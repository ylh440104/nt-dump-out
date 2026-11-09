
===== _tlgWriteTransfer_EtwWriteTransfer @ 1c0001008 =====

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



===== Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByRef<16>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>_> @ 1c00010ac =====

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
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x1c0009110,param_2,0,0,0x2b,local_2c8);
  return lVar1;
}



===== __report_gsfailure @ 1c0001500 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== memcpy_s @ 1c0001510 =====

errno_t __cdecl memcpy_s(void *_Dst,rsize_t _DstSize,void *_Src,rsize_t _MaxCount)

{
  errno_t eVar1;
  
  if (_MaxCount == 0) {
LAB_1c000152d:
    eVar1 = 0;
  }
  else {
    if (_Dst == (void *)0x0) {
LAB_1c000156f:
      eVar1 = 0x16;
    }
    else {
      if ((_Src != (void *)0x0) && (_MaxCount <= _DstSize)) {
        memcpy(_Dst,_Src,_MaxCount);
        goto LAB_1c000152d;
      }
      memset(_Dst,0,_DstSize);
      if (_Src == (void *)0x0) goto LAB_1c000156f;
      if (_MaxCount <= _DstSize) {
        return 0x16;
      }
      eVar1 = 0x22;
    }
    _guard_check_icall();
  }
  return eVar1;
}



===== _guard_check_icall @ 1c00015b0 =====

void _guard_check_icall(void)

{
  return;
}



===== __cpu_features_init @ 1c00015d0 =====

/* WARNING: Removing unreachable block (ram,0x0001c000163a) */
/* WARNING: Removing unreachable block (ram,0x0001c00015e9) */
/* WARNING: Removing unreachable block (ram,0x0001c00015da) */

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



===== McGenControlCallbackV2 @ 1c00016a0 =====

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



===== McGenEventRegister_EtwRegister @ 1c00017b0 =====

void McGenEventRegister_EtwRegister(void)

{
  longlong *in_R9;
  
  if (*in_R9 == 0) {
    EtwRegister(&Microsoft_Windows_GPIOButtons,McGenControlCallbackV2);
  }
  return;
}



===== McGenEventUnregister_EtwUnregister @ 1c00017e4 =====

undefined8 McGenEventUnregister_EtwUnregister(void)

{
  undefined8 uVar1;
  
  if (Microsoft_Windows_GPIOButtons_Context == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    Microsoft_Windows_GPIOButtons_Context = 0;
  }
  return uVar1;
}



===== WPP_RECORDER_SF_S @ 1c0001818 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_S(undefined8 param_1)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  longlong lVar4;
  wchar_t *in_stack_00000030;
  
  lVar4 = -1;
  lVar3 = 10;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (in_stack_00000030 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (in_stack_00000030[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = in_stack_00000030;
    if (in_stack_00000030 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_510fbab7d28b3ad3e7de6c0b69c24f78_Traceguids,0xd,pwVar2,lVar1,0);
  }
  if (in_stack_00000030 != (wchar_t *)0x0) {
    do {
      lVar4 = lVar4 + 1;
    } while (in_stack_00000030[lVar4] != L'\0');
    lVar3 = lVar4 * 2 + 2;
  }
  if (in_stack_00000030 == (wchar_t *)0x0) {
    in_stack_00000030 = L"NULL";
  }
  WppAutoLogTrace(param_1,2,2,&WPP_510fbab7d28b3ad3e7de6c0b69c24f78_Traceguids,0xd,in_stack_00000030
                  ,lVar3,0);
  return;
}



===== WPP_RECORDER_SF_d @ 1c0001940 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_d(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,4,0);
  }
  WppAutoLogTrace(param_1,2,param_3,param_5,param_4,&param_6,4,0);
  return;
}



===== WppClassicProviderCallback @ 1c0001a40 =====

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



===== _tlgDefineProvider_annotation__TlgTlgAggregateInternalProviderProv @ 1c0001a9c =====

void _tlgDefineProvider_annotation__TlgTlgAggregateInternalProviderProv(void)

{
  return;
}



===== ButtonTraceLoggingFirstPowerButtonPress @ 1c0001aa8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ButtonTraceLoggingFirstPowerButtonPress(longlong param_1)

{
  bool bVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 auStackY_d8 [32];
  undefined1 local_a8;
  undefined1 local_a7 [7];
  undefined8 local_a0;
  undefined8 local_98 [4];
  wchar_t *local_78;
  int local_70;
  undefined4 local_6c;
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
  undefined8 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_d8;
  if (5 < DAT_1c0009098) {
    if (((_DAT_1c00090a8 & 0x400000000000) == 0) ||
       (bVar1 = true, (DAT_1c00090b0 & 0x400000000000) != DAT_1c00090b0)) {
      bVar1 = false;
    }
    if (bVar1) {
      local_78 = *(wchar_t **)(param_1 + 0x1a8);
      lVar2 = -1;
      local_50 = 2;
      if (local_78 == (wchar_t *)0x0) {
        local_78 = L"";
        local_70 = 2;
      }
      else {
        lVar3 = -1;
        do {
          lVar3 = lVar3 + 1;
        } while (local_78[lVar3] != L'\0');
        local_70 = (int)lVar3 * 2 + 2;
      }
      local_68 = *(wchar_t **)(param_1 + 0x1b0);
      local_6c = 0;
      if (local_68 == (wchar_t *)0x0) {
        local_68 = L"";
        local_60 = 2;
      }
      else {
        lVar3 = -1;
        do {
          lVar3 = lVar3 + 1;
        } while (local_68[lVar3] != L'\0');
        local_60 = (int)lVar3 * 2 + 2;
      }
      local_58 = *(wchar_t **)(param_1 + 0x1b8);
      local_5c = 0;
      if (local_58 == (wchar_t *)0x0) {
        local_58 = L"";
      }
      else {
        do {
          lVar2 = lVar2 + 1;
        } while (local_58[lVar2] != L'\0');
        local_50 = (int)lVar2 * 2 + 2;
      }
      local_a8 = *(undefined1 *)(param_1 + 0x1c0);
      local_48 = &local_a8;
      local_a7[0] = *(undefined1 *)(param_1 + 0x119);
      local_38 = local_a7;
      local_28 = &local_a0;
      local_20 = 8;
      local_4c = 0;
      local_40 = 1;
      local_30 = 1;
      local_a0 = 0x1000000;
      _tlgWriteTransfer_EtwWriteTransfer(0x1c0009098,&DAT_1c0007d4a,0,0,8,local_98);
    }
  }
  return;
}



===== Button_AcquireButtonCacheLock @ 1c0001c40 =====

longlong Button_AcquireButtonCacheLock(longlong param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  uint uVar2;
  longlong lVar3;
  longlong *plVar4;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc();
  *param_2 = uVar1;
  uVar2 = 0;
  plVar4 = (longlong *)(param_1 + 0x98);
  do {
    lVar3 = *plVar4;
    if (lVar3 != 0) goto LAB_1c0001c94;
    uVar2 = uVar2 + 1;
    plVar4 = plVar4 + 1;
  } while (uVar2 < 5);
  lVar3 = *(longlong *)(param_1 + 0x98);
  if (lVar3 != 0) {
LAB_1c0001c94:
    KeReleaseSpinLock(param_1 + 200,uVar1);
    uVar1 = KeAcquireInterruptSpinLock(lVar3);
    *param_2 = uVar1;
  }
  return lVar3;
}



===== Button_ConfigureButtonInterrupt @ 1c0001cd0 =====

void Button_ConfigureButtonInterrupt(undefined8 *param_1,undefined8 param_2)

{
  int iVar1;
  
  iVar1 = (int)param_2;
  if (param_1[(longlong)iVar1 + 0x13] == 0) {
    return;
  }
  if (*(char *)(param_1 + 4) == '\0') {
LAB_1c0001d07:
    Button_EnableInterrupt(param_1,param_2);
  }
  else {
    if (iVar1 != 4) {
      if (1 < iVar1 - 2U) {
        return;
      }
      if (*(char *)(param_1 + 6) != '\0') goto LAB_1c0001d07;
    }
    Button_DisableInterrupt(param_1,param_2);
  }
  return;
}



===== Button_DisableInterrupt @ 1c0001d18 =====

void Button_DisableInterrupt(undefined8 *param_1,undefined8 param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 local_res10 [8];
  undefined4 local_18;
  undefined4 local_14;
  undefined8 local_10;
  
  lVar2 = (longlong)(int)param_2;
  local_14 = 0;
  local_res10[0] = 0;
  if (*(char *)((longlong)param_1 + lVar2 * 0x18 + 0x119) != '\0') {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_L(*param_1,param_2,3,0x25,&WPP_ab5e86bec157388494c90161187d07a9_Traceguids,
                        (char)param_2);
    }
    local_10 = param_1[lVar2 + 0x13];
    local_18 = 1;
    IoReportInterruptInactive(&local_18);
    *(undefined1 *)((longlong)param_1 + lVar2 * 0x18 + 0x119) = 0;
    if (*(char *)(lVar2 + 0x78 + (longlong)param_1) == '\x01') {
      lVar1 = Button_AcquireButtonCacheLock((longlong)param_1,local_res10);
      Button_QueueButtonPress(param_1,(int)param_2);
      *(bool *)(param_1 + lVar2 * 3 + 0x25) = *(char *)(param_1 + lVar2 * 3 + 0x25) == '\0';
      Button_ReleaseButtonCacheLock(lVar1,(longlong)param_1,local_res10[0]);
    }
  }
  return;
}



===== Button_EnableInterrupt @ 1c0001e1c =====

void Button_EnableInterrupt(undefined8 *param_1,undefined8 param_2)

{
  longlong lVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined8 local_10;
  
  lVar1 = (longlong)(int)param_2;
  local_14 = 0;
  if (*(char *)((longlong)param_1 + lVar1 * 0x18 + 0x119) == '\0') {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_L(*param_1,param_2,3,0x26,&WPP_ab5e86bec157388494c90161187d07a9_Traceguids,
                        (char)param_2);
    }
    if (*(char *)(param_1 + lVar1 * 3 + 0x25) != '\0') {
      Button_QueueButtonPress(param_1,(int)param_2);
      *(undefined1 *)(param_1 + lVar1 * 3 + 0x25) = 0;
    }
    local_10 = param_1[lVar1 + 0x13];
    local_18 = 1;
    IoReportInterruptActive(&local_18);
    *(undefined1 *)((longlong)param_1 + lVar1 * 0x18 + 0x119) = 1;
  }
  return;
}



===== Button_EvtIoRead @ 1c0001ef0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Button_EvtIoRead(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  undefined1 *puVar4;
  undefined *puVar5;
  undefined8 local_res18 [2];
  undefined8 in_stack_ffffffffffffffd8;
  undefined8 in_stack_ffffffffffffffe8;
  
  local_res18[0] = 0;
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x6e8))(WdfDriverGlobals,uVar2);
  puVar5 = PTR__WDF_BUTTON_CONTEXT_TYPE_INFO_1c0009040;
  puVar3 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  if (param_3 == 5) {
    uVar2 = param_2;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x860))(WdfDriverGlobals,param_2,local_res18);
    if (-1 < iVar1) {
      puVar4 = (undefined1 *)
               (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,local_res18[0],0);
      *puVar4 = *(undefined1 *)(puVar3 + 0xf);
      puVar4[1] = *(undefined1 *)((longlong)puVar3 + 0x79);
      puVar4[2] = *(undefined1 *)((longlong)puVar3 + 0x7a);
      puVar4[3] = *(undefined1 *)((longlong)puVar3 + 0x7b);
      puVar4[4] = *(undefined1 *)((longlong)puVar3 + 0x7c);
      (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_2,0,5);
      return;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*puVar3,uVar2,3,0x21,&WPP_ab5e86bec157388494c90161187d07a9_Traceguids,
                        (char)iVar1);
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_DDd(*puVar3,uVar2,puVar5,0x20,in_stack_ffffffffffffffd8,(char)param_3,
                          in_stack_ffffffffffffffe8,6);
    }
    iVar1 = -0x3ffffdfa;
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar1);
  return;
}



===== Button_EvtIoWrite @ 1c00020b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Button_EvtIoWrite(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  byte bVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  byte *pbVar5;
  longlong lVar6;
  undefined1 local_res18 [8];
  undefined8 local_res20;
  
  local_res20 = 0;
  local_res18[0] = 0;
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x6e8))(WdfDriverGlobals,uVar3);
  puVar4 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,uVar3,PTR__WDF_BUTTON_CONTEXT_TYPE_INFO_1c0009040);
  if (param_3 == 1) {
    uVar3 = param_2;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x858))(WdfDriverGlobals,param_2,&local_res20);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*puVar4,uVar3,3,0x23,&WPP_ab5e86bec157388494c90161187d07a9_Traceguids,
                          (char)iVar2);
      }
    }
    else {
      uVar3 = local_res20;
      pbVar5 = (byte *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,local_res20,0);
      bVar1 = *pbVar5;
      if (bVar1 < 5) {
        lVar6 = Button_AcquireButtonCacheLock((longlong)puVar4,local_res18);
        Button_QueueButtonPress(puVar4,(uint)bVar1);
        Button_ReleaseButtonCacheLock(lVar6,(longlong)puVar4,local_res18[0]);
        Button_RundownButtonQueue(puVar4);
        (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_2,0,1);
        return;
      }
      iVar2 = -0x3ffffff3;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_Dd(*puVar4,uVar3,3,0x24,&WPP_ab5e86bec157388494c90161187d07a9_Traceguids,
                           bVar1,0xd);
      }
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_Dd(*puVar4,uVar3,3,0x22,&WPP_ab5e86bec157388494c90161187d07a9_Traceguids,
                         (char)param_3,6);
    }
    iVar2 = -0x3ffffdfa;
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar2);
  return;
}



===== Button_EvtTimerPowerButtonPressAndHold @ 1c00022d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Button_EvtTimerPowerButtonPressAndHold(undefined8 param_1,undefined8 *param_2)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined1 local_res10 [8];
  undefined8 local_res18;
  byte *local_res20;
  
  local_res20 = (byte *)0x0;
  uVar3 = param_2[2];
  local_res18 = 0;
  local_res10[0] = 0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x4f0))(WdfDriverGlobals,uVar3,&local_res18);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*param_2,uVar3,3,10,&WPP_ab5e86bec157388494c90161187d07a9_Traceguids,
                        (char)iVar1);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*param_2,4,3,0xb,&WPP_ab5e86bec157388494c90161187d07a9_Traceguids);
      }
    }
    ExSetTimer(param_2[0x34],0xfffffffffeced300,0,0);
  }
  else {
    (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,local_res18,5,&local_res20,0);
    lVar2 = Button_AcquireButtonCacheLock((longlong)param_2,local_res10);
    if (*(char *)(param_2 + 0xf) == '\x01') {
      *local_res20 = 1;
      local_res20[1] = 0x88;
      *(undefined1 *)(param_2 + 0xf) = 2;
      *(undefined1 *)((longlong)param_2 + 0x199) = 1;
      Button_ReleaseButtonCacheLock(lVar2,(longlong)param_2,local_res10[0]);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_LL(*param_2,(ulonglong)*local_res20,3,0xc,
                           &WPP_ab5e86bec157388494c90161187d07a9_Traceguids,*local_res20,
                           local_res20[1]);
      }
      (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,local_res18,0,5);
    }
    else {
      Button_ReleaseButtonCacheLock(lVar2,(longlong)param_2,local_res10[0]);
      uVar3 = local_res18;
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x8d8))(WdfDriverGlobals);
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_d(*param_2,uVar3,3,0xd,&WPP_ab5e86bec157388494c90161187d07a9_Traceguids,
                            (char)iVar1);
        }
        (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,local_res18,iVar1);
      }
    }
  }
  return;
}



===== Button_HidReadReport @ 1c00024f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Button_HidReadReport(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 *puVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined2 uVar5;
  undefined8 local_res18 [2];
  
  local_res18[0] = 0;
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_BUTTON_CONTEXT_TYPE_INFO_1c0009040);
  uVar4 = param_2;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,5,local_res18,0);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c00025ed;
    uVar5 = 0x13;
  }
  else {
    uVar3 = Button_ReadButtonPress(puVar2,param_2);
    if ((char)uVar3 != '\0') {
      return;
    }
    uVar4 = param_2;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x8c8))(WdfDriverGlobals,param_2,puVar2[2]);
    if (-1 < iVar1) {
      return;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c00025ed;
    uVar5 = 0x14;
  }
  WPP_RECORDER_SF_d(*puVar2,uVar4,3,uVar5,&WPP_ab5e86bec157388494c90161187d07a9_Traceguids,
                    (char)iVar1);
LAB_1c00025ed:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar1);
  return;
}



===== Button_InterruptDpc @ 1c0002630 =====

void Button_InterruptDpc(void)

{
  undefined8 *in_R9;
  
  Button_RundownButtonQueue(in_R9);
  return;
}



===== Button_Isr @ 1c0002650 =====

undefined1 Button_Isr(undefined8 param_1,byte *param_2)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(param_2 + 8);
  Button_QueueButtonPress(puVar1,(uint)*param_2);
  KeInsertQueueDpc(puVar1[0x32] + 200,*(undefined8 *)(puVar1[0x32] + 0x20),puVar1);
  return 1;
}



===== Button_QueueButtonPress @ 1c0002698 =====

void Button_QueueButtonPress(undefined8 *param_1,int param_2)

{
  uint *puVar1;
  int *piVar2;
  
  piVar2 = (int *)((longlong)param_1 + (longlong)param_2 * 4 + 0x80);
  *piVar2 = *piVar2 + 1;
  puVar1 = (uint *)((longlong)param_1 + 0xd4);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_DcLLLLLL(*param_1);
  }
  *(char *)((ulonglong)*puVar1 + 0xd8 + (longlong)param_1) = (char)param_2;
  *puVar1 = *puVar1 + 1;
  *puVar1 = *puVar1 & 0x3f;
  return;
}



===== Button_ReadButtonPress @ 1c0002744 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong Button_ReadButtonPress(undefined8 *param_1,undefined8 param_2)

{
  byte bVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  byte *pbVar6;
  undefined8 uVar7;
  undefined2 uVar8;
  undefined1 local_res18 [8];
  int local_res20 [2];
  int *piVar9;
  byte bVar10;
  int local_28 [2];
  byte *local_20;
  
  local_20 = (byte *)0x0;
  local_28[0] = 0;
  local_res20[0] = 0;
  local_res18[0] = 0;
  (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,5,&local_20,0);
  lVar2 = Button_AcquireButtonCacheLock((longlong)param_1,local_res18);
  piVar9 = local_res20;
  pbVar6 = local_20 + 1;
  uVar3 = Button_ReadDataFromCache
                    ((longlong)param_1,(char *)local_20,(char *)pbVar6,local_28,piVar9);
  uVar7 = CONCAT71((int7)((ulonglong)pbVar6 >> 8),local_res18[0]);
  uVar4 = Button_ReleaseButtonCacheLock(lVar2,(longlong)param_1,local_res18[0]);
  if (local_res20[0] != 0) {
    if (local_res20[0] == 1) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_I(*param_1,0,uVar7,0xe,piVar9,(char)_DAT_fffff78000000008);
      }
      if (*(char *)((longlong)param_1 + 0x1c1) == '\0') {
        *(undefined1 *)((longlong)param_1 + 0x1c1) = 1;
        ButtonTraceLoggingFirstPowerButtonPress((longlong)param_1);
      }
      uVar4 = 1;
    }
    else {
      if (local_res20[0] != 2) goto LAB_1c000286e;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_I(*param_1,1,uVar7,0xf,piVar9,(char)_DAT_fffff78000000008);
      }
      uVar4 = 0;
    }
    uVar4 = PoSetPowerButtonHoldState(uVar4);
  }
LAB_1c000286e:
  if (local_28[0] != 0) {
    if (local_28[0] == 1) {
      uVar4 = ExSetTimer(param_1[0x34],0xfffffffffeced300,0,0);
    }
    else if (local_28[0] == 2) {
      uVar4 = ExCancelTimer(param_1[0x34],0);
    }
  }
  if ((char)uVar3 == '\0') goto LAB_1c0002965;
  bVar10 = *local_20;
  uVar5 = (ulonglong)bVar10;
  if (bVar10 == 1) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar8 = 0x10;
LAB_1c0002918:
      bVar1 = local_20[1];
LAB_1c0002925:
      WPP_RECORDER_SF_LL(*param_1,uVar5,3,uVar8,&WPP_ab5e86bec157388494c90161187d07a9_Traceguids,
                         bVar10,bVar1);
    }
  }
  else if (bVar10 == 2) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar8 = 0x11;
      goto LAB_1c0002918;
    }
  }
  else if ((bVar10 == 4) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    bVar1 = local_20[1];
    uVar8 = 0x12;
    bVar10 = 4;
    goto LAB_1c0002925;
  }
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_2,0,5);
LAB_1c0002965:
  return CONCAT71((int7)((ulonglong)uVar4 >> 8),(char)uVar3);
}



===== Button_ReadDataFromCache @ 1c0002984 =====

undefined8
Button_ReadDataFromCache
          (longlong param_1,char *param_2,char *param_3,undefined4 *param_4,undefined4 *param_5)

{
  byte bVar1;
  uint uVar2;
  uint7 uVar3;
  char cVar4;
  undefined1 *puVar5;
  byte bVar6;
  
  *param_4 = 0;
  *param_5 = 0;
  if (*(char *)(param_1 + 0x198) == '\0') {
    if (*(char *)(param_1 + 0x199) != '\0') {
      *(undefined1 *)(param_1 + 0x199) = 0;
      goto LAB_1c00029bc;
    }
    uVar2 = *(uint *)(param_1 + 0xd0);
    if (uVar2 == *(uint *)(param_1 + 0xd4)) goto LAB_1c0002ae6;
    bVar1 = *(byte *)((ulonglong)uVar2 + 0xd8 + param_1);
    puVar5 = (undefined1 *)(ulonglong)bVar1;
    register0x00000020 = (BADSPACEBASE *)0x0;
    *(uint *)(param_1 + 0xd0) = uVar2 + 1 & 0x3f;
    cVar4 = puVar5[param_1 + 0x78];
    if (cVar4 == '\x01') {
      puVar5[param_1 + 0x78] = 0;
      cVar4 = '\0';
    }
    else if (cVar4 == '\0') {
      puVar5[param_1 + 0x78] = 1;
      cVar4 = '\x01';
    }
    if ((*(char *)(param_1 + 0x19b) == '\0') && (bVar1 == 0)) {
      if (cVar4 == '\0') {
LAB_1c0002a43:
        *param_5 = 2;
      }
      else if (cVar4 == '\x01') {
        *param_5 = 1;
      }
      else if (cVar4 == '\x02') goto LAB_1c0002a43;
    }
    if (cVar4 == '\x02') {
      puVar5[param_1 + 0x78] = 0;
      register0x00000020 = (BADSPACEBASE *)0x0;
      if (*(char *)(param_1 + 0x19f) == '\0') {
LAB_1c0002ae6:
        return (ulonglong)register0x00000020 & 0xffffffffffffff00;
      }
      *param_2 = *(char *)(param_1 + 0x19f);
      *param_3 = '\0';
      *(undefined1 *)(param_1 + 0x19f) = 0;
      goto LAB_1c00029c2;
    }
    if ((cVar4 == '\x01') && (bVar1 == 1)) goto LAB_1c0002ae6;
    register0x00000020 = (BADSPACEBASE *)0x0;
    if (((*(char *)(param_1 + 0x79) == '\0') || (bVar1 == 1)) ||
       ((puVar5[param_1 + 0x78] == '\0' && (*(char *)(param_1 + 0x79) != '\x02')))) {
LAB_1c0002ac6:
      bVar6 = 0;
      if (bVar1 == 0) {
        if (*(char *)(param_1 + 0x19c) != '\0') {
          if (cVar4 == '\0') {
            *param_4 = 2;
          }
          else if (cVar4 == '\x01') {
            *param_4 = 1;
            goto LAB_1c0002ae6;
          }
        }
        goto LAB_1c0002b07;
      }
LAB_1c0002b0c:
      if (bVar1 == 1) {
        cVar4 = -0x80;
LAB_1c0002b5b:
        register0x00000020 = (BADSPACEBASE *)CONCAT71((int7)((ulonglong)register0x00000020 >> 8),1);
      }
      else {
        uVar3 = (uint7)((ulonglong)register0x00000020 >> 8);
        if (bVar1 == 2) {
          cVar4 = (-(bVar6 != 0) & 0xa1U) + 1;
        }
        else {
          if (bVar1 != 3) {
            if (bVar1 == 4) {
              cVar4 = -0x7e;
              register0x00000020 = (BADSPACEBASE *)CONCAT71(uVar3,1);
            }
            else {
              cVar4 = '\0';
              register0x00000020 = (BADSPACEBASE *)((ulonglong)uVar3 << 8);
            }
            goto LAB_1c0002b72;
          }
          cVar4 = (-(bVar6 != 0) & 0x82U) + 2;
        }
        register0x00000020 = (BADSPACEBASE *)CONCAT71(uVar3,(bVar6 ^ 1) + 1);
      }
    }
    else {
      register0x00000020 = (BADSPACEBASE *)0x0;
      do {
        if ((((undefined1 *)register0x00000020 != (undefined1 *)0x1) &&
            ((undefined1 *)register0x00000020 != puVar5)) &&
           (*(char *)((longlong)register0x00000020 + param_1 + 0x78) == '\x01')) goto LAB_1c0002ac6;
        register0x00000020 = (BADSPACEBASE *)((longlong)register0x00000020 + 1);
      } while ((longlong)register0x00000020 < 5);
      bVar6 = 1;
LAB_1c0002b07:
      if (bVar1 != 0) goto LAB_1c0002b0c;
      if (bVar6 != 0) {
        cVar4 = 'a';
        goto LAB_1c0002b5b;
      }
      cVar4 = '\x01';
      register0x00000020 = (BADSPACEBASE *)CONCAT71((int7)((ulonglong)register0x00000020 >> 8),4);
    }
LAB_1c0002b72:
    *param_2 = (char)register0x00000020;
    *param_3 = cVar4;
    if (bVar6 != 0) {
      *(undefined1 *)(param_1 + 0x79) = 2;
      puVar5[param_1 + 0x78] = 2;
      register0x00000020 =
           (BADSPACEBASE *)CONCAT71((int7)((ulonglong)register0x00000020 >> 8),*param_2);
      *(char *)(param_1 + 0x19f) = *param_2;
    }
    if (bVar1 == 0) {
      if (*(char *)(param_1 + 0x19b) != '\0') {
        *(undefined1 *)(param_1 + 0x78) = 0;
        goto LAB_1c00029c2;
      }
      if ((*(char *)(param_1 + 0x19c) != '\0') || (*(char *)(param_1 + 0x78) != '\0'))
      goto LAB_1c00029c2;
    }
    else {
      if (puVar5[param_1 + 0x78] != '\0') goto LAB_1c00029c2;
      if (bVar1 == 1) {
        *(undefined1 *)(param_1 + 0x198) = 1;
        goto LAB_1c00029c2;
      }
    }
  }
  else {
    *(undefined1 *)(param_1 + 0x198) = 0;
LAB_1c00029bc:
    *param_2 = '\x01';
  }
  *param_3 = '\0';
LAB_1c00029c2:
  return CONCAT71((int7)((ulonglong)register0x00000020 >> 8),1);
}



===== Button_ReleaseButtonCacheLock @ 1c0002bec =====

void Button_ReleaseButtonCacheLock(longlong param_1,longlong param_2,undefined1 param_3)

{
  if (param_1 == 0) {
    KeReleaseSpinLock(param_2 + 200,param_3);
  }
  else {
    KeReleaseInterruptSpinLock(param_1,param_3);
  }
  return;
}



===== Button_RundownButtonQueue @ 1c0002c28 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Button_RundownButtonQueue(undefined8 *param_1)

{
  int iVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined1 local_res8 [8];
  undefined8 local_res10;
  
  local_res10 = 0;
  local_res8[0] = 0;
  while( true ) {
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x4f0))(WdfDriverGlobals,param_1[2],&local_res10);
    if (iVar1 < 0) {
      return;
    }
    uVar2 = Button_ReadButtonPress(param_1,local_res10);
    if (((char)uVar2 == '\0') &&
       (uVar4 = local_res10, iVar1 = (**(code **)(WdfFunctions_01015 + 0x8d8))(WdfDriverGlobals),
       iVar1 < 0)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*param_1,uVar4,3,0x17,&WPP_ab5e86bec157388494c90161187d07a9_Traceguids,
                          (char)iVar1);
      }
      (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,local_res10,iVar1);
    }
    lVar3 = Button_AcquireButtonCacheLock((longlong)param_1,local_res8);
    if (*(int *)(param_1 + 0x1a) == *(int *)((longlong)param_1 + 0xd4)) break;
    Button_ReleaseButtonCacheLock(lVar3,(longlong)param_1,local_res8[0]);
  }
  Button_ReleaseButtonCacheLock(lVar3,(longlong)param_1,local_res8[0]);
  return;
}



===== WPP_RECORDER_SF_ @ 1c0002d3c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                     undefined8 param_5)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,0);
  return;
}



===== WPP_RECORDER_SF_DDd @ 1c0002e14 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DDd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined8 param_7,undefined1 param_8
                        )

{
  undefined4 local_18 [4];
  
  local_18[0] = 5;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ab5e86bec157388494c90161187d07a9_Traceguids,param_4,&param_6,4,local_18,4,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,2,3,&WPP_ab5e86bec157388494c90161187d07a9_Traceguids,param_4,&param_6,4,
                  local_18,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_DcLLLLLL @ 1c0002f0c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DcLLLLLL(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined1 uStack0000000000000068;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ab5e86bec157388494c90161187d07a9_Traceguids,0x16,&uStack0000000000000030,4,
               &uStack0000000000000038,1,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,&uStack0000000000000060,4,
               &uStack0000000000000068,4,0);
  }
  WppAutoLogTrace(param_1,4,3,&WPP_ab5e86bec157388494c90161187d07a9_Traceguids,0x16,
                  &uStack0000000000000030,4,&uStack0000000000000038,1,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,&uStack0000000000000068,4,0);
  return;
}



===== WPP_RECORDER_SF_Dd @ 1c00030ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Dd(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,4,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,2,param_3,param_5,param_4,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_I @ 1c00031d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_I(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ab5e86bec157388494c90161187d07a9_Traceguids,param_4,&param_6,8,0);
  }
  WppAutoLogTrace(param_1,4,3,&WPP_ab5e86bec157388494c90161187d07a9_Traceguids,param_4,&param_6,8,0)
  ;
  return;
}



===== WPP_RECORDER_SF_L @ 1c0003284 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_L(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,4,0);
  }
  WppAutoLogTrace(param_1,4,param_3,param_5,param_4,&param_6,4,0);
  return;
}



===== WPP_RECORDER_SF_LL @ 1c000336c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_LL(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,4,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,4,param_3,param_5,param_4,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_Sd @ 1c0003488 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Sd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,wchar_t *param_6,undefined1 param_7)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar4 = -1;
  lVar3 = 10;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
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
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ab5e86bec157388494c90161187d07a9_Traceguids,param_4,pwVar2,lVar1,&param_7,4,0);
  }
  if (param_6 != (wchar_t *)0x0) {
    do {
      lVar4 = lVar4 + 1;
    } while (param_6[lVar4] != L'\0');
    lVar3 = lVar4 * 2 + 2;
  }
  if (param_6 == (wchar_t *)0x0) {
    param_6 = L"NULL";
  }
  WppAutoLogTrace(param_1,2,3,&WPP_ab5e86bec157388494c90161187d07a9_Traceguids,param_4,param_6,lVar3
                  ,&param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_dL @ 1c00035dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dL(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ab5e86bec157388494c90161187d07a9_Traceguids,0x1d,&uStack0000000000000030,4,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,2,3,&WPP_ab5e86bec157388494c90161187d07a9_Traceguids,0x1d,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,0);
  return;
}



===== WPP_RECORDER_SF_l @ 1c00036ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_l(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ab5e86bec157388494c90161187d07a9_Traceguids,param_4,&param_6,4,0);
  }
  WppAutoLogTrace(param_1,4,3,&WPP_ab5e86bec157388494c90161187d07a9_Traceguids,param_4,&param_6,4,0)
  ;
  return;
}



===== WPP_RECORDER_SF_qS @ 1c000375c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qS(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,wchar_t *param_7)

{
  longlong lVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  longlong lVar4;
  longlong lVar5;
  
  pwVar3 = param_7;
  lVar5 = -1;
  lVar4 = 10;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (param_7 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (param_7[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = param_7;
    if (param_7 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ab5e86bec157388494c90161187d07a9_Traceguids,param_4,&param_6,8,pwVar2,lVar1,0);
  }
  if (pwVar3 != (wchar_t *)0x0) {
    do {
      lVar5 = lVar5 + 1;
    } while (pwVar3[lVar5] != L'\0');
    lVar4 = lVar5 * 2 + 2;
  }
  if (pwVar3 == (wchar_t *)0x0) {
    pwVar3 = L"NULL";
  }
  WppAutoLogTrace(param_1,4,3,&WPP_ab5e86bec157388494c90161187d07a9_Traceguids,param_4,&param_6,8,
                  pwVar3,lVar4,0);
  return;
}



===== WPP_RECORDER_SF_qd @ 1c00038b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ab5e86bec157388494c90161187d07a9_Traceguids,0x4e,&uStack0000000000000030,8,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,4,3,&WPP_ab5e86bec157388494c90161187d07a9_Traceguids,0x4e,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,0);
  return;
}



===== WPP_RECORDER_SF_qdD @ 1c0003988 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qdD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ab5e86bec157388494c90161187d07a9_Traceguids,param_4,&param_6,8,&param_7,4,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,3,3,&WPP_ab5e86bec157388494c90161187d07a9_Traceguids,param_4,&param_6,8,
                  &param_7,4,&param_8,4,0);
  return;
}



===== WStringListToWString @ 1c0003a80 =====

void WStringListToWString(longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  
  uVar1 = 0;
  if (param_2 != 1) {
    do {
      if (*(short *)(param_1 + uVar1 * 2) == 0) {
        *(undefined2 *)(param_1 + uVar1 * 2) = 0x20;
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < param_2 - 1U);
  }
  return;
}



===== GPIO_HidGetString @ 1c0003aac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 GPIO_HidGetString(undefined8 param_1)

{
  ulonglong _Size;
  short sVar1;
  longlong lVar2;
  longlong lVar3;
  wchar_t *_Src;
  undefined8 uVar4;
  
  uVar4 = 0;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_1);
  sVar1 = (short)*(undefined4 *)(*(longlong *)(lVar2 + 0xb8) + 0x20);
  if (sVar1 == 0xe) {
    _Src = L"Microsoft";
  }
  else if (sVar1 == 0xf) {
    _Src = L"GPIO Button Driver";
  }
  else {
    if (sVar1 != 0x10) {
      return 0xc000000d;
    }
    _Src = L"1.0";
  }
  lVar3 = -1;
  do {
    lVar3 = lVar3 + 1;
  } while (_Src[lVar3] != L'\0');
  _Size = lVar3 * 2 + 2;
  if (*(uint *)(*(longlong *)(lVar2 + 0xb8) + 8) < _Size) {
    uVar4 = 0xc0000023;
  }
  else {
    memcpy(*(void **)(lVar2 + 0x70),_Src,_Size);
    *(ulonglong *)(lVar2 + 0x38) = _Size;
  }
  return uVar4;
}



===== HID_InternalDeviceControl @ 1c0003b70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void HID_InternalDeviceControl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               int param_5)

{
  int iVar1;
  undefined8 uVar2;
  undefined4 *local_18 [2];
  
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  if (param_5 == 0xb0003) {
    local_18[0] = (undefined4 *)0x0;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x860))(WdfDriverGlobals,param_2,local_18);
    if ((-1 < iVar1) &&
       (iVar1 = (**(code **)(WdfFunctions_01015 + 0x628))
                          (WdfDriverGlobals,local_18[0],0,&gHidDescriptor,9), -1 < iVar1)) {
      (**(code **)(WdfFunctions_01015 + 0x898))(WdfDriverGlobals,param_2,9);
    }
    goto LAB_1c0003d7b;
  }
  if (param_5 == 0xb0007) {
    local_18[0] = (undefined4 *)0x0;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x860))(WdfDriverGlobals,param_2,local_18);
    if (iVar1 < 0) goto LAB_1c0003d7b;
    uVar2 = 0x5f;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x628))
                      (WdfDriverGlobals,local_18[0],0,&gReportDescriptor,0x5f);
    if (iVar1 < 0) goto LAB_1c0003d7b;
  }
  else {
    if (param_5 == 0xb000b) {
      Button_HidReadReport(uVar2,param_2);
      return;
    }
    if (param_5 == 0xb0013) {
      uVar2 = GPIO_HidGetString(param_2);
      iVar1 = (int)uVar2;
      goto LAB_1c0003d7b;
    }
    if (param_5 != 0xb0027) {
      iVar1 = -0x3fffff45;
      goto LAB_1c0003d7b;
    }
    local_18[0] = (undefined4 *)0x0;
    uVar2 = 0x20;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,0x20,local_18,0);
    if (iVar1 < 0) goto LAB_1c0003d7b;
    *local_18[0] = 0x20;
    *(undefined2 *)(local_18[0] + 1) = 0;
    *(undefined2 *)((longlong)local_18[0] + 6) = 0;
    *(undefined2 *)(local_18[0] + 2) = 0;
  }
  (**(code **)(WdfFunctions_01015 + 0x898))(WdfDriverGlobals,param_2,uVar2);
  iVar1 = 0;
LAB_1c0003d7b:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar1);
  return;
}



===== Indicator_EvtDeviceD0Entry @ 1c0003dc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 Indicator_EvtDeviceD0Entry(undefined8 param_1,undefined1 param_2)

{
  longlong *plVar1;
  char *pcVar2;
  undefined4 *puVar3;
  undefined8 uVar4;
  undefined *puVar5;
  undefined8 in_stack_ffffffffffffffa8;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  uStack_20 = 0;
  local_28 = 0;
  local_24 = 0;
  puVar5 = PTR__WDF_INDICATOR_CONTEXT_TYPE_INFO_1c0009018;
  puVar3 = (undefined4 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  plVar1 = (longlong *)(puVar3 + 0xc);
  pcVar2 = (char *)(puVar3 + 0xe);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_LLqd
              (*(undefined8 *)(puVar3 + 4),param_1,puVar5,0x22,in_stack_ffffffffffffffa8,param_2,
               (char)*puVar3,(char)*plVar1,*pcVar2);
  }
  if (*plVar1 != 0) {
    uVar4 = *(undefined8 *)(puVar3 + 0x16);
    (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals);
    if (*pcVar2 == '\0') {
      local_28 = 1;
      uStack_20 = (undefined4)*plVar1;
      uStack_1c = (undefined4)((ulonglong)*plVar1 >> 0x20);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_L(*(undefined8 *)(puVar3 + 4),uVar4,4,0x23,
                          &WPP_c6cd92e4efb638f901d990db7ac3a788_Traceguids,(char)*puVar3);
      }
      IoReportInterruptActive(&local_28);
      *pcVar2 = '\x01';
    }
    (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(puVar3 + 0x16));
  }
  return 0;
}



===== Indicator_EvtDeviceD0Exit @ 1c0003f10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 Indicator_EvtDeviceD0Exit(undefined8 param_1,undefined1 param_2)

{
  longlong *plVar1;
  char *pcVar2;
  undefined4 *puVar3;
  undefined8 uVar4;
  undefined *puVar5;
  undefined8 in_stack_ffffffffffffffa8;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  uStack_20 = 0;
  local_28 = 0;
  local_24 = 0;
  puVar5 = PTR__WDF_INDICATOR_CONTEXT_TYPE_INFO_1c0009018;
  puVar3 = (undefined4 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  plVar1 = (longlong *)(puVar3 + 0xc);
  pcVar2 = (char *)(puVar3 + 0xe);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_LLqd
              (*(undefined8 *)(puVar3 + 4),param_1,puVar5,0x24,in_stack_ffffffffffffffa8,param_2,
               (char)*puVar3,(char)*plVar1,*pcVar2);
  }
  if (*plVar1 != 0) {
    uVar4 = *(undefined8 *)(puVar3 + 0x16);
    (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals);
    if (*pcVar2 != '\0') {
      local_28 = 1;
      uStack_20 = (undefined4)*plVar1;
      uStack_1c = (undefined4)((ulonglong)*plVar1 >> 0x20);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_L(*(undefined8 *)(puVar3 + 4),uVar4,4,0x25,
                          &WPP_c6cd92e4efb638f901d990db7ac3a788_Traceguids,(char)*puVar3);
      }
      IoReportInterruptInactive(&local_28);
      *pcVar2 = '\0';
    }
    (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(puVar3 + 0x16));
  }
  return 0;
}



===== Indicator_EvtIoRead @ 1c0004060 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Indicator_EvtIoRead(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined1 *puVar4;
  undefined8 local_res18 [2];
  
  local_res18[0] = 0;
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar2,PTR__WDF_INDICATOR_CONTEXT_TYPE_INFO_1c0009018);
  if (param_3 == 1) {
    uVar2 = param_2;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x860))(WdfDriverGlobals,param_2,local_res18);
    if (-1 < iVar1) {
      puVar4 = (undefined1 *)
               (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,local_res18[0],0);
      *puVar4 = *(undefined1 *)(lVar3 + 0x48);
      (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_2,0,1);
      return;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(lVar3 + 0x10),uVar2,4,0x1a,
                        &WPP_c6cd92e4efb638f901d990db7ac3a788_Traceguids,(char)iVar1);
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_Dd(*(undefined8 *)(lVar3 + 0x10),uVar2,4,0x19,
                         &WPP_c6cd92e4efb638f901d990db7ac3a788_Traceguids,(char)param_3,6);
    }
    iVar1 = -0x3ffffdfa;
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar1);
  return;
}



===== Indicator_EvtIoWrite @ 1c00041f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Indicator_EvtIoWrite(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  undefined8 uVar1;
  int *piVar2;
  undefined2 uVar3;
  undefined1 uVar4;
  
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  piVar2 = (int *)(**(code **)(WdfFunctions_01015 + 0x650))
                            (WdfDriverGlobals,uVar1,PTR__WDF_INDICATOR_CONTEXT_TYPE_INFO_1c0009018);
  if (param_3 != 1) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_Dd(*(undefined8 *)(piVar2 + 4),uVar1,4,0x16,
                         &WPP_c6cd92e4efb638f901d990db7ac3a788_Traceguids,(char)param_3,6);
    }
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc0000206);
    return;
  }
  if (*piVar2 == 1) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0004316;
    uVar4 = (undefined1)piVar2[0x12];
    uVar3 = 0x17;
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0004316;
    uVar4 = (undefined1)piVar2[0x12];
    uVar3 = 0x18;
  }
  WPP_RECORDER_SF_LL(*(undefined8 *)(piVar2 + 4),uVar1,4,uVar3,
                     &WPP_c6cd92e4efb638f901d990db7ac3a788_Traceguids,(char)*piVar2,uVar4);
LAB_1c0004316:
  LOCK();
  piVar2[7] = piVar2[7] + 1;
  UNLOCK();
  piVar2[0x12] = (uint)(piVar2[0x12] == 0);
  Indicator_UpdateRegistryValue(piVar2);
  (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_2,0,1);
  return;
}



===== Indicator_InterruptDpc @ 1c0004370 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong Indicator_InterruptDpc(void)

{
  uint uVar1;
  ulonglong uVar2;
  longlong in_R9;
  
  uVar2 = 0;
  LOCK();
  uVar1 = *(uint *)(in_R9 + 0x50);
  if (uVar1 == 0) {
    *(uint *)(in_R9 + 0x50) = 1;
  }
  else {
    uVar2 = (ulonglong)uVar1;
  }
  UNLOCK();
  if (uVar1 == 0) {
    uVar2 = (**(code **)(WdfFunctions_01015 + 0xbe0))
                      (WdfDriverGlobals,*(undefined8 *)(in_R9 + 0x20));
  }
  return uVar2;
}



===== Indicator_Isr @ 1c00043b0 =====

undefined8 Indicator_Isr(undefined8 param_1,int *param_2)

{
  undefined8 uVar1;
  undefined2 uVar2;
  
  if (*param_2 == 1) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0004412;
    uVar2 = 0xe;
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0004412;
    uVar2 = 0xf;
  }
  WPP_RECORDER_SF_LL(*(undefined8 *)(param_2 + 4),param_2,4,uVar2,
                     &WPP_c6cd92e4efb638f901d990db7ac3a788_Traceguids,(char)*param_2,
                     (char)param_2[0x12]);
LAB_1c0004412:
  LOCK();
  param_2[6] = param_2[6] + 1;
  UNLOCK();
  LOCK();
  param_2[7] = param_2[7] + 1;
  UNLOCK();
  uVar1 = KeInsertQueueDpc(*(longlong *)(param_2 + 2) + 200,
                           *(undefined8 *)(*(longlong *)(param_2 + 2) + 0x20),param_2);
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
}



===== Indicator_PowerSettingCallback @ 1c0004450 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
Indicator_PowerSettingCallback(longlong *param_1,int *param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined4 local_18;
  undefined4 local_14;
  longlong local_10;
  
  uVar3 = 0;
  local_14 = 0;
  if ((((param_2 == (int *)0x0) || (param_3 != 4)) || (param_4 == (undefined4 *)0x0)) ||
     ((*param_1 != 0x470feaa4e1233993 || (param_1[1] != 0x71fbb6c151a3e79d)))) {
    uVar3 = 0xc000000d;
  }
  else {
    local_10 = *(longlong *)(param_4 + 0xc);
    if (local_10 != 0) {
      iVar1 = *param_2;
      uVar2 = *(undefined8 *)(param_4 + 0x16);
      local_18 = 1;
      (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals);
      if (iVar1 == 0) {
        if (*(char *)(param_4 + 0xe) == '\0') {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_L(*(undefined8 *)(param_4 + 4),uVar2,4,0xb,
                              &WPP_c6cd92e4efb638f901d990db7ac3a788_Traceguids,(char)*param_4);
          }
          IoReportInterruptActive(&local_18);
          *(undefined1 *)(param_4 + 0xe) = 1;
        }
      }
      else if (*(char *)(param_4 + 0xe) != '\0') {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_L(*(undefined8 *)(param_4 + 4),uVar2,4,10,
                            &WPP_c6cd92e4efb638f901d990db7ac3a788_Traceguids,(char)*param_4);
        }
        IoReportInterruptInactive(&local_18);
        *(undefined1 *)(param_4 + 0xe) = 0;
      }
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(param_4 + 0x16));
    }
  }
  return uVar3;
}



===== Indicator_ReleaseUpdateLock @ 1c00045c4 =====

undefined4 Indicator_ReleaseUpdateLock(longlong param_1)

{
  undefined4 uVar1;
  
  LOCK();
  uVar1 = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(param_1 + 0x50) = 0;
  UNLOCK();
  return uVar1;
}



===== Indicator_TryAcquireUpdateLock @ 1c00045d4 =====

undefined8 Indicator_TryAcquireUpdateLock(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  
  uVar2 = 0;
  LOCK();
  uVar1 = *(uint *)(param_1 + 0x50);
  if (uVar1 == 0) {
    *(uint *)(param_1 + 0x50) = 1;
  }
  else {
    uVar2 = (ulonglong)uVar1;
  }
  UNLOCK();
  return CONCAT71((int7)(uVar2 >> 8),uVar1 == 0);
}



===== McGenEventWrite_EtwWriteTransfer @ 1c00045ec =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_1c0009058;
  uVar2 = 0;
  if (DAT_1c0009058 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_1c0009058;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(Microsoft_Windows_GPIOButtons_Context,param_2,&Microsoft_Windows_GPIOButtons,0,2,
                   param_5);
  return;
}



===== McTemplateK0q_EtwWriteTransfer @ 1c0004654 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0q_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_68 [32];
  undefined8 local_38 [2];
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_res20[0] = (undefined4)param_4;
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_28 = local_res20;
  local_1c = 0;
  local_20 = 4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,param_4,local_38);
  return;
}



===== WPP_RECORDER_SF_LD @ 1c00046ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_LD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c6cd92e4efb638f901d990db7ac3a788_Traceguids,0x15,&uStack0000000000000030,4,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,2,4,&WPP_c6cd92e4efb638f901d990db7ac3a788_Traceguids,0x15,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,0);
  return;
}



===== WPP_RECORDER_SF_LLqd @ 1c000477c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_LLqd
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c6cd92e4efb638f901d990db7ac3a788_Traceguids,param_4,&param_6,4,&param_7,4,
               &param_8,8,&param_9,4,0);
  }
  WppAutoLogTrace(param_1,4,4,&WPP_c6cd92e4efb638f901d990db7ac3a788_Traceguids,param_4,&param_6,4,
                  &param_7,4,&param_8,8,&param_9,4,0);
  return;
}



===== FxStubDriverUnloadCommon @ 1c0004890 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  void **ppvVar1;
  void **ppvVar2;
  
  ppvVar1 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c0009228 != &__KMDF_CLASS_BIND_START) {
    ppvVar2 = (void **)(PTR___KMDF_CLASS_BIND_START_1c0009228 + 0x50);
    while( true ) {
      for (; (ppvVar1 + 1 <= ppvVar2 && (*ppvVar1 == (void *)0x0)); ppvVar1 = ppvVar1 + 1) {
      }
      if (ppvVar1 < ppvVar2) break;
      ppvVar1 = ppvVar2;
LAB_1c00048e9:
      if (ppvVar1 == (void **)0x0) goto LAB_1c000493f;
      if (ppvVar2 <= ppvVar1) goto LAB_1c0004957;
      if (ppvVar1[8] == (code *)0x0) {
        WdfVersionUnbindClass(&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      else {
        (*ppvVar1[8])(WdfVersionUnbindClass_exref,&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      ppvVar1 = (void **)((longlong)ppvVar1 + (ulonglong)*(uint *)ppvVar1);
    }
    if ((ppvVar1 + 10 <= ppvVar2) && (*(uint *)ppvVar1 == 0x50)) goto LAB_1c00048e9;
LAB_1c000493f:
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
LAB_1c0004957:
  WdfVersionUnbind(&DAT_1c00094c0,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== entry @ 1c0004990 =====

void entry(_WDF_BIND_INFO *param_1,undefined8 param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 1c00049c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FxDriverEntryWorker(_WDF_BIND_INFO *param_1,undefined8 param_2)

{
  int iVar1;
  int iVar2;
  _WDF_BIND_INFO *p_Var3;
  undefined *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  
  if (param_1 == (_WDF_BIND_INFO *)0x0) {
    iVar1 = DriverEntry(0,param_2);
  }
  else {
    _DAT_1c00094c0 = 0x2080000;
    _DAT_1c00094c8 = &DAT_1c00092a0;
    RtlCopyUnicodeString(&DAT_1c00094c0);
    p_Var3 = param_1;
    iVar1 = WdfVersionBind(param_1,&DAT_1c00094c0,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < iVar1) {
      iVar1 = FxStubBindClasses(p_Var3);
      if ((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) {
        iVar1 = DriverEntry(param_1,param_2);
        if (-1 < iVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_1c00094a8 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",iVar1,&DAT_1c00094c0);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c0009228 != &__KMDF_CLASS_BIND_START) {
          local_1c = 0;
          uStack_18 = 0;
          local_28 = &GUID_WDF_LOADER_INTERFACE_DRIVER_ENTRY_FAILURE;
          local_14 = 0;
          local_20 = 0x18;
          iVar2 = WdfLdrQueryInterface(&local_28);
          if (-1 < iVar2) {
            (*(code *)CONCAT44(local_14,uStack_18))(&WdfBindInfo,WdfDriverGlobals);
          }
        }
      }
      FxStubDriverUnloadCommon();
    }
  }
  return iVar1;
}



===== FxStubDriverUnload @ 1c0004b50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_1c00094a8 != (code *)0x0) && (DAT_1c00094a8 != FxStubDriverUnload)) {
    (*DAT_1c00094a8)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 1c0004b84 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c0004ba9) */
/* long __cdecl FxStubBindClasses(struct _WDF_BIND_INFO * __ptr64) */

long __cdecl FxStubBindClasses(_WDF_BIND_INFO *param_1)

{
  int iVar1;
  void **ppvVar2;
  
  iVar1 = 0;
  ppvVar2 = &__KMDF_CLASS_BIND_END;
  while( true ) {
    for (; (ppvVar2 + 1 < (void **)((longlong)&__KMDF_CLASS_BIND_END + 1) &&
           (*ppvVar2 == (void *)0x0)); ppvVar2 = ppvVar2 + 1) {
    }
    if ((void **)0x1c000921f < ppvVar2) break;
    if (((&__KMDF_CLASS_BIND_END < ppvVar2 + 10) || (*(uint *)ppvVar2 != 0x50)) ||
       (ppvVar2 == (void **)0x0)) {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    PTR___KMDF_CLASS_BIND_START_1c0009228 = (undefined *)ppvVar2;
    if (ppvVar2[7] == (code *)0x0) {
      iVar1 = WdfVersionBindClass(&WdfBindInfo,WdfDriverGlobals,ppvVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: VersionBindClass WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,ppvVar2,ppvVar2[1],iVar1);
        return iVar1;
      }
    }
    else {
      iVar1 = (*ppvVar2[7])(WdfVersionBindClass_exref,&WdfBindInfo,WdfDriverGlobals,ppvVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: ClientBindClass %p, WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,ppvVar2[7],ppvVar2,ppvVar2[1],iVar1);
        return iVar1;
      }
    }
    ppvVar2 = (void **)((ulonglong)*(uint *)ppvVar2 + (longlong)ppvVar2);
  }
  return iVar1;
}



===== FxStubInitTypes @ 1c0004d0c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c0004d29) */
/* long __cdecl FxStubInitTypes(void) */

long __cdecl FxStubInitTypes(void)

{
  void *pvVar1;
  void **ppvVar2;
  
  ppvVar2 = &__KMDF_TYPE_INIT_END;
  while( true ) {
    for (; (ppvVar2 + 1 < (void **)((longlong)&__KMDF_TYPE_INIT_END + 1) &&
           (*ppvVar2 == (void *)0x0)); ppvVar2 = ppvVar2 + 1) {
    }
    if ((void **)0x1c000923f < ppvVar2) break;
    if (((&__KMDF_TYPE_INIT_END < ppvVar2 + 5) || (*(uint *)ppvVar2 != 0x28)) ||
       (ppvVar2 == (void **)0x0)) {
      DbgPrintEx(0x4d,0,"FxGetNextObjectContextTypeInfo failed\n");
      return -0x3fffff85;
    }
    if (ppvVar2[4] != (code *)0x0) {
      pvVar1 = (void *)(*ppvVar2[4])();
      ppvVar2[3] = pvVar1;
    }
    ppvVar2 = (void **)((ulonglong)*(uint *)ppvVar2 + (longlong)ppvVar2);
  }
  return 0;
}



===== DestroyEventEntry @ 1c0004dd4 =====

void DestroyEventEntry(longlong param_1)

{
  if (param_1 != 0) {
    ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x10),0);
  }
  return;
}



===== EnableFlushTimer @ 1c0004dfc =====

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



===== FinishHash @ 1c0004e58 =====

void FinishHash(int *param_1)

{
  *param_1 = ((uint)(*param_1 * 9) >> 0xb ^ *param_1 * 9) * 0x8001;
  return;
}



===== FlushLookUpTableBucket @ 1c0004e74 =====

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



===== RunningHash @ 1c0004f88 =====

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



===== TlgAggregateInternalFlushTimerCallbackKernelMode @ 1c0004fc0 =====

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



===== __GSHandlerCheck @ 1c0005008 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c000502c =====

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



===== __security_check_cookie @ 1c00050a0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c00050e0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0005110 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0005110. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0005140 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c00051c0 =====

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



===== memset @ 1c00054c0 =====

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



===== __memset_repmovs @ 1c0005600 =====

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



===== __memset_query @ 1c0005680 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0005700 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0005840 =====

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



===== __memset_spec_plain @ 1c00058c0 =====

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



===== DriverCleanup @ 1c000c010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DriverCleanup(undefined8 param_1)

{
  longlong *plVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong lVar5;
  undefined *puVar6;
  
  McGenEventUnregister_EtwUnregister();
  uVar2 = DAT_1c00090b8;
  if (DAT_1c00090c0 == TlgAggregateInternalRegisteredProviderEtwCallback) {
    lVar5 = 0;
    ExAcquirePushLockExclusiveEx(&DAT_1c00094b0,0);
    lVar3 = DAT_1c00094b8;
    plVar4 = &DAT_1c00094b8;
    while (lVar3 != 0) {
      plVar1 = (longlong *)(lVar3 + 0x160);
      if (*(undefined4 **)(lVar3 + 0x158) == &DAT_1c0009098) {
        *plVar4 = *plVar1;
        LookUpTableFlushComplete(lVar3);
        uVar2 = DAT_1c0009130;
        lVar5 = lVar3;
        if (DAT_1c00094b8 == 0) {
          DAT_1c0009130 = 0;
          DAT_1c0009110 = 0;
          EtwUnregister(uVar2);
        }
        break;
      }
      plVar4 = plVar1;
      lVar3 = *plVar1;
    }
    ExReleasePushLockExclusiveEx(&DAT_1c00094b0,0);
    if (lVar5 != 0) {
      CancelTimerCallbacksAndDeleteTimer(lVar5);
    }
    uVar2 = DAT_1c00090b8;
    DAT_1c00090b8 = 0;
    DAT_1c0009098 = 0;
    EtwUnregister(uVar2);
    DAT_1c00090c0 = (code *)0x0;
    DestroyAggregateSession(lVar5);
  }
  else {
    DAT_1c00090b8 = 0;
    DAT_1c0009098 = 0;
    EtwUnregister(uVar2);
  }
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,param_1);
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    puVar6 = WPP_GLOBAL_Control;
    if (WPPTraceSuite == 4) {
      for (; puVar6 != (undefined *)0x0; puVar6 = *(undefined **)(puVar6 + 0x10)) {
        if (*(longlong *)(puVar6 + 0x38) != 0) {
          (*pfnEtwUnregister)();
          *(undefined8 *)(puVar6 + 0x38) = 0;
        }
      }
    }
    else if (WPPTraceSuite == 2) {
      IoWMIRegistrationControl(WPP_GLOBAL_Control,0x80000002);
    }
    WppAutoLogStop(WPP_GLOBAL_Control,uVar2);
    WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
    WPP_RECORDER_INITIALIZED = (undefined *)&WPP_RECORDER_INITIALIZED;
  }
  return;
}



===== GPIO_EvtDeviceAdd @ 1c000c200 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GPIO_EvtDeviceAdd(undefined8 param_1,undefined8 *******param_2)

{
  int iVar1;
  wchar_t *pwVar2;
  ulonglong uVar3;
  wchar_t *pwVar4;
  undefined8 *******pppppppuVar5;
  undefined2 uVar6;
  longlong local_res18;
  longlong local_res20;
  
  local_res18 = 0;
  local_res20 = 0;
  pppppppuVar5 = param_2;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x3f8))(WdfDriverGlobals,param_2,0xf,1,0,&local_res20);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000c426;
    uVar6 = 10;
  }
  else {
    pwVar4 = (wchar_t *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,local_res20,0);
    iVar1 = _wcsicmp(pwVar4,L"ROOT");
    if (iVar1 == 0) {
      pppppppuVar5 = param_2;
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x3f8))(WdfDriverGlobals,param_2,1,1,0,&local_res18)
      ;
      if (-1 < iVar1) goto LAB_1c000c364;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000c426;
      uVar6 = 0xb;
    }
    else {
      pppppppuVar5 = param_2;
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x3f8))(WdfDriverGlobals,param_2,2,1,0,&local_res18)
      ;
      if (-1 < iVar1) {
LAB_1c000c364:
        pwVar4 = (wchar_t *)
                 (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,local_res18,0);
        pwVar2 = wcsstr(pwVar4,L"PNP0C40");
        if (pwVar2 == (wchar_t *)0x0) {
          pwVar2 = wcsstr(pwVar4,L"PNP0C60");
          if (pwVar2 == (wchar_t *)0x0) {
            pwVar4 = wcsstr(pwVar4,L"PNP0C70");
            if (pwVar4 == (wchar_t *)0x0) {
              iVar1 = -0x3fffffff;
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
              }
              goto LAB_1c000c426;
            }
            iVar1 = 2;
          }
          else {
            iVar1 = 1;
          }
          iVar1 = Indicator_EvtDeviceAdd(param_2,iVar1);
        }
        else {
          uVar3 = Button_EvtDeviceAdd(param_2);
          iVar1 = (int)uVar3;
        }
        goto LAB_1c000c426;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000c426;
      uVar6 = 0xc;
    }
  }
  WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pppppppuVar5,2,uVar6,
                    &WPP_510fbab7d28b3ad3e7de6c0b69c24f78_Traceguids,(char)iVar1);
LAB_1c000c426:
  if (local_res20 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  if (local_res18 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  return iVar1;
}



===== WppInitKm @ 1c000c488 =====

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



===== WppLoadTracingSupport @ 1c000c564 =====

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



===== WppTraceCallback @ 1c000c6b0 =====

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
        memcpy((ushort *)((ulonglong)uVar11 + (longlong)param_4) + 1,*(void **)(puVar3 + 4),
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



===== Button_CheckExclusivity @ 1c000c938 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Button_CheckExclusivity(undefined8 *param_1)

{
  int iVar1;
  wchar_t *pwVar2;
  undefined8 *puVar3;
  undefined2 uVar4;
  undefined1 auStackY_148 [32];
  undefined8 uVar5;
  int local_108 [2];
  longlong local_100;
  undefined8 local_f8;
  wchar_t *local_f0;
  undefined8 local_e8;
  wchar_t *local_e0;
  wchar_t local_d8 [32];
  wchar_t local_98 [64];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_148;
  puVar3 = &local_f8;
  local_100 = 0;
  local_108[0] = 0;
  builtin_wcsncpy(local_98,L"\\Registry\\Machine\\System\\CurrentControlSet\\Contr",0x30);
  builtin_wcsncpy(local_98 + 0x30,L"ol\\Windows",0xb);
  local_f0 = local_98;
  builtin_wcsncpy(local_d8,L"ButtonDe",8);
  local_e0 = local_d8;
  builtin_wcsncpy(local_d8 + 0x10,L"usiveAcc",8);
  local_f8 = 0x760074;
  *(undefined1 *)((longlong)param_1 + 0x19d) = 1;
  uVar5 = 0;
  builtin_wcsncpy(local_d8 + 8,L"viceExcl",8);
  local_e8 = 0x380036;
  builtin_wcsncpy(local_d8 + 0x18,L"ess",4);
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x728))(WdfDriverGlobals,0,puVar3,0x2000000);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000caeb;
    uVar4 = 0x19;
    pwVar2 = L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Windows";
  }
  else {
    puVar3 = &local_e8;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))(WdfDriverGlobals,local_100,puVar3,local_108);
    if (-1 < iVar1) {
      *(bool *)((longlong)param_1 + 0x19d) = local_108[0] != 0;
      goto LAB_1c000caeb;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000caeb;
    uVar4 = 0x1a;
    pwVar2 = L"ButtonDeviceExclusiveAccess";
  }
  WPP_RECORDER_SF_Sd(*param_1,&WPP_RECORDER_INITIALIZED,puVar3,uVar4,uVar5,pwVar2,(char)iVar1);
LAB_1c000caeb:
  if (local_100 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals);
  }
  return;
}



===== Button_CheckPowerButtonEdges @ 1c000cb34 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Button_CheckPowerButtonEdges(undefined8 param_1)

{
  byte ****ppppbVar1;
  ushort uVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  byte bVar6;
  byte ****ppppbVar7;
  uint *puVar8;
  undefined2 uVar9;
  bool bVar10;
  uint local_res10 [2];
  byte ****local_res18 [2];
  undefined *in_stack_ffffffffffffffc8;
  
  puVar4 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_BUTTON_CONTEXT_TYPE_INFO_1c0009040);
  local_res10[0] = 0;
  local_res18[0] = (byte ****)0x0;
  puVar5 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_BUTTON_CONTEXT_TYPE_INFO_1c0009040);
  puVar8 = local_res10;
  ppppbVar7 = (byte ****)local_res18;
  bVar10 = *(char *)((longlong)puVar5 + 0x19c) == '\0';
  iVar3 = Button_EvaluateCRSMethod(param_1,(longlong *)ppppbVar7,puVar8);
  ppppbVar1 = local_res18[0];
  if (iVar3 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000cc9c;
    uVar9 = 0x2b;
  }
  else {
    iVar3 = 0;
    bVar6 = *(byte *)local_res18[0];
    puVar8 = (uint *)0xc000008b;
    ppppbVar7 = local_res18[0];
    if (local_res10[0] < 0x18) {
LAB_1c000cc6b:
      puVar8 = (uint *)0xc014000f;
    }
    else {
      while( true ) {
        if ((char)bVar6 < '\0') {
          uVar2 = *(short *)((longlong)ppppbVar7 + 1) + 3;
        }
        else {
          uVar2 = (bVar6 & 7) + 1;
          bVar6 = bVar6 & 0x78;
        }
        if (bVar6 == 0x78) break;
        if ((bVar6 == 0x8c) && (*(byte *)((longlong)ppppbVar7 + 4) == 0)) {
          if (iVar3 == 0) {
            uVar2 = *(ushort *)((longlong)ppppbVar7 + 7) & 6;
            if (uVar2 == 4) {
              bVar10 = false;
              goto LAB_1c000cc9c;
            }
            if ((uVar2 != 2) && (uVar2 != 0)) goto LAB_1c000cc6b;
            bVar10 = true;
            goto LAB_1c000cc9c;
          }
          iVar3 = iVar3 + 1;
        }
        bVar6 = *(byte *)((longlong)ppppbVar7 + (ulonglong)uVar2);
        ppppbVar7 = (byte ****)((longlong)ppppbVar7 + (ulonglong)uVar2);
      }
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000cc9c;
    iVar3 = (int)puVar8;
    uVar9 = 0x2c;
  }
  puVar8 = (uint *)0x3;
  in_stack_ffffffffffffffc8 = &WPP_ab5e86bec157388494c90161187d07a9_Traceguids;
  WPP_RECORDER_SF_d(*puVar5,ppppbVar7,3,uVar9,&WPP_ab5e86bec157388494c90161187d07a9_Traceguids,
                    (char)iVar3);
LAB_1c000cc9c:
  if (ppppbVar1 != (byte ****)0x0) {
    ppppbVar7 = (byte ****)0x6e744247;
    ExFreePoolWithTag(ppppbVar1);
  }
  *(bool *)((longlong)puVar4 + 0x19b) = bVar10;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_l(*puVar4,ppppbVar7,puVar8,0x15,in_stack_ffffffffffffffc8,bVar10);
  }
  return;
}



===== Button_CheckPowerButtonPressAndHoldSupport @ 1c000ccf4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong Button_CheckPowerButtonPressAndHoldSupport(ulonglong param_1)

{
  bool bVar1;
  int ****ppppiVar2;
  undefined1 uVar3;
  uint uVar4;
  undefined8 *puVar5;
  ulonglong uVar6;
  uint uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  longlong lVar10;
  int ****ppppiVar11;
  undefined2 uVar12;
  int ****ppppiVar13;
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  undefined4 *in_stack_ffffffffffffff88;
  int ****local_68;
  longlong local_60;
  longlong local_58;
  int ****local_50 [2];
  
  local_res20[0] = 0;
  ppppiVar13 = (int ****)0x0;
  local_60 = 0;
  local_68 = (int ****)0x0;
  uVar8 = param_1;
  puVar5 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_BUTTON_CONTEXT_TYPE_INFO_1c0009040);
  ppppiVar11 = (int ****)local_50;
  local_res18[0] = 0;
  local_58 = 0;
  local_50[0] = (int ****)0x0;
  bVar1 = false;
  uVar6 = Button_PrepareInputParametersForDsmMethod(0,uVar8,ppppiVar11);
  ppppiVar2 = local_50[0];
  uVar9 = uVar6 & 0xffffffff;
  lVar10 = 0;
  if (-1 < (int)uVar6) {
    uVar8 = (ulonglong)*(uint *)((longlong)local_50[0] + 4);
    in_stack_ffffffffffffff88 = local_res18;
    ppppiVar11 = local_50[0];
    uVar4 = Button_EvaluateAcpiMethod
                      (param_1,*(uint *)((longlong)local_50[0] + 4),(int *)local_50[0],&local_58,
                       in_stack_ffffffffffffff88);
    uVar9 = 0;
    lVar10 = local_58;
    if ((int)uVar4 < 0) {
      uVar7 = 0;
      if (uVar4 != 0xc0000034) {
        uVar7 = uVar4;
      }
      uVar9 = 0;
      if (uVar7 != 0xc0000010) {
        uVar9 = (ulonglong)uVar7;
      }
    }
    else if ((((local_58 == 0) || (*(int *)(local_58 + 8) != 1)) ||
             (*(short *)(local_58 + 0xc) != 2)) || (*(short *)(local_58 + 0xe) == 0)) {
      uVar9 = 0xc0000001;
    }
    else if ((*(short *)(local_58 + 0xe) != 0) && ((*(byte *)(local_58 + 0x10) & 2) != 0)) {
      bVar1 = true;
    }
  }
  if (ppppiVar2 != (int ****)0x0) {
    uVar8 = 0x6e744247;
    ExFreePoolWithTag(ppppiVar2);
  }
  if (lVar10 != 0) {
    uVar8 = 0x6e744247;
    ExFreePoolWithTag(lVar10);
  }
  if ((int)uVar9 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      in_stack_ffffffffffffff88 = (undefined4 *)&WPP_ab5e86bec157388494c90161187d07a9_Traceguids;
      ppppiVar11 = (int ****)0x3;
      WPP_RECORDER_SF_d(*puVar5,uVar8,3,0x40,&WPP_ab5e86bec157388494c90161187d07a9_Traceguids,
                        (char)uVar9);
    }
  }
  else if (bVar1) {
    ppppiVar11 = (int ****)&local_68;
    uVar6 = Button_PrepareInputParametersForDsmMethod(1,uVar8,ppppiVar11);
    ppppiVar13 = local_68;
    uVar9 = uVar6 & 0xffffffff;
    if (-1 < (int)uVar6) {
      in_stack_ffffffffffffff88 = local_res20;
      uVar8 = (ulonglong)*(uint *)((longlong)local_68 + 4);
      ppppiVar11 = local_68;
      uVar4 = Button_EvaluateAcpiMethod
                        (param_1,*(uint *)((longlong)local_68 + 4),(int *)local_68,&local_60,
                         in_stack_ffffffffffffff88);
      lVar10 = local_60;
      uVar9 = (ulonglong)uVar4;
      if ((int)uVar4 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          in_stack_ffffffffffffff88 = (undefined4 *)&WPP_ab5e86bec157388494c90161187d07a9_Traceguids
          ;
          ppppiVar11 = (int ****)0x3;
          WPP_RECORDER_SF_d(*puVar5,uVar8,3,0x43,&WPP_ab5e86bec157388494c90161187d07a9_Traceguids,
                            (char)uVar4);
        }
        lVar10 = local_60;
      }
      else {
        if ((local_60 == 0) || (*(int *)(local_60 + 8) != 1)) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar12 = 0x44;
LAB_1c000cfad:
            ppppiVar11 = (int ****)0x3;
            in_stack_ffffffffffffff88 =
                 (undefined4 *)&WPP_ab5e86bec157388494c90161187d07a9_Traceguids;
            uVar8 = CONCAT71((int7)(uVar8 >> 8),2);
            WPP_RECORDER_SF_(*puVar5,2,3,uVar12,&WPP_ab5e86bec157388494c90161187d07a9_Traceguids);
          }
        }
        else {
          if (*(short *)(local_60 + 0xc) == 0) {
            if (((byte)*(undefined4 *)(local_60 + 0x10) & 7) == 7) {
              uVar3 = 1;
              goto LAB_1c000cf1d;
            }
            goto LAB_1c000cf1a;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar12 = 0x45;
            goto LAB_1c000cfad;
          }
        }
        uVar9 = 0xc0000001;
      }
LAB_1c000cf1a:
      uVar3 = 0;
      goto LAB_1c000cf1d;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      in_stack_ffffffffffffff88 = (undefined4 *)&WPP_ab5e86bec157388494c90161187d07a9_Traceguids;
      ppppiVar11 = (int ****)0x3;
      WPP_RECORDER_SF_d(*puVar5,uVar8,3,0x42,&WPP_ab5e86bec157388494c90161187d07a9_Traceguids,
                        (char)uVar6);
    }
    ppppiVar13 = local_68;
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    in_stack_ffffffffffffff88 = (undefined4 *)&WPP_ab5e86bec157388494c90161187d07a9_Traceguids;
    uVar8 = CONCAT71((int7)(uVar8 >> 8),4);
    ppppiVar11 = (int ****)0x3;
    WPP_RECORDER_SF_(*puVar5,4,3,0x41,&WPP_ab5e86bec157388494c90161187d07a9_Traceguids);
  }
  uVar3 = 0;
  lVar10 = 0;
LAB_1c000cf1d:
  *(undefined1 *)((longlong)puVar5 + 0x19c) = uVar3;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_l(*puVar5,uVar8,ppppiVar11,0x46,in_stack_ffffffffffffff88,uVar3);
  }
  if (ppppiVar13 != (int ****)0x0) {
    ExFreePoolWithTag(ppppiVar13,0x6e744247);
  }
  if (lVar10 != 0) {
    ExFreePoolWithTag(lVar10,0x6e744247);
  }
  return uVar9;
}



===== Button_CreateChildPdo @ 1c000d000 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int Button_CreateChildPdo(undefined8 ****param_1)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 *******pppppppuVar3;
  undefined2 uVar4;
  undefined1 auStackY_228 [32];
  undefined8 *******local_1f8;
  undefined8 *******local_1f0;
  undefined8 local_1e8;
  undefined8 *local_1e0;
  undefined8 local_1d8;
  undefined8 *local_1d0;
  undefined8 local_1c8;
  undefined4 *local_1c0;
  undefined8 local_1b8;
  undefined8 uStack_1b0;
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  undefined8 local_198;
  undefined8 uStack_190;
  undefined8 local_188;
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_170;
  undefined1 local_16b;
  code *local_160;
  code *local_158;
  undefined4 local_118;
  undefined2 local_114;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined4 local_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined8 local_a8;
  undefined2 local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined4 local_28;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_228;
  memset(&local_178,0,0x60);
  local_1f0 = (undefined8 *******)0x0;
  local_1b8 = 0;
  uStack_1b0 = 0;
  local_188 = (ulonglong)local_188._4_4_ << 0x20;
  local_1a8 = 0;
  uStack_1a0 = 0;
  local_28 = 0x29;
  local_1d0 = &local_98;
  local_198 = 0;
  uStack_190 = 0;
  local_98 = 0x280050003a0044;
  uStack_90 = 0x47003b003b0041;
  local_78 = 0x47003b003b0041;
  uStack_70 = 0x47005700470052;
  local_a0 = 0;
  local_1e0 = &local_108;
  local_58 = 0x47003b003b0041;
  uStack_50 = 0x3b003b003b0052;
  local_88 = 0x3b003b003b0041;
  uStack_80 = 0x28002900590053;
  local_38 = 0x3b005700470052;
  uStack_30 = 0x440055003b003b;
  local_68 = 0x3b003b003b0058;
  uStack_60 = 0x28002900410042;
  local_118 = 0x30;
  local_108 = 0x6500300033007b;
  uStack_100 = 0x66006200660062;
  local_48 = 0x28002900440057;
  uStack_40 = 0x47003b003b0041;
  local_114 = 0;
  local_1c0 = &local_118;
  local_e8 = 0x2d006400340064;
  uStack_e0 = 0x35006300660039;
  local_f8 = 0x660064002d0038;
  uStack_f0 = 0x34002d00660035;
  local_c8 = 0x34006600640031;
  uStack_c0 = 0x47005c007d0061;
  local_d8 = 0x3600320061002d;
  uStack_d0 = 0x64006600370063;
  local_a8 = 0x73006e006f;
  local_1d8 = 0x740072;
  local_b8 = 0x490050;
  uStack_b4 = 0x20004f;
  uStack_b0 = 0x750042;
  uStack_ac = 0x740074;
  local_1e8 = 0x6a0068;
  local_1c8 = 0x60004;
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_BUTTON_CONTEXT_TYPE_INFO_1c0009040);
  pppppppuVar3 = (undefined8 *******)param_1;
  local_1f8 = (undefined8 *******)(**(code **)(WdfFunctions_01015 + 0x690))(WdfDriverGlobals);
  if (local_1f8 == (undefined8 *******)0x0) {
    iVar1 = -0x3fffff66;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000d51e;
    uVar4 = 0x2f;
    param_1 = pppppppuVar3;
    iVar1 = -0x3fffff66;
  }
  else {
    (**(code **)(WdfFunctions_01015 + 0x1f0))
              (WdfDriverGlobals,local_1f8,*(undefined1 *)((longlong)puVar2 + 0x19d));
    pppppppuVar3 = local_1f8;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x220))(WdfDriverGlobals,local_1f8,&local_1d8);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000d51e;
      uVar4 = 0x30;
      param_1 = pppppppuVar3;
    }
    else {
      pppppppuVar3 = local_1f8;
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x6d0))
                        (WdfDriverGlobals,local_1f8,&GUID_CUSTOM_GPIO_BUTTON_CLASS);
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000d51e;
        uVar4 = 0x31;
        param_1 = pppppppuVar3;
      }
      else {
        pppppppuVar3 = local_1f8;
        iVar1 = (**(code **)(WdfFunctions_01015 + 0x6a0))(WdfDriverGlobals,local_1f8,&local_1e8);
        if (iVar1 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1c000d51e;
          uVar4 = 0x32;
          param_1 = pppppppuVar3;
        }
        else {
          pppppppuVar3 = local_1f8;
          iVar1 = (**(code **)(WdfFunctions_01015 + 0x6b0))(WdfDriverGlobals,local_1f8,&local_1e8);
          if (iVar1 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_1c000d51e;
            uVar4 = 0x33;
            param_1 = pppppppuVar3;
          }
          else {
            pppppppuVar3 = local_1f8;
            iVar1 = (**(code **)(WdfFunctions_01015 + 0x6a8))(WdfDriverGlobals,local_1f8,&local_1c8)
            ;
            if (iVar1 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
              goto LAB_1c000d51e;
              uVar4 = 0x34;
              param_1 = pppppppuVar3;
            }
            else {
              local_188 = 0;
              pppppppuVar3 = &local_1f8;
              local_1a8 = 0;
              uStack_1b0 = 0;
              local_1b8 = 0x38;
              local_198 = 0;
              uStack_190 = 0;
              uStack_1a0 = 0x100000001;
              iVar1 = (**(code **)(WdfFunctions_01015 + 600))
                                (WdfDriverGlobals,pppppppuVar3,&local_1b8,&local_1f0);
              if (iVar1 < 0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                goto LAB_1c000d51e;
                uVar4 = 0x35;
                param_1 = pppppppuVar3;
              }
              else {
                local_158 = Button_EvtIoWrite;
                local_178 = 0x60;
                local_160 = Button_EvtIoRead;
                local_170 = 2;
                local_16b = 1;
                local_174 = 1;
                pppppppuVar3 = local_1f0;
                iVar1 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                                  (WdfDriverGlobals,local_1f0,&local_178,0);
                if (iVar1 < 0) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                  goto LAB_1c000d51e;
                  uVar4 = 0x36;
                  param_1 = pppppppuVar3;
                }
                else {
                  pppppppuVar3 = local_1f0;
                  iVar1 = (**(code **)(WdfFunctions_01015 + 0x268))
                                    (WdfDriverGlobals,local_1f0,&GUID_GPIOBUTTONS_NOTIFY_INTERFACE,0
                                    );
                  if (iVar1 < 0) {
                    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                    goto LAB_1c000d51e;
                    uVar4 = 0x37;
                    param_1 = pppppppuVar3;
                  }
                  else {
                    iVar1 = (**(code **)(WdfFunctions_01015 + 0x428))
                                      (WdfDriverGlobals,param_1,local_1f0);
                    if (-1 < iVar1) {
                      return iVar1;
                    }
                    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                    goto LAB_1c000d51e;
                    uVar4 = 0x38;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  WPP_RECORDER_SF_d(*puVar2,param_1,3,uVar4,&WPP_ab5e86bec157388494c90161187d07a9_Traceguids,
                    (char)iVar1);
LAB_1c000d51e:
  if (local_1f8 != (undefined8 *******)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x1b0))(WdfDriverGlobals);
  }
  if (local_1f0 != (undefined8 *******)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  return iVar1;
}



===== Button_EvaluateAcpiMethod @ 1c000d598 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int Button_EvaluateAcpiMethod
              (undefined8 param_1,int param_2,int *param_3,longlong *param_4,undefined4 *param_5)

{
  undefined8 uVar1;
  longlong lVar2;
  int iVar3;
  undefined4 uVar4;
  byte bVar5;
  int local_res18 [2];
  longlong local_68 [3];
  undefined4 local_50;
  undefined4 local_4c;
  ulonglong local_48;
  int *local_40;
  int local_38;
  undefined4 local_34;
  
  local_48 = (ulonglong)(uint)local_48;
  local_50 = 0;
  local_68[0] = 0;
  local_res18[0] = 0;
  local_res18[1] = 0;
  local_68[1] = 0;
  local_68[2] = 0;
  if (param_3 == (int *)0x0) {
    if (param_2 == 0) {
      return -0x3fffff11;
    }
    param_3 = local_res18;
    local_res18[1] = param_2;
    local_res18[0] = 0x42696541;
  }
  else {
    iVar3 = *param_3;
    if (iVar3 != 0x42696541) {
      if (iVar3 == 0x43696541) {
        iVar3 = param_3[2];
      }
      else if (iVar3 == 0x49696541) {
        iVar3 = 0xc;
      }
      else {
        if (iVar3 != 0x53696541) {
          return -0x3fffff10;
        }
        iVar3 = param_3[2] + 0xf;
      }
      goto LAB_1c000d604;
    }
  }
  iVar3 = 8;
LAB_1c000d604:
  bVar5 = 0;
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,param_1);
  local_48 = 1;
  uVar4 = 0x200;
  local_34 = 0;
  local_40 = param_3;
  local_38 = iVar3;
  while( true ) {
    lVar2 = ExAllocatePool2(0x100,uVar4,0x6e744247);
    if (lVar2 == 0) {
      return -0x3fffff66;
    }
    local_68[1] = 1;
    local_4c = 0;
    local_68[2] = lVar2;
    local_50 = uVar4;
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x5d0))
                      (WdfDriverGlobals,uVar1,0,0x32c004,&local_48,local_68 + 1,0,local_68);
    bVar5 = bVar5 + 1;
    if (iVar3 != -0x7ffffffb) break;
    uVar4 = *(undefined4 *)(lVar2 + 4);
    ExFreePoolWithTag(lVar2,0);
    if (1 < bVar5) {
      return -0x7ffffffb;
    }
  }
  if (-1 < iVar3) {
    if (local_68[0] != 0) {
      *param_4 = lVar2;
      if (param_5 == (undefined4 *)0x0) {
        return iVar3;
      }
      *param_5 = uVar4;
      return iVar3;
    }
    iVar3 = -0x3fffffff;
  }
  ExFreePoolWithTag(lVar2,0x6e744247);
  return iVar3;
}



===== Button_EvaluateCRSMethod @ 1c000d7a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int Button_EvaluateCRSMethod(undefined8 param_1,longlong *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  byte bVar6;
  undefined4 local_res20;
  undefined4 local_res24;
  longlong local_68;
  undefined8 local_60;
  undefined8 local_58;
  longlong lStack_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  
  local_68 = 0;
  local_3c = 0;
  local_48 = 0;
  bVar6 = 0;
  local_58 = 0;
  lStack_50 = 0;
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_BUTTON_CONTEXT_TYPE_INFO_1c0009040);
  lVar3 = 0;
  local_res20 = 0x42696541;
  local_3c = 0;
  local_38 = &local_res20;
  local_2c = 0;
  local_res24 = 0x5352435f;
  uVar5 = 0x200;
  local_40 = 1;
  local_30 = 8;
  local_60 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,param_1);
  while( true ) {
    uVar4 = local_60;
    if (lVar3 != 0) {
      uVar5 = *(undefined4 *)(lVar3 + 4);
      ExFreePoolWithTag(lVar3,0x6e744247);
    }
    lVar3 = ExAllocatePool2(0x100,uVar5,0x6e744247);
    if (lVar3 == 0) {
      return -0x3fffff66;
    }
    local_44 = 0;
    local_58 = 1;
    lStack_50 = lVar3;
    local_48 = uVar5;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x5d0))
                      (WdfDriverGlobals,uVar4,0,0x32c004,&local_40,&local_58,0,&local_68);
    bVar6 = bVar6 + 1;
    if (iVar1 != -0x7ffffffb) break;
    if (1 < bVar6) {
LAB_1c000d91f:
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*puVar2,uVar4,3,0x2d,&WPP_ab5e86bec157388494c90161187d07a9_Traceguids,
                          (char)iVar1);
      }
      if (iVar1 < 0) {
LAB_1c000d993:
        ExFreePoolWithTag(lVar3,0x6e744247);
      }
      return iVar1;
    }
  }
  if (-1 < iVar1) {
    if (local_68 != 0) {
      *param_2 = lVar3;
      *param_3 = uVar5;
      return iVar1;
    }
    iVar1 = -0x3fffffff;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*puVar2,2,3,0x2e,&WPP_ab5e86bec157388494c90161187d07a9_Traceguids);
    }
    goto LAB_1c000d993;
  }
  goto LAB_1c000d91f;
}



===== Button_EventHandler @ 1c000d9e4 =====

void Button_EventHandler(longlong param_1,undefined8 *param_2,char param_3)

{
  uint uVar1;
  longlong *plVar2;
  undefined2 uVar3;
  
  uVar1 = 0;
  plVar2 = param_2 + 5;
  while (param_1 != *plVar2) {
    uVar1 = uVar1 + 1;
    plVar2 = plVar2 + 2;
    if (1 < uVar1) {
      return;
    }
  }
  if ((char *)(param_2 + ((ulonglong)uVar1 + 2) * 2) == (char *)0x0) {
    return;
  }
  *(char *)(param_2 + ((ulonglong)uVar1 + 2) * 2) = param_3;
  if (param_3 == '\0') {
    if (uVar1 == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000dab8;
      uVar3 = 0x29;
    }
    else {
      if ((uVar1 != 1) || ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED))
      goto LAB_1c000dab8;
      uVar3 = 0x2a;
    }
  }
  else if (uVar1 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000dab8;
    uVar3 = 0x27;
  }
  else {
    if ((uVar1 != 1) || ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED))
    goto LAB_1c000dab8;
    uVar3 = 0x28;
  }
  WPP_RECORDER_SF_(*param_2,4,3,uVar3,&WPP_ab5e86bec157388494c90161187d07a9_Traceguids);
LAB_1c000dab8:
  KeEnterCriticalRegion();
  ExAcquireFastMutexUnsafe(param_2 + 8);
  Button_ConfigureButtonInterrupt(param_2,2);
  Button_ConfigureButtonInterrupt(param_2,3);
  Button_ConfigureButtonInterrupt(param_2,4);
  ExReleaseFastMutexUnsafe(param_2 + 8);
  KeLeaveCriticalRegion();
  return;
}



===== Button_EventStartCallback @ 1c000db30 =====

void Button_EventStartCallback(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  Button_EventHandler(param_1,param_3,'\x01');
  return;
}



===== Button_EventStopCallback @ 1c000db50 =====

void Button_EventStopCallback(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  Button_EventHandler(param_1,param_3,'\0');
  return;
}



===== Button_EvtDeviceAdd @ 1c000db6c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong Button_EvtDeviceAdd(undefined8 *******param_1)

{
  uint uVar1;
  undefined8 ****ppppuVar2;
  ulonglong uVar3;
  undefined8 ***pppuVar4;
  undefined8 *************pppppppppppppuVar5;
  code *pcVar6;
  ulonglong uVar7;
  undefined2 uVar8;
  undefined1 auStackY_1f8 [32];
  undefined8 ****local_1b0;
  undefined8 ***local_1a8;
  undefined4 local_1a0 [2];
  undefined8 *************local_198;
  ulonglong local_190;
  code *local_188;
  undefined8 local_180;
  undefined4 local_178;
  undefined4 local_174;
  undefined8 local_170;
  undefined8 uStack_168;
  undefined *local_160;
  undefined4 local_158;
  undefined8 local_154;
  undefined1 local_14c;
  undefined1 local_14b;
  code *local_128;
  undefined4 local_108;
  undefined4 local_f8;
  undefined4 local_f4;
  code *local_d0;
  code *local_c8;
  undefined8 ***local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined4 local_30;
  undefined2 local_2c;
  undefined1 local_2a;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_1f8;
  local_1a8 = (undefined8 ***)0x0;
  local_f4 = 0;
  local_30 = 0x74747562;
  pcVar6 = (code *)&local_68;
  local_2c = 0x6e6f;
  uStack_40 = 0;
  local_2a = 0;
  local_190 = (ulonglong)(uint)local_190;
  local_180 = 0;
  local_170 = 0;
  uStack_168 = 0;
  local_1b0 = (undefined8 ****)0x0;
  local_68 = (undefined8 ***)0x38;
  local_48 = 0;
  local_58 = 0;
  uStack_50 = 0x1000000000;
  local_38 = 0x200000002;
  uStack_60 = 0xc800000400;
  local_198 = (undefined8 *************)param_1;
  uVar1 = imp_WppRecorderLogCreate(WPP_GLOBAL_Control,pcVar6,&local_1a8);
  uVar7 = (ulonglong)uVar1;
  if ((int)uVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return uVar7;
    }
    uVar8 = 0x39;
    pppuVar4 = *(undefined8 ****)(WPP_GLOBAL_Control + 0x40);
LAB_1c000dc9e:
    WPP_RECORDER_SF_d(pppuVar4,pcVar6,3,uVar8,&WPP_ab5e86bec157388494c90161187d07a9_Traceguids,
                      (char)uVar7);
  }
  else {
    imp_WppRecorderLogSetIdentifier(WPP_GLOBAL_Control,local_1a8,&local_30);
    (**(code **)(WdfFunctions_01015 + 0x200))(WdfDriverGlobals,local_198);
    (**(code **)(WdfFunctions_01015 + 0x1c8))(WdfDriverGlobals,local_198,0);
    memset(&local_f8,0,0x90);
    local_d0 = Button_EvtDevicePrepareHardware;
    local_c8 = Button_EvtDeviceReleaseHardware;
    local_f8 = 0x90;
    (**(code **)(WdfFunctions_01015 + 0x1b8))(WdfDriverGlobals,local_198,&local_f8);
    pppppppppppppuVar5 = local_198;
    uVar1 = (**(code **)(WdfFunctions_01015 + 0x248))
                      (WdfDriverGlobals,local_198,Button_EvtDeviceWdmPnPIrpPreprocess,0x1b);
    uVar7 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar8 = 0x3a;
LAB_1c000ddd8:
        WPP_RECORDER_SF_d(local_1a8,pppppppppppppuVar5,3,uVar8,
                          &WPP_ab5e86bec157388494c90161187d07a9_Traceguids,(char)uVar7);
      }
    }
    else {
      local_160 = PTR__WDF_BUTTON_CONTEXT_TYPE_INFO_1c0009040;
      pppppppppppppuVar5 = &local_198;
      local_190 = 0x38;
      local_188 = Button_EvtDeviceCleanupCallback;
      local_180 = 0;
      local_170 = 0;
      uStack_168 = 0;
      local_178 = 1;
      local_174 = 1;
      uVar1 = (**(code **)(WdfFunctions_01015 + 600))
                        (WdfDriverGlobals,pppppppppppppuVar5,&local_190,&local_1b0);
      uVar7 = (ulonglong)uVar1;
      if (-1 < (int)uVar1) {
        ppppuVar2 = (undefined8 ****)
                    (**(code **)(WdfFunctions_01015 + 0x650))
                              (WdfDriverGlobals,local_1b0,
                               PTR__WDF_BUTTON_CONTEXT_TYPE_INFO_1c0009040);
        *ppppuVar2 = local_1a8;
        pppuVar4 = (undefined8 ***)(**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals);
        ppppuVar2[0x32] = pppuVar4;
        ppppuVar2[0x1a] = (undefined8 ***)0x0;
        memset(ppppuVar2 + 0x1b,0,0x40);
        KeInitializeSpinLock(ppppuVar2 + 0x19);
        KeInitializeSpinLock(ppppuVar2 + 0x18);
        pcVar6 = Button_InterruptDpc;
        *(undefined4 *)(ppppuVar2 + 0xf) = 0;
        *(code *)((longlong)ppppuVar2 + 0x7c) = (code)0x0;
        KeInitializeDpc(ppppuVar2[0x32] + 0x19);
        uVar3 = Button_CheckPowerButtonPressAndHoldSupport((ulonglong)local_1b0);
        uVar7 = uVar3 & 0xffffffff;
        if ((int)uVar3 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return uVar7;
          }
          uVar8 = 0x3c;
          pppuVar4 = local_1a8;
        }
        else {
          Button_CheckPowerButtonEdges(local_1b0);
          Button_CheckExclusivity(ppppuVar2);
          memset(&local_158,0,0x60);
          local_108 = 0xffffffff;
          local_128 = HID_InternalDeviceControl;
          local_158 = 0x60;
          local_14b = 1;
          local_154 = 0x200000002;
          pcVar6 = (code *)local_1b0;
          uVar1 = (**(code **)(WdfFunctions_01015 + 0x4c0))(WdfDriverGlobals,local_1b0,&local_158,0)
          ;
          uVar7 = (ulonglong)uVar1;
          if ((int)uVar1 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
              return uVar7;
            }
            uVar8 = 0x3d;
          }
          else {
            memset(&local_14c,0,0x54);
            local_158 = 0x60;
            local_154 = 3;
            pcVar6 = (code *)local_1b0;
            uVar1 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                              (WdfDriverGlobals,local_1b0,&local_158,0);
            uVar7 = (ulonglong)uVar1;
            if ((int)uVar1 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                return uVar7;
              }
              uVar8 = 0x3e;
            }
            else {
              local_1a0[0] = 0xd;
              pcVar6 = (code *)ppppuVar2;
              pppuVar4 = (undefined8 ***)
                         Ordinal_4(Button_EvtTimerPowerButtonPressAndHold,ppppuVar2,local_1a0,2);
              ppppuVar2[0x34] = pppuVar4;
              if (pppuVar4 != (undefined8 ***)0x0) {
                uVar1 = Button_CreateChildPdo(local_1b0);
                if ((int)uVar1 < 0) {
                  return (ulonglong)uVar1;
                }
                QueryDeviceConfigurationForTelemetry(local_1b0);
                return (ulonglong)uVar1;
              }
              uVar7 = 0xc000009a;
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                return 0xc000009a;
              }
              uVar8 = 0x3f;
            }
          }
          pppuVar4 = *ppppuVar2;
        }
        goto LAB_1c000dc9e;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar8 = 0x3b;
        goto LAB_1c000ddd8;
      }
    }
    imp_WppRecorderLogDelete(WPP_GLOBAL_Control,local_1a8);
  }
  return uVar7;
}



===== Button_EvtDeviceCleanupCallback @ 1c000e140 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Button_EvtDeviceCleanupCallback(undefined8 param_1)

{
  longlong *plVar1;
  
  plVar1 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_BUTTON_CONTEXT_TYPE_INFO_1c0009040);
  if (plVar1[0x34] != 0) {
    ExDeleteTimer(plVar1[0x34],1,1,0);
    plVar1[0x34] = 0;
  }
  if (*plVar1 != 0) {
    imp_WppRecorderLogDelete(WPP_GLOBAL_Control);
    *plVar1 = 0;
  }
  return;
}



===== Button_EvtDevicePrepareHardware @ 1c000e1d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int Button_EvtDevicePrepareHardware(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  undefined8 *puVar5;
  longlong lVar6;
  byte *pbVar7;
  longlong lVar8;
  undefined8 uVar9;
  uint uVar10;
  undefined8 uVar11;
  undefined1 *puVar12;
  byte bVar13;
  undefined1 auStackY_1c8 [32];
  undefined8 in_stack_fffffffffffffe58;
  undefined4 in_stack_fffffffffffffe68;
  undefined4 in_stack_fffffffffffffe6c;
  byte local_188;
  undefined1 local_187 [7];
  undefined8 *local_180;
  longlong local_178;
  undefined8 local_170;
  undefined4 local_168;
  undefined4 local_164;
  undefined8 local_160;
  longlong local_158;
  code *local_150;
  undefined1 *local_148;
  undefined8 *local_140;
  byte local_138;
  undefined1 local_136;
  undefined4 local_134;
  undefined1 local_130;
  uint local_12c;
  undefined8 local_128;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 *local_108;
  undefined8 uStack_100;
  code *local_f8;
  code *pcStack_f0;
  undefined8 *local_e8;
  undefined8 local_e0;
  undefined8 local_d8 [4];
  wchar_t *local_b8;
  int local_b0;
  undefined4 local_ac;
  wchar_t *local_a8;
  int local_a0;
  undefined4 local_9c;
  wchar_t *local_98;
  int local_90;
  undefined4 local_8c;
  byte *local_88;
  undefined8 local_80;
  undefined1 *local_78;
  undefined8 local_70;
  undefined8 **local_68;
  undefined8 local_60;
  undefined8 *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1c8;
  local_164 = 0;
  local_170 = param_3;
  memset(&local_168,0,0x4c);
  local_e8 = (undefined8 *)0x0;
  iVar4 = 0;
  local_118 = 0;
  uStack_110 = 0;
  local_108 = (undefined8 *)0x0;
  uStack_100 = 0;
  local_f8 = (code *)0x0;
  pcStack_f0 = (code *)0x0;
  puVar5 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  uVar11 = 0;
  puVar5[9] = 0;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 8) = 1;
  KeInitializeEvent(puVar5 + 0xb,1);
  puVar5[4] = 0;
  puVar5[5] = 0;
  puVar5[6] = 0;
  puVar5[7] = 0;
  puVar5[0x13] = 0;
  puVar5[0x14] = 0;
  puVar5[0x15] = 0;
  puVar5[0x16] = 0;
  puVar5[0x17] = 0;
  local_e0 = 0x41840b3ea3bdb075;
  uVar9 = param_3;
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x980))(WdfDriverGlobals);
  if (uVar3 < 6) {
    uVar10 = 0;
    bVar13 = 0;
    if (uVar3 != 0) {
      do {
        pbVar7 = (byte *)(**(code **)(WdfFunctions_01015 + 0x988))(WdfDriverGlobals,param_3,uVar10);
        bVar1 = *pbVar7;
        if (bVar1 != 2) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_Dd(*puVar5,(ulonglong)bVar1,3,0x1c,
                               &WPP_ab5e86bec157388494c90161187d07a9_Traceguids,bVar1,1);
          }
          goto LAB_1c000e30e;
        }
        local_188 = pbVar7[4];
        if (pbVar7[4] <= bVar13) {
          local_188 = bVar13;
        }
        uVar10 = uVar10 + 1;
        bVar13 = local_188;
      } while (uVar10 < uVar3);
      uVar10 = 0;
      local_180 = puVar5 + 0x10;
      local_178 = 0;
      puVar12 = (undefined1 *)((longlong)puVar5 + 0x119);
      do {
        lVar6 = (**(code **)(WdfFunctions_01015 + 0x988))(WdfDriverGlobals,local_170,uVar10);
        *(undefined8 **)(puVar12 + 7) = puVar5;
        uVar9 = 0;
        puVar12[-1] = (char)uVar10;
        *puVar12 = 1;
        puVar12[0xf] = 0;
        *(undefined4 *)local_180 = 0;
        memset(&local_168,0,0x50);
        local_168 = 1;
        local_160 = puVar5[0x32];
        local_158 = local_178 + 0x98 + (longlong)puVar5;
        local_150 = Button_Isr;
        local_140 = puVar5 + 0x18;
        local_134 = *(undefined4 *)(lVar6 + 8);
        local_130 = *(undefined1 *)(lVar6 + 4);
        local_138 = local_188;
        local_128 = *(undefined8 *)(lVar6 + 0xc);
        local_136 = *(undefined1 *)(lVar6 + 1);
        local_12c = *(byte *)(lVar6 + 2) & 1;
        local_148 = puVar12 + -1;
        iVar4 = IoConnectInterruptEx(&local_168);
        if (iVar4 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_dL(*puVar5);
          }
          iVar4 = 0;
        }
        else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_L(*puVar5,uVar9,3,0x1e,&WPP_ab5e86bec157388494c90161187d07a9_Traceguids,
                            (char)uVar10);
        }
        local_180 = (undefined8 *)((longlong)local_180 + 4);
        uVar10 = uVar10 + 1;
        local_178 = local_178 + 8;
        puVar12 = puVar12 + 0x18;
      } while (uVar10 < uVar3);
    }
    uStack_100 = 0;
    local_108 = (undefined8 *)&WNF_SEB_SYSTEM_LPE;
    local_f8 = Button_EventStartCallback;
    uStack_110 = 0x100000000;
    pcStack_f0 = Button_EventStopCallback;
    local_e8 = puVar5;
    EACreateAggregateEvent(&local_118,puVar5 + 5);
    local_108 = &local_e0;
    local_118 = 0;
    uStack_100 = 1;
    uStack_110 = 0x100000000;
    local_f8 = Button_EventStartCallback;
    pcStack_f0 = Button_EventStopCallback;
    local_e8 = puVar5;
    EACreateAggregateEvent(&local_118,puVar5 + 7);
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_DDd(*puVar5,uVar9,uVar11,0x1b,in_stack_fffffffffffffe58,(char)uVar3,
                          CONCAT44(in_stack_fffffffffffffe6c,in_stack_fffffffffffffe68),1);
    }
LAB_1c000e30e:
    iVar4 = -0x3fffffff;
  }
  local_90 = 2;
  if (5 < DAT_1c0009098) {
    if (((_DAT_1c00090a8 & 0x400000000000) == 0) ||
       (bVar2 = true, (DAT_1c00090b0 & 0x400000000000) != DAT_1c00090b0)) {
      bVar2 = false;
    }
    if (bVar2) {
      local_b8 = (wchar_t *)puVar5[0x35];
      lVar6 = -1;
      if (local_b8 == (wchar_t *)0x0) {
        local_b8 = L"";
        local_b0 = 2;
      }
      else {
        lVar8 = -1;
        do {
          lVar8 = lVar8 + 1;
        } while (local_b8[lVar8] != L'\0');
        local_b0 = (int)lVar8 * 2 + 2;
      }
      local_a8 = (wchar_t *)puVar5[0x36];
      local_ac = 0;
      if (local_a8 == (wchar_t *)0x0) {
        local_a8 = L"";
        local_a0 = 2;
      }
      else {
        lVar8 = -1;
        do {
          lVar8 = lVar8 + 1;
        } while (local_a8[lVar8] != L'\0');
        local_a0 = (int)lVar8 * 2 + 2;
      }
      local_98 = (wchar_t *)puVar5[0x37];
      local_9c = 0;
      if (local_98 == (wchar_t *)0x0) {
        local_98 = L"";
      }
      else {
        do {
          lVar6 = lVar6 + 1;
        } while (local_98[lVar6] != L'\0');
        local_90 = (int)lVar6 * 2 + 2;
      }
      local_188 = *(byte *)(puVar5 + 0x38);
      local_88 = &local_188;
      local_187[0] = *(undefined1 *)((longlong)puVar5 + 0x119);
      local_78 = local_187;
      local_68 = &local_180;
      local_58 = &local_170;
      local_8c = 0;
      local_80 = 1;
      local_70 = 1;
      local_180 = (undefined8 *)CONCAT44(local_180._4_4_,iVar4);
      local_60 = 4;
      local_170 = 0x800;
      local_50 = 8;
      _tlgWriteTransfer_EtwWriteTransfer(0x1c0009098,&DAT_1c0007c91,0,0,9,local_d8);
    }
  }
  return iVar4;
}



===== Button_EvtDeviceReleaseHardware @ 1c000e740 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 Button_EvtDeviceReleaseHardware(undefined8 param_1)

{
  undefined8 *puVar1;
  longlong *plVar2;
  uint uVar3;
  longlong lVar4;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  uStack_10 = 0;
  local_18 = 0;
  local_14 = 0;
  puVar1 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_BUTTON_CONTEXT_TYPE_INFO_1c0009040);
  lVar4 = 2;
  plVar2 = puVar1 + 5;
  do {
    if (*plVar2 != 0) {
      EADeleteAggregateEvent();
      *plVar2 = 0;
      *(undefined1 *)(plVar2 + -1) = 0;
    }
    plVar2 = plVar2 + 2;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  plVar2 = puVar1 + 0x13;
  uVar3 = 0;
  do {
    if (*plVar2 != 0) {
      local_18 = 1;
      uStack_10 = (undefined4)*plVar2;
      uStack_c = (undefined4)((ulonglong)*plVar2 >> 0x20);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_L(*puVar1,param_1,3,0x1f,&WPP_ab5e86bec157388494c90161187d07a9_Traceguids,
                          (char)uVar3);
      }
      IoDisconnectInterruptEx(&local_18);
    }
    uVar3 = uVar3 + 1;
    plVar2 = plVar2 + 1;
  } while (uVar3 < 5);
  return 0;
}



===== Button_EvtDeviceWdmIrpQueryCapabilitiesCompletion @ 1c000e840 =====

undefined8 Button_EvtDeviceWdmIrpQueryCapabilitiesCompletion(undefined8 param_1,longlong param_2)

{
  byte *pbVar1;
  uint *puVar2;
  longlong lVar3;
  
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  lVar3 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  puVar2 = (uint *)(lVar3 + 4);
  *puVar2 = *puVar2 & 0xffffc3ff;
  *(undefined8 *)(lVar3 + 0x2c) = 0;
  return 0;
}



===== Button_EvtDeviceWdmIrpQueryId @ 1c000e874 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 Button_EvtDeviceWdmIrpQueryId(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_BUTTON_CONTEXT_TYPE_INFO_1c0009040);
  lVar1 = *(longlong *)(param_2 + 0xb8);
  if (*(longlong *)(lVar1 + 0xb8) == *(longlong *)(lVar1 + 0x70)) {
    uVar5 = *(undefined4 *)(param_2 + 0x30);
  }
  else {
    uVar5 = 0;
    if ((*(int *)(lVar1 + 8) == 0) || (*(int *)(lVar1 + 8) == 1)) {
      uVar4 = 0x1a;
      puVar3 = (undefined8 *)ExAllocatePool2(0x40,0x1a,0x6e744247);
      if (puVar3 == (undefined8 *)0x0) {
        uVar5 = 0xc000009a;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_d(*puVar2,uVar4,3,0x18,&WPP_ab5e86bec157388494c90161187d07a9_Traceguids,
                            0x9a);
        }
      }
      else {
        *puVar3 = 0x54004f004f0052;
        puVar3[1] = 0x50004e0050005c;
        puVar3[2] = 0x30003400430030;
        *(undefined2 *)(puVar3 + 3) = 0;
        *(undefined8 **)(param_2 + 0x38) = puVar3;
      }
    }
    else {
      uVar5 = *(undefined4 *)(param_2 + 0x30);
    }
    *(undefined4 *)(param_2 + 0x30) = uVar5;
  }
  IofCompleteRequest(param_2,0);
  return uVar5;
}



===== Button_EvtDeviceWdmPnPIrpPreprocess @ 1c000e990 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Button_EvtDeviceWdmPnPIrpPreprocess(undefined8 param_1,longlong param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  
  puVar1 = *(undefined8 **)(param_2 + 0xb8);
  if (*(char *)((longlong)puVar1 + 1) == '\t') {
    puVar1[-9] = *puVar1;
    puVar1[-8] = puVar1[1];
    puVar1[-7] = puVar1[2];
    puVar1[-6] = puVar1[3];
    puVar1[-5] = puVar1[4];
    puVar1[-4] = puVar1[5];
    puVar1[-3] = puVar1[6];
    *(undefined1 *)((longlong)puVar1 + -0x45) = 0;
    lVar2 = *(longlong *)(param_2 + 0xb8);
    *(code **)(lVar2 + -0x10) = Button_EvtDeviceWdmIrpQueryCapabilitiesCompletion;
    *(undefined8 *)(lVar2 + -8) = param_1;
    *(undefined1 *)(lVar2 + -0x45) = 0x40;
  }
  else {
    if (*(char *)((longlong)puVar1 + 1) == '\x13') {
      Button_EvtDeviceWdmIrpQueryId(param_1,param_2);
      return;
    }
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(undefined8 **)(param_2 + 0xb8) = puVar1 + 9;
  }
  (**(code **)(WdfFunctions_01015 + 0x110))(WdfDriverGlobals,param_1,param_2);
  return;
}



===== Button_PrepareInputParametersForDsmMethod @ 1c000ea30 =====

undefined8
Button_PrepareInputParametersForDsmMethod(undefined4 param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined4 *puVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  
  puVar1 = (undefined4 *)ExAllocatePool2(0x100,0x3c,0x6e744247);
  uVar3 = 0;
  if (puVar1 == (undefined4 *)0x0) {
    uVar3 = 0xc000009a;
  }
  else {
    puVar1[2] = 0x3c;
    *puVar1 = 0x43696541;
    puVar1[1] = 0x4d53445f;
    puVar1[3] = 4;
    puVar1[4] = 0x100002;
    memcpy_s(puVar1 + 5,0x10,&WINDOWS_BUTTON_ARRAY_DSM_GUID,0x10);
    uVar2 = (ulonglong)*(ushort *)((longlong)puVar1 + 0x12);
    if (*(ushort *)((longlong)puVar1 + 0x12) < 4) {
      uVar2 = 4;
    }
    *(undefined8 *)((longlong)puVar1 + uVar2 + 0x14) = 0x40000;
    *(undefined4 *)((longlong)puVar1 + uVar2 + 0x1c) = 0x40000;
    *(undefined4 *)((longlong)puVar1 + uVar2 + 0x20) = param_1;
    *(undefined8 *)((longlong)puVar1 + uVar2 + 0x24) = 0x40003;
    *param_3 = puVar1;
  }
  return uVar3;
}



===== QueryDeviceConfigurationForTelemetry @ 1c000eb0c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void QueryDeviceConfigurationForTelemetry(undefined8 param_1)

{
  int iVar1;
  undefined8 *puVar2;
  wchar_t *pwVar3;
  longlong lVar4;
  char *pcVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  ulonglong *puVar8;
  undefined8 uVar9;
  int local_res8 [2];
  undefined8 local_res10;
  ulonglong local_res18;
  ulonglong *puVar10;
  undefined1 uVar11;
  ulonglong local_78;
  undefined *local_70;
  undefined8 local_68;
  ulonglong local_60 [5];
  undefined8 uStack_38;
  undefined8 local_30;
  
  local_78 = (ulonglong)(uint)local_78;
  local_60[0] = (ulonglong)(uint)local_60[0];
  local_res8[0] = 0;
  local_res18 = 0;
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_BUTTON_CONTEXT_TYPE_INFO_1c0009040);
  local_78 = 0x18;
  local_68 = 0;
  local_30 = 0;
  local_res10 = 0;
  local_60[2] = 0;
  local_60[3] = 0x100000001;
  puVar8 = &local_78;
  local_70 = &DEVPKEY_Device_InstanceId;
  puVar10 = local_60;
  local_60[1] = 0;
  local_60[0] = 0x38;
  uStack_38 = 0;
  uVar6 = param_1;
  local_60[4] = param_1;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0xd90))
                    (WdfDriverGlobals,param_1,puVar8,0x200,puVar10,&local_res10,local_res8);
  uVar11 = (undefined1)param_1;
  if ((iVar1 < 0) || (local_res8[0] != 0x12)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qdD(*puVar2,uVar6,puVar8,0x47,puVar10,uVar11,(char)iVar1,(char)local_res8[0]);
    }
    if (-1 < iVar1) {
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,local_res10);
    }
  }
  else {
    uVar9 = 0;
    uVar6 = local_res10;
    pwVar3 = (wchar_t *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals);
    puVar2[0x35] = pwVar3;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qS(*puVar2,uVar6,uVar9,0x48,puVar10,uVar11,pwVar3);
    }
  }
  local_78 = 0x18;
  local_70 = &DEVPKEY_Device_HardwareIds;
  puVar8 = &local_78;
  puVar10 = local_60;
  local_68 = 0;
  local_res10 = 0;
  uVar6 = param_1;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0xd90))
                    (WdfDriverGlobals,param_1,puVar8,0x200,puVar10,&local_res10,local_res8);
  if ((iVar1 < 0) || (local_res8[0] != 0x2012)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qdD(*puVar2,uVar6,puVar8,0x49,puVar10,uVar11,(char)iVar1,(char)local_res8[0]);
    }
    if (-1 < iVar1) {
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,local_res10);
    }
  }
  else {
    puVar8 = &local_res18;
    lVar4 = (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,local_res10);
    puVar2[0x36] = lVar4;
    uVar7 = local_res18 >> 1;
    WStringListToWString(lVar4,uVar7);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qS(*puVar2,uVar7,puVar8,0x4a,puVar10,uVar11,(wchar_t *)puVar2[0x36]);
    }
  }
  local_78 = 0x18;
  local_70 = &DEVPKEY_Device_LowerFilters;
  puVar8 = &local_78;
  puVar10 = local_60;
  local_68 = 0;
  local_res10 = 0;
  uVar6 = param_1;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0xd90))
                    (WdfDriverGlobals,param_1,puVar8,0x200,puVar10,&local_res10,local_res8);
  if ((iVar1 < 0) || (local_res8[0] != 0x2012)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qdD(*puVar2,uVar6,puVar8,0x4b,puVar10,uVar11,(char)iVar1,(char)local_res8[0]);
    }
    if (-1 < iVar1) {
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,local_res10);
      local_res10 = 0;
    }
  }
  else {
    puVar8 = &local_res18;
    lVar4 = (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,local_res10);
    puVar2[0x37] = lVar4;
    uVar7 = local_res18 >> 1;
    WStringListToWString(lVar4,uVar7);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qS(*puVar2,uVar7,puVar8,0x4c,puVar10,uVar11,(wchar_t *)puVar2[0x37]);
    }
  }
  local_78 = 0x18;
  local_70 = &DEVPKEY_Device_InLocalMachineContainer;
  puVar8 = &local_78;
  puVar10 = local_60;
  local_68 = 0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0xd90))
                    (WdfDriverGlobals,param_1,puVar8,0x200,puVar10,&local_res10,local_res8);
  if ((iVar1 < 0) || (local_res8[0] != 0x11)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qdD(*puVar2,param_1,puVar8,0x4d,puVar10,uVar11,(char)iVar1,(char)local_res8[0]
                         );
    }
    if (iVar1 < 0) {
      return;
    }
  }
  else {
    pcVar5 = (char *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,local_res10,0);
    *(bool *)(puVar2 + 0x38) = *pcVar5 == -1;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*puVar2);
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,local_res10);
  return;
}



===== Indicator_CheckExclusivity @ 1c000efe8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool Indicator_CheckExclusivity(int param_1)

{
  int iVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined2 uVar4;
  bool bVar5;
  undefined1 auStackY_188 [32];
  int local_148 [2];
  longlong local_140;
  undefined8 local_138;
  wchar_t *local_130;
  undefined8 local_128;
  wchar_t *local_120;
  undefined8 local_118;
  wchar_t *local_110;
  wchar_t local_108 [32];
  wchar_t local_c8 [64];
  wchar_t local_48 [24];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_188;
  local_148[0] = 0;
  local_140 = 0;
  lVar2 = 0;
  builtin_wcsncpy(local_c8,L"\\Registry\\Machine\\System\\CurrentControlSet\\Contr",0x30);
  bVar5 = true;
  builtin_wcsncpy(local_c8 + 0x30,L"ol\\Windows",0xb);
  local_130 = local_c8;
  builtin_wcsncpy(local_108 + 0x10,L"siveAccess",0xb);
  builtin_wcsncpy(local_108,L"LaptopSlateExclu",0x10);
  local_110 = local_108;
  local_120 = local_48;
  builtin_wcsncpy(local_48,L"DockmodeExclusiv",0x10);
  local_138 = 0x760074;
  local_118 = 0x360034;
  local_128 = 0x30002e;
  builtin_wcsncpy(local_48 + 0x10,L"eAccess",8);
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x728))(WdfDriverGlobals,0,&local_138,0x2000000);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000f1df;
    uVar4 = 0xc;
  }
  else {
    puVar3 = &local_128;
    if (param_1 == 1) {
      puVar3 = &local_118;
    }
    lVar2 = local_140;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))(WdfDriverGlobals,local_140,puVar3,local_148);
    if (-1 < iVar1) {
      bVar5 = local_148[0] != 0;
      goto LAB_1c000f1df;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000f1df;
    uVar4 = 0xd;
  }
  WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar2,4,uVar4,
                    &WPP_c6cd92e4efb638f901d990db7ac3a788_Traceguids,(char)iVar1);
LAB_1c000f1df:
  if (local_140 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals);
  }
  return bVar5;
}



===== Indicator_EvtDeviceAdd @ 1c000f230 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int Indicator_EvtDeviceAdd(undefined8 param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  longlong lVar4;
  undefined8 uVar5;
  ulonglong *puVar6;
  undefined8 *puVar7;
  ulonglong *puVar8;
  undefined *puVar9;
  undefined2 uVar10;
  undefined1 auStackY_208 [32];
  ulonglong *local_1d8;
  undefined8 local_1d0;
  undefined8 local_1c8;
  ulonglong local_1c0;
  code *pcStack_1b8;
  undefined8 local_1b0;
  undefined8 uStack_1a8;
  ulonglong *local_1a0;
  undefined8 uStack_198;
  undefined *local_190;
  ulonglong local_188;
  code *pcStack_180;
  undefined8 local_178;
  undefined4 local_168;
  undefined4 local_164;
  undefined4 local_160;
  undefined1 local_15b;
  code *local_150;
  code *local_148;
  undefined4 local_108;
  undefined4 local_104;
  code *local_100;
  code *local_f0;
  code *local_e0;
  code *local_d8;
  ulonglong local_78 [8];
  undefined2 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_208;
  local_1c8 = 0;
  local_1b0 = 0;
  local_1d8 = (ulonglong *)0x0;
  puVar6 = local_78;
  local_78[2] = 0;
  local_1c0 = (ulonglong)(uint)local_1c0;
  local_104 = 0;
  local_188 = (ulonglong)(uint)local_188;
  local_78[5] = 0;
  local_38 = 0x72;
  local_1a0 = (ulonglong *)0x0;
  uStack_198 = 0;
  local_78[6] = 0x200000002;
  local_78[7] = 0x6f74616369646e69;
  local_78[0] = 0x38;
  local_78[4] = 0;
  local_78[3] = 0x1000000000;
  local_78[1] = 0xc800000400;
  local_1d0 = param_1;
  iVar2 = imp_WppRecorderLogCreate(WPP_GLOBAL_Control,puVar6,&local_1c8);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar2;
    }
    uVar10 = 0x26;
    uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
  }
  else {
    imp_WppRecorderLogSetIdentifier(WPP_GLOBAL_Control,local_1c8,local_78 + 7);
    bVar1 = Indicator_CheckExclusivity(param_2);
    (**(code **)(WdfFunctions_01015 + 0x200))(WdfDriverGlobals,local_1d0);
    (**(code **)(WdfFunctions_01015 + 0x1c8))(WdfDriverGlobals,local_1d0,1);
    (**(code **)(WdfFunctions_01015 + 0x1f0))(WdfDriverGlobals,local_1d0,bVar1);
    memset(&local_108,0,0x90);
    local_e0 = Indicator_EvtDevicePrepareHardware;
    local_d8 = Indicator_EvtDeviceReleaseHardware;
    local_100 = Indicator_EvtDeviceD0Entry;
    local_f0 = Indicator_EvtDeviceD0Exit;
    local_108 = 0x90;
    (**(code **)(WdfFunctions_01015 + 0x1b8))(WdfDriverGlobals,local_1d0,&local_108);
    local_1b0 = 0;
    puVar7 = &local_1d0;
    local_190 = PTR__WDF_INDICATOR_CONTEXT_TYPE_INFO_1c0009018;
    pcStack_1b8 = Indicator_EvtDeviceCleanupCallback;
    local_1a0 = (ulonglong *)0x0;
    uStack_198 = 0;
    local_1c0 = 0x38;
    uStack_1a8 = 0x100000001;
    iVar2 = (**(code **)(WdfFunctions_01015 + 600))(WdfDriverGlobals,puVar7,&local_1c0,&local_1d8);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(local_1c8,puVar7,4,0x27,&WPP_c6cd92e4efb638f901d990db7ac3a788_Traceguids,
                          (char)iVar2);
      }
      imp_WppRecorderLogDelete(WPP_GLOBAL_Control,local_1c8);
      return iVar2;
    }
    piVar3 = (int *)(**(code **)(WdfFunctions_01015 + 0x650))
                              (WdfDriverGlobals,local_1d8,
                               PTR__WDF_INDICATOR_CONTEXT_TYPE_INFO_1c0009018);
    *piVar3 = param_2;
    *(undefined8 *)(piVar3 + 4) = local_1c8;
    lVar4 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,local_1d8);
    *(longlong *)(piVar3 + 2) = lVar4;
    *(bool *)(piVar3 + 0x13) = bVar1;
    KeInitializeDpc(lVar4 + 200,Indicator_InterruptDpc,lVar4);
    local_190 = (undefined *)0x0;
    puVar8 = &local_188;
    local_188 = 0x18;
    local_1b0 = 0;
    uStack_198 = 0;
    local_1a0 = local_1d8;
    pcStack_180 = Indicator_HandleStateChange;
    pcStack_1b8 = (code *)0x0;
    local_1c0 = 0x38;
    uStack_1a8 = 0x100000001;
    local_178 = 1;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0xbd8))(WdfDriverGlobals,puVar8,&local_1c0,piVar3 + 8)
    ;
    puVar6 = local_1d8;
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar2;
      }
      uVar10 = 0x28;
      puVar6 = puVar8;
    }
    else {
      local_1b0 = 0;
      local_190 = (undefined *)0x0;
      pcStack_1b8 = (code *)0x0;
      local_1c0 = 0x38;
      uStack_198 = 0;
      local_1a0 = local_1d8;
      uStack_1a8 = 0x100000002;
      memset(&local_168,0,0x60);
      local_160 = 0;
      local_148 = Indicator_EvtIoWrite;
      local_168 = 0x60;
      local_150 = Indicator_EvtIoRead;
      local_15b = 1;
      local_164 = 1;
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                        (WdfDriverGlobals,puVar6,&local_168,&local_1c0);
      if (iVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return iVar2;
        }
        uVar10 = 0x29;
      }
      else {
        puVar9 = &GUID_GPIOBUTTONS_LAPTOPSLATE_INTERFACE;
        if (param_2 != 1) {
          puVar9 = &GUID_GPIOBUTTONS_DOCKMODE_INTERFACE;
        }
        puVar6 = local_1d8;
        iVar2 = (**(code **)(WdfFunctions_01015 + 0x268))(WdfDriverGlobals,local_1d8,puVar9,0);
        if (iVar2 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return iVar2;
          }
          uVar10 = 0x2a;
        }
        else {
          puVar6 = &local_1c0;
          local_190 = (undefined *)0x0;
          local_1b0 = 0;
          uStack_198 = 0;
          local_1a0 = local_1d8;
          pcStack_1b8 = (code *)0x0;
          local_1c0 = 0x38;
          uStack_1a8 = 0x100000001;
          iVar2 = (**(code **)(WdfFunctions_01015 + 0x9d8))(WdfDriverGlobals,puVar6,piVar3 + 0x16);
          if (-1 < iVar2) {
            Indicator_UpdateRegistryValue(piVar3);
            return iVar2;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return iVar2;
          }
          uVar10 = 0x2b;
        }
      }
    }
    uVar5 = *(undefined8 *)(piVar3 + 4);
  }
  WPP_RECORDER_SF_d(uVar5,puVar6,4,uVar10,&WPP_c6cd92e4efb638f901d990db7ac3a788_Traceguids,
                    (char)iVar2);
  return iVar2;
}



===== Indicator_EvtDeviceCleanupCallback @ 1c000f830 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Indicator_EvtDeviceCleanupCallback(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_INDICATOR_CONTEXT_TYPE_INFO_1c0009018);
  if (*(longlong *)(lVar1 + 0x10) != 0) {
    imp_WppRecorderLogDelete(WPP_GLOBAL_Control);
    *(undefined8 *)(lVar1 + 0x10) = 0;
  }
  return;
}



===== Indicator_EvtDevicePrepareHardware @ 1c000f890 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int Indicator_EvtDevicePrepareHardware(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  byte *pbVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  undefined2 uVar7;
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  undefined8 *local_48;
  code *local_40;
  undefined4 *local_38;
  undefined8 local_30;
  byte local_28;
  byte local_26;
  undefined4 local_24;
  byte local_20;
  uint local_1c;
  undefined8 local_18;
  
  local_54 = 0;
  puVar3 = (undefined4 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_INDICATOR_CONTEXT_TYPE_INFO_1c0009018);
  puVar3[7] = 0;
  *(undefined8 *)(puVar3 + 0xc) = 0;
  puVar3[6] = 0;
  puVar3[0x12] = 0;
  *(undefined1 *)(puVar3 + 0xe) = 1;
  uVar5 = param_3;
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x980))(WdfDriverGlobals);
  if (uVar1 < 2) {
    if (uVar1 == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(puVar3 + 4),4,4,0x1c,
                         &WPP_c6cd92e4efb638f901d990db7ac3a788_Traceguids);
      }
      return 0;
    }
    pbVar4 = (byte *)(**(code **)(WdfFunctions_01015 + 0x988))(WdfDriverGlobals,param_3,0);
    uVar1 = (uint)*pbVar4;
    if (*pbVar4 == 2) {
      puVar6 = (undefined8 *)0x0;
      memset(&local_58,0,0x50);
      local_58 = 1;
      local_50 = *(undefined8 *)(puVar3 + 2);
      local_30 = 0;
      local_40 = Indicator_Isr;
      local_24 = *(undefined4 *)(pbVar4 + 8);
      local_20 = pbVar4[4];
      local_28 = pbVar4[4];
      local_18 = *(undefined8 *)(pbVar4 + 0xc);
      local_26 = pbVar4[1];
      local_1c = pbVar4[2] & 1;
      local_48 = (undefined8 *)(puVar3 + 0xc);
      local_38 = puVar3;
      iVar2 = IoConnectInterruptEx(&local_58);
      if (iVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return iVar2;
        }
        uVar7 = 0x1e;
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_L(*(undefined8 *)(puVar3 + 4),puVar6,4,0x1f,
                            &WPP_c6cd92e4efb638f901d990db7ac3a788_Traceguids,(char)*puVar3);
        }
        puVar6 = &GUID_LOW_POWER_EPOCH;
        iVar2 = PoRegisterPowerSettingCallback
                          (0,&GUID_LOW_POWER_EPOCH,Indicator_PowerSettingCallback,puVar3,
                           puVar3 + 0x10);
        if (-1 < iVar2) {
          return iVar2;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return iVar2;
        }
        uVar7 = 0x20;
      }
      WPP_RECORDER_SF_d(*(undefined8 *)(puVar3 + 4),puVar6,4,uVar7,
                        &WPP_c6cd92e4efb638f901d990db7ac3a788_Traceguids,(char)iVar2);
      return iVar2;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3fffffff;
    }
    uVar7 = 0x1d;
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3fffffff;
    }
    uVar7 = 0x1b;
    param_3 = uVar5;
  }
  WPP_RECORDER_SF_Dd(*(undefined8 *)(puVar3 + 4),param_3,4,uVar7,
                     &WPP_c6cd92e4efb638f901d990db7ac3a788_Traceguids,(char)uVar1,1);
  return -0x3fffffff;
}



===== Indicator_EvtDeviceReleaseHardware @ 1c000fb40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 Indicator_EvtDeviceReleaseHardware(undefined8 param_1)

{
  undefined4 *puVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined8 local_10;
  
  local_14 = 0;
  puVar1 = (undefined4 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_INDICATOR_CONTEXT_TYPE_INFO_1c0009018);
  if (*(longlong *)(puVar1 + 0xc) != 0) {
    if (*(longlong *)(puVar1 + 0x10) != 0) {
      PoUnregisterPowerSettingCallback();
      *(undefined8 *)(puVar1 + 0x10) = 0;
    }
    local_18 = 1;
    local_10 = *(undefined8 *)(puVar1 + 0xc);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_L(*(undefined8 *)(puVar1 + 4),param_1,4,0x21,
                        &WPP_c6cd92e4efb638f901d990db7ac3a788_Traceguids,(char)*puVar1);
    }
    IoDisconnectInterruptEx(&local_18);
    *(undefined8 *)(puVar1 + 0xc) = 0;
    *(undefined1 *)(puVar1 + 0xe) = 0;
  }
  return 0;
}



===== Indicator_HandleStateChange @ 1c000fc10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Indicator_HandleStateChange(undefined8 param_1)

{
  uint uVar1;
  int *piVar2;
  undefined8 uVar3;
  int iVar4;
  int *piVar5;
  
  uVar3 = (**(code **)(WdfFunctions_01015 + 0xbe8))(WdfDriverGlobals,param_1);
  piVar2 = (int *)(**(code **)(WdfFunctions_01015 + 0x650))
                            (WdfDriverGlobals,uVar3,PTR__WDF_INDICATOR_CONTEXT_TYPE_INFO_1c0009018);
  while( true ) {
    LOCK();
    iVar4 = piVar2[6];
    piVar2[6] = 0;
    UNLOCK();
    if (0 < iVar4) {
      uVar1 = piVar2[0x12];
      do {
        iVar4 = iVar4 + -1;
        uVar1 = (uint)(uVar1 == 0);
      } while (0 < iVar4);
      piVar2[0x12] = uVar1;
    }
    Indicator_UpdateRegistryValue(piVar2);
    piVar5 = piVar2;
    Indicator_ReleaseUpdateLock((longlong)piVar2);
    if (piVar2[6] == 0) break;
    uVar3 = Indicator_TryAcquireUpdateLock((longlong)piVar5);
    if ((char)uVar3 == '\0') {
      return;
    }
  }
  return;
}



===== Indicator_UpdateRegistryValue @ 1c000fca4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001c000ff7c) */

void Indicator_UpdateRegistryValue(int *param_1)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined *puVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined2 uVar8;
  undefined1 auStackY_188 [32];
  undefined8 local_148;
  undefined8 local_140;
  wchar_t *local_138;
  undefined8 local_130;
  wchar_t *local_128;
  undefined8 local_120;
  wchar_t *local_118;
  wchar_t local_110 [16];
  wchar_t local_f0 [28];
  wchar_t local_b8 [72];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_188;
  local_148 = 0;
  local_140 = 0x860084;
  local_130 = 0x2a0028;
  local_120 = 0x1e001c;
  uVar1 = param_1[0x12];
  puVar7 = &local_140;
  builtin_wcsncpy(local_b8,
                  L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\PriorityControl",0x43);
  builtin_wcsncpy(local_f0,L"ConvertibleSlateMode",0x15);
  local_138 = local_b8;
  uVar4 = 0;
  local_128 = local_f0;
  builtin_wcsncpy(local_110,L"SystemDockMode",0xf);
  local_118 = local_110;
  uVar3 = WdfDriverGlobals;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x728))();
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000ff72;
    uVar8 = 0x10;
    local_148 = uVar4;
  }
  else {
    if (*param_1 == 1) {
      puVar6 = &local_130;
      if ((Microsoft_Windows_GPIOButtonsEnableBits & 1) != 0) {
        puVar5 = &ConvertibleStateDPC;
LAB_1c000fe55:
        McTemplateK0q_EtwWriteTransfer(uVar3,puVar5,puVar7,(ulonglong)uVar1);
      }
    }
    else {
      puVar6 = &local_120;
      if ((Microsoft_Windows_GPIOButtonsEnableBits & 1) != 0) {
        puVar5 = &DockStateDPC;
        goto LAB_1c000fe55;
      }
    }
    uVar3 = local_148;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x7b0))(WdfDriverGlobals,0,puVar6,uVar1);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000ff72;
      uVar8 = 0x11;
      local_148 = uVar3;
    }
    else {
      uVar3 = (**(code **)(WdfFunctions_01015 + 0x740))(WdfDriverGlobals);
      iVar2 = ZwFlushKey(uVar3);
      if (-1 < iVar2) {
        if (*param_1 == 1) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1c000ff72;
          uVar8 = 0x13;
        }
        else {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1c000ff72;
          uVar8 = 0x14;
        }
        WPP_RECORDER_SF_LL(*(undefined8 *)(param_1 + 4),local_148,4,uVar8,
                           &WPP_c6cd92e4efb638f901d990db7ac3a788_Traceguids,(char)*param_1,
                           (char)uVar1);
        goto LAB_1c000ff72;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000ff72;
      uVar8 = 0x12;
    }
  }
  WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 4),local_148,4,uVar8,
                    &WPP_c6cd92e4efb638f901d990db7ac3a788_Traceguids,(char)iVar2);
LAB_1c000ff72:
  if ((iVar2 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_LD(*(undefined8 *)(param_1 + 4));
  }
  return;
}



===== CancelTimerCallbacksAndDeleteTimer @ 1c000ffe4 =====

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



===== CreateTlgAggregateSession @ 1c0010074 =====

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



===== DestroyAggregateSession @ 1c00101cc =====

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



===== FlushEventEntryList @ 1c0010218 =====

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



===== LookUpTableFlushComplete @ 1c00102b8 =====

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
      if (((5 < DAT_1c0009110) && ((_DAT_1c0009120 & 0x200000000000) != 0)) &&
         ((DAT_1c0009128 & 0x200000000000) == DAT_1c0009128)) {
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
                  (p_Var5,&DAT_1c0007df4,(_GUID *)(ulonglong)uVar4,(_GUID *)(ulonglong)uVar3,
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



===== LookUpTableFlushPartial @ 1c00106a0 =====

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



===== TlgAggregateInternalFlushWorkItemRoutineKernelMode @ 1c0010750 =====

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



===== TlgAggregateInternalProviderCallback @ 1c00107e0 =====

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
     (cVar1 = ExTryAcquirePushLockExclusiveEx(&DAT_1c00094b0,0), cVar1 != '\0')) {
    for (lVar2 = DAT_1c00094b8; lVar2 != 0; lVar2 = *(longlong *)(lVar2 + 0x160)) {
      LookUpTableFlushComplete(lVar2);
    }
    ExReleasePushLockExclusiveEx(&DAT_1c00094b0,0);
  }
  return;
}



===== TlgAggregateInternalRegisteredProviderEtwCallback @ 1c0010850 =====

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



===== TlgRegisterAggregateProvider @ 1c00108cc =====

void TlgRegisterAggregateProvider(void)

{
  TlgRegisterAggregateProviderEx();
  return;
}



===== TlgRegisterAggregateProviderEx @ 1c00108e4 =====

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
    iVar1 = TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(0x1c0009098,0,0);
  }
  else {
    *(undefined8 *)((longlong)pvVar2 + 0x148) = 0;
    *(undefined8 *)((longlong)pvVar2 + 0x150) = 0;
    local_38[0] = 0;
    *(undefined4 **)((longlong)pvVar2 + 0x158) = &DAT_1c0009098;
    *(undefined1 *)((longlong)pvVar2 + 0x175) = 0;
    local_28 = *(undefined8 *)(PTR_DAT_1c00090a0 + -0x10);
    uStack_20 = *(undefined8 *)(PTR_DAT_1c00090a0 + -8);
    local_30 = (ulonglong)pvVar2 >> 4;
    RunningHash(local_38,(longlong)&local_28,0x10);
    RunningHash(local_38,(longlong)&local_30,8);
    FinishHash((int *)local_38);
    *(uint *)((longlong)pvVar2 + 0x170) = local_38[0] % 600000 + 600000;
    iVar1 = TraceLoggingRegisterEx_EtwRegister_EtwSetInformation
                      (0x1c0009098,TlgAggregateInternalRegisteredProviderEtwCallback,pvVar2);
    if (iVar1 < 0) {
      DAT_1c00090c0 = 0;
      DestroyAggregateSession((longlong)pvVar2);
    }
    else {
      ExAcquirePushLockExclusiveEx(&DAT_1c00094b0,0);
      if (DAT_1c00094b8 == 0) {
        TraceLoggingRegisterEx_EtwRegister_EtwSetInformation
                  (0x1c0009110,TlgAggregateInternalProviderCallback,0);
      }
      plVar4 = &DAT_1c00094b8;
      lVar3 = DAT_1c00094b8;
      while (lVar3 != 0) {
        if (*(undefined4 **)(lVar3 + 0x158) == &DAT_1c0009098) goto LAB_1c0010a40;
        plVar4 = (longlong *)(lVar3 + 0x160);
        lVar3 = *plVar4;
      }
      *plVar4 = (longlong)pvVar2;
LAB_1c0010a40:
      ExReleasePushLockExclusiveEx(&DAT_1c00094b0,0);
      iVar1 = 0;
    }
  }
  return iVar1;
}



===== TraceLoggingRegisterEx_EtwRegister_EtwSetInformation @ 1c0010a90 =====

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
  *(undefined8 *)(puVar7 + -8) = 0x1c0010af1;
  iVar6 = EtwRegister(puVar7 + 0x20,_tlgEnableCallback,param_1,plVar1);
  if (iVar6 == 0) {
    puVar4 = *(undefined2 **)(param_1 + 8);
    lVar3 = *plVar1;
    uVar2 = *puVar4;
    *(undefined8 *)(puVar7 + -8) = 0x1c0010b11;
    EtwSetInformation(lVar3,2,puVar4,uVar2);
  }
  *(undefined8 *)(puVar7 + -8) = 0x1c0010b25;
  return iVar6;
}



===== _tlgEnableCallback @ 1c0010b40 =====

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



===== __security_init_cookie @ 1c0011008 =====

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



===== DriverEntry @ 1c001103c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined1 auStack_d8 [32];
  undefined8 *local_b8;
  undefined8 *local_b0;
  undefined8 local_98;
  undefined8 local_90;
  code *pcStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 local_58;
  code *local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_d8;
  local_58 = 0x20;
  local_60 = 0;
  local_b0 = &local_98;
  pcStack_88 = DriverCleanup;
  local_80 = 0;
  local_50 = GPIO_EvtDeviceAdd;
  local_b8 = &local_58;
  local_38 = 0;
  uStack_30 = 0;
  local_90 = 0x38;
  local_70 = 0;
  uStack_68 = 0;
  local_98 = 0;
  uStack_78 = 0x100000001;
  local_48 = 0;
  uStack_40 = 0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x3a0))(WdfDriverGlobals,param_1,param_2,&local_90);
  if (-1 < iVar1) {
    McGenEventRegister_EtwRegister();
    EtwSetInformation(Microsoft_Windows_GPIOButtons_Context,2,
                      &`EnableManifestedProviderForMicrosoftTelemetry'::__l2::Traits,0x16);
    _WPP_MAIN_CB = 0;
    DAT_1c00094e8 = &WPP_ThisDir_CTLGUID_MSGPIOWIN32;
    DAT_1c00094f0 = 0;
    _DAT_1c0009500 = 0;
    _DAT_1c0009508 = 1;
    _DAT_1c0009520 = 0;
    _DAT_1c0009528 = 0;
    WppLoadTracingSupport();
    _DAT_1c0009500 = 0;
    WppInitKm(param_1,param_2);
    TlgRegisterAggregateProvider();
    uStack_30 = 0x200000002;
    local_38 = CONCAT35(local_38._5_3_,0x10);
    imp_WppRecorderConfigure(WPP_GLOBAL_Control,&local_38);
  }
  return iVar1;
}


