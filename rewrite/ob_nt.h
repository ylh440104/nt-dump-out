#ifndef OB_NT_H
#define OB_NT_H

typedef unsigned char UCHAR;
typedef unsigned int ULONG;
typedef long long LONG64;
typedef unsigned long long ULONG64;
typedef long long LONG_PTR;
typedef unsigned long long ULONG_PTR;

typedef union _EX_PUSH_LOCK
{
    struct
    {
        ULONG64 Locked : 1;
        ULONG64 Waiting : 1;
        ULONG64 Waking : 1;
        ULONG64 MultipleShared : 1;
        ULONG64 Shared : 60;
    };
    ULONG64 Value;
    void *Ptr;
} EX_PUSH_LOCK, *PEX_PUSH_LOCK;

typedef union _QUAD
{
    struct
    {
        union
        {
            LONG64 QuadPart;
            void *Pointer;
        };
    };
} QUAD;

typedef union _OBJECT_HEADER_U8
{
    LONG64 HandleCount;
    void *NextToFree;
} OBJECT_HEADER_U8;

typedef union _OBJECT_HEADER_U25
{
    UCHAR TraceFlags;
    UCHAR Reserved;
} OBJECT_HEADER_U25;

typedef union _OBJECT_HEADER_U27
{
    UCHAR Reserved;
} OBJECT_HEADER_U27;

typedef union _OBJECT_HEADER_U32
{
    void *ObjectCreateInfo;
    void *QuotaBlockCharged;
} OBJECT_HEADER_U32;

typedef struct _OBJECT_HEADER
{
    LONG_PTR PointerCount;
    OBJECT_HEADER_U8 u8;
    EX_PUSH_LOCK Lock;
    UCHAR TypeIndex;
    OBJECT_HEADER_U25 u25;
    UCHAR InfoMask;
    OBJECT_HEADER_U27 u27;
    ULONG Reserved;
    OBJECT_HEADER_U32 u32;
    void *SecurityDescriptor;
    QUAD Body;
} OBJECT_HEADER, *POBJECT_HEADER;

#endif