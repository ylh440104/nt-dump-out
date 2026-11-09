
===== _tlgWriteTransfer_EtwWriteTransfer @ 140001008 =====

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



===== Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByRef<16>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>_> @ 1400010ac =====

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
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x14000b290,param_2,0,0,0x2b,local_2c8);
  return lVar1;
}



===== __report_gsfailure @ 140001500 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== McGenControlCallbackV2 @ 140001510 =====

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



===== McGenEventRegister_EtwRegister @ 140001620 =====

void McGenEventRegister_EtwRegister(void)

{
  if (DesktopActivityModeratorEventProvider_Context == 0) {
    EtwRegister(&DesktopActivityModeratorEventProvider,McGenControlCallbackV2,
                &DesktopActivityModeratorEventProvider_Context,
                &DesktopActivityModeratorEventProvider_Context);
  }
  return;
}



===== McGenEventUnregister_EtwUnregister @ 140001660 =====

undefined8 McGenEventUnregister_EtwUnregister(void)

{
  undefined8 uVar1;
  
  if (DesktopActivityModeratorEventProvider_Context == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    DesktopActivityModeratorEventProvider_Context = 0;
  }
  return uVar1;
}



===== McGenEventWrite_EtwWriteTransfer @ 140001694 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_14000a098;
  uVar2 = 0;
  if (DAT_14000a098 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_14000a098;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(DesktopActivityModeratorEventProvider_Context,param_2,0,0,param_4,param_5);
  return;
}



===== McTemplateK0_EtwWriteTransfer @ 1400016f8 =====

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



===== McTemplateK0q_EtwWriteTransfer @ 14000173c =====

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
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,2,local_38);
  return;
}



===== _tlgDefineProvider_annotation__TlgTlgAggregateInternalProviderProv @ 140001798 =====

void _tlgDefineProvider_annotation__TlgTlgAggregateInternalProviderProv(void)

{
  return;
}



===== wil_details_RecordCachedUsage @ 1400017a4 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140001900 =====

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



===== DampBugcheckCallback @ 140001990 =====

void DampBugcheckCallback(undefined8 param_1,longlong param_2,longlong *param_3)

{
  longlong lVar1;
  undefined4 uVar2;
  
  *(undefined4 *)(param_2 + 0x30) = 0x100;
  if (((int)param_3[2] == 0x14f) || ((int)param_3[2] == 0x1eb)) {
    lVar1 = param_2 + 0x48;
    *(undefined4 *)(param_2 + 0x30) = 0x200;
    uVar2 = KeAddTriageDumpDataBlock(lVar1,param_2 + -0x48,0x1b8);
    *(undefined4 *)(param_2 + 0x30) = 0x300;
    *(undefined4 *)(param_2 + 0x34) = uVar2;
    uVar2 = KeAddTriageDumpDataBlock(lVar1,&DamStateMutex,0x38);
    *(undefined4 *)(param_2 + 0x38) = uVar2;
    *param_3 = lVar1;
    *(undefined4 *)(param_2 + 0x30) = 0x500;
    uVar2 = IoAddBugcheckTriageThread(DAT_14000d2e8);
    *(undefined4 *)(param_2 + 0x3c) = uVar2;
    *(undefined4 *)(param_2 + 0x30) = 0x600;
    uVar2 = IoAddBugcheckTriageThread(*(undefined8 *)(param_2 + 0x98));
    *(undefined4 *)(param_2 + 0x40) = uVar2;
    *(undefined4 *)(param_2 + 0x30) = 0x700;
  }
  return;
}



===== DampGetPoClientFromDamExemptGroup @ 140001a74 =====

undefined8 DampGetPoClientFromDamExemptGroup(int param_1)

{
  if (param_1 == 0) {
    return 1;
  }
  if ((param_1 == 1) || (param_1 == 2)) {
    return 3;
  }
  return 4;
}



===== DampUserSessionDelayTimerRoutine @ 140001aa0 =====

void DampUserSessionDelayTimerRoutine(undefined8 param_1,longlong param_2)

{
  IoQueueWorkItemEx(*(undefined8 *)(param_2 + 0x30),DampUserSessionDelayWorkItemRoutine,5,param_2);
  return;
}



===== DampUserSessionDelayWatchdogCallback @ 140001ad0 =====

void DampUserSessionDelayWatchdogCallback(undefined8 param_1,undefined8 param_2)

{
                    /* WARNING: Subroutine does not return */
  KeBugCheckEx(0x1eb,param_2,0,0,0);
}



===== McTemplateK0qq_EtwWriteTransfer @ 140001af8 =====

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
  local_2c = 0;
  local_28 = &param_5;
  local_30 = 4;
  local_1c = 0;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(4,&DamEvent_ProcessActivityEnd,param_3,3,local_48);
  return;
}



===== McTemplateK0qqhzr2hzr4_EtwWriteTransfer @ 140001b6c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qqhzr2hzr4_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,ushort param_6,undefined8 param_7,ushort param_8,
               undefined8 param_9)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_b8 [32];
  undefined8 local_88 [2];
  undefined4 *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  ushort *local_58;
  undefined8 local_50;
  undefined8 local_48;
  int local_40;
  undefined4 local_3c;
  ushort *local_38;
  undefined8 local_30;
  undefined8 local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_70 = 4;
  local_78 = local_res20;
  local_3c = 0;
  local_68 = &param_5;
  local_58 = &param_6;
  local_48 = param_7;
  local_40 = (uint)param_6 * 2;
  local_1c = 0;
  local_38 = &param_8;
  local_60 = 4;
  local_28 = param_9;
  local_20 = (uint)param_8 * 2;
  local_50 = 2;
  local_30 = 2;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&DamEvent_ProcessActivityStart,param_3,7,local_88);
  return;
}



===== McTemplateK0qqqt_EtwWriteTransfer @ 140001c2c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qqqt_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  undefined4 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_58 = local_res20;
  local_50 = 4;
  local_48 = &param_5;
  local_40 = 4;
  local_38 = &param_6;
  local_30 = 4;
  local_28 = &param_7;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&DamEvent_ProcessExemptedByPolicy,param_3,5,local_68);
  return;
}



===== McTemplateK0qqt_EtwWriteTransfer @ 140001cc4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qqt_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_98 [32];
  undefined4 local_68 [2];
  undefined4 local_60 [2];
  undefined8 local_58 [2];
  undefined4 *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  undefined4 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_68[0] = 0x103;
  local_48 = local_res20;
  local_60[0] = 0;
  local_38 = local_68;
  local_28 = local_60;
  local_40 = 4;
  local_30 = 4;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(0,&DamEvent_PdcNotificationCallback,param_3,4,local_58);
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 140001d4c =====

uint * wil_details_FeatureReporting_RecordUsageInCache
                 (uint *param_1,uint *param_2,uint param_3,uint param_4,uint param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  if (param_3 == 0) {
LAB_140001f61:
    uVar6 = *param_2;
    do {
      uVar4 = uVar6;
      param_1[1] = 0;
      uVar6 = uVar4 | 1;
      if ((uVar4 >> 0xe & 1) != (uint)(param_3 == 4)) {
        uVar3 = uVar4 >> 5 & 0x1ff;
        if (uVar3 != 0) {
          param_1[1] = uVar3;
          param_1[2] = ~-(uint)(param_3 != 0) & 4;
          uVar6 = uVar4 & 0xffffc01f | 1;
        }
        uVar3 = 0;
        if (param_3 == 4) {
          uVar3 = 0x4000;
        }
        uVar6 = uVar3 | uVar6 & 0xffffbfff;
      }
      uVar5 = uVar6 >> 5 & 0x1ff;
      uVar3 = uVar5 + param_5;
      if ((0x1ff < uVar3) || (uVar3 < uVar5)) {
        param_1[2] = param_3;
        param_1[1] = uVar5;
        uVar3 = param_5;
      }
      LOCK();
      uVar5 = *param_2;
      if (uVar4 == uVar5) {
        *param_2 = (uVar3 << 5 ^ uVar6) & 0x3fe0 ^ uVar6;
        uVar6 = uVar4;
      }
      else {
        uVar6 = uVar5;
      }
      UNLOCK();
    } while (uVar4 != uVar5);
    *param_1 = ~uVar4 & 1;
  }
  else {
    if (param_3 != 1) {
      if ((param_3 == 2) || (param_3 == 3)) {
LAB_140001e2f:
        uVar6 = 0;
        if (param_3 == 2) {
          uVar6 = 2;
        }
        else if (param_3 == 3) {
          uVar6 = 8;
        }
        else if (param_3 == 6) {
          uVar6 = 4;
        }
        else if (param_3 == 7) {
          uVar6 = 0x10;
        }
        uVar3 = 1;
        uVar4 = *param_2;
        do {
          uVar2 = uVar4;
          uVar4 = uVar6 | uVar2;
          param_1[4] = (uint)(uVar4 == uVar2);
          uVar5 = uVar4 | 1;
          if (uVar4 == uVar2) {
            uVar5 = uVar4;
          }
          LOCK();
          uVar1 = *param_2;
          if (uVar2 == uVar1) {
            *param_2 = uVar5;
            uVar4 = uVar2;
          }
          else {
            uVar4 = uVar1;
          }
          UNLOCK();
        } while (uVar2 != uVar1);
        if (((uVar5 & 1) == 0) || ((uVar2 & 1) != 0)) {
          uVar3 = 0;
        }
        *param_1 = uVar3;
        return param_1;
      }
      if (param_3 == 4) goto LAB_140001f61;
      if (param_3 != 5) {
        if ((param_3 != 6) && (param_3 != 7)) {
          uVar6 = param_3 - 0x140;
          if ((int)uVar6 < 0x40) {
            uVar4 = param_2[1];
            do {
              if (((uVar4 & 0x10) == 0) || ((uVar4 >> 5 & 0x3f) != uVar6)) {
                uVar3 = 0;
              }
              else {
                uVar3 = 1;
              }
              param_1[4] = uVar3;
              LOCK();
              uVar3 = param_2[1];
              bVar7 = uVar4 == uVar3;
              if (bVar7) {
                param_2[1] = (uVar6 * 0x20 ^ uVar4) & 0x7e0 ^ uVar4 | 0x10;
              }
              else {
                uVar4 = uVar3;
              }
              UNLOCK();
            } while (!bVar7);
            if (param_1[4] != 0) {
              return param_1;
            }
          }
          param_1[1] = param_5;
          param_1[2] = param_3;
          param_1[3] = param_4;
          return param_1;
        }
        goto LAB_140001e2f;
      }
    }
    uVar6 = *param_2;
    do {
      uVar4 = uVar6;
      param_1[1] = 0;
      uVar6 = uVar4 | 1;
      if ((uVar4 >> 0x16 & 1) != (uint)(param_3 == 5)) {
        uVar3 = uVar4 >> 0xf & 0x7f;
        if (uVar3 != 0) {
          param_1[1] = uVar3;
          uVar3 = 5;
          if (param_3 != 1) {
            uVar3 = 1;
          }
          uVar6 = uVar4 & 0xffc07fff | 1;
          param_1[2] = uVar3;
        }
        uVar3 = 0;
        if (param_3 == 5) {
          uVar3 = 0x400000;
        }
        uVar6 = uVar3 | uVar6 & 0xffbfffff;
      }
      uVar5 = uVar6 >> 0xf & 0x7f;
      uVar3 = uVar5 + param_5;
      if ((0x7f < uVar3) || (uVar3 < uVar5)) {
        param_1[2] = param_3;
        param_1[1] = uVar5;
        uVar3 = param_5;
      }
      LOCK();
      uVar5 = *param_2;
      if (uVar4 == uVar5) {
        *param_2 = (uVar3 << 0xf ^ uVar6) & 0x3f8000 ^ uVar6;
        uVar6 = uVar4;
      }
      else {
        uVar6 = uVar5;
      }
      UNLOCK();
    } while (uVar4 != uVar5);
    *param_1 = ~uVar4 & 1;
  }
  param_1[4] = 0;
  return param_1;
}



===== wil_details_FeatureReporting_ReportUsageToService @ 140002054 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (longlong param_1,ulonglong param_2,int param_3,undefined8 param_4)

{
  bool bVar1;
  undefined7 extraout_var;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  int local_res18 [4];
  
  uVar2 = (uint)param_2 & 1;
  if (param_3 != 0) {
    if (param_3 == 1) {
      uVar3 = (uVar2 ^ 1) << 2;
      goto LAB_140002125;
    }
    if (param_3 == 2) {
      uVar3 = (uVar2 ^ 1) * 4 + 1;
      goto LAB_140002125;
    }
    if (param_3 == 3) {
      uVar3 = (uVar2 ^ 1) * 4 + 2;
      goto LAB_140002125;
    }
    if (param_3 == 4) {
      uVar3 = (uVar2 ^ 1) * 4 + 3;
      goto LAB_140002125;
    }
    if (param_3 == 5) {
      uVar3 = (uVar2 ^ 1) * 2 + 8;
      goto LAB_140002125;
    }
    if (param_3 == 6) {
      uVar3 = (uVar2 ^ 1) * 2 + 9;
      goto LAB_140002125;
    }
    bVar4 = (char)param_3 + 0x9c;
    if (bVar4 < 0x32) {
      uVar3 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar4;
      goto LAB_140002125;
    }
  }
  uVar3 = 0xff;
LAB_140002125:
  local_res18[0] = param_3;
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect
                    (param_1,param_2,uVar3,(uint)param_4);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (*(undefined4 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x10),0,uVar2,local_res18,0
               ,0,param_4);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140002180 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (longlong param_1,undefined8 param_2,uint param_3,uint param_4)

{
  uint6 uVar1;
  uint *puVar2;
  undefined1 auStackY_a8 [32];
  undefined8 local_78;
  uint local_70 [6];
  uint local_58;
  uint uStack_54;
  uint uStack_50;
  uint uStack_4c;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_a8;
  puVar2 = wil_details_FeatureReporting_RecordUsageInCache
                     (local_70,*(uint **)(param_1 + 8),param_3,(uint)((ulonglong)param_2 >> 0x20),
                      param_4);
  local_58 = *puVar2;
  uStack_54 = puVar2[1];
  uStack_50 = puVar2[2];
  uStack_4c = puVar2[3];
  local_48 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    (*g_wil_details_recordFeatureUsage)
              (*(undefined4 *)(param_1 + 0x18),param_3,param_4,*(undefined8 *)(param_1 + 8));
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && (param_3 != 0xfe)) {
    local_78._0_6_ = CONCAT24((short)param_3,*(undefined4 *)(param_1 + 0x18));
    uVar1 = (uint6)local_78;
    local_78 = (ulonglong)(uint6)local_78;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_78 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_78);
  }
  return (int)local_48 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 140002268 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                    (uint *param_1,ulonglong param_2,longlong param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  uint uVar7;
  uint uVar8;
  longlong *plVar9;
  bool bVar10;
  uint local_res8 [2];
  undefined8 local_res10;
  ulonglong local_res18;
  undefined8 in_stack_ffffffffffffff98;
  uint local_58 [8];
  
  iVar3 = 0;
  local_res8[0] = 0;
  local_res10 = param_2;
  if (g_wil_details_ensureSubscribedToFeatureConfigurationChanges != (code *)0x0) {
    iVar3 = (*g_wil_details_ensureSubscribedToFeatureConfigurationChanges)();
  }
  local_58[4] = 0;
  local_58[5] = 0;
  local_58[0] = 0;
  local_58[1] = 0;
  local_58[2] = 0;
  local_58[3] = 0;
  uVar5 = wil_QueryFeatureState
                    (local_58,*(undefined4 *)(param_3 + 0x18),
                     (uint)((byte)(*(char *)(param_3 + 0x1c) - 2U) < 2),param_4,
                     in_stack_ffffffffffffff98,local_res8);
  uVar4 = -(uint)((int)uVar5 != 0) & local_58[0] & 3;
  if (uVar4 == 0) {
    uVar7 = -(uint)(*(char *)(param_3 + 0x1f) != '\0') & 0x40;
  }
  else {
    uVar7 = 0;
    if (local_58[0] == 2) {
      uVar7 = 0x40;
    }
  }
  uVar4 = uVar7 >> 6 ^
          (uVar7 | uVar4 << 7 |
                   -(uint)(local_58[5] != 0) & 0x800 | -(uint)(local_58[4] != 0) & 0x400);
  if ((uVar7 != 0) && (plVar9 = *(longlong **)(param_3 + 0x20), plVar9 != (longlong *)0x0)) {
    do {
      puVar1 = (undefined8 *)*plVar9;
      if (puVar1 == (undefined8 *)0x0) break;
      if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
         (*(char *)((longlong)puVar1 + 0x1d) == '\0')) {
        puVar2 = (uint *)*puVar1;
        uVar8 = *puVar2;
        local_res18 = (ulonglong)uVar8;
        if ((uVar8 & 2) == 0) {
          uVar6 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            (puVar2,local_res18,(longlong)puVar1,puVar2);
          uVar8 = (uint)uVar6;
        }
        uVar7 = uVar4 & 0xfffffffe;
        uVar4 = (uint)((uVar8 & uVar4 & 1) != 0);
      }
      else {
        if (((uVar4 & 1) == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar7 = 0;
        }
        else {
          uVar7 = 1;
        }
        uVar4 = uVar4 & 0xfffffffe;
      }
      uVar4 = uVar4 | uVar7;
      plVar9 = plVar9 + 1;
    } while ((uVar4 & 1) != 0);
  }
  if (*(char *)(param_3 + 0x1c) == '\0') {
    local_res8[0] = local_res8[0] & -(uint)(iVar3 != 0);
  }
  uVar6 = param_2 & 0xffffffff;
  while( true ) {
    uVar7 = (uint)uVar6;
    local_res10 = CONCAT44(local_res10._4_4_,uVar7);
    if ((local_res8[0] != 0) && (local_res10 = CONCAT44(local_res10._4_4_,uVar7), (uVar6 & 2) == 0))
    {
      uVar8 = (uVar4 ^ uVar7) & 0x9c1 ^ uVar7;
      uVar7 = uVar8 | 2;
      local_res10 = CONCAT44(local_res10._4_4_,uVar8) | 2;
    }
    if ((param_2 & 4) == 0) {
      uVar8 = (uVar4 ^ uVar7) & 0x400 ^ uVar7;
      uVar7 = uVar8 | 4;
      local_res10 = CONCAT44(local_res10._4_4_,uVar8) | 4;
    }
    uVar6 = param_2 & 0xffffffff;
    LOCK();
    uVar8 = *param_1;
    bVar10 = (uint)param_2 == uVar8;
    if (bVar10) {
      *param_1 = uVar7;
    }
    else {
      uVar6 = (ulonglong)uVar8;
    }
    UNLOCK();
    if (bVar10) break;
    param_2 = uVar6;
  }
  if (((param_2 & 4) == 0) &&
     (g_wil_details_subscribeFeatureStateCacheToConfigurationChanges != (code *)0x0)) {
    (*g_wil_details_subscribeFeatureStateCacheToConfigurationChanges)
              (param_1,*(undefined1 *)(param_3 + 0x1c),iVar3);
  }
  if (local_res8[0] == 0) {
    local_res10 = CONCAT44(local_res10._4_4_,(uVar7 ^ uVar4) & 0x9c1 ^ uVar7);
  }
  return local_res10;
}



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140002470 =====

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



===== wil_details_IsEnabledFallback @ 1400024d4 =====

uint wil_details_IsEnabledFallback
               (ulonglong param_1,int param_2,undefined8 *param_3,undefined8 param_4)

{
  ulonglong local_res8;
  
  local_res8 = param_1 & 0xffffffff;
  if ((param_1 & 2) == 0) {
    local_res8 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                           ((uint *)*param_3,param_1,(longlong)param_3,param_4);
    param_1 = local_res8 & 0xffffffff;
  }
  if ((param_2 != 0) &&
     (wil_details_FeatureReporting_ReportUsageToService((longlong)param_3,local_res8,param_2,1),
     param_2 - 3U < 2)) {
    wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath((uint)local_res8,param_2,param_3);
  }
  return (uint)param_1 & 1;
}



===== Feature_ControlExplorerDamExemption__private_GetVariant @ 140002570 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint Feature_ControlExplorerDamExemption__private_GetVariant
               (undefined8 param_1,undefined8 param_2,ulonglong param_3,undefined8 param_4)

{
  ulonglong uVar1;
  
  uVar1 = _Feature_ControlExplorerDamExemption__private_featureState;
  if ((_Feature_ControlExplorerDamExemption__private_featureState & 8) == 0) {
    uVar1 = wil_details_FeatureStateCache_ReevaluateCachedVariantState
                      (param_1,_Feature_ControlExplorerDamExemption__private_featureState,param_3,
                       param_4);
  }
  wil_details_FeatureReporting_ReportVariantUsageToService(param_1,uVar1);
  return (uint)(uVar1 >> 0xc) & 0x3f;
}



===== Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline @ 1400025ac =====

ulonglong Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline
                    (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_EE_MPTF_Functionality__private_featureState;
  if ((Feature_EE_MPTF_Functionality__private_featureState & 0x10) == 0) {
    uVar1 = Feature_EE_MPTF_Functionality__private_IsEnabledFallback(local_res8,3,param_3,param_4);
  }
  else {
    uVar1 = (ulonglong)(Feature_EE_MPTF_Functionality__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_EE_MPTF_Functionality__private_IsEnabledFallback @ 1400025e4 =====

void Feature_EE_MPTF_Functionality__private_IsEnabledFallback
               (ulonglong param_1,int param_2,undefined8 param_3,undefined8 param_4)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_EE_MPTF_Functionality__private_descriptor,param_4);
  return;
}



===== Feature_NXTShellLauncherResiliencyExempt__private_IsEnabledDeviceUsageNoInline @ 140002600 =====

ulonglong Feature_NXTShellLauncherResiliencyExempt__private_IsEnabledDeviceUsageNoInline
                    (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_NXTShellLauncherResiliencyExempt__private_featureState;
  if ((Feature_NXTShellLauncherResiliencyExempt__private_featureState & 0x10) == 0) {
    uVar1 = Feature_NXTShellLauncherResiliencyExempt__private_IsEnabledFallback
                      (local_res8,3,param_3,param_4);
  }
  else {
    uVar1 = (ulonglong)(Feature_NXTShellLauncherResiliencyExempt__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_NXTShellLauncherResiliencyExempt__private_IsEnabledFallback @ 140002638 =====

void Feature_NXTShellLauncherResiliencyExempt__private_IsEnabledFallback
               (ulonglong param_1,int param_2,undefined8 param_3,undefined8 param_4)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_NXTShellLauncherResiliencyExempt__private_descriptor,param_4);
  return;
}



===== Feature_PackagedComElevationSupport__private_IsEnabledFallback @ 140002654 =====

void Feature_PackagedComElevationSupport__private_IsEnabledFallback
               (ulonglong param_1,int param_2,undefined8 param_3,undefined8 param_4)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_PackagedComElevationSupport__private_descriptor,param_4);
  return;
}



===== Feature_PackagedComElevationSupport__private_IsEnabledNoReportingNoInline @ 140002670 =====

ulonglong Feature_PackagedComElevationSupport__private_IsEnabledNoReportingNoInline
                    (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_PackagedComElevationSupport__private_featureState;
  if ((Feature_PackagedComElevationSupport__private_featureState & 2) == 0) {
    uVar1 = Feature_PackagedComElevationSupport__private_IsEnabledFallback
                      (local_res8,0,param_3,param_4);
  }
  else {
    uVar1 = (ulonglong)(Feature_PackagedComElevationSupport__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_RSExWOA__private_IsEnabledDeviceUsageNoInline @ 1400026a8 =====

ulonglong Feature_RSExWOA__private_IsEnabledDeviceUsageNoInline
                    (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_RSExWOA__private_featureState;
  if ((Feature_RSExWOA__private_featureState & 0x10) == 0) {
    uVar1 = Feature_RSExWOA__private_IsEnabledFallback(local_res8,3,param_3,param_4);
  }
  else {
    uVar1 = (ulonglong)(Feature_RSExWOA__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_RSExWOA__private_IsEnabledFallback @ 1400026e0 =====

void Feature_RSExWOA__private_IsEnabledFallback
               (ulonglong param_1,int param_2,undefined8 param_3,undefined8 param_4)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_RSExWOA__private_descriptor,param_4);
  return;
}



===== RtlUnicodeStringCat @ 1400026fc =====

undefined4 RtlUnicodeStringCat(ushort *param_1,ushort *param_2)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  longlong lVar4;
  longlong lVar5;
  undefined4 uVar6;
  longlong lVar7;
  ulonglong uVar8;
  short sVar9;
  undefined2 *puVar10;
  
  uVar1 = *param_1;
  if ((((((uVar1 & 1) == 0) && (uVar2 = param_1[1], (uVar2 & 1) == 0)) && (uVar1 <= uVar2)) &&
      (uVar2 != 0xffff)) &&
     ((uVar6 = 0, *(longlong *)(param_1 + 4) != 0 || ((uVar1 == 0 && (uVar2 == 0)))))) {
    uVar2 = *param_2;
    lVar4 = *(longlong *)(param_1 + 4);
    uVar1 = uVar1 >> 1;
    if (((uVar2 & 1) == 0) &&
       ((((uVar3 = param_2[1], (uVar3 & 1) == 0 && (uVar2 <= uVar3)) && (uVar3 != 0xffff)) &&
        ((*(longlong *)(param_2 + 4) != 0 || ((uVar2 == 0 && (uVar3 == 0)))))))) {
      puVar10 = *(undefined2 **)(param_2 + 4);
      sVar9 = 0;
      uVar8 = (ulonglong)(uVar2 >> 1);
      lVar7 = (ulonglong)(param_1[1] >> 1) - (ulonglong)uVar1;
      if (lVar7 != 0) {
        lVar5 = (ulonglong)uVar1 * 2 - (longlong)puVar10;
        do {
          if (uVar8 == 0) goto LAB_1400027e1;
          uVar8 = uVar8 - 1;
          *(undefined2 *)(lVar4 + lVar5 + (longlong)puVar10) = *puVar10;
          sVar9 = sVar9 + 1;
          puVar10 = puVar10 + 1;
          lVar7 = lVar7 + -1;
        } while (lVar7 != 0);
      }
      uVar6 = 0;
      if (uVar8 != 0) {
        uVar6 = 0x80000005;
      }
LAB_1400027e1:
      *param_1 = (uVar1 + sVar9) * 2;
      return uVar6;
    }
  }
  return 0xc000000d;
}



===== wil_details_FeatureReporting_ReportVariantUsageToService @ 14000280c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportVariantUsageToService(undefined8 param_1,ulonglong param_2)

{
  bool bVar1;
  undefined7 extraout_var;
  byte bVar2;
  undefined4 local_res18 [4];
  
  local_res18[0] = 2;
  bVar2 = (byte)(param_2 >> 0xc) & 0x3f;
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect
                    (0x1400091d0,param_2,bVar2 + 0x140,1);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (0x2d1411a,&Feature_Standalone_25_06_NonSec_logged_traits,0,(uint)param_2 & 1,0,
               local_res18,bVar2,1);
  }
  return;
}



===== wil_details_FeatureStateCache_ReevaluateCachedVariantState @ 1400028a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong wil_details_FeatureStateCache_ReevaluateCachedVariantState
                    (undefined8 param_1,ulonglong param_2,ulonglong param_3,undefined8 param_4)

{
  byte bVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  bool bVar8;
  undefined8 local_res8;
  ulonglong local_res18 [2];
  undefined8 in_stack_ffffffffffffffb8;
  uint local_38;
  byte bStack_34;
  undefined8 uStack_30;
  undefined8 local_28;
  
  uVar2 = 0;
  local_res18[0] = param_3 & 0xffffffff00000000;
  if (g_wil_details_ensureSubscribedToFeatureConfigurationChanges != (code *)0x0) {
    uVar2 = (*g_wil_details_ensureSubscribedToFeatureConfigurationChanges)();
  }
  local_28 = 0;
  _local_38 = 0;
  uStack_30 = 0;
  uVar3 = wil_QueryFeatureState
                    (&local_38,0x2d1411a,1,param_4,in_stack_ffffffffffffffb8,
                     (undefined4 *)local_res18);
  uVar6 = -(uint)(local_28._4_4_ != 0) & 0x800 | -(uint)((int)local_28 != 0) & 0x400;
  if ((int)uVar3 == 0) {
    bVar1 = 2;
    uVar7 = 0;
  }
  else {
    bVar1 = bStack_34;
    uVar7 = uStack_30._4_4_;
    if (bStack_34 == 0) {
      uVar7 = 0;
      uVar6 = uVar6 | 0x2000;
      goto LAB_14000295d;
    }
  }
  uVar6 = uVar6 ^ (bVar1 & 0x3f) << 0xc;
  if ((int)uStack_30 == 0) {
    uVar7 = 0;
  }
LAB_14000295d:
  while( true ) {
    uVar5 = (uint)param_2;
    if ((param_2 & 8) == 0) {
      uVar5 = uVar6 & 0x3f000 | uVar5 & 0xfffc0fff;
      uVar5 = ((uVar6 ^ uVar5) & 0x800 ^ uVar5) & 0xfffffff7 | -(uint)((int)local_res18[0] != 0) & 8
      ;
      local_res8 = CONCAT44(uVar7,uVar5);
    }
    else {
      local_res8 = param_2;
    }
    if ((param_2 & 4) == 0) {
      local_res8 = CONCAT44(local_res8._4_4_,uVar6 & 0x400 | uVar5 & 0xfffffbff) | 4;
    }
    LOCK();
    bVar8 = param_2 == _Feature_ControlExplorerDamExemption__private_featureState;
    if (bVar8) {
      uVar4 = param_2;
      _Feature_ControlExplorerDamExemption__private_featureState = local_res8;
    }
    else {
      uVar4 = _Feature_ControlExplorerDamExemption__private_featureState;
    }
    UNLOCK();
    if (bVar8) break;
    param_2 = uVar4;
  }
  if (((param_2 & 4) == 0) &&
     (g_wil_details_subscribeFeatureStateCacheToConfigurationChanges != (code *)0x0)) {
    (*g_wil_details_subscribeFeatureStateCacheToConfigurationChanges)
              (&Feature_ControlExplorerDamExemption__private_featureState,3,uVar2);
  }
  return local_res8;
}



===== DamStatePerformanceTypeIdGetFromPhase @ 140002a10 =====

void DamStatePerformanceTypeIdGetFromPhase
               (int param_1,int param_2,undefined4 *param_3,undefined1 *param_4)

{
  int iVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  
  puVar2 = DamStatePhaseDefinitionGet(param_1);
  iVar4 = *(int *)(puVar2 + 0x2c);
  puVar3 = DamStatePhaseDefinitionGet(param_2);
  iVar1 = *(int *)(puVar3 + 0x2c);
  if ((iVar4 == 2) && (iVar1 < 2)) {
    *param_3 = 0;
  }
  else {
    if ((iVar1 == 2) && (iVar4 < 2)) {
      *param_4 = 0;
      if (iVar4 == 0) {
        *param_3 = 0;
        return;
      }
      if (iVar4 == 1) {
        *param_3 = 1;
        return;
      }
      return;
    }
    if ((iVar4 != 3) || (2 < iVar1)) {
      if ((iVar1 == 3) && (iVar4 < 3)) {
        *param_3 = 4;
      }
      else {
        if ((iVar4 == 4) && (iVar1 < 4)) {
          *param_3 = 5;
          goto LAB_140002a42;
        }
        if ((iVar1 == 4) && (iVar4 < 4)) {
          *param_3 = 5;
        }
        else if (param_1 == param_2) {
          *param_3 = 0xb;
        }
        else {
          if (iVar1 != 1) {
            if (iVar1 == 3) {
              iVar4 = *(int *)(puVar2 + 8);
              *param_3 = 9;
            }
            else {
              if (iVar1 != 4) {
                *param_3 = 0xc;
                goto LAB_140002b1b;
              }
              iVar4 = *(int *)(puVar2 + 0x10);
              *param_3 = 10;
            }
            *param_4 = iVar4 == 0;
            return;
          }
          *param_3 = 8;
        }
      }
LAB_140002b1b:
      *param_4 = 0;
      return;
    }
    *param_3 = 4;
  }
LAB_140002a42:
  *param_4 = 1;
  return;
}



===== WdmlibRtlInitUnicodeStringEx @ 140002b34 =====

undefined8 WdmlibRtlInitUnicodeStringEx(short *param_1,longlong param_2)

{
  short sVar1;
  ulonglong uVar2;
  short sVar3;
  
  sVar3 = 0;
  if (param_2 == 0) {
    param_2 = 0;
    sVar1 = 0;
  }
  else {
    uVar2 = 0xffffffffffffffff;
    do {
      uVar2 = uVar2 + 1;
    } while (*(short *)(param_2 + uVar2 * 2) != 0);
    if (0x7ffe < uVar2) {
      return 0xc0000106;
    }
    sVar1 = (short)uVar2 * 2;
    sVar3 = sVar1 + 2;
  }
  *param_1 = sVar1;
  param_1[1] = sVar3;
  *(longlong *)(param_1 + 4) = param_2;
  return 0;
}



===== CreateNewEventEntry @ 140002b80 =====

undefined8
CreateNewEventEntry(char param_1,undefined8 *param_2,undefined8 param_3,longlong param_4,
                   byte param_5,undefined4 param_6,undefined8 *param_7)

{
  uint uVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  longlong lVar6;
  ulonglong _Size;
  undefined8 *puVar7;
  undefined8 *puVar8;
  longlong lVar9;
  ulonglong uVar10;
  byte bVar11;
  uint *puVar12;
  ulonglong uVar13;
  undefined8 *puVar14;
  
  lVar6 = 0;
  *param_7 = 0;
  puVar12 = (uint *)(param_4 + 8);
  bVar11 = 0;
  lVar9 = 0;
  do {
    uVar1 = *puVar12;
    puVar12 = puVar12 + 4;
    if (1 < bVar11) {
      lVar6 = (ulonglong)uVar1 + lVar6;
    }
    lVar3 = (ulonglong)uVar1 + lVar9;
    if (1 < bVar11) {
      lVar3 = lVar9;
    }
    bVar11 = bVar11 + 1;
    lVar9 = lVar3;
  } while (bVar11 < 8);
  if ((ulonglong)(lVar3 + lVar6) < 0x10000) {
    _Size = lVar6 + 0xae;
    if ((_Size == 0) ||
       (puVar5 = (undefined8 *)
                 ExAllocatePoolWithTag
                           ((-(uint)(param_1 != '\0') & 0xfffffe01) + 0x200,_Size,0x47417254),
       puVar5 == (undefined8 *)0x0)) {
      uVar4 = 0xc0000017;
    }
    else {
      memset(puVar5,0,_Size);
      if (_Size < 0x80) {
        puVar14 = (undefined8 *)0x0;
        puVar7 = puVar5;
      }
      else {
        _Size = lVar6 + 0x2e;
        puVar7 = puVar5 + 0x10;
        puVar14 = puVar5;
      }
      uVar13 = 0;
      if (param_5 != 0xfffffffe) {
        do {
          if ((byte)uVar13 < 2) {
            puVar5 = (undefined8 *)(param_4 + uVar13 * 0x10);
            uVar4 = puVar5[1];
            puVar14[uVar13 * 2] = *puVar5;
            (puVar14 + uVar13 * 2)[1] = uVar4;
          }
          else {
            uVar10 = (ulonglong)*(uint *)(param_4 + 8 + uVar13 * 0x10);
            if ((uVar10 == 0) || (_Size < uVar10)) {
              puVar5 = (undefined8 *)0x0;
            }
            else {
              _Size = _Size - uVar10;
              puVar5 = puVar7;
              puVar7 = (undefined8 *)((longlong)puVar7 + uVar10);
            }
            memmove(puVar5,*(void **)(param_4 + uVar13 * 0x10),uVar10);
            puVar14[uVar13 * 2] = puVar5;
            *(undefined4 *)((longlong)puVar14 + uVar13 * 0x10 + 0xc) =
                 *(undefined4 *)(param_4 + 0xc + uVar13 * 0x10);
            *(undefined4 *)(puVar14 + uVar13 * 2 + 1) = *(undefined4 *)(param_4 + 8 + uVar13 * 0x10)
            ;
          }
          bVar11 = (byte)uVar13 + 1;
          uVar13 = (ulonglong)bVar11;
        } while ((uint)bVar11 < param_5 + 2);
      }
      if (_Size < 0x2e) {
        puVar8 = (undefined8 *)0x0;
        puVar5 = puVar7;
      }
      else {
        _Size = _Size - 0x2e;
        puVar5 = (undefined8 *)((longlong)puVar7 + 0x2e);
        puVar8 = puVar7;
      }
      puVar8[2] = puVar14;
      uVar4 = *param_2;
      uVar2 = param_2[1];
      *(byte *)((longlong)puVar8 + 0x2d) = param_5;
      bVar11 = param_5 + 2;
      *(undefined1 *)((longlong)puVar8 + 0x2c) = 8;
      *(undefined4 *)(puVar8 + 5) = param_6;
      *puVar8 = uVar4;
      puVar8[1] = uVar2;
      if (bVar11 < 8) {
        lVar6 = -param_4;
        uVar13 = (ulonglong)(byte)(8 - bVar11);
        puVar12 = (uint *)((ulonglong)bVar11 * 0x10 + 8 + param_4);
        do {
          uVar10 = (ulonglong)*puVar12;
          if ((uVar10 == 0) || (_Size < uVar10)) {
            puVar7 = (undefined8 *)0x0;
          }
          else {
            _Size = _Size - uVar10;
            puVar7 = puVar5;
            puVar5 = (undefined8 *)((longlong)puVar5 + uVar10);
          }
          memmove(puVar7,*(void **)(puVar12 + -2),uVar10);
          *(undefined8 **)((longlong)puVar12 + puVar8[2] + lVar6 + -8) = puVar7;
          *(uint *)((longlong)puVar12 + puVar8[2] + lVar6 + 4) = puVar12[1];
          *(uint *)((longlong)puVar12 + puVar8[2] + lVar6) = *puVar12;
          uVar13 = uVar13 - 1;
          puVar12 = puVar12 + 4;
        } while (uVar13 != 0);
      }
      *param_7 = puVar8;
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 0xc0000095;
  }
  return uVar4;
}



===== DestroyEventEntry @ 140002dd4 =====

void DestroyEventEntry(longlong param_1)

{
  if (param_1 != 0) {
    ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x10),0);
  }
  return;
}



===== EnableFlushTimer @ 140002dfc =====

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



===== FinishHash @ 140002e58 =====

void FinishHash(int *param_1)

{
  *param_1 = ((uint)(*param_1 * 9) >> 0xb ^ *param_1 * 9) * 0x8001;
  return;
}



===== FlushLookUpTableBucket @ 140002e74 =====

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



===== InsertEventEntryInLookUpTable @ 140002f88 =====

ulonglong InsertEventEntryInLookUpTable
                    (undefined8 param_1,undefined8 *param_2,undefined8 param_3,longlong param_4,
                    byte param_5)

{
  int *piVar1;
  byte *pbVar2;
  longlong lVar3;
  char cVar4;
  uint uVar5;
  longlong lVar6;
  bool bVar7;
  longlong lVar8;
  byte bVar9;
  undefined1 uVar10;
  int iVar11;
  uint uVar12;
  longlong lVar13;
  longlong *plVar14;
  longlong lVar15;
  uint uVar16;
  ulonglong uVar17;
  byte bVar18;
  ulonglong uVar19;
  ulonglong local_res8;
  longlong local_58;
  void *local_50;
  
  lVar8 = DAT_14000a080;
  bVar7 = false;
  local_58 = 0;
  lVar15 = 0;
  local_50 = (void *)(param_4 + 0x10);
  local_res8 = 0;
  uVar12 = 0;
  uVar17 = 0;
  do {
    pbVar2 = (byte *)((longlong)local_50 + uVar17);
    uVar17 = uVar17 + 1;
    uVar12 = (*pbVar2 + uVar12) * 0x401;
    uVar12 = uVar12 ^ uVar12 >> 6;
  } while (uVar17 < 8);
  uVar16 = param_5 + 2;
  uVar17 = (ulonglong)uVar16;
  if ((byte)uVar16 < 8) {
    plVar14 = (longlong *)((ulonglong)(uVar16 & 0xff) * 0x10 + param_4);
    uVar19 = (ulonglong)(byte)(8 - (byte)uVar16);
    do {
      uVar17 = 0;
      if ((ulonglong)*(uint *)(plVar14 + 1) != 0) {
        do {
          pbVar2 = (byte *)(uVar17 + *plVar14);
          uVar17 = uVar17 + 1;
          uVar12 = (*pbVar2 + uVar12) * 0x401;
          uVar12 = uVar12 ^ uVar12 >> 6;
        } while (uVar17 < *(uint *)(plVar14 + 1));
      }
      plVar14 = plVar14 + 2;
      uVar19 = uVar19 - 1;
    } while (uVar19 != 0);
  }
  uVar12 = (uVar12 * 9 >> 0xb ^ uVar12 * 9) * 0x8001;
  bVar9 = KeGetCurrentIrql();
  if (bVar9 < 2) {
    iVar11 = KeIsExecutingDpc();
    if (iVar11 == 0) {
      ExAcquirePushLockSharedEx(lVar8 + 0x110,0);
      goto LAB_140003153;
    }
    if (*(char *)(lVar8 + 0x175) != '\0') {
      uVar10 = KeGetCurrentIrql();
                    /* WARNING: Subroutine does not return */
      KeBugCheckEx(0xd1,lVar8 + 0x118,uVar10,1,0);
    }
    ExAcquireSpinLockShared(lVar8 + 0x118);
  }
  else {
    if (*(char *)(lVar8 + 0x175) != '\0') {
      uVar10 = KeGetCurrentIrql();
                    /* WARNING: Subroutine does not return */
      KeBugCheckEx(0xd1,lVar8 + 0x118,uVar10,1,0);
    }
    ExAcquireSpinLockSharedAtDpcLevel(lVar8 + 0x118);
  }
  bVar7 = true;
LAB_140003153:
  plVar14 = (longlong *)(lVar8 + (ulonglong)(uVar12 & 0x1f) * 8);
  do {
    if (*plVar14 == 0) {
      if (0x3ff < *(uint *)(lVar8 + 0x100)) {
        *(int *)(lVar8 + 0x13c) = *(int *)(lVar8 + 0x13c) + 1;
        local_res8 = 0xc0000023;
        goto LAB_140003386;
      }
      if (lVar15 == 0) {
        uVar19 = CreateNewEventEntry(*(char *)(lVar8 + 0x175),param_2,uVar17,param_4,param_5,uVar12,
                                     &local_58);
        local_res8 = uVar19 & 0xffffffff;
        lVar15 = local_58;
        if (local_58 == 0) {
          local_res8 = uVar19 & 0xffffffff;
          if ((int)uVar19 == -0x3fffffe9) {
            *(int *)(lVar8 + 0x140) = *(int *)(lVar8 + 0x140) + 1;
          }
          else {
            *(int *)(lVar8 + 0x144) = *(int *)(lVar8 + 0x144) + 1;
          }
          goto LAB_140003386;
        }
      }
      LOCK();
      lVar13 = *plVar14;
      if (lVar13 == 0) {
        *plVar14 = lVar15;
      }
      UNLOCK();
      if (lVar13 == 0) {
        local_58 = 0;
        LOCK();
        piVar1 = (int *)(lVar8 + 0x100);
        iVar11 = *piVar1;
        *piVar1 = *piVar1 + 1;
        UNLOCK();
        if (iVar11 == 0) {
          EnableFlushTimer(*(longlong *)(lVar8 + 0x168),(ulonglong)*(uint *)(lVar8 + 0x170));
        }
        lVar15 = local_58;
        if (*(uint *)(lVar8 + 0x130) < *(uint *)(lVar8 + 0x100)) {
          *(uint *)(lVar8 + 0x130) = *(uint *)(lVar8 + 0x100);
        }
        goto LAB_140003386;
      }
      lVar15 = local_58;
    }
    lVar13 = *plVar14;
    if (uVar12 == *(uint *)(lVar13 + 0x28)) {
      lVar6 = *(longlong *)(lVar13 + 0x10);
      uVar17 = 8;
      iVar11 = memcmp(local_50,(void *)(lVar6 + 0x10),8);
      if (iVar11 == 0) {
        uVar16 = *(byte *)(lVar13 + 0x2d) + 2;
        while( true ) {
          if (7 < uVar16) {
            lVar13 = *plVar14;
            goto LAB_140003250;
          }
          lVar13 = (ulonglong)uVar16 * 0x10;
          uVar5 = *(uint *)(lVar13 + 8 + param_4);
          iVar11 = uVar5 - *(int *)(lVar13 + 8 + lVar6);
          if (iVar11 != 0) break;
          uVar17 = (ulonglong)uVar5;
          iVar11 = memcmp(*(void **)(lVar13 + param_4),*(void **)(lVar13 + lVar6),uVar17);
          if (iVar11 != 0) break;
          uVar16 = uVar16 + 1;
        }
        lVar13 = *plVar14;
      }
    }
    else {
      iVar11 = uVar12 - *(uint *)(lVar13 + 0x28);
      if (iVar11 == 0) {
LAB_140003250:
        if (lVar13 != 0) {
          uVar17 = 2;
          if (2 < param_5 + 2) {
            do {
              lVar15 = **(longlong **)(param_4 + uVar17 * 0x10);
              cVar4 = *(char *)(*(longlong *)(lVar13 + 0x10) + 0xd + uVar17 * 0x10);
              plVar14 = *(longlong **)(*(longlong *)(lVar13 + 0x10) + uVar17 * 0x10);
              if (cVar4 == 'q') {
                LOCK();
                *plVar14 = *plVar14 + lVar15;
                UNLOCK();
              }
              else if ((cVar4 == 'r') || (cVar4 == 's')) {
                do {
                  lVar6 = *plVar14;
                  if (cVar4 == 'r') {
                    if (lVar6 <= lVar15) break;
                  }
                  else if (lVar15 <= lVar6) break;
                  LOCK();
                  lVar3 = *plVar14;
                  if (lVar6 == lVar3) {
                    *plVar14 = lVar15;
                  }
                  UNLOCK();
                } while (lVar6 != lVar3);
              }
              bVar18 = (char)uVar17 + 1;
              uVar17 = (ulonglong)bVar18;
            } while ((uint)bVar18 < param_5 + 2);
            lVar15 = local_58;
          }
        }
LAB_140003386:
        if (bVar7) {
          if (bVar9 < 2) {
            ExReleaseSpinLockShared();
          }
          else {
            ExReleaseSpinLockSharedFromDpcLevel(lVar8 + 0x118);
          }
        }
        else {
          ExReleasePushLockSharedEx(lVar8 + 0x110,0);
        }
        if (lVar15 != 0) {
          ExFreePoolWithTag(*(undefined8 *)(lVar15 + 0x10),0);
        }
        return local_res8;
      }
    }
    plVar14 = (longlong *)(lVar13 + 0x20 + ((longlong)iVar11 >> 0x3f & 0xfffffffffffffff8U));
  } while( true );
}



===== RunningHash @ 140003400 =====

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



===== TlgAggregateInternalFlushTimerCallbackKernelMode @ 140003440 =====

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



===== _tlgWriteAgg @ 140003484 =====

ulonglong _tlgWriteAgg(undefined8 param_1,byte *param_2,ulonglong param_3,undefined8 param_4,
                      undefined8 *param_5)

{
  char cVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  char *pcVar5;
  char *pcVar6;
  undefined7 uVar7;
  byte bVar8;
  int local_18;
  uint local_14;
  undefined8 local_10;
  
  local_18 = (uint)*param_2 << 0x18;
  local_14 = (uint)*(ushort *)(param_2 + 1);
  local_10 = *(undefined8 *)(param_2 + 3);
  *param_5 = PTR_DAT_14000a058;
  *(uint *)(param_5 + 1) = (uint)*(ushort *)PTR_DAT_14000a058;
  *(undefined4 *)((longlong)param_5 + 0xc) = 2;
  param_5[2] = param_2 + 0xb;
  *(uint *)(param_5 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)param_5 + 0x1c) = 1;
  uVar4 = 0xc000000d;
  if (DAT_14000a078 == TlgAggregateInternalRegisteredProviderEtwCallback) {
    lVar3 = param_5[2];
    bVar8 = 0;
    uVar2 = *(uint *)(param_5 + 3);
    pcVar5 = (char *)(lVar3 + 2);
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 < '\0');
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    while (pcVar5 < (char *)((ulonglong)uVar2 + lVar3)) {
      do {
        pcVar6 = pcVar5;
        pcVar5 = pcVar6 + 1;
      } while (*pcVar6 != '\0');
      cVar1 = *pcVar5;
      uVar7 = (undefined7)(param_3 >> 8);
      param_3 = CONCAT71(uVar7,cVar1);
      if (-1 < cVar1) break;
      param_3 = CONCAT71(uVar7,cVar1) & 0xffffffffffffff7f;
      pcVar5 = pcVar6 + 3;
      if (-1 < pcVar6[2]) break;
      for (; cVar1 = *pcVar5, cVar1 < '\0'; pcVar5 = pcVar5 + 1) {
        if (cVar1 != -0x80) goto LAB_14000358c;
      }
      if (((char)param_3 != '\t') || (2 < (byte)(cVar1 + 0x8fU))) break;
      uVar4 = (ulonglong)bVar8;
      bVar8 = bVar8 + 1;
      *(char *)((longlong)param_5 + uVar4 * 0x10 + 0x2d) = cVar1;
    }
LAB_14000358c:
    if (bVar8 == 0) {
      uVar4 = EtwWriteTransfer(DAT_14000a070,&local_18,0,0,8,param_5);
    }
    else {
      uVar4 = InsertEventEntryInLookUpTable
                        (pcVar5,(undefined8 *)&local_18,param_3,(longlong)param_5,bVar8);
    }
  }
  return uVar4;
}



===== _guard_check_icall @ 1400035e0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1400035f8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000361c =====

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



===== __cpu_features_init @ 140003690 =====

/* WARNING: Removing unreachable block (ram,0x0001400036fa) */
/* WARNING: Removing unreachable block (ram,0x0001400036a9) */
/* WARNING: Removing unreachable block (ram,0x00014000369a) */

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



===== __security_check_cookie @ 140003760 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1400037a0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1400037d0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001400037d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140003800 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcmp @ 140003860 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_1400038a3;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_140003914;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_140003910:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140003914;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_14000390c:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140003910;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14000390c;
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
LAB_140003914:
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
LAB_1400038a3:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== memmove @ 140003980 =====

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



===== memset @ 140003c80 =====

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



===== __memset_repmovs @ 140003dc0 =====

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



===== __memset_query @ 140003e40 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140003ec0 =====

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



===== __memset_spec_ermsb_repmovsb @ 140004000 =====

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



===== __memset_spec_plain @ 140004080 =====

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



===== DamDriverUnload @ 140011010 =====

void DamDriverUnload(undefined8 param_1,undefined *param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined8 local_18;
  undefined4 local_10;
  undefined4 local_c;
  
  if ((Microsoft_Windows_DesktopActivityModeratorEnableBits & 1) != 0) {
    param_2 = &DamEvent_StopDriverBegin;
    McTemplateK0_EtwWriteTransfer(param_1,&DamEvent_StopDriverBegin,param_3);
  }
  puVar2 = &local_18;
  local_18 = 2;
  local_10 = 1;
  local_c = 1;
  DamSetState((longlong)puVar2);
  DamCloseRegistryEvents();
  DamCallbackShutdown();
  DampGlobalRundown(puVar2,param_2,param_3,param_4);
  if (DampDeviceObject != 0) {
    IoDeleteSymbolicLink(&DampWin32DeviceName);
    IoDeleteDevice(DampDeviceObject);
  }
  DampGlobalCleanup();
  DampDeviceObject = 0;
  DamDriverObject = 0;
  if (g_wil_details_featureChangeNotification != 0) {
    RtlUnregisterFeatureConfigurationChangeNotification();
    g_wil_details_featureChangeNotification = 0;
  }
  lVar3 = g_wil_details_featureUsageProvider;
  if (g_wil_details_featureUsageProvider != 0) {
    RtlUnregisterFeatureUsageProvider();
    g_wil_details_featureUsageProvider = 0;
  }
  g_wil_details_isFeatureStagingInitialized = 0;
  if ((Microsoft_Windows_DesktopActivityModeratorEnableBits & 1) != 0) {
    McTemplateK0_EtwWriteTransfer(lVar3,&DamEvent_StopDriverEnd,param_3);
  }
  McGenEventUnregister_EtwUnregister();
  uVar1 = DAT_14000a070;
  DAT_14000a070 = 0;
  DAT_14000a050 = 0;
  EtwUnregister(uVar1);
  return;
}



===== DamIsTestSigningOn @ 140011130 =====

undefined1 DamIsTestSigningOn(void)

{
  return DAT_14000d354;
}



===== DampCheckForceEnableDam @ 140011140 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool DampCheckForceEnableDam(void)

{
  int iVar1;
  bool bVar2;
  undefined1 auStack_98 [32];
  undefined4 local_78;
  uint *local_70;
  uint local_68 [2];
  longlong local_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  undefined *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined1 local_28 [4];
  int local_24;
  int local_1c;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_98;
  local_68[0] = 0;
  local_3c = 0;
  local_60 = 0;
  local_54 = 0;
  if (DAT_14000d354 == '\0') {
    return false;
  }
  local_50 = 0;
  local_58 = 0x30;
  local_48 = &DampPolicyRegistryPath;
  local_40 = 0x240;
  local_38 = 0;
  uStack_30 = 0;
  iVar1 = ZwOpenKey(&local_60,1,&local_58);
  if (-1 < iVar1) {
    local_70 = local_68;
    local_78 = 0x14;
    iVar1 = ZwQueryValueKey(local_60,&DampForceEnableDamValueName,2,local_28);
    if (((-1 < iVar1) && (local_24 == 4)) && (0xf < local_68[0])) {
      bVar2 = local_1c == 1;
      goto LAB_140011211;
    }
  }
  bVar2 = false;
LAB_140011211:
  if (local_60 != 0) {
    ZwClose();
  }
  return bVar2;
}



===== DampCheckTestSigningOn @ 14001124c =====

undefined1 DampCheckTestSigningOn(void)

{
  int iVar1;
  undefined1 uVar2;
  undefined4 local_res8 [2];
  ulonglong local_res10 [3];
  
  uVar2 = 0;
  local_res8[0] = 0;
  local_res10[0] = 8;
  iVar1 = ZwQuerySystemInformation(0x67,local_res10,8,local_res8);
  if ((-1 < iVar1) && ((local_res10[0] & 0x200000000) != 0)) {
    uVar2 = 1;
  }
  return uVar2;
}



===== DampIoDispatch @ 1400112a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DampIoDispatch(undefined8 param_1,longlong param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  ulonglong *puVar5;
  bool bVar6;
  bool bVar7;
  ulonglong uVar8;
  char cVar9;
  int iVar10;
  undefined8 uVar11;
  longlong lVar12;
  ushort *puVar13;
  undefined1 auStackY_e8 [32];
  char local_a8 [4];
  undefined4 local_a4;
  undefined8 local_a0;
  ushort *local_98;
  longlong local_90;
  longlong local_88;
  ushort local_80 [4];
  longlong lStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60 [4];
  char *local_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_e8;
  pcVar4 = *(char **)(param_2 + 0xb8);
  local_90 = 0;
  local_98 = (ushort *)0x0;
  bVar7 = true;
  local_a4 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_88 = 0;
  local_80[0] = 0;
  local_80[1] = 0;
  local_80[2] = 0;
  local_80[3] = 0;
  lStack_78 = 0;
  if (4 < DAT_14000a050) {
    if (((DAT_14000a060 & 1) == 0) || (bVar6 = true, (DAT_14000a068 & 1) != DAT_14000a068)) {
      bVar6 = false;
    }
    if (bVar6) {
      local_a8[0] = *pcVar4;
      local_40 = local_a8;
      local_38 = 1;
      _tlgWriteTransfer_EtwWriteTransfer(0x14000a050,&DAT_140007a85,0,0,3,local_60);
    }
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
  iVar10 = -0x3ffffff0;
  cVar9 = *pcVar4;
  if ((cVar9 == '\0') || (cVar9 == '\x02')) {
LAB_14001185f:
    iVar10 = 0;
  }
  else {
    if ((cVar9 != '\x0e') && (cVar9 != '\x0f')) goto LAB_140011862;
    iVar1 = *(int *)(pcVar4 + 0x18);
    iVar2 = *(int *)(pcVar4 + 0x10);
    iVar10 = 0;
    puVar5 = *(ulonglong **)(param_2 + 0x18);
    if (iVar1 == 0x226004) {
LAB_14001175f:
      if (DAT_14000d354 != '\0') {
        if ((*(longlong *)(pcVar4 + 0x30) != 0) &&
           ((*(uint *)(*(longlong *)(pcVar4 + 0x30) + 0x50) & 2) != 0)) {
          if (iVar1 == 0x226004) {
            if (*(uint *)(pcVar4 + 8) < 0x10) goto LAB_140011734;
            DampFreezeWorkerAcquireLockExclusive(0x14000d440);
            lVar12 = (longlong)DAT_14000d4b8;
            DampFreezeWorkerReleaseLockExclusive(0x14000d440);
            iVar10 = *(int *)(&DAT_1400072ec + lVar12 * 0x30);
            if ((iVar10 == 0) || (iVar10 == 1)) {
              *(uint *)(puVar5 + 1) = 1;
LAB_1400117e7:
              *(uint *)((longlong)puVar5 + 0xc) = 1;
            }
            else {
              if (iVar10 == 2) {
                *(uint *)(puVar5 + 1) = 2;
                goto LAB_1400117e7;
              }
              if (iVar10 == 3) {
                *(uint *)(puVar5 + 1) = 2;
                *(uint *)((longlong)puVar5 + 0xc) = 2;
              }
              else if (iVar10 == 4) {
                *(uint *)(puVar5 + 1) = 2;
                *(uint *)((longlong)puVar5 + 0xc) = 3;
              }
            }
            *(undefined8 *)(param_2 + 0x38) = 0x10;
            goto LAB_14001185f;
          }
          if (((iVar2 == 0x10) && (puVar5 != (ulonglong *)0x0)) && (*puVar5 < 2)) {
            if ((uint)puVar5[1] == 1) {
              if (*(uint *)((longlong)puVar5 + 0xc) == 1) goto LAB_14001183b;
            }
            else if (((uint)puVar5[1] == 2) &&
                    (((uVar3 = *(uint *)((longlong)puVar5 + 0xc), uVar3 == 1 || (uVar3 == 2)) ||
                     (uVar3 == 3)))) {
LAB_14001183b:
              cVar9 = DamSetState((longlong)puVar5);
              if (cVar9 == '\0') {
                iVar10 = -0x3ffffe7c;
                goto LAB_140011862;
              }
              *(ulonglong *)(*(longlong *)(pcVar4 + 0x30) + 0x18) = (ulonglong)(*puVar5 != 0);
              goto LAB_14001185f;
            }
          }
        }
LAB_140011725:
        iVar10 = -0x3ffffff3;
        goto LAB_140011862;
      }
    }
    else {
      if (iVar1 == 0x226014) {
        if (DAT_14000d354 == '\0') goto LAB_140011716;
        if (iVar2 != 4) goto LAB_140011725;
        if (3 < *(uint *)(pcVar4 + 8)) {
          iVar10 = DampNotificationGroupGet((ulonglong)(uint)*puVar5,(undefined4 *)puVar5);
          if (-1 < iVar10) {
            *(undefined8 *)(param_2 + 0x38) = 4;
          }
          goto LAB_140011862;
        }
LAB_140011734:
        iVar10 = -0x3fffffdd;
        goto LAB_140011862;
      }
      if (iVar1 == 0x22a008) goto LAB_14001175f;
      if (iVar1 == 0x22a01c) {
        puVar13 = (ushort *)0x0;
        if (iVar2 == 8) {
          iVar10 = PsLookupProcessByProcessId((uint)*puVar5,&local_98);
          if (-1 < iVar10) {
            uVar11 = PsGetProcessImageFileName(local_98);
            RtlInitAnsiString(&local_70,uVar11);
            iVar10 = RtlAnsiStringToUnicodeString(local_80,&local_70);
            if ((-1 < iVar10) &&
               (iVar10 = PsQueryProcessCommandLine(local_98,0), iVar10 == -0x3ffffffc)) {
              puVar13 = (ushort *)ExAllocatePool2(0x100,local_a4);
              if (puVar13 == (ushort *)0x0) {
                iVar10 = -0x3fffffe9;
              }
              else {
                iVar10 = PsQueryProcessCommandLine(local_98,puVar13);
                if (-1 < iVar10) {
                  iVar10 = PsGetProcessSessionId(local_98);
                  iVar10 = DampAddProcessToJobObject
                                     (local_98,local_80,puVar13,iVar10,
                                      *(ushort **)(local_98 + 0x198),'\x01');
                }
              }
            }
          }
        }
        else {
          iVar10 = -0x3ffffff3;
        }
        if (lStack_78 != 0) {
          RtlFreeUnicodeString(local_80);
        }
        if (local_98 != (ushort *)0x0) {
          ObfDereferenceObject();
        }
        if (puVar13 != (ushort *)0x0) {
          ExFreePoolWithTag(puVar13,0x4b6d6144);
        }
        goto LAB_140011862;
      }
      if (iVar1 == 0x22a020) {
        if (iVar2 == 8) {
          iVar10 = ObReferenceObjectByHandleWithTag(*puVar5,0x1f003f);
          if (-1 < iVar10) {
            iVar10 = PsGetJobSilo(local_90,&local_88);
            lVar12 = local_88;
            if (-1 < iVar10) {
              if (local_90 == local_88) {
                local_a0 = 0;
                iVar10 = ObReferenceObjectByHandleWithTag(DampS0JobInfo,0x1f003f);
                if (-1 < iVar10) {
                  iVar10 = PsAssignProcessToJobObject(lVar12,0);
                  if (iVar10 == -0x3fffffde) {
                    iVar10 = 0xff;
                  }
                  ObfDereferenceObjectWithTag(local_a0,0x4b6d6144);
                }
              }
              else {
                iVar10 = -0x3ffffaf7;
              }
            }
            ObfDereferenceObjectWithTag(local_90,0x4b6d6144);
          }
          goto LAB_140011862;
        }
        goto LAB_140011725;
      }
      if (iVar1 != 0x22a024) {
        if (iVar1 != 0x22a028) goto LAB_140011862;
        if (DAT_14000d355 != '\0') {
          if (iVar2 == 4) {
            uVar8 = *puVar5;
            if (4 < DAT_14000a050) {
              if (((DAT_14000a060 & 1) == 0) || (bVar6 = true, (DAT_14000a068 & 1) != DAT_14000a068)
                 ) {
                bVar6 = false;
              }
              if (bVar6) {
                local_40 = (char *)&local_a0;
                local_a0 = CONCAT44(local_a0._4_4_,(uint)uVar8);
                local_38 = 4;
                _tlgWriteTransfer_EtwWriteTransfer(0x14000a050,&DAT_140007a50,0,0,3,local_60);
              }
            }
            DampTestConfiguration = (uint)uVar8;
            goto LAB_14001185f;
          }
          goto LAB_140011725;
        }
      }
    }
LAB_140011716:
    iVar10 = -0x3fffff45;
  }
LAB_140011862:
  *(int *)(param_2 + 0x30) = iVar10;
  IofCompleteRequest(param_2,0);
  if (4 < DAT_14000a050) {
    if (((DAT_14000a060 & 1) == 0) || ((DAT_14000a068 & 1) != DAT_14000a068)) {
      bVar7 = false;
    }
    if (bVar7) {
      local_40 = (char *)&local_a0;
      local_a0 = CONCAT44(local_a0._4_4_,iVar10);
      local_38 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(0x14000a050,&DAT_140007a28,0,0,3,local_60);
    }
  }
  return iVar10;
}



===== DampNotificationGroupGet @ 140011918 =====

int DampNotificationGroupGet(ulonglong param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  longlong lVar4;
  int local_res8 [4];
  longlong local_res18;
  longlong local_res20;
  longlong local_68;
  ulonglong local_60 [2];
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  undefined *local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 uStack_28;
  
  local_res20 = -1;
  local_34 = 0;
  local_res8[0] = 0;
  local_68 = 0;
  local_4c = 0;
  local_60[0] = 0;
  local_60[1] = 0;
  local_res18 = PsGetCurrentProcess();
  uVar3 = PsGetCurrentProcessId();
  if (uVar3 != (param_1 & 0xffffffff)) {
    local_48 = 0;
    local_40 = (undefined *)0x0;
    local_50 = 0x30;
    local_38 = 0x200;
    local_30 = 0;
    uStack_28 = 0;
    local_60[0] = param_1 & 0xffffffff;
    iVar1 = ZwOpenProcess(&local_res20,0x1fffff,&local_50,local_60);
    if (iVar1 < 0) goto LAB_140011a84;
    iVar1 = ObReferenceObjectByHandleWithTag
                      (local_res20,0x1fffff,*(undefined8 *)PsProcessType_exref,0,0x4b6d6144,
                       &local_res18,0);
    if (iVar1 < 0) goto LAB_140011a84;
  }
  local_48 = 0;
  local_40 = &DamExemptCheckCallbackName;
  local_50 = 0x30;
  local_38 = 0x240;
  local_30 = 0;
  uStack_28 = 0;
  iVar1 = ExCreateCallback(&local_68,&local_50,0,0);
  if (-1 < iVar1) {
    ExNotifyCallback(local_68,local_res18,local_res8);
    if (local_res8[0] == 1) {
      uVar2 = 1;
    }
    else {
      uVar2 = 2;
      if (local_res8[0] != 3) {
        if (local_res8[0] == 4) {
          uVar2 = 0;
        }
        else {
          uVar2 = 3;
        }
      }
    }
    *param_2 = uVar2;
  }
LAB_140011a84:
  lVar4 = PsGetCurrentProcess();
  if (local_res18 != lVar4) {
    ObfDereferenceObjectWithTag(local_res18,0x4b6d6144);
  }
  if (local_res20 != -1) {
    ZwClose();
  }
  if (local_68 != 0) {
    ObfDereferenceObject();
  }
  return iVar1;
}



===== wil_details_EvaluateFeatureDependencies @ 140011aec =====

void wil_details_EvaluateFeatureDependencies(void)

{
  uint uVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  bool bVar5;
  
  puVar4 = (undefined *)0x0;
  ppuVar3 = &wil_details_featureDescriptors_a;
  ppuVar2 = &wil_details_featureDescriptors_a;
  do {
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x000140011b27;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_140011ba1:
  while( true ) {
    if (&UNK_14000969f < ppuVar3) {
      return;
    }
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  do {
    if (ppuVar3 == (undefined **)0x0) {
      return;
    }
    wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
              ((uint *)*ppuVar3,(longlong)ppuVar3);
    ppuVar3 = ppuVar3 + 7;
    while( true ) {
      if (&UNK_14000969f < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x000140011b27:
  while (ppuVar2 != (undefined **)0x0) {
    uVar1 = *(uint *)*ppuVar2;
    if ((uVar1 >> 9 & 1) != 0) {
      if ((uVar1 & 0x180) == 0) {
        bVar5 = *(char *)((longlong)ppuVar2 + 0x1f) != '\0';
      }
      else {
        bVar5 = (uVar1 & 0x180) == 0x100;
      }
      LOCK();
      *(uint *)*ppuVar2 = *(uint *)*ppuVar2 ^ uVar1 & 0x40 ^ (uint)bVar5 << 6;
      UNLOCK();
    }
    ppuVar2 = ppuVar2 + 7;
    while( true ) {
      if (&UNK_14000969f < ppuVar2) goto LAB_140011ba1;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_140011ba1;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 140011bdc =====

uint wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
               (uint *param_1,longlong param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  longlong *plVar5;
  uint uVar6;
  bool bVar7;
  
  uVar6 = *param_1;
  if ((uVar6 >> 9 & 1) == 0) {
    uVar3 = uVar6;
  }
  else {
    uVar4 = uVar6 >> 6 & 1;
    if ((uVar4 != 0) && (plVar5 = *(longlong **)(param_2 + 0x20), plVar5 != (longlong *)0x0)) {
      do {
        while( true ) {
          puVar1 = (undefined8 *)*plVar5;
          if (puVar1 == (undefined8 *)0x0) goto LAB_140011c74;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_140011c74;
          }
          uVar4 = 1;
          plVar5 = plVar5 + 1;
        }
        uVar2 = wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
                          ((uint *)*puVar1,(longlong)puVar1);
        if ((uVar4 == 0) || ((uVar2 & 1) == 0)) {
          uVar4 = 0;
        }
        else {
          uVar4 = 1;
        }
        plVar5 = plVar5 + 1;
      } while (uVar4 != 0);
    }
LAB_140011c74:
    do {
      uVar2 = uVar6 & 0xffffffce;
      if ((uVar6 & 1) == uVar4) {
        uVar2 = uVar6 & 0xfffffffe;
      }
      uVar3 = uVar2 & 0xfffffdff | uVar4;
      LOCK();
      uVar2 = *param_1;
      bVar7 = uVar6 == uVar2;
      if (bVar7) {
        *param_1 = uVar3;
      }
      else {
        uVar6 = uVar2;
      }
      UNLOCK();
    } while (!bVar7);
  }
  return uVar3;
}



===== wil_details_OnFeatureUsageProviderFlushNotification @ 140011cc0 =====

void wil_details_OnFeatureUsageProviderFlushNotification(int param_1)

{
  int iVar1;
  undefined **ppuVar2;
  
  iVar1 = g_wil_details_featureUsageCached;
  if (param_1 == 1) {
    LOCK();
    g_wil_details_featureUsageCached = 0;
    UNLOCK();
    if (iVar1 != 0) {
      for (ppuVar2 = &wil_details_featureDescriptors_a; ppuVar2 < &wil_details_featureDescriptors_z;
          ppuVar2 = ppuVar2 + 1) {
        if (*ppuVar2 != (undefined *)0x0) {
          do {
            if (ppuVar2 == (undefined **)0x0) {
              return;
            }
            if ((*(uint *)ppuVar2[1] & 1) != 0) {
              wil_details_RecordCachedUsage(*(undefined4 *)(ppuVar2 + 3),(uint *)ppuVar2[1]);
            }
            ppuVar2 = ppuVar2 + 7;
            while( true ) {
              if (&UNK_14000969f < ppuVar2) {
                return;
              }
              if (*ppuVar2 != (undefined *)0x0) break;
              ppuVar2 = ppuVar2 + 1;
            }
          } while( true );
        }
      }
    }
  }
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 140011d40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  int iVar1;
  uint uVar2;
  undefined **ppuVar3;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 local_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  for (ppuVar3 = &wil_details_featureDescriptors_a; ppuVar3 < &wil_details_featureDescriptors_z;
      ppuVar3 = ppuVar3 + 1) {
    if (*ppuVar3 != (undefined *)0x0) goto LAB_140011e3d;
  }
LAB_140011e46:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_140011e3d:
  if (ppuVar3 == (undefined **)0x0) goto LAB_140011e46;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_140011e0e:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_140011e0e;
        uVar2 = local_20._4_4_ & 0x80;
      }
      uVar2 = uVar2 << 3 | 0x206;
    }
    LOCK();
    *(uint *)*ppuVar3 = *(uint *)*ppuVar3 ^ (*(uint *)*ppuVar3 ^ uVar2) & 0xf80;
    UNLOCK();
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_14000969f < ppuVar3) goto LAB_140011e46;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_140011e3d;
}



===== DamAggregateEventsCallbackInitialize @ 140011e6c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DamAggregateEventsCallbackInitialize(void)

{
  undefined1 auStack_78 [32];
  undefined8 local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 *local_48;
  undefined8 local_40;
  code *local_38;
  code *local_30;
  undefined8 local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_78;
  local_20 = 0x41840b3ea3bdb075;
  local_58 = 0;
  local_50 = 0;
  local_28 = 0;
  local_40 = 1;
  local_48 = &local_20;
  local_4c = 1;
  local_38 = DampAudioPlaybackStartCallback;
  local_30 = DampAudioPlaybackStopCallback;
  EACreateAggregateEvent(&local_58,&DampAudioEventHandle);
  return;
}



===== DamAggregateEventsCallbackShutdown @ 140011ef8 =====

void DamAggregateEventsCallbackShutdown(void)

{
  if (DampAudioEventHandle != 0) {
    EADeleteAggregateEvent();
    DampAudioEventHandle = 0;
  }
  return;
}



===== DamCallbackInitialize @ 140011f28 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong DamCallbackInitialize(void)

{
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong local_res8;
  longlong local_res10;
  undefined4 local_68;
  undefined4 local_64;
  undefined *local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined *local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_48 = 0x30;
  local_40 = 0;
  local_38 = &DamExemptCheckCallbackName;
  local_30 = 0x250;
  local_res8 = 0;
  local_res10 = 0;
  _DamStateMutex = 1;
  local_28 = 0;
  uStack_20 = 0;
  lVar2 = 0;
  DAT_14000d2e8 = 0;
  _DAT_14000d2f0 = 0;
  KeInitializeEvent(&DAT_14000d2f8,1,0);
  _DAT_14000d338 = &DampUserContextList;
  DampUserContextList = &DampUserContextList;
  _DAT_14000d348 = &DampPowerStateList;
  _DampPowerStateList = &DampPowerStateList;
  uVar1 = ExCreateCallback(&local_res8,&local_48,1,0);
  uVar4 = (ulonglong)uVar1;
  if (-1 < (int)uVar1) {
    lVar2 = ExRegisterCallback(local_res8,DampExemptCheckCallbackRoutine,0);
    if (lVar2 == 0) {
      uVar4 = 0xc0000001;
    }
    else {
      uVar1 = DampCreateExemptGroupInfo(&DampS0JobInfo);
      uVar4 = (ulonglong)uVar1;
      if (-1 < (int)uVar1) {
        local_58 = 0;
        _DampKernelCalloutTable = DampCreateProcessCallback;
        local_68 = 0x10007;
        local_60 = &DampKernelCalloutTable;
        local_50 = DamDriverObject;
        local_64 = 0x10000;
        uVar1 = ExRegisterExtension(&local_res10,0x10001,&local_68);
        uVar4 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          uVar3 = DampSubscribePdc();
          uVar4 = uVar3 & 0xffffffff;
          if (-1 < (int)uVar3) {
            DampExemptCheckCallbackRegistration = lVar2;
            DampExemptCheckCallback = local_res8;
            DampCallbacksInitialized = 1;
            DampKernelExtensionRegistration = local_res10;
            return uVar4;
          }
        }
        DampDestroyExemptGroupInfo(&DampS0JobInfo);
      }
    }
  }
  if (local_res10 != 0) {
    ExUnregisterExtension();
  }
  if (lVar2 != 0) {
    ExUnregisterCallback(lVar2);
  }
  if (local_res8 != 0) {
    ObMakeTemporaryObject();
    ObfDereferenceObject(local_res8);
  }
  return uVar4;
}



===== DamCallbackShutdown @ 140012130 =====

void DamCallbackShutdown(void)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  longlong *plVar5;
  undefined1 *puVar6;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  if (DampCallbacksInitialized != '\0') {
    DampUnsubscribePdc();
    if (DampKernelExtensionRegistration != 0) {
      ExUnregisterExtension();
      DampKernelExtensionRegistration = 0;
    }
    if (DampExemptCheckCallbackRegistration != 0) {
      ExUnregisterCallback();
      DampExemptCheckCallbackRegistration = 0;
    }
    if (DampExemptCheckCallback != 0) {
      ObMakeTemporaryObject();
      ObfDereferenceObject(DampExemptCheckCallback);
      DampExemptCheckCallback = 0;
    }
    while( true ) {
      plVar5 = DampUserContextList;
      puVar6 = auStack_28;
      if ((longlong **)DampUserContextList == &DampUserContextList) break;
      plVar1 = DampUserContextList + -0x2a;
      lVar2 = *DampUserContextList;
      if ((*(longlong **)(lVar2 + 8) != DampUserContextList) ||
         (plVar3 = (longlong *)DampUserContextList[1], (longlong *)*plVar3 != DampUserContextList))
      {
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3);
        puVar6 = auStack_20;
        break;
      }
      *plVar3 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar3;
      plVar5[1] = (longlong)plVar5;
      *plVar5 = (longlong)plVar5;
      DampDestroyExemptGroupInfo(plVar1);
      ExFreePoolWithTag(plVar1,0x4b6d6144);
    }
    *(undefined8 *)(puVar6 + -8) = 0x14001222d;
    DampDestroyExemptGroupInfo(&DampS0JobInfo);
    DampCallbacksInitialized = '\0';
  }
  return;
}



===== DamSetState @ 140012244 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 DamSetState(longlong param_1)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined1 uVar5;
  
  DampFreezeWorkerAcquireLockExclusive(0x14000d440);
  _DAT_14000d4b0 = _DAT_14000d4b0 | 2;
  if (((DAT_14000d4bc & 1) == 0) && (*(int *)(param_1 + 8) == 2)) {
    bVar1 = DampUserSessionDelayEnabledGet();
    DAT_14000d4bc = ((uint)bVar1 << 5 ^ DAT_14000d4bc) & 0x20 ^ DAT_14000d4bc;
  }
  uVar5 = 0;
  uVar3 = 0;
  if (*(int *)(param_1 + 0xc) == 2) {
    uVar3 = 2;
  }
  uVar2 = 0;
  if (*(int *)(param_1 + 0xc) == 3) {
    uVar2 = 4;
  }
  bVar1 = *(int *)(param_1 + 8) == 2;
  uVar4 = -(uint)(uVar2 != 0 || uVar3 != 0) & 0x40;
  DAT_14000d4bc = uVar4 | (uint)bVar1 | uVar2 | uVar3 | DAT_14000d4bc & 0xffffffb8;
  if (((bVar1) || (((uVar3 == 0 && (uVar2 == 0)) && (uVar4 == 0)))) &&
     ((byte)((byte)uVar2 | (byte)uVar3) != 6)) {
    bVar1 = DampFreezeWorkerUpdatePostAndUnlock(&DAT_14000d440);
    if (bVar1) {
      KeWaitForSingleObject(&DAT_14000d480,0,0,0,0);
    }
    uVar5 = 1;
  }
  else {
    DampFreezeWorkerUpdatePostAndUnlock(&DAT_14000d440);
  }
  return uVar5;
}



===== DamWnfDevicePowerTransitionUpdate @ 140012370 =====

undefined8 DamWnfDevicePowerTransitionUpdate(void)

{
  undefined1 local_res20 [8];
  longlong in_stack_00000030;
  int local_18 [6];
  
  local_18[0] = 0;
  local_18[1] = 4;
  ZwQueryWnfStateData(in_stack_00000030 + 0x28,0,0,local_res20,local_18,local_18 + 1);
  DampFreezeWorkerAcquireLockExclusive(0x14000d440);
  DAT_14000d4bc = DAT_14000d4bc & 0xffffffef | -(uint)(local_18[0] != 0) & 0x10;
  DampFreezeWorkerUpdatePostAndUnlock(&DAT_14000d440);
  return 0;
}



===== DampAddProcessToJobObject @ 1400123f8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DampAddProcessToJobObject
              (ushort *param_1,ushort *param_2,ushort *param_3,int param_4,ushort *param_5,
              char param_6)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  ulonglong uVar6;
  ushort *puVar7;
  undefined8 uVar8;
  ushort *puVar9;
  undefined8 *puVar10;
  ushort *puVar11;
  undefined8 *puVar12;
  undefined1 auStackY_178 [32];
  char local_138;
  undefined1 local_137 [3];
  int local_134;
  undefined8 *local_130;
  longlong local_128;
  ushort *local_120;
  ushort *local_118 [2];
  undefined8 local_108 [4];
  int *local_e8;
  undefined4 local_e0;
  undefined4 local_dc;
  ushort **local_d8;
  undefined8 local_d0;
  uint *local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  uint local_b0 [2];
  uint *local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  uint local_90 [2];
  ushort **local_88;
  undefined8 local_80;
  char *local_78;
  undefined8 local_70;
  undefined8 **local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_178;
  local_128 = 0;
  bVar2 = false;
  local_118[0] = param_5;
  local_130 = (undefined8 *)0x0;
  iVar4 = 4;
  local_134 = param_4;
  local_120 = param_2;
  if (param_4 == 0) {
    puVar12 = &DampS0JobInfo;
  }
  else {
    iVar3 = DampGetSessionContext(param_4,&local_130);
    puVar10 = local_130;
    if (iVar3 < 0) goto LAB_14001256d;
    puVar12 = local_130;
  }
  puVar10 = local_130;
  puVar11 = (ushort *)0x0;
  iVar3 = ObOpenObjectByPointer(param_1);
  iVar4 = 4;
  bVar2 = false;
  if (-1 < iVar3) {
    puVar9 = (ushort *)0x0;
    iVar3 = ZwIsProcessInJob(local_128);
    iVar4 = 4;
    bVar2 = false;
    if (iVar3 == 0x123) {
      puVar7 = param_1;
      bVar2 = DampShouldRegisterProcessAtLaunch();
      if ((bVar2) || (iVar4 = 4, param_6 == '\x01')) {
        puVar7 = param_1;
        puVar9 = local_118[0];
        puVar11 = param_3;
        uVar6 = DamPolicyGetProcessExemptionGroup(param_1,local_118[0],param_3);
        iVar4 = (int)uVar6;
        if (iVar4 != 0) goto LAB_14001251c;
        uVar8 = *puVar12;
      }
      else {
LAB_14001251c:
        if ((Microsoft_Windows_DesktopActivityModeratorEnableBits & 8) != 0) {
          McTemplateK0qqqt_EtwWriteTransfer
                    (puVar7,puVar9,puVar11,*(undefined4 *)(param_1 + 0xe8),(char)local_134,
                     (char)iVar4,bVar2);
        }
        if (3 < iVar4) goto LAB_140012566;
        uVar8 = puVar12[(longlong)iVar4 * 10];
      }
      ZwAssignProcessToJobObject(uVar8);
    }
LAB_140012566:
    iVar3 = 0;
  }
  param_4 = local_134;
LAB_14001256d:
  if (local_128 != 0) {
    ZwClose();
  }
  if (puVar10 != (undefined8 *)0x0) {
    ExReleaseRundownProtection(puVar10 + 0x29);
  }
  if (DAT_14000a050 != 0) {
    if (param_3 == (ushort *)0x0) {
      param_3 = &DampEmptyString;
    }
    puVar11 = local_120;
    if (local_120 == (ushort *)0x0) {
      puVar11 = &DampEmptyString;
    }
    if (5 < DAT_14000a050) {
      if (((DAT_14000a060 & 1) == 0) || (((uint)DAT_14000a068 & 1) != DAT_14000a068)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        local_dc = 0;
        local_e8 = &local_134;
        local_e0 = 4;
        local_134 = iVar3;
        uVar5 = PsGetProcessId(param_1);
        local_d0 = 4;
        local_120 = (ushort *)CONCAT44(local_120._4_4_,uVar5);
        local_d8 = &local_120;
        local_b0[1] = 0;
        local_c8 = local_b0;
        local_90[1] = 0;
        local_b8 = *(undefined8 *)(puVar11 + 4);
        local_b0[0] = (uint)*puVar11;
        local_a8 = local_90;
        local_98 = *(undefined8 *)(param_3 + 4);
        local_90[0] = (uint)*param_3;
        local_88 = local_118;
        local_138 = param_6;
        local_78 = &local_138;
        local_68 = &local_130;
        local_58 = local_137;
        local_c0 = 2;
        local_a0 = 2;
        local_118[0] = (ushort *)CONCAT44(local_118[0]._4_4_,param_4);
        local_80 = 4;
        local_70 = 1;
        local_130 = (undefined8 *)CONCAT44(local_130._4_4_,iVar4);
        local_60 = 4;
        local_50 = 1;
        local_137[0] = bVar2;
        _tlgWriteTransfer_EtwWriteTransfer(0x14000a050,&DAT_140007d8c,0,0,0xc,local_108);
      }
    }
  }
  return iVar3;
}



===== DampAudioPlaybackStartCallback @ 140012730 =====

void DampAudioPlaybackStartCallback(void)

{
  DampFreezeWorkerAcquireLockExclusive(0x14000d440);
  DAT_14000d4bc = DAT_14000d4bc | 8;
  DampFreezeWorkerUpdatePostAndUnlock(&DAT_14000d440);
  return;
}



===== DampAudioPlaybackStopCallback @ 140012760 =====

void DampAudioPlaybackStopCallback(void)

{
  DampFreezeWorkerAcquireLockExclusive(0x14000d440);
  DAT_14000d4bc = DAT_14000d4bc & 0xfffffff7;
  DampFreezeWorkerUpdatePostAndUnlock(&DAT_14000d440);
  return;
}



===== DampCreateExemptGroupInfo @ 140012790 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DampCreateExemptGroupInfo(longlong *param_1)

{
  int iVar1;
  longlong *plVar2;
  uint uVar3;
  undefined1 auStack_118 [32];
  undefined1 local_f8 [8];
  longlong local_f0 [4];
  undefined4 local_d0;
  undefined4 local_cc;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined1 local_b8 [16];
  undefined4 local_a8;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_118;
  memset(param_1,0,0x140);
  uVar3 = 0;
  plVar2 = param_1;
  while( true ) {
    memset(local_b8,0,0x90);
    local_cc = 0;
    local_f0[0] = 0;
    local_f0[2] = 0;
    local_f0[3] = 0;
    local_f0[1] = 0x30;
    local_c8 = 0;
    uStack_c0 = 0;
    local_f8[0] = 0;
    local_d0 = 0x200;
    iVar1 = ZwCreateJobObject(local_f0,0x1f003f,local_f0 + 1);
    if (-1 < iVar1) {
      local_f8[0] = 1;
      iVar1 = ZwSetInformationJobObject(local_f0[0],0x17,local_f8);
      if (-1 < iVar1) {
        memset(local_b8,0,0x90);
        local_a8 = 0x1800;
        iVar1 = ZwSetInformationJobObject(local_f0[0],9,local_b8,0x90);
        if (-1 < iVar1) {
          *plVar2 = local_f0[0];
          iVar1 = 0;
          local_f0[0] = 0;
        }
      }
    }
    if (local_f0[0] != 0) {
      ZwClose();
    }
    if (iVar1 < 0) break;
    uVar3 = uVar3 + 1;
    plVar2 = plVar2 + 10;
    if (3 < uVar3) {
      return 0;
    }
  }
  DampDestroyExemptGroupInfo(param_1);
  return iVar1;
}



===== DampCreateProcessCallback @ 140012920 =====

void DampCreateProcessCallback(ushort *param_1,undefined4 param_2,longlong *param_3)

{
  ushort *puVar1;
  uint uVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  longlong *plVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  
  plVar6 = param_3;
  uVar2 = PsGetProcessSessionIdEx();
  if (uVar2 != 0xffffffff) {
    if (param_3 == (longlong *)0x0) {
      puVar3 = DampProcessTreeRemove(0x14000d4c0,(ulonglong)param_1);
      if (puVar3 != (undefined8 *)0x0) {
        DampProcessTreeNodeDelete((longlong)puVar3);
        DampHandleProcessTermination((longlong)param_1,(ulonglong)uVar2,plVar6);
      }
    }
    else {
      puVar3 = DampProcessTreeInsert(0x14000d4c0,(ulonglong)param_1);
      if (puVar3 != (undefined8 *)0x0) {
        if ((Microsoft_Windows_DesktopActivityModeratorEnableBits & 4) != 0) {
          puVar1 = (ushort *)param_3[7];
          if (puVar1 == (ushort *)0x0) {
            uVar5 = 0;
            uVar4 = 0;
          }
          else {
            uVar5 = *(undefined8 *)(puVar1 + 4);
            uVar4 = (ulonglong)(*puVar1 >> 1);
          }
          puVar1 = (ushort *)param_3[6];
          if (puVar1 == (ushort *)0x0) {
            uVar8 = 0;
            uVar7 = 0;
          }
          else {
            uVar8 = *(undefined8 *)(puVar1 + 4);
            uVar7 = (ulonglong)(*puVar1 >> 1);
          }
          McTemplateK0qqhzr2hzr4_EtwWriteTransfer
                    (uVar4,uVar5,uVar7,param_2,(char)uVar2,(ushort)uVar7,uVar8,(ushort)uVar4,uVar5);
        }
        DampAddProcessToJobObject
                  (param_1,(ushort *)param_3[6],(ushort *)param_3[7],uVar2,(ushort *)param_3[5],'\0'
                  );
      }
    }
  }
  return;
}



===== DampDestroyExemptGroupInfo @ 140012a34 =====

void DampDestroyExemptGroupInfo(longlong *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  
  lVar2 = 4;
  plVar1 = param_1;
  do {
    if (plVar1[1] != 0) {
      ExUnsubscribeWnfStateChange();
    }
    if (*plVar1 != 0) {
      ZwClose();
    }
    plVar1 = plVar1 + 10;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  memset(param_1,0,0x140);
  return;
}



===== DampExemptCheckCallbackRoutine @ 140012ab0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DampExemptCheckCallbackRoutine(undefined8 param_1,longlong param_2,undefined4 *param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  uint uVar8;
  undefined1 auStackY_108 [32];
  undefined1 local_c8 [4];
  int local_c4;
  int local_c0;
  uint local_bc;
  longlong local_b8;
  undefined8 local_a8 [4];
  int *local_88;
  undefined4 local_80;
  undefined4 local_7c;
  int *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined1 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  uint *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_108;
  local_b8 = 0;
  uVar8 = 0xffffffff;
  iVar2 = PsGetProcessSessionIdEx(param_2);
  if (4 < DAT_14000a050) {
    if (((DAT_14000a060 & 1) == 0) || (((uint)DAT_14000a068 & 1) != DAT_14000a068)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      local_7c = 0;
      local_88 = &local_c4;
      local_80 = 4;
      local_c4 = iVar2;
      _tlgWriteTransfer_EtwWriteTransfer(0x14000a050,&DAT_140007e6c,0,0,3,local_a8);
    }
  }
  lVar4 = PsGetCurrentProcess();
  if (param_2 == lVar4) {
    lVar4 = -1;
  }
  else {
    iVar3 = ObOpenObjectByPointer(param_2,0x200);
    if (iVar3 < 0) {
      *param_3 = 4;
      goto LAB_140012cc4;
    }
    lVar4 = local_b8;
  }
  KeEnterCriticalRegion();
  ExAcquireFastMutexUnsafe(&DamStateMutex);
  if (iVar2 == 0) {
    puVar7 = (undefined8 *)0x0;
    puVar5 = &DampS0JobInfo;
  }
  else {
    for (puVar5 = DampUserContextList; (undefined8 **)puVar5 != &DampUserContextList;
        puVar5 = (undefined8 *)*puVar5) {
      puVar7 = puVar5 + -0x2a;
      if (*(int *)(puVar5 + -2) == iVar2) {
        ExAcquireRundownProtection(puVar5 + -1);
        goto LAB_140012c28;
      }
    }
    puVar7 = (undefined8 *)0x0;
LAB_140012c28:
    puVar5 = puVar7;
  }
  uVar8 = 0;
  do {
    iVar3 = ZwIsProcessInJob(lVar4,*puVar5);
    if (iVar3 == 0x124) {
      iVar3 = 0;
      uVar6 = DampGetPoClientFromDamExemptGroup(uVar8);
      *param_3 = (int)uVar6;
      goto LAB_140012c8d;
    }
    if (iVar3 < 0) break;
    iVar3 = 0;
    uVar8 = uVar8 + 1;
    puVar5 = puVar5 + 10;
  } while (uVar8 < 3);
  *param_3 = 4;
LAB_140012c8d:
  if (puVar7 != (undefined8 *)0x0) {
    ExReleaseRundownProtection(puVar7 + 0x29);
  }
  ExReleaseFastMutexUnsafe(&DamStateMutex);
  KeLeaveCriticalRegion();
LAB_140012cc4:
  if (local_b8 != 0) {
    ZwClose();
  }
  if (4 < DAT_14000a050) {
    if (((DAT_14000a060 & 1) == 0) || (((uint)DAT_14000a068 & 1) != DAT_14000a068)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      local_7c = 0;
      local_88 = &local_c4;
      local_6c = 0;
      local_5c = 0;
      local_4c = 0;
      local_78 = &local_c0;
      local_c8[0] = *(undefined1 *)param_3;
      local_68 = local_c8;
      local_58 = &local_bc;
      local_80 = 4;
      local_70 = 4;
      local_60 = 1;
      local_50 = 4;
      local_c4 = iVar2;
      local_c0 = iVar3;
      local_bc = uVar8;
      _tlgWriteTransfer_EtwWriteTransfer(0x14000a050,&DAT_140007e0d,0,0,6,local_a8);
    }
  }
  return;
}



===== DampFreezeUserSessionJob @ 140012db8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DampFreezeUserSessionJob(longlong param_1,int param_2,byte param_3)

{
  bool bVar1;
  bool bVar2;
  undefined1 auStackY_e8 [32];
  undefined1 local_b8;
  byte local_b7 [3];
  undefined4 local_b4;
  undefined4 local_b0;
  uint uStack_ac;
  undefined8 uStack_a8;
  undefined8 local_88 [4];
  undefined4 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined1 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  byte *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_e8;
  bVar1 = true;
  if (4 < DAT_14000a050) {
    if (((DAT_14000a060 & 2) == 0) || (((uint)DAT_14000a068 & 2) != DAT_14000a068)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      local_b4 = *(undefined4 *)(param_1 + 0x140);
      local_5c = 0;
      local_4c = 0;
      local_3c = 0;
      local_68 = &local_b4;
      local_58 = &local_b8;
      local_48 = local_b7;
      local_60 = 4;
      local_b8 = (undefined1)param_2;
      local_50 = 1;
      local_40 = 1;
      local_b7[0] = param_3;
      _tlgWriteTransfer_EtwWriteTransfer(0x14000a050,&DAT_14000809b,0,0,5,local_88);
    }
  }
  uStack_a8 = 0;
  _local_b0 = CONCAT44((uint)param_3,9);
  ZwSetInformationJobObject(*(undefined8 *)(param_1 + (longlong)param_2 * 0x50),0x12);
  if (4 < DAT_14000a050) {
    if (((DAT_14000a060 & 2) == 0) || (((uint)DAT_14000a068 & 2) != DAT_14000a068)) {
      bVar1 = false;
    }
    if (bVar1) {
      _tlgWriteTransfer_EtwWriteTransfer(0x14000a050,&DAT_140008076,0,0,2,(undefined8 *)&local_b0);
    }
  }
  return;
}



===== DampFreezeUserSessions @ 140012f34 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DampFreezeUserSessions(int param_1,byte param_2)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined1 auStackY_b8 [32];
  byte local_88 [4];
  int local_84 [3];
  undefined8 local_78 [4];
  int *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  byte *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_b8;
  bVar1 = true;
  if (5 < DAT_14000a050) {
    if (((DAT_14000a060 & 2) == 0) || (((uint)DAT_14000a068 & 2) != DAT_14000a068)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      local_4c = 0;
      local_58 = local_84;
      local_3c = 0;
      local_48 = local_88;
      local_50 = 4;
      local_40 = 1;
      local_88[0] = param_2;
      local_84[0] = param_1;
      _tlgWriteTransfer_EtwWriteTransfer(0x14000a050,&DAT_140007fe3,0,0,4,local_78);
    }
  }
  puVar4 = DampUserContextList;
  if ((undefined8 **)DampUserContextList != &DampUserContextList) {
    do {
      if (param_1 == 0) {
        iVar3 = 0;
LAB_140013018:
        DampFreezeUserSessionJob((longlong)(puVar4 + -0x2a),iVar3,param_2);
      }
      else if ((param_1 == 1) || (param_1 == 2)) {
        iVar3 = param_1;
        goto LAB_140013018;
      }
      puVar4 = (undefined8 *)*puVar4;
    } while ((undefined8 **)puVar4 != &DampUserContextList);
  }
  if (5 < DAT_14000a050) {
    if (((DAT_14000a060 & 2) == 0) || (((uint)DAT_14000a068 & 2) != DAT_14000a068)) {
      bVar1 = false;
    }
    if (bVar1) {
      _tlgWriteTransfer_EtwWriteTransfer(0x14000a050,&DAT_140007fc0,0,0,2,local_78);
    }
  }
  return;
}



===== DampFreezeWorkerAcquireLockExclusive @ 1400130a8 =====

void DampFreezeWorkerAcquireLockExclusive(longlong param_1)

{
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(param_1 + 0x60,0);
  *(void **)(param_1 + 0x68) = SystemReserved1[0xf];
  return;
}



===== DampFreezeWorkerHandleFreezeEvent @ 1400130ec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 DampFreezeWorkerHandleFreezeEvent(ulonglong param_1)

{
  undefined8 *puVar1;
  uint uVar2;
  bool bVar3;
  bool bVar4;
  longlong lVar5;
  uint uVar6;
  uint uVar7;
  undefined *puVar8;
  ulonglong *puVar9;
  undefined1 *puVar10;
  uint uVar11;
  undefined1 auStackY_148 [32];
  undefined1 local_118;
  undefined1 local_117;
  undefined1 local_116;
  ulonglong local_110;
  ulonglong local_108;
  ulonglong local_100;
  ulonglong local_f8;
  ulonglong local_f0;
  ulonglong local_e8;
  undefined8 *local_e0;
  undefined8 *local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined4 local_c0;
  undefined1 local_bc;
  undefined2 local_bb;
  undefined1 local_b9;
  undefined8 local_b8 [4];
  ulonglong *local_98;
  undefined8 local_90;
  ulonglong *local_88;
  undefined8 local_80;
  ulonglong *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  ulonglong *local_58;
  undefined8 local_50;
  ulonglong *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  lVar5 = _DAT_fffff78000000320;
  local_38 = __security_cookie ^ (ulonglong)auStackY_148;
  local_108 = local_108 & 0xffffffff00000000;
  local_117 = 0;
  puVar1 = (undefined8 *)(param_1 + 0xe0);
  local_f8 = param_1;
  DampFreezeWorkerAcquireLockExclusive((longlong)puVar1);
  uVar2 = *(uint *)(param_1 + 0x150);
  bVar4 = true;
  local_118 = (uVar2 & 2) != 0;
  *(uint *)(param_1 + 0x150) = uVar2 & 0xfffffffd;
  if ((uVar2 & 1) == 0) {
    uVar11 = *(uint *)(param_1 + 0x158);
    local_116 = 0;
    uVar6 = DampStateSystemComputePhase((uint *)(param_1 + 0x15c));
    *(uint *)(param_1 + 0x154) = uVar6;
    DampFreezeWorkerReleaseLockExclusive((longlong)puVar1);
    if (4 < DAT_14000a050) {
      if (((DAT_14000a060 & 0x80) == 0) || (((uint)DAT_14000a068 & 0x80) != DAT_14000a068)) {
        bVar3 = false;
      }
      else {
        bVar3 = true;
      }
      if (bVar3) {
        local_98 = &local_100;
        local_90 = 4;
        local_88 = &local_110;
        local_80 = 4;
        local_100 = CONCAT44(local_100._4_4_,uVar6);
        local_110 = CONCAT44(local_110._4_4_,uVar11);
        _tlgWriteTransfer_EtwWriteTransfer(0x14000a050,&DAT_140007d51,0,0,4,local_b8);
      }
    }
    if (uVar6 != uVar11) {
      local_e8 = local_f8;
      local_c0 = 0;
      local_e0 = &DampS0JobInfo;
      local_d8 = &DampUserContextList;
      local_bb = 0;
      local_b9 = 0;
      local_d0 = DampPdcStateHandle;
      local_c8 = DampPdcResiliencyHandle;
      local_bc = local_118;
      DampStatePhaseTransitionExecute
                ((longlong)(&StateDefinitions + (longlong)(int)uVar6 * 0x30),
                 (longlong)(&StateDefinitions + (longlong)(int)uVar11 * 0x30),(longlong *)&local_e8)
      ;
      puVar10 = &local_117;
      puVar9 = &local_108;
      local_110 = _DAT_fffff78000000320 - lVar5;
      DamStatePerformanceTypeIdGetFromPhase(uVar6,uVar11,(undefined4 *)puVar9,puVar10);
      if (4 < DAT_14000a050) {
        if (((CONCAT71(uRam000000014000a061,DAT_14000a060) & 0x400000000010) == 0) ||
           ((DAT_14000a068 & 0x400000000010) != DAT_14000a068)) {
          puVar9 = (ulonglong *)0x0;
          bVar3 = false;
        }
        else {
          bVar3 = true;
        }
        if (bVar3) {
          local_98 = &local_f8;
          local_f8 = 1;
          local_88 = &local_100;
          local_100 = local_110;
          local_f0 = local_110;
          local_78 = &local_f0;
          local_118 = local_117;
          local_68 = &local_118;
          local_110 = CONCAT44(local_110._4_4_,(undefined4)local_108);
          local_58 = &local_110;
          local_48 = &local_108;
          local_90 = 8;
          local_80 = 8;
          local_70 = 8;
          local_60 = 1;
          local_50 = 4;
          local_108 = 0x1000000;
          local_40 = 8;
          _tlgWriteAgg(local_88,&DAT_140007cba,(ulonglong)puVar9,puVar10,local_b8);
        }
      }
    }
    DampFreezeWorkerAcquireLockExclusive((longlong)puVar1);
  }
  else {
    uVar11 = 9;
    local_116 = 1;
    uVar6 = 9;
  }
  puVar8 = &StateDefinitions;
  *(uint *)(param_1 + 0x158) = uVar6;
  uVar7 = DampStateSystemComputePhase((uint *)(param_1 + 0x15c));
  if (*(int *)(puVar8 + (longlong)(int)uVar6 * 0x30 + 0x2c) <=
      *(int *)(puVar8 + (longlong)(int)uVar7 * 0x30 + 0x2c)) {
    KeSetActualBasePriorityThread(*puVar1,0xc);
  }
  DampFreezeWorkerReleaseLockExclusive((longlong)puVar1);
  if (4 < DAT_14000a050) {
    if (((DAT_14000a060 & 0x80) == 0) || (((uint)DAT_14000a068 & 0x80) != DAT_14000a068)) {
      bVar4 = false;
    }
    if (bVar4) {
      local_98 = &local_110;
      local_88 = &local_100;
      local_90 = 4;
      local_78 = &local_108;
      local_80 = 4;
      local_70 = 4;
      local_110 = CONCAT44(local_110._4_4_,uVar6);
      local_100 = CONCAT44(local_100._4_4_,uVar11);
      local_108 = CONCAT44(local_108._4_4_,uVar7);
      _tlgWriteTransfer_EtwWriteTransfer(0x14000a050,&DAT_140007c6e,0,0,5,local_b8);
    }
  }
  if ((uVar2 & 2) != 0) {
    KeSetEvent(param_1 + 0x120,0,0);
  }
  return local_116;
}



===== DampFreezeWorkerReleaseLockExclusive @ 140013504 =====

void DampFreezeWorkerReleaseLockExclusive(longlong param_1)

{
  *(undefined8 *)(param_1 + 0x68) = 0;
  ExReleasePushLockExclusiveEx(param_1 + 0x60,0);
  KeLeaveCriticalRegion();
  return;
}



===== DampFreezeWorkerStart @ 140013538 =====

int DampFreezeWorkerStart(void)

{
  int iVar1;
  longlong local_res8 [4];
  undefined4 uVar2;
  
  local_res8[0] = 0;
  uVar2 = 0;
  iVar1 = PsCreateSystemThread(local_res8,0x1fffff,0,0,0,DampFreezeWorkerThread,&DampGlobal);
  if (-1 < iVar1) {
    ObReferenceObjectByHandleWithTag
              (local_res8[0],0x1fffff,*(undefined8 *)PsThreadType_exref,0,CONCAT44(uVar2,0x4b6d6144)
               ,&DAT_14000d440,0);
    KeSetActualBasePriorityThread(DAT_14000d440,0xc);
    iVar1 = 0;
  }
  if (local_res8[0] != 0) {
    ObCloseHandle(local_res8[0],0);
  }
  return iVar1;
}



===== DampFreezeWorkerThread @ 140013610 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DampFreezeWorkerThread(ulonglong param_1)

{
  longlong lVar1;
  longlong lVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  int iVar6;
  undefined1 auStackY_128 [32];
  int local_e8 [2];
  longlong local_e0 [15];
  undefined8 local_68 [4];
  int *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  lVar2 = *(longlong *)(param_1 + 0xe8);
  cVar5 = '\0';
  lVar1 = param_1 + 0xf0;
  bVar3 = true;
  local_e0[0] = lVar1;
  local_e0[1] = lVar2;
  if (4 < DAT_14000a050) {
    if (((DAT_14000a060 & 1) == 0) || ((DAT_14000a068 & 1) != DAT_14000a068)) {
      bVar4 = false;
    }
    else {
      bVar4 = true;
    }
    if (bVar4) {
      _tlgWriteTransfer_EtwWriteTransfer(0x14000a050,&DAT_140007c47,0,0,2,local_68);
    }
  }
  do {
    iVar6 = KeWaitForMultipleObjects(2,local_e0);
    if (local_e0[iVar6] == lVar1) {
      cVar5 = DampFreezeWorkerHandleFreezeEvent(param_1);
    }
    else if (local_e0[iVar6] == lVar2) {
      DampFreezeWorkerAcquireLockExclusive((longlong)(param_1 + 0xe0));
      if ((*(uint *)(&DAT_1400072d8 + (longlong)*(int *)(param_1 + 0x158) * 0x30) & 2) != 0) {
        *(uint *)(param_1 + 0x15c) = *(uint *)(param_1 + 0x15c) ^ 0x40;
      }
      if (*(int *)(&DAT_1400072ec + (longlong)*(int *)(param_1 + 0x158) * 0x30) == 1) {
        *(uint *)(param_1 + 0x15c) = *(uint *)(param_1 + 0x15c) & 0xffffffdf;
      }
      DampFreezeWorkerUpdatePostAndUnlock((undefined8 *)(param_1 + 0xe0));
    }
  } while (cVar5 == '\0');
  if (4 < DAT_14000a050) {
    if (((DAT_14000a060 & 1) == 0) || ((DAT_14000a068 & 1) != DAT_14000a068)) {
      bVar3 = false;
    }
    if (bVar3) {
      local_3c = 0;
      local_48 = local_e8;
      local_40 = 4;
      local_e8[0] = iVar6;
      _tlgWriteTransfer_EtwWriteTransfer(0x14000a050,&DAT_140007c17,0,0,3,local_68);
    }
  }
  return;
}



===== DampFreezeWorkerUpdatePostAndUnlock @ 1400137f4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool DampFreezeWorkerUpdatePostAndUnlock(undefined8 *param_1)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  uint uVar4;
  undefined1 auStackY_c8 [32];
  uint local_98;
  uint local_94;
  int local_90 [2];
  undefined8 local_88 [4];
  uint *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  uint *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  int *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_c8;
  uVar1 = *(uint *)((longlong)param_1 + 0x74);
  iVar2 = *(int *)(param_1 + 0xf);
  uVar4 = DampStateSystemComputePhase((uint *)((longlong)param_1 + 0x7c));
  if (*(int *)(&DAT_1400072ec + (longlong)(int)uVar4 * 0x30) <
      *(int *)(&DAT_1400072ec + (longlong)iVar2 * 0x30)) {
    KeSetActualBasePriorityThread(*param_1,0x12);
  }
  DampFreezeWorkerReleaseLockExclusive((longlong)param_1);
  bVar3 = true;
  if (uVar1 != uVar4) {
    KeSetEvent(param_1 + 2,0);
  }
  if (4 < DAT_14000a050) {
    if (((DAT_14000a060 & 0x40) == 0) || (((uint)DAT_14000a068 & 0x40) != DAT_14000a068)) {
      bVar3 = false;
    }
    if (bVar3) {
      local_5c = 0;
      local_68 = &local_98;
      local_4c = 0;
      local_3c = 0;
      local_58 = &local_94;
      local_60 = 4;
      local_48 = local_90;
      local_50 = 4;
      local_40 = 4;
      local_98 = uVar4;
      local_94 = uVar1;
      local_90[0] = iVar2;
      _tlgWriteTransfer_EtwWriteTransfer(0x14000a050,&DAT_140007bc6,0,0,5,local_88);
    }
  }
  return uVar1 != uVar4;
}



===== DampGetRegistryUlong @ 140013964 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 DampGetRegistryUlong(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_98 [32];
  undefined4 local_78;
  int *local_70;
  int local_68 [2];
  longlong local_60 [4];
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_98;
  local_3c = 0;
  local_68[0] = 0;
  local_60[0] = 0;
  local_60[2] = 0;
  local_60[1] = 0x30;
  local_28 = 0;
  uStack_20 = 0;
  local_40 = 0x240;
  local_38 = 0;
  uStack_30 = 0;
  local_60[3] = param_1;
  iVar1 = ZwOpenKey(local_60,1,local_60 + 1);
  uVar2 = param_3;
  if (-1 < iVar1) {
    local_70 = local_68;
    local_78 = 0x10;
    iVar1 = ZwQueryValueKey(local_60[0],param_2,2,&local_28);
    if ((-1 < iVar1) && (local_28._4_4_ == 4)) {
      uVar2 = uStack_20._4_4_;
      if (local_68[0] != 0x10) {
        uVar2 = param_3;
      }
    }
  }
  if (local_60[0] != 0) {
    ZwClose();
  }
  return uVar2;
}



===== DampGetSessionContext @ 140013a64 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DampGetSessionContext(int param_1,undefined8 *param_2)

{
  code *pcVar1;
  undefined1 *puVar2;
  int iVar3;
  longlong *plVar4;
  longlong *plVar5;
  longlong *plVar6;
  longlong *plVar7;
  undefined1 *puVar8;
  ulonglong uVar9;
  longlong *plVar10;
  undefined8 uStack_a0;
  undefined1 auStack_98 [32];
  undefined4 auStack_78 [2];
  longlong local_70;
  int local_68 [10];
  longlong lStack_40;
  undefined4 local_38 [2];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_98;
  KeEnterCriticalRegion();
  ExAcquireFastMutexUnsafe(&DamStateMutex);
  uVar9 = 1;
  for (plVar4 = DampUserContextList; (longlong **)plVar4 != &DampUserContextList;
      plVar4 = (longlong *)*plVar4) {
    plVar6 = plVar4 + -0x2a;
    if ((int)plVar4[-2] == param_1) {
      ExAcquireRundownProtection(plVar4 + -1);
      if (plVar6 != (longlong *)0x0) {
        *(int *)((longlong)plVar4 + -0xc) = *(int *)((longlong)plVar4 + -0xc) + 1;
      }
      goto LAB_140013ae1;
    }
  }
  plVar6 = (longlong *)0x0;
LAB_140013ae1:
  puVar8 = auStack_98;
  ExReleaseFastMutexUnsafe(&DamStateMutex);
  KeLeaveCriticalRegion();
  if (plVar6 == (longlong *)0x0) {
    plVar4 = (longlong *)ExAllocatePool2(0x100,0x160,0x4b6d6144);
    if (plVar4 == (longlong *)0x0) {
      iVar3 = -0x3fffff66;
      puVar8 = auStack_98;
    }
    else {
      memset(plVar4,0,0x160);
      plVar6 = plVar4 + 0x2a;
      *(int *)(plVar4 + 0x28) = param_1;
      plVar4[0x2b] = (longlong)plVar6;
      *plVar6 = (longlong)plVar6;
      ExInitializeRundownProtection(plVar4 + 0x29);
      *(undefined4 *)((longlong)plVar4 + 0x144) = 1;
      iVar3 = DampCreateExemptGroupInfo(plVar4);
      plVar7 = plVar4;
      puVar2 = auStack_98;
      if (-1 < iVar3) {
        KeEnterCriticalRegion();
        ExAcquireFastMutexUnsafe(&DamStateMutex);
        for (plVar5 = DampUserContextList; puVar2 = auStack_98,
            (longlong **)plVar5 != &DampUserContextList; plVar5 = (longlong *)*plVar5) {
          plVar10 = plVar5 + -0x2a;
          if ((int)plVar5[-2] == param_1) goto LAB_140013c75;
        }
        do {
          puVar8 = puVar2;
          plVar10 = (longlong *)0x3;
          if (4 < DAT_14000a050) {
            if (((DAT_14000a060 & (byte)uVar9) == 0) || ((DAT_14000a068 & uVar9) != DAT_14000a068))
            {
              uVar9 = 0;
            }
            if ((char)uVar9 != '\0') {
              *(undefined4 *)(puVar8 + 100) = 0;
              *(undefined1 **)(puVar8 + 0x58) = puVar8 + 0x30;
              *(int *)(puVar8 + 0x30) = param_1;
              *(undefined1 **)(puVar8 + 0x28) = puVar8 + 0x38;
              *(undefined4 *)(puVar8 + 0x20) = 3;
              *(undefined4 *)(puVar8 + 0x60) = 4;
              *(undefined8 *)(puVar8 + -8) = 0x140013c63;
              _tlgWriteTransfer_EtwWriteTransfer
                        (0x14000a050,&DAT_140007f94,0,0,*(undefined4 *)(puVar8 + 0x20),
                         *(undefined8 **)(puVar8 + 0x28));
            }
          }
          if ((longlong **)DampUserContextList[1] == &DampUserContextList) {
            *plVar6 = (longlong)DampUserContextList;
            plVar4[0x2b] = (longlong)&DampUserContextList;
            DampUserContextList[1] = (longlong)plVar6;
            *(undefined8 *)(puVar8 + -8) = 0x140013cb5;
            DampUserContextList = plVar6;
            ExAcquireRundownProtection(plVar4 + 0x29);
            plVar7 = (longlong *)0x0;
            goto LAB_140013cbf;
          }
          pcVar1 = (code *)swi(0x29);
          (*pcVar1)(3);
          puVar8 = puVar8 + 8;
LAB_140013c75:
          *(undefined8 *)(puVar8 + -8) = 0x140013c83;
          ExAcquireRundownProtection(plVar10 + 0x29);
          puVar2 = puVar8;
        } while (plVar10 == (longlong *)0x0);
        *(int *)((longlong)plVar10 + 0x144) = *(int *)((longlong)plVar10 + 0x144) + (int)uVar9;
        plVar4 = plVar10;
LAB_140013cbf:
        *(undefined8 *)(puVar8 + -8) = 0x140013ccd;
        ExReleaseFastMutexUnsafe(&DamStateMutex);
        *(undefined8 *)(puVar8 + -8) = 0x140013cd9;
        KeLeaveCriticalRegion();
        *param_2 = plVar4;
        iVar3 = 0;
        puVar2 = puVar8;
        if (plVar7 == (longlong *)0x0) goto LAB_140013d04;
      }
      puVar8 = puVar2;
      *(undefined8 *)(puVar8 + -8) = 0x140013cf0;
      DampDestroyExemptGroupInfo(plVar7);
      *(undefined8 *)(puVar8 + -8) = 0x140013cff;
      ExFreePoolWithTag(plVar7,0x4b6d6144);
    }
  }
  else {
    *param_2 = plVar6;
    iVar3 = 0;
    puVar8 = auStack_98;
  }
LAB_140013d04:
  *(undefined8 *)(puVar8 + -8) = 0x140013d13;
  return iVar3;
}



===== DampGlobalAllocateState @ 140013d38 =====

ulonglong DampGlobalAllocateState(void)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined4 extraout_var;
  undefined8 *puVar4;
  longlong *plVar5;
  undefined8 uVar6;
  undefined8 in_R9;
  
  plVar5 = (longlong *)0x0;
  puVar4 = (undefined8 *)0x0;
  uVar6 = 8;
  DAT_14000d448 = ExAllocateTimer();
  uVar3 = DampUserContextAllocateState();
  if (-1 < (int)uVar3) {
    iVar1 = DamPolicyAllocate(puVar4,plVar5,uVar6,in_R9);
    uVar3 = CONCAT44(extraout_var,iVar1);
    if (-1 < iVar1) {
      uVar2 = ExSubscribeWnfStateChange
                        (&DAT_14000d508,&DAT_14000d500,1,0,DamWnfDevicePowerTransitionUpdate,
                         &DAT_14000d4d8);
      uVar3 = (ulonglong)uVar2;
      if (-1 < (int)uVar2) {
        uVar3 = 0;
      }
    }
  }
  return uVar3;
}



===== DampGlobalCleanup @ 140013db8 =====

void DampGlobalCleanup(void)

{
  ulonglong uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(&DAT_14000d4c0,0);
  puVar4 = DAT_14000d4c8;
  if (DAT_14000d4c8 != (undefined8 *)0x0) {
    do {
      while ((undefined8 *)*puVar4 != (undefined8 *)0x0) {
        puVar3 = puVar4;
        puVar2 = (undefined8 *)*puVar4;
LAB_140013e04:
        puVar4 = puVar2;
        *puVar3 = 0;
      }
      puVar3 = puVar4 + 1;
      puVar2 = (undefined8 *)*puVar3;
      if ((undefined8 *)*puVar3 != (undefined8 *)0x0) goto LAB_140013e04;
      uVar1 = puVar4[2];
      DampProcessTreeNodeDelete((longlong)puVar4);
      puVar4 = (undefined8 *)(uVar1 & 0xfffffffffffffffc);
    } while (puVar4 != (undefined8 *)0x0);
  }
  ExReleasePushLockExclusiveEx(&DAT_14000d4c0,0);
  KeLeaveCriticalRegion();
  KeDeregisterBugCheckReasonCallback(&DAT_14000d3a8);
  if (DAT_14000d440 != 0) {
    ObfDereferenceObjectWithTag(DAT_14000d440,0x4b6d6144);
  }
  if (DAT_14000d508 != 0) {
    ExUnsubscribeWnfStateChange();
  }
  return;
}



===== DampGlobalInitialize @ 140013e9c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DampGlobalInitialize(void)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong local_res8;
  
  memset(&DampGlobal,0,0x1b8);
  DamPolicyInitialize();
  memset(&DampGlobal,0,0x48);
  if ((Feature_DamUserSessionDelay__private_featureState & 0x10) == 0) {
    uVar2 = Feature_DamUserSessionDelay__private_featureState | 1;
    local_res8 = (ulonglong)uVar2;
    wil_details_FeatureReporting_ReportUsageToService(0x140009208,local_res8,3,1);
    wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath
              (uVar2,3,&Feature_DamUserSessionDelay__private_descriptor);
  }
  DAT_14000d368 = DampGetRegistryUlong(&DampPolicyRegistryKey,&DampDelayDurationValue,3000);
  if (10000 < DAT_14000d368) {
    DAT_14000d368 = 3000;
  }
  _DAT_14000d370 = (ulonglong)DAT_14000d368 * -10000;
  lVar3 = SUB168(SEXT816(-10000) * SEXT816((longlong)(ulonglong)DAT_14000d368),8);
  if (_DAT_14000d370 < 0) {
    if (lVar3 != -1) goto LAB_140014153;
  }
  else if (lVar3 != 0) {
LAB_140014153:
    _DAT_14000d370 = -1;
  }
  uVar2 = DampGetRegistryUlong(&DamPdcTimeoutRegKey,&DamPdcTimeoutRegValue,10);
  if (uVar2 == 0) {
    uVar2 = 10;
  }
  _DAT_14000d380 = (ulonglong)uVar2 * -10000000;
  lVar3 = SUB168(SEXT816(-10000000) * SEXT816((longlong)(ulonglong)uVar2),8);
  if (_DAT_14000d380 < 0) {
    if (lVar3 != -1) goto LAB_140014168;
  }
  else if (lVar3 != 0) {
LAB_140014168:
    _DAT_14000d380 = -1;
  }
  DAT_14000d399 = 0;
  memset(&DAT_14000d3a8,0,0x98);
  DAT_14000d3d4 = 0;
  KeInitializeTriageDumpDataArray(&DAT_14000d3f0);
  memset(&DAT_14000d440,0,0x80);
  _DAT_14000d4a0 = 0;
  KeInitializeEvent(&DAT_14000d450,1,0);
  KeInitializeEvent(&DAT_14000d468,1,0);
  KeInitializeEvent(&DAT_14000d480,1,0);
  iVar1 = DampGetRegistryUlong(&DampPolicyRegistryKey,&DampDelayDurationValue,3000);
  _DAT_14000d498 = (longlong)iVar1 * -10000;
  lVar3 = SUB168(SEXT816(-10000) * SEXT816((longlong)iVar1),8);
  if (_DAT_14000d498 < 0) {
    if (lVar3 == -1) goto LAB_1400140aa;
  }
  else if (lVar3 == 0) goto LAB_1400140aa;
  _DAT_14000d498 = -1;
LAB_1400140aa:
  _DAT_14000d4b4 = 0;
  _DAT_14000d4c0 = 0;
  DAT_14000d4c8 = 0;
  uRam000000014000d4d0 = 0;
  DAT_14000d4bc = 0;
  _DAT_14000d4d8 = 0;
  uRam000000014000d4e0 = 0;
  DAT_14000d508 = 0;
  _DAT_14000d4e8 = 0;
  uRam000000014000d4f0 = 0;
  _DAT_14000d4f8 = 0;
  _DAT_14000d500 = 0;
  KeInitializeEvent(&DAT_14000d4e8,1,0);
  _DAT_14000d4d8 = 0;
  _DAT_14000d500 = 0x41c6013da3bdc075;
  _DAT_14000d510 = 0;
  return;
}



===== DampGlobalRundown @ 140014190 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DampGlobalRundown(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  if (DAT_14000d388 != 0) {
    ExUnsubscribeWnfStateChange();
  }
  if (DampGlobal != 0) {
    param_3 = CONCAT71((int7)((ulonglong)param_3 >> 8),1);
    param_4 = 0;
    param_2 = CONCAT71((int7)((ulonglong)param_2 >> 8),1);
    ExDeleteTimer();
  }
  lVar1 = DAT_14000d390;
  if (DAT_14000d390 != 0) {
    param_2 = 0x4b6d6144;
    ExFreePoolWithTag();
  }
  DamPolicyShutdown(lVar1,param_2,param_3,param_4);
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if (DAT_14000d448 != 0) {
    ExDeleteTimer(DAT_14000d448,0,0,&local_28);
  }
  if (DAT_14000d440 != 0) {
    DampFreezeWorkerAcquireLockExclusive(0x14000d440);
    _DAT_14000d4b0 = _DAT_14000d4b0 | 1;
    KeSetEvent(&DAT_14000d450,0,0);
    DampFreezeWorkerReleaseLockExclusive(0x14000d440);
    KeWaitForSingleObject(DAT_14000d440,0,0,0,0);
  }
  return;
}



===== DampGlobalStart @ 140014290 =====

int DampGlobalStart(void)

{
  int iVar1;
  int iVar2;
  
  KeRegisterBugCheckReasonCallback(&DAT_14000d3a8,DampBugcheckCallback,7,&DampBugcheckComponent);
  iVar1 = DampFreezeWorkerStart();
  iVar2 = 0;
  if (iVar1 < 0) {
    iVar2 = iVar1;
  }
  return iVar2;
}



===== DampHandleProcessTermination @ 1400142d8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DampHandleProcessTermination(longlong param_1,undefined8 param_2,longlong *param_3)

{
  longlong lVar1;
  code *pcVar2;
  bool bVar3;
  longlong *plVar4;
  longlong *plVar5;
  undefined8 uVar6;
  undefined1 auStackY_88 [32];
  undefined4 local_58 [2];
  undefined8 local_50 [4];
  undefined4 *local_30;
  undefined4 local_28;
  undefined4 local_24;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_88;
  uVar6 = param_2;
  KeEnterCriticalRegion();
  ExAcquireFastMutexUnsafe(&DamStateMutex);
  plVar4 = DampUserContextList;
  do {
    if ((longlong **)plVar4 == &DampUserContextList) {
LAB_140014344:
      plVar5 = (longlong *)&DamStateMutex;
      ExReleaseFastMutexUnsafe();
      KeLeaveCriticalRegion();
LAB_140014363:
      if ((Microsoft_Windows_DesktopActivityModeratorEnableBits & 4) != 0) {
        McTemplateK0qq_EtwWriteTransfer
                  (plVar5,uVar6,param_3,*(undefined4 *)(param_1 + 0x1d0),(char)param_2);
      }
      return;
    }
    plVar5 = plVar4 + -0x2a;
    if ((int)plVar4[-2] == (int)param_2) {
      ExAcquireRundownProtection(plVar4 + -1);
      if (plVar5 != (longlong *)0x0) {
        bVar3 = true;
        *(int *)((longlong)plVar4 + -0xc) = *(int *)((longlong)plVar4 + -0xc) + -1;
        ExReleaseRundownProtection(plVar4 + -1);
        if (*(int *)((longlong)plVar4 + -0xc) == 0) {
          if (4 < DAT_14000a050) {
            if (((DAT_14000a060 & 1) == 0) || ((DAT_14000a068 & 1) != DAT_14000a068)) {
              bVar3 = false;
            }
            if (bVar3) {
              local_58[0] = (undefined4)plVar4[-2];
              local_24 = 0;
              local_30 = local_58;
              local_28 = 4;
              _tlgWriteTransfer_EtwWriteTransfer(0x14000a050,&DAT_14000813d,0,0,3,local_50);
            }
          }
          lVar1 = *plVar4;
          if ((*(longlong **)(lVar1 + 8) != plVar4) ||
             (param_3 = (longlong *)plVar4[1], (longlong *)*param_3 != plVar4)) {
            pcVar2 = (code *)swi(0x29);
            (*pcVar2)(3);
            pcVar2 = (code *)swi(3);
            (*pcVar2)();
            return;
          }
          *param_3 = lVar1;
          *(longlong **)(lVar1 + 8) = param_3;
          plVar4[1] = (longlong)plVar4;
          *plVar4 = (longlong)plVar4;
          ExReleaseFastMutexUnsafe(&DamStateMutex);
          KeLeaveCriticalRegion();
          ExWaitForRundownProtectionRelease(plVar4 + -1);
          DampDestroyExemptGroupInfo(plVar5);
          uVar6 = 0x4b6d6144;
          ExFreePoolWithTag();
          goto LAB_140014363;
        }
      }
      goto LAB_140014344;
    }
    plVar4 = (longlong *)*plVar4;
  } while( true );
}



===== DampPdcControlCallback @ 1400144f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 DampPdcControlCallback(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  bool bVar1;
  undefined1 auStackY_78 [32];
  undefined4 local_48 [2];
  undefined8 local_40 [4];
  undefined4 *local_20;
  undefined4 local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  if ((Microsoft_Windows_DesktopActivityModeratorEnableBits & 0x10) != 0) {
    McTemplateK0q_EtwWriteTransfer(param_1,&DamEvent_PdcControlCallback,param_3,param_2);
  }
  if (4 < DAT_14000a050) {
    if (((DAT_14000a060 & 2) == 0) || (((uint)DAT_14000a068 & 2) != DAT_14000a068)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      local_14 = 0;
      local_20 = local_48;
      local_18 = 4;
      local_48[0] = param_2;
      _tlgWriteTransfer_EtwWriteTransfer(0x14000a050,&DAT_140007b7b,0,0,3,local_40);
    }
  }
  return 0;
}



===== DampPdcResiliencyCallback @ 1400145b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 DampPdcResiliencyCallback(undefined8 param_1,int param_2,byte *param_3)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 auStackY_68 [32];
  undefined8 local_38 [4];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  bVar1 = true;
  if ((param_3 == (byte *)0x0) || ((*param_3 & 2) == 0)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  DampFreezeWorkerAcquireLockExclusive(0x14000d440);
  uVar5 = 0;
  if (param_2 == 1) {
    uVar5 = 0x40;
  }
  uVar4 = 0;
  if (bVar2) {
    if (param_2 == 1) {
      uVar4 = 4;
    }
    uVar3 = DAT_14000d4bc & 0xffffffbb;
  }
  else {
    if (param_2 == 1) {
      uVar4 = 2;
    }
    uVar3 = DAT_14000d4bc & 0xffffffbd;
  }
  DAT_14000d4bc = uVar4 | uVar5 | uVar3;
  DampFreezeWorkerUpdatePostAndUnlock(&DAT_14000d440);
  KeWaitForSingleObject(&DAT_14000d468,0);
  if (4 < DAT_14000a050) {
    if (((DAT_14000a060 & 6) == 0) || (((uint)DAT_14000a068 & 6) != DAT_14000a068)) {
      bVar1 = false;
    }
    if (bVar1) {
      _tlgWriteTransfer_EtwWriteTransfer(0x14000a050,&DAT_140007b55,0,0,2,local_38);
    }
  }
  return 0;
}



===== DampPdcStateCallback @ 1400146f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 DampPdcStateCallback(undefined8 param_1,int param_2,undefined8 param_3)

{
  bool bVar1;
  bool bVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  undefined1 auStackY_68 [32];
  undefined8 local_38 [4];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  bVar1 = true;
  if (param_2 == 1) {
    bVar2 = DampUserSessionDelayEnabledGet();
  }
  else {
    bVar2 = false;
  }
  DampFreezeWorkerAcquireLockExclusive(0x14000d440);
  DAT_14000d4bc = (uint)(param_2 == 1) | DAT_14000d4bc & 0xfffffffe;
  uVar4 = (ulonglong)DAT_14000d4bc;
  if (param_2 == 1) {
    DAT_14000d4bc = ((uint)bVar2 << 5 ^ DAT_14000d4bc) & 0x20 ^ DAT_14000d4bc;
  }
  puVar3 = &DAT_14000d440;
  DampFreezeWorkerUpdatePostAndUnlock(&DAT_14000d440);
  if ((Microsoft_Windows_DesktopActivityModeratorEnableBits & 0x10) != 0) {
    McTemplateK0qqt_EtwWriteTransfer(puVar3,uVar4,param_3,param_2);
  }
  if (4 < DAT_14000a050) {
    if (((DAT_14000a060 & 2) == 0) || (((uint)DAT_14000a068 & 2) != DAT_14000a068)) {
      bVar1 = false;
    }
    if (bVar1) {
      _tlgWriteTransfer_EtwWriteTransfer(0x14000a050,&DAT_140007ba5,0,0,2,local_38);
    }
  }
  return 0x103;
}



===== DampProcessTreeCompare @ 140014800 =====

int DampProcessTreeCompare(ulonglong param_1,longlong param_2)

{
  if (*(ulonglong *)(param_2 + 0x18) < param_1) {
    return 1;
  }
  return -(uint)(param_1 < *(ulonglong *)(param_2 + 0x18));
}



===== DampProcessTreeInsert @ 140014818 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 * DampProcessTreeInsert(longlong param_1,ulonglong param_2)

{
  ulonglong *puVar1;
  byte bVar2;
  bool bVar3;
  int iVar4;
  undefined8 *puVar5;
  ulonglong *puVar6;
  ulonglong *puVar7;
  undefined1 auStackY_b8 [32];
  undefined4 local_88 [2];
  undefined8 *local_80;
  undefined8 local_78 [4];
  undefined8 **local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_b8;
  puVar5 = (undefined8 *)ExAllocatePool2(0x100,0x20);
  bVar3 = true;
  if (puVar5 != (undefined8 *)0x0) {
    ObfReferenceObject(param_2);
    *puVar5 = 0;
    puVar5[1] = 0;
    puVar5[2] = 0;
    puVar5[3] = param_2;
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(param_1,0);
    puVar1 = (ulonglong *)(param_1 + 8);
    puVar7 = (ulonglong *)*puVar1;
    if (((*(byte *)(param_1 + 0x10) & 1) != 0) && (puVar7 != (ulonglong *)0x0)) {
      puVar7 = (ulonglong *)((ulonglong)puVar7 ^ (ulonglong)puVar1);
    }
    bVar2 = *(byte *)(param_1 + 0x10);
    if (puVar7 != (ulonglong *)0x0) {
      do {
        iVar4 = DampProcessTreeCompare(param_2,(longlong)puVar7);
        if (iVar4 < 0) {
          puVar6 = (ulonglong *)*puVar7;
          if ((bVar2 & 1) != 0) {
            if (puVar6 == (ulonglong *)0x0) break;
            puVar6 = (ulonglong *)((ulonglong)puVar6 ^ (ulonglong)puVar7);
          }
        }
        else {
          puVar6 = (ulonglong *)puVar7[1];
          if ((bVar2 & 1) != 0) {
            if (puVar6 == (ulonglong *)0x0) break;
            puVar6 = (ulonglong *)((ulonglong)puVar6 ^ (ulonglong)puVar7);
          }
        }
        if (puVar6 == (ulonglong *)0x0) break;
        puVar7 = puVar6;
      } while( true );
    }
    RtlRbInsertNodeEx(puVar1,puVar7);
    ExReleasePushLockExclusiveEx(param_1,0);
    KeLeaveCriticalRegion();
  }
  if (5 < DAT_14000a050) {
    if (((DAT_14000a060 & 1) == 0) || ((DAT_14000a068 & 1) != DAT_14000a068)) {
      bVar3 = false;
    }
    if (bVar3) {
      local_4c = 0;
      local_58 = &local_80;
      local_50 = 8;
      local_80 = puVar5;
      local_88[0] = PsGetProcessId(param_2);
      local_3c = 0;
      local_48 = local_88;
      local_40 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(0x14000a050,&DAT_140007aea,0,0,4,local_78);
    }
  }
  return puVar5;
}



===== DampProcessTreeNodeDelete @ 140014a24 =====

void DampProcessTreeNodeDelete(longlong param_1)

{
  ObfDereferenceObject(*(undefined8 *)(param_1 + 0x18));
  ExFreePoolWithTag(param_1,0x4b6d6144);
  return;
}



===== DampProcessTreeRemove @ 140014a60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 * DampProcessTreeRemove(longlong param_1,ulonglong param_2)

{
  ulonglong *puVar1;
  byte bVar2;
  bool bVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined1 auStackY_b8 [32];
  undefined4 local_88 [2];
  undefined8 *local_80;
  undefined8 local_78 [4];
  undefined8 **local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_b8;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(param_1,0);
  puVar1 = (ulonglong *)(param_1 + 8);
  bVar3 = true;
  puVar6 = (undefined8 *)*puVar1;
  if (((*(byte *)(param_1 + 0x10) & 1) != 0) && (puVar6 != (undefined8 *)0x0)) {
    puVar6 = (undefined8 *)((ulonglong)puVar6 ^ (ulonglong)puVar1);
  }
  bVar2 = *(byte *)(param_1 + 0x10);
  while (puVar6 != (undefined8 *)0x0) {
    iVar4 = DampProcessTreeCompare(param_2,(longlong)puVar6);
    if (iVar4 < 0) {
      puVar5 = (undefined8 *)*puVar6;
    }
    else {
      if (iVar4 < 1) break;
      puVar5 = (undefined8 *)puVar6[1];
    }
    if (((bVar2 & 1) == 0) || (puVar5 == (undefined8 *)0x0)) {
      puVar6 = puVar5;
    }
    else {
      puVar6 = (undefined8 *)((ulonglong)puVar6 ^ (ulonglong)puVar5);
    }
  }
  if (puVar6 != (undefined8 *)0x0) {
    RtlRbRemoveNode(puVar1,puVar6);
  }
  ExReleasePushLockExclusiveEx(param_1,0);
  KeLeaveCriticalRegion();
  if (5 < DAT_14000a050) {
    if (((DAT_14000a060 & 1) == 0) || ((DAT_14000a068 & 1) != DAT_14000a068)) {
      bVar3 = false;
    }
    if (bVar3) {
      local_4c = 0;
      local_58 = &local_80;
      local_50 = 8;
      local_80 = puVar6;
      local_88[0] = PsGetProcessId(param_2);
      local_3c = 0;
      local_48 = local_88;
      local_40 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(0x14000a050,&DAT_140007aba,0,0,4,local_78);
    }
  }
  return puVar6;
}



===== DampSession0JobFreeze @ 140014c00 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DampSession0JobFreeze(int param_1,byte param_2)

{
  bool bVar1;
  bool bVar2;
  undefined1 auStackY_a8 [32];
  undefined1 local_78;
  byte local_77 [15];
  undefined4 local_68;
  uint uStack_64;
  undefined8 uStack_60;
  undefined1 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  byte *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_a8;
  bVar1 = true;
  if (4 < DAT_14000a050) {
    if (((DAT_14000a060 & 4) == 0) || (((uint)DAT_14000a068 & 4) != DAT_14000a068)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      local_3c = 0;
      local_48 = &local_78;
      local_2c = 0;
      local_38 = local_77;
      local_78 = (undefined1)param_1;
      local_40 = 1;
      local_30 = 1;
      local_77[0] = param_2;
      _tlgWriteTransfer_EtwWriteTransfer(0x14000a050,&DAT_14000803e,0,0,4,(undefined8 *)&local_68);
    }
  }
  uStack_60 = 0;
  _local_68 = CONCAT44((uint)param_2,9);
  ZwSetInformationJobObject((&DampS0JobInfo)[(longlong)param_1 * 10],0x12);
  if (4 < DAT_14000a050) {
    if (((DAT_14000a060 & 4) == 0) || (((uint)DAT_14000a068 & 4) != DAT_14000a068)) {
      bVar1 = false;
    }
    if (bVar1) {
      _tlgWriteTransfer_EtwWriteTransfer(0x14000a050,&DAT_14000801c,0,0,2,(undefined8 *)&local_68);
    }
  }
  return;
}



===== DampStateTransitionPhaseTimer @ 140014d68 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DampStateTransitionPhaseTimer(undefined8 param_1,int param_2,longlong *param_3)

{
  undefined8 uVar1;
  code *pcVar2;
  undefined8 uVar3;
  undefined1 *puVar4;
  undefined8 uStack_60;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [48];
  undefined8 local_20;
  ulonglong local_10;
  
  puVar4 = auStack_58;
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  uVar1 = *(undefined8 *)(*param_3 + 0xe8);
  local_20 = 0;
  if (param_2 != 3) {
    if ((param_2 == 2) || (param_2 == 0)) {
      uVar3 = 0xffffffffffffffff;
      goto LAB_140014dd1;
    }
    if (param_2 != 1) {
      pcVar2 = (code *)swi(0x2c);
      uVar3 = (*pcVar2)(param_1,0xffffffffff676980);
      puVar4 = auStack_50;
      goto LAB_140014dd1;
    }
  }
  uVar3 = 500000;
  puVar4 = auStack_58;
LAB_140014dd1:
  *(undefined8 *)(puVar4 + 0x40) = uVar3;
  if ((int)param_1 == 1) {
    *(undefined8 *)(puVar4 + -8) = 0x140014ded;
    ExSetTimer(uVar1);
  }
  else if ((int)param_1 == 0) {
    *(undefined8 *)(puVar4 + -8) = 0x140014e04;
    ExCancelTimer(uVar1,0);
    *(undefined8 *)(puVar4 + 0x30) = 0;
    *(undefined1 **)(puVar4 + 0x20) = puVar4 + 0x30;
    *(undefined8 *)(puVar4 + -8) = 0x140014e2b;
    KeWaitForSingleObject(uVar1,0,0,0);
  }
  else {
    pcVar2 = (code *)swi(0x2c);
    (*pcVar2)();
    puVar4 = puVar4 + 8;
  }
  *(undefined8 *)(puVar4 + -8) = 0x140014e41;
  return;
}



===== DampStateTransitionPoNotify @ 140014e50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DampStateTransitionPoNotify(int param_1,int param_2)

{
  code *pcVar1;
  bool bVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined8 uStack_60;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [24];
  uint auStack_38 [10];
  ulonglong local_10;
  
  puVar4 = auStack_58;
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  bVar2 = true;
  if (param_2 == 0) {
    uVar3 = 1;
    puVar4 = auStack_58;
  }
  else if (param_2 == 1) {
    uVar3 = 3;
  }
  else {
    pcVar1 = (code *)swi(0x2c);
    uVar3 = (*pcVar1)();
    puVar4 = auStack_50;
  }
  if ((param_1 != 1) && (bVar2 = false, param_1 != 0)) {
    pcVar1 = (code *)swi(0x2c);
    uVar3 = (*pcVar1)();
    puVar4 = puVar4 + 8;
  }
  *(undefined4 *)(puVar4 + 0x34) = 0;
  *(undefined4 *)(puVar4 + 0x40) = 0xffffffff;
  *(undefined4 *)(puVar4 + 0x38) = uVar3;
  *(undefined4 *)(puVar4 + 0x30) = 0x5a;
  *(undefined4 *)(puVar4 + 0x20) = 0;
  *(uint *)(puVar4 + 0x3c) = (uint)!bVar2;
  *(undefined8 *)(puVar4 + -8) = 0x140014ed3;
  ZwPowerInformation(0x57,puVar4 + 0x30,0x14);
  if (!bVar2) {
    *(undefined4 *)(puVar4 + 0x20) = 0;
    *(undefined4 *)(puVar4 + 0x3c) = 2;
    *(undefined8 *)(puVar4 + -8) = 0x140014f00;
    ZwPowerInformation(0x57,puVar4 + 0x30,0x14);
  }
  *(undefined8 *)(puVar4 + -8) = 0x140014f12;
  return;
}



===== DampSubscribePdc @ 140014f20 =====

ulonglong DampSubscribePdc(void)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 local_res8;
  undefined8 local_res10;
  undefined4 local_38;
  undefined4 local_34;
  code *local_30;
  undefined8 local_28;
  code *local_20;
  undefined8 local_18;
  code *local_10;
  
  local_res8 = 0;
  local_18 = 0;
  local_res10 = 0;
  local_34 = 0;
  local_28 = 1;
  local_20 = DampPdcStateCallback;
  local_10 = DampPdcControlCallback;
  uVar2 = PdcNotificationClientRegister(4,&local_28,0,&local_res8);
  if (-1 < (int)uVar2) {
    local_38 = 1;
    local_30 = DampPdcResiliencyCallback;
    uVar1 = PdcResiliencyClientRegister(4,&local_38,0,&local_res10);
    uVar2 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) {
      PdcNotificationClientUnregister(local_res8);
    }
    else {
      DampPdcStateHandle = local_res8;
      DampPdcResiliencyHandle = local_res10;
    }
  }
  return uVar2;
}



===== DampTracingControlCallback @ 140015000 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DampTracingControlCallback(undefined8 param_1,int param_2)

{
  bool bVar1;
  undefined1 auStackY_128 [32];
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0 [30];
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68 [4];
  undefined4 *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  undefined4 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  if (param_2 == 2) {
    local_18 = __security_cookie ^ (ulonglong)auStackY_128;
    DampFreezeWorkerAcquireLockExclusive(0x14000d440);
    local_78 = _DAT_14000d4b0;
    uStack_70 = _DAT_14000d4b8;
    DampFreezeWorkerReleaseLockExclusive(0x14000d440);
    if (4 < DAT_14000a050) {
      if ((DAT_14000a060 == '\0') || (bVar1 = true, (DAT_14000a068 & 0xff) != DAT_14000a068)) {
        bVar1 = false;
      }
      if (bVar1) {
        local_f8 = uStack_70._4_4_;
        local_48 = &local_f8;
        local_40 = 4;
        local_f4 = (undefined4)uStack_70;
        local_38 = &local_f4;
        local_f0[0] = local_78._4_4_;
        local_28 = local_f0;
        local_30 = 4;
        local_20 = 4;
        _tlgWriteTransfer_EtwWriteTransfer(0x14000a050,&DAT_140007b1a,0,0,5,local_68);
      }
    }
  }
  return;
}



===== DampUnsubscribePdc @ 140015100 =====

void DampUnsubscribePdc(void)

{
  if (DampPdcResiliencyHandle != 0) {
    PdcResiliencyClientUnregister();
    DampPdcResiliencyHandle = 0;
  }
  if (DampPdcStateHandle != 0) {
    PdcNotificationClientUnregister();
    DampPdcStateHandle = 0;
  }
  return;
}



===== DampUserContextAllocateState @ 140015150 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong DampUserContextAllocateState(void)

{
  undefined4 uVar1;
  ulonglong uVar2;
  
  if (DAT_14000d368 == 0) {
    uVar2 = 0;
  }
  else {
    uVar1 = IoSizeofWorkItem();
    DAT_14000d390 = ExAllocatePool2(0x40,uVar1,0x4b6d6144);
    if (DAT_14000d390 != 0) {
      IoInitializeWorkItem(DamDriverObject,DAT_14000d390);
      DampGlobal = ExAllocateTimer(DampUserSessionDelayTimerRoutine,&DampGlobal,8);
      if (DampGlobal != 0) {
        uVar2 = ExSubscribeWnfStateChange
                          (&DAT_14000d388,&WNF_SHEL_DEVICE_UNLOCKED,1,0,
                           DampUserSessionDelayNotificationCallback,&DampGlobal);
        if ((int)uVar2 < 0) {
          return uVar2;
        }
        _DAT_14000d378 = ExAllocateTimer(DampUserSessionDelayWatchdogCallback,&DampGlobal,8);
        return (ulonglong)(~-(uint)(_DAT_14000d378 != 0) & 0xc000009a);
      }
    }
    uVar2 = 0xc000009a;
  }
  return uVar2;
}



===== DampUserSessionDelayEnabledGet @ 14001525c =====

bool DampUserSessionDelayEnabledGet(void)

{
  int iVar1;
  bool bVar2;
  int local_res8 [2];
  int local_res10 [2];
  undefined4 local_res18 [4];
  
  local_res8[0] = 4;
  bVar2 = false;
  local_res18[0] = 0;
  local_res10[0] = 0;
  iVar1 = ZwQueryWnfStateData(&WNF_LOGN_DEVICE_FACE_AUTH_ENABLEMENT,0,0,local_res18,local_res10,
                              local_res8);
  if (((-1 < iVar1) && (local_res8[0] != 0)) && (local_res8[0] == 4)) {
    bVar2 = local_res10[0] == 1;
  }
  return bVar2;
}



===== DampUserSessionDelayNotificationCallback @ 1400152d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 DampUserSessionDelayNotificationCallback(void)

{
  bool bVar1;
  bool bVar2;
  undefined1 auStackY_68 [32];
  undefined8 local_38 [4];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  bVar1 = true;
  if (5 < DAT_14000a050) {
    if (((DAT_14000a060 & 0x10) == 0) || (((uint)DAT_14000a068 & 0x10) != DAT_14000a068)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      _tlgWriteTransfer_EtwWriteTransfer(0x14000a050,&DAT_140007f5f,0,0,2,local_38);
    }
  }
  DampFreezeWorkerAcquireLockExclusive(0x14000d440);
  DAT_14000d4bc = DAT_14000d4bc & 0xffffffdf;
  DampFreezeWorkerUpdatePostAndUnlock(&DAT_14000d440);
  if (4 < DAT_14000a050) {
    if (((DAT_14000a060 & 0x10) == 0) || (((uint)DAT_14000a068 & 0x10) != DAT_14000a068)) {
      bVar1 = false;
    }
    if (bVar1) {
      _tlgWriteTransfer_EtwWriteTransfer(0x14000a050,&DAT_140007f2a,0,0,2,local_38);
    }
  }
  return 0;
}



===== DampUserSessionDelayWorkItemRoutine @ 1400153e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DampUserSessionDelayWorkItemRoutine(void)

{
  bool bVar1;
  bool bVar2;
  undefined1 auStackY_98 [32];
  undefined1 local_68 [4];
  undefined4 local_64 [3];
  undefined8 local_58 [4];
  undefined1 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  bVar1 = true;
  if (5 < DAT_14000a050) {
    if (((DAT_14000a060 & 0x10) == 0) || (((uint)DAT_14000a068 & 0x10) != DAT_14000a068)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      local_2c = 0;
      local_38 = local_68;
      local_1c = 0;
      local_28 = local_64;
      local_64[0] = DampTestConfiguration;
      local_68[0] = 0;
      local_30 = 1;
      local_20 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(0x14000a050,&DAT_140007ed2,0,0,4,local_58);
    }
  }
  DampFreezeWorkerAcquireLockExclusive(0x14000d440);
  DAT_14000d4bc = DAT_14000d4bc & 0xffffffdf;
  DampFreezeWorkerUpdatePostAndUnlock(&DAT_14000d440);
  if (4 < DAT_14000a050) {
    if (((DAT_14000a060 & 0x10) == 0) || (((uint)DAT_14000a068 & 0x10) != DAT_14000a068)) {
      bVar1 = false;
    }
    if (bVar1) {
      _tlgWriteTransfer_EtwWriteTransfer(0x14000a050,&DAT_140007ea2,0,0,2,local_58);
    }
  }
  return;
}



===== wil_QueryFeatureState @ 140015528 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
wil_QueryFeatureState
          (uint *param_1,undefined4 param_2,int param_3,undefined8 param_4,undefined8 param_5,
          undefined4 *param_6)

{
  int iVar1;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 local_20;
  uint local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = 0;
  *param_6 = 1;
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



===== DamPolicyGetProcessExemptionGroup @ 140015604 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong DamPolicyGetProcessExemptionGroup(ushort *param_1,ushort *param_2,ushort *param_3)

{
  int iVar1;
  uint uVar2;
  ushort *puVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ushort *puVar6;
  ushort *puVar7;
  undefined8 *puVar8;
  uint *puVar9;
  uint local_res10 [2];
  
  if (param_2 == (ushort *)0x0) {
    return 4;
  }
  puVar7 = (ushort *)0x0;
  local_res10[0] = 0;
  iVar1 = ObQueryNameString(param_2,0,0,local_res10);
  if ((iVar1 == -0x3ffffffc) &&
     (puVar3 = (ushort *)ExAllocatePool2(0x100,local_res10[0],0x4b6d6144), puVar3 != (ushort *)0x0))
  {
    puVar8 = (undefined8 *)(ulonglong)local_res10[0];
    puVar9 = local_res10;
    puVar6 = puVar3;
    iVar1 = ObQueryNameString();
    if (-1 < iVar1) {
      puVar7 = puVar3;
      if (DAT_14000d2d0 != '\0') {
        KeEnterCriticalRegion();
        ExAcquirePushLockSharedEx(&DampDynamicPolicyLock);
        LOCK();
        _DampDynamicPolicy = _DampDynamicPolicy + 1;
        UNLOCK();
        puVar6 = (ushort *)0x0;
        ExReleasePushLockSharedEx(&DampDynamicPolicyLock);
        KeLeaveCriticalRegion();
        puVar8 = DAT_14000d248;
        if (DAT_14000d248 == (undefined8 *)0x0) {
          uVar4 = 4;
        }
        else {
          puVar9 = (uint *)(ulonglong)(uint)DAT_14000d250;
          puVar6 = param_3;
          uVar4 = DampCheckPolicyExemption
                            (puVar3,param_3,(longlong)DAT_14000d248,(uint)DAT_14000d250);
          uVar4 = uVar4 & 0xffffffff;
        }
        param_2 = (ushort *)&DampDynamicPolicy;
        DampReleaseDynamicPolicy((int *)&DampDynamicPolicy);
        if ((int)uVar4 != 4) goto LAB_14001580b;
        if (DAT_14000d2d0 != '\0') {
          puVar8 = &DAT_14000d2b8;
          param_2 = puVar3;
          puVar6 = param_1;
          uVar2 = DampCheckWildcardPolicyExempted(puVar3,param_1,&DAT_14000d2b8);
          uVar4 = (ulonglong)uVar2;
          if (uVar2 != 4) goto LAB_14001580b;
        }
      }
      uVar4 = Feature_RSExWOA__private_IsEnabledDeviceUsageNoInline(param_2,puVar6,puVar8,puVar9);
      if ((((int)uVar4 != 0) ||
          (uVar4 = Feature_NXTShellLauncherResiliencyExempt__private_IsEnabledDeviceUsageNoInline
                             (param_2,puVar6,puVar8,puVar9), (int)uVar4 != 0)) &&
         (DampExperimentalPolicy != 0)) {
        uVar5 = DampCheckPolicyExemption
                          (puVar3,param_3,DampExperimentalPolicy,
                           DampExperimentalPolicyNumberOfRecords);
        uVar4 = uVar5 & 0xffffffff;
        if ((int)uVar5 != 4) goto LAB_14001580b;
      }
      uVar5 = DampCheckPolicyExemption(puVar3,param_3,DampGlobalPolicy,DampPolicyNumberOfRecords);
      uVar4 = uVar5 & 0xffffffff;
      if ((int)uVar5 == 4) {
        uVar2 = DampCheckWildcardPolicyExempted(puVar3,param_1,&DamPolicyContext);
        uVar4 = (ulonglong)uVar2;
        if (uVar2 == 4) {
          iVar1 = PsGetProcessSessionId(param_1);
          uVar4 = (ulonglong)(iVar1 == 0);
        }
      }
      goto LAB_14001580b;
    }
    ExFreePoolWithTag();
  }
  uVar4 = 4;
LAB_14001580b:
  if (puVar7 != (ushort *)0x0) {
    ExFreePoolWithTag(puVar7,0x4b6d6144);
  }
  return uVar4;
}



===== DamPolicyShutdown @ 140015848 =====

void DamPolicyShutdown(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong uVar2;
  uint uVar3;
  longlong lVar4;
  bool bVar5;
  
  if (DampDynamicPolicyKeyHandle != 0) {
    LOCK();
    iVar1 = DampDynamicPolicyKeyRefCount + -1;
    UNLOCK();
    bVar5 = DampDynamicPolicyKeyRefCount == 1;
    DampDynamicPolicyKeyRefCount = iVar1;
    if (bVar5) {
      ZwClose(DampDynamicPolicyKeyHandle);
    }
  }
  if (DampDynamicPolicyAllocated != '\0') {
    param_4 = 0;
    param_3 = 0;
    param_2 = 0;
    KeWaitForSingleObject(&DampDynamicPolicyNotifyCompletedEvent);
  }
  if (DAT_14000d248 != 0) {
    DampReleaseDynamicPolicy((int *)&DampDynamicPolicy);
  }
  uVar2 = 0;
  if (DAT_14000d2c8 != 0) {
    do {
      if (*(longlong *)(DAT_14000d2b8 + 8 + uVar2 * 0x10) != 0) {
        param_2 = 0x4b6d6144;
        ExFreePoolWithTag();
      }
      uVar3 = (int)uVar2 + 1;
      uVar2 = (ulonglong)uVar3;
    } while (uVar3 < DAT_14000d2c8);
  }
  lVar4 = DAT_14000d2b8;
  if (DAT_14000d2b8 != 0) {
    param_2 = 0x4b6d6144;
    ExFreePoolWithTag();
  }
  uVar2 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline
                    (lVar4,param_2,param_3,param_4);
  if (((int)uVar2 != 0) && (DAT_14000d2c0 != 0)) {
    param_2 = 0x4b6d6144;
    ExFreePoolWithTag();
  }
  uVar2 = 0;
  if (DAT_14000d2b0 != 0) {
    do {
      if (*(longlong *)(DamPolicyContext + 8 + uVar2 * 0x10) != 0) {
        param_2 = 0x4b6d6144;
        ExFreePoolWithTag();
      }
      uVar3 = (int)uVar2 + 1;
      uVar2 = (ulonglong)uVar3;
    } while (uVar3 < DAT_14000d2b0);
  }
  lVar4 = DamPolicyContext;
  if (DamPolicyContext != 0) {
    param_2 = 0x4b6d6144;
    ExFreePoolWithTag();
  }
  uVar2 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline
                    (lVar4,param_2,param_3,param_4);
  if (((int)uVar2 != 0) && (lVar4 = DAT_14000d2a8, DAT_14000d2a8 != 0)) {
    param_2 = 0x4b6d6144;
    ExFreePoolWithTag();
  }
  uVar2 = Feature_RSExWOA__private_IsEnabledDeviceUsageNoInline(lVar4,param_2,param_3,param_4);
  if ((int)uVar2 == 0) {
    uVar2 = Feature_NXTShellLauncherResiliencyExempt__private_IsEnabledDeviceUsageNoInline
                      (lVar4,param_2,param_3,param_4);
    if ((int)uVar2 == 0) goto LAB_140015a3e;
  }
  uVar2 = 0;
  if (DampExperimentalPolicyNumberOfRecords != 0) {
    do {
      lVar4 = uVar2 * 0x38 + DampExperimentalPolicy;
      if (*(char *)(lVar4 + 0x28) != '\0') {
        ExFreePoolWithTag(*(undefined8 *)(lVar4 + 8),0x4b6d6144);
      }
      if (*(longlong *)(lVar4 + 0x30) != 0) {
        ExFreePoolWithTag(*(longlong *)(lVar4 + 0x30),0x4b6d6144);
      }
      uVar3 = (int)uVar2 + 1;
      uVar2 = (ulonglong)uVar3;
    } while (uVar3 < DampExperimentalPolicyNumberOfRecords);
  }
  if (DampExperimentalPolicy != 0) {
    ExFreePoolWithTag(DampExperimentalPolicy,0x4b6d6144);
  }
  DampExperimentalPolicyNumberOfRecords = 0;
  DampExperimentalPolicy = 0;
LAB_140015a3e:
  uVar2 = 0;
  if (DampPolicyNumberOfRecords != 0) {
    do {
      lVar4 = uVar2 * 0x38 + DampGlobalPolicy;
      if (*(char *)(lVar4 + 0x28) != '\0') {
        ExFreePoolWithTag(*(undefined8 *)(lVar4 + 8),0x4b6d6144);
      }
      if (*(longlong *)(lVar4 + 0x30) != 0) {
        ExFreePoolWithTag(*(longlong *)(lVar4 + 0x30),0x4b6d6144);
      }
      uVar3 = (int)uVar2 + 1;
      uVar2 = (ulonglong)uVar3;
    } while (uVar3 < DampPolicyNumberOfRecords);
  }
  return;
}



===== DampCheckWildcardPolicyExempted @ 140015aa8 =====

undefined4 DampCheckWildcardPolicyExempted(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  char cVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  
  uVar7 = 0;
  if ((int)param_3[2] != 0) {
    do {
      uVar9 = 0;
      uVar8 = 0;
      uVar4 = param_1;
      cVar1 = FsRtlIsNameInExpression(uVar7 * 0x10 + *param_3,param_1);
      if (cVar1 != '\0') {
        uVar5 = CONCAT71((int7)((ulonglong)uVar4 >> 8),0xc);
        uVar4 = param_2;
        iVar2 = PsCheckProcessFileSigningLevel();
        if (-1 < iVar2) {
          uVar3 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline
                            (uVar4,uVar5,uVar8,uVar9);
          if ((int)uVar3 == 0) {
            return 2;
          }
          return *(undefined4 *)(param_3[1] + uVar7 * 4);
        }
      }
      uVar6 = (int)uVar7 + 1;
      uVar7 = (ulonglong)uVar6;
    } while (uVar6 < *(uint *)(param_3 + 2));
  }
  return 4;
}



===== DampDynamicPolicyRegistryWorker @ 140015b50 =====

void DampDynamicPolicyRegistryWorker(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  LOCK();
  UNLOCK();
  if (DampDynamicPolicyKeyRefCount == 0) {
    LOCK();
    UNLOCK();
  }
  else {
    DampDynamicPolicyKeyRefCount = DampDynamicPolicyKeyRefCount + 1;
    iVar1 = DampReloadDynamicPolicy();
    if ((-1 < iVar1) && ((Microsoft_Windows_DesktopActivityModeratorEnableBits & 8) != 0)) {
      McTemplateK0q_EtwWriteTransfer
                (param_1,&DamEvent_DynamicPolicyReloaded,param_3,(undefined4)DAT_14000d250);
    }
    iVar2 = ZwNotifyChangeKey(DampDynamicPolicyKeyHandle,0,&DampDynamicPolicyWorkItem,1,&local_18,4,
                              0,0,0,1);
    LOCK();
    iVar1 = DampDynamicPolicyKeyRefCount + -1;
    UNLOCK();
    bVar3 = DampDynamicPolicyKeyRefCount == 1;
    DampDynamicPolicyKeyRefCount = iVar1;
    if (bVar3) {
      ZwClose(DampDynamicPolicyKeyHandle);
    }
    if (-1 < iVar2) {
      return;
    }
  }
  KeSetEvent(&DampDynamicPolicyNotifyCompletedEvent,0,0);
  return;
}



===== DampReleaseDynamicPolicy @ 140015c3c =====

void DampReleaseDynamicPolicy(int *param_1)

{
  int iVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  
  LOCK();
  iVar1 = *param_1;
  *param_1 = *param_1 + -1;
  UNLOCK();
  if (iVar1 == 1) {
    uVar4 = 0;
    if (param_1[4] != 0) {
      do {
        lVar2 = uVar4 * 0x38 + *(longlong *)(param_1 + 2);
        if (*(char *)(lVar2 + 0x28) != '\0') {
          ExFreePoolWithTag(*(undefined8 *)(lVar2 + 8),0x4b6d6144);
        }
        if (*(longlong *)(lVar2 + 0x30) != 0) {
          ExFreePoolWithTag(*(longlong *)(lVar2 + 0x30),0x4b6d6144);
        }
        uVar3 = (int)uVar4 + 1;
        uVar4 = (ulonglong)uVar3;
      } while (uVar3 < (uint)param_1[4]);
    }
    if (*(longlong *)(param_1 + 2) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 2),0x4b6d6144);
    }
  }
  return;
}



===== DampReloadDynamicPolicy @ 140015ce4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000140015d8b) */
/* WARNING: Removing unreachable block (ram,0x000140015d95) */
/* WARNING: Removing unreachable block (ram,0x000140015dc1) */
/* WARNING: Removing unreachable block (ram,0x000140015db7) */
/* WARNING: Removing unreachable block (ram,0x000140015e0d) */
/* WARNING: Removing unreachable block (ram,0x000140015e18) */
/* WARNING: Removing unreachable block (ram,0x000140015e37) */
/* WARNING: Removing unreachable block (ram,0x000140015e42) */
/* WARNING: Removing unreachable block (ram,0x000140015e4e) */
/* WARNING: Removing unreachable block (ram,0x000140015faa) */
/* WARNING: Removing unreachable block (ram,0x000140015e66) */
/* WARNING: Removing unreachable block (ram,0x000140015e6f) */
/* WARNING: Removing unreachable block (ram,0x000140015e95) */
/* WARNING: Removing unreachable block (ram,0x000140015ebf) */
/* WARNING: Removing unreachable block (ram,0x000140015fbb) */
/* WARNING: Removing unreachable block (ram,0x000140015fcf) */
/* WARNING: Removing unreachable block (ram,0x000140015eec) */
/* WARNING: Removing unreachable block (ram,0x000140015ef1) */
/* WARNING: Removing unreachable block (ram,0x000140015f17) */
/* WARNING: Removing unreachable block (ram,0x000140015f1a) */
/* WARNING: Removing unreachable block (ram,0x000140015f63) */
/* WARNING: Removing unreachable block (ram,0x000140015f77) */
/* WARNING: Removing unreachable block (ram,0x000140015f6e) */
/* WARNING: Removing unreachable block (ram,0x000140015fd6) */
/* WARNING: Removing unreachable block (ram,0x000140015f72) */
/* WARNING: Removing unreachable block (ram,0x000140015f84) */
/* WARNING: Removing unreachable block (ram,0x000140015fb0) */
/* WARNING: Removing unreachable block (ram,0x000140015fb9) */
/* WARNING: Removing unreachable block (ram,0x00014001608d) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DampReloadDynamicPolicy(void)

{
  int iVar1;
  int *piVar2;
  undefined1 auStackY_d8 [32];
  int local_88;
  undefined4 uStack_84;
  undefined8 uStack_80;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  ulonglong local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_d8;
  uStack_84 = 0;
  local_50 = local_50 & 0xffffffff00000000;
  local_60 = 0;
  uStack_58 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_70 = 0;
  uStack_68 = 0;
  iVar1 = ZwQueryValueKey(DampDynamicPolicyKeyHandle,&DampRegistryValueName,2,&local_48);
  if ((iVar1 == -0x3fffffdd) || (iVar1 == -0x7ffffffb)) {
    iVar1 = 0;
  }
  local_78 = 0;
  uStack_80 = 0;
  local_88 = 1;
  if (iVar1 < 0) {
    piVar2 = &local_88;
  }
  else {
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(&DampDynamicPolicyLock,0);
    local_60 = CONCAT44(uRam000000014000d244,_DampDynamicPolicy);
    uStack_58 = CONCAT44(DAT_14000d248._4_4_,(undefined4)DAT_14000d248);
    local_50 = DAT_14000d250;
    DAT_14000d250 = CONCAT44(uStack_74,local_78);
    _DampDynamicPolicy = local_88;
    uRam000000014000d244 = uStack_84;
    DAT_14000d248._0_4_ = (undefined4)uStack_80;
    DAT_14000d248._4_4_ = uStack_80._4_4_;
    ExReleasePushLockExclusiveEx(&DampDynamicPolicyLock,0);
    KeLeaveCriticalRegion();
    piVar2 = (int *)&local_60;
  }
  DampReleaseDynamicPolicy(piVar2);
  return iVar1;
}



===== DampResolveFilePath @ 1400160d8 =====

int DampResolveFilePath(undefined8 *param_1,longlong *param_2)

{
  int iVar1;
  ushort *puVar2;
  short sVar3;
  short *psVar4;
  ushort uVar5;
  short *_Src;
  ushort uVar6;
  short *psVar7;
  ushort *puVar8;
  undefined8 uVar9;
  uint uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  ushort local_res18;
  ulonglong local_res20;
  uint local_d8;
  ushort *local_d0;
  undefined2 local_c8;
  undefined2 uStack_c6;
  undefined4 uStack_c4;
  short *psStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  short *local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined2 *local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  
  puVar8 = (ushort *)0x0;
  local_b8 = *param_1;
  psVar7 = (short *)param_1[1];
  iVar1 = 0;
  uVar10 = 0;
  uVar11 = 0;
  uVar12 = 0;
  uVar13 = 0;
  local_c8 = 0;
  uStack_c6 = 0;
  uStack_c4 = 0;
  psStack_c0 = (short *)0x0;
  uVar6 = 0;
  local_a8 = (short *)0x0;
  uStack_a0 = 0;
  uStack_b0 = psVar7;
  if ((short)local_b8 != 0) {
    local_d8 = 0;
    local_a8 = (short *)0x0;
    local_d0 = (ushort *)0x0;
    local_res18 = 0;
    uVar9 = local_b8;
    do {
      psVar4 = local_a8;
      psVar7 = uStack_b0;
      local_88 = &local_c8;
      local_98 = 0x30;
      local_80 = 0x240;
      local_b8 = 0;
      local_res20 = local_res20 & 0xffffffff00000000;
      local_78 = 0;
      uStack_70 = 0;
      local_90 = 0;
      local_c8 = (undefined2)uVar9;
      uStack_c6 = (undefined2)((ulonglong)uVar9 >> 0x10);
      uStack_c4 = (undefined4)((ulonglong)uVar9 >> 0x20);
      psStack_c0 = uStack_b0;
      iVar1 = ZwOpenSymbolicLinkObject(&local_b8,1,&local_98);
      while (-1 < iVar1) {
        if (psStack_c0 != psVar7) {
          ExFreePoolWithTag(psStack_c0,0x4b6d6144);
        }
        local_c8 = 0;
        uStack_c6 = 0;
        uStack_c4 = 0;
        psStack_c0 = (short *)0x0;
        iVar1 = ZwQuerySymbolicLinkObject(local_b8,&local_c8,&local_res20);
        if ((iVar1 == -0x7ffffffb) || (iVar1 == -0x3fffffdd)) {
          psStack_c0 = (short *)ExAllocatePool2(0x100,local_res20 & 0xffffffff,0x4b6d6144);
          if (psStack_c0 == (short *)0x0) {
            iVar1 = -0x3fffff66;
          }
          else {
            local_c8 = (undefined2)local_res20;
            uStack_c6 = local_c8;
            iVar1 = ZwQuerySymbolicLinkObject(local_b8,&local_c8,&local_res20);
          }
        }
        ZwClose(local_b8);
        if (iVar1 < 0) {
          if (psStack_c0 != (short *)0x0) {
            ExFreePoolWithTag(psStack_c0,0x4b6d6144);
          }
          goto LAB_14001644f;
        }
        local_88 = &local_c8;
        local_98 = CONCAT44(local_98._4_4_,0x30);
        local_90 = 0;
        local_80 = CONCAT44(local_80._4_4_,0x240);
        local_78 = 0;
        uStack_70 = 0;
        iVar1 = ZwOpenSymbolicLinkObject(&local_b8,1,&local_98);
      }
      if (iVar1 == -0x3fffffdc) {
        uVar10 = CONCAT22(uStack_c6,local_c8);
        uVar12 = SUB84(psStack_c0,0);
        uVar13 = (undefined4)((ulonglong)psStack_c0 >> 0x20);
        iVar1 = 0;
        local_a8 = psStack_c0;
        psVar4 = psStack_c0;
        uVar11 = uStack_c4;
        local_d8 = uVar10;
      }
      else if (psStack_c0 != psVar7) {
        ExFreePoolWithTag(psStack_c0,0x4b6d6144);
      }
      if (iVar1 < 0) {
LAB_14001644f:
        psVar4 = local_a8;
        goto LAB_140016458;
      }
      _Src = psVar4 + ((local_d8 & 0xffff) >> 1);
      sVar3 = (short)local_d8;
      if (sVar3 != 0) {
        do {
          _Src = _Src + -1;
          if (_Src <= psVar4) break;
        } while (*_Src != 0x5c);
      }
      uVar5 = ((short)psVar4 - (short)_Src) + sVar3;
      if ((int)((uint)local_res18 - (uint)uVar6) < (int)(uint)uVar5) {
        if ((uint)uVar5 + (uint)uVar6 < (uint)uVar6) {
          iVar1 = -0x7ffffffb;
        }
        else {
          local_res20 = (ulonglong)(ushort)(uVar5 + uVar6);
          puVar2 = (ushort *)ExAllocatePool2(0x100,local_res20 + 0x200,0x4b6d6144);
          if (puVar2 != (ushort *)0x0) {
            if (uVar6 != 0) {
              memmove((void *)((ulonglong)uVar5 + (longlong)puVar2),local_d0,(ulonglong)uVar6);
            }
            memmove(puVar2,_Src,(ulonglong)uVar5);
            uVar6 = (ushort)local_res20;
            local_res18 = uVar6 + 0x200;
            local_d0 = puVar2;
            goto LAB_1400163eb;
          }
          iVar1 = -0x3fffff66;
        }
        goto LAB_14001644f;
      }
      memmove((void *)((ulonglong)uVar5 + (longlong)local_d0),local_d0,(ulonglong)uVar6);
      memmove(local_d0,_Src,(ulonglong)uVar5);
      uVar6 = uVar6 + uVar5;
LAB_1400163eb:
      psVar4 = local_a8;
      if ((psVar7 != (short *)param_1[1]) && (psVar7 != local_a8)) {
        ExFreePoolWithTag(psVar7,0x4b6d6144);
      }
      local_b8 = CONCAT44(uVar11,uVar10);
      uStack_b0 = (short *)CONCAT44(uVar13,uVar12);
      local_b8 = CONCAT62(local_b8._2_6_,sVar3 - uVar5);
      if ((ushort)(sVar3 - uVar5) == 0) goto LAB_140016503;
      uVar9 = local_b8;
    } while( true );
  }
  psVar4 = (short *)0x0;
  local_d0 = (ushort *)0x0;
  local_res18 = 0;
LAB_14001645c:
  if ((psVar4 != (short *)0x0) && (psVar7 != psVar4)) {
    ExFreePoolWithTag(psVar4,0x4b6d6144);
  }
  if (psVar7 != (short *)param_1[1]) {
    ExFreePoolWithTag(psVar7,0x4b6d6144);
  }
  puVar2 = (ushort *)0x0;
  if (-1 < iVar1) {
    if (0xf < (ulonglong)local_res18 - (ulonglong)uVar6) {
      if (uVar6 != 0) {
        puVar8 = local_d0 + 8;
        memmove(puVar8,local_d0,(ulonglong)uVar6);
      }
      *(ushort **)(local_d0 + 4) = puVar8;
      local_d0[1] = local_res18 - 0x10;
      *local_d0 = uVar6;
      puVar2 = local_d0;
      goto LAB_140016597;
    }
    puVar2 = (ushort *)ExAllocatePool2(0x100,(ulonglong)uVar6 + 0x10,0x4b6d6144);
    if (puVar2 == (ushort *)0x0) {
      iVar1 = -0x3fffff66;
    }
    else {
      if (uVar6 == 0) {
        puVar8 = (ushort *)0x0;
      }
      else {
        puVar8 = puVar2 + 8;
        memmove(puVar8,local_d0,(ulonglong)uVar6);
      }
      *(ushort **)(puVar2 + 4) = puVar8;
      *puVar2 = uVar6;
      puVar2[1] = uVar6;
    }
  }
  if (local_d0 != (ushort *)0x0) {
    ExFreePoolWithTag(local_d0,0x4b6d6144);
  }
  if (iVar1 < 0) {
    return iVar1;
  }
LAB_140016597:
  *param_2 = (longlong)puVar2;
  return iVar1;
LAB_140016503:
  psVar7 = uStack_b0;
LAB_140016458:
  goto LAB_14001645c;
}



===== DampShouldRegisterProcessAtLaunch @ 1400165cc =====

/* WARNING: Removing unreachable block (ram,0x00014001667a) */
/* WARNING: Removing unreachable block (ram,0x000140016694) */
/* WARNING: Removing unreachable block (ram,0x0001400166ae) */
/* WARNING: Removing unreachable block (ram,0x0001400166cc) */
/* WARNING: Removing unreachable block (ram,0x000140016659) */
/* WARNING: Removing unreachable block (ram,0x000140016666) */
/* WARNING: Removing unreachable block (ram,0x000140016674) */
/* WARNING: Removing unreachable block (ram,0x000140016682) */
/* WARNING: Removing unreachable block (ram,0x00014001668e) */
/* WARNING: Removing unreachable block (ram,0x00014001669c) */
/* WARNING: Removing unreachable block (ram,0x0001400166aa) */
/* WARNING: Removing unreachable block (ram,0x0001400166b6) */
/* WARNING: Removing unreachable block (ram,0x0001400166c2) */
/* WARNING: Removing unreachable block (ram,0x0001400166ba) */
/* WARNING: Removing unreachable block (ram,0x0001400166a2) */
/* WARNING: Removing unreachable block (ram,0x000140016686) */
/* WARNING: Removing unreachable block (ram,0x00014001666c) */
/* WARNING: Removing unreachable block (ram,0x00014001665e) */

bool DampShouldRegisterProcessAtLaunch(void)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  uVar3 = PsReferencePrimaryToken();
  iVar2 = 0;
  uVar7 = 0;
  uVar6 = 0;
  uVar5 = 0;
  uVar4 = uVar3;
  iVar1 = RtlQueryPackageClaims();
  if ((iVar1 == -0x3ffffddb) || (-1 < iVar1)) {
    iVar2 = 0x3b0001;
    Feature_PackagedComElevationSupport__private_IsEnabledNoReportingNoInline
              (uVar4,uVar5,uVar6,uVar7);
  }
  ObfDereferenceObject(uVar3);
  return iVar2 == 0x3b0001;
}



===== DampWildCardPolicyUseUpdateWorker @ 140016704 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong DampWildCardPolicyUseUpdateWorker(void)

{
  ulonglong uVar1;
  undefined1 auStackY_1e8 [32];
  undefined1 local_1b8 [4];
  undefined4 local_1b4;
  undefined4 local_1b0;
  undefined4 local_1ac;
  undefined4 local_1a8 [4];
  undefined1 local_198 [4];
  undefined4 local_194;
  undefined4 local_190;
  undefined8 local_78 [4];
  undefined1 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_1e8;
  local_1b4 = 0;
  memset(local_198,0,0x114);
  RtlGetVersion(local_198);
  uVar1 = RtlGetProductInfo(local_194,local_190);
  if (4 < DAT_14000a050) {
    if (((DAT_14000a060 & 1) == 0) ||
       (uVar1 = (ulonglong)((uint)DAT_14000a068 & 1), uVar1 != DAT_14000a068)) {
      uVar1 = uVar1 & 0xffffffffffffff00;
    }
    else {
      uVar1 = 1;
    }
    if ((char)uVar1 != '\0') {
      local_4c = 0;
      local_58 = local_1b8;
      local_3c = 0;
      local_2c = 0;
      local_1c = 0;
      local_1b0 = local_194;
      local_48 = &local_1b0;
      local_1ac = local_190;
      local_38 = &local_1ac;
      local_1a8[0] = local_1b4;
      local_28 = local_1a8;
      local_40 = 4;
      local_30 = 4;
      local_20 = 4;
      local_1b8[0] = 0;
      local_50 = 1;
      uVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x14000a050,&DAT_1400080e1,0,0,6,local_78);
    }
  }
  return uVar1 & 0xffffffffffffff00;
}



===== DamCloseRegistryEvents @ 140016880 =====

void DamCloseRegistryEvents(void)

{
  uint uVar1;
  
  KeEnterCriticalRegion();
  ExAcquireFastMutexUnsafe(&DamStateMutex);
  uVar1 = DAT_14000d1f4;
  DAT_14000d1f4 = DAT_14000d1f4 | 1;
  ExReleaseFastMutexUnsafe(&DamStateMutex);
  KeLeaveCriticalRegion();
  if ((uVar1 & 2) == 0) {
    if (DampRegEventWorkItem != 0) {
      ExFreePoolWithTag(DampRegEventWorkItem,0x4b6d6144);
    }
    DampRegEventWorkItem = 0;
    if (DampRegistryEventsKeyHandle != 0) {
      ZwClose();
    }
    DampRegistryEventsKeyHandle = 0;
  }
  return;
}



===== DamOpenRegistryEvents @ 14001692c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong DamOpenRegistryEvents(undefined8 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  ulonglong uVar6;
  longlong lVar7;
  undefined1 auStack_138 [32];
  undefined8 local_118;
  undefined4 local_110;
  undefined4 *local_108;
  undefined8 local_f8;
  undefined4 local_f0 [2];
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined *local_d0;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined8 *local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  wchar_t *local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined1 local_78 [48];
  undefined1 local_48 [48];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_138;
  local_c4 = 0;
  local_f8 = 0;
  local_f0[0] = 0;
  local_e8 = 0;
  local_d8 = 0;
  local_80 = 0;
  local_e0 = 0x30;
  local_a8 = L"registryRead";
  local_a0 = 0;
  uStack_98 = 0;
  local_b0 = 0x1a0018;
  local_90 = 0;
  uStack_88 = 0;
  local_c8 = 0x240;
  local_c0 = (undefined8 *)0x0;
  uStack_b8 = 0;
  local_d0 = (undefined *)param_1;
  uVar6 = ZwOpenKey(&local_f8,0xf003f,&local_e0);
  if (-1 < (int)uVar6) {
    uVar6 = RtlDeriveCapabilitySidsFromName(&local_b0,local_48,local_78);
    if (-1 < (int)uVar6) {
      iVar1 = RtlLengthSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0x208));
      iVar2 = RtlLengthSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0xc0));
      iVar3 = RtlLengthSid(local_78);
      iVar1 = iVar1 + iVar2 + iVar3 + 0x2c;
      lVar7 = ExAllocatePool2(0x40,iVar1,0x4b6d6144);
      if (lVar7 == 0) {
        ZwClose(local_f8);
        uVar6 = 0xc000009a;
      }
      else {
        RtlCreateAcl(lVar7,iVar1,2);
        RtlAddAccessAllowedAce
                  (lVar7,2,0x80000000,*(undefined8 *)(*(longlong *)SeExports_exref + 0xc0));
        RtlAddAccessAllowedAce
                  (lVar7,2,0x80000000,*(undefined8 *)(*(longlong *)SeExports_exref + 0x208));
        RtlAddAccessAllowedAce(lVar7,2,0x80000000,local_78);
        RtlCreateSecurityDescriptor(&local_a0,1);
        RtlSetDaclSecurityDescriptor(&local_a0,1,lVar7,0);
        uStack_b8 = 0;
        local_d8 = local_f8;
        local_e0 = CONCAT44(local_e0._4_4_,0x30);
        local_d0 = &DampRegistryEventsKeyName;
        local_c0 = &local_a0;
        local_c8 = 0x240;
        local_108 = local_f0;
        local_110 = 1;
        local_118 = 0;
        uVar4 = ZwCreateKey(&local_e8,0xf003f,&local_e0,0);
        uVar6 = (ulonglong)uVar4;
        if (-1 < (int)uVar4) {
          uVar5 = IoSizeofWorkItem();
          DampRegEventWorkItem = ExAllocatePool2(0x40,uVar5,0x4b6d6144);
          if (DampRegEventWorkItem == 0) {
            ZwClose(local_e8);
            uVar6 = 0xc000009a;
          }
          else {
            IoInitializeWorkItem(DamDriverObject,DampRegEventWorkItem);
            DampRegistryEventsKeyHandle = local_e8;
          }
        }
        ZwClose(local_f8);
        ExFreePoolWithTag(lVar7,0x4b6d6144);
      }
    }
  }
  return uVar6;
}



===== DampCheckPolicyCommandLineMatch @ 140016c60 =====

undefined1 DampCheckPolicyCommandLineMatch(ushort *param_1,ushort *param_2,int param_3)

{
  longlong lVar1;
  undefined1 uVar2;
  undefined8 local_18;
  undefined8 uStack_10;
  
  uVar2 = 0;
  if ((param_1 != (ushort *)0x0) && (*(longlong *)(param_1 + 4) != 0)) {
    if (*param_2 <= *param_1) {
      if (param_3 == 1) {
        lVar1 = RtlFindUnicodeSubstring(param_1,param_2,1);
        uVar2 = lVar1 != 0;
      }
      else if (param_3 == 2) {
        local_18 = 0;
        uStack_10 = 0;
        RtlInitUnicodeString
                  (&local_18,
                   *(longlong *)(param_1 + 4) +
                   ((ulonglong)*param_1 - (ulonglong)*param_2 & 0xfffffffffffffffe));
        uVar2 = RtlEqualUnicodeString(param_2,&local_18,1);
      }
    }
  }
  return uVar2;
}



===== DampCrackPolicyPathString @ 140016d04 =====

void DampCrackPolicyPathString
               (undefined8 *param_1,short *param_2,ushort *param_3,undefined4 *param_4,
               undefined4 *param_5)

{
  short sVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  ushort uVar6;
  
  uVar3 = param_1[1];
  *(undefined8 *)param_2 = *param_1;
  *(undefined8 *)(param_2 + 4) = uVar3;
  uVar3 = param_1[1];
  uVar4 = 1;
  *(undefined8 *)param_3 = *param_1;
  *(undefined8 *)(param_3 + 4) = uVar3;
  uVar6 = *param_3;
  while( true ) {
    if (uVar6 < 2) {
      param_3[0] = 0;
      param_3[1] = 0;
      *param_4 = 0;
      *param_5 = 3;
      return;
    }
    sVar1 = **(short **)(param_3 + 4);
    if (sVar1 == 0x26) break;
    if (sVar1 == 0x2a) {
      uVar5 = 1;
      goto LAB_140016d86;
    }
    if (sVar1 == 0x7c) {
      uVar5 = 2;
      goto LAB_140016d86;
    }
    uVar6 = uVar6 - 2;
    *param_3 = uVar6;
    *(short **)(param_3 + 4) = *(short **)(param_3 + 4) + 1;
  }
  uVar5 = 3;
LAB_140016d86:
  *param_5 = uVar5;
  *param_2 = *param_2 - *param_3;
  param_2[1] = *param_2;
  lVar2 = *(longlong *)(param_3 + 4);
  uVar6 = *param_3 - 2;
  *param_3 = uVar6;
  param_3[1] = uVar6;
  *(longlong *)(param_3 + 4) = lVar2 + 2;
  if (uVar6 == 0) {
    uVar4 = 0;
  }
  else if (*(short *)(lVar2 + (ulonglong)(uVar6 >> 1) * 2) == 0x24) {
    *(undefined2 *)(lVar2 + (ulonglong)(uVar6 >> 1) * 2) = 0;
    uVar4 = 2;
    *param_3 = *param_3 - 2;
  }
  *param_4 = uVar4;
  return;
}



===== DampPolOverrideControlExplorerApply @ 140016df0 =====

void DampPolOverrideControlExplorerApply(longlong param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined8 local_18;
  wchar_t *local_10;
  
  local_18 = 0x320030;
  local_10 = L"\\Systemroot\\explorer.exe";
  iVar2 = 1;
  cVar1 = RtlEqualUnicodeString(&local_18,param_1,1);
  if (cVar1 == '\0') {
    return;
  }
  if ((param_2 != 0) && (param_2 != 1)) {
    if (param_2 == 2) {
      iVar2 = 2;
      goto LAB_140016e4c;
    }
    if (param_2 == 3) goto LAB_140016e4c;
  }
  iVar2 = 3;
LAB_140016e4c:
  if (iVar2 < *(int *)(param_1 + 0x24)) {
    *(int *)(param_1 + 0x24) = iVar2;
  }
  return;
}



===== DampCheckPolicyExemption @ 140016e74 =====

undefined8
DampCheckPolicyExemption(undefined8 param_1,ushort *param_2,longlong param_3,uint param_4)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  ushort *puVar4;
  
  uVar3 = 0;
  if (param_4 != 0) {
    puVar4 = (ushort *)(param_3 + 0x10);
    do {
      if (((*(longlong *)(puVar4 + 0x10) != 0) &&
          (cVar2 = RtlEqualUnicodeString(param_1,*(longlong *)(puVar4 + 0x10),1), cVar2 != '\0')) &&
         ((*puVar4 == 0 ||
          (cVar2 = DampCheckPolicyCommandLineMatch(param_2,puVar4,*(int *)(puVar4 + 8)),
          cVar2 != '\0')))) {
        iVar1 = *(int *)(puVar4 + 10);
        if (iVar1 == 0) {
          return 0;
        }
        if (iVar1 == 1) {
          return 1;
        }
        if (iVar1 == 2) {
          return 2;
        }
        if (iVar1 == 3) {
          return 3;
        }
        return 4;
      }
      uVar3 = uVar3 + 1;
      puVar4 = puVar4 + 0x1c;
    } while (uVar3 < param_4);
  }
  return 4;
}



===== DampStateSystemComputePhase @ 140016f44 =====

uint DampStateSystemComputePhase(uint *param_1)

{
  uint uVar1;
  
  uVar1 = *param_1;
  if ((uVar1 & 1) == 0) {
    return uVar1 >> 5 & 1;
  }
  if ((uVar1 & 6) == 0) {
    return 2;
  }
  if ((uVar1 & 2) != 0) {
    if ((uVar1 & 8) == 0) {
      return (uVar1 & 0xff) >> 6 & 1 | 4;
    }
    return 3;
  }
  if ((uVar1 & 4) == 0) {
    return 9;
  }
  if ((uVar1 & 0x10) == 0) {
    return 8;
  }
  return (uVar1 & 0xff) >> 6 | 6;
}



===== DamStatePhaseDefinitionGet @ 140016fa4 =====

undefined * DamStatePhaseDefinitionGet(int param_1)

{
  return &StateDefinitions + (longlong)param_1 * 0x30;
}



===== DampStatePhaseTransitionExecute @ 140016fc4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DampStatePhaseTransitionExecute(longlong param_1,longlong param_2,longlong *param_3)

{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  ulonglong uVar4;
  int iVar5;
  int iVar6;
  ulonglong uVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  undefined1 auStack_a8 [32];
  char local_88;
  byte local_87;
  int local_84;
  ulonglong local_80;
  ulonglong local_70;
  longlong local_68;
  longlong *local_60;
  undefined8 local_58;
  undefined8 local_50;
  longlong local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_a8;
  local_68 = param_2;
  local_60 = param_3;
  local_48 = param_1;
  if (((*(uint *)(param_2 + 0x18) & 1) == 0) ||
     (*(int *)(param_2 + 0x2c) <= *(int *)(param_1 + 0x2c))) {
    local_88 = '\0';
  }
  else {
    local_50 = 500000;
    local_58 = 0;
    local_88 = '\x01';
    ExSetTimer(*(undefined8 *)(*param_3 + 0x18),*(undefined8 *)(*param_3 + 0x20),0,&local_58);
  }
  if (*(int *)(param_2 + 0x28) != 0) {
    DampStateTransitionPhaseTimer(0,0,param_3);
  }
  if (((*(uint *)(param_1 + 0x18) & 8) != 0) && ((*(uint *)(param_2 + 0x18) & 8) == 0)) {
    DampStateTransitionPoNotify(1,1);
  }
  if (((*(uint *)(param_1 + 0x18) & 4) != 0) && ((*(uint *)(param_2 + 0x18) & 4) == 0)) {
    DampStateTransitionPoNotify(1,0);
  }
  iVar6 = *(int *)(param_1 + 0x2c);
  uVar4 = 0xffffffffffffffff;
  iVar8 = *(int *)(param_2 + 0x2c);
  iVar9 = -1;
  if (iVar8 <= iVar6) {
    iVar9 = 1;
  }
  uVar7 = 5;
  if (iVar8 <= iVar6) {
    uVar7 = 0;
  }
  if (iVar8 <= iVar6) {
    uVar4 = 6;
  }
  piVar10 = (int *)(param_2 + uVar7 * 4);
  local_84 = iVar9;
  local_80 = uVar7;
  local_70 = uVar4;
  do {
    iVar8 = *(int *)((longlong)piVar10 + (param_1 - param_2));
    iVar6 = (int)uVar7;
    if (*piVar10 != iVar8) {
      iVar5 = 0;
      local_87 = iVar8 == 1;
      iVar8 = 0;
      if (iVar6 == 0) {
LAB_14001713b:
        DampSession0JobFreeze(iVar5,local_87);
        if (iVar8 == 4) goto LAB_140017198;
      }
      else {
        if (iVar6 != 1) {
          if (iVar6 == 2) {
            iVar5 = 1;
          }
          else {
            if (iVar6 == 3) {
              iVar8 = 2;
              goto LAB_140017149;
            }
            if (iVar6 != 4) {
              if (iVar6 == 5) {
                iVar5 = 3;
                iVar8 = 3;
              }
              goto LAB_14001713b;
            }
            iVar5 = 2;
          }
          iVar8 = 4;
          goto LAB_14001713b;
        }
        iVar8 = 1;
      }
LAB_140017149:
      KeEnterCriticalRegion();
      ExAcquireFastMutexUnsafe(&DamStateMutex);
      DampFreezeUserSessions(iVar8,local_87);
      ExReleaseFastMutexUnsafe(&DamStateMutex);
      KeLeaveCriticalRegion();
    }
LAB_140017198:
    lVar3 = local_48;
    plVar2 = local_60;
    lVar1 = local_68;
    local_80 = local_80 + (longlong)iVar9;
    piVar10 = piVar10 + iVar9;
    uVar7 = (ulonglong)(uint)(iVar6 + iVar9);
    if (local_80 == uVar4) {
      if (local_88 != '\0') {
        local_48 = 0;
        uStack_40 = 0;
        ExCancelTimer();
      }
      if (((*(uint *)(lVar3 + 0x18) & 4) == 0) && ((*(uint *)(lVar1 + 0x18) & 4) != 0)) {
        DampStateTransitionPoNotify(0,0);
      }
      if (*(int *)(lVar3 + 0x28) != 0) {
        DampStateTransitionPhaseTimer(1,*(int *)(lVar3 + 0x28),plVar2);
      }
      if ((*(int *)(lVar3 + 0x20) != *(int *)(lVar1 + 0x20)) &&
         (*(char *)((longlong)plVar2 + 0x2c) == '\0')) {
        PdcNotificationClientAcknowledge(plVar2[3],0);
      }
      if ((*(int *)(lVar3 + 0x24) != *(int *)(lVar1 + 0x24)) &&
         (*(char *)((longlong)plVar2 + 0x2c) == '\0')) {
        KeSetEvent(*plVar2 + 0x108,0,0);
      }
      return;
    }
  } while( true );
}



===== WdmlibIoCreateDeviceSecure @ 1400172bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WdmlibIoCreateDeviceSecure(undefined8 param_1)

{
  undefined8 in_stack_00000048;
  undefined8 local_18;
  undefined8 uStack_10;
  
  if (WdmlibInitialized == '\0') {
    local_18 = 0;
    uStack_10 = 0;
    RtlInitUnicodeString(&local_18,L"IoCreateDeviceSecure");
    PfnIoCreateDeviceSecure = (code *)MmGetSystemRoutineAddress(&local_18);
    if (PfnIoCreateDeviceSecure == (code *)0x0) {
      PfnIoCreateDeviceSecure = IoDevObjCreateDeviceSecure;
    }
    RtlInitUnicodeString(&local_18,L"IoValidateDeviceIoControlAccess");
    MmGetSystemRoutineAddress(&local_18);
    WdmlibInitialized = '\x01';
  }
  (*PfnIoCreateDeviceSecure)
            (param_1,0,&DampNtDeviceName,0x22,0x100,0,&SDDL_DEVOBJ_SYS_ALL,0,in_stack_00000048);
  return;
}



===== IoDevObjCreateDeviceSecure @ 1400173a0 =====

ulonglong IoDevObjCreateDeviceSecure
                    (ulonglong param_1,ulonglong param_2,longlong param_3,undefined4 param_4,
                    undefined4 param_5,undefined1 param_6,ushort *param_7,undefined4 *param_8,
                    undefined8 *param_9)

{
  undefined4 uVar1;
  undefined8 *puVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  uint uVar6;
  longlong local_res18;
  undefined4 local_res20;
  undefined8 local_68;
  longlong lStack_60;
  undefined8 local_58;
  undefined8 local_50;
  longlong local_48;
  undefined8 local_40;
  
  puVar2 = param_9;
  local_res18 = 0;
  local_58 = 0;
  *param_9 = 0;
  param_9 = (undefined8 *)0x0;
  local_68 = 0;
  lStack_60 = 0;
  if ((param_3 == 0) && (-1 < (char)param_5)) {
    return 0xc000000d;
  }
  uVar5 = param_2;
  local_res20 = param_4;
  if ((param_8 != (undefined4 *)0x0) &&
     (uVar5 = param_1,
     uVar4 = PpRegStateReadCreateClassCreationSettings(param_8,param_1,(uint *)&local_68),
     (int)uVar4 < 0)) {
    return uVar4;
  }
  uVar6 = (uint)local_68;
  if ((local_68 & 2) == 0) {
    uVar5 = SeSddlSecurityDescriptorFromSDDL(param_7,uVar5,&local_res18);
    uVar4 = uVar5 & 0xffffffff;
    if ((int)uVar5 < 0) goto LAB_140017500;
    uVar6 = 2;
    local_68 = CONCAT44(local_68._4_4_,2);
    lStack_60 = local_res18;
    if (param_8 != (undefined4 *)0x0) {
      local_50 = 2;
      local_40 = 0;
      local_48 = local_res18;
      uVar5 = PpRegStateUpdateStackCreationSettings(param_8,(longlong)&local_50);
      uVar4 = uVar5 & 0xffffffff;
      if ((int)uVar5 < 0) goto LAB_140017500;
    }
  }
  uVar1 = local_res20;
  if ((uVar6 & 1) != 0) {
    uVar1 = local_68._4_4_;
  }
  if ((uVar6 & 4) != 0) {
    param_5 = (undefined4)local_58;
  }
  if ((uVar6 & 8) != 0) {
    param_6 = local_58._4_1_;
  }
  uVar3 = IoCreateDevice(param_1,param_2 & 0xffffffff,param_3,uVar1,param_5,param_6,&param_9);
  uVar4 = (ulonglong)uVar3;
  if (-1 < (int)uVar3) {
    uVar5 = IopDevObjApplyPostCreationSettings(param_9,(uint *)&local_68);
    uVar4 = uVar5 & 0xffffffff;
    if ((int)uVar5 < 0) {
      IoDeleteDevice(param_9);
    }
    else {
      *puVar2 = param_9;
    }
  }
LAB_140017500:
  if ((uVar6 & 2) != 0) {
    ExFreePoolWithTag(lStack_60,0);
  }
  return uVar4;
}



===== IopDevObjApplyPostCreationSettings @ 140017534 =====

ulonglong IopDevObjApplyPostCreationSettings(undefined8 param_1,uint *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  uint uVar3;
  undefined1 local_res10 [8];
  uint local_res18 [2];
  undefined8 local_res20;
  
  local_res18[0] = 0;
  local_res20 = 0;
  local_res10[0] = 0;
  if ((*param_2 & 2) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = SeUtilSecurityInfoFromSecurityDescriptor
                      (*(undefined8 *)(param_2 + 2),local_res10,local_res18);
    if (-1 < (int)uVar2) {
      uVar3 = -(uint)((local_res18[0] & 3) != 0) & 0x80000;
      uVar1 = uVar3 | 0x40000;
      if ((local_res18[0] & 4) == 0) {
        uVar1 = uVar3;
      }
      uVar3 = uVar1 | 0x1000000;
      if ((local_res18[0] & 8) == 0) {
        uVar3 = uVar1;
      }
      uVar2 = ObOpenObjectByPointer
                        (param_1,0x200,0,uVar3,*(undefined8 *)IoDeviceObjectType_exref,0,
                         &local_res20);
      if (-1 < (int)uVar2) {
        uVar1 = ZwSetSecurityObject(local_res20,local_res18[0],*(undefined8 *)(param_2 + 2));
        uVar2 = (ulonglong)uVar1;
        ZwClose(local_res20);
      }
    }
  }
  return uVar2;
}



===== SeSddlSecurityDescriptorFromSDDL @ 140017624 =====

ulonglong SeSddlSecurityDescriptorFromSDDL(ushort *param_1,undefined8 param_2,longlong *param_3)

{
  ushort uVar1;
  ulonglong uVar2;
  short *_Dst;
  void *_Src;
  
  uVar2 = (ulonglong)*param_1 + 2;
  if (param_1[1] == uVar2) {
    uVar1 = *param_1 >> 1;
    if ((*(short **)(param_1 + 4))[uVar1] == 0) {
      uVar2 = SepSddlSecurityDescriptorFromSDDLString(*(short **)(param_1 + 4),(uint)uVar1,param_3);
      return uVar2;
    }
  }
  _Dst = (short *)ExAllocatePoolWithTag(1,uVar2,0x73546553);
  if (_Dst == (short *)0x0) {
    *param_3 = 0;
    uVar2 = 0xc000009a;
  }
  else {
    memset(_Dst,0,(ulonglong)*param_1 + 2);
    _Src = *(void **)(param_1 + 4);
    memmove(_Dst,_Src,(ulonglong)*param_1);
    _Dst[*param_1 >> 1] = 0;
    uVar2 = SepSddlSecurityDescriptorFromSDDLString(_Dst,(uint)_Src,param_3);
    uVar2 = uVar2 & 0xffffffff;
    ExFreePoolWithTag(_Dst,0);
  }
  return uVar2;
}



===== SepSddlAddAceToAcl @ 140017704 =====

undefined8
SepSddlAddAceToAcl(longlong *param_1,uint *param_2,undefined8 param_3,undefined8 param_4,
                  undefined4 param_5,int param_6,undefined8 param_7)

{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  void *_Dst;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  
  pvVar2 = (void *)*param_1;
  uVar1 = *param_2;
  iVar3 = RtlLengthSid(param_7);
  uVar6 = iVar3 + 8 + uVar1;
  _Dst = pvVar2;
  if (*(ushort *)((longlong)pvVar2 + 2) < uVar6) {
    uVar5 = (iVar3 + 8) * param_6 + uVar1;
    _Dst = (void *)ExAllocatePoolWithTag(1,uVar5,0x6c416553);
    if (_Dst == (void *)0x0) {
      return 0xc000009a;
    }
    memset(_Dst,0,(ulonglong)uVar5);
    memmove(_Dst,(void *)*param_1,(ulonglong)uVar1);
    *(short *)((longlong)_Dst + 2) = (short)uVar5;
    ExFreePoolWithTag(pvVar2,0);
    *param_1 = (longlong)_Dst;
  }
  *param_2 = uVar6;
  uVar4 = RtlAddAccessAllowedAce(_Dst,2,param_5,param_7);
  return uVar4;
}



===== SepSddlDaclFromSDDLString @ 140017804 =====

int SepSddlDaclFromSDDLString
              (short *param_1,undefined8 param_2,undefined4 *param_3,longlong *param_4)

{
  int iVar1;
  longlong lVar2;
  short *psVar3;
  undefined4 uVar4;
  longlong local_res8;
  short *local_res18 [2];
  
  local_res8 = 0;
  local_res18[0] = (short *)0x0;
  *param_4 = 0;
  *param_3 = 0;
  for (; *param_1 == 0x20; param_1 = param_1 + 1) {
  }
  if ((*param_1 != 0x44) || (param_1[1] != 0x3a)) {
    return -0x3ffffff3;
  }
  uVar4 = 0x1008;
  if (param_1[2] != 0x50) {
    uVar4 = 8;
  }
  lVar2 = 4;
  if (param_1[2] != 0x50) {
    lVar2 = 2;
  }
  iVar1 = SepSddlGetAclForString
                    ((wchar_t *)(lVar2 + (longlong)(param_1 + 1)),&local_res8,local_res18);
  if (iVar1 == 0) {
    for (psVar3 = local_res18[0]; *psVar3 == 0x20; psVar3 = psVar3 + 1) {
    }
    if (*psVar3 == 0) {
      *param_4 = local_res8;
      *param_3 = uVar4;
      return 0;
    }
    iVar1 = -0x3ffffff3;
  }
  if (local_res8 != 0) {
    ExFreePoolWithTag(local_res8,0);
  }
  return iVar1;
}



===== SepSddlGetAclForString @ 1400178f0 =====

int SepSddlGetAclForString(wchar_t *param_1,longlong *param_2,undefined8 *param_3)

{
  bool bVar1;
  bool bVar2;
  wchar_t wVar3;
  int iVar4;
  int iVar5;
  wchar_t *pwVar6;
  longlong lVar7;
  undefined8 *puVar8;
  undefined2 *_Dst;
  undefined8 uVar9;
  wchar_t *pwVar10;
  ulonglong uVar11;
  short *psVar12;
  short **ppsVar13;
  undefined8 uVar14;
  uint uVar15;
  uint uVar16;
  undefined **ppuVar17;
  short *local_res8;
  uint local_res10;
  uint local_res18;
  uint local_res20 [2];
  wchar_t *local_58;
  longlong local_50 [2];
  
  *param_2 = 0;
  local_50[0] = 0;
  iVar5 = 0;
  uVar16 = 0;
  pwVar6 = wcschr(param_1,L':');
  *param_3 = pwVar6;
  if (pwVar6 == param_1) {
    return -0x3ffffff3;
  }
  if (pwVar6 == (wchar_t *)0x0) {
    lVar7 = -1;
    do {
      lVar7 = lVar7 + 1;
    } while (param_1[lVar7] != L'\0');
    pwVar6 = param_1 + lVar7;
  }
  else {
    pwVar6 = pwVar6 + -1;
  }
  *param_3 = pwVar6;
  bVar2 = false;
  bVar1 = false;
  uVar14 = 1;
  for (pwVar10 = param_1; pwVar10 < pwVar6; pwVar10 = pwVar10 + 1) {
    if (*pwVar10 == L';') {
      uVar16 = uVar16 + 1;
    }
    else {
      bVar1 = bVar2;
      if (*pwVar10 != L' ') {
        bVar2 = true;
        bVar1 = true;
      }
    }
  }
  local_res18 = uVar16 / 5;
  if ((uVar16 != local_res18 * 5) || ((uVar16 == 0 && (bVar1)))) {
    iVar5 = -0x3ffffff3;
  }
  else {
    if (local_res18 == 0) {
      puVar8 = (undefined8 *)ExAllocatePoolWithTag(1,8);
      *param_2 = (longlong)puVar8;
      if (puVar8 != (undefined8 *)0x0) {
        *puVar8 = 0x80002;
        return 0;
      }
    }
    else {
      uVar16 = local_res18 * 0x30 + 8;
      if (0xffff < uVar16) {
        uVar16 = 0xffff;
      }
      _Dst = (undefined2 *)ExAllocatePoolWithTag(1,uVar16,0x6c416553);
      *param_2 = (longlong)_Dst;
      if (_Dst != (undefined2 *)0x0) {
        local_res20[0] = 8;
        memset(_Dst,0,(ulonglong)uVar16);
        *_Dst = 2;
        _Dst[1] = (short)uVar16;
        *(undefined4 *)(_Dst + 2) = 0;
        local_res10 = 0;
        uVar16 = local_res18;
        uVar15 = 8;
        if (local_res18 != 0) {
          do {
            uVar15 = 0;
            local_res8 = (short *)((ulonglong)local_res8 & 0xffffffff00000000);
            for (; *param_1 == L' '; param_1 = param_1 + 1) {
            }
            if (*param_1 == L'(') {
              do {
                param_1 = param_1 + 1;
              } while (*param_1 == L' ');
            }
            iVar4 = _wcsnicmp(param_1,L"A",1);
            if (iVar4 != 0) {
LAB_140017c8b:
              iVar5 = -0x3ffffff3;
LAB_140017c8d:
              lVar7 = *param_2;
              goto LAB_140017c73;
            }
            for (pwVar6 = param_1 + 2; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
            }
            if (*pwVar6 != L';') goto LAB_140017c8b;
            do {
              pwVar6 = pwVar6 + 1;
              wVar3 = *pwVar6;
            } while (wVar3 == L' ');
            if (wVar3 != L';') {
              do {
                uVar11 = 0;
                while (wVar3 == L' ') {
                  pwVar6 = pwVar6 + 1;
                  wVar3 = *pwVar6;
                }
                ppuVar17 = &PTR_u_RC_14000b210;
                do {
                  iVar4 = _wcsnicmp(pwVar6,(wchar_t *)*ppuVar17,(ulonglong)*(uint *)(ppuVar17 + 1));
                  if (iVar4 == 0) {
                    uVar15 = (uint)local_res8 | *(uint *)(&DAT_14000b21c + uVar11 * 0x10);
                    local_res8 = (short *)CONCAT44(local_res8._4_4_,uVar15);
                    local_58 = pwVar6 + (uint)(&DAT_14000b218)[uVar11 * 4];
                    goto LAB_140017b7d;
                  }
                  uVar16 = (int)uVar11 + 1;
                  uVar11 = (ulonglong)uVar16;
                  ppuVar17 = ppuVar17 + 2;
                } while (uVar16 < 8);
                local_58 = pwVar6;
                SepSddlParseWideStringUlong((ushort *)pwVar6,&local_58,(uint *)&local_res8);
                if (local_58 == pwVar6) goto LAB_140017c8b;
                uVar15 = (uint)local_res8;
LAB_140017b7d:
                wVar3 = *local_58;
                pwVar6 = local_58;
              } while (wVar3 != L';');
              uVar16 = local_res18;
            }
            pwVar6 = pwVar6 + 1;
            if (iVar5 != 0) goto LAB_140017c8d;
            lVar7 = 2;
            do {
              for (; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
              }
              if (*pwVar6 != L';') {
                iVar5 = -0x3ffffff3;
              }
              pwVar6 = pwVar6 + 1;
              lVar7 = lVar7 + -1;
            } while (lVar7 != 0);
            if (iVar5 != 0) goto LAB_140017c8d;
            for (; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
            }
            local_res8 = (short *)0x0;
            ppsVar13 = &local_res8;
            uVar9 = SepSddlGetSidForString(pwVar6,local_50,(longlong *)ppsVar13);
            iVar5 = (int)uVar9;
            if (iVar5 != 0) break;
            psVar12 = local_res8;
            if (local_res8 == (short *)0x0) {
LAB_140017bfb:
              iVar5 = -0x3fffff89;
              goto LAB_140017c8d;
            }
            for (; *psVar12 == 0x20; psVar12 = psVar12 + 1) {
            }
            if (*psVar12 != 0x29) goto LAB_140017bfb;
            param_1 = psVar12 + 1;
            if (local_50[0] != 0) {
              uVar9 = SepSddlAddAceToAcl(param_2,local_res20,ppsVar13,uVar14,uVar15,
                                         uVar16 - local_res10,local_50[0]);
              iVar5 = (int)uVar9;
              if (iVar5 != 0) goto LAB_140017c8d;
            }
            if (*param_1 == L'(') {
              param_1 = psVar12 + 2;
            }
            local_res10 = local_res10 + 1;
          } while (local_res10 < uVar16);
          uVar15 = local_res20[0];
        }
        lVar7 = *param_2;
        if (iVar5 == 0) {
          *(short *)(lVar7 + 2) = (short)uVar15;
          return 0;
        }
LAB_140017c73:
        ExFreePoolWithTag(lVar7,0);
        *param_2 = 0;
        return iVar5;
      }
    }
    iVar5 = -0x3fffff66;
  }
  return iVar5;
}



===== SepSddlGetSidForString @ 140017cb8 =====

undefined8 SepSddlGetSidForString(wchar_t *param_1,undefined8 *param_2,longlong *param_3)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  uint *puVar5;
  uint uVar6;
  ulonglong uVar7;
  
  uVar4 = 0;
  puVar5 = &DAT_14000cd94;
  uVar7 = 0;
  do {
    iVar2 = _wcsnicmp(param_1,(wchar_t *)(&DAT_14000cd8c + uVar7 * 0x18),(ulonglong)*puVar5);
    if (iVar2 == 0) {
      iVar2 = *(int *)(&DAT_14000cd88 + uVar7 * 0x18);
      uVar6 = (&DAT_14000cd94)[uVar7 * 6];
      *param_3 = (longlong)(param_1 + uVar6);
      if (iVar2 == 1) {
        cVar1 = IoIsWdmVersionAvailable(1,CONCAT71((int7)((ulonglong)(param_1 + uVar6) >> 8),0x20));
        if (cVar1 != '\0') goto LAB_140017d4f;
      }
      else {
LAB_140017d4f:
        uVar4 = *(undefined8 *)
                 (*(longlong *)(&DAT_14000cd80 + uVar7 * 0x18) + *(longlong *)SeExports_exref);
      }
      uVar3 = 0;
      goto LAB_140017d64;
    }
    uVar6 = (int)uVar7 + 1;
    uVar7 = (ulonglong)uVar6;
    puVar5 = puVar5 + 6;
  } while (uVar6 < 0xe);
  uVar3 = 0xc0000073;
LAB_140017d64:
  *param_2 = uVar4;
  return uVar3;
}



===== SepSddlParseWideStringUlong @ 140017d8c =====

undefined8 SepSddlParseWideStringUlong(ushort *param_1,undefined8 *param_2,uint *param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  short sVar5;
  uint uVar6;
  int iVar7;
  ushort *puVar8;
  
  uVar1 = *param_1;
  uVar6 = (uint)uVar1;
  *param_3 = 0;
  *param_2 = param_1;
  if (uVar1 == 0x30) {
    if ((param_1[1] - 0x58 & 0xffdf) != 0) {
LAB_140017e0f:
      iVar7 = 10;
      uVar4 = 0;
      puVar8 = param_1;
      goto LAB_140017ded;
    }
    param_1 = param_1 + 2;
    uVar6 = (uint)*param_1;
  }
  else if ((ushort)(uVar1 - 0x30) < 10) goto LAB_140017e0f;
  iVar7 = 0x10;
  puVar8 = param_1;
  uVar4 = 0;
  if ((short)uVar6 == 0) {
    return 0;
  }
LAB_140017ded:
  do {
    sVar5 = (short)uVar6;
    if ((ushort)(sVar5 - 0x30U) < 10) {
      iVar2 = uVar6 - 0x30;
    }
    else {
      if (iVar7 != 0x10) break;
      if ((ushort)(sVar5 - 0x41U) < 6) {
        iVar2 = uVar6 - 0x37;
      }
      else {
        if (5 < (ushort)(sVar5 - 0x61U)) break;
        iVar2 = uVar6 - 0x57;
      }
    }
    uVar3 = iVar7 * uVar4 + iVar2;
    if (uVar3 < uVar4) {
      return 0;
    }
    param_1 = param_1 + 1;
    uVar6 = (uint)*param_1;
    uVar4 = uVar3;
  } while (*param_1 != 0);
  if (param_1 == puVar8) {
    return 0;
  }
  *param_2 = param_1;
  *param_3 = uVar4;
  return 1;
}



===== SepSddlSecurityDescriptorFromSDDLString @ 140017e98 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong SepSddlSecurityDescriptorFromSDDLString(short *param_1,uint param_2,longlong *param_3)

{
  ushort uVar1;
  uint uVar2;
  code *pcVar3;
  ulonglong uVar4;
  void *_Dst;
  wchar_t *pwVar5;
  uint local_res10 [4];
  undefined4 local_res20 [2];
  longlong local_58 [3];
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  
  pwVar5 = L"SeConvertStringSecurityDescriptorToSecurityDescriptor";
  local_58[1] = 0;
  local_58[2] = 0;
  local_res10[0] = param_2;
  RtlInitUnicodeString(local_58 + 1);
  pcVar3 = (code *)MmGetSystemRoutineAddress(local_58 + 1);
  if (pcVar3 != (code *)0x0) {
    uVar4 = (*pcVar3)(param_1,1,param_3);
    if ((int)uVar4 < 0) {
      return uVar4;
    }
    *(ushort *)(*param_3 + 2) = *(ushort *)(*param_3 + 2) | 8;
    return uVar4;
  }
  local_res20[0] = 0;
  local_res10[0] = 0;
  local_58[0] = 0;
  _Dst = (void *)0x0;
  *param_3 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_20 = 0;
  local_30 = 0;
  uStack_28 = 0;
  uVar2 = SepSddlDaclFromSDDLString(param_1,pwVar5,local_res20,local_58);
  if (-1 < (int)uVar2) {
    RtlCreateSecurityDescriptor(&local_40,1);
    RtlSetDaclSecurityDescriptor(&local_40,1,local_58[0],0);
    uVar1 = local_40._2_2_ | (ushort)local_res20[0];
    local_40._0_4_ = CONCAT22(uVar1,(undefined2)local_40);
    RtlAbsoluteToSelfRelativeSD(&local_40,0,local_res10);
    _Dst = (void *)ExAllocatePoolWithTag(1,local_res10[0],0x64536553);
    if (_Dst == (void *)0x0) {
      uVar2 = 0xc000009a;
    }
    else {
      memset(_Dst,0,(ulonglong)local_res10[0]);
      uVar2 = RtlAbsoluteToSelfRelativeSD(&local_40,_Dst,local_res10);
      if (-1 < (int)uVar2) {
        ExFreePoolWithTag(local_58[0],0);
        *param_3 = (longlong)_Dst;
        goto LAB_140017fdd;
      }
    }
  }
  if (local_58[0] != 0) {
    ExFreePoolWithTag(local_58[0],0);
  }
  if (_Dst != (void *)0x0) {
    ExFreePoolWithTag(_Dst,0);
  }
LAB_140017fdd:
  return (ulonglong)uVar2;
}



===== PiRegStateOpenClassKey @ 14001803c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PiRegStateOpenClassKey
                    (undefined4 *param_1,undefined8 param_2,int param_3,undefined4 *param_4,
                    undefined8 *param_5)

{
  undefined8 uVar1;
  uint uVar2;
  ulonglong uVar3;
  wchar_t *pwVar4;
  undefined4 uVar5;
  undefined1 auStackY_128 [32];
  undefined4 local_b8;
  int local_b4;
  undefined8 local_b0;
  undefined8 local_a8 [2];
  wchar_t local_98 [38];
  undefined2 local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_128;
  local_b0 = 0;
  local_a8[0] = 0;
  *param_5 = 0;
  local_b8 = 0;
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  local_b4 = param_3;
  uVar3 = CmRegUtilOpenExistingWstrKey(0,0x140007690,0x20019,&local_b0);
  if (-1 < (int)uVar3) {
    uVar5 = *param_1;
    pwVar4 = L"{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}";
    _snwprintf(local_98,0x27,L"{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}");
    uVar1 = local_b0;
    local_4c = 0;
    if (local_b4 == 0) {
      uVar2 = CmRegUtilOpenExistingWstrKey(local_b0,(longlong)local_98,0xf003f,local_a8);
      uVar5 = 2;
    }
    else {
      uVar3 = CmRegUtilCreateWstrKey(local_b0,(longlong)local_98,pwVar4,uVar5,0,&local_b8,local_a8);
      uVar2 = (uint)uVar3;
      uVar5 = local_b8;
    }
    uVar3 = (ulonglong)uVar2;
    ZwClose(uVar1);
    if ((-1 < (int)uVar2) && (*param_5 = local_a8[0], param_4 != (undefined4 *)0x0)) {
      *param_4 = uVar5;
    }
  }
  return uVar3;
}



===== PiRegStateReadStackCreationSettingsFromKey @ 1400181d8 =====

ulonglong PiRegStateReadStackCreationSettingsFromKey
                    (undefined8 param_1,uint *param_2,uint *param_3,undefined8 param_4)

{
  uint uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  longlong lVar4;
  ulonglong uVar5;
  char local_res10 [8];
  uint local_res18 [2];
  longlong local_res20;
  longlong local_58;
  ushort local_50 [12];
  
  param_2[0] = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  local_res20 = 0;
  local_res18[0] = 0;
  local_res10[0] = '\0';
  local_58 = 0;
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  local_50[4] = 0;
  local_50[5] = 0;
  local_50[6] = 0;
  local_50[7] = 0;
  uVar2 = WdmlibRtlInitUnicodeStringEx((short *)local_50,0x140007610);
  uVar1 = (uint)uVar2;
  lVar4 = 0;
  if (((int)uVar1 < 0) ||
     (uVar1 = CmRegUtilUcValueGetFullBuffer(param_1,local_50,param_3,param_4,&local_58),
     lVar4 = local_58, (int)uVar1 < 0)) {
    uVar5 = (ulonglong)uVar1;
    if (uVar1 == 0xc0000034) {
      uVar5 = 0;
    }
  }
  else {
    param_3 = (uint *)0x1;
    uVar1 = SeCaptureSecurityDescriptor
                      ((ulonglong)*(uint *)(local_58 + 8) + local_58,0,1,1,&local_res20);
    uVar5 = (ulonglong)uVar1;
  }
  if (lVar4 != 0) {
    ExFreePoolWithTag(lVar4,0);
  }
  if (-1 < (int)uVar5) {
    if (local_res20 != 0) {
      param_3 = local_res18;
      uVar3 = SeUtilSecurityInfoFromSecurityDescriptor(local_res20,local_res10,param_3);
      uVar5 = uVar3 & 0xffffffff;
      if ((int)uVar3 < 0) goto LAB_140018357;
      if (local_res10[0] == '\0') {
        *param_2 = *param_2 | 2;
        *(longlong *)(param_2 + 2) = local_res20;
      }
      else {
        ExFreePoolWithTag(local_res20,0);
      }
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x140007628,param_3,param_2 + 1);
    uVar5 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      if ((int)uVar3 != -0x3fffffcc) goto LAB_140018357;
    }
    else {
      *param_2 = *param_2 | 1;
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x140007640,param_3,param_2 + 4);
    uVar5 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      if ((int)uVar3 != -0x3fffffcc) goto LAB_140018357;
    }
    else {
      *param_2 = *param_2 | 4;
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x140007670,param_3,param_2 + 5);
    uVar5 = uVar3 & 0xffffffff;
    if (-1 < (int)uVar3) {
      *param_2 = *param_2 | 8;
      return uVar5;
    }
    if ((int)uVar3 == -0x3fffffcc) {
      return 0;
    }
  }
LAB_140018357:
  if (*(longlong *)(param_2 + 2) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 2),0);
  }
  param_2[0] = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  return uVar5;
}



===== PpRegStateReadCreateClassCreationSettings @ 14001839c =====

ulonglong PpRegStateReadCreateClassCreationSettings
                    (undefined4 *param_1,longlong param_2,uint *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  uint *puVar5;
  undefined8 *puVar6;
  ushort *puVar7;
  int local_res18 [2];
  undefined8 local_res20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  *param_3 = 0;
  param_3[2] = 0;
  param_3[3] = 0;
  param_3[1] = 0;
  param_3[4] = 0;
  param_3[5] = 0;
  local_res18[0] = 0;
  local_res20 = 0;
  local_18 = 0;
  uVar2 = PiRegStateOpenClassKey(param_1,param_2,1,local_res18,&local_res20);
  uVar4 = local_res20;
  if ((int)uVar2 < 0) {
    return uVar2;
  }
  if (local_res18[0] == 2) {
    puVar6 = &local_18;
    puVar5 = (uint *)0x20019;
    uVar1 = CmRegUtilOpenExistingWstrKey(local_res20,0x1400075b0,0x20019,puVar6);
    ZwClose(local_res20);
    if ((int)uVar1 < 0) {
      if (uVar1 == 0xc0000034) {
        return 0;
      }
      return (ulonglong)uVar1;
    }
    uVar2 = PiRegStateReadStackCreationSettingsFromKey(local_18,param_3,puVar5,puVar6);
    uVar2 = uVar2 & 0xffffffff;
    uVar4 = local_18;
  }
  else {
    puVar7 = (ushort *)(*(longlong *)(param_2 + 0x30) + 0x18);
    if (puVar7 == (ushort *)0x0) {
      uVar2 = 0xc000009a;
    }
    else {
      local_18 = 0;
      uStack_10 = 0;
      uVar3 = WdmlibRtlInitUnicodeStringEx((short *)&local_18,0x1400075c8);
      uVar2 = uVar3 & 0xffffffff;
      if (-1 < (int)uVar3) {
        uVar1 = CmRegUtilUcValueSetUcString(uVar4,&local_18,puVar7);
        uVar2 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          local_res18[0] = 0x31;
          uVar1 = CmRegUtilWstrValueSetWstrString(uVar4,0x1400075d8,(longlong)local_res18);
          uVar2 = (ulonglong)uVar1;
          if (-1 < (int)uVar1) {
            uVar1 = CmRegUtilWstrValueSetWstrString(uVar4,0x1400075f8,(longlong)local_res18);
            uVar2 = (ulonglong)uVar1;
          }
        }
      }
    }
  }
  ZwClose(uVar4);
  return uVar2;
}



===== PpRegStateUpdateStackCreationSettings @ 140018500 =====

ulonglong PpRegStateUpdateStackCreationSettings(undefined4 *param_1,longlong param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined *puVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined *local_res18;
  undefined8 local_res20;
  undefined8 local_38;
  short local_30 [12];
  
  uVar8 = 0;
  local_res18 = (undefined *)0x0;
  uVar7 = 0;
  local_38 = 0;
  local_res20 = 0;
  uVar4 = PiRegStateOpenClassKey(param_1,param_2,0,(undefined4 *)0x0,&local_res20);
  uVar2 = (undefined4)uVar8;
  if (-1 < (int)uVar4) {
    puVar6 = &PiRegStateSysAllInherittedSecurityDescriptor;
    if (PiRegStateDiscriptor == 0) {
      uVar8 = CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
      uVar2 = (undefined4)uVar8;
      uVar7 = 1;
      iVar1 = SeCaptureSecurityDescriptor
                        (&PiRegStateSysAllInherittedSecurityDescriptor,0,1,uVar8,&local_res18);
      if (iVar1 < 0) {
        PiRegStateDiscriptor = 2;
      }
      else {
        PiRegStateDiscriptor = 1;
        ExFreePoolWithTag(local_res18,0);
      }
    }
    if (PiRegStateDiscriptor != 1) {
      puVar6 = (undefined *)0x0;
    }
    local_res18 = puVar6;
    uVar5 = CmRegUtilCreateWstrKey
                      (local_res20,0x1400075b0,uVar7,uVar2,puVar6,(undefined4 *)0x0,&local_38);
    uVar4 = uVar5 & 0xffffffff;
    ZwClose(local_res20);
    if (-1 < (int)uVar5) {
      uVar2 = RtlLengthSecurityDescriptor(*(undefined8 *)(param_2 + 8));
      uVar7 = *(undefined8 *)(param_2 + 8);
      local_30[0] = 0;
      local_30[1] = 0;
      local_30[2] = 0;
      local_30[3] = 0;
      local_30[4] = 0;
      local_30[5] = 0;
      local_30[6] = 0;
      local_30[7] = 0;
      uVar5 = WdmlibRtlInitUnicodeStringEx(local_30,0x140007610);
      uVar4 = uVar5 & 0xffffffff;
      if (-1 < (int)uVar5) {
        uVar3 = ZwSetValueKey(local_38,local_30,0,3,uVar7,uVar2);
        uVar4 = (ulonglong)uVar3;
      }
      ZwClose(local_38);
    }
  }
  return uVar4;
}



===== SeUtilSecurityInfoFromSecurityDescriptor @ 140018668 =====

undefined8
SeUtilSecurityInfoFromSecurityDescriptor(undefined8 param_1,undefined1 *param_2,uint *param_3)

{
  undefined8 uVar1;
  uint uVar2;
  undefined1 local_res10 [8];
  char local_res20 [8];
  longlong local_28 [2];
  
  local_28[0] = 0;
  local_28[1] = 0;
  *param_3 = 0;
  *param_2 = 0;
  local_res10[0] = 0;
  local_res20[0] = '\0';
  uVar1 = RtlGetOwnerSecurityDescriptor(param_1,local_28,local_res10);
  if (-1 < (int)uVar1) {
    uVar2 = (uint)(local_28[0] != 0);
    uVar1 = RtlGetGroupSecurityDescriptor(param_1,local_28,local_res10);
    if (-1 < (int)uVar1) {
      if (local_28[0] != 0) {
        uVar2 = uVar2 | 2;
      }
      uVar1 = RtlGetSaclSecurityDescriptor(param_1,local_res20,local_28 + 1,local_res10);
      if (-1 < (int)uVar1) {
        if (local_res20[0] != '\0') {
          uVar2 = uVar2 | 8;
        }
        uVar1 = RtlGetDaclSecurityDescriptor(param_1,local_res20,local_28 + 1,local_res10);
        if (-1 < (int)uVar1) {
          if (local_res20[0] != '\0') {
            uVar2 = uVar2 | 4;
          }
          *param_2 = local_res10[0];
          uVar1 = 0;
          *param_3 = uVar2;
        }
      }
    }
  }
  return uVar1;
}



===== CmRegUtilCreateWstrKey @ 140018764 =====

ulonglong CmRegUtilCreateWstrKey
                    (undefined8 param_1,longlong param_2,undefined8 param_3,undefined4 param_4,
                    undefined8 param_5,undefined4 *param_6,undefined8 *param_7)

{
  uint uVar1;
  ulonglong uVar2;
  undefined4 local_res20 [2];
  undefined8 local_58;
  short local_50 [8];
  undefined8 local_40;
  undefined8 local_38;
  short *local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined8 local_20;
  undefined8 local_18;
  
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  local_50[4] = 0;
  local_50[5] = 0;
  local_50[6] = 0;
  local_50[7] = 0;
  local_res20[0] = param_4;
  uVar2 = WdmlibRtlInitUnicodeStringEx(local_50,param_2);
  if (-1 < (int)uVar2) {
    local_24 = 0;
    local_30 = local_50;
    local_res20[0] = 0;
    local_58 = 0;
    local_18 = 0;
    local_20 = param_5;
    local_40 = 0x30;
    local_28 = 0x240;
    local_38 = param_1;
    uVar1 = ZwCreateKey(&local_58,0xf003f,&local_40,0,0,0,local_res20);
    uVar2 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) {
      local_58 = 0;
      local_res20[0] = 0;
    }
    *param_7 = local_58;
    if (param_6 != (undefined4 *)0x0) {
      *param_6 = local_res20[0];
    }
  }
  return uVar2;
}



===== CmRegUtilOpenExistingWstrKey @ 140018834 =====

void CmRegUtilOpenExistingWstrKey
               (undefined8 param_1,longlong param_2,uint param_3,undefined8 *param_4)

{
  int iVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  undefined8 local_58;
  short local_50 [8];
  undefined8 local_40;
  undefined8 local_38;
  short *local_30;
  undefined4 local_28;
  undefined4 local_24;
  
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  local_50[4] = 0;
  local_50[5] = 0;
  local_50[6] = 0;
  local_50[7] = 0;
  uVar3 = (ulonglong)param_3;
  uVar2 = WdmlibRtlInitUnicodeStringEx(local_50,param_2);
  if (-1 < (int)uVar2) {
    local_24 = 0;
    local_30 = local_50;
    local_58 = 0;
    *param_4 = 0;
    local_40 = 0x30;
    local_28 = 0x240;
    local_38 = param_1;
    iVar1 = ZwOpenKey(&local_58,uVar3 & 0xffffffff,&local_40);
    if (-1 < iVar1) {
      *param_4 = local_58;
    }
  }
  return;
}



===== CmRegUtilUcValueGetFullBuffer @ 1400188c8 =====

int CmRegUtilUcValueGetFullBuffer
              (undefined8 param_1,ushort *param_2,undefined8 param_3,undefined8 param_4,
              undefined8 *param_5)

{
  int iVar1;
  void *_Dst;
  uint uVar2;
  uint local_res20 [2];
  
  local_res20[0] = 0;
  uVar2 = *param_2 + 0x1f & 0xfffffff8;
  *param_5 = 0;
  _Dst = (void *)ExAllocatePoolWithTag(0x200,uVar2,0x62527050);
  if (_Dst == (void *)0x0) {
    return -0x3fffff66;
  }
  memset(_Dst,0,(ulonglong)uVar2);
  iVar1 = ZwQueryValueKey(param_1,param_2,1,_Dst,uVar2,local_res20);
  if (iVar1 < 0) {
    ExFreePoolWithTag(_Dst,0);
    if ((iVar1 != -0x7ffffffb) && (iVar1 != -0x3fffffdd)) {
      return iVar1;
    }
    _Dst = (void *)ExAllocatePoolWithTag(0x200,local_res20[0],0x62527050);
    if (_Dst == (void *)0x0) {
      return -0x3fffff66;
    }
    memset(_Dst,0,(ulonglong)local_res20[0]);
    iVar1 = ZwQueryValueKey(param_1,param_2,1,_Dst,local_res20[0],local_res20);
    if (iVar1 < 0) goto LAB_140018a00;
  }
  if (*(int *)((longlong)_Dst + 4) == 3) {
    *param_5 = _Dst;
    return 0;
  }
  iVar1 = -0x3fffffdc;
LAB_140018a00:
  ExFreePoolWithTag(_Dst,0);
  return iVar1;
}



===== CmRegUtilUcValueSetUcString @ 140018a44 =====

undefined4 CmRegUtilUcValueSetUcString(undefined8 param_1,undefined8 param_2,ushort *param_3)

{
  size_t _Size;
  ushort uVar1;
  undefined4 uVar2;
  ushort local_28;
  short local_26;
  undefined4 local_24;
  void *local_20;
  
  uVar1 = *param_3;
  local_24 = 0;
  if ((ulonglong)param_3[1] - (ulonglong)uVar1 < 2) {
    _Size = (ulonglong)uVar1 + 2;
    local_26 = uVar1 + 2;
    local_20 = (void *)ExAllocatePoolWithTag(1,_Size,0x63557050);
    if (local_20 == (void *)0x0) {
      uVar2 = 0xc000009a;
    }
    else {
      memset(local_20,0,_Size);
      local_28 = *param_3;
      memmove(local_20,*(void **)(param_3 + 4),(ulonglong)local_28);
      *(undefined2 *)((longlong)local_20 + (ulonglong)(local_28 >> 1) * 2) = 0;
      uVar2 = ZwSetValueKey(param_1,param_2,0,1,local_20,local_28 + 2);
      RtlFreeUnicodeString(&local_28);
    }
  }
  else {
    *(undefined2 *)(*(longlong *)(param_3 + 4) + (ulonglong)(uVar1 >> 1) * 2) = 0;
    uVar2 = ZwSetValueKey(param_1,param_2,0,1,*(undefined8 *)(param_3 + 4),*param_3 + 2);
  }
  return uVar2;
}



===== CmRegUtilWstrValueGetDword @ 140018b90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
CmRegUtilWstrValueGetDword
          (undefined8 param_1,longlong param_2,undefined8 param_3,undefined4 *param_4)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined4 *local_40;
  undefined4 local_38 [2];
  short local_30 [8];
  undefined1 local_20 [4];
  int local_1c;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  local_30[0] = 0;
  local_30[1] = 0;
  local_30[2] = 0;
  local_30[3] = 0;
  local_30[4] = 0;
  local_30[5] = 0;
  local_30[6] = 0;
  local_30[7] = 0;
  uVar1 = WdmlibRtlInitUnicodeStringEx(local_30,param_2);
  uVar2 = 0;
  if (-1 < (int)uVar1) {
    local_40 = local_38;
    local_38[0] = 0;
    local_48 = 0x10;
    uVar1 = ZwQueryValueKey(param_1,local_30,2,local_20);
    if (-1 < (int)uVar1) {
      if (local_1c == 4) {
        uVar2 = local_14;
      }
      else {
        uVar1 = 0xc0000024;
      }
    }
    *param_4 = uVar2;
  }
  return uVar1;
}



===== CmRegUtilWstrValueSetWstrString @ 140018c34 =====

void CmRegUtilWstrValueSetWstrString(undefined8 param_1,longlong param_2,longlong param_3)

{
  undefined8 uVar1;
  ushort local_28 [8];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[6] = 0;
  local_28[7] = 0;
  uVar1 = WdmlibRtlInitUnicodeStringEx((short *)local_28,param_3);
  if (-1 < (int)uVar1) {
    uVar1 = WdmlibRtlInitUnicodeStringEx((short *)&local_18,param_2);
    if (-1 < (int)uVar1) {
      CmRegUtilUcValueSetUcString(param_1,&local_18,local_28);
    }
  }
  return;
}



===== CancelTimerCallbacksAndDeleteTimer @ 140018c90 =====

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



===== CreateTlgAggregateSession @ 140018d20 =====

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



===== DestroyAggregateSession @ 140018e78 =====

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



===== FlushEventEntryList @ 140018ec4 =====

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



===== LookUpTableFlushComplete @ 140018f64 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void LookUpTableFlushComplete(longlong param_1)

{
  longlong *plVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  _tlgProvider_t *p_Var5;
  longlong lVar6;
  uint uVar7;
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
  _GUID *local_118;
  _GUID *local_110;
  undefined8 local_108;
  ulonglong local_100;
  longlong local_f8;
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
  uVar2 = *(uint *)(param_1 + 0x100);
  uVar7 = 0;
  if (uVar2 != 0) {
    if ((uVar2 < *(uint *)(param_1 + 0x138)) ||
       (lVar6 = *(longlong *)(param_1 + 0x128), uVar3 = *(uint *)(param_1 + 0x138), lVar6 == 0)) {
      lVar6 = *(longlong *)(param_1 + 0x128);
      *(uint *)(param_1 + 0x138) = uVar2;
      uVar3 = uVar2;
    }
    uVar4 = *(uint *)(param_1 + 0x134);
    if (*(uint *)(param_1 + 0x134) < uVar2) {
      *(uint *)(param_1 + 0x134) = uVar2;
      uVar4 = uVar2;
    }
    plVar1 = (longlong *)(param_1 + 0x120);
    *plVar1 = *plVar1 + (ulonglong)uVar2;
    *(longlong *)(param_1 + 0x128) = lVar6 + 1;
    if (*plVar1 != 0) {
      if (((5 < DAT_14000b290) && ((_DAT_14000b2a0 & 0x200000000000) != 0)) &&
         ((DAT_14000b2a8 & 0x200000000000) == DAT_14000b2a8)) {
        local_148 = (_tlgWrapperByVal<1>)0x4;
        local_e0 = L"SummaryCount";
        local_d8 = 0x18;
        local_130 = (ulonglong)*(uint *)(param_1 + 0x144);
        local_d0 = L"NumLargeEventFailures";
        local_128 = (ulonglong)*(uint *)(param_1 + 0x140);
        local_c0 = L"NumAllocationFailures";
        local_120 = (ulonglong)*(uint *)(param_1 + 0x13c);
        local_b0 = L"NumBucketLimitReached";
        local_a0 = L"MinEntriesFlushed";
        local_90 = L"MaxEntriesFlushed";
        local_80 = L"TotalEntriesFlushed";
        local_78 = 0x26;
        local_100 = (ulonglong)*(uint *)(param_1 + 0x130);
        local_70 = L"MaxEntriesStored";
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
        p_Var5 = *(_tlgProvider_t **)(*(longlong *)(param_1 + 0x158) + 8);
        local_f0 = &local_28;
        local_28 = *(undefined8 *)(p_Var5 + -0x10);
        uStack_20 = *(undefined8 *)(p_Var5 + -8);
        local_138 = 0xffffffff;
        local_68 = 0x20;
        local_13f[0] = (_tlgWrapperByVal<1>)0x0;
        local_134 = 300;
        local_e8 = 0x1000000;
        local_118 = (_GUID *)(ulonglong)uVar3;
        local_110 = (_GUID *)(ulonglong)uVar4;
        local_108 = *(undefined8 *)(param_1 + 0x120);
        local_f8 = lVar6 + 1;
        _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
        ::
        Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByRef<16>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>_>
                  (p_Var5,&DAT_140008166,(_GUID *)(ulonglong)uVar4,(_GUID *)(ulonglong)uVar3,
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
      *(undefined8 *)(param_1 + 0x120) = 0;
      *(undefined8 *)(param_1 + 0x128) = 0;
      local_30 = 0;
      *(undefined8 *)(param_1 + 0x130) = 0;
      *(undefined8 *)(param_1 + 0x138) = 0;
      *(undefined8 *)(param_1 + 0x140) = 0;
    }
    do {
      FlushLookUpTableBucket(param_1,uVar7);
      uVar7 = uVar7 + 1;
    } while (uVar7 < 0x20);
  }
  return;
}



===== LookUpTableFlushPartial @ 14001934c =====

void LookUpTableFlushPartial(longlong param_1)

{
  longlong *plVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = 0;
  if (*(int *)(param_1 + 0x100) != 0) {
    uVar2 = *(uint *)(param_1 + 0x104);
    uVar4 = uVar2;
    do {
      if (*(longlong *)(param_1 + (ulonglong)uVar4 * 8) != 0) {
        iVar3 = FlushLookUpTableBucket(param_1,uVar4);
        uVar5 = uVar5 + iVar3;
      }
      uVar4 = uVar4 + 1 & 0x1f;
    } while ((uVar4 != uVar2) && (uVar5 < 0x10));
    *(uint *)(param_1 + 0x104) = uVar4;
    if (uVar5 != 0) {
      plVar1 = (longlong *)(param_1 + 0x128);
      if ((uVar5 < *(uint *)(param_1 + 0x138)) || (*plVar1 == 0)) {
        *(uint *)(param_1 + 0x138) = uVar5;
      }
      if (*(uint *)(param_1 + 0x134) < uVar5) {
        *(uint *)(param_1 + 0x134) = uVar5;
      }
      *plVar1 = *plVar1 + 1;
      *(longlong *)(param_1 + 0x120) = *(longlong *)(param_1 + 0x120) + (ulonglong)uVar5;
    }
  }
  return;
}



===== TlgAggregateInternalFlushWorkItemRoutineKernelMode @ 140019400 =====

/* void __cdecl TlgAggregateInternalFlushWorkItemRoutineKernelMode(void * __ptr64) */

void __cdecl TlgAggregateInternalFlushWorkItemRoutineKernelMode(void *param_1)

{
  short *psVar1;
  short sVar2;
  short sVar3;
  
  if (*(char *)((longlong)param_1 + 0x174) == '\0') {
    LookUpTableFlushPartial((longlong)param_1);
  }
  else {
    *(undefined1 *)((longlong)param_1 + 0x174) = 0;
    LookUpTableFlushComplete((longlong)param_1);
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



===== TlgAggregateInternalProviderCallback @ 140019490 =====

/* void __cdecl TlgAggregateInternalProviderCallback(struct _GUID const * __ptr64,unsigned
   long,unsigned char,unsigned __int64,unsigned __int64,struct _EVENT_FILTER_DESCRIPTOR *
   __ptr64,void * __ptr64) */

void __cdecl
TlgAggregateInternalProviderCallback
          (_GUID *param_1,ulong param_2,uchar param_3,__uint64 param_4,__uint64 param_5,
          _EVENT_FILTER_DESCRIPTOR *param_6,void *param_7)

{
  char cVar1;
  longlong lVar2;
  
  if (((param_2 == 2) && (param_4 == 0x20)) &&
     (cVar1 = ExTryAcquirePushLockExclusiveEx(&DAT_14000d208,0), cVar1 != '\0')) {
    for (lVar2 = DAT_14000d210; lVar2 != 0; lVar2 = *(longlong *)(lVar2 + 0x160)) {
      LookUpTableFlushComplete(lVar2);
    }
    ExReleasePushLockExclusiveEx(&DAT_14000d208,0);
  }
  return;
}



===== TlgAggregateInternalRegisteredProviderEtwCallback @ 140019500 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl TlgAggregateInternalRegisteredProviderEtwCallback(struct _GUID const *
   __ptr64,unsigned long,unsigned char,unsigned __int64,unsigned __int64,struct
   _EVENT_FILTER_DESCRIPTOR * __ptr64,void * __ptr64) */

void __cdecl
TlgAggregateInternalRegisteredProviderEtwCallback
          (_GUID *param_1,ulong param_2,uchar param_3,__uint64 param_4,__uint64 param_5,
          _EVENT_FILTER_DESCRIPTOR *param_6,void *param_7)

{
  if (*(code **)((longlong)param_7 + 0x148) != (code *)0x0) {
    (**(code **)((longlong)param_7 + 0x148))
              (param_1,param_2,param_3,param_4,param_5,param_6,
               *(undefined8 *)((longlong)param_7 + 0x150));
  }
  if (param_2 == 1) {
    LookUpTableFlushComplete((longlong)param_7);
  }
  else if (param_2 == 2) {
    LookUpTableFlushPartial((longlong)param_7);
  }
  return;
}



===== TlgRegisterAggregateProviderEx @ 14001957c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int TlgRegisterAggregateProviderEx(void)

{
  int iVar1;
  void *pvVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined1 auStack_58 [32];
  uint local_38 [2];
  ulonglong local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  pvVar2 = CreateTlgAggregateSession('\0','\x01');
  if (pvVar2 == (void *)0x0) {
    iVar1 = TraceLoggingRegisterEx_EtwRegister_EtwSetInformation
                      (0x14000a050,DampTracingControlCallback,0);
  }
  else {
    *(undefined8 *)((longlong)pvVar2 + 0x150) = 0;
    local_38[0] = 0;
    *(code **)((longlong)pvVar2 + 0x148) = DampTracingControlCallback;
    *(undefined4 **)((longlong)pvVar2 + 0x158) = &DAT_14000a050;
    *(undefined1 *)((longlong)pvVar2 + 0x175) = 0;
    local_28 = *(undefined8 *)(PTR_DAT_14000a058 + -0x10);
    uStack_20 = *(undefined8 *)(PTR_DAT_14000a058 + -8);
    local_30 = (ulonglong)pvVar2 >> 4;
    RunningHash(local_38,(longlong)&local_28,0x10);
    RunningHash(local_38,(longlong)&local_30,8);
    FinishHash((int *)local_38);
    *(uint *)((longlong)pvVar2 + 0x170) = local_38[0] % 600000 + 600000;
    iVar1 = TraceLoggingRegisterEx_EtwRegister_EtwSetInformation
                      (0x14000a050,TlgAggregateInternalRegisteredProviderEtwCallback,pvVar2);
    if (iVar1 < 0) {
      DAT_14000a078 = 0;
      DestroyAggregateSession((longlong)pvVar2);
    }
    else {
      ExAcquirePushLockExclusiveEx(&DAT_14000d208,0);
      if (DAT_14000d210 == 0) {
        TraceLoggingRegisterEx_EtwRegister_EtwSetInformation
                  (0x14000b290,TlgAggregateInternalProviderCallback,0);
      }
      plVar4 = &DAT_14000d210;
      lVar3 = DAT_14000d210;
      while (lVar3 != 0) {
        if (*(undefined4 **)(lVar3 + 0x158) == &DAT_14000a050) goto LAB_1400196e3;
        plVar4 = (longlong *)(lVar3 + 0x160);
        lVar3 = *plVar4;
      }
      *plVar4 = (longlong)pvVar2;
LAB_1400196e3:
      ExReleasePushLockExclusiveEx(&DAT_14000d208,0);
      iVar1 = 0;
    }
  }
  return iVar1;
}



===== TlgUnregisterAggregateProvider @ 140019734 =====

void TlgUnregisterAggregateProvider(void)

{
  longlong *plVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong lVar5;
  
  uVar2 = DAT_14000a070;
  if (DAT_14000a078 == TlgAggregateInternalRegisteredProviderEtwCallback) {
    lVar5 = 0;
    ExAcquirePushLockExclusiveEx(&DAT_14000d208,0);
    lVar3 = DAT_14000d210;
    plVar4 = &DAT_14000d210;
    while (lVar3 != 0) {
      plVar1 = (longlong *)(lVar3 + 0x160);
      if (*(undefined4 **)(lVar3 + 0x158) == &DAT_14000a050) {
        *plVar4 = *plVar1;
        LookUpTableFlushComplete(lVar3);
        uVar2 = DAT_14000b2b0;
        lVar5 = lVar3;
        if (DAT_14000d210 == 0) {
          DAT_14000b2b0 = 0;
          DAT_14000b290 = 0;
          EtwUnregister(uVar2);
        }
        break;
      }
      plVar4 = plVar1;
      lVar3 = *plVar1;
    }
    ExReleasePushLockExclusiveEx(&DAT_14000d208,0);
    if (lVar5 != 0) {
      CancelTimerCallbacksAndDeleteTimer(lVar5);
    }
    uVar2 = DAT_14000a070;
    DAT_14000a070 = 0;
    DAT_14000a050 = 0;
    EtwUnregister(uVar2);
    DAT_14000a078 = (code *)0x0;
    DestroyAggregateSession(lVar5);
  }
  else {
    DAT_14000a070 = 0;
    DAT_14000a050 = 0;
    EtwUnregister(uVar2);
  }
  return;
}



===== TraceLoggingRegisterEx_EtwRegister_EtwSetInformation @ 140019858 =====

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
  *(undefined8 *)(puVar7 + -8) = 0x1400198b9;
  iVar6 = EtwRegister(puVar7 + 0x20,_tlgEnableCallback,param_1,plVar1);
  if (iVar6 == 0) {
    puVar4 = *(undefined2 **)(param_1 + 8);
    lVar3 = *plVar1;
    uVar2 = *puVar4;
    *(undefined8 *)(puVar7 + -8) = 0x1400198d9;
    EtwSetInformation(lVar3,2,puVar4,uVar2);
  }
  *(undefined8 *)(puVar7 + -8) = 0x1400198ed;
  return iVar6;
}



===== _tlgEnableCallback @ 140019910 =====

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



===== entry @ 14001a010 =====

void entry(undefined *param_1,undefined *param_2,undefined8 param_3)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2,param_3);
  return;
}



===== __security_init_cookie @ 14001a044 =====

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



===== DriverEntry @ 14001a078 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong DriverEntry(undefined *param_1,undefined *param_2,undefined8 param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined *puVar5;
  undefined *puVar6;
  uint uVar7;
  ulonglong uVar8;
  undefined *puVar9;
  char *pcVar10;
  bool bVar11;
  undefined1 auStack_e8 [32];
  undefined4 local_c8;
  uint *local_c0;
  undefined **local_b8;
  undefined **local_a8;
  char local_98 [4];
  uint local_94;
  undefined *local_90;
  undefined *local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined *local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  char local_50 [4];
  int local_4c;
  int local_44;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_e8;
  local_90 = (undefined *)0x0;
  puVar6 = param_1;
  McGenEventRegister_EtwRegister();
  TlgRegisterAggregateProviderEx();
  if ((Microsoft_Windows_DesktopActivityModeratorEnableBits & 1) != 0) {
    McTemplateK0_EtwWriteTransfer(puVar6,&DamEvent_StartDriverBegin,param_3);
  }
  wil_InitializeFeatureStaging();
  DamDriverObject = param_1;
  *(code **)(param_1 + 0x68) = DamDriverUnload;
  uVar7 = 8;
  *(code **)(param_1 + 0x70) = DampIoDispatch;
  *(code **)(param_1 + 0x80) = DampIoDispatch;
  *(code **)(param_1 + 0xe0) = DampIoDispatch;
  *(code **)(param_1 + 0xe8) = DampIoDispatch;
  DAT_14000d354 = DampCheckTestSigningOn();
  DampTestConfiguration = 0;
  DAT_14000d355 = 0;
  DampGlobalInitialize();
  cVar1 = DamIsTestSigningOn();
  if (cVar1 == '\0') {
LAB_14001a1dd:
    puVar6 = (undefined *)0x0;
    local_98[0] = '\0';
    pcVar10 = local_98;
    local_c8 = 1;
    puVar9 = (undefined *)0x0;
    puVar5 = (undefined *)0x42;
    ZwPowerInformation();
    if ((local_98[0] == '\0') && ((Microsoft_Windows_DesktopActivityModeratorEnableBits & 1) != 0))
    {
      puVar6 = &DamEvent_AoAcNotCapable;
      McTemplateK0_EtwWriteTransfer(puVar5,&DamEvent_AoAcNotCapable,puVar9);
    }
    DampAoAc = local_98[0];
    if (local_98[0] == '\0') {
      bVar11 = DampCheckForceEnableDam();
      if (!bVar11) goto LAB_14001a233;
    }
    uVar4 = DampGlobalAllocateState();
    uVar8 = uVar4 & 0xffffffff;
    if ((int)uVar4 < 0) {
LAB_14001a32d:
      param_1 = puVar5;
      if (-1 < (int)uVar8) goto LAB_14001a3aa;
LAB_14001a331:
      param_2 = param_1;
      if ((uVar7 & 4) != 0) {
LAB_14001a336:
        DamAggregateEventsCallbackShutdown();
        param_2 = param_1;
      }
      if ((uVar7 & 2) != 0) goto LAB_14001a340;
    }
    else {
      uVar4 = DamCallbackInitialize();
      uVar8 = uVar4 & 0xffffffff;
      if ((int)uVar4 < 0) goto LAB_14001a32d;
      uVar7 = 9;
      uVar4 = DamOpenRegistryEvents(param_2);
      uVar8 = uVar4 & 0xffffffff;
      puVar5 = param_2;
      if ((int)uVar4 < 0) goto LAB_14001a32d;
      uVar7 = 0xb;
      iVar2 = DamAggregateEventsCallbackInitialize();
      if (iVar2 == 0) {
        uVar3 = DampGlobalStart();
        uVar8 = (ulonglong)uVar3;
        puVar5 = param_2;
        if ((int)uVar3 < 0) goto LAB_14001a32d;
        uVar7 = 0xf;
        cVar1 = DamIsTestSigningOn();
        if (cVar1 == '\0') {
          local_a8 = &local_90;
          uVar3 = WdmlibIoCreateDeviceSecure(param_1);
        }
        else {
          pcVar10 = (char *)0x22;
          local_c0 = (uint *)((ulonglong)local_c0 & 0xffffffffffffff00);
          puVar9 = &DampNtDeviceName;
          puVar6 = (undefined *)0x0;
          local_c8 = 0x100;
          local_b8 = &local_90;
          uVar3 = IoCreateDevice();
        }
        uVar8 = (ulonglong)uVar3;
        if ((int)uVar3 < 0) goto LAB_14001a331;
        puVar6 = &DampNtDeviceName;
        param_1 = &DampWin32DeviceName;
        uVar3 = IoCreateSymbolicLink();
        uVar8 = (ulonglong)uVar3;
        if (-1 < (int)uVar3) {
          uVar8 = 0;
          DampDeviceObject = local_90;
          goto LAB_14001a3aa;
        }
        param_1 = local_90;
        IoDeleteDevice();
        goto LAB_14001a336;
      }
      uVar8 = 0xc0000001;
LAB_14001a340:
      DamCloseRegistryEvents();
    }
    if ((uVar7 & 1) != 0) {
      DamCallbackShutdown();
    }
    if (7 < uVar7) goto LAB_14001a354;
  }
  else {
    local_88 = (undefined *)0x0;
    local_70 = &DampPolicyRegistryPath;
    local_94 = 0;
    local_80 = 0x30;
    local_68 = 0x240;
    local_60 = 0;
    uStack_58 = 0;
    bVar11 = true;
    local_78 = 0;
    iVar2 = ZwOpenKey(&local_88);
    if (iVar2 < 0) goto LAB_14001a1dd;
    local_c0 = &local_94;
    pcVar10 = local_50;
    puVar9 = (undefined *)0x2;
    local_c8 = 0x14;
    puVar6 = &DampEnableDamValueName;
    iVar2 = ZwQueryValueKey();
    if (((-1 < iVar2) && (local_4c == 4)) && (0xf < local_94)) {
      bVar11 = local_44 != 0;
    }
    puVar5 = local_88;
    ZwClose();
    if (bVar11) goto LAB_14001a1dd;
LAB_14001a233:
    param_2 = puVar5;
    uVar8 = 0xc00000bb;
LAB_14001a354:
    DampGlobalRundown(param_2,puVar6,puVar9,pcVar10);
    DampGlobalCleanup();
  }
  DamDriverObject = (undefined *)0x0;
  if (g_wil_details_featureChangeNotification != 0) {
    RtlUnregisterFeatureConfigurationChangeNotification();
    g_wil_details_featureChangeNotification = 0;
  }
  param_1 = g_wil_details_featureUsageProvider;
  if (g_wil_details_featureUsageProvider != (undefined *)0x0) {
    RtlUnregisterFeatureUsageProvider();
    g_wil_details_featureUsageProvider = (undefined *)0x0;
  }
  g_wil_details_isFeatureStagingInitialized = 0;
LAB_14001a3aa:
  if ((Microsoft_Windows_DesktopActivityModeratorEnableBits & 1) != 0) {
    McTemplateK0q_EtwWriteTransfer(param_1,&DamEvent_StartDriverEnd,puVar9,(int)uVar8);
  }
  if ((int)uVar8 < 0) {
    McGenEventUnregister_EtwUnregister();
    TlgUnregisterAggregateProvider();
  }
  return uVar8;
}



===== wil_InitializeFeatureStaging @ 14001a3fc =====

int wil_InitializeFeatureStaging(void)

{
  bool bVar1;
  int iVar2;
  undefined **ppuVar3;
  undefined8 local_res8;
  
  bVar1 = false;
  if (g_wil_details_isFeatureStagingInitialized == 0) {
    g_wil_details_isFeatureStagingInitialized = 1;
    local_res8 = RtlQueryFeatureConfigurationChangeStamp();
    wil_details_PopulateInitialConfiguredFeatureStates();
    wil_details_EvaluateFeatureDependencies();
    for (ppuVar3 = &wil_details_featureDescriptors_a; ppuVar3 < &wil_details_featureDescriptors_z;
        ppuVar3 = ppuVar3 + 1) {
      if (*ppuVar3 != (undefined *)0x0) goto LAB_14001a483;
    }
LAB_14001a4bd:
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
LAB_14001a483:
  if (ppuVar3 == (undefined **)0x0) goto LAB_14001a4bd;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    iVar2 = RtlRegisterFeatureConfigurationChangeNotification
                      (wil_details_ReevaluateOnFeatureConfigurationChange,0,&local_res8,
                       &g_wil_details_featureChangeNotification);
    if (iVar2 == 0) {
      bVar1 = true;
    }
    else {
      g_wil_details_featureChangeNotification = 0;
    }
    goto LAB_14001a4bd;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_14000969f < ppuVar3) goto LAB_14001a4bd;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14001a483;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14001a510 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_PopulateInitialConfiguredFeatureStates(void)

{
  ulonglong *puVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined **ppuVar4;
  undefined1 auStack_48 [32];
  ulonglong local_28;
  undefined8 local_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  ppuVar4 = &wil_details_featureDescriptors_a;
  while( true ) {
    if (&wil_details_featureDescriptors_z <= ppuVar4) {
      return;
    }
    if (*ppuVar4 != (undefined *)0x0) break;
    ppuVar4 = ppuVar4 + 1;
  }
  do {
    if (ppuVar4 == (undefined **)0x0) {
      return;
    }
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    if ((*(char *)((longlong)ppuVar4 + 0x1d) == '\0') &&
       (*(char *)((longlong)ppuVar4 + 0x1e) == '\0')) {
      iVar3 = RtlQueryFeatureConfiguration
                        (*(undefined4 *)(ppuVar4 + 3),
                         1 < (byte)(*(char *)((longlong)ppuVar4 + 0x1c) - 2U),&local_28,&local_20);
      if (iVar3 == -0x7fffffde) {
        do {
          puVar2 = (undefined8 *)*ppuVar4;
          ppuVar4 = ppuVar4 + 7;
          *puVar2 = 0x206;
          while( true ) {
            if (&UNK_14000969f < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_14001a5fa;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_14001a5fa;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_14001a5fa:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_14000969f < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}



===== DamPolicyAllocate @ 14001a68c =====

int DamPolicyAllocate(undefined8 *param_1,longlong *param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong uVar2;
  undefined *puVar3;
  uint uVar4;
  
  uVar4 = 0;
  if (DampPolicyNumberOfRecords != 0) {
    do {
      param_1 = (undefined8 *)((ulonglong)uVar4 * 0x38 + DampGlobalPolicy);
      param_2 = param_1 + 6;
      iVar1 = DampResolveFilePath(param_1,param_2);
      if (iVar1 < 0) {
        return iVar1;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < DampPolicyNumberOfRecords);
  }
  uVar2 = Feature_RSExWOA__private_IsEnabledDeviceUsageNoInline(param_1,param_2,param_3,param_4);
  if ((((int)uVar2 != 0) ||
      (uVar2 = Feature_NXTShellLauncherResiliencyExempt__private_IsEnabledDeviceUsageNoInline
                         (param_1,param_2,param_3,param_4), (int)uVar2 != 0)) &&
     (iVar1 = DampExperimentalPolicyAllocate(param_1,param_2,param_3,param_4), iVar1 < 0)) {
    return iVar1;
  }
  uVar2 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline
                    (param_1,param_2,param_3,param_4);
  if ((int)uVar2 == 0) {
    uVar2 = DampWildCardPolicyUseUpdateWorker();
    if ((char)uVar2 == '\0') {
      uVar4 = 1;
      puVar3 = &DampWildcardRawData;
    }
    else {
      uVar4 = 3;
      puVar3 = &DamWildcardRawDataWithUpdateWorker;
    }
    iVar1 = DampWildcardPolicyAllocate(&DamPolicyContext,(longlong)puVar3,uVar4,param_4);
  }
  else {
    iVar1 = DampWildcardPolicyAllocate2(&DamPolicyContext,param_2,param_3,param_4);
  }
  if (-1 < iVar1) {
    if (DAT_14000d2d0 == '\0') {
      iVar1 = 0;
    }
    else {
      iVar1 = DampDynamicPolicyAllocate();
      if ((-1 < iVar1) && (iVar1 = DampDynamicWildcardPolicyAllocate(&DAT_14000d2b8), -1 < iVar1)) {
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}



===== DamPolicyInitialize @ 14001a76c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DamPolicyInitialize(void)

{
  uint uVar1;
  undefined8 *puVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  undefined **ppuVar5;
  undefined8 *puVar6;
  ulonglong local_res8;
  
  DAT_14000d2d0 = DamIsTestSigningOn();
  uVar3 = 0;
  DampPolicyNumberOfRecords = 0x45;
  DampGlobalPolicy = &DampGlobalPolicyDefault;
  do {
    puVar4 = (undefined8 *)(DampGlobalPolicy + uVar3 * 0x38);
    puVar6 = puVar4 + 4;
    ppuVar5 = (undefined **)(puVar4 + 2);
    puVar2 = puVar4;
    DampCrackPolicyPathString
              (puVar4,(short *)puVar4,(ushort *)ppuVar5,(undefined4 *)puVar6,
               (undefined4 *)((longlong)puVar4 + 0x24));
    local_res8 = (ulonglong)Feature_ControlExplorerDamExemption__private_featureState;
    if ((Feature_ControlExplorerDamExemption__private_featureState & 0x10) == 0) {
      uVar1 = Feature_ControlExplorerDamExemption__private_featureState | 1;
      puVar6 = (undefined8 *)0x1;
      local_res8 = (ulonglong)uVar1;
      wil_details_FeatureReporting_ReportUsageToService(0x1400091d0,local_res8,3,1);
      ppuVar5 = &wil_details_featureDescriptors_a;
      puVar2 = (undefined8 *)0x3;
      wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath
                (uVar1,3,&wil_details_featureDescriptors_a);
    }
    uVar1 = Feature_ControlExplorerDamExemption__private_GetVariant
                      (local_res8,puVar2,(ulonglong)ppuVar5,puVar6);
    DampPolOverrideControlExplorerApply((longlong)puVar4,uVar1);
    uVar1 = (int)uVar3 + 1;
    uVar3 = (ulonglong)uVar1;
  } while (uVar1 < DampPolicyNumberOfRecords);
  _DampDynamicPolicyLock = 0;
  DampDynamicPolicyAllocated = 0;
  KeInitializeEvent(&DampDynamicPolicyNotifyCompletedEvent,0,0);
  DampDynamicPolicyKeyHandle = 0;
  DAT_14000d250 = 0;
  _DAT_14000d2b0 = 0;
  _DAT_14000d2c8 = 0;
  _DampDynamicPolicy = 0;
  DAT_14000d248 = 0;
  DamPolicyContext = 0;
  DAT_14000d2a8 = 0;
  DAT_14000d2b8 = 0;
  DAT_14000d2c0 = 0;
  return;
}



===== DampDynamicPolicyAllocate @ 14001a8ac =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DampDynamicPolicyAllocate(void)

{
  int iVar1;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_38 = 0x30;
  local_1c = 0;
  local_30 = 0;
  local_20 = 0x240;
  local_28 = &DampRegistryKeyName;
  local_18 = 0;
  uStack_10 = 0;
  local_48 = 0;
  uStack_40 = 0;
  iVar1 = ZwOpenKey(&DampDynamicPolicyKeyHandle,0x11,&local_38);
  if (-1 < iVar1) {
    LOCK();
    DampDynamicPolicyKeyRefCount = 1;
    UNLOCK();
    DampReloadDynamicPolicy();
    _DAT_14000d278 = 0;
    _DampDynamicPolicyWorkItem = 0;
    _DAT_14000d270 = DampDynamicPolicyRegistryWorker;
    iVar1 = ZwNotifyChangeKey(DampDynamicPolicyKeyHandle,0,&DampDynamicPolicyWorkItem,1,&local_48,4,
                              0,0,0,1);
    if (-1 < iVar1) {
      DampDynamicPolicyAllocated = 1;
    }
  }
  return;
}



===== DampDynamicWildcardPolicyAllocate @ 14001a9a4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DampDynamicWildcardPolicyAllocate(longlong *param_1)

{
  short *psVar1;
  ulonglong *puVar2;
  short sVar3;
  int iVar4;
  longlong lVar5;
  void *_Dst;
  longlong lVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  short *psVar9;
  uint uVar10;
  uint uVar11;
  ulonglong uVar12;
  ulonglong _Size;
  longlong lVar13;
  uint uVar14;
  uint uVar15;
  undefined1 auStack_c8 [32];
  uint local_a8;
  uint *local_a0;
  uint local_98 [2];
  longlong local_90;
  ulonglong local_88;
  void *pvStack_80;
  ushort local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined *local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_c8;
  local_70 = 0x30;
  local_58 = 0x240;
  local_98[0] = 0;
  local_90 = 0;
  local_68 = 0;
  local_60 = &DampRegistryKeyName;
  lVar5 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_88 = 0;
  pvStack_80 = (void *)0x0;
  local_50 = 0;
  uStack_48 = 0;
  iVar4 = ZwOpenKey(&local_90,1,&local_70);
  if (-1 < iVar4) {
    local_a0 = local_98;
    local_a8 = 0x10;
    iVar4 = ZwQueryValueKey(local_90,&DampRegistryWildcardValueName,2,&local_40);
    if (iVar4 != -0x3fffffcc) {
      if (local_40._4_4_ != 7) {
        iVar4 = -0x3fffffdc;
        goto LAB_14001acb1;
      }
      if (((iVar4 != -0x3fffffdd) && (iVar4 != -0x7ffffffb)) || (0x10000 < local_98[0]))
      goto LAB_14001acac;
      lVar5 = ExAllocatePool2(0x100,local_98[0],0x4b6d6144);
      if (lVar5 == 0) goto LAB_14001aac6;
      local_a0 = local_98;
      local_a8 = local_98[0];
      lVar13 = lVar5;
      iVar4 = ZwQueryValueKey(local_90,&DampRegistryWildcardValueName,2);
      if (iVar4 < 0) goto LAB_14001acb1;
      psVar1 = (short *)(lVar5 + 0xc);
      uVar14 = (*(uint *)(lVar5 + 8) >> 1) - 1;
      uVar12 = (ulonglong)uVar14;
      if ((*(short *)(lVar5 + 0xc + uVar12 * 2) == 0) && (uVar7 = 0, uVar14 != 0)) {
        psVar9 = psVar1;
        do {
          sVar3 = *psVar9;
          psVar9 = psVar9 + 1;
          uVar15 = (uint)uVar7 + 1;
          if (sVar3 != 0) {
            uVar15 = (uint)uVar7;
          }
          uVar7 = (ulonglong)uVar15;
          uVar12 = uVar12 - 1;
        } while (uVar12 != 0);
        if ((uVar15 != 0) && (uVar15 < 0xc9)) {
          uVar12 = (ulonglong)uVar15 * 0x10;
          if (0xffffffff < uVar12) {
LAB_14001aca5:
            iVar4 = -0x3fffff6b;
            goto LAB_14001acb1;
          }
          _Size = uVar12 & 0xffffffff;
          _Dst = (void *)ExAllocatePool2(0x100,uVar12 & 0xffffffff,0x4b6d6144);
          *param_1 = (longlong)_Dst;
          if (_Dst == (void *)0x0) {
LAB_14001aac6:
            iVar4 = -0x3fffff66;
            goto LAB_14001acb1;
          }
          uVar8 = 0;
          memset(_Dst,0,_Size);
          *(uint *)(param_1 + 2) = uVar15;
          uVar12 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline
                             (_Dst,uVar8,_Size,lVar13);
          uVar15 = 0;
          if ((int)uVar12 != 0) {
            lVar6 = ExAllocatePool2(0x100,uVar7 * 4,0x4b6d6144);
            param_1[1] = lVar6;
            if (lVar6 == 0) goto LAB_14001aac6;
          }
          uVar12 = 0;
          uVar10 = uVar15;
          do {
            uVar11 = (uint)uVar12;
            if (psVar1[uVar12] == 0) {
              local_88 = 0;
              pvStack_80 = (void *)0x0;
              if ((ushort)uVar12 < (ushort)uVar10) goto LAB_14001aca5;
              local_78 = ((ushort)uVar12 - (ushort)uVar10) * 2;
              local_88 = (ulonglong)CONCAT22(local_78,local_78);
              pvStack_80 = (void *)ExAllocatePool2(0x100,local_78,0x4b6d6144);
              if (pvStack_80 == (void *)0x0) goto LAB_14001aac6;
              uVar7 = (ulonglong)local_78;
              psVar9 = psVar1 + uVar10;
              memmove(pvStack_80,psVar9,uVar7);
              puVar2 = (ulonglong *)(*param_1 + (ulonglong)uVar15 * 0x10);
              *puVar2 = local_88;
              puVar2[1] = (ulonglong)pvStack_80;
              uVar7 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline
                                ((ulonglong)uVar15 * 2,psVar9,uVar7,lVar13);
              if ((int)uVar7 != 0) {
                *(undefined4 *)(param_1[1] + (ulonglong)uVar15 * 4) = 2;
              }
              uVar15 = uVar15 + 1;
              uVar10 = (uint)uVar12 + 1;
              uVar11 = uVar10;
            }
            uVar12 = (ulonglong)(uVar11 + 1);
          } while (uVar11 + 1 < uVar14);
          goto LAB_14001aa34;
        }
      }
LAB_14001acac:
      iVar4 = -0x3ffff6f5;
      goto LAB_14001acb1;
    }
  }
LAB_14001aa34:
  iVar4 = 0;
LAB_14001acb1:
  if (local_90 != 0) {
    ZwClose();
  }
  if (lVar5 != 0) {
    ExFreePoolWithTag(lVar5,0x4b6d6144);
  }
  return iVar4;
}



===== DampExperimentalPolicyAllocate @ 14001ad18 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DampExperimentalPolicyAllocate
              (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  void *pvVar2;
  int iVar3;
  ulonglong uVar4;
  void *pvVar5;
  ulonglong uVar6;
  longlong lVar7;
  ulonglong uVar8;
  undefined8 *puVar9;
  uint uVar10;
  
  uVar4 = Feature_RSExWOA__private_IsEnabledDeviceUsageNoInline(param_1,param_2,param_3,param_4);
  iVar3 = (int)uVar4;
  uVar4 = Feature_NXTShellLauncherResiliencyExempt__private_IsEnabledDeviceUsageNoInline
                    ((ulonglong)(uint)-iVar3,param_2,param_3,param_4);
  uVar10 = (iVar3 != 0) + 1;
  if ((int)uVar4 == 0) {
    uVar10 = (uint)(iVar3 != 0);
  }
  if (uVar10 != 0) {
    uVar4 = (ulonglong)(uVar10 * 0x38);
    pvVar5 = (void *)ExAllocatePool2(0x100,uVar10 * 0x38,0x4b6d6144);
    if (pvVar5 == (void *)0x0) {
      DampExperimentalPolicy = pvVar5;
      return -0x3fffff66;
    }
    uVar8 = 0;
    DampExperimentalPolicy = pvVar5;
    memset(pvVar5,0,uVar4);
    uVar6 = Feature_RSExWOA__private_IsEnabledDeviceUsageNoInline(pvVar5,uVar8,uVar4,param_4);
    pvVar2 = DampExperimentalPolicy;
    uVar1 = uRam000000014000a280;
    if ((int)uVar6 != 0) {
      pvVar5 = (void *)((ulonglong)DampExperimentalPolicyNumberOfRecords * 0x38);
      DampExperimentalPolicyNumberOfRecords = DampExperimentalPolicyNumberOfRecords + 1;
      uVar8 = (ulonglong)DampExperimentalPolicyNumberOfRecords;
      puVar9 = (undefined8 *)((longlong)pvVar5 + (longlong)DampExperimentalPolicy);
      *puVar9 = _DampExperimentalPolicyData_WOA;
      puVar9[1] = uVar1;
      uVar1 = uRam000000014000a290;
      puVar9 = (undefined8 *)((longlong)pvVar5 + 0x10 + (longlong)pvVar2);
      *puVar9 = _DAT_14000a288;
      puVar9[1] = uVar1;
      uVar1 = uRam000000014000a2a0;
      puVar9 = (undefined8 *)((longlong)pvVar5 + 0x20 + (longlong)pvVar2);
      *puVar9 = _DAT_14000a298;
      puVar9[1] = uVar1;
      *(undefined8 *)((longlong)pvVar5 + 0x30 + (longlong)pvVar2) = DAT_14000a2a8;
    }
    uVar4 = Feature_NXTShellLauncherResiliencyExempt__private_IsEnabledDeviceUsageNoInline
                      (pvVar5,uVar8,uVar4,param_4);
    pvVar5 = DampExperimentalPolicy;
    uVar1 = uRam000000014000a248;
    if ((int)uVar4 != 0) {
      lVar7 = (ulonglong)DampExperimentalPolicyNumberOfRecords * 0x38;
      DampExperimentalPolicyNumberOfRecords = DampExperimentalPolicyNumberOfRecords + 1;
      puVar9 = (undefined8 *)(lVar7 + (longlong)DampExperimentalPolicy);
      *puVar9 = _DampNXTShellLauncherPolicyData;
      puVar9[1] = uVar1;
      uVar1 = uRam000000014000a258;
      puVar9 = (undefined8 *)(lVar7 + 0x10 + (longlong)pvVar5);
      *puVar9 = _DAT_14000a250;
      puVar9[1] = uVar1;
      uVar1 = uRam000000014000a268;
      puVar9 = (undefined8 *)(lVar7 + 0x20 + (longlong)pvVar5);
      *puVar9 = _DAT_14000a260;
      puVar9[1] = uVar1;
      *(undefined8 *)(lVar7 + 0x30 + (longlong)pvVar5) = DAT_14000a270;
    }
    uVar10 = 0;
    if (DampExperimentalPolicyNumberOfRecords != 0) {
      do {
        puVar9 = (undefined8 *)((ulonglong)uVar10 * 0x38 + (longlong)DampExperimentalPolicy);
        DampCrackPolicyPathString
                  (puVar9,(short *)puVar9,(ushort *)(puVar9 + 2),(undefined4 *)(puVar9 + 4),
                   (undefined4 *)((longlong)puVar9 + 0x24));
        iVar3 = DampResolveFilePath(puVar9,puVar9 + 6);
        if (iVar3 < 0) {
          return iVar3;
        }
        uVar10 = uVar10 + 1;
      } while (uVar10 < DampExperimentalPolicyNumberOfRecords);
    }
  }
  return 0;
}



===== DampWildcardPolicyAllocate @ 14001ae94 =====

int DampWildcardPolicyAllocate(longlong *param_1,longlong param_2,uint param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  ushort uVar6;
  ushort *puVar7;
  ushort *puVar8;
  uint uVar9;
  undefined8 uVar10;
  undefined8 *puVar11;
  ushort *local_res20;
  
  local_res20 = (ushort *)0x0;
  uVar2 = (ulonglong)param_3 * 0x10;
  if (0xffffffff < uVar2) {
    return -0x3fffff6b;
  }
  uVar4 = uVar2 & 0xffffffff;
  uVar10 = 0x4b6d6144;
  uVar5 = 0x100;
  lVar3 = ExAllocatePool2();
  *param_1 = lVar3;
  if (lVar3 == 0) {
LAB_14001aeff:
    iVar1 = -0x3fffff66;
  }
  else {
    uVar4 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline
                      (uVar5,uVar4,uVar10,param_4);
    if ((int)uVar4 != 0) {
      lVar3 = ExAllocatePool2(0x100,(ulonglong)param_3 * 4,0x4b6d6144);
      param_1[1] = lVar3;
      if (lVar3 == 0) goto LAB_14001aeff;
    }
    memset((void *)*param_1,0,uVar2 & 0xffffffff);
    uVar2 = 0;
    *(uint *)(param_1 + 2) = param_3;
    if (param_3 != 0) {
      do {
        puVar11 = (undefined8 *)(uVar2 * 0x28 + param_2);
        iVar1 = DampResolveFilePath(puVar11,(longlong *)&local_res20);
        puVar8 = local_res20;
        if (iVar1 < 0) goto LAB_14001b034;
        uVar6 = *local_res20 + *(short *)(puVar11 + 2);
        if (uVar6 < *local_res20) {
          iVar1 = -0x3fffff6b;
          goto LAB_14001b034;
        }
        local_res20 = (ushort *)(ulonglong)uVar6;
        lVar3 = uVar2 * 0x10;
        uVar10 = 0x4b6d6144;
        uVar5 = ExAllocatePool2(0x100,uVar6);
        *(undefined8 *)(lVar3 + 8 + *param_1) = uVar5;
        if (*(longlong *)(lVar3 + 8 + *param_1) == 0) {
          iVar1 = -0x3fffff66;
          goto LAB_14001b034;
        }
        *(short *)(lVar3 + 2 + *param_1) = (short)local_res20;
        RtlUnicodeStringCat((ushort *)(*param_1 + lVar3),puVar8);
        ExFreePoolWithTag(puVar8,0x4b6d6144);
        puVar8 = (ushort *)(puVar11 + 2);
        puVar7 = (ushort *)(*param_1 + lVar3);
        local_res20 = (ushort *)0x0;
        RtlUnicodeStringCat(puVar7,puVar8);
        uVar4 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline
                          (puVar7,puVar8,uVar10,param_4);
        if ((int)uVar4 != 0) {
          *(undefined4 *)(param_1[1] + uVar2 * 4) = *(undefined4 *)(puVar11 + 4);
        }
        uVar9 = (int)uVar2 + 1;
        uVar2 = (ulonglong)uVar9;
      } while (uVar9 < *(uint *)(param_1 + 2));
    }
    puVar8 = (ushort *)0x0;
    iVar1 = 0;
LAB_14001b034:
    if (puVar8 != (ushort *)0x0) {
      ExFreePoolWithTag(puVar8,0x4b6d6144);
    }
  }
  return iVar1;
}



===== DampWildcardPolicyAllocate2 @ 14001b088 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DampWildcardPolicyAllocate2
              (longlong *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong uVar2;
  undefined8 *_Dst;
  undefined8 uVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  int iVar7;
  undefined8 uVar8;
  undefined1 auStack_d8 [32];
  undefined8 local_b8 [4];
  undefined8 local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined *local_60;
  undefined8 uStack_58;
  undefined *local_50;
  undefined8 uStack_48;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_d8;
  uVar3 = 0;
  _Dst = local_b8 + 5;
  uVar8 = 0x78;
  memset(_Dst,0,0x78);
  local_b8[0] = _DampWildcardRawData;
  local_b8[1] = uRam000000014000a220;
  local_98 = DAT_14000a238;
  local_b8[2] = _DAT_14000a228;
  local_b8[3] = uRam000000014000a230;
  uVar2 = DampWildCardPolicyUseUpdateWorker();
  if ((char)uVar2 != '\0') {
    local_90 = _DamWildcardRawDataUpdateWorker;
    uStack_88 = uRam000000014000a158;
    local_70 = _DAT_14000a170;
    uStack_68 = uRam000000014000a178;
    local_80 = _DAT_14000a160;
    uStack_78 = uRam000000014000a168;
    local_50 = PTR_u__UUS___MoUsoCor_14000a190;
    uStack_48 = uRam000000014000a198;
    local_60 = PTR_u__Systemroot_14000a180;
    uStack_58 = uRam000000014000a188;
  }
  uVar4 = -(uint)((char)uVar2 != '\0') & 2;
  uVar5 = uVar4 + 1;
  uVar6 = (ulonglong)uVar5;
  uVar2 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline
                    (_Dst,uVar3,uVar8,param_4);
  if ((int)uVar2 != 0) {
    uVar5 = uVar4 + 2;
    local_b8[uVar6 * 5] = _DamWildcardRawDataMptf;
    local_b8[uVar6 * 5 + 1] = uRam000000014000a130;
    local_b8[uVar6 * 5 + 2] = _DAT_14000a138;
    local_b8[uVar6 * 5 + 3] = uRam000000014000a140;
    local_b8[uVar6 * 5 + 4] = DAT_14000a148;
  }
  iVar1 = DampWildcardPolicyAllocate(param_1,(longlong)local_b8,uVar5,param_4);
  iVar7 = 0;
  if (iVar1 < 0) {
    iVar7 = iVar1;
  }
  return iVar7;
}


