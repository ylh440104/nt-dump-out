#include "ob_nt.h"

#include <stdio.h>
#include <stdlib.h>

#define OBJ_HEADER_OFFSET 0x30
#define OBJECT_TO_OBJECT_HEADER(o) ((POBJECT_HEADER)((UCHAR *)(o) - OBJ_HEADER_OFFSET))

#define OBJECT_HEADER_CORRUPTION 0x18

typedef struct _OBJECT_TYPE
{
    ULONG Index;
    ULONG TotalNumberOfObjects;
} OBJECT_TYPE, *POBJECT_TYPE;

ULONG ObpTraceFlags = 0;
UCHAR ObHeaderCookie = 0;
void *ObTypeIndexTable[256];

int ObpDeferCount = 0;
void *ObpDeferLast = 0;
int ObpBugCheckHit = 0;
ULONG ObpLastBugCode = 0;

static void ObpPushStackInfo(POBJECT_HEADER Header, int A, LONG_PTR B, ULONG Tag)
{
    (void)Header;
    (void)A;
    (void)B;
    (void)Tag;
}

static void ObpTraceObjectReferenceIfActive(POBJECT_HEADER Header, ULONG Tag)
{
    if (ObpTraceFlags == 0)
        return;

    ObpPushStackInfo(Header, 1, 1, Tag);
}

static void ObpDeferObjectDeletion(POBJECT_HEADER Header)
{
    ObpDeferCount++;
    ObpDeferLast = Header;
}

static void KeBugCheckEx(ULONG Code, ULONG_PTR P1, ULONG_PTR P2, ULONG_PTR P3, ULONG_PTR P4)
{
    (void)P1;
    (void)P2;
    (void)P3;
    (void)P4;
    ObpBugCheckHit++;
    ObpLastBugCode = Code;
}

void *ObGetObjectType(void *Object)
{
    POBJECT_HEADER Header;
    UCHAR Idx;

    Header = OBJECT_TO_OBJECT_HEADER(Object);
    Idx = (UCHAR)(((ULONG_PTR)Header >> 8) ^ Header->TypeIndex ^ ObHeaderCookie);

    return ObTypeIndexTable[Idx];
}

static POBJECT_TYPE ObpGetTypeByHeader(POBJECT_HEADER Header)
{
    UCHAR Idx = (UCHAR)(((ULONG_PTR)Header >> 8) ^ Header->TypeIndex ^ ObHeaderCookie);
    return (POBJECT_TYPE)ObTypeIndexTable[Idx];
}

LONG_PTR ObDereferenceObjectEx(void *Object, LONG_PTR Count)
{
    POBJECT_HEADER Header;
    LONG_PTR Old;

    Header = OBJECT_TO_OBJECT_HEADER(Object);

    if (ObpTraceFlags != 0)
    {
        ObpPushStackInfo(Header, 0, Count, 0x746c6644);
    }

    Old = __atomic_fetch_add(&Header->PointerCount, -Count, __ATOMIC_SEQ_CST);
    Old -= Count;

    if (Old < 1)
    {
        if (Header->u8.HandleCount != 0)
        {
            KeBugCheckEx(OBJECT_HEADER_CORRUPTION,
                         (ULONG_PTR)ObpGetTypeByHeader(Header),
                         (ULONG_PTR)Object, 6, (ULONG_PTR)Old);
        }

        if (Old < 0)
        {
            KeBugCheckEx(OBJECT_HEADER_CORRUPTION, 0, (ULONG_PTR)Object,
                         5, (ULONG_PTR)Old);
        }

        ObpDeferObjectDeletion(Header);
    }

    return Old;
}

LONG_PTR ObReferenceObjectExWithTag(void *Object, LONG_PTR Count, ULONG Tag)
{
    POBJECT_HEADER Header;
    LONG_PTR Old;

    Header = OBJECT_TO_OBJECT_HEADER(Object);

    ObpTraceObjectReferenceIfActive(Header, Tag);

    Old = __atomic_fetch_add(&Header->PointerCount, Count, __ATOMIC_SEQ_CST);

    if (Old < 1)
    {
        KeBugCheckEx(OBJECT_HEADER_CORRUPTION, 0, (ULONG_PTR)Object,
                     0x10, (ULONG_PTR)(Count + Old));
    }

    return Old + Count;
}

LONG_PTR ObReferenceObjectByPointer(void *Object, ULONG Tag)
{
    return ObReferenceObjectExWithTag(Object, 1, Tag);
}

ULONG ObGetFilterVersion(void)
{
    return 0x100;
}

int ObpDeviceMapDerefCalls = 0;
void *ObpLastDeviceMap = 0;
ULONG ObpLastDeviceMapCount = 0;

void ObDereferenceDeviceMap(void *DeviceMap, ULONG Count)
{
    ObpDeviceMapDerefCalls++;
    ObpLastDeviceMap = DeviceMap;
    ObpLastDeviceMapCount = Count;
}

void ObCleanupSiloState(ULONG_PTR *SiloState)
{
    ULONG_PTR Old;

    Old = __atomic_exchange_n(SiloState, 0, __ATOMIC_SEQ_CST);

    if (Old != 0)
    {
        ObDereferenceDeviceMap((void *)(Old & ~(ULONG_PTR)0xF),
                               (ULONG)(Old & 0xF) + 1);
    }
}

void *ExGetHandlePointer(void *Entry)
{
    return Entry;
}

void ExUnlockHandleTableEntry(void *HandleTable, void *Entry)
{
    (void)HandleTable;
    (void)Entry;
}

int DbgPrint(const char *Format, ...)
{
    (void)Format;
    return 0;
}

void ObpShutdownCloseHandleProcedure(void *HandleTable, void *Entry, ULONG HandleValue)
{
    void *Object;

    Object = ExGetHandlePointer(Entry);

    ExUnlockHandleTableEntry(HandleTable, Entry);

    DbgPrint("\tFound object %p(handle %08lx)\n",
             (void *)((UCHAR *)Object + OBJ_HEADER_OFFSET), HandleValue);
}