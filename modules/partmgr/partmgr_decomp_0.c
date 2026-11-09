
===== Write<_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapperByRef<16>,_tlgWrapperByVal<4>_> @ 140001008 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapperByRef<16>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByRef<16>,struct _tlgWrapperByVal<4> >(struct _tlgProvider_t const * __ptr64,void
   const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,struct
   _tlgWrapperByRef<16> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByRef<16> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::Write<_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapperByRef<16>,_tlgWrapperByVal<4>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapperByRef<16> *param_5,_tlgWrapperByVal<4> *param_6,_tlgWrapperByRef<16> *param_7,
          _tlgWrapperByVal<4> *param_8)

{
  long lVar1;
  undefined1 auStackY_a8 [32];
  undefined8 local_78 [4];
  undefined8 local_58;
  undefined8 local_50;
  _tlgWrapperByVal<4> *local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  _tlgWrapperByVal<4> *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_28 = param_8;
  local_20 = 4;
  local_30 = 0x10;
  local_40 = 4;
  local_38 = *(undefined8 *)param_7;
  local_48 = param_6;
  local_50 = 0x10;
  local_58 = *(undefined8 *)param_5;
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x140019068,param_2,0,0,6,local_78);
  return lVar1;
}



===== _tlgWriteTransfer_EtwWriteTransfer @ 1400010ac =====

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



===== _tlgCreate1Sz<unsigned_short> @ 140001150 =====

/* void __cdecl _tlgCreate1Sz<unsigned short>(struct _EVENT_DATA_DESCRIPTOR * __ptr64,unsigned short
   const * __ptr64) */

void __cdecl _tlgCreate1Sz<unsigned_short>(_EVENT_DATA_DESCRIPTOR *param_1,ushort *param_2)

{
  int iVar1;
  longlong lVar2;
  
  if (param_2 == (ushort *)0x0) {
    iVar1 = 2;
    param_2 = (ushort *)L"";
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_2[lVar2] != 0);
    iVar1 = (int)lVar2 * 2 + 2;
  }
  *(ushort **)param_1 = param_2;
  *(int *)(param_1 + 8) = iVar1;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}



===== Write<_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>_> @ 140001190 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapperByRef<16>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByRef<16>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4> >(struct
   _tlgProvider_t const * __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID
   const * __ptr64,struct _tlgWrapperByRef<16> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapperByRef<16> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::
Write<_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapperByRef<16> *param_5,_tlgWrapperByVal<4> *param_6,_tlgWrapperByRef<16> *param_7,
          _tlgWrapperByVal<4> *param_8,_tlgWrapperByVal<4> *param_9)

{
  long lVar1;
  undefined1 auStackY_b8 [32];
  undefined8 local_88 [4];
  undefined8 local_68;
  undefined8 local_60;
  _tlgWrapperByVal<4> *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  _tlgWrapperByVal<4> *local_38;
  undefined8 local_30;
  _tlgWrapperByVal<4> *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_28 = param_9;
  local_38 = param_8;
  local_20 = 4;
  local_30 = 4;
  local_40 = 0x10;
  local_48 = *(undefined8 *)param_7;
  local_58 = param_6;
  local_50 = 4;
  local_60 = 0x10;
  local_68 = *(undefined8 *)param_5;
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x140019068,param_2,0,0,7,local_88);
  return lVar1;
}



===== _tlgKeywordOn @ 140001244 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 _tlgKeywordOn(void)

{
  if (((_DAT_140019078 & 0x400000000000) == 0) ||
     ((DAT_140019080 & 0x400000000000) != DAT_140019080)) {
    return 0;
  }
  return CONCAT71((int7)((DAT_140019080 & 0x400000000000) >> 8),1);
}



===== Write<_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>,_tlgWrapperByVal<8>,_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapBuffer<_UNICODE_STRING>,_tlgWrapBuffer<struct__UNICODE_STRING>,_tlgWrapBuffer<struct__UNICODE_STRING>,_tlgWrapBuffer<struct__UNICODE_STRING>,_tlgWrapBuffer<struct__UNICODE_STRING>,_tlgWrapBuffer<struct__UNICODE_STRING>,_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByRef<16>,_tlgWrapperByRef<16>,_tlgWrapperByRef<16>,_tlgWrapperByRef<16>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperBinary,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<8>,_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperBinary,_tlgWrapperBinary> @ 140001278 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<1>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<8>,struct _tlgWrapperByVal<8>,struct
   _tlgWrapperByRef<16>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<8>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapBuffer<struct _UNICODE_STRING>,struct _tlgWrapBuffer<struct
   _UNICODE_STRING>,struct _tlgWrapBuffer<struct _UNICODE_STRING>,struct _tlgWrapBuffer<struct
   _UNICODE_STRING>,struct _tlgWrapBuffer<struct _UNICODE_STRING>,struct _tlgWrapBuffer<struct
   _UNICODE_STRING>,struct _tlgWrapperByVal<8>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByRef<16>,struct _tlgWrapperByRef<16>,struct _tlgWrapperByRef<16>,struct
   _tlgWrapperByRef<16>,struct _tlgWrapperByVal<1>,struct _tlgWrapperByVal<1>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperBinary,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<1>,struct _tlgWrapperByVal<1>,struct _tlgWrapperByVal<1>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<1>,struct _tlgWrapperByVal<1>,struct _tlgWrapperByVal<1>,struct
   _tlgWrapperByVal<8>,struct _tlgWrapperByVal<8>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<1>,struct _tlgWrapperByVal<8>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapSz<unsigned short>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<1>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct _tlgWrapperBinary,struct
   _tlgWrapperBinary>(struct _tlgProvider_t const * __ptr64,void const * __ptr64,struct _GUID const
   * __ptr64,struct _GUID const * __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<8> const & __ptr64,struct _tlgWrapperByVal<8> const & __ptr64,struct
   _tlgWrapperByRef<16> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<8> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapBuffer<struct _UNICODE_STRING> const & __ptr64,struct _tlgWrapBuffer<struct
   _UNICODE_STRING> const & __ptr64,struct _tlgWrapBuffer<struct _UNICODE_STRING> const &
   __ptr64,struct _tlgWrapBuffer<struct _UNICODE_STRING> const & __ptr64,struct
   _tlgWrapBuffer<struct _UNICODE_STRING> const & __ptr64,struct _tlgWrapBuffer<struct
   _UNICODE_STRING> const & __ptr64,struct _tlgWrapperByVal<8> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByRef<16> const & __ptr64,struct
   _tlgWrapperByRef<16> const & __ptr64,struct _tlgWrapperByRef<16> const & __ptr64,struct
   _tlgWrapperByRef<16> const & __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct
   _tlgWrapperByVal<1> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperBinary const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<1> const & __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct
   _tlgWrapperByVal<1> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<1> const & __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct
   _tlgWrapperByVal<1> const & __ptr64,struct _tlgWrapperByVal<8> const & __ptr64,struct
   _tlgWrapperByVal<8> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<1> const & __ptr64,struct _tlgWrapperByVal<8> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapSz<unsigned short> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperBinary const & __ptr64,struct _tlgWrapperBinary const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::
Write<_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>,_tlgWrapperByVal<8>,_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapBuffer<_UNICODE_STRING>,_tlgWrapBuffer<struct__UNICODE_STRING>,_tlgWrapBuffer<struct__UNICODE_STRING>,_tlgWrapBuffer<struct__UNICODE_STRING>,_tlgWrapBuffer<struct__UNICODE_STRING>,_tlgWrapBuffer<struct__UNICODE_STRING>,_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByRef<16>,_tlgWrapperByRef<16>,_tlgWrapperByRef<16>,_tlgWrapperByRef<16>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperBinary,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<8>,_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperBinary,_tlgWrapperBinary>
          (undefined8 param_1,byte *param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5
          ,undefined8 param_6,undefined8 param_7,undefined8 param_8,undefined8 param_9,
          undefined8 param_10,undefined8 param_11,undefined8 param_12,undefined8 param_13,
          undefined8 param_14,undefined8 param_15,undefined8 *param_16,undefined8 param_17,
          undefined8 param_18,undefined8 param_19,undefined8 *param_20,undefined8 *param_21,
          undefined8 *param_22,undefined8 *param_23,undefined8 *param_24,undefined8 *param_25,
          undefined8 param_26,undefined8 param_27,undefined8 *param_28,undefined8 *param_29,
          undefined8 *param_30,undefined8 *param_31,undefined8 param_32,undefined8 param_33,
          undefined8 param_34,undefined8 param_35,undefined8 param_36,undefined8 param_37,
          undefined8 *param_38,undefined8 param_39,undefined8 param_40,undefined8 param_41,
          undefined8 param_42,undefined8 param_43,undefined8 param_44,undefined8 param_45,
          undefined8 param_46,undefined8 param_47,undefined8 param_48,undefined8 param_49,
          undefined8 param_50,undefined8 param_51,undefined8 param_52,undefined8 param_53,
          undefined8 param_54,undefined8 param_55,undefined8 param_56,undefined8 param_57,
          undefined8 param_58,undefined8 param_59,undefined8 param_60,undefined8 param_61,
          undefined8 param_62,undefined8 param_63,undefined8 *param_64,undefined8 param_65,
          undefined8 param_66)

{
  long lVar1;
  undefined8 *in_stack_00000228;
  undefined8 *in_stack_00000230;
  undefined1 auStackY_528 [32];
  undefined8 local_4f8 [4];
  undefined8 local_4d8;
  undefined8 local_4d0;
  undefined8 local_4c8;
  undefined8 local_4c0;
  undefined8 local_4b8;
  undefined8 local_4b0;
  undefined8 local_4a8;
  undefined8 local_4a0;
  undefined8 local_498;
  undefined8 local_490;
  undefined8 local_488;
  undefined8 local_480;
  undefined8 local_478;
  undefined8 local_470;
  undefined8 local_468;
  undefined8 local_460;
  undefined8 local_458;
  undefined8 local_450;
  undefined8 local_448;
  undefined8 local_440;
  undefined8 local_438;
  undefined8 local_430;
  undefined8 local_428;
  undefined8 local_420;
  undefined8 local_418;
  undefined8 local_410;
  undefined8 local_408;
  undefined8 local_400;
  undefined8 local_3f8;
  undefined8 local_3f0;
  uint *local_3e8;
  undefined8 local_3e0;
  undefined8 local_3d8;
  uint local_3d0 [2];
  uint *local_3c8;
  undefined8 local_3c0;
  undefined8 local_3b8;
  uint local_3b0 [2];
  uint *local_3a8;
  undefined8 local_3a0;
  undefined8 local_398;
  uint local_390 [2];
  uint *local_388;
  undefined8 local_380;
  undefined8 local_378;
  uint local_370 [2];
  uint *local_368;
  undefined8 local_360;
  undefined8 local_358;
  uint local_350 [2];
  uint *local_348;
  undefined8 local_340;
  undefined8 local_338;
  uint local_330 [2];
  undefined8 local_328;
  undefined8 local_320;
  undefined8 local_318;
  undefined8 local_310;
  undefined8 local_308;
  undefined8 local_300;
  undefined8 local_2f8;
  undefined8 local_2f0;
  undefined8 local_2e8;
  undefined8 local_2e0;
  undefined8 local_2d8;
  undefined8 local_2d0;
  undefined8 local_2c8;
  undefined8 local_2c0;
  undefined8 local_2b8;
  undefined8 local_2b0;
  undefined8 local_2a8;
  undefined8 local_2a0;
  undefined8 local_298;
  undefined8 local_290;
  undefined8 local_288;
  undefined8 local_280;
  undefined8 local_278;
  undefined8 local_270;
  uint *local_268;
  undefined8 local_260;
  undefined8 local_258;
  uint local_250 [2];
  undefined8 local_248;
  undefined8 local_240;
  undefined8 local_238;
  undefined8 local_230;
  undefined8 local_228;
  undefined8 local_220;
  undefined8 local_218;
  undefined8 local_210;
  undefined8 local_208;
  undefined8 local_200;
  undefined8 local_1f8;
  undefined8 local_1f0;
  undefined8 local_1e8;
  undefined8 local_1e0;
  undefined8 local_1d8;
  undefined8 local_1d0;
  undefined8 local_1c8;
  undefined8 local_1c0;
  undefined8 local_1b8;
  undefined8 local_1b0;
  undefined8 local_1a8;
  undefined8 local_1a0;
  undefined8 local_198;
  undefined8 local_190;
  undefined8 local_188;
  undefined8 local_180;
  undefined8 local_178;
  undefined8 local_170;
  undefined8 local_168;
  undefined8 local_160;
  undefined8 local_158;
  undefined8 local_150;
  undefined8 local_148;
  undefined8 local_140;
  undefined8 local_138;
  undefined8 local_130;
  undefined8 local_128;
  undefined8 local_120;
  undefined8 local_118;
  undefined8 local_110;
  undefined8 local_108;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  _EVENT_DATA_DESCRIPTOR local_b8 [16];
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_80;
  undefined8 local_70;
  uint *local_68;
  undefined8 local_60;
  undefined8 local_58;
  uint local_50 [2];
  uint *local_48;
  undefined8 local_40;
  undefined8 local_38;
  uint local_30 [2];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_528;
  local_48 = local_30;
  local_40 = 2;
  local_38 = *in_stack_00000230;
  local_30[0] = (uint)*(ushort *)(in_stack_00000230 + 1);
  local_68 = local_50;
  local_58 = *in_stack_00000228;
  local_50[0] = (uint)*(ushort *)(in_stack_00000228 + 1);
  local_98 = param_66;
  local_a8 = param_65;
  local_30[1] = 0;
  local_60 = 2;
  local_50[1] = 0;
  local_70 = 4;
  local_80 = 4;
  local_90 = 1;
  local_a0 = 4;
  _tlgCreate1Sz<unsigned_short>(local_b8,(ushort *)*param_64);
  local_c8 = param_63;
  local_d8 = param_62;
  local_e8 = param_61;
  local_f8 = param_60;
  local_108 = param_59;
  local_118 = param_58;
  local_128 = param_57;
  local_138 = param_56;
  local_148 = param_55;
  local_158 = param_54;
  local_168 = param_53;
  local_178 = param_52;
  local_188 = param_51;
  local_198 = param_50;
  local_1a8 = param_49;
  local_c0 = 4;
  local_d0 = 4;
  local_e0 = 4;
  local_f0 = 8;
  local_100 = 1;
  local_110 = 4;
  local_120 = 4;
  local_130 = 4;
  local_140 = 4;
  local_150 = 4;
  local_160 = 8;
  local_170 = 8;
  local_180 = 1;
  local_190 = 1;
  local_1a0 = 1;
  local_1b8 = param_48;
  local_1c8 = param_47;
  local_1d8 = param_46;
  local_1e8 = param_45;
  local_1f8 = param_44;
  local_208 = param_43;
  local_218 = param_42;
  local_228 = param_41;
  local_238 = param_40;
  local_248 = param_39;
  local_268 = local_250;
  local_258 = *param_38;
  local_250[0] = (uint)*(ushort *)(param_38 + 1);
  local_278 = param_37;
  local_288 = param_36;
  local_298 = param_35;
  local_2a8 = param_34;
  local_2b8 = param_33;
  local_2c8 = param_32;
  local_1b0 = 4;
  local_1c0 = 4;
  local_1d0 = 4;
  local_2d8 = *param_31;
  local_1e0 = 1;
  local_1f0 = 1;
  local_2e8 = *param_30;
  local_200 = 1;
  local_210 = 4;
  local_2f8 = *param_29;
  local_220 = 4;
  local_230 = 4;
  local_308 = *param_28;
  local_318 = param_27;
  local_328 = param_26;
  local_348 = local_330;
  local_240 = 4;
  local_260 = 2;
  local_250[1] = 0;
  local_270 = 4;
  local_280 = 4;
  local_290 = 4;
  local_2a0 = 4;
  local_2b0 = 1;
  local_2c0 = 1;
  local_2d0 = 0x10;
  local_2e0 = 0x10;
  local_2f0 = 0x10;
  local_300 = 0x10;
  local_310 = 4;
  local_320 = 8;
  local_340 = 2;
  local_338 = *(undefined8 *)((ushort *)*param_25 + 4);
  local_368 = local_350;
  local_330[0] = (uint)*(ushort *)*param_25;
  local_330[1] = 0;
  local_360 = 2;
  local_358 = *(undefined8 *)((ushort *)*param_24 + 4);
  local_388 = local_370;
  local_350[0] = (uint)*(ushort *)*param_24;
  local_350[1] = 0;
  local_380 = 2;
  local_378 = *(undefined8 *)((ushort *)*param_23 + 4);
  local_3a8 = local_390;
  local_370[0] = (uint)*(ushort *)*param_23;
  local_370[1] = 0;
  local_3a0 = 2;
  local_398 = *(undefined8 *)((ushort *)*param_22 + 4);
  local_3c8 = local_3b0;
  local_390[0] = (uint)*(ushort *)*param_22;
  local_390[1] = 0;
  local_3c0 = 2;
  local_3b8 = *(undefined8 *)((ushort *)*param_21 + 4);
  local_3e8 = local_3d0;
  local_3b0[0] = (uint)*(ushort *)*param_21;
  local_3b0[1] = 0;
  local_3e0 = 2;
  local_3d8 = *(undefined8 *)((ushort *)*param_20 + 4);
  local_3f8 = param_19;
  local_408 = param_18;
  local_418 = param_17;
  local_3d0[0] = (uint)*(ushort *)*param_20;
  local_3d0[1] = 0;
  local_3f0 = 4;
  local_428 = *param_16;
  local_438 = param_15;
  local_448 = param_14;
  local_458 = param_13;
  local_400 = 8;
  local_410 = 4;
  local_420 = 0x10;
  local_430 = 8;
  local_440 = 8;
  local_450 = 4;
  local_468 = param_12;
  local_478 = param_11;
  local_488 = param_10;
  local_498 = param_9;
  local_4a8 = param_8;
  local_4b8 = param_7;
  local_4c8 = param_6;
  local_4d8 = param_5;
  local_460 = 4;
  local_470 = 4;
  local_480 = 4;
  local_490 = 1;
  local_4a0 = 4;
  local_4b0 = 4;
  local_4c0 = 4;
  local_4d0 = 4;
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x140019068,param_2,0,0,0x4d,local_4f8);
  return lVar1;
}



===== Write<_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>,_tlgWrapperByVal<8>,_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapBuffer<_UNICODE_STRING>,_tlgWrapBuffer<struct__UNICODE_STRING>,_tlgWrapBuffer<struct__UNICODE_STRING>,_tlgWrapBuffer<struct__UNICODE_STRING>,_tlgWrapBuffer<struct__UNICODE_STRING>,_tlgWrapBuffer<struct__UNICODE_STRING>,_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByRef<16>,_tlgWrapperByRef<16>,_tlgWrapperByRef<16>,_tlgWrapperByRef<16>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperBinary,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<8>,_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperBinary,_tlgWrapperBinary,_tlgWrapperBinary,_tlgWrapperBinary,_tlgWrapperBinary,_tlgWrapperBinary> @ 140001a58 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<1>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<8>,struct _tlgWrapperByVal<8>,struct
   _tlgWrapperByRef<16>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<8>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapBuffer<struct _UNICODE_STRING>,struct _tlgWrapBuffer<struct
   _UNICODE_STRING>,struct _tlgWrapBuffer<struct _UNICODE_STRING>,struct _tlgWrapBuffer<struct
   _UNICODE_STRING>,struct _tlgWrapBuffer<struct _UNICODE_STRING>,struct _tlgWrapBuffer<struct
   _UNICODE_STRING>,struct _tlgWrapperByVal<8>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByRef<16>,struct _tlgWrapperByRef<16>,struct _tlgWrapperByRef<16>,struct
   _tlgWrapperByRef<16>,struct _tlgWrapperByVal<1>,struct _tlgWrapperByVal<1>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperBinary,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<1>,struct _tlgWrapperByVal<1>,struct _tlgWrapperByVal<1>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<1>,struct _tlgWrapperByVal<1>,struct _tlgWrapperByVal<1>,struct
   _tlgWrapperByVal<8>,struct _tlgWrapperByVal<8>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<1>,struct _tlgWrapperByVal<8>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapSz<unsigned short>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<1>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct _tlgWrapperBinary,struct
   _tlgWrapperBinary,struct _tlgWrapperBinary,struct _tlgWrapperBinary,struct
   _tlgWrapperBinary,struct _tlgWrapperBinary>(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,struct _tlgWrapperByVal<4>
   const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<1> const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapperByVal<8> const & __ptr64,struct _tlgWrapperByVal<8> const &
   __ptr64,struct _tlgWrapperByRef<16> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapperByVal<8> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapBuffer<struct _UNICODE_STRING> const & __ptr64,struct
   _tlgWrapBuffer<struct _UNICODE_STRING> const & __ptr64,struct _tlgWrapBuffer<struct
   _UNICODE_STRING> const & __ptr64,struct _tlgWrapBuffer<struct _UNICODE_STRING> const &
   __ptr64,struct _tlgWrapBuffer<struct _UNICODE_STRING> const & __ptr64,struct
   _tlgWrapBuffer<struct _UNICODE_STRING> const & __ptr64,struct _tlgWrapperByVal<8> const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByRef<16> const &
   __ptr64,struct _tlgWrapperByRef<16> const & __ptr64,struct _tlgWrapperByRef<16> const &
   __ptr64,struct _tlgWrapperByRef<16> const & __ptr64,struct _tlgWrapperByVal<1> const &
   __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperBinary const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct _tlgWrapperByVal<1> const &
   __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct _tlgWrapperByVal<1> const &
   __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct _tlgWrapperByVal<8> const &
   __ptr64,struct _tlgWrapperByVal<8> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct _tlgWrapperByVal<8> const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapSz<unsigned short> const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<1> const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapperBinary const & __ptr64,struct _tlgWrapperBinary const & __ptr64,struct
   _tlgWrapperBinary const & __ptr64,struct _tlgWrapperBinary const & __ptr64,struct
   _tlgWrapperBinary const & __ptr64,struct _tlgWrapperBinary const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::
Write<_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>,_tlgWrapperByVal<8>,_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapBuffer<_UNICODE_STRING>,_tlgWrapBuffer<struct__UNICODE_STRING>,_tlgWrapBuffer<struct__UNICODE_STRING>,_tlgWrapBuffer<struct__UNICODE_STRING>,_tlgWrapBuffer<struct__UNICODE_STRING>,_tlgWrapBuffer<struct__UNICODE_STRING>,_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByRef<16>,_tlgWrapperByRef<16>,_tlgWrapperByRef<16>,_tlgWrapperByRef<16>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperBinary,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<8>,_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperBinary,_tlgWrapperBinary,_tlgWrapperBinary,_tlgWrapperBinary,_tlgWrapperBinary,_tlgWrapperBinary>
          (undefined8 param_1,byte *param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5
          ,undefined8 param_6,undefined8 param_7,undefined8 param_8,undefined8 param_9,
          undefined8 param_10,undefined8 param_11,undefined8 param_12,undefined8 param_13,
          undefined8 param_14,undefined8 param_15,undefined8 *param_16,undefined8 param_17,
          undefined8 param_18,undefined8 param_19,undefined8 *param_20,undefined8 *param_21,
          undefined8 *param_22,undefined8 *param_23,undefined8 *param_24,undefined8 *param_25,
          undefined8 param_26,undefined8 param_27,undefined8 *param_28,undefined8 *param_29,
          undefined8 *param_30,undefined8 *param_31,undefined8 param_32,undefined8 param_33,
          undefined8 param_34,undefined8 param_35,undefined8 param_36,undefined8 param_37,
          undefined8 *param_38,undefined8 param_39,undefined8 param_40,undefined8 param_41,
          undefined8 param_42,undefined8 param_43,undefined8 param_44,undefined8 param_45,
          undefined8 param_46,undefined8 param_47,undefined8 param_48,undefined8 param_49,
          undefined8 param_50,undefined8 param_51,undefined8 param_52,undefined8 param_53,
          undefined8 param_54,undefined8 param_55,undefined8 param_56,undefined8 param_57,
          undefined8 param_58,undefined8 param_59,undefined8 param_60,undefined8 param_61,
          undefined8 param_62,undefined8 param_63,undefined8 *param_64,undefined8 param_65,
          undefined8 param_66)

{
  long lVar1;
  undefined8 *in_stack_00000228;
  undefined8 *in_stack_00000230;
  undefined8 *in_stack_00000238;
  undefined8 *in_stack_00000240;
  undefined8 *in_stack_00000248;
  undefined8 *in_stack_00000250;
  undefined1 auStackY_5a8 [32];
  undefined8 local_578 [4];
  undefined8 local_558;
  undefined8 local_550;
  undefined8 local_548;
  undefined8 local_540;
  undefined8 local_538;
  undefined8 local_530;
  undefined8 local_528;
  undefined8 local_520;
  undefined8 local_518;
  undefined8 local_510;
  undefined8 local_508;
  undefined8 local_500;
  undefined8 local_4f8;
  undefined8 local_4f0;
  undefined8 local_4e8;
  undefined8 local_4e0;
  undefined8 local_4d8;
  undefined8 local_4d0;
  undefined8 local_4c8;
  undefined8 local_4c0;
  undefined8 local_4b8;
  undefined8 local_4b0;
  undefined8 local_4a8;
  undefined8 local_4a0;
  undefined8 local_498;
  undefined8 local_490;
  undefined8 local_488;
  undefined8 local_480;
  undefined8 local_478;
  undefined8 local_470;
  uint *local_468;
  undefined8 local_460;
  undefined8 local_458;
  uint local_450 [2];
  uint *local_448;
  undefined8 local_440;
  undefined8 local_438;
  uint local_430 [2];
  uint *local_428;
  undefined8 local_420;
  undefined8 local_418;
  uint local_410 [2];
  uint *local_408;
  undefined8 local_400;
  undefined8 local_3f8;
  uint local_3f0 [2];
  uint *local_3e8;
  undefined8 local_3e0;
  undefined8 local_3d8;
  uint local_3d0 [2];
  uint *local_3c8;
  undefined8 local_3c0;
  undefined8 local_3b8;
  uint local_3b0 [2];
  undefined8 local_3a8;
  undefined8 local_3a0;
  undefined8 local_398;
  undefined8 local_390;
  undefined8 local_388;
  undefined8 local_380;
  undefined8 local_378;
  undefined8 local_370;
  undefined8 local_368;
  undefined8 local_360;
  undefined8 local_358;
  undefined8 local_350;
  undefined8 local_348;
  undefined8 local_340;
  undefined8 local_338;
  undefined8 local_330;
  undefined8 local_328;
  undefined8 local_320;
  undefined8 local_318;
  undefined8 local_310;
  undefined8 local_308;
  undefined8 local_300;
  undefined8 local_2f8;
  undefined8 local_2f0;
  uint *local_2e8;
  undefined8 local_2e0;
  undefined8 local_2d8;
  uint local_2d0 [2];
  undefined8 local_2c8;
  undefined8 local_2c0;
  undefined8 local_2b8;
  undefined8 local_2b0;
  undefined8 local_2a8;
  undefined8 local_2a0;
  undefined8 local_298;
  undefined8 local_290;
  undefined8 local_288;
  undefined8 local_280;
  undefined8 local_278;
  undefined8 local_270;
  undefined8 local_268;
  undefined8 local_260;
  undefined8 local_258;
  undefined8 local_250;
  undefined8 local_248;
  undefined8 local_240;
  undefined8 local_238;
  undefined8 local_230;
  undefined8 local_228;
  undefined8 local_220;
  undefined8 local_218;
  undefined8 local_210;
  undefined8 local_208;
  undefined8 local_200;
  undefined8 local_1f8;
  undefined8 local_1f0;
  undefined8 local_1e8;
  undefined8 local_1e0;
  undefined8 local_1d8;
  undefined8 local_1d0;
  undefined8 local_1c8;
  undefined8 local_1c0;
  undefined8 local_1b8;
  undefined8 local_1b0;
  undefined8 local_1a8;
  undefined8 local_1a0;
  undefined8 local_198;
  undefined8 local_190;
  undefined8 local_188;
  undefined8 local_180;
  undefined8 local_178;
  undefined8 local_170;
  undefined8 local_168;
  undefined8 local_160;
  undefined8 local_158;
  undefined8 local_150;
  undefined8 local_148;
  undefined8 local_140;
  _EVENT_DATA_DESCRIPTOR local_138 [16];
  undefined8 local_128;
  undefined8 local_120;
  undefined8 local_118;
  undefined8 local_110;
  undefined8 local_100;
  undefined8 local_f0;
  uint *local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  uint local_d0 [2];
  uint *local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  uint local_b0 [2];
  uint *local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  uint local_90 [2];
  uint *local_88;
  undefined8 local_80;
  undefined8 local_78;
  uint local_70 [2];
  uint *local_68;
  undefined8 local_60;
  undefined8 local_58;
  uint local_50 [2];
  uint *local_48;
  undefined8 local_40;
  undefined8 local_38;
  uint local_30 [2];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_5a8;
  local_48 = local_30;
  local_40 = 2;
  local_38 = *in_stack_00000250;
  local_30[0] = (uint)*(ushort *)(in_stack_00000250 + 1);
  local_68 = local_50;
  local_58 = *in_stack_00000248;
  local_50[0] = (uint)*(ushort *)(in_stack_00000248 + 1);
  local_88 = local_70;
  local_30[1] = 0;
  local_78 = *in_stack_00000240;
  local_70[0] = (uint)*(ushort *)(in_stack_00000240 + 1);
  local_a8 = local_90;
  local_60 = 2;
  local_98 = *in_stack_00000238;
  local_90[0] = (uint)*(ushort *)(in_stack_00000238 + 1);
  local_c8 = local_b0;
  local_50[1] = 0;
  local_b8 = *in_stack_00000230;
  local_b0[0] = (uint)*(ushort *)(in_stack_00000230 + 1);
  local_e8 = local_d0;
  local_80 = 2;
  local_d8 = *in_stack_00000228;
  local_d0[0] = (uint)*(ushort *)(in_stack_00000228 + 1);
  local_118 = param_66;
  local_128 = param_65;
  local_70[1] = 0;
  local_a0 = 2;
  local_90[1] = 0;
  local_c0 = 2;
  local_b0[1] = 0;
  local_e0 = 2;
  local_d0[1] = 0;
  local_f0 = 4;
  local_100 = 4;
  local_110 = 1;
  local_120 = 4;
  _tlgCreate1Sz<unsigned_short>(local_138,(ushort *)*param_64);
  local_148 = param_63;
  local_158 = param_62;
  local_168 = param_61;
  local_140 = 4;
  local_150 = 4;
  local_160 = 4;
  local_178 = param_60;
  local_188 = param_59;
  local_198 = param_58;
  local_1a8 = param_57;
  local_1b8 = param_56;
  local_1c8 = param_55;
  local_1d8 = param_54;
  local_1e8 = param_53;
  local_1f8 = param_52;
  local_208 = param_51;
  local_218 = param_50;
  local_228 = param_49;
  local_238 = param_48;
  local_248 = param_47;
  local_258 = param_46;
  local_268 = param_45;
  local_278 = param_44;
  local_288 = param_43;
  local_298 = param_42;
  local_2a8 = param_41;
  local_2b8 = param_40;
  local_2c8 = param_39;
  local_2e8 = local_2d0;
  local_2d8 = *param_38;
  local_2d0[0] = (uint)*(ushort *)(param_38 + 1);
  local_2f8 = param_37;
  local_308 = param_36;
  local_170 = 8;
  local_180 = 1;
  local_190 = 4;
  local_1a0 = 4;
  local_1b0 = 4;
  local_1c0 = 4;
  local_1d0 = 4;
  local_1e0 = 8;
  local_1f0 = 8;
  local_200 = 1;
  local_210 = 1;
  local_220 = 1;
  local_230 = 4;
  local_240 = 4;
  local_250 = 4;
  local_260 = 1;
  local_270 = 1;
  local_280 = 1;
  local_290 = 4;
  local_2a0 = 4;
  local_2b0 = 4;
  local_2c0 = 4;
  local_2e0 = 2;
  local_2d0[1] = 0;
  local_2f0 = 4;
  local_300 = 4;
  local_318 = param_35;
  local_328 = param_34;
  local_338 = param_33;
  local_348 = param_32;
  local_310 = 4;
  local_320 = 4;
  local_330 = 1;
  local_358 = *param_31;
  local_340 = 1;
  local_350 = 0x10;
  local_368 = *param_30;
  local_360 = 0x10;
  local_370 = 0x10;
  local_378 = *param_29;
  local_380 = 0x10;
  local_390 = 4;
  local_388 = *param_28;
  local_398 = param_27;
  local_3a8 = param_26;
  local_3c8 = local_3b0;
  local_3a0 = 8;
  local_3c0 = 2;
  local_3b8 = *(undefined8 *)((ushort *)*param_25 + 4);
  local_3e8 = local_3d0;
  local_3b0[0] = (uint)*(ushort *)*param_25;
  local_3b0[1] = 0;
  local_3e0 = 2;
  local_3d8 = *(undefined8 *)((ushort *)*param_24 + 4);
  local_408 = local_3f0;
  local_3d0[0] = (uint)*(ushort *)*param_24;
  local_3d0[1] = 0;
  local_400 = 2;
  local_3f8 = *(undefined8 *)((ushort *)*param_23 + 4);
  local_428 = local_410;
  local_3f0[0] = (uint)*(ushort *)*param_23;
  local_3f0[1] = 0;
  local_420 = 2;
  local_418 = *(undefined8 *)((ushort *)*param_22 + 4);
  local_448 = local_430;
  local_410[0] = (uint)*(ushort *)*param_22;
  local_410[1] = 0;
  local_440 = 2;
  local_438 = *(undefined8 *)((ushort *)*param_21 + 4);
  local_430[0] = (uint)*(ushort *)*param_21;
  local_468 = local_450;
  local_430[1] = 0;
  local_460 = 2;
  local_458 = *(undefined8 *)((ushort *)*param_20 + 4);
  local_478 = param_19;
  local_488 = param_18;
  local_498 = param_17;
  local_450[0] = (uint)*(ushort *)*param_20;
  local_450[1] = 0;
  local_470 = 4;
  local_4a8 = *param_16;
  local_4b8 = param_15;
  local_4c8 = param_14;
  local_4d8 = param_13;
  local_4e8 = param_12;
  local_4f8 = param_11;
  local_508 = param_10;
  local_518 = param_9;
  local_528 = param_8;
  local_538 = param_7;
  local_548 = param_6;
  local_558 = param_5;
  local_480 = 8;
  local_490 = 4;
  local_4a0 = 0x10;
  local_4b0 = 8;
  local_4c0 = 8;
  local_4d0 = 4;
  local_4e0 = 4;
  local_4f0 = 4;
  local_500 = 4;
  local_510 = 1;
  local_520 = 4;
  local_530 = 4;
  local_540 = 4;
  local_550 = 4;
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x140019068,param_2,0,0,0x55,local_578);
  return lVar1;
}



===== PmWmiCounterIoComplete @ 140002330 =====

void PmWmiCounterIoComplete(longlong param_1,longlong param_2,longlong *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  undefined8 local_res18 [2];
  
  local_res18[0] = 0;
  lVar2 = KeQueryUnbiasedInterruptTimePrecise(local_res18);
  *param_3 = lVar2 - *param_3;
  if (param_1 != 0) {
    PmPerfCounterIdleUpdate(param_1,lVar2,'\0','\x01');
    plVar1 = *(longlong **)
              (*(longlong *)(param_1 + 0x48) + (ulonglong)SystemReserved1[0x12]._4_4_ * 8);
    if (plVar1 != (longlong *)0x0) {
      PmPerfCounterStatUpdate(plVar1,param_2,param_3);
    }
  }
  return;
}



===== PmGlobalDispatch @ 1400023c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl PmGlobalDispatch(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl PmGlobalDispatch(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  longlong *plVar1;
  byte *pbVar2;
  code *pcVar3;
  bool bVar4;
  long lVar5;
  
  plVar1 = *(longlong **)(param_1 + 0x40);
  pbVar2 = *(byte **)(param_2 + 0xb8);
  pcVar3 = *(code **)(*plVar1 + (ulonglong)*pbVar2 * 8);
  if (pcVar3 == PmRead) {
    if (*(int *)(plVar1[0x1d] + 0x1c) != 0x12) goto LAB_14000244e;
  }
  else {
    if (pcVar3 != PmWrite) {
      lVar5 = (*pcVar3)(param_1,param_2);
      return lVar5;
    }
    if ((int)plVar1[0x41] == 0) {
      *(undefined8 *)(param_2 + 0x38) = 0;
      *(undefined4 *)(param_2 + 0x30) = 0xc00000a2;
      IofCompleteRequest(param_2,0);
      return -0x3fffff5e;
    }
  }
  if ((((pbVar2[2] & 0x10) == 0) && ((int)plVar1[0x51] == 1)) &&
     (bVar4 = PmIsOverlap((longlong)plVar1,*(longlong *)(pbVar2 + 0x18),
                          (ulonglong)*(uint *)(pbVar2 + 8)), bVar4)) {
    PmRedirectRequest((longlong)plVar1,(longlong)param_2);
    return 0x103;
  }
LAB_14000244e:
  lVar5 = PmIo(param_1,param_2);
  return lVar5;
}



===== PmWrite @ 1400024b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl PmWrite(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl PmWrite(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  char cVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  code *pcVar5;
  bool bVar6;
  undefined1 uVar7;
  int iVar8;
  long lVar9;
  longlong lVar10;
  ulonglong uVar11;
  undefined8 *puVar12;
  undefined8 local_res8;
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  lVar4 = *(longlong *)(param_2 + 0xb8);
  if (*(int *)(lVar3 + 0x208) == 0) {
    *(undefined4 *)(param_2 + 0x30) = 0xc00000a2;
    *(undefined8 *)(param_2 + 0x38) = 0;
    IofCompleteRequest(param_2,0);
    return -0x3fffff5e;
  }
  if (((*(byte *)(lVar4 + 2) & 0x10) == 0) && (*(int *)(lVar3 + 0x288) == 1)) {
    uVar2 = *(uint *)(lVar4 + 8);
    lVar4 = *(longlong *)(lVar4 + 0x18);
    bVar6 = false;
    uVar7 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x70);
    for (puVar12 = *(undefined8 **)(lVar3 + 0x380); puVar12 != (undefined8 *)(lVar3 + 0x380);
        puVar12 = (undefined8 *)*puVar12) {
      lVar10 = puVar12[4];
      if (lVar4 < lVar10) {
        bVar6 = lVar10 - lVar4 < (longlong)(ulonglong)uVar2;
        break;
      }
      if (lVar4 - lVar10 < (longlong)puVar12[5]) {
        KeReleaseSpinLock(lVar3 + 0x70,uVar7);
        goto LAB_1400026b6;
      }
    }
    KeReleaseSpinLock(lVar3 + 0x70);
    if (bVar6) {
LAB_1400026b6:
      PmRedirectRequest(lVar3,(longlong)param_2);
      return 0x103;
    }
  }
  puVar12 = *(undefined8 **)(param_2 + 0xb8);
  lVar3 = *(longlong *)(param_1 + 0x40);
  puVar12[-9] = *puVar12;
  puVar12[-8] = puVar12[1];
  puVar12[-7] = puVar12[2];
  puVar12[-6] = puVar12[3];
  *(undefined4 *)(puVar12 + -5) = *(undefined4 *)(puVar12 + 4);
  *(undefined4 *)((longlong)puVar12 + -0x24) = *(undefined4 *)((longlong)puVar12 + 0x24);
  *(undefined4 *)(puVar12 + -4) = *(undefined4 *)(puVar12 + 5);
  *(undefined4 *)((longlong)puVar12 + -0x1c) = *(undefined4 *)((longlong)puVar12 + 0x2c);
  puVar12[-3] = puVar12[6];
  *(undefined1 *)((longlong)puVar12 + -0x45) = 0;
  lVar4 = *(longlong *)(param_2 + 0xb8);
  *(ulonglong *)(lVar4 + -8) = (ulonglong)*(uint *)(puVar12 + 2);
  *(code **)(lVar4 + -0x10) = PmIoCompletion;
  *(undefined1 *)(lVar4 + -0x45) = 0xe0;
  cVar1 = *(char *)(lVar3 + 0x2c0);
  lVar4 = *(longlong *)(lVar3 + 0x2d0);
  local_res8 = 0;
  lVar10 = KeQueryUnbiasedInterruptTimePrecise(&local_res8);
  puVar12[1] = lVar10;
  if (cVar1 == '\0') {
    *(undefined1 *)((longlong)puVar12 + 1) = 0;
  }
  else {
    *(undefined1 *)((longlong)puVar12 + 1) = 1;
    iVar8 = IoGetIoPriorityHint(param_2);
    if (1 < iVar8) {
      *(byte *)((longlong)puVar12 + 1) = *(byte *)((longlong)puVar12 + 1) | 2;
    }
    uVar11 = PmPerfCounterIdleUpdate(lVar4,lVar10,1 < iVar8,'\0');
    if (uVar11 != 0) {
      PmUpdateIdlePower(*(ushort **)(lVar3 + 0x478),param_2,uVar11);
    }
  }
  if ((*(longlong *)(lVar3 + 0x2c8) != 0) &&
     (pcVar5 = *(code **)(*(longlong *)(lVar3 + 0x2c8) + 8), pcVar5 != (code *)0x0)) {
    (*pcVar5)(param_2);
  }
  lVar9 = IofCallDriver(*(undefined8 *)(lVar3 + 0x10),param_2);
  return lVar9;
}



===== PmRead @ 1400026e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl PmRead(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl PmRead(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  char cVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 *puVar5;
  code *pcVar6;
  bool bVar7;
  int iVar8;
  long lVar9;
  longlong lVar10;
  ulonglong uVar11;
  undefined8 local_res8;
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  lVar4 = *(longlong *)(param_2 + 0xb8);
  if ((((*(int *)(*(longlong *)(lVar3 + 0xe8) + 0x1c) == 0x12) &&
       ((*(byte *)(lVar4 + 2) & 0x10) == 0)) && (*(int *)(lVar3 + 0x288) == 1)) &&
     (bVar7 = PmIsOverlap(lVar3,*(longlong *)(lVar4 + 0x18),(ulonglong)*(uint *)(lVar4 + 8)), bVar7)
     ) {
    PmRedirectRequest(lVar3,(longlong)param_2);
    lVar9 = 0x103;
  }
  else {
    lVar3 = *(longlong *)(param_1 + 0x40);
    puVar5 = *(undefined8 **)(param_2 + 0xb8);
    local_res8 = 0;
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
    lVar4 = *(longlong *)(param_2 + 0xb8);
    uVar2 = *(uint *)(puVar5 + 2);
    *(code **)(lVar4 + -0x10) = PmIoCompletion;
    *(ulonglong *)(lVar4 + -8) = (ulonglong)uVar2;
    *(undefined1 *)(lVar4 + -0x45) = 0xe0;
    cVar1 = *(char *)(lVar3 + 0x2c0);
    lVar4 = *(longlong *)(lVar3 + 0x2d0);
    lVar10 = KeQueryUnbiasedInterruptTimePrecise(&local_res8);
    puVar5[1] = lVar10;
    if (cVar1 == '\0') {
      *(undefined1 *)((longlong)puVar5 + 1) = 0;
    }
    else {
      *(undefined1 *)((longlong)puVar5 + 1) = 1;
      iVar8 = IoGetIoPriorityHint(param_2);
      if (1 < iVar8) {
        *(byte *)((longlong)puVar5 + 1) = *(byte *)((longlong)puVar5 + 1) | 2;
      }
      uVar11 = PmPerfCounterIdleUpdate(lVar4,lVar10,1 < iVar8,'\0');
      if (uVar11 != 0) {
        PmUpdateIdlePower(*(ushort **)(lVar3 + 0x478),param_2,uVar11);
      }
    }
    if ((*(longlong *)(lVar3 + 0x2c8) != 0) &&
       (pcVar6 = *(code **)(*(longlong *)(lVar3 + 0x2c8) + 8), pcVar6 != (code *)0x0)) {
      (*pcVar6)(param_2);
    }
    lVar9 = IofCallDriver(*(undefined8 *)(lVar3 + 0x10),param_2);
  }
  return lVar9;
}



===== PmWmiCounterIoStart @ 140002890 =====

void PmWmiCounterIoStart(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  undefined8 local_res10 [3];
  
  local_res10[0] = 0;
  lVar1 = KeQueryUnbiasedInterruptTimePrecise(local_res10);
  *param_2 = lVar1;
  PmPerfCounterIdleUpdate(param_1,lVar1,'\0','\0');
  return;
}



===== PmIoCompletion @ 1400028e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl PmIoCompletion(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64,void * __ptr64)
    */

long __cdecl PmIoCompletion(_DEVICE_OBJECT *param_1,_IRP *param_2,void *param_3)

{
  _DEVICE_EXTENSION *p_Var1;
  char *pcVar2;
  __uint64 _Var3;
  _DISK_POWER_CONTEXT *p_Var4;
  code *pcVar5;
  char cVar6;
  int iVar7;
  __uint64 _Var8;
  ulonglong uVar9;
  ulonglong uVar10;
  undefined8 uVar11;
  longlong lVar12;
  _IRP *p_Var13;
  longlong *plVar14;
  byte bVar15;
  _DEVICE_EXTENSION *p_Var16;
  bool bVar17;
  undefined8 local_res8;
  longlong local_res10;
  void *local_res18;
  
  p_Var1 = *(_DEVICE_EXTENSION **)(param_1 + 0x40);
  p_Var16 = (_DEVICE_EXTENSION *)0x0;
  local_res10 = *(longlong *)(PmControlObject + 0x40);
  pcVar2 = *(char **)(param_2 + 0xb8);
  if (param_2[0x41] != (_IRP)0x0) {
    pcVar2[3] = pcVar2[3] | 1;
  }
  bVar15 = pcVar2[1];
  lVar12 = *(longlong *)(p_Var1 + 0x2d0);
  local_res8 = 0;
  local_res18 = param_3;
  _Var8 = KeQueryUnbiasedInterruptTimePrecise(&local_res8);
  *(__uint64 *)(pcVar2 + 8) = _Var8 - *(longlong *)(pcVar2 + 8);
  if (((bVar15 & 1) != 0) && (lVar12 != 0)) {
    bVar15 = bVar15 & 2;
    PmPerfCounterIdleUpdate(lVar12,_Var8,bVar15 != 0,'\x01');
    plVar14 = *(longlong **)
               (*(longlong *)(lVar12 + 0x48) + (ulonglong)SystemReserved1[0x12]._4_4_ * 8);
    if ((plVar14 != (longlong *)0x0) &&
       (p_Var13 = param_2,
       PmPerfCounterStatUpdate(plVar14,(longlong)param_2,(longlong *)(pcVar2 + 8)), bVar15 != 0)) {
      PmPerfCounterStatUpdate(plVar14 + 8,(longlong)p_Var13,(longlong *)(pcVar2 + 8));
    }
  }
  _Var3 = *(__uint64 *)(pcVar2 + 8);
  p_Var4 = *(_DISK_POWER_CONTEXT **)(p_Var1 + 0x478);
  cVar6 = PoEnergyEstimationEnabled();
  if ((cVar6 != '\0') && (p_Var4 != (_DISK_POWER_CONTEXT *)0x0)) {
    PmUpdateIoPower(p_Var4,param_2,_Var8,_Var3);
  }
  iVar7 = IoGetIoPriorityHint(param_2);
  if (1 < iVar7) {
    cVar6 = *pcVar2;
    if (cVar6 == '\x03') {
      p_Var16 = p_Var1 + 0x318;
    }
    else if (cVar6 == '\x04') {
      p_Var16 = p_Var1 + 800;
    }
    else if (cVar6 == '\t') {
      p_Var16 = p_Var1 + 0x328;
    }
    uVar9 = *(ulonglong *)p_Var16;
    do {
      if (*(ulonglong *)(pcVar2 + 8) <= uVar9) break;
      LOCK();
      if (uVar9 == *(ulonglong *)p_Var16) {
        *(ulonglong *)p_Var16 = *(ulonglong *)(pcVar2 + 8);
        uVar10 = uVar9;
      }
      else {
        uVar10 = *(ulonglong *)p_Var16;
      }
      UNLOCK();
      bVar17 = uVar10 != uVar9;
      uVar9 = uVar10;
    } while (bVar17);
  }
  if ((*(undefined8 **)(p_Var1 + 0x2c8) != (undefined8 *)0x0) &&
     (pcVar5 = (code *)**(undefined8 **)(p_Var1 + 0x2c8), pcVar5 != (code *)0x0)) {
    lVar12 = *(longlong *)(local_res10 + 0x1b0) * *(longlong *)(pcVar2 + 8);
    lVar12 = SUB168(SEXT816(-0x29406b2a1a85bd43) * SEXT816(lVar12),8) + lVar12;
    *(longlong *)(pcVar2 + 8) = (lVar12 >> 0x17) - (lVar12 >> 0x3f);
    (*pcVar5)((ulonglong)local_res18 & 0xffffffff,*(undefined4 *)(p_Var1 + 0xa8),param_2);
  }
  iVar7 = *(int *)(param_2 + 0x30);
  if (iVar7 == -0x7fffffea) {
    PmPropagateVerify(p_Var1);
  }
  else {
    if (iVar7 == -0x3ffffb9f) {
      uVar11 = FUN_140012c9e();
      return (long)uVar11;
    }
    if (iVar7 == -0x3ffffb95) {
      uVar11 = FUN_140012c9e();
      return (long)uVar11;
    }
    if (iVar7 == -0x3ffffb94) {
      uVar11 = FUN_140012c9e();
      return (long)uVar11;
    }
    if (iVar7 == -0x3ffffb62) {
      uVar11 = FUN_140012c9e();
      return (long)uVar11;
    }
  }
  return 0;
}



===== PmIo @ 140002b30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl PmIo(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl PmIo(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  char cVar1;
  uint uVar2;
  undefined8 *puVar3;
  longlong lVar4;
  longlong lVar5;
  code *pcVar6;
  int iVar7;
  long lVar8;
  longlong lVar9;
  ulonglong uVar10;
  undefined8 local_res8;
  
  puVar3 = *(undefined8 **)(param_2 + 0xb8);
  lVar4 = *(longlong *)(param_1 + 0x40);
  local_res8 = 0;
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
  lVar5 = *(longlong *)(param_2 + 0xb8);
  uVar2 = *(uint *)(puVar3 + 2);
  *(code **)(lVar5 + -0x10) = PmIoCompletion;
  *(ulonglong *)(lVar5 + -8) = (ulonglong)uVar2;
  *(undefined1 *)(lVar5 + -0x45) = 0xe0;
  cVar1 = *(char *)(lVar4 + 0x2c0);
  lVar5 = *(longlong *)(lVar4 + 0x2d0);
  lVar9 = KeQueryUnbiasedInterruptTimePrecise(&local_res8);
  puVar3[1] = lVar9;
  if (cVar1 == '\0') {
    *(undefined1 *)((longlong)puVar3 + 1) = 0;
  }
  else {
    *(undefined1 *)((longlong)puVar3 + 1) = 1;
    iVar7 = IoGetIoPriorityHint(param_2);
    if (1 < iVar7) {
      *(byte *)((longlong)puVar3 + 1) = *(byte *)((longlong)puVar3 + 1) | 2;
    }
    uVar10 = PmPerfCounterIdleUpdate(lVar5,lVar9,1 < iVar7,'\0');
    if (uVar10 != 0) {
      PmUpdateIdlePower(*(ushort **)(lVar4 + 0x478),param_2,uVar10);
    }
  }
  if ((*(longlong *)(lVar4 + 0x2c8) != 0) &&
     (pcVar6 = *(code **)(*(longlong *)(lVar4 + 0x2c8) + 8), pcVar6 != (code *)0x0)) {
    (*pcVar6)(param_2);
  }
  lVar8 = IofCallDriver(*(undefined8 *)(lVar4 + 0x10),param_2);
  return lVar8;
}



===== PmPerfCounterIdleUpdate @ 140002c80 =====

longlong PmPerfCounterIdleUpdate(longlong param_1,longlong param_2,char param_3,char param_4)

{
  longlong *plVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  int iVar5;
  
  if (param_4 == '\0') {
    lVar4 = CONCAT44((uint)(param_3 != '\0'),1);
  }
  else {
    lVar4 = -1;
    if (param_3 != '\0') {
      lVar4 = -0x100000001;
    }
    if (*(int *)(param_1 + 0x40) == 1) {
      *(longlong *)(param_1 + 0x50) = param_2;
    }
    if ((param_3 != '\0') && (*(int *)(param_1 + 0x44) == 1)) {
      *(longlong *)(param_1 + 0x58) = param_2;
      LOCK();
      *(longlong *)(param_1 + 0x40) = *(longlong *)(param_1 + 0x40) + lVar4;
      UNLOCK();
      return 0;
    }
  }
  LOCK();
  plVar1 = (longlong *)(param_1 + 0x40);
  lVar2 = *plVar1;
  *plVar1 = *plVar1 + lVar4;
  UNLOCK();
  if (param_4 == '\0') {
    iVar5 = (int)(lVar2 + lVar4);
    iVar3 = (int)((ulonglong)(lVar2 + lVar4) >> 0x20);
    if ((iVar5 == 1) || ((param_3 != '\0' && (iVar3 == 1)))) {
      lVar4 = *(longlong *)
               (*(longlong *)(param_1 + 0x48) + (ulonglong)SystemReserved1[0x12]._4_4_ * 8);
      if (lVar4 != 0) {
        if ((iVar5 == 1) && (*(longlong *)(param_1 + 0x50) < param_2)) {
          *(longlong *)(lVar4 + 0x28) =
               (*(longlong *)(lVar4 + 0x28) - *(longlong *)(param_1 + 0x50)) + param_2;
        }
        if (((param_3 != '\0') && (iVar3 == 1)) && (*(longlong *)(param_1 + 0x58) < param_2)) {
          *(longlong *)(lVar4 + 0x68) =
               (*(longlong *)(lVar4 + 0x68) - *(longlong *)(param_1 + 0x58)) + param_2;
        }
      }
      if ((iVar5 == 1) && (*(longlong *)(param_1 + 0x50) < param_2)) {
        return param_2 - *(longlong *)(param_1 + 0x50);
      }
    }
  }
  return 0;
}



===== PmUpdateIdlePower @ 140002da0 =====

void PmUpdateIdlePower(ushort *param_1,undefined8 param_2,ulonglong param_3)

{
  ushort uVar1;
  longlong lVar2;
  char cVar3;
  longlong lVar4;
  ulonglong uVar5;
  ushort uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  int iVar11;
  
  cVar3 = PoEnergyEstimationEnabled();
  if ((cVar3 != '\0') && (param_1 != (ushort *)0x0)) {
    uVar1 = *param_1;
    uVar8 = (ulonglong)uVar1;
    uVar10 = 0;
    iVar11 = 5;
    cVar3 = '\x05';
    uVar7 = 0;
    uVar9 = param_3;
    if (uVar1 != 0) {
      do {
        uVar5 = *(ulonglong *)(param_1 + uVar7 * 0x10 + 0xc);
        if (uVar9 <= *(ulonglong *)(param_1 + uVar7 * 0x10 + 0xc)) {
          uVar5 = uVar9;
        }
        uVar10 = uVar10 + *(uint *)(param_1 + uVar7 * 0x10 + 0x10) * uVar5;
        uVar9 = uVar9 - uVar5;
        if (uVar9 == 0) {
          cVar3 = (char)uVar7 + '\x01';
          iVar11 = (int)uVar7 + 1;
          break;
        }
        uVar6 = (short)uVar7 + 1;
        uVar7 = (ulonglong)uVar6;
      } while (uVar6 < uVar1);
    }
    lVar4 = IoGetRequestorProcess();
    lVar2 = *(longlong *)(param_1 + 0x68);
    *(int *)(param_1 + 0x74) = iVar11;
    if ((Microsoft_Windows_PartitionEnableBits & 2) != 0) {
      McTemplateK0pxxu_EtwWriteTransfer(param_2,uVar7,uVar8,lVar2,(char)uVar10,(char)param_3,cVar3);
    }
    PsUpdateComponentPower(lVar2,1,uVar10 / 10000);
    if (lVar4 != lVar2) {
      if ((lVar4 != 0) && (cVar3 = ObReferenceObjectSafe(lVar4), cVar3 == '\0')) {
        lVar4 = 0;
      }
      if (lVar2 != 0) {
        ObDereferenceObjectDeferDelete(lVar2);
      }
    }
    *(longlong *)(param_1 + 0x68) = lVar4;
  }
  return;
}



===== PmPerfCounterStatUpdate @ 140002f20 =====

void PmPerfCounterStatUpdate(longlong *param_1,longlong param_2,longlong *param_3)

{
  char cVar1;
  
  cVar1 = **(char **)(param_2 + 0xb8);
  if (cVar1 == '\x03') {
    *param_1 = *param_1 + *(longlong *)(param_2 + 0x38);
    *(int *)(param_1 + 6) = (int)param_1[6] + 1;
    param_1[2] = param_1[2] + *param_3;
  }
  else if (cVar1 == '\x04') {
    param_1[1] = param_1[1] + *(longlong *)(param_2 + 0x38);
    *(int *)((longlong)param_1 + 0x34) = *(int *)((longlong)param_1 + 0x34) + 1;
    param_1[3] = param_1[3] + *param_3;
  }
  else if (cVar1 == '\t') {
    *(int *)(param_1 + 7) = (int)param_1[7] + 1;
    param_1[4] = param_1[4] + *param_3;
  }
  if ((*(uint *)(param_2 + 0x10) & 8) != 0) {
    *(int *)((longlong)param_1 + 0x3c) = *(int *)((longlong)param_1 + 0x3c) + 1;
  }
  return;
}



===== PmUpdateIoPower @ 140002fb0 =====

/* void __cdecl PmUpdateIoPower(struct _DISK_POWER_CONTEXT * __ptr64,struct _IRP * __ptr64,unsigned
   __int64,unsigned __int64) */

void __cdecl
PmUpdateIoPower(_DISK_POWER_CONTEXT *param_1,_IRP *param_2,__uint64 param_3,__uint64 param_4)

{
  uint uVar1;
  char *pcVar2;
  longlong lVar3;
  uint uVar4;
  undefined8 uVar5;
  longlong lVar6;
  ulonglong uVar7;
  uint uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  longlong lVar11;
  longlong lVar12;
  bool bVar13;
  
  pcVar2 = *(char **)(param_2 + 0xb8);
  lVar6 = 0;
  if ((byte)(*pcVar2 - 3U) < 2) {
    lVar11 = *(longlong *)(pcVar2 + 0x18);
    uVar8 = *(uint *)(param_2 + 0x38);
    lVar12 = lVar11 + (ulonglong)uVar8;
  }
  else {
    if (*pcVar2 != '\t') {
      return;
    }
    lVar11 = 0;
    uVar8 = 0;
    lVar12 = 0;
  }
  uVar7 = *(ulonglong *)(param_1 + 0xd8);
  uVar4 = *(uint *)(param_1 + 0xe8);
  lVar3 = *(longlong *)(param_1 + 0xe0);
  if (param_3 <= uVar7) {
LAB_1400031aa:
    if ((Microsoft_Windows_PartitionEnableBits & 2) != 0) {
      McTemplateK0xxx_EtwWriteTransfer
                ((ulonglong)uVar4,uVar7,param_3,uVar7,(char)*(undefined8 *)(param_1 + 0xd8),
                 (char)param_3);
    }
    return;
  }
  LOCK();
  uVar10 = *(ulonglong *)(param_1 + 0xd8);
  if (uVar7 == uVar10) {
    *(__uint64 *)(param_1 + 0xd8) = param_3;
    uVar10 = uVar7;
  }
  else {
  }
  UNLOCK();
  if (uVar7 != uVar10) goto LAB_1400031aa;
  LOCK();
  uVar1 = *(uint *)(param_1 + 0xe8);
  if (uVar4 == uVar1) {
    *(uint *)(param_1 + 0xe8) = 0;
  }
  else {
    uVar4 = uVar1;
  }
  UNLOCK();
  *(longlong *)(param_1 + 0xe0) = lVar12;
  uVar10 = param_3 - uVar7;
  if (param_3 - param_4 < uVar7) {
    param_4 = uVar10;
  }
  if (uVar4 == 0) {
    if (*pcVar2 != '\t') {
      bVar13 = lVar11 != lVar3;
      goto LAB_14000311a;
    }
    bVar13 = true;
  }
  else {
    bVar13 = true;
    lVar6 = (ulonglong)(uVar4 - 1) * 0x20;
    uVar7 = *(ulonglong *)(param_1 + lVar6 + 8);
    lVar6 = *(longlong *)(param_1 + lVar6 + 0x10);
    uVar9 = param_4;
    if (uVar7 <= param_4) {
      uVar9 = uVar7;
    }
    param_4 = param_4 - uVar9;
LAB_14000311a:
    if (*pcVar2 == '\x03') {
      if (uVar8 < 0x10000) {
        if (bVar13 == false) {
          uVar9 = (ulonglong)*(uint *)(param_1 + 0xb0);
        }
        else {
          uVar9 = (ulonglong)*(uint *)(param_1 + 0xa8);
        }
      }
      else if (bVar13 == false) {
        uVar9 = (ulonglong)*(uint *)(param_1 + 0xc0);
      }
      else {
        uVar9 = (ulonglong)*(uint *)(param_1 + 0xb8);
      }
      goto LAB_14000309c;
    }
    if (*pcVar2 == '\x04') {
      if (uVar8 < 0x10000) {
        if (bVar13 == false) {
          uVar9 = (ulonglong)*(uint *)(param_1 + 0xb4);
        }
        else {
          uVar9 = (ulonglong)*(uint *)(param_1 + 0xac);
        }
      }
      else if (bVar13 == false) {
        uVar9 = (ulonglong)*(uint *)(param_1 + 0xc4);
      }
      else {
        uVar9 = (ulonglong)*(uint *)(param_1 + 0xbc);
      }
      goto LAB_14000309c;
    }
  }
  uVar9 = (ulonglong)*(uint *)(param_1 + 200);
LAB_14000309c:
  uVar9 = lVar6 + uVar9 * param_4;
  uVar5 = IoGetRequestorProcess();
  if ((Microsoft_Windows_PartitionEnableBits & 2) != 0) {
    McTemplateK0pxxxquu_EtwWriteTransfer
              (param_2,uVar7,uVar10,uVar5,(char)uVar9,(char)param_4,(char)lVar12,(char)uVar8,
               (char)uVar4,bVar13);
  }
  PsUpdateComponentPower(uVar5,1,uVar9 / 10000);
  return;
}



===== PmIsOverlap @ 1400031f0 =====

bool PmIsOverlap(longlong param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  undefined1 uVar2;
  bool bVar3;
  undefined8 *puVar4;
  
  bVar3 = false;
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x70);
  puVar4 = *(undefined8 **)(param_1 + 0x380);
  do {
    if (puVar4 == (undefined8 *)(param_1 + 0x380)) {
LAB_140003262:
      KeReleaseSpinLock(param_1 + 0x70,uVar2);
      return bVar3;
    }
    lVar1 = puVar4[4];
    if (param_2 < lVar1) {
      bVar3 = lVar1 - param_2 < param_3;
      goto LAB_140003262;
    }
    if (param_2 - lVar1 < (longlong)puVar4[5]) {
      bVar3 = true;
      goto LAB_140003262;
    }
    puVar4 = (undefined8 *)*puVar4;
  } while( true );
}



===== PmEnumerateOverlaps @ 1400032a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PmEnumerateOverlaps(undefined8 *param_1,ulonglong param_2,ulonglong param_3,undefined *param_4,
                        undefined8 param_5)

{
  undefined8 *puVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  
  puVar1 = (undefined8 *)*param_1;
  do {
    do {
      do {
        puVar4 = puVar1;
        if (puVar4 == param_1) {
LAB_14000336c:
          uVar3 = param_3;
          if (param_3 != 0) {
            iVar2 = (*(code *)param_4)(3,0,param_3,param_2,param_5);
            if (iVar2 < 0) {
              return;
            }
            uVar3 = 0;
            param_2 = param_2 + param_3;
          }
          goto LAB_14000333a;
        }
        puVar1 = (undefined8 *)*puVar4;
        if (param_2 < (ulonglong)puVar4[2]) {
          uVar3 = puVar4[2] - param_2;
          if (param_3 <= uVar3) goto LAB_14000336c;
          iVar2 = (*(code *)param_4)(1,0,uVar3 & 0xffffffff,param_2,param_5);
          if (iVar2 < 0) {
            return;
          }
          param_3 = param_3 - (uVar3 & 0xffffffff);
          param_2 = param_2 + (uVar3 & 0xffffffff);
        }
        uVar3 = param_3;
        if (param_3 == 0) goto LAB_14000333a;
      } while (param_2 < (ulonglong)puVar4[2]);
      uVar3 = param_2 - puVar4[2];
    } while ((ulonglong)puVar4[4] <= uVar3);
    uVar3 = puVar4[4] - uVar3;
    if (param_3 <= uVar3) {
      uVar3 = param_3;
    }
    iVar2 = (*(code *)param_4)(2,puVar4,uVar3,param_2,param_5);
    if (iVar2 < 0) {
      return;
    }
    param_2 = param_2 + uVar3;
    param_3 = param_3 - uVar3;
    uVar3 = param_3;
  } while (param_3 != 0);
LAB_14000333a:
  (*(code *)param_4)(4,0,uVar3,param_2,param_5);
  return;
}



===== PartitionOverlapCount @ 1400033d0 =====

undefined8
PartitionOverlapCount
          (int param_1,longlong param_2,undefined8 param_3,longlong param_4,longlong param_5)

{
  if (param_1 == 2) {
    if (*(int *)(param_5 + 0x10) == 0) {
      *(longlong *)(param_5 + 0x18) =
           (*(longlong *)(param_2 + 0x18) - *(longlong *)(param_2 + 0x10)) + param_4;
    }
    *(int *)(param_5 + 0x10) = *(int *)(param_5 + 0x10) + 1;
  }
  else if (((param_1 == 1) || (param_1 == 3)) || (param_1 != 4)) {
    return 0xc000000d;
  }
  return 0;
}



===== PartitionDeviceControl @ 140003420 =====

/* long __cdecl PartitionDeviceControl(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl PartitionDeviceControl(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  longlong lVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  long lVar6;
  undefined8 uVar7;
  
  uVar4 = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  uVar5 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 0x18);
  if (uVar5 != 0x560030) {
    if (uVar5 == 0x2d1400) {
      iVar3 = PartitionIoctlQueryProperty((longlong)param_1,(longlong)param_2);
      return iVar3;
    }
    if (uVar5 == 0x2d9404) {
      iVar3 = PartitionIoctlDsm((longlong)param_1,(longlong)param_2);
      return iVar3;
    }
    if (uVar5 < 0x2d0c15) {
      if (uVar5 != 0x2d0c14) {
        if (uVar5 < 0x74005) {
          if (uVar5 != 0x74004) {
            if (uVar5 < 0x70049) {
              if (uVar5 == 0x70048) {
                uVar4 = PartitionIoctlGetPartitionInfoEx((longlong)param_1,(longlong)param_2);
                goto LAB_140003554;
              }
              if (((uVar5 != 0x41018) && (uVar5 != 0x41020)) && (uVar5 != 0x70000)) {
                if (uVar5 == 0x70014) {
                  iVar3 = PartitionIoctlVerify((longlong)param_1,(longlong)param_2);
                  return iVar3;
                }
                if (uVar5 != 0x70024) goto LAB_140012d5a;
              }
            }
            else if ((uVar5 != 0x70050) && (uVar5 != 0x700a0)) {
              if (uVar5 == 0x700e8) {
                uVar4 = PartitionIoctlGetPartitionAttributes((longlong)param_1,(longlong)param_2);
                goto LAB_140003554;
              }
              if (uVar5 != 0x70c00) goto LAB_140012d5a;
            }
            goto LAB_14000346e;
          }
          uVar4 = PartitionIoctlGetPartitionInfo((longlong)param_1,(longlong)param_2);
        }
        else {
          if (uVar5 < 0x7480d) {
            if (uVar5 != 0x7480c) {
              if (uVar5 == 0x7405c) {
                uVar4 = PartitionIoctlGetLengthInfo((longlong)param_1,(longlong)param_2);
                goto LAB_140003554;
              }
              if (((uVar5 != 0x74800) && (uVar5 != 0x74804)) && (uVar5 != 0x74808))
              goto LAB_140012d5a;
            }
            goto LAB_14000346e;
          }
          if (uVar5 == 0x7c008) {
            uVar4 = PartitionIoctlSetPartitionInfo((longlong)param_1,(longlong)param_2);
          }
          else if (uVar5 == 0x7c04c) {
            uVar4 = PartitionIoctlSetPartitionInfoEx((longlong)param_1,(longlong)param_2);
          }
          else {
            if (uVar5 != 0x7c0ec) {
              if (uVar5 == 0x2d08c0) {
                uVar5 = PartitionIoctlManageBypassIo((longlong)param_1,(longlong)param_2);
                return uVar5;
              }
LAB_140012d5a:
              lVar6 = PartitionPassThrough((longlong)param_1,(longlong)param_2);
              return lVar6;
            }
            uVar4 = PartitionIoctlSetPartitionAttributes((longlong)param_1,(longlong)param_2);
          }
        }
LAB_140003554:
        *(uint *)(param_2 + 0x30) = uVar4;
        IofCompleteRequest(param_2,0);
        return uVar4;
      }
    }
    else if (uVar5 < 0x2dd499) {
      if (uVar5 == 0x2dd498) {
LAB_14000359e:
        lVar6 = PartitionIoctlBandmgmt((longlong)param_1,(longlong)param_2);
        return lVar6;
      }
      if (uVar5 < 0x2d4801) {
        if (uVar5 != 0x2d4800) {
          if (uVar5 == 0x2d1080) {
            uVar7 = PartitionIoctlGetDeviceNumber((longlong)param_1,(longlong)param_2);
            uVar4 = (uint)uVar7;
          }
          else {
            if (uVar5 != 0x2d1084) {
              if ((uVar5 == 0x2d148c) || (uVar5 == 0x2d149c)) goto LAB_14000359e;
              if (uVar5 != 0x2d164b) goto LAB_140012d5a;
              goto LAB_14000346e;
            }
            uVar4 = PartitionIoctlGetDeviceNumberEx((longlong)param_1,(longlong)param_2);
          }
          goto LAB_140003554;
        }
      }
      else if (((uVar5 != 0x2d4804) && (uVar5 != 0x2d4808)) && (uVar5 != 0x2dcc18)) {
        if (uVar5 != 0x2dd494) goto LAB_140012d5a;
        goto LAB_14000359e;
      }
    }
    else if (uVar5 < 0x4dc011) {
      if (uVar5 != 0x4dc010) {
        if ((uVar5 == 0x2dd4a0) || (uVar5 == 0x2dd4a8)) goto LAB_14000359e;
        if ((uVar5 != 0x4d0010) && (uVar5 != 0x4d0014)) goto LAB_140012d5a;
      }
    }
    else if (uVar5 != 0x4dc014) {
      if (uVar5 == 0x56c008) {
        if (param_2[0x40] == (_IRP)0x0) goto LAB_140003554;
      }
      else if (uVar5 != 0x56c064) {
        if (uVar5 != 0x66001b) goto LAB_140012d5a;
        goto LAB_14000346e;
      }
      uVar7 = PartitionIoctlVolumePostOnline((longlong)param_1);
      uVar4 = (uint)uVar7;
      goto LAB_140003554;
    }
  }
LAB_14000346e:
  param_2[0x43] = (_IRP)((char)param_2[0x43] + '\x01');
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  lVar1 = *(longlong *)(param_1 + 0x40);
  uVar2 = KeAcquireSpinLockRaiseToDpc(*(longlong *)(lVar1 + 0x18) + 0x70);
  uVar7 = *(undefined8 *)(lVar1 + 0x10);
  ObfReferenceObject(uVar7);
  KeReleaseSpinLock(*(longlong *)(lVar1 + 0x18) + 0x70,uVar2);
  lVar6 = IofCallDriver(uVar7,param_2);
  ObfDereferenceObject(uVar7);
  return lVar6;
}



===== McTemplateK0qdds_EtwWriteTransfer @ 14000378c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qdds_EtwWriteTransfer(void)

{
  longlong lVar1;
  undefined1 local_res20 [8];
  undefined1 uStack0000000000000028;
  undefined1 uStack0000000000000030;
  char *in_stack_00000038;
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  char *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_58 = local_res20;
  local_50 = 4;
  local_48 = &uStack0000000000000028;
  local_38 = &uStack0000000000000030;
  local_40 = 4;
  local_30 = 4;
  if (in_stack_00000038 == (char *)0x0) {
    local_20 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (in_stack_00000038[lVar1] != '\0');
    local_20 = (int)lVar1 + 1;
  }
  local_1c = 0;
  if (in_stack_00000038 == (char *)0x0) {
    in_stack_00000038 = "NULL";
  }
  local_28 = in_stack_00000038;
  McGenEventWrite_EtwWriteTransfer(in_stack_00000038,&WakeNotificationWorkItem,0,5,local_68);
  return;
}



===== McTemplateK0xxx_EtwWriteTransfer @ 14000384c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0xxx_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined8 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = &local_res20;
  local_40 = 8;
  local_38 = &param_5;
  local_30 = 8;
  local_28 = &param_6;
  local_20 = 8;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&RaceCompletion,0,4,local_58);
  return;
}



===== McTemplateK0pxxxquu_EtwWriteTransfer @ 1400038e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0pxxxquu_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10)

{
  undefined8 local_res20;
  undefined1 auStackY_c8 [32];
  undefined8 local_98 [2];
  undefined8 *local_88;
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
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_88 = &local_res20;
  local_80 = 8;
  local_78 = &param_5;
  local_70 = 8;
  local_68 = &param_6;
  local_60 = 8;
  local_58 = &param_7;
  local_50 = 8;
  local_48 = &param_8;
  local_38 = &param_9;
  local_28 = &param_10;
  local_40 = 4;
  local_30 = 1;
  local_20 = 1;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&IoPower,0,8,local_98);
  return;
}



===== McTemplateK0pxxu_EtwWriteTransfer @ 1400039b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0pxxu_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  undefined8 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_58 = &local_res20;
  local_50 = 8;
  local_48 = &param_5;
  local_40 = 8;
  local_38 = &param_6;
  local_30 = 8;
  local_28 = &param_7;
  local_20 = 1;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&IdlePower,0,5,local_68);
  return;
}



===== McGenEventWrite_EtwWriteTransfer @ 140003a50 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_140019008;
  if (DAT_140019008 == (ushort *)0x0) {
    uVar2 = 0;
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_140019008;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(Microsoft_Windows_Partition_Context,param_2,param_3,0,param_4,param_5);
  return;
}



===== PartitionSendRequest @ 140003ac0 =====

undefined4 PartitionSendRequest(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  uVar3 = KeAcquireSpinLockRaiseToDpc(*(longlong *)(lVar1 + 0x18) + 0x70);
  uVar2 = *(undefined8 *)(lVar1 + 0x10);
  ObfReferenceObject(uVar2);
  KeReleaseSpinLock(*(longlong *)(lVar1 + 0x18) + 0x70,uVar3);
  uVar4 = IofCallDriver(uVar2,param_2);
  ObfDereferenceObject(uVar2);
  return uVar4;
}



===== PmPassThrough @ 140003b60 =====

/* long __cdecl PmPassThrough(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl PmPassThrough(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  lVar1 = lVar2 + 0x78;
  iVar3 = IoAcquireRemoveLockEx(lVar1,param_2,"",1,0x20);
  if (iVar3 < 0) {
    *(int *)(param_2 + 0x30) = iVar3;
    IofCompleteRequest(param_2,0);
  }
  else {
    param_2[0x43] = (_IRP)((char)param_2[0x43] + '\x01');
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    iVar3 = IofCallDriver(*(undefined8 *)(lVar2 + 0x10),param_2);
    IoReleaseRemoveLockEx(lVar1,param_2,0x20);
  }
  return iVar3;
}



===== PartitionReferenceParent @ 140003c20 =====

undefined8 PartitionReferenceParent(longlong param_1)

{
  undefined8 uVar1;
  undefined1 uVar2;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(*(longlong *)(param_1 + 0x18) + 0x70);
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  ObfReferenceObject(uVar1);
  KeReleaseSpinLock(*(longlong *)(param_1 + 0x18) + 0x70,uVar2);
  return uVar1;
}



===== PartitionPassThrough @ 140003c90 =====

undefined4 PartitionPassThrough(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  lVar1 = *(longlong *)(param_1 + 0x40);
  uVar3 = KeAcquireSpinLockRaiseToDpc(*(longlong *)(lVar1 + 0x18) + 0x70);
  uVar2 = *(undefined8 *)(lVar1 + 0x10);
  ObfReferenceObject(uVar2);
  KeReleaseSpinLock(*(longlong *)(lVar1 + 0x18) + 0x70,uVar3);
  uVar4 = IofCallDriver(uVar2,param_2);
  ObfDereferenceObject(uVar2);
  return uVar4;
}



===== PartitionIoctlDsmCompletion @ 140003d40 =====

/* long __cdecl PartitionIoctlDsmCompletion(struct _DEVICE_OBJECT * __ptr64,struct _IRP *
   __ptr64,void * __ptr64) */

long __cdecl PartitionIoctlDsmCompletion(_DEVICE_OBJECT *param_1,_IRP *param_2,void *param_3)

{
  byte *pbVar1;
  uint uVar2;
  void *_Src;
  
  _Src = *(void **)(param_2 + 0x18);
  uVar2 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
  if (param_2[0x41] != (_IRP)0x0) {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  if (uVar2 != 0) {
    memmove(param_3,_Src,(ulonglong)uVar2);
  }
  *(void **)(param_2 + 0x18) = param_3;
  ExFreePoolWithTag(_Src,0);
  return 0;
}



===== RtlStringCchPrintfW @ 140003dc0 =====

undefined8
RtlStringCchPrintfW(wchar_t *param_1,longlong param_2,wchar_t *param_3,undefined8 param_4)

{
  ulonglong _Count;
  int iVar1;
  undefined8 uVar2;
  undefined8 local_res20;
  
  if (param_2 - 1U < 0x7fffffff) {
    _Count = param_2 - 1;
    uVar2 = 0;
    local_res20 = param_4;
    iVar1 = _vsnwprintf(param_1,_Count,param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (_Count < (ulonglong)(longlong)iVar1)) {
      param_1[_Count] = L'\0';
      uVar2 = 0x80000005;
    }
    else if ((longlong)iVar1 == _Count) {
      param_1[_Count] = L'\0';
    }
  }
  else {
    uVar2 = 0xc000000d;
    if (param_2 != 0) {
      *param_1 = L'\0';
    }
  }
  return uVar2;
}



===== RtlStringVPrintfWorkerW @ 140003e50 =====

undefined8
RtlStringVPrintfWorkerW
          (wchar_t *param_1,longlong param_2,undefined8 param_3,wchar_t *param_4,va_list param_5)

{
  ulonglong _Count;
  int iVar1;
  undefined8 uVar2;
  
  _Count = param_2 - 1;
  iVar1 = _vsnwprintf(param_1,_Count,param_4,param_5);
  if ((iVar1 < 0) || (_Count < (ulonglong)(longlong)iVar1)) {
    uVar2 = 0x80000005;
  }
  else {
    uVar2 = 0;
    if ((longlong)iVar1 != _Count) {
      return 0;
    }
  }
  param_1[_Count] = L'\0';
  return uVar2;
}



===== PartitionLength @ 140003ec0 =====

longlong PartitionLength(longlong param_1,char param_2)

{
  longlong lVar1;
  longlong *plVar2;
  
  lVar1 = 0x138;
  if (param_2 == '\0') {
    lVar1 = 0x148;
  }
  plVar2 = (longlong *)(lVar1 + param_1);
  if ((longlong *)*plVar2 == plVar2) {
    return 0;
  }
  return *(longlong *)(plVar2[1] + 0x20) + *(longlong *)(plVar2[1] + 0x10);
}



===== RtlStringCbCopyW @ 140003ef4 =====

uint RtlStringCbCopyW(short *param_1,ulonglong param_2,longlong param_3)

{
  short sVar1;
  uint uVar2;
  short *psVar3;
  ulonglong uVar4;
  longlong lVar5;
  longlong lVar6;
  
  uVar4 = param_2 >> 1;
  if (uVar4 - 1 < 0x7fffffff) {
    lVar5 = 0x7ffffffe - uVar4;
    lVar6 = param_3 - (longlong)param_1;
    do {
      if ((lVar5 + uVar4 == 0) || (sVar1 = *(short *)(lVar6 + (longlong)param_1), sVar1 == 0))
      break;
      *param_1 = sVar1;
      param_1 = param_1 + 1;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
    psVar3 = param_1 + -1;
    if (uVar4 != 0) {
      psVar3 = param_1;
    }
    *psVar3 = 0;
    uVar2 = ~-(uint)(uVar4 != 0) & 0x80000005;
  }
  else {
    uVar2 = 0xc000000d;
    if (uVar4 != 0) {
      *param_1 = 0;
      return 0xc000000d;
    }
  }
  return uVar2;
}



===== PartitionOffset @ 140003f68 =====

undefined8 PartitionOffset(longlong param_1,char param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  undefined8 uVar3;
  
  uVar3 = 0;
  plVar2 = (longlong *)((-(ulonglong)(param_2 != '\0') & 0xfffffffffffffff0) + param_1 + 0x148);
  plVar1 = (longlong *)*plVar2;
  if (plVar1 != plVar2) {
    uVar3 = plVar1[3];
  }
  return uVar3;
}



===== ScTrimString @ 140003f98 =====

/* void __cdecl ScTrimString(char * __ptr64) */

void __cdecl ScTrimString(char *param_1)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  char *pcVar6;
  
  lVar4 = -1;
  lVar3 = -1;
  do {
    lVar3 = lVar3 + 1;
  } while (param_1[lVar3] != '\0');
  if ((int)lVar3 != 0) {
    lVar3 = (longlong)(int)lVar3 + -1;
    if (-1 < lVar3) {
      pcVar6 = param_1 + lVar3;
      do {
        iVar1 = isspace((int)*pcVar6);
        if (iVar1 == 0) break;
        *pcVar6 = '\0';
        pcVar6 = pcVar6 + -1;
      } while (-1 < (longlong)pcVar6 - (longlong)param_1);
    }
    do {
      lVar4 = lVar4 + 1;
    } while (param_1[lVar4] != '\0');
    iVar1 = (int)lVar4;
    if (iVar1 != 0) {
      iVar5 = 0;
      if (0 < iVar1) {
        lVar3 = 0;
        do {
          iVar2 = isspace((int)param_1[lVar3]);
          if (iVar2 == 0) break;
          iVar5 = iVar5 + 1;
          lVar3 = lVar3 + 1;
        } while (lVar3 < iVar1);
      }
      memmove(param_1,param_1 + iVar5,(longlong)((iVar1 - iVar5) + 1));
    }
  }
  return;
}



===== PmGivePartition @ 140004038 =====

/* void __cdecl PmGivePartition(struct _DEVICE_EXTENSION * __ptr64,struct _PARTITION_EXTENSION *
   __ptr64) */

void __cdecl PmGivePartition(_DEVICE_EXTENSION *param_1,_PARTITION_EXTENSION *param_2)

{
  undefined8 *puVar1;
  char *pcVar2;
  longlong *plVar3;
  int iVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined1 *puVar7;
  bool bVar8;
  undefined1 uVar9;
  undefined7 uVar10;
  uint uVar11;
  undefined8 *puVar12;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 *puStack_d8;
  undefined8 local_c8;
  undefined8 uStack_c0;
  longlong local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  
  lVar5 = *(longlong *)(PmControlObject + 0x40);
  memset(&local_c8,0,0x90);
  local_e8 = 0;
  local_e0 = 0;
  puStack_d8 = (undefined8 *)0x0;
  if ((param_1[0x25c] == (_DEVICE_EXTENSION)0x0) || (*(char *)(lVar5 + 0xa8) != '\0')) {
    *(uint *)(*(longlong *)(param_2 + 8) + 0x34) =
         *(uint *)(*(longlong *)(param_2 + 8) + 0x34) |
         *(uint *)(*(longlong *)(param_1 + 8) + 0x34) & 0x40001;
  }
  puVar1 = (undefined8 *)(lVar5 + 0x48);
  puVar12 = (undefined8 *)*puVar1;
  do {
    if (puVar12 == puVar1) {
LAB_14000421f:
      bVar8 = false;
LAB_140004222:
      if ((*(longlong *)(param_2 + 0x70) == 0) || (bVar8)) {
        uVar9 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x70);
        *(uint *)(param_2 + 0x28) = *(uint *)(param_2 + 0x28) & 0xfffffffd;
        KeReleaseSpinLock(param_1 + 0x70,uVar9);
        PmDecrementPendingPartitionsCount((longlong)param_1,1);
        if (*(longlong *)(param_2 + 0x70) == 0) {
          return;
        }
      }
      local_e8 = *(undefined8 *)(param_2 + 8);
      local_e0 = *(undefined8 *)(param_1 + 0x18);
      IoReuseIrp(*(undefined8 *)(param_1 + 0x358),0xc00000bb);
      lVar5 = *(longlong *)(param_1 + 0x358);
      pcVar2 = (char *)(lVar5 + 0x43);
      *pcVar2 = *pcVar2 + -1;
      plVar3 = (longlong *)(lVar5 + 0xb8);
      *plVar3 = *plVar3 + -0x48;
      lVar5 = *(longlong *)(param_1 + 0x358);
      uVar6 = *(undefined8 *)(*(longlong *)(param_2 + 0x70) + 0x28);
      puVar7 = *(undefined1 **)(lVar5 + 0xb8);
      *puVar7 = 0xf;
      *(undefined8 **)(lVar5 + 0x18) = &local_e8;
      *(undefined4 *)(puVar7 + 8) = 0;
      *(undefined4 *)(puVar7 + 0x10) = 0x18;
      *(undefined4 *)(puVar7 + 0x18) = 0x760030;
      IoForwardIrpSynchronously(uVar6,lVar5);
      if (*(int *)(lVar5 + 0x30) < 0) {
        uVar11 = 2;
      }
      else {
        uVar11 = (uint)(*(int *)(param_1 + 0x28c) == 0);
        *(int *)(param_1 + 0x28c) = *(int *)(param_1 + 0x28c) + 1;
        *(undefined4 *)(param_2 + 0x68) = 1;
      }
      LOCK();
      *(uint *)(param_1 + 0x288) = *(int *)(param_1 + 0x288) + uVar11;
      UNLOCK();
      return;
    }
    uVar9 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x70);
    local_c8 = *(undefined8 *)(param_2 + 0xa8);
    uStack_c0 = *(undefined8 *)(param_2 + 0xb0);
    local_b8 = *(longlong *)(param_2 + 0xb8);
    uStack_b0 = *(undefined8 *)(param_2 + 0xc0);
    local_a8 = *(undefined8 *)(param_2 + 200);
    uStack_a0 = *(undefined8 *)(param_2 + 0xd0);
    local_98 = *(undefined8 *)(param_2 + 0xd8);
    uStack_90 = *(undefined8 *)(param_2 + 0xe0);
    local_88 = *(undefined8 *)(param_2 + 0xe8);
    uStack_80 = *(undefined8 *)(param_2 + 0xf0);
    local_78 = *(undefined8 *)(param_2 + 0xf8);
    uStack_70 = *(undefined8 *)(param_2 + 0x100);
    local_68 = *(undefined8 *)(param_2 + 0x108);
    uStack_60 = *(undefined8 *)(param_2 + 0x110);
    uStack_58 = *(undefined8 *)(param_2 + 0x118);
    uStack_50 = *(undefined8 *)(param_2 + 0x120);
    uStack_48 = *(undefined8 *)(param_2 + 0x128);
    uStack_40 = *(undefined8 *)(param_2 + 0x130);
    uVar10 = (undefined7)((ulonglong)&local_c8 >> 8);
    local_b8 = PartitionLength((longlong)param_2,'\x01');
    local_e8 = *(undefined8 *)(param_2 + 8);
    local_e0 = *(undefined8 *)(param_1 + 0x18);
    puStack_d8 = &local_c8;
    KeReleaseSpinLock(param_1 + 0x70,CONCAT71(uVar10,uVar9));
    IoReuseIrp(*(undefined8 *)(param_1 + 0x358),0xc00000bb);
    lVar5 = *(longlong *)(param_1 + 0x358);
    pcVar2 = (char *)(lVar5 + 0x43);
    *pcVar2 = *pcVar2 + -1;
    plVar3 = (longlong *)(lVar5 + 0xb8);
    *plVar3 = *plVar3 + -0x48;
    lVar5 = *(longlong *)(param_1 + 0x358);
    uVar6 = puVar12[5];
    puVar7 = *(undefined1 **)(lVar5 + 0xb8);
    *puVar7 = 0xf;
    *(undefined8 **)(lVar5 + 0x18) = &local_e8;
    *(undefined4 *)(puVar7 + 8) = 1;
    *(undefined4 *)(puVar7 + 0x10) = 0x18;
    *(undefined4 *)(puVar7 + 0x18) = 0x760000;
    IoForwardIrpSynchronously(uVar6,lVar5);
    iVar4 = *(int *)(lVar5 + 0x38);
    if (-1 < *(int *)(lVar5 + 0x30)) {
      LOCK();
      *(int *)(puVar12 + 4) = *(int *)(puVar12 + 4) + 1;
      UNLOCK();
      *(undefined8 **)(param_2 + 0x70) = puVar12;
      if ((iVar4 != 1) || ((char)local_e8 == '\0')) {
        bVar8 = true;
        goto LAB_140004222;
      }
      goto LAB_14000421f;
    }
    puVar12 = (undefined8 *)*puVar12;
  } while( true );
}



===== PmDecrementPendingPartitionsCount @ 140004338 =====

void PmDecrementPendingPartitionsCount(longlong param_1,int param_2)

{
  longlong lVar1;
  longlong ****pppplVar2;
  longlong ***ppplVar3;
  uint uVar4;
  longlong ****pppplVar5;
  undefined8 uVar6;
  code *pcVar7;
  undefined1 uVar8;
  longlong ****pppplVar9;
  longlong ****pppplVar10;
  undefined1 *puVar11;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [24];
  undefined8 local_48;
  longlong ****local_28;
  longlong ****local_20;
  
  local_48 = 0;
  lVar1 = param_1 + 0x38;
  KeWaitForSingleObject(lVar1,0,0,0);
  *(int *)(param_1 + 0x370) = *(int *)(param_1 + 0x370) - param_2;
  if (*(int *)(param_1 + 0x370) == 0) {
    uVar8 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x70);
    uVar4 = *(uint *)(param_1 + 0x200);
    KeReleaseSpinLock(param_1 + 0x70,uVar8);
    if ((uVar4 & 0x14) != 0) {
      local_28 = (longlong ****)&local_28;
      pppplVar5 = *(longlong *****)(param_1 + 0x360);
      local_20 = (longlong ****)&local_28;
      while (pppplVar9 = pppplVar5, pppplVar9 != (longlong ****)(param_1 + 0x360)) {
        LOCK();
        ppplVar3 = pppplVar9[-8];
        pppplVar9[-8] = (longlong ***)0x0;
        UNLOCK();
        pppplVar5 = (longlong ****)*pppplVar9;
        if (ppplVar3 == (longlong ***)0x0) {
        }
        else {
          if ((longlong ****)pppplVar5[1] != pppplVar9) goto LAB_14000449b;
          ppplVar3 = pppplVar9[1];
          if ((longlong ****)*ppplVar3 != pppplVar9) goto LAB_14000449b;
          *ppplVar3 = (longlong **)pppplVar5;
          pppplVar5[1] = ppplVar3;
          pppplVar5 = (longlong ****)*pppplVar9;
          if ((longlong *****)*local_20 != &local_28) goto LAB_14000449b;
          pppplVar9[1] = (longlong ***)local_20;
          *pppplVar9 = (longlong ***)&local_28;
          *local_20 = (longlong ***)pppplVar9;
          local_20 = pppplVar9;
        }
      }
      KeReleaseMutex(lVar1,0);
      while (pppplVar5 = local_28, puVar11 = auStack_68, (longlong *****)local_28 != &local_28) {
        if (((longlong *****)local_28[1] != &local_28) ||
           (pppplVar9 = (longlong ****)*local_28, (longlong ****)pppplVar9[1] != local_28))
        goto LAB_14000449b;
        pppplVar9[1] = (longlong ***)&local_28;
        pppplVar10 = local_28 + -0x15;
        pppplVar2 = local_28 + -0xf;
        local_28 = pppplVar9;
        *(undefined4 *)pppplVar2 = 0;
        pppplVar5[-0xe] = (longlong ***)0x0;
        IofCompleteRequest(pppplVar10,0);
      }
      if (param_2 == 0) {
        return;
      }
      goto LAB_1400044a2;
    }
  }
  KeReleaseMutex(lVar1,0);
  return;
LAB_14000449b:
  pcVar7 = (code *)swi(0x29);
  (*pcVar7)(3);
  puVar11 = auStack_60;
LAB_1400044a2:
  uVar6 = *(undefined8 *)(param_1 + 0x10);
  puVar11[0x30] = 0;
  *(undefined4 *)(puVar11 + 0x28) = 0;
  *(undefined8 *)(puVar11 + 0x20) = 0;
  *(undefined8 *)(puVar11 + -8) = 0x1400044cd;
  PmSendDeviceControl(uVar6,0x7c220,param_1 + 0xa8,4,*(undefined8 *)(puVar11 + 0x20),
                      *(undefined4 *)(puVar11 + 0x28),puVar11[0x30]);
  return;
}



===== PmUpdatePartition @ 1400044d8 =====

/* long __cdecl PmUpdatePartition(struct _DEVICE_EXTENSION * __ptr64,struct _PARTITION_EXTENSION *
   __ptr64,struct _DRIVE_LAYOUT_INFORMATION_EX * __ptr64,unsigned long,struct
   _PARTITION_INFORMATION_EX * __ptr64) */

long __cdecl
PmUpdatePartition(_DEVICE_EXTENSION *param_1,_PARTITION_EXTENSION *param_2,
                 _DRIVE_LAYOUT_INFORMATION_EX *param_3,ulong param_4,
                 _PARTITION_INFORMATION_EX *param_5)

{
  _DEVICE_EXTENSION *p_Var1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined1 uVar6;
  ulong uVar7;
  long lVar8;
  longlong lVar9;
  longlong lVar10;
  
  lVar8 = 0;
  uVar7 = PmVerifyPropertyChange(param_5,(_PARTITION_INFORMATION_EX *)(param_2 + 0xa8));
  p_Var1 = param_1 + 0x70;
  uVar6 = KeAcquireSpinLockRaiseToDpc(p_Var1);
  *(uint *)(param_2 + 0x28) = *(uint *)(param_2 + 0x28) | uVar7;
  *(ulong *)(param_2 + 0xa0) = param_4;
  uVar5 = *(undefined8 *)(param_5 + 8);
  *(undefined8 *)(param_2 + 0xa8) = *(undefined8 *)param_5;
  *(undefined8 *)(param_2 + 0xb0) = uVar5;
  uVar5 = *(undefined8 *)(param_5 + 0x18);
  *(undefined8 *)(param_2 + 0xb8) = *(undefined8 *)(param_5 + 0x10);
  *(undefined8 *)(param_2 + 0xc0) = uVar5;
  uVar5 = *(undefined8 *)(param_5 + 0x28);
  *(undefined8 *)(param_2 + 200) = *(undefined8 *)(param_5 + 0x20);
  *(undefined8 *)(param_2 + 0xd0) = uVar5;
  uVar5 = *(undefined8 *)(param_5 + 0x38);
  *(undefined8 *)(param_2 + 0xd8) = *(undefined8 *)(param_5 + 0x30);
  *(undefined8 *)(param_2 + 0xe0) = uVar5;
  uVar5 = *(undefined8 *)(param_5 + 0x48);
  *(undefined8 *)(param_2 + 0xe8) = *(undefined8 *)(param_5 + 0x40);
  *(undefined8 *)(param_2 + 0xf0) = uVar5;
  uVar5 = *(undefined8 *)(param_5 + 0x58);
  *(undefined8 *)(param_2 + 0xf8) = *(undefined8 *)(param_5 + 0x50);
  *(undefined8 *)(param_2 + 0x100) = uVar5;
  uVar5 = *(undefined8 *)(param_5 + 0x68);
  *(undefined8 *)(param_2 + 0x108) = *(undefined8 *)(param_5 + 0x60);
  *(undefined8 *)(param_2 + 0x110) = uVar5;
  uVar2 = *(undefined4 *)(param_5 + 0x74);
  uVar3 = *(undefined4 *)(param_5 + 0x78);
  uVar4 = *(undefined4 *)(param_5 + 0x7c);
  *(undefined4 *)(param_2 + 0x118) = *(undefined4 *)(param_5 + 0x70);
  *(undefined4 *)(param_2 + 0x11c) = uVar2;
  *(undefined4 *)(param_2 + 0x120) = uVar3;
  *(undefined4 *)(param_2 + 0x124) = uVar4;
  uVar2 = *(undefined4 *)(param_5 + 0x84);
  uVar3 = *(undefined4 *)(param_5 + 0x88);
  uVar4 = *(undefined4 *)(param_5 + 0x8c);
  *(undefined4 *)(param_2 + 0x128) = *(undefined4 *)(param_5 + 0x80);
  *(undefined4 *)(param_2 + 300) = uVar2;
  *(undefined4 *)(param_2 + 0x130) = uVar3;
  *(undefined4 *)(param_2 + 0x134) = uVar4;
  KeReleaseSpinLock(p_Var1,uVar6);
  lVar9 = IoGetAttachedDeviceReference(*(undefined8 *)(param_1 + 8));
  lVar10 = lVar9;
  if (lVar9 != *(longlong *)(param_2 + 0x10)) {
    PartitionAcquireRundownExclusive((longlong)param_2);
    uVar6 = KeAcquireSpinLockRaiseToDpc(p_Var1);
    LOCK();
    lVar10 = *(longlong *)(param_2 + 0x10);
    *(longlong *)(param_2 + 0x10) = lVar9;
    UNLOCK();
    KeReleaseSpinLock(p_Var1,uVar6);
    PartitionReleaseRundownExclusive((longlong)param_2);
  }
  ObfDereferenceObject(lVar10);
  if ((uVar7 & 0x20) != 0) {
    lVar8 = PmBuildStableGuid(param_1,param_2);
    if (-1 < lVar8) {
      lVar8 = PmBuildUniqueId(param_1,param_2);
    }
  }
  return lVar8;
}



===== PmVerifyPropertyChange @ 140004644 =====

/* unsigned long __cdecl PmVerifyPropertyChange(struct _PARTITION_INFORMATION_EX * __ptr64,struct
   _PARTITION_INFORMATION_EX * __ptr64) */

ulong __cdecl
PmVerifyPropertyChange(_PARTITION_INFORMATION_EX *param_1,_PARTITION_INFORMATION_EX *param_2)

{
  int iVar1;
  longlong lVar2;
  ulong uVar3;
  
  iVar1 = *(int *)param_1;
  uVar3 = 0;
  if (iVar1 == *(int *)param_2) {
    if (iVar1 == 0) {
      uVar3 = -(uint)(param_1[0x20] != param_2[0x20]) & 0x10;
      lVar2 = *(longlong *)(param_1 + 0x28) - *(longlong *)(param_2 + 0x28);
      if (lVar2 == 0) {
        lVar2 = *(longlong *)(param_1 + 0x30) - *(longlong *)(param_2 + 0x30);
      }
      if (lVar2 != 0) {
        uVar3 = uVar3 | 0x20;
      }
    }
    else if (iVar1 == 1) {
      if (((*(ulonglong *)(param_2 + 0x40) ^ *(ulonglong *)(param_1 + 0x40)) >> 0x3a & 1) == 0) {
        uVar3 = 0;
        if (*(ulonglong *)(param_1 + 0x40) != *(ulonglong *)(param_2 + 0x40)) {
          uVar3 = 0x10;
        }
      }
      else {
        uVar3 = 0x100;
      }
      lVar2 = *(longlong *)(param_1 + 0x20) - *(longlong *)(param_2 + 0x20);
      if (lVar2 == 0) {
        lVar2 = *(longlong *)(param_1 + 0x28) - *(longlong *)(param_2 + 0x28);
      }
      if (lVar2 != 0) {
        uVar3 = uVar3 | 0x10;
      }
    }
  }
  else {
    uVar3 = 0x30;
    if ((iVar1 == 1) && ((*(ulonglong *)(param_1 + 0x40) >> 0x3a & 1) != 0)) {
      uVar3 = 0x130;
    }
  }
  return uVar3;
}



===== PmAssociatePartitions @ 1400046fc =====

/* long __cdecl PmAssociatePartitions(struct _DEVICE_EXTENSION * __ptr64,struct
   _DRIVE_LAYOUT_INFORMATION_EX * __ptr64) */

long __cdecl PmAssociatePartitions(_DEVICE_EXTENSION *param_1,_DRIVE_LAYOUT_INFORMATION_EX *param_2)

{
  _DEVICE_EXTENSION *p_Var1;
  _DEVICE_EXTENSION *p_Var2;
  undefined1 uVar3;
  long lVar4;
  longlong lVar5;
  _DEVICE_EXTENSION *p_Var6;
  
  p_Var1 = param_1 + 0x70;
  lVar4 = 0;
  uVar3 = KeAcquireSpinLockRaiseToDpc(p_Var1);
  p_Var2 = param_1 + 0x380;
  for (p_Var6 = *(_DEVICE_EXTENSION **)p_Var2; p_Var6 != p_Var2;
      p_Var6 = *(_DEVICE_EXTENSION **)p_Var6) {
    *(undefined8 *)(p_Var6 + -0x70) = 0;
    if (*(int *)param_2 == 1) {
      lVar5 = *(longlong *)(p_Var6 + 0x38) + -0x6aa896aa8967a686;
      if (lVar5 == 0) {
        lVar5 = *(longlong *)(p_Var6 + 0x40) + 0x6fefaba9bd57766b;
      }
      if (lVar5 == 0) {
        *(uint *)(p_Var6 + -0x68) = *(uint *)(p_Var6 + -0x68) | 0x40;
        lVar4 = PmAssociatePartition(param_1,(_PARTITION_EXTENSION *)(p_Var6 + -0x90));
        if (lVar4 < 0) goto LAB_14000479a;
      }
    }
  }
  for (p_Var6 = *(_DEVICE_EXTENSION **)p_Var2; p_Var6 != p_Var2;
      p_Var6 = *(_DEVICE_EXTENSION **)p_Var6) {
    if (((*(uint *)(p_Var6 + -0x68) & 0x40) == 0) &&
       (*(_DEVICE_EXTENSION **)(p_Var6 + 0xb8) == p_Var6 + 0xb8)) {
      lVar4 = PartitionInsertPatch
                        ((_PARTITION_EXTENSION *)(p_Var6 + -0x90),0,*(__uint64 *)(p_Var6 + 0x20),
                         *(__uint64 *)(p_Var6 + 0x28));
      if (lVar4 < 0) goto LAB_14000479a;
    }
  }
  KeReleaseSpinLock(p_Var1,uVar3);
  PmCommitPending(param_1,param_2);
LAB_14000480d:
  PmFreePending(param_1);
  return lVar4;
LAB_14000479a:
  KeReleaseSpinLock(p_Var1,uVar3);
  goto LAB_14000480d;
}



===== PmFreePending @ 140004848 =====

/* void __cdecl PmFreePending(struct _DEVICE_EXTENSION * __ptr64) */

void __cdecl PmFreePending(_DEVICE_EXTENSION *param_1)

{
  _DEVICE_EXTENSION *p_Var1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined1 uVar5;
  _DEVICE_EXTENSION *p_Var6;
  
  uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x70);
  p_Var6 = *(_DEVICE_EXTENSION **)(param_1 + 0x380);
  do {
    if (p_Var6 == param_1 + 0x380) {
      KeReleaseSpinLock(param_1 + 0x70,uVar5);
      return;
    }
    while (p_Var1 = *(_DEVICE_EXTENSION **)(p_Var6 + 0xb8), p_Var1 != p_Var6 + 0xb8) {
      lVar2 = *(longlong *)p_Var1;
      if ((*(_DEVICE_EXTENSION **)(lVar2 + 8) != p_Var1) ||
         (plVar3 = *(longlong **)(p_Var1 + 8), (_DEVICE_EXTENSION *)*plVar3 != p_Var1)) {
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3);
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      *plVar3 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar3;
      ExFreePoolWithTag(p_Var1,0);
    }
    p_Var6 = *(_DEVICE_EXTENSION **)p_Var6;
  } while( true );
}



===== PartitionInsertPatch @ 140004900 =====

/* long __cdecl PartitionInsertPatch(struct _PARTITION_EXTENSION * __ptr64,unsigned __int64,unsigned
   __int64,unsigned __int64) */

long __cdecl
PartitionInsertPatch
          (_PARTITION_EXTENSION *param_1,__uint64 param_2,__uint64 param_3,__uint64 param_4)

{
  undefined8 *puVar1;
  code *pcVar2;
  undefined8 *puVar3;
  _PARTITION_EXTENSION *p_Var4;
  _PARTITION_EXTENSION *p_Var5;
  undefined1 *puVar6;
  undefined8 uStack_30;
  undefined1 auStack_28 [32];
  
  puVar6 = auStack_28;
  p_Var4 = param_1 + 0x148;
  p_Var5 = *(_PARTITION_EXTENSION **)p_Var4;
  do {
    if (p_Var5 != p_Var4) goto LAB_14000499a;
    do {
      *(undefined8 *)(puVar6 + -8) = 0x140004948;
      puVar3 = (undefined8 *)ExAllocatePool2(0x42,0x28,0x50506d50);
      if (puVar3 == (undefined8 *)0x0) {
        return -0x3fffff66;
      }
      puVar3[2] = param_2;
      puVar3[3] = param_3;
      puVar3[4] = param_4;
      puVar1 = *(undefined8 **)(p_Var5 + 8);
      if ((_PARTITION_EXTENSION *)*puVar1 == p_Var5) {
        *puVar3 = p_Var5;
        puVar3[1] = puVar1;
        *puVar1 = puVar3;
        *(undefined8 **)(p_Var5 + 8) = puVar3;
        return 0;
      }
      p_Var4 = (_PARTITION_EXTENSION *)0x3;
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)();
      puVar6 = puVar6 + 8;
LAB_14000499a:
    } while (param_2 < *(ulonglong *)(p_Var5 + 0x10));
    p_Var5 = *(_PARTITION_EXTENSION **)p_Var5;
  } while( true );
}



===== PmCommitPending @ 1400049b4 =====

/* void __cdecl PmCommitPending(struct _DEVICE_EXTENSION * __ptr64,struct
   _DRIVE_LAYOUT_INFORMATION_EX * __ptr64) */

void __cdecl PmCommitPending(_DEVICE_EXTENSION *param_1,_DRIVE_LAYOUT_INFORMATION_EX *param_2)

{
  _DEVICE_EXTENSION *p_Var1;
  _LIST_ENTRY *p_Var2;
  undefined1 uVar3;
  ulong uVar4;
  ulong uVar5;
  undefined8 uVar6;
  _GUID *p_Var7;
  _tlgProvider_t *p_Var8;
  _DEVICE_EXTENSION *p_Var9;
  _GUID *in_R9;
  undefined4 local_res8 [2];
  _DRIVE_LAYOUT_INFORMATION_EX *local_res10;
  ulong local_res18 [2];
  _DEVICE_EXTENSION *local_res20;
  _DEVICE_EXTENSION *local_58;
  _GUID *local_50 [2];
  
  p_Var9 = *(_DEVICE_EXTENSION **)(param_1 + 0x380);
  local_res10 = param_2;
  do {
    if (p_Var9 == param_1 + 0x380) {
      return;
    }
    p_Var1 = p_Var9 + -0x90;
    p_Var2 = (_LIST_ENTRY *)(p_Var9 + 0xb8);
    if (*(_LIST_ENTRY **)p_Var2 != p_Var2) {
      uVar4 = PmCountList((_LIST_ENTRY *)(p_Var9 + 0xa8));
      uVar5 = PmCountList(p_Var2);
      p_Var8 = (_tlgProvider_t *)(ulonglong)uVar5;
      if (uVar4 != uVar5) {
        if (uVar4 == 0) {
          if ((1 < uVar5) && (5 < DAT_140019068)) {
            uVar6 = _tlgKeywordOn();
            if ((char)uVar6 != '\0') {
              local_res20 = p_Var9 + 0x48;
              local_res8[0] = SUB84(p_Var8,0);
              local_res18[0] = *(ulong *)(param_2 + 4);
              local_58 = (_DEVICE_EXTENSION *)(param_2 + 8);
              _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
              ::
              Write<_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapperByRef<16>,_tlgWrapperByVal<4>_>
                        (p_Var8,&DAT_1400157fe,(_GUID *)param_2,in_R9,
                         (_tlgWrapperByRef<16> *)&local_58,(_tlgWrapperByVal<4> *)local_res18,
                         (_tlgWrapperByRef<16> *)&local_res20,(_tlgWrapperByVal<4> *)local_res8);
            }
          }
        }
        else if (5 < DAT_140019068) {
          uVar6 = _tlgKeywordOn();
          if ((char)uVar6 != '\0') {
            local_58 = p_Var9 + 0x48;
            local_res8[0] = SUB84(p_Var8,0);
            local_res20 = (_DEVICE_EXTENSION *)
                          CONCAT44(local_res20._4_4_,*(undefined4 *)(param_2 + 4));
            local_50[0] = (_GUID *)(param_2 + 8);
            local_res18[0] = uVar4;
            _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
            ::
            Write<_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>_>
                      (p_Var8,&DAT_140015799,(_GUID *)param_2,in_R9,(_tlgWrapperByRef<16> *)local_50
                       ,(_tlgWrapperByVal<4> *)&local_res20,(_tlgWrapperByRef<16> *)&local_58,
                       (_tlgWrapperByVal<4> *)local_res18,(_tlgWrapperByVal<4> *)local_res8);
          }
        }
      }
      if ((*(uint *)(p_Var9 + -0x68) & 0x10) == 0) {
        in_R9 = (_GUID *)PartitionOffset((longlong)p_Var1,'\x01');
        p_Var7 = (_GUID *)PartitionOffset((longlong)p_Var1,'\0');
        if (in_R9 != p_Var7) goto LAB_140004b3c;
        in_R9 = (_GUID *)PartitionLength((longlong)p_Var1,'\x01');
        p_Var7 = (_GUID *)PartitionLength((longlong)p_Var1,'\0');
        if (in_R9 != p_Var7) goto LAB_140004b3c;
      }
      else {
LAB_140004b3c:
        PartitionAcquireRundownExclusive((longlong)p_Var1);
        uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x70);
        in_R9 = (_GUID *)CONCAT71((int7)((ulonglong)in_R9 >> 8),uVar3);
        PmSwapList((_LIST_ENTRY *)(p_Var9 + 0xa8),p_Var2);
        if (uVar4 != 0) {
          *(uint *)(p_Var9 + -0x68) = *(uint *)(p_Var9 + -0x68) | 0x10;
        }
        KeReleaseSpinLock(param_1 + 0x70,(ulonglong)in_R9 & 0xff);
        PartitionReleaseRundownExclusive((longlong)p_Var1);
      }
      param_2 = local_res10;
    }
    p_Var9 = *(_DEVICE_EXTENSION **)p_Var9;
  } while( true );
}



===== UpdateStorageProperty @ 140004bb4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl SC_DEVICE::UpdateStorageProperty(enum _STORAGE_PROPERTY_ID) __ptr64 */

long __thiscall SC_DEVICE::UpdateStorageProperty(SC_DEVICE *this,_STORAGE_PROPERTY_ID param_1)

{
  long lVar1;
  _STORAGE_DESCRIPTOR_HEADER *local_res18 [2];
  
  local_res18[0] = (_STORAGE_DESCRIPTOR_HEADER *)0x0;
  lVar1 = GetStorageProperty(this,param_1,local_res18);
  if (-1 < lVar1) {
    (**(code **)(*(longlong *)this + 0x30))(this,6,local_res18[0]);
  }
  return lVar1;
}



===== GetStorageProperty @ 140004c08 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl SC_DEVICE::GetStorageProperty(enum _STORAGE_PROPERTY_ID,struct
   _STORAGE_DESCRIPTOR_HEADER * __ptr64 * __ptr64) __ptr64 */

long __thiscall
SC_DEVICE::GetStorageProperty
          (SC_DEVICE *this,_STORAGE_PROPERTY_ID param_1,_STORAGE_DESCRIPTOR_HEADER **param_2)

{
  uint uVar1;
  int iVar2;
  _STORAGE_DESCRIPTOR_HEADER *p_Var3;
  uint uVar4;
  undefined1 auStack_88 [32];
  _STORAGE_DESCRIPTOR_HEADER *local_68;
  uint local_60;
  uint local_48 [2];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_88;
  *param_2 = (_STORAGE_DESCRIPTOR_HEADER *)0x0;
  local_48[0] = 0;
  local_38 = 0;
  iVar2 = (**(code **)(*(longlong *)this + 0x20))(this,6,local_48);
  if (-1 < iVar2) {
    local_3c = 0;
    local_40 = 6;
    uVar4 = local_48[0];
    while (p_Var3 = (_STORAGE_DESCRIPTOR_HEADER *)ExAllocatePool2(0x40,uVar4,0x6d506353),
          p_Var3 != (_STORAGE_DESCRIPTOR_HEADER *)0x0) {
      local_68 = p_Var3;
      local_60 = uVar4;
      iVar2 = (**(code **)(*(longlong *)this + 0x10))(this,0x2d1400,&local_40,0xc);
      if (((iVar2 + 0x80000000U & 0x80000000) == 0) && (iVar2 != -0x7ffffffb)) {
LAB_140004cf4:
        ExFreePoolWithTag(p_Var3,0);
        return iVar2;
      }
      uVar1 = *(uint *)(p_Var3 + 4);
      if (uVar1 <= uVar4) {
        *(uint *)(p_Var3 + 4) = uVar4;
        iVar2 = (**(code **)(*(longlong *)this + 0x28))(this,6,p_Var3);
        if (-1 < iVar2) {
          *param_2 = p_Var3;
          return iVar2;
        }
        goto LAB_140004cf4;
      }
      ExFreePoolWithTag(p_Var3,0);
      uVar4 = uVar1;
    }
    iVar2 = -0x3fffff66;
  }
  return iVar2;
}



===== PmGetSnapshotData @ 140004d54 =====

long PmGetSnapshotData(_DEVICE_EXTENSION *param_1,_DRIVE_LAYOUT_INFORMATION_EX *param_2,
                      undefined8 *param_3,uint *param_4)

{
  _DEVICE_EXTENSION *p_Var1;
  uint uVar2;
  undefined1 uVar3;
  uchar uVar4;
  long lVar5;
  void *_Dst;
  _DISK_SNAPSHOT_DATA *_Src;
  undefined8 uVar6;
  _DISK_SNAPSHOT_DATA *_Dst_00;
  ulong uVar7;
  ulong local_res8 [2];
  _DISK_SNAPSHOT_DATA *local_48 [2];
  
  local_res8[0] = 0;
  p_Var1 = param_1 + 0x70;
  lVar5 = 0;
  *param_3 = 0;
  *param_4 = 0;
  uVar3 = KeAcquireSpinLockRaiseToDpc(p_Var1);
  _Dst_00 = *(_DISK_SNAPSHOT_DATA **)(param_1 + 0x470);
  *(undefined8 *)(param_1 + 0x470) = 0;
  local_48[0] = _Dst_00;
  KeReleaseSpinLock(p_Var1,uVar3);
  if (_Dst_00 == (_DISK_SNAPSHOT_DATA *)0x0) {
    lVar5 = PmReadSnapshotData(param_1,param_2,local_48,local_res8);
    _Src = local_48[0];
    uVar7 = local_res8[0];
    if (lVar5 != -0x3ffffddb) {
      if (lVar5 < 0) goto LAB_140004f00;
      uVar4 = PmVerifySnapshotData(local_48[0],local_res8[0],'\x01');
      if (uVar4 == '\0') goto LAB_140004ed8;
LAB_140004e0c:
      if (*(int *)(_Src + 0x14) == 1) {
        if (*(longlong *)(param_1 + 0xf8) == 0) {
          lVar5 = -0x3ffffddb;
          goto LAB_140004f00;
        }
        uVar6 = PmLookupId(*(longlong *)(param_1 + 0xf8),_Src + *(uint *)(_Src + 0x60),
                           *(ushort *)(_Src + 100));
        if ((char)uVar6 != '\0') {
          *(undefined4 *)(_Src + 0x14) = 0;
        }
      }
      uVar2 = *(uint *)(_Src + 0xc);
      _Dst_00 = _Src;
      if (uVar2 < uVar7) {
        _Dst_00 = (_DISK_SNAPSHOT_DATA *)ExAllocatePool2(0x42,(ulonglong)uVar2,0x44536d50);
        if (_Dst_00 == (_DISK_SNAPSHOT_DATA *)0x0) goto LAB_140004efb;
        memmove(_Dst_00,_Src,(ulonglong)uVar2);
        ExFreePoolWithTag(_Src,0);
        uVar7 = uVar2;
      }
      PmSetDeviceParameterBinary(param_1,L"SnapshotDataCache",_Dst_00,uVar7);
      goto LAB_140004e36;
    }
    uVar7 = 0x70;
    _Src = (_DISK_SNAPSHOT_DATA *)ExAllocatePool2(0x42,0x70,0x44536d50);
    if (_Src != (_DISK_SNAPSHOT_DATA *)0x0) {
      lVar5 = 0;
LAB_140004ed8:
      PmInitializeSnapshotData(_Src,uVar7);
      goto LAB_140004e0c;
    }
  }
  else {
LAB_140004e36:
    uVar2 = *(uint *)(_Dst_00 + 0xc);
    _Dst = (void *)ExAllocatePool2(0x42,uVar2,0x44536d50);
    _Src = _Dst_00;
    if (_Dst != (void *)0x0) {
      memmove(_Dst,_Dst_00,(ulonglong)uVar2);
      *param_3 = _Dst;
      *param_4 = uVar2;
      uVar3 = KeAcquireSpinLockRaiseToDpc(p_Var1);
      *(_DISK_SNAPSHOT_DATA **)(param_1 + 0x470) = _Dst_00;
      KeReleaseSpinLock(p_Var1,uVar3);
      return lVar5;
    }
  }
LAB_140004efb:
  lVar5 = -0x3fffff66;
LAB_140004f00:
  if (_Src != (_DISK_SNAPSHOT_DATA *)0x0) {
    ExFreePoolWithTag(_Src,0);
  }
  return lVar5;
}



===== PmPower @ 140004f20 =====

/* long __cdecl PmPower(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl PmPower(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 *puVar3;
  bool bVar4;
  int iVar5;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar2 = *(longlong *)(param_2 + 0xb8);
  bVar4 = true;
  iVar5 = IoAcquireRemoveLockEx(lVar1 + 0x78,0,"",1,0x20);
  if (iVar5 < 0) {
    PoStartNextPowerIrp(param_2);
    *(int *)(param_2 + 0x30) = iVar5;
    IofCompleteRequest(param_2,0);
  }
  else {
    if ((*(char *)(lVar2 + 1) == '\x02') && (*(int *)(lVar2 + 0x10) == 1)) {
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
      lVar2 = *(longlong *)(param_2 + 0xb8);
      *(undefined8 *)(lVar2 + -8) = 0;
      bVar4 = false;
      *(code **)(lVar2 + -0x10) = PmPowerCompletion;
      *(undefined1 *)(lVar2 + -0x45) = 0xe0;
    }
    else {
      PoStartNextPowerIrp(param_2);
      param_2[0x43] = (_IRP)((char)param_2[0x43] + '\x01');
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    }
    iVar5 = PoCallDriver(*(undefined8 *)(lVar1 + 0x10),param_2);
    if (bVar4) {
      IoReleaseRemoveLockEx(lVar1 + 0x78,0,0x20);
    }
  }
  return iVar5;
}



===== PmIoctlIsClustered @ 14000506c =====

uint PmIoctlIsClustered(longlong param_1,longlong param_2,char param_3)

{
  longlong lVar1;
  undefined1 uVar2;
  longlong lVar3;
  uint uVar4;
  undefined1 *puVar5;
  undefined8 uVar6;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  puVar5 = (undefined1 *)0x0;
  uVar4 = 0;
  uVar6 = 0;
  if (param_3 == '\0') {
    if (*(int *)(*(longlong *)(param_2 + 0xb8) + 8) == 0) {
      return 0xc0000023;
    }
    puVar5 = *(undefined1 **)(param_2 + 0x18);
    uVar6 = 1;
  }
  KeWaitForSingleObject(lVar1 + 0x38,0,0,0,0);
  lVar3 = *(longlong *)(lVar1 + 0x220) + -0x4354eeb5026061e9;
  if (lVar3 == 0) {
    lVar3 = *(longlong *)(lVar1 + 0x228) + 0x502d88342de82841;
  }
  if (lVar3 == 0) {
    if (param_3 == '\0') {
      *puVar5 = 1;
    }
    else {
      uVar2 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x70);
      uVar4 = *(uint *)(lVar1 + 0x200);
      KeReleaseSpinLock(lVar1 + 0x70,uVar2);
      uVar4 = -(uint)((uVar4 & 8) != 0) & 0xc0000001;
    }
  }
  else if (param_3 == '\0') {
    *puVar5 = 0;
  }
  else {
    uVar4 = 0xc0000001;
  }
  KeReleaseMutex(lVar1 + 0x38,0);
  if (param_3 == '\0') {
    *(undefined8 *)(param_2 + 0x38) = uVar6;
  }
  return uVar4;
}



===== PmInvalidatePartitionTableCache @ 14000515c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PmInvalidatePartitionTableCache(longlong param_1)

{
  undefined1 uVar1;
  undefined1 auStack_58 [32];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 local_24;
  undefined8 local_20;
  undefined4 local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  local_24 = 0;
  local_14 = 0;
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x70);
  if (*(longlong *)(param_1 + 0x470) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x470),0);
    *(undefined8 *)(param_1 + 0x470) = 0;
  }
  if (*(longlong *)(param_1 + 0x468) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x468),0);
    *(undefined8 *)(param_1 + 0x468) = 0;
  }
  if (*(longlong *)(param_1 + 0x450) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x450),0);
    *(undefined8 *)(param_1 + 0x450) = 0;
    *(uint *)(param_1 + 0x200) = *(uint *)(param_1 + 0x200) & 0xffff7fff;
  }
  *(undefined4 *)(param_1 + 0x458) = 0;
  *(undefined8 *)(param_1 + 0x460) = 0;
  KeReleaseSpinLock(param_1 + 0x70,uVar1);
  local_20 = 0;
  local_18 = 0xffffffff;
  local_34 = 0x11dff54c;
  uStack_30 = 0x41f98469;
  uStack_2c = 0x83efdeb3;
  uStack_28 = 0x4ac58764;
  local_38 = 0x240001;
  IoReportTargetDeviceChangeAsynchronous(*(undefined8 *)(param_1 + 0x18),&local_38,0,0);
  return;
}



===== SC_DISK @ 14000529c =====

/* public: __cdecl SC_DISK::SC_DISK(void) __ptr64 */

SC_DISK * __thiscall SC_DISK::SC_DISK(SC_DISK *this)

{
  SC_DEVICE::SC_DEVICE((SC_DEVICE *)this);
  *(undefined4 *)(this + 0x100) = 2;
  *(undefined ***)this = &_vftable_;
  *(undefined4 *)(this + 0x130) = 0xffffffff;
  *(undefined4 *)(this + 0x134) = 0xffffffff;
  *(undefined8 *)(this + 0xd8) = 0;
  *(undefined8 *)(this + 0xe0) = 0;
  *(undefined4 *)(this + 200) = 0;
  *(undefined8 *)(this + 0xe8) = 0;
  *(undefined8 *)(this + 0xd0) = 0;
  *(undefined8 *)(this + 0x120) = 0;
  *(undefined8 *)(this + 0x128) = 0;
  *(undefined4 *)(this + 0xf0) = 0;
  *(undefined8 *)(this + 0xf8) = 0;
  *(undefined8 *)(this + 0x108) = 0;
  *(undefined8 *)(this + 0x110) = 0;
  *(undefined8 *)(this + 0x118) = 0;
  *(undefined8 *)(this + 0x138) = 0;
  *(undefined8 *)(this + 0x140) = 0;
  *(undefined8 *)(this + 0x148) = 0;
  *(undefined8 *)(this + 0x150) = 0;
  *(undefined8 *)(this + 0x158) = 0;
  *(undefined8 *)(this + 0x160) = 0;
  *(undefined8 *)(this + 0x168) = 0;
  *(undefined8 *)(this + 0x170) = 0;
  *(undefined8 *)(this + 0x178) = 0;
  *(undefined8 *)(this + 0x180) = 0;
  return this;
}



===== SC_DEVICE @ 140005384 =====

/* public: __cdecl SC_DEVICE::SC_DEVICE(void) __ptr64 */

SC_DEVICE * __thiscall SC_DEVICE::SC_DEVICE(SC_DEVICE *this)

{
  *(undefined ***)this = &_vftable_;
  *(undefined8 *)(this + 0x98) = 0;
  *(undefined8 *)(this + 0xa0) = 0;
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 0xa8) = 0;
  *(undefined8 *)(this + 0xb0) = 0;
  *(undefined8 *)(this + 0xb8) = 0;
  *(undefined8 *)(this + 0xc0) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined8 *)(this + 0x48) = 0;
  *(undefined8 *)(this + 0x50) = 0;
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined8 *)(this + 0x40) = 0;
  return this;
}



===== PmPowerCompletion @ 1400053f0 =====

/* long __cdecl PmPowerCompletion(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64,void *
   __ptr64) */

long __cdecl PmPowerCompletion(_DEVICE_OBJECT *param_1,_IRP *param_2,void *param_3)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 uVar3;
  int iVar4;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar2 = *(longlong *)(param_2 + 0xb8);
  if (param_2[0x41] != (_IRP)0x0) {
    *(byte *)(lVar2 + 3) = *(byte *)(lVar2 + 3) | 1;
  }
  if (-1 < *(int *)(param_2 + 0x30)) {
    uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x70);
    *(undefined4 *)(lVar1 + 0x260) = *(undefined4 *)(lVar2 + 0x18);
    iVar4 = PoSetPowerState(param_1,1,*(undefined4 *)(lVar2 + 0x18));
    if (iVar4 != *(int *)(lVar1 + 0x260)) {
      *(uint *)(lVar1 + 0x200) = *(uint *)(lVar1 + 0x200) | 0x80;
      PmQueueNotificationWorkItem(lVar1);
    }
    KeReleaseSpinLock(lVar1 + 0x70,uVar3);
  }
  PoStartNextPowerIrp(param_2);
  IoReleaseRemoveLockEx(lVar1 + 0x78,0,0x20);
  return 0;
}



===== ~SC_DISK @ 1400054d8 =====

/* public: virtual __cdecl SC_DISK::~SC_DISK(void) __ptr64 */

void __thiscall SC_DISK::~SC_DISK(SC_DISK *this)

{
  *(undefined ***)this = &_vftable_;
  if (*(longlong *)(this + 0x180) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 0x180),0);
  }
  if (*(longlong *)(this + 0x178) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 0x178),0);
  }
  if (*(longlong *)(this + 0x170) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 0x170),0);
  }
  if (*(longlong *)(this + 0x168) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 0x168),0);
  }
  if (*(longlong *)(this + 0x160) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 0x160),0);
  }
  if (*(longlong *)(this + 0x158) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 0x158),0);
  }
  if (*(longlong *)(this + 0x150) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 0x150),0);
  }
  if (*(longlong *)(this + 0x148) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 0x148),0);
  }
  if (*(longlong *)(this + 0x140) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 0x140),0);
  }
  if (*(longlong *)(this + 0x138) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 0x138),0);
  }
  if (*(longlong *)(this + 0x128) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 0x128),0);
  }
  if (*(longlong *)(this + 0x108) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 0x108),0);
  }
  SC_DEVICE::~SC_DEVICE((SC_DEVICE *)this);
  return;
}



===== ~SC_DEVICE @ 1400056a0 =====

/* public: virtual __cdecl SC_DEVICE::~SC_DEVICE(void) __ptr64 */

void __thiscall SC_DEVICE::~SC_DEVICE(SC_DEVICE *this)

{
  *(undefined ***)this = &_vftable_;
  if (*(longlong *)(this + 0xc0) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 0xc0),0);
  }
  if (*(longlong *)(this + 0xb8) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 0xb8),0);
  }
  if (*(longlong *)(this + 0xb0) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 0xb0),0);
  }
  if (*(longlong *)(this + 0xa0) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 0xa0),0);
  }
  if (*(longlong *)(this + 0x98) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 0x98),0);
  }
  if (*(longlong *)(this + 0xa8) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 0xa8),0);
  }
  if (*(longlong *)(this + 0x50) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 0x50),0);
  }
  if (*(longlong *)(this + 0x40) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 0x40),0);
  }
  if (*(longlong *)(this + 0x30) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 0x30),0);
  }
  if (*(longlong *)(this + 0x20) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 0x20),0);
  }
  return;
}



===== Initialize @ 140005820 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: virtual long __cdecl SC_DEVICE::Initialize(void) __ptr64 */

long __thiscall SC_DEVICE::Initialize(SC_DEVICE *this)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 auStack_58 [32];
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  local_38 = (undefined4 *)0x0;
  local_20 = 10;
  local_30 = 0xa45c254e;
  uStack_2c = 0x4efddf1c;
  uStack_28 = 0xd1672080;
  uStack_24 = 0xe050a846;
  iVar4 = (**(code **)(*(longlong *)this + 0x18))(0xa45c254e,&local_30,&local_38);
  if (iVar4 < 0) {
    iVar4 = 0;
  }
  else {
    uVar1 = local_38[1];
    uVar2 = local_38[2];
    uVar3 = local_38[3];
    *(undefined4 *)(this + 8) = *local_38;
    *(undefined4 *)(this + 0xc) = uVar1;
    *(undefined4 *)(this + 0x10) = uVar2;
    *(undefined4 *)(this + 0x14) = uVar3;
    ExFreePoolWithTag(local_38,0);
  }
  return iVar4;
}



===== GetStoragePropertyPre @ 1400058c0 =====

/* protected: virtual long __cdecl SC_DISK::GetStoragePropertyPre(enum _STORAGE_PROPERTY_ID,unsigned
   long * __ptr64) __ptr64 */

long __thiscall
SC_DISK::GetStoragePropertyPre(SC_DISK *this,_STORAGE_PROPERTY_ID param_1,ulong *param_2)

{
  long lVar1;
  
  *param_2 = 0;
  if ((int)param_1 < 0xf) {
    if (param_1 == 0xe) {
      *param_2 = 0x20;
      return 0;
    }
    if ((param_1 == 4) || (param_1 == 6)) {
      *param_2 = 0x1c;
      return 0;
    }
    if ((param_1 == 7) || (param_1 == 8)) {
      *param_2 = 0xc;
      return 0;
    }
    if (param_1 == 0xb) {
      *param_2 = 0x28;
      return 0;
    }
  }
  else {
    if (param_1 == 0x15) {
      *param_2 = 0x18;
      return 0;
    }
    if (param_1 == 0x39) {
      *param_2 = 0x108;
      return 0;
    }
    if (param_1 == 0x3a) {
      *param_2 = 0x24;
      return 0;
    }
    if (param_1 == 0x3c) {
      *param_2 = 0x30;
      return 0;
    }
    if (param_1 == 0x41) {
      *param_2 = 0x10;
      return 0;
    }
  }
  lVar1 = SC_DEVICE::GetStoragePropertyPre((SC_DEVICE *)this,param_1,param_2);
  return lVar1;
}



===== IsUnused @ 140005964 =====

/* public: unsigned char __cdecl SC_PART_ENTRY::IsUnused(void) __ptr64 */

uchar __thiscall SC_PART_ENTRY::IsUnused(SC_PART_ENTRY *this)

{
  longlong lVar1;
  bool bVar2;
  
  bVar2 = false;
  if (*(int *)this == 0) {
    bVar2 = this[0x20] == (SC_PART_ENTRY)0x0;
  }
  else if (*(int *)this == 1) {
    lVar1 = *(longlong *)(this + 0x20);
    if (lVar1 == 0) {
      lVar1 = *(longlong *)(this + 0x28);
    }
    if (lVar1 == 0) {
      bVar2 = true;
    }
  }
  return bVar2;
}



===== InitializePartitionCache @ 1400059b4 =====

/* public: long __cdecl SC_DISK::InitializePartitionCache(void) __ptr64 */

long __thiscall SC_DISK::InitializePartitionCache(SC_DISK *this)

{
  long lVar1;
  longlong lVar2;
  
  lVar2 = ExAllocatePool2(0x40,(longlong)(1 << ((byte)*(undefined4 *)(this + 0xf0) & 0x1f)),
                          0x6d506353);
  *(longlong *)(this + 0x108) = lVar2;
  if (lVar2 == 0) {
    lVar1 = -0x3fffff66;
  }
  else {
    lVar1 = ResetPartitionCache(this);
  }
  return lVar1;
}



===== ResetPartitionCache @ 140005a0c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl SC_DISK::ResetPartitionCache(void) __ptr64 */

long __thiscall SC_DISK::ResetPartitionCache(SC_DISK *this)

{
  longlong lVar1;
  uchar uVar2;
  int iVar3;
  
  iVar3 = (**(code **)(*(longlong *)this + 0x38))
                    (this,0,1 << ((byte)*(undefined4 *)(this + 0xf0) & 0x1f),
                     *(undefined8 *)(this + 0x108));
  if (-1 < iVar3) {
    lVar1 = *(longlong *)(this + 0x108);
    if (*(short *)(lVar1 + 0x1fe) == -0x55ab) {
      if ((((*(char *)(lVar1 + 0x1c2) == -0x12) && (*(char *)(lVar1 + 0x1d2) == '\0')) &&
          (*(char *)(lVar1 + 0x1e2) == '\0')) && (*(char *)(lVar1 + 0x1f2) == '\0')) {
        *(undefined4 *)(this + 0x100) = 1;
      }
      else {
        uVar2 = IsVbr(this);
        *(uint *)(this + 0x100) = -(uint)(uVar2 != '\0') & 2;
      }
    }
    else {
      *(undefined4 *)(this + 0x100) = 2;
    }
  }
  return iVar3;
}



===== PmCheckIds @ 140005ac0 =====

/* long __cdecl PmCheckIds(struct _DEVICE_EXTENSION * __ptr64,struct _DRIVE_LAYOUT_INFORMATION_EX *
   __ptr64,unsigned char * __ptr64,enum _DISK_OFFLINE_REASON * __ptr64) */

long __cdecl
PmCheckIds(_DEVICE_EXTENSION *param_1,_DRIVE_LAYOUT_INFORMATION_EX *param_2,uchar *param_3,
          _DISK_OFFLINE_REASON *param_4)

{
  longlong lVar1;
  undefined1 uVar2;
  int iVar3;
  
  lVar1 = PmControlObject;
  iVar3 = 0;
  *param_4 = 0;
  *param_3 = '\0';
  lVar1 = *(longlong *)(lVar1 + 0x40);
  KeWaitForSingleObject(lVar1 + 0x68,0,0,0,0);
  PmRemoveIds((longlong)param_1);
  if (((byte)param_1[0x210] & 1) != 0) goto LAB_140005b89;
  if (*(int *)param_2 == 0) {
    iVar3 = PmCheckIdsMbr(param_1,param_2,param_3,param_4);
LAB_140005b53:
    if (iVar3 < 0) goto LAB_140005b89;
  }
  else {
    iVar3 = 0;
    if (*(int *)param_2 == 1) {
      iVar3 = PmCheckIdsGpt(param_1,param_2,param_3,param_4);
      goto LAB_140005b53;
    }
  }
  if (*param_4 == 4) {
    uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x70);
    *(uint *)(param_1 + 0x200) = *(uint *)(param_1 + 0x200) | 0x4000;
    KeReleaseSpinLock(param_1 + 0x70,uVar2);
  }
LAB_140005b89:
  KeReleaseMutex(lVar1 + 0x68,0);
  return iVar3;
}



===== PmRemoveIds @ 140005bc0 =====

undefined8 PmRemoveIds(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong lVar4;
  code *pcVar5;
  undefined1 uVar6;
  
  lVar2 = *(longlong *)(PmControlObject + 0x40);
  uVar6 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x70);
  *(uint *)(param_1 + 0x200) = *(uint *)(param_1 + 0x200) & 0xffffbfff;
  KeReleaseSpinLock(param_1 + 0x70,uVar6);
  plVar1 = (longlong *)(param_1 + 0x268);
  plVar3 = (longlong *)*plVar1;
  if (plVar3 != plVar1) {
    if (((longlong *)plVar3[1] != plVar1) ||
       (lVar4 = *plVar3, (longlong *)*(longlong *)(lVar4 + 8) != plVar3)) goto LAB_140005c79;
    *plVar1 = lVar4;
    *(longlong **)(lVar4 + 8) = plVar1;
    RtlDeleteElementGenericTableAvl(lVar2 + 200);
  }
  plVar1 = (longlong *)(param_1 + 0x278);
  while( true ) {
    plVar3 = (longlong *)*plVar1;
    if (plVar3 == plVar1) {
      return 0;
    }
    if (((longlong *)plVar3[1] != plVar1) ||
       (lVar4 = *plVar3, (longlong *)*(longlong *)(lVar4 + 8) != plVar3)) break;
    *plVar1 = lVar4;
    *(longlong **)(lVar4 + 8) = plVar1;
    RtlDeleteElementGenericTableAvl(lVar2 + 0x130);
  }
LAB_140005c79:
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)(3);
  return 0;
}



===== PmQueryBusRelations @ 140005c9c =====

/* long __cdecl PmQueryBusRelations(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl PmQueryBusRelations(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  longlong lVar1;
  uint *puVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  ulonglong uVar6;
  uint uVar7;
  ulonglong uVar8;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  uVar6 = 0;
  uVar5 = 0;
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x70);
  if ((*(uint *)(lVar1 + 0x200) & 2) == 0) {
    *(uint *)(lVar1 + 0x200) = *(uint *)(lVar1 + 0x200) | 0x402;
  }
  iVar4 = PmQueueNotificationWorkItem(lVar1);
  KeReleaseSpinLock(lVar1 + 0x70,uVar3);
  if (-1 < iVar4) {
    KeWaitForSingleObject(lVar1 + 0x338,0,0,0,0);
    IoForwardIrpSynchronously(*(undefined8 *)(lVar1 + 0x10),param_2);
    iVar4 = *(int *)(param_2 + 0x30);
    if ((-1 < iVar4) && (puVar2 = *(uint **)(param_2 + 0x38), puVar2 != (uint *)0x0)) {
      uVar8 = 0;
      if (*puVar2 != 0) {
        do {
          if (*(int *)(*(longlong *)(puVar2 + uVar8 * 2 + 2) + 0x48) == 0x46) {
            *(longlong *)(puVar2 + uVar6 * 2 + 2) = *(longlong *)(puVar2 + uVar8 * 2 + 2);
            uVar6 = (ulonglong)((int)uVar6 + 1);
          }
          else {
            ObfDereferenceObject();
          }
          uVar5 = (uint)uVar6;
          uVar7 = (int)uVar8 + 1;
          uVar8 = (ulonglong)uVar7;
        } while (uVar7 < *puVar2);
      }
      *puVar2 = uVar5;
    }
  }
  *(int *)(param_2 + 0x30) = iVar4;
  IofCompleteRequest(param_2,0);
  return iVar4;
}



===== PmCountList @ 140005da0 =====

/* unsigned long __cdecl PmCountList(struct _LIST_ENTRY * __ptr64) */

ulong __cdecl PmCountList(_LIST_ENTRY *param_1)

{
  ulong uVar1;
  _LIST_ENTRY *p_Var2;
  
  uVar1 = 0;
  for (p_Var2 = *(_LIST_ENTRY **)param_1; p_Var2 != param_1; p_Var2 = *(_LIST_ENTRY **)p_Var2) {
    uVar1 = uVar1 + 1;
  }
  return uVar1;
}



===== Validate @ 140005dbc =====

/* public: unsigned char __cdecl MBR_ENTRY::Validate(unsigned long,unsigned __int64) __ptr64 */

uchar __thiscall MBR_ENTRY::Validate(MBR_ENTRY *this,ulong param_1,__uint64 param_2)

{
  MBR_ENTRY MVar1;
  bool bVar2;
  ulonglong uVar3;
  
  MVar1 = this[4];
  bVar2 = true;
  uVar3 = (ulonglong)(*(int *)(this + 8) + param_1);
  if ((((MVar1 != (MBR_ENTRY)0x0) && (MVar1 != (MBR_ENTRY)0xee)) &&
      (((bVar2 = false, MVar1 != (MBR_ENTRY)0x5 && (MVar1 != (MBR_ENTRY)0xf)) ||
       (*(int *)(this + 8) != 0)))) && (uVar3 < param_2)) {
    bVar2 = (ulonglong)*(uint *)(this + 0xc) <= (param_2 * 3 >> 1) - uVar3;
  }
  return bVar2;
}



===== Initialize @ 140005e20 =====

/* public: void __cdecl SC_MBR::Initialize(class SC_DISK * __ptr64) __ptr64 */

void __thiscall SC_MBR::Initialize(SC_MBR *this,SC_DISK *param_1)

{
  *(SC_DISK **)this = param_1;
  if ((*(longlong *)(param_1 + 0xd8) == 0) || (0x400 < *(longlong *)(param_1 + 0xd8))) {
    *(undefined8 *)(param_1 + 0xd8) = 0x400;
  }
  if (0xfe < *(int *)(*(longlong *)this + 0xe4) - 1U) {
    *(undefined4 *)(*(longlong *)this + 0xe4) = 0xff;
  }
  if (*(int *)(*(longlong *)this + 0xe8) - 1U < 0x3f) {
    return;
  }
  *(undefined4 *)(*(longlong *)this + 0xe8) = 0x3f;
  return;
}



===== CheckSum @ 140005e88 =====

/* public: unsigned long __cdecl MBR_HEADER::CheckSum(void) __ptr64 */

ulong __thiscall MBR_HEADER::CheckSum(MBR_HEADER *this)

{
  int iVar1;
  MBR_HEADER *pMVar2;
  MBR_HEADER *pMVar3;
  MBR_HEADER *pMVar4;
  longlong lVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar6 = 0;
  iVar7 = 0;
  iVar8 = 0;
  iVar9 = 0;
  lVar5 = 0x20;
  do {
    iVar1 = *(int *)this;
    pMVar2 = this + 4;
    pMVar3 = this + 8;
    pMVar4 = this + 0xc;
    this = this + 0x10;
    iVar6 = iVar1 + iVar6;
    iVar7 = *(int *)pMVar2 + iVar7;
    iVar8 = *(int *)pMVar3 + iVar8;
    iVar9 = *(int *)pMVar4 + iVar9;
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  return -(iVar6 + iVar8 + iVar7 + iVar9);
}



===== ReadSectors @ 140005ecc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl SC_DISK::ReadSectors(unsigned long,unsigned __int64,void * __ptr64) __ptr64
    */

long __thiscall SC_DISK::ReadSectors(SC_DISK *this,ulong param_1,__uint64 param_2,void *param_3)

{
  long lVar1;
  
  if (param_3 == (void *)0x0) {
    param_3 = *(void **)(this + 0x108);
  }
  lVar1 = (**(code **)(*(longlong *)this + 0x38))
                    (this,param_2 << ((byte)*(undefined4 *)(this + 0xf0) & 0x3f),
                     param_1 << ((byte)*(undefined4 *)(this + 0xf0) & 0x1f),param_3);
  return lVar1;
}



===== SaveStorageProperty @ 140005f10 =====

/* protected: virtual void __cdecl SC_DISK::SaveStorageProperty(enum _STORAGE_PROPERTY_ID,struct
   _STORAGE_DESCRIPTOR_HEADER * __ptr64) __ptr64 */

void __thiscall
SC_DISK::SaveStorageProperty
          (SC_DISK *this,_STORAGE_PROPERTY_ID param_1,_STORAGE_DESCRIPTOR_HEADER *param_2)

{
  SC_DISK *pSVar1;
  longlong lVar2;
  
  if ((int)param_1 < 0xf) {
    if (param_1 == 0xe) {
      lVar2 = 0x160;
    }
    else if (param_1 == 4) {
      lVar2 = 0x148;
    }
    else if (param_1 == 6) {
      lVar2 = 0x138;
    }
    else if (param_1 == 7) {
      lVar2 = 0x168;
    }
    else if (param_1 == 8) {
      lVar2 = 0x178;
    }
    else {
      if (param_1 != 0xb) goto LAB_140005f88;
      lVar2 = 0x170;
    }
  }
  else if (param_1 == 0x39) {
    lVar2 = 0x140;
  }
  else if (param_1 == 0x3a) {
    lVar2 = 0x158;
  }
  else {
    if (param_1 != 0x3c) {
      if (param_1 == 0x41) {
        ExFreePoolWithTag(param_2,0);
        return;
      }
LAB_140005f88:
      SC_DEVICE::SaveStorageProperty((SC_DEVICE *)this,param_1,param_2);
      return;
    }
    lVar2 = 0x180;
  }
  pSVar1 = this + lVar2;
  if (pSVar1 != (SC_DISK *)0x0) {
    if (*(longlong *)pSVar1 != 0) {
      ExFreePoolWithTag(*(longlong *)pSVar1,0);
    }
    *(_STORAGE_DESCRIPTOR_HEADER **)pSVar1 = param_2;
  }
  return;
}



===== PmGetPartitionAttributesMbr @ 140005fec =====

long PmGetPartitionAttributesMbr(_DEVICE_EXTENSION *param_1,longlong *param_2)

{
  _DEVICE_EXTENSION *p_Var1;
  undefined1 uVar2;
  long lVar3;
  longlong lVar4;
  _PARTITION_ATTRIBUTES_TABLE *p_Var5;
  ulong local_res8 [2];
  _PARTITION_ATTRIBUTES_TABLE *local_res10;
  
  local_res8[0] = 0;
  p_Var1 = param_1 + 0x70;
  lVar3 = 0;
  *param_2 = 0;
  uVar2 = KeAcquireSpinLockRaiseToDpc(p_Var1);
  p_Var5 = *(_PARTITION_ATTRIBUTES_TABLE **)(param_1 + 0x468);
  *(undefined8 *)(param_1 + 0x468) = 0;
  local_res10 = p_Var5;
  KeReleaseSpinLock(p_Var1,uVar2);
  if (p_Var5 == (_PARTITION_ATTRIBUTES_TABLE *)0x0) {
    lVar3 = PmReadPartitionAttributesMbr(param_1,&local_res10,local_res8);
    p_Var5 = local_res10;
    if (lVar3 < 0) goto LAB_1400060ee;
    lVar4 = *(longlong *)local_res10 + -0x4433b9e5ebd0a0a2;
    if (lVar4 == 0) {
      lVar4 = *(longlong *)(local_res10 + 8) + 0x3866d94849973f79;
    }
    if (lVar4 != 0) {
      memset(local_res10,0,(ulonglong)local_res8[0]);
      *(longlong *)p_Var5 = 0x4433b9e5ebd0a0a2;
      *(longlong *)(p_Var5 + 8) = -0x3866d94849973f79;
      *(longlong *)(p_Var5 + 0x10) = 0;
    }
    PmSetDeviceParameterBinary(param_1,L"AttributesTableCache",p_Var5,0x18);
  }
  *param_2 = *(longlong *)(p_Var5 + 0x10);
  uVar2 = KeAcquireSpinLockRaiseToDpc(p_Var1);
  *(_PARTITION_ATTRIBUTES_TABLE **)(param_1 + 0x468) = p_Var5;
  p_Var5 = (_PARTITION_ATTRIBUTES_TABLE *)0x0;
  KeReleaseSpinLock(p_Var1,uVar2);
LAB_1400060ee:
  if (p_Var5 != (_PARTITION_ATTRIBUTES_TABLE *)0x0) {
    ExFreePoolWithTag(p_Var5,0);
  }
  return lVar3;
}



===== Free @ 140006120 =====

/* public: static void __cdecl SC_ENV::Free(void * __ptr64,unsigned long) */

void __cdecl SC_ENV::Free(void *param_1,ulong param_2)

{
  ExFreePoolWithTag(param_1,0);
  return;
}



===== IsContainer @ 140006140 =====

/* public: unsigned char __cdecl SC_PART_ENTRY::IsContainer(void) __ptr64 */

uchar __thiscall SC_PART_ENTRY::IsContainer(SC_PART_ENTRY *this)

{
  if ((*(int *)this == 0) &&
     ((this[0x20] == (SC_PART_ENTRY)0x5 || (this[0x20] == (SC_PART_ENTRY)0xf)))) {
    return '\x01';
  }
  return '\0';
}



===== PmQueryPnpDeviceState @ 140006160 =====

/* long __cdecl PmQueryPnpDeviceState(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl PmQueryPnpDeviceState(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  longlong lVar1;
  long lVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if ((((*(char *)(lVar1 + 0x25c) != '\0') || (*(int *)(lVar1 + 0x250) != 0)) ||
      (*(int *)(lVar1 + 0x254) != 0)) || (*(int *)(lVar1 + 600) != 0)) {
    *(ulonglong *)(param_2 + 0x38) = *(ulonglong *)(param_2 + 0x38) | 0x20;
    *(undefined4 *)(param_2 + 0x30) = 0;
  }
  KeWaitForSingleObject(lVar1 + 0x38,0,0,0,0);
  if (*(char *)(lVar1 + 0x20c) != '\0') {
    *(ulonglong *)(param_2 + 0x38) = *(ulonglong *)(param_2 + 0x38) | 2;
    *(undefined4 *)(param_2 + 0x30) = 0;
  }
  KeReleaseMutex(lVar1 + 0x38,0);
  param_2[0x43] = (_IRP)((char)param_2[0x43] + '\x01');
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  lVar2 = IofCallDriver(*(undefined8 *)(lVar1 + 0x10),param_2);
  return lVar2;
}



===== GetEntry @ 14000621c =====

/* public: class SC_PART_ENTRY * __ptr64 __cdecl SC_DISK_LAYOUT::GetEntry(unsigned long) __ptr64 */

SC_PART_ENTRY * __thiscall SC_DISK_LAYOUT::GetEntry(SC_DISK_LAYOUT *this,ulong param_1)

{
  return (SC_PART_ENTRY *)(this + (ulonglong)param_1 * 0x90 + 0x30);
}



===== GenerateId @ 140006238 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: long __cdecl SC_DISK::GenerateId(void) __ptr64 */

long __thiscall SC_DISK::GenerateId(SC_DISK *this)

{
  int iVar1;
  undefined1 auStack_78 [32];
  undefined8 *local_58;
  undefined4 local_50;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_78;
  local_50 = 0x28;
  local_18 = 0;
  uStack_14 = 0;
  local_58 = &local_38;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  iVar1 = (**(code **)(*(longlong *)this + 0x10))(this,0x2d1084,0,0);
  if (iVar1 < 0) {
    iVar1 = SC_ENV::CreateGuid((_GUID *)(this + 0x110));
  }
  else {
    *(ulonglong *)(this + 0x110) = CONCAT44(uStack_20,uStack_24);
    *(ulonglong *)(this + 0x118) = CONCAT44(local_18,uStack_1c);
  }
  return iVar1;
}



===== ReadPartitionTable @ 1400062c8 =====

/* public: long __cdecl SC_RAW::ReadPartitionTable(class SC_DISK_LAYOUT * __ptr64 * __ptr64) __ptr64
    */

long __thiscall SC_RAW::ReadPartitionTable(SC_RAW *this,SC_DISK_LAYOUT **param_1)

{
  MBR_HEADER *this_00;
  ulong uVar1;
  SC_DISK_LAYOUT *_Dst;
  longlong lVar2;
  long lVar3;
  SC_DISK_LAYOUT SVar4;
  
  lVar2 = *(longlong *)this;
  lVar3 = 0;
  *param_1 = (SC_DISK_LAYOUT *)0x0;
  this_00 = *(MBR_HEADER **)(lVar2 + 0x108);
  _Dst = (SC_DISK_LAYOUT *)ExAllocatePool2(0x40,0xc0,0x6d506353);
  if (_Dst == (SC_DISK_LAYOUT *)0x0) {
    lVar3 = -0x3fffff66;
  }
  else {
    memset(_Dst,0,0xc0);
    lVar2 = *(longlong *)this;
    if ((*(int *)(lVar2 + 0xe0) == 0xb) || (*(short *)(this_00 + 0x1fe) == -0x55ab)) {
      SVar4 = (SC_DISK_LAYOUT)0x1;
      *(undefined4 *)(_Dst + 4) = 1;
      *(undefined4 *)(_Dst + 8) = 1;
      uVar1 = MBR_HEADER::CheckSum(this_00);
      *(ulong *)(_Dst + 0xc) = uVar1;
      *(undefined8 *)(_Dst + 0x38) = 0;
      *(longlong *)(_Dst + 0x40) =
           *(longlong *)(lVar2 + 0xf8) << ((byte)*(undefined4 *)(lVar2 + 0xf0) & 0x3f);
      *(undefined4 *)(_Dst + 0x48) = 0;
      *(undefined2 *)(_Dst + 0x50) = 4;
      _Dst[0x52] = SVar4;
      *(undefined4 *)(_Dst + 0x54) = 0;
      *(undefined4 *)(_Dst + 0x58) = *(undefined4 *)(_Dst + 8);
      *(undefined4 *)(_Dst + 0x5c) = 0;
      *(undefined8 *)(_Dst + 0x60) = 0;
    }
    else {
      uVar1 = MBR_HEADER::CheckSum(this_00);
      *(ulong *)(_Dst + 0xc) = uVar1;
    }
    *param_1 = _Dst;
  }
  return lVar3;
}



===== PartitionIo @ 1400063d0 =====

/* long __cdecl PartitionIo(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl PartitionIo(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  byte *pbVar1;
  _IRP *p_Var2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined8 *puVar6;
  longlong lVar7;
  code *pcVar8;
  char cVar9;
  int iVar10;
  long lVar11;
  undefined1 *puVar12;
  uint uVar13;
  ulonglong uVar14;
  _IRP *p_Var15;
  undefined1 auStackY_88 [8];
  undefined1 auStackY_80 [24];
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  longlong local_40;
  _IRP *p_Stack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  lVar4 = *(longlong *)(param_2 + 0xb8);
  p_Var2 = param_2 + 0xa8;
  local_40 = 0;
  p_Stack_38 = (_IRP *)0x0;
  uVar14 = 0;
  local_30 = 0;
  uStack_28 = 0;
  iVar10 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  cVar9 = ExAcquireRundownProtectionCacheAware(*(undefined8 *)(lVar3 + 400));
  if (cVar9 == '\0') {
    KeAcquireInStackQueuedSpinLock(lVar3 + 0x1c0,&local_58);
    cVar9 = ExAcquireRundownProtectionCacheAware(*(undefined8 *)(lVar3 + 400));
    if (cVar9 == '\0') {
      pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
      *pbVar1 = *pbVar1 | 1;
      plVar5 = *(longlong **)(lVar3 + 0x1b8);
      if (*plVar5 != lVar3 + 0x1b0) {
LAB_14000667d:
        pcVar8 = (code *)swi(0x29);
        (*pcVar8)(3);
        puVar12 = auStackY_80;
        goto LAB_140006684;
      }
      *(longlong *)p_Var2 = lVar3 + 0x1b0;
      *(longlong **)(param_2 + 0xb0) = plVar5;
      iVar10 = 0x103;
      *plVar5 = (longlong)p_Var2;
      *(_IRP **)(lVar3 + 0x1b8) = p_Var2;
    }
    KeReleaseInStackQueuedSpinLock(&local_58);
    if (iVar10 != 0) {
      return iVar10;
    }
  }
  p_Var15 = param_2 + 0xb8;
  *(_IRP **)(param_2 + 0xb0) = p_Var2;
  *(_IRP **)p_Var2 = p_Var2;
  puVar6 = *(undefined8 **)p_Var15;
  puVar6[-9] = *puVar6;
  puVar6[-8] = puVar6[1];
  puVar6[-7] = puVar6[2];
  puVar6[-6] = puVar6[3];
  *(undefined4 *)(puVar6 + -5) = *(undefined4 *)(puVar6 + 4);
  *(undefined4 *)((longlong)puVar6 + -0x24) = *(undefined4 *)((longlong)puVar6 + 0x24);
  *(undefined4 *)(puVar6 + -4) = *(undefined4 *)(puVar6 + 5);
  *(undefined4 *)((longlong)puVar6 + -0x1c) = *(undefined4 *)((longlong)puVar6 + 0x2c);
  puVar6[-3] = puVar6[6];
  *(undefined1 *)((longlong)puVar6 + -0x45) = 0;
  lVar7 = *(longlong *)p_Var15;
  *(code **)(lVar7 + -0x10) = PartitionIoCompletion;
  *(undefined8 *)(lVar7 + -8) = 0;
  *(undefined1 *)(lVar7 + -0x45) = 0xe0;
  if ((char)*(undefined4 *)(lVar3 + 0x28) < '\0') {
    iVar10 = -0x3ffffff2;
  }
  else {
    local_40 = lVar3;
    p_Stack_38 = param_2;
    iVar10 = PmEnumerateOverlaps((undefined8 *)(lVar3 + 0x138),*(ulonglong *)(lVar4 + 0x18),
                                 (ulonglong)*(uint *)(lVar4 + 8),PartitionOverlapCount,&local_40);
    if (-1 < iVar10) {
      if ((uint)local_30 == 1) {
        *(undefined8 *)(*(longlong *)p_Var15 + -0x30) = uStack_28;
        lVar11 = IofCallDriver(*(undefined8 *)(lVar3 + 0x10),param_2);
        return lVar11;
      }
      iVar10 = PmEnumerateOverlaps((undefined8 *)(lVar3 + 0x138),*(ulonglong *)(lVar4 + 0x18),
                                   (ulonglong)*(uint *)(lVar4 + 8),PartitionOverlapIo,&local_40);
      if (-1 < iVar10) {
        lVar4 = *(longlong *)(param_2 + 0xb8);
        param_2[0x43] = (_IRP)((char)param_2[0x43] + -1);
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0;
        *(longlong *)(param_2 + 0xb8) = lVar4 + -0x48;
        pbVar1 = (byte *)(lVar4 + -0x45);
        *pbVar1 = *pbVar1 | 1;
        *(longlong *)(param_2 + 0x78) = (longlong)(int)(uint)local_30;
        if ((uint)local_30 != 0) {
          param_2 = param_2 + 0xa8;
          do {
            plVar5 = *(longlong **)param_2;
            if (((_IRP *)plVar5[1] != param_2) ||
               (lVar4 = *plVar5, *(longlong **)(lVar4 + 8) != plVar5)) goto LAB_14000667d;
            *(longlong *)param_2 = lVar4;
            *(_IRP **)(lVar4 + 8) = param_2;
            plVar5[1] = (longlong)plVar5;
            *plVar5 = (longlong)plVar5;
            IofCallDriver(*(undefined8 *)(lVar3 + 0x10),plVar5 + -0x15);
            uVar13 = (int)uVar14 + 1;
            uVar14 = (ulonglong)uVar13;
          } while (uVar13 < (uint)local_30);
        }
        return 0x103;
      }
    }
  }
  p_Var2 = param_2 + 0xa8;
  while( true ) {
    puVar12 = auStackY_88;
    p_Var15 = *(_IRP **)p_Var2;
    if (p_Var15 == p_Var2) break;
    if ((*(_IRP **)(p_Var15 + 8) != p_Var2) ||
       (lVar3 = *(longlong *)p_Var15, *(_IRP **)(lVar3 + 8) != p_Var15)) goto LAB_14000667d;
    *(longlong *)p_Var2 = lVar3;
    *(_IRP **)(lVar3 + 8) = p_Var2;
    if (*(longlong *)(p_Var15 + -0xa0) != 0) {
      IoFreeMdl();
    }
    IoFreeIrp(p_Var15 + -0xa8);
  }
LAB_140006684:
  param_2[0x43] = (_IRP)((char)param_2[0x43] + -1);
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + -0x48;
  *(ulonglong *)(param_2 + 0x38) = uVar14;
  *(int *)(param_2 + 0x30) = iVar10;
  *(undefined8 *)(puVar12 + -8) = 0x1400066a3;
  IofCompleteRequest(param_2,0);
  return iVar10;
}



===== PartitionIoCompletion @ 1400066e0 =====

/* long __cdecl PartitionIoCompletion(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64,void *
   __ptr64) */

long __cdecl PartitionIoCompletion(_DEVICE_OBJECT *param_1,_IRP *param_2,void *param_3)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (param_2[0x41] != (_IRP)0x0) {
    *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) = *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) | 1;
  }
  if ((*(int *)(param_2 + 0x30) < 0) && ((char)*(undefined4 *)(lVar1 + 0x28) < '\0')) {
    *(undefined4 *)(param_2 + 0x30) = 0xc000000e;
    *(undefined8 *)(param_2 + 0x38) = 0;
  }
  ExReleaseRundownProtectionCacheAware(*(undefined8 *)(lVar1 + 400));
  return 0;
}



===== PartitionWrite @ 140006740 =====

/* long __cdecl PartitionWrite(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl PartitionWrite(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  long lVar1;
  
  if ((*(uint *)(*(longlong *)(param_1 + 0x40) + 0x28) & 8) == 0) {
    lVar1 = PartitionIo(param_1,param_2);
    return lVar1;
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0xc000000e;
  IofCompleteRequest(param_2,0);
  return -0x3ffffff2;
}



===== PmDeviceUsageNotification @ 140006790 =====

/* long __cdecl PmDeviceUsageNotification(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl PmDeviceUsageNotification(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 uVar3;
  int iVar4;
  ulonglong uVar5;
  int *piVar6;
  int iVar7;
  bool bVar8;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar2 = *(longlong *)(param_2 + 0xb8);
  bVar8 = false;
  IoForwardIrpSynchronously(*(undefined8 *)(lVar1 + 0x10));
  iVar7 = *(int *)(param_2 + 0x30);
  if (iVar7 < 0) goto LAB_140006935;
  KeWaitForSingleObject(lVar1 + 0x38,0,0,0,0);
  if (((*(longlong *)(lVar1 + 0x220) == 0x4354eeb5026061e9) &&
      (*(longlong *)(lVar1 + 0x228) == -0x502d88342de82841)) && (*(char *)(lVar2 + 8) != '\0')) {
    iVar7 = -0x3fffff45;
  }
  uVar5 = Feature_Partition_Manager_Passthrough__private_IsEnabledDeviceUsageNoInline();
  if ((((int)uVar5 != 0) && (*(char *)(lVar2 + 8) != '\0')) &&
     ((*(byte *)(lVar1 + 0x210) & 0x40) != 0)) {
    iVar7 = -0x3fffff45;
  }
  KeReleaseMutex(lVar1 + 0x38,0);
  if (iVar7 < 0) goto LAB_140006935;
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x70);
  iVar4 = *(int *)(lVar2 + 0x10);
  if (iVar4 == 1) {
    piVar6 = (int *)(lVar1 + 0x250);
LAB_1400068c4:
    if (piVar6 != (int *)0x0) {
      iVar4 = *(int *)(lVar1 + 600) + *(int *)(lVar1 + 0x254) + *(int *)(lVar1 + 0x250);
      if (*(char *)(lVar2 + 8) == '\0') {
        bVar8 = iVar4 == 1;
        if (bVar8) {
          *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x2000;
        }
        LOCK();
        *piVar6 = *piVar6 + -1;
        UNLOCK();
      }
      else {
        bVar8 = iVar4 == 0;
        if (bVar8) {
          *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) & 0xffffdfff;
        }
        LOCK();
        *piVar6 = *piVar6 + 1;
        UNLOCK();
      }
    }
  }
  else {
    if (iVar4 == 2) {
      piVar6 = (int *)(lVar1 + 0x254);
      goto LAB_1400068c4;
    }
    if (iVar4 == 3) {
      piVar6 = (int *)(lVar1 + 600);
      goto LAB_1400068c4;
    }
    if ((iVar4 == 4) && (*(char *)(lVar2 + 8) != '\0')) {
      *(undefined1 *)(lVar1 + 0x25c) = 1;
      *(uint *)(*(longlong *)(lVar1 + 8) + 0x30) =
           *(uint *)(*(longlong *)(lVar1 + 8) + 0x30) | 0x400000;
    }
  }
  KeReleaseSpinLock(lVar1 + 0x70,uVar3);
  if (bVar8) {
    IoInvalidateDeviceState(*(undefined8 *)(lVar1 + 0x18));
  }
LAB_140006935:
  *(int *)(param_2 + 0x30) = iVar7;
  IofCompleteRequest(param_2,0);
  return iVar7;
}



===== PmFilterDeviceControl @ 140006980 =====

/* long __cdecl PmFilterDeviceControl(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl PmFilterDeviceControl(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 uVar4;
  int iVar5;
  uint uVar6;
  undefined8 uVar7;
  longlong lVar8;
  ulonglong uVar9;
  bool bVar10;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  lVar3 = *(longlong *)(param_2 + 0xb8);
  uVar6 = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  iVar5 = IoAcquireRemoveLockEx(lVar2 + 0x78,param_2,"",1,0x20);
  if (iVar5 < 0) {
    *(int *)(param_2 + 0x30) = iVar5;
    IofCompleteRequest(param_2,0);
    return iVar5;
  }
  uVar1 = *(uint *)(lVar3 + 0x18);
  if (uVar1 < 0x7421d) {
    if (uVar1 == 0x7421c) {
      uVar6 = PmIoctlAreVolumesReady((longlong)param_1,(longlong)param_2);
      goto LAB_140006f9b;
    }
    if (uVar1 < 0x700f9) {
      if (uVar1 == 0x700f8) {
        lVar3 = *(longlong *)(param_1 + 0x40);
        if (*(int *)(*(longlong *)(param_2 + 0xb8) + 8) == 0) {
          uVar6 = 0xc0000023;
        }
        else {
          uVar7 = *(undefined8 *)(param_2 + 0x18);
          KeWaitForSingleObject(lVar3 + 0x38,0,0,0,0);
          lVar8 = *(longlong *)(lVar3 + 0x220) + -0x4354eeb5026061e9;
          if (lVar8 == 0) {
            lVar8 = *(longlong *)(lVar3 + 0x228) + 0x502d88342de82841;
          }
          *(bool *)uVar7 = lVar8 == 0;
          KeReleaseMutex(lVar3 + 0x38,0);
          *(undefined8 *)(param_2 + 0x38) = 1;
        }
      }
      else if (uVar1 == 0x70020) {
        uVar9 = PmIoctlPerformance((longlong)param_1,(longlong)param_2);
        uVar6 = (uint)uVar9;
      }
      else if (uVar1 == 0x70024) {
        uVar6 = PmIoctlIsWritable((longlong)param_1,(longlong)param_2);
      }
      else if (uVar1 == 0x70060) {
        uVar7 = PmIoctlPerformanceOff((longlong)param_1);
        uVar6 = (uint)uVar7;
      }
      else {
        if (uVar1 != 0x700f0) goto LAB_140006ca0;
        uVar7 = PmIoctlGetDiskAttributes((longlong)param_1,(longlong)param_2);
        uVar6 = (uint)uVar7;
      }
    }
    else if (uVar1 == 0x70214) {
      uVar7 = PmIoctlGetClusterInfo((longlong)param_1,(longlong)param_2);
      uVar6 = (uint)uVar7;
    }
    else if (uVar1 == 0x70224) {
      uVar9 = PmIoctlGetPerformanceInfo((longlong)param_1,(longlong)param_2);
      uVar6 = (uint)uVar9;
    }
    else {
      if (uVar1 != 0x74004) goto LAB_140006ca0;
      uVar6 = PmIoctlGetPartitionInfo((longlong)param_1,(longlong)param_2);
    }
  }
  else if (uVar1 < 0x700011) {
    if (uVar1 == 0x700010) {
      uVar7 = PmIoctlQueryDeviceState((longlong)param_1,(longlong)param_2);
      uVar6 = (uint)uVar7;
    }
    else if (uVar1 == 0x7c064) {
      uVar6 = 0xc0000010;
    }
    else if (uVar1 == 0x7c0f4) {
      PmEtwControlStart(lVar2,(longlong)param_2);
      uVar6 = PmIoctlSetDiskAttributes((longlong)param_1,(longlong)param_2);
LAB_140006c52:
      PmEtwControlComplete(lVar2,(longlong)param_2,(char)uVar6);
    }
    else {
      if (uVar1 == 0x2d1400) {
        uVar9 = PmIoctlQueryProperty((longlong)param_1,(longlong)param_2);
        uVar6 = (uint)uVar9;
        goto LAB_140006f9b;
      }
      if (uVar1 != 0x560030) goto LAB_140006ca0;
      lVar3 = *(longlong *)(param_1 + 0x40);
      KeWaitForSingleObject(lVar3 + 0x38,0,0,0,0);
      if ((*(longlong *)(lVar3 + 0x220) == 0x4354eeb5026061e9) &&
         (*(longlong *)(lVar3 + 0x228) == -0x502d88342de82841)) {
        uVar4 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x70);
        uVar6 = *(uint *)(lVar3 + 0x200);
        KeReleaseSpinLock(lVar3 + 0x70,uVar4);
        uVar6 = -(uint)((uVar6 & 8) != 0) & 0xc0000001;
      }
      else {
        uVar6 = 0xc0000001;
      }
      KeReleaseMutex(lVar3 + 0x38,0);
    }
  }
  else if (uVar1 == 0x700014) {
    uVar7 = PmIoctlGetReliabilityInfo((longlong)param_1,(longlong)param_2);
    uVar6 = (uint)uVar7;
  }
  else if (uVar1 == 0x70c018) {
    uVar7 = PmIoctlResetReliabilityInfo((longlong)param_1);
    uVar6 = (uint)uVar7;
  }
  else if (uVar1 == 0x70c030) {
    uVar6 = 0xc00000bb;
  }
  else {
LAB_140006ca0:
    uVar6 = *(uint *)(lVar3 + 0x18);
    if ((*(byte *)(lVar2 + 0x210) & 0x40) == 0) {
      if (uVar6 < 0x7c055) {
        if (uVar6 == 0x7c054) {
          uVar6 = PmIoctlSetDriveLayoutEx((longlong)param_1,(longlong)param_2);
        }
        else if (uVar6 < 0x70049) {
          if (uVar6 != 0x70048) {
            switch(uVar6) {
            case 0x4d004:
            case 0x4d014:
            case 0x4d02c:
            case 0x4d030:
            case 0x4d044:
            case 0x4d048:
              uVar9 = PmIoctlRedirect((longlong)param_1,(longlong)param_2);
              uVar6 = (uint)uVar9;
              goto LAB_140006f9b;
            }
switchD_140006d8e_caseD_4d005:
            param_2[0x43] = (_IRP)((char)param_2[0x43] + '\x01');
            *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
            uVar6 = IofCallDriver(*(undefined8 *)(lVar2 + 0x10),param_2);
            goto LAB_140006f9b;
          }
          uVar6 = PmIoctlGetPartitionInfoEx((longlong)param_1,(longlong)param_2);
        }
        else if (uVar6 < 0x7400d) {
          if (uVar6 == 0x7400c) {
            uVar6 = PmIoctlGetDriveLayout((longlong)param_1,(longlong)param_2);
          }
          else if (uVar6 == 0x70050) {
            uVar6 = PmIoctlGetDriveLayoutEx((longlong)param_1,(longlong)param_2);
          }
          else if (uVar6 == 0x700a0) {
            uVar6 = PmIoctlGetDriveGeometryEx((longlong)param_1,(longlong)param_2);
          }
          else {
            if (uVar6 != 0x70140) goto switchD_140006d8e_caseD_4d005;
            uVar7 = PmIoctlUpdateProperties((longlong)param_1);
            uVar6 = (uint)uVar7;
          }
        }
        else if (uVar6 == 0x74208) {
          uVar6 = PmIoctlGetSnapshotInfo((longlong)param_1,(longlong)param_2);
        }
        else {
          if (uVar6 != 0x7c010) goto switchD_140006d8e_caseD_4d005;
          uVar6 = PmIoctlSetDriveLayout((longlong)param_1,(longlong)param_2);
        }
      }
      else if (uVar6 < 0x7c219) {
        if (uVar6 == 0x7c218) {
          PmEtwControlStart(lVar2,(longlong)param_2);
          uVar7 = PmIoctlSetClusterInfo((longlong)param_1,(longlong)param_2);
          uVar6 = (uint)uVar7;
          goto LAB_140006c52;
        }
        if (uVar6 < 0x7c101) {
          if (uVar6 == 0x7c100) {
            uVar6 = PmIoctlDeleteDriveLayout((longlong)param_1);
          }
          else if (uVar6 == 0x7c058) {
            uVar6 = PmIoctlCreateDisk((longlong)param_1,(longlong)param_2);
          }
          else if (uVar6 == 0x7c0c8) {
            uVar6 = PmIoctlUpdateDriveSize((longlong)param_1,(longlong)param_2);
          }
          else {
            if (uVar6 != 0x7c0d0) goto switchD_140006d8e_caseD_4d005;
            uVar6 = PmIoctlGrowPartition((longlong)param_1,(longlong)param_2);
          }
        }
        else if (uVar6 == 0x7c20c) {
          uVar6 = PmIoctlSetSnapshotInfo((longlong)param_1,(longlong)param_2);
        }
        else {
          if (uVar6 != 0x7c210) goto switchD_140006d8e_caseD_4d005;
          uVar6 = PmIoctlResetSnapshotInfo((longlong)param_1);
        }
      }
      else {
        if (uVar6 == 0x2d9404) {
          uVar9 = PmIoctlDsm((longlong)param_1,(longlong)param_2);
          uVar6 = (uint)uVar9;
          goto LAB_140006f9b;
        }
        if (uVar6 == 0x704008) {
          uVar6 = PmIoctlQueryDiskSignature((longlong)param_1,(longlong)param_2);
        }
        else if (uVar6 == 0x70c01c) {
          uVar7 = PmIoctlReauctionDisk((longlong)param_1);
          uVar6 = (uint)uVar7;
        }
        else if (uVar6 == 0x70c020) {
          uVar6 = PmIoctlCreateSpacesMetadata((longlong)param_1,(longlong)param_2);
        }
        else {
          if (uVar6 != 0x70c024) goto switchD_140006d8e_caseD_4d005;
          uVar6 = PmIoctlDeleteSpacesMetadata((longlong)param_1);
        }
      }
    }
    else {
      if (uVar6 < 0x7c0d1) {
        if (uVar6 != 0x7c0d0) {
          if (uVar6 < 0x74209) {
            if ((((uVar6 != 0x74208) && (uVar6 != 0x70048)) && (uVar6 != 0x70050)) &&
               (uVar6 != 0x70140)) {
              bVar10 = uVar6 == 0x7400c;
              goto LAB_140006d20;
            }
          }
          else if (uVar6 != 0x7c010) {
            iVar5 = uVar6 - 0x7c054;
            goto LAB_140006d1b;
          }
        }
      }
      else if (uVar6 < 0x704009) {
        if (((uVar6 != 0x704008) && (uVar6 != 0x7c100)) &&
           ((uVar6 != 0x7c20c && (uVar6 != 0x7c210)))) {
          bVar10 = uVar6 == 0x2d9404;
LAB_140006d20:
          if (!bVar10) goto switchD_140006d8e_caseD_4d005;
        }
      }
      else if (uVar6 != 0x70c01c) {
        iVar5 = uVar6 - 0x70c020;
LAB_140006d1b:
        if (iVar5 != 0) {
          bVar10 = iVar5 == 4;
          goto LAB_140006d20;
        }
      }
      uVar6 = 0xc0000022;
    }
  }
  *(uint *)(param_2 + 0x30) = uVar6;
  IofCompleteRequest(param_2,0);
LAB_140006f9b:
  IoReleaseRemoveLockEx(lVar2 + 0x78,param_2,0x20);
  return uVar6;
}



===== PmPropagateVerify @ 140006fdc =====

/* void __cdecl PmPropagateVerify(struct _DEVICE_EXTENSION * __ptr64) */

void __cdecl PmPropagateVerify(_DEVICE_EXTENSION *param_1)

{
  longlong lVar1;
  undefined1 uVar2;
  longlong lVar3;
  _DEVICE_EXTENSION *p_Var4;
  
  PmInvalidatePartitionTableCache((longlong)param_1);
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x70);
  for (p_Var4 = *(_DEVICE_EXTENSION **)(param_1 + 0x380); p_Var4 != param_1 + 0x380;
      p_Var4 = *(_DEVICE_EXTENSION **)p_Var4) {
    *(uint *)(*(longlong *)(p_Var4 + -0x88) + 0x30) =
         *(uint *)(*(longlong *)(p_Var4 + -0x88) + 0x30) | 2;
  }
  KeReleaseSpinLock(param_1 + 0x70,uVar2);
  lVar3 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 0x10) >> 8),
                                 *(undefined1 *)(*(longlong *)(param_1 + 0x10) + 0x4c)),0);
  if (lVar3 != 0) {
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    *(undefined1 *)(lVar1 + -0x48) = 0xe;
    *(undefined4 *)(lVar1 + -0x40) = 0;
    *(undefined4 *)(lVar1 + -0x38) = 0;
    *(undefined4 *)(lVar1 + -0x30) = 0x70407;
    *(undefined1 *)(lVar3 + 0x40) = 0;
    *(undefined8 *)(lVar3 + 0x18) = 0;
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    *(code **)(lVar1 + -0x10) = PmPropagateVerifyCompletion;
    *(undefined8 *)(lVar1 + -8) = 0;
    *(undefined1 *)(lVar1 + -0x45) = 0xe0;
    IofCallDriver(*(undefined8 *)(param_1 + 0x10),lVar3);
  }
  return;
}



===== PmUpdateLayoutEx @ 1400070c0 =====

/* long __cdecl PmUpdateLayoutEx(struct _DEVICE_EXTENSION * __ptr64,struct
   _DRIVE_LAYOUT_INFORMATION_EX * __ptr64,unsigned char) */

long __cdecl
PmUpdateLayoutEx(_DEVICE_EXTENSION *param_1,_DRIVE_LAYOUT_INFORMATION_EX *param_2,uchar param_3)

{
  char cVar1;
  undefined1 uVar2;
  long lVar3;
  int iVar4;
  
  PmSetLegacyRemovableFlag((longlong)param_1,(int *)param_2,param_3);
  if ((*(uint *)(param_1 + 0x200) >> 0xb & 1) == 0) {
    cVar1 = PmLayoutHasIds((int *)param_2);
    if (cVar1 != '\0') {
      lVar3 = PmUpdateAttributes(param_1,param_2);
      if (lVar3 < 0) {
        return lVar3;
      }
      lVar3 = PmValidateIds(param_1,param_2);
      if (lVar3 < 0) {
        return lVar3;
      }
    }
    iVar4 = PmUpdatePartitions(param_1,param_2);
  }
  else {
    iVar4 = PmUpdatePartitionsLegacyRemovable(param_1,param_2);
  }
  if ((-1 < iVar4) && (iVar4 = PmAssociatePartitions(param_1,param_2), -1 < iVar4)) {
    uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x70);
    PmQueueNotificationWorkItem((longlong)param_1);
    KeReleaseSpinLock(param_1 + 0x70,uVar2);
  }
  return iVar4;
}



===== PmUpdatePartitions @ 14000719c =====

/* long __cdecl PmUpdatePartitions(struct _DEVICE_EXTENSION * __ptr64,struct
   _DRIVE_LAYOUT_INFORMATION_EX * __ptr64) */

long __cdecl PmUpdatePartitions(_DEVICE_EXTENSION *param_1,_DRIVE_LAYOUT_INFORMATION_EX *param_2)

{
  _DEVICE_EXTENSION *p_Var1;
  _DEVICE_EXTENSION *p_Var2;
  undefined8 *puVar3;
  longlong lVar4;
  code *pcVar5;
  uchar uVar6;
  undefined1 uVar7;
  long lVar8;
  SC_PART_ENTRY *pSVar9;
  _DEVICE_EXTENSION *p_Var10;
  _DEVICE_EXTENSION *p_Var11;
  _DEVICE_EXTENSION *p_Var12;
  _PARTITION_EXTENSION *p_Var13;
  _DEVICE_EXTENSION *p_Var14;
  undefined1 *puVar15;
  uint uVar16;
  ulonglong uVar17;
  SC_PART_ENTRY *this;
  _DRIVE_LAYOUT_INFORMATION_EX *in_R8;
  _DRIVE_LAYOUT_INFORMATION_EX *this_00;
  ulong uVar18;
  _PARTITION_EXTENSION *local_res8;
  ulonglong local_res10;
  undefined1 auStackY_58 [8];
  undefined1 auStackY_50 [24];
  
  puVar15 = auStackY_58;
  local_res8 = (_PARTITION_EXTENSION *)0x0;
  p_Var2 = param_1 + 0x380;
  p_Var10 = *(_DEVICE_EXTENSION **)p_Var2;
  local_res10 = 0xfffffffffffffffe;
  for (; p_Var10 != p_Var2; p_Var10 = *(_DEVICE_EXTENSION **)p_Var10) {
    if ((*(uint *)(p_Var10 + -0x68) & 4) == 0) {
      uVar17 = (ulonglong)*(uint *)(param_2 + 4);
      uVar18 = 0;
      if (*(uint *)(param_2 + 4) != 0) {
        this_00 = param_2 + 0x30;
        do {
          pSVar9 = (SC_PART_ENTRY *)this_00;
          uVar6 = SC_PART_ENTRY::IsUnused((SC_PART_ENTRY *)this_00);
          if (((((uVar6 == '\0') &&
                (uVar6 = SC_PART_ENTRY::IsContainer((SC_PART_ENTRY *)this_00), uVar6 == '\0')) &&
               (*(int *)(pSVar9 + 0x18) == 0)) &&
              ((*(longlong *)(pSVar9 + 8) == *(longlong *)(p_Var10 + 0x20) &&
               (*(longlong *)(pSVar9 + 0x10) == *(longlong *)(p_Var10 + 0x28))))) &&
             (((*(int *)pSVar9 != 1 || (*(int *)(p_Var10 + 0x18) != 1)) ||
              ((*(longlong *)(pSVar9 + 0x30) == *(longlong *)(p_Var10 + 0x48) &&
               (*(longlong *)(pSVar9 + 0x38) == *(longlong *)(p_Var10 + 0x50))))))) {
            uVar16 = *(uint *)(p_Var10 + 0x30);
            *(uint *)(pSVar9 + 0x18) = uVar16;
            if (uVar16 < 0x40) {
              auStackY_58[((longlong)(ulonglong)uVar16 >> 3) + 0x68] =
                   auStackY_58[((longlong)(ulonglong)uVar16 >> 3) + 0x68] &
                   ~('\x01' << ((ulonglong)uVar16 & 7));
            }
            PmUpdatePartition(param_1,(_PARTITION_EXTENSION *)(p_Var10 + -0x90),in_R8,uVar18,
                              (_PARTITION_INFORMATION_EX *)pSVar9);
            goto LAB_14000729e;
          }
          uVar18 = uVar18 + 1;
          this_00 = (_DRIVE_LAYOUT_INFORMATION_EX *)(pSVar9 + 0x90);
        } while (uVar18 < (uint)uVar17);
      }
      uVar7 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x70);
      *(uint *)(p_Var10 + -0x68) = *(uint *)(p_Var10 + -0x68) | 4;
      *(undefined4 *)(p_Var10 + 0x10) = 0xffffffff;
      KeReleaseSpinLock(param_1 + 0x70,uVar7);
    }
LAB_14000729e:
  }
  uVar17 = 0;
  if (*(int *)(param_2 + 4) != 0) {
    do {
      this = (SC_PART_ENTRY *)(param_2 + uVar17 * 0x90 + 0x30);
      pSVar9 = this;
      uVar6 = SC_PART_ENTRY::IsUnused(this);
      uVar16 = (uint)uVar17;
      if (((uVar6 == '\0') && (uVar6 = SC_PART_ENTRY::IsContainer(pSVar9), uVar6 == '\0')) &&
         (*(int *)(this + 0x18) == 0)) {
        uVar17 = 0;
        if (local_res10 != 0) {
          for (; (local_res10 >> uVar17 & 1) == 0; uVar17 = uVar17 + 1) {
          }
        }
        *(int *)(this + 0x18) = (int)uVar17;
        if (local_res10 == 0) {
          *(undefined4 *)(this + 0x18) = 0x40;
          do {
            p_Var10 = *(_DEVICE_EXTENSION **)p_Var2;
            while( true ) {
              if (p_Var10 == p_Var2) goto LAB_140007309;
              if (((*(uint *)(p_Var10 + -0x68) & 4) == 0) &&
                 (*(int *)(p_Var10 + 0x30) == *(int *)(this + 0x18))) break;
              p_Var10 = *(_DEVICE_EXTENSION **)p_Var10;
            }
            *(int *)(this + 0x18) = *(int *)(this + 0x18) + 1;
          } while( true );
        }
        auStackY_58[((longlong)(uVar17 & 0xffffffff) >> 3) + 0x68] =
             auStackY_58[((longlong)(uVar17 & 0xffffffff) >> 3) + 0x68] & ~('\x01' << (uVar17 & 7));
LAB_140007309:
        lVar8 = PmCreatePartition(param_1,param_2,uVar16,(_PARTITION_INFORMATION_EX *)this,
                                  &local_res8);
        if (lVar8 < 0) {
          *(undefined4 *)(this + 0x18) = 0;
        }
        else {
          for (p_Var10 = *(_DEVICE_EXTENSION **)p_Var2;
              (p_Var10 != p_Var2 &&
              (((*(uint *)(p_Var10 + -0x68) & 4) != 0 ||
               ((*(longlong *)(p_Var10 + 0x20) <= *(longlong *)(this + 8) &&
                ((*(longlong *)(this + 8) != *(longlong *)(p_Var10 + 0x20) ||
                 (*(uint *)(p_Var10 + 0x10) <= uVar16))))))));
              p_Var10 = *(_DEVICE_EXTENSION **)p_Var10) {
          }
          uVar7 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x70);
          puVar3 = *(undefined8 **)(p_Var10 + 8);
          p_Var13 = local_res8 + 0x90;
          if ((_DEVICE_EXTENSION *)*puVar3 != p_Var10) {
            pcVar5 = (code *)swi(0x29);
            (*pcVar5)(3);
            puVar15 = auStackY_50;
            goto LAB_140007412;
          }
          *(_DEVICE_EXTENSION **)p_Var13 = p_Var10;
          *(undefined8 **)(local_res8 + 0x98) = puVar3;
          *puVar3 = p_Var13;
          *(_PARTITION_EXTENSION **)(p_Var10 + 8) = p_Var13;
          KeReleaseSpinLock(param_1 + 0x70,CONCAT71((int7)((ulonglong)p_Var13 >> 8),uVar7));
        }
      }
      uVar17 = (ulonglong)(uVar16 + 1);
    } while (uVar16 + 1 < *(uint *)(param_2 + 4));
  }
  p_Var10 = *(_DEVICE_EXTENSION **)p_Var2;
  do {
    if (p_Var10 == p_Var2) {
      return 0;
    }
LAB_140007412:
    if ((*(uint *)(p_Var10 + -0x68) & 4) == 0) {
      p_Var1 = param_1 + 0x70;
      *(undefined8 *)(puVar15 + -8) = 0x14000742b;
      uVar7 = KeAcquireSpinLockRaiseToDpc(p_Var1);
      *(uint *)(p_Var10 + -0x68) = *(uint *)(p_Var10 + -0x68) & 0xffffffbf;
      *(undefined8 *)(puVar15 + -8) = 0x140007440;
      KeReleaseSpinLock(p_Var1,uVar7);
      if (*(longlong *)(p_Var10 + 0x28) == 0) {
LAB_1400074af:
        *(undefined8 *)(puVar15 + -8) = 0x1400074b9;
        uVar7 = KeAcquireSpinLockRaiseToDpc(p_Var1);
        *(uint *)(p_Var10 + -0x68) = *(uint *)(p_Var10 + -0x68) | 0x40;
        *(undefined8 *)(puVar15 + -8) = 0x1400074ce;
        KeReleaseSpinLock(p_Var1,uVar7);
      }
      else {
        for (p_Var14 = *(_DEVICE_EXTENSION **)p_Var2; p_Var14 != p_Var2;
            p_Var14 = *(_DEVICE_EXTENSION **)p_Var14) {
          if (((p_Var14 != p_Var10) &&
              (*(_DEVICE_EXTENSION **)(puVar15 + 0x60) = p_Var14 + -0x90,
              (*(uint *)(p_Var14 + -0x68) & 4) == 0)) &&
             (lVar4 = *(longlong *)(puVar15 + 0x60),
             *(uint *)(lVar4 + 0xa0) <= *(uint *)(p_Var10 + 0x10))) {
            p_Var11 = (_DEVICE_EXTENSION *)(lVar4 + 0xa8);
            if (*(ulonglong *)(lVar4 + 0xb0) < *(ulonglong *)(p_Var10 + 0x20)) {
              p_Var12 = p_Var10 + 0x18;
            }
            else {
              p_Var12 = p_Var11;
              p_Var11 = p_Var10 + 0x18;
            }
            if ((ulonglong)(*(longlong *)(p_Var12 + 8) - *(longlong *)(p_Var11 + 8)) <
                *(ulonglong *)(p_Var11 + 0x10)) goto LAB_1400074af;
          }
        }
      }
    }
    p_Var10 = *(_DEVICE_EXTENSION **)p_Var10;
  } while( true );
}



===== PmUpdatePartitionsLegacyRemovable @ 140007500 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl PmUpdatePartitionsLegacyRemovable(struct _DEVICE_EXTENSION * __ptr64,struct
   _DRIVE_LAYOUT_INFORMATION_EX * __ptr64) */

long __cdecl
PmUpdatePartitionsLegacyRemovable(_DEVICE_EXTENSION *param_1,_DRIVE_LAYOUT_INFORMATION_EX *param_2)

{
  _DEVICE_EXTENSION *p_Var1;
  uint uVar2;
  code *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  bool bVar7;
  uchar uVar8;
  undefined1 uVar9;
  long lVar10;
  ulong uVar11;
  SC_PART_ENTRY *this;
  _PARTITION_EXTENSION *p_Var12;
  uint uVar13;
  ulonglong uVar14;
  longlong lVar15;
  _PARTITION_INFORMATION_EX *p_Var16;
  _PARTITION_INFORMATION_EX *this_00;
  undefined1 *puVar17;
  undefined1 *puVar18;
  ulonglong uVar19;
  char cVar20;
  undefined8 uVar21;
  undefined1 auStackY_118 [8];
  undefined1 auStackY_110 [24];
  _PARTITION_EXTENSION *local_d8 [2];
  undefined4 local_c8;
  undefined4 uStack_c4;
  undefined1 auStack_c0 [136];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_118;
  local_c8 = 0;
  uStack_c4 = 0;
  bVar7 = false;
  memset(auStack_c0,0,0x88);
  puVar17 = auStackY_118;
  local_d8[0] = (_PARTITION_EXTENSION *)0x0;
  uVar21 = 0;
  cVar20 = '\0';
  lVar10 = 0;
  uVar2 = 0;
  uVar14 = 0;
  if (*(int *)(param_2 + 4) != 0) {
    do {
      uVar13 = (int)uVar14 + 1;
      *(undefined4 *)(param_2 + uVar14 * 0x90 + 0x48) = 0;
      *(undefined4 *)(param_2 + uVar14 * 0x90 + 0x30) = *(undefined4 *)param_2;
      uVar2 = *(uint *)(param_2 + 4);
      uVar14 = (ulonglong)uVar13;
    } while (uVar13 < uVar2);
  }
  uVar19 = (ulonglong)uVar2;
  uVar14 = 0;
  uVar13 = 0;
  if (uVar2 != 0) {
    do {
      this_00 = (_PARTITION_INFORMATION_EX *)(param_2 + uVar14 * 0x90 + 0x30);
      this = (SC_PART_ENTRY *)this_00;
      uVar8 = SC_PART_ENTRY::IsUnused((SC_PART_ENTRY *)this_00);
      uVar13 = (uint)uVar14;
      if (uVar8 == '\0') {
        uVar8 = SC_PART_ENTRY::IsContainer(this);
        if (uVar8 == '\0') {
          cVar20 = '\x01';
          goto LAB_1400075c4;
        }
      }
      cVar20 = (char)uVar21;
      uVar13 = uVar13 + 1;
      uVar14 = (ulonglong)uVar13;
    } while (uVar13 < (uint)uVar19);
  }
  local_c8 = *(undefined4 *)param_2;
  this_00 = (_PARTITION_INFORMATION_EX *)&local_c8;
LAB_1400075c4:
  p_Var1 = param_1 + 0x380;
  uVar13 = -(uint)(cVar20 != '\0') & uVar13;
  if (*(_DEVICE_EXTENSION **)p_Var1 == p_Var1) {
    *(undefined4 *)(this_00 + 0x18) = 1;
    lVar10 = PmCreatePartition(param_1,param_2,uVar13,this_00,local_d8);
    if (lVar10 < 0) {
      *(undefined4 *)(this_00 + 0x18) = 0;
      puVar18 = auStackY_118;
    }
    else {
      uVar9 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x70);
      lVar15 = *(longlong *)p_Var1;
      p_Var12 = local_d8[0] + 0x90;
      if (*(_DEVICE_EXTENSION **)(lVar15 + 8) != p_Var1) {
        p_Var12 = (_PARTITION_EXTENSION *)0x3;
        pcVar3 = (code *)swi(0x29);
        uVar9 = (*pcVar3)();
        puVar17 = auStackY_110;
      }
      *(longlong *)p_Var12 = lVar15;
      *(_DEVICE_EXTENSION **)(p_Var12 + 8) = p_Var1;
      *(_PARTITION_EXTENSION **)(lVar15 + 8) = p_Var12;
      *(_PARTITION_EXTENSION **)p_Var1 = p_Var12;
      *(undefined8 *)(puVar17 + -8) = 0x14000765a;
      KeReleaseSpinLock(param_1 + 0x70,uVar9);
      puVar18 = puVar17;
    }
  }
  else {
    uVar9 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x70);
    lVar15 = *(longlong *)p_Var1;
    *(uint *)(lVar15 + -0x68) = *(uint *)(lVar15 + -0x68) & 0xfffffffb;
    local_d8[0] = (_PARTITION_EXTENSION *)(lVar15 + -0x90);
    *(undefined4 *)(this_00 + 0x18) = *(undefined4 *)(lVar15 + 0x30);
    if ((*(longlong *)(this_00 + 8) != *(longlong *)(lVar15 + 0x20)) ||
       (*(longlong *)(this_00 + 0x10) != *(longlong *)(lVar15 + 0x28))) {
      bVar7 = true;
      *(uint *)(*(longlong *)(lVar15 + -0x88) + 0x30) =
           *(uint *)(*(longlong *)(lVar15 + -0x88) + 0x30) | 2;
    }
    p_Var16 = (_PARTITION_INFORMATION_EX *)(lVar15 + 0x18);
    *(uint *)(lVar15 + 0x10) = uVar13;
    uVar11 = PmVerifyPropertyChange(this_00,p_Var16);
    *(uint *)(lVar15 + -0x68) = *(uint *)(lVar15 + -0x68) | uVar11;
    uVar21 = *(undefined8 *)(this_00 + 8);
    *(undefined8 *)p_Var16 = *(undefined8 *)this_00;
    *(undefined8 *)(p_Var16 + 8) = uVar21;
    uVar21 = *(undefined8 *)(this_00 + 0x18);
    *(undefined8 *)(p_Var16 + 0x10) = *(undefined8 *)(this_00 + 0x10);
    *(undefined8 *)(p_Var16 + 0x18) = uVar21;
    uVar21 = *(undefined8 *)(this_00 + 0x28);
    *(undefined8 *)(p_Var16 + 0x20) = *(undefined8 *)(this_00 + 0x20);
    *(undefined8 *)(p_Var16 + 0x28) = uVar21;
    uVar21 = *(undefined8 *)(this_00 + 0x38);
    *(undefined8 *)(p_Var16 + 0x30) = *(undefined8 *)(this_00 + 0x30);
    *(undefined8 *)(p_Var16 + 0x38) = uVar21;
    uVar21 = *(undefined8 *)(this_00 + 0x48);
    *(undefined8 *)(p_Var16 + 0x40) = *(undefined8 *)(this_00 + 0x40);
    *(undefined8 *)(p_Var16 + 0x48) = uVar21;
    uVar21 = *(undefined8 *)(this_00 + 0x58);
    *(undefined8 *)(p_Var16 + 0x50) = *(undefined8 *)(this_00 + 0x50);
    *(undefined8 *)(p_Var16 + 0x58) = uVar21;
    uVar21 = *(undefined8 *)(this_00 + 0x68);
    *(undefined8 *)(p_Var16 + 0x60) = *(undefined8 *)(this_00 + 0x60);
    *(undefined8 *)(p_Var16 + 0x68) = uVar21;
    uVar4 = *(undefined4 *)(this_00 + 0x74);
    uVar5 = *(undefined4 *)(this_00 + 0x78);
    uVar6 = *(undefined4 *)(this_00 + 0x7c);
    *(undefined4 *)(p_Var16 + 0x70) = *(undefined4 *)(this_00 + 0x70);
    *(undefined4 *)(p_Var16 + 0x74) = uVar4;
    *(undefined4 *)(p_Var16 + 0x78) = uVar5;
    *(undefined4 *)(p_Var16 + 0x7c) = uVar6;
    uVar4 = *(undefined4 *)(this_00 + 0x84);
    uVar5 = *(undefined4 *)(this_00 + 0x88);
    uVar6 = *(undefined4 *)(this_00 + 0x8c);
    *(undefined4 *)(p_Var16 + 0x80) = *(undefined4 *)(this_00 + 0x80);
    *(undefined4 *)(p_Var16 + 0x84) = uVar4;
    *(undefined4 *)(p_Var16 + 0x88) = uVar5;
    *(undefined4 *)(p_Var16 + 0x8c) = uVar6;
    KeReleaseSpinLock(param_1 + 0x70,uVar9);
    puVar18 = auStackY_118;
    if (bVar7) {
      PmSendDeviceControl(*(undefined8 *)(*(longlong *)(lVar15 + -0x78) + 0x10),0x70407,0,0,0,0,0);
      puVar18 = auStackY_118;
    }
  }
  *(undefined8 *)(puVar18 + -8) = 0x140007776;
  return lVar10;
}



===== PmGetDriveLayoutEx @ 14000779c =====

uint PmGetDriveLayoutEx(_DEVICE_EXTENSION *param_1,undefined8 *param_2)

{
  _DEVICE_EXTENSION *p_Var1;
  uint3 uVar2;
  bool bVar3;
  undefined1 uVar4;
  uchar uVar5;
  char cVar6;
  uint uVar7;
  uint uVar8;
  longlong lVar9;
  _DRIVE_LAYOUT_INFORMATION_EX *p_Var10;
  undefined8 uVar11;
  ulonglong uVar12;
  void *_Dst;
  uint uVar13;
  _DRIVE_LAYOUT_INFORMATION_EX *p_Var14;
  int iVar15;
  byte bVar17;
  byte bVar16;
  ulonglong local_res8;
  uchar local_res10;
  undefined8 local_res18;
  _DRIVE_LAYOUT_INFORMATION_EX *local_res20;
  
  local_res8 = local_res8 & 0xffffffffffffff00;
  local_res10 = '\0';
  bVar3 = false;
  uVar7 = 0;
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = 0;
  }
  p_Var1 = param_1 + 0x70;
  uVar4 = KeAcquireSpinLockRaiseToDpc(p_Var1);
  if (*(int *)(param_1 + 0x458) < 0) {
    local_res18 = 0;
    lVar9 = KeQueryUnbiasedInterruptTimePrecise(&local_res18);
    if ((ulonglong)(lVar9 - *(longlong *)(param_1 + 0x460)) < 300000000) {
      uVar7 = *(uint *)(param_1 + 0x458);
    }
  }
  KeReleaseSpinLock(p_Var1,uVar4);
  if ((int)uVar7 < 0) {
    return uVar7;
  }
  uVar4 = KeAcquireSpinLockRaiseToDpc(p_Var1);
  uVar13 = *(uint *)(param_1 + 0x200);
  p_Var10 = *(_DRIVE_LAYOUT_INFORMATION_EX **)(param_1 + 0x450);
  *(undefined8 *)(param_1 + 0x450) = 0;
  *(uint *)(param_1 + 0x200) = uVar13 & 0xffff7fff;
  local_res20 = p_Var10;
  KeReleaseSpinLock(p_Var1,uVar4);
  bVar16 = (byte)(uVar13 >> 0xf);
  uVar2 = (uint3)(uVar13 >> 0x17);
  bVar17 = bVar16 & 1;
  local_res18 = CONCAT44(local_res18._4_4_,CONCAT31(uVar2,bVar16)) & 0xffffffffffffff01;
  if (p_Var10 == (_DRIVE_LAYOUT_INFORMATION_EX *)0x0) {
    bVar17 = 0;
    local_res18 = (ulonglong)CONCAT43(local_res18._4_4_,uVar2) << 8;
    uVar7 = PmReadPartitionTable(*(undefined8 *)(param_1 + 8),&local_res20);
    if (-1 < (int)uVar7) {
LAB_14000796e:
      p_Var10 = local_res20;
      PmSetDeviceParameterBinary
                (param_1,L"PartitionTableCache",local_res20,*(int *)(local_res20 + 4) * 0x90 + 0x30)
      ;
      uVar12 = PmEnforceService((longlong)param_1);
      if ((((char)uVar12 != '\0') && (*(int *)p_Var10 == 1)) &&
         (uVar12 = 0, *(int *)(p_Var10 + 4) != 0)) {
        do {
          p_Var14 = p_Var10 + uVar12 * 0x90;
          uVar5 = SC_PART_ENTRY::IsUnused((SC_PART_ENTRY *)(p_Var14 + 0x30));
          iVar15 = (int)uVar12;
          if (uVar5 == '\0') {
            if (*(int *)(p_Var14 + 0x30) == 1) {
              uVar12 = *(ulonglong *)(p_Var14 + 0x70);
              uVar5 = SC_PART_ENTRY::IsRecognized((SC_PART_ENTRY *)(p_Var14 + 0x30));
              if (uVar5 != '\0') {
                uVar12 = uVar12 >> 0x39;
              }
              if ((uVar12 & 1) != 0) {
                p_Var14[0x4d] = (_DRIVE_LAYOUT_INFORMATION_EX)0x1;
                bVar3 = true;
                goto LAB_1400079ff;
              }
            }
            local_res8 = CONCAT71(local_res8._1_7_,1);
            cVar6 = '\x01';
          }
          else {
LAB_1400079ff:
            cVar6 = (char)local_res8;
          }
          uVar12 = (ulonglong)(iVar15 + 1U);
        } while (iVar15 + 1U < *(uint *)(p_Var10 + 4));
        if ((bVar3) && (cVar6 == '\0')) {
          uVar4 = KeAcquireSpinLockRaiseToDpc(p_Var1);
          *(uint *)(param_1 + 0x200) = *(uint *)(param_1 + 0x200) | 0x2000;
          KeReleaseSpinLock(p_Var1,uVar4);
        }
      }
      goto LAB_140007a3d;
    }
    if ((*(uint *)(*(longlong *)(param_1 + 8) + 0x34) & 1) == 0) {
      uVar4 = KeAcquireSpinLockRaiseToDpc(p_Var1);
      local_res8 = 0;
      *(uint *)(param_1 + 0x458) = uVar7;
      uVar11 = KeQueryUnbiasedInterruptTimePrecise(&local_res8);
      *(undefined8 *)(param_1 + 0x460) = uVar11;
      KeReleaseSpinLock(p_Var1,uVar4);
      p_Var10 = local_res20;
      goto LAB_140007b5e;
    }
    p_Var10 = (_DRIVE_LAYOUT_INFORMATION_EX *)ExAllocatePool2(0x40,0xc0,0x54506d50);
    local_res20 = p_Var10;
    if (p_Var10 != (_DRIVE_LAYOUT_INFORMATION_EX *)0x0) {
      *(int *)p_Var10 = 0;
      *(int *)(p_Var10 + 4) = 1;
      *(int *)(p_Var10 + 0x30) = 0;
      uVar7 = 0;
      local_res10 = '\x01';
      goto LAB_14000796e;
    }
LAB_1400078f6:
    uVar7 = 0xc000009a;
  }
  else {
LAB_140007a3d:
    p_Var10 = local_res20;
    if (((*(uint *)(param_1 + 0x200) & 1) != 0) && (bVar17 == 0)) {
      uVar7 = PmUpdateLayoutEx(param_1,local_res20,local_res10);
      if ((int)uVar7 < 0) goto LAB_140007b5e;
      local_res18 = CONCAT71(local_res18._1_7_,1);
    }
    if (param_2 != (undefined8 *)0x0) {
      if (0xffffffff < (ulonglong)*(uint *)(p_Var10 + 4) * 0x90) {
        uVar7 = 0xc0000095;
        goto LAB_140007b5e;
      }
      uVar8 = (int)((ulonglong)*(uint *)(p_Var10 + 4) * 0x90) + 0x30;
      uVar13 = 0xffffffff;
      if (uVar8 >= 0x30) {
        uVar13 = uVar8;
      }
      uVar7 = -(uint)(uVar8 < 0x30) & 0xc0000095;
      if (uVar8 < 0x30) goto LAB_140007b5e;
      _Dst = (void *)ExAllocatePool2(0x42,uVar13,0x54506d50);
      if (_Dst == (void *)0x0) goto LAB_1400078f6;
      memmove(_Dst,p_Var10,(ulonglong)uVar13);
      *param_2 = _Dst;
    }
    uVar4 = KeAcquireSpinLockRaiseToDpc(p_Var1);
    memmove(param_1 + 0x390,p_Var10,(ulonglong)(*(int *)(p_Var10 + 4) != 0) * 0x90 + 0x30);
    *(_DRIVE_LAYOUT_INFORMATION_EX **)(param_1 + 0x450) = p_Var10;
    if ((char)local_res18 != '\0') {
      *(uint *)(param_1 + 0x200) = *(uint *)(param_1 + 0x200) | 0x8000;
    }
    *(undefined8 *)(param_1 + 0x460) = 0;
    *(uint *)(param_1 + 0x458) = uVar7;
    KeReleaseSpinLock(p_Var1,uVar4);
    p_Var10 = (_DRIVE_LAYOUT_INFORMATION_EX *)0x0;
  }
LAB_140007b5e:
  if (p_Var10 != (_DRIVE_LAYOUT_INFORMATION_EX *)0x0) {
    ExFreePoolWithTag(p_Var10,0);
  }
  return uVar7;
}



===== PmSetLegacyRemovableFlag @ 140007b98 =====

undefined8 PmSetLegacyRemovableFlag(longlong param_1,int *param_2,char param_3)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 uVar3;
  uchar uVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  int iVar7;
  SC_PART_ENTRY *pSVar8;
  SC_PART_ENTRY *this;
  ulonglong uVar9;
  uint uVar10;
  
  iVar7 = 0;
  if ((*(uint *)(*(longlong *)(param_1 + 8) + 0x34) & 1) == 0) {
    return 0;
  }
  lVar1 = param_1 + 0x70;
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
  uVar10 = *(uint *)(param_1 + 0x200) & 0x800;
  *(uint *)(param_1 + 0x200) = *(uint *)(param_1 + 0x200) & 0xfffff7ff;
  KeReleaseSpinLock(lVar1,uVar3);
  if (*param_2 == 0) {
    if (param_2[1] == 0) {
LAB_140007c5c:
      uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
      *(uint *)(param_1 + 0x200) = *(uint *)(param_1 + 0x200) | 0x800;
      KeReleaseSpinLock(lVar1,uVar3);
      goto LAB_140007c83;
    }
    this = (SC_PART_ENTRY *)(param_2 + 0xc);
    uVar9 = (ulonglong)(uint)param_2[1];
    do {
      pSVar8 = this;
      uVar4 = SC_PART_ENTRY::IsUnused(this);
      if ((uVar4 == '\0') && (uVar4 = SC_PART_ENTRY::IsContainer(this), uVar4 == '\0')) {
        iVar7 = iVar7 + 1;
      }
      this = pSVar8 + 0x90;
      uVar9 = uVar9 - 1;
    } while (uVar9 != 0);
    if (iVar7 == 0) goto LAB_140007c5c;
    if (iVar7 != 1) goto LAB_140007c83;
    if ((param_3 != '\0') || (uVar10 != 0)) goto LAB_140007c5c;
  }
  else {
LAB_140007c83:
    if (uVar10 != 0) {
      if ((*(uint *)(param_1 + 0x200) & 0x800) != 0) {
        return 0;
      }
      plVar6 = (longlong *)(param_1 + 0x380);
      if ((longlong *)*plVar6 == plVar6) {
        return 0;
      }
      uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
      lVar2 = *plVar6;
      if (*(longlong *)(lVar2 + 0x28) == 0) {
        *(uint *)(lVar2 + -0x68) = *(uint *)(lVar2 + -0x68) | 4;
        *(undefined4 *)(lVar2 + 0x10) = 0xffffffff;
      }
      goto LAB_140007cf8;
    }
  }
  if ((*(uint *)(param_1 + 0x200) & 0x800) == 0) {
    return 0;
  }
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
  for (puVar5 = *(undefined8 **)(param_1 + 0x380); puVar5 != (undefined8 *)(param_1 + 0x380);
      puVar5 = (undefined8 *)*puVar5) {
    *(uint *)(puVar5 + -0xd) = *(uint *)(puVar5 + -0xd) | 4;
    *(undefined4 *)(puVar5 + 2) = 0xffffffff;
  }
LAB_140007cf8:
  KeReleaseSpinLock(lVar1,uVar3);
  return 0;
}



===== PmNotificationWorkItem @ 140007d40 =====

/* void __cdecl PmNotificationWorkItem(struct _DEVICE_OBJECT * __ptr64,void * __ptr64) */

void __cdecl PmNotificationWorkItem(_DEVICE_OBJECT *param_1,void *param_2)

{
  longlong ****pppplVar1;
  char *pcVar2;
  longlong *plVar3;
  _IRP _Var4;
  uint uVar5;
  undefined4 uVar6;
  longlong lVar7;
  undefined1 *puVar8;
  _IRP *p_Var9;
  longlong ***ppplVar10;
  longlong ***ppplVar11;
  longlong **pplVar12;
  _IRP *p_Var13;
  undefined8 uVar14;
  code *pcVar15;
  _DEVICE_EXTENSION *p_Var16;
  undefined1 uVar17;
  byte bVar18;
  ulonglong uVar19;
  uint uVar20;
  int iVar21;
  longlong ****pppplVar22;
  longlong ****pppplVar23;
  uint uVar24;
  _IRP *p_Var25;
  _LIST_ENTRY *p_Var26;
  _PARTITION_EXTENSION *p_Var27;
  _DEVICE_EXTENSION *p_Var28;
  _DEVICE_EXTENSION *p_Var29;
  undefined1 *puVar30;
  _DEVICE_EXTENSION *p_Var31;
  _DEVICE_EXTENSION *p_Var32;
  _IRP *p_Var33;
  _DEVICE_EXTENSION *p_Var34;
  _DEVICE_EXTENSION *p_Var35;
  uint uVar36;
  bool bVar37;
  _PARTITION_EXTENSION local_res18 [8];
  uint local_res20;
  undefined1 auStackY_258 [8];
  undefined1 auStackY_250 [24];
  uint local_228;
  longlong ****local_220;
  _DEVICE_EXTENSION *local_218;
  longlong ****local_210;
  _DEVICE_EXTENSION *local_208;
  longlong ****local_200;
  _DEVICE_EXTENSION *local_1f8;
  _IRP *local_1f0;
  _IRP *local_1e8;
  _IRP *local_1e0;
  _DEVICE_EXTENSION *p_Stack_1d8;
  longlong ****local_1d0;
  longlong ****pppplStack_1c8;
  int local_1c0;
  longlong lStack_1b8;
  ulonglong local_1b0;
  undefined4 *puStack_1a8;
  _DEVICE_EXTENSION *local_1a0;
  _DEVICE_EXTENSION *p_Stack_198;
  longlong ***local_190;
  undefined8 uStack_188;
  longlong ***local_180;
  _DEVICE_EXTENSION *p_Stack_178;
  longlong ***local_170;
  undefined8 uStack_168;
  longlong ***local_160;
  longlong ***ppplStack_158;
  longlong ***ppplStack_150;
  longlong lStack_148;
  longlong ***ppplStack_140;
  longlong ***local_138;
  longlong ***ppplStack_130;
  longlong ***local_128;
  longlong ***ppplStack_120;
  longlong ***local_118;
  longlong ***ppplStack_110;
  longlong ***local_108;
  longlong ***ppplStack_100;
  longlong ***local_f8;
  longlong ***ppplStack_f0;
  longlong ***local_e8;
  longlong ***ppplStack_e0;
  longlong ***local_d8;
  longlong ***ppplStack_d0;
  longlong ***local_c8;
  longlong ***ppplStack_c0;
  longlong local_b8;
  longlong ***ppplStack_b0;
  longlong ***local_a8;
  longlong ***ppplStack_a0;
  longlong ***local_98;
  longlong ***ppplStack_90;
  longlong ***local_88;
  longlong ***ppplStack_80;
  longlong ***local_78;
  longlong ***ppplStack_70;
  longlong ***local_68;
  longlong ***ppplStack_60;
  longlong ***local_58;
  longlong ***ppplStack_50;
  longlong ***local_48;
  longlong ***ppplStack_40;
  
  puVar30 = auStackY_258;
  p_Var31 = *(_DEVICE_EXTENSION **)(param_1 + 0x40);
  local_208 = (_DEVICE_EXTENSION *)&local_210;
  local_210 = (longlong ****)&local_210;
  local_res20 = 0;
  local_1e8 = (_IRP *)&local_1f0;
  p_Var35 = p_Var31 + 0x70;
  local_1f0 = (_IRP *)&local_1f0;
  p_Var34 = p_Var31 + 0x200;
  pppplStack_1c8 = (longlong ****)&local_1d0;
  local_1d0 = (longlong ****)&local_1d0;
  local_1f8 = (_DEVICE_EXTENSION *)&local_200;
  local_200 = (longlong ****)&local_200;
  local_218 = (_DEVICE_EXTENSION *)&local_220;
  local_220 = (longlong ****)&local_220;
  local_1c0 = 0;
  puStack_1a8 = (undefined4 *)0x0;
  local_1a0 = p_Var35;
  p_Stack_198 = p_Var31;
  do {
    iVar21 = local_1c0;
    p_Var33 = (_IRP *)0x0;
    p_Var25 = (_IRP *)0x0;
    KeWaitForSingleObject(p_Var31 + 0x38);
    uVar17 = KeAcquireSpinLockRaiseToDpc(p_Var35);
    uVar36 = 0;
    local_228 = 0;
    if ((Microsoft_Windows_PartitionEnableBits & 4) != 0) {
      local_1c0 = iVar21 + 1;
      McTemplateK0qdq_EtwWriteTransfer
                ((ulonglong)*(uint *)p_Var34,p_Var25,p_Var33,*(undefined4 *)(p_Var31 + 0xa8),
                 (char)*(uint *)p_Var34,(char)local_1c0);
    }
    p_Var28 = *(_DEVICE_EXTENSION **)(p_Var31 + 0x380);
    p_Var32 = *(_DEVICE_EXTENSION **)p_Var28;
    if (p_Var28 != p_Var31 + 0x380) {
      do {
        *(undefined4 *)(p_Var28 + -8) = 0;
        if (((*(uint *)p_Var34 & 0x10) != 0) || ((*(uint *)(p_Var28 + -0x68) & 4) != 0)) {
          *(uint *)p_Var34 = *(uint *)p_Var34 | 0x400;
          *(uint *)(p_Var28 + -0x68) = *(uint *)(p_Var28 + -0x68) | 8;
          lVar7 = *(longlong *)p_Var28;
          p_Var16 = p_Stack_1d8;
          if ((*(_DEVICE_EXTENSION **)(lVar7 + 8) == p_Var28) &&
             (plVar3 = *(longlong **)(p_Var28 + 8), (_DEVICE_EXTENSION *)*plVar3 == p_Var28)) {
            *plVar3 = lVar7;
            *(longlong **)(lVar7 + 8) = plVar3;
            if ((*(uint *)(p_Var28 + -0x68) & 2) != 0) {
              local_res20 = local_res20 + 1;
              *(uint *)(p_Var28 + -0x68) = *(uint *)(p_Var28 + -0x68) & 0xfffffffd;
            }
            p_Var29 = p_Var28 + -0x18;
            if ((longlong *****)*(longlong *****)local_218 == &local_220) {
              *(_DEVICE_EXTENSION **)(p_Var28 + -0x10) = local_218;
              *(longlong ******)p_Var29 = &local_220;
              *(_DEVICE_EXTENSION **)local_218 = p_Var29;
              local_218 = p_Var29;
              goto LAB_1400080a3;
            }
          }
          goto LAB_140008ac7;
        }
        uVar19 = Feature_Partition_Manager_Passthrough__private_IsEnabledDeviceUsageNoInline();
        uVar20 = *(uint *)p_Var34;
        p_Var16 = p_Stack_1d8;
        if ((int)uVar19 == 0) {
          if (((uVar20 & 8) == 0) && ((uVar20 >> 9 & 1) == 0)) {
            uVar5 = *(uint *)(p_Var28 + -0x68);
            goto joined_r0x000140007f31;
          }
LAB_140007ec0:
          if (*(longlong *)(p_Var28 + -0x20) != 0) {
            p_Var29 = p_Var28 + -0x18;
            p_Var25 = (_IRP *)&local_220;
            if (*(_IRP **)local_218 != (_IRP *)&local_220) goto LAB_140008ac7;
            p_Var25 = (_IRP *)&local_220;
            *(_IRP **)p_Var29 = p_Var25;
            *(_DEVICE_EXTENSION **)(p_Var28 + -0x10) = local_218;
            *(_DEVICE_EXTENSION **)local_218 = p_Var29;
            local_218 = p_Var29;
          }
          uVar20 = *(uint *)(p_Var28 + -0x68);
          *(uint *)(p_Var28 + -0x68) = uVar20 & 0xfffffefe;
          if ((uVar20 & 2) != 0) {
            local_res20 = local_res20 + 1;
            *(uint *)(p_Var28 + -0x68) = uVar20 & 0xfffffefc;
          }
        }
        else {
          if ((((uVar20 & 8) != 0) || ((uVar20 >> 9 & 1) != 0)) ||
             (((byte)p_Var31[0x210] & 0x40) != 0)) goto LAB_140007ec0;
          uVar5 = *(uint *)(p_Var28 + -0x68);
joined_r0x000140007f31:
          if ((uVar5 >> 8 & 1) != 0) goto LAB_140007ec0;
          if ((uVar20 & 0x1e0) == 0) {
            uVar24 = uVar5 & 0x30;
            p_Var25 = (_IRP *)(ulonglong)uVar24;
            if (uVar24 == 0) {
              if ((uVar5 & 1) == 0) {
                if ((uVar5 & 0x40) == 0) {
                  p_Var25 = (_IRP *)&local_1f0;
                  *(uint *)p_Var34 = uVar20 | 0x400;
                  p_Var13 = (_IRP *)(p_Var28 + -0x18);
                  if (*(_IRP **)local_1e8 != p_Var25) goto LAB_140008ac7;
                  *(_IRP **)(p_Var28 + -0x10) = local_1e8;
                  p_Var25 = (_IRP *)&local_1f0;
                  *(_IRP **)p_Var13 = p_Var25;
                  *(_IRP **)local_1e8 = p_Var13;
                  *(uint *)(p_Var28 + -0x68) = *(uint *)(p_Var28 + -0x68) | 2;
                  *(int *)(p_Var31 + 0x370) = *(int *)(p_Var31 + 0x370) + 1;
                  *(uint *)(p_Var28 + -0x68) = *(uint *)(p_Var28 + -0x68) | 1;
                  local_1e8 = p_Var13;
                }
              }
            }
            else {
              *(uint *)p_Var34 = uVar20 | 0x400;
              if (*(longlong *)(p_Var28 + -0x20) != 0) {
                p_Var33 = (_IRP *)&local_200;
                p_Var29 = p_Var28 + -0x18;
                if (*(_IRP **)local_1f8 != p_Var33) goto LAB_140008ac7;
                *(_DEVICE_EXTENSION **)(p_Var28 + -0x10) = local_1f8;
                p_Var33 = (_IRP *)&local_200;
                *(_IRP **)p_Var29 = p_Var33;
                *(_DEVICE_EXTENSION **)local_1f8 = p_Var29;
                local_1f8 = p_Var29;
              }
              *(uint *)(p_Var28 + -8) = *(uint *)(p_Var28 + -8) | uVar24;
              *(uint *)(p_Var28 + -0x68) = *(uint *)(p_Var28 + -0x68) & ~uVar24;
              uVar36 = uVar36 | uVar24;
            }
          }
          else if (*(longlong *)(p_Var28 + -0x20) == 0) {
            if (*(longlong *)(p_Var28 + -0x70) != 0) {
              if (*(longlong *)(*(longlong *)(p_Var28 + -0x70) + 0x70) != 0) goto LAB_140007f5a;
            }
          }
          else {
LAB_140007f5a:
            p_Var29 = p_Var28 + -0x18;
            if ((longlong *****)*(longlong *****)local_208 != &local_210) goto LAB_140008ac7;
            *(_DEVICE_EXTENSION **)(p_Var28 + -0x10) = local_208;
            *(longlong ******)p_Var29 = &local_210;
            *(_DEVICE_EXTENSION **)local_208 = p_Var29;
            local_208 = p_Var29;
          }
        }
LAB_1400080a3:
        bVar37 = p_Var32 != p_Var31 + 0x380;
        p_Var28 = p_Var32;
        p_Var32 = *(_DEVICE_EXTENSION **)p_Var32;
      } while (bVar37);
    }
    uVar19 = Feature_Partition_Manager_Passthrough__private_IsEnabledDeviceUsageNoInline();
    p_Var34 = p_Var31 + 0x200;
    if ((int)uVar19 == 0) {
      uVar20 = *(uint *)p_Var34;
      if (((uVar20 & 0x10) == 0) && ((uVar20 >> 9 & 1) == 0)) goto LAB_1400080d9;
      p_Var25 = (_IRP *)(ulonglong)local_res20;
      if ((uVar20 & 4) == 0) goto LAB_14000816f;
      p_Var33 = (_IRP *)0x10;
      *(uint *)(p_Var31 + 0x200) = uVar20 & 0xfffffffb;
      local_228 = 0x10;
    }
    else {
      uVar20 = *(uint *)p_Var34;
      if ((((uVar20 & 0x10) == 0) && ((uVar20 >> 9 & 1) == 0)) &&
         (((byte)p_Var31[0x210] & 0x40) == 0)) {
LAB_1400080d9:
        if ((uVar20 & 4) == 0) {
          *(uint *)(p_Var31 + 0x200) = uVar20 | 4;
          local_res20 = local_res20 + 1;
          p_Var25 = (_IRP *)(ulonglong)local_res20;
          *(int *)(p_Var31 + 0x370) = *(int *)(p_Var31 + 0x370) + 1;
          p_Var33 = (_IRP *)0x4;
          local_228 = 4;
          goto LAB_140008174;
        }
      }
      else {
        p_Var25 = (_IRP *)(ulonglong)local_res20;
        if ((uVar20 & 4) != 0) {
          p_Var33 = (_IRP *)0x10;
          *(uint *)(p_Var31 + 0x200) = uVar20 & 0xfffffffb;
          local_228 = 0x10;
          goto LAB_140008174;
        }
      }
LAB_14000816f:
      p_Var25 = (_IRP *)(ulonglong)local_res20;
      p_Var33 = (_IRP *)0x0;
    }
LAB_140008174:
    uVar20 = *(uint *)(p_Var31 + 0x200) & 0x7e0;
    if (uVar20 != 0) {
      local_228 = (uint)p_Var33 | uVar20;
      p_Var33 = (_IRP *)(ulonglong)local_228;
      *(uint *)(p_Var31 + 0x200) = ~uVar20 & *(uint *)(p_Var31 + 0x200);
    }
    if (((longlong *****)local_210 == &local_210) && ((int)p_Var33 == 0)) {
      if (local_1f0 == (_IRP *)&local_1f0) {
        if (uVar36 != 0) goto LAB_14000833f;
        if (((longlong *****)local_200 == &local_200) && ((longlong *****)local_220 == &local_220))
        {
          p_Var31[0x330] = (_DEVICE_EXTENSION)0x0;
          p_Var33 = (_IRP *)0x0;
          KeSetEvent(p_Var31 + 0x338,0);
          KeReleaseSpinLock(p_Var35,uVar17);
          KeReleaseMutex(p_Var31 + 0x38,0);
          PmDecrementPendingPartitionsCount((longlong)p_Var31,(int)p_Var25);
          break;
        }
      }
      KeReleaseSpinLock(p_Var35);
    }
    else {
LAB_14000833f:
      KeReleaseSpinLock(p_Var35);
      if (local_228 >> 10 != 0) {
        PmCollectTelemetry(p_Var31,&puStack_1a8);
      }
    }
    p_Var26 = (_LIST_ENTRY *)0x0;
    KeReleaseMutex(p_Var31 + 0x38);
    while (pppplVar23 = local_220, (longlong *****)local_220 != &local_220) {
      p_Var25 = (_IRP *)p_Var26;
      p_Var16 = p_Stack_1d8;
      if ((longlong *****)local_220[1] != &local_220) goto LAB_140008ac7;
      pppplVar22 = (longlong ****)*local_220;
      if ((longlong ****)pppplVar22[1] != local_220) goto LAB_140008ac7;
      pppplVar22[1] = (longlong ***)&local_220;
      local_190 = (longlong ***)0x0;
      uStack_188 = 0;
      local_180 = (longlong ***)0x0;
      ppplStack_158 = (longlong ***)0x0;
      ppplStack_150 = (longlong ***)0x0;
      lStack_148 = 0;
      ppplStack_140 = (longlong ***)0x0;
      local_138 = (longlong ***)0x0;
      ppplStack_130 = (longlong ***)0x0;
      local_128 = (longlong ***)0x0;
      ppplStack_120 = (longlong ***)0x0;
      local_118 = (longlong ***)0x0;
      ppplStack_110 = (longlong ***)0x0;
      local_108 = (longlong ***)0x0;
      ppplStack_100 = (longlong ***)0x0;
      local_f8 = (longlong ***)0x0;
      ppplStack_f0 = (longlong ***)0x0;
      local_e8 = (longlong ***)0x0;
      ppplStack_e0 = (longlong ***)0x0;
      local_d8 = (longlong ***)0x0;
      ppplStack_d0 = (longlong ***)0x0;
      pppplVar1 = local_220 + -1;
      local_220 = pppplVar22;
      if (*pppplVar1 != (longlong ***)0x0) {
        uVar17 = KeAcquireSpinLockRaiseToDpc();
        ppplStack_158 = pppplVar23[6];
        ppplStack_150 = pppplVar23[7];
        lStack_148 = 0;
        ppplStack_140 = pppplVar23[9];
        local_138 = pppplVar23[10];
        ppplStack_130 = pppplVar23[0xb];
        local_128 = pppplVar23[0xc];
        ppplStack_120 = pppplVar23[0xd];
        local_118 = pppplVar23[0xe];
        ppplStack_110 = pppplVar23[0xf];
        local_108 = pppplVar23[0x10];
        ppplStack_100 = pppplVar23[0x11];
        local_f8 = pppplVar23[0x12];
        ppplStack_f0 = pppplVar23[0x13];
        local_e8 = pppplVar23[0x14];
        ppplStack_e0 = pppplVar23[0x15];
        local_d8 = pppplVar23[0x16];
        ppplStack_d0 = pppplVar23[0x17];
        if ((longlong ****)pppplVar23[0x18] != pppplVar23 + 0x18) {
          lStack_148 = (longlong)pppplVar23[0x19][4] + (longlong)pppplVar23[0x19][2];
        }
        local_190 = pppplVar23[-0xe];
        if ((local_228 & 0x10) == 0) {
          uStack_188 = *(undefined8 *)(p_Var31 + 0x18);
        }
        else {
          uStack_188 = 0;
        }
        if (((ulonglong)pppplVar23[-10] & 8) == 0) {
          local_180 = (longlong ***)&ppplStack_158;
        }
        KeReleaseSpinLock(p_Var35,uVar17);
        IoReuseIrp(*(undefined8 *)(p_Var31 + 0x358),0xc00000bb);
        lVar7 = *(longlong *)(p_Var31 + 0x358);
        p_Var33 = (_IRP *)&local_190;
        pcVar2 = (char *)(lVar7 + 0x43);
        *pcVar2 = *pcVar2 + -1;
        plVar3 = (longlong *)(lVar7 + 0xb8);
        *plVar3 = *plVar3 + -0x48;
        p_Var26 = *(_LIST_ENTRY **)(p_Var31 + 0x358);
        puVar8 = *(undefined1 **)(p_Var26 + 0xb8);
        *puVar8 = 0xf;
        *(_IRP **)(p_Var26 + 0x18) = p_Var33;
        *(undefined4 *)(puVar8 + 8) = 0;
        *(undefined4 *)(puVar8 + 0x10) = 0x18;
        *(undefined4 *)(puVar8 + 0x18) = 0x760004;
        IoForwardIrpSynchronously();
        LOCK();
        *(int *)(pppplVar23[-1] + 4) = *(int *)(pppplVar23[-1] + 4) + -1;
        UNLOCK();
        pppplVar23[-1] = (longlong ***)0x0;
        if (*(int *)(pppplVar23 + -2) == 0) {
          iVar21 = -2;
        }
        else {
          *(int *)(p_Var31 + 0x28c) = *(int *)(p_Var31 + 0x28c) + -1;
          iVar21 = *(int *)(p_Var31 + 0x28c);
          *(undefined4 *)(pppplVar23 + -2) = 0;
          iVar21 = (iVar21 != 0) - 1;
        }
        LOCK();
        *(int *)(p_Var31 + 0x288) = *(int *)(p_Var31 + 0x288) + iVar21;
        UNLOCK();
      }
      if (((ulonglong)pppplVar23[-10] & 8) != 0) {
        p_Var25 = (_IRP *)p_Var26;
        p_Var16 = p_Stack_1d8;
        if ((longlong *****)*pppplStack_1c8 != &local_1d0) goto LAB_140008ac7;
        pppplVar23[1] = (longlong ***)pppplStack_1c8;
        *pppplVar23 = (longlong ***)&local_1d0;
        *pppplStack_1c8 = (longlong ***)pppplVar23;
        pppplStack_1c8 = pppplVar23;
      }
    }
    if ((local_228 & 0x10) != 0) {
      PmTakeDisk(p_Var31);
    }
    if ((local_228 & 0x40) != 0) {
      p_Var26 = (_LIST_ENTRY *)&local_210;
      PmQueryDepends(p_Var31,p_Var26);
    }
    if ((char)local_228 < '\0') {
      p_Var26 = (_LIST_ENTRY *)&local_210;
      PmPowerChanged(p_Var31,p_Var26);
    }
    if ((local_228 & 0x20) != 0) {
      local_1e0 = (_IRP *)0x0;
      p_Stack_1d8 = (_DEVICE_EXTENSION *)0x0;
      bVar18 = KeAcquireSpinLockRaiseToDpc(p_Var35);
      p_Var28 = p_Var31 + 0x290;
      p_Var26 = (_LIST_ENTRY *)(ulonglong)bVar18;
      p_Var25 = *(_IRP **)p_Var28;
      p_Var33 = (_IRP *)p_Var26;
      p_Var16 = p_Stack_1d8;
      if (*(_DEVICE_EXTENSION **)(p_Var25 + 8) != p_Var28) goto LAB_140008ac7;
      *(_IRP ***)(p_Var25 + 8) = &local_1e0;
      *(_IRP ***)p_Var28 = &local_1e0;
      p_Stack_1d8 = *(_DEVICE_EXTENSION **)(p_Var31 + 0x298);
      local_1e0 = p_Var25;
      p_Var16 = p_Var28;
      if (*(_DEVICE_EXTENSION **)p_Stack_1d8 != p_Var28) goto LAB_140008ac7;
      *(_IRP ***)p_Stack_1d8 = &local_1e0;
      *(_DEVICE_EXTENSION **)(p_Var31 + 0x298) = p_Var28;
      *(_DEVICE_EXTENSION **)p_Var28 = p_Var28;
      KeReleaseSpinLock(p_Var35);
      p_Stack_178 = p_Var34;
      while (p_Var13 = local_1e0, local_1e0 != (_IRP *)&local_1e0) {
        p_Var25 = (_IRP *)p_Var26;
        p_Var16 = p_Stack_1d8;
        if ((*(_IRP ***)(local_1e0 + 8) != &local_1e0) ||
           (p_Var9 = *(_IRP **)local_1e0, *(_IRP **)(p_Var9 + 8) != local_1e0)) goto LAB_140008ac7;
        p_Var25 = local_1e0 + -0xa8;
        p_Var27 = (_PARTITION_EXTENSION *)&local_1e0;
        *(_PARTITION_EXTENSION **)(p_Var9 + 8) = p_Var27;
        *(_IRP **)(local_1e0 + 8) = local_1e0;
        *(_IRP **)local_1e0 = local_1e0;
        p_Var33 = *(_IRP **)(local_1e0 + 0x10);
        *(ulonglong *)(local_1e0 + -0x70) = 0;
        _Var4 = *p_Var33;
        local_1e0 = p_Var9;
        if ((_Var4 == (_IRP)0x3) || (_Var4 == (_IRP)0x4)) {
          p_Var33 = (_IRP *)&local_210;
          p_Var27 = (_PARTITION_EXTENSION *)p_Var25;
          iVar21 = PmSplitAndRedirectIo(p_Var31,p_Var25,(_LIST_ENTRY *)p_Var33);
        }
        else if (_Var4 == (_IRP)0xe) {
          uVar36 = *(uint *)(p_Var33 + 0x18);
          uVar19 = (ulonglong)p_Var27 >> 8;
          p_Var27 = (_PARTITION_EXTENSION *)&local_200;
          lStack_1b8 = 0;
          local_res18[0] = (_PARTITION_EXTENSION)0x0;
          iVar21 = 0;
          local_1b0 = 0;
          if (uVar36 < 0x4d031) {
            if (uVar36 != 0x4d030) {
              if ((uVar36 == 0x4d004) || (uVar36 == 0x4d014)) {
                p_Var27 = (_PARTITION_EXTENSION *)CONCAT71((int7)uVar19,1);
                goto LAB_14000863f;
              }
              if (uVar36 != 0x4d02c) goto LAB_140008669;
            }
            p_Var33 = (_IRP *)&lStack_1b8;
            p_Var27 = local_res18;
            uVar19 = PmIoctlPassThroughQuerySectorWriteAta
                               ((longlong)p_Var25,(char *)p_Var27,(undefined8 *)p_Var33,&local_1b0);
            iVar21 = (int)uVar19;
LAB_14000865b:
            if (iVar21 < 0) goto LAB_140008746;
          }
          else {
            if ((uVar36 == 0x4d044) || (uVar36 == 0x4d048)) {
LAB_14000863f:
              p_Var33 = (_IRP *)local_res18;
              uVar19 = PmIoctlPassThroughQuerySectorWriteScsi
                                 ((longlong)p_Var25,(char)p_Var27,(char *)p_Var33,&lStack_1b8,
                                  &local_1b0);
              iVar21 = (int)uVar19;
              goto LAB_14000865b;
            }
            if (uVar36 == 0x2d9404) {
              p_Var33 = (_IRP *)&lStack_1b8;
              p_Var27 = local_res18;
              uVar19 = PmIoctlDsmQuerySectorWrite
                                 ((longlong)p_Var25,p_Var27,(ulonglong *)p_Var33,
                                  (longlong *)&local_1b0);
              iVar21 = (int)uVar19;
              goto LAB_14000865b;
            }
          }
LAB_140008669:
          lVar7 = lStack_1b8;
          pppplVar23 = local_210;
          if ((longlong *****)local_210 != &local_210) {
            do {
              bVar18 = KeAcquireSpinLockRaiseToDpc(local_1a0);
              p_Var27 = (_PARTITION_EXTENSION *)(ulonglong)bVar18;
              ppplVar10 = pppplVar23[7];
              ppplVar11 = pppplVar23[8];
              KeReleaseSpinLock(local_1a0,p_Var27);
              if (lVar7 < (longlong)ppplVar10) {
                if ((longlong)ppplVar10 - lVar7 < (longlong)local_1b0) goto LAB_1400086fd;
              }
              else if (lVar7 - (longlong)ppplVar10 < (longlong)ppplVar11) {
LAB_1400086fd:
                p_Var27 = (_PARTITION_EXTENSION *)(pppplVar23 + -0xf);
                p_Var33 = p_Var25;
                iVar21 = PmPartitionRedirect(p_Stack_198,p_Var27,p_Var25,(void *)0x0,0,0);
                if (iVar21 < 0) break;
              }
              pppplVar23 = (longlong ****)*pppplVar23;
            } while ((longlong *****)pppplVar23 != &local_210);
          }
        }
        else {
          iVar21 = -0x3ffffff0;
        }
LAB_140008746:
        p_Var26 = (_LIST_ENTRY *)CONCAT71((int7)((ulonglong)p_Var27 >> 8),1);
        *(int *)(p_Var13 + -0x78) = iVar21;
        IofCompleteRequest(p_Var25);
        p_Var31 = p_Stack_198;
      }
      p_Var35 = p_Var31 + 0x70;
      p_Var34 = p_Stack_178;
    }
    if ((local_228 >> 8 & 1) != 0) {
      p_Var26 = (_LIST_ENTRY *)&local_210;
      PmQueryVeto(p_Var31,p_Var26);
    }
    if (puStack_1a8 != (undefined4 *)0x0) {
      PmSendTelemetry(puStack_1a8);
      PmFreeTelemetry((longlong)puStack_1a8);
      puStack_1a8 = (undefined4 *)0x0;
    }
    while (pppplVar23 = local_200, (longlong *****)local_210 != &local_210) {
      p_Var25 = (_IRP *)p_Var26;
      p_Var16 = p_Stack_1d8;
      if (((longlong *****)local_210[1] != &local_210) ||
         (pppplVar23 = (longlong ****)*local_210, (longlong ****)pppplVar23[1] != local_210))
      goto LAB_140008ac7;
      pppplVar23[1] = (longlong ***)&local_210;
      local_210 = pppplVar23;
    }
    while( true ) {
      local_200 = pppplVar23;
      pppplVar22 = local_200;
      if ((longlong *****)local_200 == &local_200) break;
      p_Var25 = (_IRP *)p_Var26;
      p_Var16 = p_Stack_1d8;
      if (((longlong *****)local_200[1] != &local_200) ||
         (pppplVar23 = (longlong ****)*local_200, (longlong ****)pppplVar23[1] != local_200))
      goto LAB_140008ac7;
      pppplVar23[1] = (longlong ***)&local_200;
      if (((ulonglong)local_200[2] & 0x10) != 0) {
        local_160 = (longlong ***)0x0;
        local_170 = (longlong ***)0x0;
        uStack_168 = 0;
        local_c8 = (longlong ***)0x0;
        ppplStack_c0 = (longlong ***)0x0;
        local_b8 = 0;
        ppplStack_b0 = (longlong ***)0x0;
        local_a8 = (longlong ***)0x0;
        ppplStack_a0 = (longlong ***)0x0;
        local_98 = (longlong ***)0x0;
        ppplStack_90 = (longlong ***)0x0;
        local_88 = (longlong ***)0x0;
        ppplStack_80 = (longlong ***)0x0;
        local_78 = (longlong ***)0x0;
        ppplStack_70 = (longlong ***)0x0;
        local_68 = (longlong ***)0x0;
        ppplStack_60 = (longlong ***)0x0;
        local_58 = (longlong ***)0x0;
        ppplStack_50 = (longlong ***)0x0;
        local_48 = (longlong ***)0x0;
        ppplStack_40 = (longlong ***)0x0;
        if (local_200[-1] != (longlong ***)0x0) {
          local_200 = pppplVar23;
          uVar17 = KeAcquireSpinLockRaiseToDpc(p_Var35);
          local_c8 = pppplVar22[6];
          ppplStack_c0 = pppplVar22[7];
          local_b8 = 0;
          ppplStack_b0 = pppplVar22[9];
          local_a8 = pppplVar22[10];
          ppplStack_a0 = pppplVar22[0xb];
          local_98 = pppplVar22[0xc];
          ppplStack_90 = pppplVar22[0xd];
          local_88 = pppplVar22[0xe];
          ppplStack_80 = pppplVar22[0xf];
          local_78 = pppplVar22[0x10];
          ppplStack_70 = pppplVar22[0x11];
          local_68 = pppplVar22[0x12];
          ppplStack_60 = pppplVar22[0x13];
          local_58 = pppplVar22[0x14];
          ppplStack_50 = pppplVar22[0x15];
          local_48 = pppplVar22[0x16];
          ppplStack_40 = pppplVar22[0x17];
          if ((longlong ****)pppplVar22[0x18] != pppplVar22 + 0x18) {
            local_b8 = (longlong)pppplVar22[0x19][4] + (longlong)pppplVar22[0x19][2];
          }
          local_170 = pppplVar22[-0xe];
          uStack_168 = *(undefined8 *)(p_Var31 + 0x18);
          local_160 = (longlong ***)&local_c8;
          KeReleaseSpinLock(p_Var35,uVar17);
          IoReuseIrp(*(undefined8 *)(p_Var31 + 0x358),0xc00000bb);
          lVar7 = *(longlong *)(p_Var31 + 0x358);
          p_Var33 = (_IRP *)&local_170;
          pcVar2 = (char *)(lVar7 + 0x43);
          *pcVar2 = *pcVar2 + -1;
          plVar3 = (longlong *)(lVar7 + 0xb8);
          *plVar3 = *plVar3 + -0x48;
          p_Var26 = *(_LIST_ENTRY **)(p_Var31 + 0x358);
          pplVar12 = pppplVar22[-1][5];
          puVar8 = *(undefined1 **)(p_Var26 + 0xb8);
          *puVar8 = 0xf;
          *(_IRP **)(p_Var26 + 0x18) = p_Var33;
          *(undefined4 *)(puVar8 + 8) = 0;
          *(undefined4 *)(puVar8 + 0x10) = 0x18;
          *(undefined4 *)(puVar8 + 0x18) = 0x760020;
          IoForwardIrpSynchronously(pplVar12);
          pppplVar23 = local_200;
        }
      }
    }
    if ((local_228 & 4) != 0) {
      PmGiveDisk(p_Var31);
    }
    while (local_1f0 != (_IRP *)&local_1f0) {
      p_Var25 = local_1f0;
      p_Var16 = p_Stack_1d8;
      if ((*(_IRP ***)(local_1f0 + 8) != &local_1f0) ||
         (p_Var13 = *(_IRP **)local_1f0, *(_IRP **)(p_Var13 + 8) != local_1f0)) goto LAB_140008ac7;
      *(_IRP ***)(p_Var13 + 8) = &local_1f0;
      p_Var27 = (_PARTITION_EXTENSION *)(local_1f0 + -0x78);
      local_1f0 = p_Var13;
      PmGivePartition(p_Var31,p_Var27);
    }
  } while( true );
LAB_140008a90:
  pppplVar23 = local_1d0;
  if ((longlong *****)local_1d0 == &local_1d0) goto LAB_140008ace;
  p_Var16 = p_Stack_1d8;
  if (((longlong *****)local_1d0[1] != &local_1d0) ||
     (pppplVar23 = (longlong ****)*local_1d0, (longlong ****)pppplVar23[1] != local_1d0))
  goto LAB_140008ac7;
  p_Var25 = (_IRP *)&local_1d0;
  pppplVar22 = local_1d0 + -0xf;
  pppplVar23[1] = (longlong ***)p_Var25;
  local_1d0 = pppplVar23;
  PmDeletePartition((longlong)pppplVar22);
  goto LAB_140008a90;
LAB_140008ac7:
  p_Stack_1d8 = p_Var16;
  pppplVar23 = (longlong ****)0x3;
  pcVar15 = (code *)swi(0x29);
  (*pcVar15)();
  puVar30 = auStackY_250;
LAB_140008ace:
  if ((Microsoft_Windows_PartitionEnableBits & 4) != 0) {
    uVar6 = *(undefined4 *)(p_Var31 + 0xa8);
    *(undefined8 *)(puVar30 + -8) = 0x140008ae3;
    McTemplateK0q_EtwWriteTransfer(pppplVar23,p_Var25,p_Var33,uVar6);
  }
  uVar14 = *(undefined8 *)(p_Var31 + 0x350);
  *(undefined8 *)(puVar30 + -8) = 0x140008afb;
  IoReleaseRemoveLockEx(p_Var31 + 0x78,uVar14,0x20);
  return;
}



===== Initialize @ 140008b30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: virtual long __cdecl SC_DISK::Initialize(void) __ptr64 */

long __thiscall SC_DISK::Initialize(SC_DISK *this)

{
  SC_DISK *pSVar1;
  _STORAGE_PROPERTY_ID _Var2;
  long lVar3;
  int iVar4;
  ulonglong uVar5;
  undefined1 auStack_78 [32];
  SC_DISK *local_58;
  undefined4 local_50;
  undefined4 local_38;
  undefined8 local_34;
  undefined8 uStack_2c;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_78;
  local_38 = 0;
  local_34 = 0;
  uStack_2c = 0;
  local_14 = 0;
  local_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  lVar3 = SC_DEVICE::Initialize((SC_DEVICE *)this);
  if (-1 < lVar3) {
    if ((*(longlong *)(this + 8) == 0x4585680f53487c23) &&
       (*(longlong *)(this + 0x10) == -0x7d818829efe03c54)) {
      *(uint *)(this + 200) = *(uint *)(this + 200) | 1;
    }
    pSVar1 = this + 0xd0;
    local_50 = 8;
    local_58 = pSVar1;
    iVar4 = (**(code **)(*(longlong *)this + 0x10))(this,0x7405c,0,0);
    if ((iVar4 < 0) || (*(ulonglong *)pSVar1 == 0)) {
      local_58 = (SC_DISK *)&local_38;
      local_50 = 0x28;
      iVar4 = (**(code **)(*(longlong *)this + 0x10))(this,0x700a0,0,0);
      if (iVar4 < 0) {
        return iVar4;
      }
      *(ulonglong *)pSVar1 = CONCAT44(uStack_1c,uStack_20);
    }
    local_58 = this + 0xd8;
    local_50 = 0x18;
    lVar3 = (**(code **)(*(longlong *)this + 0x10))(this,0x70000,0,0);
    if (-1 < lVar3) {
      if (*(int *)(this + 0xec) == 0) {
        lVar3 = -0x3fffff5d;
      }
      else {
        uVar5 = Feature_3199623483__private_IsEnabledDeviceUsageNoInline();
        if (((int)uVar5 == 0) || (0x1ff < *(uint *)(this + 0xec))) {
          _Var2 = 0x1f;
          if (*(uint *)(this + 0xec) != 0) {
            for (; *(uint *)(this + 0xec) >> _Var2 == 0; _Var2 = _Var2 - 1) {
            }
          }
          *(_STORAGE_PROPERTY_ID *)(this + 0xf0) = _Var2;
          *(ulonglong *)(this + 0xf8) = *(ulonglong *)pSVar1 >> ((byte)_Var2 & 0x3f);
          SC_DEVICE::UpdateStorageProperty((SC_DEVICE *)this,_Var2);
          lVar3 = GenerateId(this);
        }
        else {
          lVar3 = -0x3fffffec;
        }
      }
    }
  }
  return lVar3;
}



===== ReadPartitionTable @ 140008cb4 =====

/* public: long __cdecl SC_MBR::ReadPartitionTable(class SC_DISK_LAYOUT * __ptr64 * __ptr64) __ptr64
    */

long __thiscall SC_MBR::ReadPartitionTable(SC_MBR *this,SC_DISK_LAYOUT **param_1)

{
  MBR_HEADER MVar1;
  short sVar2;
  MBR_HEADER *this_00;
  bool bVar3;
  uchar uVar4;
  SC_DISK_LAYOUT SVar5;
  ulong uVar6;
  uint uVar7;
  long lVar8;
  SC_DISK_LAYOUT *_Src;
  MBR_HEADER *pMVar9;
  SC_DISK_LAYOUT *_Dst;
  longlong lVar10;
  MBR_HEADER *pMVar11;
  longlong lVar12;
  int iVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  ulong local_res20;
  uint local_74;
  
  lVar12 = *(longlong *)this;
  *param_1 = (SC_DISK_LAYOUT *)0x0;
  local_res20 = 0;
  uVar14 = 0;
  iVar13 = 0;
  bVar3 = false;
  this_00 = *(MBR_HEADER **)(lVar12 + 0x108);
  lVar8 = 0;
  local_74 = 0;
  _Src = (SC_DISK_LAYOUT *)ExAllocatePool2(0x40,0x270,0x6d506353);
  if (_Src == (SC_DISK_LAYOUT *)0x0) {
    lVar8 = -0x3fffff66;
  }
  else {
    memset(_Src + 4,0,0x26c);
    *(undefined4 *)_Src = 0;
    *(undefined4 *)(_Src + 8) = *(undefined4 *)(this_00 + 0x1b8);
    uVar6 = MBR_HEADER::CheckSum(this_00);
    *(ulong *)(_Src + 0xc) = uVar6;
    sVar2 = *(short *)(this_00 + 0x1fe);
    while (sVar2 == -0x55ab) {
      pMVar9 = this_00 + 0x1c2;
      pMVar11 = (MBR_HEADER *)0x0;
      lVar12 = 4;
      uVar15 = uVar14;
      do {
        MVar1 = *pMVar9;
        uVar14 = uVar15;
        if ((MVar1 == (MBR_HEADER)0x5) || (MVar1 == (MBR_HEADER)0xf)) {
          if (pMVar11 == (MBR_HEADER *)0x0) {
            pMVar11 = pMVar9 + -4;
            uVar7 = local_res20;
            goto LAB_140008dca;
          }
          bVar3 = true;
        }
        else {
          uVar7 = local_74;
LAB_140008dca:
          uVar4 = MBR_ENTRY::Validate((MBR_ENTRY *)(pMVar9 + -4),uVar7,
                                      *(__uint64 *)(*(longlong *)this + 0xf8));
          if (uVar4 == '\0') {
            bVar3 = true;
          }
          else {
            uVar14 = (ulonglong)((int)uVar15 + 1);
            if (MVar1 != (MBR_HEADER)0x0) {
              *(undefined4 *)(_Src + uVar15 * 0x90 + 0x30) = 0;
              lVar10 = (ulonglong)*(uint *)(pMVar9 + 4) + (ulonglong)uVar7 <<
                       ((byte)*(undefined4 *)(*(longlong *)this + 0xf0) & 0x3f);
              *(longlong *)(_Src + uVar15 * 0x90 + 0x38) = lVar10;
              *(ulonglong *)(_Src + uVar15 * 0x90 + 0x40) =
                   (ulonglong)*(uint *)(pMVar9 + 8) <<
                   ((byte)*(undefined4 *)(*(longlong *)this + 0xf0) & 0x3f);
              *(undefined4 *)(_Src + uVar15 * 0x90 + 0x48) = 0;
              *(MBR_HEADER *)(_Src + uVar15 * 0x90 + 0x50) = *pMVar9;
              _Src[uVar15 * 0x90 + 0x51] =
                   (SC_DISK_LAYOUT)(*(MBR_ENTRY *)(pMVar9 + -4) == (MBR_ENTRY)0x80);
              if ((0xf < (byte)*pMVar9) ||
                 (SVar5 = (SC_DISK_LAYOUT)0x0, (0x8021U >> ((byte)*pMVar9 & 0x1f) & 1) == 0)) {
                SVar5 = (SC_DISK_LAYOUT)0x1;
              }
              _Src[uVar15 * 0x90 + 0x52] = SVar5;
              *(undefined4 *)(_Src + uVar15 * 0x90 + 0x54) = *(undefined4 *)(pMVar9 + 4);
              *(undefined4 *)(_Src + uVar15 * 0x90 + 0x58) = *(undefined4 *)(_Src + 8);
              *(undefined4 *)(_Src + uVar15 * 0x90 + 0x5c) = 0;
              *(longlong *)(_Src + uVar15 * 0x90 + 0x60) = lVar10;
            }
          }
        }
        iVar13 = (int)uVar14;
        pMVar9 = pMVar9 + 0x10;
        lVar12 = lVar12 + -1;
        uVar15 = uVar14;
      } while (lVar12 != 0);
      if ((bVar3) || (pMVar11 == (MBR_HEADER *)0x0)) break;
      local_74 = *(ulong *)(pMVar11 + 8) + local_res20;
      if (local_res20 == 0) {
        local_res20 = *(ulong *)(pMVar11 + 8);
      }
      _Dst = (SC_DISK_LAYOUT *)ExAllocatePool2(0x40,iVar13 * 0x90 + 0x270,0x6d506353);
      if (_Dst == (SC_DISK_LAYOUT *)0x0) {
        lVar8 = -0x3fffff66;
        if (_Src == (SC_DISK_LAYOUT *)0x0) {
          return -0x3fffff66;
        }
LAB_140008fd8:
        ExFreePoolWithTag(_Src,0);
        return lVar8;
      }
      memmove(_Dst,_Src,(longlong)(iVar13 * 0x90 + 0x30));
      memset(_Dst + uVar14 * 0x90 + 0x30,0,0x240);
      ExFreePoolWithTag(_Src,0);
      lVar8 = SC_DISK::ReadSectors(*(SC_DISK **)this,1,(ulonglong)local_74,(void *)0x0);
      _Src = _Dst;
      if (lVar8 < 0) goto LAB_140008fd8;
      sVar2 = *(short *)(this_00 + 0x1fe);
    }
    *(uint *)(_Src + 4) = iVar13 + 3U & 0xfffffffc;
    *param_1 = _Src;
  }
  return lVar8;
}



===== PartitionReleaseRundownExclusive @ 140008ff4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PartitionReleaseRundownExclusive(longlong param_1)

{
  longlong ****pppplVar1;
  longlong *****ppppplVar2;
  longlong ****pppplVar3;
  longlong lVar4;
  longlong lVar5;
  longlong *****ppppplVar6;
  code *pcVar7;
  longlong *****local_38;
  longlong *****local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_30 = (longlong *****)&local_38;
  local_38 = (longlong *****)&local_38;
  local_28 = 0;
  uStack_20 = 0;
  ExReInitializeRundownProtectionCacheAware(*(undefined8 *)(param_1 + 400));
  KeAcquireInStackQueuedSpinLock(param_1 + 0x1c0,&local_28);
  ppppplVar6 = local_30;
  pppplVar1 = (longlong ****)(param_1 + 0x1b0);
  ppppplVar2 = local_30;
  if (((((longlong ******)local_38[1] == &local_38) && ((longlong ******)*local_30 == &local_38)) &&
      ((longlong ****)(*pppplVar1)[1] == pppplVar1)) &&
     ((longlong ****)**(undefined8 **)(param_1 + 0x1b8) == pppplVar1)) {
    *local_30 = pppplVar1;
    ppppplVar2 = *(longlong ******)(param_1 + 0x1b8);
    *ppppplVar2 = (longlong ****)&local_38;
    *(longlong ******)(param_1 + 0x1b8) = local_30;
    pppplVar3 = (longlong ****)*pppplVar1;
    if (((longlong ****)pppplVar3[1] == pppplVar1) && (*local_30 == pppplVar1)) {
      *local_30 = pppplVar3;
      local_30 = ppppplVar2;
      pppplVar3[1] = (longlong ***)ppppplVar6;
      *(longlong *****)(param_1 + 0x1b8) = pppplVar1;
      *pppplVar1 = (longlong ***)pppplVar1;
      KeReleaseInStackQueuedSpinLock(&local_28);
      KeSetEvent(param_1 + 0x198,0,0);
      KeReleaseMutex(param_1 + 0x158,0);
      lVar4 = *(longlong *)(param_1 + 8);
      lVar5 = *(longlong *)(lVar4 + 8);
      while( true ) {
        if ((longlong ******)local_38 == &local_38) {
          return;
        }
        ppppplVar2 = local_30;
        if (((longlong ******)local_38[1] != &local_38) ||
           (ppppplVar6 = (longlong *****)*local_38, (longlong *****)ppppplVar6[1] != local_38))
        break;
        ppppplVar6[1] = (longlong ****)&local_38;
        ppppplVar2 = local_38 + 2;
        local_38 = ppppplVar6;
        (**(code **)(lVar5 + 0x70 + (ulonglong)*(byte *)*ppppplVar2 * 8))(lVar4);
      }
    }
  }
  local_30 = ppppplVar2;
  pcVar7 = (code *)swi(0x29);
  (*pcVar7)(3);
  return;
}



===== PmSwapList @ 140009180 =====

/* void __cdecl PmSwapList(struct _LIST_ENTRY * __ptr64,struct _LIST_ENTRY * __ptr64) */

void __cdecl PmSwapList(_LIST_ENTRY *param_1,_LIST_ENTRY *param_2)

{
  _LIST_ENTRY *p_Var1;
  _LIST_ENTRY *p_Var2;
  longlong lVar3;
  code *pcVar4;
  _LIST_ENTRY *local_18;
  _LIST_ENTRY *local_10;
  
  local_18 = (_LIST_ENTRY *)&local_18;
  local_10 = (_LIST_ENTRY *)&local_18;
  if ((*(_LIST_ENTRY **)(*(longlong *)param_1 + 8) == param_1) &&
     (p_Var1 = *(_LIST_ENTRY **)(param_1 + 8), *(_LIST_ENTRY **)p_Var1 == param_1)) {
    *(_LIST_ENTRY ***)p_Var1 = &local_18;
    *(_LIST_ENTRY ***)(param_1 + 8) = &local_18;
    p_Var2 = *(_LIST_ENTRY **)param_1;
    local_18 = param_1;
    local_10 = p_Var1;
    if (*(_LIST_ENTRY **)(p_Var2 + 8) == param_1) {
      *(_LIST_ENTRY ***)(p_Var2 + 8) = &local_18;
      *(_LIST_ENTRY **)(param_1 + 8) = param_1;
      *(_LIST_ENTRY **)param_1 = param_1;
      local_18 = p_Var2;
      if ((*(_LIST_ENTRY **)(*(longlong *)param_2 + 8) == param_2) &&
         ((_LIST_ENTRY *)**(longlong **)(param_2 + 8) == param_2)) {
        *(_LIST_ENTRY **)param_1 = param_2;
        *(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_2 + 8);
        **(undefined8 **)(param_2 + 8) = param_1;
        lVar3 = *(longlong *)param_2;
        *(_LIST_ENTRY **)(param_2 + 8) = param_1;
        if ((*(_LIST_ENTRY **)(lVar3 + 8) == param_2) && (*(_LIST_ENTRY **)param_1 == param_2)) {
          *(longlong *)param_1 = lVar3;
          *(_LIST_ENTRY **)(lVar3 + 8) = param_1;
          *(_LIST_ENTRY **)(param_2 + 8) = param_2;
          *(_LIST_ENTRY **)param_2 = param_2;
          if ((*(_LIST_ENTRY ***)(p_Var2 + 8) == &local_18) &&
             (*(_LIST_ENTRY ***)p_Var1 == &local_18)) {
            *(_LIST_ENTRY **)(param_2 + 8) = p_Var1;
            *(_LIST_ENTRY ***)param_2 = &local_18;
            *(_LIST_ENTRY **)p_Var1 = param_2;
            local_10 = param_2;
            if ((*(_LIST_ENTRY ***)(p_Var2 + 8) == &local_18) &&
               (*(_LIST_ENTRY ***)param_2 == &local_18)) {
              *(_LIST_ENTRY **)param_2 = p_Var2;
              *(_LIST_ENTRY **)(p_Var2 + 8) = param_2;
              return;
            }
          }
        }
      }
    }
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== PmAssociatePartition @ 1400092a0 =====

/* long __cdecl PmAssociatePartition(struct _DEVICE_EXTENSION * __ptr64,struct _PARTITION_EXTENSION
   * __ptr64) */

long __cdecl PmAssociatePartition(_DEVICE_EXTENSION *param_1,_PARTITION_EXTENSION *param_2)

{
  byte bVar1;
  bool bVar2;
  long lVar3;
  _PARTITION_EXTENSION *p_Var4;
  _DEVICE_EXTENSION *p_Var5;
  _DEVICE_EXTENSION *p_Var6;
  
  lVar3 = 0;
  p_Var5 = *(_DEVICE_EXTENSION **)(param_1 + 0x380);
  bVar1 = 0;
  p_Var6 = (_DEVICE_EXTENSION *)0x0;
  do {
    if (p_Var5 == param_1 + 0x380) {
LAB_1400092f8:
      p_Var4 = (_PARTITION_EXTENSION *)(-(ulonglong)bVar1 & (ulonglong)p_Var6);
      *(_PARTITION_EXTENSION **)(param_2 + 0x20) = p_Var4;
      if (p_Var4 != (_PARTITION_EXTENSION *)0x0) {
        lVar3 = PartitionInsertPatch
                          (p_Var4,*(ulonglong *)(param_2 + 0xe8) & 0xffffffffffffff00,
                           *(__uint64 *)(param_2 + 0xb0),*(__uint64 *)(param_2 + 0xb8));
      }
      return lVar3;
    }
    p_Var6 = p_Var5 + -0x90;
    bVar2 = PmIsEqualName((uint *)(p_Var5 + 0x48),param_2 + 0xf0);
    if (bVar2) {
      bVar1 = 1;
      goto LAB_1400092f8;
    }
    p_Var5 = *(_DEVICE_EXTENSION **)p_Var5;
  } while( true );
}



===== PmRemoveHelper @ 14000934c =====

/* void __cdecl PmRemoveHelper(struct _DEVICE_EXTENSION * __ptr64) */

void __cdecl PmRemoveHelper(_DEVICE_EXTENSION *param_1)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined1 uVar6;
  int iVar7;
  _DEVICE_EXTENSION *p_Var8;
  
  p_Var8 = param_1 + 0x70;
  lVar2 = *(longlong *)(PmControlObject + 0x40);
  uVar6 = KeAcquireSpinLockRaiseToDpc(p_Var8);
  uVar1 = *(uint *)(param_1 + 0x200);
  if ((uVar1 & 0x10) == 0) {
    *(uint *)(param_1 + 0x200) = uVar1 & 0xfffffffe | 0x10;
    iVar7 = PmQueueNotificationWorkItem((longlong)param_1);
    KeReleaseSpinLock(p_Var8,uVar6);
    if (-1 < iVar7) {
      KeWaitForSingleObject(param_1 + 0x338,0,0,0,0);
    }
    KeWaitForSingleObject(param_1 + 0x38,0,0,0,0);
    uVar6 = KeAcquireSpinLockRaiseToDpc(p_Var8);
    *(uint *)(param_1 + 0x200) = *(uint *)(param_1 + 0x200) & 0xfffffffd;
    KeReleaseSpinLock(p_Var8,uVar6);
    KeReleaseMutex(param_1 + 0x38,0);
    KeWaitForSingleObject(lVar2 + 0x68,0,0,0,0);
    PmRemoveIds((longlong)param_1);
    KeReleaseMutex(lVar2 + 0x68,0);
    IoWMIRegistrationControl(*(undefined8 *)(param_1 + 8),2);
    PmWmiCounterDisable((longlong *)(param_1 + 0x2d0),'\x01','\x01');
    param_1[0x2c0] = (_DEVICE_EXTENSION)0x0;
    PmPowerCounterDisable((longlong *)(param_1 + 0x478));
    if (*(longlong *)(param_1 + 0x1f8) != 0) {
      IoSetDeviceInterfaceState(param_1 + 0x1f0,0);
      RtlFreeUnicodeString(param_1 + 0x1f0);
    }
    if (*(longlong *)(param_1 + 0x1e8) != 0) {
      IoSetDeviceInterfaceState(param_1 + 0x1e0,0);
      RtlFreeUnicodeString(param_1 + 0x1e0);
    }
    KeWaitForSingleObject(lVar2 + 0x10,0,0,0,0);
    p_Var8 = param_1 + 0x98;
    lVar3 = *(longlong *)p_Var8;
    if ((*(_DEVICE_EXTENSION **)(lVar3 + 8) != p_Var8) ||
       (plVar4 = *(longlong **)(param_1 + 0xa0), (_DEVICE_EXTENSION *)*plVar4 != p_Var8)) {
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      pcVar5 = (code *)swi(3);
      (*pcVar5)();
      return;
    }
    *plVar4 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar4;
    KeReleaseMutex(lVar2 + 0x10,0);
    *(_DEVICE_EXTENSION **)(param_1 + 0xa0) = p_Var8;
    *(_DEVICE_EXTENSION **)p_Var8 = p_Var8;
  }
  else {
    KeReleaseSpinLock(p_Var8,CONCAT31((int3)(uVar1 >> 8),uVar6));
  }
  return;
}



===== ReadPartitionTable @ 1400095a8 =====

/* public: long __cdecl SC_DISK::ReadPartitionTable(class SC_DISK_LAYOUT * __ptr64 * __ptr64)
   __ptr64 */

long __thiscall SC_DISK::ReadPartitionTable(SC_DISK *this,SC_DISK_LAYOUT **param_1)

{
  int iVar1;
  long lVar2;
  SC_DISK *local_res8;
  
  *param_1 = (SC_DISK_LAYOUT *)0x0;
  iVar1 = *(int *)(this + 0x100);
  if (iVar1 != 0) {
    local_res8 = this;
    if (iVar1 != 1) {
      if (iVar1 == 2) {
        lVar2 = SC_RAW::ReadPartitionTable((SC_RAW *)&local_res8,param_1);
        return lVar2;
      }
      return -0x3fffff45;
    }
    lVar2 = SC_GPT::ReadPartitionTable((SC_GPT *)&local_res8,param_1);
    if (-1 < lVar2) {
      return lVar2;
    }
    lVar2 = ResetPartitionCache(this);
    if (lVar2 < 0) {
      return lVar2;
    }
  }
  SC_MBR::Initialize((SC_MBR *)&local_res8,this);
  lVar2 = SC_MBR::ReadPartitionTable((SC_MBR *)&local_res8,param_1);
  return lVar2;
}



===== McTemplateK0q_EtwWriteTransfer @ 140009638 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0q_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_68 [32];
  undefined8 local_38 [2];
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_28 = local_res20;
  local_1c = 0;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&NotificationWorkItemExit,0,2,local_38);
  return;
}



===== IsVbr @ 1400096a0 =====

/* public: unsigned char __cdecl SC_DISK::IsVbr(void) __ptr64 */

uchar __thiscall SC_DISK::IsVbr(SC_DISK *this)

{
  char *pcVar1;
  uchar uVar2;
  uint uVar3;
  
  pcVar1 = *(char **)(this + 0x108);
  uVar2 = '\0';
  if ((*(short *)(pcVar1 + 0x1fe) == -0x55ab) && ((*pcVar1 + 0x17U & 0xfd) == 0)) {
    uVar2 = '\x01';
    if (*(int *)(this + 0xe0) == 0xb) {
      if (*(longlong *)(pcVar1 + 3) != 0x202020205346544e) {
        for (uVar3 = 0; uVar3 < 4; uVar3 = uVar3 + 1) {
          if (pcVar1[(ulonglong)uVar3 * 0x10 + 0x1c2] != '\0') goto LAB_14000970e;
        }
      }
    }
    else {
LAB_14000970e:
      for (uVar3 = 0; uVar3 < 4; uVar3 = uVar3 + 1) {
        uVar2 = MBR_ENTRY::Validate((MBR_ENTRY *)(pcVar1 + (ulonglong)uVar3 * 0x10 + 0x1be),0,
                                    *(__uint64 *)(this + 0xf8));
        if (uVar2 == '\0') {
          return '\x01';
        }
      }
      uVar2 = '\0';
    }
  }
  return uVar2;
}



===== PartitionAcquireRundownExclusive @ 14000975c =====

void PartitionAcquireRundownExclusive(longlong param_1)

{
  KeWaitForSingleObject(param_1 + 0x158,0,0,0,0);
  KeClearEvent(param_1 + 0x198);
  ExWaitForRundownProtectionReleaseCacheAware(*(undefined8 *)(param_1 + 400));
  return;
}



===== FindFreeRunMbr @ 1400097bc =====

/* public: unsigned __int64 __cdecl SC_DISK_LAYOUT::FindFreeRunMbr(unsigned __int64,unsigned
   long,unsigned __int64,unsigned char,unsigned __int64 * __ptr64) __ptr64 */

__uint64 __thiscall
SC_DISK_LAYOUT::FindFreeRunMbr
          (SC_DISK_LAYOUT *this,__uint64 param_1,ulong param_2,__uint64 param_3,uchar param_4,
          __uint64 *param_5)

{
  ulonglong uVar1;
  bool bVar2;
  uchar uVar3;
  SC_DISK_LAYOUT *pSVar4;
  ulonglong uVar5;
  uint uVar6;
  ulonglong uVar7;
  __uint64 _Var8;
  ulonglong uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  
  _Var8 = 0;
  uVar6 = *(uint *)(this + 4);
  uVar5 = 0x100000;
  bVar2 = false;
  uVar10 = 0;
  *param_5 = 0;
  uVar9 = 0x100000;
  uVar7 = (ulonglong)param_2 * 0xffffffff;
  if (param_1 < (ulonglong)param_2 * 0xffffffff) {
    uVar7 = param_1;
  }
  if (uVar6 < 4) {
    if (uVar6 == 0) goto LAB_140009867;
  }
  else {
    uVar6 = 4;
  }
  pSVar4 = this + 0x40;
  uVar11 = (ulonglong)uVar6;
  bVar2 = false;
  do {
    uVar3 = SC_PART_ENTRY::IsUnused((SC_PART_ENTRY *)(pSVar4 + -0x10));
    if (uVar3 == '\0') {
      uVar1 = *(ulonglong *)(pSVar4 + -8);
      if ((uVar9 < uVar1) && (uVar10 < uVar1 - uVar9)) {
        uVar5 = uVar9;
        uVar10 = uVar1 - uVar9;
      }
      uVar9 = *(longlong *)pSVar4 + uVar1;
    }
    else {
      bVar2 = true;
    }
    pSVar4 = pSVar4 + 0x90;
    uVar11 = uVar11 - 1;
  } while (uVar11 != 0);
LAB_140009867:
  if ((uVar9 < uVar7 - 0x100000) && (uVar7 = (uVar7 - 0x100000) - uVar9, uVar10 < uVar7)) {
    uVar5 = uVar9;
    uVar10 = uVar7;
  }
  if (((uVar6 == 0) || (bVar2)) && (uVar10 != 0)) {
    *param_5 = uVar5;
    _Var8 = uVar10;
  }
  return _Var8;
}



===== __report_gsfailure @ 1400098d0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== RtlComputeCrc32 @ 1400098dd =====

void RtlComputeCrc32(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001400098dd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlComputeCrc32();
  return;
}



===== _purecall @ 1400098f0 =====

void _purecall(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001400098f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _purecall();
  return;
}



===== Feature_Partition_Manager_Passthrough__private_IsEnabledDeviceUsageNoInline @ 140009904 =====

ulonglong Feature_Partition_Manager_Passthrough__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_Partition_Manager_Passthrough__private_featureState;
  if ((Feature_Partition_Manager_Passthrough__private_featureState & 0x10) == 0) {
    uVar1 = Feature_Partition_Manager_Passthrough__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_Partition_Manager_Passthrough__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_Partition_Manager_Passthrough__private_IsEnabledFallback @ 14000993c =====

void Feature_Partition_Manager_Passthrough__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_Partition_Manager_Passthrough__private_descriptor);
  return;
}



===== PmInitializeAttributesTableCache @ 140009958 =====

long PmInitializeAttributesTableCache(_DEVICE_EXTENSION *param_1)

{
  longlong *plVar1;
  undefined1 uVar2;
  long lVar3;
  longlong lVar4;
  uint local_res10 [2];
  longlong *local_res18;
  
  local_res18 = (longlong *)0x0;
  local_res10[0] = 0;
  lVar3 = PmGetDeviceParameterBinary(param_1,L"AttributesTableCache",&local_res18,local_res10);
  if (-1 < lVar3) {
    if (local_res10[0] < 0x18) {
      lVar3 = -0x3ffffffc;
    }
    else {
      lVar4 = *local_res18 + -0x4433b9e5ebd0a0a2;
      if (lVar4 == 0) {
        lVar4 = local_res18[1] + 0x3866d94849973f79;
      }
      if (lVar4 == 0) {
        uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x70);
        plVar1 = local_res18;
        local_res18 = (longlong *)0x0;
        *(longlong **)(param_1 + 0x468) = plVar1;
        KeReleaseSpinLock(param_1 + 0x70,uVar2);
      }
      else {
        lVar3 = -0x3ffff6f5;
      }
    }
  }
  if (local_res18 != (longlong *)0x0) {
    ExFreePoolWithTag(local_res18,0);
  }
  return lVar3;
}



===== PmSetDiskAttributes @ 140009a2c =====

int PmSetDiskAttributes(_DEVICE_EXTENSION *param_1,longlong param_2,uint param_3)

{
  bool bVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  ulonglong uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  
  iVar4 = 0;
  if ((*(uint *)(param_1 + 0x200) & 1) == 0) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
    if ((*(uint *)(param_1 + 0x200) >> 0xd & 1) != 0) {
      return -0x3fffffde;
    }
  }
  if (((*(longlong *)(param_1 + 0x220) != 0) || (*(longlong *)(param_1 + 0x228) != 0)) &&
     ((*(longlong *)(param_1 + 0x220) != *(longlong *)(param_2 + 0x18) ||
      (*(longlong *)(param_1 + 0x228) != *(longlong *)(param_2 + 0x20))))) {
    return -0x3fffffde;
  }
  uVar3 = *(uint *)(param_2 + 0x10) & *(uint *)(param_2 + 8);
  uVar6 = ~*(uint *)(param_2 + 0x10);
  uVar7 = uVar6 & *(uint *)(param_1 + 0x210) | uVar3;
  if (*(char *)(param_2 + 4) != '\0') {
    uVar3 = *(uint *)(param_1 + 0x218) & uVar6 | uVar3;
    iVar4 = PmSetDeviceParameter(param_1,param_2,uVar3);
    if (iVar4 < 0) {
      return iVar4;
    }
    *(ulonglong *)(param_1 + 0x218) = (ulonglong)uVar3;
  }
  *(ulonglong *)(param_1 + 0x210) = (ulonglong)uVar7;
  if (*(char *)(param_2 + 5) == '\0') {
    uVar8 = *(undefined4 *)(param_2 + 0x18);
    uVar9 = *(undefined4 *)(param_2 + 0x1c);
    uVar10 = *(undefined4 *)(param_2 + 0x20);
    uVar11 = *(undefined4 *)(param_2 + 0x24);
  }
  else {
    uVar8 = 0;
    uVar9 = 0;
    uVar10 = 0;
    uVar11 = 0;
  }
  *(undefined4 *)(param_1 + 0x220) = uVar8;
  *(undefined4 *)(param_1 + 0x224) = uVar9;
  *(undefined4 *)(param_1 + 0x228) = uVar10;
  *(undefined4 *)(param_1 + 0x22c) = uVar11;
  if ((*(byte *)(param_2 + 0x10) & 4) != 0) {
    if ((uVar7 & 4) == 0) {
      if ((!bVar1) || (param_1[0x20c] != (_DEVICE_EXTENSION)0x0)) {
        iVar4 = IoSetDeviceInterfaceState(param_1 + 0x1f0,0);
        if (iVar4 < 0) {
          return iVar4;
        }
        iVar4 = IoSetDeviceInterfaceState(param_1 + 0x1e0,1);
        if (iVar4 < 0) {
          return iVar4;
        }
        param_1[0x20c] = (_DEVICE_EXTENSION)0x0;
      }
    }
    else if ((!bVar1) || (param_1[0x20c] == (_DEVICE_EXTENSION)0x0)) {
      iVar4 = IoSetDeviceInterfaceState(param_1 + 0x1e0,0);
      if (iVar4 < 0) {
        return iVar4;
      }
      iVar4 = IoSetDeviceInterfaceState(param_1 + 0x1f0,1);
      if (iVar4 < 0) {
        return iVar4;
      }
      param_1[0x20c] = (_DEVICE_EXTENSION)0x1;
    }
  }
  if ((*(byte *)(param_2 + 0x10) & 2) != 0) {
    LOCK();
    *(uint *)(param_1 + 0x208) = (uint)(((byte)param_1[0x210] & 2) == 0);
    UNLOCK();
  }
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x70);
  if ((*(byte *)(param_2 + 0x10) & 1) != 0) {
    uVar6 = *(uint *)(param_1 + 0x210) & 1;
    uVar3 = *(uint *)(param_1 + 0x200) | 8;
    if (uVar6 == 0) {
      uVar3 = *(uint *)(param_1 + 0x200) & 0xfffffff7;
    }
    *(uint *)(param_1 + 0x200) = uVar3;
    *(uint *)(param_1 + 0x204) = -(uint)(uVar6 != 0) & param_3;
    PmUpdateOffline((longlong)param_1,(char)uVar6);
    uVar5 = Feature_Partition_Manager_Passthrough__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar5 == 0) {
      PmQueueNotificationWorkItem((longlong)param_1);
    }
  }
  uVar5 = Feature_Partition_Manager_Passthrough__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar5 != 0) {
    PmQueueNotificationWorkItem((longlong)param_1);
  }
  KeReleaseSpinLock(param_1 + 0x70,uVar2);
  return iVar4;
}



===== PmSetPartitionAttributesMbr @ 140009cbc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long PmSetPartitionAttributesMbr(_DEVICE_EXTENSION *param_1,undefined8 param_2,ulong param_3)

{
  undefined1 uVar1;
  long lVar2;
  _DEVICE_EXTENSION *p_Var3;
  undefined1 auStack_58 [32];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined8 uStack_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_58;
  local_38 = 0xebd0a0a2;
  local_34 = 0x4433b9e5;
  uStack_30 = 0xb668c087;
  uStack_2c = 0xc79926b7;
  uStack_28 = param_2;
  lVar2 = PmWritePartitionAttributesMbr(param_1,(_PARTITION_ATTRIBUTES_TABLE *)&local_38,param_3);
  if (-1 < lVar2) {
    PmSetDeviceParameterBinary(param_1,L"AttributesTableCache",&local_38,0x18);
    uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x70);
    if (*(longlong *)(param_1 + 0x468) != 0) {
      *(undefined8 *)(*(longlong *)(param_1 + 0x468) + 0x10) = param_2;
    }
    for (p_Var3 = *(_DEVICE_EXTENSION **)(param_1 + 0x380); p_Var3 != param_1 + 0x380;
        p_Var3 = *(_DEVICE_EXTENSION **)p_Var3) {
      *(uint *)(p_Var3 + -0x68) = *(uint *)(p_Var3 + -0x68) | 0x10;
    }
    PmQueueNotificationWorkItem((longlong)param_1);
    KeReleaseSpinLock(param_1 + 0x70,uVar1);
  }
  return lVar2;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 140009dac =====

void wil_details_FeatureReporting_IncrementOpportunityInCache
               (uint *param_1,uint param_2,undefined8 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = *param_1;
  do {
    uVar1 = uVar2;
    param_4[1] = 0;
    uVar2 = uVar1 | 1;
    if ((uVar1 >> 0x16 & 1) != (uint)(param_2 == 5)) {
      uVar4 = uVar1 >> 0xf & 0x7f;
      if (uVar4 != 0) {
        param_4[1] = uVar4;
        uVar4 = 5;
        if (param_2 != 1) {
          uVar4 = 1;
        }
        uVar2 = uVar1 & 0xffc07fff | 1;
        param_4[2] = uVar4;
      }
      uVar4 = 0;
      if (param_2 == 5) {
        uVar4 = 0x400000;
      }
      uVar2 = uVar4 | uVar2 & 0xffbfffff;
    }
    uVar3 = uVar2 >> 0xf & 0x7f;
    uVar4 = uVar3 + 1;
    if ((0x7f < uVar4) || (uVar4 < uVar3)) {
      uVar4 = 1;
      param_4[2] = param_2;
      param_4[1] = uVar3;
    }
    LOCK();
    uVar3 = *param_1;
    if (uVar1 == uVar3) {
      *param_1 = uVar2 ^ (uVar4 << 0xf ^ uVar2) & 0x3f8000;
      uVar2 = uVar1;
    }
    else {
      uVar2 = uVar3;
    }
    UNLOCK();
  } while (uVar1 != uVar3);
  param_4[4] = 0;
  *param_4 = ~uVar1 & 1;
  return;
}



===== wil_details_FeatureReporting_IncrementUsageInCache @ 140009e90 =====

void wil_details_FeatureReporting_IncrementUsageInCache
               (uint *param_1,uint param_2,undefined8 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = *param_1;
  do {
    uVar1 = uVar2;
    param_4[1] = 0;
    uVar2 = uVar1 | 1;
    if ((uVar1 >> 0xe & 1) != (uint)(param_2 == 4)) {
      uVar4 = uVar1 >> 5 & 0x1ff;
      if (uVar4 != 0) {
        param_4[1] = uVar4;
        param_4[2] = ~-(uint)(param_2 != 0) & 4;
        uVar2 = uVar1 & 0xffffc01f | 1;
      }
      uVar4 = 0;
      if (param_2 == 4) {
        uVar4 = 0x4000;
      }
      uVar2 = uVar4 | uVar2 & 0xffffbfff;
    }
    uVar3 = uVar2 >> 5 & 0x1ff;
    uVar4 = uVar3 + 1;
    if ((0x1ff < uVar4) || (uVar4 < uVar3)) {
      uVar4 = 1;
      param_4[2] = param_2;
      param_4[1] = uVar3;
    }
    LOCK();
    uVar3 = *param_1;
    if (uVar1 == uVar3) {
      *param_1 = uVar2 ^ (uVar4 << 5 ^ uVar2) & 0x3fe0;
      uVar2 = uVar1;
    }
    else {
      uVar2 = uVar3;
    }
    UNLOCK();
  } while (uVar1 != uVar3);
  param_4[4] = 0;
  *param_4 = ~uVar1 & 1;
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 140009f80 =====

uint * wil_details_FeatureReporting_RecordUsageInCache
                 (uint *param_1,uint *param_2,undefined8 param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  
  uVar5 = (uint)param_3;
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  if (uVar5 == 0) {
LAB_14000a0dc:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_14000a0cc:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_14000a0dc;
      if (uVar5 == 5) goto LAB_14000a0cc;
      if ((uVar5 != 6) && (uVar5 != 7)) {
        uVar6 = uVar5 - 0x140;
        if ((int)uVar6 < 0x40) {
          uVar2 = param_2[1];
          do {
            if (((uVar2 & 0x10) == 0) || ((uVar2 >> 5 & 0x3f) != uVar6)) {
              uVar4 = 0;
            }
            else {
              uVar4 = 1;
            }
            param_1[4] = uVar4;
            LOCK();
            uVar4 = param_2[1];
            bVar7 = uVar2 == uVar4;
            if (bVar7) {
              param_2[1] = (uVar6 * 0x20 ^ uVar2) & 0x7e0 ^ uVar2 | 0x10;
            }
            else {
              uVar2 = uVar4;
            }
            UNLOCK();
          } while (!bVar7);
          if (param_1[4] != 0) {
            return param_1;
          }
        }
        param_1[2] = uVar5;
        param_1[1] = 1;
        param_1[3] = param_4;
        return param_1;
      }
    }
    uVar6 = 0;
    if (uVar5 == 2) {
      uVar6 = 2;
    }
    else if (uVar5 == 3) {
      uVar6 = 8;
    }
    else if (uVar5 == 6) {
      uVar6 = 4;
    }
    else if (uVar5 == 7) {
      uVar6 = 0x10;
    }
    uVar2 = 1;
    uVar5 = *param_2;
    do {
      uVar3 = uVar5;
      uVar5 = uVar6 | uVar3;
      param_1[4] = (uint)(uVar5 == uVar3);
      uVar4 = uVar5 | 1;
      if (uVar5 == uVar3) {
        uVar4 = uVar5;
      }
      LOCK();
      uVar1 = *param_2;
      if (uVar3 == uVar1) {
        *param_2 = uVar4;
        uVar5 = uVar3;
      }
      else {
        uVar5 = uVar1;
      }
      UNLOCK();
    } while (uVar3 != uVar1);
    if (((uVar4 & 1) == 0) || ((uVar3 & 1) != 0)) {
      uVar2 = 0;
    }
    *param_1 = uVar2;
  }
  return param_1;
}



===== wil_details_FeatureReporting_ReportUsageToService @ 14000a104 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (longlong param_1,undefined8 param_2,int param_3)

{
  bool bVar1;
  uint uVar2;
  undefined7 extraout_var;
  uint uVar3;
  int local_res18 [4];
  
  uVar3 = (uint)param_2 & 1;
  local_res18[0] = param_3;
  uVar2 = wil_details_MapReportingKind(param_3,uVar3);
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(param_1,param_2,(ulonglong)uVar2);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (*(undefined4 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x10),0,uVar3,local_res18,0
               ,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 14000a188 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (longlong param_1,undefined8 param_2,ulonglong param_3)

{
  uint6 uVar1;
  uint *puVar2;
  undefined1 auStack_98 [32];
  uint *local_78;
  undefined8 local_68;
  uint local_60 [6];
  uint local_48;
  uint uStack_44;
  uint uStack_40;
  uint uStack_3c;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_98;
  puVar2 = wil_details_FeatureReporting_RecordUsageInCache
                     (local_60,*(uint **)(param_1 + 8),param_3,(uint)((ulonglong)param_2 >> 0x20));
  local_48 = *puVar2;
  uStack_44 = puVar2[1];
  uStack_40 = puVar2[2];
  uStack_3c = puVar2[3];
  local_38 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_78 = &local_48;
    (*g_wil_details_recordFeatureUsage)
              (*(undefined4 *)(param_1 + 0x18),param_3 & 0xffffffff,1,*(undefined8 *)(param_1 + 8));
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && ((int)param_3 != 0xfe)) {
    local_68._0_6_ = CONCAT24((short)(param_3 & 0xffffffff),*(undefined4 *)(param_1 + 0x18));
    uVar1 = (uint6)local_68;
    local_68 = (ulonglong)(uint6)local_68;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_68 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_68);
  }
  return (int)local_38 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 14000a278 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                    (uint *param_1,ulonglong param_2,longlong param_3)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  uint local_res8 [2];
  undefined8 local_res10;
  
  iVar1 = 0;
  local_res8[0] = 0;
  local_res10 = param_2;
  if (g_wil_details_ensureSubscribedToFeatureConfigurationChanges != (code *)0x0) {
    iVar1 = (*g_wil_details_ensureSubscribedToFeatureConfigurationChanges)();
  }
  uVar2 = wil_details_GetCurrentFeatureEnabledState(param_3,local_res8);
  if (*(char *)(param_3 + 0x1c) == '\0') {
    local_res8[0] = local_res8[0] & -(uint)(iVar1 != 0);
  }
  uVar3 = param_2 & 0xffffffff;
  while( true ) {
    uVar5 = (uint)uVar3;
    local_res10 = CONCAT44(local_res10._4_4_,uVar5);
    if ((local_res8[0] != 0) && (local_res10 = CONCAT44(local_res10._4_4_,uVar5), (uVar3 & 2) == 0))
    {
      uVar4 = uVar5 & 0xfffff63e | uVar2 & 0x9c1;
      uVar5 = uVar4 | 2;
      local_res10 = CONCAT44(local_res10._4_4_,uVar4) | 2;
    }
    if ((param_2 & 4) == 0) {
      uVar4 = uVar2 & 0x400 | uVar5 & 0xfffffbff;
      uVar5 = uVar4 | 4;
      local_res10 = CONCAT44(local_res10._4_4_,uVar4) | 4;
    }
    uVar3 = param_2 & 0xffffffff;
    LOCK();
    uVar4 = *param_1;
    bVar6 = (uint)param_2 == uVar4;
    if (bVar6) {
      *param_1 = uVar5;
    }
    else {
      uVar3 = (ulonglong)uVar4;
    }
    UNLOCK();
    if (bVar6) break;
    param_2 = uVar3;
  }
  if (((param_2 & 4) == 0) &&
     (g_wil_details_subscribeFeatureStateCacheToConfigurationChanges != (code *)0x0)) {
    (*g_wil_details_subscribeFeatureStateCacheToConfigurationChanges)
              (param_1,*(undefined1 *)(param_3 + 0x1c),iVar1);
  }
  if (local_res8[0] == 0) {
    local_res10 = CONCAT44(local_res10._4_4_,uVar2 & 0x9c1 | uVar5 & 0xfffff63e);
  }
  return local_res10;
}



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 14000a388 =====

void wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath
               (uint param_1,int param_2,undefined8 *param_3)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
  puVar2 = (uint *)*param_3;
  if (param_2 == 3) {
    uVar4 = 0x10;
  }
  else {
    if (param_2 != 4) {
      return;
    }
    uVar4 = 0x20;
  }
  if ((*(char *)((longlong)param_3 + 0x1e) == '\0') && (*(char *)((longlong)param_3 + 0x1d) == '\0')
     ) {
    uVar3 = *puVar2;
    if ((uVar3 & 2) != 0) {
      while ((uVar3 & 1) == (param_1 & 1)) {
        LOCK();
        uVar1 = *puVar2;
        bVar5 = uVar3 == uVar1;
        if (bVar5) {
          *puVar2 = uVar4 | uVar3;
        }
        else {
          uVar3 = uVar1;
        }
        UNLOCK();
        if (bVar5) {
          return;
        }
        if ((uVar3 & 2) == 0) {
          return;
        }
      }
    }
  }
  else {
    LOCK();
    *puVar2 = *puVar2 | uVar4;
    UNLOCK();
  }
  return;
}



===== wil_details_GetCurrentFeatureEnabledState @ 14000a3ec =====

uint wil_details_GetCurrentFeatureEnabledState(longlong param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined8 *puVar3;
  uint uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  uint uVar7;
  longlong *plVar8;
  uint local_res8;
  ulonglong local_res10;
  uint local_28 [8];
  
  cVar1 = *(char *)(param_1 + 0x1c);
  uVar2 = *(undefined4 *)(param_1 + 0x18);
  *param_2 = 1;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  uVar5 = wil_RtlStagingConfig_QueryFeatureState(local_28,uVar2,(uint)((byte)(cVar1 - 2U) < 2));
  uVar4 = -(uint)((int)uVar5 != 0) & local_28[0] & 3;
  if (uVar4 == 0) {
    uVar7 = -(uint)(*(char *)(param_1 + 0x1f) != '\0') & 0x40;
  }
  else {
    uVar7 = 0;
    if (local_28[0] == 2) {
      uVar7 = 0x40;
    }
  }
  local_res8 = uVar7 >> 6 ^
               (uVar4 << 7 | -(uint)(local_28[5] != 0) & 0x800 | -(uint)(local_28[4] != 0) & 0x400 |
               uVar7);
  if ((uVar7 != 0) && (plVar8 = *(longlong **)(param_1 + 0x20), plVar8 != (longlong *)0x0)) {
    do {
      puVar3 = (undefined8 *)*plVar8;
      if (puVar3 == (undefined8 *)0x0) {
        return local_res8;
      }
      if ((*(char *)((longlong)puVar3 + 0x1e) == '\0') &&
         (*(char *)((longlong)puVar3 + 0x1d) == '\0')) {
        uVar7 = *(uint *)*puVar3;
        local_res10 = (ulonglong)uVar7;
        if ((uVar7 & 2) == 0) {
          uVar6 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            ((uint *)*puVar3,local_res10,(longlong)puVar3);
          uVar7 = (uint)uVar6;
        }
        uVar4 = local_res8 & 0xfffffffe;
        local_res8 = (uint)((uVar7 & local_res8 & 1) != 0);
      }
      else {
        if (((local_res8 & 1) == 0) || (*(char *)((longlong)puVar3 + 0x1f) == '\0')) {
          uVar4 = 0;
        }
        else {
          uVar4 = 1;
        }
        local_res8 = local_res8 & 0xfffffffe;
      }
      local_res8 = local_res8 | uVar4;
      plVar8 = plVar8 + 1;
    } while ((local_res8 & 1) != 0);
  }
  return local_res8;
}



===== wil_details_IsEnabledFallback @ 14000a54c =====

uint wil_details_IsEnabledFallback(ulonglong param_1,int param_2,undefined8 *param_3)

{
  ulonglong local_res8;
  
  local_res8 = param_1 & 0xffffffff;
  if ((param_1 & 2) == 0) {
    local_res8 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                           ((uint *)*param_3,param_1,(longlong)param_3);
    param_1 = local_res8 & 0xffffffff;
  }
  if ((param_2 != 0) &&
     (wil_details_FeatureReporting_ReportUsageToService((longlong)param_3,local_res8,param_2),
     param_2 - 3U < 2)) {
    wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath((uint)local_res8,param_2,param_3);
  }
  return (uint)param_1 & 1;
}



===== wil_details_MapReportingKind @ 14000a5e0 =====

uint wil_details_MapReportingKind(int param_1,int param_2)

{
  byte bVar1;
  
  if (param_1 != 0) {
    if (param_1 == 1) {
      return ~-(uint)(param_2 != 0) & 4;
    }
    if (param_1 == 2) {
      return (-(uint)(param_2 != 0) & 0xfffffffc) + 5;
    }
    if (param_1 == 3) {
      return (-(uint)(param_2 != 0) & 0xfffffffc) + 6;
    }
    if (param_1 == 4) {
      return (-(uint)(param_2 != 0) & 0xfffffffc) + 7;
    }
    if (param_1 == 5) {
      return (-(uint)(param_2 != 0) & 0xfffffffe) + 10;
    }
    if (param_1 == 6) {
      return (-(uint)(param_2 != 0) & 0xfffffffe) + 0xb;
    }
    bVar1 = (char)param_1 + 0x9c;
    if (bVar1 < 0x32) {
      return (-(uint)(param_2 != 0) & 0xffffffce) + 0x96 + (uint)bVar1;
    }
  }
  return 0xff;
}



===== `vector_deleting_destructor' @ 14000a680 =====

/* public: virtual void * __ptr64 __cdecl PM_DISK::`vector deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall PM_DISK::_vector_deleting_destructor_(PM_DISK *this,uint param_1)

{
  ~PM_DISK(this);
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0);
  }
  return this;
}



===== PmAreVolumesReadyCancelRoutine @ 14000a6c0 =====

/* void __cdecl PmAreVolumesReadyCancelRoutine(struct _DEVICE_OBJECT * __ptr64,struct _IRP *
   __ptr64) */

void __cdecl PmAreVolumesReadyCancelRoutine(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  _IRP *p_Var1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  IoReleaseCancelSpinLock(param_2[0x45]);
  KeWaitForSingleObject(lVar2 + 0x38,0,0,0,0);
  p_Var1 = param_2 + 0xa8;
  lVar3 = *(longlong *)p_Var1;
  if ((*(_IRP **)(lVar3 + 8) == p_Var1) &&
     (plVar4 = *(longlong **)(param_2 + 0xb0), (_IRP *)*plVar4 == p_Var1)) {
    *plVar4 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar4;
    KeReleaseMutex(lVar2 + 0x38,0);
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
    IofCompleteRequest(param_2,0);
    return;
  }
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)(3);
  pcVar5 = (code *)swi(3);
  (*pcVar5)();
  return;
}



===== Feature_3580518712__private_IsEnabledDeviceUsageNoInline @ 14000a768 =====

ulonglong Feature_3580518712__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_3580518712__private_featureState;
  if ((Feature_3580518712__private_featureState & 0x10) == 0) {
    uVar1 = Feature_3580518712__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_3580518712__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_3580518712__private_IsEnabledFallback @ 14000a7a0 =====

void Feature_3580518712__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_3580518712__private_descriptor);
  return;
}



===== PartitionIoctlVerify @ 14000a7bc =====

int PartitionIoctlVerify(longlong param_1,longlong param_2)

{
  longlong lVar1;
  ulonglong *puVar2;
  undefined1 uVar3;
  int iVar4;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong uStack_20;
  
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10) < 0x10) {
    iVar4 = -0x3ffffffc;
  }
  else {
    lVar1 = *(longlong *)(param_1 + 0x40);
    puVar2 = *(ulonglong **)(param_2 + 0x18);
    uVar3 = KeAcquireSpinLockRaiseToDpc(*(longlong *)(lVar1 + 0x18) + 0x70);
    iVar4 = PmEnumerateOverlaps((undefined8 *)(lVar1 + 0x138),*puVar2,(ulonglong)(uint)puVar2[1],
                                PartitionOverlapCount,&local_38);
    KeReleaseSpinLock(*(longlong *)(lVar1 + 0x18) + 0x70,uVar3);
    if (-1 < iVar4) {
      if ((int)local_28 == 1) {
        *puVar2 = uStack_20;
        iVar4 = PartitionPassThrough(param_1,param_2);
        return iVar4;
      }
      iVar4 = -0x3fffff45;
    }
  }
  *(int *)(param_2 + 0x30) = iVar4;
  IofCompleteRequest(param_2,0);
  return iVar4;
}



===== PartitionIoctlVolumePostOnline @ 14000a8bc =====

undefined8 PartitionIoctlVolumePostOnline(longlong param_1)

{
  longlong lVar1;
  undefined1 uVar2;
  bool bVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  uVar2 = KeAcquireSpinLockRaiseToDpc(*(longlong *)(lVar1 + 0x18) + 0x70);
  bVar3 = (*(uint *)(lVar1 + 0x28) & 2) != 0;
  if (bVar3) {
    *(uint *)(lVar1 + 0x28) = *(uint *)(lVar1 + 0x28) & 0xfffffffd;
  }
  KeReleaseSpinLock(*(longlong *)(lVar1 + 0x18) + 0x70,uVar2);
  PmDecrementPendingPartitionsCount(*(longlong *)(lVar1 + 0x18),(uint)bVar3);
  return 0;
}



===== PmInternalIoctlQueryPartitions @ 14000a928 =====

uint PmInternalIoctlQueryPartitions(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  uint *puVar4;
  ulonglong uVar5;
  undefined1 uVar6;
  uint uVar7;
  undefined8 *puVar8;
  uint uVar9;
  undefined8 *puVar10;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  lVar3 = *(longlong *)(param_1 + 0x40);
  if (*(uint *)(lVar2 + 8) < 8) {
    uVar7 = 0xc0000023;
  }
  else {
    lVar1 = lVar3 + 0x70;
    uVar6 = KeAcquireSpinLockRaiseToDpc(lVar1);
    uVar7 = PmQueueNotificationWorkItem(lVar3);
    KeReleaseSpinLock(lVar1,uVar6);
    if (-1 < (int)uVar7) {
      KeWaitForSingleObject(lVar3 + 0x338,0,0,0,0);
      uVar6 = KeAcquireSpinLockRaiseToDpc(lVar1);
      puVar4 = *(uint **)(param_2 + 0x18);
      puVar10 = (undefined8 *)(lVar3 + 0x380);
      uVar7 = 0;
      *puVar4 = 0;
      for (puVar8 = (undefined8 *)*puVar10; puVar8 != puVar10; puVar8 = (undefined8 *)*puVar8) {
        uVar7 = uVar7 + 1;
        *puVar4 = uVar7;
      }
      if ((ulonglong)uVar7 * 8 < 0x100000000) {
        uVar7 = (int)((ulonglong)uVar7 * 8) + 8;
        uVar9 = 0xffffffff;
        if (uVar7 >= 8) {
          uVar9 = uVar7;
        }
        uVar7 = -(uint)(uVar7 < 8) & 0xc0000095;
        if (-1 < (int)uVar7) {
          if (*(uint *)(lVar2 + 8) < uVar9) {
            *(undefined8 *)(param_2 + 0x38) = 8;
            uVar7 = 0x80000005;
          }
          else {
            uVar5 = 0;
            for (puVar8 = (undefined8 *)*puVar10; puVar8 != puVar10; puVar8 = (undefined8 *)*puVar8)
            {
              ObfReferenceObject(puVar8[-0x11]);
              *(undefined8 *)(puVar4 + uVar5 * 2 + 2) = puVar8[-0x11];
              uVar5 = (ulonglong)((int)uVar5 + 1);
            }
            *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar9;
          }
        }
      }
      else {
        uVar7 = 0xc0000095;
      }
      KeReleaseSpinLock(lVar1,uVar6);
    }
  }
  return uVar7;
}



===== PmIoctlAreVolumesReady @ 14000aab4 =====

undefined4 PmIoctlAreVolumesReady(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  longlong lVar2;
  longlong lVar3;
  code *pcVar4;
  bool bVar5;
  undefined1 uVar6;
  longlong *plVar7;
  longlong *plVar8;
  undefined1 *puVar9;
  undefined4 uVar10;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined8 local_28;
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  uVar10 = 0;
  local_28 = 0;
  bVar5 = false;
  KeWaitForSingleObject(lVar3 + 0x38,0,0,0);
  puVar9 = auStack_48;
  if ((*(byte *)(lVar3 + 0x210) & 1) == 0) {
    if (*(int *)(lVar3 + 0x370) == 0) {
      uVar6 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x70);
      if (*(char *)(lVar3 + 0x330) == '\0') {
        bVar5 = false;
        if ((*(byte *)(lVar3 + 0x200) & 0x14) != 0) {
          bVar5 = true;
        }
      }
      KeReleaseSpinLock(lVar3 + 0x70,uVar6);
      puVar9 = auStack_48;
      if (bVar5) goto LAB_14000abc6;
    }
    puVar9 = auStack_48;
    plVar7 = (longlong *)(param_2 + 0xa8);
    plVar8 = *(longlong **)(lVar3 + 0x368);
    if (*plVar8 != lVar3 + 0x360) {
      plVar8 = (longlong *)0x3;
      pcVar4 = (code *)swi(0x29);
      plVar7 = (longlong *)(*pcVar4)();
      puVar9 = auStack_40;
    }
    *plVar7 = lVar3 + 0x360;
    plVar7[1] = (longlong)plVar8;
    *plVar8 = (longlong)plVar7;
    *(longlong **)(lVar3 + 0x368) = plVar7;
    LOCK();
    *(code **)(param_2 + 0x68) = PmAreVolumesReadyCancelRoutine;
    UNLOCK();
    if (*(char *)(param_2 + 0x44) == '\0') {
      uVar10 = 0x103;
      pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
      *pbVar1 = *pbVar1 | 1;
      goto LAB_14000abc6;
    }
    LOCK();
    lVar2 = *(longlong *)(param_2 + 0x68);
    *(longlong *)(param_2 + 0x68) = 0;
    UNLOCK();
    if (lVar2 == 0) {
      bVar5 = false;
      goto LAB_14000abc6;
    }
    uVar10 = 0xc0000120;
  }
  else {
    uVar10 = 0x80000010;
  }
  bVar5 = true;
LAB_14000abc6:
  *(undefined8 *)(puVar9 + -8) = 0x14000abd2;
  KeReleaseMutex(lVar3 + 0x38,0);
  if (bVar5) {
    *(undefined4 *)(param_2 + 0x30) = uVar10;
    *(undefined8 *)(puVar9 + -8) = 0x14000abeb;
    IofCompleteRequest(param_2,0);
  }
  return uVar10;
}



===== PmIoctlReauctionDisk @ 14000ac18 =====

undefined8 PmIoctlReauctionDisk(longlong param_1)

{
  _DEVICE_EXTENSION *p_Var1;
  undefined1 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  p_Var1 = *(_DEVICE_EXTENSION **)(param_1 + 0x40);
  uVar4 = 0;
  uVar3 = 0;
  KeWaitForSingleObject(p_Var1 + 0x38,0,0,0,0);
  if (p_Var1[0x25c] == (_DEVICE_EXTENSION)0x0) {
    *(undefined8 *)(p_Var1 + 0x220) = 0;
    *(undefined8 *)(p_Var1 + 0x228) = 0;
    PmSetInitialDiskAttributes(p_Var1,uVar3);
    uVar2 = KeAcquireSpinLockRaiseToDpc(p_Var1 + 0x70);
    *(uint *)(p_Var1 + 0x200) = *(uint *)(p_Var1 + 0x200) | 0x200;
    PmQueueNotificationWorkItem((longlong)p_Var1);
    KeReleaseSpinLock(p_Var1 + 0x70,uVar2);
  }
  else {
    uVar4 = 0xc00000bb;
  }
  KeReleaseMutex(p_Var1 + 0x38,0);
  return uVar4;
}



===== PmSignalCompletion @ 14000acf0 =====

undefined8 PmSignalCompletion(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  KeSetEvent(param_3,0,0);
  return 0xc0000016;
}



===== RtlULongLongMult @ 14000ad1c =====

undefined8 RtlULongLongMult(ulonglong param_1,ulonglong param_2,undefined8 *param_3)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined8 uVar3;
  
  uVar3 = 0;
  auVar1._8_8_ = 0;
  auVar1._0_8_ = param_2;
  auVar2._8_8_ = 0;
  auVar2._0_8_ = param_1;
  if (SUB168(auVar1 * auVar2,8) == 0) {
    *param_3 = SUB168(auVar1 * auVar2,0);
  }
  else {
    *param_3 = 0xffffffffffffffff;
    uVar3 = 0xc0000095;
  }
  return uVar3;
}



===== PartitionChildIoCompletion @ 14000ad50 =====

/* long __cdecl PartitionChildIoCompletion(struct _DEVICE_OBJECT * __ptr64,struct _IRP *
   __ptr64,void * __ptr64) */

long __cdecl PartitionChildIoCompletion(_DEVICE_OBJECT *param_1,_IRP *param_2,void *param_3)

{
  int *piVar1;
  int iVar2;
  
  if (param_2[0x41] != (_IRP)0x0) {
    *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) = *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) | 1;
  }
  LOCK();
  *(int *)((longlong)param_3 + 0x38) = *(int *)((longlong)param_3 + 0x38) + *(int *)(param_2 + 0x38)
  ;
  UNLOCK();
  IoSetMasterIrpStatus(param_3,*(undefined4 *)(param_2 + 0x30));
  LOCK();
  piVar1 = (int *)((longlong)param_3 + 0x78);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    IofCompleteRequest(param_3,1);
  }
  IoFreeMdl(*(undefined8 *)(param_2 + 8));
  IoFreeIrp(param_2);
  return -0x3fffffea;
}



===== PmControlDeviceControl @ 14000ade0 =====

/* long __cdecl PmControlDeviceControl(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl PmControlDeviceControl(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  *(undefined8 *)(param_2 + 0x38) = 0;
  if (*(int *)(*(longlong *)(param_2 + 0xb8) + 0x18) == 0x74200) {
    uVar2 = PmIoctlGetSanSettings((longlong)param_1,(longlong)param_2);
    iVar1 = (int)uVar2;
  }
  else if (*(int *)(*(longlong *)(param_2 + 0xb8) + 0x18) == 0x7c204) {
    iVar1 = PmIoctlSetSanSettings((longlong)param_1,(longlong)param_2);
  }
  else {
    iVar1 = -0x3ffffff0;
  }
  *(int *)(param_2 + 0x30) = iVar1;
  IofCompleteRequest(param_2,0);
  return iVar1;
}



===== PmFail @ 14000ae50 =====

/* long __cdecl PmFail(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl PmFail(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  *(undefined4 *)(param_2 + 0x30) = 0xc0000010;
  IofCompleteRequest(param_2,0);
  return -0x3ffffff0;
}



===== PmFilterDeviceControlLegacy @ 14000ae80 =====

/* long __cdecl PmFilterDeviceControlLegacy(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64)
    */

long __cdecl PmFilterDeviceControlLegacy(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  char cVar7;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar2 = *(longlong *)(param_2 + 0xb8);
  *(undefined8 *)(param_2 + 0x38) = 0;
  iVar3 = IoAcquireRemoveLockEx(lVar1 + 0x78,param_2,"",1,0x20);
  if (iVar3 < 0) {
    *(int *)(param_2 + 0x30) = iVar3;
    IofCompleteRequest(param_2,0);
    return iVar3;
  }
  uVar4 = *(uint *)(lVar2 + 0x18);
  if (uVar4 < 0x7c011) {
    if (uVar4 == 0x7c010) {
      uVar4 = PmIoctlSetDriveLayout((longlong)param_1,(longlong)param_2);
    }
    else if (uVar4 < 0x70061) {
      if (uVar4 == 0x70060) {
        uVar6 = PmIoctlPerformanceOff((longlong)param_1);
        uVar4 = (uint)uVar6;
      }
      else {
        if (uVar4 < 0x4d049) {
          if ((((uVar4 == 0x4d048) || (uVar4 == 0x4d004)) || (uVar4 == 0x4d014)) ||
             (((uVar4 == 0x4d02c || (uVar4 == 0x4d030)) || (uVar4 == 0x4d044)))) {
            uVar5 = PmIoctlRedirect((longlong)param_1,(longlong)param_2);
            uVar4 = (uint)uVar5;
            goto LAB_14000b2d2;
          }
LAB_14000b273:
          param_2[0x43] = (_IRP)((char)param_2[0x43] + '\x01');
          *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
          uVar4 = IofCallDriver(*(undefined8 *)(lVar1 + 0x10),param_2);
          goto LAB_14000b2d2;
        }
        if (uVar4 == 0x70020) {
          uVar5 = PmIoctlPerformance((longlong)param_1,(longlong)param_2);
          uVar4 = (uint)uVar5;
        }
        else if (uVar4 == 0x70024) {
          uVar4 = PmIoctlIsWritable((longlong)param_1,(longlong)param_2);
        }
        else if (uVar4 == 0x70048) {
          uVar4 = PmIoctlGetPartitionInfoEx((longlong)param_1,(longlong)param_2);
        }
        else {
          if (uVar4 != 0x70050) goto LAB_14000b273;
          uVar4 = PmIoctlGetDriveLayoutEx((longlong)param_1,(longlong)param_2);
        }
      }
    }
    else if (uVar4 < 0x70225) {
      if (uVar4 == 0x70224) {
        uVar5 = PmIoctlGetPerformanceInfo((longlong)param_1,(longlong)param_2);
        uVar4 = (uint)uVar5;
      }
      else if (uVar4 == 0x700a0) {
        uVar4 = PmIoctlGetDriveGeometryEx((longlong)param_1,(longlong)param_2);
      }
      else if (uVar4 == 0x700f0) {
        uVar6 = PmIoctlGetDiskAttributes((longlong)param_1,(longlong)param_2);
        uVar4 = (uint)uVar6;
      }
      else {
        if (uVar4 == 0x700f8) {
          cVar7 = '\0';
          goto LAB_14000b00f;
        }
        if (uVar4 == 0x70140) {
          uVar6 = PmIoctlUpdateProperties((longlong)param_1);
          uVar4 = (uint)uVar6;
        }
        else {
          if (uVar4 != 0x70214) goto LAB_14000b273;
          uVar6 = PmIoctlGetClusterInfo((longlong)param_1,(longlong)param_2);
          uVar4 = (uint)uVar6;
        }
      }
    }
    else if (uVar4 == 0x74004) {
      uVar4 = PmIoctlGetPartitionInfo((longlong)param_1,(longlong)param_2);
    }
    else if (uVar4 == 0x7400c) {
      uVar4 = PmIoctlGetDriveLayout((longlong)param_1,(longlong)param_2);
    }
    else {
      if (uVar4 != 0x74208) {
        if (uVar4 == 0x7421c) {
          uVar4 = PmIoctlAreVolumesReady((longlong)param_1,(longlong)param_2);
          goto LAB_14000b2d2;
        }
        goto LAB_14000b273;
      }
      uVar4 = PmIoctlGetSnapshotInfo((longlong)param_1,(longlong)param_2);
    }
  }
  else if (uVar4 < 0x2d1401) {
    if (uVar4 == 0x2d1400) {
      uVar5 = PmIoctlQueryProperty((longlong)param_1,(longlong)param_2);
      uVar4 = (uint)uVar5;
      goto LAB_14000b2d2;
    }
    if (uVar4 < 0x7c0f5) {
      if (uVar4 == 0x7c0f4) {
        PmEtwControlStart(lVar1,(longlong)param_2);
        uVar4 = PmIoctlSetDiskAttributes((longlong)param_1,(longlong)param_2);
LAB_14000b15c:
        PmEtwControlComplete(lVar1,(longlong)param_2,(char)uVar4);
      }
      else if (uVar4 == 0x7c054) {
        uVar4 = PmIoctlSetDriveLayoutEx((longlong)param_1,(longlong)param_2);
      }
      else if (uVar4 == 0x7c058) {
        uVar4 = PmIoctlCreateDisk((longlong)param_1,(longlong)param_2);
      }
      else if (uVar4 == 0x7c064) {
        uVar4 = 0xc0000010;
      }
      else if (uVar4 == 0x7c0c8) {
        uVar4 = PmIoctlUpdateDriveSize((longlong)param_1,(longlong)param_2);
      }
      else {
        if (uVar4 != 0x7c0d0) goto LAB_14000b273;
        uVar4 = PmIoctlGrowPartition((longlong)param_1,(longlong)param_2);
      }
    }
    else if (uVar4 == 0x7c100) {
      uVar4 = PmIoctlDeleteDriveLayout((longlong)param_1);
    }
    else if (uVar4 == 0x7c20c) {
      uVar4 = PmIoctlSetSnapshotInfo((longlong)param_1,(longlong)param_2);
    }
    else {
      if (uVar4 != 0x7c210) {
        if (uVar4 != 0x7c218) goto LAB_14000b273;
        PmEtwControlStart(lVar1,(longlong)param_2);
        uVar6 = PmIoctlSetClusterInfo((longlong)param_1,(longlong)param_2);
        uVar4 = (uint)uVar6;
        goto LAB_14000b15c;
      }
      uVar4 = PmIoctlResetSnapshotInfo((longlong)param_1);
    }
  }
  else if (uVar4 < 0x70c019) {
    if (uVar4 == 0x70c018) {
      uVar6 = PmIoctlResetReliabilityInfo((longlong)param_1);
      uVar4 = (uint)uVar6;
    }
    else {
      if (uVar4 == 0x2d9404) {
        uVar5 = PmIoctlDsm((longlong)param_1,(longlong)param_2);
        uVar4 = (uint)uVar5;
        goto LAB_14000b2d2;
      }
      if (uVar4 == 0x560030) {
        cVar7 = '\x01';
LAB_14000b00f:
        uVar4 = PmIoctlIsClustered((longlong)param_1,(longlong)param_2,cVar7);
      }
      else if (uVar4 == 0x700010) {
        uVar6 = PmIoctlQueryDeviceState((longlong)param_1,(longlong)param_2);
        uVar4 = (uint)uVar6;
      }
      else if (uVar4 == 0x700014) {
        uVar6 = PmIoctlGetReliabilityInfo((longlong)param_1,(longlong)param_2);
        uVar4 = (uint)uVar6;
      }
      else {
        if (uVar4 != 0x704008) goto LAB_14000b273;
        uVar4 = PmIoctlQueryDiskSignature((longlong)param_1,(longlong)param_2);
      }
    }
  }
  else if (uVar4 == 0x70c01c) {
    uVar6 = PmIoctlReauctionDisk((longlong)param_1);
    uVar4 = (uint)uVar6;
  }
  else if (uVar4 == 0x70c020) {
    uVar4 = PmIoctlCreateSpacesMetadata((longlong)param_1,(longlong)param_2);
  }
  else if (uVar4 == 0x70c024) {
    uVar4 = PmIoctlDeleteSpacesMetadata((longlong)param_1);
  }
  else {
    if (uVar4 != 0x70c030) goto LAB_14000b273;
    uVar4 = 0xc00000bb;
  }
  *(uint *)(param_2 + 0x30) = uVar4;
  IofCompleteRequest(param_2,0);
LAB_14000b2d2:
  IoReleaseRemoveLockEx(lVar1 + 0x78,param_2,0x20);
  return uVar4;
}



===== PmFilterInternalDeviceControl @ 14000b310 =====

/* long __cdecl PmFilterInternalDeviceControl(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64)
    */

long __cdecl PmFilterInternalDeviceControl(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar2 = *(longlong *)(param_2 + 0xb8);
  *(undefined8 *)(param_2 + 0x38) = 0;
  uVar3 = IoAcquireRemoveLockEx(lVar1 + 0x78,param_2,"",1,0x20);
  if ((int)uVar3 < 0) {
    *(uint *)(param_2 + 0x30) = uVar3;
    IofCompleteRequest(param_2,0);
  }
  else {
    if (*(int *)(lVar2 + 0x18) == 0x704190) {
      uVar3 = PmInternalIoctlQueryPartitions((longlong)param_1,(longlong)param_2);
      *(uint *)(param_2 + 0x30) = uVar3;
      IofCompleteRequest(param_2,0);
    }
    else {
      param_2[0x43] = (_IRP)((char)param_2[0x43] + '\x01');
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
      uVar3 = IofCallDriver(*(undefined8 *)(lVar1 + 0x10));
    }
    IoReleaseRemoveLockEx(lVar1 + 0x78,param_2,0x20);
  }
  return uVar3;
}



===== PmOfflineDiskWorkItem @ 14000b410 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl PmOfflineDiskWorkItem(struct _DEVICE_OBJECT * __ptr64,void * __ptr64) */

void __cdecl PmOfflineDiskWorkItem(_DEVICE_OBJECT *param_1,void *param_2)

{
  _DEVICE_EXTENSION *p_Var1;
  int iVar2;
  undefined1 auStack_68 [32];
  undefined8 local_48;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  p_Var1 = *(_DEVICE_EXTENSION **)(param_1 + 0x40);
  local_38 = 0x28;
  local_48 = 0;
  KeWaitForSingleObject(p_Var1 + 0x38,0,0,0);
  local_20 = *(undefined8 *)(p_Var1 + 0x220);
  uStack_18 = *(undefined8 *)(p_Var1 + 0x228);
  local_28 = 3;
  local_30 = 3;
  iVar2 = PmSetDiskAttributes(p_Var1,(longlong)&local_38,(uint)param_2);
  if (-1 < iVar2) {
    PmInvalidatePartitionTableCache((longlong)p_Var1);
  }
  KeReleaseMutex(p_Var1 + 0x38,0);
  LOCK();
  *(undefined4 *)(p_Var1 + 0x374) = 0;
  UNLOCK();
  return;
}



===== PmPropagateVerifyCompletion @ 14000b4e0 =====

/* long __cdecl PmPropagateVerifyCompletion(struct _DEVICE_OBJECT * __ptr64,struct _IRP *
   __ptr64,void * __ptr64) */

long __cdecl PmPropagateVerifyCompletion(_DEVICE_OBJECT *param_1,_IRP *param_2,void *param_3)

{
  IoFreeIrp(param_2);
  return -0x3fffffea;
}



===== PmQueryRemovalRelations @ 14000b504 =====

/* long __cdecl PmQueryRemovalRelations(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl PmQueryRemovalRelations(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  longlong *plVar1;
  undefined4 uVar2;
  longlong lVar3;
  code *pcVar4;
  bool bVar5;
  int iVar6;
  ulonglong uVar7;
  _IRP *p_Var8;
  undefined8 *puVar9;
  undefined8 uVar10;
  undefined1 *puVar11;
  undefined8 in_R8;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  iVar6 = 0;
  bVar5 = true;
  if ((Microsoft_Windows_PartitionEnableBits & 4) != 0) {
    McTemplateK0qp_EtwWriteTransfer
              (param_1,&QueryRemovalRelationsEnter,in_R8,*(undefined4 *)(lVar3 + 0xa8),(char)param_2
              );
  }
  KeAcquireSpinLockRaiseToDpc(lVar3 + 0x70);
  plVar1 = (longlong *)(lVar3 + 0x2a0);
  if ((longlong *)*plVar1 == plVar1) {
    *(uint *)(lVar3 + 0x200) = *(uint *)(lVar3 + 0x200) | 0x40;
    iVar6 = PmQueueNotificationWorkItem(lVar3);
    puVar11 = auStack_48;
    if (iVar6 < 0) goto LAB_14000b5ae;
  }
  puVar11 = auStack_48;
  puVar9 = *(undefined8 **)(lVar3 + 0x2a8);
  p_Var8 = param_2 + 0xa8;
  if ((longlong *)*puVar9 != plVar1) {
    p_Var8 = (_IRP *)0x3;
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)();
    puVar11 = auStack_40;
  }
  *(longlong **)p_Var8 = plVar1;
  *(undefined8 **)(p_Var8 + 8) = puVar9;
  *puVar9 = p_Var8;
  *(_IRP **)(lVar3 + 0x2a8) = p_Var8;
LAB_14000b5ae:
  p_Var8 = (_IRP *)(lVar3 + 0x70);
  *(undefined8 *)(puVar11 + -8) = 0x14000b5bc;
  KeReleaseSpinLock();
  if (-1 < iVar6) {
    *(undefined8 *)(puVar11 + 0x20) = 0;
    p_Var8 = (_IRP *)(lVar3 + 0x338);
    in_R8 = 0;
    uVar10 = 0;
    *(undefined8 *)(puVar11 + -8) = 0x14000b5e5;
    KeWaitForSingleObject();
    iVar6 = *(int *)(param_2 + 0x30);
    if ((Microsoft_Windows_PartitionEnableBits & 4) != 0) {
      uVar2 = *(undefined4 *)(lVar3 + 0xa8);
      *(int *)(puVar11 + 0x28) = iVar6;
      *(_IRP **)(puVar11 + 0x20) = param_2;
      *(undefined8 *)(puVar11 + -8) = 0x14000b60b;
      McTemplateK0qpd_EtwWriteTransfer(p_Var8,uVar10,in_R8,uVar2,puVar11[0x20],puVar11[0x28]);
    }
    *(undefined8 *)(puVar11 + -8) = 0x14000b610;
    uVar7 = Feature_PartmgrRemovalRelations_Fix__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar7 == 0) {
      if (iVar6 < 0) {
        *(int *)(param_2 + 0x30) = iVar6;
        *(undefined8 *)(puVar11 + -8) = 0x14000b674;
        p_Var8 = param_2;
        IofCompleteRequest(param_2,0);
      }
      else {
        param_2[0x43] = (_IRP)((char)param_2[0x43] + '\x01');
        *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
        p_Var8 = *(_IRP **)(lVar3 + 0x10);
        *(undefined8 *)(puVar11 + -8) = 0x14000b65c;
        iVar6 = IofCallDriver(p_Var8,param_2);
      }
    }
    else if (-1 < iVar6) {
      param_2[0x43] = (_IRP)((char)param_2[0x43] + '\x01');
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
      p_Var8 = *(_IRP **)(lVar3 + 0x10);
      *(undefined8 *)(puVar11 + -8) = 0x14000b632;
      iVar6 = IofCallDriver(p_Var8,param_2);
      bVar5 = false;
    }
  }
  *(undefined8 *)(puVar11 + -8) = 0x14000b67e;
  uVar7 = Feature_PartmgrRemovalRelations_Fix__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar7 != 0) && (bVar5)) {
    *(int *)(param_2 + 0x30) = iVar6;
    *(undefined8 *)(puVar11 + -8) = 0x14000b696;
    p_Var8 = param_2;
    IofCompleteRequest(param_2,0);
  }
  if ((Microsoft_Windows_PartitionEnableBits & 4) != 0) {
    uVar2 = *(undefined4 *)(lVar3 + 0xa8);
    *(_IRP **)(puVar11 + 0x20) = param_2;
    *(undefined8 *)(puVar11 + -8) = 0x14000b6bc;
    McTemplateK0qp_EtwWriteTransfer(p_Var8,&QueryRemovalRelationsExit,in_R8,uVar2,puVar11[0x20]);
  }
  return iVar6;
}



===== PmQueryRemoveDevice @ 14000b6e4 =====

/* long __cdecl PmQueryRemoveDevice(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl PmQueryRemoveDevice(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  longlong *plVar1;
  longlong lVar2;
  undefined8 uVar3;
  code *pcVar4;
  undefined1 uVar5;
  int iVar6;
  _IRP *p_Var7;
  undefined8 *puVar8;
  undefined1 *puVar9;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [40];
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  iVar6 = 0;
  uVar5 = KeAcquireSpinLockRaiseToDpc(lVar2 + 0x70);
  plVar1 = (longlong *)(lVar2 + 0x2b0);
  if ((longlong *)*plVar1 == plVar1) {
    *(uint *)(lVar2 + 0x200) = *(uint *)(lVar2 + 0x200) | 0x100;
    iVar6 = PmQueueNotificationWorkItem(lVar2);
    puVar9 = auStack_48;
    if (iVar6 < 0) goto LAB_14000b767;
  }
  puVar9 = auStack_48;
  puVar8 = *(undefined8 **)(lVar2 + 0x2b8);
  p_Var7 = param_2 + 0xa8;
  if ((longlong *)*puVar8 != plVar1) {
    p_Var7 = (_IRP *)0x3;
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)();
    puVar9 = auStack_40;
  }
  *(longlong **)p_Var7 = plVar1;
  *(undefined8 **)(p_Var7 + 8) = puVar8;
  *puVar8 = p_Var7;
  *(_IRP **)(lVar2 + 0x2b8) = p_Var7;
LAB_14000b767:
  *(undefined8 *)(puVar9 + -8) = 0x14000b775;
  KeReleaseSpinLock(lVar2 + 0x70,uVar5);
  if (-1 < iVar6) {
    *(undefined8 *)(puVar9 + 0x20) = 0;
    *(undefined8 *)(puVar9 + -8) = 0x14000b79a;
    KeWaitForSingleObject(lVar2 + 0x338,0,0,0);
    iVar6 = *(int *)(param_2 + 0x30);
    if (iVar6 < 0) {
      *(int *)(param_2 + 0x30) = iVar6;
      *(undefined8 *)(puVar9 + -8) = 0x14000b7d7;
      IofCompleteRequest(param_2,0);
    }
    else {
      param_2[0x43] = (_IRP)((char)param_2[0x43] + '\x01');
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
      uVar3 = *(undefined8 *)(lVar2 + 0x10);
      *(undefined8 *)(puVar9 + -8) = 0x14000b7bf;
      iVar6 = IofCallDriver(uVar3,param_2);
    }
  }
  return iVar6;
}



===== PmStartDevice @ 14000b800 =====

/* long __cdecl PmStartDevice(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl PmStartDevice(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  long lVar1;
  longlong lVar2;
  
  if (*(char *)(*(longlong *)(PmControlObject + 0x40) + 0xa9) == '\0') {
    lVar1 = PmStartDeviceInternal(*(_DEVICE_EXTENSION **)(param_1 + 0x40),param_2);
  }
  else {
    lVar2 = IoAllocateWorkItem();
    if (lVar2 == 0) {
      lVar1 = -0x3fffff66;
    }
    else {
      *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) =
           *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) | 1;
      IoQueueWorkItemEx(lVar2,PmStartDeviceWorkItem,2,param_2);
      lVar1 = 0x103;
    }
  }
  return lVar1;
}



===== PmStartDeviceInternal @ 14000b880 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl PmStartDeviceInternal(struct _DEVICE_EXTENSION * __ptr64,struct _IRP * __ptr64) */

long __cdecl PmStartDeviceInternal(_DEVICE_EXTENSION *param_1,_IRP *param_2)

{
  _DEVICE_EXTENSION *p_Var1;
  longlong lVar2;
  _STORAGE_HW_FIRMWARE_INFO *p_Var3;
  undefined1 uVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  undefined1 auStackY_c8 [32];
  undefined8 local_80;
  undefined4 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 local_50;
  undefined4 uStack_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_c8;
  lVar2 = *(longlong *)(PmControlObject + 0x40);
  local_80 = 0;
  local_78 = 0;
  local_50 = 0;
  uStack_4c = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_5c = 0;
  uStack_58 = 0;
  uStack_54 = 0;
  IoForwardIrpSynchronously(*(undefined8 *)(param_1 + 0x10));
  uVar6 = *(uint *)(param_2 + 0x30);
  if ((-1 < (int)uVar6) && ((*(uint *)(param_1 + 0x200) & 1) == 0)) {
    *(uint *)(*(longlong *)(param_1 + 8) + 0x34) =
         *(uint *)(*(longlong *)(param_1 + 8) + 0x34) |
         *(uint *)(*(longlong *)(param_1 + 0x10) + 0x34) & 0x40001;
    if ((*(uint *)(*(longlong *)(param_1 + 0x10) + 0x34) & 1) != 0) {
      uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x70);
      *(uint *)(param_1 + 0x200) = *(uint *)(param_1 + 0x200) | 0x800;
      KeReleaseSpinLock(param_1 + 0x70,uVar4);
    }
    uVar6 = IoGetDevicePropertyData(*(undefined8 *)(param_1 + 0x18),&DEVPKEY_Device_ClassGuid);
    if (-1 < (int)uVar6) {
      uVar8 = PmSendDeviceControl(*(undefined8 *)(param_1 + 0x10),0x2d1084,0,0,&local_70,0x28,0);
      if ((int)uVar8 < 0) {
        uVar8 = PmSendDeviceControl(*(undefined8 *)(param_1 + 0x10),0x2d1080,0,0,&local_80,0xc,0);
        uVar6 = (uint)uVar8;
        if ((int)uVar6 < 0) goto LAB_14000beeb;
        *(undefined4 *)(param_1 + 0xa8) = local_80._4_4_;
      }
      else {
        p_Var1 = param_1 + 0xb0;
        *(undefined4 *)(param_1 + 0xa8) = local_60;
        *(ulonglong *)(param_1 + 0xb8) = CONCAT44(uStack_58,uStack_5c);
        *(ulonglong *)(param_1 + 0xc0) = CONCAT44(local_50,uStack_54);
        *(undefined4 *)(param_1 + 0xac) = (undefined4)uStack_68;
        *(undefined4 *)(param_1 + 0xb4) = 0x28;
        *(undefined4 *)p_Var1 = 0x28;
        PmSendDeviceControl(*(undefined8 *)(param_1 + 0x10),0x2d280c,p_Var1,0x28,p_Var1,0x28,0);
      }
      uVar6 = PmGetRegistryId(param_1,(_GUID *)(param_1 + 0xd8));
      if (-1 < (int)uVar6) {
        p_Var1 = param_1 + 0xe8;
        uVar6 = PmQueryStorageProperty(param_1,0,0x28,(void **)p_Var1);
        if (-1 < (int)uVar6) {
          uVar6 = ScExtractDeviceStrings
                            (*(_STORAGE_DEVICE_DESCRIPTOR **)p_Var1,
                             (_UNICODE_STRING *)(param_1 + 0x158),
                             (_UNICODE_STRING *)(param_1 + 0x168),
                             (_UNICODE_STRING *)(param_1 + 0x178),
                             (_UNICODE_STRING *)(param_1 + 0x188));
          if (-1 < (int)uVar6) {
            PmGetFirmwareInfo(param_1,*(_STORAGE_BUS_TYPE *)((longlong)*(void **)p_Var1 + 0x1c),
                              (_STORAGE_HW_FIRMWARE_INFO **)(param_1 + 0xf0));
            p_Var3 = *(_STORAGE_HW_FIRMWARE_INFO **)(param_1 + 0xf0);
            if ((p_Var3 == (_STORAGE_HW_FIRMWARE_INFO *)0x0) ||
               (uVar6 = ScExtractFirmwareRevision(p_Var3,(_UNICODE_STRING *)(param_1 + 0x178)),
               -1 < (int)uVar6)) {
              PmQueryStorageProperty(param_1,2,0x10,(void **)(param_1 + 0xf8));
              if ((*(uint *)(*(longlong *)(param_1 + 8) + 0x34) & 0x40001) == 0) {
                PmQueryStorageProperty(param_1,4,0x1c,(void **)(param_1 + 0x100));
              }
              PmQueryStorageProperty(param_1,6,0x1c,(void **)(param_1 + 0x108));
              PmQueryStorageProperty(param_1,7,0xc,(void **)(param_1 + 0x110));
              PmQueryStorageProperty(param_1,8,0xc,(void **)(param_1 + 0x118));
              PmQueryStorageProperty(param_1,0xb,0x28,(void **)(param_1 + 0x120));
              PmQueryStorageProperty(param_1,0xe,0x20,(void **)(param_1 + 0x128));
              PmQueryStorageProperty(param_1,0x3c,0x30,(void **)(param_1 + 0x130));
              PmGetHybridInfo(param_1,(_SRB_IO_CONTROL_HYBRID **)(param_1 + 0x138));
              PmQueryStorageProperty(param_1,1,0x20,(void **)(param_1 + 0x140));
              PmQueryStorageProperty(param_1,0x39,0x108,(void **)(param_1 + 0x148));
              PmQueryStorageProperty(param_1,5,0x18,(void **)(param_1 + 0x150));
              iVar7 = FsRtlGetVirtualDiskNestingLevel
                                (*(undefined8 *)(param_1 + 0x10),param_1 + 0x30,0);
              if (iVar7 < 0) {
                *(undefined4 *)(param_1 + 0x30) = 0;
              }
              uVar6 = PmConstructDeviceLocation(param_1,param_2);
              if (-1 < (int)uVar6) {
                PmGetDevicePropertyString
                          (*(_DEVICE_OBJECT **)(param_1 + 0x18),
                           (_DEVPROPKEY *)&DEVPKEY_Device_Parent,
                           (_UNICODE_STRING *)(param_1 + 0x1d0));
                uVar6 = IoRegisterDeviceInterface
                                  (*(undefined8 *)(param_1 + 0x18),&GUID_DEVINTERFACE_DISK,0,
                                   param_1 + 0x1e0);
                if ((-1 < (int)uVar6) &&
                   (uVar6 = IoRegisterDeviceInterface
                                      (*(undefined8 *)(param_1 + 0x18),
                                       &GUID_DEVINTERFACE_HIDDEN_DISK,0,param_1 + 0x1f0),
                   -1 < (int)uVar6)) {
                  if (*(char *)(lVar2 + 0xa9) != '\0') {
                    PmInitializePartitionTableCache(param_1);
                    PmInitializeAttributesTableCache(param_1);
                    PmInitializeSnapshotDataCache(param_1);
                  }
                  uVar6 = IoWMIRegistrationControl(*(undefined8 *)(param_1 + 8));
                  if (-1 < (int)uVar6) {
                    PmWmiCounterEnable((longlong *)(param_1 + 0x2d0));
                    uVar9 = 0;
                    PmWmiCounterDisable((longlong *)(param_1 + 0x2d0),'\0','\0');
                    cVar5 = PoEnergyEstimationEnabled();
                    if (cVar5 != '\0') {
                      PmPowerCounterEnable((longlong)param_1);
                    }
                    uVar8 = Feature_Partition_Manager_Passthrough__private_IsEnabledDeviceUsageNoInline
                                      ();
                    if ((int)uVar8 != 0) {
                      uVar6 = PmCheckPassthrough(param_1,uVar9);
                      if ((int)uVar6 < 0) goto LAB_14000beeb;
                      if (((byte)param_1[0x210] & 0x40) != 0) {
                        uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x70);
                        *(uint *)(param_1 + 0x200) = *(uint *)(param_1 + 0x200) | 1;
                        KeReleaseSpinLock(param_1 + 0x70,uVar4);
                        goto LAB_14000beeb;
                      }
                    }
                    uVar8 = PmEnforceService((longlong)param_1);
                    if ((char)uVar8 != '\0') {
                      uVar9 = 0;
                      uVar6 = PmGetDriveLayoutEx(param_1,(undefined8 *)0x0);
                      if (((int)uVar6 < 0) ||
                         (((*(uint *)(param_1 + 0x200) >> 0xd & 1) != 0 &&
                          (uVar6 = PmApplyServiceProtection(param_1), (int)uVar6 < 0))))
                      goto LAB_14000beeb;
                    }
                    iVar7 = IoCreateArcName(*(undefined8 *)(param_1 + 8));
                    if (-1 < iVar7) {
                      uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x70);
                      *(uint *)(param_1 + 0x200) = *(uint *)(param_1 + 0x200) | 0x1000;
                      uVar9 = CONCAT71((int7)((ulonglong)uVar9 >> 8),uVar4);
                      KeReleaseSpinLock(param_1 + 0x70);
                    }
                    uVar6 = PmSetInitialDiskAttributes(param_1,uVar9);
                    if (-1 < (int)uVar6) {
                      KeWaitForSingleObject(param_1 + 0x38,0,0,0);
                      PmSetSystemCriticalFlag(param_1);
                      KeAcquireSpinLockRaiseToDpc(param_1 + 0x70);
                      if ((param_1[0x25c] != (_DEVICE_EXTENSION)0x0) &&
                         (*(char *)(lVar2 + 0xa8) == '\0')) {
                        *(uint *)(param_1 + 0x200) = *(uint *)(param_1 + 0x200) & 0xfffff7ff;
                      }
                      *(uint *)(param_1 + 0x200) = *(uint *)(param_1 + 0x200) | 1;
                      KeReleaseSpinLock(param_1 + 0x70);
                      PmGetDriveLayoutEx(param_1,(undefined8 *)0x0);
                      if ((param_1[0x25c] != (_DEVICE_EXTENSION)0x0) &&
                         (*(char *)(lVar2 + 0xa8) == '\0')) {
                        lVar2 = *(longlong *)(param_2 + 0xb8);
                        memset((undefined2 *)(lVar2 + -0x48),0,0x48);
                        *(undefined2 *)(lVar2 + -0x48) = 0x161b;
                        *(undefined1 *)(lVar2 + -0x40) = 1;
                        *(undefined4 *)(lVar2 + -0x38) = 4;
                        *(undefined4 *)(param_2 + 0x30) = 0xc00000bb;
                        *(undefined8 *)(param_2 + 0x38) = 0;
                        IoSynchronousCallDriver(*(undefined8 *)(param_1 + 0x10),param_2);
                      }
                      KeReleaseMutex(param_1 + 0x38,0);
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
LAB_14000beeb:
  *(uint *)(param_2 + 0x30) = uVar6;
  IofCompleteRequest(param_2,0);
  IoReleaseRemoveLockEx(param_1 + 0x78,param_2,0x20);
  return uVar6;
}



===== PmStartDeviceWorkItem @ 14000bf50 =====

/* void __cdecl PmStartDeviceWorkItem(void * __ptr64,void * __ptr64,struct _IO_WORKITEM * __ptr64)
    */

void __cdecl PmStartDeviceWorkItem(void *param_1,void *param_2,_IO_WORKITEM *param_3)

{
  IoFreeWorkItem(param_3);
  PmStartDeviceInternal(*(_DEVICE_EXTENSION **)((longlong)param_1 + 0x40),param_2);
  return;
}



===== Feature_PartmgrRemovalRelations_Fix__private_IsEnabledDeviceUsageNoInline @ 14000bf90 =====

ulonglong Feature_PartmgrRemovalRelations_Fix__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_PartmgrRemovalRelations_Fix__private_featureState;
  if ((Feature_PartmgrRemovalRelations_Fix__private_featureState & 0x10) == 0) {
    uVar1 = Feature_PartmgrRemovalRelations_Fix__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_PartmgrRemovalRelations_Fix__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_PartmgrRemovalRelations_Fix__private_IsEnabledFallback @ 14000bfc8 =====

void Feature_PartmgrRemovalRelations_Fix__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_PartmgrRemovalRelations_Fix__private_descriptor);
  return;
}



===== McGenControlCallbackV2 @ 14000bff0 =====

void McGenControlCallbackV2
               (undefined8 param_1,int param_2,undefined1 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,longlong param_7)

{
  uint *puVar1;
  ulonglong uVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  
  if (param_7 != 0) {
    if (param_2 == 0) {
      *(undefined4 *)(param_7 + 0x24) = 0;
      *(undefined1 *)(param_7 + 0x28) = 0;
      *(undefined8 *)(param_7 + 0x10) = 0;
      *(undefined8 *)(param_7 + 0x18) = 0;
      if (*(ushort *)(param_7 + 0x2a) != 0) {
        memset(*(void **)(param_7 + 0x30),0,
               (longlong)((int)(*(ushort *)(param_7 + 0x2a) - 1) / 0x20 + 1) << 2);
      }
    }
    else if (param_2 == 1) {
      *(undefined1 *)(param_7 + 0x28) = param_3;
      uVar6 = 0;
      *(undefined8 *)(param_7 + 0x18) = param_5;
      *(undefined8 *)(param_7 + 0x10) = param_4;
      *(undefined4 *)(param_7 + 0x24) = 1;
      if (*(short *)(param_7 + 0x2a) != 0) {
        do {
          uVar2 = *(ulonglong *)(*(longlong *)(param_7 + 0x38) + uVar6 * 8);
          if (((*(byte *)(param_7 + 0x28) < *(byte *)(uVar6 + *(longlong *)(param_7 + 0x40))) &&
              (*(byte *)(param_7 + 0x28) != 0)) ||
             ((uVar2 != 0 &&
              (((*(ulonglong *)(param_7 + 0x10) & uVar2) == 0 ||
               ((*(ulonglong *)(param_7 + 0x18) & uVar2) != *(ulonglong *)(param_7 + 0x18))))))) {
            bVar3 = false;
          }
          else {
            bVar3 = true;
          }
          uVar4 = 1 << ((byte)uVar6 & 0x1f);
          puVar1 = (uint *)(*(longlong *)(param_7 + 0x30) + (uVar6 >> 5) * 4);
          uVar5 = *puVar1;
          if (bVar3) {
            uVar4 = uVar4 | uVar5;
          }
          else {
            uVar4 = ~uVar4 & uVar5;
          }
          *puVar1 = uVar4;
          uVar5 = (int)uVar6 + 1;
          uVar6 = (ulonglong)uVar5;
        } while (uVar5 < *(ushort *)(param_7 + 0x2a));
      }
    }
  }
  return;
}



===== McGenEventRegister_EtwRegister @ 14000c100 =====

void McGenEventRegister_EtwRegister(void)

{
  if (Microsoft_Windows_Partition_Context == 0) {
    EtwRegister(&Microsoft_Windows_Partition,McGenControlCallbackV2,
                &Microsoft_Windows_Partition_Context,&Microsoft_Windows_Partition_Context);
  }
  return;
}



===== McGenEventUnregister_EtwUnregister @ 14000c140 =====

undefined8 McGenEventUnregister_EtwUnregister(void)

{
  undefined8 uVar1;
  
  if (Microsoft_Windows_Partition_Context == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    Microsoft_Windows_Partition_Context = 0;
  }
  return uVar1;
}



===== McTemplateK0qp_EtwWriteTransfer @ 14000c174 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qp_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_78 [32];
  undefined8 local_48 [2];
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_38 = local_res20;
  local_2c = 0;
  local_28 = &param_5;
  local_30 = 4;
  local_1c = 0;
  local_20 = 8;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,0,3,local_48);
  return;
}



===== McTemplateK0qpd_EtwWriteTransfer @ 14000c1e8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qpd_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined4 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_30 = 8;
  local_48 = local_res20;
  local_40 = 4;
  local_38 = &param_5;
  local_20 = 4;
  local_28 = &param_6;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&QueryRemovalRelationsWait,0,4,local_58);
  return;
}



===== McTemplateK0qq_EtwWriteTransfer @ 14000c268 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_78 [32];
  undefined8 local_48 [2];
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_38 = local_res20;
  local_28 = &param_5;
  local_2c = 0;
  local_30 = 4;
  local_1c = 0;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(4,param_2,param_3,3,local_48);
  return;
}



===== McTemplateK0qqq_EtwWriteTransfer @ 14000c2d4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qqq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined4 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = local_res20;
  local_38 = &param_5;
  local_40 = 4;
  local_28 = &param_6;
  local_30 = 4;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&ControlComplete,param_3,4,local_58);
  return;
}



===== PartitionOverlapIo @ 14000c350 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int PartitionOverlapIo(int param_1,longlong param_2,undefined4 param_3,longlong param_4,
                      longlong *param_5)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  code *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  char cVar8;
  int iVar9;
  longlong lVar10;
  longlong lVar11;
  longlong *plVar12;
  longlong lVar13;
  undefined1 *puVar14;
  longlong *plVar15;
  undefined1 auStack_78 [8];
  undefined1 auStack_70 [24];
  longlong local_58;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_78;
  iVar9 = 0;
  local_48 = 0;
  uStack_40 = 0;
  lVar1 = param_5[1];
  puVar2 = *(undefined8 **)(lVar1 + 0xb8);
  if (param_1 != 1) {
    if (param_1 == 2) {
      lVar10 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(*param_5 + 8) >> 8),
                                      *(char *)(*(longlong *)(*param_5 + 8) + 0x4c) + '\x01'),0);
      puVar14 = auStack_78;
      if (lVar10 == 0) {
        iVar9 = -0x3fffff66;
      }
      else {
        lVar13 = ((ulonglong)*(uint *)(*(longlong *)(lVar1 + 8) + 0x2c) - puVar2[3]) +
                 *(longlong *)(*(longlong *)(lVar1 + 8) + 0x20) + param_4;
        local_58 = lVar10;
        lVar11 = IoAllocateMdl(lVar13,param_3,0,0);
        *(longlong *)(lVar10 + 8) = lVar11;
        if (lVar11 == 0) {
          iVar9 = -0x3fffff66;
        }
        else {
          IoBuildPartialMdl(*(undefined8 *)(lVar1 + 8),lVar11,lVar13,param_3);
          lVar11 = *(longlong *)(lVar10 + 0xb8);
          *(uint *)(lVar10 + 0x10) = *(uint *)(lVar10 + 0x10) | *(uint *)(lVar1 + 0x10) & 2;
          *(undefined8 *)(lVar10 + 0x98) = *(undefined8 *)(lVar1 + 0x98);
          uVar3 = *(undefined8 *)(lVar1 + 0xc0);
          *(char *)(lVar10 + 0x43) = *(char *)(lVar10 + 0x43) + -1;
          *(undefined8 *)(lVar10 + 0xc0) = uVar3;
          *(longlong *)(lVar10 + 0xb8) = lVar11 + -0x48;
          uVar3 = puVar2[1];
          *(undefined8 *)(lVar11 + -0x90) = *puVar2;
          *(undefined8 *)(lVar11 + -0x88) = uVar3;
          uVar3 = puVar2[3];
          *(undefined8 *)(lVar11 + -0x80) = puVar2[2];
          *(undefined8 *)(lVar11 + -0x78) = uVar3;
          uVar5 = *(undefined4 *)((longlong)puVar2 + 0x24);
          uVar6 = *(undefined4 *)(puVar2 + 5);
          uVar7 = *(undefined4 *)((longlong)puVar2 + 0x2c);
          *(undefined4 *)(lVar11 + -0x70) = *(undefined4 *)(puVar2 + 4);
          *(undefined4 *)(lVar11 + -0x6c) = uVar5;
          *(undefined4 *)(lVar11 + -0x68) = uVar6;
          *(undefined4 *)(lVar11 + -100) = uVar7;
          *(undefined8 *)(lVar11 + -0x60) = puVar2[6];
          *(undefined1 *)(lVar11 + -0x8d) = 0;
          *(undefined4 *)(lVar11 + -0x88) = param_3;
          *(longlong *)(lVar11 + -0x78) =
               (*(longlong *)(param_2 + 0x18) - *(longlong *)(param_2 + 0x10)) + param_4;
          cVar8 = IoIsActivityTracingEnabled();
          if (cVar8 != '\0') {
            iVar9 = IoGetActivityIdIrp(lVar1,&local_48);
            if (-1 < iVar9) {
              IoSetActivityIdIrp(lVar10,&local_48);
            }
          }
          iVar9 = IoPropagateIrpExtensionEx
                            (lVar1,lVar10,param_4 - *(longlong *)(lVar11 + -0x78),0xffffffff);
          puVar14 = auStack_78;
          if (-1 < iVar9) {
            lVar11 = *(longlong *)(lVar10 + 0xb8);
            plVar15 = (longlong *)(lVar10 + 0xa8);
            *(longlong *)(lVar11 + -8) = lVar1;
            *(code **)(lVar11 + -0x10) = PartitionChildIoCompletion;
            *(undefined1 *)(lVar11 + -0x45) = 0xe0;
            plVar12 = *(longlong **)(lVar1 + 0xb0);
            if (*plVar12 != lVar1 + 0xa8) {
              pcVar4 = (code *)swi(0x29);
              plVar12 = (longlong *)(*pcVar4)(3);
              puVar14 = auStack_70;
            }
            *plVar15 = lVar1 + 0xa8;
            *(longlong **)(lVar10 + 0xb0) = plVar12;
            *plVar12 = (longlong)plVar15;
            *(longlong **)(lVar1 + 0xb0) = plVar15;
            goto LAB_14000c3b4;
          }
        }
        puVar14 = auStack_78;
        if (*(longlong *)(lVar10 + 8) != 0) {
          IoFreeMdl();
        }
        IoFreeIrp(lVar10);
      }
      goto LAB_14000c3b4;
    }
    if ((param_1 != 3) && (puVar14 = auStack_78, param_1 == 4)) goto LAB_14000c3b4;
  }
  iVar9 = -0x3ffffff3;
  puVar14 = auStack_78;
LAB_14000c3b4:
  *(undefined8 *)(puVar14 + -8) = 0x14000c3c3;
  return iVar9;
}



===== PmRedirectRequest @ 14000c5b0 =====

void PmRedirectRequest(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined1 uVar4;
  longlong *plVar5;
  undefined8 *puVar6;
  undefined1 *puVar7;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x70);
  plVar2 = (longlong *)(param_1 + 0x290);
  if ((longlong *)*plVar2 == plVar2) {
    *(uint *)(param_1 + 0x200) = *(uint *)(param_1 + 0x200) | 0x20;
    PmQueueNotificationWorkItem(param_1);
  }
  puVar7 = auStack_28;
  plVar5 = (longlong *)(param_2 + 0xa8);
  pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
  *pbVar1 = *pbVar1 | 1;
  puVar6 = *(undefined8 **)(param_1 + 0x298);
  if ((longlong *)*puVar6 != plVar2) {
    puVar6 = (undefined8 *)0x3;
    pcVar3 = (code *)swi(0x29);
    plVar5 = (longlong *)(*pcVar3)();
    puVar7 = auStack_20;
  }
  plVar5[1] = (longlong)puVar6;
  *plVar5 = (longlong)plVar2;
  *puVar6 = plVar5;
  *(longlong **)(param_1 + 0x298) = plVar5;
  *(undefined8 *)(puVar7 + -8) = 0x14000c642;
  KeReleaseSpinLock(param_1 + 0x70,uVar4);
  return;
}



===== PmUpdateOffline @ 14000c66c =====

void PmUpdateOffline(longlong param_1,char param_2)

{
  uint uVar1;
  undefined8 *puVar2;
  
  for (puVar2 = *(undefined8 **)(param_1 + 0x380); puVar2 != (undefined8 *)(param_1 + 0x380);
      puVar2 = (undefined8 *)*puVar2) {
    uVar1 = *(uint *)(puVar2 + -0xd) | 0x80;
    if (param_2 == '\0') {
      uVar1 = *(uint *)(puVar2 + -0xd) & 0xffffff7f;
    }
    *(uint *)(puVar2 + -0xd) = uVar1;
  }
  return;
}



===== RtlStringCbCatW @ 14000c6a0 =====

uint RtlStringCbCatW(short *param_1,undefined8 param_2,longlong param_3)

{
  short sVar1;
  uint uVar2;
  short *psVar3;
  longlong lVar4;
  short *psVar5;
  ulonglong uVar6;
  longlong lVar7;
  longlong lVar8;
  
  lVar7 = 0x80;
  psVar3 = param_1;
  do {
    if (*psVar3 == 0) break;
    psVar3 = psVar3 + 1;
    lVar7 = lVar7 + -1;
  } while (lVar7 != 0);
  uVar6 = -(ulonglong)(lVar7 != 0) & 0x80U - lVar7;
  uVar2 = ~-(uint)(lVar7 != 0) & 0xc000000d;
  if (lVar7 != 0) {
    psVar3 = param_1 + uVar6;
    lVar7 = 0x80 - uVar6;
    if (lVar7 != 0) {
      lVar4 = 0x7ffffffe;
      lVar8 = param_3 - (longlong)psVar3;
      do {
        if ((lVar4 == 0) || (sVar1 = *(short *)(lVar8 + (longlong)psVar3), sVar1 == 0)) break;
        *psVar3 = sVar1;
        lVar4 = lVar4 + -1;
        psVar3 = psVar3 + 1;
        lVar7 = lVar7 + -1;
      } while (lVar7 != 0);
    }
    psVar5 = psVar3 + -1;
    if (lVar7 != 0) {
      psVar5 = psVar3;
    }
    *psVar5 = 0;
    uVar2 = ~-(uint)(lVar7 != 0) & 0x80000005;
  }
  return uVar2;
}



===== RtlStringCbPrintfW @ 14000c748 =====

undefined8
RtlStringCbPrintfW(wchar_t *param_1,ulonglong param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  ulonglong uVar2;
  undefined8 local_res20;
  
  uVar2 = param_2 >> 1;
  if (uVar2 - 1 < 0x7fffffff) {
    local_res20 = param_4;
    uVar1 = RtlStringVPrintfWorkerW(param_1,uVar2,param_3,(wchar_t *)param_3,(va_list)&local_res20);
  }
  else {
    uVar1 = 0xc000000d;
    if (uVar2 != 0) {
      *param_1 = L'\0';
    }
  }
  return uVar1;
}



===== _tlgDefineProvider_annotation__TlgPmTelemetryProv @ 14000c798 =====

void _tlgDefineProvider_annotation__TlgPmTelemetryProv(void)

{
  return;
}



===== wil_details_FeatureDescriptors_SkipPadding @ 14000c7a4 =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_140018867 < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_RecordCachedUsage @ 14000c7cc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_RecordCachedUsage(undefined4 param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  bool bVar6;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  short local_44 [2];
  undefined4 local_40 [10];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  uVar2 = *param_2;
  do {
    LOCK();
    uVar4 = *param_2;
    bVar6 = uVar2 == uVar4;
    if (bVar6) {
      *param_2 = uVar2 & 0xffc0401e;
    }
    else {
      uVar2 = uVar4;
    }
    UNLOCK();
  } while (!bVar6);
  uVar3 = uVar2 >> 1 & 0xf;
  uVar4 = 0;
  if (uVar3 != 0) {
    uVar4 = param_2[1];
    do {
      LOCK();
      uVar1 = param_2[1];
      bVar6 = uVar4 == uVar1;
      if (bVar6) {
        param_2[1] = uVar4 | uVar3;
      }
      else {
        uVar4 = uVar1;
      }
      UNLOCK();
    } while (!bVar6);
    uVar4 = uVar3 & ~uVar4;
  }
  puVar5 = &local_48;
  if ((uVar4 & 1) != 0) {
    puVar5 = local_40;
    local_44[0] = 2;
    local_44[1] = 1;
    local_48 = param_1;
  }
  if ((uVar4 & 2) != 0) {
    *puVar5 = param_1;
    puVar5[1] = 0x10006;
    puVar5 = puVar5 + 2;
  }
  if ((uVar4 & 4) != 0) {
    *puVar5 = param_1;
    puVar5[1] = 0x10003;
    puVar5 = puVar5 + 2;
  }
  if (7 < uVar4) {
    *puVar5 = param_1;
    puVar5[1] = 0x10007;
    puVar5 = puVar5 + 2;
  }
  if ((uVar2 >> 5 & 0x1ff) != 0) {
    *puVar5 = param_1;
    *(ushort *)((longlong)puVar5 + 6) = (ushort)(uVar2 >> 5) & 0x1ff;
    *(ushort *)(puVar5 + 1) = ((ushort)(uVar2 >> 0xe) & 1) << 2;
    puVar5 = puVar5 + 2;
  }
  if ((uVar2 >> 0xf & 0x7f) != 0) {
    *puVar5 = param_1;
    *(ushort *)((longlong)puVar5 + 6) = (ushort)(uVar2 >> 0xf) & 0x7f;
    *(ushort *)(puVar5 + 1) = ((ushort)(uVar2 >> 0x16) & 1) * 4 + 1;
    puVar5 = puVar5 + 2;
  }
  if (0 < (longlong)puVar5 - (longlong)&local_48 >> 3) {
    wil_details_RecordFeatureUsageCallback();
  }
  return;
}



===== wil_details_RecordFeatureUsageReporting @ 14000c920 =====

void wil_details_RecordFeatureUsageReporting(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uStack0000000000000028;
  undefined2 in_stack_0000002c;
  undefined2 in_stack_0000002e;
  
  iVar2 = g_wil_details_featureUsageCached;
  piVar1 = (int *)CONCAT26(in_stack_0000002e,CONCAT24(in_stack_0000002c,uStack0000000000000028));
  if (*piVar1 != 0) {
    LOCK();
    g_wil_details_featureUsageCached = 1;
    UNLOCK();
    if ((iVar2 == 0) && (g_wil_details_featureUsageProvider != 0)) {
      RtlArmFeatureUsageProviderFlushNotification(g_wil_details_featureUsageProvider,1);
    }
  }
  if (piVar1[1] != 0) {
    in_stack_0000002c = (undefined2)piVar1[2];
    in_stack_0000002e = (undefined2)piVar1[1];
    uStack0000000000000028 = param_1;
    RtlRecordFeatureUsage(&uStack0000000000000028,1);
  }
  return;
}



===== PmBuildUniqueId @ 14000c9a4 =====

/* long __cdecl PmBuildUniqueId(struct _DEVICE_EXTENSION * __ptr64,struct _PARTITION_EXTENSION *
   __ptr64) */

long __cdecl PmBuildUniqueId(_DEVICE_EXTENSION *param_1,_PARTITION_EXTENSION *param_2)

{
  undefined8 *_Dst;
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined1 uVar4;
  undefined2 *puVar5;
  uint uVar6;
  long lVar7;
  
  lVar7 = 0;
  if ((*(int *)(param_2 + 0xa8) == 1) || ((*(uint *)(param_1 + 0x200) >> 0xe & 1) != 0)) {
    uVar6 = 0x18;
  }
  else if ((*(uint *)(*(longlong *)(param_1 + 8) + 0x34) & 1) == 0) {
    uVar6 = 0xc;
  }
  else {
    uVar6 = (uint)*(ushort *)(param_2 + 0x30);
  }
  puVar5 = (undefined2 *)ExAllocatePool2(0x42,uVar6 + 2,0x46426d50);
  if (puVar5 == (undefined2 *)0x0) {
    lVar7 = -0x3fffff66;
  }
  else {
    _Dst = (undefined8 *)(puVar5 + 1);
    if ((*(int *)(param_2 + 0xa8) == 1) || ((*(uint *)(param_1 + 0x200) >> 0xe & 1) != 0)) {
      uVar2 = *(undefined8 *)(param_2 + 0x40);
      uVar3 = *(undefined8 *)(param_2 + 0x48);
      *_Dst = 0x3a44493a4f494d44;
      *(undefined8 *)(puVar5 + 5) = uVar2;
      *(undefined8 *)(puVar5 + 9) = uVar3;
    }
    else if ((*(uint *)(*(longlong *)(param_1 + 8) + 0x34) & 1) == 0) {
      *(undefined4 *)_Dst = *(undefined4 *)(param_2 + 0xd0);
      *(undefined8 *)(puVar5 + 3) = *(undefined8 *)(param_2 + 0xb0);
    }
    else {
      memmove(_Dst,*(void **)(param_2 + 0x38),(ulonglong)*(ushort *)(param_2 + 0x30));
    }
    *puVar5 = (short)uVar6;
    uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x70);
    lVar1 = *(longlong *)(param_2 + 0x50);
    *(undefined2 **)(param_2 + 0x50) = puVar5;
    KeReleaseSpinLock(param_1 + 0x70,uVar4);
    if (lVar1 != 0) {
      ExFreePoolWithTag(lVar1,0);
    }
  }
  return lVar7;
}



===== PmSetPartitionFlags @ 14000cae8 =====

/* void __cdecl PmSetPartitionFlags(struct _PARTITION_EXTENSION * __ptr64,struct
   _DRIVE_LAYOUT_INFORMATION_EX * __ptr64) */

void __cdecl
PmSetPartitionFlags(_PARTITION_EXTENSION *param_1,_DRIVE_LAYOUT_INFORMATION_EX *param_2)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  ulonglong uVar5;
  
  uVar5 = 0;
  if (*(char *)(*(longlong *)(param_1 + 0x18) + 0x25c) != '\0') {
    if (*(int *)(param_1 + 0xa8) == 0) {
      puVar2 = *(uint **)(*(longlong *)(PmControlObject + 0x40) + 0xc0);
      uVar5 = 0;
      uVar1 = *puVar2;
      if (uVar1 != 0) {
        do {
          puVar3 = puVar2 + uVar5 * 7 + 1;
          if (((*puVar3 == 0) && (puVar3[2] == *(uint *)(param_2 + 8))) &&
             (puVar3[1] == *(uint *)(param_1 + 0xc0))) goto LAB_14000cbc0;
          uVar4 = (int)uVar5 + 1;
          uVar5 = (ulonglong)uVar4;
        } while (uVar4 < uVar1);
      }
    }
    else if (*(int *)(param_1 + 0xa8) == 1) {
      puVar2 = *(uint **)(*(longlong *)(PmControlObject + 0x40) + 0xc0);
      uVar1 = *puVar2;
      if (uVar1 != 0) {
        do {
          puVar3 = puVar2 + uVar5 * 7 + 1;
          if (((*puVar3 == 1) && (*(longlong *)(puVar3 + 2) == *(longlong *)(param_2 + 8))) &&
             ((*(longlong *)(puVar3 + 4) == *(longlong *)(param_2 + 0x10) &&
              (puVar3[1] == *(uint *)(param_1 + 0xc0))))) {
LAB_14000cbc0:
            *(uint *)(*(longlong *)(param_1 + 8) + 0x30) =
                 puVar3[6] & 0xffffffbf | *(uint *)(*(longlong *)(param_1 + 8) + 0x30);
            return;
          }
          uVar4 = (int)uVar5 + 1;
          uVar5 = (ulonglong)uVar4;
        } while (uVar4 < uVar1);
      }
    }
  }
  return;
}



===== PmDeletePartition @ 14000cbe8 =====

void PmDeletePartition(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 uVar4;
  code *pcVar5;
  undefined1 *puVar6;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  puVar6 = auStack_28;
  do {
    plVar1 = *(longlong **)(param_1 + 0x138);
    if (plVar1 == (longlong *)(param_1 + 0x138)) {
LAB_14000cc34:
      *(undefined8 *)(puVar6 + -8) = 0x14000cc3f;
      RtlFreeUnicodeString(param_1 + 0x30);
      lVar2 = *(longlong *)(param_1 + 0x50);
      if (lVar2 != 0) {
        *(undefined8 *)(puVar6 + -8) = 0x14000cc56;
        ExFreePoolWithTag(lVar2,0);
      }
      uVar4 = *(undefined8 *)(param_1 + 0x10);
      *(undefined8 *)(puVar6 + -8) = 0x14000cc66;
      ObfDereferenceObject(uVar4);
      uVar4 = *(undefined8 *)(param_1 + 8);
      *(undefined8 *)(puVar6 + -8) = 0x14000cc76;
      IoDeleteDevice(uVar4);
      return;
    }
    lVar2 = *plVar1;
    if (((longlong *)*(longlong *)(lVar2 + 8) != plVar1) ||
       (plVar3 = (longlong *)plVar1[1], (longlong *)*plVar3 != plVar1)) {
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      puVar6 = auStack_20;
      goto LAB_14000cc34;
    }
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    ExFreePoolWithTag();
  } while( true );
}



===== PmEnforceService @ 14000cc90 =====

ulonglong PmEnforceService(longlong param_1)

{
  ulonglong in_RAX;
  ulonglong uVar1;
  
  uVar1 = in_RAX & 0xffffffffffffff00;
  if ((*(char *)(*(longlong *)(PmControlObject + 0x40) + 0xaa) != '\0') &&
     (uVar1 = 0, (*(uint *)(*(longlong *)(param_1 + 8) + 0x34) & 0x40001) == 0)) {
    uVar1 = 1;
  }
  return uVar1;
}



===== PmGrowPartition @ 14000ccc4 =====

uint PmGrowPartition(_DEVICE_EXTENSION *param_1,SC_DISK_LAYOUT *param_2,int *param_3,
                    longlong param_4)

{
  undefined1 uVar1;
  longlong lVar2;
  _DEVICE_EXTENSION *p_Var3;
  _DEVICE_EXTENSION *p_Var4;
  uint uVar5;
  ulonglong uVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  longlong lVar10;
  uint uVar11;
  
  uVar6 = 0;
  while( true ) {
    uVar11 = (uint)uVar6;
    if (*(uint *)(param_2 + 4) <= uVar11) {
      return 0xc000000e;
    }
    if (*(int *)(param_2 + uVar6 * 0x90 + 0x48) == *param_3) break;
    uVar6 = (ulonglong)(uVar11 + 1);
  }
  lVar10 = *(longlong *)(param_3 + 2);
  if ((*(int *)param_2 != 1) ||
     (lVar7 = *(longlong *)(param_2 + 0x20) + *(longlong *)(param_2 + 0x18),
     param_4 < *(longlong *)(param_2 + 0x20) + *(longlong *)(param_2 + 0x18))) {
    lVar7 = param_4;
  }
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x70);
  for (p_Var3 = *(_DEVICE_EXTENSION **)(param_1 + 0x380); p_Var3 != param_1 + 0x380;
      p_Var3 = *(_DEVICE_EXTENSION **)p_Var3) {
    if (((*(uint *)(p_Var3 + -0x68) & 4) == 0) && (*(int *)(p_Var3 + 0x30) == *param_3)) {
      lVar9 = *(longlong *)(p_Var3 + 0x20);
      lVar2 = PartitionOffset((longlong)(p_Var3 + -0x90),'\x01');
      if (lVar2 != lVar9) {
        uVar11 = 0xc00000bb;
        goto LAB_14000cf80;
      }
      lVar2 = *(longlong *)(p_Var3 + 0x28);
      lVar7 = (lVar7 - lVar2) - lVar9;
      if (((lVar10 != 0x7fffffffffffffff) && (lVar7 < *(longlong *)(param_3 + 2))) ||
         ((lVar8 = *(longlong *)(param_3 + 2), lVar8 < 0 && (lVar2 + lVar8 < 1))))
      goto LAB_14000cdb5;
      if (lVar10 == 0x7fffffffffffffff) {
        lVar8 = lVar7;
      }
      lVar8 = lVar8 + lVar2;
      p_Var4 = *(_DEVICE_EXTENSION **)(param_1 + 0x380);
      goto LAB_14000cded;
    }
  }
  uVar11 = 0xc000000e;
LAB_14000cf80:
  KeReleaseSpinLock(param_1 + 0x70,uVar1);
  return uVar11;
LAB_14000cded:
  if (p_Var4 == param_1 + 0x380) goto LAB_14000ce22;
  if (((*(uint *)(p_Var4 + -0x68) & 4) == 0) && (lVar9 < *(longlong *)(p_Var4 + 0x20))) {
    lVar7 = *(longlong *)(p_Var4 + 0x20) - *(longlong *)(p_Var3 + 0x20);
    if (lVar10 == 0x7fffffffffffffff) {
      if (lVar7 <= lVar8) {
        lVar8 = lVar7;
      }
    }
    else if (lVar7 < lVar8) goto LAB_14000cdb5;
    goto LAB_14000ce22;
  }
  p_Var4 = *(_DEVICE_EXTENSION **)p_Var4;
  goto LAB_14000cded;
LAB_14000cdb5:
  uVar11 = 0xc000000d;
  goto LAB_14000cf80;
LAB_14000ce22:
  if (*(int *)param_2 == 0) {
    p_Var4 = *(_DEVICE_EXTENSION **)(p_Var3 + 0x20);
    for (uVar5 = uVar11 & 0xfffffffc; uVar5 < *(uint *)(param_2 + 4); uVar5 = uVar5 + 1) {
      if (((param_2[(ulonglong)uVar5 * 0x90 + 0x50] == (SC_DISK_LAYOUT)0x5) ||
          (param_2[(ulonglong)uVar5 * 0x90 + 0x50] == (SC_DISK_LAYOUT)0xf)) &&
         ((longlong)p_Var4 < *(longlong *)(param_2 + (ulonglong)uVar5 * 0x90 + 0x38))) {
        lVar7 = *(longlong *)(param_2 + (ulonglong)uVar5 * 0x90 + 0x38) - (longlong)p_Var4;
        if (lVar10 == 0x7fffffffffffffff) {
          if (lVar7 <= lVar8) {
            lVar8 = lVar7;
          }
        }
        else if (lVar7 < lVar8) goto LAB_14000cdb5;
      }
    }
  }
  *(longlong *)(param_2 + uVar6 * 0x90 + 0x40) = lVar8;
  param_2[uVar6 * 0x90 + 0x4c] = (SC_DISK_LAYOUT)0x1;
  if ((*(int *)param_2 == 0) && (3 < uVar11)) {
    uVar11 = uVar11 & 0xfffffffc;
    lVar10 = *(longlong *)(p_Var3 + 0x20) + -1 + lVar8;
    while (uVar11 = uVar11 - 1, -1 < (int)uVar11) {
      uVar6 = (ulonglong)uVar11;
      p_Var4 = (_DEVICE_EXTENSION *)(uVar6 * 0x12);
      if ((param_2[uVar6 * 0x90 + 0x50] == (SC_DISK_LAYOUT)0x5) ||
         (param_2[uVar6 * 0x90 + 0x50] == (SC_DISK_LAYOUT)0xf)) {
        if (lVar10 < *(longlong *)(param_2 + uVar6 * 0x90 + 0x40) + -1 +
                     *(longlong *)(param_2 + uVar6 * 0x90 + 0x38)) break;
        param_2[uVar6 * 0x90 + 0x4c] = (SC_DISK_LAYOUT)0x1;
        *(longlong *)(param_2 + uVar6 * 0x90 + 0x40) =
             (lVar10 - *(longlong *)(param_2 + uVar6 * 0x90 + 0x38)) + 1;
      }
    }
  }
  KeReleaseSpinLock(param_1 + 0x70,CONCAT71((int7)((ulonglong)p_Var4 >> 8),uVar1));
  uVar11 = PmWritePartitionTable(*(_DEVICE_OBJECT **)(param_1 + 8),param_2);
  if ((int)uVar11 < 0) {
    return uVar11;
  }
  PmInvalidatePartitionTableCache((longlong)param_1);
  KeAcquireSpinLockRaiseToDpc(param_1 + 0x70);
  *(uint *)(p_Var3 + -0x68) = *(uint *)(p_Var3 + -0x68) | 0x10;
  *(longlong *)(p_Var3 + 0x28) = lVar8;
  PmQueueNotificationWorkItem((longlong)param_1);
  KeReleaseSpinLock(param_1 + 0x70);
  uVar11 = PmGetDriveLayoutEx(param_1,(undefined8 *)0x0);
  return uVar11;
}



===== PmInitializePartitionTableCache @ 14000cfc0 =====

uint PmInitializePartitionTableCache(_DEVICE_EXTENSION *param_1)

{
  longlong lVar1;
  undefined1 uVar2;
  uint uVar3;
  uint uVar4;
  ulonglong uVar5;
  uint uVar6;
  uint local_res10 [2];
  longlong local_res18 [2];
  
  local_res18[0] = 0;
  local_res10[0] = 0;
  uVar3 = PmGetDeviceParameterBinary(param_1,L"PartitionTableCache",local_res18,local_res10);
  if ((int)uVar3 < 0) goto LAB_14000d097;
  if (0x2f < local_res10[0]) {
    uVar5 = (ulonglong)*(uint *)(local_res18[0] + 4) * 0x90;
    if (0xffffffff < uVar5) {
      uVar3 = 0xc0000095;
      goto LAB_14000d097;
    }
    uVar4 = (int)uVar5 + 0x30;
    uVar6 = 0xffffffff;
    if (uVar4 >= 0x30) {
      uVar6 = uVar4;
    }
    uVar3 = -(uint)(uVar4 < 0x30) & 0xc0000095;
    if (uVar4 < 0x30) goto LAB_14000d097;
    if (uVar6 <= local_res10[0]) {
      uVar5 = 0;
      if (*(uint *)(local_res18[0] + 4) != 0) {
        do {
          uVar6 = (int)uVar5 + 1;
          *(undefined4 *)(local_res18[0] + 0x48 + uVar5 * 0x90) = 0;
          uVar5 = (ulonglong)uVar6;
        } while (uVar6 < *(uint *)(local_res18[0] + 4));
      }
      uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x70);
      lVar1 = local_res18[0];
      local_res18[0] = 0;
      *(longlong *)(param_1 + 0x450) = lVar1;
      KeReleaseSpinLock(param_1 + 0x70,uVar2);
      goto LAB_14000d097;
    }
  }
  uVar3 = 0xc0000004;
LAB_14000d097:
  if (local_res18[0] != 0) {
    ExFreePoolWithTag(local_res18[0],0);
  }
  return uVar3;
}



===== PmIsEqualName @ 14000d0cc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool PmIsEqualName(uint *param_1,undefined8 param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined1 auStack_88 [32];
  char local_68 [80];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_88;
  uVar2 = 0;
  memset(local_68,0,0x4c);
  PmNameFromGuid(param_1,uVar2,local_68);
  lVar1 = RtlCompareMemory(local_68,param_2,0x48);
  return lVar1 == 0x48;
}



===== PmNameFromGuid @ 14000d154 =====

/* WARNING: Restarted to delay deadcode elimination for space: register */

void PmNameFromGuid(uint *param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  char *pcVar4;
  
  memset(param_3,0,0x48);
  sprintf_s(param_3,0x48,"%08x-%04x-%04x-%02x%02x%02x%02x%02x%02x%02x%02x",(ulonglong)*param_1);
  pcVar4 = param_3 + 0x46;
  uVar3 = 0x46;
  do {
    iVar1 = (int)uVar3;
    uVar2 = iVar1 - 2;
    *pcVar4 = param_3[uVar3 >> 1];
    pcVar4 = pcVar4 + -2;
    param_3[uVar3 >> 1] = '\0';
    uVar3 = (ulonglong)uVar2;
  } while (iVar1 != 3 && 0 < (int)uVar2);
  return;
}



===== PmPowerContextInitialization @ 14000d244 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl PmPowerContextInitialization(struct _DISK_POWER_CONTEXT * __ptr64,enum
   _DISK_DEVICEPOWER_TYPE) */

long __cdecl
PmPowerContextInitialization(_DISK_POWER_CONTEXT *param_1,_DISK_DEVICEPOWER_TYPE param_2)

{
  int iVar1;
  wchar_t *pwVar2;
  uint uVar3;
  _DISK_POWER_CONTEXT *p_Var4;
  ulonglong uVar5;
  undefined1 auStack_138 [32];
  ulong local_118 [2];
  void *local_110;
  void *local_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  void *pvStack_e8;
  undefined8 *local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  void *local_c0;
  undefined8 local_b8;
  undefined1 *puStack_b0;
  wchar_t *local_a8 [4];
  wchar_t *local_88;
  wchar_t *local_80;
  wchar_t *local_78;
  wchar_t *local_70;
  wchar_t *local_68;
  undefined1 local_58 [32];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_138;
  local_c0 = (void *)0x0;
  local_118[0] = 0;
  local_108 = (void *)0x0;
  local_110 = (void *)0x0;
  local_a8[0] = L"SmallRandomReadPowerMw";
  local_a8[1] = L"SmallRandomWritePowerMw";
  local_a8[2] = L"SmallSequentialReadPowerMw";
  local_a8[3] = L"SmallSequentialWritePowerMw";
  local_88 = L"LargeRandomReadPowerMw";
  local_80 = L"LargeRandomWritePowerMw";
  local_78 = L"LargeSequentialReadPowerMw";
  local_70 = L"LargeSequentialWritePowerMw";
  local_68 = L"FlushPowerMw";
  local_100 = 0;
  uStack_f8 = 0;
  local_b8 = 0;
  puStack_b0 = (undefined1 *)0x0;
  local_f0 = 0;
  pvStack_e8 = (void *)0x0;
  local_e0 = (undefined8 *)0x0;
  uStack_d8 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  if (param_2 == 0) {
    pwVar2 = 
    L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Power\\EnergyEstimation\\Storage\\SD"
    ;
  }
  else if (param_2 == 1) {
    pwVar2 = 
    L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Power\\EnergyEstimation\\Storage\\SSD"
    ;
  }
  else if (param_2 == 2) {
    pwVar2 = 
    L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Power\\EnergyEstimation\\Storage\\HDD"
    ;
  }
  else {
    if (param_2 != 3) {
      return 0;
    }
    pwVar2 = 
    L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Power\\EnergyEstimation\\Storage\\NVME"
    ;
  }
  RtlInitUnicodeString(&local_100,pwVar2);
  pvStack_e8 = (void *)0x0;
  local_e0 = &local_100;
  local_f0 = CONCAT44(local_f0._4_4_,0x30);
  uStack_d8 = CONCAT44(uStack_d8._4_4_,0x240);
  local_d0 = 0;
  uStack_c8 = 0;
  iVar1 = ZwOpenKey(&local_108,0x20019,&local_f0);
  if (-1 < iVar1) {
    uVar5 = 0;
    p_Var4 = param_1 + 0xa8;
    while( true ) {
      if (8 < (uint)uVar5) break;
      iVar1 = PmQueryDWORDValueKey(local_108,(ushort *)local_a8[uVar5],local_118);
      if (iVar1 < 0) goto LAB_14000d5ef;
      uVar5 = (ulonglong)((uint)uVar5 + 1);
      *(ulong *)p_Var4 = local_118[0];
      p_Var4 = p_Var4 + 4;
    }
    iVar1 = PmQueryDWORDValueKey(local_108,(ushort *)L"IdleStatesNumber",local_118);
    if (-1 < iVar1) {
      *(short *)param_1 = (short)local_118[0];
      if ((ushort)((short)local_118[0] - 1U) < 5) {
        RtlInitUnicodeString(&local_100,L"IdleState");
        pvStack_e8 = local_108;
        local_e0 = &local_100;
        uStack_d8 = CONCAT44(uStack_d8._4_4_,0x240);
        local_f0 = CONCAT44(local_f0._4_4_,0x30);
        local_d0 = 0;
        uStack_c8 = 0;
        iVar1 = ZwOpenKey(&local_c0,0x20019,&local_f0);
        if (-1 < iVar1) {
          p_Var4 = (_DISK_POWER_CONTEXT *)0x0;
          local_b8._0_4_ = CONCAT22(0x1c,(undefined2)local_b8);
          puStack_b0 = local_58;
          for (uVar3 = 0; uVar3 < *(ushort *)param_1; uVar3 = uVar3 + 1) {
            local_b8 = CONCAT62(local_b8._2_6_,0x1a);
            iVar1 = RtlIntegerToUnicodeString(uVar3 + 1,10,&local_b8);
            if (iVar1 < 0) goto LAB_14000d5ef;
            pvStack_e8 = local_c0;
            local_e0 = &local_b8;
            local_f0 = CONCAT44(local_f0._4_4_,0x30);
            uStack_d8 = CONCAT44(uStack_d8._4_4_,0x240);
            local_d0 = 0;
            uStack_c8 = 0;
            iVar1 = ZwOpenKey(&local_110,0x20019,&local_f0);
            if (iVar1 < 0) goto LAB_14000d5ef;
            p_Var4 = param_1 + (ulonglong)uVar3 * 0x20 + 8;
            iVar1 = PmQueryDWORDValueKey(local_110,(ushort *)L"IdleExitLatencyMs",local_118);
            if (iVar1 < 0) goto LAB_14000d5ef;
            *(ulonglong *)p_Var4 = (ulonglong)(local_118[0] * 10000);
            iVar1 = PmQueryDWORDValueKey(local_110,(ushort *)L"IdleExitEnergyMicroJoules",local_118)
            ;
            if (iVar1 < 0) goto LAB_14000d5ef;
            *(ulonglong *)(p_Var4 + 8) = (ulonglong)(local_118[0] * 10000);
            iVar1 = PmQueryDWORDValueKey(local_110,(ushort *)L"IdleTimeLengthMs",local_118);
            if (iVar1 < 0) goto LAB_14000d5ef;
            *(ulonglong *)(p_Var4 + 0x10) = (ulonglong)(local_118[0] * 10000);
            iVar1 = PmQueryDWORDValueKey(local_110,(ushort *)L"IdlePowerMw",local_118);
            if (iVar1 < 0) goto LAB_14000d5ef;
            *(ulong *)(p_Var4 + 0x18) = local_118[0];
            ZwClose(local_110);
            local_110 = (void *)0x0;
          }
          *(undefined8 *)(p_Var4 + 0x10) = 0xffffffffffffffff;
        }
      }
      else {
        iVar1 = -0x3ffffff3;
      }
    }
  }
LAB_14000d5ef:
  if (local_110 != (void *)0x0) {
    ZwClose();
  }
  if (local_108 != (void *)0x0) {
    ZwClose();
  }
  return iVar1;
}



===== PmQueryDWORDValueKey @ 14000d64c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl PmQueryDWORDValueKey(void * __ptr64,unsigned short const * __ptr64,unsigned long *
   __ptr64) */

long __cdecl PmQueryDWORDValueKey(void *param_1,ushort *param_2,ulong *param_3)

{
  int iVar1;
  undefined1 auStack_78 [32];
  undefined4 local_58;
  undefined4 *local_50;
  undefined4 local_48 [2];
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_78;
  local_48[0] = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_20 = 0;
  local_30 = 0;
  uStack_28 = 0;
  RtlInitUnicodeString(&local_40);
  local_50 = local_48;
  local_58 = 0x14;
  iVar1 = ZwQueryValueKey(param_1,&local_40,2,&local_30);
  if (-1 < iVar1) {
    if ((local_30._4_4_ == 4) && ((int)uStack_28 == 4)) {
      *param_3 = uStack_28._4_4_;
    }
    else {
      iVar1 = -0x3ffffff3;
    }
  }
  return iVar1;
}



===== PmPowerCounterDisable @ 14000d70c =====

void PmPowerCounterDisable(longlong *param_1)

{
  if ((param_1 != (longlong *)0x0) && (*param_1 != 0)) {
    if (*(longlong *)(*param_1 + 0xd0) != 0) {
      ObfDereferenceObject();
    }
    ExFreePoolWithTag(*param_1,0);
    *param_1 = 0;
  }
  return;
}



===== PmPowerCounterEnable @ 14000d75c =====

long PmPowerCounterEnable(longlong param_1)

{
  uint uVar1;
  long lVar2;
  _DISK_POWER_CONTEXT *p_Var3;
  _DISK_DEVICEPOWER_TYPE _Var4;
  
  _Var4 = 0;
  uVar1 = *(uint *)(*(longlong *)(param_1 + 0xe8) + 0x1c);
  if (1 < uVar1 - 0xc) {
    if ((uVar1 < 0xc) && ((0xb2eU >> (uVar1 & 0x1f) & 1) != 0)) {
      if (*(longlong *)(param_1 + 0x110) == 0) {
        _Var4 = 2;
      }
      else {
        _Var4 = (*(char *)(*(longlong *)(param_1 + 0x110) + 8) != '\0') + 1;
      }
    }
    else {
      if (uVar1 != 0x11) {
        *(undefined8 *)(param_1 + 0x478) = 0;
        return 0;
      }
      _Var4 = 3;
    }
  }
  p_Var3 = (_DISK_POWER_CONTEXT *)ExAllocatePool2(0x40,0xf0,0x43506d50);
  if (p_Var3 == (_DISK_POWER_CONTEXT *)0x0) {
    lVar2 = -0x3fffff66;
  }
  else {
    lVar2 = PmPowerContextInitialization(p_Var3,_Var4);
    if (lVar2 < 0) {
      ExFreePoolWithTag(p_Var3,0);
    }
    else {
      *(_DISK_POWER_CONTEXT **)(param_1 + 0x478) = p_Var3;
    }
  }
  return lVar2;
}



===== Feature_2563478843__private_IsEnabledDeviceUsageNoInline @ 14000d830 =====

ulonglong Feature_2563478843__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_2563478843__private_featureState;
  if ((Feature_2563478843__private_featureState & 0x10) == 0) {
    uVar1 = Feature_2563478843__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_2563478843__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_2563478843__private_IsEnabledFallback @ 14000d868 =====

void Feature_2563478843__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_2563478843__private_descriptor);
  return;
}



===== Feature_3144915256__private_IsEnabledDeviceUsageNoInline @ 14000d884 =====

ulonglong Feature_3144915256__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_3144915256__private_featureState;
  if ((Feature_3144915256__private_featureState & 0x10) == 0) {
    uVar1 = Feature_3144915256__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_3144915256__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_3144915256__private_IsEnabledFallback @ 14000d8bc =====

void Feature_3144915256__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_3144915256__private_descriptor);
  return;
}



===== PmInitializeSnapshotDataCache @ 14000d8d8 =====

long PmInitializeSnapshotDataCache(_DEVICE_EXTENSION *param_1)

{
  _DISK_SNAPSHOT_DATA *p_Var1;
  uchar uVar2;
  undefined1 uVar3;
  long lVar4;
  ulong local_res10 [2];
  _DISK_SNAPSHOT_DATA *local_res18;
  
  local_res10[0] = 0;
  local_res18 = (_DISK_SNAPSHOT_DATA *)0x0;
  lVar4 = PmGetDeviceParameterBinary(param_1,L"SnapshotDataCache",&local_res18,local_res10);
  if (-1 < lVar4) {
    uVar2 = PmVerifySnapshotData(local_res18,local_res10[0],'\x01');
    if (uVar2 == '\0') {
      lVar4 = -0x3ffff6f5;
    }
    else {
      uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x70);
      p_Var1 = local_res18;
      local_res18 = (_DISK_SNAPSHOT_DATA *)0x0;
      *(_DISK_SNAPSHOT_DATA **)(param_1 + 0x470) = p_Var1;
      KeReleaseSpinLock(param_1 + 0x70,uVar3);
    }
  }
  if (local_res18 != (_DISK_SNAPSHOT_DATA *)0x0) {
    ExFreePoolWithTag(local_res18,0);
  }
  return lVar4;
}



===== PmSetSnapshotData @ 14000d990 =====

long PmSetSnapshotData(_DEVICE_EXTENSION *param_1,SC_DISK_LAYOUT *param_2,
                      _DISK_SNAPSHOT_DATA *param_3,ulong param_4)

{
  _DEVICE_EXTENSION *p_Var1;
  uchar uVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  long lVar5;
  longlong lVar6;
  uint uVar7;
  ulonglong uVar8;
  ulonglong local_38 [2];
  
  local_38[0] = 0;
  uVar2 = PmVerifySnapshotData(param_3,param_4,'\0');
  if (uVar2 == '\0') {
    lVar5 = -0x3ffffff3;
  }
  else {
    *(undefined4 *)(param_3 + 0x10) = 0;
    uVar4 = RtlComputeCrc32(0,param_3,*(undefined4 *)(param_3 + 0xc));
    *(undefined4 *)(param_3 + 0x10) = uVar4;
    if (*(int *)(param_3 + 0x14) == 2) {
      if (*(int *)param_2 == 0) {
        lVar5 = PmGetPartitionAttributesMbr(param_1,(longlong *)local_38);
        if (lVar5 < 0) {
          return lVar5;
        }
        lVar5 = PmSetPartitionAttributesMbr(param_1,local_38[0] | 0xf000000000000000,0);
        if (lVar5 < 0) {
          return lVar5;
        }
      }
      else if (*(int *)param_2 == 1) {
        uVar8 = 0;
        if (*(int *)(param_2 + 4) != 0) {
          do {
            lVar6 = *(longlong *)(param_2 + uVar8 * 0x90 + 0x50) + -0x45b94df957434f53;
            if (lVar6 == 0) {
              lVar6 = *(longlong *)(param_2 + uVar8 * 0x90 + 0x58) + -0x7c4506f070239e8e;
            }
            if (lVar6 == 0) {
LAB_14000dbd6:
              *(ulonglong *)(param_2 + uVar8 * 0x90 + 0x70) =
                   *(ulonglong *)(param_2 + uVar8 * 0x90 + 0x70) | 0xf000000000000000;
            }
            else {
              lVar6 = *(longlong *)(param_2 + uVar8 * 0x90 + 0x50) + -0x43f094cb57434f53;
              if (lVar6 == 0) {
                lVar6 = *(longlong *)(param_2 + uVar8 * 0x90 + 0x58) + -0x7da5cf103cd733a5;
              }
              if (lVar6 == 0) goto LAB_14000dbd6;
              lVar6 = *(longlong *)(param_2 + uVar8 * 0x90 + 0x50) + -0x4433b9e5ebd0a0a2;
              if (lVar6 == 0) {
                lVar6 = *(longlong *)(param_2 + uVar8 * 0x90 + 0x58) + 0x3866d94849973f79;
              }
              if (lVar6 == 0) goto LAB_14000dbd6;
              lVar6 = *(longlong *)(param_2 + uVar8 * 0x90 + 0x50) + -0x405e8f4557434f53;
              if (lVar6 == 0) {
                lVar6 = *(longlong *)(param_2 + uVar8 * 0x90 + 0x58) + 0x2ccfbc7592e7dc76;
              }
              if (lVar6 == 0) goto LAB_14000dbd6;
              lVar6 = *(longlong *)(param_2 + uVar8 * 0x90 + 0x50) + -0x4d4006d1de94bba4;
              if (lVar6 == 0) {
                lVar6 = *(longlong *)(param_2 + uVar8 * 0x90 + 0x58) + 0x532986fe2a40955f;
              }
              if (lVar6 == 0) goto LAB_14000dbd6;
              lVar6 = *(longlong *)(param_2 + uVar8 * 0x90 + 0x50) + -0x44d523f257434f53;
              if (lVar6 == 0) {
                lVar6 = *(longlong *)(param_2 + uVar8 * 0x90 + 0x58) + 0x6f659254498cf58;
              }
              if (lVar6 == 0) goto LAB_14000dbd6;
              lVar6 = *(longlong *)(param_2 + uVar8 * 0x90 + 0x50) + -0x41967fe057434f53;
              if (lVar6 == 0) {
                lVar6 = *(longlong *)(param_2 + uVar8 * 0x90 + 0x58) + 0x7bcb9bae84bdbd65;
              }
              if (lVar6 == 0) goto LAB_14000dbd6;
              lVar6 = *(longlong *)(param_2 + uVar8 * 0x90 + 0x50) + -0x4014432e57434f53;
              if (lVar6 == 0) {
                lVar6 = *(longlong *)(param_2 + uVar8 * 0x90 + 0x58) + -0x6a00c0a9ea8d4cae;
              }
              if (lVar6 == 0) goto LAB_14000dbd6;
              lVar6 = *(longlong *)(param_2 + uVar8 * 0x90 + 0x50) + -0x4a05c69157434f53;
              if (lVar6 == 0) {
                lVar6 = *(longlong *)(param_2 + uVar8 * 0x90 + 0x58) + 0x31d62d50c28fb145;
              }
              if (lVar6 == 0) goto LAB_14000dbd6;
              lVar6 = *(longlong *)(param_2 + uVar8 * 0x90 + 0x50) + -0x460b4b8157434f53;
              if (lVar6 == 0) {
                lVar6 = *(longlong *)(param_2 + uVar8 * 0x90 + 0x58) + -0x146d13feb6ff19a3;
              }
              if (lVar6 == 0) goto LAB_14000dbd6;
              lVar6 = *(longlong *)(param_2 + uVar8 * 0x90 + 0x50) + -0x4e84e84d57434f53;
              if (lVar6 == 0) {
                lVar6 = *(longlong *)(param_2 + uVar8 * 0x90 + 0x58) + 0x2046fb4244130c56;
              }
              if (lVar6 == 0) goto LAB_14000dbd6;
              lVar6 = *(longlong *)(param_2 + uVar8 * 0x90 + 0x50) + -0x4631e3e357434f53;
              if (lVar6 == 0) {
                lVar6 = *(longlong *)(param_2 + uVar8 * 0x90 + 0x58) + 0x558cc7db2dd93a5b;
              }
              if (lVar6 == 0) goto LAB_14000dbd6;
            }
            uVar7 = (int)uVar8 + 1;
            uVar8 = (ulonglong)uVar7;
          } while (uVar7 < *(uint *)(param_2 + 4));
        }
        lVar5 = PmWritePartitionTable(*(_DEVICE_OBJECT **)(param_1 + 8),param_2);
        if (lVar5 < 0) {
          return lVar5;
        }
        PmInvalidatePartitionTableCache((longlong)param_1);
      }
      uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x70);
      for (p_Var1 = *(_DEVICE_EXTENSION **)(param_1 + 0x380); p_Var1 != param_1 + 0x380;
          p_Var1 = *(_DEVICE_EXTENSION **)p_Var1) {
        *(uint *)(p_Var1 + -0x68) = *(uint *)(p_Var1 + -0x68) | 0x10;
      }
      PmQueueNotificationWorkItem((longlong)param_1);
      KeReleaseSpinLock(param_1 + 0x70,uVar3);
    }
    lVar5 = PmWriteSnapshotData(param_1,(_DRIVE_LAYOUT_INFORMATION_EX *)param_2,param_3,param_4);
    if (-1 < lVar5) {
      uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x70);
      if (*(longlong *)(param_1 + 0x470) != 0) {
        ExFreePoolWithTag(*(longlong *)(param_1 + 0x470),0);
        *(undefined8 *)(param_1 + 0x470) = 0;
      }
      KeReleaseSpinLock(param_1 + 0x70,uVar3);
    }
  }
  return lVar5;
}



===== `vector_deleting_destructor' @ 14000dd50 =====

/* public: virtual void * __ptr64 __cdecl PM_DRIVE::`vector deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall PM_DRIVE::_vector_deleting_destructor_(PM_DRIVE *this,uint param_1)

{
  ~PM_DRIVE(this);
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0);
  }
  return this;
}



===== GetPnpProperty @ 14000dd90 =====

/* public: virtual long __cdecl PM_DRIVE::GetPnpProperty(void * __ptr64,void * __ptr64 * __ptr64)
   __ptr64 */

long __thiscall PM_DRIVE::GetPnpProperty(PM_DRIVE *this,void *param_1,void **param_2)

{
  int iVar1;
  
  iVar1 = PmGetDevicePropertyData
                    (*(undefined8 *)(*(longlong *)(this + 0x248) + 0x18),param_1,(longlong *)param_2
                    );
  return iVar1;
}



===== Initialize @ 14000ddb0 =====

/* public: long __cdecl PM_DRIVE::Initialize(struct _DEVICE_EXTENSION * __ptr64) __ptr64 */

long __thiscall PM_DRIVE::Initialize(PM_DRIVE *this,_DEVICE_EXTENSION *param_1)

{
  long lVar1;
  
  *(_DEVICE_EXTENSION **)(this + 0x248) = param_1;
  lVar1 = SC_DISK::Initialize((SC_DISK *)this);
  if (-1 < lVar1) {
    lVar1 = SC_DISK::InitializePartitionCache((SC_DISK *)this);
  }
  return lVar1;
}



===== McTemplateK0qqQR1_EtwWriteTransfer @ 14000dde0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qqQR1_EtwWriteTransfer(void)

{
  undefined1 local_res20 [8];
  undefined4 uStack0000000000000028;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined1 *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = local_res20;
  local_38 = &uStack0000000000000028;
  local_40 = 4;
  local_20 = uStack0000000000000028 << 2;
  local_30 = 4;
  local_1c = 0;
  McGenEventWrite_EtwWriteTransfer(0,&PartitionHidden,0,4,local_58);
  return;
}



===== McTemplateK0qqqtqqqqxxjqxqzzzzzzdddddddddxqjjjjtuqqqqqbr41qqqqtttqqqtttxxqqqqqtxqqqzqtqqqbr73qbr75qbr77qbr79qbr81qbr83_EtwWriteTransfer @ 14000de68 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qqqtqqqqxxjqxqzzzzzzdddddddddxqjjjjtuqqqqqbr41qqqqtttqqqtttxxqqqqqtxqqqzqtqqqbr73qbr75qbr77qbr79qbr81qbr83_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11,undefined1 param_12,
               undefined1 param_13,undefined8 param_14,undefined1 param_15,undefined1 param_16,
               undefined1 param_17,wchar_t *param_18,wchar_t *param_19,wchar_t *param_20,
               wchar_t *param_21,wchar_t *param_22,wchar_t *param_23,undefined1 param_24,
               undefined1 param_25,undefined1 param_26,undefined1 param_27,undefined1 param_28,
               undefined1 param_29,undefined1 param_30,undefined1 param_31,undefined1 param_32,
               undefined1 param_33,undefined1 param_34,undefined8 param_35,undefined8 param_36,
               undefined8 param_37,undefined8 param_38,undefined1 param_39,undefined1 param_40,
               undefined1 param_41,undefined1 param_42,undefined1 param_43,undefined1 param_44,
               undefined4 param_45,undefined8 param_46,undefined1 param_47,undefined1 param_48,
               undefined1 param_49,undefined1 param_50,undefined1 param_51,undefined1 param_52,
               undefined1 param_53,undefined1 param_54,undefined1 param_55,undefined1 param_56,
               undefined1 param_57,undefined1 param_58,undefined1 param_59,undefined1 param_60,
               undefined1 param_61,undefined1 param_62,undefined1 param_63,undefined1 param_64,
               undefined1 param_65,undefined1 param_66,undefined1 param_67)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 local_res20 [2];
  wchar_t *in_stack_00000240;
  undefined1 auStackY_5d8 [32];
  undefined8 local_5a8 [2];
  undefined4 *local_598;
  undefined8 local_590;
  undefined1 *local_588;
  undefined8 local_580;
  undefined1 *local_578;
  undefined8 local_570;
  undefined1 *local_568;
  undefined8 local_560;
  undefined1 *local_558;
  undefined8 local_550;
  undefined1 *local_548;
  undefined8 local_540;
  undefined1 *local_538;
  undefined8 local_530;
  undefined1 *local_528;
  undefined8 local_520;
  undefined1 *local_518;
  undefined8 local_510;
  undefined1 *local_508;
  undefined8 local_500;
  undefined8 local_4f8;
  undefined8 local_4f0;
  undefined1 *local_4e8;
  undefined8 local_4e0;
  undefined1 *local_4d8;
  undefined8 local_4d0;
  undefined1 *local_4c8;
  undefined8 local_4c0;
  wchar_t *local_4b8;
  int local_4b0;
  undefined4 local_4ac;
  wchar_t *local_4a8;
  int local_4a0;
  undefined4 local_49c;
  wchar_t *local_498;
  int local_490;
  undefined4 local_48c;
  wchar_t *local_488;
  int local_480;
  undefined4 local_47c;
  wchar_t *local_478;
  int local_470;
  undefined4 local_46c;
  wchar_t *local_468;
  int local_460;
  undefined4 local_45c;
  undefined1 *local_458;
  undefined8 local_450;
  undefined1 *local_448;
  undefined8 local_440;
  undefined1 *local_438;
  undefined8 local_430;
  undefined1 *local_428;
  undefined8 local_420;
  undefined1 *local_418;
  undefined8 local_410;
  undefined1 *local_408;
  undefined8 local_400;
  undefined1 *local_3f8;
  undefined8 local_3f0;
  undefined1 *local_3e8;
  undefined8 local_3e0;
  undefined1 *local_3d8;
  undefined8 local_3d0;
  undefined1 *local_3c8;
  undefined8 local_3c0;
  undefined1 *local_3b8;
  undefined8 local_3b0;
  undefined8 local_3a8;
  undefined8 local_3a0;
  undefined8 local_398;
  undefined8 local_390;
  undefined8 local_388;
  undefined8 local_380;
  undefined8 local_378;
  undefined8 local_370;
  undefined1 *local_368;
  undefined8 local_360;
  undefined1 *local_358;
  undefined8 local_350;
  undefined1 *local_348;
  undefined8 local_340;
  undefined1 *local_338;
  undefined8 local_330;
  undefined1 *local_328;
  undefined8 local_320;
  undefined1 *local_318;
  undefined8 local_310;
  undefined4 *local_308;
  undefined8 local_300;
  undefined8 local_2f8;
  undefined4 local_2f0;
  undefined4 local_2ec;
  undefined1 *local_2e8;
  undefined8 local_2e0;
  undefined1 *local_2d8;
  undefined8 local_2d0;
  undefined1 *local_2c8;
  undefined8 local_2c0;
  undefined1 *local_2b8;
  undefined8 local_2b0;
  undefined1 *local_2a8;
  undefined8 local_2a0;
  undefined1 *local_298;
  undefined8 local_290;
  undefined1 *local_288;
  undefined8 local_280;
  undefined1 *local_278;
  undefined8 local_270;
  undefined1 *local_268;
  undefined8 local_260;
  undefined1 *local_258;
  undefined8 local_250;
  undefined1 *local_248;
  undefined8 local_240;
  undefined1 *local_238;
  undefined8 local_230;
  undefined1 *local_228;
  undefined8 local_220;
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
  wchar_t *local_158;
  int local_150;
  undefined4 local_14c;
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
  undefined4 local_ec;
  undefined1 *local_e8;
  undefined8 local_e0;
  undefined4 local_cc;
  undefined1 *local_c8;
  undefined8 local_c0;
  undefined4 local_ac;
  undefined1 *local_a8;
  undefined8 local_a0;
  undefined4 local_8c;
  undefined1 *local_88;
  undefined8 local_80;
  undefined4 local_6c;
  undefined1 *local_68;
  undefined8 local_60;
  undefined4 local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_5d8;
  local_598 = local_res20;
  lVar2 = -1;
  local_150 = 10;
  local_588 = &param_5;
  local_578 = &param_6;
  local_568 = &param_7;
  local_558 = &param_8;
  local_548 = &param_9;
  local_538 = &param_10;
  local_528 = &param_11;
  local_518 = &param_12;
  local_508 = &param_13;
  local_4f8 = param_14;
  local_4e8 = &param_15;
  local_4d8 = &param_16;
  local_4c8 = &param_17;
  local_590 = 4;
  local_580 = 4;
  local_570 = 4;
  local_560 = 4;
  local_550 = 4;
  local_540 = 4;
  local_530 = 4;
  local_520 = 4;
  local_510 = 8;
  local_500 = 8;
  local_4f0 = 0x10;
  local_4e0 = 4;
  local_4d0 = 8;
  local_4c0 = 4;
  if (param_18 == (wchar_t *)0x0) {
    local_4b0 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_18[lVar1] != L'\0');
    local_4b0 = (int)lVar1 * 2 + 2;
  }
  local_4ac = 0;
  local_4b8 = param_18;
  if (param_18 == (wchar_t *)0x0) {
    local_4b8 = L"NULL";
  }
  if (param_19 == (wchar_t *)0x0) {
    local_4a0 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_19[lVar1] != L'\0');
    local_4a0 = (int)lVar1 * 2 + 2;
  }
  local_49c = 0;
  local_4a8 = param_19;
  if (param_19 == (wchar_t *)0x0) {
    local_4a8 = L"NULL";
  }
  if (param_20 == (wchar_t *)0x0) {
    local_490 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_20[lVar1] != L'\0');
    local_490 = (int)lVar1 * 2 + 2;
  }
  local_48c = 0;
  local_498 = param_20;
  if (param_20 == (wchar_t *)0x0) {
    local_498 = L"NULL";
  }
  if (param_21 == (wchar_t *)0x0) {
    local_480 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_21[lVar1] != L'\0');
    local_480 = (int)lVar1 * 2 + 2;
  }
  local_47c = 0;
  local_488 = param_21;
  if (param_21 == (wchar_t *)0x0) {
    local_488 = L"NULL";
  }
  if (param_22 == (wchar_t *)0x0) {
    local_470 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_22[lVar1] != L'\0');
    local_470 = (int)lVar1 * 2 + 2;
  }
  local_46c = 0;
  local_478 = param_22;
  if (param_22 == (wchar_t *)0x0) {
    local_478 = L"NULL";
  }
  if (param_23 == (wchar_t *)0x0) {
    local_460 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_23[lVar1] != L'\0');
    local_460 = (int)lVar1 * 2 + 2;
  }
  local_458 = &param_24;
  local_45c = 0;
  local_468 = param_23;
  if (param_23 == (wchar_t *)0x0) {
    local_468 = L"NULL";
  }
  local_448 = &param_25;
  local_438 = &param_26;
  local_428 = &param_27;
  local_418 = &param_28;
  local_408 = &param_29;
  local_3f8 = &param_30;
  local_3e8 = &param_31;
  local_3d8 = &param_32;
  local_3c8 = &param_33;
  local_3b8 = &param_34;
  local_3a8 = param_35;
  local_398 = param_36;
  local_388 = param_37;
  local_378 = param_38;
  local_368 = &param_39;
  local_358 = &param_40;
  local_348 = &param_41;
  local_338 = &param_42;
  local_328 = &param_43;
  local_318 = &param_44;
  local_308 = &param_45;
  local_2f8 = param_46;
  local_2f0 = param_45;
  local_2e8 = &param_47;
  local_2d8 = &param_48;
  local_450 = 4;
  local_440 = 4;
  local_430 = 4;
  local_420 = 4;
  local_410 = 4;
  local_400 = 4;
  local_3f0 = 4;
  local_3e0 = 4;
  local_3d0 = 4;
  local_3c0 = 8;
  local_3b0 = 4;
  local_3a0 = 0x10;
  local_390 = 0x10;
  local_380 = 0x10;
  local_370 = 0x10;
  local_360 = 4;
  local_350 = 1;
  local_340 = 4;
  local_330 = 4;
  local_320 = 4;
  local_310 = 4;
  local_300 = 4;
  local_2ec = 0;
  local_2e0 = 4;
  local_2d0 = 4;
  local_2c8 = &param_49;
  local_2b8 = &param_50;
  local_2a8 = &param_51;
  local_298 = &param_52;
  local_288 = &param_53;
  local_278 = &param_54;
  local_268 = &param_55;
  local_258 = &param_56;
  local_248 = &param_57;
  local_238 = &param_58;
  local_228 = &param_59;
  local_218 = &param_60;
  local_208 = &param_61;
  local_1f8 = &param_62;
  local_1e8 = &param_63;
  local_1d8 = &param_64;
  local_1c8 = &param_65;
  local_1b8 = &param_66;
  local_1a8 = &param_67;
  local_198 = auStackY_5d8 + 0x7f8;
  local_188 = auStackY_5d8 + 0x800;
  local_178 = auStackY_5d8 + 0x808;
  local_168 = auStackY_5d8 + 0x810;
  local_2c0 = 4;
  local_2b0 = 4;
  local_2a0 = 4;
  local_290 = 4;
  local_280 = 4;
  local_270 = 4;
  local_260 = 4;
  local_250 = 4;
  local_240 = 4;
  local_230 = 4;
  local_220 = 4;
  local_210 = 8;
  local_200 = 8;
  local_1f0 = 4;
  local_1e0 = 4;
  local_1d0 = 4;
  local_1c0 = 4;
  local_1b0 = 4;
  local_1a0 = 4;
  local_190 = 8;
  local_180 = 4;
  local_170 = 4;
  local_160 = 4;
  if (in_stack_00000240 != (wchar_t *)0x0) {
    do {
      lVar2 = lVar2 + 1;
    } while (in_stack_00000240[lVar2] != L'\0');
    local_150 = (int)lVar2 * 2 + 2;
  }
  local_148 = auStackY_5d8 + 0x820;
  if (in_stack_00000240 == (wchar_t *)0x0) {
    in_stack_00000240 = L"NULL";
  }
  local_138 = auStackY_5d8 + 0x828;
  local_128 = auStackY_5d8 + 0x830;
  local_14c = 0;
  local_118 = auStackY_5d8 + 0x838;
  local_140 = 4;
  local_108 = auStackY_5d8 + 0x840;
  local_130 = 4;
  local_e8 = auStackY_5d8 + 0x850;
  local_c8 = auStackY_5d8 + 0x860;
  local_a8 = auStackY_5d8 + 0x870;
  local_88 = auStackY_5d8 + 0x880;
  local_68 = auStackY_5d8 + 0x890;
  local_120 = 4;
  local_110 = 4;
  local_100 = 4;
  local_ec = 0;
  local_e0 = 4;
  local_cc = 0;
  local_c0 = 4;
  local_ac = 0;
  local_a0 = 4;
  local_8c = 0;
  local_80 = 4;
  local_6c = 0;
  local_60 = 4;
  local_4c = 0;
  local_res20[0] = param_4;
  local_158 = in_stack_00000240;
  McGenEventWrite_EtwWriteTransfer(lVar2,param_2,0,0x56,local_5a8);
  return;
}



===== PmPartitionRedirect @ 14000e804 =====

/* long __cdecl PmPartitionRedirect(struct _DEVICE_EXTENSION * __ptr64,struct _PARTITION_EXTENSION *
   __ptr64,struct _IRP * __ptr64,void * __ptr64,__int64,unsigned long) */

long __cdecl
PmPartitionRedirect(_DEVICE_EXTENSION *param_1,_PARTITION_EXTENSION *param_2,_IRP *param_3,
                   void *param_4,__int64 param_5,ulong param_6)

{
  char *pcVar1;
  longlong *plVar2;
  undefined8 uVar3;
  undefined1 *puVar4;
  undefined1 uVar5;
  longlong lVar6;
  _PARTITION_EXTENSION *p_Var7;
  undefined7 uVar8;
  long lVar9;
  undefined8 local_48;
  undefined8 local_40;
  _IRP *local_38;
  void *local_30;
  longlong local_28;
  ulong local_20;
  undefined4 local_1c;
  
  local_1c = 0;
  lVar9 = 0;
  p_Var7 = param_2;
  uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x70);
  uVar8 = (undefined7)((ulonglong)p_Var7 >> 8);
  lVar6 = PartitionOffset((longlong)param_2,'\x01');
  if ((lVar6 != *(longlong *)(param_2 + 0xb0)) && (lVar9 = 0, *(longlong *)(param_2 + 0x20) == 0)) {
    lVar9 = -0x3fffffde;
  }
  if (*(_PARTITION_EXTENSION **)(param_2 + 0x20) != (_PARTITION_EXTENSION *)0x0) {
    param_5 = param_5 + (*(ulonglong *)(param_2 + 0xe8) & 0xffffffffffffff00);
    param_2 = *(_PARTITION_EXTENSION **)(param_2 + 0x20);
  }
  KeReleaseSpinLock(param_1 + 0x70,CONCAT71(uVar8,uVar5));
  if (-1 < lVar9) {
    local_48 = *(undefined8 *)(param_2 + 8);
    local_40 = *(undefined8 *)(param_1 + 0x18);
    local_20 = param_6;
    local_38 = param_3;
    local_30 = param_4;
    local_28 = param_5;
    IoReuseIrp(*(undefined8 *)(param_1 + 0x358),0xc00000bb);
    lVar6 = *(longlong *)(param_1 + 0x358);
    pcVar1 = (char *)(lVar6 + 0x43);
    *pcVar1 = *pcVar1 + -1;
    plVar2 = (longlong *)(lVar6 + 0xb8);
    *plVar2 = *plVar2 + -0x48;
    lVar6 = *(longlong *)(param_1 + 0x358);
    uVar3 = *(undefined8 *)(*(longlong *)(param_2 + 0x70) + 0x28);
    puVar4 = *(undefined1 **)(lVar6 + 0xb8);
    *puVar4 = 0xf;
    *(undefined8 **)(lVar6 + 0x18) = &local_48;
    *(undefined4 *)(puVar4 + 8) = 0;
    *(undefined4 *)(puVar4 + 0x10) = 0x30;
    *(undefined4 *)(puVar4 + 0x18) = 0x760034;
    IoForwardIrpSynchronously(uVar3,lVar6);
    lVar9 = *(long *)(lVar6 + 0x30);
  }
  return lVar9;
}



===== PmQueryDepends @ 14000e968 =====

/* void __cdecl PmQueryDepends(struct _DEVICE_EXTENSION * __ptr64,struct _LIST_ENTRY * __ptr64) */

void __cdecl PmQueryDepends(_DEVICE_EXTENSION *param_1,_LIST_ENTRY *param_2)

{
  char *pcVar1;
  longlong *plVar2;
  _DEVICE_EXTENSION *p_Var3;
  longlong lVar4;
  undefined8 uVar5;
  undefined1 *puVar6;
  longlong *****ppppplVar7;
  longlong *****ppppplVar8;
  longlong ****pppplVar9;
  uint *puVar10;
  code *pcVar11;
  char cVar12;
  int iVar13;
  undefined1 uVar14;
  uint *puVar15;
  longlong ****pppplVar16;
  _DEVICE_EXTENSION *p_Var17;
  ulonglong uVar18;
  _LIST_ENTRY *p_Var19;
  uint uVar20;
  ulonglong uVar21;
  int iVar22;
  undefined8 uVar23;
  ulonglong uVar24;
  int iVar25;
  uint *local_res18;
  ulonglong local_res20;
  longlong *****local_78;
  _DEVICE_EXTENSION *local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  
  local_68 = 0;
  iVar22 = 0;
  local_60 = 0;
  uStack_58 = 0;
  iVar25 = 0;
  p_Var19 = param_2;
  while (p_Var19 = *(_LIST_ENTRY **)p_Var19, p_Var19 != param_2) {
    iVar13 = iVar22 + 1;
    if (*(longlong *)(p_Var19 + -8) == 0) {
      iVar13 = iVar22;
    }
    iVar22 = iVar13;
  }
  uVar23 = 0x52526d50;
  puVar15 = (uint *)ExAllocatePool2(0x100,iVar22 * 8 + 8,0x52526d50);
  if (puVar15 == (uint *)0x0) {
    iVar25 = -0x3fffff66;
  }
  else {
    uVar24 = 0;
    for (p_Var19 = *(_LIST_ENTRY **)param_2; p_Var19 != param_2; p_Var19 = *(_LIST_ENTRY **)p_Var19)
    {
      uVar21 = uVar24;
      if (*(longlong *)(p_Var19 + -8) != 0) {
        local_68 = *(undefined8 *)(p_Var19 + -0x70);
        local_60 = *(undefined8 *)(param_1 + 0x18);
        IoReuseIrp(*(undefined8 *)(param_1 + 0x358),0xc00000bb);
        lVar4 = *(longlong *)(param_1 + 0x358);
        pcVar1 = (char *)(lVar4 + 0x43);
        *pcVar1 = *pcVar1 + -1;
        plVar2 = (longlong *)(lVar4 + 0xb8);
        *plVar2 = *plVar2 + -0x48;
        lVar4 = *(longlong *)(param_1 + 0x358);
        uVar5 = *(undefined8 *)(*(longlong *)(p_Var19 + -8) + 0x28);
        puVar6 = *(undefined1 **)(lVar4 + 0xb8);
        *puVar6 = 0xf;
        *(undefined8 **)(lVar4 + 0x18) = &local_68;
        *(undefined4 *)(puVar6 + 8) = 8;
        *(undefined4 *)(puVar6 + 0x10) = 0x18;
        *(undefined4 *)(puVar6 + 0x18) = 0x76000c;
        IoForwardIrpSynchronously(uVar5,lVar4);
        iVar25 = *(int *)(lVar4 + 0x30);
        if (iVar25 < 0) break;
        uVar21 = (ulonglong)((uint)uVar24 + 1);
        *(undefined8 *)(puVar15 + uVar24 * 2 + 2) = local_68;
      }
      uVar24 = uVar21;
    }
    *puVar15 = (uint)uVar24;
  }
  uVar14 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x70);
  p_Var3 = param_1 + 0x2a0;
  uVar24 = CONCAT71((int7)((ulonglong)uVar23 >> 8),uVar14);
  ppppplVar7 = *(longlong ******)p_Var3;
  p_Var17 = local_70;
  if ((_DEVICE_EXTENSION *)ppppplVar7[1] == p_Var3) {
    ppppplVar7[1] = (longlong ****)&local_78;
    *(longlong *******)p_Var3 = &local_78;
    local_70 = *(_DEVICE_EXTENSION **)(param_1 + 0x2a8);
    local_78 = ppppplVar7;
    p_Var17 = p_Var3;
    if (*(_DEVICE_EXTENSION **)local_70 == p_Var3) {
      *(longlong *******)local_70 = &local_78;
      p_Var17 = param_1 + 0x70;
      *(_DEVICE_EXTENSION **)(param_1 + 0x2a8) = p_Var3;
      *(_DEVICE_EXTENSION **)p_Var3 = p_Var3;
      KeReleaseSpinLock(p_Var17,CONCAT71((int7)((ulonglong)p_Var3 >> 8),uVar14));
      if (((longlong ******)local_78 == &local_78) &&
         ((Microsoft_Windows_PartitionEnableBits & 4) != 0)) {
        McTemplateK0qp_EtwWriteTransfer
                  (p_Var17,&QueryDepends,uVar24,*(undefined4 *)(param_1 + 0xa8),0);
      }
      while( true ) {
        ppppplVar7 = local_78;
        uVar21 = 0;
        if ((longlong ******)local_78 == &local_78) {
          if (puVar15 != (uint *)0x0) {
            uVar24 = uVar21;
            if (*puVar15 != 0) {
              do {
                puVar10 = *(uint **)(puVar15 + uVar24 * 2 + 2);
                if (puVar10 != (uint *)0x0) {
                  uVar18 = uVar21;
                  if (*puVar10 != 0) {
                    do {
                      ObfDereferenceObject(*(undefined8 *)(puVar10 + uVar18 * 2 + 2));
                      uVar20 = (int)uVar18 + 1;
                      uVar18 = (ulonglong)uVar20;
                    } while (uVar20 < *puVar10);
                  }
                  ExFreePoolWithTag(puVar10,0);
                  (puVar15 + uVar24 * 2 + 2)[0] = 0;
                  (puVar15 + uVar24 * 2 + 2)[1] = 0;
                }
                uVar20 = (int)uVar24 + 1;
                uVar24 = (ulonglong)uVar20;
              } while (uVar20 < *puVar15);
            }
            ExFreePoolWithTag(puVar15,0);
          }
          return;
        }
        p_Var17 = local_70;
        if (((longlong ******)local_78[1] != &local_78) ||
           (ppppplVar8 = (longlong *****)*local_78, (longlong *****)ppppplVar8[1] != local_78))
        break;
        ppppplVar8[1] = (longlong ****)&local_78;
        cVar12 = (char)local_78;
        local_78 = ppppplVar8;
        if ((Microsoft_Windows_PartitionEnableBits & 4) != 0) {
          McTemplateK0qp_EtwWriteTransfer
                    (&local_78,&QueryDepends,uVar24,*(undefined4 *)(param_1 + 0xa8),cVar12 + 'X');
        }
        ppppplVar7[1] = (longlong ****)ppppplVar7;
        *ppppplVar7 = (longlong ****)ppppplVar7;
        pppplVar9 = ppppplVar7[-0xe];
        if (iVar25 < 0) {
LAB_14000ec18:
          if (pppplVar9 != (longlong ****)0x0) {
            if (*(uint *)pppplVar9 != 0) {
              do {
                ObfDereferenceObject(pppplVar9[uVar21 + 1]);
                uVar20 = (int)uVar21 + 1;
                uVar21 = (ulonglong)uVar20;
              } while (uVar20 < *(uint *)pppplVar9);
            }
            ExFreePoolWithTag(pppplVar9);
          }
          ppppplVar7[-0xe] = (longlong ****)0x0;
          *(int *)(ppppplVar7 + -0xf) = iVar25;
        }
        else {
          uVar24 = 0x52526d50;
          pppplVar16 = (longlong ****)ExAllocatePool2(0x102);
          if (pppplVar16 == (longlong ****)0x0) {
            iVar25 = -0x3fffff66;
            goto LAB_14000ec18;
          }
          *(uint *)pppplVar16 = 0;
          local_res20 = (ulonglong)*puVar15;
          if (*puVar15 != 0) {
            local_res18 = puVar15;
            do {
              local_res18 = local_res18 + 2;
              puVar10 = *(uint **)local_res18;
              if ((puVar10 != (uint *)0x0) && (uVar18 = 0, *puVar10 != 0)) {
                do {
                  for (uVar21 = 0; (uint)uVar21 < *(uint *)pppplVar16;
                      uVar21 = (ulonglong)((uint)uVar21 + 1)) {
                    if (pppplVar16[uVar21 + 1] == *(longlong ****)(puVar10 + uVar18 * 2 + 2))
                    goto LAB_14000ecc2;
                  }
                  ObfReferenceObject();
                  pppplVar16[uVar21 + 1] = *(longlong ****)(puVar10 + uVar18 * 2 + 2);
                  *(uint *)pppplVar16 = *(uint *)pppplVar16 + 1;
LAB_14000ecc2:
                  uVar20 = (int)uVar18 + 1;
                  uVar18 = (ulonglong)uVar20;
                } while (uVar20 < *puVar10);
              }
              local_res20 = local_res20 - 1;
            } while (local_res20 != 0);
          }
          if (pppplVar9 != (longlong ****)0x0) {
            uVar18 = 0;
            if (*(uint *)pppplVar9 != 0) {
              do {
                uVar24 = uVar21;
                lVar4 = uVar18 + 1;
                uVar20 = (int)uVar18 + 1;
                uVar18 = (ulonglong)uVar20;
                pppplVar16[uVar24 + 1] = pppplVar9[lVar4];
                *(uint *)pppplVar16 = *(uint *)pppplVar16 + 1;
                uVar21 = (ulonglong)((int)uVar24 + 1);
              } while (uVar20 < *(uint *)pppplVar9);
            }
            ExFreePoolWithTag(pppplVar9);
          }
          ppppplVar7[-0xe] = pppplVar16;
          *(int *)(ppppplVar7 + -0xf) = iVar25;
        }
      }
    }
  }
  local_70 = p_Var17;
  pcVar11 = (code *)swi(0x29);
  (*pcVar11)(3);
  pcVar11 = (code *)swi(3);
  (*pcVar11)();
  return;
}



===== PmQueryVeto @ 14000edc0 =====

/* void __cdecl PmQueryVeto(struct _DEVICE_EXTENSION * __ptr64,struct _LIST_ENTRY * __ptr64) */

void __cdecl PmQueryVeto(_DEVICE_EXTENSION *param_1,_LIST_ENTRY *param_2)

{
  char *pcVar1;
  longlong *plVar2;
  _DEVICE_EXTENSION *p_Var3;
  longlong lVar4;
  undefined8 uVar5;
  undefined1 *puVar6;
  longlong ****pppplVar7;
  code *pcVar8;
  byte bVar9;
  _DEVICE_EXTENSION *p_Var10;
  undefined1 uVar11;
  _LIST_ENTRY *p_Var12;
  longlong ****local_48;
  _DEVICE_EXTENSION *p_Stack_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 uStack_28;
  
  p_Var12 = *(_LIST_ENTRY **)param_2;
  bVar9 = 0;
  local_48 = (longlong ****)0x0;
  p_Stack_40 = (_DEVICE_EXTENSION *)0x0;
  local_38 = 0;
  local_30 = 0;
  uStack_28 = 0;
  do {
    if (p_Var12 == param_2) {
LAB_14000ee9d:
      uVar11 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x70);
      p_Var3 = param_1 + 0x2b0;
      pppplVar7 = *(longlong *****)p_Var3;
      p_Var10 = p_Stack_40;
      if ((_DEVICE_EXTENSION *)pppplVar7[1] == p_Var3) {
        pppplVar7[1] = (longlong ***)&local_48;
        *(longlong ******)p_Var3 = &local_48;
        p_Stack_40 = *(_DEVICE_EXTENSION **)(param_1 + 0x2b8);
        local_48 = pppplVar7;
        p_Var10 = p_Var3;
        if (*(_DEVICE_EXTENSION **)p_Stack_40 == p_Var3) {
          *(longlong ******)p_Stack_40 = &local_48;
          *(_DEVICE_EXTENSION **)(param_1 + 0x2b8) = p_Var3;
          *(_DEVICE_EXTENSION **)p_Var3 = p_Var3;
          KeReleaseSpinLock(param_1 + 0x70,CONCAT71((int7)((ulonglong)p_Var3 >> 8),uVar11));
          while( true ) {
            if ((longlong *****)local_48 == &local_48) {
              return;
            }
            p_Var10 = p_Stack_40;
            if (((longlong *****)local_48[1] != &local_48) ||
               (pppplVar7 = (longlong ****)*local_48, (longlong ****)pppplVar7[1] != local_48))
            break;
            pppplVar7[1] = (longlong ***)&local_48;
            local_48[1] = (longlong ***)local_48;
            *local_48 = (longlong ***)local_48;
            *(uint *)(local_48 + -0xf) = -(uint)bVar9 & 0xc0000001;
            local_48 = pppplVar7;
          }
        }
      }
      p_Stack_40 = p_Var10;
      pcVar8 = (code *)swi(0x29);
      (*pcVar8)(3);
      return;
    }
    if (*(longlong *)(p_Var12 + -8) != 0) {
      local_38 = *(undefined8 *)(p_Var12 + -0x70);
      local_30 = *(undefined8 *)(param_1 + 0x18);
      IoReuseIrp(*(undefined8 *)(param_1 + 0x358),0xc00000bb);
      lVar4 = *(longlong *)(param_1 + 0x358);
      pcVar1 = (char *)(lVar4 + 0x43);
      *pcVar1 = *pcVar1 + -1;
      plVar2 = (longlong *)(lVar4 + 0xb8);
      *plVar2 = *plVar2 + -0x48;
      lVar4 = *(longlong *)(param_1 + 0x358);
      uVar5 = *(undefined8 *)(*(longlong *)(p_Var12 + -8) + 0x28);
      puVar6 = *(undefined1 **)(lVar4 + 0xb8);
      *puVar6 = 0xf;
      *(undefined8 **)(lVar4 + 0x18) = &local_38;
      *(undefined4 *)(puVar6 + 8) = 1;
      *(undefined4 *)(puVar6 + 0x10) = 0x18;
      *(undefined4 *)(puVar6 + 0x18) = 0x760038;
      IoForwardIrpSynchronously(uVar5,lVar4);
      if ((-1 < *(int *)(lVar4 + 0x30)) && ((char)local_38 != '\0')) {
        bVar9 = 1;
        goto LAB_14000ee9d;
      }
    }
    p_Var12 = *(_LIST_ENTRY **)p_Var12;
  } while( true );
}



===== PmSplitAndRedirectIo @ 14000ef7c =====

/* long __cdecl PmSplitAndRedirectIo(struct _DEVICE_EXTENSION * __ptr64,struct _IRP * __ptr64,struct
   _LIST_ENTRY * __ptr64) */

long __cdecl PmSplitAndRedirectIo(_DEVICE_EXTENSION *param_1,_IRP *param_2,_LIST_ENTRY *param_3)

{
  char *pcVar1;
  bool bVar2;
  undefined1 uVar3;
  long lVar4;
  longlong lVar5;
  void *pvVar6;
  uint uVar7;
  longlong lVar8;
  _LIST_ENTRY *p_Var9;
  uint uVar10;
  longlong local_68;
  longlong local_60;
  
  p_Var9 = *(_LIST_ENTRY **)param_3;
  local_60 = 0;
  bVar2 = false;
  pcVar1 = *(char **)(param_2 + 0xb8);
  lVar4 = 0;
  local_68 = 0;
  lVar8 = *(longlong *)(pcVar1 + 0x18);
  pvVar6 = (void *)((ulonglong)*(uint *)(*(longlong *)(param_2 + 8) + 0x2c) +
                   *(longlong *)(*(longlong *)(param_2 + 8) + 0x20));
  uVar7 = *(uint *)(pcVar1 + 8);
  if (p_Var9 != param_3) {
    do {
      uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x70);
      if ((*pcVar1 == '\x03') &&
         ((*(int *)(p_Var9 + 0x30) != 1 || ((*(ulonglong *)(p_Var9 + 0x70) >> 0x3a & 1) == 0)))) {
        bVar2 = true;
      }
      else {
        local_68 = *(longlong *)(p_Var9 + 0x38);
        local_60 = *(longlong *)(p_Var9 + 0x40);
      }
      KeReleaseSpinLock(param_1 + 0x70,uVar3);
      if (bVar2) {
        bVar2 = false;
      }
      else {
        if (lVar8 < local_68) {
          uVar10 = (uint)(local_68 - lVar8);
          if ((longlong)(ulonglong)uVar7 <= local_68 - lVar8) {
            uVar10 = uVar7;
          }
          lVar4 = PmDiskRedirect(param_1,param_2,pvVar6,lVar8,uVar10);
          if (lVar4 < 0) {
            return lVar4;
          }
          pvVar6 = (void *)((longlong)pvVar6 + (ulonglong)uVar10);
          lVar8 = lVar8 + (ulonglong)uVar10;
          uVar7 = uVar7 - uVar10;
        }
        if (uVar7 == 0) break;
        if ((local_68 <= lVar8) && (lVar5 = lVar8 - local_68, lVar5 < local_60)) {
          uVar10 = (uint)(local_60 - lVar5);
          if ((longlong)(ulonglong)uVar7 <= local_60 - lVar5) {
            uVar10 = uVar7;
          }
          lVar4 = PmPartitionRedirect(param_1,(_PARTITION_EXTENSION *)(p_Var9 + -0x78),param_2,
                                      pvVar6,lVar5,uVar10);
          if (lVar4 == -0x3ffffffe) {
            lVar4 = PmDiskRedirect(param_1,param_2,pvVar6,lVar8,uVar10);
          }
          if (lVar4 < 0) {
            return lVar4;
          }
          pvVar6 = (void *)((longlong)pvVar6 + (ulonglong)uVar10);
          lVar8 = lVar8 + (ulonglong)uVar10;
          uVar7 = uVar7 - uVar10;
          if (uVar7 == 0) goto LAB_14000f14c;
        }
      }
      p_Var9 = *(_LIST_ENTRY **)p_Var9;
    } while (p_Var9 != param_3);
    if (lVar4 < 0) {
      return lVar4;
    }
  }
LAB_14000f14c:
  if ((uVar7 != 0) && (lVar4 = PmDiskRedirect(param_1,param_2,pvVar6,lVar8,uVar7), lVar4 < 0)) {
    return lVar4;
  }
  if (*(int *)(param_2 + 0x38) != *(int *)(pcVar1 + 8)) {
    lVar4 = -0x3fffff1b;
  }
  return lVar4;
}



===== PmVolumeManagerArrival @ 14000f19c =====

/* long __cdecl PmVolumeManagerArrival(struct _CONTROL_EXTENSION * __ptr64,struct _UNICODE_STRING *
   __ptr64) */

long __cdecl PmVolumeManagerArrival(_CONTROL_EXTENSION *param_1,_UNICODE_STRING *param_2)

{
  _VOLUME_MANAGER *p_Var1;
  ushort uVar2;
  code *pcVar3;
  bool bVar4;
  undefined1 uVar5;
  int iVar6;
  _VOLUME_MANAGER *p_Var7;
  _CONTROL_EXTENSION *p_Var8;
  _VOLUME_MANAGER *p_Var9;
  undefined8 *puVar10;
  _CONTROL_EXTENSION *p_Var11;
  _CONTROL_EXTENSION *p_Var12;
  undefined1 *puVar13;
  undefined1 auStackY_88 [8];
  undefined1 auStackY_80 [24];
  code *local_48;
  code *pcStack_40;
  code *local_38;
  code *pcStack_30;
  code *local_28;
  
  uVar2 = *(ushort *)(param_2 + 2);
  local_48 = (code *)0x0;
  pcStack_40 = (code *)0x0;
  local_38 = (code *)0x0;
  pcStack_30 = (code *)0x0;
  local_28 = (code *)0x0;
  p_Var7 = (_VOLUME_MANAGER *)ExAllocatePool2(0x42,(ulonglong)uVar2 + 0x40,0x45566d50);
  if (p_Var7 == (_VOLUME_MANAGER *)0x0) {
    iVar6 = -0x3fffff66;
  }
  else {
    *(ushort *)(p_Var7 + 0x12) = uVar2;
    *(_VOLUME_MANAGER **)(p_Var7 + 0x18) = p_Var7 + 0x40;
    RtlCopyUnicodeString(p_Var7 + 0x10,param_2);
    *(undefined4 *)(p_Var7 + 0x20) = 0;
    *(undefined8 *)(p_Var7 + 0x30) = 0;
    p_Var1 = p_Var7 + 0x28;
    *(undefined8 *)p_Var1 = 0;
    p_Var9 = p_Var7 + 0x10;
    *(_VOLUME_MANAGER **)(p_Var7 + 8) = p_Var7;
    *(_VOLUME_MANAGER **)p_Var7 = p_Var7;
    iVar6 = IoGetDeviceObjectPointer(p_Var9,1,p_Var7 + 0x30,p_Var1);
    if (-1 < iVar6) {
      local_48 = PmWmiCounterEnable;
      pcStack_40 = PmWmiCounterDisable;
      local_38 = PmWmiCounterIoStart;
      pcStack_30 = PmWmiCounterIoComplete;
      local_28 = PmWmiCounterQuery;
      PmSendDeviceControl(*(undefined8 *)p_Var1,0x760024,&local_48,0x28,0,0,1);
      p_Var9 = p_Var7;
      iVar6 = PmSetVolumeManagerAltitude(p_Var7);
      puVar13 = auStackY_88;
      if (-1 < iVar6) {
        p_Var12 = param_1 + 0x48;
        p_Var8 = *(_CONTROL_EXTENSION **)p_Var12;
        if (p_Var8 != p_Var12) {
          do {
            if (*(uint *)(p_Var7 + 0x38) < *(uint *)(p_Var8 + 0x38)) break;
            p_Var8 = *(_CONTROL_EXTENSION **)p_Var8;
          } while (p_Var8 != p_Var12);
        }
        puVar10 = *(undefined8 **)(p_Var8 + 8);
        if ((_CONTROL_EXTENSION *)*puVar10 != p_Var8) {
          puVar10 = (undefined8 *)0x3;
          pcVar3 = (code *)swi(0x29);
          p_Var8 = (_CONTROL_EXTENSION *)(*pcVar3)();
          puVar13 = auStackY_80;
        }
        *(_CONTROL_EXTENSION **)p_Var7 = p_Var8;
        *(undefined8 **)(p_Var7 + 8) = puVar10;
        *puVar10 = p_Var7;
        *(_VOLUME_MANAGER **)(p_Var8 + 8) = p_Var7;
        for (p_Var12 = *(_CONTROL_EXTENSION **)(param_1 + 0x58); p_Var12 != param_1 + 0x58;
            p_Var12 = *(_CONTROL_EXTENSION **)p_Var12) {
          bVar4 = false;
          *(undefined8 *)(puVar13 + -8) = 0x14000f32b;
          uVar5 = KeAcquireSpinLockRaiseToDpc(p_Var12 + -0x28);
          p_Var8 = p_Var12 + 0x2e8;
          p_Var11 = *(_CONTROL_EXTENSION **)p_Var8;
          if (p_Var11 != p_Var8) {
            do {
              if (*(longlong *)(p_Var11 + -0x20) == 0) {
                *(uint *)(p_Var11 + -0x68) = *(uint *)(p_Var11 + -0x68) & 0xfffffffe;
                bVar4 = true;
              }
              p_Var11 = *(_CONTROL_EXTENSION **)p_Var11;
            } while (p_Var11 != p_Var8);
            if (bVar4) {
              *(undefined8 *)(puVar13 + -8) = 0x14000f36c;
              PmQueueNotificationWorkItem((longlong)(p_Var12 + -0x98));
            }
          }
          *(undefined8 *)(puVar13 + -8) = 0x14000f37a;
          KeReleaseSpinLock(p_Var12 + -0x28,uVar5);
        }
        return iVar6;
      }
    }
    PmVolumeManagerRemoval(p_Var9,(longlong *)p_Var7);
  }
  return iVar6;
}



===== McTemplateK0qdq_EtwWriteTransfer @ 14000f3bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qdq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined4 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = local_res20;
  local_38 = &param_5;
  local_40 = 4;
  local_28 = &param_6;
  local_30 = 4;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&NotificationWorkItemLoop,0,4,local_58);
  return;
}



===== PmQueueNotificationWorkItem @ 14000f438 =====

int PmQueueNotificationWorkItem(longlong param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (*(char *)(param_1 + 0x330) == '\0') {
    if ((*(uint *)(param_1 + 0x200) & 2) == 0) {
      iVar1 = -0x3fffff5d;
    }
    else {
      iVar1 = IoAcquireRemoveLockEx(param_1 + 0x78,*(undefined8 *)(param_1 + 0x350),"",1,0x20);
      if (-1 < iVar1) {
        KeClearEvent(param_1 + 0x338);
        *(undefined1 *)(param_1 + 0x330) = 1;
        IoQueueWorkItem(*(undefined8 *)(param_1 + 0x350),PmNotificationWorkItem,0,0);
      }
    }
  }
  if ((Microsoft_Windows_PartitionEnableBits & 4) != 0) {
    McTemplateK0qdds_EtwWriteTransfer();
  }
  return iVar1;
}



===== StRtlFindBestStorageDeviceId @ 14000f518 =====

longlong StRtlFindBestStorageDeviceId(longlong param_1)

{
  bool bVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  lVar3 = param_1 + 0xc;
  lVar2 = 0;
  if (*(uint *)(param_1 + 8) != 0) {
    uVar4 = (ulonglong)*(uint *)(param_1 + 8);
    do {
      if (((*(uint *)(lVar3 + 0xc) & 0xfffffffd) == 0) &&
         ((*(int *)(lVar3 + 4) - 1U < 3 || (*(int *)(lVar3 + 4) == 8)))) {
        if (lVar2 != 0) {
          bVar1 = StRtlIsBetterStorageDeviceId(lVar3,lVar2);
          if (!bVar1) goto LAB_14000f55e;
        }
        lVar2 = lVar3;
      }
LAB_14000f55e:
      lVar3 = lVar3 + (ulonglong)*(ushort *)(lVar3 + 10);
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  return lVar2;
}



===== StRtlIsBetterStorageDeviceId @ 14000f580 =====

bool StRtlIsBetterStorageDeviceId(longlong param_1,longlong param_2)

{
  int iVar1;
  ulonglong uVar2;
  uint uVar3;
  
  uVar2 = 0;
  if (*(int *)(param_1 + 0xc) != *(int *)(param_2 + 0xc)) {
    for (uVar3 = 0; uVar3 < 2; uVar3 = uVar3 + 1) {
      iVar1 = *(int *)((longlong)&StRtlStorageIdAssociations + (ulonglong)uVar3 * 4);
      if (*(int *)(param_2 + 0xc) == iVar1) {
        return false;
      }
      if (*(int *)(param_1 + 0xc) == iVar1) {
        return true;
      }
    }
  }
  if (*(int *)(param_1 + 4) != *(int *)(param_2 + 4)) {
    for (; (uint)uVar2 < 4; uVar2 = (ulonglong)((uint)uVar2 + 1)) {
      iVar1 = *(int *)((longlong)&StRtlStorageIdTypes + uVar2 * 4);
      if (*(int *)(param_2 + 4) == iVar1) {
        return false;
      }
      if (*(int *)(param_1 + 4) == iVar1) {
        return true;
      }
    }
  }
  return *(ushort *)(param_2 + 8) < *(ushort *)(param_1 + 8);
}



===== ScAnsiToUnicodeString @ 14000f614 =====

/* long __cdecl ScAnsiToUnicodeString(char * __ptr64,struct _UNICODE_STRING * __ptr64) */

long __cdecl ScAnsiToUnicodeString(char *param_1,_UNICODE_STRING *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  local_28 = 0;
  uStack_20 = 0;
  ScTrimString(param_1);
  RtlInitAnsiString(&local_18,param_1);
  uVar2 = RtlxAnsiStringToUnicodeSize(&local_18);
  local_28._0_4_ = CONCAT22((short)uVar2,(undefined2)local_28);
  uStack_20 = ExAllocatePool2(0x40,uVar2,0x6d506353);
  if (uStack_20 == 0) {
    iVar3 = -0x3fffff66;
  }
  else {
    iVar3 = RtlAnsiStringToUnicodeString(&local_28,&local_18,0);
    if (-1 < iVar3) {
      if (*(longlong *)(param_2 + 8) != 0) {
        ExFreePoolWithTag(*(longlong *)(param_2 + 8),0);
      }
      uVar2 = (undefined4)uStack_20;
      uVar1 = uStack_20._4_4_;
      uStack_20 = 0;
      *(undefined4 *)param_2 = (undefined4)local_28;
      *(undefined4 *)(param_2 + 4) = local_28._4_4_;
      *(undefined4 *)(param_2 + 8) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = uVar1;
    }
  }
  if (uStack_20 != 0) {
    ExFreePoolWithTag(uStack_20,0);
  }
  return iVar3;
}



===== ScExtractDeviceStrings @ 14000f704 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl ScExtractDeviceStrings(struct _STORAGE_DEVICE_DESCRIPTOR * __ptr64,struct
   _UNICODE_STRING * __ptr64,struct _UNICODE_STRING * __ptr64,struct _UNICODE_STRING *
   __ptr64,struct _UNICODE_STRING * __ptr64) */

long __cdecl
ScExtractDeviceStrings
          (_STORAGE_DEVICE_DESCRIPTOR *param_1,_UNICODE_STRING *param_2,_UNICODE_STRING *param_3,
          _UNICODE_STRING *param_4,_UNICODE_STRING *param_5)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  longlong lVar5;
  _UNICODE_STRING **pp_Var6;
  uint *puVar7;
  undefined1 auStack_98 [32];
  uint local_78 [4];
  _UNICODE_STRING *local_68 [4];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_98;
  pp_Var6 = local_68;
  puVar7 = local_78;
  iVar1 = *(int *)(param_1 + 4);
  lVar4 = 0;
  local_78[0] = *(uint *)(param_1 + 0xc);
  local_78[1] = *(undefined4 *)(param_1 + 0x10);
  lVar5 = 4;
  local_78[2] = *(undefined4 *)(param_1 + 0x14);
  local_78[3] = *(undefined4 *)(param_1 + 0x18);
  local_68[0] = param_2;
  local_68[1] = param_3;
  local_68[2] = param_4;
  local_68[3] = param_5;
  do {
    uVar2 = *puVar7;
    if ((0x23 < uVar2) && (uVar2 <= iVar1 - 1U)) {
      lVar3 = ScAnsiToUnicodeString((char *)(param_1 + uVar2),*pp_Var6);
      if (lVar3 < 0) {
        lVar4 = lVar3;
      }
    }
    puVar7 = puVar7 + 1;
    pp_Var6 = pp_Var6 + 1;
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  return lVar4;
}



===== ScExtractFirmwareRevision @ 14000f7bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl ScExtractFirmwareRevision(struct _STORAGE_HW_FIRMWARE_INFO * __ptr64,struct
   _UNICODE_STRING * __ptr64) */

long __cdecl ScExtractFirmwareRevision(_STORAGE_HW_FIRMWARE_INFO *param_1,_UNICODE_STRING *param_2)

{
  long lVar1;
  uint uVar2;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined1 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  local_18 = 0;
  uVar2 = 0;
  while( true ) {
    if ((byte)param_1[9] <= uVar2) {
      return 0;
    }
    if (param_1[(ulonglong)uVar2 * 0x20 + 0x20] == param_1[10]) break;
    uVar2 = uVar2 + 1;
  }
  local_28 = *(undefined8 *)(param_1 + (ulonglong)uVar2 * 0x20 + 0x28);
  uStack_20 = *(undefined8 *)(param_1 + (ulonglong)uVar2 * 0x20 + 0x28 + 8);
  lVar1 = ScAnsiToUnicodeString((char *)&local_28,param_2);
  return lVar1;
}



===== `scalar_deleting_destructor' @ 14000f840 =====

/* public: virtual void * __ptr64 __cdecl SC_DISK::`scalar deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall SC_DISK::_scalar_deleting_destructor_(SC_DISK *this,uint param_1)

{
  ~SC_DISK(this);
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0);
  }
  return this;
}



===== AddEntries @ 14000f880 =====

/* public: class SC_DISK_LAYOUT * __ptr64 __cdecl SC_DISK_LAYOUT::AddEntries(unsigned long) __ptr64
    */

SC_DISK_LAYOUT * __thiscall SC_DISK_LAYOUT::AddEntries(SC_DISK_LAYOUT *this,ulong param_1)

{
  int iVar1;
  SC_DISK_LAYOUT *_Dst;
  
  iVar1 = *(int *)(this + 4);
  _Dst = (SC_DISK_LAYOUT *)ExAllocatePool2(0x40,iVar1 * 0x90 + 0xc0,0x6d506353);
  if (_Dst != (SC_DISK_LAYOUT *)0x0) {
    memmove(_Dst,this,(ulonglong)(iVar1 * 0x90 + 0x30));
    memset(_Dst + (ulonglong)*(uint *)(this + 4) * 0x90 + 0x30,0,0x90);
    *(int *)(_Dst + 4) = *(int *)(_Dst + 4) + 1;
  }
  return _Dst;
}



===== AddPartition @ 14000f910 =====

/* public: long __cdecl SC_DISK::AddPartition(struct _GUID,unsigned char,unsigned short *
   __ptr64,unsigned __int64,unsigned char,class SC_DISK_LAYOUT * __ptr64 * __ptr64) __ptr64 */

long __thiscall
SC_DISK::AddPartition
          (SC_DISK *this,undefined4 *param_2,undefined8 param_3,undefined8 param_4,__uint64 param_5,
          undefined8 param_6,SC_DISK_LAYOUT **param_7)

{
  int iVar1;
  SC_DISK_LAYOUT *pSVar2;
  SC_DISK_LAYOUT **ppSVar3;
  long lVar4;
  __uint64 _Var5;
  undefined8 uVar6;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  ppSVar3 = param_7;
  param_5 = 0;
  pSVar2 = *param_7;
  uVar6 = param_4;
  _Var5 = FindLargestFreeRun(this,pSVar2,&param_5);
  if (_Var5 == 0) {
    lVar4 = -0x3fc7ffed;
  }
  else {
    iVar1 = *(int *)pSVar2;
    if (iVar1 == 0) {
      lVar4 = AddPartitionMbr(this,param_5,_Var5,(uchar)uVar6,ppSVar3);
    }
    else {
      if (iVar1 != 1) {
        return 0;
      }
      local_28 = *param_2;
      uStack_24 = param_2[1];
      uStack_20 = param_2[2];
      uStack_1c = param_2[3];
      lVar4 = AddPartitionGpt((SC_DISK *)0x1,param_5,_Var5,&local_28,param_4,ppSVar3);
    }
  }
  return lVar4;
}



===== AddPartitionGpt @ 14000f9cc =====

/* protected: long __cdecl SC_DISK::AddPartitionGpt(unsigned __int64,unsigned __int64,struct
   _GUID,unsigned short * __ptr64,class SC_DISK_LAYOUT * __ptr64 * __ptr64) __ptr64 */

long __thiscall
SC_DISK::AddPartitionGpt
          (undefined8 param_1_00,__uint64 param_1,undefined8 param_2,undefined8 *param_4,
          ushort *param_5,undefined8 *param_6)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long lVar3;
  SC_DISK_LAYOUT *pSVar4;
  __uint64 _Var5;
  longlong lVar6;
  
  _Var5 = param_1;
  pSVar4 = SC_DISK_LAYOUT::AddEntries((SC_DISK_LAYOUT *)*param_6,(ulong)param_1);
  if (pSVar4 == (SC_DISK_LAYOUT *)0x0) {
    lVar3 = -0x3fffff66;
  }
  else {
    uVar1 = *param_4;
    uVar2 = param_4[1];
    lVar6 = (ulonglong)(*(int *)(pSVar4 + 4) - 1) * 0x90;
    *(undefined4 *)(pSVar4 + lVar6 + 0x30) = 1;
    *(__uint64 *)(pSVar4 + lVar6 + 0x38) = param_1;
    *(undefined8 *)(pSVar4 + lVar6 + 0x40) = param_2;
    pSVar4[lVar6 + 0x4c] = (SC_DISK_LAYOUT)0x1;
    *(undefined8 *)(pSVar4 + lVar6 + 0x50) = uVar1;
    *(undefined8 *)(pSVar4 + lVar6 + 0x50 + 8) = uVar2;
    RtlStringCbCopyW((ushort *)(pSVar4 + lVar6 + 0x78),_Var5,param_5);
    lVar3 = SC_ENV::CreateGuid((_GUID *)(pSVar4 + lVar6 + 0x60));
    if (lVar3 < 0) {
      ExFreePoolWithTag(pSVar4,0);
    }
    else {
      ExFreePoolWithTag(*param_6);
      *param_6 = pSVar4;
    }
  }
  return lVar3;
}



===== AddPartitionMbr @ 14000faa8 =====

/* protected: long __cdecl SC_DISK::AddPartitionMbr(unsigned __int64,unsigned __int64,unsigned
   char,class SC_DISK_LAYOUT * __ptr64 * __ptr64) __ptr64 */

long __thiscall
SC_DISK::AddPartitionMbr
          (SC_DISK *this,__uint64 param_1,__uint64 param_2,uchar param_3,SC_DISK_LAYOUT **param_4)

{
  uint uVar1;
  SC_DISK_LAYOUT *pSVar2;
  uchar uVar3;
  SC_DISK_LAYOUT *pSVar4;
  undefined8 uVar5;
  uint uVar6;
  ulonglong uVar7;
  
  uVar5 = 0;
  pSVar2 = *param_4;
  uVar1 = *(uint *)(pSVar2 + 4);
  uVar7 = 0;
  while ((uVar6 = (uint)uVar7, uVar6 < uVar1 && (uVar6 < 4))) {
    pSVar4 = pSVar2 + uVar7 * 0x90;
    uVar3 = SC_PART_ENTRY::IsUnused((SC_PART_ENTRY *)(pSVar4 + 0x30));
    if (uVar3 != '\0') {
      *(__uint64 *)(pSVar4 + 0x38) = param_1;
      *(long *)(pSVar4 + 0x30) = (long)uVar5;
      *(__uint64 *)(pSVar4 + 0x40) = param_2;
      pSVar4[0x4c] = (SC_DISK_LAYOUT)0x1;
      pSVar4[0x50] = (SC_DISK_LAYOUT)0xe7;
      *(int *)(pSVar4 + 0x54) = (int)(param_1 >> ((byte)*(undefined4 *)(this + 0xf0) & 0x3f));
      return (long)uVar5;
    }
    uVar7 = (ulonglong)(uVar6 + 1);
  }
  return -0x3ffffddb;
}



===== CreatePartitionTable @ 14000fb58 =====

/* public: long __cdecl SC_DISK::CreatePartitionTable(struct _CREATE_DISK * __ptr64) __ptr64 */

long __thiscall SC_DISK::CreatePartitionTable(SC_DISK *this,_CREATE_DISK *param_1)

{
  int iVar1;
  long lVar2;
  SC_DISK *local_res10 [3];
  
  local_res10[0] = this;
  if (param_1 != (_CREATE_DISK *)0x0) {
    iVar1 = *(int *)param_1;
    if (iVar1 == 0) {
      SC_MBR::Initialize((SC_MBR *)local_res10,this);
      lVar2 = SC_MBR::CreatePartitionTable((SC_MBR *)local_res10,param_1);
      return lVar2;
    }
    if (iVar1 == 1) {
      lVar2 = SC_GPT::CreatePartitionTable((SC_GPT *)local_res10,param_1);
      return lVar2;
    }
    if (iVar1 != 2) {
      return -0x3fffff45;
    }
  }
  lVar2 = SC_RAW::CreatePartitionTable((SC_RAW *)local_res10);
  return lVar2;
}



===== FindFreeRunGpt @ 14000fbcc =====

/* public: unsigned __int64 __cdecl SC_DISK_LAYOUT::FindFreeRunGpt(unsigned __int64,unsigned
   char,unsigned __int64 * __ptr64) __ptr64 */

__uint64 __thiscall
SC_DISK_LAYOUT::FindFreeRunGpt
          (SC_DISK_LAYOUT *this,__uint64 param_1,uchar param_2,__uint64 *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  uchar uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  __uint64 _Var6;
  SC_DISK_LAYOUT *pSVar7;
  ulonglong uVar8;
  __uint64 _Var9;
  __uint64 _Var10;
  
  uVar1 = *(uint *)(this + 4);
  _Var9 = 0;
  *param_3 = 0;
  if (uVar1 != *(uint *)(this + 0x28)) {
    _Var6 = *(__uint64 *)(this + 0x18);
    uVar4 = 0;
    uVar8 = *(longlong *)(this + 0x20) + _Var6;
    _Var10 = _Var6;
    if (uVar1 != 0) {
      pSVar7 = this + 0x40;
      uVar5 = (ulonglong)uVar1;
      do {
        uVar3 = SC_PART_ENTRY::IsUnused((SC_PART_ENTRY *)(pSVar7 + -0x10));
        if (uVar3 == '\0') {
          uVar2 = *(ulonglong *)(pSVar7 + -8);
          if ((_Var10 < uVar2) && (uVar4 < uVar2 - _Var10)) {
            uVar4 = uVar2 - _Var10;
            _Var6 = _Var10;
          }
          _Var10 = *(longlong *)pSVar7 + uVar2;
        }
        pSVar7 = pSVar7 + 0x90;
        uVar5 = uVar5 - 1;
      } while (uVar5 != 0);
    }
    if ((_Var10 < uVar8) && (uVar4 < uVar8 - _Var10)) {
      uVar4 = uVar8 - _Var10;
      _Var6 = _Var10;
    }
    if (uVar4 != 0) {
      *param_3 = _Var6;
      _Var9 = uVar4;
    }
  }
  return _Var9;
}



===== FindLargestFreeRun @ 14000fc90 =====

/* public: unsigned __int64 __cdecl SC_DISK::FindLargestFreeRun(class SC_DISK_LAYOUT *
   __ptr64,unsigned __int64 * __ptr64) __ptr64 */

__uint64 __thiscall
SC_DISK::FindLargestFreeRun(SC_DISK *this,SC_DISK_LAYOUT *param_1,__uint64 *param_2)

{
  int iVar1;
  longlong lVar2;
  __uint64 _Var3;
  __uint64 _Var4;
  __uint64 _Var5;
  ulonglong uVar6;
  __uint64 in_R9;
  ulonglong uVar7;
  __uint64 local_res8;
  uchar in_stack_ffffffffffffffe8;
  
  *param_2 = 0;
  lVar2 = *(longlong *)(this + 8) + -0x41664d4653966cb1;
  if (lVar2 == 0) {
    lVar2 = *(longlong *)(this + 0x10) + 0x6a2bc3bfdd3adc41;
  }
  if (lVar2 == 0) {
    lVar2 = 0x200000;
  }
  else {
    iVar1 = memcmp(this + 8,&GUID_DEVCLASS_SMRDISK,0x10);
    lVar2 = (-(ulonglong)(iVar1 != 0) & 0xfffffffff0100000) + 0x10000000;
  }
  _Var3 = 0;
  local_res8 = 0;
  if (*(int *)param_1 == 0) {
    _Var3 = SC_DISK_LAYOUT::FindFreeRunMbr
                      (param_1,*(__uint64 *)(this + 0xd0),*(ulong *)(this + 0xec),in_R9,
                       in_stack_ffffffffffffffe8,&local_res8);
  }
  else {
    _Var5 = 0;
    if (*(int *)param_1 != 1) goto LAB_14000fd4a;
    _Var3 = SC_DISK_LAYOUT::FindFreeRunGpt(param_1,0,'\0',&local_res8);
  }
  _Var5 = local_res8;
LAB_14000fd4a:
  _Var4 = 0;
  if (_Var3 != 0) {
    uVar7 = ~(lVar2 - 1U);
    if (*(longlong *)(this + 0x138) == 0) {
      uVar6 = (_Var5 - 1) + lVar2 & uVar7;
    }
    else {
      uVar6 = (ulonglong)*(uint *)(*(longlong *)(this + 0x138) + 0x18);
      uVar6 = ((_Var5 - 1) + uVar6 + lVar2 & uVar7) - uVar6;
    }
    if (uVar6 < _Var3 + _Var5) {
      _Var4 = (_Var3 + _Var5) - uVar6 & uVar7;
      if (_Var4 != 0) {
        *param_2 = uVar6;
      }
    }
    else {
      _Var4 = 0;
    }
  }
  return _Var4;
}



===== FindPartition @ 14000fdb4 =====

/* public: unsigned long __cdecl SC_DISK_LAYOUT::FindPartition(struct _GUID,unsigned char) __ptr64
    */

ulong __thiscall
SC_DISK_LAYOUT::FindPartition(SC_DISK_LAYOUT *this,undefined4 *param_2,SC_DISK_LAYOUT param_3)

{
  ulong uVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  uVar1 = 0xffffffff;
  uVar3 = 0;
  if (*(int *)this == 0) {
    while (uVar2 = (uint)uVar3, uVar2 < *(uint *)(this + 4)) {
      if (this[uVar3 * 0x90 + 0x50] == param_3) {
        return uVar2;
      }
      uVar3 = (ulonglong)(uVar2 + 1);
    }
  }
  else if (*(int *)this == 1) {
    local_18 = *param_2;
    uStack_14 = param_2[1];
    uStack_10 = param_2[2];
    uStack_c = param_2[3];
    uVar1 = FindPartitionGpt(this,&local_18);
  }
  return uVar1;
}



===== FindPartitionGpt @ 14000fe18 =====

/* public: unsigned long __cdecl SC_DISK_LAYOUT::FindPartitionGpt(struct _GUID) __ptr64 */

ulong __thiscall SC_DISK_LAYOUT::FindPartitionGpt(SC_DISK_LAYOUT *this,longlong *param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  
  for (uVar2 = 0; (uint)uVar2 < *(uint *)(this + 4); uVar2 = (ulonglong)((uint)uVar2 + 1)) {
    lVar1 = *(longlong *)(this + uVar2 * 0x90 + 0x50) - *param_2;
    if (lVar1 == 0) {
      lVar1 = *(longlong *)(this + uVar2 * 0x90 + 0x58) - param_2[1];
    }
    if (lVar1 == 0) goto LAB_14000fe4f;
  }
  uVar2 = 0xffffffff;
LAB_14000fe4f:
  return (ulong)uVar2;
}



===== GetFruIdDescPost @ 14000fe5c =====

/* private: long __cdecl SC_DISK::GetFruIdDescPost(struct _STORAGE_FRU_ID_DESCRIPTOR * __ptr64)
   __ptr64 */

long __thiscall SC_DISK::GetFruIdDescPost(SC_DISK *this,_STORAGE_FRU_ID_DESCRIPTOR *param_1)

{
  long lVar1;
  char *_Dst;
  
  _Dst = (char *)ExAllocatePool2(0x40,*(int *)(param_1 + 8) + 1,0x6d506353);
  if (_Dst == (char *)0x0) {
    lVar1 = -0x3fffff66;
  }
  else {
    memmove(_Dst,param_1 + 0xc,(ulonglong)*(uint *)(param_1 + 8));
    lVar1 = ScAnsiToUnicodeString(_Dst,(_UNICODE_STRING *)(this + 0x120));
    ExFreePoolWithTag(_Dst,0);
  }
  return lVar1;
}



===== GetStoragePropertyPost @ 14000fef0 =====

/* protected: virtual long __cdecl SC_DISK::GetStoragePropertyPost(enum _STORAGE_PROPERTY_ID,struct
   _STORAGE_DESCRIPTOR_HEADER * __ptr64) __ptr64 */

long __thiscall
SC_DISK::GetStoragePropertyPost
          (SC_DISK *this,_STORAGE_PROPERTY_ID param_1,_STORAGE_DESCRIPTOR_HEADER *param_2)

{
  uint uVar1;
  long lVar2;
  
  lVar2 = 0;
  if ((int)param_1 < 0xf) {
    if ((((param_1 != 0xe) && (param_1 != 4)) && (param_1 == 6)) &&
       (((uVar1 = *(uint *)(this + 0xec), *(uint *)(param_2 + 0x10) != uVar1 ||
         (*(uint *)(param_2 + 0x14) < uVar1)) || (*(uint *)(param_2 + 0x14) % uVar1 != 0)))) {
      lVar2 = -0x3ffff6f5;
    }
  }
  else if ((param_1 != 0x15) && (param_1 != 0x39)) {
    if (param_1 == 0x3a) {
      if ((*(uint *)(param_2 + 0x20) < *(uint *)param_2) ||
         (*(int *)(param_2 + 4) - 1U < *(uint *)(param_2 + 0x20))) {
        *(undefined4 *)(param_2 + 0x20) = 0;
      }
    }
    else if ((param_1 != 0x3c) && (param_1 == 0x41)) {
      lVar2 = GetFruIdDescPost(this,(_STORAGE_FRU_ID_DESCRIPTOR *)param_2);
    }
  }
  return lVar2;
}



===== IsRecognized @ 14000ff84 =====

/* public: unsigned char __cdecl SC_PART_ENTRY::IsRecognized(void) __ptr64 */

uchar __thiscall SC_PART_ENTRY::IsRecognized(SC_PART_ENTRY *this)

{
  SC_PART_ENTRY SVar1;
  longlong lVar2;
  bool bVar3;
  
  if (*(int *)this == 0) {
    SVar1 = this[0x20];
    if (((byte)SVar1 < 0x2e) && ((0x3f80000058d2U >> ((ulonglong)(byte)SVar1 & 0x3f) & 1) != 0)) {
      return '\x01';
    }
    bVar3 = SVar1 == (SC_PART_ENTRY)0xef;
  }
  else {
    if (*(int *)this != 1) {
      return '\0';
    }
    lVar2 = *(longlong *)(this + 0x20) + -0x45b94df957434f53;
    if (lVar2 == 0) {
      lVar2 = *(longlong *)(this + 0x28) + -0x7c4506f070239e8e;
    }
    if (lVar2 == 0) {
      return '\x01';
    }
    lVar2 = *(longlong *)(this + 0x20) + -0x43f094cb57434f53;
    if (lVar2 == 0) {
      lVar2 = *(longlong *)(this + 0x28) + -0x7da5cf103cd733a5;
    }
    if (lVar2 == 0) {
      return '\x01';
    }
    lVar2 = *(longlong *)(this + 0x20) + -0x4433b9e5ebd0a0a2;
    if (lVar2 == 0) {
      lVar2 = *(longlong *)(this + 0x28) + 0x3866d94849973f79;
    }
    if (lVar2 == 0) {
      return '\x01';
    }
    lVar2 = *(longlong *)(this + 0x20) + -0x405e8f4557434f53;
    if (lVar2 == 0) {
      lVar2 = *(longlong *)(this + 0x28) + 0x2ccfbc7592e7dc76;
    }
    if (lVar2 == 0) {
      return '\x01';
    }
    lVar2 = *(longlong *)(this + 0x20) + -0x4d4006d1de94bba4;
    if (lVar2 == 0) {
      lVar2 = *(longlong *)(this + 0x28) + 0x532986fe2a40955f;
    }
    if (lVar2 == 0) {
      return '\x01';
    }
    lVar2 = *(longlong *)(this + 0x20) + -0x44d523f257434f53;
    if (lVar2 == 0) {
      lVar2 = *(longlong *)(this + 0x28) + 0x6f659254498cf58;
    }
    if (lVar2 == 0) {
      return '\x01';
    }
    lVar2 = *(longlong *)(this + 0x20) + -0x41967fe057434f53;
    if (lVar2 == 0) {
      lVar2 = *(longlong *)(this + 0x28) + 0x7bcb9bae84bdbd65;
    }
    if (lVar2 == 0) {
      return '\x01';
    }
    lVar2 = *(longlong *)(this + 0x20) + -0x4014432e57434f53;
    if (lVar2 == 0) {
      lVar2 = *(longlong *)(this + 0x28) + -0x6a00c0a9ea8d4cae;
    }
    if (lVar2 == 0) {
      return '\x01';
    }
    lVar2 = *(longlong *)(this + 0x20) + -0x4a05c69157434f53;
    if (lVar2 == 0) {
      lVar2 = *(longlong *)(this + 0x28) + 0x31d62d50c28fb145;
    }
    if (lVar2 == 0) {
      return '\x01';
    }
    lVar2 = *(longlong *)(this + 0x20) + -0x460b4b8157434f53;
    if (lVar2 == 0) {
      lVar2 = *(longlong *)(this + 0x28) + -0x146d13feb6ff19a3;
    }
    if (lVar2 == 0) {
      return '\x01';
    }
    lVar2 = *(longlong *)(this + 0x20) + -0x4e84e84d57434f53;
    if (lVar2 == 0) {
      lVar2 = *(longlong *)(this + 0x28) + 0x2046fb4244130c56;
    }
    if (lVar2 == 0) {
      return '\x01';
    }
    lVar2 = *(longlong *)(this + 0x20) + -0x4631e3e357434f53;
    if (lVar2 == 0) {
      lVar2 = *(longlong *)(this + 0x28) + 0x558cc7db2dd93a5b;
    }
    bVar3 = lVar2 == 0;
  }
  if (bVar3) {
    return '\x01';
  }
  return '\0';
}



===== RtlStringCbCopyW @ 140010148 =====

/* long __cdecl RtlStringCbCopyW(unsigned short * __ptr64,unsigned __int64,unsigned short const *
   __ptr64) */

long __cdecl RtlStringCbCopyW(ushort *param_1,__uint64 param_2,ushort *param_3)

{
  ushort uVar1;
  ushort *puVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar4 = (longlong)param_3 - (longlong)param_1;
  lVar3 = 0x24;
  do {
    if ((lVar3 == -0x7fffffda) || (uVar1 = *(ushort *)(lVar4 + (longlong)param_1), uVar1 == 0))
    break;
    *param_1 = uVar1;
    param_1 = param_1 + 1;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  puVar2 = param_1 + -1;
  if (lVar3 != 0) {
    puVar2 = param_1;
  }
  *puVar2 = 0;
  return ~-(uint)(lVar3 != 0) & 0x80000005;
}



===== SetPartition @ 14001019c =====

/* public: long __cdecl SC_DISK::SetPartition(unsigned long,struct _SET_PARTITION_INFORMATION_EX *
   __ptr64) __ptr64 */

long __thiscall
SC_DISK::SetPartition(SC_DISK *this,ulong param_1,_SET_PARTITION_INFORMATION_EX *param_2)

{
  undefined8 uVar1;
  SC_DISK_LAYOUT *pSVar2;
  uchar uVar3;
  long lVar4;
  SC_DISK_LAYOUT **ppSVar5;
  int iVar6;
  SC_DISK_LAYOUT *pSVar7;
  SC_DISK_LAYOUT *local_res8;
  
  local_res8 = (SC_DISK_LAYOUT *)0x0;
  iVar6 = *(int *)(this + 0x100);
  if ((iVar6 != 0) && (iVar6 != 1)) {
    return -0x3fffff45;
  }
  if (iVar6 != *(int *)param_2) {
    return -0x3ffffff3;
  }
  ppSVar5 = &local_res8;
  lVar4 = ReadPartitionTable(this,ppSVar5);
  pSVar2 = local_res8;
  if (-1 < lVar4) {
    iVar6 = *(int *)(this + 0x100);
    if ((*(int *)local_res8 == iVar6) && (param_1 < *(uint *)(local_res8 + 4))) {
      pSVar7 = local_res8 + (ulonglong)param_1 * 0x90;
      uVar3 = SC_PART_ENTRY::IsUnused((SC_PART_ENTRY *)(pSVar7 + 0x30));
      if ((uVar3 == '\0') &&
         (uVar3 = SC_PART_ENTRY::IsContainer((SC_PART_ENTRY *)(pSVar7 + 0x30)), uVar3 == '\0')) {
        if (iVar6 == 0) {
          *(_SET_PARTITION_INFORMATION_EX *)(pSVar7 + 0x50) = param_2[8];
          pSVar7[0x4c] = (SC_DISK_LAYOUT)0x1;
          lVar4 = ResetPartitionCache(this);
          if (lVar4 < 0) goto LAB_1400102a4;
        }
        else if (iVar6 == 1) {
          uVar1 = *(undefined8 *)(param_2 + 0x10);
          *(undefined8 *)(pSVar7 + 0x50) = *(undefined8 *)(param_2 + 8);
          *(undefined8 *)(pSVar7 + 0x58) = uVar1;
          uVar1 = *(undefined8 *)(param_2 + 0x20);
          *(undefined8 *)(pSVar7 + 0x60) = *(undefined8 *)(param_2 + 0x18);
          *(undefined8 *)(pSVar7 + 0x68) = uVar1;
          *(undefined8 *)(pSVar7 + 0x70) = *(undefined8 *)(param_2 + 0x28);
          RtlStringCbCopyW((ushort *)(pSVar7 + 0x78),(__uint64)ppSVar5,(ushort *)(param_2 + 0x30));
        }
        lVar4 = WritePartitionTable(this,pSVar2);
        goto LAB_1400102a4;
      }
    }
    lVar4 = -0x3ffffff3;
  }
LAB_1400102a4:
  if (pSVar2 != (SC_DISK_LAYOUT *)0x0) {
    ExFreePoolWithTag(pSVar2,0);
  }
  return lVar4;
}



===== UpdateControl @ 1400102d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl SC_DISK::UpdateControl(void) __ptr64 */

long __thiscall SC_DISK::UpdateControl(SC_DISK *this)

{
  long lVar1;
  
  lVar1 = (**(code **)(*(longlong *)this + 0x10))(this,0x70140,0,0,0,0);
  return lVar1;
}



===== WritePartitionTable @ 14001030c =====

/* public: long __cdecl SC_DISK::WritePartitionTable(class SC_DISK_LAYOUT * __ptr64) __ptr64 */

long __thiscall SC_DISK::WritePartitionTable(SC_DISK *this,SC_DISK_LAYOUT *param_1)

{
  long lVar1;
  SC_DISK *local_res8;
  undefined4 local_28;
  undefined4 local_24;
  undefined8 local_20;
  undefined8 uStack_18;
  
  local_24 = 0;
  lVar1 = 0;
  local_20 = 0;
  uStack_18 = 0;
  if (*(int *)(this + 0x100) == 2) {
    local_28 = *(undefined4 *)param_1;
    lVar1 = CreatePartitionTable(this,(_CREATE_DISK *)&local_28);
    if (lVar1 < 0) {
      return lVar1;
    }
    lVar1 = ResetPartitionCache(this);
    if (lVar1 < 0) {
      return lVar1;
    }
  }
  if (*(int *)param_1 == 0) {
    if ((*(int *)(this + 0x100) != 0) &&
       ((((*(int *)(param_1 + 4) != 4 || (param_1[0x50] != (SC_DISK_LAYOUT)0xee)) ||
         (param_1[0xe0] != (SC_DISK_LAYOUT)0x0)) ||
        ((param_1[0x170] != (SC_DISK_LAYOUT)0x0 || (param_1[0x200] != (SC_DISK_LAYOUT)0x0)))))) {
      return -0x3fffff45;
    }
    SC_MBR::Initialize((SC_MBR *)&local_res8,this);
    lVar1 = SC_MBR::WritePartitionTable((SC_MBR *)&local_res8,param_1);
  }
  else {
    if (*(int *)param_1 != 1) {
      return lVar1;
    }
    local_res8 = this;
    lVar1 = SC_GPT::WritePartitionTable((SC_GPT *)&local_res8,param_1,*(int *)(this + 0x100) != 1);
  }
  return lVar1;
}



===== WriteSectors @ 1400103ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl SC_DISK::WriteSectors(unsigned long,unsigned __int64,void * __ptr64) __ptr64
    */

long __thiscall SC_DISK::WriteSectors(SC_DISK *this,ulong param_1,__uint64 param_2,void *param_3)

{
  long lVar1;
  
  if (param_3 == (void *)0x0) {
    param_3 = *(void **)(this + 0x108);
  }
  lVar1 = (**(code **)(*(longlong *)this + 0x40))
                    (this,param_2 << ((byte)*(undefined4 *)(this + 0xf0) & 0x3f),
                     param_1 << ((byte)*(undefined4 *)(this + 0xf0) & 0x1f),param_3);
  return lVar1;
}



===== Feature_3199623483__private_IsEnabledDeviceUsageNoInline @ 140010430 =====

ulonglong Feature_3199623483__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_3199623483__private_featureState;
  if ((Feature_3199623483__private_featureState & 0x10) == 0) {
    uVar1 = Feature_3199623483__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_3199623483__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_3199623483__private_IsEnabledFallback @ 140010468 =====

void Feature_3199623483__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_3199623483__private_descriptor);
  return;
}



===== SC_DRIVE @ 140010484 =====

/* public: __cdecl SC_DRIVE::SC_DRIVE(void) __ptr64 */

SC_DRIVE * __thiscall SC_DRIVE::SC_DRIVE(SC_DRIVE *this)

{
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  SC_DISK::SC_DISK((SC_DISK *)this);
  *(undefined ***)this = &_vftable_;
  *(undefined2 *)(this + 0x188) = 0;
  this[0x18b] = (SC_DRIVE)0x0;
  *(undefined8 *)(this + 0x1a0) = 0;
  *(undefined8 *)(this + 0x1a8) = 0;
  *(undefined8 *)(this + 0x18c) = 0;
  *(undefined8 *)(this + 0x194) = 0;
  *(undefined8 *)(this + 0x1b0) = 0;
  *(undefined4 *)(this + 0x1b8) = 0;
  *(undefined8 *)(this + 0x1c0) = 0;
  *(undefined8 *)(this + 0x1c8) = 0;
  memset(&local_58,0,0x48);
  *(undefined8 *)(this + 0x1e0) = local_58;
  *(undefined8 *)(this + 0x1e8) = uStack_50;
  *(undefined8 *)(this + 0x228) = 0;
  *(undefined8 *)(this + 0x1f0) = local_48;
  *(undefined8 *)(this + 0x1f8) = uStack_40;
  this[0x230] = (SC_DRIVE)0x0;
  *(undefined8 *)(this + 0x200) = local_38;
  *(undefined8 *)(this + 0x208) = uStack_30;
  *(undefined8 *)(this + 0x240) = 0;
  *(undefined8 *)(this + 0x210) = local_28;
  *(undefined8 *)(this + 0x218) = uStack_20;
  *(undefined8 *)(this + 0x220) = local_18;
  *(undefined4 *)(this + 0x234) = 0;
  *(undefined4 *)(this + 0x238) = 0;
  return this;
}



===== ~SC_DRIVE @ 140010570 =====

/* public: virtual __cdecl SC_DRIVE::~SC_DRIVE(void) __ptr64 */

void __thiscall SC_DRIVE::~SC_DRIVE(SC_DRIVE *this)

{
  *(undefined ***)this = &_vftable_;
  if (*(longlong *)(this + 0x1a8) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 0x1a8),0);
  }
  if (*(longlong *)(this + 0x1a0) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 0x1a0),0);
  }
  SC_DISK::~SC_DISK((SC_DISK *)this);
  return;
}



===== `vector_deleting_destructor' @ 1400105d0 =====

/* public: virtual void * __ptr64 __cdecl SC_DRIVE::`vector deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall SC_DRIVE::_vector_deleting_destructor_(SC_DRIVE *this,uint param_1)

{
  ~SC_DRIVE(this);
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0);
  }
  return this;
}



===== CreateMetadata @ 140010610 =====

/* public: long __cdecl SC_DRIVE::CreateMetadata(unsigned short * __ptr64,class SC_DRIVE_HEADER *
   __ptr64,unsigned __int64,unsigned char) __ptr64 */

long __thiscall
SC_DRIVE::CreateMetadata
          (SC_DRIVE *this,ushort *param_1,SC_DRIVE_HEADER *param_2,__uint64 param_3,uchar param_4)

{
  long lVar1;
  ulong uVar2;
  ulonglong uVar3;
  SC_DISK_LAYOUT *pSVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  SC_DISK_LAYOUT *local_res20;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  local_res20 = (SC_DISK_LAYOUT *)0x0;
  lVar1 = SC_DISK::ReadPartitionTable((SC_DISK *)this,&local_res20);
  pSVar4 = local_res20;
  if (-1 < lVar1) {
    if (*(int *)(this + 0x100) == 2) {
      ExFreePoolWithTag(local_res20,0);
      local_res20 = (SC_DISK_LAYOUT *)0x0;
      lVar1 = InitializePartitionTable(this,&local_res20);
      if (lVar1 < 0) goto LAB_14001075f;
      uVar5 = 0xe75caf8f;
      uVar6 = 0x4ceef680;
      uVar7 = 0x1b0a3af;
      uVar8 = 0x2dfc6ee5;
    }
    else {
      uVar5 = 0xe75caf8f;
      uVar6 = 0x4ceef680;
      uVar7 = 0x1b0a3af;
      uVar8 = 0x2dfc6ee5;
      local_28 = 0xe75caf8f;
      uStack_24 = 0x4ceef680;
      uStack_20 = 0x1b0a3af;
      uStack_1c = 0x2dfc6ee5;
      uVar2 = SC_DISK_LAYOUT::FindPartition(local_res20,&local_28,0xe7);
      if (uVar2 != 0xffffffff) {
        lVar1 = -0x3fffffcb;
        goto LAB_140010763;
      }
    }
    local_28 = uVar5;
    uStack_24 = uVar6;
    uStack_20 = uVar7;
    uStack_1c = uVar8;
    lVar1 = SC_DISK::AddPartition((SC_DISK *)this,&local_28);
    pSVar4 = local_res20;
    if (-1 < lVar1) {
      local_28 = 0xe75caf8f;
      uStack_24 = 0x4ceef680;
      uStack_20 = 0x1b0a3af;
      uStack_1c = 0x2dfc6ee5;
      uVar2 = SC_DISK_LAYOUT::FindPartition(local_res20,&local_28,0xe7);
      uVar3 = (ulonglong)uVar2;
      *(undefined4 *)(this + 0x1b8) = *(undefined4 *)(pSVar4 + uVar3 * 0x90 + 0x48);
      *(undefined8 *)(this + 0x1c0) = *(undefined8 *)(pSVar4 + uVar3 * 0x90 + 0x38);
      *(undefined8 *)(this + 0x1c8) = *(undefined8 *)(pSVar4 + uVar3 * 0x90 + 0x40);
      lVar1 = ZeroMetadata(this);
      if (-1 < lVar1) {
        lVar1 = WriteHeader(this,param_2);
        if (-1 < lVar1) {
          lVar1 = SC_DISK::WritePartitionTable((SC_DISK *)this,pSVar4);
        }
      }
      goto LAB_140010763;
    }
  }
LAB_14001075f:
  pSVar4 = local_res20;
LAB_140010763:
  if (pSVar4 != (SC_DISK_LAYOUT *)0x0) {
    ExFreePoolWithTag(pSVar4,0);
  }
  return lVar1;
}



===== DeleteMetadata @ 14001079c =====

/* public: long __cdecl SC_DRIVE::DeleteMetadata(void) __ptr64 */

long __thiscall SC_DRIVE::DeleteMetadata(SC_DRIVE *this)

{
  SC_DISK_LAYOUT *pSVar1;
  long lVar2;
  ulong uVar3;
  longlong lVar4;
  SC_DISK_LAYOUT *local_res10;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  local_res10 = (SC_DISK_LAYOUT *)0x0;
  lVar2 = SC_DISK::ReadPartitionTable((SC_DISK *)this,&local_res10);
  pSVar1 = local_res10;
  if (-1 < lVar2) {
    local_18 = 0xe75caf8f;
    uStack_14 = 0x4ceef680;
    uStack_10 = 0x1b0a3af;
    uStack_c = 0x2dfc6ee5;
    uVar3 = SC_DISK_LAYOUT::FindPartition(local_res10,&local_18,0xe7);
    if (uVar3 == 0xffffffff) {
      lVar2 = -0x3fffffcc;
    }
    else {
      lVar4 = (ulonglong)uVar3 * 0x90;
      memset(pSVar1 + lVar4 + 0x30,0,0x90);
      *(undefined4 *)(pSVar1 + lVar4 + 0x30) = *(undefined4 *)pSVar1;
      pSVar1[lVar4 + 0x4c] = (SC_DISK_LAYOUT)0x1;
      local_18 = 0xe7addcb4;
      uStack_14 = 0x4539dc34;
      uStack_10 = 0xbdeb769a;
      uStack_c = 0x7e6fbe07;
      uVar3 = SC_DISK_LAYOUT::FindPartition(pSVar1,&local_18,0xd7);
      if (uVar3 != 0xffffffff) {
        lVar4 = (ulonglong)uVar3 * 0x90;
        memset(pSVar1 + lVar4 + 0x30,0,0x90);
        *(undefined4 *)(pSVar1 + lVar4 + 0x30) = *(undefined4 *)pSVar1;
        pSVar1[lVar4 + 0x4c] = (SC_DISK_LAYOUT)0x1;
      }
      lVar2 = SC_DISK::WritePartitionTable((SC_DISK *)this,pSVar1);
      if (-1 < lVar2) {
        *(undefined4 *)(this + 0x1b8) = 0;
        *(undefined8 *)(this + 0x1c0) = 0;
        *(undefined8 *)(this + 0x1c8) = 0;
      }
    }
  }
  if (pSVar1 != (SC_DISK_LAYOUT *)0x0) {
    ExFreePoolWithTag(pSVar1,0);
  }
  return lVar2;
}



===== Format @ 1400108c4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: void __cdecl SC_DRIVE_HEADER::Format(unsigned char * __ptr64 * __ptr64,unsigned long)
   __ptr64 */

void __thiscall SC_DRIVE_HEADER::Format(SC_DRIVE_HEADER *this,uchar **param_1,ulong param_2)

{
  undefined2 uVar1;
  uchar *puVar2;
  ulonglong uVar3;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  undefined2 local_30;
  undefined2 local_2e;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_58;
  uVar1 = *(undefined2 *)(this + 0x24);
  local_38 = 0x5350414345444220;
  local_30 = *(undefined2 *)this;
  local_2c = 0;
  local_2e = 0x200;
  puVar2 = SC_FORMAT::Format((SC_FIELD *)&DAT_1400154c8,4,&local_38,*param_1);
  uVar3 = (ulonglong)*(ushort *)this;
  *(ushort *)(this + 0x24) = *(ushort *)(this + 0x24) & *(ushort *)(&DAT_1400154b8 + uVar3 * 4);
  puVar2 = SC_FORMAT::Format(*(SC_FIELD **)(&DAT_1400142c8 + uVar3 * 0x10),
                             *(ulong *)(&DAT_1400142c0 + uVar3 * 0x10),this,puVar2);
  *(undefined2 *)(this + 0x24) = uVar1;
  local_2c = RtlComputeCrc32(0,*param_1,0x200);
  SC_FORMAT::Format((SC_FIELD *)&DAT_1400154c8,4,&local_38,*param_1);
  *param_1 = puVar2;
  return;
}



===== Initialize @ 1400109c0 =====

/* public: virtual long __cdecl SC_DRIVE::Initialize(void) __ptr64 */

long __thiscall SC_DRIVE::Initialize(SC_DRIVE *this)

{
  long lVar1;
  
  lVar1 = SC_DISK::Initialize((SC_DISK *)this);
  return lVar1;
}



===== InitializePartitionTable @ 1400109d8 =====

/* private: long __cdecl SC_DRIVE::InitializePartitionTable(class SC_DISK_LAYOUT * __ptr64 *
   __ptr64) __ptr64 */

long __thiscall SC_DRIVE::InitializePartitionTable(SC_DRIVE *this,SC_DISK_LAYOUT **param_1)

{
  long lVar1;
  SC_DISK_LAYOUT *pSVar2;
  SC_DISK_LAYOUT **ppSVar3;
  longlong lVar4;
  SC_DISK_LAYOUT *local_res18 [2];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_res18[0] = (SC_DISK_LAYOUT *)0x0;
  uStack_20 = 0;
  local_18 = 0;
  local_28 = 1;
  lVar1 = SC_ENV::CreateGuid((_GUID *)((longlong)&local_28 + 4));
  if (-1 < lVar1) {
    lVar1 = SC_DISK::CreatePartitionTable((SC_DISK *)this,(_CREATE_DISK *)&local_28);
    if (-1 < lVar1) {
      lVar1 = SC_DISK::ResetPartitionCache((SC_DISK *)this);
      if (-1 < lVar1) {
        ppSVar3 = local_res18;
        lVar1 = SC_DISK::ReadPartitionTable((SC_DISK *)this,ppSVar3);
        if (-1 < lVar1) {
          pSVar2 = SC_DISK_LAYOUT::AddEntries(local_res18[0],(ulong)ppSVar3);
          if (pSVar2 == (SC_DISK_LAYOUT *)0x0) {
            lVar1 = -0x3fffff66;
          }
          else {
            lVar4 = (ulonglong)(*(int *)(pSVar2 + 4) - 1) * 0x90;
            *(undefined4 *)(pSVar2 + lVar4 + 0x30) = 1;
            *(undefined8 *)(pSVar2 + lVar4 + 0x38) = *(undefined8 *)(pSVar2 + 0x18);
            *(longlong *)(pSVar2 + lVar4 + 0x40) = 0x1000000 - *(longlong *)(pSVar2 + 0x18);
            pSVar2[lVar4 + 0x4c] = (SC_DISK_LAYOUT)0x1;
            *(undefined8 *)(pSVar2 + lVar4 + 0x50) = 0x4db80b5ce3c9e316;
            *(undefined8 *)(pSVar2 + lVar4 + 0x50 + 8) = 0xae1502f02df97d81;
            RtlStringCbCopyW((ushort *)(pSVar2 + lVar4 + 0x78),(__uint64)ppSVar3,
                             (ushort *)L"Microsoft reserved partition");
            lVar1 = SC_ENV::CreateGuid((_GUID *)(pSVar2 + lVar4 + 0x60));
            if (lVar1 < 0) {
              ExFreePoolWithTag(pSVar2,0);
            }
            else {
              *param_1 = pSVar2;
            }
          }
        }
        if (local_res18[0] != (SC_DISK_LAYOUT *)0x0) {
          ExFreePoolWithTag(local_res18[0],0);
        }
      }
    }
  }
  return lVar1;
}



===== Pnp @ 140010b30 =====

/* public: virtual long __cdecl SC_DRIVE::Pnp(void * __ptr64) __ptr64 */

long __thiscall SC_DRIVE::Pnp(SC_DRIVE *this,void *param_1)

{
  return 0;
}



===== LostQuery @ 140010b40 =====

/* public: virtual unsigned char __cdecl SC_DRIVE::LostQuery(unsigned __int64,unsigned __int64)
   __ptr64 */

uchar __thiscall SC_DRIVE::LostQuery(SC_DRIVE *this,__uint64 param_1,__uint64 param_2)

{
  return '\0';
}



===== ScGetDriveHeaderVersion @ 140010b4c =====

/* unsigned char __cdecl ScGetDriveHeaderVersion(enum _SC_VERSION) */

uchar __cdecl ScGetDriveHeaderVersion(_SC_VERSION param_1)

{
  if (0x15 < param_1) {
    return '\x03';
  }
  if (param_1 < 9) {
    return param_1 != 0;
  }
  return '\x02';
}



===== WriteHeader @ 140010b6c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl SC_DRIVE::WriteHeader(class SC_DRIVE_HEADER * __ptr64) __ptr64 */

long __thiscall SC_DRIVE::WriteHeader(SC_DRIVE *this,SC_DRIVE_HEADER *param_1)

{
  undefined8 uVar1;
  uchar *puVar2;
  int iVar3;
  ulong uVar4;
  uchar *local_res8;
  
  iVar3 = 1 << ((byte)*(undefined4 *)(this + 0xf0) & 0x1f);
  uVar4 = 0x6d506353;
  puVar2 = (uchar *)ExAllocatePool2(0x40,iVar3);
  if (puVar2 == (uchar *)0x0) {
    iVar3 = -0x3fffff66;
  }
  else {
    local_res8 = puVar2;
    SC_DRIVE_HEADER::Format(param_1,&local_res8,uVar4);
    iVar3 = (**(code **)(*(longlong *)this + 0x40))(this,*(undefined8 *)(this + 0x1c0),iVar3,puVar2)
    ;
    if (-1 < iVar3) {
      uVar1 = *(undefined8 *)(param_1 + 8);
      *(undefined8 *)(this + 0x1e0) = *(undefined8 *)param_1;
      *(undefined8 *)(this + 0x1e8) = uVar1;
      uVar1 = *(undefined8 *)(param_1 + 0x18);
      *(undefined8 *)(this + 0x1f0) = *(undefined8 *)(param_1 + 0x10);
      *(undefined8 *)(this + 0x1f8) = uVar1;
      uVar1 = *(undefined8 *)(param_1 + 0x28);
      *(undefined8 *)(this + 0x200) = *(undefined8 *)(param_1 + 0x20);
      *(undefined8 *)(this + 0x208) = uVar1;
      uVar1 = *(undefined8 *)(param_1 + 0x38);
      *(undefined8 *)(this + 0x210) = *(undefined8 *)(param_1 + 0x30);
      *(undefined8 *)(this + 0x218) = uVar1;
      *(undefined8 *)(this + 0x220) = *(undefined8 *)(param_1 + 0x40);
    }
    ExFreePoolWithTag(puVar2,0);
  }
  return iVar3;
}



===== ZeroMetadata @ 140010c58 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl SC_DRIVE::ZeroMetadata(void) __ptr64 */

long __thiscall SC_DRIVE::ZeroMetadata(SC_DRIVE *this)

{
  longlong lVar1;
  int iVar2;
  void *_Dst;
  
  _Dst = (void *)ExAllocatePool2(0x40,0x100000,0x6d506353);
  if (_Dst == (void *)0x0) {
    iVar2 = -0x3fffff66;
  }
  else {
    memset(_Dst,0,0x100000);
    lVar1 = *(longlong *)(this + 0x1c0);
    iVar2 = (**(code **)(*(longlong *)this + 0x40))(this,lVar1,0x100000,_Dst);
    if ((-1 < iVar2) &&
       (lVar1 + 0x20000000U <=
        (ulonglong)(*(longlong *)(this + 0x1c8) + *(longlong *)(this + 0x1c0)))) {
      iVar2 = (**(code **)(*(longlong *)this + 0x40))(this,lVar1 + 0x1ff00000,0x100000,_Dst);
    }
    ExFreePoolWithTag(_Dst,0);
  }
  return iVar2;
}



===== ComputeChs @ 140010d44 =====

/* public: void __cdecl MBR_ENTRY::ComputeChs(struct _DISK_GEOMETRY * __ptr64) __ptr64 */

void __thiscall MBR_ENTRY::ComputeChs(MBR_ENTRY *this,_DISK_GEOMETRY *param_1)

{
  int iVar1;
  uint uVar2;
  MBR_ENTRY *pMVar3;
  byte bVar4;
  uint *puVar5;
  uint uVar6;
  MBR_ENTRY **ppMVar7;
  byte bVar8;
  uint uVar9;
  MBR_ENTRY MVar10;
  longlong lVar11;
  uint local_28 [2];
  MBR_ENTRY *local_20 [3];
  
  puVar5 = local_28;
  uVar6 = *(int *)(param_1 + 0xc) * *(int *)(param_1 + 0x10);
  ppMVar7 = local_20;
  local_20[0] = this + 1;
  local_28[0] = *(uint *)(this + 8);
  lVar11 = 2;
  local_20[1] = this + 5;
  iVar1 = *(int *)param_1;
  local_28[1] = (*(uint *)(this + 8) - 1) + *(int *)(this + 0xc);
  do {
    uVar2 = *puVar5;
    if (uVar2 < uVar6 * iVar1) {
      uVar9 = uVar2 / uVar6;
      MVar10 = SUB81(((ulonglong)uVar2 % (ulonglong)uVar6) / (ulonglong)*(uint *)(param_1 + 0x10),0)
      ;
      bVar8 = (char)(((ulonglong)uVar2 % (ulonglong)uVar6) % (ulonglong)*(uint *)(param_1 + 0x10)) +
              1;
    }
    else {
      uVar9 = *(int *)param_1 - 1;
      bVar8 = (byte)*(undefined4 *)(param_1 + 0x10);
      MVar10 = (MBR_ENTRY)((char)*(undefined4 *)(param_1 + 0xc) + -1);
    }
    pMVar3 = *ppMVar7;
    puVar5 = puVar5 + 1;
    bVar4 = (byte)(uVar9 >> 2);
    ppMVar7 = ppMVar7 + 1;
    *pMVar3 = MVar10;
    pMVar3[1] = (MBR_ENTRY)((bVar4 ^ bVar8) & 0x3f ^ bVar4);
    pMVar3[2] = SUB41(uVar9,0);
    lVar11 = lVar11 + -1;
  } while (lVar11 != 0);
  return;
}



===== CreatePartitionTable @ 140010e28 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl SC_MBR::CreatePartitionTable(struct _CREATE_DISK * __ptr64) __ptr64 */

long __thiscall SC_MBR::CreatePartitionTable(SC_MBR *this,_CREATE_DISK *param_1)

{
  longlong lVar1;
  long lVar2;
  undefined1 auStack_f8 [32];
  undefined8 local_d8;
  undefined4 local_d0;
  undefined1 local_cc [180];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_f8;
  memset(local_cc,0,0xb4);
  lVar1 = *(longlong *)(*(longlong *)this + 0x108);
  memset((void *)(lVar1 + 0x1be),0,0x40);
  *(undefined2 *)(lVar1 + 0x1fe) = 0xaa55;
  *(undefined4 *)(lVar1 + 0x1b8) = 0;
  local_d0 = *(undefined4 *)(param_1 + 4);
  local_d8 = 0;
  lVar2 = WritePartitionTable(this,(SC_DISK_LAYOUT *)&local_d8);
  return lVar2;
}



===== WritePartitionTable @ 140010ed8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl SC_MBR::WritePartitionTable(class SC_DISK_LAYOUT * __ptr64) __ptr64 */

long __thiscall SC_MBR::WritePartitionTable(SC_MBR *this,SC_DISK_LAYOUT *param_1)

{
  SC_DISK_LAYOUT SVar1;
  undefined4 uVar2;
  MBR_HEADER *this_00;
  bool bVar3;
  uint uVar4;
  ulong uVar5;
  long lVar6;
  ulonglong uVar7;
  longlong lVar8;
  ulonglong uVar9;
  MBR_ENTRY *this_01;
  int iVar10;
  ulonglong uVar11;
  MBR_ENTRY *pMVar12;
  int iVar13;
  MBR_ENTRY *pMVar14;
  undefined1 auStack_78 [32];
  uint local_58;
  uint local_54;
  uint local_50 [4];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_78;
  local_54 = 0;
  local_58 = 0;
  this_00 = *(MBR_HEADER **)(*(longlong *)this + 0x108);
  uVar4 = *(uint *)(param_1 + 8);
  lVar6 = 0;
  bVar3 = false;
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  if (uVar4 == 0) {
    SC_ENV::CreateGuid((_GUID *)local_50);
    uVar4 = local_50[0] ^ local_50[1] ^ local_50[2] ^ local_50[3];
    *(uint *)(param_1 + 8) = uVar4;
  }
  uVar11 = 0;
  pMVar12 = (MBR_ENTRY *)0x0;
  uVar7 = 0;
  iVar13 = 0;
  if (*(uint *)(this_00 + 0x1b8) != uVar4) {
    *(uint *)(this_00 + 0x1b8) = uVar4;
    bVar3 = true;
    uVar5 = MBR_HEADER::CheckSum(this_00);
    *(ulong *)(param_1 + 0xc) = uVar5;
  }
  while( true ) {
    uVar9 = (ulonglong)pMVar12 & 0xffffffff;
    pMVar14 = pMVar12;
    while( true ) {
      uVar4 = (uint)uVar7;
      if ((3 < (uint)uVar9) || (*(uint *)(param_1 + 4) <= uVar4)) break;
      uVar7 = uVar7 & 0xffffffff;
      this_01 = (MBR_ENTRY *)(this_00 + uVar9 * 0x10 + 0x1be);
      SVar1 = param_1[uVar7 * 0x90 + 0x50];
      if ((SVar1 == (SC_DISK_LAYOUT)0x5) || (iVar10 = (int)uVar11, SVar1 == (SC_DISK_LAYOUT)0xf)) {
        if (pMVar14 != (MBR_ENTRY *)0x0) {
          return -0x3fffffff;
        }
        pMVar14 = this_01;
        iVar10 = iVar13;
      }
      uVar2 = *(undefined4 *)(param_1 + 8);
      *(undefined4 *)(param_1 + uVar7 * 0x90 + 0x5c) = 0;
      *(undefined4 *)(param_1 + uVar7 * 0x90 + 0x58) = uVar2;
      *(undefined8 *)(param_1 + uVar7 * 0x90 + 0x60) =
           *(undefined8 *)(param_1 + uVar7 * 0x90 + 0x38);
      if (param_1[uVar7 * 0x90 + 0x4c] != SUB81(pMVar12,0)) {
        if (SVar1 == (SC_DISK_LAYOUT)0x0) {
          *(undefined8 *)this_01 = 0;
          *(undefined8 *)(this_01 + 8) = 0;
        }
        else {
          *this_01 = (MBR_ENTRY)(-(param_1[uVar7 * 0x90 + 0x51] != (SC_DISK_LAYOUT)0x0) & 0x80);
          *(SC_DISK_LAYOUT *)(this_01 + 4) = param_1[uVar7 * 0x90 + 0x50];
          lVar8 = *(longlong *)(param_1 + uVar7 * 0x90 + 0x38);
          if (*(uint *)(*(longlong *)this + 0xec) != 0) {
            lVar8 = lVar8 / (longlong)(ulonglong)*(uint *)(*(longlong *)this + 0xec);
          }
          *(int *)(this_01 + 8) = (int)lVar8 - iVar10;
          lVar8 = *(longlong *)(param_1 + uVar7 * 0x90 + 0x40);
          if (*(uint *)(*(longlong *)this + 0xec) != 0) {
            lVar8 = lVar8 / (longlong)(ulonglong)*(uint *)(*(longlong *)this + 0xec);
          }
          *(int *)(this_01 + 0xc) = (int)lVar8;
          MBR_ENTRY::ComputeChs(this_01,(_DISK_GEOMETRY *)(*(longlong *)this + 0xd8));
          pMVar12 = (MBR_ENTRY *)0x0;
          uVar4 = local_58;
        }
        bVar3 = true;
      }
      uVar11 = (ulonglong)local_54;
      uVar9 = (ulonglong)((uint)uVar9 + 1);
      local_58 = uVar4 + 1;
      uVar7 = (ulonglong)local_58;
    }
    if (bVar3) {
      lVar6 = SC_DISK::WriteSectors(*(SC_DISK **)this,1,uVar11 & 0xffffffff,(void *)0x0);
      if (lVar6 < 0) {
        return lVar6;
      }
      bVar3 = false;
    }
    if (pMVar14 == (MBR_ENTRY *)0x0) break;
    iVar10 = *(int *)(pMVar14 + 8);
    local_54 = iVar10 + iVar13;
    lVar6 = SC_DISK::ReadSectors(*(SC_DISK **)this,1,(ulonglong)local_54,(void *)0x0);
    pMVar12 = (MBR_ENTRY *)0x0;
    if (lVar6 < 0) {
      return lVar6;
    }
    uVar7 = (ulonglong)local_58;
    uVar11 = (ulonglong)local_54;
    if (iVar13 != 0) {
      iVar10 = iVar13;
    }
    *(undefined2 *)(this_00 + 0x1fe) = 0xaa55;
    iVar13 = iVar10;
  }
  return lVar6;
}



===== CreatePartitionTable @ 140011128 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl SC_GPT::CreatePartitionTable(struct _CREATE_DISK * __ptr64) __ptr64 */

long __thiscall SC_GPT::CreatePartitionTable(SC_GPT *this,_CREATE_DISK *param_1)

{
  long lVar1;
  undefined1 auStack_f8 [32];
  undefined4 local_d8;
  undefined4 local_d4;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined4 local_b0;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_f8;
  memset(&local_d8,0,0xc0);
  local_d0 = *(undefined8 *)(param_1 + 4);
  uStack_c8 = *(undefined8 *)(param_1 + 0xc);
  local_b0 = *(undefined4 *)(param_1 + 0x14);
  local_d4 = 0;
  local_d8 = 1;
  lVar1 = WritePartitionTable(this,(SC_DISK_LAYOUT *)&local_d8,'\x01');
  return lVar1;
}



===== ReadEntries @ 1400111b8 =====

/* private: long __cdecl SC_GPT::ReadEntries(class GPT_HEADER * __ptr64,class GPT_ENTRY * __ptr64 *
   __ptr64) __ptr64 */

long __thiscall SC_GPT::ReadEntries(SC_GPT *this,GPT_HEADER *param_1,GPT_ENTRY **param_2)

{
  int iVar1;
  longlong lVar2;
  long lVar3;
  GPT_ENTRY *pGVar4;
  
  lVar2 = *(longlong *)this;
  iVar1 = *(int *)(param_1 + 0x54);
  *param_2 = (GPT_ENTRY *)0x0;
  pGVar4 = (GPT_ENTRY *)
           ExAllocatePool2(0x40,iVar1 * *(int *)(param_1 + 0x50) + -1 + *(int *)(lVar2 + 0xec) &
                                -*(int *)(lVar2 + 0xec),0x6d506353);
  if (pGVar4 == (GPT_ENTRY *)0x0) {
    lVar3 = -0x3fffff66;
  }
  else {
    lVar3 = ReadEntries(this,param_1,pGVar4);
    if (lVar3 < 0) {
      ExFreePoolWithTag(pGVar4,0);
    }
    else {
      *param_2 = pGVar4;
    }
  }
  return lVar3;
}



===== ReadEntries @ 140011268 =====

/* private: long __cdecl SC_GPT::ReadEntries(class GPT_HEADER * __ptr64,class GPT_ENTRY * __ptr64)
   __ptr64 */

long __thiscall SC_GPT::ReadEntries(SC_GPT *this,GPT_HEADER *param_1,GPT_ENTRY *param_2)

{
  int iVar1;
  SC_DISK *this_00;
  long lVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x54);
  iVar1 = *(int *)(param_1 + 0x50);
  this_00 = *(SC_DISK **)this;
  lVar2 = SC_DISK::ReadSectors
                    (this_00,(uint)(*(int *)(this_00 + 0xec) + -1 + iVar3 * iVar1 &
                                   -*(int *)(this_00 + 0xec)) >>
                             ((byte)*(undefined4 *)(this_00 + 0xf0) & 0x1f),
                     *(__uint64 *)(param_1 + 0x48),param_2);
  if (-1 < lVar2) {
    iVar3 = RtlComputeCrc32(0,param_2,iVar3 * iVar1);
    if (iVar3 != *(int *)(param_1 + 0x58)) {
      lVar2 = -0x3fffffce;
    }
  }
  return lVar2;
}



===== ReadHeader @ 1400112f0 =====

/* private: long __cdecl SC_GPT::ReadHeader(unsigned long,class GPT_HEADER * __ptr64) __ptr64 */

long __thiscall SC_GPT::ReadHeader(SC_GPT *this,ulong param_1,GPT_HEADER *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  __uint64 _Var4;
  
  if (param_1 == 0) {
    _Var4 = 1;
  }
  else {
    _Var4 = *(longlong *)(*(longlong *)this + 0xf8) - 1;
  }
  uVar2 = SC_DISK::ReadSectors(*(SC_DISK **)this,1,_Var4,param_2);
  if ((((-1 < (int)uVar2) && (uVar2 = 0xc0000032, *(longlong *)param_2 == 0x5452415020494645)) &&
      (*(int *)(param_2 + 8) == 0x10000)) &&
     (((*(int *)(param_2 + 0xc) == 0x5c && (*(int *)(param_2 + 0x54) == 0x80)) &&
      ((*(int *)(param_2 + 0x50) - 1U < 0x400 && (*(__uint64 *)(param_2 + 0x18) == _Var4)))))) {
    iVar1 = *(int *)(param_2 + 0x10);
    *(undefined4 *)(param_2 + 0x10) = 0;
    iVar3 = RtlComputeCrc32(0,param_2);
    *(int *)(param_2 + 0x10) = iVar1;
    if (iVar3 == iVar1) {
      iVar1 = *(int *)(*(longlong *)this + 0xec);
      uVar2 = -(uint)(*(ulonglong *)(param_2 + 0x28) <
                     (ulonglong)
                     (((uint)(*(int *)(param_2 + 0x54) * *(int *)(param_2 + 0x50) + -1 + iVar1 &
                             -iVar1) >> ((byte)*(undefined4 *)(*(longlong *)this + 0xf0) & 0x1f)) +
                     2)) & 0xc0000032;
    }
  }
  return uVar2;
}



===== ReadPartitionTable @ 1400113e4 =====

/* public: long __cdecl SC_GPT::ReadPartitionTable(class SC_DISK_LAYOUT * __ptr64 * __ptr64) __ptr64
    */

long __thiscall SC_GPT::ReadPartitionTable(SC_GPT *this,SC_DISK_LAYOUT **param_1)

{
  uint *puVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  GPT_HEADER *pGVar5;
  longlong lVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  long lVar9;
  SC_DISK_LAYOUT *_Dst;
  uint uVar10;
  longlong lVar11;
  __uint64 _Var12;
  ulong uVar13;
  longlong lVar14;
  GPT_ENTRY *pGVar15;
  GPT_ENTRY *pGVar16;
  ulonglong uVar17;
  GPT_ENTRY *local_res8;
  
  lVar11 = *(longlong *)this;
  local_res8 = (GPT_ENTRY *)0x0;
  *param_1 = (SC_DISK_LAYOUT *)0x0;
  pGVar5 = *(GPT_HEADER **)(lVar11 + 0x108);
  puVar1 = (uint *)(lVar11 + 200);
  *puVar1 = *puVar1 & 0xfffffffd;
  bVar2 = *(byte *)(*(longlong *)this + 200);
  uVar13 = 0;
  do {
    lVar9 = ReadHeader(this,uVar13,pGVar5);
    if (lVar9 < 0) {
      if (lVar9 == -0x3fffffce) {
        *(uint *)(*(longlong *)this + 200) = *(uint *)(*(longlong *)this + 200) | 2;
      }
    }
    else {
      lVar9 = ReadEntries(this,pGVar5,&local_res8);
      if (-1 < lVar9) {
        if (uVar13 == 0) {
          lVar11 = *(longlong *)this;
          if ((*(uint *)(lVar11 + 200) & 1) == 0) {
            lVar11 = (*(longlong *)(lVar11 + 0xf8) -
                     (ulonglong)
                     ((uint)(*(int *)(lVar11 + 0xec) + -1 +
                             *(int *)(pGVar5 + 0x54) * *(int *)(pGVar5 + 0x50) &
                            -*(int *)(lVar11 + 0xec)) >>
                     ((byte)*(undefined4 *)(lVar11 + 0xf0) & 0x1f))) + -2;
          }
          else {
            lVar11 = *(longlong *)(lVar11 + 0xf8) + -1;
          }
          if (*(longlong *)(pGVar5 + 0x30) != lVar11) {
            *(longlong *)(pGVar5 + 0x30) = lVar11;
            *(uint *)(*(longlong *)this + 200) = *(uint *)(*(longlong *)this + 200) | 2;
          }
        }
        uVar10 = *(int *)(pGVar5 + 0x50) * 0x90 + 0x30;
        _Dst = (SC_DISK_LAYOUT *)ExAllocatePool2(0x40,uVar10,0x6d506353);
        if (_Dst != (SC_DISK_LAYOUT *)0x0) {
          memset(_Dst,0,(ulonglong)uVar10);
          lVar11 = *(longlong *)this;
          uVar17 = 0;
          lVar6 = *(longlong *)(pGVar5 + 0x28);
          uVar10 = 0;
          uVar7 = *(undefined8 *)(pGVar5 + 0x38);
          uVar8 = *(undefined8 *)(pGVar5 + 0x40);
          *(undefined4 *)_Dst = 1;
          *(undefined8 *)(_Dst + 8) = uVar7;
          *(undefined8 *)(_Dst + 0x10) = uVar8;
          *(longlong *)(_Dst + 0x18) = lVar6 << ((byte)*(undefined4 *)(lVar11 + 0xf0) & 0x3f);
          *(longlong *)(_Dst + 0x20) =
               (*(longlong *)(pGVar5 + 0x30) - lVar6) + 1 <<
               ((byte)*(undefined4 *)(lVar11 + 0xf0) & 0x3f);
          iVar3 = *(int *)(pGVar5 + 0x50);
          *(int *)(_Dst + 0x28) = iVar3;
          pGVar16 = local_res8;
          if (iVar3 != 0) {
            do {
              pGVar15 = pGVar16 + (ulonglong)uVar10 * 0x80;
              lVar11 = *(longlong *)pGVar15;
              if (lVar11 == 0) {
                lVar11 = *(longlong *)(pGVar15 + 8);
              }
              if (lVar11 != 0) {
                if (((*(ulonglong *)(pGVar15 + 0x20) <= *(ulonglong *)(pGVar15 + 0x28)) &&
                    (*(ulonglong *)(pGVar5 + 0x28) <= *(ulonglong *)(pGVar15 + 0x20))) &&
                   (*(ulonglong *)(pGVar15 + 0x28) <= *(ulonglong *)(pGVar5 + 0x30))) {
                  lVar11 = *(longlong *)this;
                  lVar14 = uVar17 * 0x90;
                  *(undefined4 *)(_Dst + lVar14 + 0x30) = 1;
                  *(longlong *)(_Dst + lVar14 + 0x38) =
                       *(longlong *)(pGVar15 + 0x20) <<
                       ((byte)*(undefined4 *)(lVar11 + 0xf0) & 0x3f);
                  uVar4 = *(undefined4 *)(lVar11 + 0xf0);
                  lVar11 = *(longlong *)(pGVar15 + 0x28);
                  lVar6 = *(longlong *)(pGVar15 + 0x20);
                  *(undefined4 *)(_Dst + lVar14 + 0x48) = 0;
                  _Var12 = (lVar11 - lVar6) + 1 << ((byte)uVar4 & 0x3f);
                  *(__uint64 *)(_Dst + lVar14 + 0x40) = _Var12;
                  lVar11 = *(longlong *)(pGVar15 + 8);
                  *(longlong *)(_Dst + lVar14 + 0x50) = *(longlong *)pGVar15;
                  *(longlong *)(_Dst + lVar14 + 0x50 + 8) = lVar11;
                  lVar11 = *(longlong *)(pGVar15 + 0x18);
                  *(longlong *)(_Dst + lVar14 + 0x60) = *(longlong *)(pGVar15 + 0x10);
                  *(longlong *)(_Dst + lVar14 + 0x60 + 8) = lVar11;
                  *(longlong *)(_Dst + lVar14 + 0x70) = *(longlong *)(pGVar15 + 0x30);
                  RtlStringCbCopyW((ushort *)(_Dst + lVar14 + 0x78),_Var12,
                                   (ushort *)(pGVar15 + 0x38));
                  uVar17 = (ulonglong)((int)uVar17 + 1);
                }
              }
              uVar10 = uVar10 + 1;
            } while (uVar10 < *(uint *)(pGVar5 + 0x50));
          }
          *(int *)(_Dst + 4) = (int)uVar17;
          *param_1 = _Dst;
          goto LAB_140011682;
        }
        lVar9 = -0x3fffff66;
        break;
      }
      if (lVar9 == -0x3fffffce) {
        *(uint *)(*(longlong *)this + 200) = *(uint *)(*(longlong *)this + 200) | 2;
      }
    }
    uVar13 = uVar13 + 1;
  } while (uVar13 < 2 - ((bVar2 & 1) != 0));
  pGVar16 = local_res8;
LAB_140011682:
  if (pGVar16 != (GPT_ENTRY *)0x0) {
    ExFreePoolWithTag(pGVar16,0);
  }
  return lVar9;
}



===== WritePartitionTable @ 1400116b8 =====

/* public: long __cdecl SC_GPT::WritePartitionTable(class SC_DISK_LAYOUT * __ptr64,unsigned char)
   __ptr64 */

long __thiscall SC_GPT::WritePartitionTable(SC_GPT *this,SC_DISK_LAYOUT *param_1,uchar param_2)

{
  _GUID *p_Var1;
  void *pvVar2;
  byte bVar3;
  GPT_HEADER *_Dst;
  SC_DISK *this_00;
  undefined8 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uchar uVar8;
  undefined4 uVar9;
  long lVar10;
  undefined8 *puVar11;
  longlong lVar12;
  longlong lVar13;
  uint uVar14;
  __uint64 _Var15;
  undefined8 *puVar16;
  ulong uVar17;
  ulonglong uVar18;
  undefined8 *puVar19;
  uint uVar20;
  ulonglong uVar21;
  uint uVar22;
  ulonglong uVar23;
  ulonglong uVar24;
  int local_68;
  undefined4 local_64;
  ulonglong local_60;
  
  lVar13 = *(longlong *)this;
  local_64 = 0;
  _Dst = *(GPT_HEADER **)(lVar13 + 0x108);
  if (param_2 == '\0') {
    bVar3 = *(byte *)(lVar13 + 200);
    uVar17 = 0;
    while (lVar10 = ReadHeader(this,uVar17,_Dst), lVar10 < 0) {
      uVar17 = uVar17 + 1;
      if (2 - ((bVar3 & 1) != 0) <= uVar17) {
        return lVar10;
      }
    }
    lVar13 = *(longlong *)this;
    local_60 = *(ulonglong *)(_Dst + 0x28);
    local_68 = *(int *)(_Dst + 0x54);
    uVar20 = *(uint *)(_Dst + 0x50);
    uVar14 = *(int *)(lVar13 + 0xec) + -1 + uVar20 * local_68 & -*(int *)(lVar13 + 0xec);
    uVar22 = uVar14 >> ((byte)*(undefined4 *)(lVar13 + 0xf0) & 0x1f);
  }
  else {
    if (*(short *)(_Dst + 0x1fe) == -0x55ab) {
      local_64 = *(undefined4 *)(_Dst + 0x1b8);
    }
    uVar20 = *(uint *)(param_1 + 0x28);
    if (uVar20 < 0x81) {
      uVar20 = 0x80;
    }
    else if (0x400 < uVar20) {
      return -0x3ffffff3;
    }
    local_68 = 0x80;
    uVar14 = *(int *)(lVar13 + 0xec) + -1 + uVar20 * 0x80 & -*(int *)(lVar13 + 0xec);
    uVar22 = uVar14 >> ((byte)*(undefined4 *)(lVar13 + 0xf0) & 0x1f);
    uVar20 = uVar14 >> 7;
    local_60 = (ulonglong)(uVar22 + 2);
  }
  uVar23 = (ulonglong)uVar22;
  if (uVar20 < *(uint *)(param_1 + 4)) {
    return -0x3ffffff3;
  }
  if ((*(uint *)(lVar13 + 200) & 1) == 0) {
    uVar24 = (*(longlong *)(lVar13 + 0xf8) - uVar23) - 2;
  }
  else {
    uVar24 = *(longlong *)(lVar13 + 0xf8) - 1;
  }
  uVar18 = (ulonglong)((2 << ((byte)*(undefined4 *)(lVar13 + 0xf0) & 0x1f)) + uVar14);
  puVar11 = (undefined8 *)ExAllocatePool2(0x40,uVar18,0x6d506353);
  if (puVar11 == (undefined8 *)0x0) {
    return -0x3fffff66;
  }
  lVar13 = (longlong)(1 << ((byte)*(undefined4 *)(*(longlong *)this + 0xf0) & 0x1f));
  puVar19 = (undefined8 *)((uVar18 - lVar13) + (longlong)puVar11);
  pvVar2 = (void *)(lVar13 + (longlong)puVar11);
  puVar16 = (undefined8 *)((longlong)pvVar2 + 0x30);
  uVar18 = 0;
  while ((uint)uVar18 < *(uint *)(param_1 + 4)) {
    uVar21 = uVar18;
    uVar8 = SC_PART_ENTRY::IsUnused((SC_PART_ENTRY *)(param_1 + uVar18 * 0x90 + 0x30));
    uVar14 = (uint)uVar21;
    if (uVar8 == '\0') {
      lVar13 = *(longlong *)(param_1 + uVar18 * 0x90 + 0x60);
      if (lVar13 == 0) {
        lVar13 = *(longlong *)(param_1 + uVar18 * 0x90 + 0x68);
      }
      if (lVar13 == 0) {
        SC_ENV::CreateGuid((_GUID *)(param_1 + uVar18 * 0x90 + 0x60));
        uVar14 = (uint)uVar18;
      }
      uVar4 = *(undefined8 *)(param_1 + uVar18 * 0x90 + 0x58);
      puVar16[-6] = *(undefined8 *)(param_1 + uVar18 * 0x90 + 0x50);
      puVar16[-5] = uVar4;
      uVar4 = *(undefined8 *)(param_1 + uVar18 * 0x90 + 0x68);
      puVar16[-4] = *(undefined8 *)(param_1 + uVar18 * 0x90 + 0x60);
      puVar16[-3] = uVar4;
      lVar13 = *(longlong *)(param_1 + uVar18 * 0x90 + 0x38);
      if (*(uint *)(*(longlong *)this + 0xec) != 0) {
        lVar13 = lVar13 / (longlong)(ulonglong)*(uint *)(*(longlong *)this + 0xec);
      }
      puVar16[-2] = lVar13;
      lVar12 = *(longlong *)(param_1 + uVar18 * 0x90 + 0x38) +
               *(longlong *)(param_1 + uVar18 * 0x90 + 0x40) + -1;
      _Var15 = (__uint64)*(uint *)(*(longlong *)this + 0xec);
      lVar13 = lVar12;
      if (*(uint *)(*(longlong *)this + 0xec) != 0) {
        lVar13 = lVar12 / (longlong)_Var15;
        _Var15 = lVar12 % (longlong)_Var15;
      }
      puVar16[-1] = lVar13;
      *puVar16 = *(undefined8 *)(param_1 + uVar18 * 0x90 + 0x70);
      RtlStringCbCopyW((ushort *)(puVar16 + 1),_Var15,(ushort *)(param_1 + uVar18 * 0x90 + 0x78));
      if (((ulonglong)puVar16[-2] < local_60) || (uVar24 < (ulonglong)puVar16[-1])) {
        lVar10 = -0x3ffffff3;
        goto LAB_140011b63;
      }
      puVar16 = puVar16 + 0x10;
    }
    uVar18 = (ulonglong)(uVar14 + 1);
  }
  p_Var1 = (_GUID *)(param_1 + 8);
  lVar13 = *(longlong *)p_Var1;
  if (lVar13 == 0) {
    lVar13 = *(longlong *)(param_1 + 0x10);
  }
  if (lVar13 == 0) {
    SC_ENV::CreateGuid(p_Var1);
  }
  uVar9 = *(undefined4 *)p_Var1;
  uVar5 = *(undefined4 *)(param_1 + 0xc);
  uVar6 = *(undefined4 *)(param_1 + 0x10);
  uVar7 = *(undefined4 *)(param_1 + 0x14);
  *(ulonglong *)(param_1 + 0x20) =
       (uVar24 - local_60) + 1 << ((byte)*(undefined4 *)(*(longlong *)this + 0xf0) & 0x3f);
  *puVar11 = 0x5452415020494645;
  *(uint *)(param_1 + 0x28) = uVar20;
  *(uint *)(puVar11 + 10) = uVar20;
  lVar13 = *(longlong *)this;
  puVar11[5] = local_60;
  puVar11[4] = uVar23 + 1 + uVar24;
  puVar11[6] = uVar24;
  *(int *)((longlong)puVar11 + 0x54) = local_68;
  *(undefined4 *)(puVar11 + 1) = 0x10000;
  *(undefined4 *)((longlong)puVar11 + 0xc) = 0x5c;
  puVar11[3] = 1;
  *(undefined4 *)(puVar11 + 7) = uVar9;
  *(undefined4 *)((longlong)puVar11 + 0x3c) = uVar5;
  *(undefined4 *)(puVar11 + 8) = uVar6;
  *(undefined4 *)((longlong)puVar11 + 0x44) = uVar7;
  puVar11[9] = local_60 - uVar23;
  uVar9 = RtlComputeCrc32(0,pvVar2,uVar22 << ((byte)*(undefined4 *)(lVar13 + 0xf0) & 0x1f));
  *(undefined4 *)(puVar11 + 0xb) = uVar9;
  uVar9 = RtlComputeCrc32(0,puVar11,*(undefined4 *)((longlong)puVar11 + 0xc));
  this_00 = *(SC_DISK **)this;
  *(undefined4 *)(puVar11 + 2) = uVar9;
  lVar10 = SC_DISK::WriteSectors(this_00,uVar22 + 1,puVar11[3],puVar11);
  if (-1 < lVar10) {
    if ((*(uint *)(*(longlong *)this + 200) & 1) == 0) {
      uVar4 = puVar11[1];
      *puVar19 = *puVar11;
      puVar19[1] = uVar4;
      uVar4 = puVar11[3];
      puVar19[2] = puVar11[2];
      puVar19[3] = uVar4;
      uVar4 = puVar11[5];
      puVar19[4] = puVar11[4];
      puVar19[5] = uVar4;
      uVar4 = puVar11[7];
      puVar19[6] = puVar11[6];
      puVar19[7] = uVar4;
      uVar9 = *(undefined4 *)((longlong)puVar11 + 0x44);
      uVar5 = *(undefined4 *)(puVar11 + 9);
      uVar6 = *(undefined4 *)((longlong)puVar11 + 0x4c);
      *(undefined4 *)(puVar19 + 8) = *(undefined4 *)(puVar11 + 8);
      *(undefined4 *)((longlong)puVar19 + 0x44) = uVar9;
      *(undefined4 *)(puVar19 + 9) = uVar5;
      *(undefined4 *)((longlong)puVar19 + 0x4c) = uVar6;
      puVar19[10] = puVar11[10];
      *(undefined4 *)(puVar19 + 0xb) = *(undefined4 *)(puVar11 + 0xb);
      uVar4 = puVar19[3];
      *(undefined4 *)(puVar19 + 2) = 0;
      puVar19[3] = puVar19[4];
      puVar19[9] = puVar19[4] - uVar23;
      puVar19[4] = uVar4;
      uVar9 = RtlComputeCrc32(0,puVar19,*(undefined4 *)((longlong)puVar19 + 0xc));
      *(undefined4 *)(puVar19 + 2) = uVar9;
      lVar10 = SC_DISK::WriteSectors(*(SC_DISK **)this,uVar22 + 1,puVar19[9],pvVar2);
      if (lVar10 < 0) goto LAB_140011b63;
    }
    *(uint *)(*(longlong *)this + 200) = *(uint *)(*(longlong *)this + 200) & 0xfffffffd;
    if (param_2 != '\0') {
      memset(_Dst,0,0x200);
      *(undefined4 *)(_Dst + 0x1ca) = 0xffffffff;
      *(undefined4 *)(_Dst + 0x1b8) = local_64;
      _Dst[0x1c2] = (GPT_HEADER)0xee;
      *(undefined4 *)(_Dst + 0x1c6) = 1;
      MBR_ENTRY::ComputeChs
                ((MBR_ENTRY *)(_Dst + 0x1be),(_DISK_GEOMETRY *)(*(longlong *)this + 0xd8));
      *(undefined2 *)(_Dst + 0x1fe) = 0xaa55;
      lVar10 = SC_DISK::WriteSectors(*(SC_DISK **)this,1,0,(void *)0x0);
    }
  }
LAB_140011b63:
  ExFreePoolWithTag(puVar11,0);
  return lVar10;
}



===== `scalar_deleting_destructor' @ 140011b90 =====

/* public: virtual void * __ptr64 __cdecl SC_DEVICE::`scalar deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall SC_DEVICE::_scalar_deleting_destructor_(SC_DEVICE *this,uint param_1)

{
  ~SC_DEVICE(this);
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0);
  }
  return this;
}



===== GetStoragePropertyPre @ 140011bd0 =====

/* protected: virtual long __cdecl SC_DEVICE::GetStoragePropertyPre(enum
   _STORAGE_PROPERTY_ID,unsigned long * __ptr64) __ptr64 */

long __thiscall
SC_DEVICE::GetStoragePropertyPre(SC_DEVICE *this,_STORAGE_PROPERTY_ID param_1,ulong *param_2)

{
  *param_2 = 0;
  if (param_1 == 0) {
    *param_2 = 0x28;
  }
  else if (param_1 == 1) {
    *param_2 = 0x20;
  }
  else {
    if (param_1 != 2) {
      if (param_1 == 5) {
        *param_2 = 0x18;
        return 0;
      }
      if (param_1 == 0x13) {
        *param_2 = 0x1c;
        return 0;
      }
      if (param_1 != 0x3f) {
        return -0x3ffffddb;
      }
    }
    *param_2 = 0x10;
  }
  return 0;
}



===== SaveStorageProperty @ 140011c30 =====

/* protected: virtual void __cdecl SC_DEVICE::SaveStorageProperty(enum _STORAGE_PROPERTY_ID,struct
   _STORAGE_DESCRIPTOR_HEADER * __ptr64) __ptr64 */

void __thiscall
SC_DEVICE::SaveStorageProperty
          (SC_DEVICE *this,_STORAGE_PROPERTY_ID param_1,_STORAGE_DESCRIPTOR_HEADER *param_2)

{
  uint uVar1;
  longlong lVar2;
  
  if (param_1 == 0) {
    lVar2 = 0xa0;
  }
  else if (param_1 == 1) {
    lVar2 = 0x98;
  }
  else if (param_1 == 2) {
    lVar2 = 0xb8;
  }
  else if (param_1 == 5) {
    lVar2 = 0xc0;
  }
  else if (param_1 == 0x13) {
    lVar2 = 0xb0;
  }
  else {
    if (param_1 != 0x3f) {
      if (param_2 == (_STORAGE_DESCRIPTOR_HEADER *)0x0) {
        return;
      }
      ExFreePoolWithTag(param_2,0);
      return;
    }
    lVar2 = 0xa8;
  }
  if (*(longlong *)(this + lVar2) != 0) {
    ExFreePoolWithTag();
  }
  *(_STORAGE_DESCRIPTOR_HEADER **)(this + lVar2) = param_2;
  if (param_1 == 0) {
    ScExtractDeviceStrings
              (*(_STORAGE_DEVICE_DESCRIPTOR **)(this + 0xa0),(_UNICODE_STRING *)(this + 0x18),
               (_UNICODE_STRING *)(this + 0x28),(_UNICODE_STRING *)(this + 0x38),
               (_UNICODE_STRING *)(this + 0x48));
  }
  else if (param_1 == 0x13) {
    memset(this + 0x58,0,0x40);
    lVar2 = *(longlong *)(this + 0xb0);
    if (lVar2 != 0) {
      uVar1 = 4;
      if (*(uint *)(lVar2 + 8) < 4) {
        uVar1 = *(uint *)(lVar2 + 8);
      }
      memmove(this + 0x58,(void *)(lVar2 + 0xc),(ulonglong)uVar1 << 4);
    }
  }
  return;
}



===== CreatePartitionTable @ 140011d58 =====

/* public: long __cdecl SC_RAW::CreatePartitionTable(void) __ptr64 */

long __thiscall SC_RAW::CreatePartitionTable(SC_RAW *this)

{
  longlong lVar1;
  SC_DISK *this_00;
  long lVar2;
  
  lVar1 = *(longlong *)(*(longlong *)this + 0x108);
  memset((void *)(lVar1 + 0x1be),0,0x40);
  *(undefined4 *)(lVar1 + 0x1b8) = 0;
  *(undefined2 *)(lVar1 + 0x1fe) = 0;
  lVar2 = SC_DISK::WriteSectors(*(SC_DISK **)this,1,0,(void *)0x0);
  if ((-1 < lVar2) && (lVar1 = *(longlong *)this, *(int *)(lVar1 + 0x100) == 1)) {
    memset(*(void **)(lVar1 + 0x108),0,(longlong)(1 << ((byte)*(undefined4 *)(lVar1 + 0xf0) & 0x1f))
          );
    lVar2 = SC_DISK::WriteSectors(*(SC_DISK **)this,1,1,(void *)0x0);
    if ((-1 < lVar2) && (this_00 = *(SC_DISK **)this, (*(uint *)(this_00 + 200) & 1) == 0)) {
      lVar2 = SC_DISK::WriteSectors(this_00,1,*(longlong *)(this_00 + 0xf8) - 1,(void *)0x0);
    }
  }
  return lVar2;
}



===== Format @ 140011e28 =====

/* public: static unsigned char * __ptr64 __cdecl SC_FORMAT::Format(class SC_FIELD const *
   __ptr64,unsigned long,void * __ptr64,unsigned char * __ptr64) */

uchar * __cdecl SC_FORMAT::Format(SC_FIELD *param_1,ulong param_2,void *param_3,uchar *param_4)

{
  SC_FIELD *pSVar1;
  uint uVar2;
  ulonglong uVar3;
  uchar uVar4;
  short sVar5;
  int iVar6;
  longlong lVar7;
  ulonglong *puVar8;
  uchar *puVar9;
  uchar *puVar10;
  SC_FIELD *pSVar11;
  
  if (param_1 + (ulonglong)param_2 * 0xc <= param_1) {
    return param_4;
  }
  pSVar11 = param_1 + 4;
LAB_140011e5f:
  iVar6 = *(int *)(pSVar11 + -4);
  puVar8 = (ulonglong *)((ulonglong)*(ushort *)(pSVar11 + 4) + (longlong)param_3);
  if (iVar6 < 8) {
    if (iVar6 == 7) {
      puVar9 = (uchar *)*puVar8;
      sVar5 = *(short *)((ulonglong)*(ushort *)pSVar11 + (longlong)param_3);
      if (puVar9 == (uchar *)0x0) goto LAB_140011fae;
      param_4[1] = (uchar)sVar5;
      *param_4 = (uchar)((ushort)sVar5 >> 8);
      param_4 = param_4 + 2;
      for (; sVar5 != 0; sVar5 = sVar5 + -1) {
        uVar4 = *puVar9;
        puVar9 = puVar9 + 1;
        *param_4 = uVar4;
        param_4 = param_4 + 1;
      }
      goto LAB_1400120cd;
    }
    if (iVar6 == 1) {
LAB_140011f91:
      uVar4 = (uchar)*puVar8;
LAB_140011f93:
      *param_4 = uVar4;
      param_4 = param_4 + 1;
      goto LAB_1400120cd;
    }
    if (iVar6 == 2) {
      *param_4 = *(uchar *)((longlong)puVar8 + 1);
      param_4[1] = (uchar)*puVar8;
      goto LAB_140011f88;
    }
    if (iVar6 == 3) {
      *param_4 = *(uchar *)((longlong)puVar8 + 3);
      param_4[1] = *(uchar *)((longlong)puVar8 + 2);
      param_4[2] = *(uchar *)((longlong)puVar8 + 1);
      param_4[3] = (uchar)*puVar8;
      param_4 = param_4 + 4;
      goto LAB_1400120cd;
    }
    if (iVar6 != 4) {
      if (iVar6 == 5) {
        *param_4 = *(uchar *)((longlong)puVar8 + 7);
        param_4[1] = *(uchar *)((longlong)puVar8 + 6);
        param_4[2] = *(uchar *)((longlong)puVar8 + 5);
        param_4[3] = *(uchar *)((longlong)puVar8 + 4);
        param_4[4] = *(uchar *)((longlong)puVar8 + 3);
        param_4[5] = *(uchar *)((longlong)puVar8 + 2);
        param_4[6] = *(uchar *)((longlong)puVar8 + 1);
        param_4[7] = (uchar)*puVar8;
        param_4 = param_4 + 8;
      }
      else if (iVar6 == 6) {
        uVar3 = *puVar8;
        puVar9 = param_4 + 1;
        iVar6 = 0x38;
        do {
          if ((char)(uVar3 >> ((byte)iVar6 & 0x3f)) != '\0') goto LAB_140011ec8;
          iVar6 = iVar6 + -8;
        } while (-1 < iVar6);
        goto LAB_140011f48;
      }
      goto LAB_1400120cd;
    }
    uVar3 = *puVar8;
    puVar9 = param_4 + 1;
    iVar6 = 0x18;
    do {
      if ((char)((uint)uVar3 >> ((byte)iVar6 & 0x1f)) != '\0') goto LAB_140011f38;
      iVar6 = iVar6 + -8;
    } while (-1 < iVar6);
    goto LAB_140011f48;
  }
  if (iVar6 == 8) {
    puVar9 = (uchar *)*puVar8;
    if (puVar9 == (uchar *)0x0) {
LAB_140011fae:
      param_4[0] = '\0';
      param_4[1] = '\0';
LAB_140011f88:
      param_4 = param_4 + 2;
    }
    else {
      lVar7 = -1;
      do {
        lVar7 = lVar7 + 1;
      } while (*(short *)(puVar9 + lVar7 * 2) != 0);
      sVar5 = (short)lVar7 + 1;
      param_4[1] = (uchar)sVar5;
      *param_4 = (uchar)((ushort)sVar5 >> 8);
      puVar10 = param_4;
      for (; param_4 = puVar10 + 2, sVar5 != 0; sVar5 = sVar5 + -1) {
        *param_4 = puVar9[1];
        uVar4 = *puVar9;
        puVar9 = puVar9 + 2;
        puVar10[3] = uVar4;
        puVar10 = param_4;
      }
    }
  }
  else if (iVar6 == 9) {
    lVar7 = 8;
    *param_4 = *(uchar *)((longlong)puVar8 + 3);
    param_4[1] = *(uchar *)((longlong)puVar8 + 2);
    param_4[2] = *(uchar *)((longlong)puVar8 + 1);
    param_4[3] = (uchar)*puVar8;
    param_4[4] = *(uchar *)((longlong)puVar8 + 5);
    param_4[5] = *(uchar *)((longlong)puVar8 + 4);
    param_4[6] = *(uchar *)((longlong)puVar8 + 7);
    param_4[7] = *(uchar *)((longlong)puVar8 + 6);
    param_4 = param_4 + 8;
    puVar8 = puVar8 + 1;
    do {
      uVar3 = *puVar8;
      puVar8 = (ulonglong *)((longlong)puVar8 + 1);
      *param_4 = (uchar)uVar3;
      param_4 = param_4 + 1;
      lVar7 = lVar7 + -1;
    } while (lVar7 != 0);
  }
  else {
    if (iVar6 == 10) {
      uVar2 = (uint)*puVar8;
      if (uVar2 == 0) {
        uVar4 = 0xff;
      }
      else {
        iVar6 = 0x1f;
        if (uVar2 != 0) {
          for (; uVar2 >> iVar6 == 0; iVar6 = iVar6 + -1) {
          }
        }
        uVar4 = (uchar)iVar6;
      }
      goto LAB_140011f93;
    }
    if (iVar6 == 0xb) goto LAB_140011f91;
    if (iVar6 == 0xc) {
      param_4 = param_4 + *(ushort *)(pSVar11 + 2);
    }
  }
  goto LAB_1400120cd;
LAB_140011ec8:
  do {
    *puVar9 = (uchar)(uVar3 >> ((byte)iVar6 & 0x3f));
    puVar9 = puVar9 + 1;
    iVar6 = iVar6 + -8;
  } while (-1 < iVar6);
  goto LAB_140011f48;
LAB_140011f38:
  do {
    *puVar9 = (uchar)((uint)uVar3 >> ((byte)iVar6 & 0x1f));
    puVar9 = puVar9 + 1;
    iVar6 = iVar6 + -8;
  } while (-1 < iVar6);
LAB_140011f48:
  *param_4 = ((char)puVar9 - (char)param_4) + 0xff;
  param_4 = puVar9;
LAB_1400120cd:
  pSVar1 = pSVar11 + 8;
  pSVar11 = pSVar11 + 0xc;
  if (param_1 + (ulonglong)param_2 * 0xc <= pSVar1) {
    return param_4;
  }
  goto LAB_140011e5f;
}



===== _guard_check_icall @ 140012110 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140012128 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14001214c =====

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



===== __cpu_features_init @ 1400121c0 =====

/* WARNING: Removing unreachable block (ram,0x00014001222a) */
/* WARNING: Removing unreachable block (ram,0x0001400121d9) */
/* WARNING: Removing unreachable block (ram,0x0001400121ca) */

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



===== __security_check_cookie @ 140012290 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1400122d0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140012300 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140012300. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140012330 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcmp @ 140012360 =====

int __cdecl memcmp(void *_Buf1,void *_Buf2,size_t _Size)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  bool bVar5;
  
  lVar3 = (longlong)_Buf2 - (longlong)_Buf1;
  if (7 < _Size) {
    for (; ((ulonglong)_Buf1 & 7) != 0; _Buf1 = (void *)((longlong)_Buf1 + 1)) {
      bVar5 = (byte)*(ulonglong *)_Buf1 < *(byte *)((longlong)_Buf1 + lVar3);
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_1400123a3;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_140012414;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_140012410:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140012414;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_14001240c:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140012410;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14001240c;
          }
          _Buf1 = (void *)((longlong)_Buf1 + 0x20);
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
        _Size = _Size & 0x1f;
      }
      uVar4 = _Size >> 3;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) {
LAB_140012414:
            uVar4 = *(ulonglong *)(lVar3 + (longlong)_Buf1);
            uVar1 = (uint)((uVar2 >> 0x38 | (uVar2 & 0xff000000000000) >> 0x28 |
                            (uVar2 & 0xff0000000000) >> 0x18 | (uVar2 & 0xff00000000) >> 8 |
                            (uVar2 & 0xff000000) << 8 | (uVar2 & 0xff0000) << 0x18 |
                            (uVar2 & 0xff00) << 0x28 | uVar2 << 0x38) <
                          (uVar4 >> 0x38 | (uVar4 & 0xff000000000000) >> 0x28 |
                           (uVar4 & 0xff0000000000) >> 0x18 | (uVar4 & 0xff00000000) >> 8 |
                           (uVar4 & 0xff000000) << 8 | (uVar4 & 0xff0000) << 0x18 |
                           (uVar4 & 0xff00) << 0x28 | uVar4 << 0x38));
            return (1 - uVar1) - (uint)(uVar1 != 0);
          }
          _Buf1 = (void *)((longlong)_Buf1 + 8);
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
        _Size = _Size & 7;
      }
    }
  }
  while( true ) {
    if (_Size == 0) {
      return 0;
    }
    bVar5 = (byte)*(ulonglong *)_Buf1 < *(byte *)((longlong)_Buf1 + lVar3);
    if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) break;
    _Buf1 = (void *)((longlong)_Buf1 + 1);
    _Size = _Size - 1;
  }
LAB_1400123a3:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== memmove @ 140012480 =====

void * __cdecl memmove(void *_Dst,void *_Src,size_t _Size)

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



===== memset @ 140012780 =====

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



===== __memset_repmovs @ 1400128c0 =====

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



===== __memset_query @ 140012940 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1400129c0 =====

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



===== __memset_spec_ermsb_repmovsb @ 140012b00 =====

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



===== __memset_spec_plain @ 140012b80 =====

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



===== FUN_140012c9e @ 140012c9e =====

/* PDB: Separated code (from the compiler): 140012c9e - 140012d21 for parent address: 1400028e0 */

undefined8 FUN_140012c9e(void)

{
  byte bVar1;
  ulonglong uVar2;
  longlong unaff_R15;
  bool bVar3;
  
  if (*(int *)(unaff_R15 + 0x204) == 0) {
    LOCK();
    bVar3 = *(int *)(unaff_R15 + 0x374) == 0;
    if (bVar3) {
      *(int *)(unaff_R15 + 0x374) = 1;
    }
    UNLOCK();
    if (bVar3) {
      bVar1 = KeAcquireSpinLockRaiseToDpc(unaff_R15 + 0x70);
      uVar2 = (ulonglong)bVar1;
      PmUpdateOffline(unaff_R15,'\x01');
      KeReleaseSpinLock(unaff_R15 + 0x70,uVar2 & 0xff);
      LOCK();
      *(undefined4 *)(unaff_R15 + 0x208) = 0;
      UNLOCK();
      IoQueueWorkItem(*(undefined8 *)(unaff_R15 + 0x378),PmOfflineDiskWorkItem,0);
    }
  }
  return 0;
}



===== CreateGuid @ 14001e008 =====

/* public: static long __cdecl SC_ENV::CreateGuid(struct _GUID * __ptr64) */

long __cdecl SC_ENV::CreateGuid(_GUID *param_1)

{
  long lVar1;
  
  lVar1 = ExUuidCreate();
  return lVar1;
}



===== PmIoctlPerformanceOff @ 14001e024 =====

undefined8 PmIoctlPerformanceOff(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (*(char *)(lVar1 + 0x2c0) != '\0') {
    uVar2 = PmWmiCounterDisable((longlong *)(lVar1 + 0x2d0),'\0','\0');
    if ((char)uVar2 == '\0') {
      *(undefined1 *)(lVar1 + 0x2c0) = 0;
    }
  }
  return 0;
}



===== PmWritePartitionAttributesMbr @ 14001e064 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl PmWritePartitionAttributesMbr(struct _DEVICE_EXTENSION * __ptr64,struct
   _PARTITION_ATTRIBUTES_TABLE * __ptr64,unsigned long) */

long __cdecl
PmWritePartitionAttributesMbr
          (_DEVICE_EXTENSION *param_1,_PARTITION_ATTRIBUTES_TABLE *param_2,ulong param_3)

{
  byte *pbVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  uint uVar4;
  int iVar5;
  undefined8 *puVar6;
  longlong lVar7;
  undefined1 auStack_a8 [32];
  ulonglong *local_88;
  ulonglong *local_80;
  undefined8 *local_78;
  ulonglong local_68 [4];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined4 local_38;
  undefined8 local_34;
  undefined8 uStack_2c;
  uint local_24;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_a8;
  local_38 = 0;
  local_68[3] = 0;
  local_68[1] = 0;
  local_68[2] = 0;
  local_24 = 0;
  local_34 = 0;
  uStack_2c = 0;
  local_48 = 0;
  uStack_40 = 0;
  iVar5 = PmGetDriveGeometry(*(undefined8 *)(param_1 + 8),&local_38);
  uVar4 = local_24;
  if (-1 < iVar5) {
    local_68[0] = (ulonglong)(local_24 * 2);
    if ((0x17 < local_24) &&
       (puVar6 = (undefined8 *)ExAllocatePool2(0x42,local_24,0x54416d50),
       puVar6 != (undefined8 *)0x0)) {
      uVar3 = *(undefined8 *)(param_2 + 8);
      uVar2 = *(undefined8 *)(param_2 + 0x10);
      *puVar6 = *(undefined8 *)param_2;
      puVar6[1] = uVar3;
      puVar6[2] = uVar2;
      memset(puVar6 + 3,0,(ulonglong)(uVar4 - 0x18));
      KeInitializeEvent(local_68 + 1,0,0);
      local_78 = &local_48;
      local_80 = local_68 + 1;
      local_88 = local_68;
      lVar7 = IoBuildSynchronousFsdRequest(4,*(undefined8 *)(param_1 + 8),puVar6,uVar4);
      if (lVar7 == 0) {
        iVar5 = -0x3fffff66;
      }
      else {
        pbVar1 = (byte *)(*(longlong *)(lVar7 + 0xb8) + -0x46);
        *pbVar1 = *pbVar1 | 0x12;
        iVar5 = IofCallDriver(*(undefined8 *)(param_1 + 8));
        if (iVar5 == 0x103) {
          local_88 = (ulonglong *)0x0;
          KeWaitForSingleObject(local_68 + 1,0,0,0);
          iVar5 = (int)local_48;
        }
      }
      ExFreePoolWithTag(puVar6,0);
      return iVar5;
    }
    iVar5 = -0x3fffff66;
  }
  return iVar5;
}



===== PmCheckPassthrough @ 14001e200 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PmCheckPassthrough(_DEVICE_EXTENSION *param_1,undefined8 param_2)

{
  longlong lVar1;
  long lVar2;
  undefined1 auStack_68 [32];
  uint local_48 [2];
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  local_3c = 0;
  local_48[0] = 0;
  local_28 = 0;
  uStack_20 = 0;
  lVar1 = *(longlong *)(PmControlObject + 0x40);
  lVar2 = PmGetDeviceParameter(param_1,param_2,local_48);
  if (lVar2 < 0) {
    if (lVar2 != -0x3fffffcc) {
      return;
    }
    if (*(int *)(lVar1 + 0xa0) != 5) {
      return;
    }
    local_38 = 0x40;
    local_3c = CONCAT31(local_3c._1_3_,1);
    local_48[0] = 0x40;
  }
  else {
    local_38 = (ulonglong)local_48[0];
    if ((local_48[0] & 0x40) == 0) {
      return;
    }
    *(ulonglong *)(param_1 + 0x218) = local_38;
  }
  local_30 = 0xffffffffffffffff;
  local_40 = 0x28;
  PmSetDiskAttributes(param_1,(longlong)&local_40,0);
  return;
}



===== PmSetInitialDiskAttributes @ 14001e2bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PmSetInitialDiskAttributes(_DEVICE_EXTENSION *param_1,undefined8 param_2)

{
  int iVar1;
  longlong lVar2;
  long lVar3;
  uint uVar4;
  bool bVar5;
  undefined1 auStack_88 [32];
  undefined8 local_68;
  uint local_58 [2];
  undefined4 local_50;
  undefined4 local_4c;
  ulonglong local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_88;
  uVar4 = 0;
  local_4c = 0;
  local_58[0] = 0;
  local_38 = 0;
  uStack_30 = 0;
  lVar2 = *(longlong *)(PmControlObject + 0x40);
  if ((*(uint *)(param_1 + 0x200) >> 0xd & 1) != 0) {
    local_48 = 4;
    local_58[0] = 4;
    goto LAB_14001e3f2;
  }
  if (*(int *)(param_1 + 0xa8) == -1) {
    local_48 = 7;
    local_58[0] = 7;
    uVar4 = 2;
    goto LAB_14001e3f2;
  }
  lVar3 = PmGetDeviceParameter(param_1,param_2,local_58);
  if (lVar3 < 0) {
    if (lVar3 != -0x3fffffcc) {
      return;
    }
    local_58[0] = 0;
    local_68 = 0;
    KeWaitForSingleObject(lVar2 + 0x10,0,0,0);
    iVar1 = *(int *)(lVar2 + 0xa0);
    if (iVar1 == 2) {
      if ((((*(uint *)(*(longlong *)(param_1 + 8) + 0x34) & 1) != 0) ||
          (0x10 < *(uint *)(*(longlong *)(param_1 + 0xe8) + 0x1c))) ||
         ((0x10642U >> (*(uint *)(*(longlong *)(param_1 + 0xe8) + 0x1c) & 0x1f) & 1) == 0))
      goto LAB_14001e3d4;
      if ((*(uint *)(param_1 + 0x200) >> 0xc & 1) != 0) {
        bVar5 = *(char *)(lVar2 + 0xa8) == '\0';
        goto LAB_14001e3ce;
      }
LAB_14001e3d0:
      local_58[0] = local_58[0] | 3;
    }
    else {
      if (iVar1 == 3) goto LAB_14001e3d0;
      if (iVar1 == 4) {
        bVar5 = (*(uint *)(*(longlong *)(param_1 + 8) + 0x34) & 0x40000) == 0;
LAB_14001e3ce:
        if (bVar5) goto LAB_14001e3d0;
      }
    }
LAB_14001e3d4:
    KeReleaseMutex(lVar2 + 0x10,0);
    local_48 = (ulonglong)local_58[0];
    local_4c = CONCAT31(local_4c._1_3_,1);
  }
  else {
    local_48 = (ulonglong)local_58[0];
    *(ulonglong *)(param_1 + 0x218) = local_48;
  }
  uVar4 = 1;
LAB_14001e3f2:
  local_40 = 0xffffffffffffffff;
  local_50 = 0x28;
  PmSetDiskAttributes(param_1,(longlong)&local_50,uVar4);
  return;
}



===== wil_RtlStagingConfig_QueryFeatureState @ 14001e43c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 wil_RtlStagingConfig_QueryFeatureState(uint *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 local_20;
  uint local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = 0;
  local_20 = 0;
  local_18 = 0;
  iVar1 = RtlQueryFeatureConfiguration(param_2,param_3 == 0,&local_28,&local_20);
  if (iVar1 == 0) {
    *param_1 = local_20._4_4_ >> 4 & 3;
    *(byte *)(param_1 + 1) = (byte)((ulonglong)local_20 >> 0x28) & 0x3f;
    param_1[3] = local_18;
    param_1[2] = local_20._4_4_ >> 0xe & 3;
    param_1[5] = local_20._4_4_ >> 6 & 1;
    param_1[4] = local_20._4_4_ >> 7 & 1;
  }
  else {
    if (iVar1 != 0x117) {
      return 0;
    }
    param_1[4] = local_20._4_4_ >> 7 & 1;
  }
  return 1;
}



===== Write @ 14001e510 =====

/* public: virtual long __cdecl PM_DISK::Write(unsigned __int64,unsigned long,unsigned char *
   __ptr64) __ptr64 */

long __thiscall PM_DISK::Write(PM_DISK *this,__uint64 param_1,ulong param_2,uchar *param_3)

{
  byte *pbVar1;
  long lVar2;
  longlong lVar3;
  __uint64 local_res10 [3];
  
  local_res10[0] = param_1;
  lVar3 = IoBuildAsynchronousFsdRequest(4,*(undefined8 *)(this + 400),param_3,param_2,local_res10,0)
  ;
  if (lVar3 == 0) {
    lVar2 = -0x3fffff66;
  }
  else {
    pbVar1 = (byte *)(*(longlong *)(lVar3 + 0xb8) + -0x46);
    *pbVar1 = *pbVar1 | 0x12;
    lVar2 = IoSynchronousCallDriver(*(undefined8 *)(this + 400),lVar3);
    MmUnlockPages(*(undefined8 *)(lVar3 + 8));
    IoFreeMdl(*(undefined8 *)(lVar3 + 8));
    IoFreeIrp(lVar3);
  }
  return lVar2;
}



===== PmCreatePartitionTable @ 14001e5c8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long PmCreatePartitionTable(_DEVICE_OBJECT *param_1,_CREATE_DISK *param_2)

{
  long lVar1;
  undefined1 auStack_1d8 [32];
  undefined **local_1b8 [49];
  undefined8 local_30;
  undefined8 local_28;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_1d8;
  SC_DISK::SC_DISK((SC_DISK *)local_1b8);
  local_30 = 0;
  local_28 = 0;
  local_1b8[0] = &PM_DISK::_vftable_;
  lVar1 = PM_DISK::Initialize((PM_DISK *)local_1b8,param_1,'\x01');
  if (-1 < lVar1) {
    lVar1 = SC_DISK::CreatePartitionTable((SC_DISK *)local_1b8,param_2);
  }
  PM_DISK::~PM_DISK((PM_DISK *)local_1b8);
  return lVar1;
}



===== PmSetPartition @ 14001e670 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long PmSetPartition(_DEVICE_OBJECT *param_1,ulong param_2,_SET_PARTITION_INFORMATION_EX *param_3)

{
  long lVar1;
  undefined1 auStack_1e8 [32];
  undefined **local_1c8 [49];
  undefined8 local_40;
  undefined8 local_38;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_1e8;
  SC_DISK::SC_DISK((SC_DISK *)local_1c8);
  local_40 = 0;
  local_38 = 0;
  local_1c8[0] = &PM_DISK::_vftable_;
  lVar1 = PM_DISK::Initialize((PM_DISK *)local_1c8,param_1,'\x01');
  if (-1 < lVar1) {
    lVar1 = SC_DISK::SetPartition((SC_DISK *)local_1c8,param_2,param_3);
  }
  PM_DISK::~PM_DISK((PM_DISK *)local_1c8);
  return lVar1;
}



===== PmWritePartitionTable @ 14001e714 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long PmWritePartitionTable(_DEVICE_OBJECT *param_1,SC_DISK_LAYOUT *param_2)

{
  long lVar1;
  undefined1 auStack_1d8 [32];
  undefined **local_1b8 [49];
  undefined8 local_30;
  undefined8 local_28;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_1d8;
  SC_DISK::SC_DISK((SC_DISK *)local_1b8);
  local_30 = 0;
  local_28 = 0;
  local_1b8[0] = &PM_DISK::_vftable_;
  if (*(uint *)param_2 < 2) {
    lVar1 = PM_DISK::Initialize((PM_DISK *)local_1b8,param_1,'\x01');
    if (-1 < lVar1) {
      lVar1 = SC_DISK::WritePartitionTable((SC_DISK *)local_1b8,param_2);
    }
  }
  else {
    lVar1 = -0x3fffff45;
  }
  PM_DISK::~PM_DISK((PM_DISK *)local_1b8);
  return lVar1;
}



===== PartitionIoctlGetPartitionInfo @ 14001e7c8 =====

uint PartitionIoctlGetPartitionInfo(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  uint uVar3;
  longlong lVar4;
  
  lVar4 = *(longlong *)(param_2 + 0xb8);
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (*(uint *)(lVar4 + 8) < 0x20) {
    uVar3 = 0xc0000023;
  }
  else {
    puVar2 = *(undefined8 **)(param_2 + 0x18);
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    KeWaitForSingleObject(*(longlong *)(lVar1 + 0x18) + 0x38,0,0,0,0);
    if (((*(byte *)(lVar4 + 2) & 2) != 0) && ((*(uint *)(*(longlong *)(lVar1 + 8) + 0x34) & 1) != 0)
       ) {
      PmInvalidatePartitionTableCache(*(longlong *)(lVar1 + 0x18));
    }
    uVar3 = PmGetDriveLayoutEx(*(_DEVICE_EXTENSION **)(lVar1 + 0x18),(undefined8 *)0x0);
    if (-1 < (int)uVar3) {
      if (*(int *)(lVar1 + 0xa8) == 0) {
        *puVar2 = *(undefined8 *)(lVar1 + 0xb0);
        lVar4 = PartitionLength(lVar1,'\x01');
        puVar2[1] = lVar4;
        *(undefined4 *)(puVar2 + 2) = *(undefined4 *)(lVar1 + 0xcc);
        *(undefined4 *)((longlong)puVar2 + 0x14) = *(undefined4 *)(lVar1 + 0xc0);
        *(undefined1 *)(puVar2 + 3) = *(undefined1 *)(lVar1 + 200);
        *(undefined1 *)((longlong)puVar2 + 0x19) = *(undefined1 *)(lVar1 + 0xc9);
        *(undefined1 *)((longlong)puVar2 + 0x1a) = *(undefined1 *)(lVar1 + 0xca);
        *(undefined1 *)((longlong)puVar2 + 0x1b) = *(undefined1 *)(lVar1 + 0xc4);
        *(undefined8 *)(param_2 + 0x38) = 0x20;
      }
      else {
        uVar3 = 0xc0000010;
      }
    }
    KeReleaseMutex(*(longlong *)(lVar1 + 0x18) + 0x38,0);
  }
  return uVar3;
}



===== PartitionIoctlManageBypassIo @ 14001e8f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint PartitionIoctlManageBypassIo(longlong param_1,longlong param_2)

{
  undefined4 uVar1;
  longlong lVar2;
  undefined4 *_Dst;
  bool bVar3;
  uint uVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  undefined1 auStack_e8 [32];
  undefined8 local_c8;
  wchar_t local_b8 [16];
  wchar_t local_98 [40];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_e8;
  lVar6 = *(longlong *)(param_2 + 0xb8);
  lVar2 = *(longlong *)(param_1 + 0x40);
  bVar3 = false;
  builtin_wcsncpy(local_b8,L"partmgr.sys",0xc);
  builtin_wcsncpy(local_98,L"Stitched partition not supported",0x21);
  if (*(uint *)(lVar6 + 0x10) < 0x18) {
    uVar4 = 0xc0000004;
    goto LAB_14001eaec;
  }
  lVar7 = *(longlong *)(param_2 + 0x18);
  if ((*(int *)(lVar7 + 8) - 1U & 0xfffffffd) != 0) goto LAB_14001eac4;
  if (*(uint *)(lVar6 + 8) < 0x160) {
    uVar4 = 0xc0000023;
    goto LAB_14001eaec;
  }
  local_c8 = 0;
  KeWaitForSingleObject(*(longlong *)(lVar2 + 0x18) + 0x38,0,0,0);
  bVar3 = true;
  uVar4 = PmGetDriveLayoutEx(*(_DEVICE_EXTENSION **)(lVar2 + 0x18),(undefined8 *)0x0);
  if (-1 < (int)uVar4) {
    if (*(int *)(lVar2 + 0xa8) == 1) {
      lVar5 = *(longlong *)(lVar2 + 200) + -0x6aa896aa8967a686;
      if (lVar5 == 0) {
        lVar5 = *(longlong *)(lVar2 + 0xd0) + 0x6fefaba9bd57766b;
      }
      if (lVar5 == 0) {
        uVar1 = *(undefined4 *)(lVar7 + 8);
        _Dst = *(undefined4 **)(param_2 + 0x18);
        memset(_Dst,0,(ulonglong)*(uint *)(lVar6 + 8));
        _Dst[2] = uVar1;
        lVar6 = -1;
        *_Dst = 0x160;
        lVar7 = -1;
        _Dst[1] = 0x160;
        _Dst[6] = 0xc00004c6;
        do {
          lVar7 = lVar7 + 1;
        } while (local_b8[lVar7] != L'\0');
        *(short *)(_Dst + 7) = (short)lVar7;
        do {
          lVar6 = lVar6 + 1;
        } while (local_98[lVar6] != L'\0');
        *(short *)((longlong)_Dst + 0x5e) = (short)lVar6;
        wcscpy_s((wchar_t *)((longlong)_Dst + 0x1e),0x40,local_b8);
        wcscpy_s((wchar_t *)(_Dst + 0x18),0x100,local_98);
        uVar4 = 0;
        *(undefined8 *)(param_2 + 0x38) = 0x160;
        goto LAB_14001ead6;
      }
    }
LAB_14001eac4:
    uVar4 = PartitionForwardIrpSynchronously(param_1,param_2);
    if (!bVar3) goto LAB_14001eaec;
  }
LAB_14001ead6:
  KeReleaseMutex(*(longlong *)(lVar2 + 0x18) + 0x38,0);
LAB_14001eaec:
  *(uint *)(param_2 + 0x30) = uVar4;
  IofCompleteRequest(param_2,0);
  return uVar4;
}



===== PartitionIoctlSetPartitionAttributes @ 14001eb34 =====

uint PartitionIoctlSetPartitionAttributes(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int *piVar2;
  uint uVar3;
  ulong uVar4;
  undefined4 local_88 [2];
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  memset(local_88,0,0x78);
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10) < 0x18) {
    return 0xc0000004;
  }
  piVar2 = *(int **)(param_2 + 0x18);
  if ((((*piVar2 != 0x18) || (*(char *)((longlong)piVar2 + 5) != '\0')) ||
      (*(char *)((longlong)piVar2 + 6) != '\0')) || (*(char *)((longlong)piVar2 + 7) != '\0')) {
    return 0xc000000d;
  }
  uVar4 = 0;
  KeWaitForSingleObject(*(longlong *)(lVar1 + 0x18) + 0x38,0,0,0,0);
  uVar3 = PmGetDriveLayoutEx(*(_DEVICE_EXTENSION **)(lVar1 + 0x18),(undefined8 *)0x0);
  if (-1 < (int)uVar3) {
    if (*(int *)(lVar1 + 0xa8) == 0) {
      uVar3 = PmSetPartitionAttributesMbr
                        (*(_DEVICE_EXTENSION **)(lVar1 + 0x18),*(undefined8 *)(piVar2 + 2),uVar4);
    }
    else if (*(int *)(lVar1 + 0xa8) == 1) {
      local_80 = *(undefined8 *)(lVar1 + 200);
      uStack_78 = *(undefined8 *)(lVar1 + 0xd0);
      local_60 = *(undefined8 *)(piVar2 + 2);
      local_70 = *(undefined8 *)(lVar1 + 0xd8);
      uStack_68 = *(undefined8 *)(lVar1 + 0xe0);
      local_88[0] = 1;
      uStack_58 = *(undefined8 *)(lVar1 + 0xf0);
      local_50 = *(undefined8 *)(lVar1 + 0xf8);
      uStack_48 = *(undefined8 *)(lVar1 + 0x100);
      local_40 = *(undefined8 *)(lVar1 + 0x108);
      uStack_38 = *(undefined8 *)(lVar1 + 0x110);
      local_30 = *(undefined8 *)(lVar1 + 0x118);
      uStack_28 = *(undefined8 *)(lVar1 + 0x120);
      local_20 = *(undefined8 *)(lVar1 + 0x128);
      uStack_18 = *(undefined8 *)(lVar1 + 0x130);
      uVar3 = PmSetPartitionInformationEx(lVar1,(_SET_PARTITION_INFORMATION_EX *)local_88);
    }
    else {
      uVar3 = 0xc0000010;
    }
  }
  KeReleaseMutex(*(longlong *)(lVar1 + 0x18) + 0x38,0);
  return uVar3;
}



===== PartitionIoctlSetPartitionInfo @ 14001ecb8 =====

uint PartitionIoctlSetPartitionInfo(longlong param_1,longlong param_2)

{
  longlong lVar1;
  uint uVar2;
  _SET_PARTITION_INFORMATION_EX local_88 [8];
  undefined1 local_80;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  memset(local_88,0,0x78);
  if (*(int *)(*(longlong *)(param_2 + 0xb8) + 0x10) == 0) {
    uVar2 = 0xc0000004;
  }
  else {
    local_80 = **(undefined1 **)(param_2 + 0x18);
    KeWaitForSingleObject(*(longlong *)(lVar1 + 0x18) + 0x38,0,0,0,0);
    uVar2 = PmGetDriveLayoutEx(*(_DEVICE_EXTENSION **)(lVar1 + 0x18),(undefined8 *)0x0);
    if (-1 < (int)uVar2) {
      if (*(int *)(lVar1 + 0xa8) == 0) {
        uVar2 = PmSetPartitionInformationEx(lVar1,local_88);
      }
      else {
        uVar2 = 0xc0000010;
      }
    }
    KeReleaseMutex(*(longlong *)(lVar1 + 0x18) + 0x38,0);
  }
  return uVar2;
}



===== PartitionIoctlSetPartitionInfoEx @ 14001ed7c =====

uint PartitionIoctlSetPartitionInfoEx(longlong param_1,longlong param_2)

{
  longlong lVar1;
  _SET_PARTITION_INFORMATION_EX *p_Var2;
  uint uVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10) < 0x78) {
    uVar3 = 0xc0000004;
  }
  else {
    p_Var2 = *(_SET_PARTITION_INFORMATION_EX **)(param_2 + 0x18);
    KeWaitForSingleObject(*(longlong *)(lVar1 + 0x18) + 0x38,0,0,0,0);
    uVar3 = PmGetDriveLayoutEx(*(_DEVICE_EXTENSION **)(lVar1 + 0x18),(undefined8 *)0x0);
    if (-1 < (int)uVar3) {
      uVar3 = PmSetPartitionInformationEx(lVar1,p_Var2);
    }
    KeReleaseMutex(*(longlong *)(lVar1 + 0x18) + 0x38,0);
  }
  return uVar3;
}



===== PmIoctlCreateDisk @ 14001ee18 =====

uint PmIoctlCreateDisk(longlong param_1,longlong param_2)

{
  _DEVICE_EXTENSION *p_Var1;
  longlong lVar2;
  _CREATE_DISK *p_Var3;
  uint uVar4;
  
  p_Var1 = *(_DEVICE_EXTENSION **)(param_1 + 0x40);
  lVar2 = *(longlong *)(param_2 + 0xb8);
  if (*(int *)(*(longlong *)(p_Var1 + 0xe8) + 0x1c) == 0x12) {
    IoForwardIrpSynchronously(*(undefined8 *)(p_Var1 + 0x10));
    if ((int)*(uint *)(param_2 + 0x30) < 0) {
      return *(uint *)(param_2 + 0x30);
    }
  }
  if (*(uint *)(lVar2 + 0x10) < 0x18) {
    uVar4 = 0xc0000004;
  }
  else {
    p_Var3 = *(_CREATE_DISK **)(param_2 + 0x18);
    KeWaitForSingleObject(p_Var1 + 0x38,0,0,0,0);
    uVar4 = PmCreateDisk(p_Var1,p_Var3);
    KeReleaseMutex(p_Var1 + 0x38,0);
  }
  return uVar4;
}



===== PmIoctlCreateSpacesMetadata @ 14001eecc =====

long PmIoctlCreateSpacesMetadata(longlong param_1,longlong param_2)

{
  _DEVICE_EXTENSION *p_Var1;
  longlong lVar2;
  long lVar3;
  undefined8 uVar4;
  __uint64 _Var5;
  
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10) < 0x260) {
    lVar3 = -0x3ffffffc;
  }
  else {
    p_Var1 = *(_DEVICE_EXTENSION **)(param_1 + 0x40);
    _Var5 = 0;
    lVar2 = *(longlong *)(param_2 + 0x18);
    uVar4 = 0;
    KeWaitForSingleObject(p_Var1 + 0x38,0,0,0,0);
    lVar3 = PmCreateSpacesMetadata(p_Var1,lVar2,uVar4,_Var5);
    KeReleaseMutex(p_Var1 + 0x38,0);
  }
  return lVar3;
}



===== PmIoctlDeleteDriveLayout @ 14001ef50 =====

uint PmIoctlDeleteDriveLayout(longlong param_1)

{
  _DEVICE_EXTENSION *p_Var1;
  _DEVICE_EXTENSION *p_Var2;
  uint uVar3;
  
  p_Var2 = *(_DEVICE_EXTENSION **)(param_1 + 0x40);
  p_Var1 = p_Var2 + 0x38;
  KeWaitForSingleObject(p_Var1,0,0,0,0);
  uVar3 = PmCreateDisk(p_Var2,(_CREATE_DISK *)0x0);
  KeReleaseMutex(p_Var1,0);
  return uVar3;
}



===== PmIoctlDeleteSpacesMetadata @ 14001efb0 =====

long PmIoctlDeleteSpacesMetadata(longlong param_1)

{
  _DEVICE_EXTENSION *p_Var1;
  _DEVICE_EXTENSION *p_Var2;
  long lVar3;
  
  p_Var2 = *(_DEVICE_EXTENSION **)(param_1 + 0x40);
  p_Var1 = p_Var2 + 0x38;
  KeWaitForSingleObject(p_Var1,0,0,0,0);
  lVar3 = PmDeleteSpacesMetadata(p_Var2);
  KeReleaseMutex(p_Var1,0);
  return lVar3;
}



===== PmIoctlDsmQuerySectorWrite @ 14001f010 =====

ulonglong PmIoctlDsmQuerySectorWrite
                    (longlong param_1,undefined1 *param_2,ulonglong *param_3,longlong *param_4)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong lVar5;
  longlong lVar6;
  ulonglong *puVar7;
  uint uVar8;
  ulonglong uVar9;
  undefined4 local_res8;
  undefined4 uStackX_c;
  
  local_res8 = 0;
  uStackX_c = 0;
  uVar1 = *(uint *)(*(longlong *)(param_1 + 0xb8) + 0x10);
  if (uVar1 < 0x1c) {
    return 0xc000000d;
  }
  lVar6 = *(longlong *)(param_1 + 0x18);
  uVar8 = *(uint *)(lVar6 + 0x18);
  if (uVar8 != 0) {
    if ((*(uint *)(lVar6 + 8) & 1) != 0) {
      return 0xc000000d;
    }
    uVar2 = *(uint *)(lVar6 + 0x14);
    if (uVar2 == 0) {
      return 0xc000000d;
    }
    if ((uVar8 & 0xf) != 0) {
      return 0xc000000d;
    }
    if (uVar2 < 0x1c) {
      return 0xc000000d;
    }
    if (uVar8 + uVar2 < uVar2) {
      return 0xc0000095;
    }
    if (uVar1 < uVar8 + uVar2) {
      return 0xc000000d;
    }
  }
  if (*(int *)(lVar6 + 4) < 0) {
LAB_14001f0e5:
    *param_2 = 0;
    return 0;
  }
  if ((*(uint *)(lVar6 + 8) & 1) == 0) {
    if (uVar8 == 0) goto LAB_14001f0e5;
    lVar5 = 0;
    puVar7 = (ulonglong *)((ulonglong)*(uint *)(lVar6 + 0x14) + lVar6);
    uVar3 = 0x7fffffffffffffff;
    if (((ulonglong)puVar7 & 7) != 0) {
      return 0xc000000d;
    }
    for (; uVar9 = 0, 0xf < uVar8; uVar8 = uVar8 - 0x10) {
      uVar9 = *puVar7;
      uVar4 = uVar9;
      if ((longlong)uVar3 <= (longlong)uVar9) {
        uVar4 = uVar3;
      }
      if ((longlong)uVar9 < 0) {
        return 0xc000000d;
      }
      uVar3 = puVar7[1] + uVar9;
      if (uVar3 < uVar9) {
        return 0xc0000095;
      }
      if ((longlong)uVar3 < 0) {
        return 0xc0000095;
      }
      if (lVar5 < (longlong)uVar3) {
        lVar5 = uVar3 - 1;
      }
      puVar7 = puVar7 + 2;
      uVar3 = uVar4;
    }
    *param_3 = uVar3;
    lVar6 = (lVar5 - uVar3) + 1;
  }
  else {
    uVar3 = PmSendDeviceControl(*(undefined8 *)(*(longlong *)(param_1 + 0xb8) + 0x28),0x7405c,0,0,
                                &local_res8,8,0);
    uVar9 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      return uVar9;
    }
    *param_3 = 0;
    lVar6 = CONCAT44(uStackX_c,local_res8);
  }
  *param_2 = 1;
  *param_4 = lVar6;
  return uVar9;
}



===== PmIoctlGetPartitionInfo @ 14001f184 =====

int PmIoctlGetPartitionInfo(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 *puVar3;
  int iVar4;
  undefined8 local_res8;
  
  local_res8 = 0;
  lVar1 = *(longlong *)(param_2 + 0xb8);
  lVar2 = *(longlong *)(param_1 + 0x40);
  if (*(uint *)(lVar1 + 8) < 0x20) {
    iVar4 = -0x3fffffdd;
  }
  else {
    puVar3 = *(undefined8 **)(param_2 + 0x18);
    *(undefined4 *)(lVar1 + 0x10) = 0;
    *(undefined4 *)(lVar1 + 8) = 8;
    *(undefined4 *)(lVar1 + 0x18) = 0x7405c;
    *(undefined8 **)(param_2 + 0x18) = &local_res8;
    IoForwardIrpSynchronously(*(undefined8 *)(lVar2 + 0x10));
    iVar4 = *(int *)(param_2 + 0x30);
    *(undefined8 **)(param_2 + 0x18) = puVar3;
    if (-1 < iVar4) {
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[2] = 0;
      puVar3[3] = 0;
      KeWaitForSingleObject(lVar2 + 0x38,0,0,0,0);
      *puVar3 = 0;
      *(undefined4 *)(puVar3 + 2) = 0;
      *(undefined4 *)((longlong)puVar3 + 0x14) = 0;
      *(undefined4 *)(puVar3 + 3) = 0;
      puVar3[1] = local_res8;
      *(undefined8 *)(param_2 + 0x38) = 0x20;
      KeReleaseMutex(lVar2 + 0x38,0);
    }
  }
  return iVar4;
}



===== PmIoctlGetReliabilityInfo @ 14001f270 =====

undefined8 PmIoctlGetReliabilityInfo(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  
  uVar3 = 0;
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 8) < 0x20) {
    uVar3 = 0xc0000023;
  }
  else {
    puVar2 = *(undefined8 **)(param_2 + 0x18);
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    KeWaitForSingleObject(lVar1 + 0x38,0,0,0,0);
    *(undefined4 *)puVar2 = 0x20;
    puVar2[1] = *(undefined8 *)(lVar1 + 0x318);
    puVar2[2] = *(undefined8 *)(lVar1 + 800);
    puVar2[3] = *(undefined8 *)(lVar1 + 0x328);
    KeReleaseMutex(lVar1 + 0x38,0);
    *(undefined8 *)(param_2 + 0x38) = 0x20;
  }
  return uVar3;
}



===== PmIoctlGetSanSettings @ 14001f338 =====

undefined8 PmIoctlGetSanSettings(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  
  uVar4 = 0;
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 8) < 8) {
    uVar4 = 0xc0000023;
  }
  else {
    puVar2 = *(undefined8 **)(param_2 + 0x18);
    *puVar2 = 0;
    KeWaitForSingleObject(lVar1 + 0x10,0,0,0,0);
    *(undefined4 *)puVar2 = 8;
    *(undefined4 *)((longlong)puVar2 + 4) = *(undefined4 *)(lVar1 + 0xa0);
    KeReleaseMutex(lVar1 + 0x10,0);
    uVar3 = Feature_Partition_Manager_Passthrough__private_IsEnabledDeviceUsageNoInline();
    if (((int)uVar3 == 0) && (*(int *)((longlong)puVar2 + 4) == 5)) {
      *(undefined4 *)((longlong)puVar2 + 4) = 1;
    }
    *(undefined8 *)(param_2 + 0x38) = 8;
  }
  return uVar4;
}



===== PmIoctlGetSnapshotInfo @ 14001f3f8 =====

uint PmIoctlGetSnapshotInfo(longlong param_1,longlong param_2)

{
  _DEVICE_EXTENSION *p_Var1;
  longlong lVar2;
  _DEVICE_EXTENSION *p_Var3;
  undefined8 *puVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  uint uVar7;
  uint uVar8;
  undefined8 *local_res8;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  local_res8 = (undefined8 *)0x0;
  p_Var3 = *(_DEVICE_EXTENSION **)(param_1 + 0x40);
  if (*(uint *)(lVar2 + 8) < 0x4c) {
    uVar7 = 0xc0000023;
  }
  else {
    p_Var1 = p_Var3 + 0x38;
    KeWaitForSingleObject(p_Var1,0,0,0,0);
    uVar7 = PmGetSnapshotInfo(p_Var3,&local_res8);
    KeReleaseMutex(p_Var1,0);
    puVar6 = local_res8;
    if (-1 < (int)uVar7) {
      uVar5 = local_res8[1];
      puVar4 = *(undefined8 **)(param_2 + 0x18);
      *puVar4 = *local_res8;
      puVar4[1] = uVar5;
      uVar5 = local_res8[3];
      puVar4[2] = local_res8[2];
      puVar4[3] = uVar5;
      uVar5 = local_res8[5];
      puVar4[4] = local_res8[4];
      puVar4[5] = uVar5;
      uVar5 = local_res8[7];
      puVar4[6] = local_res8[6];
      puVar4[7] = uVar5;
      puVar4[8] = local_res8[8];
      *(undefined4 *)(puVar4 + 9) = *(undefined4 *)(local_res8 + 9);
      uVar8 = *(int *)(local_res8 + 9) + 0x4c;
      if (uVar8 < 0x4c) {
        uVar7 = 0xc0000095;
      }
      else {
        uVar7 = 0;
        if (*(uint *)(lVar2 + 8) < uVar8) {
          *(undefined8 *)(param_2 + 0x38) = 0x4c;
          uVar7 = 0x80000005;
        }
        else {
          memmove(*(void **)(param_2 + 0x18),local_res8,(ulonglong)uVar8);
          *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar8;
        }
      }
    }
    if (puVar6 != (undefined8 *)0x0) {
      ExFreePoolWithTag(puVar6,0);
    }
  }
  return uVar7;
}



===== PmIoctlGrowPartition @ 14001f51c =====

uint PmIoctlGrowPartition(longlong param_1,longlong param_2)

{
  longlong lVar1;
  _DEVICE_EXTENSION *p_Var2;
  int *piVar3;
  SC_DISK_LAYOUT *pSVar4;
  uint uVar5;
  SC_DISK_LAYOUT *local_res8;
  longlong local_res10;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  uVar5 = 0;
  local_res10 = 0;
  local_res8 = (SC_DISK_LAYOUT *)0x0;
  p_Var2 = *(_DEVICE_EXTENSION **)(param_1 + 0x40);
  if (*(uint *)(lVar1 + 0x10) < 0x10) {
    uVar5 = 0xc0000004;
  }
  else {
    piVar3 = *(int **)(param_2 + 0x18);
    if (*(longlong *)(piVar3 + 2) != 0) {
      *(undefined4 *)(lVar1 + 0x10) = 0;
      *(undefined4 *)(lVar1 + 8) = 8;
      *(undefined4 *)(lVar1 + 0x18) = 0x7405c;
      *(longlong **)(param_2 + 0x18) = &local_res10;
      IoForwardIrpSynchronously(*(undefined8 *)(p_Var2 + 0x10));
      uVar5 = *(uint *)(param_2 + 0x30);
      *(int **)(param_2 + 0x18) = piVar3;
      if (-1 < (int)uVar5) {
        KeWaitForSingleObject(p_Var2 + 0x38,0,0,0,0);
        uVar5 = PmGetDriveLayoutEx(p_Var2,&local_res8);
        pSVar4 = local_res8;
        if (-1 < (int)uVar5) {
          uVar5 = PmGrowPartition(p_Var2,local_res8,piVar3,local_res10);
        }
        KeReleaseMutex(p_Var2 + 0x38,0);
        if (pSVar4 != (SC_DISK_LAYOUT *)0x0) {
          ExFreePoolWithTag(pSVar4,0);
        }
      }
    }
  }
  return uVar5;
}



===== PmIoctlQueryDiskSignature @ 14001f62c =====

uint PmIoctlQueryDiskSignature(longlong param_1,longlong param_2)

{
  _DEVICE_EXTENSION *p_Var1;
  undefined4 *puVar2;
  uint uVar3;
  
  p_Var1 = *(_DEVICE_EXTENSION **)(param_1 + 0x40);
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 8) < 4) {
    uVar3 = 0xc0000023;
  }
  else {
    puVar2 = *(undefined4 **)(param_2 + 0x18);
    KeWaitForSingleObject(p_Var1 + 0x38,0,0,0,0);
    uVar3 = PmGetDriveLayoutEx(p_Var1,(undefined8 *)0x0);
    if (-1 < (int)uVar3) {
      if (*(int *)(p_Var1 + 0x390) == 0) {
        *puVar2 = *(undefined4 *)(p_Var1 + 0x398);
        *(undefined8 *)(param_2 + 0x38) = 4;
      }
      else {
        uVar3 = 0xc0000010;
      }
    }
    KeReleaseMutex(p_Var1 + 0x38,0);
  }
  return uVar3;
}



===== PmIoctlResetReliabilityInfo @ 14001f6ec =====

undefined8 PmIoctlResetReliabilityInfo(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  KeWaitForSingleObject(lVar1 + 0x38,0,0,0,0);
  LOCK();
  *(undefined8 *)(lVar1 + 0x318) = 0;
  UNLOCK();
  LOCK();
  *(undefined8 *)(lVar1 + 800) = 0;
  UNLOCK();
  LOCK();
  *(undefined8 *)(lVar1 + 0x328) = 0;
  UNLOCK();
  KeReleaseMutex(lVar1 + 0x38,0);
  return 0;
}



===== PmIoctlResetSnapshotInfo @ 14001f764 =====

uint PmIoctlResetSnapshotInfo(longlong param_1)

{
  _DEVICE_EXTENSION *p_Var1;
  _DEVICE_EXTENSION *p_Var2;
  uint uVar3;
  undefined1 local_58 [80];
  
  p_Var2 = *(_DEVICE_EXTENSION **)(param_1 + 0x40);
  memset(local_58,0,0x50);
  p_Var1 = p_Var2 + 0x38;
  KeWaitForSingleObject(p_Var1,0,0,0,0);
  uVar3 = PmSetSnapshotInfo(p_Var2,(longlong)local_58);
  KeReleaseMutex(p_Var1,0);
  return uVar3;
}



===== PmIoctlSetClusterInfo @ 14001f7e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 PmIoctlSetClusterInfo(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int *piVar2;
  undefined8 uVar3;
  undefined1 auStack_68 [32];
  undefined8 local_48;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 local_24;
  undefined8 local_20;
  undefined4 local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  uVar3 = 0;
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_24 = 0;
  local_14 = 0;
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10) < 0x20) {
    uVar3 = 0xc0000004;
  }
  else {
    piVar2 = *(int **)(param_2 + 0x18);
    if (*piVar2 == 0x20) {
      local_48 = 0;
      KeWaitForSingleObject(lVar1 + 0x38,0,0,0);
      *(ulonglong *)(lVar1 + 0x238) =
           ~*(ulonglong *)(piVar2 + 4) & *(ulonglong *)(lVar1 + 0x238) |
           *(ulonglong *)(piVar2 + 2) & *(ulonglong *)(piVar2 + 4);
      KeReleaseMutex(lVar1 + 0x38,0);
      if ((char)piVar2[6] != '\0') {
        local_18 = 0xffffffff;
        local_38 = 0x240001;
        local_34 = 0x11dff54c;
        uStack_30 = 0x41f98469;
        uStack_2c = 0x83efdeb3;
        uStack_28 = 0x4ac58764;
        local_20 = 0;
        IoReportTargetDeviceChangeAsynchronous(*(undefined8 *)(lVar1 + 0x18),&local_38,0,0);
      }
    }
    else {
      uVar3 = 0xc000000d;
    }
  }
  return uVar3;
}



===== PmIoctlSetDiskAttributes @ 14001f8f8 =====

uint PmIoctlSetDiskAttributes(longlong param_1,longlong param_2)

{
  _DEVICE_EXTENSION *p_Var1;
  int *piVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  bool bVar5;
  uint uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  _DRIVE_LAYOUT_INFORMATION_EX *p_Var9;
  _DRIVE_LAYOUT_INFORMATION_EX *local_res8;
  
  p_Var1 = *(_DEVICE_EXTENSION **)(param_1 + 0x40);
  local_res8 = (_DRIVE_LAYOUT_INFORMATION_EX *)0x0;
  p_Var9 = (_DRIVE_LAYOUT_INFORMATION_EX *)0x0;
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10) < 0x28) {
    uVar6 = 0xc0000004;
  }
  else {
    piVar2 = *(int **)(param_2 + 0x18);
    if (*piVar2 == 0x28) {
      if ((*(char *)((longlong)piVar2 + 6) == '\0') && (*(char *)((longlong)piVar2 + 7) == '\0')) {
        uVar7 = Feature_Partition_Manager_Passthrough__private_IsEnabledDeviceUsageNoInline();
        if ((((int)uVar7 != 0) &&
            (((*(byte *)(piVar2 + 4) & 0x40) != 0 && ((*(byte *)(piVar2 + 2) & 0x40) != 0)))) &&
           ((p_Var1[0x25c] != (_DEVICE_EXTENSION)0x0 ||
            (((*(int *)(p_Var1 + 0x250) != 0 || (*(int *)(p_Var1 + 0x254) != 0)) ||
             (*(int *)(p_Var1 + 600) != 0)))))) {
          return 0xc00000bb;
        }
        bVar5 = false;
        if ((*(byte *)(piVar2 + 4) & 1) != 0) {
          bVar5 = false;
          if ((*(byte *)(piVar2 + 2) & 1) == 0) {
            bVar5 = true;
          }
        }
        KeWaitForSingleObject(p_Var1 + 0x38,0,0,0,0);
        uVar7 = *(ulonglong *)(piVar2 + 4);
        uVar3 = *(ulonglong *)(p_Var1 + 0x210);
        uVar4 = *(ulonglong *)(piVar2 + 2);
        while( true ) {
          p_Var9 = (_DRIVE_LAYOUT_INFORMATION_EX *)0x0;
          uVar6 = PmSetDiskAttributes(p_Var1,(longlong)piVar2,1);
          if ((int)uVar6 < 0) break;
          if ((uVar4 & uVar7) != (uVar3 & uVar7)) {
            PmInvalidatePartitionTableCache((longlong)p_Var1);
          }
          uVar8 = Feature_Partition_Manager_Passthrough__private_IsEnabledDeviceUsageNoInline();
          if ((((int)uVar8 != 0) && (((byte)p_Var1[0x210] & 0x40) != 0)) ||
             (*(int *)(p_Var1 + 0x204) != 0)) break;
          uVar6 = PmGetDriveLayoutEx(p_Var1,&local_res8);
          p_Var9 = local_res8;
          if ((((int)uVar6 < 0) || (!bVar5)) || (*(int *)(p_Var1 + 0x204) == 0)) break;
          if (1 < *(int *)(p_Var1 + 0x204) - 3U) {
            uVar6 = 0xc0000010;
            break;
          }
          uVar6 = PmUpdateIds(p_Var1,local_res8);
          if ((int)uVar6 < 0) break;
          ExFreePoolWithTag(p_Var9,0);
          local_res8 = (_DRIVE_LAYOUT_INFORMATION_EX *)0x0;
          bVar5 = false;
        }
        KeReleaseMutex(p_Var1 + 0x38,0);
      }
      else {
        uVar6 = 0xc000000d;
      }
      if (p_Var9 != (_DRIVE_LAYOUT_INFORMATION_EX *)0x0) {
        ExFreePoolWithTag(p_Var9,0);
      }
    }
    else {
      uVar6 = 0xc000000d;
    }
  }
  return uVar6;
}



===== PmIoctlSetDriveLayout @ 14001faf0 =====

uint PmIoctlSetDriveLayout(longlong param_1,longlong param_2)

{
  longlong lVar1;
  _DEVICE_EXTENSION *p_Var2;
  undefined8 uVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  SC_DISK_LAYOUT *pSVar7;
  SC_DISK_LAYOUT *pSVar8;
  uint *puVar9;
  uint uVar10;
  uint *puVar11;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  p_Var2 = *(_DEVICE_EXTENSION **)(param_1 + 0x40);
  uVar5 = *(uint *)(lVar1 + 0x10);
  if (7 < uVar5) {
    puVar11 = *(uint **)(param_2 + 0x18);
    uVar6 = (ulonglong)*puVar11 * 0x20;
    if (0xffffffff < uVar6) {
      return 0xc0000095;
    }
    uVar4 = (int)uVar6 + 8;
    uVar10 = 0xffffffff;
    if (uVar4 >= 8) {
      uVar10 = uVar4;
    }
    uVar4 = -(uint)(uVar4 < 8) & 0xc0000095;
    if ((int)uVar4 < 0) {
      return uVar4;
    }
    if (uVar10 <= uVar5) {
      uVar6 = (ulonglong)*puVar11 * 0x90;
      if (0xffffffff < uVar6) {
        return 0xc0000095;
      }
      uVar4 = (int)uVar6 + 0x30;
      uVar5 = 0xffffffff;
      if (uVar4 >= 0x30) {
        uVar5 = uVar4;
      }
      if (uVar4 < 0x30) {
        return -(uint)(uVar4 < 0x30) & 0xc0000095;
      }
      pSVar7 = (SC_DISK_LAYOUT *)ExAllocatePool2(0x42,uVar5,0x54506d50);
      if (pSVar7 == (SC_DISK_LAYOUT *)0x0) {
        return 0xc000009a;
      }
      uVar5 = *puVar11;
      *(undefined4 *)pSVar7 = 0;
      *(uint *)(pSVar7 + 4) = uVar5;
      *(uint *)(pSVar7 + 8) = puVar11[1];
      if (uVar5 != 0) {
        uVar6 = (ulonglong)uVar5;
        pSVar8 = pSVar7 + 0x40;
        puVar9 = puVar11 + 7;
        do {
          uVar3 = *(undefined8 *)(puVar9 + -5);
          *(undefined4 *)(pSVar8 + -0x10) = 0;
          *(undefined8 *)(pSVar8 + -8) = uVar3;
          *(undefined8 *)pSVar8 = *(undefined8 *)(puVar9 + -3);
          *(uint *)(pSVar8 + 8) = *puVar9;
          pSVar8[0xc] = *(SC_DISK_LAYOUT *)((longlong)puVar9 + 7);
          pSVar8[0x10] = *(SC_DISK_LAYOUT *)(puVar9 + 1);
          pSVar8[0x11] = *(SC_DISK_LAYOUT *)((longlong)puVar9 + 5);
          pSVar8[0x12] = *(SC_DISK_LAYOUT *)((longlong)puVar9 + 6);
          *(uint *)(pSVar8 + 0x14) = puVar9[-1];
          uVar6 = uVar6 - 1;
          pSVar8 = pSVar8 + 0x90;
          puVar9 = puVar9 + 8;
        } while (uVar6 != 0);
      }
      KeWaitForSingleObject(p_Var2 + 0x38,0,0,0,0);
      uVar5 = PmSetDriveLayoutEx(p_Var2,pSVar7);
      KeReleaseMutex(p_Var2 + 0x38,0);
      if (-1 < (int)uVar5) {
        if (*(uint *)(pSVar7 + 4) != 0) {
          puVar11 = puVar11 + 7;
          pSVar8 = pSVar7 + 0x48;
          uVar6 = (ulonglong)*(uint *)(pSVar7 + 4);
          do {
            uVar4 = *(uint *)pSVar8;
            pSVar8 = pSVar8 + 0x90;
            *puVar11 = uVar4;
            puVar11 = puVar11 + 8;
            uVar6 = uVar6 - 1;
          } while (uVar6 != 0);
        }
        uVar4 = *(uint *)(lVar1 + 8);
        if (uVar10 <= uVar4) {
          uVar4 = uVar10;
        }
        *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar4;
      }
      ExFreePoolWithTag(pSVar7,0);
      return uVar5;
    }
  }
  return 0xc0000004;
}



===== PmIoctlSetDriveLayoutEx @ 14001fce4 =====

uint PmIoctlSetDriveLayoutEx(longlong param_1,longlong param_2)

{
  longlong lVar1;
  _DEVICE_EXTENSION *p_Var2;
  SC_DISK_LAYOUT *pSVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  uint uVar7;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  p_Var2 = *(_DEVICE_EXTENSION **)(param_1 + 0x40);
  uVar5 = *(uint *)(lVar1 + 0x10);
  if (0x2f < uVar5) {
    pSVar3 = *(SC_DISK_LAYOUT **)(param_2 + 0x18);
    uVar6 = (ulonglong)*(uint *)(pSVar3 + 4) * 0x90;
    if (0xffffffff < uVar6) {
      return 0xc0000095;
    }
    uVar4 = (int)uVar6 + 0x30;
    uVar7 = 0xffffffff;
    if (uVar4 >= 0x30) {
      uVar7 = uVar4;
    }
    uVar4 = -(uint)(uVar4 < 0x30) & 0xc0000095;
    if ((int)uVar4 < 0) {
      return uVar4;
    }
    if (uVar7 <= uVar5) {
      KeWaitForSingleObject(p_Var2 + 0x38,0,0,0,0);
      uVar5 = PmSetDriveLayoutEx(p_Var2,pSVar3);
      KeReleaseMutex(p_Var2 + 0x38,0);
      if ((int)uVar5 < 0) {
        return uVar5;
      }
      uVar4 = *(uint *)(lVar1 + 8);
      if (uVar7 <= uVar4) {
        uVar4 = uVar7;
      }
      *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar4;
      return uVar5;
    }
  }
  return 0xc0000004;
}



===== PmIoctlSetSanSettings @ 14001fdd0 =====

int PmIoctlSetSanSettings(longlong param_1,longlong param_2)

{
  longlong lVar1;
  bool bVar2;
  int iVar3;
  ulonglong uVar4;
  int *piVar5;
  longlong local_res8;
  
  local_res8 = 0;
  bVar2 = false;
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10) < 8) {
    iVar3 = -0x3ffffffc;
  }
  else if (**(int **)(param_2 + 0x18) == 8) {
    piVar5 = *(int **)(param_2 + 0x18) + 1;
    if (*piVar5 - 1U < 5) {
      uVar4 = Feature_Partition_Manager_Passthrough__private_IsEnabledDeviceUsageNoInline();
      if (((int)uVar4 == 0) && (*piVar5 == 5)) {
        iVar3 = -0x3fffff45;
      }
      else {
        KeWaitForSingleObject(lVar1 + 0x10,0,0,0,0);
        bVar2 = true;
        iVar3 = IoOpenDriverRegistryKey(*(undefined8 *)(lVar1 + 8),1,2,0,&local_res8);
        if (-1 < iVar3) {
          iVar3 = ZwSetValueKey(local_res8,&SanPolicy,0,4,piVar5,4);
          if (-1 < iVar3) {
            *(int *)(lVar1 + 0xa0) = *piVar5;
          }
        }
      }
    }
    else {
      iVar3 = -0x3ffffff3;
    }
    if (local_res8 != 0) {
      ZwClose();
    }
    if (bVar2) {
      KeReleaseMutex(lVar1 + 0x10,0);
    }
  }
  else {
    iVar3 = -0x3ffffff3;
  }
  return iVar3;
}



===== PmIoctlSetSnapshotInfo @ 14001ff20 =====

uint PmIoctlSetSnapshotInfo(longlong param_1,longlong param_2)

{
  _DEVICE_EXTENSION *p_Var1;
  int *piVar2;
  uint uVar3;
  
  p_Var1 = *(_DEVICE_EXTENSION **)(param_1 + 0x40);
  uVar3 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10);
  if (0x4b < uVar3) {
    piVar2 = *(int **)(param_2 + 0x18);
    if (piVar2[0x12] + 0x4cU < 0x4c) {
      return 0xc0000095;
    }
    if (piVar2[0x12] + 0x4cU <= uVar3) {
      if ((*piVar2 == 0x50) && ((uint)piVar2[1] < 4)) {
        KeWaitForSingleObject(p_Var1 + 0x38,0,0,0,0);
        uVar3 = PmSetSnapshotInfo(p_Var1,(longlong)piVar2);
        KeReleaseMutex(p_Var1 + 0x38,0);
        return uVar3;
      }
      return 0xc000000d;
    }
  }
  return 0xc0000004;
}



===== PmIoctlUpdateDriveSize @ 14001ffcc =====

int PmIoctlUpdateDriveSize(longlong param_1,longlong param_2)

{
  int iVar1;
  _DEVICE_EXTENSION *p_Var2;
  
  p_Var2 = *(_DEVICE_EXTENSION **)(param_1 + 0x40);
  IoForwardIrpSynchronously(*(undefined8 *)(p_Var2 + 0x10));
  iVar1 = *(int *)(param_2 + 0x30);
  if (-1 < iVar1) {
    KeWaitForSingleObject(p_Var2 + 0x38,0,0,0,0);
    PmInvalidatePartitionTableCache((longlong)p_Var2);
    PmGetDriveLayoutEx(p_Var2,(undefined8 *)0x0);
    KeReleaseMutex(p_Var2 + 0x38,0);
  }
  return iVar1;
}



===== PmIoctlUpdateProperties @ 140020054 =====

undefined8 PmIoctlUpdateProperties(longlong param_1)

{
  _DEVICE_EXTENSION *p_Var1;
  
  p_Var1 = *(_DEVICE_EXTENSION **)(param_1 + 0x40);
  KeWaitForSingleObject(p_Var1 + 0x38,0,0,0,0);
  PmInvalidatePartitionTableCache((longlong)p_Var1);
  PmGetDriveLayoutEx(p_Var1,(undefined8 *)0x0);
  KeReleaseMutex(p_Var1 + 0x38,0);
  return 0;
}



===== PmAddDevice @ 1400200c0 =====

/* long __cdecl PmAddDevice(struct _DRIVER_OBJECT * __ptr64,struct _DEVICE_OBJECT * __ptr64) */

long __cdecl PmAddDevice(_DRIVER_OBJECT *param_1,_DEVICE_OBJECT *param_2)

{
  undefined8 *puVar1;
  longlong *plVar2;
  longlong lVar3;
  code *pcVar4;
  int iVar5;
  longlong lVar6;
  longlong *plVar7;
  undefined8 *_Dst;
  undefined1 *puVar8;
  char *pcVar9;
  longlong local_res18;
  char *local_res20;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [24];
  undefined8 local_48;
  undefined1 local_40;
  longlong *local_38;
  
  _Dst = (undefined8 *)0x0;
  local_res18 = 0;
  lVar3 = *(longlong *)(PmControlObject + 0x40);
  local_res20 = (char *)0x0;
  iVar5 = PmGetDevicePropertyData(param_2,&DEVPKEY_Storage_No_Partitions,(longlong *)&local_res20);
  pcVar9 = local_res20;
  puVar8 = auStack_68;
  if (((iVar5 < 0) || (local_res20 == (char *)0x0)) || (*local_res20 != -1)) {
    local_38 = &local_res18;
    local_40 = 0;
    local_48 = CONCAT44(local_48._4_4_,0x100);
    iVar5 = IoCreateDevice(param_1,0x480,0,0x2d);
    if (iVar5 < 0) {
      local_res18 = 0;
    }
    else {
      _Dst = *(undefined8 **)(local_res18 + 0x40);
      memset(_Dst,0,0x480);
      lVar6 = IoAttachDeviceToDeviceStack(local_res18,param_2);
      _Dst[2] = lVar6;
      if (lVar6 == 0) {
        iVar5 = -0x3ffffff2;
      }
      else {
        *_Dst = &PmFilterDispatch;
        _Dst[1] = local_res18;
        _Dst[3] = param_2;
        KeInitializeMutex(_Dst + 7,0);
        KeInitializeSpinLock(_Dst + 0xe);
        local_48 = CONCAT44(local_48._4_4_,0x20);
        IoInitializeRemoveLockEx(_Dst + 0xf,0x4c526d50,10,0);
        puVar1 = _Dst + 0x4d;
        _Dst[0x4e] = puVar1;
        plVar2 = _Dst + 0x13;
        *puVar1 = puVar1;
        puVar1 = _Dst + 0x4f;
        _Dst[0x14] = plVar2;
        _Dst[0x50] = puVar1;
        *puVar1 = puVar1;
        puVar1 = _Dst + 0x52;
        _Dst[0x53] = puVar1;
        *puVar1 = puVar1;
        puVar1 = _Dst + 0x54;
        _Dst[0x55] = puVar1;
        *puVar1 = puVar1;
        puVar1 = _Dst + 0x56;
        _Dst[0x57] = puVar1;
        *puVar1 = puVar1;
        *plVar2 = (longlong)plVar2;
        KeInitializeEvent(_Dst + 0x67,0,0);
        puVar1 = _Dst + 0x70;
        *(undefined4 *)(_Dst + 0x5b) = 1;
        _Dst[0x71] = puVar1;
        *puVar1 = puVar1;
        puVar1 = _Dst + 0x6c;
        _Dst[0x6d] = puVar1;
        *puVar1 = puVar1;
        _Dst[0x5c] = &PmGuidList;
        _Dst[0x5d] = PmQueryWmiRegInfo;
        _Dst[0x5e] = PmQueryWmiDataBlock;
        _Dst[0x62] = PmWmiFunctionControl;
        lVar6 = IoAllocateWorkItem(local_res18);
        _Dst[0x6f] = lVar6;
        if (lVar6 != 0) {
          lVar6 = IoAllocateWorkItem(local_res18);
          _Dst[0x6a] = lVar6;
          if (lVar6 != 0) {
            lVar6 = IoAllocateIrp(5);
            _Dst[0x6b] = lVar6;
            if (lVar6 != 0) {
              *(uint *)(_Dst + 0x40) = *(uint *)(_Dst + 0x40) | 8;
              _Dst[0x42] = _Dst[0x42] | 1;
              *(undefined4 *)((longlong)_Dst + 0x204) = 0;
              *(undefined4 *)(_Dst + 0x33) = 0xffffffff;
              *(undefined4 *)((longlong)_Dst + 0x19c) = 0xffffffff;
              *(undefined4 *)(_Dst + 0x36) = 0xffffffff;
              *(undefined4 *)((longlong)_Dst + 0x1b4) = 0xffffffff;
              *(undefined4 *)(_Dst + 0x37) = 0xffffffff;
              *(undefined4 *)(_Dst + 0x34) = 0xffffffff;
              *(undefined4 *)((longlong)_Dst + 0x1a4) = 0xffffffff;
              *(undefined4 *)(_Dst + 0x35) = 0xffffffff;
              *(undefined4 *)((longlong)_Dst + 0x1ac) = 0xffffffff;
              *(undefined1 *)((longlong)_Dst + 0x20c) = 1;
              *(undefined4 *)(_Dst + 0x46) = 0x20;
              *(undefined4 *)(local_res18 + 0x48) = *(undefined4 *)(_Dst[2] + 0x48);
              *(uint *)(local_res18 + 0x30) = *(uint *)(local_res18 + 0x30) | 0x10;
              local_48 = 0;
              *(uint *)(local_res18 + 0x30) =
                   (-(uint)((*(uint *)(_Dst[2] + 0x30) & 0x4000) != 0) & 0x2000) + 0x2000 |
                   *(uint *)(local_res18 + 0x30);
              KeWaitForSingleObject(lVar3 + 0x10,0,0,0);
              puVar8 = auStack_68;
              lVar6 = lVar3 + 0x58;
              plVar7 = *(longlong **)(lVar3 + 0x60);
              if (*plVar7 != lVar6) {
                plVar7 = (longlong *)0x3;
                pcVar4 = (code *)swi(0x29);
                lVar6 = (*pcVar4)();
                puVar8 = auStack_60;
              }
              _Dst[0x14] = plVar7;
              *plVar2 = lVar6;
              *plVar7 = (longlong)plVar2;
              *(longlong **)(lVar6 + 8) = plVar2;
              *(undefined8 *)(puVar8 + -8) = 0x140020496;
              KeReleaseMutex(lVar3 + 0x10,0);
              *(uint *)(local_res18 + 0x30) = *(uint *)(local_res18 + 0x30) & 0xffffff7f;
              pcVar9 = local_res20;
              goto LAB_1400204b1;
            }
          }
        }
        iVar5 = -0x3fffff66;
      }
    }
    puVar8 = auStack_68;
    if (local_res18 != 0) {
      if (_Dst[0x6b] != 0) {
        IoFreeIrp();
      }
      if (_Dst[0x6a] != 0) {
        IoFreeWorkItem();
      }
      if (_Dst[0x6f] != 0) {
        IoFreeWorkItem();
      }
      if (_Dst[2] != 0) {
        IoDetachDevice();
      }
      IoDeleteDevice(local_res18);
      puVar8 = auStack_68;
    }
  }
LAB_1400204b1:
  if (pcVar9 != (char *)0x0) {
    *(undefined8 *)(puVar8 + -8) = 0x1400204c2;
    ExFreePoolWithTag(pcVar9,0);
  }
  return iVar5;
}



===== PmApplyServiceProtection @ 1400204e8 =====

/* long __cdecl PmApplyServiceProtection(struct _DEVICE_EXTENSION * __ptr64) */

long __cdecl PmApplyServiceProtection(_DEVICE_EXTENSION *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  iVar1 = RtlLengthSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0x210));
  iVar2 = RtlLengthSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0x110));
  iVar3 = RtlLengthSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0x108));
  iVar1 = iVar1 + iVar2 + iVar3 + 0x20;
  lVar4 = ExAllocatePool2(0x102,iVar1,0x43416d50);
  if (lVar4 == 0) {
    iVar1 = -0x3fffff66;
  }
  else {
    iVar1 = RtlCreateAcl(lVar4,iVar1,2);
    if (-1 < iVar1) {
      iVar1 = RtlAddAccessAllowedAce
                        (lVar4,2,0x80000000,*(undefined8 *)(*(longlong *)SeExports_exref + 0x108));
      if (-1 < iVar1) {
        iVar1 = RtlAddAccessAllowedAce
                          (lVar4,2,0x80000000,*(undefined8 *)(*(longlong *)SeExports_exref + 0x210))
        ;
        if (-1 < iVar1) {
          iVar1 = RtlAddAccessAllowedAce
                            (lVar4,2,0x80000000,
                             *(undefined8 *)(*(longlong *)SeExports_exref + 0x110));
          if (-1 < iVar1) {
            iVar1 = RtlLengthSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0x218));
            lVar5 = ExAllocatePool2(0x102,iVar1 + 0x10,0x43416d50);
            if (lVar5 == 0) {
              iVar1 = -0x3fffff66;
            }
            else {
              iVar1 = RtlCreateAcl(lVar5,iVar1 + 0x10,2);
              if (-1 < iVar1) {
                iVar1 = RtlAddProcessTrustLabelAce
                                  (lVar5,2,0,*(undefined8 *)(*(longlong *)SeExports_exref + 0x218),
                                   0x14,0x120089);
                if (-1 < iVar1) {
                  iVar1 = RtlCreateSecurityDescriptor(&local_38,1);
                  if (-1 < iVar1) {
                    iVar1 = RtlSetDaclSecurityDescriptor(&local_38,1,lVar4,0);
                    if (-1 < iVar1) {
                      iVar1 = RtlSetSaclSecurityDescriptor(&local_38,1,lVar5,0);
                      if (-1 < iVar1) {
                        iVar1 = ObSetSecurityObjectByPointer
                                          (*(undefined8 *)(param_1 + 8),0x84,&local_38);
                        *(uint *)(*(longlong *)(param_1 + 8) + 0x34) =
                             *(uint *)(*(longlong *)(param_1 + 8) + 0x34) | 0x100;
                      }
                    }
                  }
                }
              }
              ExFreePoolWithTag(lVar5,0);
            }
          }
        }
      }
    }
    ExFreePoolWithTag(lVar4,0);
  }
  return iVar1;
}



===== PmClose @ 1400207d0 =====

/* long __cdecl PmClose(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl PmClose(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== PmConstructDeviceLocationDefault @ 1400207f8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl PmConstructDeviceLocationDefault(struct _DEVICE_EXTENSION * __ptr64) */

long __cdecl PmConstructDeviceLocationDefault(_DEVICE_EXTENSION *param_1)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  short *psVar4;
  undefined8 uVar5;
  long lVar6;
  undefined1 auStack_258 [32];
  int local_238;
  int local_230;
  wchar_t local_228;
  undefined1 local_226 [254];
  short local_128;
  undefined1 local_126 [254];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_258;
  lVar6 = 0;
  local_228 = L'\0';
  memset(local_226,0,0xfe);
  local_128 = 0;
  memset(local_126,0,0xfe);
  uVar5 = 0x100;
  if (*(uint *)(param_1 + 0x19c) == 0xffffffff) {
    RtlStringCbPrintfW(&local_228,0x100,L"Integrated",0xffffffff);
  }
  else {
    RtlStringCbPrintfW(&local_228,0x100,L"PCI Slot %u",(ulonglong)*(uint *)(param_1 + 0x19c));
  }
  RtlStringCbCatW(&local_128,uVar5,(longlong)&local_228);
  if (((*(uint *)(param_1 + 0x1b0) != 0xffffffff) && (*(int *)(param_1 + 0x1b4) != -1)) &&
     (*(int *)(param_1 + 0x1b8) != -1)) {
    uVar5 = 0x100;
    local_238 = *(int *)(param_1 + 0x1b4);
    local_230 = *(int *)(param_1 + 0x1b8);
    RtlStringCbPrintfW(&local_228,0x100,L" : Bus %u : Device %u : Function %u",
                       (ulonglong)*(uint *)(param_1 + 0x1b0));
    RtlStringCbCatW(&local_128,uVar5,(longlong)&local_228);
  }
  uVar5 = 0x100;
  RtlStringCbPrintfW(&local_228,0x100,L" : Adapter %u",(ulonglong)*(uint *)(param_1 + 0x1a0));
  RtlStringCbCatW(&local_128,uVar5,(longlong)&local_228);
  iVar1 = *(int *)(*(longlong *)(param_1 + 0xe8) + 0x1c);
  if (iVar1 < 7) {
    if ((iVar1 != 6) && (iVar1 != 1)) {
      if ((iVar1 == 2) || (iVar1 == 3)) {
        local_238 = *(int *)(param_1 + 0x1ac);
        uVar5 = 0x100;
        RtlStringCbPrintfW(&local_228,0x100,L" : Channel %u : Device %u",
                           (ulonglong)*(uint *)(param_1 + 0x1a8));
        goto LAB_1400209c7;
      }
      if ((iVar1 != 4) && (iVar1 != 5)) {
LAB_1400209a5:
        local_228 = L'\0';
        goto LAB_1400209c7;
      }
    }
LAB_140020939:
    local_230 = *(int *)(param_1 + 0x1ac);
    uVar5 = 0x100;
    local_238 = *(int *)(param_1 + 0x1a8);
    RtlStringCbPrintfW(&local_228,0x100,L" : Port %u : Target %u : LUN %u",
                       (ulonglong)*(uint *)(param_1 + 0x1a4));
  }
  else {
    if (iVar1 != 7) {
      if ((iVar1 == 8) || (iVar1 == 10)) goto LAB_140020939;
      if (iVar1 != 0xb) goto LAB_1400209a5;
    }
    uVar5 = 0x100;
    RtlStringCbPrintfW(&local_228,0x100,L" : Port %u",(ulonglong)*(uint *)(param_1 + 0x1a4));
  }
LAB_1400209c7:
  RtlStringCbCatW(&local_128,uVar5,(longlong)&local_228);
  lVar3 = -1;
  do {
    lVar3 = lVar3 + 1;
  } while (*(short *)(local_226 + lVar3 * 2 + 0xfe) != 0);
  uVar2 = (int)lVar3 * 2 + 2;
  psVar4 = (short *)ExAllocatePool2(0x42,uVar2,0x42496d50);
  if (psVar4 == (short *)0x0) {
    lVar6 = -0x3fffff66;
  }
  else {
    RtlStringCbCopyW(psVar4,(ulonglong)uVar2,(longlong)&local_128);
    RtlInitUnicodeString(param_1 + 0x1c0,psVar4);
  }
  return lVar6;
}



===== PmConstructDeviceLocationNetworkStorage @ 140020a6c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl PmConstructDeviceLocationNetworkStorage(struct _DEVICE_EXTENSION * __ptr64) */

long __cdecl PmConstructDeviceLocationNetworkStorage(_DEVICE_EXTENSION *param_1)

{
  uint uVar1;
  longlong lVar2;
  short *psVar3;
  long lVar4;
  undefined1 auStack_138 [32];
  wchar_t local_118;
  undefined1 local_116 [254];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_138;
  lVar4 = 0;
  local_118 = L'\0';
  memset(local_116,0,0xfe);
  RtlStringCbPrintfW(&local_118,0x100,L"Network storage on Adapter %u",
                     (ulonglong)*(uint *)(param_1 + 0x1a0));
  lVar2 = -1;
  do {
    lVar2 = lVar2 + 1;
  } while (*(short *)(auStack_138 + lVar2 * 2 + 0x20) != 0);
  uVar1 = (int)lVar2 * 2 + 2;
  psVar3 = (short *)ExAllocatePool2(0x42,uVar1,0x42496d50);
  if (psVar3 == (short *)0x0) {
    lVar4 = -0x3fffff66;
  }
  else {
    RtlStringCbCopyW(psVar3,(ulonglong)uVar1,(longlong)&local_118);
    RtlInitUnicodeString(param_1 + 0x1c0,psVar3);
  }
  return lVar4;
}



===== PmConstructDeviceLocationVhd @ 140020b60 =====

/* long __cdecl PmConstructDeviceLocationVhd(struct _DEVICE_EXTENSION * __ptr64) */

long __cdecl PmConstructDeviceLocationVhd(_DEVICE_EXTENSION *param_1)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  int iVar4;
  
  iVar4 = 0x40;
  while( true ) {
    lVar2 = ExAllocatePool2(0x42,iVar4);
    if (lVar2 == 0) {
      return -0x3fffff66;
    }
    uVar3 = PmSendDeviceControl(*(undefined8 *)(param_1 + 0x10),0x2d5928,0,0,lVar2,iVar4,0);
    iVar1 = (int)uVar3;
    if (-1 < iVar1) break;
    if (iVar1 != -0x3fffffdd) {
      ExFreePoolWithTag(lVar2,0);
      return iVar1;
    }
    iVar4 = iVar4 + 0x40;
    ExFreePoolWithTag();
  }
  RtlInitUnicodeString(param_1 + 0x1c0,lVar2);
  return iVar1;
}



===== PmCreate @ 140020c30 =====

/* long __cdecl PmCreate(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl PmCreate(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  uint uVar1;
  
  uVar1 = -(uint)((*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10) & 1) != 0) & 0xc0000103;
  *(uint *)(param_2 + 0x30) = uVar1;
  IofCompleteRequest(param_2,0);
  return uVar1;
}



===== PmGetDeviceParameterBinaryCallback @ 140020c80 =====

/* long __cdecl PmGetDeviceParameterBinaryCallback(unsigned short * __ptr64,unsigned long,void *
   __ptr64,unsigned long,void * __ptr64,void * __ptr64) */

long __cdecl
PmGetDeviceParameterBinaryCallback
          (ushort *param_1,ulong param_2,void *param_3,ulong param_4,void *param_5,void *param_6)

{
  void *_Dst;
  long lVar1;
  
  lVar1 = 0;
  _Dst = (void *)ExAllocatePool2(0x42,param_4,0x42496d50);
  if (_Dst == (void *)0x0) {
    lVar1 = -0x3fffff66;
  }
  else {
    memmove(_Dst,param_3,(ulonglong)param_4);
    *(ulong *)param_5 = param_4;
    *(void **)param_6 = _Dst;
  }
  return lVar1;
}



===== PmGetDevicePropertyString @ 140020d0c =====

/* long __cdecl PmGetDevicePropertyString(struct _DEVICE_OBJECT * __ptr64,struct _DEVPROPKEY const *
   __ptr64,struct _UNICODE_STRING * __ptr64) */

long __cdecl
PmGetDevicePropertyString(_DEVICE_OBJECT *param_1,_DEVPROPKEY *param_2,_UNICODE_STRING *param_3)

{
  int iVar1;
  longlong lVar2;
  longlong local_res20;
  
  local_res20 = 0;
  iVar1 = PmGetDevicePropertyData(param_1,param_2,&local_res20);
  if (iVar1 < 0) {
    lVar2 = local_res20;
  }
  else {
    RtlInitUnicodeString(param_3,local_res20);
    lVar2 = 0;
  }
  if (lVar2 != 0) {
    ExFreePoolWithTag(lVar2,0);
  }
  return iVar1;
}



===== PmGetFirmwareInfo @ 140020d74 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl PmGetFirmwareInfo(struct _DEVICE_EXTENSION * __ptr64,enum _STORAGE_BUS_TYPE,struct
   _STORAGE_HW_FIRMWARE_INFO * __ptr64 * __ptr64) */

long __cdecl
PmGetFirmwareInfo(_DEVICE_EXTENSION *param_1,_STORAGE_BUS_TYPE param_2,
                 _STORAGE_HW_FIRMWARE_INFO **param_3)

{
  int iVar1;
  ulonglong uVar2;
  _STORAGE_HW_FIRMWARE_INFO *p_Var3;
  uint uVar4;
  undefined1 auStackY_b8 [32];
  undefined4 local_78;
  undefined4 local_74;
  ulonglong local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_38 = 0;
  local_78 = 0x10;
  local_74 = 0x10;
  local_70 = (ulonglong)(param_2 == 0x11);
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  uVar2 = PmSendDeviceControl(*(undefined8 *)(param_1 + 0x10),0x2d1c00,&local_78,0x10,&local_68,0x38
                              ,0);
  iVar1 = (int)uVar2;
  if (((iVar1 + 0x80000000U & 0x80000000) != 0) || (iVar1 == -0x7ffffffb)) {
    if ((int)local_68 == 0x38) {
      uVar4 = 0x38;
      if (0x38 < local_68._4_4_) {
        uVar4 = local_68._4_4_;
      }
      p_Var3 = (_STORAGE_HW_FIRMWARE_INFO *)ExAllocatePool2(0x40,uVar4,0x42496d50);
      if (p_Var3 == (_STORAGE_HW_FIRMWARE_INFO *)0x0) {
        iVar1 = -0x3fffff66;
      }
      else {
        uVar2 = PmSendDeviceControl(*(undefined8 *)(param_1 + 0x10),0x2d1c00,&local_78,local_74,
                                    p_Var3,uVar4,0);
        iVar1 = (int)uVar2;
        if (-1 < iVar1) {
          if ((*(int *)p_Var3 == 0x38) && (*(uint *)(p_Var3 + 4) == uVar4)) {
            if (*param_3 != (_STORAGE_HW_FIRMWARE_INFO *)0x0) {
              ExFreePoolWithTag(*param_3,0);
            }
            *param_3 = p_Var3;
            return iVar1;
          }
          iVar1 = -0x3ffffffc;
        }
        ExFreePoolWithTag(p_Var3,0);
      }
    }
    else {
      iVar1 = -0x3ffffffc;
    }
  }
  return iVar1;
}



===== PmGetHybridInfo @ 140020ee8 =====

/* long __cdecl PmGetHybridInfo(struct _DEVICE_EXTENSION * __ptr64,struct _SRB_IO_CONTROL_HYBRID *
   __ptr64 * __ptr64) */

long __cdecl PmGetHybridInfo(_DEVICE_EXTENSION *param_1,_SRB_IO_CONTROL_HYBRID **param_2)

{
  int iVar1;
  _SRB_IO_CONTROL_HYBRID *p_Var2;
  ulonglong uVar3;
  int iVar4;
  
  iVar4 = 0x98;
  while( true ) {
    p_Var2 = (_SRB_IO_CONTROL_HYBRID *)ExAllocatePool2(0x40,iVar4,0x42496d50);
    if (p_Var2 == (_SRB_IO_CONTROL_HYBRID *)0x0) {
      return -0x3fffff66;
    }
    *(undefined4 *)p_Var2 = 0x1c;
    *(undefined8 *)(p_Var2 + 4) = 0x4b53494452425948;
    *(undefined4 *)(p_Var2 + 0xc) = 0x1e;
    *(int *)(p_Var2 + 0x30) = iVar4 + -0x40;
    *(undefined4 *)(p_Var2 + 0x10) = 0x1b0620;
    *(int *)(p_Var2 + 0x18) = iVar4 + -0x1c;
    *(undefined4 *)(p_Var2 + 0x1c) = 1;
    *(undefined4 *)(p_Var2 + 0x20) = 0x18;
    *(undefined4 *)(p_Var2 + 0x24) = 1;
    *(undefined4 *)(p_Var2 + 0x2c) = 0x40;
    uVar3 = PmSendDeviceControl(*(undefined8 *)(param_1 + 0x10),0x4d008,p_Var2,iVar4,p_Var2,iVar4,0)
    ;
    iVar1 = (int)uVar3;
    if (-1 < iVar1) break;
    if ((iVar1 != -0x3fffffdd) && (iVar1 != -0x7ffffffb)) {
      ExFreePoolWithTag(p_Var2,0);
      return iVar1;
    }
    iVar4 = iVar4 * 2;
    ExFreePoolWithTag(p_Var2,0);
  }
  if (*param_2 != (_SRB_IO_CONTROL_HYBRID *)0x0) {
    ExFreePoolWithTag(*param_2,0);
  }
  *param_2 = p_Var2;
  return iVar1;
}



===== PmSurpriseRemoval @ 140021020 =====

/* long __cdecl PmSurpriseRemoval(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl PmSurpriseRemoval(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  long lVar1;
  _DEVICE_EXTENSION *p_Var2;
  
  p_Var2 = *(_DEVICE_EXTENSION **)(param_1 + 0x40);
  IoForwardIrpSynchronously(*(undefined8 *)(p_Var2 + 0x10));
  lVar1 = *(long *)(param_2 + 0x30);
  PmRemoveHelper(p_Var2);
  IofCompleteRequest(param_2,0);
  return lVar1;
}



===== PmUnload @ 140021080 =====

/* void __cdecl PmUnload(struct _DRIVER_OBJECT * __ptr64) */

void __cdecl PmUnload(_DRIVER_OBJECT *param_1)

{
  longlong lVar1;
  longlong *plVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  if (PmControlObject != 0) {
    lVar1 = *(longlong *)(PmControlObject + 0x40);
    if (*(longlong *)(lVar1 + 0x198) != 0) {
      IoUnregisterPlugPlayNotification();
    }
    lVar4 = lVar1 + 0x10;
    KeWaitForSingleObject(lVar4,0,0,0,0);
    while (plVar2 = *(longlong **)(lVar1 + 0x48), plVar2 != (longlong *)(lVar1 + 0x48)) {
      PmVolumeManagerRemoval(lVar4,plVar2);
    }
    KeReleaseMutex(lVar1 + 0x10,0);
    if (*(longlong *)(lVar1 + 0x1a8) != 0) {
      ExFreePoolWithTag(*(longlong *)(lVar1 + 0x1a8),0);
    }
    RtlInitUnicodeString(&local_18,L"\\DosDevices\\PartmgrControl");
    IoDeleteSymbolicLink(&local_18);
    if (*(longlong *)(lVar1 + 0xc0) != 0) {
      ExFreePoolWithTag(*(longlong *)(lVar1 + 0xc0),0);
    }
    IoDeleteDevice(PmControlObject);
    PmControlObject = 0;
  }
  McGenEventUnregister_EtwUnregister();
  uVar3 = DAT_140019088;
  DAT_140019088 = 0;
  DAT_140019068 = 0;
  EtwUnregister(uVar3);
  if (g_wil_details_featureChangeNotification != 0) {
    RtlUnregisterFeatureConfigurationChangeNotification();
    g_wil_details_featureChangeNotification = 0;
  }
  if (g_wil_details_featureUsageProvider != 0) {
    RtlUnregisterFeatureUsageProvider();
    g_wil_details_featureUsageProvider = 0;
  }
  g_wil_details_isFeatureStagingInitialized = 0;
  return;
}



===== PmWmiFunctionControl @ 140021210 =====

/* long __cdecl PmWmiFunctionControl(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64,unsigned
   long,enum _WMIENABLEDISABLECONTROL,unsigned char) */

long __cdecl
PmWmiFunctionControl
          (_DEVICE_OBJECT *param_1,_IRP *param_2,ulong param_3,_WMIENABLEDISABLECONTROL param_4,
          uchar param_5)

{
  longlong lVar1;
  byte bVar2;
  long lVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  uVar5 = 0;
  if ((param_3 == 0) && (*(int *)(lVar1 + 0xa8) != -1)) {
    if (param_4 == 1) {
      if (param_5 == '\0') {
        uVar4 = PmWmiCounterDisable((longlong *)(lVar1 + 0x2d0),'\0','\0');
        bVar2 = (byte)uVar4;
        uVar5 = 0;
      }
      else {
        uVar4 = PmWmiCounterEnable((longlong *)(lVar1 + 0x2d0));
        bVar2 = (byte)((ulonglong)uVar4 >> 0x18) >> 7 ^ 1;
        uVar5 = (int)uVar4;
      }
      *(byte *)(lVar1 + 0x2c0) = bVar2;
    }
  }
  else {
    uVar5 = 0xc0000295;
  }
  lVar3 = WmiCompleteRequest(param_1,param_2,uVar5,0,0);
  return lVar3;
}



===== PmDriverReinitialization @ 1400212b0 =====

void PmDriverReinitialization(void)

{
  *(undefined1 *)(*(longlong *)(PmControlObject + 0x40) + 0xa9) = 0;
  return;
}



===== PmEtwControlComplete @ 1400212cc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PmEtwControlComplete(longlong param_1,longlong param_2,undefined1 param_3)

{
  longlong lVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined1 auStackY_58 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_58;
  lVar1 = *(longlong *)(param_2 + 0xb8);
  puVar3 = &local_28;
  local_28 = 0;
  uStack_20 = 0;
  iVar2 = IoGetActivityIdIrp();
  if ((-1 < iVar2) && ((Microsoft_Windows_PartitionEnableBits & 1) != 0)) {
    McTemplateK0qqq_EtwWriteTransfer
              (param_2,puVar3,&local_28,*(undefined4 *)(param_1 + 0xa8),
               (char)*(undefined4 *)(lVar1 + 0x18),param_3);
  }
  return;
}



===== PmEtwControlStart @ 140021364 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PmEtwControlStart(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  undefined1 auStack_58 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  lVar1 = *(longlong *)(param_2 + 0xb8);
  local_28 = 0;
  uStack_20 = 0;
  iVar2 = IoGetActivityIdIrp(param_2,&local_28);
  if ((-1 < iVar2) && ((Microsoft_Windows_PartitionEnableBits & 1) != 0)) {
    McTemplateK0qq_EtwWriteTransfer
              (param_2,&ControlStart,&local_28,*(undefined4 *)(param_1 + 0xa8),
               (char)*(undefined4 *)(lVar1 + 0x18));
  }
  return;
}



===== PmGetDeviceParameterBinary @ 1400213f4 =====

long PmGetDeviceParameterBinary
               (_DEVICE_EXTENSION *param_1,undefined8 param_2,undefined8 *param_3,
               undefined4 *param_4)

{
  void *pvVar1;
  long lVar2;
  void *local_res18 [2];
  code *local_88;
  undefined4 local_80 [2];
  undefined8 local_78;
  undefined8 *local_70;
  undefined4 local_68;
  
  local_res18[0] = (void *)0x0;
  local_88 = (code *)0x0;
  memset(local_80,0,0x68);
  *param_3 = 0;
  *param_4 = 0;
  lVar2 = PmOpenDeviceParameter(param_1,local_res18);
  pvVar1 = local_res18[0];
  if (-1 < lVar2) {
    local_88 = PmGetDeviceParameterBinaryCallback;
    local_80[0] = 0x104;
    local_68 = 0x3000000;
    local_78 = param_2;
    local_70 = param_3;
    lVar2 = RtlQueryRegistryValuesEx(0x40000000,local_res18[0],&local_88,param_4,0);
  }
  if (pvVar1 != (void *)0x0) {
    ZwClose(pvVar1);
  }
  return lVar2;
}



===== PmGetParameter @ 1400214d4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 PmGetParameter(undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  undefined8 uVar1;
  undefined1 auStack_58 [32];
  undefined4 local_38;
  undefined4 *local_30;
  undefined4 local_28 [2];
  undefined1 local_20 [4];
  int local_1c;
  int local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  *param_3 = 0;
  local_30 = local_28;
  local_28[0] = 0;
  local_38 = 0x10;
  uVar1 = ZwQueryValueKey(param_1,param_2,2,local_20);
  if (-1 < (int)uVar1) {
    if ((local_1c == 4) && (local_18 == 4)) {
      *param_3 = local_14;
    }
    else {
      uVar1 = 0xc0000024;
    }
  }
  return uVar1;
}



===== PmSetDeviceParameter @ 140021558 =====

long PmSetDeviceParameter(_DEVICE_EXTENSION *param_1,undefined8 param_2,undefined4 param_3)

{
  long lVar1;
  void *local_res10;
  undefined4 local_res18 [4];
  
  local_res10 = (void *)0x0;
  local_res18[0] = param_3;
  lVar1 = PmOpenDeviceParameter(param_1,&local_res10);
  if (-1 < lVar1) {
    lVar1 = RtlWriteRegistryValue(0x40000000,local_res10,L"Attributes",4,local_res18,4);
  }
  if (local_res10 != (void *)0x0) {
    ZwClose(local_res10);
  }
  return lVar1;
}



===== TraceLoggingRegisterEx_EtwRegister_EtwSetInformation @ 1400215d8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(void)

{
  undefined2 uVar1;
  code *pcVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  ulonglong local_18;
  
  puVar4 = auStack_48;
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = *(undefined4 *)(PTR_DAT_140019070 + -0x10);
  uStack_24 = *(undefined4 *)(PTR_DAT_140019070 + -0xc);
  uStack_20 = *(undefined4 *)(PTR_DAT_140019070 + -8);
  uStack_1c = *(undefined4 *)(PTR_DAT_140019070 + -4);
  if (DAT_140019088 != 0) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(5);
    puVar4 = auStack_40;
  }
  _DAT_140019090 = 0;
  uRam0000000140019098 = 0;
  *(undefined8 *)(puVar4 + -8) = 0x14002163b;
  iVar3 = EtwRegister(puVar4 + 0x20,_tlgEnableCallback,&DAT_140019068,&DAT_140019088);
  if (iVar3 == 0) {
    uVar1 = *(undefined2 *)PTR_DAT_140019070;
    *(undefined8 *)(puVar4 + -8) = 0x140021662;
    EtwSetInformation(DAT_140019088,2,PTR_DAT_140019070,uVar1);
  }
  *(undefined8 *)(puVar4 + -8) = 0x140021676;
  return iVar3;
}



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 140021684 =====

void wil_details_BuildFeatureStateCacheFromQueryResults(int param_1,longlong param_2,uint *param_3)

{
  uint uVar1;
  
  if ((param_1 == -0x7fffffde) || (param_1 == -0x3ffffddb)) {
    param_3[0] = 0;
    param_3[1] = 0;
  }
  else {
    param_3[0] = 0;
    param_3[1] = 0;
    if (param_1 == 0) {
      uVar1 = ((*(uint *)(param_2 + 4) & 0x40) << 2 | *(uint *)(param_2 + 4) & 0xb0) << 3 | 0x206;
      goto LAB_1400216e1;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_1400216e1;
    }
  }
  uVar1 = 0x206;
LAB_1400216e1:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 1400216ec =====

void wil_details_EvaluateFeatureDependencies(void)

{
  longlong *plVar1;
  undefined **ppuVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  bool bVar6;
  
  plVar1 = wil_details_FeatureDescriptors_SkipPadding((longlong *)&wil_details_featureDescriptors_a)
  ;
  if (plVar1 != (longlong *)0x0) {
    uVar4 = 0;
    uVar5 = 0x180;
    do {
      uVar3 = *(uint *)*plVar1;
      if ((uVar3 >> 9 & 1) != 0) {
        if (((uint)uVar5 & uVar3) == 0) {
          bVar6 = *(char *)((longlong)plVar1 + 0x1f) != '\0';
        }
        else {
          bVar6 = (uVar3 & (uint)uVar5) == 0x100;
        }
        uVar3 = uVar3 & 0x40 ^ (uint)bVar6 << 6 | (uint)uVar4 & 0xffffffbf;
        uVar4 = (ulonglong)uVar3;
        LOCK();
        *(uint *)*plVar1 = *(uint *)*plVar1 ^ uVar3;
        UNLOCK();
      }
      plVar1 = wil_details_FeatureDescriptors_SkipPadding(plVar1 + 7);
    } while (plVar1 != (longlong *)0x0);
  }
  ppuVar2 = &wil_details_featureDescriptors_a;
  while( true ) {
    plVar1 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar2);
    if (plVar1 == (longlong *)0x0) break;
    wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
              ((uint *)*plVar1,(longlong)plVar1);
    ppuVar2 = (undefined **)(plVar1 + 7);
  }
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 1400217a4 =====

uint wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
               (uint *param_1,longlong param_2)

{
  uint uVar1;
  
  uVar1 = *param_1;
  if ((uVar1 >> 9 & 1) != 0) {
    uVar1 = wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState
                      (param_1,uVar1,param_2);
  }
  return uVar1;
}



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 1400217dc =====

uint wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState
               (uint *param_1,uint param_2,longlong param_3)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  longlong *plVar4;
  uint uVar5;
  bool bVar6;
  
  uVar5 = param_2 >> 6 & 1;
  if ((uVar5 != 0) && (plVar4 = *(longlong **)(param_3 + 0x20), plVar4 != (longlong *)0x0)) {
    do {
      while( true ) {
        puVar1 = (undefined8 *)*plVar4;
        if (puVar1 == (undefined8 *)0x0) goto LAB_14002185e;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_14002185e;
        }
        uVar5 = 1;
        plVar4 = plVar4 + 1;
      }
      uVar2 = wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
                        ((uint *)*puVar1,(longlong)puVar1);
      if ((uVar5 == 0) || ((uVar2 & 1) == 0)) {
        uVar5 = 0;
      }
      else {
        uVar5 = 1;
      }
      plVar4 = plVar4 + 1;
    } while (uVar5 != 0);
  }
LAB_14002185e:
  do {
    uVar2 = param_2 & 0xffffffce;
    if ((param_2 & 1) == uVar5) {
      uVar2 = param_2 & 0xfffffffe;
    }
    uVar3 = uVar2 & 0xfffffdff | uVar5;
    LOCK();
    uVar2 = *param_1;
    bVar6 = param_2 == uVar2;
    if (bVar6) {
      *param_1 = uVar3;
    }
    else {
      param_2 = uVar2;
    }
    UNLOCK();
  } while (!bVar6);
  return uVar3;
}



===== wil_details_OnFeatureUsageProviderFlushNotification @ 1400218b0 =====

void wil_details_OnFeatureUsageProviderFlushNotification(int param_1)

{
  int iVar1;
  longlong *plVar2;
  undefined **ppuVar3;
  
  iVar1 = g_wil_details_featureUsageCached;
  if (param_1 == 1) {
    LOCK();
    g_wil_details_featureUsageCached = 0;
    UNLOCK();
    if (iVar1 != 0) {
      ppuVar3 = &wil_details_featureDescriptors_a;
      while (plVar2 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar3),
            plVar2 != (longlong *)0x0) {
        if ((*(uint *)plVar2[1] & 1) != 0) {
          wil_details_RecordCachedUsage((int)plVar2[3],(uint *)plVar2[1]);
        }
        ppuVar3 = (undefined **)(plVar2 + 7);
      }
    }
  }
  return;
}



===== wil_details_RecordFeatureUsageCallback @ 140021904 =====

void wil_details_RecordFeatureUsageCallback(void)

{
  RtlRecordFeatureUsage();
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 140021920 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 14002193c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_UpdateFeatureConfiguredStates(void)

{
  int iVar1;
  longlong *plVar2;
  undefined **ppuVar3;
  undefined1 auStack_58 [32];
  uint local_38 [2];
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  ppuVar3 = &wil_details_featureDescriptors_a;
  while( true ) {
    plVar2 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar3);
    if (plVar2 == (longlong *)0x0) break;
    if (((*(char *)((longlong)plVar2 + 0x1d) == '\0') &&
        (*(char *)((longlong)plVar2 + 0x1e) == '\0')) &&
       (*(char *)((longlong)plVar2 + 0x1c) == '\0')) {
      local_30 = 0;
      local_28 = 0;
      local_20 = 0;
      iVar1 = RtlQueryFeatureConfiguration((int)plVar2[3],1,&local_30,&local_28);
      local_38[0] = 0;
      local_38[1] = 0;
      wil_details_BuildFeatureStateCacheFromQueryResults(iVar1,(longlong)&local_28,local_38);
      LOCK();
      *(uint *)*plVar2 = *(uint *)*plVar2 ^ (*(uint *)*plVar2 ^ local_38[0]) & 0xf80;
      UNLOCK();
    }
    ppuVar3 = (undefined **)(plVar2 + 7);
  }
  return;
}



===== PmBuildInstanceId @ 1400219f0 =====

/* long __cdecl PmBuildInstanceId(struct _DEVICE_EXTENSION * __ptr64,struct _PARTITION_EXTENSION *
   __ptr64) */

long __cdecl PmBuildInstanceId(_DEVICE_EXTENSION *param_1,_PARTITION_EXTENSION *param_2)

{
  short sVar1;
  int iVar2;
  wchar_t *pwVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  longlong lVar6;
  
  if ((*(uint *)(param_2 + 0x28) >> 9 & 1) == 0) {
    pwVar3 = (wchar_t *)ExAllocatePool2(0x102,0x70,0x46426d50);
    if (pwVar3 == (wchar_t *)0x0) {
      iVar2 = -0x3fffff66;
    }
    else {
      uVar4 = RtlStringCbPrintfW(pwVar3,0x70,
                                 L"{%08lx-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x}#%016I64X",
                                 (ulonglong)*(uint *)(param_1 + 0xd8));
      iVar2 = (int)uVar4;
      if (iVar2 < 0) {
        ExFreePoolWithTag(pwVar3,0);
      }
      else {
        *(undefined4 *)(param_2 + 0x30) = 0x70006e;
        *(wchar_t **)(param_2 + 0x38) = pwVar3;
      }
    }
  }
  else {
    iVar2 = RtlDuplicateUnicodeString(1,param_1 + 0x1e0,param_2 + 0x30);
    lVar6 = 0;
    if ((-1 < iVar2) && (*(ushort *)(param_2 + 0x30) >> 1 != 0)) {
      uVar5 = (ulonglong)(uint)(*(ushort *)(param_2 + 0x30) >> 1);
      do {
        sVar1 = *(short *)(lVar6 + *(longlong *)(param_2 + 0x38));
        if ((sVar1 == 0x2f) || (sVar1 == 0x5c)) {
          *(undefined2 *)(lVar6 + *(longlong *)(param_2 + 0x38)) = 0x5f;
        }
        lVar6 = lVar6 + 2;
        uVar5 = uVar5 - 1;
      } while (uVar5 != 0);
    }
  }
  return iVar2;
}



===== PmBuildStableGuid @ 140021ba4 =====

/* long __cdecl PmBuildStableGuid(struct _DEVICE_EXTENSION * __ptr64,struct _PARTITION_EXTENSION *
   __ptr64) */

long __cdecl PmBuildStableGuid(_DEVICE_EXTENSION *param_1,_PARTITION_EXTENSION *param_2)

{
  undefined8 uVar1;
  long lVar2;
  longlong lVar3;
  
  lVar2 = 0;
  if ((*(uint *)(param_1 + 0x200) >> 0xe & 1) == 0) {
    lVar3 = 0xd8;
    if (*(int *)(param_2 + 0xa8) != 1) {
      lVar3 = 0xd0;
    }
    uVar1 = *(undefined8 *)(param_2 + lVar3 + 8);
    *(undefined8 *)(param_2 + 0x40) = *(undefined8 *)(param_2 + lVar3);
    *(undefined8 *)(param_2 + 0x48) = uVar1;
  }
  else {
    lVar2 = ExUuidCreate();
  }
  return lVar2;
}



===== PmCheckCriticalPartitions @ 140021bf8 =====

/* long __cdecl PmCheckCriticalPartitions(struct _DEVICE_EXTENSION * __ptr64,class SC_DISK_LAYOUT *
   __ptr64) */

long __cdecl PmCheckCriticalPartitions(_DEVICE_EXTENSION *param_1,SC_DISK_LAYOUT *param_2)

{
  longlong lVar1;
  uchar uVar2;
  int iVar3;
  ulonglong uVar4;
  _DEVICE_EXTENSION *this;
  _DEVICE_EXTENSION *p_Var5;
  ulong uVar6;
  ulonglong uVar7;
  
  lVar1 = *(longlong *)(PmControlObject + 0x40);
  if (param_1[0x25c] != (_DEVICE_EXTENSION)0x0) {
    this = param_1;
    uVar4 = PmEnforceService((longlong)param_1);
    for (p_Var5 = *(_DEVICE_EXTENSION **)(param_1 + 0x380); p_Var5 != param_1 + 0x380;
        p_Var5 = *(_DEVICE_EXTENSION **)p_Var5) {
      if (((*(char *)(lVar1 + 0xa8) == '\0') &&
          ((*(uint *)(*(longlong *)(p_Var5 + -0x88) + 0x30) >> 0x1d & 1) != 0)) ||
         (((char)uVar4 != '\0' && (p_Var5[0x35] != (_DEVICE_EXTENSION)0x0)))) {
        uVar7 = (ulonglong)*(uint *)(param_2 + 4);
        uVar6 = 0;
        if (*(uint *)(param_2 + 4) == 0) goto LAB_140021cb4;
        while( true ) {
          this = (_DEVICE_EXTENSION *)SC_DISK_LAYOUT::GetEntry(param_2,uVar6);
          uVar2 = SC_PART_ENTRY::IsUnused((SC_PART_ENTRY *)this);
          if ((uVar2 == '\0') && (*(longlong *)(this + 8) == *(longlong *)(p_Var5 + 0x20))) break;
          uVar6 = uVar6 + 1;
          if ((uint)uVar7 <= uVar6) goto LAB_140021cb4;
        }
        if (((char)uVar4 != '\0') && (p_Var5[0x35] != (_DEVICE_EXTENSION)0x0)) {
          if ((((*(longlong *)(this + 0x10) != *(longlong *)(p_Var5 + 0x28)) ||
               (*(longlong *)(this + 0x40) != *(longlong *)(p_Var5 + 0x58))) ||
              (*(longlong *)(this + 0x20) != *(longlong *)(p_Var5 + 0x38))) ||
             (*(longlong *)(this + 0x28) != *(longlong *)(p_Var5 + 0x40))) {
LAB_140021cb4:
            if ((Microsoft_Windows_PartitionEnableBits & 1) == 0) {
              return -0x3fffffde;
            }
            McTemplateK0qq_EtwWriteTransfer
                      (this,&CriticalDiskSetLayoutError,0,*(undefined4 *)(param_1 + 0xa8),
                       (char)*(undefined4 *)(p_Var5 + 0x30));
            return -0x3fffffde;
          }
          this = this + 0x48;
          iVar3 = wcsncmp((wchar_t *)this,(wchar_t *)(p_Var5 + 0x60),0x24);
          if (iVar3 != 0) goto LAB_140021cb4;
        }
      }
    }
  }
  return 0;
}



===== PmIsConversionInProgress @ 140021d64 =====

/* long __cdecl PmIsConversionInProgress(struct _DEVICE_EXTENSION * __ptr64,struct
   _PARTITION_EXTENSION * __ptr64) */

long __cdecl PmIsConversionInProgress(_DEVICE_EXTENSION *param_1,_PARTITION_EXTENSION *param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  int iVar5;
  uint uVar6;
  undefined8 *puVar7;
  longlong lVar8;
  ulonglong uVar9;
  uint uVar10;
  
  puVar7 = (undefined8 *)ExAllocatePool2(0x102,0x30,0x42496d50);
  if (puVar7 == (undefined8 *)0x0) {
    return -0x3fffff66;
  }
  lVar8 = ExAllocatePool2(0x102,0x38,0x42496d50);
  if (lVar8 == 0) {
    iVar5 = -0x3fffff66;
    goto LAB_140021ed4;
  }
  iVar5 = 0x1c;
  *puVar7 = 0;
  puVar7[1] = 0;
  puVar7[2] = 0;
  puVar7[3] = 0;
  puVar7[4] = 0;
  puVar7[5] = 0;
  *(undefined4 *)puVar7 = 0x1c;
  *(undefined4 *)((longlong)puVar7 + 4) = 0x8000001c;
  uVar2 = *(uint *)(puVar7 + 3);
  uVar3 = *(undefined8 *)(param_2 + 0xb8);
  uVar4 = *(undefined8 *)(param_2 + 0xb0);
  if (uVar2 == 0) {
    if (*(int *)(puVar7 + 2) != 0) {
      iVar5 = *(int *)((longlong)puVar7 + 0xc) + *(int *)(puVar7 + 2);
    }
    uVar10 = iVar5 + 7U & 0xfffffff8;
  }
  else {
    uVar10 = *(int *)((longlong)puVar7 + 0x14) + uVar2;
  }
  if (0xf < 0x30 - uVar10) {
    uVar6 = *(uint *)((longlong)puVar7 + 0x14);
    if (*(uint *)((longlong)puVar7 + 0x14) == 0) {
      *(uint *)((longlong)puVar7 + 0x14) = uVar10;
      uVar6 = uVar10;
    }
    *(undefined8 *)((longlong)puVar7 + ((ulonglong)uVar2 & 0xfffffffffffffff0) + (ulonglong)uVar6) =
         uVar4;
    *(undefined8 *)
     ((longlong)puVar7 + ((ulonglong)uVar2 & 0xfffffffffffffff0) + 8 + (ulonglong)uVar6) = uVar3;
    *(int *)(puVar7 + 3) = *(int *)(puVar7 + 3) + 0x10;
  }
  uVar9 = PmSendDeviceControl(*(undefined8 *)(param_1 + 0x10),0x2d9404,puVar7,0x30,lVar8,0x38,0);
  iVar5 = (int)uVar9;
  if (-1 < iVar5) {
    if (*(int *)(lVar8 + 4) == -0x7fffffe4) {
      uVar2 = *(uint *)(lVar8 + 0x1c);
      if ((((0x23 < uVar2) && (uVar2 < 0x39)) && ((uVar2 & 3) == 0)) &&
         ((0x13 < *(uint *)(lVar8 + 0x20) && (*(uint *)(lVar8 + 0x20) <= 0x38 - uVar2)))) {
        puVar1 = (undefined8 *)((ulonglong)uVar2 + 4 + lVar8);
        uVar3 = puVar1[1];
        *(undefined8 *)(param_2 + 0x58) = *puVar1;
        *(undefined8 *)(param_2 + 0x60) = uVar3;
        goto LAB_140021ec3;
      }
    }
    iVar5 = -0x3ffff6f5;
  }
LAB_140021ec3:
  ExFreePoolWithTag(lVar8,0);
LAB_140021ed4:
  ExFreePoolWithTag(puVar7,0);
  return iVar5;
}



===== PmCreateDisk @ 140021f08 =====

uint PmCreateDisk(_DEVICE_EXTENSION *param_1,_CREATE_DISK *param_2)

{
  uint uVar1;
  
  if ((*(char *)(*(longlong *)(PmControlObject + 0x40) + 0xa8) == '\0') &&
     (param_1[0x25c] != (_DEVICE_EXTENSION)0x0)) {
    uVar1 = 0xc0000022;
  }
  else {
    uVar1 = PmCreatePartitionTable(*(_DEVICE_OBJECT **)(param_1 + 8),param_2);
    if (-1 < (int)uVar1) {
      PmInvalidatePartitionTableCache((longlong)param_1);
      uVar1 = PmGetDriveLayoutEx(param_1,(undefined8 *)0x0);
    }
  }
  return uVar1;
}



===== PmSetDriveLayoutEx @ 140021f64 =====

void PmSetDriveLayoutEx(_DEVICE_EXTENSION *param_1,SC_DISK_LAYOUT *param_2)

{
  long lVar1;
  int local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  
  lVar1 = PmCheckCriticalPartitions(param_1,param_2);
  if (-1 < lVar1) {
    if (*(int *)(param_2 + 4) == 0) {
      local_28 = *(int *)param_2;
      local_18 = 0;
      uStack_24 = 0;
      uStack_20 = 0;
      uStack_1c = 0;
      if (local_28 == 0) {
        uStack_24 = *(undefined4 *)(param_2 + 8);
      }
      else if (local_28 == 1) {
        uStack_24 = (undefined4)*(undefined8 *)(param_2 + 8);
        uStack_20 = (undefined4)((ulonglong)*(undefined8 *)(param_2 + 8) >> 0x20);
        uStack_1c = (undefined4)*(undefined8 *)(param_2 + 0x10);
        local_18 = (undefined4)((ulonglong)*(undefined8 *)(param_2 + 0x10) >> 0x20);
      }
      uStack_14 = 0;
      PmCreateDisk(param_1,(_CREATE_DISK *)&local_28);
    }
    else {
      lVar1 = PmWritePartitionTable(*(_DEVICE_OBJECT **)(param_1 + 8),param_2);
      if (-1 < lVar1) {
        PmInvalidatePartitionTableCache((longlong)param_1);
        PmGetDriveLayoutEx(param_1,(undefined8 *)0x0);
      }
    }
  }
  return;
}



===== PmSetPartitionInformationEx @ 140021ffc =====

uint PmSetPartitionInformationEx(longlong param_1,_SET_PARTITION_INFORMATION_EX *param_2)

{
  _DEVICE_EXTENSION *p_Var1;
  uint uVar2;
  
  p_Var1 = *(_DEVICE_EXTENSION **)(param_1 + 0x18);
  if ((*(uint *)(param_1 + 0x28) & 4) == 0) {
    if ((p_Var1[0x25c] == (_DEVICE_EXTENSION)0x0) || (*(char *)(param_1 + 0xc5) == '\0')) {
      uVar2 = PmSetPartition(*(_DEVICE_OBJECT **)(p_Var1 + 8),*(ulong *)(param_1 + 0xa0),param_2);
      if (-1 < (int)uVar2) {
        PmInvalidatePartitionTableCache((longlong)p_Var1);
        uVar2 = PmGetDriveLayoutEx(p_Var1,(undefined8 *)0x0);
      }
    }
    else {
      if ((Microsoft_Windows_PartitionEnableBits & 1) != 0) {
        McTemplateK0qq_EtwWriteTransfer
                  (param_1,&ServiceSetPartitionError,0,*(undefined4 *)(p_Var1 + 0xa8),
                   (char)*(undefined4 *)(param_1 + 0xc0));
      }
      uVar2 = 0xc0000022;
    }
  }
  else {
    uVar2 = 0xc000000e;
  }
  return uVar2;
}



===== PmSetSystemCriticalFlag @ 14002208c =====

uint PmSetSystemCriticalFlag(_DEVICE_EXTENSION *param_1)

{
  longlong lVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  ulonglong uVar5;
  
  lVar1 = *(longlong *)(PmControlObject + 0x40);
  uVar2 = PmGetDriveLayoutEx(param_1,(undefined8 *)0x0);
  uVar5 = 0;
  if (-1 < (int)uVar2) {
    if (*(int *)(param_1 + 0x390) == 0) {
      puVar3 = *(uint **)(lVar1 + 0xc0);
      uVar5 = 0;
      if (*puVar3 != 0) {
        do {
          if ((((puVar3[uVar5 * 7 + 7] & 0x40) == 0) && (puVar3[uVar5 * 7 + 1] == 0)) &&
             (puVar3[uVar5 * 7 + 3] == *(uint *)(param_1 + 0x398))) {
            param_1[0x25c] = (_DEVICE_EXTENSION)0x1;
            *(uint *)(*(longlong *)(param_1 + 8) + 0x30) =
                 *(uint *)(*(longlong *)(param_1 + 8) + 0x30) | puVar3[uVar5 * 7 + 7];
            puVar3[uVar5 * 7 + 7] = puVar3[uVar5 * 7 + 7] | 0x40;
          }
          puVar3 = *(uint **)(lVar1 + 0xc0);
          uVar4 = (int)uVar5 + 1;
          uVar5 = (ulonglong)uVar4;
        } while (uVar4 < *puVar3);
      }
    }
    else if ((*(int *)(param_1 + 0x390) == 1) && (puVar3 = *(uint **)(lVar1 + 0xc0), *puVar3 != 0))
    {
      do {
        if ((((puVar3[uVar5 * 7 + 7] & 0x40) == 0) &&
            ((puVar3[uVar5 * 7 + 1] == 1 &&
             (*(longlong *)(puVar3 + uVar5 * 7 + 3) == *(longlong *)(param_1 + 0x398))))) &&
           (*(longlong *)(puVar3 + uVar5 * 7 + 5) == *(longlong *)(param_1 + 0x3a0))) {
          param_1[0x25c] = (_DEVICE_EXTENSION)0x1;
          *(uint *)(*(longlong *)(param_1 + 8) + 0x30) =
               *(uint *)(*(longlong *)(param_1 + 8) + 0x30) | puVar3[uVar5 * 7 + 7];
          puVar3[uVar5 * 7 + 7] = puVar3[uVar5 * 7 + 7] | 0x40;
        }
        puVar3 = *(uint **)(lVar1 + 0xc0);
        uVar4 = (int)uVar5 + 1;
        uVar5 = (ulonglong)uVar4;
      } while (uVar4 < *puVar3);
    }
  }
  return uVar2;
}



===== PmWmiCounterEnable @ 1400221c0 =====

undefined8 PmWmiCounterEnable(longlong *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  longlong lVar4;
  ulonglong uVar5;
  longlong lVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  undefined8 local_res8;
  undefined8 local_res10;
  
  uVar7 = 0;
  if (param_1 == (longlong *)0x0) {
    uVar7 = 0xc000000d;
  }
  else if (*param_1 == 0) {
    uVar1 = KeQueryMaximumProcessorCountEx(0xffff);
    uVar2 = KeQueryActiveProcessorCountEx(0xffff);
    uVar8 = (ulonglong)uVar2;
    lVar4 = ExAllocatePool2(0x40,(uVar2 * 0x10 + uVar1) * 8 + 0xe0,0x45506d50);
    if (lVar4 == 0) {
      uVar7 = 0xc000009a;
    }
    else {
      *(longlong *)(lVar4 + 0x48) = lVar4 + 0x60;
      uVar5 = lVar4 + 0x60 + (ulonglong)uVar1 * 8 + 0x80 & 0xffffffffffffff80;
      if (uVar2 != 0) {
        lVar6 = 0;
        do {
          *(ulonglong *)(lVar6 + *(longlong *)(lVar4 + 0x48)) = uVar5;
          uVar5 = uVar5 + 0x80;
          lVar6 = lVar6 + 8;
          uVar8 = uVar8 - 1;
        } while (uVar8 != 0);
      }
      *(undefined4 *)(lVar4 + 0x38) = 1;
      *(uint *)(lVar4 + 0x3c) = uVar2;
      local_res10 = 0;
      uVar3 = KeQueryUnbiasedInterruptTimePrecise(&local_res10);
      *(undefined8 *)(lVar4 + 0x50) = uVar3;
      *(undefined8 *)(lVar4 + 0x58) = uVar3;
      KeInitializeMutex(lVar4,0);
      *param_1 = lVar4;
    }
  }
  else {
    if ((*(int *)(*param_1 + 0x38) == 0) && (*(int *)(*param_1 + 0x44) == 0)) {
      local_res8 = 0;
      uVar3 = KeQueryUnbiasedInterruptTimePrecise(&local_res8);
      *(undefined8 *)(*param_1 + 0x58) = uVar3;
      if (*(int *)(*param_1 + 0x40) == 0) {
        *(undefined8 *)(*param_1 + 0x50) = *(undefined8 *)(*param_1 + 0x58);
      }
    }
    LOCK();
    *(int *)(*param_1 + 0x38) = *(int *)(*param_1 + 0x38) + 1;
    UNLOCK();
  }
  return uVar7;
}



===== PmCheckIdsMbr @ 14002232c =====

/* long __cdecl PmCheckIdsMbr(struct _DEVICE_EXTENSION * __ptr64,struct _DRIVE_LAYOUT_INFORMATION_EX
   * __ptr64,unsigned char * __ptr64,enum _DISK_OFFLINE_REASON * __ptr64) */

long __cdecl
PmCheckIdsMbr(_DEVICE_EXTENSION *param_1,_DRIVE_LAYOUT_INFORMATION_EX *param_2,uchar *param_3,
             _DISK_OFFLINE_REASON *param_4)

{
  uint uVar1;
  longlong lVar2;
  code *pcVar3;
  long lVar4;
  longlong lVar5;
  undefined8 *puVar6;
  _DEVICE_EXTENSION *p_Var7;
  longlong *plVar8;
  uchar local_res10 [8];
  undefined1 local_res18 [16];
  undefined8 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  ulonglong local_40;
  undefined8 uStack_38;
  
  lVar2 = PmControlObject;
  lVar4 = 0;
  local_58 = 0;
  *param_4 = 0;
  local_res10[0] = '\0';
  lVar2 = *(longlong *)(lVar2 + 0x40);
  uVar1 = *(uint *)(param_2 + 8);
  local_res18[0] = 0;
  *param_3 = '\0';
  local_50 = 0;
  uStack_48 = 0;
  uStack_38 = 0;
  if (uVar1 == 0) {
    *param_3 = '\x01';
  }
  else {
    local_40 = (ulonglong)uVar1;
    lVar5 = RtlLookupElementGenericTableAvl(lVar2 + 200,&local_58);
    if (lVar5 == 0) {
      local_40 = CONCAT44(local_40._4_4_,*(undefined4 *)(param_2 + 8));
      puVar6 = (undefined8 *)RtlInsertElementGenericTableAvl(lVar2 + 200,&local_58,0x28,local_res18)
      ;
      if (puVar6 == (undefined8 *)0x0) {
        lVar4 = -0x3fffff66;
      }
      else {
        p_Var7 = param_1 + 0x268;
        plVar8 = *(longlong **)(param_1 + 0x270);
        if ((_DEVICE_EXTENSION *)*plVar8 != p_Var7) {
          p_Var7 = (_DEVICE_EXTENSION *)0x3;
          pcVar3 = (code *)swi(0x29);
          puVar6 = (undefined8 *)(*pcVar3)();
        }
        *puVar6 = p_Var7;
        puVar6[1] = plVar8;
        *plVar8 = (longlong)puVar6;
        *(undefined8 **)(p_Var7 + 8) = puVar6;
        puVar6[2] = param_1;
      }
    }
    else {
      lVar4 = PmIsRedundantPath(param_1,*(_DEVICE_EXTENSION **)(lVar5 + 0x10),local_res10);
      if (-1 < lVar4) {
        *param_4 = (-(uint)(local_res10[0] != '\0') & 0xfffffffe) + 4;
      }
    }
  }
  return lVar4;
}



===== PmIsRedundantPath @ 140022444 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl PmIsRedundantPath(struct _DEVICE_EXTENSION * __ptr64,struct _DEVICE_EXTENSION *
   __ptr64,unsigned char * __ptr64) */

long __cdecl PmIsRedundantPath(_DEVICE_EXTENSION *param_1,_DEVICE_EXTENSION *param_2,uchar *param_3)

{
  byte *pbVar1;
  ushort uVar2;
  uint uVar3;
  ushort uVar4;
  int iVar5;
  uint uVar6;
  longlong lVar7;
  longlong lVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  long lVar11;
  longlong lVar12;
  undefined1 auStack_e8 [32];
  undefined8 *local_c8;
  undefined8 *local_c0;
  undefined8 *local_b8;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  ushort local_70 [8];
  undefined4 local_60;
  undefined8 local_5c;
  undefined8 uStack_54;
  uint local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_e8;
  local_a8 = 0;
  local_60 = 0;
  iVar5 = 0;
  *param_3 = '\0';
  local_90 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_4c = 0;
  local_5c = 0;
  uStack_54 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_70[0] = 0;
  local_70[1] = 0;
  local_70[2] = 0;
  local_70[3] = 0;
  local_70[4] = 0;
  local_70[5] = 0;
  local_70[6] = 0;
  local_70[7] = 0;
  if (*(int *)(param_1 + 0x30) == 0) {
    iVar5 = PmGetDriveGeometry(*(undefined8 *)(param_1 + 8),&local_60);
    uVar3 = local_4c;
    if (iVar5 < 0) {
      return iVar5;
    }
    uVar10 = (ulonglong)local_4c;
    iVar5 = PmGetDriveGeometry(*(undefined8 *)(param_2 + 8),&local_60);
    if (iVar5 < 0) {
      return iVar5;
    }
    if (local_4c == uVar3) {
      uVar6 = uVar3 * 3;
      if (uVar6 < 0x1000) {
        uVar6 = 0x1000;
      }
      lVar7 = ExAllocatePool2(0x42,uVar6,0x42496d50);
      if (lVar7 == 0) {
        return -0x3fffff66;
      }
      KeInitializeEvent(&local_a0,0,0);
      local_b8 = &local_88;
      local_c0 = &local_a0;
      local_c8 = &local_a8;
      lVar8 = IoBuildSynchronousFsdRequest(3,*(undefined8 *)(param_1 + 8),lVar7,uVar3);
      if (lVar8 == 0) {
LAB_140022576:
        iVar5 = -0x3fffff66;
      }
      else {
        pbVar1 = (byte *)(*(longlong *)(lVar8 + 0xb8) + -0x46);
        *pbVar1 = *pbVar1 | 2;
        iVar5 = IofCallDriver(*(undefined8 *)(param_1 + 8));
        if (iVar5 == 0x103) {
          local_c8 = (undefined8 *)0x0;
          KeWaitForSingleObject(&local_a0,0,0,0);
          iVar5 = (int)local_88;
        }
        if (-1 < iVar5) {
          KeInitializeEvent(&local_a0,0,0);
          local_b8 = &local_88;
          local_c0 = &local_a0;
          local_c8 = &local_a8;
          lVar8 = IoBuildSynchronousFsdRequest(3,*(undefined8 *)(param_2 + 8),lVar7 + uVar10,uVar3);
          if (lVar8 == 0) goto LAB_140022576;
          pbVar1 = (byte *)(*(longlong *)(lVar8 + 0xb8) + -0x46);
          *pbVar1 = *pbVar1 | 2;
          iVar5 = IofCallDriver(*(undefined8 *)(param_2 + 8));
          if (iVar5 == 0x103) {
            local_c8 = (undefined8 *)0x0;
            KeWaitForSingleObject(&local_a0,0,0,0);
            iVar5 = (int)local_88;
          }
          if (-1 < iVar5) {
            uVar2 = *(ushort *)(lVar7 + 0x1bc);
            do {
              PmUuidCreate((_GUID *)local_70);
              uVar4 = local_70[0] ^ local_70[1] ^ local_70[2] ^ local_70[3] ^ local_70[4] ^
                      local_70[5] ^ local_70[6] ^ local_70[7];
              *(ushort *)(lVar7 + 0x1bc) = uVar4;
            } while (uVar4 == uVar2);
            KeInitializeEvent(&local_a0,0,0);
            local_b8 = &local_88;
            local_c0 = &local_a0;
            local_c8 = &local_a8;
            lVar8 = IoBuildSynchronousFsdRequest(4,*(undefined8 *)(param_1 + 8),lVar7,uVar3);
            if (lVar8 == 0) goto LAB_140022576;
            pbVar1 = (byte *)(*(longlong *)(lVar8 + 0xb8) + -0x46);
            *pbVar1 = *pbVar1 | 0x12;
            iVar5 = IofCallDriver(*(undefined8 *)(param_1 + 8));
            if (iVar5 == 0x103) {
              local_c8 = (undefined8 *)0x0;
              KeWaitForSingleObject(&local_a0,0,0,0);
              iVar5 = (int)local_88;
            }
            if (-1 < iVar5) {
              KeInitializeEvent(&local_a0,0,0);
              local_b8 = &local_88;
              local_c0 = &local_a0;
              lVar12 = (ulonglong)(uVar3 * 2) + lVar7;
              local_c8 = &local_a8;
              lVar8 = IoBuildSynchronousFsdRequest(3,*(undefined8 *)(param_2 + 8),lVar12,uVar3);
              if (lVar8 == 0) goto LAB_140022576;
              pbVar1 = (byte *)(*(longlong *)(lVar8 + 0xb8) + -0x46);
              *pbVar1 = *pbVar1 | 2;
              iVar5 = IofCallDriver(*(undefined8 *)(param_2 + 8));
              if (iVar5 == 0x103) {
                local_c8 = (undefined8 *)0x0;
                KeWaitForSingleObject(&local_a0,0,0,0);
                iVar5 = (int)local_88;
              }
              if ((-1 < iVar5) &&
                 (uVar9 = RtlCompareMemory(uVar10 + lVar7,lVar12,uVar10), uVar9 != uVar10)) {
                *param_3 = '\x01';
              }
            }
          }
        }
      }
      ExFreePoolWithTag(lVar7,0);
      if (iVar5 < 0) {
        return iVar5;
      }
    }
    lVar11 = -0x7ffbffc5;
    if (*param_3 != '\0') goto LAB_140022843;
  }
  lVar11 = -0x7ffbffc6;
LAB_140022843:
  PmLogError(param_1,param_2,lVar11);
  return iVar5;
}



===== PmLogError @ 140022880 =====

/* void __cdecl PmLogError(struct _DEVICE_EXTENSION * __ptr64,struct _DEVICE_EXTENSION *
   __ptr64,long) */

void __cdecl PmLogError(_DEVICE_EXTENSION *param_1,_DEVICE_EXTENSION *param_2,long param_3)

{
  wchar_t *pwVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  longlong lVar4;
  longlong lVar5;
  undefined4 *puVar6;
  longlong lVar7;
  
  lVar4 = IoAllocateErrorLogEntry(*(undefined8 *)(param_1 + 8),0xb0);
  if (lVar4 != 0) {
    *(undefined4 *)(lVar4 + 4) = 0x300002;
    *(long *)(lVar4 + 0xc) = param_3;
    *(undefined2 *)(lVar4 + 2) = 0;
    RtlStringCbPrintfW((wchar_t *)(lVar4 + 0x30),0x80,L"%d",(ulonglong)*(uint *)(param_1 + 0xa8));
    lVar5 = -1;
    do {
      lVar5 = lVar5 + 1;
    } while (*(short *)(lVar4 + 0x30 + lVar5 * 2) != 0);
    lVar7 = -1;
    pwVar1 = (wchar_t *)(lVar4 + 0x32 + lVar5 * 2);
    do {
      lVar7 = lVar7 + 1;
    } while (pwVar1[lVar7] != L'\0');
    RtlStringCbPrintfW(pwVar1,(ulonglong)(uint)((0x3f - (int)lVar7) * 2),L"%d",
                       (ulonglong)*(uint *)(param_2 + 0xa8));
    IoWriteErrorLogEntry(lVar4);
    if (param_3 == -0x7ffbffc6) {
      puVar6 = (undefined4 *)ExAllocatePool2(0x42,0x28,0x42496d50);
      if (puVar6 != (undefined4 *)0x0) {
        uVar2 = *(undefined4 *)(param_2 + 0xa8);
        puVar6[8] = 0xffffffff;
        *puVar6 = 0x280001;
        puVar6[1] = 0x6a61885b;
        puVar6[2] = 0x43dd7c39;
        puVar6[3] = 0xacb8569b;
        puVar6[4] = 0xaa49a522;
        puVar6[9] = uVar2;
        uVar3 = *(undefined8 *)(param_2 + 0x18);
        *(undefined8 *)(puVar6 + 6) = 0;
        IoReportTargetDeviceChangeAsynchronous(uVar3,puVar6,0,0);
        ExFreePoolWithTag(puVar6,0);
      }
    }
  }
  return;
}



===== PmUpdateIdsGpt @ 1400229d8 =====

/* void __cdecl PmUpdateIdsGpt(struct _DRIVE_LAYOUT_INFORMATION_EX * __ptr64,unsigned char) */

void __cdecl PmUpdateIdsGpt(_DRIVE_LAYOUT_INFORMATION_EX *param_1,uchar param_2)

{
  _GUID *p_Var1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  longlong lVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  
  local_48 = 0;
  p_Var1 = (_GUID *)(param_1 + 8);
  local_40 = 0;
  uStack_38 = 0;
  lVar3 = *(longlong *)(PmControlObject + 0x40);
  local_30 = 0;
  uStack_28 = 0;
  if (param_2 == '\0') {
    lVar5 = *(longlong *)p_Var1;
    if (lVar5 == 0) {
      lVar5 = *(longlong *)(param_1 + 0x10);
    }
    if (lVar5 != 0) {
      local_30 = *(undefined8 *)p_Var1;
      uStack_28 = *(undefined8 *)(param_1 + 0x10);
      lVar5 = RtlLookupElementGenericTableAvl(lVar3 + 0x130,&local_48);
      if (lVar5 == 0) goto LAB_140022a6a;
    }
  }
  PmUuidCreate(p_Var1);
LAB_140022a6a:
  uVar2 = *(uint *)(param_1 + 4);
  uVar7 = 0;
  if (uVar2 != 0) {
    do {
      uVar4 = (uint)uVar7;
      if (param_2 == '\0') {
        lVar5 = *(longlong *)(param_1 + uVar7 * 0x90 + 0x60);
        if (lVar5 == 0) {
          lVar5 = *(longlong *)(param_1 + uVar7 * 0x90 + 0x68);
        }
        if (lVar5 != 0) {
          lVar5 = *(longlong *)(param_1 + uVar7 * 0x90 + 0x60) - *(longlong *)p_Var1;
          uVar6 = uVar4;
          if (lVar5 == 0) {
            lVar5 = *(longlong *)(param_1 + uVar7 * 0x90 + 0x68) - *(longlong *)(param_1 + 0x10);
          }
          while (lVar5 != 0) {
            uVar6 = uVar6 + 1;
            if (uVar2 <= uVar6) {
              local_30 = *(undefined8 *)(param_1 + uVar7 * 0x90 + 0x60);
              uStack_28 = *(undefined8 *)(param_1 + uVar7 * 0x90 + 0x68);
              lVar5 = RtlLookupElementGenericTableAvl(lVar3 + 0x130,&local_48);
              if (lVar5 == 0) goto LAB_140022b28;
              break;
            }
            lVar5 = *(longlong *)(param_1 + uVar7 * 0x90 + 0x60) -
                    *(longlong *)(param_1 + (ulonglong)uVar6 * 0x90 + 0x60);
            if (lVar5 == 0) {
              lVar5 = *(longlong *)(param_1 + uVar7 * 0x90 + 0x68) -
                      *(longlong *)(param_1 + (ulonglong)uVar6 * 0x90 + 0x68);
            }
          }
        }
      }
      PmUuidCreate((_GUID *)(param_1 + uVar7 * 0x90 + 0x60));
LAB_140022b28:
      uVar7 = (ulonglong)(uVar4 + 1);
      uVar2 = *(uint *)(param_1 + 4);
    } while (uVar4 + 1 < uVar2);
  }
  return;
}



===== PmUpdateIdsMbr @ 140022b5c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl PmUpdateIdsMbr(struct _DRIVE_LAYOUT_INFORMATION_EX * __ptr64,unsigned char) */

void __cdecl PmUpdateIdsMbr(_DRIVE_LAYOUT_INFORMATION_EX *param_1,uchar param_2)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  undefined1 auStack_68 [32];
  undefined8 local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  uint local_20 [4];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  local_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  lVar1 = *(longlong *)(PmControlObject + 0x40);
  local_30 = 0;
  uStack_28 = 0;
  local_20[0] = 0;
  local_20[1] = 0;
  local_20[2] = 0;
  local_20[3] = 0;
  do {
    PmUuidCreate((_GUID *)local_20);
    uVar3 = local_20[0] ^ local_20[1] ^ local_20[2] ^ local_20[3];
    local_30 = CONCAT44(local_30._4_4_,uVar3);
    lVar2 = RtlLookupElementGenericTableAvl(lVar1 + 200,&local_48);
  } while (lVar2 != 0);
  *(uint *)(param_1 + 8) = uVar3;
  return;
}



===== PmUuidCreate @ 140022c0c =====

/* void __cdecl PmUuidCreate(struct _GUID * __ptr64) */

void __cdecl PmUuidCreate(_GUID *param_1)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 local_res10 [3];
  
  iVar2 = ExUuidCreate();
  if (iVar2 < 0) {
    local_res10[0] = 0;
    uVar1 = KeQueryUnbiasedInterruptTimePrecise(local_res10);
    local_res10[0] = 0;
    *(undefined8 *)param_1 = uVar1;
    uVar1 = KeQueryUnbiasedInterruptTimePrecise(local_res10);
    *(undefined8 *)(param_1 + 8) = uVar1;
  }
  return;
}



===== PmTableSignatureCompareRoutine @ 140022c70 =====

int PmTableSignatureCompareRoutine(undefined8 param_1,longlong param_2,longlong param_3)

{
  if (*(uint *)(param_2 + 0x18) < *(uint *)(param_3 + 0x18)) {
    return 0;
  }
  return 2 - (uint)(*(uint *)(param_3 + 0x18) < *(uint *)(param_2 + 0x18));
}



===== PmUpdateIds @ 140022c8c =====

long PmUpdateIds(_DEVICE_EXTENSION *param_1,_DRIVE_LAYOUT_INFORMATION_EX *param_2)

{
  longlong lVar1;
  _DISK_SNAPSHOT_DATA *p_Var2;
  long lVar3;
  uchar uVar4;
  bool bVar5;
  uint local_res18 [2];
  _DISK_SNAPSHOT_DATA *local_res20;
  
  local_res18[0] = 0;
  local_res20 = (_DISK_SNAPSHOT_DATA *)0x0;
  lVar1 = *(longlong *)(PmControlObject + 0x40);
  lVar3 = PmGetSnapshotData(param_1,param_2,&local_res20,local_res18);
  p_Var2 = local_res20;
  if (-1 < lVar3) {
    bVar5 = *(int *)(local_res20 + 0x14) == 1;
    if (bVar5) {
      *(undefined4 *)(local_res20 + 0x14) = 2;
    }
    uVar4 = '\0';
    KeWaitForSingleObject(lVar1 + 0x68,0,0,0,0);
    if (*(int *)param_2 == 0) {
      PmUpdateIdsMbr(param_2,uVar4);
    }
    else if (*(int *)param_2 == 1) {
      PmUpdateIdsGpt(param_2,bVar5);
    }
    KeReleaseMutex(lVar1 + 0x68,0);
    lVar3 = PmWritePartitionTable(*(_DEVICE_OBJECT **)(param_1 + 8),(SC_DISK_LAYOUT *)param_2);
    if ((-1 < lVar3) && (bVar5)) {
      lVar3 = PmSetSnapshotData(param_1,(SC_DISK_LAYOUT *)param_2,p_Var2,local_res18[0]);
    }
  }
  if (p_Var2 != (_DISK_SNAPSHOT_DATA *)0x0) {
    ExFreePoolWithTag(p_Var2,0);
  }
  return lVar3;
}



===== PmCreateSnapshotPartition @ 140022d94 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl PmCreateSnapshotPartition(struct _DEVICE_EXTENSION * __ptr64) */

long __cdecl PmCreateSnapshotPartition(_DEVICE_EXTENSION *param_1)

{
  uint uVar1;
  SC_DISK_LAYOUT *pSVar2;
  _DEVICE_OBJECT *p_Var3;
  int iVar4;
  int *_Src;
  uint uVar5;
  longlong lVar6;
  SC_DISK_LAYOUT *_Dst;
  ulonglong uVar7;
  uint uVar8;
  ulonglong uVar9;
  uint uVar10;
  longlong lVar11;
  undefined1 auStack_68 [32];
  int *local_48;
  undefined4 local_40;
  undefined8 local_3c;
  undefined8 uStack_34;
  int local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_68;
  local_40 = 0;
  local_48 = (int *)0x0;
  local_3c = 0;
  uStack_34 = 0;
  local_2c = 0;
  uVar5 = PmGetDriveLayoutEx(param_1,&local_48);
  _Src = local_48;
  if ((-1 < (int)uVar5) && (*local_48 == 1)) {
    for (uVar7 = 0; (uint)uVar7 < (uint)local_48[1]; uVar7 = (ulonglong)((uint)uVar7 + 1)) {
      lVar6 = *(longlong *)(local_48 + uVar7 * 0x24 + 0x14) + -0x4de84400caddebf1;
      if (lVar6 == 0) {
        lVar6 = *(longlong *)(local_48 + uVar7 * 0x24 + 0x16) + 0x30c33082eeedfc4f;
      }
      if (lVar6 == 0) goto LAB_140022fd9;
    }
    uVar5 = PmGetDriveGeometry(*(undefined8 *)(param_1 + 8),&local_40);
    if (-1 < (int)uVar5) {
      if ((ulonglong)(uint)_Src[1] * 0x90 < 0x100000000) {
        iVar4 = (int)((ulonglong)(uint)_Src[1] * 0x90);
        uVar10 = iVar4 + 0x30;
        if (0x2f < uVar10) {
          uVar1 = iVar4 + 0xc0;
          uVar8 = 0xffffffff;
          if (uVar1 >= 0x90) {
            uVar8 = uVar1;
          }
          uVar5 = -(uint)(uVar1 < 0x90) & 0xc0000095;
          if (0x8f < uVar1) {
            _Dst = (SC_DISK_LAYOUT *)ExAllocatePool2(0x40,uVar8,0x54506d50);
            if (_Dst == (SC_DISK_LAYOUT *)0x0) {
              uVar5 = 0xc000009a;
            }
            else {
              memmove(_Dst,_Src,(ulonglong)uVar10);
              for (uVar7 = 0; (uint)uVar7 < *(uint *)(_Dst + 4);
                  uVar7 = (ulonglong)((uint)uVar7 + 1)) {
                lVar6 = *(longlong *)(_Dst + uVar7 * 0x90 + 0x50) + -0x4db80b5ce3c9e316;
                if (lVar6 == 0) {
                  lVar6 = *(longlong *)(_Dst + uVar7 * 0x90 + 0x58) + 0x51eafd0fd206827f;
                }
                if (lVar6 == 0) {
                  lVar6 = *(longlong *)(_Dst + uVar7 * 0x90 + 0x38);
                  uVar9 = (ulonglong)(uint)(local_2c << 9);
                  if (*(longlong *)(_Dst + uVar7 * 0x90 + 0x40) < (longlong)uVar9) {
                    uVar5 = 0xc000009a;
                  }
                  else {
                    _Dst[uVar7 * 0x90 + 0x4c] = (SC_DISK_LAYOUT)0x1;
                    *(ulonglong *)(_Dst + uVar7 * 0x90 + 0x38) =
                         (ulonglong)(uint)(local_2c << 9) + lVar6;
                    *(ulonglong *)(_Dst + uVar7 * 0x90 + 0x40) =
                         *(longlong *)(_Dst + uVar7 * 0x90 + 0x40) - uVar9;
                    lVar11 = (ulonglong)*(uint *)(_Dst + 4) * 0x90;
                    *(undefined4 *)(_Dst + lVar11 + 0x30) = 1;
                    *(longlong *)(_Dst + lVar11 + 0x38) = lVar6;
                    *(ulonglong *)(_Dst + lVar11 + 0x40) = uVar9;
                    _Dst[lVar11 + 0x4c] = (SC_DISK_LAYOUT)0x1;
                    pSVar2 = _Dst + lVar11 + 0x50;
                    *(undefined4 *)pSVar2 = 0xcaddebf1;
                    *(undefined4 *)(pSVar2 + 4) = 0x4de84400;
                    *(undefined4 *)(pSVar2 + 8) = 0x111203b1;
                    *(undefined4 *)(pSVar2 + 0xc) = 0xcf3ccf7d;
                    uVar5 = ExUuidCreate(_Dst + lVar11 + 0x60);
                    if (-1 < (int)uVar5) {
                      RtlStringCbCopyW((short *)(_Dst + lVar11 + 0x78),0x48,0x140015370);
                      p_Var3 = *(_DEVICE_OBJECT **)(param_1 + 8);
                      *(int *)(_Dst + 4) = *(int *)(_Dst + 4) + 1;
                      uVar5 = PmWritePartitionTable(p_Var3,_Dst);
                      if (-1 < (int)uVar5) {
                        PmInvalidatePartitionTableCache((longlong)param_1);
                        uVar5 = PmGetDriveLayoutEx(param_1,(undefined8 *)0x0);
                      }
                    }
                  }
                  goto LAB_140022fc1;
                }
              }
              uVar5 = 0xc0000225;
LAB_140022fc1:
              ExFreePoolWithTag(_Dst,0);
            }
          }
          goto LAB_140022fd9;
        }
      }
      uVar5 = 0xc0000095;
    }
  }
LAB_140022fd9:
  if (_Src != (int *)0x0) {
    ExFreePoolWithTag(_Src,0);
  }
  return uVar5;
}



===== PmVerifySnapshotData @ 14002301c =====

/* unsigned char __cdecl PmVerifySnapshotData(struct _DISK_SNAPSHOT_DATA * __ptr64,unsigned
   long,unsigned char) */

uchar __cdecl PmVerifySnapshotData(_DISK_SNAPSHOT_DATA *param_1,ulong param_2,uchar param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  uchar uVar5;
  
  uVar5 = '\0';
  if ((((0x6f < param_2) && (*(longlong *)param_1 == 0x5452415050414e53)) &&
      (*(int *)(param_1 + 8) == 1)) &&
     (((*(uint *)(param_1 + 0xc) <= param_2 && (*(uint *)(param_1 + 0x14) < 4)) &&
      ((uVar4 = Feature_2563478843__private_IsEnabledDeviceUsageNoInline(), (int)uVar4 == 0 ||
       (0x6f < *(uint *)(param_1 + 0xc))))))) {
    uVar4 = Feature_3144915256__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar4 != 0) {
      param_2 = *(ulong *)(param_1 + 0xc);
    }
    if (param_3 != '\0') {
      iVar1 = *(int *)(param_1 + 0x10);
      *(undefined4 *)(param_1 + 0x10) = 0;
      iVar3 = RtlComputeCrc32(0,param_1,*(undefined4 *)(param_1 + 0xc));
      *(int *)(param_1 + 0x10) = iVar1;
      if (iVar3 != iVar1) {
        return '\0';
      }
    }
    if (((*(uint *)(param_1 + 100) == 0) ||
        (((uVar2 = *(uint *)(param_1 + 0x60), 0x6f < uVar2 && (uVar2 < param_2)) &&
         (*(uint *)(param_1 + 100) <= param_2 - uVar2)))) &&
       ((*(uint *)(param_1 + 0x6c) == 0 ||
        (((uVar2 = *(uint *)(param_1 + 0x68), 0x6f < uVar2 && (uVar2 < param_2)) &&
         (*(uint *)(param_1 + 0x6c) <= param_2 - uVar2)))))) {
      uVar5 = '\x01';
    }
  }
  return uVar5;
}



===== PmWriteSnapshotData @ 140023104 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl PmWriteSnapshotData(struct _DEVICE_EXTENSION * __ptr64,struct
   _DRIVE_LAYOUT_INFORMATION_EX * __ptr64,struct _DISK_SNAPSHOT_DATA * __ptr64,unsigned long) */

long __cdecl
PmWriteSnapshotData(_DEVICE_EXTENSION *param_1,_DRIVE_LAYOUT_INFORMATION_EX *param_2,
                   _DISK_SNAPSHOT_DATA *param_3,ulong param_4)

{
  byte *pbVar1;
  int iVar2;
  longlong lVar3;
  void *_Dst;
  ulonglong uVar4;
  uint uVar5;
  undefined1 auStack_c8 [32];
  ulonglong *local_a8;
  ulonglong *local_a0;
  undefined8 *local_98;
  ulonglong local_88 [4];
  undefined8 local_68;
  undefined8 uStack_60;
  undefined4 local_58;
  undefined8 local_54;
  undefined8 uStack_4c;
  int local_44;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_c8;
  local_58 = 0;
  local_88[0] = 0;
  local_88[3] = 0;
  local_88[1] = 0;
  local_88[2] = 0;
  local_44 = 0;
  local_54 = 0;
  uStack_4c = 0;
  local_68 = 0;
  uStack_60 = 0;
  iVar2 = PmGetDriveGeometry(*(undefined8 *)(param_1 + 8),&local_58);
  if (-1 < iVar2) {
    if (*(int *)param_2 == 0) {
      local_88[0] = (ulonglong)(uint)(local_44 * 7);
      uVar5 = local_44 * 4;
      for (uVar4 = 0; (uint)uVar4 < *(uint *)(param_2 + 4); uVar4 = (ulonglong)((uint)uVar4 + 1)) {
        if ((param_2[uVar4 * 0x90 + 0x50] != (_DRIVE_LAYOUT_INFORMATION_EX)0x0) &&
           ((*(longlong *)(param_2 + uVar4 * 0x90 + 0x38) < (longlong)local_88[0] ||
            ((longlong)(*(longlong *)(param_2 + uVar4 * 0x90 + 0x38) - local_88[0]) <
             (longlong)(ulonglong)uVar5)))) goto LAB_14002320f;
      }
LAB_1400231be:
      if ((param_4 <= uVar5) &&
         (_Dst = (void *)ExAllocatePool2(0x40,uVar5,0x44536d50), _Dst != (void *)0x0)) {
        memmove(_Dst,param_3,(ulonglong)param_4);
        KeInitializeEvent(local_88 + 1,0,0);
        local_98 = &local_68;
        local_a0 = local_88 + 1;
        local_a8 = local_88;
        lVar3 = IoBuildSynchronousFsdRequest(4,*(undefined8 *)(param_1 + 8),_Dst,uVar5);
        if (lVar3 == 0) {
          iVar2 = -0x3fffff66;
        }
        else {
          pbVar1 = (byte *)(*(longlong *)(lVar3 + 0xb8) + -0x46);
          *pbVar1 = *pbVar1 | 0x12;
          iVar2 = IofCallDriver(*(undefined8 *)(param_1 + 8));
          if (iVar2 == 0x103) {
            local_a8 = (ulonglong *)0x0;
            KeWaitForSingleObject(local_88 + 1,0,0,0);
            iVar2 = (int)local_68;
          }
        }
        ExFreePoolWithTag(_Dst,0);
        return iVar2;
      }
      iVar2 = -0x3fffff66;
    }
    else {
      if (*(int *)param_2 == 1) {
        for (uVar4 = 0; (uint)uVar4 < *(uint *)(param_2 + 4); uVar4 = (ulonglong)((uint)uVar4 + 1))
        {
          lVar3 = *(longlong *)(param_2 + uVar4 * 0x90 + 0x50) + -0x4de84400caddebf1;
          if (lVar3 == 0) {
            lVar3 = *(longlong *)(param_2 + uVar4 * 0x90 + 0x58) + 0x30c33082eeedfc4f;
          }
          if (lVar3 == 0) {
            local_88[0] = *(ulonglong *)(param_2 + uVar4 * 0x90 + 0x38);
            uVar5 = *(uint *)(param_2 + uVar4 * 0x90 + 0x40);
            goto LAB_1400231be;
          }
        }
      }
LAB_14002320f:
      iVar2 = -0x3ffffddb;
    }
  }
  return iVar2;
}



===== PmGetSnapshotInfo @ 140023320 =====

uint PmGetSnapshotInfo(_DEVICE_EXTENSION *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint local_res10 [2];
  _DRIVE_LAYOUT_INFORMATION_EX *local_res18;
  longlong local_res20;
  
  *param_2 = 0;
  local_res18 = (_DRIVE_LAYOUT_INFORMATION_EX *)0x0;
  local_res10[0] = 0;
  local_res20 = 0;
  uVar3 = PmGetDriveLayoutEx(param_1,&local_res18);
  if (-1 < (int)uVar3) {
    uVar3 = PmGetSnapshotData(param_1,local_res18,&local_res20,local_res10);
    lVar2 = local_res20;
    if (-1 < (int)uVar3) {
      uVar4 = *(int *)(local_res20 + 0x6c) + 0x4c;
      if (uVar4 < 0x4c) {
        uVar3 = 0xc0000095;
      }
      else {
        uVar3 = 0;
        puVar5 = (undefined4 *)ExAllocatePool2(0x40,uVar4,0x44536d50);
        if (puVar5 == (undefined4 *)0x0) {
          uVar3 = 0xc000009a;
        }
        else {
          *puVar5 = 0x50;
          puVar5[1] = *(undefined4 *)(lVar2 + 0x14);
          uVar1 = *(undefined8 *)(lVar2 + 0x28);
          *(undefined8 *)(puVar5 + 2) = *(undefined8 *)(lVar2 + 0x20);
          *(undefined8 *)(puVar5 + 4) = uVar1;
          uVar1 = *(undefined8 *)(lVar2 + 0x38);
          *(undefined8 *)(puVar5 + 6) = *(undefined8 *)(lVar2 + 0x30);
          *(undefined8 *)(puVar5 + 8) = uVar1;
          uVar1 = *(undefined8 *)(lVar2 + 0x48);
          *(undefined8 *)(puVar5 + 10) = *(undefined8 *)(lVar2 + 0x40);
          *(undefined8 *)(puVar5 + 0xc) = uVar1;
          *(undefined8 *)(puVar5 + 0xe) = *(undefined8 *)(lVar2 + 0x50);
          puVar5[0x10] = *(undefined4 *)(lVar2 + 0x58);
          puVar5[0x11] = *(undefined4 *)(lVar2 + 0x5c);
          uVar4 = *(uint *)(lVar2 + 0x6c);
          puVar5[0x12] = uVar4;
          memmove(puVar5 + 0x13,(void *)((ulonglong)*(uint *)(lVar2 + 0x68) + lVar2),
                  (ulonglong)uVar4);
          *param_2 = puVar5;
        }
      }
    }
    if (lVar2 != 0) {
      ExFreePoolWithTag(lVar2,0);
    }
  }
  if (local_res18 != (_DRIVE_LAYOUT_INFORMATION_EX *)0x0) {
    ExFreePoolWithTag(local_res18,0);
  }
  return uVar3;
}



===== PmLookupId @ 14002345c =====

undefined8 PmLookupId(longlong param_1,void *param_2,ushort param_3)

{
  uint uVar1;
  int iVar2;
  ulonglong in_RAX;
  undefined4 extraout_var;
  longlong lVar3;
  uint uVar4;
  undefined1 uVar5;
  
  uVar1 = *(uint *)(param_1 + 8);
  lVar3 = param_1 + 0xc;
  uVar5 = 0;
  uVar4 = 0;
  do {
    if (uVar1 <= uVar4) {
LAB_1400234cc:
      return CONCAT71((int7)(in_RAX >> 8),uVar5);
    }
    if (((*(uint *)(lVar3 + 0xc) & 0xfffffffd) == 0) &&
       (((*(int *)(lVar3 + 4) - 1U < 3 || (*(int *)(lVar3 + 4) == 8)) &&
        (*(ushort *)(lVar3 + 8) == param_3)))) {
      iVar2 = memcmp((void *)(lVar3 + 0x10),param_2,(ulonglong)param_3);
      in_RAX = CONCAT44(extraout_var,iVar2);
      if (iVar2 == 0) {
        uVar5 = 1;
        goto LAB_1400234cc;
      }
    }
    in_RAX = (ulonglong)*(ushort *)(lVar3 + 10);
    lVar3 = lVar3 + in_RAX;
    uVar4 = uVar4 + 1;
  } while( true );
}



===== PmSetSnapshotInfo @ 1400234f0 =====

uint PmSetSnapshotInfo(_DEVICE_EXTENSION *param_1,longlong param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  longlong lVar7;
  uint uVar8;
  longlong lVar9;
  _DISK_SNAPSHOT_DATA *p_Var10;
  uint uVar11;
  void *_Src;
  uint uVar12;
  uint local_res18 [2];
  _DRIVE_LAYOUT_INFORMATION_EX *local_res20;
  longlong local_38 [2];
  
  local_res20 = (_DRIVE_LAYOUT_INFORMATION_EX *)0x0;
  local_res18[0] = 0;
  local_38[0] = 0;
  uVar8 = PmCreateSnapshotPartition(param_1);
  if ((int)uVar8 < 0) {
    return uVar8;
  }
  uVar8 = PmGetDriveLayoutEx(param_1,&local_res20);
  if ((int)uVar8 < 0) goto LAB_1400236e2;
  uVar8 = PmGetSnapshotData(param_1,local_res20,local_38,local_res18);
  lVar7 = local_38[0];
  if (-1 < (int)uVar8) {
    if (*(int *)(param_2 + 4) == 0) {
      _Src = (void *)0x0;
      uVar12 = 0;
      uVar11 = 0x70;
    }
    else {
      if (*(int *)(param_2 + 4) == 1) {
        if ((*(longlong *)(param_1 + 0xf8) == 0) ||
           (lVar9 = StRtlFindBestStorageDeviceId(*(longlong *)(param_1 + 0xf8)), lVar9 == 0)) {
          uVar8 = 0xc0000225;
          goto LAB_1400236cc;
        }
        uVar12 = (uint)*(ushort *)(lVar9 + 8);
        _Src = (void *)(lVar9 + 0x10);
      }
      else {
        uVar12 = *(uint *)(local_38[0] + 100);
        _Src = (void *)((ulonglong)*(uint *)(local_38[0] + 0x60) + local_38[0]);
      }
      uVar11 = uVar12 + 0x70;
      if (uVar11 < 0x70) {
        uVar8 = 0xc0000095;
        goto LAB_1400236cc;
      }
    }
    uVar1 = *(uint *)(param_2 + 0x48);
    uVar11 = uVar11 + uVar1;
    local_res18[0] = 0xffffffff;
    if (uVar11 >= uVar1) {
      local_res18[0] = uVar11;
    }
    uVar8 = -(uint)(uVar11 < uVar1) & 0xc0000095;
    if (uVar1 <= uVar11) {
      p_Var10 = (_DISK_SNAPSHOT_DATA *)ExAllocatePool2(0x42,local_res18[0],0x44536d50);
      uVar8 = local_res18[0];
      if (p_Var10 == (_DISK_SNAPSHOT_DATA *)0x0) {
        uVar8 = 0xc000009a;
      }
      else {
        PmInitializeSnapshotData(p_Var10,local_res18[0]);
        uVar3 = *(undefined8 *)(param_2 + 8);
        uVar4 = *(undefined8 *)(param_2 + 0x10);
        uVar5 = *(undefined8 *)(param_2 + 0x18);
        uVar6 = *(undefined8 *)(param_2 + 0x20);
        *(undefined4 *)(p_Var10 + 0x14) = *(undefined4 *)(param_2 + 4);
        *(undefined8 *)(p_Var10 + 0x50) = *(undefined8 *)(param_2 + 0x38);
        uVar2 = *(undefined4 *)(param_2 + 0x40);
        *(undefined8 *)(p_Var10 + 0x20) = uVar3;
        *(undefined8 *)(p_Var10 + 0x28) = uVar4;
        *(undefined4 *)(p_Var10 + 0x58) = uVar2;
        uVar3 = *(undefined8 *)(param_2 + 0x30);
        uVar2 = *(undefined4 *)(param_2 + 0x44);
        *(undefined8 *)(p_Var10 + 0x40) = *(undefined8 *)(param_2 + 0x28);
        *(undefined8 *)(p_Var10 + 0x48) = uVar3;
        *(uint *)(p_Var10 + 0xc) = uVar8;
        *(undefined8 *)(p_Var10 + 0x30) = uVar5;
        *(undefined8 *)(p_Var10 + 0x38) = uVar6;
        *(undefined4 *)(p_Var10 + 0x5c) = uVar2;
        *(undefined4 *)(p_Var10 + 0x60) = 0x70;
        *(uint *)(p_Var10 + 100) = uVar12;
        memmove(p_Var10 + 0x70,_Src,(ulonglong)uVar12);
        uVar11 = *(uint *)(param_2 + 0x48);
        *(uint *)(p_Var10 + 0x68) = *(int *)(p_Var10 + 100) + 0x70U;
        *(uint *)(p_Var10 + 0x6c) = uVar11;
        memmove(p_Var10 + (*(int *)(p_Var10 + 100) + 0x70U),(void *)(param_2 + 0x4c),
                (ulonglong)uVar11);
        uVar8 = PmSetSnapshotData(param_1,(SC_DISK_LAYOUT *)local_res20,p_Var10,uVar8);
        ExFreePoolWithTag(p_Var10,0);
      }
    }
  }
LAB_1400236cc:
  if (lVar7 != 0) {
    ExFreePoolWithTag(lVar7,0);
  }
LAB_1400236e2:
  if (local_res20 != (_DRIVE_LAYOUT_INFORMATION_EX *)0x0) {
    ExFreePoolWithTag(local_res20,0);
  }
  return uVar8;
}



===== ~PM_DRIVE @ 140023720 =====

/* public: virtual __cdecl PM_DRIVE::~PM_DRIVE(void) __ptr64 */

void __thiscall PM_DRIVE::~PM_DRIVE(PM_DRIVE *this)

{
  *(undefined ***)this = &_vftable_;
  SC_DRIVE::~SC_DRIVE((SC_DRIVE *)this);
  return;
}



===== Control @ 140023740 =====

/* public: virtual long __cdecl PM_DRIVE::Control(unsigned long,void * __ptr64,unsigned long,void *
   __ptr64,unsigned long) __ptr64 */

long __thiscall
PM_DRIVE::Control(PM_DRIVE *this,ulong param_1,void *param_2,ulong param_3,void *param_4,
                 ulong param_5)

{
  ulonglong uVar1;
  
  uVar1 = PmSendDeviceControl(*(undefined8 *)(*(longlong *)(this + 0x248) + 8),param_1,param_2,
                              param_3,param_4,param_5,0);
  return (long)uVar1;
}



===== Flush @ 140023778 =====

/* public: long __cdecl PM_DRIVE::Flush(void) __ptr64 */

long __thiscall PM_DRIVE::Flush(PM_DRIVE *this)

{
  byte *pbVar1;
  int iVar2;
  longlong lVar3;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_38 = 0;
  uStack_30 = 0;
  KeInitializeEvent(&local_28,0,0);
  lVar3 = IoBuildSynchronousFsdRequest
                    (9,*(undefined8 *)(*(longlong *)(this + 0x248) + 8),0,0,0,&local_28,&local_38);
  if (lVar3 == 0) {
    iVar2 = -0x3fffff66;
  }
  else {
    pbVar1 = (byte *)(*(longlong *)(lVar3 + 0xb8) + -0x46);
    *pbVar1 = *pbVar1 | 2;
    iVar2 = IofCallDriver(*(undefined8 *)(*(longlong *)(this + 0x248) + 8),lVar3);
    if (iVar2 == 0x103) {
      KeWaitForSingleObject(&local_28,0,0,0,0);
      iVar2 = (int)local_38;
    }
  }
  return iVar2;
}



===== Io @ 140023850 =====

/* public: virtual void __cdecl PM_DRIVE::Io(class SC_PACKET * __ptr64,unsigned __int64) __ptr64 */

void __thiscall PM_DRIVE::Io(PM_DRIVE *this,SC_PACKET *param_1,__uint64 param_2)

{
  return;
}



===== Read @ 140023860 =====

/* public: virtual long __cdecl PM_DRIVE::Read(unsigned __int64,unsigned long,unsigned char *
   __ptr64) __ptr64 */

long __thiscall PM_DRIVE::Read(PM_DRIVE *this,__uint64 param_1,ulong param_2,uchar *param_3)

{
  byte *pbVar1;
  int iVar2;
  longlong lVar3;
  __uint64 local_res8;
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
  local_res8 = param_1;
  KeInitializeEvent(&local_28,0,0);
  lVar3 = IoBuildSynchronousFsdRequest
                    (3,*(undefined8 *)(*(longlong *)(this + 0x248) + 8),param_3,param_2,&local_res8,
                     &local_28,&local_38);
  if (lVar3 == 0) {
    iVar2 = -0x3fffff66;
  }
  else {
    pbVar1 = (byte *)(*(longlong *)(lVar3 + 0xb8) + -0x46);
    *pbVar1 = *pbVar1 | 2;
    iVar2 = IofCallDriver(*(undefined8 *)(*(longlong *)(this + 0x248) + 8),lVar3);
    if (iVar2 == 0x103) {
      KeWaitForSingleObject(&local_28,0,0,0,0);
      iVar2 = (int)local_38;
    }
  }
  return iVar2;
}



===== Write @ 140023960 =====

/* public: virtual long __cdecl PM_DRIVE::Write(unsigned __int64,unsigned long,unsigned char *
   __ptr64) __ptr64 */

long __thiscall PM_DRIVE::Write(PM_DRIVE *this,__uint64 param_1,ulong param_2,uchar *param_3)

{
  byte *pbVar1;
  int iVar2;
  longlong lVar3;
  __uint64 local_res8;
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
  local_res8 = param_1;
  KeInitializeEvent(&local_28,0,0);
  lVar3 = IoBuildSynchronousFsdRequest
                    (4,*(undefined8 *)(*(longlong *)(this + 0x248) + 8),param_3,param_2,&local_res8,
                     &local_28,&local_38);
  if (lVar3 == 0) {
    iVar2 = -0x3fffff66;
  }
  else {
    pbVar1 = (byte *)(*(longlong *)(lVar3 + 0xb8) + -0x46);
    *pbVar1 = *pbVar1 | 0x12;
    iVar2 = IofCallDriver(*(undefined8 *)(*(longlong *)(this + 0x248) + 8),lVar3);
    if (iVar2 == 0x103) {
      KeWaitForSingleObject(&local_28,0,0,0,0);
      iVar2 = (int)local_38;
    }
  }
  return iVar2;
}



===== PmCreateSpacesMetadata @ 140023a5c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long PmCreateSpacesMetadata
               (_DEVICE_EXTENSION *param_1,longlong param_2,undefined8 param_3,__uint64 param_4)

{
  byte bVar1;
  long lVar2;
  undefined1 auStack_2e8 [32];
  uchar in_stack_fffffffffffffd38;
  ushort local_2b8 [2];
  undefined8 local_2b4;
  undefined8 uStack_2ac;
  undefined8 local_2a4;
  undefined8 uStack_29c;
  undefined2 local_294;
  undefined8 local_290;
  undefined8 uStack_288;
  undefined8 local_280;
  undefined8 local_278;
  undefined **local_268 [73];
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_2e8;
  SC_DRIVE::SC_DRIVE((SC_DRIVE *)local_268);
  local_20 = 0;
  local_268[0] = &PM_DRIVE::_vftable_;
  memset(local_2b8,0,0x48);
  if (*(uint *)(param_2 + 4) < 0x1e) {
    lVar2 = PM_DRIVE::Initialize((PM_DRIVE *)local_268,param_1);
    if (-1 < lVar2) {
      bVar1 = ScGetDriveHeaderVersion(*(_SC_VERSION *)(param_2 + 4));
      local_2b4 = *(undefined8 *)(param_2 + 0x208);
      uStack_2ac = *(undefined8 *)(param_2 + 0x210);
      local_294 = *(undefined2 *)(param_2 + 0x228);
      local_2a4 = *(undefined8 *)(param_2 + 0x218);
      uStack_29c = *(undefined8 *)(param_2 + 0x220);
      local_280 = *(undefined8 *)(param_2 + 0x250);
      local_290 = *(undefined8 *)(param_2 + 0x23c);
      uStack_288 = *(undefined8 *)(param_2 + 0x244);
      local_278 = *(undefined8 *)(param_2 + 600);
      local_2b8[0] = (ushort)bVar1;
      lVar2 = SC_DRIVE::CreateMetadata
                        ((SC_DRIVE *)local_268,(ushort *)(param_2 + 8),(SC_DRIVE_HEADER *)local_2b8,
                         param_4,in_stack_fffffffffffffd38);
      if (-1 < lVar2) {
        lVar2 = SC_DISK::UpdateControl((SC_DISK *)local_268);
        if (-1 < lVar2) {
          lVar2 = PM_DRIVE::Flush((PM_DRIVE *)local_268);
        }
      }
    }
  }
  else {
    lVar2 = -0x3f18ffeb;
  }
  local_268[0] = &PM_DRIVE::_vftable_;
  SC_DRIVE::~SC_DRIVE((SC_DRIVE *)local_268);
  return lVar2;
}



===== PmDeleteSpacesMetadata @ 140023bb0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long PmDeleteSpacesMetadata(_DEVICE_EXTENSION *param_1)

{
  long lVar1;
  undefined1 auStack_288 [32];
  undefined **local_268 [73];
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_288;
  SC_DRIVE::SC_DRIVE((SC_DRIVE *)local_268);
  local_20 = 0;
  local_268[0] = &PM_DRIVE::_vftable_;
  lVar1 = PM_DRIVE::Initialize((PM_DRIVE *)local_268,param_1);
  if (-1 < lVar1) {
    lVar1 = SC_DRIVE::DeleteMetadata((SC_DRIVE *)local_268);
    if (-1 < lVar1) {
      lVar1 = SC_DISK::UpdateControl((SC_DISK *)local_268);
      if (-1 < lVar1) {
        lVar1 = PM_DRIVE::Flush((PM_DRIVE *)local_268);
      }
    }
  }
  local_268[0] = &PM_DRIVE::_vftable_;
  SC_DRIVE::~SC_DRIVE((SC_DRIVE *)local_268);
  return lVar1;
}



===== PmCollectTelemetry @ 140023c6c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PmCollectTelemetry(_DEVICE_EXTENSION *param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  char cVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  int iVar7;
  long lVar8;
  uint uVar9;
  undefined4 *puVar10;
  _UNICODE_STRING *p_Var11;
  undefined4 *puVar12;
  ulonglong uVar13;
  undefined8 *puVar14;
  __uint64 _Var15;
  _DEVICE_EXTENSION *p_Var16;
  undefined8 *puVar17;
  longlong lVar18;
  undefined4 *puVar19;
  longlong lVar20;
  ulonglong uVar21;
  ulonglong uVar22;
  uint uVar23;
  undefined1 auStackY_238 [32];
  undefined8 local_1f8;
  undefined **local_1e8 [29];
  uint local_fc;
  byte local_f8;
  longlong local_f0;
  undefined8 *local_e0;
  undefined8 local_60;
  undefined8 local_58;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_238;
  SC_DISK::SC_DISK((SC_DISK *)local_1e8);
  local_1e8[0] = &PM_DISK::_vftable_;
  local_60 = 0;
  local_58 = 0;
  lVar20 = *(longlong *)(PmControlObject + 0x40);
  *param_2 = 0;
  local_1f8 = 0;
  if ((((*(wchar_t **)(param_1 + 0x160) == (wchar_t *)0x0) || (*(longlong *)(param_1 + 0x170) == 0))
      || (iVar7 = wcsncmp(*(wchar_t **)(param_1 + 0x160),L"MSFT",4), iVar7 != 0)) ||
     (iVar7 = wcsncmp(*(wchar_t **)(param_1 + 0x170),L"XVSC",4), iVar7 != 0)) {
    puVar10 = (undefined4 *)ExAllocatePool2(0x40,*(int *)(param_1 + 0x394) * 4 + 0x1f8,0x42546d50);
    if (puVar10 == (undefined4 *)0x0) {
      uVar21 = 0xc000009a;
    }
    else {
      if ((*(uint *)(param_1 + 0x200) & 0x10) == 0) {
        uVar21 = Feature_Partition_Manager_Passthrough__private_IsEnabledDeviceUsageNoInline();
        if (((int)uVar21 == 0) || (((byte)param_1[0x210] & 0x40) == 0)) {
          uVar23 = PmGetDriveLayoutEx(param_1,(undefined8 *)(puVar10 + 0x6a));
          if ((int)uVar23 < 0) {
            puVar10[0x66] = *(undefined4 *)(param_1 + 0x390);
            puVar10[0x67] = *(undefined4 *)(param_1 + 0x394);
          }
          else {
            puVar12 = *(undefined4 **)(puVar10 + 0x6a);
            puVar10[0x66] = *puVar12;
            puVar10[0x67] = puVar12[1];
            iVar7 = puVar12[1];
            *(ulonglong *)(puVar10 + 0x2e) = *(ulonglong *)(puVar10 + 0x2e) | 0x8000;
            puVar10[0x68] = iVar7 * 0x90 + 0x30;
          }
          lVar8 = PM_DISK::Initialize((PM_DISK *)local_1e8,*(_DEVICE_OBJECT **)(param_1 + 8),
                                      *(char *)(lVar20 + 0xa9) == '\0');
          if (-1 < lVar8) {
            puVar10[0x10] = local_fc;
            *(longlong *)(puVar10 + 0x12) = local_f0 << (local_f8 & 0x3f);
          }
        }
      }
      else {
        *(ulonglong *)(puVar10 + 0x2e) = *(ulonglong *)(puVar10 + 0x2e) | 0x10000;
      }
      lVar18 = 4;
      *puVar10 = *(undefined4 *)(param_1 + 0xa8);
      uVar2 = *(undefined8 *)(param_1 + 0x220);
      uVar5 = *(undefined8 *)(param_1 + 0x228);
      lVar20 = *(longlong *)(param_1 + 0xe8);
      puVar10[1] = *(undefined4 *)(*(longlong *)(param_1 + 8) + 0x30);
      uVar4 = *(undefined4 *)(*(longlong *)(param_1 + 8) + 0x34);
      *(_DEVICE_EXTENSION *)(puVar10 + 3) = param_1[0x25c];
      puVar10[4] = *(undefined4 *)(param_1 + 0x250);
      puVar10[5] = *(undefined4 *)(param_1 + 0x254);
      puVar10[6] = *(undefined4 *)(param_1 + 600);
      puVar10[7] = *(undefined4 *)(param_1 + 0x204);
      *(undefined8 *)(puVar10 + 8) = *(undefined8 *)(param_1 + 0x210);
      *(undefined8 *)(puVar10 + 10) = *(undefined8 *)(param_1 + 0x218);
      puVar10[2] = uVar4;
      p_Var16 = param_1 + 0x158;
      *(undefined8 *)(puVar10 + 0xc) = uVar2;
      *(undefined8 *)(puVar10 + 0xe) = uVar5;
      puVar10[0x14] = *(undefined4 *)(lVar20 + 0x1c);
      puVar14 = (undefined8 *)(puVar10 + 0x16);
      do {
        *puVar14 = p_Var16;
        p_Var16 = p_Var16 + 0x10;
        puVar14 = puVar14 + 1;
        lVar18 = lVar18 + -1;
      } while (lVar18 != 0);
      uVar5 = *(undefined8 *)(param_1 + 0x198);
      uVar6 = *(undefined8 *)(param_1 + 0x1a0);
      puVar10[0x2a] = *(undefined4 *)(param_1 + 0x1b0);
      uVar2 = *(undefined8 *)(param_1 + 0x1a8);
      puVar10[0x2b] = *(undefined4 *)(param_1 + 0x1b4);
      puVar10[0x2c] = *(undefined4 *)(param_1 + 0x1b8);
      *(undefined8 *)(puVar10 + 0x24) = uVar5;
      *(undefined8 *)(puVar10 + 0x26) = uVar6;
      *(_UNICODE_STRING **)(puVar10 + 0x1e) = (_UNICODE_STRING *)(param_1 + 0x1c0);
      *(undefined8 *)(puVar10 + 0x28) = uVar2;
      p_Var11 = &NullString;
      if (*(int *)(lVar20 + 0x1c) != 0xf) {
        p_Var11 = (_UNICODE_STRING *)(param_1 + 0x1c0);
      }
      *(_UNICODE_STRING **)(puVar10 + 0x20) = p_Var11;
      *(_DEVICE_EXTENSION **)(puVar10 + 0x22) = param_1 + 0x1d0;
      puVar10[0x30] = *(undefined4 *)(param_1 + 0xac);
      if ((*(longlong *)(param_1 + 0xb8) != 0) || (*(longlong *)(param_1 + 0xc0) != 0)) {
        uVar2 = *(undefined8 *)(param_1 + 0xb8);
        uVar5 = *(undefined8 *)(param_1 + 0xc0);
        *(ulonglong *)(puVar10 + 0x2e) = *(ulonglong *)(puVar10 + 0x2e) | 1;
        *(undefined8 *)(puVar10 + 0x31) = uVar2;
        *(undefined8 *)(puVar10 + 0x33) = uVar5;
      }
      if ((*(longlong *)(param_1 + 200) != 0) || (*(longlong *)(param_1 + 0xd0) != 0)) {
        uVar2 = *(undefined8 *)(param_1 + 200);
        uVar5 = *(undefined8 *)(param_1 + 0xd0);
        *(ulonglong *)(puVar10 + 0x2e) = *(ulonglong *)(puVar10 + 0x2e) | 2;
        *(undefined8 *)(puVar10 + 0x35) = uVar2;
        *(undefined8 *)(puVar10 + 0x37) = uVar5;
      }
      uVar2 = *(undefined8 *)(param_1 + 0xe0);
      *(undefined8 *)(puVar10 + 0x39) = *(undefined8 *)(param_1 + 0xd8);
      *(undefined8 *)(puVar10 + 0x3b) = uVar2;
      if (puVar10[0x14] == 0x10) {
        uVar2 = *(undefined8 *)(*(longlong *)(param_1 + 0xe8) + 0x2c);
        *(undefined8 *)(puVar10 + 0x3d) = *(undefined8 *)(*(longlong *)(param_1 + 0xe8) + 0x24);
        *(undefined8 *)(puVar10 + 0x3f) = uVar2;
      }
      lVar20 = *(longlong *)(param_1 + 0xf0);
      if (lVar20 != 0) {
        *(ulonglong *)(puVar10 + 0x2e) = *(ulonglong *)(puVar10 + 0x2e) | 4;
        *(byte *)(puVar10 + 0x41) = *(byte *)(lVar20 + 8) & 1;
        *(undefined1 *)((longlong)puVar10 + 0x105) = *(undefined1 *)(lVar20 + 9);
      }
      lVar20 = *(longlong *)(param_1 + 0xf8);
      if (lVar20 != 0) {
        *(ulonglong *)(puVar10 + 0x2e) = *(ulonglong *)(puVar10 + 0x2e) | 8;
        puVar12 = (undefined4 *)StRtlFindBestStorageDeviceId(lVar20);
        if ((((puVar12 != (undefined4 *)0x0) ||
             ((*(int *)(lVar20 + 8) != 0 &&
              (puVar12 = (undefined4 *)(lVar20 + 0xc), puVar12 != (undefined4 *)0x0)))) &&
            (puVar19 = (undefined4 *)
                       ((ulonglong)*(ushort *)(puVar12 + 2) + 0x10 + (longlong)puVar12),
            puVar19 <= (undefined4 *)((ulonglong)*(uint *)(lVar20 + 4) + lVar20))) &&
           ((puVar12 + 4 <= puVar19 && (puVar12 != (undefined4 *)0x0)))) {
          puVar10[0x42] = *(undefined4 *)(lVar20 + 8);
          puVar10[0x43] = *puVar12;
          puVar10[0x44] = puVar12[1];
          puVar10[0x45] = puVar12[3];
          *(undefined4 **)(puVar10 + 0x46) = puVar12 + 4;
          puVar10[0x48] = (uint)*(ushort *)(puVar12 + 2);
        }
      }
      lVar20 = *(longlong *)(param_1 + 0x100);
      if (lVar20 != 0) {
        *(ulonglong *)(puVar10 + 0x2e) = *(ulonglong *)(puVar10 + 0x2e) | 0x10;
        puVar10[0x49] = *(undefined4 *)(lVar20 + 8);
        puVar10[0x4a] = *(undefined4 *)(lVar20 + 0xc);
        puVar10[0x4b] = *(undefined4 *)(lVar20 + 0x10);
        puVar10[0x4c] = *(undefined4 *)(lVar20 + 0x14);
        *(undefined1 *)(puVar10 + 0x4d) = *(undefined1 *)(lVar20 + 0x18);
        *(undefined1 *)((longlong)puVar10 + 0x135) = *(undefined1 *)(lVar20 + 0x19);
        *(undefined1 *)((longlong)puVar10 + 0x136) = *(undefined1 *)(lVar20 + 0x1a);
      }
      lVar20 = *(longlong *)(param_1 + 0x108);
      if (lVar20 != 0) {
        *(ulonglong *)(puVar10 + 0x2e) = *(ulonglong *)(puVar10 + 0x2e) | 0x20;
        puVar10[0x4e] = *(undefined4 *)(lVar20 + 0x10);
        puVar10[0x4f] = *(undefined4 *)(lVar20 + 0x14);
        puVar10[0x50] = *(undefined4 *)(lVar20 + 0x18);
      }
      lVar20 = *(longlong *)(param_1 + 0x110);
      if (lVar20 != 0) {
        *(ulonglong *)(puVar10 + 0x2e) = *(ulonglong *)(puVar10 + 0x2e) | 0x40;
        *(undefined1 *)(puVar10 + 0x51) = *(undefined1 *)(lVar20 + 8);
      }
      lVar20 = *(longlong *)(param_1 + 0x118);
      if (lVar20 != 0) {
        *(ulonglong *)(puVar10 + 0x2e) = *(ulonglong *)(puVar10 + 0x2e) | 0x80;
        *(undefined1 *)((longlong)puVar10 + 0x145) = *(undefined1 *)(lVar20 + 8);
      }
      lVar20 = *(longlong *)(param_1 + 0x120);
      if (lVar20 != 0) {
        *(ulonglong *)(puVar10 + 0x2e) = *(ulonglong *)(puVar10 + 0x2e) | 0x100;
        *(byte *)((longlong)puVar10 + 0x146) = *(byte *)(lVar20 + 8) & 1;
        *(undefined8 *)(puVar10 + 0x52) = *(undefined8 *)(lVar20 + 0x10);
        if ((*(byte *)(lVar20 + 8) & 0x20) != 0) {
          *(undefined8 *)(puVar10 + 0x54) = *(undefined8 *)(lVar20 + 0x18);
        }
      }
      lVar20 = *(longlong *)(param_1 + 0x128);
      if (lVar20 != 0) {
        *(ulonglong *)(puVar10 + 0x2e) = *(ulonglong *)(puVar10 + 0x2e) | 0x200;
        puVar10[0x56] = *(undefined4 *)(lVar20 + 0xc);
        puVar10[0x57] = *(undefined4 *)(lVar20 + 0x10);
        puVar10[0x58] = *(undefined4 *)(lVar20 + 0x14);
        puVar10[0x59] = *(undefined4 *)(lVar20 + 0x18);
        puVar10[0x5a] = *(undefined4 *)(lVar20 + 0x1c);
      }
      lVar20 = *(longlong *)(param_1 + 0x138);
      if (lVar20 != 0) {
        *(ulonglong *)(puVar10 + 0x2e) = *(ulonglong *)(puVar10 + 0x2e) | 0x400;
        *(undefined1 *)(puVar10 + 0x5b) = *(undefined1 *)(lVar20 + 0x48);
        *(ulonglong *)(puVar10 + 0x5c) =
             (ulonglong)(uint)puVar10[0x10] * *(longlong *)(lVar20 + 0x60);
      }
      lVar20 = *(longlong *)(param_1 + 0x140);
      if (lVar20 != 0) {
        *(ulonglong *)(puVar10 + 0x2e) = *(ulonglong *)(puVar10 + 0x2e) | 0x800;
        puVar10[0x5e] = *(undefined4 *)(lVar20 + 8);
        puVar10[0x5f] = *(undefined4 *)(lVar20 + 0xc);
        puVar10[0x60] = *(undefined4 *)(lVar20 + 0x10);
      }
      lVar20 = *(longlong *)(param_1 + 0x148);
      if (lVar20 != 0) {
        *(ulonglong *)(puVar10 + 0x2e) = *(ulonglong *)(puVar10 + 0x2e) | 0x1000;
        *(longlong *)(puVar10 + 0x62) = lVar20 + 8;
      }
      lVar20 = *(longlong *)(param_1 + 0x150);
      if (lVar20 != 0) {
        *(ulonglong *)(puVar10 + 0x2e) = *(ulonglong *)(puVar10 + 0x2e) | 0x2000;
        puVar10[100] = *(undefined4 *)(lVar20 + 8);
      }
      uVar13 = PmSendDeviceControl(*(undefined8 *)(param_1 + 0x10),0x2d0c14,0,0,&local_1f8,8,0);
      uVar21 = uVar13 & 0xffffffff;
      if ((int)uVar13 < 0) {
        uVar21 = 0;
      }
      else {
        *(ulonglong *)(puVar10 + 0x2e) = *(ulonglong *)(puVar10 + 0x2e) | 0x4000;
        *(undefined1 *)(puVar10 + 0x65) = local_1f8._6_1_;
      }
      if (local_e0 != (undefined8 *)0x0) {
        puVar14 = (undefined8 *)ExAllocatePool2(0x42,0x200,0x42546d50);
        *(undefined8 **)(puVar10 + 0x6c) = puVar14;
        if (puVar14 != (undefined8 *)0x0) {
          lVar20 = 4;
          puVar17 = local_e0;
          do {
            uVar2 = puVar17[1];
            *puVar14 = *puVar17;
            puVar14[1] = uVar2;
            uVar2 = puVar17[3];
            puVar14[2] = puVar17[2];
            puVar14[3] = uVar2;
            uVar2 = puVar17[5];
            puVar14[4] = puVar17[4];
            puVar14[5] = uVar2;
            uVar2 = puVar17[7];
            puVar14[6] = puVar17[6];
            puVar14[7] = uVar2;
            uVar2 = puVar17[9];
            puVar14[8] = puVar17[8];
            puVar14[9] = uVar2;
            uVar2 = puVar17[0xb];
            puVar14[10] = puVar17[10];
            puVar14[0xb] = uVar2;
            uVar2 = puVar17[0xd];
            puVar14[0xc] = puVar17[0xc];
            puVar14[0xd] = uVar2;
            puVar1 = puVar17 + 0xe;
            uVar2 = puVar17[0xf];
            puVar17 = puVar17 + 0x10;
            puVar14[0xe] = *puVar1;
            puVar14[0xf] = uVar2;
            lVar20 = lVar20 + -1;
            puVar14 = puVar14 + 0x10;
          } while (lVar20 != 0);
          puVar10[0x6e] = 0x200;
        }
        if ((puVar10[0x66] == 0) && (lVar20 = *(longlong *)(puVar10 + 0x6a), lVar20 != 0)) {
          uVar13 = 0;
          uVar23 = 0;
          if (*(int *)(lVar20 + 4) != 0) {
            do {
              if (3 < uVar23) break;
              if ((*(longlong *)(lVar20 + 0x40 + uVar13 * 0x90) != 0) &&
                 ((cVar3 = *(char *)(lVar20 + 0x50 + uVar13 * 0x90), cVar3 == '\x05' ||
                  (cVar3 == '\x0f')))) {
                _Var15 = *(__uint64 *)(lVar20 + 0x38 + uVar13 * 0x90);
                uVar22 = (ulonglong)uVar23;
                uVar23 = uVar23 + 1;
                if (local_fc != 0) {
                  _Var15 = (longlong)_Var15 / (longlong)(ulonglong)local_fc;
                }
                uVar9 = SC_DISK::ReadSectors((SC_DISK *)local_1e8,1,_Var15,(void *)0x0);
                uVar21 = (ulonglong)uVar9;
                if (-1 < (int)uVar9) {
                  puVar14 = (undefined8 *)ExAllocatePool2(0x42,0x200,0x42546d50);
                  *(undefined8 **)(puVar10 + uVar22 * 2 + 0x70) = puVar14;
                  if (puVar14 != (undefined8 *)0x0) {
                    lVar20 = 4;
                    puVar17 = local_e0;
                    do {
                      uVar2 = puVar17[1];
                      *puVar14 = *puVar17;
                      puVar14[1] = uVar2;
                      uVar2 = puVar17[3];
                      puVar14[2] = puVar17[2];
                      puVar14[3] = uVar2;
                      uVar2 = puVar17[5];
                      puVar14[4] = puVar17[4];
                      puVar14[5] = uVar2;
                      uVar2 = puVar17[7];
                      puVar14[6] = puVar17[6];
                      puVar14[7] = uVar2;
                      uVar2 = puVar17[9];
                      puVar14[8] = puVar17[8];
                      puVar14[9] = uVar2;
                      uVar2 = puVar17[0xb];
                      puVar14[10] = puVar17[10];
                      puVar14[0xb] = uVar2;
                      uVar2 = puVar17[0xd];
                      puVar14[0xc] = puVar17[0xc];
                      puVar14[0xd] = uVar2;
                      puVar1 = puVar17 + 0xe;
                      uVar2 = puVar17[0xf];
                      puVar17 = puVar17 + 0x10;
                      puVar14[0xe] = *puVar1;
                      puVar14[0xf] = uVar2;
                      lVar20 = lVar20 + -1;
                      puVar14 = puVar14 + 0x10;
                    } while (lVar20 != 0);
                    puVar10[uVar22 + 0x78] = 0x200;
                  }
                }
              }
              lVar20 = *(longlong *)(puVar10 + 0x6a);
              uVar9 = (int)uVar13 + 1;
              uVar13 = (ulonglong)uVar9;
            } while (uVar9 < *(uint *)(lVar20 + 4));
          }
        }
      }
      for (p_Var16 = *(_DEVICE_EXTENSION **)(param_1 + 0x380); p_Var16 != param_1 + 0x380;
          p_Var16 = *(_DEVICE_EXTENSION **)p_Var16) {
        if ((*(uint *)(p_Var16 + -0x68) & 0x40) != 0) {
          if (puVar10[0x7c] == *(uint *)(param_1 + 0x394)) break;
          puVar10[(ulonglong)(uint)puVar10[0x7c] + 0x7d] = *(undefined4 *)(p_Var16 + 0x30);
          puVar10[0x7c] = puVar10[0x7c] + 1;
        }
      }
      *param_2 = puVar10;
    }
  }
  else {
    uVar21 = 0xc00000bb;
  }
  PM_DISK::~PM_DISK((PM_DISK *)local_1e8);
  return uVar21;
}



===== PmFreeTelemetry @ 1400244f0 =====

void PmFreeTelemetry(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  
  plVar2 = (longlong *)(param_1 + 0x1c0);
  lVar1 = 4;
  do {
    if (*plVar2 != 0) {
      ExFreePoolWithTag(*plVar2,0);
    }
    plVar2 = plVar2 + 1;
    lVar1 = lVar1 + -1;
  } while (lVar1 != 0);
  if (*(longlong *)(param_1 + 0x1b0) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x1b0),0);
  }
  if (*(longlong *)(param_1 + 0x1a8) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x1a8),0);
  }
  ExFreePoolWithTag(param_1,0);
  return;
}



===== PmDiskRedirect @ 14002458c =====

/* long __cdecl PmDiskRedirect(struct _DEVICE_EXTENSION * __ptr64,struct _IRP * __ptr64,void *
   __ptr64,__int64,unsigned long) */

long __cdecl
PmDiskRedirect(_DEVICE_EXTENSION *param_1,_IRP *param_2,void *param_3,__int64 param_4,ulong param_5)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  int iVar7;
  longlong lVar8;
  longlong lVar9;
  
  lVar8 = IoMakeAssociatedIrp(param_2,*(char *)(*(longlong *)(param_1 + 0x10) + 0x4c) + '\x01');
  if (lVar8 == 0) {
    iVar7 = -0x3fffff66;
  }
  else {
    lVar9 = IoAllocateMdl(param_3,param_5,0,0,lVar8);
    if (lVar9 == 0) {
      iVar7 = -0x3fffff66;
    }
    else {
      IoBuildPartialMdl(*(undefined8 *)(param_2 + 8),lVar9,param_3,param_5);
      puVar1 = *(undefined8 **)(param_2 + 0xb8);
      lVar2 = *(longlong *)(lVar8 + 0xb8);
      uVar6 = puVar1[1];
      *(undefined8 *)(lVar2 + -0x48) = *puVar1;
      *(undefined8 *)(lVar2 + -0x40) = uVar6;
      uVar6 = puVar1[3];
      *(undefined8 *)(lVar2 + -0x38) = puVar1[2];
      *(undefined8 *)(lVar2 + -0x30) = uVar6;
      uVar3 = *(undefined4 *)((longlong)puVar1 + 0x24);
      uVar4 = *(undefined4 *)(puVar1 + 5);
      uVar5 = *(undefined4 *)((longlong)puVar1 + 0x2c);
      *(undefined4 *)(lVar2 + -0x28) = *(undefined4 *)(puVar1 + 4);
      *(undefined4 *)(lVar2 + -0x24) = uVar3;
      *(undefined4 *)(lVar2 + -0x20) = uVar4;
      *(undefined4 *)(lVar2 + -0x1c) = uVar5;
      *(undefined8 *)(lVar2 + -0x18) = puVar1[6];
      *(ulong *)(lVar2 + -0x40) = param_5;
      *(__int64 *)(lVar2 + -0x30) = param_4;
      *(char *)(lVar8 + 0x43) = *(char *)(lVar8 + 0x43) + -1;
      *(longlong *)(lVar8 + 0xb8) = *(longlong *)(lVar8 + 0xb8) + -0x48;
      iVar7 = IoPropagateIrpExtensionEx
                        (param_2,lVar8,
                         (longlong)param_3 +
                         (-*(longlong *)(*(longlong *)(param_2 + 8) + 0x20) -
                         (ulonglong)*(uint *)(*(longlong *)(param_2 + 8) + 0x2c)),0xffffffff);
      if (-1 < iVar7) {
        IoForwardIrpSynchronously(*(undefined8 *)(param_1 + 0x10),lVar8);
        iVar7 = *(int *)(lVar8 + 0x30);
        if (-1 < iVar7) {
          LOCK();
          *(int *)(param_2 + 0x38) = *(int *)(param_2 + 0x38) + *(int *)(lVar8 + 0x38);
          UNLOCK();
        }
      }
      IoFreeMdl(lVar9);
    }
    IoFreeIrp(lVar8);
  }
  return iVar7;
}



===== PmSetVolumeManagerAltitude @ 140024704 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl PmSetVolumeManagerAltitude(struct _VOLUME_MANAGER * __ptr64) */

long __cdecl PmSetVolumeManagerAltitude(_VOLUME_MANAGER *param_1)

{
  longlong lVar1;
  int iVar2;
  undefined1 auStack_c8 [32];
  undefined8 *local_a8;
  undefined4 *local_a0;
  undefined4 *local_98;
  undefined4 *local_90;
  undefined4 local_88;
  undefined4 local_84;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined4 *puStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined *local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined1 local_30 [4];
  int local_2c;
  int local_28;
  uint local_24;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_c8;
  local_78 = 0;
  local_84 = 0;
  lVar1 = *(longlong *)(PmControlObject + 0x40);
  local_80 = 0;
  local_90 = &local_84;
  local_88 = 0;
  local_98 = &local_88;
  local_a0 = (undefined4 *)0x0;
  local_a8 = (undefined8 *)((ulonglong)local_a8 & 0xffffffff00000000);
  local_70 = 0;
  puStack_68 = (undefined4 *)0x0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = (undefined *)0x0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  iVar2 = IoGetDevicePropertyData
                    (*(undefined8 *)(*(longlong *)(param_1 + 0x30) + 8),&DEVPKEY_Device_Service,0,0)
  ;
  if (iVar2 == -0x3fffffdd) {
    puStack_68 = (undefined4 *)ExAllocatePool2(0x40,local_88,0x45566d50);
    if (puStack_68 == (undefined4 *)0x0) {
      iVar2 = -0x3fffff66;
      goto LAB_140024931;
    }
    local_70 = CONCAT62(CONCAT42(local_70._4_4_,(short)local_88),(short)local_88 + -2);
    local_90 = &local_84;
    local_98 = &local_88;
    local_a8 = (undefined8 *)CONCAT44(local_a8._4_4_,local_88);
    local_a0 = puStack_68;
    iVar2 = IoGetDevicePropertyData
                      (*(undefined8 *)(*(longlong *)(param_1 + 0x30) + 8),&DEVPKEY_Device_Service,0,
                       0);
  }
  if (-1 < iVar2) {
    local_a8 = &local_80;
    iVar2 = IoOpenDriverRegistryKey(*(undefined8 *)(lVar1 + 8),0,0x20019,0);
    if (-1 < iVar2) {
      uStack_58 = local_80;
      local_60 = CONCAT44(local_60._4_4_,0x30);
      local_50 = &VolmgrAltitudes;
      uStack_48 = CONCAT44(uStack_48._4_4_,0x240);
      local_40 = 0;
      uStack_38 = 0;
      iVar2 = ZwOpenKey(&local_78,0x20019,&local_60);
      ZwClose(local_80);
      if (-1 < iVar2) {
        local_a0 = &local_88;
        local_a8 = (undefined8 *)CONCAT44(local_a8._4_4_,0x10);
        iVar2 = ZwQueryValueKey(local_78,&local_70,2,local_30);
        ZwClose(local_78);
        if (((iVar2 < 0) || (local_2c != 4)) || (local_28 != 4)) {
          local_24 = 0x1f;
        }
        *(uint *)(param_1 + 0x38) = local_24;
        if (0x20 < local_24) {
          *(undefined4 *)(param_1 + 0x38) = 0x1f;
        }
      }
    }
  }
LAB_140024931:
  if (puStack_68 != (undefined4 *)0x0) {
    ExFreePoolWithTag(puStack_68,0);
  }
  return iVar2;
}



===== PmVolumeManagerNotification @ 140024980 =====

long PmVolumeManagerNotification(longlong param_1,_CONTROL_EXTENSION *param_2)

{
  char cVar1;
  long lVar2;
  longlong lVar3;
  undefined8 uVar4;
  _CONTROL_EXTENSION *p_Var5;
  _CONTROL_EXTENSION *p_Var6;
  
  lVar2 = 0;
  KeWaitForSingleObject(param_2 + 0x10,0,0,0,0);
  lVar3 = *(longlong *)(param_1 + 4) + -0x11d046f0cb3a4004;
  if (lVar3 == 0) {
    lVar3 = *(longlong *)(param_1 + 0xc) + -0x3f05139760008fb0;
  }
  if (lVar3 == 0) {
    for (p_Var6 = *(_CONTROL_EXTENSION **)(param_2 + 0x48); p_Var6 != param_2 + 0x48;
        p_Var6 = *(_CONTROL_EXTENSION **)p_Var6) {
      cVar1 = RtlEqualUnicodeString(p_Var6 + 0x10,*(_UNICODE_STRING **)(param_1 + 0x28),1);
      if (cVar1 != '\0') goto LAB_140024a66;
    }
    lVar2 = PmVolumeManagerArrival(param_2,*(_UNICODE_STRING **)(param_1 + 0x28));
  }
  else {
    lVar3 = *(longlong *)(param_1 + 4) + -0x11d046f0cb3a4005;
    if (lVar3 == 0) {
      lVar3 = *(longlong *)(param_1 + 0xc) + -0x3f05139760008fb0;
    }
    if (lVar3 == 0) {
      for (p_Var6 = *(_CONTROL_EXTENSION **)(param_2 + 0x48); p_Var6 != param_2 + 0x48;
          p_Var6 = *(_CONTROL_EXTENSION **)p_Var6) {
        p_Var5 = p_Var6 + 0x10;
        cVar1 = RtlEqualUnicodeString(p_Var5,*(undefined8 *)(param_1 + 0x28),1);
        if (cVar1 != '\0') {
          uVar4 = PmVolumeManagerRemoval(p_Var5,(longlong *)p_Var6);
          lVar2 = (long)uVar4;
          break;
        }
      }
    }
  }
LAB_140024a66:
  KeReleaseMutex(param_2 + 0x10,0);
  return lVar2;
}



===== PmVolumeManagerRemoval @ 140024a9c =====

undefined8 PmVolumeManagerRemoval(undefined8 param_1,longlong *param_2)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined8 uVar4;
  
  if ((int)param_2[4] == 0) {
    lVar1 = *param_2;
    if ((*(longlong **)(lVar1 + 8) != param_2) ||
       (plVar2 = (longlong *)param_2[1], (longlong *)*plVar2 != param_2)) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3);
      pcVar3 = (code *)swi(3);
      uVar4 = (*pcVar3)();
      return uVar4;
    }
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    if (param_2[6] != 0) {
      ObfDereferenceObject();
    }
    ExFreePoolWithTag(param_2,0);
  }
  return 0;
}



===== PartitionIoctlDsm @ 140024b00 =====

int PartitionIoctlDsm(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  int iVar9;
  undefined4 *puVar10;
  ulonglong *puVar11;
  ulonglong uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  longlong local_res10;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  
  lVar4 = *(longlong *)(param_2 + 0xb8);
  lVar5 = *(longlong *)(param_1 + 0x40);
  local_58 = 0;
  uStack_50 = 0;
  local_res10 = 0;
  local_48 = 0;
  uStack_40 = 0;
  uVar13 = *(uint *)(lVar4 + 0x10);
  uVar14 = 0;
  uVar15 = 0;
  if (uVar13 < 0x1c) {
LAB_140024e68:
    iVar9 = -0x3ffffff3;
    goto LAB_140024c5e;
  }
  lVar6 = *(longlong *)(param_2 + 0x18);
  iVar9 = *(int *)(lVar6 + 0x10);
  if (iVar9 != 0) {
    uVar2 = *(uint *)(lVar6 + 0xc);
    uVar15 = iVar9 + uVar2;
    if (uVar2 <= uVar15) {
      if ((uVar2 < 0x1c) || (uVar13 < uVar15)) goto LAB_140024e68;
      goto LAB_140024b60;
    }
LAB_140024df9:
    iVar9 = -0x3fffff6b;
    goto LAB_140024c5e;
  }
LAB_140024b60:
  uVar2 = *(uint *)(lVar6 + 0x18);
  if (uVar2 != 0) {
    if ((*(uint *)(lVar6 + 8) & 1) == 0) {
      uVar3 = *(uint *)(lVar6 + 0x14);
      uVar14 = uVar2 + uVar3;
      if (uVar14 < uVar3) goto LAB_140024df9;
      if ((((uVar3 != 0) && ((uVar2 & 0xf) == 0)) && (0x1b < uVar3)) &&
         ((uVar14 <= uVar13 && (((char)uVar3 + (char)lVar6 & 7U) == 0)))) goto LAB_140024bb1;
    }
    goto LAB_140024e68;
  }
LAB_140024bb1:
  if ((iVar9 != 0) && (uVar2 != 0)) {
    if (*(uint *)(lVar6 + 0xc) < *(uint *)(lVar6 + 0x14)) {
      if (*(uint *)(lVar6 + 0x14) < uVar15) {
        iVar9 = -0x3ffffff3;
        goto LAB_140024c5e;
      }
    }
    else if (*(uint *)(lVar6 + 0xc) < uVar14) goto LAB_140024e68;
  }
  KeWaitForSingleObject(*(longlong *)(lVar5 + 0x18) + 0x38,0,0,0,0);
  if ((*(uint *)(lVar6 + 8) & 1) == 0) {
    puVar11 = (ulonglong *)((ulonglong)*(uint *)(lVar6 + 0x14) + lVar6);
    for (uVar13 = *(uint *)(lVar6 + 0x18); 0xf < uVar13; uVar13 = uVar13 - 0x10) {
      iVar9 = PmEnumerateOverlaps((undefined8 *)(lVar5 + 0x138),*puVar11,puVar11[1],
                                  PartitionOverlapCount,&local_58);
      if (iVar9 < 0) goto LAB_140024c48;
      puVar11 = puVar11 + 2;
    }
LAB_140024c28:
    if ((int)local_48 == 0) {
      iVar9 = -0x3ffffff3;
    }
    else {
      if (*(int *)(lVar6 + 0x10) == 0) {
        uVar13 = 0x23;
LAB_140024c93:
        uVar13 = uVar13 & 0xfffffff8;
        uVar15 = uVar13 + (int)local_48 * 0x10;
        if (uVar13 <= uVar15) {
          uVar14 = *(uint *)(lVar4 + 8);
          if (uVar14 <= uVar15) {
            uVar14 = uVar15;
          }
          puVar10 = (undefined4 *)ExAllocatePool2(0x4a,uVar14,0x42496d50);
          if (puVar10 != (undefined4 *)0x0) {
            uVar15 = *(uint *)(lVar6 + 0x10);
            uVar2 = *(uint *)(lVar6 + 0xc);
            *puVar10 = 0x1c;
            puVar10[1] = *(undefined4 *)(lVar6 + 4);
            uVar3 = *(uint *)(lVar6 + 8);
            puVar10[3] = uVar2;
            puVar10[2] = uVar3 & 0xfffffffe;
            puVar10[4] = uVar15;
            puVar10[5] = uVar13;
            puVar10[6] = (int)local_48 << 4;
            if (uVar15 != 0) {
              memmove((void *)((ulonglong)uVar2 + (longlong)puVar10),
                      (void *)((ulonglong)uVar2 + lVar6),(ulonglong)uVar15);
            }
            local_res10 = (ulonglong)(uint)puVar10[5] + (longlong)puVar10;
            if ((*(uint *)(lVar6 + 8) & 1) == 0) {
              puVar11 = (ulonglong *)((ulonglong)*(uint *)(lVar6 + 0x14) + lVar6);
              if (0xf < *(uint *)(lVar6 + 0x18)) {
                uVar12 = (ulonglong)(*(uint *)(lVar6 + 0x18) >> 4);
                do {
                  PmEnumerateOverlaps((undefined8 *)(lVar5 + 0x138),*puVar11,puVar11[1],
                                      PartitionOverlapDsm,&local_res10);
                  puVar11 = puVar11 + 2;
                  uVar12 = uVar12 - 1;
                } while (uVar12 != 0);
              }
            }
            else {
              uVar12 = PartitionLength(lVar5,'\x01');
              PmEnumerateOverlaps((undefined8 *)(lVar5 + 0x138),0,uVar12,PartitionOverlapDsm,
                                  &local_res10);
            }
            KeReleaseMutex(*(longlong *)(lVar5 + 0x18) + 0x38,0);
            puVar7 = *(undefined8 **)(param_2 + 0xb8);
            puVar7[-9] = *puVar7;
            puVar7[-8] = puVar7[1];
            puVar7[-7] = puVar7[2];
            puVar7[-6] = puVar7[3];
            puVar7[-5] = puVar7[4];
            puVar7[-4] = puVar7[5];
            puVar7[-3] = puVar7[6];
            *(undefined1 *)((longlong)puVar7 + -0x45) = 0;
            lVar4 = *(longlong *)(param_2 + 0xb8);
            pbVar1 = (byte *)(lVar4 + -0x46);
            *pbVar1 = *pbVar1 | 0x12;
            *(uint *)(lVar4 + -0x38) = uVar14;
            uVar8 = *(undefined8 *)(param_2 + 0x18);
            lVar4 = *(longlong *)(param_2 + 0xb8);
            *(undefined4 **)(param_2 + 0x18) = puVar10;
            *(code **)(lVar4 + -0x10) = PartitionIoctlDsmCompletion;
            *(undefined8 *)(lVar4 + -8) = uVar8;
            *(undefined1 *)(lVar4 + -0x45) = 0xe0;
            iVar9 = PartitionSendRequest(param_1,param_2);
            return iVar9;
          }
          iVar9 = -0x3fffff66;
          goto LAB_140024c48;
        }
      }
      else {
        uVar13 = uVar15 + 7;
        if (uVar15 <= uVar13) goto LAB_140024c93;
      }
      iVar9 = -0x3fffff6b;
    }
  }
  else {
    uVar12 = PartitionLength(lVar5,'\x01');
    iVar9 = PmEnumerateOverlaps((undefined8 *)(lVar5 + 0x138),0,uVar12,PartitionOverlapCount,
                                &local_58);
    if (-1 < iVar9) goto LAB_140024c28;
  }
LAB_140024c48:
  KeReleaseMutex(*(longlong *)(lVar5 + 0x18) + 0x38,0);
LAB_140024c5e:
  *(int *)(param_2 + 0x30) = iVar9;
  IofCompleteRequest(param_2,0);
  return iVar9;
}



===== PartitionOverlapDsm @ 140024f00 =====

undefined8
PartitionOverlapDsm(int param_1,longlong param_2,longlong param_3,longlong param_4,longlong *param_5
                   )

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  
  plVar1 = (longlong *)*param_5;
  if (param_1 != 4) {
    if ((param_1 == 1) || (param_1 != 2)) {
      return 0xc000000d;
    }
    lVar2 = *(longlong *)(param_2 + 0x10);
    lVar3 = *(longlong *)(param_2 + 0x18);
    plVar1[1] = param_3;
    *plVar1 = (lVar3 - lVar2) + param_4;
    *param_5 = (longlong)(plVar1 + 2);
  }
  return 0;
}



===== PmIoctlPerformance @ 140024f50 =====

ulonglong PmIoctlPerformance(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong *plVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  int local_res8 [2];
  undefined1 local_88 [8];
  undefined4 local_80;
  wchar_t *local_78;
  int *local_70;
  undefined4 local_68;
  
  uVar3 = 0;
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_res8[0] = 0;
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 8) < 0x58) {
    return 0xc0000023;
  }
  plVar2 = *(longlong **)(param_2 + 0x18);
  if (*(char *)(lVar1 + 0x2c0) == '\0') {
    memset(local_88,0,0x70);
    local_78 = L"EnableCounterForIoctl";
    local_70 = local_res8;
    local_80 = 0x120;
    local_68 = 0x4000000;
    uVar3 = RtlQueryRegistryValuesEx(1,PTR_u_Partmgr_1400190b8,local_88,0,0);
    if ((int)uVar3 < 0) {
      return uVar3;
    }
    if (local_res8[0] != 1) {
      return 0xc0000010;
    }
    uVar4 = PmWmiCounterEnable((longlong *)(lVar1 + 0x2d0));
    uVar3 = uVar4 & 0xffffffff;
    *(byte *)(lVar1 + 0x2c0) = (byte)(uVar4 >> 0x18) >> 7 ^ 1;
    if ((int)uVar4 < 0) {
      return uVar3;
    }
  }
  PmWmiCounterQuery(*(longlong *)(lVar1 + 0x2d0),plVar2,(undefined8 *)L"Partmgr ",
                    *(undefined4 *)(lVar1 + 0xa8));
  *(undefined8 *)(param_2 + 0x38) = 0x58;
  return uVar3;
}



===== PmQueryWmiDataBlock @ 140024ff0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl PmQueryWmiDataBlock(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64,unsigned
   long,unsigned long,unsigned long,unsigned long * __ptr64,unsigned long,unsigned char * __ptr64)
    */

long __cdecl
PmQueryWmiDataBlock(_DEVICE_OBJECT *param_1,_IRP *param_2,ulong param_3,ulong param_4,ulong param_5,
                   ulong *param_6,ulong param_7,uchar *param_8)

{
  longlong lVar1;
  ushort uVar2;
  long lVar3;
  longlong lVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined1 auStack_f8 [32];
  undefined1 local_d8;
  wchar_t local_c8;
  undefined1 local_c6 [126];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_f8;
  lVar1 = *(longlong *)(param_1 + 0x40);
  uVar5 = 0;
  local_c8 = L'\0';
  memset(local_c6,0,0x7e);
  uVar6 = 0;
  if ((param_3 == 0) && (*(uint *)(lVar1 + 0xa8) != 0xffffffff)) {
    if (*(char *)(lVar1 + 0x2c0) == '\0') {
      uVar6 = 0xc0000001;
    }
    else {
      RtlStringCchPrintfW(&local_c8,0x40,L"\\Device\\Harddisk%d\\Partition0",
                          (ulonglong)*(uint *)(lVar1 + 0xa8));
      lVar4 = -1;
      do {
        lVar4 = lVar4 + 1;
      } while (*(short *)(local_c6 + lVar4 * 2 + -2) != 0);
      uVar2 = (short)lVar4 * 2;
      uVar5 = uVar2 + 0x5a;
      if (param_7 < uVar5) {
        uVar6 = 0xc0000023;
      }
      else {
        PmWmiCounterQuery(*(longlong *)(lVar1 + 0x2d0),(longlong *)param_8,(undefined8 *)L"Partmgr "
                          ,*(undefined4 *)(lVar1 + 0xa8));
        *(ushort *)(param_8 + 0x58) = uVar2;
        memmove(param_8 + 0x5a,&local_c8,(ulonglong)uVar2);
        *param_6 = uVar5;
      }
    }
  }
  else {
    uVar6 = 0xc0000295;
  }
  local_d8 = 0;
  lVar3 = WmiCompleteRequest(param_1,param_2,uVar6,uVar5);
  return lVar3;
}



===== PmWmiCounterQuery @ 140025160 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PmWmiCounterQuery(longlong param_1,longlong *param_2,undefined8 *param_3,undefined4 param_4)

{
  longlong *plVar1;
  undefined8 uVar2;
  longlong lVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined8 local_res8;
  
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  param_2[6] = 0;
  param_2[7] = 0;
  param_2[8] = 0;
  param_2[9] = 0;
  param_2[10] = 0;
  KeWaitForSingleObject(0,0,0,0,0);
  *(undefined4 *)(param_2 + 6) = *(undefined4 *)(param_1 + 0x40);
  local_res8 = 0;
  lVar3 = KeQueryUnbiasedInterruptTimePrecise(&local_res8);
  PmPerfCounterIdleUpdate(param_1,lVar3,'\0','\0');
  PmPerfCounterIdleUpdate(param_1,lVar3,'\0','\x01');
  uVar5 = 0;
  if (*(int *)(param_1 + 0x3c) != 0) {
    do {
      uVar4 = (int)uVar5 + 1;
      plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x48) + uVar5 * 8);
      *param_2 = *param_2 + *plVar1;
      param_2[1] = param_2[1] + plVar1[1];
      *(int *)(param_2 + 5) = (int)param_2[5] + (int)plVar1[6];
      *(int *)((longlong)param_2 + 0x2c) =
           *(int *)((longlong)param_2 + 0x2c) + *(int *)((longlong)plVar1 + 0x34);
      *(int *)((longlong)param_2 + 0x34) =
           *(int *)((longlong)param_2 + 0x34) + *(int *)((longlong)plVar1 + 0x3c);
      param_2[2] = param_2[2] + plVar1[2];
      param_2[3] = param_2[3] + plVar1[3];
      param_2[4] = param_2[4] + plVar1[5];
      uVar5 = (ulonglong)uVar4;
    } while (uVar4 < *(uint *)(param_1 + 0x3c));
  }
  param_2[7] = _DAT_fffff78000000014;
  KeReleaseMutex(param_1,0);
  *(undefined4 *)(param_2 + 8) = param_4;
  uVar2 = param_3[1];
  *(undefined8 *)((longlong)param_2 + 0x44) = *param_3;
  *(undefined8 *)((longlong)param_2 + 0x4c) = uVar2;
  return;
}



===== PmIoctlRedirect @ 1400252a0 =====

ulonglong PmIoctlRedirect(longlong param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  undefined8 *puVar3;
  longlong lVar4;
  bool bVar5;
  uint uVar6;
  ulonglong uVar7;
  char cVar8;
  char local_res8 [8];
  ulonglong local_res10;
  ulonglong local_res18 [2];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  local_28 = 0;
  local_res10 = 0;
  local_res18[0] = 0;
  local_res8[0] = '\0';
  cVar8 = '\0';
  uVar6 = 0;
  local_38 = 0;
  uStack_30 = 0;
  if (((*(byte *)(*(longlong *)(param_2 + 0xb8) + 2) & 0x10) != 0) || (*(int *)(lVar2 + 0x288) != 1)
     ) goto LAB_140025353;
  uVar1 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 0x18);
  if (uVar1 == 0x4d014) {
LAB_1400252fc:
    cVar8 = '\x01';
LAB_1400252ff:
    uVar7 = PmIoctlPassThroughQuerySectorWriteScsi
                      (param_2,cVar8,local_res8,&local_res10,local_res18);
    uVar6 = (uint)uVar7;
LAB_140025322:
    if ((int)uVar6 < 0) goto LAB_14002532c;
  }
  else {
    if (0x4d044 < uVar1) {
      if (uVar1 == 0x4d048) goto LAB_1400252ff;
      if (uVar1 != 0x2d9404) goto LAB_140025353;
      uVar7 = PmIoctlDsmQuerySectorWrite(param_2,local_res8,&local_res10,(longlong *)local_res18);
      uVar6 = (uint)uVar7;
      goto LAB_140025322;
    }
    if (uVar1 == 0x4d044) goto LAB_1400252ff;
    if (uVar1 == 0x4d004) goto LAB_1400252fc;
    if ((uVar1 == 0x4d02c) || (uVar1 == 0x4d030)) {
      uVar7 = PmIoctlPassThroughQuerySectorWriteAta(param_2,local_res8,&local_res10,local_res18);
      uVar6 = (uint)uVar7;
      goto LAB_140025322;
    }
  }
  if (local_res8[0] != '\0') {
    bVar5 = PmIsOverlap(lVar2,local_res10,local_res18[0]);
    if (bVar5) {
      KeInitializeEvent(&local_38,0,0);
      puVar3 = *(undefined8 **)(param_2 + 0xb8);
      puVar3[-9] = *puVar3;
      puVar3[-8] = puVar3[1];
      puVar3[-7] = puVar3[2];
      puVar3[-6] = puVar3[3];
      puVar3[-5] = puVar3[4];
      puVar3[-4] = puVar3[5];
      puVar3[-3] = puVar3[6];
      *(undefined1 *)((longlong)puVar3 + -0x45) = 0;
      lVar4 = *(longlong *)(param_2 + 0xb8);
      *(code **)(lVar4 + -0x10) = PmSignalCompletion;
      *(undefined8 **)(lVar4 + -8) = &local_38;
      *(undefined1 *)(lVar4 + -0x45) = 0xe0;
      *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + -1;
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + -0x48;
      PmRedirectRequest(lVar2,param_2);
      KeWaitForSingleObject(&local_38,0,0,0,0);
      uVar6 = *(uint *)(param_2 + 0x30);
    }
    if ((int)uVar6 < 0) {
LAB_14002532c:
      *(uint *)(param_2 + 0x30) = uVar6;
      IofCompleteRequest(param_2,0);
      return (ulonglong)uVar6;
    }
  }
LAB_140025353:
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  uVar7 = IofCallDriver(*(undefined8 *)(lVar2 + 0x10),param_2);
  return uVar7;
}



===== PmIoctlPassThroughQuerySectorWriteScsi @ 140025420 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PmIoctlPassThroughQuerySectorWriteScsi
                    (longlong param_1,char param_2,char *param_3,undefined8 *param_4,
                    ulonglong *param_5)

{
  byte bVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 auVar4 [16];
  bool bVar5;
  bool bVar6;
  char cVar7;
  undefined1 uVar8;
  ulonglong uVar9;
  uint uVar10;
  undefined1 *puVar11;
  uint uVar12;
  undefined1 auStackY_c8 [32];
  ulonglong local_88;
  ulonglong local_80;
  ulonglong local_78;
  longlong local_70;
  ulonglong *local_68;
  undefined8 *local_60;
  undefined4 local_58;
  undefined8 local_54;
  undefined8 uStack_4c;
  uint local_44;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_c8;
  lVar2 = *(longlong *)(param_1 + 0xb8);
  local_68 = param_5;
  *param_3 = '\0';
  lVar3 = *(longlong *)(param_1 + 0x18);
  bVar5 = false;
  local_58 = 0;
  local_80 = 0;
  local_54 = 0;
  uStack_4c = 0;
  local_44 = 0;
  local_88 = 0;
  local_78 = 0;
  local_70 = lVar2;
  local_60 = param_4;
  cVar7 = IoIs32bitProcess();
  uVar10 = *(uint *)(lVar2 + 0x10);
  if (cVar7 == '\0') {
    if (uVar10 < 0x38) {
      return 0xc000000d;
    }
    if (param_2 == '\0') {
      uVar10 = *(uint *)(lVar3 + 8);
      puVar11 = (undefined1 *)(lVar3 + 0x38);
      uVar9 = Feature_3580518712__private_IsEnabledDeviceUsageNoInline();
      if (((int)uVar9 != 0) && (0xffffffc6 < uVar10 - 1)) {
        return 0xc000000d;
      }
      uVar12 = uVar10 + 0x38;
    }
    else {
      uVar10 = (uint)*(byte *)(lVar3 + 6);
      puVar11 = (undefined1 *)(lVar3 + 0x24);
      uVar9 = Feature_3580518712__private_IsEnabledDeviceUsageNoInline();
      if (((int)uVar9 != 0) && (0x10 < uVar10)) {
        return 0xc000000d;
      }
      uVar12 = 0x38;
    }
  }
  else {
    uVar12 = 0x2c;
    if (param_2 == '\0') {
      uVar12 = 0x30;
    }
    if (uVar10 < uVar12) {
      return 0xc000000d;
    }
    if (param_2 == '\0') {
      uVar10 = *(uint *)(lVar3 + 8);
      puVar11 = (undefined1 *)(lVar3 + 0x30);
      uVar9 = Feature_3580518712__private_IsEnabledDeviceUsageNoInline();
      if (((int)uVar9 != 0) && (0xffffffce < uVar10 - 1)) {
        return 0xc000000d;
      }
      uVar12 = uVar10 + 0x30;
    }
    else {
      bVar1 = *(byte *)(lVar3 + 6);
      uVar10 = (uint)bVar1;
      puVar11 = (undefined1 *)(lVar3 + 0x1c);
      uVar9 = Feature_3580518712__private_IsEnabledDeviceUsageNoInline();
      if (((int)uVar9 != 0) && (0x10 < bVar1)) {
        return 0xc000000d;
      }
    }
  }
  if (*(uint *)(local_70 + 0x10) < uVar12) {
    return 0xc000000d;
  }
  bVar6 = false;
  switch(*puVar11) {
  case 10:
    if (uVar10 < 6) {
      return 0xc000000d;
    }
    local_80 = (ulonglong)(byte)puVar11[4];
    local_88 = (ulonglong)((uint6)CONCAT21(CONCAT11(puVar11[1],puVar11[2]),puVar11[3]) & 0x1fffff);
    *param_3 = '\x01';
    goto LAB_14002584c;
  case 0x18:
  case 0x3a:
  case 0x80:
    return 0xc0000010;
  case 0x2a:
  case 0x2e:
  case 0x41:
  case 0x50:
  case 0x51:
  case 0x53:
    goto switchD_14002558c_caseD_2a;
  case 0x3f:
    bVar6 = true;
    goto switchD_14002558c_caseD_2a;
  case 0x42:
    goto switchD_14002558c_caseD_42;
  case 0x7f:
    if (uVar10 < 0x20) {
      return 0xc000000d;
    }
    if (((byte)puVar11[9] < 0xf) && ((0x78d0U >> ((byte)puVar11[9] & 0x1f) & 1) != 0)) {
      local_88 = CONCAT71(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(puVar11[0xc],
                                                                                puVar11[0xd]),
                                                                       puVar11[0xe]),puVar11[0xf]),
                                                     puVar11[0x10]),puVar11[0x11]),puVar11[0x12]),
                          puVar11[0x13]);
      local_80 = (ulonglong)CONCAT21(CONCAT11(puVar11[0x1c],puVar11[0x1d]),puVar11[0x1e]) << 8;
      uVar8 = puVar11[0x1f];
      goto LAB_140025655;
    }
    break;
  case 0x83:
    if (uVar10 < 0x10) {
      return 0xc000000d;
    }
    if ((puVar11[1] & 0x1f) != 0x11) {
      return 0;
    }
    goto switchD_14002558c_caseD_42;
  case 0x8a:
  case 0x8e:
  case 0x93:
    if (uVar10 < 0x10) {
      return 0xc000000d;
    }
    local_88 = CONCAT71(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(puVar11[2],puVar11[3])
                                                                     ,puVar11[4]),puVar11[5]),
                                                   puVar11[6]),puVar11[7]),puVar11[8]),puVar11[9]);
    local_80 = (ulonglong)CONCAT21(CONCAT11(puVar11[10],puVar11[0xb]),puVar11[0xc]) << 8;
    uVar8 = puVar11[0xd];
    goto LAB_140025655;
  case 0x9f:
    if (uVar10 < 0x10) {
      return 0xc000000d;
    }
    if ((puVar11[1] & 0x1f) == 0x11) {
      bVar5 = true;
      local_88 = CONCAT71(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(puVar11[2],
                                                                                puVar11[3]),
                                                                       puVar11[4]),puVar11[5]),
                                                     puVar11[6]),puVar11[7]),puVar11[8]),puVar11[9])
      ;
      local_80 = (ulonglong)CONCAT11(puVar11[0xc],puVar11[0xd]);
      *param_3 = '\x01';
      goto LAB_14002584c;
    }
    break;
  case 0xaa:
  case 0xae:
    if (uVar10 < 0xc) {
      return 0xc000000d;
    }
    local_88 = (ulonglong)CONCAT31(CONCAT21(CONCAT11(puVar11[2],puVar11[3]),puVar11[4]),puVar11[5]);
    local_80 = (ulonglong)CONCAT21(CONCAT11(puVar11[6],puVar11[7]),puVar11[8]) << 8;
    uVar8 = puVar11[9];
LAB_140025655:
    local_80 = CONCAT71(local_80._1_7_,uVar8);
    *param_3 = '\x01';
    goto LAB_14002584c;
  }
  if (*param_3 == '\0') {
    return 0;
  }
LAB_14002584c:
  uVar9 = PmSendDeviceControl(*(undefined8 *)(local_70 + 0x28),0x70000,0,0,&local_58,0x18,0);
  if ((int)uVar9 < 0) {
    return uVar9 & 0xffffffff;
  }
  local_70 = 0;
  auVar4._8_8_ = 0;
  auVar4._0_8_ = local_88;
  if (SUB168(ZEXT416(local_44) * auVar4,8) != 0) {
    *local_60 = 0xffffffffffffffff;
    return 0xc0000095;
  }
  *local_60 = SUB168(ZEXT416(local_44) * auVar4,0);
  if (bVar5) {
    *local_68 = local_80;
    return 0;
  }
  uVar9 = RtlULongLongMult(local_80,(ulonglong)local_44,local_68);
  return uVar9 & 0xffffffff;
switchD_14002558c_caseD_42:
  if (uVar10 < 10) {
    return 0xc000000d;
  }
  uVar9 = PmSendDeviceControl(*(undefined8 *)(local_70 + 0x28),0x7405c,0,0,&local_78,8,0);
  if ((int)uVar9 < 0) {
    return uVar9 & 0xffffffff;
  }
  bVar5 = true;
  *param_3 = '\x01';
  local_80 = local_78;
  goto LAB_14002584c;
switchD_14002558c_caseD_2a:
  bVar5 = bVar6;
  if (uVar10 < 10) {
    return 0xc000000d;
  }
  local_88 = (longlong)(int)((uint)CONCAT21(CONCAT11(puVar11[2],puVar11[3]),puVar11[4]) << 8) |
             (ulonglong)(byte)puVar11[5];
  local_80 = (ulonglong)CONCAT11(puVar11[7],puVar11[8]);
  *param_3 = '\x01';
  goto LAB_14002584c;
}



===== PmIoctlPassThroughQuerySectorWriteAta @ 140025904 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00014002a7d1) */

ulonglong PmIoctlPassThroughQuerySectorWriteAta
                    (longlong param_1,char *param_2,undefined8 *param_3,ulonglong *param_4)

{
  byte bVar1;
  longlong lVar2;
  longlong lVar3;
  char cVar4;
  uint uVar5;
  ulonglong uVar6;
  char *pcVar7;
  ulonglong uVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  bool bVar12;
  undefined1 auStackY_c8 [32];
  undefined8 local_88;
  ulonglong local_80;
  undefined8 *local_78;
  undefined4 local_70;
  undefined8 local_6c;
  undefined8 uStack_64;
  uint local_5c;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_70 = 0;
  uVar8 = 0;
  local_88 = 0;
  lVar2 = *(longlong *)(param_1 + 0xb8);
  *param_2 = '\0';
  uVar6 = 0;
  local_80 = 0;
  local_5c = 0;
  local_6c = 0;
  uStack_64 = 0;
  local_78 = param_3;
  cVar4 = IoIs32bitProcess(param_1);
  if (cVar4 == '\0') {
    if (*(uint *)(lVar2 + 0x10) < 0x30) {
      return 0xc000000d;
    }
    lVar3 = *(longlong *)(param_1 + 0x18);
    pcVar7 = (char *)(lVar3 + 0x28);
    puVar9 = (undefined1 *)(lVar3 + 0x24);
    puVar10 = (undefined1 *)(lVar3 + 0x23);
    puVar11 = (undefined1 *)(lVar3 + 0x22);
  }
  else {
    if (*(uint *)(lVar2 + 0x10) < 0x28) {
      return 0xc000000d;
    }
    lVar3 = *(longlong *)(param_1 + 0x18);
    pcVar7 = (char *)(lVar3 + 0x20);
    puVar9 = (undefined1 *)(lVar3 + 0x1c);
    puVar10 = (undefined1 *)(lVar3 + 0x1b);
    puVar11 = (undefined1 *)(lVar3 + 0x1a);
  }
  bVar1 = pcVar7[6];
  if (bVar1 < 0x3e) {
    if (bVar1 == 0x3d) goto LAB_140025b49;
    if (bVar1 != 6) {
      if (bVar1 == 0x30) goto LAB_140025abd;
      if (((bVar1 == 0x34) || (bVar1 == 0x35)) || (bVar1 == 0x36)) goto LAB_140025b49;
      bVar12 = bVar1 == 0x39;
      goto LAB_1400259e0;
    }
    if ((pcVar7[5] & 0x40U) == 0) {
      return 0xc0000010;
    }
    if (*pcVar7 == '\x01') {
      uVar6 = PmSendDeviceControl(*(undefined8 *)(lVar2 + 0x28),0x7405c,0,0,&local_88,8,0);
      if ((int)uVar6 < 0) {
        return uVar6 & 0xffffffff;
      }
      uVar6 = FUN_14002a7c8();
      return uVar6;
    }
  }
  else {
    if (bVar1 == 0x3e) goto LAB_140025b49;
    if (((bVar1 == 0xc5) || (bVar1 == 0xca)) || (bVar1 == 0xcc)) {
LAB_140025abd:
      if ((pcVar7[5] & 0x40U) == 0) {
        return 0xc0000010;
      }
      uVar8 = (ulonglong)(byte)pcVar7[1];
      uVar6 = (ulonglong)
              ((uint7)CONCAT31(CONCAT21(CONCAT11(pcVar7[5],pcVar7[4]),pcVar7[3]),pcVar7[2]) &
              0xfffffff);
      *param_2 = '\x01';
      goto LAB_140025af7;
    }
    bVar12 = bVar1 == 0xce;
LAB_1400259e0:
    if (bVar12) {
LAB_140025b49:
      if ((pcVar7[5] & 0x40U) == 0) {
        return 0xc0000010;
      }
      local_80 = (ulonglong)
                 CONCAT24(CONCAT11(*puVar9,*puVar10),
                          CONCAT31(CONCAT21(CONCAT11(*puVar11,pcVar7[4]),pcVar7[3]),pcVar7[2]));
      uVar6 = FUN_14002a7c8();
      return uVar6;
    }
  }
  if (*param_2 == '\0') {
    return 0;
  }
LAB_140025af7:
  uVar5 = PmGetDriveGeometry(*(undefined8 *)(lVar2 + 0x28),&local_70);
  if ((int)uVar5 < 0) {
    return (ulonglong)uVar5;
  }
  uVar6 = RtlULongLongMult(uVar6,(ulonglong)local_5c,local_78);
  if ((int)uVar6 < 0) {
    return uVar6 & 0xffffffff;
  }
  uVar6 = RtlULongLongMult(uVar8,(ulonglong)local_5c,param_4);
  return uVar6 & 0xffffffff;
}



===== PmSystemControl @ 140025bb0 =====

/* long __cdecl PmSystemControl(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl PmSystemControl(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  longlong lVar1;
  longlong lVar2;
  long lVar3;
  int local_res8 [2];
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar3 = 0;
  local_res8[0] = 3;
  lVar2 = *(longlong *)(param_2 + 0xb8);
  if (*(char *)(lVar2 + 1) == '\r') {
    if (*(int *)(lVar2 + 0x18) == 0x10) {
      if (**(int **)(lVar2 + 0x20) == 1) {
        *(undefined8 *)(lVar1 + 0x2c8) = *(undefined8 *)(*(int **)(lVar2 + 0x20) + 2);
      }
      else {
        lVar3 = -0x3fffff45;
      }
    }
    else {
      lVar3 = -0x3ffffffc;
    }
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(long *)(param_2 + 0x30) = lVar3;
  }
  else {
    lVar3 = WmiSystemControl(lVar1 + 0x2d8,param_1,param_2,local_res8);
    if (local_res8[0] == 0) {
      return lVar3;
    }
    if (local_res8[0] != 1) {
      param_2[0x43] = (_IRP)((char)param_2[0x43] + '\x01');
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
      lVar3 = IofCallDriver(*(undefined8 *)(lVar1 + 0x10),param_2);
      return lVar3;
    }
  }
  IofCompleteRequest(param_2,0);
  return lVar3;
}



===== PmIoctlQueryProperty @ 140025c90 =====

ulonglong PmIoctlQueryProperty(longlong param_1,longlong param_2)

{
  ushort uVar1;
  longlong lVar2;
  longlong lVar3;
  int *_Dst;
  undefined8 uVar4;
  ulonglong uVar5;
  int iVar7;
  uint uVar6;
  uint uVar8;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  uVar8 = 0;
  lVar3 = *(longlong *)(param_2 + 0xb8);
  if (*(uint *)(lVar3 + 0x10) < 0xc) {
    uVar8 = 0xc0000004;
  }
  else {
    _Dst = *(int **)(param_2 + 0x18);
    if ((*_Dst != 0x3a) || (*(int *)(*(longlong *)(lVar2 + 0xe8) + 0x1c) == 0x12)) {
      *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
      *(longlong *)(param_2 + 0xb8) = lVar3 + 0x48;
      uVar5 = IofCallDriver(*(undefined8 *)(lVar2 + 0x10));
      return uVar5;
    }
    if (_Dst[1] == 0) {
      uVar8 = *(uint *)(lVar3 + 8);
      if (uVar8 < 8) {
        uVar8 = 0xc0000023;
      }
      else {
        memset(_Dst,0,(ulonglong)uVar8);
        iVar7 = 0x24;
        _Dst[0] = 0x24;
        _Dst[1] = 0;
        if (0x23 < uVar8) {
          uVar4 = *(undefined8 *)(lVar2 + 0x1a0);
          *(undefined8 *)(_Dst + 2) = *(undefined8 *)(lVar2 + 0x198);
          *(undefined8 *)(_Dst + 4) = uVar4;
          *(undefined8 *)(_Dst + 6) = *(undefined8 *)(lVar2 + 0x1a8);
        }
        _Dst[1] = 0x24;
        uVar1 = *(ushort *)(lVar2 + 0x1c2);
        uVar6 = (uint)uVar1;
        if ((uVar1 != 0) && (uVar1 + 0x24 <= uVar8)) {
          uVar6 = (uint)uVar1;
          RtlStringCbCopyW((short *)(_Dst + 9),(ulonglong)(uVar8 - 0x24),
                           *(longlong *)(lVar2 + 0x1c8));
          iVar7 = _Dst[1];
          _Dst[8] = iVar7;
        }
        uVar6 = iVar7 + uVar6;
        _Dst[1] = uVar6;
        if (uVar8 <= uVar6) {
          uVar6 = uVar8;
        }
        *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar6;
        uVar8 = 0;
      }
    }
    else if (_Dst[1] != 1) {
      uVar8 = 0xc0000002;
    }
  }
  *(uint *)(param_2 + 0x30) = uVar8;
  IofCompleteRequest(param_2,0);
  return (ulonglong)uVar8;
}



===== PartitionIoctlGetPartitionInfoEx @ 140025de0 =====

uint PartitionIoctlGetPartitionInfoEx(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *_Dst;
  undefined8 uVar2;
  uint uVar3;
  longlong lVar4;
  
  lVar4 = *(longlong *)(param_2 + 0xb8);
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (*(uint *)(lVar4 + 8) < 0x90) {
    return 0xc0000023;
  }
  _Dst = *(undefined8 **)(param_2 + 0x18);
  memset(_Dst,0,0x90);
  KeWaitForSingleObject(*(longlong *)(lVar1 + 0x18) + 0x38,0,0,0,0);
  if (((*(byte *)(lVar4 + 2) & 2) != 0) && ((*(uint *)(*(longlong *)(lVar1 + 8) + 0x34) & 1) != 0))
  {
    PmInvalidatePartitionTableCache(*(longlong *)(lVar1 + 0x18));
  }
  uVar3 = PmGetDriveLayoutEx(*(_DEVICE_EXTENSION **)(lVar1 + 0x18),(undefined8 *)0x0);
  if (-1 < (int)uVar3) {
    uVar2 = *(undefined8 *)(lVar1 + 0xb0);
    *_Dst = *(undefined8 *)(lVar1 + 0xa8);
    _Dst[1] = uVar2;
    uVar2 = *(undefined8 *)(lVar1 + 0xc0);
    _Dst[2] = *(undefined8 *)(lVar1 + 0xb8);
    _Dst[3] = uVar2;
    uVar2 = *(undefined8 *)(lVar1 + 0xd0);
    _Dst[4] = *(undefined8 *)(lVar1 + 200);
    _Dst[5] = uVar2;
    uVar2 = *(undefined8 *)(lVar1 + 0xe0);
    _Dst[6] = *(undefined8 *)(lVar1 + 0xd8);
    _Dst[7] = uVar2;
    uVar2 = *(undefined8 *)(lVar1 + 0xf0);
    _Dst[8] = *(undefined8 *)(lVar1 + 0xe8);
    _Dst[9] = uVar2;
    uVar2 = *(undefined8 *)(lVar1 + 0x100);
    _Dst[10] = *(undefined8 *)(lVar1 + 0xf8);
    _Dst[0xb] = uVar2;
    uVar2 = *(undefined8 *)(lVar1 + 0x110);
    _Dst[0xc] = *(undefined8 *)(lVar1 + 0x108);
    _Dst[0xd] = uVar2;
    uVar2 = *(undefined8 *)(lVar1 + 0x120);
    _Dst[0xe] = *(undefined8 *)(lVar1 + 0x118);
    _Dst[0xf] = uVar2;
    uVar2 = *(undefined8 *)(lVar1 + 0x130);
    _Dst[0x10] = *(undefined8 *)(lVar1 + 0x128);
    _Dst[0x11] = uVar2;
    lVar4 = PartitionLength(lVar1,'\x01');
    _Dst[2] = lVar4;
    *(undefined8 *)(param_2 + 0x38) = 0x90;
  }
  KeReleaseMutex(*(longlong *)(lVar1 + 0x18) + 0x38,0);
  return uVar3;
}



===== PartitionIoctlQueryProperty @ 140025f50 =====

int PartitionIoctlQueryProperty(longlong param_1,longlong param_2)

{
  byte bVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  longlong lVar7;
  ulonglong uVar8;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  lVar3 = *(longlong *)(param_1 + 0x40);
  if (*(uint *)(lVar2 + 0x10) < 0xc) {
    iVar4 = -0x3ffffffc;
  }
  else {
    if (**(int **)(param_2 + 0x18) != 0xb) {
      iVar4 = PartitionPassThrough(param_1,param_2);
      return iVar4;
    }
    iVar4 = PartitionForwardIrpSynchronously(param_1,param_2);
    if (((-1 < iVar4) && (0x27 < *(uint *)(lVar2 + 8))) &&
       (lVar2 = *(longlong *)(param_2 + 0x18), *(longlong *)(lVar2 + 0x10) != 0)) {
      KeWaitForSingleObject(*(longlong *)(lVar3 + 0x18) + 0x38,0,0,0,0);
      uVar5 = PartitionOffset(lVar3,'\x01');
      uVar8 = *(ulonglong *)(lVar2 + 0x10);
      bVar1 = *(byte *)(lVar2 + 8);
      uVar5 = uVar5 - uVar5 % uVar8;
      if ((bVar1 & 0x20) != 0) {
        uVar5 = uVar5 + *(longlong *)(lVar2 + 0x18);
      }
      uVar6 = PartitionOffset(lVar3,'\x01');
      *(byte *)(lVar2 + 8) = bVar1 | 0x20;
      lVar7 = PartitionOffset(lVar3,'\x01');
      uVar8 = uVar5 + uVar8;
      if (uVar6 <= uVar5) {
        uVar8 = uVar5;
      }
      *(ulonglong *)(lVar2 + 0x18) = uVar8 - lVar7;
      KeReleaseMutex(*(longlong *)(lVar3 + 0x18) + 0x38,0);
    }
  }
  *(int *)(param_2 + 0x30) = iVar4;
  IofCompleteRequest(param_2,0);
  return iVar4;
}



===== PartitionIoctlGetDeviceNumberEx @ 140025fd4 =====

int PartitionIoctlGetDeviceNumberEx(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  iVar3 = PartitionForwardIrpSynchronously(param_1,param_2);
  if (-1 < iVar3) {
    lVar2 = *(longlong *)(param_2 + 0x18);
    KeWaitForSingleObject(*(longlong *)(lVar1 + 0x18) + 0x38,0,0,0,0);
    *(undefined4 *)(lVar2 + 0x24) = *(undefined4 *)(lVar1 + 0xc0);
    KeReleaseMutex(*(longlong *)(lVar1 + 0x18) + 0x38,0);
  }
  return iVar3;
}



===== PartitionForwardIrpSynchronously @ 140026058 =====

undefined4 PartitionForwardIrpSynchronously(longlong param_1,longlong param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  uVar2 = PartitionReferenceParent(*(longlong *)(param_1 + 0x40));
  IoForwardIrpSynchronously(uVar2,param_2);
  uVar1 = *(undefined4 *)(param_2 + 0x30);
  ObfDereferenceObject(uVar2);
  return uVar1;
}



===== PmIoctlGetPerformanceInfo @ 1400260b0 =====

ulonglong PmIoctlGetPerformanceInfo(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  int *piVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  
  uVar4 = 0;
  lVar2 = *(longlong *)(param_1 + 0x40);
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10) < 8) {
    uVar4 = 0xc0000004;
  }
  else {
    piVar3 = *(int **)(param_2 + 0x18);
    if (*piVar3 == 8) {
      iVar1 = piVar3[1];
      if (iVar1 < 2) {
        if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 8) < 0x58) {
          uVar4 = 0xc0000023;
        }
        else {
          if (*(char *)(lVar2 + 0x2c0) == '\0') {
            uVar5 = PmWmiCounterEnable((longlong *)(lVar2 + 0x2d0));
            uVar4 = uVar5 & 0xffffffff;
            if ((int)uVar5 < 0) {
              return uVar5;
            }
            *(undefined1 *)(lVar2 + 0x2c0) = 1;
          }
          PmPerfCounterQuery(*(longlong *)(lVar2 + 0x2d0),iVar1,(undefined8 *)piVar3);
          *(undefined8 *)(param_2 + 0x38) = 0x58;
        }
      }
      else {
        uVar4 = 0xc000000d;
      }
    }
    else {
      uVar4 = 0xc000000d;
    }
  }
  return uVar4;
}



===== PmPerfCounterQuery @ 140026180 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PmPerfCounterQuery(longlong param_1,int param_2,undefined8 *param_3)

{
  undefined4 uVar1;
  longlong lVar2;
  longlong *plVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined8 local_res8;
  
  *param_3 = 0;
  param_3[1] = 0;
  param_3[2] = 0;
  param_3[3] = 0;
  param_3[4] = 0;
  param_3[5] = 0;
  uVar5 = 0;
  param_3[6] = 0;
  param_3[7] = 0;
  param_3[8] = 0;
  param_3[9] = 0;
  param_3[10] = 0;
  KeWaitForSingleObject(0,0,0,0,0);
  *(undefined4 *)param_3 = 0x58;
  *(int *)((longlong)param_3 + 4) = param_2;
  if (param_2 == 1) {
    uVar1 = *(undefined4 *)(param_1 + 0x44);
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 0x40);
  }
  *(undefined4 *)((longlong)param_3 + 0x4c) = uVar1;
  local_res8 = 0;
  lVar2 = KeQueryUnbiasedInterruptTimePrecise(&local_res8);
  PmPerfCounterIdleUpdate(param_1,lVar2,param_2 == 1,'\0');
  PmPerfCounterIdleUpdate(param_1,lVar2,param_2 == 1,'\x01');
  if (*(int *)(param_1 + 0x3c) != 0) {
    do {
      plVar3 = *(longlong **)(*(longlong *)(param_1 + 0x48) + uVar5 * 8);
      if (param_2 == 1) {
        plVar3 = plVar3 + 8;
      }
      uVar4 = (int)uVar5 + 1;
      uVar5 = (ulonglong)uVar4;
      param_3[2] = param_3[2] + *plVar3;
      param_3[3] = param_3[3] + plVar3[1];
      *(int *)(param_3 + 8) = *(int *)(param_3 + 8) + (int)plVar3[6];
      *(int *)((longlong)param_3 + 0x44) =
           *(int *)((longlong)param_3 + 0x44) + *(int *)((longlong)plVar3 + 0x34);
      *(int *)(param_3 + 9) = *(int *)(param_3 + 9) + (int)plVar3[7];
      *(int *)(param_3 + 10) = *(int *)(param_3 + 10) + *(int *)((longlong)plVar3 + 0x3c);
      param_3[4] = param_3[4] + plVar3[2];
      param_3[5] = param_3[5] + plVar3[3];
      param_3[6] = param_3[6] + plVar3[4];
      param_3[7] = param_3[7] + plVar3[5];
    } while (uVar4 < *(uint *)(param_1 + 0x3c));
  }
  param_3[1] = _DAT_fffff78000000014;
  KeReleaseMutex(param_1,0);
  return;
}



===== PmIoctlGetDriveLayoutEx @ 1400262f0 =====

uint PmIoctlGetDriveLayoutEx(longlong param_1,longlong param_2)

{
  _DEVICE_EXTENSION *p_Var1;
  longlong lVar2;
  _DEVICE_EXTENSION *p_Var3;
  void *pvVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  bool bVar8;
  void *local_res8;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  p_Var3 = *(_DEVICE_EXTENSION **)(param_1 + 0x40);
  local_res8 = (void *)0x0;
  if (*(uint *)(lVar2 + 8) < 0x30) {
    uVar5 = 0xc0000023;
  }
  else {
    p_Var1 = p_Var3 + 0x38;
    KeWaitForSingleObject(p_Var1,0,0,0,0);
    uVar5 = PmGetDriveLayoutEx(p_Var3,&local_res8);
    KeReleaseMutex(p_Var1,0);
    pvVar4 = local_res8;
    if (-1 < (int)uVar5) {
      uVar7 = (ulonglong)*(uint *)((longlong)local_res8 + 4) * 0x90;
      if (uVar7 < 0x100000000) {
        uVar6 = (int)uVar7 + 0x30;
        bVar8 = uVar6 < 0x30;
        if (bVar8) {
          uVar5 = -(uint)bVar8 & 0xc0000095;
        }
        else {
          uVar5 = -(uint)bVar8 & 0xc0000095;
          if (*(uint *)(lVar2 + 8) < uVar6) {
            uVar5 = 0xc0000023;
          }
          else {
            memmove(*(void **)(param_2 + 0x18),local_res8,(ulonglong)uVar6);
            *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar6;
          }
        }
      }
      else {
        uVar5 = 0xc0000095;
      }
    }
    if (pvVar4 != (void *)0x0) {
      ExFreePoolWithTag(pvVar4,0);
    }
  }
  return uVar5;
}



===== PartitionIoctlBandmgmt @ 140026400 =====

undefined4 PartitionIoctlBandmgmt(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  undefined4 uVar3;
  longlong lVar4;
  ulonglong uVar5;
  longlong lVar6;
  char cVar7;
  int *piVar8;
  uint uVar9;
  ulonglong uVar10;
  longlong *plVar11;
  ulonglong *puVar12;
  
  piVar8 = (int *)0x0;
  lVar2 = *(longlong *)(param_1 + 0x40);
  plVar11 = (longlong *)0x0;
  puVar12 = (ulonglong *)0x0;
  uVar9 = 0;
  iVar1 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x18);
  lVar4 = *(longlong *)(param_2 + 0x18);
  if (iVar1 == 0x2d148c) {
    plVar11 = (longlong *)(lVar4 + 0x18);
LAB_14002644b:
    puVar12 = (ulonglong *)(lVar4 + 0x10);
    piVar8 = (int *)(lVar4 + 0xc);
  }
  else {
    if ((iVar1 == 0x2d149c) || (iVar1 == 0x2dd494)) {
      uVar9 = 0x18;
      piVar8 = (int *)(lVar4 + 4);
      puVar12 = (ulonglong *)(lVar4 + 8);
      goto LAB_140026459;
    }
    if (iVar1 == 0x2dd498) {
      uVar9 = 0x28;
      piVar8 = (int *)(lVar4 + 0xc);
      puVar12 = (ulonglong *)(lVar4 + 0x10);
      goto LAB_140026459;
    }
    if (iVar1 != 0x2dd4a0) {
      if (iVar1 != 0x2dd4a8) goto LAB_140026459;
      goto LAB_14002644b;
    }
    piVar8 = (int *)(lVar4 + 4);
    puVar12 = (ulonglong *)(lVar4 + 8);
  }
  uVar9 = 0x20;
LAB_140026459:
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10) < uVar9) {
    *(undefined4 *)(param_2 + 0x30) = 0xc0000004;
    IofCompleteRequest(param_2,0);
    uVar3 = 0xc0000004;
  }
  else {
    KeWaitForSingleObject(*(longlong *)(lVar2 + 0x18) + 0x38,0,0,0,0);
    lVar4 = PartitionOffset(lVar2,'\x01');
    if (lVar4 != *(longlong *)(lVar2 + 0xb0)) {
      uVar3 = FUN_14002a8a4();
      return uVar3;
    }
    lVar4 = 0x7fffffffffffffff;
    if ((*piVar8 == -1) && (uVar10 = *puVar12, uVar10 != 0x7fffffffffffffff)) {
      cVar7 = '\x01';
      uVar5 = PartitionLength(lVar2,'\x01');
      if (uVar5 <= uVar10) {
        uVar3 = FUN_14002a8a4();
        return uVar3;
      }
      lVar6 = PartitionOffset(lVar2,cVar7);
      *puVar12 = lVar6 + uVar10;
    }
    if ((plVar11 != (longlong *)0x0) && (*plVar11 == lVar4)) {
      lVar4 = PartitionLength(lVar2,'\x01');
      *plVar11 = lVar4;
    }
    KeReleaseMutex(*(longlong *)(lVar2 + 0x18) + 0x38,0);
    uVar3 = PartitionPassThrough(param_1,param_2);
  }
  return uVar3;
}



===== PmPnp @ 1400265b0 =====

/* long __cdecl PmPnp(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl PmPnp(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  char cVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  long lVar5;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  lVar3 = *(longlong *)(param_2 + 0xb8);
  iVar4 = IoAcquireRemoveLockEx(lVar2 + 0x78,param_2,"",1,0x20);
  if (iVar4 < 0) {
    *(int *)(param_2 + 0x30) = iVar4;
    IofCompleteRequest(param_2,0);
    return iVar4;
  }
  cVar1 = *(char *)(lVar3 + 1);
  if (cVar1 == '\a') {
    iVar4 = *(int *)(lVar3 + 8);
    if (iVar4 == 0) {
      lVar5 = PmQueryBusRelations(param_1,param_2);
      goto LAB_14002663b;
    }
    if (iVar4 == 3) {
      lVar5 = PmQueryRemovalRelations(param_1,param_2);
      goto LAB_14002663b;
    }
LAB_140026620:
    param_2[0x43] = (_IRP)((char)param_2[0x43] + '\x01');
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    lVar5 = IofCallDriver(*(undefined8 *)(lVar2 + 0x10),param_2);
  }
  else {
    switch(cVar1) {
    case '\0':
      lVar5 = PmStartDevice(param_1,param_2);
      return lVar5;
    case '\x01':
      lVar5 = PmQueryRemoveDevice(param_1,param_2);
      break;
    case '\x02':
      lVar5 = PmRemoveDevice(param_1,param_2);
      return lVar5;
    default:
      goto LAB_140026620;
    case '\x14':
      lVar5 = PmQueryPnpDeviceState(param_1,param_2);
      break;
    case '\x16':
      lVar5 = PmDeviceUsageNotification(param_1,param_2);
      break;
    case '\x17':
      lVar5 = PmSurpriseRemoval(param_1,param_2);
    }
  }
LAB_14002663b:
  IoReleaseRemoveLockEx(lVar2 + 0x78,param_2,0x20);
  return lVar5;
}



===== PmIoctlGetClusterInfo @ 1400266c0 =====

undefined8 PmIoctlGetClusterInfo(longlong param_1,longlong param_2)

{
  undefined4 *puVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 8) < 0x20) {
    uVar6 = 0xc0000023;
  }
  else {
    puVar1 = *(undefined4 **)(param_2 + 0x18);
    lVar2 = *(longlong *)(param_1 + 0x40);
    KeWaitForSingleObject(lVar2 + 0x38,0,0,0,0);
    uVar3 = *(undefined4 *)(lVar2 + 0x234);
    uVar4 = *(undefined4 *)(lVar2 + 0x238);
    uVar5 = *(undefined4 *)(lVar2 + 0x23c);
    *puVar1 = *(undefined4 *)(lVar2 + 0x230);
    puVar1[1] = uVar3;
    puVar1[2] = uVar4;
    puVar1[3] = uVar5;
    uVar3 = *(undefined4 *)(lVar2 + 0x244);
    uVar4 = *(undefined4 *)(lVar2 + 0x248);
    uVar5 = *(undefined4 *)(lVar2 + 0x24c);
    puVar1[4] = *(undefined4 *)(lVar2 + 0x240);
    puVar1[5] = uVar3;
    puVar1[6] = uVar4;
    puVar1[7] = uVar5;
    KeReleaseMutex(lVar2 + 0x38,0);
    uVar6 = 0;
    *(undefined8 *)(param_2 + 0x38) = 0x20;
  }
  return uVar6;
}



===== PartitionIoctlGetDeviceNumber @ 140026770 =====

undefined8 PartitionIoctlGetDeviceNumber(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 8) < 0xc) {
    uVar3 = 0xc0000023;
  }
  else {
    puVar2 = *(undefined8 **)(param_2 + 0x18);
    *puVar2 = 0;
    *(undefined4 *)(puVar2 + 1) = 0;
    KeWaitForSingleObject(*(longlong *)(lVar1 + 0x18) + 0x38,0,0,0,0);
    *(undefined4 *)((longlong)puVar2 + 4) = *(undefined4 *)(*(longlong *)(lVar1 + 0x18) + 0xa8);
    *(undefined4 *)puVar2 = *(undefined4 *)(*(longlong *)(lVar1 + 8) + 0x48);
    *(undefined4 *)(puVar2 + 1) = *(undefined4 *)(lVar1 + 0xc0);
    KeReleaseMutex(*(longlong *)(lVar1 + 0x18) + 0x38,0);
    uVar3 = 0;
    *(undefined8 *)(param_2 + 0x38) = 0xc;
  }
  return uVar3;
}



===== PmIoctlGetDriveGeometryEx @ 140026830 =====

uint PmIoctlGetDriveGeometryEx(longlong param_1,longlong param_2)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  _DEVICE_EXTENSION *p_Var4;
  longlong lVar5;
  undefined8 uVar6;
  uint uVar7;
  
  lVar3 = *(longlong *)(param_2 + 0xb8);
  p_Var4 = *(_DEVICE_EXTENSION **)(param_1 + 0x40);
  uVar1 = *(uint *)(lVar3 + 8);
  if (uVar1 < 0x20) {
    uVar7 = 0xc0000023;
  }
  else {
    memset(*(void **)(param_2 + 0x18),0,(ulonglong)uVar1);
    lVar5 = *(longlong *)(param_2 + 0x18);
    *(undefined4 *)(lVar3 + 8) = 0x18;
    *(undefined4 *)(lVar3 + 0x18) = 0x70000;
    IoForwardIrpSynchronously(*(undefined8 *)(p_Var4 + 0x10),param_2);
    uVar7 = *(uint *)(param_2 + 0x30);
    if (-1 < (int)uVar7) {
      *(undefined4 *)(lVar3 + 8) = 8;
      *(undefined4 *)(lVar3 + 0x18) = 0x7405c;
      *(longlong *)(param_2 + 0x18) = lVar5 + 0x18;
      IoForwardIrpSynchronously(*(undefined8 *)(p_Var4 + 0x10));
      uVar7 = *(uint *)(param_2 + 0x30);
      *(longlong *)(param_2 + 0x18) = lVar5;
      if (-1 < (int)uVar7) {
        if (uVar1 < 0x28) {
          *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar1;
        }
        else {
          *(undefined8 *)(param_2 + 0x38) = 0x28;
          if (0x37 < uVar1) {
            *(undefined8 *)(param_2 + 0x38) = 0x38;
            KeWaitForSingleObject(p_Var4 + 0x38,0,0,0,0);
            uVar7 = PmGetDriveLayoutEx(p_Var4,(undefined8 *)0x0);
            if (-1 < (int)uVar7) {
              *(undefined4 *)(lVar5 + 0x20) = 0x18;
              iVar2 = *(int *)(p_Var4 + 0x390);
              *(int *)(lVar5 + 0x24) = iVar2;
              if (iVar2 == 0) {
                *(undefined4 *)(lVar5 + 0x28) = *(undefined4 *)(p_Var4 + 0x398);
                *(undefined4 *)(lVar5 + 0x2c) = *(undefined4 *)(p_Var4 + 0x39c);
              }
              else if (iVar2 == 1) {
                uVar6 = *(undefined8 *)(p_Var4 + 0x3a0);
                *(undefined8 *)(lVar5 + 0x28) = *(undefined8 *)(p_Var4 + 0x398);
                *(undefined8 *)(lVar5 + 0x30) = uVar6;
              }
            }
            KeReleaseMutex(p_Var4 + 0x38,0);
            if (0x6f < uVar1) {
              *(undefined8 *)(param_2 + 0x38) = 0x70;
              *(undefined8 *)((ulonglong)*(uint *)(lVar5 + 0x20) + 0x20 + lVar5) = 0x38;
            }
          }
        }
      }
    }
  }
  return uVar7;
}



===== PartitionIoctlGetLengthInfo @ 1400269d0 =====

uint PartitionIoctlGetLengthInfo(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong *plVar2;
  uint uVar3;
  longlong lVar4;
  
  lVar4 = *(longlong *)(param_2 + 0xb8);
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (*(uint *)(lVar4 + 8) < 8) {
    return 0xc0000023;
  }
  plVar2 = *(longlong **)(param_2 + 0x18);
  *plVar2 = 0;
  KeWaitForSingleObject(*(longlong *)(lVar1 + 0x18) + 0x38,0,0,0,0);
  if (((*(byte *)(lVar4 + 2) & 2) != 0) && ((*(uint *)(*(longlong *)(lVar1 + 8) + 0x34) & 1) != 0))
  {
    PmInvalidatePartitionTableCache(*(longlong *)(lVar1 + 0x18));
  }
  uVar3 = PmGetDriveLayoutEx(*(_DEVICE_EXTENSION **)(lVar1 + 0x18),(undefined8 *)0x0);
  if (-1 < (int)uVar3) {
    lVar4 = PartitionLength(lVar1,'\x01');
    *plVar2 = lVar4;
    *(undefined8 *)(param_2 + 0x38) = 8;
  }
  KeReleaseMutex(*(longlong *)(lVar1 + 0x18) + 0x38,0);
  return uVar3;
}



===== PmConstructDeviceLocation @ 140026ab4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl PmConstructDeviceLocation(struct _DEVICE_EXTENSION * __ptr64,struct _IRP * __ptr64)
    */

long __cdecl PmConstructDeviceLocation(_DEVICE_EXTENSION *param_1,_IRP *param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined2 *_Dst;
  _DEVICE_OBJECT *p_Var6;
  undefined1 auStackY_c8 [32];
  undefined8 local_78;
  undefined4 local_68 [2];
  undefined4 local_60;
  undefined4 local_5c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_c8;
  memset(local_68,0,0x40);
  lVar4 = 0;
  if (*(longlong *)(param_1 + 0x18) != 0) {
    lVar4 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x18) + 0x138) + 0x28);
  }
  p_Var6 = (_DEVICE_OBJECT *)0x0;
  local_78 = 0;
  if (lVar4 != 0) {
    p_Var6 = *(_DEVICE_OBJECT **)(*(longlong *)(lVar4 + 0x10) + 0x20);
  }
  lVar4 = *(longlong *)(param_2 + 0xb8);
  local_68[0] = 0x10040;
  _Dst = (undefined2 *)(lVar4 + -0x48);
  local_5c = 0xffffffff;
  local_60 = 0xffffffff;
  memset(_Dst,0,0x48);
  *_Dst = 0x91b;
  *(undefined4 **)(lVar4 + -0x40) = local_68;
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0xc00000bb;
  iVar2 = IoSynchronousCallDriver(*(undefined8 *)(param_1 + 0x10),param_2);
  if (-1 < iVar2) {
    *(undefined4 *)(param_1 + 0x19c) = local_5c;
  }
  if (p_Var6 != (_DEVICE_OBJECT *)0x0) {
    iVar2 = IoGetDevicePropertyData(p_Var6,&DEVPKEY_Device_BusNumber);
    if (-1 < iVar2) {
      *(undefined4 *)(param_1 + 0x1b0) = 0;
    }
    iVar2 = IoGetDevicePropertyData(p_Var6,&DEVPKEY_Device_Address);
    if (-1 < iVar2) {
      *(undefined4 *)(param_1 + 0x1b4) = 0;
      *(undefined4 *)(param_1 + 0x1b8) = 0;
    }
  }
  uVar5 = PmSendDeviceControl(*(undefined8 *)(param_1 + 0x10),0x41018,0,0,&local_78,8,0);
  iVar2 = (int)uVar5;
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  else {
    *(uint *)(param_1 + 0x1a0) = (uint)local_78._4_1_;
    *(uint *)(param_1 + 0x1a4) = (uint)local_78._5_1_;
    *(uint *)(param_1 + 0x1a8) = (uint)local_78._6_1_;
    *(uint *)(param_1 + 0x1ac) = (uint)local_78._7_1_;
  }
  iVar1 = *(int *)(*(longlong *)(param_1 + 0xe8) + 0x1c);
  if (iVar1 < 10) {
    if (iVar1 == 9) {
LAB_140026d28:
      PmConstructDeviceLocationNetworkStorage(param_1);
      return iVar2;
    }
    if (((iVar1 != 1) && (iVar1 != 2)) &&
       ((iVar1 != 3 &&
        ((((iVar1 != 4 && (iVar1 != 5)) && (iVar1 != 6)) && ((iVar1 != 7 && (iVar1 != 8)))))))) {
      return iVar2;
    }
  }
  else if ((((iVar1 != 10) && (iVar1 != 0xb)) && (iVar1 != 0xc)) && (iVar1 != 0xd)) {
    if (iVar1 == 0xf) {
      PmConstructDeviceLocationVhd(param_1);
      return iVar2;
    }
    if (iVar1 == 0x11) {
      if ((p_Var6 != (_DEVICE_OBJECT *)0x0) &&
         (lVar3 = PmGetDevicePropertyString
                            (p_Var6,(_DEVPROPKEY *)&DEVPKEY_PciDevice_Label_String,
                             (_UNICODE_STRING *)(param_1 + 0x1c0)), -1 < lVar3)) {
        return lVar3;
      }
    }
    else if (iVar1 != 0x13) {
      if (iVar1 != 0x14) {
        return iVar2;
      }
      goto LAB_140026d28;
    }
  }
  lVar3 = PmConstructDeviceLocationDefault(param_1);
  return lVar3;
}



===== PmReadSnapshotData @ 140026d6c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl PmReadSnapshotData(struct _DEVICE_EXTENSION * __ptr64,struct
   _DRIVE_LAYOUT_INFORMATION_EX * __ptr64,struct _DISK_SNAPSHOT_DATA * __ptr64 * __ptr64,unsigned
   long * __ptr64) */

long __cdecl
PmReadSnapshotData(_DEVICE_EXTENSION *param_1,_DRIVE_LAYOUT_INFORMATION_EX *param_2,
                  _DISK_SNAPSHOT_DATA **param_3,ulong *param_4)

{
  byte *pbVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  _DISK_SNAPSHOT_DATA *p_Var5;
  uint uVar6;
  undefined1 auStackY_c8 [32];
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined4 local_58;
  undefined8 local_54;
  undefined8 uStack_4c;
  int local_44;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_c8;
  *param_3 = (_DISK_SNAPSHOT_DATA *)0x0;
  local_58 = 0;
  *param_4 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_70 = 0;
  local_54 = 0;
  uStack_4c = 0;
  local_44 = 0;
  local_68 = 0;
  uStack_60 = 0;
  uVar3 = PmSendDeviceControl(*(undefined8 *)(param_1 + 8),0x70000,0,0,&local_58,0x18,0);
  iVar2 = (int)uVar3;
  if (-1 < iVar2) {
    if (*(int *)param_2 == 0) {
      uVar6 = local_44 * 4;
      for (uVar3 = 0; (uint)uVar3 < *(uint *)(param_2 + 4); uVar3 = (ulonglong)((uint)uVar3 + 1)) {
        if ((param_2[uVar3 * 0x90 + 0x50] != (_DRIVE_LAYOUT_INFORMATION_EX)0x0) &&
           ((*(longlong *)(param_2 + uVar3 * 0x90 + 0x38) <
             (longlong)(ulonglong)(uint)(local_44 * 7) ||
            ((longlong)
             (*(longlong *)(param_2 + uVar3 * 0x90 + 0x38) - (ulonglong)(uint)(local_44 * 7)) <
             (longlong)(ulonglong)uVar6)))) goto LAB_140026eb8;
      }
LAB_140026e4a:
      p_Var5 = (_DISK_SNAPSHOT_DATA *)ExAllocatePool2(0x42,uVar6,0x44536d50);
      if (p_Var5 == (_DISK_SNAPSHOT_DATA *)0x0) {
        iVar2 = -0x3fffff66;
      }
      else {
        KeInitializeEvent(&local_80,0,0);
        lVar4 = IoBuildSynchronousFsdRequest(3,*(undefined8 *)(param_1 + 8),p_Var5,uVar6);
        if (lVar4 == 0) {
          iVar2 = -0x3fffff66;
        }
        else {
          pbVar1 = (byte *)(*(longlong *)(lVar4 + 0xb8) + -0x46);
          *pbVar1 = *pbVar1 | 2;
          iVar2 = IofCallDriver(*(undefined8 *)(param_1 + 8));
          if (iVar2 == 0x103) {
            KeWaitForSingleObject(&local_80,0,0,0);
            iVar2 = (int)local_68;
          }
          if (-1 < iVar2) {
            *param_3 = p_Var5;
            *param_4 = uVar6;
            return iVar2;
          }
        }
        ExFreePoolWithTag(p_Var5,0);
      }
    }
    else {
      if (*(int *)param_2 == 1) {
        for (uVar3 = 0; (uint)uVar3 < *(uint *)(param_2 + 4); uVar3 = (ulonglong)((uint)uVar3 + 1))
        {
          lVar4 = *(longlong *)(param_2 + uVar3 * 0x90 + 0x50) + -0x4de84400caddebf1;
          if (lVar4 == 0) {
            lVar4 = *(longlong *)(param_2 + uVar3 * 0x90 + 0x58) + 0x30c33082eeedfc4f;
          }
          if (lVar4 == 0) {
            uVar6 = *(uint *)(param_2 + uVar3 * 0x90 + 0x40);
            goto LAB_140026e4a;
          }
        }
      }
LAB_140026eb8:
      iVar2 = -0x3ffffddb;
    }
  }
  return iVar2;
}



===== PmGetDriveGeometry @ 140026fa4 =====

void PmGetDriveGeometry(undefined8 param_1,undefined8 param_2)

{
  PmSendDeviceControl(param_1,0x70000,0,0,param_2,0x18,0);
  return;
}



===== PmReadPartitionAttributesMbr @ 140026fd8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl PmReadPartitionAttributesMbr(struct _DEVICE_EXTENSION * __ptr64,struct
   _PARTITION_ATTRIBUTES_TABLE * __ptr64 * __ptr64,unsigned long * __ptr64) */

long __cdecl
PmReadPartitionAttributesMbr
          (_DEVICE_EXTENSION *param_1,_PARTITION_ATTRIBUTES_TABLE **param_2,ulong *param_3)

{
  byte *pbVar1;
  ulong uVar2;
  int iVar3;
  ulonglong uVar4;
  _PARTITION_ATTRIBUTES_TABLE *p_Var5;
  longlong lVar6;
  undefined1 auStackY_c8 [32];
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined4 local_58;
  undefined8 local_54;
  undefined8 uStack_4c;
  ulong local_44;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_c8;
  *param_2 = (_PARTITION_ATTRIBUTES_TABLE *)0x0;
  local_58 = 0;
  *param_3 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_70 = 0;
  local_54 = 0;
  uStack_4c = 0;
  local_44 = 0;
  local_68 = 0;
  uStack_60 = 0;
  uVar4 = PmSendDeviceControl(*(undefined8 *)(param_1 + 8),0x70000,0,0,&local_58,0x18,0);
  uVar2 = local_44;
  iVar3 = (int)uVar4;
  if (-1 < iVar3) {
    p_Var5 = (_PARTITION_ATTRIBUTES_TABLE *)ExAllocatePool2(0x42,local_44,0x54416d50);
    if (p_Var5 == (_PARTITION_ATTRIBUTES_TABLE *)0x0) {
      iVar3 = -0x3fffff66;
    }
    else {
      KeInitializeEvent(&local_80,0,0);
      lVar6 = IoBuildSynchronousFsdRequest(3,*(undefined8 *)(param_1 + 8),p_Var5,uVar2);
      if (lVar6 == 0) {
        iVar3 = -0x3fffff66;
      }
      else {
        pbVar1 = (byte *)(*(longlong *)(lVar6 + 0xb8) + -0x46);
        *pbVar1 = *pbVar1 | 2;
        iVar3 = IofCallDriver(*(undefined8 *)(param_1 + 8));
        if (iVar3 == 0x103) {
          KeWaitForSingleObject(&local_80,0,0,0);
          iVar3 = (int)local_68;
        }
        if (-1 < iVar3) {
          *param_2 = p_Var5;
          *param_3 = uVar2;
          return iVar3;
        }
      }
      ExFreePoolWithTag(p_Var5,0);
    }
  }
  return iVar3;
}



===== PmQueryStorageProperty @ 140027180 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl PmQueryStorageProperty(struct _DEVICE_EXTENSION * __ptr64,enum
   _STORAGE_PROPERTY_ID,unsigned long,void * __ptr64 * __ptr64) */

long __cdecl
PmQueryStorageProperty
          (_DEVICE_EXTENSION *param_1,_STORAGE_PROPERTY_ID param_2,ulong param_3,void **param_4)

{
  int iVar1;
  ulonglong uVar2;
  void *pvVar3;
  undefined1 auStackY_98 [32];
  undefined8 local_58;
  _STORAGE_PROPERTY_ID local_50 [4];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_98;
  local_50[2] = 0;
  local_58 = 0;
  local_50[1] = 0;
  local_50[0] = param_2;
  uVar2 = PmSendDeviceControl(*(undefined8 *)(param_1 + 0x10),0x2d1400,local_50,0xc,&local_58,8,0);
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_3 < local_58._4_4_) {
      param_3 = local_58._4_4_;
    }
    pvVar3 = (void *)ExAllocatePool2(0x40,param_3,0x42496d50);
    if (pvVar3 == (void *)0x0) {
      iVar1 = -0x3fffff66;
    }
    else {
      local_50[1] = 0;
      local_50[0] = param_2;
      uVar2 = PmSendDeviceControl(*(undefined8 *)(param_1 + 0x10),0x2d1400,local_50,0xc,pvVar3,
                                  param_3,0);
      iVar1 = (int)uVar2;
      if (iVar1 < 0) {
        ExFreePoolWithTag(pvVar3,0);
      }
      else {
        if (*(ulong *)((longlong)pvVar3 + 4) != param_3) {
          *(ulong *)((longlong)pvVar3 + 4) = param_3;
        }
        if (*param_4 != (void *)0x0) {
          ExFreePoolWithTag(*param_4,0);
        }
        *param_4 = pvVar3;
      }
    }
  }
  return iVar1;
}



===== Control @ 1400272a0 =====

/* public: virtual long __cdecl PM_DISK::Control(unsigned long,void * __ptr64,unsigned long,void *
   __ptr64,unsigned long) __ptr64 */

long __thiscall
PM_DISK::Control(PM_DISK *this,ulong param_1,void *param_2,ulong param_3,void *param_4,ulong param_5
                )

{
  ulonglong uVar1;
  
  uVar1 = PmSendDeviceControl(*(undefined8 *)(this + 400),param_1,param_2,param_3,param_4,param_5,0)
  ;
  return (long)uVar1;
}



===== PmSendDeviceControl @ 1400272d4 =====

ulonglong PmSendDeviceControl(undefined8 param_1,undefined4 param_2,undefined8 param_3,
                             undefined4 param_4,undefined8 param_5,undefined4 param_6,
                             undefined1 param_7)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong local_38 [2];
  undefined4 local_28;
  undefined8 local_24;
  undefined8 uStack_1c;
  undefined4 local_14;
  
  local_28 = 0;
  local_14 = 0;
  local_24 = 0;
  uStack_1c = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  KeInitializeEvent(&local_28,0,0);
  lVar1 = IoBuildDeviceIoControlRequest
                    (param_2,param_1,param_3,param_4,param_5,param_6,param_7,&local_28,local_38);
  if (lVar1 == 0) {
    uVar2 = 0xc000009a;
  }
  else {
    uVar2 = IofCallDriver(param_1,lVar1);
    if ((int)uVar2 == 0x103) {
      KeWaitForSingleObject(&local_28,0,0,0,0);
      uVar2 = local_38[0] & 0xffffffff;
    }
  }
  return uVar2;
}



===== PmPowerChanged @ 1400273e0 =====

/* void __cdecl PmPowerChanged(struct _DEVICE_EXTENSION * __ptr64,struct _LIST_ENTRY * __ptr64) */

void __cdecl PmPowerChanged(_DEVICE_EXTENSION *param_1,_LIST_ENTRY *param_2)

{
  char *pcVar1;
  longlong *plVar2;
  _LIST_ENTRY *p_Var3;
  longlong lVar4;
  undefined8 uVar5;
  undefined1 *puVar6;
  ulonglong uVar7;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  p_Var3 = *(_LIST_ENTRY **)param_2;
  local_18 = 0;
  for (; p_Var3 != param_2; p_Var3 = *(_LIST_ENTRY **)p_Var3) {
    if (*(longlong *)(p_Var3 + -8) != 0) {
      local_28 = *(undefined8 *)(p_Var3 + -0x70);
      uStack_20 = *(undefined8 *)(param_1 + 0x18);
      uVar7 = (ulonglong)local_18 >> 0x20;
      local_18 = CONCAT44((int)uVar7,*(undefined4 *)(param_1 + 0x260));
      IoReuseIrp(*(undefined8 *)(param_1 + 0x358),0xc00000bb);
      lVar4 = *(longlong *)(param_1 + 0x358);
      pcVar1 = (char *)(lVar4 + 0x43);
      *pcVar1 = *pcVar1 + -1;
      plVar2 = (longlong *)(lVar4 + 0xb8);
      *plVar2 = *plVar2 + -0x48;
      lVar4 = *(longlong *)(param_1 + 0x358);
      uVar5 = *(undefined8 *)(*(longlong *)(p_Var3 + -8) + 0x28);
      puVar6 = *(undefined1 **)(lVar4 + 0xb8);
      *puVar6 = 0xf;
      *(undefined8 **)(lVar4 + 0x18) = &local_28;
      *(undefined4 *)(puVar6 + 8) = 0;
      *(undefined4 *)(puVar6 + 0x10) = 0x18;
      *(undefined4 *)(puVar6 + 0x18) = 0x760028;
      IoForwardIrpSynchronously(uVar5);
    }
  }
  return;
}



===== PmGetRegistryId @ 1400274c4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl PmGetRegistryId(struct _DEVICE_EXTENSION * __ptr64,struct _GUID * __ptr64) */

long __cdecl PmGetRegistryId(_DEVICE_EXTENSION *param_1,_GUID *param_2)

{
  long lVar1;
  undefined1 auStack_f8 [32];
  undefined8 local_d8;
  uint local_d0;
  void *local_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_a8;
  undefined4 local_a0 [2];
  wchar_t *local_98;
  undefined8 *local_90;
  undefined4 local_88;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_f8;
  local_c8 = (void *)0x0;
  local_a8 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  memset(local_a0,0,0x68);
  *(undefined8 *)param_2 = 0;
  *(undefined8 *)(param_2 + 8) = 0;
  lVar1 = PmOpenDeviceParameter(param_1,&local_c8);
  if (lVar1 < 0) goto LAB_14002760d;
  local_90 = &local_c0;
  local_a8 = 0;
  local_d8 = 0;
  local_98 = L"DiskId";
  local_a0[0] = 0x124;
  local_88 = 0x1000000;
  lVar1 = RtlQueryRegistryValuesEx(0x40000000,local_c8,&local_a8,0);
  if (lVar1 < 0) {
    if (lVar1 != -0x3fffffcc) goto LAB_14002760d;
    lVar1 = ExUuidCreate(&local_38);
    if (lVar1 < 0) goto LAB_14002760d;
    lVar1 = RtlStringFromGUID(&local_38,&local_c0);
    if (lVar1 < 0) goto LAB_14002760d;
    local_d0 = (uint)local_c0._2_2_;
    local_d8 = uStack_b8;
    lVar1 = RtlWriteRegistryValue(0x40000000,local_c8,L"DiskId",1);
  }
  else {
    lVar1 = RtlGUIDFromString(&local_c0,&local_38);
  }
  if (-1 < lVar1) {
    *(undefined8 *)param_2 = local_38;
    *(undefined8 *)(param_2 + 8) = uStack_30;
  }
LAB_14002760d:
  RtlFreeUnicodeString(&local_c0);
  if (local_c8 != (void *)0x0) {
    ZwClose(local_c8);
  }
  return lVar1;
}



===== PmGetDeviceParameter @ 140027660 =====

long PmGetDeviceParameter(_DEVICE_EXTENSION *param_1,undefined8 param_2,undefined8 param_3)

{
  void *pvVar1;
  long lVar2;
  void *local_res10;
  undefined8 local_78;
  undefined4 local_70 [2];
  wchar_t *local_68;
  undefined8 local_60;
  undefined4 local_58;
  
  local_res10 = (void *)0x0;
  local_78 = 0;
  memset(local_70,0,0x68);
  lVar2 = PmOpenDeviceParameter(param_1,&local_res10);
  pvVar1 = local_res10;
  if (-1 < lVar2) {
    local_78 = 0;
    local_68 = L"Attributes";
    local_70[0] = 0x124;
    local_58 = 0x4000000;
    local_60 = param_3;
    lVar2 = RtlQueryRegistryValuesEx(0x40000000,local_res10,&local_78,0,0);
  }
  if (pvVar1 != (void *)0x0) {
    ZwClose(pvVar1);
  }
  return lVar2;
}



===== PmSetDeviceParameterBinary @ 140027734 =====

long PmSetDeviceParameterBinary
               (_DEVICE_EXTENSION *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  long lVar1;
  void *local_18 [2];
  
  local_18[0] = (void *)0x0;
  lVar1 = PmOpenDeviceParameter(param_1,local_18);
  if (-1 < lVar1) {
    lVar1 = RtlWriteRegistryValue(0x40000000,local_18[0],param_2,3,param_3,param_4);
  }
  if (local_18[0] != (void *)0x0) {
    ZwClose(local_18[0]);
  }
  return lVar1;
}



===== PmOpenDeviceParameter @ 1400277cc =====

/* long __cdecl PmOpenDeviceParameter(struct _DEVICE_EXTENSION * __ptr64,void * __ptr64 * __ptr64)
    */

long __cdecl PmOpenDeviceParameter(_DEVICE_EXTENSION *param_1,void **param_2)

{
  int iVar1;
  void *local_res8;
  longlong local_res10;
  undefined8 local_38;
  longlong lStack_30;
  undefined *local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  *param_2 = (void *)0x0;
  local_res10 = 0;
  local_res8 = (void *)0x0;
  local_38 = 0;
  lStack_30 = 0;
  local_28 = (undefined *)0x0;
  uStack_20 = 0;
  local_18 = 0;
  uStack_10 = 0;
  iVar1 = IoOpenDeviceRegistryKey(*(undefined8 *)(param_1 + 0x18),1,0x20019,&local_res10);
  if (iVar1 < 0) {
    local_res10 = 0;
  }
  else {
    lStack_30 = local_res10;
    local_38 = CONCAT44(local_38._4_4_,0x30);
    local_28 = &Partmgr;
    uStack_20 = CONCAT44(uStack_20._4_4_,0x240);
    local_18 = 0;
    uStack_10 = 0;
    iVar1 = ZwCreateKey(&local_res8,0x2001f,&local_38,0,0,0,0);
    if (iVar1 < 0) {
      local_res8 = (void *)0x0;
      goto LAB_140027895;
    }
    *param_2 = local_res8;
    local_res8 = (void *)0x0;
  }
  if (local_res8 != (void *)0x0) {
    ZwClose();
  }
LAB_140027895:
  if (local_res10 != 0) {
    ZwClose();
  }
  return iVar1;
}



===== PmIoctlGetDiskAttributes @ 1400278e8 =====

undefined8 PmIoctlGetDiskAttributes(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  
  uVar3 = 0;
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 8) < 0x10) {
    uVar3 = 0xc0000023;
  }
  else {
    puVar2 = *(undefined8 **)(param_2 + 0x18);
    *puVar2 = 0;
    puVar2[1] = 0;
    KeWaitForSingleObject(lVar1 + 0x38,0,0,0,0);
    *(undefined4 *)puVar2 = 0x10;
    puVar2[1] = *(undefined8 *)(lVar1 + 0x210);
    KeReleaseMutex(lVar1 + 0x38,0);
    *(undefined8 *)(param_2 + 0x38) = 0x10;
  }
  return uVar3;
}



===== PmIoctlIsWritable @ 140027994 =====

uint PmIoctlIsWritable(longlong param_1,longlong param_2)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  KeWaitForSingleObject(lVar1 + 0x38,0,0,0,0);
  uVar3 = *(uint *)(lVar1 + 0x210) & 2;
  KeReleaseMutex(lVar1 + 0x38,0);
  uVar2 = -(uint)(uVar3 != 0) & 0xc00000a2;
  if (uVar3 == 0) {
    IoForwardIrpSynchronously(*(undefined8 *)(lVar1 + 0x10),param_2);
    uVar2 = *(uint *)(param_2 + 0x30);
  }
  return uVar2;
}



===== PmTableGuidCompareRoutine @ 140027a30 =====

char PmTableGuidCompareRoutine(undefined8 param_1,longlong param_2,longlong param_3)

{
  char cVar1;
  int iVar2;
  
  iVar2 = memcmp((void *)(param_2 + 0x18),(void *)(param_3 + 0x18),0x10);
  cVar1 = '\0';
  if (-1 < iVar2) {
    cVar1 = (iVar2 < 1) + '\x01';
  }
  return cVar1;
}



===== PmIoctlQueryDeviceState @ 140027a68 =====

undefined8 PmIoctlQueryDeviceState(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  
  uVar3 = 0;
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 8) < 0x18) {
    uVar3 = 0xc0000023;
  }
  else {
    puVar2 = *(undefined8 **)(param_2 + 0x18);
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    KeWaitForSingleObject(lVar1 + 0x38,0,0,0,0);
    *(undefined4 *)puVar2 = 0x18;
    *(undefined4 *)((longlong)puVar2 + 4) = *(undefined4 *)(lVar1 + 0x204);
    *(undefined4 *)(puVar2 + 1) = *(undefined4 *)(lVar1 + 0x250);
    *(undefined4 *)((longlong)puVar2 + 0xc) = *(undefined4 *)(lVar1 + 0x254);
    *(undefined4 *)(puVar2 + 2) = *(undefined4 *)(lVar1 + 600);
    *(undefined1 *)((longlong)puVar2 + 0x14) = *(undefined1 *)(lVar1 + 0x25c);
    KeReleaseMutex(lVar1 + 0x38,0);
    *(undefined8 *)(param_2 + 0x38) = 0x18;
  }
  return uVar3;
}



===== PmIoctlGetPartitionInfoEx @ 140027b44 =====

uint PmIoctlGetPartitionInfoEx(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  _DEVICE_EXTENSION *p_Var3;
  int *_Dst;
  undefined8 uVar4;
  undefined8 uVar5;
  uint uVar6;
  undefined8 local_res8;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  p_Var3 = *(_DEVICE_EXTENSION **)(param_1 + 0x40);
  local_res8 = 0;
  if (*(uint *)(lVar2 + 8) < 0x90) {
    uVar6 = 0xc0000023;
  }
  else {
    _Dst = *(int **)(param_2 + 0x18);
    *(undefined4 *)(lVar2 + 8) = 8;
    *(undefined4 *)(lVar2 + 0x10) = 0;
    *(undefined4 *)(lVar2 + 0x18) = 0x7405c;
    *(undefined8 **)(param_2 + 0x18) = &local_res8;
    IoForwardIrpSynchronously(*(undefined8 *)(p_Var3 + 0x10));
    uVar6 = *(uint *)(param_2 + 0x30);
    *(int **)(param_2 + 0x18) = _Dst;
    if (-1 < (int)uVar6) {
      memset(_Dst,0,0x90);
      KeWaitForSingleObject(p_Var3 + 0x38,0,0,0,0);
      uVar6 = PmGetDriveLayoutEx(p_Var3,(undefined8 *)0x0);
      if (-1 < (int)uVar6) {
        iVar1 = *(int *)(p_Var3 + 0x390);
        *_Dst = iVar1;
        _Dst[2] = 0;
        _Dst[3] = 0;
        *(undefined8 *)(_Dst + 4) = local_res8;
        _Dst[6] = 0;
        *(undefined1 *)(_Dst + 7) = 0;
        if (iVar1 == 0) {
          *(undefined2 *)(_Dst + 8) = 0;
          *(undefined1 *)((longlong)_Dst + 0x22) = 0;
          _Dst[9] = 0;
        }
        else if (iVar1 == 1) {
          _Dst[8] = 0;
          _Dst[9] = 0;
          _Dst[10] = 0;
          _Dst[0xb] = 0;
          uVar4 = *(undefined8 *)(p_Var3 + 0x398);
          uVar5 = *(undefined8 *)(p_Var3 + 0x3a0);
          _Dst[0x10] = 0;
          _Dst[0x11] = 0;
          *(undefined8 *)(_Dst + 0xc) = uVar4;
          *(undefined8 *)(_Dst + 0xe) = uVar5;
          *(undefined2 *)(_Dst + 0x12) = 0;
        }
        *(undefined8 *)(param_2 + 0x38) = 0x90;
      }
      KeReleaseMutex(p_Var3 + 0x38,0);
    }
  }
  return uVar6;
}



===== PmReadPartitionTable @ 140027c94 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long PmReadPartitionTable(undefined8 param_1,undefined8 *param_2)

{
  long lVar1;
  SC_DISK_LAYOUT *pSVar2;
  ulong uVar3;
  SC_DISK_LAYOUT **ppSVar4;
  SC_DISK_LAYOUT *pSVar5;
  undefined1 auStack_1f8 [32];
  SC_DISK_LAYOUT *local_1d8 [2];
  undefined **local_1c8 [25];
  byte local_100;
  longlong local_40;
  undefined8 local_38;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_1f8;
  SC_DISK::SC_DISK((SC_DISK *)local_1c8);
  local_40 = 0;
  local_38 = 0;
  local_1d8[0] = (SC_DISK_LAYOUT *)0x0;
  *param_2 = 0;
  local_1c8[0] = &PM_DISK::_vftable_;
  local_40 = IoGetDeviceAttachmentBaseRef(param_1);
  local_38 = param_1;
  lVar1 = SC_DISK::Initialize((SC_DISK *)local_1c8);
  if (-1 < lVar1) {
    lVar1 = SC_DISK::InitializePartitionCache((SC_DISK *)local_1c8);
  }
  if (-1 < lVar1) {
    ppSVar4 = local_1d8;
    lVar1 = SC_DISK::ReadPartitionTable((SC_DISK *)local_1c8,ppSVar4);
    pSVar2 = local_1d8[0];
    uVar3 = (ulong)ppSVar4;
    if (lVar1 < 0) {
    }
    else {
      if ((local_100 & 2) != 0) {
        pSVar5 = local_1d8[0];
        SC_DISK::WritePartitionTable((SC_DISK *)local_1c8,local_1d8[0]);
        uVar3 = (ulong)pSVar5;
      }
      *param_2 = pSVar2;
      pSVar2 = (SC_DISK_LAYOUT *)0x0;
    }
    if (pSVar2 != (SC_DISK_LAYOUT *)0x0) {
      SC_ENV::Free(pSVar2,uVar3);
    }
  }
  local_1c8[0] = &PM_DISK::_vftable_;
  if (local_40 != 0) {
    ObfDereferenceObject();
  }
  SC_DISK::~SC_DISK((SC_DISK *)local_1c8);
  return lVar1;
}



===== PartitionIoctlGetPartitionAttributes @ 140027de0 =====

uint PartitionIoctlGetPartitionAttributes(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 *puVar3;
  uint uVar4;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  lVar2 = *(longlong *)(param_1 + 0x40);
  if (*(uint *)(lVar1 + 8) < 0x10) {
    return 0xc0000023;
  }
  puVar3 = *(undefined8 **)(param_2 + 0x18);
  *puVar3 = 0;
  puVar3[1] = 0;
  KeWaitForSingleObject(*(longlong *)(lVar2 + 0x18) + 0x38,0,0,0,0);
  if (((*(byte *)(lVar1 + 2) & 2) != 0) && ((*(uint *)(*(longlong *)(lVar2 + 8) + 0x34) & 1) != 0))
  {
    PmInvalidatePartitionTableCache(*(longlong *)(lVar2 + 0x18));
  }
  uVar4 = PmGetDriveLayoutEx(*(_DEVICE_EXTENSION **)(lVar2 + 0x18),(undefined8 *)0x0);
  if (-1 < (int)uVar4) {
    if (*(int *)(lVar2 + 0xa8) == 0) {
      uVar4 = PmGetPartitionAttributesMbr(*(_DEVICE_EXTENSION **)(lVar2 + 0x18),puVar3 + 1);
      if ((int)uVar4 < 0) goto LAB_140027e71;
    }
    else {
      if (*(int *)(lVar2 + 0xa8) != 1) {
        uVar4 = 0xc0000010;
        goto LAB_140027e71;
      }
      puVar3[1] = *(undefined8 *)(lVar2 + 0xe8);
    }
    *(undefined8 *)(param_2 + 0x38) = 0x10;
  }
LAB_140027e71:
  KeReleaseMutex(*(longlong *)(lVar2 + 0x18) + 0x38,0);
  return uVar4;
}



===== GetPnpProperty @ 140027ee0 =====

/* public: virtual long __cdecl PM_DISK::GetPnpProperty(void * __ptr64,void * __ptr64 * __ptr64)
   __ptr64 */

long __thiscall PM_DISK::GetPnpProperty(PM_DISK *this,void *param_1,void **param_2)

{
  int iVar1;
  
  iVar1 = PmGetDevicePropertyData(*(undefined8 *)(this + 0x188),param_1,(longlong *)param_2);
  return iVar1;
}



===== PmGetDevicePropertyData @ 140027efc =====

int PmGetDevicePropertyData(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  int iVar1;
  longlong lVar2;
  undefined4 local_res20 [2];
  undefined4 local_28 [4];
  
  local_res20[0] = 0;
  local_28[0] = 0;
  iVar1 = IoGetDevicePropertyData(param_1,param_2,0,0,0,0,local_res20,local_28);
  if (iVar1 == -0x3fffffdd) {
    lVar2 = ExAllocatePool2(0x42,local_res20[0],0x42496d50);
    if (lVar2 == 0) {
      iVar1 = -0x3fffff66;
    }
    else {
      iVar1 = IoGetDevicePropertyData(param_1,param_2,0,0,local_res20[0],lVar2,local_res20,local_28)
      ;
      if (iVar1 < 0) {
        ExFreePoolWithTag(lVar2,0);
      }
      else {
        *param_3 = lVar2;
      }
    }
  }
  return iVar1;
}



===== Initialize @ 140028008 =====

/* public: long __cdecl PM_DISK::Initialize(struct _DEVICE_OBJECT * __ptr64,unsigned char) __ptr64
    */

long __thiscall PM_DISK::Initialize(PM_DISK *this,_DEVICE_OBJECT *param_1,uchar param_2)

{
  undefined8 uVar1;
  long lVar2;
  
  uVar1 = IoGetDeviceAttachmentBaseRef(param_1);
  *(_DEVICE_OBJECT **)(this + 400) = param_1;
  *(undefined8 *)(this + 0x188) = uVar1;
  lVar2 = SC_DISK::Initialize((SC_DISK *)this);
  if ((-1 < lVar2) && (param_2 != '\0')) {
    lVar2 = SC_DISK::InitializePartitionCache((SC_DISK *)this);
  }
  return lVar2;
}



===== Read @ 140028070 =====

/* public: virtual long __cdecl PM_DISK::Read(unsigned __int64,unsigned long,unsigned char *
   __ptr64) __ptr64 */

long __thiscall PM_DISK::Read(PM_DISK *this,__uint64 param_1,ulong param_2,uchar *param_3)

{
  byte *pbVar1;
  long lVar2;
  longlong lVar3;
  __uint64 local_res10 [3];
  
  local_res10[0] = param_1;
  lVar3 = IoBuildAsynchronousFsdRequest(3,*(undefined8 *)(this + 400),param_3,param_2,local_res10,0)
  ;
  if (lVar3 == 0) {
    lVar2 = -0x3fffff66;
  }
  else {
    pbVar1 = (byte *)(*(longlong *)(lVar3 + 0xb8) + -0x46);
    *pbVar1 = *pbVar1 | 0x12;
    lVar2 = IoSynchronousCallDriver(*(undefined8 *)(this + 400),lVar3);
    MmUnlockPages(*(undefined8 *)(lVar3 + 8));
    IoFreeMdl(*(undefined8 *)(lVar3 + 8));
    IoFreeIrp(lVar3);
  }
  return lVar2;
}



===== PmValidateIds @ 140028128 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long PmValidateIds(_DEVICE_EXTENSION *param_1,_DRIVE_LAYOUT_INFORMATION_EX *param_2)

{
  longlong lVar1;
  long lVar2;
  int iVar3;
  undefined1 auStack_78 [32];
  uchar local_58 [4];
  _DISK_OFFLINE_REASON local_54;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_78;
  local_58[0] = '\0';
  local_54 = 0;
  local_30 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  lVar1 = *(longlong *)(PmControlObject + 0x40);
  do {
    lVar2 = PmCheckIds(param_1,param_2,local_58,&local_54);
    if (lVar2 < 0) {
      return lVar2;
    }
    if (local_54 == 0) {
      if (local_58[0] == '\0') {
        return lVar2;
      }
    }
    else if (local_54 == 2) {
      uStack_48 = 3;
      local_40 = 3;
    }
    else {
      if (local_54 != 4) {
        return lVar2;
      }
      if (((byte)param_1[0x210] & 0x20) != 0) {
        return lVar2;
      }
      iVar3 = *(int *)(lVar1 + 0xa4);
      if (iVar3 == 2) {
        if (*(int *)(*(longlong *)(param_1 + 0xe8) + 0x1c) - 0xfU < 2) {
          return lVar2;
        }
      }
      else if (iVar3 == 3) {
        return lVar2;
      }
      uStack_48 = 1;
      local_40 = 1;
    }
    if (local_54 != 0) {
      param_1[0x25c] = (_DEVICE_EXTENSION)0x0;
      local_50 = CONCAT35(local_50._5_3_,0x28);
      iVar3 = PmSetDiskAttributes(param_1,(longlong)&local_50,local_54);
      return iVar3;
    }
    lVar2 = PmUpdateIds(param_1,param_2);
  } while (-1 < lVar2);
  return lVar2;
}



===== PmCheckIdsGpt @ 1400281ec =====

/* long __cdecl PmCheckIdsGpt(struct _DEVICE_EXTENSION * __ptr64,struct _DRIVE_LAYOUT_INFORMATION_EX
   * __ptr64,unsigned char * __ptr64,enum _DISK_OFFLINE_REASON * __ptr64) */

long __cdecl
PmCheckIdsGpt(_DEVICE_EXTENSION *param_1,_DRIVE_LAYOUT_INFORMATION_EX *param_2,uchar *param_3,
             _DISK_OFFLINE_REASON *param_4)

{
  _DEVICE_EXTENSION *p_Var1;
  longlong lVar2;
  code *pcVar3;
  long lVar4;
  longlong *plVar5;
  longlong lVar6;
  longlong *plVar7;
  uint uVar8;
  ulonglong uVar9;
  uint uVar10;
  uchar local_res10 [8];
  undefined1 local_res18 [16];
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  
  lVar2 = PmControlObject;
  lVar4 = 0;
  local_68 = 0;
  *param_3 = '\0';
  lVar2 = *(longlong *)(lVar2 + 0x40);
  lVar6 = *(longlong *)(param_2 + 8);
  local_res10[0] = '\0';
  local_res18[0] = 0;
  *param_4 = 4;
  local_60 = 0;
  uStack_58 = 0;
  if (lVar6 == 0) {
    lVar6 = *(longlong *)(param_2 + 0x10);
  }
  if (lVar6 == 0) {
    *param_3 = '\x01';
  }
  else {
    local_50 = *(undefined8 *)(param_2 + 8);
    uStack_48 = *(undefined8 *)(param_2 + 0x10);
    lVar6 = RtlLookupElementGenericTableAvl(lVar2 + 0x130,&local_68);
    if (lVar6 != 0) {
      lVar4 = PmIsRedundantPath(param_1,*(_DEVICE_EXTENSION **)(lVar6 + 0x10),local_res10);
      if (lVar4 < 0) {
        return lVar4;
      }
      if (local_res10[0] == '\0') {
        return lVar4;
      }
      *param_4 = 2;
      return lVar4;
    }
  }
  uVar9 = 0;
  while( true ) {
    uVar8 = (uint)uVar9;
    if (*(uint *)(param_2 + 4) <= uVar8) break;
    lVar6 = *(longlong *)(param_2 + uVar9 * 0x90 + 0x60);
    if (lVar6 == 0) {
      lVar6 = *(longlong *)(param_2 + uVar9 * 0x90 + 0x68);
    }
    if (lVar6 == 0) {
      *param_3 = '\x01';
    }
    else {
      lVar6 = *(longlong *)(param_2 + uVar9 * 0x90 + 0x60) - *(longlong *)(param_2 + 8);
      uVar10 = uVar8;
      if (lVar6 == 0) {
        lVar6 = *(longlong *)(param_2 + uVar9 * 0x90 + 0x68) - *(longlong *)(param_2 + 0x10);
      }
      while( true ) {
        if (lVar6 == 0) {
          return 0;
        }
        uVar10 = uVar10 + 1;
        if (*(uint *)(param_2 + 4) <= uVar10) break;
        lVar6 = *(longlong *)(param_2 + uVar9 * 0x90 + 0x60) -
                *(longlong *)(param_2 + (ulonglong)uVar10 * 0x90 + 0x60);
        if (lVar6 == 0) {
          lVar6 = *(longlong *)(param_2 + uVar9 * 0x90 + 0x68) -
                  *(longlong *)(param_2 + (ulonglong)uVar10 * 0x90 + 0x68);
        }
      }
      local_50 = *(undefined8 *)(param_2 + uVar9 * 0x90 + 0x60);
      uStack_48 = *(undefined8 *)(param_2 + uVar9 * 0x90 + 0x60 + 8);
      lVar6 = RtlLookupElementGenericTableAvl(lVar2 + 0x130,&local_68);
      if (lVar6 != 0) {
        return 0;
      }
    }
    uVar9 = (ulonglong)(uVar8 + 1);
  }
  *param_4 = 0;
  if (*param_3 == '\0') {
    local_50 = *(undefined8 *)(param_2 + 8);
    uStack_48 = *(undefined8 *)(param_2 + 0x10);
    plVar5 = (longlong *)RtlInsertElementGenericTableAvl(lVar2 + 0x130,&local_68,0x28,local_res18);
    if (plVar5 == (longlong *)0x0) {
LAB_1400283de:
      lVar4 = -0x3fffff66;
    }
    else {
      p_Var1 = param_1 + 0x278;
      plVar7 = *(longlong **)(param_1 + 0x280);
      if ((_DEVICE_EXTENSION *)*plVar7 != p_Var1) {
LAB_140028455:
        pcVar3 = (code *)swi(0x29);
        (*pcVar3)(3);
        pcVar3 = (code *)swi(3);
        lVar4 = (*pcVar3)();
        return lVar4;
      }
      uVar9 = 0;
      while( true ) {
        *plVar5 = (longlong)p_Var1;
        plVar5[1] = (longlong)plVar7;
        *plVar7 = (longlong)plVar5;
        *(longlong **)(param_1 + 0x280) = plVar5;
        plVar5[2] = (longlong)param_1;
        if (*(uint *)(param_2 + 4) <= (uint)uVar9) break;
        local_50 = *(undefined8 *)(param_2 + uVar9 * 0x90 + 0x60);
        uStack_48 = *(undefined8 *)(param_2 + uVar9 * 0x90 + 0x60 + 8);
        plVar5 = (longlong *)
                 RtlInsertElementGenericTableAvl(lVar2 + 0x130,&local_68,0x28,local_res18);
        if (plVar5 == (longlong *)0x0) goto LAB_1400283de;
        plVar7 = *(longlong **)(param_1 + 0x280);
        if ((_DEVICE_EXTENSION *)*plVar7 != p_Var1) goto LAB_140028455;
        uVar9 = (ulonglong)((uint)uVar9 + 1);
      }
    }
  }
  return lVar4;
}



===== PmInitializeSnapshotData @ 140028464 =====

/* void __cdecl PmInitializeSnapshotData(struct _DISK_SNAPSHOT_DATA * __ptr64,unsigned long) */

void __cdecl PmInitializeSnapshotData(_DISK_SNAPSHOT_DATA *param_1,ulong param_2)

{
  undefined4 uVar1;
  
  memset(param_1,0,(ulonglong)param_2);
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined8 *)param_1 = 0x5452415050414e53;
  *(undefined4 *)(param_1 + 0xc) = 0x70;
  *(undefined4 *)(param_1 + 8) = 1;
  uVar1 = RtlComputeCrc32(0,param_1);
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  return;
}



===== PmUpdateAttributes @ 1400284bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long PmUpdateAttributes(_DEVICE_EXTENSION *param_1,_DRIVE_LAYOUT_INFORMATION_EX *param_2)

{
  int iVar1;
  ulonglong uVar2;
  uint uVar3;
  longlong lVar4;
  undefined1 auStack_88 [32];
  uint local_68 [2];
  longlong local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_88;
  local_68[0] = 0;
  iVar1 = 0;
  local_38 = 0;
  local_60 = 0;
  local_58 = 0;
  local_48 = 0;
  uStack_40 = 0;
  if ((((param_1[0x25c] == (_DEVICE_EXTENSION)0x0) && (*(int *)(param_1 + 0x250) == 0)) &&
      (*(int *)(param_1 + 0x254) == 0)) && (*(int *)(param_1 + 600) == 0)) {
    uVar2 = 0;
  }
  else if (((byte)param_1[0x210] & 3) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 3;
    local_48 = 3;
  }
  uStack_50 = 0;
  if (((byte)param_1[0x210] & 1) == 0) {
    iVar1 = PmGetSnapshotData(param_1,param_2,&local_60,local_68);
    lVar4 = local_60;
    if (iVar1 < 0) goto LAB_1400285d4;
    uVar3 = 0;
    if (*(int *)(local_60 + 0x14) == 1) {
      param_1[0x25c] = (_DEVICE_EXTENSION)0x0;
      uVar2 = uVar2 | 1;
      uStack_50 = 1;
      uVar3 = 3;
      local_48 = uVar2;
    }
  }
  else {
    uVar3 = 0;
  }
  lVar4 = local_60;
  if (uVar2 != 0) {
    local_58 = CONCAT35(local_58._5_3_,0x100000028);
    iVar1 = PmSetDiskAttributes(param_1,(longlong)&local_58,uVar3);
  }
LAB_1400285d4:
  if (lVar4 != 0) {
    ExFreePoolWithTag(lVar4,0);
  }
  return iVar1;
}



===== PmIoctlGetDriveLayout @ 140028614 =====

uint PmIoctlGetDriveLayout(longlong param_1,longlong param_2)

{
  _DEVICE_EXTENSION *p_Var1;
  _DEVICE_EXTENSION *p_Var2;
  int *_Dst;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  longlong lVar7;
  ulonglong uVar8;
  int *local_res8;
  
  lVar7 = *(longlong *)(param_2 + 0xb8);
  local_res8 = (int *)0x0;
  p_Var2 = *(_DEVICE_EXTENSION **)(param_1 + 0x40);
  if (*(uint *)(lVar7 + 8) < 8) {
    uVar4 = 0xc0000023;
  }
  else {
    p_Var1 = p_Var2 + 0x38;
    KeWaitForSingleObject(p_Var1,0,0,0,0);
    uVar4 = PmGetDriveLayoutEx(p_Var2,&local_res8);
    KeReleaseMutex(p_Var1);
    piVar3 = local_res8;
    if (-1 < (int)uVar4) {
      if (*local_res8 == 0) {
        if ((ulonglong)(uint)local_res8[1] * 0x20 < 0x100000000) {
          uVar5 = (int)((ulonglong)(uint)local_res8[1] * 0x20) + 8;
          uVar6 = 0xffffffff;
          if (uVar5 >= 8) {
            uVar6 = uVar5;
          }
          uVar4 = -(uint)(uVar5 < 8) & 0xc0000095;
          if (7 < uVar5) {
            if (*(uint *)(lVar7 + 8) < uVar6) {
              uVar4 = 0xc0000023;
            }
            else {
              _Dst = *(int **)(param_2 + 0x18);
              memset(_Dst,0,(ulonglong)uVar6);
              *_Dst = piVar3[1];
              _Dst[1] = piVar3[2];
              uVar8 = 0;
              if (piVar3[1] != 0) {
                do {
                  lVar7 = uVar8 * 0x20;
                  uVar5 = (int)uVar8 + 1;
                  *(undefined8 *)(_Dst + uVar8 * 8 + 2) =
                       *(undefined8 *)(piVar3 + uVar8 * 0x24 + 0xe);
                  *(undefined8 *)(_Dst + uVar8 * 8 + 4) =
                       *(undefined8 *)(piVar3 + uVar8 * 0x24 + 0x10);
                  _Dst[uVar8 * 8 + 6] = piVar3[uVar8 * 0x24 + 0x15];
                  _Dst[uVar8 * 8 + 7] = piVar3[uVar8 * 0x24 + 0x12];
                  *(char *)(_Dst + uVar8 * 8 + 8) = (char)piVar3[uVar8 * 0x24 + 0x14];
                  *(undefined1 *)(lVar7 + 0x21 + (longlong)_Dst) =
                       *(undefined1 *)((longlong)piVar3 + uVar8 * 0x90 + 0x51);
                  *(undefined1 *)(lVar7 + 0x22 + (longlong)_Dst) =
                       *(undefined1 *)((longlong)piVar3 + uVar8 * 0x90 + 0x52);
                  *(char *)(lVar7 + 0x23 + (longlong)_Dst) = (char)piVar3[uVar8 * 0x24 + 0x13];
                  uVar8 = (ulonglong)uVar5;
                } while (uVar5 < (uint)piVar3[1]);
              }
              *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar6;
            }
          }
        }
        else {
          uVar4 = 0xc0000095;
        }
      }
      else {
        uVar4 = 0xc0000010;
      }
    }
    if (piVar3 != (int *)0x0) {
      ExFreePoolWithTag(piVar3,0);
    }
  }
  return uVar4;
}



===== PmTakeDisk @ 1400287a8 =====

/* void __cdecl PmTakeDisk(struct _DEVICE_EXTENSION * __ptr64) */

void __cdecl PmTakeDisk(_DEVICE_EXTENSION *param_1)

{
  char *pcVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined1 *puVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined8 local_res10;
  
  puVar6 = (undefined8 *)(*(longlong *)(PmControlObject + 0x40) + 0x48);
  for (puVar7 = (undefined8 *)*puVar6; puVar7 != puVar6; puVar7 = (undefined8 *)*puVar7) {
    local_res10 = *(undefined8 *)(param_1 + 0x18);
    IoReuseIrp(*(undefined8 *)(param_1 + 0x358),0xc00000bb);
    lVar3 = *(longlong *)(param_1 + 0x358);
    pcVar1 = (char *)(lVar3 + 0x43);
    *pcVar1 = *pcVar1 + -1;
    plVar2 = (longlong *)(lVar3 + 0xb8);
    *plVar2 = *plVar2 + -0x48;
    lVar3 = *(longlong *)(param_1 + 0x358);
    uVar4 = puVar7[5];
    puVar5 = *(undefined1 **)(lVar3 + 0xb8);
    *puVar5 = 0xf;
    *(undefined8 **)(lVar3 + 0x18) = &local_res10;
    *(undefined4 *)(puVar5 + 8) = 0;
    *(undefined4 *)(puVar5 + 0x10) = 8;
    *(undefined4 *)(puVar5 + 0x18) = 0x760008;
    IoForwardIrpSynchronously(uVar4);
  }
  return;
}



===== PmWmiCounterDisable @ 140028860 =====

undefined8 PmWmiCounterDisable(longlong *param_1,char param_2,char param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  ulonglong in_RAX;
  int iVar5;
  undefined1 uVar6;
  
  uVar6 = 0;
  if ((param_1 == (longlong *)0x0) || (lVar4 = *param_1, lVar4 == 0)) goto LAB_14002887c;
  if (param_2 == '\0') {
    LOCK();
    piVar1 = (int *)(lVar4 + 0x38);
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    iVar5 = iVar3 + -1;
    if (iVar5 != 0 && 0 < iVar3) {
      uVar6 = 1;
      goto LAB_14002887c;
    }
    if (iVar5 < 0) {
      in_RAX = *param_1;
      LOCK();
      piVar1 = (int *)(in_RAX + 0x38);
      iVar5 = *piVar1;
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      iVar5 = iVar5 + 1;
    }
    if (iVar5 != 0) goto LAB_14002887c;
  }
  else {
    LOCK();
    uVar2 = *(uint *)(lVar4 + 0x38);
    *(uint *)(lVar4 + 0x38) = 0;
    in_RAX = (ulonglong)uVar2;
    UNLOCK();
  }
  if (param_3 != '\0') {
    in_RAX = ExFreePoolWithTag(*param_1,0);
    *param_1 = 0;
  }
LAB_14002887c:
  return CONCAT71((int7)(in_RAX >> 8),uVar6);
}



===== PmTableAllocateRoutine @ 1400288b0 =====

void PmTableAllocateRoutine(undefined8 param_1,undefined4 param_2)

{
  ExAllocatePool2(0x102,param_2,0x45546d50);
  return;
}



===== _tlgEnableCallback @ 1400288e0 =====

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



===== PmRemoveDevice @ 14002895c =====

/* long __cdecl PmRemoveDevice(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl PmRemoveDevice(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  _DEVICE_EXTENSION *p_Var1;
  undefined8 uVar2;
  long lVar3;
  
  p_Var1 = *(_DEVICE_EXTENSION **)(param_1 + 0x40);
  uVar2 = *(undefined8 *)(p_Var1 + 0x10);
  PmRemoveHelper(p_Var1);
  IoReleaseRemoveLockAndWaitEx(p_Var1 + 0x78,param_2,0x20);
  if (*(longlong *)(p_Var1 + 0x470) != 0) {
    ExFreePoolWithTag(*(longlong *)(p_Var1 + 0x470),0);
    *(undefined8 *)(p_Var1 + 0x470) = 0;
  }
  if (*(longlong *)(p_Var1 + 0x468) != 0) {
    ExFreePoolWithTag(*(longlong *)(p_Var1 + 0x468),0);
    *(undefined8 *)(p_Var1 + 0x468) = 0;
  }
  if (*(longlong *)(p_Var1 + 0x450) != 0) {
    ExFreePoolWithTag(*(longlong *)(p_Var1 + 0x450),0);
    *(undefined8 *)(p_Var1 + 0x450) = 0;
  }
  RtlFreeUnicodeString(p_Var1 + 0x1d0);
  RtlFreeUnicodeString(p_Var1 + 0x1c0);
  RtlFreeUnicodeString(p_Var1 + 0x188);
  RtlFreeUnicodeString(p_Var1 + 0x178);
  RtlFreeUnicodeString(p_Var1 + 0x168);
  RtlFreeUnicodeString(p_Var1 + 0x158);
  if (*(longlong *)(p_Var1 + 0x150) != 0) {
    ExFreePoolWithTag(*(longlong *)(p_Var1 + 0x150),0);
    *(undefined8 *)(p_Var1 + 0x150) = 0;
  }
  if (*(longlong *)(p_Var1 + 0x148) != 0) {
    ExFreePoolWithTag(*(longlong *)(p_Var1 + 0x148),0);
    *(undefined8 *)(p_Var1 + 0x148) = 0;
  }
  if (*(longlong *)(p_Var1 + 0x140) != 0) {
    ExFreePoolWithTag(*(longlong *)(p_Var1 + 0x140),0);
    *(undefined8 *)(p_Var1 + 0x140) = 0;
  }
  if (*(longlong *)(p_Var1 + 0x138) != 0) {
    ExFreePoolWithTag(*(longlong *)(p_Var1 + 0x138),0);
    *(undefined8 *)(p_Var1 + 0x138) = 0;
  }
  if (*(longlong *)(p_Var1 + 0x130) != 0) {
    ExFreePoolWithTag(*(longlong *)(p_Var1 + 0x130),0);
    *(undefined8 *)(p_Var1 + 0x130) = 0;
  }
  if (*(longlong *)(p_Var1 + 0x128) != 0) {
    ExFreePoolWithTag(*(longlong *)(p_Var1 + 0x128),0);
    *(undefined8 *)(p_Var1 + 0x128) = 0;
  }
  if (*(longlong *)(p_Var1 + 0x118) != 0) {
    ExFreePoolWithTag(*(longlong *)(p_Var1 + 0x118),0);
    *(undefined8 *)(p_Var1 + 0x118) = 0;
  }
  if (*(longlong *)(p_Var1 + 0x120) != 0) {
    ExFreePoolWithTag(*(longlong *)(p_Var1 + 0x120),0);
    *(undefined8 *)(p_Var1 + 0x120) = 0;
  }
  if (*(longlong *)(p_Var1 + 0x110) != 0) {
    ExFreePoolWithTag(*(longlong *)(p_Var1 + 0x110),0);
    *(undefined8 *)(p_Var1 + 0x110) = 0;
  }
  if (*(longlong *)(p_Var1 + 0x108) != 0) {
    ExFreePoolWithTag(*(longlong *)(p_Var1 + 0x108),0);
    *(undefined8 *)(p_Var1 + 0x108) = 0;
  }
  if (*(longlong *)(p_Var1 + 0x100) != 0) {
    ExFreePoolWithTag(*(longlong *)(p_Var1 + 0x100),0);
    *(undefined8 *)(p_Var1 + 0x100) = 0;
  }
  if (*(longlong *)(p_Var1 + 0xf8) != 0) {
    ExFreePoolWithTag(*(longlong *)(p_Var1 + 0xf8),0);
    *(undefined8 *)(p_Var1 + 0xf8) = 0;
  }
  if (*(longlong *)(p_Var1 + 0xf0) != 0) {
    ExFreePoolWithTag(*(longlong *)(p_Var1 + 0xf0),0);
    *(undefined8 *)(p_Var1 + 0xf0) = 0;
  }
  if (*(longlong *)(p_Var1 + 0xe8) != 0) {
    ExFreePoolWithTag(*(longlong *)(p_Var1 + 0xe8),0);
    *(undefined8 *)(p_Var1 + 0xe8) = 0;
  }
  IoFreeIrp(*(undefined8 *)(p_Var1 + 0x358));
  IoFreeWorkItem(*(undefined8 *)(p_Var1 + 0x350));
  IoFreeWorkItem(*(undefined8 *)(p_Var1 + 0x378));
  param_2[0x43] = (_IRP)((char)param_2[0x43] + '\x01');
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  lVar3 = IofCallDriver(uVar2,param_2);
  IoDetachDevice(*(undefined8 *)(p_Var1 + 0x10));
  IoDeleteDevice(*(undefined8 *)(p_Var1 + 8));
  return lVar3;
}



===== PmTableFreeRoutine @ 140028ce0 =====

void PmTableFreeRoutine(undefined8 param_1,undefined8 param_2)

{
  ExFreePoolWithTag(param_2,0);
  return;
}



===== ~PM_DISK @ 140028d04 =====

/* public: virtual __cdecl PM_DISK::~PM_DISK(void) __ptr64 */

void __thiscall PM_DISK::~PM_DISK(PM_DISK *this)

{
  *(undefined ***)this = &_vftable_;
  if (*(longlong *)(this + 0x188) != 0) {
    ObfDereferenceObject();
  }
  SC_DISK::~SC_DISK((SC_DISK *)this);
  return;
}



===== PmLayoutHasIds @ 140028d48 =====

undefined1 PmLayoutHasIds(int *param_1)

{
  if (*param_1 == 0) {
    if (param_1[1] == 0) {
      if (param_1[2] == 0) {
        return 0;
      }
    }
    else if ((*(longlong *)(param_1 + 0xe) == 0) && (0 < *(longlong *)(param_1 + 0x10))) {
      return 0;
    }
  }
  else if (*param_1 != 1) {
    return 0;
  }
  return 1;
}



===== PmGiveDisk @ 140028d80 =====

/* void __cdecl PmGiveDisk(struct _DEVICE_EXTENSION * __ptr64) */

void __cdecl PmGiveDisk(_DEVICE_EXTENSION *param_1)

{
  char *pcVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined1 *puVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined8 local_res8;
  
  lVar3 = *(longlong *)(PmControlObject + 0x40);
  KeWaitForSingleObject(param_1 + 0x38,0,0,0,0);
  *(undefined4 *)(param_1 + 0x220) = 0;
  *(undefined4 *)(param_1 + 0x224) = 0;
  *(undefined4 *)(param_1 + 0x228) = 0;
  *(undefined4 *)(param_1 + 0x22c) = 0;
  KeReleaseMutex(param_1 + 0x38,0);
  puVar7 = (undefined8 *)(lVar3 + 0x48);
  puVar6 = (undefined8 *)*puVar7;
  while( true ) {
    if (puVar6 == puVar7) {
      return;
    }
    local_res8 = *(undefined8 *)(param_1 + 0x18);
    IoReuseIrp(*(undefined8 *)(param_1 + 0x358),0xc00000bb);
    lVar3 = *(longlong *)(param_1 + 0x358);
    pcVar1 = (char *)(lVar3 + 0x43);
    *pcVar1 = *pcVar1 + -1;
    plVar2 = (longlong *)(lVar3 + 0xb8);
    *plVar2 = *plVar2 + -0x48;
    lVar3 = *(longlong *)(param_1 + 0x358);
    uVar4 = puVar6[5];
    puVar5 = *(undefined1 **)(lVar3 + 0xb8);
    *puVar5 = 0xf;
    *(undefined8 **)(lVar3 + 0x18) = &local_res8;
    *(undefined4 *)(puVar5 + 8) = 0;
    *(undefined4 *)(puVar5 + 0x10) = 8;
    *(undefined4 *)(puVar5 + 0x18) = 0x76002c;
    IoForwardIrpSynchronously(uVar4,lVar3);
    if (*(int *)(lVar3 + 0x30) == -0x3fffffea) break;
    puVar6 = (undefined8 *)*puVar6;
  }
  return;
}



===== PmCreatePartition @ 140028e90 =====

/* long __cdecl PmCreatePartition(struct _DEVICE_EXTENSION * __ptr64,struct
   _DRIVE_LAYOUT_INFORMATION_EX * __ptr64,unsigned long,struct _PARTITION_INFORMATION_EX *
   __ptr64,struct _PARTITION_EXTENSION * __ptr64 * __ptr64) */

long __cdecl
PmCreatePartition(_DEVICE_EXTENSION *param_1,_DRIVE_LAYOUT_INFORMATION_EX *param_2,ulong param_3,
                 _PARTITION_INFORMATION_EX *param_4,_PARTITION_EXTENSION **param_5)

{
  _PARTITION_EXTENSION *p_Var1;
  longlong lVar2;
  _PARTITION_EXTENSION *p_Var3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined8 uVar9;
  longlong local_38 [2];
  
  local_38[0] = 0;
  lVar2 = *(longlong *)(PmControlObject + 0x40);
  *param_5 = (_PARTITION_EXTENSION *)0x0;
  iVar7 = ExSizeOfRundownProtectionCacheAware();
  iVar8 = IoCreateDevice(*(undefined8 *)(lVar2 + 8),iVar7 + 0x1c8,0,0x2d,0x100,0,local_38);
  if (-1 < iVar8) {
    p_Var3 = *(_PARTITION_EXTENSION **)(local_38[0] + 0x40);
    *(undefined8 **)p_Var3 = &PartitionDispatch;
    *(longlong *)(p_Var3 + 8) = local_38[0];
    uVar9 = IoGetAttachedDeviceReference(*(undefined8 *)(param_1 + 8));
    *(_DEVICE_EXTENSION **)(p_Var3 + 0x18) = param_1;
    *(undefined8 *)(p_Var3 + 0x10) = uVar9;
    *(ulong *)(p_Var3 + 0xa0) = param_3;
    *(_PARTITION_EXTENSION **)(p_Var3 + 400) = p_Var3 + 0x1c8;
    p_Var1 = p_Var3 + 0x138;
    uVar9 = *(undefined8 *)(param_4 + 8);
    *(undefined8 *)(p_Var3 + 0xa8) = *(undefined8 *)param_4;
    *(undefined8 *)(p_Var3 + 0xb0) = uVar9;
    uVar9 = *(undefined8 *)(param_4 + 0x18);
    *(undefined8 *)(p_Var3 + 0xb8) = *(undefined8 *)(param_4 + 0x10);
    *(undefined8 *)(p_Var3 + 0xc0) = uVar9;
    uVar9 = *(undefined8 *)(param_4 + 0x28);
    *(undefined8 *)(p_Var3 + 200) = *(undefined8 *)(param_4 + 0x20);
    *(undefined8 *)(p_Var3 + 0xd0) = uVar9;
    uVar9 = *(undefined8 *)(param_4 + 0x38);
    *(undefined8 *)(p_Var3 + 0xd8) = *(undefined8 *)(param_4 + 0x30);
    *(undefined8 *)(p_Var3 + 0xe0) = uVar9;
    uVar9 = *(undefined8 *)(param_4 + 0x48);
    *(undefined8 *)(p_Var3 + 0xe8) = *(undefined8 *)(param_4 + 0x40);
    *(undefined8 *)(p_Var3 + 0xf0) = uVar9;
    uVar9 = *(undefined8 *)(param_4 + 0x58);
    *(undefined8 *)(p_Var3 + 0xf8) = *(undefined8 *)(param_4 + 0x50);
    *(undefined8 *)(p_Var3 + 0x100) = uVar9;
    uVar9 = *(undefined8 *)(param_4 + 0x68);
    *(undefined8 *)(p_Var3 + 0x108) = *(undefined8 *)(param_4 + 0x60);
    *(undefined8 *)(p_Var3 + 0x110) = uVar9;
    uVar4 = *(undefined4 *)(param_4 + 0x74);
    uVar5 = *(undefined4 *)(param_4 + 0x78);
    uVar6 = *(undefined4 *)(param_4 + 0x7c);
    *(undefined4 *)(p_Var3 + 0x118) = *(undefined4 *)(param_4 + 0x70);
    *(undefined4 *)(p_Var3 + 0x11c) = uVar4;
    *(undefined4 *)(p_Var3 + 0x120) = uVar5;
    *(undefined4 *)(p_Var3 + 0x124) = uVar6;
    uVar4 = *(undefined4 *)(param_4 + 0x84);
    uVar5 = *(undefined4 *)(param_4 + 0x88);
    uVar6 = *(undefined4 *)(param_4 + 0x8c);
    *(undefined4 *)(p_Var3 + 0x128) = *(undefined4 *)(param_4 + 0x80);
    *(undefined4 *)(p_Var3 + 300) = uVar4;
    *(undefined4 *)(p_Var3 + 0x130) = uVar5;
    *(undefined4 *)(p_Var3 + 0x134) = uVar6;
    *(_PARTITION_EXTENSION **)(p_Var3 + 0x140) = p_Var1;
    *(_PARTITION_EXTENSION **)p_Var1 = p_Var1;
    p_Var1 = p_Var3 + 0x148;
    *(_PARTITION_EXTENSION **)(p_Var3 + 0x150) = p_Var1;
    *(_PARTITION_EXTENSION **)p_Var1 = p_Var1;
    KeInitializeMutex(p_Var3 + 0x158,0);
    ExInitializeRundownProtectionCacheAware(*(undefined8 *)(p_Var3 + 400),iVar7);
    KeInitializeEvent(p_Var3 + 0x198,0,0);
    p_Var1 = p_Var3 + 0x1b0;
    *(_PARTITION_EXTENSION **)(p_Var3 + 0x1b8) = p_Var1;
    *(_PARTITION_EXTENSION **)p_Var1 = p_Var1;
    KeInitializeSpinLock(p_Var3 + 0x1c0);
    if ((((*(uint *)(*(longlong *)(param_1 + 8) + 0x34) & 1) != 0) && (*(int *)param_4 != 1)) &&
       (*(int *)(param_4 + 0x18) == 1)) {
      *(uint *)(p_Var3 + 0x28) = *(uint *)(p_Var3 + 0x28) | 0x200;
    }
    iVar8 = PmBuildInstanceId(param_1,p_Var3);
    if (((-1 < iVar8) && (iVar8 = PmBuildStableGuid(param_1,p_Var3), -1 < iVar8)) &&
       (iVar8 = PmBuildUniqueId(param_1,p_Var3), -1 < iVar8)) {
      PmIsConversionInProgress(param_1,p_Var3);
      PmSetPartitionFlags(p_Var3,param_2);
      lVar2 = *(longlong *)(param_1 + 8);
      *param_5 = p_Var3;
      *(undefined4 *)(local_38[0] + 0x48) = *(undefined4 *)(lVar2 + 0x48);
      *(char *)(local_38[0] + 0x4c) = *(char *)(*(longlong *)(p_Var3 + 0x10) + 0x4c) + '\x01';
      *(undefined4 *)(local_38[0] + 0x98) = *(undefined4 *)(*(longlong *)(p_Var3 + 0x10) + 0x98);
      *(undefined2 *)(local_38[0] + 0x130) = *(undefined2 *)(*(longlong *)(p_Var3 + 0x10) + 0x130);
      return iVar8;
    }
    if (p_Var3 != (_PARTITION_EXTENSION *)0x0) {
      PmDeletePartition((longlong)p_Var3);
    }
  }
  return iVar8;
}



===== PmQueryWmiRegInfo @ 140029130 =====

/* long __cdecl PmQueryWmiRegInfo(struct _DEVICE_OBJECT * __ptr64,unsigned long * __ptr64,struct
   _UNICODE_STRING * __ptr64,struct _UNICODE_STRING * __ptr64 * __ptr64,struct _UNICODE_STRING *
   __ptr64,struct _DEVICE_OBJECT * __ptr64 * __ptr64) */

long __cdecl
PmQueryWmiRegInfo(_DEVICE_OBJECT *param_1,ulong *param_2,_UNICODE_STRING *param_3,
                 _UNICODE_STRING **param_4,_UNICODE_STRING *param_5,_DEVICE_OBJECT **param_6)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar2 = *(longlong *)(PmControlObject + 0x40);
  RtlInitUnicodeString(param_3,0);
  *param_2 = 0x21;
  *param_4 = (_UNICODE_STRING *)(lVar2 + 0x1a0);
  *param_6 = *(_DEVICE_OBJECT **)(lVar1 + 0x18);
  return 0;
}



===== PmIoctlDsm @ 1400291b0 =====

ulonglong PmIoctlDsm(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  undefined4 *_Dst;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  ulonglong uVar10;
  longlong *plVar11;
  longlong *plVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  bool bVar16;
  
  uVar13 = 0;
  uVar15 = 0;
  uVar2 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10);
  uVar14 = 0;
  if (uVar2 < 0x1c) {
    uVar13 = 0xc0000004;
    goto LAB_140029254;
  }
  piVar6 = *(int **)(param_2 + 0x18);
  iVar3 = piVar6[4];
  if (iVar3 == 0) {
LAB_14002921c:
    uVar4 = piVar6[6];
    if (uVar4 == 0) {
LAB_14002928c:
      if ((iVar3 == 0) || (uVar4 == 0)) {
LAB_1400292ab:
        if (piVar6[1] != -0x7fffffe4) {
          uVar10 = PmIoctlRedirect(param_1,param_2);
          return uVar10;
        }
        if (((*piVar6 == 0x1c) && (iVar3 == 0)) && (piVar6[3] == 0)) {
          uVar14 = piVar6[5];
          if ((piVar6[2] & 1U) == 0) {
            if (((((0x1b < uVar14) && (uVar14 <= uVar2)) && ((uVar14 & 7) == 0)) &&
                ((uVar15 = piVar6[6], 0xf < uVar15 && (uVar15 <= uVar2 - uVar14)))) &&
               ((uVar15 & 0xf) == 0)) {
              bVar16 = uVar15 == 0x10;
LAB_140029335:
              if (((bVar16) &&
                  ((uVar2 = piVar6[3], uVar14 <= uVar2 || (piVar6[4] + uVar2 <= uVar14)))) &&
                 ((uVar2 <= uVar14 || (uVar15 + uVar14 <= uVar2)))) {
                uVar14 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
                if (uVar14 < 0x38) {
                  uVar13 = 0xc0000023;
                }
                else {
                  _Dst = *(undefined4 **)(param_2 + 0x18);
                  lVar7 = *(longlong *)(param_1 + 0x40);
                  if ((_Dst[6] & 0xfffffff0) == 0x10) {
                    uVar2 = _Dst[5];
                    KeWaitForSingleObject(lVar7 + 0x38,0,0,0,0);
                    plVar1 = (longlong *)(lVar7 + 0x380);
                    bVar16 = false;
                    plVar11 = (longlong *)*plVar1;
                    plVar12 = (longlong *)0x0;
                    if (plVar11 == plVar1) {
LAB_140029436:
                      if (!bVar16) {
                        plVar12 = (longlong *)0x0;
                      }
                      if (plVar12 != (longlong *)0x0) {
                        lVar8 = plVar12[8];
                        lVar9 = plVar12[9];
                        KeReleaseMutex(lVar7 + 0x38);
                        memset(_Dst,0,(ulonglong)uVar14);
                        *_Dst = 0x24;
                        _Dst[1] = 0x8000001c;
                        _Dst[2] = 0;
                        _Dst[7] = 0x24;
                        _Dst[8] = uVar14 - 0x24;
                        *(longlong *)(_Dst + 10) = lVar8;
                        *(longlong *)(_Dst + 0xc) = lVar9;
                        _Dst[9] = 0x14;
                        *(undefined8 *)(param_2 + 0x38) = 0x38;
                        goto LAB_140029254;
                      }
                    }
                    else {
                      do {
                        plVar12 = plVar11 + -0x12;
                        if ((plVar11[4] == *(longlong *)((ulonglong)uVar2 + (longlong)_Dst)) &&
                           (plVar11[5] == *(longlong *)((ulonglong)uVar2 + 8 + (longlong)_Dst))) {
                          bVar16 = true;
                          goto LAB_140029436;
                        }
                        plVar11 = (longlong *)*plVar11;
                      } while (plVar11 != plVar1);
                    }
                    KeReleaseMutex(lVar7 + 0x38,0);
                    uVar13 = 0xc0000225;
                  }
                  else {
                    uVar13 = 0xc000000d;
                  }
                }
                goto LAB_140029254;
              }
            }
          }
          else if (uVar14 == 0) {
            uVar15 = piVar6[6];
            bVar16 = uVar15 == 0;
            goto LAB_140029335;
          }
        }
      }
      else if ((uint)piVar6[3] < (uint)piVar6[5]) {
        if (uVar14 <= (uint)piVar6[5]) goto LAB_1400292ab;
      }
      else if (uVar15 <= (uint)piVar6[3]) goto LAB_1400292ab;
    }
    else if ((piVar6[2] & 1U) == 0) {
      uVar5 = piVar6[5];
      uVar15 = uVar4 + uVar5;
      if (uVar15 < uVar5) goto LAB_140029285;
      if ((((uVar5 != 0) && ((uVar4 & 0xf) == 0)) && (0x1b < uVar5)) &&
         ((uVar15 <= uVar2 && (((char)uVar5 + (char)piVar6 & 7U) == 0)))) goto LAB_14002928c;
    }
  }
  else {
    uVar4 = piVar6[3];
    uVar14 = iVar3 + uVar4;
    if (uVar14 < uVar4) {
LAB_140029285:
      uVar13 = 0xc0000095;
      goto LAB_140029254;
    }
    if ((0x1b < uVar4) && (uVar14 <= uVar2)) goto LAB_14002921c;
  }
  uVar13 = 0xc000000d;
LAB_140029254:
  *(uint *)(param_2 + 0x30) = uVar13;
  IofCompleteRequest(param_2,0);
  return (ulonglong)uVar13;
}



===== PmSendTelemetry @ 1400294b8 =====

void PmSendTelemetry(undefined4 *param_1)

{
  undefined8 uVar1;
  
  if (param_1[0x66] == 0) {
    if (5 < DAT_140019068) {
      uVar1 = _tlgKeywordOn();
      if ((char)uVar1 != '\0') {
        _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
        ::
        Write<_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>,_tlgWrapperByVal<8>,_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapBuffer<_UNICODE_STRING>,_tlgWrapBuffer<struct__UNICODE_STRING>,_tlgWrapBuffer<struct__UNICODE_STRING>,_tlgWrapBuffer<struct__UNICODE_STRING>,_tlgWrapBuffer<struct__UNICODE_STRING>,_tlgWrapBuffer<struct__UNICODE_STRING>,_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByRef<16>,_tlgWrapperByRef<16>,_tlgWrapperByRef<16>,_tlgWrapperByRef<16>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperBinary,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<8>,_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperBinary,_tlgWrapperBinary,_tlgWrapperBinary,_tlgWrapperBinary,_tlgWrapperBinary,_tlgWrapperBinary>
                  ();
      }
    }
  }
  else if ((param_1[0x66] == 1) && (5 < DAT_140019068)) {
    uVar1 = _tlgKeywordOn();
    if ((char)uVar1 != '\0') {
      _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
      ::
      Write<_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>,_tlgWrapperByVal<8>,_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapBuffer<_UNICODE_STRING>,_tlgWrapBuffer<struct__UNICODE_STRING>,_tlgWrapBuffer<struct__UNICODE_STRING>,_tlgWrapBuffer<struct__UNICODE_STRING>,_tlgWrapBuffer<struct__UNICODE_STRING>,_tlgWrapBuffer<struct__UNICODE_STRING>,_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByRef<16>,_tlgWrapperByRef<16>,_tlgWrapperByRef<16>,_tlgWrapperByRef<16>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperBinary,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<8>,_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperBinary,_tlgWrapperBinary>
                ();
    }
  }
  if ((Microsoft_Windows_PartitionEnableBits & 1) != 0) {
    McTemplateK0qqqtqqqqxxjqxqzzzzzzdddddddddxqjjjjtuqqqqqbr41qqqqtttqqqtttxxqqqqqtxqqqzqtqqqbr73qbr75qbr77qbr79qbr81qbr83_EtwWriteTransfer
              (&Microsoft_Windows_Partition_Context,&DiskTelemetry,0,*param_1,(char)param_1[1],
               (char)param_1[2],*(undefined1 *)(param_1 + 3),(char)param_1[4],(char)param_1[5],
               (char)param_1[6],(char)param_1[7],(char)*(undefined8 *)(param_1 + 8),
               (char)*(undefined8 *)(param_1 + 10),param_1 + 0xc,(char)param_1[0x10],
               (char)*(undefined8 *)(param_1 + 0x12),(char)param_1[0x14],
               *(wchar_t **)(*(longlong *)(param_1 + 0x16) + 8),
               *(wchar_t **)(*(longlong *)(param_1 + 0x18) + 8),
               *(wchar_t **)(*(longlong *)(param_1 + 0x1a) + 8),
               *(wchar_t **)(*(longlong *)(param_1 + 0x1c) + 8),
               *(wchar_t **)(*(longlong *)(param_1 + 0x1e) + 8),
               *(wchar_t **)(*(longlong *)(param_1 + 0x22) + 8),(char)param_1[0x24],
               (char)param_1[0x25],(char)param_1[0x2a],(char)param_1[0x2b],(char)param_1[0x2c],
               (char)param_1[0x26],(char)param_1[0x27],(char)param_1[0x28],(char)param_1[0x29],
               (char)*(undefined8 *)(param_1 + 0x2e),(char)param_1[0x30],param_1 + 0x31,
               param_1 + 0x35,param_1 + 0x39,param_1 + 0x3d,*(undefined1 *)(param_1 + 0x41),
               *(undefined1 *)((longlong)param_1 + 0x105),(char)param_1[0x42],(char)param_1[0x43],
               (char)param_1[0x44],(char)param_1[0x45],param_1[0x48],*(undefined8 *)(param_1 + 0x46)
               ,(char)param_1[0x49],(char)param_1[0x4a],(char)param_1[0x4b],(char)param_1[0x4c],
               *(undefined1 *)(param_1 + 0x4d),*(undefined1 *)((longlong)param_1 + 0x135),
               *(undefined1 *)((longlong)param_1 + 0x136),(char)param_1[0x4e],(char)param_1[0x4f],
               (char)param_1[0x50],*(undefined1 *)(param_1 + 0x51),
               *(undefined1 *)((longlong)param_1 + 0x145),*(undefined1 *)((longlong)param_1 + 0x146)
               ,(char)*(undefined8 *)(param_1 + 0x52),(char)*(undefined8 *)(param_1 + 0x54),
               (char)param_1[0x56],(char)param_1[0x57],(char)param_1[0x58],(char)param_1[0x59],
               (char)param_1[0x5a],*(undefined1 *)(param_1 + 0x5b));
  }
  if ((param_1[0x7c] != 0) && ((Microsoft_Windows_PartitionEnableBits & 1) != 0)) {
    McTemplateK0qqQR1_EtwWriteTransfer();
  }
  return;
}



===== FUN_14002a7c8 @ 14002a7c8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_14002a7c8(void)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong unaff_RBX;
  ulonglong unaff_RSI;
  ulonglong unaff_RDI;
  char unaff_R12B;
  longlong unaff_R13;
  char *unaff_R14;
  ulonglong *unaff_R15;
  undefined8 *in_stack_00000050;
  undefined1 uStack0000000000000058;
  uint in_stack_0000006c;
  
  *unaff_R14 = '\x01';
  if (*unaff_R14 != '\0') {
    uVar1 = PmGetDriveGeometry(*(undefined8 *)(unaff_R13 + 0x28),&uStack0000000000000058);
    unaff_RDI = (ulonglong)uVar1;
    if (-1 < (int)uVar1) {
      uVar2 = RtlULongLongMult(unaff_RBX,(ulonglong)in_stack_0000006c,in_stack_00000050);
      unaff_RDI = uVar2 & 0xffffffff;
      if (-1 < (int)uVar2) {
        if (unaff_R12B == '\0') {
          uVar2 = RtlULongLongMult(unaff_RSI,(ulonglong)in_stack_0000006c,unaff_R15);
          unaff_RDI = uVar2 & 0xffffffff;
        }
        else {
          *unaff_R15 = unaff_RSI;
        }
      }
    }
  }
  return unaff_RDI & 0xffffffff;
}



===== FUN_14002a8a4 @ 14002a8a4 =====

/* PDB: Separated code (from the compiler): 14002a8a4 - 14002a8d4 for parent address: 140026400 */

undefined4 FUN_14002a8a4(void)

{
  longlong unaff_RBX;
  undefined4 unaff_ESI;
  longlong unaff_RDI;
  
  KeReleaseMutex(*(longlong *)(unaff_RBX + 0x18) + 0x38,0);
  *(undefined4 *)(unaff_RDI + 0x30) = unaff_ESI;
  IofCompleteRequest();
  return unaff_ESI;
}



===== entry @ 14002b010 =====

void entry(_DRIVER_OBJECT *param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 14002b044 =====

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



===== PmQueryGlobalSettings @ 14002b078 =====

/* long __cdecl PmQueryGlobalSettings(struct _CONTROL_EXTENSION * __ptr64) */

long __cdecl PmQueryGlobalSettings(_CONTROL_EXTENSION *param_1)

{
  _CONTROL_EXTENSION *p_Var1;
  _CONTROL_EXTENSION *p_Var2;
  _CONTROL_EXTENSION _Var3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  int iVar8;
  undefined8 local_res8;
  
  local_res8 = 0;
  iVar4 = IoOpenDriverRegistryKey(*(undefined8 *)(param_1 + 8),1,1,0,&local_res8);
  if (-1 < iVar4) {
    p_Var1 = param_1 + 0xa0;
    uVar6 = PmGetParameter(local_res8,&SanPolicy,(undefined4 *)p_Var1);
    p_Var2 = param_1 + 0xa4;
    iVar4 = (int)uVar6;
    uVar6 = PmGetParameter(local_res8,&ConflictPolicy,(undefined4 *)p_Var2);
    ZwClose(local_res8);
    iVar8 = (int)uVar6;
    if ((iVar4 == -0x3fffffcc) || (iVar8 == -0x3fffffcc)) {
      iVar5 = IoOpenDriverRegistryKey(*(undefined8 *)(param_1 + 8),0,1,0,&local_res8);
      if (iVar5 < 0) {
        return iVar5;
      }
      if (iVar4 == -0x3fffffcc) {
        uVar6 = PmGetParameter(local_res8,&SanPolicy,(undefined4 *)p_Var1);
        iVar4 = (int)uVar6;
      }
      if (iVar8 == -0x3fffffcc) {
        uVar6 = PmGetParameter(local_res8,&ConflictPolicy,(undefined4 *)p_Var2);
        iVar8 = (int)uVar6;
      }
      ZwClose(local_res8);
    }
    if ((iVar4 < 0) || (4 < *(int *)p_Var1 - 1U)) {
      *(int *)p_Var1 = 1;
    }
    uVar7 = Feature_Partition_Manager_Passthrough__private_IsEnabledDeviceUsageNoInline();
    if (((int)uVar7 == 0) && (*(int *)p_Var1 == 5)) {
      *(int *)p_Var1 = 1;
    }
    if ((iVar8 < 0) || (2 < *(int *)p_Var2 - 1U)) {
      *(int *)p_Var2 = 2;
    }
    iVar4 = RtlCheckRegistryKey(2,L"MiniNT");
    if (iVar4 < 0) {
      if (iVar4 != -0x3fffffcc) {
        return iVar4;
      }
    }
    else {
      param_1[0xa8] = (_CONTROL_EXTENSION)0x1;
    }
    _Var3 = (_CONTROL_EXTENSION)ExIsSoftBoot();
    param_1[0xa9] = _Var3;
    iVar4 = IoGetBootDiskInformationLite(param_1 + 0xc0);
    if (-1 < iVar4) {
      KeQueryPerformanceCounter(param_1 + 0x1b0);
    }
  }
  return iVar4;
}



===== DriverEntry @ 14002b260 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(_DRIVER_OBJECT *param_1,undefined8 param_2)

{
  _CONTROL_EXTENSION *p_Var1;
  _CONTROL_EXTENSION *p_Var2;
  int iVar3;
  ulonglong uVar4;
  longlong lVar5;
  _DRIVER_OBJECT *p_Var6;
  undefined8 *puVar7;
  longlong local_res8;
  undefined8 in_stack_ffffffffffffff98;
  undefined4 uVar8;
  ulonglong in_stack_ffffffffffffffa0;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  uVar8 = (undefined4)((ulonglong)in_stack_ffffffffffffff98 >> 0x20);
  local_res8 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  wil_InitializeFeatureStaging();
  TraceLoggingRegisterEx_EtwRegister_EtwSetInformation();
  McGenEventRegister_EtwRegister();
  p_Var6 = param_1 + 0x70;
  for (lVar5 = 0x1c; lVar5 != 0; lVar5 = lVar5 + -1) {
    *(code **)p_Var6 = PmGlobalDispatch;
    p_Var6 = p_Var6 + 8;
  }
  *(code **)(*(longlong *)(param_1 + 0x30) + 8) = PmAddDevice;
  *(code **)(param_1 + 0x68) = PmUnload;
  puVar7 = &PmControlDispatch;
  for (lVar5 = 0x1c; lVar5 != 0; lVar5 = lVar5 + -1) {
    *puVar7 = PmFail;
    puVar7 = puVar7 + 1;
  }
  PmControlDispatch = PmCreate;
  _DAT_1400193f0 = PmControlDeviceControl;
  _DAT_140019390 = PmClose;
  _DAT_140019410 = PmClose;
  puVar7 = &PmFilterDispatch;
  for (lVar5 = 0x1c; lVar5 != 0; lVar5 = lVar5 + -1) {
    *puVar7 = PmPassThrough;
    puVar7 = puVar7 + 1;
  }
  _DAT_140019478 = PmRead;
  _DAT_140019480 = PmWrite;
  _DAT_1400194a8 = PmIo;
  uVar4 = Feature_Partition_Manager_Passthrough__private_IsEnabledDeviceUsageNoInline();
  lVar5 = 0x1c;
  _DAT_1400194d0 = PmFilterDeviceControlLegacy;
  if ((int)uVar4 != 0) {
    _DAT_1400194d0 = PmFilterDeviceControl;
  }
  puVar7 = &PartitionDispatch;
  for (; lVar5 != 0; lVar5 = lVar5 + -1) {
    *puVar7 = PmFail;
    puVar7 = puVar7 + 1;
  }
  _DAT_1400192b8 = PartitionIo;
  _DAT_1400194d8 = PmFilterInternalDeviceControl;
  _DAT_1400192c0 = PartitionWrite;
  _DAT_140019510 = PmPower;
  PartitionDispatch = PmCreate;
  _DAT_140019518 = PmSystemControl;
  _DAT_1400192b0 = PmClose;
  _DAT_140019538 = PmPnp;
  _DAT_140019310 = PartitionDeviceControl;
  _DAT_140019330 = PmClose;
  RtlInitUnicodeString(&local_48,L"\\Device\\PartmgrControl");
  iVar3 = IoCreateDevice(param_1,0x1b8,&local_48,0x2d,CONCAT44(uVar8,0x100),
                         in_stack_ffffffffffffffa0 & 0xffffffffffffff00,&local_res8);
  if (-1 < iVar3) {
    PmControlObject = local_res8;
    p_Var2 = *(_CONTROL_EXTENSION **)(local_res8 + 0x40);
    memset(p_Var2 + 0x10,0,0x1a8);
    *(code ***)p_Var2 = &PmControlDispatch;
    *(_DRIVER_OBJECT **)(p_Var2 + 8) = param_1;
    KeInitializeMutex(p_Var2 + 0x10,0);
    p_Var1 = p_Var2 + 0x48;
    *(_CONTROL_EXTENSION **)(p_Var2 + 0x50) = p_Var1;
    *(_CONTROL_EXTENSION **)p_Var1 = p_Var1;
    p_Var1 = p_Var2 + 0x58;
    *(_CONTROL_EXTENSION **)(p_Var2 + 0x60) = p_Var1;
    *(_CONTROL_EXTENSION **)p_Var1 = p_Var1;
    KeInitializeMutex(p_Var2 + 0x68,0);
    RtlInitializeGenericTableAvl
              (p_Var2 + 200,PmTableSignatureCompareRoutine,PmTableAllocateRoutine,PmTableFreeRoutine
               ,p_Var2);
    RtlInitializeGenericTableAvl
              (p_Var2 + 0x130,PmTableGuidCompareRoutine,PmTableAllocateRoutine,PmTableFreeRoutine,
               p_Var2);
    iVar3 = RtlDuplicateUnicodeString(1,param_2,p_Var2 + 0x1a0);
    if ((-1 < iVar3) && (iVar3 = PmQueryGlobalSettings(p_Var2), -1 < iVar3)) {
      RtlInitUnicodeString(&local_38,L"\\DosDevices\\PartmgrControl");
      iVar3 = IoCreateSymbolicLink(&local_38,&local_48);
      if ((-1 < iVar3) &&
         (iVar3 = IoRegisterPlugPlayNotification
                            (2,1,&VOLMGR_VOLUME_MANAGER_GUID,param_1,PmVolumeManagerNotification,
                             p_Var2,p_Var2 + 0x198), -1 < iVar3)) {
        IoRegisterDriverReinitialization(param_1,PmDriverReinitialization,0);
        return iVar3;
      }
    }
  }
  PmUnload(param_1);
  return iVar3;
}



===== wil_InitializeFeatureStaging @ 14002b618 =====

int wil_InitializeFeatureStaging(void)

{
  bool bVar1;
  int iVar2;
  longlong *plVar3;
  undefined **ppuVar4;
  undefined8 local_res8;
  
  bVar1 = false;
  if (g_wil_details_isFeatureStagingInitialized == 0) {
    g_wil_details_isFeatureStagingInitialized = 1;
    local_res8 = RtlQueryFeatureConfigurationChangeStamp();
    wil_details_PopulateInitialConfiguredFeatureStates();
    wil_details_EvaluateFeatureDependencies();
    ppuVar4 = &wil_details_featureDescriptors_a;
    while (plVar3 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar4),
          plVar3 != (longlong *)0x0) {
      if (((*(char *)((longlong)plVar3 + 0x1d) == '\0') &&
          (*(char *)((longlong)plVar3 + 0x1e) == '\0')) &&
         (*(char *)((longlong)plVar3 + 0x1c) == '\0')) {
        iVar2 = RtlRegisterFeatureConfigurationChangeNotification
                          (wil_details_ReevaluateOnFeatureConfigurationChange,0,&local_res8,
                           &g_wil_details_featureChangeNotification);
        if (iVar2 == 0) {
          bVar1 = true;
        }
        else {
          g_wil_details_featureChangeNotification = 0;
        }
        break;
      }
      ppuVar4 = (undefined **)(plVar3 + 7);
    }
    g_wil_details_recordFeatureUsage = wil_details_RecordFeatureUsageReporting;
    iVar2 = RtlRegisterFeatureUsageProvider
                      (wil_details_OnFeatureUsageProviderFlushNotification,0,
                       &g_wil_details_featureUsageProvider);
    if (iVar2 != 0) {
      if (bVar1) {
        iVar2 = 0;
      }
      g_wil_details_featureUsageProvider = 0;
      return iVar2;
    }
  }
  return 0;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14002b708 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_PopulateInitialConfiguredFeatureStates(void)

{
  int iVar1;
  longlong *plVar2;
  undefined **ppuVar3;
  undefined8 uVar4;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  ppuVar3 = &wil_details_featureDescriptors_a;
  do {
    plVar2 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar3);
    if (plVar2 == (longlong *)0x0) {
      return;
    }
    local_30 = 0;
    local_38 = 0;
    local_28 = 0;
    local_20 = 0;
    if ((*(char *)((longlong)plVar2 + 0x1d) == '\0') && (*(char *)((longlong)plVar2 + 0x1e) == '\0')
       ) {
      iVar1 = RtlQueryFeatureConfiguration
                        ((int)plVar2[3],1 < (byte)(*(char *)((longlong)plVar2 + 0x1c) - 2U),
                         &local_30,&local_28);
      if (iVar1 == -0x7fffffde) {
        local_38 = 0x206;
        uVar4 = 0x206;
        do {
          *(undefined8 *)*plVar2 = uVar4;
          plVar2 = wil_details_FeatureDescriptors_SkipPadding(plVar2 + 7);
        } while (plVar2 != (longlong *)0x0);
        return;
      }
    }
    else {
      iVar1 = -0x3ffffddb;
    }
    wil_details_BuildFeatureStateCacheFromQueryResults(iVar1,(longlong)&local_28,(uint *)&local_38);
    ppuVar3 = (undefined **)(plVar2 + 7);
    *(undefined8 *)*plVar2 = local_38;
  } while( true );
}


