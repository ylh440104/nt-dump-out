
===== __report_gsfailure @ 1c0001010 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== WPP_SF_ @ 1c0001020 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,0);
  return;
}



===== WPP_SF_d @ 1c000104c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_d(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_44f36d42aea93cdc74daf49813a5f4b0_Traceguids,0x11,local_res20,4,0);
  return;
}



===== WPP_SF_q @ 1c0001098 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,0);
  return;
}



===== WPP_SF_qd @ 1c00010dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_44f36d42aea93cdc74daf49813a5f4b0_Traceguids,0xb,&local_res20,8,
             &param_5,4,0);
  return;
}



===== WPP_SF_qqL @ 1c0001138 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqL(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_44f36d42aea93cdc74daf49813a5f4b0_Traceguids,0xf,&local_res20,8,
             &param_5,8,&param_6,4,0);
  return;
}



===== WPP_SF_qqd @ 1c00011a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_44f36d42aea93cdc74daf49813a5f4b0_Traceguids,0xc,&local_res20,8,
             &param_5,8,&param_6,4,0);
  return;
}



===== WppClassicProviderCallback @ 1c0001210 =====

void WppClassicProviderCallback
               (undefined8 param_1,byte param_2,undefined8 *param_3,longlong param_4)

{
  undefined8 uVar1;
  
  if (param_2 < 2) {
    uVar1 = 0;
    if (param_2 == 0) {
      *(undefined1 *)(param_4 + 0x29) = 0;
      *(undefined4 *)(param_4 + 0x2c) = 0;
    }
    else {
      *(undefined4 *)(param_4 + 0x2c) = *(undefined4 *)((longlong)param_3 + 4);
      *(undefined1 *)(param_4 + 0x29) = *(undefined1 *)((longlong)param_3 + 2);
      uVar1 = *param_3;
    }
    *(undefined8 *)(param_4 + 0x18) = uVar1;
  }
  return;
}



===== ndisVBusNmrProviderCleanupBindingContext @ 1c0001250 =====

void ndisVBusNmrProviderCleanupBindingContext(void)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
            &WPP_44f36d42aea93cdc74daf49813a5f4b0_Traceguids);
  }
  return;
}



===== ndisVBusNmrProviderDetachClient @ 1c00012a0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 ndisVBusNmrProviderDetachClient(void)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
             &WPP_44f36d42aea93cdc74daf49813a5f4b0_Traceguids,DAT_1c0005480);
  }
  _DAT_1c0005490 = 0;
  DAT_1c0005480 = 0;
  DAT_1c0005488 = 0;
  return 0;
}



===== RtlUnicodeStringCopy @ 1c0001304 =====

ulonglong RtlUnicodeStringCopy(ushort *param_1,ushort *param_2)

{
  ulonglong uVar1;
  ushort *puVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  ulonglong uVar5;
  undefined2 *puVar6;
  ulonglong uVar7;
  longlong lVar8;
  
  puVar2 = param_1;
  uVar1 = RtlUnicodeStringValidateWorker(param_1);
  puVar4 = (undefined2 *)0x0;
  if (((int)uVar1 < 0) || (puVar2 == (ushort *)0x0)) {
    lVar8 = 0;
    uVar5 = 0;
    if ((int)uVar1 < 0) {
      return uVar1 & 0xffffffff;
    }
  }
  else {
    lVar8 = *(longlong *)(puVar2 + 4);
    uVar5 = (ulonglong)(puVar2[1] >> 1);
  }
  uVar1 = RtlUnicodeStringValidateWorker(param_2);
  uVar7 = uVar1 & 0xffffffff;
  if (((int)uVar1 < 0) || (param_2 == (ushort *)0x0)) {
    puVar3 = puVar4;
    puVar6 = puVar4;
    if ((int)uVar1 < 0) goto LAB_1c00013af;
  }
  else {
    puVar3 = (undefined2 *)(ulonglong)(*param_2 >> 1);
    puVar6 = *(undefined2 **)(param_2 + 4);
  }
  uVar7 = (ulonglong)puVar4 & 0xffffffff;
  if (uVar5 != 0) {
    lVar8 = lVar8 - (longlong)puVar6;
    do {
      if (puVar3 == (undefined2 *)0x0) goto LAB_1c00013af;
      puVar3 = (undefined2 *)((longlong)puVar3 + -1);
      *(undefined2 *)(lVar8 + (longlong)puVar6) = *puVar6;
      puVar4 = (undefined2 *)((longlong)puVar4 + 1);
      puVar6 = puVar6 + 1;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  if (puVar3 != (undefined2 *)0x0) {
    uVar7 = 0x80000005;
  }
LAB_1c00013af:
  *param_1 = (short)puVar4 * 2;
  return uVar7;
}



===== RtlUnicodeStringValidateWorker @ 1c00013d8 =====

undefined8 RtlUnicodeStringValidateWorker(ushort *param_1)

{
  ushort uVar1;
  ushort uVar2;
  undefined8 uVar3;
  
  uVar1 = *param_1;
  uVar3 = 0;
  if ((((((uVar1 & 1) != 0) || (uVar2 = param_1[1], (uVar2 & 1) != 0)) || (uVar2 < uVar1)) ||
      (uVar2 == 0xffff)) || ((*(longlong *)(param_1 + 4) == 0 && ((uVar1 != 0 || (uVar2 != 0)))))) {
    uVar3 = 0xc000000d;
  }
  return uVar3;
}



===== WPP_SF_L @ 1c0001420 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_L(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_21fc4829cf4b31b490700338aca4cbb2_Traceguids,param_2,local_res20,4,0);
  return;
}



===== WPP_SF_qD @ 1c0001468 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_21fc4829cf4b31b490700338aca4cbb2_Traceguids,param_2,&local_res20,8,
             &param_5,4,0);
  return;
}



===== WPP_SF_qq @ 1c00014c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_21fc4829cf4b31b490700338aca4cbb2_Traceguids,param_2,&local_res20,8,
             &param_5,8,0);
  return;
}



===== WPP_SF_qqD @ 1c0001518 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_21fc4829cf4b31b490700338aca4cbb2_Traceguids,0x1e,&local_res20,8,
             &param_5,8,&param_6,4,0);
  return;
}



===== _guard_check_icall @ 1c0001580 =====

void _guard_check_icall(void)

{
  return;
}



===== ndisVBusDeepCopyUnicodeString @ 1c000158c =====

undefined8 ndisVBusDeepCopyUnicodeString(ushort *param_1,ushort *param_2)

{
  ushort uVar1;
  void *_Dst;
  undefined8 uVar2;
  
  param_1[0] = 0;
  param_1[1] = 0;
  _Dst = (void *)ExAllocatePool2(0x40,param_2[1],0x6276444e);
  *(void **)(param_1 + 4) = _Dst;
  if (_Dst == (void *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
              &WPP_21fc4829cf4b31b490700338aca4cbb2_Traceguids);
    }
    uVar2 = 0xc000009a;
  }
  else {
    uVar1 = param_2[1];
    param_1[1] = uVar1;
    memset(_Dst,0,(ulonglong)uVar1);
    memcpy(*(void **)(param_1 + 4),*(void **)(param_2 + 4),(ulonglong)*param_2);
    *param_1 = *param_2;
    uVar2 = 0;
  }
  return uVar2;
}



===== ndisVBusEvtChildListIdDescrCleanup @ 1c0001650 =====

void ndisVBusEvtChildListIdDescrCleanup(undefined8 param_1,longlong param_2)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
             &WPP_21fc4829cf4b31b490700338aca4cbb2_Traceguids,param_2);
  }
  if (*(longlong *)(param_2 + 0x10) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x10),0);
    *(undefined8 *)(param_2 + 0x10) = 0;
  }
  if (*(longlong *)(param_2 + 0x20) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x20),0);
    *(undefined8 *)(param_2 + 0x20) = 0;
  }
  if (*(longlong *)(param_2 + 0x30) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x30),0);
    *(undefined8 *)(param_2 + 0x30) = 0;
  }
  return;
}



===== ndisVBusEvtChildListIdDescrCompare @ 1c0001700 =====

longlong ndisVBusEvtChildListIdDescrCompare(undefined8 param_1,longlong param_2,longlong param_3)

{
  undefined **ppuVar1;
  uint7 uVar2;
  longlong lVar3;
  
  ppuVar1 = &WPP_GLOBAL_Control;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (ppuVar1 = (undefined **)(ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
      (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    ppuVar1 = (undefined **)
              WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,param_3,param_2,
                        (char)param_3);
  }
  uVar2 = (uint7)((ulonglong)ppuVar1 >> 8);
  if (param_2 == param_3) {
LAB_1c000174b:
    lVar3 = CONCAT71(uVar2,1);
  }
  else {
    if ((param_2 != 0) && (param_3 != 0)) {
      lVar3 = *(longlong *)(param_2 + 0x38) - *(longlong *)(param_3 + 0x38);
      if (lVar3 == 0) {
        lVar3 = *(longlong *)(param_2 + 0x40) - *(longlong *)(param_3 + 0x40);
      }
      if (lVar3 == 0) goto LAB_1c000174b;
    }
    lVar3 = (ulonglong)uVar2 << 8;
  }
  return lVar3;
}



===== ndisVBusEvtChildListIdDescrDuplicate @ 1c0001790 =====

ulonglong ndisVBusEvtChildListIdDescrDuplicate
                    (undefined8 param_1,longlong param_2,undefined4 *param_3)

{
  ulonglong uVar1;
  ushort *puVar2;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,param_3,param_2,(char)param_3);
  }
  puVar2 = (ushort *)(param_2 + 0x28);
  uVar1 = ndisVBusVirtMiniInitializeData
                    ((ushort *)(param_2 + 8),(ushort *)(param_2 + 0x18),puVar2,
                     (undefined8 *)(param_2 + 0x38),param_3);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),
               (ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),puVar2,param_2,(char)param_3,
               (char)uVar1);
  }
  return uVar1 & 0xffffffff;
}



===== ndisVBusGetLocationString @ 1c0001850 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 ndisVBusGetLocationString(undefined8 param_1,undefined8 *param_2)

{
  ushort *puVar1;
  undefined8 uVar2;
  void *_Dst;
  
  *param_2 = 0;
  puVar1 = (ushort *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_NDIS_VBUS_VIRTMINI_DEVICE_TYPE_INFO_1c0005018);
  if (*(longlong *)(puVar1 + 4) == 0) {
    uVar2 = 0xc00000bb;
  }
  else {
    _Dst = (void *)ExAllocatePool2(0x40,(ulonglong)*puVar1 + 4,0x6276444e);
    if (_Dst == (void *)0x0) {
      uVar2 = 0xc000009a;
    }
    else {
      memcpy(_Dst,*(void **)(puVar1 + 4),(ulonglong)*puVar1);
      *(undefined2 *)((longlong)_Dst + (ulonglong)(*puVar1 >> 1) * 2) = 0;
      *(undefined2 *)((longlong)_Dst + (ulonglong)(*puVar1 >> 1) * 2 + 2) = 0;
      uVar2 = 0x120;
      *param_2 = _Dst;
    }
  }
  return uVar2;
}



===== ndisVBusPdoEvtCleanupCallback @ 1c0001920 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ndisVBusPdoEvtCleanupCallback(undefined8 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_NDIS_VBUS_VIRTMINI_DEVICE_TYPE_INFO_1c0005018);
  if (*(longlong *)(puVar1 + 2) != 0) {
    ExFreePoolWithTag(*(longlong *)(puVar1 + 2),0);
    *(undefined8 *)(puVar1 + 2) = 0;
    *puVar1 = 0;
  }
  return;
}



===== ndisVBusVirtMiniInitializeData @ 1c0001984 =====

ulonglong ndisVBusVirtMiniInitializeData
                    (ushort *param_1,ushort *param_2,ushort *param_3,undefined8 *param_4,
                    undefined4 *param_5)

{
  undefined8 uVar1;
  char cVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined *puVar6;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_21fc4829cf4b31b490700338aca4cbb2_Traceguids);
  }
  puVar6 = (undefined *)0x48;
  memset(param_5,0,0x48);
  *param_5 = 0x48;
  uVar4 = ndisVBusDeepCopyUnicodeString((ushort *)(param_5 + 2),param_1);
  uVar5 = uVar4 & 0xffffffff;
  if (-1 < (int)uVar4) {
    uVar4 = ndisVBusDeepCopyUnicodeString((ushort *)(param_5 + 6),param_2);
    uVar5 = uVar4 & 0xffffffff;
    if (-1 < (int)uVar4) {
      if ((param_3 != (ushort *)0x0) && (*param_3 != 0)) {
        uVar4 = ndisVBusDeepCopyUnicodeString((ushort *)(param_5 + 10),param_3);
        uVar5 = uVar4 & 0xffffffff;
        if ((int)uVar4 < 0) goto LAB_1c0001adb;
      }
      if (param_4 == (undefined8 *)0x0) {
        cVar2 = KeGetCurrentIrql();
        if (cVar2 != '\0') {
          uVar5 = 0xc0000005;
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            puVar6 = &WPP_21fc4829cf4b31b490700338aca4cbb2_Traceguids;
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                    &WPP_21fc4829cf4b31b490700338aca4cbb2_Traceguids);
          }
          goto LAB_1c0001adb;
        }
        uVar3 = RtlGUIDFromString(param_5 + 6,param_5 + 0xe);
        uVar5 = (ulonglong)uVar3;
      }
      else {
        uVar1 = param_4[1];
        *(undefined8 *)(param_5 + 0xe) = *param_4;
        *(undefined8 *)(param_5 + 0x10) = uVar1;
        uVar3 = (uint)uVar5;
      }
      if (-1 < (int)uVar3) goto LAB_1c0001aed;
    }
  }
LAB_1c0001adb:
  ndisVBusEvtChildListIdDescrCleanup(*DAT_1c0005498,(longlong)param_5);
LAB_1c0001aed:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,puVar6,(int)uVar5);
  }
  return uVar5;
}



===== FxStubDriverUnloadCommon @ 1c0001b40 =====

/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  _WDF_BIND_INFO *in_RCX;
  
  FxStubUnbindClasses(in_RCX);
  WdfVersionUnbind(&DAT_1c00053d0,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== entry @ 1c0001b80 =====

void entry(_WDF_BIND_INFO *param_1,undefined8 param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 1c0001bb4 =====

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
    _DAT_1c00053d0 = 0x2080000;
    _DAT_1c00053d8 = &DAT_1c00051c0;
    RtlCopyUnicodeString(&DAT_1c00053d0);
    p_Var3 = param_1;
    iVar1 = WdfVersionBind(param_1,&DAT_1c00053d0,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < iVar1) {
      iVar1 = FxStubBindClasses(p_Var3);
      if ((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) {
        iVar1 = DriverEntry((ulonglong)param_1,param_2);
        if (-1 < iVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_1c00053c8 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",iVar1,&DAT_1c00053d0);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c0005158 != &__KMDF_CLASS_BIND_START) {
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



===== FxStubDriverUnload @ 1c0001d40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_1c00053c8 != (code *)0x0) && (DAT_1c00053c8 != FxStubDriverUnload)) {
    (*DAT_1c00053c8)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 1c0001d74 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c0001d99) */
/* long __cdecl FxStubBindClasses(struct _WDF_BIND_INFO * __ptr64) */

long __cdecl FxStubBindClasses(_WDF_BIND_INFO *param_1)

{
  int iVar1;
  uint *puVar2;
  void **ppvVar3;
  
  iVar1 = 0;
  ppvVar3 = &__KMDF_CLASS_BIND_END;
  while( true ) {
    puVar2 = (uint *)FxGetNextClassBindInfo((longlong *)ppvVar3,(longlong *)&__KMDF_CLASS_BIND_END);
    if (puVar2 == (uint *)0x0) {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    if ((uint *)0x1c000514f < puVar2) break;
    PTR___KMDF_CLASS_BIND_START_1c0005158 = (undefined *)puVar2;
    if (*(code **)(puVar2 + 0xe) == (code *)0x0) {
      iVar1 = WdfVersionBindClass(&WdfBindInfo,WdfDriverGlobals,puVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: VersionBindClass WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,puVar2,*(undefined8 *)(puVar2 + 2),iVar1);
        return iVar1;
      }
    }
    else {
      iVar1 = (**(code **)(puVar2 + 0xe))
                        (WdfVersionBindClass_exref,&WdfBindInfo,WdfDriverGlobals,puVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: ClientBindClass %p, WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,*(undefined8 *)(puVar2 + 0xe),puVar2,*(undefined8 *)(puVar2 + 2),iVar1);
        return iVar1;
      }
    }
    ppvVar3 = (void **)((longlong)puVar2 + (ulonglong)*puVar2);
  }
  return iVar1;
}



===== FxStubUnbindClasses @ 1c0001ed4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubUnbindClasses(struct _WDF_BIND_INFO * __ptr64) */

void __cdecl FxStubUnbindClasses(_WDF_BIND_INFO *param_1)

{
  uint *puVar1;
  uint *puVar2;
  void **ppvVar3;
  
  ppvVar3 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c0005158 != &__KMDF_CLASS_BIND_START) {
    puVar1 = (uint *)(PTR___KMDF_CLASS_BIND_START_1c0005158 + 0x50);
    while (puVar2 = (uint *)FxGetNextClassBindInfo((longlong *)ppvVar3,(longlong *)puVar1),
          puVar2 != (uint *)0x0) {
      if (puVar1 <= puVar2) {
        return;
      }
      if (*(code **)(puVar2 + 0x10) == (code *)0x0) {
        WdfVersionUnbindClass(&WdfBindInfo,WdfDriverGlobals,puVar2);
      }
      else {
        (**(code **)(puVar2 + 0x10))
                  (WdfVersionUnbindClass_exref,&WdfBindInfo,WdfDriverGlobals,puVar2);
      }
      ppvVar3 = (void **)((longlong)puVar2 + (ulonglong)*puVar2);
    }
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
  return;
}



===== FxGetNextClassBindInfo @ 1c0001f90 =====

longlong * FxGetNextClassBindInfo(longlong *param_1,longlong *param_2)

{
  longlong *plVar1;
  
  plVar1 = param_1 + 1;
  for (; (plVar1 <= param_2 && (*param_1 == 0)); param_1 = param_1 + 1) {
    plVar1 = param_1 + 2;
  }
  if (param_2 <= param_1) {
    return param_2;
  }
  if (param_2 < param_1 + 10) {
    return (longlong *)0x0;
  }
  plVar1 = (longlong *)0x0;
  if ((int)*param_1 == 0x50) {
    plVar1 = param_1;
  }
  return plVar1;
}



===== FxStubInitTypes @ 1c0001fd8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c0001ff5) */
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
    if ((void **)0x1c000516f < ppvVar2) break;
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



===== __GSHandlerCheck @ 1c00020a8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c00020cc =====

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



===== __cpu_features_init @ 1c0002140 =====

/* WARNING: Removing unreachable block (ram,0x0001c00021aa) */
/* WARNING: Removing unreachable block (ram,0x0001c0002159) */
/* WARNING: Removing unreachable block (ram,0x0001c000214a) */

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



===== __security_check_cookie @ 1c0002210 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0002250 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0002280 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0002280. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c00022b0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c0002300 =====

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



===== memset @ 1c0002600 =====

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



===== __memset_repmovs @ 1c0002740 =====

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



===== __memset_query @ 1c00027c0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0002840 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0002980 =====

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



===== __memset_spec_plain @ 1c0002a00 =====

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



===== WppCleanupKm @ 1c0008008 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WppCleanupKm(void)

{
  undefined *puVar1;
  
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    puVar1 = WPP_GLOBAL_Control;
    if (WPPTraceSuite == 4) {
      for (; puVar1 != (undefined *)0x0; puVar1 = *(undefined **)(puVar1 + 0x10)) {
        if (*(longlong *)(puVar1 + 0x38) != 0) {
          (*pfnEtwUnregister)();
          *(undefined8 *)(puVar1 + 0x38) = 0;
        }
      }
    }
    else if (WPPTraceSuite == 2) {
      IoWMIRegistrationControl(WPP_GLOBAL_Control,0x80000002);
    }
    WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
  }
  return;
}



===== WppLoadTracingSupport @ 1c0008088 =====

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



===== WppTraceCallback @ 1c00081d0 =====

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



===== ndisVBusDeviceRemove @ 1c0008460 =====

void ndisVBusDeviceRemove(undefined8 param_1)

{
  int iVar1;
  
  if (DAT_1c0005468 != 0) {
    iVar1 = NmrDeregisterProvider();
    if (iVar1 == 0x103) {
      NmrWaitForProviderDeregisterComplete(DAT_1c0005468);
    }
    DAT_1c0005468 = 0;
  }
  DAT_1c0005498 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
             &WPP_44f36d42aea93cdc74daf49813a5f4b0_Traceguids,param_1);
  }
  return;
}



===== ndisVBusDriverUnload @ 1c00084f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ndisVBusDriverUnload(undefined8 param_1)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
             &WPP_44f36d42aea93cdc74daf49813a5f4b0_Traceguids,param_1);
  }
  (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,param_1);
  WppCleanupKm();
  return;
}



===== ndisVBusNmrProviderAttachClient @ 1c0008560 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
ndisVBusNmrProviderAttachClient
          (undefined8 param_1,undefined8 param_2,short *param_3,undefined8 param_4,
          undefined8 param_5,undefined8 *param_6,undefined8 *param_7)

{
  longlong *plVar1;
  longlong lVar2;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
             &WPP_44f36d42aea93cdc74daf49813a5f4b0_Traceguids,param_1);
  }
  if (((DAT_1c0005480 == 0) && (DAT_1c0005488 == 0)) && ((*param_3 == 1 && (param_3[1] == 0x28)))) {
    lVar2 = **(longlong **)(param_3 + 4) + -0x11d48d8b2227e811;
    if (lVar2 == 0) {
      lVar2 = (*(longlong **)(param_3 + 4))[1] + -0x99e71279000adab;
    }
    if (lVar2 == 0) {
      plVar1 = *(longlong **)(param_3 + 8);
      lVar2 = *plVar1 + -0x100000018;
      if ((lVar2 == 0) && (lVar2 = plVar1[1] + -0x11d49b1aeb004a11, lVar2 == 0)) {
        lVar2 = plVar1[2] + 0x43a688fbafffdc6f;
      }
      if (((lVar2 == 0) && (*(int *)(param_3 + 0xc) == 0)) && (*(longlong *)(param_3 + 0x10) == 0))
      {
        _DAT_1c0005490 = param_5;
        DAT_1c0005480 = param_1;
        DAT_1c0005488 = param_4;
        *param_6 = 0;
        *param_7 = &DAT_1c0005470;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                   &WPP_44f36d42aea93cdc74daf49813a5f4b0_Traceguids,param_1);
        }
        return 0;
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
             &WPP_44f36d42aea93cdc74daf49813a5f4b0_Traceguids,param_1);
  }
  return 0xc00002b9;
}



===== ndisVBusEvtChildListCreatePdo @ 1c0008700 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong ndisVBusEvtChildListCreatePdo(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  ushort *puVar1;
  uint uVar2;
  ushort *puVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined2 uVar6;
  ulonglong *puVar7;
  undefined1 auStack_198 [32];
  undefined8 local_168;
  undefined8 local_160;
  undefined8 local_158;
  wchar_t *local_150;
  ulonglong local_148;
  ulonglong *local_140;
  undefined *local_138;
  undefined8 local_130;
  undefined8 local_128;
  ulonglong local_120;
  ulonglong local_118;
  code *local_110;
  undefined8 local_108;
  undefined4 local_100;
  undefined4 local_fc;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined *local_e8;
  ulonglong local_e0;
  undefined8 local_d8;
  code *local_d0;
  code *local_c8;
  code *local_c0;
  undefined4 local_b8;
  undefined8 local_b4;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  wchar_t local_88 [32];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_198;
  builtin_wcsncpy(local_88,L"NDIS Virtual Network Adapter",0x1d);
  local_150 = local_88;
  local_158 = 0x3a0038;
  local_f8 = 0;
  uStack_f0 = 0;
  local_160 = 0;
  local_118 = (ulonglong)(uint)local_118;
  local_108 = 0;
  local_148 = (ulonglong)(uint)local_148;
  local_130 = 0;
  local_120 = local_120 & 0xffffffff00000000;
  local_e0 = (ulonglong)(uint)local_e0;
  local_168 = param_3;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
             &WPP_21fc4829cf4b31b490700338aca4cbb2_Traceguids,param_2);
  }
  (**(code **)(WdfFunctions_01015 + 0x210))(WdfDriverGlobals,local_168,0x12);
  puVar7 = (ulonglong *)(param_2 + 8);
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x6a0))(WdfDriverGlobals,local_168);
  uVar5 = (ulonglong)uVar2;
  if ((int)uVar2 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return uVar5;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return uVar5;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return uVar5;
    }
    uVar6 = 0x16;
  }
  else {
    puVar7 = (ulonglong *)(param_2 + 0x18);
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x6a8))(WdfDriverGlobals,local_168);
    uVar5 = (ulonglong)uVar2;
    if ((int)uVar2 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return uVar5;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
        return uVar5;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return uVar5;
      }
      uVar6 = 0x17;
    }
    else {
      puVar7 = (ulonglong *)(param_2 + 8);
      uVar2 = (**(code **)(WdfFunctions_01015 + 0x6b0))(WdfDriverGlobals,local_168);
      uVar5 = (ulonglong)uVar2;
      if ((int)uVar2 < 0) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return uVar5;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
          return uVar5;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
          return uVar5;
        }
        uVar6 = 0x18;
      }
      else {
        uVar2 = (**(code **)(WdfFunctions_01015 + 0x6c0))
                          (WdfDriverGlobals,local_168,&local_158,param_2 + 0x18);
        uVar5 = (ulonglong)uVar2;
        puVar7 = (ulonglong *)0x409;
        (**(code **)(WdfFunctions_01015 + 0x6c8))(WdfDriverGlobals,local_168);
        if ((int)uVar2 < 0) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return uVar5;
          }
          if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
            return uVar5;
          }
          if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
            return uVar5;
          }
          uVar6 = 0x19;
        }
        else {
          puVar7 = &local_118;
          local_e8 = PTR__WDF_NDIS_VBUS_VIRTMINI_DEVICE_TYPE_INFO_1c0005018;
          local_118 = 0x38;
          local_110 = ndisVBusPdoEvtCleanupCallback;
          local_108 = 0;
          local_f8 = 0;
          uStack_f0 = 0;
          local_100 = 1;
          local_fc = 1;
          uVar2 = (**(code **)(WdfFunctions_01015 + 600))
                            (WdfDriverGlobals,&local_168,puVar7,&local_160);
          uVar5 = (ulonglong)uVar2;
          if ((int)uVar2 < 0) {
            if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
              return uVar5;
            }
            if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
              return uVar5;
            }
            if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
              return uVar5;
            }
            uVar6 = 0x1a;
          }
          else {
            puVar3 = (ushort *)
                     (**(code **)(WdfFunctions_01015 + 0x650))
                               (WdfDriverGlobals,local_160,
                                PTR__WDF_NDIS_VBUS_VIRTMINI_DEVICE_TYPE_INFO_1c0005018);
            if (*(longlong *)(param_2 + 0x30) != 0) {
              puVar1 = (ushort *)(param_2 + 0x28);
              lVar4 = ExAllocatePool2(0x40,*puVar1,0x6276444e);
              *(longlong *)(puVar3 + 4) = lVar4;
              puVar3[1] = *puVar1;
              if (lVar4 == 0) {
                return 0xc000009a;
              }
              uVar5 = RtlUnicodeStringCopy(puVar3,puVar1);
              if ((int)uVar5 < 0) {
                return uVar5;
              }
            }
            local_90 = 0xffffffff;
            local_8c = 0xffffffff;
            local_b8 = 0x30;
            local_b4 = 2;
            local_a8 = 2;
            local_a0 = 2;
            local_98 = 2;
            local_94 = 2;
            local_ac = 0;
            local_9c = 1;
            local_a4 = 1;
            (**(code **)(WdfFunctions_01015 + 0x298))(WdfDriverGlobals,local_160,&local_b8);
            puVar7 = &local_148;
            local_d0 = _guard_check_icall;
            local_c8 = _guard_check_icall;
            local_c0 = ndisVBusGetLocationString;
            local_140 = &local_e0;
            local_138 = &GUID_PNP_LOCATION_INTERFACE;
            local_e0 = 0x10028;
            local_d8 = local_160;
            local_148 = 0x30;
            local_130 = 0;
            local_120 = 0;
            local_128 = 0;
            uVar2 = (**(code **)(WdfFunctions_01015 + 0x720))(WdfDriverGlobals);
            uVar5 = (ulonglong)uVar2;
            if (-1 < (int)uVar2) {
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
                 (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
                         &WPP_21fc4829cf4b31b490700338aca4cbb2_Traceguids,param_2);
              }
              return 0;
            }
            if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
              return uVar5;
            }
            if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
              return uVar5;
            }
            if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
              return uVar5;
            }
            uVar6 = 0x1b;
          }
        }
      }
    }
  }
  WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,puVar7,param_2,(char)uVar5);
  return uVar5;
}



===== ndisVBusVirtMiniAdd @ 1c0008c20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong ndisVBusVirtMiniAdd(ushort *param_1,ushort *param_2,ushort *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  undefined2 uVar3;
  undefined1 auStackY_a8 [32];
  ushort local_78 [2];
  undefined4 local_74;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_74 = 0;
  memset(local_78,0,0x44);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
            &WPP_21fc4829cf4b31b490700338aca4cbb2_Traceguids);
  }
  uVar2 = ndisVBusVirtMiniInitializeData
                    (param_1,param_2,param_3,(undefined8 *)0x0,(undefined4 *)local_78);
  uVar1 = (uint)uVar2;
  uVar2 = uVar2 & 0xffffffff;
  if ((int)uVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1c0008d34;
    uVar3 = 0xe;
  }
  else {
    param_3 = local_78;
    uVar1 = (**(code **)(WdfFunctions_01015 + 0x48))(WdfDriverGlobals,*DAT_1c0005498,param_3,0);
    uVar2 = (ulonglong)uVar1;
    if (((-1 < (int)uVar1) || ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control)) ||
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0 || ((byte)WPP_GLOBAL_Control[0x29] < 2))))
    goto LAB_1c0008d34;
    uVar3 = 0xf;
  }
  WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,param_3,uVar1);
LAB_1c0008d34:
  ndisVBusEvtChildListIdDescrCleanup(*DAT_1c0005498,(longlong)local_78);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,param_3,(int)uVar2);
  }
  return uVar2;
}



===== ndisVBusVirtMiniRemove @ 1c0008da0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong ndisVBusVirtMiniRemove(ushort *param_1,ushort *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  undefined2 uVar3;
  undefined4 *puVar4;
  undefined1 auStackY_98 [32];
  undefined4 local_68;
  undefined4 local_64;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_64 = 0;
  memset(&local_68,0,0x44);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
            &WPP_21fc4829cf4b31b490700338aca4cbb2_Traceguids);
  }
  puVar4 = (undefined4 *)0x0;
  uVar2 = ndisVBusVirtMiniInitializeData(param_1,param_2,(ushort *)0x0,(undefined8 *)0x0,&local_68);
  uVar1 = (uint)uVar2;
  uVar2 = uVar2 & 0xffffffff;
  if ((int)uVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1c0008eb0;
    uVar3 = 0x12;
  }
  else {
    puVar4 = &local_68;
    uVar1 = (**(code **)(WdfFunctions_01015 + 0x50))(WdfDriverGlobals,*DAT_1c0005498);
    uVar2 = (ulonglong)uVar1;
    if (((-1 < (int)uVar1) || ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control)) ||
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0 || ((byte)WPP_GLOBAL_Control[0x29] < 2))))
    goto LAB_1c0008eb0;
    uVar3 = 0x13;
  }
  WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,puVar4,uVar1);
LAB_1c0008eb0:
  ndisVBusEvtChildListIdDescrCleanup(*DAT_1c0005498,(longlong)&local_68);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,puVar4,(int)uVar2);
  }
  return uVar2;
}



===== ndisVBusDeviceAdd @ 1c0008f20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int ndisVBusDeviceAdd(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  ulonglong *puVar3;
  undefined8 *puVar4;
  bool bVar5;
  undefined1 auStackY_128 [32];
  undefined8 local_f8;
  undefined8 local_f0;
  ulonglong local_e8;
  code *local_e0;
  undefined8 local_d8;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined *local_b8;
  undefined8 local_a8;
  undefined8 uStack_a0;
  code *local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  code *pcStack_80;
  code *local_78;
  code *pcStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_128;
  local_e8 = (ulonglong)(uint)local_e8;
  local_d8 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_f0 = 0;
  local_f8 = param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
             &WPP_44f36d42aea93cdc74daf49813a5f4b0_Traceguids,param_1);
  }
  (**(code **)(WdfFunctions_01015 + 0x210))(WdfDriverGlobals,local_f8,0x2a);
  (**(code **)(WdfFunctions_01015 + 0x1f0))(WdfDriverGlobals,local_f8,1);
  uStack_a0 = 0;
  uStack_90 = 0;
  local_98 = ndisVBusEvtChildListCreatePdo;
  local_88 = 0;
  pcStack_80 = ndisVBusEvtChildListIdDescrDuplicate;
  pcStack_70 = ndisVBusEvtChildListIdDescrCompare;
  local_78 = ndisVBusEvtChildListIdDescrCleanup;
  local_68 = 0;
  uStack_60 = 0;
  local_a8 = 0x4800000060;
  local_58 = 0;
  uStack_50 = 0;
  (**(code **)(WdfFunctions_01015 + 0x410))(WdfDriverGlobals,local_f8,&local_a8,0);
  puVar3 = &local_e8;
  local_b8 = PTR__WDF_NDIS_VBUS_BUS_DEVICE_TYPE_INFO_1c0005048;
  local_e8 = 0x38;
  local_e0 = ndisVBusDeviceRemove;
  local_d8 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_cc = 1;
  local_d0 = 2;
  iVar1 = (**(code **)(WdfFunctions_01015 + 600))(WdfDriverGlobals,&local_f8,puVar3,&local_f0);
  if (iVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_qqL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),
                 (ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),puVar3,param_1,(char)local_f8,
                 (char)iVar1);
    }
  }
  else {
    puVar4 = (undefined8 *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,local_f0,PTR__WDF_NDIS_VBUS_BUS_DEVICE_TYPE_INFO_1c0005048)
    ;
    *puVar4 = 0;
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x420))(WdfDriverGlobals,local_f0);
    *puVar4 = uVar2;
    LOCK();
    bVar5 = DAT_1c0005498 == (undefined8 *)0x0;
    if (bVar5) {
      DAT_1c0005498 = puVar4;
    }
    UNLOCK();
    if (bVar5) {
      local_48 = 0x63771199;
      uStack_44 = 0x4244214b;
      uStack_40 = 0x7cf8f583;
      uStack_3c = 0x419c4f2f;
      local_38 = 0xf;
      (**(code **)(WdfFunctions_01015 + 0x2a8))(WdfDriverGlobals,local_f0,&local_48);
      _Global = 0x480000;
      _DAT_1c0005428 = ndisVBusNmrProviderAttachClient;
      puVar4 = &DAT_1c0005468;
      _DAT_1c0005440 = 0x280001;
      _DAT_1c0005430 = ndisVBusNmrProviderDetachClient;
      _DAT_1c0005458 = 0;
      _DAT_1c0005438 = ndisVBusNmrProviderCleanupBindingContext;
      _DAT_1c0005460 = 0;
      _DAT_1c0005448 = &NPI_NDIS_VBUS_INTERFACE_ID;
      _DAT_1c0005450 = &NPI_MS_NDIS_VBUS_MODULEID;
      _DAT_1c0005470 = ndisVBusVirtMiniAdd;
      _DAT_1c0005478 = ndisVBusVirtMiniRemove;
      iVar1 = NmrRegisterProvider(&Global,0);
      if (iVar1 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),
                   (ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),puVar4,iVar1);
        }
        DAT_1c0005468 = 0;
      }
      else {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                   &WPP_44f36d42aea93cdc74daf49813a5f4b0_Traceguids,param_1);
        }
        iVar1 = 0;
      }
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                 &WPP_44f36d42aea93cdc74daf49813a5f4b0_Traceguids,param_1);
      }
      iVar1 = -0x3fffff43;
    }
  }
  return iVar1;
}



===== WppInitKm @ 1c0009320 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WppInitKm(void)

{
  code *pcVar1;
  undefined *puVar2;
  
  puVar2 = &WPP_MAIN_CB;
  if (WPP_GLOBAL_Control != &WPP_MAIN_CB) {
    WPP_GLOBAL_Control = &WPP_MAIN_CB;
    if (WPPTraceSuite == 4) {
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
  }
  return;
}



===== __security_init_cookie @ 1c000a008 =====

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



===== DriverEntry @ 1c000a03c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(ulonglong param_1,undefined8 param_2)

{
  int iVar1;
  ulonglong uVar2;
  undefined8 local_res18;
  ulonglong local_28;
  code *local_20;
  code *local_18;
  undefined4 local_10;
  undefined4 local_c;
  
  _DAT_1c0005408 = 1;
  local_res18 = 0;
  local_28 = (ulonglong)(uint)local_28;
  _WPP_MAIN_CB = 0;
  DAT_1c00053e8 = &WPP_ThisDir_CTLGUID_NdisVirtualBusWPPGuid;
  DAT_1c00053f0 = 0;
  _DAT_1c0005400 = 0;
  WppLoadTracingSupport();
  _DAT_1c0005400 = 0;
  WppInitKm();
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_44f36d42aea93cdc74daf49813a5f4b0_Traceguids,param_1);
  }
  local_28 = 0x20;
  local_20 = ndisVBusDeviceAdd;
  local_18 = ndisVBusDriverUnload;
  local_10 = 0;
  local_c = 0x6276444e;
  uVar2 = param_1;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x3a0))
                    (WdfDriverGlobals,param_1,param_2,0,&local_28,&local_res18);
  if (iVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_1c000a1a9;
    uVar2 = (ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c);
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,param_2,param_1,(char)iVar1);
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,param_2,param_1,(char)local_res18,
               (char)iVar1);
  }
  if (-1 < iVar1) {
    return iVar1;
  }
LAB_1c000a1a9:
  WppCleanupKm();
  return iVar1;
}


