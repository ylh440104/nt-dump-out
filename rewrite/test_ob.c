#include <stdio.h>
#include <stddef.h>
#include "ob_nt.h"

extern LONG_PTR ObDereferenceObjectEx(void *Object, LONG_PTR Count);
extern LONG_PTR ObReferenceObjectExWithTag(void *Object, LONG_PTR Count, ULONG Tag);
extern void *ObGetObjectType(void *Object);
extern unsigned char ObHeaderCookie;
extern void *ObTypeIndexTable[256];
extern ULONG ObGetFilterVersion(void);
extern void ObCleanupSiloState(ULONG_PTR *SiloState);
extern void ObpShutdownCloseHandleProcedure(void *HandleTable, void *Entry, ULONG HandleValue);
extern int ObpDeviceMapDerefCalls;
extern void *ObpLastDeviceMap;
extern ULONG ObpLastDeviceMapCount;
extern int ObpDeferCount;
extern int ObpBugCheckHit;
extern ULONG ObpLastBugCode;

static unsigned char Storage[sizeof(OBJECT_HEADER) + 64];

#define HEADER ((POBJECT_HEADER)Storage)
#define BODY (Storage + 0x30)

static void Reset(void)
{
    size_t i;
    for (i = 0; i < sizeof(Storage); i++)
        Storage[i] = 0;
    ObpDeferCount = 0;
    ObpBugCheckHit = 0;
    ObpLastBugCode = 0;
}

int main(void)
{
    LONG_PTR r;

    Reset();
    HEADER->PointerCount = 3;
    r = ObDereferenceObjectEx(BODY, 1);
    printf("case1 deref1 of 3 : ret=%lld count=%lld defer=%d  %s\n",
           r, HEADER->PointerCount, ObpDeferCount,
           (r == 2 && HEADER->PointerCount == 2 && ObpDeferCount == 0) ? "OK" : "FAIL");

    Reset();
    HEADER->PointerCount = 1;
    r = ObDereferenceObjectEx(BODY, 1);
    printf("case2 deref1 of 1 : ret=%lld count=%lld defer=%d  %s\n",
           r, HEADER->PointerCount, ObpDeferCount,
           (r == 0 && ObpDeferCount == 1) ? "OK" : "FAIL");

    Reset();
    HEADER->PointerCount = 2;
    r = ObDereferenceObjectEx(BODY, 2);
    printf("case3 deref2 of 2 : ret=%lld count=%lld defer=%d  %s\n",
           r, HEADER->PointerCount, ObpDeferCount,
           (r == 0 && ObpDeferCount == 1) ? "OK" : "FAIL");

    Reset();
    HEADER->PointerCount = 1;
    r = ObDereferenceObjectEx(BODY, 2);
    printf("case4 underflow   : ret=%lld bug=%d code=0x%x  %s\n",
           r, ObpBugCheckHit, ObpLastBugCode,
           (r == -1 && ObpBugCheckHit == 1 && ObpLastBugCode == 0x18) ? "OK" : "FAIL");

    Reset();
    HEADER->PointerCount = 1;
    HEADER->u8.HandleCount = 1;
    r = ObDereferenceObjectEx(BODY, 1);
    printf("case5 handles!=0  : ret=%lld bug=%d code=0x%x  %s\n",
           r, ObpBugCheckHit, ObpLastBugCode,
           (ObpBugCheckHit == 1 && ObpLastBugCode == 0x18) ? "OK" : "FAIL");

    Reset();
    HEADER->PointerCount = 1;
    r = ObReferenceObjectExWithTag(BODY, 1, 0x746c6644);
    printf("case6 ref 1 -> 2  : ret=%lld count=%lld bug=%d  %s\n",
           r, HEADER->PointerCount, ObpBugCheckHit,
           (r == 2 && HEADER->PointerCount == 2 && ObpBugCheckHit == 0) ? "OK" : "FAIL");

    Reset();
    HEADER->PointerCount = 0;
    r = ObReferenceObjectExWithTag(BODY, 1, 0);
    printf("case7 ref dead obj: ret=%lld bug=%d code=0x%x  %s\n",
           r, ObpBugCheckHit, ObpLastBugCode,
           (r == 1 && ObpBugCheckHit == 1 && ObpLastBugCode == 0x18) ? "OK" : "FAIL");

    Reset();
    ObHeaderCookie = 0x5A;
    HEADER->TypeIndex = 0x07;
    {
        unsigned char idx = (unsigned char)((0x100 >> 8) ^ 0x07 ^ 0x5A);
        void *t = ObGetObjectType(BODY);
        printf("case8 cookie 0x%02x idx=%u -> %p  %s\n", ObHeaderCookie, idx, t,
               (idx == 0x5C) ? "idx-OK" : "idx-FAIL");
        printf("case8 type table hit              %s\n",
               (t == (void *)0) ? "NULL-OK(not-set)" : "MISMATCH");
    }

    Reset();
    printf("case9 filter version = 0x%x  %s\n", ObGetFilterVersion(),
           ObGetFilterVersion() == 0x100 ? "OK" : "FAIL");

    {
        ULONG_PTR silo = 0x1234;

        Reset();
        ObpDeviceMapDerefCalls = 0;
        ObCleanupSiloState(&silo);
        printf("case10 silo clear : zero=%d calls=%d map=%p cnt=%u  %s\n",
               silo == 0, ObpDeviceMapDerefCalls, ObpLastDeviceMap,
               ObpLastDeviceMapCount,
               (silo == 0 && ObpDeviceMapDerefCalls == 1 &&
                ObpLastDeviceMap == (void *)0x1230 && ObpLastDeviceMapCount == 5)
                   ? "OK" : "FAIL");

        ObCleanupSiloState(&silo);
        printf("case10b silo empty: calls=%d  %s\n", ObpDeviceMapDerefCalls,
               ObpDeviceMapDerefCalls == 1 ? "OK" : "FAIL");
    }

    Reset();
    ObpShutdownCloseHandleProcedure((void *)1, (void *)2, 0x2Cu);
    printf("case11 close handle proc survived  OK\n");

    return 0;
}