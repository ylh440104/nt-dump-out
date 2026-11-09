
===== _tlgKeywordOn @ 140001008 =====

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



===== _tlgWriteTransfer_EtwWriteTransfer @ 14000102c =====

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



===== Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByRef<16>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>_> @ 1400010d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
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
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
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
  undefined8 local_2c8 [4];
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
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x14000f098,param_2,0,0,0x2b,local_2c8);
  return lVar1;
}



===== WcGetContextFileObject @ 140001510 =====

bool WcGetContextFileObject
               (undefined8 param_1,undefined8 param_2,undefined8 *param_3,undefined8 *param_4)

{
  int iVar1;
  undefined8 local_18;
  undefined8 local_10;
  
  local_18 = 0;
  local_10 = 0;
  iVar1 = FltGetFileContext(param_1,param_2,&local_18);
  if (-1 < iVar1) {
    FltGetStreamContext(param_1,param_2,&local_10);
    *param_3 = local_18;
    *param_4 = local_10;
  }
  return -1 < iVar1;
}



===== WcUnionsExistForInstance @ 1400015a0 =====

undefined8
WcUnionsExistForInstance
          (undefined8 param_1,undefined8 param_2,undefined4 *param_3,undefined4 *param_4)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined4 uVar7;
  longlong local_18;
  longlong local_10;
  
  local_18 = 0;
  local_10 = 0;
  uVar6 = 0;
  FltGetInstanceContext(param_1,&local_18);
  lVar1 = *(longlong *)(local_18 + 0x38);
  if (lVar1 == 0) {
    if (*(int *)(local_18 + 0x40) == 0) {
      uVar4 = IoGetSilo(param_2);
      cVar2 = PsIsHostSilo(uVar4);
      if (((cVar2 != '\0') || (*(int *)(local_18 + 0x10) == -1)) ||
         (iVar3 = PsGetSiloContext(uVar4,*(int *)(local_18 + 0x10),&local_10), iVar3 < 0))
      goto LAB_140001622;
      uVar7 = *(undefined4 *)(local_10 + 0xd8);
      uVar5 = *(undefined4 *)(local_10 + 0xdc);
    }
    else {
      uVar7 = *(undefined4 *)(local_18 + 0x118);
      uVar5 = *(undefined4 *)(local_18 + 0x11c);
    }
  }
  else {
    uVar7 = *(undefined4 *)(lVar1 + 0x24);
    uVar5 = *(undefined4 *)(lVar1 + 0x28);
  }
  uVar6 = 1;
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = uVar7;
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = uVar5;
  }
LAB_140001622:
  if (local_18 != 0) {
    FltReleaseContext();
  }
  if (local_10 != 0) {
    PsDereferenceSiloContext();
  }
  return uVar6;
}



===== WcPreRead @ 1400016e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 WcPreRead(longlong param_1,longlong param_2,longlong *param_3)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  longlong lVar4;
  ulonglong uVar5;
  bool bVar6;
  char cVar7;
  int iVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  void *_Dst;
  size_t _Size;
  undefined4 unaff_EBP;
  undefined4 uVar11;
  ulonglong uVar12;
  uint uVar13;
  longlong lVar14;
  undefined1 auStackY_118 [32];
  undefined1 local_b8 [4];
  int local_b4;
  longlong local_b0;
  longlong local_a8;
  longlong *local_a0;
  longlong local_98;
  undefined8 local_88 [4];
  undefined1 *local_68;
  undefined8 local_60;
  longlong *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_118;
  uVar11 = 0;
  local_b4 = 0;
  uVar1 = **(uint **)(param_1 + 0x10);
  uVar13 = uVar1 & 2;
  local_a0 = param_3;
  if ((((DAT_14000f6a4 == '\0') &&
       ((*(uint *)(*(longlong *)(param_2 + 0x20) + 0x50) & 0x400000) != 0)) &&
      (*(char *)(param_1 + 0x50) == '\x01')) &&
     (bVar6 = WcIsSiloFileObject(*(undefined8 *)(param_2 + 0x18),*(longlong *)(param_2 + 0x20)),
     bVar6)) {
    if ((5 < DAT_14000f060) &&
       (uVar9 = _tlgKeywordOn(0x14000f060,0x400000000000), (char)uVar9 != '\0')) {
      local_68 = local_b8;
      local_b8[0] = 2;
      local_58 = &local_b0;
      local_60 = 1;
      local_b0 = 3;
      local_50 = 8;
      _tlgWriteTransfer_EtwWriteTransfer(0x14000f060,&DAT_14000b858,0,0,4,local_88);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,2,10,
                         &WPP_74e98403bd0930425909d23d2522dfc9_Traceguids,
                         "onecore\\base\\fs\\wci\\wcifs\\readwrite.c",0x5a);
    }
    *(undefined4 *)(param_1 + 0x18) = 0xc00000bb;
    *(undefined8 *)(param_1 + 0x20) = 0;
    return unaff_EBP;
  }
  uVar10 = *(undefined8 *)(param_2 + 0x18);
  uVar2 = *(undefined8 *)(param_2 + 0x20);
  local_a8 = 0;
  local_b0 = 0;
  iVar8 = FltGetFileContext(uVar10,uVar2,&local_a8);
  if (iVar8 < 0) {
    return unaff_EBP;
  }
  FltGetStreamContext(uVar10,uVar2,&local_b0);
  lVar14 = local_b0;
  local_98 = local_a8;
  uVar9 = WcIsPlaceHolderStream(local_a8,local_b0);
  if ((char)uVar9 == '\0') goto LAB_140001965;
  uVar10 = IoGetSilo(*(undefined8 *)(param_2 + 0x20));
  if (((uVar13 == 0) && (cVar7 = PsIsHostSilo(uVar10), cVar7 != '\0')) &&
     (*(int *)(*(longlong *)(lVar14 + 0x28) + 0x1c) == 3)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0xb,
                         &WPP_74e98403bd0930425909d23d2522dfc9_Traceguids,
                         "onecore\\base\\fs\\wci\\wcifs\\readwrite.c",0x83);
    }
    *(undefined4 *)(param_1 + 0x18) = 0xc0000022;
    goto LAB_140001965;
  }
  puVar3 = *(undefined8 **)(*(longlong *)(lVar14 + 0x38) + 0x18);
  if ((uVar1 & 1) == 0) {
    if (*(longlong *)(*(longlong *)(param_2 + 0x20) + 0x28) != *(longlong *)(puVar3[2] + 0x28))
    goto LAB_140001965;
  }
  else if (uVar13 == 0) {
    if (*(longlong *)(*(longlong *)(param_2 + 0x20) + 0x28) != *(longlong *)(puVar3[2] + 0x28)) {
      iVar8 = FltLockUserBuffer(param_1);
      if (iVar8 < 0) {
        *(int *)(param_1 + 0x18) = iVar8;
        goto LAB_140001965;
      }
      iVar8 = FltReadFileEx(*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),
                            *(longlong *)(param_1 + 0x10) + 0x28,
                            *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 0x18));
      if ((iVar8 < 0) || (local_b4 == 0)) {
        *(int *)(param_1 + 0x18) = iVar8;
        goto LAB_140001965;
      }
    }
  }
  else if (*(longlong *)(lVar14 + 0xe0) != 0) {
    FltAcquireResourceShared(lVar14 + 0x78);
    if (*(longlong *)(lVar14 + 0xe0) != 0) {
      lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x38);
      _Dst = *(void **)(*(longlong *)(param_1 + 0x10) + 0x30);
      if (lVar4 == 0) {
LAB_140001b3f:
        uVar9 = *(ulonglong *)(lVar14 + 0x48);
        uVar5 = *(ulonglong *)(*(longlong *)(param_1 + 0x10) + 0x28);
        uVar12 = (ulonglong)*(uint *)(*(longlong *)(param_1 + 0x10) + 0x18);
        if (uVar9 < uVar5) {
          uVar11 = 0xc0000011;
        }
        else {
          _Size = uVar9 - uVar5;
          if (uVar12 + uVar5 <= uVar9) {
            _Size = uVar12;
          }
          memmove(_Dst,(void *)(*(longlong *)(lVar14 + 0xe0) + uVar5),_Size);
          *(size_t *)(param_1 + 0x20) = _Size;
        }
      }
      else {
        if ((*(byte *)(lVar4 + 10) & 5) == 0) {
          _Dst = (void *)MmMapLockedPagesSpecifyCache(lVar4,0,1,0);
        }
        else {
          _Dst = *(void **)(lVar4 + 0x18);
        }
        if (_Dst != (void *)0x0) goto LAB_140001b3f;
        uVar11 = 0xc000009a;
      }
      *(undefined4 *)(param_1 + 0x18) = uVar11;
      FltReleaseResource(lVar14 + 0x78);
      goto LAB_140001965;
    }
    FltReleaseResource(lVar14 + 0x78);
  }
  *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 8) = puVar3[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x10) = *puVar3;
  FltSetCallbackDataDirty(param_1);
  *local_a0 = lVar14;
  lVar14 = 0;
LAB_140001965:
  if (local_98 != 0) {
    FltReleaseContext();
  }
  if (lVar14 != 0) {
    FltReleaseContext(lVar14);
  }
  return unaff_EBP;
}



===== WcIsSiloFileObject @ 140001bd0 =====

bool WcIsSiloFileObject(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined8 uVar2;
  bool bVar3;
  longlong local_res18 [2];
  
  local_res18[0] = 0;
  FltGetInstanceContext(param_1,local_res18);
  if (*(longlong *)(local_res18[0] + 0x38) == 0) {
    uVar2 = IoGetSilo(param_2);
    cVar1 = PsIsHostSilo(uVar2);
    bVar3 = cVar1 == '\0';
  }
  else {
    bVar3 = true;
  }
  if (local_res18[0] != 0) {
    FltReleaseContext();
  }
  return bVar3;
}



===== WcIsPlaceHolderStream @ 140001c64 =====

ulonglong WcIsPlaceHolderStream(longlong param_1,longlong param_2)

{
  byte bVar1;
  uint7 extraout_var;
  ulonglong uVar2;
  
  bVar1 = WcIsPlaceHolder(param_1);
  if ((bVar1 == 0) || (param_2 == 0)) {
    uVar2 = (ulonglong)extraout_var << 8;
  }
  else {
    uVar2 = (ulonglong)
            CONCAT31((uint3)(*(uint *)(param_2 + 0x18) >> 0xc),
                     ~(byte)(*(uint *)(param_2 + 0x18) >> 4)) & 0xffffffffffffff01;
  }
  return uVar2;
}



===== WcIsPlaceHolderDirectory @ 140001c98 =====

ulonglong WcIsPlaceHolderDirectory(longlong param_1,longlong param_2)

{
  byte bVar1;
  uint7 extraout_var;
  ulonglong uVar2;
  
  bVar1 = WcIsPlaceHolder(param_1);
  if ((bVar1 == 0) || (param_2 == 0)) {
    uVar2 = (ulonglong)extraout_var << 8;
  }
  else {
    uVar2 = (ulonglong)
            CONCAT31((uint3)(*(uint *)(param_2 + 0x18) >> 0xc),
                     (char)(*(uint *)(param_2 + 0x18) >> 4)) & 0xffffffffffffff01;
  }
  return uVar2;
}



===== WcIsPlaceHolder @ 140001cc8 =====

byte WcIsPlaceHolder(longlong param_1)

{
  uint uVar1;
  
  ExAcquireFastMutex(param_1 + 8);
  uVar1 = *(uint *)(param_1 + 0x58);
  ExReleaseFastMutex(param_1 + 8);
  return (byte)(uVar1 >> 1) & 1;
}



===== WcUnionExistsForFileObject @ 140001d14 =====

bool WcUnionExistsForFileObject(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  int *piVar1;
  
  piVar1 = WcpGetUnionContext(param_1,param_2,param_3,(ushort *)0x0);
  if (piVar1 != (int *)0x0) {
    WcReleaseUnionContext(piVar1);
  }
  return piVar1 != (int *)0x0;
}



===== WcGetUnionContext @ 140001d50 =====

void WcGetUnionContext(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  WcpGetUnionContext(param_1,param_2,param_3,(ushort *)0x0);
  return;
}



===== WcpGetUnionContext @ 140001d70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int * WcpGetUnionContext(longlong param_1,undefined8 param_2,undefined8 param_3,ushort *param_4)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  longlong lVar6;
  undefined8 uVar7;
  int *piVar8;
  undefined2 uVar9;
  bool bVar10;
  undefined1 auStackY_1b8 [32];
  undefined1 uVar11;
  longlong local_178;
  longlong local_170;
  longlong local_168;
  undefined1 *local_160;
  undefined1 local_158 [4];
  undefined4 local_154;
  undefined4 local_150;
  undefined4 uStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1b8;
  local_154 = 0;
  local_178 = 0;
  memset(local_158,0,0x104);
  local_160 = local_158;
  local_170 = 0;
  local_168 = 0;
  piVar8 = (int *)0x0;
  FltGetInstanceContext(param_2,&local_178);
  piVar1 = *(int **)(local_178 + 0x38);
  if (piVar1 != (int *)0x0) {
    WcReferenceUnionContext(piVar1);
    piVar8 = piVar1;
    goto LAB_140001e55;
  }
  uVar4 = IoGetSilo(param_3);
  cVar2 = PsIsHostSilo(uVar4);
  if (((cVar2 != '\0') || (*(int *)(local_178 + 0x10) == -1)) && (*(int *)(local_178 + 0x40) == 0))
  goto LAB_140001e55;
  if (param_4 == (ushort *)0x0) {
    if (param_1 == 0) {
      iVar3 = FltGetFileNameInformationUnsafe(param_3,param_2,0x101,&local_168);
      if (-1 < iVar3) goto LAB_140001f23;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140001e55;
      uVar9 = 0xab;
      uVar11 = 10;
    }
    else {
      uVar7 = 0x4000101;
      if (*(int *)(param_1 + 0x18) != 0x104) {
        uVar7 = 0x101;
      }
      iVar3 = FltGetFileNameInformation(param_1,uVar7,&local_168);
      if (-1 < iVar3) {
LAB_140001f23:
        local_150 = *(undefined4 *)(local_168 + 8);
        uStack_14c = *(undefined4 *)(local_168 + 0xc);
        uStack_148 = *(undefined4 *)(local_168 + 0x10);
        uStack_144 = *(undefined4 *)(local_168 + 0x14);
        goto LAB_140001f2c;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140001e55;
      uVar9 = 0xaa;
      uVar11 = 0xf5;
    }
    WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,uVar9,
                        &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                        "onecore\\base\\fs\\wci\\wcifs\\utils.c",uVar11,(char)iVar3);
    goto LAB_140001e55;
  }
  local_150 = *(undefined4 *)param_4;
  uStack_14c = *(undefined4 *)(param_4 + 2);
  uStack_148 = *(undefined4 *)(param_4 + 4);
  uStack_144 = *(undefined4 *)(param_4 + 6);
LAB_140001f2c:
  cVar2 = PsIsHostSilo(uVar4);
  if ((cVar2 == '\0') &&
     (iVar3 = PsGetSiloContext(uVar4,*(undefined4 *)(local_178 + 0x10),&local_170),
     iVar3 != -0x3ffffddb)) {
    if (iVar3 < 0) goto LAB_140001e55;
    FltAcquireResourceShared(local_170 + 8);
    puVar5 = (undefined8 *)RtlLookupElementGenericTableAvl(local_170 + 0x70,&local_160);
    if (puVar5 == (undefined8 *)0x0) {
      FltReleaseResource(local_170 + 8);
      goto LAB_140001f6b;
    }
    WcReferenceUnionContext((int *)*puVar5);
    lVar6 = local_170 + 8;
  }
  else {
LAB_140001f6b:
    FltAcquireResourceShared(local_178 + 0x48);
    puVar5 = (undefined8 *)RtlLookupElementGenericTableAvl(local_178 + 0xb0,&local_160);
    if (puVar5 == (undefined8 *)0x0) {
      FltReleaseResource(local_178 + 0x48);
      goto LAB_140001e55;
    }
    WcReferenceUnionContext((int *)*puVar5);
    lVar6 = local_178 + 0x48;
  }
  FltReleaseResource(lVar6);
  piVar8 = (int *)*puVar5;
  if (param_4 == (ushort *)0x0) {
    bVar10 = *(ushort *)(local_168 + 8) < *(ushort *)(piVar8 + 2);
  }
  else {
    bVar10 = *param_4 < *(ushort *)(piVar8 + 2);
  }
  if (bVar10) {
    WcReleaseUnionContext(piVar8);
    piVar8 = (int *)0x0;
  }
LAB_140001e55:
  if (local_178 != 0) {
    FltReleaseContext();
  }
  if (local_170 != 0) {
    PsDereferenceSiloContext();
  }
  if (local_168 != 0) {
    FltReleaseFileNameInformation();
  }
  return piVar8;
}



===== WcPreWrite @ 140002160 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 WcPreWrite(longlong param_1,longlong param_2)

{
  undefined8 uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  bool bVar5;
  char cVar6;
  byte bVar7;
  int iVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined2 uVar12;
  undefined1 auStackY_e8 [32];
  undefined1 uVar13;
  undefined1 local_a8 [8];
  undefined8 local_a0;
  longlong lStack_98;
  longlong local_90;
  longlong local_88 [2];
  undefined8 local_78 [4];
  undefined1 *local_58;
  undefined8 local_50;
  longlong *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_a0 = 0;
  lStack_98 = 0;
  uVar11 = 1;
  if ((((DAT_14000f6a4 == '\0') &&
       ((*(uint *)(*(longlong *)(param_2 + 0x20) + 0x50) & 0x400000) != 0)) &&
      (*(char *)(param_1 + 0x50) == '\x01')) &&
     (bVar5 = WcIsSiloFileObject(*(undefined8 *)(param_2 + 0x18),*(longlong *)(param_2 + 0x20)),
     bVar5)) {
    if ((5 < DAT_14000f060) &&
       (uVar9 = _tlgKeywordOn(0x14000f060,0x400000000000), (char)uVar9 != '\0')) {
      local_58 = local_a8;
      local_a8[0] = 2;
      local_48 = &local_90;
      local_50 = 1;
      local_90 = 4;
      local_40 = 8;
      _tlgWriteTransfer_EtwWriteTransfer(0x14000f060,&DAT_14000b818,0,0,4,local_78);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,2,0xc,
                         &WPP_74e98403bd0930425909d23d2522dfc9_Traceguids,
                         "onecore\\base\\fs\\wci\\wcifs\\readwrite.c",0x99);
    }
    *(undefined4 *)(param_1 + 0x18) = 0xc00000bb;
    *(undefined8 *)(param_1 + 0x20) = 0;
    return 4;
  }
  uVar10 = *(undefined8 *)(param_2 + 0x20);
  uVar1 = *(undefined8 *)(param_2 + 0x18);
  local_88[0] = 0;
  local_90 = 0;
  iVar8 = FltGetFileContext(uVar1,uVar10,local_88);
  if (iVar8 < 0) {
    return 1;
  }
  FltGetStreamContext(uVar1,uVar10,&local_90);
  lVar4 = local_88[0];
  lVar3 = local_90;
  uVar9 = WcIsPlaceHolderStream(local_88[0],local_90);
  if ((char)uVar9 == '\0') {
    bVar7 = WcIsPlaceHolder(lVar4);
    if (((bVar7 == 0) || (uVar9 = WcIsPlaceHolderDirectory(lVar4,lVar3), (char)uVar9 != '\0')) ||
       (lVar2 = *(longlong *)(lVar4 + 0x40), (*(uint *)(lVar2 + 0xc) & 2) != 0)) goto LAB_140002242;
    lStack_98 = lVar2 + 0x22;
    local_a0 = CONCAT62(CONCAT42(local_a0._4_4_,*(undefined2 *)(lVar2 + 0x20)),
                        *(undefined2 *)(lVar2 + 0x20));
    if ((**(uint **)(param_1 + 0x10) & 2) == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,2,0x11,
                            &WPP_74e98403bd0930425909d23d2522dfc9_Traceguids,
                            "onecore\\base\\fs\\wci\\wcifs\\readwrite.c",0x23,(wchar_t *)&local_a0);
      }
      iVar8 = WcSetPlaceHolderFlagsSynchronized
                        (param_1,*(undefined8 *)(param_2 + 0x18),*(longlong *)(param_2 + 0x20),2);
      goto joined_r0x0001400025e4;
    }
    if (((*(uint *)(*(longlong *)(param_2 + 0x20) + 0x50) & 0x100) != 0) ||
       ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)) goto LAB_140002242;
    uVar12 = 0x10;
    uVar13 = 0x16;
LAB_14000256a:
    bVar7 = 3;
  }
  else {
    lVar2 = *(longlong *)(lVar4 + 0x40);
    lStack_98 = lVar2 + 0x22;
    local_a0 = CONCAT62(CONCAT42(local_a0._4_4_,*(undefined2 *)(lVar2 + 0x20)),
                        *(undefined2 *)(lVar2 + 0x20));
    uVar10 = IoGetSilo(*(undefined8 *)(param_2 + 0x20));
    cVar6 = PsIsHostSilo(uVar10);
    if ((cVar6 == '\0') || (*(int *)(*(longlong *)(lVar3 + 0x28) + 0x1c) != 3)) {
      if ((**(uint **)(param_1 + 0x10) & 2) == 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0xf,
                              &WPP_74e98403bd0930425909d23d2522dfc9_Traceguids,
                              "onecore\\base\\fs\\wci\\wcifs\\readwrite.c",0xeb,(wchar_t *)&local_a0
                             );
        }
        iVar8 = WcExpandAndWait(param_1,*(undefined8 *)(param_2 + 0x18),
                                *(undefined8 *)(param_2 + 0x20),lVar4,1,0x12);
joined_r0x0001400025e4:
        if (iVar8 < 0) {
          uVar11 = 4;
          *(undefined8 *)(param_1 + 0x20) = 0;
          *(int *)(param_1 + 0x18) = iVar8;
        }
        goto LAB_140002242;
      }
      if (((*(uint *)(*(longlong *)(param_2 + 0x20) + 0x50) & 0x100) != 0) ||
         ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)) goto LAB_140002242;
      uVar12 = 0xe;
      uVar13 = 0xde;
      goto LAB_14000256a;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140002242;
    uVar12 = 0xd;
    uVar13 = 0xbf;
    bVar7 = 2;
  }
  WPP_RECORDER_SF_sDZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar7,2,uVar12,
                      &WPP_74e98403bd0930425909d23d2522dfc9_Traceguids,
                      "onecore\\base\\fs\\wci\\wcifs\\readwrite.c",uVar13,(wchar_t *)&local_a0);
LAB_140002242:
  if (lVar3 != 0) {
    FltReleaseContext(lVar3);
  }
  if (lVar4 != 0) {
    FltReleaseContext(lVar4);
  }
  return uVar11;
}



===== WPP_RECORDER_SF_sDD @ 140002618 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDD(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,char *param_6,undefined1 param_7,undefined1 param_8)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  uVar4 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar4 * 0x14) * 4) >> (param_3 - 1 & 0x1f)
       & 1) != 0) && (param_2 <= *(byte *)(WPP_GLOBAL_Control + 0x29 + uVar4 * 0x50))) {
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
    pcVar1 = param_6;
    if (param_6 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18 + uVar4 * 0x50),0x2b,param_5,param_4,pcVar1
               ,lVar3,&param_7,4,&param_8,4,0);
  }
  lVar3 = -1;
  if (param_6 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (param_6[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_6 == (char *)0x0) {
    param_6 = "NULL";
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,param_6,lVar2,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_sD_guid_Zd @ 1400027d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sD_guid_Zd
               (undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined8 param_6,undefined1 param_7,undefined8 param_8,
               wchar_t *param_9,undefined1 param_10)

{
  undefined8 uVar1;
  wchar_t wVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  wchar_t *pwVar5;
  wchar_t wVar6;
  wchar_t *pwVar7;
  
  pwVar4 = param_9;
  uVar1 = param_8;
  pwVar5 = L"NULL";
  wVar6 = L'\b';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) ||
     (*(byte *)(WPP_GLOBAL_Control + 0x29) < param_2)) goto LAB_14000290c;
  if (param_9 == (wchar_t *)0x0) {
    wVar2 = L'\b';
LAB_140002865:
    pwVar7 = L"NULL";
  }
  else {
    wVar2 = *param_9;
    if (*param_9 == L'\0') goto LAB_140002865;
    pwVar7 = *(wchar_t **)(param_9 + 4);
  }
  pwVar3 = param_9;
  if (param_9 == (wchar_t *)0x0) {
    pwVar3 = L"\b";
  }
  (*pfnWppTraceMessage)
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
             &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,param_4,
             "onecore\\base\\fs\\wci\\wcifs\\utils.c",0x22,&param_7,4,param_8,0x10,pwVar3,2,pwVar7,
             wVar2,&param_10,4,0);
LAB_14000290c:
  if ((pwVar4 != (wchar_t *)0x0) && (wVar6 = *pwVar4, *pwVar4 != L'\0')) {
    pwVar5 = *(wchar_t **)(pwVar4 + 4);
  }
  if (pwVar4 == (wchar_t *)0x0) {
    pwVar4 = L"\b";
  }
  WppAutoLogTrace(param_1,param_2,5,&WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,param_4,
                  "onecore\\base\\fs\\wci\\wcifs\\utils.c",0x22,&param_7,4,uVar1,0x10,pwVar4,2,
                  pwVar5,wVar6,&param_10,4,0);
  return;
}



===== WcIsSourcedStream @ 1400029d4 =====

ulonglong WcIsSourcedStream(longlong param_1)

{
  ulonglong *puVar1;
  byte bVar2;
  undefined7 extraout_var;
  ulonglong uVar3;
  
  puVar1 = (ulonglong *)(param_1 + 0x38);
  if ((ulonglong *)*puVar1 == puVar1) {
    uVar3 = (ulonglong)puVar1 & 0xffffffffffffff00;
  }
  else {
    bVar2 = WcIsExpanded(*(longlong *)(param_1 + 0x20));
    uVar3 = CONCAT71(extraout_var,bVar2 == 0);
  }
  return uVar3;
}



===== WcIsExpanded @ 140002a00 =====

byte WcIsExpanded(longlong param_1)

{
  undefined4 uVar1;
  
  ExAcquireFastMutex(param_1 + 8);
  uVar1 = *(undefined4 *)(param_1 + 0x58);
  ExReleaseFastMutex(param_1 + 8);
  return (byte)uVar1 & 1;
}



===== WcFreeEnumContexts @ 140002a4c =====

void WcFreeEnumContexts(longlong *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  
  while( true ) {
    plVar1 = (longlong *)*param_1;
    if (plVar1 == param_1) {
      return;
    }
    if (plVar1[9] != 0) {
      ExFreePoolWithTag(plVar1[9],0x6e654357);
    }
    lVar2 = *plVar1;
    if ((*(longlong **)(lVar2 + 8) != plVar1) ||
       (plVar3 = (longlong *)plVar1[1], (longlong *)*plVar3 != plVar1)) break;
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    ExFreeToPagedLookasideList(&DAT_14000f480,plVar1);
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== WPP_RECORDER_SF_sDd @ 140002ac8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDd(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,char *param_6,undefined1 param_7,undefined1 param_8)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  uVar4 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar4 * 0x14) * 4) >> (param_3 - 1 & 0x1f)
       & 1) != 0) && (param_2 <= *(byte *)(WPP_GLOBAL_Control + 0x29 + uVar4 * 0x50))) {
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
    pcVar1 = param_6;
    if (param_6 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18 + uVar4 * 0x50),0x2b,param_5,param_4,pcVar1
               ,lVar3,&param_7,4,&param_8,4,0);
  }
  lVar3 = -1;
  if (param_6 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (param_6[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_6 == (char *)0x0) {
    param_6 = "NULL";
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,param_6,lVar2,&param_7,4,&param_8,4,0);
  return;
}



===== WcUsesSourceSectionObjectPointers @ 140002c7c =====

ulonglong WcUsesSourceSectionObjectPointers(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong *in_RAX;
  
  if (param_2 != 0) {
    in_RAX = (longlong *)(param_2 + 0x38);
    if ((longlong *)*in_RAX != in_RAX) {
      lVar1 = *(longlong *)(*(longlong *)(((longlong *)*in_RAX)[3] + 0x10) + 0x28);
      return CONCAT71((int7)((ulonglong)lVar1 >> 8),*(longlong *)(param_1 + 0x28) == lVar1);
    }
  }
  return (ulonglong)in_RAX & 0xffffffffffffff00;
}



===== WPP_RECORDER_SF_sDZ @ 140002cac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDZ(undefined8 param_1,byte param_2,ulonglong param_3,undefined2 param_4,
                        undefined8 param_5,char *param_6,undefined1 param_7,wchar_t *param_8)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  wchar_t *pwVar4;
  wchar_t wVar5;
  wchar_t wVar6;
  wchar_t *pwVar7;
  uint uVar8;
  wchar_t *pwVar9;
  wchar_t *pwVar10;
  ulonglong uVar11;
  
  pwVar4 = param_8;
  uVar8 = (int)param_3 - 1;
  pwVar10 = L"NULL";
  uVar11 = (param_3 & 0xffffffff) >> 0x10;
  wVar5 = L'\b';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c + ((ulonglong)(uVar8 >> 5 & 0x7ff) + uVar11 * 0x14) * 4)
        >> (uVar8 & 0x1f) & 1) == 0) ||
     (*(byte *)(WPP_GLOBAL_Control + 0x29 + uVar11 * 0x50) < param_2)) goto LAB_140002e2c;
  if (param_8 == (wchar_t *)0x0) {
    wVar6 = L'\b';
LAB_140002d67:
    pwVar9 = L"NULL";
  }
  else {
    wVar6 = *param_8;
    if (*param_8 == L'\0') goto LAB_140002d67;
    pwVar9 = *(wchar_t **)(param_8 + 4);
  }
  pwVar7 = param_8;
  if (param_8 == (wchar_t *)0x0) {
    pwVar7 = L"\b";
  }
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
  pcVar1 = param_6;
  if (param_6 == (char *)0x0) {
    pcVar1 = "NULL";
  }
  (*pfnWppTraceMessage)
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18 + uVar11 * 0x50),0x2b,param_5,param_4,pcVar1,
             lVar3,&param_7,4,pwVar7,2,pwVar9,wVar6,0);
  param_3 = param_3 & 0xffffffff;
LAB_140002e2c:
  if ((pwVar4 != (wchar_t *)0x0) && (wVar5 = *pwVar4, *pwVar4 != L'\0')) {
    pwVar10 = *(wchar_t **)(pwVar4 + 4);
  }
  if (pwVar4 == (wchar_t *)0x0) {
    pwVar4 = L"\b";
  }
  lVar3 = -1;
  if (param_6 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (param_6[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_6 == (char *)0x0) {
    param_6 = "NULL";
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,param_6,lVar2,&param_7,4,pwVar4,2,pwVar10,
                  wVar5,0);
  return;
}



===== RtlUShortAdd @ 140002ee4 =====

uint RtlUShortAdd(ushort param_1,short param_2,ushort *param_3)

{
  ushort uVar1;
  bool bVar2;
  
  uVar1 = param_2 + param_1;
  bVar2 = uVar1 < param_1;
  if (bVar2) {
    uVar1 = 0xffff;
  }
  *param_3 = uVar1;
  return -(uint)bVar2 & 0xc0000095;
}



===== WcGetSource @ 140002f0c =====

undefined8 WcGetSource(longlong param_1)

{
  return *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 0x18);
}



===== WcIsSourceAvailable @ 140002f1c =====

undefined8 WcIsSourceAvailable(longlong param_1)

{
  longlong *plVar1;
  
  plVar1 = (longlong *)(param_1 + 0x38);
  return CONCAT71((int7)((ulonglong)plVar1 >> 8),(longlong *)*plVar1 != plVar1);
}



===== WcSetupVolumeInformationHandler @ 140002f30 =====

int WcSetupVolumeInformationHandler(int *param_1,uint param_2)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  undefined2 uVar6;
  longlong local_res8;
  uint local_res10 [2];
  longlong local_res18;
  longlong local_res20;
  undefined8 in_stack_fffffffffffffef8;
  undefined4 uVar7;
  undefined8 *puVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  undefined8 in_stack_ffffffffffffff18;
  undefined4 uVar11;
  undefined8 local_a8;
  longlong lStack_a0;
  undefined8 local_98;
  longlong local_90;
  undefined8 local_88;
  int *piStack_80;
  undefined8 local_78;
  int *piStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 *local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  uVar7 = (undefined4)((ulonglong)in_stack_fffffffffffffef8 >> 0x20);
  uVar11 = (undefined4)((ulonglong)in_stack_ffffffffffffff18 >> 0x20);
  local_res8 = 0;
  local_48 = 0;
  uStack_40 = uStack_40 & 0xffffffff00000000;
  local_90 = 0;
  local_res20 = 0;
  local_res10[0] = 0;
  iVar4 = 0;
  local_res18 = 0;
  local_78 = 0;
  piStack_70 = (int *)0x0;
  local_98 = 0;
  local_88 = 0;
  piStack_80 = (int *)0x0;
  local_a8 = 0;
  lStack_a0 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = (undefined8 *)0x0;
  uStack_50 = 0;
  local_38 = 0;
  uStack_30 = 0;
  RtlInitUnicodeString(&local_a8,0);
  uVar2 = param_1[1];
  if (param_2 < uVar2) {
    iVar4 = -0x3ffffff3;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14000341e;
    uVar10 = 0xd;
    uVar6 = 0x3b;
    uVar9 = 0xcf;
  }
  else if (*param_1 == 0x78) {
    if (uVar2 < 0x74) {
      iVar4 = -0x3ffffff3;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14000341e;
      uVar10 = 0xd;
      uVar6 = 0x3d;
      uVar9 = 0xdb;
    }
    else {
      uVar1 = *(ushort *)((longlong)param_1 + 0x72);
      if (uVar2 < uVar1 + 0x74) {
        iVar4 = -0x3ffffff3;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14000341e;
        uVar10 = 0xd;
        uVar6 = 0x3e;
        uVar9 = 0xe2;
      }
      else {
        piStack_70 = param_1 + 0x1d;
        local_88._0_4_ = CONCAT22((short)param_1[0x1c],(short)param_1[0x1c]);
        piStack_80 = param_1 + 3;
        local_78._0_4_ = CONCAT22(uVar1,uVar1);
        iVar3 = RtlCompareUnicodeString(&local_88,&DAT_14000a000,0);
        if (iVar3 != 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,0xe,0x3f,
                               &WPP_52759b377eea39e2466a1234853e56fe_Traceguids,
                               "onecore\\base\\fs\\wci\\wcifs\\message.c",0xf9);
          }
          goto LAB_14000341e;
        }
        iVar4 = WcGetInstanceFromVolumeName(&local_78,&local_88,&local_res8);
        if (iVar4 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_14000341e;
          uVar10 = (undefined1)iVar4;
          uVar6 = 0x40;
          uVar9 = 2;
        }
        else {
          iVar4 = FltCreateSystemVolumeInformationFolder(local_res8);
          if (iVar4 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_14000341e;
            uVar10 = (undefined1)iVar4;
            uVar6 = 0x41;
            uVar9 = 9;
          }
          else {
            iVar4 = FltGetVolumeFromName(Globals,&local_78,&local_res18);
            if (iVar4 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
              goto LAB_14000341e;
              uVar10 = (undefined1)iVar4;
              uVar6 = 0x42;
              uVar9 = 0x10;
            }
            else {
              iVar4 = FltGetVolumeName(local_res18,0,local_res10);
              if (iVar4 != -0x3fffffdd) {
                iVar4 = -0x3ffffff0;
                goto LAB_14000341e;
              }
              uVar2 = (local_res10[0] & 0xffff) * 2;
              if (((0xffff < uVar2) || (uVar1 = (ushort)uVar2, (ushort)(uVar1 + 8) < uVar1)) ||
                 ((ushort)(uVar1 + 0x50) < (ushort)(uVar1 + 8))) {
                local_a8._0_4_ = CONCAT22(0xffff,(undefined2)local_a8);
                iVar4 = -0x3fffff6b;
                goto LAB_14000341e;
              }
              local_a8._0_4_ = CONCAT22(uVar1 + 0x50,(undefined2)local_a8);
              uVar5 = WcAllocateUnicodeString(0x6e664357,(undefined2 *)&local_a8);
              iVar4 = (int)uVar5;
              if (iVar4 < 0) goto LAB_14000341e;
              iVar4 = FltGetVolumeName(local_res18,&local_a8,local_res10);
              if (iVar4 < 0) goto LAB_14000341e;
              iVar4 = RtlAppendUnicodeToString(&local_a8,L"\\System Volume Information\\Wcifs.md");
              if (iVar4 < 0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                goto LAB_14000341e;
                uVar10 = (undefined1)iVar4;
                uVar6 = 0x43;
                uVar9 = 0x3e;
              }
              else {
                local_58 = &local_a8;
                puVar8 = &local_68;
                local_68 = CONCAT44(local_68._4_4_,0x30);
                uStack_60 = 0;
                uStack_50 = CONCAT44(uStack_50._4_4_,0x200);
                local_48 = 0;
                uStack_40 = 0;
                iVar4 = FltCreateFileEx(Globals,local_res8,&local_90,&local_res20,
                                        CONCAT44(uVar7,0x1f01ff),puVar8,&local_38,0,
                                        CONCAT44(uVar11,6),1,3,0,0,0,0);
                if (iVar4 < 0) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                  goto LAB_14000341e;
                  uVar10 = (undefined1)iVar4;
                  uVar6 = 0x44;
                  uVar9 = 0x59;
                }
                else {
                  local_98 = 0;
                  iVar4 = FltWriteFile(local_res8,local_res20,&local_98,4,param_1 + 2,
                                       (ulonglong)puVar8 & 0xffffffff00000000,0,0,0);
                  if ((-1 < iVar4) ||
                     ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED))
                  goto LAB_14000341e;
                  uVar10 = (undefined1)iVar4;
                  uVar6 = 0x45;
                  uVar9 = 0x6a;
                }
              }
            }
          }
        }
      }
    }
  }
  else {
    iVar4 = -0x3ffffff3;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14000341e;
    uVar10 = 0xd;
    uVar6 = 0x3c;
    uVar9 = 0xd5;
  }
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xe,uVar6,
                      &WPP_52759b377eea39e2466a1234853e56fe_Traceguids,
                      "onecore\\base\\fs\\wci\\wcifs\\message.c",uVar9,uVar10);
LAB_14000341e:
  if (lStack_a0 != 0) {
    ExFreePoolWithTag(lStack_a0,0x6e664357);
  }
  if (local_res20 != 0) {
    ObfDereferenceObject();
  }
  if (local_90 != 0) {
    FltClose();
  }
  if (local_res8 != 0) {
    FltObjectDereference();
  }
  if (local_res18 != 0) {
    FltObjectDereference();
  }
  return iVar4;
}



===== RtlUShortSub @ 1400034a4 =====

uint RtlUShortSub(ushort param_1,ushort param_2,short *param_3)

{
  short sVar1;
  
  if (param_1 < param_2) {
    sVar1 = -1;
  }
  else {
    sVar1 = param_1 - param_2;
  }
  *param_3 = sVar1;
  return -(uint)(param_1 < param_2) & 0xc0000095;
}



===== WPP_RECORDER_SF_sDlLD @ 1400034d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDlLD
               (undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined8 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) &&
     (param_2 <= *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_27ac746799d63ca1d37704ce911b8053_Traceguids,param_4,
               "onecore\\base\\fs\\wci\\wcifs\\wcifs.c",0x22,&param_7,4,&param_8,4,&param_9,4,
               &param_10,4,0);
  }
  WppAutoLogTrace(param_1,param_2,4,&WPP_27ac746799d63ca1d37704ce911b8053_Traceguids,param_4,
                  "onecore\\base\\fs\\wci\\wcifs\\wcifs.c",0x22,&param_7,4,&param_8,4,&param_9,4,
                  &param_10,4,0);
  return;
}



===== WcClearOfflineAttribute @ 140003614 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int WcClearOfflineAttribute(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined2 uVar2;
  undefined1 auStackY_78 [32];
  undefined1 uVar3;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  iVar1 = FltQueryInformationFile(param_2,param_1,&local_38,0x28);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar2 = 0x7e;
    uVar3 = 0x68;
  }
  else {
    local_18 = local_18 & 0xffffffffffffefff;
    iVar1 = FltSetInformationFile(param_2,param_1,&local_38,0x28);
    if (-1 < iVar1) {
      return iVar1;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar2 = 0x7f;
    uVar3 = 0x77;
  }
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xf,uVar2,
                      &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                      "onecore\\base\\fs\\wci\\wcifs\\utils.c",uVar3,(char)iVar1);
  return iVar1;
}



===== WcCopyAsPlaceHolderWorker @ 140003750 =====

void WcCopyAsPlaceHolderWorker(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  uint uVar1;
  
  uVar1 = WcCopyAsPlaceHolder(*param_3,param_3[1],param_3[2],(wchar_t *)param_3[3],param_3[4],
                              param_3[5],param_3[6],param_3[7],*(int *)(param_3 + 8),
                              (byte)*(undefined4 *)((longlong)param_3 + 100));
  *(uint *)(param_3 + 0xc) = uVar1;
  if (((int)uVar1 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xf,0xa0,
                        &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                        "onecore\\base\\fs\\wci\\wcifs\\utils.c",99,(char)uVar1);
  }
  KeSetEvent(param_3 + 9,0,0);
  FltFreeGenericWorkItem(param_1);
  return;
}



===== McGenEventRegister_EtwRegister @ 140003838 =====

void McGenEventRegister_EtwRegister(void)

{
  if (PROV_WCIFS_Context == 0) {
    EtwRegister(&PROV_WCIFS,McGenControlCallbackV2,&PROV_WCIFS_Context,&PROV_WCIFS_Context);
  }
  return;
}



===== WPP_RECORDER_SF_sDDqDlZ @ 140003878 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDDqDlZ(undefined8 param_1)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  wchar_t *in_stack_00000060;
  undefined4 local_28 [4];
  
  pwVar4 = L"NULL";
  local_28[0] = 0xaea;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) ||
     (*(byte *)(WPP_GLOBAL_Control + 0x29) < 3)) goto LAB_1400039d4;
  if (in_stack_00000060 == (wchar_t *)0x0) {
    wVar2 = L'\b';
LAB_1400038fc:
    pwVar3 = L"NULL";
  }
  else {
    wVar2 = *in_stack_00000060;
    if (*in_stack_00000060 == L'\0') goto LAB_1400038fc;
    pwVar3 = *(wchar_t **)(in_stack_00000060 + 4);
  }
  pwVar1 = in_stack_00000060;
  if (in_stack_00000060 == (wchar_t *)0x0) {
    pwVar1 = L"\b";
  }
  (*pfnWppTraceMessage)
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
             &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,0x3d,
             "onecore\\base\\fs\\wci\\wcifs\\create.c",0x23,local_28,4,&uStack0000000000000040,4,
             &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,pwVar1,2,
             pwVar3,wVar2,0);
LAB_1400039d4:
  if (in_stack_00000060 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *in_stack_00000060;
    if (*in_stack_00000060 != L'\0') {
      pwVar4 = *(wchar_t **)(in_stack_00000060 + 4);
    }
  }
  if (in_stack_00000060 == (wchar_t *)0x0) {
    in_stack_00000060 = L"\b";
  }
  WppAutoLogTrace(param_1,3,5,&WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,0x3d,
                  "onecore\\base\\fs\\wci\\wcifs\\create.c",0x23,local_28,4,&uStack0000000000000040,
                  4,&uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  in_stack_00000060,2,pwVar4,wVar2,0);
  return;
}



===== wil_details_FeatureDescriptors_SkipPadding @ 140003ad4 =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_14000e227 < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== McTemplateK0_EtwWriteTransfer @ 140003b00 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0_EtwWriteTransfer(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 auStackY_58 [32];
  undefined8 local_28 [2];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_58;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,1,local_28);
  return;
}



===== WcSyncPlaceholderFileSize @ 140003b44 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int WcSyncPlaceholderFileSize
              (undefined8 param_1,undefined8 param_2,longlong param_3,longlong param_4)

{
  undefined8 *puVar1;
  int iVar2;
  undefined2 uVar3;
  undefined1 auStackY_98 [32];
  undefined1 uVar4;
  longlong local_58;
  longlong local_50 [5];
  
  local_50[4] = __security_cookie ^ (ulonglong)auStackY_98;
  local_50[3] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  puVar1 = *(undefined8 **)(*(longlong *)(param_3 + 0x38) + 0x18);
  iVar2 = FltQueryInformationFile(*puVar1,puVar1[2],local_50 + 1,0x18);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar2;
    }
    uVar3 = 0xbe;
    uVar4 = 0x7f;
  }
  else {
    if (param_4 == local_50[2]) {
      return iVar2;
    }
    local_58 = local_50[2];
    local_50[0] = local_50[2];
    iVar2 = FltSetInformationFile(param_1,param_2,&local_58,8);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar2;
      }
      uVar3 = 0xbf;
      uVar4 = 0x93;
    }
    else {
      iVar2 = FltSetInformationFile(param_1,param_2,local_50,8);
      if (-1 < iVar2) {
        *(longlong *)(param_3 + 0x48) = local_50[2];
        return iVar2;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar2;
      }
      uVar3 = 0xc0;
      uVar4 = 0xa2;
    }
  }
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xd,uVar3,
                      &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                      "onecore\\base\\fs\\wci\\wcifs\\utils.c",uVar4,(char)iVar2);
  return iVar2;
}



===== WcIsInstanceUnionRootDirectory @ 140003cf4 =====

bool WcIsInstanceUnionRootDirectory(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  bool bVar2;
  undefined4 local_res18 [2];
  longlong local_res20;
  longlong local_38 [4];
  
  local_res20 = 0;
  local_38[0] = 0;
  local_res18[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  bVar2 = false;
  RtlInitUnicodeString(local_38 + 1,0);
  iVar1 = FltGetInstanceContext(param_1,&local_res20);
  if (((-1 < iVar1) && (*(longlong *)(local_res20 + 0x38) != 0)) &&
     (iVar1 = FltQueryInformationFile(param_1,param_2,local_38,8,6,local_res18), -1 < iVar1)) {
    bVar2 = local_38[0] == *(longlong *)(local_res20 + 0x120);
  }
  if (local_res20 != 0) {
    FltReleaseContext();
  }
  return bVar2;
}



===== McGenEventWrite_EtwWriteTransfer @ 140003dd0 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_14000f018;
  uVar2 = 0;
  if (DAT_14000f018 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_14000f018;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(PROV_WCIFS_Context,param_2,0,0,param_4,param_5);
  return;
}



===== WcCloseHandleAsync @ 140003e34 =====

void WcCloseHandleAsync(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  iVar1 = FltQueueGenericWorkItem(param_2,Globals,WcCloseHandleAsyncWorker,1,param_1);
  if (iVar1 < 0) {
    FltFreeGenericWorkItem(param_2);
    FltClose(param_1);
  }
  return;
}



===== __report_gsfailure @ 140003eb0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 140003ebd =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140003ebd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== WPP_RECORDER_SF_sD @ 140003ed0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sD(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,char *param_6,undefined1 param_7)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  uVar4 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar4 * 0x14) * 4) >> (param_3 - 1 & 0x1f)
       & 1) != 0) && (param_2 <= *(byte *)(WPP_GLOBAL_Control + 0x29 + uVar4 * 0x50))) {
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
    pcVar1 = param_6;
    if (param_6 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18 + uVar4 * 0x50),0x2b,param_5,param_4,pcVar1
               ,lVar3,&param_7,4,0);
  }
  lVar3 = -1;
  if (param_6 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (param_6[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_6 == (char *)0x0) {
    param_6 = "NULL";
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,param_6,lVar2,&param_7,4,0);
  return;
}



===== Feature_944920889__private_IsEnabledDeviceUsageNoInline @ 140004058 =====

ulonglong Feature_944920889__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  undefined4 *local_res8;
  
  local_res8 = (undefined4 *)(ulonglong)Feature_944920889__private_featureState;
  if ((Feature_944920889__private_featureState & 0x10) == 0) {
    uVar1 = Feature_944920889__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_944920889__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_944920889__private_IsEnabledFallback @ 140004090 =====

void Feature_944920889__private_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2);
  return;
}



===== WPP_RECORDER_SF_sDDld @ 1400040a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDDld(undefined8 param_1)

{
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined4 local_18 [4];
  
  local_18[0] = 0xb6e;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) &&
     (1 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,0x40,
               "onecore\\base\\fs\\wci\\wcifs\\create.c",0x23,local_18,4,&uStack0000000000000040,4,
               &uStack0000000000000048,4,&uStack0000000000000050,4,0);
  }
  WppAutoLogTrace(param_1,2,5,&WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,0x40,
                  "onecore\\base\\fs\\wci\\wcifs\\create.c",0x23,local_18,4,&uStack0000000000000040,
                  4,&uStack0000000000000048,4,&uStack0000000000000050,4,0);
  return;
}



===== WPP_RECORDER_SF_sDZDld @ 1400041f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDZDld(undefined8 param_1)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  wchar_t wVar4;
  wchar_t *pwVar5;
  wchar_t *in_stack_00000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined4 local_28 [4];
  
  pwVar3 = L"NULL";
  local_28[0] = 0xb23;
  wVar4 = L'\b';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) ||
     (*(byte *)(WPP_GLOBAL_Control + 0x29) < 2)) goto LAB_140004339;
  if (in_stack_00000040 == (wchar_t *)0x0) {
    wVar1 = L'\b';
LAB_140004276:
    pwVar5 = L"NULL";
  }
  else {
    wVar1 = *in_stack_00000040;
    if (*in_stack_00000040 == L'\0') goto LAB_140004276;
    pwVar5 = *(wchar_t **)(in_stack_00000040 + 4);
  }
  pwVar2 = in_stack_00000040;
  if (in_stack_00000040 == (wchar_t *)0x0) {
    pwVar2 = L"\b";
  }
  (*pfnWppTraceMessage)
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
             &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,0x3e,
             "onecore\\base\\fs\\wci\\wcifs\\create.c",0x23,local_28,4,pwVar2,2,pwVar5,wVar1,
             &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,0);
LAB_140004339:
  if ((in_stack_00000040 != (wchar_t *)0x0) &&
     (wVar4 = *in_stack_00000040, *in_stack_00000040 != L'\0')) {
    pwVar3 = *(wchar_t **)(in_stack_00000040 + 4);
  }
  if (in_stack_00000040 == (wchar_t *)0x0) {
    in_stack_00000040 = L"\b";
  }
  WppAutoLogTrace(param_1,2,5,&WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,0x3e,
                  "onecore\\base\\fs\\wci\\wcifs\\create.c",0x23,local_28,4,in_stack_00000040,2,
                  pwVar3,wVar4,&uStack0000000000000048,4,&uStack0000000000000050,4,
                  &uStack0000000000000058,4,0);
  return;
}



===== WPP_RECORDER_SF_sDZZd @ 14000441c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDZZd(void)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  wchar_t wVar5;
  wchar_t wVar6;
  undefined2 in_R9W;
  wchar_t *pwVar7;
  wchar_t *pwVar8;
  undefined1 uStack0000000000000038;
  wchar_t *in_stack_00000040;
  wchar_t *in_stack_00000048;
  undefined1 uStack0000000000000050;
  
  pwVar4 = L"NULL";
  wVar5 = L'\b';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0) &&
     (4 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    if (in_stack_00000048 == (wchar_t *)0x0) {
      wVar1 = L'\b';
LAB_1400044a6:
      pwVar3 = L"NULL";
    }
    else {
      wVar1 = *in_stack_00000048;
      if (*in_stack_00000048 == L'\0') goto LAB_1400044a6;
      pwVar3 = *(wchar_t **)(in_stack_00000048 + 4);
    }
    pwVar7 = in_stack_00000048;
    if (in_stack_00000048 == (wchar_t *)0x0) {
      pwVar7 = L"\b";
    }
    if (in_stack_00000040 == (wchar_t *)0x0) {
      wVar6 = L'\b';
LAB_1400044cb:
      pwVar8 = L"NULL";
    }
    else {
      wVar6 = *in_stack_00000040;
      if (*in_stack_00000040 == L'\0') goto LAB_1400044cb;
      pwVar8 = *(wchar_t **)(in_stack_00000040 + 4);
    }
    pwVar2 = in_stack_00000040;
    if (in_stack_00000040 == (wchar_t *)0x0) {
      pwVar2 = L"\b";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,in_R9W,
               "onecore\\base\\fs\\wci\\wcifs\\create.c",0x23,&uStack0000000000000038,4,pwVar2,2,
               pwVar8,wVar6,pwVar7,2,pwVar3,wVar1,&uStack0000000000000050,4,0);
  }
  if (in_stack_00000048 == (wchar_t *)0x0) {
    wVar1 = L'\b';
  }
  else {
    wVar1 = *in_stack_00000048;
    if (*in_stack_00000048 != L'\0') {
      pwVar3 = *(wchar_t **)(in_stack_00000048 + 4);
      goto LAB_14000459b;
    }
  }
  pwVar3 = L"NULL";
LAB_14000459b:
  if (in_stack_00000048 == (wchar_t *)0x0) {
    in_stack_00000048 = L"\b";
  }
  if ((in_stack_00000040 != (wchar_t *)0x0) &&
     (wVar5 = *in_stack_00000040, *in_stack_00000040 != L'\0')) {
    pwVar4 = *(wchar_t **)(in_stack_00000040 + 4);
  }
  if (in_stack_00000040 == (wchar_t *)0x0) {
    in_stack_00000040 = L"\b";
  }
  WppAutoLogTrace(0,5,10,&WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,in_R9W,
                  "onecore\\base\\fs\\wci\\wcifs\\create.c",0x23,&uStack0000000000000038,4,
                  in_stack_00000040,2,pwVar4,wVar5,in_stack_00000048,2,pwVar3,wVar1,
                  &uStack0000000000000050,4,0);
  return;
}



===== WPP_RECORDER_SF_sDZd @ 14000467c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDZd
               (undefined8 param_1,byte param_2,ulonglong param_3,undefined2 param_4,
               undefined8 param_5,char *param_6,undefined1 param_7,wchar_t *param_8,
               undefined1 param_9)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  wchar_t *pwVar4;
  wchar_t wVar5;
  wchar_t wVar6;
  wchar_t *pwVar7;
  uint uVar8;
  wchar_t *pwVar9;
  wchar_t *pwVar10;
  ulonglong uVar11;
  
  pwVar4 = param_8;
  uVar8 = (int)param_3 - 1;
  pwVar10 = L"NULL";
  uVar11 = (param_3 & 0xffffffff) >> 0x10;
  wVar5 = L'\b';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c + ((ulonglong)(uVar8 >> 5 & 0x7ff) + uVar11 * 0x14) * 4)
        >> (uVar8 & 0x1f) & 1) == 0) ||
     (*(byte *)(WPP_GLOBAL_Control + 0x29 + uVar11 * 0x50) < param_2)) goto LAB_140004815;
  if (param_8 == (wchar_t *)0x0) {
    wVar6 = L'\b';
LAB_14000473a:
    pwVar9 = L"NULL";
  }
  else {
    wVar6 = *param_8;
    if (*param_8 == L'\0') goto LAB_14000473a;
    pwVar9 = *(wchar_t **)(param_8 + 4);
  }
  pwVar7 = param_8;
  if (param_8 == (wchar_t *)0x0) {
    pwVar7 = L"\b";
  }
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
  pcVar1 = param_6;
  if (param_6 == (char *)0x0) {
    pcVar1 = "NULL";
  }
  (*pfnWppTraceMessage)
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18 + uVar11 * 0x50),0x2b,param_5,param_4,pcVar1,
             lVar3,&param_7,4,pwVar7,2,pwVar9,wVar6,&param_9,4,0);
  param_3 = param_3 & 0xffffffff;
LAB_140004815:
  if ((pwVar4 != (wchar_t *)0x0) && (wVar5 = *pwVar4, *pwVar4 != L'\0')) {
    pwVar10 = *(wchar_t **)(pwVar4 + 4);
  }
  if (pwVar4 == (wchar_t *)0x0) {
    pwVar4 = L"\b";
  }
  lVar3 = -1;
  if (param_6 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (param_6[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_6 == (char *)0x0) {
    param_6 = "NULL";
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,param_6,lVar2,&param_7,4,pwVar4,2,pwVar10,
                  wVar5,&param_9,4,0);
  return;
}



===== WPP_RECORDER_SF_sDdZ @ 1400048e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDdZ
               (undefined8 param_1,byte param_2,ulonglong param_3,undefined2 param_4,
               undefined8 param_5,char *param_6,undefined1 param_7,undefined1 param_8,
               wchar_t *param_9)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  wchar_t *pwVar4;
  wchar_t wVar5;
  wchar_t wVar6;
  wchar_t *pwVar7;
  uint uVar8;
  wchar_t *pwVar9;
  wchar_t *pwVar10;
  ulonglong uVar11;
  
  pwVar4 = param_9;
  uVar8 = (int)param_3 - 1;
  pwVar10 = L"NULL";
  uVar11 = (param_3 & 0xffffffff) >> 0x10;
  wVar5 = L'\b';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c + ((ulonglong)(uVar8 >> 5 & 0x7ff) + uVar11 * 0x14) * 4)
        >> (uVar8 & 0x1f) & 1) == 0) ||
     (*(byte *)(WPP_GLOBAL_Control + 0x29 + uVar11 * 0x50) < param_2)) goto LAB_140004a7f;
  if (param_9 == (wchar_t *)0x0) {
    wVar6 = L'\b';
LAB_1400049a6:
    pwVar9 = L"NULL";
  }
  else {
    wVar6 = *param_9;
    if (*param_9 == L'\0') goto LAB_1400049a6;
    pwVar9 = *(wchar_t **)(param_9 + 4);
  }
  pwVar7 = param_9;
  if (param_9 == (wchar_t *)0x0) {
    pwVar7 = L"\b";
  }
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
  pcVar1 = param_6;
  if (param_6 == (char *)0x0) {
    pcVar1 = "NULL";
  }
  (*pfnWppTraceMessage)
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18 + uVar11 * 0x50),0x2b,param_5,param_4,pcVar1,
             lVar3,&param_7,4,&param_8,4,pwVar7,2,pwVar9,wVar6,0);
  param_3 = param_3 & 0xffffffff;
LAB_140004a7f:
  if ((pwVar4 != (wchar_t *)0x0) && (wVar5 = *pwVar4, *pwVar4 != L'\0')) {
    pwVar10 = *(wchar_t **)(pwVar4 + 4);
  }
  if (pwVar4 == (wchar_t *)0x0) {
    pwVar4 = L"\b";
  }
  lVar3 = -1;
  if (param_6 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (param_6[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_6 == (char *)0x0) {
    param_6 = "NULL";
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,param_6,lVar2,&param_7,4,&param_8,4,pwVar4
                  ,2,pwVar10,wVar5,0);
  return;
}



===== WPP_RECORDER_SF_sDdd @ 140004b50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDdd
               (undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,undefined8 param_5,
               char *param_6,undefined1 param_7,undefined1 param_8,undefined1 param_9)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  uVar4 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar4 * 0x14) * 4) >> (param_3 - 1 & 0x1f)
       & 1) != 0) && (param_2 <= *(byte *)(WPP_GLOBAL_Control + 0x29 + uVar4 * 0x50))) {
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
    pcVar1 = param_6;
    if (param_6 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18 + uVar4 * 0x50),0x2b,param_5,param_4,pcVar1
               ,lVar3,&param_7,4,&param_8,4,&param_9,4,0);
  }
  lVar3 = -1;
  if (param_6 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (param_6[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_6 == (char *)0x0) {
    param_6 = "NULL";
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,param_6,lVar2,&param_7,4,&param_8,4,
                  &param_9,4,0);
  return;
}



===== WPP_RECORDER_SF_sDq @ 140004d28 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDq(undefined8 param_1)

{
  undefined1 uStack0000000000000040;
  undefined4 local_18 [4];
  
  local_18[0] = 0x2be;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) &&
     (2 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,0x14,
               "onecore\\base\\fs\\wci\\wcifs\\create.c",0x23,local_18,4,&uStack0000000000000040,8,0
              );
  }
  WppAutoLogTrace(param_1,3,5,&WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,0x14,
                  "onecore\\base\\fs\\wci\\wcifs\\create.c",0x23,local_18,4,&uStack0000000000000040,
                  8,0);
  return;
}



===== WPP_RECORDER_SF_sDqDld @ 140004e30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDqDld
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined8 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) &&
     (1 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,param_4,
               "onecore\\base\\fs\\wci\\wcifs\\create.c",0x23,&param_7,4,&param_8,8,&param_9,4,
               &param_10,4,&param_11,4,0);
  }
  WppAutoLogTrace(param_1,2,5,&WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,param_4,
                  "onecore\\base\\fs\\wci\\wcifs\\create.c",0x23,&param_7,4,&param_8,8,&param_9,4,
                  &param_10,4,&param_11,4,0);
  return;
}



===== WPP_RECORDER_SF_sDqZDld @ 140004f9c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDqZDld(undefined8 param_1)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  undefined1 uStack0000000000000040;
  wchar_t *in_stack_00000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined4 local_28 [4];
  
  pwVar3 = L"NULL";
  local_28[0] = 0xab1;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) ||
     (*(byte *)(WPP_GLOBAL_Control + 0x29) < 4)) goto LAB_1400050fa;
  if (in_stack_00000048 == (wchar_t *)0x0) {
    wVar1 = L'\b';
LAB_14000501f:
    pwVar4 = L"NULL";
  }
  else {
    wVar1 = *in_stack_00000048;
    if (*in_stack_00000048 == L'\0') goto LAB_14000501f;
    pwVar4 = *(wchar_t **)(in_stack_00000048 + 4);
  }
  pwVar2 = in_stack_00000048;
  if (in_stack_00000048 == (wchar_t *)0x0) {
    pwVar2 = L"\b";
  }
  (*pfnWppTraceMessage)
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
             &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,0x3b,
             "onecore\\base\\fs\\wci\\wcifs\\create.c",0x23,local_28,4,&uStack0000000000000040,8,
             pwVar2,2,pwVar4,wVar1,&uStack0000000000000050,4,&uStack0000000000000058,4,
             &uStack0000000000000060,4,0);
LAB_1400050fa:
  if (in_stack_00000048 == (wchar_t *)0x0) {
    wVar1 = L'\b';
  }
  else {
    wVar1 = *in_stack_00000048;
    if (*in_stack_00000048 != L'\0') {
      pwVar3 = *(wchar_t **)(in_stack_00000048 + 4);
    }
  }
  if (in_stack_00000048 == (wchar_t *)0x0) {
    in_stack_00000048 = L"\b";
  }
  WppAutoLogTrace(param_1,4,5,&WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,0x3b,
                  "onecore\\base\\fs\\wci\\wcifs\\create.c",0x23,local_28,4,&uStack0000000000000040,
                  8,in_stack_00000048,2,pwVar3,wVar1,&uStack0000000000000050,4,
                  &uStack0000000000000058,4,&uStack0000000000000060,4,0);
  return;
}



===== WPP_RECORDER_SF_sDqd @ 1400051f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDqd
               (undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,undefined8 param_5,
               char *param_6,undefined1 param_7,undefined1 param_8,undefined1 param_9)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  uVar4 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar4 * 0x14) * 4) >> (param_3 - 1 & 0x1f)
       & 1) != 0) && (param_2 <= *(byte *)(WPP_GLOBAL_Control + 0x29 + uVar4 * 0x50))) {
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
    pcVar1 = param_6;
    if (param_6 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18 + uVar4 * 0x50),0x2b,param_5,param_4,pcVar1
               ,lVar3,&param_7,4,&param_8,8,&param_9,4,0);
  }
  lVar3 = -1;
  if (param_6 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (param_6[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_6 == (char *)0x0) {
    param_6 = "NULL";
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,param_6,lVar2,&param_7,4,&param_8,8,
                  &param_9,4,0);
  return;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 1400053d8 =====

void wil_details_FeatureReporting_IncrementOpportunityInCache
               (uint *param_1,uint param_2,undefined8 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = *param_1;
  do {
    uVar4 = uVar1;
    param_4[1] = 0;
    uVar1 = uVar4 | 1;
    if ((uVar4 >> 0x16 & 1) != (uint)(param_2 == 5)) {
      uVar3 = uVar4 >> 0xf & 0x7f;
      if (uVar3 != 0) {
        param_4[1] = uVar3;
        uVar3 = 5;
        if (param_2 != 1) {
          uVar3 = 1;
        }
        uVar1 = uVar4 & 0xffc07fff | 1;
        param_4[2] = uVar3;
      }
      uVar3 = 0;
      if (param_2 == 5) {
        uVar3 = 0x400000;
      }
      uVar1 = uVar3 | uVar1 & 0xffbfffff;
    }
    uVar2 = uVar1 >> 0xf & 0x7f;
    uVar3 = uVar2 + 1;
    if ((0x7f < uVar3) || (uVar3 < uVar2)) {
      uVar3 = 1;
      param_4[2] = param_2;
      param_4[1] = uVar2;
    }
    LOCK();
    uVar2 = *param_1;
    if (uVar4 == uVar2) {
      *param_1 = (uVar3 << 0xf ^ uVar1) & 0x3f8000 ^ uVar1;
      uVar1 = uVar4;
    }
    else {
      uVar1 = uVar2;
    }
    UNLOCK();
  } while (uVar4 != uVar2);
  param_4[4] = 0;
  *param_4 = ~uVar4 & 1;
  return;
}



===== wil_details_FeatureReporting_IncrementUsageInCache @ 1400054b0 =====

void wil_details_FeatureReporting_IncrementUsageInCache
               (uint *param_1,uint param_2,undefined8 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = *param_1;
  do {
    uVar3 = uVar1;
    param_4[1] = 0;
    uVar1 = uVar3 | 1;
    if ((uVar3 >> 0xe & 1) != (uint)(param_2 == 4)) {
      uVar4 = uVar3 >> 5 & 0x1ff;
      if (uVar4 != 0) {
        param_4[1] = uVar4;
        param_4[2] = ~-(uint)(param_2 != 0) & 4;
        uVar1 = uVar3 & 0xffffc01f | 1;
      }
      uVar4 = 0;
      if (param_2 == 4) {
        uVar4 = 0x4000;
      }
      uVar1 = uVar4 | uVar1 & 0xffffbfff;
    }
    uVar2 = uVar1 >> 5 & 0x1ff;
    uVar4 = uVar2 + 1;
    if ((0x1ff < uVar4) || (uVar4 < uVar2)) {
      uVar4 = 1;
      param_4[2] = param_2;
      param_4[1] = uVar2;
    }
    LOCK();
    uVar2 = *param_1;
    if (uVar3 == uVar2) {
      *param_1 = (uVar4 << 5 ^ uVar1) & 0x3fe0 ^ uVar1;
      uVar1 = uVar3;
    }
    else {
      uVar1 = uVar2;
    }
    UNLOCK();
  } while (uVar3 != uVar2);
  param_4[4] = 0;
  *param_4 = ~uVar3 & 1;
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 140005594 =====

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
LAB_1400056ec:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_1400056df:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_1400056ec;
      if (uVar5 == 5) goto LAB_1400056df;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 140005714 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (undefined8 param_1,undefined8 param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  undefined7 extraout_var;
  ulonglong uVar3;
  uint uVar4;
  uint local_res18 [4];
  
  uVar4 = (uint)param_2 & 1;
  uVar3 = (ulonglong)param_3;
  local_res18[0] = param_3;
  uVar2 = wil_details_MapReportingKind(param_3,uVar4);
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(uVar3,param_2,(ulonglong)uVar2);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (0x3ca4a10,&Feature_944920889_logged_traits,0,uVar4,local_res18,0,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140005790 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (undefined8 param_1,undefined8 param_2,ulonglong param_3)

{
  uint6 uVar1;
  uint *puVar2;
  undefined1 auStack_88 [32];
  uint *local_68;
  undefined8 local_58;
  uint local_50 [6];
  uint local_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_88;
  puVar2 = wil_details_FeatureReporting_RecordUsageInCache
                     (local_50,(uint *)&Feature_944920889__private_reporting,param_3,
                      (uint)((ulonglong)param_2 >> 0x20));
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_68 = &local_38;
    (*g_wil_details_recordFeatureUsage)
              (0x3ca4a10,param_3 & 0xffffffff,1,&Feature_944920889__private_reporting);
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && ((int)param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)(param_3 & 0xffffffff),0x3ca4a10);
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 14000587c =====

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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 14000598c =====

void wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  if (param_2 == 3) {
    uVar2 = 0x10;
  }
  else {
    if (param_2 != 4) {
      return;
    }
    uVar2 = 0x20;
  }
  if ((Feature_944920889__private_featureState & 2) != 0) {
    uVar1 = Feature_944920889__private_featureState;
    while ((uVar1 & 1) == (param_1 & 1)) {
      LOCK();
      bVar3 = uVar1 == Feature_944920889__private_featureState;
      if (bVar3) {
        Feature_944920889__private_featureState = uVar2 | uVar1;
      }
      else {
        uVar1 = Feature_944920889__private_featureState;
      }
      UNLOCK();
      if (bVar3) {
        return;
      }
      if ((uVar1 & 2) == 0) {
        return;
      }
    }
  }
  return;
}



===== wil_details_GetCurrentFeatureEnabledState @ 1400059e0 =====

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



===== wil_details_IsEnabledFallback @ 140005b40 =====

uint wil_details_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  ulonglong local_res18;
  
  local_res18 = (ulonglong)param_1 & 0xffffffff;
  if (((ulonglong)param_1 & 2) == 0) {
    puVar1 = &Feature_944920889__private_featureState;
    local_res18 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            (&Feature_944920889__private_featureState,(ulonglong)param_1,0x14000e1f0
                            );
    param_1 = puVar1;
    puVar1 = (undefined4 *)(local_res18 & 0xffffffff);
  }
  else {
    puVar1 = param_1;
  }
  if (param_2 != 0) {
    wil_details_FeatureReporting_ReportUsageToService(param_1,local_res18,param_2);
    if (param_2 - 3 < 2) {
      wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath((uint)local_res18,param_2);
    }
  }
  return (uint)puVar1 & 1;
}



===== wil_details_MapReportingKind @ 140005bd0 =====

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



===== WPP_RECORDER_SF_sDqZd @ 140005c70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDqZd
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined8 param_6,undefined1 param_7,undefined1 param_8,
               wchar_t *param_9,undefined1 param_10)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  wchar_t *pwVar5;
  
  pwVar3 = param_9;
  pwVar4 = L"NULL";
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) == 0) ||
     (*(byte *)(WPP_GLOBAL_Control + 0x29) < 4)) goto LAB_140005d95;
  if (param_9 == (wchar_t *)0x0) {
    wVar1 = L'\b';
LAB_140005cf7:
    pwVar5 = L"NULL";
  }
  else {
    wVar1 = *param_9;
    if (*param_9 == L'\0') goto LAB_140005cf7;
    pwVar5 = *(wchar_t **)(param_9 + 4);
  }
  pwVar2 = param_9;
  if (param_9 == (wchar_t *)0x0) {
    pwVar2 = L"\b";
  }
  (*pfnWppTraceMessage)
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
             &WPP_258dc4bb20423ae59ba1107eb987efad_Traceguids,param_4,
             "onecore\\base\\fs\\wci\\wcifs\\expansion.c",0x26,&param_7,4,&param_8,8,pwVar2,2,pwVar5
             ,wVar1,&param_10,4,0);
LAB_140005d95:
  if (pwVar3 == (wchar_t *)0x0) {
    wVar1 = L'\b';
  }
  else {
    wVar1 = *pwVar3;
    if (*pwVar3 != L'\0') {
      pwVar4 = *(wchar_t **)(pwVar3 + 4);
    }
  }
  if (pwVar3 == (wchar_t *)0x0) {
    pwVar3 = L"\b";
  }
  WppAutoLogTrace(param_1,4,10,&WPP_258dc4bb20423ae59ba1107eb987efad_Traceguids,param_4,
                  "onecore\\base\\fs\\wci\\wcifs\\expansion.c",0x26,&param_7,4,&param_8,8,pwVar3,2,
                  pwVar4,wVar1,&param_10,4,0);
  return;
}



===== WPP_RECORDER_SF_sDDd @ 140005e68 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDDd
               (undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
               undefined8 param_5,char *param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  uVar4 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar4 * 0x14) * 4) >> (param_3 - 1 & 0x1f)
       & 1) != 0) && (1 < *(byte *)(WPP_GLOBAL_Control + 0x29 + uVar4 * 0x50))) {
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
    pcVar1 = param_6;
    if (param_6 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18 + uVar4 * 0x50),0x2b,param_5,param_4,pcVar1
               ,lVar3,&param_7,4,&param_8,4,&param_9,4,0);
  }
  lVar3 = -1;
  if (param_6 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (param_6[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_6 == (char *)0x0) {
    param_6 = "NULL";
  }
  WppAutoLogTrace(param_1,2,param_3,param_5,param_4,param_6,lVar2,&param_7,4,&param_8,4,&param_9,4,0
                 );
  return;
}



===== WcPostRead @ 140006040 =====

undefined8 WcPostRead(longlong param_1,longlong param_2,undefined8 param_3)

{
  if ((((-1 < *(int *)(param_1 + 0x18)) && (*(longlong *)(param_1 + 0x20) != 0)) &&
      ((*(uint *)(*(longlong *)(param_2 + 0x20) + 0x50) & 2) != 0)) &&
     ((**(uint **)(param_1 + 0x10) & 2) == 0)) {
    *(longlong *)(*(longlong *)(param_2 + 0x20) + 0x68) =
         *(longlong *)(*(uint **)(param_1 + 0x10) + 10) + *(longlong *)(param_1 + 0x20);
  }
  FltReleaseContext(param_3);
  return 0;
}



===== WPP_RECORDER_SF_sDqLiLLZ @ 140006094 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDqLiLLZ(void)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  wchar_t *in_stack_00000068;
  undefined4 local_28 [4];
  
  pwVar4 = L"NULL";
  local_28[0] = 0x95;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) == 0) ||
     (*(byte *)(WPP_GLOBAL_Control + 0x29) < 5)) goto LAB_1400061f2;
  if (in_stack_00000068 == (wchar_t *)0x0) {
    wVar2 = L'\b';
LAB_14000611a:
    pwVar3 = L"NULL";
  }
  else {
    wVar2 = *in_stack_00000068;
    if (*in_stack_00000068 == L'\0') goto LAB_14000611a;
    pwVar3 = *(wchar_t **)(in_stack_00000068 + 4);
  }
  pwVar1 = in_stack_00000068;
  if (in_stack_00000068 == (wchar_t *)0x0) {
    pwVar1 = L"\b";
  }
  (*pfnWppTraceMessage)
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
             &WPP_fd6e5da2a1a53c4972de035ee243e502_Traceguids,0xb,
             "onecore\\base\\fs\\wci\\wcifs\\telemetry.c",0x26,local_28,4,&uStack0000000000000040,8,
             &uStack0000000000000048,4,&uStack0000000000000050,8,&uStack0000000000000058,4,
             &uStack0000000000000060,4,pwVar1,2,pwVar3,wVar2,0);
LAB_1400061f2:
  if (in_stack_00000068 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *in_stack_00000068;
    if (*in_stack_00000068 != L'\0') {
      pwVar4 = *(wchar_t **)(in_stack_00000068 + 4);
    }
  }
  if (in_stack_00000068 == (wchar_t *)0x0) {
    in_stack_00000068 = L"\b";
  }
  WppAutoLogTrace(0,5,10,&WPP_fd6e5da2a1a53c4972de035ee243e502_Traceguids,0xb,
                  "onecore\\base\\fs\\wci\\wcifs\\telemetry.c",0x26,local_28,4,
                  &uStack0000000000000040,8,&uStack0000000000000048,4,&uStack0000000000000050,8,
                  &uStack0000000000000058,4,&uStack0000000000000060,4,in_stack_00000068,2,pwVar4,
                  wVar2,0);
  return;
}



===== WPP_RECORDER_SF_sDqLiLZii @ 1400062f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDqLiLZii(void)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  wchar_t *in_stack_00000060;
  undefined1 uStack0000000000000068;
  undefined1 uStack0000000000000070;
  undefined4 local_28 [4];
  
  pwVar4 = L"NULL";
  local_28[0] = 0xf3;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) == 0) ||
     (*(byte *)(WPP_GLOBAL_Control + 0x29) < 5)) goto LAB_140006465;
  if (in_stack_00000060 == (wchar_t *)0x0) {
    wVar2 = L'\b';
LAB_140006373:
    pwVar3 = L"NULL";
  }
  else {
    wVar2 = *in_stack_00000060;
    if (*in_stack_00000060 == L'\0') goto LAB_140006373;
    pwVar3 = *(wchar_t **)(in_stack_00000060 + 4);
  }
  pwVar1 = in_stack_00000060;
  if (in_stack_00000060 == (wchar_t *)0x0) {
    pwVar1 = L"\b";
  }
  (*pfnWppTraceMessage)
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
             &WPP_fd6e5da2a1a53c4972de035ee243e502_Traceguids,0xd,
             "onecore\\base\\fs\\wci\\wcifs\\telemetry.c",0x26,local_28,4,&uStack0000000000000040,8,
             &uStack0000000000000048,4,&uStack0000000000000050,8,&uStack0000000000000058,4,pwVar1,2,
             pwVar3,wVar2,&uStack0000000000000068,8,&uStack0000000000000070,8,0);
LAB_140006465:
  if (in_stack_00000060 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *in_stack_00000060;
    if (*in_stack_00000060 != L'\0') {
      pwVar4 = *(wchar_t **)(in_stack_00000060 + 4);
    }
  }
  if (in_stack_00000060 == (wchar_t *)0x0) {
    in_stack_00000060 = L"\b";
  }
  WppAutoLogTrace(0,5,10,&WPP_fd6e5da2a1a53c4972de035ee243e502_Traceguids,0xd,
                  "onecore\\base\\fs\\wci\\wcifs\\telemetry.c",0x26,local_28,4,
                  &uStack0000000000000040,8,&uStack0000000000000048,4,&uStack0000000000000050,8,
                  &uStack0000000000000058,4,in_stack_00000060,2,pwVar4,wVar2,&uStack0000000000000068
                  ,8,&uStack0000000000000070,8,0);
  return;
}



===== WppClassicProviderCallback @ 140006580 =====

void WppClassicProviderCallback
               (undefined8 param_1,byte param_2,undefined8 *param_3,longlong param_4)

{
  undefined8 uVar1;
  
  if (param_2 < 2) {
    if (param_2 == 0) {
      *(undefined1 *)(param_4 + 0x29) = 0;
      *(undefined4 *)(param_4 + 0x2c) = 0;
      *(undefined8 *)(param_4 + 0x18) = 0;
    }
    else {
      *(undefined4 *)(param_4 + 0x2c) = *(undefined4 *)((longlong)param_3 + 4);
      *(undefined1 *)(param_4 + 0x29) = *(undefined1 *)((longlong)param_3 + 2);
      uVar1 = *param_3;
      *(undefined8 *)(param_4 + 0x18) = uVar1;
      imp_WppRecorderReplay
                (WPP_GLOBAL_Control,uVar1,*(undefined4 *)((longlong)param_3 + 4),
                 *(undefined1 *)((longlong)param_3 + 2));
    }
  }
  return;
}



===== _tlgDefineProvider_annotation__TlgTlgAggregateInternalProviderProv @ 1400065dc =====

void _tlgDefineProvider_annotation__TlgTlgAggregateInternalProviderProv(void)

{
  return;
}



===== WPP_RECORDER_SF_sD_guid_d @ 1400065e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sD_guid_d(undefined8 param_1)

{
  undefined4 local_10 [2];
  
  local_10[0] = 0x7c7;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) &&
     (1 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,0x5a,
               "onecore\\base\\fs\\wci\\wcifs\\utils.c",0x22,local_10,4);
  }
  WppAutoLogTrace(param_1,2,5,&WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,0x5a,
                  "onecore\\base\\fs\\wci\\wcifs\\utils.c",0x22,local_10,4);
  return;
}



===== WPP_RECORDER_SF_sDqqd @ 140006720 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDqqd(undefined8 param_1)

{
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined4 local_18 [4];
  
  local_18[0] = 0x11b6;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0) &&
     (1 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,0x81,
               "onecore\\base\\fs\\wci\\wcifs\\utils.c",0x22,local_18,4,&uStack0000000000000040,8,
               &uStack0000000000000048,8,&uStack0000000000000050,4,0);
  }
  WppAutoLogTrace(param_1,2,0xf,&WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,0x81,
                  "onecore\\base\\fs\\wci\\wcifs\\utils.c",0x22,local_18,4,&uStack0000000000000040,8
                  ,&uStack0000000000000048,8,&uStack0000000000000050,4,0);
  return;
}



===== WcClearSparseAttribute @ 140006874 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int WcClearSparseAttribute(longlong param_1,undefined8 param_2)

{
  int iVar1;
  bool bVar2;
  undefined1 auStackY_a8 [32];
  undefined1 local_58 [8];
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  ulonglong local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  iVar1 = FltQueryInformationFile(param_2,param_1,&local_50,0x28);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xf,0x80,
                          &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                          "onecore\\base\\fs\\wci\\wcifs\\utils.c",0x94,(char)iVar1);
    }
  }
  else if ((local_30 & 0x200) != 0) {
    local_58[0] = 0;
    bVar2 = *(char *)(param_1 + 0x4b) == '\0';
    if (bVar2) {
      *(undefined1 *)(param_1 + 0x4b) = 1;
    }
    iVar1 = FltFsControlFile(param_2,param_1,0x900c4,local_58);
    if ((iVar1 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_sDqqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    if (bVar2) {
      *(undefined1 *)(param_1 + 0x4b) = 0;
    }
  }
  return iVar1;
}



===== WcCloseHandleAsyncWorker @ 140006a00 =====

void WcCloseHandleAsyncWorker(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FltClose(param_3);
  FltFreeGenericWorkItem(param_1);
  return;
}



===== WcIsUnionValid @ 140006a34 =====

byte WcIsUnionValid(longlong param_1)

{
  if (*(int *)(param_1 + 0x1c) == 2) {
    return ~(byte)(*(uint *)(param_1 + 0x20) >> 5) & 1;
  }
  return 1;
}



===== WcShouldRedirectEaAndUsn @ 140006a50 =====

undefined8 WcShouldRedirectEaAndUsn(char param_1,longlong param_2,longlong param_3,longlong param_4)

{
  ulonglong in_RAX;
  undefined1 uVar1;
  
  uVar1 = 0;
  if (param_1 == '\0') {
    in_RAX = WcUsesSourceSectionObjectPointers(param_2,param_4);
    if ((char)in_RAX == '\0') {
      in_RAX = WcIsPlaceHolderStream(param_3,param_4);
      if ((((char)in_RAX == '\0') || (in_RAX = *(ulonglong *)(param_2 + 0x28), in_RAX == 0)) ||
         (*(longlong *)(in_RAX + 0x10) == 0)) goto LAB_140006a92;
    }
    uVar1 = 1;
  }
LAB_140006a92:
  return CONCAT71((int7)(in_RAX >> 8),uVar1);
}



===== WcValidateReparseInfo @ 140006aa8 =====

uint WcValidateReparseInfo(uint *param_1,ushort param_2)

{
  uint uVar1;
  ushort local_res8 [16];
  
  local_res8[0] = 0;
  if (((*param_1 < 2) && (((ushort)param_1[6] & 1) == 0)) &&
     (uVar1 = RtlUShortAdd(0x1a,(ushort)param_1[6],local_res8), -1 < (int)uVar1)) {
    return -(uint)(param_2 < local_res8[0]) & 0xc0000102;
  }
  return 0xc0000102;
}



===== WcValidateTagDataReparseInfo @ 140006afc =====

uint WcValidateTagDataReparseInfo(longlong param_1)

{
  uint uVar1;
  
  if (*(ushort *)(param_1 + 4) < 0x1a) {
    uVar1 = 0xc0000102;
  }
  else {
    uVar1 = WcValidateReparseInfo((uint *)(param_1 + 8),*(ushort *)(param_1 + 4));
  }
  return uVar1;
}



===== WcpCalculateUnionContextSize @ 140006b28 =====

void WcpCalculateUnionContextSize(longlong param_1,int *param_2,int *param_3)

{
  ushort *puVar1;
  undefined8 *puVar2;
  int iVar3;
  int iVar4;
  
  puVar2 = *(undefined8 **)(param_1 + 0xa8);
  iVar3 = *(ushort *)(param_1 + 8) + 0x10;
  iVar4 = 0x10;
  while( true ) {
    *param_3 = iVar4;
    *param_2 = iVar3;
    if (puVar2 == (undefined8 *)(param_1 + 0xa8)) break;
    puVar1 = (ushort *)(puVar2 + -3);
    puVar2 = (undefined8 *)*puVar2;
    iVar3 = iVar3 + 8 + (uint)*puVar1;
    iVar4 = iVar4 + 8;
  }
  return;
}



===== WcpFillGetUnionsResponseBuffer @ 140006b68 =====

void WcpFillGetUnionsResponseBuffer
               (longlong param_1,uint *param_2,uint *param_3,uint *param_4,longlong param_5)

{
  undefined8 *puVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  undefined8 local_res10;
  
  uVar2 = *(ushort *)(param_1 + 8);
  puVar1 = (undefined8 *)(param_1 + 0xa8);
  iVar8 = 0;
  for (puVar6 = (undefined8 *)*puVar1; puVar6 != puVar1; puVar6 = (undefined8 *)*puVar6) {
    iVar8 = iVar8 + 1;
  }
  uVar4 = *param_2;
  memmove((void *)(param_5 + (ulonglong)uVar4),*(void **)(param_1 + 0x10),(ulonglong)uVar2);
  uVar9 = uVar2 + uVar4;
  puVar6 = (undefined8 *)*puVar1;
  *param_2 = uVar9;
  uVar5 = *param_3;
  uVar10 = uVar5;
  while (puVar6 != puVar1) {
    uVar3 = *(ushort *)(puVar6 + -3);
    uVar7 = (ulonglong)uVar10;
    uVar10 = uVar10 + 8;
    *param_3 = uVar10;
    local_res10 = CONCAT44(uVar9,(uint)uVar3);
    *(undefined8 *)(uVar7 + param_5) = local_res10;
    memmove((void *)((ulonglong)uVar9 + param_5),(void *)puVar6[-2],(ulonglong)(uint)uVar3);
    puVar6 = (undefined8 *)*puVar6;
    uVar9 = uVar9 + uVar3;
    *param_2 = uVar9;
  }
  uVar9 = *param_4;
  puVar1 = (undefined8 *)(param_5 + 0xc + (ulonglong)uVar9 * 0x10);
  *puVar1 = CONCAT44(uVar4,(uint)uVar2);
  puVar1[1] = CONCAT44(uVar5,iVar8);
  *param_4 = uVar9 + 1;
  return;
}



===== McGenControlCallbackV2 @ 140006c80 =====

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



===== McGenEventUnregister_EtwUnregister @ 140006d90 =====

undefined8 McGenEventUnregister_EtwUnregister(void)

{
  undefined8 uVar1;
  
  if (PROV_WCIFS_Context == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    PROV_WCIFS_Context = 0;
  }
  return uVar1;
}



===== McTemplateK0d_EtwWriteTransfer @ 140006dc4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0d_EtwWriteTransfer
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
  McGenEventWrite_EtwWriteTransfer(param_1,&WcifsDriverEntryFailure,param_3,2,local_38);
  return;
}



===== McTemplateK0dhzr1_EtwWriteTransfer @ 140006e28 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0dhzr1_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               ushort param_5,undefined8 param_6)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined4 *local_48;
  undefined8 local_40;
  ushort *local_38;
  undefined8 local_30;
  undefined8 local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = local_res20;
  local_30 = 2;
  local_38 = &param_5;
  local_28 = param_6;
  local_20 = (uint)param_5 * 2;
  local_40 = 4;
  local_1c = 0;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(0,&WcifsInstanceAttachFailure,param_3,4,local_58);
  return;
}



===== WPP_RECORDER_SF_sDlLDd @ 140006eb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDlLDd
               (undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined8 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) &&
     (param_2 <= *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_27ac746799d63ca1d37704ce911b8053_Traceguids,param_4,
               "onecore\\base\\fs\\wci\\wcifs\\wcifs.c",0x22,&param_7,4,&param_8,4,&param_9,4,
               &param_10,4,&param_11,4,0);
  }
  WppAutoLogTrace(param_1,param_2,4,&WPP_27ac746799d63ca1d37704ce911b8053_Traceguids,param_4,
                  "onecore\\base\\fs\\wci\\wcifs\\wcifs.c",0x22,&param_7,4,&param_8,4,&param_9,4,
                  &param_10,4,&param_11,4,0);
  return;
}



===== WcSetupVsmbBootUnionContext @ 140007018 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong WcSetupVsmbBootUnionContext(longlong param_1,longlong *param_2)

{
  uint *puVar1;
  undefined8 uVar2;
  int iVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  longlong lVar7;
  ulonglong uVar8;
  int *piVar9;
  uint uVar10;
  undefined2 uVar11;
  uint uVar12;
  bool bVar13;
  undefined1 auStackY_e8 [32];
  undefined1 uVar14;
  undefined1 uVar15;
  char local_a8 [8];
  undefined8 *local_a0;
  longlong *local_98;
  int *local_90;
  longlong local_88;
  longlong local_80;
  ushort local_78 [12];
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_90 = (int *)0x0;
  local_78[0] = 0;
  local_78[1] = 0;
  local_78[2] = 0;
  local_78[3] = 0;
  local_78[4] = 0;
  local_78[5] = 0;
  local_78[6] = 0;
  local_78[7] = 0;
  local_60 = (undefined4)DAT_14000f690;
  uStack_5c = DAT_14000f690._4_4_;
  uStack_58 = (undefined4)DAT_14000f698;
  uStack_54 = DAT_14000f698._4_4_;
  local_a0 = (undefined8 *)0x0;
  local_a8[0] = '\0';
  local_88 = 0;
  local_98 = (longlong *)0x0;
  local_80 = 0;
  local_50 = 0x8264f677;
  uStack_4c = 0x4ca540b0;
  uStack_48 = 0x4a949abf;
  uStack_44 = 0x8780dac2;
  RtlInitUnicodeString(local_78,L"\\");
  *(undefined4 *)(param_1 + 0x124) = 0x50000;
  *(undefined4 *)(param_1 + 0x120) = 5;
  uVar5 = WcCreateUnionContext(local_78,1,DAT_14000f6ac,DAT_14000f6b0,&local_90);
  uVar8 = uVar5 & 0xffffffff;
  if ((int)uVar5 < 0) {
    uVar8 = 0xc000009a;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xb,10,
                         &WPP_27ac746799d63ca1d37704ce911b8053_Traceguids,
                         "onecore\\base\\fs\\wci\\wcifs\\wcifs.c",0x98);
    }
  }
  else {
    puVar1 = (uint *)(local_90 + 8);
    *puVar1 = *puVar1 | 4;
    local_90[7] = 1;
    if (DAT_14000f6a9 != '\0') {
      *puVar1 = *puVar1 | 0x10;
    }
    piVar9 = local_90;
    for (uVar12 = 0; uVar12 < 2; uVar12 = uVar12 + 1) {
      local_a0 = (undefined8 *)ExAllocatePool2(0x100,0x70,0x796c4357);
      if (local_a0 == (undefined8 *)0x0) {
        uVar8 = 0xc000009a;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar4 = 0xc000009a;
          uVar12 = 0xb;
          uVar14 = 0xa8;
LAB_1400075be:
          uVar10 = uVar12;
LAB_1400075c1:
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar10,(short)uVar12,
                              &WPP_27ac746799d63ca1d37704ce911b8053_Traceguids,
                              "onecore\\base\\fs\\wci\\wcifs\\wcifs.c",uVar14,(char)uVar4);
        }
        goto LAB_14000765a;
      }
      *(undefined4 *)(local_a0 + 2) = 0x10;
      if ((*puVar1 & 0x10) != 0) {
        *(uint *)(local_a0 + 2) = *(uint *)(local_a0 + 2) | 0x20;
      }
      RtlInitUnicodeString
                (local_a0 + 3,L"\\Device\\vmsmb\\VSMB-{dcc079ae-60ba-4d07-847c-3493609c0870}\\os\\")
      ;
      *(undefined1 *)((longlong)local_a0 + 0x14) = 0;
      puVar6 = local_a0 + 6;
      local_a0[7] = puVar6;
      *puVar6 = puVar6;
      local_a0[5] = 0;
      uVar2 = *(undefined8 *)(&uStack_58 + (ulonglong)uVar12 * 4);
      *local_a0 = *(undefined8 *)(local_78 + (ulonglong)uVar12 * 8 + 0xc);
      local_a0[1] = uVar2;
      uVar8 = WcInitializeDirectoryTable((longlong)local_a0,0x1000);
      uVar4 = (uint)uVar8;
      uVar8 = uVar8 & 0xffffffff;
      if ((int)uVar4 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar12 = 0xc;
          uVar14 = 0xbf;
          uVar10 = 0xb;
          goto LAB_1400075c1;
        }
        goto LAB_14000765a;
      }
      if (param_2 == (longlong *)0x0) {
        iVar3 = FltGetVolumeFromName(Globals,local_a0 + 3,&local_80);
        if (iVar3 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xb,0xd,
                                &WPP_27ac746799d63ca1d37704ce911b8053_Traceguids,
                                "onecore\\base\\fs\\wci\\wcifs\\wcifs.c",0xd0,(char)iVar3);
          }
          FltReferenceContext(param_1);
          uVar8 = 0;
          DAT_14000f730 = param_1;
          goto LAB_14000765a;
        }
        iVar3 = FltGetVolumeInstanceFromName(Globals,local_80,&DAT_14000f6b8,&local_88);
        if (-1 < iVar3) {
          uVar4 = FltGetInstanceContext(local_88,&local_98);
          uVar8 = (ulonglong)uVar4;
          if ((int)uVar4 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_14000765a;
            uVar12 = 0x10;
            uVar14 = 0xf3;
          }
          else {
            if (local_98[7] == 0) goto LAB_140007352;
            uVar8 = 0xc00000bb;
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_14000765a;
            uVar4 = 0xc00000bb;
            uVar12 = 0x11;
            uVar14 = 0xf9;
          }
LAB_1400072c6:
          uVar10 = 0xe;
          goto LAB_1400075c1;
        }
        uVar4 = FltAttachVolume(Globals,local_80,&DAT_14000f6b8,&local_88);
        uVar8 = (ulonglong)uVar4;
        if ((int)uVar4 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar12 = 0xe;
            uVar14 = 0xde;
            goto LAB_1400075be;
          }
          goto LAB_14000765a;
        }
        uVar4 = FltGetInstanceContext(local_88,&local_98);
        uVar8 = (ulonglong)uVar4;
        if ((int)uVar4 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar12 = 0xf;
            uVar14 = 0xe5;
            goto LAB_1400072c6;
          }
          goto LAB_14000765a;
        }
      }
      else {
        local_98 = param_2;
        FltReferenceContext(param_2);
        local_88 = *local_98;
        FltObjectReference();
      }
LAB_140007352:
      piVar9 = local_90;
      local_a0[5] = local_88;
      local_88 = 0;
      if (uVar12 == 0) {
        *(uint *)(local_a0 + 2) = *(uint *)(local_a0 + 2) | 2;
      }
      if (((int)local_98[1] == 0xd) || ((int)local_98[1] == 6)) {
        *(uint *)(local_a0 + 2) = *(uint *)(local_a0 + 2) | 1;
      }
      *(uint *)(local_a0 + 2) = *(uint *)(local_a0 + 2) | 8;
      LOCK();
      *(int *)((longlong)local_98 + 0x14) = *(int *)((longlong)local_98 + 0x14) + 1;
      UNLOCK();
      lVar7 = RtlInsertElementGenericTableAvl(local_90 + 0x10,&local_a0,8,local_a8);
      if (lVar7 == 0) {
        uVar8 = 0xc000009a;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar15 = 0x9a;
          uVar11 = 0x12;
          uVar14 = 0x2a;
LAB_14000751a:
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xe,uVar11,
                              &WPP_27ac746799d63ca1d37704ce911b8053_Traceguids,
                              "onecore\\base\\fs\\wci\\wcifs\\wcifs.c",uVar14,uVar15);
        }
LAB_14000754a:
        if ((*(uint *)(local_a0 + 2) & 8) == 0) goto LAB_14000765a;
        LOCK();
        *(int *)((longlong)local_98 + 0x14) = *(int *)((longlong)local_98 + 0x14) + -1;
        UNLOCK();
        goto LAB_14000712b;
      }
      if (local_a8[0] == '\0') {
        uVar8 = 0xc000000d;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar15 = 0xd;
          uVar11 = 0x13;
          uVar14 = 0x2f;
          goto LAB_14000751a;
        }
        goto LAB_14000754a;
      }
      local_a0 = (undefined8 *)0x0;
      FltReleaseContext(local_98);
      local_98 = (longlong *)0x0;
      if (local_80 != 0) {
        FltObjectDereference();
        local_80 = 0;
      }
    }
    LOCK();
    bVar13 = *(longlong *)(param_1 + 0x38) == 0;
    if (bVar13) {
      *(longlong *)(param_1 + 0x38) = (longlong)piVar9;
    }
    UNLOCK();
    if (bVar13) {
      piVar9 = (int *)0x0;
      goto LAB_14000765a;
    }
    uVar8 = 0xc00000bb;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xe,0x14,
                          &WPP_27ac746799d63ca1d37704ce911b8053_Traceguids,
                          "onecore\\base\\fs\\wci\\wcifs\\wcifs.c",0x54,0xbb);
    }
  }
LAB_14000712b:
  piVar9 = local_90;
LAB_14000765a:
  if (piVar9 != (int *)0x0) {
    WcReleaseUnionContext(piVar9);
  }
  if (local_98 != (longlong *)0x0) {
    FltReleaseContext();
  }
  if (local_80 != 0) {
    FltObjectDereference();
  }
  if (local_88 != 0) {
    FltObjectDereference();
  }
  if (local_a0 != (undefined8 *)0x0) {
    WcCleanupLayer((longlong)local_a0);
  }
  return uVar8;
}



===== wil_details_RecordCachedUsage @ 1400076e4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_RecordCachedUsage(undefined4 param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  longlong lVar6;
  bool bVar7;
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
    bVar7 = uVar2 == uVar4;
    if (bVar7) {
      *param_2 = uVar2 & 0xffc0401e;
    }
    else {
      uVar2 = uVar4;
    }
    UNLOCK();
  } while (!bVar7);
  uVar3 = uVar2 >> 1 & 0xf;
  uVar4 = 0;
  if (uVar3 != 0) {
    uVar4 = param_2[1];
    do {
      LOCK();
      uVar1 = param_2[1];
      bVar7 = uVar4 == uVar1;
      if (bVar7) {
        param_2[1] = uVar4 | uVar3;
      }
      else {
        uVar4 = uVar1;
      }
      UNLOCK();
    } while (!bVar7);
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
  lVar6 = (longlong)puVar5 - (longlong)&local_48 >> 3;
  if (0 < lVar6) {
    RtlRecordFeatureUsage(&local_48,lVar6);
  }
  return;
}



===== wil_details_RecordFeatureUsageReporting @ 140007840 =====

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



===== AggregateField @ 1400078c4 =====

longlong AggregateField(longlong *param_1,longlong param_2,int param_3)

{
  longlong lVar1;
  longlong in_RAX;
  longlong lVar2;
  bool bVar3;
  
  if (param_3 == 0x71) {
    LOCK();
    *param_1 = *param_1 + param_2;
    UNLOCK();
  }
  else if ((param_3 == 0x72) || (param_3 == 0x73)) {
    do {
      lVar2 = *param_1;
      if (param_3 == 0x72) {
        if (lVar2 <= param_2) {
          return lVar2;
        }
      }
      else if (param_2 <= lVar2) {
        return lVar2;
      }
      LOCK();
      lVar1 = *param_1;
      bVar3 = lVar2 == lVar1;
      if (bVar3) {
        *param_1 = param_2;
      }
      else {
        lVar2 = lVar1;
      }
      UNLOCK();
    } while (!bVar3);
    return lVar2;
  }
  return in_RAX;
}



===== CBufferGetNextOffset @ 140007904 =====

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



===== CreateNewEventEntry @ 140007938 =====

undefined8
CreateNewEventEntry(char param_1,undefined8 *param_2,undefined8 param_3,longlong param_4,
                   byte param_5,undefined4 param_6,undefined8 *param_7)

{
  size_t _Size;
  undefined8 *puVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined8 *puVar6;
  void *pvVar7;
  uint uVar8;
  longlong lVar9;
  ulonglong uVar10;
  uint *puVar11;
  byte bVar12;
  void *local_38;
  size_t local_30;
  
  uVar10 = 0;
  lVar5 = 0;
  bVar12 = 0;
  *param_7 = 0;
  puVar11 = (uint *)(param_4 + 8);
  lVar9 = 0;
  do {
    uVar8 = *puVar11;
    puVar11 = puVar11 + 4;
    if (1 < bVar12) {
      lVar5 = (ulonglong)uVar8 + lVar5;
    }
    lVar3 = (ulonglong)uVar8 + lVar9;
    if (1 < bVar12) {
      lVar3 = lVar9;
    }
    bVar12 = bVar12 + 1;
    lVar9 = lVar3;
  } while (bVar12 < 0xb);
  if ((ulonglong)(lVar3 + lVar5) < 0x10000) {
    _Size = lVar5 + 0xde;
    if ((_Size != 0) &&
       (local_38 = (void *)ExAllocatePoolWithTag
                                     ((-(uint)(param_1 != '\0') & 0xfffffe01) + 0x200,_Size,
                                      0x47417254), local_38 != (void *)0x0)) {
      memset(local_38,0,_Size);
      local_30 = _Size;
      lVar5 = CBufferGetNextOffset((longlong *)&local_38,0xb0);
      if (param_5 != 0xfffffffe) {
        do {
          if ((byte)uVar10 < 2) {
            puVar6 = (undefined8 *)(param_4 + uVar10 * 0x10);
            uVar4 = puVar6[1];
            puVar1 = (undefined8 *)(lVar5 + uVar10 * 0x10);
            *puVar1 = *puVar6;
            puVar1[1] = uVar4;
          }
          else {
            uVar8 = *(uint *)(param_4 + 8 + uVar10 * 0x10);
            pvVar7 = (void *)CBufferGetNextOffset((longlong *)&local_38,(ulonglong)uVar8);
            memmove(pvVar7,*(void **)(param_4 + uVar10 * 0x10),(ulonglong)uVar8);
            *(void **)(lVar5 + uVar10 * 0x10) = pvVar7;
            *(undefined4 *)(lVar5 + 0xc + uVar10 * 0x10) =
                 *(undefined4 *)(param_4 + 0xc + uVar10 * 0x10);
            *(undefined4 *)(lVar5 + 8 + uVar10 * 0x10) =
                 *(undefined4 *)(param_4 + 8 + uVar10 * 0x10);
          }
          bVar12 = (byte)uVar10 + 1;
          uVar10 = (ulonglong)bVar12;
        } while ((uint)bVar12 < param_5 + 2);
      }
      lVar9 = 0x2e;
      puVar6 = (undefined8 *)CBufferGetNextOffset((longlong *)&local_38,0x2e);
      puVar6[2] = lVar5;
      uVar4 = *param_2;
      uVar2 = param_2[1];
      *(byte *)((longlong)puVar6 + 0x2d) = param_5;
      bVar12 = param_5 + 2;
      *(undefined1 *)((longlong)puVar6 + 0x2c) = 0xb;
      *(undefined4 *)(puVar6 + 5) = param_6;
      *puVar6 = uVar4;
      puVar6[1] = uVar2;
      if (bVar12 < 0xb) {
        lVar5 = (lVar9 + -0x36) - param_4;
        uVar10 = (ulonglong)(byte)(0xb - bVar12);
        puVar11 = (uint *)((ulonglong)bVar12 * 0x10 + 8 + param_4);
        do {
          uVar8 = *puVar11;
          pvVar7 = (void *)CBufferGetNextOffset((longlong *)&local_38,(ulonglong)uVar8);
          memmove(pvVar7,*(void **)(puVar11 + -2),(ulonglong)uVar8);
          *(void **)((longlong)puVar11 + puVar6[2] + lVar5) = pvVar7;
          *(uint *)((longlong)puVar11 + puVar6[2] + lVar5 + 0xc) = puVar11[1];
          *(uint *)((longlong)puVar11 + puVar6[2] + lVar5 + 8) = *puVar11;
          uVar10 = uVar10 - 1;
          puVar11 = puVar11 + 4;
        } while (uVar10 != 0);
      }
      *param_7 = puVar6;
      return 0;
    }
    uVar4 = 0xc0000017;
  }
  else {
    uVar4 = 0xc0000095;
  }
  return uVar4;
}



===== DestroyEventEntry @ 140007b6c =====

void DestroyEventEntry(longlong param_1)

{
  if (param_1 != 0) {
    ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x10),0);
  }
  return;
}



===== EnableFlushTimer @ 140007b94 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void EnableFlushTimer(longlong param_1,ulonglong param_2)

{
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  if (param_1 != 0) {
    local_18 = __security_cookie ^ (ulonglong)auStack_48;
    local_28 = 0;
    local_20 = 0xffffffffffffffff;
    ExSetTimer(param_1,(param_2 & 0xffffffff) * -10000,0,&local_28);
  }
  return;
}



===== ExtractAggregateFieldTypes @ 140007bf0 =====

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
      if (bVar2 != 0x80) goto LAB_140007c6a;
    }
    if (((bVar1 & 0x7f) != 9) ||
       (uVar5 = (int)CONCAT71((int7)((ulonglong)param_2 >> 8),bVar2) - 0x71,
       in_RAX = (ulonglong)uVar5, 2 < (byte)uVar5)) break;
    uVar6 = (ulonglong)bVar10;
    in_RAX = uVar6 * 2;
    bVar10 = bVar10 + 1;
    *(byte *)(param_2 + 0x2d + uVar6 * 0x10) = bVar2;
  }
LAB_140007c6a:
  return CONCAT71((int7)(in_RAX >> 8),bVar10);
}



===== FinishHash @ 140007c78 =====

void FinishHash(int *param_1)

{
  *param_1 = ((uint)(*param_1 * 9) >> 0xb ^ *param_1 * 9) * 0x8001;
  return;
}



===== FlushLookUpTableBucket @ 140007c94 =====

int FlushLookUpTableBucket(longlong param_1,uint param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 uVar3;
  longlong *plVar4;
  longlong *plVar5;
  longlong lVar6;
  int iVar7;
  ulonglong uVar8;
  longlong local_res8;
  
  uVar8 = (ulonglong)param_2;
  if (*(longlong *)(param_1 + uVar8 * 8) == 0) {
    iVar7 = 0;
  }
  else {
    uVar3 = 0;
    ExAcquirePushLockExclusiveEx(param_1 + 0x110,0);
    if (*(char *)(param_1 + 0x175) == '\0') {
      uVar3 = ExAcquireSpinLockExclusive(param_1 + 0x118);
    }
    lVar1 = *(longlong *)(param_1 + uVar8 * 8);
    plVar5 = &local_res8;
    *(undefined8 *)(param_1 + uVar8 * 8) = 0;
    iVar7 = 0;
    local_res8 = lVar1;
    if (lVar1 != 0) {
      lVar6 = lVar1;
      do {
        lVar2 = *(longlong *)(lVar6 + 0x20);
        *(undefined8 *)(lVar6 + 0x20) = 0;
        plVar5 = (longlong *)(*plVar5 + 0x18);
        lVar6 = *plVar5;
        plVar4 = plVar5;
        while (lVar6 != 0) {
          plVar4 = (longlong *)(lVar6 + 0x20);
          lVar6 = *plVar4;
        }
        *plVar4 = lVar2;
        iVar7 = iVar7 + 1;
        lVar6 = *plVar5;
      } while (lVar6 != 0);
    }
    *(int *)(param_1 + 0x100) = *(int *)(param_1 + 0x100) - iVar7;
    if (*(char *)(param_1 + 0x175) == '\0') {
      ExReleaseSpinLockExclusive(param_1 + 0x118,uVar3);
    }
    ExReleasePushLockExclusiveEx(param_1 + 0x110,0);
    FlushEventEntryList(*(undefined8 *)(*(longlong *)(param_1 + 0x158) + 0x20),lVar1);
  }
  return iVar7;
}



===== InsertEventEntryInLookUpTable @ 140007da8 =====

ulonglong InsertEventEntryInLookUpTable
                    (ulonglong param_1,undefined8 *param_2,undefined1 param_3,longlong param_4,
                    byte param_5)

{
  int *piVar1;
  uint uVar2;
  longlong lVar3;
  bool bVar4;
  longlong lVar5;
  undefined1 uVar6;
  int iVar7;
  byte bVar8;
  longlong lVar9;
  uint uVar10;
  longlong lVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  char cVar14;
  longlong *plVar15;
  uint uVar16;
  ulonglong uVar17;
  ulonglong local_res8;
  undefined8 *local_res10;
  byte local_res18;
  longlong local_res20;
  longlong local_58;
  void *local_50;
  
  lVar5 = DAT_14000f090;
  local_50 = (void *)(param_4 + 0x10);
  bVar4 = false;
  local_58 = 0;
  local_res8 = param_1 & 0xffffffff00000000;
  lVar11 = 0;
  uVar13 = 8;
  uVar17 = 0;
  local_res10 = param_2;
  local_res18 = param_3;
  local_res20 = param_4;
  RunningHash((uint *)&local_res8,(longlong)local_50,8);
  bVar8 = param_5 + 2;
  if (bVar8 < 0xb) {
    plVar15 = (longlong *)((ulonglong)bVar8 * 0x10 + param_4);
    uVar12 = (ulonglong)(byte)(0xb - bVar8);
    do {
      uVar13 = (ulonglong)*(uint *)(plVar15 + 1);
      RunningHash((uint *)&local_res8,*plVar15,uVar13);
      plVar15 = plVar15 + 2;
      uVar12 = uVar12 - 1;
    } while (uVar12 != 0);
  }
  uVar16 = ((uint)((int)local_res8 * 9) >> 0xb ^ (int)local_res8 * 9) * 0x8001;
  local_res18 = KeGetCurrentIrql();
  if (local_res18 < 2) {
    iVar7 = KeIsExecutingDpc();
    if (iVar7 == 0) {
      ExAcquirePushLockSharedEx(lVar5 + 0x110,0);
      goto LAB_140007f3f;
    }
    if (*(char *)(lVar5 + 0x175) != '\0') {
      uVar6 = KeGetCurrentIrql();
                    /* WARNING: Subroutine does not return */
      KeBugCheckEx(0xd1,lVar5 + 0x118,uVar6,1,0);
    }
    ExAcquireSpinLockShared(lVar5 + 0x118);
  }
  else {
    if (*(char *)(lVar5 + 0x175) != '\0') {
      uVar6 = KeGetCurrentIrql();
                    /* WARNING: Subroutine does not return */
      KeBugCheckEx(0xd1,lVar5 + 0x118,uVar6,1,0);
    }
    ExAcquireSpinLockSharedAtDpcLevel(lVar5 + 0x118);
  }
  bVar4 = true;
LAB_140007f3f:
  plVar15 = (longlong *)(lVar5 + (ulonglong)(uVar16 & 0x1f) * 8);
  do {
    if (*plVar15 == 0) {
      if (0x3ff < *(uint *)(lVar5 + 0x100)) {
        *(int *)(lVar5 + 0x13c) = *(int *)(lVar5 + 0x13c) + 1;
        uVar17 = 0xc0000023;
        goto LAB_140008113;
      }
      if (lVar11 == 0) {
        uVar12 = CreateNewEventEntry(*(char *)(lVar5 + 0x175),local_res10,uVar13,param_4,param_5,
                                     uVar16,&local_58);
        uVar17 = uVar12 & 0xffffffff;
        lVar11 = local_58;
        if (local_58 == 0) {
          if ((int)uVar12 == -0x3fffffe9) {
            *(int *)(lVar5 + 0x140) = *(int *)(lVar5 + 0x140) + 1;
          }
          else {
            *(int *)(lVar5 + 0x144) = *(int *)(lVar5 + 0x144) + 1;
          }
          goto LAB_140008113;
        }
      }
      LOCK();
      lVar9 = *plVar15;
      if (lVar9 == 0) {
        *plVar15 = lVar11;
      }
      UNLOCK();
      if (lVar9 == 0) {
        local_58 = 0;
        LOCK();
        piVar1 = (int *)(lVar5 + 0x100);
        iVar7 = *piVar1;
        *piVar1 = *piVar1 + 1;
        UNLOCK();
        if (iVar7 == 0) {
          EnableFlushTimer(*(longlong *)(lVar5 + 0x168),(ulonglong)*(uint *)(lVar5 + 0x170));
        }
        lVar11 = local_58;
        if (*(uint *)(lVar5 + 0x130) < *(uint *)(lVar5 + 0x100)) {
          *(uint *)(lVar5 + 0x130) = *(uint *)(lVar5 + 0x100);
        }
        goto LAB_140008113;
      }
      lVar11 = local_58;
    }
    lVar9 = *plVar15;
    if (uVar16 == *(uint *)(lVar9 + 0x28)) {
      lVar3 = *(longlong *)(lVar9 + 0x10);
      uVar13 = 8;
      iVar7 = memcmp(local_50,(void *)(lVar3 + 0x10),8);
      if (iVar7 == 0) {
        uVar10 = *(byte *)(lVar9 + 0x2d) + 2;
        while( true ) {
          if (10 < uVar10) {
            lVar9 = *plVar15;
            param_4 = local_res20;
            goto LAB_1400080cf;
          }
          lVar9 = (ulonglong)uVar10 * 0x10;
          uVar2 = *(uint *)(lVar9 + 8 + local_res20);
          iVar7 = uVar2 - *(int *)(lVar9 + 8 + lVar3);
          if (iVar7 != 0) break;
          uVar13 = (ulonglong)uVar2;
          iVar7 = memcmp(*(void **)(lVar9 + local_res20),*(void **)(lVar9 + lVar3),uVar13);
          if (iVar7 != 0) break;
          uVar10 = uVar10 + 1;
        }
        lVar9 = *plVar15;
      }
      param_4 = local_res20;
    }
    else {
      iVar7 = uVar16 - *(uint *)(lVar9 + 0x28);
      if (iVar7 == 0) {
LAB_1400080cf:
        if (lVar9 != 0) {
          uVar13 = 2;
          if (2 < param_5 + 2) {
            do {
              cVar14 = (char)uVar13;
              AggregateField(*(longlong **)(*(longlong *)(lVar9 + 0x10) + uVar13 * 0x10),
                             **(longlong **)(param_4 + uVar13 * 0x10),
                             (uint)*(byte *)(*(longlong *)(lVar9 + 0x10) + 0xd + uVar13 * 0x10));
              uVar13 = (ulonglong)(byte)(cVar14 + 1U);
            } while ((uint)(byte)(cVar14 + 1U) < param_5 + 2);
          }
        }
LAB_140008113:
        if (bVar4) {
          if (local_res18 < 2) {
            ExReleaseSpinLockShared();
          }
          else {
            ExReleaseSpinLockSharedFromDpcLevel(lVar5 + 0x118);
          }
        }
        else {
          ExReleasePushLockSharedEx(lVar5 + 0x110,0);
        }
        if (lVar11 != 0) {
          DestroyEventEntry(lVar11);
        }
        return uVar17;
      }
    }
    plVar15 = (longlong *)(lVar9 + 0x20 + ((longlong)iVar7 >> 0x3f & 0xfffffffffffffff8U));
  } while( true );
}



===== RunningHash @ 140008184 =====

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



===== TlgAggregateInternalFlushTimerCallbackKernelMode @ 1400081c0 =====

/* void __cdecl TlgAggregateInternalFlushTimerCallbackKernelMode(struct _EX_TIMER * __ptr64,void *
   __ptr64) */

void __cdecl TlgAggregateInternalFlushTimerCallbackKernelMode(_EX_TIMER *param_1,void *param_2)

{
  short sVar1;
  short sVar2;
  
  sVar2 = 0;
  LOCK();
  sVar1 = *(short *)((longlong)param_2 + 0x38);
  if (sVar1 == 0) {
    *(short *)((longlong)param_2 + 0x38) = 1;
  }
  else {
    sVar2 = sVar1;
  }
  UNLOCK();
  if (sVar2 == 0) {
    ExQueueWorkItem(param_2);
  }
  else if (sVar2 == 1) {
    EnableFlushTimer((longlong)param_1,15000);
  }
  return;
}



===== _tlgWriteAgg @ 140008204 =====

ulonglong _tlgWriteAgg(undefined8 param_1,byte *param_2,undefined1 param_3,undefined8 param_4,
                      undefined8 *param_5)

{
  ulonglong uVar1;
  undefined8 uVar2;
  code *pcVar3;
  int local_18;
  uint local_14;
  undefined8 local_10;
  
  local_18 = (uint)*param_2 << 0x18;
  local_14 = (uint)*(ushort *)(param_2 + 1);
  local_10 = *(undefined8 *)(param_2 + 3);
  *param_5 = PTR_DAT_14000f068;
  *(uint *)(param_5 + 1) = (uint)*(ushort *)PTR_DAT_14000f068;
  *(undefined4 *)((longlong)param_5 + 0xc) = 2;
  param_5[2] = param_2 + 0xb;
  *(uint *)(param_5 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)param_5 + 0x1c) = 1;
  pcVar3 = TlgAggregateInternalRegisteredProviderEtwCallback;
  uVar1 = 0xc000000d;
  if (DAT_14000f088 == TlgAggregateInternalRegisteredProviderEtwCallback) {
    uVar2 = ExtractAggregateFieldTypes
                      (TlgAggregateInternalRegisteredProviderEtwCallback,(longlong)param_5);
    if ((byte)uVar2 == 0) {
      uVar1 = EtwWriteTransfer(DAT_14000f080,&local_18,0,0,0xb,param_5);
    }
    else {
      uVar1 = InsertEventEntryInLookUpTable
                        ((ulonglong)pcVar3,(undefined8 *)&local_18,param_3,(longlong)param_5,
                         (byte)uVar2);
    }
  }
  return uVar1;
}



===== _guard_check_icall @ 1400082f0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140008308 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000832c =====

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



===== __cpu_features_init @ 1400083a0 =====

/* WARNING: Removing unreachable block (ram,0x00014000840a) */
/* WARNING: Removing unreachable block (ram,0x0001400083b9) */
/* WARNING: Removing unreachable block (ram,0x0001400083aa) */

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



===== __security_check_cookie @ 140008470 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1400084b0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1400084e0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001400084e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140008510 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcmp @ 140008560 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_1400085a3;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_140008614;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_140008610:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140008614;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_14000860c:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140008610;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14000860c;
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
LAB_140008614:
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
LAB_1400085a3:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== memmove @ 140008680 =====

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



===== memset @ 140008980 =====

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



===== __memset_repmovs @ 140008ac0 =====

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



===== __memset_query @ 140008b40 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140008bc0 =====

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



===== __memset_spec_ermsb_repmovsb @ 140008d00 =====

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



===== __memset_spec_plain @ 140008d80 =====

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



===== WcExpandAndWait @ 140015008 =====

int WcExpandAndWait(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4,
                   int param_5,int param_6)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  bVar1 = WcIsExpanded(param_4);
  if (bVar1 == 0) {
    iVar3 = WcLaunchExpansion(param_2,param_3,param_4,0,param_5,param_6);
    if (((-1 < iVar3) &&
        (iVar3 = FltCancellableWaitForSingleObject(*(longlong *)(param_4 + 0x50) + 8,0,param_1),
        iVar3 < 0)) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_sDqd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,10,0x16,
                 &WPP_258dc4bb20423ae59ba1107eb987efad_Traceguids,
                 "onecore\\base\\fs\\wci\\wcifs\\expansion.c",0x35,(char)param_3,(char)iVar3);
    }
    bVar1 = WcIsExpanded(param_4);
    iVar2 = 0;
    if (bVar1 == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDqd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0x17,
                   &WPP_258dc4bb20423ae59ba1107eb987efad_Traceguids,
                   "onecore\\base\\fs\\wci\\wcifs\\expansion.c",0x42,(char)param_3,(char)iVar3);
      }
      if (-1 < iVar3) {
        iVar3 = -0x3fffffff;
      }
      iVar2 = iVar3;
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}



===== WcMungeNamesEnumerate @ 140015170 =====

undefined4
WcMungeNamesEnumerate
          (int param_1,char param_2,void *param_3,undefined4 *param_4,uint param_5,
          undefined8 *param_6,uint *param_7)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  uVar2 = 0;
  if (param_1 == 0xc) {
    uVar1 = *(uint *)((longlong)param_3 + 8);
    if ((uVar1 + 0xc <= param_5) || ((0xb < param_5 && (param_2 != '\0')))) {
      uVar2 = uVar1;
      if (param_5 - 0xc <= uVar1) {
        uVar2 = param_5 - 0xc;
      }
      uVar2 = uVar2 + 0xc;
      memmove(param_4,param_3,(ulonglong)uVar2);
      *param_4 = 0;
      *param_6 = param_4;
      uVar3 = 0;
      if (uVar2 < uVar1 + 0xc) {
        uVar3 = 0x80000005;
      }
    }
    *param_7 = uVar2;
  }
  else {
    uVar3 = 0xc00000bb;
  }
  return uVar3;
}



===== WcShouldSkipReparsePointInDirectoryEntry @ 140015228 =====

bool WcShouldSkipReparsePointInDirectoryEntry
               (int param_1,int param_2,undefined8 param_3,longlong param_4)

{
  bool bVar1;
  
  if (param_1 == 0x21) {
    bVar1 = false;
    if (*(int *)(param_4 + 8) == param_2) {
      bVar1 = true;
    }
  }
  else if ((((param_1 == 0x3c) || (param_1 == 0x3f)) || (param_1 == 0x4e)) ||
          (((param_1 == 0x4f || (param_1 == 0x50)) || (bVar1 = false, param_1 == 0x51)))) {
    bVar1 = *(int *)(param_4 + 0x44) == param_2;
  }
  return bVar1;
}



===== WcValidateContainerRootId @ 140015274 =====

undefined8 WcValidateContainerRootId(ushort *param_1,uint param_2)

{
  undefined2 uVar1;
  undefined1 uVar2;
  
  if (*param_1 == param_2) {
    if ((uint)*param_1 == param_1[2] + 6) {
      if (param_1[1] <= param_1[2]) {
        return 0;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0xc000000d;
      }
      uVar1 = 0xd;
      uVar2 = 0xb;
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0xc000000d;
      }
      uVar1 = 0xc;
      uVar2 = 6;
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000000d;
    }
    uVar1 = 0xb;
    uVar2 = 1;
  }
  WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xb,uVar1,
                     &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                     "onecore\\base\\fs\\wci\\wcifs\\utils.c",uVar2);
  return 0xc000000d;
}



===== WcGetEnumEntry @ 140015340 =====

undefined4 *
WcGetEnumEntry(longlong param_1,uint param_2,undefined4 *param_3,undefined4 *param_4,
              undefined4 *param_5)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  uVar1 = *(uint *)(param_1 + 0x3c);
  puVar4 = (undefined4 *)0x0;
  if (uVar1 <= param_2) {
    return (undefined4 *)0x0;
  }
  iVar2 = *(int *)(param_1 + 0x34);
  if (iVar2 == 0xc) {
    if (param_2 + 0xc < uVar1) {
      puVar4 = (undefined4 *)((ulonglong)param_2 + *(longlong *)(param_1 + 0x48));
      *param_3 = 0xc;
      uVar3 = *puVar4;
      *param_4 = puVar4[2];
      *param_5 = uVar3;
    }
  }
  else {
    if (iVar2 == 0x21) {
      if (uVar1 < param_2 + 0x10) {
        return (undefined4 *)0x0;
      }
      uVar3 = 0x10;
      puVar4 = (undefined4 *)((ulonglong)param_2 + *(longlong *)(param_1 + 0x48));
      *param_4 = 0;
      *param_3 = 0x10;
    }
    else {
      if (iVar2 == 0x3c) {
        if (uVar1 <= param_2 + 0x58) {
          return (undefined4 *)0x0;
        }
        *param_3 = 0x58;
      }
      else if (iVar2 == 0x3f) {
        if (uVar1 <= param_2 + 0x72) {
          return (undefined4 *)0x0;
        }
        *param_3 = 0x72;
      }
      else if (iVar2 == 0x4e) {
        if (uVar1 <= param_2 + 0x50) {
          return (undefined4 *)0x0;
        }
        *param_3 = 0x50;
      }
      else if (iVar2 == 0x4f) {
        if (uVar1 <= param_2 + 0x6a) {
          return (undefined4 *)0x0;
        }
        *param_3 = 0x6a;
      }
      else if (iVar2 == 0x50) {
        if (uVar1 <= param_2 + 0x60) {
          return (undefined4 *)0x0;
        }
        *param_3 = 0x60;
      }
      else {
        if (iVar2 != 0x51) {
          return (undefined4 *)0x0;
        }
        if (uVar1 <= param_2 + 0x7a) {
          return (undefined4 *)0x0;
        }
        *param_3 = 0x7a;
      }
      puVar4 = (undefined4 *)((ulonglong)param_2 + *(longlong *)(param_1 + 0x48));
      uVar3 = *puVar4;
      *param_4 = puVar4[0xf];
    }
    *param_5 = uVar3;
  }
  return puVar4;
}



===== WcGetSetSiloContext @ 140015478 =====

int WcGetSetSiloContext(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
                       undefined8 *param_5)

{
  undefined8 *puVar1;
  char cVar2;
  undefined2 uVar3;
  undefined1 uVar4;
  int iVar5;
  undefined8 *local_28;
  longlong local_20;
  
  local_28 = (undefined8 *)0x0;
  local_20 = 0;
  cVar2 = PsIsHostSilo();
  if (cVar2 == '\0') {
    FltGetInstanceContext(param_2,&local_20);
    if (*(int *)(local_20 + 0x10) == -1) {
      iVar5 = -0x3ffffff3;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001572d;
      iVar5 = -0x3ffffff3;
      uVar3 = 0x11;
      uVar4 = 0xbc;
    }
    else {
      iVar5 = PsGetSiloContext(param_1,*(int *)(local_20 + 0x10),&local_28);
      if (iVar5 == -0x3ffffddb) {
        iVar5 = PsCreateSiloContext(param_1,0xe0,0x200,WcCleanupSiloContext,&local_28);
        if (iVar5 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_14001572d;
          uVar3 = 0x12;
          uVar4 = 0xd0;
        }
        else {
          WcInitializeSiloContext(param_1,param_3,param_4,local_28);
          iVar5 = PsInsertSiloContext(param_1,*(undefined4 *)(local_20 + 0x10),local_28);
          if (iVar5 == -0x3fffff45) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,9,0x13,
                                 &WPP_2b73349c3ae735a72745210a57314671_Traceguids,
                                 "onecore\\base\\fs\\wci\\wcifs\\context.c",0xe3);
            }
            PsDereferenceSiloContext(local_28);
            local_28 = (undefined8 *)0x0;
            iVar5 = PsGetSiloContext(param_1,*(undefined4 *)(local_20 + 0x10),&local_28);
            if (-1 < iVar5) goto LAB_14001572b;
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_14001572d;
            uVar3 = 0x14;
            uVar4 = 0xec;
          }
          else {
            if (-1 < iVar5) goto LAB_14001571b;
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_14001572d;
            uVar3 = 0x15;
            uVar4 = 0xf6;
          }
        }
      }
      else {
        if (-1 < iVar5) {
LAB_14001571b:
          puVar1 = local_28;
          local_28 = (undefined8 *)0x0;
          *param_5 = puVar1;
LAB_14001572b:
          iVar5 = 0;
          goto LAB_14001572d;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001572d;
        uVar3 = 0x16;
        uVar4 = 0xfc;
      }
    }
  }
  else {
    iVar5 = -0x3ffffff3;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001572d;
    iVar5 = -0x3ffffff3;
    uVar3 = 0x10;
    uVar4 = 0xb0;
  }
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,uVar3,
                      &WPP_2b73349c3ae735a72745210a57314671_Traceguids,
                      "onecore\\base\\fs\\wci\\wcifs\\context.c",uVar4,(char)iVar5);
LAB_14001572d:
  if (local_20 != 0) {
    FltReleaseContext();
  }
  if (local_28 != (undefined8 *)0x0) {
    PsDereferenceSiloContext();
  }
  return iVar5;
}



===== WcCopySectionObjectPointers @ 14001577c =====

int WcCopySectionObjectPointers(undefined8 param_1,longlong param_2)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  longlong local_res18 [2];
  
  local_res18[0] = 0;
  iVar2 = FltGetStreamContext(param_1,param_2,local_res18);
  if (-1 < iVar2) {
    lVar4 = local_res18[0];
    lVar3 = WcGetSource(local_res18[0]);
    lVar3 = *(longlong *)(lVar3 + 0x10);
    WcGetSource(lVar4);
    *(undefined8 *)(param_2 + 0x28) = *(undefined8 *)(lVar3 + 0x28);
    LOCK();
    piVar1 = (int *)(**(longlong **)(lVar4 + 0x20) + 0x18);
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    if (DAT_14000f680 != '\0') {
      LOCK();
      piVar1 = (int *)(*(longlong *)(**(longlong **)(local_res18[0] + 0x20) + 0x20) + 4);
      *piVar1 = *piVar1 + 1;
      UNLOCK();
    }
    iVar2 = IoSetShadowFileInformation(param_2);
    if ((iVar2 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,10,
                         &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                         "onecore\\base\\fs\\wci\\wcifs\\create.c",0x7a);
    }
  }
  if (local_res18[0] != 0) {
    FltReleaseContext();
  }
  return iVar2;
}



===== WcPostQueryOpen @ 140015880 =====

undefined8 WcPostQueryOpen(longlong param_1,longlong param_2)

{
  longlong lVar1;
  bool bVar2;
  uint uVar3;
  undefined8 uVar4;
  int local_res8 [2];
  
  local_res8[0] = 0;
  if (-1 < *(int *)(param_1 + 0x18)) {
    if (*(int *)(*(longlong *)(param_1 + 0x10) + 0x30) == 0x47) {
      WcHandleQueryOnCreateEcp
                (param_1,*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20));
      return 0;
    }
    lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x20);
    if ((*(uint *)(lVar1 + 0x38) & 0x400) == 0) {
      return 0;
    }
    uVar4 = WcUnionsExistForInstance
                      (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),local_res8,
                       (undefined4 *)0x0);
    if ((char)uVar4 == '\0') {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0;
      }
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x53,
                         &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                         "onecore\\base\\fs\\wci\\wcifs\\create.c",0xb2);
      return 0;
    }
    if (*(int *)(lVar1 + 0x3c) == local_res8[0]) {
      bVar2 = WcIsSiloFileObject(*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20));
      if (bVar2) {
        *(undefined4 *)(lVar1 + 0x3c) = 0;
        uVar3 = *(uint *)(lVar1 + 0x38) & 0xffffe9ff;
        if (uVar3 == 0) {
          uVar3 = 0x80;
        }
        *(uint *)(lVar1 + 0x38) = uVar3;
        WcHandleQueryOnCreateEcp
                  (param_1,*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20));
        return 0;
      }
    }
    else if (*(int *)(lVar1 + 0x3c) != -0x5fffffe1) {
      return 0;
    }
  }
  return 2;
}



===== WcRedirectCallbackData @ 1400159a4 =====

uint WcRedirectCallbackData(longlong param_1,longlong param_2,short *param_3)

{
  short sVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  longlong local_res20;
  undefined8 local_48;
  longlong lStack_40;
  undefined8 local_38;
  longlong lStack_30;
  
  local_res20 = 0;
  local_48 = 0;
  lStack_40 = 0;
  local_38 = 0;
  lStack_30 = 0;
  RtlInitUnicodeString(&local_48,0);
  uVar5 = Feature_944920889__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar5 != 0) {
    uVar4 = WcValidateTagDataReparseInfo(*(longlong *)(param_1 + 0x28));
    if ((int)uVar4 < 0) goto LAB_140015b51;
  }
  lVar2 = *(longlong *)(param_1 + 0x28);
  uVar6 = WcLookupLayer(param_2,(longlong *)(param_2 + 0xa8),(longlong *)(lVar2 + 0x10),&local_res20
                       );
  lVar3 = local_res20;
  uVar4 = (uint)uVar6;
  if (-1 < (int)uVar4) {
    uVar4 = RtlUShortAdd(*(ushort *)(local_res20 + 0x18),*(short *)(lVar2 + 0x20),
                         (ushort *)((longlong)&local_48 + 2));
    if (-1 < (int)uVar4) {
      uVar4 = RtlUShortAdd(local_48._2_2_,*param_3,(ushort *)((longlong)&local_48 + 2));
      if (-1 < (int)uVar4) {
        uVar6 = WcAllocateUnicodeString(0x6e664357,(undefined2 *)&local_48);
        uVar4 = (uint)uVar6;
        if (-1 < (int)uVar4) {
          RtlCopyUnicodeString(&local_48,lVar3 + 0x18);
          sVar1 = *(short *)(lVar2 + 0x20);
          if (sVar1 == 0) {
            local_48 = CONCAT62(local_48._2_6_,(short)local_48 + -2);
          }
          else {
            local_38 = CONCAT62(CONCAT42(local_38._4_4_,sVar1),sVar1);
            lStack_30 = lVar2 + 0x22;
            uVar4 = RtlAppendUnicodeStringToString(&local_48,&local_38);
            if ((int)uVar4 < 0) goto LAB_140015b51;
          }
          uVar4 = RtlAppendUnicodeStringToString(&local_48,param_3);
          if (-1 < (int)uVar4) {
            uVar4 = IoReplaceFileObjectName
                              (*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 8),lStack_40,
                               local_48 & 0xffff);
            if (-1 < (int)uVar4) {
              ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x28),0);
              *(undefined8 *)(param_1 + 0x28) = 0;
              FltSetCallbackDataDirty(param_1);
              *(undefined4 *)(param_1 + 0x18) = 0x104;
              *(ulonglong *)(param_1 + 0x20) = (ulonglong)((byte)~*(byte *)(param_2 + 0x20) & 2);
            }
          }
        }
      }
    }
  }
LAB_140015b51:
  if (lStack_40 != 0) {
    ExFreePoolWithTag(lStack_40,0x6e664357);
  }
  return uVar4;
}



===== wil_RtlStagingConfig_QueryFeatureState @ 140015b94 =====

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



===== WcEnumerateDirectoryWithMerge @ 140015c60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint WcEnumerateDirectoryWithMerge
               (longlong param_1,longlong param_2,int param_3,undefined8 *param_4,undefined4 param_5
               ,byte param_6,uint param_7,undefined8 *param_8,uint *param_9)

{
  uint uVar1;
  bool bVar2;
  char cVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  longlong *plVar7;
  uint uVar8;
  undefined2 uVar9;
  int iVar10;
  undefined1 auStackY_158 [32];
  undefined1 uVar11;
  undefined1 in_stack_fffffffffffffef0;
  char local_e8 [8];
  longlong *local_e0;
  int local_d8;
  uint local_d4;
  uint local_d0;
  uint local_cc;
  longlong local_c8;
  longlong local_c0;
  uint *local_b8;
  longlong local_b0;
  longlong local_a8;
  undefined8 *local_a0;
  undefined8 *local_98;
  void *local_90;
  undefined8 local_88 [4];
  char *local_68;
  undefined8 local_60;
  uint **local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_158;
  local_98 = param_8;
  plVar7 = (longlong *)0x0;
  local_b8 = param_9;
  local_e0 = (longlong *)0x0;
  uVar4 = 0;
  local_c8 = 0;
  local_c0 = 0;
  cVar3 = '\0';
  local_e8[0] = '\0';
  local_d4 = 0;
  local_d8 = 0;
  local_d0 = 0;
  local_90 = (void *)0x0;
  local_cc = 0;
  local_b0 = param_2;
  local_a8 = param_1;
  local_a0 = param_4;
  bVar2 = WcGetContextFileObject(param_1,param_2,&local_c0,&local_c8);
  if (!bVar2) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,0x12,0x1c,
                          &WPP_795aeb0acc6f36f288a32122a031d179_Traceguids,
                          "onecore\\base\\fs\\wci\\wcifs\\dir.c",0x26,(char)param_3);
    }
    *param_9 = 0;
    goto LAB_140016405;
  }
  if ((param_6 & 4) != 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0x12,0x1d,
                         &WPP_795aeb0acc6f36f288a32122a031d179_Traceguids,
                         "onecore\\base\\fs\\wci\\wcifs\\dir.c",0x31);
    }
    if ((5 < DAT_14000f060) &&
       (uVar5 = _tlgKeywordOn(0x14000f060,0x400000000000), (char)uVar5 != '\0')) {
      local_68 = local_e8;
      local_e8[0] = '\x04';
      local_58 = &local_b8;
      local_60 = 1;
      local_b8 = (uint *)0x4;
      local_50 = 8;
      _tlgWriteTransfer_EtwWriteTransfer(0x14000f060,&DAT_14000b551,0,0,4,local_88);
    }
    uVar4 = 0xc00000bb;
    goto LAB_140016405;
  }
  if (param_3 < 0x27) {
    if (param_3 == 0x26) {
LAB_140015eb7:
      uVar4 = 0x50;
    }
    else if (param_3 == 1) {
      uVar4 = 0x40;
    }
    else {
      if (param_3 != 2) {
        if (param_3 == 3) {
          uVar4 = 0x5e;
        }
        else {
          if (param_3 == 0xc) {
            uVar4 = 0xc;
            goto LAB_140015ea7;
          }
          if (param_3 == 0x21) {
            uVar4 = 0x10;
            uVar8 = 0x218;
            iVar10 = 0x21;
            goto LAB_140015f39;
          }
          if (param_3 != 0x25) goto LAB_140015ee6;
          uVar4 = 0x68;
        }
LAB_140015e89:
        uVar8 = 0x272;
        iVar10 = 0x4f;
        goto LAB_140015f39;
      }
      uVar4 = 0x44;
    }
LAB_140015ea7:
    uVar8 = 600;
    iVar10 = 0x4e;
  }
  else {
    iVar10 = 0x3c;
    if (param_3 == 0x3c) {
      uVar8 = 0x260;
      uVar4 = 0x58;
    }
    else if (param_3 == 0x3f) {
      uVar4 = 0x72;
      uVar8 = 0x27a;
      iVar10 = 0x3f;
    }
    else {
      if (param_3 == 0x4e) goto LAB_140015eb7;
      if (param_3 == 0x4f) {
        uVar4 = 0x6a;
        goto LAB_140015e89;
      }
      if (param_3 == 0x50) {
        uVar4 = 0x60;
        uVar8 = 0x268;
        iVar10 = 0x50;
      }
      else {
        if (param_3 != 0x51) {
LAB_140015ee6:
          uVar4 = 0xc000000d;
          goto LAB_140016405;
        }
        uVar4 = 0x7a;
        uVar8 = 0x282;
        iVar10 = 0x51;
      }
    }
  }
LAB_140015f39:
  if (param_7 < uVar4) {
    uVar4 = 0xc0000004;
    goto LAB_140016405;
  }
  if (uVar8 <= param_7) {
    if (param_7 < 0x10001) {
      uVar4 = uVar4 + 7 & 0xfffffff8;
      uVar8 = (param_7 / uVar4) * ((uVar8 + 7 & 0xfffffff8) - uVar4) + param_7;
      if (0x10000 < uVar8) {
        uVar8 = 0x10000;
      }
    }
    else {
      uVar8 = 0x10000;
    }
  }
  uVar5 = WcGetSetStreamHandleContext(local_a8,param_2,(longlong *)&local_e0);
  plVar7 = local_e0;
  uVar4 = (uint)uVar5;
  uVar5 = uVar5 & 0xffffffff;
  if (-1 < (int)uVar4) {
    KeWaitForSingleObject(local_e0 + 2,0,0,0);
    local_e0 = (longlong *)CONCAT44(local_e0._4_4_,1);
    if ((param_6 & 1) != 0) {
      *(uint *)(plVar7 + 5) = *(uint *)(plVar7 + 5) & 0xfffffffd;
    }
    if (((param_6 & 0x10) == 0) && ((*(uint *)(plVar7 + 5) & 2) != 0)) {
      uVar4 = 0x80000006;
    }
    else if (((((*(uint *)(*(longlong *)
                            (*(longlong *)(*(longlong *)(local_c8 + 0x38) + 0x18) + 0x20) + 0x10) &
                1) == 0) && ((longlong *)plVar7[6] == plVar7 + 6)) &&
             (local_a0 != (undefined8 *)0x0)) &&
            (cVar3 = FsRtlDoesNameContainWildCards(local_a0), cVar3 == '\0')) {
      uVar5 = WcEnumerateDirectorySingleEntry
                        (local_c8,local_a8,local_b0,iVar10,param_3,local_a0,uVar8,param_6,
                         **(uint **)(local_c0 + 0x40),in_stack_fffffffffffffef0,param_7,local_98,
                         local_b8);
      uVar4 = (uint)uVar5;
      if (uVar4 == 0) {
        cVar3 = (char)local_e0;
        if ((param_6 & 0x10) == 0) {
          *(uint *)(plVar7 + 5) = *(uint *)(plVar7 + 5) | 2;
        }
        goto LAB_1400163d1;
      }
    }
    else {
      if ((longlong *)plVar7[6] == plVar7 + 6) {
        uVar6 = IoGetSilo(local_b0);
        uVar5 = PsGetParentSilo(uVar6);
        uVar4 = WcCopySourceList((undefined8 *)(local_c8 + 0x38),uVar5,(longlong)(plVar7 + 6));
        uVar5 = (ulonglong)uVar4;
        if ((int)uVar4 < 0) goto LAB_1400163cc;
        *(uint *)(plVar7 + 5) = *(uint *)(plVar7 + 5) | 4;
      }
      if ((param_6 & 1) == 0) {
        if ((((*(uint *)(plVar7 + 5) & 4) != 0) && ((int)plVar7[9] != 0)) &&
           (*(int *)((longlong)plVar7 + 0x254) == 0)) {
          param_6 = param_6 | (byte)local_e0;
        }
      }
      else {
        *(undefined4 *)(plVar7 + 9) = 0;
        *(undefined4 *)((longlong)plVar7 + 0x254) = 0;
        *(uint *)(plVar7 + 5) = *(uint *)(plVar7 + 5) | 4;
      }
      while (((-1 < (int)uVar4 && (local_e8[0] == '\0')) && (local_d4 < param_7))) {
        uVar5 = WcPrepareEnumerationContexts
                          (plVar7,local_a8,local_b0,plVar7 + 6,uVar8,iVar10,param_6,
                           *(int *)((longlong)plVar7 + 0x254));
        uVar4 = (uint)uVar5;
        if ((int)uVar4 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar9 = 0x1e;
            uVar11 = 0x39;
LAB_140016315:
            WPP_RECORDER_SF_sDdd
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0x12,uVar9,
                       &WPP_795aeb0acc6f36f288a32122a031d179_Traceguids,
                       "onecore\\base\\fs\\wci\\wcifs\\dir.c",uVar11,(char)param_3,(char)uVar4);
          }
          goto LAB_1400163cc;
        }
        uVar6 = WcEnumerateLayeredDirectories
                          (plVar7,local_a0,(longlong)plVar7 + 0x4c,
                           *(int *)((longlong)plVar7 + 0x254),param_5);
        uVar4 = (uint)uVar6;
        if ((int)uVar4 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar9 = 0x1f;
            uVar11 = 0x45;
            goto LAB_140016315;
          }
          goto LAB_1400163cc;
        }
        uVar4 = WcMergeEnumerationResults
                          (plVar7,param_3,**(uint **)(local_c0 + 0x40),param_7,(longlong)local_98,
                           &local_d8,(longlong *)&local_90,&local_cc);
        uVar1 = local_cc;
        uVar5 = (ulonglong)uVar4;
        if ((uVar4 == 0x80000006) || (uVar4 == 0xc000000f)) {
          local_e8[0] = (byte)local_e0;
        }
        else if (uVar4 == 0x80000005) {
          *(int *)(plVar7 + 9) = (int)plVar7[9] + local_d8;
          *(uint *)(plVar7 + 5) = *(uint *)(plVar7 + 5) | 4;
          local_e8[0] = (byte)local_e0;
        }
        else {
          if ((int)uVar4 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar9 = 0x20;
              uVar11 = 0x5e;
              goto LAB_140016315;
            }
            goto LAB_1400163cc;
          }
          if (local_cc != 0) {
            memmove((void *)((longlong)plVar7 + 0x4c),local_90,(ulonglong)local_cc);
          }
          *(uint *)((longlong)plVar7 + 0x254) = uVar1;
          if (local_d8 == 0) {
            WcResetEnumContexts(plVar7,(byte)local_e0);
            param_6 = param_6 & 0xfe;
            local_e8[0] = '\0';
          }
          else {
            local_d4 = local_d4 + local_d8;
            *(int *)(plVar7 + 9) = (int)plVar7[9] + local_d8;
            local_e8[0] = (byte)local_e0;
          }
        }
        local_d0 = local_d0 + local_d8;
      }
      if (((*(uint *)(plVar7 + 5) & 4) != 0) && (uVar4 != 0x80000005)) {
        if ((uVar4 == 0x80000006) && (uVar4 = (uint)uVar5, (int)plVar7[9] == 0)) {
          uVar4 = 0xc000000f;
        }
        *(uint *)(plVar7 + 5) = *(uint *)(plVar7 + 5) & 0xfffffffb;
      }
      *local_b8 = local_d0;
    }
LAB_1400163cc:
    cVar3 = (char)local_e0;
  }
LAB_1400163d1:
  if (plVar7 != (longlong *)0x0) {
    if ((int)uVar4 < 0) {
      WcFreeEnumContexts(plVar7);
    }
    else {
      WcResetEnumContexts(plVar7,'\0');
    }
  }
  if (cVar3 != '\0') {
    KeSetEvent(plVar7 + 2,0,0);
  }
LAB_140016405:
  if (local_c0 != 0) {
    FltReleaseContext(local_c0);
  }
  if (local_c8 != 0) {
    FltReleaseContext(local_c8);
  }
  if (plVar7 != (longlong *)0x0) {
    FltReleaseContext(plVar7);
  }
  return uVar4;
}



===== WcEnumerateDirectoryWithMunge @ 14001647c =====

ulonglong WcEnumerateDirectoryWithMunge
                    (longlong param_1,longlong param_2,int param_3,undefined8 param_4,
                    undefined4 param_5,byte param_6,uint param_7,uint param_8,uint param_9,
                    longlong param_10,int *param_11)

{
  bool bVar1;
  undefined8 ***pppuVar2;
  uint uVar3;
  int iVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  int iVar7;
  ulonglong uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  undefined8 local_res20;
  byte local_a8;
  char local_9c;
  int local_98;
  uint local_94;
  uint local_90;
  uint local_8c;
  uint local_88;
  uint local_84;
  undefined8 ***local_80;
  undefined8 ***local_78;
  uint local_70;
  int local_6c;
  undefined4 local_68;
  uint *local_60;
  uint *local_58;
  undefined8 ***local_50;
  undefined8 local_48;
  
  local_8c = 0x100;
  local_88 = 0;
  local_60 = (uint *)0x0;
  local_94 = 0;
  local_98 = 0;
  local_58 = (uint *)0x0;
  local_90 = 0;
  local_9c = '\x01';
  bVar1 = true;
  local_78 = &local_80;
  local_80 = &local_80;
  if (param_3 < 0x27) {
    if (param_3 == 0x26) {
      uVar3 = 0x50;
      uVar9 = 0x50;
      iVar7 = 0x4e;
    }
    else {
      if (param_3 == 1) {
        uVar3 = 0x40;
      }
      else {
        if (param_3 != 2) {
          if (param_3 == 3) {
            uVar3 = 0x5e;
          }
          else {
            if (param_3 == 0xc) {
              uVar3 = 0xc;
              goto LAB_140016545;
            }
            if (param_3 == 0x21) {
              uVar3 = 0x10;
              iVar7 = 0x21;
              goto LAB_1400165d3;
            }
            if (param_3 != 0x25) goto LAB_140016a10;
            uVar3 = 0x68;
          }
LAB_140016524:
          iVar7 = 0x4f;
          uVar9 = 0x6a;
          goto LAB_1400165da;
        }
        uVar3 = 0x44;
      }
LAB_140016545:
      uVar9 = 0x50;
      iVar7 = 0x4e;
    }
LAB_1400165da:
    uVar11 = param_9 + uVar9;
    local_6c = iVar7;
    if ((uVar9 <= uVar11) && (uVar3 <= uVar11)) {
      uVar11 = uVar11 - uVar3;
      if (0x10000 < uVar11) {
        uVar11 = 0x10000;
      }
      local_res20 = param_4;
      local_84 = uVar11;
      while( true ) {
        local_70 = local_8c;
        local_68 = param_5;
        local_48 = local_res20;
        uVar5 = WcPrepareEnumerationContexts
                          ((longlong *)&local_80,param_1,param_2,(undefined8 *)0x0,uVar11,iVar7,
                           param_6,0);
        pppuVar2 = local_80;
        uVar8 = uVar5 & 0xffffffff;
        if ((int)uVar5 < 0) break;
        local_50 = local_80;
        uVar3 = WcEnumerateDirectory
                          (param_1,param_2,iVar7,local_res20,param_5,param_6,
                           *(undefined4 *)(local_80 + 8),local_80[9],
                           (undefined4 *)((longlong)local_80 + 0x3c));
        uVar8 = (ulonglong)uVar3;
        if (-1 < (int)uVar3) {
          if (*(int *)((longlong)pppuVar2 + 0x3c) != 0) {
            iVar10 = local_98;
            do {
              do {
                local_a8 = param_6;
                if (param_9 <= local_94) goto LAB_14001697b;
                uVar6 = WcSkipReparsePointInEnumeration((longlong)pppuVar2,-0x5fffffe1);
              } while (((char)uVar6 != '\0') ||
                      ((param_3 == 0x21 &&
                       ((uVar6 = WcSkipReparsePointInEnumeration
                                           ((longlong)pppuVar2,*(int *)((longlong)pppuVar2 + 0x14)),
                        (char)uVar6 != '\0' ||
                        (uVar6 = WcSkipReparsePointInEnumeration((longlong)pppuVar2,param_8),
                        (char)uVar6 != '\0'))))));
              uVar8 = WcTranslateNextEnumEntry
                                ((longlong)pppuVar2,param_3,param_7,param_8,local_9c,
                                 param_9 - local_94,(undefined8 *)((ulonglong)local_94 + param_10),
                                 &local_60,&local_88);
              iVar4 = (int)uVar8;
              uVar8 = uVar8 & 0xffffffff;
              if (iVar4 == -0x7ffffffb) {
                local_90 = local_88;
                break;
              }
              if (iVar4 < 0) goto LAB_140016a15;
              if (local_88 == 0) break;
              if (local_90 != 0) {
                if (param_3 == 0x21) {
                  iVar10 = local_98 + local_90;
                  local_98 = iVar10;
                }
                else {
                  iVar10 = iVar10 + (local_90 + 7 & 0xfffffff8);
                  local_98 = iVar10;
                }
              }
              if ((local_58 != (uint *)0x0) && (*local_58 = local_90 + 7 & 0xfffffff8, iVar4 < 0))
              goto LAB_140016a15;
              local_9c = '\0';
              local_90 = local_88;
              local_58 = local_60;
              local_94 = local_94 + (local_88 + 7 & 0xfffffff8);
              WcAdvanceNextEnumEntry((longlong)pppuVar2);
            } while ((param_6 & 2) == 0);
            goto LAB_14001697b;
          }
LAB_140016a03:
          *param_11 = local_98;
          goto LAB_140016a15;
        }
        if (uVar3 != 0x80000005) {
          if (((uVar3 == 0x80000006) && (!bVar1)) && (local_94 == 0)) {
            uVar8 = 0xc000000f;
          }
          goto LAB_140016a15;
        }
        local_a8 = param_6 | 2;
        uVar3 = WcGetNextEntryFileName((longlong)pppuVar2,(longlong *)0x0);
        if (uVar3 == 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,0x12,0x1b,
                               &WPP_795aeb0acc6f36f288a32122a031d179_Traceguids,
                               "onecore\\base\\fs\\wci\\wcifs\\dir.c",0x84);
          }
          uVar3 = local_8c * 2;
          if (bVar1) {
            uVar3 = local_70;
          }
        }
        uVar11 = uVar3 + uVar9;
        local_8c = uVar3;
        local_84 = uVar11;
LAB_14001697b:
        local_98 = local_98 + local_90;
        if (local_98 != 0) goto LAB_140016a03;
        if ((int)uVar8 < 0) {
          WcFreeEnumContexts((longlong *)&local_80);
        }
        else {
          WcResetEnumContexts(&local_80,'\x01');
        }
        param_6 = local_a8 & 0xfa;
        bVar1 = false;
        param_5 = 0;
        if (local_6c != 0x21) {
          param_5 = local_68;
        }
        local_res20 = 0;
        if (local_6c != 0x21) {
          local_res20 = local_48;
        }
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDdd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0x12,0x1a,
                   &WPP_795aeb0acc6f36f288a32122a031d179_Traceguids,
                   "onecore\\base\\fs\\wci\\wcifs\\dir.c",0x52,(char)param_3,(char)uVar5);
      }
      goto LAB_140016a15;
    }
  }
  else {
    iVar7 = 0x3c;
    if (param_3 == 0x3c) {
      uVar3 = 0x58;
LAB_1400165d3:
      uVar9 = uVar3;
      goto LAB_1400165da;
    }
    if (param_3 == 0x3f) {
      uVar3 = 0x72;
      iVar7 = 0x3f;
      goto LAB_1400165d3;
    }
    if (param_3 == 0x4e) {
      uVar3 = 0x50;
      goto LAB_140016545;
    }
    if (param_3 == 0x4f) {
      uVar3 = 0x6a;
      goto LAB_140016524;
    }
    if (param_3 == 0x50) {
      uVar3 = 0x60;
      iVar7 = 0x50;
      goto LAB_1400165d3;
    }
    if (param_3 == 0x51) {
      uVar3 = 0x7a;
      iVar7 = 0x51;
      goto LAB_1400165d3;
    }
  }
LAB_140016a10:
  uVar8 = 0xc000000d;
LAB_140016a15:
  WcFreeEnumContexts((longlong *)&local_80);
  return uVar8;
}



===== WcMungeDirectoryEnumerateWithShortname @ 140016a3c =====

undefined4
WcMungeDirectoryEnumerateWithShortname
          (int param_1,char param_2,undefined8 *param_3,char param_4,uint param_5,uint param_6,
          undefined8 *param_7,uint param_8,undefined8 *param_9,uint *param_10)

{
  byte bVar1;
  uint uVar2;
  undefined8 uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  
  uVar6 = 0;
  uVar5 = 0;
  if (param_1 != 0x3f) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,0x12,0xc,
                          &WPP_795aeb0acc6f36f288a32122a031d179_Traceguids,
                          "onecore\\base\\fs\\wci\\wcifs\\dir.c",9,(char)param_1);
    }
    uVar6 = 0xc00000bb;
    goto LAB_140016c9d;
  }
  uVar2 = *(uint *)((longlong)param_3 + 0x3c);
  if ((param_8 < uVar2 + 0x72) && ((param_8 < 0x72 || (param_2 == '\0')))) goto LAB_140016c9d;
  uVar5 = uVar2;
  if (param_8 - 0x72 <= uVar2) {
    uVar5 = param_8 - 0x72;
  }
  uVar3 = param_3[1];
  *param_7 = *param_3;
  param_7[1] = uVar3;
  uVar3 = param_3[3];
  param_7[2] = param_3[2];
  param_7[3] = uVar3;
  uVar3 = param_3[5];
  param_7[4] = param_3[4];
  param_7[5] = uVar3;
  uVar3 = param_3[7];
  param_7[6] = param_3[6];
  param_7[7] = uVar3;
  uVar3 = param_3[9];
  param_7[8] = param_3[8];
  param_7[9] = uVar3;
  param_7[10] = param_3[10];
  if (param_4 == '\0') {
    param_7[9] = 0xffffffffffffffff;
    param_7[10] = 0xffffffffffffffff;
LAB_140016baf:
    *(undefined1 *)(param_7 + 0xb) = 0;
  }
  else {
    bVar1 = *(byte *)(param_3 + 0xb);
    if (0x18 < bVar1) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0x12,0xb,
                            &WPP_795aeb0acc6f36f288a32122a031d179_Traceguids,
                            "onecore\\base\\fs\\wci\\wcifs\\dir.c",0xdf,bVar1);
      }
      goto LAB_140016baf;
    }
    *(byte *)(param_7 + 0xb) = bVar1;
    memmove((void *)((longlong)param_7 + 0x5a),(void *)((longlong)param_3 + 0x5a),
            (longlong)*(char *)(param_3 + 0xb));
  }
  if (*(uint *)((longlong)param_3 + 0x44) == param_5) {
    uVar4 = *(uint *)(param_3 + 7) & 0xffffe9ff;
    if (uVar4 == 0) {
      uVar4 = 0x80;
    }
LAB_140016c4f:
    *(uint *)(param_7 + 7) = uVar4;
    *(undefined4 *)((longlong)param_7 + 0x44) = 0;
  }
  else if (((((param_6 & 0xfff0000) == 0) && (2 < param_6)) &&
           ((param_6 & 0xc0000000) != 0x40000000)) &&
          (((param_6 & 0x30000000) != 0x30000000 && (*(uint *)((longlong)param_3 + 0x44) == param_6)
           ))) {
    uVar4 = *(uint *)(param_3 + 7) & 0xffffe9ff;
    if (uVar4 == 0) {
      uVar4 = 0x80;
    }
    goto LAB_140016c4f;
  }
  if (param_4 == '\0') {
    *(uint *)(param_7 + 7) = *(uint *)(param_7 + 7) & 0xffffbfff;
  }
  memmove((void *)((longlong)param_7 + 0x72),(void *)((longlong)param_3 + 0x72),(ulonglong)uVar5);
  *(undefined4 *)param_7 = 0;
  *param_9 = param_7;
  uVar5 = uVar5 + 0x72;
  uVar6 = 0;
  if (uVar5 < uVar2 + 0x72) {
    uVar6 = 0x80000005;
  }
LAB_140016c9d:
  *param_10 = uVar5;
  return uVar6;
}



===== WcMungeDirectoryEnumerateWithShortnameFileId64 @ 140016cd8 =====

undefined4
WcMungeDirectoryEnumerateWithShortnameFileId64
          (int param_1,char param_2,undefined8 *param_3,char param_4,uint param_5,uint param_6,
          undefined8 *param_7,uint param_8,undefined8 *param_9,uint *param_10)

{
  byte bVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  
  uVar6 = 0;
  uVar4 = 0;
  if (param_1 != 3) {
    if (param_1 == 0x25) {
      uVar5 = *(uint *)((longlong)param_3 + 0x3c);
      uVar7 = uVar5 + 0x68;
      if ((param_8 < uVar7) && ((param_8 < 0x68 || (param_2 == '\0')))) goto LAB_140017333;
      if (param_8 - 0x68 <= uVar5) {
        uVar5 = param_8 - 0x68;
      }
      uVar3 = param_3[1];
      *param_7 = *param_3;
      param_7[1] = uVar3;
      uVar3 = param_3[3];
      param_7[2] = param_3[2];
      param_7[3] = uVar3;
      uVar3 = param_3[5];
      param_7[4] = param_3[4];
      param_7[5] = uVar3;
      param_7[6] = param_3[6];
      if (*(uint *)((longlong)param_3 + 0x44) == param_5) {
        uVar4 = *(uint *)(param_3 + 7) & 0xffffe9ff;
        if (uVar4 == 0) {
          uVar4 = 0x80;
        }
LAB_140016fc4:
        *(uint *)(param_7 + 7) = uVar4;
LAB_140016fca:
        uVar2 = *(undefined4 *)(param_3 + 8);
      }
      else {
        if (((((param_6 & 0xfff0000) == 0) && (2 < param_6)) &&
            ((param_6 & 0xc0000000) != 0x40000000)) &&
           (((param_6 & 0x30000000) != 0x30000000 &&
            (*(uint *)((longlong)param_3 + 0x44) == param_6)))) {
          uVar4 = *(uint *)(param_3 + 7) & 0xffffe9ff;
          if (uVar4 == 0) {
            uVar4 = 0x80;
          }
          goto LAB_140016fc4;
        }
        *(undefined4 *)(param_7 + 7) = *(undefined4 *)(param_3 + 7);
        if ((*(uint *)(param_3 + 7) & 0x400) == 0) goto LAB_140016fca;
        uVar2 = *(undefined4 *)((longlong)param_3 + 0x44);
      }
      *(undefined4 *)(param_7 + 8) = uVar2;
      if (param_4 == '\0') {
        *(uint *)(param_7 + 7) = *(uint *)(param_7 + 7) & 0xffffbfff;
        param_7[0xc] = 0xffffffffffffffff;
LAB_1400170eb:
        *(undefined1 *)((longlong)param_7 + 0x44) = 0;
      }
      else {
        param_7[0xc] = param_3[9];
        bVar1 = *(byte *)(param_3 + 10);
        if (0x18 < bVar1) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0x12,0xf,
                                &WPP_795aeb0acc6f36f288a32122a031d179_Traceguids,
                                "onecore\\base\\fs\\wci\\wcifs\\dir.c",0xf1,bVar1);
          }
          goto LAB_1400170eb;
        }
        *(byte *)((longlong)param_7 + 0x44) = bVar1;
        memmove((void *)((longlong)param_7 + 0x46),(void *)((longlong)param_3 + 0x52),
                (longlong)*(char *)(param_3 + 10));
      }
      *(undefined1 *)((longlong)param_7 + 0x44) = 0;
      *(undefined8 *)((longlong)param_7 + 0x46) = 0;
      *(undefined8 *)((longlong)param_7 + 0x4e) = 0;
      *(undefined8 *)((longlong)param_7 + 0x56) = 0;
      *(undefined4 *)((longlong)param_7 + 0x3c) = *(undefined4 *)((longlong)param_3 + 0x3c);
      memmove(param_7 + 0xd,(void *)((longlong)param_3 + 0x6a),(ulonglong)uVar5);
      *(undefined4 *)param_7 = 0;
      *param_9 = param_7;
      uVar4 = uVar5 + 0x68;
    }
    else {
      if (param_1 != 0x4f) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,0x12,0x11,
                              &WPP_795aeb0acc6f36f288a32122a031d179_Traceguids,
                              "onecore\\base\\fs\\wci\\wcifs\\dir.c",0x57,(char)param_1);
        }
        uVar6 = 0xc00000bb;
        uVar4 = 0;
        goto LAB_140017333;
      }
      uVar5 = *(uint *)((longlong)param_3 + 0x3c);
      uVar7 = uVar5 + 0x6a;
      if ((param_8 < uVar7) && ((param_8 < 0x6a || (param_2 == '\0')))) goto LAB_140017333;
      if (param_8 - 0x6a <= uVar5) {
        uVar5 = param_8 - 0x6a;
      }
      uVar3 = param_3[1];
      *param_7 = *param_3;
      param_7[1] = uVar3;
      uVar3 = param_3[3];
      param_7[2] = param_3[2];
      param_7[3] = uVar3;
      uVar3 = param_3[5];
      param_7[4] = param_3[4];
      param_7[5] = uVar3;
      uVar3 = param_3[7];
      param_7[6] = param_3[6];
      param_7[7] = uVar3;
      uVar3 = param_3[9];
      param_7[8] = param_3[8];
      param_7[9] = uVar3;
      if (param_4 == '\0') {
        param_7[9] = 0xffffffffffffffff;
LAB_140016e54:
        *(undefined1 *)(param_7 + 10) = 0;
      }
      else {
        bVar1 = *(byte *)(param_3 + 10);
        if (0x18 < bVar1) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0x12,0x10,
                                &WPP_795aeb0acc6f36f288a32122a031d179_Traceguids,
                                "onecore\\base\\fs\\wci\\wcifs\\dir.c",0x2d,bVar1);
          }
          goto LAB_140016e54;
        }
        *(byte *)(param_7 + 10) = bVar1;
        memmove((void *)((longlong)param_7 + 0x52),(void *)((longlong)param_3 + 0x52),
                (longlong)*(char *)(param_3 + 10));
      }
      if (*(uint *)((longlong)param_3 + 0x44) == param_5) {
        uVar4 = *(uint *)(param_3 + 7) & 0xffffe9ff;
        if (uVar4 == 0) {
          uVar4 = 0x80;
        }
LAB_140016ef3:
        *(uint *)(param_7 + 7) = uVar4;
        *(undefined4 *)((longlong)param_7 + 0x44) = 0;
      }
      else if (((((param_6 & 0xfff0000) == 0) && (2 < param_6)) &&
               ((param_6 & 0xc0000000) != 0x40000000)) &&
              (((param_6 & 0x30000000) != 0x30000000 &&
               (*(uint *)((longlong)param_3 + 0x44) == param_6)))) {
        uVar4 = *(uint *)(param_3 + 7) & 0xffffe9ff;
        if (uVar4 == 0) {
          uVar4 = 0x80;
        }
        goto LAB_140016ef3;
      }
      if (param_4 == '\0') {
        *(uint *)(param_7 + 7) = *(uint *)(param_7 + 7) & 0xffffbfff;
      }
      memmove((void *)((longlong)param_7 + 0x6a),(void *)((longlong)param_3 + 0x6a),(ulonglong)uVar5
             );
      *(undefined4 *)param_7 = 0;
      *param_9 = param_7;
      uVar4 = uVar5 + 0x6a;
    }
    if (uVar4 < uVar7) {
      uVar6 = 0x80000005;
    }
    goto LAB_140017333;
  }
  uVar7 = *(uint *)((longlong)param_3 + 0x3c);
  if ((param_8 < uVar7 + 0x5e) && ((param_8 < 0x5e || (param_2 == '\0')))) goto LAB_140017333;
  uVar4 = uVar7;
  if (param_8 - 0x5e <= uVar7) {
    uVar4 = param_8 - 0x5e;
  }
  uVar3 = param_3[1];
  *param_7 = *param_3;
  param_7[1] = uVar3;
  uVar3 = param_3[3];
  param_7[2] = param_3[2];
  param_7[3] = uVar3;
  uVar3 = param_3[5];
  param_7[4] = param_3[4];
  param_7[5] = uVar3;
  param_7[6] = param_3[6];
  if (*(uint *)((longlong)param_3 + 0x44) == param_5) {
    uVar5 = *(uint *)(param_3 + 7) & 0xffffe9ff;
    if (uVar5 == 0) {
      uVar5 = 0x80;
    }
LAB_1400171d6:
    *(uint *)(param_7 + 7) = uVar5;
LAB_1400171dc:
    uVar6 = *(undefined4 *)(param_3 + 8);
  }
  else {
    if (((((param_6 & 0xfff0000) == 0) && (2 < param_6)) && ((param_6 & 0xc0000000) != 0x40000000))
       && (((param_6 & 0x30000000) != 0x30000000 && (*(uint *)((longlong)param_3 + 0x44) == param_6)
           ))) {
      uVar5 = *(uint *)(param_3 + 7) & 0xffffe9ff;
      if (uVar5 == 0) {
        uVar5 = 0x80;
      }
      goto LAB_1400171d6;
    }
    *(undefined4 *)(param_7 + 7) = *(undefined4 *)(param_3 + 7);
    if ((*(uint *)(param_3 + 7) & 0x400) == 0) goto LAB_1400171dc;
    uVar6 = *(undefined4 *)((longlong)param_3 + 0x44);
  }
  *(undefined4 *)(param_7 + 8) = uVar6;
  if (param_4 == '\0') {
    *(uint *)(param_7 + 7) = *(uint *)(param_7 + 7) & 0xffffbfff;
LAB_1400172ee:
    *(undefined1 *)((longlong)param_7 + 0x44) = 0;
  }
  else {
    bVar1 = *(byte *)(param_3 + 10);
    if (0x18 < bVar1) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0x12,0xe,
                            &WPP_795aeb0acc6f36f288a32122a031d179_Traceguids,
                            "onecore\\base\\fs\\wci\\wcifs\\dir.c",0xa3,bVar1);
      }
      goto LAB_1400172ee;
    }
    *(byte *)((longlong)param_7 + 0x44) = bVar1;
    memmove((void *)((longlong)param_7 + 0x46),(void *)((longlong)param_3 + 0x52),
            (longlong)*(char *)(param_3 + 10));
  }
  *(undefined4 *)((longlong)param_7 + 0x3c) = *(undefined4 *)((longlong)param_3 + 0x3c);
  memmove((void *)((longlong)param_7 + 0x5e),(void *)((longlong)param_3 + 0x6a),(ulonglong)uVar4);
  *(undefined4 *)param_7 = 0;
  *param_9 = param_7;
  uVar4 = uVar4 + 0x5e;
  uVar6 = 0;
  if (uVar4 < uVar7 + 0x5e) {
    uVar6 = 0x80000005;
  }
LAB_140017333:
  *param_10 = uVar4;
  return uVar6;
}



===== WcMungeDirectoryEnumerateWithShortnameFileIdAll @ 140017370 =====

undefined4
WcMungeDirectoryEnumerateWithShortnameFileIdAll
          (int param_1,char param_2,undefined8 *param_3,char param_4,uint param_5,uint param_6,
          undefined8 *param_7,uint param_8,undefined8 *param_9,uint *param_10)

{
  byte bVar1;
  uint uVar2;
  undefined8 uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  
  uVar6 = 0;
  uVar5 = 0;
  if (param_1 != 0x51) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,0x12,0x14,
                          &WPP_795aeb0acc6f36f288a32122a031d179_Traceguids,
                          "onecore\\base\\fs\\wci\\wcifs\\dir.c",0x40,(char)param_1);
    }
    uVar6 = 0xc00000bb;
    goto LAB_1400175d4;
  }
  uVar2 = *(uint *)((longlong)param_3 + 0x3c);
  if ((param_8 < uVar2 + 0x7a) && ((param_8 < 0x7a || (param_2 == '\0')))) goto LAB_1400175d4;
  uVar5 = uVar2;
  if (param_8 - 0x7a <= uVar2) {
    uVar5 = param_8 - 0x7a;
  }
  uVar3 = param_3[1];
  *param_7 = *param_3;
  param_7[1] = uVar3;
  uVar3 = param_3[3];
  param_7[2] = param_3[2];
  param_7[3] = uVar3;
  uVar3 = param_3[5];
  param_7[4] = param_3[4];
  param_7[5] = uVar3;
  uVar3 = param_3[7];
  param_7[6] = param_3[6];
  param_7[7] = uVar3;
  uVar3 = param_3[9];
  param_7[8] = param_3[8];
  param_7[9] = uVar3;
  uVar3 = param_3[0xb];
  param_7[10] = param_3[10];
  param_7[0xb] = uVar3;
  if (param_4 == '\0') {
    param_7[9] = 0xffffffffffffffff;
    param_7[10] = 0xffffffffffffffff;
    param_7[0xb] = 0xffffffffffffffff;
LAB_1400174e6:
    *(undefined1 *)(param_7 + 0xc) = 0;
  }
  else {
    bVar1 = *(byte *)(param_3 + 0xc);
    if (0x18 < bVar1) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0x12,0x13,
                            &WPP_795aeb0acc6f36f288a32122a031d179_Traceguids,
                            "onecore\\base\\fs\\wci\\wcifs\\dir.c",0x15,bVar1);
      }
      goto LAB_1400174e6;
    }
    *(byte *)(param_7 + 0xc) = bVar1;
    memmove((void *)((longlong)param_7 + 0x62),(void *)((longlong)param_3 + 0x62),
            (longlong)*(char *)(param_3 + 0xc));
  }
  if (*(uint *)((longlong)param_3 + 0x44) == param_5) {
    uVar4 = *(uint *)(param_3 + 7) & 0xffffe9ff;
    if (uVar4 == 0) {
      uVar4 = 0x80;
    }
LAB_140017586:
    *(uint *)(param_7 + 7) = uVar4;
    *(undefined4 *)((longlong)param_7 + 0x44) = 0;
  }
  else if (((((param_6 & 0xfff0000) == 0) && (2 < param_6)) &&
           ((param_6 & 0xc0000000) != 0x40000000)) &&
          (((param_6 & 0x30000000) != 0x30000000 && (*(uint *)((longlong)param_3 + 0x44) == param_6)
           ))) {
    uVar4 = *(uint *)(param_3 + 7) & 0xffffe9ff;
    if (uVar4 == 0) {
      uVar4 = 0x80;
    }
    goto LAB_140017586;
  }
  if (param_4 == '\0') {
    *(uint *)(param_7 + 7) = *(uint *)(param_7 + 7) & 0xffffbfff;
  }
  memmove((void *)((longlong)param_7 + 0x7a),(void *)((longlong)param_3 + 0x7a),(ulonglong)uVar5);
  *(undefined4 *)param_7 = 0;
  *param_9 = param_7;
  uVar5 = uVar5 + 0x7a;
  uVar6 = 0;
  if (uVar5 < uVar2 + 0x7a) {
    uVar6 = 0x80000005;
  }
LAB_1400175d4:
  *param_10 = uVar5;
  return uVar6;
}



===== WcMungeDirectoryEnumerateWithoutShortname @ 140017610 =====

undefined4
WcMungeDirectoryEnumerateWithoutShortname
          (int param_1,char param_2,undefined8 *param_3,char param_4,uint param_5,uint param_6,
          undefined8 *param_7,uint param_8,undefined8 *param_9,uint *param_10)

{
  uint uVar1;
  undefined8 uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  uVar4 = 0;
  if (param_1 != 0x3c) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,0x12,10,
                          &WPP_795aeb0acc6f36f288a32122a031d179_Traceguids,
                          "onecore\\base\\fs\\wci\\wcifs\\dir.c",0x8a,(char)param_1);
    }
    uVar5 = 0xc00000bb;
    goto LAB_1400177fe;
  }
  uVar1 = *(uint *)((longlong)param_3 + 0x3c);
  if ((param_8 < uVar1 + 0x58) && ((param_8 < 0x58 || (param_2 == '\0')))) goto LAB_1400177fe;
  uVar4 = uVar1;
  if (param_8 - 0x58 <= uVar1) {
    uVar4 = param_8 - 0x58;
  }
  uVar2 = param_3[1];
  *param_7 = *param_3;
  param_7[1] = uVar2;
  uVar2 = param_3[3];
  param_7[2] = param_3[2];
  param_7[3] = uVar2;
  uVar2 = param_3[5];
  param_7[4] = param_3[4];
  param_7[5] = uVar2;
  uVar2 = param_3[7];
  param_7[6] = param_3[6];
  param_7[7] = uVar2;
  uVar2 = param_3[9];
  param_7[8] = param_3[8];
  param_7[9] = uVar2;
  param_7[10] = param_3[10];
  if (*(uint *)((longlong)param_3 + 0x44) == param_5) {
    uVar3 = *(uint *)(param_3 + 7) & 0xffffe9ff;
    if (uVar3 == 0) {
      uVar3 = 0x80;
    }
LAB_1400177a2:
    *(uint *)(param_7 + 7) = uVar3;
    *(undefined4 *)((longlong)param_7 + 0x44) = 0;
  }
  else if (((((param_6 & 0xfff0000) == 0) && (2 < param_6)) &&
           ((param_6 & 0xc0000000) != 0x40000000)) &&
          (((param_6 & 0x30000000) != 0x30000000 && (*(uint *)((longlong)param_3 + 0x44) == param_6)
           ))) {
    uVar3 = *(uint *)(param_3 + 7) & 0xffffe9ff;
    if (uVar3 == 0) {
      uVar3 = 0x80;
    }
    goto LAB_1400177a2;
  }
  if (param_4 == '\0') {
    *(uint *)(param_7 + 7) = *(uint *)(param_7 + 7) & 0xffffbfff;
  }
  memmove(param_7 + 0xb,param_3 + 0xb,(ulonglong)uVar4);
  if (param_4 == '\0') {
    param_7[9] = 0xffffffffffffffff;
    param_7[10] = 0xffffffffffffffff;
  }
  *(undefined4 *)param_7 = 0;
  *param_9 = param_7;
  uVar4 = uVar4 + 0x58;
  uVar5 = 0;
  if (uVar4 < uVar1 + 0x58) {
    uVar5 = 0x80000005;
  }
LAB_1400177fe:
  *param_10 = uVar4;
  return uVar5;
}



===== WcMungeDirectoryEnumerateWithoutShortnameFileId64 @ 140017838 =====

undefined4
WcMungeDirectoryEnumerateWithoutShortnameFileId64
          (int param_1,char param_2,undefined8 *param_3,char param_4,uint param_5,uint param_6,
          undefined8 *param_7,uint param_8,undefined8 *param_9,uint *param_10)

{
  undefined8 uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  bool bVar7;
  
  uVar5 = 0;
  uVar2 = 0;
  if (param_1 == 1) {
    uVar6 = *(uint *)((longlong)param_3 + 0x3c);
    if ((uVar6 + 0x40 <= param_8) || ((0x3f < param_8 && (param_2 != '\0')))) {
      uVar2 = uVar6;
      if (param_8 - 0x40 <= uVar6) {
        uVar2 = param_8 - 0x40;
      }
      uVar1 = param_3[1];
      *param_7 = *param_3;
      param_7[1] = uVar1;
      uVar1 = param_3[3];
      param_7[2] = param_3[2];
      param_7[3] = uVar1;
      uVar1 = param_3[5];
      param_7[4] = param_3[4];
      param_7[5] = uVar1;
      param_7[6] = param_3[6];
      if (*(uint *)((longlong)param_3 + 0x44) == param_5) {
        uVar4 = *(uint *)(param_3 + 7) & 0xffffe9ff;
        if (uVar4 == 0) {
          uVar4 = 0x80;
        }
      }
      else if (((((param_6 & 0xfff0000) == 0) && (2 < param_6)) &&
               ((param_6 & 0xc0000000) != 0x40000000)) &&
              (((param_6 & 0x30000000) != 0x30000000 &&
               (*(uint *)((longlong)param_3 + 0x44) == param_6)))) {
        uVar4 = *(uint *)(param_3 + 7) & 0xffffe9ff;
        if (uVar4 == 0) {
          uVar4 = 0x80;
        }
      }
      else {
        uVar4 = *(uint *)(param_3 + 7);
      }
      *(uint *)(param_7 + 7) = uVar4;
      if (param_4 == '\0') {
        *(uint *)(param_7 + 7) = *(uint *)(param_7 + 7) & 0xffffbfff;
      }
      *(undefined4 *)((longlong)param_7 + 0x3c) = *(undefined4 *)((longlong)param_3 + 0x3c);
      memmove(param_7 + 8,param_3 + 10,(ulonglong)uVar2);
      *(undefined4 *)param_7 = 0;
      *param_9 = param_7;
      uVar2 = uVar2 + 0x40;
      uVar5 = 0;
      if (uVar2 < uVar6 + 0x40) {
        uVar5 = 0x80000005;
      }
    }
    goto LAB_140017edd;
  }
  if (param_1 == 2) {
    uVar4 = *(uint *)((longlong)param_3 + 0x3c);
    uVar6 = uVar4 + 0x44;
    if ((param_8 < uVar6) && ((param_8 < 0x44 || (param_2 == '\0')))) goto LAB_140017edd;
    if (param_8 - 0x44 <= uVar4) {
      uVar4 = param_8 - 0x44;
    }
    uVar1 = param_3[1];
    *param_7 = *param_3;
    param_7[1] = uVar1;
    uVar1 = param_3[3];
    param_7[2] = param_3[2];
    param_7[3] = uVar1;
    uVar1 = param_3[5];
    param_7[4] = param_3[4];
    param_7[5] = uVar1;
    param_7[6] = param_3[6];
    if (*(uint *)((longlong)param_3 + 0x44) == param_5) {
      uVar2 = *(uint *)(param_3 + 7) & 0xffffe9ff;
      if (uVar2 == 0) {
        uVar2 = 0x80;
      }
LAB_140017cb9:
      *(uint *)(param_7 + 7) = uVar2;
LAB_140017cbf:
      uVar3 = *(undefined4 *)(param_3 + 8);
    }
    else {
      if (((((param_6 & 0xfff0000) == 0) && (2 < param_6)) && ((param_6 & 0xc0000000) != 0x40000000)
          ) && (((param_6 & 0x30000000) != 0x30000000 &&
                (*(uint *)((longlong)param_3 + 0x44) == param_6)))) {
        uVar2 = *(uint *)(param_3 + 7) & 0xffffe9ff;
        if (uVar2 == 0) {
          uVar2 = 0x80;
        }
        goto LAB_140017cb9;
      }
      *(undefined4 *)(param_7 + 7) = *(undefined4 *)(param_3 + 7);
      if ((*(uint *)(param_3 + 7) & 0x400) == 0) goto LAB_140017cbf;
      uVar3 = *(undefined4 *)((longlong)param_3 + 0x44);
    }
    *(undefined4 *)(param_7 + 8) = uVar3;
    if (param_4 == '\0') {
      *(uint *)(param_7 + 7) = *(uint *)(param_7 + 7) & 0xffffbfff;
    }
    *(undefined4 *)((longlong)param_7 + 0x3c) = *(undefined4 *)((longlong)param_3 + 0x3c);
    memmove((void *)((longlong)param_7 + 0x44),param_3 + 10,(ulonglong)uVar4);
    uVar2 = uVar4 + 0x44;
LAB_140017a27:
    bVar7 = uVar2 < uVar6;
  }
  else {
    if (param_1 != 0xc) {
      if (param_1 == 0x26) {
        uVar4 = *(uint *)((longlong)param_3 + 0x3c);
        uVar6 = uVar4 + 0x50;
        if ((param_8 < uVar6) && ((param_8 < 0x50 || (param_2 == '\0')))) goto LAB_140017edd;
        if (param_8 - 0x50 <= uVar4) {
          uVar4 = param_8 - 0x50;
        }
        uVar1 = param_3[1];
        *param_7 = *param_3;
        param_7[1] = uVar1;
        uVar1 = param_3[3];
        param_7[2] = param_3[2];
        param_7[3] = uVar1;
        uVar1 = param_3[5];
        param_7[4] = param_3[4];
        param_7[5] = uVar1;
        param_7[6] = param_3[6];
        if (*(uint *)((longlong)param_3 + 0x44) == param_5) {
          uVar2 = *(uint *)(param_3 + 7) & 0xffffe9ff;
          if (uVar2 == 0) {
            uVar2 = 0x80;
          }
LAB_140017aca:
          *(uint *)(param_7 + 7) = uVar2;
LAB_140017ad0:
          uVar3 = *(undefined4 *)(param_3 + 8);
        }
        else {
          if (((((param_6 & 0xfff0000) == 0) && (2 < param_6)) &&
              ((param_6 & 0xc0000000) != 0x40000000)) &&
             (((param_6 & 0x30000000) != 0x30000000 &&
              (*(uint *)((longlong)param_3 + 0x44) == param_6)))) {
            uVar2 = *(uint *)(param_3 + 7) & 0xffffe9ff;
            if (uVar2 == 0) {
              uVar2 = 0x80;
            }
            goto LAB_140017aca;
          }
          *(undefined4 *)(param_7 + 7) = *(undefined4 *)(param_3 + 7);
          if ((*(uint *)(param_3 + 7) & 0x400) == 0) goto LAB_140017ad0;
          uVar3 = *(undefined4 *)((longlong)param_3 + 0x44);
        }
        *(undefined4 *)(param_7 + 8) = uVar3;
        if (param_4 == '\0') {
          *(uint *)(param_7 + 7) = *(uint *)(param_7 + 7) & 0xffffbfff;
        }
        param_7[9] = param_3[9];
        if (param_4 == '\0') {
          param_7[9] = 0xffffffffffffffff;
        }
        *(undefined4 *)((longlong)param_7 + 0x3c) = *(undefined4 *)((longlong)param_3 + 0x3c);
        memmove(param_7 + 10,param_3 + 10,(ulonglong)uVar4);
      }
      else {
        if (param_1 != 0x4e) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,0x12,0xd,
                                &WPP_795aeb0acc6f36f288a32122a031d179_Traceguids,
                                "onecore\\base\\fs\\wci\\wcifs\\dir.c",0x39,(char)param_1);
          }
          uVar5 = 0xc00000bb;
          uVar2 = 0;
          goto LAB_140017edd;
        }
        uVar4 = *(uint *)((longlong)param_3 + 0x3c);
        uVar6 = uVar4 + 0x50;
        if ((param_8 < uVar6) && ((param_8 < 0x50 || (param_2 == '\0')))) goto LAB_140017edd;
        if (param_8 - 0x50 <= uVar4) {
          uVar4 = param_8 - 0x50;
        }
        uVar1 = param_3[1];
        *param_7 = *param_3;
        param_7[1] = uVar1;
        uVar1 = param_3[3];
        param_7[2] = param_3[2];
        param_7[3] = uVar1;
        uVar1 = param_3[5];
        param_7[4] = param_3[4];
        param_7[5] = uVar1;
        uVar1 = param_3[7];
        param_7[6] = param_3[6];
        param_7[7] = uVar1;
        uVar1 = param_3[9];
        param_7[8] = param_3[8];
        param_7[9] = uVar1;
        if (*(uint *)((longlong)param_3 + 0x44) == param_5) {
          uVar2 = *(uint *)(param_3 + 7) & 0xffffe9ff;
          if (uVar2 == 0) {
            uVar2 = 0x80;
          }
LAB_1400179f4:
          *(uint *)(param_7 + 7) = uVar2;
          *(undefined4 *)((longlong)param_7 + 0x44) = 0;
        }
        else if (((((param_6 & 0xfff0000) == 0) && (2 < param_6)) &&
                 ((param_6 & 0xc0000000) != 0x40000000)) &&
                (((param_6 & 0x30000000) != 0x30000000 &&
                 (*(uint *)((longlong)param_3 + 0x44) == param_6)))) {
          uVar2 = *(uint *)(param_3 + 7) & 0xffffe9ff;
          if (uVar2 == 0) {
            uVar2 = 0x80;
          }
          goto LAB_1400179f4;
        }
        if (param_4 == '\0') {
          *(uint *)(param_7 + 7) = *(uint *)(param_7 + 7) & 0xffffbfff;
        }
        memmove(param_7 + 10,param_3 + 10,(ulonglong)uVar4);
        if (param_4 == '\0') {
          param_7[9] = 0xffffffffffffffff;
        }
      }
      uVar2 = uVar4 + 0x50;
      goto LAB_140017a27;
    }
    uVar6 = *(uint *)((longlong)param_3 + 0x3c);
    if ((param_8 < uVar6 + 0xc) && ((param_8 < 0xc || (param_2 == '\0')))) goto LAB_140017edd;
    uVar2 = uVar6;
    if (param_8 - 0xc <= uVar6) {
      uVar2 = param_8 - 0xc;
    }
    *(undefined4 *)((longlong)param_7 + 4) = *(undefined4 *)((longlong)param_3 + 4);
    *(undefined4 *)(param_7 + 1) = *(undefined4 *)((longlong)param_3 + 0x3c);
    memmove((void *)((longlong)param_7 + 0xc),param_3 + 10,(ulonglong)uVar2);
    uVar2 = uVar2 + 0xc;
    bVar7 = uVar2 < uVar6 + 0xc;
  }
  *(undefined4 *)param_7 = 0;
  *param_9 = param_7;
  if (bVar7) {
    uVar5 = 0x80000005;
  }
LAB_140017edd:
  *param_10 = uVar2;
  return uVar5;
}



===== WcMungeDirectoryEnumerateWithoutShortnameFileIdAll @ 140017f1c =====

undefined4
WcMungeDirectoryEnumerateWithoutShortnameFileIdAll
          (int param_1,char param_2,undefined8 *param_3,char param_4,uint param_5,uint param_6,
          undefined8 *param_7,uint param_8,undefined8 *param_9,uint *param_10)

{
  uint uVar1;
  undefined8 uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  uVar4 = 0;
  if (param_1 != 0x50) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,0x12,0x12,
                          &WPP_795aeb0acc6f36f288a32122a031d179_Traceguids,
                          "onecore\\base\\fs\\wci\\wcifs\\dir.c",0xc1,(char)param_1);
    }
    uVar5 = 0xc00000bb;
    goto LAB_14001810c;
  }
  uVar1 = *(uint *)((longlong)param_3 + 0x3c);
  if ((param_8 < uVar1 + 0x60) && ((param_8 < 0x60 || (param_2 == '\0')))) goto LAB_14001810c;
  uVar4 = uVar1;
  if (param_8 - 0x60 <= uVar1) {
    uVar4 = param_8 - 0x60;
  }
  uVar2 = param_3[1];
  *param_7 = *param_3;
  param_7[1] = uVar2;
  uVar2 = param_3[3];
  param_7[2] = param_3[2];
  param_7[3] = uVar2;
  uVar2 = param_3[5];
  param_7[4] = param_3[4];
  param_7[5] = uVar2;
  uVar2 = param_3[7];
  param_7[6] = param_3[6];
  param_7[7] = uVar2;
  uVar2 = param_3[9];
  param_7[8] = param_3[8];
  param_7[9] = uVar2;
  uVar2 = param_3[0xb];
  param_7[10] = param_3[10];
  param_7[0xb] = uVar2;
  if (*(uint *)((longlong)param_3 + 0x44) == param_5) {
    uVar3 = *(uint *)(param_3 + 7) & 0xffffe9ff;
    if (uVar3 == 0) {
      uVar3 = 0x80;
    }
LAB_1400180ab:
    *(uint *)(param_7 + 7) = uVar3;
    *(undefined4 *)((longlong)param_7 + 0x44) = 0;
  }
  else if (((((param_6 & 0xfff0000) == 0) && (2 < param_6)) &&
           ((param_6 & 0xc0000000) != 0x40000000)) &&
          (((param_6 & 0x30000000) != 0x30000000 && (*(uint *)((longlong)param_3 + 0x44) == param_6)
           ))) {
    uVar3 = *(uint *)(param_3 + 7) & 0xffffe9ff;
    if (uVar3 == 0) {
      uVar3 = 0x80;
    }
    goto LAB_1400180ab;
  }
  if (param_4 == '\0') {
    *(uint *)(param_7 + 7) = *(uint *)(param_7 + 7) & 0xffffbfff;
  }
  memmove(param_7 + 0xc,param_3 + 0xc,(ulonglong)uVar4);
  if (param_4 == '\0') {
    param_7[9] = 0xffffffffffffffff;
    param_7[10] = 0xffffffffffffffff;
    param_7[0xb] = 0xffffffffffffffff;
  }
  *(undefined4 *)param_7 = 0;
  *param_9 = param_7;
  uVar4 = uVar4 + 0x60;
  uVar5 = 0;
  if (uVar4 < uVar1 + 0x60) {
    uVar5 = 0x80000005;
  }
LAB_14001810c:
  *param_10 = uVar4;
  return uVar5;
}



===== WcMungeReparseEnumerate @ 140018148 =====

undefined8
WcMungeReparseEnumerate
          (int param_1,undefined8 *param_2,undefined8 *param_3,uint param_4,undefined4 *param_5)

{
  undefined8 uVar1;
  
  if (param_1 == 0x21) {
    if (param_4 < 0x10) {
      *param_5 = 0;
    }
    else {
      uVar1 = param_2[1];
      *param_3 = *param_2;
      param_3[1] = uVar1;
      *param_5 = 0x10;
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 0xc00000bb;
  }
  return uVar1;
}



===== WcCopyStreamData @ 14001819c =====

int WcCopyStreamData(undefined8 param_1,undefined8 param_2,longlong param_3,undefined8 param_4,
                    undefined8 param_5,char param_6)

{
  int iVar1;
  longlong lVar2;
  uint uVar3;
  undefined2 uVar4;
  longlong lVar5;
  uint local_res18 [2];
  undefined1 uVar6;
  undefined4 local_48 [2];
  longlong local_40;
  
  uVar3 = 0x1000000;
  local_res18[0] = 0;
  local_48[0] = 0;
  iVar1 = 0;
  if (param_3 < 0x1000000) {
    uVar3 = (int)param_3 + 0xfffU & 0xfffff000;
  }
  lVar2 = FltAllocatePoolAlignedWithTag(param_4,0x200,uVar3,0x62654357);
  if (lVar2 == 0) {
    iVar1 = -0x3fffff66;
  }
  else {
    local_40 = 0;
    for (lVar5 = param_3; lVar5 != 0; lVar5 = lVar5 - (ulonglong)local_res18[0]) {
      iVar1 = FltReadFile(param_1,param_2,&local_40,uVar3,lVar2,5 - (uint)(param_6 != '\0'),
                          local_res18,0,0);
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400183c2;
        uVar4 = 0xd;
        uVar6 = 0xe;
        param_5 = param_2;
        goto LAB_140018392;
      }
      iVar1 = FltWriteFile(param_4,param_5,&local_40,local_res18[0],lVar2,5,local_48,0,0);
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400183c2;
        uVar4 = 0xe;
        uVar6 = 0x2a;
        goto LAB_140018392;
      }
      local_40 = local_40 + (ulonglong)local_res18[0];
    }
    if (param_3 < 0x1000) {
      iVar1 = FltFlushBuffers(param_4,param_5);
      if ((iVar1 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        uVar4 = 0xf;
        uVar6 = 0x42;
LAB_140018392:
        WPP_RECORDER_SF_sDqd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,10,uVar4,
                   &WPP_258dc4bb20423ae59ba1107eb987efad_Traceguids,
                   "onecore\\base\\fs\\wci\\wcifs\\expansion.c",uVar6,(char)param_5,(char)iVar1);
      }
    }
LAB_1400183c2:
    FltFreePoolAlignedWithTag(param_4,lVar2,0x62654357);
  }
  return iVar1;
}



===== WcCreateExpansionContext @ 1400183fc =====

int WcCreateExpansionContext
              (undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 *param_4)

{
  longlong *plVar1;
  undefined4 *puVar2;
  longlong lVar3;
  int iVar4;
  undefined4 *puVar5;
  
  puVar5 = (undefined4 *)ExAllocateFromNPagedLookasideList(&DAT_14000f580);
  if (puVar5 == (undefined4 *)0x0) {
    iVar4 = -0x3fffff66;
  }
  else {
    iVar4 = FltCbdqInitialize(param_1,puVar5 + 10,WcExpansionCsqInsertIo,WcExpansionCsqRemoveIo,
                              WcExpansionCsqPeekNextIo,WcExpansionCsqAcquireLock,
                              WcExpansionCsqReleaseLock,WcExpansionCsqCompleteCanceledIo);
    if (iVar4 < 0) {
      ExFreeToNPagedLookasideList(&DAT_14000f580,puVar5);
    }
    else {
      puVar2 = puVar5 + 0x2a;
      *(undefined4 **)(puVar5 + 0x2c) = puVar2;
      *(undefined4 **)puVar2 = puVar2;
      KeInitializeEvent(puVar5 + 2,0,1);
      *(undefined8 *)(puVar5 + 0x30) = 0;
      puVar5[0x32] = 0;
      puVar5[0x2e] = 1;
      KeInitializeEvent(puVar5 + 0x34,1);
      *puVar5 = 0;
      puVar5[8] = 0;
      *(undefined8 *)(puVar5 + 0x3c) = param_3;
      puVar5[0x3f] = *(undefined4 *)(param_2 + 0x38);
      LOCK();
      plVar1 = (longlong *)(param_2 + 0x30);
      lVar3 = *plVar1;
      *plVar1 = *plVar1 + 1;
      UNLOCK();
      *param_4 = puVar5;
      *(longlong *)(puVar5 + 0x40) = lVar3 + 1;
      puVar5[0x3e] = 0;
    }
  }
  return iVar4;
}



===== WcExpandAndPend @ 140018570 =====

int WcExpandAndPend(longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4,
                   int param_5,int param_6)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = 0;
  bVar1 = WcIsExpanded(param_4);
  if ((bVar1 == 0) &&
     (iVar2 = WcLaunchExpansion(param_2,param_3,param_4,param_1,param_5,param_6), -1 < iVar2)) {
    iVar2 = 0x103;
  }
  return iVar2;
}



===== WcExpandDirectory @ 1400185f4 =====

ulonglong WcExpandDirectory(longlong param_1,longlong param_2,ulonglong param_3,longlong *param_4)

{
  uint *puVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  char local_res18 [8];
  longlong local_58;
  longlong local_50;
  longlong local_48;
  ulonglong local_40;
  longlong lStack_38;
  wchar_t local_30 [12];
  
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_res18[0] = '\0';
  local_30[0] = L'\0';
  local_30[1] = L'\0';
  local_30[2] = L'\0';
  local_30[3] = L'\0';
  local_30[4] = L'\0';
  local_30[5] = L'\0';
  local_30[6] = L'\0';
  local_30[7] = L'\0';
  lStack_38 = *(longlong *)(*(longlong *)(param_3 + 0x20) + 0x40);
  uVar2 = *(undefined2 *)(lStack_38 + 0x20);
  local_40 = (ulonglong)CONCAT22(uVar2,uVar2);
  lStack_38 = lStack_38 + 0x22;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sDZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,10,0x10,
                        &WPP_258dc4bb20423ae59ba1107eb987efad_Traceguids,
                        "onecore\\base\\fs\\wci\\wcifs\\expansion.c",0x7c,(wchar_t *)&local_40);
  }
  RtlInitUnicodeString(local_30,0);
  uVar5 = WcRelativeStreamOpen(param_1,param_2,local_30,&local_58,&local_50);
  uVar7 = uVar5 & 0xffffffff;
  if ((int)uVar5 < 0) goto LAB_140018847;
  uVar3 = WcPopulateDirectory((longlong *)(param_3 + 0x38),
                              *(undefined4 **)(*(longlong *)(param_3 + 0x20) + 0x40),local_58,
                              local_50,param_1,local_res18,&local_48);
  uVar7 = (ulonglong)uVar3;
  if ((int)uVar3 < 0) goto LAB_140018847;
  if (local_res18[0] == '\0') {
    puVar6 = (undefined8 *)WcGetSource(param_3);
    iVar4 = WcCopyFileMetaData(puVar6[1],puVar6[2],*puVar6,local_58,param_2,param_1,4);
    if ((iVar4 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_sDZd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,10,0x11,
                 &WPP_258dc4bb20423ae59ba1107eb987efad_Traceguids,
                 "onecore\\base\\fs\\wci\\wcifs\\expansion.c",0xc3,(wchar_t *)&local_40,(char)iVar4)
      ;
    }
    uVar3 = WcSetPlaceHolderFlags(param_1,param_2,*(longlong *)(param_3 + 0x20),4);
    uVar7 = (ulonglong)uVar3;
    if (-1 < (int)uVar3) {
      ExAcquireFastMutex(*(longlong *)(param_3 + 0x20) + 8);
      puVar1 = (uint *)(*(longlong *)(param_3 + 0x20) + 0x58);
      *puVar1 = *puVar1 | 1;
      goto LAB_140018827;
    }
  }
  else {
    uVar3 = WcUntagFile(param_1,param_2,param_3);
    uVar7 = (ulonglong)uVar3;
    if (-1 < (int)uVar3) {
      ExAcquireFastMutex(*(longlong *)(param_3 + 0x20) + 8);
      puVar1 = (uint *)(*(longlong *)(param_3 + 0x20) + 0x58);
      *puVar1 = *puVar1 | 1;
      puVar1 = (uint *)(*(longlong *)(param_3 + 0x20) + 0x58);
      *puVar1 = *puVar1 & 0xfffffffd;
LAB_140018827:
      ExReleaseFastMutex(*(longlong *)(param_3 + 0x20) + 8);
    }
  }
  if (param_4 != (longlong *)0x0) {
    *param_4 = local_48;
  }
LAB_140018847:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sDZd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,10,0x12,
               &WPP_258dc4bb20423ae59ba1107eb987efad_Traceguids,
               "onecore\\base\\fs\\wci\\wcifs\\expansion.c",0xdd,(wchar_t *)&local_40,(char)uVar7);
  }
  if (local_58 != 0) {
    FltClose();
  }
  if (local_50 != 0) {
    ObfDereferenceObject();
  }
  return uVar7;
}



===== WcExpandFile @ 1400188f0 =====

int WcExpandFile(longlong param_1,longlong param_2,ulonglong param_3,longlong *param_4)

{
  int *piVar1;
  int iVar2;
  char extraout_var;
  undefined8 *puVar3;
  char cVar4;
  longlong *plVar5;
  longlong lVar6;
  bool bVar7;
  
  lVar6 = 0;
  cVar4 = '\0';
  bVar7 = *(char *)(param_2 + 0x4b) == '\0';
  if (bVar7) {
    *(undefined1 *)(param_2 + 0x4b) = 1;
  }
  WcSuppressTimestamps(param_1,param_2,'\x01');
  if ((**(uint **)(*(longlong *)(param_3 + 0x20) + 0x50) & 2) == 0) {
    puVar3 = (undefined8 *)WcGetSource(param_3);
    lVar6 = *(longlong *)(param_3 + 0x48);
    if (((*(uint *)(*(longlong *)(param_3 + 0x28) + 0x20) & 4) == 0) &&
       (*(int *)(*(longlong *)(param_3 + 0x28) + 0x1c) == 1)) {
      cVar4 = '\x01';
    }
    iVar2 = WcCopyStreamData(*puVar3,puVar3[2],lVar6,param_1,param_2,cVar4);
    if (iVar2 < 0) goto LAB_140018a1c;
  }
  plVar5 = (longlong *)(param_3 + 0x20);
  iVar2 = WcUntagFile(param_1,param_2,param_3);
  if (-1 < iVar2) {
    ExAcquireFastMutex(*(longlong *)(param_3 + 0x20) + 8);
    *(uint *)(*plVar5 + 0x58) = *(uint *)(*plVar5 + 0x58) | 1;
    *(uint *)(*plVar5 + 0x58) = *(uint *)(*plVar5 + 0x58) & 0xfffffffd;
    ExReleaseFastMutex(*plVar5 + 8);
  }
  if (-1 < extraout_var) {
    WcSuppressTimestamps(param_1,param_2,'\0');
  }
  if (DAT_14000f680 != '\0') {
    LOCK();
    piVar1 = (int *)(*(longlong *)(*(longlong *)*plVar5 + 0x20) + 8);
    *piVar1 = *piVar1 + 1;
    UNLOCK();
  }
  if (param_4 != (longlong *)0x0) {
    *param_4 = lVar6;
  }
LAB_140018a1c:
  if (bVar7) {
    *(undefined1 *)(param_2 + 0x4b) = 0;
  }
  return iVar2;
}



===== WcExpansionCsqAcquireLock @ 140018a50 =====

void WcExpansionCsqAcquireLock(longlong param_1,undefined1 *param_2)

{
  ExAcquireFastMutex(param_1 + 0x90);
  *param_2 = 0;
  return;
}



===== WcExpansionCsqCompleteCanceledIo @ 140018a80 =====

void WcExpansionCsqCompleteCanceledIo(undefined8 param_1,uint *param_2)

{
  if ((*param_2 & 0x80000) == 0) {
    param_2[8] = 0;
    param_2[9] = 0;
    param_2[6] = 0xc0000120;
    FltCompletePendedPreOperation(param_2,4,0,param_2);
  }
  else {
    FltCompletePendedPostOperation();
  }
  return;
}



===== WcExpansionCsqInsertIo @ 140018ad0 =====

ulonglong WcExpansionCsqInsertIo(longlong param_1,longlong param_2,longlong param_3)

{
  ulonglong uVar1;
  
  if (param_3 == 0) {
    uVar1 = 0xc000000d;
  }
  else {
    uVar1 = WcScheduleExpansionWorkItem
                      (*(undefined8 *)**(undefined8 **)(param_1 + 200),param_3,param_1 + -0x28,
                       param_2);
  }
  return uVar1;
}



===== WcExpansionCsqPeekNextIo @ 140018b10 =====

undefined8 * WcExpansionCsqPeekNextIo(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  if (param_2 == 0) {
    puVar2 = *(undefined8 **)(param_1 + 0x80);
  }
  else {
    puVar2 = *(undefined8 **)(param_2 + 0x30);
  }
  puVar1 = puVar2 + -6;
  if (puVar2 == (undefined8 *)(param_1 + 0x80)) {
    puVar1 = (undefined8 *)0x0;
  }
  return puVar1;
}



===== WcExpansionCsqReleaseLock @ 140018b40 =====

void WcExpansionCsqReleaseLock(longlong param_1)

{
  ExReleaseFastMutex(param_1 + 0x90);
  return;
}



===== WcExpansionCsqRemoveIo @ 140018b70 =====

void WcExpansionCsqRemoveIo(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  longlong *plVar4;
  
  plVar4 = (longlong *)(param_2 + 0x30);
  lVar1 = *plVar4;
  if ((*(longlong **)(lVar1 + 8) == plVar4) &&
     (plVar2 = *(longlong **)(param_2 + 0x38), (longlong *)*plVar2 == plVar4)) {
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    return;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== WcExpansionWorker @ 140018ba0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WcExpansionWorker(undefined8 param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  ulonglong uVar5;
  int *piVar6;
  longlong lVar7;
  longlong lVar8;
  uint *puVar9;
  uint unaff_ESI;
  uint uVar10;
  undefined1 auStackY_118 [32];
  byte local_c8;
  int local_c4;
  ulonglong local_c0;
  longlong local_b8;
  uint local_b0;
  int local_ac;
  uint local_a8;
  longlong local_a0;
  undefined4 local_98;
  ulonglong local_90;
  longlong local_88;
  longlong local_80;
  undefined8 local_78;
  longlong local_70;
  int *local_68;
  longlong local_60;
  longlong local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_118;
  local_c0 = 0;
  uVar10 = unaff_ESI & 0xffffff00;
  local_88 = 0;
  local_68 = (int *)0x0;
  uVar3 = 0;
  local_a0 = 0;
  local_b8 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_78 = 0;
  local_98 = 1;
  local_70 = 0;
  local_90 = 0;
  local_60 = 0;
  local_c4 = 0;
  local_c8 = 0;
  local_80 = 0;
  local_a8 = 0;
  local_ac = 0;
  local_b0 = uVar10;
  local_58 = param_3;
  FltFreeGenericWorkItem();
  WcGetContextFileObject(param_2,param_3,&local_88,&local_c0);
  lVar1 = local_88;
  bVar2 = WcIsExpanded(local_88);
  if (bVar2 != 0) {
    local_c8 = 1;
    goto LAB_140018e12;
  }
  uVar5 = WcIsPlaceHolderStream(lVar1,local_c0);
  if ((char)uVar5 == '\0') {
    uVar5 = WcIsPlaceHolderDirectory(lVar1,local_c0);
    if ((char)uVar5 != '\0') goto LAB_140018d5f;
    bVar2 = WcIsPlaceHolder(lVar1);
    if (bVar2 == 0) goto LAB_140018d5f;
    piVar6 = (int *)WcGetUnionContext(0,param_2,param_3);
    local_68 = piVar6;
    if ((piVar6 == (int *)0x0) &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,10,0x13,
                          &WPP_258dc4bb20423ae59ba1107eb987efad_Traceguids,
                          "onecore\\base\\fs\\wci\\wcifs\\expansion.c",0xb7,0);
    }
    uVar5 = WcOpenDefaultStream(param_2,param_3,piVar6,&local_a0,&local_b8);
    param_3 = local_b8;
    uVar3 = (uint)uVar5;
    if (-1 < (int)(uint)uVar5) {
      uVar3 = FltGetStreamContext(param_2,local_b8,&local_c0);
      if ((int)uVar3 < 0) {
        FltClose(local_a0);
        local_a0 = 0;
        ObfDereferenceObject(param_3);
        param_3 = 0;
        local_b8 = 0;
      }
    }
  }
  else {
LAB_140018d5f:
    uVar3 = 0;
    local_b8 = param_3;
  }
  if (param_3 != 0) {
    local_a8 = *(uint *)(*(longlong *)(local_c0 + 0x28) + 0x1c);
    local_ac = *(int *)(*(longlong *)(local_c0 + 0x28) + 0x20);
    lVar7 = KeQueryPerformanceCounter(&local_80);
    ExWaitForRundownProtectionRelease(lVar1 + 0x48);
    ExRundownCompleted(lVar1 + 0x48);
    if ((*(uint *)(local_c0 + 0x18) & 0x10) == 0) {
      uVar3 = WcExpandFile(param_2,param_3,local_c0,(longlong *)&local_90);
      local_c4 = 1;
    }
    else {
      uVar5 = WcExpandDirectory(param_2,param_3,local_c0,(longlong *)&local_90);
      uVar3 = (uint)uVar5;
      local_c4 = 2;
    }
    lVar8 = KeQueryPerformanceCounter(0);
    local_70 = ((lVar8 - lVar7) * 1000) / local_80;
  }
  uVar10 = local_b0;
LAB_140018e12:
  lVar7 = local_60;
  do {
    while( true ) {
      LOCK();
      *(undefined4 *)(*(longlong *)(lVar1 + 0x50) + 0x20) = 1;
      UNLOCK();
      puVar9 = (uint *)FltCbdqRemoveNextIo(*(longlong *)(lVar1 + 0x50) + 0x28,0);
      if (puVar9 == (uint *)0x0) break;
      iVar4 = FltPropagateActivityIdToThread(puVar9);
      uVar10 = uVar10 & 0xff;
      if (-1 < iVar4) {
        uVar10 = 1;
      }
      if ((*puVar9 & 0x80000) == 0) {
        if ((int)uVar3 < 0) {
          puVar9[6] = uVar3;
        }
        FltCompletePendedPreOperation(puVar9);
      }
      else {
        if (((int)uVar3 < 0) && (*(char *)(*(longlong *)(puVar9 + 4) + 4) == '\0')) {
          FltCancelFileOpen(param_2);
          puVar9[8] = 0;
          puVar9[9] = 0;
          puVar9[6] = uVar3;
        }
        FltCompletePendedPostOperation(puVar9);
      }
      if ((char)uVar10 != '\0') {
        IoClearActivityIdThread(local_78);
      }
      lVar7 = lVar7 + 1;
    }
    LOCK();
    piVar6 = (int *)(*(longlong *)(lVar1 + 0x50) + 0x20);
    iVar4 = *piVar6;
    *piVar6 = *piVar6 + -1;
    UNLOCK();
  } while (iVar4 != 1);
  KeSetEvent(*(longlong *)(lVar1 + 0x50) + 8,0,0);
  lVar8 = local_58;
  WcTelemetryPostExpansionComplete
            ((char)local_58,local_c8,local_c4,*(longlong *)(lVar1 + 0x50),uVar3,lVar7,local_90,
             local_70,local_a8,local_ac);
  piVar6 = local_68;
  if (local_c0 != 0) {
    FltReleaseContext();
  }
  FltReleaseContext(local_88);
  if (lVar8 != 0) {
    ObfDereferenceObject(lVar8);
  }
  if (local_a0 != 0) {
    FltClose();
    ObfDereferenceObject(local_b8);
  }
  if (piVar6 != (int *)0x0) {
    WcReleaseUnionContext(piVar6);
  }
  return;
}



===== WcLaunchExpansion @ 14001900c =====

int WcLaunchExpansion(undefined8 param_1,undefined8 param_2,longlong param_3,longlong param_4,
                     int param_5,int param_6)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  ulonglong uVar4;
  int iVar5;
  byte bVar6;
  byte bVar7;
  bool bVar8;
  longlong local_res18;
  
  piVar3 = (int *)0x0;
  iVar5 = 0;
  bVar7 = 0;
  bVar6 = 0;
  if (*(longlong *)(param_3 + 0x50) == 0) {
    local_res18 = 0;
    piVar3 = (int *)WcGetUnionContext(param_4,param_1,param_2);
    if (piVar3 == (int *)0x0) {
      iVar2 = -0x3fffffff;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0x14,
                           &WPP_258dc4bb20423ae59ba1107eb987efad_Traceguids,
                           "onecore\\base\\fs\\wci\\wcifs\\expansion.c",0xb0);
      }
      goto LAB_140019204;
    }
    if (piVar3[6] == 2) {
      iVar2 = -0x3fffffff;
      bVar6 = bVar7;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0x15,
                           &WPP_258dc4bb20423ae59ba1107eb987efad_Traceguids,
                           "onecore\\base\\fs\\wci\\wcifs\\expansion.c",0xbd);
      }
    }
    else {
      iVar2 = WcCreateExpansionContext(param_1,(longlong)piVar3,param_3,&local_res18);
      bVar6 = bVar7;
      if (-1 < iVar2) {
        LOCK();
        bVar8 = *(longlong *)(param_3 + 0x50) == 0;
        if (bVar8) {
          *(longlong *)(param_3 + 0x50) = local_res18;
        }
        UNLOCK();
        if (!bVar8) {
          ExFreeToNPagedLookasideList(&DAT_14000f580,local_res18);
        }
        goto LAB_140019164;
      }
    }
  }
  else {
LAB_140019164:
    if (param_6 == 0x13) {
      **(uint **)(param_3 + 0x50) = **(uint **)(param_3 + 0x50) | 2;
    }
    if (param_4 == 0) {
      ExAcquireFastMutex(*(longlong *)(param_3 + 0x50) + 0xb8);
      uVar4 = WcScheduleExpansionWorkItem(param_1,param_2,*(longlong *)(param_3 + 0x50),0);
      iVar2 = (int)uVar4;
      ExReleaseFastMutex(*(longlong *)(param_3 + 0x50) + 0xb8);
      bVar6 = bVar7;
      if (-1 < iVar2) goto LAB_1400191e4;
    }
    else {
      iVar2 = FltCbdqInsertIo(*(longlong *)(param_3 + 0x50) + 0x28,param_4,0,param_2);
      bVar6 = bVar7;
      if (-1 < iVar2) {
        bVar7 = 1;
LAB_1400191e4:
        LOCK();
        piVar1 = (int *)(*(longlong *)(param_3 + 0x50) + 0xf8);
        iVar5 = *piVar1;
        *piVar1 = *piVar1 + 1;
        UNLOCK();
        iVar5 = iVar5 + 1;
        bVar6 = bVar7;
      }
    }
    if (piVar3 == (int *)0x0) goto LAB_140019204;
  }
  WcReleaseUnionContext(piVar3);
LAB_140019204:
  WcTelemetryPostExpansionTrigger
            ((char)param_2,param_5,param_6,*(longlong *)(param_3 + 0x50),iVar5,iVar2,bVar6);
  return iVar2;
}



===== WcPopulateDirectory @ 140019254 =====

int WcPopulateDirectory(longlong *param_1,undefined4 *param_2,longlong param_3,longlong param_4,
                       longlong param_5,undefined1 *param_6,longlong *param_7)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  uint *puVar4;
  ulonglong uVar5;
  undefined1 uVar6;
  longlong lVar7;
  uint *puVar8;
  undefined1 uVar9;
  undefined4 local_58 [2];
  wchar_t local_50 [4];
  uint *puStack_48;
  
  local_50[0] = L'\0';
  local_50[1] = L'\0';
  local_50[2] = L'\0';
  local_50[3] = L'\0';
  puStack_48 = (uint *)0x0;
  uVar9 = 1;
  lVar7 = 0;
  puVar4 = (uint *)ExAllocatePool2(0x100,0x10000,0x65644357);
  if (puVar4 == (uint *)0x0) {
    iVar3 = -0x3fffff66;
  }
  else {
    uVar6 = 1;
    RtlInitUnicodeString(local_50,L"*");
    lVar1 = *param_1;
    while( true ) {
      iVar3 = WcEnumerateDirectory
                        (**(undefined8 **)(lVar1 + 0x18),(*(undefined8 **)(lVar1 + 0x18))[2],0xc,
                         local_50,0,uVar6,0x10000,puVar4,local_58);
      if (iVar3 < 0) break;
      puVar8 = puVar4;
      while( true ) {
        puStack_48 = puVar8 + 3;
        local_50[1] = (short)puVar8[2];
        local_50[0] = (short)puVar8[2];
        cVar2 = RtlEqualUnicodeString(local_50,&DAT_14000a470,1);
        if (cVar2 == '\0') {
          cVar2 = RtlEqualUnicodeString(local_50,&DAT_14000a480,1);
          if (cVar2 == '\0') {
            uVar5 = WcPopulateFile(local_50,param_1,param_2,param_5,param_3,param_4,'\0','\0');
            iVar3 = 0;
            if ((int)uVar5 != -0x3ffffdd3) {
              iVar3 = (int)uVar5;
            }
            if (iVar3 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_sDZd
                          (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0x19,
                           &WPP_258dc4bb20423ae59ba1107eb987efad_Traceguids,
                           "onecore\\base\\fs\\wci\\wcifs\\expansion.c",0x62,local_50,(char)iVar3);
              }
              goto LAB_1400194a4;
            }
            uVar9 = 0;
            lVar7 = lVar7 + 1;
          }
        }
        if (*puVar8 == 0) break;
        puVar8 = (uint *)((longlong)puVar8 + (ulonglong)*puVar8);
      }
      uVar6 = 0;
    }
    if (iVar3 == -0x7ffffffa) {
      iVar3 = 0;
      *param_6 = uVar9;
      if (param_7 != (longlong *)0x0) {
        *param_7 = lVar7;
      }
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0x18,
                          &WPP_258dc4bb20423ae59ba1107eb987efad_Traceguids,
                          "onecore\\base\\fs\\wci\\wcifs\\expansion.c",0x2a,(char)iVar3);
    }
LAB_1400194a4:
    ExFreePoolWithTag(puVar4,0x65644357);
  }
  return iVar3;
}



===== WcPreCreateExpansion @ 1400194dc =====

ulonglong WcPreCreateExpansion(longlong param_1,longlong param_2,undefined4 param_3,uint param_4)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  longlong lVar9;
  longlong lVar10;
  undefined2 uVar11;
  wchar_t *pwVar12;
  longlong lVar13;
  uint local_res20 [2];
  longlong *plVar14;
  undefined1 uVar15;
  longlong local_80;
  longlong local_78;
  undefined4 local_70 [2];
  longlong local_68;
  wchar_t local_60 [4];
  longlong lStack_58;
  longlong local_50;
  longlong local_48;
  int *local_40;
  
  local_78 = 0;
  lVar13 = 0;
  cVar1 = *(char *)(*(longlong *)(param_1 + 0x10) + 0x23);
  lVar10 = 0;
  uVar6 = *(uint *)(*(longlong *)(param_1 + 0x10) + 0x20);
  lVar9 = 0;
  local_48 = 0;
  local_50 = 0;
  local_res20[0] = param_4 & 0xffffff00;
  local_60[0] = L'\0';
  local_60[1] = L'\0';
  local_60[2] = L'\0';
  local_60[3] = L'\0';
  lStack_58 = 0;
  local_70[0] = 0;
  local_40 = (int *)0x0;
  local_68 = 0;
  local_80 = 0;
  RtlInitUnicodeString(local_60);
  if ((uVar6 >> 0xd & 1) == 0) {
    uVar3 = FltGetFileNameInformation(param_1,0x102,&local_78);
    uVar8 = (ulonglong)uVar3;
    if ((int)uVar3 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400197e9;
      uVar11 = 0x26;
      uVar15 = 0x8d;
    }
    else {
      uVar3 = FltParseFileNameInformation(local_78);
      uVar8 = (ulonglong)uVar3;
      if (-1 < (int)uVar3) {
        uVar3 = WcPrePopulatePath(param_1,param_2,param_3,local_78);
        uVar8 = (ulonglong)uVar3;
        if ((int)uVar3 < 0) {
          if ((uVar3 == 0xc0000034) || (uVar3 == 0xc000003a)) {
            uVar8 = 0;
          }
          else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sDZd
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0x28,
                       &WPP_258dc4bb20423ae59ba1107eb987efad_Traceguids,
                       "onecore\\base\\fs\\wci\\wcifs\\expansion.c",0xaa,(wchar_t *)(local_78 + 8),
                       (char)uVar3);
          }
          goto LAB_1400197e9;
        }
        pwVar12 = (wchar_t *)(local_78 + 8);
        goto LAB_14001978f;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400197e9;
      uVar11 = 0x27;
      uVar15 = 0x95;
    }
    WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,uVar11,
                        &WPP_258dc4bb20423ae59ba1107eb987efad_Traceguids,
                        "onecore\\base\\fs\\wci\\wcifs\\expansion.c",uVar15,(char)uVar3);
    goto LAB_1400197e9;
  }
  iVar4 = FltGetVolumeName(*(undefined8 *)(param_2 + 0x10),0,local_70);
  if (iVar4 != -0x3fffffdd) {
    uVar8 = 0xc0000010;
    goto LAB_1400197e9;
  }
  uVar3 = RtlUShortAdd((ushort)local_70[0],2,(ushort *)(local_60 + 1));
  uVar8 = (ulonglong)uVar3;
  if ((int)uVar3 < 0) goto LAB_1400197e9;
  uVar3 = RtlUShortAdd(local_60[1],8,(ushort *)(local_60 + 1));
  uVar8 = (ulonglong)uVar3;
  if ((int)uVar3 < 0) goto LAB_1400197e9;
  uVar7 = WcAllocateUnicodeString(0x6e664357,local_60);
  uVar8 = uVar7 & 0xffffffff;
  if ((int)uVar7 < 0) goto LAB_1400197e9;
  uVar3 = FltGetVolumeName(*(undefined8 *)(param_2 + 0x10),local_60,0);
  uVar8 = (ulonglong)uVar3;
  if ((int)uVar3 < 0) goto LAB_1400197e9;
  uVar3 = RtlAppendUnicodeToString(local_60,L"\\");
  uVar8 = (ulonglong)uVar3;
  if ((int)uVar3 < 0) goto LAB_1400197e9;
  uVar3 = RtlAppendUnicodeStringToString(local_60,*(longlong *)(param_2 + 0x20) + 0x58);
  uVar8 = (ulonglong)uVar3;
  if ((int)uVar3 < 0) goto LAB_1400197e9;
  pwVar12 = local_60;
LAB_14001978f:
  if (cVar1 == '\x02') goto LAB_1400197e9;
  plVar14 = &local_48;
  uVar3 = WcOpenPlaceHolder(*(undefined8 *)(param_2 + 0x18),pwVar12,uVar6 & 0x2041 | 0x28,param_3,
                            plVar14,&local_50,(byte *)local_res20);
  lVar13 = local_50;
  if ((int)uVar3 < 0) {
    uVar5 = 0;
    if (uVar3 != 0xc0000279) {
      uVar5 = uVar3;
    }
  }
  else {
    uVar5 = uVar3;
    if ((char)local_res20[0] != '\0') {
      local_40 = (int *)WcGetUnionContext(0,*(undefined8 *)(param_2 + 0x18),local_50);
      if (local_40 == (int *)0x0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0x29,
                             &WPP_258dc4bb20423ae59ba1107eb987efad_Traceguids,
                             "onecore\\base\\fs\\wci\\wcifs\\expansion.c",0x11);
        }
        uVar8 = 0xc0000001;
        goto LAB_1400197e9;
      }
      uVar6 = WcGetSetContextFileObject
                        (*(undefined8 *)(param_2 + 0x18),lVar13,local_40,uVar6 & 0x41,plVar14,
                         &local_68,&local_80);
      lVar10 = local_68;
      uVar8 = (ulonglong)uVar6;
      if ((int)uVar6 < 0) {
        if (uVar6 == 0xc0000275) goto LAB_140019a3c;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDdZ
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0x2a,
                     &WPP_258dc4bb20423ae59ba1107eb987efad_Traceguids,
                     "onecore\\base\\fs\\wci\\wcifs\\expansion.c",0x2d,(char)uVar6,pwVar12);
        }
      }
      else {
        if (uVar6 != 0x104) {
          bVar2 = WcIsExpanded(local_68);
          lVar9 = local_80;
          if (bVar2 == 0) {
            uVar7 = WcIsPlaceHolderDirectory(lVar10,local_80);
            if (((char)uVar7 == '\0') || (uVar7 = WcIsSourcedStream(lVar9), (char)uVar7 == '\0')) {
              uVar7 = WcIsPlaceHolderStream(lVar10,lVar9);
              if ((char)uVar7 == '\0') goto LAB_1400197e9;
              iVar4 = 1;
            }
            else {
              iVar4 = 2;
            }
            uVar6 = WcExpandAndWait(param_1,*(undefined8 *)(param_2 + 0x18),lVar13,lVar10,iVar4,0x11
                                   );
            uVar8 = (ulonglong)uVar6;
          }
          goto LAB_1400197e9;
        }
LAB_140019a3c:
        uVar8 = 0;
      }
      lVar9 = local_80;
      lVar10 = local_68;
      goto LAB_1400197e9;
    }
  }
  uVar8 = (ulonglong)uVar5;
LAB_1400197e9:
  if (local_78 != 0) {
    FltReleaseFileNameInformation();
  }
  if (lStack_58 != 0) {
    ExFreePoolWithTag(lStack_58,0x6e664357);
  }
  if (local_48 != 0) {
    FltClose();
  }
  if (lVar13 != 0) {
    ObfDereferenceObject(lVar13);
  }
  if (lVar10 != 0) {
    FltReleaseContext(lVar10);
  }
  if (lVar9 != 0) {
    FltReleaseContext(lVar9);
  }
  if (local_40 != (int *)0x0) {
    WcReleaseUnionContext(local_40);
  }
  return uVar8;
}



===== WcPrePopulatePath @ 140019a48 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int WcPrePopulatePath(longlong param_1,longlong param_2,undefined4 param_3,longlong param_4)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  undefined1 auStackY_108 [32];
  char local_b8 [4];
  int local_b4 [3];
  longlong local_a8;
  longlong local_a0;
  longlong local_98;
  undefined8 ****local_90;
  undefined8 ****ppppuStack_88;
  undefined8 ****local_80;
  undefined8 ****ppppuStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStackY_108;
  local_b8[0] = '\0';
  local_80 = (undefined8 ****)0x0;
  ppppuStack_78 = (undefined8 ****)0x0;
  local_a8 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_a0 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_b4[0] = 0;
  local_90 = (undefined8 ****)0x0;
  ppppuStack_88 = (undefined8 ****)0x0;
  local_98 = 0;
  local_b4[1] = 0;
  iVar2 = 0;
  uVar1 = *(uint *)(*(longlong *)(param_1 + 0x10) + 0x20);
  while (local_b8[0] == '\0') {
    local_80 = &local_90;
    ppppuStack_78 = &local_90;
    local_90 = &local_80;
    local_70 = CONCAT44(0x80000004,param_3);
    ppppuStack_88 = &local_80;
    uStack_58 = CONCAT44(uStack_58._4_4_,0x30);
    uStack_68 = 0;
    local_60 = 0;
    iVar2 = WcOpenReparsePoint(*(undefined8 *)(param_2 + 0x18),param_4 + 8,0,0,0x80,
                               uVar1 & 0x41 | 0x28,7,(longlong *)&local_90,&local_a8,&local_a0);
    if (((local_70 & 0x100000000) == 0) || (iVar2 != -0x3ffffd87)) break;
    uVar3 = WcProcessWciReparsePointBounce
                      (param_1,*(longlong *)(param_2 + 0x18),param_3,param_4,uStack_58._2_2_,
                       (uint *)(local_b4 + 1),local_b8,local_b4,&local_98);
    iVar2 = (int)uVar3;
    if (iVar2 < 0) break;
  }
  if (local_a8 != 0) {
    FltClose();
  }
  if (local_a0 != 0) {
    ObfDereferenceObject();
  }
  if (local_98 != 0) {
    ObfDereferenceObject();
  }
  return iVar2;
}



===== WcScheduleExpansionWorkItem @ 140019c08 =====

ulonglong WcScheduleExpansionWorkItem
                    (undefined8 param_1,undefined8 param_2,longlong param_3,longlong param_4)

{
  longlong *plVar1;
  int *piVar2;
  longlong *plVar3;
  int iVar4;
  longlong *plVar5;
  longlong *plVar6;
  undefined8 *puVar7;
  code *pcVar8;
  bool bVar9;
  uint uVar10;
  longlong lVar11;
  ulonglong uVar12;
  
  uVar12 = 0;
  plVar3 = (longlong *)(param_3 + 0xa8);
  bVar9 = false;
  plVar5 = (longlong *)*plVar3;
  if (param_4 != 0) {
    plVar6 = *(longlong **)(param_3 + 0xb0);
    plVar1 = (longlong *)(param_4 + 0x30);
    if ((longlong *)*plVar6 != plVar3) goto LAB_140019d68;
    *plVar1 = (longlong)plVar3;
    *(longlong **)(param_4 + 0x38) = plVar6;
    *plVar6 = (longlong)plVar1;
    *(longlong **)(param_3 + 0xb0) = plVar1;
  }
  if (plVar5 == plVar3) {
    LOCK();
    piVar2 = (int *)(param_3 + 0x20);
    iVar4 = *piVar2;
    *piVar2 = *piVar2 + 1;
    UNLOCK();
    if (iVar4 == 0) {
      KeWaitForSingleObject(param_3 + 8,0,0,0,0);
      KeClearEvent(param_3 + 8);
      lVar11 = FltAllocateGenericWorkItem();
      if (lVar11 == 0) {
        uVar12 = 0xc000009a;
      }
      else {
        ObfReferenceObject(param_2);
        uVar10 = FltQueueGenericWorkItem(lVar11,param_1,WcExpansionWorker,0,param_2);
        uVar12 = (ulonglong)uVar10;
        if (-1 < (int)uVar10) {
          return uVar12;
        }
        FltFreeGenericWorkItem(lVar11);
        bVar9 = true;
      }
      if (param_4 != 0) {
        puVar7 = *(undefined8 **)(param_3 + 0xb0);
        if (((longlong *)*puVar7 != plVar3) ||
           (plVar5 = (longlong *)puVar7[1], (undefined8 *)*plVar5 != puVar7)) {
LAB_140019d68:
          pcVar8 = (code *)swi(0x29);
          (*pcVar8)(3);
          pcVar8 = (code *)swi(3);
          uVar12 = (*pcVar8)();
          return uVar12;
        }
        *(longlong **)(param_3 + 0xb0) = plVar5;
        *plVar5 = (longlong)plVar3;
      }
      LOCK();
      *(int *)(param_3 + 0x20) = *(int *)(param_3 + 0x20) + -1;
      UNLOCK();
      if (bVar9) {
        ObfDereferenceObject(param_2);
      }
    }
  }
  return uVar12;
}



===== WcSynchronizeExpansionPostOp @ 140019d78 =====

undefined8 WcSynchronizeExpansionPostOp(longlong param_1)

{
  if (param_1 != 0) {
    ExReleaseRundownProtection(param_1 + 0x48);
    FltReleaseContext(param_1);
  }
  return 0;
}



===== WcUntagFile @ 140019db4 =====

int WcUntagFile(longlong param_1,longlong param_2,ulonglong param_3)

{
  longlong lVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined2 uVar5;
  bool bVar6;
  undefined1 local_res10 [8];
  undefined4 in_stack_ffffffffffffffb8;
  undefined4 in_stack_ffffffffffffffbc;
  undefined8 in_stack_ffffffffffffffc0;
  undefined1 uVar7;
  
  bVar6 = *(char *)(param_2 + 0x4b) == '\0';
  if (bVar6) {
    *(undefined1 *)(param_2 + 0x4b) = 1;
  }
  lVar1 = *(longlong *)(param_3 + 0x20);
  local_res10[0] = 0;
  uVar3 = WcIsPlaceHolderStream(lVar1,param_3);
  if (((char)uVar3 == '\0') || ((**(uint **)(lVar1 + 0x50) & 1) != 0)) {
LAB_140019e7f:
    lVar4 = param_1;
    iVar2 = WcClearOfflineAttribute(param_2,param_1);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140019f33;
      uVar5 = 0xb;
      uVar7 = 0x8e;
    }
    else {
      param_3 = (ulonglong)**(uint **)(lVar1 + 0x40);
      lVar4 = param_2;
      iVar2 = FltUntagFile(param_1,param_2,param_3,0);
      if (-1 < iVar2) goto LAB_140019f33;
      if (iVar2 == -0x3ffffd8b) {
        iVar2 = 0;
        goto LAB_140019f33;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140019f33;
      uVar5 = 0xc;
      uVar7 = 0xb6;
    }
  }
  else {
    param_3 = 0x900c4;
    in_stack_ffffffffffffffc0 = 0;
    in_stack_ffffffffffffffb8 = 1;
    lVar4 = param_2;
    iVar2 = FltFsControlFile(param_1,param_2,0x900c4,local_res10,1,0,0,0);
    if (-1 < iVar2) {
      **(uint **)(lVar1 + 0x50) = **(uint **)(lVar1 + 0x50) | 1;
      goto LAB_140019e7f;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140019f33;
    uVar5 = 10;
    uVar7 = 0x77;
  }
  WPP_RECORDER_SF_sDqZd
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar4,param_3,uVar5,
             CONCAT44(in_stack_ffffffffffffffbc,in_stack_ffffffffffffffb8),in_stack_ffffffffffffffc0
             ,uVar7,(char)param_2,(wchar_t *)(param_2 + 0x58),(char)iVar2);
LAB_140019f33:
  if (bVar6) {
    *(undefined1 *)(param_2 + 0x4b) = 0;
  }
  return iVar2;
}



===== WcPostQueryInformation @ 140019f60 =====

undefined8 WcPostQueryInformation(longlong param_1,longlong param_2)

{
  int iVar1;
  byte bVar2;
  ulonglong uVar3;
  uint uVar4;
  longlong lVar5;
  ulonglong *puVar6;
  longlong lVar7;
  longlong *plVar8;
  uint uVar9;
  longlong local_30;
  longlong *local_28 [2];
  
  lVar5 = 0;
  local_30 = 0;
  plVar8 = (longlong *)0x0;
  local_28[0] = (longlong *)0x0;
  if (((*(int *)(param_1 + 0x18) + 0x80000000U & 0x80000000) == 0) &&
     (*(int *)(param_1 + 0x18) != -0x7ffffffb)) goto LAB_14001a2c9;
  iVar1 = *(int *)(*(longlong *)(param_1 + 0x10) + 0x20);
  puVar6 = *(ulonglong **)(*(longlong *)(param_1 + 0x10) + 0x28);
  WcGetContextFileObject
            (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),local_28,&local_30);
  plVar8 = local_28[0];
  lVar5 = local_30;
  uVar3 = WcIsPlaceHolderStream((longlong)local_28[0],local_30);
  if (((char)uVar3 == '\0') &&
     (((uVar3 = WcIsPlaceHolderDirectory((longlong)plVar8,lVar5), (char)uVar3 == '\0' &&
       (bVar2 = WcIsPlaceHolder((longlong)plVar8), bVar2 == 0)) &&
      (uVar3 = WcUsesSourceSectionObjectPointers(*(longlong *)(param_2 + 0x20),lVar5),
      (char)uVar3 == '\0')))) goto LAB_14001a2c9;
  if (iVar1 == 0x16) {
    if (lVar5 == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,0xd,0x18,
                           &WPP_62cdeb337fdf307834c1a2cccb2efbc6_Traceguids,
                           "onecore\\base\\fs\\wci\\wcifs\\fileinfo.c",0x13);
      }
    }
    else {
      do {
        if (((*(uint *)((longlong)puVar6 + 4) == 0xe) && (puVar6[3] == 0x440024003a003a)) &&
           (((uint)puVar6[4] == 0x540041 && (*(short *)((longlong)puVar6 + 0x24) == 0x41)))) {
          puVar6[2] = *(longlong *)(lVar5 + 0x48) + -1 + (ulonglong)*(uint *)(*plVar8 + 0xc) &
                      -(ulonglong)*(uint *)(*plVar8 + 0xc);
        }
        if ((uint)*puVar6 == 0) {
          puVar6 = (ulonglong *)0x0;
        }
        else {
          puVar6 = (ulonglong *)((longlong)puVar6 + (ulonglong)(uint)*puVar6);
        }
      } while (puVar6 != (ulonglong *)0x0);
    }
    goto LAB_14001a2c9;
  }
  if (iVar1 == 0x1c) goto LAB_14001a2c9;
  if (iVar1 == 5) {
    if (lVar5 != 0) {
      *puVar6 = *(longlong *)(lVar5 + 0x48) + -1 + (ulonglong)*(uint *)(*plVar8 + 0xc) &
                ~((ulonglong)*(uint *)(*plVar8 + 0xc) - 1);
    }
    goto LAB_14001a2c9;
  }
  lVar7 = 0;
  uVar9 = 0;
  if (iVar1 == 4) {
LAB_14001a1d6:
    lVar7 = 0x20;
  }
  else {
    if (iVar1 == 0x12) {
      if (lVar5 != 0) {
        puVar6[5] = *(longlong *)(lVar5 + 0x48) + -1 + (ulonglong)*(uint *)(*plVar8 + 0xc) &
                    -(ulonglong)*(uint *)(*plVar8 + 0xc);
      }
      goto LAB_14001a1d6;
    }
    if (iVar1 == 0x22) {
      lVar7 = 0x30;
    }
    else if (iVar1 == 0x23) {
      uVar9 = 4;
    }
    else if (((iVar1 == 0x44) || (iVar1 == 0x46)) || (iVar1 == 0x4d)) {
      lVar7 = 0x38;
      uVar9 = 0x3c;
    }
  }
  if ((*(int *)(param_1 + 0x18) != -0x7ffffffb) ||
     (lVar7 + 4U <= (ulonglong)*(uint *)(*(longlong *)(param_1 + 0x10) + 0x18))) {
    uVar3 = WcIsPlaceHolderStream((longlong)plVar8,lVar5);
    uVar4 = *(uint *)(lVar7 + (longlong)puVar6) & 0xffffebff;
    if ((char)uVar3 != '\0') {
      uVar4 = *(uint *)(lVar7 + (longlong)puVar6) & 0xffffe9ff;
    }
    if (uVar4 == 0) {
      uVar4 = 0x80;
    }
    *(uint *)(lVar7 + (longlong)puVar6) = uVar4;
  }
  if ((uVar9 != 0) &&
     ((*(int *)(param_1 + 0x18) != -0x7ffffffb ||
      (uVar9 + 4 <= *(uint *)(*(longlong *)(param_1 + 0x10) + 0x18))))) {
    *(undefined4 *)((ulonglong)uVar9 + (longlong)puVar6) = 0;
  }
LAB_14001a2c9:
  if (plVar8 != (longlong *)0x0) {
    FltReleaseContext(plVar8);
  }
  if (lVar5 != 0) {
    FltReleaseContext(lVar5);
  }
  return 0;
}



===== WcPreQueryQuota @ 14001a320 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 WcPreQueryQuota(longlong param_1,longlong param_2)

{
  bool bVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined1 auStackY_a8 [32];
  undefined1 local_68 [8];
  undefined8 local_60;
  undefined8 local_58 [4];
  undefined1 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  uVar3 = 1;
  if ((DAT_14000f6a1 == '\0') && (*(char *)(param_1 + 0x50) == '\x01')) {
    bVar1 = WcIsSiloFileObject(*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20));
    if (bVar1) {
      if (5 < DAT_14000f060) {
        uVar2 = _tlgKeywordOn(0x14000f060,0x400000000000);
        if ((char)uVar2 != '\0') {
          local_2c = 0;
          local_38 = local_68;
          local_1c = 0;
          local_28 = &local_60;
          local_68[0] = 2;
          local_30 = 1;
          local_60 = 0x19;
          local_20 = 8;
          _tlgWriteTransfer_EtwWriteTransfer(0x14000f060,&DAT_14000b758,0,0,4,local_58);
        }
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,7,0x1c,
                           &WPP_62cdeb337fdf307834c1a2cccb2efbc6_Traceguids,
                           "onecore\\base\\fs\\wci\\wcifs\\fileinfo.c",0xfa);
      }
      *(undefined8 *)(param_1 + 0x20) = 0;
      uVar3 = 4;
      *(undefined4 *)(param_1 + 0x18) = 0xc00000bb;
    }
  }
  return uVar3;
}



===== WcPreSetQuota @ 14001a490 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 WcPreSetQuota(longlong param_1,longlong param_2)

{
  bool bVar1;
  ulonglong uVar2;
  undefined4 uVar3;
  undefined1 auStackY_a8 [32];
  undefined1 local_68 [8];
  undefined8 local_60;
  undefined8 local_58 [4];
  undefined1 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  uVar3 = 1;
  if ((DAT_14000f6a1 == '\0') && (*(char *)(param_1 + 0x50) == '\x01')) {
    bVar1 = WcIsSiloFileObject(*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20));
    if ((!bVar1) &&
       (bVar1 = WcUnionExistsForFileObject
                          (param_1,*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20)),
       !bVar1)) {
      return 1;
    }
    if ((5 < DAT_14000f060) &&
       (uVar2 = _tlgKeywordOn(0x14000f060,0x400000000000), (char)uVar2 != '\0')) {
      local_2c = 0;
      local_38 = local_68;
      local_1c = 0;
      local_28 = &local_60;
      local_68[0] = 2;
      local_30 = 1;
      local_60 = 0x1a;
      local_20 = 8;
      _tlgWriteTransfer_EtwWriteTransfer(0x14000f060,&DAT_14000b5fe,0,0,4,local_58);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,7,0x1b,
                         &WPP_62cdeb337fdf307834c1a2cccb2efbc6_Traceguids,
                         "onecore\\base\\fs\\wci\\wcifs\\fileinfo.c",0xcf);
    }
    *(undefined8 *)(param_1 + 0x20) = 0;
    uVar3 = 4;
    *(undefined4 *)(param_1 + 0x18) = 0xc00000bb;
  }
  return uVar3;
}



===== WcFailFsctlIfPlaceHolderStream @ 14001a61c =====

undefined8 WcFailFsctlIfPlaceHolderStream(longlong param_1,longlong param_2)

{
  bool bVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong local_res10;
  longlong local_res18 [2];
  
  local_res10 = 0;
  local_res18[0] = 0;
  uVar4 = 1;
  bVar1 = WcGetContextFileObject
                    (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),local_res18,
                     &local_res10);
  if (bVar1) {
    lVar3 = local_res10;
    uVar2 = WcIsPlaceHolderStream(local_res18[0],local_res10);
    if ((char)uVar2 != '\0') {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDDd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar3,7,0x12,
                   &WPP_6905edae906b30b18cb12ec0224aaf5b_Traceguids,
                   "onecore\\base\\fs\\wci\\wcifs\\fsctrl.c",0x3a,
                   (char)*(undefined4 *)(*(longlong *)(param_1 + 0x10) + 0x28),0xbb);
      }
      *(undefined8 *)(param_1 + 0x20) = 0;
      *(undefined4 *)(param_1 + 0x18) = 0xc00000bb;
      uVar4 = 4;
    }
  }
  if (local_res18[0] != 0) {
    FltReleaseContext(local_res18[0]);
  }
  if (local_res10 != 0) {
    FltReleaseContext(local_res10);
  }
  return uVar4;
}



===== WcFsctlManageBypassIo @ 14001a720 =====

undefined8 WcFsctlManageBypassIo(longlong param_1,longlong param_2)

{
  int iVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  longlong local_res8;
  
  local_res8 = 0;
  uVar3 = 1;
  if ((0x17 < *(uint *)(*(longlong *)(param_1 + 0x10) + 0x20)) &&
     ((**(int **)(*(longlong *)(param_1 + 0x10) + 0x30) - 1U & 0xfffffffd) == 0)) {
    iVar1 = FltGetStreamContext(*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),
                                &local_res8);
    if (-1 < iVar1) {
      uVar2 = WcIsPlaceHolderStream(*(longlong *)(local_res8 + 0x20),local_res8);
      if ((char)uVar2 != '\0') {
        iVar1 = FltVetoBypassIo(param_1,param_2,0xc00004d0,&bypassVetoReason);
        uVar3 = 4;
        *(int *)(param_1 + 0x18) = iVar1;
        *(ulonglong *)(param_1 + 0x20) = ((longlong)iVar1 >> 0x3f & 0xfffffffffffffea0U) + 0x160;
      }
      FltReleaseContext(local_res8);
    }
  }
  return uVar3;
}



===== WcPostFsControl @ 14001a800 =====

ulonglong WcPostFsControl(longlong param_1,longlong param_2,longlong param_3)

{
  ulonglong uVar1;
  
  uVar1 = 0;
  if (*(int *)(*(longlong *)(param_1 + 0x10) + 0x28) == 0x90020) {
    WcPostDismountVolume(param_1,param_2);
  }
  else {
    uVar1 = WcSynchronizeExpansionPostOp(param_3);
    uVar1 = uVar1 & 0xffffffff;
  }
  return uVar1;
}



===== WcPreDismountLockRemove @ 14001a838 =====

undefined8 WcPreDismountLockRemove(longlong param_1,longlong param_2)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  bool bVar4;
  longlong local_res18;
  
  uVar3 = 1;
  local_res18 = 0;
  FltGetInstanceContext(*(undefined8 *)(param_2 + 0x18),&local_res18);
  if (*(int *)(local_res18 + 0x14) == 0) {
    LOCK();
    bVar4 = *(int *)(local_res18 + 0x18) == 0;
    if (bVar4) {
      *(int *)(local_res18 + 0x18) = 0;
    }
    UNLOCK();
    if (bVar4) {
      uVar2 = PsGetCurrentSilo();
      cVar1 = PsIsHostSilo(uVar2);
      if ((cVar1 != '\0') ||
         (uVar2 = WcUnionsExistForInstance
                            (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),
                             (undefined4 *)0x0,(undefined4 *)0x0), (char)uVar2 == '\0'))
      goto LAB_14001a8d3;
    }
  }
  uVar3 = 4;
  *(undefined4 *)(param_1 + 0x18) = 0xc0000022;
LAB_14001a8d3:
  FltReleaseContext(local_res18);
  return uVar3;
}



===== WcPreFsctlFindFilesBySid @ 14001a904 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 WcPreFsctlFindFilesBySid(longlong param_1,longlong param_2)

{
  uint uVar1;
  bool bVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined1 auStackY_a8 [32];
  undefined1 local_68 [8];
  ulonglong local_60;
  undefined8 local_58 [4];
  undefined1 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  uVar4 = 1;
  uVar1 = *(uint *)(*(longlong *)(param_1 + 0x10) + 0x28);
  bVar2 = WcUnionExistsForFileObject
                    (param_1,*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20));
  if (bVar2) {
    if (5 < DAT_14000f060) {
      uVar3 = _tlgKeywordOn(0x14000f060,0x400000000000);
      if ((char)uVar3 != '\0') {
        local_2c = 0;
        local_38 = local_68;
        local_1c = 0;
        local_28 = &local_60;
        local_68[0] = 3;
        local_30 = 1;
        local_20 = 8;
        local_60 = (ulonglong)uVar1;
        _tlgWriteTransfer_EtwWriteTransfer(0x14000f060,&DAT_14000b798,0,0,4,local_58);
      }
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,7,0x11,
                          &WPP_6905edae906b30b18cb12ec0224aaf5b_Traceguids,
                          "onecore\\base\\fs\\wci\\wcifs\\fsctrl.c",0x6f,(char)uVar1);
    }
    *(undefined8 *)(param_1 + 0x20) = 0;
    uVar4 = 4;
    *(undefined4 *)(param_1 + 0x18) = 0xc00000bb;
  }
  return uVar4;
}



===== WcPreGetUnions @ 14001aa6c =====

undefined8 WcPreGetUnions(longlong param_1)

{
  longlong lVar1;
  uint *_Dst;
  void *_Src;
  char cVar2;
  uint uVar3;
  undefined8 uVar4;
  void *_Dst_00;
  ulonglong uVar5;
  byte bVar6;
  int iVar7;
  uint uVar8;
  undefined2 uVar9;
  uint local_res10 [2];
  void *local_res18;
  void *local_res20;
  undefined1 uVar10;
  uint uVar11;
  
  iVar7 = 0;
  _Dst_00 = (void *)0x0;
  uVar8 = 0;
  local_res10[0] = 0;
  lVar1 = *(longlong *)(param_1 + 0x10);
  uVar3 = *(uint *)(lVar1 + 0x20);
  uVar5 = (ulonglong)uVar3;
  uVar11 = *(uint *)(lVar1 + 0x18);
  local_res18 = *(void **)(lVar1 + 0x30);
  _Dst = *(uint **)(lVar1 + 0x38);
  uVar4 = PsGetCurrentServerSilo();
  cVar2 = PsIsHostSilo(uVar4);
  if (cVar2 == '\0') {
    if (uVar3 < 0x18) {
      iVar7 = -0x3ffffff3;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001acc9;
      uVar9 = 0xb;
      uVar10 = 0x3c;
      uVar11 = uVar3;
    }
    else {
      if (0xb < uVar11) {
        _Dst_00 = (void *)ExAllocatePool2(0x100,uVar5,0x746d4357);
        local_res20 = _Dst_00;
        if (_Dst_00 != (void *)0x0) {
          cVar2 = ExGetPreviousMode();
          _Src = local_res18;
          if (cVar2 == '\x01') {
            ProbeForRead(local_res18,uVar5,1);
            ProbeForWrite(_Dst,(ulonglong)uVar11,1);
          }
          memmove(_Dst_00,_Src,uVar5);
          memset(_Dst,0,(ulonglong)uVar11);
          uVar3 = WcProcessGetUnions((longlong)_Dst_00 + 8,uVar11,(longlong)_Dst,local_res10);
          _Dst[1] = uVar3;
          *_Dst = local_res10[0];
          uVar8 = local_res10[0];
          goto LAB_14001acc9;
        }
        iVar7 = -0x3fffff66;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001acc9;
        uVar9 = 0xd;
        uVar10 = 0x4a;
        bVar6 = 2;
        goto LAB_14001aaf0;
      }
      iVar7 = -0x3ffffff3;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001acc9;
      uVar9 = 0xc;
      uVar10 = 0x42;
    }
    iVar7 = -0x3ffffff3;
    WPP_RECORDER_SF_sDdd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xe,uVar9,
               &WPP_6905edae906b30b18cb12ec0224aaf5b_Traceguids,
               "onecore\\base\\fs\\wci\\wcifs\\fsctrl.c",uVar10,(char)uVar11,0xc);
  }
  else {
    iVar7 = -0x3fffff45;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001acc9;
    uVar9 = 10;
    uVar10 = 0x36;
    bVar6 = 3;
    iVar7 = -0x3fffff45;
LAB_14001aaf0:
    WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar6,0xe,uVar9,
                       &WPP_6905edae906b30b18cb12ec0224aaf5b_Traceguids,
                       "onecore\\base\\fs\\wci\\wcifs\\fsctrl.c",uVar10);
  }
LAB_14001acc9:
  *(int *)(param_1 + 0x18) = iVar7;
  if (iVar7 < 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = (ulonglong)uVar8;
  }
  *(ulonglong *)(param_1 + 0x20) = uVar5;
  if (_Dst_00 != (void *)0x0) {
    ExFreePoolWithTag(_Dst_00,0x746d4357);
  }
  return 4;
}



===== WcCopyFileHandler @ 14001ad10 =====

ulonglong WcCopyFileHandler(int *param_1,uint param_2)

{
  ushort *puVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  char cVar6;
  uint uVar7;
  uint uVar8;
  uint extraout_EAX;
  uint uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  undefined8 *puVar12;
  undefined2 uVar13;
  ushort *puVar14;
  char local_res8 [8];
  char local_res10;
  byte local_res18 [8];
  byte local_res20 [8];
  undefined1 uVar15;
  undefined1 uVar16;
  byte local_e8;
  byte local_e7 [7];
  longlong local_e0;
  uint local_d8 [2];
  longlong local_d0;
  undefined8 local_c8;
  longlong local_c0;
  undefined8 local_b8;
  longlong local_b0;
  undefined8 *local_a8;
  longlong local_a0;
  longlong local_98;
  undefined8 local_90;
  int *piStack_88;
  undefined8 local_80;
  ushort *puStack_78;
  undefined8 local_70;
  ushort *puStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  
  local_a0 = 0;
  local_d0 = 0;
  uVar8 = param_1[1];
  local_b8 = 0;
  puVar12 = (undefined8 *)0x0;
  local_c8 = 0;
  cVar6 = '\0';
  local_e0 = 0;
  local_98 = 0;
  local_res20[0] = 0;
  local_res18[0] = 0;
  local_e8 = 0;
  local_res8[0] = '\0';
  local_e7[0] = 0;
  local_a8 = (undefined8 *)0x0;
  local_50 = 0;
  local_res10 = '\0';
  local_d8[0] = 0;
  local_b0 = 0;
  local_c0 = 0;
  local_80 = 0;
  puStack_78 = (ushort *)0x0;
  local_70 = 0;
  puStack_68 = (ushort *)0x0;
  local_90 = 0;
  piStack_88 = (int *)0x0;
  local_60 = 0;
  uStack_58 = 0;
  if (param_2 < uVar8) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000000d;
    }
    uVar13 = 0xc;
    uVar16 = 0xd1;
LAB_14001b674:
    uVar8 = 0xc000000d;
    uVar11 = 0xc000000d;
    uVar9 = 0xe;
  }
  else {
    if (*param_1 != 0x94) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0xc000000d;
      }
      uVar13 = 0xd;
      uVar16 = 0xd8;
      goto LAB_14001b674;
    }
    if (0x91 < uVar8) {
      uVar9 = param_1[0x1d];
      if (uVar9 < 0x92) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return 0xc000000d;
        }
        uVar13 = 0xf;
        uVar16 = 0xe4;
      }
      else {
        uVar3 = param_1[0x1f];
        if (uVar3 < 0x92) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return 0xc000000d;
          }
          uVar13 = 0x10;
          uVar16 = 0xea;
        }
        else {
          uVar4 = param_1[0x21];
          if (uVar4 < 0x92) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
              return 0xc000000d;
            }
            uVar13 = 0x11;
            uVar16 = 0xf0;
          }
          else {
            uVar5 = param_1[0x23];
            if (uVar5 < 0x92) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                return 0xc000000d;
              }
              uVar13 = 0x12;
              uVar16 = 0xf6;
            }
            else {
              uVar7 = uVar9 + *(ushort *)(param_1 + 0x1e);
              if ((uVar7 < uVar9) || (uVar8 < uVar7)) {
                if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                  return 0xc000000d;
                }
                uVar13 = 0x13;
                uVar16 = 0xfd;
              }
              else if ((*(ushort *)(param_1 + 0x20) + uVar3 < uVar3) ||
                      (uVar8 < *(ushort *)(param_1 + 0x20) + uVar3)) {
                if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                  return 0xc000000d;
                }
                uVar13 = 0x14;
                uVar16 = 4;
              }
              else if ((*(ushort *)(param_1 + 0x22) + uVar4 < uVar4) ||
                      (uVar8 < *(ushort *)(param_1 + 0x22) + uVar4)) {
                if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                  return 0xc000000d;
                }
                uVar13 = 0x15;
                uVar16 = 0xb;
              }
              else {
                if ((uVar5 <= *(ushort *)(param_1 + 0x24) + uVar5) &&
                   (*(ushort *)(param_1 + 0x24) + uVar5 <= uVar8)) {
                  uVar2 = *(ushort *)(param_1 + 0x1b);
                  if (100 < uVar2) {
                    uVar11 = 0xc000000d;
                    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                      return 0xc000000d;
                    }
                    uVar13 = 0x17;
                    uVar8 = 0xc000000d;
                    uVar16 = 0x18;
                    uVar9 = 0xb;
                    goto LAB_14001b67a;
                  }
                  puVar1 = (ushort *)((longlong)param_1 + (ulonglong)uVar9);
                  local_90 = (ulonglong)CONCAT22(uVar2,uVar2);
                  piStack_88 = param_1 + 2;
                  uVar10 = WcValidateContainerRootId(puVar1,(uint)*(ushort *)(param_1 + 0x1e));
                  uVar11 = uVar10 & 0xffffffff;
                  if ((int)uVar10 < 0) {
                    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                      uVar16 = (undefined1)uVar10;
                      uVar13 = 0x18;
                      uVar15 = 0x25;
LAB_14001b028:
                      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xe,uVar13,
                                          &WPP_52759b377eea39e2466a1234853e56fe_Traceguids,
                                          "onecore\\base\\fs\\wci\\wcifs\\message.c",uVar15,uVar16);
                    }
                  }
                  else {
                    puVar14 = (ushort *)((ulonglong)(uint)param_1[0x1f] + (longlong)param_1);
                    uVar10 = WcValidateContainerRootId(puVar14,(uint)*(ushort *)(param_1 + 0x20));
                    uVar11 = uVar10 & 0xffffffff;
                    if ((int)uVar10 < 0) {
                      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                        uVar16 = (undefined1)uVar10;
                        uVar13 = 0x19;
                        uVar15 = 0x2e;
                        goto LAB_14001b028;
                      }
                    }
                    else {
                      uVar8 = RtlUShortAdd(puVar1[2],(short)param_1[0x22],
                                           (ushort *)((longlong)&local_b8 + 2));
                      uVar11 = (ulonglong)uVar8;
                      if (-1 < (int)uVar8) {
                        uVar8 = RtlUShortAdd(2,local_b8._2_2_,(ushort *)((longlong)&local_b8 + 2));
                        uVar11 = (ulonglong)uVar8;
                        if (-1 < (int)uVar8) {
                          uVar13 = local_b8._2_2_;
                          local_b8 = local_b8 & 0xffffffffffff0000;
                          local_b0 = ExAllocatePool2(0x100,uVar13,0x746d4357);
                          if (local_b0 == 0) {
                            uVar11 = 0xc000009a;
                          }
                          else {
                            uVar8 = RtlUShortAdd(puVar14[2],(short)param_1[0x24],
                                                 (ushort *)((longlong)&local_c8 + 2));
                            uVar11 = (ulonglong)uVar8;
                            if (-1 < (int)uVar8) {
                              uVar8 = RtlUShortAdd(2,local_c8._2_2_,
                                                   (ushort *)((longlong)&local_c8 + 2));
                              uVar11 = (ulonglong)uVar8;
                              if (-1 < (int)uVar8) {
                                uVar13 = local_c8._2_2_;
                                local_c8 = local_c8 & 0xffffffffffff0000;
                                local_c0 = ExAllocatePool2(0x100,uVar13,0x746d4357);
                                if (local_c0 == 0) {
                                  uVar11 = 0xc000009a;
                                  if ((undefined **)WPP_RECORDER_INITIALIZED !=
                                      &WPP_RECORDER_INITIALIZED) {
                                    uVar16 = 0x9a;
                                    uVar13 = 0x1a;
                                    uVar15 = 0x5b;
                                    goto LAB_14001b028;
                                  }
                                }
                                else {
                                  uVar8 = WcRelPathToFullPath((ushort *)&local_b8,puVar1[2],
                                                              puVar1 + 3,
                                                              (void *)((ulonglong)
                                                                       (uint)param_1[0x21] +
                                                                      (longlong)param_1),
                                                              *(ushort *)(param_1 + 0x22));
                                  uVar11 = (ulonglong)uVar8;
                                  if ((int)uVar8 < 0) {
                                    if ((undefined **)WPP_RECORDER_INITIALIZED !=
                                        &WPP_RECORDER_INITIALIZED) {
                                      uVar16 = (undefined1)uVar8;
                                      uVar13 = 0x1b;
                                      uVar15 = 0x66;
                                      goto LAB_14001b028;
                                    }
                                  }
                                  else {
                                    uVar8 = WcRelPathToFullPath((ushort *)&local_c8,puVar14[2],
                                                                puVar14 + 3,
                                                                (void *)((ulonglong)
                                                                         (uint)param_1[0x23] +
                                                                        (longlong)param_1),
                                                                *(ushort *)(param_1 + 0x24));
                                    uVar11 = (ulonglong)uVar8;
                                    if ((int)uVar8 < 0) {
                                      if ((undefined **)WPP_RECORDER_INITIALIZED !=
                                          &WPP_RECORDER_INITIALIZED) {
                                        uVar16 = (undefined1)uVar8;
                                        uVar13 = 0x1c;
                                        uVar15 = 0x71;
                                        goto LAB_14001b028;
                                      }
                                    }
                                    else {
                                      local_80._0_4_ = CONCAT22(puVar1[1],puVar1[1]);
                                      local_70._0_4_ = CONCAT22(puVar14[1],puVar14[1]);
                                      puStack_78 = puVar1 + 3;
                                      puStack_68 = puVar14 + 3;
                                      uVar8 = WcGetInstanceFromVolumeName
                                                        (&local_80,&local_90,&local_e0);
                                      uVar11 = (ulonglong)uVar8;
                                      if ((int)uVar8 < 0) {
                                        if ((undefined **)WPP_RECORDER_INITIALIZED !=
                                            &WPP_RECORDER_INITIALIZED) {
                                          uVar16 = (undefined1)uVar8;
                                          uVar13 = 0x1d;
                                          uVar15 = 0x82;
                                          goto LAB_14001b028;
                                        }
                                      }
                                      else {
                                        uVar8 = WcGetInstanceFromVolumeName
                                                          (&local_70,&local_90,&local_98);
                                        uVar11 = (ulonglong)uVar8;
                                        if ((int)uVar8 < 0) {
                                          if ((undefined **)WPP_RECORDER_INITIALIZED !=
                                              &WPP_RECORDER_INITIALIZED) {
                                            uVar16 = (undefined1)uVar8;
                                            uVar13 = 0x1e;
                                            uVar15 = 0x8b;
                                            goto LAB_14001b028;
                                          }
                                        }
                                        else {
                                          WcOpenAsReparsePoint
                                                    (&local_b8,0,0,local_e0,0x80020000,param_1[0x1c]
                                                     ,&local_a0,&local_d0,local_res18,local_res20,
                                                     &local_e8,local_res8,local_e7);
                                          uVar11 = (ulonglong)extraout_EAX;
                                          if (-1 < (int)extraout_EAX) {
                                            if (local_res18[0] == 0) {
                                              if (local_res8[0] == '\0') {
                                                if (((local_res20[0] != 0) || (local_e8 != 0)) ||
                                                   (cVar6 = '\x01', local_e7[0] != 0)) {
                                                  cVar6 = '\0';
                                                }
                                                uVar8 = WcCopyFile(local_a0,local_d0,local_e0,
                                                                   (wchar_t *)&local_c8,local_98,0,0
                                                                   ,cVar6,0);
                                                uVar11 = (ulonglong)uVar8;
                                                if (((int)uVar8 < 0) &&
                                                   ((undefined **)WPP_RECORDER_INITIALIZED !=
                                                    &WPP_RECORDER_INITIALIZED)) {
                                                  uVar16 = (undefined1)uVar8;
                                                  uVar13 = 0x23;
                                                  uVar15 = 0xf7;
                                                  goto LAB_14001b028;
                                                }
                                                goto LAB_14001b058;
                                              }
LAB_14001b42b:
                                              cVar6 = '\x01';
                                              local_res10 = '\x01';
                                              puVar12 = &local_60;
                                              local_60 = CONCAT26(local_60._6_2_,0x80000020);
                                              uVar8 = 8;
LAB_14001b546:
                                              uVar8 = WcCopyAsPlaceHolder(local_a0,local_d0,local_e0
                                                                          ,(wchar_t *)&local_c8,
                                                                          local_98,0,0,
                                                                          (longlong)puVar12,uVar8,0)
                                              ;
                                              uVar11 = (ulonglong)uVar8;
                                              if (((int)uVar8 < 0) &&
                                                 ((undefined **)WPP_RECORDER_INITIALIZED !=
                                                  &WPP_RECORDER_INITIALIZED)) {
                                                uVar13 = 0x22;
                                                uVar16 = 0xe1;
                                                uVar9 = 0xf;
                                                goto LAB_14001b67a;
                                              }
                                            }
                                            else {
                                              if (local_res8[0] != '\0') goto LAB_14001b42b;
                                              uVar9 = WcGetReparseData(local_e0,local_d0,0x200,
                                                                       (longlong *)&local_a8,
                                                                       local_d8);
                                              puVar12 = local_a8;
                                              uVar8 = local_d8[0];
                                              uVar11 = (ulonglong)uVar9;
                                              if ((int)uVar9 < 0) {
                                                if ((undefined **)WPP_RECORDER_INITIALIZED !=
                                                    &WPP_RECORDER_INITIALIZED) {
                                                  WPP_RECORDER_SF_sDd(*(undefined8 *)
                                                                       (WPP_GLOBAL_Control + 0x40),2
                                                                      ,0xf,0x20,
                                                                      &
                                                  WPP_52759b377eea39e2466a1234853e56fe_Traceguids,
                                                  "onecore\\base\\fs\\wci\\wcifs\\message.c",0xbb,
                                                  (char)uVar9);
                                                }
                                                puVar12 = local_a8;
LAB_14001b4c7:
                                                cVar6 = '\0';
                                                goto LAB_14001b6a4;
                                              }
                                              uVar9 = WcValidateWcReparseInfo
                                                                ((longlong)local_a8,local_d8[0]);
                                              if (-1 < (int)uVar9) {
                                                *(uint *)((longlong)puVar12 + 0xc) =
                                                     *(uint *)((longlong)puVar12 + 0xc) & 0xfffffff1
                                                ;
                                                cVar6 = '\0';
                                                goto LAB_14001b546;
                                              }
                                              uVar11 = 0xc0000102;
                                              if ((undefined **)WPP_RECORDER_INITIALIZED !=
                                                  &WPP_RECORDER_INITIALIZED) {
                                                WPP_RECORDER_SF_sDd(*(undefined8 *)
                                                                     (WPP_GLOBAL_Control + 0x40),2,
                                                                    0xf,0x21,&
                                                  WPP_52759b377eea39e2466a1234853e56fe_Traceguids,
                                                  "onecore\\base\\fs\\wci\\wcifs\\message.c",0xcb,2)
                                                ;
                                                goto LAB_14001b4c7;
                                              }
                                            }
                                            cVar6 = local_res10;
                                            goto LAB_14001b6a4;
                                          }
                                          if ((undefined **)WPP_RECORDER_INITIALIZED !=
                                              &WPP_RECORDER_INITIALIZED) {
                                            uVar16 = (undefined1)extraout_EAX;
                                            uVar13 = 0x1f;
                                            uVar15 = 0x9e;
                                            goto LAB_14001b028;
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
                  }
LAB_14001b058:
                  cVar6 = '\0';
                  goto LAB_14001b6a4;
                }
                if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                  return 0xc000000d;
                }
                uVar13 = 0x16;
                uVar16 = 0x12;
              }
            }
          }
        }
      }
      goto LAB_14001b674;
    }
    uVar11 = 0xc000000d;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000000d;
    }
    uVar13 = 0xe;
    uVar8 = 0xc000000d;
    uVar9 = 0xe;
    uVar16 = 0xde;
  }
LAB_14001b67a:
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar9,uVar13,
                      &WPP_52759b377eea39e2466a1234853e56fe_Traceguids,
                      "onecore\\base\\fs\\wci\\wcifs\\message.c",uVar16,(char)uVar8);
LAB_14001b6a4:
  if (local_a0 != 0) {
    FltClose();
  }
  if (local_d0 != 0) {
    ObfDereferenceObject();
  }
  if (local_e0 != 0) {
    FltObjectDereference();
  }
  if (local_98 != 0) {
    FltObjectDereference();
  }
  if (local_b0 != 0) {
    ExFreePoolWithTag(local_b0,0x746d4357);
  }
  if (local_c0 != 0) {
    ExFreePoolWithTag(local_c0,0x746d4357);
  }
  if ((puVar12 != (undefined8 *)0x0) && (cVar6 == '\0')) {
    ExFreePoolWithTag(puVar12,0x69724357);
  }
  return uVar11;
}



===== WcTelemetryAndTracingCleanup @ 14001b768 =====

void WcTelemetryAndTracingCleanup
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,_GUID *param_4)

{
  TlgUnregisterAggregateProvider(param_1,param_2,param_3,param_4);
  imp_WppRecorderLogDelete(WPP_GLOBAL_Control,_WcVerboseRecorder);
  WppCleanupKm();
  return;
}



===== WcTelemetryPostExpansionComplete @ 14001b79c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WcTelemetryPostExpansionComplete
               (undefined1 param_1,byte param_2,int param_3,longlong param_4,int param_5,
               undefined8 param_6,ulonglong param_7,undefined8 param_8,uint param_9,int param_10)

{
  undefined2 uVar1;
  longlong lVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  ushort uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  wchar_t *pwVar10;
  undefined8 uVar11;
  undefined1 auStackY_1b8 [32];
  int local_148;
  uint local_144;
  undefined4 local_140 [2];
  ulonglong local_138;
  undefined8 local_130;
  ulonglong local_128;
  undefined8 local_120;
  ulonglong local_118;
  wchar_t *pwStack_110;
  undefined8 local_108;
  ulonglong local_100;
  undefined8 local_f8 [4];
  int *local_d8;
  undefined8 local_d0;
  ulonglong *local_c8;
  undefined8 local_c0;
  undefined8 *local_b8;
  undefined8 local_b0;
  wchar_t *local_a8;
  undefined8 local_a0;
  ulonglong *local_98;
  undefined8 local_90;
  ulonglong *local_88;
  undefined8 local_80;
  uint *local_78;
  undefined8 local_70;
  ulonglong *local_68;
  undefined8 local_60;
  undefined8 *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1b8;
  lVar2 = *(longlong *)(*(longlong *)(param_4 + 0xf0) + 0x40);
  uVar1 = *(undefined2 *)(lVar2 + 0x20);
  pwStack_110 = (wchar_t *)(lVar2 + 0x22);
  local_118 = (ulonglong)CONCAT22(uVar1,uVar1);
  if (param_5 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDqd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0xe,
                 &WPP_fd6e5da2a1a53c4972de035ee243e502_Traceguids,
                 "onecore\\base\\fs\\wci\\wcifs\\telemetry.c",0xfa,param_1,(char)param_5);
    }
  }
  else if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
          (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_sDqLiLZii();
  }
  uVar9 = 0;
  if (param_3 == 1) {
    if ((-1 < param_5) && (param_2 == 0)) {
      uVar9 = 0x400;
      uVar11 = 1;
      if (param_7 < 0x400) {
        uVar9 = 1;
      }
      else if (param_7 < 0x100000) {
        param_7 = param_7 >> 10;
      }
      else {
        uVar9 = 0x40000000;
        if (param_7 < 0x40000000) {
          uVar9 = 0x100000;
          param_7 = param_7 >> 0x14;
        }
        else {
          param_7 = param_7 >> 0x1e;
        }
      }
      local_108 = 0;
      auVar3._8_8_ = 0;
      auVar3._0_8_ = param_7;
      auVar4._8_8_ = 0;
      auVar4._0_8_ = param_7;
      uVar7 = SUB168(auVar3 * auVar4,0);
      if (SUB168(auVar3 * auVar4,8) == 0) {
        if (5 < DAT_14000f060) {
          puVar8 = &DAT_14000f060;
          uVar6 = _tlgKeywordOn(0x14000f060,0x400000000000);
          if ((char)uVar6 != '\0') {
            local_d8 = (int *)&local_120;
            local_c8 = &local_128;
            local_d0 = 8;
            local_b8 = &local_130;
            local_a8 = (wchar_t *)&local_138;
            local_98 = &local_100;
            local_88 = (ulonglong *)local_140;
            local_144 = param_9;
            local_78 = &local_144;
            local_148 = param_10;
            local_68 = (ulonglong *)&local_148;
            local_58 = &local_108;
            local_c0 = 8;
            local_b0 = 8;
            local_a0 = 8;
            local_90 = 8;
            local_80 = 4;
            local_70 = 4;
            local_60 = 4;
            local_108 = 0x1000000;
            local_50 = 8;
            local_140[0] = uVar9;
            local_138 = param_7;
            local_130 = uVar7;
            local_128 = param_7;
            local_120 = uVar11;
            local_100 = param_7;
            _tlgWriteAgg(puVar8,&DAT_14000b961,(char)uVar9,uVar7,local_f8);
          }
        }
      }
      else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,10,0xf,
                            &WPP_fd6e5da2a1a53c4972de035ee243e502_Traceguids,
                            "onecore\\base\\fs\\wci\\wcifs\\telemetry.c",0x46,0x95);
      }
    }
  }
  else if (((param_3 == 2) && (5 < DAT_14000f060)) &&
          (pwVar10 = pwStack_110, uVar6 = _tlgKeywordOn(0x14000f060,0x400000000000),
          (char)uVar6 != '\0')) {
    local_148 = param_5;
    local_d8 = &local_148;
    local_c8 = (ulonglong *)&local_144;
    local_d0 = 4;
    local_144 = (uint)param_2;
    local_c0 = 4;
    if (pwVar10 == (wchar_t *)0x0) {
      pwVar10 = L"";
      uVar5 = (ushort)uVar9;
    }
    else {
      uVar5 = (ushort)local_118;
    }
    local_b8 = &local_a0;
    local_140[0] = *(undefined4 *)(param_4 + 0xfc);
    local_98 = (ulonglong *)local_140;
    local_138 = *(ulonglong *)(param_4 + 0x100);
    local_88 = &local_138;
    local_130 = param_6;
    local_78 = (uint *)&local_130;
    local_68 = &local_128;
    local_58 = &local_120;
    local_b0 = 2;
    local_a0 = CONCAT44(uVar9,(uint)uVar5);
    local_90 = 4;
    local_80 = 8;
    local_70 = 8;
    local_128 = param_7;
    local_60 = 8;
    local_120 = param_8;
    local_50 = 8;
    local_a8 = pwVar10;
    _tlgWriteTransfer_EtwWriteTransfer(0x14000f060,&DAT_14000b898,0,0,0xb,local_f8);
  }
  return;
}



===== WcTelemetryPostExpansionTrigger @ 14001bc04 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WcTelemetryPostExpansionTrigger
               (undefined1 param_1,int param_2,undefined4 param_3,longlong param_4,int param_5,
               int param_6,byte param_7)

{
  ushort uVar1;
  longlong lVar2;
  ulonglong uVar3;
  wchar_t *pwVar4;
  undefined1 auStackY_178 [32];
  int local_108;
  undefined4 local_104;
  undefined4 local_100;
  int local_fc;
  uint local_f8 [2];
  ulonglong local_f0;
  wchar_t *pwStack_e8;
  undefined8 local_e0;
  undefined8 local_d8 [4];
  int *local_b8;
  undefined8 local_b0;
  undefined4 *local_a8;
  undefined8 local_a0;
  uint *local_98;
  undefined8 local_90;
  wchar_t *local_88;
  uint local_80 [2];
  undefined4 *local_78;
  undefined8 local_70;
  undefined8 *local_68;
  undefined8 local_60;
  int *local_58;
  undefined8 local_50;
  uint *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_178;
  local_f0 = 0;
  pwStack_e8 = (wchar_t *)0x0;
  if (param_6 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDqd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0xc,
                 &WPP_fd6e5da2a1a53c4972de035ee243e502_Traceguids,
                 "onecore\\base\\fs\\wci\\wcifs\\telemetry.c",0xab,param_1,(char)param_6);
    }
  }
  else {
    lVar2 = *(longlong *)(*(longlong *)(param_4 + 0xf0) + 0x40);
    uVar1 = *(ushort *)(lVar2 + 0x20);
    local_80[0] = (uint)uVar1;
    pwStack_e8 = (wchar_t *)(lVar2 + 0x22);
    local_f0 = (ulonglong)CONCAT22(uVar1,uVar1);
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_sDqLiLLZ();
      local_80[0] = (uint)(ushort)local_f0;
    }
    if (((param_2 == 2) && (param_5 < 2)) && (5 < DAT_14000f060)) {
      pwVar4 = pwStack_e8;
      uVar3 = _tlgKeywordOn(0x14000f060,0x400000000000);
      if ((char)uVar3 != '\0') {
        local_108 = param_6;
        local_b8 = &local_108;
        local_a8 = &local_104;
        local_b0 = 4;
        local_a0 = 4;
        if (pwVar4 == (wchar_t *)0x0) {
          pwVar4 = L"";
          local_80[0] = 0;
        }
        local_98 = local_80;
        local_80[0] = local_80[0] & 0xffff;
        local_100 = *(undefined4 *)(param_4 + 0xfc);
        local_78 = &local_100;
        local_e0 = *(undefined8 *)(param_4 + 0x100);
        local_68 = &local_e0;
        local_58 = &local_fc;
        local_f8[0] = (uint)param_7;
        local_48 = local_f8;
        local_90 = 2;
        local_80[1] = 0;
        local_70 = 4;
        local_60 = 8;
        local_50 = 4;
        local_40 = 4;
        local_104 = param_3;
        local_fc = param_5;
        local_88 = pwVar4;
        _tlgWriteTransfer_EtwWriteTransfer(0x14000f060,&DAT_14000ba41,0,0,10,local_d8);
      }
    }
  }
  return;
}



===== WppCleanupKm @ 14001be74 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WppCleanupKm(void)

{
  undefined8 *puVar1;
  
  if ((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    puVar1 = WPP_GLOBAL_Control;
    if (WPPTraceSuite == 4) {
      for (; puVar1 != (undefined8 *)0x0; puVar1 = (undefined8 *)puVar1[2]) {
        if (puVar1[7] != 0) {
          (*pfnEtwUnregister)();
          puVar1[7] = 0;
        }
      }
    }
    else if (WPPTraceSuite == 2) {
      IoWMIRegistrationControl(WPP_GLOBAL_Control,0x80000002);
    }
    WppAutoLogStop(WPP_GLOBAL_Control,0);
    WPP_GLOBAL_Control = &WPP_GLOBAL_Control;
    WPP_RECORDER_INITIALIZED = (undefined *)&WPP_RECORDER_INITIALIZED;
  }
  return;
}



===== WppInitKm @ 14001bf18 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WppInitKm(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  undefined *puVar2;
  
  if (WPP_GLOBAL_Control != &WPP_MAIN_CB) {
    WPP_GLOBAL_Control = &WPP_MAIN_CB;
    if (WPPTraceSuite == 4) {
      puVar2 = &WPP_MAIN_CB;
      do {
        pcVar1 = pfnEtwRegisterClassicProvider;
        *(undefined8 *)(puVar2 + 0x38) = 0;
        (*pcVar1)(*(undefined8 *)(puVar2 + 8),0,WppClassicProviderCallback,puVar2,puVar2 + 0x38);
        puVar2 = *(undefined **)(puVar2 + 0x10);
      } while (puVar2 != (undefined *)0x0);
    }
    else if (WPPTraceSuite == 2) {
      _WPP_MAIN_CB = WppTraceCallback;
      IoWMIRegistrationControl(&WPP_MAIN_CB,0x80010001);
    }
    WppAutoLogStart(WPP_GLOBAL_Control,param_1,param_2);
    WPP_RECORDER_INITIALIZED = &WPP_MAIN_CB;
  }
  return;
}



===== WppLoadTracingSupport @ 14001bff4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WppLoadTracingSupport(void)

{
  uint local_res8 [8];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res8[0] = 0;
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_18,L"PsGetVersion");
  pfnWppGetVersion = (code *)MmGetSystemRoutineAddress(&local_18);
  RtlInitUnicodeString(&local_18,L"WmiTraceMessage");
  pfnWppTraceMessage = MmGetSystemRoutineAddress(&local_18);
  RtlInitUnicodeString(&local_18,L"WmiQueryTraceInformation");
  pfnWppQueryTraceInformation = MmGetSystemRoutineAddress(&local_18);
  WPPTraceSuite = 2;
  if (pfnWppGetVersion != (code *)0x0) {
    (*pfnWppGetVersion)(local_res8,0,0,0);
  }
  if (5 < local_res8[0]) {
    RtlInitUnicodeString(&local_18,L"EtwRegisterClassicProvider");
    pfnEtwRegisterClassicProvider = MmGetSystemRoutineAddress(&local_18);
    if (pfnEtwRegisterClassicProvider != 0) {
      RtlInitUnicodeString(&local_18,L"EtwUnregister");
      pfnEtwUnregister = MmGetSystemRoutineAddress(&local_18);
      WPPTraceSuite = 4;
    }
  }
  return;
}



===== WppTraceCallback @ 14001c140 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
WppTraceCallback(byte param_1,undefined8 param_2,uint param_3,uint *param_4,longlong param_5,
                uint *param_6)

{
  uint *puVar1;
  undefined8 uVar2;
  ushort *puVar3;
  undefined8 uVar4;
  int iVar5;
  undefined4 uVar6;
  longlong lVar7;
  ulonglong uVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  undefined4 local_res8 [2];
  undefined1 uStack_36;
  undefined4 uStack_34;
  
  puVar1 = param_6;
  *param_6 = 0;
  if (param_1 < 6) {
    if ((param_1 == 5) ||
       ((((param_1 != 0 && (param_1 != 1)) && (param_1 != 2)) && ((param_1 != 3 && (param_1 == 4))))
       )) {
      local_res8[0] = 0;
      param_6._0_4_ = 0;
      if (param_5 != 0) {
        if (param_3 < 0x30) {
          return 0xc000000d;
        }
        do {
          puVar1 = *(uint **)(param_5 + 8);
          if (((*puVar1 == param_4[6]) && (puVar1[1] == param_4[7])) &&
             ((puVar1[2] == param_4[8] && (puVar1[3] == param_4[9])))) break;
          param_5 = *(longlong *)(param_5 + 0x10);
        } while (param_5 != 0);
        if (param_5 != 0) {
          if (param_1 == 5) {
            *(undefined4 *)(param_5 + 0x2c) = 0;
            *(undefined8 *)(param_5 + 0x18) = 0;
            *(undefined1 *)(param_5 + 0x29) = 0;
            return 0;
          }
          bVar13 = WPPTraceSuite != 2;
          uVar2 = *(undefined8 *)(param_4 + 2);
          *(undefined8 *)(param_5 + 0x18) = uVar2;
          if (bVar13) {
            uStack_34 = (undefined4)((ulonglong)uVar2 >> 0x20);
            *(undefined4 *)(param_5 + 0x2c) = uStack_34;
            uStack_36 = (undefined1)((ulonglong)uVar2 >> 0x10);
            *(undefined1 *)(param_5 + 0x29) = uStack_36;
            return 0;
          }
          iVar5 = (*pfnWppQueryTraceInformation)(3,local_res8,4,&param_6,param_4);
          if (iVar5 == 0) {
            *(undefined1 *)(param_5 + 0x29) = (undefined1)local_res8[0];
          }
          uVar6 = (*pfnWppQueryTraceInformation)(2,param_5 + 0x2c,4,&param_6,param_4);
          return uVar6;
        }
      }
      return 0xc0000295;
    }
  }
  else {
    if (param_1 == 6) {
      return 0;
    }
    if (param_1 == 7) {
      return 0;
    }
    if (param_1 == 8) {
      uVar10 = 0;
      puVar3 = *(ushort **)(param_5 + 0x20);
      lVar7 = param_5;
      do {
        lVar7 = *(longlong *)(lVar7 + 0x10);
        uVar10 = uVar10 + 1;
      } while (lVar7 != 0);
      if (0x3f < uVar10) {
        return 0xc000000d;
      }
      uVar11 = uVar10 * 0x20 + 0x18;
      if (puVar3 == (ushort *)0x0) {
        uVar12 = uVar11;
        uVar11 = 0;
      }
      else {
        uVar12 = *puVar3 + 2 + uVar11;
      }
      if (param_3 < uVar12) {
        if (param_3 < 4) {
          return 0xc0000023;
        }
        *param_4 = uVar12;
        *param_6 = 4;
        return 0xc0000023;
      }
      memset(param_4,0,(ulonglong)param_3);
      *param_4 = uVar12;
      param_4[2] = uVar11;
      param_4[4] = uVar10;
      if (puVar3 != (ushort *)0x0) {
        *(ushort *)((ulonglong)uVar11 + (longlong)param_4) = *puVar3;
        memmove((ushort *)((ulonglong)uVar11 + (longlong)param_4) + 1,*(void **)(puVar3 + 4),
                (ulonglong)*puVar3);
      }
      if (uVar10 != 0) {
        uVar8 = (ulonglong)uVar10;
        puVar9 = param_4 + 10;
        do {
          uVar2 = **(undefined8 **)(param_5 + 8);
          uVar4 = (*(undefined8 **)(param_5 + 8))[1];
          *puVar9 = 0x81000;
          *(undefined8 *)(puVar9 + -4) = uVar2;
          *(undefined8 *)(puVar9 + -2) = uVar4;
          *(undefined1 *)(param_5 + 0x29) = 0;
          *(undefined4 *)(param_5 + 0x2c) = 0;
          param_5 = *(longlong *)(param_5 + 0x10);
          uVar8 = uVar8 - 1;
          puVar9 = puVar9 + 8;
        } while (uVar8 != 0);
      }
      *puVar1 = uVar12;
      return 0;
    }
  }
  return 0xc0000010;
}



===== WcAddInMemoryTombstone @ 14001c3c8 =====

uint WcAddInMemoryTombstone
               (longlong param_1,undefined8 param_2,longlong param_3,undefined1 param_4,
               longlong param_5)

{
  longlong lVar1;
  char cVar2;
  uint uVar3;
  int *piVar4;
  longlong lVar5;
  undefined8 in_stack_ffffffffffffffa8;
  undefined4 local_38 [2];
  longlong local_30;
  longlong local_28;
  longlong local_20;
  
  uVar3 = 0;
  local_20 = 0;
  local_28 = 0;
  lVar5 = 0;
  local_38[0] = 0;
  local_30 = 0;
  piVar4 = (int *)WcGetUnionContext(param_1,param_2,param_5);
  if (piVar4 == (int *)0x0) goto LAB_14001c5cd;
  uVar3 = WcGetSetContextFileObject
                    (param_2,param_5,piVar4,1,in_stack_ffffffffffffffa8,&local_20,&local_28);
  lVar1 = local_28;
  if ((int)uVar3 < 0) {
    if (uVar3 == 0xc0000275) goto LAB_14001c589;
  }
  else if (uVar3 == 0x104) {
LAB_14001c589:
    uVar3 = 0;
  }
  else if (local_28 != 0) {
    lVar5 = ExAllocatePool2(0x100,(ulonglong)*(ushort *)(param_3 + 2) + 0x30,0x74684357);
    if (lVar5 == 0) {
LAB_14001c487:
      uVar3 = 0xc000009a;
    }
    else {
      *(undefined1 *)(lVar5 + 0x18) = param_4;
      *(longlong *)(lVar5 + 0x28) = lVar5 + 0x30;
      *(undefined2 *)(lVar5 + 0x22) = *(undefined2 *)(param_3 + 2);
      RtlCopyUnicodeString(lVar5 + 0x20,param_3);
      uVar3 = RtlDowncaseUnicodeString(param_3,param_3,0);
      if (-1 < (int)uVar3) {
        uVar3 = RtlHashUnicodeString(param_3,1,0,local_38);
        KeWaitForSingleObject(lVar1 + 0xe8,0,0,0,0);
        if (*(longlong *)(lVar1 + 0x100) == 0) {
          cVar2 = RtlCreateHashTable(&local_30,0,0);
          if (cVar2 == '\0') goto LAB_14001c487;
          *(longlong *)(lVar1 + 0x100) = local_30;
          local_30 = 0;
        }
        RtlInsertEntryHashTable(*(undefined8 *)(lVar1 + 0x100),lVar5,local_38[0],0);
        KeSetEvent(lVar1 + 0xe8,0,0);
        lVar5 = 0;
      }
    }
  }
  if (local_20 != 0) {
    FltReleaseContext();
  }
  if (lVar1 != 0) {
    FltReleaseContext(lVar1);
  }
  if (lVar5 != 0) {
    ExFreePoolWithTag(lVar5,0x74684357);
  }
LAB_14001c5cd:
  if (local_30 != 0) {
    RtlDeleteHashTable();
  }
  if (piVar4 != (int *)0x0) {
    WcReleaseUnionContext(piVar4);
  }
  return uVar3;
}



===== WcCreateTombstone @ 14001c618 =====

int WcCreateTombstone(undefined8 param_1,undefined8 param_2,char param_3)

{
  char cVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 *local_res20;
  undefined4 uVar4;
  undefined1 uVar5;
  longlong local_c8;
  longlong local_c0;
  longlong local_b8 [6];
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  ulonglong uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  
  local_48 = 0;
  local_c8 = 0;
  local_res20 = (undefined2 *)0x0;
  local_b8[5] = local_b8[5] & 0xffffffffffff0000;
  local_68 = 0;
  uStack_60 = uStack_60 & 0xffffffff00000000;
  local_c0 = 0;
  local_b8[0] = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_b8[1] = 0;
  local_b8[2] = 0;
  local_b8[3] = 0;
  local_b8[4] = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_40 = 0;
  uStack_38 = 0;
  iVar2 = FltAllocateExtraCreateParameterList(Globals,0,&local_c8);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001c8c2;
    uVar3 = 0xe;
    uVar5 = 0xf6;
  }
  else {
    uVar4 = 0;
    iVar2 = FltAllocateExtraCreateParameterFromLookasideList
                      (Globals,&GUID_ECP_ATOMIC_CREATE,0x58,0,0,&DAT_14000f280,&local_res20);
    if (-1 < iVar2) {
      local_58 = CONCAT26(local_58._6_2_,0xa000001f);
      memset(local_res20,0,0x58);
      *local_res20 = 0x58;
      local_res20[1] = 2;
      local_res20[2] = 0;
      local_res20[3] = 8;
      *(undefined8 **)(local_res20 + 4) = &local_58;
      FltInsertExtraCreateParameter(Globals,local_c8,local_res20);
      local_b8[3] = 0;
      local_b8[4] = 0;
      local_b8[1] = 0x28;
      local_b8[5] = PsGetHostSilo();
      local_b8[2] = local_c8;
      local_88 = CONCAT44(local_88._4_4_,0x30);
      uStack_80 = 0;
      uStack_70 = CONCAT44(uStack_70._4_4_,0x240);
      local_68 = 0;
      uStack_60 = 0;
      local_78 = param_2;
      iVar2 = FltCreateFileEx2(Globals,param_1,&local_c0,local_b8,CONCAT44(uVar4,0x40000000),
                               &local_88,&local_40,0,6,0,2,(param_3 != '\0') + 0x210028,0,0,0,
                               local_b8 + 1);
      if (iVar2 == -0x3fffffcb) {
        iVar2 = 0;
      }
      else if (-1 < iVar2) {
        cVar1 = FltIsEcpAcknowledged(Globals,local_res20);
        if (cVar1 == '\0') {
          iVar2 = -0x3fffffff;
        }
      }
      goto LAB_14001c8c2;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001c8c2;
    uVar3 = 0xf;
    uVar5 = 3;
  }
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0x13,uVar3,
                      &WPP_6c993b8198b53d328fc429e03cc469de_Traceguids,
                      "onecore\\base\\fs\\wci\\wcifs\\tombstone.c",uVar5,(char)iVar2);
LAB_14001c8c2:
  if (local_c8 != 0) {
    FltFreeExtraCreateParameterList(Globals);
  }
  if (local_c0 != 0) {
    FltClose();
  }
  if (local_b8[0] != 0) {
    ObfDereferenceObject();
  }
  return iVar2;
}



===== WcDeleteTombstone @ 14001c930 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint WcDeleteTombstone(longlong param_1,undefined8 param_2,longlong param_3,undefined8 param_4,
                      longlong param_5)

{
  uint uVar1;
  ulonglong uVar2;
  undefined2 uVar3;
  undefined1 auStackY_1c8 [32];
  undefined1 uVar4;
  undefined1 local_148;
  undefined1 local_147;
  undefined1 local_146 [6];
  longlong local_140;
  undefined4 local_138;
  uint local_134;
  longlong local_130;
  undefined4 local_128;
  undefined4 local_124;
  undefined8 local_120;
  longlong local_118;
  undefined4 local_110;
  undefined4 local_10c;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 local_a8 [4];
  undefined1 *local_88;
  undefined8 local_80;
  undefined1 *local_78;
  undefined8 local_70;
  uint *local_68;
  undefined8 local_60;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_1c8;
  local_130 = 0;
  local_b0 = 0;
  local_140 = 0;
  local_148 = 0;
  local_138 = 0;
  local_d8 = 1;
  local_124 = 0;
  local_10c = 0;
  uStack_f0 = 0;
  local_f8 = 0x28;
  local_c0 = 0;
  uStack_b8 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  local_e8 = 0;
  uStack_e0 = 0;
  if (param_3 != 0) {
    local_d8 = IoGetSilo(param_3);
  }
  local_128 = 0x30;
  local_110 = 0x240;
  local_118 = param_5;
  local_108 = 0;
  uStack_100 = 0;
  local_120 = param_4;
  uVar1 = FltCreateFileEx2(Globals,param_2,&local_130,&local_140);
  if (uVar1 == 0xc0000034) {
    uVar1 = 0;
    goto LAB_14001cc71;
  }
  if ((int)uVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001cc71;
    uVar3 = 10;
    uVar4 = 0x75;
  }
  else {
    uVar1 = FltQueryInformationFile(param_2,local_140,&local_c0,0x18);
    if ((int)uVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001cc71;
      uVar3 = 0xb;
      uVar4 = 0x85;
    }
    else {
      uVar1 = WcAddInMemoryTombstone(param_1,param_2,param_5,local_b0._5_1_,param_3);
      if ((int)uVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0x13,0xc,
                              &WPP_6c993b8198b53d328fc429e03cc469de_Traceguids,
                              "onecore\\base\\fs\\wci\\wcifs\\tombstone.c",0x94,(char)uVar1);
        }
        if (5 < DAT_14000f060) {
          uVar2 = _tlgKeywordOn(0x14000f060,0x400000000000);
          if ((char)uVar2 != '\0') {
            local_88 = &local_147;
            local_147 = 3;
            local_78 = local_146;
            local_80 = 1;
            local_68 = &local_134;
            local_146[0] = 3;
            local_70 = 1;
            local_60 = 4;
            local_134 = uVar1;
            _tlgWriteTransfer_EtwWriteTransfer(0x14000f060,&DAT_14000bb49,0,0,5,local_a8);
          }
        }
        goto LAB_14001cc71;
      }
      local_148 = 1;
      uVar1 = FltSetInformationFile(param_2,local_140,&local_148,1);
      if ((-1 < (int)uVar1) || ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
         ) goto LAB_14001cc71;
      uVar3 = 0xd;
      uVar4 = 0xac;
    }
  }
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0x13,uVar3,
                      &WPP_6c993b8198b53d328fc429e03cc469de_Traceguids,
                      "onecore\\base\\fs\\wci\\wcifs\\tombstone.c",uVar4,(char)uVar1);
LAB_14001cc71:
  if (local_130 != 0) {
    FltClose();
  }
  if (local_140 != 0) {
    ObfDereferenceObject();
  }
  return uVar1;
}



===== WcFreeInMemoryTombstoneHashTable @ 14001ccc4 =====

void WcFreeInMemoryTombstoneHashTable(longlong param_1)

{
  longlong lVar1;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if (*(int *)(param_1 + 0x14) != 0) {
    RtlInitEnumerationHashTable(0,&local_38);
    while( true ) {
      lVar1 = RtlEnumerateEntryHashTable(param_1,&local_38);
      if (lVar1 == 0) break;
      RtlRemoveEntryHashTable(param_1,lVar1,0);
      ExFreePoolWithTag(lVar1,0x74684357);
    }
    RtlEndEnumerationHashTable(param_1,&local_38);
  }
  RtlDeleteHashTable(param_1);
  return;
}



===== WcProcessTombstoneBounce @ 14001cd74 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint WcProcessTombstoneBounce
               (longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  char cVar1;
  undefined8 uVar2;
  short sVar3;
  uint uVar4;
  uint extraout_EAX;
  int iVar5;
  undefined4 uVar6;
  ulonglong uVar7;
  short sVar8;
  longlong lVar9;
  undefined2 uVar10;
  longlong lVar11;
  undefined1 auStackY_198 [32];
  undefined1 uVar12;
  char local_128;
  byte local_127;
  byte local_126 [6];
  longlong local_120;
  longlong local_118;
  longlong local_110;
  longlong local_108;
  undefined4 local_100;
  longlong local_f8;
  undefined8 local_f0;
  longlong local_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  longlong local_c8 [3];
  char cStack_ab;
  undefined8 local_b0;
  undefined8 local_a8 [4];
  byte *local_88;
  undefined8 local_80;
  char *local_78;
  undefined8 local_70;
  longlong *local_68;
  undefined8 local_60;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_198;
  cVar1 = *(char *)(*(longlong *)(param_1 + 0x10) + 0x23);
  local_120 = 0;
  local_f8 = 0;
  uVar4 = 0;
  local_126[1] = 0;
  lVar9 = 0;
  local_110 = 0;
  lVar11 = 0;
  local_108 = 0;
  local_126[0] = 0;
  local_100 = 0;
  local_b0 = 0;
  local_128 = '\0';
  local_c8[0] = 0;
  local_118 = 0;
  local_127 = 0;
  local_c8[1] = 0;
  local_c8[2] = 0;
  local_e0 = 0;
  uStack_d8 = 0;
  local_f0 = param_2;
  local_e8 = param_4;
  local_d0 = param_3;
  if ((cVar1 == '\x01') || (cVar1 == '\x04')) {
    if ((*(longlong *)(param_1 + 0x28) == 0) ||
       (uVar6 = 0xc000003a, *(short *)(*(longlong *)(param_1 + 0x28) + 6) == 0)) {
      uVar6 = 0xc0000034;
    }
    *(undefined4 *)(param_1 + 0x18) = uVar6;
    *(undefined8 *)(param_1 + 0x28) = 0;
    FltSetCallbackDataDirty(param_1);
    goto LAB_14001ce86;
  }
  uVar4 = FltParseFileNameInformation(*(undefined8 *)(param_4 + 0x30));
  if ((int)uVar4 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001ce86;
    uVar10 = 0x11;
    uVar12 = 0x78;
LAB_14001ce57:
    WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0x13,uVar10,
                        &WPP_6c993b8198b53d328fc429e03cc469de_Traceguids,
                        "onecore\\base\\fs\\wci\\wcifs\\tombstone.c",uVar12,(char)uVar4);
  }
  else {
    WcOpenAsReparsePoint
              (*(longlong *)(param_4 + 0x30) + 8,0,0,param_2,0x10000000,-0x7fffffe0,&local_110,
               &local_108,(byte *)0x0,(byte *)0x0,(byte *)0x0,(undefined1 *)0x0,local_126);
    if ((int)extraout_EAX < 0) {
      uVar4 = extraout_EAX;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001ce86;
      uVar10 = 0x12;
      uVar12 = 0x8e;
      goto LAB_14001ce57;
    }
    if (local_126[0] == 0) {
LAB_14001d2bf:
      lVar9 = local_e8;
      *(undefined4 *)(local_e8 + 0x14) = 0;
      FltReissueSynchronousIo(param_2,param_1);
      uVar2 = local_f0;
      if (*(int *)(param_1 + 0x18) == 0) {
        iVar5 = WcGetSetFileContext(local_f0,local_d0,1,0,&local_f8);
        if ((iVar5 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0x13,0x18,
                              &WPP_6c993b8198b53d328fc429e03cc469de_Traceguids,
                              "onecore\\base\\fs\\wci\\wcifs\\tombstone.c",10,(char)iVar5);
        }
        local_120 = local_f8;
      }
      else if ((local_126[0] != 0) &&
              (iVar5 = WcCreateTombstone(local_f0,*(longlong *)(lVar9 + 0x30) + 8,local_128),
              iVar5 < 0)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0x13,0x19,
                              &WPP_6c993b8198b53d328fc429e03cc469de_Traceguids,
                              "onecore\\base\\fs\\wci\\wcifs\\tombstone.c",0x22,(char)iVar5);
        }
        if ((5 < DAT_14000f060) &&
           (uVar7 = _tlgKeywordOn(0x14000f060,0x400000000000), (char)uVar7 != '\0')) {
          local_88 = &local_127;
          local_78 = &local_128;
          local_127 = 1;
          local_68 = &local_118;
          local_80 = 1;
          local_128 = '\x01';
          local_70 = 1;
          local_118 = CONCAT44(local_118._4_4_,iVar5);
          local_60 = 4;
          _tlgWriteTransfer_EtwWriteTransfer(0x14000f060,&DAT_14000bba7,0,0,5,local_a8);
        }
      }
      uVar4 = WcRemoveInMemoryTombstone(uVar2,*(longlong *)(local_e8 + 0x30),lVar11);
      if ((int)uVar4 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0x13,0x1a,
                              &WPP_6c993b8198b53d328fc429e03cc469de_Traceguids,
                              "onecore\\base\\fs\\wci\\wcifs\\tombstone.c",0x36,(char)uVar4);
        }
        if ((5 < DAT_14000f060) &&
           (uVar7 = _tlgKeywordOn(0x14000f060,0x400000000000), (char)uVar7 != '\0')) {
          local_88 = &local_127;
          local_127 = 2;
          local_78 = &local_128;
          local_80 = 1;
          local_68 = &local_118;
          local_128 = '\x01';
          local_70 = 1;
          local_118 = CONCAT44(local_118._4_4_,uVar4);
          local_60 = 4;
          _tlgWriteTransfer_EtwWriteTransfer(0x14000f060,&DAT_14000bc05,0,0,5,local_a8);
        }
        uVar4 = 0;
      }
    }
    else {
      uVar4 = FltQueryInformationFile(param_2,local_108,local_c8 + 1,0x18);
      lVar9 = local_e8;
      if ((int)uVar4 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar10 = 0x13;
          uVar12 = 0x9f;
          goto LAB_14001ce57;
        }
      }
      else {
        local_128 = cStack_ab;
        lVar11 = *(longlong *)(local_e8 + 0x30);
        uStack_d8 = *(undefined8 *)(lVar11 + 0x10);
        sVar8 = *(short *)(lVar11 + 8) - *(short *)(lVar11 + 0x58);
        sVar3 = sVar8 + -2;
        if (sVar3 == *(short *)(lVar11 + 0x18)) {
          sVar3 = sVar8;
        }
        local_e0 = CONCAT62(*(undefined6 *)(lVar11 + 10),sVar3);
        uVar4 = WcOpenPlaceHolder(param_2,(wchar_t *)&local_e0,0x29,*(undefined4 *)(local_e8 + 0x10)
                                  ,local_c8,&local_118,&local_127);
        lVar11 = local_118;
        if ((int)uVar4 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar10 = 0x14;
            uVar12 = 0xb7;
LAB_14001d0af:
            WPP_RECORDER_SF_sDdZ
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0x13,uVar10,
                       &WPP_6c993b8198b53d328fc429e03cc469de_Traceguids,
                       "onecore\\base\\fs\\wci\\wcifs\\tombstone.c",uVar12,(char)uVar4,
                       (wchar_t *)&local_e0);
          }
        }
        else {
          if (local_127 != 0) {
            uVar4 = WcAddInMemoryTombstone
                              (param_1,param_2,*(longlong *)(lVar9 + 0x30) + 0x58,local_128,
                               local_118);
            if (-1 < (int)uVar4) {
              local_126[1] = 1;
              iVar5 = FltSetInformationFile(param_2,local_108,local_126 + 1);
              if ((iVar5 < 0) &&
                 ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                WPP_RECORDER_SF_sDqd
                          (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0x13,0x17,
                           &WPP_6c993b8198b53d328fc429e03cc469de_Traceguids,
                           "onecore\\base\\fs\\wci\\wcifs\\tombstone.c",0xea,(char)local_d0,
                           (char)iVar5);
              }
              FltClose(local_110);
              local_110 = 0;
              goto LAB_14001d2bf;
            }
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0x13,0x16,
                                  &WPP_6c993b8198b53d328fc429e03cc469de_Traceguids,
                                  "onecore\\base\\fs\\wci\\wcifs\\tombstone.c",0xcc,(char)uVar4);
            }
            if ((5 < DAT_14000f060) &&
               (uVar7 = _tlgKeywordOn(0x14000f060,0x400000000000), (char)uVar7 != '\0')) {
              local_88 = &local_127;
              local_127 = 3;
              local_78 = &local_128;
              local_80 = 1;
              local_68 = &local_118;
              local_128 = '\x01';
              local_70 = 1;
              local_118 = CONCAT44(local_118._4_4_,uVar4);
              local_60 = 4;
              _tlgWriteTransfer_EtwWriteTransfer(0x14000f060,&DAT_14000bcc1,0,0,5,local_a8);
            }
            goto LAB_14001ce81;
          }
          uVar4 = 0xc0000034;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar10 = 0x15;
            uVar12 = 0xbe;
            goto LAB_14001d0af;
          }
        }
        lVar11 = local_118;
      }
    }
  }
LAB_14001ce81:
  lVar9 = local_120;
LAB_14001ce86:
  if (local_110 != 0) {
    FltClose();
  }
  if (local_108 != 0) {
    ObfDereferenceObject();
  }
  if (lVar9 != 0) {
    FltReleaseContext(lVar9);
  }
  if (local_c8[0] != 0) {
    FltClose();
  }
  if (lVar11 != 0) {
    ObfDereferenceObject(lVar11);
  }
  return uVar4;
}



===== WcRemoveInMemoryTombstone @ 14001d580 =====

int WcRemoveInMemoryTombstone(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  longlong lVar1;
  bool bVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  undefined4 local_res20 [2];
  longlong local_18;
  longlong local_10;
  
  iVar3 = 0;
  local_10 = 0;
  local_18 = 0;
  local_res20[0] = 0;
  bVar2 = WcGetContextFileObject(param_1,param_3,&local_10,&local_18);
  lVar1 = local_18;
  if (((bVar2) && (local_18 != 0)) && (*(longlong *)(local_18 + 0x100) != 0)) {
    lVar5 = param_2 + 0x58;
    iVar3 = RtlDowncaseUnicodeString(lVar5,lVar5,0);
    if (-1 < iVar3) {
      iVar3 = RtlHashUnicodeString(lVar5,1,0,local_res20);
      if (-1 < iVar3) {
        KeWaitForSingleObject(lVar1 + 0xe8,0,0,0,0);
        lVar4 = RtlLookupEntryHashTable(*(undefined8 *)(lVar1 + 0x100),local_res20[0],0);
        lVar5 = 0;
        if (lVar4 != 0) {
          RtlRemoveEntryHashTable(*(undefined8 *)(lVar1 + 0x100),lVar4,0);
          lVar5 = lVar4;
        }
        KeSetEvent(lVar1 + 0xe8,0,0);
        if (lVar5 != 0) {
          ExFreePoolWithTag(lVar5,0x74684357);
        }
      }
    }
  }
  if (local_10 != 0) {
    FltReleaseContext();
  }
  if (lVar1 != 0) {
    FltReleaseContext(lVar1);
  }
  return iVar3;
}



===== WcRemoveTombstonesFromDirectory @ 14001d6f8 =====

ulonglong WcRemoveTombstonesFromDirectory(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  uint *puVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined1 uVar5;
  uint *puVar6;
  undefined4 local_res20 [2];
  longlong local_48;
  longlong local_40;
  undefined8 local_38;
  uint *puStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_40 = 0;
  local_48 = 0;
  local_28 = 0;
  uStack_20 = 0;
  uVar5 = 1;
  local_38 = 0;
  puStack_30 = (uint *)0x0;
  puVar2 = (uint *)ExAllocatePool2(0x100,0x10000,0x65644357);
  if (puVar2 == (uint *)0x0) {
    uVar3 = 0xc000009a;
  }
  else {
    uVar4 = WcReopenFile(param_2,param_3,&local_40,&local_48);
    uVar3 = uVar4 & 0xffffffff;
    if (-1 < (int)uVar4) {
      RtlInitUnicodeString(&local_28,L"*");
      while( true ) {
        uVar1 = WcEnumerateDirectory
                          (param_2,local_48,0x3c,&local_28,0,uVar5,0x10000,puVar2,local_res20);
        uVar3 = (ulonglong)uVar1;
        if ((int)uVar1 < 0) break;
        puVar6 = puVar2;
        while( true ) {
          if (puVar6[0x11] == 0xa000001f) {
            puStack_30 = puVar6 + 0x16;
            local_38._0_4_ = CONCAT22((short)puVar6[0xf],(short)puVar6[0xf]);
            uVar1 = WcDeleteTombstone(param_1,param_2,local_48,local_40,(longlong)&local_38);
            uVar3 = (ulonglong)uVar1;
            if ((int)uVar1 < 0) goto LAB_14001d889;
          }
          if (*puVar6 == 0) break;
          puVar6 = (uint *)((longlong)puVar6 + (ulonglong)*puVar6);
        }
        uVar5 = 0;
      }
      if (uVar1 == 0x80000006) {
        uVar3 = 0;
      }
      else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0x13,0x10,
                            &WPP_6c993b8198b53d328fc429e03cc469de_Traceguids,
                            "onecore\\base\\fs\\wci\\wcifs\\tombstone.c",0xb4,(char)uVar1);
      }
    }
LAB_14001d889:
    ExFreePoolWithTag(puVar2,0x65644357);
    if (local_40 != 0) {
      FltClose();
    }
    if (local_48 != 0) {
      ObfDereferenceObject();
    }
  }
  return uVar3;
}



===== WcAllocateLayerTableEntry @ 14001d8f0 =====

void WcAllocateLayerTableEntry(undefined8 param_1,undefined4 param_2)

{
  ExAllocatePool2(0x100,param_2,0x796c4357);
  return;
}



===== WcAllocateUnionTableEntry @ 14001d920 =====

void WcAllocateUnionTableEntry(undefined8 param_1,undefined4 param_2)

{
  ExAllocatePool2(0x100,param_2,0x63754357);
  return;
}



===== WcCleanupLayer @ 14001d94c =====

void WcCleanupLayer(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  longlong local_res8 [4];
  
  local_res8[0] = 0;
  plVar1 = (longlong *)(param_1 + 0x30);
  lVar2 = *plVar1;
  if ((*(longlong **)(lVar2 + 8) != plVar1) ||
     (plVar3 = *(longlong **)(param_1 + 0x38), (longlong *)*plVar3 != plVar1)) {
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)(3);
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  *plVar3 = lVar2;
  *(longlong **)(lVar2 + 8) = plVar3;
  if (*(longlong *)(param_1 + 0x40) != 0) {
    WcClearDirectoryTable(param_1);
    RtlDeleteHashTable(param_1 + 0x48);
    ExDeleteResourceLite(*(undefined8 *)(param_1 + 0x40));
    ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x40),0x796c4357);
  }
  if (*(longlong *)(param_1 + 0x28) != 0) {
    if ((*(uint *)(param_1 + 0x10) & 8) != 0) {
      FltGetInstanceContext(*(longlong *)(param_1 + 0x28),local_res8);
      LOCK();
      *(int *)(local_res8[0] + 0x14) = *(int *)(local_res8[0] + 0x14) + -1;
      UNLOCK();
      FltReleaseContext(local_res8[0]);
      FltObjectDereference(*(undefined8 *)(param_1 + 0x28));
    }
    *(undefined8 *)(param_1 + 0x28) = 0;
  }
  if ((*(longlong *)(param_1 + 0x20) != 0) && (*(char *)(param_1 + 0x14) != '\0')) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x20),0x796c4357);
  }
  ExFreePoolWithTag(param_1,0x796c4357);
  return;
}



===== WcCleanupSiloContext @ 14001da60 =====

void WcCleanupSiloContext(longlong param_1)

{
  WcClearUnionTable(param_1 + 0x70);
  ExDeleteResourceLite(param_1 + 8);
  return;
}



===== WcCleanupUnionContext @ 14001da90 =====

void WcCleanupUnionContext(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  
  uVar2 = 1;
  while( true ) {
    lVar1 = RtlEnumerateGenericTableAvl(param_1 + 0x40,uVar2);
    if (lVar1 == 0) break;
    RtlDeleteElementGenericTableAvl(param_1 + 0x40);
    uVar2 = 0;
  }
  if ((*(uint *)(param_1 + 0x20) & 1) != 0) {
    ExAcquireFastMutex(&DAT_14000f208);
    DAT_14000f244 = DAT_14000f244 + -1;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffffe;
    ExReleaseFastMutex(&DAT_14000f208);
  }
  ExFreePoolWithTag(param_1,0x63754357);
  return;
}



===== WcClearDirectoryTable @ 14001db2c =====

void WcClearDirectoryTable(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_38 = 0;
  uStack_30 = 0;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  FltAcquireResourceExclusive(*(undefined8 *)(param_1 + 0x40));
  if (*(int *)(param_1 + 0x5c) != 0) {
    lVar1 = param_1 + 0x48;
    RtlInitEnumerationHashTable(lVar1,&local_38);
    while( true ) {
      lVar2 = RtlEnumerateEntryHashTable(lVar1,&local_38);
      if (lVar2 == 0) break;
      RtlRemoveEntryHashTable(lVar1,lVar2,0);
      if (*(longlong *)(lVar2 + 0x20) != 0) {
        ExFreePoolWithTag(*(longlong *)(lVar2 + 0x20),0x6e664357);
      }
      if (*(longlong *)(*(longlong *)(lVar2 + 0x28) + 8) != 0) {
        FltClose();
      }
      if (*(longlong *)(*(longlong *)(lVar2 + 0x28) + 0x10) != 0) {
        ObfDereferenceObject();
      }
      ExFreePoolWithTag(*(undefined8 *)(lVar2 + 0x28),0x73734357);
      ExFreePoolWithTag(lVar2,0x74644357);
    }
    RtlEndEnumerationHashTable(lVar1,&local_38);
  }
  FltReleaseResource(*(undefined8 *)(param_1 + 0x40));
  return;
}



===== WcClearUnionTable @ 14001dc6c =====

void WcClearUnionTable(undefined8 param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  
  uVar2 = 1;
  while( true ) {
    lVar1 = RtlEnumerateGenericTableAvl(param_1,uVar2);
    if (lVar1 == 0) break;
    RtlDeleteElementGenericTableAvl(param_1);
    uVar2 = 0;
  }
  return;
}



===== WcCopyDataStreamByName @ 14001dcb0 =====

int WcCopyDataStreamByName
              (wchar_t *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              wchar_t *param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
              longlong param_9)

{
  int iVar1;
  undefined2 uVar2;
  longlong local_res8;
  longlong local_res10;
  undefined8 in_stack_ffffffffffffff08;
  undefined4 uVar4;
  undefined8 uVar3;
  undefined1 uVar5;
  longlong local_98;
  longlong local_90;
  longlong local_88 [6];
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  wchar_t *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  uVar4 = (undefined4)((ulonglong)in_stack_ffffffffffffff08 >> 0x20);
  local_88[0] = 0;
  local_88[5] = 0;
  local_88[2] = 0;
  local_54 = 0;
  local_88[1] = 0x28;
  local_3c = 0;
  local_90 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_res10 = 0;
  local_res8 = 0;
  local_98 = 0;
  local_88[3] = 0;
  local_88[4] = 0;
  local_88[5] = IoGetSilo(param_3);
  local_58 = 0x30;
  uVar3 = CONCAT44(uVar4,0x120089);
  local_40 = 0x240;
  local_38 = 0;
  uStack_30 = 0;
  local_50 = param_2;
  local_48 = param_1;
  iVar1 = FltCreateFileEx2(Globals,param_4,&local_90,&local_res10,uVar3,&local_58,&local_28,0,0x80,1
                           ,1,0x200020,0,0,0x100,local_88 + 1);
  uVar4 = (undefined4)((ulonglong)uVar3 >> 0x20);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001df75;
    uVar2 = 0x6b;
    uVar5 = 0x37;
  }
  else {
    local_88[5] = 1;
    local_88[2] = 0;
    local_88[1] = 0x28;
    local_88[3] = 0;
    local_88[4] = 0;
    local_88[5] = IoGetSilo(param_7);
    local_50 = param_6;
    local_48 = param_5;
    local_58 = 0x30;
    local_40 = 0x240;
    local_38 = 0;
    uStack_30 = 0;
    iVar1 = FltCreateFileEx2(Globals,param_8,local_88,&local_res8,CONCAT44(uVar4,0xc0000000),
                             &local_58,&local_28,0,0x80,1,2,0x200028,0,0,0x100,local_88 + 1);
    if (-1 < iVar1) {
      local_98 = param_9;
      iVar1 = FltSetInformationFile(param_8,local_res8,&local_98,8,0x14);
      if (-1 < iVar1) {
        iVar1 = WcCopyStreamData(param_4,local_res10,param_9,param_8,local_res8,'\0');
      }
      goto LAB_14001df75;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001df75;
    uVar2 = 0x6c;
    uVar5 = 99;
  }
  WPP_RECORDER_SF_sDZd
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,uVar2,
             &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
             "onecore\\base\\fs\\wci\\wcifs\\utils.c",uVar5,param_1,(char)iVar1);
LAB_14001df75:
  if (local_90 != 0) {
    FltClose();
  }
  if (local_res10 != 0) {
    ObfDereferenceObject();
  }
  if (local_88[0] != 0) {
    FltClose();
  }
  if (local_res8 != 0) {
    ObfDereferenceObject();
  }
  return iVar1;
}



===== WcCopyFile @ 14001dfec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int WcCopyFile(longlong param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4,
              longlong param_5,undefined8 param_6,longlong param_7,char param_8,byte param_9)

{
  char cVar1;
  int iVar2;
  byte bVar3;
  longlong lVar4;
  uint uVar5;
  undefined2 uVar6;
  longlong lVar7;
  undefined1 auStackY_208 [32];
  undefined1 uVar8;
  uint local_180 [2];
  longlong local_178;
  longlong local_170;
  longlong local_168;
  undefined4 local_160;
  undefined4 local_15c;
  wchar_t *local_158;
  longlong local_150;
  longlong local_148;
  longlong local_140 [7];
  undefined8 local_108;
  longlong local_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  wchar_t *local_e8;
  undefined8 uStack_e0;
  longlong local_d8;
  ulonglong local_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  ulonglong local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_208;
  local_108 = param_6;
  lVar4 = 0;
  local_140[6] = param_7;
  lVar7 = 0;
  local_150 = 0;
  local_180[1] = 0;
  local_178 = 0;
  local_160 = 0;
  local_148 = 0;
  local_168 = 0;
  local_140[0] = 0;
  local_180[0] = 0;
  local_170 = 0;
  local_d8 = 0;
  local_d0 = local_d0 & 0xffffffff00000000;
  local_140[5] = local_140[5] & 0xffffffffffff0000;
  local_60 = 0;
  local_98 = 0;
  local_f8 = 0;
  uStack_f0 = 0;
  local_e8 = (wchar_t *)0x0;
  uStack_e0 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_140[1] = 0;
  local_140[2] = 0;
  local_140[3] = 0;
  local_140[4] = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_158 = param_4;
  local_100 = param_1;
  iVar2 = FltQueryInformationFile(param_3,0,&local_70,0x18);
  if (iVar2 < 0) goto LAB_14001e674;
  local_15c = 0x210028;
  if (local_60._5_1_ != '\0') {
    local_15c = 0x210029;
  }
  iVar2 = WcQueryEa(param_3,param_2,&local_150,local_180 + 1);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001e674;
    uVar6 = 0xa1;
    uVar8 = 0xdd;
    goto LAB_14001e156;
  }
  if ((param_9 & 0x40) == 0) {
    iVar2 = WcQuerySecurity(param_3,param_2,0x1e,&local_178,&local_160);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xf,0xa2,
                            &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                            "onecore\\base\\fs\\wci\\wcifs\\utils.c",0xea,(char)iVar2);
      }
      lVar4 = local_178;
      goto LAB_14001e674;
    }
    lVar4 = local_178;
  }
  iVar2 = FltAllocateExtraCreateParameterList(Globals,0,&local_170);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001e674;
    uVar6 = 0xa3;
    uVar8 = 0xf8;
LAB_14001e266:
    uVar5 = 5;
  }
  else {
    iVar2 = FltAllocateExtraCreateParameterFromLookasideList(Globals,&GUID_ECP_ATOMIC_CREATE,0x58);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001e674;
      uVar6 = 0xa4;
      uVar8 = 5;
      goto LAB_14001e266;
    }
    memset((void *)0x0,0,0x58);
    uRam0000000000000000 = 0x58;
    uRam0000000000000002 = 0;
    uRam0000000000000004 = 0;
    iVar2 = WcGetReparseData(param_3,param_2,0x200,local_140,local_180);
    lVar7 = local_140[0];
    if (iVar2 < 0) {
      if (iVar2 != -0x3ffffd8b) goto LAB_14001e674;
    }
    else {
      uRam0000000000000002 = 2;
      uRam0000000000000006 = (undefined2)local_180[0];
      lRam0000000000000008 = local_140[0];
    }
    iVar2 = FltQueryInformationFile(param_3,param_2,&local_b8,0x28);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001e674;
      uVar6 = 0xa5;
      uVar8 = 0x2d;
    }
    else {
      puRam0000000000000020 = &local_90;
      uStack_78 = uStack_a0;
      local_90 = local_b8;
      uStack_88 = uStack_b0;
      local_80 = local_a8;
      uRam0000000000000002 = uRam0000000000000002 | 0x610;
      iVar2 = FltInsertExtraCreateParameter(Globals,local_170,0);
      if (-1 < iVar2) {
        local_140[1] = 0x28;
        local_140[5] = 1;
        local_140[3] = 0;
        local_140[4] = 0;
        if (local_140[6] != 0) {
          local_140[5] = IoGetSilo(local_140[6]);
        }
        local_140[2] = local_170;
        uStack_f0 = local_108;
        local_e8 = local_158;
        local_d0 = 0;
        local_f8 = CONCAT44(local_f8._4_4_,0x30);
        uStack_e0 = CONCAT44(uStack_e0._4_4_,0x240);
        local_d8 = lVar4;
        iVar2 = FltCreateFileEx2(Globals,param_5,&local_148,&local_168);
        if (iVar2 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_14001e674;
          uVar6 = 0xa7;
          bVar3 = 3;
          uVar8 = 0x71;
        }
        else {
          cVar1 = FltIsEcpAcknowledged(Globals,0);
          if (cVar1 != '\0') {
            if (((local_98 & 0x800) == 0) ||
               (iVar2 = WcCopyFileCompression(param_2,param_3,local_168,param_5), -1 < iVar2)) {
              iVar2 = WcCopyFileMetaData(local_100,param_2,param_3,local_148,local_168,param_5,
                                         (-(uint)(param_8 != '\0') & 2) + 1);
              goto LAB_14001e674;
            }
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_14001e674;
            uVar6 = 0xa9;
            uVar8 = 0x95;
            goto LAB_14001e156;
          }
          iVar2 = -0x3fffff45;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_14001e674;
          uVar6 = 0xa8;
          iVar2 = -0x3fffff45;
          bVar3 = 2;
          uVar8 = 0x7f;
        }
        WPP_RECORDER_SF_sDZd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar3,10,uVar6,
                   &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                   "onecore\\base\\fs\\wci\\wcifs\\utils.c",uVar8,local_158,(char)iVar2);
        goto LAB_14001e674;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001e674;
      uVar6 = 0xa6;
      uVar8 = 0x43;
    }
LAB_14001e156:
    uVar5 = 0xf;
  }
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar5,uVar6,
                      &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                      "onecore\\base\\fs\\wci\\wcifs\\utils.c",uVar8,(char)iVar2);
LAB_14001e674:
  if (local_170 != 0) {
    FltFreeExtraCreateParameterList(Globals);
  }
  if (lVar4 != 0) {
    ExFreePoolWithTag(lVar4,0x73664357);
  }
  if (local_150 != 0) {
    ExFreePoolWithTag(local_150,0x65664357);
  }
  if (local_148 != 0) {
    FltClose();
  }
  if (local_168 != 0) {
    ObfDereferenceObject();
  }
  if (lVar7 != 0) {
    ExFreePoolWithTag(lVar7,0x69724357);
  }
  return iVar2;
}



===== WcCopyFileBasicInformation @ 14001e734 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int WcCopyFileBasicInformation
              (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              uint param_5)

{
  int iVar1;
  undefined2 uVar2;
  undefined1 auStackY_d8 [32];
  undefined1 uVar3;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  ulonglong local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_78 = 0;
  local_50 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  iVar1 = FltQueryInformationFile(param_2,param_1,&local_98,0x28);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar2 = 0x7b;
    uVar3 = 0x15;
  }
  else {
    if ((param_5 & 4) == 0) {
      local_98 = 0;
      uStack_90 = 0;
      local_88 = 0;
      uStack_80 = 0;
    }
    if ((param_5 & 8) == 0) {
      local_78 = local_78 & 0xffffffff00000000;
    }
    else {
      iVar1 = FltQueryInformationFile(param_4,param_3,&local_70,0x28);
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return iVar1;
        }
        uVar2 = 0x7c;
        uVar3 = 0x2c;
        goto LAB_14001e7d8;
      }
      local_78 = CONCAT44(local_78._4_4_,(uint)local_78 | (uint)local_50 & 0xffffbfff);
    }
    iVar1 = FltSetInformationFile(param_4,param_3,&local_98,0x28);
    if (-1 < iVar1) {
      if ((param_5 & 8) == 0) {
        return iVar1;
      }
      if ((local_78 & 0x800) == 0) {
        return iVar1;
      }
      iVar1 = WcCopyFileCompression(param_1,param_2,param_3,param_4);
      return iVar1;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar2 = 0x7d;
    uVar3 = 0x40;
  }
LAB_14001e7d8:
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xf,uVar2,
                      &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                      "onecore\\base\\fs\\wci\\wcifs\\utils.c",uVar3,(char)iVar1);
  return iVar1;
}



===== WcCopyFileCompression @ 14001e930 =====

int WcCopyFileCompression
              (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong in_stack_ffffffffffffffb8;
  ulonglong uVar2;
  undefined4 uVar3;
  undefined2 local_28 [8];
  
  local_28[0] = 0;
  uVar2 = in_stack_ffffffffffffffb8 & 0xffffffff00000000;
  iVar1 = FltFsControlFile(param_2,param_1,0x9003c,0,uVar2,local_28,2,0);
  uVar3 = (undefined4)(uVar2 >> 0x20);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar3 = 1;
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xf,0x77,
                          &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                          "onecore\\base\\fs\\wci\\wcifs\\utils.c",0x80,(char)iVar1);
    }
    local_28[0] = 1;
  }
  iVar1 = FltFsControlFile(param_4,param_3,0x9c040,local_28,CONCAT44(uVar3,2),0,0,0);
  if ((iVar1 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xf,0x78,
                        &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                        "onecore\\base\\fs\\wci\\wcifs\\utils.c",0x90,(char)iVar1);
  }
  return iVar1;
}



===== WcCopyFileMetaData @ 14001ea80 =====

int WcCopyFileMetaData(longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4,
                      longlong param_5,longlong param_6,uint param_7)

{
  int iVar1;
  undefined2 uVar2;
  undefined1 uVar3;
  
  iVar1 = 0;
  if ((((param_7 == 0) || (param_1 == 0)) || (param_4 == 0)) || ((param_5 == 0 || (param_6 == 0))))
  {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xf,0x68,
                         &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                         "onecore\\base\\fs\\wci\\wcifs\\utils.c",0xa5);
    }
    return -0x3ffffff3;
  }
  if (((param_7 & 3) == 0) ||
     (iVar1 = WcCopyFileDataStreams(param_1,param_2,param_3,param_4,param_5,param_6,(byte)param_7),
     -1 < iVar1)) {
    if ((param_7 & 0xc) == 0) {
      return iVar1;
    }
    iVar1 = WcCopyFileBasicInformation(param_2,param_3,param_5,param_6,param_7);
    if (-1 < iVar1) {
      return iVar1;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar2 = 0x6a;
    uVar3 = 200;
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar2 = 0x69;
    uVar3 = 0xb8;
  }
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xf,uVar2,
                      &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                      "onecore\\base\\fs\\wci\\wcifs\\utils.c",uVar3,(char)iVar1);
  return iVar1;
}



===== WcCreateUnionContext @ 14001ec18 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
WcCreateUnionContext(ushort *param_1,int param_2,int param_3,int param_4,undefined8 *param_5)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined8 uVar4;
  uint local_res8 [2];
  
  uVar4 = 0;
  piVar3 = (int *)ExAllocatePool2(0x40,(ulonglong)*param_1 + 0x100,0x63754357);
  if (piVar3 == (int *)0x0) {
    uVar4 = 0xc000009a;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,0xac,
                         &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                         "onecore\\base\\fs\\wci\\wcifs\\utils.c",2);
    }
  }
  else {
    RtlInitializeGenericTableAvl
              (piVar3 + 0x10,WcCompareLayerTableEntry,WcAllocateLayerTableEntry,
               WcFreeLayerTableEntry,0);
    piVar1 = piVar3 + 0x2a;
    *(int **)(piVar3 + 0x2c) = piVar1;
    *(int **)piVar1 = piVar1;
    local_res8[0] =
         (uint)SystemReserved1[0xf] ^ (uint)((ulonglong)_DAT_fffff78000000320 >> 0x20) ^
         (uint)_DAT_fffff78000000320 ^ (uint)piVar3;
    iVar2 = RtlRandomEx(local_res8);
    piVar3[6] = param_2;
    piVar3[0xe] = iVar2;
    piVar3[0xc] = 0;
    piVar3[0xd] = 0;
    *(undefined2 *)(piVar3 + 2) = 0;
    *(ushort *)((longlong)piVar3 + 10) = *param_1;
    *(int **)(piVar3 + 4) = piVar3 + 0x40;
    piVar3[9] = param_3;
    piVar3[10] = param_4;
    RtlCopyUnicodeString(piVar3 + 2,param_1);
    piVar3[8] = 0;
    *piVar3 = 0;
    LOCK();
    *piVar3 = *piVar3 + 1;
    UNLOCK();
    piVar3[0x32] = 1;
    piVar3[0x34] = 0;
    piVar3[0x35] = 0;
    piVar3[0x36] = 0;
    KeInitializeEvent(piVar3 + 0x38,1,0);
    piVar1 = piVar3 + 0x2e;
    *(int **)(piVar3 + 0x30) = piVar1;
    *(int **)piVar1 = piVar1;
    *param_5 = piVar3;
  }
  return uVar4;
}



===== WcFreeLayerTableEntry @ 14001ede0 =====

void WcFreeLayerTableEntry(undefined8 param_1,longlong param_2)

{
  WcCleanupLayer(*(longlong *)(param_2 + 0x20));
  ExFreePoolWithTag(param_2,0x796c4357);
  return;
}



===== WcFreeUnionTableEntry @ 14001ee20 =====

void WcFreeUnionTableEntry(undefined8 param_1,longlong param_2)

{
  int *piVar1;
  int *piVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  undefined8 uVar5;
  code *pcVar6;
  undefined1 *puVar7;
  int iVar8;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [56];
  
  puVar7 = auStack_58;
  piVar2 = *(int **)(param_2 + 0x20);
  iVar8 = 0;
  if (piVar2[7] - 2U < 2) {
    ExAcquireFastMutex(piVar2 + 0x32);
    puVar7 = auStack_58;
    piVar1 = piVar2 + 0x2e;
    while (*(int **)piVar1 != piVar1) {
      puVar3 = *(undefined8 **)(piVar2 + 0x30);
      if (((int *)*puVar3 != piVar1) ||
         (plVar4 = (longlong *)puVar3[1], (undefined8 *)*plVar4 != puVar3)) {
        pcVar6 = (code *)swi(0x29);
        (*pcVar6)(3);
        puVar7 = auStack_50;
        break;
      }
      *(longlong **)(piVar2 + 0x30) = plVar4;
      *plVar4 = (longlong)piVar1;
      FltDeleteContext(puVar3);
      puVar3[1] = puVar3;
      *puVar3 = puVar3;
      FltReleaseContext(puVar3);
      iVar8 = iVar8 + 1;
    }
    *(undefined8 *)(puVar7 + -8) = 0x14001eec7;
    ExReleaseFastMutex(piVar2 + 0x32);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      *(int *)(puVar7 + 0x38) = iVar8;
      *(undefined4 *)(puVar7 + 0x30) = 0x15a;
      *(char **)(puVar7 + 0x28) = "onecore\\base\\fs\\wci\\wcifs\\utils.c";
      uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
      *(undefined **)(puVar7 + 0x20) = &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids;
      *(undefined8 *)(puVar7 + -8) = 0x14001ef1d;
      WPP_RECORDER_SF_sDD(uVar5,4,9,10,*(undefined8 *)(puVar7 + 0x20),*(char **)(puVar7 + 0x28),
                          puVar7[0x30],puVar7[0x38]);
    }
  }
  *(undefined8 *)(puVar7 + -8) = 0x14001ef25;
  WcReleaseUnionContext(piVar2);
  *(undefined8 *)(puVar7 + -8) = 0x14001ef34;
  ExFreePoolWithTag(param_2,0x63754357);
  return;
}



===== WcInitializeDirectoryTable @ 14001ef5c =====

undefined8 WcInitializeDirectoryTable(longlong param_1,undefined8 param_2)

{
  char cVar1;
  longlong lVar2;
  undefined8 uVar3;
  longlong local_res8;
  
  local_res8 = param_1 + 0x48;
  uVar3 = 0;
  cVar1 = RtlCreateHashTableEx(&local_res8,param_2,0,0);
  if (cVar1 == '\0') {
    uVar3 = 0xc000009a;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xb,199,
                          &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                          "onecore\\base\\fs\\wci\\wcifs\\utils.c",0x6e,0x9a);
    }
  }
  else {
    lVar2 = ExAllocatePool2(0x40,0x68,0x796c4357);
    *(longlong *)(param_1 + 0x40) = lVar2;
    if (lVar2 == 0) {
      uVar3 = 0xc000009a;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xb,200,
                            &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                            "onecore\\base\\fs\\wci\\wcifs\\utils.c",0x79,0x9a);
      }
      RtlDeleteHashTable(local_res8);
    }
    else {
      ExInitializeResourceLite(lVar2);
    }
  }
  return uVar3;
}



===== WcInitializeSiloContext @ 14001f0a4 =====

void WcInitializeSiloContext
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined8 *param_4)

{
  memset(param_4 + 1,0,0xd0);
  *param_4 = param_1;
  *(undefined4 *)(param_4 + 0x1b) = param_2;
  *(undefined4 *)((longlong)param_4 + 0xdc) = param_3;
  RtlInitializeGenericTableAvl
            (param_4 + 0xe,WcCompareUnionTableEntry,WcAllocateUnionTableEntry,WcFreeUnionTableEntry,
             0);
  ExInitializeResourceLite(param_4 + 1);
  return;
}



===== WcInsertDirectoryTableEntry @ 14001f140 =====

ulonglong WcInsertDirectoryTableEntry(longlong param_1,longlong param_2,undefined8 param_3)

{
  undefined2 uVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined4 local_res20 [2];
  
  local_res20[0] = 0;
  uVar2 = RtlHashUnicodeString(param_2,0,0,local_res20);
  uVar5 = (ulonglong)uVar2;
  if (-1 < (int)uVar2) {
    lVar3 = ExAllocatePool2(0x100,0x30,0x74644357);
    if (lVar3 == 0) {
      uVar5 = 0xc000009a;
    }
    else {
      uVar1 = *(undefined2 *)(param_2 + 2);
      *(undefined8 *)(lVar3 + 0x20) = 0;
      *(undefined2 *)(lVar3 + 0x1a) = uVar1;
      uVar4 = WcAllocateUnicodeString(0x6e664357,(undefined2 *)(lVar3 + 0x18));
      uVar5 = uVar4 & 0xffffffff;
      if ((int)uVar4 < 0) {
        if (*(longlong *)(lVar3 + 0x20) != 0) {
          ExFreePoolWithTag(*(longlong *)(lVar3 + 0x20),0x6e664357);
        }
        ExFreePoolWithTag(lVar3,0x74644357);
      }
      else {
        RtlCopyUnicodeString(lVar3 + 0x18,param_2);
        *(undefined8 *)(lVar3 + 0x28) = param_3;
        FltAcquireResourceExclusive(*(undefined8 *)(param_1 + 0x40));
        RtlInsertEntryHashTable(param_1 + 0x48,lVar3,local_res20[0],0);
        FltReleaseResource(*(undefined8 *)(param_1 + 0x40));
      }
    }
  }
  return uVar5;
}



===== WcInsertDirectoryTableSourceList @ 14001f27c =====

ulonglong WcInsertDirectoryTableSourceList(undefined8 *param_1,longlong param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  
  uVar2 = 0;
  puVar3 = (undefined8 *)*param_1;
  do {
    if (puVar3 == param_1) {
      return uVar2;
    }
    if ((*(uint *)(puVar3 + 4) & 1) != 0) {
      uVar1 = WcInsertDirectoryTableEntry(*(longlong *)(puVar3[3] + 0x20),param_2,puVar3[3]);
      uVar2 = uVar1 & 0xffffffff;
      if ((int)uVar1 < 0) {
        return uVar2;
      }
      *(uint *)(puVar3 + 4) = *(uint *)(puVar3 + 4) & 0xfffffffe;
    }
    puVar3 = (undefined8 *)*puVar3;
  } while( true );
}



===== WcIsDirectoryEmpty @ 14001f2e0 =====

uint WcIsDirectoryEmpty(longlong param_1,longlong param_2,undefined8 param_3)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  uint *puVar4;
  byte bVar5;
  uint *puVar6;
  uint local_res20 [2];
  undefined8 local_48;
  uint *puStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  uVar3 = 0;
  local_res20[0] = 0;
  bVar1 = true;
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  puStack_40 = (uint *)0x0;
  RtlInitUnicodeString(&local_38,L"*");
  bVar5 = 1;
  puVar4 = (uint *)ExAllocatePool2(0x100,0x10000,0x65644357);
  if (puVar4 == (uint *)0x0) {
    uVar3 = 0xc000009a;
  }
  else {
    while (bVar1) {
      uVar3 = WcEnumerateDirectoryWithMerge
                        (param_1,param_2,0x3c,&local_38,0,bVar5,0x10000,(undefined8 *)puVar4,
                         local_res20);
      if ((int)uVar3 < 0) {
        if (uVar3 != 0x80000006) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0xc4,
                                &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                                "onecore\\base\\fs\\wci\\wcifs\\utils.c",0xf4,(char)uVar3);
          }
          goto LAB_14001f422;
        }
        uVar3 = 0;
        break;
      }
      puVar6 = puVar4;
LAB_14001f3aa:
      puStack_40 = puVar6 + 0x16;
      local_48._0_4_ = CONCAT22((short)puVar6[0xf],(short)puVar6[0xf]);
      cVar2 = RtlEqualUnicodeString(&local_48,&DAT_14000a4b0,1);
      if (cVar2 != '\0') {
LAB_14001f3ff:
        if (*puVar6 == 0) goto LAB_14001f40d;
        puVar6 = (uint *)((longlong)puVar6 + (ulonglong)*puVar6);
        goto LAB_14001f3aa;
      }
      cVar2 = RtlEqualUnicodeString(&local_48,&DAT_14000a4c0,1);
      if (cVar2 != '\0') goto LAB_14001f3ff;
      bVar1 = false;
LAB_14001f40d:
      bVar5 = 0;
    }
    *(bool *)param_3 = bVar1;
LAB_14001f422:
    ExFreePoolWithTag(puVar4,0x65644357);
  }
  return uVar3;
}



===== WcIsTargetPartialDirectory @ 14001f4b0 =====

uint WcIsTargetPartialDirectory
               (longlong param_1,int *param_2,wchar_t *param_3,longlong param_4,undefined8 param_5,
               undefined1 *param_6)

{
  byte bVar1;
  uint extraout_EAX;
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  byte local_res10 [8];
  undefined8 in_stack_ffffffffffffff58;
  undefined8 uVar6;
  char local_58 [8];
  longlong local_50;
  longlong local_48;
  longlong local_40;
  longlong local_38 [2];
  
  local_38[0] = 0;
  local_40 = 0;
  local_58[0] = '\0';
  uVar6 = CONCAT44((int)((ulonglong)in_stack_ffffffffffffff58 >> 0x20),0x80);
  local_50 = 0;
  local_48 = 0;
  local_res10[0] = 0;
  WcOpenAsReparsePoint
            (param_3,param_5,param_4,param_1,0x80,param_2[9],local_38,&local_40,local_res10,
             (byte *)0x0,(byte *)0x0,(undefined1 *)0x0,(byte *)0x0);
  lVar4 = 0;
  lVar5 = 0;
  if ((extraout_EAX == 0xc0000034) || (local_res10[0] == 0)) goto LAB_14001f6cd;
  if ((int)extraout_EAX < 0) {
    uVar2 = extraout_EAX;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDZd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xd,0xb5,
                 &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                 "onecore\\base\\fs\\wci\\wcifs\\utils.c",0x80,param_3,(char)extraout_EAX);
    }
    goto LAB_14001f6ff;
  }
  uVar2 = WcGetSetContextFileObject(param_1,local_40,param_2,1,uVar6,&local_48,&local_50);
  lVar5 = local_48;
  lVar4 = local_50;
  if ((int)uVar2 < 0) {
    if (uVar2 == 0xc0000275) {
LAB_14001f6cd:
      uVar2 = 0;
      goto LAB_14001f6d0;
    }
  }
  else {
    if (uVar2 == 0x104) goto LAB_14001f6cd;
    uVar3 = WcIsPlaceHolderDirectory(local_48,local_50);
    if ((((char)uVar3 != '\0') && (bVar1 = WcIsExpanded(lVar5), bVar1 == 0)) &&
       (uVar3 = WcIsSourcedStream(lVar4), (char)uVar3 != '\0')) {
      uVar2 = WcIsDirectoryEmpty(param_1,local_40,local_58);
      if ((int)uVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDZd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xd,0xb6,
                     &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                     "onecore\\base\\fs\\wci\\wcifs\\utils.c",0xaa,param_3,(char)uVar2);
        }
      }
      else {
        *param_6 = local_58[0] == '\0';
      }
      goto LAB_14001f6d7;
    }
LAB_14001f6d0:
    *param_6 = 0;
  }
LAB_14001f6d7:
  if (lVar4 != 0) {
    FltReleaseContext(lVar4);
  }
  if (lVar5 != 0) {
    FltReleaseContext(lVar5);
  }
LAB_14001f6ff:
  if (local_38[0] != 0) {
    FltClose();
  }
  if (local_40 != 0) {
    ObfDereferenceObject();
  }
  return uVar2;
}



===== WcOpenDefaultStream @ 14001f760 =====

ulonglong WcOpenDefaultStream(undefined8 param_1,longlong param_2,int *param_3,longlong *param_4,
                             longlong *param_5)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong *plVar4;
  longlong local_48;
  longlong local_40;
  longlong local_38;
  longlong local_30;
  wchar_t local_28 [8];
  
  local_40 = 0;
  local_48 = 0;
  local_28[0] = L'\0';
  local_28[1] = L'\0';
  local_28[2] = L'\0';
  local_28[3] = L'\0';
  local_28[4] = L'\0';
  local_28[5] = L'\0';
  local_28[6] = L'\0';
  local_28[7] = L'\0';
  RtlInitUnicodeString(local_28,0);
  plVar4 = &local_48;
  uVar2 = WcRelativeStreamOpen(param_1,param_2,local_28,&local_40,plVar4);
  uVar3 = uVar2 & 0xffffffff;
  if (-1 < (int)uVar2) {
    if (param_3 != (int *)0x0) {
      local_30 = 0;
      local_38 = 0;
      uVar1 = WcGetSetContextFileObject(param_1,param_2,param_3,0,plVar4,&local_38,&local_30);
      uVar3 = (ulonglong)uVar1;
      if (local_38 != 0) {
        FltReleaseContext();
      }
      if (local_30 != 0) {
        FltReleaseContext();
      }
      if ((int)uVar1 < 0) goto LAB_14001f85a;
    }
    *param_4 = local_40;
    local_40 = 0;
    *param_5 = local_48;
    local_48 = 0;
  }
LAB_14001f85a:
  if (local_40 != 0) {
    FltClose(local_40);
  }
  if (local_48 != 0) {
    ObfDereferenceObject();
  }
  return uVar3;
}



===== WcPrepareTargetDirectoryForRenameOrLink @ 14001f8a8 =====

ulonglong WcPrepareTargetDirectoryForRenameOrLink(longlong param_1,longlong param_2)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ushort uVar6;
  longlong local_res8;
  undefined8 local_38;
  longlong lStack_30;
  wchar_t local_28 [8];
  
  local_res8 = 0;
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x38);
  local_38 = 0;
  lStack_30 = 0;
  local_28[0] = L'\0';
  local_28[1] = L'\0';
  local_28[2] = L'\0';
  local_28[3] = L'\0';
  local_28[4] = L'\0';
  local_28[5] = L'\0';
  local_28[6] = L'\0';
  local_28[7] = L'\0';
  uVar4 = WcReopenFile(*(undefined8 *)(param_2 + 0x18),
                       *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x28),&local_res8,0);
  uVar5 = uVar4 & 0xffffffff;
  if (-1 < (int)uVar4) {
    lStack_30 = lVar1 + 0x14;
    uVar6 = *(ushort *)(lVar1 + 0x10);
    if (*(short *)(lVar1 + 0x12 + (ulonglong)(uVar6 >> 1) * 2) == 0x5c) {
      uVar6 = uVar6 - 2;
    }
    local_38 = CONCAT62(CONCAT42(local_38._4_4_,*(undefined2 *)(lVar1 + 0x10)),uVar6);
    uVar2 = FltParseFileName(&local_38,0,0,local_28);
    uVar5 = (ulonglong)uVar2;
    if (-1 < (int)uVar2) {
      uVar5 = WcPartiallyExpandDirectory
                        (param_1,*(longlong *)(param_2 + 0x18),
                         *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x28),local_res8,'\x01',
                         local_28);
      iVar3 = (int)uVar5;
      uVar5 = uVar5 & 0xffffffff;
      if (((-1 < iVar3) || (iVar3 == -0x3ffffdd3)) || (iVar3 == -0x3fffffcc)) {
        uVar2 = WcPrepareTargetForRenameOrLink
                          (param_1,*(longlong *)(param_2 + 0x18),
                           *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x28),local_res8,local_28);
        uVar5 = (ulonglong)uVar2;
        if (-1 < (int)uVar2) {
          uVar5 = 0;
        }
      }
    }
  }
  if (local_res8 != 0) {
    FltClose();
  }
  return uVar5;
}



===== WcPrepareTargetForRenameOrLink @ 14001f9ec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint WcPrepareTargetForRenameOrLink
               (longlong param_1,longlong param_2,longlong param_3,undefined8 param_4,
               wchar_t *param_5)

{
  int iVar1;
  uint *puVar2;
  bool bVar3;
  uint uVar4;
  int *piVar5;
  undefined1 auStackY_138 [32];
  char local_f8 [8];
  undefined4 local_f0;
  undefined4 local_ec;
  undefined8 local_e8;
  wchar_t *local_e0;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined1 local_a8 [56];
  byte local_70;
  int local_6c;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_138;
  local_ec = 0;
  local_d4 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  memset(local_a8,0,0x48);
  local_f8[0] = '\0';
  iVar1 = *(int *)(*(longlong *)(param_1 + 0x10) + 0x20);
  if ((((iVar1 != 10) && (iVar1 != 0x41)) ||
      (puVar2 = *(uint **)(*(longlong *)(param_1 + 0x10) + 0x38), (char)*puVar2 == '\0')) ||
     (bVar3 = true, (*puVar2 & 2) == 0)) {
    bVar3 = false;
  }
  local_f0 = 0x30;
  local_d8 = 0x200;
  local_e0 = param_5;
  local_d0 = 0;
  uStack_c8 = 0;
  local_e8 = param_4;
  uVar4 = FltQueryInformationByName(Globals,param_2,&local_f0,&local_c0);
  if (uVar4 == 0xc0000034) {
    uVar4 = 0;
  }
  else if ((int)uVar4 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xd,0xc1,
                          &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                          "onecore\\base\\fs\\wci\\wcifs\\utils.c",0xfd,(char)uVar4);
    }
  }
  else if (local_6c == -0x5fffffe1) {
    uVar4 = WcDeleteTombstone(param_1,param_2,*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x28),
                              param_4,(longlong)param_5);
  }
  else if ((bVar3) && ((local_70 & 0x10) != 0)) {
    piVar5 = (int *)WcGetUnionContext(param_1,param_2,param_3);
    if (piVar5 == (int *)0x0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,0xd,0xc2,
                           &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                           "onecore\\base\\fs\\wci\\wcifs\\utils.c",0x15);
      }
      uVar4 = 0;
    }
    else {
      uVar4 = WcIsTargetPartialDirectory(param_2,piVar5,param_5,param_3,param_4,local_f8);
      if (((-1 < (int)uVar4) && (local_f8[0] != '\0')) &&
         ((uVar4 = 0xc0000101, (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED
          && (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)))) {
        WPP_RECORDER_SF_sDd(_WcVerboseRecorder,5,0xd,0xc3,
                            &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                            "onecore\\base\\fs\\wci\\wcifs\\utils.c",0x30,1);
      }
      WcReleaseUnionContext(piVar5);
    }
  }
  return uVar4;
}



===== WcProcessGetUnions @ 14001fca4 =====

int WcProcessGetUnions(ulonglong param_1,uint param_2,longlong param_3,uint *param_4)

{
  longlong lVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  longlong *plVar5;
  undefined8 uVar6;
  longlong lVar7;
  undefined2 uVar8;
  longlong lVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  ulonglong local_res8;
  uint local_res10;
  longlong local_res18;
  uint *local_res20;
  undefined1 uVar13;
  uint local_94;
  uint local_90 [2];
  longlong local_88;
  undefined8 local_80;
  longlong local_78;
  longlong local_70;
  longlong local_68;
  longlong local_60;
  longlong local_58;
  undefined8 local_50 [2];
  
  iVar12 = 0;
  lVar1 = *(longlong *)(param_1 + 8);
  local_68 = 0;
  local_78 = 0;
  lVar7 = 0;
  local_70 = 0;
  lVar9 = 0;
  local_60 = 0;
  local_80 = 0;
  local_88 = 0;
  local_58 = 0;
  bVar2 = false;
  local_50[0] = 0;
  local_res8 = param_1;
  local_res10 = param_2;
  local_res18 = param_3;
  local_res20 = param_4;
  if ((*(uint *)(param_1 + 4) & 5) == 0) {
    if ((*(uint *)(param_1 + 4) & 2) == 0) {
      return -0x3ffffff3;
    }
    if (lVar1 == 0) {
      local_80 = PsGetCurrentSilo();
      cVar3 = PsIsHostSilo(local_80);
      if (cVar3 != '\0') {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xe,0x14,
                             &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                             "onecore\\base\\fs\\wci\\wcifs\\utils.c",7);
        }
        iVar4 = -0x3ffffff3;
        goto LAB_1400201d6;
      }
LAB_14001fe7e:
      iVar4 = PsGetSiloContext(local_80,DAT_14000f250,&local_58);
      if (iVar4 < 0) goto LAB_1400201d6;
      lVar7 = local_58 + 0x70;
      lVar9 = local_58 + 8;
LAB_14001feae:
      uVar11 = 0xc;
      local_94 = 0xc;
      if ((*(uint *)(param_1 + 4) & 6) == 0) {
        local_res8 = local_res8 & 0xffffffff00000000;
        local_94 = 0;
        WcpCalculateUnionContextSize
                  (*(longlong *)(local_88 + 0x38),(int *)&local_res8,(int *)&local_94);
        uVar11 = (int)local_res8 + 0xc;
        iVar12 = 1;
        local_94 = local_94 + 0xc;
      }
      else {
        FltAcquireResourceExclusive(lVar9);
        bVar2 = true;
        plVar5 = (longlong *)RtlEnumerateGenericTableAvl(lVar7,1);
        if (plVar5 != (longlong *)0x0) {
          uVar10 = 0xc;
          do {
            local_94 = 0;
            local_90[0] = 0;
            WcpCalculateUnionContextSize(*plVar5,(int *)&local_94,(int *)local_90);
            uVar11 = uVar11 + local_94;
            uVar10 = uVar10 + local_90[0];
            iVar12 = iVar12 + 1;
            plVar5 = (longlong *)RtlEnumerateGenericTableAvl(lVar7,0);
          } while (plVar5 != (longlong *)0x0);
          param_1 = local_res8;
          local_94 = uVar10;
        }
      }
      lVar1 = local_res18;
      if (local_res10 < uVar11) {
        iVar4 = -0x7ffffffb;
        *local_res20 = uVar11;
      }
      else {
        local_90[0] = iVar12 * 0x10 + 0xc;
        *(int *)(local_res18 + 8) = iVar12;
        local_res8 = local_res8 & 0xffffffff00000000;
        if ((*(uint *)(param_1 + 4) & 6) == 0) {
          WcpFillGetUnionsResponseBuffer
                    (*(longlong *)(local_88 + 0x38),&local_94,local_90,(uint *)&local_res8,
                     local_res18);
        }
        else {
          uVar6 = 1;
          while (plVar5 = (longlong *)RtlEnumerateGenericTableAvl(lVar7,uVar6),
                plVar5 != (longlong *)0x0) {
            WcpFillGetUnionsResponseBuffer(*plVar5,&local_94,local_90,(uint *)&local_res8,lVar1);
            uVar6 = 0;
          }
        }
        *local_res20 = local_94;
      }
      if (bVar2) {
        FltReleaseResource(lVar9);
      }
      goto LAB_1400201d6;
    }
    cVar3 = ObIsKernelHandle(lVar1);
    iVar4 = ObReferenceObjectByHandle
                      (lVar1,4,*(undefined8 *)PsJobType_exref,cVar3 == '\0',&local_60,0);
    if (iVar4 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400201d6;
      uVar8 = 0x12;
      uVar13 = 0xf1;
    }
    else {
      iVar4 = PsGetJobSilo(local_60,&local_80);
      if (-1 < iVar4) goto LAB_14001fe7e;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400201d6;
      uVar8 = 0x13;
      uVar13 = 0xf9;
    }
  }
  else {
    cVar3 = ObIsKernelHandle(lVar1);
    iVar4 = IoConvertFileHandleToKernelHandle(lVar1,cVar3 == '\0',0,0,local_50);
    if (iVar4 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400201d6;
      uVar8 = 0xe;
      uVar13 = 0xae;
    }
    else {
      iVar4 = ObReferenceObjectByHandle
                        (local_50[0],0,*(undefined8 *)IoFileObjectType_exref,0,&local_68,0);
      if (iVar4 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400201d6;
        uVar8 = 0xf;
        uVar13 = 0xb6;
      }
      else {
        iVar4 = FltGetVolumeFromFileObject(Globals,local_68,&local_78);
        if (iVar4 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1400201d6;
          uVar8 = 0x10;
          uVar13 = 0xbd;
        }
        else {
          iVar4 = FltGetVolumeInstanceFromName(Globals,local_78,0,&local_70);
          if (-1 < iVar4) {
            iVar4 = FltGetInstanceContext(local_70,&local_88);
            if (iVar4 < 0) goto LAB_1400201d6;
            if ((*(uint *)(param_1 + 4) & 4) == 0) {
              if (((*(uint *)(param_1 + 4) & 1) != 0) && (*(longlong *)(local_88 + 0x38) == 0)) {
                *param_4 = 0;
                goto LAB_1400201d6;
              }
            }
            else {
              lVar7 = local_88 + 0xb0;
              lVar9 = local_88 + 0x48;
            }
            goto LAB_14001feae;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1400201d6;
          uVar8 = 0x11;
          uVar13 = 0xc4;
        }
      }
    }
  }
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xe,uVar8,
                      &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                      "onecore\\base\\fs\\wci\\wcifs\\utils.c",uVar13,(char)iVar4);
LAB_1400201d6:
  if (local_78 != 0) {
    FltObjectDereference();
  }
  if (local_70 != 0) {
    FltObjectDereference();
  }
  if (local_68 != 0) {
    ObfDereferenceObject();
  }
  if (local_60 != 0) {
    ObfDereferenceObject();
  }
  if (local_88 != 0) {
    FltReleaseContext();
  }
  if (local_58 != 0) {
    PsDereferenceSiloContext();
  }
  return iVar4;
}



===== WcQuerySecurity @ 140020274 =====

int WcQuerySecurity(undefined8 param_1,undefined8 param_2,undefined4 param_3,longlong *param_4,
                   undefined4 *param_5)

{
  int iVar1;
  longlong lVar2;
  undefined8 in_stack_ffffffffffffffb8;
  undefined4 uVar3;
  undefined4 local_28 [4];
  
  local_28[0] = 0;
  uVar3 = (undefined4)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);
  iVar1 = FltQuerySecurityObject();
  if (iVar1 == -0x3fffffdd) {
    lVar2 = ExAllocatePool2(0x100,local_28[0],0x73664357);
    if (lVar2 == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xf,0x75,
                            &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                            "onecore\\base\\fs\\wci\\wcifs\\utils.c",0x2c,(char)local_28[0]);
      }
      iVar1 = -0x3fffffe9;
    }
    else {
      iVar1 = FltQuerySecurityObject
                        (param_1,param_2,param_3,lVar2,CONCAT44(uVar3,local_28[0]),local_28);
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xf,0x76,
                              &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                              "onecore\\base\\fs\\wci\\wcifs\\utils.c",0x3b,(char)iVar1);
        }
        ExFreePoolWithTag(lVar2,0x73664357);
      }
      else {
        *param_4 = lVar2;
        *param_5 = local_28[0];
      }
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xf,0x74,
                          &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                          "onecore\\base\\fs\\wci\\wcifs\\utils.c",0x1c,(char)iVar1);
    }
    if (iVar1 == 0) {
      iVar1 = -0x3fffffff;
    }
  }
  return iVar1;
}



===== WcRelativeStreamOpen @ 140020470 =====

ulonglong WcRelativeStreamOpen
                    (undefined8 param_1,undefined8 param_2,wchar_t *param_3,longlong *param_4,
                    longlong *param_5)

{
  uint uVar1;
  ulonglong uVar2;
  longlong local_res18 [2];
  undefined8 in_stack_ffffffffffffff08;
  undefined4 uVar3;
  longlong local_98 [8];
  undefined8 local_58;
  longlong lStack_50;
  wchar_t *local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong uStack_30;
  
  uVar3 = (undefined4)((ulonglong)in_stack_ffffffffffffff08 >> 0x20);
  local_38 = 0;
  uStack_30 = uStack_30 & 0xffffffff00000000;
  local_98[7] = local_98[7] & 0xffffffffffff0000;
  local_res18[0] = 0;
  local_98[0] = 0;
  local_98[1] = 0;
  local_98[2] = 0;
  local_58 = 0;
  lStack_50 = 0;
  local_48 = (wchar_t *)0x0;
  uStack_40 = 0;
  local_98[3] = 0;
  local_98[4] = 0;
  local_98[5] = 0;
  local_98[6] = 0;
  uVar2 = WcReopenFile(param_1,param_2,local_res18,local_98);
  uVar2 = uVar2 & 0xffffffff;
  if (*param_3 == L'\0') {
    *param_4 = local_res18[0];
    local_res18[0] = 0;
    if (param_5 != (longlong *)0x0) {
      *param_5 = local_98[0];
      return uVar2;
    }
  }
  else {
    local_98[7] = 0;
    local_98[4] = 0;
    local_98[3] = 0x28;
    local_98[5] = 0;
    local_98[6] = 0;
    local_98[7] = IoGetSilo(param_2);
    lStack_50 = local_res18[0];
    local_58 = CONCAT44(local_58._4_4_,0x30);
    uStack_40 = CONCAT44(uStack_40._4_4_,0x200);
    local_38 = 0;
    uStack_30 = 0;
    local_48 = param_3;
    uVar1 = FltCreateFileEx2(Globals,param_1,param_4,param_5,CONCAT44(uVar3,0x80000000),&local_58,
                             local_98 + 1,0,0,7,1,0x202028,0,0,0,local_98 + 3);
    uVar2 = (ulonglong)uVar1;
    if (((int)uVar1 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_sDZd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0x67,
                 &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                 "onecore\\base\\fs\\wci\\wcifs\\utils.c",0x44,param_3,(char)uVar1);
    }
    if (local_res18[0] != 0) {
      FltClose();
    }
  }
  if (local_98[0] != 0) {
    ObfDereferenceObject();
  }
  return uVar2;
}



===== WcRemoveUnionContext @ 14002066c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong WcRemoveUnionContext(int *param_1,uint param_2)

{
  ushort *puVar1;
  ushort uVar2;
  ushort uVar3;
  char cVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  uint uVar7;
  byte bVar8;
  undefined2 uVar9;
  bool bVar10;
  undefined1 auStackY_1d8 [32];
  undefined1 uVar11;
  uint uVar12;
  longlong local_198;
  int *local_190;
  longlong local_188;
  undefined8 local_180;
  ushort *puStack_178;
  undefined8 local_170;
  int *piStack_168;
  undefined8 local_160;
  ushort *puStack_158;
  undefined4 local_150;
  undefined4 uStack_14c;
  undefined8 uStack_148;
  undefined8 local_140;
  undefined8 uStack_138;
  int local_128 [3];
  undefined4 uStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_1d8;
  local_188 = 0;
  local_198 = 0;
  local_128[1] = 0;
  local_150 = 0;
  uStack_14c = 0;
  uStack_148 = (ushort *)0x0;
  local_160 = 0;
  puStack_158 = (ushort *)0x0;
  local_140 = 0;
  uStack_138 = 0;
  local_180 = 0;
  puStack_178 = (ushort *)0x0;
  local_170 = 0;
  piStack_168 = (int *)0x0;
  memset(local_128,0,0x104);
  local_190 = local_128;
  RtlInitUnicodeString(&local_140,L"\\");
  if (param_2 < 0xa0) {
    uVar5 = 0xc000000d;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140020c13;
    uVar12 = 0xc000000d;
    uVar9 = 0x4b;
    uVar11 = 0xf6;
  }
  else if (param_2 < (uint)param_1[1]) {
    uVar5 = 0xc000000d;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140020c13;
    uVar12 = 0xc000000d;
    uVar9 = 0x4c;
    uVar11 = 0xfd;
  }
  else if (*param_1 == 0xa0) {
    uVar2 = *(ushort *)(param_1 + 0x1c);
    if (uVar2 < 0x65) {
      if (*(longlong *)(param_1 + 0x1e) == 0) {
        if ((param_1[0x24] & 1U) == 0) {
          uVar5 = 0xc000000d;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_140020c13;
          uVar12 = 0xc000000d;
          uVar9 = 0x50;
          uVar11 = 0x1a;
        }
        else {
          piStack_168 = param_1 + 3;
          uVar12 = param_1[0x25];
          local_170._0_4_ = CONCAT22(uVar2,uVar2);
          uVar7 = *(ushort *)(param_1 + 0x26) + uVar12;
          if ((uVar7 < uVar12) || (param_2 < uVar7)) {
            uVar5 = 0xc000000d;
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_140020c13;
            uVar12 = 0xc000000d;
            uVar9 = 0x51;
            uVar11 = 0x28;
          }
          else {
            puVar1 = (ushort *)((longlong)param_1 + (ulonglong)uVar12);
            uVar5 = WcValidateContainerRootId(puVar1,(uint)*(ushort *)(param_1 + 0x26));
            uVar12 = (uint)uVar5;
            uVar5 = uVar5 & 0xffffffff;
            if ((int)uVar12 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
              goto LAB_140020c13;
              uVar9 = 0x52;
              uVar11 = 0x31;
            }
            else {
              uVar2 = puVar1[1];
              puStack_158 = puVar1 + 3;
              local_160._0_4_ = CONCAT22(uVar2,uVar2);
              uVar3 = puVar1[2];
              local_150 = CONCAT22(uVar3,uVar3);
              local_180._0_4_ = CONCAT22(uVar3,uVar3 - uVar2);
              puStack_178 = puStack_158 + (uVar2 >> 1);
              uStack_148 = puStack_158;
              cVar4 = RtlEqualUnicodeString
                                (&local_180,&local_140,CONCAT71((uint7)(byte)(uVar2 >> 9),1));
              if (cVar4 == '\0') {
                WcGetInstanceFromVolumeName(&local_160,&local_170,&local_188);
                uVar12 = FltGetInstanceContext(local_188,&local_198);
                uVar5 = (ulonglong)uVar12;
                if ((int)uVar12 < 0) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                  goto LAB_140020c13;
                  uVar9 = 0x54;
                  uVar11 = 0x52;
                }
                else {
                  if (*(int *)(local_198 + 8) != 2) {
                    uVar5 = 0xc00000bb;
                    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                    goto LAB_140020c13;
                    uVar9 = 0x55;
                    uVar11 = 0x58;
                    bVar8 = 2;
LAB_1400209e8:
                    WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar8,0xb,uVar9,
                                       &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                                       "onecore\\base\\fs\\wci\\wcifs\\utils.c",uVar11);
                    goto LAB_140020c13;
                  }
                  if (*(longlong *)(local_198 + 0x38) == 0) {
                    if (*(int *)(local_198 + 0x40) == 0) {
                      uVar5 = 0;
                      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                      goto LAB_140020c13;
                      uVar9 = 0x57;
                      uVar11 = 0x69;
                      bVar8 = 4;
                      goto LAB_1400209e8;
                    }
                    LOCK();
                    bVar10 = *(int *)(local_198 + 0x18) == 0;
                    if (bVar10) {
                      *(int *)(local_198 + 0x18) = 0;
                    }
                    UNLOCK();
                    if (bVar10) {
                      local_128[2] = local_150;
                      uStack_11c = uStack_14c;
                      uStack_118 = (undefined4)uStack_148;
                      uStack_114 = uStack_148._4_4_;
                      FltAcquireResourceExclusive(local_198 + 0x48);
                      puVar6 = (undefined8 *)
                               RtlLookupElementGenericTableAvl(local_198 + 0xb0,&local_190);
                      if (puVar6 == (undefined8 *)0x0) {
                        uVar5 = 0xc000000d;
                        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xb,0x59,
                                              &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                                              "onecore\\base\\fs\\wci\\wcifs\\utils.c",0x8b,0xd);
                        }
                      }
                      else {
                        local_190 = (int *)*puVar6;
                        LOCK();
                        *local_190 = *local_190 + 1;
                        UNLOCK();
                        RtlDeleteElementGenericTableAvl(local_198 + 0xb0,puVar6);
                        local_190[8] = local_190[8] | 0x20;
                        WcReleaseUnionContext(local_190);
                        *(int *)(local_198 + 0x40) = *(int *)(local_198 + 0x40) + -1;
                      }
                      FltReleaseResource(local_198 + 0x48);
                      goto LAB_140020c13;
                    }
                    uVar5 = 0xc00000bb;
                    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                    goto LAB_140020c13;
                    uVar12 = 0xc00000bb;
                    uVar9 = 0x58;
                    uVar11 = 0x70;
                  }
                  else {
                    uVar5 = 0xc00000bb;
                    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                    goto LAB_140020c13;
                    uVar12 = 0xc00000bb;
                    uVar9 = 0x56;
                    uVar11 = 99;
                  }
                }
              }
              else {
                uVar5 = 0xc000000d;
                if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                goto LAB_140020c13;
                uVar12 = 0xc000000d;
                uVar9 = 0x53;
                uVar11 = 0x47;
              }
            }
          }
        }
      }
      else {
        uVar5 = 0xc000000d;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140020c13;
        uVar12 = 0xc000000d;
        uVar9 = 0x4f;
        uVar11 = 0x13;
      }
    }
    else {
      uVar5 = 0xc000000d;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140020c13;
      uVar12 = 0xc000000d;
      uVar9 = 0x4e;
      uVar11 = 0xb;
    }
  }
  else {
    uVar5 = 0xc000000d;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140020c13;
    uVar12 = 0xc000000d;
    uVar9 = 0x4d;
    uVar11 = 4;
  }
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xb,uVar9,
                      &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                      "onecore\\base\\fs\\wci\\wcifs\\utils.c",uVar11,(char)uVar12);
LAB_140020c13:
  if (local_198 != 0) {
    FltReleaseContext();
  }
  if (local_188 != 0) {
    FltObjectDereference();
  }
  return uVar5;
}



===== WcReopenFile @ 140020c70 =====

ulonglong WcReopenFile(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 in_stack_fffffffffffffed8;
  undefined4 uVar5;
  undefined8 uVar4;
  undefined4 local_c8 [2];
  longlong local_c0;
  wchar_t local_b8 [4];
  longlong lStack_b0;
  undefined4 local_a8 [2];
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 *puStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  ulonglong local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  wchar_t *local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  ulonglong uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  
  uVar5 = (undefined4)((ulonglong)in_stack_fffffffffffffed8 >> 0x20);
  local_a0 = 0;
  local_a8[0] = 0;
  local_c0 = 0;
  local_c8[0] = 0;
  local_40 = 0;
  uStack_38 = uStack_38 & 0xffffffff00000000;
  local_68 = local_68 & 0xffffffffffff0000;
  local_b8[0] = L'\0';
  local_b8[1] = L'\0';
  local_b8[2] = L'\0';
  local_b8[3] = L'\0';
  lStack_b0 = 0;
  local_98 = 0;
  puStack_90 = (undefined8 *)0x0;
  local_30 = 0;
  uStack_28 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = (wchar_t *)0x0;
  uStack_48 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_78 = 0;
  uStack_70 = 0;
  RtlInitUnicodeString(local_b8,0);
  uVar4 = CONCAT44(uVar5,6);
  uVar1 = FltQueryInformationFile(param_1,param_2,&local_a0,8,uVar4,local_a8);
  uVar5 = (undefined4)((ulonglong)uVar4 >> 0x20);
  uVar3 = (ulonglong)uVar1;
  if (-1 < (int)uVar1) {
    uVar1 = FltGetVolumeFromInstance(param_1,&local_c0);
    uVar3 = (ulonglong)uVar1;
    if (-1 < (int)uVar1) {
      uVar1 = FltGetVolumeName(local_c0,0,local_c8);
      uVar3 = (ulonglong)uVar1;
      if (((uVar1 + 0x80000000 & 0x80000000) != 0) || (uVar1 == 0xc0000023)) {
        uVar1 = RtlUShortAdd((ushort)local_c8[0],10,(ushort *)(local_b8 + 1));
        uVar3 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          uVar2 = WcAllocateUnicodeString(0x6e664357,local_b8);
          uVar3 = uVar2 & 0xffffffff;
          if (-1 < (int)uVar2) {
            uVar1 = FltGetVolumeName(local_c0,local_b8,local_c8);
            uVar3 = (ulonglong)uVar1;
            if (-1 < (int)uVar1) {
              uVar1 = RtlAppendUnicodeToString(local_b8,L"\\");
              uVar3 = (ulonglong)uVar1;
              if (-1 < (int)uVar1) {
                puStack_90 = &local_a0;
                local_98 = CONCAT44(local_98._4_4_,0x80008);
                uVar1 = RtlAppendUnicodeStringToString(local_b8,&local_98);
                uVar3 = (ulonglong)uVar1;
                if (-1 < (int)uVar1) {
                  local_68 = 0;
                  uStack_80 = 0;
                  local_88 = 0x28;
                  local_78 = 0;
                  uStack_70 = 0;
                  local_68 = IoGetSilo(param_2);
                  uStack_58 = 0;
                  local_50 = local_b8;
                  local_60 = CONCAT44(local_60._4_4_,0x30);
                  uStack_48 = CONCAT44(uStack_48._4_4_,0x200);
                  local_40 = 0;
                  uStack_38 = 0;
                  uVar1 = FltCreateFileEx2(Globals,param_1,param_3,param_4,
                                           CONCAT44(uVar5,0x80000000),&local_60,&local_30,0,0,7,1,
                                           0x202028,0,0,0x800,&local_88);
                  uVar3 = (ulonglong)uVar1;
                  if (((int)uVar1 < 0) &&
                     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                    WPP_RECORDER_SF_sDZd
                              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0x66,
                               &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                               "onecore\\base\\fs\\wci\\wcifs\\utils.c",0xac,local_b8,(char)uVar1);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if (local_c0 != 0) {
    FltObjectDereference();
  }
  if (lStack_b0 != 0) {
    ExFreePoolWithTag(lStack_b0,0x6e664357);
  }
  return uVar3;
}



===== WcSetDispositionFile @ 140020f98 =====

int WcSetDispositionFile(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined1 local_res18 [8];
  longlong local_res20;
  
  local_res20 = 0;
  local_res18[0] = 1;
  iVar1 = FltAllocateCallbackData(param_1,param_2,&local_res20);
  if (-1 < iVar1) {
    *(undefined1 *)(*(longlong *)(local_res20 + 0x10) + 4) = 6;
    *(undefined1 *)(*(longlong *)(local_res20 + 0x10) + 5) = 4;
    *(undefined1 *)(*(longlong *)(local_res20 + 0x10) + 6) = 0x40;
    *(undefined4 *)(*(longlong *)(local_res20 + 0x10) + 0x18) = 1;
    *(undefined4 *)(*(longlong *)(local_res20 + 0x10) + 0x20) = 0xd;
    *(undefined8 *)(*(longlong *)(local_res20 + 0x10) + 0x28) = 0;
    *(undefined8 *)(*(longlong *)(local_res20 + 0x10) + 0x30) = 0;
    *(undefined1 **)(*(longlong *)(local_res20 + 0x10) + 0x38) = local_res18;
    FltPerformSynchronousIo(local_res20);
    iVar1 = *(int *)(local_res20 + 0x18);
  }
  if (local_res20 != 0) {
    FltFreeCallbackData();
  }
  return iVar1;
}



===== WcSetFileAttributes @ 14002107c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int WcSetFileAttributes(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined2 uVar2;
  undefined1 auStackY_78 [32];
  undefined1 uVar3;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  iVar1 = FltQueryInformationFile(param_2,param_1,&local_38,0x28);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar2 = 0x79;
    uVar3 = 0xc4;
  }
  else {
    local_18 = local_18 | 1;
    local_38 = 0;
    uStack_30 = 0;
    local_28 = 0;
    uStack_20 = 0;
    iVar1 = FltSetInformationFile(param_2,param_1,&local_38,0x28);
    if (-1 < iVar1) {
      return iVar1;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar2 = 0x7a;
    uVar3 = 0xd8;
  }
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xf,uVar2,
                      &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                      "onecore\\base\\fs\\wci\\wcifs\\utils.c",uVar3,(char)iVar1);
  return iVar1;
}



===== WcSetPlaceHolderFlags @ 1400211c4 =====

int WcSetPlaceHolderFlags(undefined8 param_1,longlong param_2,longlong param_3,uint param_4)

{
  longlong lVar1;
  undefined2 uVar2;
  longlong lVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  bool bVar8;
  int local_res20;
  undefined8 local_48;
  longlong lStack_40;
  
  lVar3 = *(longlong *)(param_3 + 0x40);
  iVar6 = 0;
  if ((param_4 & *(uint *)(lVar3 + 0xc)) != param_4) {
    lVar1 = param_3 + 8;
    ExAcquireFastMutex(lVar1);
    *(uint *)(lVar3 + 0xc) = *(uint *)(lVar3 + 0xc) | param_4;
    local_res20 = *(int *)(lVar3 + 0xc);
    ExReleaseFastMutex(lVar1);
    bVar8 = *(char *)(param_2 + 0x4b) == '\0';
    if (bVar8) {
      *(undefined1 *)(param_2 + 0x4b) = 1;
    }
    iVar5 = WcSuppressTimestamps(param_1,param_2,'\x01');
    iVar6 = 0;
    for (uVar7 = 0; uVar7 < 5; uVar7 = uVar7 + 1) {
      puVar4 = *(undefined4 **)(param_3 + 0x40);
      iVar6 = FltTagFile(param_1,param_2,*puVar4,0,puVar4 + 2,*(undefined2 *)(puVar4 + 1));
      if (iVar6 < 0) {
        lStack_40 = *(longlong *)(param_3 + 0x40) + 0x22;
        uVar2 = *(undefined2 *)(*(longlong *)(param_3 + 0x40) + 0x20);
        local_48 = (ulonglong)CONCAT22(uVar2,uVar2);
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDdZ
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0x91,
                     &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                     "onecore\\base\\fs\\wci\\wcifs\\utils.c",0x69,(char)iVar6,(wchar_t *)&local_48)
          ;
        }
        break;
      }
      if (*(int *)(lVar3 + 0xc) == local_res20) break;
      ExAcquireFastMutex(lVar1);
      local_res20 = *(int *)(lVar3 + 0xc);
      ExReleaseFastMutex(lVar1);
    }
    if (-1 < iVar5) {
      WcSuppressTimestamps(param_1,param_2,'\0');
    }
    if (bVar8) {
      *(undefined1 *)(param_2 + 0x4b) = 0;
    }
  }
  return iVar6;
}



===== WcSetUnion @ 140021394 =====

ulonglong WcSetUnion(int *param_1,uint param_2)

{
  uint uVar1;
  int *piVar2;
  ulonglong uVar3;
  uint uVar4;
  undefined2 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  
  if (param_2 < 0xa8) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000000d;
    }
    uVar5 = 0x15;
    uVar6 = 0x9b;
  }
  else if (param_2 < (uint)param_1[1]) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000000d;
    }
    uVar5 = 0x16;
    uVar6 = 0xa2;
  }
  else {
    if (*param_1 == 1) {
      piVar2 = (int *)ExAllocatePool2(0x100,param_2,0x746d4357);
      uVar4 = 0;
      if (piVar2 != (int *)0x0) {
        *piVar2 = 0xa8;
        if (*(ushort *)(param_1 + 0x1c) < 0x65) {
          uVar1 = param_1[0x1e];
          if (((((uVar1 & 0xfff0000) == 0) && (2 < uVar1)) && ((uVar1 & 0xc0000000) != 0x40000000))
             && ((((uVar1 >> 0x1d & 1) != 0 && (uVar1 & 0x30000000) != 0x30000000 &&
                  (uVar1 != 0xa000000c)) && (uVar1 != 0xa0000003)))) {
            *(ushort *)(piVar2 + 0x1c) = *(ushort *)(param_1 + 0x1c);
            memmove(piVar2 + 3,param_1 + 3,(ulonglong)*(ushort *)(param_1 + 0x1c));
            piVar2[0x1e] = param_1[0x1f];
            *(undefined8 *)(piVar2 + 0x20) = *(undefined8 *)(param_1 + 0x20);
            piVar2[0x1d] = param_1[0x1d];
            piVar2[2] = param_1[2];
            piVar2[1] = param_2;
            memmove(piVar2 + 0x22,param_1 + 0x22,(ulonglong)(param_2 - 0x88));
            if (piVar2[2] != 0) {
              do {
                uVar4 = uVar4 + 1;
              } while (uVar4 < (uint)piVar2[2]);
            }
            uVar3 = WcSetUnionContext(piVar2,param_2,param_1[0x1e]);
            uVar3 = uVar3 & 0xffffffff;
          }
          else {
            uVar3 = 0xc000000d;
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_sDDd
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),(ulonglong)uVar1,0xb,0x1a,
                         &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                         "onecore\\base\\fs\\wci\\wcifs\\utils.c",199,(char)uVar1,0xd);
            }
          }
        }
        else {
          uVar3 = 0xc000000d;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xb,0x19,
                                &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                                "onecore\\base\\fs\\wci\\wcifs\\utils.c",0xba,0xd);
          }
        }
        ExFreePoolWithTag(piVar2,0x746d4357);
        return uVar3;
      }
      uVar3 = 0xc000009a;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0xc000009a;
      }
      uVar7 = 0x9a;
      uVar5 = 0x18;
      uVar6 = 0xb1;
      uVar4 = 0xe;
      goto LAB_1400213e8;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000000d;
    }
    uVar5 = 0x17;
    uVar6 = 0xa9;
  }
  uVar7 = 0xd;
  uVar3 = 0xc000000d;
  uVar4 = 0xb;
LAB_1400213e8:
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar4,uVar5,
                      &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                      "onecore\\base\\fs\\wci\\wcifs\\utils.c",uVar6,uVar7);
  return uVar3;
}



===== WcSetUnionContext @ 1400216a0 =====

ulonglong WcSetUnionContext(int *param_1,uint param_2,int param_3)

{
  ushort *puVar1;
  ushort uVar2;
  ushort uVar3;
  longlong *plVar4;
  undefined8 uVar5;
  code *pcVar6;
  char cVar7;
  uint uVar8;
  int iVar9;
  ulonglong uVar10;
  undefined8 *puVar11;
  longlong lVar12;
  longlong lVar13;
  uint uVar14;
  longlong *plVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  undefined1 *puVar18;
  ulonglong uVar19;
  undefined2 uVar20;
  int *piVar21;
  bool bVar22;
  char local_res20 [8];
  undefined1 auStackY_178 [8];
  undefined1 auStackY_170 [24];
  undefined1 uVar23;
  undefined1 uVar24;
  char local_128 [8];
  undefined8 *local_120;
  longlong local_118;
  char local_110;
  longlong local_108;
  longlong local_100;
  longlong local_f8;
  uint local_f0;
  longlong local_e8;
  longlong local_e0;
  undefined8 local_d8;
  longlong local_d0;
  longlong local_c8;
  undefined8 local_c0;
  int *piStack_b8;
  ushort *local_b0;
  longlong local_a8;
  undefined8 local_a0;
  ushort *puStack_98;
  undefined8 local_90;
  ushort *puStack_88;
  undefined8 local_80;
  ushort *puStack_78;
  undefined8 local_70;
  ushort *puStack_68;
  ushort local_60 [4];
  ushort *puStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  
  local_e8 = 0;
  local_100 = 0;
  local_118 = 0;
  local_f8 = 0;
  local_108 = 0;
  local_60[0] = 0;
  local_60[1] = 0;
  local_60[2] = 0;
  local_60[3] = 0;
  puStack_58 = (ushort *)0x0;
  local_120 = (undefined8 *)0x0;
  local_70 = 0;
  puStack_68 = (ushort *)0x0;
  local_res20[0] = '\0';
  local_90 = 0;
  puStack_88 = (ushort *)0x0;
  local_e0 = 0;
  local_a0 = 0;
  puStack_98 = (ushort *)0x0;
  local_128[0] = '\0';
  local_50 = 0;
  uStack_48 = 0;
  local_c8 = 0;
  local_80 = 0;
  puStack_78 = (ushort *)0x0;
  local_d8 = 0;
  local_c0 = 0;
  piStack_b8 = (int *)0x0;
  local_d0 = 0;
  RtlInitUnicodeString(&local_50,L"\\");
  RtlInitUnicodeString(&local_90,L"");
  puVar18 = auStackY_178;
  if (param_2 < 0xa8) {
    uVar19 = 0xc000000d;
    puVar18 = auStackY_178;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400228bf;
    uVar20 = 0x1b;
LAB_14002178b:
    puVar16 = auStackY_178;
  }
  else {
    if (param_2 < (uint)param_1[1]) {
      uVar19 = 0xc000000d;
      puVar18 = auStackY_178;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400228bf;
      uVar20 = 0x1c;
      goto LAB_14002178b;
    }
    if (*param_1 != 0xa8) {
      uVar19 = 0xc000000d;
      puVar18 = auStackY_178;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400228bf;
      uVar20 = 0x1d;
      goto LAB_14002178b;
    }
    uVar2 = *(ushort *)(param_1 + 0x1c);
    if (100 < uVar2) {
      uVar19 = 0xc000000d;
      puVar18 = auStackY_178;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400228bf;
      uVar20 = 0x1e;
      goto LAB_14002178b;
    }
    uVar19 = (ulonglong)(uint)param_1[2] * 0x1c + 0x88;
    if (param_2 < uVar19) {
      uVar19 = 0xc000000d;
      puVar18 = auStackY_178;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400228bf;
      uVar20 = 0x1f;
      goto LAB_14002178b;
    }
    if ((uint)param_1[2] < 2) {
      uVar19 = 0xc000000d;
      puVar18 = auStackY_178;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400228bf;
      uVar20 = 0x20;
      goto LAB_14002178b;
    }
    piStack_b8 = param_1 + 3;
    local_a8 = *(longlong *)(param_1 + 0x20);
    uVar8 = param_1[0x27];
    local_c0._0_4_ = CONCAT22(uVar2,uVar2);
    uVar14 = *(ushort *)(param_1 + 0x28) + uVar8;
    if ((uVar14 < uVar8) || (param_2 < uVar14)) {
      uVar19 = 0xc000000d;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400228bf;
      uVar20 = 0x21;
      uVar24 = 0xd;
      uVar23 = 0x6c;
LAB_14002288b:
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xb,uVar20,
                          &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                          "onecore\\base\\fs\\wci\\wcifs\\utils.c",uVar23,uVar24);
LAB_1400228a7:
      puVar18 = auStackY_178;
      if (local_d0 != 0) {
        PsDereferenceSiloContext(local_d0);
        puVar18 = auStackY_178;
      }
      goto LAB_1400228bf;
    }
    if (uVar8 < uVar19) {
      uVar19 = 0xc000000d;
      puVar18 = auStackY_178;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400228bf;
      uVar20 = 0x22;
      goto LAB_14002178b;
    }
    if ((param_1[0x26] & 1U) == 0) {
      uVar19 = 0xc000000d;
      puVar18 = auStackY_178;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400228bf;
      uVar20 = 0x23;
      goto LAB_14002178b;
    }
    puVar1 = (ushort *)((ulonglong)uVar8 + (longlong)param_1);
    uVar10 = WcValidateContainerRootId(puVar1,(uint)*(ushort *)(param_1 + 0x28));
    uVar19 = uVar10 & 0xffffffff;
    if ((int)uVar10 < 0) {
      puVar18 = auStackY_178;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400228bf;
      uVar20 = 0x24;
      goto LAB_14002178b;
    }
    uVar2 = puVar1[1];
    puStack_68 = puVar1 + 3;
    local_70._0_4_ = CONCAT22(uVar2,uVar2);
    uVar3 = puVar1[2];
    local_60[1] = uVar3;
    local_60[0] = uVar3;
    local_80._0_4_ = CONCAT22(uVar3,uVar3 - uVar2);
    puStack_78 = puStack_68 + (uVar2 >> 1);
    puStack_58 = puStack_68;
    cVar7 = RtlEqualUnicodeString(&local_80,&local_50,CONCAT11((byte)(uVar2 >> 9),1));
    local_110 = cVar7;
    uVar8 = WcGetInstanceFromVolumeName(&local_70,&local_c0,&local_e8);
    uVar19 = (ulonglong)uVar8;
    if ((int)uVar8 < 0) {
      puVar18 = auStackY_178;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400228bf;
      uVar20 = 0x25;
      goto LAB_14002178b;
    }
    uVar8 = FltGetInstanceContext(local_e8,&local_118);
    uVar19 = (ulonglong)uVar8;
    if ((int)uVar8 < 0) {
      puVar18 = auStackY_178;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400228bf;
      uVar20 = 0x26;
      goto LAB_14002178b;
    }
    if (*(int *)(local_118 + 8) != 2) {
      uVar19 = 0xc00000bb;
      puVar18 = auStackY_178;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400228bf;
      uVar20 = 0x27;
      uVar23 = 0xad;
LAB_140021c63:
      uVar19 = 0xc00000bb;
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xb,uVar20,
                         &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                         "onecore\\base\\fs\\wci\\wcifs\\utils.c",uVar23);
      puVar18 = auStackY_178;
      goto LAB_1400228bf;
    }
    if (*(char *)(local_118 + 0x128) == '\0') {
      uVar19 = 0xc00000bb;
      puVar18 = auStackY_178;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400228bf;
      uVar20 = 0x28;
      uVar23 = 0xb3;
      goto LAB_140021c63;
    }
    if (*(longlong *)(local_118 + 0x38) != 0) {
      uVar19 = 0xc00000bb;
      puVar18 = auStackY_178;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400228bf;
      uVar20 = 0x29;
      goto LAB_14002178b;
    }
    if (cVar7 != '\0') {
      if (param_1[0x1e] == 1) {
        uVar19 = 0xc00000bb;
        puVar18 = auStackY_178;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400228bf;
        uVar20 = 0x2a;
        goto LAB_14002178b;
      }
      *(undefined4 *)(local_118 + 0x124) = 0x50000;
      *(undefined4 *)(local_118 + 0x120) = 5;
    }
    uVar10 = WcCreateUnionContext
                       (local_60,(param_1[0x1e] - 1U < 2) + 1,param_1[0x1d],param_3,&local_108);
    uVar19 = uVar10 & 0xffffffff;
    if ((int)uVar10 < 0) {
      puVar18 = auStackY_178;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400228bf;
      uVar20 = 0x2b;
      goto LAB_14002178b;
    }
    if (param_1[0x1e] == 2) {
      *(uint *)(local_108 + 0x20) = *(uint *)(local_108 + 0x20) | 2;
    }
    ExAcquireFastMutex(&DAT_14000f208);
    if (DAT_14000f240 != '\0') {
      ExReleaseFastMutex();
      uVar19 = 0xc00000bb;
      puVar18 = auStackY_178;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400228bf;
      uVar20 = 0x2c;
      uVar23 = 0xf5;
      goto LAB_140021c63;
    }
    *(uint *)(local_108 + 0x20) = *(uint *)(local_108 + 0x20) | 1;
    DAT_14000f244 = DAT_14000f244 + 1;
    ExReleaseFastMutex(&DAT_14000f208);
    uVar10 = 1;
    while( true ) {
      puVar17 = auStackY_178;
      puVar18 = auStackY_178;
      puVar16 = auStackY_178;
      local_f0 = (uint)uVar10;
      if ((uint)param_1[2] <= local_f0) break;
      piVar21 = param_1 + uVar10 * 7 + 0x22;
      if (piVar21 == (int *)0x0) {
        uVar19 = 0xc000000d;
        puVar18 = auStackY_178;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400228bf;
        uVar20 = 0x2d;
        puVar16 = auStackY_178;
        goto LAB_14002224c;
      }
      uVar8 = piVar21[5];
      uVar14 = *(ushort *)(piVar21 + 6) + uVar8;
      if ((uVar14 < uVar8) || (param_2 < uVar14)) {
        uVar19 = 0xc000000d;
        puVar18 = auStackY_178;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400228bf;
        uVar20 = 0x2e;
        puVar16 = auStackY_178;
        goto LAB_14002224c;
      }
      if ((ulonglong)uVar8 < (ulonglong)(uint)param_1[2] * 0x1c + 0x88) {
        uVar19 = 0xc000000d;
        puVar18 = auStackY_178;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400228bf;
        uVar20 = 0x2f;
        puVar16 = auStackY_178;
        goto LAB_14002224c;
      }
      if ((piVar21[4] & 1U) != 0) {
        uVar19 = 0xc000000d;
        puVar18 = auStackY_178;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400228bf;
        uVar20 = 0x30;
        puVar16 = auStackY_178;
        goto LAB_14002224c;
      }
      local_b0 = (ushort *)((ulonglong)uVar8 + (longlong)param_1);
      uVar10 = WcValidateContainerRootId(local_b0,(uint)*(ushort *)(piVar21 + 6));
      uVar19 = uVar10 & 0xffffffff;
      if ((int)uVar10 < 0) {
        puVar18 = auStackY_178;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDdd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xb,0x31,
                     &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                     "onecore\\base\\fs\\wci\\wcifs\\utils.c",0x28,(char)local_f0,(char)uVar10);
          puVar18 = auStackY_178;
        }
        goto LAB_1400228bf;
      }
      puStack_98 = local_b0 + 3;
      local_90._0_4_ = CONCAT22(local_b0[2],local_b0[2]);
      local_a0._0_4_ = CONCAT22(local_b0[1],local_b0[1]);
      puStack_88 = puStack_98;
      iVar9 = WcGetInstanceFromVolumeName(&local_a0,&local_c0,&local_100);
      if (iVar9 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xb,0x32,
                              &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                              "onecore\\base\\fs\\wci\\wcifs\\utils.c",0x3a,(char)iVar9);
        }
        uVar8 = FltGetVolumeFromName(Globals,&local_a0,&local_e0);
        uVar19 = (ulonglong)uVar8;
        if ((int)uVar8 < 0) {
          puVar18 = auStackY_178;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1400228bf;
          uVar20 = 0x33;
          puVar16 = auStackY_178;
          goto LAB_14002224c;
        }
        uVar8 = FltAttachVolume(Globals,local_e0,&local_c0,&local_100);
        uVar19 = (ulonglong)uVar8;
        if ((int)uVar8 < 0) {
          puVar18 = auStackY_178;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1400228bf;
          uVar20 = 0x34;
          puVar16 = auStackY_178;
          goto LAB_14002224c;
        }
        uVar8 = FltGetInstanceContext(local_100,&local_f8);
        uVar19 = (ulonglong)uVar8;
        if ((int)uVar8 < 0) {
          puVar18 = auStackY_178;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1400228bf;
          uVar20 = 0x35;
          puVar16 = auStackY_178;
          goto LAB_14002224c;
        }
      }
      else {
        uVar8 = FltGetInstanceContext(local_100,&local_f8);
        uVar19 = (ulonglong)uVar8;
        if ((int)uVar8 < 0) {
          puVar18 = auStackY_178;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1400228bf;
          uVar20 = 0x36;
          puVar16 = auStackY_178;
          goto LAB_14002224c;
        }
        if (*(longlong *)(local_f8 + 0x38) != 0) {
          uVar19 = 0xc00000bb;
          puVar18 = auStackY_178;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1400228bf;
          uVar20 = 0x37;
          puVar16 = auStackY_178;
          goto LAB_14002224c;
        }
      }
      if (local_e8 != local_100) {
        uVar8 = FltIsIoRedirectionAllowed(local_e8,local_100,local_128);
        uVar19 = (ulonglong)uVar8;
        if ((int)uVar8 < 0) {
          puVar18 = auStackY_178;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1400228bf;
          uVar20 = 0x38;
          puVar16 = auStackY_178;
          goto LAB_14002224c;
        }
        if (local_128[0] == '\0') {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xb,0x39,
                               &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                               "onecore\\base\\fs\\wci\\wcifs\\utils.c",0x77);
          }
          uVar8 = FltAdjustDeviceStackSizeForIoRedirection(local_e8,local_100,0);
          uVar19 = (ulonglong)uVar8;
          if ((int)uVar8 < 0) {
            puVar18 = auStackY_178;
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_1400228bf;
            uVar20 = 0x3a;
            puVar16 = auStackY_178;
            goto LAB_14002224c;
          }
        }
      }
      local_120 = (undefined8 *)ExAllocatePool2(0x100,0x70,0x796c4357);
      if (local_120 == (undefined8 *)0x0) {
        uVar19 = 0xc000009a;
        puVar18 = auStackY_178;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400228bf;
        uVar20 = 0x3b;
        puVar16 = auStackY_178;
        goto LAB_14002224c;
      }
      RtlInitUnicodeString(local_120 + 3,0);
      puVar11 = local_120 + 6;
      local_120[7] = puVar11;
      *puVar11 = puVar11;
      local_120[5] = 0;
      local_120[8] = 0;
      *(undefined4 *)(local_120 + 2) = 0;
      uVar8 = RtlUShortAdd(local_b0[2],2,(ushort *)((longlong)local_120 + 0x1a));
      uVar19 = (ulonglong)uVar8;
      puVar18 = auStackY_178;
      if ((int)uVar8 < 0) goto LAB_1400228bf;
      uVar10 = WcAllocateUnicodeString(0x796c4357,(undefined2 *)(local_120 + 3));
      uVar19 = uVar10 & 0xffffffff;
      if ((int)uVar10 < 0) {
        puVar18 = auStackY_178;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400228bf;
        uVar20 = 0x3c;
        puVar16 = auStackY_178;
        goto LAB_14002224c;
      }
      *(undefined1 *)((longlong)local_120 + 0x14) = 1;
      RtlCopyUnicodeString(local_120 + 3,&local_90);
      if ((*(int *)(local_f8 + 8) != 6) ||
         (*(short *)(local_120[4] + -2 + (ulonglong)(*(ushort *)(local_120 + 3) >> 1) * 2) != 0x5c))
      {
        uVar8 = RtlAppendUnicodeToString(local_120 + 3,L"\\");
        uVar19 = (ulonglong)uVar8;
        if ((int)uVar8 < 0) {
          puVar18 = auStackY_178;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1400228bf;
          uVar20 = 0x3d;
          puVar16 = auStackY_178;
          goto LAB_14002224c;
        }
      }
      cVar7 = local_110;
      uVar5 = *(undefined8 *)(piVar21 + 2);
      *local_120 = *(undefined8 *)piVar21;
      local_120[1] = uVar5;
      if (((byte)*(ushort *)((longlong)piVar21 + 0x1a) & 3) == 3) {
LAB_14002229c:
        uVar19 = 0xc000000d;
        puVar18 = puVar17;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400228bf;
        *(undefined4 *)(puVar17 + 0x38) = 0xc000000d;
        uVar20 = 0x3e;
        *(undefined4 *)(puVar17 + 0x30) = 0x5b7;
        puVar16 = puVar17;
        goto LAB_14002224c;
      }
      if ((*(ushort *)((longlong)piVar21 + 0x1a) & 2) != 0) {
        *(uint *)(local_120 + 2) = *(uint *)(local_120 + 2) | 4;
      }
      if ((*(byte *)((longlong)piVar21 + 0x1a) & 1) != 0) {
        *(uint *)(local_120 + 2) = *(uint *)(local_120 + 2) | 2;
      }
      if ((*(byte *)((longlong)piVar21 + 0x1a) & 4) != 0) {
        *(uint *)(local_120 + 2) = *(uint *)(local_120 + 2) | 0x40;
      }
      if ((*(int *)(local_f8 + 8) == 0xd) || (*(int *)(local_f8 + 8) == 6)) {
        *(uint *)(local_120 + 2) = *(uint *)(local_120 + 2) | 1;
      }
      if (local_110 != '\0') {
        uVar10 = WcInitializeDirectoryTable((longlong)local_120,0x2000);
        uVar19 = uVar10 & 0xffffffff;
        puVar18 = auStackY_178;
        if ((int)uVar10 < 0) goto LAB_1400228bf;
      }
      plVar15 = local_120 + 6;
      plVar4 = *(longlong **)(local_108 + 0xb0);
      if (*plVar4 != local_108 + 0xa8) {
        pcVar6 = (code *)swi(0x29);
        (*pcVar6)(3);
        puVar17 = auStackY_170;
        goto LAB_14002229c;
      }
      *plVar15 = local_108 + 0xa8;
      local_120[7] = plVar4;
      *plVar4 = (longlong)plVar15;
      *(longlong **)(local_108 + 0xb0) = plVar15;
      local_120[5] = local_100;
      if (local_f8 == local_118) {
        FltObjectDereference(local_100);
      }
      else {
        LOCK();
        *(int *)(local_f8 + 0x14) = *(int *)(local_f8 + 0x14) + 1;
        UNLOCK();
        *(uint *)(local_120 + 2) = *(uint *)(local_120 + 2) | 8;
      }
      local_100 = 0;
      lVar12 = RtlInsertElementGenericTableAvl(local_108 + 0x40,&local_120,8,local_res20);
      if (lVar12 == 0) {
        uVar19 = 0xc000009a;
        puVar18 = auStackY_178;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400228bf;
        uVar20 = 0x3f;
        puVar16 = auStackY_178;
        goto LAB_14002224c;
      }
      if (local_res20[0] == '\0') {
        uVar19 = 0xc000000d;
        puVar18 = auStackY_178;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400228bf;
        uVar20 = 0x40;
        puVar16 = auStackY_178;
        goto LAB_14002224c;
      }
      puVar18 = auStackY_178;
      if ((int)uVar19 < 0) goto LAB_1400228bf;
      local_120 = (undefined8 *)0x0;
      FltReleaseContext(local_f8);
      local_f8 = 0;
      if (local_e0 != 0) {
        FltObjectDereference();
        local_e0 = 0;
      }
      uVar10 = (ulonglong)(local_f0 + 1);
    }
    if (cVar7 == '\0') {
      if ((*(int *)(local_118 + 0x118) == 0) || (*(int *)(local_118 + 0x118) == param_1[0x1d])) {
        lVar13 = RtlCompareMemory(*(longlong *)(local_108 + 0x10) +
                                  ((ulonglong)*(ushort *)(local_108 + 8) - 2 & 0xfffffffffffffffe),
                                  L"\\",2);
        lVar12 = local_a8;
        if (lVar13 == 2) {
          *(short *)(local_108 + 8) = *(short *)(local_108 + 8) + -2;
        }
        if (local_a8 == 0) {
          *(undefined4 *)(local_108 + 0x1c) = 2;
          FltAcquireResourceExclusive(local_118 + 0x48);
          lVar12 = RtlInsertElementGenericTableAvl(local_118 + 0xb0,&local_108,8,local_res20);
          if ((lVar12 != 0) && (local_res20[0] != '\0')) {
            *(int *)(local_118 + 0x40) = *(int *)(local_118 + 0x40) + 1;
          }
          *(int *)(local_118 + 0x118) = param_1[0x1d];
          *(int *)(local_118 + 0x11c) = param_3;
          lVar13 = local_118 + 0x48;
LAB_14002279b:
          FltReleaseResource(lVar13);
          if (lVar12 == 0) {
            uVar19 = 0xc000009a;
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar8 = 0xc000009a;
              uVar20 = 0x48;
              uVar23 = 0x8a;
LAB_140022754:
              uVar24 = (undefined1)uVar8;
              goto LAB_14002288b;
            }
          }
          else if (local_res20[0] == '\0') {
            uVar19 = 0xc000000d;
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar8 = 0xc000000d;
              uVar20 = 0x49;
              uVar23 = 0x8f;
              goto LAB_140022754;
            }
          }
          else if (-1 < (int)uVar19) goto LAB_14002280e;
          goto LAB_1400228a7;
        }
        *(undefined4 *)(local_108 + 0x1c) = 3;
        cVar7 = ObIsKernelHandle(local_a8);
        uVar8 = ObReferenceObjectByHandle(lVar12,4,*(undefined8 *)PsJobType_exref,cVar7 == '\0');
        uVar19 = (ulonglong)uVar8;
        if ((int)uVar8 < 0) {
          puVar18 = auStackY_178;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1400228bf;
          uVar20 = 0x44;
          puVar16 = auStackY_178;
        }
        else {
          uVar8 = PsGetJobSilo(local_c8,&local_d8);
          uVar19 = (ulonglong)uVar8;
          if ((int)uVar8 < 0) {
            puVar18 = auStackY_178;
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_1400228bf;
            uVar20 = 0x45;
            puVar16 = auStackY_178;
          }
          else {
            cVar7 = PsIsHostSilo(local_d8);
            if (cVar7 == '\0') {
              uVar8 = WcGetSetSiloContext(local_d8,local_e8,param_1[0x1d],param_3,&local_d0);
              lVar12 = local_d0;
              uVar19 = (ulonglong)uVar8;
              if (-1 < (int)uVar8) {
                lVar13 = local_d0 + 8;
                FltAcquireResourceExclusive(lVar13);
                lVar12 = RtlInsertElementGenericTableAvl(lVar12 + 0x70,&local_108,8,local_res20);
                goto LAB_14002279b;
              }
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar20 = 0x47;
                uVar23 = 0x79;
                goto LAB_140022754;
              }
              goto LAB_1400228a7;
            }
            uVar19 = 0xc000000d;
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_1400228bf;
            uVar20 = 0x46;
          }
        }
      }
      else {
        uVar19 = 0xc000000d;
        puVar18 = auStackY_178;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400228bf;
        uVar20 = 0x43;
        puVar16 = auStackY_178;
      }
    }
    else if (*(longlong *)(local_118 + 0x38) == 0) {
      *(undefined4 *)(local_108 + 0x1c) = 1;
      LOCK();
      bVar22 = *(longlong *)(local_118 + 0x38) == 0;
      if (bVar22) {
        *(longlong *)(local_118 + 0x38) = local_108;
      }
      UNLOCK();
      if (bVar22) {
LAB_14002280e:
        local_108 = 0;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xb,0x4a,
                             &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                             "onecore\\base\\fs\\wci\\wcifs\\utils.c",0x99);
        }
        goto LAB_1400228a7;
      }
      uVar19 = 0xc00000bb;
      puVar18 = auStackY_178;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400228bf;
      uVar20 = 0x42;
      puVar16 = auStackY_178;
    }
    else {
      uVar19 = 0xc00000bb;
      puVar18 = auStackY_178;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400228bf;
      uVar20 = 0x41;
      puVar16 = auStackY_178;
    }
  }
LAB_14002224c:
  *(char **)(puVar16 + 0x28) = "onecore\\base\\fs\\wci\\wcifs\\utils.c";
  *(undefined **)(puVar16 + 0x20) = &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids;
  uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
  *(undefined8 *)(puVar16 + -8) = 0x140022268;
  WPP_RECORDER_SF_sDd(uVar5,2,0xb,uVar20,*(undefined8 *)(puVar16 + 0x20),*(char **)(puVar16 + 0x28),
                      puVar16[0x30],puVar16[0x38]);
  puVar18 = puVar16;
LAB_1400228bf:
  if (local_c8 != 0) {
    *(undefined8 *)(puVar18 + -8) = 0x1400228cf;
    ObfDereferenceObject();
  }
  if (*(int **)(puVar18 + 0x70) != (int *)0x0) {
    *(undefined8 *)(puVar18 + -8) = 0x1400228e3;
    WcReleaseUnionContext(*(int **)(puVar18 + 0x70));
  }
  if (*(longlong *)(puVar18 + 0x60) != 0) {
    *(undefined8 *)(puVar18 + -8) = 0x1400228f4;
    FltReleaseContext();
  }
  if (local_f8 != 0) {
    *(undefined8 *)(puVar18 + -8) = 0x140022909;
    FltReleaseContext();
  }
  if (local_e8 != 0) {
    *(undefined8 *)(puVar18 + -8) = 0x14002291e;
    FltObjectDereference();
  }
  if (local_e0 != 0) {
    *(undefined8 *)(puVar18 + -8) = 0x140022933;
    FltObjectDereference();
  }
  if (*(longlong *)(puVar18 + 0x78) != 0) {
    *(undefined8 *)(puVar18 + -8) = 0x140022949;
    FltObjectDereference();
  }
  if (*(longlong *)(puVar18 + 0x58) != 0) {
    *(undefined8 *)(puVar18 + -8) = 0x14002295d;
    WcCleanupLayer(*(longlong *)(puVar18 + 0x58));
  }
  return uVar19;
}



===== WcSuppressTimestamps @ 140022984 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WcSuppressTimestamps(undefined8 param_1,undefined8 param_2,char param_3)

{
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  local_14 = 0;
  local_18 = 0;
  if (param_3 == '\0') {
    local_38 = 0xfffffffffffffffe;
    uStack_30 = 0xfffffffffffffffe;
  }
  else {
    local_38 = 0xffffffffffffffff;
    uStack_30 = 0xffffffffffffffff;
  }
  local_48 = 4;
  local_28 = local_38;
  uStack_20 = uStack_30;
  FltSetInformationFile(local_38,local_38,&local_38,0x28);
  return;
}



===== WcInstanceQueryTeardown @ 140022a10 =====

uint WcInstanceQueryTeardown(longlong param_1)

{
  uint uVar1;
  bool bVar2;
  longlong local_res8;
  
  local_res8 = 0;
  FltGetInstanceContext(*(undefined8 *)(param_1 + 0x18),&local_res8);
  uVar1 = -(uint)(*(int *)(local_res8 + 0x14) != 0) & 0xc01c0010;
  LOCK();
  bVar2 = *(int *)(local_res8 + 0x18) == 0;
  if (bVar2) {
    *(int *)(local_res8 + 0x18) = 0;
  }
  UNLOCK();
  if (!bVar2) {
    uVar1 = 0xc01c0010;
  }
  FltReleaseContext(local_res8);
  return uVar1;
}



===== WcInstanceTeardownComplete @ 140022a80 =====

void WcInstanceTeardownComplete(void)

{
  return;
}



===== WcPostAcquireForSectionSynchronization @ 140022a90 =====

void WcPostAcquireForSectionSynchronization(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  WcSynchronizeExpansionPostOp(param_3);
  return;
}



===== WcUnload @ 140022ab0 =====

undefined8 WcUnload(void)

{
  undefined8 uVar1;
  ulonglong uVar2;
  undefined *puVar3;
  _GUID *in_R9;
  
  ExAcquireFastMutex(&DAT_14000f208);
  if (DAT_14000f244 == 0) {
    DAT_14000f240 = 1;
    ExReleaseFastMutex(&DAT_14000f208);
    if (DAT_14000f730 != 0) {
      FltReleaseContext();
    }
    FltCloseCommunicationPort(DAT_14000f248);
    FltDeleteExtraCreateParameterLookasideList(Globals,&DAT_14000f300);
    puVar3 = &DAT_14000f280;
    uVar1 = 0;
    FltDeleteExtraCreateParameterLookasideList(Globals);
    ExDeletePagedLookasideList(&DAT_14000f380);
    ExDeletePagedLookasideList(&DAT_14000f400);
    ExDeletePagedLookasideList(&DAT_14000f500);
    ExDeletePagedLookasideList(&DAT_14000f480);
    ExDeleteNPagedLookasideList(&DAT_14000f580);
    if (DAT_14000f6a9 != '\0') {
      ExDeleteNPagedLookasideList(&DAT_14000f600);
    }
    if (DAT_14000f680 != '\0') {
      puVar3 = (undefined *)0x656c4357;
      ExFreePoolWithTag(DAT_14000f688);
      DAT_14000f688 = 0;
    }
    FltUnregisterFilter(Globals);
    PsFreeSiloContextSlot(DAT_14000f250);
    uVar2 = (ulonglong)DAT_14000f254;
    PsFreeSiloContextSlot();
    if ((Microsoft_Windows_Containers_WcifsEnableBits & 2) != 0) {
      puVar3 = &WcifsUnloadSuccessful;
      McTemplateK0_EtwWriteTransfer(uVar2,&WcifsUnloadSuccessful,uVar1);
    }
    McGenEventUnregister_EtwUnregister();
    WcTelemetryAndTracingCleanup(uVar2,puVar3,uVar1,in_R9);
    wil_UninitializeFeatureStaging();
    uVar1 = 0;
  }
  else {
    ExReleaseFastMutex();
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0x10,0x34,
                          &WPP_27ac746799d63ca1d37704ce911b8053_Traceguids,
                          "onecore\\base\\fs\\wci\\wcifs\\wcifs.c",0xfd,0xbb);
    }
    uVar1 = 0xc00000bb;
  }
  return uVar1;
}



===== wil_UninitializeFeatureStaging @ 140022cc8 =====

void wil_UninitializeFeatureStaging(void)

{
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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 140022d20 =====

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
      goto LAB_140022d7d;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_140022d7d;
    }
  }
  uVar1 = 0x206;
LAB_140022d7d:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 140022d88 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  longlong *plVar1;
  undefined **ppuVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  bool bVar6;
  
  plVar1 = wil_details_FeatureDescriptors_SkipPadding
                     ((longlong *)&Feature_944920889__private_descriptor);
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
  ppuVar2 = &Feature_944920889__private_descriptor;
  while( true ) {
    plVar1 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar2);
    if (plVar1 == (longlong *)0x0) break;
    wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
              ((uint *)*plVar1,(longlong)plVar1);
    ppuVar2 = (undefined **)(plVar1 + 7);
  }
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 140022e40 =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 140022e78 =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_140022efa;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_140022efa;
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
LAB_140022efa:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 140022f50 =====

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
      ppuVar3 = &Feature_944920889__private_descriptor;
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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 140022fb0 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 140022fcc =====

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
  ppuVar3 = &Feature_944920889__private_descriptor;
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



===== CancelTimerCallbacksAndDeleteTimer @ 140023080 =====

void CancelTimerCallbacksAndDeleteTimer(longlong param_1)

{
  short *psVar1;
  short sVar2;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  if (*(longlong *)(param_1 + 0x168) != 0) {
    LOCK();
    psVar1 = (short *)(*(longlong *)(param_1 + 0x108) + 0x38);
    sVar2 = *psVar1;
    *psVar1 = 2;
    UNLOCK();
    if (sVar2 == 1) {
      KeWaitForSingleObject(*(longlong *)(param_1 + 0x108) + 0x20,0,0,0,0);
    }
    local_28 = 0;
    uStack_20 = 0;
    local_18 = 0;
    ExDeleteTimer(*(undefined8 *)(param_1 + 0x168),1,1,&local_28);
    *(undefined8 *)(param_1 + 0x168) = 0;
  }
  return;
}



===== ComputeFlushPeriod @ 140023110 =====

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
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x158) + 8);
  local_28 = *(undefined8 *)(lVar1 + -0x10);
  uStack_20 = *(undefined8 *)(lVar1 + -8);
  RunningHash(local_38,(longlong)&local_28,0x10);
  RunningHash(local_38,(longlong)&local_30,8);
  FinishHash((int *)local_38);
  return local_38[0] % 600000 + 600000;
}



===== CreateTlgAggregateSession @ 1400231b4 =====

void * CreateTlgAggregateSession(char param_1,char param_2)

{
  undefined8 *puVar1;
  void *_Dst;
  void *_Dst_00;
  longlong lVar2;
  
  _Dst = (void *)ExAllocatePoolWithTag
                           ((-(uint)(param_1 != '\0') & 0xfffffe01) + 0x200,0x178,0x47417254);
  if (_Dst != (void *)0x0) {
    memset(_Dst,0,0x178);
    *(undefined8 *)((longlong)_Dst + 0x110) = 0;
    if ((param_2 == '\0') && (param_1 != '\0')) {
      return _Dst;
    }
    _Dst_00 = (void *)ExAllocatePoolWithTag(0x200,0x40,0x47417254);
    if (_Dst_00 != (void *)0x0) {
      memset(_Dst_00,0,0x40);
    }
    *(void **)((longlong)_Dst + 0x108) = _Dst_00;
    if (_Dst_00 != (void *)0x0) {
      KeInitializeEvent((longlong)_Dst_00 + 0x20,0,0);
      puVar1 = *(undefined8 **)((longlong)_Dst + 0x108);
      puVar1[2] = TlgAggregateInternalFlushWorkItemRoutineKernelMode;
      puVar1[3] = _Dst;
      *puVar1 = 0;
      *(undefined2 *)(*(longlong *)((longlong)_Dst + 0x108) + 0x38) = 0;
      if (param_2 == '\0') {
        return _Dst;
      }
      lVar2 = ExAllocateTimer(TlgAggregateInternalFlushTimerCallbackKernelMode,
                              *(undefined8 *)((longlong)_Dst + 0x108),8);
      *(longlong *)((longlong)_Dst + 0x168) = lVar2;
      if (lVar2 != 0) {
        return _Dst;
      }
    }
  }
  DestroyAggregateSession((longlong)_Dst);
  return (void *)0x0;
}



===== DestroyAggregateSession @ 14002330c =====

void DestroyAggregateSession(longlong param_1)

{
  if (param_1 != 0) {
    CancelTimerCallbacksAndDeleteTimer(param_1);
    if (*(longlong *)(param_1 + 0x108) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x108),0);
    }
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== FlushEventEntryList @ 140023358 =====

void FlushEventEntryList(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  
  if (param_2 != 0) {
    do {
      iVar2 = 2;
      if (2 < *(byte *)(param_2 + 0x2d) + 2) {
        lVar1 = 0x20;
        do {
          lVar1 = lVar1 + 0x10;
          iVar2 = iVar2 + 1;
          *(undefined1 *)(*(longlong *)(param_2 + 0x10) + -3 + lVar1) = 0;
        } while (iVar2 < (int)(*(byte *)(param_2 + 0x2d) + 2));
      }
      EtwWriteTransfer(param_1,param_2,0,0,*(undefined1 *)(param_2 + 0x2c),
                       *(undefined8 *)(param_2 + 0x10));
      lVar1 = *(longlong *)(param_2 + 0x18);
      DestroyEventEntry(param_2);
      param_2 = lVar1;
    } while (lVar1 != 0);
  }
  return;
}



===== LookUpTableFlushPartial @ 1400233f8 =====

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
        iVar2 = FlushLookUpTableBucket(param_1,uVar3);
        uVar4 = uVar4 + iVar2;
      }
      uVar3 = uVar3 + 1 & 0x1f;
    } while ((uVar3 != uVar1) && (uVar4 < 0x10));
    *(uint *)(param_1 + 0x104) = uVar3;
    UpdateInternalStatsOnFlush(param_1,uVar4);
  }
  return;
}



===== TlgAggregateInternalFlushWorkItemRoutineKernelMode @ 140023470 =====

/* void __cdecl TlgAggregateInternalFlushWorkItemRoutineKernelMode(void * __ptr64) */

void __cdecl TlgAggregateInternalFlushWorkItemRoutineKernelMode(void *param_1)

{
  short *psVar1;
  short sVar2;
  short sVar3;
  undefined8 in_RDX;
  undefined8 in_R8;
  _GUID *in_R9;
  
  if (*(char *)((longlong)param_1 + 0x174) == '\0') {
    LookUpTableFlushPartial((longlong)param_1);
  }
  else {
    *(undefined1 *)((longlong)param_1 + 0x174) = 0;
    LookUpTableFlushComplete((longlong)param_1,in_RDX,in_R8,in_R9);
  }
  if (*(int *)((longlong)param_1 + 0x100) != 0) {
    EnableFlushTimer(*(longlong *)((longlong)param_1 + 0x168),
                     (ulonglong)*(uint *)((longlong)param_1 + 0x170));
  }
  sVar3 = 1;
  psVar1 = (short *)(*(longlong *)((longlong)param_1 + 0x108) + 0x38);
  LOCK();
  sVar2 = *psVar1;
  if (sVar2 == 1) {
    *psVar1 = 0;
  }
  else {
    sVar3 = sVar2;
  }
  UNLOCK();
  if (sVar3 == 2) {
    KeSetEvent(*(longlong *)((longlong)param_1 + 0x108) + 0x20,0,0);
  }
  return;
}



===== UpdateInternalStatsOnFlush @ 1400234fc =====

void UpdateInternalStatsOnFlush(longlong param_1,uint param_2)

{
  longlong *plVar1;
  longlong lVar2;
  
  if (param_2 != 0) {
    plVar1 = (longlong *)(param_1 + 0x128);
    if ((param_2 < *(uint *)(param_1 + 0x138)) || (lVar2 = *plVar1, lVar2 == 0)) {
      lVar2 = *plVar1;
      *(uint *)(param_1 + 0x138) = param_2;
    }
    if (*(uint *)(param_1 + 0x134) < param_2) {
      *(uint *)(param_1 + 0x134) = param_2;
    }
    *plVar1 = lVar2 + 1;
    *(longlong *)(param_1 + 0x120) = *(longlong *)(param_1 + 0x120) + (ulonglong)param_2;
  }
  return;
}



===== TlgRegisterAggregateProvider @ 140023548 =====

void TlgRegisterAggregateProvider(void)

{
  TlgRegisterAggregateProviderEx();
  return;
}



===== TlgRegisterAggregateProviderEx @ 140023560 =====

int TlgRegisterAggregateProviderEx(void)

{
  longlong lVar1;
  int iVar2;
  void *pvVar3;
  longlong *plVar4;
  
  pvVar3 = CreateTlgAggregateSession('\0','\x01');
  if (pvVar3 == (void *)0x0) {
    iVar2 = TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(0x14000f060,0,0);
  }
  else {
    *(undefined8 *)((longlong)pvVar3 + 0x148) = 0;
    *(undefined8 *)((longlong)pvVar3 + 0x150) = 0;
    *(undefined4 **)((longlong)pvVar3 + 0x158) = &DAT_14000f060;
    *(undefined1 *)((longlong)pvVar3 + 0x175) = 0;
    iVar2 = ComputeFlushPeriod((ulonglong)pvVar3);
    *(int *)((longlong)pvVar3 + 0x170) = iVar2;
    iVar2 = TraceLoggingRegisterEx_EtwRegister_EtwSetInformation
                      (0x14000f060,TlgAggregateInternalRegisteredProviderEtwCallback,pvVar3);
    if (iVar2 < 0) {
      DAT_14000f088 = 0;
      DestroyAggregateSession((longlong)pvVar3);
    }
    else {
      ExAcquirePushLockExclusiveEx(&DAT_14000f740,0);
      if (DAT_14000f748 == 0) {
        TraceLoggingRegisterEx_EtwRegister_EtwSetInformation
                  (0x14000f098,TlgAggregateInternalProviderCallback,0);
      }
      plVar4 = &DAT_14000f748;
      while (lVar1 = *plVar4, lVar1 != 0) {
        if (*(undefined4 **)(lVar1 + 0x158) == &DAT_14000f060) goto LAB_14002363a;
        plVar4 = (longlong *)(lVar1 + 0x160);
      }
      *plVar4 = (longlong)pvVar3;
LAB_14002363a:
      ExReleasePushLockExclusiveEx(&DAT_14000f740,0);
      iVar2 = 0;
    }
  }
  return iVar2;
}



===== TlgUnregisterAggregateProvider @ 14002367c =====

void TlgUnregisterAggregateProvider
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,_GUID *param_4)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong *plVar3;
  longlong lVar4;
  
  uVar2 = DAT_14000f080;
  if (DAT_14000f088 == TlgAggregateInternalRegisteredProviderEtwCallback) {
    ExAcquirePushLockExclusiveEx(&DAT_14000f740,0);
    plVar3 = &DAT_14000f748;
    while (lVar1 = *plVar3, lVar4 = 0, lVar1 != 0) {
      if (*(undefined4 **)(lVar1 + 0x158) == &DAT_14000f060) {
        *plVar3 = *(longlong *)(lVar1 + 0x160);
        LookUpTableFlushComplete(lVar1,&DAT_14000f060,param_3,param_4);
        uVar2 = DAT_14000f0b8;
        lVar4 = lVar1;
        if (DAT_14000f748 == 0) {
          DAT_14000f0b8 = 0;
          DAT_14000f098 = 0;
          EtwUnregister(uVar2);
        }
        break;
      }
      plVar3 = (longlong *)(lVar1 + 0x160);
    }
    ExReleasePushLockExclusiveEx(&DAT_14000f740,0);
    if (lVar4 != 0) {
      CancelTimerCallbacksAndDeleteTimer(lVar4);
    }
    uVar2 = DAT_14000f080;
    DAT_14000f080 = 0;
    DAT_14000f060 = 0;
    EtwUnregister(uVar2);
    DAT_14000f088 = (code *)0x0;
    DestroyAggregateSession(lVar4);
  }
  else {
    DAT_14000f080 = 0;
    DAT_14000f060 = 0;
    EtwUnregister(uVar2);
  }
  return;
}



===== TraceLoggingRegisterEx_EtwRegister_EtwSetInformation @ 14002379c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int TraceLoggingRegisterEx_EtwRegister_EtwSetInformation
              (longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong *plVar1;
  undefined2 uVar2;
  longlong lVar3;
  undefined2 *puVar4;
  code *pcVar5;
  int iVar6;
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
  lVar3 = *(longlong *)(param_1 + 8);
  plVar1 = (longlong *)(param_1 + 0x20);
  local_28 = *(undefined4 *)(lVar3 + -0x10);
  uStack_24 = *(undefined4 *)(lVar3 + -0xc);
  uStack_20 = *(undefined4 *)(lVar3 + -8);
  uStack_1c = *(undefined4 *)(lVar3 + -4);
  if (*plVar1 != 0) {
    pcVar5 = (code *)swi(0x29);
    (*pcVar5)(5);
    puVar7 = auStack_40;
  }
  *(undefined8 *)(param_1 + 0x28) = param_2;
  *(undefined8 *)(param_1 + 0x30) = param_3;
  *(undefined8 *)(puVar7 + -8) = 0x1400237fd;
  iVar6 = EtwRegister(puVar7 + 0x20,_tlgEnableCallback,param_1,plVar1);
  if (iVar6 == 0) {
    puVar4 = *(undefined2 **)(param_1 + 8);
    lVar3 = *plVar1;
    uVar2 = *puVar4;
    *(undefined8 *)(puVar7 + -8) = 0x14002381d;
    EtwSetInformation(lVar3,2,puVar4,uVar2);
  }
  *(undefined8 *)(puVar7 + -8) = 0x140023831;
  return iVar6;
}



===== WcProcessWciLinkBounce @ 140023850 =====

uint WcProcessWciLinkBounce(longlong param_1,undefined8 param_2,longlong param_3)

{
  uint uVar1;
  int *piVar2;
  short local_18 [8];
  
  local_18[0] = 0;
  local_18[1] = 0;
  local_18[2] = 0;
  local_18[3] = 0;
  local_18[4] = 0;
  local_18[5] = 0;
  local_18[6] = 0;
  local_18[7] = 0;
  uVar1 = 0;
  piVar2 = (int *)WcGetUnionContext(param_1,param_2,param_3);
  if (piVar2 != (int *)0x0) {
    if ((ulonglong)(uint)piVar2[10] == *(ulonglong *)(param_1 + 0x20)) {
      if (piVar2[6] == 2) {
        RtlInitUnicodeString(local_18,0);
        uVar1 = WcRedirectCallbackData(param_1,(longlong)piVar2,local_18);
        if (((int)uVar1 < 0) &&
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_SF_sDZd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x20,
                     &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                     "onecore\\base\\fs\\wci\\wcifs\\create.c",0xc6,(wchar_t *)(param_3 + 0x58),
                     (char)uVar1);
        }
      }
      else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDdZ
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x21,
                   &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                   "onecore\\base\\fs\\wci\\wcifs\\create.c",0xd0,(char)piVar2[6],
                   (wchar_t *)(param_3 + 0x58));
      }
    }
    WcReleaseUnionContext(piVar2);
  }
  return uVar1;
}



===== WcPostCreate @ 1400239b0 =====

undefined8 WcPostCreate(longlong param_1,longlong param_2,longlong *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  bool bVar3;
  bool bVar4;
  wchar_t *pwVar5;
  ulonglong uVar6;
  uint uVar7;
  undefined8 uVar8;
  ushort uVar9;
  undefined2 uVar10;
  undefined8 *puVar11;
  ulonglong *puVar12;
  uint *puVar13;
  char local_res18 [8];
  undefined8 in_stack_ffffffffffffff48;
  uint *in_stack_ffffffffffffff50;
  undefined1 uVar14;
  uint local_78;
  char local_74 [4];
  undefined8 *local_70;
  ulonglong *local_68;
  int local_60 [2];
  undefined8 *local_58;
  uint local_50 [2];
  longlong local_48;
  ulonglong *local_40;
  ulonglong *local_38;
  
  uVar8 = 0;
  local_78 = 0;
  local_74[0] = '\0';
  local_res18[0] = '\0';
  local_60[0] = 0;
  local_48 = 0;
  local_50[0] = 0;
  uVar6 = 0;
  uVar9 = 0;
  while( true ) {
    puVar11 = (undefined8 *)(param_2 + 0x18);
    puVar12 = (ulonglong *)(param_1 + 0x20);
    local_70 = puVar11;
    local_68 = puVar12;
    local_58 = puVar11;
    local_40 = puVar12;
    local_38 = puVar12;
    if ((*(uint *)((longlong)param_3 + 0x14) & 1) == 0) break;
    puVar13 = (uint *)(param_1 + 0x18);
    if (*(int *)(param_1 + 0x18) != 0x104) {
      if (*(int *)(param_1 + 0x18) == 0) {
        local_78 = WcProcessWciReparsePointOpen(param_1,*puVar11,*(longlong *)(param_2 + 0x20));
        if (local_78 != 0xc0000034) {
          if (local_78 == 0xc0000275) {
            local_78 = WcClearOfflineAttribute(*(undefined8 *)(param_2 + 0x20),*puVar11);
            if ((int)local_78 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_sDqd
                          (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x44,
                           &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                           "onecore\\base\\fs\\wci\\wcifs\\create.c",0xc5,
                           (char)*(undefined8 *)(param_2 + 0x20),(char)local_78);
              }
              FltCancelFileOpen(*puVar11,*(undefined8 *)(param_2 + 0x20));
              *puVar13 = local_78;
              *puVar12 = 0;
            }
            else {
              local_78 = WcClearSparseAttribute(*(longlong *)(param_2 + 0x20),*puVar11);
              if (-1 < (int)local_78) goto LAB_140023a3c;
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_sDqd
                          (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x45,
                           &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                           "onecore\\base\\fs\\wci\\wcifs\\create.c",0xdd,
                           (char)*(undefined8 *)(param_2 + 0x20),(char)local_78);
              }
              FltCancelFileOpen(*puVar11,*(undefined8 *)(param_2 + 0x20));
              *puVar13 = local_78;
              *puVar12 = 0;
            }
            goto LAB_140023a77;
          }
          if ((int)local_78 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar7 = *(uint *)(*(longlong *)(param_1 + 0x10) + 0x20);
              WPP_RECORDER_SF_sDqDld
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),(ulonglong)(uVar7 & 0xffffff),
                         (ulonglong)local_78,0x46,in_stack_ffffffffffffff48,
                         in_stack_ffffffffffffff50,0xf1,(char)*(undefined8 *)(param_2 + 0x20),
                         (char)uVar7,*(undefined1 *)(*(longlong *)(param_1 + 0x10) + 0x23),
                         (char)local_78);
            }
            FltCancelFileOpen(*puVar11,*(undefined8 *)(param_2 + 0x20));
            *puVar13 = local_78;
            *puVar12 = 0;
            goto LAB_140023a77;
          }
          if (local_78 == 0x103) {
            uVar8 = 1;
            goto LAB_140023a77;
          }
          if ((local_78 == 0x104) && (local_78 = 0, param_3[7] == 0)) {
            uVar7 = *(uint *)(param_3 + 2);
            FltCancelFileOpen(*puVar11,*(undefined8 *)(param_2 + 0x20));
            *puVar12 = (ulonglong)uVar7;
            local_78 = 0;
            *puVar13 = 0xc0000279;
            goto LAB_140023a77;
          }
          bVar3 = true;
          goto LAB_140023a3f;
        }
        local_78 = WcSetDispositionFile(*puVar11,*(undefined8 *)(param_2 + 0x20));
        if (((int)local_78 < 0) &&
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_SF_sDqd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x41,
                     &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                     "onecore\\base\\fs\\wci\\wcifs\\create.c",0xa2,
                     (char)*(undefined8 *)(param_2 + 0x20),(char)local_78);
        }
        FltCancelFileOpen(*puVar11,*(undefined8 *)(param_2 + 0x20));
        *puVar13 = 0xc0000034;
        *puVar12 = 0;
        if ((*(uint *)(*(longlong *)(param_1 + 0x10) + 0x20) & 0x2000) == 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_140023a77;
          if (*(short *)(WPP_GLOBAL_Control + 0x48) == 0) goto LAB_140023a77;
          uVar10 = 0x43;
          pwVar5 = (wchar_t *)(param_3[6] + 8);
          uVar14 = 0xae;
        }
        else {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_140023a77;
          if (*(short *)(WPP_GLOBAL_Control + 0x48) == 0) goto LAB_140023a77;
          uVar10 = 0x42;
          pwVar5 = (wchar_t *)(*(longlong *)(param_2 + 0x20) + 0x58);
          uVar14 = 0xac;
        }
        WPP_RECORDER_SF_sDZ(_WcVerboseRecorder,5,5,uVar10,
                            &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                            "onecore\\base\\fs\\wci\\wcifs\\create.c",uVar14,pwVar5);
        goto LAB_140023a77;
      }
      break;
    }
    lVar2 = *(longlong *)(param_1 + 0x10);
    uVar7 = *(uint *)(lVar2 + 0x20);
    if ((uVar7 >> 0xd & 1) != 0) {
      *puVar13 = 0xc000003a;
      *puVar12 = 0;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDqZDld(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
      goto LAB_140023a77;
    }
    if (local_res18[0] != '\0') {
      *puVar13 = 0xc000003a;
      *puVar12 = 0;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDqDld
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar6,(ulonglong)uVar7,0x3c,
                   in_stack_ffffffffffffff48,in_stack_ffffffffffffff50,0xd0,
                   (char)*(undefined8 *)(param_2 + 0x20),(char)*(undefined4 *)(lVar2 + 0x20),
                   *(undefined1 *)(lVar2 + 0x23),0x3a);
      }
      goto LAB_140023a77;
    }
    if (((uVar9 == *(ushort *)(*(longlong *)(param_1 + 0x28) + 6)) && ((int)uVar6 == 0)) &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_sDDqDlZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    plVar1 = (longlong *)(param_2 + 0x18);
    uVar9 = *(ushort *)(*(longlong *)(param_1 + 0x28) + 6);
    in_stack_ffffffffffffff50 = local_50;
    in_stack_ffffffffffffff48 = CONCAT62((int6)((ulonglong)in_stack_ffffffffffffff48 >> 0x10),uVar9)
    ;
    uVar6 = WcProcessWciReparsePointBounce
                      (param_1,*plVar1,(int)param_3[2],param_3[6],uVar9,in_stack_ffffffffffffff50,
                       local_res18,local_60,&local_48);
    local_78 = (uint)uVar6;
    if ((int)local_78 < 0) {
      *puVar13 = local_78;
      *puVar12 = 0;
      if (local_78 != 0xc0000034) {
        if (local_78 != 0xc000003a) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sDZDld(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
          }
        }
      }
      goto LAB_140023a77;
    }
    if (local_60[0] == 2) goto LAB_140023a77;
    *(undefined4 *)((longlong)param_3 + 0x14) = 0x80000004;
    *(undefined2 *)((longlong)param_3 + 0x2a) = 0;
    if (local_res18[0] != '\0') {
      *(undefined4 *)((longlong)param_3 + 0x14) = 0x80000000;
    }
    FltReissueSynchronousIo(*plVar1,param_1);
    if ((int)*puVar13 < 0) {
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_sDZd
                  (_WcVerboseRecorder,5,5,0x3f,&WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                   "onecore\\base\\fs\\wci\\wcifs\\create.c",0x53,(wchar_t *)(param_3[6] + 8),
                   (char)*puVar13);
      }
      break;
    }
    if (*(longlong *)(param_1 + 0x20) == 2) {
      local_78 = WcSetPlaceHolderFlagsSynchronized(param_1,*plVar1,local_48,2);
      if (((int)local_78 < 0) &&
         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_SF_sDDld(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
      puVar11 = local_70;
      goto LAB_140023a3c;
    }
    if (local_48 != 0) {
      ObfDereferenceObject();
      local_48 = 0;
    }
    uVar6 = (ulonglong)local_50[0];
  }
  puVar11 = local_70;
LAB_140023a3c:
  bVar3 = false;
LAB_140023a3f:
  puVar13 = (uint *)(param_1 + 0x18);
  uVar7 = *puVar13;
  if ((int)uVar7 < 0) {
    if (((*(uint *)((longlong)param_3 + 0x14) & 1) == 0) &&
       (((uVar7 == 0xc00000ba || (uVar7 == 0xc0000103)) ||
        ((uVar7 == 0xc0000035 && (*(char *)(*(longlong *)(param_1 + 0x10) + 0x23) == '\x02')))))) {
      if ((*(uint *)(*(longlong *)(param_1 + 0x10) + 0x20) & 0x2000) == 0) {
        local_78 = WcIsTombstoneByName(param_2,param_3[6] + 8,local_74);
        if ((int)local_78 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x48,
                                &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                                "onecore\\base\\fs\\wci\\wcifs\\create.c",0x49,(char)local_78);
          }
          local_78 = 0;
        }
        else if (local_74[0] != '\0') {
          *puVar13 = 0x104;
          *local_68 = 0xa000001f;
        }
      }
      else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x47,
                            &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                            "onecore\\base\\fs\\wci\\wcifs\\create.c",0x3f,
                            (wchar_t *)(*(longlong *)(param_2 + 0x20) + 0x58));
      }
    }
    uVar7 = *puVar13;
    if ((int)uVar7 < 0) goto LAB_140023a77;
    puVar11 = local_70;
  }
  if (uVar7 == 0x104) {
    uVar6 = *local_68;
    if (uVar6 == 0xa000001f) {
      bVar4 = WcUnionExistsForFileObject(param_1,*puVar11,*(undefined8 *)(param_2 + 0x20));
      if (bVar4) {
        local_78 = WcProcessTombstoneBounce
                             (param_1,*local_58,*(undefined8 *)(param_2 + 0x20),(longlong)param_3);
        if ((int)local_78 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x49,
                                &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                                "onecore\\base\\fs\\wci\\wcifs\\create.c",0x98,(char)local_78);
          }
          *puVar13 = local_78;
          *local_40 = 0;
          goto LAB_140023a77;
        }
      }
      else {
        if ((*(uint *)(*(longlong *)(param_1 + 0x10) + 0x20) & 0x200000) == 0) goto LAB_140023a77;
        FltRemoveOpenReparseEntry(Globals,param_1,param_3[7]);
        ExFreeToPagedLookasideList(&DAT_14000f380,param_3[7]);
        param_3[7] = 0;
        FltReissueSynchronousIo(*local_58,param_1);
      }
    }
    else {
      if (param_3[8] == 0) {
        if ((((uVar6 >> 0x1d & 1) != 0) && (uVar6 != 0xa000000c)) && (uVar6 != 0xa0000003))
        goto LAB_140023d8d;
      }
      else if ((*(uint *)(param_3[8] + 0x14) & 1) != 0) {
LAB_140023d8d:
        local_78 = WcProcessWciLinkBounce(param_1,*puVar11,*(longlong *)(param_2 + 0x20));
      }
      if ((int)local_78 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x4a,
                              &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                              "onecore\\base\\fs\\wci\\wcifs\\create.c",0xbd,(char)local_78);
        }
        *puVar13 = local_78;
        *local_38 = 0;
        goto LAB_140023a77;
      }
    }
  }
  if (((*puVar13 == 0) && ((*(uint *)(*(longlong *)(param_1 + 0x10) + 0x20) & 0x1000) != 0)) &&
     ((local_60[0] != 2 && ((*(byte *)(*(longlong *)(param_1 + 0x10) + 6) & 2) == 0)))) {
    local_70 = (undefined8 *)0x0;
    uVar6 = WcGetSetStreamHandleContext
                      (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),
                       (longlong *)&local_70);
    local_78 = (uint)uVar6;
    if (-1 < (int)local_78) {
      *(uint *)(local_70 + 5) = *(uint *)(local_70 + 5) | 1;
    }
    if (local_70 != (undefined8 *)0x0) {
      local_70 = (undefined8 *)(param_2 + 0x18);
      FltReleaseContext();
    }
    local_70 = (undefined8 *)(param_2 + 0x18);
    if ((int)local_78 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x4b,
                            &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                            "onecore\\base\\fs\\wci\\wcifs\\create.c",0xd8,(char)uVar6);
      }
      FltCancelFileOpen(*local_70,*(undefined8 *)(param_2 + 0x20));
      *(uint *)(param_1 + 0x18) = local_78;
      *(undefined8 *)(param_1 + 0x20) = 0;
      goto LAB_140023a77;
    }
  }
  if (bVar3) {
    WcAcknowledgeRedirectionEcp
              (param_1,*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20));
  }
  WcHandleQueryOnCreateEcp(param_1,*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20));
LAB_140023a77:
  if (local_48 != 0) {
    ObfDereferenceObject();
  }
  if (param_3[6] != 0) {
    if ((*(int *)(param_1 + 0x18) == -0x3ffffd87) &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_sDdZ
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x4c,
                 &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                 "onecore\\base\\fs\\wci\\wcifs\\create.c",0xfe,(char)local_78,
                 (wchar_t *)(param_3[6] + 8));
    }
    FltReleaseFileNameInformation(param_3[6]);
  }
  if ((longlong *)*param_3 != param_3) {
    FltRemoveOpenReparseEntry(Globals,param_1,param_3);
  }
  if (param_3[8] != 0) {
    FltRemoveOpenReparseEntry(Globals,param_1);
    ExFreeToPagedLookasideList(&DAT_14000f380,param_3[8]);
  }
  if (param_3[7] != 0) {
    FltRemoveOpenReparseEntry(Globals,param_1);
    ExFreeToPagedLookasideList(&DAT_14000f380,param_3[7]);
  }
  ExFreeToPagedLookasideList(&DAT_14000f400,param_3);
  return uVar8;
}



===== WcHandleQueryOnCreateEcp @ 1400247fc =====

void WcHandleQueryOnCreateEcp(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  longlong lVar7;
  longlong lVar8;
  int local_res20 [2];
  undefined4 local_48 [2];
  longlong local_40;
  longlong local_38;
  longlong local_30;
  longlong local_28 [2];
  
  local_28[0] = 0;
  local_40 = 0;
  local_48[0] = 0;
  local_res20[0] = 0;
  lVar8 = 0;
  lVar7 = 0;
  local_38 = 0;
  local_30 = 0;
  iVar3 = FltGetEcpListFromCallbackData(Globals,param_1,local_28);
  if (((((-1 < iVar3) && (local_28[0] != 0)) &&
       (iVar3 = FltFindExtraCreateParameter
                          (Globals,local_28[0],&GUID_ECP_QUERY_ON_CREATE,&local_40,local_48),
       -1 < iVar3)) &&
      ((cVar1 = FltIsEcpAcknowledged(Globals,local_40), cVar1 != '\0' &&
       ((*(uint *)(local_40 + 4) & 1) != 0)))) &&
     ((uVar5 = WcUnionsExistForInstance(param_2,param_3,local_res20,(undefined4 *)0x0),
      (char)uVar5 != '\0' && (*(int *)(local_40 + 0x4c) == local_res20[0])))) {
    if ((*(char *)(*(longlong *)(param_1 + 0x10) + 4) != '\0') ||
       ((bVar2 = WcGetContextFileObject(param_2,param_3,&local_38,&local_30), lVar7 = local_30,
        lVar8 = local_38, bVar2 &&
        ((uVar6 = WcIsPlaceHolderStream(local_38,local_30), (char)uVar6 != '\0' ||
         (uVar6 = WcIsPlaceHolderDirectory(lVar8,lVar7), (char)uVar6 != '\0')))))) {
      uVar4 = *(uint *)(local_40 + 0x48) & 0xffffe9ff;
      if (uVar4 == 0) {
        uVar4 = 0x80;
      }
      *(uint *)(local_40 + 0x48) = uVar4;
      *(undefined4 *)(local_40 + 0x4c) = 0;
    }
    if (lVar8 != 0) {
      FltReleaseContext(lVar8);
    }
    if (lVar7 != 0) {
      FltReleaseContext(lVar7);
    }
  }
  return;
}



===== WcProcessWciReparsePointBounce @ 140024990 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong WcProcessWciReparsePointBounce
                    (longlong param_1,longlong param_2,undefined4 param_3,longlong param_4,
                    ushort param_5,uint *param_6,char *param_7,int *param_8,longlong *param_9)

{
  char cVar1;
  ushort uVar2;
  short sVar3;
  ushort uVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  longlong lVar10;
  bool bVar11;
  undefined1 auStackY_198 [32];
  longlong *plVar12;
  char local_148;
  byte local_147;
  byte local_146 [6];
  int *local_140;
  undefined4 local_138 [2];
  longlong local_130;
  longlong local_128;
  longlong local_120;
  longlong local_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 local_100;
  longlong local_f8;
  longlong *local_f0;
  longlong local_e8;
  longlong local_e0;
  undefined8 local_d8;
  longlong lStack_d0;
  uint *local_c8;
  int *local_c0;
  char *local_b8;
  undefined8 local_a8 [4];
  byte *local_88;
  undefined8 local_80;
  byte *local_78;
  undefined8 local_70;
  undefined4 *local_68;
  undefined8 local_60;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_198;
  local_c8 = param_6;
  local_c0 = param_8;
  local_b8 = param_7;
  local_f0 = param_9;
  local_100 = 0;
  local_118 = 0;
  local_130 = 0;
  local_110 = 0;
  uStack_108 = 0;
  local_147 = 0;
  local_d8 = 0;
  lStack_d0 = 0;
  local_140 = (int *)0x0;
  local_148 = '\0';
  local_e8 = 0;
  local_e0 = 0;
  local_138[0] = param_3;
  local_128 = param_2;
  local_120 = param_1;
  uVar5 = FltParseFileNameInformation(param_4);
  uVar9 = (ulonglong)uVar5;
  if ((int)uVar5 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return uVar9;
    }
    WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x22,
                        &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                        "onecore\\base\\fs\\wci\\wcifs\\create.c",0x26,(char)uVar5);
    return uVar9;
  }
  if (*(short *)(param_4 + 0x68) == 2) {
    *param_7 = '\x01';
    *param_9 = 0;
    return uVar9;
  }
  uVar2 = *(ushort *)(param_4 + 8);
  lVar10 = *(longlong *)(param_4 + 0x10);
  uVar9 = (ulonglong)(uVar2 >> 1);
  uVar4 = param_5 + 2;
  if (*(short *)(lVar10 + -2 + uVar9 * 2) != 0x5c) {
    uVar4 = param_5;
  }
  uVar8 = (ulonglong)uVar4;
  if (uVar2 < uVar4) {
    return 0xc000003a;
  }
  uVar5 = RtlUShortSub(uVar2,uVar4,(short *)&local_100);
  if ((int)uVar5 < 0) {
    return (ulonglong)uVar5;
  }
  uVar5 = RtlUShortSub(*(ushort *)(param_4 + 10),(ushort)uVar8,(short *)((longlong)&local_100 + 2));
  if ((int)uVar5 < 0) {
    return (ulonglong)uVar5;
  }
  local_d8._0_4_ = CONCAT22((short)uVar8,(short)uVar8);
  lStack_d0 = lVar10 + (uVar9 - ((uVar8 & 0xffff) >> 1)) * 2;
  local_f8 = lVar10;
  uVar9 = WcParseNextPathComponentName((ushort *)&local_d8,(short *)&local_110,&local_148);
  if ((int)uVar9 < 0) {
    return uVar9 & 0xffffffff;
  }
  cVar1 = *(char *)(*(longlong *)(param_1 + 0x10) + 0x23);
  if (((local_148 == '\0') || (cVar1 == '\x01')) || (cVar1 == '\x04')) {
    uVar9 = Feature_944920889__private_IsEnabledDeviceUsageNoInline();
    lVar10 = local_120;
    if ((int)uVar9 != 0) {
      uVar5 = WcValidateTagDataReparseInfo(*(longlong *)(local_120 + 0x28));
      if ((int)uVar5 < 0) {
        return (ulonglong)uVar5;
      }
    }
    uVar9 = WcFastLookupInLayer(local_128,*(longlong *)(lVar10 + 0x28) + 8,&local_110,local_148);
    iVar6 = (int)uVar9;
    uVar8 = uVar9 & 0xffffffff;
    if (iVar6 < 0) {
      if (iVar6 == -0x3fffffcc) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return uVar8;
        }
        sVar3 = *(short *)(WPP_GLOBAL_Control + 0x48);
joined_r0x000140024c52:
        if (sVar3 == 0) {
          return uVar8;
        }
        WPP_RECORDER_SF_sDZZd();
        return uVar8;
      }
      if (iVar6 == -0x3fffffc6) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return uVar8;
        }
        sVar3 = *(short *)(WPP_GLOBAL_Control + 0x48);
        goto joined_r0x000140024c52;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDdZ
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x25,
                   &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                   "onecore\\base\\fs\\wci\\wcifs\\create.c",0x9f,(char)uVar9,(wchar_t *)&local_100)
        ;
      }
    }
  }
  plVar12 = &local_118;
  uVar5 = WcOpenPlaceHolder(local_128,(wchar_t *)&local_100,0x29,local_138[0],plVar12,&local_130,
                            &local_147);
  lVar10 = local_130;
  uVar9 = (ulonglong)uVar5;
  if ((int)uVar5 < 0) {
    if (uVar5 == 0xc0000279) {
      uVar9 = 0xc000003a;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        sVar3 = *(short *)(WPP_GLOBAL_Control + 0x48);
        goto joined_r0x000140024dc4;
      }
    }
    else if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
            (WPP_RECORDER_SF_sDdZ
                       (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x27,
                        &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                        "onecore\\base\\fs\\wci\\wcifs\\create.c",0xd2,(char)uVar5,
                        (wchar_t *)&local_100),
            (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      sVar3 = *(short *)(WPP_GLOBAL_Control + 0x48);
joined_r0x000140024dc4:
      if (sVar3 != 0) {
        WPP_RECORDER_SF_sDZZd();
      }
    }
    lVar10 = local_130;
    goto LAB_140025127;
  }
  if (local_147 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
        WPP_RECORDER_SF_sDZZd();
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,10,0x30,
                            &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                            "onecore\\base\\fs\\wci\\wcifs\\create.c",0xb4,(wchar_t *)&local_110);
      }
    }
LAB_1400252cc:
    iVar6 = 0;
LAB_1400252cf:
    *local_c0 = iVar6;
    *local_b8 = local_148;
    if (local_148 == '\0') {
      *local_f0 = 0;
    }
    else {
      *local_f0 = lVar10;
      lVar10 = 0;
    }
LAB_1400252f2:
    if (local_e8 != 0) {
      FltReleaseContext();
    }
    if (local_e0 != 0) {
      FltReleaseContext();
    }
    if (local_140 == (int *)0x0) goto LAB_140025127;
  }
  else {
    piVar7 = (int *)WcGetUnionContext(0,local_128,local_130);
    local_140 = piVar7;
    if (piVar7 == (int *)0x0) {
      if (local_148 == '\0') {
        uVar9 = 0xc000003a;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDdZ
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x29,
                     &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                     "onecore\\base\\fs\\wci\\wcifs\\create.c",0xfc,0x3a,(wchar_t *)&local_100);
        }
        goto LAB_140025127;
      }
      uVar9 = 0;
      goto LAB_1400252cc;
    }
    iVar6 = piVar7[6];
    if (iVar6 == 1) {
      uVar5 = WcGetSetContextFileObject(local_128,lVar10,piVar7,1,plVar12,&local_e8,&local_e0);
      uVar9 = (ulonglong)uVar5;
      if (-1 < (int)uVar5) {
        if (uVar5 == 0x104) goto LAB_1400250c8;
        uVar9 = WcPartiallyExpandDirectory
                          (local_120,local_128,lVar10,local_118,local_148,(wchar_t *)&local_110);
        iVar6 = (int)uVar9;
        uVar9 = uVar9 & 0xffffffff;
        if (iVar6 < 0) {
          if (iVar6 == -0x3ffffdd3) {
            if (*local_c8 < 0x14) {
              *local_c8 = *local_c8 + 1;
              local_148 = '\0';
            }
            else {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x2b,
                                   &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                                   "onecore\\base\\fs\\wci\\wcifs\\create.c",0x43);
              }
              if ((5 < DAT_14000f060) &&
                 (uVar9 = _tlgKeywordOn(0x14000f060,0x400000000000), (char)uVar9 != '\0')) {
                local_88 = &local_147;
                local_147 = 4;
                local_78 = local_146;
                local_80 = 1;
                local_68 = local_138;
                local_146[0] = 8;
                local_70 = 1;
                local_138[0] = 0xc000022d;
                local_60 = 4;
                _tlgWriteTransfer_EtwWriteTransfer(0x14000f060,&DAT_14000b442,0,0,5,local_a8);
              }
            }
          }
          else if (iVar6 != -0x3fffffcc) goto LAB_1400252f2;
          uVar9 = 0;
        }
        else if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
                (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
          WPP_RECORDER_SF_sDZZd();
        }
LAB_140024ffe:
        iVar6 = local_140[6];
        goto LAB_1400252cf;
      }
      if (uVar5 == 0xc0000275) {
LAB_1400250c8:
        uVar9 = 0;
      }
      else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDdZ
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x2a,
                   &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                   "onecore\\base\\fs\\wci\\wcifs\\create.c",0x29,(char)uVar5,(wchar_t *)&local_100)
        ;
      }
      goto LAB_1400252f2;
    }
    if (iVar6 == 2) {
      uVar9 = Feature_944920889__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar9 != 0) {
        uVar5 = WcValidateTagDataReparseInfo(*(longlong *)(local_120 + 0x28));
        uVar9 = (ulonglong)uVar5;
        if ((int)uVar5 < 0) goto LAB_140025122;
        piVar7 = local_140;
      }
      if ((*(uint *)(*(longlong *)(local_120 + 0x28) + 0xc) & 4) == 0) {
        uVar5 = WcRedirectCallbackData(local_120,(longlong)piVar7,(short *)&local_d8);
        uVar9 = (ulonglong)uVar5;
        if (-1 < (int)uVar5) goto LAB_140024ffe;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x2d,
                              &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                              "onecore\\base\\fs\\wci\\wcifs\\create.c",0x9d,(char)uVar5);
        }
      }
      else {
        bVar11 = local_148 != '\0';
        local_148 = -local_148;
        uVar9 = (ulonglong)((-(uint)bVar11 & 0xfffffffa) + 0xc000003a);
      }
    }
    else {
      uVar9 = 0xc000000d;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDdd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x2e,
                   &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                   "onecore\\base\\fs\\wci\\wcifs\\create.c",0xa5,(char)iVar6,0xd);
      }
    }
  }
LAB_140025122:
  WcReleaseUnionContext(local_140);
LAB_140025127:
  if (local_118 != 0) {
    FltClose(local_118);
  }
  if (lVar10 != 0) {
    ObfDereferenceObject(lVar10);
  }
  return uVar9;
}



===== WcIsTombstoneByName @ 140025338 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int WcIsTombstoneByName(longlong param_1,undefined8 param_2,undefined1 *param_3)

{
  int iVar1;
  undefined1 auStackY_f8 [32];
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined1 local_78 [56];
  uint local_40;
  int local_3c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_f8;
  local_9c = 0;
  local_b8 = 0x30;
  local_88 = 0;
  uStack_80 = 0;
  memset(local_78,0,0x48);
  local_b0 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a0 = 0x200;
  local_a8 = param_2;
  iVar1 = FltQueryInformationByName(Globals,*(undefined8 *)(param_1 + 0x18),&local_b8,&local_88);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x1b,
                          &WPP_6c993b8198b53d328fc429e03cc469de_Traceguids,
                          "onecore\\base\\fs\\wci\\wcifs\\tombstone.c",0x7c,(char)iVar1);
    }
  }
  else if (((local_40 & 0x400) == 0) || (local_3c != -0x5fffffe1)) {
    *param_3 = 0;
  }
  else {
    *param_3 = 1;
  }
  return iVar1;
}



===== WcProcessWciReparsePointOpen @ 14002547c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint WcProcessWciReparsePointOpen(longlong param_1,undefined8 param_2,longlong param_3)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  bool bVar5;
  byte bVar6;
  uint uVar7;
  ulonglong uVar8;
  undefined8 *puVar9;
  longlong lVar10;
  longlong lVar11;
  undefined4 uVar12;
  undefined2 uVar13;
  uint uVar14;
  undefined1 auStackY_168 [32];
  undefined8 in_stack_fffffffffffffeb8;
  undefined1 uVar15;
  longlong local_110;
  longlong local_108;
  ushort local_100;
  undefined8 local_f8;
  longlong local_f0;
  wchar_t local_e8 [4];
  longlong lStack_e0;
  uint local_d8;
  undefined4 local_d4;
  int local_d0 [2];
  int *local_c8;
  longlong local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 local_98 [4];
  uint *local_78;
  undefined8 local_70;
  undefined4 *local_68;
  undefined8 local_60;
  int *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_168;
  local_a8 = 0;
  local_c0 = *(longlong *)(param_3 + 0x18);
  lVar10 = *(longlong *)(param_1 + 0x10);
  local_b8 = 0;
  uStack_b0 = 0;
  local_e8[0] = L'\0';
  local_e8[1] = L'\0';
  local_e8[2] = L'\0';
  local_e8[3] = L'\0';
  lStack_e0 = 0;
  uVar7 = *(uint *)(lVar10 + 0x20);
  local_110 = 0;
  uVar2 = *(uint *)(*(longlong *)(lVar10 + 0x18) + 0x10);
  local_100 = *(ushort *)(lVar10 + 0x2a);
  local_108 = 0;
  if (((local_100 - 1 & 0xfffb) == 0) &&
     (((((uVar2 == 0x1200a0 || (uVar2 == 0x120020)) || (uVar2 == 0x1000a1)) ||
       ((uVar2 - 0x100020 < 2 || (uVar2 == 0x20)))) || (uVar2 == 0x1200a9)))) {
    bVar5 = true;
  }
  else {
    bVar5 = false;
  }
  local_f8 = param_2;
  local_f0 = param_1;
  local_c8 = (int *)WcGetUnionContext(param_1,param_2,param_3);
  uVar14 = uVar7 & 0x41;
  if (local_c8 == (int *)0x0) {
    if (uVar14 == 0) {
      uVar7 = FltQueryInformationFile(param_2,param_3,&local_b8,0x18);
      if ((int)uVar7 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDqd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x13,
                     &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                     "onecore\\base\\fs\\wci\\wcifs\\create.c",0x72,(char)param_3,(char)uVar7);
        }
        return 0xc0000022;
      }
      if (local_a8._5_1_ != '\0') {
        return uVar7;
      }
    }
    else if ((uVar7 & 0x40) == 0) {
      return 0;
    }
    return 0x104;
  }
  uVar14 = WcGetSetContextFileObject
                     (param_2,param_3,local_c8,uVar14,in_stack_fffffffffffffeb8,&local_110,
                      &local_108);
  uVar7 = 0;
  if ((*(byte *)(*(longlong *)(param_1 + 0x10) + 6) & 2) != 0) {
    if ((*(longlong *)(param_1 + 0x20) == 0) || (uVar12 = 0, *(longlong *)(param_1 + 0x20) == 3)) {
      uVar12 = 1;
    }
    if ((5 < DAT_14000f060) &&
       (uVar8 = _tlgKeywordOn(0x14000f060,0x400000000000), (char)uVar8 != '\0')) {
      local_78 = &local_d8;
      local_68 = &local_d4;
      local_70 = 4;
      local_60 = 4;
      local_50 = 4;
      local_d0[0] = local_c8[0xe];
      local_58 = local_d0;
      local_d8 = uVar14;
      local_d4 = uVar12;
      _tlgWriteTransfer_EtwWriteTransfer(0x14000f060,&DAT_14000b4a0,0,0,5,local_98);
    }
  }
  lVar11 = local_108;
  lVar10 = local_110;
  if ((int)uVar14 < 0) {
    if (uVar14 == 0xc0000275) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x15,
                          &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                          "onecore\\base\\fs\\wci\\wcifs\\create.c",0xc4,(char)uVar14);
    }
    goto LAB_140025dc5;
  }
  if (uVar14 == 0x104) goto LAB_140025dcf;
  uVar8 = WcIsPlaceHolderDirectory(local_110,local_108);
  uVar7 = uVar14;
  if ((char)uVar8 == '\0') {
    uVar8 = WcIsPlaceHolderStream(lVar10,lVar11);
    if ((char)uVar8 != '\0') {
      if ((*(longlong *)(local_f0 + 0x20) == 3) || (*(longlong *)(local_f0 + 0x20) == 0)) {
        uVar14 = WcExpandAndWait(local_f0,local_f8,param_3,lVar10,1,0x13);
        uVar7 = uVar14;
        if ((int)uVar14 < 0) goto LAB_140025dcf;
        if (*(int *)(lVar11 + 0x14) == 1) {
          uVar14 = IoSetShadowFileInformation(param_3,0,0);
          if ((int)uVar14 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_140025924;
            WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x16,
                               &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                               "onecore\\base\\fs\\wci\\wcifs\\create.c",0xf5);
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar13 = 0x17;
            uVar15 = 0xf8;
LAB_1400258f7:
            WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,uVar13,
                               &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                               "onecore\\base\\fs\\wci\\wcifs\\create.c",uVar15);
          }
        }
      }
      else if ((uVar2 & 6) != 0) {
        uVar14 = WcExpandAndWait(local_f0,local_f8,param_3,lVar10,1,0x10);
        uVar7 = uVar14;
        if ((int)uVar14 < 0) goto LAB_140025dcf;
        if (*(int *)(lVar11 + 0x14) == 1) {
          uVar14 = IoSetShadowFileInformation(param_3,0,0);
          if ((int)uVar14 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_140025924;
            WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x18,
                               &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                               "onecore\\base\\fs\\wci\\wcifs\\create.c",0x11);
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar13 = 0x19;
            uVar15 = 0x14;
            goto LAB_1400258f7;
          }
        }
      }
LAB_140025924:
      uVar8 = WcIsPlaceHolderStream(lVar10,lVar11);
      uVar7 = uVar14;
      if ((char)uVar8 == '\0') goto LAB_140025dcf;
      ExAcquireFastMutex(lVar10 + 8);
      lVar4 = *(longlong *)(lVar10 + 0x40);
      lStack_e0 = lVar4 + 0x22;
      local_e8[1] = *(undefined2 *)(lVar4 + 0x20);
      local_e8[0] = *(undefined2 *)(lVar4 + 0x20);
      iVar3 = *(int *)(lVar11 + 0x14);
      if (iVar3 == 2) {
        if (bVar5) {
          if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
             (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
            WPP_RECORDER_SF_sDZ(_WcVerboseRecorder,5,5,0x1d,
                                &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                                "onecore\\base\\fs\\wci\\wcifs\\create.c",0xac,local_e8);
          }
          uVar14 = WcCopySectionObjectPointers(local_f8,param_3);
          if ((int)uVar14 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_sDZd
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x1e,
                         &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                         "onecore\\base\\fs\\wci\\wcifs\\create.c",0xb5,local_e8,(char)uVar14);
            }
LAB_140025c00:
            uVar14 = 0;
          }
        }
      }
      else if (bVar5) {
        uVar14 = WcCopySectionObjectPointers(local_f8,param_3);
        if ((int)uVar14 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sDZd
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x1a,
                       &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                       "onecore\\base\\fs\\wci\\wcifs\\create.c",0x5c,local_e8,(char)uVar14);
          }
          uVar14 = 0;
          uVar12 = 2;
        }
        else {
          uVar12 = 1;
        }
        *(undefined4 *)(lVar11 + 0x14) = uVar12;
      }
      else if (((iVar3 == 1) && ((uVar2 & 0xffedff76) == 0)) &&
              ((uVar2 & 1) == 0 || (local_100 >> 1 & 1) == 0)) {
        uVar14 = WcCopySectionObjectPointers(local_f8,param_3);
        if ((int)uVar14 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sDZd
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x1b,
                       &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                       "onecore\\base\\fs\\wci\\wcifs\\create.c",0x81,local_e8,(char)uVar14);
          }
          *(undefined4 *)(lVar11 + 0x14) = 2;
          goto LAB_140025c00;
        }
      }
      else if ((uVar2 & 0xffefff77) != 0) {
        if ((iVar3 == 1) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_SF_sDZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x1c,
                              &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                              "onecore\\base\\fs\\wci\\wcifs\\create.c",0x98,local_e8);
        }
        *(undefined4 *)(lVar11 + 0x14) = 2;
      }
      ExReleaseFastMutex(lVar10 + 8);
      lVar10 = local_c0;
      if ((*(byte *)(local_c0 + 6) & 4) != 0) {
        if ((*(byte *)(local_c0 + 4) & 0x40) == 0) {
          *(byte *)(local_c0 + 6) = *(byte *)(local_c0 + 6) & 0xfb;
        }
        else {
          ExAcquireFastMutex(*(undefined8 *)(local_c0 + 0x30));
          pbVar1 = (byte *)(lVar10 + 6);
          *pbVar1 = *pbVar1 & 0xfb;
          ExReleaseFastMutex(*(undefined8 *)(lVar10 + 0x30));
        }
      }
      lVar10 = local_f0;
      if ((uVar2 >> 8 & 1) != 0) {
        uVar14 = WcSetPlaceHolderFlagsSynchronized(local_f0,local_f8,param_3,2);
      }
      lVar4 = local_108;
      if ((*(uint *)(lVar11 + 0x10) & 1) == 0) {
        puVar9 = (undefined8 *)WcGetSource(local_108);
        uVar14 = FltFlushBuffers2(*puVar9,puVar9[2],2,lVar10);
        if (-1 < (int)uVar14) {
          LOCK();
          *(uint *)(lVar4 + 0x10) = *(uint *)(lVar4 + 0x10) | 1;
          UNLOCK();
          goto LAB_140025dc5;
        }
        lVar11 = lVar4;
        if ((uVar14 == 0xc00000a2) ||
           ((uVar14 == 0xc0000022 && ((*(uint *)(puVar9[4] + 0x10) & 1) != 0)))) {
          uVar14 = 0;
        }
        else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDZd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x1f,
                     &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                     "onecore\\base\\fs\\wci\\wcifs\\create.c",0x10,local_e8,(char)uVar14);
        }
      }
      else {
LAB_140025dc5:
        lVar11 = local_108;
      }
      lVar10 = local_110;
      uVar7 = uVar14;
      goto LAB_140025dcf;
    }
    bVar6 = WcIsPlaceHolder(lVar10);
    if (bVar6 == 0) goto LAB_140025924;
    if ((uVar2 & 0x116) == 0) goto LAB_140025dcf;
    param_2 = local_f8;
  }
  else if ((uVar2 & 0x106) == 0) goto LAB_140025dcf;
  uVar7 = WcSetPlaceHolderFlagsSynchronized(local_f0,param_2,param_3,2);
LAB_140025dcf:
  if (lVar10 != 0) {
    FltReleaseContext(lVar10);
  }
  if (lVar11 != 0) {
    FltReleaseContext(lVar11);
  }
  WcReleaseUnionContext(local_c8);
  return uVar7;
}



===== WcPreCleanup @ 140025e30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 WcPreCleanup(longlong param_1,longlong param_2,undefined8 *param_3)

{
  bool bVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  longlong *plVar6;
  ulonglong uVar7;
  short sVar8;
  longlong lVar9;
  longlong lVar10;
  undefined2 uVar11;
  undefined8 uVar12;
  undefined1 auStackY_1d8 [32];
  longlong *plVar13;
  undefined1 uVar14;
  undefined1 uVar15;
  byte local_158 [8];
  longlong local_150;
  uint local_148 [2];
  longlong local_140;
  longlong local_138;
  longlong local_130;
  longlong local_128;
  undefined8 *local_120;
  longlong local_118;
  longlong local_110;
  longlong local_108;
  longlong local_100;
  longlong local_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  longlong local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  ulonglong uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_98 [4];
  byte *local_78;
  undefined8 local_70;
  byte *local_68;
  undefined8 local_60;
  uint *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1d8;
  lVar10 = 0;
  local_130 = 0;
  local_118 = 0;
  plVar6 = (longlong *)0x0;
  uVar12 = 1;
  local_128 = 0;
  local_150 = 0;
  lVar9 = 0;
  local_110 = 0;
  piVar5 = (int *)0x0;
  local_138 = 0;
  local_158[0] = 0;
  local_140 = 0;
  local_108 = 0;
  local_f8 = 0;
  local_100 = 0;
  local_f0 = 0;
  uStack_e8 = 0;
  local_c0 = 0;
  local_e0 = 0;
  uStack_d8 = 0;
  uStack_b8 = uStack_b8 & 0xffffffff00000000;
  local_d0 = 0;
  uStack_c8 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_120 = param_3;
  iVar3 = FltGetStreamHandleContext
                    (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),&local_128);
  if (((iVar3 < 0) || ((*(uint *)(local_128 + 0x28) & 1) == 0)) ||
     (local_148[0] = WcPrepareForDelete(param_1,param_2), -1 < (int)local_148[0])) {
    bVar1 = WcGetContextFileObject
                      (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),&local_118,
                       &local_130);
    lVar10 = local_130;
    if ((!bVar1) || (local_130 == 0)) goto LAB_140025f02;
    piVar5 = (int *)WcGetUnionContext(param_1,*(undefined8 *)(param_2 + 0x18),
                                      *(undefined8 *)(param_2 + 0x20));
    if ((piVar5 != (int *)0x0) && (*(char *)(lVar10 + 0x1c) != '\0')) {
      plVar6 = (longlong *)ExAllocateFromPagedLookasideList(&DAT_14000f500);
      if (plVar6 == (longlong *)0x0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140025f02;
        uVar15 = 0x9a;
        uVar11 = 0x38;
        uVar14 = 0xb9;
        goto LAB_1400260e9;
      }
      iVar3 = FltGetFileNameInformation(param_1,0x301,&local_150);
      if ((iVar3 < 0) || (iVar3 = FltParseFileNameInformation(local_150), iVar3 < 0))
      goto LAB_140025f02;
      uStack_e8 = *(undefined8 *)(local_150 + 0x10);
      sVar8 = *(short *)(local_150 + 8) - *(short *)(local_150 + 0x58);
      sVar2 = sVar8 + -2;
      if (sVar2 == *(short *)(local_150 + 0x18)) {
        sVar2 = sVar8;
      }
      local_f0 = CONCAT62(*(undefined6 *)(local_150 + 10),sVar2);
      plVar13 = &local_110;
      iVar3 = WcOpenPlaceHolder(*(undefined8 *)(param_2 + 0x18),(wchar_t *)&local_f0,0x29,piVar5[9],
                                plVar13,&local_138,local_158);
      lVar9 = local_138;
      if ((((iVar3 < 0) || (local_158[0] == 0)) ||
          (uVar4 = WcGetSetContextFileObject
                             (*(undefined8 *)(param_2 + 0x18),local_138,piVar5,1,plVar13,&local_100,
                              &local_f8), (int)uVar4 < 0)) || (uVar4 == 0x104)) goto LAB_140025f02;
      *(undefined1 *)(plVar6 + 2) = 0;
      bVar1 = (*(uint *)(lVar10 + 0x18) & 0x10) != 0;
      if (bVar1) {
        *(undefined1 *)(plVar6 + 2) = 1;
      }
      uVar4 = WcAddInMemoryTombstone
                        (param_1,*(undefined8 *)(param_2 + 0x18),local_150 + 0x58,bVar1,lVar9);
      if ((int)uVar4 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x39,
                              &WPP_27ac746799d63ca1d37704ce911b8053_Traceguids,
                              "onecore\\base\\fs\\wci\\wcifs\\wcifs.c",7,(char)uVar4);
        }
        if ((5 < DAT_14000f060) &&
           (uVar7 = _tlgKeywordOn(0x14000f060,0x400000000000), (char)uVar7 != '\0')) {
          local_78 = local_158;
          local_158[0] = 3;
          local_68 = local_158 + 1;
          local_70 = 1;
          local_58 = local_148;
          local_158[1] = 4;
          local_60 = 1;
          local_50 = 4;
          local_148[0] = uVar4;
          _tlgWriteTransfer_EtwWriteTransfer(0x14000f060,&DAT_14000be56,0,0,5,local_98);
        }
        goto LAB_140025f02;
      }
      *(undefined1 *)((longlong)plVar6 + 0x11) = 0;
      plVar6[3] = 0;
      *plVar6 = local_150;
      local_150 = 0;
      plVar6[1] = lVar9;
      *local_120 = plVar6;
    }
    uVar12 = 0;
LAB_140026093:
    lVar9 = 0;
    plVar6 = (longlong *)0x0;
  }
  else {
    plVar6 = (longlong *)ExAllocateFromPagedLookasideList(&DAT_14000f500);
    if (plVar6 == (longlong *)0x0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140025f02;
      uVar15 = 0x9a;
      uVar11 = 0x35;
      uVar14 = 0x6b;
    }
    else {
      *(undefined1 *)((longlong)plVar6 + 0x11) = 1;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x36,
                            &WPP_27ac746799d63ca1d37704ce911b8053_Traceguids,
                            "onecore\\base\\fs\\wci\\wcifs\\wcifs.c",0x71,(char)local_148[0]);
      }
      iVar3 = FltGetFileNameInformation(param_1,0x101,&local_150);
      if (iVar3 < 0) goto LAB_140025f02;
      local_d0 = local_150 + 8;
      local_e0 = CONCAT44(local_e0._4_4_,0x30);
      uStack_d8 = 0;
      uStack_c8 = CONCAT44(uStack_c8._4_4_,0x240);
      local_c0 = 0;
      uStack_b8 = 0;
      iVar3 = FltCreateFileEx2(Globals,*(undefined8 *)(param_2 + 0x18),&local_140,&local_108);
      if (-1 < iVar3) {
        *plVar6 = 0;
        uVar12 = 5;
        plVar6[1] = 0;
        plVar6[3] = local_140;
        local_140 = 0;
        *local_120 = plVar6;
        goto LAB_140026093;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140025f02;
      uVar15 = (undefined1)iVar3;
      uVar11 = 0x37;
      uVar14 = 0x95;
    }
LAB_1400260e9:
    WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,uVar11,
                        &WPP_27ac746799d63ca1d37704ce911b8053_Traceguids,
                        "onecore\\base\\fs\\wci\\wcifs\\wcifs.c",uVar14,uVar15);
  }
LAB_140025f02:
  if (local_150 != 0) {
    FltReleaseFileNameInformation();
  }
  if (plVar6 != (longlong *)0x0) {
    ExFreeToPagedLookasideList(&DAT_14000f500,plVar6);
  }
  if (piVar5 != (int *)0x0) {
    WcReleaseUnionContext(piVar5);
  }
  if (local_118 != 0) {
    FltReleaseContext();
  }
  if (lVar10 != 0) {
    FltReleaseContext(lVar10);
  }
  if (local_128 != 0) {
    FltReleaseContext();
  }
  if (local_110 != 0) {
    FltClose();
  }
  if (lVar9 != 0) {
    ObfDereferenceObject(lVar9);
  }
  if (local_140 != 0) {
    FltClose();
  }
  if (local_108 != 0) {
    ObfDereferenceObject();
  }
  if (local_100 != 0) {
    FltReleaseContext();
  }
  if (local_f8 != 0) {
    FltReleaseContext();
  }
  return uVar12;
}



===== WcReleaseUnionContext @ 140026558 =====

void WcReleaseUnionContext(int *param_1)

{
  int iVar1;
  
  LOCK();
  iVar1 = *param_1;
  *param_1 = *param_1 + -1;
  UNLOCK();
  if (iVar1 == 1) {
    WcCleanupUnionContext((longlong)param_1);
  }
  return;
}



===== WcGetSetContextFileObject @ 14002657c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint WcGetSetContextFileObject
               (undefined8 param_1,longlong param_2,int *param_3,uint param_4,undefined8 param_5,
               longlong *param_6,longlong *param_7)

{
  longlong lVar1;
  bool bVar2;
  byte bVar3;
  uint uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  longlong lVar7;
  undefined2 uVar8;
  undefined4 uVar9;
  int *piVar10;
  undefined1 auStackY_118 [32];
  undefined1 uVar11;
  undefined1 uVar12;
  longlong local_c0;
  longlong local_b8;
  uint local_b0;
  uint local_ac;
  undefined8 local_a8;
  undefined8 ****local_a0;
  undefined8 ****local_98;
  int *local_90;
  int *local_88;
  wchar_t local_80;
  undefined1 auStack_7e [6];
  longlong lStack_78;
  longlong *local_70;
  longlong *local_68;
  undefined8 local_60;
  longlong lStack_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_118;
  local_70 = param_6;
  local_68 = param_7;
  local_50 = 0;
  local_98 = &local_a0;
  local_a0 = &local_a0;
  uVar4 = 0;
  local_b8 = 0;
  local_c0 = 0;
  piVar10 = (int *)0x0;
  local_88 = (int *)0x0;
  local_ac = 0;
  local_60 = 0;
  lStack_58 = 0;
  _local_80 = 0;
  lStack_78 = 0;
  local_b0 = param_4;
  local_a8 = param_1;
  local_90 = param_3;
  bVar2 = WcGetContextFileObject(param_1,param_2,&local_c0,&local_b8);
  if (bVar2) {
    bVar3 = WcIsExpanded(local_c0);
    if (bVar3 != 0) goto LAB_14002680f;
    lVar7 = local_b8;
    if (local_b8 == 0) {
      piVar10 = *(int **)(local_c0 + 0x40);
      goto LAB_140026644;
    }
  }
  else {
    uVar4 = WcGetReparseData(param_1,param_2,(uint)*(ushort *)(param_2 + 0x58),(longlong *)&local_88
                             ,&local_ac);
    piVar10 = local_88;
    if ((int)uVar4 < 0) goto LAB_14002682f;
    if (*local_88 != param_3[9]) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0xb,
                            &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                            "onecore\\base\\fs\\wci\\wcifs\\create.c",0xf7,(char)*local_88);
      }
      uVar4 = 0x104;
      goto LAB_14002682f;
    }
    uVar4 = WcValidateWcReparseInfo((longlong)local_88,local_ac);
    if ((int)uVar4 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0xc,
                            &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                            "onecore\\base\\fs\\wci\\wcifs\\create.c",3,(char)uVar4);
      }
      goto LAB_14002682f;
    }
LAB_140026644:
    _local_80 = CONCAT62(CONCAT42(auStack_7e._2_4_,(short)piVar10[8]),(short)piVar10[8]);
    lStack_78 = (longlong)piVar10 + 0x22;
    uVar4 = FltQueryInformationFile(param_1,param_2,&local_60,0x18);
    uVar12 = (undefined1)param_2;
    if ((int)uVar4 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar8 = 0xd;
        uVar11 = 0x1b;
        bVar3 = 2;
LAB_1400269e8:
        WPP_RECORDER_SF_sDqd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar3,5,uVar8,
                   &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                   "onecore\\base\\fs\\wci\\wcifs\\create.c",uVar11,uVar12,(char)uVar4);
      }
LAB_140026a02:
      uVar4 = 0xc0000022;
      goto LAB_14002682f;
    }
    if ((((local_50._6_1_ == '\0') && (local_50._7_1_ == '\0')) &&
        (uVar4 = FltGetStreamContext(local_a8,param_2,&local_b8), (int)uVar4 < 0)) &&
       ((local_50._5_1_ == '\0' || (local_b0 = local_b0 | 1, (piVar10[3] & 4U) == 0)))) {
      uVar5 = IoGetSilo(param_2);
      uVar6 = PsGetParentSilo(uVar5);
      uVar6 = WcGetSourceList(uVar6,(longlong)local_90,(longlong)(piVar10 + 2),local_b0,
                              (longlong *)&local_a0);
      uVar4 = (uint)uVar6;
      if ((int)uVar4 < 0) {
        if ((local_50._5_1_ == '\0') || ((uVar4 != 0xc0000034 && (uVar4 != 0xc000003a)))) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sDZd
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0xf,
                       &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                       "onecore\\base\\fs\\wci\\wcifs\\create.c",99,&local_80,(char)uVar6);
          }
          if (uVar4 == 0xc000003a) {
            uVar4 = 0xc0000034;
          }
          goto LAB_14002682f;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0xe,
                              &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                              "onecore\\base\\fs\\wci\\wcifs\\create.c",0x50,&local_80);
        }
        uVar4 = 0;
      }
    }
    if ((!bVar2) && (uVar4 = FltGetFileContext(local_a8,param_2,&local_c0), (int)uVar4 < 0)) {
      uVar9 = 2;
      if ((piVar10[3] & 4U) != 0) {
        if (local_50._5_1_ == '\0') {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sDqd
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x10,
                       &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                       "onecore\\base\\fs\\wci\\wcifs\\create.c",0x98,uVar12,(char)uVar4);
          }
        }
        else {
          uVar9 = 3;
        }
      }
      uVar4 = WcGetSetFileContext(local_a8,param_2,uVar9,(longlong)piVar10,&local_c0);
      if ((int)uVar4 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar8 = 0x11;
          bVar3 = 4;
          uVar11 = 0xa7;
          goto LAB_1400269e8;
        }
        goto LAB_140026a02;
      }
      piVar10 = (int *)0x0;
    }
    if ((local_50._6_1_ == '\0') && (local_50._7_1_ == '\0')) {
      lVar7 = local_b8;
      if (local_b8 != 0) goto LAB_140026813;
      if ((undefined8 *****)local_a0 == &local_a0) {
        uVar4 = 0x10;
      }
      else {
        uVar4 = *(uint *)(local_a0[3] + 3);
      }
      uVar6 = WcGetSetStreamContext
                        (local_a8,param_2,local_c0,local_90,uVar4,lStack_58,(longlong *)&local_a0,
                         &local_b8);
      uVar4 = (uint)uVar6;
      if ((int)uVar4 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDqd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x12,
                     &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                     "onecore\\base\\fs\\wci\\wcifs\\create.c",0xd3,uVar12,(char)uVar6);
        }
        goto LAB_14002682f;
      }
    }
LAB_14002680f:
    lVar7 = local_b8;
  }
LAB_140026813:
  lVar1 = local_c0;
  local_c0 = 0;
  local_b8 = 0;
  *local_70 = lVar1;
  *local_68 = lVar7;
LAB_14002682f:
  if (local_b8 != 0) {
    FltReleaseContext();
  }
  if (local_c0 != 0) {
    FltReleaseContext();
  }
  if ((!bVar2) && (piVar10 != (int *)0x0)) {
    ExFreePoolWithTag(piVar10,0x69724357);
  }
  WcFreeSourceList((longlong *)&local_a0);
  return uVar4;
}



===== WcFreeSourceList @ 140026bd8 =====

void WcFreeSourceList(longlong *param_1)

{
  longlong *plVar1;
  undefined8 *puVar2;
  code *pcVar3;
  
  while( true ) {
    if ((longlong *)*param_1 == param_1) {
      return;
    }
    plVar1 = (longlong *)param_1[1];
    if (((longlong *)*plVar1 != param_1) ||
       (puVar2 = (undefined8 *)plVar1[1], (longlong *)*puVar2 != plVar1)) break;
    param_1[1] = (longlong)puVar2;
    *puVar2 = param_1;
    if ((*(uint *)(plVar1 + 4) & 1) != 0) {
      if (plVar1[2] == 0) {
        FltClose();
      }
      else {
        WcCloseHandleAsync(*(undefined8 *)(plVar1[3] + 8),plVar1[2]);
      }
      ObfDereferenceObject(*(undefined8 *)(plVar1[3] + 0x10));
      ExFreePoolWithTag(plVar1[3],0x73734357);
    }
    ExFreePoolWithTag(plVar1,0x65734357);
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== WcGetReparseData @ 140026c94 =====

int WcGetReparseData(undefined8 param_1,undefined8 param_2,int param_3,longlong *param_4,
                    uint *param_5)

{
  longlong lVar1;
  byte bVar2;
  int iVar3;
  undefined2 uVar4;
  uint local_res18 [4];
  ulonglong in_stack_ffffffffffffffb8;
  undefined1 uVar5;
  int iVar6;
  
  local_res18[0] = 0;
  iVar3 = param_3 + 0x24;
  while( true ) {
    lVar1 = ExAllocatePool2(0x100,iVar3,0x69724357);
    if (lVar1 == 0) {
      return -0x3fffff66;
    }
    in_stack_ffffffffffffffb8 = in_stack_ffffffffffffffb8 & 0xffffffff00000000;
    iVar3 = FltFsControlFile(param_1,param_2,0x900a8,0,in_stack_ffffffffffffffb8,lVar1,iVar3,
                             local_res18);
    if ((local_res18[0] < 8) || (iVar3 != -0x7ffffffb)) break;
    iVar3 = *(ushort *)(lVar1 + 4) + 8;
    ExFreePoolWithTag(lVar1,0x69724357);
  }
  if (iVar3 == -0x3ffffd8b) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140026e55;
    iVar6 = -0x3ffffd8b;
    uVar4 = 0x82;
    uVar5 = 0xf9;
    bVar2 = 4;
  }
  else {
    if (-1 < iVar3) {
      if (*(ushort *)(lVar1 + 4) + 8 <= local_res18[0]) {
        *param_4 = lVar1;
        *param_5 = local_res18[0];
        return iVar3;
      }
      iVar3 = -0x3ffffefe;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDqd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x84,
                   &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                   "onecore\\base\\fs\\wci\\wcifs\\utils.c",0xf,(char)param_2,2);
      }
      goto LAB_140026e55;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140026e55;
    uVar4 = 0x83;
    uVar5 = 1;
    bVar2 = 2;
    iVar6 = iVar3;
  }
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar2,5,uVar4,
                      &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                      "onecore\\base\\fs\\wci\\wcifs\\utils.c",uVar5,(char)iVar6);
LAB_140026e55:
  ExFreePoolWithTag(lVar1,0x69724357);
  return iVar3;
}



===== WcGetSetFileContext @ 140026e8c =====

int WcGetSetFileContext(undefined8 param_1,undefined8 param_2,undefined4 param_3,longlong param_4,
                       longlong *param_5)

{
  int iVar1;
  longlong *local_38;
  longlong local_30;
  longlong *local_28 [2];
  
  local_38 = (longlong *)0x0;
  local_28[0] = (longlong *)0x0;
  local_30 = 0;
  iVar1 = FltAllocateContext(Globals,4,0x60,0x200,&local_38);
  if (-1 < iVar1) {
    FltGetInstanceContext(param_1,&local_30);
    FltReferenceContext(local_30);
    *local_38 = local_30;
    *(undefined4 *)(local_38 + 0xb) = param_3;
    local_38[10] = 0;
    local_38[8] = param_4;
    local_38[2] = 0;
    *(undefined4 *)(local_38 + 3) = 0;
    *(undefined4 *)(local_38 + 1) = 1;
    KeInitializeEvent(local_38 + 4,1,0);
    ExInitializeRundownProtection(local_38 + 9);
    iVar1 = FltSetFileContext(param_1,param_2,1,local_38,local_28);
    if (iVar1 < 0) {
      if (iVar1 != -0x3fe3fffe) {
        local_38[8] = 0;
        FltReleaseContext(local_38);
        goto LAB_140026fec;
      }
      FltReleaseContext(local_38);
      iVar1 = 0;
      local_38 = local_28[0];
    }
    *param_5 = (longlong)local_38;
  }
LAB_140026fec:
  if (local_30 != 0) {
    FltReleaseContext();
  }
  return iVar1;
}



===== WcGetSetStreamContext @ 140027024 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001400275ac) */

ulonglong WcGetSetStreamContext
                    (undefined8 param_1,longlong param_2,longlong param_3,int *param_4,uint param_5,
                    longlong param_6,longlong *param_7,undefined8 *param_8)

{
  code *pcVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  longlong lVar5;
  undefined8 uVar6;
  longlong *plVar7;
  longlong *plVar8;
  int *piVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined2 uVar13;
  undefined1 auStackY_e8 [8];
  undefined1 auStackY_e0 [24];
  undefined1 uVar14;
  longlong *local_a8;
  longlong local_98;
  longlong *local_90;
  longlong *local_88;
  ulonglong local_80 [8];
  
  local_80[5] = __security_cookie ^ (ulonglong)auStackY_e8;
  local_a8 = (longlong *)0x0;
  local_90 = (longlong *)0x0;
  local_88 = param_8;
  local_98 = 0;
  local_80[4] = 0;
  local_80[2] = 0;
  local_80[3] = 0;
  local_80[0] = 0;
  local_80[1] = 0;
  uVar3 = FltAllocateContext(Globals,8,0x108,0x200);
  puVar12 = auStackY_e8;
  if ((int)uVar3 < 0) goto LAB_140027344;
  memset((void *)0x0,0,0x108);
  FltReferenceContext(param_3);
  LOCK();
  *param_4 = *param_4 + 1;
  UNLOCK();
  uRam0000000000000008 = 0;
  uRam0000000000000000 = 0;
  uRam0000000000000010 = 0;
  uRam0000000000000014 = 0;
  uRam0000000000000018 = param_5;
  uRam0000000000000030 = *(undefined8 *)(param_2 + 0x28);
  uRam0000000000000100 = 0;
  uRam000000000000001c = 0;
  uRam000000000000001d = 0;
  uRam00000000000000e0 = 0;
  lRam0000000000000020 = param_3;
  piRam0000000000000028 = param_4;
  ExInitializeResourceLite(0x78);
  KeInitializeEvent(0xe8,1,1);
  lRam0000000000000040 = 0x38;
  puRam0000000000000038 = (undefined8 *)0x38;
  if ((param_7 == (longlong *)0x0) || ((longlong *)*param_7 == param_7)) {
LAB_140027274:
    puVar10 = auStackY_e8;
    puVar11 = auStackY_e8;
    puVar12 = auStackY_e8;
    for (puVar4 = puRam0000000000000038; puVar4 != (undefined8 *)0x38;
        puVar4 = (undefined8 *)*puVar4) {
      if ((*(uint *)(puVar4 + 4) & 1) != 0) {
        lVar5 = FltAllocateGenericWorkItem();
        puVar4[2] = lVar5;
        if (lVar5 == 0) {
          uVar3 = 0xc000009a;
          puVar12 = auStackY_e8;
          goto LAB_140027328;
        }
      }
    }
    if ((param_5 & 0x10) == 0 && (*(byte *)(param_3 + 0x58) & 1) == 0) {
      lVar5 = IoGetTopLevelIrp();
      if (lVar5 == 0) {
        IoSetTopLevelIrp(1);
      }
      FsRtlAcquireFileExclusive(param_2);
      CcCoherencyFlushAndPurgeCache(*(undefined8 *)(param_2 + 0x28),0,0,local_80);
      if (lVar5 == 0) {
        IoSetTopLevelIrp(0);
      }
      FsRtlReleaseFile(param_2);
      uVar3 = local_80[0] & 0xffffffff;
      if (-1 < (int)(uint)local_80[0]) {
        plVar8 = local_a8;
        uVar6 = WcIsSourceAvailable(0);
        if ((char)uVar6 == '\0') {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0xd,
                               &WPP_2b73349c3ae735a72745210a57314671_Traceguids,
                               "onecore\\base\\fs\\wci\\wcifs\\context.c",0x6f);
          }
        }
        else {
          uVar2 = WcSyncPlaceholderFileSize(param_1,param_2,(longlong)plVar8,param_6);
          uVar3 = (ulonglong)uVar2;
          if ((int)uVar2 < 0) {
            puVar12 = auStackY_e8;
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar13 = 0xc;
              uVar14 = 0x5f;
              goto LAB_14002749d;
            }
            goto LAB_140027328;
          }
        }
        goto LAB_1400272d9;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140027328;
      uVar13 = 0xb;
      uVar14 = 0x46;
      uVar2 = (uint)local_80[0];
LAB_14002749d:
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,uVar13,
                          &WPP_2b73349c3ae735a72745210a57314671_Traceguids,
                          "onecore\\base\\fs\\wci\\wcifs\\context.c",uVar14,(char)uVar2);
      puVar12 = auStackY_e8;
    }
    else {
LAB_1400272d9:
      uVar2 = FltSetStreamContext(param_1,param_2,1,0);
      uVar3 = (ulonglong)uVar2;
      if ((int)uVar2 < 0) {
        if (uVar2 != 0xc01c0002) {
          puVar12 = auStackY_e8;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_140027328;
          uVar13 = 0xe;
          uVar14 = 0x86;
          goto LAB_14002749d;
        }
        FltReleaseContext(0);
        uVar3 = 0;
        local_a8 = local_90;
      }
      else {
        if (param_4[7] - 2U < 2) {
          ExAcquireFastMutex(param_4 + 0x32);
          piVar9 = param_4 + 0x2e;
          plVar8 = *(longlong **)(param_4 + 0x30);
          plVar7 = local_a8;
          puVar10 = auStackY_e8;
          if ((int *)*plVar8 != piVar9) {
            piVar9 = (int *)0x3;
            pcVar1 = (code *)swi(0x29);
            plVar7 = (longlong *)(*pcVar1)();
            puVar10 = auStackY_e0;
          }
          *plVar7 = (longlong)piVar9;
          plVar7[1] = (longlong)plVar8;
          *plVar8 = (longlong)plVar7;
          *(longlong **)(piVar9 + 2) = plVar7;
          *(undefined8 *)(puVar10 + -8) = 0x140027582;
          FltReferenceContext(0);
          *(undefined8 *)(puVar10 + -8) = 0x140027591;
          ExReleaseFastMutex(param_4 + 0x32);
        }
        puVar11 = puVar10;
      }
      *local_88 = (longlong)local_a8;
      puVar12 = puVar11;
    }
  }
  else {
    lRam0000000000000048 = param_6;
    puRam0000000000000038 = (undefined8 *)*param_7;
    lRam0000000000000040 = param_7[1];
    *(undefined8 *)(*param_7 + 8) = 0x38;
    *(undefined8 *)param_7[1] = 0x38;
    param_7[1] = (longlong)param_7;
    *param_7 = (longlong)param_7;
    puVar4 = (undefined8 *)WcGetSource(0);
    if ((*(uint *)(puVar4[4] + 0x10) & 1) != 0) goto LAB_140027274;
    uVar2 = FltGetInstanceContext(*puVar4,&local_98);
    uVar3 = (ulonglong)uVar2;
    puVar12 = auStackY_e8;
    if (-1 < (int)uVar2) {
      uVar2 = FltQueryInformationFile(*puVar4,puVar4[2],local_80 + 2,0x18);
      uVar3 = (ulonglong)uVar2;
      puVar12 = auStackY_e8;
      if (-1 < (int)uVar2) {
        uRam0000000000000064 = *(undefined8 *)(local_98 + 0x28);
        uRam000000000000006c = *(undefined8 *)(local_98 + 0x30);
        uRam0000000000000054 = local_80[3];
        uRam000000000000005c = local_80[4];
        goto LAB_140027274;
      }
    }
  }
LAB_140027328:
  if (local_98 != 0) {
    *(undefined8 *)(puVar12 + -8) = 0x1400275a2;
    FltReleaseContext();
  }
LAB_140027344:
  *(undefined8 *)(puVar12 + -8) = 0x140027350;
  return uVar3;
}



===== WcGetSourceList @ 1400275c4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong WcGetSourceList(ulonglong param_1,longlong param_2,longlong param_3,uint param_4,
                         longlong *param_5)

{
  ushort uVar1;
  code *pcVar2;
  undefined8 *puVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  longlong lVar7;
  ulonglong uVar8;
  longlong *plVar9;
  undefined1 *puVar10;
  longlong *plVar11;
  undefined8 uVar12;
  undefined2 uVar13;
  int *piVar14;
  undefined1 auStackY_f8 [8];
  undefined1 auStackY_f0 [24];
  wchar_t *in_stack_ffffffffffffff28;
  wchar_t *pwVar15;
  undefined8 in_stack_ffffffffffffff30;
  undefined8 uVar16;
  undefined1 uVar17;
  longlong *plVar18;
  undefined8 local_a8;
  longlong lStack_a0;
  undefined8 *local_98;
  uint local_90;
  uint local_8c;
  int *local_88;
  longlong *local_80;
  longlong *local_78;
  longlong local_70;
  ulonglong local_68;
  longlong *local_60;
  longlong local_58;
  longlong lStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_f8;
  local_80 = (longlong *)0x0;
  puVar6 = (undefined8 *)0x0;
  local_98 = (undefined8 *)0x0;
  piVar14 = (int *)0x0;
  local_88 = (int *)0x0;
  local_8c = 0;
  local_60 = (longlong *)(param_2 + 0xa8);
  local_a8 = (ulonglong)CONCAT22(*(undefined2 *)(param_3 + 0x18),*(undefined2 *)(param_3 + 0x18));
  lStack_a0 = param_3 + 0x1a;
  local_58 = *(longlong *)(param_3 + 8);
  lStack_50 = *(longlong *)(param_3 + 0x10);
  plVar9 = local_60;
  local_90 = param_4;
  local_70 = param_2;
  local_68 = param_1;
  if ((param_4 & 1) == 0) {
    plVar9 = &local_58;
    uVar5 = WcLookupLayer(param_2,local_60,plVar9,(longlong *)&local_80);
    uVar4 = (uint)uVar5;
    uVar5 = uVar5 & 0xffffffff;
    if ((int)uVar4 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar13 = 99;
        plVar18 = &local_58;
        uVar17 = 0xaf;
LAB_1400278fd:
        WPP_RECORDER_SF_sD_guid_Zd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,plVar9,uVar13,
                   in_stack_ffffffffffffff28,in_stack_ffffffffffffff30,uVar17,plVar18,
                   (wchar_t *)&local_a8,(char)uVar4);
      }
    }
    else {
      puVar6 = (undefined8 *)ExAllocatePool2(0x100,0x28);
      if (puVar6 != (undefined8 *)0x0) {
        pwVar15 = (wchar_t *)&local_a8;
        uVar16 = CONCAT44((int)((ulonglong)in_stack_ffffffffffffff30 >> 0x20),param_4);
        uVar12 = 0;
        uVar4 = WcOpenSourceFile(param_1,(longlong)local_80,0,0,pwVar15,param_4,&local_98);
        puVar10 = auStackY_f8;
        uVar5 = (ulonglong)uVar4;
        if (-1 < (int)uVar4) {
          *(uint *)(puVar6 + 4) = *(uint *)(puVar6 + 4) | 1;
          puVar6[3] = local_98;
          plVar9 = (longlong *)param_5[1];
          if ((longlong *)*plVar9 != param_5) {
LAB_140027b4c:
            pcVar2 = (code *)swi(0x29);
            plVar9 = (longlong *)(*pcVar2)(3);
            puVar10 = auStackY_f0;
          }
          *puVar6 = param_5;
          puVar6[1] = plVar9;
          *plVar9 = (longlong)puVar6;
          param_5[1] = (longlong)puVar6;
          goto LAB_140027b61;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sD_guid_Zd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar12,100,pwVar15,uVar16,0xcb,
                     &local_58,(wchar_t *)&local_a8,(char)uVar4);
        }
        goto LAB_140027b15;
      }
LAB_1400276ab:
      uVar5 = 0xc000009a;
    }
  }
  else {
    do {
      do {
        plVar11 = &local_58;
        uVar5 = WcLookupLayer(param_2,plVar9,plVar11,(longlong *)&local_80);
        plVar18 = local_80;
        uVar4 = (uint)uVar5;
        uVar5 = uVar5 & 0xffffffff;
        if ((int)uVar4 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar13 = 0x5f;
            plVar18 = &local_58;
            uVar17 = 0xe8;
LAB_140027a03:
            WPP_RECORDER_SF_sD_guid_Zd
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,plVar11,uVar13,
                       in_stack_ffffffffffffff28,in_stack_ffffffffffffff30,uVar17,plVar18,
                       (wchar_t *)&local_a8,(char)uVar4);
          }
          goto LAB_140027a15;
        }
        local_78 = local_80 + 6;
        if (puVar6 == (undefined8 *)0x0) {
          puVar6 = (undefined8 *)ExAllocatePool2(0x100,0x28);
          if (puVar6 == (undefined8 *)0x0) goto LAB_1400276ab;
        }
        else {
          *puVar6 = 0;
          puVar6[1] = 0;
          puVar6[2] = 0;
          puVar6[3] = 0;
          puVar6[4] = 0;
        }
        local_98 = (undefined8 *)0x0;
        if (*(int *)(param_2 + 0x1c) == 1) {
          uVar4 = WcLookupDirectoryTableEntry((longlong)plVar18,&local_a8,&local_98);
          uVar5 = (ulonglong)uVar4;
          if ((int)uVar4 < 0) goto LAB_1400276ef;
LAB_140027757:
          puVar3 = local_98;
          puVar6[3] = local_98;
          plVar9 = (longlong *)param_5[1];
          if ((longlong *)*plVar9 != param_5) goto LAB_140027b4c;
          puVar6[1] = plVar9;
          *puVar6 = param_5;
          *plVar9 = (longlong)puVar6;
          param_5[1] = (longlong)puVar6;
          puVar6 = (undefined8 *)0x0;
          if (((longlong *)*local_78 == local_60) || ((*(uint *)(plVar18 + 2) & 2) != 0))
          goto LAB_140027955;
          if ((*(uint *)(plVar18 + 2) & 4) == 0) {
            if (piVar14 != (int *)0x0) {
              ExFreePoolWithTag(piVar14,0x69724357);
              piVar14 = (int *)0x0;
              local_88 = (int *)0x0;
            }
            if ((*(uint *)(puVar3 + 3) & 0x400) != 0) {
              in_stack_ffffffffffffff28 = (wchar_t *)&local_8c;
              uVar1 = *(ushort *)(puVar3[2] + 0x58);
              plVar9 = (longlong *)(ulonglong)uVar1;
              uVar4 = WcGetReparseData(*puVar3,puVar3[2],(uint)uVar1,(longlong *)&local_88,
                                       (uint *)in_stack_ffffffffffffff28);
              param_2 = local_70;
              piVar14 = local_88;
              uVar5 = (ulonglong)uVar4;
              if (uVar4 == 0xc0000275) {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  WPP_RECORDER_SF_sD_guid_Zd
                            (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,plVar9,0x61,
                             in_stack_ffffffffffffff28,in_stack_ffffffffffffff30,0x6a,plVar18,
                             (wchar_t *)&local_a8,0x75);
                }
                uVar5 = 0;
                piVar14 = local_88;
              }
              else if (*local_88 == *(int *)(local_70 + 0x24)) {
                uVar4 = WcValidateWcReparseInfo((longlong)local_88,local_8c);
                uVar5 = (ulonglong)uVar4;
                if (-1 < (int)uVar4) {
                  local_58 = *(longlong *)(piVar14 + 4);
                  lStack_50 = *(longlong *)(piVar14 + 6);
                  local_a8 = CONCAT62(CONCAT42(local_a8._4_4_,(short)piVar14[8]),(short)piVar14[8]);
                  lStack_a0 = (longlong)piVar14 + 0x22;
                  goto LAB_14002785a;
                }
                if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                goto LAB_140027b2d;
                uVar13 = 0x62;
                uVar17 = 0x86;
                goto LAB_1400278fd;
              }
            }
            goto LAB_140027955;
          }
          local_58 = 0;
          lStack_50 = 0;
          param_2 = local_70;
        }
        else {
LAB_1400276ef:
          plVar11 = (longlong *)0x0;
          in_stack_ffffffffffffff30 =
               CONCAT44((int)((ulonglong)in_stack_ffffffffffffff30 >> 0x20),local_90);
          in_stack_ffffffffffffff28 = (wchar_t *)&local_a8;
          uVar4 = WcOpenSourceFile(local_68,(longlong)plVar18,0,0,in_stack_ffffffffffffff28,local_90
                                   ,&local_98);
          *(uint *)(puVar6 + 4) = *(uint *)(puVar6 + 4) | 1;
          uVar5 = (ulonglong)uVar4;
          if (-1 < (int)uVar4) goto LAB_140027757;
          if (((*(uint *)(plVar18 + 2) & 4) == 0) ||
             ((uVar4 != 0xc0000034 && (uVar4 != 0xc000003a)))) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar13 = 0x60;
              uVar17 = 0x36;
              goto LAB_140027a03;
            }
            goto LAB_140027a15;
          }
          uVar5 = 0;
          local_58 = 0;
          lStack_50 = 0;
LAB_14002785a:
        }
        plVar9 = local_78;
      } while ((*(uint *)(plVar18 + 2) & 4) != 0);
      lVar7 = local_58;
      if (local_58 == 0) {
        lVar7 = lStack_50;
      }
    } while (lVar7 == 0);
LAB_140027955:
    if (*(int *)(local_70 + 0x1c) == 1) {
      uVar8 = WcInsertDirectoryTableSourceList(param_5,(longlong)&local_a8);
      uVar5 = uVar8 & 0xffffffff;
      if ((int)uVar8 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDZd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x65,
                     &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                     "onecore\\base\\fs\\wci\\wcifs\\utils.c",0xe6,(wchar_t *)&local_a8,(char)uVar8)
          ;
        }
        uVar5 = 0;
      }
    }
LAB_140027a15:
    if (puVar6 != (undefined8 *)0x0) {
LAB_140027b15:
      ExFreePoolWithTag(puVar6,0x65734357);
    }
    puVar10 = auStackY_f8;
    if (-1 < (int)uVar5) goto LAB_140027b61;
  }
LAB_140027b2d:
  puVar10 = auStackY_f8;
  WcFreeSourceList(param_5);
LAB_140027b61:
  if (piVar14 != (int *)0x0) {
    *(undefined8 *)(puVar10 + -8) = 0x140027b75;
    ExFreePoolWithTag(piVar14,0x69724357);
  }
  *(undefined8 *)(puVar10 + -8) = 0x140027b88;
  return uVar5;
}



===== WcPreSetInformation @ 140027bb0 =====

uint WcPreSetInformation(longlong param_1,longlong param_2,longlong *param_3)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  uint uVar6;
  longlong local_res10;
  
  local_res10 = 0;
  uVar6 = 1;
  uVar4 = WcUnionsExistForInstance
                    (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),
                     (undefined4 *)0x0,(undefined4 *)0x0);
  if ((char)uVar4 == '\0') {
    return 1;
  }
  iVar1 = *(int *)(*(longlong *)(param_1 + 0x10) + 0x20);
  switch(iVar1) {
  case 10:
  case 0x41:
    uVar3 = WcProcessSetRenameInformation(param_1,param_2,&local_res10);
    if (-1 < (int)uVar3) {
      if (local_res10 == 0) {
        return 1;
      }
      *param_3 = local_res10;
      return 0;
    }
    break;
  case 0xb:
  case 0x48:
    uVar5 = WcProcessSetLinkInformation(param_1,param_2);
    uVar3 = (uint)uVar5;
    if (-1 < (int)uVar3) {
      return 0;
    }
    break;
  default:
    goto switchD_140027c39_caseD_c;
  case 0xd:
  case 0x40:
    puVar2 = *(uint **)(*(longlong *)(param_1 + 0x10) + 0x38);
    uVar3 = 0;
    if (iVar1 == 0xd) {
      if ((char)*puVar2 == '\x01') goto LAB_140027c55;
    }
    else if ((iVar1 == 0x40) && ((*puVar2 & 1) != 0)) {
LAB_140027c55:
      uVar3 = WcPrepareForDelete(param_1,param_2);
    }
    uVar6 = uVar3 >> 0x1f;
    goto LAB_140027c67;
  case 0x15:
    if (DAT_14000f6a5 != '\0') {
      return 1;
    }
    uVar4 = WcBlockQuerySetInformation(param_1,param_2);
    uVar3 = (uint)uVar4;
LAB_140027c67:
    if (-1 < (int)uVar3) {
      return uVar6;
    }
  }
  *(uint *)(param_1 + 0x18) = uVar3;
  uVar6 = 4;
  *(undefined8 *)(param_1 + 0x20) = 0;
switchD_140027c39_caseD_c:
  return uVar6;
}



===== WcPrepareForDelete @ 140027cec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint WcPrepareForDelete(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  bool bVar3;
  byte bVar4;
  short sVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  ulonglong uVar9;
  undefined8 *puVar10;
  short sVar11;
  longlong lVar12;
  uint uVar13;
  undefined2 uVar14;
  longlong lVar15;
  undefined1 auStackY_118 [32];
  longlong *plVar16;
  undefined1 uVar17;
  char local_c8;
  byte local_c7 [7];
  longlong local_c0;
  longlong local_b8;
  longlong local_b0;
  longlong local_a8;
  longlong local_a0;
  longlong local_98;
  longlong local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_118;
  local_b8 = 0;
  local_c0 = 0;
  local_a8 = 0;
  uVar6 = 0;
  local_a0 = 0;
  lVar12 = 0;
  local_c8 = '\0';
  lVar15 = 0;
  local_b0 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_90 = 0;
  local_98 = 0;
  local_c7[0] = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_48 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  piVar8 = (int *)WcGetUnionContext(param_1,*(undefined8 *)(param_2 + 0x18),
                                    *(undefined8 *)(param_2 + 0x20));
  if (piVar8 == (int *)0x0) goto LAB_140027d7d;
  if (piVar8[6] == 2) {
    uVar6 = 0xc00000bb;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xd,0xb7,
                         &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                         "onecore\\base\\fs\\wci\\wcifs\\utils.c",1);
    }
  }
  else {
    bVar3 = WcGetContextFileObject
                      (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),&local_c0,
                       &local_b8);
    lVar2 = local_b8;
    if (bVar3) {
      uVar9 = WcIsPlaceHolderDirectory(local_c0,local_b8);
      lVar1 = local_c0;
      if ((char)uVar9 == '\0') {
        uVar9 = WcIsPlaceHolderStream(local_c0,local_b8);
        if (((char)uVar9 == '\0') && (bVar4 = WcIsPlaceHolder(lVar1), bVar4 != 0)) {
          uVar6 = WcSetPlaceHolderFlagsSynchronized
                            (param_1,*(undefined8 *)(param_2 + 0x18),*(longlong *)(param_2 + 0x20),2
                            );
          if ((-1 < (int)uVar6) ||
             ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED))
          goto LAB_140028325;
          uVar14 = 0xbb;
          uVar17 = 0x52;
          bVar4 = 3;
LAB_140027eff:
          uVar13 = 0xd;
LAB_140027f22:
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar4,uVar13,uVar14,
                              &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                              "onecore\\base\\fs\\wci\\wcifs\\utils.c",uVar17,(char)uVar6);
        }
        else {
LAB_14002827a:
          if (local_b8 == 0) {
            uVar6 = FltQueryInformationFile
                              (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),
                               &local_68,0x28);
            if (-1 < (int)uVar6) {
              uVar9 = WcGetSetStreamContext
                                (*(undefined8 *)(param_2 + 0x18),*(longlong *)(param_2 + 0x20),
                                 local_c0,piVar8,(uint)local_48,0,(longlong *)0x0,&local_b8);
              uVar6 = (uint)uVar9;
              if (-1 < (int)uVar6) goto LAB_1400282e5;
            }
          }
          else {
LAB_1400282e5:
            lVar2 = local_c0;
            ExAcquireFastMutex(local_c0 + 8);
            *(undefined1 *)(local_b8 + 0x1c) = 1;
            ExReleaseFastMutex(lVar2 + 8);
          }
        }
      }
      else {
        uVar9 = WcIsSourcedStream(lVar2);
        if ((char)uVar9 == '\0') {
LAB_140027fb1:
          uVar9 = WcRemoveTombstonesFromDirectory
                            (param_1,*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20)
                            );
          uVar6 = (uint)uVar9;
          if (-1 < (int)uVar6) goto LAB_14002827a;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar14 = 0xba;
            uVar17 = 0x3b;
            bVar4 = 4;
            goto LAB_140027eff;
          }
        }
        else {
          uVar6 = WcIsDirectoryEmpty(*(longlong *)(param_2 + 0x18),*(longlong *)(param_2 + 0x20),
                                     &local_c8);
          if ((int)uVar6 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar14 = 0xb8;
              uVar17 = 0x1d;
              bVar4 = 2;
              goto LAB_140027eff;
            }
          }
          else {
            if (local_c8 != '\0') goto LAB_140027fb1;
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xd,0xb9,
                                  &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                                  "onecore\\base\\fs\\wci\\wcifs\\utils.c",0x2c,(char)uVar6);
            }
            uVar6 = 0xc0000101;
          }
        }
      }
    }
    else {
      uVar6 = FltGetFileNameInformation(param_1,0x101,&local_b0);
      if (((-1 < (int)uVar6) && (uVar6 = FltParseFileNameInformation(local_b0), -1 < (int)uVar6)) &&
         (*(short *)(local_b0 + 0x48) == 0)) {
        uStack_80 = *(undefined8 *)(local_b0 + 0x10);
        bVar4 = 2;
        sVar11 = *(short *)(local_b0 + 8) - *(short *)(local_b0 + 0x58);
        sVar5 = sVar11 + -2;
        if (sVar5 == *(short *)(local_b0 + 0x18)) {
          sVar5 = sVar11;
        }
        local_88 = CONCAT62(*(undefined6 *)(local_b0 + 10),sVar5);
        plVar16 = &local_90;
        uVar6 = WcOpenPlaceHolder(*(undefined8 *)(param_2 + 0x18),(wchar_t *)&local_88,0x29,
                                  piVar8[9],plVar16,&local_98,local_c7);
        if ((int)uVar6 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sDdZ
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0xbc,
                       &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                       "onecore\\base\\fs\\wci\\wcifs\\utils.c",0x98,(char)uVar6,
                       (wchar_t *)&local_88);
          }
        }
        else if (local_c7[0] == 0) {
LAB_140028233:
          uVar6 = 0;
        }
        else {
          uVar6 = WcGetSetContextFileObject
                            (*(undefined8 *)(param_2 + 0x18),local_98,piVar8,1,plVar16,&local_a0,
                             &local_a8);
          lVar15 = local_a0;
          lVar12 = local_a8;
          if ((int)uVar6 < 0) {
            if (uVar6 == 0xc0000275) goto LAB_14002831a;
          }
          else {
            if (uVar6 != 0x104) {
              uVar9 = WcIsPlaceHolderDirectory(local_a0,local_a8);
              if (((char)uVar9 != '\0') && (uVar9 = WcIsSourcedStream(lVar12), (char)uVar9 != '\0'))
              {
                puVar10 = (undefined8 *)WcGetSource(lVar12);
                iVar7 = FltQueryDirectoryFile(*puVar10,puVar10[2],&local_78);
                if (((iVar7 + 0x80000000U & 0x80000000) == 0) && (iVar7 != -0x7ffffffb))
                goto LAB_140028233;
              }
              uVar6 = WcGetSetFileContext(*(undefined8 *)(param_2 + 0x18),
                                          *(undefined8 *)(param_2 + 0x20),1,0,&local_c0);
              if (-1 < (int)uVar6) goto LAB_14002827a;
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
              goto LAB_140028325;
              uVar14 = 0xbd;
              uVar17 = 0xfc;
              uVar13 = 5;
              goto LAB_140027f22;
            }
LAB_14002831a:
            uVar6 = 0;
          }
        }
      }
    }
  }
LAB_140028325:
  WcReleaseUnionContext(piVar8);
LAB_140027d7d:
  if (local_b0 != 0) {
    FltReleaseFileNameInformation();
  }
  if (local_90 != 0) {
    FltClose();
  }
  if (local_98 != 0) {
    ObfDereferenceObject();
  }
  if (local_c0 != 0) {
    FltReleaseContext(local_c0);
  }
  if (local_b8 != 0) {
    FltReleaseContext(local_b8);
  }
  if (lVar15 != 0) {
    FltReleaseContext(lVar15);
  }
  if (lVar12 != 0) {
    FltReleaseContext(lVar12);
  }
  return uVar6;
}



===== WcProcessSetRenameInformation @ 1400283bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint WcProcessSetRenameInformation(longlong param_1,longlong param_2,longlong *param_3)

{
  bool bVar1;
  longlong lVar2;
  bool bVar3;
  byte bVar4;
  short sVar5;
  uint uVar6;
  ulonglong uVar7;
  longlong *plVar8;
  short sVar9;
  undefined1 uVar10;
  uint uVar11;
  undefined2 uVar12;
  int iVar13;
  longlong lVar14;
  longlong lVar15;
  undefined1 auStackY_168 [32];
  byte local_118;
  undefined1 local_117;
  char local_116 [6];
  longlong local_110;
  longlong local_108;
  longlong local_100;
  undefined4 local_f8;
  longlong local_f0;
  longlong local_e8;
  int *local_e0;
  longlong local_d8;
  longlong local_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  longlong *local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 local_98 [4];
  char *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  byte *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  longlong *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_168;
  local_110 = 0;
  local_f8 = 0;
  local_f0 = 0;
  uVar6 = 0;
  local_100 = 0;
  lVar15 = 0;
  local_d8 = 0;
  local_e8 = 0;
  plVar8 = (longlong *)0x0;
  local_e0 = (int *)0x0;
  lVar14 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_d0 = 0;
  bVar1 = false;
  local_108 = 0;
  local_118 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_a0 = 0;
  local_116[0] = '\0';
  local_117 = 0;
  local_b8 = param_3;
  bVar3 = WcGetContextFileObject
                    (*(undefined8 *)(param_2 + 0x18),
                     *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x28),&local_f0,&local_100);
  if (((bVar3) && (uVar7 = WcIsPlaceHolderDirectory(local_f0,local_100), (char)uVar7 != '\0')) &&
     (bVar4 = WcIsUnionValid(*(longlong *)(local_100 + 0x28)), bVar4 != 0)) {
    uVar7 = WcPrepareTargetDirectoryForRenameOrLink(param_1,param_2);
    uVar6 = (uint)uVar7;
    if (-1 < (int)uVar6) goto LAB_140028467;
  }
  else {
LAB_140028467:
    local_e0 = (int *)WcGetUnionContext(param_1,*(undefined8 *)(param_2 + 0x18),
                                        *(undefined8 *)(param_2 + 0x20));
    if (local_e0 != (int *)0x0) {
      bVar3 = WcGetContextFileObject
                        (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),&local_d8,
                         &local_e8);
      lVar15 = local_d8;
      lVar2 = local_e8;
      if (!bVar3) {
LAB_140028621:
        uVar6 = FltQueryInformationFile
                          (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),&local_b0
                           ,0x18);
        if ((int)uVar6 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_140028497;
          uVar12 = 10;
          uVar10 = 0xa4;
          uVar11 = 0xd;
        }
        else {
          if (local_a0._5_1_ == '\0') {
            if ((local_a0._6_1_ != '\0') || (local_a0._7_1_ != '\0')) goto LAB_140028484;
            uVar10 = local_117;
          }
          else {
            uVar10 = 1;
          }
          if (local_118 != 0) goto LAB_140028704;
          iVar13 = local_e0[9];
LAB_14002870b:
          plVar8 = (longlong *)ExAllocateFromPagedLookasideList(&DAT_14000f500);
          if (plVar8 != (longlong *)0x0) {
            *(undefined1 *)(plVar8 + 2) = uVar10;
            uVar6 = FltGetFileNameInformation(param_1,0x101,&local_110);
            if ((-1 < (int)uVar6) &&
               (uVar6 = FltParseFileNameInformation(local_110), -1 < (int)uVar6)) {
              uStack_c0 = *(undefined8 *)(local_110 + 0x10);
              sVar9 = *(short *)(local_110 + 8) - *(short *)(local_110 + 0x58);
              sVar5 = sVar9 + -2;
              if (sVar5 == *(short *)(local_110 + 0x18)) {
                sVar5 = sVar9;
              }
              local_c8 = CONCAT62(*(undefined6 *)(local_110 + 10),sVar5);
              uVar6 = WcOpenPlaceHolder(*(undefined8 *)(param_2 + 0x18),(wchar_t *)&local_c8,0x29,
                                        iVar13,&local_d0,&local_108,&local_118);
              lVar14 = local_108;
              if ((int)uVar6 < 0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  WPP_RECORDER_SF_sDdZ
                            (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0xc,
                             &WPP_62cdeb337fdf307834c1a2cccb2efbc6_Traceguids,
                             "onecore\\base\\fs\\wci\\wcifs\\fileinfo.c",0xf2,(char)uVar6,
                             (wchar_t *)&local_c8);
                }
                lVar14 = local_108;
                goto LAB_140028497;
              }
              if ((local_118 != 0) &&
                 (uVar6 = WcAddInMemoryTombstone
                                    (param_1,*(undefined8 *)(param_2 + 0x18),local_110 + 0x58,
                                     (char)plVar8[2],local_108), (int)uVar6 < 0)) {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0xd,
                                      &WPP_62cdeb337fdf307834c1a2cccb2efbc6_Traceguids,
                                      "onecore\\base\\fs\\wci\\wcifs\\fileinfo.c",8,(char)uVar6);
                }
                if ((5 < DAT_14000f060) &&
                   (uVar7 = _tlgKeywordOn(0x14000f060,0x400000000000), (char)uVar7 != '\0')) {
                  local_6c = 0;
                  local_78 = local_116;
                  local_5c = 0;
                  local_4c = 0;
                  local_68 = &local_118;
                  local_70 = 1;
                  local_58 = &local_108;
                  local_60 = 1;
                  local_116[0] = '\x03';
                  local_118 = 9;
                  local_108 = CONCAT44(local_108._4_4_,uVar6);
                  local_50 = 4;
                  _tlgWriteTransfer_EtwWriteTransfer(0x14000f060,&DAT_14000b6fa,0,0,5,local_98);
                }
                goto LAB_140028497;
              }
              *plVar8 = local_110;
              local_110 = 0;
              plVar8[1] = lVar14;
              *local_b8 = (longlong)plVar8;
              plVar8 = (longlong *)0x0;
            }
            goto LAB_140028484;
          }
          uVar6 = 0xc000009a;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_140028497;
          uVar12 = 0xb;
          uVar6 = 0xc000009a;
          uVar10 = 0xc3;
          uVar11 = 5;
        }
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar11,uVar12,
                            &WPP_62cdeb337fdf307834c1a2cccb2efbc6_Traceguids,
                            "onecore\\base\\fs\\wci\\wcifs\\fileinfo.c",uVar10,(char)uVar6);
        goto LAB_140028497;
      }
      uVar7 = WcIsPlaceHolderDirectory(local_d8,local_e8);
      if ((char)uVar7 == '\0') {
        uVar7 = WcIsPlaceHolderStream(lVar15,lVar2);
        if ((char)uVar7 == '\0') {
          bVar4 = WcIsPlaceHolder(lVar15);
          if (bVar4 == 0) goto LAB_140028621;
          uVar6 = 2;
        }
        else {
          uVar6 = 10;
          local_116[0] = '\x01';
        }
      }
      else {
        bVar1 = true;
        uVar6 = 10;
        local_117 = 1;
      }
      local_118 = 1;
      uVar6 = WcSetPlaceHolderFlagsSynchronized
                        (param_1,*(undefined8 *)(param_2 + 0x18),*(longlong *)(param_2 + 0x20),uVar6
                        );
      if (-1 < (int)uVar6) {
        if ((!bVar1) && (local_116[0] == '\0')) goto LAB_140028621;
        uVar10 = local_117;
LAB_140028704:
        iVar13 = **(int **)(lVar15 + 0x40);
        goto LAB_14002870b;
      }
    }
  }
LAB_140028484:
  lVar14 = 0;
LAB_140028497:
  if (local_110 != 0) {
    FltReleaseFileNameInformation();
  }
  if (plVar8 != (longlong *)0x0) {
    ExFreeToPagedLookasideList(&DAT_14000f500,plVar8);
  }
  if (local_d0 != 0) {
    FltClose();
  }
  if (lVar14 != 0) {
    ObfDereferenceObject(lVar14);
  }
  if (local_f0 != 0) {
    FltReleaseContext();
  }
  if (local_100 != 0) {
    FltReleaseContext(local_100);
  }
  if (lVar15 != 0) {
    FltReleaseContext(lVar15);
  }
  if (local_e8 != 0) {
    FltReleaseContext(local_e8);
  }
  if (local_e0 != (int *)0x0) {
    WcReleaseUnionContext(local_e0);
  }
  if (((int)uVar6 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0xe,
                        &WPP_62cdeb337fdf307834c1a2cccb2efbc6_Traceguids,
                        "onecore\\base\\fs\\wci\\wcifs\\fileinfo.c",0x4e,(char)uVar6);
  }
  return uVar6;
}



===== WcProcessSetLinkInformation @ 140028aa4 =====

ulonglong WcProcessSetLinkInformation(longlong param_1,longlong param_2)

{
  longlong lVar1;
  bool bVar2;
  byte bVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong local_res8;
  longlong local_res10;
  
  uVar5 = 0;
  local_res8 = 0;
  local_res10 = 0;
  bVar2 = WcGetContextFileObject
                    (*(undefined8 *)(param_2 + 0x18),
                     *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x28),&local_res8,&local_res10)
  ;
  lVar1 = local_res10;
  if (bVar2) {
    uVar4 = WcIsPlaceHolderDirectory(local_res8,local_res10);
    if ((char)uVar4 != '\0') {
      bVar3 = WcIsUnionValid(*(longlong *)(lVar1 + 0x28));
      if (bVar3 != 0) {
        uVar5 = WcPrepareTargetDirectoryForRenameOrLink(param_1,param_2);
        uVar5 = uVar5 & 0xffffffff;
      }
    }
  }
  if (local_res8 != 0) {
    FltReleaseContext(local_res8);
  }
  if (lVar1 != 0) {
    FltReleaseContext(lVar1);
  }
  return uVar5;
}



===== WcLookupLayer @ 140028b54 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 WcLookupLayer(longlong param_1,longlong *param_2,longlong *param_3,longlong *param_4)

{
  longlong lVar1;
  longlong *plVar2;
  undefined8 uVar3;
  undefined1 auStack_108 [56];
  longlong *local_d0;
  longlong *local_b8 [2];
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_108;
  uVar3 = 0;
  memset(&local_a8,0,0x70);
  lVar1 = *param_3;
  local_b8[0] = (longlong *)&local_a8;
  if (lVar1 == 0) {
    lVar1 = param_3[1];
  }
  if (lVar1 == 0) {
    plVar2 = (longlong *)*param_2;
    if ((plVar2 == param_2) || (plVar2 == (longlong *)(param_1 + 0xa8))) {
      uVar3 = 0xc0000001;
    }
    else {
      local_b8[0] = plVar2 + -6;
    }
  }
  else {
    local_a8 = (undefined4)*param_3;
    uStack_a4 = *(undefined4 *)((longlong)param_3 + 4);
    uStack_a0 = (undefined4)param_3[1];
    uStack_9c = *(undefined4 *)((longlong)param_3 + 0xc);
    plVar2 = (longlong *)RtlLookupElementGenericTableAvl(param_1 + 0x40,local_b8);
    if (plVar2 == (longlong *)0x0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0xc0000034;
      }
      local_d0 = param_3;
      WPP_RECORDER_SF_sD_guid_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      return 0xc0000034;
    }
    local_b8[0] = (longlong *)*plVar2;
  }
  *param_4 = (longlong)local_b8[0];
  return uVar3;
}



===== WcOpenSourceFile @ 140028c58 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int WcOpenSourceFile(ulonglong param_1,longlong param_2,longlong param_3,longlong param_4,
                    wchar_t *param_5,uint param_6,undefined8 *param_7)

{
  char cVar1;
  int iVar2;
  longlong *plVar3;
  ushort uVar4;
  undefined2 uVar5;
  longlong lVar6;
  undefined1 auStackY_1b8 [32];
  undefined1 uVar7;
  longlong *local_138;
  longlong local_130;
  longlong local_128;
  undefined8 local_120;
  longlong lStack_118;
  int local_110;
  undefined4 local_108;
  undefined4 uStack_104;
  longlong lStack_100;
  wchar_t *local_f8;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined8 local_e8;
  ulonglong uStack_e0;
  undefined8 local_d8;
  longlong lStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  ulonglong local_b8;
  ulonglong local_b0;
  longlong local_a8;
  longlong local_a0;
  undefined8 *local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_1b8;
  local_98 = param_7;
  local_128 = 0;
  plVar3 = (longlong *)0x0;
  local_138 = (longlong *)0x0;
  local_a8 = 0;
  lVar6 = 0;
  local_130 = 0;
  local_e8 = 0;
  uStack_e0 = uStack_e0 & 0xffffffff00000000;
  local_b8 = local_b8 & 0xffffffffffff0000;
  local_60 = 0;
  local_120 = 0;
  lStack_118 = 0;
  local_108 = 0;
  uStack_104 = 0;
  lStack_100 = 0;
  local_f8 = (wchar_t *)0x0;
  uStack_f0 = 0;
  uStack_ec = 0;
  local_d8 = 0;
  lStack_d0 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_b0 = param_1;
  local_a0 = param_2;
  RtlInitUnicodeString(&local_120,0);
  if (param_4 == 0) {
    uVar4 = *(ushort *)(param_2 + 0x18) + *param_5;
    if (uVar4 < *(ushort *)(param_2 + 0x18)) {
      iVar2 = -0x3fffff6b;
      local_120._0_4_ = CONCAT22(0xffff,(wchar_t)local_120);
      goto LAB_140029093;
    }
    local_120._0_4_ = CONCAT22(uVar4,(wchar_t)local_120);
    lStack_118 = ExAllocatePool2(0x100,uVar4,0x6e664357);
    if (lStack_118 == 0) {
      iVar2 = -0x3fffff66;
      goto LAB_140029093;
    }
    local_120 = local_120 & 0xffffffffffff0000;
    RtlCopyUnicodeString(&local_120,param_2 + 0x18);
    iVar2 = RtlAppendUnicodeStringToString(&local_120,param_5);
    if (iVar2 < 0) goto LAB_140029093;
    local_f8 = (wchar_t *)&local_120;
    lStack_100 = 0;
    param_3 = *(longlong *)(local_a0 + 0x28);
  }
  else {
    local_f8 = param_5;
    lStack_100 = param_4;
  }
  local_108 = 0x30;
  uStack_f0 = 0x240;
  local_e8 = 0;
  uStack_e0 = 0;
  plVar3 = (longlong *)ExAllocatePool2(0x100,0x28,0x73734357);
  if (plVar3 == (longlong *)0x0) {
    iVar2 = -0x3fffff66;
  }
  else {
    lStack_d0 = 0;
    local_110 = (~param_6 & 1) * 2 + 3;
    local_d8 = 0x28;
    local_c8 = 0;
    uStack_c0 = 0;
    local_b8 = local_b0;
    iVar2 = FltCreateFileEx2(Globals,param_3,plVar3 + 1,plVar3 + 2);
    if (iVar2 + 0x3ffffc98U < 2) {
      iVar2 = FltAllocateExtraCreateParameterList(Globals,0,&local_128);
      if (iVar2 < 0) {
        lVar6 = 0;
        goto LAB_140029093;
      }
      iVar2 = FltAllocateExtraCreateParameter(Globals,&GUID_ECP_FLT_CREATEFILE_TARGET,0x20,0);
      if (-1 < iVar2) {
        *(undefined2 *)(local_138 + 3) = 1;
        *local_138 = 0;
        local_138[1] = 0;
        local_138[2] = 0;
        iVar2 = FltInsertExtraCreateParameter(Globals,local_128,local_138);
        if (-1 < iVar2) {
          local_b8 = local_b0;
          lStack_d0 = local_128;
          local_d8 = 0x28;
          local_c8 = 0;
          uStack_c0 = 0;
          local_108 = 0x30;
          uStack_f0 = 0x240;
          local_e8 = 0;
          uStack_e0 = 0;
          if ((wchar_t)local_120 == L'\0') {
            local_f8 = param_5;
            lStack_100 = param_4;
          }
          else {
            local_f8 = (wchar_t *)&local_120;
            lStack_100 = 0;
          }
          iVar2 = FltCreateFileEx2(Globals,param_3,plVar3 + 1,plVar3 + 2);
          if (-1 < iVar2) {
            cVar1 = FltIsEcpAcknowledged(Globals,local_138);
            if (cVar1 != '\0') {
              if (*local_138 != 0) {
                param_3 = *local_138;
              }
            }
            goto LAB_140029044;
          }
          if (1 < iVar2 + 0x3ffffc98U) goto LAB_1400293f1;
          cVar1 = FltIsEcpAcknowledged(Globals);
          if (cVar1 == '\0') {
            if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
               (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
              uVar5 = 0x5b;
              uVar7 = 0xe9;
LAB_140029236:
              WPP_RECORDER_SF_sDd(_WcVerboseRecorder,5,5,uVar5,
                                  &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                                  "onecore\\base\\fs\\wci\\wcifs\\utils.c",uVar7,(char)iVar2);
              goto LAB_14002908f;
            }
          }
          else {
            iVar2 = FltAttachVolume(Globals,local_138[1],&DAT_14000a4a0,&local_a8);
            param_3 = local_a8;
            if (-1 < iVar2) {
              if (local_138[1] != 0) {
                FltObjectDereference();
                local_138[1] = 0;
              }
              if (*local_138 != 0) {
                FltObjectDereference();
                *local_138 = 0;
              }
              lVar6 = local_138[2];
              local_138[2] = 0;
              local_130 = lVar6;
              FltPrepareToReuseEcp(Globals,local_138);
              local_108 = 0x30;
              lStack_100 = 0;
              local_d8 = 0x28;
              local_b8 = local_b0;
              lStack_d0 = local_128;
              local_f8 = (wchar_t *)(lVar6 + 8);
              local_c8 = 0;
              uStack_c0 = 0;
              uStack_f0 = 0x240;
              local_e8 = 0;
              uStack_e0 = 0;
              iVar2 = FltCreateFileEx2(Globals,param_3,plVar3 + 1,plVar3 + 2);
              goto LAB_14002903c;
            }
            if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
               (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
              uVar5 = 0x5c;
              uVar7 = 0;
              goto LAB_140029236;
            }
          }
        }
      }
      lVar6 = 0;
      goto LAB_140029093;
    }
LAB_14002903c:
    if (iVar2 < 0) {
LAB_1400293f1:
      if ((wchar_t)local_120 == L'\0') {
        if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
           (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
          uVar5 = 0x5e;
          uVar7 = 0x42;
          goto LAB_140029456;
        }
      }
      else if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
              (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        param_5 = (wchar_t *)&local_120;
        uVar5 = 0x5d;
        uVar7 = 0x3b;
LAB_140029456:
        WPP_RECORDER_SF_sDZd
                  (_WcVerboseRecorder,5,5,uVar5,&WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                   "onecore\\base\\fs\\wci\\wcifs\\utils.c",uVar7,param_5,(char)iVar2);
      }
    }
    else {
LAB_140029044:
      iVar2 = FltQueryInformationFile(param_3,plVar3[2],&local_80,0x28);
      if (-1 < iVar2) {
        plVar3[4] = local_a0;
        *plVar3 = param_3;
        *(undefined4 *)(plVar3 + 3) = (undefined4)local_60;
        *local_98 = plVar3;
        plVar3 = (longlong *)0x0;
      }
    }
  }
LAB_14002908f:
  lVar6 = local_130;
LAB_140029093:
  if ((local_138 != (longlong *)0x0) && (cVar1 = FltIsEcpAcknowledged(Globals), cVar1 != '\0')) {
    FltRemoveExtraCreateParameter(Globals,local_128,&GUID_ECP_FLT_CREATEFILE_TARGET,&local_138);
    if (*local_138 != 0) {
      FltObjectDereference();
    }
    if (local_138[1] != 0) {
      FltObjectDereference();
    }
    if (local_138[2] != 0) {
      FltReleaseFileNameInformation();
    }
    FltFreeExtraCreateParameter(Globals,local_138);
  }
  if (local_128 != 0) {
    FltFreeExtraCreateParameterList(Globals);
  }
  if (lVar6 != 0) {
    FltReleaseFileNameInformation(lVar6);
  }
  if (lStack_118 != 0) {
    ExFreePoolWithTag(lStack_118,0x6e664357);
  }
  if (local_a8 != 0) {
    FltObjectDereference();
  }
  if (plVar3 != (longlong *)0x0) {
    if (plVar3[1] != 0) {
      FltClose();
    }
    if (plVar3[2] != 0) {
      ObfDereferenceObject();
    }
    ExFreePoolWithTag(plVar3,0x73734357);
  }
  return iVar2;
}



===== WcCopySourceList @ 14002958c =====

int WcCopySourceList(undefined8 *param_1,ulonglong param_2,longlong param_3)

{
  longlong *plVar1;
  undefined8 uVar2;
  code *pcVar3;
  int iVar4;
  longlong *plVar5;
  undefined1 *puVar6;
  undefined8 *puVar7;
  undefined1 auStackY_88 [8];
  undefined1 auStackY_80 [24];
  wchar_t local_48 [4];
  wchar_t *local_40;
  
  puVar6 = auStackY_88;
  puVar7 = (undefined8 *)*param_1;
  local_40 = L"::$DATA";
  iVar4 = 0;
  local_48[0] = L'\0';
  local_48[1] = L'\x0e';
  local_48[2] = L'\0';
  local_48[3] = L'\0';
  while( true ) {
    if (puVar7 == param_1) {
      return iVar4;
    }
    plVar5 = (longlong *)ExAllocatePool2(0x100,0x28,0x65734357);
    if (plVar5 == (longlong *)0x0) {
      return -0x3fffff66;
    }
    plVar5[2] = 0;
    plVar1 = (longlong *)puVar7[3];
    iVar4 = WcOpenSourceFile(param_2,plVar1[4],*plVar1,plVar1[1],local_48,0x21,plVar5 + 3);
    if (iVar4 < 0) break;
    *(uint *)(plVar5 + 4) = *(uint *)(plVar5 + 4) | 1;
    plVar1 = *(longlong **)(param_3 + 8);
    if (*plVar1 != param_3) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3);
      puVar6 = auStackY_80;
      break;
    }
    *plVar5 = param_3;
    plVar5[1] = (longlong)plVar1;
    *plVar1 = (longlong)plVar5;
    *(longlong **)(param_3 + 8) = plVar5;
    puVar7 = (undefined8 *)*puVar7;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    *(int *)(puVar6 + 0x38) = iVar4;
    *(undefined4 *)(puVar6 + 0x30) = 0x2fd;
    *(char **)(puVar6 + 0x28) = "onecore\\base\\fs\\wci\\wcifs\\context.c";
    uVar2 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
    *(undefined **)(puVar6 + 0x20) = &WPP_2b73349c3ae735a72745210a57314671_Traceguids;
    *(undefined8 *)(puVar6 + -8) = 0x1400296a9;
    WPP_RECORDER_SF_sDd(uVar2,2,10,0xf,*(undefined8 *)(puVar6 + 0x20),*(char **)(puVar6 + 0x28),
                        puVar6[0x30],puVar6[0x38]);
  }
  *(undefined8 *)(puVar6 + -8) = 0x1400296b8;
  ExFreePoolWithTag(plVar5,0x65734357);
  return iVar4;
}



===== WcPreLockControl @ 1400296e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000140029979) */
/* WARNING: Removing unreachable block (ram,0x0001400299c7) */
/* WARNING: Removing unreachable block (ram,0x000140029999) */
/* WARNING: Removing unreachable block (ram,0x0001400299ba) */
/* WARNING: Removing unreachable block (ram,0x0001400299a8) */
/* WARNING: Removing unreachable block (ram,0x000140029a02) */
/* WARNING: Removing unreachable block (ram,0x0001400299d7) */

undefined4 WcPreLockControl(uint *param_1,longlong param_2,longlong *param_3)

{
  longlong lVar1;
  bool bVar2;
  byte bVar3;
  uint uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined1 auStackY_f8 [32];
  undefined1 local_b8 [8];
  uint *local_b0;
  longlong local_a8;
  ulonglong local_a0;
  longlong local_98;
  longlong local_90;
  undefined8 local_88 [4];
  undefined1 *local_68;
  undefined8 local_60;
  ulonglong *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_f8;
  local_90 = 0;
  local_a8 = 0;
  local_b0 = param_1;
  bVar2 = WcGetContextFileObject
                    (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),&local_90,
                     &local_a8);
  if ((bVar2) &&
     (uVar5 = WcUsesSourceSectionObjectPointers(*(longlong *)(param_2 + 0x20),local_a8),
     (char)uVar5 != '\0')) {
    uVar7 = 4;
    if ((5 < DAT_14000f060) &&
       (uVar5 = _tlgKeywordOn(0x14000f060,0x400000000000), (char)uVar5 != '\0')) {
      local_68 = local_b8;
      local_b8[0] = 5;
      local_60 = 1;
      local_a0 = (ulonglong)*(byte *)(*(longlong *)(param_1 + 4) + 5);
      local_58 = &local_a0;
      local_50 = 8;
      _tlgWriteTransfer_EtwWriteTransfer(0x14000f060,&DAT_14000bd5a,0,0,4,local_88);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,0xd,0x43,
                         &WPP_27ac746799d63ca1d37704ce911b8053_Traceguids,
                         "onecore\\base\\fs\\wci\\wcifs\\wcifs.c",0xd7);
    }
    param_1[6] = 0xc00000bb;
    goto LAB_140029792;
  }
  *param_3 = 0;
  iVar8 = 1;
  uVar7 = 1;
  local_98 = 0;
  local_a0 = 0;
  bVar2 = WcGetContextFileObject
                    (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),&local_98,
                     &local_a0);
  lVar1 = local_98;
  uVar5 = local_a0;
  if (((bVar2) && (bVar3 = WcIsPlaceHolder(local_98), bVar3 != 0)) &&
     ((*(uint *)(*(longlong *)(param_2 + 0x20) + 0x50) & 0x100) == 0)) {
    uVar6 = WcIsPlaceHolderDirectory(lVar1,uVar5);
    if ((char)uVar6 == '\0') {
      uVar6 = WcIsPlaceHolderStream(lVar1,uVar5);
      if ((char)uVar6 != '\0') {
LAB_140029961:
        if ((*local_b0 & 2) == 0) {
          uVar4 = WcExpandAndPend((longlong)local_b0,*(undefined8 *)(param_2 + 0x18),
                                  *(undefined8 *)(param_2 + 0x20),lVar1,iVar8,0xd);
          if (uVar4 == 0x103) {
            uVar7 = 2;
          }
          else if ((int)uVar4 < 0) goto LAB_1400299e8;
        }
        else {
          uVar7 = 3;
        }
      }
    }
    else {
      uVar6 = WcIsSourcedStream(uVar5);
      if ((char)uVar6 != '\0') {
        iVar8 = 2;
        if ((char)uVar6 != '\0') goto LAB_140029961;
        uVar4 = 0xc000000d;
LAB_1400299e8:
        uVar7 = 4;
        local_b0[6] = uVar4;
        local_b0[8] = 0;
        local_b0[9] = 0;
      }
    }
  }
  if (uVar5 != 0) {
    FltReleaseContext(uVar5);
  }
  if (lVar1 != 0) {
    FltReleaseContext(lVar1);
  }
LAB_140029792:
  if (local_90 != 0) {
    FltReleaseContext();
  }
  if (local_a8 != 0) {
    FltReleaseContext(local_a8);
  }
  return uVar7;
}



===== WcGenerateFileName @ 140029ab0 =====

int WcGenerateFileName(undefined8 param_1,undefined8 param_2,longlong param_3,uint param_4,
                      undefined1 *param_5,undefined8 param_6)

{
  int iVar1;
  longlong local_res18 [2];
  
  local_res18[0] = 0;
  if (param_3 == 0) {
    iVar1 = FltGetFileNameInformationUnsafe(param_2,param_1,param_4 & 0xfeffffff,local_res18);
  }
  else {
    iVar1 = FltGetFileNameInformation(param_3,param_4 & 0xfeffffff,local_res18);
  }
  if ((-1 < iVar1) &&
     (iVar1 = FltCheckAndGrowNameControl(param_6,*(undefined2 *)(local_res18[0] + 8)), -1 < iVar1))
  {
    RtlCopyUnicodeString(param_6,local_res18[0] + 8);
    *param_5 = 0;
  }
  if (local_res18[0] != 0) {
    FltReleaseFileNameInformation();
  }
  return iVar1;
}



===== WcPreFsControl @ 140029b90 =====

ulonglong WcPreFsControl(uint *param_1,ulonglong param_2,longlong *param_3)

{
  int iVar1;
  longlong lVar2;
  char cVar3;
  byte bVar4;
  uint uVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  undefined8 *puVar8;
  ulonglong uVar9;
  bool bVar10;
  ulonglong local_res8;
  longlong local_res18 [2];
  undefined4 uVar11;
  undefined8 uVar12;
  undefined4 uVar13;
  
  *param_3 = 0;
  uVar9 = 1;
  uVar5 = *(uint *)(*(longlong *)(param_1 + 4) + 0x28);
  if (0x9013c < uVar5) {
    if (0x90394 < uVar5) {
      if (uVar5 < 0x90c24) {
        if (uVar5 == 0x90c23) {
          uVar6 = WcPreGetUnions((longlong)param_1);
          uVar5 = (uint)uVar6;
        }
        else {
          switch(uVar5) {
          case 0x9039b:
          case 0x903a4:
            uVar6 = WcFsctlRedirectDirectMappedRequest((longlong)param_1,param_2);
            uVar5 = (uint)uVar6;
            break;
          default:
            goto switchD_140029c4d_caseD_90019;
          case 0x903ab:
            goto switchD_140029c4d_caseD_900b3;
          case 0x9040c:
            goto switchD_140029c4d_caseD_900a4;
          case 0x9042b:
            goto switchD_140029c4d_caseD_9006f;
          case 0x90448:
            uVar6 = WcFsctlManageBypassIo((longlong)param_1,param_2);
            uVar5 = (uint)uVar6;
          }
        }
        goto LAB_140029dd4;
      }
      if (uVar5 < 0x98345) {
        if (uVar5 != 0x98344) {
          if (uVar5 == 0x940cf) {
            uVar9 = WcPreFsctlQueryAllocatedRanges((longlong)param_1,param_2,param_3);
            return uVar9 & 0xffffffff;
          }
          if (uVar5 != 0x9411e) {
            if (uVar5 == 0x980c8) {
              uVar9 = WcSynchronizeExpansionPreopWithReason(param_1,param_2,1,3,0xb,param_3);
              return uVar9 & 0xffffffff;
            }
            return 1;
          }
          goto switchD_140029c4d_caseD_9001c;
        }
      }
      else if ((uVar5 != 0x9c280) && (uVar5 != 0x9c2b4)) {
        return 1;
      }
switchD_140029cf6_caseD_9027c:
      if (DAT_14000f6a8 == '\0') {
        uVar9 = WcFsctlBlockOperation((longlong)param_1,param_2);
        if ((int)uVar9 == 4) {
          return uVar9 & 0xffffffff;
        }
      }
      uVar6 = WcFailFsctlIfPlaceHolderStream((longlong)param_1,param_2);
      uVar5 = (uint)uVar6;
      goto LAB_140029dd4;
    }
    if (uVar5 == 0x90394) {
      uVar9 = WcFsctlSetLayerRoot((longlong)param_1,param_2);
      return uVar9 & 0xffffffff;
    }
    if (0x901fc < uVar5) {
      if (uVar5 == 0x90390) {
        uVar9 = WcPreFsctlQueryContainerState((longlong)param_1,param_2);
        return uVar9 & 0xffffffff;
      }
      if (0x90390 < uVar5) {
        return 1;
      }
      switch(uVar5) {
      case 0x90230:
      case 0x9024c:
      case 0x902ec:
        goto switchD_140029c4d_caseD_9001c;
      default:
        goto switchD_140029c4d_caseD_90019;
      case 0x90234:
      case 0x90277:
      case 0x902f0:
        goto switchD_140029c4d_caseD_9006f;
      case 0x9027c:
      case 0x902b0:
        goto switchD_140029cf6_caseD_9027c;
      case 0x902d0:
      case 0x902f4:
        goto switchD_140029c4d_caseD_900b3;
      }
    }
    if (uVar5 == 0x901fc) {
switchD_140029c4d_caseD_9006f:
      bVar10 = DAT_14000f6a6 == '\0';
      goto LAB_140029dc3;
    }
    if (uVar5 != 0x901b0) {
      if (uVar5 != 0x901b4) {
        return 1;
      }
      if (DAT_14000f6a5 != '\0') {
        return 1;
      }
      goto LAB_140029dcf;
    }
switchD_140029c4d_caseD_9001c:
    bVar10 = DAT_14000f6a4 == '\0';
    goto LAB_140029dc3;
  }
  if (uVar5 == 0x9013c) goto switchD_140029c4d_caseD_9001c;
  switch(uVar5) {
  case 0x90018:
    if (DAT_14000f6a4 == '\0') {
      uVar9 = WcFsctlBlockOperation((longlong)param_1,param_2);
      if ((int)uVar9 == 4) {
        return uVar9 & 0xffffffff;
      }
    }
    uVar6 = WcPreDismountLockRemove((longlong)param_1,param_2);
    uVar5 = (uint)uVar6;
    goto LAB_140029dd4;
  case 0x9001c:
  case 0x90030:
  case 0x900f0:
    goto switchD_140029c4d_caseD_9001c;
  case 0x90020:
    if (DAT_14000f6a4 == '\0') {
      uVar9 = WcFsctlBlockOperation((longlong)param_1,param_2);
      if ((int)uVar9 == 4) {
        return uVar9 & 0xffffffff;
      }
    }
    uVar7 = WcPreDismountLockRemove((longlong)param_1,param_2);
    uVar9 = uVar7 & 0xffffffff;
    if ((int)uVar7 != 4) {
      uVar9 = 0;
    }
    break;
  case 0x9006f:
  case 0x90073:
  case 0x90074:
    goto switchD_140029c4d_caseD_9006f;
  case 0x9008f:
    uVar6 = WcPreFsctlFindFilesBySid((longlong)param_1,param_2);
    uVar5 = (uint)uVar6;
    goto LAB_140029dd4;
  case 0x90098:
  case 0x9009c:
  case 0x900a0:
  case 0x900bc:
  case 0x900c0:
    bVar10 = DAT_14000f6a2 == '\0';
    goto LAB_140029dc3;
  case 0x900a4:
switchD_140029c4d_caseD_900a4:
    uVar9 = WcPreFsctlSetReparsePoint(param_1,param_2,param_3);
    uVar9 = uVar9 & 0xffffffff;
    break;
  case 0x900a8:
  case 0x900ac:
    local_res8 = 0;
    local_res18[0] = 0;
    bVar10 = WcIsSiloFileObject(*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20));
    if ((!bVar10) &&
       (bVar10 = WcUnionExistsForFileObject
                           ((longlong)param_1,*(undefined8 *)(param_2 + 0x18),
                            *(undefined8 *)(param_2 + 0x20)), !bVar10)) {
      return 1;
    }
    bVar10 = WcGetContextFileObject
                       (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),&local_res8,
                        local_res18);
    uVar7 = local_res8;
    if ((bVar10) && (bVar4 = WcIsPlaceHolder(local_res8), bVar4 != 0)) {
      param_1[6] = 0xc0000275;
      uVar9 = 4;
    }
    if (uVar7 != 0) {
      FltReleaseContext(uVar7);
    }
    goto LAB_140029c8c;
  case 0x900b3:
  case 0x900bb:
  case 0x900e7:
  case 0x900ef:
  case 0x900f8:
  case 0x900fc:
switchD_140029c4d_caseD_900b3:
    if (DAT_14000f6a7 != '\0') {
      return 1;
    }
    cVar3 = PsIsCurrentThreadInServerSilo();
    if (cVar3 == '\0') {
      return 1;
    }
    goto LAB_140029dcf;
  case 0x900c4:
    uVar9 = WcSynchronizeExpansionPreopWithReason(param_1,param_2,1,3,0xc,param_3);
    uVar9 = uVar9 & 0xffffffff;
    break;
  case 0x900d7:
  case 0x900db:
  case 0x900df:
  case 0x900e3:
    bVar10 = DAT_14000f6a3 == '\0';
LAB_140029dc3:
    if (!bVar10) {
      return 1;
    }
LAB_140029dcf:
    uVar6 = WcFsctlBlockOperation((longlong)param_1,param_2);
    uVar5 = (uint)uVar6;
LAB_140029dd4:
    uVar9 = (ulonglong)uVar5;
    break;
  case 0x900eb:
  case 0x900f4:
    local_res8 = local_res8 & 0xffffffff00000000;
    local_res18[0] = 0;
    uVar5 = FltGetStreamContext(*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),
                                local_res18);
    if (((int)uVar5 < 0) ||
       (uVar6 = WcShouldRedirectEaAndUsn
                          ((char)param_1[0x14],*(longlong *)(param_2 + 0x20),
                           *(longlong *)(local_res18[0] + 0x20),local_res18[0]), (char)uVar6 == '\0'
       )) {
      if ((DAT_14000f6a7 == '\0') && (cVar3 = PsIsCurrentThreadInServerSilo(), cVar3 != '\0')) {
        uVar9 = WcFsctlBlockOperation((longlong)param_1,param_2);
        uVar9 = uVar9 & 0xffffffff;
      }
    }
    else {
      puVar8 = (undefined8 *)WcGetSource(local_res18[0]);
      lVar2 = *(longlong *)(param_1 + 4);
      iVar1 = *(int *)(lVar2 + 0x28);
      if (iVar1 == 0x900f4) {
        uVar13 = *(undefined4 *)(lVar2 + 0x18);
        uVar6 = *(undefined8 *)(lVar2 + 0x30);
        uVar11 = *(undefined4 *)(lVar2 + 0x20);
        uVar12 = uVar6;
LAB_140029fe6:
        uVar5 = FltFsControlFile(*puVar8,puVar8[2],iVar1,uVar6,uVar11,uVar12,uVar13,&local_res8);
      }
      else if (iVar1 == 0x900eb) {
        uVar6 = *(undefined8 *)(lVar2 + 0x30);
        uVar13 = *(undefined4 *)(lVar2 + 0x18);
        uVar12 = *(undefined8 *)(lVar2 + 0x38);
        uVar11 = *(undefined4 *)(lVar2 + 0x20);
        goto LAB_140029fe6;
      }
      uVar9 = 4;
      *(ulonglong *)(param_1 + 8) = local_res8 & 0xffffffff;
      param_1[6] = uVar5;
    }
LAB_140029c8c:
    if (local_res18[0] != 0) {
      FltReleaseContext();
    }
  }
switchD_140029c4d_caseD_90019:
  return uVar9;
}



===== WcFsctlBlockOperation @ 14002a07c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 WcFsctlBlockOperation(longlong param_1,longlong param_2)

{
  uint uVar1;
  bool bVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined1 auStackY_a8 [32];
  undefined1 local_68 [8];
  ulonglong local_60;
  undefined8 local_58 [4];
  undefined1 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  uVar4 = 1;
  uVar1 = *(uint *)(*(longlong *)(param_1 + 0x10) + 0x28);
  if (*(char *)(param_1 + 0x50) == '\x01') {
    bVar2 = WcIsSiloFileObject(*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20));
    if (bVar2) {
      if (5 < DAT_14000f060) {
        uVar3 = _tlgKeywordOn(0x14000f060,0x400000000000);
        if ((char)uVar3 != '\0') {
          local_2c = 0;
          local_38 = local_68;
          local_1c = 0;
          local_28 = &local_60;
          local_68[0] = 3;
          local_30 = 1;
          local_20 = 8;
          local_60 = (ulonglong)uVar1;
          _tlgWriteTransfer_EtwWriteTransfer(0x14000f060,&DAT_14000b7d8,0,0,4,local_58);
        }
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,7,0x10,
                            &WPP_6905edae906b30b18cb12ec0224aaf5b_Traceguids,
                            "onecore\\base\\fs\\wci\\wcifs\\fsctrl.c",0x4c,(char)uVar1);
      }
      *(undefined8 *)(param_1 + 0x20) = 0;
      uVar4 = 4;
      *(undefined4 *)(param_1 + 0x18) = 0xc00000bb;
    }
  }
  return uVar4;
}



===== WcPreFsctlQueryContainerState @ 14002a1ec =====

undefined8 WcPreFsctlQueryContainerState(longlong param_1,longlong param_2)

{
  undefined8 uVar1;
  longlong local_res10 [3];
  
  local_res10[0] = 0;
  uVar1 = 1;
  FltGetInstanceContext(*(undefined8 *)(param_2 + 0x18),local_res10);
  if (local_res10[0] != 0) {
    if ((*(longlong *)(local_res10[0] + 0x38) != 0) &&
       (3 < *(uint *)(*(longlong *)(param_1 + 0x10) + 0x18))) {
      **(undefined4 **)(*(longlong *)(param_1 + 0x10) + 0x30) = 1;
      uVar1 = 4;
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(undefined8 *)(param_1 + 0x20) = 0;
    }
    FltReleaseContext(local_res10[0]);
  }
  return uVar1;
}



===== WcPreFsctlQueryAllocatedRanges @ 14002a274 =====

undefined8 WcPreFsctlQueryAllocatedRanges(longlong param_1,longlong param_2,undefined8 param_3)

{
  uint uVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong *plVar4;
  bool bVar5;
  ulonglong uVar6;
  longlong lVar7;
  undefined4 uVar8;
  longlong lVar9;
  undefined8 uVar10;
  longlong *local_res10;
  undefined8 local_res18;
  longlong local_res20;
  
  local_res20 = 0;
  local_res10 = (longlong *)0x0;
  uVar8 = 0;
  uVar10 = 1;
  local_res18 = param_3;
  bVar5 = WcGetContextFileObject
                    (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),&local_res10,
                     &local_res20);
  lVar2 = local_res20;
  plVar3 = local_res10;
  if (bVar5) {
    uVar6 = WcIsPlaceHolderStream((longlong)local_res10,local_res20);
    if ((char)uVar6 != '\0') {
      *(undefined8 *)(param_1 + 0x20) = 0;
      uVar10 = 4;
      local_res18 = CONCAT44(local_res18._4_4_,4);
      uVar6 = *(longlong *)(lVar2 + 0x48) + -1 + (ulonglong)*(uint *)(*plVar3 + 0xc) &
              -(ulonglong)*(uint *)(*plVar3 + 0xc);
      lVar2 = *(longlong *)(param_1 + 0x10);
      plVar3 = *(longlong **)(lVar2 + 0x38);
      uVar1 = *(uint *)(lVar2 + 0x18);
      plVar4 = *(longlong **)(lVar2 + 0x30);
      if (0xf < *(uint *)(lVar2 + 0x20)) {
        if (*(char *)(param_1 + 0x50) != '\0') {
          ProbeForRead(plVar4,*(uint *)(lVar2 + 0x20),4);
          ProbeForWrite(plVar3,uVar1,4);
        }
        lVar2 = *plVar4;
        lVar7 = plVar4[1];
        if (((-1 < lVar2) && (-1 < lVar7)) && (lVar7 <= 0x7fffffffffffffff - lVar2)) {
          if ((lVar7 == 0) || ((longlong)uVar6 < lVar2)) {
            uVar8 = 0;
          }
          else {
            lVar9 = uVar6 - lVar2;
            if (lVar9 < lVar7) {
              lVar7 = lVar9;
            }
            if (uVar1 < 0x10) {
              uVar8 = 0xc0000023;
            }
            else {
              *plVar3 = lVar2;
              plVar3[1] = lVar7;
              *(undefined8 *)(param_1 + 0x20) = 0x10;
              uVar8 = 0;
            }
          }
          goto LAB_14002a2bb;
        }
      }
      uVar8 = 0xc000000d;
    }
  }
LAB_14002a2bb:
  *(undefined4 *)(param_1 + 0x18) = uVar8;
  if (local_res10 != (longlong *)0x0) {
    FltReleaseContext(local_res10);
  }
  if (local_res20 != 0) {
    FltReleaseContext(local_res20);
  }
  return uVar10;
}



===== WcSynchronizeExpansionPreopWithReason @ 14002a470 =====

undefined8
WcSynchronizeExpansionPreopWithReason
          (uint *param_1,longlong param_2,int param_3,int param_4,int param_5,longlong *param_6)

{
  longlong *plVar1;
  longlong lVar2;
  bool bVar3;
  byte bVar4;
  char cVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  longlong lVar9;
  int iVar10;
  longlong local_res10;
  longlong local_38 [2];
  
  plVar1 = param_6;
  local_res10 = 0;
  local_38[0] = 0;
  *param_6 = 0;
  uVar8 = 1;
  bVar3 = WcGetContextFileObject
                    (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),&local_res10,
                     local_38);
  lVar2 = local_38[0];
  lVar9 = local_res10;
  if (((!bVar3) || (bVar4 = WcIsPlaceHolder(local_res10), bVar4 == 0)) ||
     ((*(uint *)(*(longlong *)(param_2 + 0x20) + 0x50) & 0x100) != 0)) goto LAB_14002a4d5;
  uVar7 = WcIsPlaceHolderDirectory(lVar9,lVar2);
  if ((char)uVar7 == '\0') {
    uVar7 = WcIsPlaceHolderStream(lVar9,lVar2);
    param_6._0_4_ = 1;
    if ((char)uVar7 == '\0') {
      param_3 = param_4;
    }
    iVar10 = 1;
  }
  else {
    iVar10 = 2;
    param_6._0_4_ = 2;
    uVar7 = WcIsSourcedStream(lVar2);
    if ((char)uVar7 == '\0') {
      param_3 = 0;
    }
  }
  if (param_3 == 0) goto LAB_14002a4d5;
  if (param_3 == 1) {
    if ((*param_1 & 2) != 0) {
      uVar8 = 3;
      goto LAB_14002a4d5;
    }
LAB_14002a62a:
    uVar6 = WcExpandAndPend((longlong)param_1,*(undefined8 *)(param_2 + 0x18),
                            *(undefined8 *)(param_2 + 0x20),lVar9,iVar10,param_5);
    if (uVar6 == 0x103) {
      uVar8 = 2;
      goto LAB_14002a4d5;
    }
LAB_14002a68d:
    if (-1 < (int)uVar6) goto LAB_14002a4d5;
  }
  else {
    if (param_3 == 2) {
LAB_14002a678:
      uVar6 = WcExpandAndWait(param_1,*(undefined8 *)(param_2 + 0x18),
                              *(undefined8 *)(param_2 + 0x20),lVar9,iVar10,param_5);
      goto LAB_14002a68d;
    }
    if ((param_3 == 3) || (param_3 == 4)) {
      cVar5 = ExAcquireRundownProtection(lVar9 + 0x48);
      if (cVar5 == '\0') {
        iVar10 = (int)param_6;
        if (param_3 == 3) {
          if ((*param_1 & 2) != 0) {
            uVar8 = 3;
            goto LAB_14002a4d5;
          }
          goto LAB_14002a62a;
        }
        goto LAB_14002a678;
      }
      uVar6 = WcSetPlaceHolderFlagsSynchronized
                        (param_1,*(undefined8 *)(param_2 + 0x18),*(longlong *)(param_2 + 0x20),2);
      if (-1 < (int)uVar6) {
        *plVar1 = lVar9;
        uVar8 = 0;
        lVar9 = 0;
        goto LAB_14002a4d5;
      }
      ExReleaseRundownProtection(lVar9 + 0x48);
    }
    else {
      uVar6 = 0xc000000d;
    }
  }
  param_1[6] = uVar6;
  param_1[8] = 0;
  param_1[9] = 0;
  uVar8 = 4;
LAB_14002a4d5:
  if (lVar2 != 0) {
    FltReleaseContext(lVar2);
  }
  if (lVar9 != 0) {
    FltReleaseContext(lVar9);
  }
  return uVar8;
}



===== WcPreFsctlSetReparsePoint @ 14002a6ec =====

ulonglong WcPreFsctlSetReparsePoint(uint *param_1,longlong param_2,longlong *param_3)

{
  int iVar1;
  longlong lVar2;
  bool bVar3;
  uint uVar4;
  int *piVar5;
  ulonglong uVar6;
  int *piVar7;
  ulonglong uVar8;
  longlong lVar9;
  longlong lVar10;
  int *piVar11;
  char local_res8 [8];
  longlong local_res10;
  longlong *local_res18;
  longlong local_res20;
  
  uVar4 = 0;
  lVar9 = 0;
  local_res8[0] = '\0';
  lVar10 = 0;
  local_res10 = 0;
  local_res20 = 0;
  uVar8 = 1;
  local_res18 = param_3;
  piVar5 = (int *)WcGetUnionContext((longlong)param_1,*(undefined8 *)(param_2 + 0x18),
                                    *(undefined8 *)(param_2 + 0x20));
  if (piVar5 == (int *)0x0) goto LAB_14002a735;
  lVar2 = *(longlong *)(param_1 + 4);
  piVar11 = *(int **)(lVar2 + 0x30);
  if (piVar11 == (int *)0x0) {
    uVar4 = 0xc0000206;
LAB_14002a75f:
    uVar8 = 4;
  }
  else {
    uVar4 = *(uint *)(lVar2 + 0x20);
    if (*(int *)(lVar2 + 0x28) == 0x9040c) {
      if (uVar4 < 0x20) {
        uVar4 = 0xc0000023;
        goto LAB_14002a75f;
      }
      piVar11 = piVar11 + 8;
      uVar4 = uVar4 - 0x20;
    }
    piVar7 = piVar11;
    uVar4 = FsRtlValidateReparsePointBuffer(uVar4);
    if ((int)uVar4 < 0) goto LAB_14002a75f;
    iVar1 = *piVar11;
    if ((iVar1 == piVar5[9]) || (iVar1 == -0x5fffffe1)) {
      uVar4 = 0xc00000bb;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDDd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),piVar7,7,0xf,
                   &WPP_6905edae906b30b18cb12ec0224aaf5b_Traceguids,
                   "onecore\\base\\fs\\wci\\wcifs\\fsctrl.c",0xa0,(char)iVar1,0xbb);
      }
      goto LAB_14002a8d8;
    }
    bVar3 = WcGetContextFileObject
                      (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),&local_res10,
                       &local_res20);
    lVar10 = local_res20;
    lVar9 = local_res10;
    if (bVar3) {
      uVar6 = WcIsPlaceHolderDirectory(local_res10,local_res20);
      if (((char)uVar6 == '\0') || (uVar6 = WcIsSourcedStream(lVar10), (char)uVar6 == '\0')) {
        uVar6 = WcIsPlaceHolderStream(lVar9,lVar10);
        if ((char)uVar6 != '\0') {
          uVar8 = WcSynchronizeExpansionPreopWithReason(param_1,param_2,1,3,0xf,local_res18);
          uVar8 = uVar8 & 0xffffffff;
        }
      }
      else {
        uVar4 = WcIsDirectoryEmpty(*(longlong *)(param_2 + 0x18),*(longlong *)(param_2 + 0x20),
                                   local_res8);
        if (-1 < (int)uVar4) {
          if (local_res8[0] != '\0') goto LAB_14002a8dd;
          uVar4 = 0xc0000101;
        }
LAB_14002a8d8:
        uVar8 = 4;
      }
    }
LAB_14002a8dd:
    if (lVar9 != 0) {
      FltReleaseContext(lVar9);
    }
    if (lVar10 != 0) {
      FltReleaseContext(lVar10);
    }
  }
  WcReleaseUnionContext(piVar5);
LAB_14002a735:
  param_1[6] = uVar4;
  return uVar8;
}



===== WcFsctlSetLayerRoot @ 14002a918 =====

undefined8 WcFsctlSetLayerRoot(longlong param_1,ulonglong param_2)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  ushort *puVar4;
  short sVar5;
  longlong local_res8;
  ulonglong local_res10;
  
  lVar1 = *(longlong *)(param_1 + 0x10);
  local_res8 = 0;
  local_res10 = param_2 & 0xffffffffffff0000;
  if (((*(uint **)(lVar1 + 0x30) != (uint *)0x0) && (*(int *)(lVar1 + 0x20) == 4)) &&
     (uVar2 = **(uint **)(lVar1 + 0x30), (uVar2 & 0xfffffc00) == 0)) {
    uVar2 = uVar2 & 3;
    if (uVar2 == 0) {
      return 1;
    }
    if (uVar2 != 3) {
      if (*(uint *)(lVar1 + 0x18) < 2) {
        *(undefined4 *)(param_1 + 0x18) = 0xc0000023;
      }
      else {
        iVar3 = FltGetFileNameInformation(param_1,0x101,&local_res8);
        if (-1 < iVar3) {
          iVar3 = FltParseFileNameInformation(local_res8);
          if (iVar3 < 0) {
            *(int *)(param_1 + 0x18) = iVar3;
            *(undefined8 *)(param_1 + 0x20) = 0;
          }
          else {
            sVar5 = 6;
            puVar4 = *(ushort **)(*(longlong *)(param_1 + 0x10) + 0x30);
            uVar2 = RtlUShortAdd(*(ushort *)(local_res8 + 8),6,puVar4);
            if ((-1 < (int)uVar2) &&
               (uVar2 = RtlUShortAdd(*puVar4,sVar5 + -4,(ushort *)&local_res10), -1 < (int)uVar2)) {
              if (*(uint *)(*(longlong *)(param_1 + 0x10) + 0x18) < (uint)(ushort)local_res10) {
                *(undefined4 *)(param_1 + 0x18) = 0x80000005;
                *(undefined8 *)(param_1 + 0x20) = 2;
              }
              else {
                uVar2 = RtlUShortAdd(*(ushort *)(local_res8 + 8),sVar5,puVar4 + 1);
                if (-1 < (int)uVar2) {
                  puVar4[2] = *(ushort *)(local_res8 + 0x18);
                  puVar4[3] = *(ushort *)(local_res8 + 8);
                  memmove(puVar4 + 4,*(void **)(local_res8 + 0x10),
                          (ulonglong)*(ushort *)(local_res8 + 8));
                  *(ulonglong *)(param_1 + 0x20) = local_res10 & 0xffff;
                  *(undefined4 *)(param_1 + 0x18) = 0;
                }
              }
            }
          }
          if (local_res8 == 0) {
            return 4;
          }
          FltReleaseFileNameInformation();
          return 4;
        }
        *(int *)(param_1 + 0x18) = iVar3;
      }
      goto LAB_14002aaa1;
    }
  }
  *(undefined4 *)(param_1 + 0x18) = 0xc000000d;
LAB_14002aaa1:
  *(undefined8 *)(param_1 + 0x20) = 0;
  return 4;
}



===== WcPreQueryInformation @ 14002aac0 =====

undefined8 WcPreQueryInformation(longlong param_1,longlong param_2)

{
  int iVar1;
  bool bVar2;
  byte bVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  longlong lVar7;
  undefined8 uVar8;
  longlong local_res8;
  longlong local_res20;
  
  lVar7 = 0;
  local_res8 = 0;
  local_res20 = 0;
  uVar8 = 1;
  iVar1 = *(int *)(*(longlong *)(param_1 + 0x10) + 0x20);
  if (iVar1 == 0x4d) {
switchD_14002ab98_caseD_4:
    if ((*(uint *)(*(longlong *)(param_2 + 0x20) + 0x50) & 0x100) != 0) {
      return 1;
    }
    uVar4 = WcUnionsExistForInstance
                      (*(undefined8 *)(param_2 + 0x18),*(longlong *)(param_2 + 0x20),
                       (undefined4 *)0x0,(undefined4 *)0x0);
    if ((char)uVar4 == '\0') {
      return 1;
    }
    bVar2 = WcGetContextFileObject
                      (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),&local_res8,
                       &local_res20);
    lVar7 = local_res20;
    if (bVar2) {
      uVar5 = WcUsesSourceSectionObjectPointers(*(longlong *)(param_2 + 0x20),local_res20);
      if ((char)uVar5 == '\0') {
        bVar3 = WcIsPlaceHolder(local_res8);
        if (bVar3 != 0) goto LAB_14002ac1e;
      }
      else if (iVar1 == 5) {
        puVar6 = (undefined8 *)WcGetSource(lVar7);
        *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 8) = puVar6[2];
        *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x10) = *puVar6;
        FltSetCallbackDataDirty(param_1);
      }
      else {
LAB_14002ac1e:
        uVar8 = 0;
      }
    }
    if (local_res8 != 0) {
      FltReleaseContext(local_res8);
    }
switchD_14002ab98_caseD_6:
    if (lVar7 != 0) {
      FltReleaseContext(lVar7);
    }
  }
  else {
    switch(iVar1) {
    case 4:
    case 5:
    case 0x12:
    case 0x16:
    case 0x1c:
    case 0x22:
    case 0x23:
    case 0x44:
    case 0x46:
      goto switchD_14002ab98_caseD_4;
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 0xb:
    case 0xc:
    case 0xd:
    case 0xe:
    case 0xf:
    case 0x10:
    case 0x11:
    case 0x13:
    case 0x14:
    case 0x17:
    case 0x18:
    case 0x19:
    case 0x1a:
    case 0x1b:
    case 0x1d:
    case 0x1e:
    case 0x1f:
    case 0x20:
    case 0x21:
    case 0x24:
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x28:
    case 0x29:
    case 0x2a:
    case 0x2b:
    case 0x2c:
    case 0x2d:
    case 0x2e:
    case 0x2f:
    case 0x30:
    case 0x31:
    case 0x32:
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x36:
    case 0x37:
    case 0x38:
    case 0x39:
    case 0x3a:
    case 0x3b:
    case 0x3c:
    case 0x3d:
    case 0x3e:
    case 0x3f:
    case 0x40:
    case 0x41:
    case 0x42:
    case 0x43:
    case 0x45:
      goto switchD_14002ab98_caseD_6;
    case 0x15:
      if (DAT_14000f6a5 == '\0') {
        uVar4 = WcBlockQuerySetInformation(param_1,param_2);
        if ((int)uVar4 != 0) {
          *(int *)(param_1 + 0x18) = (int)uVar4;
          *(undefined8 *)(param_1 + 0x20) = 0;
          return 4;
        }
      }
    }
  }
  return uVar8;
}



===== WcBlockQuerySetInformation @ 14002ac44 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 WcBlockQuerySetInformation(longlong param_1,longlong param_2)

{
  int iVar1;
  bool bVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined1 auStackY_a8 [32];
  undefined1 local_68 [8];
  longlong local_60;
  undefined8 local_58 [4];
  undefined1 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  uVar4 = 0;
  iVar1 = *(int *)(*(longlong *)(param_1 + 0x10) + 0x20);
  if (*(char *)(param_1 + 0x50) == '\x01') {
    bVar2 = WcIsSiloFileObject(*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20));
    if (bVar2) {
      if (5 < DAT_14000f060) {
        uVar3 = _tlgKeywordOn(0x14000f060,0x400000000000);
        if ((char)uVar3 != '\0') {
          local_2c = 0;
          local_38 = local_68;
          local_1c = 0;
          local_28 = &local_60;
          local_68[0] = 1;
          local_30 = 1;
          local_20 = 8;
          local_60 = (longlong)iVar1;
          _tlgWriteTransfer_EtwWriteTransfer(0x14000f060,&DAT_14000b5be,0,0,4,local_58);
        }
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,7,0xf,
                            &WPP_62cdeb337fdf307834c1a2cccb2efbc6_Traceguids,
                            "onecore\\base\\fs\\wci\\wcifs\\fileinfo.c",0x9b,(char)iVar1);
      }
      *(undefined8 *)(param_1 + 0x20) = 0;
      uVar4 = 0xc00000bb;
      *(undefined4 *)(param_1 + 0x18) = 0xc00000bb;
    }
  }
  return uVar4;
}



===== WcPreNetworkQueryOpen @ 14002adb0 =====

undefined8 WcPreNetworkQueryOpen(longlong param_1,longlong param_2,undefined8 *param_3)

{
  longlong lVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  longlong *plVar5;
  undefined8 uVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined2 uVar9;
  undefined4 local_res10 [4];
  longlong *local_res20;
  undefined1 auStackY_78 [8];
  undefined1 auStackY_70 [24];
  undefined1 uVar10;
  longlong local_38;
  longlong local_30;
  
  uVar6 = 0;
  local_res10[0] = 0xfff0000;
  local_38 = 0;
  local_30 = 0;
  local_res20 = (longlong *)0x0;
  plVar5 = (longlong *)0x0;
  uVar4 = WcUnionsExistForInstance
                    (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),local_res10,
                     (undefined4 *)0x0);
  if ((char)uVar4 == '\0') {
    uVar6 = 1;
LAB_14002ae03:
    puVar8 = auStackY_78;
    puVar7 = auStackY_78;
    if (local_38 == 0) goto LAB_14002ae0c;
  }
  else {
    iVar3 = FltGetFileNameInformation(param_1,0x102,&local_38);
    if (iVar3 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar9 = 0x4d;
        uVar10 = 0x49;
LAB_14002b0d6:
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,uVar9,
                            &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                            "onecore\\base\\fs\\wci\\wcifs\\create.c",uVar10,(char)iVar3);
      }
LAB_14002afe3:
      *(undefined8 *)(param_1 + 0x20) = 0;
      uVar6 = 4;
      *(int *)(param_1 + 0x18) = iVar3;
      goto LAB_14002ae03;
    }
    plVar5 = (longlong *)ExAllocateFromPagedLookasideList(&DAT_14000f400);
    if (plVar5 == (longlong *)0x0) {
      iVar3 = -0x3fffff66;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        iVar3 = -0x3fffff66;
        uVar9 = 0x4e;
        uVar10 = 0x52;
        goto LAB_14002b0d6;
      }
      goto LAB_14002afe3;
    }
    plVar5[1] = (longlong)plVar5;
    *plVar5 = (longlong)plVar5;
    plVar5[3] = 0;
    plVar5[4] = 0;
    *(undefined4 *)(plVar5 + 2) = local_res10[0];
    *(undefined4 *)((longlong)plVar5 + 0x14) = 0x80000004;
    *(undefined4 *)(plVar5 + 5) = 0x30;
    lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18);
    local_30 = *(longlong *)(lVar1 + 0x70);
    if (local_30 != 0) {
      iVar3 = FltFindExtraCreateParameter(Globals,local_30,&ECP_TYPE_OPEN_REPARSE_GUID,&local_res20)
      ;
      if (((iVar3 + 0x80000000U & 0x80000000) != 0) || (iVar3 == -0x3ffffddb)) goto LAB_14002aee6;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar9 = 0x50;
        uVar10 = 0x7a;
        goto LAB_14002b0d6;
      }
      goto LAB_14002afe3;
    }
    iVar3 = FltAllocateExtraCreateParameterList(Globals,0,&local_30);
    if (iVar3 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar9 = 0x4f;
        uVar10 = 99;
        goto LAB_14002b0d6;
      }
      goto LAB_14002afe3;
    }
    FsRtlSetEcpListIntoIrp(lVar1,local_30);
LAB_14002aee6:
    if (local_res20 == (longlong *)0x0) {
      iVar3 = FltAllocateExtraCreateParameterFromLookasideList
                        (Globals,&ECP_TYPE_OPEN_REPARSE_GUID,0x10);
      if (iVar3 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar9 = 0x51;
          uVar10 = 0x8b;
          goto LAB_14002b0d6;
        }
        goto LAB_14002afe3;
      }
      local_res20[1] = (longlong)local_res20;
      *local_res20 = (longlong)local_res20;
      FltInsertExtraCreateParameter(Globals,local_30,local_res20);
    }
    lVar1 = *local_res20;
    if (*(longlong **)(lVar1 + 8) == local_res20) {
      *plVar5 = lVar1;
      plVar5[1] = (longlong)local_res20;
      *(longlong **)(lVar1 + 8) = plVar5;
      *local_res20 = (longlong)plVar5;
      iVar3 = FltObjectReference(Globals);
      if (-1 < iVar3) {
        plVar5[6] = local_38;
        *param_3 = plVar5;
        plVar5 = (longlong *)0x0;
        local_38 = 0;
        goto LAB_14002ae03;
      }
      goto LAB_14002afe3;
    }
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(3);
    puVar8 = auStackY_70;
  }
  *(undefined8 *)(puVar8 + -8) = 0x14002b12f;
  FltReleaseFileNameInformation();
  puVar7 = puVar8;
LAB_14002ae0c:
  if (plVar5 != (longlong *)0x0) {
    *(undefined8 *)(puVar7 + -8) = 0x14002b14a;
    ExFreeToPagedLookasideList(&DAT_14000f400,plVar5);
  }
  return uVar6;
}



===== WcPreCreate @ 14002b160 =====

undefined8 WcPreCreate(longlong param_1,longlong param_2,longlong *param_3)

{
  byte *pbVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  undefined2 uVar11;
  uint *puVar12;
  undefined4 local_res10 [4];
  uint local_res20 [2];
  undefined1 uVar13;
  longlong local_48 [2];
  
  local_res10[0] = 0xfff0000;
  local_48[0] = 0;
  local_res20[0] = 0xfff0000;
  uVar10 = 1;
  lVar6 = 0;
  lVar7 = 0;
  lVar8 = 0;
  if ((*(uint *)(*(longlong *)(param_2 + 0x20) + 0x50) & 0x400000) != 0) {
    return 1;
  }
  puVar12 = local_res20;
  uVar5 = WcUnionsExistForInstance
                    (*(undefined8 *)(param_2 + 0x18),*(longlong *)(param_2 + 0x20),local_res10,
                     puVar12);
  if ((char)uVar5 == '\0') goto LAB_14002b1c4;
  if (*(longlong *)(param_2 + 0x28) != 0) {
    uVar9 = WcPreTransaction(param_1,param_2,local_res10[0],(uint)puVar12);
    iVar4 = (int)uVar9;
    if (-1 < iVar4) goto LAB_14002b1c4;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002b37a;
    uVar11 = 0x33;
    uVar13 = 0xb6;
LAB_14002b486:
    WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,uVar11,
                        &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                        "onecore\\base\\fs\\wci\\wcifs\\create.c",uVar13,(char)iVar4);
    *(int *)(param_1 + 0x18) = iVar4;
    uVar10 = 4;
    *(undefined8 *)(param_1 + 0x20) = 0;
    goto LAB_14002b1c4;
  }
  lVar2 = *(longlong *)(param_1 + 0x10);
  if ((*(uint *)(lVar2 + 0x20) & 0x2000) == 0) {
    if ((*(byte *)(lVar2 + 6) & 4) == 0) {
      iVar4 = FltGetFileNameInformation(param_1,0x102);
    }
    else {
      *(byte *)(lVar2 + 6) = *(byte *)(lVar2 + 6) & 0xfb;
      iVar4 = FltGetFileNameInformation(param_1,0x302,local_48);
      pbVar1 = (byte *)(*(longlong *)(param_1 + 0x10) + 6);
      *pbVar1 = *pbVar1 | 4;
    }
    if (-1 < iVar4) goto LAB_14002b245;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar11 = 0x34;
      uVar13 = 0xe2;
      goto LAB_14002b486;
    }
  }
  else {
LAB_14002b245:
    lVar6 = ExAllocateFromPagedLookasideList(&DAT_14000f400);
    if (lVar6 == 0) {
      iVar4 = -0x3fffff66;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        iVar4 = -0x3fffff66;
        uVar11 = 0x35;
        uVar13 = 0xec;
        goto LAB_14002b486;
      }
    }
    else {
      *(longlong *)(lVar6 + 8) = lVar6;
      *(longlong *)lVar6 = lVar6;
      *(undefined8 *)(lVar6 + 0x18) = 0;
      *(undefined8 *)(lVar6 + 0x20) = 0;
      *(undefined4 *)(lVar6 + 0x10) = local_res10[0];
      *(undefined4 *)(lVar6 + 0x14) = 0x80000004;
      *(undefined4 *)(lVar6 + 0x28) = 0x30;
      iVar4 = FltAddOpenReparseEntry(Globals,param_1,lVar6);
      if (iVar4 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar11 = 0x36;
          uVar13 = 0xf8;
          goto LAB_14002b486;
        }
      }
      else {
        if ((*(uint *)(*(longlong *)(param_1 + 0x10) + 0x20) & 0x200000) == 0) goto LAB_14002b332;
        lVar7 = ExAllocateFromPagedLookasideList(&DAT_14000f380);
        if (lVar7 == 0) {
          iVar4 = -0x3fffff66;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            iVar4 = -0x3fffff66;
            uVar11 = 0x37;
            uVar13 = 8;
            goto LAB_14002b486;
          }
        }
        else {
          *(longlong *)(lVar7 + 8) = lVar7;
          *(longlong *)lVar7 = lVar7;
          *(undefined8 *)(lVar7 + 0x18) = 0;
          *(undefined8 *)(lVar7 + 0x20) = 0;
          *(undefined4 *)(lVar7 + 0x10) = 0xa000001f;
          *(undefined4 *)(lVar7 + 0x28) = 0x30;
          *(undefined4 *)(lVar7 + 0x14) = 0x8000007e;
          iVar4 = FltAddOpenReparseEntry(Globals,param_1,lVar7);
          uVar3 = local_res20[0];
          if (iVar4 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar11 = 0x38;
              uVar13 = 0x1a;
              goto LAB_14002b486;
            }
          }
          else if (((((local_res20[0] & 0xfff0000) == 0) && (2 < local_res20[0])) &&
                   ((local_res20[0] & 0xc0000000) != 0x40000000)) &&
                  ((local_res20[0] & 0x30000000) != 0x30000000)) {
            lVar8 = ExAllocateFromPagedLookasideList(&DAT_14000f380);
            if (lVar8 == 0) {
              iVar4 = -0x3fffff66;
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                iVar4 = -0x3fffff66;
                uVar11 = 0x39;
                uVar13 = 0x25;
                goto LAB_14002b486;
              }
            }
            else {
              *(longlong *)(lVar8 + 8) = lVar8;
              *(longlong *)lVar8 = lVar8;
              *(undefined8 *)(lVar8 + 0x18) = 0;
              *(undefined8 *)(lVar8 + 0x20) = 0;
              *(uint *)(lVar8 + 0x10) = uVar3;
              *(undefined4 *)(lVar8 + 0x28) = 0x30;
              *(undefined4 *)(lVar8 + 0x14) = 0x8000007e;
              iVar4 = FltAddOpenReparseEntry(Globals,param_1,lVar8);
              if (-1 < iVar4) goto LAB_14002b332;
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar11 = 0x3a;
                uVar13 = 0x37;
                goto LAB_14002b486;
              }
            }
          }
          else {
LAB_14002b332:
            *(longlong *)(lVar6 + 0x30) = local_48[0];
            local_48[0] = 0;
            *(longlong *)(lVar6 + 0x38) = lVar7;
            *(longlong *)(lVar6 + 0x40) = lVar8;
            *param_3 = lVar6;
            uVar10 = 5;
            lVar6 = 0;
            lVar7 = 0;
            if (-1 < iVar4) goto LAB_14002b1c4;
          }
        }
      }
    }
  }
LAB_14002b37a:
  *(int *)(param_1 + 0x18) = iVar4;
  uVar10 = 4;
  *(undefined8 *)(param_1 + 0x20) = 0;
LAB_14002b1c4:
  if (local_48[0] != 0) {
    FltReleaseFileNameInformation();
  }
  if (lVar7 != 0) {
    ExFreeToPagedLookasideList(&DAT_14000f380,lVar7);
  }
  if (lVar6 != 0) {
    ExFreeToPagedLookasideList(&DAT_14000f400,lVar6);
  }
  return uVar10;
}



===== WcPreReleaseForSectionSynchronization @ 14002b640 =====

undefined8 WcPreReleaseForSectionSynchronization(longlong param_1,longlong param_2)

{
  longlong lVar1;
  bool bVar2;
  int iVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  longlong lVar6;
  longlong local_res10;
  longlong local_res20;
  
  local_res20 = 0;
  local_res10 = 0;
  bVar2 = WcGetContextFileObject
                    (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),&local_res20,
                     &local_res10);
  lVar1 = local_res10;
  if (bVar2) {
    lVar6 = *(longlong *)(param_2 + 0x20);
    uVar4 = WcUsesSourceSectionObjectPointers(lVar6,local_res10);
    if ((char)uVar4 != '\0') {
      puVar5 = (undefined8 *)WcGetSource(lVar1);
      iVar3 = FsRtlChangeBackingFileObject(lVar6,puVar5[2],1);
      if ((iVar3 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x40,
                            &WPP_27ac746799d63ca1d37704ce911b8053_Traceguids,
                            "onecore\\base\\fs\\wci\\wcifs\\wcifs.c",0x69,(char)iVar3);
      }
      iVar3 = FsRtlChangeBackingFileObject(*(undefined8 *)(param_2 + 0x20),puVar5[2],0,0);
      if ((iVar3 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x41,
                            &WPP_27ac746799d63ca1d37704ce911b8053_Traceguids,
                            "onecore\\base\\fs\\wci\\wcifs\\wcifs.c",0x77,(char)iVar3);
      }
      iVar3 = FsRtlChangeBackingFileObject(*(undefined8 *)(param_2 + 0x20),puVar5[2],2);
      if ((iVar3 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x42,
                            &WPP_27ac746799d63ca1d37704ce911b8053_Traceguids,
                            "onecore\\base\\fs\\wci\\wcifs\\wcifs.c",0x85,(char)iVar3);
      }
      *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 8) = puVar5[2];
      *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x10) = *puVar5;
      FltSetCallbackDataDirty(param_1);
    }
  }
  if (local_res20 != 0) {
    FltReleaseContext();
  }
  if (lVar1 != 0) {
    FltReleaseContext(lVar1);
  }
  return 1;
}



===== WcPreClose @ 14002b8a0 =====

undefined8 WcPreClose(undefined8 param_1,longlong param_2)

{
  int *piVar1;
  bool bVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  longlong local_res10 [2];
  longlong local_res20;
  
  local_res20 = 0;
  local_res10[0] = 0;
  bVar2 = WcGetContextFileObject
                    (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),&local_res20,
                     local_res10);
  lVar5 = local_res10[0];
  if ((bVar2) && (local_res10[0] != 0)) {
    uVar3 = WcIsPlaceHolderDirectory(local_res20,local_res10[0]);
    if ((char)uVar3 == '\0') {
      lVar4 = *(longlong *)(param_2 + 0x20);
      uVar3 = WcUsesSourceSectionObjectPointers(lVar4,lVar5);
      if ((char)uVar3 != '\0') {
        *(undefined8 *)(lVar4 + 0x28) = *(undefined8 *)(lVar5 + 0x30);
        LOCK();
        piVar1 = (int *)(**(longlong **)(lVar5 + 0x20) + 0x18);
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (DAT_14000f680 != '\0') {
          piVar1 = *(int **)(**(longlong **)(lVar5 + 0x20) + 0x20);
          LOCK();
          *piVar1 = *piVar1 + 1;
          UNLOCK();
        }
        lVar5 = local_res10[0];
      }
    }
    if (*(char *)(lVar5 + 0x1d) != '\0') {
      FltDeleteContext(lVar5);
    }
  }
  if (local_res20 != 0) {
    FltReleaseContext();
  }
  if (lVar5 != 0) {
    FltReleaseContext(lVar5);
  }
  return 1;
}



===== WcPreAcquireForSectionSynchronization @ 14002b9a0 =====

ulonglong WcPreAcquireForSectionSynchronization(uint *param_1,longlong param_2,longlong *param_3)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  longlong lVar5;
  bool bVar6;
  byte bVar7;
  char cVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  undefined8 *puVar11;
  ulonglong uVar12;
  longlong local_res8;
  longlong local_res10;
  wchar_t local_48;
  undefined1 auStack_46 [6];
  longlong lStack_40;
  
  local_res8 = 0;
  _local_48 = 0;
  lStack_40 = 0;
  local_res10 = 0;
  uVar12 = 1;
  iVar2 = *(int *)(*(longlong *)(param_1 + 4) + 0x18);
  uVar3 = *(uint *)(*(longlong *)(param_1 + 4) + 0x1c);
  bVar6 = WcGetContextFileObject
                    (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),&local_res8,
                     &local_res10);
  lVar5 = local_res10;
  lVar4 = local_res8;
  if (bVar6) {
    uVar9 = WcIsPlaceHolderDirectory(local_res8,local_res10);
    if ((char)uVar9 == '\0') {
      uVar9 = WcIsPlaceHolderStream(lVar4,lVar5);
      if ((char)uVar9 == '\0') {
        bVar7 = WcIsPlaceHolder(lVar4);
        if (bVar7 == 0) {
          uVar9 = WcUsesSourceSectionObjectPointers(*(longlong *)(param_2 + 0x20),lVar5);
          if ((char)uVar9 == '\0') goto LAB_14002ba0b;
        }
      }
      if ((iVar2 == 1) && ((uVar3 & 0x44) != 0)) {
        uVar9 = WcIsPlaceHolderStream(lVar4,lVar5);
        if ((char)uVar9 != '\0') {
          uVar10 = IoGetSilo(*(undefined8 *)(param_2 + 0x20));
          cVar8 = PsIsHostSilo(uVar10);
          if ((cVar8 == '\0') || (*(int *)(*(longlong *)(lVar5 + 0x28) + 0x1c) != 3)) {
            uVar12 = WcUsesSourceSectionObjectPointers(*(longlong *)(param_2 + 0x20),lVar5);
            if ((char)uVar12 == '\0') {
              uVar9 = WcSynchronizeExpansionPreopWithReason(param_1,param_2,2,4,0xe,param_3);
              uVar12 = uVar9 & 0xffffffff;
              if ((int)uVar9 == 0) {
                uVar1 = *(undefined2 *)(*(longlong *)(lVar4 + 0x40) + 0x20);
                lStack_40 = *(longlong *)(lVar4 + 0x40) + 0x22;
                _local_48 = CONCAT62(CONCAT42(auStack_46._2_4_,uVar1),uVar1);
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  WPP_RECORDER_SF_sDZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,
                                      (short)uVar9 + 0x3f,
                                      &WPP_27ac746799d63ca1d37704ce911b8053_Traceguids,
                                      "onecore\\base\\fs\\wci\\wcifs\\wcifs.c",0xc6,&local_48);
                }
              }
              goto LAB_14002ba0b;
            }
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x3e,
                                 &WPP_27ac746799d63ca1d37704ce911b8053_Traceguids,
                                 "onecore\\base\\fs\\wci\\wcifs\\wcifs.c",0xa4);
            }
          }
          param_1[6] = 0xc0000022;
          uVar12 = 4;
          param_1[8] = 0;
          param_1[9] = 0;
        }
      }
      else {
        uVar9 = WcUsesSourceSectionObjectPointers(*(longlong *)(param_2 + 0x20),lVar5);
        if ((char)uVar9 != '\0') {
          puVar11 = (undefined8 *)WcGetSource(lVar5);
          *(undefined8 *)(*(longlong *)(param_1 + 4) + 8) = puVar11[2];
          *(undefined8 *)(*(longlong *)(param_1 + 4) + 0x10) = *puVar11;
          FltSetCallbackDataDirty(param_1);
        }
      }
    }
  }
LAB_14002ba0b:
  if (lVar4 != 0) {
    FltReleaseContext(lVar4);
  }
  if (lVar5 != 0) {
    FltReleaseContext(lVar5);
  }
  return uVar12;
}



===== WcPreQueryVolumeInformation @ 14002bc60 =====

bool WcPreQueryVolumeInformation(longlong param_1,longlong param_2)

{
  bool bVar1;
  
  bVar1 = true;
  if (*(int *)(*(longlong *)(param_1 + 0x10) + 0x20) == 5) {
    bVar1 = WcIsSiloFileObject(*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20));
    bVar1 = !bVar1;
  }
  return bVar1;
}



===== WcPreQueryEa @ 14002bca0 =====

undefined8 WcPreQueryEa(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  longlong lVar7;
  longlong local_res20;
  ulonglong in_stack_ffffffffffffffb8;
  
  local_res20 = 0;
  uVar6 = 1;
  iVar1 = FltGetStreamContext(*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),
                              &local_res20);
  if (-1 < iVar1) {
    uVar3 = WcShouldRedirectEaAndUsn
                      (*(char *)(param_1 + 0x50),*(longlong *)(param_2 + 0x20),
                       *(longlong *)(local_res20 + 0x20),local_res20);
    if ((char)uVar3 != '\0') {
      lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x40);
      lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x38);
      if (lVar7 != 0) {
        if ((*(byte *)(lVar7 + 10) & 5) == 0) {
          lVar4 = MmMapLockedPagesSpecifyCache
                            (lVar7,0,1,0,in_stack_ffffffffffffffb8 & 0xffffffff00000000,0x40000010);
        }
        else {
          lVar4 = *(longlong *)(lVar7 + 0x18);
        }
      }
      if (lVar4 == 0) {
        uVar2 = 0xc0000017;
      }
      else {
        lVar7 = *(longlong *)(param_1 + 0x10);
        lVar5 = WcGetSource(local_res20);
        uVar2 = FsRtlQueryKernelEaFile
                          (*(undefined8 *)(lVar5 + 0x10),lVar4,*(undefined4 *)(lVar7 + 0x18));
      }
      *(undefined4 *)(param_1 + 0x18) = uVar2;
      uVar6 = 4;
      *(undefined8 *)(param_1 + 0x20) = 0;
    }
    FltReleaseContext(local_res20);
  }
  return uVar6;
}



===== WcPreSetSecurity @ 14002be00 =====

undefined8 WcPreSetSecurity(longlong param_1,longlong param_2)

{
  undefined8 uVar1;
  longlong lVar2;
  longlong lVar3;
  bool bVar4;
  byte bVar5;
  char cVar6;
  int iVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  longlong local_res10;
  longlong local_res20;
  
  uVar1 = *(undefined8 *)(param_2 + 0x18);
  lVar2 = *(longlong *)(param_2 + 0x20);
  iVar7 = 0;
  local_res20 = 0;
  local_res10 = 0;
  uVar9 = 1;
  bVar4 = WcGetContextFileObject(uVar1,lVar2,&local_res20,&local_res10);
  lVar3 = local_res20;
  if ((bVar4) && (bVar5 = WcIsPlaceHolder(local_res20), bVar5 != 0)) {
    uVar8 = WcIsPlaceHolderDirectory(lVar3,local_res10);
    if ((char)uVar8 == '\0') {
      if ((*(uint *)(*(longlong *)(lVar3 + 0x40) + 0xc) & 2) == 0) {
        cVar6 = ExAcquireRundownProtection(lVar3 + 0x48);
        if (cVar6 == '\0') {
          iVar7 = WcExpandAndWait(param_1,uVar1,lVar2,lVar3,1,9);
        }
        else {
          iVar7 = WcSetPlaceHolderFlags(uVar1,lVar2,lVar3,2);
          ExReleaseRundownProtection(lVar3 + 0x48);
        }
      }
    }
    else {
      iVar7 = WcSetPlaceHolderFlags(uVar1,lVar2,lVar3,2);
    }
  }
  if (lVar3 != 0) {
    FltReleaseContext(lVar3);
  }
  if (local_res10 != 0) {
    FltReleaseContext(local_res10);
  }
  if (iVar7 < 0) {
    *(undefined8 *)(param_1 + 0x20) = 0;
    uVar9 = 4;
    *(int *)(param_1 + 0x18) = iVar7;
  }
  return uVar9;
}



===== WcSetPlaceHolderFlagsSynchronized @ 14002bf68 =====

int WcSetPlaceHolderFlagsSynchronized
              (undefined8 param_1,undefined8 param_2,longlong param_3,uint param_4)

{
  longlong lVar1;
  bool bVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  ulonglong uVar6;
  longlong local_28;
  longlong local_20;
  
  iVar5 = 0;
  local_20 = 0;
  local_28 = 0;
  bVar2 = WcGetContextFileObject(param_2,param_3,&local_20,&local_28);
  lVar1 = local_20;
  if ((bVar2) && (bVar3 = WcIsPlaceHolder(local_20), bVar3 != 0)) {
    uVar6 = WcIsPlaceHolderDirectory(lVar1,local_28);
    if ((char)uVar6 == '\0') {
      if ((*(uint *)(*(longlong *)(lVar1 + 0x40) + 0xc) & param_4) != param_4) {
        cVar4 = ExAcquireRundownProtection(lVar1 + 0x48);
        if (cVar4 == '\0') {
          iVar5 = WcExpandAndWait(param_1,param_2,param_3,lVar1,1,9);
        }
        else {
          iVar5 = WcSetPlaceHolderFlags(param_2,param_3,lVar1,param_4);
          ExReleaseRundownProtection(lVar1 + 0x48);
        }
      }
    }
    else {
      iVar5 = WcSetPlaceHolderFlags(param_2,param_3,lVar1,param_4);
    }
  }
  if (lVar1 != 0) {
    FltReleaseContext(lVar1);
  }
  if (local_28 != 0) {
    FltReleaseContext(local_28);
  }
  return iVar5;
}



===== WcInstanceSetup @ 14002c0c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong WcInstanceSetup(longlong param_1,uint param_2,undefined4 param_3,uint param_4)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  longlong lVar5;
  ulonglong uVar6;
  uint *puVar7;
  ulonglong uVar8;
  uint *puVar9;
  undefined2 uVar10;
  wchar_t *pwVar11;
  undefined1 auStackY_448 [32];
  undefined4 *puVar12;
  undefined8 uVar13;
  char *in_stack_fffffffffffffbe0;
  undefined1 uVar14;
  uint local_3c8;
  char local_3c4;
  char local_3c3;
  uint *local_3c0;
  char local_3b8;
  wchar_t *local_3b0;
  uint local_3a8;
  uint local_3a4;
  undefined8 local_3a0;
  undefined4 local_398;
  uint *local_390;
  uint local_388 [2];
  undefined1 *puStack_380;
  undefined4 local_378 [2];
  uint *local_370;
  undefined8 local_368;
  undefined1 *puStack_360;
  longlong local_358;
  undefined8 local_350;
  undefined8 uStack_348;
  uint *local_340;
  undefined8 uStack_338;
  undefined8 local_330;
  ulonglong uStack_328;
  undefined8 local_320;
  undefined8 uStack_318;
  uint local_310 [6];
  undefined8 local_2f8;
  undefined8 uStack_2f0;
  wchar_t local_2e8 [24];
  undefined1 local_2b8 [112];
  uint local_248;
  undefined2 local_244;
  ushort uStack_242;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_448;
  local_310[4] = 0;
  local_310[5] = 0;
  local_330 = 0;
  local_3b0 = local_2e8;
  uStack_328 = uStack_328 & 0xffffffff00000000;
  builtin_wcsncpy(local_2e8,L"Name Not Available",0x13);
  local_3c8 = 0x13;
  local_3c0 = (uint *)0x0;
  local_3a0 = local_3a0 & 0xffffffffffffff00;
  local_3c4 = '\0';
  local_390 = (uint *)0x0;
  local_3a8 = 0;
  local_370 = (uint *)0x0;
  local_358 = 0;
  local_378[0] = 0;
  local_310[0] = 0;
  local_310[1] = 0;
  local_310[2] = 0;
  local_310[3] = 0;
  local_350 = 0;
  uStack_348 = 0;
  local_340 = (uint *)0x0;
  uStack_338 = 0;
  local_320 = 0;
  uStack_318 = 0;
  local_2f8 = 0;
  uStack_2f0 = 0;
  local_368 = 0;
  puStack_360 = (undefined1 *)0x0;
  local_388[0] = 0;
  local_388[1] = 0;
  puStack_380 = (undefined1 *)0x0;
  if ((0x1c < param_4) || ((0x10002044U >> (param_4 & 0x1f) & 1) == 0)) {
    return 0xc01c000f;
  }
  puVar12 = local_378;
  puVar9 = &local_248;
  puVar7 = (uint *)0x0;
  local_3a4 = param_2;
  local_398 = param_3;
  uVar2 = FltGetInstanceInformation(*(undefined8 *)(param_1 + 0x18),0,puVar9,0x210);
  uVar8 = (ulonglong)uVar2;
  uVar14 = (undefined1)param_4;
  if ((int)uVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      puVar7 = (uint *)CONCAT71((int7)((ulonglong)puVar7 >> 8),2);
      WPP_RECORDER_SF_sDlLDd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar9,0x15,puVar12,
                 in_stack_fffffffffffffbe0,0xd0,(char)param_3,uVar14,(char)param_2,(char)uVar2);
    }
LAB_14002c407:
    uVar6 = 0x13;
    pwVar11 = local_2e8;
  }
  else {
    local_368._0_4_ = CONCAT22(local_244,local_244);
    puStack_360 = local_2b8 + (ulonglong)uStack_242 + 0x70;
    local_3c3 = RtlEqualUnicodeString(&local_368,&DAT_14000a4d0);
    puVar9 = (uint *)0x0;
    local_3b8 = RtlEqualUnicodeString(&local_368,&DAT_14000a4e0);
    if ((local_3a4 & 1) != 0) {
      if (param_4 != 2) {
        uVar8 = local_3a0 >> 8;
        local_3a0 = uVar8 << 8;
        if ((param_4 != 6) || (local_3a0 = uVar8 << 8, DAT_14000f730 == 0)) goto LAB_14002c4d5;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          puVar9 = (uint *)0x4;
          in_stack_fffffffffffffbe0 = "onecore\\base\\fs\\wci\\wcifs\\wcifs.c";
          puVar12 = (undefined4 *)&WPP_27ac746799d63ca1d37704ce911b8053_Traceguids;
          WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x17,
                             &WPP_27ac746799d63ca1d37704ce911b8053_Traceguids,
                             "onecore\\base\\fs\\wci\\wcifs\\wcifs.c",0x1c);
        }
        local_3a0 = CONCAT71(local_3a0._1_7_,1);
        goto LAB_14002c4f8;
      }
      lVar5 = DAT_14000f690;
      if (DAT_14000f690 == 0) {
        lVar5 = DAT_14000f698;
      }
      if (lVar5 == 0) {
LAB_14002c45a:
        bVar1 = (byte)local_3a0;
LAB_14002c45d:
        if (bVar1 == 0) {
          if (local_3c3 == '\0') goto LAB_14002c4d5;
          bVar1 = WcShouldAutoAttach(*(undefined8 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x10)
                                    );
        }
        if (bVar1 == 0) goto LAB_14002c4d5;
        goto LAB_14002c4f8;
      }
      puVar9 = (uint *)0x0;
      iVar3 = RtlCompareUnicodeString(&local_368,&DAT_14000f6b8);
      if (iVar3 != 0) goto LAB_14002c45a;
      puVar7 = (uint *)&local_3a0;
      local_3a0 = 0;
      uVar2 = FltGetDiskDeviceObject(*(undefined8 *)(param_1 + 0x10));
      uVar8 = (ulonglong)uVar2;
      if (-1 < (int)uVar2) {
        uVar2 = *(uint *)(local_3a0 + 0x30);
        ObfDereferenceObject();
        local_3a0 = CONCAT44(local_3a0._4_4_,uVar2 >> 8) & 0xffffffff00ffff01;
        bVar1 = (byte)(uVar2 >> 8) & 1;
        goto LAB_14002c45d;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002c407;
      uVar14 = 0xfe;
      uVar10 = 0x16;
LAB_14002c3e4:
      puVar9 = (uint *)0x4;
      puVar7 = (uint *)CONCAT71((int7)((ulonglong)puVar7 >> 8),2);
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,uVar10,
                          &WPP_27ac746799d63ca1d37704ce911b8053_Traceguids,
                          "onecore\\base\\fs\\wci\\wcifs\\wcifs.c",uVar14,(char)uVar2);
      goto LAB_14002c407;
    }
LAB_14002c4d5:
    if ((((local_3a4 & 2) == 0) || (0x1c < param_4)) || ((0x10002044U >> (param_4 & 0x1f) & 1) == 0)
       ) {
      uVar8 = 0xc01c000f;
      goto LAB_14002c240;
    }
LAB_14002c4f8:
    iVar3 = FltIsVolumeSnapshot(*(undefined8 *)(param_1 + 0x10),&local_3c4);
    if (iVar3 < 0) {
      if ((iVar3 != -0x3fe3ffe7) &&
         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_SF_sDlLDd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,puVar9,0x18,puVar12,
                   in_stack_fffffffffffffbe0,0x37,(char)local_398,uVar14,(char)local_3a4,(char)iVar3
                  );
      }
    }
    else if (local_3c4 != '\0') {
      uVar8 = 0xc01c000f;
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_sDlLD
                  (_WcVerboseRecorder,5,puVar9,0x19,puVar12,in_stack_fffffffffffffbe0,0x43,
                   (char)local_398,uVar14,(char)local_3a4);
      }
      goto LAB_14002c240;
    }
    puVar7 = (uint *)0x2;
    if (DAT_14000f680 == '\0') {
      puVar9 = (uint *)0x130;
      uVar2 = FltAllocateContext(*(undefined8 *)(param_1 + 8),2,0x130,0x200);
      uVar8 = (ulonglong)uVar2;
      if (-1 < (int)uVar2) {
        memset(local_3c0,0,0x130);
        goto LAB_14002c67c;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002c407;
      uVar10 = 0x1b;
      uVar14 = 0x6b;
      goto LAB_14002c3e4;
    }
    puVar9 = (uint *)0x13c;
    uVar2 = FltAllocateContext();
    uVar8 = (ulonglong)uVar2;
    if ((int)uVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002c407;
      uVar10 = 0x1a;
      uVar14 = 0x57;
      goto LAB_14002c3e4;
    }
    memset(local_3c0,0,0x130);
    puVar9 = local_3c0 + 0x4c;
    *(uint **)(local_3c0 + 8) = puVar9;
    puVar9[0] = 0;
    puVar9[1] = 0;
    local_3c0[0x4e] = 0;
LAB_14002c67c:
    *(undefined8 *)local_3c0 = *(undefined8 *)(param_1 + 0x18);
    local_3c0[2] = param_4;
    if (local_3c3 == '\0') {
      if (local_3b8 == '\0') {
        local_3c0[4] = 0xffffffff;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          in_stack_fffffffffffffbe0 = "onecore\\base\\fs\\wci\\wcifs\\wcifs.c";
          WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,4,0x1c,
                             &WPP_27ac746799d63ca1d37704ce911b8053_Traceguids,
                             "onecore\\base\\fs\\wci\\wcifs\\wcifs.c",0x85);
        }
      }
      else {
        uVar2 = 0xffffffff;
        if (DAT_14000f6a9 == '\0') {
          uVar2 = DAT_14000f254;
        }
        local_3c0[4] = uVar2;
      }
    }
    else {
      local_3c0[4] = DAT_14000f250;
    }
    ExInitializeResourceLite(local_3c0 + 0x12);
    if ((param_4 == 2) || (param_4 == 0x1c)) {
      puVar9 = (uint *)0x0;
      puVar7 = (uint *)0x0;
      uVar2 = FltGetVolumeProperties(*(undefined8 *)(param_1 + 0x10),0,0,&local_3a8);
      uVar8 = (ulonglong)uVar2;
      if (uVar2 == 0xc0000023) {
        puVar7 = (uint *)(ulonglong)local_3a8;
        puVar9 = (uint *)0x63694357;
        puVar4 = (uint *)ExAllocatePool2(0x100);
        local_390 = puVar4;
        if (puVar4 != (uint *)0x0) goto LAB_14002c7c0;
        uVar8 = 0xc000009a;
      }
      else {
        local_390 = (uint *)0x0;
        puVar4 = (uint *)0x0;
        if (-1 < (int)uVar2) {
LAB_14002c7c0:
          puVar9 = (uint *)(ulonglong)local_3a8;
          puVar7 = local_390;
          uVar2 = FltGetVolumeProperties
                            (*(undefined8 *)(param_1 + 0x10),local_390,puVar9,&local_3a8);
          uVar8 = (ulonglong)uVar2;
          if ((int)uVar2 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_14002c407;
            uVar10 = 0x1e;
            uVar14 = 0xac;
            goto LAB_14002c3e4;
          }
          puVar7 = *(uint **)(param_1 + 0x18);
          puVar9 = (uint *)&local_358;
          local_3b0 = *(wchar_t **)(local_390 + 0x10);
          local_340 = local_390 + 0xe;
          local_3c8 = (uint)(ushort)((ushort)*local_340 >> 1);
          uStack_348 = 0;
          local_350 = CONCAT44(local_350._4_4_,0x30);
          uStack_338 = CONCAT44(uStack_338._4_4_,0x240);
          local_330 = 0;
          uStack_328 = 0;
          uVar2 = FltCreateFileEx(Globals,puVar7,puVar9,&local_370);
          uVar8 = (ulonglong)uVar2;
          if ((int)uVar2 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar10 = 0x1f;
              uVar14 = 0xd0;
LAB_14002c8da:
              puVar9 = (uint *)0x4;
              puVar7 = (uint *)CONCAT71((int7)((ulonglong)puVar7 >> 8),2);
              WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,uVar10,
                                  &WPP_27ac746799d63ca1d37704ce911b8053_Traceguids,
                                  "onecore\\base\\fs\\wci\\wcifs\\wcifs.c",uVar14,(char)uVar2);
            }
          }
          else {
            puVar9 = local_310;
            in_stack_fffffffffffffbe0 = (char *)0x0;
            puVar7 = local_370;
            uVar2 = FltQueryVolumeInformationFile
                              (*(undefined8 *)(param_1 + 0x18),local_370,puVar9,0x18);
            uVar8 = (ulonglong)uVar2;
            if ((int)uVar2 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar10 = 0x20;
                uVar14 = 0xdd;
                goto LAB_14002c8da;
              }
            }
            else {
              puVar9 = &local_3a8;
              puVar7 = local_388;
              local_3c0[3] = local_310[4] * local_310[5];
              puStack_380 = local_2b8;
              local_388[0] = 0x620000;
              uVar2 = FltGetVolumeGuidName(*(undefined8 *)(param_1 + 0x10));
              uVar8 = (ulonglong)uVar2;
              if ((int)uVar2 < 0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  uVar10 = 0x21;
                  uVar14 = 0xeb;
                  goto LAB_14002c8da;
                }
              }
              else {
                puStack_380 = puStack_380 + 0x14;
                local_388[0]._0_2_ = (short)local_388[0] + -0x14;
                puVar7 = local_3c0 + 10;
                uVar2 = RtlGUIDFromString(local_388);
                uVar8 = (ulonglong)uVar2;
                if (-1 < (int)uVar2) goto LAB_14002ca07;
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  uVar10 = 0x22;
                  uVar14 = 0xf6;
                  goto LAB_14002c8da;
                }
              }
            }
          }
          goto LAB_14002c8f9;
        }
      }
      local_390 = puVar4;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        puVar9 = (uint *)0x4;
        puVar7 = (uint *)CONCAT71((int7)((ulonglong)puVar7 >> 8),2);
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x1d,
                            &WPP_27ac746799d63ca1d37704ce911b8053_Traceguids,
                            "onecore\\base\\fs\\wci\\wcifs\\wcifs.c",0xa1,(char)uVar8);
      }
      uVar6 = 0x13;
      pwVar11 = local_2e8;
      if (-1 < (int)uVar8) goto LAB_14002c240;
    }
    else {
LAB_14002ca07:
      iVar3 = FltQueryVolumeInformation(*(undefined8 *)(param_1 + 0x18),&local_320,&local_2f8,0x10);
      if (((iVar3 + 0x80000000U & 0x80000000) == 0) && (iVar3 != -0x7ffffffb)) {
        *(undefined1 *)(local_3c0 + 0x4a) = 0;
      }
      else {
        *(byte *)(local_3c0 + 0x4a) = (byte)((uint)local_2f8 >> 9) & 1;
      }
      uVar13 = 0;
      local_3c0[0x10] = 0;
      RtlInitializeGenericTableAvl
                (local_3c0 + 0x2c,WcCompareUnionTableEntry,WcAllocateUnionTableEntry);
      puVar7 = (uint *)0x1;
      puVar9 = local_3c0;
      uVar2 = FltSetInstanceContext(*(undefined8 *)(param_1 + 0x18));
      uVar8 = (ulonglong)uVar2;
      if (-1 < (int)uVar2) {
        if ((byte)local_3a0 != '\0') {
          if (param_4 == 2) {
            puVar7 = (uint *)0x0;
            uVar6 = WcSetupVsmbBootUnionContext((longlong)local_3c0,(longlong *)0x0);
          }
          else {
            puVar7 = local_3c0;
            uVar6 = WcSetupVsmbBootUnionContext(DAT_14000f730,(longlong *)local_3c0);
            FltReleaseContext(DAT_14000f730);
            DAT_14000f730 = 0;
          }
          uVar8 = uVar6 & 0xffffffff;
          uVar2 = (uint)uVar6;
          if ((int)uVar2 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar10 = 0x24;
              uVar14 = 0x39;
              goto LAB_14002c8da;
            }
            goto LAB_14002c8f9;
          }
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDlLD
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar9,0x25,uVar13,
                     in_stack_fffffffffffffbe0,0x41,(char)local_398,uVar14,(char)local_3a4);
        }
        uVar8 = 0;
        goto LAB_14002c240;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar10 = 0x23;
        uVar14 = 0x1b;
        goto LAB_14002c8da;
      }
LAB_14002c8f9:
      uVar6 = (ulonglong)local_3c8;
      pwVar11 = local_3b0;
    }
  }
  if (((int)uVar8 != -0x3fe3fff1) && ((Microsoft_Windows_Containers_WcifsEnableBits & 1) != 0)) {
    McTemplateK0dhzr1_EtwWriteTransfer(uVar6,puVar7,puVar9,(int)uVar8,(ushort)uVar6,pwVar11);
  }
LAB_14002c240:
  if (local_3c0 != (uint *)0x0) {
    FltReleaseContext();
  }
  if (local_390 != (uint *)0x0) {
    ExFreePoolWithTag(local_390,0x63694357);
  }
  if (local_370 != (uint *)0x0) {
    ObfDereferenceObject();
  }
  if (local_358 != 0) {
    FltClose();
  }
  return uVar8;
}



===== WcPostNetworkQueryOpen @ 14002cbf0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 WcPostNetworkQueryOpen(longlong param_1,longlong param_2,longlong *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  code *pcVar4;
  bool bVar5;
  int iVar6;
  uint uVar7;
  undefined8 uVar8;
  undefined1 auStackY_108 [32];
  undefined8 local_c8;
  undefined8 uStack_c0;
  longlong local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  ulonglong uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined1 local_88 [60];
  int local_4c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_108;
  local_a8 = 0;
  uStack_a0 = uStack_a0 & 0xffffffff00000000;
  local_c8 = 0;
  uStack_c0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_98 = 0;
  uStack_90 = 0;
  memset(local_88,0,0x48);
  if ((*(int *)(param_1 + 0x18) < 0) ||
     (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x20),
     (*(uint *)(lVar3 + 0x30) & 0x400) == 0)) goto LAB_14002cc4b;
  local_b8 = param_3[6] + 8;
  uStack_c0 = 0;
  local_c8 = CONCAT44(local_c8._4_4_,0x30);
  uStack_b0 = CONCAT44(uStack_b0._4_4_,0x200);
  local_a8 = 0;
  uStack_a0 = 0;
  iVar6 = FltQueryInformationByName(Globals,*(undefined8 *)(param_2 + 0x18),&local_c8,&local_98);
  if (iVar6 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x52,
                          &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                          "onecore\\base\\fs\\wci\\wcifs\\create.c",0xf9,(char)iVar6);
    }
  }
  else if (local_4c == (int)param_3[2]) {
    bVar5 = WcIsSiloFileObject(*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20));
    if (bVar5) {
      uVar7 = *(uint *)(lVar3 + 0x30) & 0xffffe9ff;
      if (uVar7 == 0) {
        uVar7 = 0x80;
      }
      *(uint *)(lVar3 + 0x30) = uVar7;
      WcHandleQueryOnCreateEcp
                (param_1,*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20));
      goto LAB_14002cc4b;
    }
  }
  else if (local_4c != -0x5fffffe1) goto LAB_14002cc4b;
  *(undefined8 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0xc01c0004;
LAB_14002cc4b:
  if (param_3 != (longlong *)0x0) {
    if (param_3[6] != 0) {
      FltReleaseFileNameInformation();
    }
    plVar1 = (longlong *)*param_3;
    if (plVar1 != param_3) {
      if (((longlong *)plVar1[1] != param_3) ||
         (plVar2 = (longlong *)param_3[1], (longlong *)*plVar2 != param_3)) {
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3);
        pcVar4 = (code *)swi(3);
        uVar8 = (*pcVar4)();
        return uVar8;
      }
      *plVar2 = (longlong)plVar1;
      plVar1[1] = (longlong)plVar2;
      FltObjectDereference(Globals);
    }
    ExFreeToPagedLookasideList(&DAT_14000f400,param_3);
  }
  return 0;
}



===== WcPreQueryOpen @ 14002ce10 =====

bool WcPreQueryOpen(undefined8 param_1,longlong param_2)

{
  undefined8 uVar1;
  
  uVar1 = WcUnionsExistForInstance
                    (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),
                     (undefined4 *)0x0,(undefined4 *)0x0);
  return (char)uVar1 == '\0';
}



===== WcCompareUnionTableEntry @ 14002ce40 =====

undefined8 WcCompareUnionTableEntry(undefined8 param_1,longlong *param_2,longlong *param_3)

{
  ushort *puVar1;
  ushort *puVar2;
  longlong *plVar3;
  longlong *plVar4;
  ushort uVar5;
  ushort uVar6;
  int iVar7;
  longlong lVar8;
  ushort *puVar9;
  ushort *puVar10;
  undefined8 uVar11;
  ushort local_18;
  ushort local_16;
  undefined4 local_14;
  longlong local_10;
  
  local_14 = 0;
  puVar1 = (ushort *)(*param_2 + 8);
  uVar5 = *puVar1;
  puVar2 = (ushort *)(*param_3 + 8);
  plVar3 = (longlong *)(*param_3 + 0x10);
  plVar4 = (longlong *)(*param_2 + 0x10);
  if (*puVar2 < uVar5) {
    local_16 = *puVar2;
    local_10 = *plVar4;
    puVar9 = &local_18;
    puVar10 = puVar2;
    local_18 = *puVar2;
  }
  else {
    puVar10 = &local_18;
    local_16 = *puVar1;
    local_10 = *plVar3;
    puVar9 = puVar1;
    local_18 = uVar5;
  }
  iVar7 = RtlCompareUnicodeString(puVar9,puVar10,CONCAT71((uint7)(byte)(uVar5 >> 8),1));
  if (iVar7 < 1) {
    if (iVar7 < 0) {
      return 0;
    }
    uVar5 = *puVar2;
    uVar11 = 2;
    uVar6 = *puVar1;
    if (uVar5 <= uVar6) {
      if (uVar5 < uVar6) {
        lVar8 = RtlCompareMemory(*plVar4 + (ulonglong)(uVar5 >> 1) * 2,L"\\",2);
        uVar11 = 2;
        if (lVar8 != 2) {
          uVar11 = 0;
        }
      }
      goto LAB_14002cef7;
    }
    lVar8 = RtlCompareMemory(*plVar3 + (ulonglong)(uVar6 >> 1) * 2,L"\\",2);
    if (lVar8 == 2) goto LAB_14002cef7;
  }
  uVar11 = 1;
LAB_14002cef7:
  return uVar11;
}



===== WcMergeEnumerationResults @ 14002cf68 =====

int WcMergeEnumerationResults
              (undefined8 *param_1,int param_2,uint param_3,uint param_4,longlong param_5,
              int *param_6,longlong *param_7,undefined4 *param_8)

{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  ulonglong uVar6;
  undefined4 uVar7;
  int iVar8;
  longlong *plVar9;
  int iVar10;
  longlong *plVar11;
  int iVar12;
  int iVar13;
  longlong lVar14;
  int iVar15;
  uint uVar16;
  undefined4 in_stack_ffffffffffffff68;
  undefined4 in_stack_ffffffffffffff6c;
  char local_68;
  uint local_64;
  undefined4 local_60;
  uint local_5c;
  int local_58;
  uint local_54;
  uint local_50;
  undefined4 local_4c;
  longlong *local_48;
  longlong local_40;
  uint *local_38;
  uint *local_30;
  
  iVar13 = 0;
  iVar8 = 0;
  iVar12 = 0;
  iVar10 = 0;
  bVar1 = false;
  local_5c = 0;
  local_38 = (uint *)0x0;
  local_64 = 0;
  local_58 = 0;
  local_30 = (uint *)0x0;
  local_50 = 0;
  lVar14 = 0;
  local_40 = 0;
  *param_8 = 0;
  for (puVar5 = (undefined8 *)*param_1; iVar15 = 0, puVar5 != param_1;
      puVar5 = (undefined8 *)*puVar5) {
    iVar13 = iVar13 + 1;
    iVar15 = *(int *)(puVar5 + 3);
    if (iVar15 == -0x7ffffffa) {
      iVar8 = iVar8 + 1;
    }
    else if (iVar15 == -0x3ffffff1) {
      iVar12 = iVar12 + 1;
    }
    else if (iVar15 == -0x7ffffffb) {
      iVar10 = iVar10 + 1;
    }
    else if (iVar15 < 0) {
      bVar1 = true;
      break;
    }
  }
  if (!bVar1) {
    if (iVar12 != iVar13) {
      if (iVar12 + iVar8 == iVar13) {
        *param_6 = 0;
        return -0x7ffffffa;
      }
      if (iVar10 == 0) {
        local_68 = '\x01';
        uVar16 = 0;
LAB_14002d058:
        do {
          if (param_4 <= local_64) break;
          plVar11 = (longlong *)0x0;
          local_48 = (longlong *)0x0;
          plVar9 = (longlong *)*param_1;
          if (plVar9 != param_1) {
            do {
              if ((int)plVar9[3] != -0x7ffffffa) {
                if ((int)plVar9[3] != -0x3ffffff1) {
                  if (plVar11 != (longlong *)0x0) {
                    uVar4 = WcCompareEnumEntries((longlong)plVar11,(longlong)plVar9);
                    if ((int)uVar4 < 1) {
                      if ((int)uVar4 == 0) {
                        WcAdvanceNextEnumEntry((longlong)plVar9);
                      }
                      goto LAB_14002d0a4;
                    }
                  }
                  plVar11 = plVar9;
                  local_48 = plVar9;
                }
              }
LAB_14002d0a4:
              plVar9 = (longlong *)*plVar9;
            } while (plVar9 != param_1);
            uVar16 = local_50;
          }
          if (plVar11 == (longlong *)0x0) break;
          local_54 = 0;
          local_60 = 0;
          puVar3 = WcGetEnumEntry((longlong)plVar11,*(uint *)(plVar11 + 7),&local_54,&local_60,
                                  &local_4c);
          if (puVar3 == (undefined4 *)0x0) {
            uVar7 = 0;
          }
          else {
            lVar14 = (ulonglong)local_54 + (longlong)puVar3;
            uVar7 = local_60;
            local_40 = lVar14;
          }
          local_60 = uVar7;
          uVar4 = WcSkipReparsePointInEnumeration((longlong)plVar11,-0x5fffffe1);
          if ((char)uVar4 != '\0') {
            *param_7 = lVar14;
            *param_8 = uVar7;
            goto LAB_14002d058;
          }
          iVar15 = 0;
          puVar5 = (undefined8 *)
                   WcGetEnumEntry((longlong)plVar11,*(uint *)(plVar11 + 7),&local_54,&local_50,
                                  &local_4c);
          if (puVar5 == (undefined8 *)0x0) {
            local_5c = 0;
          }
          else {
            uVar6 = WcMungeDirectoryEntry
                              (*(int *)((longlong)plVar11 + 0x34),param_2,local_68,
                               *(byte *)(plVar11 + 2) & 1,param_3,0xfff0000,
                               CONCAT44(in_stack_ffffffffffffff6c,in_stack_ffffffffffffff68),puVar5,
                               param_4 - local_64,(undefined8 *)((ulonglong)local_64 + param_5),
                               &local_38,&local_5c);
            iVar15 = (int)uVar6;
          }
          uVar2 = local_5c;
          if (iVar15 == -0x7ffffffb) {
            uVar16 = uVar2;
            break;
          }
          if (iVar15 < 0) goto LAB_14002d28f;
          if (local_5c == 0) break;
          if (uVar16 != 0) {
            local_58 = local_58 + (uVar16 + 7 & 0xfffffff8);
          }
          if ((local_30 != (uint *)0x0) && (*local_30 = uVar16 + 7 & 0xfffffff8, iVar15 < 0))
          goto LAB_14002d28f;
          local_68 = '\0';
          local_30 = local_38;
          local_64 = local_64 + (local_5c + 7 & 0xfffffff8);
          local_50 = local_5c;
          WcAdvanceNextEnumEntry((longlong)plVar11);
          *param_7 = lVar14;
          *param_8 = uVar7;
          uVar16 = uVar2;
        } while ((*(byte *)(plVar11 + 6) & 2) == 0);
        *param_6 = local_58 + uVar16;
        goto LAB_14002d28f;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0x12,0x19,
                            &WPP_795aeb0acc6f36f288a32122a031d179_Traceguids,
                            "onecore\\base\\fs\\wci\\wcifs\\dir.c",0x96,5);
      }
    }
    *param_6 = 0;
    iVar15 = -0x3ffffff1;
  }
LAB_14002d28f:
  return iVar15;
}



===== WcSkipReparsePointInEnumeration @ 14002d39c =====

ulonglong WcSkipReparsePointInEnumeration(longlong param_1,int param_2)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined7 extraout_var;
  ulonglong uVar3;
  undefined4 *puVar4;
  undefined4 local_res8 [2];
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  
  puVar4 = local_res20;
  puVar2 = WcGetEnumEntry(param_1,*(uint *)(param_1 + 0x38),puVar4,local_res18,local_res8);
  uVar3 = 0;
  if (puVar2 != (undefined4 *)0x0) {
    bVar1 = WcShouldSkipReparsePointInDirectoryEntry
                      (*(int *)(param_1 + 0x34),param_2,puVar4,(longlong)puVar2);
    uVar3 = CONCAT71(extraout_var,bVar1);
    if (bVar1) {
      uVar3 = WcAdvanceNextEnumEntry(param_1);
      return CONCAT71((int7)(uVar3 >> 8),1);
    }
  }
  return uVar3 & 0xffffffffffffff00;
}



===== WcAdvanceNextEnumEntry @ 14002d3fc =====

ulonglong WcAdvanceNextEnumEntry(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  ulonglong uVar4;
  int local_res8 [2];
  undefined4 local_res10 [2];
  undefined4 local_res18 [2];
  
  uVar1 = *(uint *)(param_1 + 0x38);
  local_res8[0] = 0;
  puVar3 = WcGetEnumEntry(param_1,uVar1,local_res18,local_res10,local_res8);
  if (puVar3 == (undefined4 *)0x0) {
    uVar2 = *(uint *)(param_1 + 0x3c);
    if (uVar1 != uVar2) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDdd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,0x12,0x18,
                   &WPP_795aeb0acc6f36f288a32122a031d179_Traceguids,
                   "onecore\\base\\fs\\wci\\wcifs\\dir.c",0x2e,(char)uVar1,(char)uVar2);
      }
      uVar2 = *(uint *)(param_1 + 0x3c);
      *(uint *)(param_1 + 0x38) = uVar2;
    }
    uVar4 = (ulonglong)uVar2 & 0xffffffffffffff00;
  }
  else {
    if (local_res8[0] == 0) {
      local_res8[0] = *(int *)(param_1 + 0x3c);
    }
    else {
      local_res8[0] = local_res8[0] + uVar1;
    }
    *(int *)(param_1 + 0x38) = local_res8[0];
    uVar4 = CONCAT71((uint7)(uint3)((uint)local_res8[0] >> 8),1);
  }
  return uVar4;
}



===== WcTranslateNextEnumEntry @ 14002d4bc =====

ulonglong WcTranslateNextEnumEntry
                    (longlong param_1,int param_2,uint param_3,uint param_4,char param_5,
                    uint param_6,undefined8 *param_7,undefined8 *param_8,uint *param_9)

{
  undefined8 *puVar1;
  ulonglong uVar2;
  undefined4 local_res8 [2];
  undefined8 in_stack_ffffffffffffffa8;
  undefined4 local_28;
  undefined4 local_24 [3];
  
  uVar2 = 0;
  puVar1 = (undefined8 *)
           WcGetEnumEntry(param_1,*(uint *)(param_1 + 0x38),local_24,&local_28,local_res8);
  if (puVar1 == (undefined8 *)0x0) {
    *param_9 = 0;
  }
  else {
    uVar2 = WcMungeDirectoryEntry
                      (*(int *)(param_1 + 0x34),param_2,param_5,*(byte *)(param_1 + 0x10) & 1,
                       param_3,param_4,in_stack_ffffffffffffffa8,puVar1,param_6,param_7,param_8,
                       param_9);
    uVar2 = uVar2 & 0xffffffff;
  }
  return uVar2;
}



===== WcMungeDirectoryEntry @ 14002d57c =====

ulonglong WcMungeDirectoryEntry
                    (int param_1,int param_2,char param_3,char param_4,uint param_5,uint param_6,
                    undefined8 param_7,undefined8 *param_8,uint param_9,undefined8 *param_10,
                    undefined8 *param_11,uint *param_12)

{
  undefined4 uVar1;
  ulonglong uVar2;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  undefined4 extraout_var_01;
  undefined4 extraout_var_02;
  undefined4 extraout_var_03;
  undefined4 extraout_var_04;
  undefined4 extraout_var_05;
  
  if (param_1 == 0xc) {
    uVar1 = WcMungeNamesEnumerate
                      (param_2,param_3,param_8,(undefined4 *)param_10,param_9,param_11,param_12);
    uVar2 = CONCAT44(extraout_var_05,uVar1);
  }
  else if (param_1 == 0x21) {
    uVar2 = WcMungeReparseEnumerate(param_2,param_8,param_10,param_9,param_12);
  }
  else if (param_1 == 0x3c) {
    uVar1 = WcMungeDirectoryEnumerateWithoutShortname
                      (param_2,param_3,param_8,param_4,param_5,param_6,param_10,param_9,param_11,
                       param_12);
    uVar2 = CONCAT44(extraout_var_04,uVar1);
  }
  else if (param_1 == 0x3f) {
    uVar1 = WcMungeDirectoryEnumerateWithShortname
                      (param_2,param_3,param_8,param_4,param_5,param_6,param_10,param_9,param_11,
                       param_12);
    uVar2 = CONCAT44(extraout_var_03,uVar1);
  }
  else if (param_1 == 0x4e) {
    uVar1 = WcMungeDirectoryEnumerateWithoutShortnameFileId64
                      (param_2,param_3,param_8,param_4,param_5,param_6,param_10,param_9,param_11,
                       param_12);
    uVar2 = CONCAT44(extraout_var_02,uVar1);
  }
  else if (param_1 == 0x4f) {
    uVar1 = WcMungeDirectoryEnumerateWithShortnameFileId64
                      (param_2,param_3,param_8,param_4,param_5,param_6,param_10,param_9,param_11,
                       param_12);
    uVar2 = CONCAT44(extraout_var_01,uVar1);
  }
  else if (param_1 == 0x50) {
    uVar1 = WcMungeDirectoryEnumerateWithoutShortnameFileIdAll
                      (param_2,param_3,param_8,param_4,param_5,param_6,param_10,param_9,param_11,
                       param_12);
    uVar2 = CONCAT44(extraout_var_00,uVar1);
  }
  else if (param_1 == 0x51) {
    uVar1 = WcMungeDirectoryEnumerateWithShortnameFileIdAll
                      (param_2,param_3,param_8,param_4,param_5,param_6,param_10,param_9,param_11,
                       param_12);
    uVar2 = CONCAT44(extraout_var,uVar1);
  }
  else {
    uVar2 = 0xc000000d;
  }
  return uVar2;
}



===== WcCompareEnumEntries @ 14002d888 =====

undefined8 WcCompareEnumEntries(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  uint local_res8 [2];
  int local_res10 [2];
  undefined4 local_res18 [4];
  undefined2 local_48;
  undefined2 local_46;
  undefined4 local_44;
  longlong local_40;
  undefined2 local_38;
  undefined2 local_36;
  undefined4 local_34;
  longlong local_30;
  
  lVar5 = 0;
  local_34 = 0;
  local_44 = 0;
  local_res8[0] = 0;
  lVar6 = 0;
  local_res10[0] = 0;
  puVar2 = WcGetEnumEntry(param_1,*(uint *)(param_1 + 0x38),local_res8,local_res10,local_res18);
  if (puVar2 == (undefined4 *)0x0) {
    iVar4 = 0;
  }
  else {
    lVar6 = (ulonglong)local_res8[0] + (longlong)puVar2;
    iVar4 = local_res10[0];
  }
  local_res8[0] = 0;
  local_res10[0] = 0;
  puVar2 = WcGetEnumEntry(param_2,*(uint *)(param_2 + 0x38),local_res8,local_res10,local_res18);
  if (puVar2 == (undefined4 *)0x0) {
    iVar1 = 0;
  }
  else {
    lVar5 = (ulonglong)local_res8[0] + (longlong)puVar2;
    iVar1 = local_res10[0];
  }
  if (iVar4 == 0) {
    uVar3 = 0xffffffff;
  }
  else if (iVar1 == 0) {
    uVar3 = 1;
  }
  else {
    local_38 = (undefined2)iVar4;
    local_48 = (undefined2)iVar1;
    local_46 = local_48;
    local_40 = lVar5;
    local_36 = local_38;
    local_30 = lVar6;
    uVar3 = RtlCompareUnicodeString(&local_38,&local_48,1);
  }
  return uVar3;
}



===== WcPreSetEa @ 14002d960 =====

undefined8 WcPreSetEa(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  longlong local_res10;
  
  local_res10 = 0;
  uVar6 = 1;
  iVar1 = FltGetStreamContext(*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),
                              &local_res10);
  if (-1 < iVar1) {
    if (*(char *)(param_1 + 0x50) == '\0') {
      uVar3 = WcUsesSourceSectionObjectPointers(*(longlong *)(param_2 + 0x20),local_res10);
      if (((char)uVar3 != '\0') &&
         (lVar5 = *(longlong *)(param_1 + 0x10), *(char *)(lVar5 + 5) == '\x04')) {
        lVar4 = *(longlong *)(lVar5 + 0x20);
        lVar5 = *(longlong *)(lVar5 + 0x28);
        if (lVar5 != 0) {
          if ((*(byte *)(lVar5 + 10) & 5) == 0) {
            lVar4 = MmMapLockedPagesSpecifyCache(lVar5,0,1,0,0,0x40000010);
          }
          else {
            lVar4 = *(longlong *)(lVar5 + 0x18);
          }
        }
        if (lVar4 == 0) {
          uVar2 = 0xc0000017;
        }
        else if (WcDbgProtectPackage == '\0') {
          lVar5 = WcGetSource(local_res10);
          uVar2 = FsRtlSetKernelEaFile(*(undefined8 *)(lVar5 + 0x10));
        }
        else {
          uVar2 = 0xc00000a2;
        }
        *(undefined8 *)(param_1 + 0x20) = 0;
        uVar6 = 4;
        *(undefined4 *)(param_1 + 0x18) = uVar2;
      }
    }
    FltReleaseContext(local_res10);
  }
  return uVar6;
}



===== WcPostSetInformation @ 14002da90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 WcPostSetInformation(longlong param_1,longlong param_2,longlong *param_3)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  int *piVar5;
  byte *pbVar6;
  undefined2 uVar7;
  undefined1 auStackY_e8 [32];
  undefined8 in_stack_ffffffffffffff38;
  undefined1 uVar8;
  undefined1 local_a8;
  undefined1 local_a7 [3];
  int local_a4;
  longlong local_a0;
  longlong local_98 [2];
  undefined8 local_88 [4];
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  int *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_98[0] = 0;
  local_a0 = 0;
  piVar5 = (int *)0x0;
  iVar3 = *(int *)(*(longlong *)(param_1 + 0x10) + 0x20);
  if (iVar3 == 10) {
LAB_14002dcd6:
    if (*(int *)(param_1 + 0x18) == 0) {
      uVar4 = WcRemoveInMemoryTombstoneAfterRenameLink(param_1,param_2,'\0');
      iVar3 = (int)uVar4;
      if (iVar3 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar7 = 0x10;
          uVar8 = 0x3c;
          goto LAB_14002df59;
        }
      }
      else {
        piVar5 = (int *)WcGetUnionContext(0,*(undefined8 *)(param_2 + 0x18),param_3[1]);
        if (((piVar5 != (int *)0x0) &&
            (uVar2 = WcGetSetContextFileObject
                               (*(undefined8 *)(param_2 + 0x18),param_3[1],piVar5,1,
                                in_stack_ffffffffffffff38,&local_a0,local_98), -1 < (int)uVar2)) &&
           (uVar2 != 0x104)) {
          iVar3 = WcCreateTombstone(*(undefined8 *)(param_2 + 0x18),*param_3 + 8,(char)param_3[2]);
          if (iVar3 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x11,
                                  &WPP_62cdeb337fdf307834c1a2cccb2efbc6_Traceguids,
                                  "onecore\\base\\fs\\wci\\wcifs\\fileinfo.c",0x6c,(char)iVar3);
            }
            if ((5 < DAT_14000f060) &&
               (uVar4 = _tlgKeywordOn(0x14000f060,0x400000000000), (char)uVar4 != '\0')) {
              local_68 = &local_a8;
              local_a8 = 1;
              pbVar6 = &DAT_14000b63e;
              local_58 = local_a7;
              local_a4 = iVar3;
LAB_14002de47:
              local_48 = &local_a4;
              local_40 = 4;
              local_50 = 1;
              local_a7[0] = 2;
              local_60 = 1;
              _tlgWriteTransfer_EtwWriteTransfer(0x14000f060,pbVar6,0,0,5,local_88);
            }
          }
          else {
            iVar3 = WcRemoveInMemoryTombstone(*(undefined8 *)(param_2 + 0x18),*param_3,param_3[1]);
            if (iVar3 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0x13,0x12,
                                    &WPP_62cdeb337fdf307834c1a2cccb2efbc6_Traceguids,
                                    "onecore\\base\\fs\\wci\\wcifs\\fileinfo.c",0x7f,(char)iVar3);
              }
              if ((5 < DAT_14000f060) &&
                 (uVar4 = _tlgKeywordOn(0x14000f060,0x400000000000), (char)uVar4 != '\0')) {
                local_68 = local_a7;
                local_a8 = 2;
                pbVar6 = &DAT_14000b69c;
                local_58 = &local_a8;
                local_a4 = iVar3;
                goto LAB_14002de47;
              }
            }
          }
        }
      }
    }
    else {
      uVar4 = WcRemoveInMemoryTombstoneAfterRenameLink(param_1,param_2,'\x01');
      iVar3 = (int)uVar4;
      if ((iVar3 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        uVar7 = 0x13;
        uVar8 = 0x97;
LAB_14002df59:
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,uVar7,
                            &WPP_62cdeb337fdf307834c1a2cccb2efbc6_Traceguids,
                            "onecore\\base\\fs\\wci\\wcifs\\fileinfo.c",uVar8,(char)iVar3);
      }
    }
    if (param_3 != (longlong *)0x0) {
      if (*param_3 != 0) {
        FltReleaseFileNameInformation();
      }
      if (param_3[1] != 0) {
        ObfDereferenceObject();
      }
      ExFreeToPagedLookasideList(&DAT_14000f500,param_3);
    }
LAB_14002db85:
    if (local_a0 != 0) {
      FltReleaseContext();
    }
    if (local_98[0] != 0) {
      FltReleaseContext();
    }
    if (piVar5 != (int *)0x0) {
      WcReleaseUnionContext(piVar5);
    }
  }
  else {
    if (iVar3 == 0xb) {
LAB_14002dbc3:
      if (*(int *)(param_1 + 0x18) == 0) {
        uVar4 = WcRemoveInMemoryTombstoneAfterRenameLink(param_1,param_2,'\x01');
        iVar3 = (int)uVar4;
        if (-1 < iVar3) {
          return 0;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return 0;
        }
        uVar7 = 0x14;
        uVar8 = 0xaf;
      }
      else {
        uVar4 = WcRemoveInMemoryTombstoneAfterRenameLink(param_1,param_2,'\0');
        iVar3 = (int)uVar4;
        if (-1 < iVar3) {
          return 0;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return 0;
        }
        uVar7 = 0x15;
        uVar8 = 0xbc;
      }
    }
    else {
      if ((iVar3 != 0xd) && (iVar3 != 0x40)) {
        if (iVar3 == 0x41) goto LAB_14002dcd6;
        if (iVar3 == 0x48) goto LAB_14002dbc3;
        goto LAB_14002db85;
      }
      puVar1 = *(uint **)(*(longlong *)(param_1 + 0x10) + 0x38);
      if (*(int *)(param_1 + 0x18) == 0) {
        if ((iVar3 != 0xd) || ((char)*puVar1 != '\0')) {
          if (iVar3 != 0x40) {
            return 0;
          }
          if ((*puVar1 & 1) != 0) {
            return 0;
          }
        }
        uVar4 = WcRevertDelete(param_1,param_2);
        iVar3 = (int)uVar4;
        if (-1 < iVar3) {
          return 0;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return 0;
        }
        uVar7 = 0x16;
        uVar8 = 0xdd;
      }
      else {
        if ((iVar3 != 0xd) || ((char)*puVar1 != '\x01')) {
          if (iVar3 != 0x40) {
            return 0;
          }
          if ((*puVar1 & 1) == 0) {
            return 0;
          }
        }
        uVar4 = WcRevertDelete(param_1,param_2);
        iVar3 = (int)uVar4;
        if (-1 < iVar3) {
          return 0;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return 0;
        }
        uVar7 = 0x17;
        uVar8 = 0xf9;
      }
    }
    WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,uVar7,
                        &WPP_62cdeb337fdf307834c1a2cccb2efbc6_Traceguids,
                        "onecore\\base\\fs\\wci\\wcifs\\fileinfo.c",uVar8,(char)iVar3);
  }
  return 0;
}



===== WcRemoveInMemoryTombstoneAfterRenameLink @ 14002e000 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong WcRemoveInMemoryTombstoneAfterRenameLink(longlong param_1,longlong param_2,char param_3)

{
  bool bVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  ulonglong uVar5;
  longlong lVar6;
  undefined1 auStackY_118 [32];
  undefined1 local_d8;
  undefined1 local_d7 [3];
  undefined4 local_d4;
  longlong local_d0;
  longlong local_c8;
  undefined8 local_c0;
  longlong lStack_b8;
  longlong local_b0;
  undefined2 local_a8;
  undefined2 local_a6;
  undefined4 local_a4;
  longlong local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88 [4];
  undefined1 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined1 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_118;
  lVar6 = 0;
  local_b0 = 0;
  local_d0 = 0;
  lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x38);
  local_a4 = 0;
  local_d4 = 0;
  local_c8 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_c0 = 0;
  lStack_b8 = 0;
  RtlInitUnicodeString(&local_c0,0);
  local_a6 = *(undefined2 *)(lVar4 + 0x10);
  local_a8 = *(undefined2 *)(lVar4 + 0x10);
  local_a0 = lVar4 + 0x14;
  uVar2 = FltParseFileName(&local_a8,0,0,&local_98);
  uVar5 = (ulonglong)uVar2;
  if (-1 < (int)uVar2) {
    bVar1 = WcGetContextFileObject
                      (*(undefined8 *)(param_2 + 0x18),
                       *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x28),&local_b0,&local_d0);
    lVar6 = local_d0;
    if (((bVar1) && (local_d0 != 0)) && (*(longlong *)(local_d0 + 0x100) != 0)) {
      uVar2 = RtlDowncaseUnicodeString(&local_98,&local_98,0);
      uVar5 = (ulonglong)uVar2;
      if (-1 < (int)uVar2) {
        uVar2 = RtlHashUnicodeString(&local_98,1,0);
        uVar5 = (ulonglong)uVar2;
        if (-1 < (int)uVar2) {
          if (param_3 != '\0') {
            uVar2 = FltGetFileNameInformationUnsafe
                              (*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x28),
                               *(undefined8 *)(param_2 + 0x18),0x301);
            uVar5 = (ulonglong)uVar2;
            if ((int)uVar2 < 0) goto LAB_14002e359;
            local_c0._0_4_ = CONCAT22(*(short *)(local_c8 + 10) + 0x20a,(undefined2)local_c0);
            uVar3 = WcAllocateUnicodeString(0x6e664357,(undefined2 *)&local_c0);
            uVar5 = uVar3 & 0xffffffff;
            if ((int)uVar3 < 0) goto LAB_14002e359;
            RtlAppendUnicodeStringToString(&local_c0,local_c8 + 8);
            RtlAppendUnicodeToString(&local_c0,L"\\");
          }
          KeWaitForSingleObject(lVar6 + 0xe8,0,0);
          lVar4 = RtlLookupEntryHashTable(*(undefined8 *)(lVar6 + 0x100),local_d4,0);
          if (lVar4 != 0) {
            RtlRemoveEntryHashTable(*(undefined8 *)(lVar6 + 0x100),lVar4,0);
            if (param_3 != '\0') {
              RtlAppendUnicodeStringToString(&local_c0,lVar4 + 0x20);
              uVar2 = WcCreateTombstone(*(undefined8 *)(param_2 + 0x18),&local_c0,
                                        *(char *)(lVar4 + 0x18));
              uVar5 = (ulonglong)uVar2;
              if ((int)uVar2 < 0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x1c,
                                      &WPP_6c993b8198b53d328fc429e03cc469de_Traceguids,
                                      "onecore\\base\\fs\\wci\\wcifs\\tombstone.c",0x1f,(char)uVar2)
                  ;
                }
                if (5 < DAT_14000f060) {
                  uVar3 = _tlgKeywordOn(0x14000f060,0x400000000000);
                  if ((char)uVar3 != '\0') {
                    local_5c = 0;
                    local_68 = &local_d8;
                    local_4c = 0;
                    local_3c = 0;
                    local_58 = local_d7;
                    local_d8 = 1;
                    local_48 = &local_d0;
                    local_60 = 1;
                    local_50 = 1;
                    local_d7[0] = 7;
                    local_d0 = CONCAT44(local_d0._4_4_,uVar2);
                    local_40 = 4;
                    _tlgWriteTransfer_EtwWriteTransfer(0x14000f060,&DAT_14000bc63,0,0,5,local_88);
                  }
                }
              }
            }
            ExFreePoolWithTag(lVar4,0x74684357);
          }
          KeSetEvent(lVar6 + 0xe8,0,0);
        }
      }
    }
  }
LAB_14002e359:
  if (lStack_b8 != 0) {
    ExFreePoolWithTag(lStack_b8,0x6e664357);
  }
  if (local_c8 != 0) {
    FltReleaseFileNameInformation();
  }
  if (local_b0 != 0) {
    FltReleaseContext();
  }
  if (lVar6 != 0) {
    FltReleaseContext(lVar6);
  }
  return uVar5;
}



===== WcPostQueryVolumeInformation @ 14002e3f0 =====

undefined8 WcPostQueryVolumeInformation(longlong param_1)

{
  uint *puVar1;
  uint uVar2;
  
  if (((*(int *)(param_1 + 0x18) + 0x80000000U & 0x80000000) != 0) ||
     (*(int *)(param_1 + 0x18) == -0x7ffffffb)) {
    puVar1 = *(uint **)(*(longlong *)(param_1 + 0x10) + 0x28);
    uVar2 = 0;
    if (DAT_14000f6a3 == '\0') {
      uVar2 = 0x20000;
    }
    if (DAT_14000f6a0 == '\0') {
      uVar2 = uVar2 | 0x200000;
    }
    if (DAT_14000f6a7 == '\0') {
      uVar2 = uVar2 | 0x2000000;
    }
    if (DAT_14000f6a8 == '\0') {
      uVar2 = uVar2 | 0x4000000;
    }
    if (DAT_14000f6a1 == '\0') {
      uVar2 = uVar2 | 0x20;
    }
    *puVar1 = *puVar1 & ~uVar2;
  }
  return 0;
}



===== WcGetNextEntryFileName @ 14002e46c =====

uint WcGetNextEntryFileName(longlong param_1,longlong *param_2)

{
  undefined4 *puVar1;
  uint local_res8 [4];
  uint local_res18 [2];
  undefined4 local_res20 [2];
  
  local_res8[0] = 0;
  local_res18[0] = 0;
  puVar1 = WcGetEnumEntry(param_1,*(uint *)(param_1 + 0x38),local_res8,local_res18,local_res20);
  if (puVar1 == (undefined4 *)0x0) {
    local_res18[0] = 0;
  }
  else if (param_2 != (longlong *)0x0) {
    *param_2 = (ulonglong)local_res8[0] + (longlong)puVar1;
  }
  return local_res18[0];
}



===== WcCopyAsPlaceHolder @ 14002e4c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint WcCopyAsPlaceHolder(undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4,
                        undefined8 param_5,undefined8 param_6,longlong param_7,longlong param_8,
                        int param_9,byte param_10)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  uint uVar5;
  undefined2 uVar6;
  ushort uVar7;
  undefined1 auStackY_268 [32];
  undefined1 uVar8;
  int local_1e0 [2];
  undefined8 local_1d8;
  undefined4 local_1d0 [2];
  longlong local_1c8;
  undefined8 local_1c0;
  longlong local_1b8;
  undefined4 local_1b0 [2];
  wchar_t *local_1a8;
  longlong local_1a0;
  longlong local_198;
  longlong local_190;
  longlong local_188;
  longlong local_180;
  undefined8 local_178;
  longlong lStack_170;
  undefined8 local_168;
  undefined8 uStack_160;
  ulonglong local_158;
  undefined8 local_150;
  undefined8 local_148;
  undefined8 local_140;
  undefined8 uStack_138;
  wchar_t *local_130;
  undefined8 uStack_128;
  longlong local_120;
  ulonglong local_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  ulonglong local_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined4 local_88;
  undefined4 local_84;
  undefined8 local_80 [4];
  int *local_60;
  undefined8 local_58;
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStackY_268;
  local_1c0 = param_5;
  local_150 = param_6;
  local_180 = param_7;
  local_190 = 0;
  local_1d0[0] = 0;
  local_198 = 0;
  local_1b0[0] = 0;
  local_1b8 = 0;
  local_158 = local_158 & 0xffffffffffff0000;
  local_120 = 0;
  local_118 = local_118 & 0xffffffff00000000;
  local_188 = 0;
  local_1c8 = 0;
  local_c8 = 0;
  local_e0 = 0;
  local_1a0 = 0;
  local_a0 = 0x701;
  local_98 = 0x1601;
  local_90 = 0xf01;
  local_88 = 3;
  local_84 = 0x9f;
  local_178 = 0;
  lStack_170 = 0;
  local_168 = 0;
  uStack_160 = 0;
  local_140 = 0;
  uStack_138 = 0;
  local_130 = (wchar_t *)0x0;
  uStack_128 = 0;
  local_110 = 0;
  uStack_108 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  local_100 = 0;
  uStack_f8 = 0;
  local_f0 = 0;
  uStack_e8 = 0;
  local_1d8 = param_2;
  local_1a8 = param_4;
  local_148 = param_1;
  if ((param_9 == 0) || (param_8 == 0)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar6 = 0x92;
      uVar8 = 0xd2;
LAB_14002ed72:
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,uVar6,
                         &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                         "onecore\\base\\fs\\wci\\wcifs\\utils.c",uVar8);
    }
  }
  else {
    if (param_9 == *(ushort *)(param_8 + 4) + 8) {
      uVar2 = FltGetInstanceContext(param_3,&local_1a0);
      if ((int)uVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002eda9;
        uVar8 = 0xf4;
        uVar6 = 0x94;
        goto LAB_14002e667;
      }
      if (((*(int *)(local_1a0 + 8) == 0xd) || (*(int *)(local_1a0 + 8) == 6)) &&
         (iVar3 = FltFsControlFile(param_3,local_1d8), iVar3 < 0)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,0xf,0x95,
                              &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                              "onecore\\base\\fs\\wci\\wcifs\\utils.c",10,(char)iVar3);
        }
        if ((5 < DAT_14000f060) &&
           (uVar4 = _tlgKeywordOn(0x14000f060,0x400000000000), (char)uVar4 != '\0')) {
          local_60 = local_1e0;
          local_58 = 4;
          local_1e0[0] = iVar3;
          _tlgWriteTransfer_EtwWriteTransfer(0x14000f060,&DAT_14000bd1f,0,0,3,local_80);
        }
      }
      uVar2 = FltQueryInformationFile(param_3,local_1d8,&local_d8,0x18);
      if ((int)uVar2 < 0) goto LAB_14002eda9;
      local_1e0[0] = 0x210028;
      if (local_c8._5_1_ != '\0') {
        local_1e0[0] = 0x210029;
      }
      uVar2 = WcQueryEa(param_3,local_1d8,&local_190,local_1d0);
      if ((int)uVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002eda9;
        uVar6 = 0x96;
        uVar8 = 0x28;
LAB_14002e667:
        uVar5 = 0xf;
      }
      else {
        if (((param_10 & 0x40) == 0) &&
           (uVar2 = WcQuerySecurity(param_3,local_1d8,(local_180 != 0) + 0x9e,&local_198,local_1b0),
           (int)uVar2 < 0)) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_14002eda9;
          uVar6 = 0x97;
          uVar8 = 0x39;
          goto LAB_14002e667;
        }
        uVar2 = FltAllocateExtraCreateParameterList(Globals,0,&local_1b8);
        if ((int)uVar2 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_14002eda9;
          uVar6 = 0x98;
          uVar8 = 0x47;
LAB_14002e8d4:
          uVar5 = 5;
        }
        else {
          uVar2 = FltAllocateExtraCreateParameterFromLookasideList
                            (Globals,&GUID_ECP_ATOMIC_CREATE,0x58);
          if ((int)uVar2 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_14002eda9;
            uVar6 = 0x99;
            uVar8 = 0x54;
            goto LAB_14002e8d4;
          }
          memset((void *)0x0,0,0x58);
          cVar1 = '\0';
          uVar7 = 8;
          uRam0000000000000000 = 0x58;
          uRam0000000000000002 = 2;
          uRam0000000000000004 = 0;
          uVar2 = RtlUShortAdd(*(ushort *)(param_8 + 4),8,(ushort *)0x6);
          if ((int)uVar2 < 0) goto LAB_14002eda9;
          lRam0000000000000008 = param_8;
          if (local_c8._5_1_ == cVar1) {
            uRam0000000000000010 = uStack_d0;
            uRam0000000000000018 = uStack_d0;
            uRam0000000000000002 = uVar7 | 7;
          }
          uVar7 = uRam0000000000000002 | 0x600;
          uVar2 = FltQueryInformationFile(param_3,local_1d8,&local_100,0x28);
          if ((int)uVar2 < 0) {
            uRam0000000000000002 = uVar7;
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_14002eda9;
            uVar6 = 0x9a;
            uVar8 = 0x8e;
          }
          else {
            uVar4 = local_e0 & 1;
            if ((local_e0 & 1) != 0) {
              local_e0 = local_e0 & 0xfffffffffffffffe;
            }
            puRam0000000000000020 = &local_c0;
            uStack_a8 = uStack_e8;
            local_c0 = local_100;
            uStack_b8 = uStack_f8;
            local_b0 = local_f0;
            uRam0000000000000002 = uRam0000000000000002 | 0x610;
            uVar2 = FltInsertExtraCreateParameter(Globals,local_1b8,0);
            if (-1 < (int)uVar2) {
              local_168 = 0;
              uStack_160 = 0;
              local_178 = 0x28;
              local_158 = 1;
              if (local_180 != 0) {
                local_158 = IoGetSilo(local_180);
              }
              lStack_170 = local_1b8;
              uStack_138 = local_150;
              local_130 = local_1a8;
              local_120 = local_198;
              local_140 = CONCAT44(local_140._4_4_,0x30);
              uStack_128 = CONCAT44(uStack_128._4_4_,0x240);
              local_118 = 0;
              uVar2 = FltCreateFileEx2(Globals,local_1c0,&local_188,&local_1c8);
              if ((int)uVar2 < 0) {
                if ((uVar2 == 0xc0000035) || (uVar2 == 0xc0000909)) {
                  uVar2 = 0;
                  goto LAB_14002eda9;
                }
                if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                goto LAB_14002eda9;
                uVar6 = 0x9c;
                uVar8 = 0xdf;
              }
              else {
                cVar1 = FltIsEcpAcknowledged(Globals,0);
                if (cVar1 != '\0') {
                  if (((local_e0 & 0x800) == 0) ||
                     (uVar2 = WcCopyFileCompression(local_1d8,param_3,local_1c8,local_1c0),
                     -1 < (int)uVar2)) {
                    uVar2 = WcCopyFileDataStreams
                                      (local_148,local_1d8,param_3,local_188,local_1c8,local_1c0,1);
                    if (-1 < (int)uVar2) {
                      if (uVar4 != 0) {
                        uVar2 = WcSetFileAttributes(local_1c8,local_1c0);
                      }
                      goto LAB_14002eda9;
                    }
                    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                    goto LAB_14002eda9;
                    uVar6 = 0x9f;
                    uVar8 = 0x14;
                  }
                  else {
                    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                    goto LAB_14002eda9;
                    uVar6 = 0x9e;
                    uVar8 = 3;
                  }
                  goto LAB_14002ea4a;
                }
                uVar2 = 0xc00000bb;
                if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                goto LAB_14002eda9;
                uVar6 = 0x9d;
                uVar2 = 0xc00000bb;
                uVar8 = 0xee;
              }
              WPP_RECORDER_SF_sDZd
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,uVar6,
                         &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                         "onecore\\base\\fs\\wci\\wcifs\\utils.c",uVar8,local_1a8,(char)uVar2);
              goto LAB_14002eda9;
            }
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_14002eda9;
            uVar6 = 0x9b;
            uVar8 = 0xa6;
          }
LAB_14002ea4a:
          uVar5 = 0xf;
        }
      }
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar5,uVar6,
                          &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                          "onecore\\base\\fs\\wci\\wcifs\\utils.c",uVar8,(char)uVar2);
      goto LAB_14002eda9;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar6 = 0x93;
      uVar8 = 0xd9;
      goto LAB_14002ed72;
    }
  }
  uVar2 = 0xc000000d;
LAB_14002eda9:
  if (local_1a0 != 0) {
    FltReleaseContext();
  }
  if (local_198 != 0) {
    ExFreePoolWithTag(local_198,0x73664357);
  }
  if (local_190 != 0) {
    ExFreePoolWithTag(local_190,0x65664357);
  }
  if (local_1b8 != 0) {
    FltFreeExtraCreateParameterList(Globals);
  }
  if (local_188 != 0) {
    FltClose();
  }
  if (local_1c8 != 0) {
    ObfDereferenceObject();
  }
  return uVar2;
}



===== WcQueryEa @ 14002ee68 =====

int WcQueryEa(undefined8 param_1,undefined8 param_2,longlong *param_3,undefined4 *param_4)

{
  int iVar1;
  longlong lVar2;
  uint uVar3;
  undefined8 in_stack_ffffffffffffff98;
  ulonglong uVar4;
  uint local_38;
  undefined4 local_34 [3];
  
  local_38 = 0;
  local_34[0] = 0;
  uVar4 = CONCAT44((int)((ulonglong)in_stack_ffffffffffffff98 >> 0x20),7);
  iVar1 = FltQueryInformationFile(param_1,param_2,&local_38,4,uVar4,0);
  if (iVar1 < 0) {
    if ((iVar1 != -0x3fffffb1) && (iVar1 != -0x3fffff45)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar1;
      }
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xf,0x6d,
                          &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                          "onecore\\base\\fs\\wci\\wcifs\\utils.c",0xb8,(char)iVar1);
      return iVar1;
    }
    iVar1 = 0;
  }
  else if (local_38 != 0) {
    uVar3 = local_38;
    if (local_38 < 0xc) {
      uVar3 = 0xc;
    }
    do {
      lVar2 = ExAllocatePool2(0x100,uVar3,0x65664357);
      if (lVar2 == 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xf,0x6e,
                              &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                              "onecore\\base\\fs\\wci\\wcifs\\utils.c",0xcd,(char)uVar3);
        }
        return -0x3fffffe9;
      }
      uVar4 = uVar4 & 0xffffffffffffff00;
      iVar1 = FltQueryEaFile(param_1,param_2,lVar2,uVar3,uVar4,0,0,0,1,local_34);
      if (iVar1 < 0) {
        ExFreePoolWithTag(lVar2,0x65664357);
        uVar3 = uVar3 + 0x800;
        lVar2 = 0;
      }
    } while ((iVar1 == -0x7ffffffb) || (iVar1 == -0x3fffffdd));
    if (-1 < iVar1) {
      *param_4 = local_34[0];
      *param_3 = lVar2;
      return iVar1;
    }
    if (((iVar1 == -0x3fffffb1) || (iVar1 == -0x3fffff45)) || (iVar1 == -0x3fffffae)) {
      iVar1 = 0;
      *param_3 = 0;
      *param_4 = 0;
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xf,0x6f,
                          &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                          "onecore\\base\\fs\\wci\\wcifs\\utils.c",0xf8,(char)iVar1);
    }
    if (lVar2 == 0) {
      return iVar1;
    }
    ExFreePoolWithTag(lVar2,0x65664357);
    return iVar1;
  }
  *param_3 = 0;
  *param_4 = 0;
  return iVar1;
}



===== WcCopyAsPlaceHolderHandler @ 14002f100 =====

ulonglong WcCopyAsPlaceHolderHandler(int *param_1,uint param_2)

{
  ushort *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint extraout_EAX;
  ulonglong uVar7;
  int *piVar8;
  ushort uVar9;
  ulonglong uVar10;
  int iVar11;
  ushort *puVar12;
  undefined2 uVar13;
  uint uVar14;
  int *piVar15;
  byte local_res8 [8];
  byte local_res10 [8];
  byte local_res18 [8];
  char local_res20 [8];
  undefined1 uVar16;
  undefined1 uVar17;
  byte local_d8 [8];
  longlong local_d0;
  undefined8 local_c8;
  longlong local_c0;
  undefined8 local_b8;
  longlong local_b0;
  longlong local_a8;
  longlong local_a0;
  longlong local_98;
  undefined8 local_90;
  int *piStack_88;
  undefined8 local_80;
  ushort *puStack_78;
  undefined8 local_70;
  ushort *puStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  
  uVar6 = param_1[1];
  local_a8 = 0;
  local_a0 = 0;
  local_50 = 0;
  local_c8 = 0;
  local_b8 = 0;
  piVar8 = (int *)0x0;
  local_d0 = 0;
  local_98 = 0;
  local_res8[0] = 0;
  local_d8[0] = 0;
  local_res10[0] = 0;
  local_res20[0] = '\0';
  local_res18[0] = 0;
  local_c0 = 0;
  local_b0 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_80 = 0;
  puStack_78 = (ushort *)0x0;
  local_70 = 0;
  puStack_68 = (ushort *)0x0;
  local_90 = 0;
  piStack_88 = (int *)0x0;
  if (param_2 < uVar6) {
    uVar10 = 0xc000000d;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000000d;
    }
    uVar17 = 0xd;
    uVar13 = 0x24;
    uVar16 = 0x5d;
LAB_14002f9aa:
    uVar6 = 0xe;
  }
  else {
    if (*param_1 != 0xa8) {
      uVar10 = 0xc000000d;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0xc000000d;
      }
      uVar17 = 0xd;
      uVar13 = 0x25;
      uVar16 = 100;
      goto LAB_14002f9aa;
    }
    if (uVar6 < 0xa4) {
      uVar10 = 0xc000000d;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0xc000000d;
      }
      uVar17 = 0xd;
      uVar13 = 0x26;
      uVar16 = 0x6a;
      goto LAB_14002f9aa;
    }
    uVar2 = param_1[0x1e];
    if (uVar2 < 0xa4) {
      uVar10 = 0xc000000d;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0xc000000d;
      }
      uVar17 = 0xd;
      uVar13 = 0x27;
      uVar16 = 0x70;
      goto LAB_14002f9aa;
    }
    uVar14 = param_1[0x21];
    if (uVar14 < 0xa4) {
      uVar10 = 0xc000000d;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0xc000000d;
      }
      uVar17 = 0xd;
      uVar13 = 0x28;
      uVar16 = 0x76;
      goto LAB_14002f9aa;
    }
    uVar3 = param_1[0x23];
    if (uVar3 < 0xa4) {
      uVar10 = 0xc000000d;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0xc000000d;
      }
      uVar17 = 0xd;
      uVar13 = 0x29;
      uVar16 = 0x7c;
      goto LAB_14002f9aa;
    }
    uVar4 = param_1[0x25];
    if (uVar4 < 0xa4) {
      uVar10 = 0xc000000d;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0xc000000d;
      }
      uVar17 = 0xd;
      uVar13 = 0x2a;
      uVar16 = 0x82;
      goto LAB_14002f9aa;
    }
    uVar5 = uVar2 + *(ushort *)(param_1 + 0x1f);
    if ((uVar5 < uVar2) || (uVar6 < uVar5)) {
      uVar10 = 0xc000000d;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0xc000000d;
      }
      uVar17 = 0xd;
      uVar13 = 0x2b;
      uVar16 = 0x89;
      goto LAB_14002f9aa;
    }
    if ((*(ushort *)(param_1 + 0x22) + uVar14 < uVar14) ||
       (uVar6 < *(ushort *)(param_1 + 0x22) + uVar14)) {
      uVar10 = 0xc000000d;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0xc000000d;
      }
      uVar17 = 0xd;
      uVar13 = 0x2c;
      uVar16 = 0x90;
      goto LAB_14002f9aa;
    }
    if ((*(ushort *)(param_1 + 0x24) + uVar3 < uVar3) ||
       (uVar6 < *(ushort *)(param_1 + 0x24) + uVar3)) {
      uVar10 = 0xc000000d;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0xc000000d;
      }
      uVar17 = 0xd;
      uVar13 = 0x2d;
      uVar16 = 0x97;
      goto LAB_14002f9aa;
    }
    if ((*(ushort *)(param_1 + 0x26) + uVar4 < uVar4) ||
       (uVar6 < *(ushort *)(param_1 + 0x26) + uVar4)) {
      uVar10 = 0xc000000d;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0xc000000d;
      }
      uVar17 = 0xd;
      uVar13 = 0x2e;
      uVar16 = 0x9e;
      goto LAB_14002f9aa;
    }
    uVar14 = param_1[0x28] + param_1[0x27];
    if ((uVar14 < (uint)param_1[0x27]) || (uVar6 < uVar14)) {
      uVar10 = 0xc000000d;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0xc000000d;
      }
      uVar17 = 0xd;
      uVar13 = 0x2f;
      uVar16 = 0xa5;
      goto LAB_14002f9aa;
    }
    uVar9 = *(ushort *)(param_1 + 0x1c);
    if (uVar9 < 0x65) {
      puVar1 = (ushort *)((longlong)param_1 + (ulonglong)uVar2);
      local_90 = (ulonglong)CONCAT22(uVar9,uVar9);
      piStack_88 = param_1 + 3;
      uVar7 = WcValidateContainerRootId(puVar1,(uint)*(ushort *)(param_1 + 0x1f));
      uVar10 = uVar7 & 0xffffffff;
      if ((int)uVar7 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002f9da;
        uVar17 = (undefined1)uVar7;
        uVar13 = 0x31;
        uVar16 = 0xb8;
      }
      else {
        puVar12 = (ushort *)((ulonglong)(uint)param_1[0x21] + (longlong)param_1);
        uVar7 = WcValidateContainerRootId(puVar12,(uint)*(ushort *)(param_1 + 0x22));
        uVar10 = uVar7 & 0xffffffff;
        if (-1 < (int)uVar7) {
          uVar9 = puVar1[2] + (short)param_1[0x24];
          if ((uVar9 < puVar1[2]) || (uVar9 = uVar9 + 2, uVar9 < 2)) {
            local_c8._0_4_ = CONCAT22(0xffff,(ushort)local_c8);
LAB_14002f8a6:
            uVar10 = 0xc0000095;
          }
          else {
            local_c8 = (ulonglong)CONCAT42(local_c8._4_4_,uVar9) << 0x10;
            local_c0 = ExAllocatePool2(0x100,uVar9,0x746d4357);
            if (local_c0 != 0) {
              uVar9 = puVar12[2] + (short)param_1[0x26];
              if ((uVar9 < puVar12[2]) || (uVar9 = uVar9 + 2, uVar9 < 2)) {
                local_b8._0_4_ = CONCAT22(0xffff,(wchar_t)local_b8);
                goto LAB_14002f8a6;
              }
              local_b8 = (ulonglong)CONCAT42(local_b8._4_4_,uVar9) << 0x10;
              local_b0 = ExAllocatePool2(0x100,uVar9,0x746d4357);
              if (local_b0 != 0) {
                uVar6 = WcRelPathToFullPath((ushort *)&local_c8,puVar1[2],puVar1 + 3,
                                            (void *)((ulonglong)(uint)param_1[0x23] +
                                                    (longlong)param_1),*(ushort *)(param_1 + 0x24));
                uVar10 = (ulonglong)uVar6;
                if ((int)uVar6 < 0) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                  goto LAB_14002f9da;
                  uVar17 = (undefined1)uVar6;
                  uVar13 = 0x33;
                  uVar16 = 0xf8;
                }
                else {
                  uVar6 = WcRelPathToFullPath((ushort *)&local_b8,puVar12[2],puVar12 + 3,
                                              (void *)((ulonglong)(uint)param_1[0x25] +
                                                      (longlong)param_1),*(ushort *)(param_1 + 0x26)
                                             );
                  uVar10 = (ulonglong)uVar6;
                  if ((int)uVar6 < 0) {
                    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                    goto LAB_14002f9da;
                    uVar17 = (undefined1)uVar6;
                    uVar13 = 0x34;
                    uVar16 = 3;
                  }
                  else {
                    local_80._0_4_ = CONCAT22(puVar1[1],puVar1[1]);
                    local_70._0_4_ = CONCAT22(puVar12[1],puVar12[1]);
                    puStack_78 = puVar1 + 3;
                    puStack_68 = puVar12 + 3;
                    uVar6 = WcGetInstanceFromVolumeName(&local_80,&local_90,&local_d0);
                    uVar10 = (ulonglong)uVar6;
                    if ((int)uVar6 < 0) {
                      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                      goto LAB_14002f9da;
                      uVar17 = (undefined1)uVar6;
                      uVar13 = 0x35;
                      uVar16 = 0x14;
                    }
                    else {
                      uVar6 = WcGetInstanceFromVolumeName(&local_70,&local_90,&local_98);
                      uVar10 = (ulonglong)uVar6;
                      if ((int)uVar6 < 0) {
                        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                        goto LAB_14002f9da;
                        uVar17 = (undefined1)uVar6;
                        uVar13 = 0x36;
                        uVar16 = 0x1d;
                      }
                      else {
                        WcOpenAsReparsePoint
                                  (&local_c8,0,0,local_d0,0x80020000,param_1[0x1d],&local_a8,
                                   &local_a0,local_d8,local_res8,local_res10,local_res20,local_res18
                                  );
                        uVar10 = (ulonglong)extraout_EAX;
                        if ((int)extraout_EAX < 0) {
                          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                          goto LAB_14002f9da;
                          uVar17 = (undefined1)extraout_EAX;
                          uVar13 = 0x37;
                          uVar16 = 0x30;
                        }
                        else if (((local_res8[0] == 0) && (local_res10[0] == 0)) &&
                                (local_res18[0] == 0)) {
                          if (local_res20[0] == '\0') {
                            uVar6 = param_1[0x27];
                            iVar11 = *(ushort *)
                                      ((longlong)((ulonglong)uVar6 + (longlong)param_1) + 0x18) +
                                     0x22;
                            piVar8 = (int *)ExAllocatePool2(0x100,iVar11,0x746d4357);
                            if (piVar8 == (int *)0x0) {
                              uVar10 = 0xc000009a;
                              if ((undefined **)WPP_RECORDER_INITIALIZED ==
                                  &WPP_RECORDER_INITIALIZED) goto LAB_14002f9da;
                              uVar17 = 0x9a;
                              uVar13 = 0x39;
                              uVar16 = 0x55;
                              goto LAB_14002f9aa;
                            }
                            memmove(piVar8 + 2,(void *)((ulonglong)uVar6 + (longlong)param_1),
                                    (ulonglong)(uint)param_1[0x28]);
                            *piVar8 = param_1[0x20];
                            uVar6 = RtlUShortAdd(0x1a,(short)piVar8[8],(ushort *)(piVar8 + 1));
                            uVar10 = (ulonglong)uVar6;
                            piVar15 = piVar8;
                            if ((int)uVar6 < 0) goto LAB_14002f9da;
                          }
                          else {
                            local_60 = CONCAT26(local_60._6_2_,0x80000020);
                            iVar11 = 8;
                            piVar15 = (int *)&local_60;
                          }
                          uVar6 = WcCopyAsPlaceHolder(local_a8,local_a0,local_d0,
                                                      (wchar_t *)&local_b8,local_98,0,0,
                                                      (longlong)piVar15,iVar11,
                                                      (byte)((param_1[2] & 1U) << 6));
                          uVar10 = (ulonglong)uVar6;
                          if ((-1 < (int)uVar6) ||
                             ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED))
                          goto LAB_14002f9da;
                          uVar17 = (undefined1)uVar6;
                          uVar13 = 0x3a;
                          uVar16 = 0x7c;
                        }
                        else {
                          uVar10 = 0xc000000d;
                          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                          goto LAB_14002f9da;
                          uVar17 = 0xd;
                          uVar13 = 0x38;
                          uVar16 = 0x36;
                        }
                      }
                    }
                  }
                }
                goto LAB_14002f9aa;
              }
            }
            uVar10 = 0xc000009a;
          }
          goto LAB_14002f9da;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002f9da;
        uVar17 = (undefined1)uVar7;
        uVar13 = 0x32;
        uVar16 = 0xc1;
      }
      goto LAB_14002f9aa;
    }
    uVar10 = 0xc000000d;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000000d;
    }
    uVar13 = 0x30;
    uVar17 = 0xd;
    uVar16 = 0xab;
    uVar6 = 0xb;
  }
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar6,uVar13,
                      &WPP_52759b377eea39e2466a1234853e56fe_Traceguids,
                      "onecore\\base\\fs\\wci\\wcifs\\message.c",uVar16,uVar17);
LAB_14002f9da:
  if (local_a8 != 0) {
    FltClose();
  }
  if (local_a0 != 0) {
    ObfDereferenceObject();
  }
  if (local_d0 != 0) {
    FltObjectDereference();
  }
  if (local_98 != 0) {
    FltObjectDereference();
  }
  if (piVar8 != (int *)0x0) {
    ExFreePoolWithTag(piVar8,0x746d4357);
  }
  if (local_c0 != 0) {
    ExFreePoolWithTag(local_c0,0x746d4357);
  }
  if (local_b0 != 0) {
    ExFreePoolWithTag(local_b0,0x746d4357);
  }
  return uVar10;
}



===== WcPopulateFile @ 14002fa9c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong WcPopulateFile(wchar_t *param_1,longlong *param_2,undefined4 *param_3,longlong param_4,
                        longlong param_5,longlong param_6,char param_7,char param_8)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  undefined8 *puVar3;
  bool bVar4;
  longlong *plVar5;
  int iVar6;
  uint uVar7;
  uint extraout_EAX;
  uint uVar8;
  longlong lVar9;
  ulonglong uVar10;
  undefined8 *puVar11;
  longlong *plVar12;
  longlong lVar13;
  undefined8 uVar14;
  byte bVar15;
  ulonglong uVar16;
  ulonglong uVar17;
  ushort *puVar18;
  undefined2 uVar19;
  ushort *puVar20;
  undefined1 auStackY_1a8 [32];
  undefined1 uVar21;
  undefined1 uVar22;
  byte local_137;
  byte local_136;
  byte local_135;
  char local_134;
  byte local_133;
  char local_132;
  uint local_130 [2];
  longlong local_128;
  undefined4 local_120;
  uint local_11c;
  longlong local_118;
  longlong local_110;
  undefined8 local_108;
  longlong local_100;
  undefined8 local_f8;
  longlong local_f0;
  longlong local_e8;
  longlong local_e0;
  longlong local_d8;
  longlong local_d0;
  longlong local_c8;
  longlong *local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80 [4];
  undefined8 *local_60;
  undefined8 local_58;
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStackY_1a8;
  local_d8 = param_5;
  local_108 = 0;
  local_110 = 0;
  puVar11 = (undefined8 *)0x0;
  local_128 = 0;
  plVar12 = (longlong *)0x0;
  local_f8 = (undefined8 *)0x0;
  local_132 = '\0';
  local_130[0] = 0;
  local_133 = 0;
  local_135 = 0;
  local_136 = 0;
  local_134 = '\0';
  local_137 = 0;
  local_e8 = 0;
  local_11c = 0;
  local_118 = 0;
  local_c8 = 0;
  local_120 = 0;
  local_98 = 0;
  local_e0 = param_6;
  local_b8 = 0;
  uStack_b0 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_d0 = param_4;
  local_c0 = param_2;
  RtlInitUnicodeString(&local_b8,0);
  WcGetContextFileObject(param_4,param_6,&local_c8,&local_118);
  iVar6 = FltQueryDirectoryFile(param_4,param_6,&local_90,0x10);
  lVar9 = local_118;
  if (((iVar6 + 0x80000000U & 0x80000000) != 0) || (iVar6 == -0x7ffffffb)) {
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_sDZ(_WcVerboseRecorder,5,10,0x1a,
                          &WPP_258dc4bb20423ae59ba1107eb987efad_Traceguids,
                          "onecore\\base\\fs\\wci\\wcifs\\expansion.c",0x28,param_1);
    }
LAB_14003052b:
    bVar4 = false;
    uVar16 = 0;
    goto LAB_14003052d;
  }
  lVar13 = local_118 + 0xe8;
  KeWaitForSingleObject(lVar13,0,0,0);
  bVar4 = true;
  if ((*(longlong *)(lVar9 + 0x100) == 0) || (*(int *)(*(longlong *)(lVar9 + 0x100) + 0x14) == 0)) {
LAB_14002fce5:
    KeSetEvent(lVar13,0,0);
    bVar4 = false;
    uVar10 = WcLocateSourceDirectory(param_1,param_2,&local_108);
    uVar17 = local_108;
    uVar16 = uVar10 & 0xffffffff;
    if ((int)uVar10 < 0) goto LAB_14003052d;
    puVar3 = *(undefined8 **)(local_108 + 0x18);
    WcOpenAsReparsePoint
              (param_1,puVar3[1],puVar3[2],*puVar3,0x120088,**(int **)(local_c8 + 0x40),&local_110,
               &local_128,&local_133,&local_135,&local_136,&local_134,&local_137);
    uVar16 = (ulonglong)extraout_EAX;
    if ((int)extraout_EAX < 0) goto LAB_14003052d;
    if (param_8 != '\0') {
      uVar16 = 0xc0000034;
      if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
         (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) goto LAB_14003052d;
      uVar22 = 0x34;
      uVar19 = 0x1c;
      uVar21 = 0x94;
      goto LAB_14002fcb4;
    }
    if (local_137 != 0) {
LAB_14002fdec:
      uVar16 = 0xc0000034;
      goto LAB_14003052d;
    }
    if (param_7 != '\0') {
      uVar7 = FltGetFileNameInformationUnsafe
                        (local_128,**(undefined8 **)(uVar17 + 0x18),0x101,&local_e8);
      uVar16 = (ulonglong)uVar7;
      if ((int)uVar7 < 0) goto LAB_14003052d;
      uVar7 = FltParseFileNameInformation(local_e8);
      uVar16 = (ulonglong)uVar7;
      if ((int)uVar7 < 0) goto LAB_14003052d;
      pwVar1 = (wchar_t *)(local_e8 + 0x58);
      if (*(short *)(local_e8 + 0x48) != 0) {
        *pwVar1 = *pwVar1 - *(short *)(local_e8 + 0x48);
      }
      wVar2 = *param_1;
      param_1 = pwVar1;
      if (((ushort)wVar2 < 0x19) && (iVar6 = RtlCompareUnicodeString(), iVar6 != 0)) {
        RtlHashUnicodeString(pwVar1,1);
        if ((5 < DAT_14000f060) &&
           (uVar16 = _tlgKeywordOn(0x14000f060,0x400000000000), (char)uVar16 != '\0')) {
          local_108 = (ulonglong)local_11c;
          local_60 = &local_108;
          local_58 = 8;
          _tlgWriteTransfer_EtwWriteTransfer(0x14000f060,&DAT_14000b591,0,0,3,local_80);
        }
        goto LAB_14002fdec;
      }
    }
    local_c0 = (longlong *)*local_c0;
    if ((local_136 == 0) && (local_135 == 0)) {
      if (local_134 == '\0') {
        if (local_133 == 0) {
          local_108 = local_108 & 0xffffffff;
          local_f8 = (undefined8 *)((ulonglong)local_f8 & 0xffffffff);
          local_130[0] = (uint)(-(ushort)(*(ushort *)(param_3 + 8) != 0) & 2);
          uVar7 = *(ushort *)(param_3 + 8) + 0x22 + (ushort)*param_1 + local_130[0];
          puVar11 = (undefined8 *)ExAllocatePool2(0x100,uVar7,0x69724357);
          uVar19 = 0;
          if (puVar11 == (undefined8 *)0x0) {
            uVar16 = 0xc000009a;
            goto LAB_14003052d;
          }
          puVar11[1] = 1;
          puVar18 = (ushort *)(puVar11 + 4);
          puVar3 = *(undefined8 **)(*(longlong *)(uVar17 + 0x18) + 0x20);
          uVar14 = puVar3[1];
          puVar11[2] = *puVar3;
          puVar11[3] = uVar14;
          puVar20 = puVar18;
          uVar8 = RtlUShortAdd(*param_1,*(short *)(param_3 + 8),puVar18);
          uVar16 = (ulonglong)uVar8;
          if ((int)uVar8 < 0) goto LAB_14003052d;
          uVar8 = RtlUShortAdd(*puVar20,(short)local_130[0],puVar18);
          uVar16 = (ulonglong)uVar8;
          if ((int)uVar8 < 0) goto LAB_14003052d;
          *(undefined4 *)puVar11 = *param_3;
          uVar8 = RtlUShortAdd(0x1a,*puVar20,(ushort *)((longlong)puVar11 + 4));
          uVar16 = (ulonglong)uVar8;
          if ((int)uVar8 < 0) goto LAB_14003052d;
          local_100 = (longlong)puVar11 + 0x22;
          local_108 = CONCAT62(CONCAT42(local_108._4_4_,*puVar20),uVar19);
          local_f8 = (undefined8 *)
                     CONCAT62(CONCAT42(local_f8._4_4_,*(undefined2 *)(param_3 + 8)),
                              *(undefined2 *)(param_3 + 8));
          local_f0 = (longlong)param_3 + 0x22;
          RtlCopyUnicodeString(&local_108,&local_f8);
          if (*(short *)(param_3 + 8) != 0) {
            uVar8 = RtlAppendUnicodeToString(&local_108,L"\\");
            uVar16 = (ulonglong)uVar8;
            if ((int)uVar8 < 0) goto LAB_14003052d;
          }
          uVar8 = RtlAppendUnicodeStringToString(&local_108,param_1);
          uVar16 = (ulonglong)uVar8;
          if ((int)uVar8 < 0) goto LAB_14003052d;
          goto LAB_1400301e3;
        }
        uVar8 = WcGetReparseData(**(undefined8 **)(uVar17 + 0x18),local_128,0x200,&local_f8,
                                 local_130);
        puVar11 = local_f8;
        uVar7 = local_130[0];
        uVar16 = (ulonglong)uVar8;
        if ((int)uVar8 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xf,0x1e,
                                &WPP_258dc4bb20423ae59ba1107eb987efad_Traceguids,
                                "onecore\\base\\fs\\wci\\wcifs\\expansion.c",0x32,(char)uVar8);
          }
          puVar11 = local_f8;
          goto LAB_14003052d;
        }
        uVar8 = WcValidateWcReparseInfo((longlong)local_f8,local_130[0]);
        uVar16 = (ulonglong)uVar8;
        if (-1 < (int)uVar8) {
          lVar9 = puVar11[2];
          if (lVar9 == 0) {
            lVar9 = puVar11[3];
          }
          if (lVar9 == 0) {
            puVar3 = *(undefined8 **)(*(longlong *)(uVar17 + 0x18) + 0x20);
            uVar14 = puVar3[1];
            puVar11[2] = *puVar3;
            puVar11[3] = uVar14;
          }
          *(uint *)((longlong)puVar11 + 0xc) = *(uint *)((longlong)puVar11 + 0xc) & 0xfffffff1;
          goto LAB_1400301e3;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14003052d;
        uVar19 = 0x1f;
        uVar21 = 0x39;
      }
      else {
        local_a8 = CONCAT26(local_a8._6_2_,0x80000020);
        uVar7 = 8;
        local_132 = '\x01';
        puVar11 = &local_a8;
LAB_1400301e3:
        plVar5 = local_c0;
        uVar8 = *(uint *)(*(longlong *)(local_c0[3] + 0x20) + 0x10);
        if ((uVar8 & 0x20) == 0) {
          uVar7 = WcCopyAsPlaceHolder(local_110,local_128,**(undefined8 **)(uVar17 + 0x18),param_1,
                                      local_d0,local_d8,local_e0,(longlong)puVar11,uVar7,(byte)uVar8
                                     );
          uVar16 = (ulonglong)uVar7;
          if ((-1 < (int)uVar7) ||
             ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED))
          goto LAB_14003052d;
          uVar19 = 0x24;
          uVar21 = 0xe6;
LAB_1400303a0:
          uVar17 = 0xf;
          goto LAB_1400304bd;
        }
        plVar12 = (longlong *)ExAllocateFromNPagedLookasideList(&DAT_14000f600);
        lVar9 = local_d0;
        if (plVar12 == (longlong *)0x0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_14003052d;
          uVar8 = (uint)uVar16;
          uVar19 = 0x20;
          uVar21 = 0xa3;
        }
        else {
          *plVar12 = local_110;
          plVar12[1] = local_128;
          lVar13 = **(longlong **)(uVar17 + 0x18);
          plVar12[5] = local_d8;
          plVar12[2] = lVar13;
          plVar12[6] = local_e0;
          plVar12[3] = (longlong)param_1;
          plVar12[4] = local_d0;
          plVar12[7] = (longlong)puVar11;
          *(uint *)(plVar12 + 8) = uVar7;
          *(undefined4 *)(plVar12 + 0xc) = 0;
          *(undefined4 *)((longlong)plVar12 + 100) =
               *(undefined4 *)(*(longlong *)(plVar5[3] + 0x20) + 0x10);
          KeInitializeEvent(plVar12 + 9,0,0);
          lVar13 = FltAllocateGenericWorkItem();
          if (lVar13 == 0) {
            uVar16 = 0xc000009a;
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_14003052d;
            uVar8 = 0xc000009a;
            uVar19 = 0x21;
            uVar21 = 0xba;
          }
          else {
            uVar8 = FltQueueGenericWorkItem(lVar13,lVar9,WcCopyAsPlaceHolderWorker,0);
            uVar16 = (ulonglong)uVar8;
            if (-1 < (int)uVar8) {
              KeWaitForSingleObject(plVar12 + 9,0,0,0);
              uVar7 = *(uint *)(plVar12 + 0xc);
              uVar16 = (ulonglong)uVar7;
              if ((-1 < (int)uVar7) ||
                 ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED))
              goto LAB_14003052d;
              uVar19 = 0x23;
              uVar21 = 0xd4;
              goto LAB_1400303a0;
            }
            FltFreeGenericWorkItem(lVar13);
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_14003052d;
            uVar19 = 0x22;
            uVar21 = 199;
          }
        }
      }
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xf,uVar19,
                          &WPP_258dc4bb20423ae59ba1107eb987efad_Traceguids,
                          "onecore\\base\\fs\\wci\\wcifs\\expansion.c",uVar21,(char)uVar8);
      goto LAB_14003052d;
    }
    uVar7 = WcCopyFile(local_110,local_128,**(undefined8 **)(uVar17 + 0x18),param_1,local_d0,
                       local_d8,local_e0,'\0',
                       (byte)*(undefined4 *)(*(longlong *)(local_c0[3] + 0x20) + 0x10));
    uVar16 = (ulonglong)uVar7;
    if (-1 < (int)uVar7) goto LAB_14003052d;
    if ((uVar7 == 0xc0000035) || (uVar7 == 0xc0000909)) goto LAB_14003052b;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14003052d;
    uVar19 = 0x1d;
    uVar21 = 0x13;
    uVar17 = 10;
LAB_1400304bd:
    uVar22 = (undefined1)uVar7;
    bVar15 = 2;
    uVar14 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
  }
  else {
    uVar7 = RtlDowncaseUnicodeString(&local_b8,param_1,1);
    uVar16 = (ulonglong)uVar7;
    if ((int)uVar7 < 0) goto LAB_14003052d;
    uVar7 = RtlHashUnicodeString(&local_b8,1,0,&local_120);
    uVar16 = (ulonglong)uVar7;
    if ((int)uVar7 < 0) goto LAB_14003052d;
    lVar9 = RtlLookupEntryHashTable(*(undefined8 *)(local_118 + 0x100),local_120,0);
    if (lVar9 == 0) goto LAB_14002fce5;
    uVar16 = 0xc000022d;
    if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
       (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) goto LAB_14003052d;
    uVar22 = 0x2d;
    uVar19 = 0x1b;
    uVar21 = 0x62;
LAB_14002fcb4:
    uVar17 = 10;
    bVar15 = 5;
    uVar14 = _WcVerboseRecorder;
  }
  WPP_RECORDER_SF_sDZd
            (uVar14,bVar15,uVar17,uVar19,&WPP_258dc4bb20423ae59ba1107eb987efad_Traceguids,
             "onecore\\base\\fs\\wci\\wcifs\\expansion.c",uVar21,param_1,uVar22);
LAB_14003052d:
  RtlFreeUnicodeString(&local_b8);
  lVar9 = local_118;
  if (bVar4) {
    KeSetEvent(local_118 + 0xe8,0,0);
  }
  if ((puVar11 != (undefined8 *)0x0) && (local_132 == '\0')) {
    ExFreePoolWithTag(puVar11,0x69724357);
  }
  if (local_e8 != 0) {
    FltReleaseFileNameInformation();
  }
  if (local_110 != 0) {
    FltClose();
  }
  if (local_128 != 0) {
    ObfDereferenceObject();
  }
  if (local_c8 != 0) {
    FltReleaseContext(local_c8);
  }
  if (lVar9 != 0) {
    FltReleaseContext(lVar9);
  }
  if (plVar12 != (longlong *)0x0) {
    ExFreeToNPagedLookasideList(&DAT_14000f600,plVar12);
  }
  return uVar16;
}



===== WcLocateSourceDirectory @ 140030634 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 WcLocateSourceDirectory(undefined8 param_1,undefined8 *param_2,undefined8 *param_3)

{
  int iVar1;
  undefined8 uVar2;
  longlong *plVar3;
  undefined1 auStack_98 [32];
  undefined4 local_78;
  undefined1 local_70;
  undefined8 local_68;
  undefined1 local_60;
  undefined8 local_58;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_98;
  plVar3 = (longlong *)*param_2;
  local_48 = 0;
  uStack_40 = 0;
  do {
    if (plVar3 == param_2) {
LAB_14003067d:
      uVar2 = 0xc0000034;
      if (plVar3 != param_2) {
        uVar2 = 0;
      }
      return uVar2;
    }
    if ((undefined8 *)*plVar3 == param_2) {
LAB_14003067a:
      *param_3 = plVar3;
      goto LAB_14003067d;
    }
    local_58 = 0;
    local_60 = 1;
    local_70 = 1;
    local_78 = 0xc;
    local_68 = param_1;
    iVar1 = FltQueryDirectoryFile
                      (*(undefined8 *)plVar3[3],((undefined8 *)plVar3[3])[2],&local_48,0x10);
    if (((iVar1 + 0x80000000U & 0x80000000) != 0) || (iVar1 == -0x7ffffffb)) goto LAB_14003067a;
    plVar3 = (longlong *)*plVar3;
  } while( true );
}



===== WcOpenAsReparsePoint @ 140030708 =====

int WcOpenAsReparsePoint
              (undefined8 param_1,undefined8 param_2,longlong param_3,undefined8 param_4,
              undefined4 param_5,int param_6,longlong *param_7,longlong *param_8,byte *param_9,
              byte *param_10,byte *param_11,undefined1 *param_12,byte *param_13)

{
  undefined8 uVar1;
  code *pcVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  undefined8 ****ppppuVar6;
  undefined8 ****ppppuVar7;
  undefined8 ****ppppuVar8;
  undefined8 ****ppppuVar9;
  undefined1 uVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined2 uVar13;
  byte *pbVar14;
  bool bVar15;
  bool bVar16;
  bool bVar17;
  undefined1 auStackY_178 [8];
  undefined1 auStackY_170 [24];
  bool local_f4;
  longlong local_f0;
  undefined8 ****local_e8;
  undefined8 ****ppppuStack_e0;
  longlong local_d8;
  longlong local_d0;
  longlong local_c8;
  undefined8 local_c0;
  longlong local_b8 [6];
  undefined4 local_88;
  undefined4 uStack_84;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined8 local_68;
  ulonglong uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  
  local_b8[0] = 0;
  local_d8 = 0;
  ppppuVar6 = (undefined8 ****)0x0;
  ppppuVar7 = (undefined8 ****)0x0;
  ppppuVar8 = (undefined8 ****)0x0;
  ppppuVar9 = (undefined8 ****)0x0;
  local_68 = 0;
  local_e8 = (undefined8 ****)0x0;
  ppppuStack_e0 = (undefined8 ****)0x0;
  uStack_60 = uStack_60 & 0xffffffff00000000;
  local_88 = 0;
  uStack_84 = 0;
  uStack_80 = 0;
  local_f0 = 0;
  local_78 = 0;
  uStack_70 = 0;
  uStack_6c = 0;
  local_d0 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_c8 = 0;
  local_c0 = 0;
  local_f4 = false;
  local_b8[1] = 0;
  local_b8[2] = 0;
  local_b8[5] = local_b8[5] & 0xffffffffffff0000;
  local_b8[3] = 0;
  local_b8[4] = 0;
  puVar12 = auStackY_178;
  if ((param_8 == (longlong *)0x0) || (puVar12 = auStackY_178, param_7 == (longlong *)0x0))
  goto LAB_14003122a;
  FltGetInstanceContext(param_4,local_b8);
  if ((*(int *)(local_b8[0] + 8) == 2) || (*(int *)(local_b8[0] + 8) == 0x1c)) {
    pbVar14 = (byte *)0x80000004;
    ppppuStack_e0 = &local_e8;
    local_e8 = &local_e8;
    if (param_9 == (byte *)0x0) {
LAB_140030cc2:
      if (param_10 != (byte *)0x0) {
        ppppuVar7 = (undefined8 ****)ExAllocateFromPagedLookasideList(&DAT_14000f380);
        if (ppppuVar7 == (undefined8 ****)0x0) {
          puVar12 = auStackY_178;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_14003114c;
          uVar13 = 0x86;
          uVar10 = 0xee;
          goto LAB_140030c48;
        }
        ppppuVar7[1] = ppppuVar7;
        *ppppuVar7 = ppppuVar7;
        ppppuVar7[3] = (undefined8 ***)0x0;
        ppppuVar7[4] = (undefined8 ***)0x0;
        *(undefined4 *)(ppppuVar7 + 2) = 0xa000000c;
        *(undefined4 *)((longlong)ppppuVar7 + 0x14) = 0x80000004;
        *(undefined4 *)(ppppuVar7 + 5) = 0x30;
        if ((undefined8 *****)*ppppuStack_e0 != &local_e8) goto LAB_140030e8c;
        ppppuVar7[1] = ppppuStack_e0;
        *ppppuVar7 = &local_e8;
        *ppppuStack_e0 = ppppuVar7;
        ppppuStack_e0 = ppppuVar7;
      }
      if (param_11 != (byte *)0x0) {
        ppppuVar8 = (undefined8 ****)ExAllocateFromPagedLookasideList(&DAT_14000f380);
        if (ppppuVar8 == (undefined8 ****)0x0) {
          puVar12 = auStackY_178;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_14003114c;
          uVar13 = 0x87;
          uVar10 = 0xfd;
          goto LAB_140030c48;
        }
        ppppuVar8[1] = ppppuVar8;
        *ppppuVar8 = ppppuVar8;
        ppppuVar8[3] = (undefined8 ***)0x0;
        ppppuVar8[4] = (undefined8 ***)0x0;
        *(undefined4 *)(ppppuVar8 + 2) = 0xa0000003;
        *(undefined4 *)((longlong)ppppuVar8 + 0x14) = 0x80000004;
        *(undefined4 *)(ppppuVar8 + 5) = 0x30;
        if ((undefined8 *****)*ppppuStack_e0 != &local_e8) goto LAB_140030e8c;
        ppppuVar8[1] = ppppuStack_e0;
        *ppppuVar8 = &local_e8;
        *ppppuStack_e0 = ppppuVar8;
        ppppuStack_e0 = ppppuVar8;
      }
      puVar11 = auStackY_178;
      if (param_13 == (byte *)0x0) {
LAB_140030ea7:
        *(longlong **)(puVar11 + 0x48) = param_8;
        *(longlong **)(puVar11 + 0x40) = param_7;
        *(undefined8 ******)(puVar11 + 0x38) = &local_e8;
        *(undefined4 *)(puVar11 + 0x30) = 3;
        *(undefined4 *)(puVar11 + 0x28) = 0x28;
        *(undefined4 *)(puVar11 + 0x20) = param_5;
        *(undefined8 *)(puVar11 + -8) = 0x140030eff;
        iVar5 = WcOpenReparsePoint(param_4,param_1,param_2,param_3,*(undefined4 *)(puVar11 + 0x20),
                                   *(undefined4 *)(puVar11 + 0x28),*(undefined4 *)(puVar11 + 0x30),
                                   *(longlong **)(puVar11 + 0x38),*(undefined8 *)(puVar11 + 0x40),
                                   *(undefined8 *)(puVar11 + 0x48));
        puVar12 = puVar11;
        if (iVar5 == -0x3ffffd87) {
          local_b8[5] = 1;
          local_b8[2] = 0;
          local_b8[1] = 0x28;
          local_b8[3] = 0;
          local_b8[4] = 0;
          if (param_3 != 0) {
            *(undefined8 *)(puVar11 + -8) = 0x140030f3c;
            local_b8[5] = IoGetSilo();
          }
          uStack_70 = 0x240;
          local_88 = 0x30;
          *(longlong **)(puVar11 + 0x78) = local_b8 + 1;
          *(undefined4 *)(puVar11 + 0x70) = 0x800;
          *(undefined4 *)(puVar11 + 0x68) = 0;
          *(undefined8 *)(puVar11 + 0x60) = 0;
          *(undefined4 *)(puVar11 + 0x58) = 0x200028;
          *(undefined4 *)(puVar11 + 0x50) = 1;
          *(undefined4 *)(puVar11 + 0x48) = 3;
          *(undefined4 *)(puVar11 + 0x40) = 0;
          *(undefined8 *)(puVar11 + 0x38) = 0;
          *(undefined8 **)(puVar11 + 0x30) = &local_58;
          *(undefined4 **)(puVar11 + 0x28) = &local_88;
          *(undefined4 *)(puVar11 + 0x20) = param_5;
          local_68 = 0;
          uStack_60 = 0;
          *(undefined8 *)(puVar11 + -8) = 0x140030fe2;
          uStack_80 = param_2;
          local_78 = param_1;
          iVar5 = FltCreateFileEx2(Globals,param_4,&local_d8,&local_f0);
          lVar4 = local_d8;
          lVar3 = local_f0;
          if (-1 < iVar5) {
            uVar10 = 1;
            local_d8 = 0;
            *param_7 = lVar4;
            local_f0 = 0;
            *param_8 = lVar3;
            goto LAB_1400310ef;
          }
          if (((iVar5 != -0x3fffffcc) && (iVar5 != -0x3fffffc6)) &&
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            uVar13 = 0x89;
            *(int *)(puVar11 + 0x40) = iVar5;
            *(undefined8 *)(puVar11 + 0x38) = param_1;
            *(undefined4 *)(puVar11 + 0x30) = 0x135a;
            goto LAB_140031038;
          }
        }
        else if (iVar5 < 0) {
          if (((iVar5 != -0x3fffffcc) && (iVar5 != -0x3fffffc6)) &&
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            uVar13 = 0x8a;
            *(int *)(puVar11 + 0x40) = iVar5;
            *(undefined8 *)(puVar11 + 0x38) = param_1;
            *(undefined4 *)(puVar11 + 0x30) = 0x136f;
LAB_140031038:
            *(char **)(puVar11 + 0x28) = "onecore\\base\\fs\\wci\\wcifs\\utils.c";
            *(undefined **)(puVar11 + 0x20) = &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids;
            uVar1 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
            *(undefined8 *)(puVar11 + -8) = 0x140031068;
            WPP_RECORDER_SF_sDZd
                      (uVar1,2,10,uVar13,*(undefined8 *)(puVar11 + 0x20),*(char **)(puVar11 + 0x28),
                       puVar11[0x30],*(wchar_t **)(puVar11 + 0x38),puVar11[0x40]);
            puVar12 = puVar11;
          }
        }
        else {
          uVar10 = 0;
LAB_1400310ef:
          if (param_9 != (byte *)0x0) {
            *param_9 = *(byte *)((longlong)ppppuVar6 + 0x14) & 1;
          }
          if (param_10 != (byte *)0x0) {
            *param_10 = *(byte *)((longlong)ppppuVar7 + 0x14) & 1;
          }
          if (param_11 != (byte *)0x0) {
            *param_11 = *(byte *)((longlong)ppppuVar8 + 0x14) & 1;
          }
          if (param_12 != (undefined1 *)0x0) {
            *param_12 = uVar10;
          }
          if (param_13 != (byte *)0x0) {
            *param_13 = *(byte *)((longlong)ppppuVar9 + 0x14) & 1;
          }
        }
        goto LAB_14003114c;
      }
      ppppuVar9 = (undefined8 ****)ExAllocateFromPagedLookasideList(&DAT_14000f380);
      puVar11 = auStackY_178;
      if (ppppuVar9 != (undefined8 ****)0x0) {
        ppppuVar9[1] = ppppuVar9;
        *ppppuVar9 = ppppuVar9;
        ppppuVar9[3] = (undefined8 ***)0x0;
        ppppuVar9[4] = (undefined8 ***)0x0;
        *(undefined4 *)(ppppuVar9 + 2) = 0xa000001f;
        *(undefined4 *)((longlong)ppppuVar9 + 0x14) = 0x80000004;
        *(undefined4 *)(ppppuVar9 + 5) = 0x30;
        pbVar14 = param_13;
        if ((undefined8 *****)*ppppuStack_e0 != &local_e8) goto LAB_140030e8c;
        goto LAB_140030e93;
      }
      puVar12 = auStackY_178;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14003114c;
      uVar13 = 0x88;
      uVar10 = 0xc;
    }
    else {
      ppppuVar6 = (undefined8 ****)ExAllocateFromPagedLookasideList(&DAT_14000f380);
      if (ppppuVar6 != (undefined8 ****)0x0) {
        ppppuVar6[1] = ppppuVar6;
        *ppppuVar6 = ppppuVar6;
        ppppuVar6[3] = (undefined8 ***)0x0;
        ppppuVar6[4] = (undefined8 ***)0x0;
        *(int *)(ppppuVar6 + 2) = param_6;
        *(undefined4 *)((longlong)ppppuVar6 + 0x14) = 0x80000004;
        *(undefined4 *)(ppppuVar6 + 5) = 0x30;
        if ((undefined8 *****)*ppppuStack_e0 == &local_e8) {
          ppppuVar6[1] = ppppuStack_e0;
          *ppppuVar6 = &local_e8;
          *ppppuStack_e0 = ppppuVar6;
          ppppuStack_e0 = ppppuVar6;
          goto LAB_140030cc2;
        }
LAB_140030e8c:
        pcVar2 = (code *)swi(0x29);
        ppppuStack_e0 = (undefined8 ****)(*pcVar2)(3);
        puVar11 = auStackY_170;
        param_13 = pbVar14;
LAB_140030e93:
        ppppuVar9[1] = ppppuStack_e0;
        *ppppuVar9 = &local_e8;
        *ppppuStack_e0 = ppppuVar9;
        ppppuStack_e0 = ppppuVar9;
        goto LAB_140030ea7;
      }
      puVar12 = auStackY_178;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14003114c;
      uVar13 = 0x85;
      uVar10 = 0xdf;
    }
LAB_140030c48:
    WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,uVar13,
                        &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                        "onecore\\base\\fs\\wci\\wcifs\\utils.c",uVar10,0x9a);
    puVar12 = auStackY_178;
  }
  else {
    local_b8[5] = 1;
    local_b8[2] = 0;
    local_b8[1] = 0x28;
    local_b8[3] = 0;
    local_b8[4] = 0;
    if (param_3 != 0) {
      local_b8[5] = IoGetSilo(param_3);
    }
    local_88 = 0x30;
    uStack_70 = 0x240;
    local_68 = 0;
    uStack_60 = 0;
    uStack_80 = param_2;
    local_78 = param_1;
    iVar5 = FltCreateFileEx2(Globals,param_4,&local_d8,&local_f0);
    puVar11 = auStackY_178;
    if (iVar5 < 0) {
      puVar12 = auStackY_178;
      if (((iVar5 != -0x3fffffcc) && (puVar12 = auStackY_178, iVar5 != -0x3fffffc6)) &&
         (puVar12 = auStackY_178,
         (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        uVar13 = 0x8b;
        goto LAB_140031038;
      }
    }
    else {
      iVar5 = FltQueryInformationFile(param_4,local_f0,&local_c0,8);
      puVar11 = auStackY_178;
      if (iVar5 < 0) {
        puVar12 = auStackY_178;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar13 = 0x8c;
          goto LAB_140031038;
        }
      }
      else {
        if ((local_c0 & 0x400) == 0) {
LAB_140030aea:
          bVar15 = false;
LAB_140030af4:
          bVar16 = false;
LAB_140030afe:
          bVar17 = false;
LAB_140030b0f:
          uVar10 = 0;
        }
        else {
          if (local_c0._4_4_ == param_6) {
            bVar15 = param_9 != (byte *)0x0;
            goto LAB_140030af4;
          }
          if (local_c0._4_4_ == -0x5ffffff4) {
            bVar15 = false;
            bVar16 = param_10 != (byte *)0x0;
            goto LAB_140030afe;
          }
          if (local_c0._4_4_ == -0x5ffffffd) {
            bVar15 = false;
            bVar17 = param_11 != (byte *)0x0;
            bVar16 = false;
            goto LAB_140030b0f;
          }
          if (local_c0._4_4_ == -0x5fffffe1) {
            bVar15 = false;
            local_f4 = param_13 != (byte *)0x0;
            bVar16 = false;
            bVar17 = false;
            goto LAB_140030b0f;
          }
          uStack_70 = 0x240;
          local_88 = 0x30;
          local_68 = 0;
          uStack_60 = 0;
          uStack_80 = param_2;
          local_78 = param_1;
          iVar5 = FltCreateFileEx2(Globals,param_4,&local_d0,&local_c8);
          puVar11 = auStackY_178;
          if (-1 < iVar5) {
            FltClose(local_d8);
            ObfDereferenceObject(local_f0);
            local_f0 = local_c8;
            local_d8 = local_d0;
            local_d0 = 0;
            local_c8 = 0;
            goto LAB_140030aea;
          }
          if (iVar5 != -0x3ffffd87) {
            puVar12 = auStackY_178;
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar13 = 0x8d;
              goto LAB_140031038;
            }
            goto LAB_14003114c;
          }
          uVar10 = 1;
          bVar15 = false;
          bVar16 = false;
          bVar17 = false;
        }
        lVar4 = local_d8;
        lVar3 = local_f0;
        if (param_12 != (undefined1 *)0x0) {
          *param_12 = uVar10;
        }
        if (param_9 != (byte *)0x0) {
          *param_9 = bVar15;
        }
        if (param_10 != (byte *)0x0) {
          *param_10 = bVar16;
        }
        if (param_11 != (byte *)0x0) {
          *param_11 = bVar17;
        }
        if (param_13 != (byte *)0x0) {
          *param_13 = local_f4;
        }
        local_d8 = 0;
        *param_7 = lVar4;
        local_f0 = 0;
        *param_8 = lVar3;
        puVar12 = auStackY_178;
      }
    }
  }
LAB_14003114c:
  if (local_b8[0] != 0) {
    *(undefined8 *)(puVar12 + -8) = 0x14003115c;
    FltReleaseContext();
  }
  if (ppppuVar6 != (undefined8 ****)0x0) {
    *(undefined8 *)(puVar12 + -8) = 0x140031177;
    ExFreeToPagedLookasideList(&DAT_14000f380,ppppuVar6);
  }
  if (ppppuVar7 != (undefined8 ****)0x0) {
    *(undefined8 *)(puVar12 + -8) = 0x140031192;
    ExFreeToPagedLookasideList(&DAT_14000f380,ppppuVar7);
  }
  if (ppppuVar8 != (undefined8 ****)0x0) {
    *(undefined8 *)(puVar12 + -8) = 0x1400311ad;
    ExFreeToPagedLookasideList(&DAT_14000f380,ppppuVar8);
  }
  if (ppppuVar9 != (undefined8 ****)0x0) {
    *(undefined8 *)(puVar12 + -8) = 0x1400311c8;
    ExFreeToPagedLookasideList(&DAT_14000f380,ppppuVar9);
  }
  if (local_d8 != 0) {
    *(undefined8 *)(puVar12 + -8) = 0x1400311dd;
    FltClose();
  }
  if (local_f0 != 0) {
    *(undefined8 *)(puVar12 + -8) = 0x1400311f2;
    ObfDereferenceObject();
  }
  if (local_d0 != 0) {
    *(undefined8 *)(puVar12 + -8) = 0x140031207;
    FltClose();
  }
  if (local_c8 != 0) {
    *(undefined8 *)(puVar12 + -8) = 0x14003121c;
    ObfDereferenceObject();
  }
LAB_14003122a:
  return (int)*(undefined8 *)(puVar12 + 0x168);
}



===== WcRelPathToFullPath @ 140031248 =====

uint WcRelPathToFullPath(ushort *param_1,ushort param_2,void *param_3,void *param_4,ushort param_5)

{
  bool bVar1;
  uint uVar2;
  ushort *puVar3;
  undefined2 uVar4;
  undefined2 *_Dst;
  undefined1 uVar5;
  
  bVar1 = false;
  if ((uint)param_1[1] < (uint)param_5 + (uint)param_2) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar4 = 10;
      uVar5 = 0x65;
LAB_140031318:
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xe,uVar4,
                          &WPP_52759b377eea39e2466a1234853e56fe_Traceguids,
                          "onecore\\base\\fs\\wci\\wcifs\\message.c",uVar5,0x23);
    }
LAB_140031348:
    uVar2 = 0xc0000023;
  }
  else {
    memmove(*(void **)(param_1 + 4),param_3,(ulonglong)param_2);
    _Dst = (undefined2 *)(*(longlong *)(param_1 + 4) + (ulonglong)param_2);
    if (((param_2 == 0) || (_Dst[-1] != 0x5c)) || (param_2 == 0)) {
      if ((uint)param_1[1] < (uint)param_5 + (uint)param_2 + 2) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar4 = 0xb;
          uVar5 = 0x76;
          goto LAB_140031318;
        }
        goto LAB_140031348;
      }
      *_Dst = 0x5c;
      bVar1 = true;
      _Dst = _Dst + 1;
    }
    memmove(_Dst,param_4,(ulonglong)param_5);
    puVar3 = param_1;
    uVar2 = RtlUShortAdd(param_2,param_5,param_1);
    if ((-1 < (int)uVar2) && (bVar1)) {
      uVar2 = RtlUShortAdd(2,*param_1,puVar3);
    }
  }
  return uVar2;
}



===== WcGetInstanceFromVolumeName @ 1400313c0 =====

int WcGetInstanceFromVolumeName(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined2 uVar2;
  longlong local_res20;
  undefined1 uVar3;
  
  local_res20 = 0;
  iVar1 = FltGetVolumeFromName(Globals,param_1,&local_res20);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140031499;
    uVar2 = 0xc5;
    uVar3 = 0x4c;
  }
  else {
    iVar1 = FltGetVolumeInstanceFromName(Globals,local_res20,param_2,param_3);
    if ((-1 < iVar1) || ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED))
    goto LAB_140031499;
    uVar2 = 0xc6;
    uVar3 = 0x53;
  }
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xe,uVar2,
                      &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                      "onecore\\base\\fs\\wci\\wcifs\\utils.c",uVar3,(char)iVar1);
LAB_140031499:
  if (local_res20 != 0) {
    FltObjectDereference();
  }
  return iVar1;
}



===== WcOpenPlaceHolder @ 1400314c8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int WcOpenPlaceHolder(undefined8 param_1,wchar_t *param_2,undefined4 param_3,undefined4 param_4,
                     longlong *param_5,longlong *param_6,byte *param_7)

{
  int iVar1;
  undefined1 auStackY_d8 [32];
  longlong local_88;
  longlong local_80;
  undefined8 ***local_78;
  undefined8 ***local_70;
  undefined8 ***local_68;
  undefined8 ***local_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_68 = &local_78;
  local_60 = &local_78;
  local_78 = &local_68;
  local_40 = 0x30;
  local_70 = &local_68;
  local_88 = 0;
  local_80 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_54 = 0x80000004;
  local_58 = param_4;
  iVar1 = WcOpenReparsePoint(param_1,param_2,0,0,0x80,param_3,7,(longlong *)&local_78,&local_88,
                             &local_80);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDZd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0x90,
                 &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                 "onecore\\base\\fs\\wci\\wcifs\\utils.c",0x67,param_2,(char)iVar1);
    }
  }
  else {
    if (param_7 != (byte *)0x0) {
      *param_7 = (byte)local_54 & 1;
    }
    *param_5 = local_88;
    local_88 = 0;
    if (param_6 == (longlong *)0x0) goto LAB_140031621;
    *param_6 = local_80;
    local_80 = 0;
  }
  if (local_88 != 0) {
    FltClose();
  }
LAB_140031621:
  if (local_80 != 0) {
    ObfDereferenceObject();
  }
  return iVar1;
}



===== WcOpenReparsePoint @ 140031668 =====

int WcOpenReparsePoint(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4,
                      undefined4 param_5,undefined4 param_6,undefined4 param_7,longlong *param_8,
                      undefined8 param_9,undefined8 param_10)

{
  longlong *plVar1;
  longlong lVar2;
  code *pcVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined2 uVar6;
  undefined1 auStackY_118 [8];
  undefined1 auStackY_110 [24];
  undefined1 uVar7;
  longlong local_90 [6];
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  ulonglong uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  
  local_90[5] = local_90[5] & 0xffffffffffff0000;
  local_40 = 0;
  uStack_38 = uStack_38 & 0xffffffff00000000;
  local_90[0] = 0;
  local_90[1] = 0;
  local_90[2] = 0;
  local_90[3] = 0;
  local_90[4] = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_30 = 0;
  uStack_28 = 0;
  iVar4 = FltAllocateExtraCreateParameterList(Globals,0,local_90);
  puVar5 = auStackY_118;
  if (iVar4 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400318e4;
    uVar6 = 0x8e;
    uVar7 = 0xcb;
  }
  else {
    iVar4 = FltAllocateExtraCreateParameterFromLookasideList
                      (Globals,&ECP_TYPE_OPEN_REPARSE_GUID,0x10);
    puVar5 = auStackY_118;
    if (-1 < iVar4) {
      plRam0000000000000008 = (longlong *)0x0;
      uRam0000000000000000 = 0;
      while (plVar1 = (longlong *)*param_8, puVar5 = auStackY_118, plVar1 != param_8) {
        if (((longlong *)plVar1[1] != param_8) ||
           (lVar2 = *plVar1, *(longlong **)(lVar2 + 8) != plVar1)) {
LAB_1400317f6:
          pcVar3 = (code *)swi(0x29);
          (*pcVar3)(3);
          puVar5 = auStackY_110;
          break;
        }
        *param_8 = lVar2;
        *(longlong **)(lVar2 + 8) = param_8;
        if (*plRam0000000000000008 != 0) goto LAB_1400317f6;
        *plVar1 = 0;
        plVar1[1] = (longlong)plRam0000000000000008;
        *plRam0000000000000008 = (longlong)plVar1;
        plRam0000000000000008 = plVar1;
      }
      *(undefined8 *)(puVar5 + -8) = 0x140031813;
      FltInsertExtraCreateParameter(Globals,local_90[0],0);
      local_90[1] = 0x28;
      local_90[3] = 0;
      local_90[4] = 0;
      local_90[2] = local_90[0];
      local_90[5] = 1;
      if (param_4 != 0) {
        *(undefined8 *)(puVar5 + -8) = 0x140031850;
        local_90[5] = IoGetSilo(param_4);
      }
      *(longlong **)(puVar5 + 0x78) = local_90 + 1;
      *(undefined4 *)(puVar5 + 0x70) = 0;
      *(undefined4 *)(puVar5 + 0x68) = 0;
      *(undefined8 *)(puVar5 + 0x60) = 0;
      *(undefined4 *)(puVar5 + 0x58) = param_6;
      *(undefined4 *)(puVar5 + 0x50) = 1;
      *(undefined4 *)(puVar5 + 0x48) = param_7;
      *(undefined4 *)(puVar5 + 0x40) = 0;
      *(undefined8 *)(puVar5 + 0x38) = 0;
      *(undefined8 **)(puVar5 + 0x30) = &local_30;
      *(undefined8 **)(puVar5 + 0x28) = &local_60;
      *(undefined4 *)(puVar5 + 0x20) = param_5;
      local_60 = CONCAT44(local_60._4_4_,0x30);
      uStack_48 = CONCAT44(uStack_48._4_4_,0x240);
      local_40 = 0;
      uStack_38 = 0;
      *(undefined8 *)(puVar5 + -8) = 0x1400318dd;
      uStack_58 = param_3;
      local_50 = param_2;
      iVar4 = FltCreateFileEx2(Globals,param_1,param_9,param_10);
      goto LAB_1400318e4;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400318e4;
    uVar6 = 0x8f;
    uVar7 = 0xd8;
  }
  puVar5 = auStackY_118;
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,uVar6,
                      &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                      "onecore\\base\\fs\\wci\\wcifs\\utils.c",uVar7,(char)iVar4);
LAB_1400318e4:
  if (local_90[0] != 0) {
    *(undefined8 *)(puVar5 + -8) = 0x1400318fb;
    FltFreeExtraCreateParameterList(Globals);
  }
  return iVar4;
}



===== WcPrepareEnumerationContexts @ 14003192c =====

ulonglong WcPrepareEnumerationContexts
                    (longlong *param_1,longlong param_2,longlong param_3,undefined8 *param_4,
                    int param_5,int param_6,byte param_7,int param_8)

{
  bool bVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  ulonglong uVar6;
  
  uVar6 = 0;
  if ((longlong *)*param_1 == param_1) {
    uVar2 = WcAddSubContext((longlong)param_1,param_2,param_3,1);
    uVar6 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) {
      return uVar6;
    }
    if (param_4 != (undefined8 *)0x0) {
      for (puVar4 = (undefined8 *)*param_4; puVar4 != param_4; puVar4 = (undefined8 *)*puVar4) {
        uVar2 = WcAddSubContext((longlong)param_1,*(longlong *)puVar4[3],((longlong *)puVar4[3])[2],
                                0);
        uVar6 = uVar2 & 0xffffffff;
        if ((int)uVar2 < 0) {
          return uVar6;
        }
      }
    }
  }
  plVar5 = (longlong *)*param_1;
  do {
    if (plVar5 == param_1) {
      return uVar6;
    }
    lVar3 = plVar5[9];
    bVar1 = false;
    if (((lVar3 == 0) || (*(int *)((longlong)plVar5 + 0x3c) == 0)) || ((param_7 & 1) != 0)) {
LAB_1400319e0:
      if ((*(byte *)(plVar5 + 2) & 1) != 0) {
        bVar1 = true;
      }
      if (lVar3 == 0) {
LAB_1400319fd:
        lVar3 = ExAllocatePool2(0x100,param_5,0x6e654357);
        plVar5[9] = lVar3;
        if (lVar3 == 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return 0xc000009a;
          }
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0x12,0x17,
                              &WPP_795aeb0acc6f36f288a32122a031d179_Traceguids,
                              "onecore\\base\\fs\\wci\\wcifs\\dir.c",0x8b,0x9a);
          return 0xc000009a;
        }
        *(int *)(plVar5 + 8) = param_5;
      }
      else if ((int)plVar5[8] != param_5) {
        ExFreePoolWithTag(lVar3,0x6e654357);
        plVar5[9] = 0;
        goto LAB_1400319fd;
      }
      *(undefined4 *)((longlong)plVar5 + 0x3c) = 0;
      *(undefined4 *)(plVar5 + 7) = 0;
      *(undefined4 *)(plVar5 + 3) = 0;
      *(int *)((longlong)plVar5 + 0x34) = param_6;
      *(byte *)(plVar5 + 6) = param_7;
      if (((bVar1) && ((param_7 & 1) == 0)) && (param_8 != 0)) {
        *(byte *)(plVar5 + 6) = param_7 | 4;
      }
    }
    else if (param_6 != *(int *)((longlong)plVar5 + 0x34)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDdd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0x12,0x16,
                   &WPP_795aeb0acc6f36f288a32122a031d179_Traceguids,
                   "onecore\\base\\fs\\wci\\wcifs\\dir.c",0x67,(char)param_6,
                   (char)*(int *)((longlong)plVar5 + 0x34));
        lVar3 = plVar5[9];
      }
      bVar1 = true;
      goto LAB_1400319e0;
    }
    plVar5 = (longlong *)*plVar5;
  } while( true );
}



===== WcAddSubContext @ 140031bb4 =====

undefined8 WcAddSubContext(longlong param_1,longlong param_2,longlong param_3,undefined4 param_4)

{
  longlong *plVar1;
  code *pcVar2;
  longlong *_Dst;
  undefined8 uVar3;
  
  uVar3 = 0;
  _Dst = (longlong *)ExAllocateFromPagedLookasideList(&DAT_14000f480);
  if (_Dst == (longlong *)0x0) {
    uVar3 = 0xc000009a;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0x12,0x15,
                          &WPP_795aeb0acc6f36f288a32122a031d179_Traceguids,
                          "onecore\\base\\fs\\wci\\wcifs\\dir.c",0xe1,0x9a);
    }
  }
  else {
    memset(_Dst,0,0x50);
    *(undefined4 *)(_Dst + 2) = param_4;
    _Dst[4] = param_3;
    _Dst[5] = param_2;
    plVar1 = *(longlong **)(param_1 + 8);
    if (*plVar1 != param_1) {
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(3);
      pcVar2 = (code *)swi(3);
      uVar3 = (*pcVar2)();
      return uVar3;
    }
    *_Dst = param_1;
    _Dst[1] = (longlong)plVar1;
    *plVar1 = (longlong)_Dst;
    *(longlong **)(param_1 + 8) = _Dst;
  }
  return uVar3;
}



===== WcEnumerateLayeredDirectories @ 140031cac =====

undefined8
WcEnumerateLayeredDirectories
          (undefined8 *param_1,undefined8 *param_2,undefined8 param_3,int param_4,undefined4 param_5
          )

{
  undefined8 *puVar1;
  int iVar2;
  undefined8 local_28;
  undefined8 uStack_20;
  
  puVar1 = (undefined8 *)*param_1;
  local_28 = 0;
  uStack_20 = 0;
  for (; puVar1 != param_1; puVar1 = (undefined8 *)*puVar1) {
    if (*(int *)((longlong)puVar1 + 0x3c) == 0) {
      if (((*(byte *)(puVar1 + 6) & 4) != 0) && (param_4 != 0)) {
        param_2 = &local_28;
        local_28._4_4_ = (undefined4)((ulonglong)local_28 >> 0x20);
        local_28 = CONCAT62(CONCAT42(local_28._4_4_,(short)param_4),(short)param_4);
        uStack_20 = param_3;
      }
      iVar2 = WcEnumerateDirectory
                        (puVar1[5],puVar1[4],*(undefined4 *)((longlong)puVar1 + 0x34),param_2,
                         param_5,*(undefined1 *)(puVar1 + 6),*(undefined4 *)(puVar1 + 8),puVar1[9],
                         (int *)((longlong)puVar1 + 0x3c));
      *(int *)(puVar1 + 3) = iVar2;
    }
  }
  return 0;
}



===== WcEnumerateDirectory @ 140031d74 =====

int WcEnumerateDirectory
              (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
              undefined4 param_5,undefined1 param_6,undefined4 param_7,undefined8 param_8,
              undefined4 *param_9)

{
  int iVar1;
  longlong local_18 [2];
  
  local_18[0] = 0;
  iVar1 = FltAllocateCallbackData(param_1,param_2,local_18);
  if (-1 < iVar1) {
    *(undefined1 *)(*(longlong *)(local_18[0] + 0x10) + 4) = 0xc;
    *(undefined1 *)(*(longlong *)(local_18[0] + 0x10) + 5) = 1;
    *(undefined4 *)(*(longlong *)(local_18[0] + 0x10) + 0x18) = param_7;
    *(undefined4 *)(*(longlong *)(local_18[0] + 0x10) + 0x28) = param_3;
    *(undefined8 *)(*(longlong *)(local_18[0] + 0x10) + 0x20) = param_4;
    *(undefined4 *)(*(longlong *)(local_18[0] + 0x10) + 0x30) = param_5;
    *(undefined8 *)(*(longlong *)(local_18[0] + 0x10) + 0x38) = param_8;
    *(undefined8 *)(*(longlong *)(local_18[0] + 0x10) + 0x40) = 0;
    *(undefined1 *)(*(longlong *)(local_18[0] + 0x10) + 6) = param_6;
    FltPerformSynchronousIo(local_18[0]);
    iVar1 = *(int *)(local_18[0] + 0x18);
    *param_9 = *(undefined4 *)(local_18[0] + 0x20);
  }
  FltFreeCallbackData(local_18[0]);
  return iVar1;
}



===== WcGetSetStreamHandleContext @ 140031e78 =====

ulonglong WcGetSetStreamHandleContext(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong local_res20;
  longlong local_38;
  longlong local_30;
  longlong local_28 [2];
  
  local_28[0] = 0;
  local_38 = 0;
  local_res20 = 0;
  local_30 = 0;
  WcGetContextFileObject(param_1,param_2,local_28,&local_38);
  uVar1 = FltGetStreamHandleContext(param_1,param_2,&local_res20);
  uVar2 = (ulonglong)uVar1;
  if (uVar1 == 0xc0000225) {
    uVar2 = FltAllocateContext(Globals,0x10,600,0x200,&local_res20);
    if ((int)uVar2 < 0) {
      return uVar2;
    }
    *(longlong *)(local_res20 + 8) = local_res20;
    *(longlong *)local_res20 = local_res20;
    lVar3 = local_res20 + 0x30;
    *(longlong *)(local_res20 + 0x38) = lVar3;
    *(longlong *)lVar3 = lVar3;
    KeInitializeEvent(local_res20 + 0x10,1,1);
    *(undefined4 *)(local_res20 + 0x2c) = 0;
    *(undefined4 *)(local_res20 + 0x28) = 0;
    *(longlong *)(local_res20 + 0x40) = local_38;
    *(undefined4 *)(local_res20 + 0x254) = 0;
    *(undefined4 *)(local_res20 + 0x48) = 0;
    uVar1 = FltSetStreamHandleContext(param_1,param_2,1,local_res20,&local_30);
    uVar2 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) {
      FltReleaseContext(local_res20);
      if (uVar1 != 0xc01c0002) {
        return uVar2;
      }
      uVar2 = 0;
      local_res20 = local_30;
    }
    else {
    }
    lVar4 = local_res20;
    lVar3 = 0;
  }
  else {
    lVar3 = local_38;
    if ((int)uVar1 < 0) goto LAB_140031fe2;
    lVar4 = local_res20;
  }
  local_res20 = 0;
  *param_3 = lVar4;
LAB_140031fe2:
  if (local_28[0] != 0) {
    FltReleaseContext();
  }
  if (lVar3 != 0) {
    FltReleaseContext(lVar3);
  }
  if (local_res20 != 0) {
    FltReleaseContext();
  }
  return uVar2;
}



===== _tlgEnableCallback @ 140032040 =====

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



===== WcShouldAutoAttach @ 1400320bc =====

bool WcShouldAutoAttach(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  ushort uVar2;
  int iVar3;
  uint *puVar4;
  ushort uVar5;
  undefined2 uVar6;
  bool bVar7;
  uint local_res18 [2];
  uint local_res20 [2];
  undefined8 in_stack_ffffffffffffff08;
  undefined4 uVar8;
  undefined8 *puVar9;
  undefined1 uVar10;
  undefined1 uVar11;
  ulonglong in_stack_ffffffffffffff28;
  longlong local_98 [3];
  undefined8 local_80;
  longlong lStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined1 *local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  ulonglong uStack_38;
  
  uVar8 = (undefined4)((ulonglong)in_stack_ffffffffffffff08 >> 0x20);
  bVar7 = false;
  local_res18[0] = 0;
  local_98[2] = 0;
  local_98[0] = 0;
  local_40 = 0;
  local_80 = 0;
  lStack_78 = 0;
  uStack_38 = uStack_38 & 0xffffffff00000000;
  local_60 = 0;
  uStack_58 = 0;
  local_98[1] = 0;
  local_50 = (undefined1 *)0x0;
  uStack_48 = 0;
  local_res20[0] = 0;
  local_70 = 0;
  uStack_68 = 0;
  RtlInitUnicodeString(&local_80,0);
  iVar3 = FltGetVolumeName(param_2,0,local_res18);
  if (iVar3 == -0x3fffffdd) {
    uVar1 = (local_res18[0] & 0xffff) * 2;
    if (uVar1 < 0x10000) {
      uVar5 = (ushort)uVar1 + 8;
      if (uVar5 < (ushort)uVar1) {
        local_80._0_4_ = CONCAT22(0xffff,(undefined2)local_80);
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400321c2;
        uVar11 = 0x95;
        uVar6 = 0xaf;
        uVar10 = 0xe2;
      }
      else {
        uVar2 = (ushort)(uVar1 + 0x50);
        if (uVar2 < uVar5) {
          local_80._0_4_ = CONCAT22(0xffff,(undefined2)local_80);
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1400321c2;
          uVar11 = 0x95;
          uVar6 = 0xb0;
          uVar10 = 0xe9;
        }
        else {
          local_80._0_4_ = CONCAT22(uVar2,(undefined2)local_80);
          lStack_78 = ExAllocatePool2(0x100,uVar1 + 0x50 & 0xffff,0x6e664357);
          if (lStack_78 == 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_1400321c2;
            uVar11 = 0x9a;
            uVar6 = 0xb1;
            uVar10 = 0xf0;
          }
          else {
            local_80 = local_80 & 0xffffffffffff0000;
            iVar3 = FltGetVolumeName(param_2,&local_80,local_res18);
            if (iVar3 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
              goto LAB_1400321c2;
              uVar11 = (undefined1)iVar3;
              uVar6 = 0xb2;
              uVar10 = 0xf7;
            }
            else {
              iVar3 = RtlAppendUnicodeToString(&local_80,L"\\System Volume Information\\Wcifs.md");
              if (iVar3 < 0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                goto LAB_1400321c2;
                uVar11 = (undefined1)iVar3;
                uVar6 = 0xb3;
                uVar10 = 0xfe;
              }
              else {
                local_50 = (undefined1 *)&local_80;
                puVar9 = &local_60;
                local_60 = CONCAT44(local_60._4_4_,0x30);
                uStack_58 = 0;
                uStack_48 = CONCAT44(uStack_48._4_4_,0x200);
                local_40 = 0;
                uStack_38 = 0;
                iVar3 = FltCreateFileEx(Globals,param_1,local_98 + 2,local_98,CONCAT44(uVar8,1),
                                        puVar9,&local_70,0,
                                        in_stack_ffffffffffffff28 & 0xffffffff00000000,5,1,0,0,0,0);
                uVar8 = (undefined4)((ulonglong)puVar9 >> 0x20);
                if (iVar3 < 0) goto LAB_1400321c2;
                local_98[1] = 0;
                puVar4 = (uint *)FltAllocatePoolAlignedWithTag(param_1,1,0x1000,0x61614357);
                if (puVar4 == (uint *)0x0) goto LAB_1400321c2;
                iVar3 = FltReadFile(param_1,local_98[0],local_98 + 1,0x1000,puVar4,CONCAT44(uVar8,1)
                                    ,local_res20,0,0);
                if (-1 < iVar3) {
                  if (3 < local_res20[0]) {
                    bVar7 = (*puVar4 & 1) != 0;
                  }
                  goto LAB_1400321c2;
                }
                if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                goto LAB_1400321c2;
                uVar11 = (undefined1)iVar3;
                uVar6 = 0xb4;
                uVar10 = 0x35;
              }
            }
          }
        }
      }
    }
    else {
      local_80._0_4_ = CONCAT22(0xffff,(undefined2)local_80);
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400321c2;
      uVar11 = 0x95;
      uVar6 = 0xae;
      uVar10 = 0xdb;
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400321c2;
    uVar11 = 0x10;
    uVar6 = 0xad;
    uVar10 = 0xd3;
  }
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xe,uVar6,
                      &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                      "onecore\\base\\fs\\wci\\wcifs\\utils.c",uVar10,uVar11);
LAB_1400321c2:
  if (lStack_78 != 0) {
    ExFreePoolWithTag(lStack_78,0x6e664357);
  }
  if (local_98[0] != 0) {
    ObfDereferenceObject();
  }
  if (local_98[2] != 0) {
    FltClose();
  }
  return bVar7;
}



===== TlgAggregateInternalRegisteredProviderEtwCallback @ 140032510 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
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
  if (*(code **)((longlong)param_7 + 0x148) != (code *)0x0) {
    uVar2 = CONCAT71((int7)(param_5 >> 8),param_3);
    (**(code **)((longlong)param_7 + 0x148))();
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



===== LookUpTableFlushComplete @ 14003258c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void LookUpTableFlushComplete(longlong param_1,undefined8 param_2,undefined8 param_3,_GUID *param_4)

{
  _tlgProvider_t *p_Var1;
  ulonglong uVar2;
  longlong lVar3;
  uint uVar4;
  _GUID *p_Var5;
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
  _GUID *local_108;
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
    lVar3 = param_1;
    UpdateInternalStatsOnFlush(param_1,*(uint *)(param_1 + 0x100));
    p_Var5 = *(_GUID **)(lVar3 + 0x120);
    if (p_Var5 != (_GUID *)0x0) {
      if ((5 < DAT_14000f098) &&
         (uVar2 = _tlgKeywordOn(0x14000f098,0x200000000000), (char)uVar2 != '\0')) {
        local_148 = (_tlgWrapperByVal<1>)0x4;
        local_c8 = 0x2a;
        local_e0 = L"SummaryCount";
        local_d8 = 0x18;
        local_130 = (ulonglong)*(uint *)(param_1 + 0x144);
        local_d0 = L"NumLargeEventFailures";
        local_128 = (ulonglong)*(uint *)(param_1 + 0x140);
        local_c0 = L"NumAllocationFailures";
        local_120 = (ulonglong)*(uint *)(param_1 + 0x13c);
        local_b0 = L"NumBucketLimitReached";
        local_118 = (ulonglong)*(uint *)(param_1 + 0x138);
        local_a0 = L"MinEntriesFlushed";
        local_110 = (ulonglong)*(uint *)(param_1 + 0x134);
        local_90 = L"MaxEntriesFlushed";
        local_80 = L"TotalEntriesFlushed";
        local_78 = 0x26;
        local_100 = (ulonglong)*(uint *)(param_1 + 0x130);
        local_70 = L"MaxEntriesStored";
        local_f8 = *(undefined8 *)(param_1 + 0x128);
        local_60 = L"NumFlushes";
        local_58 = 0x14;
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
        p_Var1 = *(_tlgProvider_t **)(*(longlong *)(param_1 + 0x158) + 8);
        local_f0 = &local_28;
        local_28 = *(undefined8 *)(p_Var1 + -0x10);
        uStack_20 = *(undefined8 *)(p_Var1 + -8);
        local_138 = 0xffffffff;
        local_68 = 0x20;
        local_13f[0] = (_tlgWrapperByVal<1>)0x0;
        local_134 = 300;
        local_e8 = 0x1000000;
        local_108 = p_Var5;
        _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
        ::
        Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByRef<16>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>_>
                  (p_Var1,&DAT_14000beb4,p_Var5,param_4,(_tlgWrapperByVal<8> *)&local_e8,
                   (_tlgWrapperByVal<4> *)&local_134,(_tlgWrapperByVal<4> *)&local_138,local_13f,
                   (_tlgWrapperByRef<16> *)&local_f0,(_tlgWrapperBinary *)&local_60,
                   (_tlgWrapperByVal<8> *)&local_f8,&local_140,(_tlgWrapperBinary *)&local_70,
                   (_tlgWrapperByVal<8> *)&local_100,&local_141,(_tlgWrapperBinary *)&local_80,
                   (_tlgWrapperByVal<8> *)&local_108,&local_142,(_tlgWrapperBinary *)&local_90,
                   (_tlgWrapperByVal<8> *)&local_110,&local_143,(_tlgWrapperBinary *)&local_a0,
                   (_tlgWrapperByVal<8> *)&local_118,&local_144,(_tlgWrapperBinary *)&local_b0,
                   (_tlgWrapperByVal<8> *)&local_120,&local_145,(_tlgWrapperBinary *)&local_c0,
                   (_tlgWrapperByVal<8> *)&local_128,&local_146,(_tlgWrapperBinary *)&local_d0,
                   (_tlgWrapperByVal<8> *)&local_130,&local_147,(_tlgWrapperBinary *)&local_e0,
                   (_tlgWrapperByVal<4> *)&local_13c,&local_148);
      }
      *(undefined8 *)(param_1 + 0x120) = 0;
      *(undefined8 *)(param_1 + 0x128) = 0;
      local_30 = 0;
      *(undefined8 *)(param_1 + 0x130) = 0;
      *(undefined8 *)(param_1 + 0x138) = 0;
      *(undefined8 *)(param_1 + 0x140) = 0;
    }
    do {
      FlushLookUpTableBucket(param_1,uVar4);
      uVar4 = uVar4 + 1;
    } while (uVar4 < 0x20);
  }
  return;
}



===== WcResetEnumContexts @ 14003292c =====

void WcResetEnumContexts(undefined8 *param_1,char param_2)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)*param_1;
  do {
    if (puVar1 == param_1) {
      return;
    }
    if (((*(uint *)(puVar1 + 2) & 1) == 0) &&
       (*(uint *)(puVar1 + 7) < *(uint *)((longlong)puVar1 + 0x3c))) {
      if (*(uint *)((longlong)puVar1 + 0x3c) == 0) goto LAB_140032985;
    }
    else {
      *(undefined4 *)((longlong)puVar1 + 0x3c) = 0;
LAB_140032985:
      *(undefined4 *)(puVar1 + 7) = 0;
      if (param_2 == '\0') {
        ExFreePoolWithTag(puVar1[9],0x6e654357);
        puVar1[9] = 0;
        *(undefined4 *)(puVar1 + 8) = 0;
      }
    }
    *(undefined4 *)(puVar1 + 3) = 0;
    *(uint *)(puVar1 + 2) = *(uint *)(puVar1 + 2) & 1;
    *(undefined1 *)(puVar1 + 6) = 0;
    puVar1 = (undefined8 *)*puVar1;
  } while( true );
}



===== WcPreTransaction @ 1400329b4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong WcPreTransaction(longlong param_1,longlong param_2,undefined4 param_3,uint param_4)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined2 uVar6;
  undefined4 uVar7;
  undefined1 auStackY_e8 [32];
  undefined1 uVar8;
  undefined4 local_a8;
  undefined4 local_a4;
  uint local_a0;
  longlong local_98;
  ulonglong local_90;
  undefined8 local_88 [4];
  undefined4 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  ulonglong *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_e8;
  uVar4 = 0;
  local_98 = 0;
  local_a0 = 0;
  piVar3 = (int *)0x0;
  bVar1 = WcIsSiloFileObject(*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20));
  if (bVar1) {
    if (DAT_14000f6a0 != '\0') {
      uVar4 = WcPreCreateExpansion(param_1,param_2,param_3,param_4);
      uVar4 = uVar4 & 0xffffffff;
      goto LAB_140032a1c;
    }
    if ((*(uint *)(*(longlong *)(param_1 + 0x10) + 0x20) & 0x2000) == 0) {
      iVar2 = FltGetFileNameInformation(param_1,0x102);
      if (-1 < iVar2) {
        iVar2 = FltParseFileNameInformation(local_98);
        if (-1 < iVar2) {
          RtlHashUnicodeString(local_98 + 0x58,1);
        }
      }
      uVar7 = 0;
    }
    else {
      uVar7 = 1;
    }
    if (5 < DAT_14000f060) {
      uVar4 = _tlgKeywordOn(0x14000f060,0x400000000000);
      if ((char)uVar4 != '\0') {
        local_68 = &local_a8;
        local_5c = 0;
        local_4c = 0;
        local_90 = (ulonglong)local_a0;
        local_58 = &local_90;
        local_60 = 4;
        local_50 = 8;
        local_a8 = uVar7;
        uVar5 = IoGetSilo(*(undefined8 *)(param_2 + 0x20));
        local_a4 = PsGetSiloIdentifier(uVar5);
        local_3c = 0;
        local_48 = &local_a4;
        local_40 = 4;
        _tlgWriteTransfer_EtwWriteTransfer(0x14000f060,&DAT_14000b500,0,0,5,local_88);
      }
    }
    uVar4 = 0xc019003f;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140032a1c;
    uVar6 = 0x31;
    uVar8 = 0x30;
  }
  else {
    piVar3 = (int *)WcGetUnionContext(param_1,*(undefined8 *)(param_2 + 0x18),
                                      *(undefined8 *)(param_2 + 0x20));
    if (piVar3 == (int *)0x0) goto LAB_140032a1c;
    if (5 < DAT_14000f060) {
      uVar4 = _tlgKeywordOn(0x14000f060,0x400000000000);
      if ((char)uVar4 != '\0') {
        local_a4 = 0;
        local_68 = &local_a4;
        local_5c = 0;
        local_90 = 0;
        local_4c = 0;
        local_58 = &local_90;
        local_60 = 4;
        local_50 = 8;
        uVar5 = IoGetSilo(*(undefined8 *)(param_2 + 0x20));
        local_a8 = PsGetSiloIdentifier(uVar5);
        local_3c = 0;
        local_48 = &local_a8;
        local_40 = 4;
        _tlgWriteTransfer_EtwWriteTransfer(0x14000f060,&DAT_14000b3f1,0,0,5,local_88);
      }
    }
    uVar4 = 0xc019003f;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140032a1c;
    uVar6 = 0x32;
    uVar8 = 0x4d;
  }
  uVar4 = 0xc019003f;
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,uVar6,
                      &WPP_f0814e6c447a328576e13f442d5bd6ed_Traceguids,
                      "onecore\\base\\fs\\wci\\wcifs\\create.c",uVar8,0x3f);
LAB_140032a1c:
  if (local_98 != 0) {
    FltReleaseFileNameInformation();
  }
  if (piVar3 != (int *)0x0) {
    WcReleaseUnionContext(piVar3);
  }
  return uVar4;
}



===== WcPostCleanup @ 140032d00 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 WcPostCleanup(longlong param_1,longlong param_2,longlong *param_3)

{
  int iVar1;
  ulonglong uVar2;
  longlong *plVar3;
  undefined2 uVar4;
  undefined1 auStackY_e8 [32];
  undefined1 uVar5;
  undefined1 local_a8;
  undefined1 local_a7;
  undefined1 local_a6 [2];
  int local_a4;
  longlong local_a0;
  longlong local_98;
  longlong local_90;
  undefined8 local_88 [4];
  undefined1 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined1 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  int *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_98 = 0;
  local_a0 = 0;
  local_a6[0] = 0;
  plVar3 = (longlong *)0x0;
  local_90 = param_1;
  if (param_3 == (longlong *)0x0) {
LAB_140033051:
    if ((((*(ulonglong *)(local_90 + 0x20) & 4) != 0) &&
        ((*(ulonglong *)(local_90 + 0x20) & 0x20) == 0)) &&
       (iVar1 = FltGetStreamContext(*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),
                                    &local_a0), -1 < iVar1)) {
      *(undefined1 *)(local_a0 + 0x1d) = 1;
      FltReleaseContext(local_a0);
    }
    if (plVar3 == (longlong *)0x0) goto LAB_1400330ea;
  }
  else {
    plVar3 = param_3;
    if (*(char *)((longlong)param_3 + 0x11) == '\0') {
      if (((*(byte *)(param_1 + 0x20) & 0xc) != 0) &&
         (local_a4 = WcCreateTombstone(*(undefined8 *)(param_2 + 0x18),*param_3 + 8,(char)param_3[2]
                                      ), local_a4 < 0)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0x3c,
                              &WPP_27ac746799d63ca1d37704ce911b8053_Traceguids,
                              "onecore\\base\\fs\\wci\\wcifs\\wcifs.c",0xb7,(char)local_a4);
        }
        if (5 < DAT_14000f060) {
          iVar1 = local_a4;
          uVar2 = _tlgKeywordOn(0x14000f060,0x400000000000);
          if ((char)uVar2 != '\0') {
            local_5c = 0;
            local_68 = &local_a8;
            local_4c = 0;
            local_3c = 0;
            local_58 = &local_a7;
            local_48 = &local_a4;
            local_a8 = 1;
            local_60 = 1;
            local_a7 = 5;
            local_50 = 1;
            local_40 = 4;
            local_a4 = iVar1;
            _tlgWriteTransfer_EtwWriteTransfer(0x14000f060,&DAT_14000bd9a,0,0,5,local_88);
          }
        }
      }
      iVar1 = WcRemoveInMemoryTombstone(*(undefined8 *)(param_2 + 0x18),*param_3,param_3[1]);
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x3d,
                              &WPP_27ac746799d63ca1d37704ce911b8053_Traceguids,
                              "onecore\\base\\fs\\wci\\wcifs\\wcifs.c",0xcb,(char)iVar1);
        }
        if ((5 < DAT_14000f060) &&
           (uVar2 = _tlgKeywordOn(0x14000f060,0x400000000000), (char)uVar2 != '\0')) {
          local_5c = 0;
          local_68 = &local_a7;
          local_4c = 0;
          local_3c = 0;
          local_58 = &local_a8;
          local_a7 = 2;
          local_48 = &local_a4;
          local_60 = 1;
          local_a8 = 5;
          local_50 = 1;
          local_40 = 4;
          local_a4 = iVar1;
          _tlgWriteTransfer_EtwWriteTransfer(0x14000f060,&DAT_14000bdf8,0,0,5,local_88);
        }
        goto LAB_140033096;
      }
      goto LAB_140033051;
    }
    iVar1 = ObReferenceObjectByHandle(param_3[3],0x10000,*(undefined8 *)IoFileObjectType_exref,0);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar4 = 0x3a;
        uVar5 = 0x97;
        goto LAB_140032db9;
      }
    }
    else {
      iVar1 = FltSetInformationFile(*(undefined8 *)(param_2 + 0x18),local_98,local_a6,1);
      if ((iVar1 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        uVar4 = 0x3b;
        uVar5 = 0xa5;
LAB_140032db9:
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,uVar4,
                            &WPP_27ac746799d63ca1d37704ce911b8053_Traceguids,
                            "onecore\\base\\fs\\wci\\wcifs\\wcifs.c",uVar5,(char)iVar1);
      }
    }
  }
LAB_140033096:
  if (*plVar3 != 0) {
    FltReleaseFileNameInformation();
  }
  if (plVar3[1] != 0) {
    ObfDereferenceObject();
  }
  if (plVar3[3] != 0) {
    FltClose();
  }
  ExFreeToPagedLookasideList(&DAT_14000f500,plVar3);
LAB_1400330ea:
  if (local_98 != 0) {
    ObfDereferenceObject();
  }
  return 0;
}



===== WcPreDirectoryControl @ 140033130 =====

int WcPreDirectoryControl(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  bool bVar5;
  bool bVar6;
  uint uVar7;
  int *piVar8;
  undefined8 *puVar9;
  ulonglong uVar10;
  int local_78;
  uint local_70 [2];
  longlong *local_68;
  longlong *local_60;
  int local_58;
  uint local_54;
  longlong local_50;
  longlong local_48;
  int *local_40;
  undefined8 *local_38;
  longlong *local_30;
  
  uVar7 = 0;
  local_78 = 1;
  piVar8 = (int *)0x0;
  local_48 = 0;
  local_50 = 0;
  local_70[0] = 0;
  plVar1 = (longlong *)(param_1 + 0x10);
  local_30 = plVar1;
  if (*(char *)(*plVar1 + 5) == '\x01') {
    local_68 = (longlong *)(param_2 + 0x20);
    local_60 = (longlong *)(param_2 + 0x18);
    piVar8 = (int *)WcGetUnionContext(param_1,*local_60,*local_68);
    local_40 = piVar8;
    if (piVar8 != (int *)0x0) {
      iVar2 = *(int *)(*plVar1 + 0x28);
      local_58 = iVar2;
      bVar5 = WcGetContextFileObject(*local_60,*local_68,&local_48,&local_50);
      if (((bVar5) || (iVar2 == 0x21)) ||
         (bVar6 = WcIsInstanceUnionRootDirectory(*local_60,*local_68), bVar6)) {
        if (iVar2 < 0x27) {
          if ((((iVar2 != 0x26) && (iVar2 != 1)) &&
              ((iVar2 != 2 && ((iVar2 != 3 && (iVar2 != 0xc)))))) &&
             ((iVar2 != 0x21 && (iVar2 != 0x25)))) goto LAB_140033449;
        }
        else if (((((iVar2 != 0x3c) && (iVar2 != 0x3f)) && (iVar2 != 0x4e)) &&
                 ((iVar2 != 0x4f && (iVar2 != 0x50)))) && (iVar2 != 0x51)) goto LAB_140033449;
        local_78 = 4;
        lVar4 = *plVar1;
        uVar3 = *(uint *)(lVar4 + 0x18);
        local_54 = uVar3;
        if (*(longlong *)(lVar4 + 0x40) == 0) {
          puVar9 = *(undefined8 **)(lVar4 + 0x38);
          local_38 = puVar9;
          if (*(char *)(param_1 + 0x50) != '\0') {
            ProbeForWrite(puVar9,uVar3,1);
          }
        }
        else {
          uVar7 = FltLockUserBuffer(param_1);
          if ((int)uVar7 < 0) goto LAB_140033449;
          lVar4 = *(longlong *)(*plVar1 + 0x40);
          if ((*(byte *)(lVar4 + 10) & 5) == 0) {
            puVar9 = (undefined8 *)MmMapLockedPagesSpecifyCache(lVar4,0,1,0,0,0x40000010);
          }
          else {
            puVar9 = *(undefined8 **)(lVar4 + 0x18);
          }
          if (puVar9 == (undefined8 *)0x0) {
            uVar7 = 0xc0000017;
            goto LAB_140033449;
          }
        }
        lVar4 = local_50;
        if (((!bVar5) ||
            (uVar10 = WcIsPlaceHolderDirectory(local_48,local_50), (char)uVar10 == '\0')) ||
           ((uVar10 = WcIsSourcedStream(lVar4), (char)uVar10 == '\0' || (iVar2 == 0x21)))) {
          lVar4 = *plVar1;
          uVar10 = WcEnumerateDirectoryWithMunge
                             (*local_60,*local_68,iVar2,*(undefined8 *)(lVar4 + 0x20),
                              *(undefined4 *)(lVar4 + 0x30),*(byte *)(lVar4 + 6),piVar8[9],
                              piVar8[10],uVar3,(longlong)puVar9,(int *)local_70);
          uVar7 = (uint)uVar10;
        }
        else {
          lVar4 = *plVar1;
          uVar7 = WcEnumerateDirectoryWithMerge
                            (*local_60,*local_68,iVar2,*(undefined8 **)(lVar4 + 0x20),
                             *(undefined4 *)(lVar4 + 0x30),*(byte *)(lVar4 + 6),uVar3,puVar9,
                             local_70);
        }
        if (((uVar7 + 0x80000000 & 0x80000000) != 0) || (uVar7 == 0x80000005)) {
          *(ulonglong *)(param_1 + 0x20) = (ulonglong)local_70[0];
        }
      }
    }
  }
LAB_140033449:
  if (local_78 == 4) {
    *(uint *)(param_1 + 0x18) = uVar7;
  }
  if (local_50 != 0) {
    FltReleaseContext(local_50);
  }
  if (local_48 != 0) {
    FltReleaseContext();
  }
  if (piVar8 != (int *)0x0) {
    WcReleaseUnionContext(piVar8);
  }
  return local_78;
}



===== WcRevertDelete @ 1400334b8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong WcRevertDelete(undefined8 param_1,longlong param_2)

{
  bool bVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined1 auStackY_148 [32];
  undefined1 local_108;
  undefined1 local_107;
  undefined2 local_106;
  longlong local_100;
  longlong local_f8;
  undefined8 local_f0;
  longlong lStack_e8;
  longlong local_e0;
  longlong local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  longlong local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 local_98 [4];
  undefined1 *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined1 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  longlong *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_148;
  local_e0 = 0;
  local_b8 = 0;
  local_f8 = 0;
  lVar5 = 0;
  local_100 = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  local_a0 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_f0 = 0;
  lStack_e8 = 0;
  uVar2 = FltQueryInformationFile
                    (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),&local_b0,0x18)
  ;
  uVar6 = (ulonglong)uVar2;
  if ((int)uVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x1d,
                          &WPP_6c993b8198b53d328fc429e03cc469de_Traceguids,
                          "onecore\\base\\fs\\wci\\wcifs\\tombstone.c",0x7e,(char)uVar2);
    }
  }
  else if ((((local_a0._6_1_ == '\0') &&
            (bVar1 = WcGetContextFileObject
                               (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),
                                &local_e0,&local_100), lVar5 = local_100, bVar1)) &&
           (local_100 != 0)) && (*(char *)(local_100 + 0x1c) != '\0')) {
    uVar2 = FltGetFileNameInformation(param_1,0x301,&local_f8);
    uVar6 = (ulonglong)uVar2;
    if (-1 < (int)uVar2) {
      local_f0._0_4_ = CONCAT22(*(short *)(local_f8 + 10) + 0x20a,(undefined2)local_f0);
      uVar3 = WcAllocateUnicodeString(0x6e664357,(undefined2 *)&local_f0);
      uVar6 = uVar3 & 0xffffffff;
      if (-1 < (int)uVar3) {
        RtlAppendUnicodeStringToString(&local_f0,local_f8 + 8);
        RtlAppendUnicodeToString(&local_f0,L"\\");
        local_106 = (undefined2)local_f0;
        KeWaitForSingleObject(lVar5 + 0xe8,0,0);
        lVar4 = *(longlong *)(lVar5 + 0x100);
        if ((lVar4 != 0) && (*(int *)(lVar4 + 0x14) != 0)) {
          RtlInitEnumerationHashTable(lVar4,&local_d8);
          lVar4 = RtlEnumerateEntryHashTable(*(undefined8 *)(lVar5 + 0x100),&local_d8);
          while (lVar4 != 0) {
            uVar6 = (ulonglong)local_f0 >> 0x10;
            local_f0 = CONCAT62((int6)uVar6,local_106);
            RtlAppendUnicodeStringToString(&local_f0,lVar4 + 0x20);
            uVar2 = WcCreateTombstone(*(undefined8 *)(param_2 + 0x18),&local_f0,
                                      *(char *)(lVar4 + 0x18));
            uVar6 = (ulonglong)uVar2;
            if ((int)uVar2 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x1e,
                                    &WPP_6c993b8198b53d328fc429e03cc469de_Traceguids,
                                    "onecore\\base\\fs\\wci\\wcifs\\tombstone.c",0xc5,(char)uVar2);
              }
              if ((5 < DAT_14000f060) &&
                 (uVar3 = _tlgKeywordOn(0x14000f060,0x400000000000), (char)uVar3 != '\0')) {
                local_6c = 0;
                local_78 = &local_108;
                local_5c = 0;
                local_4c = 0;
                local_68 = &local_107;
                local_108 = 1;
                local_58 = &local_100;
                local_70 = 1;
                local_60 = 1;
                local_107 = 6;
                local_100 = CONCAT44(local_100._4_4_,uVar2);
                local_50 = 4;
                _tlgWriteTransfer_EtwWriteTransfer(0x14000f060,&DAT_14000baeb,0,0,5,local_98);
              }
            }
            RtlRemoveEntryHashTable(*(undefined8 *)(lVar5 + 0x100),lVar4,0);
            ExFreePoolWithTag(lVar4,0x74684357);
            lVar4 = RtlEnumerateEntryHashTable(*(undefined8 *)(lVar5 + 0x100),&local_d8);
          }
          RtlEndEnumerationHashTable(*(undefined8 *)(lVar5 + 0x100),&local_d8);
        }
        KeSetEvent(lVar5 + 0xe8,0,0);
        if (lStack_e8 != 0) {
          ExFreePoolWithTag(lStack_e8,0x6e664357);
        }
      }
    }
  }
  if (local_f8 != 0) {
    FltReleaseFileNameInformation();
  }
  if (local_e0 != 0) {
    FltReleaseContext();
  }
  if (lVar5 != 0) {
    FltReleaseContext(lVar5);
  }
  return uVar6;
}



===== WcPrePnp @ 140033920 =====

ulonglong WcPrePnp(longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  
  uVar1 = 1;
  if (*(char *)(*(longlong *)(param_1 + 0x10) + 5) == '\x01') {
    uVar1 = WcPreDismountLockRemove(param_1,param_2);
    uVar1 = uVar1 & 0xffffffff;
  }
  return uVar1;
}



===== WcAllocateUnicodeString @ 140033950 =====

undefined8 WcAllocateUnicodeString(undefined4 param_1,undefined2 *param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = ExAllocatePool2(0x100,param_2[1],param_1);
  *(longlong *)(param_2 + 4) = lVar1;
  if (lVar1 == 0) {
    uVar2 = 0xc000009a;
  }
  else {
    *param_2 = 0;
    uVar2 = 0;
  }
  return uVar2;
}



===== WcPartiallyExpandDirectory @ 140033998 =====

ulonglong WcPartiallyExpandDirectory
                    (undefined8 param_1,longlong param_2,longlong param_3,longlong param_4,
                    char param_5,wchar_t *param_6)

{
  longlong lVar1;
  longlong lVar2;
  bool bVar3;
  char cVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  longlong local_58;
  longlong local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  local_50 = 0;
  local_58 = 0;
  uVar9 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  bVar3 = WcGetContextFileObject(param_2,param_3,&local_50,&local_58);
  lVar2 = local_50;
  lVar1 = local_58;
  if (!bVar3) goto LAB_140033bc4;
  cVar4 = ExAcquireRundownProtection(local_50 + 0x48);
  if (cVar4 == '\0') {
    uVar7 = WcExpandAndWait(param_1,param_2,param_3,lVar2,2,8);
    uVar9 = (ulonglong)uVar7;
    if ((int)uVar7 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDdZ
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0x25,
                   &WPP_258dc4bb20423ae59ba1107eb987efad_Traceguids,
                   "onecore\\base\\fs\\wci\\wcifs\\expansion.c",0xa5,(char)uVar7,
                   (wchar_t *)&local_48);
      }
      goto LAB_140033bc4;
    }
    if (param_5 != '\0') goto LAB_140033bc4;
    bVar5 = WcIsExpanded(lVar2);
    if (bVar5 == 0) {
      uVar9 = WcPopulateFile(param_6,(longlong *)(lVar1 + 0x38),*(undefined4 **)(lVar2 + 0x40),
                             param_2,param_4,param_3,'\x01','\x01');
      uVar9 = uVar9 & 0xffffffff;
      goto LAB_140033bb7;
    }
  }
  else {
    bVar5 = WcIsExpanded(lVar2);
    if (bVar5 == 0) {
      uVar8 = WcIsPlaceHolderDirectory(lVar2,lVar1);
      if ((char)uVar8 != '\0') {
        uStack_40 = *(undefined8 *)(param_6 + 4);
        local_48 = CONCAT44(local_48._4_4_,*(undefined4 *)param_6);
        if (param_5 != '\0') {
          RtlInitUnicodeString(&local_38,0);
          iVar6 = FltParseFileName(&local_48,0,&local_38,0);
          if ((-1 < iVar6) && ((short)local_38 != 0)) {
            local_48 = CONCAT62(local_48._2_6_,(wchar_t)local_48 - (short)local_38);
          }
        }
        uVar9 = WcPopulateFile((wchar_t *)&local_48,(longlong *)(lVar1 + 0x38),
                               *(undefined4 **)(lVar2 + 0x40),param_2,param_4,param_3,'\x01','\0');
        uVar9 = uVar9 & 0xffffffff;
      }
    }
    else {
      uVar9 = 0xc0000034;
    }
    ExReleaseRundownProtection(lVar2 + 0x48);
    if (param_5 != '\0') goto LAB_140033bc4;
LAB_140033bb7:
    if ((int)uVar9 != -0x3fffffcc) goto LAB_140033bc4;
  }
  uVar9 = 0xc000003a;
LAB_140033bc4:
  if (lVar2 != 0) {
    FltReleaseContext(lVar2);
  }
  if (lVar1 != 0) {
    FltReleaseContext(lVar1);
  }
  return uVar9;
}



===== TlgAggregateInternalProviderCallback @ 140033c20 =====

/* void __cdecl TlgAggregateInternalProviderCallback(struct _GUID const * __ptr64,unsigned
   long,unsigned char,unsigned __int64,unsigned __int64,struct _EVENT_FILTER_DESCRIPTOR *
   __ptr64,void * __ptr64) */

void __cdecl
TlgAggregateInternalProviderCallback
          (_GUID *param_1,ulong param_2,uchar param_3,__uint64 param_4,__uint64 param_5,
          _EVENT_FILTER_DESCRIPTOR *param_6,void *param_7)

{
  char cVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined7 in_register_00000081;
  
  if (param_2 != 2) {
    return;
  }
  if (param_4 == 0x20) {
    uVar2 = 0;
    cVar1 = ExTryAcquirePushLockExclusiveEx(&DAT_14000f740);
    if (cVar1 != '\0') {
      for (lVar3 = DAT_14000f748; lVar3 != 0; lVar3 = *(longlong *)(lVar3 + 0x160)) {
        LookUpTableFlushComplete
                  (lVar3,uVar2,CONCAT71(in_register_00000081,param_3),(_GUID *)param_4);
      }
      ExReleasePushLockExclusiveEx(&DAT_14000f740,0);
    }
  }
  return;
}



===== WcAcknowledgeRedirectionEcp @ 140033c8c =====

void WcAcknowledgeRedirectionEcp(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  longlong lVar2;
  longlong lVar3;
  bool bVar4;
  int iVar5;
  ulonglong uVar6;
  longlong lVar7;
  uint local_res20 [2];
  longlong local_28;
  undefined8 local_20;
  longlong local_18;
  longlong local_10;
  
  local_20 = 0;
  local_28 = 0;
  local_18 = 0;
  local_10 = 0;
  local_res20[0] = 0;
  iVar5 = FltGetEcpListFromCallbackData(Globals,param_1,&local_20);
  if (iVar5 < 0) {
    return;
  }
  iVar5 = FltFindExtraCreateParameter
                    (Globals,local_20,&GUID_ECP_CREATE_REDIRECTION,&local_28,local_res20);
  if (iVar5 < 0) {
    return;
  }
  *(ushort *)(local_28 + 2) = *(ushort *)(local_28 + 2) | 2;
  bVar4 = WcGetContextFileObject(param_2,param_3,&local_18,&local_10);
  lVar3 = local_10;
  lVar2 = local_18;
  if ((bVar4) &&
     (((uVar6 = WcIsPlaceHolderStream(local_18,local_10), (char)uVar6 != '\0' ||
       (uVar6 = WcIsPlaceHolderDirectory(lVar2,lVar3), (char)uVar6 != '\0')) &&
      (uVar6 = WcIsSourcedStream(lVar3), (char)uVar6 != '\0')))) {
    lVar7 = WcGetSource(lVar3);
    *(ushort *)(local_28 + 2) = *(ushort *)(local_28 + 2) & 0xfffd;
    *(ushort *)(local_28 + 2) = *(ushort *)(local_28 + 2) | 1;
    if ((*(uint *)(*(longlong *)(lVar7 + 0x20) + 0x10) & 2) != 0) {
      *(ushort *)(local_28 + 2) = *(ushort *)(local_28 + 2) | 4;
    }
    if ((*(uint *)(*(longlong *)(lVar7 + 0x20) + 0x10) & 1) == 0) {
      if (0x23 < local_res20[0]) {
        uVar1 = *(undefined8 *)(lVar3 + 0x5c);
        *(undefined8 *)(local_28 + 4) = *(undefined8 *)(lVar3 + 0x54);
        *(undefined8 *)(local_28 + 0xc) = uVar1;
        uVar1 = *(undefined8 *)(lVar3 + 0x6c);
        *(undefined8 *)(local_28 + 0x14) = *(undefined8 *)(lVar3 + 100);
        *(undefined8 *)(local_28 + 0x1c) = uVar1;
      }
    }
    else {
      *(ushort *)(local_28 + 2) = *(ushort *)(local_28 + 2) | 8;
    }
  }
  FltAcknowledgeEcp(Globals,local_28);
  if (lVar2 != 0) {
    FltReleaseContext(lVar2);
  }
  if (lVar3 != 0) {
    FltReleaseContext(lVar3);
  }
  return;
}



===== WcReferenceUnionContext @ 140033e2c =====

void WcReferenceUnionContext(int *param_1)

{
  LOCK();
  *param_1 = *param_1 + 1;
  UNLOCK();
  return;
}



===== WcParseNextPathComponentName @ 140033e38 =====

undefined8 WcParseNextPathComponentName(ushort *param_1,short *param_2,undefined1 *param_3)

{
  ushort uVar1;
  short *psVar2;
  undefined8 uVar3;
  ushort uVar4;
  undefined1 uVar5;
  
  psVar2 = *(short **)(param_1 + 4);
  if ((*psVar2 == 0x5c) &&
     ((uVar1 = *param_1, psVar2[(ulonglong)(uVar1 >> 1) - 1] != 0x5c || (uVar1 != 2)))) {
    for (uVar4 = 4; uVar5 = 0, uVar4 <= uVar1; uVar4 = uVar4 + 2) {
      if (psVar2[(ulonglong)(uVar4 >> 1) - 1] == 0x5c) {
        uVar5 = 0;
        if (uVar4 == uVar1) {
          uVar5 = 1;
        }
        break;
      }
    }
    *(short **)(param_2 + 4) = psVar2 + 1;
    if ((ushort)(uVar4 - 2) == uVar1) {
      uVar5 = 1;
    }
    *param_2 = uVar4 - 4;
    uVar3 = 0;
    param_2[1] = uVar4 - 4;
    *param_3 = uVar5;
  }
  else {
    uVar3 = 0xc000000d;
  }
  return uVar3;
}



===== WcCompareLayerTableEntry @ 140033ee0 =====

undefined8 WcCompareLayerTableEntry(undefined8 param_1,undefined8 *param_2,undefined8 *param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = memcmp((void *)*param_2,(void *)*param_3,0x10);
  if (iVar1 < 1) {
    uVar2 = 2;
    if (iVar1 < 0) {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



===== WcPostDismountVolume @ 140033f1c =====

void WcPostDismountVolume(longlong param_1,longlong param_2)

{
  uint *puVar1;
  int iVar2;
  longlong *plVar3;
  undefined8 uVar4;
  longlong local_res8 [4];
  
  local_res8[0] = 0;
  if (*(int *)(param_1 + 0x18) < 0) {
    return;
  }
  iVar2 = FltGetInstanceContext(*(undefined8 *)(param_2 + 0x18),local_res8);
  if (iVar2 < 0) {
    return;
  }
  if (*(longlong *)(local_res8[0] + 0x38) == 0) {
    if (*(int *)(local_res8[0] + 0x40) == 0) goto LAB_140034013;
    ExAcquireFastMutex(&DAT_14000f208);
    FltAcquireResourceExclusive(local_res8[0] + 0x48);
    uVar4 = 1;
    while (plVar3 = (longlong *)RtlEnumerateGenericTableAvl(local_res8[0] + 0xb0,uVar4),
          plVar3 != (longlong *)0x0) {
      DAT_14000f244 = DAT_14000f244 + -1;
      *(uint *)(*plVar3 + 0x20) = *(uint *)(*plVar3 + 0x20) & 0xfffffffe;
      uVar4 = 0;
    }
    FltReleaseResource(local_res8[0] + 0x48);
  }
  else {
    ExAcquireFastMutex(&DAT_14000f208);
    DAT_14000f244 = DAT_14000f244 + -1;
    puVar1 = (uint *)(*(longlong *)(local_res8[0] + 0x38) + 0x20);
    *puVar1 = *puVar1 & 0xfffffffe;
  }
  ExReleaseFastMutex(&DAT_14000f208);
LAB_140034013:
  FltReleaseContext(local_res8[0]);
  return;
}



===== WcContextCleanup @ 140034030 =====

void WcContextCleanup(longlong *param_1,short param_2)

{
  int iVar1;
  undefined8 *puVar2;
  int *piVar3;
  
  piVar3 = DAT_14000f688;
  if (param_2 == 2) {
    if ((DAT_14000f680 != '\0') && (DAT_14000f688 != (int *)0x0)) {
      ExAcquireFastMutex(&DAT_14000f208);
      iVar1 = *piVar3;
      puVar2 = (undefined8 *)param_1[4];
      *(undefined8 *)(piVar3 + (longlong)iVar1 * 3 + 1) = *puVar2;
      piVar3[(longlong)iVar1 * 3 + 3] = *(int *)(puVar2 + 1);
      *piVar3 = (*piVar3 + 1) % 3;
      ExReleaseFastMutex(&DAT_14000f208);
    }
    if ((int *)param_1[7] == (int *)0x0) {
      if ((int)param_1[8] != 0) {
        WcClearUnionTable(param_1 + 0x16);
        *(undefined4 *)(param_1 + 8) = 0;
      }
    }
    else {
      WcReleaseUnionContext((int *)param_1[7]);
    }
    ExDeleteResourceLite(param_1 + 9);
  }
  else if (param_2 == 4) {
    FltReleaseContext(*param_1);
    if (param_1[10] != 0) {
      ExFreeToNPagedLookasideList(&DAT_14000f580);
    }
    if (param_1[8] != 0) {
      ExFreePoolWithTag(param_1[8],0x69724357);
    }
  }
  else if (param_2 == 8) {
    if (param_1[0x20] != 0) {
      WcFreeInMemoryTombstoneHashTable(param_1[0x20]);
    }
    ExDeleteResourceLite(param_1 + 0xf);
    WcFreeSourceList(param_1 + 7);
    FltReleaseContext(param_1[4]);
    WcReleaseUnionContext((int *)param_1[5]);
    if (((longlong *)*param_1 != param_1) &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,9,10,
                         &WPP_2b73349c3ae735a72745210a57314671_Traceguids,
                         "onecore\\base\\fs\\wci\\wcifs\\context.c",0xeb);
    }
  }
  else if (param_2 == 0x10) {
    WcFreeEnumContexts(param_1);
    WcFreeSourceList(param_1 + 6);
    if (param_1[8] != 0) {
      FltReleaseContext();
    }
  }
  return;
}



===== WcPortConnect @ 140034240 =====

undefined8 WcPortConnect(undefined8 param_1)

{
  undefined8 *in_stack_00000028;
  
  *in_stack_00000028 = param_1;
  return 0;
}



===== WcPortDisconnect @ 140034260 =====

void WcPortDisconnect(undefined8 param_1)

{
  undefined8 local_res8 [4];
  
  local_res8[0] = param_1;
  FltCloseClientPort(Globals,local_res8);
  return;
}



===== WcLookupDirectoryTableEntry @ 140034290 =====

int WcLookupDirectoryTableEntry(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  undefined4 local_res20 [2];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_28 = 0;
  local_res20[0] = 0;
  iVar2 = RtlHashUnicodeString(param_2,0,0,local_res20);
  if (-1 < iVar2) {
    local_38 = 0;
    uStack_30 = 0;
    iVar2 = -0x3fffffc6;
    FltAcquireResourceShared(*(undefined8 *)(param_1 + 0x40));
    lVar3 = RtlLookupEntryHashTable(param_1 + 0x48,local_res20[0],&local_38);
    while (lVar3 != 0) {
      cVar1 = RtlEqualUnicodeString(param_2,lVar3 + 0x18,0);
      if (cVar1 != '\0') {
        iVar2 = 0;
        *param_3 = *(undefined8 *)(lVar3 + 0x28);
        break;
      }
      lVar3 = RtlGetNextEntryHashTable(param_1 + 0x48,&local_38);
    }
    FltReleaseResource(*(undefined8 *)(param_1 + 0x40));
  }
  return iVar2;
}



===== WcFsctlRedirectDirectMappedRequest @ 140034388 =====

undefined8 WcFsctlRedirectDirectMappedRequest(longlong param_1,longlong param_2)

{
  byte bVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  longlong lVar6;
  longlong local_res10;
  
  local_res10 = 0;
  uVar5 = 1;
  iVar2 = FltGetStreamContext(*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),
                              &local_res10);
  if (-1 < iVar2) {
    lVar6 = local_res10;
    uVar3 = WcUsesSourceSectionObjectPointers(*(longlong *)(param_2 + 0x20),local_res10);
    if ((char)uVar3 == '\0') {
      bVar1 = WcIsPlaceHolder(*(longlong *)(lVar6 + 0x20));
      if (bVar1 != 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDqd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,0x13,
                     &WPP_6905edae906b30b18cb12ec0224aaf5b_Traceguids,
                     "onecore\\base\\fs\\wci\\wcifs\\fsctrl.c",0x8a,
                     (char)*(undefined8 *)(param_2 + 0x20),0xbb);
        }
        *(undefined4 *)(param_1 + 0x18) = 0xc00000bb;
        uVar5 = 4;
      }
    }
    else {
      puVar4 = (undefined8 *)WcGetSource(lVar6);
      *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 8) = puVar4[2];
      *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x10) = *puVar4;
      FltSetCallbackDataDirty(param_1);
    }
    FltReleaseContext(local_res10);
  }
  return uVar5;
}



===== WcCopyFileDataStreams @ 1400344ac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000140034601) */
/* WARNING: Removing unreachable block (ram,0x00014003460b) */
/* WARNING: Removing unreachable block (ram,0x00014003460e) */
/* WARNING: Removing unreachable block (ram,0x0001400346d1) */
/* WARNING: Removing unreachable block (ram,0x0001400346d7) */
/* WARNING: Removing unreachable block (ram,0x000140034727) */
/* WARNING: Removing unreachable block (ram,0x000140034737) */
/* WARNING: Removing unreachable block (ram,0x000140034645) */
/* WARNING: Removing unreachable block (ram,0x00014003464f) */
/* WARNING: Removing unreachable block (ram,0x000140034686) */
/* WARNING: Removing unreachable block (ram,0x0001400346a9) */
/* WARNING: Removing unreachable block (ram,0x0001400346bd) */
/* WARNING: Removing unreachable block (ram,0x000140034719) */
/* WARNING: Removing unreachable block (ram,0x00014003471f) */

int WcCopyFileDataStreams
              (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              undefined8 param_5,undefined8 param_6,byte param_7)

{
  int iVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  
  lVar2 = 0;
  if ((param_7 & 3) == 0) {
    iVar1 = -0x3ffffff3;
  }
  else {
    uVar4 = 0x20;
    do {
      if (lVar2 != 0) {
        ExFreePoolWithTag(lVar2,0x69664357);
      }
      uVar4 = uVar4 + 0x800;
      uVar3 = 0x20;
      if (0x1f < uVar4) {
        uVar3 = uVar4;
      }
      lVar2 = ExAllocatePool2(0x100,uVar3,0x69664357);
      if (lVar2 == 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xf,0x70,
                              &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                              "onecore\\base\\fs\\wci\\wcifs\\utils.c",100,(char)uVar4);
        }
        return -0x3fffffe9;
      }
      iVar1 = FltQueryInformationFile(param_3,param_2,lVar2,uVar4);
    } while ((iVar1 == -0x7ffffffb) || (iVar1 == -0x3fffffdd));
    if (iVar1 < 0) {
      if ((iVar1 == -0x3ffffff3) || (iVar1 == -0x3ffffffe)) {
        iVar1 = 0;
      }
      else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xf,0x71,
                            &WPP_34d8ecac7c903bfc06060a0eb8877f13_Traceguids,
                            "onecore\\base\\fs\\wci\\wcifs\\utils.c",0x81,(char)iVar1);
      }
    }
    ExFreePoolWithTag(lVar2,0x69664357);
  }
  return iVar1;
}



===== WcEnumerateDirectorySingleEntry @ 14003480c =====

ulonglong WcEnumerateDirectorySingleEntry
                    (longlong param_1,undefined8 param_2,undefined8 param_3,int param_4,int param_5,
                    undefined8 param_6,undefined4 param_7,byte param_8,uint param_9,
                    undefined1 param_10,uint param_11,undefined8 *param_12,uint *param_13)

{
  bool bVar1;
  uint uVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  char cVar7;
  undefined8 local_res10;
  undefined8 uVar8;
  
  _param_10 = 0;
  cVar7 = '\x01';
  puVar5 = (undefined8 *)0x0;
  puVar3 = (undefined8 *)ExAllocatePool2(0x100,param_7,0x6e654357);
  if (puVar3 == (undefined8 *)0x0) {
    uVar4 = 0xc000009a;
  }
  else {
    do {
      if (puVar5 != (undefined8 *)0x0) {
        param_2 = *(undefined8 *)puVar5[3];
        param_3 = ((undefined8 *)puVar5[3])[2];
      }
      puVar6 = puVar3;
      uVar8 = param_6;
      uVar2 = FltQueryDirectoryFileEx
                        (param_2,param_3,puVar3,param_7,param_4,param_8 | 0x10,param_6,&param_10);
      uVar4 = (ulonglong)uVar2;
      if (-1 < (int)uVar2) {
        bVar1 = WcShouldSkipReparsePointInDirectoryEntry
                          (param_4,-0x5fffffe1,puVar6,(longlong)puVar3);
        if (bVar1) {
          uVar4 = 0xc000000f;
        }
        else {
          uVar4 = WcMungeDirectoryEntry
                            (param_4,param_5,'\x01',cVar7,param_9,0xfff0000,uVar8,puVar3,param_11,
                             param_12,&local_res10,param_13);
          uVar4 = uVar4 & 0xffffffff;
        }
        break;
      }
      if ((uVar2 != 0xc000000f) && (uVar2 != 0x80000006)) break;
      if (puVar5 == (undefined8 *)0x0) {
        puVar5 = *(undefined8 **)(param_1 + 0x38);
      }
      else {
        puVar5 = (undefined8 *)*puVar5;
      }
      cVar7 = '\0';
    } while (puVar5 != (undefined8 *)(param_1 + 0x38));
    ExFreePoolWithTag(puVar3,0x6e654357);
  }
  return uVar4;
}



===== WcFastLookupInLayer @ 1400349b4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong WcFastLookupInLayer(undefined8 param_1,longlong param_2,undefined8 param_3,char param_4)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined1 auStack_a8 [32];
  undefined4 local_88;
  undefined4 local_80;
  undefined8 local_78;
  undefined8 local_70;
  longlong local_68;
  longlong local_60;
  longlong local_58;
  undefined8 local_50;
  longlong lStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_a8;
  local_68 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  lStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  uVar2 = FltGetInstanceContext(0,&local_68);
  uVar5 = (ulonglong)uVar2;
  if (*(longlong *)(local_68 + 0x38) == 0) goto LAB_140034ad1;
  local_50._0_4_ = CONCAT22(*(undefined2 *)(param_2 + 0x18),*(undefined2 *)(param_2 + 0x18));
  lStack_48 = param_2 + 0x1a;
  uVar4 = WcLookupLayer(*(longlong *)(local_68 + 0x38),
                        (longlong *)(*(longlong *)(local_68 + 0x38) + 0xa8),
                        (longlong *)(param_2 + 8),&local_60);
  lVar1 = local_60;
  uVar5 = uVar4 & 0xffffffff;
  if (-1 < (int)uVar4) {
    if ((*(uint *)(local_60 + 0x10) & 0x24) != 0) goto LAB_140034ad1;
    uVar2 = WcLookupDirectoryTableEntry(local_60,&local_50,&local_58);
    if ((int)uVar2 < 0) {
      uVar5 = 0;
      if (uVar2 != 0xc000003a) {
        uVar5 = (ulonglong)uVar2;
      }
      goto LAB_140034ad1;
    }
    local_70 = 0;
    local_80 = 0x13;
    local_88 = 0xc;
    local_78 = param_3;
    iVar3 = FltQueryDirectoryFileEx
                      (*(undefined8 *)(lVar1 + 0x28),*(undefined8 *)(local_58 + 0x10),&local_40,0x10
                      );
    if ((iVar3 != -0x3ffffff1) && (iVar3 != -0x7ffffffa)) {
      uVar5 = 0;
      goto LAB_140034ad1;
    }
  }
  uVar5 = (ulonglong)((-(uint)(param_4 != '\0') & 0xfffffffa) + 0xc000003a);
LAB_140034ad1:
  if (local_68 != 0) {
    FltReleaseContext();
  }
  return uVar5;
}



===== WcPortMessage @ 140034b10 =====

undefined8
WcPortMessage(undefined8 param_1,void *param_2,uint param_3,uint *param_4,uint param_5,uint *param_6
             )

{
  int iVar1;
  uint uVar2;
  int *_Dst;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined2 uVar5;
  uint local_res18 [4];
  undefined1 uVar6;
  
  uVar3 = (ulonglong)param_3;
  uVar4 = 0;
  _Dst = (int *)0x0;
  local_res18[0] = 0;
  if (param_3 < 0xc) {
    uVar4 = 0xc000000d;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14003503b;
    uVar5 = 0x46;
    uVar6 = 0x18;
  }
  else if (param_5 < 0xc) {
    uVar4 = 0xc000000d;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14003503b;
    uVar5 = 0x47;
    uVar6 = 0x1e;
  }
  else {
    _Dst = (int *)ExAllocatePool2(0x100,uVar3,0x746d4357);
    if (_Dst == (int *)0x0) {
      uVar4 = 0xc000009a;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDDd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),&WPP_RECORDER_INITIALIZED,0xe,0x48,
                   &WPP_52759b377eea39e2466a1234853e56fe_Traceguids,
                   "onecore\\base\\fs\\wci\\wcifs\\message.c",0x26,(char)param_3,0x9a);
      }
      goto LAB_14003503b;
    }
    ProbeForRead(param_2,uVar3,1);
    ProbeForWrite(param_4,(ulonglong)param_5,1);
    memmove(_Dst,param_2,uVar3);
    uVar2 = _Dst[1];
    uVar3 = (ulonglong)uVar2;
    if (uVar2 == param_3) {
      iVar1 = *_Dst;
      if (iVar1 == 0) {
        *param_4 = 1;
        param_4[1] = 0xc;
        uVar3 = WcSetUnionContext(_Dst + 2,_Dst[1] - 8,0xfff0000);
        uVar2 = (uint)uVar3;
        goto LAB_140035021;
      }
      if (iVar1 == 2) {
        if (uVar2 < 0xac) {
          uVar4 = 0xc000000d;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_14003503b;
          uVar5 = 0x4c;
          uVar6 = 0x69;
        }
        else {
          if (uVar3 == (ulonglong)(uint)_Dst[3] + 8) {
            *param_4 = 3;
            param_4[1] = 0xc;
            uVar3 = WcCopyAsPlaceHolderHandler(_Dst + 2,_Dst[1] - 8);
            uVar2 = (uint)uVar3;
            goto LAB_140035021;
          }
          uVar4 = 0xc000000d;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_14003503b;
          uVar5 = 0x4f;
          uVar6 = 0x7f;
        }
      }
      else if (iVar1 == 4) {
        if (uVar2 < 0x9a) {
          uVar4 = 0xc000000d;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_14003503b;
          uVar5 = 0x50;
          uVar6 = 0x97;
        }
        else {
          if (uVar3 == (ulonglong)(uint)_Dst[3] + 8) {
            *param_4 = 5;
            param_4[1] = 0xc;
            uVar3 = WcCopyFileHandler(_Dst + 2,_Dst[1] - 8);
            uVar2 = (uint)uVar3;
            goto LAB_140035021;
          }
          uVar4 = 0xc000000d;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_14003503b;
          uVar5 = 0x53;
          uVar6 = 0xad;
        }
      }
      else {
        if (iVar1 != 6) {
          if (iVar1 == 8) {
            *param_4 = 9;
            param_4[1] = 0xc;
            uVar3 = WcRemoveUnionContext(_Dst + 2,_Dst[1] - 8);
            uVar2 = (uint)uVar3;
          }
          else {
            if (iVar1 != 10) {
              if (iVar1 == 0xc) {
                if (uVar2 < 0x18) {
                  uVar4 = 0xc000000d;
                  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                  goto LAB_14003503b;
                  uVar5 = 0x5c;
                  uVar6 = 0x2f;
                }
                else {
                  if (0x1b < param_5) {
                    memset(param_4,0,(ulonglong)param_5);
                    uVar2 = WcProcessGetUnions((ulonglong)(_Dst + 2),param_5,(longlong)param_4,
                                               local_res18);
                    param_4[1] = uVar2;
                    *param_4 = local_res18[0];
                    *param_6 = local_res18[0];
                    goto LAB_14003503b;
                  }
                  uVar4 = 0xc000000d;
                  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                  goto LAB_14003503b;
                  uVar5 = 0x5d;
                  uVar6 = 0x37;
                }
              }
              else {
                uVar4 = 0xc000000d;
                if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                goto LAB_14003503b;
                uVar5 = 0x5f;
                uVar6 = 0x54;
              }
              goto LAB_140034b67;
            }
            *param_4 = 0xb;
            param_4[1] = 0xc;
            uVar3 = WcSetUnion(_Dst + 2,_Dst[1] - 8);
            uVar2 = (uint)uVar3;
          }
LAB_140035021:
          param_4[2] = uVar2;
          *param_6 = 0xc;
          goto LAB_14003503b;
        }
        if (uVar2 < 0x7c) {
          uVar4 = 0xc000000d;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_14003503b;
          uVar5 = 0x54;
          uVar6 = 0xc5;
        }
        else {
          if (uVar3 == (ulonglong)(uint)_Dst[3] + 8) {
            *param_4 = 7;
            param_4[1] = 0xc;
            uVar2 = WcSetupVolumeInformationHandler(_Dst + 2,_Dst[1] - 8);
            goto LAB_140035021;
          }
          uVar4 = 0xc000000d;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_14003503b;
          uVar5 = 0x57;
          uVar6 = 0xdb;
        }
      }
    }
    else {
      uVar4 = 0xc000000d;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14003503b;
      uVar5 = 0x49;
      uVar6 = 0x40;
    }
  }
LAB_140034b67:
  uVar4 = 0xc000000d;
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xe,uVar5,
                      &WPP_52759b377eea39e2466a1234853e56fe_Traceguids,
                      "onecore\\base\\fs\\wci\\wcifs\\message.c",uVar6,0xd);
LAB_14003503b:
  if (_Dst != (int *)0x0) {
    ExFreePoolWithTag(_Dst,0x746d4357);
  }
  return uVar4;
}



===== WcValidateWcReparseInfo @ 140035078 =====

uint WcValidateWcReparseInfo(longlong param_1,uint param_2)

{
  uint uVar1;
  ulonglong uVar2;
  ushort local_res10 [4];
  
  local_res10[0] = 0;
  if (((7 < param_2) && (*(ushort *)(param_1 + 4) + 8 <= param_2)) &&
     (0x19 < *(ushort *)(param_1 + 4))) {
    uVar2 = Feature_944920889__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar2 != 0) {
      uVar1 = WcValidateReparseInfo((uint *)(param_1 + 8),*(ushort *)(param_1 + 4));
      return uVar1;
    }
    if (((*(uint *)(param_1 + 8) < 2) && ((*(ushort *)(param_1 + 0x20) & 1) == 0)) &&
       ((uVar1 = RtlUShortAdd(0x1a,*(ushort *)(param_1 + 0x20),local_res10), -1 < (int)uVar1 &&
        (local_res10[0] <= *(ushort *)(param_1 + 4))))) {
      return 0;
    }
  }
  return 0xc0000102;
}



===== WcNormalizeNameComponent @ 140035110 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint WcNormalizeNameComponent
               (longlong param_1,undefined8 param_2,ushort *param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,uint param_7,byte param_8)

{
  undefined8 uVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  longlong lVar5;
  int *piVar6;
  undefined8 ***pppuVar7;
  ulonglong uVar8;
  undefined8 ***pppuVar9;
  byte bVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined8 uVar13;
  undefined2 uVar14;
  undefined1 auStack_1a8 [8];
  undefined1 auStack_1a0 [24];
  undefined8 local_188;
  undefined8 *local_180;
  undefined8 ***local_178;
  undefined8 local_170;
  undefined4 local_168;
  undefined4 local_160;
  undefined4 local_158;
  undefined4 local_150;
  undefined8 local_148;
  undefined4 local_140;
  undefined4 local_138;
  undefined8 *local_130;
  undefined8 local_128;
  longlong local_120;
  undefined8 ***local_118;
  longlong local_110;
  longlong local_108;
  longlong local_100;
  longlong local_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  ushort *local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  ulonglong uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  longlong lStack_a0;
  undefined8 local_98;
  undefined8 *puStack_90;
  undefined8 local_88;
  undefined8 **local_80;
  undefined8 uStack_78;
  undefined8 ***local_70;
  undefined8 ***pppuStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  ulonglong local_40;
  
  puVar12 = auStack_1a8;
  local_40 = __security_cookie ^ (ulonglong)auStack_1a8;
  local_128 = param_5;
  local_b0 = param_6;
  local_118 = (undefined8 ***)0x0;
  local_70 = (undefined8 ***)0x0;
  pppuStack_68 = (undefined8 ***)0x0;
  local_108 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_110 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_120 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_d0 = 0;
  local_f0 = 0;
  uStack_e8 = 0;
  uStack_c8 = uStack_c8 & 0xffffffff00000000;
  local_e0 = (ushort *)0x0;
  uStack_d8 = 0;
  local_100 = 0;
  local_80 = (undefined8 **)0x0;
  uStack_78 = 0;
  local_f8 = 0;
  if (param_7 < 0x10) {
    uVar3 = 0xc000000d;
    goto LAB_1400357ff;
  }
  lStack_a0 = 0;
  local_a8 = 0x28;
  local_98 = 0;
  puStack_90 = (undefined8 *)0x0;
  local_88 = 1;
  lVar5 = IoGetTransactionParameterBlock(param_2);
  if (lVar5 != 0) {
    uStack_b8 = *(undefined8 *)(lVar5 + 8);
    local_c0 = CONCAT44(local_c0._4_4_,0xfffe0010);
    puStack_90 = &local_c0;
  }
  piVar6 = WcpGetUnionContext(0,param_1,param_2,param_3);
  if (piVar6 == (int *)0x0) {
    uStack_e8 = 0;
    local_f0 = CONCAT44(local_f0._4_4_,0x30);
    uStack_d8 = CONCAT44(uStack_d8._4_4_,(param_8 & 1 ^ 1) << 6) | 0x200;
    local_178 = &local_80;
    local_138 = 0x800;
    local_140 = 0;
    local_148 = 0;
    local_150 = 0x4021;
    local_158 = 1;
    local_160 = 7;
    local_168 = 0x90;
    local_170 = 0;
    local_180 = &local_f0;
    local_188 = CONCAT44(local_188._4_4_,0x100001);
    local_d0 = 0;
    uStack_c8 = 0;
    local_130 = &local_a8;
    local_e0 = param_3;
    uVar3 = FltCreateFileEx2(Globals,param_1,&local_110,&local_120);
    puVar11 = auStack_1a8;
    puVar12 = auStack_1a8;
    if (-1 < (int)uVar3) goto LAB_14003563c;
    goto LAB_1400356ca;
  }
  pppuStack_68 = &local_70;
  local_70 = &local_70;
  uStack_58 = 0;
  local_50 = 0;
  local_60 = CONCAT44(0x80000004,piVar6[9]);
  uStack_48 = CONCAT44(uStack_48._4_4_,0x30);
  uVar3 = FltAllocateExtraCreateParameterList(Globals,0,&local_108);
  if ((int)uVar3 < 0) {
    puVar12 = auStack_1a8;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400356ca;
    local_170 = CONCAT44(local_170._4_4_,uVar3);
    uVar14 = 0x26;
    local_178 = (undefined8 ***)CONCAT44(local_178._4_4_,0x5d6);
LAB_1400352c0:
    puVar11 = auStack_1a8;
    bVar10 = 2;
LAB_1400356aa:
    *(char **)(puVar11 + 0x28) = "onecore\\base\\fs\\wci\\wcifs\\wcifs.c";
    *(undefined **)(puVar11 + 0x20) = &WPP_27ac746799d63ca1d37704ce911b8053_Traceguids;
    uVar13 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
    *(undefined8 *)(puVar11 + -8) = 0x1400356ca;
    WPP_RECORDER_SF_sDd(uVar13,bVar10,0x11,uVar14,*(undefined8 *)(puVar11 + 0x20),
                        *(char **)(puVar11 + 0x28),puVar11[0x30],puVar11[0x38]);
    puVar12 = puVar11;
  }
  else {
    local_178 = &local_118;
    local_180 = (undefined8 *)&DAT_14000f300;
    local_188 = 0;
    uVar3 = FltAllocateExtraCreateParameterFromLookasideList
                      (Globals,&ECP_TYPE_OPEN_REPARSE_GUID,0x10,0);
    puVar11 = auStack_1a8;
    if ((int)uVar3 < 0) {
      puVar12 = auStack_1a8;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        local_170 = CONCAT44(local_170._4_4_,uVar3);
        uVar14 = 0x27;
        local_178 = (undefined8 ***)CONCAT44(local_178._4_4_,0x5e3);
        goto LAB_1400352c0;
      }
    }
    else {
      local_118[1] = local_118;
      *local_118 = local_118;
      pppuVar9 = (undefined8 ***)local_118[1];
      pppuVar7 = local_118;
      if ((undefined8 ***)*pppuVar9 != local_118) {
        pppuVar9 = (undefined8 ***)0x3;
        pcVar2 = (code *)swi(0x29);
        pppuVar7 = (undefined8 ***)(*pcVar2)();
        puVar11 = auStack_1a0;
      }
      *pppuVar9 = &local_70;
      pppuVar7[1] = &local_70;
      *(undefined8 *)(puVar11 + -8) = 0x14003538c;
      local_70 = pppuVar7;
      pppuStack_68 = pppuVar9;
      FltInsertExtraCreateParameter(Globals,local_108,local_118);
      lStack_a0 = local_108;
      uStack_e8 = 0;
      local_f0 = CONCAT44(local_f0._4_4_,0x30);
      uStack_d8 = CONCAT44(uStack_d8._4_4_,(param_8 & 1 ^ 1) << 6) | 0x200;
      *(undefined8 **)(puVar11 + 0x78) = &local_a8;
      *(undefined4 *)(puVar11 + 0x70) = 0x800;
      *(undefined4 *)(puVar11 + 0x68) = 0;
      *(undefined8 *)(puVar11 + 0x60) = 0;
      *(undefined4 *)(puVar11 + 0x58) = 0x4021;
      *(undefined4 *)(puVar11 + 0x50) = 1;
      *(undefined4 *)(puVar11 + 0x48) = 7;
      *(undefined4 *)(puVar11 + 0x40) = 0x90;
      *(undefined8 *)(puVar11 + 0x38) = 0;
      *(undefined8 ****)(puVar11 + 0x30) = &local_80;
      *(undefined8 **)(puVar11 + 0x28) = &local_f0;
      *(undefined4 *)(puVar11 + 0x20) = 0x100001;
      local_d0 = 0;
      uStack_c8 = 0;
      *(undefined8 *)(puVar11 + -8) = 0x140035438;
      local_e0 = param_3;
      uVar3 = FltCreateFileEx2(Globals,param_1,&local_110,&local_120);
      puVar12 = puVar11;
      if ((int)uVar3 < 0) {
        if ((uVar3 == 0xc0000279) &&
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          *(ushort **)(puVar11 + 0x40) = param_3;
          *(undefined4 *)(puVar11 + 0x38) = 0xc0000279;
          *(undefined4 *)(puVar11 + 0x30) = 0x617;
          uVar13 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
          *(char **)(puVar11 + 0x28) = "onecore\\base\\fs\\wci\\wcifs\\wcifs.c";
          *(undefined **)(puVar11 + 0x20) = &WPP_27ac746799d63ca1d37704ce911b8053_Traceguids;
          *(undefined8 *)(puVar11 + -8) = 0x1400354a7;
          WPP_RECORDER_SF_sDdZ
                    (uVar13,3,0x11,0x28,*(undefined8 *)(puVar11 + 0x20),*(char **)(puVar11 + 0x28),
                     puVar11[0x30],puVar11[0x38],*(wchar_t **)(puVar11 + 0x40));
        }
      }
      else {
        if ((piVar6[6] == 2) || ((local_60 & 0x100000000) == 0)) {
LAB_14003563c:
          uVar13 = local_128;
        }
        else {
          *(longlong **)(puVar11 + 0x30) = &local_f8;
          *(longlong **)(puVar11 + 0x28) = &local_100;
          *(undefined8 *)(puVar11 + -8) = 0x1400354e7;
          uVar3 = WcGetSetContextFileObject
                            (param_1,local_120,piVar6,1,*(undefined8 *)(puVar11 + 0x20),
                             *(longlong **)(puVar11 + 0x28),*(longlong **)(puVar11 + 0x30));
          uVar13 = local_128;
          if ((int)uVar3 < 0) {
            if (uVar3 != 0xc0000275) goto LAB_1400356ca;
            goto LAB_14003563c;
          }
          if (uVar3 != 0x104) {
            *(undefined8 *)(puVar11 + 0x28) = local_128;
            puVar11[0x20] = 0;
            *(undefined8 *)(puVar11 + -8) = 0x140035528;
            uVar8 = WcPartiallyExpandDirectory
                              (0,param_1,local_120,local_110,puVar11[0x20],
                               *(wchar_t **)(puVar11 + 0x28));
            iVar4 = (int)uVar8;
            if ((((iVar4 < 0) && (1 < iVar4 + 0x3fffffcdU)) && (iVar4 != -0x3fffffc6)) &&
               ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              *(ushort **)(puVar11 + 0x40) = param_3;
              *(int *)(puVar11 + 0x38) = iVar4;
              *(undefined4 *)(puVar11 + 0x30) = 0x651;
              uVar1 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
              *(char **)(puVar11 + 0x28) = "onecore\\base\\fs\\wci\\wcifs\\wcifs.c";
              *(undefined **)(puVar11 + 0x20) = &WPP_27ac746799d63ca1d37704ce911b8053_Traceguids;
              *(undefined8 *)(puVar11 + -8) = 0x14003558e;
              WPP_RECORDER_SF_sDdZ
                        (uVar1,3,0x11,0x29,*(undefined8 *)(puVar11 + 0x20),
                         *(char **)(puVar11 + 0x28),puVar11[0x30],puVar11[0x38],
                         *(wchar_t **)(puVar11 + 0x40));
            }
          }
        }
        *(undefined8 *)(puVar11 + 0x40) = 0;
        puVar11[0x38] = 1;
        *(undefined8 *)(puVar11 + 0x30) = uVar13;
        puVar11[0x28] = 1;
        *(undefined4 *)(puVar11 + 0x20) = 0xc;
        *(undefined8 *)(puVar11 + -8) = 0x140035677;
        uVar3 = FltQueryDirectoryFile(param_1,local_120,local_b0,param_7);
        puVar12 = puVar11;
        if ((((int)uVar3 < 0) && (piVar6 != (int *)0x0)) &&
           ((piVar6[6] == 2 && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
            ))) {
          *(uint *)(puVar11 + 0x38) = uVar3;
          uVar14 = 0x2a;
          *(undefined4 *)(puVar11 + 0x30) = 0x693;
          bVar10 = 3;
          goto LAB_1400356aa;
        }
      }
    }
  }
LAB_1400356ca:
  if (local_110 != 0) {
    *(undefined8 *)(puVar12 + -8) = 0x1400356da;
    FltClose();
  }
  if (local_120 != 0) {
    *(undefined8 *)(puVar12 + -8) = 0x1400356ef;
    ObfDereferenceObject();
  }
  if (local_100 != 0) {
    *(undefined8 *)(puVar12 + -8) = 0x140035704;
    FltReleaseContext();
  }
  if (local_f8 != 0) {
    *(undefined8 *)(puVar12 + -8) = 0x140035719;
    FltReleaseContext();
  }
  if (local_108 != 0) {
    *(undefined8 *)(puVar12 + -8) = 0x140035735;
    FltFreeExtraCreateParameterList(Globals);
  }
  if (piVar6 != (int *)0x0) {
    LOCK();
    iVar4 = *piVar6;
    *piVar6 = *piVar6 + -1;
    UNLOCK();
    if (iVar4 == 1) {
      *(undefined8 *)(puVar12 + -8) = 0x140035763;
      lVar5 = RtlEnumerateGenericTableAvl(piVar6 + 0x10,1);
      while (lVar5 != 0) {
        *(undefined8 *)(puVar12 + -8) = 0x14003577e;
        RtlDeleteElementGenericTableAvl(piVar6 + 0x10,lVar5);
        *(undefined8 *)(puVar12 + -8) = 0x140035790;
        lVar5 = RtlEnumerateGenericTableAvl(piVar6 + 0x10,0);
      }
      if ((piVar6[8] & 1U) != 0) {
        *(undefined8 *)(puVar12 + -8) = 0x1400357af;
        ExAcquireFastMutex(&DAT_14000f208);
        DAT_14000f244 = DAT_14000f244 + -1;
        piVar6[8] = piVar6[8] & 0xfffffffe;
        *(undefined8 *)(puVar12 + -8) = 0x1400357cc;
        ExReleaseFastMutex(&DAT_14000f208);
      }
      *(undefined8 *)(puVar12 + -8) = 0x1400357e0;
      ExFreePoolWithTag(piVar6,0x63754357);
    }
  }
LAB_1400357ff:
  *(undefined8 *)(puVar12 + -8) = 0x14003580b;
  return uVar3;
}



===== WcMungeNamesEnumerate$filt$0 @ 140035821 =====

bool WcMungeNamesEnumerate_filt_0(undefined8 param_1,longlong param_2)

{
  return *(char *)(param_2 + 0x20) != '\0';
}



===== WcMungeDirectoryEnumerateWithShortname$filt$0 @ 14003583f =====

bool WcMungeDirectoryEnumerateWithShortname_filt_0(undefined8 param_1,longlong param_2)

{
  return *(char *)(param_2 + 0x40) != '\0';
}



===== WcMungeReparseEnumerate$filt$0 @ 14003585d =====

bool WcMungeReparseEnumerate_filt_0(undefined8 param_1,char *param_2)

{
  return *param_2 != '\0';
}



===== entry @ 140036010 =====

void entry(undefined8 ****param_1,undefined8 param_2,undefined8 param_3,_GUID *param_4)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2,param_3,param_4);
  return;
}



===== __security_init_cookie @ 140036044 =====

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



===== WcTelemetryAndTracingInit @ 140036078 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WcTelemetryAndTracingInit(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined1 auStackY_68 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  _DAT_14000f788 = 1;
  _WPP_MAIN_CB = 0;
  DAT_14000f768 = &WPP_ThisDir_CTLGUID_WcifsTrace;
  DAT_14000f770 = 0;
  _DAT_14000f780 = 0;
  _DAT_14000f7a0 = 0;
  _DAT_14000f7a8 = 0;
  WppLoadTracingSupport();
  _DAT_14000f780 = 0;
  WppInitKm(param_1,param_2);
  local_28 = 0x100000010;
  uStack_20 = 0x200000002;
  imp_WppRecorderConfigure(WPP_GLOBAL_Control,&local_28);
  iVar1 = TlgRegisterAggregateProvider();
  if ((iVar1 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,10,
                        &WPP_fd6e5da2a1a53c4972de035ee243e502_Traceguids,
                        "onecore\\base\\fs\\wci\\wcifs\\telemetry.c",0x61,(char)iVar1);
  }
  return;
}



===== DriverEntry @ 1400361a8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

_GUID * DriverEntry(undefined8 ****param_1,undefined8 param_2,undefined8 param_3,_GUID *param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  undefined8 *puVar5;
  _GUID *p_Var6;
  undefined8 *puVar7;
  undefined8 *******local_res18 [2];
  code *pcVar8;
  char *pcVar9;
  undefined4 uVar10;
  undefined1 uVar11;
  code *pcVar12;
  ulonglong uVar13;
  undefined8 local_78;
  wchar_t *local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 *local_48;
  undefined8 uStack_40;
  undefined8 *******local_38;
  ulonglong local_30;
  
  local_78 = 0x660064;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = (undefined8 *)0x0;
  uStack_40 = 0;
  local_38 = (undefined8 *******)0x0;
  local_30 = local_30 & 0xffffffff00000000;
  local_70 = L"\\Registry\\Machine\\System\\CurrentControlSet\\Control";
  local_68 = 0;
  uStack_60 = 0;
  local_res18[0] = (undefined8 *******)0x0;
  wil_InitializeFeatureStaging();
  WcTelemetryAndTracingInit(param_1,param_2);
  _DAT_14000f210 = 0;
  _DAT_14000f208 = 1;
  _DAT_14000f218 = 0;
  KeInitializeEvent(&DAT_14000f220,1,0);
  _DAT_14000f6a2 = 0;
  _DAT_14000f6c0 = &DAT_14000f6c8;
  _DAT_14000f6a0 = 0;
  DAT_14000f680 = '\0';
  DAT_14000f688 = 0;
  DAT_14000f6ac = 0x80000018;
  _DAT_14000f6b8 = 0x640000;
  RtlCopyUnicodeString(&DAT_14000f6b8,&DAT_14000a4d0);
  iVar1 = WcSetConfiguration(param_1);
  if ((iVar1 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    param_4 = (_GUID *)0x2b;
    WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x2b,
                        &WPP_27ac746799d63ca1d37704ce911b8053_Traceguids,
                        "onecore\\base\\fs\\wci\\wcifs\\wcifs.c",7,(char)iVar1);
  }
  puVar7 = &Globals;
  puVar5 = (undefined8 *)&FilterRegistration;
  uVar2 = FltRegisterFilter();
  p_Var6 = (_GUID *)(ulonglong)uVar2;
  if ((int)uVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140036754;
    param_4 = (_GUID *)0x2c;
    uVar11 = 0x13;
  }
  else {
    if (DAT_14000f680 != '\0') {
      puVar5 = (undefined8 *)0x28;
      param_1 = (undefined8 *******)0x100;
      puVar7 = (undefined8 *)0x656c4357;
      DAT_14000f688 = ExAllocatePool2();
      if (DAT_14000f688 == 0) {
        p_Var6 = (_GUID *)0xc000009a;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140036754;
        uVar2 = 0xc000009a;
        param_4 = (_GUID *)0x2d;
        uVar11 = 0x20;
        goto LAB_140036735;
      }
    }
    McGenEventRegister_EtwRegister();
    RtlInitUnicodeString(&local_68,L"\\WcifsPort");
    puVar5 = (undefined8 *)0x1f0001;
    param_1 = local_res18;
    uVar2 = FltBuildDefaultSecurityDescriptor();
    p_Var6 = (_GUID *)(ulonglong)uVar2;
    if ((int)uVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140036754;
      param_4 = (_GUID *)0x2e;
      uVar11 = 0x30;
    }
    else {
      local_48 = &local_68;
      puVar7 = &local_58;
      puVar5 = &DAT_14000f248;
      local_38 = local_res18[0];
      iVar1 = 1000;
      pcVar12 = WcPortMessage;
      param_4 = (_GUID *)0x0;
      local_58 = CONCAT44(local_58._4_4_,0x30);
      pcVar8 = WcPortDisconnect;
      uStack_50 = 0;
      uStack_40 = CONCAT44(uStack_40._4_4_,0x240);
      local_30 = 0;
      uVar2 = FltCreateCommunicationPort(Globals);
      p_Var6 = (_GUID *)(ulonglong)uVar2;
      param_1 = local_res18[0];
      FltFreeSecurityDescriptor();
      if ((int)uVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140036754;
        param_4 = (_GUID *)0x2f;
        uVar11 = 0x46;
      }
      else {
        iVar3 = WcSetBootConfiguration(&local_78);
        if ((iVar3 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          pcVar12 = (code *)CONCAT44((int)((ulonglong)pcVar12 >> 0x20),0x756);
          pcVar9 = "onecore\\base\\fs\\wci\\wcifs\\wcifs.c";
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x30,
                              &WPP_27ac746799d63ca1d37704ce911b8053_Traceguids,
                              "onecore\\base\\fs\\wci\\wcifs\\wcifs.c",0x56,(char)iVar3);
          pcVar8 = (code *)pcVar9;
          iVar1 = iVar3;
        }
        FltInitExtraCreateParameterLookasideList
                  (Globals,&DAT_14000f300,0,0x10,0x6f724357,pcVar8,pcVar12,iVar1);
        uVar10 = (undefined4)((ulonglong)pcVar8 >> 0x20);
        FltInitExtraCreateParameterLookasideList(Globals,&DAT_14000f280,0,0x58,0x6f724357);
        uVar13 = (ulonglong)pcVar12 & 0xffffffffffff0000;
        ExInitializePagedLookasideList(&DAT_14000f380,0,0,0,0x30,CONCAT44(uVar10,0x62724357),uVar13)
        ;
        uVar13 = uVar13 & 0xffffffffffff0000;
        ExInitializePagedLookasideList(&DAT_14000f400,0,0,0,0x48,0x65634357,uVar13);
        uVar13 = uVar13 & 0xffffffffffff0000;
        ExInitializePagedLookasideList(&DAT_14000f500,0,0,0,0x20,0x63634357,uVar13);
        uVar13 = uVar13 & 0xffffffffffff0000;
        ExInitializePagedLookasideList(&DAT_14000f480,0,0,0,0x50,0x6e654357,uVar13);
        uVar13 = uVar13 & 0xffffffffffff0000;
        param_4 = (_GUID *)0x200;
        puVar7 = (undefined8 *)0x0;
        ExInitializeNPagedLookasideList(&DAT_14000f580,0,0,0x200,0x108,0x63654357,uVar13);
        if (DAT_14000f6a9 != '\0') {
          param_4 = (_GUID *)0x200;
          puVar7 = (undefined8 *)0x0;
          ExInitializeNPagedLookasideList
                    (&DAT_14000f600,0,0,0x200,0x68,0x70634357,uVar13 & 0xffffffffffff0000);
        }
        puVar5 = (undefined8 *)&DAT_14000f250;
        param_1 = (undefined8 *******)0x0;
        uVar2 = PsAllocSiloContextSlot();
        p_Var6 = (_GUID *)(ulonglong)uVar2;
        if ((int)uVar2 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_140036754;
          param_4 = (_GUID *)0x31;
          uVar11 = 0xa0;
        }
        else {
          puVar5 = (undefined8 *)&DAT_14000f254;
          param_1 = (undefined8 *******)0x0;
          uVar2 = PsAllocSiloContextSlot();
          p_Var6 = (_GUID *)(ulonglong)uVar2;
          if ((int)uVar2 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_140036754;
            param_4 = (_GUID *)0x32;
            uVar11 = 0xab;
          }
          else {
            DAT_14000f730 = 0;
            param_1 = Globals;
            uVar2 = FltStartFiltering();
            p_Var6 = (_GUID *)(ulonglong)uVar2;
            if (-1 < (int)uVar2) {
              if ((Microsoft_Windows_Containers_WcifsEnableBits & 2) == 0) {
                return p_Var6;
              }
              McTemplateK0_EtwWriteTransfer(param_1,&WcifsDriverEntrySuccess,puVar7);
              return p_Var6;
            }
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_140036754;
            param_4 = (_GUID *)0x33;
            uVar11 = 0xb8;
          }
        }
      }
    }
  }
LAB_140036735:
  puVar7 = (undefined8 *)0x1;
  puVar5 = (undefined8 *)CONCAT71((int7)((ulonglong)puVar5 >> 8),2);
  param_1 = *(undefined8 *****)(WPP_GLOBAL_Control + 0x40);
  WPP_RECORDER_SF_sDd(param_1,2,1,(short)param_4,&WPP_27ac746799d63ca1d37704ce911b8053_Traceguids,
                      "onecore\\base\\fs\\wci\\wcifs\\wcifs.c",uVar11,(char)uVar2);
LAB_140036754:
  if ((Microsoft_Windows_Containers_WcifsEnableBits & 1) != 0) {
    param_4 = p_Var6;
    McTemplateK0d_EtwWriteTransfer(param_1,puVar5,puVar7,(int)p_Var6);
  }
  if (DAT_14000f248 != 0) {
    FltCloseCommunicationPort();
  }
  if (Globals != (undefined8 *******)0x0) {
    FltUnregisterFilter();
  }
  lVar4 = DAT_14000f688;
  if (DAT_14000f688 != 0) {
    puVar5 = (undefined8 *)0x656c4357;
    ExFreePoolWithTag();
  }
  WcTelemetryAndTracingCleanup(lVar4,puVar5,puVar7,param_4);
  wil_UninitializeFeatureStaging();
  return p_Var6;
}



===== WcSetBootConfiguration @ 1400367fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int WcSetBootConfiguration(undefined8 *param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined1 *puVar3;
  undefined1 auStackY_1a8 [32];
  undefined1 uVar4;
  longlong local_160;
  longlong local_158;
  undefined8 local_150;
  int *piStack_148;
  longlong local_140;
  undefined4 local_138;
  undefined4 uStack_134;
  longlong local_130;
  undefined8 *local_128;
  undefined4 local_120;
  undefined4 local_11c;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  wchar_t *local_100;
  undefined8 local_f8;
  wchar_t *local_f0;
  undefined8 local_e8;
  wchar_t *local_e0;
  undefined8 local_d8;
  wchar_t *local_d0;
  undefined8 local_c8;
  wchar_t *local_c0;
  undefined8 local_b8;
  wchar_t *local_b0;
  undefined1 local_a8 [4];
  int local_a4;
  short sStack_a0;
  int local_9c [29];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_1a8;
  local_11c = 0;
  local_160 = 0;
  local_158 = 0;
  local_140 = 0;
  puVar3 = (undefined1 *)0x0;
  local_130 = 0;
  local_f0 = L"BootContainer";
  local_c0 = L"Hvsi";
  local_b0 = L"WCIFSContainerMode";
  local_100 = L"BootContainerGuid";
  local_e0 = L"InstanceName";
  local_138 = 0x30;
  uStack_134 = 0;
  local_d0 = L"ReparseTag";
  local_f8 = 0x1c001a;
  local_c8 = 0xa0008;
  local_b8 = 0x260024;
  local_108 = 0x240022;
  local_e8 = 0x1a0018;
  local_d8 = 0x160014;
  local_150 = 0;
  piStack_148 = (int *)0x0;
  local_120 = 0x240;
  local_118 = 0;
  uStack_110 = 0;
  local_128 = param_1;
  iVar1 = ZwOpenKey(&local_160,0x20019,&local_138);
  if (iVar1 < 0) {
    if ((iVar1 == -0x3fffffcc) ||
       ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)) goto LAB_140036e41;
    uVar2 = 0x46;
    uVar4 = 0xaa;
  }
  else {
    iVar1 = ZwQueryValueKey(local_160,&local_108,2,local_a8);
    puVar3 = local_a8;
    if (iVar1 < 0) {
      if ((iVar1 == -0x3fffffcc) ||
         ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)) goto LAB_140036e41;
      uVar2 = 0x47;
      uVar4 = 0xc2;
    }
    else {
      if (local_a4 != 1) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140036e41;
        uVar2 = 0x48;
        uVar4 = 0xc9;
        goto LAB_140036a13;
      }
      piStack_148 = local_9c;
      local_150 = CONCAT62(CONCAT42(local_150._4_4_,sStack_a0),sStack_a0 + -2);
      iVar1 = RtlGUIDFromString(&local_150,&DAT_14000f690);
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140036e41;
        uVar2 = 0x49;
        uVar4 = 0xdc;
      }
      else {
        local_130 = local_160;
        local_128 = &local_f8;
        local_138 = 0x30;
        local_120 = 0x240;
        local_118 = 0;
        uStack_110 = 0;
        iVar1 = ZwOpenKey(&local_158,0x20019,&local_138);
        if (iVar1 < 0) {
          if ((iVar1 == -0x3fffffcc) ||
             ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED))
          goto LAB_140036e41;
          uVar2 = 0x4a;
          uVar4 = 0xf1;
        }
        else {
          iVar1 = ZwQueryValueKey(local_158,&local_e8,2,local_a8);
          if (iVar1 < 0) {
            if ((iVar1 == -0x3fffffcc) ||
               ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED))
            goto LAB_140036e41;
            uVar2 = 0x4b;
            uVar4 = 5;
          }
          else {
            if (local_a4 != 1) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
              goto LAB_140036e41;
              uVar2 = 0x4c;
              uVar4 = 0xc;
LAB_140036a13:
              WPP_RECORDER_SF_sDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar2,
                                  &WPP_27ac746799d63ca1d37704ce911b8053_Traceguids,
                                  "onecore\\base\\fs\\wci\\wcifs\\wcifs.c",uVar4,(char)local_a4);
              goto LAB_140036e41;
            }
            piStack_148 = local_9c;
            local_150 = CONCAT62(CONCAT42(local_150._4_4_,sStack_a0),sStack_a0 + -2);
            RtlCopyUnicodeString(&DAT_14000f6b8,&local_150);
            iVar1 = ZwQueryValueKey(local_158,&local_d8,2,local_a8);
            if (iVar1 < 0) {
              if ((iVar1 == -0x3fffffcc) ||
                 ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED))
              goto LAB_140036e41;
              uVar2 = 0x4d;
              uVar4 = 0x24;
            }
            else {
              if (local_a4 != 4) {
                if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                goto LAB_140036e41;
                uVar2 = 0x4e;
                uVar4 = 0x2b;
                goto LAB_140036a13;
              }
              DAT_14000f6ac = local_9c[0];
              if (local_9c[0] == -0x7fffffe8) {
                DAT_14000f6b0 = 0xa0000027;
              }
              else if (local_9c[0] == -0x6fffefe8) {
                DAT_14000f6b0 = 0xa0001027;
              }
              local_130 = local_160;
              local_128 = &local_c8;
              local_138 = 0x30;
              local_120 = 0x240;
              local_118 = 0;
              uStack_110 = 0;
              iVar1 = ZwOpenKey(&local_140,0x20019,&local_138);
              if (iVar1 < 0) {
                if (iVar1 == -0x3fffffcc) {
                  iVar1 = 0;
                  goto LAB_140036e41;
                }
                if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                goto LAB_140036e41;
                uVar2 = 0x4f;
                uVar4 = 0x4c;
              }
              else {
                iVar1 = ZwQueryValueKey(local_140,&local_b8,2,local_a8);
                if (-1 < iVar1) {
                  if (local_a4 == 4) {
                    if (local_9c[0] == 1) {
                      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                        WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x52,
                                           &WPP_27ac746799d63ca1d37704ce911b8053_Traceguids,
                                           "onecore\\base\\fs\\wci\\wcifs\\wcifs.c",0x6e);
                      }
                      DAT_14000f6a9 = 1;
                    }
                    goto LAB_140036e41;
                  }
                  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                  goto LAB_140036e41;
                  uVar2 = 0x51;
                  uVar4 = 0x69;
                  goto LAB_140036a13;
                }
                if ((iVar1 == -0x3fffffcc) ||
                   ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED))
                goto LAB_140036e41;
                uVar2 = 0x50;
                uVar4 = 0x62;
              }
            }
          }
        }
      }
    }
  }
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar2,
                      &WPP_27ac746799d63ca1d37704ce911b8053_Traceguids,
                      "onecore\\base\\fs\\wci\\wcifs\\wcifs.c",uVar4,(char)iVar1);
LAB_140036e41:
  if (local_160 != 0) {
    ZwClose();
  }
  if (local_158 != 0) {
    ZwClose(local_158);
  }
  if (local_140 != 0) {
    ZwClose(local_160);
  }
  if ((puVar3 != (undefined1 *)0x0) && (puVar3 != local_a8)) {
    ExFreePoolWithTag(puVar3,0x6e664357);
  }
  return iVar1;
}



===== WcSetConfiguration @ 140036ee0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00014003707a) */

int WcSetConfiguration(undefined8 param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined1 auStackY_88 [32];
  undefined1 uVar3;
  undefined8 local_38;
  wchar_t *local_30;
  undefined1 local_28 [12];
  ulonglong local_1c;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_88;
  local_30 = L"DebugOptions";
  local_38 = 0x1a0018;
  iVar1 = IoOpenDriverRegistryKey(param_1,0,0x20019,0);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar2 = 0x44;
    uVar3 = 0x2c;
  }
  else {
    iVar1 = ZwQueryValueKey(0,&local_38,2,local_28);
    if (-1 < iVar1) {
      if ((local_1c & 1) != 0) {
        DAT_14000f680 = 1;
      }
      if ((local_1c & 8) != 0) {
        DAT_14000f6a3 = 1;
      }
      if ((local_1c & 4) != 0) {
        DAT_14000f6a2 = 1;
      }
      if ((local_1c & 0x40) != 0) {
        DAT_14000f6a4 = 1;
      }
      if ((local_1c & 0x10) != 0) {
        DAT_14000f6a1 = 1;
      }
      if ((local_1c & 0x20) != 0) {
        DAT_14000f6a5 = 1;
      }
      if ((local_1c & 2) != 0) {
        DAT_14000f6a0 = 1;
      }
      if ((char)local_1c < '\0') {
        DAT_14000f6a6 = 1;
      }
      if (((uint)local_1c >> 8 & 1) != 0) {
        DAT_14000f6a7 = 1;
      }
      if (((uint)local_1c >> 9 & 1) == 0) {
        return iVar1;
      }
      DAT_14000f6a8 = 1;
      return iVar1;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar2 = 0x45;
    uVar3 = 0x3d;
  }
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar2,
                      &WPP_27ac746799d63ca1d37704ce911b8053_Traceguids,
                      "onecore\\base\\fs\\wci\\wcifs\\wcifs.c",uVar3,(char)iVar1);
  return iVar1;
}



===== wil_InitializeFeatureStaging @ 1400370ac =====

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
    ppuVar4 = &Feature_944920889__private_descriptor;
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



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14003719c =====

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
  ppuVar3 = &Feature_944920889__private_descriptor;
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


