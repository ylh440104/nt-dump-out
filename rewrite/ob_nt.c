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