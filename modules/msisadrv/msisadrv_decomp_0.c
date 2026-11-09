
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



===== FxStubDriverUnloadCommon @ 1c0001020 =====

/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  _WDF_BIND_INFO *in_RCX;
  
  FxStubUnbindClasses(in_RCX);
  WdfVersionUnbind(&DAT_1c00042e0,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== entry @ 1c0001060 =====

void entry(_WDF_BIND_INFO *param_1,undefined8 param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 1c0001094 =====

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
    _DAT_1c00042e0 = 0x2080000;
    _DAT_1c00042e8 = &DAT_1c00040d0;
    RtlCopyUnicodeString(&DAT_1c00042e0);
    p_Var3 = param_1;
    iVar1 = WdfVersionBind(param_1,&DAT_1c00042e0,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < iVar1) {
      iVar1 = FxStubBindClasses(p_Var3);
      if ((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) {
        iVar1 = DriverEntry(param_1,param_2);
        if (-1 < iVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_1c00042d8 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",iVar1,&DAT_1c00042e0);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c0004098 != &__KMDF_CLASS_BIND_START) {
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



===== FxStubDriverUnload @ 1c0001220 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_1c00042d8 != (code *)0x0) && (DAT_1c00042d8 != FxStubDriverUnload)) {
    (*DAT_1c00042d8)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 1c0001254 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c0001279) */
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
    if ((uint *)0x1c000408f < puVar2) break;
    PTR___KMDF_CLASS_BIND_START_1c0004098 = (undefined *)puVar2;
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



===== FxStubUnbindClasses @ 1c00013b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubUnbindClasses(struct _WDF_BIND_INFO * __ptr64) */

void __cdecl FxStubUnbindClasses(_WDF_BIND_INFO *param_1)

{
  uint *puVar1;
  uint *puVar2;
  void **ppvVar3;
  
  ppvVar3 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c0004098 != &__KMDF_CLASS_BIND_START) {
    puVar1 = (uint *)(PTR___KMDF_CLASS_BIND_START_1c0004098 + 0x50);
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



===== FxGetNextClassBindInfo @ 1c0001470 =====

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



===== FxStubInitTypes @ 1c00014b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c00014d5) */
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
    if ((void **)0x1c00040af < ppvVar2) break;
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



===== _guard_check_icall @ 1c0001590 =====

void _guard_check_icall(void)

{
  return;
}



===== __security_check_cookie @ 1c00015b0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c00015f0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0001620 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0001620. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0001650 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== MsIsaEvtCleanupCallback @ 1c0007010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void MsIsaEvtCleanupCallback(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DATA_TYPE_INFO_1c0004018);
  KeEnterCriticalRegion();
  KeWaitForSingleObject(&BusNumberLock,0,0,0,0);
  RtlClearBits(&BusNumberBitMap,*(undefined4 *)(lVar1 + 4),1);
  KeSetEvent(&BusNumberLock,0,0);
  KeLeaveCriticalRegion();
  return;
}



===== MsIsaEvtDeviceAdd @ 1c00070c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void MsIsaEvtDeviceAdd(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined8 local_res10;
  undefined8 local_res18;
  ulonglong local_98;
  undefined8 *puStack_90;
  undefined *local_88;
  undefined8 uStack_80;
  code *local_78;
  undefined8 uStack_70;
  undefined4 local_68;
  undefined4 local_64;
  code *local_60;
  undefined8 local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined *local_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  
  local_res18 = 0;
  local_64 = 0;
  local_98 = (ulonglong)(uint)local_98;
  local_res10 = param_2;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x248))
                    (WdfDriverGlobals,param_2,MsIsaPnPIrpPreProcessingCallback,0x1b,
                     &PnPMinorFunctionTable,1);
  if (-1 < iVar1) {
    (**(code **)(WdfFunctions_01015 + 0x1f8))(WdfDriverGlobals,local_res10);
    local_64 = 0;
    local_58 = 0;
    local_38 = PTR__WDF_FDO_DATA_TYPE_INFO_1c0004018;
    local_60 = MsIsaEvtCleanupCallback;
    local_48 = 0;
    uStack_40 = 0;
    local_68 = 0x38;
    local_50 = 1;
    local_4c = 1;
    iVar1 = (**(code **)(WdfFunctions_01015 + 600))
                      (WdfDriverGlobals,&local_res10,&local_68,&local_res18);
    if (-1 < iVar1) {
      (**(code **)(WdfFunctions_01015 + 0x188))(WdfDriverGlobals,local_res18,1,1);
      (**(code **)(WdfFunctions_01015 + 0x188))(WdfDriverGlobals,local_res18,2,1);
      (**(code **)(WdfFunctions_01015 + 0x188))(WdfDriverGlobals,local_res18,3,1);
      puVar3 = (undefined4 *)
               (**(code **)(WdfFunctions_01015 + 0x650))
                         (WdfDriverGlobals,local_res18,PTR__WDF_FDO_DATA_TYPE_INFO_1c0004018);
      *puVar3 = 0x6173494d;
      KeEnterCriticalRegion();
      KeWaitForSingleObject(&BusNumberLock,0,0,0,0);
      uVar2 = RtlFindClearBitsAndSet(&BusNumberBitMap,1,0);
      puVar3[1] = uVar2;
      KeSetEvent(&BusNumberLock,0,0);
      KeLeaveCriticalRegion();
      local_98 = 0x30;
      uStack_70 = 1;
      uStack_28 = 0;
      local_30 = 0x30;
      puStack_90 = &local_30;
      uStack_80 = 0;
      local_88 = &GUID_TRANSLATOR_INTERFACE_STANDARD;
      local_78 = MsIsaEvtDeviceProcessQueryInterface;
      local_20 = 0;
      uStack_18 = 0;
      (**(code **)(WdfFunctions_01015 + 0x720))(WdfDriverGlobals,local_res18,&local_98);
    }
  }
  return;
}



===== MsIsaPnPIrpPreProcessingCallback @ 1c0007340 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 MsIsaPnPIrpPreProcessingCallback(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DATA_TYPE_INFO_1c0004018);
  if (*(char *)(*(longlong *)(param_2 + 0xb8) + 1) == '\x18') {
    puVar2 = (undefined4 *)ExAllocatePool2(0x100,0x18,0x6173494d);
    uVar4 = 0;
    if (puVar2 == (undefined4 *)0x0) {
      *(undefined4 *)(param_2 + 0x30) = 0xc000009a;
      IofCompleteRequest(param_2);
      return 0xc000009a;
    }
    puVar2[4] = 1;
    *puVar2 = 0xe676f854;
    puVar2[1] = 0x11d0d87d;
    puVar2[2] = 0xa000b292;
    puVar2[3] = 0xc55f05c9;
    puVar2[5] = *(undefined4 *)(lVar1 + 4);
    *(undefined4 **)(param_2 + 0x38) = puVar2;
  }
  else {
    uVar4 = *(undefined4 *)(param_2 + 0x30);
  }
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  *(undefined4 *)(param_2 + 0x30) = uVar4;
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x110))(WdfDriverGlobals,param_1,param_2);
  return uVar3;
}



===== MsIsaEvtDeviceProcessQueryInterface @ 1c0007430 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
MsIsaEvtDeviceProcessQueryInterface
          (undefined8 param_1,longlong *param_2,ushort *param_3,int param_4)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined4 local_res18 [4];
  undefined4 local_18;
  undefined4 local_14 [3];
  
  local_18 = 0;
  if ((0x2f < *param_3) && (param_4 == 2)) {
    lVar2 = *param_2 + -0x11d0aacf6c154a92;
    if (lVar2 == 0) {
      lVar2 = param_2[1] + -0x44b206c9a0002a8d;
    }
    if (lVar2 == 0) {
      local_14[0] = 0;
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x288))
                        (WdfDriverGlobals,param_1,0xd,4,local_14,&local_18);
      if (-1 < iVar1) {
        local_res18[0] = 0;
        iVar1 = (**(code **)(WdfFunctions_01015 + 0x288))
                          (WdfDriverGlobals,param_1,0xe,4,local_res18,&local_18);
        if (-1 < iVar1) {
          uVar3 = (**(code **)(HalDispatchTable_exref + 0x78))
                            (local_14[0],local_res18[0],1,*param_3,param_3[1],param_3,local_res18);
          return uVar3;
        }
      }
      return 0xc0000001;
    }
  }
  return 0xc00000bb;
}



===== __security_init_cookie @ 1c0008008 =====

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



===== DriverEntry @ 1c000803c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 DriverEntry(undefined8 param_1,undefined8 param_2)

{
  undefined4 uVar1;
  undefined4 local_28;
  undefined4 local_24;
  code *local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_24 = 0;
  local_28 = 0x20;
  local_18 = 0;
  uStack_10 = 0;
  local_20 = MsIsaEvtDeviceAdd;
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x3a0))(WdfDriverGlobals,param_1,param_2,0,&local_28,0);
  KeInitializeEvent(&BusNumberLock,1,1);
  RtlInitializeBitMap(&BusNumberBitMap,&BusNumberBuffer,0x100);
  RtlClearAllBits(&BusNumberBitMap);
  return uVar1;
}


