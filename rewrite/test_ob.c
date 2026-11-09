#include <stdio.h>
#include <stddef.h>
#include "ob_nt.h"

extern LONG_PTR ObDereferenceObjectEx(void *Object, LONG_PTR Count);
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

    return 0;
}