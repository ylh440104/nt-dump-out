#include <stdio.h>
#include <stddef.h>
#include "ob_nt.h"

#define CHECK(f, off)                                    \
    do                                                   \
    {                                                    \
        size_t a = offsetof(OBJECT_HEADER, f);            \
        printf("%-20s %3zu  %s\n", #f, a,                 \
               a == (off) ? "OK" : "MISMATCH");           \
    } while (0)

int main(void)
{
    printf("sizeof(OBJECT_HEADER) = %zu (expect 56)\n\n", sizeof(OBJECT_HEADER));
    CHECK(PointerCount, 0);
    CHECK(u8, 8);
    CHECK(Lock, 16);
    CHECK(TypeIndex, 24);
    CHECK(u25, 25);
    CHECK(InfoMask, 26);
    CHECK(u27, 27);
    CHECK(Reserved, 28);
    CHECK(u32, 32);
    CHECK(SecurityDescriptor, 40);
    CHECK(Body, 48);
    printf("\nsizeof(EX_PUSH_LOCK) = %zu (expect 8)\n", sizeof(EX_PUSH_LOCK));
    return 0;
}