
===== Write<_tlgWrapperByVal<8>,_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapSz<char>_> @ 1c0001008 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapperByVal<8>,struct _tlgWrapperByRef<16>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapSz<char>,struct _tlgWrapperByVal<4>,struct _tlgWrapSz<char>
   >(struct _tlgProvider_t const * __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct
   _GUID const * __ptr64,struct _tlgWrapperByVal<8> const & __ptr64,struct _tlgWrapperByRef<16>
   const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapSz<char> const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapSz<char> const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::
Write<_tlgWrapperByVal<8>,_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapSz<char>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapperByVal<8> *param_5,_tlgWrapperByRef<16> *param_6,_tlgWrapperByVal<4> *param_7,
          _tlgWrapSz<char> *param_8,_tlgWrapperByVal<4> *param_9,_tlgWrapSz<char> *param_10)

{
  long lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 auStackY_c8 [32];
  undefined8 local_98 [4];
  _tlgWrapperByVal<8> *local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  _tlgWrapperByVal<4> *local_58;
  undefined8 local_50;
  char *local_48;
  int local_40;
  undefined4 local_3c;
  _tlgWrapperByVal<4> *local_38;
  undefined8 local_30;
  char *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  lVar3 = -1;
  local_28 = *(char **)param_10;
  if (local_28 == (char *)0x0) {
    local_28 = "";
    local_20 = 1;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (local_28[lVar2] != '\0');
    local_20 = (int)lVar2 + 1;
  }
  local_38 = param_9;
  local_1c = 0;
  local_30 = 4;
  local_48 = *(char **)param_8;
  if (local_48 == (char *)0x0) {
    local_48 = "";
    local_40 = 1;
  }
  else {
    do {
      lVar3 = lVar3 + 1;
    } while (local_48[lVar3] != '\0');
    local_40 = (int)lVar3 + 1;
  }
  local_58 = param_7;
  local_3c = 0;
  local_68 = *(undefined8 *)param_6;
  local_78 = param_5;
  local_70 = 8;
  local_50 = 4;
  local_60 = 0x10;
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x1c0018058,param_2,0,0,8,local_98);
  return lVar1;
}



===== _tlgWriteTransfer_EtwWriteTransfer @ 1c0001110 =====

void _tlgWriteTransfer_EtwWriteTransfer
               (longlong param_1,byte *param_2,undefined8 param_3,undefined8 param_4,
               undefined4 param_5,undefined8 *param_6)

{
  int local_18;
  uint local_14;
  undefined8 local_10;
  
  local_18 = (uint)*param_2 << 0x18;
  local_14 = (uint)*(ushort *)(param_2 + 1);
  local_10 = *(undefined8 *)(param_2 + 3);
  *param_6 = *(undefined8 *)(param_1 + 8);
  *(uint *)(param_6 + 1) = (uint)**(ushort **)(param_1 + 8);
  param_6[2] = param_2 + 0xb;
  *(undefined4 *)((longlong)param_6 + 0xc) = 2;
  *(uint *)(param_6 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)param_6 + 0x1c) = 1;
  EtwWriteTransfer(*(undefined8 *)(param_1 + 0x20),&local_18,param_3,param_4,param_5,param_6);
  return;
}



===== Write<_tlgWrapperByVal<8>,_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>_> @ 1c00011b4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapperByVal<8>,struct _tlgWrapperByRef<16>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapSz<char>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4> >(struct _tlgProvider_t const * __ptr64,void const
   * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,struct _tlgWrapperByVal<8>
   const & __ptr64,struct _tlgWrapperByRef<16> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapSz<char> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::
Write<_tlgWrapperByVal<8>,_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapperByVal<8> *param_5,_tlgWrapperByRef<16> *param_6,_tlgWrapperByVal<4> *param_7,
          _tlgWrapSz<char> *param_8,_tlgWrapperByVal<4> *param_9,_tlgWrapperByVal<4> *param_10,
          _tlgWrapperByVal<4> *param_11)

{
  long lVar1;
  longlong lVar2;
  undefined1 auStackY_d8 [32];
  undefined8 local_a8 [4];
  _tlgWrapperByVal<8> *local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  _tlgWrapperByVal<4> *local_68;
  undefined8 local_60;
  char *local_58;
  int local_50;
  undefined4 local_4c;
  _tlgWrapperByVal<4> *local_48;
  undefined8 local_40;
  _tlgWrapperByVal<4> *local_38;
  undefined8 local_30;
  _tlgWrapperByVal<4> *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_28 = param_11;
  local_38 = param_10;
  local_48 = param_9;
  local_20 = 4;
  local_30 = 4;
  local_40 = 4;
  local_58 = *(char **)param_8;
  if (local_58 == (char *)0x0) {
    local_58 = "";
    local_50 = 1;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (local_58[lVar2] != '\0');
    local_50 = (int)lVar2 + 1;
  }
  local_68 = param_7;
  local_4c = 0;
  local_60 = 4;
  local_78 = *(undefined8 *)param_6;
  local_88 = param_5;
  local_70 = 0x10;
  local_80 = 8;
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x1c0018058,param_2,0,0,9,local_a8);
  return lVar1;
}



===== Write<_tlgWrapperByVal<8>,_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperBinary> @ 1c00012a8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapperByVal<8>,struct _tlgWrapperByRef<16>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapSz<char>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<1>,struct
   _tlgWrapperByVal<1>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<1>,struct _tlgWrapperByVal<1>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperBinary>(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,struct _tlgWrapperByVal<8>
   const & __ptr64,struct _tlgWrapperByRef<16> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapSz<char> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct
   _tlgWrapperByVal<1> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<1> const & __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperBinary const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::
Write<_tlgWrapperByVal<8>,_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperBinary>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapperByVal<8> *param_5,_tlgWrapperByRef<16> *param_6,_tlgWrapperByVal<4> *param_7,
          _tlgWrapSz<char> *param_8,_tlgWrapperByVal<4> *param_9,_tlgWrapperByVal<4> *param_10,
          _tlgWrapperByVal<4> *param_11,_tlgWrapperByVal<4> *param_12,_tlgWrapperByVal<4> *param_13,
          _tlgWrapperByVal<4> *param_14,_tlgWrapperByVal<1> *param_15,_tlgWrapperByVal<1> *param_16,
          _tlgWrapperByVal<4> *param_17,_tlgWrapperByVal<4> *param_18,_tlgWrapperByVal<4> *param_19,
          _tlgWrapperByVal<1> *param_20,_tlgWrapperByVal<1> *param_21,_tlgWrapperByVal<4> *param_22,
          _tlgWrapperByVal<4> *param_23,_tlgWrapperByVal<4> *param_24,_tlgWrapperByVal<4> *param_25,
          _tlgWrapperByVal<4> *param_26,_tlgWrapperByVal<4> *param_27,_tlgWrapperByVal<4> *param_28,
          _tlgWrapperByVal<4> *param_29,_tlgWrapperByVal<4> *param_30,_tlgWrapperByVal<4> *param_31,
          _tlgWrapperBinary *param_32)

{
  long lVar1;
  longlong lVar2;
  undefined1 auStackY_238 [32];
  undefined8 local_208 [4];
  _tlgWrapperByVal<8> *local_1e8;
  undefined8 local_1e0;
  undefined8 local_1d8;
  undefined8 local_1d0;
  _tlgWrapperByVal<4> *local_1c8;
  undefined8 local_1c0;
  char *local_1b8;
  int local_1b0;
  undefined4 local_1ac;
  _tlgWrapperByVal<4> *local_1a8;
  undefined8 local_1a0;
  _tlgWrapperByVal<4> *local_198;
  undefined8 local_190;
  _tlgWrapperByVal<4> *local_188;
  undefined8 local_180;
  _tlgWrapperByVal<4> *local_178;
  undefined8 local_170;
  _tlgWrapperByVal<4> *local_168;
  undefined8 local_160;
  _tlgWrapperByVal<4> *local_158;
  undefined8 local_150;
  _tlgWrapperByVal<1> *local_148;
  undefined8 local_140;
  _tlgWrapperByVal<1> *local_138;
  undefined8 local_130;
  _tlgWrapperByVal<4> *local_128;
  undefined8 local_120;
  _tlgWrapperByVal<4> *local_118;
  undefined8 local_110;
  _tlgWrapperByVal<4> *local_108;
  undefined8 local_100;
  _tlgWrapperByVal<1> *local_f8;
  undefined8 local_f0;
  _tlgWrapperByVal<1> *local_e8;
  undefined8 local_e0;
  _tlgWrapperByVal<4> *local_d8;
  undefined8 local_d0;
  _tlgWrapperByVal<4> *local_c8;
  undefined8 local_c0;
  _tlgWrapperByVal<4> *local_b8;
  undefined8 local_b0;
  _tlgWrapperByVal<4> *local_a8;
  undefined8 local_a0;
  _tlgWrapperByVal<4> *local_98;
  undefined8 local_90;
  _tlgWrapperByVal<4> *local_88;
  undefined8 local_80;
  _tlgWrapperByVal<4> *local_78;
  undefined8 local_70;
  _tlgWrapperByVal<4> *local_68;
  undefined8 local_60;
  _tlgWrapperByVal<4> *local_58;
  undefined8 local_50;
  _tlgWrapperByVal<4> *local_48;
  undefined8 local_40;
  uint *local_38;
  undefined8 local_30;
  undefined8 local_28;
  uint local_20 [2];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_238;
  local_38 = local_20;
  local_30 = 2;
  local_20[1] = 0;
  local_28 = *(undefined8 *)param_32;
  local_20[0] = (uint)*(ushort *)(param_32 + 8);
  local_48 = param_31;
  local_58 = param_30;
  local_68 = param_29;
  local_78 = param_28;
  local_88 = param_27;
  local_98 = param_26;
  local_a8 = param_25;
  local_b8 = param_24;
  local_c8 = param_23;
  local_d8 = param_22;
  local_e8 = param_21;
  local_f8 = param_20;
  local_108 = param_19;
  local_118 = param_18;
  local_128 = param_17;
  local_138 = param_16;
  local_148 = param_15;
  local_158 = param_14;
  local_168 = param_13;
  local_178 = param_12;
  local_188 = param_11;
  local_198 = param_10;
  local_1a8 = param_9;
  local_40 = 4;
  local_50 = 4;
  local_60 = 4;
  local_70 = 4;
  local_80 = 4;
  local_90 = 4;
  local_a0 = 4;
  local_b0 = 4;
  local_c0 = 4;
  local_d0 = 4;
  local_e0 = 1;
  local_f0 = 1;
  local_100 = 4;
  local_110 = 4;
  local_120 = 4;
  local_130 = 1;
  local_140 = 1;
  local_150 = 4;
  local_160 = 4;
  local_170 = 4;
  local_180 = 4;
  local_190 = 4;
  local_1a0 = 4;
  local_1b8 = *(char **)param_8;
  if (local_1b8 == (char *)0x0) {
    local_1b8 = "";
    local_1b0 = 1;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (local_1b8[lVar2] != '\0');
    local_1b0 = (int)lVar2 + 1;
  }
  local_1c8 = param_7;
  local_1ac = 0;
  local_1c0 = 4;
  local_1d8 = *(undefined8 *)param_6;
  local_1e8 = param_5;
  local_1d0 = 0x10;
  local_1e0 = 8;
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x1c0018058,param_2,0,0,0x1f,local_208);
  return lVar1;
}



===== Write<_tlgWrapperByVal<8>,_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapperByVal<2>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>_> @ 1c000159c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapperByVal<8>,struct _tlgWrapperByRef<16>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapSz<char>,struct _tlgWrapperByVal<2>,struct
   _tlgWrapperByVal<2>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapSz<char>,struct _tlgWrapSz<char>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapSz<char>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<8>,struct
   _tlgWrapperByVal<1>,struct _tlgWrapperByVal<1>,struct _tlgWrapperByVal<1>,struct
   _tlgWrapperByVal<1>,struct _tlgWrapperByVal<1>,struct _tlgWrapperByVal<1>,struct
   _tlgWrapperByVal<1> >(struct _tlgProvider_t const * __ptr64,void const * __ptr64,struct _GUID
   const * __ptr64,struct _GUID const * __ptr64,struct _tlgWrapperByVal<8> const & __ptr64,struct
   _tlgWrapperByRef<16> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapSz<char> const & __ptr64,struct _tlgWrapperByVal<2> const & __ptr64,struct
   _tlgWrapperByVal<2> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapSz<char> const & __ptr64,struct
   _tlgWrapSz<char> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapSz<char> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<8> const & __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct
   _tlgWrapperByVal<1> const & __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct
   _tlgWrapperByVal<1> const & __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct
   _tlgWrapperByVal<1> const & __ptr64,struct _tlgWrapperByVal<1> const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::
Write<_tlgWrapperByVal<8>,_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapperByVal<2>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapperByVal<8> *param_5,_tlgWrapperByRef<16> *param_6,_tlgWrapperByVal<4> *param_7,
          _tlgWrapSz<char> *param_8,_tlgWrapperByVal<2> *param_9,_tlgWrapperByVal<2> *param_10,
          _tlgWrapperByVal<4> *param_11,_tlgWrapperByVal<4> *param_12,_tlgWrapSz<char> *param_13,
          _tlgWrapSz<char> *param_14,_tlgWrapperByVal<4> *param_15,_tlgWrapSz<char> *param_16,
          _tlgWrapperByVal<4> *param_17,_tlgWrapperByVal<8> *param_18,_tlgWrapperByVal<1> *param_19,
          _tlgWrapperByVal<1> *param_20,_tlgWrapperByVal<1> *param_21,_tlgWrapperByVal<1> *param_22,
          _tlgWrapperByVal<1> *param_23,_tlgWrapperByVal<1> *param_24,_tlgWrapperByVal<1> *param_25)

{
  long lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 auStackY_1b8 [32];
  undefined8 local_188 [4];
  _tlgWrapperByVal<8> *local_168;
  undefined8 local_160;
  undefined8 local_158;
  undefined8 local_150;
  _tlgWrapperByVal<4> *local_148;
  undefined8 local_140;
  char *local_138;
  int local_130;
  undefined4 local_12c;
  _tlgWrapperByVal<2> *local_128;
  undefined8 local_120;
  _tlgWrapperByVal<2> *local_118;
  undefined8 local_110;
  _tlgWrapperByVal<4> *local_108;
  undefined8 local_100;
  _tlgWrapperByVal<4> *local_f8;
  undefined8 local_f0;
  char *local_e8;
  int local_e0;
  undefined4 local_dc;
  char *local_d8;
  int local_d0;
  undefined4 local_cc;
  _tlgWrapperByVal<4> *local_c8;
  undefined8 local_c0;
  char *local_b8;
  int local_b0;
  undefined4 local_ac;
  _tlgWrapperByVal<4> *local_a8;
  undefined8 local_a0;
  _tlgWrapperByVal<8> *local_98;
  undefined8 local_90;
  _tlgWrapperByVal<1> *local_88;
  undefined8 local_80;
  _tlgWrapperByVal<1> *local_78;
  undefined8 local_70;
  _tlgWrapperByVal<1> *local_68;
  undefined8 local_60;
  _tlgWrapperByVal<1> *local_58;
  undefined8 local_50;
  _tlgWrapperByVal<1> *local_48;
  undefined8 local_40;
  _tlgWrapperByVal<1> *local_38;
  undefined8 local_30;
  _tlgWrapperByVal<1> *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_1b8;
  local_28 = param_25;
  local_38 = param_24;
  lVar3 = -1;
  local_48 = param_23;
  local_58 = param_22;
  local_68 = param_21;
  local_78 = param_20;
  local_88 = param_19;
  local_98 = param_18;
  local_a8 = param_17;
  local_20 = 1;
  local_30 = 1;
  local_40 = 1;
  local_b8 = *(char **)param_16;
  local_50 = 1;
  local_60 = 1;
  local_70 = 1;
  local_80 = 1;
  local_90 = 8;
  local_a0 = 4;
  if (local_b8 == (char *)0x0) {
    local_b8 = "";
    local_b0 = 1;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (local_b8[lVar2] != '\0');
    local_b0 = (int)lVar2 + 1;
  }
  local_c8 = param_15;
  local_ac = 0;
  local_c0 = 4;
  local_d8 = *(char **)param_14;
  if (local_d8 == (char *)0x0) {
    local_d8 = "";
    local_d0 = 1;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (local_d8[lVar2] != '\0');
    local_d0 = (int)lVar2 + 1;
  }
  local_cc = 0;
  local_e8 = *(char **)param_13;
  if (local_e8 == (char *)0x0) {
    local_e8 = "";
    local_e0 = 1;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (local_e8[lVar2] != '\0');
    local_e0 = (int)lVar2 + 1;
  }
  local_f8 = param_12;
  local_108 = param_11;
  local_118 = param_10;
  local_128 = param_9;
  local_dc = 0;
  local_f0 = 4;
  local_138 = *(char **)param_8;
  local_100 = 4;
  local_110 = 2;
  local_120 = 2;
  if (local_138 == (char *)0x0) {
    local_138 = "";
    local_130 = 1;
  }
  else {
    do {
      lVar3 = lVar3 + 1;
    } while (local_138[lVar3] != '\0');
    local_130 = (int)lVar3 + 1;
  }
  local_148 = param_7;
  local_12c = 0;
  local_158 = *(undefined8 *)param_6;
  local_168 = param_5;
  local_140 = 4;
  local_150 = 0x10;
  local_160 = 8;
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x1c0018058,param_2,0,0,0x17,local_188);
  return lVar1;
}



===== Write<_tlgWrapperByVal<8>,_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>_> @ 1c0001824 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapperByVal<8>,struct _tlgWrapperByRef<16>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapSz<char>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapSz<char>,struct _tlgWrapSz<char>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<1>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<1>,struct _tlgWrapperByVal<1>,struct
   _tlgWrapperByVal<1>,struct _tlgWrapperByVal<1>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<1>,struct
   _tlgWrapperByVal<1>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<1>,struct _tlgWrapperByVal<1>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<1>,struct _tlgWrapperByVal<1>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<1>,struct _tlgWrapperByVal<1>,struct
   _tlgWrapperByVal<1>,struct _tlgWrapperByVal<1>,struct _tlgWrapperByVal<1>,struct
   _tlgWrapperByVal<1>,struct _tlgWrapperByVal<1>,struct _tlgWrapperByVal<1> >(struct _tlgProvider_t
   const * __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const *
   __ptr64,struct _tlgWrapperByVal<8> const & __ptr64,struct _tlgWrapperByRef<16> const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapSz<char> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapSz<char> const & __ptr64,struct _tlgWrapSz<char> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<1> const & __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct
   _tlgWrapperByVal<1> const & __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<1> const & __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<1> const & __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<1> const & __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct
   _tlgWrapperByVal<1> const & __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct
   _tlgWrapperByVal<1> const & __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct
   _tlgWrapperByVal<1> const & __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct
   _tlgWrapperByVal<1> const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::
Write<_tlgWrapperByVal<8>,_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapperByVal<8> *param_5,_tlgWrapperByRef<16> *param_6,_tlgWrapperByVal<4> *param_7,
          _tlgWrapSz<char> *param_8,_tlgWrapperByVal<4> *param_9,_tlgWrapperByVal<4> *param_10,
          _tlgWrapSz<char> *param_11,_tlgWrapSz<char> *param_12,_tlgWrapperByVal<4> *param_13,
          _tlgWrapperByVal<1> *param_14,_tlgWrapperByVal<4> *param_15,_tlgWrapperByVal<4> *param_16,
          _tlgWrapperByVal<1> *param_17,_tlgWrapperByVal<1> *param_18,_tlgWrapperByVal<1> *param_19,
          _tlgWrapperByVal<1> *param_20,_tlgWrapperByVal<4> *param_21,_tlgWrapperByVal<4> *param_22,
          _tlgWrapperByVal<4> *param_23,_tlgWrapperByVal<4> *param_24,_tlgWrapperByVal<4> *param_25,
          _tlgWrapperByVal<4> *param_26,_tlgWrapperByVal<1> *param_27,_tlgWrapperByVal<1> *param_28,
          _tlgWrapperByVal<4> *param_29,_tlgWrapperByVal<4> *param_30,_tlgWrapperByVal<1> *param_31,
          _tlgWrapperByVal<1> *param_32,_tlgWrapperByVal<4> *param_33,_tlgWrapperByVal<4> *param_34,
          _tlgWrapperByVal<1> *param_35,_tlgWrapperByVal<1> *param_36,_tlgWrapperByVal<4> *param_37,
          _tlgWrapperByVal<1> *param_38,_tlgWrapperByVal<1> *param_39,_tlgWrapperByVal<1> *param_40,
          _tlgWrapperByVal<1> *param_41,_tlgWrapperByVal<1> *param_42,_tlgWrapperByVal<1> *param_43,
          _tlgWrapperByVal<1> *param_44,_tlgWrapperByVal<1> *param_45)

{
  long lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 auStackY_2f8 [32];
  undefined8 local_2c8 [4];
  _tlgWrapperByVal<8> *local_2a8;
  undefined8 local_2a0;
  undefined8 local_298;
  undefined8 local_290;
  _tlgWrapperByVal<4> *local_288;
  undefined8 local_280;
  char *local_278;
  int local_270;
  undefined4 local_26c;
  _tlgWrapperByVal<4> *local_268;
  undefined8 local_260;
  _tlgWrapperByVal<4> *local_258;
  undefined8 local_250;
  char *local_248;
  int local_240;
  undefined4 local_23c;
  char *local_238;
  int local_230;
  undefined4 local_22c;
  _tlgWrapperByVal<4> *local_228;
  undefined8 local_220;
  _tlgWrapperByVal<1> *local_218;
  undefined8 local_210;
  _tlgWrapperByVal<4> *local_208;
  undefined8 local_200;
  _tlgWrapperByVal<4> *local_1f8;
  undefined8 local_1f0;
  _tlgWrapperByVal<1> *local_1e8;
  undefined8 local_1e0;
  _tlgWrapperByVal<1> *local_1d8;
  undefined8 local_1d0;
  _tlgWrapperByVal<1> *local_1c8;
  undefined8 local_1c0;
  _tlgWrapperByVal<1> *local_1b8;
  undefined8 local_1b0;
  _tlgWrapperByVal<4> *local_1a8;
  undefined8 local_1a0;
  _tlgWrapperByVal<4> *local_198;
  undefined8 local_190;
  _tlgWrapperByVal<4> *local_188;
  undefined8 local_180;
  _tlgWrapperByVal<4> *local_178;
  undefined8 local_170;
  _tlgWrapperByVal<4> *local_168;
  undefined8 local_160;
  _tlgWrapperByVal<4> *local_158;
  undefined8 local_150;
  _tlgWrapperByVal<1> *local_148;
  undefined8 local_140;
  _tlgWrapperByVal<1> *local_138;
  undefined8 local_130;
  _tlgWrapperByVal<4> *local_128;
  undefined8 local_120;
  _tlgWrapperByVal<4> *local_118;
  undefined8 local_110;
  _tlgWrapperByVal<1> *local_108;
  undefined8 local_100;
  _tlgWrapperByVal<1> *local_f8;
  undefined8 local_f0;
  _tlgWrapperByVal<4> *local_e8;
  undefined8 local_e0;
  _tlgWrapperByVal<4> *local_d8;
  undefined8 local_d0;
  _tlgWrapperByVal<1> *local_c8;
  undefined8 local_c0;
  _tlgWrapperByVal<1> *local_b8;
  undefined8 local_b0;
  _tlgWrapperByVal<4> *local_a8;
  undefined8 local_a0;
  _tlgWrapperByVal<1> *local_98;
  undefined8 local_90;
  _tlgWrapperByVal<1> *local_88;
  undefined8 local_80;
  _tlgWrapperByVal<1> *local_78;
  undefined8 local_70;
  _tlgWrapperByVal<1> *local_68;
  undefined8 local_60;
  _tlgWrapperByVal<1> *local_58;
  undefined8 local_50;
  _tlgWrapperByVal<1> *local_48;
  undefined8 local_40;
  _tlgWrapperByVal<1> *local_38;
  undefined8 local_30;
  _tlgWrapperByVal<1> *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_2f8;
  local_28 = param_45;
  local_38 = param_44;
  local_48 = param_43;
  local_58 = param_42;
  local_68 = param_41;
  local_78 = param_40;
  local_88 = param_39;
  local_98 = param_38;
  local_a8 = param_37;
  local_b8 = param_36;
  local_c8 = param_35;
  local_d8 = param_34;
  local_e8 = param_33;
  local_f8 = param_32;
  local_108 = param_31;
  local_118 = param_30;
  local_128 = param_29;
  local_138 = param_28;
  local_148 = param_27;
  local_158 = param_26;
  local_168 = param_25;
  local_178 = param_24;
  local_188 = param_23;
  local_198 = param_22;
  local_1a8 = param_21;
  local_1b8 = param_20;
  local_20 = 1;
  local_30 = 1;
  local_40 = 1;
  local_50 = 1;
  local_60 = 1;
  local_70 = 1;
  local_80 = 1;
  local_90 = 1;
  local_a0 = 4;
  local_b0 = 1;
  local_c0 = 1;
  local_d0 = 4;
  local_e0 = 4;
  local_f0 = 1;
  local_100 = 1;
  local_110 = 4;
  local_120 = 4;
  local_130 = 1;
  local_140 = 1;
  local_150 = 4;
  local_160 = 4;
  local_170 = 4;
  local_180 = 4;
  local_190 = 4;
  local_1a0 = 4;
  local_1b0 = 1;
  lVar3 = -1;
  local_1c8 = param_19;
  local_1d8 = param_18;
  local_1e8 = param_17;
  local_1f8 = param_16;
  local_208 = param_15;
  local_218 = param_14;
  local_228 = param_13;
  local_1c0 = 1;
  local_1d0 = 1;
  local_1e0 = 1;
  local_238 = *(char **)param_12;
  local_1f0 = 4;
  local_200 = 4;
  local_210 = 1;
  local_220 = 4;
  if (local_238 == (char *)0x0) {
    local_238 = "";
    local_230 = 1;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (local_238[lVar2] != '\0');
    local_230 = (int)lVar2 + 1;
  }
  local_22c = 0;
  local_248 = *(char **)param_11;
  if (local_248 == (char *)0x0) {
    local_248 = "";
    local_240 = 1;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (local_248[lVar2] != '\0');
    local_240 = (int)lVar2 + 1;
  }
  local_258 = param_10;
  local_268 = param_9;
  local_23c = 0;
  local_250 = 4;
  local_278 = *(char **)param_8;
  local_260 = 4;
  if (local_278 == (char *)0x0) {
    local_278 = "";
    local_270 = 1;
  }
  else {
    do {
      lVar3 = lVar3 + 1;
    } while (local_278[lVar3] != '\0');
    local_270 = (int)lVar3 + 1;
  }
  local_288 = param_7;
  local_26c = 0;
  local_298 = *(undefined8 *)param_6;
  local_2a8 = param_5;
  local_280 = 4;
  local_290 = 0x10;
  local_2a0 = 8;
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x1c0018058,param_2,0,0,0x2b,local_2c8);
  return lVar1;
}



===== Write<_tlgWrapperByVal<8>,_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>_> @ 1c0001c48 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapperByVal<8>,struct _tlgWrapperByRef<16>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapSz<char>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<1>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<1>,struct _tlgWrapperByVal<1>,struct _tlgWrapperByVal<1>,struct
   _tlgWrapperByVal<1>,struct _tlgWrapperByVal<1>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<1>,struct
   _tlgWrapperByVal<1>,struct _tlgWrapperByVal<1>,struct _tlgWrapperByVal<4> >(struct _tlgProvider_t
   const * __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const *
   __ptr64,struct _tlgWrapperByVal<8> const & __ptr64,struct _tlgWrapperByRef<16> const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapSz<char> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<1> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct
   _tlgWrapperByVal<1> const & __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct
   _tlgWrapperByVal<1> const & __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct
   _tlgWrapperByVal<1> const & __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::
Write<_tlgWrapperByVal<8>,_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapperByVal<8> *param_5,_tlgWrapperByRef<16> *param_6,_tlgWrapperByVal<4> *param_7,
          _tlgWrapSz<char> *param_8,_tlgWrapperByVal<4> *param_9,_tlgWrapperByVal<4> *param_10,
          _tlgWrapperByVal<1> *param_11,_tlgWrapperByVal<4> *param_12,_tlgWrapperByVal<4> *param_13,
          _tlgWrapperByVal<4> *param_14,_tlgWrapperByVal<4> *param_15,_tlgWrapperByVal<1> *param_16,
          _tlgWrapperByVal<1> *param_17,_tlgWrapperByVal<1> *param_18,_tlgWrapperByVal<1> *param_19,
          _tlgWrapperByVal<1> *param_20,_tlgWrapperByVal<4> *param_21,_tlgWrapperByVal<4> *param_22,
          _tlgWrapperByVal<4> *param_23,_tlgWrapperByVal<4> *param_24,_tlgWrapperByVal<4> *param_25,
          _tlgWrapperByVal<4> *param_26,_tlgWrapperByVal<4> *param_27,_tlgWrapperByVal<4> *param_28,
          _tlgWrapperByVal<4> *param_29,_tlgWrapperByVal<1> *param_30,_tlgWrapperByVal<1> *param_31,
          _tlgWrapperByVal<1> *param_32,_tlgWrapperByVal<4> *param_33)

{
  long lVar1;
  longlong lVar2;
  undefined1 auStackY_238 [32];
  undefined8 local_208 [4];
  _tlgWrapperByVal<8> *local_1e8;
  undefined8 local_1e0;
  undefined8 local_1d8;
  undefined8 local_1d0;
  _tlgWrapperByVal<4> *local_1c8;
  undefined8 local_1c0;
  char *local_1b8;
  int local_1b0;
  undefined4 local_1ac;
  _tlgWrapperByVal<4> *local_1a8;
  undefined8 local_1a0;
  _tlgWrapperByVal<4> *local_198;
  undefined8 local_190;
  _tlgWrapperByVal<1> *local_188;
  undefined8 local_180;
  _tlgWrapperByVal<4> *local_178;
  undefined8 local_170;
  _tlgWrapperByVal<4> *local_168;
  undefined8 local_160;
  _tlgWrapperByVal<4> *local_158;
  undefined8 local_150;
  _tlgWrapperByVal<4> *local_148;
  undefined8 local_140;
  _tlgWrapperByVal<1> *local_138;
  undefined8 local_130;
  _tlgWrapperByVal<1> *local_128;
  undefined8 local_120;
  _tlgWrapperByVal<1> *local_118;
  undefined8 local_110;
  _tlgWrapperByVal<1> *local_108;
  undefined8 local_100;
  _tlgWrapperByVal<1> *local_f8;
  undefined8 local_f0;
  _tlgWrapperByVal<4> *local_e8;
  undefined8 local_e0;
  _tlgWrapperByVal<4> *local_d8;
  undefined8 local_d0;
  _tlgWrapperByVal<4> *local_c8;
  undefined8 local_c0;
  _tlgWrapperByVal<4> *local_b8;
  undefined8 local_b0;
  _tlgWrapperByVal<4> *local_a8;
  undefined8 local_a0;
  _tlgWrapperByVal<4> *local_98;
  undefined8 local_90;
  _tlgWrapperByVal<4> *local_88;
  undefined8 local_80;
  _tlgWrapperByVal<4> *local_78;
  undefined8 local_70;
  _tlgWrapperByVal<4> *local_68;
  undefined8 local_60;
  _tlgWrapperByVal<1> *local_58;
  undefined8 local_50;
  _tlgWrapperByVal<1> *local_48;
  undefined8 local_40;
  _tlgWrapperByVal<1> *local_38;
  undefined8 local_30;
  _tlgWrapperByVal<4> *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_238;
  local_28 = param_33;
  local_38 = param_32;
  local_48 = param_31;
  local_58 = param_30;
  local_68 = param_29;
  local_78 = param_28;
  local_88 = param_27;
  local_98 = param_26;
  local_a8 = param_25;
  local_b8 = param_24;
  local_c8 = param_23;
  local_d8 = param_22;
  local_e8 = param_21;
  local_f8 = param_20;
  local_108 = param_19;
  local_118 = param_18;
  local_128 = param_17;
  local_138 = param_16;
  local_148 = param_15;
  local_158 = param_14;
  local_168 = param_13;
  local_178 = param_12;
  local_188 = param_11;
  local_198 = param_10;
  local_1a8 = param_9;
  local_20 = 4;
  local_30 = 1;
  local_40 = 1;
  local_1b8 = *(char **)param_8;
  local_50 = 1;
  local_60 = 4;
  local_70 = 4;
  local_80 = 4;
  local_90 = 4;
  local_a0 = 4;
  local_b0 = 4;
  local_c0 = 4;
  local_d0 = 4;
  local_e0 = 4;
  local_f0 = 1;
  local_100 = 1;
  local_110 = 1;
  local_120 = 1;
  local_130 = 1;
  local_140 = 4;
  local_150 = 4;
  local_160 = 4;
  local_170 = 4;
  local_180 = 1;
  local_190 = 4;
  local_1a0 = 4;
  if (local_1b8 == (char *)0x0) {
    local_1b8 = "";
    local_1b0 = 1;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (local_1b8[lVar2] != '\0');
    local_1b0 = (int)lVar2 + 1;
  }
  local_1c8 = param_7;
  local_1ac = 0;
  local_1c0 = 4;
  local_1d8 = *(undefined8 *)param_6;
  local_1e8 = param_5;
  local_1d0 = 0x10;
  local_1e0 = 8;
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x1c0018058,param_2,0,0,0x1f,local_208);
  return lVar1;
}



===== __report_gsfailure @ 1c0001f30 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== _purecall @ 1c0001f40 =====

void _purecall(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001c0001f40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _purecall();
  return;
}



===== memcpy_s @ 1c0001f54 =====

errno_t __cdecl memcpy_s(void *_Dst,rsize_t _DstSize,void *_Src,rsize_t _MaxCount)

{
  errno_t eVar1;
  
  if (_MaxCount == 0) {
LAB_1c0001f71:
    eVar1 = 0;
  }
  else {
    if (_Dst == (void *)0x0) {
LAB_1c0001fb3:
      eVar1 = 0x16;
    }
    else {
      if ((_Src != (void *)0x0) && (_MaxCount <= _DstSize)) {
        memcpy(_Dst,_Src,_MaxCount);
        goto LAB_1c0001f71;
      }
      memset(_Dst,0,_DstSize);
      if (_Src == (void *)0x0) goto LAB_1c0001fb3;
      if (_MaxCount <= _DstSize) {
        return 0x16;
      }
      eVar1 = 0x22;
    }
    wistd::__function::
    __func<<lambda_19eb9d4442d94dae27ff02cd8a0db90c>,INvdimmFwUpdater_*___cdecl(void)>::destroy();
  }
  return eVar1;
}



===== __cpu_features_init @ 1c0001ff0 =====

/* WARNING: Removing unreachable block (ram,0x0001c000205a) */
/* WARNING: Removing unreachable block (ram,0x0001c0002009) */
/* WARNING: Removing unreachable block (ram,0x0001c0001ffa) */

undefined8 __cpu_features_init(void)

{
  int *piVar1;
  longlong lVar2;
  uint uVar3;
  undefined8 uVar4;
  bool bVar5;
  byte bVar6;
  byte bVar7;
  byte in_XCR0;
  
  piVar1 = (int *)cpuid_basic_info(0);
  bVar7 = 0;
  bVar5 = false;
  lVar2 = cpuid_Version_info(1);
  uVar3 = *(uint *)(lVar2 + 0xc);
  if ((uVar3 >> 0x14 & 1) != 0) {
    bVar7 = 8;
    bVar5 = false;
    if (((uVar3 >> 0x1b & 1) != 0) && ((uVar3 >> 0x1c & 1) != 0)) {
      uVar4 = xinuse(0);
      bVar7 = 8;
      bVar5 = false;
      if ((in_XCR0 & (byte)uVar4 & 6) == 6) {
        bVar7 = 0xc;
        bVar5 = true;
      }
    }
  }
  if (6 < *piVar1) {
    lVar2 = cpuid_Extended_Feature_Enumeration_info(7);
    bVar6 = bVar7 | 2;
    if ((*(uint *)(lVar2 + 4) >> 9 & 1) == 0) {
      bVar6 = bVar7;
    }
    bVar7 = bVar6;
    if (((*(uint *)(lVar2 + 4) & 0x20) != 0) && (bVar5)) {
      bVar7 = bVar7 | 0x10;
    }
  }
  __isa_info = bVar7 | 1;
  return 0;
}



===== NvdCreateClose @ 1c00020c0 =====

/* long __cdecl NvdCreateClose(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl NvdCreateClose(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  longlong lVar1;
  int iVar2;
  long lVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  iVar2 = IoAcquireRemoveLockEx(lVar1 + 0xf0,param_2,"",1,0x20);
  if (iVar2 == 0) {
    lVar3 = 0;
    IoReleaseRemoveLockEx(lVar1 + 0xf0,param_2,0x20);
  }
  else {
    lVar3 = -0x3ffffff2;
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(long *)(param_2 + 0x30) = lVar3;
  IofCompleteRequest(param_2,0);
  return lVar3;
}



===== NvdDevicePowerCompletion @ 1c0002160 =====

/* void __cdecl NvdDevicePowerCompletion(struct _DEVICE_OBJECT * __ptr64,unsigned char,union
   _POWER_STATE,void * __ptr64,struct _IO_STATUS_BLOCK * __ptr64) */

void __cdecl
NvdDevicePowerCompletion
          (longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4,
          undefined4 *param_5)

{
  longlong lVar1;
  
  if (param_4 != 0) {
    lVar1 = *(longlong *)(param_1 + 0x40);
    *(undefined4 *)(param_4 + 0x30) = *param_5;
    PoStartNextPowerIrp(param_4);
    IofCompleteRequest(param_4,0);
    IoReleaseRemoveLockEx(lVar1 + 0xf0,param_4,0x20);
  }
  return;
}



===== NvdInternalControlDispatch @ 1c00021d0 =====

/* long __cdecl NvdInternalControlDispatch(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl NvdInternalControlDispatch(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  longlong lVar1;
  long lVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  param_2[0x43] = (_IRP)((char)param_2[0x43] + '\x01');
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  lVar2 = IofCallDriver(*(undefined8 *)(lVar1 + 8));
  return lVar2;
}



===== NvdPowerCompletion @ 1c0002200 =====

/* long __cdecl NvdPowerCompletion(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64,void *
   __ptr64) */

long __cdecl NvdPowerCompletion(_DEVICE_OBJECT *param_1,_IRP *param_2,void *param_3)

{
  _NVDIMM_DEVICE_EXTENSION *p_Var1;
  int iVar2;
  longlong lVar3;
  
  lVar3 = *(longlong *)(param_2 + 0xb8);
  p_Var1 = *(_NVDIMM_DEVICE_EXTENSION **)(param_1 + 0x40);
  if (-1 < *(int *)(param_2 + 0x30)) {
    if (*(int *)(lVar3 + 0x10) == 0) {
      iVar2 = PoRequestPowerIrp(param_1,*(undefined1 *)(lVar3 + 1),
                                *(undefined4 *)
                                 (p_Var1 + (longlong)*(int *)(lVar3 + 0x18) * 4 + 0x118),
                                NvdDevicePowerCompletion,param_2,0);
      if (-1 < iVar2) {
        return -0x3fffffea;
      }
      *(int *)(param_2 + 0x30) = iVar2;
    }
    else {
      PoSetPowerState(param_1,1,*(undefined4 *)(lVar3 + 0x18));
      iVar2 = *(int *)(lVar3 + 0x18);
      *(int *)(p_Var1 + 0x114) = iVar2;
      if ((iVar2 == 1) && (lVar3 = IoAllocateWorkItem(*(undefined8 *)p_Var1), lVar3 != 0)) {
        WriteTraceEvent(p_Var1,4,"D0 transition: queueing workitem");
        IoAcquireRemoveLockEx(p_Var1 + 0xf0,param_2,"",1,0x20);
        IoQueueWorkItem(lVar3,NvdResumeWorkItemRoutine,3,lVar3);
      }
    }
  }
  PoStartNextPowerIrp(param_2);
  IoReleaseRemoveLockEx(p_Var1 + 0xf0,param_2,0x20);
  return 0;
}



===== NvdPowerDispatch @ 1c0002350 =====

/* long __cdecl NvdPowerDispatch(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl NvdPowerDispatch(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  char cVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 *puVar4;
  int iVar5;
  long lVar6;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  lVar3 = *(longlong *)(param_2 + 0xb8);
  iVar5 = IoAcquireRemoveLockEx(lVar2 + 0xf0,param_2,"",1,0x20);
  if (iVar5 == 0) {
    cVar1 = *(char *)(lVar3 + 1);
    if (*(int *)(lVar3 + 0x10) == 0) {
      if ((cVar1 == '\x02') || (cVar1 == '\x03')) {
LAB_1c00023f2:
        *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) =
             *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) | 1;
        puVar4 = *(undefined8 **)(param_2 + 0xb8);
        puVar4[-9] = *puVar4;
        puVar4[-8] = puVar4[1];
        puVar4[-7] = puVar4[2];
        puVar4[-6] = puVar4[3];
        *(undefined4 *)(puVar4 + -5) = *(undefined4 *)(puVar4 + 4);
        *(undefined4 *)((longlong)puVar4 + -0x24) = *(undefined4 *)((longlong)puVar4 + 0x24);
        *(undefined4 *)(puVar4 + -4) = *(undefined4 *)(puVar4 + 5);
        *(undefined4 *)((longlong)puVar4 + -0x1c) = *(undefined4 *)((longlong)puVar4 + 0x2c);
        puVar4[-3] = puVar4[6];
        *(undefined1 *)((longlong)puVar4 + -0x45) = 0;
        lVar3 = *(longlong *)(param_2 + 0xb8);
        *(code **)(lVar3 + -0x10) = NvdPowerCompletion;
        *(undefined8 *)(lVar3 + -8) = 0;
        *(undefined1 *)(lVar3 + -0x45) = 0xe0;
        PoCallDriver(*(undefined8 *)(lVar2 + 8),param_2);
        return 0x103;
      }
    }
    else if (cVar1 == '\x02') {
      if (*(int *)(lVar3 + 0x18) <= *(int *)(lVar2 + 0x114)) goto LAB_1c00023f2;
      PoSetPowerState(param_1,1,*(undefined4 *)(lVar3 + 0x18));
      *(undefined4 *)(lVar2 + 0x114) = *(undefined4 *)(lVar3 + 0x18);
    }
    PoStartNextPowerIrp(param_2);
    param_2[0x43] = (_IRP)((char)param_2[0x43] + '\x01');
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    lVar6 = PoCallDriver(*(undefined8 *)(lVar2 + 8),param_2);
    IoReleaseRemoveLockEx(lVar2 + 0xf0,param_2,0x20);
  }
  else {
    lVar6 = -0x3ffffff2;
    *(undefined4 *)(param_2 + 0x30) = 0xc000000e;
    PoStartNextPowerIrp(param_2);
    IofCompleteRequest(param_2,0);
  }
  return lVar6;
}



===== NvdShutdownFlush @ 1c0002500 =====

/* long __cdecl NvdShutdownFlush(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl NvdShutdownFlush(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== WriteTraceEvent @ 1c0002528 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl WriteTraceEvent(struct _NVDIMM_DEVICE_EXTENSION * __ptr64,unsigned long,char const *
   __ptr64,...) */

void __cdecl WriteTraceEvent(_NVDIMM_DEVICE_EXTENSION *param_1,ulong param_2,char *param_3,...)

{
  char *pcVar1;
  uint uVar2;
  longlong lVar4;
  longlong lVar3;
  _tlgProvider_t *_Dest;
  undefined8 *puVar5;
  undefined8 *puVar6;
  _GUID *p_Var7;
  undefined8 in_R9;
  _NVDIMM_DEVICE_EXTENSION *p_Var8;
  undefined8 local_res20;
  undefined1 auStackY_1f8 [32];
  ulong local_1a8;
  undefined4 local_1a4;
  _tlgProvider_t *local_1a0;
  undefined8 *local_198;
  undefined8 local_190;
  undefined8 uStack_188;
  undefined8 local_180;
  undefined8 uStack_178;
  undefined8 *local_170 [2];
  _NVDIMM_DEVICE_EXTENSION *local_160;
  undefined4 local_158;
  undefined4 local_154;
  _tlgProvider_t *local_150;
  int local_148;
  undefined4 local_144;
  _tlgProvider_t local_138;
  char acStack_137 [254];
  undefined1 local_39;
  ulonglong local_38;
  
  if (param_2 != 0) {
    local_38 = __security_cookie ^ (ulonglong)auStackY_1f8;
    local_190 = 0;
    if ((param_2 < 4) || ((Microsoft_Windows_PersistentMemory_NvdimmEnableBits & 0x10) != 0)) {
      local_res20 = in_R9;
      memset(&local_138,0,0x100);
      _Dest = &local_138;
      puVar6 = (undefined8 *)0xff;
      uVar2 = _vsnprintf((char *)_Dest,0xff,param_3,(va_list)&local_res20);
      if ((-1 < (int)uVar2) && (uVar2 < 0x100)) {
        if (uVar2 == 0xff) {
          local_39 = 0;
        }
        if ((Microsoft_Windows_PersistentMemory_NvdimmEnableBits & 0x10) != 0) {
          local_160 = param_1 + 400;
          local_180 = 0;
          uStack_178 = 0;
          uStack_188 = 0x2000000000000000;
          local_190 = (ulonglong)CONCAT14((char)param_2,0x11000384);
          if (param_1 == (_NVDIMM_DEVICE_EXTENSION *)0x0) {
            local_160 = (_NVDIMM_DEVICE_EXTENSION *)local_170;
          }
          local_154 = 0;
          local_150 = &local_138;
          local_158 = 0x10;
          lVar4 = -1;
          do {
            lVar3 = lVar4 + 1;
            pcVar1 = acStack_137 + lVar4;
            lVar4 = lVar3;
          } while (*pcVar1 != '\0');
          local_144 = 0;
          puVar6 = &local_190;
          local_148 = (int)lVar3 + 1;
          _Dest = nvdimmEventProvider_Context;
          EtwWrite(nvdimmEventProvider_Context,puVar6,&local_180,2);
        }
        if (param_2 < 4) {
          puVar5 = (undefined8 *)0x0;
          p_Var7 = (_GUID *)0x0;
          local_180 = 0;
          uStack_178 = 0;
          if (param_1 != (_NVDIMM_DEVICE_EXTENSION *)0x0) {
            local_180 = *(undefined8 *)(param_1 + 400);
            uStack_178 = *(undefined8 *)(param_1 + 0x198);
            p_Var7 = (_GUID *)(ulonglong)*(uint *)(param_1 + 0x20);
            puVar5 = *(undefined8 **)(param_1 + 0x188);
          }
          puVar6 = puVar5;
          if (((5 < DAT_1c0018058) && ((_DAT_1c0018068 & 0x400000000000) != 0)) &&
             ((DAT_1c0018070 & 0x400000000000) == DAT_1c0018070)) {
            local_1a0 = &local_138;
            puVar6 = (undefined8 *)&DAT_1c0015191;
            local_170[0] = &local_180;
            local_1a4 = SUB84(p_Var7,0);
            local_190 = 0x1000000;
            local_1a8 = param_2;
            local_198 = puVar5;
            _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
            ::
            Write<_tlgWrapperByVal<8>,_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapSz<char>_>
                      (_Dest,&DAT_1c0015191,p_Var7,(_GUID *)0x400000000000,
                       (_tlgWrapperByVal<8> *)&local_190,(_tlgWrapperByRef<16> *)local_170,
                       (_tlgWrapperByVal<4> *)&local_1a4,(_tlgWrapSz<char> *)&local_198,
                       (_tlgWrapperByVal<4> *)&local_1a8,(_tlgWrapSz<char> *)&local_1a0);
          }
        }
        if (param_2 < 3) {
          local_180 = 0;
          uStack_178 = 0;
          if (param_1 == (_NVDIMM_DEVICE_EXTENSION *)0x0) {
            local_190 = 0;
            uStack_188 = 0;
            if ((Microsoft_Windows_PersistentMemory_NvdimmEnableBits & 4) == 0) {
              return;
            }
            p_Var8 = (_NVDIMM_DEVICE_EXTENSION *)&local_190;
          }
          else {
            if ((Microsoft_Windows_PersistentMemory_NvdimmEnableBits & 4) == 0) {
              return;
            }
            p_Var8 = param_1 + 400;
          }
          McTemplateK0js_EtwWriteTransfer
                    (&nvdimmEventProvider_Context,puVar6,&local_180,p_Var8,(char *)&local_138);
        }
      }
    }
  }
  return;
}



===== McGenControlCallbackV2 @ 1c00027c0 =====

void McGenControlCallbackV2
               (undefined8 param_1,int param_2,undefined1 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,longlong param_7)

{
  uint *puVar1;
  ulonglong uVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  
  if (param_7 != 0) {
    if (param_2 == 0) {
      *(undefined4 *)(param_7 + 0x24) = 0;
      *(undefined1 *)(param_7 + 0x28) = 0;
      *(undefined8 *)(param_7 + 0x10) = 0;
      *(undefined8 *)(param_7 + 0x18) = 0;
      if (*(ushort *)(param_7 + 0x2a) != 0) {
        iVar4 = *(ushort *)(param_7 + 0x2a) - 1;
        memset(*(void **)(param_7 + 0x30),0,
               (longlong)(((int)(iVar4 + (iVar4 >> 0x1f & 0x1fU)) >> 5) + 1) << 2);
      }
    }
    else if (param_2 == 1) {
      *(undefined1 *)(param_7 + 0x28) = param_3;
      uVar7 = 0;
      *(undefined8 *)(param_7 + 0x18) = param_5;
      *(undefined8 *)(param_7 + 0x10) = param_4;
      *(undefined4 *)(param_7 + 0x24) = 1;
      if (*(short *)(param_7 + 0x2a) != 0) {
        do {
          uVar2 = *(ulonglong *)(*(longlong *)(param_7 + 0x38) + uVar7 * 8);
          if (((*(byte *)(param_7 + 0x28) < *(byte *)(uVar7 + *(longlong *)(param_7 + 0x40))) &&
              (*(byte *)(param_7 + 0x28) != 0)) ||
             ((uVar2 != 0 &&
              (((*(ulonglong *)(param_7 + 0x10) & uVar2) == 0 ||
               ((*(ulonglong *)(param_7 + 0x18) & uVar2) != *(ulonglong *)(param_7 + 0x18))))))) {
            bVar3 = false;
          }
          else {
            bVar3 = true;
          }
          uVar5 = 1 << ((byte)uVar7 & 0x1f);
          puVar1 = (uint *)(*(longlong *)(param_7 + 0x30) + (uVar7 >> 5) * 4);
          uVar6 = *puVar1;
          if (bVar3) {
            uVar5 = uVar5 | uVar6;
          }
          else {
            uVar5 = ~uVar5 & uVar6;
          }
          *puVar1 = uVar5;
          uVar6 = (int)uVar7 + 1;
          uVar7 = (ulonglong)uVar6;
        } while (uVar6 < *(ushort *)(param_7 + 0x2a));
      }
    }
  }
  return;
}



===== McGenEventRegister_EtwRegister @ 1c00028d0 =====

void McGenEventRegister_EtwRegister(void)

{
  if (nvdimmEventProvider_Context == 0) {
    EtwRegister(&nvdimmEventProvider,McGenControlCallbackV2,&nvdimmEventProvider_Context,
                &nvdimmEventProvider_Context);
  }
  return;
}



===== McGenEventUnregister_EtwUnregister @ 1c0002910 =====

undefined8 McGenEventUnregister_EtwUnregister(void)

{
  undefined8 uVar1;
  
  if (nvdimmEventProvider_Context == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    nvdimmEventProvider_Context = 0;
  }
  return uVar1;
}



===== McGenEventWrite_EtwWriteTransfer @ 1c0002944 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = (ushort *)param_1[1];
  uVar2 = 0;
  if (puVar1 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = puVar1;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(*param_1,param_2,param_3,0,param_4,param_5);
  return;
}



===== McTemplateK0js_EtwWriteTransfer @ 1c00029a4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0js_EtwWriteTransfer
               (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               char *param_5)

{
  longlong lVar1;
  undefined1 auStackY_78 [32];
  undefined8 local_48 [2];
  undefined8 local_38;
  undefined8 local_30;
  char *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_30 = 0x10;
  if (param_5 == (char *)0x0) {
    local_20 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_5[lVar1] != '\0');
    local_20 = (int)lVar1 + 1;
  }
  local_1c = 0;
  if (param_5 == (char *)0x0) {
    param_5 = "NULL";
  }
  local_38 = param_4;
  local_28 = param_5;
  McGenEventWrite_EtwWriteTransfer(param_1,&EventInternalError,param_3,3,local_48);
  return;
}



===== MakeNvdimmObject @ 1c0002a44 =====

/* class Nvdimm * __ptr64 __cdecl NvdimmFactory::MakeNvdimmObject(struct _NVDIMM_DEVICE_EXTENSION *
   __ptr64,unsigned char,unsigned short * __ptr64) */

Nvdimm * __cdecl
NvdimmFactory::MakeNvdimmObject(_NVDIMM_DEVICE_EXTENSION *param_1,uchar param_2,ushort *param_3)

{
  bool bVar1;
  Nvdimm *pNVar2;
  VNvdimm *this;
  INvdimm *this_00;
  int iVar3;
  
  iVar3 = 0x101;
  bVar1 = ContainsFormatInterfaceCode(param_3,param_2,0x101);
  if (bVar1) {
    pNVar2 = (Nvdimm *)ExAllocatePool2(0x40,iVar3 + 0x67,0x6344564e);
    if (pNVar2 == (Nvdimm *)0x0) {
      pNVar2 = (Nvdimm *)0x0;
    }
    else {
      *(_NVDIMM_DEVICE_EXTENSION **)(pNVar2 + 0x10) = param_1;
      *(undefined ***)pNVar2 = &NvdimmN::_vftable_;
      *(code **)(pNVar2 + 0x18) = NvdNotifyHealthChange;
      KeInitializeMutex(pNVar2 + 0x48,0);
      KeInitializeDpc(pNVar2 + 0x120,NvdimmNUtil::NvdnDeferredDsmDependentInitDpcRoutine,param_1);
      KeInitializeTimer(pNVar2 + 0xe0);
      *(undefined4 *)(pNVar2 + 8) = 0;
      *(undefined8 *)(pNVar2 + 0x160) = *(undefined8 *)(param_1 + 0x1b8);
    }
    return pNVar2;
  }
  bVar1 = ContainsFormatInterfaceCode(param_3,param_2,0x1901);
  if (bVar1) {
    this = (VNvdimm *)ExAllocatePool2(0x40,0x78,0x6344564e);
    if (this == (VNvdimm *)0x0) {
      return (Nvdimm *)0x0;
    }
    pNVar2 = (Nvdimm *)VNvdimm::VNvdimm(this,param_1);
  }
  else {
    iVar3 = 0x301;
    bVar1 = ContainsFormatInterfaceCode(param_3,param_2,0x301);
    if (!bVar1) {
      bVar1 = ContainsFormatInterfaceCode(param_3,param_2,0x1900);
      if (!bVar1) {
        return (Nvdimm *)0x0;
      }
      pNVar2 = (Nvdimm *)ExAllocatePool2(0x40,0x20,0x6344564e);
      if (pNVar2 == (Nvdimm *)0x0) {
        return (Nvdimm *)0x0;
      }
      *(_NVDIMM_DEVICE_EXTENSION **)(pNVar2 + 0x10) = param_1;
      *(undefined ***)pNVar2 = &SimulatedNvdimm::_vftable_;
      *(undefined8 *)(pNVar2 + 0x18) = *(undefined8 *)(param_1 + 0x1b8);
      *(undefined4 *)(pNVar2 + 8) = 0;
      return pNVar2;
    }
    this_00 = (INvdimm *)ExAllocatePool2(0x40,iVar3 + 0x67,0x6344564e);
    if (this_00 == (INvdimm *)0x0) {
      return (Nvdimm *)0x0;
    }
    pNVar2 = (Nvdimm *)INvdimm::INvdimm(this_00,param_1);
  }
  return pNVar2;
}



===== NvdPnpDeviceStateCompletion @ 1c0002bf0 =====

/* long __cdecl NvdPnpDeviceStateCompletion(struct _DEVICE_OBJECT * __ptr64,struct _IRP *
   __ptr64,void * __ptr64) */

long __cdecl NvdPnpDeviceStateCompletion(_DEVICE_OBJECT *param_1,_IRP *param_2,void *param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0x30);
  if (param_2[0x41] != (_IRP)0x0) {
    *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) = *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) | 1;
  }
  if (((-1 < iVar1) && (*(int *)(*(longlong *)(param_1 + 0x40) + 0x110) == 0)) &&
     ((*(ulonglong *)(param_2 + 0x38) & 0x20) != 0)) {
    *(ulonglong *)(param_2 + 0x38) = *(ulonglong *)(param_2 + 0x38) & 0xffffffffffffffdf;
  }
  return iVar1;
}



===== NvdPnpDispatch @ 1c0002c40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl NvdPnpDispatch(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl NvdPnpDispatch(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  byte bVar1;
  char cVar2;
  _NVDIMM_DEVICE_EXTENSION *p_Var3;
  longlong lVar4;
  long lVar5;
  
  p_Var3 = *(_NVDIMM_DEVICE_EXTENSION **)(param_1 + 0x40);
  lVar4 = *(longlong *)(param_2 + 0xb8);
  bVar1 = *(byte *)(lVar4 + 1);
  IoAcquireRemoveLockEx(p_Var3 + 0xf0,param_2,"",1,0x20);
  cVar2 = *(char *)(lVar4 + 1);
  WriteTraceEvent(p_Var3,5,"DIMM %d, Irp %p, Pnp, Minor %x\n",(ulonglong)*(uint *)(p_Var3 + 0x20),
                  param_2,(uint)bVar1);
  if ((bVar1 < 0x1a) && ((code *)(&NvdPnpDispatchTable)[bVar1] != (code *)0x0)) {
    lVar5 = (*(code *)(&NvdPnpDispatchTable)[bVar1])(param_1,param_2);
  }
  else {
    lVar5 = NvdPassIrp(param_1,param_2);
  }
  WriteTraceEvent(p_Var3,5,"Disk Number %d, Irp %p, Pnp Minor %x, ret = %08x\n",
                  (ulonglong)*(uint *)(p_Var3 + 0x20),param_2,(uint)bVar1,lVar5);
  if (cVar2 != '\x02') {
    IoReleaseRemoveLockEx(p_Var3 + 0xf0,param_2,0x20);
  }
  return lVar5;
}



===== NvdUsageNotification @ 1c0002d60 =====

/* long __cdecl NvdUsageNotification(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl NvdUsageNotification(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  _NVDIMM_DEVICE_EXTENSION *p_Var1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  p_Var1 = *(_NVDIMM_DEVICE_EXTENSION **)(param_1 + 0x40);
  uVar4 = NvdDeferProcessing(param_1,param_2);
  if ((int)uVar4 < 0) {
    WriteTraceEvent(p_Var1,2,"NvdUsageNotification: lower driver returned NTSTATUS 0x%x",
                    (ulonglong)uVar4);
    goto LAB_1c0002e21;
  }
  lVar2 = *(longlong *)(param_2 + 0xb8);
  iVar5 = *(int *)(p_Var1 + 0x110);
  if (*(char *)(lVar2 + 8) == '\0') {
    if (iVar5 != 0) {
      iVar5 = iVar5 + -1;
      goto LAB_1c0002dc0;
    }
  }
  else {
    iVar5 = iVar5 + 1;
LAB_1c0002dc0:
    *(int *)(p_Var1 + 0x110) = iVar5;
  }
  WriteTraceEvent(p_Var1,4,
                  "NvdUsageNotification: Special file notification, type = %u, inPath = %u, new count = %u"
                  ,(ulonglong)*(uint *)(lVar2 + 0x10),(uint)*(byte *)(lVar2 + 8),iVar5);
  uVar3 = *(uint *)(param_1 + 0x30) & 0xffffdfff;
  if (*(int *)(p_Var1 + 0x110) == 0) {
    uVar3 = *(uint *)(param_1 + 0x30) | 0x2000;
  }
  *(uint *)(param_1 + 0x30) = uVar3;
  if (*(uint *)(p_Var1 + 0x110) < 2) {
    IoInvalidateDeviceState(*(undefined8 *)(p_Var1 + 0x10));
  }
  *(uint *)(param_2 + 0x30) = uVar4;
LAB_1c0002e21:
  IofCompleteRequest(param_2,0);
  return uVar4;
}



===== RtlStringCchPrintfW @ 1c0002e50 =====

/* long __cdecl RtlStringCchPrintfW(unsigned short * __ptr64,unsigned __int64,unsigned short const *
   __ptr64,...) */

long __cdecl RtlStringCchPrintfW(ushort *param_1,__uint64 param_2,ushort *param_3,...)

{
  ulonglong _Count;
  int iVar1;
  long lVar2;
  undefined8 in_R9;
  undefined8 local_res20;
  
  if (param_2 - 1 < 0x7fffffff) {
    _Count = param_2 - 1;
    lVar2 = 0;
    local_res20 = in_R9;
    iVar1 = _vsnwprintf((wchar_t *)param_1,_Count,(wchar_t *)param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (_Count < (ulonglong)(longlong)iVar1)) {
      lVar2 = -0x7ffffffb;
    }
    else if ((longlong)iVar1 != _Count) {
      return 0;
    }
    param_1[_Count] = 0;
  }
  else {
    lVar2 = -0x3ffffff3;
    if (param_2 != 0) {
      *param_1 = 0;
    }
  }
  return lVar2;
}



===== McTemplateK0jdsssz_EtwWriteTransfer @ 1c0002ecc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0jdsssz_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,char *param_6,char *param_7,char *param_8,wchar_t *param_9)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 auStackY_b8 [32];
  undefined8 local_88 [2];
  undefined8 local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  char *local_58;
  int local_50;
  undefined4 local_4c;
  char *local_48;
  int local_40;
  undefined4 local_3c;
  char *local_38;
  int local_30;
  undefined4 local_2c;
  wchar_t *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_68 = &param_5;
  lVar2 = -1;
  local_70 = 0x10;
  local_60 = 4;
  if (param_6 == (char *)0x0) {
    local_50 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_6[lVar1] != '\0');
    local_50 = (int)lVar1 + 1;
  }
  local_4c = 0;
  local_58 = param_6;
  if (param_6 == (char *)0x0) {
    local_58 = "NULL";
  }
  if (param_7 == (char *)0x0) {
    local_40 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_7[lVar1] != '\0');
    local_40 = (int)lVar1 + 1;
  }
  local_3c = 0;
  local_48 = param_7;
  if (param_7 == (char *)0x0) {
    local_48 = "NULL";
  }
  if (param_8 == (char *)0x0) {
    local_30 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_8[lVar1] != '\0');
    local_30 = (int)lVar1 + 1;
  }
  local_2c = 0;
  local_38 = param_8;
  if (param_8 == (char *)0x0) {
    local_38 = "NULL";
  }
  if (param_9 == (wchar_t *)0x0) {
    local_20 = 10;
  }
  else {
    do {
      lVar2 = lVar2 + 1;
    } while (param_9[lVar2] != L'\0');
    local_20 = (int)lVar2 * 2 + 2;
  }
  local_1c = 0;
  local_28 = param_9;
  if (param_9 == (wchar_t *)0x0) {
    local_28 = L"NULL";
  }
  local_78 = param_4;
  McGenEventWrite_EtwWriteTransfer
            (&nvdimmEventProvider_Context,&EventStartDeviceSucceeded,param_3,7,local_88);
  return;
}



===== McTemplateK0jdssszqq_EtwWriteTransfer @ 1c0003038 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0jdssszqq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,char *param_6,char *param_7,char *param_8,wchar_t *param_9,
               undefined1 param_10,undefined1 param_11)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 auStackY_e8 [32];
  undefined8 local_b8 [2];
  undefined8 local_a8;
  undefined8 local_a0;
  undefined1 *local_98;
  undefined8 local_90;
  char *local_88;
  int local_80;
  undefined4 local_7c;
  char *local_78;
  int local_70;
  undefined4 local_6c;
  char *local_68;
  int local_60;
  undefined4 local_5c;
  wchar_t *local_58;
  int local_50;
  undefined4 local_4c;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_98 = &param_5;
  lVar2 = -1;
  local_a0 = 0x10;
  local_90 = 4;
  if (param_6 == (char *)0x0) {
    local_80 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_6[lVar1] != '\0');
    local_80 = (int)lVar1 + 1;
  }
  local_7c = 0;
  local_88 = param_6;
  if (param_6 == (char *)0x0) {
    local_88 = "NULL";
  }
  if (param_7 == (char *)0x0) {
    local_70 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_7[lVar1] != '\0');
    local_70 = (int)lVar1 + 1;
  }
  local_6c = 0;
  local_78 = param_7;
  if (param_7 == (char *)0x0) {
    local_78 = "NULL";
  }
  if (param_8 == (char *)0x0) {
    local_60 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_8[lVar1] != '\0');
    local_60 = (int)lVar1 + 1;
  }
  local_5c = 0;
  local_68 = param_8;
  if (param_8 == (char *)0x0) {
    local_68 = "NULL";
  }
  if (param_9 == (wchar_t *)0x0) {
    local_50 = 10;
  }
  else {
    do {
      lVar2 = lVar2 + 1;
    } while (param_9[lVar2] != L'\0');
    local_50 = (int)lVar2 * 2 + 2;
  }
  local_4c = 0;
  local_58 = param_9;
  if (param_9 == (wchar_t *)0x0) {
    local_58 = L"NULL";
  }
  local_40 = 4;
  local_48 = &param_10;
  local_38 = &param_11;
  local_30 = 4;
  local_a8 = param_4;
  McGenEventWrite_EtwWriteTransfer(&nvdimmEventProvider_Context,param_2,param_3,9,local_b8);
  return;
}



===== NvdDeviceControlDispatch @ 1c00031c0 =====

/* long __cdecl NvdDeviceControlDispatch(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl NvdDeviceControlDispatch(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  _NVDIMM_DEVICE_EXTENSION *p_Var1;
  uint uVar2;
  _NVDIMM_DEVICE_EXTENSION *p_Var3;
  undefined8 *puVar4;
  int iVar5;
  long lVar6;
  uchar local_res8 [8];
  uint uVar7;
  
  p_Var3 = *(_NVDIMM_DEVICE_EXTENSION **)(param_1 + 0x40);
  local_res8[0] = '\0';
  p_Var1 = p_Var3 + 0xf0;
  iVar5 = IoAcquireRemoveLockEx(p_Var1,param_2,"",1,0x20);
  if (iVar5 == 0) {
    uVar2 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 0x18);
    uVar7 = uVar2;
    WriteTraceEvent(p_Var3,5,"DIMM Handle %d, Irp %p, Ioctl = %08x\n",
                    (ulonglong)*(uint *)(p_Var3 + 0x20),param_2,uVar2);
    if (uVar2 == 0x591800) {
      lVar6 = NvdQueryProperty(p_Var3,param_2,local_res8);
    }
    else if (uVar2 == 0x591810) {
      lVar6 = NvdRefreshManagementStatus(p_Var3,param_2,local_res8);
    }
    else if (uVar2 == 0x592000) {
      lVar6 = NvdQueryPrivateProperty(p_Var3,param_2,local_res8);
    }
    else if (uVar2 == 0x599804) {
      lVar6 = NvdFirmwareDownloadIoctl(p_Var3,param_2,local_res8);
    }
    else if (uVar2 == 0x599808) {
      lVar6 = NvdFirmwareActivateIoctl(p_Var3,param_2,local_res8);
    }
    else if (uVar2 == 0x599814) {
      lVar6 = NvdReinitializeMediaIoctl(p_Var3,param_2,local_res8);
    }
    else if (uVar2 == 0x599818) {
      lVar6 = NvdSetProperty(p_Var3,param_2,local_res8);
    }
    else {
      if (uVar2 != 0x59d80c) {
        WriteTraceEvent(p_Var3,5,"IoDeviceControl: Unknown device IOCTL %x for %p\n",
                        (ulonglong)uVar2,param_1,uVar7);
        puVar4 = *(undefined8 **)(param_2 + 0xb8);
        puVar4[-9] = *puVar4;
        puVar4[-8] = puVar4[1];
        puVar4[-7] = puVar4[2];
        puVar4[-6] = puVar4[3];
        *(undefined4 *)(puVar4 + -5) = *(undefined4 *)(puVar4 + 4);
        *(undefined4 *)((longlong)puVar4 + -0x24) = *(undefined4 *)((longlong)puVar4 + 0x24);
        *(undefined4 *)(puVar4 + -4) = *(undefined4 *)(puVar4 + 5);
        *(undefined4 *)((longlong)puVar4 + -0x1c) = *(undefined4 *)((longlong)puVar4 + 0x2c);
        puVar4[-3] = puVar4[6];
        *(undefined1 *)((longlong)puVar4 + -0x45) = 0;
        IoReleaseRemoveLockEx(p_Var1,param_2,0x20);
        lVar6 = IofCallDriver(*(undefined8 *)(p_Var3 + 8),param_2);
        return lVar6;
      }
      lVar6 = NvdPassthroughCommandIoctl(p_Var3,param_2,local_res8);
    }
    WriteTraceEvent(p_Var3,5,"DIMM Handle %d, Irp %p, Ioctl = %08x, ret = %08x\n",
                    (ulonglong)*(uint *)(p_Var3 + 0x20),param_2,uVar2,lVar6);
    IoReleaseRemoveLockEx(p_Var1,param_2,0x20);
    if (local_res8[0] != '\0') {
      return lVar6;
    }
  }
  else {
    *(undefined8 *)(param_2 + 0x38) = 0;
    lVar6 = -0x3ffffff2;
  }
  *(long *)(param_2 + 0x30) = lVar6;
  IofCompleteRequest(param_2,0);
  return lVar6;
}



===== operator_delete @ 1c00033fc =====

/* void __cdecl operator delete(void * __ptr64) */

void __cdecl operator_delete(void *param_1)

{
  if (param_1 != (void *)0x0) {
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== NvdPnpCompletion @ 1c0003420 =====

/* long __cdecl NvdPnpCompletion(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64,void *
   __ptr64) */

long __cdecl NvdPnpCompletion(_DEVICE_OBJECT *param_1,_IRP *param_2,void *param_3)

{
  KeSetEvent(param_3,1);
  return -0x3fffffea;
}



===== NvdSignalCompletion @ 1c0003450 =====

/* long __cdecl NvdSignalCompletion(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64,void *
   __ptr64) */

long __cdecl NvdSignalCompletion(_DEVICE_OBJECT *param_1,_IRP *param_2,void *param_3)

{
  long lVar1;
  
  if (param_3 == (void *)0x0) {
    lVar1 = -0x3ffffff3;
  }
  else {
    KeSetEvent(param_3,0,0);
    lVar1 = -0x3fffffea;
  }
  return lVar1;
}



===== NvdNotifyLogicalDisksOfHealthChange @ 1c0003488 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl NvdNotifyLogicalDisksOfHealthChange(struct _NVDIMM_DEVICE_EXTENSION * __ptr64) */

long __cdecl NvdNotifyLogicalDisksOfHealthChange(_NVDIMM_DEVICE_EXTENSION *param_1)

{
  longlong ****pppplVar1;
  longlong ****pppplVar2;
  longlong ****pppplVar3;
  code *pcVar4;
  longlong ***ppplVar5;
  longlong ****pppplVar6;
  _NVDIMM_DEVICE_EXTENSION *p_Var7;
  longlong ****local_38;
  longlong ****local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_30 = (longlong ****)&local_38;
  local_38 = (longlong ****)&local_38;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  KeAcquireInStackQueuedSpinLock(param_1 + 0x1c8,&local_28);
  for (p_Var7 = *(_NVDIMM_DEVICE_EXTENSION **)(param_1 + 0x1d0); p_Var7 != param_1 + 0x1d0;
      p_Var7 = *(_NVDIMM_DEVICE_EXTENSION **)p_Var7) {
    pppplVar6 = (longlong ****)ExAllocatePool2(0x40,0x20,0x6f6e764e);
    if (pppplVar6 != (longlong ****)0x0) {
      ppplVar5 = *(longlong ****)(p_Var7 + 8);
      *pppplVar6 = *(longlong ****)p_Var7;
      pppplVar6[1] = ppplVar5;
      ppplVar5 = *(longlong ****)(p_Var7 + 0x18);
      pppplVar6[2] = *(longlong ****)(p_Var7 + 0x10);
      pppplVar6[3] = ppplVar5;
      *pppplVar6 = (longlong ***)0x0;
      pppplVar6[1] = (longlong ***)0x0;
      if ((longlong *****)*local_30 != &local_38) goto LAB_1c0003595;
      pppplVar6[1] = (longlong ***)local_30;
      *pppplVar6 = (longlong ***)&local_38;
      *local_30 = (longlong ***)pppplVar6;
      local_30 = pppplVar6;
    }
  }
  KeReleaseInStackQueuedSpinLock(&local_28);
  while( true ) {
    pppplVar6 = local_38;
    if ((longlong *****)local_38 == &local_38) {
      return 0;
    }
    if (((longlong *****)local_38[1] != &local_38) ||
       (pppplVar3 = (longlong ****)*local_38, (longlong ****)pppplVar3[1] != local_38)) break;
    pppplVar3[1] = (longlong ***)&local_38;
    pppplVar1 = local_38 + 2;
    pppplVar2 = local_38 + 3;
    local_38 = pppplVar3;
    (*(code *)*pppplVar1)(*pppplVar2,1);
    ExFreePoolWithTag(pppplVar6,0);
  }
LAB_1c0003595:
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  return 0;
}



===== NvdSendPnpHealthChangeNotification @ 1c00035b8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl NvdSendPnpHealthChangeNotification(struct _NVDIMM_DEVICE_EXTENSION * __ptr64) */

long __cdecl NvdSendPnpHealthChangeNotification(_NVDIMM_DEVICE_EXTENSION *param_1)

{
  long lVar1;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined8 local_44;
  undefined8 uStack_3c;
  undefined4 local_34;
  undefined8 local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  local_34 = 0;
  local_30 = 0;
  local_28 = 0xffffffff;
  local_44 = 0x4ee372f59da2d386;
  uStack_3c = 0x63b8e67a0ec5581;
  local_48 = 0x340001;
  local_24 = *(undefined4 *)(param_1 + 400);
  uStack_20 = *(undefined4 *)(param_1 + 0x194);
  uStack_1c = *(undefined4 *)(param_1 + 0x198);
  uStack_18 = *(undefined4 *)(param_1 + 0x19c);
  lVar1 = IoReportTargetDeviceChangeAsynchronous(*(undefined8 *)(param_1 + 0x10),&local_48,0,0);
  return lVar1;
}



===== AddAllOperationalStatusReasonsToArray @ 1c0003634 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl AddAllOperationalStatusReasonsToArray(struct _NVDIMM_DEVICE_EXTENSION * __ptr64,enum
   _SCM_PD_OPERATIONAL_STATUS * __ptr64,unsigned long,enum _SCM_PD_OPERATIONAL_STATUS_REASON *
   __ptr64,unsigned long,unsigned long * __ptr64,unsigned long * __ptr64) */

void __cdecl
AddAllOperationalStatusReasonsToArray
          (_NVDIMM_DEVICE_EXTENSION *param_1,_SCM_PD_OPERATIONAL_STATUS *param_2,ulong param_3,
          _SCM_PD_OPERATIONAL_STATUS_REASON *param_4,ulong param_5,ulong *param_6,ulong *param_7)

{
  _SCM_PD_OPERATIONAL_STATUS_REASON *p_Var1;
  _SCM_PD_OPERATIONAL_STATUS_REASON _Var2;
  uint uVar3;
  char cVar4;
  char *pcVar5;
  uint uVar6;
  undefined1 auStack_98 [32];
  char *local_78;
  uint *local_68;
  undefined8 local_60;
  char local_58 [24];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_98;
  local_68 = param_7;
  local_78 = local_58;
  local_60 = 0;
  local_58[0x10] = '\0';
  local_58[0x11] = '\0';
  local_58[0x12] = '\0';
  local_58[0x13] = '\0';
  local_58[0x14] = '\0';
  local_58[0x15] = '\0';
  local_58[0x16] = 0;
  local_58[0] = '\0';
  local_58[1] = '\0';
  local_58[2] = '\0';
  local_58[3] = '\0';
  local_58[4] = '\0';
  local_58[5] = '\0';
  local_58[6] = '\0';
  local_58[7] = '\0';
  local_58[8] = '\0';
  local_58[9] = '\0';
  local_58[10] = '\0';
  local_58[0xb] = '\0';
  local_58[0xc] = '\0';
  local_58[0xd] = '\0';
  local_58[0xe] = '\0';
  local_58[0xf] = '\0';
  uVar6 = 0;
  uVar3 = (**(code **)(**(longlong **)(param_1 + 0x18) + 0x38))
                    (*(longlong **)(param_1 + 0x18),8,&local_60,0x17);
  if ((int)uVar3 < 0) {
    WriteTraceEvent(param_1,2,
                    "AddAllOperationalStatusReasonsToArray(): Nvdimm->GetOperationalStatus() failed with 0x%x"
                    ,(ulonglong)uVar3);
    uVar3 = 0;
    uVar6 = 0;
  }
  else {
    if (param_1[0xe5] == (_NVDIMM_DEVICE_EXTENSION)0x0) {
      cVar4 = local_60._4_1_;
    }
    else {
      local_58[0xd] = 1;
      cVar4 = '\x01';
    }
    if (*(int *)(param_1 + 0x48) != 0) {
      local_58[1] = 1;
      cVar4 = '\x01';
    }
    pcVar5 = local_58;
    _Var2 = 0;
    do {
      if (*pcVar5 != '\0') {
        if (uVar6 < param_5) {
          uVar3 = 0;
          if (param_5 != 0) {
            p_Var1 = param_4;
            do {
              if (*p_Var1 == _Var2) goto LAB_1c0003732;
              uVar3 = uVar3 + 1;
              p_Var1 = p_Var1 + 1;
            } while (uVar3 < param_5);
          }
          param_4[uVar6] = _Var2;
        }
        uVar6 = uVar6 + 1;
      }
LAB_1c0003732:
      _Var2 = _Var2 + 1;
      pcVar5 = pcVar5 + 1;
    } while (_Var2 < 0x17);
    uVar3 = 0;
    if (local_60._5_1_ != '\0') {
      if (param_3 != 0) {
        *param_2 = 5;
      }
      uVar3 = 1;
    }
    if (cVar4 != '\0') {
      if (uVar3 < param_3) {
        param_2[uVar3] = 4;
      }
      uVar3 = uVar3 + 1;
    }
    if (local_60._6_1_ != '\0') {
      if (uVar3 < param_3) {
        param_2[uVar3] = 6;
      }
      uVar3 = uVar3 + 1;
    }
    if (local_60._2_1_ != '\0') {
      if (uVar3 < param_3) {
        param_2[uVar3] = 2;
      }
      uVar3 = uVar3 + 1;
    }
    if (uVar3 == 0) {
      if (param_3 != 0) {
        *param_2 = 1;
      }
      uVar3 = 1;
    }
  }
  *param_6 = uVar3;
  *local_68 = uVar6;
  return;
}



===== NvdGetDeviceManagementStatus @ 1c00037d8 =====

/* long __cdecl NvdGetDeviceManagementStatus(struct _NVDIMM_DEVICE_EXTENSION * __ptr64,struct
   _SCM_PD_MANAGEMENT_STATUS * __ptr64,unsigned long,unsigned long * __ptr64) */

long __cdecl
NvdGetDeviceManagementStatus
          (_NVDIMM_DEVICE_EXTENSION *param_1,_SCM_PD_MANAGEMENT_STATUS *param_2,ulong param_3,
          ulong *param_4)

{
  int iVar1;
  uint uVar2;
  _SCM_PD_MANAGEMENT_STATUS *p_Var3;
  undefined4 uVar4;
  uint uVar5;
  _SCM_PD_MANAGEMENT_STATUS *p_Var6;
  ulong local_res10 [2];
  ulong local_38 [4];
  
  uVar4 = 0;
  if (param_2 == (_SCM_PD_MANAGEMENT_STATUS *)0x0) {
    if (param_3 != 0) {
      return -0x3fffff10;
    }
LAB_1c000380e:
    uVar5 = 0;
  }
  else {
    if (param_3 < 8) {
      return -0x3fffff10;
    }
    if (param_3 < 0x58) goto LAB_1c000380e;
    uVar5 = param_3 - 0x54 >> 2;
  }
  local_38[0] = 0;
  local_res10[0] = 0;
  memset(param_2,0,(ulonglong)param_3);
  p_Var6 = param_2 + 0x54;
  if (uVar5 == 0) {
    p_Var6 = (_SCM_PD_MANAGEMENT_STATUS *)0x0;
  }
  p_Var3 = param_2 + 0x14;
  if (param_3 < 0x58) {
    p_Var3 = (_SCM_PD_MANAGEMENT_STATUS *)0x0;
  }
  AddAllOperationalStatusReasonsToArray
            (param_1,(_SCM_PD_OPERATIONAL_STATUS *)p_Var3,~-(uint)(param_3 < 0x58) & 0x10,
             (_SCM_PD_OPERATIONAL_STATUS_REASON *)p_Var6,uVar5,local_38,local_res10);
  uVar2 = 1;
  if (1 < local_res10[0]) {
    uVar2 = local_res10[0];
  }
  *param_4 = uVar2 * 4 + 0x54;
  if (7 < param_3) {
    *(undefined4 *)param_2 = 0x58;
    *(ulong *)(param_2 + 4) = *param_4;
  }
  if (param_3 < 0x58) {
    return 0;
  }
  iVar1 = *(int *)(param_2 + 0x14);
  if (iVar1 != 1) {
    if (iVar1 == 2) {
      uVar4 = 2;
      goto LAB_1c00038fa;
    }
    if (iVar1 != 3) {
      if ((((iVar1 == 4) || (iVar1 == 5)) || (iVar1 == 6)) || (iVar1 == 7)) {
        uVar4 = 1;
      }
      goto LAB_1c00038fa;
    }
  }
  uVar4 = 3;
LAB_1c00038fa:
  *(undefined4 *)(param_2 + 8) = uVar4;
  if (uVar5 < local_res10[0]) {
    local_res10[0] = uVar5;
  }
  *(ulong *)(param_2 + 0xc) = local_38[0];
  *(ulong *)(param_2 + 0x10) = local_res10[0];
  return 0;
}



===== NvdIntGetDeviceGuid @ 1c0003930 =====

/* long __cdecl NvdIntGetDeviceGuid(void * __ptr64,struct _GUID * __ptr64) */

long __cdecl NvdIntGetDeviceGuid(void *param_1,_GUID *param_2)

{
  undefined8 uVar1;
  
  if ((param_1 == (void *)0x0) || (param_2 == (_GUID *)0x0)) {
    return -0x3ffffff3;
  }
  uVar1 = *(undefined8 *)((longlong)param_1 + 0x198);
  *(undefined8 *)param_2 = *(undefined8 *)((longlong)param_1 + 400);
  *(undefined8 *)(param_2 + 8) = uVar1;
  return 0;
}



===== NvdIntGetDeviceManagementStatus @ 1c0003960 =====

/* long __cdecl NvdIntGetDeviceManagementStatus(void * __ptr64,struct _SCM_PD_MANAGEMENT_STATUS *
   __ptr64,unsigned long,unsigned long * __ptr64) */

long __cdecl
NvdIntGetDeviceManagementStatus
          (void *param_1,_SCM_PD_MANAGEMENT_STATUS *param_2,ulong param_3,ulong *param_4)

{
  long lVar1;
  
  if ((param_1 == (void *)0x0) || (param_4 == (ulong *)0x0)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = NvdGetDeviceManagementStatus(param_1,param_2,param_3,param_4);
  }
  return lVar1;
}



===== NvdIntGetFruIdString @ 1c0003990 =====

/* long __cdecl NvdIntGetFruIdString(void * __ptr64,struct _STRING * __ptr64) */

long __cdecl NvdIntGetFruIdString(void *param_1,_STRING *param_2)

{
  long lVar1;
  char *pcVar2;
  void *_Dst;
  longlong lVar3;
  size_t _Size;
  
  if ((param_1 == (void *)0x0) || (param_2 == (_STRING *)0x0)) {
    return -0x3ffffff3;
  }
  pcVar2 = *(char **)((longlong)param_1 + 0x188);
  if (pcVar2 != (char *)0x0) {
    lVar3 = 0x7fffffff;
    do {
      if (*pcVar2 == '\0') break;
      pcVar2 = pcVar2 + 1;
      lVar3 = lVar3 + -1;
    } while (lVar3 != 0);
    _Size = -(ulonglong)(lVar3 != 0) & 0x7fffffffU - lVar3;
    if (lVar3 != 0) goto LAB_1c00039f7;
  }
  _Size = 0;
LAB_1c00039f7:
  _Dst = (void *)ExAllocatePool2(0x100,_Size + 1,0x6966764e);
  *(void **)(param_2 + 8) = _Dst;
  if (_Dst == (void *)0x0) {
    lVar1 = -0x3fffff66;
  }
  else {
    *(short *)param_2 = (short)_Size;
    *(short *)(param_2 + 2) = (short)_Size + 1;
    memcpy(_Dst,*(void **)((longlong)param_1 + 0x188),_Size);
    lVar1 = 0;
  }
  return lVar1;
}



===== NvdIntGetLocationString @ 1c0003a70 =====

/* long __cdecl NvdIntGetLocationString(void * __ptr64,struct _UNICODE_STRING * __ptr64) */

long __cdecl NvdIntGetLocationString(void *param_1,_UNICODE_STRING *param_2)

{
  long lVar1;
  longlong lVar2;
  longlong lVar3;
  
  if ((param_1 == (void *)0x0) || (param_2 == (_UNICODE_STRING *)0x0)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar3 = (ulonglong)*(ushort *)((longlong)param_1 + 0x138) + 2;
    lVar2 = ExAllocatePool2(0x100,lVar3,0x6f6c764e);
    *(longlong *)(param_2 + 8) = lVar2;
    if (lVar2 == 0) {
      lVar1 = -0x3fffff66;
    }
    else {
      *(undefined2 *)param_2 = 0;
      *(short *)(param_2 + 2) = (short)lVar3;
      RtlCopyUnicodeString(param_2,(ushort *)((longlong)param_1 + 0x138));
      lVar1 = 0;
    }
  }
  return lVar1;
}



===== NvdIntGetSecurityState @ 1c0003b10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl NvdIntGetSecurityState(void * __ptr64,enum _SCM_PD_SECURITY_STATE * __ptr64) */

long __cdecl NvdIntGetSecurityState(void *param_1,_SCM_PD_SECURITY_STATE *param_2)

{
  _SCM_PD_SECURITY_STATE _Var1;
  long lVar2;
  
  if ((param_1 == (void *)0x0) || (param_2 == (_SCM_PD_SECURITY_STATE *)0x0)) {
    lVar2 = -0x3ffffff3;
  }
  else {
    _Var1 = (**(code **)(**(longlong **)((longlong)param_1 + 0x18) + 0x88))();
    *param_2 = _Var1;
    lVar2 = 0;
  }
  return lVar2;
}



===== NvdIntGetSlotNumber @ 1c0003b50 =====

/* long __cdecl NvdIntGetSlotNumber(void * __ptr64,unsigned long * __ptr64) */

long __cdecl NvdIntGetSlotNumber(void *param_1,ulong *param_2)

{
  if ((param_1 == (void *)0x0) || (param_2 == (ulong *)0x0)) {
    return -0x3ffffff3;
  }
  *param_2 = *(ulong *)((longlong)param_1 + 0x134);
  return 0;
}



===== NvdIntGetUnsafeShutdownCount @ 1c0003b80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl NvdIntGetUnsafeShutdownCount(void * __ptr64,unsigned long * __ptr64) */

long __cdecl NvdIntGetUnsafeShutdownCount(void *param_1,ulong *param_2)

{
  long lVar1;
  
  if ((param_1 == (void *)0x0) || (param_2 == (ulong *)0x0)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = (**(code **)(**(longlong **)((longlong)param_1 + 0x18) + 0x10))();
  }
  return lVar1;
}



===== NvdIntRegisterNvdimmNotification @ 1c0003bc0 =====

/* long __cdecl NvdIntRegisterNvdimmNotification(void * __ptr64,void (__cdecl*)(void * __ptr64,enum
   _NVDIMM_NOTFICIATION),void * __ptr64) */

long __cdecl
NvdIntRegisterNvdimmNotification
          (void *param_1,_func_void_void_ptr__NVDIMM_NOTFICIATION *param_2,void *param_3)

{
  code *pcVar1;
  long lVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined1 *puVar5;
  undefined8 *puVar6;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  if ((param_1 == (void *)0x0) || (param_2 == (_func_void_void_ptr__NVDIMM_NOTFICIATION *)0x0)) {
    lVar2 = -0x3ffffff3;
  }
  else {
    local_28 = 0;
    uStack_20 = 0;
    local_18 = 0;
    KeAcquireInStackQueuedSpinLock((longlong)param_1 + 0x1c8,&local_28);
    puVar6 = (undefined8 *)((longlong)param_1 + 0x1d0);
    for (puVar3 = (undefined8 *)*puVar6; puVar3 != puVar6; puVar3 = (undefined8 *)*puVar3) {
      if (((_func_void_void_ptr__NVDIMM_NOTFICIATION *)puVar3[2] == param_2) &&
         ((void *)puVar3[3] == param_3)) {
        KeReleaseInStackQueuedSpinLock(&local_28);
        return -0x3ffff8e8;
      }
    }
    KeReleaseInStackQueuedSpinLock(&local_28);
    puVar3 = (undefined8 *)ExAllocatePool2(0x40,0x20,0x6f6e764e);
    if (puVar3 == (undefined8 *)0x0) {
      lVar2 = -0x3fffff66;
    }
    else {
      puVar3[2] = param_2;
      puVar3[3] = param_3;
      KeAcquireInStackQueuedSpinLock((longlong)param_1 + 0x1c8,&local_28);
      puVar5 = auStack_48;
      puVar4 = *(undefined8 **)((longlong)param_1 + 0x1d8);
      if ((undefined8 *)*puVar4 != puVar6) {
        pcVar1 = (code *)swi(0x29);
        puVar4 = (undefined8 *)(*pcVar1)(3);
        puVar5 = auStack_40;
      }
      *puVar3 = puVar6;
      puVar3[1] = puVar4;
      *puVar4 = puVar3;
      *(undefined8 **)((longlong)param_1 + 0x1d8) = puVar3;
      *(undefined8 *)(puVar5 + -8) = 0x1c0003cd4;
      KeReleaseInStackQueuedSpinLock(puVar5 + 0x20);
      lVar2 = 0;
    }
  }
  return lVar2;
}



===== NvdIntUnregisterNvdimmNotification @ 1c0003d10 =====

/* long __cdecl NvdIntUnregisterNvdimmNotification(void * __ptr64,void (__cdecl*)(void *
   __ptr64,enum _NVDIMM_NOTFICIATION)) */

long __cdecl
NvdIntUnregisterNvdimmNotification(void *param_1,_func_void_void_ptr__NVDIMM_NOTFICIATION *param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  code *pcVar4;
  undefined8 *puVar5;
  long lVar6;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  if (param_1 == (void *)0x0) {
    lVar6 = -0x3ffffff3;
  }
  else {
    puVar1 = (undefined8 *)((longlong)param_1 + 0x1d0);
    puVar2 = (undefined8 *)*puVar1;
    local_28 = 0;
    uStack_20 = 0;
    local_18 = 0;
    KeAcquireInStackQueuedSpinLock((longlong)param_1 + 0x1c8,&local_28);
    do {
      puVar5 = puVar2;
      if (puVar5 == puVar1) goto LAB_1c0003d7c;
      puVar2 = (undefined8 *)*puVar5;
    } while ((_func_void_void_ptr__NVDIMM_NOTFICIATION *)puVar5[2] != param_2);
    if (((undefined8 *)puVar2[1] != puVar5) ||
       (puVar3 = (undefined8 *)puVar5[1], (undefined8 *)*puVar3 != puVar5)) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      pcVar4 = (code *)swi(3);
      lVar6 = (*pcVar4)();
      return lVar6;
    }
    *puVar3 = puVar2;
    puVar2[1] = puVar3;
    ExFreePoolWithTag(puVar5,0);
LAB_1c0003d7c:
    KeReleaseInStackQueuedSpinLock(&local_28);
    lVar6 = 0;
    if (puVar5 == puVar1) {
      lVar6 = -0x3ffffddb;
    }
  }
  return lVar6;
}



===== NvdIntUnsafeShutdownAcknowledged @ 1c0003df0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl NvdIntUnsafeShutdownAcknowledged(void * __ptr64) */

long __cdecl NvdIntUnsafeShutdownAcknowledged(void *param_1)

{
  long lVar1;
  
  if (param_1 == (void *)0x0) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = (**(code **)(**(longlong **)((longlong)param_1 + 0x18) + 0x18))();
  }
  return lVar1;
}



===== NvdInterfaceDereference @ 1c0003e20 =====

/* void __cdecl NvdInterfaceDereference(void * __ptr64) */

void __cdecl NvdInterfaceDereference(void *param_1)

{
  LOCK();
  *(int *)((longlong)param_1 + 0x1c0) = *(int *)((longlong)param_1 + 0x1c0) + -1;
  UNLOCK();
  IoReleaseRemoveLockEx((longlong)param_1 + 0xf0,param_1,0x20);
  return;
}



===== NvdInterfaceReference @ 1c0003e60 =====

/* void __cdecl NvdInterfaceReference(void * __ptr64) */

void __cdecl NvdInterfaceReference(void *param_1)

{
  LOCK();
  *(int *)((longlong)param_1 + 0x1c0) = *(int *)((longlong)param_1 + 0x1c0) + 1;
  UNLOCK();
  IoAcquireRemoveLockEx((longlong)param_1 + 0xf0,param_1,"",1,0x20);
  return;
}



===== VNvdimm @ 1c0003ea4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: __cdecl VNvdimm::VNvdimm(struct _NVDIMM_DEVICE_EXTENSION * __ptr64) __ptr64 */

VNvdimm * __thiscall VNvdimm::VNvdimm(VNvdimm *this,_NVDIMM_DEVICE_EXTENSION *param_1)

{
  VNvdimm *pVVar1;
  uint uVar2;
  long lVar3;
  char *pcVar4;
  undefined8 local_res10;
  undefined4 uVar5;
  
  *(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10) = param_1;
  *(undefined ***)this = &_vftable_;
  *(undefined8 *)(this + 0x18) = *(undefined8 *)(param_1 + 0x1b8);
  KeInitializeMutex(this + 0x38,0);
  pVVar1 = this + 0x74;
  local_res10 = 0;
  uVar5 = 0;
  uVar2 = (**(code **)(*(longlong *)(this + 0x10) + 0x78))
                    (*(undefined8 *)(*(longlong *)(this + 0x10) + 0x58),&DAT_1c00150b0,1,2,0,0,
                     &local_res10,8);
  if ((int)uVar2 < 0) {
    pcVar4 = 
    "VNvdimm::GetUnsafeShutdownCountFromDsm VDsmGetUnsafeShutdownCount() failed with NTSTATUS 0x%x";
LAB_1c0003f41:
    WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10),2,pcVar4,(ulonglong)uVar2);
  }
  else {
    if ((int)local_res10 != 0) {
      WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10),2,
                      "VNvdimm::GetUnsafeShutdownCountFromDsm: VDsmGetUnsafeShutdownCount() call failed with _DSM status 0x%x"
                     );
      if ((int)local_res10 == 0) {
        uVar2 = 0;
      }
      else if ((short)local_res10 == 1) {
        uVar2 = 0xc00000bb;
      }
      else {
        uVar2 = 0xc0000001;
        if ((short)local_res10 == 2) {
          uVar2 = 0xc000000d;
        }
      }
      goto LAB_1c0004026;
    }
    *(undefined4 *)(this + 0x70) = local_res10._4_4_;
    uVar2 = NvdQueryDeviceRegistryUlong
                      (*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10),(ushort *)L"",
                       (ushort *)L"BaselineUnsafeShutdownCount",(ulong *)pVVar1);
    if (uVar2 == 0xc0000034) {
      WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10),4,
                      "VNvdimm::GetUnsafeShutdownCountFromDsm: the baseline USC isn\'t in the registry, so assuming the current value (%d) as the baseline"
                      ,(ulonglong)*(uint *)(this + 0x70));
      uVar2 = UpdateBaselineUnsafeShutdownCount(this,*(ulong *)(this + 0x70));
      *(ulong *)pVVar1 = *(ulong *)(this + 0x70);
      if ((int)uVar2 < 0) goto LAB_1c0004026;
    }
    else if ((int)uVar2 < 0) {
      pcVar4 = 
      "VNvdimm::GetUnsafeShutdownCountFromDsm: VnvdQueryDeviceRegistryUlong() failed with NTSTATUS 0x%x"
      ;
      goto LAB_1c0003f41;
    }
    WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10),4,
                    "VNvdimm::GetUnsafeShutdownCountFromDsm: Current USC: %d; Baseline USC: %d",
                    (ulonglong)*(uint *)(this + 0x70),CONCAT44(uVar5,*(ulong *)pVVar1));
  }
LAB_1c0004026:
  *(uint *)(this + 8) = uVar2;
  if (-1 < (int)uVar2) {
    lVar3 = HandleDataLossFailures(this);
    *(long *)(this + 8) = lVar3;
  }
  return this;
}



===== `vector_deleting_destructor' @ 1c0004070 =====

/* public: virtual void * __ptr64 __cdecl SimulatedNvdimm::`vector deleting destructor'(unsigned
   int) __ptr64 */

void * __thiscall SimulatedNvdimm::_vector_deleting_destructor_(SimulatedNvdimm *this,uint param_1)

{
  *(undefined ***)this = &Nvdimm::_vftable_;
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0);
  }
  return this;
}



===== AcknowledgeUnsafeShutdown @ 1c00040b0 =====

/* public: virtual long __cdecl VNvdimm::AcknowledgeUnsafeShutdown(void) __ptr64 */

long __thiscall VNvdimm::AcknowledgeUnsafeShutdown(VNvdimm *this)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  char *pcVar4;
  
  uVar2 = UpdateBaselineUnsafeShutdownCount(this,*(ulong *)(this + 0x70));
  if ((int)uVar2 < 0) {
    pcVar4 = 
    "VNvdimm::AcknowledgeUnsafeShutdown: error writing updated baseline USC to registry: 0x%x";
    uVar3 = 2;
    uVar1 = uVar2;
  }
  else {
    pcVar4 = "VNvdimm::AcknowledgeUnsafeShutdown: baseline USC updated in the registry to %d";
    *(uint *)(this + 0x74) = *(uint *)(this + 0x70);
    uVar3 = 4;
    uVar1 = *(uint *)(this + 0x70);
  }
  WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10),uVar3,pcVar4,(ulonglong)uVar1);
  return uVar2;
}



===== ReinitializeMedia @ 1c0004110 =====

/* public: virtual long __cdecl Nvdimm::ReinitializeMedia(bool,enum
   _SCM_PD_MEDIA_REINITIALIZATION_STATUS * __ptr64) __ptr64 */

long __thiscall
Nvdimm::ReinitializeMedia(Nvdimm *this,bool param_1,_SCM_PD_MEDIA_REINITIALIZATION_STATUS *param_2)

{
  return -0x3fffff45;
}



===== GetCurrentFirmwareRevision @ 1c0004120 =====

/* public: virtual long __cdecl VNvdimm::GetCurrentFirmwareRevision(char * __ptr64 const) __ptr64 */

long __thiscall VNvdimm::GetCurrentFirmwareRevision(VNvdimm *this,char *param_1)

{
  long lVar1;
  
  lVar1 = RtlStringCchPrintfA(param_1,0x20,"1.0");
  return lVar1;
}



===== GetDeviceName @ 1c0004150 =====

/* public: virtual long __cdecl VNvdimm::GetDeviceName(unsigned short * __ptr64,unsigned long)
   __ptr64 */

long __thiscall VNvdimm::GetDeviceName(VNvdimm *this,ushort *param_1,ulong param_2)

{
  long lVar1;
  
  lVar1 = RtlStringCbPrintfW(param_1,param_2,(ushort *)L"Virtual NVDIMM device");
  return lVar1;
}



===== GetDeviceSpecificInfo @ 1c0004180 =====

/* public: virtual long __cdecl Nvdimm::GetDeviceSpecificInfo(class wistd::unique_ptr<struct
   _SCM_PD_DEVICE_SPECIFIC_INFO,struct wistd::default_delete<struct _SCM_PD_DEVICE_SPECIFIC_INFO> >
   * __ptr64) __ptr64 */

long __thiscall
Nvdimm::GetDeviceSpecificInfo
          (Nvdimm *this,
          unique_ptr<_SCM_PD_DEVICE_SPECIFIC_INFO,wistd::default_delete<_SCM_PD_DEVICE_SPECIFIC_INFO>_>
          *param_1)

{
  longlong lVar1;
  long lVar2;
  undefined8 uVar3;
  
  uVar3 = ExAllocatePool2(0x100,0x118,0x7370764e);
  lVar1 = *(longlong *)param_1;
  *(undefined8 *)param_1 = uVar3;
  if (lVar1 != 0) {
    ExFreePoolWithTag(lVar1,0);
  }
  if (*(longlong *)param_1 == 0) {
    lVar2 = -0x3fffff66;
  }
  else {
    *(undefined4 *)(*(longlong *)param_1 + 4) = 0x118;
    **(undefined4 **)param_1 = 0x118;
    *(undefined4 *)(*(longlong *)param_1 + 8) = 0;
    lVar2 = 0;
  }
  return lVar2;
}



===== GetFirmwareInfo @ 1c0004200 =====

/* public: virtual long __cdecl SimulatedNvdimm::GetFirmwareInfo(class wistd::unique_ptr<struct
   _SCM_PD_FIRMWARE_INFO,struct wistd::default_delete<struct _SCM_PD_FIRMWARE_INFO> > *
   __ptr64,unsigned char * __ptr64,unsigned long * __ptr64,unsigned long * __ptr64) __ptr64 */

long __thiscall
SimulatedNvdimm::GetFirmwareInfo
          (SimulatedNvdimm *this,
          unique_ptr<_SCM_PD_FIRMWARE_INFO,wistd::default_delete<_SCM_PD_FIRMWARE_INFO>_> *param_1,
          uchar *param_2,ulong *param_3,ulong *param_4)

{
  longlong lVar1;
  undefined4 *puVar2;
  long lVar3;
  undefined8 uVar4;
  
  uVar4 = ExAllocatePool2(0x40,0x3c,0x7766764e);
  lVar1 = *(longlong *)param_1;
  *(undefined8 *)param_1 = uVar4;
  if (lVar1 != 0) {
    ExFreePoolWithTag(lVar1,0);
  }
  puVar2 = *(undefined4 **)param_1;
  if (puVar2 == (undefined4 *)0x0) {
    lVar3 = -0x3fffff66;
  }
  else {
    *(byte *)((longlong)puVar2 + 0x15) = *(byte *)((longlong)puVar2 + 0x15) | 1;
    *puVar2 = 0x3c;
    puVar2[1] = 0x3c;
    *(undefined2 *)(puVar2 + 2) = 0xff00;
    *(undefined1 *)((longlong)puVar2 + 10) = 1;
    puVar2[4] = 0x30;
    puVar2[3] = 0x30;
    *(undefined1 *)(puVar2 + 5) = 0;
    RtlStringCchPrintfA((char *)(puVar2 + 7),0x20,"1.0");
    if (param_2 != (uchar *)0x0) {
      *param_2 = '\0';
    }
    if (param_3 != (ulong *)0x0) {
      *param_3 = 0;
    }
    if (param_4 != (ulong *)0x0) {
      *param_4 = 0;
    }
    lVar3 = 0;
  }
  return lVar3;
}



===== GetFirmwareInitializationStatus @ 1c00042d0 =====

/* public: virtual long __cdecl Nvdimm::GetFirmwareInitializationStatus(void) __ptr64 */

long __thiscall Nvdimm::GetFirmwareInitializationStatus(Nvdimm *this)

{
  return 0;
}



===== GetOperationalStatus @ 1c00042e0 =====

/* public: virtual long __cdecl VNvdimm::GetOperationalStatus(unsigned long,bool * __ptr64
   const,unsigned long,bool * __ptr64 const) __ptr64 */

long __thiscall
VNvdimm::GetOperationalStatus(VNvdimm *this,ulong param_1,bool *param_2,ulong param_3,bool *param_4)

{
  long lVar1;
  VNvdimm *pVVar2;
  
  if ((param_1 < 8) || (param_3 < 0x17)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    memset(param_2,0,(ulonglong)param_1);
    memset(param_4,0,(ulonglong)param_3);
    KeWaitForSingleObject(this + 0x38,0,0,0,0);
    pVVar2 = this + 0x24;
    if (((byte)*pVVar2 & 1) != 0) {
      param_4[0xc] = true;
      param_2[4] = true;
    }
    if (((byte)*pVVar2 & 2) != 0) {
      param_4[0xf] = true;
      param_2[4] = true;
    }
    if (((byte)*pVVar2 & 4) != 0) {
      param_4[0x10] = true;
      param_2[4] = true;
    }
    pVVar2 = this + 0x24;
    if (((byte)*pVVar2 & 8) != 0) {
      param_4[0x11] = true;
      param_2[2] = true;
    }
    if (((byte)*pVVar2 & 0x10) != 0) {
      param_4[0x12] = true;
      param_2[2] = true;
    }
    if (((byte)*pVVar2 & 0x20) != 0) {
      param_4[8] = true;
      param_2[2] = true;
    }
    if (*(char *)(*(longlong *)(this + 0x10) + 0xe2) != '\0') {
      param_4[0xc] = true;
      param_2[6] = true;
    }
    KeReleaseMutex(this + 0x38,0);
    if ((*(uint *)(*(longlong *)(this + 0x10) + 0xe8) & 0x10) != 0) {
      param_4[3] = true;
      param_2[6] = true;
    }
    lVar1 = 0;
  }
  return lVar1;
}



===== GetSecurityState @ 1c0004420 =====

/* public: virtual enum _SCM_PD_SECURITY_STATE __cdecl Nvdimm::GetSecurityState(void) __ptr64 */

_SCM_PD_SECURITY_STATE __thiscall Nvdimm::GetSecurityState(Nvdimm *this)

{
  return 1;
}



===== GetUnsafeShutdownCount @ 1c0004430 =====

/* public: virtual long __cdecl VNvdimm::GetUnsafeShutdownCount(unsigned long * __ptr64) __ptr64 */

long __thiscall VNvdimm::GetUnsafeShutdownCount(VNvdimm *this,ulong *param_1)

{
  *param_1 = *(ulong *)(this + 0x70);
  return 0;
}



===== HandleDataLossFailures @ 1c0004440 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: long __cdecl VNvdimm::HandleDataLossFailures(void) __ptr64 */

long __thiscall VNvdimm::HandleDataLossFailures(VNvdimm *this)

{
  longlong lVar1;
  undefined1 auStackY_88 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  if (*(uint *)(this + 0x74) < *(uint *)(this + 0x70)) {
    *(uint *)(*(longlong *)(this + 0x10) + 0xe8) =
         *(uint *)(*(longlong *)(this + 0x10) + 0xe8) | 0x10;
    local_28 = 0;
    uStack_20 = 0;
    if ((Microsoft_Windows_PersistentMemory_NvdimmEnableBits & 4) != 0) {
      lVar1 = *(longlong *)(this + 0x10);
      McTemplateK0jdssszqq_EtwWriteTransfer
                (lVar1,&EventLostData,&local_28,lVar1 + 400,(char)*(undefined4 *)(lVar1 + 0x20),
                 *(char **)(lVar1 + 0x178),*(char **)(lVar1 + 0x180),*(char **)(lVar1 + 0x188),
                 *(wchar_t **)(lVar1 + 0x140),(char)*(undefined4 *)(this + 0x70),
                 (char)*(undefined4 *)(this + 0x74));
    }
    VNvdimmTelemetry::LogDataLoss
              (*(VNvdimmTelemetry **)(this + 0x18),*(ulong *)(this + 0x74),*(ulong *)(this + 0x70),
               *(uint *)(*(longlong *)(this + 0x10) + 0xe8) >> 4 & 1);
  }
  else if (*(uint *)(this + 0x70) < *(uint *)(this + 0x74)) {
    WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10),3,
                    "VNvdimm::HandleDataLossFailures: current USC is less than baseline; updating baseline (current: %d; baseline: %d)"
                   );
    UpdateBaselineUnsafeShutdownCount(this,*(ulong *)(this + 0x70));
  }
  return 0;
}



===== HandleDeviceHealthErrors @ 1c0004550 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl VNvdimm::HandleDeviceHealthErrors(void) __ptr64 */

void __thiscall VNvdimm::HandleDeviceHealthErrors(VNvdimm *this)

{
  VNvdimm *pVVar1;
  uint uVar2;
  longlong lVar3;
  bool bVar4;
  _WHEA_ERROR_SEVERITY _Var5;
  longlong lVar6;
  _NVDIMM_DEVICE_EXTENSION *p_Var7;
  undefined1 auStackY_a8 [32];
  undefined1 uVar8;
  uint local_48 [2];
  undefined8 local_40;
  undefined8 uStack_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_a8;
  _Var5 = 0;
  local_40 = 0;
  uStack_38 = 0;
  KeWaitForSingleObject(this + 0x38,0,0);
  if (*(int *)(this + 0x30) < 0) {
    if ((Microsoft_Windows_PersistentMemory_NvdimmEnableBits & 1) != 0) {
      lVar6 = *(longlong *)(this + 0x10);
      McTemplateK0jdqssszq_EtwWriteTransfer
                (lVar6,&EventHealthCheckFailed,&local_40,lVar6 + 400,
                 (char)*(undefined4 *)(lVar6 + 0x20),(char)*(undefined4 *)(lVar6 + 0x134),
                 *(char **)(lVar6 + 0x178),*(char **)(lVar6 + 0x180),*(char **)(lVar6 + 0x188),
                 *(wchar_t **)(lVar6 + 0x140),(char)*(int *)(this + 0x30));
    }
    goto LAB_1c0004a85;
  }
  uVar2 = *(uint *)(this + 0x24);
  pVVar1 = this + 0x2c;
  bVar4 = false;
  uVar8 = (undefined1)(uVar2 & 1);
  if ((uVar2 & 1) == 0) {
    if (((byte)*pVVar1 & 1) != 0) goto LAB_1c00046ca;
  }
  else if (((byte)*pVVar1 & 1) == 0) {
    if ((Microsoft_Windows_PersistentMemory_NvdimmEnableBits & 1) != 0) {
      lVar3 = *(longlong *)(this + 0x10);
      lVar6 = lVar3 + 400;
      McTemplateK0jdttttttt_EtwWriteTransfer
                ((ulonglong)(uVar2 >> 3 & 1),&Event_VirtualNvdimm_LostDataPersistenceGuarantee,
                 &local_40,lVar6,(char)*(undefined4 *)(lVar3 + 0x20),uVar8,(byte)(uVar2 >> 1) & 1,
                 (byte)(uVar2 >> 2) & 1,(byte)(uVar2 >> 3) & 1,(byte)(uVar2 >> 4) & 1,
                 (byte)(uVar2 >> 5) & 1,*(undefined1 *)(lVar3 + 0xe2));
      _Var5 = (_WHEA_ERROR_SEVERITY)lVar6;
    }
    bVar4 = true;
  }
  else {
LAB_1c00046ca:
    if ((Microsoft_Windows_PersistentMemory_NvdimmEnableBits & 2) != 0) {
      lVar3 = *(longlong *)(this + 0x10);
      lVar6 = lVar3 + 400;
      McTemplateK0jdttttttt_EtwWriteTransfer
                ((ulonglong)(uVar2 >> 3 & 1),&Event_VirtualNvdimm_RegainedDataPersistenceGuarantee,
                 &local_40,lVar6,(char)*(undefined4 *)(lVar3 + 0x20),uVar8,(byte)(uVar2 >> 1) & 1,
                 (byte)(uVar2 >> 2) & 1,(byte)(uVar2 >> 3) & 1,(byte)(uVar2 >> 4) & 1,
                 (byte)(uVar2 >> 5) & 1,*(undefined1 *)(lVar3 + 0xe2));
      _Var5 = (_WHEA_ERROR_SEVERITY)lVar6;
    }
  }
  uVar2 = *(uint *)(this + 0x24);
  if ((uVar2 & 2) == 0) {
    if (((byte)*pVVar1 & 2) != 0) goto LAB_1c00047ec;
  }
  else if (((byte)*pVVar1 & 2) == 0) {
    if ((Microsoft_Windows_PersistentMemory_NvdimmEnableBits & 1) != 0) {
      lVar3 = *(longlong *)(this + 0x10);
      lVar6 = lVar3 + 400;
      McTemplateK0jdttttttt_EtwWriteTransfer
                ((ulonglong)(uVar2 >> 2 & 1),&Event_VirtualNvdimm_LostWritePersistenceGuarantee,
                 &local_40,lVar6,(char)*(undefined4 *)(lVar3 + 0x20),(byte)uVar2 & 1,
                 (byte)(uVar2 >> 1) & 1,(byte)(uVar2 >> 2) & 1,(byte)(uVar2 >> 3) & 1,
                 (byte)(uVar2 >> 4) & 1,(byte)(uVar2 >> 5) & 1,*(undefined1 *)(lVar3 + 0xe2));
      _Var5 = (_WHEA_ERROR_SEVERITY)lVar6;
    }
    bVar4 = true;
  }
  else {
LAB_1c00047ec:
    if ((Microsoft_Windows_PersistentMemory_NvdimmEnableBits & 2) != 0) {
      lVar3 = *(longlong *)(this + 0x10);
      lVar6 = lVar3 + 400;
      McTemplateK0jdttttttt_EtwWriteTransfer
                ((ulonglong)(uVar2 >> 2 & 1),&Event_VirtualNvdimm_RegainedWritePersistenceGuarantee,
                 &local_40,lVar6,(char)*(undefined4 *)(lVar3 + 0x20),(byte)uVar2 & 1,
                 (byte)(uVar2 >> 1) & 1,(byte)(uVar2 >> 2) & 1,(byte)(uVar2 >> 3) & 1,
                 (byte)(uVar2 >> 4) & 1,(byte)(uVar2 >> 5) & 1,*(undefined1 *)(lVar3 + 0xe2));
      _Var5 = (_WHEA_ERROR_SEVERITY)lVar6;
    }
  }
  uVar2 = *(uint *)(this + 0x24);
  if (((uVar2 & 4) == 0) || (((byte)*pVVar1 & 4) != 0)) {
    if ((((byte)this[0x2c] & 4) != 0) &&
       ((Microsoft_Windows_PersistentMemory_NvdimmEnableBits & 2) != 0)) {
      lVar3 = *(longlong *)(this + 0x10);
      lVar6 = lVar3 + 400;
      McTemplateK0jdttttttt_EtwWriteTransfer
                ((ulonglong)(uVar2 >> 2 & 1),&Event_VirtualNvdimm_FatalErrorRecovered,&local_40,
                 lVar6,(char)*(undefined4 *)(lVar3 + 0x20),(byte)uVar2 & 1,(byte)(uVar2 >> 1) & 1,
                 (byte)(uVar2 >> 2) & 1,(byte)(uVar2 >> 3) & 1,(byte)(uVar2 >> 4) & 1,
                 (byte)(uVar2 >> 5) & 1,*(undefined1 *)(lVar3 + 0xe2));
      _Var5 = (_WHEA_ERROR_SEVERITY)lVar6;
    }
  }
  else {
    if ((Microsoft_Windows_PersistentMemory_NvdimmEnableBits & 1) != 0) {
      lVar3 = *(longlong *)(this + 0x10);
      lVar6 = lVar3 + 400;
      McTemplateK0jdttttttt_EtwWriteTransfer
                ((ulonglong)(uVar2 >> 2 & 1),&Event_VirtualNvdimm_FatalError,&local_40,lVar6,
                 (char)*(undefined4 *)(lVar3 + 0x20),(byte)uVar2 & 1,(byte)(uVar2 >> 1) & 1,
                 (byte)(uVar2 >> 2) & 1,(byte)(uVar2 >> 3) & 1,(byte)(uVar2 >> 4) & 1,
                 (byte)(uVar2 >> 5) & 1,*(undefined1 *)(lVar3 + 0xe2));
      _Var5 = (_WHEA_ERROR_SEVERITY)lVar6;
    }
    bVar4 = true;
  }
  uVar2 = *(uint *)(this + 0x24);
  if (((((uVar2 & 8) == 0) || (((byte)this[0x2c] & 8) != 0)) &&
      (((uVar2 & 0x10) == 0 || (((byte)this[0x2c] & 0x10) != 0)))) &&
     (((uVar2 & 0x20) == 0 || (((byte)this[0x2c] & 0x20) != 0)))) {
    if (bVar4) goto LAB_1c0004a53;
  }
  else {
    if ((Microsoft_Windows_PersistentMemory_NvdimmEnableBits & 8) != 0) {
      lVar3 = *(longlong *)(this + 0x10);
      lVar6 = lVar3 + 400;
      McTemplateK0jdttttttt_EtwWriteTransfer
                ((ulonglong)(uVar2 >> 2 & 1),&Event_VirtualNvdimm_HealthWarning,&local_40,lVar6,
                 (char)*(undefined4 *)(lVar3 + 0x20),(byte)uVar2 & 1,(byte)(uVar2 >> 1) & 1,
                 (byte)(uVar2 >> 2) & 1,(byte)(uVar2 >> 3) & 1,(byte)(uVar2 >> 4) & 1,
                 (byte)(uVar2 >> 5) & 1,*(undefined1 *)(lVar3 + 0xe2));
      _Var5 = (_WHEA_ERROR_SEVERITY)lVar6;
    }
LAB_1c0004a53:
    p_Var7 = *(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10);
    local_48[0] = 0;
    `anonymous_namespace'::PrepareWheaErrorData((longlong)p_Var7,(longlong)(this + 0x20),local_48);
    NvdimmWheaReportError(p_Var7,local_48,4,_Var5);
  }
  *(undefined8 *)(this + 0x28) = *(undefined8 *)(this + 0x20);
LAB_1c0004a85:
  KeReleaseMutex(this + 0x38,0);
  return;
}



===== IsInitialized @ 1c0004ad0 =====

/* public: virtual long __cdecl SimulatedNvdimm::IsInitialized(void) __ptr64 */

long __thiscall SimulatedNvdimm::IsInitialized(SimulatedNvdimm *this)

{
  return *(long *)(this + 8);
}



===== RefreshHealthStatus @ 1c0004ae0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: virtual long __cdecl VNvdimm::RefreshHealthStatus(enum
   _NVDIMM_DEVICE_HEALTH_CHECK_REASON) __ptr64 */

long __thiscall
VNvdimm::RefreshHealthStatus(VNvdimm *this,_NVDIMM_DEVICE_HEALTH_CHECK_REASON param_1)

{
  _VDSM_HEALTH_INFO *p_Var1;
  uint uVar2;
  longlong lVar3;
  short sVar4;
  uint uVar5;
  uint uVar6;
  undefined1 auStackY_b8 [32];
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_b8;
  KeWaitForSingleObject(this + 0x38,0,0,0);
  p_Var1 = (_VDSM_HEALTH_INFO *)(this + 0x20);
  uVar5 = (**(code **)(*(longlong *)(this + 0x10) + 0x78))
                    (*(undefined8 *)(*(longlong *)(this + 0x10) + 0x58),&DAT_1c00150b0,1,1);
  if ((int)uVar5 < 0) {
    WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10),2,
                    "VNvdimm::RefreshHealthStatus(): VDsmGetHealthInformation() failed with NTSTATUS 0x%x"
                    ,(ulonglong)uVar5);
  }
  else {
    if (*(int *)p_Var1 != 0) {
      WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10),2,
                      "VNvdimm::RefreshHealthStatus(): VDsmGetHealthInformation() call failed with _DSM status 0x%x"
                     );
      if (*(int *)p_Var1 != 0) {
        sVar4 = (short)*(int *)p_Var1;
        if (sVar4 == 1) {
          uVar5 = 0xc00000bb;
        }
        else {
          uVar5 = 0xc0000001;
          if (sVar4 == 2) {
            uVar5 = 0xc000000d;
          }
        }
        goto LAB_1c0004c49;
      }
      uVar5 = 0;
    }
    local_58 = 0;
    uStack_50 = 0;
    if ((Microsoft_Windows_PersistentMemory_NvdimmEnableBits & 2) != 0) {
      uVar2 = *(uint *)(this + 0x24);
      lVar3 = *(longlong *)(this + 0x10);
      uVar6 = uVar2 >> 2 & 1;
      McTemplateK0jdttttttt_EtwWriteTransfer
                ((ulonglong)uVar6,&Event_VirtualNvdimm_ReceivedNvdimmNotification,&local_58,
                 lVar3 + 400,(char)*(undefined4 *)(lVar3 + 0x20),(byte)uVar2 & 1,
                 (byte)(uVar2 >> 1) & 1,(char)uVar6,(byte)(uVar2 >> 3) & 1,(byte)(uVar2 >> 4) & 1,
                 (byte)(uVar2 >> 5) & 1,*(undefined1 *)(lVar3 + 0xe2));
    }
    HandleDeviceHealthErrors(this);
  }
LAB_1c0004c49:
  *(uint *)(this + 0x30) = uVar5;
  VNvdimmTelemetry::LogDeviceHealth(*(VNvdimmTelemetry **)(this + 0x18),uVar5,param_1,p_Var1);
  KeReleaseMutex(this + 0x38,0);
  return uVar5;
}



===== RtlStringCchPrintfA @ 1c0004cc0 =====

/* long __cdecl RtlStringCchPrintfA(char * __ptr64,unsigned __int64,char const * __ptr64,...) */

long __cdecl RtlStringCchPrintfA(char *param_1,__uint64 param_2,char *param_3,...)

{
  ulonglong _Count;
  int iVar1;
  long lVar2;
  undefined8 in_R9;
  undefined8 local_res20;
  
  if (param_2 - 1 < 0x7fffffff) {
    _Count = param_2 - 1;
    lVar2 = 0;
    local_res20 = in_R9;
    iVar1 = _vsnprintf(param_1,_Count,param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (_Count < (ulonglong)(longlong)iVar1)) {
      param_1[_Count] = '\0';
      lVar2 = -0x7ffffffb;
    }
    else if ((longlong)iVar1 == _Count) {
      param_1[_Count] = '\0';
    }
  }
  else {
    lVar2 = -0x3ffffff3;
    if (param_2 != 0) {
      *param_1 = '\0';
    }
  }
  return lVar2;
}



===== RtlStringCbPrintfW @ 1c0004d34 =====

/* long __cdecl RtlStringCbPrintfW(unsigned short * __ptr64,unsigned __int64,unsigned short const *
   __ptr64,...) */

long __cdecl RtlStringCbPrintfW(ushort *param_1,__uint64 param_2,ushort *param_3,...)

{
  int iVar1;
  ulonglong uVar2;
  long lVar3;
  undefined8 in_R9;
  undefined8 local_res20;
  
  uVar2 = param_2 >> 1;
  if (uVar2 - 1 < 0x7fffffff) {
    uVar2 = uVar2 - 1;
    lVar3 = 0;
    local_res20 = in_R9;
    iVar1 = _vsnwprintf((wchar_t *)param_1,uVar2,(wchar_t *)param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (uVar2 < (ulonglong)(longlong)iVar1)) {
      lVar3 = -0x7ffffffb;
    }
    else if ((longlong)iVar1 != uVar2) {
      return 0;
    }
    param_1[uVar2] = 0;
  }
  else {
    lVar3 = -0x3ffffff3;
    if (uVar2 != 0) {
      *param_1 = 0;
    }
  }
  return lVar3;
}



===== UpdateBaselineUnsafeShutdownCount @ 1c0004db0 =====

/* private: long __cdecl VNvdimm::UpdateBaselineUnsafeShutdownCount(unsigned long) __ptr64 */

long __thiscall VNvdimm::UpdateBaselineUnsafeShutdownCount(VNvdimm *this,ulong param_1)

{
  uint uVar1;
  
  uVar1 = NvdWriteDeviceRegistryUlong
                    (*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10),
                     (ushort *)L"BaselineUnsafeShutdownCount",param_1);
  if ((int)uVar1 < 0) {
    WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10),2,
                    "VNvdimm::UpdateBaselineUnsafeShutdownCount: failed to write new baseline with status 0x%x"
                    ,(ulonglong)uVar1);
  }
  return uVar1;
}



===== McTemplateK0jdqssszq_EtwWriteTransfer @ 1c0004e04 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0jdqssszq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,char *param_7,char *param_8,char *param_9,
               wchar_t *param_10,undefined1 param_11)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 auStackY_e8 [32];
  undefined8 local_b8 [2];
  undefined8 local_a8;
  undefined8 local_a0;
  undefined1 *local_98;
  undefined8 local_90;
  undefined1 *local_88;
  undefined8 local_80;
  char *local_78;
  int local_70;
  undefined4 local_6c;
  char *local_68;
  int local_60;
  undefined4 local_5c;
  char *local_58;
  int local_50;
  undefined4 local_4c;
  wchar_t *local_48;
  int local_40;
  undefined4 local_3c;
  undefined1 *local_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_98 = &param_5;
  lVar2 = -1;
  local_88 = &param_6;
  local_a0 = 0x10;
  local_90 = 4;
  local_80 = 4;
  if (param_7 == (char *)0x0) {
    local_70 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_7[lVar1] != '\0');
    local_70 = (int)lVar1 + 1;
  }
  local_6c = 0;
  local_78 = param_7;
  if (param_7 == (char *)0x0) {
    local_78 = "NULL";
  }
  if (param_8 == (char *)0x0) {
    local_60 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_8[lVar1] != '\0');
    local_60 = (int)lVar1 + 1;
  }
  local_5c = 0;
  local_68 = param_8;
  if (param_8 == (char *)0x0) {
    local_68 = "NULL";
  }
  if (param_9 == (char *)0x0) {
    local_50 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_9[lVar1] != '\0');
    local_50 = (int)lVar1 + 1;
  }
  local_4c = 0;
  local_58 = param_9;
  if (param_9 == (char *)0x0) {
    local_58 = "NULL";
  }
  if (param_10 == (wchar_t *)0x0) {
    local_40 = 10;
  }
  else {
    do {
      lVar2 = lVar2 + 1;
    } while (param_10[lVar2] != L'\0');
    local_40 = (int)lVar2 * 2 + 2;
  }
  local_3c = 0;
  local_48 = param_10;
  if (param_10 == (wchar_t *)0x0) {
    local_48 = L"NULL";
  }
  local_30 = 4;
  local_38 = &param_11;
  local_a8 = param_4;
  McGenEventWrite_EtwWriteTransfer(&nvdimmEventProvider_Context,param_2,param_3,9,local_b8);
  return;
}



===== McTemplateK0jdttttttt_EtwWriteTransfer @ 1c0004f8c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0jdttttttt_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11,undefined1 param_12)

{
  undefined1 auStackY_e8 [32];
  undefined8 local_b8 [2];
  undefined8 local_a8;
  undefined8 local_a0;
  undefined1 *local_98;
  undefined8 local_90;
  undefined1 *local_88;
  undefined8 local_80;
  undefined1 *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_98 = &param_5;
  local_88 = &param_6;
  local_a0 = 0x10;
  local_78 = &param_7;
  local_90 = 4;
  local_68 = &param_8;
  local_58 = &param_9;
  local_48 = &param_10;
  local_38 = &param_11;
  local_28 = &param_12;
  local_80 = 4;
  local_70 = 4;
  local_60 = 4;
  local_50 = 4;
  local_40 = 4;
  local_30 = 4;
  local_20 = 4;
  local_a8 = param_4;
  McGenEventWrite_EtwWriteTransfer(&nvdimmEventProvider_Context,param_2,param_3,10,local_b8);
  return;
}



===== INvdimm @ 1c0005070 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: __cdecl INvdimm::INvdimm(struct _NVDIMM_DEVICE_EXTENSION * __ptr64) __ptr64 */

INvdimm * __thiscall INvdimm::INvdimm(INvdimm *this,_NVDIMM_DEVICE_EXTENSION *param_1)

{
  int iVar1;
  long lVar2;
  uint uVar3;
  undefined **local_80;
  _NVDIMM_DEVICE_EXTENSION *local_78;
  INvdimm *pIStack_70;
  undefined ***local_18;
  
  *(undefined ***)this = &_vftable_;
  *(undefined8 *)(this + 0x10) = *(undefined8 *)(param_1 + 0x1b8);
  *(undefined4 *)(this + 0x90) = 0;
  *(undefined8 *)(this + 0x98) = 0;
  local_80 = &PTR__scalar_deleting_destructor__1c000f238;
  local_18 = &local_80;
  *(INvdimm **)(this + 0x88) = this + 0x20;
  local_78 = param_1;
  pIStack_70 = this;
  wistd::__function::
  __func<<lambda_19eb9d4442d94dae27ff02cd8a0db90c>,INvdimmFwUpdater_*___cdecl(void)>::__clone
            ((longlong)&local_80,(undefined8 *)(this + 0x20));
  if (local_18 != (undefined ***)0x0) {
    (*(code *)(*local_18)[3])();
  }
  *(undefined4 *)(this + 0x118) = 0;
  *(undefined8 *)(this + 0x120) = 0;
  local_80 = &PTR__scalar_deleting_destructor__1c000f300;
  local_18 = &local_80;
  *(INvdimm **)(this + 0x110) = this + 0xa8;
  local_78 = param_1;
  wistd::__function::
  __func<<lambda_bb9bbeef4085303a346b29e35479209a>,INvdimmCommandEffectLog_*___cdecl(void)>::__clone
            ((longlong)&local_80,(undefined8 *)(this + 0xa8));
  if (local_18 != (undefined ***)0x0) {
    (*(code *)(*local_18)[3])();
  }
  INvdimmSecurityManager::INvdimmSecurityManager
            ((INvdimmSecurityManager *)(this + 0x128),param_1,*(INvdimmTelemetry **)(this + 0x10));
  *(undefined4 *)(this + 0x1bc) = 0;
  *(_NVDIMM_DEVICE_EXTENSION **)(this + 0x1a8) = param_1;
  KeInitializeMutex(this + 0x1c0);
  *(_NVDIMM_DEVICE_EXTENSION **)(this + 0x208) = param_1;
  KeInitializeMutex(this + 0x330);
  this[800] = (INvdimm)0x0;
  lVar2 = RefreshHealthStatus(this,0);
  *(long *)(this + 8) = lVar2;
  if (-1 < lVar2) {
    if (((byte)this[0x21c] & 4) == 0) {
      uVar3 = `anonymous_namespace'::EnableAllAlarms(param_1);
      *(uint *)(this + 8) = uVar3;
      if (-1 < (int)uVar3) {
        uVar3 = `anonymous_namespace'::EnableLatchLss(param_1);
        *(uint *)(this + 8) = uVar3;
      }
      if (-1 < (int)uVar3) {
        iVar1 = *(int *)(this + 0x128);
        *(int *)(this + 8) = iVar1;
        if (((*(int *)(*(longlong *)(this + 0x208) + 500) != 0) || (-1 < iVar1)) &&
           (*(undefined4 *)(this + 8) = *(undefined4 *)(this + 0x1a0),
           *(int *)(*(longlong *)(this + 0x208) + 500) != 0)) {
          *(undefined4 *)(this + 8) = 0;
        }
      }
    }
    else {
      WriteTraceEvent(param_1,2,
                      "INvdimm(): NVDIMM is fatal - ignoring any errors in initializing INVDIMM subcomponents"
                     );
    }
  }
  if (*(int *)(this + 8) < 0) {
    WriteTraceEvent(param_1,1,"INvdimm: the constructor failed with initialization status 0x%x");
  }
  else {
    WriteTraceEvent(param_1,4,"The INVDIMM driver initialized successfully.");
  }
  return this;
}



===== ~Lazy<INvdimmCommandEffectLog> @ 1c0005288 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: __cdecl Lazy<class INvdimmCommandEffectLog>::~Lazy<class INvdimmCommandEffectLog>(void)
   __ptr64 */

void __thiscall
Lazy<INvdimmCommandEffectLog>::~Lazy<INvdimmCommandEffectLog>(Lazy<INvdimmCommandEffectLog> *this)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *(longlong *)(this + 0x80);
  *(undefined8 *)(this + 0x80) = 0;
  if (lVar1 != 0) {
    lVar2 = *(longlong *)(lVar1 + 0x10);
    *(undefined8 *)(lVar1 + 0x10) = 0;
    if (lVar2 != 0) {
      ExFreePoolWithTag(lVar2,0);
    }
    ExFreePoolWithTag(lVar1,0);
  }
  if (*(longlong **)(this + 0x70) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(this + 0x70) + 0x18))();
  }
  return;
}



===== ~INvdimm @ 1c0005300 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual __cdecl INvdimm::~INvdimm(void) __ptr64 */

void __thiscall INvdimm::~INvdimm(INvdimm *this)

{
  longlong lVar1;
  
  RtlFreeAnsiString(this + 0x148);
  Lazy<INvdimmCommandEffectLog>::~Lazy<INvdimmCommandEffectLog>
            ((Lazy<INvdimmCommandEffectLog> *)(this + 0xa0));
  lVar1 = *(longlong *)(this + 0x98);
  *(undefined8 *)(this + 0x98) = 0;
  if (lVar1 != 0) {
    ExFreePoolWithTag(lVar1,0);
  }
  if (*(longlong **)(this + 0x88) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(this + 0x88) + 0x18))();
  }
  *(undefined ***)this = &Nvdimm::_vftable_;
  return;
}



===== operator() @ 1c0005380 =====

long * wistd::__function::
       __func<<lambda_19eb9d4442d94dae27ff02cd8a0db90c>,INvdimmFwUpdater_*___cdecl(void)>::
       operator()(longlong param_1)

{
  _NVDIMM_DEVICE_EXTENSION *p_Var1;
  undefined8 uVar2;
  long lVar3;
  long *plVar4;
  
  plVar4 = (long *)ExAllocatePool2(0x40,0x90,0x6344564e);
  if (plVar4 == (long *)0x0) {
    plVar4 = (long *)0x0;
  }
  else {
    p_Var1 = *(_NVDIMM_DEVICE_EXTENSION **)(param_1 + 8);
    uVar2 = *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x10);
    plVar4[0x11] = 0;
    plVar4[0x12] = 0;
    *(undefined8 *)(plVar4 + 4) = uVar2;
    *(_NVDIMM_DEVICE_EXTENSION **)(plVar4 + 2) = p_Var1;
    lVar3 = INvdimmFwUpdater::GetFirmwareInfo(p_Var1,(_IDSM_FIRMWARE_INFO *)(plVar4 + 6));
    *plVar4 = lVar3;
    if (*(longlong *)(plVar4 + 0xf) != 0) {
      plVar4[0x11] = (-(uint)((*(byte *)(plVar4 + 0xb) & 2) != 0) & 2) + 3;
    }
    KeInitializeMutex(plVar4 + 0x16,0);
  }
  return plVar4;
}



===== operator() @ 1c0005420 =====

uint * wistd::__function::
       __func<<lambda_bb9bbeef4085303a346b29e35479209a>,INvdimmCommandEffectLog_*___cdecl(void)>::
       operator()(longlong param_1)

{
  uint *puVar1;
  _NVDIMM_DEVICE_EXTENSION *p_Var2;
  uint uVar3;
  uint *puVar4;
  
  puVar4 = (uint *)ExAllocatePool2(0x40,0x18,0x6344564e);
  if (puVar4 == (uint *)0x0) {
    puVar4 = (uint *)0x0;
  }
  else {
    p_Var2 = *(_NVDIMM_DEVICE_EXTENSION **)(param_1 + 8);
    puVar1 = puVar4 + 4;
    *puVar4 = 0;
    puVar1[0] = 0;
    puVar1[1] = 0;
    *(_NVDIMM_DEVICE_EXTENSION **)(puVar4 + 2) = p_Var2;
    uVar3 = `anonymous_namespace'::GetCommandEffectLog(p_Var2,(longlong *)puVar1);
    *puVar4 = uVar3;
  }
  return puVar4;
}



===== `scalar_deleting_destructor' @ 1c0005490 =====

/* public: virtual void * __ptr64 __cdecl wistd::__function::__base<class INvdimmFwUpdater * __ptr64
   __cdecl(void)>::`scalar deleting destructor'(unsigned int) __ptr64 */

void * __thiscall
wistd::__function::__base<class_INvdimmFwUpdater*___ptr64___cdecl(void)>::
_scalar_deleting_destructor_
          (__base<class_INvdimmFwUpdater*___ptr64___cdecl(void)> *this,uint param_1)

{
  *(undefined ***)this = &_vftable_;
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 1c00054d0 =====

undefined8 *
wistd::__function::
__func<<lambda_19eb9d4442d94dae27ff02cd8a0db90c>,INvdimmFwUpdater_*___cdecl(void)>::
_scalar_deleting_destructor_(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = &__base<class_INvdimmFwUpdater*___ptr64___cdecl(void)>::_vftable_;
  if ((param_2 & 1) != 0) {
    ExFreePoolWithTag(param_1,0);
  }
  return param_1;
}



===== `scalar_deleting_destructor' @ 1c0005510 =====

/* public: virtual void * __ptr64 __cdecl INvdimm::`scalar deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall INvdimm::_scalar_deleting_destructor_(INvdimm *this,uint param_1)

{
  ~INvdimm(this);
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0);
  }
  return this;
}



===== AcknowledgeUnsafeShutdown @ 1c0005550 =====

/* public: virtual long __cdecl INvdimm::AcknowledgeUnsafeShutdown(void) __ptr64 */

long __thiscall INvdimm::AcknowledgeUnsafeShutdown(INvdimm *this)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  char *pcVar4;
  
  uVar2 = UpdateBaselineUnsafeShutdownCount(this,*(ulong *)(this + 0x1f8));
  if ((int)uVar2 < 0) {
    pcVar4 = 
    "INvdimm::AcknowledgeUnsafeShutdown: error writing updated baseline USC to registry: 0x%x";
    uVar3 = 2;
    uVar1 = uVar2;
  }
  else {
    pcVar4 = "INvdimm::AcknowledgeUnsafeShutdown: baseline USC updated in the registry to %d";
    *(uint *)(this + 0x1fc) = *(uint *)(this + 0x1f8);
    uVar3 = 4;
    uVar1 = *(uint *)(this + 0x1f8);
  }
  WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x208),uVar3,pcVar4,(ulonglong)uVar1);
  return uVar2;
}



===== DownloadFirmwareRegions @ 1c00055c0 =====

/* public: virtual long __cdecl INvdimm::DownloadFirmwareRegions(unsigned char,void *
   __ptr64,unsigned long,unsigned __int64,bool) __ptr64 */

long __thiscall
INvdimm::DownloadFirmwareRegions
          (INvdimm *this,uchar param_1,void *param_2,ulong param_3,__uint64 param_4,bool param_5)

{
  uint uVar1;
  INvdimmFwUpdater *this_00;
  
  if (param_1 == '\x01') {
    this_00 = Lazy<INvdimmFwUpdater>::Get((Lazy<INvdimmFwUpdater> *)(this + 0x18));
    if (this_00 == (INvdimmFwUpdater *)0x0) {
      if (*(int *)(this + 0x90) == 0) {
        uVar1 = 0xc0000184;
      }
      else if (*(uint **)(this + 0x98) == (uint *)0x0) {
        uVar1 = 0xc0000017;
      }
      else {
        uVar1 = **(uint **)(this + 0x98);
      }
      WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x208),2,
                      "INvdimm::DownloadFirmwareRegions(): Failed to download firmware regions because the firmware updater initialization failed with NTSTATUS 0x%x"
                      ,(ulonglong)uVar1);
    }
    else {
      uVar1 = INvdimmFwUpdater::DownloadFirmwareRegions(this_00,param_2,param_3,param_4,param_5);
    }
  }
  else {
    uVar1 = 0xc000000d;
  }
  return uVar1;
}



===== EnableAllAlarms @ 1c0005668 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint `anonymous_namespace'::EnableAllAlarms(_NVDIMM_DEVICE_EXTENSION *param_1)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  undefined1 auStack_98 [32];
  undefined2 *local_78;
  uint local_70;
  uint *local_68;
  undefined2 local_60;
  uint local_48;
  undefined2 local_44;
  byte local_42;
  undefined2 local_41;
  ushort local_3f;
  short local_38;
  undefined2 uStack_36;
  byte bStack_34;
  undefined1 uStack_33;
  byte bStack_32;
  undefined1 uStack_31;
  undefined1 uStack_30;
  ushort uStack_2f;
  undefined1 uStack_2d;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_98;
  local_60 = 0xc;
  local_38 = 0;
  uStack_36 = 0;
  bStack_34 = 0;
  uStack_33 = 0;
  bStack_32 = 0;
  uStack_31 = 0;
  uStack_30 = 0;
  uStack_2f = 0;
  uStack_2d = 0;
  local_68 = (uint *)&local_38;
  local_70 = local_70 & 0xffff0000;
  local_78 = (undefined2 *)0x0;
  uVar1 = (**(code **)(param_1 + 0x78))(*(undefined8 *)(param_1 + 0x58),&DAT_1c00150d0,2,2);
  if ((int)uVar1 < 0) {
    pcVar3 = "INvdimm::EnableAllAlarms: Get Health Thresholds failed with NTSTATUS 0x%x";
LAB_1c00056e1:
    WriteTraceEvent(param_1,2,pcVar3,(ulonglong)uVar1);
  }
  else {
    if (local_38 != 0) {
      WriteTraceEvent(param_1,2,
                      "INvdimm::EnableAllAlarms: Get Health Thresholds failed with _DSM status 0x%x"
                      ,(ulonglong)CONCAT22(uStack_36,local_38));
      iVar2 = 2;
      uVar1 = CONCAT22(uStack_36,local_38);
LAB_1c0005713:
      uVar1 = FUNCTION_SPECIFIC_IDSM_STATUS_TO_NTSTATUS(uVar1,iVar2);
      return uVar1;
    }
    local_70 = (uint)bStack_32;
    local_78 = (undefined2 *)CONCAT44(local_78._4_4_,(uint)CONCAT11(uStack_30,uStack_31));
    WriteTraceEvent(param_1,4,
                    "INvdimm::EnableAllAlarms: Current thresholds: controller temperature = 0x%x (multiples); media temperature = 0x%x (multiples); percentage remaining = %d"
                    ,(ulonglong)uStack_2f);
    if ((((bStack_34 & 4) == 0) || ((bStack_34 & 2) == 0)) || ((bStack_34 & 1) == 0)) {
      local_68 = &local_48;
      local_3f = uStack_2f;
      local_41 = CONCAT11(uStack_30,uStack_31);
      local_60 = 4;
      local_78 = &local_44;
      local_70 = CONCAT22(local_70._2_2_,7);
      local_42 = bStack_32;
      local_44 = 7;
      local_48 = 0;
      uVar1 = (**(code **)(param_1 + 0x78))(*(undefined8 *)(param_1 + 0x58),&DAT_1c00150d0,2,0x11);
      if ((int)uVar1 < 0) {
        pcVar3 = "INvdimm::EnableAllAlarms: Set Health Thresholds failed with NTSTATUS 0x%x";
        goto LAB_1c00056e1;
      }
      if ((short)local_48 != 0) {
        WriteTraceEvent(param_1,2,
                        "INvdimm::EnableAllAlarms: Set Health Thresholds failed with _DSM status 0x%x"
                       );
        iVar2 = 0x11;
        uVar1 = local_48;
        goto LAB_1c0005713;
      }
    }
    else {
      WriteTraceEvent(param_1,4,"INvdimm::EnableAllAlarms: All alarms were already set.");
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== EnableLatchLss @ 1c0005830 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint `anonymous_namespace'::EnableLatchLss(_NVDIMM_DEVICE_EXTENSION *param_1)

{
  uint uVar1;
  undefined1 local_res8 [8];
  uint local_res10 [2];
  
  local_res8[0] = 1;
  local_res10[0] = 0;
  uVar1 = (**(code **)(param_1 + 0x78))
                    (*(undefined8 *)(param_1 + 0x58),&DAT_1c00150d0,2,10,local_res8,1,local_res10,4)
  ;
  if ((int)uVar1 < 0) {
    WriteTraceEvent(param_1,2,"INvdimm::EnableLatchLss: _DSM failed with NTSTATUS 0x%x",
                    (ulonglong)uVar1);
  }
  else if ((short)local_res10[0] == 0) {
    uVar1 = 0;
  }
  else {
    WriteTraceEvent(param_1,2,"INvdimm::EnableLatchLss: _DSM failed with _DSM status 0x%x");
    uVar1 = FUNCTION_SPECIFIC_IDSM_STATUS_TO_NTSTATUS(local_res10[0],10);
  }
  return uVar1;
}



===== Get @ 1c00058f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: class INvdimmFwUpdater * __ptr64 __cdecl Lazy<class INvdimmFwUpdater>::Get(void) __ptr64
    */

INvdimmFwUpdater * __thiscall Lazy<INvdimmFwUpdater>::Get(Lazy<INvdimmFwUpdater> *this)

{
  longlong lVar1;
  code *pcVar2;
  undefined8 uVar3;
  INvdimmFwUpdater *pIVar4;
  bool bVar5;
  
  LOCK();
  bVar5 = *(int *)(this + 0x78) == 0;
  if (bVar5) {
    *(int *)(this + 0x78) = 1;
  }
  UNLOCK();
  if (bVar5) {
    if (*(longlong **)(this + 0x70) == (longlong *)0x0) {
      wistd::__throw_bad_function_call();
      pcVar2 = (code *)swi(3);
      pIVar4 = (INvdimmFwUpdater *)(*pcVar2)();
      return pIVar4;
    }
    uVar3 = (**(code **)(**(longlong **)(this + 0x70) + 0x20))();
    lVar1 = *(longlong *)(this + 0x80);
    *(undefined8 *)(this + 0x80) = uVar3;
    if (lVar1 != 0) {
      ExFreePoolWithTag(lVar1,0);
    }
  }
  pIVar4 = *(INvdimmFwUpdater **)(this + 0x80);
  if ((pIVar4 != (INvdimmFwUpdater *)0x0) && (*(int *)pIVar4 < 0)) {
    pIVar4 = (INvdimmFwUpdater *)0x0;
  }
  return pIVar4;
}



===== GetCurrentFirmwareRevision @ 1c0005970 =====

/* public: virtual long __cdecl INvdimm::GetCurrentFirmwareRevision(char * __ptr64 const) __ptr64 */

long __thiscall INvdimm::GetCurrentFirmwareRevision(INvdimm *this,char *param_1)

{
  uint uVar1;
  INvdimmFwUpdater *pIVar2;
  
  pIVar2 = Lazy<INvdimmFwUpdater>::Get((Lazy<INvdimmFwUpdater> *)(this + 0x18));
  if (pIVar2 == (INvdimmFwUpdater *)0x0) {
    if (*(int *)(this + 0x90) == 0) {
      uVar1 = 0xc0000184;
    }
    else if (*(uint **)(this + 0x98) == (uint *)0x0) {
      uVar1 = 0xc0000017;
    }
    else {
      uVar1 = **(uint **)(this + 0x98);
    }
    WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x208),2,
                    "INvdimm::GetCurrentFirmwareRevision(): Failed to get cached firmware revision because the firmware updater initialization failed with NTSTATUS 0x%x"
                    ,(ulonglong)uVar1);
  }
  else {
    uVar1 = RtlStringCchPrintfA(param_1,0x20,"%I64x",*(undefined8 *)(pIVar2 + 0x34));
  }
  return uVar1;
}



===== GetDeviceName @ 1c0005a10 =====

/* public: virtual long __cdecl INvdimm::GetDeviceName(unsigned short * __ptr64,unsigned long)
   __ptr64 */

long __thiscall INvdimm::GetDeviceName(INvdimm *this,ushort *param_1,ulong param_2)

{
  long lVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  
  if (*(short *)(*(longlong *)(this + 0x208) + 0x148) == 0) {
    pwVar2 = L"";
    pwVar3 = L"";
  }
  else {
    pwVar3 = *(wchar_t **)(*(longlong *)(this + 0x208) + 0x150);
    pwVar2 = L" ";
  }
  lVar1 = RtlStringCbPrintfW(param_1,param_2,(ushort *)L"%ws%wsINVDIMM device",pwVar3,pwVar2);
  return lVar1;
}



===== GetDeviceRuntimeFwActivationInfo @ 1c0005a70 =====

/* public: virtual long __cdecl INvdimm::GetDeviceRuntimeFwActivationInfo(struct
   _SCM_PD_RUNTIME_FW_ACTIVATION_INFO * __ptr64) __ptr64 */

long __thiscall
INvdimm::GetDeviceRuntimeFwActivationInfo(INvdimm *this,_SCM_PD_RUNTIME_FW_ACTIVATION_INFO *param_1)

{
  uint uVar1;
  INvdimmFwUpdater *this_00;
  char *pcVar2;
  undefined2 local_res8;
  uint local_resa;
  undefined2 local_rese;
  
  this_00 = Lazy<INvdimmFwUpdater>::Get((Lazy<INvdimmFwUpdater> *)(this + 0x18));
  if (this_00 == (INvdimmFwUpdater *)0x0) {
    if (*(int *)(this + 0x90) == 0) {
      uVar1 = 0xc0000184;
    }
    else if (*(uint **)(this + 0x98) == (uint *)0x0) {
      uVar1 = 0xc0000017;
    }
    else {
      uVar1 = **(uint **)(this + 0x98);
    }
    pcVar2 = 
    "INvdimm::GetDeviceRuntimeFWActivationStatus(): Firmware updater initialization failed with NTSTATUS 0x%x"
    ;
  }
  else {
    local_res8 = 0;
    local_resa = 0;
    local_rese = 0;
    uVar1 = INvdimmFwUpdater::GetDeviceRuntimeFirmwareActivationInfo
                      (this_00,(_IDSM_GET_DEVICE_RUNTIME_FW_ACTIVATION_INFO_OUTPUT *)&local_res8);
    if (-1 < (int)uVar1) {
      *(uint *)(param_1 + 8) = local_resa >> 0x10;
      *(uint *)(param_1 + 0xc) = (uint)(byte)local_rese;
      return uVar1;
    }
    pcVar2 = 
    "INvdimm::GetDeviceRuntimeFwActivationInfo(): Failed to get Runtime Fw Activation Info with NTSTATUS 0x%x"
    ;
  }
  WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x208),2,pcVar2,(ulonglong)uVar1);
  return uVar1;
}



===== GetDeviceSpecificInfo @ 1c0005b40 =====

/* public: virtual long __cdecl INvdimm::GetDeviceSpecificInfo(class wistd::unique_ptr<struct
   _SCM_PD_DEVICE_SPECIFIC_INFO,struct wistd::default_delete<struct _SCM_PD_DEVICE_SPECIFIC_INFO> >
   * __ptr64) __ptr64 */

long __thiscall
INvdimm::GetDeviceSpecificInfo
          (INvdimm *this,
          unique_ptr<_SCM_PD_DEVICE_SPECIFIC_INFO,wistd::default_delete<_SCM_PD_DEVICE_SPECIFIC_INFO>_>
          *param_1)

{
  INvdimm IVar1;
  short sVar2;
  uint uVar3;
  undefined4 *puVar4;
  long lVar5;
  undefined8 uVar6;
  short *psVar7;
  ulonglong uVar8;
  short *psVar9;
  longlong lVar10;
  longlong lVar11;
  longlong lVar12;
  int iVar13;
  
  uVar6 = ExAllocatePool2(0x100,0x748,0x7370764e);
  lVar10 = *(longlong *)param_1;
  *(undefined8 *)param_1 = uVar6;
  if (lVar10 != 0) {
    ExFreePoolWithTag(lVar10,0);
  }
  puVar4 = *(undefined4 **)param_1;
  if (puVar4 == (undefined4 *)0x0) {
    lVar5 = -0x3fffff66;
  }
  else {
    KeWaitForSingleObject(this + 0x330,0,0,0,0);
    uVar3 = *(uint *)(this + 0x224);
    psVar9 = (short *)(puVar4 + 4);
    lVar11 = 0x80;
    lVar12 = (longlong)L"Unsafe shutdown count" - (longlong)psVar9;
    lVar10 = 0x80;
    do {
      if ((lVar10 == -0x7fffff7e) || (sVar2 = *(short *)(lVar12 + (longlong)psVar9), sVar2 == 0))
      break;
      *psVar9 = sVar2;
      psVar9 = psVar9 + 1;
      lVar10 = lVar10 + -1;
    } while (lVar10 != 0);
    lVar12 = 0x80;
    psVar7 = psVar9 + -1;
    if (lVar10 != 0) {
      psVar7 = psVar9;
    }
    *psVar7 = 0;
    *(ulonglong *)(puVar4 + 0x44) = (ulonglong)uVar3;
    psVar9 = (short *)(puVar4 + 0x46);
    IVar1 = this[0x21d];
    lVar10 = (longlong)L"Percentage remaining" - (longlong)psVar9;
    do {
      if ((lVar12 == -0x7fffff7e) || (sVar2 = *(short *)(lVar10 + (longlong)psVar9), sVar2 == 0))
      break;
      *psVar9 = sVar2;
      psVar9 = psVar9 + 1;
      lVar12 = lVar12 + -1;
    } while (lVar12 != 0);
    lVar10 = 0x80;
    psVar7 = psVar9 + -1;
    if (lVar12 != 0) {
      psVar7 = psVar9;
    }
    *psVar7 = 0;
    *(ulonglong *)(puVar4 + 0x86) = (ulonglong)(byte)IVar1;
    psVar9 = (short *)(puVar4 + 0x88);
    IVar1 = this[0x21e];
    lVar12 = (longlong)L"Lifetime used %" - (longlong)psVar9;
    do {
      if ((lVar10 == -0x7fffff7e) || (sVar2 = *(short *)(lVar12 + (longlong)psVar9), sVar2 == 0))
      break;
      *psVar9 = sVar2;
      psVar9 = psVar9 + 1;
      lVar10 = lVar10 + -1;
    } while (lVar10 != 0);
    psVar7 = psVar9 + -1;
    if (lVar10 != 0) {
      psVar7 = psVar9;
    }
    *psVar7 = 0;
    *(ulonglong *)(puVar4 + 200) = (ulonglong)(byte)IVar1;
    psVar9 = (short *)(puVar4 + 0xca);
    uVar8 = (ulonglong)(*(ushort *)(this + 0x220) >> 4) & 0x7ff;
    if ((short)*(ushort *)(this + 0x220) < 0) {
      uVar8 = -uVar8;
    }
    lVar10 = 0x80;
    lVar12 = (longlong)L"Media temperature in C" - (longlong)psVar9;
    do {
      if ((lVar10 == -0x7fffff7e) || (sVar2 = *(short *)(lVar12 + (longlong)psVar9), sVar2 == 0))
      break;
      *psVar9 = sVar2;
      psVar9 = psVar9 + 1;
      lVar10 = lVar10 + -1;
    } while (lVar10 != 0);
    psVar7 = psVar9 + -1;
    if (lVar10 != 0) {
      psVar7 = psVar9;
    }
    *psVar7 = 0;
    *(ulonglong *)(puVar4 + 0x10a) = uVar8;
    psVar9 = (short *)(puVar4 + 0x10c);
    uVar8 = (ulonglong)(*(ushort *)(this + 0x222) >> 4) & 0x7ff;
    if ((short)*(ushort *)(this + 0x222) < 0) {
      uVar8 = -uVar8;
    }
    lVar10 = 0x80;
    lVar12 = (longlong)L"Controller temperature in C" - (longlong)psVar9;
    do {
      if ((lVar10 == -0x7fffff7e) || (sVar2 = *(short *)(lVar12 + (longlong)psVar9), sVar2 == 0))
      break;
      *psVar9 = sVar2;
      psVar9 = psVar9 + 1;
      lVar10 = lVar10 + -1;
    } while (lVar10 != 0);
    iVar13 = 6;
    psVar7 = psVar9 + -1;
    if (lVar10 != 0) {
      psVar7 = psVar9;
    }
    psVar9 = (short *)(puVar4 + 0x14e);
    *psVar7 = 0;
    *(ulonglong *)(puVar4 + 0x14c) = uVar8;
    KeWaitForSingleObject(this + 0x168,0,0,0,0);
    uVar3 = *(uint *)(this + 0x160);
    KeReleaseMutex(this + 0x168,0);
    lVar10 = 0x80;
    lVar12 = (longlong)L"Security state bitmask" - (longlong)psVar9;
    do {
      if ((lVar10 == -0x7fffff7e) || (sVar2 = *(short *)(lVar12 + (longlong)psVar9), sVar2 == 0))
      break;
      *psVar9 = sVar2;
      psVar9 = psVar9 + 1;
      lVar10 = lVar10 + -1;
    } while (lVar10 != 0);
    psVar7 = psVar9 + -1;
    if (lVar10 != 0) {
      psVar7 = psVar9;
    }
    *psVar7 = 0;
    *(ulonglong *)(puVar4 + 0x18e) = (ulonglong)uVar3;
    IVar1 = this[800];
    if (IVar1 != (INvdimm)0x0) {
      psVar9 = (short *)(puVar4 + 400);
      iVar13 = 7;
      lVar10 = (longlong)L"Is energy backed" - (longlong)psVar9;
      do {
        if ((lVar11 == -0x7fffff7e) || (sVar2 = *(short *)(lVar10 + (longlong)psVar9), sVar2 == 0))
        break;
        *psVar9 = sVar2;
        psVar9 = psVar9 + 1;
        lVar11 = lVar11 + -1;
      } while (lVar11 != 0);
      psVar7 = psVar9 + -1;
      if (lVar11 != 0) {
        psVar7 = psVar9;
      }
      *psVar7 = 0;
      *(ulonglong *)(puVar4 + 0x1d0) = (ulonglong)(byte)IVar1;
    }
    KeReleaseMutex(this + 0x330,0);
    *puVar4 = 0x118;
    puVar4[2] = iVar13;
    puVar4[1] = iVar13 * 0x108 + 0x10;
    lVar5 = 0;
  }
  return lVar5;
}



===== GetFirmwareInfo @ 1c0005ef0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: virtual long __cdecl INvdimm::GetFirmwareInfo(class wistd::unique_ptr<struct
   _SCM_PD_FIRMWARE_INFO,struct wistd::default_delete<struct _SCM_PD_FIRMWARE_INFO> > *
   __ptr64,unsigned char * __ptr64,unsigned long * __ptr64,unsigned long * __ptr64) __ptr64 */

long __thiscall
INvdimm::GetFirmwareInfo
          (INvdimm *this,
          unique_ptr<_SCM_PD_FIRMWARE_INFO,wistd::default_delete<_SCM_PD_FIRMWARE_INFO>_> *param_1,
          uchar *param_2,ulong *param_3,ulong *param_4)

{
  longlong lVar1;
  undefined4 *puVar2;
  undefined1 uVar3;
  uint uVar4;
  INvdimmFwUpdater *pIVar5;
  undefined8 uVar6;
  char *pcVar7;
  undefined1 auStack_98 [32];
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_98;
  pIVar5 = Lazy<INvdimmFwUpdater>::Get((Lazy<INvdimmFwUpdater> *)(this + 0x18));
  if (pIVar5 == (INvdimmFwUpdater *)0x0) {
    if (*(int *)(this + 0x90) == 0) {
      uVar4 = 0xc0000184;
    }
    else if (*(uint **)(this + 0x98) == (uint *)0x0) {
      uVar4 = 0xc0000017;
    }
    else {
      uVar4 = **(uint **)(this + 0x98);
    }
    pcVar7 = 
    "INvdimm::GetFirmwareInfo(): Failed to get firmware info because the firmware updater initialization failed with NTSTATUS 0x%x"
    ;
  }
  else {
    local_78 = 0;
    uStack_70 = 0;
    uStack_58 = 0;
    uStack_54 = 0;
    local_68 = 0;
    uStack_60 = 0;
    uStack_5c = 0;
    local_50 = 0;
    uVar4 = INvdimmFwUpdater::GetFirmwareInfo
                      (*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x208),(_IDSM_FIRMWARE_INFO *)&local_78
                      );
    if (-1 < (int)uVar4) {
      uVar6 = ExAllocatePool2(0x40,0x6c,0x7766764e);
      lVar1 = *(longlong *)param_1;
      *(undefined8 *)param_1 = uVar6;
      if (lVar1 != 0) {
        ExFreePoolWithTag(lVar1,0);
      }
      puVar2 = *(undefined4 **)param_1;
      if (puVar2 == (undefined4 *)0x0) {
        return -0x3fffff66;
      }
      *(byte *)((longlong)puVar2 + 0x15) = *(byte *)((longlong)puVar2 + 0x15) | 1;
      *(byte *)((longlong)puVar2 + 0x45) = *(byte *)((longlong)puVar2 + 0x45) & 0xfe;
      *puVar2 = 0x3c;
      puVar2[1] = 0x6c;
      *(undefined1 *)(puVar2 + 2) = 0;
      *(undefined1 *)((longlong)puVar2 + 10) = 2;
      if ((CONCAT44(local_50,uStack_54) == 0) ||
         (uVar3 = 1, (*(int *)(pIVar5 + 0x44) - 3U & 0xfffffffd) != 0)) {
        uVar3 = 0xff;
      }
      *(undefined1 *)((longlong)puVar2 + 9) = uVar3;
      *(undefined1 *)(puVar2 + 5) = 0;
      puVar2[4] = 0x30;
      puVar2[3] = 0x30;
      RtlStringCchPrintfA((char *)(puVar2 + 7),0x20,"%I64x",CONCAT44(uStack_58,uStack_5c));
      puVar2[0x10] = 0x30;
      puVar2[0xf] = 0x30;
      *(undefined1 *)(puVar2 + 0x11) = 1;
      RtlStringCchPrintfA((char *)(puVar2 + 0x13),0x20,"%I64x",CONCAT44(local_50,uStack_54));
      if (param_2 != (uchar *)0x0) {
        *param_2 = '\x01';
      }
      if (param_3 != (ulong *)0x0) {
        *param_3 = 0;
      }
      if (param_4 != (ulong *)0x0) {
        *param_4 = (ulong)uStack_70;
      }
      return 0;
    }
    pcVar7 = "INvdimm::GetFirmwareInfo(): Failed to get fw info with NTSTATUS 0x%x";
  }
  WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x208),2,pcVar7,(ulonglong)uVar4);
  return uVar4;
}



===== GetFirmwareInitializationStatus @ 1c00060c0 =====

/* public: virtual long __cdecl INvdimm::GetFirmwareInitializationStatus(void) __ptr64 */

long __thiscall INvdimm::GetFirmwareInitializationStatus(INvdimm *this)

{
  if (*(int *)(this + 0x90) == 0) {
    return -0x3ffffe7c;
  }
  if (*(long **)(this + 0x98) == (long *)0x0) {
    return -0x3fffffe9;
  }
  return **(long **)(this + 0x98);
}



===== GetOperationalStatus @ 1c00060f0 =====

/* public: virtual long __cdecl INvdimm::GetOperationalStatus(unsigned long,bool * __ptr64
   const,unsigned long,bool * __ptr64 const) __ptr64 */

long __thiscall
INvdimm::GetOperationalStatus(INvdimm *this,ulong param_1,bool *param_2,ulong param_3,bool *param_4)

{
  bool *pbVar1;
  INvdimm *pIVar2;
  INvdimm *pIVar3;
  long lVar4;
  byte bVar5;
  
  pIVar2 = this + 0x330;
  KeWaitForSingleObject(pIVar2,0,0,0,0);
  if ((param_1 < 8) || (param_3 < 0x17)) {
    KeReleaseMutex(pIVar2,0);
    lVar4 = -0x3ffffff3;
  }
  else {
    memset(param_2,0,(ulonglong)param_1);
    memset(param_4,0,(ulonglong)param_3);
    bVar5 = (byte)this[0x21f] & 7;
    if (((byte)this[0x21c] & 4) != 0) {
      param_4[0x10] = true;
      param_4[0xc] = true;
      param_2[4] = true;
    }
    pbVar1 = param_4 + 0x14;
    if (((byte)this[0x21f] & 1) != 0) {
      param_4[0x13] = true;
      *pbVar1 = true;
      param_4[0xe] = true;
    }
    if (((byte)this[0x21f] & 6) != 0) {
      param_4[0x15] = true;
      *pbVar1 = true;
      param_4[0x11] = true;
    }
    if ((((byte)this[0x21c] & 2) != 0) && (param_2[4] = true, bVar5 == 0)) {
      *pbVar1 = true;
    }
    if ((((byte)this[0x21c] & 1) != 0) && (param_2[2] = true, bVar5 == 0)) {
      param_4[0x14] = true;
    }
    if (*(int *)(this + 0x294) < 0) {
      param_4[0xb] = true;
      param_2[6] = true;
    }
    if ((bVar5 != 0) && (((byte)this[0x21c] & 7) == 0)) {
      param_2[2] = true;
    }
    if ((*(uint *)(*(longlong *)(this + 0x208) + 0xe8) & 0x10) != 0) {
      param_4[3] = true;
      param_2[6] = true;
    }
    if (this[800] != (INvdimm)0x0) {
      if (this[0x321] != (INvdimm)0x0) {
        param_4[0xc] = true;
        param_4[4] = true;
        param_2[6] = true;
      }
      if (*(int *)(this + 0x324) < 0) {
        param_4[0xb] = true;
        param_4[4] = true;
        param_2[6] = true;
      }
    }
    pIVar3 = this + 0x229;
    if (((byte)*pIVar3 & 9) != 0) {
      param_4[0x13] = true;
    }
    if (((byte)*pIVar3 & 0x10) != 0) {
      param_4[8] = true;
    }
    if ((*(ushort *)pIVar3 & 0x244) != 0) {
      param_4[4] = true;
    }
    if (((byte)*pIVar3 & 2) != 0) {
      param_4[8] = true;
    }
    if (((byte)this[0x229] & 0x20) != 0) {
      param_4[8] = true;
      param_4[0x14] = true;
    }
    if ((char)this[0x229] < '\0') {
      param_4[0x16] = true;
    }
    if ((*(ushort *)(this + 0x229) >> 8 & 1) != 0) {
      param_4[0x14] = true;
    }
    KeReleaseMutex(pIVar2,0);
    lVar4 = 0;
  }
  return lVar4;
}



===== GetSecurityState @ 1c0006340 =====

/* public: virtual enum _SCM_PD_SECURITY_STATE __cdecl INvdimm::GetSecurityState(void) __ptr64 */

_SCM_PD_SECURITY_STATE __thiscall INvdimm::GetSecurityState(INvdimm *this)

{
  _SCM_PD_SECURITY_STATE _Var1;
  
  _Var1 = INvdimmSecurityManager::GetSecurityStateAsEnum((INvdimmSecurityManager *)(this + 0x128));
  return _Var1;
}



===== GetUnsafeShutdownCount @ 1c0006360 =====

/* public: virtual long __cdecl INvdimm::GetUnsafeShutdownCount(unsigned long * __ptr64) __ptr64 */

long __thiscall INvdimm::GetUnsafeShutdownCount(INvdimm *this,ulong *param_1)

{
  *param_1 = *(ulong *)(this + 0x1f8);
  return 0;
}



===== GetUnsafeShutdownCountFromDsm @ 1c0006374 =====

/* private: long __cdecl INvdimm::GetUnsafeShutdownCountFromDsm(unsigned long * __ptr64,unsigned
   long * __ptr64) __ptr64 */

long __thiscall INvdimm::GetUnsafeShutdownCountFromDsm(INvdimm *this,ulong *param_1,ulong *param_2)

{
  long lVar1;
  uint uVar2;
  undefined8 in_stack_ffffffffffffffe8;
  undefined4 uVar3;
  
  uVar3 = (undefined4)((ulonglong)in_stack_ffffffffffffffe8 >> 0x20);
  lVar1 = NvdQueryDeviceRegistryUlong
                    (*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x208),(ushort *)L"",
                     (ushort *)L"ErrInj_UnsafeShutdownCount",param_1);
  if (lVar1 < 0) {
    uVar3 = 0;
    KeWaitForSingleObject(this + 0x330,0,0,0,0);
    *param_1 = *(ulong *)(this + 0x224);
    KeReleaseMutex(this + 0x330,0);
  }
  else {
    WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x208),2,
                    "INvdimm::GetUnsafeShutdownCountFromDsm: The USC error injection registry value exists and is set to %d"
                    ,(ulonglong)*param_1);
  }
  uVar2 = NvdQueryDeviceRegistryUlong
                    (*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x208),(ushort *)L"",
                     (ushort *)L"BaselineUnsafeShutdownCount",param_2);
  if (uVar2 == 0xc0000034) {
    WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x208),4,
                    "INvdimm::GetUnsafeShutdownCountFromDsm: the baseline USC isn\'t in the registry, so assuming the current value (%d) as the baseline"
                    ,(ulonglong)*param_1);
    uVar2 = UpdateBaselineUnsafeShutdownCount(this,*param_1);
    *param_2 = *param_1;
  }
  else if ((int)uVar2 < 0) {
    WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x208),2,
                    "INvdimm::GetUnsafeShutdownCountFromDsm: NvdQueryDeviceRegistryUlong() failed with NTSTATUS 0x%x"
                    ,(ulonglong)uVar2);
    goto LAB_1c00064a6;
  }
  if (-1 < (int)uVar2) {
    WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x208),4,
                    "INvdimm::GetUnsafeShutdownCountFromDsm: Current USC: %d; Baseline USC: %d",
                    (ulonglong)*param_1,CONCAT44(uVar3,*param_2));
    return uVar2;
  }
LAB_1c00064a6:
  WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x208),2,
                  "INvdimm::GetUnsafeShutdownCountFromDsm: failed with NTSTATUS 0x%x",
                  (ulonglong)uVar2);
  return uVar2;
}



===== HandleDataLossFailures @ 1c00064e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl INvdimm::HandleDataLossFailures(void) __ptr64 */

long __thiscall INvdimm::HandleDataLossFailures(INvdimm *this)

{
  _NVDIMM_DEVICE_EXTENSION *p_Var1;
  longlong lVar2;
  bool bVar3;
  uint uVar4;
  undefined1 auStackY_88 [32];
  ulong local_28 [2];
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_88;
  p_Var1 = *(_NVDIMM_DEVICE_EXTENSION **)(this + 0x208);
  if (*(uint *)(this + 0x1fc) < *(uint *)(this + 0x1f8)) {
    if ((*(longlong *)(p_Var1 + 0x30) == 0) && (*(longlong *)(p_Var1 + 0x38) != 0)) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
    }
    local_28[0] = 0;
    uVar4 = NvdGetLogicalDeviceCount(p_Var1,local_28);
    if ((int)uVar4 < 0) {
      WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x208),2,
                      "INvdimm::HandleDataLossFailures(): NvdGetLogicalDeviceCount() failed with NTSTATUS 0x%x"
                      ,(ulonglong)uVar4);
      local_28[0] = 1;
    }
    if ((bVar3) || (local_28[0] == 0)) {
      *(uint *)(*(longlong *)(this + 0x208) + 0xe8) =
           *(uint *)(*(longlong *)(this + 0x208) + 0xe8) & 0xffffffef;
      WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x208),4,
                      "INvdimm::HandleDataLossFailures(): Unsafe shutdown ignored because NVDIMM 0x%x is in memory mode or has no logical device created; updating baseline (new USC: %d; baseline: %d)"
                      ,(ulonglong)*(uint *)(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x208) + 0x20));
      (**(code **)(*(longlong *)this + 0x18))(this);
    }
    else {
      *(uint *)(*(longlong *)(this + 0x208) + 0xe8) =
           *(uint *)(*(longlong *)(this + 0x208) + 0xe8) | 0x10;
      if (this[0x200] == (INvdimm)0x0) {
        local_20 = 0;
        uStack_18 = 0;
        if ((Microsoft_Windows_PersistentMemory_NvdimmEnableBits & 4) != 0) {
          lVar2 = *(longlong *)(this + 0x208);
          McTemplateK0jdssszqq_EtwWriteTransfer
                    (lVar2,&EventLostData,&local_20,lVar2 + 400,(char)*(undefined4 *)(lVar2 + 0x20),
                     *(char **)(lVar2 + 0x178),*(char **)(lVar2 + 0x180),*(char **)(lVar2 + 0x188),
                     *(wchar_t **)(lVar2 + 0x140),(char)*(undefined4 *)(this + 0x1f8),
                     (char)*(undefined4 *)(this + 0x1fc));
        }
        INvdimmTelemetry::LogDataLoss
                  (*(INvdimmTelemetry **)(this + 0x10),*(ulong *)(this + 0x1fc),
                   *(ulong *)(this + 0x1f8),*(uint *)(*(longlong *)(this + 0x208) + 0xe8) >> 4 & 1);
        this[0x200] = (INvdimm)0x1;
      }
    }
  }
  else {
    *(uint *)(p_Var1 + 0xe8) = *(uint *)(p_Var1 + 0xe8) & 0xffffffef;
  }
  if (*(uint *)(this + 0x1f8) < *(uint *)(this + 0x1fc)) {
    WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x208),3,
                    "INvdimm::HandleDataLossFailures: current USC is less than baseline; updating baseline (current: %d; baseline: %d)"
                   );
    UpdateBaselineUnsafeShutdownCount(this,*(ulong *)(this + 0x1f8));
  }
  return 0;
}



===== HandleDeviceHealthErrors @ 1c0006700 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl INvdimm::HandleDeviceHealthErrors(void) __ptr64 */

void __thiscall INvdimm::HandleDeviceHealthErrors(INvdimm *this)

{
  INvdimm IVar1;
  longlong lVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  INvdimm IVar6;
  undefined1 *_Dst;
  INvdimm *pIVar7;
  INvdimm IVar8;
  undefined1 auStackY_1e8 [32];
  undefined1 uVar9;
  byte local_c8;
  undefined1 local_c7 [127];
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_1e8;
  local_48 = 0;
  uStack_40 = 0;
  KeWaitForSingleObject(this + 0x330,0,0,0);
  bVar5 = false;
  uVar9 = (undefined1)*(int *)(this + 0x294);
  if (*(int *)(this + 0x294) < 0) {
    if ((Microsoft_Windows_PersistentMemory_NvdimmEnableBits & 1) != 0) {
      lVar2 = *(longlong *)(this + 0x208);
      McTemplateK0jdqssszq_EtwWriteTransfer
                (lVar2,&EventHealthCheckFailed,&local_48,lVar2 + 400,
                 (char)*(undefined4 *)(lVar2 + 0x20),(char)*(undefined4 *)(lVar2 + 0x134),
                 *(char **)(lVar2 + 0x178),*(char **)(lVar2 + 0x180),*(char **)(lVar2 + 0x188),
                 *(wchar_t **)(lVar2 + 0x140),uVar9);
    }
    goto LAB_1c0007973;
  }
  IVar8 = this[0x21c];
  IVar6 = this[0x2a4];
  if ((((byte)IVar8 & 4) == 0) || (((byte)IVar6 & 4) != 0)) {
    if (((byte)IVar6 & 4) != 0) {
      WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x208),4,
                      "INvdimm::HandleDeviceHealthErrors: fatal status recovered");
      IVar6 = this[0x2a4];
    }
  }
  else {
    if ((Microsoft_Windows_PersistentMemory_NvdimmEnableBits & 1) != 0) {
      IVar6 = this[0x21f];
      lVar2 = *(longlong *)(this + 0x208);
      McTemplateK0jdqsssztttqqtttddqqqqtqqqbr24_EtwWriteTransfer
                (lVar2,&Event_INvdimm_FatalStatus,&local_48,lVar2 + 400,
                 (char)*(undefined4 *)(lVar2 + 0x20),(char)*(undefined4 *)(lVar2 + 0x134),
                 *(char **)(lVar2 + 0x178),*(char **)(lVar2 + 0x180),*(char **)(lVar2 + 0x188),
                 *(wchar_t **)(lVar2 + 0x140),(byte)IVar8 >> 2 & 1,(byte)IVar8 >> 1 & 1,
                 (byte)IVar8 & 1,this[0x21d],this[0x21e],(byte)IVar6 & 1,(byte)IVar6 >> 1 & 1,
                 (byte)IVar6 >> 2 & 1,(char)*(undefined2 *)(this + 0x220),
                 (char)*(undefined2 *)(this + 0x222),(char)*(undefined4 *)(this + 0x224),this[0x228]
                 ,this[0x233],uVar9,this[800],this[0x321],(char)*(undefined4 *)(this + 0x324),
                 *(undefined4 *)(this + 0x234),this + 0x238);
      IVar6 = this[0x2a4];
    }
    bVar5 = true;
  }
  IVar8 = this[0x21c];
  if (((byte)IVar8 & 2) == 0) {
    if (((byte)IVar6 & 2) != 0) goto LAB_1c0006bc0;
  }
  else if (((byte)this[0x2a4] & 2) == 0) {
    if ((Microsoft_Windows_PersistentMemory_NvdimmEnableBits & 4) != 0) {
      IVar6 = this[0x21f];
      lVar2 = *(longlong *)(this + 0x208);
      McTemplateK0jdqsssztttqqtttddqqqqtqqqbr24_EtwWriteTransfer
                (lVar2,&Event_INvdimm_CriticalStatus,&local_48,lVar2 + 400,
                 (char)*(undefined4 *)(lVar2 + 0x20),(char)*(undefined4 *)(lVar2 + 0x134),
                 *(char **)(lVar2 + 0x178),*(char **)(lVar2 + 0x180),*(char **)(lVar2 + 0x188),
                 *(wchar_t **)(lVar2 + 0x140),(byte)IVar8 >> 2 & 1,(byte)IVar8 >> 1 & 1,
                 (byte)IVar8 & 1,this[0x21d],this[0x21e],(byte)IVar6 & 1,(byte)IVar6 >> 1 & 1,
                 (byte)IVar6 >> 2 & 1,(char)*(undefined2 *)(this + 0x220),
                 (char)*(undefined2 *)(this + 0x222),(char)*(undefined4 *)(this + 0x224),this[0x228]
                 ,this[0x233],(char)*(undefined4 *)(this + 0x294),this[800],this[0x321],
                 (char)*(undefined4 *)(this + 0x324),*(undefined4 *)(this + 0x234),this + 0x238);
    }
    bVar5 = true;
  }
  else {
LAB_1c0006bc0:
    WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x208),4,
                    "INvdimm::HandleDeviceHealthErrors: critical status recovered");
  }
  IVar8 = this[0x21c];
  if (((byte)IVar8 & 1) == 0) {
    if (((byte)this[0x2a4] & 1) != 0) {
      WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x208),4,
                      "INvdimm::HandleDeviceHealthErrors: non-critical status recovered");
    }
  }
  else {
    if ((Microsoft_Windows_PersistentMemory_NvdimmEnableBits & 8) != 0) {
      IVar6 = this[0x21f];
      lVar2 = *(longlong *)(this + 0x208);
      McTemplateK0jdqsssztttqqtttddqqqqtqqqbr24_EtwWriteTransfer
                (lVar2,&Event_INvdimm_NonCriticalStatus,&local_48,lVar2 + 400,
                 (char)*(undefined4 *)(lVar2 + 0x20),(char)*(undefined4 *)(lVar2 + 0x134),
                 *(char **)(lVar2 + 0x178),*(char **)(lVar2 + 0x180),*(char **)(lVar2 + 0x188),
                 *(wchar_t **)(lVar2 + 0x140),(byte)IVar8 >> 2 & 1,(byte)IVar8 >> 1 & 1,
                 (byte)IVar8 & 1,this[0x21d],this[0x21e],(byte)IVar6 & 1,(byte)IVar6 >> 1 & 1,
                 (byte)IVar6 >> 2 & 1,(char)*(undefined2 *)(this + 0x220),
                 (char)*(undefined2 *)(this + 0x222),(char)*(undefined4 *)(this + 0x224),this[0x228]
                 ,this[0x233],(char)*(undefined4 *)(this + 0x294),this[800],this[0x321],
                 (char)*(undefined4 *)(this + 0x324),*(undefined4 *)(this + 0x234),this + 0x238);
    }
    bVar5 = true;
  }
  IVar8 = this[0x21f];
  if ((((byte)IVar8 & 6) == 0) || (((byte)this[0x2a7] & 6) != 0)) {
    if ((((byte)this[0x2a7] & 4) != 0) || (((byte)this[0x2a7] & 2) != 0)) {
      WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x208),4,
                      "INvdimm::HandleDeviceHealthErrors: excessive temperature recovered");
    }
  }
  else {
    if ((Microsoft_Windows_PersistentMemory_NvdimmEnableBits & 4) != 0) {
      IVar6 = this[0x21c];
      lVar2 = *(longlong *)(this + 0x208);
      McTemplateK0jdqsssztttqqtttddqqqqtqqqbr24_EtwWriteTransfer
                (lVar2,&Event_INvdimm_ExcessiveTemperature,&local_48,lVar2 + 400,
                 (char)*(undefined4 *)(lVar2 + 0x20),(char)*(undefined4 *)(lVar2 + 0x134),
                 *(char **)(lVar2 + 0x178),*(char **)(lVar2 + 0x180),*(char **)(lVar2 + 0x188),
                 *(wchar_t **)(lVar2 + 0x140),(byte)IVar6 >> 2 & 1,(byte)IVar6 >> 1 & 1,
                 (byte)IVar6 & 1,this[0x21d],this[0x21e],(byte)IVar8 & 1,(byte)IVar8 >> 1 & 1,
                 (byte)IVar8 >> 2 & 1,(char)*(undefined2 *)(this + 0x220),
                 (char)*(undefined2 *)(this + 0x222),(char)*(undefined4 *)(this + 0x224),this[0x228]
                 ,this[0x233],(char)*(undefined4 *)(this + 0x294),this[800],this[0x321],
                 (char)*(undefined4 *)(this + 0x324),*(undefined4 *)(this + 0x234),this + 0x238);
    }
    bVar5 = true;
  }
  IVar8 = this[0x2a4];
  IVar6 = this[0x21c];
  if (((((byte)IVar6 & 7) == 0) && (IVar1 = this[0x21f], ((byte)IVar1 & 1) != 0)) &&
     ((((byte)IVar8 & 7) != 0 || (((byte)this[0x2a7] & 1) == 0)))) {
    if ((Microsoft_Windows_PersistentMemory_NvdimmEnableBits & 8) != 0) {
      lVar2 = *(longlong *)(this + 0x208);
      McTemplateK0jdqsssztttqqtttddqqqqtqqqbr24_EtwWriteTransfer
                (lVar2,&Event_INvdimm_NonCriticalStatus,&local_48,lVar2 + 400,
                 (char)*(undefined4 *)(lVar2 + 0x20),(char)*(undefined4 *)(lVar2 + 0x134),
                 *(char **)(lVar2 + 0x178),*(char **)(lVar2 + 0x180),*(char **)(lVar2 + 0x188),
                 *(wchar_t **)(lVar2 + 0x140),(byte)IVar6 >> 2 & 1,(byte)IVar6 >> 1 & 1,
                 (byte)IVar6 & 1,this[0x21d],this[0x21e],(byte)IVar1 & 1,(byte)IVar1 >> 1 & 1,
                 (byte)IVar1 >> 2 & 1,(char)*(undefined2 *)(this + 0x220),
                 (char)*(undefined2 *)(this + 0x222),(char)*(undefined4 *)(this + 0x224),this[0x228]
                 ,this[0x233],(char)*(undefined4 *)(this + 0x294),this[800],this[0x321],
                 (char)*(undefined4 *)(this + 0x324),*(undefined4 *)(this + 0x234),this + 0x238);
      IVar6 = this[0x21c];
      IVar8 = this[0x2a4];
    }
    bVar5 = true;
  }
  if ((((byte)IVar6 & 7) == 0) && (((byte)this[0x21f] & 7) == 0)) {
    bVar3 = false;
  }
  else {
    bVar3 = true;
  }
  if ((((byte)IVar8 & 7) == 0) && (((byte)this[0x2a7] & 7) == 0)) {
    bVar4 = false;
  }
  else {
    bVar4 = true;
  }
  if (((!bVar3) && (bVar4)) && ((Microsoft_Windows_PersistentMemory_NvdimmEnableBits & 2) != 0)) {
    IVar8 = this[0x21f];
    lVar2 = *(longlong *)(this + 0x208);
    McTemplateK0jdqsssztttqqtttddqqqqtqqqbr24_EtwWriteTransfer
              (lVar2,&Event_INvdimm_RecoveredHealth,&local_48,lVar2 + 400,
               (char)*(undefined4 *)(lVar2 + 0x20),(char)*(undefined4 *)(lVar2 + 0x134),
               *(char **)(lVar2 + 0x178),*(char **)(lVar2 + 0x180),*(char **)(lVar2 + 0x188),
               *(wchar_t **)(lVar2 + 0x140),(byte)IVar6 >> 2 & 1,(byte)IVar6 >> 1 & 1,
               (byte)IVar6 & 1,this[0x21d],this[0x21e],(byte)IVar8 & 1,(byte)IVar8 >> 1 & 1,
               (byte)IVar8 >> 2 & 1,(char)*(undefined2 *)(this + 0x220),
               (char)*(undefined2 *)(this + 0x222),(char)*(undefined4 *)(this + 0x224),this[0x228],
               this[0x233],(char)*(undefined4 *)(this + 0x294),this[800],this[0x321],
               (char)*(undefined4 *)(this + 0x324),*(undefined4 *)(this + 0x234),this + 0x238);
  }
  if (this[800] != (INvdimm)0x0) {
    if (*(int *)(this + 0x324) < 0) {
      if ((Microsoft_Windows_PersistentMemory_NvdimmEnableBits & 4) != 0) {
        IVar8 = this[0x21f];
        IVar6 = this[0x21c];
        lVar2 = *(longlong *)(this + 0x208);
        McTemplateK0jdqsssztttqqtttddqqqqtqqqbr24_EtwWriteTransfer
                  (lVar2,&Event_INvdimm_EnergySourceFailure,&local_48,lVar2 + 400,
                   (char)*(undefined4 *)(lVar2 + 0x20),(char)*(undefined4 *)(lVar2 + 0x134),
                   *(char **)(lVar2 + 0x178),*(char **)(lVar2 + 0x180),*(char **)(lVar2 + 0x188),
                   *(wchar_t **)(lVar2 + 0x140),(byte)IVar6 >> 2 & 1,(byte)IVar6 >> 1 & 1,
                   (byte)IVar6 & 1,this[0x21d],this[0x21e],(byte)IVar8 & 1,(byte)IVar8 >> 1 & 1,
                   (byte)IVar8 >> 2 & 1,(char)*(undefined2 *)(this + 0x220),
                   (char)*(undefined2 *)(this + 0x222),(char)*(undefined4 *)(this + 0x224),
                   this[0x228],this[0x233],(char)*(undefined4 *)(this + 0x294),this[800],this[0x321]
                   ,(char)*(int *)(this + 0x324),*(undefined4 *)(this + 0x234),this + 0x238);
      }
      bVar5 = true;
    }
    IVar8 = this[0x321];
    if (IVar8 == (INvdimm)0x0) {
LAB_1c000775e:
      if (this[0x32d] != (INvdimm)0x0) {
        if ((Microsoft_Windows_PersistentMemory_NvdimmEnableBits & 2) != 0) {
          IVar8 = this[0x21f];
          IVar6 = this[0x21c];
          lVar2 = *(longlong *)(this + 0x208);
          McTemplateK0jdqsssztttqqtttddqqqqtqqqbr24_EtwWriteTransfer
                    (lVar2,&Event_INvdimm_EnergySourceRecovered,&local_48,lVar2 + 400,
                     (char)*(undefined4 *)(lVar2 + 0x20),(char)*(undefined4 *)(lVar2 + 0x134),
                     *(char **)(lVar2 + 0x178),*(char **)(lVar2 + 0x180),*(char **)(lVar2 + 0x188),
                     *(wchar_t **)(lVar2 + 0x140),(byte)IVar6 >> 2 & 1,(byte)IVar6 >> 1 & 1,
                     (byte)IVar6 & 1,this[0x21d],this[0x21e],(byte)IVar8 & 1,(byte)IVar8 >> 1 & 1,
                     (byte)IVar8 >> 2 & 1,(char)*(undefined2 *)(this + 0x220),
                     (char)*(undefined2 *)(this + 0x222),(char)*(undefined4 *)(this + 0x224),
                     this[0x228],this[0x233],(char)*(undefined4 *)(this + 0x294),this[800],0,
                     (char)*(undefined4 *)(this + 0x324),*(undefined4 *)(this + 0x234),this + 0x238)
          ;
        }
        bVar5 = true;
      }
    }
    else if (this[0x32d] == (INvdimm)0x0) {
      if ((Microsoft_Windows_PersistentMemory_NvdimmEnableBits & 4) != 0) {
        IVar6 = this[0x21f];
        IVar1 = this[0x21c];
        lVar2 = *(longlong *)(this + 0x208);
        McTemplateK0jdqsssztttqqtttddqqqqtqqqbr24_EtwWriteTransfer
                  (lVar2,&Event_INvdimm_EnergySourceFailure,&local_48,lVar2 + 400,
                   (char)*(undefined4 *)(lVar2 + 0x20),(char)*(undefined4 *)(lVar2 + 0x134),
                   *(char **)(lVar2 + 0x178),*(char **)(lVar2 + 0x180),*(char **)(lVar2 + 0x188),
                   *(wchar_t **)(lVar2 + 0x140),(byte)IVar1 >> 2 & 1,(byte)IVar1 >> 1 & 1,
                   (byte)IVar1 & 1,this[0x21d],this[0x21e],(byte)IVar6 & 1,(byte)IVar6 >> 1 & 1,
                   (byte)IVar6 >> 2 & 1,(char)*(undefined2 *)(this + 0x220),
                   (char)*(undefined2 *)(this + 0x222),(char)*(undefined4 *)(this + 0x224),
                   this[0x228],this[0x233],(char)*(undefined4 *)(this + 0x294),this[800],IVar8,
                   (char)*(undefined4 *)(this + 0x324),*(undefined4 *)(this + 0x234),this + 0x238);
        IVar8 = this[0x321];
      }
      bVar5 = true;
      if (IVar8 == (INvdimm)0x0) goto LAB_1c000775e;
    }
  }
  if (bVar5) {
    local_c8 = 0;
    _Dst = local_c7;
    memset(_Dst,0,0x77);
    pIVar7 = this + 0x31c;
    `anonymous_namespace'::PrepareWheaErrorData
              (_Dst,(longlong)(this + 0x210),*(undefined4 *)(this + 0x294),(longlong)pIVar7,
               *(undefined4 *)(this + 0x324),&local_c8);
    NvdimmWheaReportError
              (*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x208),&local_c8,0x78,
               (_WHEA_ERROR_SEVERITY)pIVar7);
  }
LAB_1c0007973:
  KeReleaseMutex(this + 0x330,0);
  return;
}



===== PassthroughCommand @ 1c00079c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl INvdimm::PassthroughCommand(struct _GUID const & __ptr64,void *
   __ptr64,unsigned long,void * __ptr64,unsigned long,unsigned long * __ptr64) __ptr64 */

long __thiscall
INvdimm::PassthroughCommand
          (INvdimm *this,_GUID *param_1,void *param_2,ulong param_3,void *param_4,ulong param_5,
          ulong *param_6)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  INvdimmCommandEffectLog *this_00;
  code *pcVar4;
  uint uVar5;
  int iVar6;
  long lVar7;
  undefined8 uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  char *pcVar11;
  ulong uVar12;
  bool bVar13;
  bool local_res8 [8];
  
  LOCK();
  bVar13 = *(int *)(this + 0x118) == 0;
  if (bVar13) {
    *(int *)(this + 0x118) = 1;
  }
  UNLOCK();
  if (bVar13) {
    if (*(longlong **)(this + 0x110) == (longlong *)0x0) {
      wistd::__throw_bad_function_call();
      pcVar4 = (code *)swi(3);
      lVar7 = (*pcVar4)();
      return lVar7;
    }
    uVar8 = (**(code **)(**(longlong **)(this + 0x110) + 0x20))();
    lVar2 = *(longlong *)(this + 0x120);
    *(undefined8 *)(this + 0x120) = uVar8;
    if (lVar2 != 0) {
      lVar3 = *(longlong *)(lVar2 + 0x10);
      *(undefined8 *)(lVar2 + 0x10) = 0;
      if (lVar3 != 0) {
        ExFreePoolWithTag(lVar3,0);
      }
      ExFreePoolWithTag(lVar2,0);
    }
  }
  this_00 = *(INvdimmCommandEffectLog **)(this + 0x120);
  if ((this_00 == (INvdimmCommandEffectLog *)0x0) || (*(int *)this_00 < 0)) {
    if (*(int *)(this + 0x118) == 0) {
      uVar5 = 0xc0000184;
    }
    else if (this_00 == (INvdimmCommandEffectLog *)0x0) {
      uVar5 = 0xc0000017;
    }
    else {
      uVar5 = *(uint *)this_00;
    }
    pcVar11 = 
    "INvdimm::PassthroughCommand(): Passthrough is disabled because the command effect log couldn\'t be retrieved (0x%x)"
    ;
    uVar12 = 2;
  }
  else {
    if ((*(longlong *)param_1 != 0x11e40d114309ac30) ||
       (*(longlong *)(param_1 + 8) != 0x669a0c2000089191)) {
      return -0x3fff5fed;
    }
    if (((param_3 < 0xc) || (param_5 < 0xc)) || (param_3 < *(int *)((longlong)param_2 + 4) + 8U)) {
      return -0x3ffffff3;
    }
    local_res8[0] = false;
    uVar5 = INvdimmCommandEffectLog::AllowPassthroughCommand(this_00,*(ulong *)param_2,local_res8);
    if (-1 < (int)uVar5) {
      if (local_res8[0] == false) {
        WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x208),3,
                        "INvdimm::PassthroughCommand: opcode 0x%x is not allowed",
                        (ulonglong)*(uint *)param_2);
        return -0x3ffffff0;
      }
      uVar5 = *(int *)((longlong)param_2 + 4) + 8;
      uVar12 = param_5;
      if (0xfffe < param_5) {
        uVar12 = 0xffff;
      }
      if (0xffff < uVar5) {
        return -0x3ffffff3;
      }
      puVar9 = (undefined4 *)ExAllocatePool2(0x100,uVar5,0x7470764e);
      puVar10 = (undefined4 *)ExAllocatePool2(0x100,uVar12,0x7470764e);
      if (puVar9 == (undefined4 *)0x0) {
        if (puVar10 == (undefined4 *)0x0) {
          return -0x3fffff66;
        }
      }
      else {
        if (puVar10 != (undefined4 *)0x0) {
          *puVar9 = *(undefined4 *)param_2;
          uVar1 = *(uint *)((longlong)param_2 + 4);
          puVar9[1] = uVar1;
          memcpy(puVar9 + 2,(void *)((longlong)param_2 + 8),(ulonglong)uVar1);
          iVar6 = (**(code **)(*(longlong *)(this + 0x208) + 0x78))
                            (*(undefined8 *)(*(longlong *)(this + 0x208) + 0x58),&DAT_1c00150d0,2,9,
                             puVar9,(short)uVar5,puVar10,(short)uVar12);
          *param_6 = 0;
          if (-1 < iVar6) {
            *(undefined2 *)param_4 = *(undefined2 *)puVar10;
            *(undefined2 *)((longlong)param_4 + 2) = *(undefined2 *)((longlong)puVar10 + 2);
            uVar5 = puVar10[1];
            *(uint *)((longlong)param_4 + 4) = uVar5;
            if (param_5 - 8 < uVar5) {
              ExFreePoolWithTag(puVar10,0);
              ExFreePoolWithTag(puVar9,0);
              return -0x3fffffdd;
            }
            memcpy((void *)((longlong)param_4 + 8),puVar10 + 2,(ulonglong)uVar5);
            *param_6 = *(int *)((longlong)param_4 + 4) + 8;
          }
          ExFreePoolWithTag(puVar10,0);
          ExFreePoolWithTag(puVar9,0);
          return iVar6;
        }
        puVar10 = puVar9;
      }
      ExFreePoolWithTag(puVar10,0);
      return -0x3fffff66;
    }
    pcVar11 = "INvdimm::PassthroughCommand: AllowPassthroughCommand() failed with NTSTATUS 0x%x";
    uVar12 = 3;
  }
  WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x208),uVar12,pcVar11,(ulonglong)uVar5);
  return uVar5;
}



===== RefreshHealthStatus @ 1c0007d10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: virtual long __cdecl INvdimm::RefreshHealthStatus(enum
   _NVDIMM_DEVICE_HEALTH_CHECK_REASON) __ptr64 */

long __thiscall
INvdimm::RefreshHealthStatus(INvdimm *this,_NVDIMM_DEVICE_HEALTH_CHECK_REASON param_1)

{
  _IDSM_HEALTH_INFO *p_Var1;
  INvdimm IVar2;
  INvdimm IVar3;
  longlong lVar4;
  bool bVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  undefined1 auStackY_178 [32];
  uint local_88;
  undefined4 local_84;
  undefined8 local_50;
  undefined8 uStack_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_178;
  KeWaitForSingleObject(this + 0x330,0,0,0);
  p_Var1 = (_IDSM_HEALTH_INFO *)(this + 0x210);
  uVar6 = (**(code **)(*(longlong *)(this + 0x208) + 0x78))
                    (*(undefined8 *)(*(longlong *)(this + 0x208) + 0x58),&DAT_1c00150d0,2,1);
  if ((int)uVar6 < 0) {
    pcVar8 = "INvdimm::RefreshHealthStatus(): health status failed with NTSTATUS 0x%x";
    uVar7 = uVar6;
  }
  else {
    uVar7 = FUNCTION_SPECIFIC_IDSM_STATUS_TO_NTSTATUS(*(uint *)p_Var1,1);
    if (-1 < (int)uVar7) goto LAB_1c0007dfe;
    uVar6 = *(uint *)p_Var1;
    pcVar8 = "INvdimm::RefreshHealthStatus(): health status failed with _DSM error 0x%x";
  }
  WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x208),2,pcVar8,(ulonglong)uVar6);
LAB_1c0007dfe:
  *(uint *)(this + 0x294) = uVar7;
  bVar5 = NvdShouldFakeHealthProblem(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x208));
  if (bVar5) {
    this[0x21c] = (INvdimm)((byte)this[0x21c] | 2);
    this[0x21f] = (INvdimm)((byte)this[0x21f] | 1);
    this[0x21d] = (INvdimm)0x0;
    WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x208),2,
                    "INvdimm::RefreshHealthStatus(): Faking a health problem because of a registry error injection"
                   );
  }
  local_84 = 0;
  local_88 = (**(code **)(*(longlong *)(this + 0x208) + 0x78))
                       (*(undefined8 *)(*(longlong *)(this + 0x208) + 0x58),&DAT_1c00150d0,2,0x40);
  if ((int)local_88 < 0) {
    if (this[800] == (INvdimm)0x0) {
      WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x208),4,
                      "INvdimm::RefreshHealthStatus(): energy source _DSM failed with NTSTATUS 0x%x - assuming not AD-WB"
                      ,(ulonglong)local_88);
      local_88 = 0;
    }
    else {
      WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x208),2,
                      "INvdimm::RefreshHealthStatus(): energy source _DSM failed with NTSTATUS 0x%x while in AD-WB mode"
                      ,(ulonglong)local_88);
    }
  }
  else {
    local_88 = FUNCTION_SPECIFIC_IDSM_STATUS_TO_NTSTATUS(0,0x40);
    if ((int)local_88 < 0) {
      if (this[800] == (INvdimm)0x0) {
        WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x208),4,
                        "INvdimm::RefreshHealthStatus(): energy source _DSM failed with _DSM error 0x%x - assuming not AD-WB"
                       );
        local_88 = 0;
      }
      else {
        WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x208),2,
                        "INvdimm::RefreshHealthStatus(): energy source _DSM failed with _DSM error 0x%x while in AD-WB mode"
                       );
      }
    }
    else {
      *(undefined4 *)(this + 0x31c) = local_84;
      *(undefined2 *)(this + 800) = 0;
    }
  }
  *(uint *)(this + 0x324) = local_88;
  if (param_1 == 1) {
    local_50 = 0;
    uStack_48 = 0;
    if ((Microsoft_Windows_PersistentMemory_NvdimmEnableBits & 2) != 0) {
      IVar2 = this[0x21c];
      IVar3 = this[0x21f];
      lVar4 = *(longlong *)(this + 0x208);
      McTemplateK0jdqsssztttqqtttddqqqqtqqqbr24_EtwWriteTransfer
                (lVar4,&Event_INvdimm_ReceivedNvdimmNotification,&local_50,lVar4 + 400,
                 (char)*(undefined4 *)(lVar4 + 0x20),(char)*(undefined4 *)(lVar4 + 0x134),
                 *(char **)(lVar4 + 0x178),*(char **)(lVar4 + 0x180),*(char **)(lVar4 + 0x188),
                 *(wchar_t **)(lVar4 + 0x140),(byte)IVar2 >> 2 & 1,(byte)IVar2 >> 1 & 1,
                 (byte)IVar2 & 1,this[0x21d],this[0x21e],(byte)IVar3 & 1,(byte)IVar3 >> 1 & 1,
                 (byte)IVar3 >> 2 & 1,(char)*(undefined2 *)(this + 0x220),
                 (char)*(undefined2 *)(this + 0x222),(char)*(undefined4 *)(this + 0x224),this[0x228]
                 ,this[0x233],(char)*(undefined4 *)(this + 0x294),this[800],this[0x321],
                 (char)local_88,*(undefined4 *)(this + 0x234),this + 0x238);
    }
  }
  HandleDeviceHealthErrors(this);
  if (-1 < (int)local_88) {
    *(undefined8 *)(this + 0x298) = *(undefined8 *)p_Var1;
    *(undefined8 *)(this + 0x2a0) = *(undefined8 *)(this + 0x218);
    *(undefined8 *)(this + 0x2a8) = *(undefined8 *)(this + 0x220);
    *(undefined8 *)(this + 0x2b0) = *(undefined8 *)(this + 0x228);
    *(undefined8 *)(this + 0x2b8) = *(undefined8 *)(this + 0x230);
    *(undefined8 *)(this + 0x2c0) = *(undefined8 *)(this + 0x238);
    *(undefined8 *)(this + 0x2c8) = *(undefined8 *)(this + 0x240);
    *(undefined8 *)(this + 0x2d0) = *(undefined8 *)(this + 0x248);
    *(undefined8 *)(this + 0x2d8) = *(undefined8 *)(this + 0x250);
    *(undefined8 *)(this + 0x2e0) = *(undefined8 *)(this + 600);
    *(undefined8 *)(this + 0x2e8) = *(undefined8 *)(this + 0x260);
    *(undefined8 *)(this + 0x2f0) = *(undefined8 *)(this + 0x268);
    *(undefined8 *)(this + 0x2f8) = *(undefined8 *)(this + 0x270);
    *(undefined8 *)(this + 0x300) = *(undefined8 *)(this + 0x278);
    *(undefined8 *)(this + 0x308) = *(undefined8 *)(this + 0x280);
    *(undefined8 *)(this + 0x310) = *(undefined8 *)(this + 0x288);
    *(undefined4 *)(this + 0x318) = *(undefined4 *)(this + 0x290);
    *(undefined4 *)(this + 0x328) = *(undefined4 *)(this + 0x31c);
    *(undefined2 *)(this + 0x32c) = *(undefined2 *)(this + 800);
    local_88 = GetUnsafeShutdownCountFromDsm(this,(ulong *)(this + 0x1f8),(ulong *)(this + 0x1fc));
    if (-1 < (int)local_88) {
      local_88 = HandleDataLossFailures(this);
    }
  }
  INvdimmTelemetry::LogDeviceHealth
            (*(INvdimmTelemetry **)(this + 0x10),local_88,param_1,p_Var1,
             (_IDSM_ENERGY_SOURCE_STATUS *)(this + 0x31c));
  KeReleaseMutex(this + 0x330,0);
  return local_88;
}



===== RefreshSecurityState @ 1c0008280 =====

/* public: virtual long __cdecl INvdimm::RefreshSecurityState(void) __ptr64 */

long __thiscall INvdimm::RefreshSecurityState(INvdimm *this)

{
  long lVar1;
  
  lVar1 = INvdimmSecurityManager::UpdateCachedSecurityState
                    ((INvdimmSecurityManager *)(this + 0x128));
  return lVar1;
}



===== ReinitializeMedia @ 1c00082a0 =====

/* public: virtual long __cdecl INvdimm::ReinitializeMedia(bool,enum
   _SCM_PD_MEDIA_REINITIALIZATION_STATUS * __ptr64) __ptr64 */

long __thiscall
INvdimm::ReinitializeMedia
          (INvdimm *this,bool param_1,_SCM_PD_MEDIA_REINITIALIZATION_STATUS *param_2)

{
  long lVar1;
  uint uVar2;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = *(undefined8 *)(this + 0x148);
  uStack_10 = *(undefined8 *)(this + 0x150);
  lVar1 = INvdimmMediaReinitializer::ReinitializeMedia
                    ((INvdimmMediaReinitializer *)(this + 0x1a0),(_STRING *)&local_18,param_1,
                     param_2);
  uVar2 = INvdimmSecurityManager::UpdateCachedSecurityState
                    ((INvdimmSecurityManager *)(this + 0x128));
  if ((int)uVar2 < 0) {
    WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x208),2,
                    "INvdimm::ReinitializeMedia(): Failed to update cached security state with NTSTATUS 0x%x"
                    ,(ulonglong)uVar2);
  }
  return lVar1;
}



===== ResumeFromHibernate @ 1c0008320 =====

/* public: virtual long __cdecl INvdimm::ResumeFromHibernate(void) __ptr64 */

long __thiscall INvdimm::ResumeFromHibernate(INvdimm *this)

{
  uint uVar1;
  
  uVar1 = `anonymous_namespace'::EnableLatchLss(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x208));
  if ((int)uVar1 < 0) {
    WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x208),2,
                    "Invdimm::ResumeFromHibernate: failed to latch LSS (0x%x)",(ulonglong)uVar1);
  }
  else {
    WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x208),4,
                    "INvdimm::ResumeFromHibernate: latched LSS successfully.");
  }
  return uVar1;
}



===== SelectFirmwareImageSlot @ 1c0008390 =====

/* public: virtual long __cdecl INvdimm::SelectFirmwareImageSlot(unsigned char) __ptr64 */

long __thiscall INvdimm::SelectFirmwareImageSlot(INvdimm *this,uchar param_1)

{
  uint uVar1;
  INvdimmFwUpdater *pIVar2;
  
  if (param_1 == '\0') {
    uVar1 = 0;
  }
  else if (param_1 < 2) {
    pIVar2 = Lazy<INvdimmFwUpdater>::Get((Lazy<INvdimmFwUpdater> *)(this + 0x18));
    if (pIVar2 == (INvdimmFwUpdater *)0x0) {
      if (*(int *)(this + 0x90) == 0) {
        uVar1 = 0xc0000184;
      }
      else if (*(uint **)(this + 0x98) == (uint *)0x0) {
        uVar1 = 0xc0000017;
      }
      else {
        uVar1 = **(uint **)(this + 0x98);
      }
      WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x208),2,
                      "INvdimm::SelectFirmwareImageSlot(): Failed to select firmware image slot because the firmware updater initialization failed with NTSTATUS 0x%x"
                      ,(ulonglong)uVar1);
    }
    else if (*(int *)(pIVar2 + 0x44) == 3) {
      uVar1 = 0x80000031;
    }
    else {
      uVar1 = -(uint)(*(int *)(pIVar2 + 0x44) != 5) & 0xc0000010;
    }
  }
  else {
    uVar1 = 0xc000000d;
  }
  return uVar1;
}



===== SetDeviceRuntimeFwActivationArmState @ 1c0008430 =====

/* public: virtual long __cdecl INvdimm::SetDeviceRuntimeFwActivationArmState(unsigned char) __ptr64
    */

long __thiscall INvdimm::SetDeviceRuntimeFwActivationArmState(INvdimm *this,uchar param_1)

{
  uint uVar1;
  INvdimmFwUpdater *this_00;
  ulong uVar2;
  char *pcVar3;
  undefined2 local_res8;
  undefined4 local_resa;
  undefined2 local_rese;
  
  this_00 = Lazy<INvdimmFwUpdater>::Get((Lazy<INvdimmFwUpdater> *)(this + 0x18));
  if (this_00 == (INvdimmFwUpdater *)0x0) {
    if (*(int *)(this + 0x90) == 0) {
      uVar1 = 0xc0000184;
    }
    else if (*(uint **)(this + 0x98) == (uint *)0x0) {
      uVar1 = 0xc0000017;
    }
    else {
      uVar1 = **(uint **)(this + 0x98);
    }
    pcVar3 = 
    "INvdimm::SetDeviceRuntimeFwActivationArmState(): Firmware updater initialization failed with NTSTATUS 0x%x"
    ;
  }
  else {
    local_res8 = 0;
    local_resa = 0;
    local_rese = 0;
    uVar1 = INvdimmFwUpdater::GetDeviceRuntimeFirmwareActivationInfo
                      (this_00,(_IDSM_GET_DEVICE_RUNTIME_FW_ACTIVATION_INFO_OUTPUT *)&local_res8);
    if ((int)uVar1 < 0) {
      pcVar3 = 
      "INvdimm::SetDeviceRuntimeFwActivationArmState(): Failed to get Runtime Fw Activation Info with NTSTATUS 0x%x"
      ;
    }
    else {
      if ((char)local_rese == '\x02') {
        uVar1 = 0xc0000184;
        pcVar3 = 
        "INvdimm::SetDeviceRuntimeFwActivationArmState(): Abort to set Runtime Fw Activation Arm State with NTSTATUS 0x%x"
        ;
        uVar2 = 4;
        goto LAB_1c00084f4;
      }
      uVar1 = INvdimmFwUpdater::SetDeviceRuntimeFirmwareActivationArmState
                        (this_00,(uint)(param_1 != '\0'));
      if (-1 < (int)uVar1) {
        return uVar1;
      }
      pcVar3 = 
      "INvdimm::SetDeviceRuntimeFwActivationArmState(): Failed to set Runtime Fw Activation Arm State with NTSTATUS 0x%x"
      ;
    }
  }
  uVar2 = 2;
LAB_1c00084f4:
  WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x208),uVar2,pcVar3,(ulonglong)uVar1);
  return uVar1;
}



===== UpdateBaselineUnsafeShutdownCount @ 1c0008520 =====

/* private: long __cdecl INvdimm::UpdateBaselineUnsafeShutdownCount(unsigned long) __ptr64 */

long __thiscall INvdimm::UpdateBaselineUnsafeShutdownCount(INvdimm *this,ulong param_1)

{
  uint uVar1;
  
  uVar1 = NvdWriteDeviceRegistryUlong
                    (*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x208),
                     (ushort *)L"BaselineUnsafeShutdownCount",param_1);
  if ((int)uVar1 < 0) {
    WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x208),2,
                    "INvdimm::UpdateBaselineUnsafeShutdownCount: failed to write new baseline with status 0x%x"
                    ,(ulonglong)uVar1);
  }
  return uVar1;
}



===== __clone @ 1c0008580 =====

void wistd::__function::
     __func<<lambda_19eb9d4442d94dae27ff02cd8a0db90c>,INvdimmFwUpdater_*___cdecl(void)>::__clone
               (longlong param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  *param_2 = &PTR__scalar_deleting_destructor__1c000f238;
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  param_2[1] = *(undefined8 *)(param_1 + 8);
  param_2[2] = uVar1;
  return;
}



===== __clone @ 1c00085a0 =====

void wistd::__function::
     __func<<lambda_bb9bbeef4085303a346b29e35479209a>,INvdimmCommandEffectLog_*___cdecl(void)>::
     __clone(longlong param_1,undefined8 *param_2)

{
  *param_2 = &PTR__scalar_deleting_destructor__1c000f300;
  param_2[1] = *(undefined8 *)(param_1 + 8);
  return;
}



===== __throw_bad_function_call @ 1c00085bc =====

/* void __cdecl wistd::__throw_bad_function_call(void) */

void __cdecl wistd::__throw_bad_function_call(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(7);
  return;
}



===== destroy @ 1c00085d0 =====

void wistd::__function::
     __func<<lambda_19eb9d4442d94dae27ff02cd8a0db90c>,INvdimmFwUpdater_*___cdecl(void)>::destroy
               (void)

{
  return;
}



===== FUNCTION_SPECIFIC_IDSM_STATUS_TO_NTSTATUS @ 1c00085dc =====

undefined4 FUNCTION_SPECIFIC_IDSM_STATUS_TO_NTSTATUS(uint param_1,int param_2)

{
  undefined4 uVar1;
  short sVar2;
  uint uVar3;
  undefined4 uVar4;
  bool bVar5;
  
  sVar2 = (short)param_1;
  if (sVar2 == 7) {
    if (param_2 == 0xd) {
      if (param_1 >> 0x10 == 1) {
        return 0xc0000476;
      }
      if (param_1 >> 0x10 == 2) {
        return 0xc0000184;
      }
    }
    else if (param_2 == 0xe) {
      if (param_1 >> 0x10 == 1) {
        return 0xc00000ef;
      }
    }
    else if (param_2 == 0xf) {
      uVar3 = param_1 >> 0x10;
      if (uVar3 == 1) {
        return 0xc00000ef;
      }
      if (uVar3 == 2) {
        return 0xc0000184;
      }
      if (uVar3 == 3) {
        return 0xc000003e;
      }
      if (uVar3 == 4) {
        return 0;
      }
    }
    else if (param_2 == 0x10) {
      uVar3 = param_1 >> 0x10;
      if (uVar3 == 1) {
        return 0xc00000ef;
      }
      if (uVar3 == 2) {
        return 0x103;
      }
      if (uVar3 == 3) {
        return 0xc000003e;
      }
      if (uVar3 == 4) {
        return 0xc000042a;
      }
    }
    else if (param_2 == 0x18) {
      uVar3 = param_1 >> 0x10;
      if (uVar3 == 10) {
        return 0xc0000184;
      }
      if (uVar3 == 0xb) {
        return 0xc0000184;
      }
      if (uVar3 == 0xc) {
        return 0xc000000d;
      }
    }
    else if (param_2 == 0x1a) {
      uVar1 = 0xc000042a;
      bVar5 = (short)(param_1 >> 0x10) == 2;
      goto LAB_1c000862a;
    }
    uVar1 = 0xc0000001;
  }
  else {
    uVar1 = 0;
    if (sVar2 != 0) {
      if (sVar2 == 1) {
        return 0xc00000bb;
      }
      if (sVar2 == 3) {
        return 0xc000000d;
      }
      if (sVar2 == 2) {
        return 0xc000000e;
      }
      if (sVar2 == 5) {
        return 0xc0000476;
      }
      if (sVar2 == 10) {
        return 0xc0000184;
      }
      uVar1 = 0xc000000d;
      bVar5 = sVar2 == 0xb;
LAB_1c000862a:
      uVar4 = 0xc0000001;
      if (bVar5) {
        uVar4 = uVar1;
      }
      return uVar4;
    }
  }
  return uVar1;
}



===== McTemplateK0jdqsssztttqqtttddqqqqtqqqbr24_EtwWriteTransfer @ 1c0008708 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0jdqsssztttqqtttddqqqqtqqqbr24_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,char *param_7,char *param_8,char *param_9,
               wchar_t *param_10,undefined1 param_11,undefined1 param_12,undefined1 param_13,
               undefined1 param_14,undefined1 param_15,undefined1 param_16,undefined1 param_17,
               undefined1 param_18,undefined1 param_19,undefined1 param_20,undefined1 param_21,
               undefined1 param_22,undefined1 param_23,undefined1 param_24,undefined1 param_25,
               undefined1 param_26,undefined1 param_27,undefined4 param_28,undefined8 param_29)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 auStackY_208 [32];
  undefined8 local_1d8 [2];
  undefined8 local_1c8;
  undefined8 local_1c0;
  undefined1 *local_1b8;
  undefined8 local_1b0;
  undefined1 *local_1a8;
  undefined8 local_1a0;
  char *local_198;
  int local_190;
  undefined4 local_18c;
  char *local_188;
  int local_180;
  undefined4 local_17c;
  char *local_178;
  int local_170;
  undefined4 local_16c;
  wchar_t *local_168;
  int local_160;
  undefined4 local_15c;
  undefined1 *local_158;
  undefined8 local_150;
  undefined1 *local_148;
  undefined8 local_140;
  undefined1 *local_138;
  undefined8 local_130;
  undefined1 *local_128;
  undefined8 local_120;
  undefined1 *local_118;
  undefined8 local_110;
  undefined1 *local_108;
  undefined8 local_100;
  undefined1 *local_f8;
  undefined8 local_f0;
  undefined1 *local_e8;
  undefined8 local_e0;
  undefined1 *local_d8;
  undefined8 local_d0;
  undefined1 *local_c8;
  undefined8 local_c0;
  undefined1 *local_b8;
  undefined8 local_b0;
  undefined1 *local_a8;
  undefined8 local_a0;
  undefined1 *local_98;
  undefined8 local_90;
  undefined1 *local_88;
  undefined8 local_80;
  undefined1 *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined4 *local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_208;
  local_1b8 = &param_5;
  lVar2 = -1;
  local_1a8 = &param_6;
  local_1c0 = 0x10;
  local_1b0 = 4;
  local_1a0 = 4;
  if (param_7 == (char *)0x0) {
    local_190 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_7[lVar1] != '\0');
    local_190 = (int)lVar1 + 1;
  }
  local_18c = 0;
  local_198 = param_7;
  if (param_7 == (char *)0x0) {
    local_198 = "NULL";
  }
  if (param_8 == (char *)0x0) {
    local_180 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_8[lVar1] != '\0');
    local_180 = (int)lVar1 + 1;
  }
  local_17c = 0;
  local_188 = param_8;
  if (param_8 == (char *)0x0) {
    local_188 = "NULL";
  }
  if (param_9 == (char *)0x0) {
    local_170 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_9[lVar1] != '\0');
    local_170 = (int)lVar1 + 1;
  }
  local_16c = 0;
  local_178 = param_9;
  if (param_9 == (char *)0x0) {
    local_178 = "NULL";
  }
  if (param_10 == (wchar_t *)0x0) {
    local_160 = 10;
  }
  else {
    do {
      lVar2 = lVar2 + 1;
    } while (param_10[lVar2] != L'\0');
    local_160 = (int)lVar2 * 2 + 2;
  }
  local_15c = 0;
  local_168 = param_10;
  if (param_10 == (wchar_t *)0x0) {
    local_168 = L"NULL";
  }
  local_2c = 0;
  local_158 = &param_11;
  local_148 = &param_12;
  local_150 = 4;
  local_138 = &param_13;
  local_140 = 4;
  local_128 = &param_14;
  local_130 = 4;
  local_118 = &param_15;
  local_120 = 4;
  local_108 = &param_16;
  local_f8 = &param_17;
  local_e8 = &param_18;
  local_d8 = &param_19;
  local_c8 = &param_20;
  local_b8 = &param_21;
  local_a8 = &param_22;
  local_98 = &param_23;
  local_88 = &param_24;
  local_78 = &param_25;
  local_68 = &param_26;
  local_58 = &param_27;
  local_48 = &param_28;
  local_38 = param_29;
  local_30 = param_28;
  local_110 = 4;
  local_100 = 4;
  local_f0 = 4;
  local_e0 = 4;
  local_d0 = 4;
  local_c0 = 4;
  local_b0 = 4;
  local_a0 = 4;
  local_90 = 4;
  local_80 = 4;
  local_70 = 4;
  local_60 = 4;
  local_50 = 4;
  local_40 = 4;
  local_1c8 = param_4;
  McGenEventWrite_EtwWriteTransfer(&nvdimmEventProvider_Context,param_2,param_3,0x1b,local_1d8);
  return;
}



===== ~lambda_call<<lambda_19680483569ec4d991ca082b80196242>_> @ 1c0008a40 =====

void wil::details::lambda_call<<lambda_19680483569ec4d991ca082b80196242>_>::
     ~lambda_call<<lambda_19680483569ec4d991ca082b80196242>_>(undefined8 *param_1)

{
  longlong lVar1;
  long lVar2;
  undefined4 uVar3;
  undefined4 local_res8 [2];
  
  if (*(char *)(param_1 + 2) != '\0') {
    *(undefined1 *)(param_1 + 2) = 0;
    if (*(int *)*param_1 < 0) {
      if (*(int *)(param_1[1] + 0x44) == 1) {
        WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(param_1[1] + 8),2,
                        "FwUpdater::DownloadFirmwareRegions(): ScopeExit: Aborting update because of an error"
                       );
        lVar2 = INvdimmFwUpdater::AbortFirmwareUpdate((INvdimmFwUpdater *)param_1[1]);
        *(long *)*param_1 = lVar2;
        uVar3 = 4;
        if (-1 < *(int *)*param_1) {
          uVar3 = 0;
        }
        *(undefined4 *)(param_1[1] + 0x44) = uVar3;
      }
      lVar1 = param_1[1];
      local_res8[0] = 0;
      INvdimmTelemetry::LogFwUpdate
                (*(INvdimmTelemetry **)(lVar1 + 0x10),(ushort *)L"DownloadFirmwareRegions",
                 *(long *)*param_1,(_IDSM_STATUS *)local_res8,*(State *)(lVar1 + 0x44),
                 (_IDSM_FIRMWARE_INFO *)(lVar1 + 0x18),*(__uint64 *)(lVar1 + 0x50));
    }
  }
  return;
}



===== AllowPassthroughCommand @ 1c0008af4 =====

/* public: long __cdecl INvdimmCommandEffectLog::AllowPassthroughCommand(unsigned long,bool *
   __ptr64) __ptr64 */

long __thiscall
INvdimmCommandEffectLog::AllowPassthroughCommand
          (INvdimmCommandEffectLog *this,ulong param_1,bool *param_2)

{
  longlong lVar1;
  _NVDIMM_DEVICE_EXTENSION *p_Var2;
  uint uVar3;
  ulonglong uVar4;
  ulong local_res8 [2];
  
  lVar1 = *(longlong *)(this + 0x10);
  uVar4 = 0;
  if (*(ushort *)(lVar1 + 4) != 0) {
    do {
      if (*(ulong *)(lVar1 + 8 + uVar4 * 8) == param_1) {
        if ((*(byte *)(lVar1 + 0xc + uVar4 * 8) & 0x7a) != 0) {
          p_Var2 = *(_NVDIMM_DEVICE_EXTENSION **)(this + 8);
          if (p_Var2[0xe5] != (_NVDIMM_DEVICE_EXTENSION)0x0) {
            *param_2 = true;
            WriteTraceEvent(p_Var2,4,
                            "INvdimmCommandEffectLog::IsCommandAllowed(): command with side effects allowed because NoSPAMapping is set."
                           );
            return 0;
          }
          local_res8[0] = 0;
          *param_2 = false;
          uVar3 = NvdGetLogicalDeviceCount(p_Var2,local_res8);
          if ((int)uVar3 < 0) {
            WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 8),2,
                            "INvdimmCommandEffectLog::IsCommandAllowed(): NvdGetLogicalDeviceCount() failed with NTSTATUS 0x%x"
                            ,(ulonglong)uVar3);
            *param_2 = false;
            return uVar3;
          }
          if (local_res8[0] != 0) {
            WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 8),3,
                            "Command 0x%x has been blocked because it has side effects (effect log: 0x%x) and there are %d logical devices associated with this NVDIMM"
                            ,(ulonglong)*(uint *)(lVar1 + 8 + uVar4 * 8),
                            *(undefined4 *)(lVar1 + 0xc + uVar4 * 8),local_res8[0]);
            *param_2 = false;
            return 0;
          }
        }
        *param_2 = true;
        return 0;
      }
      uVar3 = (int)uVar4 + 1;
      uVar4 = (ulonglong)uVar3;
    } while (uVar3 < *(ushort *)(lVar1 + 4));
  }
  return -0x3ffffff3;
}



===== GetCommandEffectLog @ 1c0008bec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint `anonymous_namespace'::GetCommandEffectLog(_NVDIMM_DEVICE_EXTENSION *param_1,longlong *param_2)

{
  longlong lVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  longlong lVar5;
  int iVar6;
  undefined8 local_res8;
  
  local_res8 = 0;
  uVar3 = (**(code **)(param_1 + 0x78))
                    (*(undefined8 *)(param_1 + 0x58),&DAT_1c00150d0,2,7,0,0,&local_res8,8);
  if ((int)uVar3 < 0) {
    WriteTraceEvent(param_1,2,
                    "GetCommandEffectLog: IDsmGetCommandEffectLogInfo() call failed with NTSTATUS 0x%x"
                    ,(ulonglong)uVar3);
    return uVar3;
  }
  if ((short)local_res8 == 0) {
    WriteTraceEvent(param_1,4,"GetCommandEffectLog: log size is %d bytes",local_res8 >> 0x20);
    uVar3 = local_res8._4_4_ + 8;
    if (uVar3 < 0x10000) {
      lVar5 = ExAllocatePool2(0x100,uVar3,0x7470764e);
      lVar1 = *param_2;
      *param_2 = lVar5;
      if (lVar1 != 0) {
        ExFreePoolWithTag(lVar1,0);
      }
      if (*param_2 == 0) {
        return 0xc000009a;
      }
      uVar4 = (**(code **)(param_1 + 0x78))
                        (*(undefined8 *)(param_1 + 0x58),&DAT_1c00150d0,2,8,0,0,*param_2,
                         (short)uVar3);
      if ((int)uVar4 < 0) {
        WriteTraceEvent(param_1,2,
                        "GetCommandEffectLog: IDsmGetCommandEffectLog() call failed with NTSTATUS 0x%x"
                        ,(ulonglong)uVar4);
        return uVar4;
      }
      puVar2 = (uint *)*param_2;
      if ((short)*puVar2 != 0) {
        WriteTraceEvent(param_1,2,
                        "GetCommandEffectLog: IDsmGetCommandEffectLog() _DSM status is 0x%x",
                        (ulonglong)*puVar2);
        iVar6 = 8;
        uVar3 = *(uint *)*param_2;
        goto LAB_1c0008c93;
      }
      if ((uint)(ushort)puVar2[1] * 8 + 8 <= uVar3) {
        return 0;
      }
      WriteTraceEvent(param_1,2,
                      "GetCommandEffectLog: IDsmGetCommandEffectLog() _DSM returned a number of opcodes that would exceed the buffer size"
                     );
    }
    uVar3 = 0xc0000001;
  }
  else {
    WriteTraceEvent(param_1,2,
                    "GetCommandEffectLog: IDsmGetCommandEffectLogInfo() _DSM status is 0x%x");
    iVar6 = 7;
    uVar3 = (uint)local_res8;
LAB_1c0008c93:
    uVar3 = FUNCTION_SPECIFIC_IDSM_STATUS_TO_NTSTATUS(uVar3,iVar6);
  }
  return uVar3;
}



===== INvdimmSecurityManager @ 1c0008ddc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: __cdecl INvdimmSecurityManager::INvdimmSecurityManager(struct _NVDIMM_DEVICE_EXTENSION *
   __ptr64,class INvdimmTelemetry & __ptr64) __ptr64 */

INvdimmSecurityManager * __thiscall
INvdimmSecurityManager::INvdimmSecurityManager
          (INvdimmSecurityManager *this,_NVDIMM_DEVICE_EXTENSION *param_1,INvdimmTelemetry *param_2)

{
  INvdimmSecurityManager *pIVar1;
  longlong lVar2;
  long lVar3;
  uint uVar4;
  ushort *puVar5;
  undefined1 auStackY_98 [32];
  short local_38 [8];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_98;
  *(_NVDIMM_DEVICE_EXTENSION **)(this + 8) = param_1;
  pIVar1 = this + 0x20;
  *(INvdimmTelemetry **)(this + 0x10) = param_2;
  puVar5 = (ushort *)0x0;
  *(undefined8 *)pIVar1 = 0;
  *(undefined8 *)(this + 0x28) = 0;
  KeInitializeMutex(this + 0x40);
  lVar3 = UpdateCachedSecurityState(this);
  *(long *)this = lVar3;
  if (-1 < lVar3) {
    local_38[0] = 0;
    local_38[1] = 0;
    local_38[2] = 0;
    local_38[3] = 0;
    local_38[4] = 0;
    local_38[5] = 0;
    local_38[6] = 0;
    local_38[7] = 0;
    lVar3 = NvdQueryDeviceRegistryUnicodeString
                      (*(_NVDIMM_DEVICE_EXTENSION **)(this + 8),puVar5,(ushort *)param_2,
                       (_UNICODE_STRING *)local_38);
    this[0x18] = (INvdimmSecurityManager)((byte)((uint)lVar3 >> 0x1f) ^ 1);
    WriteTraceEvent(param_1,4,"INvdimmSecurityManager(): has cached passphrase: %d");
    if ((this[0x18] != (INvdimmSecurityManager)0x0) && (local_38[0] == 0)) {
      WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 8),4,
                      "INvdimmSecurityManager(): passphrase is empty - same as no passphrase key");
      this[0x18] = (INvdimmSecurityManager)0x0;
    }
    uVar4 = RtlUnicodeStringToAnsiString(pIVar1,local_38,1);
    *(uint *)this = uVar4;
    if ((int)uVar4 < 0) {
      WriteTraceEvent(param_1,2,
                      "INvdimmSecurityManager(): passphrase conversion to ANSI failed with NTSTATUS 0x%x"
                      ,(ulonglong)uVar4);
      RtlFreeUnicodeString(local_38);
      return this;
    }
    if (0x20 < *(ushort *)pIVar1) {
      WriteTraceEvent(param_1,2,
                      "INvdimmSecurityManager(): passphrase too long (%d characters; maximum is %d)"
                      ,(ulonglong)*(ushort *)pIVar1);
      *(undefined4 *)this = 0xc000000d;
    }
    RtlFreeUnicodeString(local_38);
  }
  if (-1 < *(int *)this) {
    lVar3 = InitializeSecurity(this);
    *(long *)this = lVar3;
  }
  if ((*(uint *)(this + 0x38) & 4) != 0) {
    local_38[0] = 0;
    local_38[1] = 0;
    local_38[2] = 0;
    local_38[3] = 0;
    local_38[4] = 0;
    local_38[5] = 0;
    local_38[6] = 0;
    local_38[7] = 0;
    if ((Microsoft_Windows_PersistentMemory_NvdimmEnableBits & 8) != 0) {
      lVar2 = *(longlong *)(this + 8);
      McTemplateK0jdqssszq_EtwWriteTransfer
                ((ulonglong)*(uint *)(lVar2 + 0x20),&Event_INvdimm_LockedNvdimm,local_38,lVar2 + 400
                 ,(char)*(uint *)(lVar2 + 0x20),(char)*(undefined4 *)(lVar2 + 0x134),
                 *(char **)(lVar2 + 0x178),*(char **)(lVar2 + 0x180),*(char **)(lVar2 + 0x188),
                 *(wchar_t **)(lVar2 + 0x140),(char)*(uint *)(this + 0x38));
    }
  }
  return this;
}



===== NvdimmTelemetry @ 1c0008fcc =====

/* public: __cdecl NvdimmTelemetry::NvdimmTelemetry(struct _NVDIMM_DEVICE_EXTENSION * __ptr64)
   __ptr64 */

NvdimmTelemetry * __thiscall
NvdimmTelemetry::NvdimmTelemetry(NvdimmTelemetry *this,_NVDIMM_DEVICE_EXTENSION *param_1)

{
  undefined8 uVar1;
  
  *(_NVDIMM_DEVICE_EXTENSION **)(this + 0x88) = param_1;
  *(undefined ***)this = &_vftable_;
  uVar1 = KeQueryUnbiasedInterruptTime();
  *(undefined8 *)(param_1 + 0x1b0) = uVar1;
  LOCK();
  s_deviceCount = s_deviceCount + 1;
  UNLOCK();
  KeInitializeTimer(this + 8);
  if (*(int *)(param_1 + 0x1f8) == 0) {
    KeQueryUnbiasedInterruptTime();
    KeInitializeDpc(this + 0x48,`anonymous_namespace'::PeriodicTimerDpcRoutine,param_1);
    KeSetCoalescableTimer
              (this + 8,(-0x15 - (longlong)s_deviceCount) * 288000000000,0,900000,this + 0x48);
  }
  return this;
}



===== ~NvdimmTelemetry @ 1c00090b0 =====

/* public: virtual __cdecl NvdimmTelemetry::~NvdimmTelemetry(void) __ptr64 */

void __thiscall NvdimmTelemetry::~NvdimmTelemetry(NvdimmTelemetry *this)

{
  *(undefined ***)this = &_vftable_;
  LOCK();
  s_deviceCount = s_deviceCount + -1;
  UNLOCK();
  if (*(int *)(*(longlong *)(this + 0x88) + 0x1f8) == 0) {
    KeCancelTimer(this + 8);
  }
  return;
}



===== `vector_deleting_destructor' @ 1c0009100 =====

/* public: virtual void * __ptr64 __cdecl SimulatedNvdimmTelemetry::`vector deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
SimulatedNvdimmTelemetry::_vector_deleting_destructor_(SimulatedNvdimmTelemetry *this,uint param_1)

{
  *(undefined ***)this = &_vftable_;
  NvdimmTelemetry::~NvdimmTelemetry((NvdimmTelemetry *)this);
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 1c0009150 =====

/* public: virtual void * __ptr64 __cdecl NvdimmTelemetry::`scalar deleting destructor'(unsigned
   int) __ptr64 */

void * __thiscall NvdimmTelemetry::_scalar_deleting_destructor_(NvdimmTelemetry *this,uint param_1)

{
  ~NvdimmTelemetry(this);
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0);
  }
  return this;
}



===== PeriodicTimerDpcRoutine @ 1c0009190 =====

void `anonymous_namespace'::PeriodicTimerDpcRoutine(undefined8 param_1,undefined8 *param_2)

{
  int iVar1;
  longlong lVar2;
  
  iVar1 = IoAcquireRemoveLockEx(param_2 + 0x1e,param_2,"",1,0x20);
  if (iVar1 == 0) {
    lVar2 = IoAllocateWorkItem(*param_2);
    if (lVar2 == 0) {
      KeSetCoalescableTimer(param_2[0x37] + 8,0xfffffa7fd71bc000,0,900000,param_2[0x37] + 0x48);
      IoReleaseRemoveLockEx(param_2 + 0x1e,param_2,0x20);
    }
    else {
      IoQueueWorkItem(lVar2,PeriodicHealthWorkItemRoutine,3,lVar2);
    }
  }
  return;
}



===== _tlgDefineProvider_annotation__TlgNvdimmTraceLoggingProviderProv @ 1c0009264 =====

void _tlgDefineProvider_annotation__TlgNvdimmTraceLoggingProviderProv(void)

{
  return;
}



===== ~NvdimmN @ 1c0009270 =====

/* public: virtual __cdecl NvdimmN::~NvdimmN(void) __ptr64 */

void __thiscall NvdimmN::~NvdimmN(NvdimmN *this)

{
  *(undefined ***)this = &_vftable_;
  KeCancelTimer(this + 0xe0);
  *(undefined ***)this = &Nvdimm::_vftable_;
  return;
}



===== `vector_deleting_destructor' @ 1c00092b0 =====

/* public: virtual void * __ptr64 __cdecl NvdimmN::`vector deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall NvdimmN::_vector_deleting_destructor_(NvdimmN *this,uint param_1)

{
  ~NvdimmN(this);
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0);
  }
  return this;
}



===== AcknowledgeUnsafeShutdown @ 1c00092f0 =====

/* public: virtual long __cdecl NvdimmN::AcknowledgeUnsafeShutdown(void) __ptr64 */

long __thiscall NvdimmN::AcknowledgeUnsafeShutdown(NvdimmN *this)

{
  uint uVar1;
  char cVar2;
  long lVar3;
  uint uVar4;
  ulong uVar5;
  char *pcVar6;
  ulong local_res10 [6];
  
  cVar2 = KeGetCurrentIrql();
  if (cVar2 == '\0') {
    local_res10[0] = 0;
    lVar3 = NvdQueryDeviceRegistryUlong
                      (*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10),(ushort *)L"",
                       (ushort *)L"UnsafeShutdownCount",local_res10);
    if (lVar3 < 0) {
      local_res10[0] = 0;
    }
    local_res10[0] = local_res10[0] + 1;
    uVar4 = NvdWriteDeviceRegistryUlong
                      (*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10),(ushort *)L"UnsafeShutdownCount",
                       local_res10[0]);
    if ((int)uVar4 < 0) {
      pcVar6 = "NvdimmN::AcknowledgeUnsafeShutdown: failed to query current USC (0x%x)";
      uVar5 = 2;
      uVar1 = uVar4;
    }
    else {
      pcVar6 = "NvdimmN::AcknowledgeUnsafeShutdown: updated baseline USC to %d";
      uVar5 = 4;
      uVar1 = local_res10[0];
    }
    WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10),uVar5,pcVar6,(ulonglong)uVar1);
  }
  else {
    uVar4 = 0xc0000148;
  }
  return uVar4;
}



===== DoDsmDependentInit @ 1c00093a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl NvdimmN::DoDsmDependentInit(enum _NVDIMM_DEVICE_HEALTH_CHECK_REASON)
   __ptr64 */

long __thiscall
NvdimmN::DoDsmDependentInit(NvdimmN *this,_NVDIMM_DEVICE_HEALTH_CHECK_REASON param_1)

{
  _SCMDSM_LAST_BACKUP_INFORMATION *p_Var1;
  _NVDIMM_DEVICE_EXTENSION *p_Var2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined8 in_stack_ffffffffffffff98;
  undefined4 uVar8;
  ulonglong in_stack_ffffffffffffffa0;
  _SCMDSM_ENERGY_SOURCE_IDENTIFICATION *p_Var9;
  
  uVar8 = (undefined4)((ulonglong)in_stack_ffffffffffffff98 >> 0x20);
  uVar4 = 0xc0000001;
  uVar3 = `anonymous_namespace'::GetHealthInfo
                    (*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10),(undefined4 *)(this + 0x20),
                     (undefined8 *)(this + 0x25),(undefined8 *)(this + 0x32));
  if (((param_1 == 2) && (uVar3 != 0xc0000295)) && (uVar3 != 0xc0140018)) {
    (**(code **)(this + 0x18))(*(undefined8 *)(this + 0x10),1);
  }
  p_Var2 = *(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10);
  uVar7 = 0xc0000001;
  if ((int)uVar3 < 0) {
    WriteTraceEvent(p_Var2,3,
                    "NvdnDsmDependentInit: NvdnGetDeviceHealthInfo() failed with status %x. Scheduling deferred health check"
                    ,(ulonglong)uVar3);
    uVar5 = uVar3;
  }
  else {
    in_stack_ffffffffffffffa0 = in_stack_ffffffffffffffa0 & 0xffffffffffff0000;
    uVar8 = 0;
    uVar4 = (**(code **)(p_Var2 + 0x78))
                      (*(undefined8 *)(p_Var2 + 0x58),&GUID_SCM_DSM_0101,1,1,0,
                       in_stack_ffffffffffffffa0,this + 0x80,0x32);
    p_Var2 = *(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10);
    if ((int)uVar4 < 0) {
      WriteTraceEvent(p_Var2,2,"NvdnDsmDependentInit: failed getting NVDIMM-N identification 0x%x\n"
                      ,(ulonglong)uVar4);
      *(undefined8 *)(this + 0x80) = 0;
      *(undefined8 *)(this + 0x88) = 0;
      *(undefined8 *)(this + 0x90) = 0;
      *(undefined8 *)(this + 0x98) = 0;
      *(undefined8 *)(this + 0xa0) = 0;
      *(undefined8 *)(this + 0xa8) = 0;
      *(undefined2 *)(this + 0xb0) = 0;
      uVar5 = uVar4;
    }
    else {
      in_stack_ffffffffffffffa0 = in_stack_ffffffffffffffa0 & 0xffffffffffff0000;
      uVar8 = 0;
      uVar5 = (**(code **)(p_Var2 + 0x78))
                        (*(undefined8 *)(p_Var2 + 0x58),&GUID_SCM_DSM_0101,1,3,0,
                         in_stack_ffffffffffffffa0,this + 0xb2,0x13);
      p_Var2 = *(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10);
      uVar7 = uVar5;
      if ((int)uVar5 < 0) {
        WriteTraceEvent(p_Var2,2,
                        "NvdnDsmDependentInit: failed getting energy source identification 0x%x\n",
                        (ulonglong)uVar5);
        *(undefined8 *)(this + 0xb2) = 0;
        *(undefined8 *)(this + 0xba) = 0;
        *(undefined2 *)(this + 0xc2) = 0;
        this[0xc4] = (NvdimmN)0x0;
      }
      else {
        p_Var1 = (_SCMDSM_LAST_BACKUP_INFORMATION *)(this + 0xc5);
        uVar8 = 0;
        uVar6 = (**(code **)(p_Var2 + 0x78))
                          (*(undefined8 *)(p_Var2 + 0x58),&GUID_SCM_DSM_0101,1,4,0,
                           in_stack_ffffffffffffffa0 & 0xffffffffffff0000,p_Var1,0xc);
        if ((int)uVar6 < 0) {
          WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10),3,
                          "NvdnDsmDependentInit: failed getting last backup info with NTSTATUS 0x%x"
                          ,(ulonglong)uVar6);
          *(undefined8 *)p_Var1 = 0;
          *(undefined4 *)(this + 0xcd) = 0;
        }
        NvdimmNTelemetry::BootStatus
                  (*(NvdimmNTelemetry **)(this + 0x160),*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10),
                   uVar6,p_Var1);
      }
    }
  }
  p_Var9 = (_SCMDSM_ENERGY_SOURCE_IDENTIFICATION *)(this + 0xb2);
  NvdimmNTelemetry::Identification
            (*(NvdimmNTelemetry **)(this + 0x160),*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10),uVar4,
             (_SCMDSM_NVDIMM_IDENTIFICATION *)(this + 0x80),uVar7,p_Var9);
  if ((int)uVar5 < 0) {
    if ((uVar5 != 0xc0000295) && (uVar5 != 0xc0140018)) {
      return uVar5;
    }
    WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10),3,
                    "NvdnDsmDependentInit: Some _DSM dependent routine failed with a retriable error (health: %x, id: %x, energy source: %x). Scheduling deferred init"
                    ,(ulonglong)uVar3,CONCAT44(uVar8,uVar4),
                    CONCAT44((int)((ulonglong)p_Var9 >> 0x20),uVar7));
    ScheduleDeferredDsmInitTimer(this);
  }
  else {
    this[0x45] = (NvdimmN)0x1;
  }
  return 0;
}



===== DownloadFirmwareRegions @ 1c0009650 =====

/* public: virtual long __cdecl NvdimmN::DownloadFirmwareRegions(unsigned char,void *
   __ptr64,unsigned long,unsigned __int64,bool) __ptr64 */

long __thiscall
NvdimmN::DownloadFirmwareRegions
          (NvdimmN *this,uchar param_1,void *param_2,ulong param_3,__uint64 param_4,bool param_5)

{
  _NVDIMMN_FIRMWARE_UPDATE_CONTEXT *p_Var1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  ulonglong uVar5;
  uint uVar6;
  char *pcVar7;
  ulonglong uVar8;
  ushort uVar9;
  uint uVar10;
  
  uVar8 = (ulonglong)param_3;
  uVar4 = 0;
  if ((byte)this[0x8f] <= param_1) {
    WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10),2,
                    "NvdnFirmwareDownloadIoctl: Invalid firmware slot (slot index %d; only %d slots available).\n"
                    ,(ulonglong)(uint)param_1,(uint)(byte)this[0x8f]);
    return -0x3ffffff3;
  }
  uVar6 = *(int *)(this + 0xae) * 0x20;
  iVar3 = (int)((ulonglong)param_3 / (ulonglong)uVar6);
  uVar2 = (ushort)((ulonglong)param_3 / (ulonglong)uVar6);
  if ((iVar3 == 0) || (iVar3 * uVar6 != param_3)) {
    WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10),2,
                    "NvdnDownloadFirmwareImageRegion: chunk is not a multiple of region size (0x%x)"
                   );
    return -0x3ffffff3;
  }
  if (param_4 % (ulonglong)uVar6 != 0) {
    WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10),2,
                    "NvdnDownloadFirmwareImageRegion: offset is not region aligned (0x%x)",param_4);
    return -0x3ffffff3;
  }
  if ((param_4 != 0) && (*(int *)(this + 0xd8) == 0)) {
    pcVar7 = 
    "NvdnDownloadFirmwareImageRegion: RegionOffset isn\'t 0 and this isn\'t the first download command"
    ;
LAB_1c000971b:
    WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10),2,pcVar7);
    return -0x3ffffff3;
  }
  p_Var1 = (_NVDIMMN_FIRMWARE_UPDATE_CONTEXT *)(this + 0xd4);
  if (*(int *)(this + 0xd8) == 0) {
    uVar8 = (ulonglong)(uint)param_1;
    WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10),4,
                    "NvdnDownloadFirmwareImageRegion: starting firmware update for slot %d");
    uVar4 = NvdimmNUtil::StartFirmwareUpdate
                      (*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10),p_Var1,param_1);
    if ((int)uVar4 < 0) {
      WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10),2,
                      "NvdnDownloadFirmwareImageRegion: NvdnStartFirmwareUpdate() failed with 0x%x",
                      (ulonglong)uVar4);
      return uVar4;
    }
  }
  else if ((_NVDIMMN_FIRMWARE_UPDATE_CONTEXT)param_1 != *p_Var1) {
    pcVar7 = "NvdnDownloadFirmwareImageRegion: there is an update in progress for a different slot";
    goto LAB_1c000971b;
  }
  uVar5 = param_4 / uVar6;
  if (uVar5 < 0x10000) {
    uVar10 = 0;
    if (uVar2 != 0) {
      do {
        uVar4 = NvdimmNUtil::SendFirmwareUpdateData
                          (*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10),p_Var1,
                           (short)uVar10 + (short)uVar5,(uchar)uVar8,uVar6,
                           (void *)((ulonglong)(uVar10 * uVar6) + (longlong)param_2));
        if ((int)uVar4 < 0) {
          WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10),2,
                          "NvdnDownloadFirmwareImageRegion: NvdnSendFirmwareUpdateData() failed with 0x%x"
                          ,uVar5);
          goto LAB_1c0009832;
        }
        uVar9 = (short)uVar10 + 1;
        uVar10 = (uint)uVar9;
      } while (uVar9 < uVar2);
    }
    if (!param_5) {
      return uVar4;
    }
  }
  else {
    WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10),2,
                    "NvdnDownloadFirmwareImageRegion: startingRegion is too large: 0x%x",uVar5);
    uVar4 = 0xc000000d;
  }
LAB_1c0009832:
  WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10),4,
                  "NvdnDownloadFirmwareImageRegion: finishing firmware update");
  uVar6 = NvdimmNUtil::FinishFirmwareUpdate(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10),p_Var1);
  if ((int)uVar6 < 0) {
    WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10),2,
                    "NvdnDownloadFirmwareImageRegion: NvdnFinishFirmwareUpdate() failed with 0x%x",
                    (ulonglong)uVar4);
  }
  if (-1 < (int)uVar4) {
    uVar4 = uVar6;
  }
  return uVar4;
}



===== GetCurrentFirmwareRevision @ 1c00098e0 =====

/* public: virtual long __cdecl NvdimmN::GetCurrentFirmwareRevision(char * __ptr64 const) __ptr64 */

long __thiscall NvdimmN::GetCurrentFirmwareRevision(NvdimmN *this,char *param_1)

{
  long lVar1;
  
  lVar1 = RtlStringCchPrintfA(param_1,0x20,"%u",(ulonglong)*(ushort *)(this + 0x8c));
  return lVar1;
}



===== GetDeviceName @ 1c0009910 =====

/* public: virtual long __cdecl NvdimmN::GetDeviceName(unsigned short * __ptr64,unsigned long)
   __ptr64 */

long __thiscall NvdimmN::GetDeviceName(NvdimmN *this,ushort *param_1,ulong param_2)

{
  long lVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  
  if (*(short *)(*(longlong *)(this + 0x10) + 0x148) == 0) {
    pwVar2 = L"";
    pwVar3 = L"";
  }
  else {
    pwVar3 = *(wchar_t **)(*(longlong *)(this + 0x10) + 0x150);
    pwVar2 = L" ";
  }
  lVar1 = RtlStringCbPrintfW(param_1,param_2,(ushort *)L"%ws%wsNVDIMM-N device",pwVar3,pwVar2);
  return lVar1;
}



===== GetDeviceSpecificInfo @ 1c0009970 =====

/* public: virtual long __cdecl NvdimmN::GetDeviceSpecificInfo(class wistd::unique_ptr<struct
   _SCM_PD_DEVICE_SPECIFIC_INFO,struct wistd::default_delete<struct _SCM_PD_DEVICE_SPECIFIC_INFO> >
   * __ptr64) __ptr64 */

long __thiscall
NvdimmN::GetDeviceSpecificInfo
          (NvdimmN *this,
          unique_ptr<_SCM_PD_DEVICE_SPECIFIC_INFO,wistd::default_delete<_SCM_PD_DEVICE_SPECIFIC_INFO>_>
          *param_1)

{
  NvdimmN NVar1;
  short sVar2;
  ushort uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined8 uVar6;
  short *psVar7;
  short *psVar8;
  longlong lVar9;
  int iVar10;
  int iVar11;
  long lVar12;
  longlong lVar13;
  longlong lVar14;
  
  lVar12 = 0;
  KeWaitForSingleObject(this + 0x48,0,0,0,0);
  iVar4 = *(int *)(this + 0x32);
  iVar11 = (-(uint)(iVar4 != 0) & 0xfffffffe) + 4;
  iVar10 = iVar11 * 0x108 + 0x10;
  uVar6 = ExAllocatePool2(0x100,iVar10,0x7370764e);
  lVar9 = *(longlong *)param_1;
  *(undefined8 *)param_1 = uVar6;
  if (lVar9 != 0) {
    ExFreePoolWithTag(lVar9,0);
  }
  puVar5 = *(undefined4 **)param_1;
  if (puVar5 == (undefined4 *)0x0) {
    lVar12 = -0x3fffff66;
  }
  else {
    puVar5[1] = iVar10;
    psVar8 = (short *)(puVar5 + 4);
    *puVar5 = 0x118;
    NVar1 = this[0x2f];
    lVar9 = 0x80;
    lVar14 = (longlong)L"Media lifetime remaining %" - (longlong)psVar8;
    lVar13 = 0x80;
    do {
      if ((lVar13 == -0x7fffff7e) || (sVar2 = *(short *)(lVar14 + (longlong)psVar8), sVar2 == 0))
      break;
      *psVar8 = sVar2;
      psVar8 = psVar8 + 1;
      lVar13 = lVar13 + -1;
    } while (lVar13 != 0);
    lVar14 = 0x80;
    psVar7 = psVar8 + -1;
    if (lVar13 != 0) {
      psVar7 = psVar8;
    }
    *psVar7 = 0;
    *(ulonglong *)(puVar5 + 0x44) = (ulonglong)(byte)NVar1;
    psVar8 = (short *)(puVar5 + 0x46);
    uVar3 = *(ushort *)(this + 0x2b);
    lVar13 = (longlong)L"Media temperature in C" - (longlong)psVar8;
    do {
      if ((lVar14 == -0x7fffff7e) || (sVar2 = *(short *)(lVar13 + (longlong)psVar8), sVar2 == 0))
      break;
      *psVar8 = sVar2;
      psVar8 = psVar8 + 1;
      lVar14 = lVar14 + -1;
    } while (lVar14 != 0);
    psVar7 = psVar8 + -1;
    if (lVar14 != 0) {
      psVar7 = psVar8;
    }
    *psVar7 = 0;
    *(ulonglong *)(puVar5 + 0x86) = (ulonglong)uVar3;
    if (iVar4 == 0) {
      NVar1 = this[0x36];
      psVar8 = (short *)(puVar5 + 0x88);
      lVar14 = (longlong)L"Energy source lifetime remaining %" - (longlong)psVar8;
      lVar13 = 0x80;
      do {
        if ((lVar13 == -0x7fffff7e) || (sVar2 = *(short *)(lVar14 + (longlong)psVar8), sVar2 == 0))
        break;
        *psVar8 = sVar2;
        psVar8 = psVar8 + 1;
        lVar13 = lVar13 + -1;
      } while (lVar13 != 0);
      psVar7 = psVar8 + -1;
      if (lVar13 != 0) {
        psVar7 = psVar8;
      }
      *psVar7 = 0;
      *(ulonglong *)(puVar5 + 200) = (ulonglong)(byte)NVar1;
      uVar3 = *(ushort *)(this + 0x37);
      if (uVar3 == 0xffff) {
        iVar11 = 3;
      }
      else {
        psVar8 = (short *)(puVar5 + 0xca);
        lVar13 = (longlong)L"Energy source temperature in C" - (longlong)psVar8;
        do {
          if ((lVar9 == -0x7fffff7e) || (sVar2 = *(short *)(lVar13 + (longlong)psVar8), sVar2 == 0))
          break;
          *psVar8 = sVar2;
          psVar8 = psVar8 + 1;
          lVar9 = lVar9 + -1;
        } while (lVar9 != 0);
        psVar7 = psVar8 + -1;
        if (lVar9 != 0) {
          psVar7 = psVar8;
        }
        *psVar7 = 0;
        *(ulonglong *)(puVar5 + 0x10a) = (ulonglong)(uVar3 >> 4);
      }
    }
    puVar5[2] = iVar11;
  }
  KeReleaseMutex(this + 0x48,0);
  return lVar12;
}



===== GetFirmwareInfo @ 1c0009bd0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl NvdimmN::GetFirmwareInfo(class wistd::unique_ptr<struct
   _SCM_PD_FIRMWARE_INFO,struct wistd::default_delete<struct _SCM_PD_FIRMWARE_INFO> > *
   __ptr64,unsigned char * __ptr64,unsigned long * __ptr64,unsigned long * __ptr64) __ptr64 */

long __thiscall
NvdimmN::GetFirmwareInfo
          (NvdimmN *this,
          unique_ptr<_SCM_PD_FIRMWARE_INFO,wistd::default_delete<_SCM_PD_FIRMWARE_INFO>_> *param_1,
          uchar *param_2,ulong *param_3,ulong *param_4)

{
  NvdimmN NVar1;
  byte bVar2;
  longlong lVar3;
  undefined4 *puVar4;
  char cVar5;
  long lVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  byte bVar9;
  byte bVar10;
  int iVar11;
  byte local_res8 [8];
  short local_res10;
  undefined2 uStackX_12;
  ushort uStackX_14;
  
  if ((ulonglong)(byte)this[0x8f] * 0x30 + 0xc < 0x3d) {
    iVar11 = 0x3c;
  }
  else {
    iVar11 = (uint)(byte)this[0x8f] * 0x30 + 0xc;
  }
  uVar7 = ExAllocatePool2(0x40,iVar11,0x7766764e);
  lVar3 = *(longlong *)param_1;
  *(undefined8 *)param_1 = uVar7;
  if (lVar3 != 0) {
    ExFreePoolWithTag(lVar3,0);
  }
  puVar4 = *(undefined4 **)param_1;
  if (puVar4 == (undefined4 *)0x0) {
    lVar6 = -0x3fffff66;
  }
  else {
    *puVar4 = 0x3c;
    puVar4[1] = iVar11;
    *(NvdimmN *)(puVar4 + 2) = this[0x8e];
    NVar1 = this[0x8f];
    *(NvdimmN *)((longlong)puVar4 + 10) = NVar1;
    if (this[0xd5] == (NvdimmN)0x0) {
      cVar5 = -1;
    }
    else {
      cVar5 = (char)this[0xd5] + -1;
    }
    *(char *)((longlong)puVar4 + 9) = cVar5;
    bVar10 = 0;
    if (NVar1 != (NvdimmN)0x0) {
      do {
        uVar8 = (ulonglong)bVar10;
        bVar2 = *(byte *)((longlong)puVar4 + uVar8 * 0x30 + 0x15);
        puVar4[uVar8 * 0xc + 3] = 0x30;
        puVar4[uVar8 * 0xc + 4] = 0x30;
        *(byte *)(puVar4 + uVar8 * 0xc + 5) = bVar10;
        bVar9 = bVar2 | 1;
        if (bVar10 != 0) {
          bVar9 = bVar2 & 0xfe;
        }
        *(byte *)((longlong)puVar4 + uVar8 * 0x30 + 0x15) = bVar9;
        local_res10 = 0;
        uStackX_12 = 0;
        uStackX_14 = 0;
        local_res8[0] = bVar10;
        iVar11 = (**(code **)(*(longlong *)(this + 0x10) + 0x78))
                           (*(undefined8 *)(*(longlong *)(this + 0x10) + 0x58),&GUID_SCM_DSM_0101,1,
                            0x1a,local_res8,1,&local_res10,6);
        if (iVar11 < 0) {
          return iVar11;
        }
        if (CONCAT22(uStackX_12,local_res10) == 0) {
          iVar11 = RtlStringCchPrintfA((char *)(puVar4 + uVar8 * 0xc + 7),0x20,"%u",
                                       (ulonglong)uStackX_14);
        }
        else if (local_res10 == 1) {
          iVar11 = -0x3fffff45;
        }
        else {
          iVar11 = -0x3fffffff;
          if (local_res10 == 2) {
            iVar11 = -0x3ffffff3;
          }
        }
        if (iVar11 < 0) {
          return iVar11;
        }
        bVar10 = bVar10 + 1;
      } while (bVar10 < *(byte *)((longlong)puVar4 + 10));
    }
    if (param_2 != (uchar *)0x0) {
      *param_2 = '\x01';
    }
    if (param_3 != (ulong *)0x0) {
      *param_3 = *(int *)(this + 0xae) << 5;
    }
    if (param_4 != (ulong *)0x0) {
      *param_4 = 0;
    }
    lVar6 = 0;
  }
  return lVar6;
}



===== GetHealthInfo @ 1c0009df4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint `anonymous_namespace'::GetHealthInfo
               (_NVDIMM_DEVICE_EXTENSION *param_1,undefined4 *param_2,undefined8 *param_3,
               undefined8 *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_c8 [32];
  undefined8 local_a8;
  undefined2 local_a0;
  int *local_98;
  undefined2 local_90;
  int local_78;
  undefined1 local_74;
  short local_70;
  undefined2 uStack_6e;
  undefined4 uStack_6c;
  undefined2 uStack_68;
  undefined2 uStack_66;
  undefined1 local_64;
  undefined2 local_60;
  undefined2 uStack_5e;
  undefined4 uStack_5c;
  undefined2 uStack_58;
  undefined1 local_56;
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStack_c8;
  if (*(int *)(param_1 + 0x1ec) != 0) {
    if (*(int *)(param_1 + 0x1f0) == 0) {
      WriteTraceEvent(param_1,2,
                      "ShouldHealthCheckFail: Failing health check with fatal error because of registry"
                     );
      *(int *)(param_1 + 0x1ec) = *(int *)(param_1 + 0x1ec) + -1;
      return 0xc0000183;
    }
    *(int *)(param_1 + 0x1f0) = *(int *)(param_1 + 0x1f0) + -1;
  }
  if (*(int *)(param_1 + 0x1e8) == 0) {
    local_90 = 5;
    local_74 = 0;
    local_98 = &local_78;
    local_78 = 0;
    local_a0 = 0;
    local_a8 = 0;
    uVar1 = (**(code **)(param_1 + 0x78))(*(undefined8 *)(param_1 + 0x58),&GUID_SCM_DSM_0101,1,10);
    if (((int)uVar1 < 0) || (local_78 != 0)) {
      local_a8 = CONCAT44(local_a8._4_4_,local_78);
      WriteTraceEvent(param_1,2,
                      "NvdnGetHealthInfo: Failed to call ScmDsmGetCriticalHealthInfo with NTSTATUS 0x%x and DSM status 0x%x"
                      ,(ulonglong)uVar1);
    }
    else {
      *param_2 = 0;
      *(undefined1 *)(param_2 + 1) = local_74;
    }
    local_90 = 0xd;
    uStack_6e = 0;
    uStack_6c = 0;
    uStack_68 = 0;
    local_98 = (int *)&local_70;
    uStack_66 = 0;
    local_64 = 0;
    local_a0 = 0;
    local_70 = 0;
    local_a8 = 0;
    uVar2 = (**(code **)(param_1 + 0x78))(*(undefined8 *)(param_1 + 0x58),&GUID_SCM_DSM_0101,1);
    if (((int)uVar2 < 0) || (CONCAT22(uStack_6e,local_70) != 0)) {
      local_a8 = CONCAT44(local_a8._4_4_,CONCAT22(uStack_6e,local_70));
      WriteTraceEvent(param_1,2,
                      "NvdnGetHealthInfo: Failed to call ScmDsmGetNvdimmHealthInfo with NTSTATUS 0x%x and DSM status 0x%x"
                      ,(ulonglong)uVar2);
    }
    else {
      *param_3 = CONCAT44(uStack_6c,CONCAT22(uStack_6e,local_70));
      *(uint *)(param_3 + 1) = CONCAT22(uStack_66,uStack_68);
      *(undefined1 *)((longlong)param_3 + 0xc) = local_64;
    }
    local_90 = 0xb;
    local_98 = (int *)&local_60;
    uStack_5e = 0;
    uStack_5c = 0;
    uStack_58 = 0;
    local_56 = 0;
    local_a0 = 0;
    local_a8 = 0;
    local_60 = 0;
    uVar3 = (**(code **)(param_1 + 0x78))(*(undefined8 *)(param_1 + 0x58),&GUID_SCM_DSM_0101,1,0xc);
    if (((int)uVar3 < 0) || (CONCAT22(uStack_5e,local_60) != 0)) {
      local_a8 = CONCAT44(local_a8._4_4_,CONCAT22(uStack_5e,local_60));
      WriteTraceEvent(param_1,2,
                      "NvdnGetHealthInfo: Failed to call ScmDsmGetEnergySourceHealthInfo with NTSTATUS 0x%x and DSM status 0x%x"
                      ,(ulonglong)uVar3);
    }
    else {
      *param_4 = CONCAT44(uStack_5c,CONCAT22(uStack_5e,local_60));
      *(undefined2 *)(param_4 + 1) = uStack_58;
      *(undefined1 *)((longlong)param_4 + 10) = local_56;
    }
    if (-1 < (int)uVar1) {
      if (local_78 == 0) {
        uVar1 = 0;
      }
      else if ((short)local_78 == 1) {
        uVar1 = 0xc00000bb;
      }
      else {
        uVar1 = 0xc0000001;
        if ((short)local_78 == 2) {
          uVar1 = 0xc000000d;
        }
      }
    }
    if (-1 < (int)uVar2) {
      if (CONCAT22(uStack_6e,local_70) == 0) {
        uVar2 = 0;
      }
      else if (local_70 == 1) {
        uVar2 = 0xc00000bb;
      }
      else {
        uVar2 = 0xc0000001;
        if (local_70 == 2) {
          uVar2 = 0xc000000d;
        }
      }
    }
    if ((int)uVar1 < 0) {
      uVar2 = uVar1;
    }
  }
  else {
    *(int *)(param_1 + 0x1e8) = *(int *)(param_1 + 0x1e8) + -1;
    WriteTraceEvent(param_1,2,
                    "ShouldHealthCheckFail: Failing health check because of registry; %d more failures still"
                   );
    uVar2 = 0xc0000295;
  }
  return uVar2;
}



===== GetOperationalStatus @ 1c000a0b0 =====

/* public: virtual long __cdecl NvdimmN::GetOperationalStatus(unsigned long,bool * __ptr64
   const,unsigned long,bool * __ptr64 const) __ptr64 */

long __thiscall
NvdimmN::GetOperationalStatus(NvdimmN *this,ulong param_1,bool *param_2,ulong param_3,bool *param_4)

{
  bool *pbVar1;
  int iVar2;
  long lVar3;
  NvdimmN *pNVar4;
  
  if ((param_1 < 8) || (param_3 < 0x17)) {
    lVar3 = -0x3ffffff3;
  }
  else {
    memset(param_2,0,(ulonglong)param_1);
    memset(param_4,0,(ulonglong)param_3);
    KeWaitForSingleObject(this + 0x48,0,0,0,0);
    if (((byte)this[0x24] & 1) != 0) {
      param_4[0xc] = true;
    }
    if (((byte)this[0x2a] & 0x10) != 0) {
      param_4[5] = true;
      param_2[5] = true;
    }
    pNVar4 = this + 0x29;
    pbVar1 = param_2 + 4;
    if (((byte)*pNVar4 & 0x20) != 0) {
      param_4[6] = true;
      *pbVar1 = true;
    }
    if (((byte)*pNVar4 & 0x40) != 0) {
      param_4[7] = true;
      *pbVar1 = true;
    }
    if (((byte)*pNVar4 & 1) != 0) {
      param_4[8] = true;
      *pbVar1 = true;
    }
    pNVar4 = this + 0x29;
    if (((byte)*pNVar4 & 0xe) != 0) {
      param_4[8] = true;
      *pbVar1 = true;
    }
    if ((char)*pNVar4 < '\0') {
      param_4[2] = true;
      param_2[4] = true;
    }
    pbVar1 = param_2 + 6;
    if (((byte)this[0x2a] & 4) != 0) {
      param_4[5] = true;
      *pbVar1 = true;
    }
    if (((byte)*pNVar4 & 0x10) != 0) {
      param_4[8] = true;
      *pbVar1 = true;
    }
    if (((byte)this[0x2a] & 0x40) != 0) {
      param_4[9] = true;
      *pbVar1 = true;
    }
    if (((byte)this[0x2a] & 0x20) != 0) {
      param_4[4] = true;
      *pbVar1 = true;
    }
    if (((byte)this[0x2d] & 6) != 0) {
      param_4[2] = true;
      param_2[6] = true;
    }
    if ((*(uint *)(*(longlong *)(this + 0x10) + 0xe8) & 0x10) != 0) {
      param_4[3] = true;
      param_2[6] = true;
    }
    iVar2 = *(int *)(this + 0x40);
    if (((iVar2 < 0) && (iVar2 != -0x3ffffd6b)) && (iVar2 != -0x3febffe8)) {
      param_4[0xb] = true;
      param_2[6] = true;
    }
    if (*(char *)(*(longlong *)(this + 0x10) + 0xe2) != '\0') {
      param_4[0xc] = true;
      param_2[6] = true;
    }
    if (((byte)this[0x2e] & 7) != 0) {
      param_4[0x11] = true;
      param_4[2] = true;
      param_2[2] = true;
    }
    if (((((byte)this[0x24] & 1) != 0) && (param_2[6] == false)) && (param_2[4] == false)) {
      param_2[6] = true;
    }
    KeReleaseMutex(this + 0x48,0);
    lVar3 = 0;
  }
  return lVar3;
}



===== GetUnsafeShutdownCount @ 1c000a2a0 =====

/* public: virtual long __cdecl NvdimmN::GetUnsafeShutdownCount(unsigned long * __ptr64) __ptr64 */

long __thiscall NvdimmN::GetUnsafeShutdownCount(NvdimmN *this,ulong *param_1)

{
  char cVar1;
  long lVar2;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 == '\0') {
    lVar2 = NvdQueryDeviceRegistryUlong
                      (*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10),(ushort *)L"",
                       (ushort *)L"UnsafeShutdownCount",param_1);
    if (lVar2 < 0) {
      *param_1 = 0;
    }
    lVar2 = 0;
  }
  else {
    lVar2 = -0x3ffffeb8;
  }
  return lVar2;
}



===== HandleDeviceHealthErrors @ 1c000a2fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl NvdimmN::HandleDeviceHealthErrors(enum _NVDIMM_DEVICE_HEALTH_CHECK_REASON)
   __ptr64 */

void __thiscall
NvdimmN::HandleDeviceHealthErrors(NvdimmN *this,_NVDIMM_DEVICE_HEALTH_CHECK_REASON param_1)

{
  NvdimmN NVar1;
  NvdimmN NVar2;
  NvdimmN NVar3;
  NvdimmN NVar4;
  NvdimmN NVar5;
  undefined4 uVar6;
  int iVar7;
  longlong lVar8;
  longlong lVar9;
  bool bVar10;
  uint uVar11;
  undefined8 uVar12;
  __uint64 _Var13;
  _NVDIMM_DEVICE_EXTENSION *p_Var14;
  char cVar15;
  NvdimmN *pNVar16;
  undefined1 auStackY_238 [32];
  uchar local_e8;
  ulong local_e4;
  char local_e0;
  NvdimmN local_df;
  uint local_dc;
  uint local_d8;
  uint local_d4;
  uint local_d0;
  uint local_cc;
  uint local_c8;
  uint local_c4;
  uint local_c0;
  uint local_bc;
  uint local_b8;
  uint local_b4;
  uint local_b0;
  uint local_ac;
  uint local_a8;
  uint local_a4;
  uint local_a0;
  NvdimmN *local_98;
  _NVDIMM_DEVICE_EXTENSION *local_90;
  _NVDIMM_DEVICE_HEALTH_CHECK_REASON local_88;
  _NVDIMM_DEVICE_EXTENSION *local_80;
  __uint64 local_78;
  undefined1 local_70;
  undefined8 local_6f;
  undefined8 uStack_67;
  undefined8 local_5f;
  undefined2 local_57;
  undefined1 local_55;
  undefined8 local_50;
  undefined8 uStack_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_238;
  local_78 = 0;
  local_df = this[0x44];
  lVar8 = *(longlong *)(this + 0x10);
  local_e8 = '\0';
  local_50 = 0;
  uStack_48 = 0;
  p_Var14 = *(_NVDIMM_DEVICE_EXTENSION **)(lVar8 + 0x1b0);
  local_98 = this;
  local_88 = param_1;
  local_80 = p_Var14;
  if ((param_1 & 0xfffffffd) == 0) {
    if (((*(char *)(lVar8 + 0xe0) == '\0') && (*(char *)(lVar8 + 0xe1) == '\0')) &&
       (*(char *)(lVar8 + 0xe3) == '\0')) {
      bVar10 = false;
    }
    else {
      bVar10 = true;
    }
    uVar6 = *(undefined4 *)(this + 0xcd);
    if (bVar10) {
      if ((Microsoft_Windows_PersistentMemory_NvdimmEnableBits & 4) != 0) {
        McTemplateK0jdqsssztttti_EtwWriteTransfer
                  ((ulonglong)*(byte *)(lVar8 + 0xe3),&EventBootTimeOperationFailed,&local_50,
                   lVar8 + 400,(char)*(undefined4 *)(lVar8 + 0x20),
                   (char)*(undefined4 *)(lVar8 + 0x134),*(char **)(lVar8 + 0x178),
                   *(char **)(lVar8 + 0x180),*(char **)(lVar8 + 0x188),*(wchar_t **)(lVar8 + 0x140),
                   *(char *)(lVar8 + 0xe0),*(undefined1 *)(lVar8 + 0xe1),*(byte *)(lVar8 + 0xe3),
                   *(undefined1 *)(lVar8 + 0xe2),(char)uVar6);
      }
      local_e4 = 0;
      uVar11 = NvdGetLogicalDeviceCount(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10),&local_e4);
      if ((int)uVar11 < 0) {
        WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10),2,
                        "NvdimmN::HandleDeviceHealthErrors(): NvdGetLogicalDeviceCount() failed with NTSTATUS 0x%x"
                        ,(ulonglong)uVar11);
        local_e4 = 1;
      }
      lVar9 = *(longlong *)(this + 0x10);
      if (local_e4 == 0) {
        *(uint *)(lVar9 + 0xe8) = *(uint *)(lVar9 + 0xe8) & 0xffffffef;
        WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10),4,
                        "INvdimm::HandleDataLossFailures(): Unsafe shutdown ignored because NVDIMM 0x%x has no logical device created"
                        ,(ulonglong)*(uint *)(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10) + 0x20));
      }
      else {
        *(uint *)(lVar9 + 0xe8) = *(uint *)(lVar9 + 0xe8) | 0x10;
      }
    }
    p_Var14 = (_NVDIMM_DEVICE_EXTENSION *)0x0;
    if ((*(char *)(lVar8 + 0xe2) != '\0') &&
       ((Microsoft_Windows_PersistentMemory_NvdimmEnableBits & 4) != 0)) {
      lVar9 = *(longlong *)(this + 0x10);
      p_Var14 = (_NVDIMM_DEVICE_EXTENSION *)(ulonglong)*(byte *)(lVar8 + 0xe3);
      McTemplateK0jdqsssztttti_EtwWriteTransfer
                (p_Var14,&EventArmFailed,&local_50,lVar9 + 400,(char)*(undefined4 *)(lVar9 + 0x20),
                 (char)*(undefined4 *)(lVar9 + 0x134),*(char **)(lVar9 + 0x178),
                 *(char **)(lVar9 + 0x180),*(char **)(lVar9 + 0x188),*(wchar_t **)(lVar9 + 0x140),
                 *(undefined1 *)(lVar8 + 0xe0),*(undefined1 *)(lVar8 + 0xe1),*(byte *)(lVar8 + 0xe3)
                 ,*(char *)(lVar8 + 0xe2),(char)uVar6);
    }
  }
  NVar1 = this[0x24];
  cVar15 = '\0';
  NVar2 = this[0x44];
  p_Var14 = (_NVDIMM_DEVICE_EXTENSION *)CONCAT71((int7)((ulonglong)p_Var14 >> 8),NVar2);
  local_e0 = '\0';
  if (((byte)NVar1 & 1) == 0) {
    if (NVar2 != (NvdimmN)0x0) {
      if ((Microsoft_Windows_PersistentMemory_NvdimmEnableBits & 2) != 0) {
        NVar2 = this[0x2a];
        NVar3 = this[0x29];
        NVar4 = this[0x2e];
        NVar5 = this[0x2d];
        local_90 = *(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10);
        local_a0 = (uint)(byte)this[0x31];
        local_a4 = (uint)(byte)this[0x30];
        local_a8 = (uint)(byte)this[0x2f];
        local_ac = (byte)NVar4 >> 2 & 1;
        local_b4 = (byte)NVar4 & 1;
        local_b0 = (byte)NVar4 >> 1 & 1;
        local_b8 = (byte)NVar5 >> 2 & 1;
        local_c0 = (byte)NVar5 & 1;
        local_bc = (byte)NVar5 >> 1 & 1;
        local_c4 = (uint)*(ushort *)(this + 0x2b);
        local_c8 = (byte)NVar2 >> 6 & 1;
        local_cc = (byte)NVar2 >> 5 & 1;
        local_d0 = (byte)NVar2 >> 4 & 1;
        local_d8 = (byte)NVar2 & 1;
        local_d4 = (byte)NVar2 >> 3 & 1;
        local_dc = (byte)NVar3 & 1;
        local_e4 = (byte)NVar1 & 1;
        McTemplateK0jdqsssztttttttttttttttttttqttttttqqqdd_EtwWriteTransfer
                  (local_90,&Event_NvdimmN_RegainedPersistenceGuarantee,&local_50,local_90 + 400,
                   (char)*(undefined4 *)(local_90 + 0x20),(char)*(undefined4 *)(local_90 + 0x134),
                   *(char **)(local_90 + 0x178),*(char **)(local_90 + 0x180),
                   *(char **)(local_90 + 0x188),*(wchar_t **)(local_90 + 0x140),(char)local_e4,
                   (byte)NVar1 >> 1 & 1,(byte)NVar1 >> 2 & 1,(byte)NVar1 >> 3 & 1,(byte)NVar3 & 1,
                   (byte)NVar3 >> 1 & 1,(byte)NVar3 >> 2 & 1,(byte)NVar3 >> 3 & 1,
                   (byte)NVar3 >> 4 & 1,(byte)NVar3 >> 5 & 1,(byte)NVar3 >> 6 & 1,(byte)NVar3 >> 7,
                   (char)local_d8,(byte)NVar2 >> 1 & 1,(byte)NVar2 >> 2 & 1,(char)local_d4,
                   (char)local_d0,(char)local_cc,(char)local_c8,(char)*(ushort *)(this + 0x2b),
                   (char)local_c0,(char)local_bc,(char)local_b8,(char)local_b4,(char)local_b0,
                   (char)local_ac,this[0x2f],this[0x30],this[0x31],
                   (char)*(undefined4 *)(local_98 + 0xc9),(char)*(undefined4 *)(local_98 + 0xcd));
        this = local_98;
      }
      cVar15 = local_e0;
      p_Var14 = *(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10);
      WriteTraceEvent(p_Var14,3,"NvdnHandleDeviceHealthErrors: regained persistence");
      local_e8 = '\x01';
    }
    p_Var14 = (_NVDIMM_DEVICE_EXTENSION *)((ulonglong)p_Var14 & 0xffffffffffffff00);
  }
  else {
    cVar15 = '\0';
    if (NVar2 == (NvdimmN)0x0) {
      if ((Microsoft_Windows_PersistentMemory_NvdimmEnableBits & 1) != 0) {
        NVar2 = this[0x2a];
        NVar3 = this[0x29];
        NVar4 = this[0x2e];
        NVar5 = this[0x2d];
        local_90 = *(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10);
        local_dc = (uint)(byte)this[0x31];
        local_d8 = (uint)(byte)this[0x30];
        local_d4 = (uint)(byte)this[0x2f];
        local_d0 = (byte)NVar4 >> 2 & 1;
        local_c8 = (byte)NVar4 & 1;
        local_cc = (byte)NVar4 >> 1 & 1;
        local_c4 = (byte)NVar5 >> 2 & 1;
        local_bc = (byte)NVar5 & 1;
        local_c0 = (byte)NVar5 >> 1 & 1;
        local_b8 = (uint)*(ushort *)(this + 0x2b);
        local_b4 = (byte)NVar2 >> 6 & 1;
        local_b0 = (byte)NVar2 >> 5 & 1;
        local_ac = (byte)NVar2 >> 4 & 1;
        local_a4 = (byte)NVar2 & 1;
        local_a8 = (byte)NVar2 >> 3 & 1;
        local_a0 = (byte)NVar3 & 1;
        local_e4 = (byte)NVar1 & 1;
        McTemplateK0jdqsssztttttttttttttttttttqttttttqqqdd_EtwWriteTransfer
                  (local_90,&Event_NvdimmN_LostPersistenceGuarantee,&local_50,local_90 + 400,
                   (char)*(undefined4 *)(local_90 + 0x20),(char)*(undefined4 *)(local_90 + 0x134),
                   *(char **)(local_90 + 0x178),*(char **)(local_90 + 0x180),
                   *(char **)(local_90 + 0x188),*(wchar_t **)(local_90 + 0x140),(char)local_e4,
                   (byte)NVar1 >> 1 & 1,(byte)NVar1 >> 2 & 1,(byte)NVar1 >> 3 & 1,(byte)NVar3 & 1,
                   (byte)NVar3 >> 1 & 1,(byte)NVar3 >> 2 & 1,(byte)NVar3 >> 3 & 1,
                   (byte)NVar3 >> 4 & 1,(byte)NVar3 >> 5 & 1,(byte)NVar3 >> 6 & 1,(byte)NVar3 >> 7,
                   (char)local_a4,(byte)NVar2 >> 1 & 1,(byte)NVar2 >> 2 & 1,(char)local_a8,
                   (char)local_ac,(char)local_b0,(char)local_b4,(char)*(ushort *)(this + 0x2b),
                   (char)local_bc,(char)local_c0,(char)local_c4,(char)local_c8,(char)local_cc,
                   (char)local_d0,this[0x2f],this[0x30],this[0x31],
                   (char)*(undefined4 *)(local_98 + 0xc9),(char)*(undefined4 *)(local_98 + 0xcd));
        this = local_98;
      }
      p_Var14 = *(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10);
      WriteTraceEvent(p_Var14,1,"NvdnHandleDeviceHealthErrors: lost persistence");
      cVar15 = '\x01';
      local_e8 = '\x01';
    }
    p_Var14 = (_NVDIMM_DEVICE_EXTENSION *)CONCAT71((int7)((ulonglong)p_Var14 >> 8),1);
  }
  this[0x44] = SUB81(p_Var14,0);
  iVar7 = *(int *)(this + 0x40);
  if (((iVar7 < 0) && (iVar7 != -0x3ffffd6b)) && (iVar7 != -0x3febffe8)) {
    if ((Microsoft_Windows_PersistentMemory_NvdimmEnableBits & 1) != 0) {
      lVar8 = *(longlong *)(this + 0x10);
      McTemplateK0jdqssszq_EtwWriteTransfer
                (lVar8,&EventHealthCheckFailed,&local_50,lVar8 + 400,
                 (char)*(undefined4 *)(lVar8 + 0x20),(char)*(undefined4 *)(lVar8 + 0x134),
                 *(char **)(lVar8 + 0x178),*(char **)(lVar8 + 0x180),*(char **)(lVar8 + 0x188),
                 *(wchar_t **)(lVar8 + 0x140),(char)iVar7);
    }
    p_Var14 = *(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10);
    WriteTraceEvent(p_Var14,2,
                    "NvdnHandleDeviceHealthCheckFailure: putting the disk in read only mode (status = 0x%x)"
                    ,(ulonglong)*(uint *)(this + 0x40));
  }
  NVar1 = this[0x24];
  if (((byte)NVar1 & 2) != 0) {
    if ((Microsoft_Windows_PersistentMemory_NvdimmEnableBits & 8) != 0) {
      NVar2 = this[0x2a];
      NVar3 = this[0x29];
      NVar4 = this[0x2e];
      NVar5 = this[0x2d];
      p_Var14 = *(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10);
      local_a0 = (uint)(byte)this[0x31];
      local_a4 = (uint)(byte)this[0x30];
      local_a8 = (uint)(byte)this[0x2f];
      local_ac = (byte)NVar4 >> 2 & 1;
      local_b4 = (byte)NVar4 & 1;
      local_b0 = (byte)NVar4 >> 1 & 1;
      local_b8 = (byte)NVar5 >> 2 & 1;
      local_c0 = (byte)NVar5 & 1;
      local_bc = (byte)NVar5 >> 1 & 1;
      local_c4 = (uint)*(ushort *)(this + 0x2b);
      local_c8 = (byte)NVar2 >> 6 & 1;
      local_cc = (byte)NVar2 >> 5 & 1;
      local_d0 = (byte)NVar2 >> 4 & 1;
      local_d8 = (byte)NVar2 & 1;
      local_d4 = (byte)NVar2 >> 3 & 1;
      local_dc = (byte)NVar3 & 1;
      local_e4 = (byte)NVar1 & 1;
      local_90 = p_Var14;
      McTemplateK0jdqsssztttttttttttttttttttqttttttqqqdd_EtwWriteTransfer
                (p_Var14,&Event_NvdimmN_HealthWarning,&local_50,p_Var14 + 400,
                 (char)*(undefined4 *)(p_Var14 + 0x20),(char)*(undefined4 *)(p_Var14 + 0x134),
                 *(char **)(p_Var14 + 0x178),*(char **)(p_Var14 + 0x180),*(char **)(p_Var14 + 0x188)
                 ,*(wchar_t **)(p_Var14 + 0x140),(char)local_e4,(byte)NVar1 >> 1 & 1,
                 (byte)NVar1 >> 2 & 1,(byte)NVar1 >> 3 & 1,(byte)NVar3 & 1,(byte)NVar3 >> 1 & 1,
                 (byte)NVar3 >> 2 & 1,(byte)NVar3 >> 3 & 1,(byte)NVar3 >> 4 & 1,(byte)NVar3 >> 5 & 1
                 ,(byte)NVar3 >> 6 & 1,(byte)NVar3 >> 7,(char)local_d8,(byte)NVar2 >> 1 & 1,
                 (byte)NVar2 >> 2 & 1,(char)local_d4,(char)local_d0,(char)local_cc,(char)local_c8,
                 (char)*(ushort *)(this + 0x2b),(char)local_c0,(char)local_bc,(char)local_b8,
                 (char)local_b4,(char)local_b0,(char)local_ac,this[0x2f],this[0x30],this[0x31],
                 (char)*(undefined4 *)(local_98 + 0xc9),(char)*(undefined4 *)(local_98 + 0xcd));
      this = local_98;
    }
    cVar15 = '\x01';
  }
  NVar1 = this[0x44];
  if (local_e8 == '\0') {
    _Var13 = local_78;
  }
  else {
    uVar12 = KeQueryUnbiasedInterruptTime();
    *(undefined8 *)(*(longlong *)(this + 0x10) + 0x1b0) = uVar12;
    p_Var14 = local_80;
    _Var13 = `anonymous_namespace'::GetDurationIn100ns
                       ((ulonglong)local_80,*(ulonglong *)(*(longlong *)(this + 0x10) + 0x1b0));
  }
  if ((this[0x31] != (NvdimmN)0x0) &&
     ((Microsoft_Windows_PersistentMemory_NvdimmEnableBits & 8) != 0)) {
    lVar8 = *(longlong *)(this + 0x10);
    McTemplateK0jdqssszq_EtwWriteTransfer
              (p_Var14,&Event_NvdimmN_CorrectableMemoryErrorsAboveThreshold,&local_50,lVar8 + 400,
               (char)*(undefined4 *)(lVar8 + 0x20),(char)*(undefined4 *)(lVar8 + 0x134),
               *(char **)(lVar8 + 0x178),*(char **)(lVar8 + 0x180),*(char **)(lVar8 + 0x188),
               *(wchar_t **)(lVar8 + 0x140),this[0x31]);
  }
  if ((this[0x30] != (NvdimmN)0x0) &&
     ((Microsoft_Windows_PersistentMemory_NvdimmEnableBits & 4) != 0)) {
    lVar8 = *(longlong *)(this + 0x10);
    McTemplateK0jdqssszq_EtwWriteTransfer
              (lVar8,&Event_NvdimmN_UncorrectableMemoryErrors,&local_50,lVar8 + 400,
               (char)*(undefined4 *)(lVar8 + 0x20),(char)*(undefined4 *)(lVar8 + 0x134),
               *(char **)(lVar8 + 0x178),*(char **)(lVar8 + 0x180),*(char **)(lVar8 + 0x188),
               *(wchar_t **)(lVar8 + 0x140),this[0x30]);
  }
  if (cVar15 != '\0') {
    local_70 = 0;
    local_5f = 0;
    local_57 = 0;
    pNVar16 = this + 0x32;
    local_55 = 0;
    local_6f = 0;
    uStack_67 = 0;
    `anonymous_namespace'::PrepareWheaErrorData
              (&local_70,(longlong)(this + 0x20),(longlong)(this + 0x25),(longlong)pNVar16,
               (longlong)(this + 0xc5),&local_70);
    NvdimmWheaReportError
              (*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10),&local_70,0x1c,
               (_WHEA_ERROR_SEVERITY)pNVar16);
  }
  NvdimmNTelemetry::HealthStatusChange
            (*(NvdimmNTelemetry **)(this + 0x160),*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10),
             local_88,local_e8,_Var13,(uchar)local_df,(uchar)NVar1);
  return;
}



===== RefreshHealthStatus @ 1c000b040 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: virtual long __cdecl NvdimmN::RefreshHealthStatus(enum
   _NVDIMM_DEVICE_HEALTH_CHECK_REASON) __ptr64 */

long __thiscall
NvdimmN::RefreshHealthStatus(NvdimmN *this,_NVDIMM_DEVICE_HEALTH_CHECK_REASON param_1)

{
  NvdimmN *pNVar1;
  NvdimmN NVar2;
  NvdimmN NVar3;
  NvdimmN NVar4;
  NvdimmN NVar5;
  NvdimmN NVar6;
  int iVar7;
  longlong lVar8;
  uint uVar9;
  undefined1 auStackY_208 [32];
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_208;
  KeWaitForSingleObject(this + 0x48,0,0,0);
  pNVar1 = this + 0x10;
  if (this[0x45] == (NvdimmN)0x0) {
    uVar9 = DoDsmDependentInit(this,param_1);
  }
  else {
    uVar9 = `anonymous_namespace'::GetHealthInfo
                      (*(_NVDIMM_DEVICE_EXTENSION **)pNVar1,(undefined4 *)(this + 0x20),
                       (undefined8 *)(this + 0x25),(undefined8 *)(this + 0x32));
  }
  *(uint *)(this + 0x40) = uVar9;
  NvdimmNTelemetry::Health
            (*(NvdimmNTelemetry **)(this + 0x160),*(_NVDIMM_DEVICE_EXTENSION **)pNVar1,param_1,uVar9
             ,(_SCMDSM_CRITICAL_HEALTH_INFO *)(this + 0x20),
             (_SCMDSM_NVDIMM_HEALTH_INFO *)(this + 0x25),
             (_SCMDSM_ENERGY_SOURCE_HEALTH_INFO *)(this + 0x32));
  if (param_1 == 1) {
    local_58 = 0;
    uStack_50 = 0;
    if ((Microsoft_Windows_PersistentMemory_NvdimmEnableBits & 2) != 0) {
      NVar2 = this[0x2a];
      NVar3 = this[0x29];
      NVar4 = this[0x2e];
      NVar5 = this[0x2d];
      NVar6 = this[0x24];
      lVar8 = *(longlong *)pNVar1;
      McTemplateK0jdqsssztttttttttttttttttttqttttttqqqdd_EtwWriteTransfer
                (lVar8,&Event_NvdimmN_ReceivedNvdimmNotification,&local_58,lVar8 + 400,
                 (char)*(undefined4 *)(lVar8 + 0x20),(char)*(undefined4 *)(lVar8 + 0x134),
                 *(char **)(lVar8 + 0x178),*(char **)(lVar8 + 0x180),*(char **)(lVar8 + 0x188),
                 *(wchar_t **)(lVar8 + 0x140),(byte)NVar6 & 1,(byte)NVar6 >> 1 & 1,
                 (byte)NVar6 >> 2 & 1,(byte)NVar6 >> 3 & 1,(byte)NVar3 & 1,(byte)NVar3 >> 1 & 1,
                 (byte)NVar3 >> 2 & 1,(byte)NVar3 >> 3 & 1,(byte)NVar3 >> 4 & 1,(byte)NVar3 >> 5 & 1
                 ,(byte)NVar3 >> 6 & 1,(byte)NVar3 >> 7,(byte)NVar2 & 1,(byte)NVar2 >> 1 & 1,
                 (byte)NVar2 >> 2 & 1,(byte)NVar2 >> 3 & 1,(byte)NVar2 >> 4 & 1,(byte)NVar2 >> 5 & 1
                 ,(byte)NVar2 >> 6 & 1,(char)*(undefined2 *)(this + 0x2b),(byte)NVar5 & 1,
                 (byte)NVar5 >> 1 & 1,(byte)NVar5 >> 2 & 1,(byte)NVar4 & 1,(byte)NVar4 >> 1 & 1,
                 (byte)NVar4 >> 2 & 1,this[0x2f],this[0x30],this[0x31],
                 (char)*(undefined4 *)(this + 0xc9),(char)*(undefined4 *)(this + 0xcd));
    }
  }
  iVar7 = *(int *)(this + 0x40);
  if ((-1 < iVar7) || ((iVar7 != -0x3ffffd6b && (iVar7 != -0x3febffe8)))) {
    HandleDeviceHealthErrors(this,param_1);
  }
  KeReleaseMutex(this + 0x48,0);
  return uVar9;
}



===== ScheduleDeferredDsmInitTimer @ 1c000b4ec =====

/* public: void __cdecl NvdimmN::ScheduleDeferredDsmInitTimer(void) __ptr64 */

void __thiscall NvdimmN::ScheduleDeferredDsmInitTimer(NvdimmN *this)

{
  KeSetCoalescableTimer(this + 0xe0,0xfffffffffa0a1f00,0,0x9c4,this + 0x120);
  WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10),4,
                  "ScheduleDeferredDsmInitTimer(): set the timer for %d seconds");
  return;
}



===== SelectFirmwareImageSlot @ 1c000b550 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl NvdimmN::SelectFirmwareImageSlot(unsigned char) __ptr64 */

long __thiscall NvdimmN::SelectFirmwareImageSlot(NvdimmN *this,uchar param_1)

{
  _NVDIMM_DEVICE_EXTENSION *p_Var1;
  int iVar2;
  int iVar3;
  undefined4 local_res8;
  uchar local_res10 [8];
  undefined8 in_stack_ffffffffffffffb8;
  
  p_Var1 = *(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10);
  if (param_1 < (byte)this[0x8f]) {
    iVar3 = 0;
    local_res8 = 0;
    local_res10[0] = param_1;
    iVar2 = (**(code **)(p_Var1 + 0x78))
                      (*(undefined8 *)(p_Var1 + 0x58),&GUID_SCM_DSM_0101,1,0x19,local_res10,1,
                       &local_res8,4);
    if (-1 < iVar2) {
      if (local_res8 == 0) {
        iVar2 = -0x7fffffcf;
        this[0xd5] = (NvdimmN)(param_1 + '\x01');
      }
      else {
        WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 0x10),2,
                        "NvdnSelectFirmwareImageSlot: _DSM failed with 0x%d");
        if ((short)local_res8 == 4) {
          if (local_res8._2_1_ == '\x01') {
            iVar3 = -0x3fffff11;
          }
          else if (local_res8._2_1_ == '\x02') {
            iVar3 = -0x3ffffe7c;
          }
          else {
            iVar3 = -0x3fffffff;
          }
        }
        else if (local_res8 != 0) {
          if ((short)local_res8 == 1) {
            iVar3 = -0x3fffff45;
          }
          else {
            iVar3 = -0x3fffffff;
            if ((short)local_res8 == 2) {
              iVar3 = -0x3ffffff3;
            }
          }
        }
        iVar2 = iVar3;
      }
    }
  }
  else {
    WriteTraceEvent(p_Var1,2,
                    "NvdnFirmwareDownloadIoctl: Invalid firmware slot (slot index %d; only %d slots available).\n"
                    ,(ulonglong)param_1,
                    CONCAT44((int)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20),
                             (uint)(byte)this[0x8f]));
    iVar2 = -0x3ffffff3;
  }
  return iVar2;
}



===== McTemplateK0jdqsssztttti_EtwWriteTransfer @ 1c000b684 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0jdqsssztttti_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,char *param_7,char *param_8,char *param_9,
               wchar_t *param_10,undefined1 param_11,undefined1 param_12,undefined1 param_13,
               undefined1 param_14,undefined1 param_15)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 auStackY_128 [32];
  undefined8 local_f8 [2];
  undefined8 local_e8;
  undefined8 local_e0;
  undefined1 *local_d8;
  undefined8 local_d0;
  undefined1 *local_c8;
  undefined8 local_c0;
  char *local_b8;
  int local_b0;
  undefined4 local_ac;
  char *local_a8;
  int local_a0;
  undefined4 local_9c;
  char *local_98;
  int local_90;
  undefined4 local_8c;
  wchar_t *local_88;
  int local_80;
  undefined4 local_7c;
  undefined1 *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_128;
  local_d8 = &param_5;
  lVar2 = -1;
  local_c8 = &param_6;
  local_e0 = 0x10;
  local_d0 = 4;
  local_c0 = 4;
  if (param_7 == (char *)0x0) {
    local_b0 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_7[lVar1] != '\0');
    local_b0 = (int)lVar1 + 1;
  }
  local_ac = 0;
  local_b8 = param_7;
  if (param_7 == (char *)0x0) {
    local_b8 = "NULL";
  }
  if (param_8 == (char *)0x0) {
    local_a0 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_8[lVar1] != '\0');
    local_a0 = (int)lVar1 + 1;
  }
  local_9c = 0;
  local_a8 = param_8;
  if (param_8 == (char *)0x0) {
    local_a8 = "NULL";
  }
  if (param_9 == (char *)0x0) {
    local_90 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_9[lVar1] != '\0');
    local_90 = (int)lVar1 + 1;
  }
  local_8c = 0;
  local_98 = param_9;
  if (param_9 == (char *)0x0) {
    local_98 = "NULL";
  }
  if (param_10 == (wchar_t *)0x0) {
    local_80 = 10;
  }
  else {
    do {
      lVar2 = lVar2 + 1;
    } while (param_10[lVar2] != L'\0');
    local_80 = (int)lVar2 * 2 + 2;
  }
  local_7c = 0;
  local_88 = param_10;
  if (param_10 == (wchar_t *)0x0) {
    local_88 = L"NULL";
  }
  local_70 = 4;
  local_78 = &param_11;
  local_68 = &param_12;
  local_60 = 4;
  local_58 = &param_13;
  local_50 = 4;
  local_48 = &param_14;
  local_40 = 4;
  local_38 = &param_15;
  local_30 = 8;
  local_e8 = param_4;
  McGenEventWrite_EtwWriteTransfer(&nvdimmEventProvider_Context,param_2,param_3,0xd,local_f8);
  return;
}



===== McTemplateK0jdqsssztttttttttttttttttttqttttttqqqdd_EtwWriteTransfer @ 1c000b870 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0jdqsssztttttttttttttttttttqttttttqqqdd_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,char *param_7,char *param_8,char *param_9,
               wchar_t *param_10,undefined1 param_11,undefined1 param_12,undefined1 param_13,
               undefined1 param_14,undefined1 param_15,undefined1 param_16,undefined1 param_17,
               undefined1 param_18,undefined1 param_19,undefined1 param_20,undefined1 param_21,
               undefined1 param_22,undefined1 param_23,undefined1 param_24,undefined1 param_25,
               undefined1 param_26,undefined1 param_27,undefined1 param_28,undefined1 param_29,
               undefined1 param_30,undefined1 param_31,undefined1 param_32,undefined1 param_33,
               undefined1 param_34,undefined1 param_35,undefined1 param_36,undefined1 param_37,
               undefined1 param_38,undefined1 param_39,undefined1 param_40,undefined1 param_41)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 auStackY_2c8 [32];
  undefined8 local_298 [2];
  undefined8 local_288;
  undefined8 local_280;
  undefined1 *local_278;
  undefined8 local_270;
  undefined1 *local_268;
  undefined8 local_260;
  char *local_258;
  int local_250;
  undefined4 local_24c;
  char *local_248;
  int local_240;
  undefined4 local_23c;
  char *local_238;
  int local_230;
  undefined4 local_22c;
  wchar_t *local_228;
  int local_220;
  undefined4 local_21c;
  undefined1 *local_218;
  undefined8 local_210;
  undefined1 *local_208;
  undefined8 local_200;
  undefined1 *local_1f8;
  undefined8 local_1f0;
  undefined1 *local_1e8;
  undefined8 local_1e0;
  undefined1 *local_1d8;
  undefined8 local_1d0;
  undefined1 *local_1c8;
  undefined8 local_1c0;
  undefined1 *local_1b8;
  undefined8 local_1b0;
  undefined1 *local_1a8;
  undefined8 local_1a0;
  undefined1 *local_198;
  undefined8 local_190;
  undefined1 *local_188;
  undefined8 local_180;
  undefined1 *local_178;
  undefined8 local_170;
  undefined1 *local_168;
  undefined8 local_160;
  undefined1 *local_158;
  undefined8 local_150;
  undefined1 *local_148;
  undefined8 local_140;
  undefined1 *local_138;
  undefined8 local_130;
  undefined1 *local_128;
  undefined8 local_120;
  undefined1 *local_118;
  undefined8 local_110;
  undefined1 *local_108;
  undefined8 local_100;
  undefined1 *local_f8;
  undefined8 local_f0;
  undefined1 *local_e8;
  undefined8 local_e0;
  undefined1 *local_d8;
  undefined8 local_d0;
  undefined1 *local_c8;
  undefined8 local_c0;
  undefined1 *local_b8;
  undefined8 local_b0;
  undefined1 *local_a8;
  undefined8 local_a0;
  undefined1 *local_98;
  undefined8 local_90;
  undefined1 *local_88;
  undefined8 local_80;
  undefined1 *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_2c8;
  local_278 = &param_5;
  lVar2 = -1;
  local_268 = &param_6;
  local_280 = 0x10;
  local_270 = 4;
  local_260 = 4;
  if (param_7 == (char *)0x0) {
    local_250 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_7[lVar1] != '\0');
    local_250 = (int)lVar1 + 1;
  }
  local_24c = 0;
  local_258 = param_7;
  if (param_7 == (char *)0x0) {
    local_258 = "NULL";
  }
  if (param_8 == (char *)0x0) {
    local_240 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_8[lVar1] != '\0');
    local_240 = (int)lVar1 + 1;
  }
  local_23c = 0;
  local_248 = param_8;
  if (param_8 == (char *)0x0) {
    local_248 = "NULL";
  }
  if (param_9 == (char *)0x0) {
    local_230 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_9[lVar1] != '\0');
    local_230 = (int)lVar1 + 1;
  }
  local_22c = 0;
  local_238 = param_9;
  if (param_9 == (char *)0x0) {
    local_238 = "NULL";
  }
  if (param_10 == (wchar_t *)0x0) {
    local_220 = 10;
  }
  else {
    do {
      lVar2 = lVar2 + 1;
    } while (param_10[lVar2] != L'\0');
    local_220 = (int)lVar2 * 2 + 2;
  }
  local_21c = 0;
  local_210 = 4;
  local_228 = param_10;
  if (param_10 == (wchar_t *)0x0) {
    local_228 = L"NULL";
  }
  local_200 = 4;
  local_218 = &param_11;
  local_208 = &param_12;
  local_1f8 = &param_13;
  local_1e8 = &param_14;
  local_1d8 = &param_15;
  local_1c8 = &param_16;
  local_1b8 = &param_17;
  local_1a8 = &param_18;
  local_198 = &param_19;
  local_188 = &param_20;
  local_178 = &param_21;
  local_168 = &param_22;
  local_158 = &param_23;
  local_148 = &param_24;
  local_138 = &param_25;
  local_128 = &param_26;
  local_118 = &param_27;
  local_108 = &param_28;
  local_f8 = &param_29;
  local_e8 = &param_30;
  local_d8 = &param_31;
  local_c8 = &param_32;
  local_b8 = &param_33;
  local_a8 = &param_34;
  local_98 = &param_35;
  local_1f0 = 4;
  local_1e0 = 4;
  local_1d0 = 4;
  local_1c0 = 4;
  local_1b0 = 4;
  local_1a0 = 4;
  local_190 = 4;
  local_180 = 4;
  local_170 = 4;
  local_160 = 4;
  local_150 = 4;
  local_140 = 4;
  local_130 = 4;
  local_120 = 4;
  local_110 = 4;
  local_100 = 4;
  local_f0 = 4;
  local_e0 = 4;
  local_d0 = 4;
  local_c0 = 4;
  local_b0 = 4;
  local_a0 = 4;
  local_90 = 4;
  local_88 = &param_36;
  local_80 = 4;
  local_78 = &param_37;
  local_70 = 4;
  local_68 = &param_38;
  local_60 = 4;
  local_58 = &param_39;
  local_50 = 4;
  local_48 = &param_40;
  local_40 = 4;
  local_38 = &param_41;
  local_30 = 4;
  local_288 = param_4;
  McGenEventWrite_EtwWriteTransfer(&nvdimmEventProvider_Context,param_2,param_3,0x27,local_298);
  return;
}



===== NvdnDeferredDsmDependentInitDpcRoutine @ 1c000bcd0 =====

/* void __cdecl NvdimmNUtil::NvdnDeferredDsmDependentInitDpcRoutine(struct _KDPC * __ptr64,void *
   __ptr64,void * __ptr64,void * __ptr64) */

void __cdecl
NvdimmNUtil::NvdnDeferredDsmDependentInitDpcRoutine
          (_KDPC *param_1,void *param_2,void *param_3,void *param_4)

{
  int iVar1;
  longlong lVar2;
  
  iVar1 = IoAcquireRemoveLockEx((longlong)param_2 + 0xf0,param_2,"",1,0x20);
  if (iVar1 == 0) {
    lVar2 = IoAllocateWorkItem(*(undefined8 *)param_2);
    if (lVar2 == 0) {
      WriteTraceEvent(param_2,2,
                      "NvdnDeferredDsmDependentInitDpcRoutine: failed to allocate workitem; trying again"
                     );
      NvdimmN::ScheduleDeferredDsmInitTimer(*(NvdimmN **)((longlong)param_2 + 0x18));
      IoReleaseRemoveLockEx((longlong)param_2 + 0xf0,param_2,0x20);
    }
    else {
      WriteTraceEvent(param_2,4,"NvdnDeferredDsmDependentInitDpcRoutine: queueing workitem");
      IoQueueWorkItem(lVar2,NvdnDeferredDsmDependentInitWorkitemRoutine,3,lVar2);
    }
  }
  return;
}



===== NvdnDeferredDsmDependentInitWorkitemRoutine @ 1c000bdb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl NvdimmNUtil::NvdnDeferredDsmDependentInitWorkitemRoutine(struct _DEVICE_OBJECT *
   __ptr64,void * __ptr64) */

void __cdecl
NvdimmNUtil::NvdnDeferredDsmDependentInitWorkitemRoutine(_DEVICE_OBJECT *param_1,void *param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  (**(code **)(**(longlong **)(lVar1 + 0x18) + 0x20))(*(longlong **)(lVar1 + 0x18),2);
  if (param_2 != (void *)0x0) {
    IoFreeWorkItem(param_2);
  }
  IoReleaseRemoveLockEx(lVar1 + 0xf0,lVar1,0x20);
  return;
}



===== NvdimmWheaPrepareErrorData @ 1c000be18 =====

/* void __cdecl NvdimmWheaPrepareErrorData(struct _NVDIMM_DEVICE_EXTENSION * __ptr64,void *
   __ptr64,unsigned long,struct _NVDIMM_WHEA_ERROR_DATA * __ptr64) */

void __cdecl
NvdimmWheaPrepareErrorData
          (_NVDIMM_DEVICE_EXTENSION *param_1,void *param_2,ulong param_3,
          _NVDIMM_WHEA_ERROR_DATA *param_4)

{
  undefined8 uVar1;
  bool bVar2;
  uint uVar3;
  _NVDIMM_WHEA_ERROR_DATA *p_Var4;
  longlong lVar5;
  ushort *puVar6;
  _NVDIMM_DEVICE_EXTENSION _Var7;
  _NVDIMM_WHEA_ERROR_DATA *p_Var8;
  undefined4 in_register_00000084;
  longlong lVar9;
  _NVDIMM_WHEA_ERROR_DATA *p_Var10;
  undefined8 local_18;
  void *pvStack_10;
  
  *(undefined8 *)param_4 = 0;
  *(undefined4 *)param_4 = 0x4e4d4353;
  *(undefined2 *)(param_4 + 4) = 0x4456;
  *(undefined4 *)(param_4 + 8) = 0x1100001;
  uVar1 = *(undefined8 *)(param_1 + 0x198);
  *(undefined8 *)(param_4 + 0xc) = *(undefined8 *)(param_1 + 400);
  *(undefined8 *)(param_4 + 0x14) = uVar1;
  *(uint *)(param_4 + 0x1c) = (uint)**(ushort **)(param_1 + 0x28);
  *(undefined4 *)(param_4 + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(param_4 + 0x24) = *(undefined4 *)(param_1 + 0x134);
  local_18 = 0;
  pvStack_10 = (void *)0x0;
  uVar3 = RtlUnicodeStringToAnsiString
                    (&local_18,param_1 + 0x138,
                     CONCAT71((int7)(CONCAT44(in_register_00000084,param_3) >> 8),1));
  if ((int)uVar3 < 0) {
    WriteTraceEvent(param_1,3,
                    "NvdWheaPrepareErrorData: Failed to convert unicode string Location to ansi string (0x%x)\n"
                    ,(ulonglong)uVar3);
  }
  else {
    uVar3 = 0x40;
    if ((ushort)local_18 < 0x41) {
      uVar3 = (uint)(ushort)local_18;
    }
    memcpy(param_4 + 0x28,pvStack_10,(ulonglong)uVar3);
  }
  RtlFreeAnsiString(&local_18);
  p_Var10 = *(_NVDIMM_WHEA_ERROR_DATA **)(param_1 + 0x178);
  p_Var8 = param_4 + 0x69;
  lVar5 = 0xb;
  lVar9 = 0xb;
  do {
    if ((lVar9 == -0x7ffffff3) || (*p_Var10 == (_NVDIMM_WHEA_ERROR_DATA)0x0)) break;
    *p_Var8 = *p_Var10;
    p_Var10 = p_Var10 + 1;
    p_Var8 = p_Var8 + 1;
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
  p_Var10 = p_Var8 + -1;
  if (lVar9 != 0) {
    p_Var10 = p_Var8;
  }
  p_Var8 = param_4 + 0x74;
  *p_Var10 = (_NVDIMM_WHEA_ERROR_DATA)0x0;
  p_Var10 = *(_NVDIMM_WHEA_ERROR_DATA **)(param_1 + 0x180);
  do {
    if ((lVar5 == -0x7ffffff3) || (*p_Var10 == (_NVDIMM_WHEA_ERROR_DATA)0x0)) break;
    *p_Var8 = *p_Var10;
    p_Var10 = p_Var10 + 1;
    p_Var8 = p_Var8 + 1;
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  p_Var10 = param_4 + 0x7f;
  p_Var4 = p_Var8 + -1;
  if (lVar5 != 0) {
    p_Var4 = p_Var8;
  }
  lVar5 = 0x17;
  *p_Var4 = (_NVDIMM_WHEA_ERROR_DATA)0x0;
  p_Var8 = *(_NVDIMM_WHEA_ERROR_DATA **)(param_1 + 0x188);
  do {
    if ((lVar5 == -0x7fffffe7) || (*p_Var8 == (_NVDIMM_WHEA_ERROR_DATA)0x0)) break;
    *p_Var10 = *p_Var8;
    p_Var8 = p_Var8 + 1;
    p_Var10 = p_Var10 + 1;
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  p_Var8 = p_Var10 + -1;
  if (lVar5 != 0) {
    p_Var8 = p_Var10;
  }
  *p_Var8 = (_NVDIMM_WHEA_ERROR_DATA)0x0;
  _Var7 = param_1[0x26];
  puVar6 = *(ushort **)(param_1 + 0x28);
  bVar2 = ContainsFormatInterfaceCode(puVar6,(uchar)_Var7,0x101);
  if (((bVar2) || (bVar2 = ContainsFormatInterfaceCode(puVar6,(uchar)_Var7,0x1901), bVar2)) ||
     (bVar2 = ContainsFormatInterfaceCode(puVar6,(uchar)_Var7,0x301), bVar2)) {
    memcpy(param_4 + 0x98,param_2,(ulonglong)param_3);
    return;
  }
  WriteTraceEvent(param_1,2,"NvdimmWheaPrepareErrorData: Unknown Format Interface Code (0x%x)",
                  (ulonglong)*puVar6);
  return;
}



===== NvdimmWheaReportError @ 1c000c03c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl NvdimmWheaReportError(struct _NVDIMM_DEVICE_EXTENSION * __ptr64,void *
   __ptr64,unsigned long,enum _WHEA_ERROR_SEVERITY) */

void __cdecl
NvdimmWheaReportError
          (_NVDIMM_DEVICE_EXTENSION *param_1,void *param_2,ulong param_3,
          _WHEA_ERROR_SEVERITY param_4)

{
  bool bVar1;
  ushort *puVar2;
  _NVDIMM_DEVICE_EXTENSION _Var3;
  undefined1 auStack_198 [32];
  char *local_178;
  undefined4 local_170;
  undefined4 local_168;
  undefined4 local_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  _NVDIMM_WHEA_ERROR_DATA local_148 [272];
  char local_38 [24];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_198;
  memset(local_148,0,0x110);
  local_38[0x10] = '\0';
  local_38[0x11] = '\0';
  local_38[0x12] = '\0';
  local_38[0x13] = '\0';
  local_38[0] = '\0';
  local_38[1] = '\0';
  local_38[2] = '\0';
  local_38[3] = '\0';
  local_38[4] = '\0';
  local_38[5] = '\0';
  local_38[6] = '\0';
  local_38[7] = '\0';
  local_38[8] = '\0';
  local_38[9] = '\0';
  local_38[10] = '\0';
  local_38[0xb] = '\0';
  local_38[0xc] = '\0';
  local_38[0xd] = '\0';
  local_38[0xe] = '\0';
  local_38[0xf] = '\0';
  local_178 = (char *)CONCAT44(local_178._4_4_,*(undefined4 *)(param_1 + 0x20));
  RtlStringCchPrintfA(local_38,0x14,"%x-%x",(ulonglong)**(ushort **)(param_1 + 0x28));
  NvdimmWheaPrepareErrorData(param_1,param_2,param_3,local_148);
  _Var3 = param_1[0x26];
  puVar2 = *(ushort **)(param_1 + 0x28);
  bVar1 = ContainsFormatInterfaceCode(puVar2,(uchar)_Var3,0x101);
  if (bVar1) {
    local_158 = 0x5aca6046;
    uStack_154 = 0x42b5c69d;
    uStack_150 = 0xfcfec2a6;
    uStack_14c = 0x354ec1e3;
  }
  else {
    bVar1 = ContainsFormatInterfaceCode(puVar2,(uchar)_Var3,0x1901);
    if (bVar1) {
      local_158 = 0x73bcf26e;
      uStack_154 = 0x420ffa4e;
      uStack_150 = 0xc1f55895;
      uStack_14c = 0x2d63a554;
    }
    else {
      bVar1 = ContainsFormatInterfaceCode(puVar2,(uchar)_Var3,0x301);
      if (bVar1) {
        local_158 = 0xf9efdac8;
        uStack_154 = 0x444eabcd;
        uStack_150 = 0x937264ae;
        uStack_14c = 0xa7d64003;
      }
      else {
        WriteTraceEvent(param_1,2,"NvdimmWheaPrepareErrorData: Unknown Format Interface Code (0x%x)"
                        ,(ulonglong)*puVar2);
        local_158 = 0x95167887;
        uStack_154 = 0x40cc492b;
        uStack_150 = 0x5e734491;
        uStack_14c = 0xd489e178;
      }
    }
  }
  local_178 = local_38;
  local_168 = 2;
  local_170 = 0x14;
  (**(code **)(param_1 + 0xd8))(*(undefined8 *)(param_1 + 0x58),&local_158,local_148,0x110);
  return;
}



===== GetDeviceName @ 1c000c1a0 =====

/* public: virtual long __cdecl SimulatedNvdimm::GetDeviceName(unsigned short * __ptr64,unsigned
   long) __ptr64 */

long __thiscall SimulatedNvdimm::GetDeviceName(SimulatedNvdimm *this,ushort *param_1,ulong param_2)

{
  long lVar1;
  
  lVar1 = RtlStringCbPrintfW(param_1,param_2,(ushort *)L"Simulated NVDIMM device");
  return lVar1;
}



===== GetUnsafeShutdownCount @ 1c000c1d0 =====

/* public: virtual long __cdecl SimulatedNvdimm::GetUnsafeShutdownCount(unsigned long * __ptr64)
   __ptr64 */

long __thiscall SimulatedNvdimm::GetUnsafeShutdownCount(SimulatedNvdimm *this,ulong *param_1)

{
  *param_1 = 0;
  return 0;
}



===== ScmDsmFinishFirmwareUpdate @ 1c000c1e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ScmDsmFinishFirmwareUpdate(longlong param_1,undefined8 param_2)

{
  (**(code **)(param_1 + 0x28))
            (*(undefined8 *)(param_1 + 8),&GUID_SCM_DSM_0101,1,0x18,0,0,param_2,4);
  return;
}



===== ScmDsmGetOperationalStatistics @ 1c000c228 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ScmDsmGetOperationalStatistics(longlong param_1,undefined8 param_2)

{
  (**(code **)(param_1 + 0x28))
            (*(undefined8 *)(param_1 + 8),&GUID_SCM_DSM_0101,1,0xd,0,0,param_2,0x20);
  return;
}



===== ScmDsmSendFirmwareUpdateData @ 1c000c270 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ScmDsmSendFirmwareUpdateData(longlong param_1,int *param_2,undefined8 param_3)

{
  (**(code **)(param_1 + 0x28))
            (*(undefined8 *)(param_1 + 8),&GUID_SCM_DSM_0101,1,
             CONCAT71((uint7)(uint3)((uint)(*param_2 + 7) >> 8),0x17),param_2,(short)(*param_2 + 7),
             param_3,4);
  return;
}



===== ScmDsmStartFirmwareUpdate @ 1c000c2bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ScmDsmStartFirmwareUpdate(longlong param_1,undefined1 param_2,undefined8 param_3)

{
  undefined1 local_res10 [24];
  
  local_res10[0] = param_2;
  (**(code **)(param_1 + 0x28))
            (*(undefined8 *)(param_1 + 8),&GUID_SCM_DSM_0101,1,0x16,local_res10,1,param_3,4);
  return;
}



===== IDsmFinishFirmwareUpdate @ 1c000c30c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void IDsmFinishFirmwareUpdate(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  (**(code **)(param_1 + 0x28))
            (*(undefined8 *)(param_1 + 8),&DAT_1c00150d0,2,0xf,param_2,8,param_3,4);
  return;
}



===== IDsmGetDeviceRuntimeFwActivationInfo @ 1c000c354 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void IDsmGetDeviceRuntimeFwActivationInfo(longlong param_1,undefined8 param_2)

{
  (**(code **)(param_1 + 0x28))(*(undefined8 *)(param_1 + 8),&DAT_1c00150d0,2,0x1d,0,0,param_2,8);
  return;
}



===== IDsmGetFirmwareInformation @ 1c000c39c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void IDsmGetFirmwareInformation(longlong param_1,undefined8 param_2)

{
  (**(code **)(param_1 + 0x28))(*(undefined8 *)(param_1 + 8),&DAT_1c00150d0,2,0xc,0,0,param_2,0x2c);
  return;
}



===== IDsmGetSecurityState @ 1c000c3e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void IDsmGetSecurityState(longlong param_1,undefined8 param_2)

{
  (**(code **)(param_1 + 0x28))(*(undefined8 *)(param_1 + 8),&DAT_1c00150d0,2,0x13,0,0,param_2,0xc);
  return;
}



===== IDsmOverwriteNvdimm @ 1c000c42c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 IDsmOverwriteNvdimm(longlong param_1,void *param_2,uint param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined1 auStack_98 [32];
  undefined8 *local_78;
  undefined2 local_70;
  undefined8 local_68;
  undefined2 local_60;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_98;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  if (param_3 < 0x21) {
    if ((param_2 == (void *)0x0) && (param_3 != 0)) {
      uVar1 = 0xc00000f1;
    }
    else {
      memcpy_s(&local_48,0x20,param_2,(ulonglong)param_3);
      local_78 = &local_48;
      local_60 = 4;
      local_70 = 0x20;
      local_68 = param_4;
      uVar1 = (**(code **)(param_1 + 0x28))(*(undefined8 *)(param_1 + 8),&DAT_1c00150d0,2,0x19);
    }
  }
  else {
    uVar1 = 0xc00000f0;
  }
  return uVar1;
}



===== IDsmQueryFinishFwUpdateStatus @ 1c000c4e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void IDsmQueryFinishFwUpdateStatus(longlong param_1,undefined4 param_2,undefined8 param_3)

{
  undefined4 local_res10 [6];
  
  local_res10[0] = param_2;
  (**(code **)(param_1 + 0x28))
            (*(undefined8 *)(param_1 + 8),&DAT_1c00150d0,2,0x10,local_res10,4,param_3,0xc);
  return;
}



===== IDsmQueryOverwriteNvdimmStatus @ 1c000c538 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void IDsmQueryOverwriteNvdimmStatus(longlong param_1,undefined8 param_2)

{
  (**(code **)(param_1 + 0x28))(*(undefined8 *)(param_1 + 8),&DAT_1c00150d0,2,0x1a,0,0,param_2,4);
  return;
}



===== IDsmSecureEraseNvdimm @ 1c000c580 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 IDsmSecureEraseNvdimm(longlong param_1,void *param_2,uint param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined1 auStack_98 [32];
  undefined8 *local_78;
  undefined2 local_70;
  undefined8 local_68;
  undefined2 local_60;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_98;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  if (param_3 < 0x21) {
    if ((param_2 == (void *)0x0) && (param_3 != 0)) {
      uVar1 = 0xc00000f1;
    }
    else {
      memcpy_s(&local_48,0x20,param_2,(ulonglong)param_3);
      local_78 = &local_48;
      local_60 = 4;
      local_70 = 0x20;
      local_68 = param_4;
      uVar1 = (**(code **)(param_1 + 0x28))(*(undefined8 *)(param_1 + 8),&DAT_1c00150d0,2,0x18);
    }
  }
  else {
    uVar1 = 0xc00000f0;
  }
  return uVar1;
}



===== IDsmSendFirmwareUpdateData @ 1c000c63c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void IDsmSendFirmwareUpdateData
               (longlong param_1,undefined8 param_2,undefined2 param_3,undefined8 param_4)

{
  (**(code **)(param_1 + 0x28))
            (*(undefined8 *)(param_1 + 8),&DAT_1c00150d0,2,0xe,param_2,param_3,param_4,4);
  return;
}



===== IDsmSetDeviceRuntimeFwActivationArmState @ 1c000c680 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void IDsmSetDeviceRuntimeFwActivationArmState
               (longlong param_1,undefined1 param_2,undefined8 param_3)

{
  undefined1 local_res10 [24];
  
  local_res10[0] = param_2;
  (**(code **)(param_1 + 0x28))
            (*(undefined8 *)(param_1 + 8),&DAT_1c00150d0,2,0x1e,local_res10,1,param_3,4);
  return;
}



===== IDsmSetPassphrase @ 1c000c6d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void IDsmSetPassphrase(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  (**(code **)(param_1 + 0x28))
            (*(undefined8 *)(param_1 + 8),&DAT_1c00150d0,2,0x14,param_2,0x40,param_3,4);
  return;
}



===== IDsmStartFirmwareUpdate @ 1c000c718 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void IDsmStartFirmwareUpdate(longlong param_1,undefined8 param_2)

{
  (**(code **)(param_1 + 0x28))(*(undefined8 *)(param_1 + 8),&DAT_1c00150d0,2,0xd,0,0,param_2,8);
  return;
}



===== IDsmUnlockUnit @ 1c000c760 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 IDsmUnlockUnit(longlong param_1,void *param_2,uint param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined1 auStack_98 [32];
  undefined8 *local_78;
  undefined2 local_70;
  undefined8 local_68;
  undefined2 local_60;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_98;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  if (param_3 < 0x21) {
    memcpy_s(&local_48,0x20,param_2,(ulonglong)param_3);
    local_78 = &local_48;
    local_60 = 4;
    local_70 = 0x20;
    local_68 = param_4;
    uVar1 = (**(code **)(param_1 + 0x28))(*(undefined8 *)(param_1 + 8),&DAT_1c00150d0,2,0x16);
  }
  else {
    uVar1 = 0xc00000f0;
  }
  return uVar1;
}



===== __GSHandlerCheck @ 1c000c818 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c000c83c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong __GSHandlerCheckCommon(undefined8 param_1,longlong param_2)

{
  byte bVar1;
  ulonglong uVar2;
  
  uVar2 = *(ulonglong *)(param_2 + 8);
  bVar1 = *(byte *)((ulonglong)*(uint *)(*(longlong *)(param_2 + 0x10) + 8) + 3 + uVar2);
  if ((bVar1 & 0xf) != 0) {
    uVar2 = (ulonglong)(bVar1 & 0xfffffff0);
  }
  return uVar2;
}



===== __security_check_cookie @ 1c000c8b0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c000c8f0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c000c920 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c000c920. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c000c950 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c000c9c0 =====

void * __cdecl memcpy(void *_Dst,void *_Src,size_t _Size)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined1 *puVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  longlong lVar15;
  ulonglong uVar16;
  ulonglong uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  
  if (_Size < 8) {
    if (_Size != 0) {
      puVar9 = _Dst;
      if (_Src < _Dst) {
        puVar9 = (undefined1 *)((longlong)_Dst + _Size);
        do {
          puVar2 = puVar9 + ((longlong)_Src - (longlong)_Dst) + -1;
          puVar9 = puVar9 + -1;
          _Size = _Size - 1;
          *puVar9 = *puVar2;
        } while (_Size != 0);
        return _Dst;
      }
      do {
        _Size = _Size - 1;
        *puVar9 = puVar9[(longlong)_Src - (longlong)_Dst];
        puVar9 = puVar9 + 1;
      } while (_Size != 0);
    }
    return _Dst;
  }
  if (_Size < 0x11) {
    uVar3 = *(undefined8 *)((longlong)_Src + (_Size - 8));
    *(undefined8 *)_Dst = *(undefined8 *)_Src;
    *(undefined8 *)((longlong)_Dst + (_Size - 8)) = uVar3;
    return _Dst;
  }
  if (_Size < 0x21) {
    uVar3 = *(undefined8 *)((longlong)_Src + 8);
    puVar10 = (undefined8 *)((longlong)_Src + (_Size - 0x10));
    uVar4 = *puVar10;
    uVar5 = puVar10[1];
    *(undefined8 *)_Dst = *(undefined8 *)_Src;
    *(undefined8 *)((longlong)_Dst + 8) = uVar3;
    puVar10 = (undefined8 *)((longlong)_Dst + (_Size - 0x10));
    *puVar10 = uVar4;
    puVar10[1] = uVar5;
    return _Dst;
  }
  lVar15 = (longlong)_Src - (longlong)_Dst;
  if ((_Src < _Dst) && (_Dst < (void *)((longlong)_Src + _Size))) {
    puVar14 = (undefined4 *)((longlong)_Dst + lVar15 + (_Size - 0x10));
    uVar18 = puVar14[1];
    uVar20 = puVar14[2];
    uVar22 = puVar14[3];
    puVar12 = (undefined4 *)((longlong)_Dst + (_Size - 0x10));
    uVar16 = _Size - 0x10;
    puVar13 = puVar12;
    uVar19 = *puVar14;
    uVar21 = uVar18;
    uVar23 = uVar20;
    uVar25 = uVar22;
    if (((ulonglong)puVar12 & 0xf) != 0) {
      puVar13 = (undefined4 *)((ulonglong)puVar12 & 0xfffffffffffffff0);
      puVar1 = (undefined4 *)((longlong)puVar13 + lVar15);
      uVar19 = *puVar1;
      uVar21 = puVar1[1];
      uVar23 = puVar1[2];
      uVar25 = puVar1[3];
      *puVar12 = *puVar14;
      *(undefined4 *)((longlong)_Dst + (_Size - 0xc)) = uVar18;
      *(undefined4 *)((longlong)_Dst + (_Size - 8)) = uVar20;
      *(undefined4 *)((longlong)_Dst + (_Size - 4)) = uVar22;
      uVar16 = (longlong)puVar13 - (longlong)_Dst;
    }
    uVar17 = uVar16 >> 6;
    if (uVar17 != 0) {
      uVar16 = uVar16 & 0x3f;
      puVar14 = puVar13;
      uVar18 = uVar19;
      uVar20 = uVar21;
      uVar22 = uVar23;
      uVar24 = uVar25;
      do {
        puVar10 = (undefined8 *)((longlong)puVar14 + lVar15 + -0x10);
        uVar3 = *puVar10;
        uVar4 = puVar10[1];
        puVar10 = (undefined8 *)((longlong)puVar14 + lVar15 + -0x20);
        uVar5 = *puVar10;
        uVar6 = puVar10[1];
        puVar10 = (undefined8 *)((longlong)puVar14 + lVar15 + -0x30);
        uVar7 = *puVar10;
        uVar8 = puVar10[1];
        puVar13 = (undefined4 *)((longlong)puVar14 + lVar15 + -0x40);
        uVar19 = *puVar13;
        uVar21 = puVar13[1];
        uVar23 = puVar13[2];
        uVar25 = puVar13[3];
        *puVar14 = uVar18;
        puVar14[1] = uVar20;
        puVar14[2] = uVar22;
        puVar14[3] = uVar24;
        puVar13 = puVar14 + -0x10;
        uVar17 = uVar17 - 1;
        *(undefined8 *)(puVar14 + -4) = uVar3;
        *(undefined8 *)(puVar14 + -2) = uVar4;
        *(undefined8 *)(puVar14 + -8) = uVar5;
        *(undefined8 *)(puVar14 + -6) = uVar6;
        *(undefined8 *)(puVar14 + -0xc) = uVar7;
        *(undefined8 *)(puVar14 + -10) = uVar8;
        puVar14 = puVar13;
        uVar18 = uVar19;
        uVar20 = uVar21;
        uVar22 = uVar23;
        uVar24 = uVar25;
      } while (uVar17 != 0);
    }
    for (uVar17 = uVar16 >> 4; uVar17 != 0; uVar17 = uVar17 - 1) {
      *puVar13 = uVar19;
      puVar13[1] = uVar21;
      puVar13[2] = uVar23;
      puVar13[3] = uVar25;
      puVar14 = (undefined4 *)((longlong)puVar13 + lVar15 + -0x10);
      uVar19 = *puVar14;
      uVar21 = puVar14[1];
      uVar23 = puVar14[2];
      uVar25 = puVar14[3];
      puVar13 = puVar13 + -4;
    }
    if ((uVar16 & 0xf) != 0) {
      puVar10 = (undefined8 *)((longlong)puVar13 - (uVar16 & 0xf));
      uVar3 = ((undefined8 *)((longlong)puVar10 + lVar15))[1];
      *puVar10 = *(undefined8 *)((longlong)puVar10 + lVar15);
      puVar10[1] = uVar3;
    }
    *puVar13 = uVar19;
    puVar13[1] = uVar21;
    puVar13[2] = uVar23;
    puVar13[3] = uVar25;
    return _Dst;
  }
  puVar14 = (undefined4 *)((longlong)_Dst + lVar15);
  uVar18 = puVar14[1];
  uVar20 = puVar14[2];
  uVar22 = puVar14[3];
  puVar10 = (undefined8 *)((longlong)_Dst + 0x10);
  uVar19 = *puVar14;
  uVar21 = uVar18;
  uVar23 = uVar20;
  uVar25 = uVar22;
  if (((ulonglong)puVar10 & 0xf) != 0) {
    puVar13 = (undefined4 *)(((ulonglong)puVar10 & 0xfffffffffffffff0) + lVar15);
    uVar19 = *puVar13;
    uVar21 = puVar13[1];
    uVar23 = puVar13[2];
    uVar25 = puVar13[3];
    *(undefined4 *)_Dst = *puVar14;
    *(undefined4 *)((longlong)_Dst + 4) = uVar18;
    *(undefined4 *)((longlong)_Dst + 8) = uVar20;
    *(undefined4 *)((longlong)_Dst + 0xc) = uVar22;
    puVar10 = (undefined8 *)(((ulonglong)puVar10 & 0xfffffffffffffff0) + 0x10);
  }
  uVar16 = (longlong)_Dst + (_Size - (longlong)puVar10);
  uVar17 = uVar16 >> 6;
  if (uVar17 != 0) {
    if (uVar17 < 0x1001) {
      uVar16 = uVar16 & 0x3f;
      puVar11 = puVar10;
      uVar18 = uVar19;
      uVar20 = uVar21;
      uVar22 = uVar23;
      uVar24 = uVar25;
      do {
        uVar3 = *(undefined8 *)((longlong)puVar11 + lVar15);
        uVar4 = ((undefined8 *)((longlong)puVar11 + lVar15))[1];
        puVar10 = (undefined8 *)((longlong)puVar11 + lVar15 + 0x10);
        uVar5 = *puVar10;
        uVar6 = puVar10[1];
        puVar10 = (undefined8 *)((longlong)puVar11 + lVar15 + 0x20);
        uVar7 = *puVar10;
        uVar8 = puVar10[1];
        puVar14 = (undefined4 *)((longlong)puVar11 + lVar15 + 0x30);
        uVar19 = *puVar14;
        uVar21 = puVar14[1];
        uVar23 = puVar14[2];
        uVar25 = puVar14[3];
        *(undefined4 *)(puVar11 + -2) = uVar18;
        *(undefined4 *)((longlong)puVar11 + -0xc) = uVar20;
        *(undefined4 *)(puVar11 + -1) = uVar22;
        *(undefined4 *)((longlong)puVar11 + -4) = uVar24;
        puVar10 = puVar11 + 8;
        uVar17 = uVar17 - 1;
        *puVar11 = uVar3;
        puVar11[1] = uVar4;
        puVar11[2] = uVar5;
        puVar11[3] = uVar6;
        puVar11[4] = uVar7;
        puVar11[5] = uVar8;
        puVar11 = puVar10;
        uVar18 = uVar19;
        uVar20 = uVar21;
        uVar22 = uVar23;
        uVar24 = uVar25;
      } while (uVar17 != 0);
    }
    else {
      uVar17 = uVar16 >> 6;
      uVar16 = uVar16 & 0x3f;
      puVar11 = puVar10;
      uVar18 = uVar19;
      uVar20 = uVar21;
      uVar22 = uVar23;
      uVar24 = uVar25;
      do {
        uVar3 = *(undefined8 *)((longlong)puVar11 + lVar15);
        uVar4 = ((undefined8 *)((longlong)puVar11 + lVar15))[1];
        puVar10 = (undefined8 *)((longlong)puVar11 + lVar15 + 0x10);
        uVar5 = *puVar10;
        uVar6 = puVar10[1];
        puVar10 = (undefined8 *)((longlong)puVar11 + lVar15 + 0x20);
        uVar7 = *puVar10;
        uVar8 = puVar10[1];
        puVar14 = (undefined4 *)((longlong)puVar11 + lVar15 + 0x30);
        uVar19 = *puVar14;
        uVar21 = puVar14[1];
        uVar23 = puVar14[2];
        uVar25 = puVar14[3];
        *(undefined4 *)(puVar11 + -2) = uVar18;
        *(undefined4 *)((longlong)puVar11 + -0xc) = uVar20;
        *(undefined4 *)(puVar11 + -1) = uVar22;
        *(undefined4 *)((longlong)puVar11 + -4) = uVar24;
        puVar10 = puVar11 + 8;
        uVar17 = uVar17 - 1;
        *puVar11 = uVar3;
        puVar11[1] = uVar4;
        puVar11[2] = uVar5;
        puVar11[3] = uVar6;
        puVar11[4] = uVar7;
        puVar11[5] = uVar8;
        puVar11 = puVar10;
        uVar18 = uVar19;
        uVar20 = uVar21;
        uVar22 = uVar23;
        uVar24 = uVar25;
      } while (uVar17 != 0);
    }
  }
  for (uVar17 = uVar16 >> 4; uVar17 != 0; uVar17 = uVar17 - 1) {
    *(undefined4 *)(puVar10 + -2) = uVar19;
    *(undefined4 *)((longlong)puVar10 + -0xc) = uVar21;
    *(undefined4 *)(puVar10 + -1) = uVar23;
    *(undefined4 *)((longlong)puVar10 + -4) = uVar25;
    puVar14 = (undefined4 *)((longlong)puVar10 + lVar15);
    uVar19 = *puVar14;
    uVar21 = puVar14[1];
    uVar23 = puVar14[2];
    uVar25 = puVar14[3];
    puVar10 = puVar10 + 2;
  }
  if ((uVar16 & 0xf) != 0) {
    puVar11 = (undefined8 *)((longlong)puVar10 + ((uVar16 & 0xf) - 0x10));
    uVar3 = ((undefined8 *)((longlong)puVar11 + lVar15))[1];
    *puVar11 = *(undefined8 *)((longlong)puVar11 + lVar15);
    puVar11[1] = uVar3;
  }
  *(undefined4 *)(puVar10 + -2) = uVar19;
  *(undefined4 *)((longlong)puVar10 + -0xc) = uVar21;
  *(undefined4 *)(puVar10 + -1) = uVar23;
  *(undefined4 *)((longlong)puVar10 + -4) = uVar25;
  return _Dst;
}



===== memset @ 1c000ccc0 =====

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  longlong *plVar1;
  undefined4 *puVar2;
  void *pvVar3;
  longlong *plVar4;
  undefined4 uVar5;
  longlong lVar6;
  undefined1 *puVar7;
  ulonglong uVar8;
  longlong lVar9;
  longlong *plVar10;
  longlong extraout_XMM0_Qa;
  longlong extraout_XMM0_Qb;
  
  pvVar3 = _Dst;
  lVar6 = (ulonglong)(byte)_Val * 0x101010101010101;
  if (_Size < 0x40) {
    if (_Size < 0x10) {
      if (3 < _Size) {
        puVar2 = (undefined4 *)((_Size - 4) + (longlong)_Dst);
        uVar5 = (undefined4)lVar6;
        *(undefined4 *)_Dst = uVar5;
        uVar8 = (_Size & 8) >> 1;
        *puVar2 = uVar5;
        *(undefined4 *)((longlong)_Dst + uVar8) = uVar5;
        *(undefined4 *)((longlong)puVar2 - uVar8) = uVar5;
        return pvVar3;
      }
      if (_Size != 0) {
        *(char *)_Dst = (char)lVar6;
        if (_Size != 1) {
          *(short *)((longlong)_Dst + (_Size - 2)) = (short)lVar6;
        }
      }
      return pvVar3;
    }
  }
  else {
    if (((__isa_info & 2) != 0) && (799 < _Size)) {
      plVar4 = _Dst;
      lVar9 = lVar6;
      if ((__isa_info & 1) == 0) {
        _Dst = (void *)__memset_query();
        lVar6 = extraout_XMM0_Qa;
        lVar9 = extraout_XMM0_Qb;
      }
      *plVar4 = lVar6;
      plVar4[1] = lVar9;
      plVar4[2] = lVar6;
      plVar4[3] = lVar9;
      plVar4[4] = lVar6;
      plVar4[5] = lVar9;
      plVar4[6] = lVar6;
      plVar4[7] = lVar9;
      puVar7 = (undefined1 *)((ulonglong)(plVar4 + 8) & 0xffffffffffffffc0);
      for (lVar9 = (longlong)plVar4 +
                   (_Size - (longlong)((ulonglong)(plVar4 + 8) & 0xffffffffffffffc0)); lVar9 != 0;
          lVar9 = lVar9 + -1) {
        *puVar7 = (char)lVar6;
        puVar7 = puVar7 + 1;
      }
      return _Dst;
    }
    *(longlong *)_Dst = lVar6;
    *(longlong *)((longlong)_Dst + 8) = lVar6;
    plVar4 = (longlong *)((longlong)_Dst + 0x10U & 0xfffffffffffffff0);
    _Size = (longlong)_Dst + (_Size - (longlong)plVar4);
    _Dst = plVar4;
    if (0x3f < _Size) {
      plVar1 = (longlong *)((longlong)plVar4 + (_Size - 0x10));
      plVar10 = (longlong *)((longlong)plVar4 + (_Size - 0x30) & 0xfffffffffffffff0);
      uVar8 = _Size >> 6;
      do {
        *plVar4 = lVar6;
        plVar4[1] = lVar6;
        plVar4[2] = lVar6;
        plVar4[3] = lVar6;
        uVar8 = uVar8 - 1;
        plVar4[4] = lVar6;
        plVar4[5] = lVar6;
        plVar4[6] = lVar6;
        plVar4[7] = lVar6;
        plVar4 = plVar4 + 8;
      } while (uVar8 != 0);
      *plVar10 = lVar6;
      plVar10[1] = lVar6;
      plVar10[2] = lVar6;
      plVar10[3] = lVar6;
      plVar10[4] = lVar6;
      plVar10[5] = lVar6;
      *plVar1 = lVar6;
      plVar1[1] = lVar6;
      return pvVar3;
    }
  }
  plVar1 = (longlong *)((_Size - 0x10) + (longlong)_Dst);
  *(longlong *)_Dst = lVar6;
  *(longlong *)((longlong)_Dst + 8) = lVar6;
  uVar8 = (_Size & 0x20) >> 1;
  *plVar1 = lVar6;
  plVar1[1] = lVar6;
  plVar4 = (longlong *)((longlong)_Dst + uVar8);
  *plVar4 = lVar6;
  plVar4[1] = lVar6;
  plVar1 = (longlong *)((longlong)plVar1 - uVar8);
  *plVar1 = lVar6;
  plVar1[1] = lVar6;
  return pvVar3;
}



===== __memset_repmovs @ 1c000ce00 =====

undefined8 __memset_repmovs(undefined1 *param_1,undefined8 param_2,longlong param_3)

{
  undefined8 in_RAX;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 in_XMM0_Ba;
  undefined1 extraout_XMM0_Ba;
  undefined1 in_XMM0_Bb;
  undefined1 extraout_XMM0_Bb;
  undefined1 in_XMM0_Bc;
  undefined1 extraout_XMM0_Bc;
  undefined1 in_XMM0_Bd;
  undefined1 extraout_XMM0_Bd;
  undefined1 in_XMM0_Be;
  undefined1 extraout_XMM0_Be;
  undefined1 in_XMM0_Bf;
  undefined1 extraout_XMM0_Bf;
  undefined1 in_XMM0_Bg;
  undefined1 extraout_XMM0_Bg;
  undefined1 in_XMM0_Bh;
  undefined1 extraout_XMM0_Bh;
  undefined1 in_XMM0_Bi;
  undefined1 extraout_XMM0_Bi;
  undefined1 in_XMM0_Bj;
  undefined1 extraout_XMM0_Bj;
  undefined1 in_XMM0_Bk;
  undefined1 extraout_XMM0_Bk;
  undefined1 in_XMM0_Bl;
  undefined1 extraout_XMM0_Bl;
  undefined1 in_XMM0_Bm;
  undefined1 extraout_XMM0_Bm;
  undefined1 in_XMM0_Bn;
  undefined1 extraout_XMM0_Bn;
  undefined1 in_XMM0_Bo;
  undefined1 extraout_XMM0_Bo;
  undefined1 in_XMM0_Bp;
  undefined1 extraout_XMM0_Bp;
  
  if ((__isa_info & 1) == 0) {
    in_RAX = __memset_query();
    in_XMM0_Ba = extraout_XMM0_Ba;
    in_XMM0_Bb = extraout_XMM0_Bb;
    in_XMM0_Bc = extraout_XMM0_Bc;
    in_XMM0_Bd = extraout_XMM0_Bd;
    in_XMM0_Be = extraout_XMM0_Be;
    in_XMM0_Bf = extraout_XMM0_Bf;
    in_XMM0_Bg = extraout_XMM0_Bg;
    in_XMM0_Bh = extraout_XMM0_Bh;
    in_XMM0_Bi = extraout_XMM0_Bi;
    in_XMM0_Bj = extraout_XMM0_Bj;
    in_XMM0_Bk = extraout_XMM0_Bk;
    in_XMM0_Bl = extraout_XMM0_Bl;
    in_XMM0_Bm = extraout_XMM0_Bm;
    in_XMM0_Bn = extraout_XMM0_Bn;
    in_XMM0_Bo = extraout_XMM0_Bo;
    in_XMM0_Bp = extraout_XMM0_Bp;
  }
  *param_1 = in_XMM0_Ba;
  param_1[1] = in_XMM0_Bb;
  param_1[2] = in_XMM0_Bc;
  param_1[3] = in_XMM0_Bd;
  param_1[4] = in_XMM0_Be;
  param_1[5] = in_XMM0_Bf;
  param_1[6] = in_XMM0_Bg;
  param_1[7] = in_XMM0_Bh;
  param_1[8] = in_XMM0_Bi;
  param_1[9] = in_XMM0_Bj;
  param_1[10] = in_XMM0_Bk;
  param_1[0xb] = in_XMM0_Bl;
  param_1[0xc] = in_XMM0_Bm;
  param_1[0xd] = in_XMM0_Bn;
  param_1[0xe] = in_XMM0_Bo;
  param_1[0xf] = in_XMM0_Bp;
  param_1[0x10] = in_XMM0_Ba;
  param_1[0x11] = in_XMM0_Bb;
  param_1[0x12] = in_XMM0_Bc;
  param_1[0x13] = in_XMM0_Bd;
  param_1[0x14] = in_XMM0_Be;
  param_1[0x15] = in_XMM0_Bf;
  param_1[0x16] = in_XMM0_Bg;
  param_1[0x17] = in_XMM0_Bh;
  param_1[0x18] = in_XMM0_Bi;
  param_1[0x19] = in_XMM0_Bj;
  param_1[0x1a] = in_XMM0_Bk;
  param_1[0x1b] = in_XMM0_Bl;
  param_1[0x1c] = in_XMM0_Bm;
  param_1[0x1d] = in_XMM0_Bn;
  param_1[0x1e] = in_XMM0_Bo;
  param_1[0x1f] = in_XMM0_Bp;
  param_1[0x20] = in_XMM0_Ba;
  param_1[0x21] = in_XMM0_Bb;
  param_1[0x22] = in_XMM0_Bc;
  param_1[0x23] = in_XMM0_Bd;
  param_1[0x24] = in_XMM0_Be;
  param_1[0x25] = in_XMM0_Bf;
  param_1[0x26] = in_XMM0_Bg;
  param_1[0x27] = in_XMM0_Bh;
  param_1[0x28] = in_XMM0_Bi;
  param_1[0x29] = in_XMM0_Bj;
  param_1[0x2a] = in_XMM0_Bk;
  param_1[0x2b] = in_XMM0_Bl;
  param_1[0x2c] = in_XMM0_Bm;
  param_1[0x2d] = in_XMM0_Bn;
  param_1[0x2e] = in_XMM0_Bo;
  param_1[0x2f] = in_XMM0_Bp;
  param_1[0x30] = in_XMM0_Ba;
  param_1[0x31] = in_XMM0_Bb;
  param_1[0x32] = in_XMM0_Bc;
  param_1[0x33] = in_XMM0_Bd;
  param_1[0x34] = in_XMM0_Be;
  param_1[0x35] = in_XMM0_Bf;
  param_1[0x36] = in_XMM0_Bg;
  param_1[0x37] = in_XMM0_Bh;
  param_1[0x38] = in_XMM0_Bi;
  param_1[0x39] = in_XMM0_Bj;
  param_1[0x3a] = in_XMM0_Bk;
  param_1[0x3b] = in_XMM0_Bl;
  param_1[0x3c] = in_XMM0_Bm;
  param_1[0x3d] = in_XMM0_Bn;
  param_1[0x3e] = in_XMM0_Bo;
  param_1[0x3f] = in_XMM0_Bp;
  puVar1 = (undefined1 *)((ulonglong)(param_1 + 0x40) & 0xffffffffffffffc0);
  for (puVar2 = param_1 + (param_3 - (longlong)((ulonglong)(param_1 + 0x40) & 0xffffffffffffffc0));
      puVar2 != (undefined1 *)0x0; puVar2 = puVar2 + -1) {
    *puVar1 = in_XMM0_Ba;
    puVar1 = puVar1 + 1;
  }
  return in_RAX;
}



===== __memset_query @ 1c000ce80 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c000cf00 =====

longlong * __memset_spec_ermsb(longlong *param_1,byte param_2,undefined1 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  undefined4 uVar3;
  longlong lVar4;
  undefined1 *puVar5;
  ulonglong uVar6;
  longlong lVar7;
  longlong *plVar8;
  
  plVar1 = param_1;
  lVar4 = (ulonglong)param_2 * 0x101010101010101;
  if (param_3 < (undefined1 *)0x40) {
    if (param_3 < (undefined1 *)0x10) {
      if ((undefined1 *)0x3 < param_3) {
        uVar3 = (undefined4)lVar4;
        *(undefined4 *)param_1 = uVar3;
        uVar6 = ((ulonglong)param_3 & 8) >> 1;
        *(undefined4 *)(param_3 + -4 + (longlong)param_1) = uVar3;
        *(undefined4 *)((longlong)param_1 + uVar6) = uVar3;
        *(undefined4 *)((longlong)(param_3 + -4 + (longlong)param_1) - uVar6) = uVar3;
        return plVar1;
      }
      if (param_3 != (undefined1 *)0x0) {
        *(char *)param_1 = (char)lVar4;
        if (param_3 != (undefined1 *)0x1) {
          *(short *)(param_3 + (longlong)param_1 + -2) = (short)lVar4;
        }
      }
      return plVar1;
    }
  }
  else {
    if ((undefined1 *)0x31f < param_3) {
      *param_1 = lVar4;
      param_1[1] = lVar4;
      param_1[2] = lVar4;
      param_1[3] = lVar4;
      param_1[4] = lVar4;
      param_1[5] = lVar4;
      param_1[6] = lVar4;
      param_1[7] = lVar4;
      puVar5 = (undefined1 *)((ulonglong)(param_1 + 8) & 0xffffffffffffffc0);
      for (lVar7 = (longlong)(param_3 + (longlong)param_1) -
                   (longlong)((ulonglong)(param_1 + 8) & 0xffffffffffffffc0); lVar7 != 0;
          lVar7 = lVar7 + -1) {
        *puVar5 = (char)lVar4;
        puVar5 = puVar5 + 1;
      }
      return param_1;
    }
    *param_1 = lVar4;
    param_1[1] = lVar4;
    puVar5 = param_3 + (longlong)param_1;
    param_1 = (longlong *)((ulonglong)(param_1 + 2) & 0xfffffffffffffff0);
    param_3 = puVar5 + -(longlong)param_1;
    if ((undefined1 *)0x3f < param_3) {
      plVar8 = (longlong *)
               ((ulonglong)((longlong)(param_1 + -6) + (longlong)param_3) & 0xfffffffffffffff0);
      uVar6 = (ulonglong)param_3 >> 6;
      plVar2 = param_1;
      do {
        *plVar2 = lVar4;
        plVar2[1] = lVar4;
        plVar2[2] = lVar4;
        plVar2[3] = lVar4;
        uVar6 = uVar6 - 1;
        plVar2[4] = lVar4;
        plVar2[5] = lVar4;
        plVar2[6] = lVar4;
        plVar2[7] = lVar4;
        plVar2 = plVar2 + 8;
      } while (uVar6 != 0);
      *plVar8 = lVar4;
      plVar8[1] = lVar4;
      plVar8[2] = lVar4;
      plVar8[3] = lVar4;
      plVar8[4] = lVar4;
      plVar8[5] = lVar4;
      *(longlong *)((longlong)(param_1 + -2) + (longlong)param_3) = lVar4;
      ((longlong *)((longlong)(param_1 + -2) + (longlong)param_3))[1] = lVar4;
      return plVar1;
    }
  }
  plVar8 = (longlong *)(param_3 + -0x10 + (longlong)param_1);
  *param_1 = lVar4;
  param_1[1] = lVar4;
  uVar6 = ((ulonglong)param_3 & 0x20) >> 1;
  *plVar8 = lVar4;
  plVar8[1] = lVar4;
  plVar2 = (longlong *)((longlong)param_1 + uVar6);
  *plVar2 = lVar4;
  plVar2[1] = lVar4;
  plVar8 = (longlong *)((longlong)plVar8 - uVar6);
  *plVar8 = lVar4;
  plVar8[1] = lVar4;
  return plVar1;
}



===== __memset_spec_ermsb_repmovsb @ 1c000d040 =====

void __memset_spec_ermsb_repmovsb(undefined1 *param_1,undefined8 param_2,longlong param_3)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 in_XMM0_Ba;
  undefined1 in_XMM0_Bb;
  undefined1 in_XMM0_Bc;
  undefined1 in_XMM0_Bd;
  undefined1 in_XMM0_Be;
  undefined1 in_XMM0_Bf;
  undefined1 in_XMM0_Bg;
  undefined1 in_XMM0_Bh;
  undefined1 in_XMM0_Bi;
  undefined1 in_XMM0_Bj;
  undefined1 in_XMM0_Bk;
  undefined1 in_XMM0_Bl;
  undefined1 in_XMM0_Bm;
  undefined1 in_XMM0_Bn;
  undefined1 in_XMM0_Bo;
  undefined1 in_XMM0_Bp;
  
  *param_1 = in_XMM0_Ba;
  param_1[1] = in_XMM0_Bb;
  param_1[2] = in_XMM0_Bc;
  param_1[3] = in_XMM0_Bd;
  param_1[4] = in_XMM0_Be;
  param_1[5] = in_XMM0_Bf;
  param_1[6] = in_XMM0_Bg;
  param_1[7] = in_XMM0_Bh;
  param_1[8] = in_XMM0_Bi;
  param_1[9] = in_XMM0_Bj;
  param_1[10] = in_XMM0_Bk;
  param_1[0xb] = in_XMM0_Bl;
  param_1[0xc] = in_XMM0_Bm;
  param_1[0xd] = in_XMM0_Bn;
  param_1[0xe] = in_XMM0_Bo;
  param_1[0xf] = in_XMM0_Bp;
  param_1[0x10] = in_XMM0_Ba;
  param_1[0x11] = in_XMM0_Bb;
  param_1[0x12] = in_XMM0_Bc;
  param_1[0x13] = in_XMM0_Bd;
  param_1[0x14] = in_XMM0_Be;
  param_1[0x15] = in_XMM0_Bf;
  param_1[0x16] = in_XMM0_Bg;
  param_1[0x17] = in_XMM0_Bh;
  param_1[0x18] = in_XMM0_Bi;
  param_1[0x19] = in_XMM0_Bj;
  param_1[0x1a] = in_XMM0_Bk;
  param_1[0x1b] = in_XMM0_Bl;
  param_1[0x1c] = in_XMM0_Bm;
  param_1[0x1d] = in_XMM0_Bn;
  param_1[0x1e] = in_XMM0_Bo;
  param_1[0x1f] = in_XMM0_Bp;
  param_1[0x20] = in_XMM0_Ba;
  param_1[0x21] = in_XMM0_Bb;
  param_1[0x22] = in_XMM0_Bc;
  param_1[0x23] = in_XMM0_Bd;
  param_1[0x24] = in_XMM0_Be;
  param_1[0x25] = in_XMM0_Bf;
  param_1[0x26] = in_XMM0_Bg;
  param_1[0x27] = in_XMM0_Bh;
  param_1[0x28] = in_XMM0_Bi;
  param_1[0x29] = in_XMM0_Bj;
  param_1[0x2a] = in_XMM0_Bk;
  param_1[0x2b] = in_XMM0_Bl;
  param_1[0x2c] = in_XMM0_Bm;
  param_1[0x2d] = in_XMM0_Bn;
  param_1[0x2e] = in_XMM0_Bo;
  param_1[0x2f] = in_XMM0_Bp;
  param_1[0x30] = in_XMM0_Ba;
  param_1[0x31] = in_XMM0_Bb;
  param_1[0x32] = in_XMM0_Bc;
  param_1[0x33] = in_XMM0_Bd;
  param_1[0x34] = in_XMM0_Be;
  param_1[0x35] = in_XMM0_Bf;
  param_1[0x36] = in_XMM0_Bg;
  param_1[0x37] = in_XMM0_Bh;
  param_1[0x38] = in_XMM0_Bi;
  param_1[0x39] = in_XMM0_Bj;
  param_1[0x3a] = in_XMM0_Bk;
  param_1[0x3b] = in_XMM0_Bl;
  param_1[0x3c] = in_XMM0_Bm;
  param_1[0x3d] = in_XMM0_Bn;
  param_1[0x3e] = in_XMM0_Bo;
  param_1[0x3f] = in_XMM0_Bp;
  puVar1 = (undefined1 *)((ulonglong)(param_1 + 0x40) & 0xffffffffffffffc0);
  for (puVar2 = param_1 + (param_3 - (longlong)((ulonglong)(param_1 + 0x40) & 0xffffffffffffffc0));
      puVar2 != (undefined1 *)0x0; puVar2 = puVar2 + -1) {
    *puVar1 = in_XMM0_Ba;
    puVar1 = puVar1 + 1;
  }
  return;
}



===== __memset_spec_plain @ 1c000d0c0 =====

longlong * __memset_spec_plain(longlong *param_1,byte param_2,undefined1 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  undefined4 uVar3;
  longlong lVar4;
  undefined1 *puVar5;
  ulonglong uVar6;
  longlong *plVar7;
  
  plVar1 = param_1;
  lVar4 = (ulonglong)param_2 * 0x101010101010101;
  if (param_3 < (undefined1 *)0x40) {
    if (param_3 < (undefined1 *)0x10) {
      if ((undefined1 *)0x3 < param_3) {
        uVar3 = (undefined4)lVar4;
        *(undefined4 *)param_1 = uVar3;
        uVar6 = ((ulonglong)param_3 & 8) >> 1;
        *(undefined4 *)(param_3 + -4 + (longlong)param_1) = uVar3;
        *(undefined4 *)((longlong)param_1 + uVar6) = uVar3;
        *(undefined4 *)((longlong)(param_3 + -4 + (longlong)param_1) - uVar6) = uVar3;
        return plVar1;
      }
      if (param_3 != (undefined1 *)0x0) {
        *(char *)param_1 = (char)lVar4;
        if (param_3 != (undefined1 *)0x1) {
          *(short *)(param_3 + (longlong)param_1 + -2) = (short)lVar4;
        }
      }
      return plVar1;
    }
  }
  else {
    *param_1 = lVar4;
    param_1[1] = lVar4;
    puVar5 = param_3 + (longlong)param_1;
    param_1 = (longlong *)((ulonglong)(param_1 + 2) & 0xfffffffffffffff0);
    param_3 = puVar5 + -(longlong)param_1;
    if ((undefined1 *)0x3f < param_3) {
      plVar7 = (longlong *)
               ((ulonglong)((longlong)(param_1 + -6) + (longlong)param_3) & 0xfffffffffffffff0);
      uVar6 = (ulonglong)param_3 >> 6;
      plVar2 = param_1;
      do {
        *plVar2 = lVar4;
        plVar2[1] = lVar4;
        plVar2[2] = lVar4;
        plVar2[3] = lVar4;
        uVar6 = uVar6 - 1;
        plVar2[4] = lVar4;
        plVar2[5] = lVar4;
        plVar2[6] = lVar4;
        plVar2[7] = lVar4;
        plVar2 = plVar2 + 8;
      } while (uVar6 != 0);
      *plVar7 = lVar4;
      plVar7[1] = lVar4;
      plVar7[2] = lVar4;
      plVar7[3] = lVar4;
      plVar7[4] = lVar4;
      plVar7[5] = lVar4;
      *(longlong *)((longlong)(param_1 + -2) + (longlong)param_3) = lVar4;
      ((longlong *)((longlong)(param_1 + -2) + (longlong)param_3))[1] = lVar4;
      return plVar1;
    }
  }
  plVar7 = (longlong *)(param_3 + -0x10 + (longlong)param_1);
  *param_1 = lVar4;
  param_1[1] = lVar4;
  uVar6 = ((ulonglong)param_3 & 0x20) >> 1;
  *plVar7 = lVar4;
  plVar7[1] = lVar4;
  plVar2 = (longlong *)((longlong)param_1 + uVar6);
  *plVar2 = lVar4;
  plVar2[1] = lVar4;
  plVar7 = (longlong *)((longlong)plVar7 - uVar6);
  *plVar7 = lVar4;
  plVar7[1] = lVar4;
  return plVar1;
}



===== NvdAddDevice @ 1c001b010 =====

/* long __cdecl NvdAddDevice(struct _DRIVER_OBJECT * __ptr64,struct _DEVICE_OBJECT * __ptr64) */

long __cdecl NvdAddDevice(_DRIVER_OBJECT *param_1,_DEVICE_OBJECT *param_2)

{
  longlong *_Dst;
  uint uVar1;
  longlong lVar2;
  longlong local_res18 [2];
  
  local_res18[0] = 0;
  uVar1 = IoCreateDevice(param_1,0x210,0,0x5a,0x100,0,local_res18);
  if ((int)uVar1 < 0) {
    WriteTraceEvent((_NVDIMM_DEVICE_EXTENSION *)0x0,2,
                    "NvdAddDevice: IoCreateDevice failed with error: 0x%X\n",(ulonglong)uVar1);
  }
  else {
    _Dst = *(longlong **)(local_res18[0] + 0x40);
    memset(_Dst,0,0x210);
    _Dst[2] = (longlong)param_2;
    *_Dst = local_res18[0];
    lVar2 = IoAttachDeviceToDeviceStack(local_res18[0],param_2);
    _Dst[1] = lVar2;
    if (lVar2 == 0) {
      WriteTraceEvent((_NVDIMM_DEVICE_EXTENSION *)0x0,2,
                      "NvdAddDevice: Failed to attach device to device stack\n");
      uVar1 = 0xc000000e;
    }
    else {
      RtlInitUnicodeString(_Dst + 0x34,0);
      uVar1 = IoRegisterDeviceInterface
                        (param_2,&GUID_DEVINTERFACE_SCM_PHYSICAL_DEVICE,0,_Dst + 0x34);
      if (-1 < (int)uVar1) {
        IoInitializeRemoveLockEx(_Dst + 0x1e,0x6f70764e,1,5000,0x20);
        *(undefined4 *)((longlong)_Dst + 0xec) = 2;
        *(uint *)(local_res18[0] + 0x30) =
             *(uint *)(local_res18[0] + 0x30) | *(uint *)(param_2 + 0x30) & 0x2000;
        *(uint *)(local_res18[0] + 0x30) = *(uint *)(local_res18[0] + 0x30) | 0x10;
        *(uint *)(local_res18[0] + 0x30) = *(uint *)(local_res18[0] + 0x30) & 0xffffff7f;
        return uVar1;
      }
      WriteTraceEvent((_NVDIMM_DEVICE_EXTENSION *)0x0,2,
                      "NvdAddDevice: Failed to register device interface (0x%x)\n",(ulonglong)uVar1)
      ;
    }
    if (_Dst != (longlong *)0x0) {
      RtlFreeUnicodeString(_Dst + 0x34);
    }
  }
  if (local_res18[0] != 0) {
    IoDeleteDevice();
  }
  return uVar1;
}



===== NvdUnload @ 1c001b1d0 =====

/* void __cdecl NvdUnload(struct _DRIVER_OBJECT * __ptr64) */

void __cdecl NvdUnload(_DRIVER_OBJECT *param_1)

{
  undefined8 uVar1;
  
  McGenEventUnregister_EtwUnregister();
  uVar1 = DAT_1c0018078;
  DAT_1c0018078 = 0;
  DAT_1c0018058 = 0;
  EtwUnregister(uVar1);
  if (DAT_1c0018150 != 0) {
    ExFreePoolWithTag(DAT_1c0018150,0x6f70764e);
  }
  return;
}



===== _tlgEnableCallback @ 1c001b230 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _tlgEnableCallback(undefined8 param_1,int param_2,byte param_3,undefined8 param_4,
                       undefined8 param_5,undefined8 param_6,int *param_7)

{
  int iVar1;
  
  if (param_7 != (int *)0x0) {
    if (param_2 == 0) {
      *param_7 = 0;
    }
    else if (param_2 == 1) {
      if (param_3 == 0) {
        iVar1 = 0x100;
      }
      else {
        iVar1 = param_3 + 1;
      }
      *param_7 = iVar1;
      *(undefined8 *)(param_7 + 4) = param_4;
      *(undefined8 *)(param_7 + 6) = param_5;
    }
    if (*(code **)(param_7 + 10) != (code *)0x0) {
      (**(code **)(param_7 + 10))(param_1);
    }
  }
  return;
}



===== NvdCancelStopDevice @ 1c001b2b0 =====

/* long __cdecl NvdCancelStopDevice(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl NvdCancelStopDevice(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  NvdDeferProcessing(param_1,param_2);
  *(undefined4 *)(*(longlong *)(param_1 + 0x40) + 0xec) = 1;
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== NvdCreateSymbolicLinks @ 1c001b2fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl NvdCreateSymbolicLinks(struct _NVDIMM_DEVICE_EXTENSION * __ptr64) */

long __cdecl NvdCreateSymbolicLinks(_NVDIMM_DEVICE_EXTENSION *param_1)

{
  _NVDIMM_DEVICE_EXTENSION *p_Var1;
  long lVar2;
  undefined1 auStack_d8 [32];
  _NVDIMM_DEVICE_EXTENSION *local_b8;
  int local_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  ushort local_98 [64];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_d8;
  lVar2 = 0;
  if ((*(uint *)(param_1 + 0xe8) & 4) == 0) {
    memset(local_98,0,0x80);
    local_a8 = 0;
    uStack_a0 = 0;
    lVar2 = RtlStringCchPrintfW(local_98,0x3f,(ushort *)L"\\DosDevices\\PhysicalNvdimm%x",
                                (ulonglong)*(uint *)(param_1 + 0x20));
    if (-1 < lVar2) {
      RtlInitUnicodeString(&local_a8,local_98);
      p_Var1 = param_1 + 0x1a0;
      local_b8 = p_Var1;
      WriteTraceEvent(param_1,4,"NvdCreateSymbolicLinks: Linking %wZ to %wZ\n",&local_a8);
      lVar2 = IoCreateSymbolicLink(&local_a8,p_Var1);
      if (lVar2 < 0) {
        local_b8 = p_Var1;
        local_b0 = lVar2;
        WriteTraceEvent(param_1,2,
                        "NvdCreateSymbolicLinks: Error creating symbolic link from %wZ to %wZ (0x%x)"
                        ,&local_a8);
      }
      else {
        *(uint *)(param_1 + 0xe8) = *(uint *)(param_1 + 0xe8) | 4;
      }
    }
  }
  return lVar2;
}



===== NvdFreeResources @ 1c001b420 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl NvdFreeResources(struct _NVDIMM_DEVICE_EXTENSION * __ptr64) */

void __cdecl NvdFreeResources(_NVDIMM_DEVICE_EXTENSION *param_1)

{
  longlong *plVar1;
  undefined8 *puVar2;
  long lVar3;
  undefined1 auStack_c8 [32];
  undefined8 local_a8;
  undefined8 uStack_a0;
  ushort local_98 [64];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_c8;
  memset(local_98,0,0x80);
  local_a8 = 0;
  uStack_a0 = 0;
  if ((*(uint *)(param_1 + 0xe8) & 4) != 0) {
    lVar3 = RtlStringCchPrintfW(local_98,0x3f,(ushort *)L"\\DosDevices\\PhysicalNvdimm%x",
                                (ulonglong)*(uint *)(param_1 + 0x20));
    if (-1 < lVar3) {
      RtlInitUnicodeString(&local_a8,local_98);
      IoDeleteSymbolicLink(&local_a8);
    }
    *(uint *)(param_1 + 0xe8) = *(uint *)(param_1 + 0xe8) & 0xfffffffb;
  }
  IoSetDeviceInterfaceState(param_1 + 0x1a0,0);
  RtlFreeUnicodeString(param_1 + 0x1a0);
  RtlFreeUnicodeString(param_1 + 0x138);
  RtlFreeUnicodeString(param_1 + 0x148);
  if (*(longlong *)(param_1 + 0x188) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x188),0);
    *(undefined8 *)(param_1 + 0x188) = 0;
  }
  if (*(longlong *)(param_1 + 0x178) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x178),0);
    *(undefined8 *)(param_1 + 0x178) = 0;
  }
  if (*(longlong *)(param_1 + 0x180) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x180),0);
    *(undefined8 *)(param_1 + 0x180) = 0;
  }
  if (*(longlong *)(param_1 + 0x28) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x28),0);
    *(undefined8 *)(param_1 + 0x28) = 0;
  }
  plVar1 = *(longlong **)(param_1 + 0x18);
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 0x98))(plVar1,1);
    *(undefined8 *)(param_1 + 0x18) = 0;
  }
  puVar2 = *(undefined8 **)(param_1 + 0x1b8);
  if (puVar2 != (undefined8 *)0x0) {
    (**(code **)*puVar2)(puVar2,1);
    *(undefined8 *)(param_1 + 0x1b8) = 0;
  }
  return;
}



===== NvdQueryCapabilities @ 1c001b5f0 =====

/* long __cdecl NvdQueryCapabilities(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl NvdQueryCapabilities(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  longlong lVar1;
  longlong lVar2;
  long lVar3;
  longlong lVar4;
  longlong lVar5;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  lVar2 = *(longlong *)(param_1 + 0x40);
  lVar3 = NvdDeferProcessing(param_1,param_2);
  if (-1 < lVar3) {
    if (*(short *)(*(longlong *)(lVar1 + 8) + 2) == 1) {
      lVar4 = 0x10;
      *(undefined4 *)(lVar2 + 0x158) = *(undefined4 *)(*(longlong *)(lVar1 + 8) + 8);
      lVar5 = 7;
      *(undefined4 *)(lVar2 + 0x15c) = *(undefined4 *)(*(longlong *)(lVar1 + 8) + 0xc);
      do {
        *(undefined4 *)(lVar4 + 0x108 + lVar2) = *(undefined4 *)(lVar4 + *(longlong *)(lVar1 + 8));
        lVar4 = lVar4 + 4;
        lVar5 = lVar5 + -1;
      } while (lVar5 != 0);
      *(undefined4 *)(param_2 + 0x30) = 0;
      lVar3 = 0;
    }
    else {
      lVar3 = -0x3ffffff3;
      *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
    }
  }
  IofCompleteRequest(param_2,0);
  return lVar3;
}



===== NvdQueryInterface @ 1c001b6b0 =====

/* long __cdecl NvdQueryInterface(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl NvdQueryInterface(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  undefined8 *puVar1;
  void *pvVar2;
  int iVar3;
  
  puVar1 = *(undefined8 **)(param_2 + 0xb8);
  pvVar2 = *(void **)(param_1 + 0x40);
  if ((*(longlong *)puVar1[1] == 0x405e917e0079c21b) &&
     (((longlong *)puVar1[1])[1] == -0x4231444acdf83157)) {
    if ((((*(ushort *)(puVar1 + 2) < 0x70) || (*(short *)((longlong)puVar1 + 0x12) != 5)) ||
        (puVar1[3] == 0)) || (puVar1[4] != 0)) {
      iVar3 = -0x3ffffff3;
      *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
    }
    else {
      iVar3 = IoAcquireRemoveLockEx((longlong)pvVar2 + 0xf0,param_2,"",1,0x20);
      if (iVar3 < 0) {
        *(int *)(param_2 + 0x30) = iVar3;
      }
      else {
        puVar1 = (undefined8 *)puVar1[3];
        puVar1[2] = NvdInterfaceReference;
        puVar1[3] = NvdInterfaceDereference;
        puVar1[4] = NvdIntGetSlotNumber;
        puVar1[5] = NvdIntGetDeviceGuid;
        puVar1[6] = NvdIntGetUnsafeShutdownCount;
        puVar1[7] = NvdIntUnsafeShutdownAcknowledged;
        puVar1[8] = NvdIntGetDeviceManagementStatus;
        puVar1[9] = NvdIntRegisterNvdimmNotification;
        puVar1[10] = NvdIntUnregisterNvdimmNotification;
        puVar1[0xb] = NvdIntGetLocationString;
        puVar1[0xc] = NvdIntGetSecurityState;
        puVar1[0xd] = NvdIntGetFruIdString;
        *puVar1 = 0x50070;
        puVar1[1] = pvVar2;
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(int *)(param_2 + 0x30) = iVar3;
        NvdInterfaceReference(pvVar2);
        IoReleaseRemoveLockEx((longlong)pvVar2 + 0xf0,param_2,0x20);
      }
    }
    IofCompleteRequest(param_2,0);
  }
  else {
    puVar1[-9] = *puVar1;
    puVar1[-8] = puVar1[1];
    puVar1[-7] = puVar1[2];
    puVar1[-6] = puVar1[3];
    *(undefined4 *)(puVar1 + -5) = *(undefined4 *)(puVar1 + 4);
    *(undefined4 *)((longlong)puVar1 + -0x24) = *(undefined4 *)((longlong)puVar1 + 0x24);
    *(undefined4 *)(puVar1 + -4) = *(undefined4 *)(puVar1 + 5);
    *(undefined4 *)((longlong)puVar1 + -0x1c) = *(undefined4 *)((longlong)puVar1 + 0x2c);
    puVar1[-3] = puVar1[6];
    *(undefined1 *)((longlong)puVar1 + -0x45) = 0;
    iVar3 = IofCallDriver(*(undefined8 *)((longlong)pvVar2 + 8));
  }
  return iVar3;
}



===== NvdQueryPnPDeviceState @ 1c001b8b0 =====

/* long __cdecl NvdQueryPnPDeviceState(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl NvdQueryPnPDeviceState(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  _IRP *p_Var1;
  longlong lVar2;
  undefined8 *puVar3;
  longlong lVar4;
  long lVar5;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  p_Var1 = param_2 + 0x38;
  if ((*(uint *)(lVar2 + 0xe8) & 8) != 0) {
    *(ulonglong *)p_Var1 = *(ulonglong *)p_Var1 | 4;
    *(undefined4 *)(param_2 + 0x30) = 0;
  }
  if (*(int *)(lVar2 + 0xec) == 2) {
    *(ulonglong *)p_Var1 = *(ulonglong *)p_Var1 | 1;
    *(undefined4 *)(param_2 + 0x30) = 0;
  }
  if (*(int *)(lVar2 + 0x110) != 0) {
    *(ulonglong *)p_Var1 = *(ulonglong *)p_Var1 | 0x20;
  }
  puVar3 = *(undefined8 **)(param_2 + 0xb8);
  puVar3[-9] = *puVar3;
  puVar3[-8] = puVar3[1];
  puVar3[-7] = puVar3[2];
  puVar3[-6] = puVar3[3];
  *(undefined4 *)(puVar3 + -5) = *(undefined4 *)(puVar3 + 4);
  *(undefined4 *)((longlong)puVar3 + -0x24) = *(undefined4 *)((longlong)puVar3 + 0x24);
  *(undefined4 *)(puVar3 + -4) = *(undefined4 *)(puVar3 + 5);
  *(undefined4 *)((longlong)puVar3 + -0x1c) = *(undefined4 *)((longlong)puVar3 + 0x2c);
  puVar3[-3] = puVar3[6];
  *(undefined1 *)((longlong)puVar3 + -0x45) = 0;
  lVar4 = *(longlong *)(param_2 + 0xb8);
  *(code **)(lVar4 + -0x10) = NvdPnpDeviceStateCompletion;
  *(undefined8 *)(lVar4 + -8) = 0;
  *(undefined1 *)(lVar4 + -0x45) = 0xe0;
  lVar5 = IofCallDriver(*(undefined8 *)(lVar2 + 8));
  return lVar5;
}



===== NvdQueryRemoveDevice @ 1c001b960 =====

/* long __cdecl NvdQueryRemoveDevice(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl NvdQueryRemoveDevice(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  longlong lVar1;
  long lVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (*(int *)(lVar1 + 0x110) == 0) {
    if ((*(int *)(lVar1 + 0x1c0) == 0) &&
       (*(longlong **)(lVar1 + 0x1d0) == (longlong *)(lVar1 + 0x1d0))) {
      *(undefined4 *)(lVar1 + 0xec) = 4;
      lVar2 = 0;
    }
    else {
      lVar2 = -0x3fffffff;
    }
    *(long *)(param_2 + 0x30) = lVar2;
    if (lVar2 < 0) {
      IofCompleteRequest(param_2,0);
    }
    else {
      lVar1 = *(longlong *)(param_1 + 0x40);
      param_2[0x43] = (_IRP)((char)param_2[0x43] + '\x01');
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
      lVar2 = IofCallDriver(*(undefined8 *)(lVar1 + 8),param_2);
    }
  }
  else {
    lVar2 = -0x3fffffff;
  }
  return lVar2;
}



===== NvdQueryStopDevice @ 1c001ba00 =====

/* long __cdecl NvdQueryStopDevice(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl NvdQueryStopDevice(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  longlong lVar1;
  long lVar2;
  
  *(undefined4 *)(*(longlong *)(param_1 + 0x40) + 0xec) = 3;
  *(undefined4 *)(param_2 + 0x30) = 0;
  lVar1 = *(longlong *)(param_1 + 0x40);
  param_2[0x43] = (_IRP)((char)param_2[0x43] + '\x01');
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  lVar2 = IofCallDriver(*(undefined8 *)(lVar1 + 8));
  return lVar2;
}



===== NvdReadRegistrySettings @ 1c001ba44 =====

/* void __cdecl NvdReadRegistrySettings(struct _NVDIMM_DEVICE_EXTENSION * __ptr64) */

void __cdecl NvdReadRegistrySettings(_NVDIMM_DEVICE_EXTENSION *param_1)

{
  long lVar1;
  _NVDIMM_DEVICE_EXTENSION *p_Var2;
  ushort *in_RDX;
  ulong local_res8 [2];
  
  p_Var2 = param_1;
  lVar1 = NvdQueryDriverRegistryUlong
                    (param_1,in_RDX,(ushort *)L"BringUpMode",(ulong *)(param_1 + 500));
  if (lVar1 < 0) {
    *(ulong *)(param_1 + 500) = 0;
  }
  lVar1 = NvdQueryDriverRegistryUlong
                    (p_Var2,in_RDX,(ushort *)L"DisableTimer",(ulong *)(param_1 + 0x1f8));
  if (lVar1 < 0) {
    *(ulong *)(param_1 + 0x1f8) = 0;
  }
  lVar1 = NvdQueryDeviceRegistryUlong
                    (param_1,(ushort *)L"",(ushort *)L"ErrInj_FailFirstNHealthChecks_Retriable",
                     (ulong *)(param_1 + 0x1e8));
  if (lVar1 < 0) {
    *(ulong *)(param_1 + 0x1e8) = 0;
  }
  lVar1 = NvdQueryDeviceRegistryUlong
                    (param_1,(ushort *)L"",(ushort *)L"ErrInj_FailNHealthChecks_NonRetriable",
                     (ulong *)(param_1 + 0x1ec));
  if (lVar1 < 0) {
    *(ulong *)(param_1 + 0x1ec) = 0;
  }
  lVar1 = NvdQueryDeviceRegistryUlong
                    (param_1,(ushort *)L"",(ushort *)L"ErrInj_FailHealthChecks_NonRetriableDelay",
                     (ulong *)(param_1 + 0x1f0));
  if (lVar1 < 0) {
    *(ulong *)(param_1 + 0x1f0) = 0;
  }
  local_res8[0] = 0;
  lVar1 = NvdQueryDeviceRegistryUlong
                    (param_1,(ushort *)0x0,(ushort *)L"EnableSecurityIfPassphrasePresent",local_res8
                    );
  if (lVar1 < 0) {
    *(uint *)(param_1 + 0x1fc) = *(uint *)(param_1 + 0x1fc) | 1;
  }
  else {
    *(uint *)(param_1 + 0x1fc) =
         *(uint *)(param_1 + 0x1fc) & 0xfffffffe | (uint)(local_res8[0] != 0);
  }
  return;
}



===== NvdRemoveDevice @ 1c001bb60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl NvdRemoveDevice(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl NvdRemoveDevice(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  _NVDIMM_DEVICE_EXTENSION *p_Var1;
  _NVDIMM_DEVICE_EXTENSION *p_Var2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  long lVar6;
  
  p_Var2 = *(_NVDIMM_DEVICE_EXTENSION **)(param_1 + 0x40);
  *(undefined4 *)(p_Var2 + 0xec) = 6;
  *(undefined4 *)(param_2 + 0x30) = 0;
  if ((*(uint *)(p_Var2 + 0xe8) & 0x20) != 0) {
    (**(code **)(p_Var2 + 200))(*(undefined8 *)(p_Var2 + 0x58),NvdNotificationCallback);
  }
  if (*(code **)(p_Var2 + 0x68) != (code *)0x0) {
    (**(code **)(p_Var2 + 0x68))(*(undefined8 *)(p_Var2 + 0x58));
  }
  lVar3 = *(longlong *)(param_1 + 0x40);
  param_2[0x43] = (_IRP)((char)param_2[0x43] + '\x01');
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  lVar6 = IofCallDriver(*(undefined8 *)(lVar3 + 8),param_2);
  if (*(NvdimmTelemetry **)(p_Var2 + 0x1b8) != (NvdimmTelemetry *)0x0) {
    NvdimmTelemetry::DeviceRemoved(*(NvdimmTelemetry **)(p_Var2 + 0x1b8));
  }
  IoReleaseRemoveLockAndWaitEx(p_Var2 + 0xf0,param_2,0x20);
  NvdFreeResources(p_Var2);
  KeFlushQueuedDpcs();
  if ((*(uint *)(p_Var2 + 0xe8) & 1) == 0) {
    PoSetPowerState(param_1,1,4);
    *(undefined4 *)(p_Var2 + 0x114) = 1;
  }
  p_Var1 = p_Var2 + 0x200;
  lVar3 = *(longlong *)p_Var1;
  if ((lVar3 != 0) && (plVar4 = *(longlong **)(p_Var2 + 0x208), plVar4 != (longlong *)0x0)) {
    if ((*(_NVDIMM_DEVICE_EXTENSION **)(lVar3 + 8) != p_Var1) ||
       ((_NVDIMM_DEVICE_EXTENSION *)*plVar4 != p_Var1)) {
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      pcVar5 = (code *)swi(3);
      lVar6 = (*pcVar5)();
      return lVar6;
    }
    *plVar4 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar4;
  }
  *(_NVDIMM_DEVICE_EXTENSION **)(p_Var2 + 0x208) = p_Var1;
  *(_NVDIMM_DEVICE_EXTENSION **)p_Var1 = p_Var1;
  IoDetachDevice(*(undefined8 *)(p_Var2 + 8));
  *(undefined8 *)(p_Var2 + 8) = 0;
  IoDeleteDevice(param_1);
  return lVar6;
}



===== NvdStartDevice @ 1c001bcd0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl NvdStartDevice(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl NvdStartDevice(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  _NVDIMM_DEVICE_EXTENSION *p_Var1;
  _NVDIMM_DEVICE_EXTENSION *p_Var2;
  code *pcVar3;
  uint uVar4;
  int iVar5;
  NvdimmTelemetry *pNVar6;
  Nvdimm *pNVar7;
  longlong lVar8;
  _NVDIMM_DEVICE_EXTENSION *p_Var9;
  _IRP *p_Var10;
  undefined8 *puVar11;
  short *psVar12;
  undefined **ppuVar13;
  undefined1 *puVar14;
  _NVDIMM_START_DEVICE_FAILURE _Var15;
  undefined1 auStackY_1d8 [8];
  undefined1 auStackY_1d0 [24];
  char local_178 [8];
  undefined8 local_170;
  undefined8 uStack_168;
  undefined8 local_160;
  undefined8 uStack_158;
  short local_148 [128];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1d8;
  p_Var2 = *(_NVDIMM_DEVICE_EXTENSION **)(param_1 + 0x40);
  _Var15 = 0;
  local_160 = 0;
  uStack_158 = 0;
  IoGetActivityIdIrp(param_2,&local_160);
  uVar4 = NvdDeferProcessing(param_1,param_2);
  if ((int)uVar4 < 0) {
    _Var15 = 10;
  }
  else {
    NvdReadRegistrySettings(p_Var2);
    PoSetPowerState(param_1,1,1);
    *(undefined4 *)(p_Var2 + 0x114) = 1;
    *(undefined4 *)(p_Var2 + 0xec) = 1;
    uVar4 = NvdGetBusInterface(p_Var2,(_SCM_BUS_NVD_INTERFACE *)(p_Var2 + 0x50));
    if ((int)uVar4 < 0) {
      _Var15 = 1;
    }
    else {
      KeInitializeSpinLock(p_Var2 + 0x1c8);
      p_Var9 = p_Var2 + 0x1d0;
      *(_NVDIMM_DEVICE_EXTENSION **)(p_Var2 + 0x1d8) = p_Var9;
      *(_NVDIMM_DEVICE_EXTENSION **)p_Var9 = p_Var9;
      uVar4 = (**(code **)(p_Var2 + 0x70))(*(undefined8 *)(p_Var2 + 0x58),p_Var2 + 0x20);
      if ((int)uVar4 < 0) {
        _Var15 = 0xb;
      }
      else {
        (**(code **)(p_Var2 + 0xa8))(*(undefined8 *)(p_Var2 + 0x58),p_Var2 + 0x24);
        p_Var9 = p_Var2 + 0x28;
        p_Var1 = p_Var2 + 0x26;
        uVar4 = (**(code **)(p_Var2 + 0x98))(*(undefined8 *)(p_Var2 + 0x58),p_Var1,p_Var9);
        if ((int)uVar4 < 0) {
          _Var15 = 0xf;
        }
        else {
          iVar5 = (**(code **)(p_Var2 + 0x90))(*(undefined8 *)(p_Var2 + 0x58),p_Var2 + 0x134);
          if (iVar5 < 0) {
            *(undefined4 *)(p_Var2 + 0x134) = 0xffffffff;
          }
          uVar4 = NvdGetIdentifyingInfo(p_Var2);
          if ((int)uVar4 < 0) {
            _Var15 = 2;
          }
          else {
            uVar4 = NvdCreateDeviceGuid(p_Var2,(_GUID *)(p_Var2 + 400));
            if ((int)uVar4 < 0) {
              _Var15 = 3;
            }
            else {
              uVar4 = (**(code **)(p_Var2 + 0xa0))
                                (*(undefined8 *)(p_Var2 + 0x58),p_Var2 + 0x30,p_Var2 + 0x38,
                                 p_Var2 + 0x40);
              if ((int)uVar4 < 0) {
                _Var15 = 0x10;
              }
              else {
                uVar4 = NvdCreateSymbolicLinks(p_Var2);
                if ((int)uVar4 < 0) {
                  _Var15 = 4;
                }
                else {
                  uVar4 = (**(code **)(p_Var2 + 0xb8))(*(undefined8 *)(p_Var2 + 0x58),p_Var2 + 0xe0)
                  ;
                  if (((int)uVar4 < 0) && (*(int *)(p_Var2 + 500) == 0)) {
                    _Var15 = 0xd;
                  }
                  else {
                    if (p_Var2[0xe5] != (_NVDIMM_DEVICE_EXTENSION)0x0) {
                      WriteTraceEvent(p_Var2,2,
                                      "The NoSPAMapping bit is set, meaning that the platform didn\'t map the contents of this NVDIMM into virtual memory."
                                     );
                    }
                    pNVar6 = NvdimmTelemetry::Create(p_Var2,(uchar)*p_Var1,*(ushort **)p_Var9);
                    *(NvdimmTelemetry **)(p_Var2 + 0x1b8) = pNVar6;
                    if (pNVar6 == (NvdimmTelemetry *)0x0) {
                      _Var15 = 0x11;
                      uVar4 = 0xc0000001;
                    }
                    else {
                      pNVar7 = NvdimmFactory::MakeNvdimmObject
                                         (p_Var2,(uchar)*p_Var1,*(ushort **)p_Var9);
                      *(Nvdimm **)(p_Var2 + 0x18) = pNVar7;
                      if (pNVar7 == (Nvdimm *)0x0) {
                        _Var15 = 0xe;
LAB_1c001bf42:
                        uVar4 = 0xc00000bb;
                      }
                      else {
                        uVar4 = (*(code *)**(undefined8 **)pNVar7)(pNVar7);
                        if ((int)uVar4 < 0) {
                          _Var15 = 0xe;
                          goto LAB_1c001c132;
                        }
                        local_178[0] = '\0';
                        uVar4 = (**(code **)(p_Var2 + 0x80))
                                          (*(undefined8 *)(p_Var2 + 0x58),1,local_178);
                        if ((int)uVar4 < 0) {
                          WriteTraceEvent(p_Var2,2,
                                          "NvdStartDevice: NvdNotificationSupported() failed with 0x%x"
                                          ,(ulonglong)uVar4);
LAB_1c001bfbe:
                          if ((local_178[0] == '\0') && (*(int *)(p_Var2 + 500) == 0)) {
                            _Var15 = 7;
                            goto LAB_1c001bf42;
                          }
                        }
                        else if (local_178[0] == '\0') {
                          WriteTraceEvent(p_Var2,2,
                                          "NvdStartDevice: NvdNotificationSupported() ACPI notifications are not supported"
                                         );
                          goto LAB_1c001bfbe;
                        }
                        uVar4 = (**(code **)(p_Var2 + 0xc0))
                                          (*(undefined8 *)(p_Var2 + 0x58),NvdNotificationCallback,
                                           p_Var2);
                        if (((int)uVar4 < 0) && (*(int *)(p_Var2 + 500) == 0)) {
                          _Var15 = 7;
                        }
                        else {
                          *(uint *)(p_Var2 + 0xe8) = *(uint *)(p_Var2 + 0xe8) | 0x20;
                          uVar4 = (**(code **)(p_Var2 + 0xd0))
                                            (*(undefined8 *)(p_Var2 + 0x58),1,p_Var2 + 0x48);
                          if ((int)uVar4 < 0) {
                            WriteTraceEvent(p_Var2,3,
                                            "NvdStartDevice: NvdGetBadMemoryRangesInfo() failed with 0x%x"
                                            ,(ulonglong)uVar4);
                          }
                          if (*(int *)(p_Var2 + 0x48) != 0) {
                            WriteTraceEvent(p_Var2,2,
                                            "NvdNotification(): %d bad memory ranges detected on NVDIMM 0x%x"
                                           );
                          }
                          (**(code **)(**(longlong **)(p_Var2 + 0x18) + 0x20))();
                          memset(local_148,0,0x100);
                          iVar5 = (**(code **)(**(longlong **)(p_Var2 + 0x18) + 8))
                                            (*(longlong **)(p_Var2 + 0x18),local_148,0x100);
                          if (-1 < iVar5) {
                            lVar8 = 0x80;
                            psVar12 = local_148;
                            do {
                              if (*psVar12 == 0) break;
                              psVar12 = psVar12 + 1;
                              lVar8 = lVar8 + -1;
                            } while (lVar8 != 0);
                            IoSetDevicePropertyData
                                      (*(undefined8 *)(p_Var2 + 0x10),&DEVPKEY_Device_DeviceDesc,0,0
                                      );
                          }
                          uVar4 = IoSetDeviceInterfaceState(p_Var2 + 0x1a0,1);
                          if (-1 < (int)uVar4) {
                            if (*(int *)(p_Var2 + 500) != 0) {
                              WriteTraceEvent(p_Var2,3,
                                              "NvdStartDevice: the device is in bring up mode - overriding status 0x%x with STATUS_SUCCESS"
                                              ,(ulonglong)uVar4);
                              uVar4 = 0;
                            }
                            puVar14 = auStackY_1d8;
                            ppuVar13 = &g_AllFdosList;
                            p_Var9 = p_Var2 + 0x200;
                            puVar11 = (undefined8 *)PTR_g_AllFdosList_1c0018050;
                            if (*(undefined ***)PTR_g_AllFdosList_1c0018050 != &g_AllFdosList) {
                              puVar11 = (undefined8 *)0x3;
                              pcVar3 = (code *)swi(0x29);
                              p_Var9 = (_NVDIMM_DEVICE_EXTENSION *)(*pcVar3)();
                              puVar14 = auStackY_1d0;
                            }
                            *(undefined ***)p_Var9 = ppuVar13;
                            *(undefined8 **)(p_Var9 + 8) = puVar11;
                            *puVar11 = p_Var9;
                            PTR_g_AllFdosList_1c0018050 = p_Var9;
                            if ((Microsoft_Windows_PersistentMemory_NvdimmEnableBits & 2) != 0) {
                              *(undefined8 *)(puVar14 + 0x40) = *(undefined8 *)(p_Var2 + 0x140);
                              *(undefined8 *)(puVar14 + 0x38) = *(undefined8 *)(p_Var2 + 0x188);
                              *(undefined8 *)(puVar14 + 0x30) = *(undefined8 *)(p_Var2 + 0x180);
                              *(undefined8 *)(puVar14 + 0x28) = *(undefined8 *)(p_Var2 + 0x178);
                              *(undefined4 *)(puVar14 + 0x20) = *(undefined4 *)(p_Var2 + 0x20);
                              *(undefined8 *)(puVar14 + -8) = 0x1c001c25d;
                              McTemplateK0jdsssz_EtwWriteTransfer
                                        (puVar11,ppuVar13,puVar14 + 0x78,p_Var2 + 400,puVar14[0x20],
                                         *(char **)(puVar14 + 0x28),*(char **)(puVar14 + 0x30),
                                         *(char **)(puVar14 + 0x38),*(wchar_t **)(puVar14 + 0x40));
                            }
                            goto LAB_1c001c25d;
                          }
                          _Var15 = 0xc;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_1c001c132:
  local_170 = 0;
  uStack_168 = 0;
  p_Var10 = param_2;
  IoGetActivityIdIrp(param_2,&local_170);
  puVar14 = auStackY_1d8;
  if ((Microsoft_Windows_PersistentMemory_NvdimmEnableBits & 1) != 0) {
    McTemplateK0jdssszqq_EtwWriteTransfer
              (p_Var10,&EventStartDeviceFailed,&local_170,p_Var2 + 400,
               (char)*(undefined4 *)(p_Var2 + 0x20),*(char **)(p_Var2 + 0x178),
               *(char **)(p_Var2 + 0x180),*(char **)(p_Var2 + 0x188),*(wchar_t **)(p_Var2 + 0x140),
               (char)_Var15,(char)uVar4);
    puVar14 = auStackY_1d8;
  }
LAB_1c001c25d:
  pNVar6 = *(NvdimmTelemetry **)(p_Var2 + 0x1b8);
  if (pNVar6 != (NvdimmTelemetry *)0x0) {
    *(undefined8 *)(puVar14 + -8) = 0x1c001c273;
    NvdimmTelemetry::DeviceStarted(pNVar6,uVar4,_Var15);
  }
  *(uint *)(param_2 + 0x30) = uVar4;
  *(undefined8 *)(puVar14 + -8) = 0x1c001c283;
  IofCompleteRequest(param_2,0);
  *(undefined8 *)(puVar14 + -8) = 0x1c001c299;
  return uVar4;
}



===== NvdStopDevice @ 1c001c2c0 =====

/* long __cdecl NvdStopDevice(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl NvdStopDevice(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  longlong lVar1;
  long lVar2;
  
  *(undefined4 *)(*(longlong *)(param_1 + 0x40) + 0xec) = 2;
  *(undefined4 *)(param_2 + 0x30) = 0;
  lVar1 = *(longlong *)(param_1 + 0x40);
  param_2[0x43] = (_IRP)((char)param_2[0x43] + '\x01');
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  lVar2 = IofCallDriver(*(undefined8 *)(lVar1 + 8));
  return lVar2;
}



===== NvdSurpriseRemoveDevice @ 1c001c310 =====

/* long __cdecl NvdSurpriseRemoveDevice(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl NvdSurpriseRemoveDevice(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  uint *puVar1;
  longlong lVar2;
  long lVar3;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  puVar1 = (uint *)(lVar2 + 0xe8);
  *puVar1 = *puVar1 | 1;
  *(undefined4 *)(lVar2 + 0xec) = 5;
  *(undefined4 *)(param_2 + 0x30) = 0;
  lVar2 = *(longlong *)(param_1 + 0x40);
  param_2[0x43] = (_IRP)((char)param_2[0x43] + '\x01');
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  lVar3 = IofCallDriver(*(undefined8 *)(lVar2 + 8));
  return lVar3;
}



===== NvdDeviceInfoIoctl @ 1c001c358 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl NvdDeviceInfoIoctl(struct _NVDIMM_DEVICE_EXTENSION * __ptr64,struct _IRP *
   __ptr64,struct _SCM_PD_PROPERTY_QUERY * __ptr64) */

long __cdecl
NvdDeviceInfoIoctl(_NVDIMM_DEVICE_EXTENSION *param_1,_IRP *param_2,_SCM_PD_PROPERTY_QUERY *param_3)

{
  _NVDIMM_DEVICE_EXTENSION _Var1;
  undefined4 *_Dst;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  long lVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  longlong lVar9;
  size_t _Size;
  uint uVar10;
  
  if (*(int *)(param_3 + 0xc) == 1) {
    lVar5 = 0;
  }
  else if (*(int *)(param_3 + 0xc) == 0) {
    uVar7 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
    if (7 < uVar7) {
      pcVar8 = *(char **)(param_1 + 0x188);
      _Size = 0;
      if (pcVar8 != (char *)0x0) {
        lVar9 = 0x7fffffff;
        do {
          if (*pcVar8 == '\0') break;
          pcVar8 = pcVar8 + 1;
          lVar9 = lVar9 + -1;
        } while (lVar9 != 0);
        if (lVar9 == 0) {
          _Size = 0;
        }
        else {
          _Size = (-(ulonglong)(lVar9 != 0) & 0x7fffffffU - lVar9) + 1;
        }
      }
      _Dst = *(undefined4 **)(param_2 + 0x18);
      uVar6 = (int)_Size + 0x70;
      uVar10 = 0x78;
      if (0x78 < uVar6) {
        uVar10 = uVar6;
      }
      memset(_Dst,0,(ulonglong)uVar7);
      *_Dst = 0x78;
      _Dst[1] = uVar10;
      if (uVar7 < uVar10) {
        *(undefined8 *)(param_2 + 0x38) = 8;
        return 0;
      }
      uVar2 = *(undefined4 *)(param_1 + 0x194);
      uVar3 = *(undefined4 *)(param_1 + 0x198);
      uVar4 = *(undefined4 *)(param_1 + 0x19c);
      _Dst[2] = *(undefined4 *)(param_1 + 400);
      _Dst[3] = uVar2;
      _Dst[4] = uVar3;
      _Dst[5] = uVar4;
      *(undefined8 *)(_Dst + 8) = *(undefined8 *)(param_1 + 0x30);
      *(undefined8 *)(_Dst + 10) = *(undefined8 *)(param_1 + 0x38);
      *(undefined8 *)(_Dst + 0xc) = *(undefined8 *)(param_1 + 0x40);
      _Dst[0xe] = *(undefined4 *)(param_1 + 0x134);
      _Dst[0xf] = *(undefined4 *)(param_1 + 0x20);
      *(undefined2 *)(_Dst + 0x10) = *(undefined2 *)(param_1 + 0x24);
      uVar7 = (**(code **)(**(longlong **)(param_1 + 0x18) + 0x10))
                        (*(longlong **)(param_1 + 0x18),_Dst + 6);
      if ((int)uVar7 < 0) {
        WriteTraceEvent(param_1,3,
                        "NvdDeviceInfoIoctl: Nvdimm->GetUnsafeShutdownCount() failed with 0x%x",
                        (ulonglong)uVar7);
      }
      else {
        _Var1 = param_1[0x26];
        *(_NVDIMM_DEVICE_EXTENSION *)((longlong)_Dst + 0x42) = _Var1;
        if (8 < (byte)_Var1) {
          return -0x3ffffff3;
        }
        memcpy(_Dst + 0x11,*(void **)(param_1 + 0x28),(ulonglong)(byte)_Var1 * 2);
        _Dst[0x15] = *(undefined4 *)(param_1 + 0x160);
        _Dst[0x16] = *(undefined4 *)(param_1 + 0x164);
        _Dst[0x17] = *(undefined4 *)(param_1 + 0x168);
        _Dst[0x18] = *(undefined4 *)(param_1 + 0x16c);
        *(_NVDIMM_DEVICE_EXTENSION *)(_Dst + 0x19) = param_1[0x170];
        *(_NVDIMM_DEVICE_EXTENSION *)((longlong)_Dst + 0x65) = param_1[0x171];
        *(_NVDIMM_DEVICE_EXTENSION *)((longlong)_Dst + 0x66) = param_1[0x172];
        _Dst[0x1a] = *(undefined4 *)(param_1 + 0x174);
        _Dst[0x1b] = (int)_Size;
        memcpy(_Dst + 0x1c,*(void **)(param_1 + 0x188),_Size);
        *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar10;
      }
      return uVar7;
    }
    lVar5 = -0x3fffffdd;
  }
  else {
    lVar5 = -0x3fffff45;
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
  return lVar5;
}



===== NvdDeviceSpecificInfoIoctl @ 1c001c54c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl NvdDeviceSpecificInfoIoctl(struct _NVDIMM_DEVICE_EXTENSION * __ptr64,struct _IRP *
   __ptr64,struct _SCM_PD_PROPERTY_QUERY * __ptr64) */

long __cdecl
NvdDeviceSpecificInfoIoctl
          (_NVDIMM_DEVICE_EXTENSION *param_1,_IRP *param_2,_SCM_PD_PROPERTY_QUERY *param_3)

{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  uint uVar4;
  void *local_res18;
  
  iVar1 = *(int *)(param_3 + 0xc);
  *(undefined8 *)(param_2 + 0x38) = 0;
  if (iVar1 == 1) {
    uVar4 = 0;
  }
  else if (iVar1 == 0) {
    uVar2 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
    if (uVar2 < 8) {
      uVar4 = 0xc0000023;
    }
    else {
      local_res18 = (void *)0x0;
      uVar4 = (**(code **)(**(longlong **)(param_1 + 0x18) + 0x30))
                        (*(longlong **)(param_1 + 0x18),&local_res18);
      if ((int)uVar4 < 0) {
        WriteTraceEvent(param_1,2,
                        "NvdDeviceSpecificInfoIoctl: GetDeviceSpecificInfo() failed with NTSTATUS 0x%x"
                        ,(ulonglong)uVar4);
      }
      else {
        if (*(uint *)((longlong)local_res18 + 4) <= uVar2) {
          uVar2 = *(uint *)((longlong)local_res18 + 4);
        }
        memcpy(*(void **)(param_2 + 0x18),local_res18,(ulonglong)uVar2);
        *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar2;
      }
      pvVar3 = local_res18;
      local_res18 = (void *)0x0;
      if (pvVar3 != (void *)0x0) {
        operator_delete(pvVar3);
      }
    }
  }
  else {
    uVar4 = 0xc00000bb;
  }
  return uVar4;
}



===== NvdFirmwareActivateIoctl @ 1c001c62c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl NvdFirmwareActivateIoctl(struct _NVDIMM_DEVICE_EXTENSION * __ptr64,struct _IRP *
   __ptr64,unsigned char * __ptr64) */

long __cdecl
NvdFirmwareActivateIoctl(_NVDIMM_DEVICE_EXTENSION *param_1,_IRP *param_2,uchar *param_3)

{
  longlong lVar1;
  byte bVar2;
  uint uVar3;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  *param_3 = '\0';
  if (*(uint *)(lVar1 + 0x10) < 0x10) {
    WriteTraceEvent(param_1,2,"NvdFirmwareActivateIoctl: Input buffer too small.\n");
    uVar3 = 0xc000000d;
  }
  else {
    bVar2 = KeGetCurrentIrql();
    if (bVar2 < 2) {
      uVar3 = (**(code **)(**(longlong **)(param_1 + 0x18) + 0x50))
                        (*(longlong **)(param_1 + 0x18),
                         CONCAT71((int7)((ulonglong)*(longlong *)(param_2 + 0x18) >> 8),
                                  *(undefined1 *)(*(longlong *)(param_2 + 0x18) + 0xc)));
      if ((int)uVar3 < 0) {
        WriteTraceEvent(param_1,2,
                        "NvdFirmwareActivateIoctl: NvdnSelectFirmwareImageSlot failed with status 0x%x.\n"
                        ,(ulonglong)uVar3);
      }
    }
    else {
      WriteTraceEvent(param_1,3,"NvdFirmwareActivateIoctl: Called at invalid IRQL.\n");
      *(undefined8 *)(param_2 + 0x38) = 0;
      uVar3 = 0xc0000148;
    }
  }
  return uVar3;
}



===== NvdFirmwareDownloadIoctl @ 1c001c6e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl NvdFirmwareDownloadIoctl(struct _NVDIMM_DEVICE_EXTENSION * __ptr64,struct _IRP *
   __ptr64,unsigned char * __ptr64) */

long __cdecl
NvdFirmwareDownloadIoctl(_NVDIMM_DEVICE_EXTENSION *param_1,_IRP *param_2,uchar *param_3)

{
  longlong lVar1;
  byte bVar2;
  int iVar3;
  undefined8 uVar4;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  *param_3 = '\0';
  if (*(uint *)(lVar1 + 0x10) < 0x20) {
    WriteTraceEvent(param_1,2,"NvdFirmwareDownloadIoctl: Input buffer too small.\n");
    iVar3 = -0x3ffffff3;
  }
  else {
    bVar2 = KeGetCurrentIrql();
    if (bVar2 < 2) {
      lVar1 = *(longlong *)(param_2 + 0x18);
      uVar4 = *(undefined8 *)(lVar1 + 0x10);
      iVar3 = (**(code **)(**(longlong **)(param_1 + 0x18) + 0x48))
                        (*(longlong **)(param_1 + 0x18),
                         CONCAT71((int7)((ulonglong)uVar4 >> 8),*(undefined1 *)(lVar1 + 0xc)),
                         lVar1 + 0x1c,*(undefined4 *)(lVar1 + 0x18),uVar4,*(byte *)(lVar1 + 8) & 1);
      if (iVar3 < 0) {
        WriteTraceEvent(param_1,2,
                        "NvdFirmwareDownloadIoctl: Firmware update to slot %d failed with status 0x%x.\n"
                        ,(ulonglong)*(byte *)(lVar1 + 0xc),
                        CONCAT44((int)((ulonglong)uVar4 >> 0x20),iVar3));
      }
    }
    else {
      WriteTraceEvent(param_1,3,"NvdFirmwareDownloadIoctl: Called at invalid IRQL.\n");
      *(undefined8 *)(param_2 + 0x38) = 0;
      iVar3 = -0x3ffffeb8;
    }
  }
  return iVar3;
}



===== NvdFirmwareInfoIoctl @ 1c001c7c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl NvdFirmwareInfoIoctl(struct _NVDIMM_DEVICE_EXTENSION * __ptr64,struct _IRP *
   __ptr64,struct _SCM_PD_PROPERTY_QUERY * __ptr64) */

long __cdecl
NvdFirmwareInfoIoctl
          (_NVDIMM_DEVICE_EXTENSION *param_1,_IRP *param_2,_SCM_PD_PROPERTY_QUERY *param_3)

{
  uint uVar1;
  void *pvVar2;
  long lVar3;
  uint uVar4;
  void *local_res18;
  
  if (*(int *)(param_3 + 0xc) == 1) {
    lVar3 = 0;
  }
  else if (*(int *)(param_3 + 0xc) == 0) {
    uVar1 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
    if (7 < uVar1) {
      local_res18 = (void *)0x0;
      uVar4 = (**(code **)(**(longlong **)(param_1 + 0x18) + 0x40))
                        (*(longlong **)(param_1 + 0x18),&local_res18,0,0,0);
      if ((int)uVar4 < 0) {
        WriteTraceEvent(param_1,3,"NvdFirmwareInfoIoctl: Nvdimm->GetFirmwareInfo() failed with 0x%x"
                        ,(ulonglong)uVar4);
      }
      else {
        if (*(uint *)((longlong)local_res18 + 4) <= uVar1) {
          uVar1 = *(uint *)((longlong)local_res18 + 4);
        }
        memcpy(*(void **)(param_2 + 0x18),local_res18,(ulonglong)uVar1);
        *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar1;
      }
      pvVar2 = local_res18;
      local_res18 = (void *)0x0;
      if (pvVar2 != (void *)0x0) {
        operator_delete(pvVar2);
      }
      return uVar4;
    }
    lVar3 = -0x3fffffdd;
  }
  else {
    lVar3 = -0x3fffff45;
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
  return lVar3;
}



===== NvdFruIdStringIoctl @ 1c001c8a8 =====

/* long __cdecl NvdFruIdStringIoctl(struct _NVDIMM_DEVICE_EXTENSION * __ptr64,struct _IRP *
   __ptr64,struct _SCM_PD_PROPERTY_QUERY * __ptr64) */

long __cdecl
NvdFruIdStringIoctl(_NVDIMM_DEVICE_EXTENSION *param_1,_IRP *param_2,_SCM_PD_PROPERTY_QUERY *param_3)

{
  uint uVar1;
  undefined4 *_Dst;
  int iVar2;
  long lVar3;
  char *pcVar4;
  longlong lVar5;
  ulonglong _Size;
  uint uVar6;
  uint uVar7;
  
  if (*(int *)(param_3 + 0xc) == 1) {
    lVar3 = 0;
  }
  else if (*(int *)(param_3 + 0xc) == 0) {
    uVar1 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
    if (7 < uVar1) {
      pcVar4 = *(char **)(param_1 + 0x188);
      if (pcVar4 == (char *)0x0) {
        uVar6 = 0xc000000d;
      }
      else {
        lVar5 = 0x7fffffff;
        do {
          if (*pcVar4 == '\0') break;
          pcVar4 = pcVar4 + 1;
          lVar5 = lVar5 + -1;
        } while (lVar5 != 0);
        uVar6 = ~-(uint)(lVar5 != 0) & 0xc000000d;
        _Size = -(ulonglong)(lVar5 != 0) & 0x7fffffffU - lVar5;
        if (lVar5 != 0) {
          _Dst = *(undefined4 **)(param_2 + 0x18);
          iVar2 = (int)_Size;
          uVar7 = iVar2 + 0xc;
          memset(_Dst,0,(ulonglong)uVar1);
          *_Dst = 0x10;
          _Dst[1] = uVar7;
          if (uVar1 < uVar7) {
            *(undefined8 *)(param_2 + 0x38) = 8;
            return 0;
          }
          _Dst[2] = iVar2;
          memcpy(_Dst + 3,*(void **)(param_1 + 0x188),_Size);
          *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar7;
        }
      }
      return uVar6;
    }
    lVar3 = -0x3fffffdd;
  }
  else {
    lVar3 = -0x3fffff45;
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
  return lVar3;
}



===== NvdGetRuntimeFirmwareActivationInfoIoctl @ 1c001c9c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl NvdGetRuntimeFirmwareActivationInfoIoctl(struct _NVDIMM_DEVICE_EXTENSION *
   __ptr64,struct _IRP * __ptr64,struct _SCM_PD_PROPERTY_QUERY * __ptr64) */

long __cdecl
NvdGetRuntimeFirmwareActivationInfoIoctl
          (_NVDIMM_DEVICE_EXTENSION *param_1,_IRP *param_2,_SCM_PD_PROPERTY_QUERY *param_3)

{
  undefined4 *_Dst;
  long lVar1;
  uint uVar2;
  undefined8 uVar3;
  
  if (*(int *)(param_3 + 8) == 7) {
    if (*(int *)(param_3 + 0xc) == 1) {
      lVar1 = 0;
    }
    else if (*(int *)(param_3 + 0xc) == 0) {
      uVar2 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
      if (7 < uVar2) {
        _Dst = *(undefined4 **)(param_2 + 0x18);
        memset(_Dst,0,(ulonglong)uVar2);
        uVar3 = 0x10;
        *_Dst = 0x10;
        _Dst[1] = 0x10;
        if (uVar2 < 0x10) {
          *(undefined8 *)(param_2 + 0x38) = 8;
          return 0;
        }
        uVar2 = (**(code **)(**(longlong **)(param_1 + 0x18) + 0x68))
                          (*(longlong **)(param_1 + 0x18),_Dst);
        if ((int)uVar2 < 0) {
          WriteTraceEvent(param_1,2,
                          "NvdGetRuntimeFirmwareActivationInfoIoctl: get runtime firmware activation info failed with status 0x%x.\n"
                          ,(ulonglong)uVar2);
          uVar3 = 0;
        }
        *(undefined8 *)(param_2 + 0x38) = uVar3;
        return uVar2;
      }
      lVar1 = -0x3fffffdd;
    }
    else {
      lVar1 = -0x3fffff45;
    }
    *(undefined8 *)(param_2 + 0x38) = 0;
  }
  else {
    lVar1 = -0x3ffffff3;
  }
  return lVar1;
}



===== NvdLocationStringIoctl @ 1c001cab4 =====

/* long __cdecl NvdLocationStringIoctl(struct _NVDIMM_DEVICE_EXTENSION * __ptr64,struct _IRP *
   __ptr64,struct _SCM_PD_PROPERTY_QUERY * __ptr64) */

long __cdecl
NvdLocationStringIoctl
          (_NVDIMM_DEVICE_EXTENSION *param_1,_IRP *param_2,_SCM_PD_PROPERTY_QUERY *param_3)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  long lVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  ulonglong uVar7;
  uint uVar8;
  ulonglong uVar9;
  longlong lVar10;
  
  if (*(int *)(param_3 + 0xc) == 1) {
    lVar4 = 0;
  }
  else if (*(int *)(param_3 + 0xc) == 0) {
    uVar3 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
    if (7 < uVar3) {
      if (*(ushort *)(param_1 + 0x138) + 10 < 0xd) {
        uVar8 = 0xc;
      }
      else {
        uVar8 = *(ushort *)(param_1 + 0x138) + 10;
      }
      puVar6 = *(undefined4 **)(param_2 + 0x18);
      memset(puVar6,0,(ulonglong)uVar3);
      *puVar6 = 0xc;
      puVar6[1] = uVar8;
      if (uVar3 < uVar8) {
        *(undefined8 *)(param_2 + 0x38) = 8;
      }
      else {
        uVar7 = (ulonglong)(uVar3 - 8 >> 1);
        puVar6 = puVar6 + 2;
        if (uVar7 - 1 < 0x7fff) {
          uVar1 = *(ushort *)(param_1 + 0x138);
          if ((((((uVar1 & 1) == 0) && (uVar2 = *(ushort *)(param_1 + 0x13a), (uVar2 & 1) == 0)) &&
               (uVar1 <= uVar2)) && (uVar2 != 0xffff)) &&
             ((*(longlong *)(param_1 + 0x140) != 0 || ((uVar1 == 0 && (uVar2 == 0)))))) {
            uVar9 = (ulonglong)(uVar1 >> 1);
            lVar10 = *(longlong *)(param_1 + 0x140) - (longlong)puVar6;
            do {
              if (uVar9 == 0) break;
              uVar9 = uVar9 - 1;
              *(undefined2 *)puVar6 = *(undefined2 *)(lVar10 + (longlong)puVar6);
              puVar6 = (undefined4 *)((longlong)puVar6 + 2);
              uVar7 = uVar7 - 1;
            } while (uVar7 != 0);
            puVar5 = (undefined4 *)((longlong)puVar6 + -2);
            if (uVar7 != 0) {
              puVar5 = puVar6;
            }
            *(undefined2 *)puVar5 = 0;
          }
          else {
            *(undefined2 *)puVar6 = 0;
          }
        }
        *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar8;
      }
      return 0;
    }
    lVar4 = -0x3fffffdd;
  }
  else {
    lVar4 = -0x3fffff45;
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
  return lVar4;
}



===== NvdPassthroughCommandIoctl @ 1c001cc10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl NvdPassthroughCommandIoctl(struct _NVDIMM_DEVICE_EXTENSION * __ptr64,struct _IRP *
   __ptr64,unsigned char * __ptr64) */

long __cdecl
NvdPassthroughCommandIoctl(_NVDIMM_DEVICE_EXTENSION *param_1,_IRP *param_2,uchar *param_3)

{
  longlong lVar1;
  undefined4 *_Dst;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  uint uVar7;
  int *_Dst_00;
  uint uVar8;
  uint uVar9;
  char *pcVar10;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  *(undefined8 *)(param_2 + 0x38) = 0;
  *param_3 = '\0';
  if (*(uint *)(lVar1 + 0x10) < 0x20) {
    pcVar10 = "NvdPassthroughCommandIoctl: Input buffer too small.\n";
  }
  else {
    if (0x1f < *(uint *)(lVar1 + 8)) {
      bVar6 = KeGetCurrentIrql();
      if (1 < bVar6) {
        WriteTraceEvent(param_1,3,"NvdPassthroughCommandIoctl: Called at invalid IRQL.\n");
        return -0x3ffffeb8;
      }
      uVar9 = *(uint *)(lVar1 + 0x10);
      _Dst_00 = (int *)ExAllocatePool2(0x100,(ulonglong)uVar9,0x6f69764e);
      if (_Dst_00 == (int *)0x0) {
        return -0x3fffff66;
      }
      memcpy(_Dst_00,*(void **)(param_2 + 0x18),(ulonglong)uVar9);
      if (*_Dst_00 == 0x20) {
        uVar9 = *(uint *)(lVar1 + 8);
        _Dst = *(undefined4 **)(param_2 + 0x18);
        memset(_Dst,0,(ulonglong)uVar9);
        uVar7 = (**(code **)(**(longlong **)(param_1 + 0x18) + 0x78))
                          (*(longlong **)(param_1 + 0x18),_Dst_00 + 2,_Dst_00 + 7,_Dst_00[6],
                           _Dst + 7,uVar9 - 0x1c,_Dst + 6);
        iVar2 = _Dst_00[2];
        iVar3 = _Dst_00[3];
        iVar4 = _Dst_00[4];
        iVar5 = _Dst_00[5];
        uVar8 = _Dst[6] + 0x1c;
        *_Dst = 0x20;
        _Dst[2] = iVar2;
        _Dst[3] = iVar3;
        _Dst[4] = iVar4;
        _Dst[5] = iVar5;
        uVar9 = 0x20;
        if (0x20 < uVar8) {
          uVar9 = uVar8;
        }
        _Dst[1] = uVar9;
        WriteTraceEvent(param_1,4,"NvdPassthroughCommand: NVDIMM object call returned NTSTATUS 0x%x"
                        ,(ulonglong)uVar7);
        *(ulonglong *)(param_2 + 0x38) = (ulonglong)(uint)_Dst[1];
      }
      else {
        WriteTraceEvent(param_1,3,"NvdPassthroughCommandIoctl: Invalid version number (0x%x)");
        uVar7 = 0xc00000bb;
      }
      operator_delete(_Dst_00);
      return uVar7;
    }
    pcVar10 = "NvdPassthroughCommandIoctl: Output buffer too small.\n";
  }
  WriteTraceEvent(param_1,2,pcVar10);
  return -0x3ffffff3;
}



===== NvdPrivateDeviceInfoIoctl @ 1c001cdc4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl NvdPrivateDeviceInfoIoctl(struct _NVDIMM_DEVICE_EXTENSION * __ptr64,struct _IRP *
   __ptr64,struct _SCM_PD_PRIVATE_PROPERTY_QUERY * __ptr64) */

long __cdecl
NvdPrivateDeviceInfoIoctl
          (_NVDIMM_DEVICE_EXTENSION *param_1,_IRP *param_2,_SCM_PD_PRIVATE_PROPERTY_QUERY *param_3)

{
  undefined8 *puVar1;
  byte bVar2;
  _NVDIMM_DEVICE_EXTENSION _Var3;
  undefined4 *_Dst;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  void *pvVar7;
  long lVar8;
  uint uVar9;
  uint uVar10;
  undefined4 uVar11;
  char *pcVar12;
  longlong lVar13;
  uint uVar14;
  size_t _Size;
  char local_res18 [8];
  void *local_res20;
  
  if (*(int *)(param_3 + 0xc) == 1) {
    lVar8 = 0;
  }
  else if (*(int *)(param_3 + 0xc) == 0) {
    uVar10 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
    if (7 < uVar10) {
      pcVar12 = *(char **)(param_1 + 0x188);
      _Size = 0;
      if (pcVar12 != (char *)0x0) {
        lVar13 = 0x7fffffff;
        do {
          if (*pcVar12 == '\0') break;
          pcVar12 = pcVar12 + 1;
          lVar13 = lVar13 + -1;
        } while (lVar13 != 0);
        if (lVar13 == 0) {
          _Size = 0;
        }
        else {
          _Size = (-(ulonglong)(lVar13 != 0) & 0x7fffffffU - lVar13) + 1;
        }
      }
      _Dst = *(undefined4 **)(param_2 + 0x18);
      uVar9 = (int)_Size + 0xa0;
      uVar14 = 0x78;
      if (0x78 < uVar9) {
        uVar14 = uVar9;
      }
      memset(_Dst,0,(ulonglong)uVar10);
      *_Dst = 0xa8;
      _Dst[1] = uVar14;
      if (uVar10 < uVar14) {
        *(undefined8 *)(param_2 + 0x38) = 8;
        return 0;
      }
      uVar11 = *(undefined4 *)(param_1 + 0x194);
      uVar4 = *(undefined4 *)(param_1 + 0x198);
      uVar5 = *(undefined4 *)(param_1 + 0x19c);
      _Dst[2] = *(undefined4 *)(param_1 + 400);
      _Dst[3] = uVar11;
      _Dst[4] = uVar4;
      _Dst[5] = uVar5;
      *(undefined8 *)(_Dst + 0x12) = *(undefined8 *)(param_1 + 0x30);
      *(undefined8 *)(_Dst + 0x14) = *(undefined8 *)(param_1 + 0x38);
      *(undefined8 *)(_Dst + 0x16) = *(undefined8 *)(param_1 + 0x40);
      _Dst[0x18] = *(undefined4 *)(param_1 + 0x134);
      _Dst[0x19] = *(undefined4 *)(param_1 + 0x20);
      *(undefined2 *)(_Dst + 0x1a) = *(undefined2 *)(param_1 + 0x24);
      uVar10 = (**(code **)(**(longlong **)(param_1 + 0x18) + 0x10))
                         (*(longlong **)(param_1 + 0x18),_Dst + 6);
      if ((int)uVar10 < 0) {
        WriteTraceEvent(param_1,3,
                        "NvdPrivateDeviceInfoIoctl: Nvdimm->GetUnsafeShutdownCount() failed with 0x%x"
                        ,(ulonglong)uVar10);
      }
      else {
        uVar11 = (**(code **)(**(longlong **)(param_1 + 0x18) + 0x88))();
        _Dst[0x1b] = uVar11;
        local_res20 = (void *)0x0;
        local_res18[0] = '\0';
        uVar10 = (**(code **)(**(longlong **)(param_1 + 0x18) + 0x40))
                           (*(longlong **)(param_1 + 0x18),&local_res20,local_res18,_Dst + 0x10,
                            _Dst + 0x11);
        pvVar7 = local_res20;
        if ((int)uVar10 < 0) {
          WriteTraceEvent(param_1,3,
                          "NvdPrivateDeviceInfoIoctl: Nvdimm->GetFirmwareInfo() failed with 0x%x",
                          (ulonglong)uVar10);
        }
        else {
          *(byte *)((longlong)_Dst + 0x3d) =
               *(byte *)((longlong)_Dst + 0x3d) & 0xfe | local_res18[0] != '\0';
          *(undefined1 *)(_Dst + 0xf) = *(undefined1 *)((longlong)local_res20 + 10);
          bVar2 = *(byte *)((longlong)local_res20 + 8);
          puVar1 = (undefined8 *)((longlong)local_res20 + (ulonglong)bVar2 * 0x30 + 0x1c);
          uVar6 = puVar1[1];
          *(undefined8 *)(_Dst + 7) = *puVar1;
          *(undefined8 *)(_Dst + 9) = uVar6;
          puVar1 = (undefined8 *)((longlong)local_res20 + (ulonglong)bVar2 * 0x30 + 0x2c);
          uVar6 = puVar1[1];
          *(undefined8 *)(_Dst + 0xb) = *puVar1;
          *(undefined8 *)(_Dst + 0xd) = uVar6;
          _Var3 = param_1[0x26];
          *(_NVDIMM_DEVICE_EXTENSION *)(_Dst + 0x1c) = _Var3;
          if (8 < (byte)_Var3) {
            local_res20 = (void *)0x0;
            if (pvVar7 != (void *)0x0) {
              operator_delete(pvVar7);
            }
            return -0x3ffffff3;
          }
          memcpy((void *)((longlong)_Dst + 0x72),*(void **)(param_1 + 0x28),
                 (ulonglong)(byte)_Var3 * 2);
          _Dst[0x21] = *(undefined4 *)(param_1 + 0x160);
          _Dst[0x22] = *(undefined4 *)(param_1 + 0x164);
          _Dst[0x23] = *(undefined4 *)(param_1 + 0x168);
          _Dst[0x24] = *(undefined4 *)(param_1 + 0x16c);
          *(_NVDIMM_DEVICE_EXTENSION *)(_Dst + 0x25) = param_1[0x170];
          *(_NVDIMM_DEVICE_EXTENSION *)((longlong)_Dst + 0x95) = param_1[0x171];
          *(_NVDIMM_DEVICE_EXTENSION *)((longlong)_Dst + 0x96) = param_1[0x172];
          _Dst[0x26] = *(undefined4 *)(param_1 + 0x174);
          _Dst[0x27] = (int)_Size;
          memcpy(_Dst + 0x28,*(void **)(param_1 + 0x188),_Size);
          *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar14;
        }
        pvVar7 = local_res20;
        local_res20 = (void *)0x0;
        if (pvVar7 != (void *)0x0) {
          operator_delete(pvVar7);
        }
      }
      return uVar10;
    }
    lVar8 = -0x3fffffdd;
  }
  else {
    lVar8 = -0x3fffff45;
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
  return lVar8;
}



===== NvdQueryPrivateProperty @ 1c001d0a8 =====

/* long __cdecl NvdQueryPrivateProperty(struct _NVDIMM_DEVICE_EXTENSION * __ptr64,struct _IRP *
   __ptr64,unsigned char * __ptr64) */

long __cdecl NvdQueryPrivateProperty(_NVDIMM_DEVICE_EXTENSION *param_1,_IRP *param_2,uchar *param_3)

{
  longlong lVar1;
  _SCM_PD_PRIVATE_PROPERTY_QUERY *p_Var2;
  undefined8 *puVar3;
  byte bVar4;
  long lVar5;
  ulong uVar6;
  char *pcVar7;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  *param_3 = '\0';
  if (*(uint *)(lVar1 + 0x10) < 0x14) {
    pcVar7 = "NvdQueryPrivateProperty: Input buffer too small.\n";
    uVar6 = 2;
  }
  else {
    bVar4 = KeGetCurrentIrql();
    if (1 < bVar4) {
      WriteTraceEvent(param_1,3,"NvdQueryPrivateProperty: Called at invalid IRQL.\n");
      *(undefined8 *)(param_2 + 0x38) = 0;
      return -0x3ffffeb8;
    }
    p_Var2 = *(_SCM_PD_PRIVATE_PROPERTY_QUERY **)(param_2 + 0x18);
    if (*(int *)p_Var2 == 0x14) {
      if (*(int *)(p_Var2 + 8) == 0) {
        lVar5 = NvdPrivateDeviceInfoIoctl(param_1,param_2,p_Var2);
        return lVar5;
      }
      puVar3 = *(undefined8 **)(param_2 + 0xb8);
      *param_3 = '\x01';
      puVar3[-9] = *puVar3;
      puVar3[-8] = puVar3[1];
      puVar3[-7] = puVar3[2];
      puVar3[-6] = puVar3[3];
      *(undefined4 *)(puVar3 + -5) = *(undefined4 *)(puVar3 + 4);
      *(undefined4 *)((longlong)puVar3 + -0x24) = *(undefined4 *)((longlong)puVar3 + 0x24);
      *(undefined4 *)(puVar3 + -4) = *(undefined4 *)(puVar3 + 5);
      *(undefined4 *)((longlong)puVar3 + -0x1c) = *(undefined4 *)((longlong)puVar3 + 0x2c);
      puVar3[-3] = puVar3[6];
      *(undefined1 *)((longlong)puVar3 + -0x45) = 0;
      lVar5 = IofCallDriver(*(undefined8 *)(param_1 + 8));
      return lVar5;
    }
    pcVar7 = "NvdQueryPrivateProperty: Version field did not match sizeof().\n";
    uVar6 = 3;
  }
  WriteTraceEvent(param_1,uVar6,pcVar7);
  return -0x3ffffff3;
}



===== NvdQueryProperty @ 1c001d1a4 =====

/* long __cdecl NvdQueryProperty(struct _NVDIMM_DEVICE_EXTENSION * __ptr64,struct _IRP *
   __ptr64,unsigned char * __ptr64) */

long __cdecl NvdQueryProperty(_NVDIMM_DEVICE_EXTENSION *param_1,_IRP *param_2,uchar *param_3)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  _SCM_PD_MANAGEMENT_STATUS *p_Var4;
  undefined8 *puVar5;
  undefined8 uVar6;
  byte bVar7;
  long lVar8;
  ulong uVar9;
  char *pcVar10;
  ulong local_res10 [2];
  
  lVar3 = *(longlong *)(param_2 + 0xb8);
  *param_3 = '\0';
  if (*(uint *)(lVar3 + 0x10) < 0x14) {
    pcVar10 = "NvdQueryProperty: Input buffer too small.\n";
    uVar9 = 2;
  }
  else {
    bVar7 = KeGetCurrentIrql();
    if (1 < bVar7) {
      WriteTraceEvent(param_1,3,"NvdQueryProperty: Called at invalid IRQL.\n");
      *(undefined8 *)(param_2 + 0x38) = 0;
      return -0x3ffffeb8;
    }
    p_Var4 = *(_SCM_PD_MANAGEMENT_STATUS **)(param_2 + 0x18);
    if (*(int *)p_Var4 == 0x14) {
      iVar1 = *(int *)(p_Var4 + 8);
      if (iVar1 == 0) {
        lVar8 = NvdDeviceInfoIoctl(param_1,param_2,(_SCM_PD_PROPERTY_QUERY *)p_Var4);
      }
      else if (iVar1 == 1) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        if (*(int *)(p_Var4 + 0xc) == 1) {
          return 0;
        }
        if (*(int *)(p_Var4 + 0xc) != 0) {
          return -0x3fffff45;
        }
        uVar2 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
        if (uVar2 < 8) {
          return -0x3fffffdd;
        }
        local_res10[0] = 0;
        lVar8 = NvdGetDeviceManagementStatus(param_1,p_Var4,uVar2,local_res10);
        if (-1 < lVar8) {
          if (uVar2 < local_res10[0]) {
            local_res10[0] = uVar2;
          }
          *(ulonglong *)(param_2 + 0x38) = (ulonglong)local_res10[0];
        }
      }
      else if (iVar1 == 2) {
        lVar8 = NvdFirmwareInfoIoctl(param_1,param_2,(_SCM_PD_PROPERTY_QUERY *)p_Var4);
      }
      else if (iVar1 == 3) {
        lVar8 = NvdLocationStringIoctl(param_1,param_2,(_SCM_PD_PROPERTY_QUERY *)p_Var4);
      }
      else if (iVar1 == 4) {
        lVar8 = NvdDeviceSpecificInfoIoctl(param_1,param_2,(_SCM_PD_PROPERTY_QUERY *)p_Var4);
      }
      else {
        if (iVar1 == 5) {
          if (*(int *)(p_Var4 + 0xc) == 1) {
            *(undefined8 *)(param_2 + 0x38) = 0;
            return 0;
          }
          if (*(int *)(p_Var4 + 0xc) != 0) {
            *(undefined8 *)(param_2 + 0x38) = 0;
            return -0x3fffff45;
          }
          uVar2 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
          if (uVar2 < 8) {
            *(undefined8 *)(param_2 + 0x38) = 0;
            return -0x3fffffdd;
          }
          *(undefined4 *)p_Var4 = 0x1c;
          *(undefined4 *)(p_Var4 + 4) = 0x1c;
          if (uVar2 < 0x1c) {
            *(undefined8 *)(param_2 + 0x38) = 8;
            return 0;
          }
          *(undefined4 *)(p_Var4 + 0x18) = *(undefined4 *)(param_1 + 0x20);
          uVar6 = *(undefined8 *)(param_1 + 0x198);
          *(undefined8 *)(p_Var4 + 8) = *(undefined8 *)(param_1 + 400);
          *(undefined8 *)(p_Var4 + 0x10) = uVar6;
          *(undefined8 *)(param_2 + 0x38) = 0x1c;
          return 0;
        }
        if (iVar1 == 6) {
          lVar8 = NvdFruIdStringIoctl(param_1,param_2,(_SCM_PD_PROPERTY_QUERY *)p_Var4);
        }
        else if (iVar1 == 7) {
          lVar8 = NvdGetRuntimeFirmwareActivationInfoIoctl
                            (param_1,param_2,(_SCM_PD_PROPERTY_QUERY *)p_Var4);
        }
        else {
          puVar5 = *(undefined8 **)(param_2 + 0xb8);
          *param_3 = '\x01';
          puVar5[-9] = *puVar5;
          puVar5[-8] = puVar5[1];
          puVar5[-7] = puVar5[2];
          puVar5[-6] = puVar5[3];
          *(undefined4 *)(puVar5 + -5) = *(undefined4 *)(puVar5 + 4);
          *(undefined4 *)((longlong)puVar5 + -0x24) = *(undefined4 *)((longlong)puVar5 + 0x24);
          *(undefined4 *)(puVar5 + -4) = *(undefined4 *)(puVar5 + 5);
          *(undefined4 *)((longlong)puVar5 + -0x1c) = *(undefined4 *)((longlong)puVar5 + 0x2c);
          puVar5[-3] = puVar5[6];
          *(undefined1 *)((longlong)puVar5 + -0x45) = 0;
          lVar8 = IofCallDriver(*(undefined8 *)(param_1 + 8),param_2);
        }
      }
      return lVar8;
    }
    pcVar10 = "NvdQueryProperty: Version field did not match sizeof().\n";
    uVar9 = 3;
  }
  WriteTraceEvent(param_1,uVar9,pcVar10);
  return -0x3ffffff3;
}



===== NvdRefreshManagementStatus @ 1c001d408 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl NvdRefreshManagementStatus(struct _NVDIMM_DEVICE_EXTENSION * __ptr64,struct _IRP *
   __ptr64,unsigned char * __ptr64) */

long __cdecl
NvdRefreshManagementStatus(_NVDIMM_DEVICE_EXTENSION *param_1,_IRP *param_2,uchar *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  *param_3 = '\0';
  *(undefined8 *)(param_2 + 0x38) = 0;
  WriteTraceEvent(param_1,4,
                  "NvdRefreshManagementStatus(): Refreshing health and security state of the NVDIMM"
                 );
  iVar1 = (**(code **)(**(longlong **)(param_1 + 0x18) + 0x20))(*(longlong **)(param_1 + 0x18),3);
  iVar2 = (**(code **)(**(longlong **)(param_1 + 0x18) + 0x90))();
  uVar3 = NvdNotifyHealthChange(param_1,'\x01');
  if ((int)uVar3 < 0) {
    WriteTraceEvent(param_1,2,
                    "NvdRefreshManagementStatus: NvdNotifyHealthChange() failed with NTSTATUS 0x%x",
                    (ulonglong)uVar3);
  }
  if ((-1 < iVar1) && (iVar1 = 0, iVar2 < 0)) {
    iVar1 = iVar2;
  }
  return iVar1;
}



===== NvdReinitializeMediaIoctl @ 1c001d4b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl NvdReinitializeMediaIoctl(struct _NVDIMM_DEVICE_EXTENSION * __ptr64,struct _IRP *
   __ptr64,unsigned char * __ptr64) */

long __cdecl
NvdReinitializeMediaIoctl(_NVDIMM_DEVICE_EXTENSION *param_1,_IRP *param_2,uchar *param_3)

{
  uint uVar1;
  longlong lVar2;
  int *piVar3;
  byte bVar4;
  long lVar5;
  char *pcVar6;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  *(undefined8 *)(param_2 + 0x38) = 0;
  *param_3 = '\0';
  if (*(uint *)(lVar2 + 0x10) < 0xc) {
    pcVar6 = "NvdReinitializeMedia: Input buffer too small.\n";
  }
  else {
    if (0xb < *(uint *)(lVar2 + 8)) {
      bVar4 = KeGetCurrentIrql();
      if (1 < bVar4) {
        WriteTraceEvent(param_1,3,"NvdReinitializeMedia: Called at invalid IRQL.\n");
        return -0x3ffffeb8;
      }
      piVar3 = *(int **)(param_2 + 0x18);
      if (*piVar3 == 0xc) {
        uVar1 = piVar3[2];
        piVar3[2] = 0;
        *piVar3 = 0xc;
        piVar3[1] = 0xc;
        *(undefined8 *)(param_2 + 0x38) = 0xc;
        lVar5 = (**(code **)(**(longlong **)(param_1 + 0x18) + 0x80))
                          (*(longlong **)(param_1 + 0x18),uVar1 & 0xffffff01);
        return lVar5;
      }
      return -0x3ffffff0;
    }
    pcVar6 = "NvdReinitializeMedia: Output buffer too small.\n";
  }
  WriteTraceEvent(param_1,2,pcVar6);
  return -0x3ffffff3;
}



===== NvdSetProperty @ 1c001d584 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl NvdSetProperty(struct _NVDIMM_DEVICE_EXTENSION * __ptr64,struct _IRP *
   __ptr64,unsigned char * __ptr64) */

long __cdecl NvdSetProperty(_NVDIMM_DEVICE_EXTENSION *param_1,_IRP *param_2,uchar *param_3)

{
  longlong lVar1;
  int *piVar2;
  undefined8 *puVar3;
  int iVar4;
  byte bVar5;
  uint uVar6;
  char *pcVar7;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  uVar6 = 0;
  *param_3 = '\0';
  if (*(uint *)(lVar1 + 0x10) < 0x14) {
    pcVar7 = "NvdSetProperty: Input buffer too small.\n";
  }
  else {
    bVar5 = KeGetCurrentIrql();
    if (1 < bVar5) {
      WriteTraceEvent(param_1,3,"NvdSetProperty: Called at invalid IRQL.\n");
      *(undefined8 *)(param_2 + 0x38) = 0;
      return -0x3ffffeb8;
    }
    piVar2 = *(int **)(param_2 + 0x18);
    if (*piVar2 == 0x14) {
      if (piVar2[2] == 8) {
        if (piVar2[3] == 1) {
          *(undefined8 *)(param_2 + 0x38) = 0;
        }
        else if (piVar2[3] == 0) {
          if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10) < 0x11) {
            *(undefined8 *)(param_2 + 0x38) = 0;
            uVar6 = 0xc000000d;
          }
          else {
            iVar4 = piVar2[4];
            *(undefined8 *)(param_2 + 0x38) = 0;
            uVar6 = (**(code **)(**(longlong **)(param_1 + 0x18) + 0x70))
                              (*(longlong **)(param_1 + 0x18),
                               CONCAT71((int7)((ulonglong)piVar2 >> 8),(char)iVar4));
            if ((int)uVar6 < 0) {
              WriteTraceEvent(param_1,2,
                              "NvdSetRuntimeFirmwareActivationArmStateIoctl: set firmware activation arm state failed with status 0x%x.\n"
                              ,(ulonglong)uVar6);
            }
          }
        }
        else {
          *(undefined8 *)(param_2 + 0x38) = 0;
          uVar6 = 0xc00000bb;
        }
      }
      else {
        puVar3 = *(undefined8 **)(param_2 + 0xb8);
        *param_3 = '\x01';
        puVar3[-9] = *puVar3;
        puVar3[-8] = puVar3[1];
        puVar3[-7] = puVar3[2];
        puVar3[-6] = puVar3[3];
        *(undefined4 *)(puVar3 + -5) = *(undefined4 *)(puVar3 + 4);
        *(undefined4 *)((longlong)puVar3 + -0x24) = *(undefined4 *)((longlong)puVar3 + 0x24);
        *(undefined4 *)(puVar3 + -4) = *(undefined4 *)(puVar3 + 5);
        *(undefined4 *)((longlong)puVar3 + -0x1c) = *(undefined4 *)((longlong)puVar3 + 0x2c);
        puVar3[-3] = puVar3[6];
        *(undefined1 *)((longlong)puVar3 + -0x45) = 0;
        uVar6 = IofCallDriver(*(undefined8 *)(param_1 + 8),param_2);
      }
      return uVar6;
    }
    pcVar7 = "NvdSetProperty: Version field did not match sizeof().\n";
  }
  WriteTraceEvent(param_1,3,pcVar7);
  return -0x3ffffff3;
}



===== NvdQueryRegistry<unsigned_long> @ 1c001d6ec =====

/* long __cdecl NvdQueryRegistry<unsigned long>(void * __ptr64,unsigned short const *
   __ptr64,unsigned short const * __ptr64,unsigned long,unsigned long * __ptr64) */

long __cdecl
NvdQueryRegistry<unsigned_long>
          (void *param_1,ushort *param_2,ushort *param_3,ulong param_4,ulong *param_5)

{
  int iVar1;
  long lVar2;
  void *local_res10;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined4 local_a8;
  undefined4 local_a4;
  void *local_a0;
  undefined8 *local_98;
  undefined4 local_90;
  undefined4 local_8c;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined4 local_70 [2];
  ushort *local_68;
  ulong *local_60;
  undefined4 local_58;
  undefined8 local_50;
  undefined4 local_48;
  
  local_78 = 0;
  memset(local_70,0,0x68);
  local_res10 = (void *)0x0;
  if (param_2 != (ushort *)0x0) {
    local_a4 = 0;
    local_8c = 0;
    local_b8 = 0;
    uStack_b0 = 0;
    RtlInitUnicodeString(&local_b8,param_2);
    local_98 = &local_b8;
    local_a8 = 0x30;
    local_90 = 0x240;
    local_88 = 0;
    uStack_80 = 0;
    local_a0 = param_1;
    iVar1 = ZwOpenKey(&local_res10,0x20019,&local_a8);
    if (iVar1 < 0) {
      return iVar1;
    }
  }
  local_50 = 0;
  local_48 = 0;
  local_70[0] = 0x124;
  if (param_2 != (ushort *)0x0) {
    param_1 = local_res10;
  }
  local_60 = param_5;
  local_58 = 0x4000000;
  local_68 = param_3;
  lVar2 = RtlQueryRegistryValuesEx(0x40000000,param_1,&local_78,0,0);
  if (local_res10 != (void *)0x0) {
    ZwClose();
  }
  return lVar2;
}



===== ContainsFormatInterfaceCode @ 1c001d81c =====

/* bool __cdecl ContainsFormatInterfaceCode(unsigned short * __ptr64,unsigned char,unsigned short)
    */

bool __cdecl ContainsFormatInterfaceCode(ushort *param_1,uchar param_2,ushort param_3)

{
  byte bVar1;
  
  bVar1 = 0;
  if (param_2 != '\0') {
    do {
      if (param_1[bVar1] == param_3) {
        return true;
      }
      bVar1 = bVar1 + 1;
    } while (bVar1 < param_2);
  }
  return false;
}



===== NvdDeferProcessing @ 1c001d844 =====

/* long __cdecl NvdDeferProcessing(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl NvdDeferProcessing(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  longlong lVar3;
  int iVar4;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  KeInitializeEvent(&local_28,0,0);
  puVar2 = *(undefined8 **)(param_2 + 0xb8);
  puVar2[-9] = *puVar2;
  puVar2[-8] = puVar2[1];
  puVar2[-7] = puVar2[2];
  puVar2[-6] = puVar2[3];
  *(undefined4 *)(puVar2 + -5) = *(undefined4 *)(puVar2 + 4);
  *(undefined4 *)((longlong)puVar2 + -0x24) = *(undefined4 *)((longlong)puVar2 + 0x24);
  *(undefined4 *)(puVar2 + -4) = *(undefined4 *)(puVar2 + 5);
  *(undefined4 *)((longlong)puVar2 + -0x1c) = *(undefined4 *)((longlong)puVar2 + 0x2c);
  puVar2[-3] = puVar2[6];
  *(undefined1 *)((longlong)puVar2 + -0x45) = 0;
  lVar3 = *(longlong *)(param_2 + 0xb8);
  *(code **)(lVar3 + -0x10) = NvdPnpCompletion;
  *(undefined8 **)(lVar3 + -8) = &local_28;
  *(undefined1 *)(lVar3 + -0x45) = 0xe0;
  iVar4 = IofCallDriver(*(undefined8 *)(lVar1 + 8),param_2);
  if (iVar4 == 0x103) {
    KeWaitForSingleObject(&local_28,0,0,0,0);
    iVar4 = *(int *)(param_2 + 0x30);
  }
  return iVar4;
}



===== NvdGetLogicalDeviceCount @ 1c001d914 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl NvdGetLogicalDeviceCount(struct _NVDIMM_DEVICE_EXTENSION * __ptr64,unsigned long *
   __ptr64) */

long __cdecl NvdGetLogicalDeviceCount(_NVDIMM_DEVICE_EXTENSION *param_1,ulong *param_2)

{
  uint uVar1;
  
  *param_2 = 0;
  uVar1 = (**(code **)(param_1 + 0xb0))(*(undefined8 *)(param_1 + 0x58),param_2,0);
  if (((uVar1 + 0x80000000 & 0x80000000) == 0) && (uVar1 != 0xc0000023)) {
    WriteTraceEvent(param_1,2,
                    "NvdGetLogicalDeviceCount(): NvdGetLogicalDeviceGuids() failed with NTSTATUS 0x%x"
                    ,(ulonglong)uVar1);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



===== NvdPassIrp @ 1c001d97c =====

/* long __cdecl NvdPassIrp(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl NvdPassIrp(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  longlong lVar1;
  long lVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  param_2[0x43] = (_IRP)((char)param_2[0x43] + '\x01');
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  lVar2 = IofCallDriver(*(undefined8 *)(lVar1 + 8));
  return lVar2;
}



===== NvdQueryDeviceRegistryUlong @ 1c001d9ac =====

/* long __cdecl NvdQueryDeviceRegistryUlong(struct _NVDIMM_DEVICE_EXTENSION * __ptr64,unsigned short
   const * __ptr64,unsigned short const * __ptr64,unsigned long * __ptr64) */

long __cdecl
NvdQueryDeviceRegistryUlong
          (_NVDIMM_DEVICE_EXTENSION *param_1,ushort *param_2,ushort *param_3,ulong *param_4)

{
  int iVar1;
  ulong uVar2;
  void *local_res8;
  
  local_res8 = (void *)0x0;
  uVar2 = (ulong)&local_res8;
  iVar1 = IoOpenDeviceRegistryKey(*(undefined8 *)(param_1 + 0x10),1,0x20019);
  if (-1 < iVar1) {
    iVar1 = NvdQueryRegistry<unsigned_long>(local_res8,param_2,param_3,uVar2,param_4);
    ZwClose(local_res8);
  }
  return iVar1;
}



===== NvdQueryDeviceRegistryUnicodeString @ 1c001da3c =====

/* long __cdecl NvdQueryDeviceRegistryUnicodeString(struct _NVDIMM_DEVICE_EXTENSION *
   __ptr64,unsigned short const * __ptr64,unsigned short const * __ptr64,struct _UNICODE_STRING *
   __ptr64) */

long __cdecl
NvdQueryDeviceRegistryUnicodeString
          (_NVDIMM_DEVICE_EXTENSION *param_1,ushort *param_2,ushort *param_3,
          _UNICODE_STRING *param_4)

{
  int iVar1;
  undefined8 local_res18 [2];
  undefined8 local_78;
  undefined4 local_70 [2];
  wchar_t *local_68;
  _UNICODE_STRING *local_60;
  undefined4 local_58;
  undefined8 local_50;
  undefined4 local_48;
  
  local_res18[0] = 0;
  iVar1 = IoOpenDeviceRegistryKey(*(undefined8 *)(param_1 + 0x10),1,0x20019,local_res18);
  if (-1 < iVar1) {
    local_78 = 0;
    memset(local_70,0,0x68);
    local_50 = 0;
    local_48 = 0;
    local_68 = L"NvdimmPassphrase";
    local_70[0] = 0x124;
    local_58 = 0x1000000;
    local_60 = param_4;
    iVar1 = RtlQueryRegistryValuesEx(0x40000000,local_res18[0],&local_78,0,0);
    ZwClose(local_res18[0]);
  }
  return iVar1;
}



===== NvdQueryDriverRegistryUlong @ 1c001db10 =====

/* long __cdecl NvdQueryDriverRegistryUlong(struct _NVDIMM_DEVICE_EXTENSION * __ptr64,unsigned short
   const * __ptr64,unsigned short const * __ptr64,unsigned long * __ptr64) */

long __cdecl
NvdQueryDriverRegistryUlong
          (_NVDIMM_DEVICE_EXTENSION *param_1,ushort *param_2,ushort *param_3,ulong *param_4)

{
  int iVar1;
  ulong uVar2;
  void *local_res10;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  _UNICODE_STRING *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  uVar2 = (ulong)param_4;
  local_res10 = (void *)0x0;
  local_34 = 0;
  local_1c = 0;
  local_30 = 0;
  local_28 = &DriverRegistryPath;
  local_38 = 0x30;
  local_18 = 0;
  uStack_10 = 0;
  local_20 = 0x240;
  iVar1 = ZwOpenKey(&local_res10,0x20019,&local_38);
  if (-1 < iVar1) {
    iVar1 = NvdQueryRegistry<unsigned_long>(local_res10,(ushort *)L"",param_3,uVar2,param_4);
    ZwClose(local_res10);
  }
  return iVar1;
}



===== NvdSendIrpSynchronous @ 1c001dbcc =====

/* long __cdecl NvdSendIrpSynchronous(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl NvdSendIrpSynchronous(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  longlong lVar1;
  int iVar2;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  KeInitializeEvent(&local_28,1,0);
  lVar1 = *(longlong *)(param_2 + 0xb8);
  *(code **)(lVar1 + -0x10) = NvdSignalCompletion;
  *(undefined8 **)(lVar1 + -8) = &local_28;
  *(undefined1 *)(lVar1 + -0x45) = 0xe0;
  iVar2 = IofCallDriver(param_1,param_2);
  if (iVar2 == 0x103) {
    KeWaitForSingleObject(&local_28,0,0,0,0);
    iVar2 = *(int *)(param_2 + 0x30);
  }
  return iVar2;
}



===== NvdWriteDeviceRegistryUlong @ 1c001dc70 =====

/* long __cdecl NvdWriteDeviceRegistryUlong(struct _NVDIMM_DEVICE_EXTENSION * __ptr64,unsigned short
   const * __ptr64,unsigned long) */

long __cdecl
NvdWriteDeviceRegistryUlong(_NVDIMM_DEVICE_EXTENSION *param_1,ushort *param_2,ulong param_3)

{
  int iVar1;
  undefined8 local_res8 [2];
  ulong local_res18 [4];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res8[0] = 0;
  local_res18[0] = param_3;
  iVar1 = IoOpenDeviceRegistryKey(*(undefined8 *)(param_1 + 0x10),1,0x20006,local_res8);
  if (-1 < iVar1) {
    local_18 = 0;
    uStack_10 = 0;
    RtlInitUnicodeString(&local_18,param_2);
    iVar1 = ZwSetValueKey(local_res8[0],&local_18,0,4,local_res18,4);
    ZwClose(local_res8[0]);
  }
  return iVar1;
}



===== NvdNotificationCallback @ 1c001dd20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl NvdNotificationCallback(void * __ptr64,enum _SCM_BUS_NVD_NOTIFICATION_TYPE,unsigned
   long,unsigned char) */

void __cdecl
NvdNotificationCallback
          (void *param_1,_SCM_BUS_NVD_NOTIFICATION_TYPE param_2,ulong param_3,uchar param_4)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  
  iVar1 = IoAcquireRemoveLockEx((longlong)param_1 + 0xf0,param_1,"",1,0x20);
  if (iVar1 < 0) {
    return;
  }
  if (param_2 == 2) {
    param_2 = (**(code **)((longlong)param_1 + 0xd0))
                        (*(undefined8 *)((longlong)param_1 + 0x58),0,(longlong)param_1 + 0x48);
    if ((int)param_2 < 0) {
      pcVar3 = "NvdNotification(): NvdGetBadMemoryRangesInfo() failed with 0x%x";
LAB_1c001dda3:
      WriteTraceEvent(param_1,2,pcVar3,(ulonglong)param_2);
      goto LAB_1c001de5c;
    }
    (**(code **)(**(longlong **)((longlong)param_1 + 0x18) + 0x20))
              (*(longlong **)((longlong)param_1 + 0x18),1);
    if (*(uint *)((longlong)param_1 + 0x48) != 0) {
      WriteTraceEvent(param_1,2,"NvdNotification(): %d bad memory ranges detected on NVDIMM 0x%x",
                      (ulonglong)*(uint *)((longlong)param_1 + 0x48),
                      *(undefined4 *)((longlong)param_1 + 0x20));
    }
  }
  else {
    if (param_2 == 1) {
      if (param_3 != 0x81) goto LAB_1c001de5c;
    }
    else if (param_2 != 3) {
      pcVar3 = "NvdNotification(): Unknown notification type (%d)";
      goto LAB_1c001dda3;
    }
    (**(code **)(**(longlong **)((longlong)param_1 + 0x18) + 0x20))
              (*(longlong **)((longlong)param_1 + 0x18),1);
    if ((param_2 == 3) &&
       (uVar2 = (**(code **)(**(longlong **)((longlong)param_1 + 0x18) + 0x28))(), (int)uVar2 < 0))
    {
      WriteTraceEvent(param_1,2,"NvdNotificationCallback: error resuming from hibernate (0x%x)",
                      (ulonglong)uVar2);
    }
  }
  NvdNotifyHealthChange(param_1,param_4);
LAB_1c001de5c:
  IoReleaseRemoveLockEx((longlong)param_1 + 0xf0,param_1,0x20);
  return;
}



===== NvdNotifyHealthChange @ 1c001dea0 =====

/* long __cdecl NvdNotifyHealthChange(struct _NVDIMM_DEVICE_EXTENSION * __ptr64,unsigned char) */

long __cdecl NvdNotifyHealthChange(_NVDIMM_DEVICE_EXTENSION *param_1,uchar param_2)

{
  long lVar1;
  long lVar2;
  
  lVar1 = 0;
  if (param_2 != '\0') {
    lVar1 = NvdNotifyLogicalDisksOfHealthChange(param_1);
  }
  lVar2 = NvdSendPnpHealthChangeNotification(param_1);
  if (lVar1 < 0) {
    lVar2 = lVar1;
  }
  return lVar2;
}



===== NvdResumeWorkItemRoutine @ 1c001dee0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl NvdResumeWorkItemRoutine(struct _DEVICE_OBJECT * __ptr64,void * __ptr64) */

void __cdecl NvdResumeWorkItemRoutine(_DEVICE_OBJECT *param_1,void *param_2)

{
  _NVDIMM_DEVICE_EXTENSION *p_Var1;
  uint uVar2;
  
  p_Var1 = *(_NVDIMM_DEVICE_EXTENSION **)(param_1 + 0x40);
  uVar2 = (**(code **)(p_Var1 + 0xd0))(*(undefined8 *)(p_Var1 + 0x58),1);
  if ((int)uVar2 < 0) {
    WriteTraceEvent(p_Var1,2,"D0 transition: NvdGetBadMemoryRangesInfo() failed with 0x%x",
                    (ulonglong)uVar2);
  }
  uVar2 = (**(code **)(p_Var1 + 0xb8))(*(undefined8 *)(p_Var1 + 0x58),p_Var1 + 0xe0);
  if ((int)uVar2 < 0) {
    WriteTraceEvent(p_Var1,2,"D0 transition: NvdGetBootTimeStatus() failed with 0x%x",
                    (ulonglong)uVar2);
  }
  if (p_Var1[0xe5] != (_NVDIMM_DEVICE_EXTENSION)0x0) {
    WriteTraceEvent(p_Var1,2,
                    "After resuming, the NoSPAMapping bit is set, meaning that the platform didn\'t map the contents of this NVDIMM into virtual memory."
                   );
  }
  NvdNotificationCallback(p_Var1,3,0,'\x01');
  if (param_2 != (void *)0x0) {
    IoFreeWorkItem(param_2);
  }
  IoReleaseRemoveLockEx(p_Var1 + 0xf0,p_Var1,0x20);
  return;
}



===== NvdShouldFakeHealthProblem @ 1c001dfc8 =====

/* bool __cdecl NvdShouldFakeHealthProblem(struct _NVDIMM_DEVICE_EXTENSION * __ptr64) */

bool __cdecl NvdShouldFakeHealthProblem(_NVDIMM_DEVICE_EXTENSION *param_1)

{
  bool bVar1;
  long lVar2;
  int iVar3;
  ulong local_res10 [2];
  undefined8 local_res18 [2];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res10[0] = 0;
  lVar2 = NvdQueryDeviceRegistryUlong
                    (param_1,(ushort *)L"",(ushort *)L"FakeHealthProblem",local_res10);
  if ((lVar2 < 0) || (local_res10[0] == 0)) {
    bVar1 = false;
  }
  else {
    local_res18[0] = 0;
    iVar3 = IoOpenDeviceRegistryKey(*(undefined8 *)(param_1 + 0x10),1,0x20006,local_res18);
    if (-1 < iVar3) {
      local_18 = 0;
      uStack_10 = 0;
      RtlInitUnicodeString(&local_18,L"FakeHealthProblem");
      ZwDeleteValueKey(local_res18[0],&local_18);
      ZwClose(local_res18[0]);
    }
    bVar1 = true;
  }
  return bVar1;
}



===== NvdGetBusInterface @ 1c001e080 =====

/* long __cdecl NvdGetBusInterface(struct _NVDIMM_DEVICE_EXTENSION * __ptr64,struct
   _SCM_BUS_NVD_INTERFACE * __ptr64) */

long __cdecl NvdGetBusInterface(_NVDIMM_DEVICE_EXTENSION *param_1,_SCM_BUS_NVD_INTERFACE *param_2)

{
  longlong lVar1;
  byte bVar2;
  int iVar3;
  longlong lVar4;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  local_38 = 0;
  uStack_30 = 0;
  bVar2 = KeGetCurrentIrql();
  if (bVar2 < 2) {
    memset(param_2 + 4,0,0x8c);
    *(undefined4 *)param_2 = 0xa0090;
    KeInitializeEvent(&local_28,0,0);
    lVar4 = IoBuildSynchronousFsdRequest
                      (0x1b,*(undefined8 *)(param_1 + 8),0,0,0,&local_28,&local_38);
    if (lVar4 == 0) {
      iVar3 = -0x3fffff66;
    }
    else {
      lVar1 = *(longlong *)(lVar4 + 0xb8);
      *(undefined8 *)(lVar4 + 0x38) = 0;
      *(undefined4 *)(lVar4 + 0x30) = 0xc00000bb;
      *(undefined1 *)(lVar1 + -0x47) = 8;
      *(undefined **)(lVar1 + -0x40) = &GUID_SCM_BUS_NVD_INTERFACE;
      *(undefined2 *)(lVar1 + -0x38) = *(undefined2 *)param_2;
      *(undefined2 *)(lVar1 + -0x36) = 10;
      *(_SCM_BUS_NVD_INTERFACE **)(lVar1 + -0x30) = param_2;
      iVar3 = IofCallDriver(*(undefined8 *)(param_1 + 8),lVar4);
      if (iVar3 == 0x103) {
        KeWaitForSingleObject(&local_28,0,0,0,0);
        iVar3 = (int)local_38;
      }
    }
  }
  else {
    iVar3 = -0x3ffffeb8;
  }
  return iVar3;
}



===== NvdCopyDevicePropertyString @ 1c001e1bc =====

/* long __cdecl NvdCopyDevicePropertyString(struct _STORAGE_DEVICE_DESCRIPTOR * __ptr64,unsigned
   long,char * __ptr64 * __ptr64) */

long __cdecl
NvdCopyDevicePropertyString(_STORAGE_DEVICE_DESCRIPTOR *param_1,ulong param_2,char **param_3)

{
  _STORAGE_DEVICE_DESCRIPTOR *p_Var1;
  ulonglong uVar2;
  char *_Dst;
  ulonglong uVar3;
  _STORAGE_DEVICE_DESCRIPTOR *_Src;
  
  _Src = param_1 + param_2;
  if ((_Src != (_STORAGE_DEVICE_DESCRIPTOR *)0x0) &&
     (uVar3 = (ulonglong)(*(int *)(param_1 + 4) - param_2), p_Var1 = _Src, uVar2 = uVar3,
     uVar3 < 0x80000000)) {
    for (; (uVar2 != 0 && (*p_Var1 != (_STORAGE_DEVICE_DESCRIPTOR)0x0)); p_Var1 = p_Var1 + 1) {
      uVar2 = uVar2 - 1;
    }
    if (uVar2 != 0) {
      _Dst = (char *)ExAllocatePool2(0x40,(uVar3 - uVar2) + 1,0x7567764e);
      *param_3 = _Dst;
      if (_Dst == (char *)0x0) {
        return -0x3fffff66;
      }
      memcpy(_Dst,_Src,uVar3 - uVar2);
      return 0;
    }
  }
  WriteTraceEvent((_NVDIMM_DEVICE_EXTENSION *)0x0,2,
                  "NvdCopyDevicePropertyString: Failed to get string length.\n");
  return -0x3ffffff3;
}



===== NvdCreateDeviceGuid @ 1c001e29c =====

/* long __cdecl NvdCreateDeviceGuid(struct _NVDIMM_DEVICE_EXTENSION * __ptr64,struct _GUID *
   __ptr64) */

long __cdecl NvdCreateDeviceGuid(_NVDIMM_DEVICE_EXTENSION *param_1,_GUID *param_2)

{
  long lVar1;
  char *pcVar2;
  void *_Dst;
  ulonglong _Size;
  ulonglong _Size_00;
  ulonglong _Size_01;
  uint uVar3;
  longlong lVar4;
  
  pcVar2 = *(char **)(param_1 + 0x188);
  if (pcVar2 == (char *)0x0) {
    uVar3 = 0xc000000d;
  }
  else {
    lVar4 = 0x7fffffff;
    do {
      if (*pcVar2 == '\0') break;
      pcVar2 = pcVar2 + 1;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
    uVar3 = ~-(uint)(lVar4 != 0) & 0xc000000d;
    _Size_00 = -(ulonglong)(lVar4 != 0) & 0x7fffffffU - lVar4;
    if (lVar4 != 0) {
      pcVar2 = *(char **)(param_1 + 0x180);
      if (pcVar2 == (char *)0x0) {
        uVar3 = 0xc000000d;
      }
      else {
        lVar4 = 0x7fffffff;
        do {
          if (*pcVar2 == '\0') break;
          pcVar2 = pcVar2 + 1;
          lVar4 = lVar4 + -1;
        } while (lVar4 != 0);
        uVar3 = ~-(uint)(lVar4 != 0) & 0xc000000d;
        _Size = -(ulonglong)(lVar4 != 0) & 0x7fffffffU - lVar4;
        if (lVar4 != 0) {
          pcVar2 = *(char **)(param_1 + 0x178);
          if (pcVar2 == (char *)0x0) {
            uVar3 = 0xc000000d;
          }
          else {
            lVar4 = 0x7fffffff;
            do {
              if (*pcVar2 == '\0') break;
              pcVar2 = pcVar2 + 1;
              lVar4 = lVar4 + -1;
            } while (lVar4 != 0);
            uVar3 = ~-(uint)(lVar4 != 0) & 0xc000000d;
            _Size_01 = -(ulonglong)(lVar4 != 0) & 0x7fffffffU - lVar4;
            if (lVar4 != 0) {
              _Dst = (void *)ExAllocatePool2(0x100,_Size_00 + _Size + 1 + _Size_01,0x7567764e);
              if (_Dst == (void *)0x0) {
                return -0x3fffff66;
              }
              memcpy(_Dst,*(void **)(param_1 + 0x188),_Size_00);
              memcpy((void *)(_Size_00 + (longlong)_Dst),*(void **)(param_1 + 0x180),_Size);
              memcpy((void *)(_Size_00 + _Size + (longlong)_Dst),*(void **)(param_1 + 0x178),
                     _Size_01);
              lVar1 = NvdGenerateMD5BasedGuid
                                (_Dst,(int)(_Size_00 + _Size) + (int)_Size_01 + 1,param_2);
              ExFreePoolWithTag(_Dst,0);
              return lVar1;
            }
          }
          return uVar3;
        }
      }
    }
  }
  return uVar3;
}



===== NvdGenerateMD5BasedGuid @ 1c001e474 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl NvdGenerateMD5BasedGuid(void * __ptr64,unsigned long,struct _GUID * __ptr64) */

long __cdecl NvdGenerateMD5BasedGuid(void *param_1,ulong param_2,_GUID *param_3)

{
  code *pcVar1;
  undefined8 uVar2;
  NTSTATUS NVar3;
  undefined1 *puVar4;
  undefined8 uStackY_80;
  undefined1 auStackY_78 [8];
  undefined1 auStackY_70 [24];
  BCRYPT_HASH_HANDLE local_38 [3];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_78;
  local_38[0] = (BCRYPT_HASH_HANDLE)0x0;
  local_38[1] = (BCRYPT_HASH_HANDLE)0x0;
  local_38[2] = (BCRYPT_HASH_HANDLE)0x0;
  NVar3 = BCryptCreateHash((BCRYPT_ALG_HANDLE)0x21,local_38,(PUCHAR)0x0,0,(PUCHAR)0x0,0,0);
  puVar4 = auStackY_78;
  if (NVar3 < 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(7);
    puVar4 = auStackY_70;
  }
  *(undefined8 *)(puVar4 + -8) = 0x1c001e4ee;
  NVar3 = BCryptHashData(*(BCRYPT_HASH_HANDLE *)(puVar4 + 0x40),param_1,param_2,0);
  if (NVar3 < 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(7);
    puVar4 = puVar4 + 8;
  }
  *(undefined8 *)(puVar4 + -8) = 0x1c001e514;
  NVar3 = BCryptFinishHash(*(BCRYPT_HASH_HANDLE *)(puVar4 + 0x40),puVar4 + 0x48,0x10,0);
  if (NVar3 < 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(7);
    puVar4 = puVar4 + 8;
  }
  *(undefined8 *)(puVar4 + -8) = 0x1c001e52e;
  BCryptDestroyHash(*(BCRYPT_HASH_HANDLE *)(puVar4 + 0x40));
  uVar2 = *(undefined8 *)(puVar4 + 0x50);
  *(undefined8 *)param_3 = *(undefined8 *)(puVar4 + 0x48);
  *(undefined8 *)(param_3 + 8) = uVar2;
  *(undefined8 *)(puVar4 + -8) = 0x1c001e54b;
  return 0;
}



===== NvdGetDeviceDescriptor @ 1c001e564 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl NvdGetDeviceDescriptor(struct _NVDIMM_DEVICE_EXTENSION * __ptr64,struct
   _STORAGE_DEVICE_DESCRIPTOR * __ptr64 * __ptr64) */

long __cdecl
NvdGetDeviceDescriptor(_NVDIMM_DEVICE_EXTENSION *param_1,_STORAGE_DEVICE_DESCRIPTOR **param_2)

{
  long lVar1;
  _IRP *p_Var2;
  _STORAGE_DEVICE_DESCRIPTOR *p_Var3;
  uint uVar4;
  char *pcVar5;
  undefined1 auStack_a8 [32];
  _STORAGE_DEVICE_DESCRIPTOR *local_88;
  uint local_80;
  undefined1 local_78;
  undefined8 local_70;
  undefined8 *local_68;
  undefined8 local_58;
  undefined8 local_50;
  ulonglong uStack_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_a8;
  *param_2 = (_STORAGE_DEVICE_DESCRIPTOR *)0x0;
  local_68 = &local_50;
  local_38 = 0;
  local_40 = 0;
  local_3c = 0;
  local_58 = 0;
  local_70 = 0;
  local_88 = (_STORAGE_DEVICE_DESCRIPTOR *)&local_58;
  local_78 = 0;
  local_80 = 8;
  local_50 = 0;
  uStack_48 = 0;
  p_Var2 = (_IRP *)IoBuildDeviceIoControlRequest(0x2d1400,*(undefined8 *)param_1,&local_40,0xc);
  if (p_Var2 != (_IRP *)0x0) {
    lVar1 = NvdSendIrpSynchronous(*(_DEVICE_OBJECT **)(param_1 + 8),p_Var2);
    *(long *)(p_Var2 + 0x30) = lVar1;
    IofCompleteRequest(p_Var2,0);
    if (lVar1 < 0) {
      pcVar5 = "NvdGetDeviceDescriptor: 1st STORAGE_QUERY_PROPERTY IRP failed\n";
LAB_1c001e6de:
      WriteTraceEvent(param_1,2,pcVar5);
      goto LAB_1c001e6eb;
    }
    uVar4 = local_58._4_4_;
    if (local_58._4_4_ < 9) {
      uVar4 = 8;
    }
    p_Var3 = (_STORAGE_DEVICE_DESCRIPTOR *)ExAllocatePool2(0x40,uVar4,0x7567764e);
    *param_2 = p_Var3;
    if (p_Var3 != (_STORAGE_DEVICE_DESCRIPTOR *)0x0) {
      local_68 = &local_50;
      local_70 = 0;
      local_78 = 0;
      local_88 = p_Var3;
      local_80 = uVar4;
      p_Var2 = (_IRP *)IoBuildDeviceIoControlRequest(0x2d1400,*(undefined8 *)param_1,&local_40,0xc);
      if (p_Var2 != (_IRP *)0x0) {
        lVar1 = NvdSendIrpSynchronous(*(_DEVICE_OBJECT **)(param_1 + 8),p_Var2);
        *(long *)(p_Var2 + 0x30) = lVar1;
        IofCompleteRequest(p_Var2,0);
        if (-1 < lVar1) {
          if (uStack_48 == uVar4) {
            return lVar1;
          }
          lVar1 = -0x3fffffff;
        }
        pcVar5 = "NvdGetDeviceDescriptor: 2nd STORAGE_QUERY_PROPERTY IRP failed\n";
        goto LAB_1c001e6de;
      }
    }
  }
  lVar1 = -0x3fffff66;
LAB_1c001e6eb:
  if (*param_2 != (_STORAGE_DEVICE_DESCRIPTOR *)0x0) {
    ExFreePoolWithTag(*param_2,0);
    *param_2 = (_STORAGE_DEVICE_DESCRIPTOR *)0x0;
  }
  return lVar1;
}



===== NvdGetIdentifyingInfo @ 1c001e734 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl NvdGetIdentifyingInfo(struct _NVDIMM_DEVICE_EXTENSION * __ptr64) */

long __cdecl NvdGetIdentifyingInfo(_NVDIMM_DEVICE_EXTENSION *param_1)

{
  _STORAGE_DEVICE_DESCRIPTOR *p_Var1;
  uint uVar2;
  _STORAGE_DEVICE_DESCRIPTOR *local_res8;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  local_38 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0x3800000002;
  local_48 = 0;
  uStack_40 = 0;
  uVar2 = (**(code **)(param_1 + 0x88))(*(undefined8 *)(param_1 + 0x58),&local_68);
  if ((int)uVar2 < 0) {
    WriteTraceEvent(param_1,2,"NvdGetIdentifyingInfo: NvdGetProductInfo() failed with 0x%x\n",
                    (ulonglong)uVar2);
  }
  else {
    *(char **)(param_1 + 0x188) = (char *)0x0;
    *(char **)(param_1 + 0x180) = (char *)0x0;
    *(char **)(param_1 + 0x178) = (char *)0x0;
    local_res8 = (_STORAGE_DEVICE_DESCRIPTOR *)0x0;
    *(undefined4 *)(param_1 + 0x174) = (undefined4)local_58;
    *(uint *)(param_1 + 0x164) = (uint)uStack_60._2_2_;
    *(uint *)(param_1 + 0x160) = (uint)(ushort)uStack_60;
    *(uint *)(param_1 + 0x168) = (uint)local_58._4_2_;
    *(uint *)(param_1 + 0x16c) = (uint)local_58._6_2_;
    param_1[0x170] = uStack_60._4_1_;
    param_1[0x171] = uStack_60._5_1_;
    param_1[0x172] = uStack_60._6_1_;
    *(undefined8 *)(param_1 + 0x138) = uStack_50;
    *(undefined8 *)(param_1 + 0x140) = local_48;
    *(undefined8 *)(param_1 + 0x148) = uStack_40;
    *(undefined8 *)(param_1 + 0x150) = local_38;
    uVar2 = NvdGetDeviceDescriptor(param_1,&local_res8);
    p_Var1 = local_res8;
    if (-1 < (int)uVar2) {
      if (*(ulong *)(local_res8 + 0x18) != 0) {
        uVar2 = NvdCopyDevicePropertyString
                          (local_res8,*(ulong *)(local_res8 + 0x18),(char **)(param_1 + 0x188));
      }
      if ((*(int *)(p_Var1 + 0x18) == 0) || ((int)uVar2 < 0)) {
        WriteTraceEvent(param_1,2,"NvdGetIdentifyingInfo: couldn\'t copy serial number\n");
        uVar2 = 0xc0000001;
      }
      else {
        if (*(ulong *)(p_Var1 + 0x10) != 0) {
          NvdCopyDevicePropertyString(p_Var1,*(ulong *)(p_Var1 + 0x10),(char **)(param_1 + 0x180));
        }
        if (*(ulong *)(p_Var1 + 0xc) != 0) {
          NvdCopyDevicePropertyString(p_Var1,*(ulong *)(p_Var1 + 0xc),(char **)(param_1 + 0x178));
        }
      }
      ExFreePoolWithTag(p_Var1,0);
    }
  }
  return uVar2;
}



===== PrepareWheaErrorData @ 1c001e8d8 =====

void `anonymous_namespace'::PrepareWheaErrorData(longlong param_1,longlong param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(param_2 + 4);
  uVar2 = (*param_3 ^ uVar1) & 1 ^ *param_3;
  uVar2 = (uVar1 ^ uVar2) & 2 ^ uVar2;
  uVar2 = (uVar2 ^ uVar1) & 4 ^ uVar2;
  uVar2 = (uVar2 ^ uVar1) & 8 ^ uVar2;
  uVar2 = (uVar2 ^ uVar1) & 0x10 ^ uVar2;
  uVar2 = (uVar2 ^ uVar1) & 0x20 ^ uVar2;
  *param_3 = ((uint)*(byte *)(param_1 + 0xe2) << 6 ^ uVar2) & 0x40 ^ uVar2;
  return;
}



===== PrepareWheaErrorData @ 1c001e93c =====

void `anonymous_namespace'::PrepareWheaErrorData
               (undefined8 param_1,longlong param_2,undefined4 param_3,longlong param_4,
               undefined4 param_5,byte *param_6)

{
  undefined8 uVar1;
  byte bVar2;
  
  bVar2 = (*(byte *)(param_2 + 0xc) >> 2 ^ *param_6) & 1 ^ *param_6;
  *param_6 = bVar2;
  bVar2 = (bVar2 ^ *(byte *)(param_2 + 0xc)) & 2 ^ bVar2;
  *param_6 = bVar2;
  *param_6 = (*(char *)(param_2 + 0xc) << 2 ^ bVar2) & 4 ^ bVar2;
  param_6[1] = *(byte *)(param_2 + 0xd);
  param_6[2] = *(byte *)(param_2 + 0xe);
  bVar2 = (param_6[3] ^ *(byte *)(param_2 + 0xf)) & 1 ^ param_6[3];
  param_6[3] = bVar2;
  bVar2 = (bVar2 ^ *(byte *)(param_2 + 0xf)) & 2 ^ bVar2;
  param_6[3] = bVar2;
  param_6[3] = (bVar2 ^ *(byte *)(param_2 + 0xf)) & 4 ^ bVar2;
  *(undefined2 *)(param_6 + 4) = *(undefined2 *)(param_2 + 0x10);
  *(undefined2 *)(param_6 + 6) = *(undefined2 *)(param_2 + 0x12);
  *(undefined4 *)(param_6 + 8) = *(undefined4 *)(param_2 + 0x14);
  param_6[0xc] = *(byte *)(param_2 + 0x18);
  param_6[0xd] = *(byte *)(param_2 + 0x23);
  param_6[0xe] = *(byte *)(param_4 + 4);
  param_6[0xf] = *(byte *)(param_4 + 5);
  *(undefined4 *)(param_6 + 0x14) = param_5;
  *(undefined4 *)(param_6 + 0x10) = param_3;
  *(undefined4 *)(param_6 + 0x18) = *(undefined4 *)(param_2 + 0x24);
  uVar1 = *(undefined8 *)(param_2 + 0x30);
  *(undefined8 *)(param_6 + 0x1c) = *(undefined8 *)(param_2 + 0x28);
  *(undefined8 *)(param_6 + 0x24) = uVar1;
  uVar1 = *(undefined8 *)(param_2 + 0x40);
  *(undefined8 *)(param_6 + 0x2c) = *(undefined8 *)(param_2 + 0x38);
  *(undefined8 *)(param_6 + 0x34) = uVar1;
  uVar1 = *(undefined8 *)(param_2 + 0x50);
  *(undefined8 *)(param_6 + 0x3c) = *(undefined8 *)(param_2 + 0x48);
  *(undefined8 *)(param_6 + 0x44) = uVar1;
  uVar1 = *(undefined8 *)(param_2 + 0x60);
  *(undefined8 *)(param_6 + 0x4c) = *(undefined8 *)(param_2 + 0x58);
  *(undefined8 *)(param_6 + 0x54) = uVar1;
  uVar1 = *(undefined8 *)(param_2 + 0x70);
  *(undefined8 *)(param_6 + 0x5c) = *(undefined8 *)(param_2 + 0x68);
  *(undefined8 *)(param_6 + 100) = uVar1;
  *(undefined8 *)(param_6 + 0x6c) = *(undefined8 *)(param_2 + 0x78);
  *(undefined4 *)(param_6 + 0x74) = *(undefined4 *)(param_2 + 0x80);
  return;
}



===== AbortFirmwareUpdate @ 1c001ea58 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: long __cdecl INvdimmFwUpdater::AbortFirmwareUpdate(void) __ptr64 */

long __thiscall INvdimmFwUpdater::AbortFirmwareUpdate(INvdimmFwUpdater *this)

{
  int iVar1;
  char *pcVar2;
  undefined1 auStackY_68 [32];
  uint local_28 [2];
  undefined4 local_20;
  undefined4 uStack_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_28[0] = 0;
  WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 8),4,
                  "FwUpdater::AbortFirmwareUpdate(): Aborting the firmware update.");
  _local_20 = CONCAT44(*(undefined4 *)(this + 0x48),1);
  iVar1 = IDsmFinishFirmwareUpdate(*(longlong *)(this + 8) + 0x50,&local_20,local_28);
  if (iVar1 < 0) {
    pcVar2 = "FwUpdater::AbortFirmwareUpdate(): Finish FW Update failed with NTSTATUS 0x%x";
  }
  else {
    iVar1 = FUNCTION_SPECIFIC_IDSM_STATUS_TO_NTSTATUS(local_28[0],0xf);
    if (-1 < iVar1) goto LAB_1c001eafb;
    pcVar2 = "FwUpdater::AbortFirmwareUpdate(): Finish FW Update failed with IDSM status 0x%x";
  }
  WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 8),2,pcVar2);
LAB_1c001eafb:
  INvdimmTelemetry::LogFwUpdate
            (*(INvdimmTelemetry **)(this + 0x10),(ushort *)L"AbortFirmwareUpdate",iVar1,
             (_IDSM_STATUS *)local_28,*(State *)(this + 0x44),(_IDSM_FIRMWARE_INFO *)(this + 0x18),
             *(__uint64 *)(this + 0x50));
  return iVar1;
}



===== DownloadFirmwareChunk @ 1c001eb54 =====

/* private: long __cdecl INvdimmFwUpdater::DownloadFirmwareChunk(void * __ptr64,unsigned
   short,unsigned __int64) __ptr64 */

long __thiscall
INvdimmFwUpdater::DownloadFirmwareChunk
          (INvdimmFwUpdater *this,void *param_1,ushort param_2,__uint64 param_3)

{
  ulonglong _Size;
  int iVar1;
  undefined4 *puVar2;
  _NVDIMM_DEVICE_EXTENSION *p_Var3;
  uint uVar4;
  long lVar5;
  char *pcVar6;
  uint uVar7;
  uint local_res18 [2];
  __uint64 _Var8;
  undefined4 uVar9;
  undefined8 in_stack_ffffffffffffffc0;
  undefined4 uVar10;
  
  uVar10 = (undefined4)((ulonglong)in_stack_ffffffffffffffc0 >> 0x20);
  _Size = (ulonglong)param_2;
  local_res18[0] = 0;
  uVar4 = (uint)param_2;
  _Var8 = param_3;
  WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 8),4,
                  "FwUpdater::DownloadFirmwareChunk(): Downloading 0x%x bytes at offset 0x%llx",
                  _Size,param_3);
  uVar9 = (undefined4)(_Var8 >> 0x20);
  if (*(uint *)(this + 0x20) < uVar4) {
    WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 8),3,
                    "FwUpdater::DownloadFirmwareChunk(): specified firmware image size (0x%x) is larger than max data per transfer (0x%x)"
                    ,_Size,CONCAT44(uVar9,*(uint *)(this + 0x20)));
  }
  else {
    uVar7 = *(uint *)(this + 0x1c);
    if (((uVar7 < param_3) || ((ulonglong)uVar7 < _Size + param_3)) || (0xffffffff < param_3)) {
      WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 8),3,
                      "FwUpdater::DownloadFirmwareChunk(): The region offset (0x%x) and chunk size (0x%x) exceed the max fw image storage area size (0x%x)"
                      ,param_3,CONCAT44(uVar9,uVar4),CONCAT44(uVar10,uVar7));
    }
    else {
      uVar7 = uVar4 + 0xc;
      if (uVar7 < 0x10000) {
        puVar2 = (undefined4 *)ExAllocatePool2(0x100,uVar7,0x7766764e);
        if (puVar2 != (undefined4 *)0x0) {
          *puVar2 = *(undefined4 *)(this + 0x48);
          puVar2[2] = uVar4;
          puVar2[1] = (int)param_3;
          memcpy(puVar2 + 3,param_1,_Size);
          iVar1 = IDsmSendFirmwareUpdateData
                            (*(longlong *)(this + 8) + 0x50,puVar2,(short)uVar7,local_res18);
          if (iVar1 < 0) {
            p_Var3 = *(_NVDIMM_DEVICE_EXTENSION **)(this + 8);
            pcVar6 = 
            "FwUpdater::DownloadFirmwareChunk(): Send FW Update Data call failed with NTSTATUS 0x%x"
            ;
          }
          else {
            iVar1 = FUNCTION_SPECIFIC_IDSM_STATUS_TO_NTSTATUS(local_res18[0],0xe);
            p_Var3 = *(_NVDIMM_DEVICE_EXTENSION **)(this + 8);
            if (-1 < iVar1) {
              WriteTraceEvent(p_Var3,5,"FwUpdater::DownloadFirmwareChunk(): Completed the download")
              ;
              operator_delete(puVar2);
              return iVar1;
            }
            pcVar6 = 
            "FwUpdater::DownloadFirmwareChunk(): Send FW Update Data failed with IDSM status 0x%x";
          }
          WriteTraceEvent(p_Var3,2,pcVar6);
          operator_delete(puVar2);
          INvdimmTelemetry::LogFwUpdate
                    (*(INvdimmTelemetry **)(this + 0x10),(ushort *)L"DownloadFirmwareChunk",iVar1,
                     (_IDSM_STATUS *)local_res18,*(State *)(this + 0x44),
                     (_IDSM_FIRMWARE_INFO *)(this + 0x18),*(__uint64 *)(this + 0x50));
          return iVar1;
        }
        lVar5 = -0x3fffff66;
        goto LAB_1c001ed2f;
      }
    }
  }
  lVar5 = -0x3ffffff3;
LAB_1c001ed2f:
  INvdimmTelemetry::LogFwUpdate
            (*(INvdimmTelemetry **)(this + 0x10),(ushort *)L"DownloadFirmwareChunk",lVar5,
             (_IDSM_STATUS *)local_res18,*(State *)(this + 0x44),
             (_IDSM_FIRMWARE_INFO *)(this + 0x18),*(__uint64 *)(this + 0x50));
  return lVar5;
}



===== DownloadFirmwareRegions @ 1c001ed8c =====

/* public: long __cdecl INvdimmFwUpdater::DownloadFirmwareRegions(void * __ptr64,unsigned
   long,unsigned __int64,bool) __ptr64 */

long __thiscall
INvdimmFwUpdater::DownloadFirmwareRegions
          (INvdimmFwUpdater *this,void *param_1,ulong param_2,__uint64 param_3,bool param_4)

{
  INvdimmFwUpdater *pIVar1;
  uint uVar2;
  uint uVar3;
  _NVDIMM_DEVICE_EXTENSION *p_Var4;
  ulong uVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  uint uVar11;
  INvdimmFwUpdater *pIVar12;
  uint local_res8 [2];
  void *local_res10;
  ulong local_res18;
  __uint64 local_res20;
  __uint64 _Var13;
  undefined2 local_70;
  undefined4 local_6e;
  undefined2 local_6a;
  uint *local_68;
  INvdimmFwUpdater *local_60;
  undefined1 local_58;
  
  pIVar1 = this + 0x58;
  local_res10 = param_1;
  local_res18 = param_2;
  local_res20 = param_3;
  KeWaitForSingleObject(pIVar1,0,0,0,0);
  uVar6 = *(uint *)(this + 0x44);
  uVar9 = (ulonglong)uVar6;
  local_68 = local_res8;
  local_res8[0] = 0;
  local_58 = 1;
  local_60 = this;
  if (uVar6 == 5) {
    local_70 = 0;
    local_6e = 0;
    local_6a = 0;
    local_res8[0] =
         GetDeviceRuntimeFirmwareActivationInfo
                   (this,(_IDSM_GET_DEVICE_RUNTIME_FW_ACTIVATION_INFO_OUTPUT *)&local_70);
    if ((char)local_6a == '\x02') {
      uVar10 = 2;
LAB_1c001ee2b:
      WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 8),2,
                      "FwUpdater::DownloadFirmwareRegions(): Previous runtime FW activation is still in progress (FW activation state = %d)"
                      ,uVar10);
      local_res8[0] = 0xc0000184;
      wil::details::lambda_call<<lambda_19680483569ec4d991ca082b80196242>_>::
      ~lambda_call<<lambda_19680483569ec4d991ca082b80196242>_>(&local_68);
      KeReleaseMutex(pIVar1,0);
      return -0x3ffffe7c;
    }
    if (local_6e._2_2_ == 4) {
      uVar10 = 4;
      goto LAB_1c001ee2b;
    }
    if (local_6e._2_2_ == 3) {
      p_Var4 = *(_NVDIMM_DEVICE_EXTENSION **)(this + 8);
      pcVar8 = 
      "FwUpdater::DownloadFirmwareRegions(): Device state invalid (Last FW activation status = %d)";
      *(undefined4 *)(this + 0x44) = 3;
      uVar9 = 3;
      uVar5 = 2;
      goto LAB_1c001ef30;
    }
    *(undefined4 *)(this + 0x44) = 0;
LAB_1c001ee9d:
    local_res8[0] = StartFirmwareUpdate(this);
    if ((int)local_res8[0] < 0) goto LAB_1c001f038;
    *(undefined4 *)(this + 0x44) = 1;
  }
  else {
    if (uVar6 == 0) goto LAB_1c001ee9d;
    if (uVar6 != 1) {
      p_Var4 = *(_NVDIMM_DEVICE_EXTENSION **)(this + 8);
      pcVar8 = "FwUpdater::DownloadFirmwareRegions(): Invalid state (state = %d)";
      uVar5 = 3;
LAB_1c001ef30:
      WriteTraceEvent(p_Var4,uVar5,pcVar8,uVar9);
      local_res8[0] = 0xc0000184;
      goto LAB_1c001f038;
    }
  }
  pIVar12 = this + 8;
  uVar11 = (uint)param_4;
  _Var13 = local_res20;
  WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)pIVar12,4,
                  "FwUpdater::DownloadFirmwareRegions(): Downloading 0x%x bytes at offset 0x%llx; IsLastRegion = %d"
                  ,(ulonglong)param_2,local_res20,uVar11);
  uVar6 = *(uint *)(this + 0x20);
  if (uVar6 < 0xfff3) {
    if (uVar6 == 0) {
      WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)pIVar12,2,
                      "FwUpdater::DownloadFirmwareRegions(): The maximum transfer size reported by the _DSM is 0 bytes"
                     );
      local_res8[0] = 0xc0000001;
      goto LAB_1c001f038;
    }
  }
  else {
    uVar6 = 0xfff3;
  }
  uVar2 = param_2 / uVar6 + 1;
  if (param_2 <= param_2 - param_2 % uVar6) {
    uVar2 = param_2 / uVar6;
  }
  WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)pIVar12,4,
                  "FwUpdater::DownloadFirmwareRegions(): splitting region into %d chunks",
                  (ulonglong)uVar2,_Var13,uVar11);
  uVar11 = 0;
  if (uVar2 != 0) {
    do {
      uVar3 = uVar11 * uVar6;
      uVar7 = local_res18 - uVar3;
      if (uVar6 <= uVar7) {
        uVar7 = uVar6 & 0xffff;
      }
      local_res8[0] =
           DownloadFirmwareChunk
                     (this,(void *)((longlong)local_res10 + (ulonglong)uVar3),(ushort)uVar7,
                      local_res20 + uVar3);
      if ((int)local_res8[0] < 0) {
        pcVar8 = 
        "FwUpdater::DownloadFirmwareRegions(): Error downloading chunk (NTSTATUS 0x%x); giving up";
        goto LAB_1c001f01f;
      }
      uVar11 = uVar11 + 1;
    } while (uVar11 < uVar2);
  }
  if (param_4) {
    *(undefined4 *)(this + 0x44) = 2;
    local_res8[0] = FinishFirmwareUpdate(this);
    if (-1 < (int)local_res8[0]) {
      if (((byte)this[0x2c] & 2) == 0) {
        *(undefined4 *)(this + 0x44) = 3;
      }
      else {
        *(undefined4 *)(this + 0x44) = 5;
        local_res8[0] = SetDeviceRuntimeFirmwareActivationArmState(this,1);
        if ((int)local_res8[0] < 0) {
          pcVar8 = "FwUpdater::DownloadFirmwareRegions(): arm device failed with NTSTATUS 0x%x";
LAB_1c001f01f:
          WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)pIVar12,2,pcVar8,(ulonglong)local_res8[0]);
        }
      }
    }
  }
  else {
    local_res8[0] = 0;
  }
LAB_1c001f038:
  uVar6 = local_res8[0];
  wil::details::lambda_call<<lambda_19680483569ec4d991ca082b80196242>_>::
  ~lambda_call<<lambda_19680483569ec4d991ca082b80196242>_>(&local_68);
  KeReleaseMutex(pIVar1,0);
  return uVar6;
}



===== FinishFirmwareUpdate @ 1c001f06c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: long __cdecl INvdimmFwUpdater::FinishFirmwareUpdate(void) __ptr64 */

long __thiscall INvdimmFwUpdater::FinishFirmwareUpdate(INvdimmFwUpdater *this)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  _NVDIMM_DEVICE_EXTENSION *p_Var5;
  ulonglong uVar6;
  ulonglong uVar7;
  undefined1 auStackY_98 [32];
  State SVar8;
  __uint64 _Var9;
  uint local_58 [2];
  longlong local_50;
  uint local_48;
  undefined4 uStack_44;
  undefined4 local_40;
  longlong local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_98;
  local_58[0] = 0;
  WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 8),4,
                  "FwUpdater::FinishFirmwareUpdate(): Finishing the firmware update.");
  local_38 = (ulonglong)*(uint *)(this + 0x48) << 0x20;
  iVar2 = IDsmFinishFirmwareUpdate(*(longlong *)(this + 8) + 0x50,&local_38,local_58);
  p_Var5 = *(_NVDIMM_DEVICE_EXTENSION **)(this + 8);
  if (iVar2 < 0) {
    pcVar4 = "FwUpdater::FinishFirmwareUpdate(): Finish FW Update failed with NTSTATUS 0x%x";
  }
  else {
    iVar2 = FUNCTION_SPECIFIC_IDSM_STATUS_TO_NTSTATUS(local_58[0],0xf);
    if (-1 < iVar2) {
      WriteTraceEvent(p_Var5,4,
                      "FwUpdater::FinishFirmwareUpdate(): Finish FW Update _DSM succeeded. Polling for completion (interval = %d usecs; timeout = %d uSecs)"
                      ,(ulonglong)*(uint *)(this + 0x24));
      iVar2 = *(int *)(this + 0x28);
      bVar1 = false;
      uVar6 = 0;
      while( true ) {
        local_48 = 0;
        uStack_44 = 0;
        local_40 = 0;
        uVar3 = IDsmQueryFinishFwUpdateStatus
                          (*(longlong *)(this + 8) + 0x50,*(undefined4 *)(this + 0x48),&local_48);
        uVar7 = (ulonglong)uVar3;
        if ((int)uVar3 < 0) break;
        uVar3 = FUNCTION_SPECIFIC_IDSM_STATUS_TO_NTSTATUS(local_48,0x10);
        if (uVar3 == 0) {
          *(ulonglong *)(this + 0x50) = CONCAT44(local_40,uStack_44);
          WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 8),4,
                          "FwUpdater::QueryFinishFirmwareUpdateStatus(): Query Finish FW Update Status succeeded (dsmStatus.AsUlong = 0x%x). The new firmware revision is 0x%x"
                         );
          bVar1 = true;
        }
        else if (uVar3 == 0x103) {
          bVar1 = false;
          uVar3 = 0;
        }
        else {
          WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 8),2,
                          "FwUpdater::QueryFinishFirmwareUpdateStatus(): Query Finish FW Update Status failed (dsmStatus.AsUlong = 0x%x)"
                         );
          if ((int)uVar3 < 0) {
            INvdimmTelemetry::LogFwUpdate
                      (*(INvdimmTelemetry **)(this + 0x10),(ushort *)L"QueryFinishFirmwareUpdate",
                       uVar3,(_IDSM_STATUS *)&local_48,*(State *)(this + 0x44),
                       (_IDSM_FIRMWARE_INFO *)(this + 0x18),*(__uint64 *)(this + 0x50));
          }
        }
        uVar7 = (ulonglong)uVar3;
        if ((int)uVar3 < 0) goto LAB_1c001f345;
        if (!bVar1) {
          local_50 = (ulonglong)*(uint *)(this + 0x24) * -10;
          uVar6 = uVar6 + *(uint *)(this + 0x24);
          KeDelayExecutionThread(0,0,&local_50);
        }
        if (iVar2 + 10000000 <= uVar6) {
          WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 8),2,
                          "FwUpdater::FinishFirmwareUpdate(): firmware update timed out after %llu microseconds."
                          ,uVar6);
          _Var9 = *(__uint64 *)(this + 0x50);
          uVar3 = 0xc000047d;
          SVar8 = *(State *)(this + 0x44);
          goto LAB_1c001f373;
        }
        if (bVar1) {
          WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 8),4,
                          "FwUpdater::FinishFirmwareUpdate(): firmware update completed.");
          INvdimmTelemetry::LogFwUpdate
                    (*(INvdimmTelemetry **)(this + 0x10),(ushort *)L"FinishFirmwareUpdate",0,
                     (_IDSM_STATUS *)local_58,*(State *)(this + 0x44),
                     (_IDSM_FIRMWARE_INFO *)(this + 0x18),*(__uint64 *)(this + 0x50));
          return 0;
        }
      }
      WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 8),2,
                      "FwUpdater::QueryFinishFirmwareUpdateStatus(): Query Finish FW Update Status failed with NTSTATUS 0x%x"
                      ,uVar7);
      INvdimmTelemetry::LogFwUpdate
                (*(INvdimmTelemetry **)(this + 0x10),(ushort *)L"QueryFinishFirmwareUpdate",uVar3,
                 (_IDSM_STATUS *)&local_48,*(State *)(this + 0x44),
                 (_IDSM_FIRMWARE_INFO *)(this + 0x18),*(__uint64 *)(this + 0x50));
LAB_1c001f345:
      WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 8),2,
                      "FwUpdater::FinishFirmwareUpdate(): Polling failed with NTSTATUS 0x%x",uVar7);
      _Var9 = *(__uint64 *)(this + 0x50);
      SVar8 = *(State *)(this + 0x44);
LAB_1c001f373:
      INvdimmTelemetry::LogFwUpdate
                (*(INvdimmTelemetry **)(this + 0x10),(ushort *)L"FinishFirmwareUpdate",uVar3,
                 (_IDSM_STATUS *)local_58,SVar8,(_IDSM_FIRMWARE_INFO *)(this + 0x18),_Var9);
      return uVar3;
    }
    pcVar4 = "FwUpdater::FinishFirmwareUpdate(): Finish FW Update failed with IDSM status 0x%x";
  }
  WriteTraceEvent(p_Var5,2,pcVar4);
  INvdimmTelemetry::LogFwUpdate
            (*(INvdimmTelemetry **)(this + 0x10),(ushort *)L"FinishFirmwareUpdate",iVar2,
             (_IDSM_STATUS *)local_58,*(State *)(this + 0x44),(_IDSM_FIRMWARE_INFO *)(this + 0x18),
             *(__uint64 *)(this + 0x50));
  return iVar2;
}



===== GetDeviceRuntimeFirmwareActivationInfo @ 1c001f3c0 =====

/* public: long __cdecl INvdimmFwUpdater::GetDeviceRuntimeFirmwareActivationInfo(struct
   _IDSM_GET_DEVICE_RUNTIME_FW_ACTIVATION_INFO_OUTPUT * __ptr64) __ptr64 */

long __thiscall
INvdimmFwUpdater::GetDeviceRuntimeFirmwareActivationInfo
          (INvdimmFwUpdater *this,_IDSM_GET_DEVICE_RUNTIME_FW_ACTIVATION_INFO_OUTPUT *param_1)

{
  short sVar1;
  int iVar2;
  
  iVar2 = IDsmGetDeviceRuntimeFwActivationInfo(*(longlong *)(this + 8) + 0x50,param_1);
  if (-1 < iVar2) {
    if (*(short *)param_1 == 0) {
      if ((*(int *)(this + 0x44) == 5) &&
         (param_1[6] == (_IDSM_GET_DEVICE_RUNTIME_FW_ACTIVATION_INFO_OUTPUT)0x0)) {
        sVar1 = *(short *)(param_1 + 4);
        if (((ushort)(sVar1 - 1U) < 2) || ((ushort)(sVar1 - 6U) < 2)) {
          *(undefined4 *)(this + 0x44) = 0;
        }
        else if (sVar1 == 3) {
          *(undefined4 *)(this + 0x44) = 3;
        }
      }
      iVar2 = 0;
    }
    else {
      sVar1 = (short)*(undefined4 *)param_1;
      iVar2 = 0;
      if (sVar1 != 0) {
        if (sVar1 == 1) {
          iVar2 = -0x3fffff45;
        }
        else if (sVar1 == 3) {
          iVar2 = -0x3ffffff3;
        }
        else if (sVar1 == 2) {
          iVar2 = -0x3ffffff2;
        }
        else if (sVar1 == 5) {
          iVar2 = -0x3ffffb8a;
        }
        else if (sVar1 == 10) {
          iVar2 = -0x3ffffe7c;
        }
        else {
          iVar2 = -0x3fffffff;
          if (sVar1 == 0xb) {
            iVar2 = -0x3ffffff3;
          }
        }
      }
    }
  }
  return iVar2;
}



===== GetFirmwareInfo @ 1c001f4ac =====

/* public: static long __cdecl INvdimmFwUpdater::GetFirmwareInfo(struct _NVDIMM_DEVICE_EXTENSION *
   __ptr64,struct _IDSM_FIRMWARE_INFO * __ptr64) */

long __cdecl
INvdimmFwUpdater::GetFirmwareInfo(_NVDIMM_DEVICE_EXTENSION *param_1,_IDSM_FIRMWARE_INFO *param_2)

{
  short sVar1;
  int iVar2;
  
  iVar2 = IDsmGetFirmwareInformation((longlong)(param_1 + 0x50),param_2);
  if (-1 < iVar2) {
    if (*(short *)param_2 == 0) {
      iVar2 = 0;
    }
    else {
      sVar1 = (short)*(undefined4 *)param_2;
      iVar2 = 0;
      if (sVar1 != 0) {
        if (sVar1 == 1) {
          iVar2 = -0x3fffff45;
        }
        else if (sVar1 == 3) {
          iVar2 = -0x3ffffff3;
        }
        else if (sVar1 == 2) {
          iVar2 = -0x3ffffff2;
        }
        else if (sVar1 == 5) {
          iVar2 = -0x3ffffb8a;
        }
        else if (sVar1 == 10) {
          iVar2 = -0x3ffffe7c;
        }
        else {
          iVar2 = -0x3fffffff;
          if (sVar1 == 0xb) {
            iVar2 = -0x3ffffff3;
          }
        }
      }
    }
  }
  return iVar2;
}



===== SetDeviceRuntimeFirmwareActivationArmState @ 1c001f540 =====

/* public: long __cdecl INvdimmFwUpdater::SetDeviceRuntimeFirmwareActivationArmState(enum
   _IDSM_FW_ACTIVATION_ARM_STATE) __ptr64 */

long __thiscall
INvdimmFwUpdater::SetDeviceRuntimeFirmwareActivationArmState
          (INvdimmFwUpdater *this,_IDSM_FW_ACTIVATION_ARM_STATE param_1)

{
  int iVar1;
  undefined4 local_res8 [8];
  
  local_res8[0] = 0;
  iVar1 = IDsmSetDeviceRuntimeFwActivationArmState
                    (*(longlong *)(this + 8) + 0x50,(char)param_1,local_res8);
  if (-1 < iVar1) {
    if ((short)local_res8[0] == 0) {
      iVar1 = 0;
    }
    else if ((short)local_res8[0] == 1) {
      iVar1 = -0x3fffff45;
    }
    else if ((short)local_res8[0] == 3) {
      iVar1 = -0x3ffffff3;
    }
    else if ((short)local_res8[0] == 2) {
      iVar1 = -0x3ffffff2;
    }
    else if ((short)local_res8[0] == 5) {
      iVar1 = -0x3ffffb8a;
    }
    else if ((short)local_res8[0] == 10) {
      iVar1 = -0x3ffffe7c;
    }
    else {
      iVar1 = -0x3fffffff;
      if ((short)local_res8[0] == 0xb) {
        iVar1 = -0x3ffffff3;
      }
    }
  }
  return iVar1;
}



===== StartFirmwareUpdate @ 1c001f5d0 =====

/* private: long __cdecl INvdimmFwUpdater::StartFirmwareUpdate(void) __ptr64 */

long __thiscall INvdimmFwUpdater::StartFirmwareUpdate(INvdimmFwUpdater *this)

{
  uint uVar1;
  ulong uVar2;
  char *pcVar3;
  undefined8 local_res8;
  
  local_res8 = 0;
  uVar1 = IDsmStartFirmwareUpdate(*(longlong *)(this + 8) + 0x50,&local_res8);
  if ((int)uVar1 < 0) {
    WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 8),2,
                    "FwUpdater::StartFirmwareUpdate(): Start FW Update failed with NTSTATUS 0x%x",
                    (ulonglong)uVar1);
    INvdimmTelemetry::LogFwUpdate
              (*(INvdimmTelemetry **)(this + 0x10),(ushort *)L"StartFirmwareUpdate",uVar1,
               (_IDSM_STATUS *)&local_res8,*(State *)(this + 0x44),
               (_IDSM_FIRMWARE_INFO *)(this + 0x18),*(__uint64 *)(this + 0x50));
  }
  else {
    uVar1 = FUNCTION_SPECIFIC_IDSM_STATUS_TO_NTSTATUS((uint)local_res8,0xd);
    if ((int)uVar1 < 0) {
      pcVar3 = "FwUpdater::StartFirmwareUpdate(): Start FW Update failed with IDSM status 0x%x";
      uVar2 = 2;
    }
    else {
      pcVar3 = "FwUpdater::StartFirmwareUpdate(): Start FW Update started. Context = 0x%x";
      *(undefined4 *)(this + 0x48) = local_res8._4_4_;
      uVar2 = 4;
    }
    WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 8),uVar2,pcVar3);
    INvdimmTelemetry::LogFwUpdate
              (*(INvdimmTelemetry **)(this + 0x10),(ushort *)L"StartFirmwareUpdate",uVar1,
               (_IDSM_STATUS *)&local_res8,*(State *)(this + 0x44),
               (_IDSM_FIRMWARE_INFO *)(this + 0x18),*(__uint64 *)(this + 0x50));
  }
  return uVar1;
}



===== DoOverwrite @ 1c001f6e4 =====

/* private: long __cdecl INvdimmMediaReinitializer::DoOverwrite(struct _STRING const & __ptr64,enum
   _SCM_PD_MEDIA_REINITIALIZATION_STATUS * __ptr64) __ptr64 */

long __thiscall
INvdimmMediaReinitializer::DoOverwrite
          (INvdimmMediaReinitializer *this,_STRING *param_1,
          _SCM_PD_MEDIA_REINITIALIZATION_STATUS *param_2)

{
  INvdimmMediaReinitializer *pIVar1;
  long lVar2;
  uint uVar3;
  ulonglong uVar4;
  _NVDIMM_DEVICE_EXTENSION *p_Var5;
  int iVar6;
  ulonglong uVar7;
  char *pcVar8;
  undefined4 local_res8;
  undefined8 local_res20;
  
  pIVar1 = this + 0x20;
  KeWaitForSingleObject(pIVar1,0,0,0,0);
  if (*(int *)(this + 0x1c) == 1) {
    WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 8),3,
                    "DoOverwrite(): overwrite request received while overwrite is already in progress"
                   );
    lVar2 = -0x3ffffb8a;
    goto LAB_1c001f8ad;
  }
  if (*(int *)(this + 0x1c) == 2) {
    WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 8),3,
                    "DoOverwrite(): overwrite request received while cold boot is pending");
    lVar2 = -0x7fffffcf;
    goto LAB_1c001f8ad;
  }
  *(undefined4 *)(this + 0x1c) = 1;
  KeReleaseMutex(pIVar1,0);
  local_res8 = 0;
  uVar4 = IDsmOverwriteNvdimm(*(longlong *)(this + 8) + 0x50,*(void **)(param_1 + 8),
                              (uint)*(ushort *)param_1,&local_res8);
  p_Var5 = *(_NVDIMM_DEVICE_EXTENSION **)(this + 8);
  uVar7 = uVar4 & 0xffffffff;
  if ((int)uVar4 < 0) {
    pcVar8 = "DoOverwrite(): IDsmOverwriteNvdimm() call failed with NTSTATUS 0x%x";
LAB_1c001f882:
    lVar2 = (long)uVar7;
    WriteTraceEvent(p_Var5,2,pcVar8,uVar7);
  }
  else {
    if ((short)local_res8 == 0) {
      WriteTraceEvent(p_Var5,4,"DoOverwrite(): Overwrite NVDIMM start");
      local_res20 = 0xffffffffff676980;
      while( true ) {
        KeDelayExecutionThread(0,0,&local_res20);
        uVar3 = IDsmQueryOverwriteNvdimmStatus(*(longlong *)(this + 8) + 0x50,&local_res8);
        uVar7 = (ulonglong)uVar3;
        if ((int)uVar3 < 0) break;
        if ((short)local_res8 == 0) {
          WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 8),4,
                          "DoOverwrite(): IDsmQueryOverwriteNvdimmStatus() returned success (0x%x), overwrite completed"
                         );
          *param_2 = 2;
          KeWaitForSingleObject(pIVar1,0,0,0,0);
          *(undefined4 *)(this + 0x1c) = 2;
          KeReleaseMutex(pIVar1,0);
          return 0;
        }
        if (((short)local_res8 != 7) || (local_res8._2_2_ != 1)) {
          WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 8),2,
                          "DoOverwrite(): IDsmQueryOverwriteNvdimmStatus failed with _DSM status 0x%x"
                         );
          iVar6 = 0x1a;
          goto LAB_1c001f7e1;
        }
        WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 8),4,
                        "DoOverwrite(): overwrite still in progress (_DSM status: 0x%x)");
        local_res20 = 0xffffffffee1e5d00;
      }
      p_Var5 = *(_NVDIMM_DEVICE_EXTENSION **)(this + 8);
      pcVar8 = "DoOverwrite(): IDsmQueryOverwriteNvdimmStatus() call failed with NTSTATUS 0x%x";
      goto LAB_1c001f882;
    }
    WriteTraceEvent(p_Var5,2,"DoOverwrite(): IDsmOverwriteNvdimm() failed with _DSM status 0x%x");
    iVar6 = 0x18;
LAB_1c001f7e1:
    lVar2 = FUNCTION_SPECIFIC_IDSM_STATUS_TO_NTSTATUS(local_res8,iVar6);
  }
  KeWaitForSingleObject(pIVar1,0,0,0,0);
  *(undefined4 *)(this + 0x1c) = 0;
LAB_1c001f8ad:
  KeReleaseMutex(pIVar1,0);
  return lVar2;
}



===== DoSecureErase @ 1c001f948 =====

/* private: long __cdecl INvdimmMediaReinitializer::DoSecureErase(struct _STRING const &
   __ptr64,enum _SCM_PD_MEDIA_REINITIALIZATION_STATUS * __ptr64) __ptr64 */

long __thiscall
INvdimmMediaReinitializer::DoSecureErase
          (INvdimmMediaReinitializer *this,_STRING *param_1,
          _SCM_PD_MEDIA_REINITIALIZATION_STATUS *param_2)

{
  int iVar1;
  ulonglong uVar2;
  uint local_res8 [2];
  
  KeWaitForSingleObject(this + 0x20,0,0,0,0);
  if (*(int *)(this + 0x1c) == 1) {
    WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 8),3,
                    "DoOverwrite(): overwrite request received while overwrite is already in progress"
                   );
    iVar1 = -0x3ffffb8a;
  }
  else {
    KeInvalidateAllCaches();
    local_res8[0] = 0;
    uVar2 = IDsmSecureEraseNvdimm
                      (*(longlong *)(this + 8) + 0x50,*(void **)(param_1 + 8),
                       (uint)*(ushort *)param_1,local_res8);
    iVar1 = (int)uVar2;
    if (iVar1 < 0) {
      WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 8),2,
                      "DoSecureErase(): IDsmSecureEraseNvdimm() call failed with NTSTATUS 0x%x",
                      uVar2 & 0xffffffff);
    }
    else if ((short)local_res8[0] == 0) {
      KeInvalidateAllCaches();
      *param_2 = 0;
      iVar1 = 0;
    }
    else {
      WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 8),2,
                      "DoSecureErase(): IDsmSecureEraseNvdimm() _DSM status is 0x%x");
      iVar1 = FUNCTION_SPECIFIC_IDSM_STATUS_TO_NTSTATUS(local_res8[0],0x18);
    }
  }
  KeReleaseMutex(this + 0x20,0);
  return iVar1;
}



===== ReinitializeMedia @ 1c001fa60 =====

/* public: long __cdecl INvdimmMediaReinitializer::ReinitializeMedia(struct _STRING const &
   __ptr64,bool,enum _SCM_PD_MEDIA_REINITIALIZATION_STATUS * __ptr64) __ptr64 */

long __thiscall
INvdimmMediaReinitializer::ReinitializeMedia
          (INvdimmMediaReinitializer *this,_STRING *param_1,bool param_2,
          _SCM_PD_MEDIA_REINITIALIZATION_STATUS *param_3)

{
  uint uVar1;
  long lVar2;
  char *pcVar3;
  ulong local_res8 [2];
  
  local_res8[0] = 0;
  uVar1 = NvdGetLogicalDeviceCount(*(_NVDIMM_DEVICE_EXTENSION **)(this + 8),local_res8);
  if ((int)uVar1 < 0) {
    pcVar3 = 
    "INvdimmMediaReinitializer::ReinitializeMedia(): NvdGetLogicalDeviceCount() failed with NTSTATUS 0x%x"
    ;
  }
  else {
    if (local_res8[0] != 0) {
      WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 8),3,
                      "INvdimmMediaReinitializer::ReinitializeMedia(): The media can\'t be reinitialized because there are %d logical devices associacted with the NVDIMM"
                     );
      return -0x3ffffff0;
    }
    uVar1 = DoSecureErase(this,param_1,param_3);
    if (!param_2) {
      return uVar1;
    }
    if (-1 < (int)uVar1) {
      lVar2 = DoOverwrite(this,param_1,param_3);
      return lVar2;
    }
    pcVar3 = 
    "INvdimmMediaReinitializer::ReinitializeMedia(): Secure Erase failed as part of an overwrite with NTSTATUS 0x%x"
    ;
  }
  WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 8),2,pcVar3,(ulonglong)uVar1);
  return uVar1;
}



===== GetSecurityStateAsEnum @ 1c001fb24 =====

/* public: enum _SCM_PD_SECURITY_STATE __cdecl INvdimmSecurityManager::GetSecurityStateAsEnum(void)
   __ptr64 */

_SCM_PD_SECURITY_STATE __thiscall
INvdimmSecurityManager::GetSecurityStateAsEnum(INvdimmSecurityManager *this)

{
  uint uVar1;
  _SCM_PD_SECURITY_STATE _Var2;
  
  KeWaitForSingleObject(this + 0x40,0,0,0,0);
  uVar1 = *(uint *)(this + 0x38);
  KeReleaseMutex(this + 0x40,0);
  if ((uVar1 & 2) == 0) {
    _Var2 = 1;
  }
  else {
    _Var2 = (uVar1 & 4 | 8) >> 2;
  }
  return _Var2;
}



===== InitializeSecurity @ 1c001fb90 =====

/* private: long __cdecl INvdimmSecurityManager::InitializeSecurity(void) __ptr64 */

long __thiscall INvdimmSecurityManager::InitializeSecurity(INvdimmSecurityManager *this)

{
  _NVDIMM_DEVICE_EXTENSION *p_Var1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  SecurityManagerAction SVar5;
  uint uVar6;
  ulonglong uVar7;
  uint uVar8;
  bool bVar9;
  uint local_res8 [2];
  undefined8 local_38;
  uint local_30;
  
  local_30 = *(uint *)(this + 0x38);
  uVar6 = 0;
  local_38 = *(undefined8 *)(this + 0x30);
  uVar2 = 0;
  uVar3 = 0;
  uVar8 = 0;
  bVar9 = false;
  SVar5 = 0;
  if ((local_30 & 2) == 0) {
    if (this[0x18] == (INvdimmSecurityManager)0x0) {
      if (((local_30 & 8) != 0) && ((local_30 & 0x10) != 0)) {
        SVar5 = 5;
      }
      goto LAB_1c001fd6b;
    }
    p_Var1 = *(_NVDIMM_DEVICE_EXTENSION **)(this + 8);
    bVar9 = (*(uint *)(p_Var1 + 0x1fc) & 1) == 0;
    if (bVar9) {
      WriteTraceEvent(p_Var1,4,
                      "INvdimmSecurityManager::InitializeSecurity(): security is disabled, passphrase key is set, but we\'re not enabling security because of a registry setting"
                     );
    }
    else {
      WriteTraceEvent(p_Var1,4,
                      "INvdimmSecurityManager::InitializeSecurity(): security is disabled and passphrase key is set - enabling security"
                     );
      uVar2 = `anonymous_namespace'::SetPassphrase
                        (*(_NVDIMM_DEVICE_EXTENSION **)(this + 8),(ushort *)(this + 0x20));
    }
    SVar5 = (SecurityManagerAction)!bVar9;
    bVar9 = !bVar9;
    uVar8 = uVar2;
    if ((int)uVar2 < 0) goto LAB_1c001fd6b;
  }
  else {
    if ((local_30 & 4) == 0) {
      SVar5 = 4;
      goto LAB_1c001fd6b;
    }
    if (this[0x18] == (INvdimmSecurityManager)0x0) {
      SVar5 = 3;
      WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 8),3,
                      "INvdimmSecurityManager::InitializeSecurity(): NVDIMM is locked but no passphrase key is set"
                     );
      bVar9 = false;
    }
    else {
      WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 8),4,
                      "INvdimmSecurityManager::InitializeSecurity(): NVDIMM is locked and passphrase key is set - enabling security"
                     );
      p_Var1 = *(_NVDIMM_DEVICE_EXTENSION **)(this + 8);
      KeInvalidateAllCaches();
      local_res8[0] = 0;
      uVar4 = IDsmUnlockUnit((longlong)(p_Var1 + 0x50),*(void **)(this + 0x28),
                             (uint)*(ushort *)(this + 0x20),local_res8);
      uVar3 = (uint)uVar4;
      uVar7 = uVar4 & 0xffffffff;
      if ((int)uVar3 < 0) {
        WriteTraceEvent(p_Var1,2,
                        "INvdimmSecurityManager::UnlockUnit(): Unlock Unit failed with NTSTATUS 0x%x"
                        ,uVar4 & 0xffffffff);
LAB_1c001fcfa:
        WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 8),2,
                        "INvdimmSecurityManager::InitializeSecurity(): the NVDIMM could not be unlocked: NTSTATUS 0x%x. This is not a fatal error"
                        ,uVar7);
      }
      else {
        uVar3 = FUNCTION_SPECIFIC_IDSM_STATUS_TO_NTSTATUS(local_res8[0],0x16);
        uVar7 = (ulonglong)uVar3;
        if ((int)uVar3 < 0) {
          WriteTraceEvent(p_Var1,2,
                          "INvdimmSecurityManager::UnlockUnit(): Unlock Unit failed with _DSM status 0x%x"
                         );
          goto LAB_1c001fcfa;
        }
        WriteTraceEvent(p_Var1,4,
                        "INvdimmSecurityManager::UnlockUnit(): NVDIMM unlocked successfully.");
        KeInvalidateAllCaches();
      }
      SVar5 = 2;
      bVar9 = true;
    }
    uVar2 = 0;
    uVar8 = uVar3;
  }
  if (bVar9 != false) {
    WriteTraceEvent(*(_NVDIMM_DEVICE_EXTENSION **)(this + 8),4,
                    "INvdimmSecurityManager::InitializeSecurity(): the security state might have changed; refreshing it"
                   );
    uVar2 = UpdateCachedSecurityState(this);
    uVar6 = uVar2;
  }
LAB_1c001fd6b:
  INvdimmTelemetry::LogSecurityInfo
            (*(INvdimmTelemetry **)(this + 0x10),(_IDSM_SECURITY_STATE *)(this + 0x30),
             (_IDSM_SECURITY_STATE *)&local_38,(bool)this[0x18],SVar5,uVar8,bVar9,uVar6,uVar2);
  return uVar2;
}



===== SetPassphrase @ 1c001fdbc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int `anonymous_namespace'::SetPassphrase(_NVDIMM_DEVICE_EXTENSION *param_1,ushort *param_2)

{
  int iVar1;
  char *pcVar2;
  undefined1 auStack_88 [32];
  uint local_68 [4];
  undefined1 local_58 [32];
  undefined1 local_38 [32];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_88;
  memset(local_58,0,0x40);
  memcpy_s(local_38,0x20,*(void **)(param_2 + 4),(ulonglong)*param_2);
  local_68[0] = 0;
  iVar1 = IDsmSetPassphrase((longlong)(param_1 + 0x50),local_58,local_68);
  if (iVar1 < 0) {
    pcVar2 = "INvdimmSecurityManager::SetPassphrase(): Set Passphrase failed with NTSTATUS 0x%x";
  }
  else {
    iVar1 = FUNCTION_SPECIFIC_IDSM_STATUS_TO_NTSTATUS(local_68[0],0x14);
    if (-1 < iVar1) {
      WriteTraceEvent(param_1,4,
                      "INvdimmSecurityManager::SetPassphrase(): Passphrase set successfully.");
      return iVar1;
    }
    pcVar2 = "INvdimmSecurityManager::SetPassphrase(): Set Passphrase failed with _DSM status 0x%x";
  }
  WriteTraceEvent(param_1,2,pcVar2);
  return iVar1;
}



===== UpdateCachedSecurityState @ 1c001fe98 =====

/* public: long __cdecl INvdimmSecurityManager::UpdateCachedSecurityState(void) __ptr64 */

long __thiscall INvdimmSecurityManager::UpdateCachedSecurityState(INvdimmSecurityManager *this)

{
  _NVDIMM_DEVICE_EXTENSION *p_Var1;
  uint uVar2;
  ulong uVar3;
  char *pcVar4;
  short sVar5;
  ulonglong uVar6;
  
  KeWaitForSingleObject(this + 0x40,0,0,0,0);
  p_Var1 = *(_NVDIMM_DEVICE_EXTENSION **)(this + 8);
  uVar2 = IDsmGetSecurityState((longlong)(p_Var1 + 0x50),this + 0x30);
  if ((int)uVar2 < 0) {
    uVar6 = (ulonglong)uVar2;
    pcVar4 = 
    "INvdimmSecurityManager::GetSecurityState(): Get Security State failed with NTSTATUS 0x%x";
    uVar3 = 2;
  }
  else {
    uVar2 = *(uint *)(this + 0x30);
    uVar6 = (ulonglong)uVar2;
    sVar5 = (short)uVar2;
    if (sVar5 == 0) {
      uVar6 = (ulonglong)*(uint *)(this + 0x38);
      uVar3 = 4;
      uVar2 = 0;
      pcVar4 = "INvdimmSecurityManager::GetSecurityState(): Security state is 0x%x";
    }
    else {
      uVar3 = 2;
      if (sVar5 == 1) {
        uVar2 = 0xc00000bb;
      }
      else if (sVar5 == 3) {
        uVar2 = 0xc000000d;
      }
      else if (sVar5 == 2) {
        uVar2 = 0xc000000e;
      }
      else if (sVar5 == 5) {
        uVar2 = 0xc0000476;
      }
      else if (sVar5 == 10) {
        uVar2 = 0xc0000184;
      }
      else {
        uVar2 = 0xc0000001;
        if (sVar5 == 0xb) {
          uVar2 = 0xc000000d;
        }
      }
      pcVar4 = 
      "INvdimmSecurityManager::GetSecurityState(): Get Security State failed with _DSM status 0x%x";
    }
  }
  WriteTraceEvent(p_Var1,uVar3,pcVar4,uVar6);
  KeReleaseMutex(this + 0x40,0);
  return uVar2;
}



===== LogDataLoss @ 1c001ffc4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __cdecl INvdimmTelemetry::LogDataLoss(unsigned long,unsigned long,unsigned long)
   __ptr64 */

void __thiscall
INvdimmTelemetry::LogDataLoss(INvdimmTelemetry *this,ulong param_1,ulong param_2,ulong param_3)

{
  _tlgProvider_t *p_Var1;
  undefined4 in_register_00000084;
  undefined4 in_register_0000008c;
  ulong local_38;
  ulong local_34;
  ulong local_30;
  undefined4 local_2c;
  undefined8 local_28;
  _tlgProvider_t *local_20;
  undefined8 local_18 [2];
  
  if (((5 < DAT_1c0018058) && ((_DAT_1c0018068 & 0x400000000000) != 0)) &&
     ((DAT_1c0018070 & 0x400000000000) == DAT_1c0018070)) {
    p_Var1 = *(_tlgProvider_t **)(this + 0x88);
    local_28 = *(undefined8 *)(p_Var1 + 0x188);
    local_2c = *(undefined4 *)(p_Var1 + 0x20);
    local_20 = p_Var1 + 400;
    local_18[0] = 0x1000000;
    local_38 = param_3;
    local_34 = param_2;
    local_30 = param_1;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::
    Write<_tlgWrapperByVal<8>,_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>_>
              (p_Var1,&DAT_1c00154c7,(_GUID *)CONCAT44(in_register_00000084,param_2),
               (_GUID *)CONCAT44(in_register_0000008c,param_3),(_tlgWrapperByVal<8> *)local_18,
               (_tlgWrapperByRef<16> *)&local_20,(_tlgWrapperByVal<4> *)&local_2c,
               (_tlgWrapSz<char> *)&local_28,(_tlgWrapperByVal<4> *)&local_30,
               (_tlgWrapperByVal<4> *)&local_34,(_tlgWrapperByVal<4> *)&local_38);
  }
  return;
}



===== LogDeviceHealth @ 1c00200a0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __cdecl INvdimmTelemetry::LogDeviceHealth(long,enum
   _NVDIMM_DEVICE_HEALTH_CHECK_REASON,struct _IDSM_HEALTH_INFO const & __ptr64,struct
   _IDSM_ENERGY_SOURCE_STATUS const & __ptr64) __ptr64 */

void __thiscall
INvdimmTelemetry::LogDeviceHealth
          (INvdimmTelemetry *this,long param_1,_NVDIMM_DEVICE_HEALTH_CHECK_REASON param_2,
          _IDSM_HEALTH_INFO *param_3,_IDSM_ENERGY_SOURCE_STATUS *param_4)

{
  _IDSM_HEALTH_INFO _Var1;
  ushort uVar2;
  _tlgProvider_t *p_Var3;
  undefined4 in_register_00000084;
  _IDSM_HEALTH_INFO local_88;
  _IDSM_HEALTH_INFO local_87;
  _IDSM_ENERGY_SOURCE_STATUS local_86;
  _IDSM_ENERGY_SOURCE_STATUS local_85;
  uint local_84;
  uint local_80;
  uint local_7c;
  uint local_78;
  uint local_74;
  uint local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  undefined4 local_4c;
  undefined4 local_48;
  _NVDIMM_DEVICE_HEALTH_CHECK_REASON local_44;
  undefined4 local_40;
  long local_3c;
  undefined4 local_38 [2];
  undefined8 local_30;
  _tlgProvider_t *local_28;
  undefined8 local_20;
  _IDSM_HEALTH_INFO *local_18;
  undefined2 local_10;
  
  if (((5 < DAT_1c0018058) && ((_DAT_1c0018068 & 0x400000000000) != 0)) &&
     ((DAT_1c0018070 & 0x400000000000) == DAT_1c0018070)) {
    uVar2 = *(ushort *)(param_3 + 0x19);
    local_10 = 0x84;
    local_84 = uVar2 >> 9 & 1;
    local_80 = uVar2 >> 8 & 1;
    local_7c = uVar2 >> 7 & 1;
    local_78 = uVar2 >> 6 & 1;
    local_74 = uVar2 >> 5 & 1;
    local_70 = uVar2 >> 4 & 1;
    local_6c = uVar2 >> 3 & 1;
    local_68 = uVar2 >> 2 & 1;
    local_60 = uVar2 & 1;
    local_64 = uVar2 >> 1 & 1;
    _Var1 = param_3[0xc];
    local_88 = param_3[0xe];
    local_87 = param_3[0xd];
    local_5c = (byte)_Var1 >> 2 & 1;
    local_54 = (byte)_Var1 & 1;
    local_58 = (byte)_Var1 >> 1 & 1;
    local_86 = param_4[5];
    local_85 = param_4[4];
    p_Var3 = *(_tlgProvider_t **)(this + 0x88);
    local_50 = *(uint *)(p_Var3 + 0xe8) >> 4 & 1;
    local_4c = *(undefined4 *)(param_3 + 0x14);
    local_48 = *(undefined4 *)(param_3 + 4);
    local_40 = *(undefined4 *)param_3;
    local_30 = *(undefined8 *)(p_Var3 + 0x188);
    local_38[0] = *(undefined4 *)(p_Var3 + 0x20);
    local_28 = p_Var3 + 400;
    local_20 = 0x1000000;
    local_44 = param_2;
    local_3c = param_1;
    local_18 = param_3;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::
    Write<_tlgWrapperByVal<8>,_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperBinary>
              (p_Var3,&DAT_1c001555b,(_GUID *)CONCAT44(in_register_00000084,param_2),(_GUID *)0x1,
               (_tlgWrapperByVal<8> *)&local_20,(_tlgWrapperByRef<16> *)&local_28,
               (_tlgWrapperByVal<4> *)local_38,(_tlgWrapSz<char> *)&local_30,
               (_tlgWrapperByVal<4> *)&local_3c,(_tlgWrapperByVal<4> *)&local_40,
               (_tlgWrapperByVal<4> *)&local_44,(_tlgWrapperByVal<4> *)&local_48,
               (_tlgWrapperByVal<4> *)&local_4c,(_tlgWrapperByVal<4> *)&local_50,
               (_tlgWrapperByVal<1> *)&local_85,(_tlgWrapperByVal<1> *)&local_86,
               (_tlgWrapperByVal<4> *)&local_54,(_tlgWrapperByVal<4> *)&local_58,
               (_tlgWrapperByVal<4> *)&local_5c,(_tlgWrapperByVal<1> *)&local_87,
               (_tlgWrapperByVal<1> *)&local_88,(_tlgWrapperByVal<4> *)&local_60,
               (_tlgWrapperByVal<4> *)&local_64,(_tlgWrapperByVal<4> *)&local_68,
               (_tlgWrapperByVal<4> *)&local_6c,(_tlgWrapperByVal<4> *)&local_70,
               (_tlgWrapperByVal<4> *)&local_74,(_tlgWrapperByVal<4> *)&local_78,
               (_tlgWrapperByVal<4> *)&local_7c,(_tlgWrapperByVal<4> *)&local_80,
               (_tlgWrapperByVal<4> *)&local_84,(_tlgWrapperBinary *)&local_18);
  }
  return;
}



===== LogFwUpdate @ 1c0020348 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __cdecl INvdimmTelemetry::LogFwUpdate(unsigned short const * __ptr64,long,union
   _IDSM_STATUS const & __ptr64,enum INvdimmFwUpdater::State,struct _IDSM_FIRMWARE_INFO const &
   __ptr64,unsigned __int64) __ptr64 */

void __thiscall
INvdimmTelemetry::LogFwUpdate
          (INvdimmTelemetry *this,ushort *param_1,long param_2,_IDSM_STATUS *param_3,State param_4,
          _IDSM_FIRMWARE_INFO *param_5,__uint64 param_6)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 auStackY_148 [32];
  State local_118;
  undefined4 local_114;
  long local_110;
  undefined4 local_10c;
  __uint64 local_108;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 local_e8 [4];
  undefined8 *local_c8;
  undefined8 local_c0;
  longlong local_b8;
  undefined8 local_b0;
  undefined4 *local_a8;
  undefined8 local_a0;
  char *local_98;
  int local_90;
  undefined4 local_8c;
  wchar_t *local_88;
  int local_80;
  undefined4 local_7c;
  long *local_78;
  undefined8 local_70;
  undefined4 *local_68;
  undefined8 local_60;
  State *local_58;
  undefined8 local_50;
  undefined8 *local_48;
  undefined8 local_40;
  undefined8 *local_38;
  undefined8 local_30;
  __uint64 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_148;
  if (((5 < DAT_1c0018058) && ((_DAT_1c0018068 & 0x400000000000) != 0)) &&
     ((DAT_1c0018070 & 0x400000000000) == DAT_1c0018070)) {
    local_108 = param_6;
    local_100 = *(undefined8 *)(param_5 + 0x24);
    local_f8 = *(undefined8 *)(param_5 + 0x1c);
    lVar1 = *(longlong *)(this + 0x88);
    local_118 = param_4;
    local_114 = *(undefined4 *)param_3;
    local_b8 = lVar1 + 400;
    local_10c = *(undefined4 *)(lVar1 + 0x20);
    local_98 = *(char **)(lVar1 + 0x188);
    local_28 = &local_108;
    local_38 = &local_100;
    local_48 = &local_f8;
    local_58 = &local_118;
    local_68 = &local_114;
    local_78 = &local_110;
    lVar1 = -1;
    local_f0 = 0x1000000;
    local_20 = 8;
    local_30 = 8;
    local_40 = 8;
    local_50 = 4;
    local_60 = 4;
    local_70 = 4;
    if (param_1 == (ushort *)0x0) {
      local_80 = 2;
      param_1 = (ushort *)L"";
    }
    else {
      lVar2 = -1;
      do {
        lVar2 = lVar2 + 1;
      } while (param_1[lVar2] != 0);
      local_80 = (int)lVar2 * 2 + 2;
    }
    local_7c = 0;
    if (local_98 == (char *)0x0) {
      local_98 = "";
      local_90 = 1;
    }
    else {
      do {
        lVar1 = lVar1 + 1;
      } while (local_98[lVar1] != '\0');
      local_90 = (int)lVar1 + 1;
    }
    local_a8 = &local_10c;
    local_c8 = &local_f0;
    local_8c = 0;
    local_a0 = 4;
    local_b0 = 0x10;
    local_c0 = 8;
    local_110 = param_2;
    local_88 = (wchar_t *)param_1;
    _tlgWriteTransfer_EtwWriteTransfer(0x1c0018058,&DAT_1c001520b,0,0,0xd,local_e8);
  }
  return;
}



===== LogSecurityInfo @ 1c002053c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __cdecl INvdimmTelemetry::LogSecurityInfo(struct _IDSM_SECURITY_STATE const &
   __ptr64,struct _IDSM_SECURITY_STATE const & __ptr64,bool,enum
   INvdimmTelemetry::SecurityManagerAction,long,bool,long,long) __ptr64 */

void __thiscall
INvdimmTelemetry::LogSecurityInfo
          (INvdimmTelemetry *this,_IDSM_SECURITY_STATE *param_1,_IDSM_SECURITY_STATE *param_2,
          bool param_3,SecurityManagerAction param_4,long param_5,bool param_6,long param_7,
          long param_8)

{
  uint uVar1;
  longlong lVar2;
  undefined1 auStackY_228 [32];
  long local_1f8;
  uint local_1f4;
  long local_1f0;
  SecurityManagerAction local_1ec;
  uint local_1e8;
  uint local_1e4;
  uint local_1e0;
  uint local_1dc;
  uint local_1d8;
  uint local_1d4;
  uint local_1d0;
  uint local_1cc;
  uint local_1c8;
  uint local_1c4;
  uint local_1c0;
  long local_1bc;
  uint local_1b8;
  uint local_1b4;
  undefined4 local_1b0 [2];
  undefined8 local_1a8 [2];
  undefined8 local_198 [4];
  undefined8 *local_178;
  undefined8 local_170;
  longlong local_168;
  undefined8 local_160;
  undefined4 *local_158;
  undefined8 local_150;
  char *local_148;
  int local_140;
  undefined4 local_13c;
  uint *local_138;
  undefined8 local_130;
  uint *local_128;
  undefined8 local_120;
  long *local_118;
  undefined8 local_110;
  uint *local_108;
  undefined8 local_100;
  uint *local_f8;
  undefined8 local_f0;
  uint *local_e8;
  undefined8 local_e0;
  uint *local_d8;
  undefined8 local_d0;
  uint *local_c8;
  undefined8 local_c0;
  uint *local_b8;
  undefined8 local_b0;
  uint *local_a8;
  undefined8 local_a0;
  uint *local_98;
  undefined8 local_90;
  uint *local_88;
  undefined8 local_80;
  uint *local_78;
  undefined8 local_70;
  uint *local_68;
  undefined8 local_60;
  SecurityManagerAction *local_58;
  undefined8 local_50;
  long *local_48;
  undefined8 local_40;
  uint *local_38;
  undefined8 local_30;
  long *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_228;
  if (((5 < DAT_1c0018058) && ((_DAT_1c0018068 & 0x400000000000) != 0)) &&
     ((DAT_1c0018070 & 0x400000000000) == DAT_1c0018070)) {
    uVar1 = *(uint *)(param_1 + 8);
    local_1f8 = param_7;
    local_1f4 = (uint)param_6;
    local_1f0 = param_5;
    local_1ec = param_4;
    local_1e8 = uVar1 >> 6 & 1;
    local_1b8 = (uint)param_3;
    local_1e4 = uVar1 >> 5 & 1;
    local_20 = 4;
    local_1e0 = uVar1 >> 4 & 1;
    local_30 = 4;
    local_1dc = uVar1 >> 3 & 1;
    local_40 = 4;
    local_1d8 = uVar1 >> 2 & 1;
    local_1d4 = uVar1 >> 1 & 1;
    uVar1 = *(uint *)(param_2 + 8);
    local_1d0 = uVar1 >> 5 & 1;
    local_50 = 4;
    local_1cc = uVar1 >> 4 & 1;
    local_60 = 4;
    local_1c8 = uVar1 >> 3 & 1;
    local_1c4 = uVar1 >> 2 & 1;
    local_1c0 = uVar1 >> 1 & 1;
    local_1bc = param_8;
    local_168 = *(longlong *)(this + 0x88);
    local_1b4 = *(uint *)(local_168 + 0x1fc) & 1;
    local_1b0[0] = *(undefined4 *)(local_168 + 0x20);
    local_148 = *(char **)(local_168 + 0x188);
    local_168 = local_168 + 400;
    local_28 = &local_1f8;
    local_1a8[0] = 0x1000000;
    local_38 = &local_1f4;
    local_48 = &local_1f0;
    local_58 = &local_1ec;
    local_68 = &local_1e8;
    local_70 = 4;
    local_78 = &local_1e4;
    local_88 = &local_1e0;
    local_98 = &local_1dc;
    local_a8 = &local_1d8;
    local_b8 = &local_1d4;
    local_c8 = &local_1d0;
    local_d8 = &local_1cc;
    local_e8 = &local_1c8;
    local_f8 = &local_1c4;
    local_108 = &local_1c0;
    local_118 = &local_1bc;
    local_128 = &local_1b8;
    local_138 = &local_1b4;
    local_80 = 4;
    local_90 = 4;
    local_a0 = 4;
    local_b0 = 4;
    local_c0 = 4;
    local_d0 = 4;
    local_e0 = 4;
    local_f0 = 4;
    local_100 = 4;
    local_110 = 4;
    local_120 = 4;
    local_130 = 4;
    if (local_148 == (char *)0x0) {
      local_148 = "";
      local_140 = 1;
    }
    else {
      lVar2 = -1;
      do {
        lVar2 = lVar2 + 1;
      } while (local_148[lVar2] != '\0');
      local_140 = (int)lVar2 + 1;
    }
    local_158 = local_1b0;
    local_178 = local_1a8;
    local_13c = 0;
    local_150 = 4;
    local_160 = 0x10;
    local_170 = 8;
    _tlgWriteTransfer_EtwWriteTransfer(0x1c0018058,&DAT_1c00152e0,0,0,0x18,local_198);
  }
  return;
}



===== Create @ 1c00208a0 =====

/* public: static class NvdimmTelemetry * __ptr64 __cdecl NvdimmTelemetry::Create(struct
   _NVDIMM_DEVICE_EXTENSION * __ptr64,unsigned char,unsigned short * __ptr64) */

NvdimmTelemetry * __cdecl
NvdimmTelemetry::Create(_NVDIMM_DEVICE_EXTENSION *param_1,uchar param_2,ushort *param_3)

{
  NvdimmTelemetry *this;
  ulonglong uVar1;
  byte bVar2;
  
  bVar2 = 0;
  if (param_2 != '\0') {
    do {
      if (param_3[bVar2] == 0x101) {
        this = (NvdimmTelemetry *)ExAllocatePool2(0x40,0x90,0x6344564e);
        if (this == (NvdimmTelemetry *)0x0) goto LAB_1c0020a16;
        NvdimmTelemetry(this,param_1);
        goto LAB_1c0020a11;
      }
      bVar2 = bVar2 + 1;
    } while (bVar2 < param_2);
    uVar1 = 0;
    do {
      if (param_3[uVar1] == 0x1901) {
        this = (NvdimmTelemetry *)ExAllocatePool2(0x40,0x90,0x6344564e);
        if (this == (NvdimmTelemetry *)0x0) goto LAB_1c0020a16;
        NvdimmTelemetry(this,param_1);
        goto LAB_1c0020a11;
      }
      bVar2 = (char)uVar1 + 1;
      uVar1 = (ulonglong)bVar2;
    } while (bVar2 < param_2);
    bVar2 = 0;
    do {
      if (param_3[bVar2] == 0x301) {
        this = (NvdimmTelemetry *)ExAllocatePool2(0x40,0x90,0x6344564e);
        if (this == (NvdimmTelemetry *)0x0) goto LAB_1c0020a16;
        NvdimmTelemetry(this,param_1);
        goto LAB_1c0020a11;
      }
      bVar2 = bVar2 + 1;
    } while (bVar2 < param_2);
    bVar2 = 0;
    do {
      if (param_3[bVar2] == 0x1900) {
        this = (NvdimmTelemetry *)ExAllocatePool2(0x40,0x90,0x6344564e);
        if (this == (NvdimmTelemetry *)0x0) {
LAB_1c0020a16:
          this = (NvdimmTelemetry *)0x0;
        }
        else {
          NvdimmTelemetry(this,param_1);
LAB_1c0020a11:
          *(undefined ***)this = &SimulatedNvdimmTelemetry::_vftable_;
        }
        return this;
      }
      bVar2 = bVar2 + 1;
    } while (bVar2 < param_2);
  }
  return (NvdimmTelemetry *)0x0;
}



===== DeviceRemoved @ 1c0020a28 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __cdecl NvdimmTelemetry::DeviceRemoved(void) __ptr64 */

void __thiscall NvdimmTelemetry::DeviceRemoved(NvdimmTelemetry *this)

{
  longlong lVar1;
  undefined1 auStackY_c8 [32];
  byte local_98 [4];
  undefined4 local_94;
  undefined8 local_90;
  undefined8 local_88 [4];
  undefined8 *local_68;
  undefined8 local_60;
  longlong local_58;
  undefined8 local_50;
  undefined4 *local_48;
  undefined8 local_40;
  char *local_38;
  int local_30;
  undefined4 local_2c;
  byte *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  if (((5 < DAT_1c0018058) && ((_DAT_1c0018068 & 0x400000000000) != 0)) &&
     ((DAT_1c0018070 & 0x400000000000) == DAT_1c0018070)) {
    local_58 = *(longlong *)(this + 0x88);
    local_20 = 1;
    local_98[0] = *(byte *)(local_58 + 0xe8) & 1;
    local_38 = *(char **)(local_58 + 0x188);
    local_94 = *(undefined4 *)(local_58 + 0x20);
    local_58 = local_58 + 400;
    local_28 = local_98;
    local_90 = 0x1000000;
    if (local_38 == (char *)0x0) {
      local_38 = "";
      local_30 = 1;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (local_38[lVar1] != '\0');
      local_30 = (int)lVar1 + 1;
    }
    local_48 = &local_94;
    local_68 = &local_90;
    local_2c = 0;
    local_40 = 4;
    local_50 = 0x10;
    local_60 = 8;
    _tlgWriteTransfer_EtwWriteTransfer(0x1c0018058,&DAT_1c00157a5,0,0,7,local_88);
  }
  return;
}



===== DeviceStarted @ 1c0020b60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __cdecl NvdimmTelemetry::DeviceStarted(long,enum _NVDIMM_START_DEVICE_FAILURE)
   __ptr64 */

void __thiscall
NvdimmTelemetry::DeviceStarted
          (NvdimmTelemetry *this,long param_1,_NVDIMM_START_DEVICE_FAILURE param_2)

{
  longlong lVar1;
  _tlgProvider_t *p_Var2;
  undefined2 uVar3;
  _NVDIMM_START_DEVICE_FAILURE _Var4;
  undefined4 in_register_00000084;
  _GUID *in_R9;
  undefined1 auStackY_178 [32];
  _tlgWrapperByVal<1> local_a8;
  _tlgWrapperByVal<1> local_a7;
  _tlgWrapperByVal<1> local_a6;
  _tlgWrapperByVal<1> local_a5;
  _tlgWrapperByVal<1> local_a4;
  _tlgWrapperByVal<1> local_a3;
  _tlgWrapperByVal<1> local_a2 [2];
  ushort local_a0;
  undefined2 local_9e;
  undefined4 local_9c;
  int local_98;
  _NVDIMM_START_DEVICE_FAILURE local_94;
  long local_90;
  undefined4 local_8c;
  undefined8 local_88;
  undefined8 *local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  _tlgProvider_t *local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_178;
  lVar1 = *(longlong *)(this + 0x88);
  uVar3 = 0;
  if (*(undefined2 **)(lVar1 + 0x28) != (undefined2 *)0x0) {
    uVar3 = **(undefined2 **)(lVar1 + 0x28);
  }
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  _Var4 = param_2;
  local_98 = (**(code **)(**(longlong **)(lVar1 + 0x18) + 0x58))();
  if (-1 < local_98) {
    (**(code **)(**(longlong **)(*(longlong *)(this + 0x88) + 0x18) + 0x60))
              (*(longlong **)(*(longlong *)(this + 0x88) + 0x18),&local_50);
  }
  if (((5 < DAT_1c0018058) && ((_DAT_1c0018068 & 0x400000000000) != 0)) &&
     ((DAT_1c0018070 & 0x400000000000) == DAT_1c0018070)) {
    p_Var2 = *(_tlgProvider_t **)(this + 0x88);
    local_a8 = *(_tlgWrapperByVal<1> *)(lVar1 + 0xe5);
    local_a7 = *(_tlgWrapperByVal<1> *)(lVar1 + 0xe4);
    local_a6 = *(_tlgWrapperByVal<1> *)(lVar1 + 0xe3);
    local_a5 = *(_tlgWrapperByVal<1> *)(lVar1 + 0xe2);
    local_a4 = *(_tlgWrapperByVal<1> *)(lVar1 + 0xe1);
    local_a3 = *(_tlgWrapperByVal<1> *)(lVar1 + 0xe0);
    local_a2[0] = (_tlgWrapperByVal<1>)((byte)(*(uint *)(p_Var2 + 0xe8) >> 4) & 1);
    local_88 = *(undefined8 *)(p_Var2 + 0x30);
    local_9c = *(undefined4 *)(p_Var2 + 0x134);
    local_80 = &local_50;
    local_78 = *(undefined8 *)(p_Var2 + 0x180);
    local_70 = *(undefined8 *)(p_Var2 + 0x178);
    local_a0 = (ushort)(byte)p_Var2[0x26];
    local_68 = *(undefined8 *)(p_Var2 + 0x188);
    local_8c = *(undefined4 *)(p_Var2 + 0x20);
    local_60 = p_Var2 + 400;
    local_58 = 0x1000000;
    local_9e = uVar3;
    local_94 = param_2;
    local_90 = param_1;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::
    Write<_tlgWrapperByVal<8>,_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapperByVal<2>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>_>
              (p_Var2,&DAT_1c001580a,(_GUID *)CONCAT44(in_register_00000084,_Var4),in_R9,
               (_tlgWrapperByVal<8> *)&local_58,(_tlgWrapperByRef<16> *)&local_60,
               (_tlgWrapperByVal<4> *)&local_8c,(_tlgWrapSz<char> *)&local_68,
               (_tlgWrapperByVal<2> *)&local_9e,(_tlgWrapperByVal<2> *)&local_a0,
               (_tlgWrapperByVal<4> *)&local_90,(_tlgWrapperByVal<4> *)&local_94,
               (_tlgWrapSz<char> *)&local_70,(_tlgWrapSz<char> *)&local_78,
               (_tlgWrapperByVal<4> *)&local_98,(_tlgWrapSz<char> *)&local_80,
               (_tlgWrapperByVal<4> *)&local_9c,(_tlgWrapperByVal<8> *)&local_88,local_a2,&local_a3,
               &local_a4,&local_a5,&local_a6,&local_a7,&local_a8);
  }
  return;
}



===== PeriodicHealthWorkItemRoutine @ 1c0020e00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void `anonymous_namespace'::PeriodicHealthWorkItemRoutine(longlong param_1,longlong param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  (**(code **)(**(longlong **)(lVar1 + 0x18) + 0x20))(*(longlong **)(lVar1 + 0x18),4);
  KeSetCoalescableTimer
            (*(longlong *)(lVar1 + 0x1b8) + 8,0xfffffa7fd71bc000,0,900000,
             *(longlong *)(lVar1 + 0x1b8) + 0x48);
  if (param_2 != 0) {
    IoFreeWorkItem(param_2);
  }
  IoReleaseRemoveLockEx(lVar1 + 0xf0,lVar1,0x20);
  return;
}



===== GetDurationIn100ns @ 1c0020e9c =====

longlong `anonymous_namespace'::GetDurationIn100ns(ulonglong param_1,ulonglong param_2)

{
  if ((param_2 == 0) || (param_1 <= param_2)) {
    return param_2 - param_1;
  }
  return (param_2 - param_1) + -1;
}



===== PrepareWheaErrorData @ 1c0020ec0 =====

void `anonymous_namespace'::PrepareWheaErrorData
               (undefined8 param_1,longlong param_2,longlong param_3,longlong param_4,
               longlong param_5,undefined1 *param_6)

{
  *param_6 = *(undefined1 *)(param_2 + 4);
  *(undefined2 *)(param_6 + 2) = *(undefined2 *)(param_3 + 4);
  param_6[4] = *(undefined1 *)(param_3 + 8);
  param_6[5] = *(undefined1 *)(param_3 + 9);
  param_6[6] = *(undefined1 *)(param_3 + 10);
  param_6[7] = *(undefined1 *)(param_3 + 0xb);
  param_6[8] = *(undefined1 *)(param_3 + 0xc);
  param_6[0xc] = *(undefined1 *)(param_4 + 4);
  *(undefined2 *)(param_6 + 0xe) = *(undefined2 *)(param_4 + 5);
  *(undefined4 *)(param_6 + 0x10) = *(undefined4 *)(param_4 + 7);
  *(undefined4 *)(param_6 + 0x14) = *(undefined4 *)(param_5 + 4);
  *(undefined4 *)(param_6 + 0x18) = *(undefined4 *)(param_5 + 8);
  return;
}



===== FinishFirmwareUpdate @ 1c0020f28 =====

/* long __cdecl NvdimmNUtil::FinishFirmwareUpdate(struct _NVDIMM_DEVICE_EXTENSION * __ptr64,struct
   _NVDIMMN_FIRMWARE_UPDATE_CONTEXT * __ptr64) */

long __cdecl
NvdimmNUtil::FinishFirmwareUpdate
          (_NVDIMM_DEVICE_EXTENSION *param_1,_NVDIMMN_FIRMWARE_UPDATE_CONTEXT *param_2)

{
  int iVar1;
  int local_res10 [2];
  
  if (*(int *)(param_2 + 4) == 0) {
    WriteTraceEvent(param_1,3,"NvdnFinishFirmwareUpdate: No firmware update in progress");
    iVar1 = -0x3ffffe7c;
  }
  else {
    local_res10[0] = 0;
    iVar1 = ScmDsmFinishFirmwareUpdate((longlong)(param_1 + 0x50),local_res10);
    if ((-1 < iVar1) && (local_res10[0] != 0)) {
      WriteTraceEvent(param_1,2,"NvdnFinishFirmwareUpdate: _DSM failed with 0x%d");
      if ((short)local_res10[0] == 4) {
        iVar1 = -0x3fffffff;
      }
      else if (local_res10[0] == 0) {
        iVar1 = 0;
      }
      else if ((short)local_res10[0] == 1) {
        iVar1 = -0x3fffff45;
      }
      else {
        iVar1 = -0x3fffffff;
        if ((short)local_res10[0] == 2) {
          iVar1 = -0x3ffffff3;
        }
      }
    }
    *(undefined4 *)(param_2 + 4) = 0;
  }
  return iVar1;
}



===== SendFirmwareUpdateData @ 1c0020fec =====

/* long __cdecl NvdimmNUtil::SendFirmwareUpdateData(struct _NVDIMM_DEVICE_EXTENSION * __ptr64,struct
   _NVDIMMN_FIRMWARE_UPDATE_CONTEXT * __ptr64,unsigned short,unsigned char,unsigned long,void *
   __ptr64) */

long __cdecl
NvdimmNUtil::SendFirmwareUpdateData
          (_NVDIMM_DEVICE_EXTENSION *param_1,_NVDIMMN_FIRMWARE_UPDATE_CONTEXT *param_2,
          ushort param_3,uchar param_4,ulong param_5,void *param_6)

{
  int iVar1;
  ulong *puVar2;
  int iVar3;
  undefined4 local_res20;
  
  local_res20 = CONCAT31(local_res20._1_3_,param_4);
  iVar3 = 0;
  if (*(int *)(param_2 + 4) == 0) {
    WriteTraceEvent(param_1,3,"NvdnSendFirmwareUpdateData: No firmware update in progress");
    iVar1 = -0x3ffffe7c;
  }
  else {
    puVar2 = (ulong *)ExAllocatePool2(0x100,param_5 + 7,0x7766764e);
    if (puVar2 == (ulong *)0x0) {
      iVar1 = -0x3fffff66;
    }
    else {
      *(ushort *)(puVar2 + 1) = param_3;
      *(undefined1 *)((longlong)puVar2 + 6) = 0;
      *puVar2 = param_5;
      memcpy((void *)((longlong)puVar2 + 7),param_6,(ulonglong)param_5);
      local_res20 = 0;
      iVar1 = ScmDsmSendFirmwareUpdateData((longlong)(param_1 + 0x50),(int *)puVar2,&local_res20);
      if ((iVar1 < 0) || (local_res20 == 0)) {
        operator_delete(puVar2);
      }
      else {
        WriteTraceEvent(param_1,2,"NvdnSendFirmwareUpdateData: _DSM failed with 0x%d");
        if ((short)local_res20 == 4) {
          if (local_res20._2_1_ == '\x01') {
            iVar3 = -0x3ffffe7c;
          }
          else if (local_res20._2_1_ == '\x02') {
            iVar3 = -0x3fffff11;
          }
          else if (local_res20._2_1_ == '\x03') {
            iVar3 = -0x3fffffc2;
          }
          else if (local_res20._2_1_ == '\x04') {
            iVar3 = 0x102;
          }
          else {
            iVar3 = -0x3fffffff;
          }
        }
        else if (local_res20 != 0) {
          if ((short)local_res20 == 1) {
            iVar3 = -0x3fffff45;
          }
          else {
            iVar3 = -0x3fffffff;
            if ((short)local_res20 == 2) {
              iVar3 = -0x3ffffff3;
            }
          }
        }
        operator_delete(puVar2);
        iVar1 = iVar3;
      }
    }
  }
  return iVar1;
}



===== StartFirmwareUpdate @ 1c0021154 =====

/* long __cdecl NvdimmNUtil::StartFirmwareUpdate(struct _NVDIMM_DEVICE_EXTENSION * __ptr64,struct
   _NVDIMMN_FIRMWARE_UPDATE_CONTEXT * __ptr64,unsigned char) */

long __cdecl
NvdimmNUtil::StartFirmwareUpdate
          (_NVDIMM_DEVICE_EXTENSION *param_1,_NVDIMMN_FIRMWARE_UPDATE_CONTEXT *param_2,uchar param_3
          )

{
  int iVar1;
  int iVar2;
  undefined4 local_res10;
  
  iVar1 = 0;
  LOCK();
  iVar2 = *(int *)(param_2 + 4);
  if (iVar2 == 0) {
    *(int *)(param_2 + 4) = 1;
  }
  else {
    iVar1 = iVar2;
  }
  UNLOCK();
  if (iVar1 == 1) {
    WriteTraceEvent(param_1,3,"StartFirmwareUpdate: Firmware update already in progress");
    iVar2 = -0x3ffffe7c;
  }
  else {
    *param_2 = (_NVDIMMN_FIRMWARE_UPDATE_CONTEXT)param_3;
    local_res10 = 0;
    iVar2 = ScmDsmStartFirmwareUpdate((longlong)(param_1 + 0x50),param_3,&local_res10);
    if (-1 < iVar2) {
      if (local_res10 == 0) {
        return iVar2;
      }
      WriteTraceEvent(param_1,2,"StartFirmwareUpdate: _DSM failed with 0x%d");
      if ((short)local_res10 == 4) {
        iVar2 = -0x3fffffff;
        if (local_res10._2_1_ == '\x01') {
          iVar2 = -0x3ffffb8a;
        }
      }
      else {
        if (local_res10 == 0) {
          iVar2 = 0;
        }
        else if ((short)local_res10 == 1) {
          iVar2 = -0x3fffff45;
        }
        else {
          iVar2 = -0x3fffffff;
          if ((short)local_res10 == 2) {
            iVar2 = -0x3ffffff3;
          }
        }
        if (-1 < iVar2) {
          return iVar2;
        }
      }
    }
    *(undefined4 *)(param_2 + 4) = 0;
  }
  return iVar2;
}



===== BootStatus @ 1c002123c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __cdecl NvdimmNTelemetry::BootStatus(struct _NVDIMM_DEVICE_EXTENSION *
   __ptr64,long,struct _SCMDSM_LAST_BACKUP_INFORMATION * __ptr64) __ptr64 */

void __thiscall
NvdimmNTelemetry::BootStatus
          (NvdimmNTelemetry *this,_NVDIMM_DEVICE_EXTENSION *param_1,long param_2,
          _SCMDSM_LAST_BACKUP_INFORMATION *param_3)

{
  _GUID *p_Var1;
  _GUID _Var2;
  _tlgProvider_t *p_Var3;
  _SCMDSM_LAST_BACKUP_INFORMATION *p_Var4;
  long lVar5;
  int iVar6;
  uint uVar7;
  _tlgWrapperByVal<1> _Var8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  undefined1 auStackY_1e8 [32];
  _tlgWrapperByVal<1> local_d8;
  _tlgWrapperByVal<1> local_d7;
  _tlgWrapperByVal<1> local_d6;
  _NVDIMM_DEVICE_EXTENSION local_d5;
  _NVDIMM_DEVICE_EXTENSION local_d4;
  _NVDIMM_DEVICE_EXTENSION local_d3;
  _NVDIMM_DEVICE_EXTENSION local_d2;
  _NVDIMM_DEVICE_EXTENSION local_d1;
  _tlgWrapperByVal<1> local_d0 [4];
  uint local_cc;
  uint local_c8;
  ulong local_c4;
  int local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  long local_b0;
  ulong local_ac;
  ulong local_a8;
  ulong local_a4;
  ulong local_a0;
  undefined4 local_9c;
  uint local_98;
  uint local_94;
  uint local_90;
  uint local_8c;
  undefined4 local_88;
  int local_84;
  int local_80 [2];
  _SCMDSM_LAST_BACKUP_INFORMATION *local_78;
  NvdimmNTelemetry *local_70;
  _NVDIMM_DEVICE_EXTENSION *local_68;
  undefined8 local_60;
  undefined2 local_58;
  undefined2 uStack_56;
  ushort uStack_54;
  undefined2 uStack_52;
  ushort uStack_50;
  undefined2 uStack_4e;
  ushort uStack_4c;
  undefined2 uStack_4a;
  ushort uStack_48;
  undefined8 local_46;
  uint local_3e;
  undefined2 local_3a;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_1e8;
  iVar6 = 0;
  local_58 = 0;
  local_46 = 0;
  local_3e = 0;
  local_3a = 0;
  _Var8 = (_tlgWrapperByVal<1>)0x0;
  uStack_56 = 0;
  uStack_54 = 0;
  uStack_52 = 0;
  uStack_50 = 0;
  uStack_4e = 0;
  uStack_4c = 0;
  uStack_4a = 0;
  uStack_48 = 0;
  local_ac = 0;
  uVar11 = 0;
  local_a8 = 0;
  uVar10 = 0;
  local_a4 = 0;
  uVar7 = 0;
  local_a0 = 0;
  uVar9 = 0;
  local_c4 = 0;
  local_c8 = 0;
  local_cc = 0;
  local_c0 = 0;
  local_b8 = 0;
  local_bc = 0;
  local_b0 = param_2;
  local_78 = param_3;
  local_70 = this;
  lVar5 = NvdQueryDeviceRegistryUlong
                    (param_1,(ushort *)L"",(ushort *)L"DeviceSaveOpsCompleted",&local_ac);
  if (-1 < lVar5) {
    lVar5 = NvdQueryDeviceRegistryUlong
                      (param_1,(ushort *)L"",(ushort *)L"DeviceRestoreOpsCompleted",&local_a8);
    if (-1 < lVar5) {
      lVar5 = NvdQueryDeviceRegistryUlong
                        (param_1,(ushort *)L"",(ushort *)L"DeviceEraseOpsCompleted",&local_a4);
      if (-1 < lVar5) {
        lVar5 = NvdQueryDeviceRegistryUlong
                          (param_1,(ushort *)L"",(ushort *)L"DevicePowerCycles",&local_a0);
        _Var8 = (_tlgWrapperByVal<1>)0x0;
        if (-1 < lVar5) {
          _Var8 = (_tlgWrapperByVal<1>)0x1;
        }
      }
    }
  }
  local_b4 = ScmDsmGetOperationalStatistics((longlong)(param_1 + 0x50),&local_58);
  if ((-1 < local_b4) && (CONCAT22(uStack_56,local_58) == 0)) {
    if ((uStack_54 & 0x8000) == 0) {
      uVar11 = uStack_54 & 0x7fff;
    }
    else {
      uVar11 = (uStack_54 & 0x7fff) * 1000;
    }
    if ((uStack_50 & 0x8000) == 0) {
      uVar10 = uStack_50 & 0x7fff;
    }
    else {
      uVar10 = (uStack_50 & 0x7fff) * 1000;
    }
    if ((uStack_4c & 0x8000) == 0) {
      uVar7 = uStack_4c & 0x7fff;
    }
    else {
      uVar7 = (uStack_4c & 0x7fff) * 1000;
    }
    local_cc = local_3e >> 0x10;
    local_c4 = (ulong)local_46._2_2_;
    local_c8 = (uint)local_46._6_2_;
    uVar9 = (uint)uStack_48;
    if (_Var8 != (_tlgWrapperByVal<1>)0x0) {
      local_b8 = local_c4 - local_a8;
      local_c0 = uVar9 - local_ac;
      local_bc = local_c8 - local_a4;
      iVar6 = local_cc - local_a0;
    }
    NvdWriteDeviceRegistryUlong(param_1,(ushort *)L"DeviceSaveOpsCompleted",uVar9);
    NvdWriteDeviceRegistryUlong(param_1,(ushort *)L"DeviceRestoreOpsCompleted",local_c4);
    NvdWriteDeviceRegistryUlong(param_1,(ushort *)L"DeviceEraseOpsCompleted",local_c8);
    NvdWriteDeviceRegistryUlong(param_1,(ushort *)L"DevicePowerCycles",local_cc);
  }
  p_Var4 = local_78;
  if (((5 < DAT_1c0018058) && ((_DAT_1c0018068 & 0x400000000000) != 0)) &&
     ((DAT_1c0018070 & 0x400000000000) == DAT_1c0018070)) {
    p_Var1 = (_GUID *)(local_78 + 8);
    _Var2 = *(_GUID *)(local_78 + 4);
    local_d8 = (_tlgWrapperByVal<1>)((byte)_Var2 >> 2 & 1);
    local_d7 = (_tlgWrapperByVal<1>)((byte)_Var2 >> 1 & 1);
    local_d6 = (_tlgWrapperByVal<1>)((byte)_Var2 & 1);
    local_9c = *(undefined4 *)local_78;
    local_88 = CONCAT22(uStack_56,local_58);
    local_d5 = param_1[0xe4];
    local_d4 = param_1[0xe3];
    local_d3 = param_1[0xe2];
    local_d2 = param_1[0xe1];
    local_d1 = param_1[0xe0];
    p_Var3 = *(_tlgProvider_t **)(local_70 + 0x88);
    local_70 = *(NvdimmNTelemetry **)(p_Var3 + 0x188);
    local_78 = (_SCMDSM_LAST_BACKUP_INFORMATION *)
               CONCAT44(local_78._4_4_,*(undefined4 *)(p_Var3 + 0x20));
    local_68 = param_1 + 400;
    local_60 = 0x1000000;
    local_d0[0] = _Var8;
    local_80[0] = local_b4;
    local_b4 = *(undefined4 *)p_Var1;
    local_98 = uVar9;
    local_94 = uVar7;
    local_90 = uVar10;
    local_8c = uVar11;
    local_84 = iVar6;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::
    Write<_tlgWrapperByVal<8>,_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>_>
              (p_Var3,&DAT_1c0015b94,(_GUID *)p_Var4,(_GUID *)0x1,(_tlgWrapperByVal<8> *)&local_60,
               (_tlgWrapperByRef<16> *)&local_68,(_tlgWrapperByVal<4> *)&local_78,
               (_tlgWrapSz<char> *)&local_70,(_tlgWrapperByVal<4> *)local_80,
               (_tlgWrapperByVal<4> *)&local_b0,local_d0,(_tlgWrapperByVal<4> *)&local_84,
               (_tlgWrapperByVal<4> *)&local_c0,(_tlgWrapperByVal<4> *)&local_b8,
               (_tlgWrapperByVal<4> *)&local_bc,(_tlgWrapperByVal<1> *)&local_d1,
               (_tlgWrapperByVal<1> *)&local_d2,(_tlgWrapperByVal<1> *)&local_d3,
               (_tlgWrapperByVal<1> *)&local_d4,(_tlgWrapperByVal<1> *)&local_d5,
               (_tlgWrapperByVal<4> *)&local_88,(_tlgWrapperByVal<4> *)&local_8c,
               (_tlgWrapperByVal<4> *)&local_90,(_tlgWrapperByVal<4> *)&local_94,
               (_tlgWrapperByVal<4> *)&local_98,(_tlgWrapperByVal<4> *)&local_c4,
               (_tlgWrapperByVal<4> *)&local_c8,(_tlgWrapperByVal<4> *)&local_cc,
               (_tlgWrapperByVal<4> *)&local_9c,&local_d6,&local_d7,&local_d8,
               (_tlgWrapperByVal<4> *)&local_b4);
  }
  return;
}



===== Health @ 1c00216d8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __cdecl NvdimmNTelemetry::Health(struct _NVDIMM_DEVICE_EXTENSION * __ptr64,enum
   _NVDIMM_DEVICE_HEALTH_CHECK_REASON,long,struct _SCMDSM_CRITICAL_HEALTH_INFO * __ptr64,struct
   _SCMDSM_NVDIMM_HEALTH_INFO * __ptr64,struct _SCMDSM_ENERGY_SOURCE_HEALTH_INFO * __ptr64) __ptr64
    */

void __thiscall
NvdimmNTelemetry::Health
          (NvdimmNTelemetry *this,_NVDIMM_DEVICE_EXTENSION *param_1,
          _NVDIMM_DEVICE_HEALTH_CHECK_REASON param_2,long param_3,
          _SCMDSM_CRITICAL_HEALTH_INFO *param_4,_SCMDSM_NVDIMM_HEALTH_INFO *param_5,
          _SCMDSM_ENERGY_SOURCE_HEALTH_INFO *param_6)

{
  _SCMDSM_CRITICAL_HEALTH_INFO _Var1;
  longlong lVar2;
  undefined1 auStackY_218 [32];
  _SCMDSM_ENERGY_SOURCE_HEALTH_INFO local_1e8;
  _SCMDSM_NVDIMM_HEALTH_INFO local_1e7;
  _SCMDSM_NVDIMM_HEALTH_INFO local_1e6;
  _SCMDSM_NVDIMM_HEALTH_INFO local_1e5;
  _SCMDSM_NVDIMM_HEALTH_INFO local_1e4;
  _SCMDSM_NVDIMM_HEALTH_INFO local_1e3;
  byte local_1e2;
  byte local_1e1;
  byte local_1e0;
  byte local_1df [3];
  undefined4 local_1dc;
  uint local_1d8;
  undefined4 local_1d4;
  uint local_1d0;
  uint local_1cc;
  undefined4 local_1c8;
  undefined4 local_1c4;
  long local_1c0;
  _NVDIMM_DEVICE_HEALTH_CHECK_REASON local_1bc;
  undefined4 local_1b8 [2];
  undefined8 local_1b0;
  undefined8 local_1a8 [4];
  undefined8 *local_188;
  undefined8 local_180;
  _NVDIMM_DEVICE_EXTENSION *local_178;
  undefined8 local_170;
  undefined4 *local_168;
  undefined8 local_160;
  char *local_158;
  int local_150;
  undefined4 local_14c;
  _NVDIMM_DEVICE_HEALTH_CHECK_REASON *local_148;
  undefined8 local_140;
  long *local_138;
  undefined8 local_130;
  undefined4 *local_128;
  undefined8 local_120;
  byte *local_118;
  undefined8 local_110;
  byte *local_108;
  undefined8 local_100;
  byte *local_f8;
  undefined8 local_f0;
  byte *local_e8;
  undefined8 local_e0;
  undefined4 *local_d8;
  undefined8 local_d0;
  uint *local_c8;
  undefined8 local_c0;
  uint *local_b8;
  undefined8 local_b0;
  _SCMDSM_NVDIMM_HEALTH_INFO *local_a8;
  undefined8 local_a0;
  _SCMDSM_NVDIMM_HEALTH_INFO *local_98;
  undefined8 local_90;
  _SCMDSM_NVDIMM_HEALTH_INFO *local_88;
  undefined8 local_80;
  _SCMDSM_NVDIMM_HEALTH_INFO *local_78;
  undefined8 local_70;
  _SCMDSM_NVDIMM_HEALTH_INFO *local_68;
  undefined8 local_60;
  undefined4 *local_58;
  undefined8 local_50;
  _SCMDSM_ENERGY_SOURCE_HEALTH_INFO *local_48;
  undefined8 local_40;
  uint *local_38;
  undefined8 local_30;
  undefined4 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_218;
  if (((5 < DAT_1c0018058) && ((_DAT_1c0018068 & 0x400000000000) != 0)) &&
     ((DAT_1c0018070 & 0x400000000000) == DAT_1c0018070)) {
    local_178 = param_1 + 400;
    local_1dc = *(undefined4 *)(param_6 + 7);
    local_1d8 = (uint)*(ushort *)(param_6 + 5);
    local_1e8 = param_6[4];
    local_1d4 = *(undefined4 *)param_6;
    local_20 = 4;
    local_30 = 4;
    local_1e7 = param_5[0xc];
    local_1e6 = param_5[0xb];
    local_1e5 = param_5[10];
    local_1e4 = param_5[9];
    local_1e3 = param_5[8];
    local_1d0 = (uint)*(ushort *)(param_5 + 6);
    local_1cc = (uint)*(ushort *)(param_5 + 4);
    local_1c8 = *(undefined4 *)param_5;
    _Var1 = param_4[4];
    local_1e2 = (byte)_Var1 >> 3 & 1;
    local_40 = 1;
    local_1e1 = (byte)_Var1 >> 2 & 1;
    local_50 = 4;
    local_1df[0] = (byte)_Var1 & 1;
    local_1e0 = (byte)_Var1 >> 1 & 1;
    local_1c4 = *(undefined4 *)param_4;
    local_60 = 1;
    local_70 = 1;
    local_80 = 1;
    local_158 = *(char **)(*(longlong *)(this + 0x88) + 0x188);
    local_1b8[0] = *(undefined4 *)(*(longlong *)(this + 0x88) + 0x20);
    local_28 = &local_1dc;
    local_38 = &local_1d8;
    local_48 = &local_1e8;
    local_58 = &local_1d4;
    local_68 = &local_1e7;
    local_78 = &local_1e6;
    local_88 = &local_1e5;
    local_98 = &local_1e4;
    local_a8 = &local_1e3;
    local_1b0 = 0x1000000;
    local_90 = 1;
    local_a0 = 1;
    local_b0 = 4;
    local_b8 = &local_1d0;
    local_c8 = &local_1cc;
    local_d8 = &local_1c8;
    local_e8 = &local_1e2;
    local_f8 = &local_1e1;
    local_108 = &local_1e0;
    local_118 = local_1df;
    local_128 = &local_1c4;
    local_138 = &local_1c0;
    local_148 = &local_1bc;
    local_c0 = 4;
    local_d0 = 4;
    local_e0 = 1;
    local_f0 = 1;
    local_100 = 1;
    local_110 = 1;
    local_120 = 4;
    local_130 = 4;
    local_140 = 4;
    if (local_158 == (char *)0x0) {
      local_158 = "";
      local_150 = 1;
    }
    else {
      lVar2 = -1;
      do {
        lVar2 = lVar2 + 1;
      } while (local_158[lVar2] != '\0');
      local_150 = (int)lVar2 + 1;
    }
    local_168 = local_1b8;
    local_188 = &local_1b0;
    local_14c = 0;
    local_160 = 4;
    local_170 = 0x10;
    local_180 = 8;
    local_1c0 = param_3;
    local_1bc = param_2;
    _tlgWriteTransfer_EtwWriteTransfer(0x1c0018058,&DAT_1c001598b,0,0,0x19,local_1a8);
  }
  return;
}



===== HealthStatusChange @ 1c0021a0c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __cdecl NvdimmNTelemetry::HealthStatusChange(struct _NVDIMM_DEVICE_EXTENSION *
   __ptr64,enum _NVDIMM_DEVICE_HEALTH_CHECK_REASON,unsigned char,unsigned __int64,unsigned
   char,unsigned char) __ptr64 */

void __thiscall
NvdimmNTelemetry::HealthStatusChange
          (NvdimmNTelemetry *this,_NVDIMM_DEVICE_EXTENSION *param_1,
          _NVDIMM_DEVICE_HEALTH_CHECK_REASON param_2,uchar param_3,__uint64 param_4,uchar param_5,
          uchar param_6)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined1 auStackY_118 [32];
  uchar local_e8;
  uchar local_e7;
  uchar local_e6 [2];
  undefined4 local_e4;
  _NVDIMM_DEVICE_HEALTH_CHECK_REASON local_e0;
  undefined4 local_dc;
  undefined8 local_d8 [2];
  undefined8 local_c8 [4];
  undefined8 *local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  _NVDIMM_DEVICE_EXTENSION *local_98;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 *local_88;
  undefined4 local_80;
  undefined4 local_7c;
  char *local_78;
  int local_70;
  undefined4 local_6c;
  _NVDIMM_DEVICE_HEALTH_CHECK_REASON *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  uchar *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  uchar *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  uchar *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  if (param_2 != 0) {
    local_18 = __security_cookie ^ (ulonglong)auStackY_118;
    uVar2 = param_4 / 10000;
    if (0xffffffff < uVar2) {
      uVar2 = 0xffffffff;
    }
    if (((5 < DAT_1c0018058) && ((_DAT_1c0018068 & 0x400000000000) != 0)) &&
       ((DAT_1c0018070 & 0x400000000000) == DAT_1c0018070)) {
      local_98 = param_1 + 400;
      local_1c = 0;
      local_2c = 0;
      local_3c = 0;
      local_4c = 0;
      local_5c = 0;
      local_e8 = param_6;
      local_e7 = param_5;
      local_e4 = (undefined4)uVar2;
      local_78 = *(char **)(*(longlong *)(this + 0x88) + 0x188);
      local_dc = *(undefined4 *)(*(longlong *)(this + 0x88) + 0x20);
      local_28 = &local_e8;
      local_38 = &local_e7;
      local_48 = &local_e4;
      local_58 = local_e6;
      local_68 = &local_e0;
      local_d8[0] = 0x1000000;
      local_20 = 1;
      local_30 = 1;
      local_40 = 4;
      local_50 = 1;
      local_60 = 4;
      if (local_78 == (char *)0x0) {
        local_78 = "";
        local_70 = 1;
      }
      else {
        lVar1 = -1;
        do {
          lVar1 = lVar1 + 1;
        } while (local_78[lVar1] != '\0');
        local_70 = (int)lVar1 + 1;
      }
      local_6c = 0;
      local_7c = 0;
      local_8c = 0;
      local_9c = 0;
      local_88 = &local_dc;
      local_a8 = local_d8;
      local_80 = 4;
      local_90 = 0x10;
      local_a0 = 8;
      local_e6[0] = param_3;
      local_e0 = param_2;
      _tlgWriteTransfer_EtwWriteTransfer(0x1c0018058,&DAT_1c0016114,0,0,0xb,local_c8);
    }
  }
  return;
}



===== Identification @ 1c0021be0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __cdecl NvdimmNTelemetry::Identification(struct _NVDIMM_DEVICE_EXTENSION *
   __ptr64,long,struct _SCMDSM_NVDIMM_IDENTIFICATION * __ptr64,long,struct
   _SCMDSM_ENERGY_SOURCE_IDENTIFICATION * __ptr64) __ptr64 */

void __thiscall
NvdimmNTelemetry::Identification
          (NvdimmNTelemetry *this,_NVDIMM_DEVICE_EXTENSION *param_1,long param_2,
          _SCMDSM_NVDIMM_IDENTIFICATION *param_3,long param_4,
          _SCMDSM_ENERGY_SOURCE_IDENTIFICATION *param_5)

{
  _tlgProvider_t *p_Var1;
  undefined4 in_register_00000084;
  _SCMDSM_ENERGY_SOURCE_IDENTIFICATION local_88;
  _SCMDSM_ENERGY_SOURCE_IDENTIFICATION local_87;
  _tlgWrapperByVal<1> local_86;
  _tlgWrapperByVal<1> local_85;
  _SCMDSM_ENERGY_SOURCE_IDENTIFICATION local_84;
  _SCMDSM_ENERGY_SOURCE_IDENTIFICATION local_83;
  _SCMDSM_ENERGY_SOURCE_IDENTIFICATION local_82;
  _SCMDSM_ENERGY_SOURCE_IDENTIFICATION local_81;
  _tlgWrapperByVal<1> local_80;
  _tlgWrapperByVal<1> local_7f;
  _tlgWrapperByVal<1> local_7e;
  _tlgWrapperByVal<1> local_7d;
  _SCMDSM_NVDIMM_IDENTIFICATION local_7c;
  _SCMDSM_NVDIMM_IDENTIFICATION local_7b;
  _SCMDSM_NVDIMM_IDENTIFICATION local_7a;
  _SCMDSM_NVDIMM_IDENTIFICATION local_79;
  _SCMDSM_NVDIMM_IDENTIFICATION local_78;
  _SCMDSM_NVDIMM_IDENTIFICATION local_77;
  _SCMDSM_NVDIMM_IDENTIFICATION local_76 [2];
  uint local_74;
  uint local_70;
  uint local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  uint local_48;
  uint local_44;
  undefined4 local_40;
  long local_3c;
  long local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  _NVDIMM_DEVICE_EXTENSION *local_18;
  undefined8 local_10;
  
  if (((5 < DAT_1c0018058) && ((_DAT_1c0018068 & 0x400000000000) != 0)) &&
     ((DAT_1c0018070 & 0x400000000000) == DAT_1c0018070)) {
    local_88 = param_5[0x12];
    local_87 = param_5[0x11];
    local_86 = (_tlgWrapperByVal<1>)((byte)param_5[0x10] >> 3);
    local_85 = (_tlgWrapperByVal<1>)((byte)param_5[0x10] & 7);
    local_84 = param_5[0xf];
    local_83 = param_5[0xe];
    local_82 = param_5[0xd];
    local_81 = param_5[0xc];
    local_74 = (uint)*(ushort *)(param_5 + 10);
    local_7f = (_tlgWrapperByVal<1>)((byte)param_5[9] & 7);
    local_80 = (_tlgWrapperByVal<1>)((byte)param_5[9] >> 3);
    local_70 = (uint)*(ushort *)(param_5 + 7);
    local_6c = (uint)(byte)param_5[5];
    local_7e = (_tlgWrapperByVal<1>)((byte)param_5[4] >> 1 & 1);
    local_7d = (_tlgWrapperByVal<1>)((byte)param_5[4] & 1);
    local_68 = *(undefined4 *)param_5;
    local_64 = *(undefined4 *)(param_3 + 0x2e);
    local_7c = param_3[0x2d];
    local_7b = param_3[0x2c];
    local_60 = *(undefined4 *)(param_3 + 0x28);
    local_5c = *(undefined4 *)(param_3 + 0x24);
    local_58 = *(undefined4 *)(param_3 + 0x20);
    local_54 = *(undefined4 *)(param_3 + 0x1c);
    local_50 = *(undefined4 *)(param_3 + 0x18);
    local_4c = *(undefined4 *)(param_3 + 0x14);
    local_7a = param_3[0x12];
    local_79 = param_3[0x10];
    local_78 = param_3[0xf];
    local_77 = param_3[0xe];
    local_48 = (uint)*(ushort *)(param_3 + 0xc);
    local_44 = (uint)(byte)param_3[8];
    local_76[0] = param_3[4];
    local_40 = *(undefined4 *)param_3;
    p_Var1 = *(_tlgProvider_t **)(this + 0x88);
    local_30 = *(undefined8 *)(p_Var1 + 0x180);
    local_28 = *(undefined8 *)(p_Var1 + 0x178);
    local_3c = param_4;
    local_20 = *(undefined8 *)(p_Var1 + 0x188);
    local_34 = *(undefined4 *)(p_Var1 + 0x20);
    local_18 = param_1 + 400;
    local_10 = 0x1000000;
    local_38 = param_2;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::
    Write<_tlgWrapperByVal<8>,_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>_>
              (p_Var1,&DAT_1c0015d94,(_GUID *)CONCAT44(in_register_00000084,param_2),
               (_GUID *)param_3,(_tlgWrapperByVal<8> *)&local_10,(_tlgWrapperByRef<16> *)&local_18,
               (_tlgWrapperByVal<4> *)&local_34,(_tlgWrapSz<char> *)&local_20,
               (_tlgWrapperByVal<4> *)&local_38,(_tlgWrapperByVal<4> *)&local_3c,
               (_tlgWrapSz<char> *)&local_28,(_tlgWrapSz<char> *)&local_30,
               (_tlgWrapperByVal<4> *)&local_40,(_tlgWrapperByVal<1> *)local_76,
               (_tlgWrapperByVal<4> *)&local_44,(_tlgWrapperByVal<4> *)&local_48,
               (_tlgWrapperByVal<1> *)&local_77,(_tlgWrapperByVal<1> *)&local_78,
               (_tlgWrapperByVal<1> *)&local_79,(_tlgWrapperByVal<1> *)&local_7a,
               (_tlgWrapperByVal<4> *)&local_4c,(_tlgWrapperByVal<4> *)&local_50,
               (_tlgWrapperByVal<4> *)&local_54,(_tlgWrapperByVal<4> *)&local_58,
               (_tlgWrapperByVal<4> *)&local_5c,(_tlgWrapperByVal<4> *)&local_60,
               (_tlgWrapperByVal<1> *)&local_7b,(_tlgWrapperByVal<1> *)&local_7c,
               (_tlgWrapperByVal<4> *)&local_64,(_tlgWrapperByVal<4> *)&local_68,&local_7d,&local_7e
               ,(_tlgWrapperByVal<4> *)&local_6c,(_tlgWrapperByVal<4> *)&local_70,&local_7f,
               &local_80,(_tlgWrapperByVal<4> *)&local_74,(_tlgWrapperByVal<1> *)&local_81,
               (_tlgWrapperByVal<1> *)&local_82,(_tlgWrapperByVal<1> *)&local_83,
               (_tlgWrapperByVal<1> *)&local_84,&local_85,&local_86,(_tlgWrapperByVal<1> *)&local_87
               ,(_tlgWrapperByVal<1> *)&local_88);
  }
  return;
}



===== LogDataLoss @ 1c0021f58 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __cdecl VNvdimmTelemetry::LogDataLoss(unsigned long,unsigned long,unsigned long)
   __ptr64 */

void __thiscall
VNvdimmTelemetry::LogDataLoss(VNvdimmTelemetry *this,ulong param_1,ulong param_2,ulong param_3)

{
  _tlgProvider_t *p_Var1;
  undefined4 in_register_00000084;
  undefined4 in_register_0000008c;
  ulong local_38;
  ulong local_34;
  ulong local_30;
  undefined4 local_2c;
  undefined8 local_28;
  _tlgProvider_t *local_20;
  undefined8 local_18 [2];
  
  if (((5 < DAT_1c0018058) && ((_DAT_1c0018068 & 0x400000000000) != 0)) &&
     ((DAT_1c0018070 & 0x400000000000) == DAT_1c0018070)) {
    p_Var1 = *(_tlgProvider_t **)(this + 0x88);
    local_28 = *(undefined8 *)(p_Var1 + 0x188);
    local_2c = *(undefined4 *)(p_Var1 + 0x20);
    local_20 = p_Var1 + 400;
    local_18[0] = 0x1000000;
    local_38 = param_3;
    local_34 = param_2;
    local_30 = param_1;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::
    Write<_tlgWrapperByVal<8>,_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>_>
              (p_Var1,&DAT_1c00161f1,(_GUID *)CONCAT44(in_register_00000084,param_2),
               (_GUID *)CONCAT44(in_register_0000008c,param_3),(_tlgWrapperByVal<8> *)local_18,
               (_tlgWrapperByRef<16> *)&local_20,(_tlgWrapperByVal<4> *)&local_2c,
               (_tlgWrapSz<char> *)&local_28,(_tlgWrapperByVal<4> *)&local_30,
               (_tlgWrapperByVal<4> *)&local_34,(_tlgWrapperByVal<4> *)&local_38);
  }
  return;
}



===== LogDeviceHealth @ 1c0022034 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __cdecl VNvdimmTelemetry::LogDeviceHealth(long,enum
   _NVDIMM_DEVICE_HEALTH_CHECK_REASON,struct _VDSM_HEALTH_INFO const & __ptr64) __ptr64 */

void __thiscall
VNvdimmTelemetry::LogDeviceHealth
          (VNvdimmTelemetry *this,long param_1,_NVDIMM_DEVICE_HEALTH_CHECK_REASON param_2,
          _VDSM_HEALTH_INFO *param_3)

{
  longlong lVar1;
  undefined1 auStackY_108 [32];
  _NVDIMM_DEVICE_HEALTH_CHECK_REASON local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  long local_cc;
  undefined4 local_c8 [2];
  undefined8 local_c0;
  undefined8 local_b8 [4];
  undefined8 *local_98;
  undefined8 local_90;
  longlong local_88;
  undefined8 local_80;
  undefined4 *local_78;
  undefined8 local_70;
  char *local_68;
  int local_60;
  undefined4 local_5c;
  long *local_58;
  undefined8 local_50;
  undefined4 *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  _NVDIMM_DEVICE_HEALTH_CHECK_REASON *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_108;
  if (((5 < DAT_1c0018058) && ((_DAT_1c0018068 & 0x400000000000) != 0)) &&
     ((DAT_1c0018070 & 0x400000000000) == DAT_1c0018070)) {
    local_88 = *(longlong *)(this + 0x88);
    local_d4 = *(undefined4 *)(param_3 + 4);
    local_d0 = *(undefined4 *)param_3;
    local_68 = *(char **)(local_88 + 0x188);
    local_c8[0] = *(undefined4 *)(local_88 + 0x20);
    local_88 = local_88 + 400;
    local_28 = &local_d8;
    local_38 = &local_d4;
    local_48 = &local_d0;
    local_58 = &local_cc;
    local_c0 = 0x1000000;
    local_20 = 4;
    local_30 = 4;
    local_40 = 4;
    local_50 = 4;
    if (local_68 == (char *)0x0) {
      local_68 = "";
      local_60 = 1;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (local_68[lVar1] != '\0');
      local_60 = (int)lVar1 + 1;
    }
    local_78 = local_c8;
    local_98 = &local_c0;
    local_5c = 0;
    local_70 = 4;
    local_80 = 0x10;
    local_90 = 8;
    local_d8 = param_2;
    local_cc = param_1;
    _tlgWriteTransfer_EtwWriteTransfer(0x1c0018058,&DAT_1c0016285,0,0,10,local_b8);
  }
  return;
}



===== entry @ 1c0023010 =====

void entry(longlong param_1,short *param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 1c0023044 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __security_init_cookie(void)

{
  code *pcVar1;
  
  if ((__security_cookie == 0) || (__security_cookie == 0x2b992ddfa232)) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(6);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  ___security_cookie_complement = ~__security_cookie;
  return;
}



===== DriverEntry @ 1c0023078 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DriverEntry(longlong param_1,short *param_2)

{
  undefined2 uVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  undefined1 *puVar5;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [24];
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_58;
  McGenEventRegister_EtwRegister();
  puVar5 = auStack_58;
  local_38 = *(undefined4 *)(PTR_DAT_1c0018060 + -0x10);
  uStack_34 = *(undefined4 *)(PTR_DAT_1c0018060 + -0xc);
  uStack_30 = *(undefined4 *)(PTR_DAT_1c0018060 + -8);
  uStack_2c = *(undefined4 *)(PTR_DAT_1c0018060 + -4);
  if (DAT_1c0018078 != 0) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(5);
    puVar5 = auStack_50;
  }
  _DAT_1c0018080 = 0;
  uRam00000001c0018088 = 0;
  *(undefined8 *)(puVar5 + -8) = 0x1c00230eb;
  iVar3 = EtwRegister(puVar5 + 0x20,_tlgEnableCallback,&DAT_1c0018058,&DAT_1c0018078);
  if (iVar3 == 0) {
    uVar1 = *(undefined2 *)PTR_DAT_1c0018060;
    *(undefined8 *)(puVar5 + -8) = 0x1c0023114;
    EtwSetInformation(DAT_1c0018078,2,PTR_DAT_1c0018060,uVar1);
  }
  *(code **)(param_1 + 0x70) = NvdCreateClose;
  *(code **)(param_1 + 0x80) = NvdCreateClose;
  *(code **)(param_1 + 0xb8) = NvdShutdownFlush;
  *(code **)(param_1 + 0xf0) = NvdShutdownFlush;
  *(code **)(param_1 + 0x148) = NvdPnpDispatch;
  *(code **)(param_1 + 0x120) = NvdPowerDispatch;
  *(code **)(param_1 + 0xe0) = NvdDeviceControlDispatch;
  *(code **)(param_1 + 0xe8) = NvdInternalControlDispatch;
  *(code **)(param_1 + 0x128) = NvdInternalControlDispatch;
  *(code **)(*(longlong *)(param_1 + 0x30) + 8) = NvdAddDevice;
  *(code **)(param_1 + 0x68) = NvdUnload;
  _DAT_1c001814a = *param_2 + 2;
  _DriverRegistryPath = 0;
  *(undefined8 *)(puVar5 + -8) = 0x1c00231d2;
  DAT_1c0018150 = ExAllocatePool2(0x40,_DAT_1c001814a,0x6f70764e);
  if (DAT_1c0018150 == 0) {
    uVar4 = 0xc000009a;
  }
  else {
    *(undefined8 *)(puVar5 + -8) = 0x1c00231fb;
    RtlCopyUnicodeString(&DriverRegistryPath,param_2);
    uVar4 = 0;
  }
  *(undefined8 *)(puVar5 + -8) = 0x1c002320f;
  return uVar4;
}


