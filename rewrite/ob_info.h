#ifndef OB_INFO_H
#define OB_INFO_H

#include "ob_nt.h"

typedef unsigned short USHORT;
typedef unsigned short WCHAR;
typedef WCHAR *PWSTR;

typedef struct _UNICODE_STRING
{
    USHORT Length;
    USHORT MaximumLength;
    PWSTR Buffer;
} UNICODE_STRING, *PUNICODE_STRING;

#define OBJ_CREATOR_INFO 0x01
#define OBJ_NAME_INFO 0x02
#define OBJ_HANDLE_INFO 0x04
#define OBJ_QUOTA_INFO 0x08
#define OBJ_PROCESS_INFO 0x10
#define OBJ_AUDIT_INFO 0x20
#define OBJ_EXTENDED_INFO 0x40

typedef struct _OBJECT_HEADER_NAME_INFO
{
    void *Directory;
    UNICODE_STRING Name;
    ULONG QueryReferences;
    ULONG Reserved2;
    ULONG DbgReferenceCount;
    ULONG64 Reserved3;
} OBJECT_HEADER_NAME_INFO, *POBJECT_HEADER_NAME_INFO;

typedef struct _OBJECT_HEADER_HANDLE_INFO
{
    void *HandleCountDatabase;
    ULONG64 Reserved;
} OBJECT_HEADER_HANDLE_INFO, *POBJECT_HEADER_HANDLE_INFO;

extern const UCHAR ObpInfoMaskToOffset[128];

#define OBJECT_HEADER_TO_INFO(h, m) \
    ((void *)((UCHAR *)(h) - ObpInfoMaskToOffset[(h)->InfoMask & (m)]))

#endif