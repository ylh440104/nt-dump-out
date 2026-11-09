
===== MarsEvtDevicePrepareHardware @ 140001000 =====

void MarsEvtDevicePrepareHardware(undefined8 param_1)

{
  ushort *puVar1;
  int iVar2;
  longlong lVar3;
  undefined1 local_res20 [8];
  ushort local_18 [2];
  ushort local_14 [6];
  
  local_res20[0] = 0;
  lVar3 = (*DAT_140003710)(WdfDriverGlobals,param_1,PTR__WDF_FDO_DATA_TYPE_INFO_140003018);
  iVar2 = SdioGetProperty(param_1,3,lVar3 + 0x42,1);
  if (-1 < iVar2) {
    puVar1 = (ushort *)(lVar3 + 0x40);
    *puVar1 = 0x100;
    SdioGetProperty(param_1,5,puVar1,2);
    *(undefined1 *)(lVar3 + 0x43) = *(undefined1 *)(lVar3 + 0x42);
    *(bool *)(lVar3 + 0x44) = 0x1ff < *puVar1;
    iVar2 = SdioGetProperty(param_1,9,local_18,2);
    if (-1 < iVar2) {
      iVar2 = SdioGetProperty(param_1,0xc,local_res20,1);
      if (-1 < iVar2) {
        local_14[0] = 0x40;
        if (local_18[0] < 0x40) {
          local_14[0] = local_18[0];
        }
        SdioSetProperty(param_1,10,local_14,2);
      }
    }
  }
  return;
}



===== MarsEvtDeviceReleaseHardware @ 140001104 =====

undefined8 MarsEvtDeviceReleaseHardware(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = (*DAT_140003710)(WdfDriverGlobals,param_1,PTR__WDF_FDO_DATA_TYPE_INFO_140003018);
  if (*(code **)(lVar1 + 0x28) != (code *)0x0) {
    (**(code **)(lVar1 + 0x28))(*(undefined8 *)(lVar1 + 0x18));
    *(undefined8 *)(lVar1 + 0x28) = 0;
  }
  return 0;
}



===== SdioGetProperty @ 140001140 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SdioGetProperty(undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4)

{
  longlong lVar1;
  undefined1 auStack_c8 [32];
  undefined4 local_a8 [16];
  undefined4 local_68;
  undefined8 local_60;
  undefined4 local_58;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_c8;
  lVar1 = (*DAT_140003710)(WdfDriverGlobals,param_1,PTR__WDF_FDO_DATA_TYPE_INFO_140003018);
  memset(local_a8,0,0x68);
  local_a8[0] = 0;
  local_68 = param_2;
  local_60 = param_3;
  local_58 = param_4;
  SdBusSubmitRequest(*(int **)(lVar1 + 0x18),(longlong)local_a8);
  return;
}



===== SdioSetProperty @ 1400011cc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SdioSetProperty(undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4)

{
  longlong lVar1;
  undefined1 auStack_c8 [32];
  undefined4 local_a8 [16];
  undefined4 local_68;
  undefined8 local_60;
  undefined4 local_58;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_c8;
  lVar1 = (*DAT_140003710)(WdfDriverGlobals,param_1,PTR__WDF_FDO_DATA_TYPE_INFO_140003018);
  memset(local_a8,0,0x68);
  local_a8[0] = 1;
  local_68 = param_2;
  local_60 = param_3;
  local_58 = param_4;
  SdBusSubmitRequest(*(int **)(lVar1 + 0x18),(longlong)local_a8);
  return;
}



===== __C_specific_handler @ 14000125c =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000125c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== WdfVersionBind @ 140001262 =====

void WdfVersionBind(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001262. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WdfVersionBind();
  return;
}



===== WdfVersionUnbind @ 140001268 =====

void WdfVersionUnbind(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001268. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WdfVersionUnbind();
  return;
}



===== WdfVersionBindClass @ 14000126e =====

void WdfVersionBindClass(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000126e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WdfVersionBindClass();
  return;
}



===== WdfVersionUnbindClass @ 140001274 =====

void WdfVersionUnbindClass(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001274. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WdfVersionUnbindClass();
  return;
}



===== SdBusOpenInterface @ 140001280 =====

int SdBusOpenInterface(undefined8 param_1,undefined8 param_2,undefined2 param_3,undefined2 param_4)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  int local_30 [4];
  undefined1 local_20 [24];
  
  local_30[0] = 0;
  local_30[1] = 0;
  local_30[2] = 0;
  local_30[3] = 0;
  uVar3 = IoGetAttachedDeviceReference();
  KeInitializeEvent(local_20,0,0);
  lVar4 = IoBuildSynchronousFsdRequest(0x1b,uVar3,0,0,0,local_20,local_30);
  if (lVar4 == 0) {
    iVar2 = -0x3fffff66;
  }
  else {
    *(undefined4 *)(lVar4 + 0x30) = 0xc00000bb;
    *(undefined8 *)(lVar4 + 0x38) = 0;
    lVar1 = *(longlong *)(lVar4 + 0xb8);
    *(undefined1 *)(lVar1 + -0x47) = 8;
    *(undefined **)(lVar1 + -0x40) = &GUID_SDBUS_INTERFACE_STANDARD;
    *(undefined2 *)(lVar1 + -0x38) = param_3;
    *(undefined2 *)(lVar1 + -0x36) = param_4;
    *(undefined8 *)(lVar1 + -0x30) = param_2;
    iVar2 = IofCallDriver(uVar3,lVar4);
    if (iVar2 == 0x103) {
      KeWaitForSingleObject(local_20,0,0,0,0);
      iVar2 = local_30[0];
    }
  }
  ObfDereferenceObject(uVar3);
  return iVar2;
}



===== SdBusSubmitRequest @ 14000138c =====

ulonglong SdBusSubmitRequest(int *param_1,longlong param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint local_38 [2];
  undefined8 local_30;
  undefined1 local_28 [32];
  
  local_38[0] = 0;
  local_38[1] = 0;
  local_30 = 0;
  if (((param_1 == (int *)0x0) || (*param_1 != 0x43494453)) || (*(longlong *)(param_1 + 2) == 0)) {
    uVar2 = 0xc0000056;
  }
  else {
    lVar1 = IoAllocateIrp(*(undefined1 *)(*(longlong *)(param_1 + 2) + 0x4c),0);
    if (lVar1 == 0) {
      uVar2 = 0xc000009a;
    }
    else {
      *(uint **)(lVar1 + 0x48) = local_38;
      KeInitializeEvent(local_28,0,0);
      uVar3 = SdBusSubmitRequestAsync(param_1,param_2,lVar1,SdbusIoctlCompletion,local_28);
      uVar2 = uVar3 & 0xffffffff;
      if ((int)uVar3 == 0x103) {
        KeWaitForSingleObject(local_28,0,0,0,0);
        uVar2 = (ulonglong)local_38[0];
        *(undefined8 *)(param_2 + 0x20) = local_30;
      }
      IoFreeIrp(lVar1);
    }
  }
  return uVar2;
}



===== SdBusSubmitRequestAsync @ 140001478 =====

undefined8
SdBusSubmitRequestAsync
          (int *param_1,undefined8 param_2,longlong param_3,undefined8 param_4,undefined8 param_5)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = *(longlong *)(param_3 + 0xb8);
  *(undefined4 *)(lVar1 + -0x40) = 0;
  *(undefined1 *)(lVar1 + -0x48) = 0xf;
  *(undefined4 *)(lVar1 + -0x38) = 0x68;
  *(undefined4 *)(lVar1 + -0x30) = 0x43073;
  *(undefined8 *)(lVar1 + -0x28) = param_2;
  lVar1 = *(longlong *)(param_3 + 0xb8);
  *(undefined8 *)(lVar1 + -0x10) = param_4;
  *(undefined1 *)(lVar1 + -0x45) = 0xe0;
  *(undefined8 *)(lVar1 + -8) = param_5;
  if (((param_1 == (int *)0x0) || (*param_1 != 0x43494453)) || (*(longlong *)(param_1 + 2) == 0)) {
    *(char *)(param_3 + 0x43) = *(char *)(param_3 + 0x43) + -1;
    *(longlong *)(param_3 + 0xb8) = *(longlong *)(param_3 + 0xb8) + -0x48;
    *(undefined4 *)(param_3 + 0x30) = 0xc0000056;
    IofCompleteRequest(param_3,0);
    return 0xc0000056;
  }
                    /* WARNING: Could not recover jumptable at 0x0001400014d2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = IofCallDriver(*(longlong *)(param_1 + 2),param_3);
  return uVar2;
}



===== SdbusIoctlCompletion @ 140001504 =====

undefined8 SdbusIoctlCompletion(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  **(undefined4 **)(param_2 + 0x48) = *(undefined4 *)(param_2 + 0x30);
  *(undefined8 *)(*(longlong *)(param_2 + 0x48) + 8) = *(undefined8 *)(param_2 + 0x38);
  KeSetEvent(param_3,0,0);
  return 0xc0000016;
}



===== __security_check_cookie @ 140001550 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  if ((_StackCookie == __security_cookie) && ((short)(_StackCookie >> 0x30) == 0)) {
    return;
  }
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __GSHandlerCheck @ 140001578 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140001598 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong __GSHandlerCheckCommon(undefined8 param_1,longlong param_2)

{
  byte bVar1;
  longlong lVar2;
  
  bVar1 = *(byte *)((ulonglong)*(uint *)(*(longlong *)(param_2 + 0x10) + 8) +
                    *(longlong *)(param_2 + 8) + 3);
  lVar2 = CONCAT71((int7)((ulonglong)*(longlong *)(param_2 + 0x10) >> 8),bVar1);
  if ((bVar1 & 0xf) != 0) {
    lVar2 = (longlong)(int)(bVar1 & 0xfffffff0);
  }
  return lVar2;
}



===== FxStubDriverUnloadCommon @ 140001600 =====

/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  FxStubUnbindClasses((_WDF_BIND_INFO *)&DAT_140003040);
  WdfVersionUnbind(&DAT_140004078,&DAT_140003040,WdfDriverGlobals);
  return;
}



===== entry @ 140001630 =====

void entry(longlong param_1,undefined8 param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 14000165c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FxDriverEntryWorker(longlong param_1,undefined8 param_2)

{
  uint uVar1;
  ulonglong uVar2;
  
  if (param_1 == 0) {
    uVar2 = DriverEntry(0,param_2);
  }
  else {
    _DAT_140004080 = &DAT_140003e70;
    _DAT_140004078 = 0x2080000;
    _DAT_140003e58 = param_1;
    RtlCopyUnicodeString(&DAT_140004078);
    uVar2 = WdfVersionBind(param_1,&DAT_140004078,&DAT_140003040,&WdfDriverGlobals);
    if (-1 < (int)uVar2) {
      uVar1 = FxStubBindClasses((_WDF_BIND_INFO *)&DAT_140003040);
      if (((-1 < (int)uVar1) && (uVar1 = FxStubInitTypes(), -1 < (int)uVar1)) &&
         (uVar1 = DriverEntry(param_1,param_2), -1 < (int)uVar1)) {
        if (*(char *)(WdfDriverGlobals + 0x30) == '\0') {
          if ((*(uint *)(WdfDriverGlobals + 8) & 2) != 0) {
            _DAT_140003e60 = DAT_140003708;
            DAT_140003708 = &FxStubDriverMiniportUnload;
          }
        }
        else {
          if (*(longlong *)(param_1 + 0x68) != 0) {
            DAT_140003e48 = *(longlong *)(param_1 + 0x68);
          }
          *(code **)(param_1 + 0x68) = FxStubDriverUnload;
        }
        return 0;
      }
      FxStubDriverUnloadCommon();
      uVar2 = (ulonglong)uVar1;
    }
  }
  return uVar2;
}



===== FxStubDriverUnload @ 140001784 =====

void FxStubDriverUnload(void)

{
  if ((DAT_140003e48 != (code *)0x0) && (DAT_140003e48 != FxStubDriverUnload)) {
    (*DAT_140003e48)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubInitTypes @ 1400017ac =====

/* WARNING: Removing unreachable block (ram,0x0001400017dc) */
/* WARNING: Removing unreachable block (ram,0x0001400017e3) */
/* WARNING: Removing unreachable block (ram,0x000140001811) */
/* WARNING: Removing unreachable block (ram,0x0001400017e9) */
/* WARNING: Removing unreachable block (ram,0x0001400017f1) */
/* WARNING: Removing unreachable block (ram,0x0001400017f7) */
/* WARNING: Removing unreachable block (ram,0x0001400017c9) */
/* long __cdecl FxStubInitTypes(void) */

long __cdecl FxStubInitTypes(void)

{
  return 0;
}



===== FxStubBindClasses @ 140001818 =====

/* WARNING: Removing unreachable block (ram,0x00014000183f) */
/* long __cdecl FxStubBindClasses(struct _WDF_BIND_INFO * __ptr64) */

long __cdecl FxStubBindClasses(_WDF_BIND_INFO *param_1)

{
  int iVar1;
  void **ppvVar2;
  
  iVar1 = 0;
  ppvVar2 = &__KMDF_CLASS_BIND_END;
  while( true ) {
    if ((void **)0x14000307f < ppvVar2) {
      return iVar1;
    }
    if (*(int *)ppvVar2 != 0x50) break;
    PTR___KMDF_CLASS_BIND_START_140003088 = (undefined *)ppvVar2;
    if (ppvVar2[7] == (code *)0x0) {
      iVar1 = WdfVersionBindClass(param_1,WdfDriverGlobals,ppvVar2);
    }
    else {
      iVar1 = (*ppvVar2[7])(WdfVersionBindClass,param_1,WdfDriverGlobals,ppvVar2);
    }
    if (iVar1 < 0) {
      return iVar1;
    }
    ppvVar2 = ppvVar2 + 10;
  }
  return -0x3ffffffc;
}



===== FxStubUnbindClasses @ 1400018b0 =====

/* void __cdecl FxStubUnbindClasses(struct _WDF_BIND_INFO * __ptr64) */

void __cdecl FxStubUnbindClasses(_WDF_BIND_INFO *param_1)

{
  void **ppvVar1;
  
  ppvVar1 = &__KMDF_CLASS_BIND_END;
  if (((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_140003088 != &__KMDF_CLASS_BIND_START) &&
     ((undefined *)0x14000307f < PTR___KMDF_CLASS_BIND_START_140003088)) {
    do {
      if (ppvVar1[8] == (code *)0x0) {
        WdfVersionUnbindClass(param_1,WdfDriverGlobals,ppvVar1);
      }
      else {
        (*ppvVar1[8])(WdfVersionUnbindClass,param_1,WdfDriverGlobals,ppvVar1);
      }
      ppvVar1 = ppvVar1 + 10;
    } while (ppvVar1 <= PTR___KMDF_CLASS_BIND_START_140003088);
  }
  return;
}



===== memset @ 140001940 =====

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  uint uVar1;
  void *pvVar2;
  ulonglong *puVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  
  uVar4 = (ulonglong)(uint)_Val;
  pvVar2 = _Dst;
  if (7 < _Size) {
    uVar4 = (ulonglong)(byte)_Val * 0x101010101010101;
    if (0x46 < _Size) {
      uVar1 = -(int)_Dst & 7;
      if (uVar1 != 0) {
        _Size = _Size - uVar1;
        *(ulonglong *)_Dst = uVar4;
      }
      puVar3 = (ulonglong *)((ulonglong)uVar1 + (longlong)_Dst);
      uVar6 = _Size >> 6;
      uVar5 = _Size >> 3 & 7;
      if (uVar5 == 0) goto LAB_140001a00;
      puVar3 = puVar3 + (uVar5 - 8);
      uVar6 = uVar6 + 1;
      switch(uVar5) {
      case 2:
        goto switchD_1400019fd_caseD_2;
      case 3:
        goto switchD_1400019fd_caseD_3;
      case 4:
        goto switchD_1400019fd_caseD_4;
      case 5:
        goto switchD_1400019fd_caseD_5;
      case 6:
        goto switchD_1400019fd_caseD_6;
      case 7:
        goto switchD_1400019fd_caseD_7;
      }
      while( true ) {
        puVar3[7] = uVar4;
        puVar3 = puVar3 + 8;
        uVar6 = uVar6 - 1;
        if (uVar6 == 0) break;
LAB_140001a00:
        *puVar3 = uVar4;
switchD_1400019fd_caseD_7:
        puVar3[1] = uVar4;
switchD_1400019fd_caseD_6:
        puVar3[2] = uVar4;
switchD_1400019fd_caseD_5:
        puVar3[3] = uVar4;
switchD_1400019fd_caseD_4:
        puVar3[4] = uVar4;
switchD_1400019fd_caseD_3:
        puVar3[5] = uVar4;
switchD_1400019fd_caseD_2:
        puVar3[6] = uVar4;
      }
      for (uVar5 = _Size & 7; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(char *)((uVar5 - 1) + (longlong)puVar3) = (char)uVar4;
      }
      return _Dst;
    }
    uVar5 = _Size & 0xfffffffffffffff8;
    pvVar2 = (void *)((longlong)_Dst + uVar5);
    do {
      *(ulonglong *)((uVar5 - 8) + (longlong)_Dst) = uVar4;
      uVar5 = uVar5 - 8;
    } while (uVar5 != 0);
  }
  for (uVar5 = _Size & 7; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(char *)((uVar5 - 1) + (longlong)pvVar2) = (char)uVar4;
  }
  return _Dst;
}



===== FUN_140001a40 @ 140001a40 =====

void FUN_140001a40(undefined8 param_1,longlong param_2)

{
  ObfDereferenceObject(*(undefined8 *)(param_2 + 0x40));
  return;
}



===== MarsEvtDeviceAdd @ 140006000 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int MarsEvtDeviceAdd(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined1 auStack_198 [32];
  undefined8 local_178;
  undefined8 local_170;
  undefined2 local_168;
  undefined2 local_166 [3];
  undefined8 local_160;
  undefined1 local_158;
  undefined8 local_150;
  undefined8 *local_148;
  undefined4 local_140 [6];
  undefined4 local_128;
  undefined4 local_124;
  undefined *local_110;
  undefined4 local_108 [10];
  code *local_e0;
  code *local_d8;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined8 local_60;
  undefined4 local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_198;
  local_168 = 0;
  local_170 = param_2;
  memset(local_166,0,0x26);
  (*DAT_1400032c0)(WdfDriverGlobals,param_2);
  (*DAT_1400032a8)(WdfDriverGlobals,local_170,2);
  memset(local_108,0,0x90);
  local_108[0] = 0x90;
  local_e0 = MarsEvtDevicePrepareHardware;
  local_d8 = MarsEvtDeviceReleaseHardware;
  (*DAT_140003278)(WdfDriverGlobals,local_170,local_108);
  memset(local_140,0,0x38);
  local_110 = PTR__WDF_FDO_DATA_TYPE_INFO_140003018;
  local_140[0] = 0x38;
  local_128 = 1;
  local_124 = 1;
  iVar1 = (*DAT_140003318)(WdfDriverGlobals,&local_170,local_140,&local_178);
  if (-1 < iVar1) {
    memset(&local_50,0,0x30);
    local_50 = 0x30;
    local_4c = 2;
    local_48 = 2;
    local_40 = 2;
    local_3c = 2;
    local_38 = 2;
    local_34 = 2;
    local_30 = 2;
    local_28 = 0xffffffff;
    local_24 = 0xffffffff;
    local_2c = 1;
    (*DAT_140003358)(WdfDriverGlobals,local_178,&local_50);
    puVar2 = (undefined8 *)
             (*DAT_140003710)(WdfDriverGlobals,local_178,PTR__WDF_FDO_DATA_TYPE_INFO_140003018);
    memset(&local_78,0,0x24);
    local_78 = 0x24;
    local_68 = 2;
    local_64 = 2;
    local_60 = 2;
    local_58 = 2;
    local_74 = 1;
    local_6c = 10000;
    local_70 = 3;
    iVar1 = (*DAT_140003230)(WdfDriverGlobals,local_178,&local_78);
    if (-1 < iVar1) {
      uVar3 = (*DAT_1400031c8)(WdfDriverGlobals,local_178);
      iVar1 = SdBusOpenInterface(uVar3,puVar2 + 2,0x30,0x101);
      if (-1 < iVar1) {
        local_168 = 0x28;
        local_160 = (*DAT_1400031c0)(WdfDriverGlobals,local_178);
        local_158 = 0;
        local_150 = 0;
        local_166[0] = 1;
        iVar1 = -0x3fffffff;
        local_148 = puVar2;
        if (((code *)puVar2[6] != (code *)0x0) &&
           (iVar1 = (*(code *)puVar2[6])(puVar2[3],&local_168), -1 < iVar1)) {
          *puVar2 = local_178;
          return iVar1;
        }
        (*(code *)puVar2[5])(puVar2[3]);
        puVar2[5] = 0;
      }
    }
  }
  return iVar1;
}



===== DriverEntry @ 140007000 =====

void DriverEntry(undefined8 param_1,undefined8 param_2)

{
  undefined4 local_28 [2];
  code *local_20;
  
  memset(local_28,0,0x20);
  local_20 = MarsEvtDeviceAdd;
  local_28[0] = 0x20;
  (*DAT_140003460)(WdfDriverGlobals,param_1,param_2,0,local_28,0);
  return;
}



===== __security_init_cookie @ 140007068 =====

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


