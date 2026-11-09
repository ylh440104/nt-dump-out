#include <stdio.h>
#include <string.h>
#include "ob_info.h"

static unsigned char Arena[512];
#define HEADER ((POBJECT_HEADER)(Arena + 256))

int main(void)
{
    long g1, g2, g3;

    memset(Arena, 0, sizeof(Arena));

    HEADER->InfoMask = OBJ_NAME_INFO | OBJ_HANDLE_INFO;

    g1 = (long)((unsigned char *)OBJECT_HEADER_TO_INFO(HEADER, 0x06) - Arena);
    g2 = (long)((unsigned char *)OBJECT_HEADER_TO_INFO(HEADER, 0x04) - Arena);

    printf("mask=0x06, lookup mask=0x06 -> %3ld  expect 208  %s\n",
           g1, g1 == 208 ? "OK" : "FAIL");
    printf("mask=0x06, lookup mask=0x04 -> %3ld  expect 240  %s\n",
           g2, g2 == 240 ? "OK" : "FAIL");

    HEADER->InfoMask = OBJ_NAME_INFO;
    g3 = (long)((unsigned char *)OBJECT_HEADER_TO_INFO(HEADER, 0x06) - Arena);
    printf("mask=0x02, lookup mask=0x06 -> %3ld  expect 224  %s\n",
           g3, g3 == 224 ? "OK" : "FAIL");

    printf("\ntable checks: t[0]=%d t[1]=%d t[3]=%d t[6]=%d t[0x7f]=%d\n",
           ObpInfoMaskToOffset[0], ObpInfoMaskToOffset[1],
           ObpInfoMaskToOffset[3], ObpInfoMaskToOffset[6],
           ObpInfoMaskToOffset[0x7f]);
    printf("expect       : 0 32 64 48 160\n");
    return 0;
}