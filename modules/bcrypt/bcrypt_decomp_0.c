
===== _tlgCreate1Sz_wchar_t @ 180001008 =====

void _tlgCreate1Sz_wchar_t(longlong *param_1,wchar_t *param_2)

{
  int iVar1;
  longlong lVar2;
  
  if (param_2 == (wchar_t *)0x0) {
    param_2 = L"";
    iVar1 = 2;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_2[lVar2] != L'\0');
    iVar1 = (int)lVar2 * 2 + 2;
  }
  *param_1 = (longlong)param_2;
  *(int *)(param_1 + 1) = iVar1;
  *(undefined4 *)((longlong)param_1 + 0xc) = 0;
  return;
}



===== _tlgKeywordOn @ 180001048 =====

ulonglong _tlgKeywordOn(longlong param_1,ulonglong param_2)

{
  ulonglong in_RAX;
  
  if (((*(ulonglong *)(param_1 + 0x10) & param_2) == 0) ||
     (in_RAX = *(ulonglong *)(param_1 + 0x18) & param_2, in_RAX != *(ulonglong *)(param_1 + 0x18)))
  {
    return in_RAX & 0xffffffffffffff00;
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}



===== Write<_tlgWrapSz<unsigned_short>_> @ 18000106c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EventWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapSz<unsigned short> >(struct _tlgProvider_t const * __ptr64,void
   const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,struct
   _tlgWrapSz<unsigned short> const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EventWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::Write<_tlgWrapSz<unsigned_short>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapSz<unsigned_short> *param_5)

{
  long lVar1;
  longlong lVar2;
  undefined1 auStackY_78 [32];
  _EVENT_DATA_DESCRIPTOR local_48 [2];
  wchar_t *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_28 = *(wchar_t **)param_5;
  if (local_28 == (wchar_t *)0x0) {
    local_28 = L"";
    local_20 = 2;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (local_28[lVar2] != L'\0');
    local_20 = (int)lVar2 * 2 + 2;
  }
  local_1c = 0;
  lVar1 = _tlgWriteTransfer_EventWriteTransfer
                    (0x180025058,param_2,(LPCGUID)0x0,(LPCGUID)0x0,3,local_48);
  return lVar1;
}



===== _tlgWriteTransfer_EventWriteTransfer @ 180001100 =====

void _tlgWriteTransfer_EventWriteTransfer
               (longlong param_1,byte *param_2,LPCGUID param_3,LPCGUID param_4,ULONG param_5,
               PEVENT_DATA_DESCRIPTOR param_6)

{
  EVENT_DESCRIPTOR local_18;
  
  local_18._0_4_ = (uint)*param_2 << 0x18;
  local_18._4_4_ = ZEXT24(*(ushort *)(param_2 + 1));
  local_18.Keyword = *(ULONGLONG *)(param_2 + 3);
  param_6->Ptr = *(ULONGLONG *)(param_1 + 8);
  param_6->Size = (uint)**(ushort **)(param_1 + 8);
  param_6[1].Ptr = (ULONGLONG)(param_2 + 0xb);
  param_6->Reserved = 2;
  param_6[1].Size = (uint)*(ushort *)(param_2 + 0xb);
  param_6[1].Reserved = 1;
  EventWriteTransfer(*(REGHANDLE *)(param_1 + 0x20),&local_18,param_3,param_4,param_5,param_6);
  return;
}



===== Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByRef<16>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>_> @ 1800011a4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EventWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapperByVal<8>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<1>,struct _tlgWrapperByRef<16>,struct
   _tlgWrapperBinary,struct _tlgWrapperByVal<8>,struct _tlgWrapperByVal<1>,struct
   _tlgWrapperBinary,struct _tlgWrapperByVal<8>,struct _tlgWrapperByVal<1>,struct
   _tlgWrapperBinary,struct _tlgWrapperByVal<8>,struct _tlgWrapperByVal<1>,struct
   _tlgWrapperBinary,struct _tlgWrapperByVal<8>,struct _tlgWrapperByVal<1>,struct
   _tlgWrapperBinary,struct _tlgWrapperByVal<8>,struct _tlgWrapperByVal<1>,struct
   _tlgWrapperBinary,struct _tlgWrapperByVal<8>,struct _tlgWrapperByVal<1>,struct
   _tlgWrapperBinary,struct _tlgWrapperByVal<8>,struct _tlgWrapperByVal<1>,struct
   _tlgWrapperBinary,struct _tlgWrapperByVal<8>,struct _tlgWrapperByVal<1>,struct
   _tlgWrapperBinary,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<1> >(struct _tlgProvider_t
   const * __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const *
   __ptr64,struct _tlgWrapperByVal<8> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<1> const &
   __ptr64,struct _tlgWrapperByRef<16> const & __ptr64,struct _tlgWrapperBinary const &
   __ptr64,struct _tlgWrapperByVal<8> const & __ptr64,struct _tlgWrapperByVal<1> const &
   __ptr64,struct _tlgWrapperBinary const & __ptr64,struct _tlgWrapperByVal<8> const &
   __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct _tlgWrapperBinary const &
   __ptr64,struct _tlgWrapperByVal<8> const & __ptr64,struct _tlgWrapperByVal<1> const &
   __ptr64,struct _tlgWrapperBinary const & __ptr64,struct _tlgWrapperByVal<8> const &
   __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct _tlgWrapperBinary const &
   __ptr64,struct _tlgWrapperByVal<8> const & __ptr64,struct _tlgWrapperByVal<1> const &
   __ptr64,struct _tlgWrapperBinary const & __ptr64,struct _tlgWrapperByVal<8> const &
   __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct _tlgWrapperBinary const &
   __ptr64,struct _tlgWrapperByVal<8> const & __ptr64,struct _tlgWrapperByVal<1> const &
   __ptr64,struct _tlgWrapperBinary const & __ptr64,struct _tlgWrapperByVal<8> const &
   __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct _tlgWrapperBinary const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<1> const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EventWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::
Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByRef<16>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapperByVal<8> *param_5,_tlgWrapperByVal<4> *param_6,_tlgWrapperByVal<4> *param_7,
          _tlgWrapperByVal<1> *param_8,_tlgWrapperByRef<16> *param_9,_tlgWrapperBinary *param_10,
          _tlgWrapperByVal<8> *param_11,_tlgWrapperByVal<1> *param_12,_tlgWrapperBinary *param_13,
          _tlgWrapperByVal<8> *param_14,_tlgWrapperByVal<1> *param_15,_tlgWrapperBinary *param_16,
          _tlgWrapperByVal<8> *param_17,_tlgWrapperByVal<1> *param_18,_tlgWrapperBinary *param_19,
          _tlgWrapperByVal<8> *param_20,_tlgWrapperByVal<1> *param_21,_tlgWrapperBinary *param_22,
          _tlgWrapperByVal<8> *param_23,_tlgWrapperByVal<1> *param_24,_tlgWrapperBinary *param_25,
          _tlgWrapperByVal<8> *param_26,_tlgWrapperByVal<1> *param_27,_tlgWrapperBinary *param_28,
          _tlgWrapperByVal<8> *param_29,_tlgWrapperByVal<1> *param_30,_tlgWrapperBinary *param_31,
          _tlgWrapperByVal<8> *param_32,_tlgWrapperByVal<1> *param_33,_tlgWrapperBinary *param_34,
          _tlgWrapperByVal<4> *param_35,_tlgWrapperByVal<1> *param_36)

{
  long lVar1;
  undefined1 auStackY_2f8 [32];
  _EVENT_DATA_DESCRIPTOR local_2c8 [2];
  _tlgWrapperByVal<8> *local_2a8;
  undefined8 local_2a0;
  _tlgWrapperByVal<4> *local_298;
  undefined8 local_290;
  _tlgWrapperByVal<4> *local_288;
  undefined8 local_280;
  _tlgWrapperByVal<1> *local_278;
  undefined8 local_270;
  undefined8 local_268;
  undefined8 local_260;
  uint *local_258;
  undefined8 local_250;
  undefined8 local_248;
  uint local_240 [2];
  _tlgWrapperByVal<8> *local_238;
  undefined8 local_230;
  _tlgWrapperByVal<1> *local_228;
  undefined8 local_220;
  uint *local_218;
  undefined8 local_210;
  undefined8 local_208;
  uint local_200 [2];
  _tlgWrapperByVal<8> *local_1f8;
  undefined8 local_1f0;
  _tlgWrapperByVal<1> *local_1e8;
  undefined8 local_1e0;
  uint *local_1d8;
  undefined8 local_1d0;
  undefined8 local_1c8;
  uint local_1c0 [2];
  _tlgWrapperByVal<8> *local_1b8;
  undefined8 local_1b0;
  _tlgWrapperByVal<1> *local_1a8;
  undefined8 local_1a0;
  uint *local_198;
  undefined8 local_190;
  undefined8 local_188;
  uint local_180 [2];
  _tlgWrapperByVal<8> *local_178;
  undefined8 local_170;
  _tlgWrapperByVal<1> *local_168;
  undefined8 local_160;
  uint *local_158;
  undefined8 local_150;
  undefined8 local_148;
  uint local_140 [2];
  _tlgWrapperByVal<8> *local_138;
  undefined8 local_130;
  _tlgWrapperByVal<1> *local_128;
  undefined8 local_120;
  uint *local_118;
  undefined8 local_110;
  undefined8 local_108;
  uint local_100 [2];
  _tlgWrapperByVal<8> *local_f8;
  undefined8 local_f0;
  _tlgWrapperByVal<1> *local_e8;
  undefined8 local_e0;
  uint *local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  uint local_c0 [2];
  _tlgWrapperByVal<8> *local_b8;
  undefined8 local_b0;
  _tlgWrapperByVal<1> *local_a8;
  undefined8 local_a0;
  uint *local_98;
  undefined8 local_90;
  undefined8 local_88;
  uint local_80 [2];
  _tlgWrapperByVal<8> *local_78;
  undefined8 local_70;
  _tlgWrapperByVal<1> *local_68;
  undefined8 local_60;
  uint *local_58;
  undefined8 local_50;
  undefined8 local_48;
  uint local_40 [2];
  _tlgWrapperByVal<4> *local_38;
  undefined8 local_30;
  _tlgWrapperByVal<1> *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_2f8;
  local_28 = param_36;
  local_38 = param_35;
  local_58 = local_40;
  local_48 = *(undefined8 *)param_34;
  local_40[0] = (uint)*(ushort *)(param_34 + 8);
  local_68 = param_33;
  local_78 = param_32;
  local_98 = local_80;
  local_88 = *(undefined8 *)param_31;
  local_80[0] = (uint)*(ushort *)(param_31 + 8);
  local_a8 = param_30;
  local_b8 = param_29;
  local_d8 = local_c0;
  local_c8 = *(undefined8 *)param_28;
  local_c0[0] = (uint)*(ushort *)(param_28 + 8);
  local_e8 = param_27;
  local_f8 = param_26;
  local_118 = local_100;
  local_108 = *(undefined8 *)param_25;
  local_100[0] = (uint)*(ushort *)(param_25 + 8);
  local_128 = param_24;
  local_138 = param_23;
  local_158 = local_140;
  local_148 = *(undefined8 *)param_22;
  local_140[0] = (uint)*(ushort *)(param_22 + 8);
  local_168 = param_21;
  local_178 = param_20;
  local_20 = 1;
  local_30 = 4;
  local_50 = 2;
  local_40[1] = 0;
  local_60 = 1;
  local_70 = 8;
  local_90 = 2;
  local_80[1] = 0;
  local_a0 = 1;
  local_b0 = 8;
  local_d0 = 2;
  local_c0[1] = 0;
  local_e0 = 1;
  local_f0 = 8;
  local_110 = 2;
  local_100[1] = 0;
  local_120 = 1;
  local_130 = 8;
  local_150 = 2;
  local_140[1] = 0;
  local_160 = 1;
  local_198 = local_180;
  local_170 = 8;
  local_190 = 2;
  local_188 = *(undefined8 *)param_19;
  local_180[0] = (uint)*(ushort *)(param_19 + 8);
  local_1a8 = param_18;
  local_1b8 = param_17;
  local_1d8 = local_1c0;
  local_1c8 = *(undefined8 *)param_16;
  local_1c0[0] = (uint)*(ushort *)(param_16 + 8);
  local_1e8 = param_15;
  local_1f8 = param_14;
  local_218 = local_200;
  local_208 = *(undefined8 *)param_13;
  local_200[0] = (uint)*(ushort *)(param_13 + 8);
  local_228 = param_12;
  local_238 = param_11;
  local_258 = local_240;
  local_248 = *(undefined8 *)param_10;
  local_240[0] = (uint)*(ushort *)(param_10 + 8);
  local_180[1] = 0;
  local_1a0 = 1;
  local_1b0 = 8;
  local_268 = *(undefined8 *)param_9;
  local_278 = param_8;
  local_288 = param_7;
  local_298 = param_6;
  local_2a8 = param_5;
  local_1d0 = 2;
  local_1c0[1] = 0;
  local_1e0 = 1;
  local_1f0 = 8;
  local_210 = 2;
  local_200[1] = 0;
  local_220 = 1;
  local_230 = 8;
  local_250 = 2;
  local_240[1] = 0;
  local_260 = 0x10;
  local_270 = 1;
  local_280 = 4;
  local_290 = 4;
  local_2a0 = 8;
  lVar1 = _tlgWriteTransfer_EventWriteTransfer
                    (0x180025090,param_2,(LPCGUID)0x0,(LPCGUID)0x0,0x2b,local_2c8);
  return lVar1;
}



===== WPP_SF_qqqdqdqD @ 1800015e0 =====

void WPP_SF_qqqdqdqD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                    undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                    undefined1 param_9,undefined1 param_10,undefined1 param_11)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  EtwTraceMessage(param_1,0x2b,&WPP_e4386b12b8143f81186affdeca2b77e8_Traceguids,param_2,&local_res20
                  ,8,&param_5,8,&param_6,8,&param_7,4,&param_8,8,&param_9,4,&param_10,8,&param_11,4,
                  0);
  return;
}



===== BCryptEnumAlgorithms @ 180001690 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

NTSTATUS __stdcall
BCryptEnumAlgorithms
          (ULONG dwAlgOperations,ULONG *pAlgCount,BCRYPT_ALGORITHM_IDENTIFIER **ppAlgList,
          ULONG dwFlags)

{
  PWSTR _Src;
  NTSTATUS NVar1;
  longlong lVar2;
  PCRYPT_PROVIDER_REFS p_Var3;
  PCRYPT_PROVIDER_REFS *pp_Var4;
  undefined8 uVar5;
  PCRYPT_PROVIDER_REF *pp_Var6;
  ulonglong uVar7;
  int iVar8;
  ULONG UVar9;
  undefined1 uVar10;
  ulonglong uVar11;
  int iVar12;
  uint uVar13;
  longlong lVar14;
  ulonglong uVar15;
  LPWSTR _Dst;
  undefined1 auStackY_178 [32];
  PCRYPT_PROVIDER_REFS *local_138;
  BCRYPT_ALGORITHM_IDENTIFIER *local_130;
  longlong local_128;
  undefined1 local_104 [12];
  PCRYPT_PROVIDER_REFS local_f8;
  undefined4 local_f0;
  undefined8 local_ec;
  undefined8 local_e0;
  undefined4 local_d8;
  undefined8 local_d4;
  undefined8 local_c8;
  undefined4 local_c0;
  undefined8 local_bc;
  undefined8 local_b0;
  undefined4 local_a8;
  undefined8 local_a4;
  undefined8 local_98;
  undefined4 local_90;
  undefined8 local_8c;
  undefined8 local_80;
  undefined4 local_78;
  undefined8 local_74;
  undefined8 local_68;
  undefined4 local_60;
  undefined8 local_5c;
  undefined8 local_50;
  ulonglong local_48;
  
                    /* 0x1690  22  BCryptEnumAlgorithms */
  local_48 = __security_cookie ^ (ulonglong)auStackY_178;
  iVar8 = 0;
  local_130 = (BCRYPT_ALGORITHM_IDENTIFIER *)0x0;
  local_104._0_8_ = 1;
  local_f8 = (PCRYPT_PROVIDER_REFS)0x0;
  uVar5 = 4;
  local_f0 = 2;
  lVar14 = 8;
  local_d4 = 4;
  local_c0 = 4;
  local_ec = 2;
  local_e0 = 0;
  local_d8 = 3;
  local_c8 = 0;
  local_bc = 8;
  local_b0 = 0;
  local_a8 = 5;
  local_a4 = 0x10;
  local_98 = 0;
  local_90 = 6;
  local_8c = 0x20;
  local_80 = 0;
  local_78 = 7;
  local_74 = 0x40;
  local_68 = 0;
  local_60 = 8;
  local_5c = 0x80;
  local_50 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_DqqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),4,ppAlgList,dwAlgOperations,
                (char)pAlgCount,(char)ppAlgList,(char)dwFlags);
  }
  uVar11 = 0;
  if ((((dwAlgOperations < 0x100) && (pAlgCount != (ULONG *)0x0)) &&
      (ppAlgList != (BCRYPT_ALGORITHM_IDENTIFIER **)0x0)) && (dwFlags == 0)) {
    *pAlgCount = 0;
    *ppAlgList = (BCRYPT_ALGORITHM_IDENTIFIER *)0x0;
    for (; (uint)uVar11 < 8; uVar11 = (ulonglong)((uint)uVar11 + 1)) {
      if (((*(uint *)(local_104 + (uVar11 * 6 + -1) * 4 + 4) & dwAlgOperations) != 0) ||
         (dwAlgOperations == 0)) {
        pp_Var4 = (PCRYPT_PROVIDER_REFS *)(local_104 + (uVar11 * 6 + 2) * 4 + 4);
        while (NVar1 = BCryptResolveProviders
                                 ((LPCWSTR)0x0,*(ULONG *)(local_104 + (uVar11 * 6 + -2) * 4 + 4),
                                  (LPCWSTR)0x0,(LPCWSTR)0x0,1,1,
                                  (ULONG *)(local_104 + uVar11 * 0x18 + 4),pp_Var4),
              NVar1 == -0x3fffffdd) {
          if (*pp_Var4 != (PCRYPT_PROVIDER_REFS)0x0) {
            SafeAllocaFreeToHeap(*pp_Var4);
          }
          p_Var3 = (PCRYPT_PROVIDER_REFS)
                   BCryptAlloc((ulonglong)*(uint *)(local_104 + uVar11 * 0x18 + 4));
          *pp_Var4 = p_Var3;
          if (p_Var3 == (PCRYPT_PROVIDER_REFS)0x0) {
            NVar1 = -0x3fffffe9;
            goto LAB_180001a16;
          }
        }
        if ((NVar1 != -0x3ffffddb) && (NVar1 < 0)) {
LAB_180001a16:
          uVar10 = 0x2a;
          goto LAB_180001a30;
        }
      }
    }
    pp_Var4 = &local_f8;
    iVar12 = 0;
    do {
      p_Var3 = *pp_Var4;
      if ((p_Var3 != (PCRYPT_PROVIDER_REFS)0x0) && (p_Var3->cProviders != 0)) {
        iVar8 = iVar8 + p_Var3->cProviders;
        pp_Var6 = p_Var3->rgpProviders;
        uVar11 = (ulonglong)p_Var3->cProviders;
        do {
          lVar2 = -1;
          do {
            lVar2 = lVar2 + 1;
          } while ((*pp_Var6)->pszFunction[lVar2] != L'\0');
          pp_Var6 = pp_Var6 + 1;
          iVar12 = iVar12 + (int)lVar2 * 2 + 2;
          uVar11 = uVar11 - 1;
        } while (uVar11 != 0);
      }
      pp_Var4 = pp_Var4 + 3;
      lVar14 = lVar14 + -1;
    } while (lVar14 != 0);
    UVar9 = 0;
    if (iVar8 != 0) {
      local_130 = (BCRYPT_ALGORITHM_IDENTIFIER *)
                  BCryptAlloc((ulonglong)(uint)(iVar8 * 0x10 + iVar12));
      if (local_130 == (BCRYPT_ALGORITHM_IDENTIFIER *)0x0) {
        NVar1 = -0x3fffffe9;
        uVar10 = 0x55;
LAB_180001a30:
        DebugTraceError((char)NVar1,"Status",
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar10);
        goto LAB_18000179a;
      }
      local_138 = &local_f8;
      local_128 = 8;
      _Dst = (LPWSTR)((longlong)&local_130->pszName + (ulonglong)(uint)(iVar8 * 0x10));
      uVar11 = 0;
      do {
        p_Var3 = *local_138;
        if ((p_Var3 != (PCRYPT_PROVIDER_REFS)0x0) && (uVar15 = 0, p_Var3->cProviders != 0)) {
          UVar9 = *(ULONG *)(local_138 + -2);
          do {
            local_130[uVar11].pszName = _Dst;
            local_130[uVar11].dwClass = UVar9;
            local_130[uVar11].dwFlags = 0;
            _Src = p_Var3->rgpProviders[uVar15]->pszFunction;
            lVar14 = -1;
            do {
              lVar2 = lVar14;
              lVar14 = lVar2 + 1;
            } while (_Src[lVar14] != L'\0');
            uVar7 = (ulonglong)((int)lVar2 + 2);
            memcpy(_Dst,_Src,uVar7 * 2);
            _Dst = _Dst + uVar7;
            uVar11 = (ulonglong)((int)uVar11 + 1);
            uVar13 = (int)uVar15 + 1;
            uVar15 = (ulonglong)uVar13;
          } while (uVar13 < p_Var3->cProviders);
        }
        UVar9 = (ULONG)uVar11;
        local_138 = local_138 + 3;
        local_128 = local_128 + -1;
      } while (local_128 != 0);
    }
    NVar1 = 0;
    *pAlgCount = UVar9;
    *ppAlgList = local_130;
  }
  else {
    NVar1 = -0x3ffffff3;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar5,ppAlgList,"Status",0xd,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",0xf2);
    }
  }
LAB_18000179a:
  lVar14 = 8;
  pp_Var4 = &local_f8;
  do {
    if (*pp_Var4 != (PCRYPT_PROVIDER_REFS)0x0) {
      SafeAllocaFreeToHeap(*pp_Var4);
    }
    pp_Var4 = pp_Var4 + 3;
    lVar14 = lVar14 + -1;
  } while (lVar14 != 0);
  return NVar1;
}



===== ConvertRsaPrivateBlobToLegacy @ 180001a8c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

int ConvertRsaPrivateBlobToLegacy
              (undefined1 (*param_1) [16],ulonglong param_2,undefined4 *param_3,uint param_4,
              uint *param_5)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  undefined4 *puVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined1 uVar11;
  undefined1 auStackY_78 [32];
  uint local_38 [2];
  ulonglong local_30;
  
  puVar10 = auStackY_78;
  local_30 = __security_cookie ^ (ulonglong)local_38;
  local_38[0] = 0;
  uVar6 = param_2 & 0xffffffff;
  if ((*(uint *)(*param_1 + 8) < 5) && (*(uint *)(*param_1 + 0xc) < 0x801)) {
    uVar2 = *(uint *)(*param_1 + 4);
    if ((0x3f00 < uVar2 - 0x100) || ((uVar2 & 7) != 0)) {
      uVar11 = 0xde;
      goto LAB_180001cea;
    }
    uVar2 = uVar2 + 0xf >> 4;
    if ((*(uint *)param_1[1] != uVar2) || (*(uint *)(param_1[1] + 4) != uVar2)) {
      uVar11 = 0xeb;
      goto LAB_180001cea;
    }
    uVar2 = uVar2 * 9 + 0x14;
    *param_5 = uVar2;
    if (param_3 == (undefined4 *)0x0) {
      iVar3 = 0;
      puVar10 = auStackY_78;
      goto LAB_180001d04;
    }
    if (param_4 < uVar2) {
      iVar3 = -0x7ff6ffd8;
      goto LAB_180001d04;
    }
    iVar3 = ConvertRsaPrivateBlobToFullRsa(param_1,param_2,0,0,local_38);
    if (iVar3 == 0) {
      uVar8 = (ulonglong)local_38[0];
      puVar5 = (undefined4 *)0x0;
      puVar9 = auStackY_78;
      if (((uVar8 == 0) || (puVar9 = auStackY_78, g_ulMaxStackAllocSize < uVar8)) ||
         (uVar7 = g_ulAdditionalProbeSize + 8 + uVar8, puVar9 = auStackY_78, uVar7 < uVar8)) {
LAB_180001bd5:
        puVar10 = puVar9;
        if (uVar8 <= uVar8 + 8) {
          *(undefined8 *)(puVar9 + -8) = 0x180001bea;
          puVar5 = (undefined4 *)(*g_pfnAllocate)();
          if (puVar5 != (undefined4 *)0x0) {
            *puVar5 = 0x70616548;
            puVar5 = puVar5 + 2;
          }
        }
      }
      else {
        uVar4 = VerifyStackAvailable(uVar7);
        puVar9 = auStackY_78;
        if ((int)uVar4 == 0) goto LAB_180001bd5;
        uVar7 = uVar8 + 0x17;
        if (uVar7 <= uVar8 + 8) {
          uVar7 = 0xffffffffffffff0;
        }
        lVar1 = -(uVar7 & 0xfffffffffffffff0);
        puVar5 = (undefined4 *)0x0;
        puVar9 = auStackY_78 + lVar1;
        if ((undefined4 *)((longlong)local_38 + lVar1) == (undefined4 *)0x0) goto LAB_180001bd5;
        *(undefined4 *)((longlong)local_38 + lVar1) = 0x6b637453;
        puVar5 = (undefined4 *)((longlong)local_38 + lVar1 + 8);
        puVar9 = auStackY_78 + lVar1;
        puVar10 = auStackY_78 + lVar1;
        if (puVar5 == (undefined4 *)0x0) goto LAB_180001bd5;
      }
      if (puVar5 != (undefined4 *)0x0) {
        uVar8 = (ulonglong)local_38[0];
        *(uint **)(puVar10 + 0x20) = local_38;
        *(undefined8 *)(puVar10 + -8) = 0x180001c2e;
        iVar3 = ConvertRsaPrivateBlobToFullRsa
                          (param_1,uVar6,puVar5,uVar8,*(undefined8 *)(puVar10 + 0x20));
        uVar2 = local_38[0];
        if (iVar3 == 0) {
          *(undefined4 *)(puVar10 + 0x28) = 0xa400;
          *(uint **)(puVar10 + 0x20) = param_5;
          *(undefined8 *)(puVar10 + -8) = 0x180001c95;
          uVar6 = ConvertFullRsaToLegacy
                            ((longlong)puVar5,uVar2,param_3,param_4,*(uint **)(puVar10 + 0x20),
                             *(undefined4 *)(puVar10 + 0x28));
          iVar3 = (int)uVar6;
          if (iVar3 == 0) {
            iVar3 = 0;
          }
          else {
            *(undefined8 *)(puVar10 + -8) = 0x180001cb6;
            DebugTraceError((char)uVar6,"Status",
                            "onecore\\ds\\security\\cryptoapi\\ncrypt\\translate\\bcrypttranslate.c"
                            ,0x34);
          }
        }
        else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
          uVar4 = *(undefined8 *)(WPP_GLOBAL_Control + 0x10);
          *(undefined4 *)(puVar10 + 0x30) = 800;
          *(char **)(puVar10 + 0x28) =
               "onecore\\ds\\security\\cryptoapi\\ncrypt\\translate\\bcrypttranslate.c";
          *(int *)(puVar10 + 0x20) = iVar3;
          *(undefined8 *)(puVar10 + -8) = 0x180001c75;
          WPP_SF_sDsd(uVar4,uVar6,
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\translate\\bcrypttranslate.c",
                      "Status",puVar10[0x20],*(char **)(puVar10 + 0x28),puVar10[0x30]);
        }
        if (puVar5[-2] == 0x70616548) {
          *(undefined8 *)(puVar10 + -8) = 0x180001cd2;
          (*g_pfnFree)();
        }
        goto LAB_180001d04;
      }
      iVar3 = -0x7ff6fff2;
      uVar11 = 0x19;
    }
    else {
      uVar11 = 0xc;
      puVar10 = auStackY_78;
    }
  }
  else {
    uVar11 = 0xd5;
LAB_180001cea:
    iVar3 = -0x7ff6ffd7;
    puVar10 = auStackY_78;
  }
  *(undefined8 *)(puVar10 + -8) = 0x180001d04;
  DebugTraceError((char)iVar3,"Status",
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\translate\\bcrypttranslate.c",uVar11);
LAB_180001d04:
  *(undefined8 *)(puVar10 + -8) = 0x180001d12;
  return iVar3;
}



===== ConvertRsaPrivateBlobToFullRsa @ 180001d34 =====

undefined4
ConvertRsaPrivateBlobToFullRsa
          (undefined1 (*param_1) [16],ulonglong param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5)

{
  undefined4 uVar1;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  int local_18;
  
  uVar4 = *(int *)(*param_1 + 8) + 0x18;
  uVar3 = param_2;
  if (0x17 < uVar4) {
    uVar2 = SUB164(*param_1,0xc) + uVar4;
    uVar3 = (ulonglong)uVar2;
    if (uVar4 <= uVar2) {
      local_18 = (int)*(undefined8 *)param_1[1];
      uVar4 = local_18 + uVar2;
      if (uVar2 <= uVar4) {
        uVar2 = (int)((ulonglong)*(undefined8 *)param_1[1] >> 0x20) + uVar4;
        uVar3 = (ulonglong)uVar2;
        if (uVar4 <= uVar2) {
          if ((uint)param_2 < uVar2) {
            DebugTraceError(5,"Status",
                            "onecore\\ds\\security\\cryptoapi\\ncrypt\\translate\\bcrypttranslate.c"
                            ,0xa8);
            return 0x80090005;
          }
          uVar1 = MSCryptConvertRsaPrivateBlobToFullRsaBlob
                            (param_1,param_2 & 0xffffffff,SUB168(*param_1,8),param_4,param_5);
          return uVar1;
        }
      }
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
    WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar3,param_3,"Status",0x16,
                "onecore\\ds\\security\\cryptoapi\\ncrypt\\translate\\bcrypttranslate.c",0xa1);
  }
  return 0x216;
}



===== BCryptDeriveKeyCapi @ 180001e30 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

NTSTATUS __stdcall
BCryptDeriveKeyCapi(BCRYPT_HASH_HANDLE hHash,BCRYPT_ALG_HANDLE hTargetAlg,PUCHAR pbDerivedKey,
                   ULONG cbDerivedKey,ULONG dwFlags)

{
  undefined4 *puVar1;
  byte bVar2;
  undefined8 uVar3;
  uint uVar4;
  longlong lVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  BCRYPT_HASH_HANDLE pvVar12;
  BCRYPT_ALG_HANDLE pvVar13;
  NTSTATUS NVar14;
  int iVar15;
  undefined8 uVar16;
  byte *pbVar17;
  uint uVar18;
  ulonglong uVar19;
  wchar_t *pwVar20;
  BCRYPT_HASH_HANDLE *phHash;
  uint *puVar21;
  PUCHAR pbOutput;
  undefined1 *puVar22;
  undefined1 *puVar23;
  uint *puVar24;
  ulonglong uVar25;
  undefined1 uVar26;
  bool bVar27;
  uint uVar28;
  undefined1 auStackY_148 [32];
  uint local_108;
  ULONG local_104;
  BCRYPT_HASH_HANDLE local_100;
  BCRYPT_HASH_HANDLE local_f8;
  BCRYPT_ALG_HANDLE local_f0;
  wchar_t local_e8 [8];
  uint local_d8 [16];
  uint local_98 [16];
  ulonglong local_58;
  
                    /* 0x1e30  13  BCryptDeriveKeyCapi */
  puVar21 = &local_108;
  local_58 = __security_cookie ^ (ulonglong)puVar21;
  local_108 = 0;
  local_f0 = (BCRYPT_ALG_HANDLE)0x0;
  local_100 = (BCRYPT_HASH_HANDLE)0x0;
  local_f8 = (BCRYPT_HASH_HANDLE)0x0;
  local_104 = 0;
  pwVar20 = hTargetAlg;
  puVar24 = (uint *)pbDerivedKey;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    pwVar20 = (wchar_t *)0x29;
    WPP_SF_qqqdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x29,pbDerivedKey,hHash,(char)hTargetAlg
                 ,(char)pbDerivedKey,(char)cbDerivedKey,(char)dwFlags);
  }
  puVar23 = auStackY_148;
  if (((dwFlags == 0) && (pbDerivedKey != (PUCHAR)0x0)) && (cbDerivedKey != 0)) {
    pwVar20 = L"HashDigestLength";
    NVar14 = BCryptGetProperty(hHash,L"HashDigestLength",(PUCHAR)puVar21,4,&local_104,0);
    if (NVar14 < 0) {
      puVar23 = auStackY_148;
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_180002084;
      bVar2 = WPP_GLOBAL_Control[0x1c];
      goto joined_r0x000180002105;
    }
    uVar4 = local_108 * 2;
    if ((uVar4 < cbDerivedKey) || (0x40 < local_108)) {
      NVar14 = -0x3ffffff3;
      DebugTraceError(0xd,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",0xfe);
      puVar23 = auStackY_148;
      goto LAB_180002084;
    }
    uVar19 = (ulonglong)uVar4;
    pbOutput = (PUCHAR)0x0;
    puVar22 = auStackY_148;
    if (((uVar4 == 0) || (puVar22 = auStackY_148, g_ulMaxStackAllocSize < uVar19)) ||
       ((uVar25 = g_ulAdditionalProbeSize + 8 + uVar19, puVar22 = auStackY_148, uVar25 < uVar19 ||
        (uVar16 = VerifyStackAvailable(uVar25), puVar22 = auStackY_148, (int)uVar16 == 0)))) {
LAB_180001f0b:
      puVar23 = puVar22;
      if (uVar19 <= uVar19 + 8) {
        *(undefined8 *)(puVar22 + -8) = 0x180001f24;
        pbOutput = (PUCHAR)(*g_pfnAllocate)();
        if (pbOutput != (PUCHAR)0x0) {
          builtin_memcpy(pbOutput,"Heap",4);
          pbOutput = pbOutput + 8;
        }
      }
    }
    else {
      uVar25 = uVar19 + 0x17;
      if (uVar25 <= uVar19 + 8) {
        uVar25 = 0xffffffffffffff0;
      }
      lVar5 = -(uVar25 & 0xfffffffffffffff0);
      puVar23 = auStackY_148 + lVar5;
      puVar1 = (undefined4 *)((longlong)local_e8 + lVar5 + -0x20);
      pbOutput = (PUCHAR)0x0;
      puVar22 = auStackY_148 + lVar5;
      if (puVar1 == (undefined4 *)0x0) goto LAB_180001f0b;
      *puVar1 = 0x6b637453;
      pbOutput = (PUCHAR)((longlong)local_e8 + lVar5 + -0x18);
      puVar22 = auStackY_148 + lVar5;
      if (pbOutput == (PUCHAR)0x0) goto LAB_180001f0b;
    }
    uVar4 = local_108;
    if (pbOutput != (PUCHAR)0x0) {
      *(undefined8 *)(puVar23 + -8) = 0x180001ffe;
      NVar14 = BCryptFinishHash(hHash,pbOutput,uVar4,0);
      if (NVar14 < 0) {
        *(undefined8 *)(puVar23 + -8) = 0x18000246c;
        DebugTraceError((char)NVar14,"Status",
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",0x18);
      }
      else {
        bVar27 = local_108 < cbDerivedKey;
        if (((hTargetAlg != (BCRYPT_ALG_HANDLE)0x0) && (cbDerivedKey == 0x10)) && (local_108 < 0x20)
           ) {
          *(undefined4 *)(puVar23 + 0x28) = 0;
          *(ULONG **)(puVar23 + 0x20) = &local_104;
          *(undefined8 *)(puVar23 + -8) = 0x1800024a5;
          NVar14 = BCryptGetProperty(hTargetAlg,L"AlgorithmName",(PUCHAR)local_e8,8,
                                     *(ULONG **)(puVar23 + 0x20),*(ULONG *)(puVar23 + 0x28));
          if (NVar14 < 0) {
            *(undefined8 *)(puVar23 + -8) = 0x1800024c7;
            DebugTraceError((char)NVar14,"Status",
                            "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",0x34);
          }
          else {
            *(undefined8 *)(puVar23 + -8) = 0x1800024e0;
            iVar15 = wcscmp(local_e8,L"AES");
            bVar27 = iVar15 == 0 || bVar27;
          }
        }
        uVar4 = local_108;
        if (bVar27) {
          *(undefined8 *)(puVar23 + -8) = 0x18000214e;
          memset(local_d8,0x36,0x40);
          *(undefined8 *)(puVar23 + -8) = 0x180002160;
          memset(local_98,0x5c,0x40);
          uVar19 = 0;
          uVar18 = 0;
          if (uVar4 != 0) {
            if (7 < uVar4) {
              uVar28 = uVar4 - 1;
              if (((pbOutput + uVar28 < local_98) ||
                  ((PUCHAR)((longlong)local_98 + (ulonglong)uVar28) < pbOutput)) &&
                 ((pbOutput + uVar28 < local_d8 ||
                  ((PUCHAR)((longlong)local_d8 + (ulonglong)uVar28) < pbOutput)))) {
                if (0xf < uVar4) {
                  do {
                    puVar21 = (uint *)(pbOutput + uVar19);
                    uVar18 = *puVar21;
                    uVar28 = puVar21[1];
                    uVar6 = puVar21[2];
                    uVar7 = puVar21[3];
                    uVar8 = *(uint *)((longlong)local_98 + uVar19);
                    uVar9 = *(uint *)((longlong)local_98 + uVar19 + 4);
                    uVar10 = *(uint *)((longlong)local_98 + uVar19 + 8);
                    uVar11 = *(uint *)((longlong)local_98 + uVar19 + 0xc);
                    *(uint *)((longlong)local_d8 + uVar19) =
                         uVar18 ^ *(uint *)((longlong)local_d8 + uVar19);
                    *(uint *)((longlong)local_d8 + uVar19 + 4) =
                         uVar28 ^ *(uint *)((longlong)local_d8 + uVar19 + 4);
                    *(uint *)((longlong)local_d8 + uVar19 + 8) =
                         uVar6 ^ *(uint *)((longlong)local_d8 + uVar19 + 8);
                    *(uint *)((longlong)local_d8 + uVar19 + 0xc) =
                         uVar7 ^ *(uint *)((longlong)local_d8 + uVar19 + 0xc);
                    *(uint *)((longlong)local_98 + uVar19) = uVar18 ^ uVar8;
                    *(uint *)((longlong)local_98 + uVar19 + 4) = uVar28 ^ uVar9;
                    *(uint *)((longlong)local_98 + uVar19 + 8) = uVar6 ^ uVar10;
                    *(uint *)((longlong)local_98 + uVar19 + 0xc) = uVar7 ^ uVar11;
                    uVar18 = (int)uVar19 + 0x10;
                    uVar19 = (ulonglong)uVar18;
                  } while (uVar18 < uVar4 - (uVar4 & 0xf));
                  if ((uVar4 & 0xf) < 8) goto LAB_18000222b;
                }
                do {
                  uVar28 = (uint)*(undefined8 *)(pbOutput + uVar19);
                  uVar18 = (uint)((ulonglong)*(undefined8 *)(pbOutput + uVar19) >> 0x20);
                  *(ulonglong *)((longlong)local_d8 + uVar19) =
                       CONCAT44(uVar18 ^ (uint)((ulonglong)
                                                *(undefined8 *)((longlong)local_d8 + uVar19) >> 0x20
                                               ),
                                uVar28 ^ (uint)*(undefined8 *)((longlong)local_d8 + uVar19));
                  *(ulonglong *)((longlong)local_98 + uVar19) =
                       CONCAT44(uVar18 ^ (uint)((ulonglong)
                                                *(undefined8 *)((longlong)local_98 + uVar19) >> 0x20
                                               ),
                                uVar28 ^ (uint)*(undefined8 *)((longlong)local_98 + uVar19));
                  uVar18 = (int)uVar19 + 8;
                  uVar19 = (ulonglong)uVar18;
                } while (uVar18 < uVar4 - (uVar4 & 7));
              }
            }
LAB_18000222b:
            if (uVar18 < uVar4) {
              uVar25 = (ulonglong)uVar18;
              uVar19 = (ulonglong)(uVar4 - uVar18);
              do {
                pbVar17 = (byte *)((longlong)local_d8 + uVar25);
                bVar2 = pbVar17[(longlong)pbOutput - (longlong)local_d8];
                *(byte *)((longlong)local_98 + uVar25) =
                     *(byte *)((longlong)local_98 + uVar25) ^ bVar2;
                uVar25 = uVar25 + 1;
                *pbVar17 = *pbVar17 ^ bVar2;
                uVar19 = uVar19 - 1;
              } while (uVar19 != 0);
            }
          }
          *(undefined4 *)(puVar23 + 0x28) = 0;
          *(ULONG **)(puVar23 + 0x20) = &local_104;
          *(undefined8 *)(puVar23 + -8) = 0x180002289;
          NVar14 = BCryptGetProperty(hHash,L"ProviderHandle",(PUCHAR)&local_f0,8,
                                     *(ULONG **)(puVar23 + 0x20),*(ULONG *)(puVar23 + 0x28));
          pvVar13 = local_f0;
          if (NVar14 < 0) {
            uVar26 = 0x5b;
LAB_1800023bf:
            *(undefined8 *)(puVar23 + -8) = 0x1800023d0;
            DebugTraceError((char)NVar14,"Status",
                            "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar26);
          }
          else {
            phHash = &local_100;
            *(undefined4 *)(puVar23 + 0x30) = 0;
            *(undefined4 *)(puVar23 + 0x28) = 0;
            uVar16 = 0;
            *(undefined8 *)(puVar23 + 0x20) = 0;
            *(undefined8 *)(puVar23 + -8) = 0x1800022bf;
            NVar14 = BCryptCreateHash(pvVar13,phHash,(PUCHAR)0x0,0,*(PUCHAR *)(puVar23 + 0x20),
                                      *(ULONG *)(puVar23 + 0x28),*(ULONG *)(puVar23 + 0x30));
            pvVar12 = local_100;
            if (NVar14 < 0) {
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
                uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x10);
                *(undefined4 *)(puVar23 + 0x30) = 0x1c68;
                *(char **)(puVar23 + 0x28) =
                     "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c";
                *(NTSTATUS *)(puVar23 + 0x20) = NVar14;
                *(undefined8 *)(puVar23 + -8) = 0x180002421;
                WPP_SF_sDsd(uVar3,phHash,uVar16,"Status",puVar23[0x20],*(char **)(puVar23 + 0x28),
                            puVar23[0x30]);
              }
            }
            else {
              puVar21 = local_d8;
              uVar16 = 0x40;
              *(undefined8 *)(puVar23 + -8) = 0x1800022dd;
              NVar14 = BCryptHashData(pvVar12,(PUCHAR)puVar21,0x40,0);
              pvVar12 = local_100;
              uVar4 = local_108;
              if (-1 < NVar14) {
                *(undefined8 *)(puVar23 + -8) = 0x18000233d;
                NVar14 = BCryptFinishHash(pvVar12,pbOutput,uVar4,0);
                pvVar13 = local_f0;
                if (NVar14 < 0) {
                  uVar26 = 0x7c;
                }
                else {
                  *(undefined4 *)(puVar23 + 0x30) = 0;
                  *(undefined4 *)(puVar23 + 0x28) = 0;
                  *(undefined8 *)(puVar23 + 0x20) = 0;
                  *(undefined8 *)(puVar23 + -8) = 0x180002373;
                  NVar14 = BCryptCreateHash(pvVar13,&local_f8,(PUCHAR)0x0,0,
                                            *(PUCHAR *)(puVar23 + 0x20),*(ULONG *)(puVar23 + 0x28),
                                            *(ULONG *)(puVar23 + 0x30));
                  pvVar12 = local_f8;
                  if (NVar14 < 0) {
                    uVar26 = 0x89;
                  }
                  else {
                    *(undefined8 *)(puVar23 + -8) = 0x180002391;
                    NVar14 = BCryptHashData(pvVar12,(PUCHAR)local_98,0x40,0);
                    pvVar12 = local_f8;
                    uVar4 = local_108;
                    if (NVar14 < 0) {
                      uVar26 = 0x93;
                    }
                    else {
                      uVar19 = (ulonglong)local_108;
                      *(undefined8 *)(puVar23 + -8) = 0x1800023af;
                      NVar14 = BCryptFinishHash(pvVar12,pbOutput + uVar19,uVar4,0);
                      if (-1 < NVar14) goto LAB_180002037;
                      uVar26 = 0x9d;
                    }
                  }
                }
                goto LAB_1800023bf;
              }
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
                uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x10);
                *(undefined4 *)(puVar23 + 0x30) = 0x1c72;
                *(char **)(puVar23 + 0x28) =
                     "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c";
                *(NTSTATUS *)(puVar23 + 0x20) = NVar14;
                *(undefined8 *)(puVar23 + -8) = 0x180002325;
                WPP_SF_sDsd(uVar3,puVar21,uVar16,"Status",puVar23[0x20],*(char **)(puVar23 + 0x28),
                            puVar23[0x30]);
              }
            }
          }
        }
        else {
LAB_180002037:
          *(undefined8 *)(puVar23 + -8) = 0x180002045;
          memcpy(pbDerivedKey,pbOutput,(ulonglong)cbDerivedKey);
          NVar14 = 0;
        }
      }
      if (*(int *)(pbOutput + -8) == 0x70616548) {
        *(undefined8 *)(puVar23 + -8) = 0x180002060;
        (*g_pfnFree)(pbOutput + -8);
      }
      goto LAB_180002084;
    }
    NVar14 = -0x3fffffe9;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180002084;
    *(undefined4 *)(puVar23 + 0x30) = 0x1c0e;
    *(char **)(puVar23 + 0x28) = "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c";
    *(undefined4 *)(puVar23 + 0x20) = 0xc0000017;
  }
  else {
    NVar14 = -0x3ffffff3;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_180002084;
    bVar2 = WPP_GLOBAL_Control[0x1c];
    puVar21 = puVar24;
joined_r0x000180002105:
    puVar23 = auStackY_148;
    if ((bVar2 & 1) == 0) goto LAB_180002084;
  }
  uVar16 = *(undefined8 *)(WPP_GLOBAL_Control + 0x10);
  *(undefined8 *)(puVar23 + -8) = 0x180002137;
  WPP_SF_sDsd(uVar16,pwVar20,puVar21,"Status",puVar23[0x20],*(char **)(puVar23 + 0x28),puVar23[0x30]
             );
LAB_180002084:
  pvVar12 = local_100;
  if (local_100 != (BCRYPT_HASH_HANDLE)0x0) {
    *(undefined8 *)(puVar23 + -8) = 0x18000242b;
    BCryptDestroyHash(pvVar12);
  }
  pvVar12 = local_f8;
  if (local_f8 != (BCRYPT_HASH_HANDLE)0x0) {
    *(undefined8 *)(puVar23 + -8) = 0x1800023da;
    BCryptDestroyHash(pvVar12);
  }
  *(undefined8 *)(puVar23 + -8) = 0x1800020af;
  return NVar14;
}



===== VerifyStackAvailable @ 180002550 =====

undefined8 VerifyStackAvailable(ulonglong param_1)

{
  InternalVerifyStackAvailable(param_1);
  return 1;
}



===== InternalVerifyStackAvailable @ 18000257c =====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void InternalVerifyStackAvailable(ulonglong param_1)

{
  ulonglong uVar1;
  undefined8 auStack_40 [7];
  
  uVar1 = param_1 + 0xf;
  if (uVar1 <= param_1) {
    uVar1 = 0xffffffffffffff0;
  }
  *(undefined8 *)((longlong)auStack_40 - (uVar1 & 0xfffffffffffffff0)) = 0x1800025c0;
  return;
}



===== BCryptDeriveKeyPBKDF2 @ 1800025d0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

NTSTATUS __stdcall
BCryptDeriveKeyPBKDF2
          (BCRYPT_ALG_HANDLE hPrf,PUCHAR pbPassword,ULONG cbPassword,PUCHAR pbSalt,ULONG cbSalt,
          ULONGLONG cIterations,PUCHAR pbDerivedKey,ULONG cbDerivedKey,ULONG dwFlags)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  ULONG UVar4;
  BCRYPT_ALG_HANDLE pvVar5;
  PUCHAR pUVar6;
  PUCHAR pUVar7;
  NTSTATUS NVar8;
  undefined8 uVar9;
  uint uVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  undefined4 *puVar16;
  undefined4 *puVar17;
  undefined4 in_register_00000084;
  uint *puVar18;
  undefined1 uVar19;
  uint uVar20;
  undefined4 *puVar21;
  undefined4 *puVar22;
  undefined1 auStackY_c8 [32];
  undefined1 uVar23;
  uint local_68;
  ULONG UStack_64;
  uint local_60 [2];
  ULONG local_58;
  BCRYPT_ALG_HANDLE local_50;
  PUCHAR local_48;
  PUCHAR local_40;
  ulonglong local_38;
  
                    /* 0x25d0  14  BCryptDeriveKeyPBKDF2 */
  puVar18 = (uint *)CONCAT44(in_register_00000084,cbPassword);
  local_38 = __security_cookie ^ (ulonglong)&local_68;
  puVar21 = (undefined4 *)0x0;
  local_60[1] = 0;
  UStack_64 = 0;
  local_60[0] = 0;
  local_68 = 0;
  local_58 = cbPassword;
  local_50 = hPrf;
  local_48 = pbSalt;
  local_40 = pbPassword;
  if ((((cIterations == 0) || (dwFlags != 0)) || ((pbPassword == (PUCHAR)0x0 && (cbPassword != 0))))
     || ((((pbSalt == (PUCHAR)0x0 && (cbSalt != 0)) || (pbDerivedKey == (PUCHAR)0x0)) ||
         (cbDerivedKey == 0)))) {
    NVar8 = -0x3ffffff3;
    puVar13 = auStackY_c8;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       (puVar13 = auStackY_c8, (WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_1800027cd;
    uVar23 = 0x69;
    uVar19 = 0xd;
  }
  else {
    puVar18 = local_60 + 1;
    NVar8 = BCryptGetProperty(hPrf,L"IsKeyedHash",(PUCHAR)puVar18,4,&UStack_64,0);
    if ((-1 < NVar8) && (local_60[1] != 0)) {
      NVar8 = BCryptGetProperty(hPrf,L"HashDigestLength",(PUCHAR)&local_68,4,&UStack_64,0);
      if (NVar8 < 0) {
        uVar19 = 0x82;
      }
      else {
        puVar18 = local_60;
        uVar20 = ((local_68 - 1) + cbDerivedKey) / local_68;
        NVar8 = BCryptGetProperty(hPrf,L"ObjectLength",(PUCHAR)puVar18,4,&UStack_64,0);
        if (-1 < NVar8) {
          uVar11 = (ulonglong)local_68;
          puVar16 = (undefined4 *)0x0;
          puVar13 = auStackY_c8;
          if (((uVar11 == 0) || (puVar13 = auStackY_c8, g_ulMaxStackAllocSize < uVar11)) ||
             (uVar12 = g_ulAdditionalProbeSize + 8 + uVar11, puVar13 = auStackY_c8, uVar12 < uVar11)
             ) {
LAB_18000273f:
            puVar15 = puVar13;
            if (uVar11 <= uVar11 + 8) {
              *(undefined8 *)(puVar13 + -8) = 0x180002758;
              puVar16 = (undefined4 *)(*g_pfnAllocate)();
              if (puVar16 != (undefined4 *)0x0) {
                *puVar16 = 0x70616548;
                puVar16 = puVar16 + 2;
              }
            }
          }
          else {
            uVar9 = VerifyStackAvailable(uVar12);
            puVar13 = auStackY_c8;
            if ((int)uVar9 == 0) goto LAB_18000273f;
            uVar12 = uVar11 + 0x17;
            if (uVar12 <= uVar11 + 8) {
              uVar12 = 0xffffffffffffff0;
            }
            lVar1 = -(uVar12 & 0xfffffffffffffff0);
            puVar15 = auStackY_c8 + lVar1;
            puVar16 = (undefined4 *)0x0;
            puVar13 = auStackY_c8 + lVar1;
            if ((undefined4 *)((longlong)&local_68 + lVar1) == (undefined4 *)0x0)
            goto LAB_18000273f;
            *(undefined4 *)((longlong)&local_68 + lVar1) = 0x6b637453;
            puVar16 = (undefined4 *)((longlong)local_60 + lVar1);
            puVar13 = auStackY_c8 + lVar1;
            if (puVar16 == (undefined4 *)0x0) goto LAB_18000273f;
          }
          uVar11 = (ulonglong)local_60[0];
          puVar22 = (undefined4 *)0x0;
          puVar13 = puVar15;
          if (((uVar11 == 0) || (g_ulMaxStackAllocSize < uVar11)) ||
             (uVar12 = g_ulAdditionalProbeSize + 8 + uVar11, uVar12 < uVar11)) {
LAB_1800028c9:
            puVar14 = puVar13;
            if (uVar11 <= uVar11 + 8) {
              *(undefined8 *)(puVar13 + -8) = 0x1800028de;
              puVar22 = (undefined4 *)(*g_pfnAllocate)();
              if (puVar22 != (undefined4 *)0x0) {
                *puVar22 = 0x70616548;
                puVar22 = puVar22 + 2;
              }
            }
          }
          else {
            *(undefined8 *)(puVar15 + -8) = 0x180002895;
            uVar9 = VerifyStackAvailable(uVar12);
            if ((int)uVar9 == 0) goto LAB_1800028c9;
            uVar12 = uVar11 + 0x17;
            if (uVar12 <= uVar11 + 8) {
              uVar12 = 0xffffffffffffff0;
            }
            *(undefined8 *)(puVar15 + -8) = 0x1800028bc;
            lVar1 = -(uVar12 & 0xfffffffffffffff0);
            puVar14 = puVar15 + lVar1;
            puVar22 = (undefined4 *)0x0;
            puVar13 = puVar15 + lVar1;
            if ((undefined4 *)(puVar15 + lVar1 + 0x60) == (undefined4 *)0x0) goto LAB_1800028c9;
            *(undefined4 *)(puVar15 + lVar1 + 0x60) = 0x6b637453;
            puVar22 = (undefined4 *)(puVar15 + lVar1 + 0x68);
            puVar13 = puVar15 + lVar1;
            if (puVar22 == (undefined4 *)0x0) goto LAB_1800028c9;
          }
          uVar11 = (ulonglong)(local_68 * uVar20);
          puVar13 = puVar14;
          if (((local_68 * uVar20 == 0) || (g_ulMaxStackAllocSize < uVar11)) ||
             (uVar12 = g_ulAdditionalProbeSize + 8 + uVar11, uVar12 < uVar11)) {
LAB_18000290c:
            puVar15 = puVar13;
            if (uVar11 <= uVar11 + 8) {
              *(undefined8 *)(puVar13 + -8) = 0x180002921;
              puVar21 = (undefined4 *)(*g_pfnAllocate)();
              if (puVar21 != (undefined4 *)0x0) {
                *puVar21 = 0x70616548;
                puVar21 = puVar21 + 2;
              }
            }
          }
          else {
            *(undefined8 *)(puVar14 + -8) = 0x180002ae4;
            uVar9 = VerifyStackAvailable(uVar12);
            if ((int)uVar9 == 0) goto LAB_18000290c;
            uVar12 = uVar11 + 0x17;
            if (uVar12 <= uVar11 + 8) {
              uVar12 = 0xffffffffffffff0;
            }
            *(undefined8 *)(puVar14 + -8) = 0x180002954;
            lVar1 = -(uVar12 & 0xfffffffffffffff0);
            puVar15 = puVar14 + lVar1;
            puVar21 = (undefined4 *)0x0;
            puVar13 = puVar14 + lVar1;
            if ((undefined4 *)(puVar14 + lVar1 + 0x60) == (undefined4 *)0x0) goto LAB_18000290c;
            *(undefined4 *)(puVar14 + lVar1 + 0x60) = 0x6b637453;
            puVar21 = (undefined4 *)(puVar14 + lVar1 + 0x68);
            puVar13 = puVar14 + lVar1;
            if (puVar21 == (undefined4 *)0x0) goto LAB_18000290c;
          }
          if (((puVar16 == (undefined4 *)0x0) || (puVar22 == (undefined4 *)0x0)) ||
             (puVar21 == (undefined4 *)0x0)) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
              *(undefined4 *)(puVar15 + 0x30) = 0x1da4;
              *(char **)(puVar15 + 0x28) = "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c"
              ;
              uVar9 = *(undefined8 *)(WPP_GLOBAL_Control + 0x10);
              *(undefined4 *)(puVar15 + 0x20) = 0xc0000017;
              *(undefined8 *)(puVar15 + -8) = 0x180002b84;
              WPP_SF_sDsd(uVar9,WPP_GLOBAL_Control,puVar18,"Status",puVar15[0x20],
                          *(char **)(puVar15 + 0x28),puVar15[0x30]);
            }
            NVar8 = -0x3fffffe9;
            if (puVar21 != (undefined4 *)0x0) goto LAB_1800029c2;
          }
          else {
            uVar10 = 0;
            while (pUVar6 = local_48, UVar4 = local_58, uVar3 = local_60[0], uVar2 = local_68,
                  uVar10 < uVar20) {
              *(uint *)(puVar15 + 0x58) = local_68;
              pUVar7 = local_40;
              *(undefined1 **)(puVar15 + 0x50) =
                   (undefined1 *)((ulonglong)(uVar10 * uVar2) + (longlong)puVar21);
              pvVar5 = local_50;
              *(undefined4 **)(puVar15 + 0x48) = puVar16;
              *(uint *)(puVar15 + 0x40) = uVar3;
              *(undefined4 **)(puVar15 + 0x38) = puVar22;
              *(uint *)(puVar15 + 0x30) = uVar10 + 1;
              *(ULONGLONG *)(puVar15 + 0x28) = cIterations;
              *(ULONG *)(puVar15 + 0x20) = cbSalt;
              *(undefined8 *)(puVar15 + -8) = 0x180002a57;
              NVar8 = GetPBKDF2Block(pvVar5,pUVar7,UVar4,pUVar6,*(uint *)(puVar15 + 0x20),
                                     *(ulonglong *)(puVar15 + 0x28),*(undefined4 *)(puVar15 + 0x30),
                                     *(PUCHAR *)(puVar15 + 0x38),*(ULONG *)(puVar15 + 0x40),
                                     *(PUCHAR *)(puVar15 + 0x48),*(PUCHAR *)(puVar15 + 0x50),
                                     *(ULONG *)(puVar15 + 0x58));
              if (NVar8 < 0) {
                *(undefined8 *)(puVar15 + -8) = 0x180002b53;
                DebugTraceError((char)NVar8,"Status",
                                "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",0xb8);
                goto LAB_1800029c2;
              }
              uVar10 = uVar10 + 1;
            }
            *(undefined8 *)(puVar15 + -8) = 0x1800029c0;
            memcpy(pbDerivedKey,puVar21,(ulonglong)cbDerivedKey);
            NVar8 = 0;
LAB_1800029c2:
            puVar17 = puVar21;
            for (uVar11 = (ulonglong)(local_68 * uVar20); uVar11 != 0; uVar11 = uVar11 - 1) {
              *(undefined1 *)puVar17 = 0;
              puVar17 = (undefined4 *)((longlong)puVar17 + 1);
            }
            if (puVar21[-2] == 0x70616548) {
              *(undefined8 *)(puVar15 + -8) = 0x1800029eb;
              (*g_pfnFree)();
            }
          }
          if ((puVar22 != (undefined4 *)0x0) && (puVar22[-2] == 0x70616548)) {
            *(undefined8 *)(puVar15 + -8) = 0x180002b95;
            (*g_pfnFree)();
          }
          puVar13 = puVar15;
          if (puVar16 != (undefined4 *)0x0) {
            puVar21 = puVar16;
            for (uVar11 = (ulonglong)local_68; uVar11 != 0; uVar11 = uVar11 - 1) {
              *(undefined1 *)puVar21 = 0;
              puVar21 = (undefined4 *)((longlong)puVar21 + 1);
            }
            if (puVar16[-2] == 0x70616548) {
              *(undefined8 *)(puVar15 + -8) = 0x180002818;
              (*g_pfnFree)();
            }
          }
          goto LAB_1800027cd;
        }
        uVar19 = 0x93;
      }
      DebugTraceError((char)NVar8,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c"
                      ,uVar19);
      puVar13 = auStackY_c8;
      goto LAB_1800027cd;
    }
    NVar8 = -0x3ffffff8;
    puVar13 = auStackY_c8;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       (puVar13 = auStackY_c8, (WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_1800027cd;
    uVar23 = 0x76;
    uVar19 = 8;
  }
  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),WPP_GLOBAL_Control,puVar18,"Status",uVar19,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar23);
  puVar13 = auStackY_c8;
LAB_1800027cd:
  *(undefined8 *)(puVar13 + -8) = 0x1800027db;
  return NVar8;
}



===== WPP_SF_qqqdD @ 180002ba0 =====

void WPP_SF_qqqdD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  EtwTraceMessage(param_1,0x2b,&WPP_e4386b12b8143f81186affdeca2b77e8_Traceguids,param_2,&local_res20
                  ,8,&param_5,8,&param_6,8,&param_7,4,&param_8,4,0);
  return;
}



===== _LoadImage @ 180002c28 =====

int _LoadImage(longlong param_1,longlong *param_2)

{
  LPCWSTR lpLibFileName;
  int iVar1;
  DWORD DVar2;
  HMODULE pHVar3;
  LPCWSTR *ppWVar4;
  undefined8 uVar5;
  LPCWSTR local_res8;
  undefined8 local_38;
  wchar_t *local_30;
  ushort local_28 [8];
  
  local_res8 = (LPCWSTR)0x0;
  local_38 = 0x160014;
  local_30 = L"bcrypt.dll";
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[6] = 0;
  local_28[7] = 0;
  RtlInitUnicodeString(local_28,**(undefined8 **)(param_1 + 0x28));
  ppWVar4 = &local_res8;
  iVar1 = _GetImagePath(local_28,ppWVar4);
  lpLibFileName = local_res8;
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),ppWVar4,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\loader\\loader.c","sResult",(char)iVar1
                  ,"onecore\\ds\\security\\cryptoapi\\ncrypt\\loader\\loader.c",0xab);
    }
  }
  else {
    *param_2 = 0;
    iVar1 = RtlCompareUnicodeString(local_28,&local_38);
    if (iVar1 == 0) {
      *param_2 = g_hInstance;
    }
    if (*param_2 == 0) {
      uVar5 = 0;
      pHVar3 = LoadLibraryExW(lpLibFileName,(HANDLE)0x0,0);
      *param_2 = (longlong)pHVar3;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 0x20) != 0)) {
        WPP_SF_qSq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pHVar3,uVar5,param_1,lpLibFileName,
                   (char)pHVar3);
      }
      if (*param_2 == 0) {
        DVar2 = GetLastError();
        iVar1 = -0x3ffffecb;
        if (DVar2 != 0x7e) {
          iVar1 = -0x3fffff85;
        }
        DebugTraceError((char)iVar1,"sResult",
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\loader\\loader.c",200);
        goto LAB_180002d00;
      }
    }
    iVar1 = 0;
  }
LAB_180002d00:
  if (lpLibFileName != (LPCWSTR)0x0) {
    SafeAllocaFreeToHeap(lpLibFileName);
  }
  return iVar1;
}



===== _GetImagePath @ 180002dd4 =====

undefined4 _GetImagePath(ushort *param_1,undefined8 *param_2)

{
  ushort uVar1;
  UINT UVar2;
  LPWSTR lpBuffer;
  ulonglong uVar3;
  undefined4 uVar4;
  undefined1 uVar5;
  
  *param_2 = 0;
  lpBuffer = (LPWSTR)0x0;
  UVar2 = GetSystemDirectoryW((LPWSTR)0x0,0);
  if (UVar2 == 0) {
    uVar5 = 0x19;
  }
  else {
    lpBuffer = (LPWSTR)BCryptAlloc((ulonglong)*param_1 + 4 + (ulonglong)UVar2 * 2);
    if (lpBuffer == (LPWSTR)0x0) {
      uVar4 = 0xc0000017;
      uVar5 = 0x22;
      goto LAB_180002eaf;
    }
    UVar2 = GetSystemDirectoryW(lpBuffer,UVar2);
    if (UVar2 != 0) {
      uVar3 = (ulonglong)UVar2;
      lpBuffer[uVar3] = L'\\';
      memcpy(lpBuffer + uVar3 + 1,*(void **)(param_1 + 4),(ulonglong)*param_1);
      uVar1 = *param_1;
      *param_2 = lpBuffer;
      lpBuffer[(uVar1 >> 1) + uVar3 + 1] = L'\0';
      return 0;
    }
    uVar5 = 0x2b;
  }
  uVar4 = 0xc000003a;
LAB_180002eaf:
  DebugTraceError((char)uVar4,"sResult","onecore\\ds\\security\\cryptoapi\\ncrypt\\loader\\loader.c"
                  ,uVar5);
  if (lpBuffer != (LPWSTR)0x0) {
    SafeAllocaFreeToHeap(lpBuffer);
  }
  return uVar4;
}



===== BCryptHash @ 180002ee0 =====

NTSTATUS BCryptHash(BCRYPT_ALG_HANDLE param_1,PUCHAR param_2,ULONG param_3,PUCHAR param_4,
                   ULONG param_5,PUCHAR param_6,ULONG param_7)

{
  NTSTATUS NVar1;
  BCRYPT_HASH_HANDLE local_18 [2];
  
                    /* 0x2ee0  37  BCryptHash */
  local_18[0] = (BCRYPT_HASH_HANDLE)0x0;
  NVar1 = BCryptCreateHash(param_1,local_18,(PUCHAR)0x0,0,param_2,param_3,0);
  if (-1 < NVar1) {
    NVar1 = BCryptHashData(local_18[0],param_4,param_5,0);
    if (-1 < NVar1) {
      NVar1 = BCryptFinishHash(local_18[0],param_6,param_7,0);
    }
  }
  if (local_18[0] != (BCRYPT_HASH_HANDLE)0x0) {
    BCryptDestroyHash(local_18[0]);
  }
  return NVar1;
}



===== BCryptDuplicateHash @ 180002f80 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

NTSTATUS __stdcall
BCryptDuplicateHash(BCRYPT_HASH_HANDLE hHash,BCRYPT_HASH_HANDLE *phNewHash,PUCHAR pbHashObject,
                   ULONG cbHashObject,ULONG dwFlags)

{
  uint uVar1;
  BCRYPT_HANDLE hObject;
  int iVar2;
  undefined1 uVar3;
  uint uVar4;
  PUCHAR pUVar5;
  BCRYPT_HASH_HANDLE *ppvVar6;
  int iVar7;
  ulonglong uVar8;
  undefined1 uVar9;
  ulonglong uVar10;
  PUCHAR pUVar11;
  ulonglong uVar12;
  undefined4 *puVar13;
  uint local_res8 [2];
  ULONG local_38 [4];
  
                    /* 0x2f80  18  BCryptDuplicateHash */
  pUVar11 = (PUCHAR)0x0;
  ppvVar6 = phNewHash;
  pUVar5 = pbHashObject;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    ppvVar6 = (BCRYPT_HASH_HANDLE *)0x25;
    WPP_SF_qqqdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x25,pbHashObject,hHash,(char)phNewHash,
                 (char)pbHashObject,(char)cbHashObject,(char)dwFlags);
  }
  if (((hHash == (BCRYPT_HASH_HANDLE)0x0) || (*(uint *)hHash < 0x28)) ||
     (*(int *)((longlong)hHash + 4) != 0x55555553)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),ppvVar6,pUVar5,"Status",8,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",0x46);
    }
    return -0x3ffffff8;
  }
  hObject = *(BCRYPT_HANDLE *)((longlong)hHash + 8);
  if (pbHashObject == (PUCHAR)0x0) {
    if (cbHashObject == 0) {
      local_res8[0] = 0;
      local_38[0] = 0;
      iVar2 = BCryptGetProperty(hObject,L"ObjectLength",(PUCHAR)local_res8,4,local_38,0);
      if (iVar2 < 0) {
        DebugTraceError((char)iVar2,"Status",
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",0xe2);
        goto LAB_18000308d;
      }
      pbHashObject = (PUCHAR)BCryptAlloc((ulonglong)local_res8[0]);
      if (pbHashObject == (PUCHAR)0x0) {
        DebugTraceError(0x17,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",0xea
                       );
        iVar2 = -0x3fffffe9;
        goto LAB_18000308d;
      }
      pUVar11 = pbHashObject;
      cbHashObject = local_res8[0];
      goto LAB_180002fff;
    }
LAB_18000319f:
    iVar2 = -0x3ffffff3;
    uVar9 = 0x65;
    uVar3 = 0xd;
LAB_1800031af:
    DebugTraceError(uVar3,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar9);
  }
  else {
LAB_180002fff:
    if (phNewHash == (BCRYPT_HASH_HANDLE *)0x0) goto LAB_18000319f;
    if (cbHashObject < 0x46) {
      iVar2 = -0x3fffffdd;
      uVar9 = 0x6c;
      uVar3 = 0x23;
      goto LAB_1800031af;
    }
    puVar13 = (undefined4 *)((ulonglong)(pbHashObject + 0xf) & 0xfffffffffffffff0);
    uVar4 = ((uint)(pbHashObject + 0xf) & 0xfffffff0) - (int)pbHashObject;
    *puVar13 = 0x28;
    pUVar5 = pbHashObject + (ulonglong)uVar4 + 0x28;
    puVar13[1] = 0x55555553;
    uVar4 = cbHashObject + (-0x28 - uVar4);
    *(BCRYPT_HANDLE *)(puVar13 + 2) = hObject;
    *(PUCHAR *)(puVar13 + 8) = pUVar11;
    if ((*(byte *)((longlong)hObject + 8) & 8) == 0) {
      uVar12 = (ulonglong)(pUVar5 + 0xf) & 0xfffffffffffffff0;
      iVar7 = uVar4 + ((int)pUVar5 - (int)uVar12);
LAB_18000305e:
      iVar2 = (**(code **)((longlong)hObject + 0x70))
                        (*(undefined8 *)((longlong)hHash + 0x10),puVar13 + 4,uVar12,iVar7,dwFlags);
      if (iVar2 == 0) {
        *phNewHash = puVar13;
        goto LAB_18000308d;
      }
      uVar9 = 0xb6;
      uVar3 = (undefined1)iVar2;
      goto LAB_1800031af;
    }
    uVar1 = *(uint *)((longlong)hObject + 0xc);
    if (uVar1 + 0xf <= uVar4) {
      pUVar5 = pUVar5 + uVar1;
      uVar8 = (ulonglong)(pUVar5 + 0xf) & 0xfffffffffffffff0;
      uVar10 = (ulonglong)(((uVar4 - uVar1 >> 1) - (int)uVar8) + (int)pUVar5);
      uVar12 = uVar8 + 0xf + uVar10 & 0xfffffffffffffff0;
      iVar7 = (uVar4 - uVar1) + (((uint)(pUVar5 + 0xf) & 0xfffffff0) - (int)uVar12);
      iVar2 = (**(code **)((longlong)hObject + 0x70))
                        (*(undefined8 *)((longlong)hHash + 0x18),puVar13 + 6,uVar8,uVar10,dwFlags);
      if (iVar2 != 0) {
        uVar9 = 0xa1;
        uVar3 = (undefined1)iVar2;
        goto LAB_1800031af;
      }
      goto LAB_18000305e;
    }
    iVar2 = -0x3fffffdd;
  }
  if (pUVar11 != (PUCHAR)0x0) {
    SafeAllocaFreeToHeap(pUVar11);
  }
LAB_18000308d:
  if ((hObject != (BCRYPT_HANDLE)0x0) && (-1 < iVar2)) {
    LOCK();
    *(int *)((longlong)hObject + 0x10) = *(int *)((longlong)hObject + 0x10) + 1;
    UNLOCK();
  }
  return iVar2;
}



===== BCryptAlloc @ 1800032d0 =====

void BCryptAlloc(undefined8 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0001800032e2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,param_1);
  return;
}



===== BCryptEncrypt @ 180003300 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

NTSTATUS __stdcall
BCryptEncrypt(BCRYPT_KEY_HANDLE hKey,PUCHAR pbInput,ULONG cbInput,void *pPaddingInfo,PUCHAR pbIV,
             ULONG cbIV,PUCHAR pbOutput,ULONG cbOutput,ULONG *pcbResult,ULONG dwFlags)

{
  undefined4 *puVar1;
  longlong lVar2;
  bool bVar3;
  undefined8 uVar4;
  undefined4 *puVar5;
  undefined1 uVar6;
  uint uVar7;
  PUCHAR pUVar8;
  undefined8 *puVar9;
  int iVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  ULONG UVar14;
  undefined4 in_register_00000084;
  ulonglong uVar15;
  undefined1 uVar16;
  code *pcVar17;
  undefined1 auStackY_b8 [32];
  ULONG local_58;
  uint local_54;
  PUCHAR local_50;
  undefined8 *local_48;
  ULONG local_40 [2];
  ulonglong local_38;
  
                    /* 0x3300  21  BCryptEncrypt */
  uVar15 = CONCAT44(in_register_00000084,cbInput);
  local_38 = __security_cookie ^ (ulonglong)&local_58;
  local_58 = cbInput;
  local_54 = 0;
  local_40[0] = 0;
  local_50 = pbInput;
  pUVar8 = pbInput;
  local_48 = pPaddingInfo;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    pUVar8 = (PUCHAR)0x17;
    WPP_SF_qqqdqdqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x17,uVar15,hKey,(char)pPaddingInfo,
                    (char)pbInput,(char)cbInput,(char)pbOutput,(char)cbOutput,(char)pcbResult,
                    (char)dwFlags);
    uVar15 = (ulonglong)local_58;
  }
  puVar12 = auStackY_b8;
  puVar13 = auStackY_b8;
  puVar11 = auStackY_b8;
  bVar3 = false;
  if (pcbResult == (ULONG *)0x0) {
    iVar10 = -0x3ffffff3;
    puVar12 = auStackY_b8;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       (puVar12 = auStackY_b8, (WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_1800033be;
    uVar16 = 0x49;
    uVar6 = 0xd;
LAB_180003562:
    WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pUVar8,
                "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c","Status",uVar6,
                "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar16);
    puVar12 = auStackY_b8;
    goto LAB_1800033be;
  }
  if (((hKey == (BCRYPT_KEY_HANDLE)0x0) || (*(uint *)hKey < 0x20)) ||
     (*(int *)((longlong)hKey + 4) != 0x55555552)) {
    iVar10 = -0x3ffffff8;
    uVar16 = 0x51;
    uVar6 = 8;
    puVar11 = auStackY_b8;
LAB_1800033ab:
    *(undefined8 *)(puVar11 + -8) = 0x1800033be;
    DebugTraceError(uVar6,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar16)
    ;
    puVar12 = puVar11;
  }
  else {
    lVar2 = *(longlong *)((longlong)hKey + 8);
    uVar7 = *(int *)(lVar2 + 0x24) - 1;
    pUVar8 = (PUCHAR)(ulonglong)uVar7;
    if (uVar7 == 0) {
      pcVar17 = *(code **)(lVar2 + 0x60);
LAB_1800034a5:
      iVar10 = (*pcVar17)(*(undefined8 *)((longlong)hKey + 0x10),local_50,uVar15,pPaddingInfo);
      puVar13 = auStackY_b8;
      puVar5 = (undefined4 *)0x0;
      if (iVar10 < 0) {
        uVar16 = 0xdd;
        uVar6 = (undefined1)iVar10;
        puVar11 = auStackY_b8;
        goto LAB_1800033ab;
      }
LAB_1800034f7:
      iVar10 = 0;
      puVar12 = puVar13;
      if (puVar5 == (undefined4 *)0x0) goto LAB_1800033be;
    }
    else {
      if (uVar7 != 2) {
        iVar10 = -0x3fffff45;
        puVar12 = auStackY_b8;
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           (puVar12 = auStackY_b8, (WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_1800033be;
        uVar16 = 0x88;
        uVar6 = 0xbb;
        goto LAB_180003562;
      }
      uVar7 = *(uint *)(lVar2 + 0x1b8);
      pcVar17 = *(code **)(lVar2 + 0x68);
      if ((((uVar7 & 1) != 0) && (dwFlags != 0)) &&
         (((dwFlags & 1) == 0 &&
          (((uVar7 & dwFlags & 2) == 0 && ((dwFlags & 4) == 0 || (uVar7 & 8) == 0)))))) {
        bVar3 = true;
        iVar10 = BCryptGetProperty(hKey,L"KeyStrength",(PUCHAR)&local_54,4,local_40,0);
        if (iVar10 < 0) {
          uVar16 = 0x7f;
          uVar6 = (undefined1)iVar10;
          goto LAB_1800033ab;
        }
        uVar15 = (ulonglong)local_58;
        local_54 = local_54 + 7 >> 3;
        pPaddingInfo = local_48;
      }
      puVar5 = (undefined4 *)0x0;
      if (!bVar3) goto LAB_1800034a5;
      if (pbOutput == (PUCHAR)0x0) {
        iVar10 = (*pcVar17)(*(undefined8 *)((longlong)hKey + 0x10),local_50,uVar15,0);
        puVar5 = (undefined4 *)0x0;
        if (iVar10 < 0) {
          uVar16 = 0x9d;
          uVar6 = (undefined1)iVar10;
          puVar11 = auStackY_b8;
          goto LAB_1800033ab;
        }
        goto LAB_1800034f7;
      }
      local_48 = (undefined8 *)(ulonglong)local_54;
      puVar13 = auStackY_b8;
      pUVar8 = local_50;
      if ((local_48 == (undefined8 *)0x0) ||
         (puVar13 = auStackY_b8, g_ulMaxStackAllocSize < local_48)) {
LAB_1800036fc:
        puVar9 = local_48 + 1;
        UVar14 = (uint)uVar15;
        if (local_48 <= puVar9) {
          *(undefined8 *)(puVar13 + -8) = 0x180003714;
          puVar5 = (undefined4 *)(*g_pfnAllocate)(puVar9);
          pUVar8 = local_50;
          UVar14 = local_58;
          if (puVar5 != (undefined4 *)0x0) {
            *puVar5 = 0x70616548;
            puVar5 = puVar5 + 2;
          }
        }
      }
      else {
        puVar9 = (undefined8 *)(g_ulAdditionalProbeSize + 8 + (longlong)local_48);
        puVar13 = auStackY_b8;
        if (puVar9 < local_48) goto LAB_1800036fc;
        uVar4 = VerifyStackAvailable((ulonglong)puVar9);
        pUVar8 = local_50;
        UVar14 = local_58;
        if ((int)uVar4 == 0) {
LAB_1800036f8:
          uVar15 = (ulonglong)UVar14;
          puVar13 = puVar12;
          goto LAB_1800036fc;
        }
        puVar9 = (undefined8 *)((longlong)local_48 + 0x17);
        if (puVar9 <= local_48 + 1) {
          puVar9 = (undefined8 *)0xffffffffffffff0;
        }
        lVar2 = -((ulonglong)puVar9 & 0xfffffffffffffff0);
        puVar13 = auStackY_b8 + lVar2;
        puVar1 = (undefined4 *)((longlong)local_40 + lVar2 + -0x18);
        puVar5 = (undefined4 *)0x0;
        puVar12 = auStackY_b8 + lVar2;
        if (puVar1 == (undefined4 *)0x0) goto LAB_1800036f8;
        *puVar1 = 0x6b637453;
        puVar5 = (undefined4 *)((longlong)local_40 + lVar2 + -0x10);
        puVar12 = auStackY_b8 + lVar2;
        if (puVar5 == (undefined4 *)0x0) goto LAB_1800036f8;
      }
      if (puVar5 == (undefined4 *)0x0) {
        iVar10 = -0x3fffffe9;
        uVar16 = 0xad;
        uVar6 = 0x17;
        puVar11 = puVar13;
        goto LAB_1800033ab;
      }
      *(uint *)(puVar13 + 0x28) = local_54;
      *(undefined4 **)(puVar13 + 0x20) = puVar5;
      *(undefined8 *)(puVar13 + -8) = 0x180003765;
      iVar10 = ApplyEncryptionPadding
                         ((ulonglong)dwFlags,pPaddingInfo,pUVar8,UVar14,*(byte **)(puVar13 + 0x20),
                          *(uint *)(puVar13 + 0x28));
      if (iVar10 < 0) {
        uVar6 = 0xba;
      }
      else {
        *(undefined4 *)(puVar13 + 0x48) = 0;
        *(ULONG **)(puVar13 + 0x40) = pcbResult;
        *(ULONG *)(puVar13 + 0x38) = cbOutput;
        uVar4 = *(undefined8 *)((longlong)hKey + 0x10);
        *(PUCHAR *)(puVar13 + 0x30) = pbOutput;
        *(ULONG *)(puVar13 + 0x28) = cbIV;
        *(PUCHAR *)(puVar13 + 0x20) = pbIV;
        *(undefined8 *)(puVar13 + -8) = 0x1800037da;
        iVar10 = (*pcVar17)(uVar4,puVar5,cbOutput,0);
        if (-1 < iVar10) goto LAB_1800034f7;
        uVar6 = 0xca;
      }
      *(undefined8 *)(puVar13 + -8) = 0x18000378e;
      DebugTraceError((char)iVar10,"Status",
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar6);
    }
    puVar12 = puVar13;
    if (puVar5[-2] == 0x70616548) {
      *(undefined8 *)(puVar13 + -8) = 0x18000351f;
      (*g_pfnFree)(puVar5 + -2);
    }
  }
LAB_1800033be:
  *(undefined8 *)(puVar12 + -8) = 0x1800033cc;
  return iVar10;
}



===== GetPBKDF2Block @ 180003800 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

NTSTATUS GetPBKDF2Block(BCRYPT_ALG_HANDLE param_1,PUCHAR param_2,ULONG param_3,PUCHAR param_4,
                       uint param_5,ulonglong param_6,undefined4 param_7,PUCHAR param_8,
                       ULONG param_9,PUCHAR param_10,PUCHAR param_11,ULONG param_12)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  longlong lVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  NTSTATUS NVar11;
  uint uVar12;
  undefined1 uVar13;
  uint uVar14;
  PUCHAR pUVar15;
  ulonglong uVar16;
  byte *pbVar17;
  undefined1 uVar18;
  uint uVar19;
  UCHAR local_58;
  undefined1 local_57;
  undefined1 local_56;
  undefined1 local_55;
  uint *local_50;
  ulonglong local_48;
  
  local_50 = (uint *)0x0;
  NVar11 = BCryptCreateHash(param_1,&local_50,param_8,param_9,param_2,param_3,0);
  if (NVar11 < 0) {
    DebugTraceError((char)NVar11,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",
                    0xe6);
    goto LAB_180003aa7;
  }
  uVar16 = (ulonglong)param_5;
  NVar11 = BCryptHashData(local_50,param_4,param_5,0);
  if (NVar11 < 0) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180003aa7;
    uVar13 = 0xf0;
  }
  else {
    param_4 = &local_58;
    local_55 = (undefined1)param_7;
    local_58 = (UCHAR)((uint)param_7 >> 0x18);
    local_57 = (undefined1)((uint)param_7 >> 0x10);
    uVar16 = 4;
    local_56 = (undefined1)((uint)param_7 >> 8);
    NVar11 = BCryptHashData(local_50,param_4,4,0);
    if (-1 < NVar11) {
      NVar11 = BCryptFinishHash(local_50,param_10,param_12,0);
      if (NVar11 < 0) {
        DebugTraceError((char)NVar11,"Status",
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",9);
      }
      else {
        memcpy(param_11,param_10,(ulonglong)param_12);
        for (local_48 = 1; local_48 < param_6; local_48 = local_48 + 1) {
          BCryptDestroyHash(local_50);
          local_50 = (uint *)0x0;
          pUVar15 = param_8;
          NVar11 = BCryptCreateHash(param_1,&local_50,param_8,param_9,param_2,param_3,0);
          puVar2 = local_50;
          if (NVar11 < 0) {
            DebugTraceError((char)NVar11,"Status",
                            "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",0x1e);
            goto LAB_180003aa7;
          }
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
            WPP_SF_qqdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x22,pUVar15,local_50,
                        (char)param_10,(char)param_12,0);
          }
          if (((puVar2 == (uint *)0x0) || (*puVar2 < 0x28)) || (puVar2[1] != 0x55555553)) {
            NVar11 = -0x3ffffff8;
            DebugTraceError(8,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",
                            0xd2);
LAB_1800039ed:
            DebugTraceError((char)NVar11,"Status",
                            "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",0x28);
            goto LAB_180003aa7;
          }
          uVar16 = (ulonglong)param_12;
          NVar11 = (**(code **)(*(longlong *)(puVar2 + 2) + 0x60))
                             (*(undefined8 *)(puVar2 + 4),param_10,uVar16,0);
          puVar2 = local_50;
          if (NVar11 < 0) goto LAB_1800039ed;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
            WPP_SF_qqdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x23,uVar16,local_50,
                        (char)param_10,(char)param_12,0);
          }
          if (((puVar2 == (uint *)0x0) || (*puVar2 < 0x28)) || (puVar2[1] != 0x55555553)) {
            uVar18 = 0xf4;
            NVar11 = -0x3ffffff8;
            uVar13 = 8;
            goto LAB_180003a6f;
          }
          lVar5 = *(longlong *)(puVar2 + 2);
          uVar16 = (ulonglong)param_12;
          pUVar15 = param_10;
          NVar11 = (**(code **)(lVar5 + 0x68))(*(undefined8 *)(puVar2 + 4),param_10,uVar16,0);
          if (NVar11 < 0) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
              WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pUVar15,uVar16,"Status",
                          (char)NVar11,"onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",
                          0xfe);
            }
LAB_180003a7e:
            DebugTraceError((char)NVar11,"Status",
                            "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",0x32);
            goto LAB_180003aa7;
          }
          if ((*(byte *)(lVar5 + 8) & 8) != 0) {
            NVar11 = (**(code **)(lVar5 + 0x60))(*(undefined8 *)(puVar2 + 6),param_10,param_12,0);
            if (NVar11 < 0) {
              uVar18 = 10;
              uVar13 = (undefined1)NVar11;
            }
            else {
              NVar11 = (**(code **)(lVar5 + 0x68))(*(undefined8 *)(puVar2 + 6),param_10,param_12,0);
              if (-1 < NVar11) goto LAB_180003b81;
              uVar18 = 0x13;
              uVar13 = (undefined1)NVar11;
            }
LAB_180003a6f:
            DebugTraceError(uVar13,"Status",
                            "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar18);
            goto LAB_180003a7e;
          }
LAB_180003b81:
          uVar16 = 0;
          uVar14 = 0;
          if (param_12 != 0) {
            if ((7 < param_12) &&
               ((param_10 + (param_12 - 1) < param_11 || (param_11 + (param_12 - 1) < param_10)))) {
              if (param_12 < 0x40) {
LAB_180003c39:
                do {
                  *(ulonglong *)(param_11 + uVar16) =
                       CONCAT44((uint)((ulonglong)*(undefined8 *)(param_10 + uVar16) >> 0x20) ^
                                (uint)((ulonglong)*(undefined8 *)(param_11 + uVar16) >> 0x20),
                                (uint)*(undefined8 *)(param_10 + uVar16) ^
                                (uint)*(undefined8 *)(param_11 + uVar16));
                  uVar14 = (int)uVar16 + 8;
                  uVar16 = (ulonglong)uVar14;
                } while (uVar14 < (param_12 & 0xfffffff8));
              }
              else {
                uVar19 = 0x20;
                do {
                  puVar2 = (uint *)(param_11 + uVar16);
                  uVar14 = puVar2[1];
                  uVar1 = puVar2[2];
                  uVar6 = puVar2[3];
                  uVar12 = uVar19 - 0x10;
                  puVar3 = (uint *)(param_10 + uVar16);
                  uVar7 = puVar3[1];
                  uVar8 = puVar3[2];
                  uVar9 = puVar3[3];
                  puVar4 = (uint *)(param_11 + uVar16);
                  *puVar4 = *puVar3 ^ *puVar2;
                  puVar4[1] = uVar7 ^ uVar14;
                  puVar4[2] = uVar8 ^ uVar1;
                  puVar4[3] = uVar9 ^ uVar6;
                  uVar14 = (int)uVar16 + 0x40;
                  uVar16 = (ulonglong)uVar14;
                  puVar2 = (uint *)(param_11 + uVar12);
                  uVar1 = puVar2[1];
                  uVar6 = puVar2[2];
                  uVar7 = puVar2[3];
                  puVar3 = (uint *)(param_10 + uVar12);
                  uVar8 = puVar3[1];
                  uVar9 = puVar3[2];
                  uVar10 = puVar3[3];
                  puVar4 = (uint *)(param_11 + uVar12);
                  *puVar4 = *puVar3 ^ *puVar2;
                  puVar4[1] = uVar8 ^ uVar1;
                  puVar4[2] = uVar9 ^ uVar6;
                  puVar4[3] = uVar10 ^ uVar7;
                  puVar2 = (uint *)(param_11 + uVar19);
                  uVar1 = puVar2[1];
                  uVar6 = puVar2[2];
                  uVar7 = puVar2[3];
                  puVar3 = (uint *)(param_10 + uVar19);
                  uVar8 = puVar3[1];
                  uVar9 = puVar3[2];
                  uVar10 = puVar3[3];
                  puVar4 = (uint *)(param_11 + uVar19);
                  *puVar4 = *puVar3 ^ *puVar2;
                  puVar4[1] = uVar8 ^ uVar1;
                  puVar4[2] = uVar9 ^ uVar6;
                  puVar4[3] = uVar10 ^ uVar7;
                  uVar1 = uVar19 + 0x10;
                  uVar19 = uVar19 + 0x40;
                  puVar2 = (uint *)(param_11 + uVar1);
                  uVar6 = puVar2[1];
                  uVar7 = puVar2[2];
                  uVar8 = puVar2[3];
                  puVar3 = (uint *)(param_10 + uVar1);
                  uVar9 = puVar3[1];
                  uVar10 = puVar3[2];
                  uVar12 = puVar3[3];
                  puVar4 = (uint *)(param_11 + uVar1);
                  *puVar4 = *puVar3 ^ *puVar2;
                  puVar4[1] = uVar9 ^ uVar6;
                  puVar4[2] = uVar10 ^ uVar7;
                  puVar4[3] = uVar12 ^ uVar8;
                } while (uVar14 < param_12 - (param_12 & 0x3f));
                if (7 < (param_12 & 0x3f)) goto LAB_180003c39;
              }
              if (param_12 <= uVar14) goto LAB_180003c82;
            }
            pbVar17 = param_11 + uVar14;
            uVar16 = (ulonglong)(param_12 - uVar14);
            do {
              *pbVar17 = *pbVar17 ^ pbVar17[(longlong)param_10 - (longlong)param_11];
              pbVar17 = pbVar17 + 1;
              uVar16 = uVar16 - 1;
            } while (uVar16 != 0);
          }
LAB_180003c82:
        }
        NVar11 = 0;
      }
      goto LAB_180003aa7;
    }
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180003aa7;
    uVar13 = 0xff;
  }
  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_4,uVar16,"Status",(char)NVar11,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar13);
LAB_180003aa7:
  if (local_50 != (uint *)0x0) {
    BCryptDestroyHash(local_50);
  }
  return NVar11;
}



===== BCryptCloseAlgorithmProvider @ 180003e00 =====

NTSTATUS __stdcall BCryptCloseAlgorithmProvider(BCRYPT_ALG_HANDLE hAlgorithm,ULONG dwFlags)

{
  uint *puVar1;
  uint uVar2;
  NTSTATUS NVar3;
  uint *puVar4;
  undefined4 in_register_00000014;
  undefined8 uVar5;
  undefined8 in_R8;
  
                    /* 0x3e00  3  BCryptCloseAlgorithmProvider */
  uVar5 = CONCAT44(in_register_00000014,dwFlags);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    uVar5 = 0xe;
    WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xe,in_R8,hAlgorithm,(char)dwFlags);
  }
  puVar4 = ValidateBaseAlgHandle(hAlgorithm);
  if ((puVar4 == (uint *)0x0) || ((int)puVar4[2] < 0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",in_R8,"Status",8,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",0x8f);
    }
    NVar3 = -0x3ffffff8;
  }
  else {
    LOCK();
    puVar1 = puVar4 + 4;
    uVar2 = *puVar1;
    *puVar1 = *puVar1 - 1;
    UNLOCK();
    if (uVar2 == 1) {
      DestroyAlgorithmHeader(puVar4,uVar5,in_R8);
    }
    NVar3 = 0;
  }
  return NVar3;
}



===== BCryptGenerateSymmetricKey @ 180003ed0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

NTSTATUS __stdcall
BCryptGenerateSymmetricKey
          (BCRYPT_ALG_HANDLE hAlgorithm,BCRYPT_KEY_HANDLE *phKey,PUCHAR pbKeyObject,
          ULONG cbKeyObject,PUCHAR pbSecret,ULONG cbSecret,ULONG dwFlags)

{
  NTSTATUS NVar1;
  uint *puVar2;
  undefined1 uVar3;
  char *pcVar4;
  undefined4 *puVar5;
  char *pcVar6;
  undefined1 uVar7;
  PUCHAR pUVar8;
  uint local_38;
  ULONG local_34 [3];
  
                    /* 0x3ed0  34  BCryptGenerateSymmetricKey */
  pUVar8 = (PUCHAR)0x0;
  pcVar4 = (char *)phKey;
  pcVar6 = (char *)pbKeyObject;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    pcVar4 = (char *)0x14;
    WPP_SF_qqqdqdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x14,pbKeyObject,hAlgorithm,
                   (char)phKey,(char)pbKeyObject,(char)cbKeyObject,(char)pbSecret,(char)cbSecret,
                   (char)dwFlags);
  }
  puVar2 = ValidateBaseAlgHandle(hAlgorithm);
  if (puVar2 == (uint *)0x0) {
    DebugTraceError(8,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",7);
    return -0x3ffffff8;
  }
  if (pbKeyObject == (PUCHAR)0x0) {
    if (cbKeyObject != 0) goto LAB_1800040aa;
    local_38 = 0;
    local_34[0] = 0;
    NVar1 = BCryptGetProperty(hAlgorithm,L"ObjectLength",(PUCHAR)&local_38,4,local_34,0);
    if (NVar1 < 0) {
      uVar3 = (undefined1)NVar1;
      uVar7 = 0xe2;
    }
    else {
      pcVar4 = (char *)0x0;
      pcVar6 = (char *)(ulonglong)local_38;
      pbKeyObject = (PUCHAR)RtlAllocateHeap(*(undefined8 *)
                                             ((longlong)ProcessEnvironmentBlock + 0x30));
      if (pbKeyObject != (PUCHAR)0x0) {
        pUVar8 = pbKeyObject;
        cbKeyObject = local_38;
        goto LAB_180003fb0;
      }
      NVar1 = -0x3fffffe9;
      uVar3 = 0x17;
      uVar7 = 0xea;
    }
    pcVar6 = "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c";
    pcVar4 = "Status";
    DebugTraceError(uVar3,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar7);
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return NVar1;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) goto LAB_18000412b;
    uVar7 = 0x15;
    uVar3 = (undefined1)NVar1;
LAB_1800040e4:
    WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pcVar4,pcVar6,"Status",uVar3,
                "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar7);
  }
  else {
LAB_180003fb0:
    if ((phKey == (BCRYPT_KEY_HANDLE *)0x0) || (pbSecret == (PUCHAR)0x0)) {
LAB_1800040aa:
      NVar1 = -0x3ffffff3;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        uVar7 = 0x26;
        uVar3 = 0xd;
        NVar1 = -0x3ffffff3;
        goto LAB_1800040e4;
      }
    }
    else if (cbKeyObject < 0x3e) {
      NVar1 = -0x3fffffdd;
    }
    else {
      puVar5 = (undefined4 *)((ulonglong)(pbKeyObject + 0xf) & 0xfffffffffffffff0);
      *puVar5 = 0x20;
      puVar5[1] = 0x55555552;
      *(uint **)(puVar5 + 2) = puVar2;
      *(PUCHAR *)(puVar5 + 6) = pUVar8;
      if ((puVar2[9] == 1) || (puVar2[9] == 7)) {
        NVar1 = (**(code **)(puVar2 + 0x16))
                          (*(undefined8 *)(puVar2 + 6),puVar5 + 4,puVar5 + 8,
                           ((int)pbKeyObject - (int)(puVar5 + 8)) + cbKeyObject,pbSecret,cbSecret,
                           dwFlags);
        if (-1 < NVar1) {
          *phKey = puVar5;
          NVar1 = 0;
          goto LAB_180004039;
        }
        DebugTraceError((char)NVar1,"Status",
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",0x5a);
      }
      else {
        NVar1 = -0x3fffff45;
        DebugTraceError(0xbb,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",0x4b
                       );
      }
    }
  }
LAB_18000412b:
  if (pUVar8 != (PUCHAR)0x0) {
    SafeAllocaFreeToHeap(pUVar8);
  }
  if (NVar1 < 0) {
    return NVar1;
  }
LAB_180004039:
  LOCK();
  puVar2[4] = puVar2[4] + 1;
  UNLOCK();
  return NVar1;
}



===== BCryptCreateHash @ 180004210 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

NTSTATUS __stdcall
BCryptCreateHash(BCRYPT_ALG_HANDLE hAlgorithm,BCRYPT_HASH_HANDLE *phHash,PUCHAR pbHashObject,
                ULONG cbHashObject,PUCHAR pbSecret,ULONG cbSecret,ULONG dwFlags)

{
  uint uVar1;
  code *pcVar2;
  NTSTATUS NVar3;
  uint *puVar4;
  undefined1 uVar5;
  uint uVar6;
  ulonglong uVar7;
  char *pcVar8;
  BCRYPT_HASH_HANDLE *ppvVar9;
  longlong lVar10;
  PUCHAR pUVar11;
  char *pcVar12;
  ulonglong uVar13;
  undefined1 uVar14;
  PUCHAR pUVar15;
  undefined4 *puVar16;
  uint uVar17;
  PUCHAR pUVar18;
  undefined8 in_stack_ffffffffffffff60;
  uint local_78;
  uint local_74;
  PUCHAR local_70;
  ULONG local_68 [2];
  code *local_60;
  code *local_58;
  code *local_50;
  code *local_48;
  code *local_40;
  ulonglong local_38;
  
                    /* 0x4210  7  BCryptCreateHash */
  uVar17 = (uint)((ulonglong)in_stack_ffffffffffffff60 >> 0x20);
  pUVar15 = (PUCHAR)0x0;
  ppvVar9 = phHash;
  pUVar18 = pbHashObject;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    ppvVar9 = (BCRYPT_HASH_HANDLE *)0x21;
    pUVar18 = (PUCHAR)(ulonglong)cbSecret;
    pUVar11 = pbHashObject;
    WPP_SF_qqqdqdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x21,pUVar18,hAlgorithm,(char)phHash,
                   (char)pbHashObject,(char)cbHashObject,(char)pbSecret,(char)cbSecret,(char)dwFlags
                  );
    uVar17 = (uint)((ulonglong)pUVar11 >> 0x20);
  }
  puVar4 = ValidateBaseAlgHandle(hAlgorithm);
  if (puVar4 == (uint *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),ppvVar9,pUVar18,"Status",8,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",0x87);
    }
    return -0x3ffffff8;
  }
  if (pbHashObject == (PUCHAR)0x0) {
    if (cbHashObject != 0) goto LAB_180004447;
    local_74 = 0;
    local_68[0] = 0;
    NVar3 = BCryptGetProperty(hAlgorithm,L"ObjectLength",(PUCHAR)&local_74,4,local_68,0);
    if (NVar3 < 0) {
      uVar5 = (undefined1)NVar3;
      uVar14 = 0xe2;
    }
    else {
      pbHashObject = (PUCHAR)RtlAllocateHeap(*(undefined8 *)
                                              ((longlong)ProcessEnvironmentBlock + 0x30),0,local_74)
      ;
      if (pbHashObject != (PUCHAR)0x0) {
        pUVar15 = pbHashObject;
        cbHashObject = local_74;
        goto LAB_18000427b;
      }
      NVar3 = -0x3fffffe9;
      uVar5 = 0x17;
      uVar14 = 0xea;
    }
    pcVar12 = "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c";
    pcVar8 = "Status";
    DebugTraceError(uVar5,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar14)
    ;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return NVar3;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) != 0) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pcVar8,pcVar12,"Status",(char)NVar3,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",0x93);
    }
  }
  else {
LAB_18000427b:
    if (phHash == (BCRYPT_HASH_HANDLE *)0x0) {
LAB_180004447:
      uVar5 = 0xa3;
LAB_18000444d:
      NVar3 = -0x3ffffff3;
      uVar14 = 0xd;
    }
    else if (cbHashObject < 0x46) {
      NVar3 = -0x3fffffdd;
      uVar5 = 0xaa;
      uVar14 = 0x23;
    }
    else {
      puVar16 = (undefined4 *)((ulonglong)(pbHashObject + 0xf) & 0xfffffffffffffff0);
      uVar6 = ((uint)(pbHashObject + 0xf) & 0xfffffff0) - (int)pbHashObject;
      if (puVar4[9] == 2) {
        local_58 = *(code **)(puVar4 + 0x16);
        *puVar16 = 0x28;
        pUVar18 = pbHashObject + (ulonglong)uVar6 + 0x28;
        puVar16[1] = 0x55555553;
        uVar6 = cbHashObject + (-0x28 - uVar6);
        *(uint **)(puVar16 + 2) = puVar4;
        *(PUCHAR *)(puVar16 + 8) = pUVar15;
        if ((puVar4[2] & 8) == 0) {
          NVar3 = (*local_58)(*(undefined8 *)(puVar4 + 6),puVar16 + 4,
                              (ulonglong)(pUVar18 + 0xf) & 0xfffffffffffffff0,
                              ((int)pUVar18 - (int)((ulonglong)(pUVar18 + 0xf) & 0xfffffffffffffff0)
                              ) + uVar6,pbSecret,CONCAT44(uVar17,cbSecret),dwFlags);
          if (-1 < NVar3) {
LAB_18000432d:
            *phHash = puVar16;
            NVar3 = 0;
            goto LAB_180004333;
          }
          uVar5 = 0xa3;
          uVar14 = (undefined1)NVar3;
        }
        else {
          local_60 = *(code **)(puVar4 + 0x18);
          local_48 = *(code **)(puVar4 + 0x1a);
          local_40 = *(code **)(puVar4 + 0x1e);
          local_50 = *(code **)(puVar4 + 0x10);
          uVar1 = puVar4[3];
          local_78 = 0;
          local_68[1] = 0;
          if (uVar6 <= uVar1) {
            uVar5 = 0xf3;
            goto LAB_18000444d;
          }
          uVar6 = uVar6 - uVar1 >> 1;
          uVar7 = (ulonglong)uVar17 << 0x20;
          local_38 = (ulonglong)(pUVar18 + uVar1 + 0xf) & 0xfffffffffffffff0;
          uVar17 = ((int)(pUVar18 + uVar1) - (int)local_38) + uVar6;
          lVar10 = uVar17 + local_38;
          local_70 = pUVar18;
          NVar3 = (*local_58)(*(undefined8 *)(puVar4 + 6),puVar16 + 4,local_38,uVar17,0,uVar7,0);
          pcVar2 = local_58;
          if (NVar3 < 0) {
            uVar5 = 0xe;
            uVar14 = (undefined1)NVar3;
          }
          else {
            uVar13 = lVar10 + 0xfU & 0xfffffffffffffff0;
            uVar7 = uVar7 & 0xffffffff00000000;
            NVar3 = (*local_58)(*(undefined8 *)(puVar4 + 6),puVar16 + 6,uVar13,
                                ((int)lVar10 - (int)uVar13) + uVar6,0,uVar7,0);
            pUVar18 = local_70;
            if (NVar3 < 0) {
              uVar5 = 0x1e;
              uVar14 = (undefined1)NVar3;
            }
            else {
              if (cbSecret <= puVar4[3]) {
                memcpy(local_70,pbSecret,(ulonglong)cbSecret);
                pUVar11 = pUVar18 + cbSecret;
                for (uVar7 = (ulonglong)(puVar4[3] - cbSecret); uVar7 != 0; uVar7 = uVar7 - 1) {
                  *pUVar11 = '\0';
                  pUVar11 = pUVar11 + 1;
                }
LAB_1800047d6:
                pcVar2 = local_60;
                uVar7 = 0;
                uVar17 = 0;
                if (puVar4[3] != 0) {
                  do {
                    pUVar18[uVar7] = pUVar18[uVar7] ^ 0x36;
                    uVar6 = (int)uVar7 + 1;
                    uVar7 = (ulonglong)uVar6;
                    uVar17 = puVar4[3];
                  } while (uVar6 < uVar17);
                }
                NVar3 = (*local_60)(*(undefined8 *)(puVar16 + 4),pUVar18,uVar17,0);
                if (NVar3 < 0) {
                  uVar5 = 0x7b;
                }
                else {
                  uVar7 = 0;
                  uVar17 = 0;
                  if (puVar4[3] != 0) {
                    do {
                      pUVar18[uVar7] = pUVar18[uVar7] ^ 0x6a;
                      uVar6 = (int)uVar7 + 1;
                      uVar7 = (ulonglong)uVar6;
                      uVar17 = puVar4[3];
                    } while (uVar6 < uVar17);
                  }
                  NVar3 = (*pcVar2)(*(undefined8 *)(puVar16 + 6),pUVar18,uVar17,0);
                  if (-1 < NVar3) {
                    for (uVar7 = (ulonglong)puVar4[3]; uVar7 != 0; uVar7 = uVar7 - 1) {
                      *pUVar18 = '\0';
                      pUVar18 = pUVar18 + 1;
                    }
                    goto LAB_18000432d;
                  }
                  uVar5 = 0x8d;
                }
                DebugTraceError((char)NVar3,"Status",
                                "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar5);
                for (uVar7 = (ulonglong)puVar4[3]; uVar7 != 0; uVar7 = uVar7 - 1) {
                  *pUVar18 = '\0';
                  pUVar18 = pUVar18 + 1;
                }
                goto LAB_180004428;
              }
              uVar7 = uVar7 & 0xffffffff00000000;
              NVar3 = (*local_50)(*(undefined8 *)(puVar4 + 6),L"HashDigestLength",&local_78,4,
                                  local_68 + 1,uVar7);
              if (NVar3 < 0) {
                uVar5 = 0x2f;
                uVar14 = (undefined1)NVar3;
              }
              else {
                if (puVar4[3] < local_78) {
                  uVar5 = 0x37;
                  goto LAB_18000444d;
                }
                NVar3 = (*local_60)(*(undefined8 *)(puVar16 + 4),pbSecret,cbSecret,0);
                if (NVar3 < 0) {
                  uVar5 = 0x42;
                  uVar14 = (undefined1)NVar3;
                }
                else {
                  NVar3 = (*local_48)(*(undefined8 *)(puVar16 + 4),local_70,local_78,0);
                  if (NVar3 < 0) {
                    uVar5 = 0x4d;
                    uVar14 = (undefined1)NVar3;
                  }
                  else {
                    pUVar18 = local_70 + local_78;
                    for (uVar13 = (ulonglong)(puVar4[3] - local_78); uVar13 != 0;
                        uVar13 = uVar13 - 1) {
                      *pUVar18 = '\0';
                      pUVar18 = pUVar18 + 1;
                    }
                    NVar3 = (*local_40)(*(undefined8 *)(puVar16 + 4));
                    if (NVar3 < 0) {
                      uVar5 = 0x57;
                      uVar14 = (undefined1)NVar3;
                    }
                    else {
                      NVar3 = (*pcVar2)(*(undefined8 *)(puVar4 + 6),puVar16 + 4,local_38,uVar17,0,
                                        uVar7 & 0xffffffff00000000,0);
                      if (-1 < NVar3) {
                        pUVar18 = local_70;
                        goto LAB_1800047d6;
                      }
                      uVar5 = 100;
                      uVar14 = (undefined1)NVar3;
                    }
                  }
                }
              }
            }
          }
        }
      }
      else {
        NVar3 = -0x3fffff45;
        uVar5 = 0xb7;
        uVar14 = 0xbb;
      }
    }
    DebugTraceError(uVar14,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar5)
    ;
  }
LAB_180004428:
  if (pUVar15 != (PUCHAR)0x0) {
    SafeAllocaFreeToHeap(pUVar15);
  }
  if (NVar3 < 0) {
    return NVar3;
  }
LAB_180004333:
  LOCK();
  puVar4[4] = puVar4[4] + 1;
  UNLOCK();
  return NVar3;
}



===== ValidateBaseAlgHandle @ 1800048a0 =====

uint * ValidateBaseAlgHandle(uint *param_1)

{
  ulonglong *puVar1;
  byte bVar2;
  byte bVar3;
  uint *puVar4;
  void *_Dst;
  ulonglong uVar5;
  ulonglong uVar6;
  bool bVar7;
  
  if (param_1 != (uint *)0x0) {
    if (((byte)param_1 & 0xf) == 1) {
      uVar5 = (ulonglong)param_1 >> 4;
      if (uVar5 < 0x4b) {
        uVar6 = (ulonglong)(byte)(&DAT_18001fc33)[uVar5 * 5];
        bVar2 = (&DAT_18001fc34)[uVar5 * 5];
        _Dst = *(void **)(&PseudoHandleTableTable + uVar6 * 8);
        if (_Dst == (void *)0x0) {
          bVar3 = (&PseudoHandleTableSize)[uVar6];
          _Dst = (void *)BCryptAlloc((ulonglong)bVar3 << 3);
          if (_Dst == (void *)0x0) {
            return (uint *)0x0;
          }
          memset(_Dst,0,(ulonglong)bVar3 << 3);
          LOCK();
          bVar7 = *(longlong *)(&PseudoHandleTableTable + uVar6 * 8) == 0;
          if (bVar7) {
            *(void **)(&PseudoHandleTableTable + uVar6 * 8) = _Dst;
          }
          UNLOCK();
          if (!bVar7) {
            SafeAllocaFreeToHeap(_Dst);
            _Dst = *(void **)(&PseudoHandleTableTable + uVar6 * 8);
          }
        }
        puVar4 = *(uint **)((longlong)_Dst + (ulonglong)bVar2 * 8);
        puVar1 = (ulonglong *)((longlong)_Dst + (ulonglong)bVar2 * 8);
        if (puVar4 == (uint *)0x0) {
          InitializePseudoHandleEntry(uVar5,puVar1);
          return (uint *)*puVar1;
        }
        return puVar4;
      }
    }
    else if ((0x3c7 < *param_1) && (param_1[1] == 0x55555551)) {
      return param_1;
    }
  }
  return (uint *)0x0;
}



===== AllocateObjectBuffer @ 1800049c0 =====

NTSTATUS AllocateObjectBuffer(BCRYPT_HANDLE param_1,longlong *param_2,undefined4 *param_3)

{
  NTSTATUS NVar1;
  longlong lVar2;
  undefined4 local_res20 [2];
  ULONG local_18 [4];
  
  local_res20[0] = 0;
  local_18[0] = 0;
  NVar1 = BCryptGetProperty(param_1,L"ObjectLength",(PUCHAR)local_res20,4,local_18,0);
  if (NVar1 < 0) {
    DebugTraceError((char)NVar1,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",
                    0xe2);
  }
  else {
    lVar2 = RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,
                            local_res20[0]);
    if (lVar2 == 0) {
      DebugTraceError(0x17,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",0xea);
      NVar1 = -0x3fffffe9;
    }
    else {
      *param_2 = lVar2;
      NVar1 = 0;
      *param_3 = local_res20[0];
    }
  }
  return NVar1;
}



===== BCryptGetProperty @ 180004aa0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

NTSTATUS __stdcall
BCryptGetProperty(BCRYPT_HANDLE hObject,LPCWSTR pszProperty,PUCHAR pbOutput,ULONG cbOutput,
                 ULONG *pcbResult,ULONG dwFlags)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  longlong lVar4;
  wchar_t *pwVar5;
  longlong lVar6;
  PUCHAR pUVar7;
  undefined8 uVar8;
  int iVar9;
  uint local_res10;
  undefined1 uVar10;
  
                    /* 0x4aa0  36  BCryptGetProperty */
  iVar9 = 0;
  local_res10 = 0;
  pUVar7 = pbOutput;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_qSqdqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0,pbOutput,hObject,pszProperty,
                  (char)pbOutput,(char)cbOutput,(char)pcbResult,(char)dwFlags);
  }
  pwVar5 = (LPCWSTR)0x0;
  if (((pszProperty == (LPCWSTR)0x0) || (*pszProperty == L'\0')) || (pcbResult == (ULONG *)0x0)) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff3;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return -0x3ffffff3;
    }
    uVar10 = 0x89;
    iVar1 = -0x3ffffff3;
LAB_180004e9e:
    WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pwVar5,pUVar7,"Status",(char)iVar1,
                "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar10);
    return iVar1;
  }
  puVar2 = ValidateBaseAlgHandle(hObject);
  if (puVar2 == (uint *)0x0) {
    if ((((byte)hObject & 0xf) == 1) ||
       (puVar3 = ValidateBaseObjectHandle(hObject), puVar3 == (uint *)0x0)) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3ffffff8;
      }
      if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
        return -0x3ffffff8;
      }
      uVar10 = 0x9b;
      iVar1 = -0x3ffffff8;
      goto LAB_180004e9e;
    }
    puVar2 = *(uint **)(puVar3 + 2);
    uVar8 = *(undefined8 *)(puVar3 + 4);
  }
  else {
    uVar8 = *(undefined8 *)(puVar2 + 6);
  }
  lVar6 = -1;
  lVar4 = -1;
  do {
    if (pszProperty[lVar4 + 1] != L"ProviderHandle"[lVar4 + 1]) break;
    lVar4 = lVar4 + 2;
    if (lVar4 == 0xf) {
      *pcbResult = 8;
      if (pbOutput == (PUCHAR)0x0) {
        return 0;
      }
      if (cbOutput < 8) {
        return -0x3fffffdd;
      }
      *(uint **)pbOutput = puVar2;
      return 0;
    }
  } while (pszProperty[lVar4] == L"ProviderHandle"[lVar4]);
  pUVar7 = (PUCHAR)0x0;
  pwVar5 = L"PrimitiveType";
  lVar4 = 0;
  while ((pszProperty[lVar4] == L"PrimitiveType"[lVar4] &&
         (pszProperty[lVar4 + 1] == L"PrimitiveType"[lVar4 + 1]))) {
    lVar4 = lVar4 + 2;
    if (lVar4 == 0xe) {
      *pcbResult = 4;
      if (pbOutput != (PUCHAR)0x0) {
        if (cbOutput < 4) {
          return -0x3fffffdd;
        }
        *(uint *)pbOutput = puVar2[9];
      }
      return 0;
    }
  }
  switch(puVar2[9]) {
  case 1:
  case 3:
  case 4:
  case 5:
  case 7:
  case 8:
    iVar9 = 0x20;
  case 6:
    break;
  case 2:
    iVar9 = 0x28;
    local_res10 = puVar2[2] >> 3 & 1;
    break;
  default:
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff8;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return -0x3ffffff8;
    }
    uVar10 = 0;
    iVar1 = -0x3ffffff8;
    goto LAB_180004e9e;
  }
  lVar4 = 0;
  do {
    if ((pszProperty[lVar4] != L"IsKeyedHash"[lVar4]) ||
       (pszProperty[lVar4 + 1] != L"IsKeyedHash"[lVar4 + 1])) goto LAB_180004cd5;
    lVar4 = lVar4 + 2;
  } while (lVar4 != 0xc);
  if (local_res10 == 0) {
LAB_180004cd5:
    pwVar5 = pszProperty;
    pUVar7 = pbOutput;
    iVar1 = (**(code **)(puVar2 + 0x10))(uVar8,pszProperty,pbOutput,cbOutput,pcbResult,dwFlags);
    if (iVar1 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar1;
      }
      if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
        return iVar1;
      }
      uVar10 = 0x28;
      goto LAB_180004e9e;
    }
    do {
      if (pszProperty[lVar6 + 1] != L"ObjectLength"[lVar6 + 1]) break;
      lVar6 = lVar6 + 2;
      if (lVar6 == 0xd) {
        *pcbResult = 4;
        if (pbOutput == (PUCHAR)0x0) {
          return 0;
        }
        if (cbOutput < 4) {
          return -0x3fffffdd;
        }
        iVar1 = *(int *)pbOutput;
        if (local_res10 != 0) {
          iVar1 = puVar2[3] + iVar1 * 2 + 0xf;
        }
        *(int *)pbOutput = iVar1 + iVar9 + 0x1e;
        break;
      }
    } while (pszProperty[lVar6] == L"ObjectLength"[lVar6]);
    lVar4 = 0;
    do {
      if (pszProperty[lVar4] != L"MultiObjectLength"[lVar4]) {
        return 0;
      }
      if (pszProperty[lVar4 + 1] != L"MultiObjectLength"[lVar4 + 1]) {
        return 0;
      }
      lVar4 = lVar4 + 2;
    } while (lVar4 != 0x12);
    *pcbResult = 8;
    if (pbOutput == (PUCHAR)0x0) {
      return 0;
    }
    if (7 < cbOutput) {
      *(int *)pbOutput = *(int *)pbOutput + iVar9 + 0x1e;
      return 0;
    }
  }
  else {
    *pcbResult = 4;
    if (pbOutput == (PUCHAR)0x0) {
      return 0;
    }
    if (3 < cbOutput) {
      pbOutput[0] = '\x01';
      pbOutput[1] = '\0';
      pbOutput[2] = '\0';
      pbOutput[3] = '\0';
      return 0;
    }
  }
  return -0x3fffffdd;
}



===== BCryptDestroyHash @ 180004f00 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

NTSTATUS __stdcall BCryptDestroyHash(BCRYPT_HASH_HANDLE hHash)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  NTSTATUS NVar4;
  ulonglong uVar5;
  undefined8 in_RDX;
  longlong in_R8;
  longlong lVar6;
  
                    /* 0x4f00  15  BCryptDestroyHash */
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    in_RDX = 0x24;
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x24,in_R8,hHash);
  }
  if (((hHash == (BCRYPT_HASH_HANDLE)0x0) || (*(uint *)hHash < 0x28)) ||
     (*(int *)((longlong)hHash + 4) != 0x55555553)) {
    DebugTraceError(0xd,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",0xf7);
    return -0x3ffffff3;
  }
  puVar3 = *(uint **)((longlong)hHash + 8);
  lVar6 = *(longlong *)((longlong)hHash + 0x20);
  NVar4 = (**(code **)(puVar3 + 0x1e))(*(undefined8 *)((longlong)hHash + 0x10));
  if (NVar4 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return NVar4;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return NVar4;
    }
    WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),in_RDX,
                "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c","Status",(char)NVar4,
                "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",4);
  }
  else {
    if (((puVar3[2] & 8) == 0) ||
       (NVar4 = (**(code **)(puVar3 + 0x1e))(*(undefined8 *)((longlong)hHash + 0x18)), -1 < NVar4))
    {
      uVar5 = (ulonglong)*(uint *)hHash;
      for (; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined1 *)hHash = 0;
        hHash = (undefined1 *)((longlong)hHash + 1);
      }
      if (lVar6 != 0) {
        RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0);
        in_R8 = lVar6;
      }
      LOCK();
      puVar1 = puVar3 + 4;
      uVar2 = *puVar1;
      *puVar1 = *puVar1 - 1;
      UNLOCK();
      if (uVar2 == 1) {
        DestroyAlgorithmHeader(puVar3,1,in_R8);
      }
      return 0;
    }
    DebugTraceError((char)NVar4,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",
                    0xf);
  }
  return NVar4;
}



===== BCryptFinishHash @ 180005090 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

NTSTATUS __stdcall
BCryptFinishHash(BCRYPT_HASH_HANDLE hHash,PUCHAR pbOutput,ULONG cbOutput,ULONG dwFlags)

{
  longlong lVar1;
  NTSTATUS NVar2;
  int iVar3;
  PUCHAR pUVar4;
  undefined4 in_register_00000084;
  
                    /* 0x5090  30  BCryptFinishHash */
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_qqdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x23,
                CONCAT44(in_register_00000084,cbOutput),hHash,(char)pbOutput,(char)cbOutput,
                (char)dwFlags);
  }
  if (((hHash == (BCRYPT_HASH_HANDLE)0x0) || (*(uint *)hHash < 0x28)) ||
     (*(int *)((longlong)hHash + 4) != 0x55555553)) {
    DebugTraceError(8,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",0xf4);
    return -0x3ffffff8;
  }
  lVar1 = *(longlong *)((longlong)hHash + 8);
  pUVar4 = pbOutput;
  NVar2 = (**(code **)(lVar1 + 0x68))
                    (*(undefined8 *)((longlong)hHash + 0x10),pbOutput,cbOutput,dwFlags);
  if (NVar2 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return NVar2;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return NVar2;
    }
    WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pUVar4,
                "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c","Status",(char)NVar2,
                "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",0xfe);
  }
  else {
    if ((*(byte *)(lVar1 + 8) & 8) != 0) {
      NVar2 = (**(code **)(lVar1 + 0x60))
                        (*(undefined8 *)((longlong)hHash + 0x18),pbOutput,cbOutput,dwFlags);
      if (NVar2 < 0) {
        DebugTraceError((char)NVar2,"Status",
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",10);
        goto LAB_18000514b;
      }
      iVar3 = (**(code **)(lVar1 + 0x68))
                        (*(undefined8 *)((longlong)hHash + 0x18),pbOutput,cbOutput,dwFlags);
      if (iVar3 < 0) {
        DebugTraceError((char)iVar3,"Status",
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",0x13);
        return iVar3;
      }
    }
    NVar2 = 0;
  }
LAB_18000514b:
  return NVar2;
}



===== BCryptHashData @ 180005240 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

NTSTATUS __stdcall
BCryptHashData(BCRYPT_HASH_HANDLE hHash,PUCHAR pbInput,ULONG cbInput,ULONG dwFlags)

{
  NTSTATUS NVar1;
  undefined4 in_register_00000084;
  
                    /* 0x5240  38  BCryptHashData */
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_qqdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x22,
                CONCAT44(in_register_00000084,cbInput),hHash,(char)pbInput,(char)cbInput,
                (char)dwFlags);
  }
  if (((hHash == (BCRYPT_HASH_HANDLE)0x0) || (*(uint *)hHash < 0x28)) ||
     (*(int *)((longlong)hHash + 4) != 0x55555553)) {
    DebugTraceError(8,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",0xd2);
    NVar1 = -0x3ffffff8;
  }
  else {
    NVar1 = (**(code **)(*(longlong *)((longlong)hHash + 8) + 0x60))
                      (*(undefined8 *)((longlong)hHash + 0x10),pbInput,cbInput,dwFlags);
  }
  return NVar1;
}



===== DebugTraceError @ 180005308 =====

void DebugTraceError(undefined1 param_1,undefined8 param_2,undefined8 param_3,undefined1 param_4)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
    WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,param_3,(char *)param_2,param_1,
                (char *)param_3,param_4);
  }
  return;
}



===== DestroyAlgorithmHeader @ 180005350 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

int DestroyAlgorithmHeader(uint *param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  uint *puVar4;
  
  switch(param_1[9]) {
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
    break;
  default:
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,param_3,"Status",8,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",0xb6);
    }
    return -0x3ffffff8;
  }
  uVar3 = 0;
  iVar1 = (**(code **)(param_1 + 0x14))(*(undefined8 *)(param_1 + 6));
  if (-1 < iVar1) {
    UnloadProvider(*(undefined8 **)(param_1 + 10),uVar3,param_3);
    puVar4 = param_1;
    for (uVar2 = (ulonglong)*param_1; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)puVar4 = 0;
      puVar4 = (uint *)((longlong)puVar4 + 1);
    }
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,param_1);
    return iVar1;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
    WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar3,param_3,"Status",(char)iVar1,
                "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",0xbf);
  }
  return iVar1;
}



===== BCryptDeriveKey @ 1800054b0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

NTSTATUS __stdcall
BCryptDeriveKey(BCRYPT_SECRET_HANDLE hSharedSecret,LPCWSTR pwszKDF,BCryptBufferDesc *pParameterList,
               PUCHAR pbDerivedKey,ULONG cbDerivedKey,ULONG *pcbResult,ULONG dwFlags)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  BCryptBufferDesc **ppBVar4;
  LPCWSTR pWVar5;
  BCryptBufferDesc *pBVar6;
  BCryptBufferDesc *local_38 [2];
  
                    /* 0x54b0  12  BCryptDeriveKey */
  local_38[0] = (BCryptBufferDesc *)0x0;
  pWVar5 = pwszKDF;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_qSqqDqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pwszKDF,pParameterList,hSharedSecret,
                   pwszKDF,(char)pParameterList,(char)pbDerivedKey,(char)cbDerivedKey,
                   (char)pcbResult,(char)dwFlags);
  }
  if (pcbResult == (ULONG *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pWVar5,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c","Status",0xd,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",0xeb);
    }
    return -0x3ffffff3;
  }
  if (((hSharedSecret == (BCRYPT_SECRET_HANDLE)0x0) || (*(uint *)hSharedSecret < 0x18)) ||
     (*(int *)((longlong)hSharedSecret + 4) != 0x55555554)) {
    DebugTraceError(8,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",0xf3);
    return -0x3ffffff8;
  }
  if (*(int *)(*(longlong *)((longlong)hSharedSecret + 8) + 0x24) != 4) {
    DebugTraceError(0xbb,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",1);
    return -0x3fffff45;
  }
  pcVar1 = *(code **)(*(longlong *)((longlong)hSharedSecret + 8) + 0x60);
  pBVar6 = (BCryptBufferDesc *)0x0;
  if (pParameterList != (BCryptBufferDesc *)0x0) {
    ppBVar4 = local_38;
    uVar3 = _ProcessBufferDescParameters(&pParameterList->ulVersion,ppBVar4);
    iVar2 = (int)uVar3;
    if (iVar2 != 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),ppBVar4,
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c","Status",(char)uVar3,
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",0xd);
      }
      pBVar6 = local_38[0];
      goto LAB_1800055c1;
    }
    pBVar6 = local_38[0];
  }
  iVar2 = (*pcVar1)(*(undefined8 *)((longlong)hSharedSecret + 0x10),pwszKDF,pBVar6,pbDerivedKey,
                    cbDerivedKey,pcbResult,dwFlags);
  if (iVar2 < 0) {
    DebugTraceError((char)iVar2,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",
                    0x1b);
  }
LAB_1800055c1:
  if ((pBVar6 != (BCryptBufferDesc *)0x0) && (pParameterList != pBVar6)) {
    if (pBVar6->pBuffers != (PBCryptBuffer)0x0) {
      SafeAllocaFreeToHeap(pBVar6->pBuffers);
    }
    SafeAllocaFreeToHeap(pBVar6);
  }
  return iVar2;
}



===== InitializePseudoHandleEntry @ 180005740 =====

ulonglong InitializePseudoHandleEntry(longlong param_1,ulonglong *param_2)

{
  ulonglong uVar1;
  byte bVar2;
  longlong lVar3;
  NTSTATUS NVar4;
  undefined4 extraout_var;
  ulonglong uVar5;
  undefined4 extraout_var_00;
  undefined4 extraout_var_01;
  BCRYPT_ALG_HANDLE local_res8;
  
  local_res8 = (BCRYPT_HANDLE)0x0;
  lVar3 = param_1 * 5;
  NVar4 = BCryptOpenAlgorithmProvider
                    (&local_res8,
                     (LPCWSTR)(&PseudoHandleAlgName)[(byte)(&PseudoHandlePropertyTable)[lVar3]],
                     (LPCWSTR)0x0,
                     *(ULONG *)(&PseudoHandleFlags + (ulonglong)(byte)(&DAT_18001fc31)[lVar3] * 4));
  uVar5 = CONCAT44(extraout_var,NVar4);
  if (-1 < NVar4) {
    bVar2 = (&DAT_18001fc32)[lVar3];
    if (bVar2 != 0) {
      NVar4 = BCryptSetProperty(local_res8,L"ChainingMode",
                                *(PUCHAR *)(&PseudohandleChainingMode + (ulonglong)bVar2 * 0x10),
                                *(ULONG *)(&DAT_18001e6b8 + (ulonglong)bVar2 * 0x10),0);
      uVar5 = CONCAT44(extraout_var_00,NVar4);
      if (NVar4 < 0) goto LAB_1800057f1;
    }
    *(uint *)((longlong)local_res8 + 8U) = *(uint *)((longlong)local_res8 + 8U) | 0x80000000;
    uVar5 = 0;
    LOCK();
    uVar1 = *param_2;
    if (uVar1 == 0) {
      *param_2 = (ulonglong)local_res8;
    }
    else {
      uVar5 = uVar1;
    }
    UNLOCK();
    if (uVar1 == 0) {
      local_res8 = (BCRYPT_ALG_HANDLE)0x0;
    }
  }
LAB_1800057f1:
  if (local_res8 != (BCRYPT_ALG_HANDLE)0x0) {
    NVar4 = BCryptCloseAlgorithmProvider(local_res8,0);
    uVar5 = CONCAT44(extraout_var_01,NVar4);
  }
  return uVar5;
}



===== _ProcessBufferDescParameters @ 180005818 =====

undefined8 _ProcessBufferDescParameters(undefined4 *param_1,undefined8 *param_2)

{
  longlong lVar1;
  bool bVar2;
  longlong lVar3;
  uint *puVar4;
  undefined4 *puVar5;
  undefined1 uVar6;
  undefined8 *puVar7;
  longlong lVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  undefined1 uVar11;
  uint uVar12;
  
  bVar2 = false;
  uVar10 = 0;
  if (param_1[1] != 0) {
    do {
      if (bVar2) goto LAB_180005875;
      if (*(int *)(*(longlong *)(param_1 + 2) + 4 + uVar10 * 0x10) == 6) {
        bVar2 = true;
      }
      uVar12 = (int)uVar10 + 1;
      uVar10 = (ulonglong)uVar12;
    } while (uVar12 < (uint)param_1[1]);
    if (bVar2) {
LAB_180005875:
      puVar7 = param_2;
      lVar3 = BCryptAlloc((ulonglong)(uint)param_1[1] << 4);
      if (lVar3 == 0) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0xc0000017;
        }
        if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
          return 0xc0000017;
        }
        WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),puVar7,
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c","Status",0x17,
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",0x57);
        return 0xc0000017;
      }
      uVar10 = 0;
      while (uVar12 = (uint)uVar10, uVar12 < (uint)param_1[1]) {
        lVar8 = uVar10 * 2;
        *(undefined4 *)(lVar3 + 4 + uVar10 * 0x10) =
             *(undefined4 *)(*(longlong *)(param_1 + 2) + 4 + uVar10 * 0x10);
        *(undefined4 *)(lVar3 + uVar10 * 0x10) =
             *(undefined4 *)(*(longlong *)(param_1 + 2) + uVar10 * 0x10);
        lVar1 = *(longlong *)(param_1 + 2);
        if (*(int *)(lVar1 + 4 + uVar10 * 0x10) == 6) {
          if (*(int *)(lVar1 + uVar10 * 0x10) != 8) {
            uVar9 = 0xc000000d;
            uVar6 = 0xd;
            uVar11 = 0x6e;
            goto LAB_180005980;
          }
          puVar4 = ValidateBaseSecretHandle(*(uint **)(lVar1 + 8 + uVar10 * 0x10));
          if (puVar4 == (uint *)0x0) {
            uVar9 = 0xc0000008;
            uVar6 = 8;
            uVar11 = 0x7c;
            goto LAB_180005980;
          }
          uVar9 = *(undefined8 *)(puVar4 + 4);
        }
        else {
          uVar9 = *(undefined8 *)(lVar1 + 8 + uVar10 * 0x10);
        }
        *(undefined8 *)(lVar3 + 8 + lVar8 * 8) = uVar9;
        uVar10 = (ulonglong)(uVar12 + 1);
      }
      puVar5 = (undefined4 *)BCryptAlloc(0x10);
      if (puVar5 == (undefined4 *)0x0) {
        uVar9 = 0xc0000017;
        uVar6 = 0x17;
        uVar11 = 0x8d;
LAB_180005980:
        DebugTraceError(uVar6,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",
                        uVar11);
        SafeAllocaFreeToHeap(lVar3);
        return uVar9;
      }
      *puVar5 = *param_1;
      puVar5[1] = param_1[1];
      *(longlong *)(puVar5 + 2) = lVar3;
      param_1 = puVar5;
    }
  }
  *param_2 = param_1;
  return 0;
}



===== InitializeSystemPreferredCache @ 1800059e0 =====

int InitializeSystemPreferredCache(void)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined1 uVar4;
  
  uVar2 = 0;
  uVar3 = 0x60;
  g_pCachedRngRWLock = RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30));
  if (g_pCachedRngRWLock == 0) {
    lVar1 = -0x3fffffe9;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180005b25;
    uVar4 = 0xe;
LAB_180005b6b:
    lVar1 = -0x3fffffe9;
  }
  else {
    RtlInitializeResource(g_pCachedRngRWLock);
    uVar2 = 0;
    uVar3 = 0x28;
    DAT_180025b18 = RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30));
    if (DAT_180025b18 == 0) {
      lVar1 = -0x3fffffe9;
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180005b25;
      uVar4 = 0x22;
      goto LAB_180005b6b;
    }
    lVar1 = RtlInitializeCriticalSection(DAT_180025b18);
    if (lVar1 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar2,uVar3,"Status",(char)lVar1,
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\syspref.c",0x29);
      }
      SafeAllocaFreeToHeap(DAT_180025b18);
      DAT_180025b18 = 0;
      goto LAB_180005b25;
    }
    lVar1 = BcpRegisterConfigChangeNotifyNoLogging(&DAT_180025b10);
    if (-1 < lVar1) {
      DAT_180025ac4 = 1;
      lVar1 = 0;
      goto LAB_180005b25;
    }
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180005b25;
    uVar4 = 0x34;
  }
  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar2,uVar3,"Status",(char)lVar1,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\syspref.c",uVar4);
LAB_180005b25:
  if (lVar1 < 0) {
    CleanupSystemPreferredCache();
  }
  return lVar1;
}



===== BcpRegisterConfigChangeNotifyNoLogging @ 180005bf4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long BcpRegisterConfigChangeNotifyNoLogging(undefined8 *param_1)

{
  ulong uVar1;
  long lVar2;
  uint uVar3;
  HANDLE pvVar4;
  uchar *puVar5;
  undefined1 auStackY_128 [32];
  ulong local_b8 [4];
  uchar local_a8 [128];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_128;
  lVar2 = 0;
  memset(local_a8,0,0x80);
  local_b8[0] = 0;
  puVar5 = local_a8;
  if (param_1 == (undefined8 *)0x0) {
    uVar1 = 0x57;
  }
  else {
    *param_1 = 0;
    pvVar4 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    *param_1 = pvVar4;
    if (pvVar4 == (HANDLE)0x0) {
      uVar1 = GetLastError();
    }
    else {
      uVar3 = g_TrustedEnvironment;
      if (g_TrustedEnvironment == 0) {
        uVar3 = GetTrustedEnvironment();
      }
      if ((uVar3 & 1) == 0) {
        return 0;
      }
      uVar1 = IoPack_Configuration_ParamBlock
                        (0,(ushort *)0x0,0,(ushort *)0x0,(ushort *)0x0,(ushort *)0x0,0,
                         (_CRYPT_CONTEXT_CONFIG *)0x0,(_CRYPT_CONTEXT_FUNCTION_CONFIG *)0x0,0,
                         (uchar *)0x0,(void *)*param_1,local_b8,(uchar *)0x0);
      if (uVar1 == 0) {
        if ((local_b8[0] < 0x81) ||
           (puVar5 = (uchar *)BCryptAlloc((ulonglong)local_b8[0]), puVar5 != (uchar *)0x0)) {
          uVar1 = IoPack_Configuration_ParamBlock
                            (0,(ushort *)0x0,0,(ushort *)0x0,(ushort *)0x0,(ushort *)0x0,0,
                             (_CRYPT_CONTEXT_CONFIG *)0x0,(_CRYPT_CONTEXT_FUNCTION_CONFIG *)0x0,0,
                             (uchar *)0x0,(void *)*param_1,(ulong *)0x0,puVar5);
          if ((uVar1 == 0) &&
             (lVar2 = IoCallKernelDriver(0x10500,puVar5,local_b8[0],(uchar *)0x0,(ulong *)0x0),
             -1 < lVar2)) goto LAB_180005d59;
        }
        else {
          uVar1 = 8;
        }
      }
    }
    if ((HANDLE)*param_1 != (HANDLE)0x0) {
      CloseHandle((HANDLE)*param_1);
      *param_1 = 0;
    }
    if (lVar2 < 0) goto LAB_180005d59;
  }
  lVar2 = WinErrorToNtStatus(uVar1);
LAB_180005d59:
  if ((puVar5 != (uchar *)0x0) && (puVar5 != local_a8)) {
    BCryptFree((longlong)puVar5);
  }
  return lVar2;
}



===== SafeAllocaFreeToHeap @ 180005e20 =====

void SafeAllocaFreeToHeap(undefined8 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180005e32. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,param_1);
  return;
}



===== IoUnpack_SG_SzStringArray @ 180005e44 =====

/* unsigned long __cdecl IoUnpack_SG_SzStringArray(unsigned short * __ptr64 * __ptr64 *
   __ptr64,unsigned long,unsigned char * __ptr64,unsigned long,unsigned char * __ptr64) */

ulong __cdecl
IoUnpack_SG_SzStringArray
          (ushort ***param_1,ulong param_2,uchar *param_3,ulong param_4,uchar *param_5)

{
  ulong uVar1;
  ushort **ppuVar2;
  ulonglong uVar3;
  ulong uVar4;
  undefined4 in_register_0000008c;
  
  ppuVar2 = *param_1;
  if (ppuVar2 == (ushort **)0xffffffffffffffff) {
    *param_1 = (ushort **)0x0;
    if (param_2 != 0) {
      return 0x54f;
    }
    ppuVar2 = (ushort **)0x0;
  }
  else {
    if ((((param_2 == 0) || ((ushort **)(ulonglong)param_4 <= ppuVar2)) ||
        (ppuVar2 + param_2 < ppuVar2)) || ((ushort **)(ulonglong)param_4 < ppuVar2 + param_2)) {
      return 0x54f;
    }
    ppuVar2 = (ushort **)((longlong)ppuVar2 + (longlong)param_3);
    *param_1 = ppuVar2;
  }
  if (ppuVar2 != (ushort **)0x0) {
    uVar4 = param_4;
    for (uVar3 = 0; (uint)uVar3 < param_2; uVar3 = (ulonglong)((uint)uVar3 + 1)) {
      uVar1 = IoUnpack_SG_SzString
                        (*param_1 + uVar3,param_3,param_4,
                         (uchar *)CONCAT44(in_register_0000008c,uVar4));
      if (uVar1 != 0) {
        return uVar1;
      }
    }
  }
  return 0;
}



===== BCryptEnumContextFunctionProviders @ 180005ef0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

NTSTATUS __stdcall
BCryptEnumContextFunctionProviders
          (ULONG dwTable,LPCWSTR pszContext,ULONG dwInterface,LPCWSTR pszFunction,ULONG *pcbBuffer,
          PCRYPT_CONTEXT_FUNCTION_PROVIDERS *ppBuffer)

{
  ulong uVar1;
  int iVar2;
  ulong uVar3;
  int iVar4;
  uchar *puVar5;
  _CRYPT_CONTEXT_FUNCTION_PROVIDERS **pp_Var6;
  ULONG UVar7;
  LPCWSTR pWVar8;
  undefined1 auStackY_218 [32];
  ulong local_1a8;
  int local_1a4;
  LPCWSTR local_1a0;
  uchar local_198 [320];
  ulonglong local_58;
  
                    /* 0x5ef0  23  BCryptEnumContextFunctionProviders */
  local_58 = __security_cookie ^ (ulonglong)auStackY_218;
  puVar5 = local_198;
  iVar4 = 0;
  local_1a8 = 0;
  local_1a4 = 0;
  pWVar8 = pszFunction;
  UVar7 = dwInterface;
  local_1a0 = pszContext;
  iVar2 = ValidateTableId(dwTable,(ulong)pszContext);
  if ((((iVar2 == 0) || (iVar2 = ValidateInterfaceId(UVar7,0), iVar2 == 0)) ||
      (pWVar8 == (LPCWSTR)0x0)) || ((*pWVar8 == L'\0' || (pcbBuffer == (ULONG *)0x0)))) {
    uVar3 = 0x57;
LAB_1800060d1:
    if (local_1a4 != 0) {
      BCryptFree((longlong)*ppBuffer);
      *ppBuffer = (PCRYPT_CONTEXT_FUNCTION_PROVIDERS)0x0;
    }
    if (iVar4 < 0) goto LAB_18000607b;
  }
  else {
    uVar3 = IoPack_Configuration_ParamBlock
                      (dwTable,(ushort *)pszContext,UVar7,(ushort *)pWVar8,(ushort *)0x0,
                       (ushort *)0x0,0,(_CRYPT_CONTEXT_CONFIG *)0x0,
                       (_CRYPT_CONTEXT_FUNCTION_CONFIG *)0x0,0,(uchar *)0x0,(void *)0x0,&local_1a8,
                       (uchar *)0x0);
    uVar1 = local_1a8;
    if (uVar3 == 0) {
      if ((local_1a8 < 0x141) ||
         (puVar5 = (uchar *)BCryptAlloc((ulonglong)local_1a8), puVar5 != (uchar *)0x0)) {
        uVar3 = IoPack_Configuration_ParamBlock
                          (dwTable,(ushort *)local_1a0,dwInterface,(ushort *)pszFunction,
                           (ushort *)0x0,(ushort *)0x0,0,(_CRYPT_CONTEXT_CONFIG *)0x0,
                           (_CRYPT_CONTEXT_FUNCTION_CONFIG *)0x0,0,(uchar *)0x0,(void *)0x0,
                           (ulong *)0x0,puVar5);
        if (uVar3 == 0) {
          pp_Var6 = (_CRYPT_CONTEXT_FUNCTION_PROVIDERS **)0x10302;
          iVar4 = IoCallKernelDriverQueryLoop
                            (0x10302,puVar5,uVar1,(uchar **)ppBuffer,pcbBuffer,&local_1a4);
          if ((-1 < iVar4) &&
             (uVar3 = IoUnpack_ContextFunctionProviders(pp_Var6,(uchar *)*ppBuffer,*pcbBuffer),
             uVar3 == 0)) goto LAB_18000607b;
          goto LAB_1800060d1;
        }
      }
      else {
        uVar3 = 8;
      }
    }
  }
  iVar4 = WinErrorToNtStatus(uVar3);
LAB_18000607b:
  if ((puVar5 != (uchar *)0x0) && (puVar5 != local_198)) {
    BCryptFree((longlong)puVar5);
  }
  if (ppBuffer == (PCRYPT_CONTEXT_FUNCTION_PROVIDERS *)0x0) {
    if (iVar4 == -0x3fffffdd) {
      iVar4 = 0;
    }
  }
  return iVar4;
}



===== ValidateTableId @ 180006100 =====

/* int __cdecl ValidateTableId(unsigned long,unsigned long) */

int __cdecl ValidateTableId(ulong param_1,ulong param_2)

{
  if (param_1 - 1 < 2) {
    return 1;
  }
  return 0;
}



===== BCryptResolveProvidersForBcoapCached @ 180006120 =====

NTSTATUS BCryptResolveProvidersForBcoapCached
                   (LPCWSTR param_1,LPCWSTR param_2,ULONG param_3,ULONG *param_4,
                   PCRYPT_PROVIDER_REFS *param_5,undefined1 *param_6)

{
  WCHAR WVar1;
  WCHAR WVar2;
  NTSTATUS NVar3;
  HRESULT HVar4;
  LPCWSTR pWVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  bool bVar9;
  
  NVar3 = 0;
  bVar9 = false;
  if ((param_2 == (LPCWSTR)0x0) && (puVar6 = g_pResolveProviderCache, param_3 == 2)) {
    for (; puVar6 != (undefined8 *)0x0; puVar6 = (undefined8 *)*puVar6) {
      pWVar5 = param_1;
      do {
        WVar1 = *pWVar5;
        WVar2 = *(WCHAR *)((longlong)pWVar5 + (longlong)puVar6 + (0x14 - (longlong)param_1));
        if (WVar1 != WVar2) break;
        pWVar5 = pWVar5 + 1;
      } while (WVar2 != L'\0');
      if (WVar1 == WVar2) {
        *param_4 = *(ULONG *)(puVar6 + 2);
        *param_5 = (PCRYPT_PROVIDER_REFS)puVar6[1];
        goto LAB_18000619e;
      }
    }
    pWVar5 = param_1;
    NVar3 = BCryptResolveProviders((LPCWSTR)0x0,0,param_1,(LPCWSTR)0x0,1,2,param_4,param_5);
    bVar9 = *param_5 != (PCRYPT_PROVIDER_REFS)0x0;
    if (NVar3 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),&WPP_GLOBAL_Control,pWVar5,"Status",
                    (char)NVar3,"onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",0xfb);
      }
    }
    else {
      puVar6 = (undefined8 *)BCryptAlloc(0x40);
      if (puVar6 == (undefined8 *)0x0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
          WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),&WPP_GLOBAL_Control,pWVar5,
                      "STATUS_NO_MEMORY",0x17,
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",2);
        }
      }
      else {
        HVar4 = StringCchCopyW((STRSAFE_LPWSTR)((longlong)puVar6 + 0x14),0x14,param_1);
        if (HVar4 == 0) {
          *(ULONG *)(puVar6 + 2) = *param_4;
          puVar6[1] = *param_5;
          puVar7 = g_pResolveProviderCache;
          do {
            *puVar6 = puVar7;
            LOCK();
            if (puVar7 == g_pResolveProviderCache) {
              puVar8 = puVar7;
              g_pResolveProviderCache = puVar6;
            }
            else {
              puVar8 = g_pResolveProviderCache;
            }
            UNLOCK();
            bVar9 = puVar7 != puVar8;
            puVar7 = puVar8;
          } while (bVar9);
          bVar9 = false;
        }
        else {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
            WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),&WPP_GLOBAL_Control,param_1,
                        "STATUS_BUFFER_TOO_SMALL",0x23,
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",9);
          }
          BCryptFree((longlong)puVar6);
        }
      }
    }
  }
  else {
    NVar3 = BCryptResolveProviders((LPCWSTR)0x0,0,param_1,param_2,1,param_3,param_4,param_5);
    bVar9 = *param_5 != (PCRYPT_PROVIDER_REFS)0x0;
  }
LAB_18000619e:
  *param_6 = bVar9;
  return NVar3;
}



===== BCryptResolveProviders @ 1800063b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

NTSTATUS __stdcall
BCryptResolveProviders
          (LPCWSTR pszContext,ULONG dwInterface,LPCWSTR pszFunction,LPCWSTR pszProvider,ULONG dwMode
          ,ULONG dwFlags,ULONG *pcbBuffer,PCRYPT_PROVIDER_REFS *ppBuffer)

{
  PCRYPT_PROVIDER_REFS p_Var1;
  ulong uVar2;
  PCRYPT_PROVIDER_REFS *pp_Var3;
  int iVar4;
  ulong uVar5;
  ULONG UVar6;
  long lVar7;
  LPCWSTR *ppWVar8;
  PCRYPT_PROVIDER_REF *pp_Var9;
  _CRYPT_PROVIDER_REFS *_Dst;
  LPCWSTR pWVar10;
  void *_Dst_00;
  LPCWSTR *ppWVar11;
  uint uVar12;
  void *_Dst_01;
  PCRYPT_PROVIDER_REF *pp_Var13;
  uint *puVar14;
  _CRYPT_PROVIDER_REFS *_Src;
  uint uVar15;
  ulonglong uVar16;
  undefined1 auStackY_238 [32];
  ulong local_1e8;
  ulong local_1e4;
  uint local_1e0;
  PCRYPT_PROVIDER_REFS *local_1d8;
  uint *local_1d0;
  LPCWSTR *local_1c8;
  LPCWSTR local_1c0;
  ulonglong uStack_1b8;
  LPCWSTR local_1b0;
  _CRYPT_PROVIDER_REFS local_1a8;
  LPCWSTR local_198 [40];
  ulonglong local_58;
  
                    /* 0x63b0  52  BCryptResolveProviders */
  local_58 = __security_cookie ^ (ulonglong)auStackY_238;
  ppWVar8 = local_198;
  local_1d0 = pcbBuffer;
  local_1d8 = ppBuffer;
  local_1e0 = dwInterface;
  local_1c0 = pszContext;
  local_1b0 = pszProvider;
  iVar4 = ValidateInterfaceId(dwInterface,1);
  if ((iVar4 == 0) ||
     (((dwMode != 2 && ((dwMode == 0 || ((dwMode != 1 && (dwMode != 3)))))) ||
      (pcbBuffer == (ULONG *)0x0)))) {
    uVar5 = 0x57;
  }
  else if ((dwFlags & 0xfffffffc) == 0) {
    uVar16 = 0x30;
    local_1e4 = 0x30;
    if (pszContext != (LPCWSTR)0x0) {
      local_1e4 = 0;
      uVar5 = SzString_CchLength((ushort *)pszContext,&local_1e4,0);
      if (uVar5 != 0) goto LAB_180006767;
      local_1e4 = (local_1e4 * 2 + 9 & 0xfffffff8) + 0x30;
    }
    uVar2 = local_1e4;
    if (pszFunction != (LPCWSTR)0x0) {
      local_1e4 = 0;
      uVar5 = SzString_CchLength((ushort *)pszFunction,&local_1e4,0);
      if (uVar5 != 0) goto LAB_180006767;
      local_1e4 = uVar2 + (local_1e4 * 2 + 9 & 0xfffffff8);
    }
    uVar2 = local_1e4;
    if (pszProvider != (LPCWSTR)0x0) {
      local_1e4 = 0;
      uVar5 = SzString_CchLength((ushort *)pszProvider,&local_1e4,0);
      if (uVar5 != 0) goto LAB_180006767;
      local_1e4 = uVar2 + (local_1e4 * 2 + 9 & 0xfffffff8);
    }
    if ((0x140 < local_1e4) &&
       (ppWVar8 = (LPCWSTR *)BCryptAlloc((ulonglong)local_1e4), ppWVar8 == (LPCWSTR *)0x0)) {
      local_1e4 = WinErrorToNtStatus(8);
      UVar6 = local_1e4;
      goto LAB_180006780;
    }
    _Dst_01 = (void *)0x0;
    local_1c8 = (LPCWSTR *)0x0;
    _Dst_00 = (void *)0x0;
    if (local_1c0 != (LPCWSTR)0x0) {
      local_1e8 = 0;
      local_1c8 = ppWVar8 + 6;
      if (ppWVar8 == (LPCWSTR *)0x0) {
        local_1c8 = (LPCWSTR *)0x0;
      }
      uVar5 = SzString_CchLength((ushort *)local_1c0,&local_1e8,0);
      if (uVar5 != 0) goto LAB_180006767;
      iVar4 = local_1e8 * 2;
      if (local_1c8 != (LPCWSTR *)0x0) {
        memcpy(local_1c8,local_1c0,(ulonglong)(local_1e8 + 1) * 2);
      }
      uVar16 = (ulonglong)((iVar4 + 9U & 0xfffffff8) + 0x30);
    }
    if (pszFunction != (LPCWSTR)0x0) {
      if (ppWVar8 != (LPCWSTR *)0x0) {
        _Dst_01 = (void *)((longlong)ppWVar8 + uVar16);
      }
      local_1e8 = 0;
      uVar5 = SzString_CchLength((ushort *)pszFunction,&local_1e8,0);
      if (uVar5 != 0) goto LAB_180006767;
      iVar4 = local_1e8 * 2;
      if (_Dst_01 != (void *)0x0) {
        memcpy(_Dst_01,pszFunction,(ulonglong)(local_1e8 + 1) * 2);
      }
      uVar16 = (ulonglong)((int)uVar16 + (iVar4 + 9U & 0xfffffff8));
    }
    pWVar10 = local_1b0;
    if (local_1b0 != (LPCWSTR)0x0) {
      if (ppWVar8 != (LPCWSTR *)0x0) {
        _Dst_00 = (void *)((longlong)ppWVar8 + uVar16);
      }
      local_1e8 = 0;
      uVar5 = SzString_CchLength((ushort *)local_1b0,&local_1e8,0);
      if (uVar5 != 0) goto LAB_180006767;
      if (_Dst_00 != (void *)0x0) {
        memcpy(_Dst_00,pWVar10,(ulonglong)(local_1e8 + 1) * 2);
      }
    }
    if (ppWVar8 != (LPCWSTR *)0x0) {
      *(uint *)(ppWVar8 + 2) = local_1e0;
      *(ULONG *)(ppWVar8 + 5) = dwMode;
      *(ULONG *)((longlong)ppWVar8 + 0x2c) = dwFlags;
      if (local_1c8 == (LPCWSTR *)0x0) {
        pWVar10 = (LPCWSTR)0xffffffffffffffff;
      }
      else {
        pWVar10 = (LPCWSTR)((longlong)local_1c8 - (longlong)ppWVar8);
      }
      ppWVar8[1] = pWVar10;
      if (_Dst_01 == (void *)0x0) {
        pWVar10 = (LPCWSTR)0xffffffffffffffff;
      }
      else {
        pWVar10 = (LPCWSTR)((longlong)_Dst_01 - (longlong)ppWVar8);
      }
      ppWVar8[3] = pWVar10;
      if (_Dst_00 == (void *)0x0) {
        ppWVar8[4] = (LPCWSTR)0xffffffffffffffff;
      }
      else {
        ppWVar8[4] = (LPCWSTR)((longlong)_Dst_00 - (longlong)ppWVar8);
      }
    }
    local_1e8 = 0;
    if (local_1d8 == (PCRYPT_PROVIDER_REFS *)0x0) {
      UVar6 = IoCallKernelDriver(0x20000,(uchar *)ppWVar8,local_1e4,(uchar *)0x0,&local_1e8);
      if (UVar6 != 0xc0000023) goto LAB_180006817;
      *local_1d0 = local_1e8;
      puVar14 = local_1d0;
    }
    else {
      _Dst = *local_1d8;
      if (_Dst == (_CRYPT_PROVIDER_REFS *)0x0) {
        uVar16 = 0x180;
        local_1e8 = 0x180;
        _Dst = (_CRYPT_PROVIDER_REFS *)0x0;
        goto LAB_1800068eb;
      }
      uVar15 = *local_1d0;
      local_1e8 = uVar15;
      do {
        local_1e0 = local_1e4;
        local_1c8 = (LPCWSTR *)((ulonglong)local_1c8 & 0xffffffff00000000);
        local_1c0 = (LPCWSTR)0x0;
        uStack_1b8 = 0;
        if (ppWVar8 != (LPCWSTR *)0x0) {
          ppWVar11 = ppWVar8;
          if (7 < local_1e4) goto LAB_18000693a;
          *local_1d0 = uVar15;
LAB_180006a14:
          UVar6 = 0xc00000e5;
LAB_180006a19:
          puVar14 = local_1d0;
          if ((_Dst != (_CRYPT_PROVIDER_REFS *)0x0) && (*local_1d8 == (PCRYPT_PROVIDER_REFS)0x0)) {
            BCryptFree((longlong)_Dst);
          }
          goto LAB_18000681c;
        }
        local_1e0 = 8;
        ppWVar11 = &local_1b0;
LAB_18000693a:
        *(undefined4 *)ppWVar11 = 0x1a2b3c4d;
        *(undefined4 *)((longlong)ppWVar11 + 4) = 0x20000;
        if ((_Dst == (_CRYPT_PROVIDER_REFS *)0x0) || (uVar15 < 8)) {
          _Src = &local_1a8;
        }
        else {
          _Src = _Dst;
        }
        if (g_hIoDevice == (void *)0x0) {
          EnterCriticalSection(&g_csIoInitialize);
          if (g_hIoDevice == (void *)0x0) {
            lVar7 = _IoOpenDevice();
            local_1c8 = (LPCWSTR *)CONCAT44(local_1c8._4_4_,lVar7);
          }
          LeaveCriticalSection(&g_csIoInitialize);
          UVar6 = (ULONG)local_1c8;
          if (-1 < (int)(ULONG)local_1c8) goto LAB_180006967;
          goto LAB_180006aae;
        }
LAB_180006967:
        UVar6 = NtDeviceIoControlFile(g_hIoDevice,0,0,0);
        uVar15 = (uint)uStack_1b8;
        if ((int)UVar6 < 0) {
          if (UVar6 == 0xc0000023) {
LAB_180006b6d:
            *local_1d0 = local_1e8;
            goto LAB_180006a14;
          }
          if (UVar6 == 0x80000005) {
            if (uVar15 < 4) goto LAB_180006b6d;
            UVar6 = _Src->cProviders;
            if (UVar6 == 0xc0000023) {
              if (uVar15 != 8) goto LAB_180006b6d;
              local_1e8 = *(ulong *)&_Src->field_0x4;
            }
            else if (uVar15 != 4) goto LAB_180006b6d;
LAB_180006aae:
            uVar16 = (ulonglong)local_1e8;
            if (UVar6 == 0xc0000023) goto LAB_180006adf;
          }
          uVar5 = local_1e8;
LAB_180006abd:
          *local_1d0 = uVar5;
          if (-1 < (int)UVar6) goto LAB_1800069e1;
          goto LAB_180006a19;
        }
        if ((_Dst != (_CRYPT_PROVIDER_REFS *)0x0) && (uVar15 <= local_1e8)) {
          if (_Src == &local_1a8) {
            memcpy(_Dst,_Src,uStack_1b8 & 0xffffffff);
          }
          UVar6 = 0;
          *local_1d0 = uVar15;
LAB_1800069e1:
          p_Var1 = *local_1d8;
          *local_1d8 = _Dst;
          local_1e0 = (uint)(p_Var1 == (PCRYPT_PROVIDER_REFS)0x0);
          puVar14 = local_1d0;
          local_1e4 = UVar6;
          goto LAB_180006836;
        }
        UVar6 = 0xc0000023;
        uVar16 = uStack_1b8;
        local_1e8 = uVar15;
LAB_180006adf:
        uVar5 = (ulong)uVar16;
        if (*local_1d8 != (PCRYPT_PROVIDER_REFS)0x0) goto LAB_180006abd;
LAB_1800068eb:
        uVar15 = (uint)uVar16;
        if (_Dst != (_CRYPT_PROVIDER_REFS *)0x0) {
          BCryptFree((longlong)_Dst);
        }
        _Dst = (_CRYPT_PROVIDER_REFS *)BCryptAlloc(uVar16 & 0xffffffff);
      } while (_Dst != (_CRYPT_PROVIDER_REFS *)0x0);
      UVar6 = 0xc0000017;
LAB_180006817:
      puVar14 = local_1d0;
    }
LAB_18000681c:
    local_1e0 = 0;
    local_1e4 = UVar6;
    if ((int)UVar6 < 0) goto LAB_180006780;
LAB_180006836:
    uVar2 = local_1e4;
    p_Var1 = *local_1d8;
    pp_Var13 = (PCRYPT_PROVIDER_REF *)(ulonglong)*puVar14;
    local_1c8 = (LPCWSTR *)CONCAT44(local_1c8._4_4_,*puVar14);
    UVar6 = uVar2;
    if (p_Var1 == (PCRYPT_PROVIDER_REFS)0x0) goto LAB_180006780;
    if ((p_Var1 <= p_Var1 + 1) &&
       (p_Var1 + 1 <= (PCRYPT_PROVIDER_REFS)((longlong)pp_Var13 + (longlong)p_Var1))) {
      pp_Var9 = p_Var1->rgpProviders;
      uVar15 = p_Var1->cProviders;
      if (pp_Var9 == (PCRYPT_PROVIDER_REF *)0xffffffffffffffff) {
        p_Var1->rgpProviders = (PCRYPT_PROVIDER_REF *)0x0;
        if (uVar15 == 0) {
          pp_Var9 = (PCRYPT_PROVIDER_REF *)0x0;
          goto LAB_180006887;
        }
      }
      else if ((((uVar15 != 0) && (pp_Var9 < pp_Var13)) && (pp_Var9 <= pp_Var9 + uVar15)) &&
              (pp_Var9 + uVar15 <= pp_Var13)) {
        pp_Var9 = (PCRYPT_PROVIDER_REF *)((longlong)pp_Var9 + (longlong)p_Var1);
        p_Var1->rgpProviders = pp_Var9;
LAB_180006887:
        if (pp_Var9 != (PCRYPT_PROVIDER_REF *)0x0) {
          for (uVar12 = 0; UVar6 = local_1e4, uVar12 < uVar15; uVar12 = uVar12 + 1) {
            uVar5 = IoUnpack_ProviderRef
                              (p_Var1->rgpProviders + uVar12,(uchar *)p_Var1,(ulong)pp_Var13);
            if (uVar5 != 0) goto LAB_18000674b;
            pp_Var13 = (PCRYPT_PROVIDER_REF *)((ulonglong)local_1c8 & 0xffffffff);
          }
        }
        goto LAB_180006780;
      }
    }
    uVar5 = 0x54f;
LAB_18000674b:
    pp_Var3 = local_1d8;
    if (local_1e0 != 0) {
      BCryptFree((longlong)*local_1d8);
      *pp_Var3 = (PCRYPT_PROVIDER_REFS)0x0;
    }
    UVar6 = uVar2;
    if ((int)uVar2 < 0) goto LAB_180006780;
  }
  else {
    uVar5 = 0x3ec;
  }
LAB_180006767:
  local_1e4 = WinErrorToNtStatus(uVar5);
  UVar6 = local_1e4;
LAB_180006780:
  pp_Var3 = local_1d8;
  if ((ppWVar8 != (LPCWSTR *)0x0) && (ppWVar8 != local_198)) {
    BCryptFree((longlong)ppWVar8);
    UVar6 = local_1e4;
  }
  if (pp_Var3 == (PCRYPT_PROVIDER_REFS *)0x0) {
    if (UVar6 == 0xc0000023) {
      UVar6 = 0;
    }
  }
  return UVar6;
}



===== IoUnpack_ProviderRef @ 180006bd0 =====

/* unsigned long __cdecl IoUnpack_ProviderRef(struct _CRYPT_PROVIDER_REF * __ptr64 *
   __ptr64,unsigned char * __ptr64,unsigned long) */

ulong __cdecl IoUnpack_ProviderRef(_CRYPT_PROVIDER_REF **param_1,uchar *param_2,ulong param_3)

{
  _CRYPT_PROVIDER_REF *p_Var1;
  _CRYPT_PROVIDER_REF *p_Var2;
  ulong uVar3;
  PCRYPT_PROPERTY_REF *pp_Var4;
  PWSTR pWVar5;
  _CRYPT_PROVIDER_REF *p_Var6;
  uint uVar7;
  _CRYPT_PROVIDER_REF *p_Var8;
  uint uVar9;
  ulong local_res8 [2];
  
  p_Var8 = *param_1;
  uVar7 = 0;
  p_Var2 = (_CRYPT_PROVIDER_REF *)(ulonglong)param_3;
  if (p_Var8 == (_CRYPT_PROVIDER_REF *)0xffffffffffffffff) {
    p_Var8 = (_CRYPT_PROVIDER_REF *)0x0;
  }
  else {
    if (p_Var2 <= p_Var8) {
      return 0x54f;
    }
    if (p_Var8 + 1 < p_Var8) {
      return 0x54f;
    }
    if (p_Var2 < p_Var8 + 1) {
      return 0x54f;
    }
    p_Var8 = (_CRYPT_PROVIDER_REF *)(param_2 + (longlong)&p_Var8->dwInterface);
  }
  *param_1 = p_Var8;
  if (p_Var8 != (_CRYPT_PROVIDER_REF *)0x0) {
    p_Var1 = (_CRYPT_PROVIDER_REF *)p_Var8->pszFunction;
    if (p_Var1 == (_CRYPT_PROVIDER_REF *)0xffffffffffffffff) {
      pWVar5 = (PWSTR)0x0;
    }
    else {
      if (p_Var2 <= p_Var1) {
        return 0x54f;
      }
      local_res8[0] = 0;
      uVar3 = SzString_CbLength((ushort *)(param_2 + (longlong)&p_Var1->dwInterface),local_res8,
                                param_3 - (int)p_Var1);
      if (uVar3 != 0) {
        return 0x54f;
      }
      p_Var1 = (_CRYPT_PROVIDER_REF *)p_Var8->pszFunction;
      p_Var6 = (_CRYPT_PROVIDER_REF *)
               ((longlong)&p_Var1->dwInterface + (ulonglong)local_res8[0] + 2);
      if (p_Var6 < p_Var1) {
        return 0x54f;
      }
      if (p_Var2 < p_Var6) {
        return 0x54f;
      }
      pWVar5 = (PWSTR)(param_2 + (longlong)&p_Var1->dwInterface);
    }
    p_Var8->pszFunction = pWVar5;
    if (pWVar5 != (PWSTR)0x0) {
      uVar9 = ((int)param_2 - (int)pWVar5) + param_3;
      if (uVar9 == 1) {
        return 0x7a;
      }
      uVar3 = SzString_CchLength((ushort *)pWVar5,local_res8,uVar9 >> 1);
      if (uVar3 != 0) {
        return uVar3;
      }
    }
    p_Var8 = *param_1;
    p_Var1 = (_CRYPT_PROVIDER_REF *)p_Var8->pszProvider;
    if (p_Var1 == (_CRYPT_PROVIDER_REF *)0xffffffffffffffff) {
      pWVar5 = (PWSTR)0x0;
    }
    else {
      if (p_Var2 <= p_Var1) {
        return 0x54f;
      }
      local_res8[0] = 0;
      uVar3 = SzString_CbLength((ushort *)(param_2 + (longlong)&p_Var1->dwInterface),local_res8,
                                param_3 - (int)p_Var1);
      if (uVar3 != 0) {
        return 0x54f;
      }
      p_Var1 = (_CRYPT_PROVIDER_REF *)p_Var8->pszProvider;
      p_Var6 = (_CRYPT_PROVIDER_REF *)
               ((longlong)&p_Var1->dwInterface + (ulonglong)local_res8[0] + 2);
      if (p_Var6 < p_Var1) {
        return 0x54f;
      }
      if (p_Var2 < p_Var6) {
        return 0x54f;
      }
      pWVar5 = (PWSTR)(param_2 + (longlong)&p_Var1->dwInterface);
    }
    p_Var8->pszProvider = pWVar5;
    if (pWVar5 != (PWSTR)0x0) {
      uVar9 = ((int)param_2 - (int)pWVar5) + param_3;
      if (uVar9 == 1) {
        return 0x7a;
      }
      uVar3 = SzString_CchLength((ushort *)pWVar5,local_res8,uVar9 >> 1);
      if (uVar3 != 0) {
        return uVar3;
      }
    }
    p_Var8 = *param_1;
    uVar3 = IoUnpack_ImageRef(&p_Var8->pUM,param_2,param_3);
    if (uVar3 != 0) {
      return uVar3;
    }
    uVar3 = IoUnpack_ImageRef(&p_Var8->pKM,param_2,param_3);
    if (uVar3 != 0) {
      return uVar3;
    }
    p_Var8 = *param_1;
    p_Var1 = (_CRYPT_PROVIDER_REF *)p_Var8->rgpProperties;
    uVar9 = p_Var8->cProperties;
    if (p_Var1 == (_CRYPT_PROVIDER_REF *)0xffffffffffffffff) {
      p_Var8->rgpProperties = (PCRYPT_PROPERTY_REF *)0x0;
      if (uVar9 != 0) {
        return 0x54f;
      }
      pp_Var4 = (PCRYPT_PROPERTY_REF *)0x0;
    }
    else {
      if (uVar9 == 0) {
        return 0x54f;
      }
      if (p_Var2 <= p_Var1) {
        return 0x54f;
      }
      if ((_CRYPT_PROVIDER_REF *)(&p_Var1->dwInterface + (ulonglong)uVar9 * 2) < p_Var1) {
        return 0x54f;
      }
      if (p_Var2 < (_CRYPT_PROVIDER_REF *)(&p_Var1->dwInterface + (ulonglong)uVar9 * 2)) {
        return 0x54f;
      }
      pp_Var4 = (PCRYPT_PROPERTY_REF *)(param_2 + (longlong)&p_Var1->dwInterface);
      p_Var8->rgpProperties = pp_Var4;
    }
    if (pp_Var4 != (PCRYPT_PROPERTY_REF *)0x0) {
      for (; uVar7 < uVar9; uVar7 = uVar7 + 1) {
        uVar3 = IoUnpack_PropertyRef(p_Var8->rgpProperties + uVar7,param_2,param_3);
        if (uVar3 != 0) {
          return uVar3;
        }
      }
    }
  }
  return 0;
}



===== ValidateInterfaceId @ 180006e24 =====

/* int __cdecl ValidateInterfaceId(unsigned long,unsigned long) */

int __cdecl ValidateInterfaceId(ulong param_1,ulong param_2)

{
  uint uVar1;
  
  if ((param_1 - 1 < 8) || (param_1 - 0x10001 < 4)) {
    return 1;
  }
  uVar1 = 0;
  if (param_1 == 0) {
    uVar1 = param_2 & 1;
  }
  return uVar1;
}



===== IoUnpack_ImageRef @ 180006e50 =====

/* unsigned long __cdecl IoUnpack_ImageRef(struct _CRYPT_IMAGE_REF * __ptr64 * __ptr64,unsigned char
   * __ptr64,unsigned long) */

ulong __cdecl IoUnpack_ImageRef(_CRYPT_IMAGE_REF **param_1,uchar *param_2,ulong param_3)

{
  _CRYPT_IMAGE_REF *p_Var1;
  _CRYPT_IMAGE_REF *p_Var2;
  ulong uVar3;
  PWSTR pWVar4;
  _CRYPT_IMAGE_REF *p_Var5;
  _CRYPT_IMAGE_REF *p_Var6;
  uint uVar7;
  ulong local_res8 [2];
  
  p_Var6 = *param_1;
  p_Var2 = (_CRYPT_IMAGE_REF *)(ulonglong)param_3;
  if (p_Var6 == (_CRYPT_IMAGE_REF *)0xffffffffffffffff) {
    p_Var6 = (_CRYPT_IMAGE_REF *)0x0;
LAB_180006e9b:
    *param_1 = p_Var6;
    if (p_Var6 != (_CRYPT_IMAGE_REF *)0x0) {
      p_Var1 = (_CRYPT_IMAGE_REF *)p_Var6->pszImage;
      if (p_Var1 == (_CRYPT_IMAGE_REF *)0xffffffffffffffff) {
        pWVar4 = (PWSTR)0x0;
LAB_180006eed:
        p_Var6->pszImage = pWVar4;
        if ((pWVar4 == (PWSTR)0x0) ||
           ((uVar7 = ((int)param_2 - (int)pWVar4) + param_3, uVar7 != 1 &&
            (uVar3 = SzString_CchLength((ushort *)pWVar4,local_res8,uVar7 >> 1), uVar3 == 0))))
        goto LAB_180006eaa;
      }
      else if (p_Var1 < p_Var2) {
        local_res8[0] = 0;
        uVar3 = SzString_CbLength((ushort *)(param_2 + (longlong)&p_Var1->pszImage),local_res8,
                                  param_3 - (int)p_Var1);
        if (uVar3 == 0) {
          p_Var1 = (_CRYPT_IMAGE_REF *)p_Var6->pszImage;
          p_Var5 = (_CRYPT_IMAGE_REF *)((longlong)&p_Var1->pszImage + (ulonglong)local_res8[0] + 2);
          if ((p_Var1 <= p_Var5) && (p_Var5 <= p_Var2)) {
            pWVar4 = (PWSTR)(param_2 + (longlong)&p_Var1->pszImage);
            goto LAB_180006eed;
          }
        }
      }
      p_Var6 = *param_1;
      p_Var1 = (_CRYPT_IMAGE_REF *)p_Var6->pszImage;
      if (p_Var1 != (_CRYPT_IMAGE_REF *)0xffffffffffffffff) {
        if (p_Var1 < p_Var2) {
          local_res8[0] = 0;
          uVar3 = SzString_CbLength((ushort *)(param_2 + (longlong)&p_Var1->pszImage),local_res8,
                                    param_3 - (int)p_Var1);
          if (uVar3 == 0) {
            p_Var1 = (_CRYPT_IMAGE_REF *)p_Var6->pszImage;
            p_Var5 = (_CRYPT_IMAGE_REF *)
                     ((longlong)&p_Var1->pszImage + (ulonglong)local_res8[0] + 2);
            if ((p_Var1 <= p_Var5) && (p_Var5 <= p_Var2)) {
              pWVar4 = (PWSTR)(param_2 + (longlong)&p_Var1->pszImage);
              goto LAB_180006eae;
            }
          }
        }
        goto LAB_180006fc9;
      }
      pWVar4 = (PWSTR)0x0;
LAB_180006eae:
      p_Var6->pszImage = pWVar4;
      if (pWVar4 != (PWSTR)0x0) {
        uVar7 = ((int)param_2 - (int)pWVar4) + param_3;
        if (uVar7 == 1) {
          return 0x7a;
        }
        uVar3 = SzString_CchLength((ushort *)pWVar4,local_res8,uVar7 >> 1);
        if (uVar3 != 0) {
          return uVar3;
        }
      }
    }
LAB_180006eaa:
    uVar3 = 0;
  }
  else {
    if (((p_Var6 < p_Var2) && (p_Var6 <= p_Var6 + 1)) && (p_Var6 + 1 <= p_Var2)) {
      p_Var6 = (_CRYPT_IMAGE_REF *)(param_2 + (longlong)&p_Var6->pszImage);
      goto LAB_180006e9b;
    }
LAB_180006fc9:
    uVar3 = 0x54f;
  }
  return uVar3;
}



===== IoUnpack_SG_SzString @ 180006fe0 =====

/* unsigned long __cdecl IoUnpack_SG_SzString(unsigned short * __ptr64 * __ptr64,unsigned char *
   __ptr64,unsigned long,unsigned char * __ptr64) */

ulong __cdecl IoUnpack_SG_SzString(ushort **param_1,uchar *param_2,ulong param_3,uchar *param_4)

{
  ulong uVar1;
  ushort *puVar2;
  ushort *puVar3;
  uint uVar4;
  uchar *local_res20;
  
  puVar2 = *param_1;
  if (puVar2 == (ushort *)0xffffffffffffffff) {
    puVar2 = (ushort *)0x0;
    local_res20 = param_4;
LAB_180007051:
    *param_1 = puVar2;
    if (puVar2 != (ushort *)0x0) {
      uVar4 = ((int)param_2 - (int)puVar2) + param_3;
      if (uVar4 == 1) {
        return 0x7a;
      }
      uVar1 = SzString_CchLength(puVar2,(ulong *)&local_res20,uVar4 >> 1);
      if (uVar1 != 0) {
        return uVar1;
      }
    }
    return 0;
  }
  if (puVar2 < (ushort *)(ulonglong)param_3) {
    local_res20 = (uchar *)((ulonglong)param_4 & 0xffffffff00000000);
    uVar1 = SzString_CbLength((ushort *)((longlong)puVar2 + (longlong)param_2),(ulong *)&local_res20
                              ,param_3 - (int)puVar2);
    if (uVar1 == 0) {
      puVar2 = *param_1;
      puVar3 = (ushort *)(((ulonglong)local_res20 & 0xffffffff) + 2 + (longlong)puVar2);
      if ((puVar2 <= puVar3) && (puVar3 <= (ushort *)(ulonglong)param_3)) {
        puVar2 = (ushort *)((longlong)puVar2 + (longlong)param_2);
        goto LAB_180007051;
      }
    }
  }
  return 0x54f;
}



===== IoCopy_SzString @ 1800070b0 =====

/* unsigned long __cdecl IoCopy_SzString(unsigned short * __ptr64,unsigned long * __ptr64,unsigned
   char * __ptr64) */

ulong __cdecl IoCopy_SzString(ushort *param_1,ulong *param_2,uchar *param_3)

{
  int iVar1;
  ulong uVar2;
  ulong local_res8 [2];
  
  local_res8[0] = 0;
  if (param_1 == (ushort *)0x0) {
    uVar2 = 0x57;
  }
  else {
    if (param_2 != (ulong *)0x0) {
      *param_2 = 0;
    }
    uVar2 = SzString_CchLength(param_1,local_res8,0);
    if (uVar2 == 0) {
      iVar1 = local_res8[0] * 2;
      if (param_3 != (uchar *)0x0) {
        memcpy(param_3,param_1,(ulonglong)(local_res8[0] + 1) * 2);
      }
      if (param_2 != (ulong *)0x0) {
        *param_2 = iVar1 + 9U & 0xfffffff8;
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}



===== SzString_CbLength @ 180007150 =====

/* unsigned long __cdecl SzString_CbLength(unsigned short const * __ptr64,unsigned long *
   __ptr64,unsigned long) */

ulong __cdecl SzString_CbLength(ushort *param_1,ulong *param_2,ulong param_3)

{
  ulong uVar1;
  
  if (param_3 == 1) {
    return 0x7a;
  }
  uVar1 = SzString_CchLength(param_1,param_2,param_3 >> 1);
  if ((uVar1 == 0) && (param_2 != (ulong *)0x0)) {
    *param_2 = *param_2 * 2;
  }
  return uVar1;
}



===== SzString_CchLength @ 180007190 =====

/* unsigned long __cdecl SzString_CchLength(unsigned short const * __ptr64,unsigned long *
   __ptr64,unsigned long) */

ulong __cdecl SzString_CchLength(ushort *param_1,ulong *param_2,ulong param_3)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  ulong uVar4;
  ulong uVar5;
  
  uVar5 = 0;
  uVar4 = 0;
  bVar1 = false;
  if (param_2 != (ulong *)0x0) {
    *param_2 = 0;
  }
  if (param_1 == (ushort *)0x0) {
    return 0x57;
  }
  uVar2 = 0xffff;
  if (param_3 != 0) {
    uVar2 = param_3;
  }
  uVar3 = 0;
  do {
    if (uVar2 <= uVar3) {
LAB_1800071eb:
      if (bVar1) {
        if (param_2 != (ulong *)0x0) {
          *param_2 = uVar4;
        }
      }
      else {
        uVar5 = 0x7a;
      }
      return uVar5;
    }
    if (param_1[uVar3] == 0) {
      bVar1 = true;
      goto LAB_1800071eb;
    }
    uVar4 = uVar4 + 1;
    uVar3 = uVar3 + 1;
  } while( true );
}



===== BCryptDestroySecret @ 180007240 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

NTSTATUS __stdcall BCryptDestroySecret(BCRYPT_SECRET_HANDLE hSecret)

{
  uint *puVar1;
  int iVar2;
  undefined8 in_RDX;
  undefined8 uVar3;
  undefined8 in_R8;
  ulonglong _Size;
  undefined1 uVar4;
  
                    /* 0x7240  17  BCryptDestroySecret */
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    in_RDX = 0x20;
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x20,in_R8,hSecret);
  }
  if (((hSecret == (BCRYPT_SECRET_HANDLE)0x0) || (*(uint *)hSecret < 0x18)) ||
     (*(int *)((longlong)hSecret + 4) != 0x55555554)) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff8;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return -0x3ffffff8;
    }
    uVar4 = 0x36;
  }
  else {
    puVar1 = *(uint **)((longlong)hSecret + 8);
    if (puVar1[9] == 4) {
      iVar2 = (**(code **)(puVar1 + 0x1a))(*(undefined8 *)((longlong)hSecret + 0x10));
      if (iVar2 < 0) {
        DebugTraceError((char)iVar2,"Status",
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",0x51);
        return iVar2;
      }
      _Size = (ulonglong)*(uint *)hSecret;
      uVar3 = 0;
      memset(hSecret,0,_Size);
      BCryptFree((longlong)hSecret);
      if (iVar2 == 0) {
        DecrementReferenceCount(puVar1,uVar3,_Size);
        return 0;
      }
      return iVar2;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff8;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return -0x3ffffff8;
    }
    uVar4 = 0x48;
  }
  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),in_RDX,in_R8,"Status",8,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar4);
  return -0x3ffffff8;
}



===== DecrementReferenceCount @ 180007380 =====

int DecrementReferenceCount(uint *param_1,undefined8 param_2,undefined8 param_3)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  
  LOCK();
  puVar1 = param_1 + 4;
  uVar2 = *puVar1;
  *puVar1 = *puVar1 - 1;
  UNLOCK();
  if (uVar2 == 1) {
    iVar3 = DestroyAlgorithmHeader(param_1,param_2,param_3);
    return iVar3;
  }
  return 0;
}



===== BCryptFree @ 1800073a0 =====

void BCryptFree(longlong param_1)

{
  if (param_1 == 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0001800073b7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,param_1);
  return;
}



===== IoPack_Configuration_ParamBlock @ 1800073cc =====

/* unsigned long __cdecl IoPack_Configuration_ParamBlock(unsigned long,unsigned short const *
   __ptr64,unsigned long,unsigned short const * __ptr64,unsigned short const * __ptr64,unsigned
   short const * __ptr64,unsigned long,struct _CRYPT_CONTEXT_CONFIG * __ptr64,struct
   _CRYPT_CONTEXT_FUNCTION_CONFIG * __ptr64,unsigned long,unsigned char * __ptr64,void *
   __ptr64,unsigned long * __ptr64,unsigned char * __ptr64) */

ulong __cdecl
IoPack_Configuration_ParamBlock
          (ulong param_1,ushort *param_2,ulong param_3,ushort *param_4,ushort *param_5,
          ushort *param_6,ulong param_7,_CRYPT_CONTEXT_CONFIG *param_8,
          _CRYPT_CONTEXT_FUNCTION_CONFIG *param_9,ulong param_10,uchar *param_11,void *param_12,
          ulong *param_13,uchar *param_14)

{
  longlong *plVar1;
  longlong *plVar2;
  int iVar3;
  longlong lVar4;
  ulong *puVar5;
  ulong uVar6;
  ulonglong uVar7;
  ulong *puVar8;
  uchar *puVar9;
  uchar *_Dst;
  uchar *_Dst_00;
  ulong local_res10 [2];
  ulong local_res18;
  ushort *local_res20;
  ulong local_68 [2];
  uchar *local_60;
  ulong *local_58;
  void *local_50;
  
  local_58 = (ulong *)0x0;
  _Dst_00 = (uchar *)0x0;
  local_68[0] = 0;
  _Dst = (uchar *)0x0;
  local_60 = (uchar *)0x0;
  puVar5 = (ulong *)0x0;
  puVar9 = (uchar *)0x0;
  local_50 = (void *)0x0;
  uVar7 = 0x68;
  if (param_13 != (ulong *)0x0) {
    *param_13 = 0;
  }
  local_res18 = param_3;
  local_res20 = param_4;
  if (param_2 != (ushort *)0x0) {
    local_res10[0] = 0;
    local_50 = (void *)(-(ulonglong)(param_14 != (uchar *)0x0) & (ulonglong)(param_14 + 0x68));
    uVar6 = SzString_CchLength(param_2,local_res10,0);
    if (uVar6 != 0) {
      return uVar6;
    }
    iVar3 = local_res10[0] * 2;
    if (local_50 != (void *)0x0) {
      memcpy(local_50,param_2,(ulonglong)(local_res10[0] + 1) * 2);
    }
    uVar7 = (ulonglong)((iVar3 + 9U & 0xfffffff8) + 0x68);
  }
  if (local_res20 != (ushort *)0x0) {
    if (param_14 != (uchar *)0x0) {
      _Dst_00 = param_14 + uVar7;
    }
    local_res10[0] = 0;
    uVar6 = SzString_CchLength(local_res20,local_res10,0);
    if (uVar6 != 0) {
      return uVar6;
    }
    iVar3 = local_res10[0] * 2;
    if (_Dst_00 != (uchar *)0x0) {
      memcpy(_Dst_00,local_res20,(ulonglong)(local_res10[0] + 1) * 2);
    }
    uVar7 = (ulonglong)((int)uVar7 + (iVar3 + 9U & 0xfffffff8));
  }
  if (param_5 != (ushort *)0x0) {
    if (param_14 != (uchar *)0x0) {
      _Dst = param_14 + uVar7;
    }
    local_res10[0] = 0;
    uVar6 = SzString_CchLength(param_5,local_res10,0);
    if (uVar6 != 0) {
      return uVar6;
    }
    iVar3 = local_res10[0] * 2;
    if (_Dst != (uchar *)0x0) {
      memcpy(_Dst,param_5,(ulonglong)(local_res10[0] + 1) * 2);
    }
    uVar7 = (ulonglong)((int)uVar7 + (iVar3 + 9U & 0xfffffff8));
  }
  if (param_6 != (ushort *)0x0) {
    if (param_14 != (uchar *)0x0) {
      puVar9 = param_14 + uVar7;
    }
    uVar6 = IoCopy_SzString(param_6,local_68,puVar9);
    if (uVar6 != 0) {
      return uVar6;
    }
    uVar7 = (ulonglong)((int)uVar7 + local_68[0]);
  }
  if (param_8 == (_CRYPT_CONTEXT_CONFIG *)0x0) {
LAB_180007467:
    if (param_9 != (_CRYPT_CONTEXT_FUNCTION_CONFIG *)0x0) {
      if (param_14 == (uchar *)0x0) {
        puVar8 = (ulong *)0x0;
      }
      else {
        puVar8 = (ulong *)(param_14 + uVar7);
      }
      uVar6 = param_9->dwFlags;
      local_58 = puVar8;
      iVar3 = ValidateConfigurationFlags(0x10030,0,uVar6);
      if (iVar3 == 0) goto LAB_180007722;
      if (puVar8 != (ulong *)0x0) {
        *puVar8 = uVar6;
      }
      uVar7 = (ulonglong)((int)uVar7 + 8);
    }
    uVar6 = (ulong)uVar7;
    if (param_11 != (uchar *)0x0) {
      if (param_14 == (uchar *)0x0) {
        local_60 = (uchar *)0x0;
      }
      else {
        local_60 = param_14 + uVar7;
        if (local_60 != (uchar *)0x0) {
          memcpy(local_60,param_11,(ulonglong)param_10);
        }
      }
      uVar6 = uVar6 + (param_10 + 7 & 0xfffffff8);
    }
    if (param_14 != (uchar *)0x0) {
      plVar1 = (longlong *)(param_14 + 0x48);
      *(ulong *)(param_14 + 8) = param_1;
      plVar2 = (longlong *)(param_14 + 0x40);
      *(ulong *)(param_14 + 0x18) = local_res18;
      *(ulong *)(param_14 + 0x38) = param_7;
      *plVar1 = (longlong)local_58;
      *(uchar **)(param_14 + 0x58) = local_60;
      *(void **)(param_14 + 0x60) = param_12;
      *plVar2 = (longlong)puVar5;
      *(ulong *)(param_14 + 0x50) = param_10;
      if (local_50 == (void *)0x0) {
        lVar4 = -1;
      }
      else {
        lVar4 = (longlong)local_50 - (longlong)param_14;
      }
      *(longlong *)(param_14 + 0x10) = lVar4;
      if (_Dst_00 == (uchar *)0x0) {
        lVar4 = -1;
      }
      else {
        lVar4 = (longlong)_Dst_00 - (longlong)param_14;
      }
      *(longlong *)(param_14 + 0x20) = lVar4;
      if (_Dst == (uchar *)0x0) {
        lVar4 = -1;
      }
      else {
        lVar4 = (longlong)_Dst - (longlong)param_14;
      }
      *(longlong *)(param_14 + 0x28) = lVar4;
      if (puVar9 == (uchar *)0x0) {
        lVar4 = -1;
      }
      else {
        lVar4 = (longlong)puVar9 - (longlong)param_14;
      }
      *(longlong *)(param_14 + 0x30) = lVar4;
      if (plVar2 != (longlong *)0x0) {
        if (puVar5 == (ulong *)0x0) {
          *plVar2 = -1;
        }
        else {
          *plVar2 = (longlong)puVar5 - (longlong)param_14;
        }
      }
      if (plVar1 != (longlong *)0x0) {
        if (*plVar1 == 0) {
          *plVar1 = -1;
        }
        else {
          *plVar1 = *plVar1 - (longlong)param_14;
        }
      }
      IoPack_Buffer((uchar **)(param_14 + 0x58),param_14);
    }
    if (param_13 != (ulong *)0x0) {
      *param_13 = uVar6;
    }
    uVar6 = 0;
  }
  else {
    if (param_14 != (uchar *)0x0) {
      puVar5 = (ulong *)(param_14 + uVar7);
    }
    uVar6 = param_8->dwFlags;
    iVar3 = ValidateConfigurationFlags(0x10010,param_1,uVar6);
    if (iVar3 != 0) {
      if (puVar5 != (ulong *)0x0) {
        *puVar5 = uVar6;
      }
      uVar7 = (ulonglong)((int)uVar7 + 8);
      goto LAB_180007467;
    }
LAB_180007722:
    uVar6 = 0x3ec;
  }
  return uVar6;
}



===== IoCallKernelDriverQueryLoop @ 180007780 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl IoCallKernelDriverQueryLoop(unsigned long,unsigned char * __ptr64,unsigned
   long,unsigned char * __ptr64 * __ptr64,unsigned long * __ptr64,int * __ptr64) */

long __cdecl
IoCallKernelDriverQueryLoop
          (ulong param_1,uchar *param_2,ulong param_3,uchar **param_4,ulong *param_5,int *param_6)

{
  uchar *puVar1;
  long lVar2;
  int iVar3;
  int *piVar4;
  int *_Dst;
  uint uVar5;
  uchar *puVar6;
  undefined1 auStackY_d8 [32];
  ulong local_88 [2];
  uint *local_80;
  long local_78;
  ulong local_74;
  ulong local_70;
  uint local_6c;
  undefined8 local_68;
  ulonglong uStack_60;
  uchar *local_58;
  int local_50 [2];
  uchar local_48 [8];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_d8;
  _Dst = (int *)0x0;
  local_80 = param_5;
  local_88[0] = 0;
  if (param_6 != (int *)0x0) {
    *param_6 = 0;
  }
  local_74 = param_3;
  local_70 = param_1;
  local_58 = param_2;
  if (param_4 == (uchar **)0x0) {
    lVar2 = IoCallKernelDriver(param_1,param_2,param_3,(uchar *)0x0,local_88);
    if (lVar2 == -0x3fffffdd) {
      *param_5 = local_88[0];
    }
    return lVar2;
  }
  piVar4 = (int *)*param_4;
  if (piVar4 == (int *)0x0) {
    local_88[0] = 0x180;
  }
  else {
    local_88[0] = *param_5;
    _Dst = piVar4;
  }
  do {
    puVar1 = local_58;
    if (piVar4 == (int *)0x0) {
      if (_Dst != (int *)0x0) {
        BCryptFree((longlong)_Dst);
      }
      _Dst = (int *)RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,
                                    local_88[0]);
      if (_Dst == (int *)0x0) {
        return -0x3fffffe9;
      }
    }
    local_78 = 0;
    local_68 = 0;
    uStack_60 = 0;
    if ((puVar1 != (uchar *)0x0) && (local_74 < 8)) goto LAB_18000797f;
    puVar6 = local_48;
    if (puVar1 != (uchar *)0x0) {
      puVar6 = puVar1;
    }
    local_6c = 8;
    if (puVar1 != (uchar *)0x0) {
      local_6c = local_74;
    }
    puVar6[0] = 'M';
    puVar6[1] = '<';
    puVar6[2] = '+';
    puVar6[3] = '\x1a';
    *(ulong *)(puVar6 + 4) = local_70;
    if ((_Dst == (int *)0x0) || (local_88[0] < 8)) {
      piVar4 = local_50;
    }
    else {
      piVar4 = _Dst;
    }
    if (g_hIoDevice == (void *)0x0) {
      EnterCriticalSection(&g_csIoInitialize);
      if (g_hIoDevice == (void *)0x0) {
        local_78 = _IoOpenDevice();
      }
      LeaveCriticalSection(&g_csIoInitialize);
      iVar3 = local_78;
      if (-1 < local_78) goto LAB_1800078bd;
      goto LAB_180007a0b;
    }
LAB_1800078bd:
    iVar3 = NtDeviceIoControlFile(g_hIoDevice,0,0,0);
    uVar5 = (uint)uStack_60;
    if (iVar3 < 0) {
      if (iVar3 != -0x3fffffdd) {
        if (iVar3 != -0x7ffffffb) {
LAB_180007a16:
          *local_80 = local_88[0];
          if (iVar3 < 0) {
LAB_18000798e:
            if ((_Dst != (int *)0x0) && (*param_4 == (uchar *)0x0)) {
              BCryptFree((longlong)_Dst);
            }
          }
          else {
LAB_180007938:
            if (param_6 != (int *)0x0) {
              *param_6 = (uint)(*param_4 == (uchar *)0x0);
            }
            *param_4 = (uchar *)_Dst;
          }
          return iVar3;
        }
        if (3 < uVar5) {
          iVar3 = *piVar4;
          if (iVar3 == -0x3fffffdd) {
            if (uVar5 == 8) {
              local_88[0] = piVar4[1];
              goto LAB_180007a0b;
            }
          }
          else if (uVar5 == 4) {
LAB_180007a0b:
            if (iVar3 == -0x3fffffdd) goto LAB_180007a37;
            goto LAB_180007a16;
          }
        }
      }
LAB_18000797f:
      iVar3 = -0x3fffff1b;
      *local_80 = local_88[0];
      goto LAB_18000798e;
    }
    if ((_Dst != (int *)0x0) && (uVar5 <= local_88[0])) {
      if (piVar4 == local_50) {
        memcpy(_Dst,piVar4,uStack_60 & 0xffffffff);
      }
      iVar3 = 0;
      *local_80 = uVar5;
      goto LAB_180007938;
    }
    iVar3 = -0x3fffffdd;
    local_88[0] = uVar5;
LAB_180007a37:
    if (*param_4 != (uchar *)0x0) goto LAB_180007a16;
    piVar4 = (int *)0x0;
  } while( true );
}



===== IoUnpack_ContextFunctionProviders @ 180007ac4 =====

/* unsigned long __cdecl IoUnpack_ContextFunctionProviders(struct _CRYPT_CONTEXT_FUNCTION_PROVIDERS
   * __ptr64 * __ptr64,unsigned char * __ptr64,unsigned long) */

ulong __cdecl
IoUnpack_ContextFunctionProviders
          (_CRYPT_CONTEXT_FUNCTION_PROVIDERS **param_1,uchar *param_2,ulong param_3)

{
  ulong uVar1;
  uchar *in_stack_ffffffffffffffe8;
  
  if (param_2 != (uchar *)0x0) {
    if ((param_2 + 0x10 < param_2) || (param_2 + param_3 < param_2 + 0x10)) {
      return 0x54f;
    }
    uVar1 = IoUnpack_SG_SzStringArray
                      ((ushort ***)(param_2 + 8),*(ulong *)param_2,param_2,param_3,
                       in_stack_ffffffffffffffe8);
    if (uVar1 != 0) {
      uVar1 = IoUnpack_SG_SzStringArray
                        ((ushort ***)(param_2 + 8),*(ulong *)param_2,param_2,param_3,
                         in_stack_ffffffffffffffe8);
      return uVar1;
    }
  }
  return 0;
}



===== WinErrorToNtStatus @ 180007b40 =====

/* long __cdecl WinErrorToNtStatus(unsigned long) */

long __cdecl WinErrorToNtStatus(ulong param_1)

{
  int iVar1;
  ulong uVar2;
  
  if (param_1 < 0x104) {
    if (param_1 == 0x103) {
      return -0x7fffffe6;
    }
    switch(param_1) {
    case 0:
      return 0;
    case 1:
      return -0x3fffff51;
    case 2:
      return -0x3fffffcc;
    case 3:
      return -0x3fffffc6;
    case 5:
      return -0x3fffffde;
    case 6:
      return -0x3ffffff8;
    case 8:
    case 0xe:
      return -0x3fffffe9;
    case 0xd:
    case 0x17:
      return -0x3fffffc2;
    case 0x12:
      return -0x7ffffffa;
    case 0x1f:
      return -0x3fffffff;
    case 0x20:
      return -0x3fffffbd;
    case 0x32:
      return -0x3ffffffe;
    case 0x57:
      return -0x3ffffff3;
    case 0x7a:
      return -0x3fffffdd;
    case 0x7b:
      return -0x3fffffcd;
    case 0xa1:
      return -0x3fffffc7;
    case 0xb7:
      return -0x3fffffcb;
    case 0xea:
      return -0x7ffffffb;
    }
  }
  else if (param_1 < 0x491) {
    if (param_1 == 0x490) {
      return -0x3ffffddb;
    }
    if (param_1 == 0x250) {
      return -0x3ffffde5;
    }
    if (param_1 == 0x3e6) {
      return -0x3ffffffb;
    }
    if (param_1 == 0x3ec) {
      return -0x3ffffff3;
    }
  }
  else {
    if (param_1 == 0x491) {
      return -0x3ffffd8e;
    }
    if (param_1 == 0x4db) {
      return -0x3ffffea0;
    }
    if (param_1 == 0x54f) {
      return -0x3fffff1b;
    }
  }
  iVar1 = RtlNtStatusToDosError(param_1);
  uVar2 = 0xc0000001;
  if (iVar1 != 0x13d) {
    uVar2 = param_1;
  }
  return uVar2;
}



===== StringCchCopyW @ 180007e4c =====

HRESULT __stdcall StringCchCopyW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPCWSTR pszSrc)

{
  wchar_t wVar1;
  uint uVar2;
  STRSAFE_LPWSTR pwVar3;
  longlong lVar4;
  longlong lVar5;
  
  if (cchDest - 1 < 0x7fffffff) {
    lVar4 = 0x7ffffffe - cchDest;
    lVar5 = (longlong)pszSrc - (longlong)pszDest;
    do {
      if ((lVar4 + cchDest == 0) ||
         (wVar1 = *(wchar_t *)(lVar5 + (longlong)pszDest), wVar1 == L'\0')) break;
      *pszDest = wVar1;
      pszDest = pszDest + 1;
      cchDest = cchDest - 1;
    } while (cchDest != 0);
    pwVar3 = pszDest + -1;
    if (cchDest != 0) {
      pwVar3 = pszDest;
    }
    *pwVar3 = L'\0';
    uVar2 = ~-(uint)(cchDest != 0) & 0x8007007a;
  }
  else {
    uVar2 = 0x80070057;
    if (cchDest != 0) {
      *pszDest = L'\0';
      return -0x7ff8ffa9;
    }
  }
  return uVar2;
}



===== IoUnpack_PropertyRef @ 180007ec0 =====

/* unsigned long __cdecl IoUnpack_PropertyRef(struct _CRYPT_PROPERTY_REF * __ptr64 *
   __ptr64,unsigned char * __ptr64,unsigned long) */

ulong __cdecl IoUnpack_PropertyRef(_CRYPT_PROPERTY_REF **param_1,uchar *param_2,ulong param_3)

{
  ulong uVar1;
  _CRYPT_PROPERTY_REF *p_Var2;
  uchar *in_R9;
  uchar *in_stack_ffffffffffffffe8;
  
  p_Var2 = *param_1;
  if (p_Var2 == (_CRYPT_PROPERTY_REF *)0xffffffffffffffff) {
    p_Var2 = (_CRYPT_PROPERTY_REF *)0x0;
  }
  else {
    if ((((_CRYPT_PROPERTY_REF *)(ulonglong)param_3 <= p_Var2) || (p_Var2 + 1 < p_Var2)) ||
       ((_CRYPT_PROPERTY_REF *)(ulonglong)param_3 < p_Var2 + 1)) {
      return 0x54f;
    }
    p_Var2 = (_CRYPT_PROPERTY_REF *)(param_2 + (longlong)&p_Var2->pszProperty);
  }
  *param_1 = p_Var2;
  if (p_Var2 == (_CRYPT_PROPERTY_REF *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = IoUnpack_SG_SzString((ushort **)p_Var2,param_2,param_3,in_R9);
    if (uVar1 == 0) {
      uVar1 = IoUnpack_SG_Buffer(&(*param_1)->pbValue,(*param_1)->cbValue,param_2,param_3,
                                 in_stack_ffffffffffffffe8);
    }
  }
  return uVar1;
}



===== IoCallKernelDriver @ 180007f50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl IoCallKernelDriver(unsigned long,unsigned char * __ptr64,unsigned long,unsigned char
   * __ptr64,unsigned long * __ptr64) */

long __cdecl
IoCallKernelDriver(ulong param_1,uchar *param_2,ulong param_3,uchar *param_4,ulong *param_5)

{
  int iVar1;
  long lVar2;
  uchar *puVar3;
  ulong uVar4;
  int *_Src;
  uint uVar5;
  undefined1 auStack_b8 [32];
  undefined8 *local_98;
  undefined4 local_90;
  uchar *local_88;
  ulong local_80;
  int *local_78;
  uint local_70;
  undefined8 local_68;
  ulonglong uStack_60;
  int local_58 [2];
  uchar local_50 [8];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_b8;
  lVar2 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if ((param_2 == (uchar *)0x0) || (7 < param_3)) {
    puVar3 = local_50;
    if (param_2 != (uchar *)0x0) {
      puVar3 = param_2;
    }
    uVar4 = 8;
    if (param_2 != (uchar *)0x0) {
      uVar4 = param_3;
    }
    puVar3[0] = 'M';
    puVar3[1] = '<';
    puVar3[2] = '+';
    puVar3[3] = '\x1a';
    *(ulong *)(puVar3 + 4) = param_1;
    if (param_5 == (ulong *)0x0) {
      uVar5 = 0;
    }
    else {
      uVar5 = *param_5;
    }
    if ((param_4 == (uchar *)0x0) || (uVar5 < 8)) {
      uVar5 = 8;
      _Src = local_58;
    }
    else {
      _Src = (int *)param_4;
    }
    if (g_hIoDevice == (void *)0x0) {
      EnterCriticalSection(&g_csIoInitialize);
      if (g_hIoDevice == (void *)0x0) {
        lVar2 = _IoOpenDevice();
      }
      LeaveCriticalSection(&g_csIoInitialize);
      if (lVar2 < 0) {
        return lVar2;
      }
    }
    local_98 = &local_68;
    local_90 = 0x390400;
    local_88 = puVar3;
    local_80 = uVar4;
    local_78 = _Src;
    local_70 = uVar5;
    iVar1 = NtDeviceIoControlFile(g_hIoDevice,0,0,0);
    uVar5 = (uint)uStack_60;
    if (-1 < iVar1) {
      if (param_5 != (ulong *)0x0) {
        if ((param_4 == (uchar *)0x0) || (*param_5 < uVar5)) {
          *param_5 = uVar5;
          return -0x3fffffdd;
        }
        if (_Src == local_58) {
          memcpy(param_4,_Src,uStack_60 & 0xffffffff);
        }
        *param_5 = uVar5;
      }
      return 0;
    }
    if (iVar1 != -0x3fffffdd) {
      if (iVar1 != -0x7ffffffb) {
        return iVar1;
      }
      if (3 < uVar5) {
        iVar1 = *_Src;
        if (iVar1 != -0x3fffffdd) {
          if (uVar5 != 4) {
            iVar1 = -0x3fffff1b;
          }
          return iVar1;
        }
        if (uVar5 == 8) {
          if (param_5 == (ulong *)0x0) {
            return -0x3fffffdd;
          }
          *param_5 = _Src[1];
          return -0x3fffffdd;
        }
      }
    }
  }
  return -0x3fffff1b;
}



===== _IoOpenDevice @ 180008154 =====

/* long __cdecl _IoOpenDevice(void) */

long __cdecl _IoOpenDevice(void)

{
  long lVar1;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_34 = 0;
  local_1c = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  RtlInitUnicodeString(&local_58,L"\\Device\\KsecDD");
  local_30 = 0;
  local_28 = &local_58;
  local_20 = 0;
  local_38 = 0x30;
  local_18 = 0;
  uStack_10 = 0;
  lVar1 = NtOpenFile(&g_hIoDevice,0x100003,&local_38,&local_48,7,0x20);
  return lVar1;
}



===== IoPack_Buffer @ 1800081ec =====

/* void __cdecl IoPack_Buffer(unsigned char * __ptr64 * __ptr64,unsigned char * __ptr64) */

void __cdecl IoPack_Buffer(uchar **param_1,uchar *param_2)

{
  if (param_1 != (uchar **)0x0) {
    if (*param_1 != (uchar *)0x0) {
      *param_1 = *param_1 + -(longlong)param_2;
      return;
    }
    *param_1 = (uchar *)0xffffffffffffffff;
  }
  return;
}



===== IoUnpack_SG_Buffer @ 180008210 =====

/* unsigned long __cdecl IoUnpack_SG_Buffer(unsigned char * __ptr64 * __ptr64,unsigned long,unsigned
   char * __ptr64,unsigned long,unsigned char * __ptr64) */

ulong __cdecl
IoUnpack_SG_Buffer(uchar **param_1,ulong param_2,uchar *param_3,ulong param_4,uchar *param_5)

{
  uchar *puVar1;
  uchar *puVar2;
  
  puVar2 = (uchar *)0x0;
  if (param_1 == (uchar **)0x0) {
    if ((param_3 != (uchar *)0x0) &&
       ((param_3 + param_2 < param_3 || (param_3 + param_4 < param_3 + param_2)))) {
      return 0x54f;
    }
  }
  else {
    puVar1 = *param_1;
    if (puVar1 != (uchar *)0xffffffffffffffff) {
      if (param_2 == 0) {
        return 0x54f;
      }
      if ((uchar *)(ulonglong)param_4 <= puVar1) {
        return 0x54f;
      }
      if (puVar1 + param_2 < puVar1) {
        return 0x54f;
      }
      if ((uchar *)(ulonglong)param_4 < puVar1 + param_2) {
        return 0x54f;
      }
      puVar2 = puVar1 + (longlong)param_3;
    }
    *param_1 = puVar2;
  }
  return 0;
}



===== IoPack_Registration_ParamBlock @ 180008270 =====

/* unsigned long __cdecl IoPack_Registration_ParamBlock(unsigned short const * __ptr64,unsigned
   long,unsigned long,unsigned long,struct _CRYPT_PROVIDER_REG * __ptr64,unsigned long *
   __ptr64,unsigned char * __ptr64) */

ulong __cdecl
IoPack_Registration_ParamBlock
          (ushort *param_1,ulong param_2,ulong param_3,ulong param_4,_CRYPT_PROVIDER_REG *param_5,
          ulong *param_6,uchar *param_7)

{
  int iVar1;
  ulong *puVar2;
  uchar *puVar3;
  ulong uVar4;
  _CRYPT_PROVIDER_REG *p_Var5;
  uint uVar6;
  void *_Dst;
  longlong lVar7;
  ulong local_res8 [2];
  ulong local_res10;
  
  puVar3 = param_7;
  puVar2 = param_6;
  _Dst = (void *)0x0;
  local_res8[0] = 0;
  p_Var5 = (_CRYPT_PROVIDER_REG *)0x0;
  uVar6 = 0x28;
  if (param_6 != (ulong *)0x0) {
    *param_6 = 0;
  }
  local_res10 = param_2;
  if (param_1 != (ushort *)0x0) {
    param_6._0_4_ = 0;
    _Dst = (void *)(-(ulonglong)(param_7 != (uchar *)0x0) & (ulonglong)(param_7 + 0x28));
    uVar4 = SzString_CchLength(param_1,(ulong *)&param_6,0);
    if (uVar4 != 0) {
      return uVar4;
    }
    iVar1 = (int)param_6 * 2;
    if (_Dst != (void *)0x0) {
      memcpy(_Dst,param_1,(ulonglong)((int)param_6 + 1) * 2);
    }
    uVar6 = (iVar1 + 9U & 0xfffffff8) + 0x28;
  }
  if (param_5 != (_CRYPT_PROVIDER_REG *)0x0) {
    if (puVar3 != (uchar *)0x0) {
      p_Var5 = (_CRYPT_PROVIDER_REG *)(puVar3 + uVar6);
    }
    uVar4 = IoCopy_ProviderReg(param_5,local_res8,(uchar *)p_Var5);
    if (uVar4 != 0) {
      return uVar4;
    }
    uVar6 = uVar6 + local_res8[0];
  }
  if (puVar3 != (uchar *)0x0) {
    *(_CRYPT_PROVIDER_REG **)(puVar3 + 0x20) = p_Var5;
    *(ulong *)(puVar3 + 0x10) = local_res10;
    *(ulong *)(puVar3 + 0x14) = param_3;
    *(ulong *)(puVar3 + 0x18) = param_4;
    if (_Dst == (void *)0x0) {
      lVar7 = -1;
    }
    else {
      lVar7 = (longlong)_Dst - (longlong)puVar3;
    }
    *(longlong *)(puVar3 + 8) = lVar7;
    IoPack_ProviderReg((_CRYPT_PROVIDER_REG **)(puVar3 + 0x20),puVar3);
  }
  if (puVar2 != (ulong *)0x0) {
    *puVar2 = uVar6;
  }
  return 0;
}



===== BCryptQueryProviderRegistration @ 1800083a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

NTSTATUS __stdcall
BCryptQueryProviderRegistration
          (LPCWSTR pszProvider,ULONG dwMode,ULONG dwInterface,ULONG *pcbBuffer,
          PCRYPT_PROVIDER_REG *ppBuffer)

{
  int iVar1;
  ulong uVar2;
  int iVar3;
  uchar *puVar4;
  _CRYPT_PROVIDER_REG **pp_Var5;
  uint uVar6;
  PCRYPT_PROVIDER_REG *pp_Var7;
  undefined1 auStackY_1a8 [32];
  ulong local_168;
  int local_164 [3];
  uchar local_158 [256];
  ulonglong local_58;
  
                    /* 0x83a0  47  BCryptQueryProviderRegistration */
  local_58 = __security_cookie ^ (ulonglong)auStackY_1a8;
  puVar4 = local_158;
  local_164[0] = 0;
  iVar3 = 0;
  if (((((pszProvider == (LPCWSTR)0x0) || (*pszProvider == L'\0')) || (dwMode == 0)) ||
      (((dwMode != 1 && (dwMode != 2)) && ((dwMode != 3 && (dwMode != 4)))))) ||
     ((iVar1 = ValidateInterfaceId(dwInterface,1), iVar1 == 0 || (pcbBuffer == (ULONG *)0x0)))) {
    uVar2 = 0x57;
LAB_180008542:
    if (local_164[0] != 0) {
      BCryptFree((longlong)*ppBuffer);
      *ppBuffer = (PCRYPT_PROVIDER_REG)0x0;
    }
    if (iVar3 < 0) goto LAB_1800084d3;
  }
  else {
    local_168 = 0;
    uVar2 = SzString_CchLength((ushort *)pszProvider,&local_168,0);
    if (uVar2 == 0) {
      uVar6 = (local_168 * 2 + 9 & 0xfffffff8) + 0x28;
      if ((uVar6 < 0x101) ||
         (puVar4 = (uchar *)BCryptAlloc((ulonglong)uVar6), puVar4 != (uchar *)0x0)) {
        uVar2 = IoPack_Registration_ParamBlock
                          ((ushort *)pszProvider,dwMode,dwInterface,0,(_CRYPT_PROVIDER_REG *)0x0,
                           (ulong *)0x0,puVar4);
        if (uVar2 == 0) {
          pp_Var5 = (_CRYPT_PROVIDER_REG **)0x2;
          pp_Var7 = ppBuffer;
          iVar3 = IoCallKernelDriverQueryLoop(2,puVar4,uVar6,(uchar **)ppBuffer,pcbBuffer,local_164)
          ;
          if ((-1 < iVar3) &&
             (uVar2 = IoUnpack_SG_ProviderReg
                                (pp_Var5,(uchar *)*ppBuffer,*pcbBuffer,(uchar *)pp_Var7), uVar2 == 0
             )) goto LAB_1800084d3;
          goto LAB_180008542;
        }
      }
      else {
        uVar2 = 8;
      }
    }
  }
  iVar3 = WinErrorToNtStatus(uVar2);
LAB_1800084d3:
  if ((puVar4 != (uchar *)0x0) && (puVar4 != local_158)) {
    BCryptFree((longlong)puVar4);
  }
  if (ppBuffer == (PCRYPT_PROVIDER_REG *)0x0) {
    if (iVar3 == -0x3fffffdd) {
      iVar3 = 0;
    }
  }
  return iVar3;
}



===== IoUnpack_SG_ProviderReg @ 18000858c =====

/* unsigned long __cdecl IoUnpack_SG_ProviderReg(struct _CRYPT_PROVIDER_REG * __ptr64 *
   __ptr64,unsigned char * __ptr64,unsigned long,unsigned char * __ptr64) */

ulong __cdecl
IoUnpack_SG_ProviderReg(_CRYPT_PROVIDER_REG **param_1,uchar *param_2,ulong param_3,uchar *param_4)

{
  ulong uVar1;
  uchar *puVar2;
  uchar *in_stack_ffffffffffffffe8;
  
  puVar2 = (uchar *)(ulonglong)param_3;
  if (param_2 != (uchar *)0x0) {
    if ((param_2 + 0x20 < param_2) || (param_2 + (longlong)puVar2 < param_2 + 0x20)) {
      return 0x54f;
    }
    uVar1 = IoUnpack_SG_SzStringArray
                      ((ushort ***)(param_2 + 8),*(ulong *)param_2,param_2,param_3,
                       in_stack_ffffffffffffffe8);
    if (uVar1 != 0) {
      return uVar1;
    }
    uVar1 = IoUnpack_SG_ImageReg((_CRYPT_IMAGE_REG **)(param_2 + 0x10),param_2,param_3,puVar2);
    if (uVar1 != 0) {
      return uVar1;
    }
    uVar1 = IoUnpack_SG_ImageReg((_CRYPT_IMAGE_REG **)(param_2 + 0x18),param_2,param_3,puVar2);
    if (uVar1 != 0) {
      return uVar1;
    }
  }
  return 0;
}



===== IoPack_ProviderReg @ 18000860c =====

/* void __cdecl IoPack_ProviderReg(struct _CRYPT_PROVIDER_REG * __ptr64 * __ptr64,unsigned char *
   __ptr64) */

void __cdecl IoPack_ProviderReg(_CRYPT_PROVIDER_REG **param_1,uchar *param_2)

{
  _CRYPT_PROVIDER_REG *p_Var1;
  
  if (param_1 == (_CRYPT_PROVIDER_REG **)0x0) {
    p_Var1 = (_CRYPT_PROVIDER_REG *)param_2;
    if (param_2 == (uchar *)0x0) {
      return;
    }
  }
  else {
    p_Var1 = *param_1;
    if (p_Var1 == (_CRYPT_PROVIDER_REG *)0x0) {
      *param_1 = (_CRYPT_PROVIDER_REG *)0xffffffffffffffff;
      return;
    }
    *param_1 = (_CRYPT_PROVIDER_REG *)((longlong)p_Var1 - (longlong)param_2);
  }
  IoPack_SzStringArray((ushort ***)&p_Var1->rgpszAliases,p_Var1->cAliases,param_2);
  IoPack_ImageReg(&p_Var1->pUM,param_2);
  IoPack_ImageReg(&p_Var1->pKM,param_2);
  return;
}



===== IoUnpack_SG_ImageReg @ 180008678 =====

/* unsigned long __cdecl IoUnpack_SG_ImageReg(struct _CRYPT_IMAGE_REG * __ptr64 * __ptr64,unsigned
   char * __ptr64,unsigned long,unsigned char * __ptr64) */

ulong __cdecl
IoUnpack_SG_ImageReg(_CRYPT_IMAGE_REG **param_1,uchar *param_2,ulong param_3,uchar *param_4)

{
  ulong uVar1;
  _CRYPT_IMAGE_REG *p_Var2;
  uchar *in_stack_ffffffffffffffe8;
  
  p_Var2 = *param_1;
  if (p_Var2 == (_CRYPT_IMAGE_REG *)0xffffffffffffffff) {
    p_Var2 = (_CRYPT_IMAGE_REG *)0x0;
  }
  else {
    if ((((_CRYPT_IMAGE_REG *)(ulonglong)param_3 <= p_Var2) || (p_Var2 + 1 < p_Var2)) ||
       ((_CRYPT_IMAGE_REG *)(ulonglong)param_3 < p_Var2 + 1)) {
      return 0x54f;
    }
    p_Var2 = (_CRYPT_IMAGE_REG *)(param_2 + (longlong)&p_Var2->pszImage);
  }
  *param_1 = p_Var2;
  if (p_Var2 == (_CRYPT_IMAGE_REG *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = IoUnpack_SG_SzString((ushort **)p_Var2,param_2,param_3,param_4);
    if (uVar1 == 0) {
      uVar1 = IoUnpack_SG_InterfaceRegArray
                        (&(*param_1)->rgpInterfaces,(*param_1)->cInterfaces,param_2,param_3,
                         in_stack_ffffffffffffffe8);
    }
  }
  return uVar1;
}



===== IoUnpack_SG_InterfaceRegArray @ 180008704 =====

/* unsigned long __cdecl IoUnpack_SG_InterfaceRegArray(struct _CRYPT_INTERFACE_REG * __ptr64 *
   __ptr64 * __ptr64,unsigned long,unsigned char * __ptr64,unsigned long,unsigned char * __ptr64) */

ulong __cdecl
IoUnpack_SG_InterfaceRegArray
          (_CRYPT_INTERFACE_REG ***param_1,ulong param_2,uchar *param_3,ulong param_4,uchar *param_5
          )

{
  ulong uVar1;
  _CRYPT_INTERFACE_REG **pp_Var2;
  ulonglong uVar3;
  ulong uVar4;
  undefined4 in_register_0000008c;
  
  pp_Var2 = *param_1;
  if (pp_Var2 == (_CRYPT_INTERFACE_REG **)0xffffffffffffffff) {
    *param_1 = (_CRYPT_INTERFACE_REG **)0x0;
    if (param_2 != 0) {
      return 0x54f;
    }
    pp_Var2 = (_CRYPT_INTERFACE_REG **)0x0;
  }
  else {
    if ((((param_2 == 0) || ((_CRYPT_INTERFACE_REG **)(ulonglong)param_4 <= pp_Var2)) ||
        (pp_Var2 + param_2 < pp_Var2)) ||
       ((_CRYPT_INTERFACE_REG **)(ulonglong)param_4 < pp_Var2 + param_2)) {
      return 0x54f;
    }
    pp_Var2 = (_CRYPT_INTERFACE_REG **)((longlong)pp_Var2 + (longlong)param_3);
    *param_1 = pp_Var2;
  }
  if (pp_Var2 != (_CRYPT_INTERFACE_REG **)0x0) {
    uVar4 = param_4;
    for (uVar3 = 0; (uint)uVar3 < param_2; uVar3 = (ulonglong)((uint)uVar3 + 1)) {
      uVar1 = IoUnpack_SG_InterfaceReg
                        (*param_1 + uVar3,param_3,param_4,
                         (uchar *)CONCAT44(in_register_0000008c,uVar4));
      if (uVar1 != 0) {
        return uVar1;
      }
    }
  }
  return 0;
}



===== IoUnpack_SG_InterfaceReg @ 1800087ac =====

/* unsigned long __cdecl IoUnpack_SG_InterfaceReg(struct _CRYPT_INTERFACE_REG * __ptr64 *
   __ptr64,unsigned char * __ptr64,unsigned long,unsigned char * __ptr64) */

ulong __cdecl
IoUnpack_SG_InterfaceReg(_CRYPT_INTERFACE_REG **param_1,uchar *param_2,ulong param_3,uchar *param_4)

{
  ulong uVar1;
  _CRYPT_INTERFACE_REG *p_Var2;
  uchar *in_stack_ffffffffffffffe8;
  
  p_Var2 = *param_1;
  if (p_Var2 == (_CRYPT_INTERFACE_REG *)0xffffffffffffffff) {
    p_Var2 = (_CRYPT_INTERFACE_REG *)0x0;
  }
  else {
    if ((((_CRYPT_INTERFACE_REG *)(ulonglong)param_3 <= p_Var2) || (p_Var2 + 1 < p_Var2)) ||
       ((_CRYPT_INTERFACE_REG *)(ulonglong)param_3 < p_Var2 + 1)) {
      return 0x54f;
    }
    p_Var2 = (_CRYPT_INTERFACE_REG *)(param_2 + (longlong)p_Var2);
  }
  *param_1 = p_Var2;
  if ((p_Var2 == (_CRYPT_INTERFACE_REG *)0x0) ||
     (uVar1 = IoUnpack_SG_SzStringArray
                        ((ushort ***)&p_Var2->rgpszFunctions,p_Var2->cFunctions,param_2,param_3,
                         in_stack_ffffffffffffffe8), uVar1 == 0)) {
    return 0;
  }
  uVar1 = IoUnpack_SG_SzStringArray
                    ((ushort ***)&(*param_1)->rgpszFunctions,(*param_1)->cFunctions,param_2,param_3,
                     in_stack_ffffffffffffffe8);
  return uVar1;
}



===== LoadProviderEx @ 180008840 =====

ulonglong LoadProviderEx(uint *param_1,void *param_2,ulonglong param_3,undefined8 *param_4,
                        void *param_5)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined8 *puVar6;
  short *psVar7;
  undefined2 uVar8;
  uint *puVar9;
  HMODULE *ppHVar10;
  ulonglong uVar11;
  ulonglong _Size;
  undefined1 uVar12;
  wchar_t *pwVar13;
  undefined1 uVar14;
  HMODULE local_38;
  void *local_30;
  
  bVar1 = false;
  local_30 = (void *)0x0;
  local_38 = (HMODULE)0x0;
  if (g_fLoaderInitialized == 0) {
    uVar11 = 0xc00000e5;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      uVar14 = 0x8f;
      uVar12 = 0xe5;
LAB_1800088b6:
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,param_3,"sResult",uVar12,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\loader\\loader.c",uVar14);
    }
    goto LAB_180008d59;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&g_csLoaderLock);
  bVar1 = true;
  puVar6 = g_pLoadedProviderList;
  _Size = param_3;
  if (g_pLoadedProviderList == (undefined8 *)0x0) {
LAB_180008959:
    ppHVar10 = &local_38;
    uVar3 = _LoadImage((longlong)param_1,(longlong *)ppHVar10);
    uVar11 = (ulonglong)uVar3;
    if (uVar3 == 0) goto LAB_180008921;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180008d4a;
    uVar12 = 0xa9;
LAB_180008d3a:
    WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),ppHVar10,_Size,"sResult",(char)uVar3,
                "onecore\\ds\\security\\cryptoapi\\ncrypt\\loader\\loader.c",uVar12);
LAB_180008d4a:
    if (local_38 != (HMODULE)0x0) {
      _FreeImage(local_38);
    }
  }
  else {
    do {
      iVar2 = _wcsicmp((wchar_t *)**(undefined8 **)(param_1 + 10),(wchar_t *)*puVar6);
      if (iVar2 == 0) break;
      puVar6 = (undefined8 *)puVar6[3];
    } while (puVar6 != (undefined8 *)0x0);
    if (puVar6 == (undefined8 *)0x0) goto LAB_180008959;
    local_38 = (HMODULE)puVar6[1];
LAB_180008921:
    puVar9 = param_1;
    uVar4 = _LoadInterface(local_38,param_1,_Size,(HMODULE)&local_30);
    uVar11 = uVar4 & 0xffffffff;
    if ((int)uVar4 == 0) {
      uVar3 = *param_1;
      if (uVar3 < 0x10002) {
        if (uVar3 == 0x10001) {
          uVar3 = 0x100;
        }
        else {
          switch(uVar3) {
          case 1:
          case 2:
          case 5:
          case 8:
            uVar3 = 0x60;
            break;
          case 3:
            uVar3 = 0x70;
            break;
          case 4:
            uVar3 = 0x68;
            break;
          case 6:
            uVar3 = 0x30;
            break;
          case 7:
            uVar3 = 0x58;
            break;
          default:
switchD_1800089ce_default:
            uVar11 = 0xc000000d;
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
              WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),puVar9,_Size,"sResult",0xd,
                          "onecore\\ds\\security\\cryptoapi\\ncrypt\\loader\\loader.c",0xc4);
            }
            goto LAB_180008a5d;
          }
        }
      }
      else if (uVar3 == 0x10002) {
        uVar3 = 0x188;
      }
      else {
        if (uVar3 != 0x10004) goto switchD_1800089ce_default;
        uVar3 = 0x28;
      }
      _Size = (ulonglong)uVar3;
      param_2 = local_30;
      memcpy(param_5,local_30,_Size);
      if (puVar6 == (undefined8 *)0x0) {
        psVar7 = (short *)**(undefined8 **)(param_1 + 10);
        if (psVar7 == (short *)0x0) {
LAB_180008cd8:
          ppHVar10 = (HMODULE *)0x80070057;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
            WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x80070057,_Size,"hResult",0x57,
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\loader\\loader.c",0x52);
          }
          uVar11 = 0xc000000d;
LAB_180008d1e:
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
            uVar12 = 0xeb;
            uVar3 = (uint)uVar11;
            goto LAB_180008d3a;
          }
        }
        else {
          _Size = 0x800;
          lVar5 = 0x800;
          do {
            if (*psVar7 == 0) break;
            psVar7 = psVar7 + 1;
            lVar5 = lVar5 + -1;
          } while (lVar5 != 0);
          if (lVar5 == 0) goto LAB_180008cd8;
          ppHVar10 = (HMODULE *)0x0;
          _Size = (0x800 - lVar5) * 2;
          if (lVar5 == 0) {
            _Size = 0;
          }
          param_3 = _Size + 2;
          if ((param_3 < _Size) || (_Size = _Size + 0x22, _Size < 0x20)) {
            uVar11 = 0xc0000095;
            if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_180008d4a;
            if ((WPP_GLOBAL_Control[0x1c] & 1) != 0) {
              uVar14 = 0x5c;
              uVar12 = 0x95;
LAB_180008bf5:
              WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),ppHVar10,_Size,"sResult",uVar12
                          ,"onecore\\ds\\security\\cryptoapi\\ncrypt\\loader\\loader.c",uVar14);
            }
            goto LAB_180008d1e;
          }
          ppHVar10 = (HMODULE *)0x0;
          puVar6 = (undefined8 *)
                   RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30));
          if (puVar6 != (undefined8 *)0x0) {
            *puVar6 = puVar6 + 4;
            memcpy(puVar6 + 4,(void *)**(undefined8 **)(param_1 + 10),param_3);
            puVar6[1] = local_38;
            *(undefined4 *)(puVar6 + 2) = 2;
            puVar6[3] = g_pLoadedProviderList;
            uVar11 = 0;
            g_pLoadedProviderList = puVar6;
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((WPP_GLOBAL_Control[0x1c] & 0x20) != 0)) {
              uVar3 = *(uint *)(puVar6 + 2);
              uVar8 = 0x1c;
              pwVar13 = (wchar_t *)*puVar6;
              goto LAB_180008c82;
            }
            goto LAB_180008c8e;
          }
          uVar11 = 0xc0000017;
          if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
            if ((WPP_GLOBAL_Control[0x1c] & 1) != 0) {
              uVar14 = 0x6f;
              uVar12 = 0x17;
              goto LAB_180008bf5;
            }
            goto LAB_180008d1e;
          }
        }
        goto LAB_180008d4a;
      }
      uVar3 = *(uint *)(puVar6 + 2) + 1;
      param_3 = (ulonglong)uVar3;
      if (*(uint *)(puVar6 + 2) <= uVar3) {
        *(uint *)(puVar6 + 2) = uVar3;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((WPP_GLOBAL_Control[0x1c] & 0x20) != 0)) {
          pwVar13 = (wchar_t *)*puVar6;
          uVar8 = 0x1b;
LAB_180008c82:
          WPP_SF_qqSD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar8,param_3,param_1,(char)puVar6,
                      pwVar13,(char)uVar3);
        }
LAB_180008c8e:
        *param_4 = puVar6;
        goto LAB_180008d66;
      }
      uVar11 = 0xc000009a;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        uVar14 = 0xd5;
        uVar12 = 0x9a;
        goto LAB_1800088b6;
      }
    }
    else {
      DebugTraceError((char)uVar4,"sResult",
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\loader\\loader.c",0xba);
LAB_180008a5d:
      if (puVar6 == (undefined8 *)0x0) goto LAB_180008d4a;
    }
  }
LAB_180008d59:
  *param_4 = 0;
  if (!bVar1) {
    return uVar11;
  }
LAB_180008d66:
  LeaveCriticalSection((LPCRITICAL_SECTION)&g_csLoaderLock);
  return uVar11;
}



===== ValidateBaseHashHandle @ 180008dd0 =====

uint * ValidateBaseHashHandle(uint *param_1)

{
  uint *puVar1;
  
  if ((param_1 == (uint *)0x0) || (*param_1 < 0x28)) {
    return (uint *)0x0;
  }
  puVar1 = (uint *)0x0;
  if (param_1[1] == 0x55555553) {
    puVar1 = param_1;
  }
  return puVar1;
}



===== ReopenSystemPreferredRngCallback @ 180008e00 =====

void ReopenSystemPreferredRngCallback(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  NTSTATUS NVar1;
  undefined8 *puVar2;
  
  puVar2 = &DAT_180025ac8;
  if (g_fLoadCNGDone != 0) {
    puVar2 = &DAT_180025ad0;
  }
  NVar1 = ReopenSystemPreferredRngHandle(puVar2,param_2,param_3);
  if (NVar1 < 0) {
    DebugTraceError((char)NVar1,"Status",
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\syspref.c",0xb2);
    return;
  }
  return;
}



===== ReopenSystemPreferredRngHandle @ 180008e54 =====

NTSTATUS ReopenSystemPreferredRngHandle(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  NTSTATUS NVar1;
  undefined8 uVar2;
  
  RtlAcquireResourceExclusive(g_pCachedRngRWLock);
  uVar2 = 0;
  BCryptCloseAlgorithmProvider((BCRYPT_ALG_HANDLE)*param_1,0);
  *param_1 = 0;
  NVar1 = OpenSystemPreferredAlgorithmProvider(param_1);
  if (NVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar2,param_3,"Status",(char)NVar1,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\syspref.c",0x7f);
    }
  }
  else {
    NVar1 = 0;
  }
  RtlReleaseResource(g_pCachedRngRWLock);
  return NVar1;
}



===== BCryptGenRandom @ 180008f00 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

NTSTATUS __stdcall
BCryptGenRandom(BCRYPT_ALG_HANDLE hAlgorithm,PUCHAR pbBuffer,ULONG cbBuffer,ULONG dwFlags)

{
  bool bVar1;
  DWORD DVar2;
  uint uVar3;
  uint *puVar4;
  BCRYPT_ALG_HANDLE hAlgorithm_00;
  PUCHAR pUVar5;
  undefined4 in_register_00000084;
  undefined1 uVar6;
  BCRYPT_ALG_HANDLE local_18 [2];
  
                    /* 0x8f00  32  BCryptGenRandom */
  pUVar5 = pbBuffer;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    pUVar5 = (PUCHAR)0x28;
    WPP_SF_qqdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x28,
                CONCAT44(in_register_00000084,cbBuffer),hAlgorithm,(char)pbBuffer,(char)cbBuffer,
                (char)dwFlags);
  }
  if ((dwFlags & 2) == 0) {
    puVar4 = ValidateBaseAlgHandle(hAlgorithm);
    if (puVar4 == (uint *)0x0) {
      DVar2 = 0xc0000008;
      uVar6 = 0xa7;
    }
    else if (puVar4[9] == 6) {
      DVar2 = (**(code **)(puVar4 + 0x16))(*(undefined8 *)(puVar4 + 6),pbBuffer,cbBuffer,dwFlags);
      if (-1 < (int)DVar2) {
        return DVar2;
      }
      uVar6 = 0xb9;
    }
    else {
      DVar2 = 0xc0000008;
      uVar6 = 0xae;
    }
    goto LAB_1800090ef;
  }
  if (hAlgorithm != (BCRYPT_ALG_HANDLE)0x0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff3;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return -0x3ffffff3;
    }
    WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pUVar5,
                "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c","Status",0xd,
                "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",0x92);
    return -0x3ffffff3;
  }
  bVar1 = false;
  local_18[0] = (BCRYPT_ALG_HANDLE)0x0;
  uVar3 = g_TrustedEnvironment;
  if (g_TrustedEnvironment == 0) {
    uVar3 = GetTrustedEnvironment();
  }
  if ((uVar3 & 1) == 0) {
    hAlgorithm_00 = (BCRYPT_ALG_HANDLE)0x81;
LAB_180009008:
    DVar2 = BCryptGenRandom(hAlgorithm_00,pbBuffer,cbBuffer,dwFlags & 0xfffffffd);
    if ((int)DVar2 < 0) {
      DebugTraceError((char)DVar2,"Status",
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\syspref.c",0x32);
    }
    else {
      DVar2 = 0;
    }
    if (bVar1) {
      RtlReleaseResource(g_pCachedRngRWLock);
    }
  }
  else {
    DVar2 = GetSystemPreferredRngHandle((longlong *)local_18,pUVar5);
    if (-1 < (int)DVar2) {
      bVar1 = true;
      hAlgorithm_00 = local_18[0];
      goto LAB_180009008;
    }
  }
  if (-1 < (int)DVar2) {
    return DVar2;
  }
  uVar6 = 0x9c;
LAB_1800090ef:
  DebugTraceError((char)DVar2,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",
                  uVar6);
  return DVar2;
}



===== GetSystemPreferredRngHandle @ 180009110 =====

DWORD GetSystemPreferredRngHandle(longlong *param_1,undefined8 param_2)

{
  DWORD DVar1;
  longlong lVar2;
  longlong *plVar3;
  BCRYPT_ALG_HANDLE local_res10 [2];
  
  local_res10[0] = (BCRYPT_ALG_HANDLE)0x0;
  if (g_fLoadCNGDone == 0) {
    plVar3 = &DAT_180025ac8;
    lVar2 = DAT_180025ac8;
  }
  else {
    plVar3 = &DAT_180025ad0;
    lVar2 = DAT_180025ad0;
  }
  if (lVar2 == 0) {
    DVar1 = OpenSystemPreferredAlgorithmProvider(local_res10);
    if ((int)DVar1 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\syspref.c","Status",
                    (char)DVar1,"onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\syspref.c",0xba);
      }
      if (local_res10[0] == (BCRYPT_ALG_HANDLE)0x0) {
        return DVar1;
      }
      BCryptCloseAlgorithmProvider(local_res10[0],0);
      return DVar1;
    }
    LOCK();
    lVar2 = *plVar3;
    if (lVar2 == 0) {
      *plVar3 = (longlong)local_res10[0];
    }
    UNLOCK();
    if (lVar2 == 0) {
      if (g_fLoadCNGDone != 0) {
        DAT_180025ac4 = 1;
      }
    }
    else {
      BCryptCloseAlgorithmProvider(local_res10[0],0);
    }
  }
  else if ((DAT_180025b20 == 0) && (DVar1 = RegisterReopenWait(), (int)DVar1 < 0)) {
    DebugTraceError((char)DVar1,"Status",
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\syspref.c",0xf4);
    return DVar1;
  }
  RtlAcquireResourceShared(g_pCachedRngRWLock,1);
  *param_1 = *plVar3;
  return 0;
}



===== OpenSystemPreferredAlgorithmProvider @ 18000927c =====

NTSTATUS OpenSystemPreferredAlgorithmProvider(undefined8 *param_1)

{
  BCRYPT_ALG_HANDLE pvVar1;
  NTSTATUS NVar2;
  wchar_t *pszAlgId;
  undefined8 uVar3;
  PCRYPT_PROVIDER_REFS pvBuffer;
  undefined8 uVar4;
  PCRYPT_PROVIDER_REFS local_res18;
  ULONG local_res20 [2];
  BCRYPT_ALG_HANDLE local_28 [2];
  
  local_28[0] = (BCRYPT_ALG_HANDLE)0x0;
  local_res20[0] = 0;
  local_res18 = (PCRYPT_PROVIDER_REFS)0x0;
  if (g_fLoadCNGDone == 0) {
LAB_1800092b2:
    pszAlgId = L"RNG";
  }
  else {
    uVar4 = 0;
    uVar3 = 6;
    NVar2 = BCryptResolveProviders
                      ((LPCWSTR)0x0,6,(LPCWSTR)0x0,(LPCWSTR)0x0,1,0,local_res20,&local_res18);
    if (NVar2 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar3,uVar4,"Status",(char)NVar2,
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\syspref.c",0x6d);
      }
      pvBuffer = local_res18;
      goto LAB_1800092dc;
    }
    if (local_res18->cProviders == 0) {
      NVar2 = -0x3fffff1b;
      pvBuffer = local_res18;
      goto LAB_1800092dc;
    }
    if (g_fLoadCNGDone == 0) goto LAB_1800092b2;
    pszAlgId = (*local_res18->rgpProviders)->pszFunction;
  }
  pvBuffer = local_res18;
  uVar3 = 0;
  NVar2 = BCryptOpenAlgorithmProvider(local_28,pszAlgId,(LPCWSTR)0x0,0);
  pvVar1 = local_28[0];
  if (NVar2 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pszAlgId,uVar3,"Status",(char)NVar2,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\syspref.c",0x88);
    }
  }
  else {
    local_28[0] = (BCRYPT_ALG_HANDLE)0x0;
    NVar2 = 0;
    *param_1 = pvVar1;
  }
LAB_1800092dc:
  if (local_28[0] != (BCRYPT_ALG_HANDLE)0x0) {
    BCryptCloseAlgorithmProvider(local_28[0],0);
  }
  if (pvBuffer != (PCRYPT_PROVIDER_REFS)0x0) {
    BCryptFreeBuffer(pvBuffer);
  }
  return NVar2;
}



===== BCryptOpenAlgorithmProvider @ 180009410 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

NTSTATUS __stdcall
BCryptOpenAlgorithmProvider
          (BCRYPT_ALG_HANDLE *phAlgorithm,LPCWSTR pszAlgId,LPCWSTR pszImplementation,ULONG dwFlags)

{
  PCRYPT_PROVIDER_REF **ppp_Var1;
  _CRYPT_PROVIDER_REFS *p_Var2;
  _CRYPT_PROVIDER_REFS *p_Var3;
  longlong lVar4;
  PCRYPT_PROPERTY_REF p_Var5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  PCRYPT_PROVIDER_REF *pp_Var9;
  bool bVar10;
  ULONG UVar11;
  undefined4 uVar12;
  char cVar13;
  ULONG UVar14;
  uint uVar15;
  int iVar16;
  longlong lVar17;
  _CRYPT_PROVIDER_REFS *p_Var18;
  ulonglong uVar19;
  undefined8 uVar20;
  ulonglong uVar21;
  _CRYPT_PROVIDER_REFS *p_Var22;
  PCRYPT_PROVIDER_REF *pp_Var23;
  undefined **ppuVar24;
  ULONG UVar25;
  code *pcVar26;
  code *pcVar27;
  wchar_t *pwVar28;
  longlong lVar29;
  code *pcVar30;
  undefined1 auStackY_378 [32];
  undefined1 uVar31;
  undefined1 uVar32;
  char local_337 [3];
  ULONG local_334;
  LPCWSTR local_330;
  _CRYPT_PROVIDER_REFS *local_328;
  LPCWSTR local_320;
  ULONG local_318 [2];
  LPCWSTR local_310;
  _CRYPT_PROVIDER_REFS *local_308;
  ULONG local_300 [2];
  _CRYPT_PROVIDER_REFS *local_2f8;
  _CRYPT_PROVIDER_REFS *local_2f0;
  undefined4 local_2e8;
  PCRYPT_PROVIDER_REFS local_2e0;
  _CRYPT_PROVIDER_REFS *local_2d8;
  undefined4 local_2d0;
  code *local_2c8;
  code *local_2c0;
  code *local_2b8;
  LPCWSTR local_2b0;
  BCRYPT_ALG_HANDLE *local_2a8;
  code *local_2a0;
  _CRYPT_PROVIDER_REFS *local_298;
  _CRYPT_PROVIDER_REFS *local_290;
  _CRYPT_PROVIDER_REFS local_288 [25];
  _CRYPT_PROVIDER_REFS local_f8;
  _CRYPT_PROVIDER_REFS *local_e8;
  ulonglong uStack_e0;
  BCRYPT_ALG_HANDLE **local_d8;
  ulonglong uStack_d0;
  LPCWSTR *local_c8;
  ulonglong uStack_c0;
  ULONG *local_b8;
  undefined8 local_b0;
  ULONG *local_a8;
  undefined8 local_a0;
  wchar_t *local_98;
  int local_90;
  undefined4 local_8c;
  longlong local_88 [2];
  longlong local_78 [2];
  longlong local_68 [2];
  ulonglong local_58;
  
                    /* 0x9410  42  BCryptOpenAlgorithmProvider */
  local_58 = __security_cookie ^ (ulonglong)auStackY_378;
  local_2c8 = (code *)0x0;
  local_2d8 = (_CRYPT_PROVIDER_REFS *)0x0;
  local_328 = (_CRYPT_PROVIDER_REFS *)0x0;
  uVar15 = 0;
  local_337[0] = '\0';
  bVar10 = false;
  local_2d0 = 0;
  local_2c0 = (code *)0x0;
  local_2b8 = (code *)0x0;
  local_2a0 = (code *)0x0;
  local_2e8 = 4;
  local_334 = dwFlags;
  local_308 = (_CRYPT_PROVIDER_REFS *)pszImplementation;
  local_2b0 = pszAlgId;
  local_2a8 = phAlgorithm;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_SSD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),&WPP_GLOBAL_Control,pszImplementation,
               pszAlgId,pszImplementation,(char)dwFlags);
  }
  lVar29 = -1;
  if ((phAlgorithm == (BCRYPT_ALG_HANDLE *)0x0) || (pszAlgId == (LPCWSTR)0x0)) {
    UVar14 = 0xc000000d;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      uVar32 = 0xa2;
LAB_18000a147:
      UVar14 = 0xc000000d;
      uVar31 = 0xd;
LAB_18000a15b:
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),&WPP_GLOBAL_Control,pszImplementation,
                  "Status",uVar31,"onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar32);
    }
LAB_18000a16b:
    p_Var18 = local_308;
  }
  else {
    if ((local_334 & 1) != 0) {
      UVar14 = 0xc000000d;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        uVar32 = 0xac;
        goto LAB_18000a147;
      }
      goto LAB_18000a16b;
    }
    if (g_TrustedEnvironment == 0) {
      memset(local_288,0,0xb0);
      iVar16 = NtQueryInformationProcess(0xffffffffffffffff,0x56,local_288);
      if (iVar16 < 0) {
        local_f8.cProviders = 0x40;
        local_f8._4_4_ = 0;
        local_f8.rgpProviders = (PCRYPT_PROVIDER_REF *)0x0;
        local_e8 = (_CRYPT_PROVIDER_REFS *)0x0;
        uStack_e0 = 0;
        local_d8 = (BCRYPT_ALG_HANDLE **)0x0;
        uStack_d0 = 0;
        local_c8 = (LPCWSTR *)0x0;
        uStack_c0 = 0;
        iVar16 = NtQueryInformationProcess(0xffffffffffffffff,0,&local_f8,0x40);
        if ((iVar16 < 0) || (g_TrustedEnvironment = 4, (uStack_c0 & 0x80) == 0)) {
          g_TrustedEnvironment = 1;
        }
      }
      else if (local_288[0].cProviders - 0x10 < 2) {
        g_TrustedEnvironment = 0x10;
      }
      else {
        g_TrustedEnvironment = 1;
        if (local_288[0].cProviders == 1) {
          g_TrustedEnvironment = 8;
        }
      }
    }
    p_Var18 = local_308;
    if ((g_TrustedEnvironment & 1) != 0) {
      if (g_fLoadCNGDone == 0) {
        local_2f0 = (_CRYPT_PROVIDER_REFS *)&u_Microsoft_Primi;
      }
      else {
        local_2f0 = local_308;
        if (local_308 == (_CRYPT_PROVIDER_REFS *)0x0) {
          bVar10 = true;
          uVar15 = 2;
        }
      }
      pwVar28 = (wchar_t *)local_2f0;
      local_330._0_4_ = 0;
      pszImplementation = (LPCWSTR)(ulonglong)uVar15;
      local_2e0 = (_CRYPT_PROVIDER_REFS *)0x0;
      UVar14 = BCryptResolveProvidersForBcoapCached
                         (pszAlgId,(LPCWSTR)local_2f0,uVar15,(ULONG *)&local_330,&local_2e0,
                          local_337);
      if ((int)UVar14 < 0) {
        if ((Microsoft_Windows_Crypto_BCryptEnableBits & 1) != 0) {
          local_330._0_4_ = local_334;
          local_320._0_4_ = 1;
          if ((_CRYPT_PROVIDER_REFS *)pwVar28 == (_CRYPT_PROVIDER_REFS *)0x0) {
            uVar15 = 10;
            pwVar28 = L"NULL";
          }
          else {
            lVar17 = -1;
            do {
              lVar4 = lVar17 * 2;
              lVar17 = lVar17 + 1;
            } while (*(short *)((longlong)&((_CRYPT_PROVIDER_REFS *)pwVar28)->cProviders + lVar4 + 2
                               ) != 0);
            uVar15 = (int)lVar17 * 2 + 2;
          }
          uStack_e0 = (ulonglong)uVar15;
          lVar17 = -1;
          do {
            lVar4 = lVar17 + 1;
            lVar17 = lVar17 + 1;
          } while (pszAlgId[lVar4] != L'\0');
          local_c8 = &local_330;
          local_b8 = local_300;
          local_a8 = (ULONG *)&local_320;
          uStack_d0 = (ulonglong)((int)lVar17 * 2 + 2);
          uStack_c0 = 4;
          local_b0 = 4;
          local_a0 = 4;
          local_300[0] = UVar14;
          local_e8 = (_CRYPT_PROVIDER_REFS *)pwVar28;
          local_d8 = (BCRYPT_ALG_HANDLE **)pszAlgId;
          McGenEventWrite_USE_EtwEventWrite();
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
          WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),&WPP_GLOBAL_Control,
                      pszImplementation,"Status",(char)UVar14,
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",0xed);
        }
        p_Var18 = local_308;
        p_Var22 = local_2e0;
        goto LAB_18000a175;
      }
      local_328 = local_2e0;
      local_300[0] = (*local_2e0->rgpProviders)->dwInterface;
      if (local_300[0] - 1 < 8) {
        p_Var18 = (_CRYPT_PROVIDER_REFS *)BCryptAlloc(0x3c8);
        local_2f8 = p_Var18;
        if (p_Var18 != (_CRYPT_PROVIDER_REFS *)0x0) {
          memset(p_Var18,0,0x3c8);
          *(ULONG *)&p_Var18[2].field_0x4 = local_300[0];
          p_Var18->cProviders = 0x3c8;
          *(undefined4 *)&p_Var18->field_0x4 = 0x55555551;
          p_Var18[1].cProviders = 1;
          pszImplementation = pszAlgId;
          wcsncpy_s((wchar_t *)((longlong)&p_Var18[0x1b].rgpProviders + 4),0x104,pszAlgId,
                    0xffffffffffffffff);
          uVar21 = 0;
          p_Var18[2].cProviders = 0;
          local_330._0_4_ = 0;
          pcVar26 = (code *)0x0;
          pcVar27 = (code *)0x0;
          pcVar30 = (code *)0x0;
          if (local_328->cProviders == 0) {
LAB_180009ead:
            p_Var22 = (_CRYPT_PROVIDER_REFS *)pszImplementation;
            if (local_300[0] == 2) {
              if (pcVar26 == (code *)0x0) {
                UVar14 = 0xc00000e5;
                ppuVar24 = &WPP_GLOBAL_Control;
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
                  uVar32 = 0xf3;
                  UVar14 = 0xc00000e5;
LAB_18000a01f:
                  ppuVar24 = &WPP_GLOBAL_Control;
                  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),&WPP_GLOBAL_Control,
                              pszImplementation,"Status",(char)UVar14,
                              "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar32);
                  p_Var22 = (_CRYPT_PROVIDER_REFS *)pszImplementation;
                }
              }
              else {
                pszImplementation = (LPCWSTR)((longlong)&p_Var18->rgpProviders + 4);
                UVar14 = (*pcVar26)(p_Var18[1].rgpProviders,L"HashBlockLength",pszImplementation,4);
                if (-1 < (int)UVar14) goto LAB_18000a084;
                ppuVar24 = &WPP_GLOBAL_Control;
                p_Var22 = (_CRYPT_PROVIDER_REFS *)pszImplementation;
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
                  uVar32 = 0xff;
                  goto LAB_18000a01f;
                }
              }
            }
            else {
              if (local_300[0] != 3) {
LAB_18000a084:
                p_Var18 = local_2f8;
                p_Var22 = local_328;
                uVar21 = (ulonglong)(uint)local_330;
                uVar19 = 0;
                pp_Var23 = local_328->rgpProviders;
                if (pp_Var23[uVar21]->cProperties != 0) {
                  do {
                    p_Var5 = pp_Var23[uVar21]->rgpProperties[uVar19];
                    pszImplementation = (LPCWSTR)p_Var5->pbValue;
                    (*pcVar27)(p_Var18[1].rgpProviders,p_Var5->pszProperty,pszImplementation,
                               p_Var5->cbValue);
                    pp_Var23 = p_Var22->rgpProviders;
                    uVar15 = (int)uVar19 + 1;
                    uVar19 = (ulonglong)uVar15;
                  } while (uVar15 < pp_Var23[uVar21]->cProperties);
                  pszAlgId = local_2b0;
                }
                *local_2a8 = local_2f8;
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
                  WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xd,pszImplementation,
                           local_2f8);
                }
                UVar14 = 0;
                p_Var18 = local_308;
                goto LAB_18000a175;
              }
              if (pcVar26 == (code *)0x0) {
                UVar14 = 0xc00000e5;
                ppuVar24 = &WPP_GLOBAL_Control;
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
                  uVar32 = 8;
                  UVar14 = 0xc00000e5;
                  goto LAB_18000a01f;
                }
              }
              else {
                pszImplementation = (LPCWSTR)&p_Var18[0x1b].rgpProviders;
                UVar14 = (*pcVar26)(p_Var18[1].rgpProviders,L"PaddingSchemes",pszImplementation,
                                    local_2e8);
                if (-1 < (int)UVar14) goto LAB_18000a084;
                ppuVar24 = &WPP_GLOBAL_Control;
                p_Var22 = (_CRYPT_PROVIDER_REFS *)pszImplementation;
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
                  uVar32 = 0x14;
                  goto LAB_18000a01f;
                }
              }
            }
            if (pcVar30 != (code *)0x0) {
              ppuVar24 = (undefined **)0x0;
              (*pcVar30)(local_2f8[1].rgpProviders);
            }
          }
          else {
            local_298 = p_Var18 + 3;
            local_2f0 = (_CRYPT_PROVIDER_REFS *)&p_Var18[2].rgpProviders;
            UVar25 = local_334;
            do {
              ppuVar24 = (undefined **)local_328;
              p_Var22 = local_2f0;
              uVar19 = LoadProviderEx(&local_328->rgpProviders[uVar21]->dwInterface,local_328,
                                      (ulonglong)local_2f0,(undefined8 *)local_2f0,local_298);
              UVar14 = (ULONG)uVar19;
              local_2d8 = (_CRYPT_PROVIDER_REFS *)local_328->rgpProviders[uVar21]->pszProvider;
              local_290 = local_2d8;
              if ((int)UVar14 < 0) {
                if ((Microsoft_Windows_Crypto_BCryptEnableBits & 1) != 0) {
                  local_310._0_4_ = 2;
                  if (local_2d8 == (_CRYPT_PROVIDER_REFS *)0x0) {
                    uVar15 = 10;
                    local_e8 = (_CRYPT_PROVIDER_REFS *)0x18001f368;
                  }
                  else {
                    lVar17 = -1;
                    do {
                      lVar4 = lVar17 * 2;
                      lVar17 = lVar17 + 1;
                    } while (*(short *)((longlong)&local_2d8->cProviders + lVar4 + 2) != 0);
                    uVar15 = (int)lVar17 * 2 + 2;
                    local_e8 = local_2d8;
                  }
                  uStack_e0 = (ulonglong)uVar15;
                  lVar17 = -1;
                  do {
                    lVar4 = lVar17 + 1;
                    lVar17 = lVar17 + 1;
                  } while (pszAlgId[lVar4] != L'\0');
                  local_c8 = &local_320;
                  local_b8 = local_318;
                  local_a8 = (ULONG *)&local_310;
                  uStack_d0 = (ulonglong)((int)lVar17 * 2 + 2);
                  uStack_c0 = 4;
                  local_b0 = 4;
                  local_a0 = 4;
                  local_320._0_4_ = UVar25;
                  local_318[0] = UVar14;
                  local_d8 = (BCRYPT_ALG_HANDLE **)pszAlgId;
                  McGenEventWrite_USE_EtwEventWrite();
                }
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
                  uVar32 = 0x5b;
LAB_180009a5d:
                  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),ppuVar24,p_Var22,"Status",
                              (char)UVar14,"onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c"
                              ,uVar32);
                }
LAB_180009a7e:
                if (!bVar10) goto LAB_18000a046;
              }
              else {
                lVar17 = 3;
                p_Var18 = local_298;
                p_Var22 = local_288;
                do {
                  p_Var2 = p_Var22 + 8;
                  uVar6 = *(undefined4 *)&p_Var18->field_0x4;
                  pp_Var23 = p_Var18->rgpProviders;
                  UVar14 = p_Var18[1].cProviders;
                  uVar7 = *(undefined4 *)&p_Var18[1].field_0x4;
                  pp_Var9 = p_Var18[1].rgpProviders;
                  p_Var3 = p_Var18 + 8;
                  p_Var22->cProviders = p_Var18->cProviders;
                  *(undefined4 *)&p_Var22->field_0x4 = uVar6;
                  p_Var22->rgpProviders = pp_Var23;
                  UVar11 = p_Var18[2].cProviders;
                  uVar6 = *(undefined4 *)&p_Var18[2].field_0x4;
                  pp_Var23 = p_Var18[2].rgpProviders;
                  p_Var22[1].cProviders = UVar14;
                  *(undefined4 *)&p_Var22[1].field_0x4 = uVar7;
                  p_Var22[1].rgpProviders = pp_Var9;
                  UVar14 = p_Var18[3].cProviders;
                  uVar7 = *(undefined4 *)&p_Var18[3].field_0x4;
                  pp_Var9 = p_Var18[3].rgpProviders;
                  p_Var22[2].cProviders = UVar11;
                  *(undefined4 *)&p_Var22[2].field_0x4 = uVar6;
                  p_Var22[2].rgpProviders = pp_Var23;
                  UVar11 = p_Var18[4].cProviders;
                  uVar6 = *(undefined4 *)&p_Var18[4].field_0x4;
                  pp_Var23 = p_Var18[4].rgpProviders;
                  p_Var22[3].cProviders = UVar14;
                  *(undefined4 *)&p_Var22[3].field_0x4 = uVar7;
                  p_Var22[3].rgpProviders = pp_Var9;
                  UVar14 = p_Var18[5].cProviders;
                  uVar7 = *(undefined4 *)&p_Var18[5].field_0x4;
                  pp_Var9 = p_Var18[5].rgpProviders;
                  p_Var22[4].cProviders = UVar11;
                  *(undefined4 *)&p_Var22[4].field_0x4 = uVar6;
                  p_Var22[4].rgpProviders = pp_Var23;
                  UVar11 = p_Var18[6].cProviders;
                  uVar12 = *(undefined4 *)&p_Var18[6].field_0x4;
                  pp_Var23 = p_Var18[6].rgpProviders;
                  p_Var22[5].cProviders = UVar14;
                  *(undefined4 *)&p_Var22[5].field_0x4 = uVar7;
                  p_Var22[5].rgpProviders = pp_Var9;
                  UVar14 = p_Var18[7].cProviders;
                  uVar6 = *(undefined4 *)&p_Var18[7].field_0x4;
                  uVar7 = *(undefined4 *)&p_Var18[7].rgpProviders;
                  uVar8 = *(undefined4 *)((longlong)&p_Var18[7].rgpProviders + 4);
                  p_Var22[6].cProviders = UVar11;
                  *(undefined4 *)&p_Var22[6].field_0x4 = uVar12;
                  p_Var22[6].rgpProviders = pp_Var23;
                  p_Var22[7].cProviders = UVar14;
                  *(undefined4 *)&p_Var22[7].field_0x4 = uVar6;
                  *(undefined4 *)&p_Var22[7].rgpProviders = uVar7;
                  *(undefined4 *)((longlong)&p_Var22[7].rgpProviders + 4) = uVar8;
                  lVar17 = lVar17 + -1;
                  p_Var18 = p_Var3;
                  p_Var22 = p_Var2;
                } while (lVar17 != 0);
                uVar6 = *(undefined4 *)&p_Var3->field_0x4;
                p_Var2->cProviders = p_Var3->cProviders;
                *(undefined4 *)&p_Var2->field_0x4 = uVar6;
                p_Var22 = (_CRYPT_PROVIDER_REFS *)&local_2a0;
                uVar20 = ValidateFunctionTable
                                   (local_300[0],(longlong)local_288,(longlong *)p_Var22,
                                    (longlong *)&local_2c8,(longlong *)&local_2c0,&local_2b8);
                pcVar26 = local_2a0;
                p_Var18 = local_2f8;
                UVar14 = (ULONG)uVar20;
                if ((int)UVar14 < 0) {
                  pwVar28 = local_328->rgpProviders[uVar21]->pszProvider;
                  if ((Microsoft_Windows_Crypto_BCryptEnableBits & 1) != 0) {
                    local_320._0_4_ = 3;
                    if ((_CRYPT_PROVIDER_REFS *)pwVar28 == (_CRYPT_PROVIDER_REFS *)0x0) {
                      uVar15 = 10;
                      pwVar28 = L"NULL";
                    }
                    else {
                      lVar17 = -1;
                      do {
                        lVar4 = lVar17 * 2;
                        lVar17 = lVar17 + 1;
                      } while (*(short *)((longlong)&((_CRYPT_PROVIDER_REFS *)pwVar28)->cProviders +
                                         lVar4 + 2) != 0);
                      uVar15 = (int)lVar17 * 2 + 2;
                    }
                    uStack_e0 = (ulonglong)uVar15;
                    lVar17 = -1;
                    do {
                      lVar4 = lVar17 + 1;
                      lVar17 = lVar17 + 1;
                    } while (pszAlgId[lVar4] != L'\0');
                    local_c8 = &local_310;
                    local_b8 = local_318;
                    local_a8 = (ULONG *)&local_320;
                    uStack_d0 = (ulonglong)((int)lVar17 * 2 + 2);
                    uStack_c0 = 4;
                    local_b0 = 4;
                    local_a0 = 4;
                    local_318[0] = UVar14;
                    local_310._0_4_ = UVar25;
                    local_e8 = (_CRYPT_PROVIDER_REFS *)pwVar28;
                    local_d8 = (BCRYPT_ALG_HANDLE **)pszAlgId;
                    McGenEventWrite_USE_EtwEventWrite();
                  }
                  ppuVar24 = (undefined **)pwVar28;
                  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                     ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
                    uVar32 = 0x82;
                    goto LAB_180009a5d;
                  }
                  goto LAB_180009a7e;
                }
                pszImplementation = (LPCWSTR)(ulonglong)local_334;
                UVar14 = (*local_2a0)(&local_2f8[1].rgpProviders,pszAlgId);
                if (UVar14 == 0xc000a001) {
                  p_Var22 = (_CRYPT_PROVIDER_REFS *)(ulonglong)local_334;
                  if ((local_300[0] == 2) && (((byte)local_334 & 0x68) == 8)) {
                    pszImplementation = (LPCWSTR)(ulonglong)(local_334 & 0xfffffff7);
                    UVar14 = (*pcVar26)(&p_Var18[1].rgpProviders,pszAlgId);
                    ppp_Var1 = &p_Var18->rgpProviders;
                    *(uint *)ppp_Var1 = *(uint *)ppp_Var1 | 8;
                    goto LAB_180009c9f;
                  }
                }
                else {
LAB_180009c9f:
                  if (-1 < (int)UVar14) {
                    pcVar26 = local_2b8;
                    pcVar27 = local_2c0;
                    pcVar30 = local_2c8;
                    p_Var18 = local_2f8;
                    goto LAB_180009ead;
                  }
                  p_Var22 = (_CRYPT_PROVIDER_REFS *)(ulonglong)local_334;
                }
                pwVar28 = local_328->rgpProviders[uVar21]->pszProvider;
                if ((Microsoft_Windows_Crypto_BCryptEnableBits & 1) != 0) {
                  local_320._0_4_ = 4;
                  local_310._0_4_ = (ULONG)p_Var22;
                  if ((_CRYPT_PROVIDER_REFS *)pwVar28 == (_CRYPT_PROVIDER_REFS *)0x0) {
                    uVar15 = 10;
                    pwVar28 = L"NULL";
                  }
                  else {
                    lVar17 = -1;
                    do {
                      lVar4 = lVar17 * 2;
                      lVar17 = lVar17 + 1;
                    } while (*(short *)((longlong)&((_CRYPT_PROVIDER_REFS *)pwVar28)->cProviders +
                                       lVar4 + 2) != 0);
                    uVar15 = (int)lVar17 * 2 + 2;
                  }
                  uStack_e0 = (ulonglong)uVar15;
                  lVar17 = -1;
                  do {
                    lVar4 = lVar17 + 1;
                    lVar17 = lVar17 + 1;
                  } while (pszAlgId[lVar4] != L'\0');
                  local_c8 = &local_310;
                  local_b8 = local_318;
                  local_a8 = (ULONG *)&local_320;
                  uStack_d0 = (ulonglong)((int)lVar17 * 2 + 2);
                  uStack_c0 = 4;
                  local_b0 = 4;
                  local_a0 = 4;
                  local_318[0] = UVar14;
                  local_e8 = (_CRYPT_PROVIDER_REFS *)pwVar28;
                  local_d8 = (BCRYPT_ALG_HANDLE **)pszAlgId;
                  McGenEventWrite_USE_EtwEventWrite();
                }
                ppuVar24 = &WPP_GLOBAL_Control;
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
                  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),&WPP_GLOBAL_Control,p_Var22
                              ,"Status",(char)UVar14,
                              "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",0xc2);
                }
                if (!bVar10) goto LAB_18000a046;
                UnloadProvider((undefined8 *)*(code **)local_2f0,ppuVar24,p_Var22);
                *(code **)local_2f0 = (code *)0x0;
                UVar25 = local_334;
              }
              p_Var18 = local_290;
              local_330._0_4_ = (uint)local_330 + 1;
              uVar21 = (ulonglong)(uint)local_330;
            } while ((uint)local_330 < local_328->cProviders);
            local_2d8 = local_290;
            if (-1 < (int)UVar14) {
              pcVar26 = local_2b8;
              pcVar27 = local_2c0;
              pszImplementation = (LPCWSTR)local_2f0;
              pcVar30 = local_2c8;
              p_Var18 = local_2f8;
              goto LAB_180009ead;
            }
            ppuVar24 = (undefined **)local_328;
            p_Var22 = local_2f0;
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
              WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),local_328,local_2f0,"Status",
                          (char)UVar14,"onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",
                          0xe3);
            }
            local_2d8 = p_Var18;
          }
LAB_18000a046:
          pszImplementation = (LPCWSTR)local_2f8;
          if (local_2f8[2].rgpProviders != (PCRYPT_PROVIDER_REF *)0x0) {
            UnloadProvider(local_2f8[2].rgpProviders,ppuVar24,p_Var22);
          }
          RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30));
          p_Var18 = local_308;
          p_Var22 = local_2e0;
          goto LAB_18000a175;
        }
        UVar14 = 0xc0000017;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
          uVar32 = 0x1b;
          uVar31 = 0x17;
          goto LAB_18000a15b;
        }
      }
      else {
        pszImplementation = (LPCWSTR)(ulonglong)local_334;
        _LogBCryptOpenProviderFailure(pwVar28,pszAlgId,(char)local_334,(char)UVar14,1);
        UVar14 = 0xc0000008;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
          uVar32 = 0xc;
          uVar31 = 8;
          goto LAB_18000a15b;
        }
      }
      goto LAB_18000a16b;
    }
    pszImplementation = (LPCWSTR)local_308;
    UVar14 = VsmOpenAlgorithmProvider(phAlgorithm,pszAlgId,local_308,local_334);
  }
  p_Var22 = local_328;
LAB_18000a175:
  if (g_TrustedEnvironment == 0) {
    memset(local_288,0,0xb0);
    pszImplementation = (LPCWSTR)local_288;
    iVar16 = NtQueryInformationProcess(0xffffffffffffffff,0x56);
    if (iVar16 < 0) {
      local_f8.rgpProviders = (PCRYPT_PROVIDER_REF *)0x0;
      local_e8 = (_CRYPT_PROVIDER_REFS *)0x0;
      uStack_e0 = 0;
      local_d8 = (BCRYPT_ALG_HANDLE **)0x0;
      uStack_d0 = 0;
      pszImplementation = (LPCWSTR)&local_f8;
      local_c8 = (LPCWSTR *)0x0;
      uStack_c0 = 0;
      local_f8.cProviders = 0x40;
      local_f8._4_4_ = 0;
      iVar16 = NtQueryInformationProcess(0xffffffffffffffff,0,pszImplementation,0x40);
      if ((iVar16 < 0) || (g_TrustedEnvironment = 4, (uStack_c0 & 0x80) == 0)) {
        g_TrustedEnvironment = 1;
      }
    }
    else if (local_288[0].cProviders - 0x10 < 2) {
      g_TrustedEnvironment = 0x10;
    }
    else {
      g_TrustedEnvironment = 1;
      if (local_288[0].cProviders == 1) {
        g_TrustedEnvironment = 8;
      }
    }
  }
  if (((((g_TrustedEnvironment & 1) != 0) && (cVar13 = RtlDllShutdownInProgress(), cVar13 == '\0'))
      && (5 < DAT_180025058)) &&
     (uVar21 = _tlgKeywordOn(0x180025058,0x400000000000), (char)uVar21 != '\0')) {
    local_d8 = &local_2a8;
    local_2a8 = (BCRYPT_ALG_HANDLE *)0x1;
    local_c8 = &local_2b0;
    uStack_d0 = 8;
    local_b8 = (ULONG *)&local_310;
    local_a8 = local_318;
    local_2b0 = (LPCWSTR)0x1000000;
    uStack_c0 = 8;
    local_b0 = 4;
    local_318[0] = 0;
    local_a0 = 4;
    do {
      lVar17 = lVar29 + 1;
      lVar29 = lVar29 + 1;
    } while (g_processImageName[lVar17] != L'\0');
    local_90 = (int)lVar29 * 2 + 2;
    local_98 = g_processImageName;
    local_8c = 0;
    local_310._0_4_ = UVar14;
    _tlgCreate1Sz_wchar_t(local_88,pszAlgId);
    _tlgCreate1Sz_wchar_t(local_78,(wchar_t *)p_Var18);
    _tlgCreate1Sz_wchar_t(local_68,(wchar_t *)local_2d8);
    _tlgWriteAgg(&local_f8,&DAT_18002068c,pszImplementation,10,(PEVENT_DATA_DESCRIPTOR)&local_f8);
  }
  if ((local_337[0] != '\0') && (p_Var22 != (_CRYPT_PROVIDER_REFS *)0x0)) {
    BCryptFreeBuffer(p_Var22);
  }
  return UVar14;
}



===== BCryptFreeBuffer @ 18000a3e0 =====

void __stdcall BCryptFreeBuffer(PVOID pvBuffer)

{
  undefined8 in_R8;
  
                    /* 0xa3e0  31  BCryptFreeBuffer */
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x11,in_R8,pvBuffer);
  }
  if (pvBuffer == (PVOID)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00018000a42f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,pvBuffer);
  return;
}



===== RegisterReopenWait @ 18000a448 =====

DWORD RegisterReopenWait(void)

{
  DWORD DVar1;
  HANDLE pvVar2;
  
  RtlEnterCriticalSection(DAT_180025b18);
  DVar1 = 0;
  if ((DAT_180025b20 == (HANDLE)0x0) && (g_fLoadCNGDone != 0)) {
    pvVar2 = RegisterWaitForSingleObjectEx
                       (DAT_180025b10,ReopenSystemPreferredRngCallback,(PVOID)0x0,0xffffffff,0x10);
    if (pvVar2 == (HANDLE)0x0) {
      DVar1 = GetLastError();
      if ((int)DVar1 < 1) {
        DVar1 = GetLastError();
      }
      else {
        DVar1 = GetLastError();
        DVar1 = DVar1 & 0xffff | 0xc0070000;
      }
      DebugTraceError((char)DVar1,"Status",
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\syspref.c",0xd6);
    }
    else {
      LOCK();
      UNLOCK();
      DAT_180025b20 = pvVar2;
    }
  }
  RtlLeaveCriticalSection(DAT_180025b18);
  return DVar1;
}



===== BCryptKeyDerivation @ 18000a520 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

int BCryptKeyDerivation(uint *param_1,undefined8 param_2,longlong param_3,int param_4,
                       longlong param_5,undefined4 param_6)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  
                    /* 0xa520  41  BCryptKeyDerivation */
  uVar2 = param_2;
  lVar3 = param_3;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_qqqDqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,param_3,param_1,(char)param_2,
                  (char)param_3,(char)param_4,(char)param_5,(char)param_6);
  }
  if (((param_5 == 0) || (param_3 == 0)) || (param_4 == 0)) {
    iVar1 = -0x3ffffff3;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff3;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return -0x3ffffff3;
    }
    uVar5 = 0xfe;
    uVar4 = 0xd;
  }
  else {
    if (((param_1 != (uint *)0x0) && (0x1f < *param_1)) && (param_1[1] == 0x55555552)) {
      if (*(int *)(*(longlong *)(param_1 + 2) + 0x24) != 7) {
        DebugTraceError(0xbb,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",0x13
                       );
        return -0x3fffff45;
      }
      iVar1 = (**(code **)(*(longlong *)(param_1 + 2) + 0x68))
                        (*(undefined8 *)(param_1 + 4),param_2,param_3,param_4,param_5,param_6);
      if (iVar1 < 0) {
        DebugTraceError((char)iVar1,"Status",
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",0x1f);
        return iVar1;
      }
      return 0;
    }
    iVar1 = -0x3ffffff8;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff8;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return -0x3ffffff8;
    }
    uVar5 = 6;
    uVar4 = 8;
  }
  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar2,lVar3,"Status",uVar4,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar5);
  return iVar1;
}



===== BCryptDuplicateKey @ 18000a6f0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

NTSTATUS __stdcall
BCryptDuplicateKey(BCRYPT_KEY_HANDLE hKey,BCRYPT_KEY_HANDLE *phNewKey,PUCHAR pbKeyObject,
                  ULONG cbKeyObject,ULONG dwFlags)

{
  BCRYPT_HANDLE pvVar1;
  int iVar2;
  uint *puVar3;
  undefined1 uVar4;
  BCRYPT_KEY_HANDLE *ppvVar5;
  PUCHAR pUVar6;
  undefined1 uVar7;
  undefined **ppuVar8;
  undefined4 *puVar9;
  uint local_38 [2];
  PUCHAR local_30;
  
                    /* 0xa6f0  19  BCryptDuplicateKey */
  pUVar6 = (PUCHAR)0x0;
  local_38[0] = 0;
  local_30 = (PUCHAR)0x0;
  ppvVar5 = phNewKey;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    ppvVar5 = (BCRYPT_KEY_HANDLE *)0x1e;
    WPP_SF_qqqdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x1e,pbKeyObject,hKey,(char)phNewKey,
                 (char)pbKeyObject,(char)cbKeyObject,(char)dwFlags);
  }
  ppuVar8 = (undefined **)WPP_GLOBAL_Control;
  puVar3 = ValidateBaseKeyHandle(hKey);
  if (puVar3 == (uint *)0x0) {
    if (ppuVar8 == &WPP_GLOBAL_Control) {
      return -0x3ffffff8;
    }
    if ((*(byte *)((longlong)ppuVar8 + 0x1c) & 1) == 0) {
      return -0x3ffffff8;
    }
    WPP_SF_sDsd(ppuVar8[2],ppvVar5,"onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",
                "Status",8,"onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",0x4c);
    return -0x3ffffff8;
  }
  if (phNewKey == (BCRYPT_KEY_HANDLE *)0x0) {
    DebugTraceError(0xd,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",0x53);
    return -0x3ffffff3;
  }
  pvVar1 = *(BCRYPT_HANDLE *)(puVar3 + 2);
  if (pbKeyObject == (PUCHAR)0x0) {
    if (cbKeyObject == 0) {
      iVar2 = AllocateObjectBuffer(pvVar1,(longlong *)&local_30,local_38);
      if (iVar2 < 0) {
        DebugTraceError((char)iVar2,"Status",
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",0x62);
        pUVar6 = local_30;
        goto LAB_18000a80c;
      }
      pbKeyObject = local_30;
      pUVar6 = local_30;
      cbKeyObject = local_38[0];
    }
    if (pbKeyObject != (PUCHAR)0x0) goto LAB_18000a79b;
    iVar2 = -0x3ffffff3;
    uVar7 = 0x73;
    uVar4 = 0xd;
  }
  else {
LAB_18000a79b:
    if (cbKeyObject < 0x3e) {
      iVar2 = -0x3fffffdd;
      goto LAB_18000a80c;
    }
    puVar9 = (undefined4 *)((ulonglong)(pbKeyObject + 0xf) & 0xfffffffffffffff0);
    *puVar9 = 0x20;
    puVar9[1] = 0x55555552;
    *(BCRYPT_HANDLE *)(puVar9 + 2) = pvVar1;
    *(PUCHAR *)(puVar9 + 6) = pUVar6;
    if ((*(int *)((longlong)pvVar1 + 0x24) == 1) || (*(int *)((longlong)pvVar1 + 0x24) == 7)) {
      iVar2 = (**(code **)((longlong)pvVar1 + 0x80))
                        (*(undefined8 *)(puVar3 + 4),puVar9 + 4,puVar9 + 8,
                         ((int)pbKeyObject - (int)(puVar9 + 8)) + cbKeyObject,dwFlags);
      if (-1 < iVar2) {
        *phNewKey = puVar9;
        local_30 = (PUCHAR)0x0;
        pUVar6 = (PUCHAR)0x0;
        goto LAB_18000a80c;
      }
      uVar7 = 0xa2;
      uVar4 = (undefined1)iVar2;
    }
    else {
      iVar2 = -0x3fffff45;
      uVar7 = 0x97;
      uVar4 = 0xbb;
    }
  }
  DebugTraceError(uVar4,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar7);
LAB_18000a80c:
  if (pUVar6 != (PUCHAR)0x0) {
    SafeAllocaFreeToHeap(pUVar6);
  }
  if ((pvVar1 != (BCRYPT_HANDLE)0x0) && (-1 < iVar2)) {
    LOCK();
    *(int *)((longlong)pvVar1 + 0x10) = *(int *)((longlong)pvVar1 + 0x10) + 1;
    UNLOCK();
  }
  return iVar2;
}



===== BCryptSecretAgreement @ 18000a980 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

NTSTATUS __stdcall
BCryptSecretAgreement
          (BCRYPT_KEY_HANDLE hPrivKey,BCRYPT_KEY_HANDLE hPubKey,BCRYPT_SECRET_HANDLE *phAgreedSecret
          ,ULONG dwFlags)

{
  longlong lVar1;
  code *pcVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  undefined4 *puVar6;
  undefined1 uVar7;
  BCRYPT_KEY_HANDLE pvVar8;
  undefined1 uVar9;
  undefined **ppuVar10;
  
                    /* 0xa980  53  BCryptSecretAgreement */
  puVar6 = (undefined4 *)0x0;
  pvVar8 = hPubKey;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_qqqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),hPubKey,phAgreedSecret,hPrivKey,
                (char)hPubKey,(char)phAgreedSecret,(char)dwFlags);
  }
  ppuVar10 = (undefined **)WPP_GLOBAL_Control;
  puVar4 = ValidateBaseKeyHandle(hPrivKey);
  puVar5 = ValidateBaseKeyHandle(hPubKey);
  if ((puVar4 == (uint *)0x0) || (puVar5 == (uint *)0x0)) {
    iVar3 = -0x3ffffff8;
    uVar7 = 8;
    uVar9 = 0x95;
  }
  else {
    if (phAgreedSecret == (BCRYPT_SECRET_HANDLE *)0x0) {
      DebugTraceError(0xd,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",0x9c);
      return -0x3ffffff3;
    }
    lVar1 = *(longlong *)(puVar4 + 2);
    if (*(int *)(lVar1 + 0x24) != 4) {
      if (ppuVar10 == &WPP_GLOBAL_Control) {
        return -0x3fffff45;
      }
      if ((*(byte *)((longlong)ppuVar10 + 0x1c) & 1) == 0) {
        return -0x3fffff45;
      }
      WPP_SF_sDsd(ppuVar10[2],pvVar8,"onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",
                  "Status",0xbb,"onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",0xaa);
      return -0x3fffff45;
    }
    pcVar2 = *(code **)(lVar1 + 0x58);
    puVar6 = (undefined4 *)
             RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,0x18);
    if (puVar6 == (undefined4 *)0x0) {
      return -0x3fffffe9;
    }
    iVar3 = (*pcVar2)(*(undefined8 *)(puVar4 + 4),*(undefined8 *)(puVar5 + 4),puVar6 + 4,dwFlags);
    if (-1 < iVar3) {
      *puVar6 = 0x18;
      puVar6[1] = 0x55555554;
      *(longlong *)(puVar6 + 2) = lVar1;
      LOCK();
      *(int *)(lVar1 + 0x10) = *(int *)(lVar1 + 0x10) + 1;
      UNLOCK();
      *phAgreedSecret = puVar6;
      return iVar3;
    }
    uVar7 = (undefined1)iVar3;
    uVar9 = 0xbc;
  }
  DebugTraceError(uVar7,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar9);
  if (puVar6 != (undefined4 *)0x0) {
    SafeAllocaFreeToHeap(puVar6);
  }
  return iVar3;
}



===== ValidateBaseKeyHandle @ 18000ab70 =====

uint * ValidateBaseKeyHandle(uint *param_1)

{
  uint *puVar1;
  
  if ((param_1 == (uint *)0x0) || (*param_1 < 0x20)) {
    return (uint *)0x0;
  }
  puVar1 = (uint *)0x0;
  if (param_1[1] == 0x55555552) {
    puVar1 = param_1;
  }
  return puVar1;
}



===== UnloadProvider @ 18000aba0 =====

void UnloadProvider(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  
  if ((g_fLoaderInitialized == 0) || (param_1 == (undefined8 *)0x0)) {
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&g_csLoaderLock);
  iVar1 = *(int *)(param_1 + 2);
  *(int *)(param_1 + 2) = iVar1 + -1;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 0x20) != 0)) {
    WPP_SF_qSD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),&WPP_GLOBAL_Control,param_3,param_1,
               (wchar_t *)*param_1,(char)(iVar1 + -1));
  }
  if (*(int *)(param_1 + 2) == 0) {
    if ((HMODULE)param_1[1] != (HMODULE)0x0) {
      _FreeImage((HMODULE)param_1[1]);
    }
    puVar3 = g_pLoadedProviderList;
    if (param_1 == g_pLoadedProviderList) {
      g_pLoadedProviderList = (undefined8 *)param_1[3];
    }
    else {
      do {
        puVar2 = puVar3;
        if (puVar2 == (undefined8 *)0x0) break;
        puVar3 = (undefined8 *)puVar2[3];
      } while ((undefined8 *)puVar2[3] != param_1);
      puVar2[3] = param_1[3];
    }
    param_1[3] = 0;
    SafeAllocaFreeToHeap(param_1);
  }
                    /* WARNING: Could not recover jumptable at 0x00018000abfd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LeaveCriticalSection((LPCRITICAL_SECTION)&g_csLoaderLock);
  return;
}



===== ValidateBaseObjectHandle @ 18000ac90 =====

uint * ValidateBaseObjectHandle(uint *param_1)

{
  if (((param_1 == (uint *)0x0) || (*param_1 < 0x18)) || (2 < param_1[1] + 0xaaaaaaae)) {
    return (uint *)0x0;
  }
  return param_1;
}



===== BCryptGetFipsAlgorithmMode @ 18000acc0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

NTSTATUS __stdcall BCryptGetFipsAlgorithmMode(BOOLEAN *pfEnabled)

{
  int iVar1;
  undefined1 auStack_c8 [32];
  undefined4 local_a8;
  undefined4 *local_a0;
  int local_98;
  undefined4 local_94;
  longlong local_90 [6];
  undefined8 local_60;
  undefined8 uStack_58;
  longlong *local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  ulonglong uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined4 local_20;
  ulonglong local_18;
  
                    /* 0xacc0  35  BCryptGetFipsAlgorithmMode */
  local_18 = __security_cookie ^ (ulonglong)auStack_c8;
  local_98 = 0;
  local_90[4] = 0;
  local_90[5] = 0;
  local_90[1] = 0;
  local_90[2] = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = (longlong *)0x0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = uStack_38 & 0xffffffff00000000;
  local_90[0] = 0;
  local_90[3] = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_20 = 0;
  local_94 = 0;
  if (pfEnabled == (BOOLEAN *)0x0) {
    local_98 = -0x3ffffff3;
  }
  else {
    *pfEnabled = '\0';
    RtlInitUnicodeString
              (local_90 + 4,
               L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Lsa\\FipsAlgorithmPolicy")
    ;
    RtlInitUnicodeString(local_90 + 1,L"Enabled");
    local_60 = CONCAT44(local_60._4_4_,0x30);
    uStack_58 = 0;
    uStack_48 = CONCAT44(uStack_48._4_4_,0x240);
    local_50 = local_90 + 4;
    local_40 = 0;
    uStack_38 = 0;
    local_98 = NtOpenKey(local_90,1,&local_60);
    if (-1 < local_98) {
      local_a0 = &local_94;
      local_a8 = 0x14;
      local_98 = NtQueryValueKey(local_90[0],local_90 + 1,2,&local_30);
      if (-1 < local_98) {
        if (((int)uStack_28 == 4) && (local_30._4_4_ == 4)) {
          if (uStack_28._4_1_ != '\0') {
            *pfEnabled = '\x01';
          }
        }
        else {
          local_98 = -0x3fffffc2;
        }
      }
    }
    if (local_98 < 0) {
      local_98 = 0;
    }
    if (*pfEnabled == '\0') {
      RtlInitUnicodeString
                (local_90 + 4,L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Lsa");
      RtlInitUnicodeString(local_90 + 1,L"FipsAlgorithmPolicy");
      local_60 = CONCAT44(local_60._4_4_,0x30);
      uStack_58 = 0;
      uStack_48 = CONCAT44(uStack_48._4_4_,0x240);
      local_50 = local_90 + 4;
      local_40 = 0;
      uStack_38 = 0;
      local_98 = NtOpenKey(local_90 + 3,1,&local_60);
      if (-1 < local_98) {
        local_a0 = &local_94;
        local_a8 = 0x14;
        local_98 = NtQueryValueKey(local_90[3],local_90 + 1,2,&local_30);
        if (-1 < local_98) {
          if ((local_30._4_4_ == 4) && ((int)uStack_28 == 4)) {
            if (uStack_28._4_1_ != '\0') {
              *pfEnabled = '\x01';
            }
          }
          else {
            local_98 = -0x3fffffc2;
          }
        }
      }
      if (local_98 < 0) {
        local_98 = 0;
      }
      if (*pfEnabled == '\0') {
        iVar1 = local_98;
        if (local_90[0] == 0) goto LAB_18000afe8;
        RtlInitUnicodeString(local_90 + 1,L"MDMEnabled");
        local_a0 = &local_94;
        local_a8 = 0x14;
        local_98 = NtQueryValueKey(local_90[0],local_90 + 1,2,&local_30);
        if (-1 < local_98) {
          if ((local_30._4_4_ == 4) && ((int)uStack_28 == 4)) {
            if (uStack_28._4_1_ != '\0') {
              *pfEnabled = '\x01';
            }
          }
          else {
            local_98 = -0x3fffffc2;
          }
        }
        if (local_98 < 0) {
          local_98 = 0;
        }
      }
    }
  }
  iVar1 = local_98;
  if (local_90[0] != 0) {
    NtClose();
  }
LAB_18000afe8:
  if (local_90[3] != 0) {
    NtClose();
  }
  return iVar1;
}



===== SymCryptDetectCpuFeaturesByCpuid @ 18000b044 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00018000b16c) */
/* WARNING: Removing unreachable block (ram,0x00018000b13e) */
/* WARNING: Removing unreachable block (ram,0x00018000b11d) */
/* WARNING: Removing unreachable block (ram,0x00018000b0e2) */
/* WARNING: Removing unreachable block (ram,0x00018000b07f) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SymCryptDetectCpuFeaturesByCpuid(void)

{
  byte bVar1;
  uint *puVar2;
  uint *puVar3;
  longlong lVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined8 uVar7;
  uint uVar8;
  byte *pbVar9;
  uint uVar10;
  uint uVar11;
  byte in_XCR0;
  uint local_28 [4];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)local_28;
  uVar8 = 0;
  pbVar9 = &DAT_18001f292;
  g_SymCryptCpuFeaturesNotPresent = 0xffffc020;
  uVar11 = 0;
  puVar2 = (uint *)cpuid_basic_info(0);
  local_28[0] = *puVar2;
  local_28[1] = puVar2[1];
  local_28[2] = puVar2[3];
  local_28[3] = puVar2[2];
  do {
    bVar1 = pbVar9[-2];
    uVar10 = (uint)bVar1;
    if (uVar10 != uVar8) {
      if (uVar10 == 0) {
        puVar3 = (uint *)cpuid_basic_info(0);
      }
      else if (uVar10 == 1) {
        puVar3 = (uint *)cpuid_Version_info(1);
      }
      else if (uVar10 == 2) {
        puVar3 = (uint *)cpuid_cache_tlb_info(2);
      }
      else if (uVar10 == 3) {
        puVar3 = (uint *)cpuid_serial_info(3);
      }
      else if (uVar10 == 4) {
        puVar3 = (uint *)cpuid_Deterministic_Cache_Parameters_info(4);
      }
      else if (uVar10 == 5) {
        puVar3 = (uint *)cpuid_MONITOR_MWAIT_Features_info(5);
      }
      else if (uVar10 == 6) {
        puVar3 = (uint *)cpuid_Thermal_Power_Management_info(6);
      }
      else if (uVar10 == 7) {
        puVar3 = (uint *)cpuid_Extended_Feature_Enumeration_info(7);
      }
      else if (uVar10 == 9) {
        puVar3 = (uint *)cpuid_Direct_Cache_Access_info(9);
      }
      else if (uVar10 == 10) {
        puVar3 = (uint *)cpuid_Architectural_Performance_Monitoring_info(10);
      }
      else if (uVar10 == 0xb) {
        puVar3 = (uint *)cpuid_Extended_Topology_info(0xb);
      }
      else if (uVar10 == 0xd) {
        puVar3 = (uint *)cpuid_Processor_Extended_States_info(0xd);
      }
      else if (uVar10 == 0xf) {
        puVar3 = (uint *)cpuid_Quality_of_Service_info(0xf);
      }
      else if (uVar10 == 0x80000002) {
        puVar3 = (uint *)cpuid_brand_part1_info(0x80000002);
      }
      else if (uVar10 == 0x80000003) {
        puVar3 = (uint *)cpuid_brand_part2_info(0x80000003);
      }
      else if (uVar10 == 0x80000004) {
        puVar3 = (uint *)cpuid_brand_part3_info(0x80000004);
      }
      else {
        puVar3 = (uint *)cpuid(uVar10);
      }
      local_28[0] = *puVar3;
      local_28[1] = puVar3[1];
      local_28[2] = puVar3[3];
      local_28[3] = puVar3[2];
      uVar8 = (uint)bVar1;
    }
    if (((int)*puVar2 < (int)(uint)bVar1) || ((local_28[pbVar9[-1]] >> (*pbVar9 & 0x1f) & 1) == 0))
    {
      g_SymCryptCpuFeaturesNotPresent = g_SymCryptCpuFeaturesNotPresent | *(uint *)(pbVar9 + 2);
    }
    uVar11 = uVar11 + 1;
    pbVar9 = pbVar9 + 8;
  } while (uVar11 < 0x14);
  lVar4 = cpuid_Version_info(1);
  if ((*(uint *)(lVar4 + 0xc) >> 0x1b & 1) == 0) {
LAB_18000b1b1:
    g_SymCryptCpuFeaturesNotPresent = g_SymCryptCpuFeaturesNotPresent | 0x10;
  }
  else {
    uVar7 = xinuse(0);
    bVar1 = in_XCR0 & (byte)uVar7;
    if ((bVar1 & 6) != 6) goto LAB_18000b1b1;
    if ((bVar1 & 0xe0) == 0xe0) goto LAB_18000b113;
  }
  g_SymCryptCpuFeaturesNotPresent = g_SymCryptCpuFeaturesNotPresent | 0x1000;
LAB_18000b113:
  if ((g_SymCryptCpuFeaturesNotPresent & 4) == 0) {
    lVar4 = cpuid_basic_info(0);
    if (((*(int *)(lVar4 + 4) == 0x68747541) && (*(int *)(lVar4 + 0xc) == 0x444d4163)) &&
       (*(int *)(lVar4 + 8) == 0x69746e65)) {
      piVar5 = (int *)cpuid_Version_info(1);
      uVar8 = *piVar5 >> 8 & 0xf;
      if ((uVar8 < 0xf) || ((*piVar5 >> 0x14 & 0xffU) + uVar8 < 0x15)) {
        g_SymCryptCpuFeaturesNotPresent = g_SymCryptCpuFeaturesNotPresent | 4;
      }
    }
  }
  puVar6 = (undefined4 *)cpuid_Version_info(1);
  _g_SymCryptCpuid1 = *puVar6;
  _DAT_180025b74 = puVar6[1];
  _DAT_180025b78 = puVar6[3];
  _DAT_180025b7c = puVar6[2];
  return;
}



===== InitializeCNG @ 18000b1c0 =====

ulonglong InitializeCNG(undefined8 param_1,char *param_2,char *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  undefined *puVar3;
  ulonglong uVar4;
  undefined1 uVar5;
  
  SymCryptInitEnvWindowsUsermodeWin8_1nLater();
  uVar1 = g_TrustedEnvironment;
  if (g_TrustedEnvironment == 0) {
    uVar1 = GetTrustedEnvironment();
  }
  if ((uVar1 & 0x18) == 0) {
    uVar2 = InitializeLoader(param_1,param_2,param_3);
    uVar4 = uVar2 & 0xffffffff;
    if ((int)uVar2 == 0) {
      DAT_180025aa8 = DAT_180025aa8 | 2;
      uVar1 = InitializeConfig(param_1,param_2,(wchar_t *)param_3);
      uVar4 = (ulonglong)uVar1;
      if (uVar1 == 0) {
        DAT_180025aa8 = DAT_180025aa8 | 4;
        uVar1 = InitializeSystemPreferredCache();
        uVar4 = (ulonglong)uVar1;
        if (uVar1 == 0) {
          DAT_180025aa8 = DAT_180025aa8 | 8;
          goto LAB_18000b1d9;
        }
        puVar3 = WPP_GLOBAL_Control;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
          uVar5 = 0xab;
          goto LAB_18000b295;
        }
      }
      else {
        puVar3 = WPP_GLOBAL_Control;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
          uVar5 = 0xa2;
LAB_18000b295:
          puVar3 = *(undefined **)(WPP_GLOBAL_Control + 0x10);
          WPP_SF_sDsd(puVar3,param_2,param_3,"Status",(char)uVar4,
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\bcrypt\\init.c",uVar5);
        }
      }
    }
    else {
      param_3 = "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\bcrypt\\init.c";
      param_2 = "Status";
      puVar3 = (undefined *)(uVar2 & 0xffffffff);
      DebugTraceError((char)puVar3,"Status",
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\bcrypt\\init.c",0x99);
    }
    UninitializeCNG(puVar3,param_2,param_3);
  }
  else {
LAB_18000b1d9:
    g_fLoadCNGDone = 1;
    uVar4 = 0;
  }
  return uVar4;
}



===== SymCryptInitEnvWindowsUsermodeWin8_1nLater @ 18000b2c0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SymCryptInitEnvWindowsUsermodeWin8_1nLater(void)

{
  char cVar1;
  ulonglong uVar2;
  char *pcVar3;
  
  if ((g_SymCryptFlags & 1) == 0) {
    SymCryptDetectCpuFeaturesByCpuid();
    uVar2 = GetEnabledXStateFeatures();
    if ((uVar2 & 4) == 0) {
      g_SymCryptCpuFeaturesNotPresent = g_SymCryptCpuFeaturesNotPresent | 0x10;
    }
    if ((uVar2 & 0xe0) == 0) {
      g_SymCryptCpuFeaturesNotPresent = g_SymCryptCpuFeaturesNotPresent | 0x1000;
    }
    g_SymCryptCpuFeaturesNotPresent = g_SymCryptCpuFeaturesNotPresent & 0xffff3fdf;
    LOCK();
    g_SymCryptFlags = g_SymCryptFlags | 1;
    UNLOCK();
    pcVar3 = "v103.12.0__2026-05-07T00:16:03+00:00_0df2f18_2026-05-07T21:50:22";
    cVar1 = 'v';
    while (cVar1 != '\0') {
      pcVar3 = pcVar3 + 1;
      cVar1 = *pcVar3;
    }
    _g_SymCryptCpuFeaturesPresentCheck = ~g_SymCryptCpuFeaturesNotPresent;
  }
  return;
}



===== InitializeConfig @ 18000b348 =====

void InitializeConfig(undefined8 param_1,undefined8 param_2,wchar_t *param_3)

{
  char cVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar2 = g_TrustedEnvironment;
  if (g_TrustedEnvironment == 0) {
    uVar2 = GetTrustedEnvironment();
  }
  uVar3 = (ulonglong)uVar2;
  if ((uVar2 & 1) == 0) {
    TraceLoggingRegisterEx_EventRegister_EventSetInformation(&DAT_180025058,0,0);
  }
  else {
    uVar2 = g_TrustedEnvironment;
    if (g_TrustedEnvironment == 0) {
      uVar2 = GetTrustedEnvironment();
    }
    if ((uVar2 & 1) != 0) {
      InitializeProcessImageNameUM(uVar3,param_2,param_3);
    }
    cVar1 = RtlDllShutdownInProgress();
    if (cVar1 == '\0') {
      TlgRegisterAggregateProviderEx();
    }
  }
  IoStartup();
  return;
}



===== InitializeLoader @ 18000b3b8 =====

ulonglong InitializeLoader(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  uVar2 = 0;
  if (g_fLoaderInitialized == 0) {
    g_pLoadedProviderList = 0;
    uVar1 = _InitializeLoaderLock();
    uVar2 = uVar1 & 0xffffffff;
    if ((int)uVar1 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,param_3,"sResult",(char)uVar1
                    ,"onecore\\ds\\security\\cryptoapi\\ncrypt\\loader\\loader.c",0xac);
      }
    }
    else {
      g_fLoaderInitialized = 1;
    }
  }
  return uVar2;
}



===== _InitializeLoaderLock @ 18000b438 =====

undefined8 _InitializeLoaderLock(void)

{
  InitializeCriticalSection((LPCRITICAL_SECTION)&g_csLoaderLock);
  return 0;
}



===== GetTrustedEnvironment @ 18000b484 =====

void GetTrustedEnvironment(void)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  
  uVar3 = IsEnclave();
  iVar2 = (int)uVar3;
  if (iVar2 == 0) {
    uVar1 = IsTrustlet();
    iVar2 = (-(uint)(uVar1 != 0) & 3) + 1;
  }
  g_TrustedEnvironment = iVar2;
  return;
}



===== IsEnclave @ 18000b4b4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 IsEnclave(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStack_f8 [32];
  undefined8 local_d8;
  int local_c8 [44];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_f8;
  memset(local_c8,0,0xb0);
  local_d8 = 0;
  iVar1 = NtQueryInformationProcess(0xffffffffffffffff,0x56,local_c8);
  if (iVar1 < 0) {
    uVar2 = 0;
  }
  else if (local_c8[0] - 0x10U < 2) {
    uVar2 = 0x10;
  }
  else {
    uVar2 = 1;
    if (local_c8[0] == 1) {
      uVar2 = 8;
    }
  }
  return uVar2;
}



===== IsTrustlet @ 18000b54c =====

uint IsTrustlet(void)

{
  int iVar1;
  uint uVar2;
  undefined8 local_48 [7];
  uint local_10;
  
  memset(local_48,0,0x40);
  local_48[0] = 0x40;
  iVar1 = NtQueryInformationProcess(0xffffffffffffffff,0,local_48,0x40,0);
  if (iVar1 < 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = local_10 >> 7 & 1;
  }
  return uVar2;
}



===== ValidateBaseSecretHandle @ 18000b5ac =====

uint * ValidateBaseSecretHandle(uint *param_1)

{
  uint *puVar1;
  
  puVar1 = (uint *)0x0;
  if (((param_1 != (uint *)0x0) && (0x17 < *param_1)) && (param_1[1] == 0x55555554)) {
    puVar1 = param_1;
  }
  return puVar1;
}



===== TraceLoggingRegisterEx_EventRegister_EventSetInformation @ 18000b5cc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ULONG TraceLoggingRegisterEx_EventRegister_EventSetInformation
                (PVOID param_1,undefined8 param_2,undefined8 param_3)

{
  PREGHANDLE RegHandle;
  undefined2 uVar1;
  longlong lVar2;
  undefined2 *puVar3;
  ULONGLONG UVar4;
  code *pcVar5;
  ULONG UVar6;
  undefined1 *puVar7;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  ulonglong local_18;
  
  puVar7 = auStack_48;
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  lVar2 = *(longlong *)((longlong)param_1 + 8);
  RegHandle = (PREGHANDLE)((longlong)param_1 + 0x20);
  local_28 = *(undefined4 *)(lVar2 + -0x10);
  uStack_24 = *(undefined4 *)(lVar2 + -0xc);
  uStack_20 = *(undefined4 *)(lVar2 + -8);
  uStack_1c = *(undefined4 *)(lVar2 + -4);
  if (*RegHandle != 0) {
    pcVar5 = (code *)swi(0x29);
    (*pcVar5)(5);
    puVar7 = auStack_40;
  }
  *(undefined8 *)((longlong)param_1 + 0x28) = param_2;
  *(undefined8 *)((longlong)param_1 + 0x30) = param_3;
  *(undefined8 *)(puVar7 + -8) = 0x18000b626;
  UVar6 = EventRegister((LPCGUID)(puVar7 + 0x20),_tlgEnableCallback,param_1,RegHandle);
  if (UVar6 == 0) {
    puVar3 = *(undefined2 **)((longlong)param_1 + 8);
    UVar4 = *RegHandle;
    uVar1 = *puVar3;
    *(undefined8 *)(puVar7 + -8) = 0x18000b646;
    EventSetInformation(UVar4,2,puVar3,uVar1);
  }
  else if (0 < (int)UVar6) {
    UVar6 = UVar6 & 0xffff | 0x80070000;
  }
  *(undefined8 *)(puVar7 + -8) = 0x18000b65a;
  return UVar6;
}



===== ShouldRouterPadSignature @ 18000b688 =====

undefined8 ShouldRouterPadSignature(byte param_1,byte param_2,undefined4 *param_3)

{
  *param_3 = 0;
  if ((((param_1 & 1) != 0) && ((param_2 & 2) == 0 || (param_1 & 4) == 0)) &&
     ((param_2 & 8) == 0 || (param_1 & 0x10) == 0)) {
    *param_3 = 1;
  }
  return 0;
}



===== _tlgEnableCallback @ 18000b6d0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

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



===== SafeAllocaInitialize @ 18000b74c =====

void SafeAllocaInitialize(void)

{
  longlong lVar1;
  
  lVar1 = RtlImageNtHeader(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x10));
  if (((*(char *)((longlong)ProcessEnvironmentBlock + 2) != '\0') || (lVar1 == 0)) ||
     (g_ulMaxStackAllocSize = *(longlong *)(lVar1 + 0x68),
     (ulonglong)(*(longlong *)(lVar1 + 0x60) - g_ulMaxStackAllocSize) < 0x3000)) {
    g_ulMaxStackAllocSize = 0;
  }
  if (lVar1 != 0) {
    g_ulAdditionalProbeSize = (ulonglong)DAT_ff00001748;
    if (g_ulAdditionalProbeSize == 0) {
      g_pfnAllocate = BCryptAlloc;
      g_ulAdditionalProbeSize = 0x3000;
      g_pfnFree = SafeAllocaFreeToHeap;
      return;
    }
    if (7 < g_ulAdditionalProbeSize + 8) {
      g_pfnAllocate = BCryptAlloc;
      g_pfnFree = SafeAllocaFreeToHeap;
      return;
    }
  }
  g_ulAdditionalProbeSize = 0xfffffffffffffff7;
  g_pfnAllocate = BCryptAlloc;
  g_pfnFree = SafeAllocaFreeToHeap;
  return;
}



===== WppInitUm @ 18000b80c =====

void WppInitUm(void)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 local_18;
  undefined8 local_10;
  
  puVar2 = &WPP_REGISTRATION_GUIDS;
  for (puVar1 = (undefined8 *)WPP_GLOBAL_Control; puVar1 != (undefined8 *)0x0;
      puVar1 = (undefined8 *)*puVar1) {
    local_18 = *puVar2;
    local_10 = 0;
    puVar2 = puVar2 + 1;
    puVar1[4] = local_18;
    EtwRegisterTraceGuidsW(WppControlCallback,puVar1,local_18,1,&local_18,0,0,puVar1 + 1);
  }
  return;
}



===== IoStartup @ 18000b894 =====

/* long __cdecl IoStartup(void) */

long __cdecl IoStartup(void)

{
  if (DAT_180025ad8 == 0) {
    g_hIoDevice = (void *)0x0;
    InitializeCriticalSection(&g_csIoInitialize);
    DAT_180025ad8 = 1;
  }
  return 0;
}



===== WppCleanupUm @ 18000b8dc =====

void WppCleanupUm(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)WPP_GLOBAL_Control;
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    for (; puVar1 != (undefined8 *)0x0; puVar1 = (undefined8 *)*puVar1) {
      if (puVar1[1] != 0) {
        EtwUnregisterTraceGuids();
        puVar1[1] = 0;
      }
    }
    WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
  }
  return;
}



===== McGenEventRegister_EtwEventRegister @ 18000b938 =====

void McGenEventRegister_EtwEventRegister(void)

{
  if (ETW_LOG_BCRYPT_PROVIDER_Context == 0) {
    EtwEventRegister(&ETW_LOG_BCRYPT_PROVIDER,McGenControlCallbackV2,
                     &ETW_LOG_BCRYPT_PROVIDER_Context,&ETW_LOG_BCRYPT_PROVIDER_Context);
  }
  return;
}



===== McGenEventUnregister_EtwEventUnregister @ 18000b978 =====

undefined8 McGenEventUnregister_EtwEventUnregister(void)

{
  undefined8 uVar1;
  
  if (ETW_LOG_BCRYPT_PROVIDER_Context == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwEventUnregister();
    ETW_LOG_BCRYPT_PROVIDER_Context = 0;
  }
  return uVar1;
}



===== ReverseMemCopy @ 18000b9ac =====

void ReverseMemCopy(undefined1 *param_1,undefined1 *param_2,uint param_3)

{
  undefined1 *puVar1;
  
  for (puVar1 = param_1 + ((ulonglong)param_3 - 1); param_1 <= puVar1; puVar1 = puVar1 + -1) {
    *puVar1 = *param_2;
    param_2 = param_2 + 1;
  }
  return;
}



===== ConvertRsaFullPrivateBlob @ 18000b9d0 =====

int ConvertRsaFullPrivateBlob
              (int *param_1,undefined8 param_2,undefined4 *param_3,uint param_4,uint *param_5)

{
  int iVar1;
  ulonglong uVar2;
  uint *puVar3;
  uint local_38 [2];
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_10;
  
  local_38[0] = 0;
  puVar3 = local_38;
  iVar1 = VerifyRsaFullPrivateBlob(param_1,(uint)param_2,(int *)puVar3);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,puVar3,"Status",(char)iVar1,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\translate\\bcrypttranslate.c",0x49);
    }
  }
  else {
    uVar2 = (ulonglong)local_38[0];
    *param_5 = local_38[0];
    if (param_3 != (undefined4 *)0x0) {
      if (param_4 < local_38[0]) {
        return -0x7ff6ffd8;
      }
      local_30 = *(undefined8 *)param_1;
      uStack_28 = *(undefined8 *)(param_1 + 2);
      local_10 = *(undefined8 *)(param_1 + 4);
      memset(param_3,0,(ulonglong)param_4);
      *param_3 = 0x32415352;
      param_3[1] = local_30._4_4_;
      param_3[3] = uStack_28._4_4_;
      param_3[4] = (undefined4)local_10;
      param_3[5] = (int)((ulonglong)local_10 >> 0x20);
      param_3[2] = (undefined4)uStack_28;
      memcpy(param_3 + 6,param_1 + 6,uVar2 - 0x18);
    }
    iVar1 = 0;
  }
  return iVar1;
}



===== VerifyRsaFullPrivateBlob @ 18000bb0c =====

undefined4 VerifyRsaFullPrivateBlob(int *param_1,uint param_2,int *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined1 uVar4;
  int iVar5;
  uint local_18;
  
  if ((param_1 == (int *)0x0) || (param_2 < 0x18)) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0x80090027;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return 0x80090027;
    }
    WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x80090027,param_3,"Status",0x27,
                "onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\translate.c",0x28);
    return 0x80090027;
  }
  uVar1 = param_1[3];
  if ((((*param_1 == 0x33415352) && ((uint)param_1[1] >> 3 == uVar1)) && ((uint)param_1[2] <= uVar1)
      ) && ((local_18 = (uint)*(undefined8 *)(param_1 + 4), local_18 <= uVar1 &&
            (uVar3 = (uint)((ulonglong)*(undefined8 *)(param_1 + 4) >> 0x20), uVar3 <= uVar1)))) {
    iVar5 = param_1[2] + 0x18U + uVar1 + uVar3 + local_18;
    if (uVar1 + local_18 * 2 + uVar3 + iVar5 <= param_2) {
      if (param_1[1] - 0x100U < 0x3f01) {
        *param_3 = iVar5;
        return 0;
      }
      uVar2 = 0x80090029;
      uVar4 = 0x52;
      goto LAB_18000bbea;
    }
    uVar4 = 0x4a;
  }
  else {
    uVar4 = 0x35;
  }
  uVar2 = 0x80090005;
LAB_18000bbea:
  DebugTraceError((char)uVar2,"Status",
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\translate.c",uVar4);
  return uVar2;
}



===== RouterAesKeyWrap @ 18000bc58 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int RouterAesKeyWrap(longlong param_1,longlong param_2,void *param_3,uint param_4,uint *param_5)

{
  uint uVar1;
  undefined8 uVar2;
  code *pcVar3;
  uint uVar4;
  int iVar5;
  ulonglong *puVar6;
  ulonglong uVar7;
  longlong lVar8;
  wchar_t *pwVar9;
  undefined8 *puVar10;
  undefined1 uVar11;
  undefined1 uVar12;
  uint uVar13;
  ulonglong *puVar14;
  undefined1 auStackY_158 [32];
  uint local_f8;
  int local_f4;
  int local_f0;
  int local_ec;
  void *local_e8;
  undefined8 local_e0;
  code *local_d8;
  ulonglong local_d0;
  ulonglong local_c8;
  undefined8 local_c0;
  ulonglong local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  ulonglong local_98 [10];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_158;
  local_f0 = 0;
  uVar2 = *(undefined8 *)(param_1 + 0x10);
  local_f8 = 0;
  local_f4 = 0;
  pcVar3 = *(code **)(*(longlong *)(param_1 + 8) + 0x40);
  local_d8 = *(code **)(*(longlong *)(param_2 + 8) + 0x60);
  local_e0 = *(undefined8 *)(param_2 + 0x10);
  pwVar9 = L"BlockLength";
  local_e8 = param_3;
  iVar5 = (**(code **)(*(longlong *)(param_2 + 8) + 0x40))(local_e0,L"BlockLength",&local_f0,4);
  if (iVar5 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pwVar9,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\routeraeskeywrap.c","Status",
                  (char)iVar5,"onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\routeraeskeywrap.c",
                  0xba);
    }
  }
  else {
    if ((local_f4 == 4) && (local_f0 == 0x10)) {
      iVar5 = (*pcVar3)(uVar2,L"KeyLength",&local_f8,4);
      if (-1 < iVar5) {
        local_f8 = local_f8 >> 3;
        if ((local_f4 != 4) || ((local_f8 & 7) != 0)) {
          iVar5 = -0x3ffffff8;
          goto LAB_18000bf9f;
        }
        uVar1 = local_f8 + 8;
        if (local_e8 == (void *)0x0) {
          iVar5 = 0;
        }
        else {
          if (uVar1 <= param_4) {
            if (uVar1 < 0x49) {
              puVar6 = local_98;
              puVar14 = (ulonglong *)0x0;
            }
            else {
              puVar6 = (ulonglong *)BCryptAlloc((ulonglong)uVar1);
              if (puVar6 == (ulonglong *)0x0) {
                iVar5 = -0x3fffffe9;
                DebugTraceError(0x17,"Status",
                                "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\routeraeskeywrap.c"
                                ,0);
                goto LAB_18000be19;
              }
              puVar14 = puVar6;
            }
            iVar5 = RouterGetKeyDataBlob(param_1,puVar6 + 1,local_f8);
            if (iVar5 < 0) {
              uVar12 = 0x12;
LAB_18000be40:
              DebugTraceError((char)iVar5,"Status",
                              "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\routeraeskeywrap.c",
                              uVar12);
            }
            else {
              uVar7 = 0xa6a6a6a6a6a6a6a6;
              uVar4 = local_f8 >> 3;
              for (uVar13 = 0; uVar13 < 6; uVar13 = uVar13 + 1) {
                local_d0 = 0;
                while( true ) {
                  local_ec = (int)local_d0;
                  if (uVar4 <= local_d0) break;
                  local_b8 = (ulonglong)(uint)(local_ec * 8);
                  local_c0 = *(undefined8 *)(local_b8 + 8 + (longlong)puVar6);
                  local_b0 = 0;
                  uStack_a8 = 0;
                  local_c8 = uVar7;
                  iVar5 = (*local_d8)(local_e0,&local_c8,0x10);
                  if (iVar5 < 0) {
                    uVar12 = 0x35;
                    goto LAB_18000be40;
                  }
                  uVar7 = (ulonglong)uVar13 * (ulonglong)uVar4 + local_d0 + 1;
                  uVar7 = (uVar7 >> 0x38 | (uVar7 & 0xff000000000000) >> 0x28 |
                           (uVar7 & 0xff0000000000) >> 0x18 | (uVar7 & 0xff00000000) >> 8 |
                           (uVar7 & 0xff000000) << 8 | (uVar7 & 0xff0000) << 0x18 |
                           (uVar7 & 0xff00) << 0x28 | uVar7 << 0x38) ^ local_c8;
                  *(undefined8 *)(local_b8 + 8 + (longlong)puVar6) = local_c0;
                  local_d0 = (ulonglong)(local_ec + 1);
                }
              }
              *puVar6 = uVar7;
              memcpy(local_e8,puVar6,(ulonglong)uVar1);
              iVar5 = 0;
            }
            *param_5 = uVar1;
            if (puVar6 != (ulonglong *)0x0) {
              for (uVar7 = (ulonglong)uVar1; uVar7 != 0; uVar7 = uVar7 - 1) {
                *(undefined1 *)puVar6 = 0;
                puVar6 = (ulonglong *)((longlong)puVar6 + 1);
              }
            }
            if (puVar14 != (ulonglong *)0x0) {
              BCryptFree((longlong)puVar14);
            }
            goto LAB_18000bfa2;
          }
          iVar5 = -0x3fffffdd;
        }
LAB_18000be19:
        *param_5 = uVar1;
        goto LAB_18000bfa2;
      }
      uVar11 = 0xd0;
      uVar12 = (undefined1)iVar5;
    }
    else {
      iVar5 = -0x3ffffff8;
      uVar11 = 0xc2;
      uVar12 = 8;
    }
    DebugTraceError(uVar12,"Status",
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\routeraeskeywrap.c",uVar11);
  }
LAB_18000bf9f:
  *param_5 = 0;
LAB_18000bfa2:
  puVar10 = &local_b0;
  for (lVar8 = 0x10; lVar8 != 0; lVar8 = lVar8 + -1) {
    *(undefined1 *)puVar10 = 0;
    puVar10 = (undefined8 *)((longlong)puVar10 + 1);
  }
  puVar6 = &local_c8;
  for (lVar8 = 0x10; lVar8 != 0; lVar8 = lVar8 + -1) {
    *(undefined1 *)puVar6 = 0;
    puVar6 = (ulonglong *)((longlong)puVar6 + 1);
  }
  puVar6 = &local_b8;
  for (lVar8 = 8; lVar8 != 0; lVar8 = lVar8 + -1) {
    *(undefined1 *)puVar6 = 0;
    puVar6 = (ulonglong *)((longlong)puVar6 + 1);
  }
  return iVar5;
}



===== ExportLegacyRsaKey @ 18000bff0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

ulonglong ExportLegacyRsaKey(undefined *param_1,undefined8 param_2,undefined8 param_3,
                            wchar_t *param_4,undefined8 *param_5,uint param_6,uint *param_7,
                            int param_8)

{
  int iVar1;
  uint uVar2;
  undefined1 (*pauVar3) [16];
  undefined1 uVar4;
  ulonglong uVar5;
  undefined1 uVar6;
  ulonglong in_stack_ffffffffffffffc8;
  undefined4 uVar7;
  uint local_18 [4];
  
  local_18[0] = 0;
  if (param_8 != 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc000000d;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return 0xc000000d;
    }
    WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,
                "onecore\\ds\\security\\cryptoapi\\ncrypt\\translate\\bcrypttranslate.c","Status",
                0xd,"onecore\\ds\\security\\cryptoapi\\ncrypt\\translate\\bcrypttranslate.c",99);
    return 0xc000000d;
  }
  iVar1 = wcscmp(param_4,L"CAPIPUBLICBLOB");
  if (iVar1 == 0) {
    in_stack_ffffffffffffffc8 = in_stack_ffffffffffffffc8 & 0xffffffff00000000;
    uVar2 = (*(code *)param_1)(param_2,param_3,L"RSAPUBLICBLOB",0,in_stack_ffffffffffffffc8,local_18
                               ,0);
    uVar7 = (undefined4)(in_stack_ffffffffffffffc8 >> 0x20);
    if (uVar2 == 0) {
      pauVar3 = (undefined1 (*) [16])BCryptAlloc((ulonglong)local_18[0]);
      if (pauVar3 == (undefined1 (*) [16])0x0) {
        uVar6 = 0x7f;
LAB_18000c0e4:
        uVar5 = 0xc0000017;
        uVar4 = 0x17;
        goto LAB_18000c284;
      }
      uVar2 = (*(code *)param_1)(param_2,param_3,L"RSAPUBLICBLOB",pauVar3,
                                 CONCAT44(uVar7,local_18[0]),local_18,0);
      uVar5 = (ulonglong)uVar2;
      if (uVar2 == 0) {
        uVar5 = ConvertRsaPublicBlobToLegacy((longlong)pauVar3,param_3,param_5,param_6,param_7);
        uVar2 = (uint)uVar5;
        uVar5 = uVar5 & 0xffffffff;
        if (uVar2 == 0) {
LAB_18000c268:
          uVar5 = 0;
          goto LAB_18000c26a;
        }
        uVar6 = 0xa0;
      }
      else {
        uVar6 = 0x8d;
      }
LAB_18000c12e:
      DebugTraceError((char)uVar2,"Status",
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\translate\\bcrypttranslate.c",uVar6
                     );
LAB_18000c26a:
      SafeAllocaFreeToHeap(pauVar3);
      return uVar5;
    }
    uVar6 = 0x77;
  }
  else {
    iVar1 = wcscmp(param_4,L"CAPIPRIVATEBLOB");
    if (iVar1 != 0) {
      uVar5 = 0xc00000e5;
      uVar6 = 0xe4;
      uVar4 = 0xe5;
      goto LAB_18000c284;
    }
    in_stack_ffffffffffffffc8 = in_stack_ffffffffffffffc8 & 0xffffffff00000000;
    uVar2 = (*(code *)param_1)(param_2,param_3,L"RSAPRIVATEBLOB",0,in_stack_ffffffffffffffc8,
                               local_18,0);
    uVar7 = (undefined4)(in_stack_ffffffffffffffc8 >> 0x20);
    if (uVar2 == 0) {
      pauVar3 = (undefined1 (*) [16])BCryptAlloc((ulonglong)local_18[0]);
      if (pauVar3 == (undefined1 (*) [16])0x0) {
        uVar6 = 0xbc;
        goto LAB_18000c0e4;
      }
      uVar2 = (*(code *)param_1)(param_2,param_3,L"RSAPRIVATEBLOB",pauVar3,
                                 CONCAT44(uVar7,local_18[0]),local_18,0);
      uVar5 = (ulonglong)uVar2;
      if (uVar2 == 0) {
        uVar2 = ConvertRsaPrivateBlobToLegacy
                          (pauVar3,(ulonglong)local_18[0],(undefined4 *)param_5,param_6,param_7);
        uVar5 = (ulonglong)uVar2;
        if (uVar2 == 0) goto LAB_18000c268;
        uVar6 = 0xdd;
      }
      else {
        uVar6 = 0xca;
      }
      goto LAB_18000c12e;
    }
    uVar6 = 0xb4;
  }
  uVar5 = (ulonglong)uVar2;
  uVar4 = (undefined1)uVar2;
LAB_18000c284:
  DebugTraceError(uVar4,"Status",
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\translate\\bcrypttranslate.c",uVar6);
  return uVar5;
}



===== ExportLegacyDsaKey @ 18000c2bc =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

ulonglong ExportLegacyDsaKey(undefined *param_1,undefined8 param_2,undefined8 param_3,
                            wchar_t *param_4,undefined8 *param_5,uint param_6,uint *param_7,
                            int param_8)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  ulonglong in_stack_ffffffffffffffb8;
  undefined4 uVar7;
  uint local_28 [4];
  
  local_28[0] = 0;
  if (param_8 != 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc000000d;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return 0xc000000d;
    }
    WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,
                "onecore\\ds\\security\\cryptoapi\\ncrypt\\translate\\bcrypttranslate.c","Status",
                0xd,"onecore\\ds\\security\\cryptoapi\\ncrypt\\translate\\bcrypttranslate.c",0xcb);
    return 0xc000000d;
  }
  iVar1 = wcscmp(param_4,L"CAPIDSAPUBLICBLOB");
  if (iVar1 == 0) {
    in_stack_ffffffffffffffb8 = in_stack_ffffffffffffffb8 & 0xffffffff00000000;
    uVar2 = (*(code *)param_1)(param_2,param_3,L"DSAPUBLICBLOB",0,in_stack_ffffffffffffffb8,local_28
                               ,0);
    uVar7 = (undefined4)(in_stack_ffffffffffffffb8 >> 0x20);
    uVar4 = (ulonglong)uVar2;
    if (uVar2 != 0) {
      uVar6 = 0xdf;
LAB_18000c398:
      uVar5 = (undefined1)uVar2;
LAB_18000c6ed:
      DebugTraceError(uVar5,"Status",
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\translate\\bcrypttranslate.c",uVar6
                     );
      return uVar4;
    }
    lVar3 = BCryptAlloc((ulonglong)local_28[0]);
    if (lVar3 == 0) {
      uVar6 = 0xe7;
LAB_18000c3b5:
      uVar4 = 0xc0000017;
      uVar5 = 0x17;
      goto LAB_18000c6ed;
    }
    uVar2 = (*(code *)param_1)(param_2,param_3,L"DSAPUBLICBLOB",lVar3,CONCAT44(uVar7,local_28[0]),
                               local_28,0);
    uVar4 = (ulonglong)uVar2;
    if (uVar2 == 0) {
      uVar4 = ConvertDsaPublicBlobToLegacy(lVar3,param_3,param_5,param_6,param_7);
      uVar2 = (uint)uVar4;
      uVar4 = uVar4 & 0xffffffff;
      if (uVar2 == 0) goto LAB_18000c6cb;
      uVar5 = 7;
    }
    else {
      uVar5 = 0xf5;
    }
  }
  else {
    iVar1 = wcscmp(param_4,L"V2CAPIDSAPUBLICBLOB");
    if (iVar1 == 0) {
      in_stack_ffffffffffffffb8 = in_stack_ffffffffffffffb8 & 0xffffffff00000000;
      uVar2 = (*(code *)param_1)(param_2,param_3,L"DSAPUBLICBLOB",0,in_stack_ffffffffffffffb8,
                                 local_28,0);
      uVar7 = (undefined4)(in_stack_ffffffffffffffb8 >> 0x20);
      uVar4 = (ulonglong)uVar2;
      if (uVar2 != 0) {
        uVar6 = 0x1b;
        goto LAB_18000c398;
      }
      lVar3 = BCryptAlloc((ulonglong)local_28[0]);
      if (lVar3 == 0) {
        uVar6 = 0x23;
        goto LAB_18000c3b5;
      }
      uVar2 = (*(code *)param_1)(param_2,param_3,L"DSAPUBLICBLOB",lVar3,CONCAT44(uVar7,local_28[0]),
                                 local_28,0);
      uVar4 = (ulonglong)uVar2;
      if (uVar2 == 0) {
        uVar4 = ConvertDsaPublicBlobToLegacyV2(lVar3,param_3,param_5,param_6,param_7);
        uVar2 = (uint)uVar4;
        uVar4 = uVar4 & 0xffffffff;
        if (uVar2 == 0) goto LAB_18000c6cb;
        uVar5 = 0x43;
      }
      else {
        uVar5 = 0x31;
      }
    }
    else {
      iVar1 = wcscmp(param_4,L"CAPIDSAPRIVATEBLOB");
      if (iVar1 == 0) {
        in_stack_ffffffffffffffb8 = in_stack_ffffffffffffffb8 & 0xffffffff00000000;
        uVar2 = (*(code *)param_1)(param_2,param_3,L"DSAPRIVATEBLOB",0,in_stack_ffffffffffffffb8,
                                   local_28,0);
        uVar7 = (undefined4)(in_stack_ffffffffffffffb8 >> 0x20);
        uVar4 = (ulonglong)uVar2;
        if (uVar2 != 0) {
          uVar6 = 0x57;
          goto LAB_18000c398;
        }
        lVar3 = BCryptAlloc((ulonglong)local_28[0]);
        if (lVar3 == 0) {
          uVar6 = 0x5f;
          goto LAB_18000c3b5;
        }
        uVar2 = (*(code *)param_1)(param_2,param_3,L"DSAPRIVATEBLOB",lVar3,
                                   CONCAT44(uVar7,local_28[0]),local_28,0);
        uVar4 = (ulonglong)uVar2;
        if (uVar2 == 0) {
          uVar4 = ConvertDsaPrivateBlobToLegacy(lVar3,param_3,param_5,(ulonglong)param_6,param_7);
          uVar2 = (uint)uVar4;
          uVar4 = uVar4 & 0xffffffff;
          if (uVar2 == 0) {
LAB_18000c6cb:
            uVar4 = 0;
            if (lVar3 == 0) {
              return 0;
            }
            goto LAB_18000c6d3;
          }
          uVar5 = 0x7f;
        }
        else {
          uVar5 = 0x6d;
        }
      }
      else {
        iVar1 = wcscmp(param_4,L"V2CAPIDSAPRIVATEBLOB");
        if (iVar1 != 0) {
          uVar4 = 0xc00000e5;
          uVar6 = 0xc1;
          uVar5 = 0xe5;
          goto LAB_18000c6ed;
        }
        in_stack_ffffffffffffffb8 = in_stack_ffffffffffffffb8 & 0xffffffff00000000;
        uVar2 = (*(code *)param_1)(param_2,param_3,L"DSAPRIVATEBLOB",0,in_stack_ffffffffffffffb8,
                                   local_28,0);
        uVar7 = (undefined4)(in_stack_ffffffffffffffb8 >> 0x20);
        uVar4 = (ulonglong)uVar2;
        if (uVar2 != 0) {
          uVar6 = 0x93;
          goto LAB_18000c398;
        }
        lVar3 = BCryptAlloc((ulonglong)local_28[0]);
        if (lVar3 == 0) {
          return 0xc0000017;
        }
        uVar2 = (*(code *)param_1)(param_2,param_3,L"DSAPRIVATEBLOB",lVar3,
                                   CONCAT44(uVar7,local_28[0]),local_28,0);
        uVar4 = (ulonglong)uVar2;
        if (uVar2 == 0) {
          uVar4 = ConvertDsaPrivateBlobToLegacyV2(lVar3,param_3,param_5,param_6,param_7);
          uVar2 = (uint)uVar4;
          uVar4 = uVar4 & 0xffffffff;
          if (uVar2 == 0) goto LAB_18000c6cb;
          uVar5 = 0xba;
        }
        else {
          uVar5 = 0xa8;
        }
      }
    }
  }
  DebugTraceError((char)uVar2,"Status",
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\translate\\bcrypttranslate.c",uVar5);
LAB_18000c6d3:
  SafeAllocaFreeToHeap(lVar3);
  return uVar4;
}



===== ExportFullRsaKey @ 18000c728 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

int ExportFullRsaKey(undefined *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                    uint param_5,undefined8 param_6,int param_7)

{
  int iVar1;
  undefined1 (*pauVar2) [16];
  undefined1 uVar3;
  undefined1 uVar4;
  undefined8 in_stack_ffffffffffffffa8;
  ulonglong uVar5;
  undefined4 uVar6;
  uint local_38 [4];
  
  local_38[0] = 0;
  if (param_7 != 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff3;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return -0x3ffffff3;
    }
    WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,
                "onecore\\ds\\security\\cryptoapi\\ncrypt\\translate\\bcrypttranslate.c","Status",
                0xd,"onecore\\ds\\security\\cryptoapi\\ncrypt\\translate\\bcrypttranslate.c",0xcb);
    return -0x3ffffff3;
  }
  uVar5 = CONCAT44((int)((ulonglong)in_stack_ffffffffffffffa8 >> 0x20),param_5);
  iVar1 = (*(code *)param_1)(param_2,param_3,L"RSAFULLPRIVATEBLOB",param_4,uVar5,param_6,0);
  if (-1 < iVar1) {
    return iVar1;
  }
  uVar5 = uVar5 & 0xffffffff00000000;
  iVar1 = (*(code *)param_1)(param_2,param_3,L"RSAPRIVATEBLOB",0,uVar5,local_38,0);
  uVar6 = (undefined4)(uVar5 >> 0x20);
  if (iVar1 < 0) {
    uVar4 = 0xec;
    uVar3 = (undefined1)iVar1;
LAB_18000c82a:
    DebugTraceError(uVar3,"Status",
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\translate\\bcrypttranslate.c",uVar4);
    return iVar1;
  }
  pauVar2 = (undefined1 (*) [16])BCryptAlloc((ulonglong)local_38[0]);
  if (pauVar2 == (undefined1 (*) [16])0x0) {
    iVar1 = -0x3fffffe9;
    uVar4 = 0xf4;
    uVar3 = 0x17;
    goto LAB_18000c82a;
  }
  iVar1 = (*(code *)param_1)(param_2,param_3,L"RSAPRIVATEBLOB",pauVar2,CONCAT44(uVar6,local_38[0]),
                             local_38,0);
  if (iVar1 < 0) {
    uVar3 = 2;
  }
  else {
    iVar1 = ConvertRsaPrivateBlobToFullRsa
                      (pauVar2,(ulonglong)local_38[0],param_4,(ulonglong)param_5,param_6);
    if (-1 < iVar1) {
      iVar1 = 0;
      goto LAB_18000c8de;
    }
    uVar3 = 0x13;
  }
  DebugTraceError((char)iVar1,"Status",
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\translate\\bcrypttranslate.c",uVar3);
LAB_18000c8de:
  SafeAllocaFreeToHeap(pauVar2);
  return iVar1;
}



===== ExportLegacyDhKey @ 18000c910 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

ulonglong ExportLegacyDhKey(undefined *param_1,undefined8 param_2,undefined8 param_3,
                           wchar_t *param_4,undefined8 *param_5,uint param_6,uint *param_7,
                           int param_8)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  undefined1 uVar4;
  ulonglong uVar5;
  undefined1 uVar6;
  ulonglong in_stack_ffffffffffffffc8;
  undefined4 uVar7;
  uint local_18 [4];
  
  local_18[0] = 0;
  if (param_8 != 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc000000d;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return 0xc000000d;
    }
    WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,
                "onecore\\ds\\security\\cryptoapi\\ncrypt\\translate\\bcrypttranslate.c","Status",
                0xd,"onecore\\ds\\security\\cryptoapi\\ncrypt\\translate\\bcrypttranslate.c",0xda);
    return 0xc000000d;
  }
  iVar1 = wcscmp(param_4,L"CAPIDHPUBLICBLOB");
  if (iVar1 == 0) {
    in_stack_ffffffffffffffc8 = in_stack_ffffffffffffffc8 & 0xffffffff00000000;
    uVar2 = (*(code *)param_1)(param_2,param_3,L"DHPUBLICBLOB",0,in_stack_ffffffffffffffc8,local_18,
                               0);
    uVar7 = (undefined4)(in_stack_ffffffffffffffc8 >> 0x20);
    if (uVar2 == 0) {
      lVar3 = BCryptAlloc((ulonglong)local_18[0]);
      if (lVar3 == 0) {
        uVar6 = 0xf6;
LAB_18000ca06:
        uVar5 = 0xc0000017;
        uVar4 = 0x17;
        goto LAB_18000cba2;
      }
      uVar2 = (*(code *)param_1)(param_2,param_3,L"DHPUBLICBLOB",lVar3,CONCAT44(uVar7,local_18[0]),
                                 local_18,0);
      uVar5 = (ulonglong)uVar2;
      if (uVar2 == 0) {
        uVar5 = ConvertDhPublicBlobToLegacy(lVar3,param_3,param_5,param_6,param_7);
        uVar2 = (uint)uVar5;
        uVar5 = uVar5 & 0xffffffff;
        if (uVar2 == 0) {
LAB_18000cb86:
          uVar5 = 0;
          goto LAB_18000cb88;
        }
        uVar6 = 0x16;
      }
      else {
        uVar6 = 4;
      }
LAB_18000ca50:
      DebugTraceError((char)uVar2,"Status",
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\translate\\bcrypttranslate.c",uVar6
                     );
LAB_18000cb88:
      SafeAllocaFreeToHeap(lVar3);
      return uVar5;
    }
    uVar6 = 0xee;
  }
  else {
    iVar1 = wcscmp(param_4,L"CAPIDHPRIVATEBLOB");
    if (iVar1 != 0) {
      uVar5 = 0xc00000e5;
      uVar6 = 0x59;
      uVar4 = 0xe5;
      goto LAB_18000cba2;
    }
    in_stack_ffffffffffffffc8 = in_stack_ffffffffffffffc8 & 0xffffffff00000000;
    uVar2 = (*(code *)param_1)(param_2,param_3,L"DHPRIVATEBLOB",0,in_stack_ffffffffffffffc8,local_18
                               ,0);
    uVar7 = (undefined4)(in_stack_ffffffffffffffc8 >> 0x20);
    if (uVar2 == 0) {
      lVar3 = BCryptAlloc((ulonglong)local_18[0]);
      if (lVar3 == 0) {
        uVar6 = 0x32;
        goto LAB_18000ca06;
      }
      uVar2 = (*(code *)param_1)(param_2,param_3,L"DHPRIVATEBLOB",lVar3,CONCAT44(uVar7,local_18[0]),
                                 local_18,0);
      uVar5 = (ulonglong)uVar2;
      if (uVar2 == 0) {
        uVar5 = ConvertDhPrivateBlobToLegacy(lVar3,param_3,param_5,param_6,param_7);
        uVar2 = (uint)uVar5;
        uVar5 = uVar5 & 0xffffffff;
        if (uVar2 == 0) goto LAB_18000cb86;
        uVar6 = 0x52;
      }
      else {
        uVar6 = 0x40;
      }
      goto LAB_18000ca50;
    }
    uVar6 = 0x2a;
  }
  uVar5 = (ulonglong)uVar2;
  uVar4 = (undefined1)uVar2;
LAB_18000cba2:
  DebugTraceError(uVar4,"Status",
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\translate\\bcrypttranslate.c",uVar6);
  return uVar5;
}



===== WPP_SF_qqSqdqD @ 18000cbdc =====

void WPP_SF_qqSqdqD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                   undefined1 param_5,wchar_t *param_6,undefined1 param_7,undefined1 param_8,
                   undefined1 param_9,undefined1 param_10)

{
  longlong lVar1;
  wchar_t *pwVar2;
  undefined8 local_res20;
  
  if (param_6 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_6[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  pwVar2 = param_6;
  if (param_6 == (wchar_t *)0x0) {
    pwVar2 = L"NULL";
  }
  local_res20 = param_4;
  EtwTraceMessage(param_1,0x2b,&WPP_e4386b12b8143f81186affdeca2b77e8_Traceguids,0x19,&local_res20,8,
                  &param_5,8,pwVar2,lVar1,&param_7,8,&param_8,4,&param_9,8,&param_10,4,0);
  return;
}



===== ApplyPKCS1SigningFormat @ 18000cce0 =====

undefined8
ApplyPKCS1SigningFormat
          (void *param_1,uint param_2,void *param_3,uint param_4,undefined2 *param_5,uint param_6,
          int param_7)

{
  undefined1 uVar1;
  longlong lVar2;
  undefined8 uVar3;
  uint uVar4;
  undefined1 uVar5;
  ulonglong uVar6;
  uint uVar7;
  
  if (param_7 == 0) {
    uVar4 = param_4;
  }
  else {
    if (param_1 == (void *)0x0) {
      if (param_2 != 0) {
        return 0xc000000d;
      }
    }
    else if (param_2 != 0) {
      uVar4 = param_4 + 6 + param_2;
      goto LAB_18000cd38;
    }
    uVar4 = param_4 + 2;
  }
LAB_18000cd38:
  if (uVar4 < 0x81) {
    if (uVar4 + 0xb <= param_6) {
      uVar7 = param_6 - uVar4;
      *param_5 = 0x100;
      uVar6 = (ulonglong)(uVar7 - 3);
      *(undefined1 *)((ulonglong)(uVar7 - 1) + (longlong)param_5) = 0;
      memset(param_5 + 1,0xff,(ulonglong)(uVar7 - 3));
      if (param_7 == 0) {
        lVar2 = uVar6 + 3;
      }
      else {
        if ((param_1 == (void *)0x0) || (param_2 == 0)) {
          uVar4 = 1;
        }
        else {
          *(undefined1 *)((ulonglong)uVar7 + (longlong)param_5) = 0x30;
          *(char *)((ulonglong)(uVar7 + 1) + (longlong)param_5) = (char)uVar4 + -2;
          *(undefined1 *)((ulonglong)(uVar7 + 2) + (longlong)param_5) = 0x30;
          uVar4 = 5;
          *(char *)((ulonglong)(uVar7 + 3) + (longlong)param_5) = (char)param_2;
          memcpy((void *)((longlong)param_5 + uVar6 + 7),param_1,(ulonglong)param_2);
        }
        *(undefined1 *)((ulonglong)((uVar7 - 1) + uVar4 + param_2) + (longlong)param_5) = 4;
        *(char *)((ulonglong)(uVar7 + uVar4 + param_2) + (longlong)param_5) = (char)param_4;
        lVar2 = (ulonglong)param_2 + 4 + uVar4 + uVar6;
      }
      memcpy((void *)(lVar2 + (longlong)param_5),param_3,(ulonglong)param_4);
      return 0;
    }
    uVar3 = 0xc000000d;
    uVar5 = 0x69;
    uVar1 = 0xd;
  }
  else {
    uVar3 = 0xc00000e5;
    uVar5 = 0x5f;
    uVar1 = 0xe5;
  }
  DebugTraceError(uVar1,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\format.c",uVar5)
  ;
  return uVar3;
}



===== WPP_SF_qqSD @ 18000ce68 =====

void WPP_SF_qqSD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,wchar_t *param_6,undefined1 param_7)

{
  longlong lVar1;
  wchar_t *pwVar2;
  undefined8 local_res20;
  
  if (param_6 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_6[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  pwVar2 = param_6;
  if (param_6 == (wchar_t *)0x0) {
    pwVar2 = L"NULL";
  }
  local_res20 = param_4;
  EtwTraceMessage(param_1,0x2b,&WPP_321c0d2313123f81ee86e6c36df24469_Traceguids,param_2,&local_res20
                  ,8,&param_5,8,pwVar2,lVar1,&param_7,4,0);
  return;
}



===== BCryptDecrypt @ 18000cf30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

NTSTATUS __stdcall
BCryptDecrypt(BCRYPT_KEY_HANDLE hKey,PUCHAR pbInput,ULONG cbInput,void *pPaddingInfo,PUCHAR pbIV,
             ULONG cbIV,PUCHAR pbOutput,ULONG cbOutput,ULONG *pcbResult,ULONG dwFlags)

{
  byte bVar1;
  uint uVar2;
  longlong lVar3;
  bool bVar4;
  longlong *plVar5;
  PUCHAR pUVar6;
  uint *puVar7;
  uint uVar8;
  ULONG UVar9;
  int iVar10;
  ulonglong uVar11;
  undefined8 uVar12;
  ulonglong *puVar13;
  longlong lVar14;
  undefined *puVar15;
  PUCHAR pUVar16;
  PUCHAR pUVar17;
  int iVar18;
  ulonglong uVar19;
  undefined1 *puVar20;
  undefined1 *puVar21;
  undefined1 *puVar22;
  undefined **ppuVar23;
  code *pcVar24;
  undefined1 auStackY_148 [32];
  uint local_e8;
  ULONG local_e4;
  ulonglong local_e0;
  longlong *local_d8;
  PUCHAR local_d0;
  PUCHAR local_c8;
  uint *local_c0;
  code *local_b8;
  PUCHAR local_b0;
  ULONG *local_a8;
  undefined8 local_a0;
  undefined *local_98;
  uint local_90;
  undefined4 local_8c;
  undefined *local_88;
  undefined4 local_80;
  undefined4 local_7c;
  longlong **local_78;
  undefined8 local_70;
  wchar_t *local_68;
  int local_60;
  undefined4 local_5c;
  ulonglong local_58;
  
                    /* 0xcf30  10  BCryptDecrypt */
  local_58 = __security_cookie ^ (ulonglong)&local_e8;
  local_d8 = pPaddingInfo;
  local_b0 = pbInput;
  local_c0 = hKey;
  uVar19 = (ulonglong)cbInput;
  puVar13 = (ulonglong *)0x0;
  local_c8 = pbIV;
  uVar8 = 0;
  local_d0 = pbOutput;
  local_e0._0_4_ = 0;
  local_e4 = cbInput;
  local_a8 = pcbResult;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_qqqdqdqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x18,WPP_GLOBAL_Control,hKey,
                    (char)pPaddingInfo,(char)pbInput,(char)cbInput,(char)pbOutput,(char)cbOutput,
                    (char)pcbResult,(char)dwFlags);
  }
  puVar20 = auStackY_148;
  pUVar17 = local_c8;
  ppuVar23 = (undefined **)WPP_GLOBAL_Control;
  if (pcbResult == (ULONG *)0x0) {
    iVar18 = -0x3ffffff3;
    iVar10 = -0x3ffffff3;
    puVar20 = auStackY_148;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_18000d58a;
    bVar1 = WPP_GLOBAL_Control[0x1c];
joined_r0x00018000d55c:
    puVar21 = auStackY_148;
    puVar20 = puVar21;
    if ((bVar1 & 1) == 0) goto LAB_18000d58a;
LAB_18000d57a:
    iVar10 = iVar18;
    puVar15 = ppuVar23[2];
    puVar22 = puVar21;
  }
  else {
    if (((local_c0 == (uint *)0x0) || (*local_c0 < 0x20)) || (local_c0[1] != 0x55555552)) {
      iVar18 = -0x3ffffff8;
      iVar10 = -0x3ffffff8;
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_18000d58a;
      bVar1 = WPP_GLOBAL_Control[0x1c];
      goto joined_r0x00018000d55c;
    }
    lVar14 = *(longlong *)(local_c0 + 2);
    if (*(int *)(lVar14 + 0x24) != 1) {
      if (*(int *)(lVar14 + 0x24) != 3) {
        iVar18 = -0x3fffff45;
        iVar10 = -0x3fffff45;
        puVar20 = auStackY_148;
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_18000d58a;
        bVar1 = WPP_GLOBAL_Control[0x1c];
        goto joined_r0x00018000d55c;
      }
      pcVar24 = *(code **)(lVar14 + 0x70);
      bVar4 = false;
      uVar2 = *(uint *)(lVar14 + 0x1b8);
      local_b8 = pcVar24;
      if ((uVar2 & 1) != 0) {
        if (((dwFlags == 0) || ((dwFlags & 1) != 0)) ||
           (((uVar2 & dwFlags & 2) != 0 || (((dwFlags & 4) != 0 && ((uVar2 & 8) != 0)))))) {
          bVar4 = false;
        }
        else {
          bVar4 = true;
        }
      }
      if (!bVar4) goto LAB_18000d4c5;
      if (cbInput * 2 < cbInput) {
        iVar18 = -0x3fffff6b;
        iVar10 = -0x3fffff6b;
        puVar20 = auStackY_148;
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_18000d58a;
        bVar1 = WPP_GLOBAL_Control[0x1c];
        goto joined_r0x00018000d55c;
      }
      uVar11 = 1;
      if (1 < uVar19) {
        do {
          uVar11 = uVar11 * 2;
          if (uVar11 == 0) break;
        } while (uVar11 < uVar19);
      }
      pUVar16 = local_d0;
      if ((uint)uVar11 < 0x20) {
        uVar8 = 0x20;
      }
      else {
        uVar8 = SymCryptRoundUpPow2Sizet(uVar19);
      }
      UVar9 = cbInput;
      if (pUVar16 != (PUCHAR)0x0) {
        UVar9 = 0;
      }
      local_e8 = UVar9 + uVar8;
      uVar19 = (ulonglong)local_e8;
      puVar21 = auStackY_148;
      if (((local_e8 == 0) || (puVar21 = auStackY_148, g_ulMaxStackAllocSize < uVar19)) ||
         (uVar11 = g_ulAdditionalProbeSize + 8 + uVar19, puVar21 = auStackY_148, uVar11 < uVar19)) {
LAB_18000d200:
        if (uVar19 <= uVar19 + 8) {
          *(undefined8 *)(puVar21 + -8) = 0x18000d215;
          puVar13 = (ulonglong *)(*g_pfnAllocate)();
          if (puVar13 != (ulonglong *)0x0) {
            *(undefined4 *)puVar13 = 0x70616548;
            puVar13 = puVar13 + 1;
          }
          goto LAB_18000d227;
        }
      }
      else {
        uVar12 = VerifyStackAvailable(uVar11);
        puVar20 = auStackY_148;
        if ((int)uVar12 == 0) {
LAB_18000d1f9:
          puVar21 = puVar20;
          ppuVar23 = (undefined **)WPP_GLOBAL_Control;
          goto LAB_18000d200;
        }
        uVar11 = uVar19 + 0x17;
        if (uVar11 <= uVar19 + 8) {
          uVar11 = 0xffffffffffffff0;
        }
        lVar3 = -(uVar11 & 0xfffffffffffffff0);
        puVar21 = auStackY_148 + lVar3;
        puVar13 = (ulonglong *)0x0;
        puVar20 = auStackY_148 + lVar3;
        if ((undefined4 *)((longlong)&local_e8 + lVar3) == (undefined4 *)0x0) goto LAB_18000d1f9;
        *(undefined4 *)((longlong)&local_e8 + lVar3) = 0x6b637453;
        puVar13 = (ulonglong *)((longlong)&local_e0 + lVar3);
        puVar20 = auStackY_148 + lVar3;
        if (puVar13 == (ulonglong *)0x0) goto LAB_18000d1f9;
LAB_18000d227:
        ppuVar23 = (undefined **)WPP_GLOBAL_Control;
      }
      pUVar16 = local_b0;
      puVar7 = local_c0;
      UVar9 = local_e4;
      if (puVar13 != (ulonglong *)0x0) {
        if (local_d0 == (PUCHAR)0x0) {
          pUVar17 = (PUCHAR)((ulonglong)uVar8 + (longlong)puVar13);
        }
        else {
          pUVar17 = local_d0;
        }
        uVar19 = (ulonglong)local_e4;
        if (local_d0 != (PUCHAR)0x0) {
          cbInput = cbOutput;
        }
        *(ULONG *)(puVar21 + 0x48) = dwFlags;
        *(ulonglong **)(puVar21 + 0x40) = &local_e0;
        pUVar6 = local_c8;
        uVar12 = *(undefined8 *)(puVar7 + 4);
        *(ULONG *)(puVar21 + 0x38) = UVar9;
        *(ulonglong **)(puVar21 + 0x30) = puVar13;
        *(ULONG *)(puVar21 + 0x28) = cbIV;
        *(PUCHAR *)(puVar21 + 0x20) = pUVar6;
        pcVar24 = local_b8;
        *(undefined8 *)(puVar21 + -8) = 0x18000d2dc;
        iVar10 = (*pcVar24)(uVar12,pUVar16,uVar19,0);
        plVar5 = local_d8;
        uVar2 = (uint)local_e0;
        if (-1 < iVar10) {
          *(ULONG **)(puVar21 + 0x38) = local_a8;
          *(ULONG *)(puVar21 + 0x30) = cbInput;
          *(PUCHAR *)(puVar21 + 0x28) = pUVar17;
          *(uint *)(puVar21 + 0x20) = uVar8;
          *(undefined8 *)(puVar21 + -8) = 0x18000d37d;
          CheckEncryptionPadding
                    ((ulonglong)dwFlags,plVar5,puVar13,uVar2,*(uint *)(puVar21 + 0x20),
                     *(void **)(puVar21 + 0x28),*(uint *)(puVar21 + 0x30),*(uint **)(puVar21 + 0x38)
                    );
          if (5 < DAT_180025058) {
            if (((_DAT_180025068 & 0x200000000000) == 0) ||
               ((DAT_180025070 & 0x200000000000) != DAT_180025070)) {
              bVar4 = false;
            }
            else {
              bVar4 = true;
            }
            if (bVar4) {
              local_78 = &local_d8;
              local_d8 = (longlong *)0x1000000;
              local_70 = 8;
              local_68 = (wchar_t *)**(longlong **)(lVar14 + 0x28);
              if (local_68 == (wchar_t *)0x0) {
                local_68 = L"";
                local_60 = 2;
              }
              else {
                lVar14 = -1;
                do {
                  lVar3 = lVar14 + 1;
                  lVar14 = lVar14 + 1;
                } while (local_68[lVar3] != L'\0');
                local_60 = (int)lVar14 * 2 + 2;
              }
              local_98 = PTR_DAT_180025060;
              local_a0 = 0x200000000000;
              local_5c = 0;
              local_a8 = (ULONG *)0x50b000000;
              local_90 = (uint)*(ushort *)PTR_DAT_180025060;
              local_88 = &DAT_180020734;
              local_8c = 2;
              local_80 = 0x35;
              local_7c = 1;
              local_e4 = 0x463;
              *(undefined ***)(puVar21 + 0x28) = &local_98;
              *(undefined4 *)(puVar21 + 0x20) = 4;
              *(undefined8 *)(puVar21 + -8) = 0x18000d4a7;
              EtwEventWriteTransfer(DAT_180025078,&local_a8,0,0);
            }
          }
          uVar8 = local_e8;
          goto LAB_18000d4af;
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
          uVar12 = *(undefined8 *)(WPP_GLOBAL_Control + 0x10);
          *(undefined4 *)(puVar21 + 0x30) = 0x1089;
          *(char **)(puVar21 + 0x28) = "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c";
          *(int *)(puVar21 + 0x20) = iVar10;
          *(undefined8 *)(puVar21 + -8) = 0x18000d323;
          WPP_SF_sDsd(uVar12,pUVar16,uVar19,"Status",puVar21[0x20],*(char **)(puVar21 + 0x28),
                      puVar21[0x30]);
        }
        uVar8 = local_e8;
LAB_18000d326:
        *(undefined8 *)(puVar21 + -8) = 0x18000d330;
        SymCryptWipeAsm(puVar13,(ulonglong)uVar8);
        puVar20 = puVar21;
        if ((int)puVar13[-1] == 0x70616548) {
          *(undefined8 *)(puVar21 + -8) = 0x18000d34d;
          (*g_pfnFree)(puVar13 + -1);
        }
        goto LAB_18000d58a;
      }
      iVar10 = -0x3fffffe9;
      puVar20 = puVar21;
      if ((ppuVar23 == &WPP_GLOBAL_Control) || ((*(byte *)((longlong)ppuVar23 + 0x1c) & 1) == 0))
      goto LAB_18000d58a;
      *(undefined4 *)(puVar21 + 0x30) = 0x106a;
      *(char **)(puVar21 + 0x28) = "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c";
      *(undefined4 *)(puVar21 + 0x20) = 0xc0000017;
      iVar18 = -0x3fffffe9;
      goto LAB_18000d57a;
    }
    pcVar24 = *(code **)(lVar14 + 0x68);
LAB_18000d4c5:
    ppuVar23 = (undefined **)(ulonglong)cbInput;
    pUVar17 = local_b0;
    iVar10 = (*pcVar24)(*(undefined8 *)(local_c0 + 4),local_b0,ppuVar23,pPaddingInfo);
    puVar21 = auStackY_148;
    puVar22 = auStackY_148;
    if ((*(int *)(lVar14 + 0x24) == 3) && (puVar20 = auStackY_148, (dwFlags & 2) != 0))
    goto LAB_18000d58a;
    if (-1 < iVar10) {
LAB_18000d4af:
      iVar10 = 0;
      puVar20 = puVar21;
      if (puVar13 == (ulonglong *)0x0) goto LAB_18000d58a;
      goto LAB_18000d326;
    }
    puVar20 = auStackY_148;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       (puVar20 = auStackY_148, (WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000d58a;
    puVar15 = *(undefined **)(WPP_GLOBAL_Control + 0x10);
  }
  *(undefined8 *)(puVar22 + -8) = 0x18000d58a;
  WPP_SF_sDsd(puVar15,pUVar17,ppuVar23,"Status",puVar22[0x20],*(char **)(puVar22 + 0x28),
              puVar22[0x30]);
  puVar20 = puVar22;
LAB_18000d58a:
  *(undefined8 *)(puVar20 + -8) = 0x18000d59b;
  return iVar10;
}



===== BCryptDestroyKey @ 18000d5c0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

NTSTATUS __stdcall BCryptDestroyKey(BCRYPT_KEY_HANDLE hKey)

{
  uint *puVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  code *pcVar5;
  ulonglong uVar6;
  ulonglong in_RDX;
  undefined1 *puVar7;
  uint *puVar8;
  BCRYPT_KEY_HANDLE in_R8;
  BCRYPT_KEY_HANDLE pvVar9;
  undefined1 uVar10;
  
                    /* 0xd5c0  16  BCryptDestroyKey */
  bVar2 = false;
  pvVar9 = (BCRYPT_KEY_HANDLE)0x0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    in_RDX = 0x1f;
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x1f,in_R8,hKey);
  }
  if (((hKey == (BCRYPT_KEY_HANDLE)0x0) || (*(uint *)hKey < 0x20)) ||
     (*(int *)((longlong)hKey + 4) != 0x55555552)) {
    uVar3 = 0xc0000008;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff8;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return -0x3ffffff8;
    }
    uVar10 = 0xce;
    goto LAB_18000d823;
  }
  puVar1 = *(uint **)((longlong)hKey + 8);
  switch(puVar1[9]) {
  case 1:
    pvVar9 = *(BCRYPT_KEY_HANDLE *)((longlong)hKey + 0x18);
    bVar2 = false;
    goto LAB_18000d689;
  default:
    uVar3 = 0xc0000008;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff8;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return -0x3ffffff8;
    }
    uVar10 = 0xff;
    goto LAB_18000d823;
  case 3:
  case 5:
  case 8:
    bVar2 = true;
LAB_18000d689:
    pcVar5 = *(code **)(puVar1 + 0x22);
    break;
  case 4:
    pcVar5 = *(code **)(puVar1 + 0x24);
    bVar2 = true;
    break;
  case 7:
    pcVar5 = *(code **)(puVar1 + 0x18);
    pvVar9 = *(BCRYPT_KEY_HANDLE *)((longlong)hKey + 0x18);
  }
  uVar3 = (*pcVar5)(*(undefined8 *)((longlong)hKey + 0x10));
  if ((int)uVar3 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return uVar3;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return uVar3;
    }
    uVar10 = 8;
    uVar4 = uVar3;
  }
  else {
    puVar7 = hKey;
    for (uVar6 = (ulonglong)*(uint *)hKey; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
    if (bVar2) {
      in_RDX = 0;
      RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30));
      in_R8 = hKey;
    }
    if (pvVar9 != (BCRYPT_KEY_HANDLE)0x0) {
      in_RDX = 0;
      RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30));
      in_R8 = pvVar9;
    }
    LOCK();
    puVar8 = puVar1 + 4;
    uVar4 = *puVar8;
    *puVar8 = *puVar8 - 1;
    UNLOCK();
    if (uVar4 != 1) {
      return uVar3;
    }
    switch(puVar1[9]) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
      uVar4 = (**(code **)(puVar1 + 0x14))(*(undefined8 *)(puVar1 + 6),0);
      in_RDX = (ulonglong)uVar4;
      if (-1 < (int)uVar4) {
        UnloadProvider(*(undefined8 **)(puVar1 + 10),in_RDX,in_R8);
        puVar8 = puVar1;
        for (uVar6 = (ulonglong)*puVar1; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined1 *)puVar8 = 0;
          puVar8 = (uint *)((longlong)puVar8 + 1);
        }
        RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,puVar1);
        return uVar3;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return uVar3;
      }
      if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
        return uVar3;
      }
      uVar10 = 0xbf;
      break;
    default:
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return uVar3;
      }
      if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
        return uVar3;
      }
      uVar10 = 0xb6;
LAB_18000d823:
      uVar4 = 0xc0000008;
    }
  }
  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),in_RDX,in_R8,"Status",(char)uVar4,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar10);
  return uVar3;
}



===== BCryptExportKey @ 18000d8c0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

NTSTATUS __stdcall
BCryptExportKey(BCRYPT_KEY_HANDLE hKey,BCRYPT_KEY_HANDLE hExportKey,LPCWSTR pszBlobType,
               PUCHAR pbOutput,ULONG cbOutput,ULONG *pcbResult,ULONG dwFlags)

{
  undefined4 uVar1;
  bool bVar2;
  int iVar3;
  ulonglong uVar4;
  IMAGE_DOS_HEADER *pIVar5;
  IMAGE_DOS_HEADER *pIVar6;
  undefined *puVar7;
  wchar_t *pwVar8;
  longlong lVar9;
  longlong lVar10;
  IMAGE_DOS_HEADER *pIVar11;
  undefined **ppuVar12;
  code *pcVar13;
  IMAGE_DOS_HEADER *local_res20;
  undefined1 uVar14;
  undefined1 uVar15;
  
                    /* 0xd8c0  28  BCryptExportKey */
  lVar10 = 0;
  local_res20 = (IMAGE_DOS_HEADER *)0x0;
  pIVar5 = (IMAGE_DOS_HEADER *)0x0;
  bVar2 = false;
  pwVar8 = hExportKey;
  pIVar11 = (IMAGE_DOS_HEADER *)pszBlobType;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_qqSqdqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),hExportKey,pszBlobType,hKey,
                   (char)hExportKey,pszBlobType,(char)pbOutput,(char)cbOutput,(char)pcbResult,
                   (char)dwFlags);
  }
  ppuVar12 = (undefined **)WPP_GLOBAL_Control;
  if ((pcbResult == (ULONG *)0x0) || (pszBlobType == (LPCWSTR)0x0)) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff3;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return -0x3ffffff3;
    }
    uVar15 = 0xfc;
LAB_18000e013:
    iVar3 = -0x3ffffff3;
    uVar14 = 0xd;
  }
  else if (((hKey == (BCRYPT_KEY_HANDLE)0x0) || (*(uint *)hKey < 0x20)) ||
          (*(int *)((longlong)hKey + 4) != 0x55555552)) {
    iVar3 = -0x3ffffff8;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff8;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return -0x3ffffff8;
    }
    uVar15 = 5;
    uVar14 = 8;
  }
  else {
    pwVar8 = *(wchar_t **)((longlong)hKey + 8);
    uVar1._0_2_ = ((IMAGE_DOS_HEADER *)pwVar8)->e_oemid;
    uVar1._2_2_ = ((IMAGE_DOS_HEADER *)pwVar8)->e_oeminfo;
    pIVar11 = &IMAGE_DOS_HEADER_180000000;
    switch(uVar1) {
    case 1:
      pcVar13 = *(code **)(((IMAGE_DOS_HEADER *)pwVar8)->e_program + 0x38);
      break;
    default:
      iVar3 = -0x3fffff45;
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3fffff45;
      }
      if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
        return -0x3fffff45;
      }
      uVar15 = 0x29;
      uVar14 = 0xbb;
      goto LAB_18000e027;
    case 3:
    case 5:
    case 8:
      pcVar13 = *(code **)((longlong)pwVar8 + 0x80);
      break;
    case 4:
      pcVar13 = *(code **)&((IMAGE_DOS_HEADER *)((longlong)pwVar8 + 0x80))->e_cparhdr;
      break;
    case 7:
      pcVar13 = *(code **)(((IMAGE_DOS_HEADER *)pwVar8)->e_program + 0x30);
    }
    pIVar11 = (IMAGE_DOS_HEADER *)0xffffffffffffffff;
    if (hExportKey == (BCRYPT_KEY_HANDLE)0x0) {
LAB_18000daf7:
      pIVar6 = pIVar11;
      do {
        if (pszBlobType[(longlong)(pIVar6->e_magic + 1)] !=
            L"CAPIPUBLICBLOB"[(longlong)(pIVar6->e_magic + 1)]) break;
        pIVar6 = (IMAGE_DOS_HEADER *)&pIVar6->e_cblp;
        if (pIVar6 == (IMAGE_DOS_HEADER *)0xf) goto LAB_18000db58;
      } while (pszBlobType[(longlong)pIVar6] == L"CAPIPUBLICBLOB"[(longlong)pIVar6]);
      lVar9 = 0;
      do {
        if ((pszBlobType[lVar9] != L"CAPIPRIVATEBLOB"[lVar9]) ||
           (pszBlobType[lVar9 + 1] != L"CAPIPRIVATEBLOB"[lVar9 + 1])) {
          pIVar6 = pIVar11;
          goto LAB_18000dbe0;
        }
        lVar9 = lVar9 + 2;
      } while (lVar9 != 0x10);
LAB_18000db58:
      local_res20 = *(IMAGE_DOS_HEADER **)((longlong)hKey + 0x10);
      uVar4 = ExportLegacyRsaKey(pcVar13,local_res20,pIVar5,pszBlobType,(undefined8 *)pbOutput,
                                 cbOutput,pcbResult,dwFlags);
      iVar3 = (int)uVar4;
      if (-1 < iVar3) {
        return iVar3;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar3;
      }
      if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
        return iVar3;
      }
      puVar7 = *(undefined **)(WPP_GLOBAL_Control + 0x10);
      uVar15 = 0x71;
      uVar14 = (undefined1)uVar4;
      goto LAB_18000e02b;
    }
    local_res20 = (IMAGE_DOS_HEADER *)ValidateBaseKeyHandle(hExportKey);
    if (local_res20 == (IMAGE_DOS_HEADER *)0x0) {
      iVar3 = -0x3ffffff8;
      if (ppuVar12 == &WPP_GLOBAL_Control) {
        return -0x3ffffff8;
      }
      if ((*(byte *)((longlong)ppuVar12 + 0x1c) & 1) == 0) {
        return -0x3ffffff8;
      }
      uVar15 = 0x35;
      uVar14 = 8;
    }
    else {
      if (*(int *)(*(longlong *)&local_res20->e_cparhdr + 0x24) == 1) {
        bVar2 = false;
        if (*(longlong *)(*(longlong *)&local_res20->e_cparhdr + 0x28) !=
            *(longlong *)((IMAGE_DOS_HEADER *)pwVar8)->e_res2_10_) {
          pwVar8 = L"Rfc3565KeyWrapBlob";
          pIVar5 = pIVar11;
          do {
            if (pszBlobType[(longlong)(pIVar5->e_magic + 1)] !=
                L"Rfc3565KeyWrapBlob"[(longlong)(pIVar5->e_magic + 1)]) break;
            pIVar5 = (IMAGE_DOS_HEADER *)&pIVar5->e_cblp;
            if (pIVar5 == (IMAGE_DOS_HEADER *)0x13) {
              bVar2 = true;
              goto LAB_18000daf3;
            }
          } while (pszBlobType[(longlong)pIVar5] == L"Rfc3565KeyWrapBlob"[(longlong)pIVar5]);
          if (ppuVar12 == &WPP_GLOBAL_Control) {
            return -0x3ffffff3;
          }
          if ((*(byte *)((longlong)ppuVar12 + 0x1c) & 1) == 0) {
            return -0x3ffffff3;
          }
          uVar15 = 0x4f;
          goto LAB_18000e013;
        }
LAB_18000daf3:
        pIVar5 = *(IMAGE_DOS_HEADER **)&local_res20->e_sp;
        goto LAB_18000daf7;
      }
      iVar3 = -0x3ffffff8;
      if (ppuVar12 == &WPP_GLOBAL_Control) {
        return -0x3ffffff8;
      }
      if ((*(byte *)((longlong)ppuVar12 + 0x1c) & 1) == 0) {
        return -0x3ffffff8;
      }
      uVar15 = 0x3e;
      uVar14 = 8;
    }
  }
LAB_18000e027:
  puVar7 = ppuVar12[2];
  local_res20 = (IMAGE_DOS_HEADER *)pwVar8;
  pIVar5 = pIVar11;
  goto LAB_18000e02b;
  while( true ) {
    pIVar6 = (IMAGE_DOS_HEADER *)&pIVar6->e_cblp;
    if (pIVar6 == (IMAGE_DOS_HEADER *)0x13) {
      local_res20 = *(IMAGE_DOS_HEADER **)((longlong)hKey + 0x10);
      iVar3 = ExportFullRsaKey(pcVar13,local_res20,pIVar5,pbOutput,cbOutput,pcbResult,dwFlags);
      if (-1 < iVar3) {
        return iVar3;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar3;
      }
      if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
        return iVar3;
      }
      puVar7 = *(undefined **)(WPP_GLOBAL_Control + 0x10);
      uVar15 = 0x85;
      uVar14 = (undefined1)iVar3;
      goto LAB_18000e02b;
    }
    if (pszBlobType[(longlong)pIVar6] != L"RSAFULLPRIVATEBLOB"[(longlong)pIVar6]) break;
LAB_18000dbe0:
    if (pszBlobType[(longlong)(pIVar6->e_magic + 1)] !=
        L"RSAFULLPRIVATEBLOB"[(longlong)(pIVar6->e_magic + 1)]) break;
  }
  lVar9 = 0;
  do {
    if ((pszBlobType[lVar9] != L"CAPIDSAPUBLICBLOB"[lVar9]) ||
       (pszBlobType[lVar9 + 1] != L"CAPIDSAPUBLICBLOB"[lVar9 + 1])) {
      pIVar6 = pIVar11;
      goto LAB_18000dd40;
    }
    lVar9 = lVar9 + 2;
  } while (lVar9 != 0x12);
  goto LAB_18000dc38;
  while( true ) {
    pIVar6 = (IMAGE_DOS_HEADER *)&pIVar6->e_cblp;
    if (pIVar6 == (IMAGE_DOS_HEADER *)0x15) goto LAB_18000dc38;
    if (pszBlobType[(longlong)pIVar6] != L"V2CAPIDSAPRIVATEBLOB"[(longlong)pIVar6]) break;
LAB_18000dda0:
    if (pszBlobType[(longlong)(pIVar6->e_magic + 1)] !=
        L"V2CAPIDSAPRIVATEBLOB"[(longlong)(pIVar6->e_magic + 1)]) break;
  }
  do {
    if (pszBlobType[(longlong)(pIVar11->e_magic + 1)] !=
        L"CAPIDHPUBLICBLOB"[(longlong)(pIVar11->e_magic + 1)]) break;
    pIVar11 = (IMAGE_DOS_HEADER *)&pIVar11->e_cblp;
    if (pIVar11 == (IMAGE_DOS_HEADER *)0x11) goto LAB_18000de28;
  } while (pszBlobType[(longlong)pIVar11] == L"CAPIDHPUBLICBLOB"[(longlong)pIVar11]);
  do {
    if ((pszBlobType[lVar10] != L"CAPIDHPRIVATEBLOB"[lVar10]) ||
       (pszBlobType[lVar10 + 1] != L"CAPIDHPRIVATEBLOB"[lVar10 + 1])) {
      if (bVar2) {
        iVar3 = RouterAesKeyWrap((longlong)hKey,(longlong)local_res20,pbOutput,cbOutput,pcbResult);
        if (-1 < iVar3) {
          return iVar3;
        }
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return iVar3;
        }
        if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
          return iVar3;
        }
        puVar7 = *(undefined **)(WPP_GLOBAL_Control + 0x10);
        uVar15 = 0xd1;
        uVar14 = (undefined1)iVar3;
        pIVar5 = (IMAGE_DOS_HEADER *)pbOutput;
      }
      else {
        iVar3 = (*pcVar13)(*(undefined8 *)((longlong)hKey + 0x10),pIVar5,pszBlobType,pbOutput,
                           cbOutput,pcbResult,dwFlags);
        if (-1 < iVar3) {
          return iVar3;
        }
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return iVar3;
        }
        if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
          return iVar3;
        }
        puVar7 = *(undefined **)(WPP_GLOBAL_Control + 0x10);
        uVar15 = 0xe0;
        uVar14 = (undefined1)iVar3;
        local_res20 = pIVar5;
        pIVar5 = (IMAGE_DOS_HEADER *)pszBlobType;
      }
      goto LAB_18000e02b;
    }
    lVar10 = lVar10 + 2;
  } while (lVar10 != 0x12);
LAB_18000de28:
  local_res20 = *(IMAGE_DOS_HEADER **)((longlong)hKey + 0x10);
  uVar4 = ExportLegacyDhKey(pcVar13,local_res20,pIVar5,pszBlobType,(undefined8 *)pbOutput,cbOutput,
                            pcbResult,dwFlags);
  iVar3 = (int)uVar4;
  if (-1 < iVar3) {
    return iVar3;
  }
  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
    return iVar3;
  }
  if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
    return iVar3;
  }
  puVar7 = *(undefined **)(WPP_GLOBAL_Control + 0x10);
  uVar15 = 0xc3;
  uVar14 = (undefined1)uVar4;
  goto LAB_18000e02b;
  while( true ) {
    pIVar6 = (IMAGE_DOS_HEADER *)&pIVar6->e_cblp;
    if (pIVar6 == (IMAGE_DOS_HEADER *)0x13) goto LAB_18000dc38;
    if (pszBlobType[(longlong)pIVar6] != L"CAPIDSAPRIVATEBLOB"[(longlong)pIVar6]) break;
LAB_18000dd40:
    if (pszBlobType[(longlong)(pIVar6->e_magic + 1)] !=
        L"CAPIDSAPRIVATEBLOB"[(longlong)(pIVar6->e_magic + 1)]) break;
  }
  lVar9 = 0;
  do {
    if ((pszBlobType[lVar9] != L"V2CAPIDSAPUBLICBLOB"[lVar9]) ||
       (pszBlobType[lVar9 + 1] != L"V2CAPIDSAPUBLICBLOB"[lVar9 + 1])) {
      pIVar6 = pIVar11;
      goto LAB_18000dda0;
    }
    lVar9 = lVar9 + 2;
  } while (lVar9 != 0x14);
LAB_18000dc38:
  local_res20 = *(IMAGE_DOS_HEADER **)((longlong)hKey + 0x10);
  uVar4 = ExportLegacyDsaKey(pcVar13,local_res20,pIVar5,pszBlobType,(undefined8 *)pbOutput,cbOutput,
                             pcbResult,dwFlags);
  iVar3 = (int)uVar4;
  if (-1 < iVar3) {
    return iVar3;
  }
  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
    return iVar3;
  }
  if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
    return iVar3;
  }
  puVar7 = *(undefined **)(WPP_GLOBAL_Control + 0x10);
  uVar15 = 0xa4;
  uVar14 = (undefined1)uVar4;
LAB_18000e02b:
  WPP_SF_sDsd(puVar7,local_res20,pIVar5,"Status",uVar14,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar15);
  return iVar3;
}



===== BCryptFinalizeKeyPair @ 18000e080 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

NTSTATUS __stdcall BCryptFinalizeKeyPair(BCRYPT_KEY_HANDLE hKey,ULONG dwFlags)

{
  longlong lVar1;
  int iVar2;
  uint *puVar3;
  code *pcVar4;
  undefined1 uVar5;
  undefined8 in_R8;
  undefined1 uVar6;
  
                    /* 0xe080  29  BCryptFinalizeKeyPair */
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x16,in_R8,hKey,(char)dwFlags);
  }
  puVar3 = ValidateBaseKeyHandle(hKey);
  if (puVar3 == (uint *)0x0) {
    iVar2 = -0x3ffffff8;
    uVar6 = 0xf2;
    uVar5 = 8;
    goto LAB_18000e0dd;
  }
  lVar1 = *(longlong *)(puVar3 + 2);
  iVar2 = *(int *)(lVar1 + 0x24);
  if (iVar2 == 3) {
LAB_18000e125:
    pcVar4 = *(code **)(lVar1 + 0x60);
  }
  else {
    if (iVar2 != 4) {
      if ((iVar2 != 5) && (iVar2 != 8)) {
        iVar2 = -0x3fffff45;
        uVar6 = 0xe;
        uVar5 = 0xbb;
        goto LAB_18000e0dd;
      }
      goto LAB_18000e125;
    }
    pcVar4 = *(code **)(lVar1 + 0x78);
  }
  iVar2 = (*pcVar4)(*(undefined8 *)(puVar3 + 4),dwFlags);
  if (-1 < iVar2) {
    return 0;
  }
  uVar6 = 0x16;
  uVar5 = (undefined1)iVar2;
LAB_18000e0dd:
  DebugTraceError(uVar5,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar6);
  return iVar2;
}



===== BCryptGenerateKeyPair @ 18000e160 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

NTSTATUS __stdcall
BCryptGenerateKeyPair
          (BCRYPT_ALG_HANDLE hAlgorithm,BCRYPT_KEY_HANDLE *phKey,ULONG dwLength,ULONG dwFlags)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  undefined4 *puVar4;
  code *pcVar5;
  BCRYPT_KEY_HANDLE *ppvVar6;
  undefined4 *puVar7;
  NTSTATUS NVar8;
  undefined4 in_register_00000084;
  undefined8 uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  undefined1 uVar12;
  undefined1 uVar13;
  
                    /* 0xe160  33  BCryptGenerateKeyPair */
  uVar9 = CONCAT44(in_register_00000084,dwLength);
  uVar11 = (ulonglong)dwLength;
  ppvVar6 = phKey;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    ppvVar6 = (BCRYPT_KEY_HANDLE *)0x15;
    WPP_SF_qqdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x15,uVar9,hAlgorithm,(char)phKey,
                (char)dwLength,(char)dwFlags);
  }
  puVar3 = ValidateBaseAlgHandle(hAlgorithm);
  if (puVar3 == (uint *)0x0) {
    NVar8 = -0x3ffffff8;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff8;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return -0x3ffffff8;
    }
    uVar13 = 0x8c;
    uVar12 = 8;
LAB_18000e203:
    WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),ppvVar6,uVar9,"Status",uVar12,
                "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar13);
    return NVar8;
  }
  if (phKey == (BCRYPT_KEY_HANDLE *)0x0) {
    NVar8 = -0x3ffffff3;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff3;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return -0x3ffffff3;
    }
    uVar13 = 0x93;
    uVar12 = 0xd;
    goto LAB_18000e203;
  }
  puVar7 = (undefined4 *)0x0;
  uVar10 = 0x20;
  puVar4 = (undefined4 *)RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30));
  if (puVar4 == (undefined4 *)0x0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3fffffe9;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return -0x3fffffe9;
    }
    WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),puVar7,uVar10,"Status",0x17,
                "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",0x9c);
    return -0x3fffffe9;
  }
  *puVar4 = 0x20;
  puVar4[1] = 0x55555552;
  *(uint **)(puVar4 + 2) = puVar3;
  uVar1 = puVar3[9];
  if (uVar1 == 3) {
LAB_18000e33d:
    pcVar5 = *(code **)(puVar3 + 0x16);
LAB_18000e341:
    puVar7 = puVar4 + 4;
    iVar2 = (*pcVar5)(*(undefined8 *)(puVar3 + 6),puVar7,uVar11,dwFlags);
    if (-1 < iVar2) {
      *phKey = puVar4;
      LOCK();
      puVar3[4] = puVar3[4] + 1;
      UNLOCK();
      return 0;
    }
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000e394;
    uVar12 = 0xc5;
  }
  else {
    if (uVar1 == 4) {
      pcVar5 = *(code **)(puVar3 + 0x1c);
      goto LAB_18000e341;
    }
    if ((uVar1 == 5) || (uVar1 == 8)) goto LAB_18000e33d;
    iVar2 = -0x3fffff45;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000e394;
    uVar12 = 0xba;
    iVar2 = -0x3fffff45;
    uVar11 = uVar10;
  }
  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),puVar7,uVar11,"Status",(char)iVar2,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar12);
LAB_18000e394:
  RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,puVar4);
  return iVar2;
}



===== BCryptImportKey @ 18000e3e0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

NTSTATUS __stdcall
BCryptImportKey(BCRYPT_ALG_HANDLE hAlgorithm,BCRYPT_KEY_HANDLE hImportKey,LPCWSTR pszBlobType,
               BCRYPT_KEY_HANDLE *phKey,PUCHAR pbKeyObject,ULONG cbKeyObject,PUCHAR pbInput,
               ULONG cbInput,ULONG dwFlags)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  NTSTATUS NVar4;
  uint *puVar5;
  uint *puVar6;
  undefined1 uVar7;
  PUCHAR pUVar8;
  int *piVar9;
  int *piVar10;
  undefined1 uVar11;
  code *pcVar12;
  uint local_48;
  int local_44;
  PUCHAR local_40;
  undefined8 local_38;
  
                    /* 0xe3e0  39  BCryptImportKey */
  puVar6 = (uint *)0x0;
  local_38 = 0;
  local_40 = (PUCHAR)0x0;
  local_48 = 0;
  local_44 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_qqSqqdqdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pbInput,pszBlobType,hAlgorithm,
                     (char)hImportKey,pszBlobType,(char)phKey,(char)pbKeyObject,(char)cbKeyObject,
                     (char)pbInput,(char)cbInput,(char)dwFlags);
  }
  puVar5 = ValidateBaseAlgHandle(hAlgorithm);
  if (puVar5 == (uint *)0x0) {
    uVar11 = 0x23;
LAB_18000e4a3:
    NVar4 = -0x3ffffff8;
    uVar7 = 8;
LAB_18000e4ad:
    DebugTraceError(uVar7,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar11)
    ;
    return NVar4;
  }
  if (hImportKey != (BCRYPT_KEY_HANDLE)0x0) {
    puVar6 = ValidateBaseKeyHandle(hImportKey);
    if (puVar6 == (uint *)0x0) {
      uVar11 = 0x2d;
      goto LAB_18000e4a3;
    }
    lVar1 = *(longlong *)(puVar6 + 2);
    if (pszBlobType == (LPCWSTR)0x0) {
LAB_18000e507:
      iVar3 = 1;
    }
    else {
      iVar2 = wcscmp(pszBlobType,L"PKCS11RsaAesWrapBlob");
      iVar3 = 3;
      if (iVar2 != 0) goto LAB_18000e507;
    }
    if (lVar1 == 0) {
      NVar4 = -0x3ffff6f6;
      uVar11 = 0x39;
      uVar7 = 10;
      goto LAB_18000e4ad;
    }
    if (*(int *)(lVar1 + 0x24) != iVar3) {
      uVar11 = 0x40;
      goto LAB_18000e4a3;
    }
    if (*(longlong *)(lVar1 + 0x28) != *(longlong *)(puVar5 + 10)) {
      iVar2 = wcscmp(pszBlobType,L"Rfc3565KeyWrapBlob");
      if (iVar2 != 0) {
        NVar4 = -0x3ffffff3;
        uVar11 = 0x4e;
        uVar7 = 0xd;
        goto LAB_18000e4ad;
      }
      local_44 = 1;
    }
    local_38 = *(undefined8 *)(puVar6 + 4);
  }
  pUVar8 = (PUCHAR)0x0;
  if ((pbKeyObject == (PUCHAR)0x0) && (cbKeyObject == 0)) {
    NVar4 = AllocateObjectBuffer(hAlgorithm,(longlong *)&local_40,&local_48);
    if (-1 < NVar4) {
      pUVar8 = local_40;
      pbKeyObject = local_40;
      cbKeyObject = local_48;
      goto LAB_18000e5ca;
    }
    DebugTraceError((char)NVar4,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",
                    0x5e);
    pUVar8 = local_40;
  }
  else {
LAB_18000e5ca:
    if (((phKey == (BCRYPT_KEY_HANDLE *)0x0) || (pbKeyObject == (PUCHAR)0x0)) ||
       (pszBlobType == (LPCWSTR)0x0)) {
      NVar4 = -0x3ffffff3;
      uVar7 = 0x71;
      uVar11 = 0xd;
LAB_18000e70d:
      DebugTraceError(uVar11,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",
                      uVar7);
    }
    else {
      if (0x3d < cbKeyObject) {
        piVar9 = (int *)((ulonglong)(pbKeyObject + 0xf) & 0xfffffffffffffff0);
        iVar2 = cbKeyObject + ((int)pbKeyObject - (int)piVar9);
        *piVar9 = iVar2;
        piVar10 = piVar9 + 8;
        piVar9[1] = 0x55555552;
        *(uint **)(piVar9 + 2) = puVar5;
        *(PUCHAR *)(piVar9 + 6) = pUVar8;
        iVar2 = (((uint)(pbKeyObject + 0xf) & 0xfffffff0) - (int)piVar10) + iVar2;
        if (puVar5[9] == 1) {
          pcVar12 = *(code **)(puVar5 + 0x1c);
        }
        else {
          if (puVar5[9] != 7) {
            NVar4 = -0x3fffff45;
            uVar7 = 0x97;
            uVar11 = 0xbb;
            goto LAB_18000e70d;
          }
          pcVar12 = *(code **)(puVar5 + 0x1e);
        }
        if (local_44 == 0) {
          NVar4 = (*pcVar12)(*(undefined8 *)(puVar5 + 6),local_38,pszBlobType,piVar9 + 4,piVar10,
                             iVar2,pbInput,cbInput,dwFlags);
          if (NVar4 < 0) {
            uVar7 = 0xbb;
            goto LAB_18000e698;
          }
        }
        else {
          NVar4 = RouterAesKeyUnwrap((longlong)puVar5,(longlong)puVar6,piVar9 + 4,piVar10,iVar2,
                                     pbInput,cbInput);
          if (NVar4 < 0) {
            uVar7 = 0xa8;
LAB_18000e698:
            uVar11 = (undefined1)NVar4;
            goto LAB_18000e70d;
          }
        }
        NVar4 = 0;
        *phKey = piVar9;
        goto LAB_18000e731;
      }
      NVar4 = -0x3fffffdd;
    }
  }
  if (pUVar8 != (PUCHAR)0x0) {
    SafeAllocaFreeToHeap(pUVar8);
  }
  if (NVar4 < 0) {
    return NVar4;
  }
LAB_18000e731:
  LOCK();
  puVar5[4] = puVar5[4] + 1;
  UNLOCK();
  return NVar4;
}



===== BCryptImportKeyPair @ 18000e760 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

NTSTATUS __stdcall
BCryptImportKeyPair(BCRYPT_ALG_HANDLE hAlgorithm,BCRYPT_KEY_HANDLE hImportKey,LPCWSTR pszBlobType,
                   BCRYPT_KEY_HANDLE *phKey,PUCHAR pbInput,ULONG cbInput,ULONG dwFlags)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  wchar_t *pwVar4;
  ulonglong uVar5;
  wchar_t *pwVar6;
  longlong lVar7;
  uint uVar8;
  wchar_t *pwVar9;
  uint uVar10;
  NTSTATUS NVar11;
  undefined1 uVar12;
  wchar_t *pwVar13;
  LPCWSTR pWVar14;
  wchar_t *pwVar15;
  code *pcVar16;
  undefined1 uVar17;
  uint local_58 [2];
  undefined4 *local_50;
  int local_40;
  uint uStack_3c;
  uint uStack_38;
  uint uStack_34;
  ulonglong local_30;
  
                    /* 0xe760  40  BCryptImportKeyPair */
  pwVar4 = (wchar_t *)0x0;
  local_58[0] = 0;
  pwVar9 = hImportKey;
  pWVar14 = pszBlobType;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_qqSqqdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),hImportKey,pszBlobType,hAlgorithm,
                   (char)hImportKey,pszBlobType,(char)phKey,(char)pbInput,(char)cbInput,
                   (char)dwFlags);
  }
  puVar2 = ValidateBaseAlgHandle(hAlgorithm);
  if (puVar2 == (uint *)0x0) {
    NVar11 = -0x3ffffff8;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff8;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return -0x3ffffff8;
    }
    uVar17 = 0xf9;
    uVar12 = 8;
LAB_18000f39e:
    WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pwVar9,pWVar14,"Status",uVar12,
                "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar17);
    return NVar11;
  }
  if ((phKey == (BCRYPT_KEY_HANDLE *)0x0) || (pszBlobType == (LPCWSTR)0x0)) {
    NVar11 = -0x3ffffff3;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff3;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return -0x3ffffff3;
    }
    uVar17 = 1;
    uVar12 = 0xd;
    goto LAB_18000f39e;
  }
  pwVar9 = (wchar_t *)0x0;
  pWVar14 = (LPCWSTR)0x20;
  local_50 = (undefined4 *)
             RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30));
  if (local_50 == (undefined4 *)0x0) {
    NVar11 = -0x3fffffe9;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3fffffe9;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return -0x3fffffe9;
    }
    uVar17 = 0x1b;
    uVar12 = 0x17;
    local_50 = (undefined4 *)0x0;
    goto LAB_18000f39e;
  }
  *local_50 = 0x20;
  local_50[1] = 0x55555552;
  *(uint **)(local_50 + 2) = puVar2;
  uVar8 = puVar2[9];
  if (uVar8 == 3) {
LAB_18000e8f6:
    pcVar16 = *(code **)(puVar2 + 0x1e);
  }
  else {
    if (uVar8 != 4) {
      if ((uVar8 != 5) && (uVar8 != 8)) {
        iVar1 = -0x3fffff45;
        goto LAB_18000f320;
      }
      goto LAB_18000e8f6;
    }
    pcVar16 = *(code **)(puVar2 + 0x20);
  }
  pwVar15 = (wchar_t *)0xffffffffffffffff;
  if (hImportKey == (BCRYPT_KEY_HANDLE)0x0) {
    pwVar13 = (wchar_t *)0x0;
LAB_18000ea98:
    pwVar9 = L"RSAFULLPRIVATEBLOB";
    pwVar6 = pwVar15;
    do {
      if (pszBlobType[(longlong)pwVar6 + 1] != L"RSAFULLPRIVATEBLOB"[(longlong)pwVar6 + 1]) break;
      pwVar6 = pwVar6 + 1;
      if (pwVar6 == (wchar_t *)0x13) {
        if ((pbInput == (PUCHAR)0x0) || (cbInput < 0x18)) {
          iVar1 = -0x7ff6ffd9;
          uVar12 = 0x27;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
            uVar17 = 0x28;
            uVar12 = 0x27;
            goto LAB_18000ed70;
          }
          goto LAB_18000ed97;
        }
        local_40 = *(int *)pbInput;
        uStack_3c = *(uint *)(pbInput + 4);
        uStack_38 = *(uint *)(pbInput + 8);
        uStack_34 = *(uint *)(pbInput + 0xc);
        local_30 = *(ulonglong *)(pbInput + 0x10);
        if (((local_40 == 0x33415352) && (uStack_3c >> 3 == uStack_34)) && (uStack_38 <= uStack_34))
        {
          pwVar15 = (wchar_t *)(local_30 & 0xffffffff);
          if (uStack_34 < (uint)local_30) goto LAB_18000ed1e;
          pwVar9 = (wchar_t *)(local_30 >> 0x20);
          uVar8 = (uint)(local_30 >> 0x20);
          if (uStack_34 < uVar8) goto LAB_18000ed1e;
          uVar10 = (uint)local_30 + 0x18 + uVar8 + uStack_38 + uStack_34;
          if (cbInput < uVar10 + (uint)local_30 * 2 + uStack_34 + uVar8) {
            iVar1 = -0x7ff6fffb;
            uVar12 = 5;
            if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
               ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000ed97;
            uVar17 = 0x4a;
            uVar12 = 5;
            goto LAB_18000ed70;
          }
          if (uStack_3c - 0x100 < 0x3f01) {
            local_58[0] = uVar10;
            pwVar4 = (wchar_t *)BCryptAlloc((ulonglong)uVar10);
            if (pwVar4 == (wchar_t *)0x0) {
              iVar1 = -0x3fffffe9;
              if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                 ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000f320;
              uVar12 = 0x7d;
              iVar1 = -0x3fffffe9;
            }
            else {
              pwVar9 = (wchar_t *)(ulonglong)cbInput;
              pwVar15 = pwVar4;
              iVar1 = ConvertRsaFullPrivateBlob
                                ((int *)pbInput,pwVar9,(undefined4 *)pwVar4,uVar10,local_58);
              if (-1 < iVar1) goto LAB_18000eeae;
              if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                 ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000f320;
              uVar12 = 0x89;
            }
            goto LAB_18000f1ca;
          }
          iVar1 = -0x7ff6ffd7;
          uVar12 = 0x29;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
            uVar17 = 0x52;
            uVar12 = 0x29;
            goto LAB_18000ed70;
          }
        }
        else {
LAB_18000ed1e:
          iVar1 = -0x7ff6fffb;
          uVar12 = 5;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
            uVar17 = 0x35;
            uVar12 = 5;
LAB_18000ed70:
            WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pwVar9,pwVar15,"Status",
                        (char)iVar1,"onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\translate.c",
                        uVar17);
          }
        }
LAB_18000ed97:
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_18000f320;
        if ((WPP_GLOBAL_Control[0x1c] & 1) != 0) {
          WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pwVar9,pwVar15,"Status",uVar12,
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\translate\\bcrypttranslate.c",0x49)
          ;
        }
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000f320;
        uVar12 = 0x74;
        goto LAB_18000f1ca;
      }
    } while (pszBlobType[(longlong)pwVar6] == L"RSAFULLPRIVATEBLOB"[(longlong)pwVar6]);
    lVar7 = 0;
    do {
      if ((pszBlobType[lVar7] != L"CAPIPRIVATEBLOB"[lVar7]) ||
         (pszBlobType[lVar7 + 1] != L"CAPIPRIVATEBLOB"[lVar7 + 1])) {
        pwVar9 = pwVar15;
        goto LAB_18000eed0;
      }
      lVar7 = lVar7 + 2;
    } while (lVar7 != 0x10);
    pwVar15 = (wchar_t *)0x0;
    pwVar9 = (wchar_t *)(ulonglong)cbInput;
    iVar1 = ConvertLegacyRsaPrivateBlob((char *)pbInput,cbInput,(undefined4 *)0x0,0,local_58);
    uVar8 = local_58[0];
    if (iVar1 == 0) {
      pwVar4 = (wchar_t *)BCryptAlloc((ulonglong)local_58[0]);
      if (pwVar4 == (wchar_t *)0x0) {
        iVar1 = -0x3fffffe9;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
          uVar12 = 0xab;
          iVar1 = -0x3fffffe9;
          goto LAB_18000f1ca;
        }
        goto LAB_18000f320;
      }
      pwVar9 = (wchar_t *)(ulonglong)cbInput;
      pwVar15 = pwVar4;
      iVar1 = ConvertLegacyRsaPrivateBlob
                        ((char *)pbInput,cbInput,(undefined4 *)pwVar4,uVar8,local_58);
      if (iVar1 == 0) {
LAB_18000eeae:
        pwVar15 = L"RSAPRIVATEBLOB";
        pbInput = (PUCHAR)pwVar4;
        uVar8 = local_58[0];
        goto LAB_18000f15c;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        uVar12 = 0xb8;
        goto LAB_18000f2c7;
      }
    }
    else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      uVar12 = 0xa2;
LAB_18000f2c7:
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pwVar9,pwVar15,"Status",(char)iVar1,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar12);
    }
    goto LAB_18000f2e7;
  }
  puVar3 = ValidateBaseKeyHandle(hImportKey);
  if (puVar3 != (uint *)0x0) {
    lVar7 = *(longlong *)(puVar3 + 2);
    pwVar13 = pwVar15;
    do {
      pwVar9 = (wchar_t *)
               (ulonglong)
               ((uint)(ushort)pszBlobType[(longlong)pwVar13 + 1] -
               (uint)(ushort)L"PKCS11RsaAesWrapBlob"[(longlong)pwVar13 + 1]);
      if (((uint)(ushort)pszBlobType[(longlong)pwVar13 + 1] -
           (uint)(ushort)L"PKCS11RsaAesWrapBlob"[(longlong)pwVar13 + 1] != 0) ||
         (pwVar13 = pwVar13 + 1, pwVar13 == (wchar_t *)0x15)) break;
      pwVar9 = (wchar_t *)
               (ulonglong)
               ((uint)(ushort)pszBlobType[(longlong)pwVar13] -
               (uint)(ushort)L"PKCS11RsaAesWrapBlob"[(longlong)pwVar13]);
    } while ((uint)(ushort)pszBlobType[(longlong)pwVar13] -
             (uint)(ushort)L"PKCS11RsaAesWrapBlob"[(longlong)pwVar13] == 0);
    iVar1 = 3;
    if ((int)pwVar9 != 0) {
      iVar1 = 1;
    }
    if (lVar7 == 0) {
      iVar1 = -0x3ffff6f6;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        uVar12 = 0x51;
        iVar1 = -0x3ffff6f6;
        goto LAB_18000f1ca;
      }
    }
    else if (*(int *)(lVar7 + 0x24) == iVar1) {
      if (*(longlong *)(lVar7 + 0x28) == *(longlong *)(puVar2 + 10)) {
        pwVar13 = *(wchar_t **)(puVar3 + 4);
        goto LAB_18000ea98;
      }
      iVar1 = -0x3fffffdc;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        uVar12 = 0x5f;
        iVar1 = -0x3fffffdc;
        goto LAB_18000f1ca;
      }
    }
    else {
      iVar1 = -0x3ffffff8;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        uVar12 = 0x58;
        iVar1 = -0x3ffffff8;
        goto LAB_18000f1ca;
      }
    }
    goto LAB_18000f320;
  }
  iVar1 = -0x3ffffff8;
  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
     ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000f320;
  uVar12 = 0x45;
  iVar1 = -0x3ffffff8;
  goto LAB_18000f1ca;
  while( true ) {
    pwVar9 = pwVar9 + 1;
    if (pwVar9 == (wchar_t *)0x13) {
      pwVar15 = (wchar_t *)0x0;
      pwVar9 = (wchar_t *)(ulonglong)cbInput;
      uVar5 = ConvertLegacyDsaPrivateBlob
                        ((undefined8 *)pbInput,cbInput,(undefined4 *)0x0,0,local_58);
      uVar8 = local_58[0];
      iVar1 = (int)uVar5;
      if (iVar1 != 0) {
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000f2e7;
        uVar12 = 0xd0;
        goto LAB_18000f2c7;
      }
      pwVar4 = (wchar_t *)BCryptAlloc((ulonglong)local_58[0]);
      if (pwVar4 == (wchar_t *)0x0) {
        iVar1 = -0x3fffffe9;
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000f320;
        uVar12 = 0xd9;
        iVar1 = -0x3fffffe9;
        goto LAB_18000f1ca;
      }
      pwVar9 = (wchar_t *)(ulonglong)cbInput;
      pwVar15 = pwVar4;
      uVar5 = ConvertLegacyDsaPrivateBlob
                        ((undefined8 *)pbInput,cbInput,(undefined4 *)pwVar4,uVar8,local_58);
      iVar1 = (int)uVar5;
      pbInput = (PUCHAR)pwVar4;
      if (iVar1 == 0) goto LAB_18000f2f1;
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000f2e7;
      uVar12 = 0xe6;
      goto LAB_18000f2c7;
    }
    if (pszBlobType[(longlong)pwVar9] != L"CAPIDSAPRIVATEBLOB"[(longlong)pwVar9]) break;
LAB_18000eed0:
    if (pszBlobType[(longlong)pwVar9 + 1] != L"CAPIDSAPRIVATEBLOB"[(longlong)pwVar9 + 1]) break;
  }
  lVar7 = 0;
  do {
    if ((pszBlobType[lVar7] != L"CAPIDHPRIVATEBLOB"[lVar7]) ||
       (pszBlobType[lVar7 + 1] != L"CAPIDHPRIVATEBLOB"[lVar7 + 1])) goto LAB_18000f131;
    lVar7 = lVar7 + 2;
  } while (lVar7 != 0x12);
  pwVar15 = (wchar_t *)0x0;
  pwVar9 = (wchar_t *)(ulonglong)cbInput;
  uVar5 = ConvertLegacyDhPrivateBlob((undefined8 *)pbInput,cbInput,(undefined4 *)0x0,0,local_58);
  uVar8 = local_58[0];
  iVar1 = (int)uVar5;
  if (iVar1 == 0) {
    pwVar4 = (wchar_t *)BCryptAlloc((ulonglong)local_58[0]);
    if (pwVar4 != (wchar_t *)0x0) {
      pwVar9 = (wchar_t *)(ulonglong)cbInput;
      pwVar15 = pwVar4;
      uVar5 = ConvertLegacyDhPrivateBlob
                        ((undefined8 *)pbInput,cbInput,(undefined4 *)pwVar4,uVar8,local_58);
      iVar1 = (int)uVar5;
      if (iVar1 == 0) {
        pwVar15 = L"DHPRIVATEBLOB";
        pbInput = (PUCHAR)pwVar4;
        uVar8 = local_58[0];
        goto LAB_18000f15c;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        uVar12 = 0x13;
        goto LAB_18000f2c7;
      }
      goto LAB_18000f2e7;
    }
    iVar1 = -0x3fffffe9;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      uVar12 = 6;
      iVar1 = -0x3fffffe9;
      goto LAB_18000f1ca;
    }
    goto LAB_18000f320;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
    uVar12 = 0xfd;
    goto LAB_18000f2c7;
  }
LAB_18000f2e7:
  if (-1 < iVar1) goto LAB_18000f317;
  goto LAB_18000f320;
LAB_18000f2f1:
  pwVar15 = L"DSAPRIVATEBLOB";
  pwVar4 = (wchar_t *)pbInput;
  uVar8 = local_58[0];
  goto LAB_18000f15c;
  while( true ) {
    pwVar15 = pwVar15 + 1;
    if (pwVar15 == (wchar_t *)0x15) {
      pwVar15 = (wchar_t *)0x0;
      pwVar9 = (wchar_t *)(ulonglong)cbInput;
      iVar1 = ConvertLegacyDsaV2PrivateBlob
                        ((undefined8 *)pbInput,cbInput,(undefined4 *)0x0,0,local_58);
      uVar8 = local_58[0];
      if (iVar1 != 0) {
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000f2e7;
        uVar12 = 0x2a;
        goto LAB_18000f2c7;
      }
      pwVar4 = (wchar_t *)BCryptAlloc((ulonglong)local_58[0]);
      if (pwVar4 == (wchar_t *)0x0) {
        iVar1 = -0x3fffffe9;
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000f320;
        uVar12 = 0x33;
        iVar1 = -0x3fffffe9;
        goto LAB_18000f1ca;
      }
      pwVar9 = (wchar_t *)(ulonglong)cbInput;
      pwVar15 = pwVar4;
      iVar1 = ConvertLegacyDsaV2PrivateBlob
                        ((undefined8 *)pbInput,cbInput,(undefined4 *)pwVar4,uVar8,local_58);
      pbInput = (PUCHAR)pwVar4;
      if (iVar1 == 0) goto LAB_18000f2f1;
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_18000f2e7;
      uVar12 = 0x40;
      goto LAB_18000f2c7;
    }
    if (pszBlobType[(longlong)pwVar15] != L"V2CAPIDSAPRIVATEBLOB"[(longlong)pwVar15]) break;
LAB_18000f131:
    if (pszBlobType[(longlong)pwVar15 + 1] != L"V2CAPIDSAPRIVATEBLOB"[(longlong)pwVar15 + 1]) break;
  }
  pwVar15 = pszBlobType;
  uVar8 = cbInput;
LAB_18000f15c:
  iVar1 = (*pcVar16)(*(undefined8 *)(puVar2 + 6),pwVar13,pwVar15,local_50 + 4,pbInput,uVar8,dwFlags)
  ;
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      uVar12 = 0x59;
      pwVar9 = pwVar13;
LAB_18000f1ca:
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pwVar9,pwVar15,"Status",(char)iVar1,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar12);
    }
  }
  else {
    *phKey = local_50;
    local_50 = (undefined4 *)0x0;
    iVar1 = 0;
LAB_18000f317:
    LOCK();
    puVar2[4] = puVar2[4] + 1;
    UNLOCK();
    if (local_50 == (undefined4 *)0x0) goto LAB_18000f33f;
  }
LAB_18000f320:
  RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,local_50);
LAB_18000f33f:
  if (pwVar4 != (wchar_t *)0x0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,pwVar4);
  }
  return iVar1;
}



===== BCryptSetProperty @ 18000f3e0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

NTSTATUS __stdcall
BCryptSetProperty(BCRYPT_HANDLE hObject,LPCWSTR pszProperty,PUCHAR pbInput,ULONG cbInput,
                 ULONG dwFlags)

{
  int iVar1;
  uint *puVar2;
  undefined8 uVar3;
  LPCWSTR pWVar4;
  PUCHAR pUVar5;
  undefined1 uVar6;
  
                    /* 0xf3e0  56  BCryptSetProperty */
  pWVar4 = pszProperty;
  pUVar5 = pbInput;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_qSqdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pszProperty,pbInput,hObject,pszProperty,
                 (char)pbInput,(char)cbInput,(char)dwFlags);
  }
  if (pszProperty == (LPCWSTR)0x0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff3;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return -0x3ffffff3;
    }
    uVar6 = 0x8a;
    iVar1 = -0x3ffffff3;
    pszProperty = pWVar4;
    pbInput = pUVar5;
    goto LAB_18000f5e6;
  }
  puVar2 = ValidateBaseAlgHandle(hObject);
  if (puVar2 == (uint *)0x0) {
    if ((((((byte)hObject & 0xf) != 1) && (hObject != (BCRYPT_HANDLE)0x0)) &&
        (0x17 < *(uint *)hObject)) && (*(int *)((longlong)hObject + 4) + 0xaaaaaaaeU < 3)) {
      puVar2 = *(uint **)((longlong)hObject + 8);
      uVar3 = *(undefined8 *)((longlong)hObject + 0x10);
      goto LAB_18000f51a;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff8;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return -0x3ffffff8;
    }
    uVar6 = 0xa4;
  }
  else {
    if ((int)puVar2[2] < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3fffffde;
      }
      if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
        return -0x3fffffde;
      }
      uVar6 = 0x97;
      iVar1 = -0x3fffffde;
      pszProperty = pWVar4;
      pbInput = pUVar5;
      goto LAB_18000f5e6;
    }
    uVar3 = *(undefined8 *)(puVar2 + 6);
LAB_18000f51a:
    switch(puVar2[9]) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
      iVar1 = (**(code **)(puVar2 + 0x12))(uVar3,pszProperty,pbInput,cbInput,dwFlags);
      if (-1 < iVar1) {
        return 0;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar1;
      }
      if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
        return iVar1;
      }
      uVar6 = 0xd8;
      goto LAB_18000f5e6;
    default:
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3ffffff8;
      }
      if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
        return -0x3ffffff8;
      }
      uVar6 = 0xcc;
    }
  }
  iVar1 = -0x3ffffff8;
  pszProperty = pWVar4;
  pbInput = pUVar5;
LAB_18000f5e6:
  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pszProperty,pbInput,"Status",(char)iVar1,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar6);
  return iVar1;
}



===== BCryptSignHash @ 18000f640 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

NTSTATUS __stdcall
BCryptSignHash(BCRYPT_KEY_HANDLE hKey,void *pPaddingInfo,PUCHAR pbInput,ULONG cbInput,
              PUCHAR pbOutput,ULONG cbOutput,ULONG *pcbResult,ULONG dwFlags)

{
  undefined4 *puVar1;
  longlong lVar2;
  bool bVar3;
  ULONG UVar4;
  undefined8 *puVar5;
  char cVar6;
  uint uVar7;
  uint uVar8;
  uint *hObject;
  undefined8 uVar9;
  uint *puVar10;
  undefined1 uVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  code *pcVar16;
  wchar_t *pwVar17;
  char *pcVar18;
  uint *puVar19;
  undefined1 uVar20;
  undefined1 auStackY_168 [32];
  uint local_108;
  ULONG local_104;
  uint local_100 [2];
  wchar_t *local_f8;
  uint *local_f0;
  undefined8 *local_e8;
  ULONG local_e0 [2];
  undefined1 local_d8 [32];
  undefined8 **local_b8;
  undefined4 local_b0;
  undefined4 local_ac;
  uint **local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  uint *local_98;
  undefined4 local_90;
  undefined4 local_8c;
  ULONG *local_88;
  undefined4 local_80;
  undefined4 local_7c;
  longlong local_78 [2];
  longlong local_68 [2];
  ulonglong local_58;
  
                    /* 0xf640  57  BCryptSignHash */
  puVar19 = &local_108;
  local_58 = __security_cookie ^ (ulonglong)puVar19;
  local_100[0] = 0;
  puVar10 = (uint *)0x0;
  local_108 = 0;
  local_e0[0] = 0;
  local_104 = cbInput;
  local_f0 = (uint *)pbInput;
  local_e8 = pPaddingInfo;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_qqqdqdqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x26,(ulonglong)cbOutput,hKey,
                    (char)pPaddingInfo,(char)pbInput,(char)cbInput,(char)pbOutput,(char)cbOutput,
                    (char)pcbResult,(byte)dwFlags);
  }
  if (pcbResult == (ULONG *)0x0) {
    uVar7 = 0xc000000d;
    uVar20 = 0xf1;
    uVar11 = 0xd;
  }
  else {
    hObject = ValidateBaseKeyHandle(hKey);
    puVar15 = auStackY_168;
    if (hObject != (uint *)0x0) {
      lVar2 = *(longlong *)(hObject + 2);
      local_f8 = (wchar_t *)(lVar2 + 0x1bc);
      if (*(int *)(lVar2 + 0x24) == 5) {
        pcVar16 = *(code **)(lVar2 + 0x68);
LAB_18000f75c:
        puVar15 = auStackY_168;
        pcVar18 = (char *)local_f0;
        uVar7 = (*pcVar16)(*(undefined8 *)(hObject + 4),local_e8,local_f0,local_104);
        if ((int)uVar7 < 0) {
          uVar20 = 0x7e;
          puVar15 = auStackY_168;
LAB_18000f7cc:
          uVar11 = (undefined1)uVar7;
LAB_18000f99a:
          pcVar18 = "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c";
          *(undefined8 *)(puVar15 + -8) = 0x18000f9ad;
          DebugTraceError(uVar11,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",
                          uVar20);
        }
        else {
LAB_18000f986:
          uVar7 = 0;
        }
      }
      else {
        if (*(int *)(lVar2 + 0x24) != 3) {
          uVar7 = 0xc00000bb;
          uVar20 = 0x30;
          uVar11 = 0xbb;
          goto LAB_18000f99a;
        }
        pcVar18 = (char *)local_100;
        uVar9 = ShouldRouterPadSignature
                          ((byte)*(undefined4 *)(lVar2 + 0x1b8),(byte)dwFlags,(undefined4 *)pcVar18)
        ;
        uVar8 = local_100[0];
        uVar7 = (uint)uVar9;
        if ((int)uVar7 < 0) {
          uVar20 = 0x15;
          puVar15 = auStackY_168;
          goto LAB_18000f7cc;
        }
        if (local_100[0] != 0) {
          uVar7 = BCryptGetProperty(hObject,L"KeyStrength",(PUCHAR)puVar19,4,local_e0,0);
          if ((int)uVar7 < 0) {
            uVar20 = 0x24;
            puVar15 = auStackY_168;
            goto LAB_18000f7cc;
          }
          local_108 = local_108 + 7 >> 3;
          pcVar18 = (char *)puVar19;
        }
        pcVar16 = *(code **)(lVar2 + 0x90);
        if (uVar8 == 0) goto LAB_18000f75c;
        if (pbOutput == (PUCHAR)0x0) {
          pcVar18 = (char *)local_f0;
          uVar7 = (*pcVar16)(*(undefined8 *)(hObject + 4),0,local_f0,local_104);
          puVar15 = auStackY_168;
          if ((int)uVar7 < 0) {
            uVar20 = 0x43;
            puVar15 = auStackY_168;
            goto LAB_18000f7cc;
          }
          goto LAB_18000f986;
        }
        uVar13 = (ulonglong)local_108;
        puVar14 = auStackY_168;
        if (((uVar13 == 0) || (puVar14 = auStackY_168, g_ulMaxStackAllocSize < uVar13)) ||
           (uVar12 = g_ulAdditionalProbeSize + 8 + uVar13, puVar14 = auStackY_168, uVar12 < uVar13))
        {
LAB_18000f8dd:
          puVar15 = puVar14;
          if (uVar13 <= uVar13 + 8) {
            *(undefined8 *)(puVar14 + -8) = 0x18000f8f2;
            puVar10 = (uint *)(*g_pfnAllocate)();
            if (puVar10 != (uint *)0x0) {
              *puVar10 = 0x70616548;
              puVar10 = puVar10 + 2;
            }
          }
        }
        else {
          uVar9 = VerifyStackAvailable(uVar12);
          puVar14 = auStackY_168;
          if ((int)uVar9 == 0) goto LAB_18000f8dd;
          uVar12 = uVar13 + 0x17;
          if (uVar12 <= uVar13 + 8) {
            uVar12 = 0xffffffffffffff0;
          }
          lVar2 = -(uVar12 & 0xfffffffffffffff0);
          puVar1 = (undefined4 *)((longlong)local_100 + lVar2 + -8);
          puVar10 = (uint *)0x0;
          puVar14 = auStackY_168 + lVar2;
          if (puVar1 == (undefined4 *)0x0) goto LAB_18000f8dd;
          *puVar1 = 0x6b637453;
          puVar10 = (uint *)((longlong)local_100 + lVar2);
          puVar14 = auStackY_168 + lVar2;
          puVar15 = auStackY_168 + lVar2;
          if (puVar10 == (uint *)0x0) goto LAB_18000f8dd;
        }
        puVar5 = local_e8;
        puVar19 = local_f0;
        UVar4 = local_104;
        if (puVar10 != (uint *)0x0) {
          *(uint *)(puVar15 + 0x28) = local_108;
          *(uint **)(puVar15 + 0x20) = puVar10;
          *(undefined8 *)(puVar15 + -8) = 0x18000f936;
          uVar7 = ApplySignaturePadding
                            ((ulonglong)dwFlags,puVar5,puVar19,UVar4,*(byte **)(puVar15 + 0x20),
                             *(uint *)(puVar15 + 0x28));
          if ((int)uVar7 < 0) {
            uVar20 = 0x5f;
          }
          else {
            *(undefined4 *)(puVar15 + 0x38) = 0;
            uVar7 = local_108;
            uVar9 = *(undefined8 *)(hObject + 4);
            *(ULONG **)(puVar15 + 0x30) = pcbResult;
            *(ULONG *)(puVar15 + 0x28) = cbOutput;
            *(PUCHAR *)(puVar15 + 0x20) = pbOutput;
            *(undefined8 *)(puVar15 + -8) = 0x18000f975;
            pcVar18 = (char *)puVar10;
            uVar7 = (*pcVar16)(uVar9,0,puVar10,uVar7);
            if (-1 < (int)uVar7) goto LAB_18000f986;
            uVar20 = 0x6d;
          }
          goto LAB_18000f7cc;
        }
        uVar7 = 0xc0000017;
      }
      pwVar17 = local_f8;
      goto LAB_18000f9b1;
    }
    uVar7 = 0xc0000008;
    uVar20 = 0xf9;
    uVar11 = 8;
  }
  puVar15 = auStackY_168;
  pcVar18 = "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c";
  DebugTraceError(uVar11,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar20);
  pwVar17 = (wchar_t *)0x0;
LAB_18000f9b1:
  uVar8 = g_TrustedEnvironment;
  if (g_TrustedEnvironment == 0) {
    *(undefined8 *)(puVar15 + -8) = 0x18000f9c0;
    uVar8 = GetTrustedEnvironment();
  }
  if ((uVar8 & 1) != 0) {
    *(undefined8 *)(puVar15 + -8) = 0x18000f9cf;
    cVar6 = RtlDllShutdownInProgress();
    if ((cVar6 == '\0') && (5 < DAT_180025058)) {
      if (((_DAT_180025068 & 0x400000000000) == 0) ||
         ((DAT_180025070 & 0x400000000000) != DAT_180025070)) {
        bVar3 = false;
      }
      else {
        bVar3 = true;
      }
      if (bVar3) {
        local_ac = 0;
        local_b8 = &local_e8;
        local_9c = 0;
        local_8c = 0;
        local_104 = 0;
        local_7c = 0;
        local_a8 = &local_f0;
        local_98 = local_100;
        local_88 = &local_104;
        local_e8 = (undefined8 *)0x1;
        local_b0 = 8;
        local_f0 = (uint *)0x1000000;
        local_a0 = 8;
        local_90 = 4;
        local_80 = 4;
        local_100[0] = uVar7;
        *(undefined8 *)(puVar15 + -8) = 0x18000fa9c;
        _tlgCreate1Sz_wchar_t(local_78,g_processImageName);
        *(undefined8 *)(puVar15 + -8) = 0x18000faab;
        _tlgCreate1Sz_wchar_t(local_68,pwVar17);
        *(undefined1 **)(puVar15 + 0x20) = local_d8;
        *(undefined8 *)(puVar15 + -8) = 0x18000fac6;
        _tlgWriteAgg(local_d8,&DAT_180020621,pcVar18,8,*(PEVENT_DATA_DESCRIPTOR *)(puVar15 + 0x20));
      }
    }
  }
  if ((puVar10 != (uint *)0x0) && (puVar10[-2] == 0x70616548)) {
    *(undefined8 *)(puVar15 + -8) = 0x18000fae3;
    (*g_pfnFree)();
  }
  *(undefined8 *)(puVar15 + -8) = 0x18000faf4;
  return uVar7;
}



===== BCryptVerifySignature @ 18000fb10 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

NTSTATUS __stdcall
BCryptVerifySignature
          (BCRYPT_KEY_HANDLE hKey,void *pPaddingInfo,PUCHAR pbHash,ULONG cbHash,PUCHAR pbSignature,
          ULONG cbSignature,ULONG dwFlags)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  PUCHAR pUVar4;
  char cVar5;
  ULONG UVar6;
  uint uVar7;
  uint *puVar8;
  undefined4 *puVar9;
  code *pcVar10;
  undefined1 uVar11;
  ulonglong uVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  ulonglong uVar15;
  undefined8 uVar16;
  undefined1 uVar17;
  longlong lVar18;
  undefined8 *puVar19;
  wchar_t *pwVar20;
  undefined1 auStackY_168 [32];
  int local_108 [2];
  wchar_t *local_100;
  undefined8 *local_f8;
  PUCHAR local_f0;
  undefined4 local_e8 [4];
  undefined1 local_d8 [32];
  PUCHAR *local_b8;
  undefined8 local_b0;
  undefined8 **local_a8;
  undefined8 local_a0;
  int *local_98;
  undefined8 local_90;
  int *local_88;
  undefined8 local_80;
  longlong local_78 [2];
  longlong local_68 [2];
  ulonglong local_58;
  
                    /* 0xfb10  60  BCryptVerifySignature */
  local_58 = __security_cookie ^ (ulonglong)local_108;
  local_108[0] = 0;
  puVar9 = (undefined4 *)0x0;
  local_e8[0] = 0;
  pwVar20 = (wchar_t *)0x0;
  uVar15 = (ulonglong)cbSignature;
  local_108[1] = cbHash;
  local_f8 = pPaddingInfo;
  local_f0 = pbHash;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_qqqdqdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x27,pbHash,hKey,(char)pPaddingInfo,
                   (char)pbHash,(char)cbHash,(char)pbSignature,(char)cbSignature,(byte)dwFlags);
  }
  puVar19 = local_f8;
  puVar8 = ValidateBaseKeyHandle(hKey);
  if (puVar8 == (uint *)0x0) {
    UVar6 = 0xc0000008;
    uVar11 = 0xd1;
    uVar17 = 8;
  }
  else {
    if (pbSignature != (PUCHAR)0x0) {
      lVar18 = *(longlong *)(puVar8 + 2);
      pwVar20 = (wchar_t *)(lVar18 + 0x1bc);
      local_100 = pwVar20;
      if (*(int *)(lVar18 + 0x24) == 5) {
        pcVar10 = *(code **)(lVar18 + 0x70);
LAB_18000fda8:
        pwVar20 = local_100;
        UVar6 = (*pcVar10)(*(undefined8 *)(puVar8 + 4),puVar19,local_f0,local_108[1]);
        puVar14 = auStackY_168;
        if ((int)UVar6 < 0) {
          uVar11 = 0x40;
LAB_18000fc40:
          uVar17 = (undefined1)UVar6;
          goto LAB_18000fdf2;
        }
LAB_18000fddb:
        UVar6 = 0;
      }
      else {
        if (*(int *)(lVar18 + 0x24) != 3) {
          UVar6 = 0xc00000bb;
          uVar11 = 0xfb;
          uVar17 = 0xbb;
          goto LAB_18000fdf2;
        }
        uVar16 = ShouldRouterPadSignature
                           ((byte)*(undefined4 *)(lVar18 + 0x1b8),(byte)dwFlags,local_108);
        UVar6 = (ULONG)uVar16;
        if ((int)UVar6 < 0) {
          uVar11 = 0xf1;
          goto LAB_18000fc40;
        }
        pcVar10 = *(code **)(lVar18 + 0x98);
        pcVar1 = *(code **)(lVar18 + 0x68);
        if (local_108[0] == 0) goto LAB_18000fda8;
        puVar13 = auStackY_168;
        if ((cbSignature == 0) || (puVar13 = auStackY_168, g_ulMaxStackAllocSize < uVar15)) {
LAB_18000fcc3:
          puVar14 = puVar13;
          if (uVar15 <= uVar15 + 8) {
            *(undefined8 *)(puVar13 + -8) = 0x18000fcd8;
            puVar9 = (undefined4 *)(*g_pfnAllocate)();
            if (puVar9 != (undefined4 *)0x0) {
              *puVar9 = 0x70616548;
              puVar9 = puVar9 + 2;
            }
          }
        }
        else {
          uVar12 = g_ulAdditionalProbeSize + 8 + uVar15;
          puVar13 = auStackY_168;
          if (uVar12 < uVar15) goto LAB_18000fcc3;
          uVar16 = VerifyStackAvailable(uVar12);
          puVar13 = auStackY_168;
          if ((int)uVar16 == 0) goto LAB_18000fcc3;
          uVar12 = uVar15 + 0x17;
          if (uVar12 <= uVar15 + 8) {
            uVar12 = 0xffffffffffffff0;
          }
          lVar18 = -(uVar12 & 0xfffffffffffffff0);
          puVar9 = (undefined4 *)0x0;
          puVar13 = auStackY_168 + lVar18;
          if ((undefined4 *)((longlong)local_108 + lVar18) == (undefined4 *)0x0) goto LAB_18000fcc3;
          *(undefined4 *)((longlong)local_108 + lVar18) = 0x6b637453;
          puVar9 = (undefined4 *)((longlong)local_108 + lVar18 + 8);
          puVar13 = auStackY_168 + lVar18;
          puVar14 = auStackY_168 + lVar18;
          if (puVar9 == (undefined4 *)0x0) goto LAB_18000fcc3;
        }
        if (puVar9 == (undefined4 *)0x0) {
          UVar6 = 0xc0000017;
          uVar17 = 0xd;
          uVar11 = 0x17;
        }
        else if (pcVar1 == (code *)0x0) {
          UVar6 = 0xc00000e5;
          uVar17 = 0x14;
          uVar11 = 0xe5;
        }
        else {
          *(undefined4 *)(puVar14 + 0x48) = 0;
          uVar16 = *(undefined8 *)(puVar8 + 4);
          *(undefined4 **)(puVar14 + 0x40) = local_e8;
          *(ULONG *)(puVar14 + 0x38) = cbSignature;
          *(undefined4 **)(puVar14 + 0x30) = puVar9;
          *(undefined4 *)(puVar14 + 0x28) = 0;
          *(undefined8 *)(puVar14 + 0x20) = 0;
          *(undefined8 *)(puVar14 + -8) = 0x18000fd69;
          UVar6 = (*pcVar1)(uVar16,pbSignature,cbSignature,0);
          pUVar4 = local_f0;
          puVar19 = local_f8;
          iVar3 = local_108[1];
          if ((int)UVar6 < 0) {
            uVar17 = 0x24;
          }
          else {
            *(ULONG *)(puVar14 + 0x28) = cbSignature;
            *(undefined4 **)(puVar14 + 0x20) = puVar9;
            *(undefined8 *)(puVar14 + -8) = 0x18000fd96;
            UVar6 = CheckSignaturePadding
                              ((ulonglong)dwFlags,puVar19,pUVar4,iVar3,*(byte **)(puVar14 + 0x20),
                               *(uint *)(puVar14 + 0x28));
            if (-1 < (int)UVar6) goto LAB_18000fddb;
            uVar17 = 0x31;
          }
          uVar11 = (undefined1)UVar6;
        }
        *(undefined8 *)(puVar14 + -8) = 0x18000fd12;
        DebugTraceError(uVar11,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",
                        uVar17);
      }
      pwVar20 = local_100;
      goto LAB_18000fe05;
    }
    UVar6 = 0xc000000d;
    uVar11 = 0xd8;
    uVar17 = 0xd;
  }
LAB_18000fdf2:
  DebugTraceError(uVar17,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar11);
  puVar14 = auStackY_168;
LAB_18000fe05:
  uVar7 = g_TrustedEnvironment;
  if (g_TrustedEnvironment == 0) {
    *(undefined8 *)(puVar14 + -8) = 0x18000fe14;
    uVar7 = GetTrustedEnvironment();
  }
  if ((uVar7 & 1) != 0) {
    *(undefined8 *)(puVar14 + -8) = 0x18000fe23;
    cVar5 = RtlDllShutdownInProgress();
    if ((cVar5 == '\0') && (5 < DAT_180025058)) {
      uVar16 = 0x400000000000;
      if (((_DAT_180025068 & 0x400000000000) == 0) ||
         (bVar2 = true, (DAT_180025070 & 0x400000000000) != DAT_180025070)) {
        bVar2 = false;
      }
      if (bVar2) {
        local_b8 = &local_f0;
        local_108[0] = 0;
        local_a8 = &local_f8;
        local_f0 = (PUCHAR)0x1;
        local_98 = local_108 + 1;
        local_b0 = 8;
        local_f8 = (undefined8 *)0x1000000;
        local_a0 = 8;
        local_90 = 4;
        local_80 = 4;
        local_108[1] = UVar6;
        local_88 = local_108;
        *(undefined8 *)(puVar14 + -8) = 0x18000fee0;
        _tlgCreate1Sz_wchar_t(local_78,g_processImageName);
        *(undefined8 *)(puVar14 + -8) = 0x18000feef;
        _tlgCreate1Sz_wchar_t(local_68,pwVar20);
        *(undefined1 **)(puVar14 + 0x20) = local_d8;
        *(undefined8 *)(puVar14 + -8) = 0x18000ff0a;
        _tlgWriteAgg(local_d8,&DAT_18002076a,uVar16,8,*(PEVENT_DATA_DESCRIPTOR *)(puVar14 + 0x20));
      }
    }
  }
  if ((puVar9 != (undefined4 *)0x0) && (puVar9[-2] == 0x70616548)) {
    *(undefined8 *)(puVar14 + -8) = 0x18000ff27;
    (*g_pfnFree)();
  }
  *(undefined8 *)(puVar14 + -8) = 0x18000ff38;
  return UVar6;
}



===== ValidateFunctionTable @ 18000ff60 =====

undefined8
ValidateFunctionTable
          (undefined4 param_1,longlong param_2,longlong *param_3,longlong *param_4,longlong *param_5
          ,undefined8 *param_6)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 uVar4;
  
  switch(param_1) {
  case 1:
    lVar2 = *(longlong *)(param_2 + 8);
    lVar3 = *(longlong *)(param_2 + 0x20);
    *param_3 = lVar2;
    param_3 = *(longlong **)(param_2 + 0x18);
    *param_5 = (longlong)param_3;
    *param_4 = lVar3;
    if (((((lVar2 != 0) && (lVar3 != 0)) &&
         ((param_3 != (longlong *)0x0 &&
          (((*(longlong *)(param_2 + 0x10) != 0 && (*(longlong *)(param_2 + 0x28) != 0)) &&
           (*(longlong *)(param_2 + 0x30) != 0)))))) &&
        ((*(longlong *)(param_2 + 0x38) != 0 && (*(longlong *)(param_2 + 0x40) != 0)))) &&
       ((*(longlong *)(param_2 + 0x48) != 0 &&
        ((*(longlong *)(param_2 + 0x50) != 0 && (*(longlong *)(param_2 + 0x58) != 0)))))) {
      return 0;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc0000008;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return 0xc0000008;
    }
    uVar4 = 0xdf;
    break;
  case 2:
    lVar2 = *(longlong *)(param_2 + 8);
    lVar3 = *(longlong *)(param_2 + 0x20);
    *param_4 = lVar3;
    lVar1 = *(longlong *)(param_2 + 0x18);
    *param_5 = lVar1;
    *param_3 = lVar2;
    param_3 = *(longlong **)(param_2 + 0x10);
    *param_6 = param_3;
    if ((((lVar2 != 0) && (lVar3 != 0)) &&
        ((lVar1 != 0 &&
         (((param_3 != (longlong *)0x0 && (*(longlong *)(param_2 + 0x28) != 0)) &&
          (*(longlong *)(param_2 + 0x30) != 0)))))) &&
       (((*(longlong *)(param_2 + 0x38) != 0 && (*(longlong *)(param_2 + 0x40) != 0)) &&
        (*(longlong *)(param_2 + 0x48) != 0)))) {
      return 0;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc0000008;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return 0xc0000008;
    }
    uVar4 = 0xf2;
    break;
  case 3:
    lVar2 = *(longlong *)(param_2 + 8);
    lVar3 = *(longlong *)(param_2 + 0x20);
    *param_4 = lVar3;
    lVar1 = *(longlong *)(param_2 + 0x18);
    *param_5 = lVar1;
    *param_3 = lVar2;
    param_3 = *(longlong **)(param_2 + 0x10);
    *param_6 = param_3;
    if (((lVar2 != 0) && (lVar3 != 0)) &&
       ((((lVar1 != 0 && ((param_3 != (longlong *)0x0 && (*(longlong *)(param_2 + 0x28) != 0)))) &&
         (*(longlong *)(param_2 + 0x30) != 0)) &&
        (((((*(longlong *)(param_2 + 0x38) != 0 && (*(longlong *)(param_2 + 0x40) != 0)) &&
           (*(longlong *)(param_2 + 0x58) != 0)) &&
          ((*(longlong *)(param_2 + 0x48) != 0 && (*(longlong *)(param_2 + 0x50) != 0)))) &&
         ((*(longlong *)(param_2 + 0x60) != 0 && (*(longlong *)(param_2 + 0x68) != 0)))))))) {
      return 0;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc0000008;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return 0xc0000008;
    }
    uVar4 = 9;
    break;
  case 4:
    lVar2 = *(longlong *)(param_2 + 8);
    lVar3 = *(longlong *)(param_2 + 0x20);
    *param_3 = lVar2;
    param_3 = *(longlong **)(param_2 + 0x18);
    *param_5 = (longlong)param_3;
    *param_4 = lVar3;
    if (((((lVar2 != 0) && (lVar3 != 0)) && (param_3 != (longlong *)0x0)) &&
        (((*(longlong *)(param_2 + 0x10) != 0 && (*(longlong *)(param_2 + 0x28) != 0)) &&
         ((*(longlong *)(param_2 + 0x30) != 0 &&
          ((*(longlong *)(param_2 + 0x38) != 0 && (*(longlong *)(param_2 + 0x40) != 0)))))))) &&
       ((*(longlong *)(param_2 + 0x48) != 0 &&
        (((*(longlong *)(param_2 + 0x50) != 0 && (*(longlong *)(param_2 + 0x58) != 0)) &&
         (*(longlong *)(param_2 + 0x60) != 0)))))) {
      return 0;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc0000008;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return 0xc0000008;
    }
    uVar4 = 0x1e;
    break;
  case 5:
    lVar2 = *(longlong *)(param_2 + 8);
    lVar3 = *(longlong *)(param_2 + 0x20);
    *param_3 = lVar2;
    param_3 = *(longlong **)(param_2 + 0x18);
    *param_5 = (longlong)param_3;
    *param_4 = lVar3;
    if ((((lVar2 != 0) && (lVar3 != 0)) &&
        ((param_3 != (longlong *)0x0 &&
         ((((*(longlong *)(param_2 + 0x10) != 0 && (*(longlong *)(param_2 + 0x28) != 0)) &&
           (*(longlong *)(param_2 + 0x30) != 0)) &&
          ((*(longlong *)(param_2 + 0x38) != 0 && (*(longlong *)(param_2 + 0x40) != 0)))))))) &&
       ((*(longlong *)(param_2 + 0x48) != 0 &&
        ((*(longlong *)(param_2 + 0x50) != 0 && (*(longlong *)(param_2 + 0x58) != 0)))))) {
      return 0;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc0000008;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return 0xc0000008;
    }
    uVar4 = 0x32;
    break;
  case 6:
    lVar2 = *(longlong *)(param_2 + 8);
    lVar3 = *(longlong *)(param_2 + 0x20);
    *param_3 = lVar2;
    param_3 = *(longlong **)(param_2 + 0x18);
    *param_5 = (longlong)param_3;
    *param_4 = lVar3;
    if ((((lVar2 != 0) && (lVar3 != 0)) && (param_3 != (longlong *)0x0)) &&
       ((*(longlong *)(param_2 + 0x10) != 0 && (*(longlong *)(param_2 + 0x28) != 0)))) {
      return 0;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc0000008;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return 0xc0000008;
    }
    uVar4 = 0x40;
    break;
  case 7:
    lVar2 = *(longlong *)(param_2 + 8);
    lVar3 = *(longlong *)(param_2 + 0x20);
    *param_3 = lVar2;
    param_3 = *(longlong **)(param_2 + 0x18);
    *param_5 = (longlong)param_3;
    *param_4 = lVar3;
    if (((((lVar2 != 0) && (lVar3 != 0)) && (param_3 != (longlong *)0x0)) &&
        (((*(longlong *)(param_2 + 0x10) != 0 && (*(longlong *)(param_2 + 0x28) != 0)) &&
         ((*(longlong *)(param_2 + 0x38) != 0 &&
          ((*(longlong *)(param_2 + 0x48) != 0 && (*(longlong *)(param_2 + 0x40) != 0)))))))) &&
       ((*(longlong *)(param_2 + 0x50) != 0 && (*(longlong *)(param_2 + 0x30) != 0)))) {
      return 0;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc0000008;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return 0xc0000008;
    }
    uVar4 = 0x53;
    break;
  case 8:
    lVar2 = *(longlong *)(param_2 + 8);
    lVar3 = *(longlong *)(param_2 + 0x20);
    *param_3 = lVar2;
    param_3 = *(longlong **)(param_2 + 0x18);
    *param_5 = (longlong)param_3;
    *param_4 = lVar3;
    if (((((((lVar2 != 0) && (lVar3 != 0)) && (param_3 != (longlong *)0x0)) &&
          ((*(longlong *)(param_2 + 0x10) != 0 && (*(longlong *)(param_2 + 0x28) != 0)))) &&
         (*(longlong *)(param_2 + 0x30) != 0)) &&
        ((*(longlong *)(param_2 + 0x38) != 0 && (*(longlong *)(param_2 + 0x40) != 0)))) &&
       ((*(longlong *)(param_2 + 0x48) != 0 &&
        ((*(longlong *)(param_2 + 0x50) != 0 && (*(longlong *)(param_2 + 0x58) != 0)))))) {
      return 0;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc0000008;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return 0xc0000008;
    }
    uVar4 = 0x67;
    break;
  default:
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc0000008;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return 0xc0000008;
    }
    uVar4 = 0x6e;
  }
  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,param_3,"Status",8,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar4);
  return 0xc0000008;
}



===== VsmOpenAlgorithmProvider @ 18001046c =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

int VsmOpenAlgorithmProvider(undefined8 *param_1,wchar_t *param_2,void *param_3,uint param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *_Dst;
  longlong lVar6;
  undefined8 uVar7;
  undefined1 uVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  undefined1 uVar12;
  ulonglong uVar13;
  longlong lVar14;
  uint local_res18 [4];
  code **ppcVar15;
  code **ppcVar16;
  undefined4 local_1f8;
  undefined4 local_1f4;
  code *local_1f0;
  code *local_1e8;
  code *local_1e0;
  longlong local_1d8 [2];
  undefined8 local_1c8 [50];
  
  local_1f8 = 4;
  local_res18[0] = 0;
  local_1f0 = (code *)0x0;
  local_1d8[0] = 0;
  local_1e0 = (code *)0x0;
  local_1e8 = (code *)0x0;
  local_1f4 = 0;
  if ((param_3 != (void *)0x0) && (iVar4 = memcmp(param_3,&u_Microsoft_Primi,0x3a), iVar4 != 0)) {
    iVar4 = -0x3ffffff3;
    uVar12 = 0x7b;
    uVar8 = 0xd;
    goto LAB_1800104ed;
  }
  GetAlgorithmClass((longlong)param_2,local_res18);
  if (local_res18[0] < 0x35) {
    uVar13 = (ulonglong)local_res18[0];
    lVar14 = uVar13 * 0x20;
    iVar4 = *(int *)(&DAT_18001e018 + lVar14);
    if (iVar4 - 1U < 8) {
      _Dst = (undefined4 *)BCryptAlloc(0x3c8);
      if (_Dst == (undefined4 *)0x0) {
        iVar4 = -0x3fffffe9;
        uVar12 = 0x9a;
        uVar8 = 0x17;
        goto LAB_1800104ed;
      }
      memset(_Dst,0,0x3c8);
      *_Dst = 0x3c8;
      _Dst[1] = 0x55555551;
      _Dst[4] = 1;
      _Dst[9] = iVar4;
      wcsncpy_s((wchar_t *)(_Dst + 0x6f),0x104,param_2,0xffffffffffffffff);
      puVar11 = (undefined8 *)(_Dst + 0xc);
      _Dst[8] = param_4 & 1;
      iVar5 = VsmLoadInterface(_Dst[9],param_2,param_4,puVar11);
      if (iVar5 < 0) {
        uVar8 = 0xb9;
        goto LAB_180010793;
      }
      lVar6 = 3;
      puVar9 = local_1c8;
      do {
        uVar7 = puVar11[1];
        uVar1 = puVar11[2];
        uVar2 = puVar11[3];
        *puVar9 = *puVar11;
        puVar9[1] = uVar7;
        uVar7 = puVar11[4];
        uVar3 = puVar11[5];
        puVar9[2] = uVar1;
        puVar9[3] = uVar2;
        uVar1 = puVar11[6];
        uVar2 = puVar11[7];
        puVar9[4] = uVar7;
        puVar9[5] = uVar3;
        uVar7 = puVar11[8];
        uVar3 = puVar11[9];
        puVar9[6] = uVar1;
        puVar9[7] = uVar2;
        uVar1 = puVar11[10];
        uVar2 = puVar11[0xb];
        puVar9[8] = uVar7;
        puVar9[9] = uVar3;
        uVar7 = puVar11[0xc];
        uVar3 = puVar11[0xd];
        puVar9[10] = uVar1;
        puVar9[0xb] = uVar2;
        uVar1 = puVar11[0xe];
        uVar2 = puVar11[0xf];
        puVar11 = puVar11 + 0x10;
        puVar9[0xc] = uVar7;
        puVar9[0xd] = uVar3;
        puVar10 = puVar9 + 0x10;
        puVar9[0xe] = uVar1;
        puVar9[0xf] = uVar2;
        lVar6 = lVar6 + -1;
        puVar9 = puVar10;
      } while (lVar6 != 0);
      *puVar10 = *puVar11;
      ppcVar16 = &local_1e8;
      ppcVar15 = &local_1e0;
      uVar7 = ValidateFunctionTable
                        (iVar4,(longlong)local_1c8,(longlong *)&local_1f0,local_1d8,
                         (longlong *)ppcVar15,ppcVar16);
      iVar5 = (int)uVar7;
      if (iVar5 < 0) {
        uVar8 = 0xc2;
        goto LAB_180010793;
      }
      puVar11 = (undefined8 *)(_Dst + 6);
      iVar5 = (*local_1f0)(puVar11,param_2,param_4);
      if (iVar5 == -0x3fff5fff) {
        if (iVar4 != 2) goto LAB_180010739;
        if (((byte)param_4 & 0x28) == 8) {
          (*local_1f0)(puVar11,param_2,param_4 & 0xfffffff7);
          _Dst[2] = _Dst[2] | 8;
        }
      }
      else if (iVar4 != 2) {
LAB_180010739:
        if (iVar4 != 3) goto LAB_1800107b0;
        if (local_1e8 == (code *)0x0) {
          iVar5 = -0x3fffff1b;
          uVar8 = 0xfd;
        }
        else {
          ppcVar15 = (code **)&local_1f8;
          iVar5 = (*local_1e8)(*puVar11,L"PaddingSchemes",_Dst + 0x6e,local_1f8,ppcVar15,
                               (ulonglong)ppcVar16 & 0xffffffff00000000);
          if (-1 < iVar5) goto LAB_1800107b0;
          uVar8 = 9;
        }
        goto LAB_180010793;
      }
      if (local_1e8 == (code *)0x0) {
        iVar5 = -0x3fffff1b;
        uVar8 = 0xe8;
      }
      else {
        ppcVar15 = (code **)&local_1f4;
        iVar5 = (*local_1e8)(*puVar11,L"HashBlockLength",_Dst + 3,4,ppcVar15,
                             (ulonglong)ppcVar16 & 0xffffffff00000000);
        if (-1 < iVar5) {
LAB_1800107b0:
          if ((&PTR_u_KeyLength_18001e020)[uVar13 * 4] != (undefined *)0x0) {
            (*local_1e0)(*puVar11,(&PTR_u_KeyLength_18001e020)[uVar13 * 4],&DAT_18001e028 + lVar14,
                         *(undefined4 *)(&DAT_18001e02c + lVar14),
                         (ulonglong)ppcVar15 & 0xffffffff00000000);
          }
          *param_1 = _Dst;
          return iVar5;
        }
        uVar8 = 0xf4;
      }
LAB_180010793:
      DebugTraceError((char)iVar5,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c"
                      ,uVar8);
      SafeAllocaFreeToHeap(_Dst);
      return iVar5;
    }
    uVar12 = 0x8c;
  }
  else {
    uVar12 = 0x83;
  }
  iVar4 = -0x3ffffff8;
  uVar8 = 8;
LAB_1800104ed:
  DebugTraceError(uVar8,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar12);
  return iVar4;
}



===== _LoadInterface @ 180010810 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

ulonglong _LoadInterface(HMODULE param_1,uint *param_2,undefined8 param_3,HMODULE param_4)

{
  uint uVar1;
  FARPROC pFVar2;
  char *lpProcName;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined1 uVar5;
  int iVar6;
  undefined1 uVar7;
  
  uVar1 = *param_2;
  if (uVar1 < 0x10002) {
    if (uVar1 == 0x10001) {
      lpProcName = "GetKeyStorageInterface";
    }
    else {
      switch(uVar1) {
      case 1:
        lpProcName = "GetCipherInterface";
        break;
      case 2:
        lpProcName = "GetHashInterface";
        break;
      case 3:
        lpProcName = "GetAsymmetricEncryptionInterface";
        break;
      case 4:
        lpProcName = "GetSecretAgreementInterface";
        break;
      case 5:
        lpProcName = "GetSignatureInterface";
        break;
      case 6:
        lpProcName = "GetRngInterface";
        break;
      case 7:
        lpProcName = "GetKeyDerivationInterface";
        break;
      case 8:
        lpProcName = "GetKeyEncapsulationInterface";
        break;
      default:
        goto switchD_18001085e_default;
      }
    }
  }
  else if (uVar1 == 0x10002) {
    lpProcName = "GetSChannelInterface";
  }
  else {
    if (uVar1 != 0x10004) {
switchD_18001085e_default:
      uVar3 = 0xc00000bb;
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc00000bb;
      }
      if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
        return 0xc00000bb;
      }
      uVar7 = 0x68;
      uVar5 = 0xbb;
      goto LAB_180010918;
    }
    lpProcName = "GetKeyProtectionInterface";
  }
  pFVar2 = GetProcAddress(param_1,lpProcName);
  if (pFVar2 == (FARPROC)0x0) {
    uVar3 = 0xc0000139;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc0000139;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return 0xc0000139;
    }
    uVar7 = 0x73;
    uVar5 = 0x39;
    param_2 = (uint *)lpProcName;
LAB_180010918:
    WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,param_1,"sResult",uVar5,
                "onecore\\ds\\security\\cryptoapi\\ncrypt\\loader\\loader.c",uVar7);
    return uVar3;
  }
  uVar1 = *param_2;
  if (0x10001 < uVar1) {
    if (uVar1 == 0x10002) {
      param_1 = (HMODULE)0x0;
      uVar4 = (*pFVar2)(*(undefined8 *)(param_2 + 4),param_4);
      iVar6 = (int)uVar4;
      uVar3 = uVar4 & 0xffffffff;
      uVar4 = uVar4 & 0xffffffff;
      if (((iVar6 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        uVar5 = 0x48;
        goto LAB_180010d36;
      }
    }
    else {
      if (uVar1 != 0x10004) goto switchD_1800109d5_default;
      param_1 = (HMODULE)0x0;
      uVar4 = (*pFVar2)(*(undefined8 *)(param_2 + 4),param_4);
      iVar6 = (int)uVar4;
      uVar3 = uVar4 & 0xffffffff;
      uVar4 = uVar4 & 0xffffffff;
      if (((iVar6 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        uVar5 = 0x3c;
        goto LAB_180010d36;
      }
    }
    goto LAB_180010da2;
  }
  if (uVar1 == 0x10001) {
    param_1 = (HMODULE)0x0;
    uVar4 = (*pFVar2)(*(undefined8 *)(param_2 + 4),param_4);
    iVar6 = (int)uVar4;
    uVar3 = uVar4 & 0xffffffff;
    uVar4 = uVar4 & 0xffffffff;
    if (((iVar6 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      uVar5 = 0x30;
      goto LAB_180010d36;
    }
    goto LAB_180010da2;
  }
  switch(uVar1) {
  case 1:
    param_1 = param_4;
    uVar4 = (*pFVar2)(*(undefined8 *)(param_2 + 4),*(undefined8 *)(param_2 + 2),param_4,0);
    iVar6 = (int)uVar4;
    uVar3 = uVar4 & 0xffffffff;
    uVar4 = uVar4 & 0xffffffff;
    if (((-1 < iVar6) || ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control)) ||
       ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) break;
    uVar5 = 0xca;
LAB_180010d36:
    WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),WPP_GLOBAL_Control,param_1,"ntStatus",
                (char)iVar6,"onecore\\ds\\security\\cryptoapi\\ncrypt\\loader\\loader.c",uVar5);
    goto LAB_180010d4d;
  case 2:
    param_1 = param_4;
    uVar4 = (*pFVar2)(*(undefined8 *)(param_2 + 4),*(undefined8 *)(param_2 + 2),param_4,0);
    iVar6 = (int)uVar4;
    uVar3 = uVar4 & 0xffffffff;
    uVar4 = uVar4 & 0xffffffff;
    if (((iVar6 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      uVar5 = 0xd7;
      goto LAB_180010d36;
    }
    break;
  case 3:
    param_1 = param_4;
    uVar4 = (*pFVar2)(*(undefined8 *)(param_2 + 4),*(undefined8 *)(param_2 + 2),param_4,0);
    iVar6 = (int)uVar4;
    uVar3 = uVar4 & 0xffffffff;
    uVar4 = uVar4 & 0xffffffff;
    if (((iVar6 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      uVar5 = 0xe4;
      goto LAB_180010d36;
    }
    break;
  case 4:
    param_1 = param_4;
    uVar4 = (*pFVar2)(*(undefined8 *)(param_2 + 4),*(undefined8 *)(param_2 + 2),param_4,0);
    iVar6 = (int)uVar4;
    uVar3 = uVar4 & 0xffffffff;
    uVar4 = uVar4 & 0xffffffff;
    if (((iVar6 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      uVar5 = 0xf1;
      goto LAB_180010d36;
    }
    break;
  case 5:
    param_1 = param_4;
    uVar4 = (*pFVar2)(*(undefined8 *)(param_2 + 4),*(undefined8 *)(param_2 + 2),param_4,0);
    iVar6 = (int)uVar4;
    uVar3 = uVar4 & 0xffffffff;
    uVar4 = uVar4 & 0xffffffff;
    if (((iVar6 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      uVar5 = 0xfe;
      goto LAB_180010d36;
    }
    break;
  case 6:
    param_1 = (HMODULE)0x0;
    uVar4 = (*pFVar2)(*(undefined8 *)(param_2 + 4),param_4);
    iVar6 = (int)uVar4;
    uVar3 = uVar4 & 0xffffffff;
    uVar4 = uVar4 & 0xffffffff;
    if (((iVar6 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      uVar5 = 10;
      goto LAB_180010d36;
    }
    break;
  case 7:
    param_1 = param_4;
    uVar4 = (*pFVar2)(*(undefined8 *)(param_2 + 4),*(undefined8 *)(param_2 + 2),param_4,0);
    iVar6 = (int)uVar4;
    uVar3 = uVar4 & 0xffffffff;
    uVar4 = uVar4 & 0xffffffff;
    if (((iVar6 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      uVar5 = 0x17;
      goto LAB_180010d36;
    }
    break;
  case 8:
    param_1 = param_4;
    uVar4 = (*pFVar2)(*(undefined8 *)(param_2 + 4),*(undefined8 *)(param_2 + 2),param_4,0);
    iVar6 = (int)uVar4;
    uVar3 = uVar4 & 0xffffffff;
    uVar4 = uVar4 & 0xffffffff;
    if (((iVar6 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      uVar5 = 0x24;
      goto LAB_180010d36;
    }
    break;
  default:
switchD_1800109d5_default:
    uVar4 = 0xc00000bb;
    iVar6 = -0x3fffff45;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc00000bb;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) != 0) {
      uVar5 = 0x4e;
      iVar6 = -0x3fffff45;
      goto LAB_180010d36;
    }
    goto LAB_180010d4d;
  }
LAB_180010da2:
  uVar4 = uVar3;
  iVar6 = (int)uVar4;
  if (iVar6 < 0) {
LAB_180010d4d:
    uVar5 = (undefined1)iVar6;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return uVar4;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return uVar4;
    }
    uVar7 = 0x87;
    goto LAB_180010d60;
  }
  uVar1 = *param_2;
  uVar3 = 0;
  if (0x10001 < uVar1) {
    if (uVar1 == 0x10002) {
      if (**(short **)param_4 == 0) {
        uVar4 = 0xc00000bb;
        iVar6 = -0x3fffff45;
        uVar3 = 0xc00000bb;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
          WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),WPP_GLOBAL_Control,param_1,
                      "ntStatus",0xbb,"onecore\\ds\\security\\cryptoapi\\ncrypt\\loader\\loader.c",
                      0xa4);
          goto LAB_180010e33;
        }
      }
    }
    else {
      if (uVar1 != 0x10004) goto switchD_180010ddb_default;
      if (((**(short **)param_4 == 0) &&
          (uVar3 = 0xc00000bb, (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        uVar5 = 0x9a;
        goto LAB_180010e05;
      }
    }
    goto LAB_180010e29;
  }
  if (uVar1 == 0x10001) {
    if (((**(short **)param_4 == 0) &&
        (uVar3 = 0xc00000bb, (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      uVar5 = 0x90;
      goto LAB_180010e05;
    }
    goto LAB_180010e29;
  }
  switch(uVar1) {
  case 1:
    if (((**(short **)param_4 == 0) &&
        (uVar3 = 0xc00000bb, (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      uVar5 = 0x40;
LAB_180010e05:
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),WPP_GLOBAL_Control,param_1,"ntStatus",
                  0xbb,"onecore\\ds\\security\\cryptoapi\\ncrypt\\loader\\loader.c",uVar5);
      uVar3 = 0xc00000bb;
    }
    break;
  case 2:
    if (((**(short **)param_4 == 0) &&
        (uVar3 = 0xc00000bb, (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      uVar5 = 0x4a;
      goto LAB_180010e05;
    }
    break;
  case 3:
    if (((**(short **)param_4 == 0) &&
        (uVar3 = 0xc00000bb, (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      uVar5 = 0x54;
      goto LAB_180010e05;
    }
    break;
  case 4:
    if (((**(short **)param_4 == 0) &&
        (uVar3 = 0xc00000bb, (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      uVar5 = 0x5e;
      goto LAB_180010e05;
    }
    break;
  case 5:
    if (((**(short **)param_4 == 0) &&
        (uVar3 = 0xc00000bb, (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      uVar5 = 0x68;
      goto LAB_180010e05;
    }
    break;
  case 6:
    if (((**(short **)param_4 == 0) &&
        (uVar3 = 0xc00000bb, (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      uVar5 = 0x72;
      goto LAB_180010e05;
    }
    break;
  case 7:
    if (((**(short **)param_4 == 0) &&
        (uVar3 = 0xc00000bb, (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      uVar5 = 0x7c;
      goto LAB_180010e05;
    }
    break;
  case 8:
    if (((**(short **)param_4 == 0) &&
        (uVar3 = 0xc00000bb, (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      uVar5 = 0x86;
      goto LAB_180010e05;
    }
    break;
  default:
switchD_180010ddb_default:
    uVar4 = 0xc00000bb;
    iVar6 = -0x3fffff45;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc00000bb;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) != 0) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),WPP_GLOBAL_Control,param_1,"ntStatus",
                  0xbb,"onecore\\ds\\security\\cryptoapi\\ncrypt\\loader\\loader.c",0xaa);
    }
    goto LAB_180010e33;
  }
LAB_180010e29:
  uVar4 = uVar3;
  iVar6 = (int)uVar4;
  if (-1 < iVar6) {
    return uVar4;
  }
LAB_180010e33:
  uVar5 = (undefined1)iVar6;
  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
    return uVar4;
  }
  if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
    return uVar4;
  }
  uVar7 = 0x82;
LAB_180010d60:
  WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),WPP_GLOBAL_Control,param_1,"sResult",uVar5,
              "onecore\\ds\\security\\cryptoapi\\ncrypt\\loader\\loader.c",uVar7);
  return uVar4;
}



===== entry @ 180011140 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 entry(undefined8 param_1,int param_2,HMODULE *param_3)

{
  BOOL BVar1;
  DWORD DVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  char *pcVar5;
  HMODULE local_res8;
  undefined1 uVar6;
  
  local_res8 = (HMODULE)0x0;
  g_hInstance = param_1;
  if (param_2 == 1) {
    LdrDisableThreadCalloutsForDll();
    pcVar5 = (char *)0x1;
    uVar4 = param_1;
    _DllMainCRTStartupForGS2(param_1,1);
    SafeAllocaInitialize();
    DAT_180025bf0 = 0;
    WPP_REGISTRATION_GUIDS = &WPP_ThisDir_CTLGUID_CNGTraceControlGuid;
    WPP_GLOBAL_Control = &WPP_MAIN_CB;
    _WPP_MAIN_CB = 0;
    _DAT_180025bf8 = 1;
    WppInitUm();
    McGenEventRegister_EtwEventRegister();
    uVar3 = InitializeCNG(uVar4,pcVar5,(char *)param_3);
    if ((int)uVar3 == 0) {
      if ((WPP_GLOBAL_Control[0x1c] & 0x20) != 0) {
        uVar4 = 0x100;
        GetModuleFileNameW((HMODULE)0x0,(LPWSTR)&DAT_1800258a0,0x100);
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((WPP_GLOBAL_Control[0x1c] & 0x20) != 0)) {
          WPP_SF_qS(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),10,uVar4,param_1);
        }
      }
      param_3 = &local_res8;
      BVar1 = GetModuleHandleExW(5,(LPCWSTR)entry,param_3);
      if (BVar1 != 0) goto LAB_180011305;
      DVar2 = GetLastError();
      uVar3 = (ulonglong)DVar2;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        uVar6 = 0xd;
        pcVar5 = "GetLastError()";
        goto LAB_1800112b0;
      }
    }
    else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      uVar6 = 0xf6;
      pcVar5 = "Status";
LAB_1800112b0:
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar3 & 0xffffffff,param_3,pcVar5,
                  (char)uVar3,"onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\bcrypt\\init.c",
                  uVar6);
    }
    uVar4 = 0;
  }
  else {
    if (param_2 == 0) {
      if (((WPP_GLOBAL_Control[0x1c] & 0x20) != 0) &&
         ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) {
        WPP_SF_qS(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xb,param_3,param_1);
      }
      WppCleanupUm();
      McGenEventUnregister_EtwEventUnregister();
    }
LAB_180011305:
    uVar4 = 1;
  }
  return uVar4;
}



===== IoCopy_ProviderReg @ 180011324 =====

/* unsigned long __cdecl IoCopy_ProviderReg(struct _CRYPT_PROVIDER_REG * __ptr64,unsigned long *
   __ptr64,unsigned char * __ptr64) */

ulong __cdecl IoCopy_ProviderReg(_CRYPT_PROVIDER_REG *param_1,ulong *param_2,uchar *param_3)

{
  ulong uVar1;
  uchar *puVar2;
  ulonglong uVar3;
  uchar *puVar4;
  ulong local_res8 [2];
  ulong local_res10 [2];
  undefined8 local_res20;
  undefined8 local_38 [2];
  
  puVar4 = (uchar *)0x0;
  local_res8[0] = 0;
  local_res10[0] = 0;
  local_res20 = 0;
  uVar3 = 0x20;
  local_38[0] = 0;
  if (param_2 != (ulong *)0x0) {
    *param_2 = 0;
  }
  if (param_1 == (_CRYPT_PROVIDER_REG *)0x0) {
LAB_180011426:
    uVar1 = 0x57;
  }
  else {
    if (param_1->rgpszAliases == (PWSTR *)0x0) {
      if (param_1->cAliases != 0) goto LAB_180011426;
    }
    else {
      if (param_1->cAliases == 0) goto LAB_180011426;
      puVar4 = (uchar *)(-(ulonglong)(param_3 != (uchar *)0x0) & (ulonglong)(param_3 + 0x20));
      uVar1 = IoCopy_SzStringArray
                        ((ushort **)param_1->rgpszAliases,param_1->cAliases,local_res8,puVar4);
      if (uVar1 != 0) {
        return uVar1;
      }
      uVar3 = (ulonglong)(local_res8[0] + 0x20);
    }
    if (param_3 == (uchar *)0x0) {
      puVar2 = (uchar *)0x0;
    }
    else {
      puVar2 = param_3 + uVar3;
    }
    uVar1 = IoCopy_ImageRegs(param_1->pUM,param_1->pKM,
                             (uchar **)
                             (-(ulonglong)(param_3 != (uchar *)0x0) & (ulonglong)&local_res20),
                             (uchar **)(-(ulonglong)(param_3 != (uchar *)0x0) & (ulonglong)local_38)
                             ,local_res10,puVar2);
    if (uVar1 == 0) {
      if (param_3 != (uchar *)0x0) {
        *(uchar **)(param_3 + 8) = puVar4;
        *(ULONG *)param_3 = param_1->cAliases;
        *(undefined8 *)(param_3 + 0x10) = local_res20;
        *(undefined8 *)(param_3 + 0x18) = local_38[0];
      }
      if (param_2 != (ulong *)0x0) {
        *param_2 = (int)uVar3 + local_res10[0];
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}



===== WPP_SF_qSD @ 180011448 =====

void WPP_SF_qSD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               wchar_t *param_5,undefined1 param_6)

{
  longlong lVar1;
  undefined8 local_res20;
  
  if (param_5 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_5[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"NULL";
  }
  local_res20 = param_4;
  EtwTraceMessage(param_1,0x2b,&WPP_321c0d2313123f81ee86e6c36df24469_Traceguids,0x1d,&local_res20,8,
                  param_5,lVar1,&param_6,4,0);
  return;
}



===== CleanupSystemPreferredCache @ 1800114f0 =====

void CleanupSystemPreferredCache(void)

{
  if (DAT_180025b20 != (HANDLE)0x0) {
    UnregisterWaitEx(DAT_180025b20,(HANDLE)0xffffffffffffffff);
    DAT_180025b20 = (HANDLE)0x0;
  }
  if (DAT_180025ad0 != (BCRYPT_ALG_HANDLE)0x0) {
    BCryptCloseAlgorithmProvider(DAT_180025ad0,0);
    DAT_180025ad0 = (BCRYPT_ALG_HANDLE)0x0;
  }
  if (DAT_180025ac8 != (BCRYPT_ALG_HANDLE)0x0) {
    BCryptCloseAlgorithmProvider(DAT_180025ac8,0);
    DAT_180025ac8 = (BCRYPT_ALG_HANDLE)0x0;
  }
  if (DAT_180025ac4 != 0) {
    BcpUnregisterConfigChangeNotifyNoLogging(DAT_180025b10);
    DAT_180025b10 = (HANDLE)0x0;
    DAT_180025ac4 = 0;
  }
  if (g_pCachedRngRWLock != 0) {
    RtlDeleteResource();
    SafeAllocaFreeToHeap(g_pCachedRngRWLock);
    g_pCachedRngRWLock = 0;
  }
  if (DAT_180025b18 != 0) {
    RtlDeleteCriticalSection();
    SafeAllocaFreeToHeap(DAT_180025b18);
    DAT_180025b18 = 0;
  }
  return;
}



===== BCryptRegisterProvider @ 1800115e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long BCryptRegisterProvider(ushort *param_1,uint param_2,_CRYPT_PROVIDER_REG *param_3)

{
  ulong uVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  uchar *puVar5;
  undefined1 auStackY_1c8 [32];
  ulong local_180 [2];
  uint local_178;
  int local_170;
  uchar *local_168;
  ushort *local_160;
  _CRYPT_PROVIDER_REG *local_158;
  uchar local_148 [256];
  ulonglong local_48;
  
                    /* 0x115e0  49  BCryptRegisterProvider */
  local_48 = __security_cookie ^ (ulonglong)auStackY_1c8;
  lVar4 = 0;
  puVar5 = local_148;
  local_170 = 0;
  local_180[0] = 0;
  local_178 = param_2;
  local_168 = puVar5;
  local_160 = param_1;
  local_158 = param_3;
  iVar2 = BcpIsValidString(param_1);
  uVar3 = 0;
  if (iVar2 == 0) {
    uVar3 = 0x57;
  }
  if (uVar3 == 0) {
    if ((param_2 & 0xfffffffe) == 0) {
      iVar2 = BcpIsValidProviderReg(param_3);
      if (iVar2 == 0) {
        uVar3 = 0x57;
      }
      if (uVar3 == 0) {
        uVar3 = IoPack_Registration_ParamBlock(param_1,0,0,param_2,param_3,local_180,(uchar *)0x0);
        uVar1 = local_180[0];
        if (uVar3 == 0) {
          if (0x100 < local_180[0]) {
            puVar5 = (uchar *)BCryptAlloc((ulonglong)local_180[0]);
            local_168 = puVar5;
            if (puVar5 == (uchar *)0x0) {
              uVar3 = 8;
              goto LAB_18001178b;
            }
            local_170 = 1;
          }
          uVar3 = IoPack_Registration_ParamBlock(param_1,0,0,param_2,param_3,(ulong *)0x0,puVar5);
          if (uVar3 == 0) {
            lVar4 = IoCallKernelDriver(0,puVar5,uVar1,(uchar *)0x0,(ulong *)0x0);
            if (-1 < lVar4) goto LAB_180011798;
          }
        }
      }
    }
    else {
      uVar3 = 0x3ec;
    }
  }
LAB_18001178b:
  if (-1 < lVar4) {
    lVar4 = WinErrorToNtStatus(uVar3);
  }
LAB_180011798:
  if (local_170 != 0) {
    BCryptFree((longlong)puVar5);
  }
  return lVar4;
}



===== BcpIsValidString @ 1800117d4 =====

/* int __cdecl BcpIsValidString(unsigned short const * __ptr64) */

int __cdecl BcpIsValidString(ushort *param_1)

{
  ulong uVar1;
  uint uVar2;
  ulong local_res10 [6];
  
  local_res10[0] = 0;
  uVar1 = SzString_CchLength(param_1,local_res10,0xffff);
  if (uVar1 == 0) {
    uVar2 = (uint)(local_res10[0] != 0);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



===== _LogBCryptOpenProviderFailure @ 180011810 =====

void _LogBCryptOpenProviderFailure
               (undefined8 param_1,undefined8 param_2,undefined1 param_3,undefined1 param_4,
               undefined1 param_5)

{
  if ((Microsoft_Windows_Crypto_BCryptEnableBits & 1) != 0) {
    McTemplateU0zzqdq_USE_EtwEventWrite
              (param_1,param_2,(wchar_t *)param_1,(wchar_t *)param_2,param_3,param_4,param_5);
  }
  return;
}



===== WPP_SF_q @ 180011848 =====

void WPP_SF_q(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  EtwTraceMessage(param_1,0x2b,&WPP_e4386b12b8143f81186affdeca2b77e8_Traceguids,param_2,&local_res20
                  ,8,0);
  return;
}



===== MaskGeneration @ 180011890 =====

NTSTATUS MaskGeneration(BCRYPT_ALG_HANDLE param_1,uint param_2,PUCHAR param_3,PUCHAR param_4,
                       ULONG param_5,PUCHAR param_6,uint param_7)

{
  uint uVar1;
  NTSTATUS NVar2;
  PUCHAR pbHashObject;
  uint *puVar3;
  undefined1 *puVar4;
  longlong lVar5;
  undefined1 uVar6;
  uint uVar7;
  uint uVar8;
  ulonglong uVar9;
  undefined4 local_res10;
  ULONG local_res18;
  PUCHAR local_res20;
  undefined1 uVar10;
  BCRYPT_HASH_HANDLE local_58 [3];
  
  uVar7 = param_7;
  local_res18 = (ULONG)param_3;
  local_58[0] = (BCRYPT_HASH_HANDLE)0x0;
  uVar1 = ((param_2 - 1) + param_7) / param_2;
  uVar9 = (ulonglong)param_3 & 0xffffffff;
  if (uVar1 < 0x100) {
    param_7 = 0;
  }
  local_res20 = param_4;
  pbHashObject = (PUCHAR)BCryptAlloc((ulonglong)(param_2 + local_res18));
  if (pbHashObject == (PUCHAR)0x0) {
    NVar2 = -0x3fffffe9;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      uVar10 = 0x35;
      uVar6 = 0x17;
LAB_180011931:
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),WPP_GLOBAL_Control,param_3,"Status",
                  uVar6,"onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\format.c",uVar10);
    }
  }
  else {
    for (uVar8 = 0; local_res10 = uVar8, uVar8 < uVar1; uVar8 = uVar8 + 1) {
      param_3 = pbHashObject;
      NVar2 = BCryptCreateHash(param_1,local_58,pbHashObject,local_res18,(PUCHAR)0x0,0,0);
      if (NVar2 < 0) {
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) goto LAB_180011a69;
        uVar10 = 0x46;
        uVar6 = (undefined1)NVar2;
        goto LAB_180011931;
      }
      NVar2 = BCryptHashData(local_58[0],local_res20,param_5,0);
      if (NVar2 < 0) {
        uVar6 = 0x51;
LAB_180011aa6:
        DebugTraceError((char)NVar2,"Status",
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\format.c",uVar6);
        goto LAB_180011a69;
      }
      if (uVar1 < 0x100) {
        param_7 = CONCAT13((char)uVar8,(undefined3)param_7);
      }
      else {
        puVar3 = &param_7;
        lVar5 = 4;
        puVar4 = (undefined1 *)((longlong)&local_res10 + 3);
        do {
          uVar6 = *puVar4;
          puVar4 = puVar4 + -1;
          *(undefined1 *)puVar3 = uVar6;
          puVar3 = (uint *)((longlong)puVar3 + 1);
          lVar5 = lVar5 + -1;
        } while (lVar5 != 0);
      }
      NVar2 = BCryptHashData(local_58[0],(PUCHAR)&param_7,4,0);
      if (NVar2 < 0) {
        uVar6 = 0x6a;
        goto LAB_180011aa6;
      }
      if (uVar7 < param_2) {
        NVar2 = BCryptFinishHash(local_58[0],pbHashObject + uVar9,param_2,0);
        if (NVar2 < 0) {
          uVar6 = 0x87;
          goto LAB_180011aa6;
        }
        memcpy(param_6,pbHashObject + uVar9,(ulonglong)uVar7);
        BCryptDestroyHash(local_58[0]);
        local_58[0] = (BCRYPT_HASH_HANDLE)0x0;
        break;
      }
      NVar2 = BCryptFinishHash(local_58[0],param_6,param_2,0);
      if (NVar2 < 0) {
        uVar6 = 0x77;
        goto LAB_180011aa6;
      }
      uVar7 = uVar7 - param_2;
      param_6 = param_6 + param_2;
      BCryptDestroyHash(local_58[0]);
      local_58[0] = (BCRYPT_HASH_HANDLE)0x0;
    }
    NVar2 = 0;
  }
LAB_180011a69:
  if (local_58[0] != (BCRYPT_HASH_HANDLE)0x0) {
    BCryptDestroyHash(local_58[0]);
  }
  if (pbHashObject != (PUCHAR)0x0) {
    SafeAllocaFreeToHeap(pbHashObject);
  }
  return NVar2;
}



===== VerifyPKCS1SigningFormat @ 180011afc =====

ulonglong VerifyPKCS1SigningFormat
                    (uint param_1,longlong param_2,void *param_3,uint param_4,void *param_5,
                    uint param_6,int param_7)

{
  int iVar1;
  undefined2 *_Dst;
  ulonglong uVar2;
  undefined1 uVar3;
  void *pvVar4;
  ulonglong uVar5;
  undefined1 uVar6;
  uint uVar7;
  ulonglong _Size;
  
  _Size = (ulonglong)param_6;
  uVar5 = 0xc00000e5;
  _Dst = (undefined2 *)BCryptAlloc(_Size);
  if (_Dst == (undefined2 *)0x0) {
    DebugTraceError(0x17,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\format.c",0xb8)
    ;
    return 0xc0000017;
  }
  if (param_7 == 0) {
    memset(_Dst,0,_Size);
    uVar2 = ApplyPKCS1SigningFormat((void *)0x0,0,param_3,param_4,_Dst,param_6,0);
    uVar5 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) {
      uVar6 = 0xec;
      uVar3 = (undefined1)uVar2;
    }
    else {
      iVar1 = memcmp(_Dst,param_5,_Size);
      if (iVar1 == 0) {
LAB_180011c95:
        uVar5 = 0;
        goto LAB_180011cbc;
      }
      uVar5 = 0xc000a000;
      uVar6 = 0xf8;
      uVar3 = 0;
    }
LAB_180011cb0:
    DebugTraceError(uVar3,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\format.c",
                    uVar6);
  }
  else {
    for (uVar7 = 0; uVar7 < param_1; uVar7 = uVar7 + 1) {
      memset(_Dst,0,_Size);
      uVar2 = ApplyPKCS1SigningFormat
                        (*(void **)(param_2 + 8 + (ulonglong)uVar7 * 0x10),
                         *(uint *)(param_2 + (ulonglong)uVar7 * 0x10),param_3,param_4,_Dst,param_6,1
                        );
      uVar5 = uVar2 & 0xffffffff;
      if ((int)uVar2 < 0) {
        uVar6 = 0xce;
        uVar3 = (undefined1)uVar2;
        goto LAB_180011cb0;
      }
      pvVar4 = param_5;
      uVar2 = _Size;
      iVar1 = memcmp(_Dst,param_5,_Size);
      if (iVar1 == 0) goto LAB_180011c95;
      uVar5 = 0xc000a000;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pvVar4,uVar2,"Status",0,
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\format.c",0xdb);
      }
    }
  }
LAB_180011cbc:
  SafeAllocaFreeToHeap(_Dst);
  return uVar5;
}



===== BCryptEnumContextFunctions @ 180011cf0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

NTSTATUS __stdcall
BCryptEnumContextFunctions
          (ULONG dwTable,LPCWSTR pszContext,ULONG dwInterface,ULONG *pcbBuffer,
          PCRYPT_CONTEXT_FUNCTIONS *ppBuffer)

{
  uint uVar1;
  PCRYPT_CONTEXT_FUNCTIONS p_Var2;
  ulong uVar3;
  int iVar4;
  ulong uVar5;
  int iVar6;
  uchar *puVar7;
  ULONG UVar8;
  ULONG *pUVar9;
  undefined1 auStackY_1d8 [32];
  ulong local_168;
  int local_164 [3];
  uchar local_158 [256];
  ulonglong local_58;
  
                    /* 0x11cf0  24  BCryptEnumContextFunctions */
  local_58 = __security_cookie ^ (ulonglong)auStackY_1d8;
  puVar7 = local_158;
  iVar6 = 0;
  local_168 = 0;
  local_164[0] = 0;
  pUVar9 = pcbBuffer;
  UVar8 = dwInterface;
  iVar4 = ValidateTableId(dwTable,(ulong)pszContext);
  if (((iVar4 == 0) || (iVar4 = ValidateInterfaceId(UVar8,0), iVar4 == 0)) ||
     (pUVar9 == (ULONG *)0x0)) {
    uVar5 = 0x57;
LAB_180011f08:
    if (local_164[0] != 0) {
      BCryptFree((longlong)*ppBuffer);
      *ppBuffer = (PCRYPT_CONTEXT_FUNCTIONS)0x0;
    }
    if (iVar6 < 0) goto LAB_180011ddd;
  }
  else {
    uVar5 = IoPack_Configuration_ParamBlock
                      (dwTable,(ushort *)pszContext,UVar8,(ushort *)0x0,(ushort *)0x0,(ushort *)0x0,
                       0,(_CRYPT_CONTEXT_CONFIG *)0x0,(_CRYPT_CONTEXT_FUNCTION_CONFIG *)0x0,0,
                       (uchar *)0x0,(void *)0x0,&local_168,(uchar *)0x0);
    uVar3 = local_168;
    if (uVar5 == 0) {
      if ((local_168 < 0x101) ||
         (puVar7 = (uchar *)BCryptAlloc((ulonglong)local_168), puVar7 != (uchar *)0x0)) {
        uVar5 = IoPack_Configuration_ParamBlock
                          (dwTable,(ushort *)pszContext,dwInterface,(ushort *)0x0,(ushort *)0x0,
                           (ushort *)0x0,0,(_CRYPT_CONTEXT_CONFIG *)0x0,
                           (_CRYPT_CONTEXT_FUNCTION_CONFIG *)0x0,0,(uchar *)0x0,(void *)0x0,
                           (ulong *)0x0,puVar7);
        if (uVar5 == 0) {
          pUVar9 = pcbBuffer;
          iVar6 = IoCallKernelDriverQueryLoop
                            (0x10202,puVar7,uVar3,(uchar **)ppBuffer,pcbBuffer,local_164);
          if (-1 < iVar6) {
            p_Var2 = *ppBuffer;
            uVar1 = *pcbBuffer;
            if (p_Var2 == (PCRYPT_CONTEXT_FUNCTIONS)0x0) goto LAB_180011ddd;
            if ((p_Var2 + 1 < p_Var2) ||
               ((PCRYPT_CONTEXT_FUNCTIONS)((longlong)&p_Var2->cFunctions + (ulonglong)uVar1) <
                p_Var2 + 1)) {
              uVar5 = 0x54f;
            }
            else {
              uVar5 = IoUnpack_SG_SzStringArray
                                ((ushort ***)&p_Var2->rgpszFunctions,p_Var2->cFunctions,
                                 (uchar *)p_Var2,uVar1,(uchar *)pUVar9);
              if ((uVar5 == 0) ||
                 (uVar5 = IoUnpack_SG_SzStringArray
                                    ((ushort ***)&p_Var2->rgpszFunctions,p_Var2->cFunctions,
                                     (uchar *)p_Var2,uVar1,(uchar *)pUVar9), uVar5 == 0))
              goto LAB_180011ddd;
            }
          }
          goto LAB_180011f08;
        }
      }
      else {
        uVar5 = 8;
      }
    }
  }
  iVar6 = WinErrorToNtStatus(uVar5);
LAB_180011ddd:
  if ((puVar7 != (uchar *)0x0) && (puVar7 != local_158)) {
    BCryptFree((longlong)puVar7);
  }
  if (ppBuffer == (PCRYPT_CONTEXT_FUNCTIONS *)0x0) {
    if (iVar6 == -0x3fffffdd) {
      iVar6 = 0;
    }
  }
  return iVar6;
}



===== CngSetAuditingInterface @ 180011f30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

DWORD CngSetAuditingInterface(void)

{
  BOOL BVar1;
  DWORD DVar2;
  HANDLE ProcessHandle;
  undefined8 uVar3;
  undefined1 uVar4;
  undefined1 auStackY_88 [32];
  BOOL local_48 [2];
  HANDLE local_40;
  DWORD local_38;
  LONG LStack_34;
  _PRIVILEGE_SET local_30;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_40 = (HANDLE)0x0;
  LStack_34 = 0;
  local_48[0] = 0;
  local_30.PrivilegeCount = 0;
  local_30.Control = 0;
  local_30.Privilege[0].Luid.LowPart = 0;
  local_30.Privilege[0].Luid.HighPart = 0;
  local_30.Privilege[0].Attributes = 0;
  local_38 = 7;
  ProcessHandle = GetCurrentProcess();
  uVar3 = 8;
  BVar1 = OpenProcessToken(ProcessHandle,8,&local_40);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    if ((int)DVar2 < 1) {
      DVar2 = GetLastError();
    }
    else {
      DVar2 = GetLastError();
      DVar2 = DVar2 & 0xffff | 0xc0070000;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar3,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\audit.c","Status",(char)DVar2,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\audit.c",0x56);
    }
  }
  else {
    local_30.Privilege[0].Luid.HighPart = LStack_34;
    local_30.Privilege[0].Luid.LowPart = local_38;
    local_30.Privilege[0].Attributes = 0;
    local_30.PrivilegeCount = 1;
    local_30.Control = 0;
    BVar1 = PrivilegeCheck(local_40,&local_30,local_48);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
      if ((int)DVar2 < 1) {
        DVar2 = GetLastError();
      }
      else {
        DVar2 = GetLastError();
        DVar2 = DVar2 & 0xffff | 0xc0070000;
      }
      uVar4 = 100;
    }
    else {
      if (local_48[0] != 0) {
        DVar2 = 0;
        goto LAB_1800120bc;
      }
      DVar2 = 0xc0000061;
      uVar4 = 0x6b;
    }
    DebugTraceError((char)DVar2,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\audit.c"
                    ,uVar4);
  }
LAB_1800120bc:
  if (local_40 != (HANDLE)0x0) {
    CloseHandle(local_40);
  }
  return DVar2;
}



===== BCryptSetContextFunctionProperty @ 180012100 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

NTSTATUS __stdcall
BCryptSetContextFunctionProperty
          (ULONG dwTable,LPCWSTR pszContext,ULONG dwInterface,LPCWSTR pszFunction,
          LPCWSTR pszProperty,ULONG cbValue,PUCHAR pbValue)

{
  ulong uVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  uchar *puVar5;
  LPCWSTR pWVar6;
  undefined1 auStackY_2d8 [32];
  ulong local_268 [2];
  PUCHAR local_260;
  uchar local_258 [512];
  ulonglong local_58;
  
                    /* 0x12100  55  BCryptSetContextFunctionProperty */
  local_58 = __security_cookie ^ (ulonglong)auStackY_2d8;
  puVar5 = local_258;
  local_260 = pbValue;
  local_268[0] = 0;
  pWVar6 = pszFunction;
  iVar2 = ValidateTableId(dwTable,(ulong)pszContext);
  if (iVar2 == 0) {
LAB_18001227e:
    uVar3 = 0x57;
  }
  else {
    iVar2 = ValidateInterfaceId(dwInterface,0);
    if ((((iVar2 == 0) || (pWVar6 == (LPCWSTR)0x0)) || (*pWVar6 == L'\0')) ||
       ((pszProperty == (LPCWSTR)0x0 || (*pszProperty == L'\0')))) goto LAB_18001227e;
    uVar3 = IoPack_Configuration_ParamBlock
                      (dwTable,(ushort *)pszContext,dwInterface,(ushort *)pWVar6,(ushort *)0x0,
                       (ushort *)pszProperty,0,(_CRYPT_CONTEXT_CONFIG *)0x0,
                       (_CRYPT_CONTEXT_FUNCTION_CONFIG *)0x0,cbValue,pbValue,(void *)0x0,local_268,
                       (uchar *)0x0);
    uVar1 = local_268[0];
    if (uVar3 == 0) {
      if (0x200 < local_268[0]) {
        puVar5 = (uchar *)BCryptAlloc((ulonglong)local_268[0]);
        if (puVar5 == (uchar *)0x0) {
          uVar3 = 8;
          goto LAB_180012283;
        }
      }
      uVar3 = IoPack_Configuration_ParamBlock
                        (dwTable,(ushort *)pszContext,dwInterface,(ushort *)pszFunction,
                         (ushort *)0x0,(ushort *)pszProperty,0,(_CRYPT_CONTEXT_CONFIG *)0x0,
                         (_CRYPT_CONTEXT_FUNCTION_CONFIG *)0x0,cbValue,local_260,(void *)0x0,
                         (ulong *)0x0,puVar5);
      if (uVar3 == 0) {
        lVar4 = IoCallKernelDriver(0x10400,puVar5,uVar1,(uchar *)0x0,(ulong *)0x0);
        goto LAB_18001228a;
      }
    }
  }
LAB_180012283:
  lVar4 = WinErrorToNtStatus(uVar3);
LAB_18001228a:
  if ((puVar5 != (uchar *)0x0) && (puVar5 != local_258)) {
    BCryptFree((longlong)puVar5);
  }
  return lVar4;
}



===== BCryptAddContextFunctionProvider @ 1800122e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long BCryptAddContextFunctionProvider
               (ulong param_1,ushort *param_2,ulong param_3,ushort *param_4,ushort *param_5,
               ulong param_6)

{
  ulong uVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  uchar *puVar5;
  ushort *puVar6;
  undefined1 auStackY_258 [32];
  ulong local_1e8 [4];
  uchar local_1d8 [384];
  ulonglong local_58;
  
                    /* 0x122e0  2  BCryptAddContextFunctionProvider */
  local_58 = __security_cookie ^ (ulonglong)auStackY_258;
  puVar5 = local_1d8;
  local_1e8[0] = 0;
  puVar6 = param_4;
  uVar3 = param_3;
  iVar2 = ValidateTableId(param_1,(ulong)param_2);
  if (((((iVar2 == 0) || (iVar2 = ValidateInterfaceId(uVar3,0), iVar2 == 0)) ||
       (puVar6 == (ushort *)0x0)) || ((*puVar6 == 0 || (param_5 == (ushort *)0x0)))) ||
     (*param_5 == 0)) {
    uVar3 = 0x57;
  }
  else {
    uVar3 = IoPack_Configuration_ParamBlock
                      (param_1,param_2,uVar3,puVar6,param_5,(ushort *)0x0,param_6,
                       (_CRYPT_CONTEXT_CONFIG *)0x0,(_CRYPT_CONTEXT_FUNCTION_CONFIG *)0x0,0,
                       (uchar *)0x0,(void *)0x0,local_1e8,(uchar *)0x0);
    uVar1 = local_1e8[0];
    if (uVar3 == 0) {
      if ((local_1e8[0] < 0x181) ||
         (puVar5 = (uchar *)BCryptAlloc((ulonglong)local_1e8[0]), puVar5 != (uchar *)0x0)) {
        uVar3 = IoPack_Configuration_ParamBlock
                          (param_1,param_2,param_3,param_4,param_5,(ushort *)0x0,param_6,
                           (_CRYPT_CONTEXT_CONFIG *)0x0,(_CRYPT_CONTEXT_FUNCTION_CONFIG *)0x0,0,
                           (uchar *)0x0,(void *)0x0,(ulong *)0x0,puVar5);
        if (uVar3 == 0) {
          lVar4 = IoCallKernelDriver(0x10300,puVar5,uVar1,(uchar *)0x0,(ulong *)0x0);
          goto LAB_180012456;
        }
      }
      else {
        uVar3 = 8;
      }
    }
  }
  lVar4 = WinErrorToNtStatus(uVar3);
LAB_180012456:
  if ((puVar5 != (uchar *)0x0) && (puVar5 != local_1d8)) {
    BCryptFree((longlong)puVar5);
  }
  return lVar4;
}



===== BCryptAddContextFunction @ 1800124a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

NTSTATUS __stdcall
BCryptAddContextFunction
          (ULONG dwTable,LPCWSTR pszContext,ULONG dwInterface,LPCWSTR pszFunction,ULONG dwPosition)

{
  ulong uVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  uchar *puVar5;
  ULONG UVar6;
  LPCWSTR pWVar7;
  undefined1 auStackY_218 [32];
  ulong local_1a8 [4];
  uchar local_198 [320];
  ulonglong local_58;
  
                    /* 0x124a0  1  BCryptAddContextFunction */
  local_58 = __security_cookie ^ (ulonglong)auStackY_218;
  puVar5 = local_198;
  local_1a8[0] = 0;
  pWVar7 = pszFunction;
  UVar6 = dwInterface;
  iVar2 = ValidateTableId(dwTable,(ulong)pszContext);
  if (iVar2 == 0) {
LAB_1800125e7:
    uVar3 = 0x57;
  }
  else {
    iVar2 = ValidateInterfaceId(UVar6,0);
    if (((iVar2 == 0) || (pWVar7 == (LPCWSTR)0x0)) || (*pWVar7 == L'\0')) goto LAB_1800125e7;
    uVar3 = IoPack_Configuration_ParamBlock
                      (dwTable,(ushort *)pszContext,UVar6,(ushort *)pWVar7,(ushort *)0x0,
                       (ushort *)0x0,dwPosition,(_CRYPT_CONTEXT_CONFIG *)0x0,
                       (_CRYPT_CONTEXT_FUNCTION_CONFIG *)0x0,0,(uchar *)0x0,(void *)0x0,local_1a8,
                       (uchar *)0x0);
    uVar1 = local_1a8[0];
    if (uVar3 == 0) {
      if (0x140 < local_1a8[0]) {
        puVar5 = (uchar *)BCryptAlloc((ulonglong)local_1a8[0]);
        if (puVar5 == (uchar *)0x0) {
          uVar3 = 8;
          goto LAB_1800125ec;
        }
      }
      uVar3 = IoPack_Configuration_ParamBlock
                        (dwTable,(ushort *)pszContext,dwInterface,(ushort *)pszFunction,
                         (ushort *)0x0,(ushort *)0x0,dwPosition,(_CRYPT_CONTEXT_CONFIG *)0x0,
                         (_CRYPT_CONTEXT_FUNCTION_CONFIG *)0x0,0,(uchar *)0x0,(void *)0x0,
                         (ulong *)0x0,puVar5);
      if (uVar3 == 0) {
        lVar4 = IoCallKernelDriver(0x10200,puVar5,uVar1,(uchar *)0x0,(ulong *)0x0);
        goto LAB_1800125f3;
      }
    }
  }
LAB_1800125ec:
  lVar4 = WinErrorToNtStatus(uVar3);
LAB_1800125f3:
  if ((puVar5 != (uchar *)0x0) && (puVar5 != local_198)) {
    BCryptFree((longlong)puVar5);
  }
  return lVar4;
}



===== BCryptCreateContext @ 180012640 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

NTSTATUS __stdcall
BCryptCreateContext(ULONG dwTable,LPCWSTR pszContext,PCRYPT_CONTEXT_CONFIG pConfig)

{
  ulong uVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  uchar *puVar5;
  ULONG UVar6;
  LPCWSTR pWVar7;
  PCRYPT_CONTEXT_CONFIG p_Var8;
  undefined1 auStackY_1b8 [32];
  ulong local_148 [4];
  uchar local_138 [256];
  ulonglong local_38;
  
                    /* 0x12640  6  BCryptCreateContext */
  local_38 = __security_cookie ^ (ulonglong)auStackY_1b8;
  puVar5 = local_138;
  local_148[0] = 0;
  pWVar7 = pszContext;
  p_Var8 = pConfig;
  UVar6 = dwTable;
  iVar2 = ValidateTableId(dwTable,(ulong)pszContext);
  if (((iVar2 == 0) || (pWVar7 == (LPCWSTR)0x0)) || (*pWVar7 == L'\0')) {
    uVar3 = 0x57;
  }
  else {
    uVar3 = IoPack_Configuration_ParamBlock
                      (UVar6,(ushort *)pWVar7,0,(ushort *)0x0,(ushort *)0x0,(ushort *)0x0,0,p_Var8,
                       (_CRYPT_CONTEXT_FUNCTION_CONFIG *)0x0,0,(uchar *)0x0,(void *)0x0,local_148,
                       (uchar *)0x0);
    uVar1 = local_148[0];
    if (uVar3 == 0) {
      if (0x100 < local_148[0]) {
        puVar5 = (uchar *)BCryptAlloc((ulonglong)local_148[0]);
        if (puVar5 == (uchar *)0x0) {
          uVar3 = 8;
          goto LAB_18001276c;
        }
      }
      uVar3 = IoPack_Configuration_ParamBlock
                        (dwTable,(ushort *)pszContext,0,(ushort *)0x0,(ushort *)0x0,(ushort *)0x0,0,
                         pConfig,(_CRYPT_CONTEXT_FUNCTION_CONFIG *)0x0,0,(uchar *)0x0,(void *)0x0,
                         (ulong *)0x0,puVar5);
      if (uVar3 == 0) {
        lVar4 = IoCallKernelDriver(0x10000,puVar5,uVar1,(uchar *)0x0,(ulong *)0x0);
        goto LAB_180012773;
      }
    }
  }
LAB_18001276c:
  lVar4 = WinErrorToNtStatus(uVar3);
LAB_180012773:
  if ((puVar5 != (uchar *)0x0) && (puVar5 != local_138)) {
    BCryptFree((longlong)puVar5);
  }
  return lVar4;
}



===== WPP_SF_qqqDqD @ 1800127c0 =====

void WPP_SF_qqqDqD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                  undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                  undefined1 param_9)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  EtwTraceMessage(param_1,0x2b,&WPP_e4386b12b8143f81186affdeca2b77e8_Traceguids,0x2a,&local_res20,8,
                  &param_5,8,&param_6,8,&param_7,4,&param_8,8,&param_9,4,0);
  return;
}



===== _DllMainCRTStartupForGS2 @ 180012858 =====

undefined8 _DllMainCRTStartupForGS2(undefined8 param_1,int param_2)

{
  if (param_2 == 1) {
    __security_init_cookie();
  }
  return 1;
}



===== __report_gsfailure @ 180012880 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  DWORD64 ControlPc;
  PRUNTIME_FUNCTION FunctionEntry;
  DWORD64 unaff_retaddr;
  uintptr_t local_res8 [4];
  ulonglong local_38 [2];
  PVOID local_28;
  undefined8 uStack_20;
  undefined8 uStack_18;
  
  local_38[1] = 0;
  local_28 = (PVOID)0x0;
  local_38[0] = 0;
  local_res8[0] = _StackCookie;
  RtlCaptureContext(&DAT_1800253a0);
  ControlPc = DAT_180025498;
  FunctionEntry = RtlLookupFunctionEntry(DAT_180025498,local_38,(PUNWIND_HISTORY_TABLE)0x0);
  if (FunctionEntry == (PRUNTIME_FUNCTION)0x0) {
    _DAT_180025438 = local_res8;
    DAT_180025498 = unaff_retaddr;
  }
  else {
    RtlVirtualUnwind(0,local_38[0],ControlPc,FunctionEntry,(PCONTEXT)&DAT_1800253a0,&local_28,
                     local_38 + 1,(PKNONVOLATILE_CONTEXT_POINTERS)0x0);
  }
  _DAT_180025310 = DAT_180025498;
  _DAT_180025420 = local_res8[0];
  _DAT_180025300 = 0xc0000409;
  _DAT_180025304 = 1;
  _DAT_180025318 = 1;
  DAT_180025320 = 2;
  uStack_20 = __security_cookie;
  uStack_18 = __security_cookie_complement;
  RtlUnhandledExceptionFilter(&PTR_DAT_18001e000);
  NtTerminateProcess(0xffffffffffffffff,0xc0000409);
  return;
}



===== __security_init_cookie @ 1800129fc =====

void __cdecl __security_init_cookie(void)

{
  if ((__security_cookie == 0) || (__security_cookie == 0x2b992ddfa232)) {
    __security_init_cookie_ex(&__security_cookie);
  }
  __security_cookie_complement = ~__security_cookie;
  return;
}



===== __security_init_cookie_ex @ 180012a48 =====

void __security_init_cookie_ex(ulonglong *param_1)

{
  ulonglong uVar1;
  undefined8 in_RAX;
  
  uVar1 = rdtsc();
  *param_1 = ((CONCAT44((int)((ulonglong)in_RAX >> 0x20),(int)uVar1) | uVar1 & 0xffffffff00000000)
              >> 4 ^ (ulonglong)param_1) & 0xffffffffffff;
  if ((*param_1 == 0) || (*param_1 == 0x2b992ddfa232)) {
    *param_1 = 0x2b992ddfa233;
  }
  return;
}



===== NtTerminateProcess @ 180012aac =====

void NtTerminateProcess(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180012aac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  NtTerminateProcess();
  return;
}



===== RtlCaptureContext @ 180012ab8 =====

void RtlCaptureContext(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180012ab8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlCaptureContext();
  return;
}



===== RtlLookupFunctionEntry @ 180012ac4 =====

PRUNTIME_FUNCTION __stdcall
RtlLookupFunctionEntry(DWORD64 ControlPc,PDWORD64 ImageBase,PUNWIND_HISTORY_TABLE HistoryTable)

{
  PRUNTIME_FUNCTION p_Var1;
  
                    /* WARNING: Could not recover jumptable at 0x000180012ac4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  p_Var1 = RtlLookupFunctionEntry(ControlPc,ImageBase,HistoryTable);
  return p_Var1;
}



===== RtlVirtualUnwind @ 180012ad0 =====

PEXCEPTION_ROUTINE __stdcall
RtlVirtualUnwind(DWORD HandlerType,DWORD64 ImageBase,DWORD64 ControlPc,
                PRUNTIME_FUNCTION FunctionEntry,PCONTEXT ContextRecord,PVOID *HandlerData,
                PDWORD64 EstablisherFrame,PKNONVOLATILE_CONTEXT_POINTERS ContextPointers)

{
  PEXCEPTION_ROUTINE puVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180012ad0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  puVar1 = RtlVirtualUnwind(HandlerType,ImageBase,ControlPc,FunctionEntry,ContextRecord,HandlerData,
                            EstablisherFrame,ContextPointers);
  return puVar1;
}



===== RtlUnhandledExceptionFilter @ 180012adc =====

void RtlUnhandledExceptionFilter(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180012adc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlUnhandledExceptionFilter();
  return;
}



===== __tailMerge_bcryptprimitives_dll @ 180012ae2 =====

void __tailMerge_bcryptprimitives_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_XMM0_Qa;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_1800229c8,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x000180012b59. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(in_XMM0_Qa,param_2,param_3,param_4);
  return;
}



===== DelayLoad_MSCryptConvertRsaPrivateBlobToFullRsaBlob @ 180012b61 =====

void DelayLoad_MSCryptConvertRsaPrivateBlobToFullRsaBlob
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_bcryptprimitives_dll(param_1,param_2,param_3,param_4);
  return;
}



===== __imp_load_GetHashInterface @ 180012b80 =====

void __imp_load_GetHashInterface
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_bcryptprimitives_dll(param_1,param_2,param_3,param_4);
  return;
}



===== __imp_load_GetKeyEncapsulationInterface @ 180012ba0 =====

void __imp_load_GetKeyEncapsulationInterface
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_bcryptprimitives_dll(param_1,param_2,param_3,param_4);
  return;
}



===== __imp_load_GetCipherInterface @ 180012bc0 =====

void __imp_load_GetCipherInterface
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_bcryptprimitives_dll(param_1,param_2,param_3,param_4);
  return;
}



===== __imp_load_GetSignatureInterface @ 180012be0 =====

void __imp_load_GetSignatureInterface
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_bcryptprimitives_dll(param_1,param_2,param_3,param_4);
  return;
}



===== __imp_load_GetKeyDerivationInterface @ 180012c00 =====

void __imp_load_GetKeyDerivationInterface
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_bcryptprimitives_dll(param_1,param_2,param_3,param_4);
  return;
}



===== __imp_load_GetSecretAgreementInterface @ 180012c20 =====

void __imp_load_GetSecretAgreementInterface
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_bcryptprimitives_dll(param_1,param_2,param_3,param_4);
  return;
}



===== __imp_load_GetAsymmetricEncryptionInterface @ 180012c40 =====

void __imp_load_GetAsymmetricEncryptionInterface
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_bcryptprimitives_dll(param_1,param_2,param_3,param_4);
  return;
}



===== __imp_load_GetRngInterface @ 180012c60 =====

void __imp_load_GetRngInterface
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_bcryptprimitives_dll(param_1,param_2,param_3,param_4);
  return;
}



===== SymCryptWipeAsm @ 180012c90 =====

void SymCryptWipeAsm(undefined8 *param_1,ulonglong param_2)

{
  ulonglong uVar1;
  uint uVar2;
  ulonglong uVar3;
  
  if (param_2 < 0x10) {
    uVar2 = (uint)param_2;
    if (7 < uVar2) {
      *param_1 = 0;
      *(undefined8 *)((longlong)param_1 + (param_2 - 8)) = 0;
      return;
    }
    if (3 < uVar2) {
      *(undefined4 *)param_1 = 0;
      *(undefined4 *)((longlong)param_1 + (param_2 - 4)) = 0;
      return;
    }
    if (1 < uVar2) {
      *(undefined2 *)param_1 = 0;
      *(undefined2 *)((longlong)param_1 + (param_2 - 2)) = 0;
      return;
    }
    if (uVar2 != 0) {
      *(undefined1 *)param_1 = 0;
    }
    return;
  }
  if (((ulonglong)param_1 & 0xf) != 0) {
    *param_1 = 0;
    param_1[1] = 0;
    uVar1 = (ulonglong)(-(int)param_1 & 0xf);
    param_1 = (undefined8 *)((longlong)param_1 + uVar1);
    param_2 = param_2 - uVar1;
    if (param_2 < 0x10) {
      *(undefined8 *)((longlong)param_1 + (param_2 - 0x10)) = 0;
      *(undefined8 *)((longlong)param_1 + (param_2 - 8)) = 0;
      return;
    }
  }
  *param_1 = 0;
  param_1[1] = 0;
  if ((param_2 & 0x10) != 0) {
    param_1 = param_1 + 2;
  }
  while (uVar1 = param_2 - 0x20, 0x1f < param_2) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1 = param_1 + 4;
    param_2 = uVar1;
  }
  uVar3 = (ulonglong)((uint)uVar1 & 0xf);
  if ((uVar1 & 0xf) == 0) {
    return;
  }
  *(undefined8 *)((longlong)param_1 + (uVar3 - 0x10)) = 0;
  *(undefined8 *)((longlong)param_1 + (uVar3 - 8)) = 0;
  return;
}



===== __C_specific_handler @ 180012d47 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180012d47. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== AllocateMultiObjectBuffer @ 180012d54 =====

NTSTATUS AllocateMultiObjectBuffer
                   (BCRYPT_HANDLE param_1,int param_2,longlong *param_3,uint *param_4)

{
  NTSTATUS NVar1;
  longlong lVar2;
  uint uVar3;
  undefined1 uVar4;
  ULONG local_18 [2];
  int local_10 [2];
  
  local_10[0] = 0;
  local_10[1] = 0;
  local_18[0] = 0;
  NVar1 = BCryptGetProperty(param_1,L"MultiObjectLength",(PUCHAR)local_10,8,local_18,0);
  if (NVar1 < 0) {
    uVar4 = 0x12;
  }
  else {
    uVar3 = local_10[1] * param_2 + local_10[0];
    lVar2 = BCryptAlloc((ulonglong)uVar3);
    if (lVar2 != 0) {
      *param_4 = uVar3;
      *param_3 = lVar2;
      return 0;
    }
    NVar1 = -0x3fffffe9;
    uVar4 = 0x21;
  }
  DebugTraceError((char)NVar1,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",
                  uVar4);
  return NVar1;
}



===== ApplyEncryptionPadding @ 180012e10 =====

NTSTATUS ApplyEncryptionPadding
                   (ulonglong param_1,undefined8 *param_2,BCRYPT_ALG_HANDLE param_3,uint param_4,
                   byte *param_5,uint param_6)

{
  uint uVar1;
  NTSTATUS NVar2;
  undefined1 uVar3;
  BCRYPT_ALG_HANDLE hObject;
  undefined1 uVar4;
  ULONG local_res8 [2];
  undefined4 uVar5;
  undefined4 in_stack_ffffffffffffffa4;
  uint local_38;
  uint local_34;
  BCRYPT_ALG_HANDLE local_30;
  
  local_30 = (BCRYPT_ALG_HANDLE)0x0;
  local_38 = 0;
  local_34 = 0;
  hObject = (BCRYPT_ALG_HANDLE)0x0;
  local_res8[0] = 0;
  if ((param_1 & 2) == 0) {
    if ((param_1 & 4) == 0) {
      NVar2 = -0x3ffffff3;
      uVar4 = 0xa2;
      uVar3 = 0xd;
    }
    else {
      if ((param_2 == (undefined8 *)0x0) || ((wchar_t *)*param_2 == (wchar_t *)0x0)) {
        NVar2 = -0x3ffffff3;
        uVar4 = 0x69;
        uVar3 = 0xd;
        goto LAB_180012f20;
      }
      NVar2 = CachedOpenAlgorithmProvider((longlong *)&local_30,(wchar_t *)*param_2,param_3);
      hObject = local_30;
      if (NVar2 < 0) {
        DebugTraceError((char)NVar2,"Status",
                        "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",0x74);
        hObject = local_30;
        goto LAB_18001307a;
      }
      NVar2 = BCryptGetProperty(local_30,L"ObjectLength",(PUCHAR)&local_38,4,local_res8,0);
      if (NVar2 < 0) {
        uVar4 = 0x80;
      }
      else {
        uVar5 = 0;
        NVar2 = BCryptGetProperty(hObject,L"HashDigestLength",(PUCHAR)&local_34,4,local_res8,0);
        if (NVar2 < 0) {
          uVar4 = 0x8c;
        }
        else {
          NVar2 = ApplyOAEPPaddingSeeded
                            (hObject,local_34,local_38,(PUCHAR)param_2[1],*(ULONG *)(param_2 + 2),
                             (BCRYPT_HASH_HANDLE)CONCAT44(in_stack_ffffffffffffffa4,uVar5),param_3,
                             param_4,param_5,param_6);
          if (-1 < NVar2) goto LAB_180012eff;
          uVar4 = 0x9b;
        }
      }
      uVar3 = (undefined1)NVar2;
    }
    DebugTraceError(uVar3,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar4);
LAB_18001307a:
    if (hObject == (BCRYPT_ALG_HANDLE)0x0) {
      return NVar2;
    }
    CachedCloseAlgorithmProvider(hObject);
    return NVar2;
  }
  uVar1 = param_4 + 3;
  if (uVar1 < param_4) {
    uVar4 = 0x38;
  }
  else {
    if (uVar1 <= param_6) {
      local_res8[0] = param_6 - uVar1;
      param_5[0] = 0;
      param_5[1] = 2;
      NVar2 = BCryptGenRandom((BCRYPT_ALG_HANDLE)0x0,param_5 + 2,local_res8[0],2);
      if (NVar2 < 0) {
        uVar4 = 0x4a;
LAB_180012e9e:
        uVar3 = (undefined1)NVar2;
        goto LAB_180012f20;
      }
      for (uVar1 = 0; uVar1 < local_res8[0]; uVar1 = uVar1 + 1) {
        while (param_5[uVar1 + 2] == 0) {
          NVar2 = BCryptGenRandom((BCRYPT_ALG_HANDLE)0x0,param_5 + (ulonglong)uVar1 + 2,1,2);
          if (NVar2 < 0) {
            uVar4 = 0x58;
            goto LAB_180012e9e;
          }
        }
      }
      param_5[local_res8[0] + 2] = 0;
      memcpy(param_5 + (ulonglong)local_res8[0] + 3,param_3,(ulonglong)param_4);
LAB_180012eff:
      NVar2 = 0;
      goto LAB_18001307a;
    }
    uVar4 = 0x3d;
  }
  local_res8[0] = 0xffffffff;
  NVar2 = -0x7ff8fdea;
  uVar3 = 0x16;
LAB_180012f20:
  DebugTraceError(uVar3,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar4);
  return NVar2;
}



===== BCryptCreateMultiHash @ 1800130b0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

int BCryptCreateMultiHash
              (uint *param_1,undefined8 *param_2,int param_3,longlong param_4,uint param_5,
              undefined8 param_6,undefined4 param_7,undefined4 param_8)

{
  code *pcVar1;
  NTSTATUS NVar2;
  uint *puVar3;
  undefined1 uVar4;
  longlong lVar5;
  int iVar6;
  longlong lVar7;
  uint uVar8;
  undefined1 uVar9;
  ulonglong uVar10;
  undefined4 *puVar11;
  uint local_28 [2];
  longlong local_20;
  
                    /* 0x130b0  8  BCryptCreateMultiHash */
  lVar7 = 0;
  local_28[0] = 0;
  local_20 = 0;
  puVar3 = ValidateBaseAlgHandle(param_1);
  if (puVar3 == (uint *)0x0) {
    iVar6 = -0x3ffffff8;
    uVar9 = 0x46;
    uVar4 = 8;
LAB_1800130fa:
    DebugTraceError(uVar4,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar9);
    return iVar6;
  }
  if (param_3 == 0) {
    iVar6 = -0x3ffffff3;
    uVar9 = 0x4d;
    uVar4 = 0xd;
    goto LAB_1800130fa;
  }
  if (param_4 == 0) {
    if (param_5 != 0) {
LAB_18001316c:
      if (param_4 != 0) goto LAB_180013175;
      goto LAB_18001325c;
    }
    NVar2 = AllocateMultiObjectBuffer(param_1,param_3,&local_20,local_28);
    lVar7 = local_20;
    if (-1 < NVar2) {
      param_4 = local_20;
      param_5 = local_28[0];
      goto LAB_18001316c;
    }
    uVar4 = 0x59;
  }
  else {
LAB_180013175:
    if (param_2 == (undefined8 *)0x0) {
LAB_18001325c:
      NVar2 = -0x3ffffff3;
      uVar4 = 0x69;
    }
    else if (param_5 < 0x46) {
      NVar2 = -0x3fffffdd;
      uVar4 = 0x70;
    }
    else {
      puVar11 = (undefined4 *)(param_4 + 0xfU & 0xfffffffffffffff0);
      uVar8 = ((uint)(param_4 + 0xfU) & 0xfffffff0) - (int)param_4;
      if ((puVar3[9] == 2) && (1 < (ushort)puVar3[0xc])) {
        pcVar1 = *(code **)(puVar3 + 0x20);
        *puVar11 = 0x28;
        lVar5 = (ulonglong)uVar8 + 0x28 + param_4;
        puVar11[1] = 0x55555553;
        *(uint **)(puVar11 + 2) = puVar3;
        *(longlong *)(puVar11 + 8) = lVar7;
        uVar10 = lVar5 + 0xfU & 0xfffffffffffffff0;
        NVar2 = (*pcVar1)(*(undefined8 *)(puVar3 + 6),puVar11 + 4,param_3,uVar10,
                          (((int)lVar5 - (int)uVar10) - uVar8) + -0x28 + param_5,param_6,param_7,
                          param_8);
        if (-1 < NVar2) {
          *param_2 = puVar11;
          NVar2 = 0;
          goto LAB_180013290;
        }
        uVar4 = 0x9b;
      }
      else {
        NVar2 = -0x3fffff45;
        uVar4 = 0x7e;
      }
    }
  }
  DebugTraceError((char)NVar2,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",
                  uVar4);
  if (lVar7 != 0) {
    SafeAllocaFreeToHeap(lVar7);
  }
  if (NVar2 < 0) {
    return NVar2;
  }
LAB_180013290:
  LOCK();
  puVar3[4] = puVar3[4] + 1;
  UNLOCK();
  return NVar2;
}



===== BCryptDecapsulate @ 1800132c0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

int BCryptDecapsulate(uint *param_1,undefined8 param_2,ulonglong param_3,undefined8 param_4,
                     undefined4 param_5,undefined8 param_6,undefined4 param_7)

{
  int iVar1;
  uint *puVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  
                    /* 0x132c0  9  BCryptDecapsulate */
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_qqDqDqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,param_3,param_1,(char)param_2,
                   (char)param_3,(char)param_4,(char)param_5,(char)param_6,(char)param_7);
  }
  puVar2 = ValidateBaseKeyHandle(param_1);
  if (puVar2 == (uint *)0x0) {
    iVar1 = -0x3ffffff8;
    uVar4 = 0xb9;
    uVar3 = 8;
  }
  else if (*(int *)(*(longlong *)(puVar2 + 2) + 0x24) == 8) {
    iVar1 = (**(code **)(*(longlong *)(puVar2 + 2) + 0x70))
                      (*(undefined8 *)(puVar2 + 4),param_2,param_3 & 0xffffffff,param_4,param_5,
                       param_6,param_7);
    if (-1 < iVar1) {
      return 0;
    }
    uVar4 = 0xd1;
    uVar3 = (undefined1)iVar1;
  }
  else {
    iVar1 = -0x3fffff45;
    uVar4 = 0xc2;
    uVar3 = 0xbb;
  }
  DebugTraceError(uVar3,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar4);
  return iVar1;
}



===== BCryptEncapsulate @ 1800133f0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

int BCryptEncapsulate(uint *param_1,undefined8 param_2,ulonglong param_3,undefined8 param_4,
                     undefined8 param_5,undefined4 param_6,undefined8 param_7,undefined4 param_8)

{
  int iVar1;
  uint *puVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  
                    /* 0x133f0  20  BCryptEncapsulate */
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_qqDqqDqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,param_3,param_1,(char)param_2
                    ,(char)param_3,(char)param_4,(char)param_5,(char)param_6,(char)param_7,
                    (char)param_8);
  }
  puVar2 = ValidateBaseKeyHandle(param_1);
  if (puVar2 == (uint *)0x0) {
    iVar1 = -0x3ffffff8;
    uVar4 = 0x7d;
    uVar3 = 8;
  }
  else if (*(int *)(*(longlong *)(puVar2 + 2) + 0x24) == 8) {
    iVar1 = (**(code **)(*(longlong *)(puVar2 + 2) + 0x68))
                      (*(undefined8 *)(puVar2 + 4),param_2,param_3 & 0xffffffff,param_4,param_5,
                       param_6,param_7,param_8);
    if (-1 < iVar1) {
      return 0;
    }
    uVar4 = 0x96;
    uVar3 = (undefined1)iVar1;
  }
  else {
    iVar1 = -0x3fffff45;
    uVar4 = 0x86;
    uVar3 = 0xbb;
  }
  DebugTraceError(uVar3,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar4);
  return iVar1;
}



===== BCryptEnumProviders @ 180013530 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

NTSTATUS __stdcall
BCryptEnumProviders(LPCWSTR pszAlgId,ULONG *pImplCount,BCRYPT_PROVIDER_NAME **ppImplList,
                   ULONG dwFlags)

{
  void *_Src;
  NTSTATUS NVar1;
  uint uVar2;
  undefined8 uVar3;
  longlong lVar4;
  BCRYPT_PROVIDER_NAME *pBVar5;
  longlong lVar6;
  ulonglong uVar7;
  longlong *plVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  uint *puVar11;
  ulonglong uVar12;
  undefined1 uVar13;
  int iVar14;
  LPWSTR _Dst;
  uint uVar15;
  ulonglong uVar16;
  undefined1 auStackY_298 [32];
  uint local_258 [2];
  uint *local_250;
  uint local_248 [128];
  ulonglong local_48;
  
                    /* 0x13530  26  BCryptEnumProviders */
  local_48 = __security_cookie ^ (ulonglong)local_258;
  puVar11 = local_248;
  local_258[0] = 0x200;
  uVar16 = 0;
  local_250 = puVar11;
  iVar14 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_SqqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pImplCount,ppImplList,pszAlgId,
                (char)pImplCount,(char)ppImplList,(char)dwFlags);
  }
  puVar10 = auStackY_298;
  if ((((pszAlgId == (LPCWSTR)0x0) || (*pszAlgId == L'\0')) || (pImplCount == (ULONG *)0x0)) ||
     ((ppImplList == (BCRYPT_PROVIDER_NAME **)0x0 || (dwFlags != 0)))) {
    NVar1 = -0x3ffffff3;
    uVar13 = 0xc6;
    puVar10 = auStackY_298;
  }
  else {
    *pImplCount = 0;
    *ppImplList = (BCRYPT_PROVIDER_NAME *)0x0;
    do {
      *(uint ***)(puVar10 + 0x38) = &local_250;
      *(uint **)(puVar10 + 0x30) = local_258;
      *(undefined4 *)(puVar10 + 0x28) = 2;
      *(undefined4 *)(puVar10 + 0x20) = 1;
      *(undefined8 *)(puVar10 + -8) = 0x18001361a;
      NVar1 = BCryptResolveProviders
                        ((LPCWSTR)0x0,0,pszAlgId,(LPCWSTR)0x0,*(ULONG *)(puVar10 + 0x20),
                         *(ULONG *)(puVar10 + 0x28),*(ULONG **)(puVar10 + 0x30),
                         *(PCRYPT_PROVIDER_REFS **)(puVar10 + 0x38));
      puVar11 = local_250;
      if (NVar1 != -0x3fffffdd) {
        if (-1 < NVar1) {
          uVar2 = *local_250;
          if (uVar2 != 0) {
            plVar8 = *(longlong **)(local_250 + 2);
            uVar12 = (ulonglong)uVar2;
            do {
              lVar4 = -1;
              do {
                lVar4 = lVar4 + 1;
              } while (*(short *)(*(longlong *)(*plVar8 + 0x10) + lVar4 * 2) != 0);
              plVar8 = plVar8 + 1;
              iVar14 = iVar14 + (int)lVar4 * 2 + 2;
              uVar12 = uVar12 - 1;
            } while (uVar12 != 0);
          }
          *(undefined8 *)(puVar10 + -8) = 0x180013751;
          pBVar5 = (BCRYPT_PROVIDER_NAME *)BCryptAlloc((ulonglong)(uVar2 * 8 + iVar14));
          if (pBVar5 != (BCRYPT_PROVIDER_NAME *)0x0) {
            _Dst = (LPWSTR)((longlong)&pBVar5->pszProviderName + (ulonglong)(uVar2 * 8));
            uVar2 = 0;
            if (*puVar11 != 0) {
              do {
                lVar4 = -1;
                do {
                  lVar6 = lVar4;
                  lVar4 = lVar6 + 1;
                } while (*(short *)(*(longlong *)
                                     (*(longlong *)(*(longlong *)(puVar11 + 2) + uVar16 * 8) + 0x10)
                                   + lVar4 * 2) != 0);
                pBVar5[uVar16].pszProviderName = _Dst;
                uVar12 = (ulonglong)((int)lVar6 + 2);
                _Src = *(void **)(*(longlong *)(*(longlong *)(puVar11 + 2) + uVar16 * 8) + 0x10);
                *(undefined8 *)(puVar10 + -8) = 0x1800137bb;
                memcpy(_Dst,_Src,uVar12 * 2);
                uVar2 = *puVar11;
                _Dst = _Dst + uVar12;
                uVar15 = (int)uVar16 + 1;
                uVar16 = (ulonglong)uVar15;
              } while (uVar15 < uVar2);
            }
            *pImplCount = uVar2;
            NVar1 = 0;
            *ppImplList = pBVar5;
            goto LAB_180013801;
          }
          NVar1 = -0x3fffffe9;
          uVar13 = 0x18;
          goto LAB_1800137ee;
        }
        goto LAB_180013700;
      }
      if (((local_250 != local_248) && (local_250 != (uint *)0x0)) && (local_250[-2] == 0x70616548))
      {
        *(undefined8 *)(puVar10 + -8) = 0x180013651;
        (*g_pfnFree)();
      }
      uVar12 = (ulonglong)local_258[0];
      puVar11 = (uint *)0x0;
      puVar9 = puVar10;
      if (((uVar12 == 0) || (g_ulMaxStackAllocSize < uVar12)) ||
         (uVar7 = g_ulAdditionalProbeSize + 8 + uVar12, uVar7 < uVar12)) {
LAB_1800136bd:
        puVar10 = puVar9;
        if (uVar12 <= uVar12 + 8) {
          *(undefined8 *)(puVar9 + -8) = 0x1800136d2;
          puVar11 = (uint *)(*g_pfnAllocate)();
          if (puVar11 != (uint *)0x0) {
            *puVar11 = 0x70616548;
            puVar11 = puVar11 + 2;
          }
        }
      }
      else {
        *(undefined8 *)(puVar10 + -8) = 0x18001367d;
        uVar3 = VerifyStackAvailable(uVar7);
        if ((int)uVar3 == 0) goto LAB_1800136bd;
        uVar7 = uVar12 + 0x17;
        if (uVar7 <= uVar12 + 8) {
          uVar7 = 0xffffffffffffff0;
        }
        *(undefined8 *)(puVar10 + -8) = 0x1800136a4;
        lVar4 = -(uVar7 & 0xfffffffffffffff0);
        puVar11 = (uint *)0x0;
        puVar9 = puVar10 + lVar4;
        if ((undefined4 *)(puVar10 + lVar4 + 0x40) == (undefined4 *)0x0) goto LAB_1800136bd;
        *(undefined4 *)(puVar10 + lVar4 + 0x40) = 0x6b637453;
        puVar11 = (uint *)(puVar10 + lVar4 + 0x48);
        puVar9 = puVar10 + lVar4;
        puVar10 = puVar10 + lVar4;
        if (puVar11 == (uint *)0x0) goto LAB_1800136bd;
      }
      local_250 = puVar11;
    } while (puVar11 != (uint *)0x0);
    NVar1 = -0x3fffffe9;
LAB_180013700:
    uVar13 = 0xff;
    puVar11 = local_250;
  }
LAB_1800137ee:
  *(undefined8 *)(puVar10 + -8) = 0x180013801;
  DebugTraceError((char)NVar1,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",
                  uVar13);
LAB_180013801:
  if (((puVar11 != (uint *)0x0) && (puVar11 != local_248)) && (puVar11[-2] == 0x70616548)) {
    *(undefined8 *)(puVar10 + -8) = 0x180013827;
    (*g_pfnFree)();
  }
  *(undefined8 *)(puVar10 + -8) = 0x180013838;
  return NVar1;
}



===== BCryptProcessMultiOperations @ 180013860 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

undefined4 BCryptProcessMultiOperations(uint *param_1,undefined8 param_2,longlong param_3)

{
  undefined4 uVar1;
  uint *puVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  
                    /* 0x13860  43  BCryptProcessMultiOperations */
  puVar2 = ValidateBaseHashHandle(param_1);
  if ((puVar2 == (uint *)0x0) || (*(ushort *)(*(longlong *)(puVar2 + 2) + 0x30) < 2)) {
    uVar1 = 0xc0000008;
    uVar4 = 0xce;
    uVar3 = 8;
  }
  else {
    if (param_3 != 0) {
      uVar1 = (**(code **)(*(longlong *)(puVar2 + 2) + 0x88))(*(undefined8 *)(puVar2 + 4));
      return uVar1;
    }
    uVar1 = 0xc000000d;
    uVar4 = 0xd5;
    uVar3 = 0xd;
  }
  DebugTraceError(uVar3,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar4);
  return uVar1;
}



===== BCryptSetAuditingInterface @ 1800138f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

DWORD BCryptSetAuditingInterface(void)

{
  BOOL BVar1;
  DWORD DVar2;
  HANDLE ProcessHandle;
  undefined8 uVar3;
  undefined1 uVar4;
  undefined1 auStackY_88 [32];
  BOOL aBStack_48 [2];
  HANDLE pvStack_40;
  DWORD DStack_38;
  LONG LStack_34;
  _PRIVILEGE_SET _Stack_30;
  ulonglong uStack_18;
  
  uStack_18 = __security_cookie ^ (ulonglong)auStackY_88;
  pvStack_40 = (HANDLE)0x0;
  LStack_34 = 0;
  aBStack_48[0] = 0;
  _Stack_30.PrivilegeCount = 0;
  _Stack_30.Control = 0;
  _Stack_30.Privilege[0].Luid.LowPart = 0;
  _Stack_30.Privilege[0].Luid.HighPart = 0;
  _Stack_30.Privilege[0].Attributes = 0;
  DStack_38 = 7;
  ProcessHandle = GetCurrentProcess();
  uVar3 = 8;
  BVar1 = OpenProcessToken(ProcessHandle,8,&pvStack_40);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    if ((int)DVar2 < 1) {
      DVar2 = GetLastError();
    }
    else {
      DVar2 = GetLastError();
      DVar2 = DVar2 & 0xffff | 0xc0070000;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_sDsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar3,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\audit.c","Status",(char)DVar2,
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\audit.c",0x56);
    }
  }
  else {
    _Stack_30.Privilege[0].Luid.HighPart = LStack_34;
    _Stack_30.Privilege[0].Luid.LowPart = DStack_38;
    _Stack_30.Privilege[0].Attributes = 0;
    _Stack_30.PrivilegeCount = 1;
    _Stack_30.Control = 0;
    BVar1 = PrivilegeCheck(pvStack_40,&_Stack_30,aBStack_48);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
      if ((int)DVar2 < 1) {
        DVar2 = GetLastError();
      }
      else {
        DVar2 = GetLastError();
        DVar2 = DVar2 & 0xffff | 0xc0070000;
      }
      uVar4 = 100;
    }
    else {
      if (aBStack_48[0] != 0) {
        DVar2 = 0;
        goto LAB_1800120bc;
      }
      DVar2 = 0xc0000061;
      uVar4 = 0x6b;
    }
    DebugTraceError((char)DVar2,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\audit.c"
                    ,uVar4);
  }
LAB_1800120bc:
  if (pvStack_40 != (HANDLE)0x0) {
    CloseHandle(pvStack_40);
  }
  return DVar2;
}



===== CheckEncryptionPadding @ 1800138fc =====

uint CheckEncryptionPadding
               (ulonglong param_1,longlong *param_2,ulonglong *param_3,uint param_4,uint param_5,
               void *param_6,uint param_7,uint *param_8)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  BCRYPT_ALG_HANDLE hObject;
  ulonglong uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  ULONG local_res20 [2];
  uint local_38;
  uint local_34;
  BCRYPT_ALG_HANDLE local_30;
  
  uVar5 = 0;
  hObject = (BCRYPT_ALG_HANDLE)0x0;
  local_30 = (BCRYPT_ALG_HANDLE)0x0;
  local_38 = 0;
  local_34 = 0;
  local_res20[0] = 0;
  if (param_5 < param_4) {
    uVar6 = 0xc6;
LAB_18001393b:
    DebugTraceError(0xd,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar6);
    return 0xc000000d;
  }
  if ((param_1 & 2) != 0) {
    local_30 = (BCRYPT_ALG_HANDLE)0x0;
    uVar3 = SymCryptRsaPkcs1RemoveEncryptionPadding
                      (param_3,(ulonglong)param_4,(ulonglong)param_5,(longlong)param_6,
                       (ulonglong)param_7,(ulonglong *)&local_30);
    uVar4 = 0xc000000d;
    do {
      puVar1 = (uint *)((longlong)&symmErrorsMap + uVar5);
      puVar2 = (uint *)((longlong)&DAT_18001fc1c + uVar5);
      uVar5 = uVar5 + 8;
      uVar4 = uVar4 ^ ~(uint)(-(ulonglong)(*puVar1 ^ uVar3) >> 0x20) & (uVar4 ^ *puVar2);
    } while (uVar5 < 0x18);
    *param_8 = (uint)local_30;
    return uVar4;
  }
  if ((param_1 & 4) == 0) {
    uVar3 = 0xc000000d;
    uVar7 = 0x1e;
    uVar6 = 0xd;
  }
  else {
    if ((param_2 == (longlong *)0x0) || (*param_2 == 0)) {
      uVar6 = 0xe4;
      goto LAB_18001393b;
    }
    uVar3 = CachedOpenAlgorithmProvider((longlong *)&local_30,(wchar_t *)*param_2,param_3);
    hObject = local_30;
    if ((int)uVar3 < 0) {
      DebugTraceError((char)uVar3,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c"
                      ,0xef);
      hObject = local_30;
      goto LAB_180013b10;
    }
    uVar3 = BCryptGetProperty(local_30,L"ObjectLength",(PUCHAR)&local_38,4,local_res20,0);
    if ((int)uVar3 < 0) {
      uVar7 = 0xfb;
    }
    else {
      uVar3 = BCryptGetProperty(hObject,L"HashDigestLength",(PUCHAR)&local_34,4,local_res20,0);
      if ((int)uVar3 < 0) {
        uVar7 = 7;
      }
      else {
        uVar3 = CheckOAEPPadding(hObject,local_34,local_38,(PUCHAR)param_2[1],
                                 *(ULONG *)(param_2 + 2),(byte *)param_3,param_4,param_6,param_7,
                                 param_8);
        if (-1 < (int)uVar3) goto LAB_180013b10;
        uVar7 = 0x17;
      }
    }
    uVar6 = (undefined1)uVar3;
  }
  DebugTraceError(uVar6,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\base.c",uVar7);
LAB_180013b10:
  if (hObject != (BCRYPT_ALG_HANDLE)0x0) {
    CachedCloseAlgorithmProvider(hObject);
  }
  return uVar3;
}



===== GetAlgorithmClass @ 180013b40 =====

void GetAlgorithmClass(longlong param_1,uint *param_2)

{
  short sVar1;
  short sVar2;
  short *psVar3;
  uint uVar4;
  uint uVar5;
  longlong lVar6;
  
  uVar4 = 0;
  do {
    uVar5 = 0x35;
    if (0x34 < uVar4) {
LAB_180013b91:
      *param_2 = uVar5;
      return;
    }
    psVar3 = (short *)(&AlgorithmClassPropertyTable)[(ulonglong)uVar4 * 4];
    lVar6 = param_1 - (longlong)psVar3;
    do {
      sVar1 = *psVar3;
      sVar2 = *(short *)((longlong)psVar3 + lVar6);
      if (sVar1 != sVar2) break;
      psVar3 = psVar3 + 1;
    } while (sVar2 != 0);
    if (sVar1 == sVar2) {
      uVar5 = uVar4;
      goto LAB_180013b91;
    }
    uVar4 = uVar4 + 1;
  } while( true );
}



===== McGenEventWrite_USE_EtwEventWrite @ 180013ba4 =====

void McGenEventWrite_USE_EtwEventWrite(void)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined8 *in_stack_00000028;
  
  puVar1 = DAT_180025018;
  uVar2 = 0;
  if (DAT_180025018 == (ushort *)0x0) {
    *in_stack_00000028 = 0;
    uVar3 = 0;
  }
  else {
    *in_stack_00000028 = DAT_180025018;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(in_stack_00000028 + 1) = uVar3;
  *(undefined4 *)((longlong)in_stack_00000028 + 0xc) = uVar2;
                    /* WARNING: Could not recover jumptable at 0x000180013be5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EtwEventWrite(ETW_LOG_BCRYPT_PROVIDER_Context,&ETW_LOG_BCRYPT_OPEN_PROVIDER_FAILED,6);
  return;
}



===== McTemplateU0zzqdq_USE_EtwEventWrite @ 180013bf8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0zzqdq_USE_EtwEventWrite
               (undefined8 param_1,undefined8 param_2,wchar_t *param_3,wchar_t *param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 auStack_a8 [32];
  undefined1 *local_88;
  undefined1 local_78 [16];
  wchar_t *local_68;
  int local_60;
  undefined4 local_5c;
  wchar_t *local_58;
  int local_50;
  undefined4 local_4c;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_a8;
  lVar1 = -1;
  local_50 = 10;
  if (param_3 == (wchar_t *)0x0) {
    local_60 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_3[lVar2] != L'\0');
    local_60 = (int)lVar2 * 2 + 2;
  }
  local_5c = 0;
  if (param_3 == (wchar_t *)0x0) {
    param_3 = L"NULL";
  }
  if (param_4 != (wchar_t *)0x0) {
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != L'\0');
    local_50 = (int)lVar1 * 2 + 2;
  }
  local_48 = &param_5;
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"NULL";
  }
  local_38 = &param_6;
  local_28 = &param_7;
  local_88 = local_78;
  local_4c = 0;
  local_40 = 4;
  local_30 = 4;
  local_20 = 4;
  local_68 = param_3;
  local_58 = param_4;
  McGenEventWrite_USE_EtwEventWrite();
  return;
}



===== WPP_SF_DqqD @ 180013cd8 =====

void WPP_SF_DqqD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  EtwTraceMessage(param_1,0x2b,&WPP_e4386b12b8143f81186affdeca2b77e8_Traceguids,0xf,local_res20,4,
                  &param_5,8,&param_6,8,&param_7,4,0);
  return;
}



===== WPP_SF_SSD @ 180013d4c =====

void WPP_SF_SSD(undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4,
               wchar_t *param_5,undefined1 param_6)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar1 = -1;
  lVar3 = 10;
  if (param_5 == (wchar_t *)0x0) {
    lVar2 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_5[lVar2] != L'\0');
    lVar2 = lVar2 * 2 + 2;
  }
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"NULL";
  }
  if (param_4 != (wchar_t *)0x0) {
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != L'\0');
    lVar3 = lVar1 * 2 + 2;
  }
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"NULL";
  }
  EtwTraceMessage(param_1,0x2b,&WPP_e4386b12b8143f81186affdeca2b77e8_Traceguids,0xc,param_4,lVar3,
                  param_5,lVar2,&param_6,4,0);
  return;
}



===== WPP_SF_SqqD @ 180013e10 =====

void WPP_SF_SqqD(undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  longlong lVar1;
  
  if (param_4 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"NULL";
  }
  EtwTraceMessage(param_1,0x2b,&WPP_e4386b12b8143f81186affdeca2b77e8_Traceguids,0x10,param_4,lVar1,
                  &param_5,8,&param_6,8,&param_7,4,0);
  return;
}



===== WPP_SF_qD @ 180013ec0 =====

void WPP_SF_qD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  EtwTraceMessage(param_1,0x2b,&WPP_e4386b12b8143f81186affdeca2b77e8_Traceguids,param_2,&local_res20
                  ,8,&param_5,4,0);
  return;
}



===== WPP_SF_qSqdD @ 180013f18 =====

void WPP_SF_qSqdD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 wchar_t *param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  longlong lVar1;
  undefined8 local_res20;
  
  if (param_5 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_5[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"NULL";
  }
  local_res20 = param_4;
  EtwTraceMessage(param_1,0x2b,&WPP_e4386b12b8143f81186affdeca2b77e8_Traceguids,0x13,&local_res20,8,
                  param_5,lVar1,&param_6,8,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_SF_qSqdqD @ 180013ff0 =====

void WPP_SF_qSqdqD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                  wchar_t *param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                  undefined1 param_9)

{
  longlong lVar1;
  undefined8 local_res20;
  
  if (param_5 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_5[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"NULL";
  }
  local_res20 = param_4;
  EtwTraceMessage(param_1,0x2b,&WPP_e4386b12b8143f81186affdeca2b77e8_Traceguids,0x12,&local_res20,8,
                  param_5,lVar1,&param_6,8,&param_7,4,&param_8,8,&param_9,4,0);
  return;
}



===== WPP_SF_qSqqDqD @ 1800140dc =====

void WPP_SF_qSqqDqD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                   wchar_t *param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                   undefined1 param_9,undefined1 param_10)

{
  longlong lVar1;
  undefined8 local_res20;
  
  if (param_5 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_5[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"NULL";
  }
  local_res20 = param_4;
  EtwTraceMessage(param_1,0x2b,&WPP_e4386b12b8143f81186affdeca2b77e8_Traceguids,0x1d,&local_res20,8,
                  param_5,lVar1,&param_6,8,&param_7,8,&param_8,4,&param_9,8,&param_10,4,0);
  return;
}



===== WPP_SF_qqDqDqD @ 1800141e0 =====

void WPP_SF_qqDqDqD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                   undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                   undefined1 param_9,undefined1 param_10)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  EtwTraceMessage(param_1,0x2b,&WPP_e4386b12b8143f81186affdeca2b77e8_Traceguids,0x2c,&local_res20,8,
                  &param_5,8,&param_6,4,&param_7,8,&param_8,4,&param_9,8,&param_10,4,0);
  return;
}



===== WPP_SF_qqDqqDqD @ 18001427c =====

void WPP_SF_qqDqqDqD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                    undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                    undefined1 param_9,undefined1 param_10,undefined1 param_11)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  EtwTraceMessage(param_1,0x2b,&WPP_e4386b12b8143f81186affdeca2b77e8_Traceguids,0x2b,&local_res20,8,
                  &param_5,8,&param_6,4,&param_7,8,&param_8,8,&param_9,4,&param_10,8,&param_11,4,0);
  return;
}



===== WPP_SF_qqSqqdD @ 180014324 =====

void WPP_SF_qqSqqdD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                   undefined1 param_5,wchar_t *param_6,undefined1 param_7,undefined1 param_8,
                   undefined1 param_9,undefined1 param_10)

{
  longlong lVar1;
  wchar_t *pwVar2;
  undefined8 local_res20;
  
  if (param_6 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_6[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  pwVar2 = param_6;
  if (param_6 == (wchar_t *)0x0) {
    pwVar2 = L"NULL";
  }
  local_res20 = param_4;
  EtwTraceMessage(param_1,0x2b,&WPP_e4386b12b8143f81186affdeca2b77e8_Traceguids,0x1b,&local_res20,8,
                  &param_5,8,pwVar2,lVar1,&param_7,8,&param_8,8,&param_9,4,&param_10,4,0);
  return;
}



===== WPP_SF_qqSqqdqdD @ 180014428 =====

void WPP_SF_qqSqqdqdD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                     undefined1 param_5,wchar_t *param_6,undefined1 param_7,undefined1 param_8,
                     undefined1 param_9,undefined1 param_10,undefined1 param_11,undefined1 param_12)

{
  longlong lVar1;
  wchar_t *pwVar2;
  undefined8 local_res20;
  
  if (param_6 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_6[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  pwVar2 = param_6;
  if (param_6 == (wchar_t *)0x0) {
    pwVar2 = L"NULL";
  }
  local_res20 = param_4;
  EtwTraceMessage(param_1,0x2b,&WPP_e4386b12b8143f81186affdeca2b77e8_Traceguids,0x1a,&local_res20,8,
                  &param_5,8,pwVar2,lVar1,&param_7,8,&param_8,8,&param_9,4,&param_10,8,&param_11,4,
                  &param_12,4,0);
  return;
}



===== WPP_SF_qqdD @ 18001455c =====

void WPP_SF_qqdD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  EtwTraceMessage(param_1,0x2b,&WPP_e4386b12b8143f81186affdeca2b77e8_Traceguids,param_2,&local_res20
                  ,8,&param_5,8,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_qqqD @ 1800145d0 =====

void WPP_SF_qqqD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  EtwTraceMessage(param_1,0x2b,&WPP_e4386b12b8143f81186affdeca2b77e8_Traceguids,0x1c,&local_res20,8,
                  &param_5,8,&param_6,8,&param_7,4,0);
  return;
}



===== WPP_SF_qqqdqdD @ 180014644 =====

void WPP_SF_qqqdqdD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                   undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                   undefined1 param_9,undefined1 param_10)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  EtwTraceMessage(param_1,0x2b,&WPP_e4386b12b8143f81186affdeca2b77e8_Traceguids,param_2,&local_res20
                  ,8,&param_5,8,&param_6,8,&param_7,4,&param_8,8,&param_9,4,&param_10,4,0);
  return;
}



===== RouterAesKeyUnwrap @ 1800146e4 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */

int RouterAesKeyUnwrap(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
                      undefined4 param_5,void *param_6,uint param_7)

{
  ulonglong *puVar1;
  int iVar2;
  ulonglong *puVar3;
  ulonglong uVar4;
  ulonglong _Size;
  longlong lVar5;
  ulonglong uVar6;
  code **ppcVar7;
  ulonglong uVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  ulonglong uVar11;
  ulonglong *puVar12;
  uint uVar13;
  undefined1 auStack_178 [32];
  ulonglong *local_158;
  int local_150;
  ulonglong *local_148;
  undefined4 local_140;
  int *local_138;
  undefined4 local_130;
  undefined8 local_118;
  uint local_110;
  undefined8 local_108;
  code *local_100;
  ulonglong local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  longlong local_e0;
  ulonglong local_d8;
  undefined8 local_d0;
  code *local_c8;
  ulonglong local_c0 [3];
  ulonglong local_a8 [10];
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStack_178;
  _Size = (ulonglong)param_7;
  local_c8 = *(code **)(param_1 + 0x58);
  local_118._4_4_ = 0;
  local_118._0_4_ = 0;
  local_100 = *(code **)(*(longlong *)(param_2 + 8) + 0x68);
  local_108 = *(undefined8 *)(param_2 + 0x10);
  local_158 = &local_118;
  local_150 = 0;
  local_f0 = param_4;
  local_e8 = param_3;
  local_e0 = param_1;
  iVar2 = (**(code **)(*(longlong *)(param_2 + 8) + 0x40))
                    (local_108,L"BlockLength",(int *)((longlong)&local_118 + 4),4);
  if (iVar2 < 0) {
    uVar9 = 0x94;
    uVar10 = (undefined1)iVar2;
  }
  else if (((int)local_118 == 4) && (local_118._4_4_ == 0x10)) {
    if (((param_7 & 7) == 0) && (0xf < param_7)) {
      if (param_7 < 0x49) {
        puVar3 = local_a8;
        puVar12 = (ulonglong *)0x0;
      }
      else {
        puVar3 = (ulonglong *)BCryptAlloc(_Size);
        if (puVar3 == (ulonglong *)0x0) {
          iVar2 = -0x3fffffe9;
          uVar9 = 0xb8;
          uVar10 = 0x17;
          goto LAB_180014985;
        }
        puVar12 = puVar3;
      }
      memcpy(puVar3,param_6,_Size);
      uVar4 = *puVar3;
      puVar1 = puVar3 + 1;
      uVar11 = (ulonglong)(param_7 - 8 >> 3);
      for (uVar13 = 0; uVar13 < 6; uVar13 = uVar13 + 1) {
        uVar8 = uVar11;
        while ((int)uVar8 != 0) {
          local_130 = 0;
          uVar6 = (5 - uVar13) * uVar11 + uVar8;
          local_d8 = (uVar6 >> 0x38 | (uVar6 & 0xff000000000000) >> 0x28 |
                      (uVar6 & 0xff0000000000) >> 0x18 | (uVar6 & 0xff00000000) >> 8 |
                      (uVar6 & 0xff000000) << 8 | (uVar6 & 0xff0000) << 0x18 |
                      (uVar6 & 0xff00) << 0x28 | uVar6 << 0x38) ^ uVar4;
          local_110 = (int)uVar8 - 1;
          local_f8 = (ulonglong)(local_110 * 8);
          local_d0 = *(undefined8 *)(local_f8 + (longlong)puVar1);
          local_138 = (int *)&local_118;
          local_148 = &local_d8;
          local_140 = 0x10;
          local_158 = local_c0;
          local_150 = 0x10;
          local_c0[0] = 0;
          local_c0[1] = 0;
          iVar2 = (*local_100)(local_108,&local_d8,0x10);
          if (iVar2 < 0) {
            uVar10 = 0xe5;
            goto LAB_1800148d8;
          }
          uVar8 = (ulonglong)local_110;
          *(undefined8 *)(local_f8 + (longlong)puVar1) = local_d0;
          uVar4 = local_d8;
        }
      }
      if (uVar4 == 0xa6a6a6a6a6a6a6a6) {
        local_148 = (ulonglong *)((ulonglong)local_148 & 0xffffffff00000000);
        local_150 = param_7 - 8;
        local_158 = puVar1;
        iVar2 = (*local_c8)(*(undefined8 *)(local_e0 + 0x18),local_e8,local_f0,param_5);
        if (iVar2 < 0) {
          uVar10 = 0xff;
LAB_1800148d8:
          DebugTraceError((char)iVar2,"Status",
                          "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\routeraeskeywrap.c",
                          uVar10);
        }
        else {
          iVar2 = 0;
        }
      }
      else {
        iVar2 = -0x3fff5ffe;
      }
      if (puVar3 != (ulonglong *)0x0) {
        for (; _Size != 0; _Size = _Size - 1) {
          *(undefined1 *)puVar3 = 0;
          puVar3 = (ulonglong *)((longlong)puVar3 + 1);
        }
      }
      if (puVar12 != (ulonglong *)0x0) {
        BCryptFree((longlong)puVar12);
      }
      goto LAB_180014998;
    }
    iVar2 = -0x3ffffff3;
    uVar9 = 0xa4;
    uVar10 = 0xd;
  }
  else {
    iVar2 = -0x3ffffff8;
    uVar9 = 0x9c;
    uVar10 = 8;
  }
LAB_180014985:
  DebugTraceError(uVar10,"Status",
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\routeraeskeywrap.c",uVar9);
LAB_180014998:
  puVar3 = local_c0;
  for (lVar5 = 0x10; lVar5 != 0; lVar5 = lVar5 + -1) {
    *(undefined1 *)puVar3 = 0;
    puVar3 = (ulonglong *)((longlong)puVar3 + 1);
  }
  puVar3 = &local_d8;
  for (lVar5 = 0x10; lVar5 != 0; lVar5 = lVar5 + -1) {
    *(undefined1 *)puVar3 = 0;
    puVar3 = (ulonglong *)((longlong)puVar3 + 1);
  }
  ppcVar7 = &local_c8;
  for (lVar5 = 8; lVar5 != 0; lVar5 = lVar5 + -1) {
    *(undefined1 *)ppcVar7 = 0;
    ppcVar7 = (code **)((longlong)ppcVar7 + 1);
  }
  return iVar2;
}



===== RouterGetKeyDataBlob @ 1800149e0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int RouterGetKeyDataBlob(longlong param_1,void *param_2,uint param_3)

{
  undefined8 uVar1;
  code *pcVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 uVar5;
  ulonglong uVar6;
  undefined1 *puVar7;
  undefined1 uVar8;
  undefined1 auStack_e8 [32];
  uint local_c8;
  uint *local_c0;
  undefined4 local_b8;
  uint local_a8 [4];
  undefined1 local_98 [80];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_e8;
  puVar4 = (undefined1 *)0x0;
  local_a8[0] = 0;
  local_a8[1] = 0;
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  pcVar2 = *(code **)(*(longlong *)(param_1 + 8) + 0x78);
  local_b8 = 0;
  local_c0 = local_a8;
  local_c8 = 0;
  iVar3 = (*pcVar2)(uVar1,0,L"KeyDataBlob",0);
  if (iVar3 < 0) {
    uVar8 = 0x46;
    uVar5 = (undefined1)iVar3;
LAB_180014a55:
    DebugTraceError(uVar5,"Status",
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\routeraeskeywrap.c",uVar8);
    return iVar3;
  }
  if (local_a8[0] < 0x4d) {
    puVar7 = local_98;
  }
  else {
    puVar4 = (undefined1 *)BCryptAlloc((ulonglong)local_a8[0]);
    if (puVar4 == (undefined1 *)0x0) {
      iVar3 = -0x3fffffe9;
      uVar8 = 0x57;
      uVar5 = 0x17;
      goto LAB_180014a55;
    }
    puVar7 = puVar4;
  }
  local_b8 = 0;
  local_c0 = local_a8 + 1;
  local_c8 = local_a8[0];
  iVar3 = (*pcVar2)(uVar1,0,L"KeyDataBlob",puVar7);
  if (iVar3 < 0) {
    uVar8 = 0x6b;
    uVar5 = (undefined1)iVar3;
  }
  else {
    if (param_3 == *(uint *)(puVar7 + 8)) {
      memcpy(param_2,puVar7 + 0xc,(ulonglong)param_3);
      iVar3 = 0;
      goto LAB_180014b19;
    }
    iVar3 = -0x3ffffff3;
    uVar8 = 0x74;
    uVar5 = 0xd;
  }
  DebugTraceError(uVar5,"Status",
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\crypt\\routeraeskeywrap.c",uVar8);
LAB_180014b19:
  if (puVar4 != (undefined1 *)0x0) {
    puVar7 = puVar4;
    for (uVar6 = (ulonglong)local_a8[0]; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
    BCryptFree((longlong)puVar4);
  }
  return iVar3;
}



===== McGenControlCallbackV2 @ 180014b60 =====

void McGenControlCallbackV2
               (undefined8 param_1,int param_2,undefined1 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,longlong param_7)

{
  uint *puVar1;
  ulonglong uVar2;
  bool bVar3;
  uint uVar4;
  ulonglong uVar5;
  
  if (param_7 != 0) {
    if (param_2 == 0) {
      *(undefined4 *)(param_7 + 0x24) = 0;
      *(undefined1 *)(param_7 + 0x28) = 0;
      *(undefined8 *)(param_7 + 0x10) = 0;
      *(undefined8 *)(param_7 + 0x18) = 0;
      if (*(short *)(param_7 + 0x2a) != 0) {
        memset(*(void **)(param_7 + 0x30),0,
               (longlong)((int)(*(ushort *)(param_7 + 0x2a) - 1) / 0x20 + 1) << 2);
      }
    }
    else if (param_2 == 1) {
      *(undefined1 *)(param_7 + 0x28) = param_3;
      uVar5 = 0;
      *(undefined8 *)(param_7 + 0x18) = param_5;
      *(undefined8 *)(param_7 + 0x10) = param_4;
      *(undefined4 *)(param_7 + 0x24) = 1;
      if (*(short *)(param_7 + 0x2a) != 0) {
        do {
          uVar2 = *(ulonglong *)(*(longlong *)(param_7 + 0x38) + uVar5 * 8);
          if (((*(byte *)(param_7 + 0x28) < *(byte *)(uVar5 + *(longlong *)(param_7 + 0x40))) &&
              (*(byte *)(param_7 + 0x28) != 0)) ||
             ((uVar2 != 0 &&
              (((*(ulonglong *)(param_7 + 0x10) & uVar2) == 0 ||
               ((*(ulonglong *)(param_7 + 0x18) & uVar2) != *(ulonglong *)(param_7 + 0x18))))))) {
            bVar3 = false;
          }
          else {
            bVar3 = true;
          }
          uVar4 = 1 << ((byte)uVar5 & 0x1f);
          puVar1 = (uint *)(*(longlong *)(param_7 + 0x30) + (uVar5 >> 5) * 4);
          if (bVar3) {
            uVar4 = uVar4 | *puVar1;
          }
          else {
            uVar4 = ~uVar4 & *puVar1;
          }
          *puVar1 = uVar4;
          uVar4 = (int)uVar5 + 1;
          uVar5 = (ulonglong)uVar4;
        } while (uVar4 < *(ushort *)(param_7 + 0x2a));
        return;
      }
    }
  }
  return;
}



===== UninitializeCNG @ 180014c74 =====

void UninitializeCNG(undefined8 param_1,undefined8 param_2,undefined *param_3)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)DAT_180025aa8;
  if ((DAT_180025aa8 & 2) != 0) {
    UninitializeLoader(uVar1,param_2,param_3);
    DAT_180025aa8 = DAT_180025aa8 & 0xfffffffd;
    uVar1 = (ulonglong)DAT_180025aa8;
  }
  if ((uVar1 & 8) != 0) {
    CleanupSystemPreferredCache();
    DAT_180025aa8 = DAT_180025aa8 & 0xfffffff7;
    uVar1 = (ulonglong)DAT_180025aa8;
  }
  if ((uVar1 & 4) != 0) {
    UninitializeConfig();
    DAT_180025aa8 = DAT_180025aa8 & 0xfffffffb;
  }
  g_fLoadCNGDone = 0;
  return;
}



===== WPP_SF_qS @ 180014cd8 =====

void WPP_SF_qS(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  undefined8 local_res20;
  
  lVar1 = -1;
  do {
    lVar1 = lVar1 + 1;
  } while (*(short *)(&DAT_1800258a0 + lVar1 * 2) != 0);
  local_res20 = param_4;
  EtwTraceMessage(param_1,0x2b,&WPP_fe074c7cd9a7391c7f5067cf19ca123d_Traceguids,param_2,&local_res20
                  ,8,&DAT_1800258a0,lVar1 * 2 + 2,0);
  return;
}



===== WppControlCallback @ 180014d50 =====

undefined8 WppControlCallback(int param_1,longlong param_2,undefined4 *param_3,undefined8 param_4)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  *param_3 = 0;
  if (param_1 == 4) {
    uVar3 = EtwGetTraceLoggerHandle(param_4);
    uVar1 = EtwGetTraceEnableLevel(uVar3);
    uVar2 = EtwGetTraceEnableFlags(uVar3);
  }
  else {
    if (param_1 != 5) {
      return 0x57;
    }
    uVar3 = 0;
    uVar2 = 0;
    uVar1 = 0;
  }
  if (((*(byte *)(param_2 + 0x1a) & 2) != 0) && (*(longlong *)(param_2 + 0x10) != 0)) {
    param_2 = *(longlong *)(param_2 + 0x10);
  }
  *(undefined4 *)(param_2 + 0x1c) = uVar2;
  *(undefined8 *)(param_2 + 0x10) = uVar3;
  *(undefined1 *)(param_2 + 0x19) = uVar1;
  return 0;
}



===== CachedCloseAlgorithmProvider @ 180014de8 =====

NTSTATUS CachedCloseAlgorithmProvider(BCRYPT_ALG_HANDLE param_1)

{
  bool bVar1;
  NTSTATUS NVar2;
  longlong *plVar3;
  longlong lVar4;
  
  bVar1 = false;
  plVar3 = getCache();
  if (plVar3 != (longlong *)0x0) {
    AcquireSRWLockShared(g_pHandleCacheLock);
    for (lVar4 = 0; lVar4 < 8; lVar4 = lVar4 + 1) {
      if ((BCRYPT_ALG_HANDLE)*plVar3 == param_1) {
        LOCK();
        plVar3[1] = plVar3[1] + -1;
        UNLOCK();
        bVar1 = true;
        break;
      }
      plVar3 = plVar3 + 0x1c;
    }
    ReleaseSRWLockShared(g_pHandleCacheLock);
    if (bVar1) {
      return 0;
    }
  }
  NVar2 = BCryptCloseAlgorithmProvider(param_1,0);
  return NVar2;
}



===== CachedOpenAlgorithmProvider @ 180014e88 =====

NTSTATUS CachedOpenAlgorithmProvider(longlong *param_1,wchar_t *param_2,BCRYPT_ALG_HANDLE param_3)

{
  NTSTATUS NVar1;
  BCRYPT_ALG_HANDLE local_res18 [2];
  
  NVar1 = 0;
  local_res18[0] = param_3;
  local_res18[0] = (BCRYPT_ALG_HANDLE)findEntryInCache(param_2);
  if (local_res18[0] == (BCRYPT_ALG_HANDLE)0x0) {
    NVar1 = BCryptOpenAlgorithmProvider(local_res18,param_2,(LPCWSTR)0x0,0);
    if (NVar1 < 0) {
      local_res18[0] = (BCRYPT_ALG_HANDLE)0x0;
    }
    else {
      addEntryToCache((longlong)local_res18[0],param_2);
    }
  }
  *param_1 = (longlong)local_res18[0];
  return NVar1;
}



===== addEntryToCache @ 180014f04 =====

void addEntryToCache(longlong param_1,STRSAFE_LPCWSTR param_2)

{
  HRESULT HVar1;
  longlong *plVar2;
  int iVar3;
  longlong *_Dst;
  longlong lVar4;
  
  plVar2 = getCache();
  if (plVar2 == (longlong *)0x0) {
    return;
  }
  AcquireSRWLockExclusive(g_pHandleCacheLock);
  _Dst = plVar2;
  for (lVar4 = 0; lVar4 < 8; lVar4 = lVar4 + 1) {
    if (*_Dst == 0) goto LAB_180014fad;
    _Dst = _Dst + 0x1c;
  }
  iVar3 = 0;
  while( true ) {
    if (7 < iVar3) goto LAB_180014fe4;
    _Dst = plVar2 + (ulonglong)g_handleCacheNextReplace * 0x1c;
    g_handleCacheNextReplace = g_handleCacheNextReplace + 1 & 7;
    if (_Dst[1] == 0) break;
    iVar3 = iVar3 + 1;
  }
  BCryptCloseAlgorithmProvider((BCRYPT_ALG_HANDLE)*_Dst,0);
  memset(_Dst,0,0xe0);
LAB_180014fad:
  HVar1 = StringCchCopyW((STRSAFE_LPWSTR)(_Dst + 3),0x21,param_2);
  if (HVar1 < 0) {
    memset(_Dst,0,0xe0);
  }
  else {
    *(undefined4 *)((longlong)_Dst + 0x14) = 0;
    *(undefined4 *)(_Dst + 2) = 0;
    *_Dst = param_1;
    _Dst[1] = 1;
  }
LAB_180014fe4:
  ReleaseSRWLockExclusive(g_pHandleCacheLock);
  return;
}



===== findEntryInCache @ 18001501c =====

undefined8 findEntryInCache(wchar_t *param_1)

{
  int iVar1;
  void *pvVar2;
  undefined8 uVar3;
  int *piVar4;
  longlong lVar5;
  
  pvVar2 = getCache();
  uVar3 = 0;
  if (pvVar2 != (void *)0x0) {
    AcquireSRWLockShared(g_pHandleCacheLock);
    piVar4 = (int *)((longlong)pvVar2 + 0x14);
    for (lVar5 = 0; uVar3 = 0, lVar5 < 8; lVar5 = lVar5 + 1) {
      if (*(longlong *)(piVar4 + -5) != 0) {
        iVar1 = wcsncmp(param_1,(wchar_t *)(piVar4 + 1),0x21);
        if (((iVar1 == 0) && (*piVar4 == 0)) && (piVar4[-1] == 0)) {
          uVar3 = *(undefined8 *)(piVar4 + -5);
          LOCK();
          *(longlong *)(piVar4 + -3) = *(longlong *)(piVar4 + -3) + 1;
          UNLOCK();
          break;
        }
      }
      piVar4 = piVar4 + 0x38;
    }
    ReleaseSRWLockShared(g_pHandleCacheLock);
  }
  return uVar3;
}



===== getCache @ 1800150d8 =====

void * getCache(void)

{
  void *_Dst;
  PSRWLOCK SRWLock;
  bool bVar1;
  
  if (g_handleCache == (void *)0x0) {
    _Dst = (void *)BCryptAlloc(0x700);
    if (_Dst == (void *)0x0) {
      return (void *)0x0;
    }
    memset(_Dst,0,0x700);
    LOCK();
    bVar1 = g_handleCache == (void *)0x0;
    if (bVar1) {
      g_handleCache = _Dst;
    }
    UNLOCK();
    if (!bVar1) {
      SafeAllocaFreeToHeap(_Dst);
    }
  }
  if (g_pHandleCacheLock == (PSRWLOCK)0x0) {
    SRWLock = (PSRWLOCK)BCryptAlloc(8);
    if (SRWLock == (PSRWLOCK)0x0) {
      return (void *)0x0;
    }
    InitializeSRWLock(SRWLock);
    LOCK();
    bVar1 = g_pHandleCacheLock == (PSRWLOCK)0x0;
    if (bVar1) {
      g_pHandleCacheLock = SRWLock;
    }
    UNLOCK();
    if (!bVar1) {
      SafeAllocaFreeToHeap(SRWLock);
    }
  }
  return g_handleCache;
}



===== ApplyOAEPPaddingSeeded @ 180015180 =====

NTSTATUS ApplyOAEPPaddingSeeded
                   (BCRYPT_ALG_HANDLE param_1,uint param_2,uint param_3,PUCHAR param_4,ULONG param_5
                   ,BCRYPT_HASH_HANDLE param_6,void *param_7,uint param_8,byte *param_9,
                   uint param_10)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  NTSTATUS NVar4;
  PUCHAR pbHashObject;
  undefined1 uVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  ulonglong uVar9;
  byte *pbVar10;
  ulonglong uVar11;
  byte *pbBuffer;
  uint uVar12;
  undefined1 uVar13;
  
  param_6 = (BCRYPT_HASH_HANDLE)0x0;
  pbHashObject = (PUCHAR)0x0;
  uVar11 = (ulonglong)param_2;
  if (uVar11 * 2 < 0x100000000) {
    uVar12 = (uint)(uVar11 * 2);
    if (uVar12 + param_8 < param_8) {
      uVar13 = 0xd2;
      goto LAB_18001547d;
    }
    uVar6 = uVar12 + param_8 + 2;
    if (uVar6 < 2) {
      uVar13 = 0xd7;
      goto LAB_18001547d;
    }
    if (uVar6 <= param_10) {
      uVar6 = param_10 - uVar6;
      uVar7 = param_2 + 1;
      if (uVar7 == 0) {
        uVar13 = 0xe6;
      }
      else if (param_10 < uVar7) {
        uVar13 = 0xeb;
      }
      else {
        uVar7 = param_10 - uVar7;
        if ((ulonglong)uVar7 * 2 < 0x100000000) {
          uVar3 = (int)((ulonglong)uVar7 * 2) + uVar12;
          if (uVar3 < uVar12) {
            uVar13 = 0xfc;
          }
          else {
            uVar3 = uVar3 + param_3;
            if (param_3 <= uVar3) {
              pbHashObject = (PUCHAR)BCryptAlloc((ulonglong)uVar3);
              if (pbHashObject == (PUCHAR)0x0) {
                NVar4 = -0x3fffffe9;
                uVar13 = 10;
                uVar5 = 0x17;
                goto LAB_180015484;
              }
              pbBuffer = pbHashObject + param_3;
              pbVar10 = pbBuffer + uVar11 * 2;
              NVar4 = BCryptCreateHash(param_1,&param_6,pbHashObject,param_3,(PUCHAR)0x0,0,0);
              if (NVar4 < 0) {
                uVar13 = 0x1d;
              }
              else {
                if (param_5 != 0) {
                  NVar4 = BCryptHashData(param_6,param_4,param_5,0);
                  if (NVar4 < 0) {
                    uVar13 = 0x2a;
                    goto LAB_1800152a9;
                  }
                }
                NVar4 = BCryptFinishHash(param_6,pbVar10,param_2,0);
                if (NVar4 < 0) {
                  uVar13 = 0x35;
                }
                else {
                  memset(pbVar10 + uVar11,0,(ulonglong)uVar6);
                  pbVar10[uVar6 + param_2] = 1;
                  memcpy(pbVar10 + (ulonglong)uVar6 + 1 + uVar11,param_7,(ulonglong)param_8);
                  NVar4 = BCryptGenRandom((BCRYPT_ALG_HANDLE)0x0,pbBuffer,param_2,2);
                  if (NVar4 < 0) {
                    uVar13 = 0x45;
                  }
                  else {
                    NVar4 = MaskGeneration(param_1,param_2,(PUCHAR)(ulonglong)param_3,pbBuffer,
                                           param_2,pbVar10 + uVar7,uVar7);
                    pbVar8 = param_9;
                    if (NVar4 < 0) {
                      uVar13 = 0x58;
                    }
                    else {
                      uVar12 = 0;
                      *param_9 = 0;
                      if (uVar7 != 0) {
                        do {
                          pbVar1 = pbVar10 + uVar7;
                          uVar6 = param_2 + 1 + uVar12;
                          bVar2 = *pbVar10;
                          uVar12 = uVar12 + 1;
                          pbVar10 = pbVar10 + 1;
                          param_9[uVar6] = *pbVar1 ^ bVar2;
                        } while (uVar12 < uVar7);
                      }
                      NVar4 = MaskGeneration(param_1,param_2,(PUCHAR)(ulonglong)param_3,
                                             param_9 + uVar11 + 1,uVar7,pbBuffer + uVar11,param_2);
                      if (-1 < NVar4) {
                        if (param_2 != 0) {
                          uVar9 = uVar11;
                          do {
                            pbVar8 = pbVar8 + 1;
                            pbVar10 = pbBuffer + uVar11;
                            bVar2 = *pbBuffer;
                            pbBuffer = pbBuffer + 1;
                            *pbVar8 = *pbVar10 ^ bVar2;
                            uVar9 = uVar9 - 1;
                          } while (uVar9 != 0);
                        }
                        NVar4 = 0;
                        goto LAB_180015497;
                      }
                      uVar13 = 0x6f;
                    }
                  }
                }
              }
LAB_1800152a9:
              uVar5 = (undefined1)NVar4;
              goto LAB_180015484;
            }
            uVar13 = 1;
          }
        }
        else {
          uVar13 = 0xf2;
        }
      }
      goto LAB_18001547d;
    }
    NVar4 = -0x3ffffff3;
    uVar13 = 0xde;
    uVar5 = 0xd;
  }
  else {
    uVar13 = 0xcd;
LAB_18001547d:
    NVar4 = -0x3fffff6b;
    uVar5 = 0x95;
  }
LAB_180015484:
  DebugTraceError(uVar5,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\format.c",uVar13
                 );
LAB_180015497:
  if (param_6 != (BCRYPT_HASH_HANDLE)0x0) {
    BCryptDestroyHash(param_6);
  }
  if (pbHashObject != (PUCHAR)0x0) {
    SafeAllocaFreeToHeap(pbHashObject);
  }
  return NVar4;
}



===== ApplyPSSPaddingSalted @ 1800154d0 =====

NTSTATUS ApplyPSSPaddingSalted
                   (BCRYPT_ALG_HANDLE param_1,ULONG param_2,uint param_3,undefined8 param_4,
                   uint param_5,void *param_6,uint param_7,byte *param_8,uint param_9)

{
  PUCHAR pbInput;
  NTSTATUS NVar1;
  PUCHAR pbHashObject;
  undefined1 uVar2;
  longlong lVar3;
  ulonglong uVar4;
  uint uVar5;
  uint uVar6;
  byte *_Dst;
  undefined1 uVar7;
  BCRYPT_HASH_HANDLE local_res20;
  
  local_res20 = (BCRYPT_HASH_HANDLE)0x0;
  if (param_9 < param_5 + 2 + param_2) {
    return -0x7ff6fffe;
  }
  uVar5 = (param_9 - param_2) - 1;
  uVar6 = param_7 + 8 + param_5;
  uVar4 = (ulonglong)((uVar5 - param_5) - 1);
  pbHashObject = (PUCHAR)BCryptAlloc((ulonglong)(uVar6 + uVar5 * 2 + param_3));
  if (pbHashObject == (PUCHAR)0x0) {
    NVar1 = -0x3fffffe9;
    uVar7 = 0xb0;
    uVar2 = 0x17;
  }
  else {
    pbInput = pbHashObject + param_3;
    _Dst = pbInput + uVar6;
    pbInput[0] = '\0';
    pbInput[1] = '\0';
    pbInput[2] = '\0';
    pbInput[3] = '\0';
    pbInput[4] = '\0';
    pbInput[5] = '\0';
    pbInput[6] = '\0';
    pbInput[7] = '\0';
    memcpy(pbInput + 8,param_6,(ulonglong)param_7);
    NVar1 = BCryptGenRandom((BCRYPT_ALG_HANDLE)0x0,pbInput + (ulonglong)param_7 + 8,param_5,2);
    if (NVar1 < 0) {
      uVar7 = 0xc5;
    }
    else {
      NVar1 = BCryptCreateHash(param_1,&local_res20,pbHashObject,param_3,(PUCHAR)0x0,0,0);
      if (NVar1 < 0) {
        uVar7 = 0xd9;
      }
      else {
        NVar1 = BCryptHashData(local_res20,pbInput,param_7 + 8 + param_5,0);
        if (NVar1 < 0) {
          uVar7 = 0xe3;
        }
        else {
          NVar1 = BCryptFinishHash(local_res20,param_8 + uVar5,param_2,0);
          if (NVar1 < 0) {
            uVar7 = 0xed;
          }
          else {
            memset(_Dst,0,uVar4);
            _Dst[uVar4] = 1;
            memcpy(_Dst + uVar4 + 1,pbInput + (ulonglong)param_7 + 8,(ulonglong)param_5);
            NVar1 = MaskGeneration(param_1,param_2,(PUCHAR)(ulonglong)param_3,param_8 + uVar5,
                                   param_2,_Dst + uVar5,uVar5);
            if (-1 < NVar1) {
              if (uVar5 != 0) {
                uVar4 = (ulonglong)uVar5;
                lVar3 = (longlong)param_8 - (longlong)_Dst;
                do {
                  _Dst[lVar3] = _Dst[uVar5] ^ *_Dst;
                  _Dst = _Dst + 1;
                  uVar4 = uVar4 - 1;
                } while (uVar4 != 0);
              }
              *param_8 = *param_8 & 0x7f;
              param_8[param_9 - 1] = 0xbc;
              NVar1 = 0;
              goto LAB_180015726;
            }
            uVar7 = 0;
          }
        }
      }
    }
    uVar2 = (undefined1)NVar1;
  }
  DebugTraceError(uVar2,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\format.c",uVar7)
  ;
LAB_180015726:
  if (local_res20 != (BCRYPT_HASH_HANDLE)0x0) {
    BCryptDestroyHash(local_res20);
  }
  if (pbHashObject != (PUCHAR)0x0) {
    SafeAllocaFreeToHeap(pbHashObject);
  }
  return NVar1;
}



===== ApplySignaturePadding @ 180015768 =====

NTSTATUS ApplySignaturePadding
                   (ulonglong param_1,undefined8 *param_2,BCRYPT_ALG_HANDLE param_3,uint param_4,
                   byte *param_5,uint param_6)

{
  NTSTATUS NVar1;
  int iVar2;
  int *pbOutput;
  undefined8 uVar3;
  undefined1 uVar4;
  BCRYPT_ALG_HANDLE hObject;
  undefined1 uVar5;
  ULONG local_res8 [2];
  uint local_38;
  uint local_34;
  BCRYPT_ALG_HANDLE local_30;
  
  hObject = (BCRYPT_ALG_HANDLE)0x0;
  pbOutput = (int *)0x0;
  local_34 = 0;
  local_38 = 0;
  local_res8[0] = 0;
  local_30 = (BCRYPT_ALG_HANDLE)0x0;
  if ((param_1 & 2) == 0) {
    if ((param_1 & 8) == 0) {
      uVar5 = 0xe0;
LAB_180015ab3:
      uVar4 = 0xd;
      NVar1 = -0x3ffffff3;
LAB_180015abd:
      DebugTraceError(uVar4,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\format.c",
                      uVar5);
      goto LAB_180015ad0;
    }
    if ((param_2 != (undefined8 *)0x0) && ((wchar_t *)*param_2 != (wchar_t *)0x0)) {
      NVar1 = CachedOpenAlgorithmProvider((longlong *)&local_30,(wchar_t *)*param_2,param_3);
      hObject = local_30;
      if (-1 < NVar1) {
        NVar1 = BCryptGetProperty(local_30,L"ObjectLength",(PUCHAR)&local_34,4,local_res8,0);
        if (NVar1 < 0) {
          uVar5 = 0xbf;
        }
        else {
          uVar3 = 4;
          NVar1 = BCryptGetProperty(hObject,L"HashDigestLength",(PUCHAR)&local_38,4,local_res8,0);
          if (NVar1 < 0) {
            uVar5 = 0xcb;
          }
          else {
            NVar1 = ApplyPSSPaddingSalted
                              (hObject,local_38,local_34,uVar3,*(uint *)(param_2 + 1),param_3,
                               param_4,param_5,param_6);
            if (-1 < NVar1) goto LAB_180015a91;
            uVar5 = 0xd9;
          }
        }
        goto LAB_180015849;
      }
      DebugTraceError(0xbb,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\format.c",
                      0xb3);
LAB_18001580a:
      NVar1 = -0x3fffff45;
      hObject = local_30;
      goto LAB_180015ad0;
    }
    uVar5 = 0xa7;
  }
  else {
    if (param_2 != (undefined8 *)0x0) {
      if ((wchar_t *)*param_2 == (wchar_t *)0x0) {
        uVar3 = ApplyPKCS1SigningFormat
                          ((void *)0x0,0,param_3,param_4,(undefined2 *)param_5,param_6,0);
        iVar2 = (int)uVar3;
        if (iVar2 < 0) {
          uVar5 = 0x9a;
          uVar4 = (undefined1)uVar3;
          goto LAB_1800157b9;
        }
LAB_180015a91:
        NVar1 = 0;
        if (pbOutput == (int *)0x0) goto LAB_180015ad0;
      }
      else {
        NVar1 = CachedOpenAlgorithmProvider((longlong *)&local_30,(wchar_t *)*param_2,param_3);
        hObject = local_30;
        if (NVar1 < 0) {
          DebugTraceError((char)NVar1,"Status",
                          "onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\format.c",0x3e);
          goto LAB_18001580a;
        }
        NVar1 = BCryptGetProperty(local_30,L"HashDigestLength",(PUCHAR)&local_38,4,local_res8,0);
        if (NVar1 < 0) {
          uVar5 = 0x4b;
LAB_180015849:
          uVar4 = (undefined1)NVar1;
          goto LAB_180015abd;
        }
        if (local_38 != param_4) {
          uVar5 = 0x51;
          goto LAB_180015ab3;
        }
        NVar1 = BCryptGetProperty(hObject,L"HashOIDList",(PUCHAR)0x0,0,local_res8,0);
        if (NVar1 < 0) {
          uVar5 = 0x5d;
          goto LAB_180015849;
        }
        pbOutput = (int *)BCryptAlloc((ulonglong)local_res8[0]);
        if (pbOutput == (int *)0x0) {
          NVar1 = -0x3fffffe9;
          uVar5 = 0x67;
          uVar4 = 0x17;
          goto LAB_180015abd;
        }
        NVar1 = BCryptGetProperty(hObject,L"HashOIDList",(PUCHAR)pbOutput,local_res8[0],local_res8,0
                                 );
        if (NVar1 < 0) {
          uVar5 = 0x73;
LAB_1800158e6:
          uVar4 = (undefined1)NVar1;
        }
        else {
          if (*pbOutput != 0) {
            uVar3 = ApplyPKCS1SigningFormat
                              (*(void **)(*(uint **)(pbOutput + 2) + 2),**(uint **)(pbOutput + 2),
                               param_3,param_4,(undefined2 *)param_5,param_6,1);
            NVar1 = (NTSTATUS)uVar3;
            if (-1 < NVar1) goto LAB_180015a91;
            uVar5 = 0x8a;
            goto LAB_1800158e6;
          }
          NVar1 = -0x3fffff1b;
          uVar5 = 0x7c;
          uVar4 = 0xe5;
        }
        DebugTraceError(uVar4,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\format.c",
                        uVar5);
      }
      SafeAllocaFreeToHeap(pbOutput);
LAB_180015ad0:
      if (hObject != (BCRYPT_ALG_HANDLE)0x0) {
        CachedCloseAlgorithmProvider(hObject);
      }
      return NVar1;
    }
    uVar5 = 0x31;
  }
  iVar2 = -0x3ffffff3;
  uVar4 = 0xd;
LAB_1800157b9:
  DebugTraceError(uVar4,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\format.c",uVar5)
  ;
  return iVar2;
}



===== CheckOAEPPadding @ 180015b00 =====

NTSTATUS CheckOAEPPadding(BCRYPT_ALG_HANDLE param_1,uint param_2,uint param_3,PUCHAR param_4,
                         ULONG param_5,byte *param_6,uint param_7,void *param_8,uint param_9,
                         uint *param_10)

{
  uint uVar1;
  byte *pbVar2;
  byte *pbVar3;
  NTSTATUS NVar4;
  PUCHAR pUVar5;
  undefined1 uVar6;
  byte *pbVar7;
  uint uVar8;
  byte *pbVar9;
  uint uVar10;
  ulonglong uVar11;
  undefined1 uVar12;
  ulonglong uVar13;
  BCRYPT_HASH_HANDLE local_58;
  byte *local_50;
  PUCHAR local_48;
  byte *local_40;
  
  local_58 = (BCRYPT_HASH_HANDLE)0x0;
  pUVar5 = (PUCHAR)0x0;
  uVar11 = (ulonglong)param_2;
  if ((param_7 < param_2 + 1) || (*param_6 != 0)) {
    uVar12 = 0xd8;
LAB_180015d79:
    NVar4 = -0x3ffffff3;
    uVar6 = 0xd;
  }
  else {
    uVar10 = (param_7 - param_2) - 1;
    pUVar5 = (PUCHAR)BCryptAlloc((ulonglong)(param_3 + (param_2 + 5) * 3 + uVar10 * 2));
    if (pUVar5 == (PUCHAR)0x0) {
      NVar4 = -0x3fffffe9;
      goto LAB_180015d96;
    }
    local_50 = pUVar5 + uVar11;
    pbVar2 = local_50 + uVar11;
    pbVar3 = pbVar2 + uVar10;
    local_40 = pbVar3 + uVar10;
    local_48 = (PUCHAR)((ulonglong)(local_40 + uVar11 + 0xf) & 0xfffffffffffffff0);
    NVar4 = MaskGeneration(param_1,param_2,(PUCHAR)(ulonglong)param_3,param_6 + uVar11 + 1,uVar10,
                           pUVar5,param_2);
    if (NVar4 < 0) {
      uVar12 = 0xf8;
    }
    else {
      if (param_2 != 0) {
        pbVar7 = local_50;
        uVar13 = uVar11;
        pbVar9 = param_6;
        do {
          pbVar9 = pbVar9 + 1;
          *pbVar7 = pbVar7[(longlong)pUVar5 - (longlong)local_50] ^ *pbVar9;
          pbVar7 = pbVar7 + 1;
          uVar13 = uVar13 - 1;
        } while (uVar13 != 0);
      }
      NVar4 = MaskGeneration(param_1,param_2,(PUCHAR)(ulonglong)param_3,local_50,param_2,pbVar2,
                             uVar10);
      if (NVar4 < 0) {
        uVar12 = 0xc;
      }
      else {
        uVar8 = 0;
        if (uVar10 != 0) {
          pbVar9 = pbVar3;
          do {
            uVar1 = param_2 + 1 + uVar8;
            uVar8 = uVar8 + 1;
            *pbVar9 = param_6[uVar1] ^ pbVar9[(longlong)pbVar2 - (longlong)pbVar3];
            pbVar9 = pbVar9 + 1;
          } while (uVar8 < uVar10);
        }
        NVar4 = BCryptCreateHash(param_1,&local_58,local_48,param_3,(PUCHAR)0x0,0,0);
        if (NVar4 < 0) {
          uVar12 = 0x20;
        }
        else {
          if (param_5 != 0) {
            NVar4 = BCryptHashData(local_58,param_4,param_5,0);
            if (NVar4 < 0) {
              uVar12 = 0x2d;
              goto LAB_180015bd9;
            }
          }
          pbVar2 = local_40;
          NVar4 = BCryptFinishHash(local_58,local_40,param_2,0);
          if (-1 < NVar4) {
            for (uVar13 = 0; (uint)uVar13 < param_2; uVar13 = (ulonglong)((uint)uVar13 + 1)) {
              if (pbVar2[uVar13] != pbVar3[uVar13]) {
                uVar12 = 0x42;
                goto LAB_180015d79;
              }
            }
            while (uVar8 = (uint)uVar11, uVar8 < uVar10) {
              if (pbVar3[uVar11] == 1) {
                uVar11 = (ulonglong)(uVar8 + 1);
                break;
              }
              if (pbVar3[uVar11] != 0) {
                uVar12 = 0x52;
                goto LAB_180015d79;
              }
              uVar11 = (ulonglong)(uVar8 + 1);
            }
            uVar10 = uVar10 - (int)uVar11;
            *param_10 = uVar10;
            if (param_8 != (void *)0x0) {
              if (param_9 < uVar10) {
                NVar4 = -0x3fffffdd;
                goto LAB_180015d96;
              }
              memcpy(param_8,pbVar3 + uVar11,(ulonglong)uVar10);
            }
            NVar4 = 0;
            goto LAB_180015d96;
          }
          uVar12 = 0x38;
        }
      }
    }
LAB_180015bd9:
    uVar6 = (undefined1)NVar4;
  }
  DebugTraceError(uVar6,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\format.c",uVar12
                 );
LAB_180015d96:
  if (local_58 != (BCRYPT_HASH_HANDLE)0x0) {
    BCryptDestroyHash(local_58);
  }
  if (pUVar5 != (PUCHAR)0x0) {
    SafeAllocaFreeToHeap(pUVar5);
  }
  return NVar4;
}



===== CheckPSSPadding @ 180015dd4 =====

NTSTATUS CheckPSSPadding(BCRYPT_ALG_HANDLE param_1,uint param_2,uint param_3,uint param_4,
                        void *param_5,uint param_6,byte *param_7,int param_8)

{
  PUCHAR pbInput;
  PUCHAR pbOutput;
  NTSTATUS NVar1;
  int iVar2;
  PUCHAR pUVar3;
  undefined1 uVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  undefined1 uVar8;
  ulonglong uVar9;
  BCRYPT_HASH_HANDLE local_58;
  PUCHAR local_50;
  byte *local_48;
  
  pUVar3 = (PUCHAR)0x0;
  local_58 = (BCRYPT_HASH_HANDLE)0x0;
  if (((char)*param_7 < '\0') || (param_7[param_8 - 1] != 0xbc)) {
    uVar8 = 0x70;
LAB_180016014:
    uVar4 = 0xd;
    NVar1 = -0x3ffffff3;
  }
  else {
    uVar6 = param_6 + param_4 + 8;
    uVar7 = (param_8 - param_2) - 1;
    pUVar3 = (PUCHAR)BCryptAlloc((ulonglong)(uVar6 + param_3 + param_8 + 0xe));
    if (pUVar3 == (PUCHAR)0x0) {
      NVar1 = -0x3fffffe9;
      goto LAB_180016031;
    }
    pbInput = pUVar3 + uVar7;
    uVar9 = (ulonglong)uVar7;
    local_50 = (PUCHAR)((ulonglong)(pbInput + (ulonglong)uVar6 + 0xf) & 0xfffffffffffffff0);
    pbOutput = local_50 + (longlong)(ulonglong)param_3;
    local_48 = param_7 + uVar7;
    NVar1 = MaskGeneration(param_1,param_2,(PUCHAR)(ulonglong)param_3,local_48,param_2,pUVar3,uVar7)
    ;
    if (NVar1 < 0) {
      uVar8 = 0x94;
    }
    else {
      if (uVar7 != 0) {
        pbVar5 = param_7;
        do {
          *pbVar5 = *pbVar5 ^ pbVar5[(longlong)pUVar3 - (longlong)param_7];
          pbVar5 = pbVar5 + 1;
          uVar9 = uVar9 - 1;
        } while (uVar9 != 0);
      }
      *param_7 = *param_7 & 0x7f;
      uVar6 = (uVar7 - param_4) - 1;
      for (uVar9 = 0; (uint)uVar9 < uVar6; uVar9 = (ulonglong)((uint)uVar9 + 1)) {
        if (param_7[uVar9] != 0) {
          uVar8 = 0xa7;
          goto LAB_180016014;
        }
      }
      if (param_7[uVar6] != 1) {
        uVar8 = 0xb0;
        goto LAB_180016014;
      }
      pbInput[0] = '\0';
      pbInput[1] = '\0';
      pbInput[2] = '\0';
      pbInput[3] = '\0';
      pbInput[4] = '\0';
      pbInput[5] = '\0';
      pbInput[6] = '\0';
      pbInput[7] = '\0';
      memcpy(pbInput + 8,param_5,(ulonglong)param_6);
      memcpy(pbInput + (ulonglong)param_6 + 8,param_7 + (uVar7 - param_4),(ulonglong)param_4);
      NVar1 = BCryptCreateHash(param_1,&local_58,local_50,param_3,(PUCHAR)0x0,0,0);
      if (NVar1 < 0) {
        uVar8 = 0xc5;
      }
      else {
        NVar1 = BCryptHashData(local_58,pbInput,param_6 + 8 + param_4,0);
        if (NVar1 < 0) {
          uVar8 = 0xcf;
        }
        else {
          NVar1 = BCryptFinishHash(local_58,pbOutput,param_2,0);
          if (-1 < NVar1) {
            iVar2 = memcmp(local_48,pbOutput,(ulonglong)param_2);
            if (iVar2 == 0) {
              NVar1 = 0;
              goto LAB_180016031;
            }
            uVar8 = 0xe2;
            goto LAB_180016014;
          }
          uVar8 = 0xd9;
        }
      }
    }
    uVar4 = (undefined1)NVar1;
  }
  DebugTraceError(uVar4,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\format.c",uVar8)
  ;
LAB_180016031:
  if (local_58 != (BCRYPT_HASH_HANDLE)0x0) {
    BCryptDestroyHash(local_58);
  }
  if (pUVar3 != (PUCHAR)0x0) {
    SafeAllocaFreeToHeap(pUVar3);
  }
  return NVar1;
}



===== CheckSignaturePadding @ 180016070 =====

NTSTATUS CheckSignaturePadding
                   (ulonglong param_1,undefined8 *param_2,BCRYPT_ALG_HANDLE param_3,uint param_4,
                   byte *param_5,uint param_6)

{
  NTSTATUS NVar1;
  int iVar2;
  uint *pbOutput;
  ulonglong uVar3;
  undefined1 uVar4;
  BCRYPT_ALG_HANDLE hObject;
  undefined1 uVar5;
  ULONG local_res8 [2];
  uint local_38;
  uint local_34;
  BCRYPT_ALG_HANDLE local_30;
  
  hObject = (BCRYPT_ALG_HANDLE)0x0;
  pbOutput = (uint *)0x0;
  local_34 = 0;
  local_38 = 0;
  local_res8[0] = 0;
  local_30 = (BCRYPT_ALG_HANDLE)0x0;
  if ((param_1 & 2) == 0) {
    if ((param_1 & 8) == 0) {
      uVar5 = 0xb9;
LAB_180016394:
      uVar4 = 0xd;
      NVar1 = -0x3ffffff3;
LAB_18001639e:
      DebugTraceError(uVar4,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\format.c",
                      uVar5);
      goto LAB_1800163b1;
    }
    if ((param_2 != (undefined8 *)0x0) && ((wchar_t *)*param_2 != (wchar_t *)0x0)) {
      NVar1 = CachedOpenAlgorithmProvider((longlong *)&local_30,(wchar_t *)*param_2,param_3);
      hObject = local_30;
      if (-1 < NVar1) {
        NVar1 = BCryptGetProperty(local_30,L"ObjectLength",(PUCHAR)&local_34,4,local_res8,0);
        if (NVar1 < 0) {
          uVar5 = 0x98;
        }
        else {
          NVar1 = BCryptGetProperty(hObject,L"HashDigestLength",(PUCHAR)&local_38,4,local_res8,0);
          if (NVar1 < 0) {
            uVar5 = 0xa4;
          }
          else {
            NVar1 = CheckPSSPadding(hObject,local_38,local_34,*(uint *)(param_2 + 1),param_3,param_4
                                    ,param_5,param_6);
            if (-1 < NVar1) goto LAB_180016372;
            uVar5 = 0xb2;
          }
        }
        goto LAB_18001614e;
      }
      uVar5 = 0x8c;
LAB_1800160fa:
      DebugTraceError((char)NVar1,"Status",
                      "onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\format.c",uVar5);
      hObject = local_30;
      goto LAB_1800163b1;
    }
    uVar5 = 0x81;
  }
  else {
    if (param_2 != (undefined8 *)0x0) {
      if ((wchar_t *)*param_2 == (wchar_t *)0x0) {
        uVar3 = VerifyPKCS1SigningFormat(0,0,param_3,param_4,param_5,param_6,0);
        iVar2 = (int)uVar3;
        if (iVar2 < 0) {
          uVar5 = 0x75;
          uVar4 = (undefined1)uVar3;
          goto LAB_1800160c1;
        }
LAB_180016372:
        NVar1 = 0;
        if (pbOutput == (uint *)0x0) goto LAB_1800163b1;
      }
      else {
        NVar1 = CachedOpenAlgorithmProvider((longlong *)&local_30,(wchar_t *)*param_2,param_3);
        hObject = local_30;
        if (NVar1 < 0) {
          uVar5 = 0x1a;
          goto LAB_1800160fa;
        }
        NVar1 = BCryptGetProperty(local_30,L"HashDigestLength",(PUCHAR)&local_38,4,local_res8,0);
        if (NVar1 < 0) {
          uVar5 = 0x26;
LAB_18001614e:
          uVar4 = (undefined1)NVar1;
          goto LAB_18001639e;
        }
        if (local_38 != param_4) {
          uVar5 = 0x2c;
          goto LAB_180016394;
        }
        NVar1 = BCryptGetProperty(hObject,L"HashOIDList",(PUCHAR)0x0,0,local_res8,0);
        if (NVar1 < 0) {
          uVar5 = 0x38;
          goto LAB_18001614e;
        }
        pbOutput = (uint *)BCryptAlloc((ulonglong)local_res8[0]);
        if (pbOutput == (uint *)0x0) {
          NVar1 = -0x3fffffe9;
          uVar5 = 0x42;
          uVar4 = 0x17;
          goto LAB_18001639e;
        }
        NVar1 = BCryptGetProperty(hObject,L"HashOIDList",(PUCHAR)pbOutput,local_res8[0],local_res8,0
                                 );
        if (NVar1 < 0) {
          uVar5 = 0x4e;
LAB_1800161eb:
          uVar4 = (undefined1)NVar1;
        }
        else {
          if (*pbOutput != 0) {
            uVar3 = VerifyPKCS1SigningFormat
                              (*pbOutput,*(longlong *)(pbOutput + 2),param_3,param_4,param_5,param_6
                               ,1);
            NVar1 = (NTSTATUS)uVar3;
            if (-1 < NVar1) goto LAB_180016372;
            uVar5 = 0x65;
            goto LAB_1800161eb;
          }
          NVar1 = -0x3fffff1b;
          uVar5 = 0x57;
          uVar4 = 0xe5;
        }
        DebugTraceError(uVar4,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\format.c",
                        uVar5);
      }
      SafeAllocaFreeToHeap(pbOutput);
LAB_1800163b1:
      if (hObject != (BCRYPT_ALG_HANDLE)0x0) {
        CachedCloseAlgorithmProvider(hObject);
      }
      return NVar1;
    }
    uVar5 = 0xd;
  }
  iVar2 = -0x3ffffff3;
  uVar4 = 0xd;
LAB_1800160c1:
  DebugTraceError(uVar4,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\common\\format.c",uVar5)
  ;
  return iVar2;
}



===== StringCchPrintfW @ 1800163e0 =====

HRESULT __stdcall
StringCchPrintfW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPCWSTR pszFormat,...)

{
  ulonglong _Count;
  int iVar1;
  HRESULT HVar2;
  undefined8 in_R9;
  undefined8 local_res20;
  
  if (cchDest - 1 < 0x7fffffff) {
    _Count = cchDest - 1;
    HVar2 = 0;
    local_res20 = in_R9;
    iVar1 = _vsnwprintf(pszDest,_Count,pszFormat,(va_list)&local_res20);
    if ((iVar1 < 0) || (_Count < (ulonglong)(longlong)iVar1)) {
      HVar2 = -0x7ff8ff86;
    }
    else if ((longlong)iVar1 != _Count) {
      return 0;
    }
    pszDest[_Count] = L'\0';
  }
  else {
    HVar2 = -0x7ff8ffa9;
    if (cchDest != 0) {
      *pszDest = L'\0';
    }
  }
  return HVar2;
}



===== WPP_SF_sDsd @ 18001645c =====

void WPP_SF_sDsd(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4,
                undefined1 param_5,char *param_6,undefined1 param_7)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  char *pcVar4;
  
  if (param_6 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    lVar2 = -1;
    do {
      lVar3 = lVar2;
      lVar2 = lVar3 + 1;
    } while (param_6[lVar2] != '\0');
    lVar3 = lVar3 + 2;
  }
  pcVar4 = param_6;
  if (param_6 == (char *)0x0) {
    pcVar4 = "NULL";
  }
  lVar2 = -1;
  if (param_4 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar2;
      lVar2 = lVar1 + 1;
    } while (param_4[lVar2] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  EtwTraceMessage(param_1,0x2b,&WPP_0d7e072671ea36b765e87831c1b7d985_Traceguids,10,param_4,lVar1,
                  &param_5,4,pcVar4,lVar3,&param_7,4,0);
  return;
}



===== ConvertDhPrivateBlobToLegacy @ 180016528 =====

undefined8
ConvertDhPrivateBlobToLegacy
          (longlong param_1,undefined8 param_2,undefined8 *param_3,uint param_4,uint *param_5)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined8 uVar5;
  undefined1 *puVar6;
  
  if (*(int *)(param_1 + 4) - 0x40U < 0x1c1) {
    uVar1 = *(int *)(param_1 + 4) * 4 + 0x34;
    uVar5 = 0;
    *param_5 = uVar1;
    if (param_3 != (undefined8 *)0x0) {
      if (param_4 < uVar1) {
        uVar5 = 0x80090028;
      }
      else {
        iVar3 = *(int *)(param_1 + 4) << 3;
        memset(param_3,0,(ulonglong)param_4);
        *param_3 = 0xaa0100000307;
        param_3[1] = CONCAT44(iVar3,0x34484400);
        param_3[2] = 0;
        param_3[3] = CONCAT44(0xffffffff,iVar3);
        param_3[4] = 0;
        param_3[5] = 0;
        *(undefined4 *)(param_3 + 6) = 0;
        ReverseMemCopy((undefined1 *)((longlong)param_3 + 0x34),(undefined1 *)(param_1 + 8),
                       *(uint *)(param_1 + 4));
        uVar1 = *(uint *)(param_1 + 4);
        puVar4 = (undefined1 *)(param_1 + 8) + uVar1;
        puVar6 = (undefined1 *)((longlong)param_3 + 0x34) + uVar1;
        ReverseMemCopy(puVar6,puVar4,uVar1);
        uVar1 = *(uint *)(param_1 + 4);
        ReverseMemCopy(puVar6 + uVar1,puVar4 + uVar1,uVar1);
        uVar2 = *(uint *)(param_1 + 4);
        ReverseMemCopy(puVar6 + uVar1 + uVar2,puVar4 + uVar1 + uVar2,uVar2);
      }
    }
  }
  else {
    uVar5 = 0x80090029;
    DebugTraceError(0x29,"Status",
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\translate\\bcrypttranslate.c",0xe);
  }
  return uVar5;
}



===== ConvertDhPublicBlobToLegacy @ 180016698 =====

undefined8
ConvertDhPublicBlobToLegacy
          (longlong param_1,undefined8 param_2,undefined8 *param_3,uint param_4,uint *param_5)

{
  uint uVar1;
  undefined8 *puVar2;
  undefined1 *puVar3;
  undefined8 uVar4;
  undefined1 *puVar5;
  
  if (*(int *)(param_1 + 4) - 0x40U < 0x1c1) {
    uVar4 = 0;
    uVar1 = (*(int *)(param_1 + 4) + 0x10) * 3;
    *param_5 = uVar1;
    if (param_3 != (undefined8 *)0x0) {
      if (param_4 < uVar1) {
        uVar4 = 0x80090028;
      }
      else {
        memset(param_3,0,(ulonglong)param_4);
        puVar5 = (undefined1 *)(param_1 + 8);
        puVar2 = param_3 + 6;
        param_3[1] = CONCAT44(*(int *)(param_1 + 4) << 3,0x33484400);
        param_3[2] = 0;
        *param_3 = 0xaa0100000306;
        param_3[3] = 0xffffffff;
        param_3[4] = 0;
        param_3[5] = 0;
        ReverseMemCopy((undefined1 *)puVar2,puVar5,*(uint *)(param_1 + 4));
        uVar1 = *(uint *)(param_1 + 4);
        puVar5 = puVar5 + uVar1;
        puVar3 = (undefined1 *)((longlong)puVar2 + (ulonglong)uVar1);
        ReverseMemCopy(puVar3,puVar5,uVar1);
        uVar1 = *(uint *)(param_1 + 4);
        ReverseMemCopy(puVar3 + uVar1,puVar5 + uVar1,uVar1);
      }
    }
  }
  else {
    uVar4 = 0x80090029;
    DebugTraceError(0x29,"Status",
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\translate\\bcrypttranslate.c",0x90);
  }
  return uVar4;
}



===== ConvertDsaPrivateBlobToLegacy @ 1800167c8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
ConvertDsaPrivateBlobToLegacy
          (longlong param_1,undefined8 param_2,undefined8 *param_3,ulonglong param_4,uint *param_5)

{
  uint uVar1;
  undefined1 *puVar2;
  undefined8 uVar3;
  undefined1 *puVar4;
  undefined1 auStack_88 [32];
  undefined8 local_68;
  undefined4 local_60;
  int iStack_5c;
  undefined8 uStack_58;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_88;
  if (*(int *)(param_1 + 4) - 0x40U < 0x41) {
    uVar3 = 0;
    uVar1 = *(int *)(param_1 + 4) * 3 + 0x5c;
    *param_5 = uVar1;
    if (param_3 != (undefined8 *)0x0) {
      if ((uint)param_4 < uVar1) {
        uVar3 = 0x80090028;
      }
      else {
        iStack_5c = *(int *)(param_1 + 4) << 3;
        uStack_58 = 0xa0;
        local_50 = 0xa0;
        local_68 = 0x220000000307;
        uStack_4c = 0;
        uStack_48 = 0;
        uStack_44 = 0;
        uStack_40 = 0;
        uStack_3c = 0;
        uStack_38 = 0;
        local_60 = 0x34535344;
        ReverseMemCopy((undefined1 *)&uStack_4c,(undefined1 *)(param_1 + 8),4);
        ReverseMemCopy((undefined1 *)&uStack_48,(undefined1 *)(param_1 + 0xc),0x14);
        memset(param_3,0,param_4 & 0xffffffff);
        *param_3 = local_68;
        param_3[1] = CONCAT44(iStack_5c,local_60);
        param_3[2] = uStack_58;
        param_3[3] = CONCAT44(uStack_4c,local_50);
        param_3[4] = CONCAT44(uStack_44,uStack_48);
        param_3[5] = CONCAT44(uStack_3c,uStack_40);
        *(undefined4 *)(param_3 + 6) = uStack_38;
        ReverseMemCopy((undefined1 *)((longlong)param_3 + 0x34),(undefined1 *)(param_1 + 0x34),
                       *(uint *)(param_1 + 4));
        puVar4 = (undefined1 *)((longlong)param_3 + 0x34) + *(uint *)(param_1 + 4);
        puVar2 = (undefined1 *)(param_1 + 0x34) + *(uint *)(param_1 + 4);
        ReverseMemCopy(puVar4,(undefined1 *)(param_1 + 0x20),0x14);
        puVar4 = puVar4 + 0x14;
        ReverseMemCopy(puVar4,puVar2,*(uint *)(param_1 + 4));
        uVar1 = *(uint *)(param_1 + 4);
        ReverseMemCopy(puVar4 + uVar1,puVar2 + uVar1,uVar1);
        ReverseMemCopy(puVar4 + uVar1 + *(uint *)(param_1 + 4),
                       puVar2 + uVar1 + *(uint *)(param_1 + 4),0x14);
      }
    }
  }
  else {
    uVar3 = 0x80090029;
    DebugTraceError(0x29,"Status",
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\translate\\bcrypttranslate.c",0x81);
  }
  return uVar3;
}



===== ConvertDsaPrivateBlobToLegacyV2 @ 18001697c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
ConvertDsaPrivateBlobToLegacyV2
          (longlong param_1,undefined8 param_2,undefined8 *param_3,uint param_4,uint *param_5)

{
  undefined1 *puVar1;
  undefined8 uVar2;
  undefined1 *puVar3;
  uint uVar4;
  longlong lVar5;
  undefined1 auStack_78 [32];
  undefined8 local_58;
  undefined4 local_50;
  int iStack_4c;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_78;
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  if (*(int *)(param_1 + 4) - 0x40U < 0x41) {
    uVar2 = 0;
    uVar4 = *(int *)(param_1 + 4) * 2 + 0x50;
    *param_5 = uVar4;
    if (param_3 != (undefined8 *)0x0) {
      if (param_4 < uVar4) {
        uVar2 = 0x80090028;
      }
      else {
        iStack_4c = *(int *)(param_1 + 4) << 3;
        local_58 = 0x220000000207;
        local_50 = 0x32535344;
        memset(param_3,0,(ulonglong)param_4);
        *param_3 = local_58;
        param_3[1] = CONCAT44(iStack_4c,local_50);
        ReverseMemCopy((undefined1 *)(param_3 + 2),(undefined1 *)(param_1 + 0x34),
                       *(uint *)(param_1 + 4));
        puVar3 = (undefined1 *)((longlong)(param_3 + 2) + (ulonglong)*(uint *)(param_1 + 4));
        lVar5 = 0x14;
        puVar1 = (undefined1 *)(param_1 + 0x34) + *(uint *)(param_1 + 4);
        ReverseMemCopy(puVar3,(undefined1 *)(param_1 + 0x20),0x14);
        puVar3 = puVar3 + lVar5;
        ReverseMemCopy(puVar3,puVar1,*(uint *)(param_1 + 4));
        puVar3 = puVar3 + *(uint *)(param_1 + 4);
        uVar4 = (uint)lVar5;
        ReverseMemCopy(puVar3,puVar1 + (ulonglong)*(uint *)(param_1 + 4) * 2,uVar4);
        ReverseMemCopy((undefined1 *)&local_48,(undefined1 *)(param_1 + 8),uVar4 - 0x10);
        ReverseMemCopy((undefined1 *)((longlong)&local_48 + 4),(undefined1 *)(param_1 + 0xc),uVar4);
        *(undefined8 *)(puVar3 + 0x14) = local_48;
        *(undefined8 *)(puVar3 + 0x1c) = uStack_40;
        *(undefined8 *)(puVar3 + 0x24) = local_38;
      }
    }
  }
  else {
    uVar2 = 0x80090029;
  }
  return uVar2;
}



===== ConvertDsaPublicBlobToLegacy @ 180016ae4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
ConvertDsaPublicBlobToLegacy
          (longlong param_1,undefined8 param_2,undefined8 *param_3,uint param_4,uint *param_5)

{
  uint uVar1;
  undefined8 uVar2;
  undefined1 *puVar3;
  undefined8 *puVar4;
  undefined1 *puVar5;
  undefined1 auStack_78 [32];
  undefined8 local_58;
  undefined4 local_50;
  int iStack_4c;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_78;
  if (*(int *)(param_1 + 4) - 0x40U < 0x41) {
    uVar2 = 0;
    uVar1 = *(int *)(param_1 + 4) * 3 + 0x44;
    *param_5 = uVar1;
    if (param_3 != (undefined8 *)0x0) {
      if (param_4 < uVar1) {
        uVar2 = 0x80090028;
      }
      else {
        memset(param_3,0,(ulonglong)param_4);
        iStack_4c = *(int *)(param_1 + 4) << 3;
        puVar4 = param_3 + 6;
        puVar3 = (undefined1 *)(param_1 + 0x34);
        local_58 = 0x220000000306;
        local_40 = 0;
        uStack_38 = 0;
        local_30 = 0;
        local_50 = 0x33535344;
        uStack_48 = 0xa0;
        ReverseMemCopy((undefined1 *)&local_40,(undefined1 *)(param_1 + 8),4);
        ReverseMemCopy((undefined1 *)((longlong)&local_40 + 4),(undefined1 *)(param_1 + 0xc),0x14);
        *param_3 = local_58;
        param_3[1] = CONCAT44(iStack_4c,local_50);
        param_3[2] = uStack_48;
        param_3[3] = local_40;
        param_3[4] = uStack_38;
        param_3[5] = local_30;
        ReverseMemCopy((undefined1 *)puVar4,puVar3,*(uint *)(param_1 + 4));
        puVar5 = (undefined1 *)((longlong)puVar4 + (ulonglong)*(uint *)(param_1 + 4));
        puVar3 = puVar3 + *(uint *)(param_1 + 4);
        ReverseMemCopy(puVar5,(undefined1 *)(param_1 + 0x20),0x14);
        puVar5 = puVar5 + 0x14;
        ReverseMemCopy(puVar5,puVar3,*(uint *)(param_1 + 4));
        uVar1 = *(uint *)(param_1 + 4);
        ReverseMemCopy(puVar5 + uVar1,puVar3 + uVar1,uVar1);
      }
    }
  }
  else {
    uVar2 = 0x80090029;
    DebugTraceError(0x29,"Status",
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\translate\\bcrypttranslate.c",0xf8);
  }
  return uVar2;
}



===== ConvertDsaPublicBlobToLegacyV2 @ 180016c64 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
ConvertDsaPublicBlobToLegacyV2
          (longlong param_1,undefined8 param_2,undefined8 *param_3,uint param_4,uint *param_5)

{
  uint uVar1;
  undefined1 *puVar2;
  undefined8 uVar3;
  undefined1 *puVar4;
  undefined8 *puVar5;
  undefined1 auStack_78 [32];
  undefined8 local_58;
  undefined4 local_50;
  int iStack_4c;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_78;
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  if (*(int *)(param_1 + 4) - 0x40U < 0x41) {
    uVar3 = 0;
    uVar1 = (*(int *)(param_1 + 4) + 0x14) * 3;
    *param_5 = uVar1;
    if (param_3 != (undefined8 *)0x0) {
      if (param_4 < uVar1) {
        uVar3 = 0x80090028;
      }
      else {
        iStack_4c = *(int *)(param_1 + 4) << 3;
        local_58 = 0x220000000206;
        local_50 = 0x31535344;
        memset(param_3,0,(ulonglong)param_4);
        *param_3 = local_58;
        param_3[1] = CONCAT44(iStack_4c,local_50);
        ReverseMemCopy((undefined1 *)(param_3 + 2),(undefined1 *)(param_1 + 0x34),
                       *(uint *)(param_1 + 4));
        puVar4 = (undefined1 *)((longlong)(param_3 + 2) + (ulonglong)*(uint *)(param_1 + 4));
        puVar2 = (undefined1 *)(param_1 + 0x34) + *(uint *)(param_1 + 4);
        ReverseMemCopy(puVar4,(undefined1 *)(param_1 + 0x20),0x14);
        puVar4 = puVar4 + 0x14;
        ReverseMemCopy(puVar4,puVar2,*(uint *)(param_1 + 4));
        uVar1 = *(uint *)(param_1 + 4);
        ReverseMemCopy(puVar4 + uVar1,puVar2 + uVar1,uVar1);
        puVar5 = (undefined8 *)(puVar4 + uVar1 + *(uint *)(param_1 + 4));
        ReverseMemCopy((undefined1 *)&local_48,(undefined1 *)(param_1 + 8),4);
        ReverseMemCopy((undefined1 *)((longlong)&local_48 + 4),(undefined1 *)(param_1 + 0xc),0x14);
        *puVar5 = local_48;
        puVar5[1] = uStack_40;
        puVar5[2] = local_38;
      }
    }
  }
  else {
    uVar3 = 0x80090029;
    DebugTraceError(0x29,"Status",
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\translate\\bcrypttranslate.c",0x1b);
  }
  return uVar3;
}



===== ConvertFullRsaToLegacy @ 180016dec =====

ulonglong ConvertFullRsaToLegacy
                    (longlong param_1,uint param_2,undefined4 *param_3,uint param_4,uint *param_5,
                    undefined4 param_6)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined1 *puVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined4 *puVar8;
  undefined1 *puVar9;
  ulonglong uVar10;
  
  uVar1 = *(uint *)(param_1 + 8);
  if (((uVar1 < 5) && (uVar2 = *(uint *)(param_1 + 4), uVar2 - 0x100 < 0x3f01)) &&
     ((uVar2 & 7) == 0)) {
    uVar3 = *(uint *)(param_1 + 0xc);
    uVar4 = uVar3 + 1 >> 1;
    if ((*(uint *)(param_1 + 0x10) == uVar4) && (*(uint *)(param_1 + 0x14) == uVar4)) {
      uVar10 = 0;
      uVar6 = (uVar4 + 4) * 5 + uVar3 * 2;
      *param_5 = uVar6;
      if (param_3 != (undefined4 *)0x0) {
        if (param_4 < uVar6) {
          uVar10 = 0x80090028;
        }
        else if (param_2 < uVar1 + uVar4 * 5 + (uVar3 + 0xc) * 2) {
          uVar10 = 0x80090027;
        }
        else {
          param_3[1] = param_6;
          *param_3 = 0x207;
          puVar8 = param_3 + 5;
          param_3[3] = uVar2;
          param_3[4] = 0;
          param_3[2] = 0x32415352;
          ReverseMemCopy((undefined1 *)(param_3 + 4),(undefined1 *)(param_1 + 0x18),
                         *(uint *)(param_1 + 8));
          puVar5 = (undefined1 *)(param_1 + 0x18) + *(uint *)(param_1 + 8);
          ReverseMemCopy((undefined1 *)puVar8,puVar5,uVar3);
          puVar5 = puVar5 + uVar3;
          puVar9 = (undefined1 *)((longlong)puVar8 + (ulonglong)uVar3);
          ReverseMemCopy(puVar9,puVar5,uVar4);
          uVar7 = (ulonglong)uVar4;
          puVar5 = puVar5 + uVar7;
          puVar9 = puVar9 + uVar7;
          ReverseMemCopy(puVar9,puVar5,uVar4);
          puVar5 = puVar5 + uVar7;
          puVar9 = puVar9 + uVar7;
          ReverseMemCopy(puVar9,puVar5,uVar4);
          puVar5 = puVar5 + uVar7;
          puVar9 = puVar9 + uVar7;
          ReverseMemCopy(puVar9,puVar5,uVar4);
          puVar9 = puVar9 + uVar7;
          ReverseMemCopy(puVar9,puVar5 + uVar7,uVar4);
          ReverseMemCopy(puVar9 + uVar4,puVar5 + uVar7 + uVar4,uVar3);
        }
      }
      goto LAB_180016f6a;
    }
  }
  uVar10 = 0x80090029;
LAB_180016f6a:
  return uVar10 & 0xffffffff;
}



===== ConvertLegacyDhPrivateBlob @ 180016f90 =====

ulonglong ConvertLegacyDhPrivateBlob
                    (undefined8 *param_1,uint param_2,undefined4 *param_3,uint param_4,uint *param_5
                    )

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  undefined1 uVar5;
  uint uVar6;
  undefined1 uVar7;
  undefined1 *puVar8;
  undefined4 *puVar9;
  undefined1 *puVar10;
  char cStack0000000000000031;
  int iStack0000000000000034;
  int iStack_50;
  int iStack_4c;
  int local_48;
  
  uVar4 = VerifyLegacyDhPrivateBlob(param_1,param_2);
  if ((int)uVar4 != 0) {
    DebugTraceError((char)uVar4,"Status",
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\translate\\bcrypttranslate.c",0xd1);
    return uVar4 & 0xffffffff;
  }
  if ((param_1 == (undefined8 *)0x0) || (param_2 < 0x34)) {
    uVar4 = 0x80090027;
    uVar7 = 0xd9;
    uVar5 = 0x27;
  }
  else {
    uVar2 = *param_1;
    if ((char)uVar2 == '\a') {
      cStack0000000000000031 = (char)((ulonglong)uVar2 >> 8);
      if ((cStack0000000000000031 == '\x03') &&
         (iStack0000000000000034 = (int)((ulonglong)uVar2 >> 0x20),
         iStack0000000000000034 - 0xaa01U < 2)) {
        uVar2 = param_1[2];
        uVar3 = param_1[3];
        uVar1 = (uint)((ulonglong)param_1[1] >> 0x23);
        uVar6 = uVar1 * 4 + 8;
        *param_5 = uVar6;
        if (param_3 == (undefined4 *)0x0) {
          return 0;
        }
        if (param_4 < uVar6) {
          return 0x80090028;
        }
        memset(param_3,0,(ulonglong)param_4);
        puVar8 = (undefined1 *)((longlong)param_1 + 0x34);
        *param_3 = 0x56504844;
        puVar9 = param_3 + 2;
        param_3[1] = uVar1;
        ReverseMemCopy((undefined1 *)puVar9,puVar8,uVar1);
        uVar1 = param_3[1];
        iStack_50 = (int)uVar2;
        iStack_4c = (int)((ulonglong)uVar2 >> 0x20);
        puVar10 = (undefined1 *)((longlong)puVar9 + (ulonglong)uVar1);
        puVar8 = puVar8 + (ulonglong)(iStack_50 + 7U >> 3) + (ulonglong)uVar1;
        ReverseMemCopy(puVar10,puVar8,uVar1);
        uVar1 = param_3[1];
        puVar10 = puVar10 + uVar1;
        puVar8 = puVar8 + ((iStack_4c + 7U >> 3) + uVar1);
        ReverseMemCopy(puVar10,puVar8,uVar1);
        uVar1 = param_3[1];
        local_48 = (int)uVar3;
        uVar6 = local_48 + 7U >> 3;
        ReverseMemCopy(puVar10 + (ulonglong)(uVar1 - uVar6) + (ulonglong)uVar1,puVar8 + uVar1,uVar6)
        ;
        return 0;
      }
      uVar7 = 0xef;
    }
    else {
      uVar7 = 0xe7;
    }
    uVar5 = 3;
    uVar4 = 0x80090003;
  }
  DebugTraceError(uVar5,"Status",
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\translate\\bcrypttranslate.c",uVar7);
  return uVar4;
}



===== ConvertLegacyDsaPrivateBlob @ 18001717c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong ConvertLegacyDsaPrivateBlob
                    (undefined8 *param_1,uint param_2,undefined4 *param_3,uint param_4,uint *param_5
                    )

{
  uint uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 *puVar6;
  undefined4 *puVar7;
  undefined1 *puVar8;
  uint uVar9;
  longlong lVar10;
  undefined1 auStack_98 [32];
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined4 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_98;
  uVar3 = VerifyLegacyDsaPrivateBlob(param_1,param_2);
  if ((int)uVar3 != 0) {
    DebugTraceError((char)uVar3,"Status",
                    "onecore\\ds\\security\\cryptoapi\\ncrypt\\translate\\bcrypttranslate.c",0x3e);
    return uVar3 & 0xffffffff;
  }
  if ((param_1 == (undefined8 *)0x0) || (param_2 < 0x34)) {
    uVar3 = 0x80090027;
    uVar5 = 0x46;
    uVar4 = 0x27;
  }
  else {
    uVar2 = *param_1;
    if ((char)uVar2 == '\a') {
      local_78._1_1_ = (char)((ulonglong)uVar2 >> 8);
      if ((local_78._1_1_ == '\x03') &&
         (local_78._4_4_ = (int)((ulonglong)uVar2 >> 0x20), local_78._4_4_ == 0x2200)) {
        local_78 = param_1[1];
        uStack_70 = param_1[2];
        local_40 = *(undefined4 *)(param_1 + 6);
        local_58 = param_1[3];
        uStack_50 = param_1[4];
        local_48 = param_1[5];
        uVar1 = (uint)((ulonglong)local_78 >> 0x23);
        uVar9 = (uVar1 + 0x18) * 3;
        *param_5 = uVar9;
        if (param_3 == (undefined4 *)0x0) {
          return 0;
        }
        if (param_4 < uVar9) {
          return 0x80090028;
        }
        local_68 = local_78;
        uStack_60 = uStack_70;
        memset(param_3,0,(ulonglong)param_4);
        *param_3 = 0x56505344;
        param_3[1] = uVar1;
        ReverseMemCopy((undefined1 *)(param_3 + 2),(undefined1 *)((longlong)&local_58 + 4),4);
        lVar10 = 0x14;
        ReverseMemCopy((undefined1 *)(param_3 + 3),(undefined1 *)&uStack_50,0x14);
        puVar6 = (undefined1 *)((longlong)param_1 + 0x34);
        puVar7 = param_3 + 0xd;
        ReverseMemCopy((undefined1 *)puVar7,puVar6,param_3[1]);
        puVar6 = puVar6 + (uint)param_3[1];
        puVar8 = (undefined1 *)((longlong)puVar7 + (ulonglong)(uint)param_3[1]);
        ReverseMemCopy((undefined1 *)(param_3 + 8),puVar6,(uint)lVar10);
        puVar6 = puVar6 + lVar10;
        ReverseMemCopy(puVar8,puVar6,param_3[1]);
        uVar9 = (uint)lVar10;
        uVar1 = param_3[1];
        puVar8 = puVar8 + uVar1;
        puVar6 = puVar6 + ((uStack_70._4_4_ + 7U >> 3) + uVar1);
        ReverseMemCopy(puVar8,puVar6,uVar1);
        ReverseMemCopy(puVar8 + (uint)param_3[1],puVar6 + (uint)param_3[1],uVar9);
        return 0;
      }
      uVar5 = 0x5c;
    }
    else {
      uVar5 = 0x54;
    }
    uVar4 = 3;
    uVar3 = 0x80090003;
    local_78 = uVar2;
  }
  DebugTraceError(uVar4,"Status",
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\translate\\bcrypttranslate.c",uVar5);
  return uVar3;
}



===== ConvertLegacyDsaV2PrivateBlob @ 180017398 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
ConvertLegacyDsaV2PrivateBlob
          (undefined8 *param_1,uint param_2,undefined4 *param_3,uint param_4,uint *param_5)

{
  undefined8 *puVar1;
  uint uVar2;
  undefined8 uVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined4 uVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 uVar9;
  undefined1 auStack_68 [32];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_68;
  uVar6 = 0;
  if (param_1 == (undefined8 *)0x0) {
    uVar9 = 99;
    uVar6 = 0x80090027;
    goto LAB_180017569;
  }
  if (((((param_2 < 0x10) || (uVar3 = *param_1, (char)uVar3 != '\a')) ||
       ((char)((ulonglong)uVar3 >> 8) != '\x02')) ||
      (((short)((ulonglong)uVar3 >> 0x10) != 0 || ((int)((ulonglong)uVar3 >> 0x20) != 0x2200)))) ||
     (uVar5 = param_1[1], (int)uVar5 != 0x32535344)) {
LAB_18001755e:
    uVar6 = 0x80090005;
  }
  else {
    uVar2 = (uint)(uVar5 >> 0x20);
    if ((uVar2 - 0x200 < 0xa01) && ((uVar5 >> 0x20 & 0x3f) == 0)) {
      if ((uVar2 >> 3) * 2 + 0x50 <= param_2) {
        uVar2 = uVar2 >> 3;
        uVar4 = (uVar2 + 0x18) * 3;
        *param_5 = uVar4;
        if (param_3 != (undefined4 *)0x0) {
          if (param_4 < uVar4) {
            uVar6 = 0x80090028;
          }
          else {
            uVar5 = (ulonglong)(uVar2 * 2 + 0x38);
            puVar1 = (undefined8 *)(uVar5 + (longlong)param_1);
            local_48 = *puVar1;
            uStack_40 = puVar1[1];
            local_38 = *(undefined8 *)(uVar5 + 0x10 + (longlong)param_1);
            memset(param_3,0,(ulonglong)param_4);
            *param_3 = 0x56505344;
            param_3[1] = uVar2;
            ReverseMemCopy((undefined1 *)(param_3 + 2),(undefined1 *)&local_48,4);
            ReverseMemCopy((undefined1 *)(param_3 + 3),(undefined1 *)((longlong)&local_48 + 4),0x14)
            ;
            ReverseMemCopy((undefined1 *)(param_3 + 0xd),(undefined1 *)(param_1 + 2),param_3[1]);
            puVar8 = (undefined1 *)((longlong)(param_1 + 2) + (ulonglong)(uint)param_3[1]);
            puVar7 = (undefined1 *)((longlong)(param_3 + 0xd) + (ulonglong)(uint)param_3[1]);
            ReverseMemCopy((undefined1 *)(param_3 + 8),puVar8,0x14);
            puVar8 = puVar8 + 0x14;
            ReverseMemCopy(puVar7,puVar8,param_3[1]);
            uVar2 = param_3[1];
            puVar7 = puVar7 + uVar2;
            memset(puVar7,0,(ulonglong)uVar2);
            ReverseMemCopy(puVar7 + (uint)param_3[1],puVar8 + uVar2,0x14);
          }
        }
        return uVar6;
      }
      goto LAB_18001755e;
    }
    uVar6 = 0x80090029;
  }
  uVar9 = 0x6e;
LAB_180017569:
  DebugTraceError((char)uVar6,"Status",
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\translate\\bcrypttranslate.c",uVar9);
  return uVar6;
}



===== ConvertLegacyRsaPrivateBlob @ 1800175a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
ConvertLegacyRsaPrivateBlob
          (char *param_1,uint param_2,undefined4 *param_3,uint param_4,uint *param_5)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  undefined4 *puVar8;
  undefined1 *puVar9;
  undefined1 auStack_68 [32];
  undefined8 local_48;
  uint local_40 [2];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_68;
  if ((((0x13 < param_2) && (*param_1 == '\a')) && (param_1[1] == '\x02')) &&
     (((*(short *)(param_1 + 2) == 0 && ((*(int *)(param_1 + 4) - 0x2400U & 0xffff7fff) == 0)) &&
      (*(int *)(param_1 + 8) == 0x32415352)))) {
    if (0x3f00 < *(int *)(param_1 + 0xc) - 0x100U) {
      uVar3 = 0x80090029;
      goto LAB_180017748;
    }
    if ((ulonglong)((*(int *)(param_1 + 0xc) + 0xfU >> 4) * 9) + 0x14 <= (ulonglong)param_2) {
      local_40[0] = *(uint *)(param_1 + 0x10);
      local_48 = *(undefined8 *)(param_1 + 8);
      iVar1 = (int)((ulonglong)local_48 >> 0x20);
      uVar4 = iVar1 + 7U >> 3;
      uVar5 = iVar1 + 0xfU >> 4;
      if ((local_40[0] & 0xff000000) == 0) {
        if ((local_40[0] & 0xff0000) == 0) {
          uVar6 = ((local_40[0] & 0xff00) != 0) + 1;
        }
        else {
          uVar6 = 3;
        }
      }
      else {
        uVar6 = 4;
      }
      uVar2 = uVar5 * 2 + 0x18 + uVar4 + uVar6;
      *param_5 = uVar2;
      if (param_3 != (undefined4 *)0x0) {
        if (param_4 < uVar2) {
          return 0x80090028;
        }
        memset(param_3,0,(ulonglong)param_4);
        puVar8 = param_3 + 6;
        *param_3 = 0x32415352;
        param_3[1] = iVar1;
        param_3[2] = uVar6;
        param_3[3] = uVar4;
        param_3[4] = uVar5;
        pcVar7 = param_1 + 0x14;
        param_3[5] = uVar5;
        ReverseMemCopy((undefined1 *)puVar8,(undefined1 *)local_40,uVar6);
        puVar9 = (undefined1 *)((longlong)puVar8 + (ulonglong)uVar6);
        ReverseMemCopy(puVar9,pcVar7,uVar4);
        pcVar7 = pcVar7 + uVar4;
        puVar9 = puVar9 + uVar4;
        ReverseMemCopy(puVar9,pcVar7,uVar5);
        ReverseMemCopy(puVar9 + uVar5,pcVar7 + uVar5,uVar5);
      }
      return 0;
    }
  }
  uVar3 = 0x80090005;
LAB_180017748:
  DebugTraceError((char)uVar3,"Status",
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\translate\\bcrypttranslate.c",0x20);
  return uVar3;
}



===== ConvertRsaPublicBlobToLegacy @ 18001778c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
ConvertRsaPublicBlobToLegacy
          (longlong param_1,undefined8 param_2,undefined8 *param_3,uint param_4,uint *param_5)

{
  uint uVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined4 local_20;
  int iStack_1c;
  undefined4 local_18 [2];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  if ((*(uint *)(param_1 + 8) < 5) && (uVar1 = *(uint *)(param_1 + 0xc), uVar1 < 0x801)) {
    if (uVar1 * 8 - 0x100 < 0x3f01) {
      *param_5 = uVar1 + 0x14;
      if (param_3 == (undefined8 *)0x0) {
        return 0;
      }
      if (param_4 < uVar1 + 0x14) {
        return 0x80090028;
      }
      iStack_1c = *(int *)(param_1 + 0xc) << 3;
      puVar3 = (undefined1 *)(param_1 + 0x18) + *(uint *)(param_1 + 8);
      local_28 = 0xa40000000206;
      local_18[0] = 0;
      local_20 = 0x31415352;
      ReverseMemCopy((undefined1 *)local_18,(undefined1 *)(param_1 + 0x18),*(uint *)(param_1 + 8));
      param_3[1] = CONCAT44(iStack_1c,local_20);
      *param_3 = local_28;
      *(undefined4 *)(param_3 + 2) = local_18[0];
      ReverseMemCopy((undefined1 *)((longlong)param_3 + 0x14),puVar3,*(uint *)(param_1 + 0xc));
      return 0;
    }
    uVar2 = 0xb8;
  }
  else {
    uVar2 = 0xad;
  }
  DebugTraceError(0x29,"Status",
                  "onecore\\ds\\security\\cryptoapi\\ncrypt\\translate\\bcrypttranslate.c",uVar2);
  return 0x80090029;
}



===== BcpIsValidImageReg @ 1800178ac =====

/* int __cdecl BcpIsValidImageReg(struct _CRYPT_IMAGE_REG * __ptr64) */

int __cdecl BcpIsValidImageReg(_CRYPT_IMAGE_REG *param_1)

{
  uint uVar1;
  PCRYPT_INTERFACE_REG *pp_Var2;
  int iVar3;
  ulonglong uVar4;
  PCRYPT_INTERFACE_REG p_Var5;
  
  if ((((param_1 != (_CRYPT_IMAGE_REG *)0x0) &&
       (iVar3 = BcpIsValidString((ushort *)param_1->pszImage), iVar3 != 0)) &&
      (uVar1 = param_1->cInterfaces, uVar1 != 0)) &&
     (pp_Var2 = param_1->rgpInterfaces, pp_Var2 != (PCRYPT_INTERFACE_REG *)0x0)) {
    uVar4 = 0;
    while( true ) {
      if (uVar1 <= (uint)uVar4) {
        return 1;
      }
      p_Var5 = pp_Var2[uVar4];
      if (((p_Var5 == (PCRYPT_INTERFACE_REG)0x0) ||
          (iVar3 = ValidateInterfaceId(p_Var5->dwInterface,0), iVar3 == 0)) ||
         ((p_Var5->cFunctions == 0 ||
          ((p_Var5->rgpszFunctions == (PWSTR *)0x0 ||
           (iVar3 = BcpIsValidStringArray((ushort **)p_Var5->rgpszFunctions,p_Var5->cFunctions),
           iVar3 == 0)))))) break;
      uVar4 = (ulonglong)((uint)uVar4 + 1);
    }
  }
  return 0;
}



===== BcpIsValidProviderReg @ 18001793c =====

/* int __cdecl BcpIsValidProviderReg(struct _CRYPT_PROVIDER_REG * __ptr64) */

int __cdecl BcpIsValidProviderReg(_CRYPT_PROVIDER_REG *param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 != (_CRYPT_PROVIDER_REG *)0x0) {
    if (param_1->cAliases == 0) {
      if (param_1->rgpszAliases != (PWSTR *)0x0) {
        return 0;
      }
    }
    else {
      iVar1 = BcpIsValidStringArray((ushort **)param_1->rgpszAliases,param_1->cAliases);
      if (iVar1 == 0) {
        return 0;
      }
    }
    if (param_1->pUM == (_CRYPT_IMAGE_REG *)0x0) {
      bVar2 = param_1->pKM == (PCRYPT_IMAGE_REG)0x0;
    }
    else {
      iVar1 = BcpIsValidImageReg(param_1->pUM);
      bVar2 = iVar1 == 0;
    }
    if (!bVar2) {
      if (param_1->pKM == (_CRYPT_IMAGE_REG *)0x0) {
        return 1;
      }
      iVar1 = BcpIsValidImageReg(param_1->pKM);
      return (uint)(iVar1 != 0);
    }
  }
  return 0;
}



===== BcpIsValidStringArray @ 1800179b4 =====

/* int __cdecl BcpIsValidStringArray(unsigned short * __ptr64 * __ptr64,unsigned long) */

int __cdecl BcpIsValidStringArray(ushort **param_1,ulong param_2)

{
  int iVar1;
  ulonglong uVar2;
  
  if (param_1 == (ushort **)0x0) {
LAB_1800179eb:
    iVar1 = 0;
  }
  else {
    for (uVar2 = 0; (uint)uVar2 < param_2; uVar2 = (ulonglong)((uint)uVar2 + 1)) {
      iVar1 = BcpIsValidString(param_1[uVar2]);
      if (iVar1 == 0) goto LAB_1800179eb;
    }
    iVar1 = 1;
  }
  return iVar1;
}



===== BCryptConfigureContext @ 180017a10 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

NTSTATUS __stdcall
BCryptConfigureContext(ULONG dwTable,LPCWSTR pszContext,PCRYPT_CONTEXT_CONFIG pConfig)

{
  ulong uVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  uchar *puVar5;
  ULONG UVar6;
  LPCWSTR pWVar7;
  PCRYPT_CONTEXT_CONFIG p_Var8;
  undefined1 auStackY_1b8 [32];
  ulong local_148 [4];
  uchar local_138 [256];
  ulonglong local_38;
  
                    /* 0x17a10  4  BCryptConfigureContext */
  local_38 = __security_cookie ^ (ulonglong)auStackY_1b8;
  puVar5 = local_138;
  local_148[0] = 0;
  pWVar7 = pszContext;
  p_Var8 = pConfig;
  UVar6 = dwTable;
  iVar2 = ValidateTableId(dwTable,(ulong)pszContext);
  if ((iVar2 == 0) || (p_Var8 == (_CRYPT_CONTEXT_CONFIG *)0x0)) {
    uVar3 = 0x57;
  }
  else {
    uVar3 = IoPack_Configuration_ParamBlock
                      (UVar6,(ushort *)pWVar7,0,(ushort *)0x0,(ushort *)0x0,(ushort *)0x0,0,p_Var8,
                       (_CRYPT_CONTEXT_FUNCTION_CONFIG *)0x0,0,(uchar *)0x0,(void *)0x0,local_148,
                       (uchar *)0x0);
    uVar1 = local_148[0];
    if (uVar3 == 0) {
      if (0x100 < local_148[0]) {
        puVar5 = (uchar *)BCryptAlloc((ulonglong)local_148[0]);
        if (puVar5 == (uchar *)0x0) {
          uVar3 = 8;
          goto LAB_180017b32;
        }
      }
      uVar3 = IoPack_Configuration_ParamBlock
                        (dwTable,(ushort *)pszContext,0,(ushort *)0x0,(ushort *)0x0,(ushort *)0x0,0,
                         pConfig,(_CRYPT_CONTEXT_FUNCTION_CONFIG *)0x0,0,(uchar *)0x0,(void *)0x0,
                         (ulong *)0x0,puVar5);
      if (uVar3 == 0) {
        lVar4 = IoCallKernelDriver(0x10003,puVar5,uVar1,(uchar *)0x0,(ulong *)0x0);
        goto LAB_180017b39;
      }
    }
  }
LAB_180017b32:
  lVar4 = WinErrorToNtStatus(uVar3);
LAB_180017b39:
  if ((puVar5 != (uchar *)0x0) && (puVar5 != local_138)) {
    BCryptFree((longlong)puVar5);
  }
  return lVar4;
}



===== BCryptConfigureContextFunction @ 180017b90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

NTSTATUS __stdcall
BCryptConfigureContextFunction
          (ULONG dwTable,LPCWSTR pszContext,ULONG dwInterface,LPCWSTR pszFunction,
          PCRYPT_CONTEXT_FUNCTION_CONFIG pConfig)

{
  ulong uVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  uchar *puVar5;
  ULONG UVar6;
  LPCWSTR pWVar7;
  undefined1 auStackY_218 [32];
  ulong local_1a8 [4];
  uchar local_198 [320];
  ulonglong local_58;
  
                    /* 0x17b90  5  BCryptConfigureContextFunction */
  local_58 = __security_cookie ^ (ulonglong)auStackY_218;
  puVar5 = local_198;
  local_1a8[0] = 0;
  pWVar7 = pszFunction;
  UVar6 = dwInterface;
  iVar2 = ValidateTableId(dwTable,(ulong)pszContext);
  if (iVar2 == 0) {
LAB_180017cd7:
    uVar3 = 0x57;
  }
  else {
    iVar2 = ValidateInterfaceId(UVar6,0);
    if (((iVar2 == 0) || (pWVar7 == (LPCWSTR)0x0)) || (*pWVar7 == L'\0')) goto LAB_180017cd7;
    uVar3 = IoPack_Configuration_ParamBlock
                      (dwTable,(ushort *)pszContext,UVar6,(ushort *)pWVar7,(ushort *)0x0,
                       (ushort *)0x0,0,(_CRYPT_CONTEXT_CONFIG *)0x0,pConfig,0,(uchar *)0x0,
                       (void *)0x0,local_1a8,(uchar *)0x0);
    uVar1 = local_1a8[0];
    if (uVar3 == 0) {
      if (0x140 < local_1a8[0]) {
        puVar5 = (uchar *)BCryptAlloc((ulonglong)local_1a8[0]);
        if (puVar5 == (uchar *)0x0) {
          uVar3 = 8;
          goto LAB_180017cdc;
        }
      }
      uVar3 = IoPack_Configuration_ParamBlock
                        (dwTable,(ushort *)pszContext,dwInterface,(ushort *)pszFunction,
                         (ushort *)0x0,(ushort *)0x0,0,(_CRYPT_CONTEXT_CONFIG *)0x0,pConfig,0,
                         (uchar *)0x0,(void *)0x0,(ulong *)0x0,puVar5);
      if (uVar3 == 0) {
        lVar4 = IoCallKernelDriver(0x10203,puVar5,uVar1,(uchar *)0x0,(ulong *)0x0);
        goto LAB_180017ce3;
      }
    }
  }
LAB_180017cdc:
  lVar4 = WinErrorToNtStatus(uVar3);
LAB_180017ce3:
  if ((puVar5 != (uchar *)0x0) && (puVar5 != local_198)) {
    BCryptFree((longlong)puVar5);
  }
  return lVar4;
}



===== BCryptDeleteContext @ 180017d30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

NTSTATUS __stdcall BCryptDeleteContext(ULONG dwTable,LPCWSTR pszContext)

{
  ulong uVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  uchar *puVar5;
  ULONG UVar6;
  LPCWSTR pWVar7;
  undefined1 auStackY_1a8 [32];
  ulong local_138 [4];
  uchar local_128 [256];
  ulonglong local_28;
  
                    /* 0x17d30  11  BCryptDeleteContext */
  local_28 = __security_cookie ^ (ulonglong)auStackY_1a8;
  puVar5 = local_128;
  local_138[0] = 0;
  pWVar7 = pszContext;
  UVar6 = dwTable;
  iVar2 = ValidateTableId(dwTable,(ulong)pszContext);
  if (((iVar2 == 0) || (pWVar7 == (LPCWSTR)0x0)) || (*pWVar7 == L'\0')) {
    uVar3 = 0x57;
  }
  else {
    uVar3 = IoPack_Configuration_ParamBlock
                      (UVar6,(ushort *)pWVar7,0,(ushort *)0x0,(ushort *)0x0,(ushort *)0x0,0,
                       (_CRYPT_CONTEXT_CONFIG *)0x0,(_CRYPT_CONTEXT_FUNCTION_CONFIG *)0x0,0,
                       (uchar *)0x0,(void *)0x0,local_138,(uchar *)0x0);
    uVar1 = local_138[0];
    if (uVar3 == 0) {
      if (0x100 < local_138[0]) {
        puVar5 = (uchar *)BCryptAlloc((ulonglong)local_138[0]);
        if (puVar5 == (uchar *)0x0) {
          uVar3 = 8;
          goto LAB_180017e5b;
        }
      }
      uVar3 = IoPack_Configuration_ParamBlock
                        (dwTable,(ushort *)pszContext,0,(ushort *)0x0,(ushort *)0x0,(ushort *)0x0,0,
                         (_CRYPT_CONTEXT_CONFIG *)0x0,(_CRYPT_CONTEXT_FUNCTION_CONFIG *)0x0,0,
                         (uchar *)0x0,(void *)0x0,(ulong *)0x0,puVar5);
      if (uVar3 == 0) {
        lVar4 = IoCallKernelDriver(0x10001,puVar5,uVar1,(uchar *)0x0,(ulong *)0x0);
        goto LAB_180017e62;
      }
    }
  }
LAB_180017e5b:
  lVar4 = WinErrorToNtStatus(uVar3);
LAB_180017e62:
  if ((puVar5 != (uchar *)0x0) && (puVar5 != local_128)) {
    BCryptFree((longlong)puVar5);
  }
  return lVar4;
}



===== BCryptEnumContexts @ 180017eb0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

NTSTATUS __stdcall BCryptEnumContexts(ULONG dwTable,ULONG *pcbBuffer,PCRYPT_CONTEXTS *ppBuffer)

{
  uint uVar1;
  PCRYPT_CONTEXTS p_Var2;
  ulong uVar3;
  int iVar4;
  ulong uVar5;
  long lVar6;
  uchar *puVar7;
  ULONG UVar8;
  ULONG *pUVar9;
  undefined1 auStackY_148 [32];
  ulong local_d8;
  int local_d4 [3];
  uchar local_c8 [128];
  ulonglong local_48;
  
                    /* 0x17eb0  25  BCryptEnumContexts */
  local_48 = __security_cookie ^ (ulonglong)auStackY_148;
  puVar7 = local_c8;
  lVar6 = 0;
  local_d8 = 0;
  local_d4[0] = 0;
  pUVar9 = pcbBuffer;
  UVar8 = dwTable;
  iVar4 = ValidateTableId(dwTable,(ulong)pcbBuffer);
  if ((iVar4 == 0) || (pUVar9 == (ULONG *)0x0)) {
    uVar5 = 0x57;
LAB_180018047:
    if (local_d4[0] != 0) {
      BCryptFree((longlong)*ppBuffer);
      *ppBuffer = (PCRYPT_CONTEXTS)0x0;
    }
    if (lVar6 < 0) goto LAB_180018066;
  }
  else {
    uVar5 = IoPack_Configuration_ParamBlock
                      (UVar8,(ushort *)0x0,0,(ushort *)0x0,(ushort *)0x0,(ushort *)0x0,0,
                       (_CRYPT_CONTEXT_CONFIG *)0x0,(_CRYPT_CONTEXT_FUNCTION_CONFIG *)0x0,0,
                       (uchar *)0x0,(void *)0x0,&local_d8,(uchar *)0x0);
    uVar3 = local_d8;
    if (uVar5 == 0) {
      if ((local_d8 < 0x81) ||
         (puVar7 = (uchar *)BCryptAlloc((ulonglong)local_d8), puVar7 != (uchar *)0x0)) {
        uVar5 = IoPack_Configuration_ParamBlock
                          (dwTable,(ushort *)0x0,0,(ushort *)0x0,(ushort *)0x0,(ushort *)0x0,0,
                           (_CRYPT_CONTEXT_CONFIG *)0x0,(_CRYPT_CONTEXT_FUNCTION_CONFIG *)0x0,0,
                           (uchar *)0x0,(void *)0x0,(ulong *)0x0,puVar7);
        if (uVar5 == 0) {
          pUVar9 = pcbBuffer;
          lVar6 = IoCallKernelDriverQueryLoop
                            (0x10002,puVar7,uVar3,(uchar **)ppBuffer,pcbBuffer,local_d4);
          if (-1 < lVar6) {
            p_Var2 = *ppBuffer;
            uVar1 = *pcbBuffer;
            if (p_Var2 == (PCRYPT_CONTEXTS)0x0) goto LAB_180018066;
            if ((p_Var2 + 1 < p_Var2) ||
               ((PCRYPT_CONTEXTS)((longlong)&p_Var2->cContexts + (ulonglong)uVar1) < p_Var2 + 1)) {
              uVar5 = 0x54f;
            }
            else {
              uVar5 = IoUnpack_SG_SzStringArray
                                ((ushort ***)&p_Var2->rgpszContexts,p_Var2->cContexts,
                                 (uchar *)p_Var2,uVar1,(uchar *)pUVar9);
              if ((uVar5 == 0) ||
                 (uVar5 = IoUnpack_SG_SzStringArray
                                    ((ushort ***)&p_Var2->rgpszContexts,p_Var2->cContexts,
                                     (uchar *)p_Var2,uVar1,(uchar *)pUVar9), uVar5 == 0))
              goto LAB_180018066;
            }
          }
          goto LAB_180018047;
        }
      }
      else {
        uVar5 = 8;
      }
    }
  }
  lVar6 = WinErrorToNtStatus(uVar5);
LAB_180018066:
  if ((puVar7 != (uchar *)0x0) && (puVar7 != local_c8)) {
    BCryptFree((longlong)puVar7);
  }
  if ((ppBuffer == (PCRYPT_CONTEXTS *)0x0) && (lVar6 == -0x3fffffdd)) {
    lVar6 = 0;
  }
  return lVar6;
}



===== BCryptEnumRegisteredProviders @ 1800180c0 =====

NTSTATUS __stdcall BCryptEnumRegisteredProviders(ULONG *pcbBuffer,PCRYPT_PROVIDERS *ppBuffer)

{
  uint uVar1;
  PCRYPT_PROVIDERS p_Var2;
  long lVar3;
  ulong uVar4;
  int local_res8 [2];
  ULONG *pUVar5;
  
                    /* 0x180c0  27  BCryptEnumRegisteredProviders */
  local_res8[0] = 0;
  uVar4 = 0;
  if (pcbBuffer == (ULONG *)0x0) {
    uVar4 = 0x57;
  }
  else {
    pUVar5 = pcbBuffer;
    lVar3 = IoCallKernelDriverQueryLoop(3,(uchar *)0x0,0,(uchar **)ppBuffer,pcbBuffer,local_res8);
    if (-1 < lVar3) {
      p_Var2 = *ppBuffer;
      uVar1 = *pcbBuffer;
      if (p_Var2 == (PCRYPT_PROVIDERS)0x0) {
        return lVar3;
      }
      if ((p_Var2 + 1 < p_Var2) ||
         ((PCRYPT_PROVIDERS)((longlong)&p_Var2->cProviders + (ulonglong)uVar1) < p_Var2 + 1)) {
        uVar4 = 0x54f;
      }
      else {
        uVar4 = IoUnpack_SG_SzStringArray
                          ((ushort ***)&p_Var2->rgpszProviders,p_Var2->cProviders,(uchar *)p_Var2,
                           uVar1,(uchar *)pUVar5);
        if (uVar4 == 0) {
          return lVar3;
        }
        uVar4 = IoUnpack_SG_SzStringArray
                          ((ushort ***)&p_Var2->rgpszProviders,p_Var2->cProviders,(uchar *)p_Var2,
                           uVar1,(uchar *)pUVar5);
        if (uVar4 == 0) {
          return lVar3;
        }
      }
    }
    if (local_res8[0] != 0) {
      BCryptFree((longlong)*ppBuffer);
      *ppBuffer = (PCRYPT_PROVIDERS)0x0;
    }
    if (lVar3 < 0) goto LAB_180018189;
  }
  lVar3 = WinErrorToNtStatus(uVar4);
LAB_180018189:
  if ((ppBuffer == (PCRYPT_PROVIDERS *)0x0) && (lVar3 == -0x3fffffdd)) {
    lVar3 = 0;
  }
  return lVar3;
}



===== BCryptQueryContextConfiguration @ 1800181c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

NTSTATUS __stdcall
BCryptQueryContextConfiguration
          (ULONG dwTable,LPCWSTR pszContext,ULONG *pcbBuffer,PCRYPT_CONTEXT_CONFIG *ppBuffer)

{
  PCRYPT_CONTEXT_CONFIG p_Var1;
  ulong uVar2;
  int iVar3;
  ulong uVar4;
  long lVar5;
  uchar *puVar6;
  ULONG UVar7;
  LPCWSTR pWVar8;
  ULONG *pUVar9;
  undefined1 auStackY_1d8 [32];
  ulong local_168;
  int local_164 [3];
  uchar local_158 [256];
  ulonglong local_58;
  
                    /* 0x181c0  44  BCryptQueryContextConfiguration */
  local_58 = __security_cookie ^ (ulonglong)auStackY_1d8;
  puVar6 = local_158;
  lVar5 = 0;
  local_168 = 0;
  local_164[0] = 0;
  pWVar8 = pszContext;
  pUVar9 = pcbBuffer;
  UVar7 = dwTable;
  iVar3 = ValidateTableId(dwTable,(ulong)pszContext);
  if ((iVar3 == 0) || (pUVar9 == (ULONG *)0x0)) {
    uVar4 = 0x57;
LAB_180018328:
    if (local_164[0] != 0) {
      BCryptFree((longlong)*ppBuffer);
      *ppBuffer = (PCRYPT_CONTEXT_CONFIG)0x0;
    }
    if (lVar5 < 0) goto LAB_180018347;
  }
  else {
    uVar4 = IoPack_Configuration_ParamBlock
                      (UVar7,(ushort *)pWVar8,0,(ushort *)0x0,(ushort *)0x0,(ushort *)0x0,0,
                       (_CRYPT_CONTEXT_CONFIG *)0x0,(_CRYPT_CONTEXT_FUNCTION_CONFIG *)0x0,0,
                       (uchar *)0x0,(void *)0x0,&local_168,(uchar *)0x0);
    uVar2 = local_168;
    if (uVar4 == 0) {
      if (0x100 < local_168) {
        puVar6 = (uchar *)BCryptAlloc((ulonglong)local_168);
        if (puVar6 == (uchar *)0x0) {
          uVar4 = 8;
          goto LAB_18001833e;
        }
      }
      uVar4 = IoPack_Configuration_ParamBlock
                        (dwTable,(ushort *)pszContext,0,(ushort *)0x0,(ushort *)0x0,(ushort *)0x0,0,
                         (_CRYPT_CONTEXT_CONFIG *)0x0,(_CRYPT_CONTEXT_FUNCTION_CONFIG *)0x0,0,
                         (uchar *)0x0,(void *)0x0,(ulong *)0x0,puVar6);
      if (uVar4 == 0) {
        lVar5 = IoCallKernelDriverQueryLoop
                          (0x10004,puVar6,uVar2,(uchar **)ppBuffer,pcbBuffer,local_164);
        if (-1 < lVar5) {
          p_Var1 = *ppBuffer;
          if ((p_Var1 == (PCRYPT_CONTEXT_CONFIG)0x0) ||
             ((p_Var1 <= p_Var1 + 1 &&
              (p_Var1 + 1 <=
               (PCRYPT_CONTEXT_CONFIG)((longlong)&p_Var1->dwFlags + (ulonglong)*pcbBuffer)))))
          goto LAB_180018347;
          uVar4 = 0x54f;
        }
        goto LAB_180018328;
      }
    }
  }
LAB_18001833e:
  lVar5 = WinErrorToNtStatus(uVar4);
LAB_180018347:
  if ((puVar6 != (uchar *)0x0) && (puVar6 != local_158)) {
    BCryptFree((longlong)puVar6);
  }
  if ((ppBuffer == (PCRYPT_CONTEXT_CONFIG *)0x0) && (lVar5 == -0x3fffffdd)) {
    lVar5 = 0;
  }
  return lVar5;
}



===== BCryptQueryContextFunctionConfiguration @ 1800183a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

NTSTATUS __stdcall
BCryptQueryContextFunctionConfiguration
          (ULONG dwTable,LPCWSTR pszContext,ULONG dwInterface,LPCWSTR pszFunction,ULONG *pcbBuffer,
          PCRYPT_CONTEXT_FUNCTION_CONFIG *ppBuffer)

{
  PCRYPT_CONTEXT_FUNCTION_CONFIG p_Var1;
  ulong uVar2;
  int iVar3;
  ulong uVar4;
  int iVar5;
  uchar *puVar6;
  ULONG UVar7;
  LPCWSTR pWVar8;
  undefined1 auStackY_218 [32];
  ulong local_1a8;
  int local_1a4;
  LPCWSTR local_1a0;
  uchar local_198 [320];
  ulonglong local_58;
  
                    /* 0x183a0  45  BCryptQueryContextFunctionConfiguration */
  local_58 = __security_cookie ^ (ulonglong)auStackY_218;
  puVar6 = local_198;
  iVar5 = 0;
  local_1a8 = 0;
  local_1a4 = 0;
  pWVar8 = pszFunction;
  UVar7 = dwInterface;
  local_1a0 = pszContext;
  iVar3 = ValidateTableId(dwTable,(ulong)pszContext);
  if ((((iVar3 == 0) || (iVar3 = ValidateInterfaceId(UVar7,0), iVar3 == 0)) ||
      (pWVar8 == (LPCWSTR)0x0)) || ((*pWVar8 == L'\0' || (pcbBuffer == (ULONG *)0x0)))) {
    uVar4 = 0x57;
LAB_1800185a1:
    if (local_1a4 != 0) {
      BCryptFree((longlong)*ppBuffer);
      *ppBuffer = (PCRYPT_CONTEXT_FUNCTION_CONFIG)0x0;
    }
    if (iVar5 < 0) goto LAB_1800184a9;
  }
  else {
    uVar4 = IoPack_Configuration_ParamBlock
                      (dwTable,(ushort *)pszContext,UVar7,(ushort *)pWVar8,(ushort *)0x0,
                       (ushort *)0x0,0,(_CRYPT_CONTEXT_CONFIG *)0x0,
                       (_CRYPT_CONTEXT_FUNCTION_CONFIG *)0x0,0,(uchar *)0x0,(void *)0x0,&local_1a8,
                       (uchar *)0x0);
    uVar2 = local_1a8;
    if (uVar4 == 0) {
      if ((local_1a8 < 0x141) ||
         (puVar6 = (uchar *)BCryptAlloc((ulonglong)local_1a8), puVar6 != (uchar *)0x0)) {
        uVar4 = IoPack_Configuration_ParamBlock
                          (dwTable,(ushort *)local_1a0,dwInterface,(ushort *)pszFunction,
                           (ushort *)0x0,(ushort *)0x0,0,(_CRYPT_CONTEXT_CONFIG *)0x0,
                           (_CRYPT_CONTEXT_FUNCTION_CONFIG *)0x0,0,(uchar *)0x0,(void *)0x0,
                           (ulong *)0x0,puVar6);
        if (uVar4 == 0) {
          iVar5 = IoCallKernelDriverQueryLoop
                            (0x10204,puVar6,uVar2,(uchar **)ppBuffer,pcbBuffer,&local_1a4);
          if (-1 < iVar5) {
            p_Var1 = *ppBuffer;
            if ((p_Var1 == (PCRYPT_CONTEXT_FUNCTION_CONFIG)0x0) ||
               ((p_Var1 <= p_Var1 + 1 &&
                (p_Var1 + 1 <=
                 (PCRYPT_CONTEXT_FUNCTION_CONFIG)
                 ((longlong)&p_Var1->dwFlags + (ulonglong)*pcbBuffer))))) goto LAB_1800184a9;
            uVar4 = 0x54f;
          }
          goto LAB_1800185a1;
        }
      }
      else {
        uVar4 = 8;
      }
    }
  }
  iVar5 = WinErrorToNtStatus(uVar4);
LAB_1800184a9:
  if ((puVar6 != (uchar *)0x0) && (puVar6 != local_198)) {
    BCryptFree((longlong)puVar6);
  }
  if (ppBuffer == (PCRYPT_CONTEXT_FUNCTION_CONFIG *)0x0) {
    if (iVar5 == -0x3fffffdd) {
      iVar5 = 0;
    }
  }
  return iVar5;
}



===== BCryptQueryContextFunctionProperty @ 1800185d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

NTSTATUS __stdcall
BCryptQueryContextFunctionProperty
          (ULONG dwTable,LPCWSTR pszContext,ULONG dwInterface,LPCWSTR pszFunction,
          LPCWSTR pszProperty,ULONG *pcbValue,PUCHAR *ppbValue)

{
  ulong uVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  uchar *puVar5;
  ULONG UVar6;
  LPCWSTR pWVar7;
  undefined1 auStackY_2a8 [32];
  ULONG *pUVar8;
  ulong local_238;
  int local_234;
  ULONG local_230;
  LPCWSTR local_228;
  uchar local_218 [448];
  ulonglong local_58;
  
                    /* 0x185d0  46  BCryptQueryContextFunctionProperty */
  local_58 = __security_cookie ^ (ulonglong)auStackY_2a8;
  puVar5 = local_218;
  lVar4 = 0;
  local_238 = 0;
  local_234 = 0;
  pWVar7 = pszFunction;
  UVar6 = dwInterface;
  local_230 = dwTable;
  local_228 = pszContext;
  iVar2 = ValidateTableId(dwTable,(ulong)pszContext);
  if ((((iVar2 == 0) || (iVar2 = ValidateInterfaceId(UVar6,0), iVar2 == 0)) ||
      (pWVar7 == (LPCWSTR)0x0)) ||
     (((*pWVar7 == L'\0' || (pszProperty == (LPCWSTR)0x0)) ||
      ((*pszProperty == L'\0' || (pcbValue == (ULONG *)0x0)))))) {
    uVar3 = 0x57;
LAB_18001878d:
    if (local_234 != 0) {
      BCryptFree((longlong)*ppbValue);
      *ppbValue = (PUCHAR)0x0;
    }
    if (lVar4 < 0) goto LAB_1800187ad;
  }
  else {
    uVar3 = IoPack_Configuration_ParamBlock
                      (dwTable,(ushort *)pszContext,UVar6,(ushort *)pWVar7,(ushort *)0x0,
                       (ushort *)pszProperty,0,(_CRYPT_CONTEXT_CONFIG *)0x0,
                       (_CRYPT_CONTEXT_FUNCTION_CONFIG *)0x0,0,(uchar *)0x0,(void *)0x0,&local_238,
                       (uchar *)0x0);
    uVar1 = local_238;
    if (uVar3 == 0) {
      if ((local_238 < 0x1c1) ||
         (puVar5 = (uchar *)BCryptAlloc((ulonglong)local_238), puVar5 != (uchar *)0x0)) {
        uVar3 = IoPack_Configuration_ParamBlock
                          (local_230,(ushort *)local_228,dwInterface,(ushort *)pszFunction,
                           (ushort *)0x0,(ushort *)pszProperty,0,(_CRYPT_CONTEXT_CONFIG *)0x0,
                           (_CRYPT_CONTEXT_FUNCTION_CONFIG *)0x0,0,(uchar *)0x0,(void *)0x0,
                           (ulong *)0x0,puVar5);
        if (uVar3 == 0) {
          pUVar8 = pcbValue;
          lVar4 = IoCallKernelDriverQueryLoop(0x10401,puVar5,uVar1,ppbValue,pcbValue,&local_234);
          if ((-1 < lVar4) &&
             (uVar3 = IoUnpack_SG_Buffer((uchar **)0x0,*pcbValue,*ppbValue,*pcbValue,(uchar *)pUVar8
                                        ), uVar3 == 0)) goto LAB_1800187ad;
          goto LAB_18001878d;
        }
      }
      else {
        uVar3 = 8;
      }
    }
  }
  lVar4 = WinErrorToNtStatus(uVar3);
LAB_1800187ad:
  if ((puVar5 != (uchar *)0x0) && (puVar5 != local_218)) {
    BCryptFree((longlong)puVar5);
  }
  if (((ppbValue == (PUCHAR *)0x0) && (lVar4 == -0x3fffffdd)) && (lVar4 = 0, *pcbValue < 8)) {
    *pcbValue = 8;
  }
  return lVar4;
}



===== BCryptRegisterConfigChangeNotify @ 180018810 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

NTSTATUS __stdcall BCryptRegisterConfigChangeNotify(HANDLE *phEvent)

{
  BOOL BVar1;
  long lVar2;
  HANDLE hProcess;
  _GUID *lpExeName;
  _GUID *lpdwSize;
  undefined1 auStackY_268 [32];
  _GUID local_238;
  _GUID local_228 [33];
  ulonglong local_18;
  
                    /* 0x18810  48  BCryptRegisterConfigChangeNotify */
  local_18 = __security_cookie ^ (ulonglong)auStackY_268;
  memset(local_228,0,0x20a);
  local_238.Data1 = 0x105;
  hProcess = GetCurrentProcess();
  lpdwSize = &local_238;
  lpExeName = local_228;
  BVar1 = QueryFullProcessImageNameW(hProcess,0,(LPWSTR)lpExeName,&lpdwSize->Data1);
  if (BVar1 == 0) {
    local_228[0].Data1._0_2_ = 0;
  }
  if (((5 < DAT_180025058) && ((_DAT_180025068 & 0x200000000000) != 0)) &&
     ((DAT_180025070 & 0x200000000000) == DAT_180025070)) {
    local_238.Data4 = (uchar  [8])local_228;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EventWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>_>
              ((_tlgProvider_t *)0x200000000000,&DAT_1800207dc,lpExeName,lpdwSize,
               (_tlgWrapSz<unsigned_short> *)local_238.Data4);
  }
  lVar2 = BcpRegisterConfigChangeNotifyNoLogging(phEvent);
  return lVar2;
}



===== BCryptRemoveContextFunction @ 180018900 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

NTSTATUS __stdcall
BCryptRemoveContextFunction(ULONG dwTable,LPCWSTR pszContext,ULONG dwInterface,LPCWSTR pszFunction)

{
  ulong uVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  uchar *puVar5;
  ULONG UVar6;
  LPCWSTR pWVar7;
  undefined1 auStackY_208 [32];
  ulong local_198 [4];
  uchar local_188 [320];
  ulonglong local_48;
  
                    /* 0x18900  50  BCryptRemoveContextFunction */
  local_48 = __security_cookie ^ (ulonglong)auStackY_208;
  puVar5 = local_188;
  local_198[0] = 0;
  pWVar7 = pszFunction;
  UVar6 = dwInterface;
  iVar2 = ValidateTableId(dwTable,(ulong)pszContext);
  if (iVar2 == 0) {
LAB_180018a3d:
    uVar3 = 0x57;
  }
  else {
    iVar2 = ValidateInterfaceId(UVar6,0);
    if (((iVar2 == 0) || (pWVar7 == (LPCWSTR)0x0)) || (*pWVar7 == L'\0')) goto LAB_180018a3d;
    uVar3 = IoPack_Configuration_ParamBlock
                      (dwTable,(ushort *)pszContext,UVar6,(ushort *)pWVar7,(ushort *)0x0,
                       (ushort *)0x0,0,(_CRYPT_CONTEXT_CONFIG *)0x0,
                       (_CRYPT_CONTEXT_FUNCTION_CONFIG *)0x0,0,(uchar *)0x0,(void *)0x0,local_198,
                       (uchar *)0x0);
    uVar1 = local_198[0];
    if (uVar3 == 0) {
      if (0x140 < local_198[0]) {
        puVar5 = (uchar *)BCryptAlloc((ulonglong)local_198[0]);
        if (puVar5 == (uchar *)0x0) {
          uVar3 = 8;
          goto LAB_180018a42;
        }
      }
      uVar3 = IoPack_Configuration_ParamBlock
                        (dwTable,(ushort *)pszContext,dwInterface,(ushort *)pszFunction,
                         (ushort *)0x0,(ushort *)0x0,0,(_CRYPT_CONTEXT_CONFIG *)0x0,
                         (_CRYPT_CONTEXT_FUNCTION_CONFIG *)0x0,0,(uchar *)0x0,(void *)0x0,
                         (ulong *)0x0,puVar5);
      if (uVar3 == 0) {
        lVar4 = IoCallKernelDriver(0x10201,puVar5,uVar1,(uchar *)0x0,(ulong *)0x0);
        goto LAB_180018a49;
      }
    }
  }
LAB_180018a42:
  lVar4 = WinErrorToNtStatus(uVar3);
LAB_180018a49:
  if ((puVar5 != (uchar *)0x0) && (puVar5 != local_188)) {
    BCryptFree((longlong)puVar5);
  }
  return lVar4;
}



===== BCryptRemoveContextFunctionProvider @ 180018a90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long BCryptRemoveContextFunctionProvider
               (ulong param_1,ushort *param_2,ulong param_3,ushort *param_4,ushort *param_5)

{
  ulong uVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  uchar *puVar5;
  ushort *puVar6;
  undefined1 auStackY_258 [32];
  ulong local_1e8 [4];
  uchar local_1d8 [384];
  ulonglong local_58;
  
                    /* 0x18a90  51  BCryptRemoveContextFunctionProvider */
  local_58 = __security_cookie ^ (ulonglong)auStackY_258;
  puVar5 = local_1d8;
  local_1e8[0] = 0;
  puVar6 = param_4;
  uVar3 = param_3;
  iVar2 = ValidateTableId(param_1,(ulong)param_2);
  if (iVar2 == 0) {
LAB_180018beb:
    uVar3 = 0x57;
  }
  else {
    iVar2 = ValidateInterfaceId(uVar3,0);
    if ((((iVar2 == 0) || (puVar6 == (ushort *)0x0)) || (*puVar6 == 0)) ||
       ((param_5 == (ushort *)0x0 || (*param_5 == 0)))) goto LAB_180018beb;
    uVar3 = IoPack_Configuration_ParamBlock
                      (param_1,param_2,uVar3,puVar6,param_5,(ushort *)0x0,0,
                       (_CRYPT_CONTEXT_CONFIG *)0x0,(_CRYPT_CONTEXT_FUNCTION_CONFIG *)0x0,0,
                       (uchar *)0x0,(void *)0x0,local_1e8,(uchar *)0x0);
    uVar1 = local_1e8[0];
    if (uVar3 == 0) {
      if (0x180 < local_1e8[0]) {
        puVar5 = (uchar *)BCryptAlloc((ulonglong)local_1e8[0]);
        if (puVar5 == (uchar *)0x0) {
          uVar3 = 8;
          goto LAB_180018bf0;
        }
      }
      uVar3 = IoPack_Configuration_ParamBlock
                        (param_1,param_2,param_3,param_4,param_5,(ushort *)0x0,0,
                         (_CRYPT_CONTEXT_CONFIG *)0x0,(_CRYPT_CONTEXT_FUNCTION_CONFIG *)0x0,0,
                         (uchar *)0x0,(void *)0x0,(ulong *)0x0,puVar5);
      if (uVar3 == 0) {
        lVar4 = IoCallKernelDriver(0x10301,puVar5,uVar1,(uchar *)0x0,(ulong *)0x0);
        goto LAB_180018bf7;
      }
    }
  }
LAB_180018bf0:
  lVar4 = WinErrorToNtStatus(uVar3);
LAB_180018bf7:
  if ((puVar5 != (uchar *)0x0) && (puVar5 != local_1d8)) {
    BCryptFree((longlong)puVar5);
  }
  return lVar4;
}



===== BCryptUnregisterConfigChangeNotify @ 180018c40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

NTSTATUS __stdcall BCryptUnregisterConfigChangeNotify(HANDLE hEvent)

{
  BOOL BVar1;
  long lVar2;
  HANDLE hProcess;
  _GUID *lpExeName;
  _GUID *lpdwSize;
  undefined1 auStackY_268 [32];
  _GUID local_238;
  _GUID local_228 [33];
  ulonglong local_18;
  
                    /* 0x18c40  58  BCryptUnregisterConfigChangeNotify */
  local_18 = __security_cookie ^ (ulonglong)auStackY_268;
  memset(local_228,0,0x20a);
  local_238.Data1 = 0x105;
  hProcess = GetCurrentProcess();
  lpdwSize = &local_238;
  lpExeName = local_228;
  BVar1 = QueryFullProcessImageNameW(hProcess,0,(LPWSTR)lpExeName,&lpdwSize->Data1);
  if (BVar1 == 0) {
    local_228[0].Data1._0_2_ = 0;
  }
  if (((5 < DAT_180025058) && ((_DAT_180025068 & 0x200000000000) != 0)) &&
     ((DAT_180025070 & 0x200000000000) == DAT_180025070)) {
    local_238.Data4 = (uchar  [8])local_228;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EventWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>_>
              ((_tlgProvider_t *)0x200000000000,&DAT_18002081e,lpExeName,lpdwSize,
               (_tlgWrapSz<unsigned_short> *)local_238.Data4);
  }
  lVar2 = BcpUnregisterConfigChangeNotifyNoLogging(hEvent);
  return lVar2;
}



===== BCryptUnregisterProvider @ 180018d30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long BCryptUnregisterProvider(ushort *param_1)

{
  ulong uVar1;
  long lVar2;
  uchar *puVar3;
  undefined1 auStackY_168 [32];
  ulong local_128 [4];
  uchar local_118 [256];
  ulonglong local_18;
  
                    /* 0x18d30  59  BCryptUnregisterProvider */
  local_18 = __security_cookie ^ (ulonglong)auStackY_168;
  puVar3 = local_118;
  local_128[0] = 0;
  if ((param_1 == (ushort *)0x0) || (*param_1 == 0)) {
    uVar1 = 0x57;
  }
  else {
    uVar1 = IoPack_Registration_ParamBlock
                      (param_1,0,0,0,(_CRYPT_PROVIDER_REG *)0x0,local_128,(uchar *)0x0);
    if (uVar1 == 0) {
      if (0x100 < local_128[0]) {
        puVar3 = (uchar *)BCryptAlloc((ulonglong)local_128[0]);
        if (puVar3 == (uchar *)0x0) {
          uVar1 = 8;
          goto LAB_180018dfb;
        }
      }
      uVar1 = IoPack_Registration_ParamBlock
                        (param_1,0,0,0,(_CRYPT_PROVIDER_REG *)0x0,(ulong *)0x0,puVar3);
      if (uVar1 == 0) {
        lVar2 = IoCallKernelDriver(1,puVar3,local_128[0],(uchar *)0x0,(ulong *)0x0);
        goto LAB_180018e02;
      }
    }
  }
LAB_180018dfb:
  lVar2 = WinErrorToNtStatus(uVar1);
LAB_180018e02:
  if ((puVar3 != (uchar *)0x0) && (puVar3 != local_118)) {
    BCryptFree((longlong)puVar3);
  }
  return lVar2;
}



===== BcpUnregisterConfigChangeNotifyNoLogging @ 180018e4c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long BcpUnregisterConfigChangeNotifyNoLogging(HANDLE param_1)

{
  ulong uVar1;
  long lVar2;
  uint uVar3;
  ulong uVar4;
  uchar *puVar5;
  undefined1 auStackY_118 [32];
  ulong local_a8 [4];
  uchar local_98 [128];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_118;
  lVar2 = 0;
  memset(local_98,0,0x80);
  local_a8[0] = 0;
  puVar5 = local_98;
  if (param_1 == (HANDLE)0x0) {
    uVar4 = 0x57;
  }
  else {
    uVar3 = g_TrustedEnvironment;
    if (g_TrustedEnvironment == 0) {
      uVar3 = GetTrustedEnvironment();
    }
    if ((uVar3 & 1) == 0) {
LAB_180018f99:
      CloseHandle(param_1);
      goto LAB_180018fa8;
    }
    uVar4 = IoPack_Configuration_ParamBlock
                      (0,(ushort *)0x0,0,(ushort *)0x0,(ushort *)0x0,(ushort *)0x0,0,
                       (_CRYPT_CONTEXT_CONFIG *)0x0,(_CRYPT_CONTEXT_FUNCTION_CONFIG *)0x0,0,
                       (uchar *)0x0,param_1,local_a8,(uchar *)0x0);
    uVar1 = local_a8[0];
    if (uVar4 == 0) {
      if (0x80 < local_a8[0]) {
        puVar5 = (uchar *)BCryptAlloc((ulonglong)local_a8[0]);
        if (puVar5 == (uchar *)0x0) {
          uVar4 = 8;
          goto LAB_180018ea4;
        }
      }
      uVar4 = IoPack_Configuration_ParamBlock
                        (0,(ushort *)0x0,0,(ushort *)0x0,(ushort *)0x0,(ushort *)0x0,0,
                         (_CRYPT_CONTEXT_CONFIG *)0x0,(_CRYPT_CONTEXT_FUNCTION_CONFIG *)0x0,0,
                         (uchar *)0x0,param_1,(ulong *)0x0,puVar5);
      if (uVar4 == 0) {
        lVar2 = IoCallKernelDriver(0x10501,puVar5,uVar1,(uchar *)0x0,(ulong *)0x0);
        if (lVar2 < 0) goto LAB_180018fa8;
        goto LAB_180018f99;
      }
    }
  }
LAB_180018ea4:
  lVar2 = WinErrorToNtStatus(uVar4);
LAB_180018fa8:
  if ((puVar5 != (uchar *)0x0) && (puVar5 != local_98)) {
    BCryptFree((longlong)puVar5);
  }
  return lVar2;
}



===== UninitializeConfig @ 180018ff4 =====

void UninitializeConfig(void)

{
  REGHANDLE RegHandle;
  uint uVar1;
  
  uVar1 = g_TrustedEnvironment;
  if (g_TrustedEnvironment == 0) {
    uVar1 = GetTrustedEnvironment();
  }
  RegHandle = DAT_180025078;
  if ((uVar1 & 1) == 0) {
    DAT_180025078 = 0;
    DAT_180025058 = 0;
    EventUnregister(RegHandle);
  }
  else {
    TlgUnregisterAggregateProvider();
  }
  IoShutdown();
  return;
}



===== IoCopy_ImageReg @ 180019050 =====

/* unsigned long __cdecl IoCopy_ImageReg(struct _CRYPT_IMAGE_REG * __ptr64,unsigned long,unsigned
   long * __ptr64,unsigned char * __ptr64) */

ulong __cdecl IoCopy_ImageReg(_CRYPT_IMAGE_REG *param_1,ulong param_2,ulong *param_3,uchar *param_4)

{
  PWSTR pWVar1;
  ulong uVar2;
  uchar *puVar3;
  uchar *puVar4;
  uint uVar5;
  uchar *puVar6;
  ulong local_res8 [2];
  ulong local_res10 [2];
  
  local_res10[0] = 0;
  local_res8[0] = 0;
  if (param_3 != (ulong *)0x0) {
    *param_3 = 0;
  }
  pWVar1 = param_1->pszImage;
  if ((((pWVar1 == (PWSTR)0x0) || (*pWVar1 == L'\0')) ||
      (param_1->rgpInterfaces == (PCRYPT_INTERFACE_REG *)0x0)) || (param_1->cInterfaces == 0)) {
    uVar2 = 0x57;
  }
  else {
    puVar6 = (uchar *)(-(ulonglong)(param_4 != (uchar *)0x0) & (ulonglong)(param_4 + 0x18));
    puVar4 = puVar6;
    uVar2 = IoCopy_SzString((ushort *)pWVar1,local_res10,puVar6);
    if (uVar2 == 0) {
      uVar5 = local_res10[0] + 0x18;
      if (param_4 == (uchar *)0x0) {
        puVar3 = (uchar *)0x0;
      }
      else {
        puVar3 = param_4 + uVar5;
      }
      IoCopy_InterfaceRegArray
                (param_1->rgpInterfaces,param_1->cInterfaces,(ulong)puVar4,local_res8,puVar3);
      if (param_4 != (uchar *)0x0) {
        *(uchar **)param_4 = puVar6;
        *(uchar **)(param_4 + 0x10) = puVar3;
        *(ULONG *)(param_4 + 8) = param_1->cInterfaces;
      }
      if (param_3 != (ulong *)0x0) {
        *param_3 = uVar5 + local_res8[0];
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}



===== IoCopy_ImageRegs @ 18001913c =====

/* unsigned long __cdecl IoCopy_ImageRegs(struct _CRYPT_IMAGE_REG * __ptr64,struct _CRYPT_IMAGE_REG
   * __ptr64,unsigned char * __ptr64 * __ptr64,unsigned char * __ptr64 * __ptr64,unsigned long *
   __ptr64,unsigned char * __ptr64) */

ulong __cdecl
IoCopy_ImageRegs(_CRYPT_IMAGE_REG *param_1,_CRYPT_IMAGE_REG *param_2,uchar **param_3,uchar **param_4
                ,ulong *param_5,uchar *param_6)

{
  ulong uVar1;
  ulong uVar2;
  uchar *puVar3;
  ulong local_res8 [2];
  
  uVar2 = (ulong)param_2;
  local_res8[0] = 0;
  if (param_5 != (ulong *)0x0) {
    *param_5 = 0;
  }
  if (param_3 != (uchar **)0x0) {
    *param_3 = (uchar *)0x0;
  }
  if (param_4 != (uchar **)0x0) {
    *param_4 = (uchar *)0x0;
  }
  if (param_1 == (_CRYPT_IMAGE_REG *)0x0) {
    if (param_2 == (_CRYPT_IMAGE_REG *)0x0) {
      return 0x57;
    }
  }
  else {
    puVar3 = (uchar *)(-(ulonglong)(param_6 != (uchar *)0x0) & (ulonglong)param_6);
    uVar1 = IoCopy_ImageReg(param_1,uVar2,local_res8,puVar3);
    if (uVar1 != 0) {
      return uVar1;
    }
    if (param_3 != (uchar **)0x0) {
      *param_3 = puVar3;
    }
    if (param_2 == (_CRYPT_IMAGE_REG *)0x0) goto LAB_1800191ef;
  }
  uVar1 = local_res8[0];
  if (param_6 == (uchar *)0x0) {
    puVar3 = (uchar *)0x0;
  }
  else {
    puVar3 = param_6 + local_res8[0];
  }
  uVar2 = IoCopy_ImageReg(param_2,uVar2,local_res8,puVar3);
  if (uVar2 != 0) {
    return uVar2;
  }
  if (param_4 != (uchar **)0x0) {
    *param_4 = puVar3;
  }
  local_res8[0] = uVar1 + local_res8[0];
LAB_1800191ef:
  if (param_5 != (ulong *)0x0) {
    *param_5 = local_res8[0];
  }
  return 0;
}



===== IoCopy_InterfaceReg @ 180019214 =====

/* unsigned long __cdecl IoCopy_InterfaceReg(struct _CRYPT_INTERFACE_REG * __ptr64,unsigned
   long,unsigned long * __ptr64,unsigned char * __ptr64) */

ulong __cdecl
IoCopy_InterfaceReg(_CRYPT_INTERFACE_REG *param_1,ulong param_2,ulong *param_3,uchar *param_4)

{
  int iVar1;
  ulong uVar2;
  uchar *puVar3;
  ulong local_res10 [2];
  
  local_res10[0] = 0;
  if (param_3 != (ulong *)0x0) {
    *param_3 = 0;
  }
  puVar3 = param_4;
  iVar1 = ValidateInterfaceId(param_1->dwInterface,0);
  if (((iVar1 != 0) && (param_1->cFunctions != 0)) && (param_1->rgpszFunctions != (PWSTR *)0x0)) {
    if ((param_1->dwFlags & 0xfffffffe) != 0) {
      return 0x3ec;
    }
    puVar3 = (uchar *)(-(ulonglong)(param_4 != (uchar *)0x0) & (ulonglong)(puVar3 + 0x18));
    uVar2 = IoCopy_SzStringArray
                      ((ushort **)param_1->rgpszFunctions,param_1->cFunctions,local_res10,puVar3);
    if (uVar2 != 0) {
      return uVar2;
    }
    if (local_res10[0] != 0) {
      if (param_4 != (uchar *)0x0) {
        *(ULONG *)param_4 = param_1->dwInterface;
        *(ULONG *)(param_4 + 4) = param_1->dwFlags;
        *(uchar **)(param_4 + 0x10) = puVar3;
        *(ULONG *)(param_4 + 8) = param_1->cFunctions;
      }
      if (param_3 != (ulong *)0x0) {
        *param_3 = local_res10[0] + 0x18;
      }
      return 0;
    }
  }
  return 0x57;
}



===== IoCopy_InterfaceRegArray @ 1800192e0 =====

/* unsigned long __cdecl IoCopy_InterfaceRegArray(struct _CRYPT_INTERFACE_REG * __ptr64 *
   __ptr64,unsigned long,unsigned long,unsigned long * __ptr64,unsigned char * __ptr64) */

ulong __cdecl
IoCopy_InterfaceRegArray
          (_CRYPT_INTERFACE_REG **param_1,ulong param_2,ulong param_3,ulong *param_4,uchar *param_5)

{
  ulong uVar1;
  ulong uVar2;
  ulonglong uVar3;
  uchar *puVar4;
  uint uVar5;
  uchar *puVar6;
  ulong local_res18 [4];
  
  local_res18[0] = 0;
  if ((param_1 == (_CRYPT_INTERFACE_REG **)0x0) || (param_2 == 0)) {
LAB_18001937e:
    uVar2 = 0x57;
  }
  else {
    if (param_4 != (ulong *)0x0) {
      *param_4 = 0;
    }
    uVar5 = param_2 * 8;
    uVar2 = param_2;
    puVar6 = param_5;
    for (uVar3 = 0; (uint)uVar3 < param_2; uVar3 = (ulonglong)((uint)uVar3 + 1)) {
      if (param_1[uVar3] == (_CRYPT_INTERFACE_REG *)0x0) goto LAB_18001937e;
      if (param_5 == (uchar *)0x0) {
        puVar4 = (uchar *)0x0;
      }
      else {
        puVar4 = param_5 + uVar5;
      }
      uVar1 = IoCopy_InterfaceReg(param_1[uVar3],uVar2,local_res18,puVar4);
      if (uVar1 != 0) {
        return uVar1;
      }
      if (param_5 != (uchar *)0x0) {
        *(uchar **)puVar6 = puVar4;
        puVar6 = puVar6 + 8;
      }
      uVar5 = uVar5 + local_res18[0];
    }
    if (param_4 != (ulong *)0x0) {
      *param_4 = uVar5;
    }
    uVar2 = 0;
  }
  return uVar2;
}



===== IoCopy_SzStringArray @ 1800193a4 =====

/* unsigned long __cdecl IoCopy_SzStringArray(unsigned short * __ptr64 * __ptr64,unsigned
   long,unsigned long * __ptr64,unsigned char * __ptr64) */

ulong __cdecl IoCopy_SzStringArray(ushort **param_1,ulong param_2,ulong *param_3,uchar *param_4)

{
  size_t _Size;
  ulong uVar1;
  ulonglong uVar2;
  uchar *_Dst;
  int iVar3;
  ulonglong uVar4;
  ulong local_res8 [2];
  
  local_res8[0] = 0;
  iVar3 = 0;
  uVar4 = (ulonglong)param_2;
  if (param_3 != (ulong *)0x0) {
    *param_3 = 0;
  }
  if (param_1 != (ushort **)0x0) {
    if (param_4 == (uchar *)0x0) {
      _Dst = (uchar *)0x0;
    }
    else {
      _Dst = param_4 + param_2 * 8;
    }
    for (uVar2 = 0; (uint)uVar2 < param_2; uVar2 = (ulonglong)((uint)uVar2 + 1)) {
      if (param_1[uVar2] == (ushort *)0x0) {
        return 0x57;
      }
      uVar1 = SzString_CchLength(param_1[uVar2],local_res8,0);
      if (uVar1 != 0) {
        return uVar1;
      }
      if (local_res8[0] == 0) {
        return 0x57;
      }
      iVar3 = iVar3 + 1 + local_res8[0];
    }
    if (iVar3 != 0) {
      if ((param_4 != (uchar *)0x0) && (param_2 != 0)) {
        do {
          SzString_CchLength(*param_1,local_res8,0);
          _Size = (ulonglong)(local_res8[0] + 1) * 2;
          memcpy(_Dst,*param_1,_Size);
          *(uchar **)param_4 = _Dst;
          param_1 = param_1 + 1;
          _Dst = _Dst + _Size;
          param_4 = param_4 + 8;
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
      }
      if (param_3 != (ulong *)0x0) {
        *param_3 = param_2 * 8 + (iVar3 * 2 + 7U & 0xfffffff8);
      }
      return 0;
    }
  }
  return 0x57;
}



===== IoPack_ImageReg @ 1800194c0 =====

/* void __cdecl IoPack_ImageReg(struct _CRYPT_IMAGE_REG * __ptr64 * __ptr64,unsigned char * __ptr64)
    */

void __cdecl IoPack_ImageReg(_CRYPT_IMAGE_REG **param_1,uchar *param_2)

{
  _CRYPT_IMAGE_REG *p_Var1;
  PCRYPT_INTERFACE_REG p_Var2;
  PCRYPT_INTERFACE_REG p_Var3;
  PWSTR pWVar4;
  PCRYPT_INTERFACE_REG *pp_Var5;
  ulonglong uVar6;
  _CRYPT_IMAGE_REG *p_Var7;
  PCRYPT_INTERFACE_REG *pp_Var8;
  
  p_Var1 = *param_1;
  if (p_Var1 == (_CRYPT_IMAGE_REG *)0x0) {
    p_Var7 = (_CRYPT_IMAGE_REG *)0xffffffffffffffff;
  }
  else {
    p_Var7 = (_CRYPT_IMAGE_REG *)((longlong)p_Var1 - (longlong)param_2);
  }
  *param_1 = p_Var7;
  if (p_Var1 != (_CRYPT_IMAGE_REG *)0x0) {
    if (p_Var1->pszImage == (PWSTR)0x0) {
      pWVar4 = (PWSTR)0xffffffffffffffff;
    }
    else {
      pWVar4 = (PWSTR)((longlong)p_Var1->pszImage - (longlong)param_2);
    }
    p_Var1->pszImage = pWVar4;
    pp_Var8 = p_Var1->rgpInterfaces;
    uVar6 = (ulonglong)p_Var1->cInterfaces;
    if (pp_Var8 == (PCRYPT_INTERFACE_REG *)0x0) {
      pp_Var5 = (PCRYPT_INTERFACE_REG *)0xffffffffffffffff;
    }
    else {
      pp_Var5 = (PCRYPT_INTERFACE_REG *)((longlong)pp_Var8 - (longlong)param_2);
    }
    p_Var1->rgpInterfaces = pp_Var5;
    if ((pp_Var8 != (PCRYPT_INTERFACE_REG *)0x0) && (p_Var1->cInterfaces != 0)) {
      do {
        p_Var2 = *pp_Var8;
        if (p_Var2 == (PCRYPT_INTERFACE_REG)0x0) {
          p_Var3 = (PCRYPT_INTERFACE_REG)0xffffffffffffffff;
        }
        else {
          p_Var3 = (PCRYPT_INTERFACE_REG)((longlong)p_Var2 - (longlong)param_2);
        }
        *pp_Var8 = p_Var3;
        if (p_Var2 != (PCRYPT_INTERFACE_REG)0x0) {
          IoPack_SzStringArray((ushort ***)&p_Var2->rgpszFunctions,p_Var2->cFunctions,param_2);
        }
        pp_Var8 = pp_Var8 + 1;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
  }
  return;
}



===== IoPack_SzStringArray @ 180019578 =====

/* void __cdecl IoPack_SzStringArray(unsigned short * __ptr64 * __ptr64 * __ptr64,unsigned
   long,unsigned char * __ptr64) */

void __cdecl IoPack_SzStringArray(ushort ***param_1,ulong param_2,uchar *param_3)

{
  ushort **ppuVar1;
  ushort *puVar2;
  ulonglong uVar3;
  ushort **ppuVar4;
  
  ppuVar1 = *param_1;
  if (ppuVar1 == (ushort **)0x0) {
    ppuVar4 = (ushort **)0xffffffffffffffff;
  }
  else {
    ppuVar4 = (ushort **)((longlong)ppuVar1 - (longlong)param_3);
  }
  *param_1 = ppuVar4;
  if ((ppuVar1 != (ushort **)0x0) && (param_2 != 0)) {
    uVar3 = (ulonglong)param_2;
    do {
      if (*ppuVar1 == (ushort *)0x0) {
        puVar2 = (ushort *)0xffffffffffffffff;
      }
      else {
        puVar2 = (ushort *)((longlong)*ppuVar1 - (longlong)param_3);
      }
      *ppuVar1 = puVar2;
      ppuVar1 = ppuVar1 + 1;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  return;
}



===== IoShutdown @ 1800195c4 =====

/* void __cdecl IoShutdown(void) */

void __cdecl IoShutdown(void)

{
  if (DAT_180025ad8 == 1) {
    EnterCriticalSection(&g_csIoInitialize);
    if (g_hIoDevice != (void *)0x0) {
      CloseHandle(g_hIoDevice);
      g_hIoDevice = (void *)0x0;
    }
    LeaveCriticalSection(&g_csIoInitialize);
    DeleteCriticalSection(&g_csIoInitialize);
    DAT_180025ad8 = 0;
  }
  return;
}



===== ValidateConfigurationFlags @ 180019648 =====

/* int __cdecl ValidateConfigurationFlags(unsigned long,unsigned long,unsigned long) */

int __cdecl ValidateConfigurationFlags(ulong param_1,ulong param_2,ulong param_3)

{
  uint uVar1;
  
  if (param_1 == 0x10010) {
    uVar1 = 0x10001;
    if (param_2 != 2) {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0;
    if (param_1 == 0x10030) {
      uVar1 = 1;
    }
  }
  return (uint)((param_3 & ~uVar1) == 0);
}



===== UninitializeLoader @ 180019688 =====

void UninitializeLoader(undefined8 param_1,undefined8 param_2,undefined *param_3)

{
  undefined **ppuVar1;
  
  if (g_fLoaderInitialized == 0) {
    DebugTraceError(0x20,"NTE_FAIL","onecore\\ds\\security\\cryptoapi\\ncrypt\\loader\\loader.c",
                    0xc3);
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&g_csLoaderLock);
  LeaveCriticalSection((LPCRITICAL_SECTION)&g_csLoaderLock);
  if (g_pLoadedProviderList != (undefined8 *)0x0) {
    ppuVar1 = &WPP_GLOBAL_Control;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 2) != 0)) {
      param_3 = &WPP_321c0d2313123f81ee86e6c36df24469_Traceguids;
      ppuVar1 = (undefined **)0x19;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x19,
              &WPP_321c0d2313123f81ee86e6c36df24469_Traceguids);
    }
    while (g_pLoadedProviderList != (undefined8 *)0x0) {
      UnloadProvider(g_pLoadedProviderList,ppuVar1,param_3);
    }
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)&g_csLoaderLock);
  g_fLoaderInitialized = 0;
  return;
}



===== VsmGetInterfaceProviderFromLibrary @ 180019754 =====

int VsmGetInterfaceProviderFromLibrary(int param_1,undefined8 *param_2,undefined8 *param_3)

{
  int iVar1;
  DWORD DVar2;
  HMODULE hModule;
  FARPROC pFVar3;
  char *lpProcName;
  undefined1 uVar4;
  LPCWSTR local_res20;
  ushort local_18 [8];
  
  local_res20 = (LPCWSTR)0x0;
  local_18[0] = 0;
  local_18[1] = 0;
  local_18[2] = 0;
  local_18[3] = 0;
  local_18[4] = 0;
  local_18[5] = 0;
  local_18[6] = 0;
  local_18[7] = 0;
  RtlInitUnicodeString(local_18,L"bcryptprimitives.dll");
  iVar1 = _GetImagePath(local_18,&local_res20);
  if (iVar1 < 0) {
    uVar4 = 0x95;
  }
  else {
    hModule = LoadLibraryExW(local_res20,(HANDLE)0x0,0);
    *param_3 = hModule;
    if (hModule == (HMODULE)0x0) {
      DVar2 = GetLastError();
      uVar4 = 0x9d;
      iVar1 = -0x3ffffecb;
      if (DVar2 != 0x7e) {
        iVar1 = -0x3fffff85;
      }
    }
    else {
      if (param_1 == 1) {
        lpProcName = "GetCipherInterface";
      }
      else if (param_1 == 2) {
        lpProcName = "GetHashInterface";
      }
      else if (param_1 == 3) {
        lpProcName = "GetAsymmetricEncryptionInterface";
      }
      else if (param_1 == 4) {
        lpProcName = "GetSecretAgreementInterface";
      }
      else if (param_1 == 5) {
        lpProcName = "GetSignatureInterface";
      }
      else if (param_1 == 6) {
        lpProcName = "GetRngInterface";
      }
      else if (param_1 == 7) {
        lpProcName = "GetKeyDerivationInterface";
      }
      else {
        if (param_1 != 8) {
          iVar1 = -0x3fffff45;
          uVar4 = 0xaf;
          goto LAB_1800198a4;
        }
        lpProcName = "GetKeyEncapsulationInterface";
      }
      pFVar3 = GetProcAddress(hModule,lpProcName);
      *param_2 = pFVar3;
      if (pFVar3 != (FARPROC)0x0) goto LAB_1800198b7;
      iVar1 = -0x3ffffec7;
      uVar4 = 0xb9;
    }
  }
LAB_1800198a4:
  DebugTraceError((char)iVar1,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\loader\\loader.c",
                  uVar4);
LAB_1800198b7:
  if (local_res20 != (LPCWSTR)0x0) {
    SafeAllocaFreeToHeap(local_res20);
  }
  return iVar1;
}



===== VsmGetLinkedInterfaceProvider @ 1800198e8 =====

undefined8 VsmGetLinkedInterfaceProvider(int param_1,undefined8 *param_2)

{
  code *pcVar1;
  undefined1 uVar2;
  
  if (param_1 == 1) {
    *param_2 = GetCipherInterface_exref;
  }
  else {
    if (param_1 == 2) {
      pcVar1 = GetHashInterface_exref;
    }
    else if (param_1 == 3) {
      pcVar1 = GetAsymmetricEncryptionInterface_exref;
    }
    else if (param_1 == 4) {
      pcVar1 = GetSecretAgreementInterface_exref;
    }
    else if (param_1 == 5) {
      pcVar1 = GetSignatureInterface_exref;
    }
    else if (param_1 == 6) {
      pcVar1 = GetRngInterface_exref;
    }
    else if (param_1 == 7) {
      pcVar1 = GetKeyDerivationInterface_exref;
    }
    else {
      if (param_1 != 8) {
        uVar2 = 0xfb;
        if (param_1 == 0x10002) {
          uVar2 = 0xf6;
        }
        DebugTraceError(0xbb,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\loader\\loader.c",
                        uVar2);
        return 0xc00000bb;
      }
      pcVar1 = GetKeyEncapsulationInterface_exref;
    }
    *param_2 = pcVar1;
  }
  return 0;
}



===== VsmLoadInterface @ 1800199b0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

int VsmLoadInterface(uint param_1,undefined8 param_2,undefined4 param_3,undefined8 *param_4)

{
  undefined8 *puVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  undefined1 uVar6;
  longlong lVar7;
  undefined1 uVar8;
  HMODULE pHVar9;
  undefined8 *puVar10;
  code *local_48;
  undefined8 *local_40;
  HMODULE local_38 [2];
  
  local_48 = (code *)0x0;
  local_40 = (undefined8 *)0x0;
  local_38[0] = (HMODULE)0x0;
  uVar2 = g_TrustedEnvironment;
  if (g_TrustedEnvironment == 0) {
    uVar2 = GetTrustedEnvironment();
  }
  if ((uVar2 & 0x18) == 0) {
    iVar3 = VsmGetInterfaceProviderFromLibrary(param_1,&local_48,local_38);
    pHVar9 = local_38[0];
  }
  else {
    uVar4 = VsmGetLinkedInterfaceProvider(param_1,&local_48);
    iVar3 = (int)uVar4;
    pHVar9 = (HMODULE)0x0;
  }
  if (iVar3 < 0) {
    uVar8 = 0x2c;
    uVar6 = (undefined1)iVar3;
  }
  else {
    if (param_1 < 7) {
      if (param_1 != 6) {
        if (param_1 == 1) {
          iVar3 = (*local_48)(&u_Microsoft_Primi,param_2,&local_40,param_3);
          if (-1 < iVar3) goto LAB_180019cc6;
          uVar6 = 0xf8;
        }
        else if (param_1 == 2) {
          iVar3 = (*local_48)(&u_Microsoft_Primi,param_2,&local_40,param_3);
          if (-1 < iVar3) goto LAB_180019cc6;
          uVar6 = 5;
        }
        else if (param_1 == 3) {
          iVar3 = (*local_48)(&u_Microsoft_Primi,param_2,&local_40,param_3);
          if (-1 < iVar3) goto LAB_180019cc6;
          uVar6 = 0x12;
        }
        else if (param_1 == 4) {
          iVar3 = (*local_48)(&u_Microsoft_Primi,param_2,&local_40,param_3);
          if (-1 < iVar3) goto LAB_180019cc6;
          uVar6 = 0x1f;
        }
        else {
          if (param_1 != 5) goto LAB_180019bc0;
          iVar3 = (*local_48)(&u_Microsoft_Primi,param_2,&local_40,param_3);
          if (-1 < iVar3) goto LAB_180019cc6;
          uVar6 = 0x2c;
        }
LAB_180019aa5:
        uVar8 = (undefined1)iVar3;
        goto LAB_180019bd2;
      }
      iVar3 = (*local_48)(&u_Microsoft_Primi,&local_40,param_3);
      if (iVar3 < 0) {
        uVar6 = 0x38;
        goto LAB_180019aa5;
      }
LAB_180019cc6:
      if (-1 < iVar3) {
        lVar7 = 3;
        puVar5 = local_40;
        do {
          uVar4 = puVar5[1];
          *param_4 = *puVar5;
          param_4[1] = uVar4;
          uVar4 = puVar5[3];
          param_4[2] = puVar5[2];
          param_4[3] = uVar4;
          uVar4 = puVar5[5];
          param_4[4] = puVar5[4];
          param_4[5] = uVar4;
          uVar4 = puVar5[7];
          param_4[6] = puVar5[6];
          param_4[7] = uVar4;
          uVar4 = puVar5[9];
          param_4[8] = puVar5[8];
          param_4[9] = uVar4;
          uVar4 = puVar5[0xb];
          param_4[10] = puVar5[10];
          param_4[0xb] = uVar4;
          uVar4 = puVar5[0xd];
          param_4[0xc] = puVar5[0xc];
          param_4[0xd] = uVar4;
          puVar10 = param_4 + 0x10;
          puVar1 = puVar5 + 0xe;
          uVar4 = puVar5[0xf];
          puVar5 = puVar5 + 0x10;
          param_4[0xe] = *puVar1;
          param_4[0xf] = uVar4;
          lVar7 = lVar7 + -1;
          param_4 = puVar10;
        } while (lVar7 != 0);
        *puVar10 = *puVar5;
        goto LAB_180019d40;
      }
    }
    else {
      if (param_1 == 7) {
        iVar3 = (*local_48)(&u_Microsoft_Primi,param_2,&local_40,param_3);
        if (-1 < iVar3) goto LAB_180019cc6;
        uVar6 = 0x45;
        goto LAB_180019aa5;
      }
      if (param_1 == 8) {
        iVar3 = (*local_48)(&u_Microsoft_Primi,param_2,&local_40,param_3);
        if (-1 < iVar3) goto LAB_180019cc6;
        uVar6 = 0x52;
        goto LAB_180019aa5;
      }
      if (param_1 == 0x10001) {
        iVar3 = (*local_48)(&u_Microsoft_Primi,&local_40,param_3);
        if (-1 < iVar3) goto LAB_180019cc6;
        uVar6 = 0x5e;
        goto LAB_180019aa5;
      }
      if (param_1 == 0x10002) {
        iVar3 = (*local_48)(&u_Microsoft_Primi,&local_40,param_3);
        if (-1 < iVar3) goto LAB_180019cc6;
        uVar6 = 0x76;
        goto LAB_180019aa5;
      }
      if (param_1 == 0x10004) {
        iVar3 = (*local_48)(&u_Microsoft_Primi,&local_40,param_3);
        if (-1 < iVar3) goto LAB_180019cc6;
        uVar6 = 0x6a;
        goto LAB_180019aa5;
      }
LAB_180019bc0:
      iVar3 = -0x3fffff45;
      uVar6 = 0x7c;
      uVar8 = 0xbb;
LAB_180019bd2:
      DebugTraceError(uVar8,"ntStatus","onecore\\ds\\security\\cryptoapi\\ncrypt\\loader\\loader.c",
                      uVar6);
    }
    uVar8 = 0x39;
    uVar6 = (undefined1)iVar3;
  }
  DebugTraceError(uVar6,"Status","onecore\\ds\\security\\cryptoapi\\ncrypt\\loader\\loader.c",uVar8)
  ;
LAB_180019d40:
  if (pHVar9 != (HMODULE)0x0) {
    _FreeImage(pHVar9);
  }
  return iVar3;
}



===== WPP_SF_ @ 180019d74 =====

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  EtwTraceMessage(param_1,0x2b,param_3,param_2,0);
  return;
}



===== WPP_SF_qSq @ 180019da0 =====

void WPP_SF_qSq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               wchar_t *param_5,undefined1 param_6)

{
  longlong lVar1;
  undefined8 local_res20;
  
  if (param_5 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_5[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"NULL";
  }
  local_res20 = param_4;
  EtwTraceMessage(param_1,0x2b,&WPP_321c0d2313123f81ee86e6c36df24469_Traceguids,0x12,&local_res20,8,
                  param_5,lVar1,&param_6,8,0);
  return;
}



===== _FreeImage @ 180019e48 =====

void _FreeImage(HMODULE param_1)

{
  if ((param_1 != g_hInstance) && (param_1 != (HMODULE)0x0)) {
    FreeLibrary(param_1);
  }
  return;
}



===== SymCryptRsaPkcs1RemoveEncryptionPadding @ 180019e74 =====

uint SymCryptRsaPkcs1RemoveEncryptionPadding
               (ulonglong *param_1,ulonglong param_2,longlong param_3,longlong param_4,
               ulonglong param_5,ulonglong *param_6)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  uint uVar9;
  
  uVar5 = 0;
  uVar7 = 0;
  uVar6 = 0;
  uVar3 = 0;
  if (param_2 < 0xb) {
    uVar5 = 0x800e;
  }
  else {
    uVar3 = 2;
    uVar9 = 0;
    uVar7 = 0;
    uVar8 = 2;
    do {
      uVar1 = ~uVar7;
      uVar2 = ~((int)-(uint)*(byte *)(uVar8 + (longlong)param_1) >> 0x1f);
      uVar7 = uVar7 | uVar2;
      uVar1 = uVar1 & uVar2 & uVar3;
      uVar3 = uVar3 + 1;
      uVar9 = uVar9 | uVar1;
      uVar8 = (ulonglong)uVar3;
    } while (uVar8 < param_2);
    uVar7 = (int)(-(*(byte *)((longlong)param_1 + 1) ^ 2) | -(uint)(byte)*param_1) >> 0x1f |
            (int)(uVar9 - 10) >> 0x1f | ~uVar7;
    uVar3 = ((int)param_2 - uVar9) - 1 & ~uVar7;
    if (param_4 != 0) {
      uVar1 = (uint)param_5 & 0x7fffffff;
      if (uVar1 == param_5) {
        uVar6 = (int)(uVar1 - uVar3) >> 0x1f;
      }
      SymCryptScsRotateBuffer(param_1,(uint)param_3,(ulonglong)(uVar9 + 1) & param_3 - 1U);
      uVar9 = 0;
      if (param_2 <= param_5) {
        param_5 = param_2;
      }
      if (param_5 != 0) {
        uVar8 = 0;
        do {
          iVar4 = uVar9 - uVar3;
          uVar9 = uVar9 + 1;
          *(byte *)(uVar8 + param_4) =
               (byte)(iVar4 >> 0x1f) &
               (*(byte *)(uVar8 + param_4) ^ *(byte *)(uVar8 + (longlong)param_1)) ^
               *(byte *)(uVar8 + param_4);
          uVar8 = (ulonglong)uVar9;
        } while (uVar8 < param_5);
      }
    }
  }
  uVar5 = uVar5 ^ (uVar5 ^ 0x800d) & uVar6;
  *param_6 = (ulonglong)uVar3;
  return (uVar5 ^ 0x800e) & uVar7 ^ uVar5;
}



===== SymCryptRoundUpPow2Sizet @ 180019fc4 =====

void SymCryptRoundUpPow2Sizet(ulonglong param_1)

{
  ulonglong uVar1;
  
  uVar1 = 1;
  do {
    if (param_1 <= uVar1) {
      return;
    }
    uVar1 = uVar1 * 2;
  } while (uVar1 != 0);
  return;
}



===== SymCryptScsRotateBuffer @ 180019fdc =====

void SymCryptScsRotateBuffer(ulonglong *param_1,uint param_2,ulonglong param_3)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong *puVar7;
  uint uVar8;
  int iVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  uint uVar12;
  uint uVar13;
  longlong lVar14;
  ulonglong uVar15;
  uint uVar16;
  ulonglong local_c8 [17];
  
  uVar2 = *param_1;
  uVar8 = param_2 >> 3;
  uVar12 = (uint)param_3 & 7;
  uVar13 = uVar12 * 8;
  lVar14 = -(ulonglong)uVar13;
  uVar10 = (ulonglong)uVar8;
  do {
    iVar9 = (int)uVar10;
    uVar10 = (ulonglong)(iVar9 - 1U);
    uVar11 = uVar2 << ((char)uVar12 * -8 + 0x40U & (byte)(lVar14 >> 0x3f) & 0x3f);
    uVar2 = param_1[uVar10];
    param_1[uVar10] = uVar11 & lVar14 >> 0x3f | uVar2 >> (sbyte)uVar13;
  } while (iVar9 - 1U != 0);
  uVar11 = param_3 >> 3;
  uVar12 = iVar9 + 3;
  uVar10 = (ulonglong)uVar12;
  uVar13 = iVar9 + 1;
  uVar2 = -(ulonglong)((uint)uVar11 & 1);
  if (uVar8 != 0) {
    uVar1 = uVar13;
    do {
      uVar16 = uVar1 + uVar12;
      uVar3 = (param_1[uVar1 - 1] ^ param_1[uVar1 - 2]) & uVar2;
      uVar15 = param_1[uVar1 - 2] ^ uVar3;
      uVar3 = param_1[uVar1 - 1] ^ uVar3;
      uVar4 = (param_1[uVar1 + 1] ^ param_1[uVar1]) & uVar2;
      uVar6 = param_1[uVar1] ^ uVar4;
      uVar4 = param_1[uVar1 + 1] ^ uVar4;
      uVar5 = (uVar6 ^ uVar15) & -(ulonglong)((uint)(param_3 >> 4) & 1);
      param_1[uVar1 - 2] = uVar15 ^ uVar5;
      param_1[uVar1] = uVar6 ^ uVar5;
      uVar5 = (uVar4 ^ uVar3) & -(ulonglong)((uint)(uVar11 + 1 >> 1) & 1);
      param_1[uVar1 - 1] = uVar3 ^ uVar5;
      param_1[uVar1 + 1] = uVar4 ^ uVar5;
      uVar1 = uVar16;
    } while (uVar16 - 2 < uVar8);
  }
  uVar16 = param_2 >> 5;
  uVar1 = 0x10;
  if ((0x10 < uVar16) || (uVar1 = uVar16, uVar12 <= uVar16)) {
    do {
      iVar9 = (int)uVar10;
      if (iVar9 != 0) {
        puVar7 = local_c8;
        uVar2 = uVar11;
        uVar3 = uVar10;
        do {
          uVar4 = uVar2 >> ((byte)uVar13 & 0x3f);
          uVar2 = uVar2 + 1;
          *puVar7 = -(ulonglong)((uint)uVar4 & 1);
          puVar7 = puVar7 + 1;
          uVar3 = uVar3 - 1;
        } while (uVar3 != 0);
      }
      uVar2 = 0;
      if (uVar8 != 0) {
        do {
          if (iVar9 != 0) {
            uVar3 = uVar2;
            puVar7 = local_c8;
            uVar4 = uVar10;
            do {
              uVar12 = (int)uVar3 + iVar9;
              uVar5 = param_1[uVar12];
              uVar6 = (uVar5 ^ param_1[uVar3]) & *puVar7;
              puVar7 = puVar7 + 1;
              param_1[uVar3] = param_1[uVar3] ^ uVar6;
              param_1[uVar12] = uVar5 ^ uVar6;
              uVar4 = uVar4 - 1;
              uVar3 = (ulonglong)((int)uVar3 + 1);
            } while (uVar4 != 0);
          }
          uVar12 = (int)uVar2 + iVar9 * 2;
          uVar2 = (ulonglong)uVar12;
        } while (uVar12 < uVar8);
      }
      uVar10 = (ulonglong)(uint)(iVar9 * 2);
      uVar13 = uVar13 + 1;
    } while ((uint)(iVar9 * 2) <= uVar1);
  }
  while (uVar12 = (uint)uVar10, uVar12 < uVar8) {
    uVar2 = 0;
    if (uVar8 != 0) {
      do {
        if (uVar12 != 0) {
          uVar3 = uVar10;
          uVar4 = uVar2;
          uVar5 = uVar11;
          do {
            uVar1 = (int)uVar4 + uVar12;
            uVar6 = param_1[uVar1];
            uVar15 = -(ulonglong)((uint)(uVar5 >> ((byte)uVar13 & 0x3f)) & 1) &
                     (uVar6 ^ param_1[uVar4]);
            uVar5 = uVar5 + 1;
            param_1[uVar4] = param_1[uVar4] ^ uVar15;
            param_1[uVar1] = uVar6 ^ uVar15;
            uVar3 = uVar3 - 1;
            uVar4 = (ulonglong)((int)uVar4 + 1);
          } while (uVar3 != 0);
        }
        uVar1 = (int)uVar2 + uVar12 * 2;
        uVar2 = (ulonglong)uVar1;
      } while (uVar1 < uVar8);
    }
    uVar13 = uVar13 + 1;
    uVar10 = (ulonglong)(uVar12 * 2);
  }
  return;
}



===== CBufferGetNextOffset @ 18001a274 =====

longlong CBufferGetNextOffset(longlong *param_1,ulonglong param_2)

{
  longlong lVar1;
  
  if (((param_1 == (longlong *)0x0) || (param_2 == 0)) || ((ulonglong)param_1[1] < param_2)) {
    return 0;
  }
  lVar1 = *param_1;
  param_1[1] = param_1[1] - param_2;
  *param_1 = lVar1 + param_2;
  return lVar1;
}



===== CancelTimerCallbacksAndDeleteTimer @ 18001a2a8 =====

void CancelTimerCallbacksAndDeleteTimer(longlong param_1)

{
  if (*(PTP_TIMER *)(param_1 + 0x158) != (PTP_TIMER)0x0) {
    SetThreadpoolTimer(*(PTP_TIMER *)(param_1 + 0x158),(PFILETIME)0x0,0,0);
    WaitForThreadpoolTimerCallbacks(*(PTP_TIMER *)(param_1 + 0x158),1);
    CloseThreadpoolTimer(*(PTP_TIMER *)(param_1 + 0x158));
    *(undefined8 *)(param_1 + 0x158) = 0;
  }
  return;
}



===== CompareEventEntry @ 18001a314 =====

int CompareEventEntry(byte param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  uint uVar4;
  
  lVar1 = *(longlong *)(param_3 + 0x10);
  iVar2 = memcmp((void *)(param_2 + 0x10),(void *)(lVar1 + 0x10),8);
  if (iVar2 == 0) {
    for (uVar4 = *(byte *)(param_3 + 0x2d) + 2; uVar4 < param_1; uVar4 = uVar4 + 1) {
      lVar3 = (ulonglong)uVar4 * 0x10;
      iVar2 = *(int *)(lVar3 + 8 + param_2) - *(int *)(lVar3 + 8 + lVar1);
      if (iVar2 != 0) {
        return iVar2;
      }
      iVar2 = memcmp(*(void **)(lVar3 + param_2),*(void **)(lVar3 + lVar1),
                     (ulonglong)*(uint *)(lVar3 + 8 + param_2));
      if (iVar2 != 0) {
        return iVar2;
      }
    }
    iVar2 = 0;
  }
  return iVar2;
}



===== ComputeEventEntryHash @ 18001a3a0 =====

int ComputeEventEntryHash(char param_1,byte param_2,longlong param_3)

{
  byte bVar1;
  ulonglong uVar2;
  longlong *plVar3;
  uint local_res8 [2];
  
  local_res8[0] = 0;
  RunningHash(local_res8,param_3 + 0x10,8);
  bVar1 = param_1 + 2;
  if (bVar1 < param_2) {
    plVar3 = (longlong *)((ulonglong)bVar1 * 0x10 + param_3);
    uVar2 = (ulonglong)(byte)(param_2 - bVar1);
    do {
      RunningHash(local_res8,*plVar3,(ulonglong)*(uint *)(plVar3 + 1));
      plVar3 = plVar3 + 2;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  return (local_res8[0] * 9 >> 0xb ^ local_res8[0] * 9) * 0x8001;
}



===== ComputeFlushPeriod @ 18001a430 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int ComputeFlushPeriod(ulonglong param_1)

{
  longlong lVar1;
  undefined1 auStack_58 [32];
  uint local_38 [2];
  ulonglong local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  local_38[0] = 0;
  local_30 = param_1 >> 4;
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x148) + 8);
  local_28 = *(undefined8 *)(lVar1 + -0x10);
  uStack_20 = *(undefined8 *)(lVar1 + -8);
  RunningHash(local_38,(longlong)&local_28,0x10);
  RunningHash(local_38,(longlong)&local_30,8);
  return ((local_38[0] * 9 >> 0xb ^ local_38[0] * 9) * 0x8001) % 600000 + 600000;
}



===== CreateNewEventEntry @ 18001a4dc =====

undefined8
CreateNewEventEntry(undefined8 *param_1,byte param_2,longlong param_3,byte param_4,
                   undefined4 param_5,undefined8 *param_6)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  longlong lVar4;
  HANDLE hHeap;
  longlong lVar5;
  undefined8 *puVar6;
  void *pvVar7;
  byte bVar8;
  uint uVar9;
  longlong lVar10;
  ulonglong uVar11;
  byte bVar12;
  uint *puVar13;
  SIZE_T dwBytes;
  LPVOID local_38;
  SIZE_T local_30;
  
  bVar12 = 0;
  lVar5 = 0;
  bVar8 = 0;
  *param_6 = 0;
  if (param_2 != 0) {
    puVar13 = (uint *)(param_3 + 8);
    lVar10 = 0;
    do {
      uVar9 = *puVar13;
      puVar13 = puVar13 + 4;
      if (1 < bVar8) {
        lVar5 = (ulonglong)uVar9 + lVar5;
      }
      lVar4 = (ulonglong)uVar9 + lVar10;
      if (1 < bVar8) {
        lVar4 = lVar10;
      }
      bVar8 = bVar8 + 1;
      lVar10 = lVar4;
    } while (bVar8 < param_2);
    if (0xffff < (ulonglong)(lVar4 + lVar5)) {
      return 0x216;
    }
  }
  dwBytes = (ulonglong)param_2 * 0x10 + 0x2e + lVar5;
  if (dwBytes != 0) {
    hHeap = GetProcessHeap();
    local_38 = HeapAlloc(hHeap,8,dwBytes);
    if (local_38 != (LPVOID)0x0) {
      local_30 = dwBytes;
      lVar5 = CBufferGetNextOffset((longlong *)&local_38,(ulonglong)param_2 * 0x10);
      if (param_4 != 0xfffffffe) {
        do {
          uVar11 = (ulonglong)bVar12;
          if (bVar12 < 2) {
            puVar6 = (undefined8 *)(param_3 + uVar11 * 0x10);
            uVar2 = puVar6[1];
            puVar1 = (undefined8 *)(lVar5 + uVar11 * 0x10);
            *puVar1 = *puVar6;
            puVar1[1] = uVar2;
          }
          else {
            uVar9 = *(uint *)(param_3 + 8 + uVar11 * 0x10);
            pvVar7 = (void *)CBufferGetNextOffset((longlong *)&local_38,(ulonglong)uVar9);
            memcpy(pvVar7,*(void **)(param_3 + uVar11 * 0x10),(ulonglong)uVar9);
            *(void **)(lVar5 + uVar11 * 0x10) = pvVar7;
            *(undefined4 *)(lVar5 + 0xc + uVar11 * 0x10) =
                 *(undefined4 *)(param_3 + 0xc + uVar11 * 0x10);
            *(undefined4 *)(lVar5 + 8 + uVar11 * 0x10) =
                 *(undefined4 *)(param_3 + 8 + uVar11 * 0x10);
          }
          bVar12 = bVar12 + 1;
        } while ((uint)bVar12 < param_4 + 2);
      }
      lVar10 = 0x2e;
      puVar6 = (undefined8 *)CBufferGetNextOffset((longlong *)&local_38,0x2e);
      puVar6[2] = lVar5;
      uVar2 = *param_1;
      uVar3 = param_1[1];
      *(byte *)((longlong)puVar6 + 0x2d) = param_4;
      bVar8 = param_4 + 2;
      *(byte *)((longlong)puVar6 + 0x2c) = param_2;
      *(undefined4 *)(puVar6 + 5) = param_5;
      *puVar6 = uVar2;
      puVar6[1] = uVar3;
      if (bVar8 < param_2) {
        lVar5 = (lVar10 + -0x36) - param_3;
        uVar11 = (ulonglong)(byte)(param_2 - bVar8);
        puVar13 = (uint *)((ulonglong)bVar8 * 0x10 + 8 + param_3);
        do {
          uVar9 = *puVar13;
          pvVar7 = (void *)CBufferGetNextOffset((longlong *)&local_38,(ulonglong)uVar9);
          memcpy(pvVar7,*(void **)(puVar13 + -2),(ulonglong)uVar9);
          *(void **)((longlong)puVar13 + puVar6[2] + lVar5) = pvVar7;
          *(uint *)((longlong)puVar13 + puVar6[2] + lVar5 + 0xc) = puVar13[1];
          *(uint *)((longlong)puVar13 + puVar6[2] + lVar5 + 8) = *puVar13;
          uVar11 = uVar11 - 1;
          puVar13 = puVar13 + 4;
        } while (uVar11 != 0);
      }
      *param_6 = puVar6;
      return 0;
    }
  }
  return 8;
}



===== CreateTlgAggregateSession @ 18001a700 =====

LPVOID CreateTlgAggregateSession(char param_1)

{
  bool bVar1;
  HANDLE hHeap;
  LPVOID pv;
  PTP_TIMER p_Var2;
  
  bVar1 = false;
  hHeap = GetProcessHeap();
  pv = HeapAlloc(hHeap,8,0x168);
  if (pv == (LPVOID)0x0) goto LAB_18001a7b3;
  InitializeSRWLock((PSRWLOCK)((longlong)pv + 0x108));
  if (param_1 != '\0') {
    if (DAT_180025b28 != 0) goto LAB_18001a7b3;
    p_Var2 = CreateThreadpoolTimer(FlushTimerCallbackUserMode,pv,(PTP_CALLBACK_ENVIRON)0x0);
    *(PTP_TIMER *)((longlong)pv + 0x158) = p_Var2;
    if (*(longlong *)((longlong)pv + 0x158) == 0) goto LAB_18001a7b3;
  }
  bVar1 = true;
LAB_18001a7b3:
  if (!bVar1) {
    DestroyAggregateSession(pv);
    pv = (LPVOID)0x0;
  }
  return pv;
}



===== DestroyAggregateSession @ 18001a7dc =====

void DestroyAggregateSession(LPVOID param_1)

{
  HANDLE hHeap;
  
  if (param_1 != (LPVOID)0x0) {
    CancelTimerCallbacksAndDeleteTimer((longlong)param_1);
    hHeap = GetProcessHeap();
    HeapFree(hHeap,0,param_1);
  }
  return;
}



===== DestroyEventEntry @ 18001a81c =====

void DestroyEventEntry(longlong param_1)

{
  LPVOID lpMem;
  HANDLE hHeap;
  
  if (param_1 != 0) {
    lpMem = *(LPVOID *)(param_1 + 0x10);
    hHeap = GetProcessHeap();
    HeapFree(hHeap,0,lpMem);
  }
  return;
}



===== EnableFlushTimer @ 18001a858 =====

void EnableFlushTimer(PTP_TIMER param_1,ulonglong param_2)

{
  _FILETIME local_res8 [4];
  
  if ((param_1 != (PTP_TIMER)0x0) &&
     (local_res8[0] = (_FILETIME)((param_2 & 0xffffffff) * -10000), DAT_180025b28 == 0)) {
    SetThreadpoolTimer(param_1,local_res8,0,5000);
  }
  return;
}



===== ExtractAggregateFieldTypes @ 18001a8b8 =====

undefined8 ExtractAggregateFieldTypes(undefined8 param_1,longlong param_2)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  longlong lVar4;
  uint uVar5;
  ulonglong in_RAX;
  undefined7 uVar7;
  ulonglong uVar6;
  byte *pbVar8;
  byte *pbVar9;
  byte bVar10;
  
  lVar4 = *(longlong *)(param_2 + 0x10);
  bVar10 = 0;
  uVar3 = *(uint *)(param_2 + 0x18);
  pbVar8 = (byte *)(lVar4 + 2);
  do {
    bVar1 = *pbVar8;
    in_RAX = CONCAT71((int7)(in_RAX >> 8),bVar1);
    pbVar8 = pbVar8 + 1;
  } while ((char)bVar1 < '\0');
  do {
    bVar1 = *pbVar8;
    in_RAX = CONCAT71((int7)(in_RAX >> 8),bVar1);
    pbVar8 = pbVar8 + 1;
  } while (bVar1 != 0);
  while (pbVar8 < (byte *)((ulonglong)uVar3 + lVar4)) {
    do {
      pbVar9 = pbVar8;
      uVar7 = (undefined7)(in_RAX >> 8);
      in_RAX = CONCAT71(uVar7,*pbVar9);
      pbVar8 = pbVar9 + 1;
    } while (*pbVar9 != 0);
    bVar1 = pbVar9[1];
    if (-1 < (char)bVar1) break;
    in_RAX = CONCAT71(uVar7,pbVar9[2]);
    pbVar8 = pbVar9 + 3;
    if (-1 < (char)pbVar9[2]) break;
    for (; bVar2 = *pbVar8, (char)bVar2 < '\0'; pbVar8 = pbVar8 + 1) {
      if (bVar2 != 0x80) goto LAB_18001a932;
    }
    if (((bVar1 & 0x7f) != 9) ||
       (uVar5 = (int)CONCAT71((int7)((ulonglong)param_2 >> 8),bVar2) - 0x71,
       in_RAX = (ulonglong)uVar5, 2 < (byte)uVar5)) break;
    uVar6 = (ulonglong)bVar10;
    in_RAX = uVar6 * 2;
    bVar10 = bVar10 + 1;
    *(byte *)(param_2 + 0x2d + uVar6 * 0x10) = bVar2;
  }
LAB_18001a932:
  return CONCAT71((int7)(in_RAX >> 8),bVar10);
}



===== FlattenEventEntryTree @ 18001a940 =====

int FlattenEventEntryTree(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong *plVar5;
  longlong local_res8 [4];
  
  local_res8[0] = param_1;
  plVar4 = local_res8;
  iVar2 = 0;
  while (param_1 != 0) {
    lVar1 = *(longlong *)(param_1 + 0x20);
    *(undefined8 *)(param_1 + 0x20) = 0;
    plVar4 = (longlong *)(*plVar4 + 0x18);
    lVar3 = *plVar4;
    plVar5 = plVar4;
    while (lVar3 != 0) {
      plVar5 = (longlong *)(lVar3 + 0x20);
      lVar3 = *plVar5;
    }
    *plVar5 = lVar1;
    iVar2 = iVar2 + 1;
    param_1 = *plVar4;
  }
  return iVar2;
}



===== FlushEventEntryList @ 18001a988 =====

void FlushEventEntryList(REGHANDLE param_1,PCEVENT_DESCRIPTOR param_2)

{
  PCEVENT_DESCRIPTOR pEVar1;
  longlong lVar2;
  int iVar3;
  
  if (param_2 != (PCEVENT_DESCRIPTOR)0x0) {
    do {
      iVar3 = 2;
      if (2 < *(byte *)((longlong)&param_2[2].Keyword + 5) + 2) {
        lVar2 = 0x20;
        do {
          lVar2 = lVar2 + 0x10;
          iVar3 = iVar3 + 1;
          *(undefined1 *)(*(longlong *)(param_2 + 1) + -3 + lVar2) = 0;
        } while (iVar3 < (int)(*(byte *)((longlong)&param_2[2].Keyword + 5) + 2));
      }
      EventWriteTransfer(param_1,param_2,(LPCGUID)0x0,(LPCGUID)0x0,
                         (uint)*(byte *)((longlong)&param_2[2].Keyword + 4),
                         *(PEVENT_DATA_DESCRIPTOR *)(param_2 + 1));
      pEVar1 = (PCEVENT_DESCRIPTOR)param_2[1].Keyword;
      DestroyEventEntry((longlong)param_2);
      param_2 = pEVar1;
    } while (pEVar1 != (PCEVENT_DESCRIPTOR)0x0);
  }
  return;
}



===== FlushLookUpTableBucket @ 18001aa28 =====

int FlushLookUpTableBucket(longlong param_1,ulonglong param_2)

{
  PCEVENT_DESCRIPTOR pEVar1;
  int iVar2;
  ulonglong uVar3;
  
  uVar3 = param_2 & 0xffffffff;
  if (*(longlong *)(param_1 + uVar3 * 8) == 0) {
    iVar2 = 0;
  }
  else {
    AcquireSRWLockExclusive((PSRWLOCK)(param_1 + 0x108));
    pEVar1 = *(PCEVENT_DESCRIPTOR *)(param_1 + uVar3 * 8);
    *(undefined8 *)(param_1 + uVar3 * 8) = 0;
    iVar2 = FlattenEventEntryTree((longlong)pEVar1);
    *(int *)(param_1 + 0x100) = *(int *)(param_1 + 0x100) - iVar2;
    ReleaseSRWLockExclusive((PSRWLOCK)(param_1 + 0x108));
    FlushEventEntryList(*(REGHANDLE *)(*(longlong *)(param_1 + 0x148) + 0x20),pEVar1);
  }
  return iVar2;
}



===== FlushTimerCallbackUserMode @ 18001aac0 =====

void FlushTimerCallbackUserMode
               (undefined8 param_1,longlong param_2,undefined8 param_3,_GUID *param_4)

{
  if (*(char *)(param_2 + 0x164) == '\0') {
    LookUpTableFlushPartial(param_2);
  }
  else {
    *(undefined1 *)(param_2 + 0x164) = 0;
    LookUpTableFlushComplete(param_2,param_2,param_3,param_4);
  }
  if (*(int *)(param_2 + 0x100) != 0) {
    EnableFlushTimer(*(PTP_TIMER *)(param_2 + 0x158),(ulonglong)*(uint *)(param_2 + 0x160));
  }
  return;
}



===== InsertEventEntryInLookUpTable @ 18001ab10 =====

ulonglong InsertEventEntryInLookUpTable
                    (undefined8 param_1,undefined8 *param_2,byte param_3,longlong param_4,
                    byte param_5)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  char cVar4;
  longlong lVar5;
  longlong lVar6;
  uint uVar7;
  int iVar8;
  ulonglong uVar9;
  byte bVar10;
  longlong *plVar11;
  longlong lVar12;
  ulonglong uVar13;
  longlong local_res8;
  
  lVar6 = DAT_180025088;
  lVar12 = 0;
  local_res8 = 0;
  uVar13 = 0;
  uVar7 = ComputeEventEntryHash(param_5,param_3,param_4);
  AcquireSRWLockShared((PSRWLOCK)(lVar6 + 0x108));
  plVar11 = (longlong *)(lVar6 + (ulonglong)(uVar7 & 0x1f) * 8);
  do {
    if (*plVar11 == 0) {
      if (0x3ff < *(uint *)(lVar6 + 0x100)) {
        *(int *)(lVar6 + 300) = *(int *)(lVar6 + 300) + 1;
        uVar13 = 0xea;
        goto LAB_18001ad1d;
      }
      if (lVar12 == 0) {
        uVar9 = CreateNewEventEntry(param_2,param_3,param_4,param_5,uVar7,&local_res8);
        uVar13 = uVar9 & 0xffffffff;
        lVar12 = local_res8;
        if (local_res8 == 0) {
          if ((int)uVar9 == 8) {
            *(int *)(lVar6 + 0x130) = *(int *)(lVar6 + 0x130) + 1;
          }
          else {
            *(int *)(lVar6 + 0x134) = *(int *)(lVar6 + 0x134) + 1;
          }
          goto LAB_18001ad1d;
        }
      }
      LOCK();
      lVar2 = *plVar11;
      if (lVar2 == 0) {
        *plVar11 = lVar12;
      }
      UNLOCK();
      if (lVar2 == 0) {
        local_res8 = 0;
        LOCK();
        piVar1 = (int *)(lVar6 + 0x100);
        iVar8 = *piVar1;
        *piVar1 = *piVar1 + 1;
        UNLOCK();
        if (iVar8 == 0) {
          EnableFlushTimer(*(PTP_TIMER *)(lVar6 + 0x158),(ulonglong)*(uint *)(lVar6 + 0x160));
        }
        lVar12 = local_res8;
        if (*(uint *)(lVar6 + 0x120) < *(uint *)(lVar6 + 0x100)) {
          *(uint *)(lVar6 + 0x120) = *(uint *)(lVar6 + 0x100);
        }
        goto LAB_18001ad1d;
      }
      lVar12 = local_res8;
    }
    lVar2 = *plVar11;
    if (uVar7 == *(uint *)(lVar2 + 0x28)) {
      iVar8 = CompareEventEntry(param_3,param_4,lVar2);
    }
    else {
      iVar8 = uVar7 - *(int *)(lVar2 + 0x28);
    }
    if (iVar8 == 0) {
      if (lVar2 != 0) {
        uVar9 = 2;
        if (2 < param_5 + 2) {
          do {
            lVar12 = **(longlong **)(param_4 + uVar9 * 0x10);
            cVar4 = *(char *)(*(longlong *)(lVar2 + 0x10) + 0xd + uVar9 * 0x10);
            plVar11 = *(longlong **)(*(longlong *)(lVar2 + 0x10) + uVar9 * 0x10);
            if (cVar4 == 'q') {
              LOCK();
              *plVar11 = *plVar11 + lVar12;
              UNLOCK();
            }
            else if ((cVar4 == 'r') || (cVar4 == 's')) {
              do {
                lVar5 = *plVar11;
                if (cVar4 == 'r') {
                  if (lVar5 <= lVar12) break;
                }
                else if (lVar12 <= lVar5) break;
                LOCK();
                lVar3 = *plVar11;
                if (lVar5 == lVar3) {
                  *plVar11 = lVar12;
                }
                UNLOCK();
              } while (lVar5 != lVar3);
            }
            bVar10 = (char)uVar9 + 1;
            uVar9 = (ulonglong)bVar10;
          } while ((uint)bVar10 < param_5 + 2);
          lVar12 = local_res8;
        }
      }
LAB_18001ad1d:
      ReleaseSRWLockShared((PSRWLOCK)(lVar6 + 0x108));
      if (lVar12 != 0) {
        DestroyEventEntry(lVar12);
      }
      return uVar13;
    }
    plVar11 = (longlong *)(lVar2 + 0x20 + ((longlong)iVar8 >> 0x3f & 0xfffffffffffffff8U));
  } while( true );
}



===== LookUpTableFlushComplete @ 18001ad60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void LookUpTableFlushComplete(longlong param_1,undefined8 param_2,undefined8 param_3,_GUID *param_4)

{
  _tlgProvider_t *p_Var1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined1 auStackY_268 [32];
  _tlgWrapperByVal<1> local_148;
  _tlgWrapperByVal<1> local_147;
  _tlgWrapperByVal<1> local_146;
  _tlgWrapperByVal<1> local_145;
  _tlgWrapperByVal<1> local_144;
  _tlgWrapperByVal<1> local_143;
  _tlgWrapperByVal<1> local_142;
  _tlgWrapperByVal<1> local_141;
  _tlgWrapperByVal<1> local_140;
  _tlgWrapperByVal<1> local_13f [3];
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  ulonglong local_130;
  ulonglong local_128;
  ulonglong local_120;
  ulonglong local_118;
  ulonglong local_110;
  longlong local_108;
  ulonglong local_100;
  undefined8 local_f8;
  undefined8 *local_f0;
  undefined8 local_e8;
  wchar_t *local_e0;
  undefined2 local_d8;
  wchar_t *local_d0;
  undefined2 local_c8;
  wchar_t *local_c0;
  undefined2 local_b8;
  wchar_t *local_b0;
  undefined2 local_a8;
  wchar_t *local_a0;
  undefined2 local_98;
  wchar_t *local_90;
  undefined2 local_88;
  wchar_t *local_80;
  undefined2 local_78;
  wchar_t *local_70;
  undefined2 local_68;
  wchar_t *local_60;
  undefined2 local_58;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_268;
  uVar4 = 0;
  if (*(uint *)(param_1 + 0x100) != 0) {
    lVar2 = param_1;
    UpdateInternalStatsOnFlush(param_1,*(uint *)(param_1 + 0x100));
    if (*(longlong *)(lVar2 + 0x110) != 0) {
      if (((5 < DAT_180025090) && ((_DAT_1800250a0 & 0x200000000000) != 0)) &&
         ((DAT_1800250a8 & 0x200000000000) == DAT_1800250a8)) {
        local_148 = (_tlgWrapperByVal<1>)0x4;
        local_e0 = L"SummaryCount";
        local_d8 = 0x18;
        local_130 = (ulonglong)*(uint *)(lVar2 + 0x134);
        local_d0 = L"NumLargeEventFailures";
        local_128 = (ulonglong)*(uint *)(param_1 + 0x130);
        local_c0 = L"NumAllocationFailures";
        local_120 = (ulonglong)*(uint *)(param_1 + 300);
        local_b0 = L"NumBucketLimitReached";
        local_118 = (ulonglong)*(uint *)(param_1 + 0x128);
        local_a0 = L"MinEntriesFlushed";
        local_110 = (ulonglong)*(uint *)(param_1 + 0x124);
        local_90 = L"MaxEntriesFlushed";
        local_80 = L"TotalEntriesFlushed";
        local_78 = 0x26;
        local_100 = (ulonglong)*(uint *)(param_1 + 0x120);
        local_70 = L"MaxEntriesStored";
        local_f8 = *(undefined8 *)(param_1 + 0x118);
        local_60 = L"NumFlushes";
        local_58 = 0x14;
        local_c8 = 0x2a;
        local_b8 = 0x2a;
        local_a8 = 0x2a;
        local_13c = 1;
        local_147 = (_tlgWrapperByVal<1>)0x4;
        local_146 = (_tlgWrapperByVal<1>)0x4;
        local_145 = (_tlgWrapperByVal<1>)0x4;
        local_144 = (_tlgWrapperByVal<1>)0x4;
        local_143 = (_tlgWrapperByVal<1>)0x4;
        local_142 = (_tlgWrapperByVal<1>)0x4;
        local_141 = (_tlgWrapperByVal<1>)0x4;
        local_140 = (_tlgWrapperByVal<1>)0x4;
        local_98 = 0x22;
        local_88 = 0x22;
        p_Var1 = *(_tlgProvider_t **)(*(longlong *)(param_1 + 0x148) + 8);
        local_f0 = &local_28;
        local_28 = *(undefined8 *)(p_Var1 + -0x10);
        uStack_20 = *(undefined8 *)(p_Var1 + -8);
        local_138 = 0xffffffff;
        local_68 = 0x20;
        local_13f[0] = (_tlgWrapperByVal<1>)0x0;
        local_134 = 300;
        local_e8 = 0x1000000;
        local_108 = *(longlong *)(lVar2 + 0x110);
        _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EventWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
        ::
        Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByRef<16>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>_>
                  (p_Var1,&DAT_180020862,(_GUID *)0x200000000000,param_4,
                   (_tlgWrapperByVal<8> *)&local_e8,(_tlgWrapperByVal<4> *)&local_134,
                   (_tlgWrapperByVal<4> *)&local_138,local_13f,(_tlgWrapperByRef<16> *)&local_f0,
                   (_tlgWrapperBinary *)&local_60,(_tlgWrapperByVal<8> *)&local_f8,&local_140,
                   (_tlgWrapperBinary *)&local_70,(_tlgWrapperByVal<8> *)&local_100,&local_141,
                   (_tlgWrapperBinary *)&local_80,(_tlgWrapperByVal<8> *)&local_108,&local_142,
                   (_tlgWrapperBinary *)&local_90,(_tlgWrapperByVal<8> *)&local_110,&local_143,
                   (_tlgWrapperBinary *)&local_a0,(_tlgWrapperByVal<8> *)&local_118,&local_144,
                   (_tlgWrapperBinary *)&local_b0,(_tlgWrapperByVal<8> *)&local_120,&local_145,
                   (_tlgWrapperBinary *)&local_c0,(_tlgWrapperByVal<8> *)&local_128,&local_146,
                   (_tlgWrapperBinary *)&local_d0,(_tlgWrapperByVal<8> *)&local_130,&local_147,
                   (_tlgWrapperBinary *)&local_e0,(_tlgWrapperByVal<4> *)&local_13c,&local_148);
      }
      *(undefined8 *)(param_1 + 0x110) = 0;
      *(undefined8 *)(param_1 + 0x118) = 0;
      local_30 = 0;
      *(undefined8 *)(param_1 + 0x120) = 0;
      *(undefined8 *)(param_1 + 0x128) = 0;
      *(undefined8 *)(param_1 + 0x130) = 0;
    }
    do {
      FlushLookUpTableBucket(param_1,uVar4);
      uVar3 = (int)uVar4 + 1;
      uVar4 = (ulonglong)uVar3;
    } while (uVar3 < 0x20);
  }
  return;
}



===== LookUpTableFlushPartial @ 18001b10c =====

void LookUpTableFlushPartial(longlong param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 0;
  if (*(int *)(param_1 + 0x100) != 0) {
    uVar1 = *(uint *)(param_1 + 0x104);
    uVar3 = uVar1;
    do {
      if (*(longlong *)(param_1 + (ulonglong)uVar3 * 8) != 0) {
        iVar2 = FlushLookUpTableBucket(param_1,(ulonglong)uVar3);
        uVar4 = uVar4 + iVar2;
      }
      uVar3 = uVar3 + 1 & 0x1f;
    } while ((uVar3 != uVar1) && (uVar4 < 0x10));
    *(uint *)(param_1 + 0x104) = uVar3;
    UpdateInternalStatsOnFlush(param_1,uVar4);
  }
  return;
}



===== RunningHash @ 18001b184 =====

void RunningHash(uint *param_1,longlong param_2,ulonglong param_3)

{
  byte *pbVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar3 = 0;
  if (param_3 != 0) {
    do {
      pbVar1 = (byte *)(uVar3 + param_2);
      uVar3 = uVar3 + 1;
      uVar2 = ((uint)*pbVar1 + *param_1) * 0x401;
      *param_1 = uVar2 >> 6 ^ uVar2;
    } while (uVar3 < param_3);
  }
  return;
}



===== TlgAggregateInternalProviderCallback @ 18001b1c0 =====

/* void __cdecl TlgAggregateInternalProviderCallback(struct _GUID const * __ptr64,unsigned
   long,unsigned char,unsigned __int64,unsigned __int64,struct _EVENT_FILTER_DESCRIPTOR *
   __ptr64,void * __ptr64) */

void __cdecl
TlgAggregateInternalProviderCallback
          (_GUID *param_1,ulong param_2,uchar param_3,__uint64 param_4,__uint64 param_5,
          _EVENT_FILTER_DESCRIPTOR *param_6,void *param_7)

{
  BOOLEAN BVar1;
  undefined4 in_register_00000014;
  longlong lVar2;
  undefined7 in_register_00000081;
  
  if (((param_2 == 2) && (param_4 == 0x20)) &&
     (BVar1 = TryAcquireSRWLockExclusive((PSRWLOCK)&DAT_180025b38), BVar1 != '\0')) {
    for (lVar2 = DAT_180025b40; lVar2 != 0; lVar2 = *(longlong *)(lVar2 + 0x150)) {
      LookUpTableFlushComplete
                (lVar2,CONCAT44(in_register_00000014,param_2),CONCAT71(in_register_00000081,param_3)
                 ,(_GUID *)param_4);
    }
    ReleaseSRWLockExclusive((PSRWLOCK)&DAT_180025b38);
  }
  return;
}



===== TlgAggregateInternalRegisteredProviderEtwCallback @ 18001b230 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* void __cdecl TlgAggregateInternalRegisteredProviderEtwCallback(struct _GUID const *
   __ptr64,unsigned long,unsigned char,unsigned __int64,unsigned __int64,struct
   _EVENT_FILTER_DESCRIPTOR * __ptr64,void * __ptr64) */

void __cdecl
TlgAggregateInternalRegisteredProviderEtwCallback
          (_GUID *param_1,ulong param_2,uchar param_3,__uint64 param_4,__uint64 param_5,
          _EVENT_FILTER_DESCRIPTOR *param_6,void *param_7)

{
  ulong uVar1;
  undefined4 in_register_00000014;
  undefined7 in_register_00000081;
  undefined8 uVar2;
  
  uVar2 = CONCAT71(in_register_00000081,param_3);
  uVar1 = param_2;
  if (*(code **)((longlong)param_7 + 0x138) != (code *)0x0) {
    uVar2 = CONCAT71((int7)(param_5 >> 8),param_3);
    (**(code **)((longlong)param_7 + 0x138))();
  }
  if (param_2 == 1) {
    LookUpTableFlushComplete
              ((longlong)param_7,CONCAT44(in_register_00000014,uVar1),uVar2,(_GUID *)param_4);
  }
  else if (param_2 == 2) {
    LookUpTableFlushPartial((longlong)param_7);
  }
  return;
}



===== UpdateInternalStatsOnFlush @ 18001b2ac =====

void UpdateInternalStatsOnFlush(longlong param_1,uint param_2)

{
  longlong *plVar1;
  longlong lVar2;
  
  if (param_2 != 0) {
    plVar1 = (longlong *)(param_1 + 0x118);
    if ((param_2 < *(uint *)(param_1 + 0x128)) || (lVar2 = *plVar1, lVar2 == 0)) {
      lVar2 = *plVar1;
      *(uint *)(param_1 + 0x128) = param_2;
    }
    if (*(uint *)(param_1 + 0x124) < param_2) {
      *(uint *)(param_1 + 0x124) = param_2;
    }
    *plVar1 = lVar2 + 1;
    *(longlong *)(param_1 + 0x110) = *(longlong *)(param_1 + 0x110) + (ulonglong)param_2;
  }
  return;
}



===== TlgRegisterAggregateProviderEx @ 18001b2f8 =====

ULONG TlgRegisterAggregateProviderEx(void)

{
  ULONG UVar1;
  int iVar2;
  LPVOID pvVar3;
  longlong lVar4;
  longlong *plVar5;
  
  pvVar3 = CreateTlgAggregateSession('\x01');
  if (pvVar3 == (LPVOID)0x0) {
    UVar1 = TraceLoggingRegisterEx_EventRegister_EventSetInformation(&DAT_180025058,0,0);
  }
  else {
    *(undefined8 *)((longlong)pvVar3 + 0x138) = 0;
    *(undefined8 *)((longlong)pvVar3 + 0x140) = 0;
    *(undefined4 **)((longlong)pvVar3 + 0x148) = &DAT_180025058;
    iVar2 = ComputeFlushPeriod((ulonglong)pvVar3);
    *(int *)((longlong)pvVar3 + 0x160) = iVar2;
    UVar1 = TraceLoggingRegisterEx_EventRegister_EventSetInformation
                      (&DAT_180025058,TlgAggregateInternalRegisteredProviderEtwCallback,pvVar3);
    if ((int)UVar1 < 0) {
      DAT_180025080 = 0;
      DestroyAggregateSession(pvVar3);
    }
    else {
      AcquireSRWLockExclusive((PSRWLOCK)&DAT_180025b38);
      if (DAT_180025b40 == 0) {
        TraceLoggingRegisterEx_EventRegister_EventSetInformation
                  (&DAT_180025090,TlgAggregateInternalProviderCallback,0);
      }
      plVar5 = &DAT_180025b40;
      lVar4 = DAT_180025b40;
      while (lVar4 != 0) {
        if (*(undefined4 **)(lVar4 + 0x148) == &DAT_180025058) goto LAB_18001b3d0;
        plVar5 = (longlong *)(lVar4 + 0x150);
        lVar4 = *plVar5;
      }
      *plVar5 = (longlong)pvVar3;
LAB_18001b3d0:
      ReleaseSRWLockExclusive((PSRWLOCK)&DAT_180025b38);
      UVar1 = 0;
    }
  }
  return UVar1;
}



===== TlgUnregisterAggregateProvider @ 18001b410 =====

void TlgUnregisterAggregateProvider(void)

{
  longlong *plVar1;
  REGHANDLE RVar2;
  LPVOID pvVar3;
  longlong *plVar4;
  LPVOID pvVar5;
  _GUID *in_R9;
  
  RVar2 = DAT_180025078;
  if (DAT_180025080 != TlgAggregateInternalRegisteredProviderEtwCallback) {
    DAT_180025078 = 0;
    DAT_180025058 = 0;
                    /* WARNING: Could not recover jumptable at 0x00018001b51f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    EventUnregister(RVar2);
    return;
  }
  pvVar5 = (LPVOID)0x0;
  AcquireSRWLockExclusive((PSRWLOCK)&DAT_180025b38);
  pvVar3 = DAT_180025b40;
  plVar4 = (longlong *)&DAT_180025b40;
  do {
    if (pvVar3 == (LPVOID)0x0) {
LAB_18001b4ad:
      ReleaseSRWLockExclusive((PSRWLOCK)&DAT_180025b38);
      if (pvVar5 != (LPVOID)0x0) {
        CancelTimerCallbacksAndDeleteTimer((longlong)pvVar5);
      }
      RVar2 = DAT_180025078;
      DAT_180025078 = 0;
      DAT_180025058 = 0;
      EventUnregister(RVar2);
      DAT_180025080 = (code *)0x0;
      DestroyAggregateSession(pvVar5);
      return;
    }
    plVar1 = (longlong *)((longlong)pvVar3 + 0x150);
    if (*(undefined4 **)((longlong)pvVar3 + 0x148) == &DAT_180025058) {
      *plVar4 = *plVar1;
      LookUpTableFlushComplete((longlong)pvVar3,plVar4,&DAT_180025058,in_R9);
      RVar2 = DAT_1800250b0;
      pvVar5 = pvVar3;
      if (DAT_180025b40 == (LPVOID)0x0) {
        DAT_1800250b0 = 0;
        DAT_180025090 = 0;
        EventUnregister(RVar2);
      }
      goto LAB_18001b4ad;
    }
    pvVar3 = (LPVOID)*plVar1;
    plVar4 = plVar1;
  } while( true );
}



===== _tlgWriteAgg @ 18001b534 =====

ulonglong _tlgWriteAgg(undefined8 param_1,byte *param_2,undefined8 param_3,byte param_4,
                      PEVENT_DATA_DESCRIPTOR param_5)

{
  ULONG UVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined4 extraout_var;
  code *pcVar4;
  EVENT_DESCRIPTOR local_18;
  
  local_18._0_4_ = (uint)*param_2 << 0x18;
  local_18._4_4_ = ZEXT24(*(ushort *)(param_2 + 1));
  local_18.Keyword = *(ULONGLONG *)(param_2 + 3);
  param_5->Ptr = (ULONGLONG)PTR_DAT_180025060;
  param_5->Size = (uint)*(ushort *)PTR_DAT_180025060;
  param_5->Reserved = 2;
  param_5[1].Ptr = (ULONGLONG)(param_2 + 0xb);
  param_5[1].Size = (uint)*(ushort *)(param_2 + 0xb);
  param_5[1].Reserved = 1;
  pcVar4 = TlgAggregateInternalRegisteredProviderEtwCallback;
  uVar2 = 0xc000000d;
  if (DAT_180025080 == TlgAggregateInternalRegisteredProviderEtwCallback) {
    uVar3 = ExtractAggregateFieldTypes
                      (TlgAggregateInternalRegisteredProviderEtwCallback,(longlong)param_5);
    if ((byte)uVar3 == 0) {
      UVar1 = EventWriteTransfer(DAT_180025078,&local_18,(LPCGUID)0x0,(LPCGUID)0x0,(uint)param_4,
                                 param_5);
      uVar2 = CONCAT44(extraout_var,UVar1);
    }
    else {
      uVar2 = InsertEventEntryInLookUpTable
                        (pcVar4,(undefined8 *)&local_18,param_4,(longlong)param_5,(byte)uVar3);
    }
  }
  return uVar2;
}



===== _resetstkoflw_static @ 18001b620 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool _resetstkoflw_static(void)

{
  PVOID pvVar1;
  DWORD DVar2;
  BOOL BVar3;
  uint uVar4;
  SIZE_T SVar5;
  LPVOID pvVar6;
  uint uVar7;
  ulonglong uVar8;
  LPVOID lpAddress;
  undefined1 local_98 [16];
  ULONG local_88;
  DWORD local_84;
  _MEMORY_BASIC_INFORMATION local_80;
  _SYSTEM_INFO local_50;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)&local_88;
  local_80.BaseAddress = (PVOID)0x0;
  local_80.AllocationBase = (PVOID)0x0;
  local_84 = 0;
  local_80.AllocationProtect = 0;
  local_80._20_4_ = 0;
  local_80.RegionSize = 0;
  local_88 = 0;
  local_80.State = 0;
  local_80.Protect = 0;
  local_80.Type = 0;
  local_80._44_4_ = 0;
  local_50.u.dwOemId = 0;
  local_50.dwPageSize = 0;
  local_50.lpMinimumApplicationAddress = (LPVOID)0x0;
  local_50.lpMaximumApplicationAddress = (LPVOID)0x0;
  local_50.dwActiveProcessorMask = 0;
  local_50.dwNumberOfProcessors = 0;
  local_50.dwProcessorType = 0;
  local_50.dwAllocationGranularity = 0;
  local_50.wProcessorLevel = 0;
  local_50.wProcessorRevision = 0;
  SVar5 = VirtualQuery(local_98,&local_80,0x30);
  pvVar1 = local_80.AllocationBase;
  if (SVar5 != 0) {
    GetSystemInfo(&local_50);
    DVar2 = local_50.dwPageSize;
    uVar8 = (ulonglong)local_50.dwPageSize;
    BVar3 = SetThreadStackGuarantee(&local_88);
    uVar4 = 0;
    if ((BVar3 == 1) && (uVar4 = 0, local_88 != 0)) {
      uVar4 = local_88;
    }
    uVar7 = (DVar2 - 1) + uVar4;
    if (uVar4 <= uVar7) {
      uVar7 = uVar7 & ~(DVar2 - 1);
      uVar4 = uVar7;
      if ((uVar7 != 0) && (uVar4 = uVar7 + DVar2, uVar4 < uVar7)) {
        return false;
      }
      uVar7 = DVar2 * 3;
      if (DVar2 * 3 <= uVar4) {
        uVar7 = uVar4;
      }
      lpAddress = (LPVOID)((~(ulonglong)(DVar2 - 1) & (ulonglong)local_98) - (ulonglong)uVar7);
      if (((LPVOID)((longlong)pvVar1 + uVar8) <= lpAddress) &&
         (pvVar6 = VirtualAlloc(lpAddress,(ulonglong)uVar7,0x1000,4), pvVar6 != (LPVOID)0x0)) {
        BVar3 = VirtualProtect(lpAddress,(ulonglong)uVar7,0x104,&local_84);
        return BVar3 != 0;
      }
    }
  }
  return false;
}



===== __delayLoadHelper2 @ 18001b7b0 =====

void __delayLoadHelper2(undefined8 param_1,undefined8 param_2)

{
  ResolveDelayLoadedAPI(0x180000000,param_1,0,DelayLoadFailureHook_exref,param_2,0);
  return;
}



===== VerifyLegacyDhPrivateBlob @ 18001b7f4 =====

undefined8 VerifyLegacyDhPrivateBlob(undefined8 *param_1,uint param_2)

{
  undefined1 auVar1 [16];
  undefined8 uVar2;
  uint uVar3;
  
  if ((((0x33 < param_2) && (uVar2 = *param_1, (char)uVar2 == '\a')) &&
      ((char)((ulonglong)uVar2 >> 8) == '\x03')) &&
     (((short)((ulonglong)uVar2 >> 0x10) == 0 && ((int)((ulonglong)uVar2 >> 0x20) - 0xaa01U < 2))))
  {
    auVar1 = *(undefined1 (*) [16])(param_1 + 1);
    if (auVar1._0_4_ == 0x34484400) {
      uVar3 = auVar1._4_4_;
      if (((0xe00 < uVar3 - 0x200) || ((auVar1._0_8_ >> 0x20 & 0x3f) != 0)) ||
         ((uVar3 < auVar1._8_4_ || (uVar3 < *(uint *)(param_1 + 3))))) {
        return 0x80090029;
      }
      if ((ulonglong)(auVar1._8_4_ >> 3) + 0x34 +
          (ulonglong)(auVar1._12_4_ + 7U >> 3) + (ulonglong)((uVar3 >> 3) * 3) +
          (ulonglong)(*(uint *)(param_1 + 3) >> 3) <= (ulonglong)param_2) {
        return 0;
      }
    }
  }
  return 0x80090005;
}



===== VerifyLegacyDsaPrivateBlob @ 18001b8ec =====

undefined8 VerifyLegacyDsaPrivateBlob(undefined8 *param_1,uint param_2)

{
  undefined1 auVar1 [16];
  undefined8 uVar2;
  
  if ((((0x33 < param_2) && (uVar2 = *param_1, (char)uVar2 == '\a')) &&
      ((char)((ulonglong)uVar2 >> 8) == '\x03')) &&
     (((short)((ulonglong)uVar2 >> 0x10) == 0 && ((int)((ulonglong)uVar2 >> 0x20) == 0x2200)))) {
    auVar1 = *(undefined1 (*) [16])(param_1 + 1);
    if (auVar1._0_4_ == 0x34535344) {
      if (((0xa00 < auVar1._4_4_ - 0x200) || ((auVar1._0_8_ >> 0x20 & 0x3f) != 0)) ||
         ((auVar1._8_4_ != 0xa0 || (*(int *)(param_1 + 3) != 0xa0)))) {
        return 0x80090029;
      }
      if ((ulonglong)(auVar1._12_4_ + 7U >> 3) + (ulonglong)((auVar1._4_4_ >> 3) * 3) + 0x5c <=
          (ulonglong)param_2) {
        return 0;
      }
    }
  }
  return 0x80090005;
}



===== InitializeProcessImageNameUM @ 18001b9cc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void InitializeProcessImageNameUM(undefined8 param_1,undefined8 param_2,wchar_t *param_3)

{
  wchar_t *_Src;
  DWORD DVar1;
  BOOL BVar2;
  int iVar3;
  HANDLE hProcess;
  wchar_t *hMem;
  undefined2 uVar4;
  longlong lVar5;
  ulonglong *puVar6;
  undefined1 auStackY_6e8 [32];
  DWORD local_698 [2];
  ulonglong local_690;
  wchar_t *pwStack_688;
  DWORD local_680;
  undefined4 local_67c;
  undefined8 local_678;
  wchar_t *pwStack_670;
  wchar_t local_648;
  undefined1 local_646 [510];
  wchar_t local_448;
  undefined1 local_446 [526];
  WCHAR local_238;
  undefined1 local_236 [526];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_6e8;
  hProcess = GetCurrentProcess();
  if (hProcess == (HANDLE)0x0) {
    DVar1 = GetLastError();
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 2) == 0) {
      return;
    }
    uVar4 = 10;
    goto LAB_18001bd94;
  }
  local_238 = L'\0';
  memset(local_236,0,0x206);
  param_3 = &local_238;
  local_698[0] = 0x104;
  BVar2 = QueryFullProcessImageNameW(hProcess,0,param_3,local_698);
  if (BVar2 == 0) {
    DVar1 = GetLastError();
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 2) == 0) {
      return;
    }
    uVar4 = 0xb;
    goto LAB_18001bd94;
  }
  local_648 = L'\0';
  memset(local_646,0,0x1fe);
  param_3 = (STRSAFE_LPCWSTR)0x0;
  DVar1 = _wsplitpath_s(&local_238,(wchar_t *)0x0,0,(wchar_t *)0x0,0,&local_648,0x100,(wchar_t *)0x0
                        ,0);
  if (DVar1 != 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 2) == 0) {
      return;
    }
    uVar4 = 0xc;
    goto LAB_18001bd94;
  }
  local_448 = L'\0';
  memset(local_446,0,0x206);
  iVar3 = _wcsnicmp(&local_648,L"svchost",7);
  lVar5 = -1;
  if (iVar3 == 0) {
    DVar1 = GetProcessId(hProcess);
    local_678 = 0;
    pwStack_670 = (wchar_t *)0x0;
    local_67c = SUB84(SubProcessTag,0);
    local_680 = DVar1;
    iVar3 = I_QueryTagInformation(0,1,&local_680);
    if (iVar3 == 0) {
      if (pwStack_670 != (wchar_t *)0x0) {
        wcsncpy_s(&local_448,0x104,pwStack_670,0xffffffffffffffff);
        hMem = pwStack_670;
LAB_18001bc07:
        LocalFree(hMem);
      }
    }
    else {
      puVar6 = &local_690;
      pwStack_688 = (wchar_t *)0x0;
      local_690 = (ulonglong)DVar1;
      iVar3 = I_QueryTagInformation(0,3);
      hMem = pwStack_688;
      if (iVar3 == 0) {
        if (pwStack_688 != (wchar_t *)0x0) {
          if (((*(int *)pwStack_688 == 1) &&
              (_Src = (wchar_t *)(*(undefined8 **)(pwStack_688 + 4))[1],
              (int)**(undefined8 **)(pwStack_688 + 4) == 1)) && (_Src != (wchar_t *)0x0)) {
            wcsncpy_s(&local_448,0x104,_Src,0xffffffffffffffff);
          }
          goto LAB_18001bc07;
        }
      }
      else if (((iVar3 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
              ((WPP_GLOBAL_Control[0x1c] & 2) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xd,puVar6,iVar3);
      }
    }
  }
  do {
    lVar5 = lVar5 + 1;
  } while (*(short *)(local_646 + lVar5 * 2 + 0x1fe) != 0);
  if (lVar5 == 0) {
    param_3 = &local_648;
    DVar1 = StringCchCopyW(g_processImageName,0x104,param_3);
  }
  else {
    param_3 = L"%ls[%ls]";
    DVar1 = StringCchPrintfW(g_processImageName,0x104,L"%ls[%ls]",&local_648);
  }
  if (DVar1 == 0x8007007a) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 2) != 0) {
      param_3 = (wchar_t *)&WPP_c7a8d9b2b0213f11ac3a70e9b100c4dc_Traceguids;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xe,
              &WPP_c7a8d9b2b0213f11ac3a70e9b100c4dc_Traceguids);
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 2) != 0) {
      WPP_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xf,param_3,&local_648);
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 2) == 0) {
      return;
    }
    WPP_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x10,param_3,&local_448);
    return;
  }
  if (-1 < (int)DVar1) {
    return;
  }
  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
    return;
  }
  if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
    return;
  }
  uVar4 = 0x11;
LAB_18001bd94:
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar4,param_3,DVar1);
  return;
}



===== WPP_SF_D @ 18001bdd4 =====

void WPP_SF_D(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  EtwTraceMessage(param_1,0x2b,&WPP_c7a8d9b2b0213f11ac3a70e9b100c4dc_Traceguids,param_2,local_res20,
                  4,0);
  return;
}



===== WPP_SF_S @ 18001be1c =====

void WPP_SF_S(undefined8 param_1,undefined2 param_2,undefined8 param_3,wchar_t *param_4)

{
  longlong lVar1;
  
  if (param_4 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"NULL";
  }
  EtwTraceMessage(param_1,0x2b,&WPP_c7a8d9b2b0213f11ac3a70e9b100c4dc_Traceguids,param_2,param_4,
                  lVar1,0);
  return;
}



===== _guard_check_icall @ 18001bea0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 18001beb8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 18001bedc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong __GSHandlerCheckCommon(undefined8 param_1,longlong param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  uVar2 = (ulonglong)*(uint *)(*(longlong *)(param_2 + 0x10) + 8);
  uVar1 = *(ulonglong *)(param_2 + 8);
  if ((*(byte *)(uVar2 + 3 + uVar1) & 0xf) != 0) {
    uVar1 = (ulonglong)(*(byte *)(uVar2 + 3 + uVar1) & 0xfffffff0);
  }
  return uVar1;
}



===== __GSHandlerCheck_SEH @ 18001bf40 =====

void __GSHandlerCheck_SEH
               (_EXCEPTION_RECORD *param_1,void *param_2,_CONTEXT *param_3,
               _DISPATCHER_CONTEXT *param_4)

{
  uint uVar1;
  uint *puVar2;
  
  puVar2 = *(uint **)(param_4 + 0x38);
  uVar1 = *puVar2;
  __GSHandlerCheckCommon(param_2,(longlong)param_4);
  if ((puVar2[(ulonglong)uVar1 * 4 + 1] & ((param_1->ExceptionFlags & 0x66) != 0) + 1) != 0) {
    __C_specific_handler(param_1,param_2,param_3,param_4);
  }
  return;
}



===== __chkstk @ 18001bfcb =====

/* WARNING: This is an inlined function */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __chkstk(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018001bfcb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  return;
}



===== memcmp @ 18001bfd7 =====

int __cdecl memcmp(void *_Buf1,void *_Buf2,size_t _Size)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018001bfd7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = memcmp(_Buf1,_Buf2,_Size);
  return iVar1;
}



===== memcpy @ 18001bfe3 =====

void * __cdecl memcpy(void *_Dst,void *_Src,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018001bfe3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memcpy(_Dst,_Src,_Size);
  return pvVar1;
}



===== memset @ 18001bfef =====

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018001bfef. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memset(_Dst,_Val,_Size);
  return pvVar1;
}



===== wcscmp @ 18001bffb =====

int __cdecl wcscmp(wchar_t *_Str1,wchar_t *_Str2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018001bffb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = wcscmp(_Str1,_Str2);
  return iVar1;
}



===== __security_check_cookie @ 18001c020 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 18001c060 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 18001c090 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00018001c090. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 18001c0c0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== VerifyStackAvailable$filt$0 @ 18001c0d0 =====

bool VerifyStackAvailable_filt_0(undefined8 *param_1)

{
  return *(int *)*param_1 == -0x3fffff03;
}



===== BCryptGetFipsAlgorithmMode$fin$0 @ 18001c100 =====

void BCryptGetFipsAlgorithmMode_fin_0(undefined8 param_1,longlong param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0x30);
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  *(int *)(param_2 + 0x30) = iVar1;
  return;
}



===== BCryptGetFipsAlgorithmMode$fin$1 @ 18001c11d =====

void BCryptGetFipsAlgorithmMode_fin_1(undefined8 param_1,longlong param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0x30);
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  *(int *)(param_2 + 0x30) = iVar1;
  return;
}



===== BCryptGetFipsAlgorithmMode$fin$2 @ 18001c13a =====

void BCryptGetFipsAlgorithmMode_fin_2(undefined8 param_1,longlong param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0x30);
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  *(int *)(param_2 + 0x30) = iVar1;
  return;
}



===== filt$0 @ 18001c15d =====

bool `CreateTlgAggregateSession'::__l1::filt_0(undefined8 *param_1,longlong param_2)

{
  int iVar1;
  
  *(undefined8 **)(param_2 + 0x28) = param_1;
  iVar1 = *(int *)*param_1;
  *(int *)(param_2 + 0x20) = iVar1;
  return iVar1 == -0x3ffffff3;
}



===== _guard_dispatch_icall$thunk$10345483385596137414 @ 18001d010 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall_thunk_10345483385596137414(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}


