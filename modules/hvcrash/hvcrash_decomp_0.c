
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



===== __report_gsfailure @ 1c00010c0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== _tlgWriteActivityAutoStop<1,4> @ 1c00010d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl _tlgWriteActivityAutoStop<1,4>(struct _tlgProvider_t const * __ptr64,struct _GUID
   const * __ptr64) */

void __cdecl _tlgWriteActivityAutoStop<1,4>(_tlgProvider_t *param_1,_GUID *param_2)

{
  undefined1 auStackY_68 [32];
  undefined8 local_38 [4];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  if (((4 < *(uint *)param_1) && (((byte)param_1[0x10] & 1) != 0)) &&
     ((ulonglong)((uint)*(ulonglong *)(param_1 + 0x18) & 1) == *(ulonglong *)(param_1 + 0x18))) {
    _tlgWriteTransfer_EtwWriteTransfer((longlong)param_1,&DAT_1c00058c9,param_2,0,2,local_38);
  }
  return;
}



===== operator() @ 1c000113c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void <lambda_2c9f845d685a0ccedaec2df770c4e004>::operator()(undefined8 *param_1)

{
  undefined4 *puVar1;
  undefined1 auStackY_78 [32];
  undefined4 local_48 [2];
  undefined8 local_40 [4];
  undefined4 *local_20;
  undefined4 local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  puVar1 = (undefined4 *)*param_1;
  *puVar1 = 2;
  if (((4 < DAT_1c0007028) && (((byte)DAT_1c0007038 & 1) != 0)) &&
     (((uint)DAT_1c0007040 & 1) == DAT_1c0007040)) {
    local_48[0] = *(undefined4 *)param_1[1];
    local_20 = local_48;
    local_14 = 0;
    local_18 = 4;
    _tlgWriteTransfer_EtwWriteTransfer(0x1c0007028,&DAT_1c0005711,puVar1 + 2,0,3,local_40);
  }
  return;
}



===== operator() @ 1c00011e4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void <lambda_943ce50503ab45fdba1c243ff726252d>::operator()(undefined8 *param_1)

{
  undefined4 *puVar1;
  undefined1 auStackY_78 [32];
  undefined4 local_48 [2];
  undefined8 local_40 [4];
  undefined4 *local_20;
  undefined4 local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  puVar1 = (undefined4 *)*param_1;
  *puVar1 = 2;
  if (((4 < DAT_1c0007028) && (((byte)DAT_1c0007038 & 1) != 0)) &&
     (((uint)DAT_1c0007040 & 1) == DAT_1c0007040)) {
    local_48[0] = *(undefined4 *)param_1[1];
    local_20 = local_48;
    local_14 = 0;
    local_18 = 4;
    _tlgWriteTransfer_EtwWriteTransfer(0x1c0007028,&DAT_1c000583f,puVar1 + 2,0,3,local_40);
  }
  return;
}



===== Initialize @ 1c000128c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl Diagnostics::Initialize(struct WDFDRIVER__ * __ptr64) */

void __cdecl Diagnostics::Initialize(WDFDRIVER__ *param_1)

{
  int iVar1;
  undefined1 auStack_78 [32];
  undefined8 *local_58;
  uint local_48 [2];
  undefined8 local_40;
  undefined8 local_38;
  wchar_t *local_30;
  wchar_t local_28 [12];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_78;
  local_58 = &local_40;
  local_40 = 0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x3b8))(WdfDriverGlobals,param_1,0x20019,0);
  if (-1 < iVar1) {
    local_48[0] = 0;
    builtin_wcsncpy(local_28,L"DebugFlags",0xb);
    local_30 = local_28;
    local_38 = 0x160014;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))(WdfDriverGlobals,local_40,&local_38,local_48);
    if (-1 < iVar1) {
      g_DbgPrintOnError = (bool)((byte)local_48[0] & 1);
      g_DbgBreakOnError = (bool)((byte)(local_48[0] >> 1) & 1);
    }
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals,local_40);
  }
  return;
}



===== NtStatus_ResultErrorCallback @ 1c000138c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl Diagnostics::NtStatus_ResultErrorCallback(struct Diagnostics::ErrorContext const &
   __ptr64) */

void __cdecl Diagnostics::NtStatus_ResultErrorCallback(ErrorContext *param_1)

{
  code *pcVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 auStackY_b8 [32];
  undefined2 local_88 [2];
  undefined4 local_84 [3];
  undefined8 local_78 [4];
  char *local_58;
  int local_50;
  undefined4 local_4c;
  undefined2 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  char *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  if (2 < DAT_1c0007028) {
    local_84[0] = *(undefined4 *)(param_1 + 8);
    local_28 = *(char **)(param_1 + 0x18);
    local_58 = *(char **)param_1;
    local_88[0] = *(undefined2 *)(param_1 + 0xc);
    lVar2 = -1;
    if (local_28 == (char *)0x0) {
      local_28 = "";
      local_20 = 1;
    }
    else {
      lVar3 = -1;
      do {
        lVar3 = lVar3 + 1;
      } while (local_28[lVar3] != '\0');
      local_20 = (int)lVar3 + 1;
    }
    local_1c = 0;
    local_2c = 0;
    local_3c = 0;
    local_38 = local_84;
    local_48 = local_88;
    local_30 = 4;
    local_40 = 2;
    if (local_58 == (char *)0x0) {
      local_58 = "";
      local_50 = 1;
    }
    else {
      do {
        lVar2 = lVar2 + 1;
      } while (local_58[lVar2] != '\0');
      local_50 = (int)lVar2 + 1;
    }
    local_4c = 0;
    _tlgWriteTransfer_EtwWriteTransfer(0x1c0007028,&DAT_1c00058f5,0,0,6,local_78);
  }
  if (g_DbgPrintOnError != false) {
    DbgPrint("HvCrash ERROR: %s:%d status 0x%08x\n   message: %s\n",*(undefined8 *)param_1,
             *(undefined2 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 8));
  }
  if (g_DbgBreakOnError == false) {
    return;
  }
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== _tlgDefineProvider_annotation__TlgHvCrashTraceLoggingProviderProv @ 1c00014e4 =====

void _tlgDefineProvider_annotation__TlgHvCrashTraceLoggingProviderProv(void)

{
  return;
}



===== FxStubDriverUnloadCommon @ 1c00014f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  void **ppvVar1;
  void **ppvVar2;
  
  ppvVar1 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c0007158 != &__KMDF_CLASS_BIND_START) {
    ppvVar2 = (void **)(PTR___KMDF_CLASS_BIND_START_1c0007158 + 0x50);
    while( true ) {
      for (; (ppvVar1 + 1 <= ppvVar2 && (*ppvVar1 == (void *)0x0)); ppvVar1 = ppvVar1 + 1) {
      }
      if (ppvVar1 < ppvVar2) break;
      ppvVar1 = ppvVar2;
LAB_1c0001549:
      if (ppvVar1 == (void **)0x0) goto LAB_1c000159f;
      if (ppvVar2 <= ppvVar1) goto LAB_1c00015b7;
      if (ppvVar1[8] == (code *)0x0) {
        WdfVersionUnbindClass(&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      else {
        (*ppvVar1[8])(WdfVersionUnbindClass_exref,&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      ppvVar1 = (void **)((longlong)ppvVar1 + (ulonglong)*(uint *)ppvVar1);
    }
    if ((ppvVar1 + 10 <= ppvVar2) && (*(uint *)ppvVar1 == 0x50)) goto LAB_1c0001549;
LAB_1c000159f:
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
LAB_1c00015b7:
  WdfVersionUnbind(&DAT_1c00073b0,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== entry @ 1c00015f0 =====

void entry(_WDF_BIND_INFO *param_1,undefined8 param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 1c0001624 =====

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
    _DAT_1c00073b0 = 0x2080000;
    _DAT_1c00073b8 = &DAT_1c00071a0;
    RtlCopyUnicodeString(&DAT_1c00073b0);
    p_Var3 = param_1;
    iVar1 = WdfVersionBind(param_1,&DAT_1c00073b0,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < iVar1) {
      iVar1 = FxStubBindClasses(p_Var3);
      if ((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) {
        iVar1 = DriverEntry(param_1,param_2);
        if (-1 < iVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_1c00073a8 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",iVar1,&DAT_1c00073b0);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c0007158 != &__KMDF_CLASS_BIND_START) {
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



===== FxStubDriverUnload @ 1c00017b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_1c00073a8 != (code *)0x0) && (DAT_1c00073a8 != FxStubDriverUnload)) {
    (*DAT_1c00073a8)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 1c00017e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c0001809) */
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
    if ((void **)0x1c000714f < ppvVar2) break;
    if (((&__KMDF_CLASS_BIND_END < ppvVar2 + 10) || (*(uint *)ppvVar2 != 0x50)) ||
       (ppvVar2 == (void **)0x0)) {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    PTR___KMDF_CLASS_BIND_START_1c0007158 = (undefined *)ppvVar2;
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



===== FxStubInitTypes @ 1c000196c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c0001989) */
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
    if ((void **)0x1c000716f < ppvVar2) break;
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



===== DumpControl @ 1c0001a40 =====

/* long __cdecl CrashdumpShim::DumpControl(struct _DUMP_DISK_INFO * __ptr64,enum
   _DUMP_CONTROL_CODE,void * __ptr64) */

long __cdecl
CrashdumpShim::DumpControl(_DUMP_DISK_INFO *param_1,_DUMP_CONTROL_CODE param_2,void *param_3)

{
  long lVar1;
  undefined4 in_register_00000014;
  char *local_28;
  long local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 local_10;
  
  if (param_2 == 1) {
    *(undefined1 *)((longlong)param_3 + 1) = 1;
  }
  else if (param_2 == 2) {
    lVar1 = HvCrashWriter::DumpPrepare
                      (*(HvCrashWriter **)(param_1 + 0x30),
                       (_DUMP_PREPARE_INFO *)CONCAT44(in_register_00000014,2),param_3);
    if (lVar1 < 0) {
      local_1c = 0x65;
LAB_1c0001a7f:
      local_10 = 0;
      local_28 = "onecore\\vm\\dv\\crashdump\\driver\\lib\\crashdumpshim.cpp";
      local_18 = 1;
      local_20 = lVar1;
      Diagnostics::NtStatus_ResultErrorCallback((ErrorContext *)&local_28);
      return lVar1;
    }
  }
  else if (2 < param_2 - 3) {
    if (param_2 != 6) {
      if (param_2 == 7) {
        lVar1 = HvCrashWriter::DumpComplete
                          (*(HvCrashWriter **)(param_1 + 0x30),
                           (_DUMP_CLEANUP_INFO *)CONCAT44(in_register_00000014,7),param_3);
        if (-1 < lVar1) {
          return 0;
        }
        local_1c = 0x84;
      }
      else {
        lVar1 = -0x3fffff45;
        local_1c = 0x88;
      }
      goto LAB_1c0001a7f;
    }
    *(undefined4 *)param_3 = 0x1000;
    *(undefined4 *)((longlong)param_3 + 4) = 0x4000;
  }
  return 0;
}



===== DumpFlush @ 1c0001b00 =====

/* long __cdecl CrashdumpShim::DumpFlush(struct _DUMP_DISK_INFO * __ptr64,unsigned __int64 *
   __ptr64,unsigned __int64 * __ptr64) */

long __cdecl CrashdumpShim::DumpFlush(_DUMP_DISK_INFO *param_1,__uint64 *param_2,__uint64 *param_3)

{
  return 0;
}



===== DumpWrite @ 1c0001b10 =====

/* long __cdecl CrashdumpShim::DumpWrite(struct _DUMP_DISK_INFO * __ptr64,enum
   _DUMP_IO_MODE,unsigned __int64 * __ptr64,void * __ptr64,void * __ptr64) */

long __cdecl
CrashdumpShim::DumpWrite
          (_DUMP_DISK_INFO *param_1,_DUMP_IO_MODE param_2,__uint64 *param_3,void *param_4,
          void *param_5)

{
  long lVar1;
  char *local_28;
  long local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 local_10;
  
  if (param_2 == 1) {
    lVar1 = HvCrashWriter::DumpWrite(*(HvCrashWriter **)(param_1 + 0x30),*param_3,param_4,param_4);
    if (-1 < lVar1) {
      return 0;
    }
    local_1c = 0x3e;
  }
  else {
    lVar1 = -0x3fffff45;
    local_1c = 0x3b;
  }
  local_10 = 0;
  local_28 = "onecore\\vm\\dv\\crashdump\\driver\\lib\\crashdumpshim.cpp";
  local_18 = 1;
  local_20 = lVar1;
  Diagnostics::NtStatus_ResultErrorCallback((ErrorContext *)&local_28);
  return lVar1;
}



===== GetDriveGeometry @ 1c0001b8c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl CrashdumpShim::GetDriveGeometry(struct WDFDEVICE__ * __ptr64,struct WDFREQUEST__ *
   __ptr64) */

long __cdecl CrashdumpShim::GetDriveGeometry(WDFDEVICE__ *param_1,WDFREQUEST__ *param_2)

{
  int iVar1;
  longlong lVar2;
  longlong local_res18;
  char *local_28;
  int local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 local_10;
  
  local_res18 = 0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,0x28,&local_res18,0);
  if (iVar1 < 0) {
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar1);
    local_10 = 0;
    local_28 = "onecore\\vm\\dv\\crashdump\\driver\\lib\\crashdumpshim.cpp";
    local_1c = 0x151;
    local_18 = 1;
    local_20 = iVar1;
    Diagnostics::NtStatus_ResultErrorCallback((ErrorContext *)&local_28);
  }
  else {
    *(undefined4 *)(local_res18 + 0x14) = 0x200;
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_HVCRASH_DEVICE_CONTEXT_TYPE_INFO_1c0007018)
    ;
    *(undefined8 *)(local_res18 + 0x18) = *(undefined8 *)(*(longlong *)(lVar2 + 8) + 0x10);
    (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_2,0,0x28);
    iVar1 = 0;
  }
  return iVar1;
}



===== GetDumpInfo @ 1c0001cb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */
/* long __cdecl CrashdumpShim::GetDumpInfo(struct WDFDEVICE__ * __ptr64,struct WDFREQUEST__ *
   __ptr64) */

long __cdecl CrashdumpShim::GetDumpInfo(WDFDEVICE__ *param_1,WDFREQUEST__ *param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  int iVar8;
  undefined4 *_Dst;
  longlong lVar9;
  HvCrashWriter *this;
  undefined8 *puVar10;
  ulonglong *puVar11;
  undefined8 *puVar12;
  ulonglong uVar13;
  longlong lVar14;
  longlong lVar15;
  ulonglong *puVar16;
  undefined1 *puVar17;
  _GUID *p_Var18;
  undefined1 auStack_1c8 [8];
  undefined1 auStack_1c0 [24];
  undefined8 local_1a8;
  char *local_198;
  int local_190;
  undefined4 local_18c;
  undefined4 uStack_188;
  undefined4 local_184;
  undefined8 local_180;
  int *local_178 [2];
  undefined8 local_168;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_1c8;
  local_178[0] = (int *)0x0;
  local_1a8 = 0;
  iVar8 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,0x48,local_178);
  if (iVar8 < 0) {
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar8);
    local_18c = 0xb6;
    uStack_188 = 0;
  }
  else {
    if (*local_178[0] == 0x48) {
      if (local_178[0][1] == 1) {
        _Dst = (undefined4 *)ExAllocatePool2(0x40,0xf8,0x72437648);
        if (_Dst == (undefined4 *)0x0) {
          iVar8 = -0x3fffff66;
          (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc000009a);
          local_190 = 0xc000009a;
          local_198 = "onecore\\vm\\dv\\crashdump\\driver\\lib\\crashdumpshim.cpp";
          local_18c = 0xc9;
          uStack_188 = 1;
          local_184 = 0;
          local_180 = 0;
          Diagnostics::NtStatus_ResultErrorCallback((ErrorContext *)&local_198);
        }
        else {
          memset(_Dst,0,0xf8);
          lVar9 = (**(code **)(WdfFunctions_01015 + 0x650))
                            (WdfDriverGlobals,param_1,
                             PTR__WDF_HVCRASH_DEVICE_CONTEXT_TYPE_INFO_1c0007018);
          if (*(longlong *)(lVar9 + 0x10) == 0) {
            p_Var18 = (_GUID *)0x72437648;
            this = (HvCrashWriter *)ExAllocatePool2(0x40,0x158);
            if (this == (HvCrashWriter *)0x0) {
              iVar8 = -0x3fffff66;
              (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc000009a);
              local_18c = 0xdb;
              uStack_188 = 1;
              goto LAB_1c0001ffb;
            }
            iVar8 = HvCrashWriter::Initialize(this,param_1,p_Var18);
            if (-1 < iVar8) {
              lVar15 = *(longlong *)(lVar9 + 0x10);
              *(HvCrashWriter **)(lVar9 + 0x10) = this;
              if (lVar15 != 0) {
                ExFreePoolWithTag();
              }
              goto LAB_1c0001f9b;
            }
            (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar8);
            local_198 = "onecore\\vm\\dv\\crashdump\\driver\\lib\\crashdumpshim.cpp";
            local_18c = 0xdd;
            uStack_188 = 0;
            local_184 = 0;
            local_180 = 0;
            local_190 = iVar8;
            Diagnostics::NtStatus_ResultErrorCallback((ErrorContext *)&local_198);
            ExFreePoolWithTag(this,0);
          }
          else {
LAB_1c0001f9b:
            memset((undefined1 *)((longlong)&local_168 + 4),0,0x120);
            local_168._0_4_ = 0x124;
            iVar8 = RtlGetVersion(&local_168);
            puVar17 = auStack_1c8;
            if (-1 < iVar8) {
              puVar6 = &local_168;
              puVar7 = *(undefined8 **)(lVar9 + 0x10);
              lVar15 = 2;
              do {
                lVar14 = lVar15;
                puVar12 = puVar7;
                puVar10 = puVar6;
                uVar5 = puVar10[1];
                *puVar12 = *puVar10;
                puVar12[1] = uVar5;
                uVar5 = puVar10[3];
                puVar12[2] = puVar10[2];
                puVar12[3] = uVar5;
                uVar5 = puVar10[5];
                puVar12[4] = puVar10[4];
                puVar12[5] = uVar5;
                uVar5 = puVar10[7];
                puVar12[6] = puVar10[6];
                puVar12[7] = uVar5;
                uVar5 = puVar10[9];
                puVar12[8] = puVar10[8];
                puVar12[9] = uVar5;
                uVar5 = puVar10[0xb];
                puVar12[10] = puVar10[10];
                puVar12[0xb] = uVar5;
                uVar5 = puVar10[0xd];
                puVar12[0xc] = puVar10[0xc];
                puVar12[0xd] = uVar5;
                uVar5 = puVar10[0xf];
                puVar12[0xe] = puVar10[0xe];
                puVar12[0xf] = uVar5;
                lVar15 = lVar14 + -1;
                puVar6 = puVar10 + 0x10;
                puVar7 = puVar12 + 0x10;
              } while (lVar15 != 0);
              uVar2 = *(undefined4 *)((longlong)puVar10 + 0x84);
              uVar3 = *(undefined4 *)(puVar10 + 0x11);
              uVar4 = *(undefined4 *)((longlong)puVar10 + 0x8c);
              *(undefined4 *)(puVar12 + 0x10) = *(undefined4 *)(puVar10 + 0x10);
              *(undefined4 *)((longlong)puVar12 + 0x84) = uVar2;
              *(undefined4 *)(puVar12 + 0x11) = uVar3;
              *(undefined4 *)((longlong)puVar12 + 0x8c) = uVar4;
              uVar2 = *(undefined4 *)((longlong)puVar10 + 0x94);
              uVar3 = *(undefined4 *)(puVar10 + 0x13);
              uVar4 = *(undefined4 *)((longlong)puVar10 + 0x9c);
              *(undefined4 *)(puVar12 + 0x12) = *(undefined4 *)(puVar10 + 0x12);
              *(undefined4 *)((longlong)puVar12 + 0x94) = uVar2;
              *(undefined4 *)(puVar12 + 0x13) = uVar3;
              *(undefined4 *)((longlong)puVar12 + 0x9c) = uVar4;
              *(undefined4 *)(puVar12 + 0x14) = *(undefined4 *)(puVar10 + 0x14);
              *_Dst = 0x48;
              *(undefined8 *)(_Dst + 0xc) = *(undefined8 *)(lVar9 + 0x10);
              *(undefined4 **)(_Dst + 0x10) = _Dst + 0x12;
              _Dst[0x12] = 0xb0;
              *(code **)(_Dst + 0x18) = LiveControl;
              *(wchar_t **)(_Dst + 0x1a) = L"HvCrash";
              *(code **)(_Dst + 0x28) = DumpWrite;
              *(code **)(_Dst + 0x2a) = DumpFlush;
              *(code **)(_Dst + 0x2c) = DumpControl;
              *(undefined4 **)(local_178[0] + 4) = _Dst;
              puVar16 = (ulonglong *)(_Dst + 2);
              puVar11 = (ulonglong *)(local_178[0] + 6);
              uVar13 = *puVar11;
              if (*(ulonglong **)(uVar13 + 8) != puVar11) {
                uVar13 = (ulonglong)((int)lVar14 + 2);
                pcVar1 = (code *)swi(0x29);
                puVar11 = (ulonglong *)(*pcVar1)();
                puVar17 = auStack_1c0;
              }
              *puVar16 = uVar13;
              *(ulonglong **)(_Dst + 4) = puVar11;
              *(ulonglong **)(uVar13 + 8) = puVar16;
              *puVar11 = (ulonglong)puVar16;
              pcVar1 = *(code **)(WdfFunctions_01015 + 0x848);
              *(undefined8 *)(puVar17 + -8) = 0x1c0002152;
              (*pcVar1)(WdfDriverGlobals,param_2,0,0x48);
              iVar8 = 0;
              goto LAB_1c0002154;
            }
            (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar8);
            local_18c = 0xe5;
            uStack_188 = 0;
LAB_1c0001ffb:
            local_184 = 0;
            local_198 = "onecore\\vm\\dv\\crashdump\\driver\\lib\\crashdumpshim.cpp";
            local_180 = 0;
            local_190 = iVar8;
            Diagnostics::NtStatus_ResultErrorCallback((ErrorContext *)&local_198);
          }
          ExFreePool(_Dst);
        }
        puVar17 = auStack_1c8;
        goto LAB_1c0002154;
      }
      (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc000000d);
      local_18c = 0xb9;
    }
    else {
      (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc000000d);
      local_18c = 0xb8;
    }
    iVar8 = -0x3ffffff3;
    uStack_188 = 1;
  }
  local_184 = 0;
  puVar17 = auStack_1c8;
  local_198 = "onecore\\vm\\dv\\crashdump\\driver\\lib\\crashdumpshim.cpp";
  local_180 = 0;
  local_190 = iVar8;
  Diagnostics::NtStatus_ResultErrorCallback((ErrorContext *)&local_198);
LAB_1c0002154:
  *(undefined8 *)(puVar17 + -8) = 0x1c0002163;
  return iVar8;
}



===== GetPartitionInfo @ 1c0002188 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl CrashdumpShim::GetPartitionInfo(struct WDFDEVICE__ * __ptr64,struct WDFREQUEST__ *
   __ptr64) */

long __cdecl CrashdumpShim::GetPartitionInfo(WDFDEVICE__ *param_1,WDFREQUEST__ *param_2)

{
  int iVar1;
  longlong lVar2;
  undefined4 *local_res18;
  char *local_28;
  int local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 local_10;
  
  local_res18 = (undefined4 *)0x0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,0x90,&local_res18,0);
  if (iVar1 < 0) {
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar1);
    local_10 = 0;
    local_28 = "onecore\\vm\\dv\\crashdump\\driver\\lib\\crashdumpshim.cpp";
    local_1c = 0x136;
    local_18 = 1;
    local_20 = iVar1;
    Diagnostics::NtStatus_ResultErrorCallback((ErrorContext *)&local_28);
  }
  else {
    *local_res18 = 2;
    *(undefined8 *)(local_res18 + 2) = 0;
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_HVCRASH_DEVICE_CONTEXT_TYPE_INFO_1c0007018)
    ;
    *(undefined8 *)(local_res18 + 4) = *(undefined8 *)(*(longlong *)(lVar2 + 8) + 0x10);
    (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_2,0,0x90);
    iVar1 = 0;
  }
  return iVar1;
}



===== GetVolumeDiskExtents @ 1c00022b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl CrashdumpShim::GetVolumeDiskExtents(struct WDFDEVICE__ * __ptr64,struct WDFREQUEST__
   * __ptr64) */

long __cdecl CrashdumpShim::GetVolumeDiskExtents(WDFDEVICE__ *param_1,WDFREQUEST__ *param_2)

{
  int iVar1;
  longlong lVar2;
  undefined4 *local_res18;
  char *local_28;
  int local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 local_10;
  
  local_res18 = (undefined4 *)0x0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,0x20,&local_res18,0);
  if (iVar1 < 0) {
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar1);
  }
  else {
    *local_res18 = 1;
    local_res18[2] = 0;
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_HVCRASH_DEVICE_CONTEXT_TYPE_INFO_1c0007018)
    ;
    *(undefined8 *)(local_res18 + 6) = *(undefined8 *)(*(longlong *)(lVar2 + 8) + 0x10);
    *(undefined8 *)(local_res18 + 4) = 0;
    (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_2,0,0x20);
  }
  if (iVar1 < 0) {
    local_10 = 0;
    local_28 = "onecore\\vm\\dv\\crashdump\\driver\\lib\\crashdumpshim.cpp";
    local_1c = 0xa6;
    local_18 = 1;
    local_20 = iVar1;
    Diagnostics::NtStatus_ResultErrorCallback((ErrorContext *)&local_28);
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



===== LiveControl @ 1c00023f0 =====

/* long __cdecl CrashdumpShim::LiveControl(struct _DUMP_DISK_INFO * __ptr64,enum
   _DUMP_CONTROL_CODE,void * __ptr64) */

long __cdecl
CrashdumpShim::LiveControl(_DUMP_DISK_INFO *param_1,_DUMP_CONTROL_CODE param_2,void *param_3)

{
  _DUMP_DISK_INFO *p_Var1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  long lVar5;
  
  lVar5 = 0;
  if (param_2 != 2) {
    if (param_2 == 7) {
      p_Var1 = param_1 + 8;
      lVar2 = *(longlong *)p_Var1;
      if ((*(_DUMP_DISK_INFO **)(lVar2 + 8) != p_Var1) ||
         (plVar3 = *(longlong **)(param_1 + 0x10), (_DUMP_DISK_INFO *)*plVar3 != p_Var1)) {
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3);
        pcVar4 = (code *)swi(3);
        lVar5 = (*pcVar4)();
        return lVar5;
      }
      *plVar3 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar3;
      ExFreePoolWithTag(param_1,0);
    }
    else {
      lVar5 = -0x3fffff45;
    }
  }
  return lVar5;
}



===== QueryRetrivalPointers @ 1c0002450 =====

/* long __cdecl CrashdumpShim::QueryRetrivalPointers(struct _IRP * __ptr64) */

long __cdecl CrashdumpShim::QueryRetrivalPointers(_IRP *param_1)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  long lVar4;
  char *local_28;
  long local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 local_10;
  
  lVar1 = *(longlong *)(param_1 + 0xb8);
  if ((*(int *)(lVar1 + 8) == 8) && (*(int *)(lVar1 + 0x10) == 8)) {
    puVar2 = *(undefined8 **)(param_1 + 0x70);
    puVar3 = (undefined8 *)ExAllocatePool2(0x40,0x20,0x72437648);
    *puVar2 = puVar3;
    if (puVar3 != (undefined8 *)0x0) {
      *puVar3 = **(undefined8 **)(lVar1 + 0x20);
      *(undefined4 *)(param_1 + 0x30) = 0;
      IofCompleteRequest(param_1,0);
      return 0;
    }
    lVar4 = -0x3fffff66;
    *(undefined4 *)(param_1 + 0x30) = 0xc000009a;
    IofCompleteRequest(param_1);
    local_1c = 0x179;
  }
  else {
    lVar4 = -0x3ffffff3;
    *(undefined4 *)(param_1 + 0x30) = 0xc000000d;
    IofCompleteRequest(param_1,0);
    local_1c = 0x16c;
  }
  local_10 = 0;
  local_28 = "onecore\\vm\\dv\\crashdump\\driver\\lib\\crashdumpshim.cpp";
  local_18 = 1;
  local_20 = lVar4;
  Diagnostics::NtStatus_ResultErrorCallback((ErrorContext *)&local_28);
  return lVar4;
}



===== _tlgWriteActivityAutoStop<2,4> @ 1c0002548 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl _tlgWriteActivityAutoStop<2,4>(struct _tlgProvider_t const * __ptr64,struct _GUID
   const * __ptr64) */

void __cdecl _tlgWriteActivityAutoStop<2,4>(_tlgProvider_t *param_1,_GUID *param_2)

{
  undefined1 auStackY_68 [32];
  undefined8 local_38 [4];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  if (((4 < *(uint *)param_1) && (((byte)param_1[0x10] & 2) != 0)) &&
     ((ulonglong)((uint)*(ulonglong *)(param_1 + 0x18) & 2) == *(ulonglong *)(param_1 + 0x18))) {
    _tlgWriteTransfer_EtwWriteTransfer((longlong)param_1,&DAT_1c0005976,param_2,0,2,local_38);
  }
  return;
}



===== _tlgWriteActivityAutoStop<2,5> @ 1c00025b4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl _tlgWriteActivityAutoStop<2,5>(struct _tlgProvider_t const * __ptr64,struct _GUID
   const * __ptr64) */

void __cdecl _tlgWriteActivityAutoStop<2,5>(_tlgProvider_t *param_1,_GUID *param_2)

{
  undefined1 auStackY_68 [32];
  undefined8 local_38 [4];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  if (((5 < *(uint *)param_1) && (((byte)param_1[0x10] & 2) != 0)) &&
     ((ulonglong)((uint)*(ulonglong *)(param_1 + 0x18) & 2) == *(ulonglong *)(param_1 + 0x18))) {
    _tlgWriteTransfer_EtwWriteTransfer((longlong)param_1,&DAT_1c00059f8,param_2,0,2,local_38);
  }
  return;
}



===== ~HvCrashControl @ 1c0002620 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: __cdecl HvCrashControl::~HvCrashControl(void) __ptr64 */

void __thiscall HvCrashControl::~HvCrashControl(HvCrashControl *this)

{
  if (*(longlong *)(this + 0x20) != 0) {
    (**(code **)(WdfFunctions_01015 + 0x550))(WdfDriverGlobals);
  }
  if (*(longlong *)(this + 0x20) != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  return;
}



===== Initialize @ 1c000267c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001c0002943) */
/* public: long __cdecl HvCrashControl::Initialize(struct _GUID const * __ptr64) __ptr64 */

long __thiscall HvCrashControl::Initialize(HvCrashControl *this,_GUID *param_1)

{
  long lVar1;
  WDFIOTARGET__ *pWVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  _GUID *p_Var6;
  undefined1 auStackY_c8 [32];
  longlong local_90;
  longlong lStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  char *local_70;
  undefined8 local_68;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_c8;
  if (param_1 != (_GUID *)0x0) {
    local_80 = *(undefined8 *)param_1;
    uStack_78 = *(undefined8 *)(param_1 + 8);
  }
  uVar4 = CONCAT71(DAT_1c0007038._1_7_,(byte)DAT_1c0007038);
  if (((DAT_1c0007028 < 5) || (((byte)DAT_1c0007038 & 2) == 0)) ||
     ((DAT_1c0007040 & 2) != DAT_1c0007040)) {
    local_90 = 0;
    lStack_88 = 0;
  }
  else {
    EtwActivityIdControl(3,&local_90);
    uVar4 = CONCAT71(DAT_1c0007038._1_7_,(byte)DAT_1c0007038);
  }
  if (((4 < DAT_1c0007028) && ((uVar4 & 2) != 0)) && ((DAT_1c0007040 & 2) == DAT_1c0007040)) {
    if ((param_1 != (_GUID *)0x0) &&
       ((((int)local_80 != 0 || (local_80._4_4_ != 0)) ||
        (((int)uStack_78 != 0 || (uStack_78._4_4_ != 0)))))) {
      puVar5 = &local_80;
    }
    else {
      puVar5 = (undefined8 *)0x0;
    }
    _tlgWriteTransfer_EtwWriteTransfer(0x1c0007028,&DAT_1c0005a51,&local_90,puVar5,2,&local_50);
  }
  local_70 = (char *)0x1;
  local_60 = 8;
  uStack_5c = 0;
  local_50 = 0;
  uStack_48 = 0;
  lVar3 = local_90;
  if (local_90 == 0) {
    lVar3 = lStack_88;
  }
  local_68 = this + 8;
  pWVar2 = (WDFIOTARGET__ *)
           (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,*(undefined8 *)this);
  p_Var6 = (_GUID *)&local_90;
  if (lVar3 == 0) {
    p_Var6 = (_GUID *)0x0;
  }
  lVar1 = TransactRequest(pWVar2,1,(_WDF_MEMORY_DESCRIPTOR *)&local_70,p_Var6);
  if (lVar1 < 0) {
    local_68._4_4_ = 0x91;
  }
  else {
    if (((byte)this[8] & 1) == 0) {
      lVar1 = -0x3fffff45;
      local_68._4_4_ = 0x94;
      local_60 = 1;
      goto LAB_1c0002821;
    }
    local_68 = this + 0x10;
    local_70 = (char *)0x1;
    local_60 = 0xc;
    uStack_5c = 0;
    local_50 = 0;
    uStack_48 = 0;
    lVar3 = local_90;
    if (local_90 == 0) {
      lVar3 = lStack_88;
    }
    pWVar2 = (WDFIOTARGET__ *)
             (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,*(undefined8 *)this);
    p_Var6 = (_GUID *)&local_90;
    if (lVar3 == 0) {
      p_Var6 = (_GUID *)0x0;
    }
    lVar1 = TransactRequest(pWVar2,2,(_WDF_MEMORY_DESCRIPTOR *)&local_70,p_Var6);
    if (-1 < lVar1) {
      if (((4 < DAT_1c0007028) && (((byte)DAT_1c0007038 & 2) != 0)) &&
         ((DAT_1c0007040 & 2) == DAT_1c0007040)) {
        _tlgWriteTransfer_EtwWriteTransfer(0x1c0007028,&DAT_1c00059a2,&local_90,0,2,&local_70);
      }
      return 0;
    }
    local_68._4_4_ = 0x9a;
  }
  local_60 = 0;
LAB_1c0002821:
  uStack_5c = 0;
  local_70 = "onecore\\vm\\dv\\crashdump\\driver\\lib\\hvcrashcontrol.cpp";
  local_58 = 0;
  local_68._0_4_ = lVar1;
  Diagnostics::NtStatus_ResultErrorCallback((ErrorContext *)&local_70);
  _tlgWriteActivityAutoStop<2,4>((_tlgProvider_t *)&DAT_1c0007028,(_GUID *)&local_90);
  return lVar1;
}



===== TransactRequest @ 1c000298c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001c0002d0f) */
/* WARNING: Removing unreachable block (ram,0x0001c0002ccd) */
/* WARNING: Removing unreachable block (ram,0x0001c0002d4d) */
/* WARNING: Removing unreachable block (ram,0x0001c0002d91) */
/* WARNING: Removing unreachable block (ram,0x0001c0002d9e) */
/* WARNING: Removing unreachable block (ram,0x0001c0002da7) */
/* WARNING: Removing unreachable block (ram,0x0001c0002dba) */
/* WARNING: Removing unreachable block (ram,0x0001c0002dfb) */
/* WARNING: Removing unreachable block (ram,0x0001c0002d84) */
/* WARNING: Removing unreachable block (ram,0x0001c0002cdb) */
/* WARNING: Removing unreachable block (ram,0x0001c0002c34) */
/* WARNING: Removing unreachable block (ram,0x0001c0002e05) */
/* WARNING: Removing unreachable block (ram,0x0001c0002e1f) */
/* WARNING: Removing unreachable block (ram,0x0001c0002e25) */
/* WARNING: Removing unreachable block (ram,0x0001c0002e39) */
/* long __cdecl TransactRequest(struct WDFIOTARGET__ * __ptr64,enum CrashDumpMessageType,struct
   _WDF_MEMORY_DESCRIPTOR & __ptr64,struct _GUID const * __ptr64) */

long __cdecl
TransactRequest(WDFIOTARGET__ *param_1,CrashDumpMessageType param_2,_WDF_MEMORY_DESCRIPTOR *param_3,
               _GUID *param_4)

{
  undefined1 auVar1 [16];
  int iVar2;
  undefined4 in_register_00000014;
  char *pcVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined1 auStackY_158 [32];
  undefined8 local_108;
  undefined8 *local_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  char *local_d8;
  int iStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined8 local_c0;
  int local_b8;
  char local_b4;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  char *local_80;
  undefined8 local_78 [4];
  char **local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  pcVar3 = (char *)CONCAT44(in_register_00000014,param_2);
  local_48 = __security_cookie ^ (ulonglong)auStackY_158;
  local_b8 = 0;
  local_b4 = param_4 != (_GUID *)0x0;
  if ((bool)local_b4) {
    local_a0 = *(undefined8 *)param_4;
    uStack_98 = *(undefined8 *)(param_4 + 8);
  }
  uVar4 = CONCAT71(DAT_1c0007038._1_7_,(byte)DAT_1c0007038);
  if (((DAT_1c0007028 < 6) || (((byte)DAT_1c0007038 & 2) == 0)) ||
     ((DAT_1c0007040 & 2) != DAT_1c0007040)) {
    local_b0._0_4_ = 0;
    local_b0._4_4_ = 0;
    uStack_a8._0_4_ = 0;
    uStack_a8._4_4_ = 0;
    local_b0 = 0;
    uStack_a8 = 0;
  }
  else {
    EtwActivityIdControl(3,&local_b0);
    uVar4 = CONCAT71(DAT_1c0007038._1_7_,(byte)DAT_1c0007038);
  }
  local_b8 = 1;
  uVar6 = (undefined4)local_b0;
  uVar7 = local_b0._4_4_;
  uVar8 = (undefined4)uStack_a8;
  uVar9 = uStack_a8._4_4_;
  if (((5 < DAT_1c0007028) && ((uVar4 & 2) != 0)) && ((DAT_1c0007040 & 2) == DAT_1c0007040)) {
    if ((local_b4 == '\0') ||
       ((((int)local_a0 == 0 && (local_a0._4_4_ == 0)) &&
        (((int)uStack_98 == 0 && (uStack_98._4_4_ == 0)))))) {
      puVar5 = (undefined8 *)0x0;
    }
    else {
      puVar5 = &local_a0;
    }
    local_58 = &local_d8;
    local_50 = 8;
    local_d8 = pcVar3;
    _tlgWriteTransfer_EtwWriteTransfer(0x1c0007028,&DAT_1c00059cc,&local_b0,puVar5,3,local_78);
    uVar6 = (undefined4)local_b0;
    uVar7 = local_b0._4_4_;
    uVar8 = (undefined4)uStack_a8;
    uVar9 = uStack_a8._4_4_;
  }
  local_90 = 0;
  uStack_88 = 0;
  local_d8 = (char *)0x0;
  iStack_d0 = 0;
  uStack_cc = 0;
  local_80 = pcVar3;
  if ((CONCAT44(uVar7,uVar6) == 0) &&
     (auVar1._4_4_ = uVar7, auVar1._0_4_ = uVar6, auVar1._8_4_ = uVar8, auVar1._12_4_ = uVar9,
     auVar1._8_8_ == 0)) {
    EtwActivityIdControl(3,&local_90);
  }
  else {
    local_90 = CONCAT44(uVar7,uVar6);
    uStack_88 = CONCAT44(uVar9,uVar8);
  }
  local_100 = &local_90;
  local_108 = 1;
  local_f8 = 0x18;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x5c0))(WdfDriverGlobals,param_1,0,&local_108);
  if (iVar2 < 0) {
    local_d8 = "onecore\\vm\\dv\\crashdump\\driver\\lib\\hvcrashcontrol.cpp";
    uStack_cc = 0x4a;
    uStack_c8 = 0;
    uStack_c4 = 0;
    local_c0 = 0;
    iStack_d0 = iVar2;
    Diagnostics::NtStatus_ResultErrorCallback((ErrorContext *)&local_d8);
  }
  else {
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x600))(WdfDriverGlobals,0,1,0x72437648);
    if (iVar2 < 0) {
      uStack_cc = 0x54;
    }
    else {
      local_e8 = 0;
      local_f0 = 3;
      local_e0 = 0;
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x5b0))(WdfDriverGlobals,param_1,0,&local_f0);
      if (-1 < iVar2) {
        uStack_cc = 100;
        iStack_d0 = 0xc00000e9;
        local_d8 = "onecore\\vm\\dv\\crashdump\\driver\\lib\\hvcrashcontrol.cpp";
        uStack_c8 = 1;
        uStack_c4 = 0;
        local_c0 = 0;
        Diagnostics::NtStatus_ResultErrorCallback((ErrorContext *)&local_d8);
        if (local_b8 == 1) {
          local_b8 = 2;
          _tlgWriteActivityAutoStop<2,5>((_tlgProvider_t *)&DAT_1c0007028,(_GUID *)&local_b0);
        }
        return -0x3fffff17;
      }
      uStack_cc = 0x5f;
    }
    uStack_c8 = 0;
    local_d8 = "onecore\\vm\\dv\\crashdump\\driver\\lib\\hvcrashcontrol.cpp";
    uStack_c4 = 0;
    local_c0 = 0;
    iStack_d0 = iVar2;
    Diagnostics::NtStatus_ResultErrorCallback((ErrorContext *)&local_d8);
  }
  if (local_b8 == 1) {
    local_b8 = 2;
    _tlgWriteActivityAutoStop<2,5>((_tlgProvider_t *)&DAT_1c0007028,(_GUID *)&local_b0);
  }
  return iVar2;
}



===== DumpComplete @ 1c0002e6c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl HvCrashWriter::DumpComplete(struct _DUMP_CLEANUP_INFO & __ptr64,struct _GUID
   const * __ptr64) __ptr64 */

long __thiscall
HvCrashWriter::DumpComplete(HvCrashWriter *this,_DUMP_CLEANUP_INFO *param_1,_GUID *param_2)

{
  undefined1 auStack_68 [32];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  ulonglong uStack_20;
  uint local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  uStack_30 = 0;
  local_18 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 5;
  local_28 = 0;
  uStack_20 = 0;
  EtwActivityIdControl(3,&local_48);
  uStack_30 = *(undefined8 *)(this + 4);
  local_28 = (ulonglong)CONCAT24(*(undefined2 *)(this + 0x114),*(undefined4 *)(this + 0xc));
  uStack_20 = (ulonglong)CONCAT24(*(undefined2 *)(this + 0x118),(uint)*(ushort *)(this + 0x116));
  local_18 = (uint)(byte)this[0x11a];
  Details::VmbCrashWrite((_VMBUS_CRASH_INTERFACE *)(this + 0x128),&local_48,0x34,false);
  return 0;
}



===== DumpPrepare @ 1c0002f2c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl HvCrashWriter::DumpPrepare(struct _DUMP_PREPARE_INFO & __ptr64,struct _GUID
   const * __ptr64) __ptr64 */

long __thiscall
HvCrashWriter::DumpPrepare(HvCrashWriter *this,_DUMP_PREPARE_INFO *param_1,_GUID *param_2)

{
  _VMBUS_CRASH_INTERFACE *p_Var1;
  char cVar2;
  long lVar3;
  undefined1 auStackY_a8 [32];
  undefined4 local_74;
  char *local_70;
  long local_68;
  undefined4 local_64;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  int local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_a8;
  p_Var1 = (_VMBUS_CRASH_INTERFACE *)(this + 0x128);
  cVar2 = (**(code **)(this + 0x130))(*(undefined8 *)p_Var1);
  if (cVar2 == '\0') {
    local_58 = 0;
    local_70 = "onecore\\vm\\dv\\crashdump\\driver\\lib\\hvcrashwriter.cpp";
    local_68 = 0xc0000001;
    local_64 = 0xcb;
    local_60 = 1;
    Diagnostics::NtStatus_ResultErrorCallback((ErrorContext *)&local_70);
    lVar3 = -0x3fffffff;
  }
  else {
    local_48 = 0;
    local_40 = 0;
    local_38 = 3;
    EtwActivityIdControl(3,&local_48);
    lVar3 = Details::VmbCrashWrite(p_Var1,&local_48,0x18,false);
    if (lVar3 < 0) {
      local_70 = "onecore\\vm\\dv\\crashdump\\driver\\lib\\hvcrashwriter.cpp";
      local_58 = 0;
      local_64 = 0xd4;
      local_60 = 0;
      local_68 = lVar3;
      Diagnostics::NtStatus_ResultErrorCallback((ErrorContext *)&local_70);
    }
    else {
      local_50 = 0;
      local_74 = 0;
      local_30 = 0;
      uStack_28 = 0;
      local_20 = 0;
      local_18 = 0;
      while( true ) {
        cVar2 = (**(code **)(this + 0x140))(*(undefined8 *)p_Var1,&local_74,&local_50,&local_30);
        if (cVar2 != '\0') break;
        KeStallExecutionProcessor(0x32);
      }
      if (local_18 == 0) {
        lVar3 = 0;
      }
      else {
        lVar3 = Diagnostics::NtStatus_ErrorMsg
                          (0xdf,"onecore\\vm\\dv\\crashdump\\driver\\lib\\hvcrashwriter.cpp",
                           -0x3fffffff,1,"host status 0x%08x");
      }
    }
  }
  return lVar3;
}



===== DumpWrite @ 1c00030c8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl HvCrashWriter::DumpWrite(unsigned __int64,struct _MDL * __ptr64,struct _GUID
   const * __ptr64) __ptr64 */

long __thiscall
HvCrashWriter::DumpWrite(HvCrashWriter *this,__uint64 param_1,_MDL *param_2,_GUID *param_3)

{
  long lVar1;
  uint uVar2;
  void *pvVar3;
  undefined1 auStack_a8 [32];
  undefined4 local_88;
  undefined4 local_80;
  char *local_78;
  long local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  __uint64 local_40;
  uint local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_a8;
  if (((byte)param_2[10] & 5) == 0) {
    local_80 = 0xc0000020;
    local_88 = 0;
    pvVar3 = (void *)MmMapLockedPagesSpecifyCache(param_2,0,1);
  }
  else {
    pvVar3 = *(void **)(param_2 + 0x18);
  }
  uVar2 = *(uint *)(param_2 + 0x28);
  if (uVar2 != 0) {
    do {
      local_58 = 0;
      local_50 = 0;
      local_40 = 0;
      local_38 = 0;
      local_48 = 4;
      EtwActivityIdControl(3,&local_58);
      local_38 = 0x4000;
      if (uVar2 < 0x4000) {
        local_38 = uVar2;
      }
      local_40 = param_1;
      Details::VmbCrashWrite((_VMBUS_CRASH_INTERFACE *)(this + 0x128),&local_58,0x24,false);
      lVar1 = Details::VmbCrashWrite((_VMBUS_CRASH_INTERFACE *)(this + 0x128),pvVar3,local_38,true);
      if (lVar1 < 0) {
        local_68 = 0;
        local_78 = "onecore\\vm\\dv\\crashdump\\driver\\lib\\hvcrashwriter.cpp";
        local_60 = 0;
        local_6c = 0x108;
        local_64 = 0;
        local_70 = lVar1;
        Diagnostics::NtStatus_ResultErrorCallback((ErrorContext *)&local_78);
        return lVar1;
      }
      param_1 = param_1 + local_38;
      pvVar3 = (void *)((longlong)pvVar3 + (ulonglong)local_38);
      uVar2 = uVar2 - local_38;
    } while (uVar2 != 0);
  }
  return 0;
}



===== Initialize @ 1c0003214 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl HvCrashWriter::Initialize(struct WDFDEVICE__ * __ptr64,struct _GUID const *
   __ptr64) __ptr64 */

long __thiscall HvCrashWriter::Initialize(HvCrashWriter *this,WDFDEVICE__ *param_1,_GUID *param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStack_c8 [32];
  undefined4 *local_a8;
  undefined4 *local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined4 local_78;
  undefined4 local_74;
  HvCrashWriter *local_70;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  char *local_48;
  int local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_c8;
  local_20 = 0;
  local_58 = &local_28;
  local_5c = 0;
  local_4c = 0;
  local_74 = 0;
  local_64 = 0;
  local_70 = this + 0x128;
  local_28 = 6;
  local_24 = 0x12;
  local_60 = 1;
  local_50 = 0x10;
  local_78 = 1;
  local_68 = 0x30;
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals);
  local_90 = 0;
  local_98 = 0;
  local_a0 = &local_78;
  local_a8 = &local_60;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x5d0))(WdfDriverGlobals,uVar2,0,0x3ec080);
  if (iVar1 < 0) {
    local_38 = 0;
    local_48 = "onecore\\vm\\dv\\crashdump\\driver\\lib\\hvcrashwriter.cpp";
    local_30 = 0;
    local_3c = 0xa3;
    local_34 = 0;
    local_40 = iVar1;
    Diagnostics::NtStatus_ResultErrorCallback((ErrorContext *)&local_48);
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



===== NtStatus_ErrorMsg @ 1c0003344 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl Diagnostics::NtStatus_ErrorMsg(unsigned short,char const * __ptr64,long,enum
   Diagnostics::ErrorType,char const * __ptr64,...) */

long __cdecl
Diagnostics::NtStatus_ErrorMsg
          (ushort param_1,char *param_2,long param_3,ErrorType param_4,char *param_5,...)

{
  char cStack0000000000000030;
  undefined1 auStack_278 [32];
  char *local_258;
  long local_250;
  ushort local_24c;
  undefined2 local_24a;
  ErrorType local_248;
  undefined4 local_244;
  char *local_240;
  char local_228 [512];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_278;
  local_240 = (char *)0x0;
  local_24a = 0;
  local_244 = 0;
  local_258 = param_2;
  local_250 = param_3;
  local_24c = param_1;
  local_248 = param_4;
  if (param_5 != (char *)0x0) {
    _vsnprintf(local_228,0x1ff,param_5,&cStack0000000000000030);
    local_240 = local_228;
  }
  NtStatus_ResultErrorCallback((ErrorContext *)&local_258);
  return param_3;
}



===== PollForWriteErrorResponse @ 1c00033ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001c000346d) */
/* long __cdecl Details::PollForWriteErrorResponse(struct _VMBUS_CRASH_INTERFACE & __ptr64) */

long __cdecl Details::PollForWriteErrorResponse(_VMBUS_CRASH_INTERFACE *param_1)

{
  char cVar1;
  long lVar2;
  undefined1 auStackY_78 [32];
  undefined4 local_44;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  longlong local_28;
  int local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_40 = 0;
  local_44 = 0;
  local_28 = 0;
  local_20 = 0;
  local_38 = 0;
  uStack_30 = 0;
  cVar1 = (**(code **)(param_1 + 0x18))(*(undefined8 *)param_1,&local_44,&local_40,&local_38);
  if ((cVar1 == '\0') || (local_28 != 0x10004)) {
    lVar2 = 0;
  }
  else {
    if (((*(uint *)(WdfDriverGlobals + 8) & 4) != 0) && (local_20 == 0)) {
      RtlAssert("response.Status != 0","onecore\\vm\\dv\\crashdump\\driver\\lib\\hvcrashwriter.cpp",
                0x40);
    }
    lVar2 = Diagnostics::NtStatus_ErrorMsg
                      (0x42,"onecore\\vm\\dv\\crashdump\\driver\\lib\\hvcrashwriter.cpp",-0x3fffffff
                       ,1,"host status 0x%08x");
  }
  return lVar2;
}



===== VmbCrashWrite @ 1c0003510 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl Details::VmbCrashWrite(struct _VMBUS_CRASH_INTERFACE & __ptr64,void *
   __ptr64,unsigned int,bool) */

long __cdecl
Details::VmbCrashWrite(_VMBUS_CRASH_INTERFACE *param_1,void *param_2,uint param_3,bool param_4)

{
  char cVar1;
  long lVar2;
  char *local_38;
  long local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined8 local_20;
  
  if (((*(uint *)(WdfDriverGlobals + 8) & 4) != 0) && (0x4000 < param_3)) {
    RtlAssert("ByteCount <= HvCrashWriter::c_MaxIoSize",
              "onecore\\vm\\dv\\crashdump\\driver\\lib\\hvcrashwriter.cpp",0x5b);
  }
  do {
    cVar1 = (**(code **)(param_1 + 0x10))(*(undefined8 *)param_1,1,0,param_2,param_3,0,0);
    if (cVar1 != '\0') {
      if ((!param_4) || (lVar2 = PollForWriteErrorResponse(param_1), -1 < lVar2)) {
        return 0;
      }
      local_2c = 0x69;
LAB_1c00035d0:
      local_28 = 0;
      local_20 = 0;
      local_38 = "onecore\\vm\\dv\\crashdump\\driver\\lib\\hvcrashwriter.cpp";
      local_24 = 0;
      local_30 = lVar2;
      Diagnostics::NtStatus_ResultErrorCallback((ErrorContext *)&local_38);
      return lVar2;
    }
    if ((param_4) && (lVar2 = PollForWriteErrorResponse(param_1), lVar2 < 0)) {
      local_2c = 0x61;
      goto LAB_1c00035d0;
    }
    KeStallExecutionProcessor(0x32);
  } while( true );
}



===== _guard_check_icall @ 1c0003640 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c0003658 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c000367c =====

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



===== __cpu_features_init @ 1c00036f0 =====

/* WARNING: Removing unreachable block (ram,0x0001c000375a) */
/* WARNING: Removing unreachable block (ram,0x0001c0003709) */
/* WARNING: Removing unreachable block (ram,0x0001c00036fa) */

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



===== __security_check_cookie @ 1c00037c0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0003800 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0003830 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0003830. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0003860 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memset @ 1c00038c0 =====

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



===== __memset_repmovs @ 1c0003a00 =====

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



===== __memset_query @ 1c0003a80 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0003b00 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0003c40 =====

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



===== __memset_spec_plain @ 1c0003cc0 =====

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



===== HvCrashDeviceControl @ 1c000a010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void HvCrashDeviceControl
               (undefined8 param_1,WDFREQUEST__ *param_2,undefined8 param_3,undefined8 param_4,
               int param_5)

{
  char cVar1;
  long lVar2;
  WDFDEVICE__ *pWVar3;
  ulonglong uVar4;
  int *piVar5;
  undefined1 auStackY_b8 [32];
  int local_88 [2];
  int local_80;
  char local_7c;
  undefined8 local_78;
  undefined8 uStack_70;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  undefined8 local_58 [4];
  int *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_80 = 0;
  uVar4 = CONCAT71(DAT_1c0007038._1_7_,(byte)DAT_1c0007038);
  local_7c = '\0';
  if (((DAT_1c0007028 < 5) || (((byte)DAT_1c0007038 & 1) == 0)) ||
     (((uint)DAT_1c0007040 & 1) != DAT_1c0007040)) {
    local_78 = 0;
    uStack_70 = 0;
  }
  else {
    EtwActivityIdControl(3,&local_78);
    uVar4 = CONCAT71(DAT_1c0007038._1_7_,(byte)DAT_1c0007038);
  }
  local_80 = 1;
  if (((4 < DAT_1c0007028) && ((uVar4 & 1) != 0)) && (((uint)DAT_1c0007040 & 1) == DAT_1c0007040)) {
    local_88[0] = param_5;
    if ((local_7c == '\0') ||
       (((local_68 == 0 && (local_64 == 0)) && ((local_60 == 0 && (local_5c == 0)))))) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = &local_68;
    }
    local_2c = 0;
    local_38 = local_88;
    local_30 = 4;
    _tlgWriteTransfer_EtwWriteTransfer(0x1c0007028,&DAT_1c0005775,&local_78,piVar5,3,local_58);
  }
  cVar1 = (**(code **)(WdfFunctions_01015 + 0x8c0))(WdfDriverGlobals,param_2);
  if (cVar1 == '\0') {
    if (param_5 == 0x70048) {
      pWVar3 = (WDFDEVICE__ *)(**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
      lVar2 = CrashdumpShim::GetPartitionInfo(pWVar3,param_2);
      goto LAB_1c000a201;
    }
    if (param_5 == 0x700a0) {
      pWVar3 = (WDFDEVICE__ *)(**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
      lVar2 = CrashdumpShim::GetDriveGeometry(pWVar3,param_2);
      goto LAB_1c000a201;
    }
    if (param_5 == 0x2d164b) {
      pWVar3 = (WDFDEVICE__ *)(**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
      lVar2 = CrashdumpShim::GetDumpInfo(pWVar3,param_2);
      goto LAB_1c000a201;
    }
    if (param_5 == 0x560000) {
      pWVar3 = (WDFDEVICE__ *)(**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
      lVar2 = CrashdumpShim::GetVolumeDiskExtents(pWVar3,param_2);
      goto LAB_1c000a201;
    }
  }
  lVar2 = -0x3fffff45;
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc00000bb);
LAB_1c000a201:
  local_80 = 2;
  if (((4 < DAT_1c0007028) && (((byte)DAT_1c0007038 & 1) != 0)) &&
     (((uint)DAT_1c0007040 & 1) == DAT_1c0007040)) {
    local_2c = 0;
    local_38 = local_88;
    local_30 = 4;
    local_88[0] = lVar2;
    _tlgWriteTransfer_EtwWriteTransfer(0x1c0007028,&DAT_1c0005748,&local_78,0,3,local_58);
    if (local_80 == 1) {
      local_80 = 2;
      _tlgWriteActivityAutoStop<1,4>((_tlgProvider_t *)&DAT_1c0007028,(_GUID *)&local_78);
    }
  }
  return;
}



===== HvCrashEvtDeviceAdd @ 1c000a2b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int HvCrashEvtDeviceAdd(undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  HvCrashControl *this;
  int iVar2;
  longlong lVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  int *piVar6;
  undefined1 auStackY_238 [32];
  undefined8 local_1f8;
  undefined8 local_1f0;
  undefined8 local_1e8;
  wchar_t *local_1e0;
  undefined8 local_1d8;
  undefined8 local_1d0;
  undefined8 uStack_1c8;
  undefined8 local_1c0;
  undefined8 uStack_1b8;
  undefined8 local_1b0;
  undefined8 uStack_1a8;
  undefined *local_1a0;
  undefined4 local_198;
  undefined8 local_194;
  undefined1 local_18b;
  code *local_170;
  undefined4 local_138 [16];
  code *local_f8;
  code *local_f0;
  int local_a8;
  char local_a4;
  undefined8 local_a0;
  undefined8 uStack_98;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  char *local_80;
  int local_78;
  undefined4 local_74;
  undefined4 uStack_70;
  undefined4 local_6c;
  undefined8 local_68;
  wchar_t local_60 [20];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_238;
  uVar5 = CONCAT71(DAT_1c0007038._1_7_,(byte)DAT_1c0007038);
  local_a8 = 0;
  local_a4 = '\0';
  local_1f8 = param_2;
  if (((DAT_1c0007028 < 5) || (((byte)DAT_1c0007038 & 1) == 0)) ||
     ((DAT_1c0007040 & 1) != DAT_1c0007040)) {
    local_a0 = 0;
    uStack_98 = 0;
  }
  else {
    EtwActivityIdControl(3,&local_a0);
    uVar5 = CONCAT71(DAT_1c0007038._1_7_,(byte)DAT_1c0007038);
  }
  local_a8 = 1;
  if (((4 < DAT_1c0007028) && ((uVar5 & 1) != 0)) && ((DAT_1c0007040 & 1) == DAT_1c0007040)) {
    if ((local_a4 == '\0') ||
       (((local_90 == 0 && (local_8c == 0)) && ((local_88 == 0 && (local_84 == 0)))))) {
      piVar6 = (int *)0x0;
    }
    else {
      piVar6 = &local_90;
    }
    _tlgWriteTransfer_EtwWriteTransfer(0x1c0007028,&DAT_1c0005875,&local_a0,piVar6,2,&local_80);
  }
  local_1a0 = PTR__WDF_HVCRASH_DEVICE_CONTEXT_TYPE_INFO_1c0007018;
  local_1c0 = 0;
  uStack_1c8 = 0;
  local_1d0 = 0x38;
  uStack_1b8 = 0x100000001;
  local_1b0 = 0;
  uStack_1a8 = 0;
  memset(local_138,0,0x90);
  local_f0 = HvCrashEvtDeviceSelfManagedIoInit;
  local_f8 = HvCrashEvtDeviceSelfManagedIoFlush;
  local_138[0] = 0x90;
  (**(code **)(WdfFunctions_01015 + 0x1b8))(WdfDriverGlobals,local_1f8,local_138);
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x248))
                    (WdfDriverGlobals,local_1f8,HvCrashEvtIrpFileSystemControl,0xd);
  if (iVar2 < 0) {
    local_74 = 0xcd;
  }
  else {
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x248))
                      (WdfDriverGlobals,local_1f8,HvCrashEvtIrpQueryInformation,5);
    if (iVar2 < 0) {
      local_74 = 0xd2;
    }
    else {
      local_1e0 = local_60;
      builtin_wcsncpy(local_60,L"\\Device\\HvCrashD",0x10);
      local_1e8 = 0x280026;
      builtin_wcsncpy(local_60 + 0x10,L"ump",4);
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x218))(WdfDriverGlobals,local_1f8,&local_1e8);
      if (iVar2 < 0) {
        local_74 = 0xd5;
      }
      else {
        local_1f0 = 0;
        iVar2 = (**(code **)(WdfFunctions_01015 + 600))
                          (WdfDriverGlobals,&local_1f8,&local_1d0,&local_1f0);
        if (-1 < iVar2) {
          (**(code **)(WdfFunctions_01015 + 0x188))(WdfDriverGlobals,local_1f0,3);
          lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                            (WdfDriverGlobals,local_1f0,
                             PTR__WDF_HVCRASH_DEVICE_CONTEXT_TYPE_INFO_1c0007018);
          memset(&local_198,0,0x60);
          local_198 = 0x60;
          local_194 = 1;
          local_18b = 1;
          local_170 = HvCrashDeviceControl;
          local_1d8 = 0;
          iVar2 = (**(code **)(WdfFunctions_01015 + 0x4c0))(WdfDriverGlobals,local_1f0,&local_198);
          if (iVar2 < 0) {
            local_80 = "onecore\\vm\\dv\\crashdump\\driver\\sys\\drivermain.cpp";
            local_74 = 0xe8;
            uStack_70 = 0;
            local_6c = 0;
            local_68 = 0;
            local_78 = iVar2;
            Diagnostics::NtStatus_ResultErrorCallback((ErrorContext *)&local_80);
            if (local_a8 == 1) {
              local_a8 = 2;
              _tlgWriteActivityAutoStop<1,4>((_tlgProvider_t *)&DAT_1c0007028,(_GUID *)&local_a0);
            }
            return iVar2;
          }
          lVar1 = *(longlong *)(lVar3 + 0x10);
          *(undefined8 *)(lVar3 + 0x10) = 0;
          if (lVar1 != 0) {
            ExFreePoolWithTag(lVar1,0);
          }
          puVar4 = (undefined8 *)ExAllocatePool2(0x40,0x28,0x72437648);
          if (puVar4 == (undefined8 *)0x0) {
            puVar4 = (undefined8 *)0x0;
          }
          else {
            *puVar4 = local_1f0;
            puVar4[1] = 0;
            puVar4[2] = 0;
            *(undefined4 *)(puVar4 + 3) = 0;
            puVar4[4] = 0;
          }
          this = *(HvCrashControl **)(lVar3 + 8);
          *(undefined8 **)(lVar3 + 8) = puVar4;
          if (this != (HvCrashControl *)0x0) {
            HvCrashControl::~HvCrashControl(this);
            ExFreePoolWithTag(this,0);
          }
          if (*(longlong *)(lVar3 + 8) != 0) {
            local_a8 = 2;
            if ((((4 < DAT_1c0007028) && (((byte)DAT_1c0007038 & 1) != 0)) &&
                ((DAT_1c0007040 & 1) == DAT_1c0007040)) &&
               (_tlgWriteTransfer_EtwWriteTransfer
                          (0x1c0007028,&DAT_1c00057d9,&local_a0,0,2,&local_80), local_a8 == 1)) {
              local_a8 = 2;
              _tlgWriteActivityAutoStop<1,4>((_tlgProvider_t *)&DAT_1c0007028,(_GUID *)&local_a0);
            }
            return 0;
          }
          iVar2 = -0x3fffff66;
          local_74 = 0xec;
          uStack_70 = 1;
          goto LAB_1c000a4b5;
        }
        local_74 = 0xd8;
      }
    }
  }
  uStack_70 = 0;
LAB_1c000a4b5:
  local_6c = 0;
  local_80 = "onecore\\vm\\dv\\crashdump\\driver\\sys\\drivermain.cpp";
  local_68 = 0;
  local_78 = iVar2;
  Diagnostics::NtStatus_ResultErrorCallback((ErrorContext *)&local_80);
  if (local_a8 == 1) {
    local_a8 = 2;
    _tlgWriteActivityAutoStop<1,4>((_tlgProvider_t *)&DAT_1c0007028,(_GUID *)&local_a0);
  }
  return iVar2;
}



===== HvCrashEvtDeviceSelfManagedIoFlush @ 1c000a870 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void HvCrashEvtDeviceSelfManagedIoFlush(undefined8 param_1)

{
  HvCrashControl *this;
  longlong lVar1;
  longlong lVar2;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_HVCRASH_DEVICE_CONTEXT_TYPE_INFO_1c0007018);
  this = *(HvCrashControl **)(lVar2 + 8);
  *(undefined8 *)(lVar2 + 8) = 0;
  if (this != (HvCrashControl *)0x0) {
    HvCrashControl::~HvCrashControl(this);
    ExFreePoolWithTag(this,0);
  }
  lVar1 = *(longlong *)(lVar2 + 0x10);
  *(undefined8 *)(lVar2 + 0x10) = 0;
  if (lVar1 != 0) {
    ExFreePoolWithTag(lVar1,0);
  }
  return;
}



===== HvCrashEvtDeviceSelfManagedIoInit @ 1c000a900 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001c000a9bf) */
/* WARNING: Removing unreachable block (ram,0x0001c000a9c4) */
/* WARNING: Removing unreachable block (ram,0x0001c000a9c9) */
/* WARNING: Removing unreachable block (ram,0x0001c000a9ce) */
/* WARNING: Removing unreachable block (ram,0x0001c000a9d3) */
/* WARNING: Removing unreachable block (ram,0x0001c000ab01) */

long HvCrashEvtDeviceSelfManagedIoInit(undefined8 param_1)

{
  long lVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  _GUID *p_Var5;
  undefined1 auStackY_88 [32];
  longlong local_50;
  longlong lStack_48;
  char *local_30;
  long lStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_88;
  uVar4 = CONCAT71(DAT_1c0007038._1_7_,(byte)DAT_1c0007038);
  if (((DAT_1c0007028 < 5) || (((byte)DAT_1c0007038 & 1) == 0)) ||
     (((uint)DAT_1c0007040 & 1) != DAT_1c0007040)) {
    local_50 = 0;
    lStack_48 = 0;
  }
  else {
    EtwActivityIdControl(3,&local_50);
    uVar4 = CONCAT71(DAT_1c0007038._1_7_,(byte)DAT_1c0007038);
  }
  if (((4 < DAT_1c0007028) && ((uVar4 & 1) != 0)) && (((uint)DAT_1c0007040 & 1) == DAT_1c0007040)) {
    _tlgWriteTransfer_EtwWriteTransfer(0x1c0007028,&DAT_1c0005898,&local_50,0,2,&local_30);
  }
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_HVCRASH_DEVICE_CONTEXT_TYPE_INFO_1c0007018);
  local_30 = (char *)0x0;
  lStack_28 = 0;
  uStack_24 = 0;
  lVar3 = local_50;
  if (local_50 == 0) {
    lVar3 = lStack_48;
  }
  p_Var5 = (_GUID *)&local_50;
  if (lVar3 == 0) {
    p_Var5 = (_GUID *)0x0;
  }
  lVar1 = HvCrashControl::Initialize(*(HvCrashControl **)(lVar2 + 8),p_Var5);
  if (lVar1 < 0) {
    local_30 = "onecore\\vm\\dv\\crashdump\\driver\\sys\\drivermain.cpp";
    uStack_24 = 0x109;
    uStack_20 = 0;
    local_1c = 0;
    local_18 = 0;
    lStack_28 = lVar1;
    Diagnostics::NtStatus_ResultErrorCallback((ErrorContext *)&local_30);
    _tlgWriteActivityAutoStop<1,4>((_tlgProvider_t *)&DAT_1c0007028,(_GUID *)&local_50);
  }
  else {
    if (((4 < DAT_1c0007028) && (((byte)DAT_1c0007038 & 1) != 0)) &&
       (((uint)DAT_1c0007040 & 1) == DAT_1c0007040)) {
      _tlgWriteTransfer_EtwWriteTransfer(0x1c0007028,&DAT_1c00057a8,&local_50,0,2,&local_30);
    }
    lVar1 = 0;
  }
  return lVar1;
}



===== HvCrashEvtDriverCleanup @ 1c000ab50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void HvCrashEvtDriverCleanup(undefined8 param_1)

{
  undefined8 uVar1;
  
  (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,param_1);
  uVar1 = DAT_1c0007048;
  DAT_1c0007048 = 0;
  DAT_1c0007028 = 0;
  EtwUnregister(uVar1);
  return;
}



===== HvCrashEvtIrpFileSystemControl @ 1c000aba0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long HvCrashEvtIrpFileSystemControl(undefined8 param_1,_IRP *param_2)

{
  int iVar1;
  longlong lVar2;
  long lVar3;
  int *piVar4;
  undefined1 auStackY_c8 [32];
  long local_98;
  undefined4 local_94;
  int *local_90;
  long *local_88;
  undefined1 local_80;
  int local_78;
  char local_74;
  undefined8 local_70;
  undefined8 uStack_68;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  char *local_50;
  long local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined8 local_38;
  undefined4 *local_30;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_c8;
  lVar2 = *(longlong *)(param_2 + 0xb8);
  local_78 = 0;
  local_74 = '\0';
  if (((DAT_1c0007028 < 5) || ((DAT_1c0007038 & 1) == 0)) || ((DAT_1c0007040 & 1) != DAT_1c0007040))
  {
    local_70 = 0;
    uStack_68 = 0;
  }
  else {
    EtwActivityIdControl(3,&local_70);
  }
  local_78 = 1;
  if (((4 < DAT_1c0007028) && ((DAT_1c0007038 & 1) != 0)) && ((DAT_1c0007040 & 1) == DAT_1c0007040))
  {
    local_94 = *(undefined4 *)(lVar2 + 0x18);
    if ((local_74 == '\0') ||
       (((local_60 == 0 && (local_5c == 0)) && ((local_58 == 0 && (local_54 == 0)))))) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = &local_60;
    }
    local_30 = &local_94;
    local_28 = 4;
    _tlgWriteTransfer_EtwWriteTransfer(0x1c0007028,&DAT_1c0005939,&local_70,piVar4,3,&local_50);
  }
  local_90 = &local_78;
  local_98 = -0x3fffffff;
  local_88 = &local_98;
  if (param_2[0x40] == (_IRP)0x0) {
    iVar1 = *(int *)(lVar2 + 0x18);
    if (iVar1 == 0x9003b) {
      local_98 = CrashdumpShim::QueryRetrivalPointers(param_2);
      if (-1 < local_98) {
LAB_1c000ad42:
        local_80 = 0;
        <lambda_2c9f845d685a0ccedaec2df770c4e004>::operator()(&local_90);
        if (local_78 == 1) {
          local_78 = 2;
          _tlgWriteActivityAutoStop<1,4>((_tlgProvider_t *)&DAT_1c0007028,(_GUID *)&local_70);
        }
        return 0;
      }
      local_44 = 399;
      goto LAB_1c000ad8a;
    }
    if (iVar1 == 0x90204) {
      *(undefined4 *)(param_2 + 0x30) = 0;
      IofCompleteRequest();
      local_98 = 0;
      goto LAB_1c000ad42;
    }
    *(undefined4 *)(param_2 + 0x30) = 0xc00000bb;
    IofCompleteRequest(param_2,0);
    local_44 = 0x19a;
  }
  else {
    *(undefined4 *)(param_2 + 0x30) = 0xc00000bb;
    IofCompleteRequest(param_2,0);
    local_44 = 0x189;
  }
  local_98 = -0x3fffff45;
LAB_1c000ad8a:
  lVar3 = local_98;
  local_50 = "onecore\\vm\\dv\\crashdump\\driver\\sys\\drivermain.cpp";
  local_40 = 1;
  local_38 = 0;
  local_48 = local_98;
  Diagnostics::NtStatus_ResultErrorCallback((ErrorContext *)&local_50);
  local_80 = 0;
  <lambda_2c9f845d685a0ccedaec2df770c4e004>::operator()(&local_90);
  if (local_78 == 1) {
    local_78 = 2;
    _tlgWriteActivityAutoStop<1,4>((_tlgProvider_t *)&DAT_1c0007028,(_GUID *)&local_70);
  }
  return lVar3;
}



===== HvCrashEvtIrpQueryInformation @ 1c000ae10 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 HvCrashEvtIrpQueryInformation(undefined8 param_1,longlong param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  longlong lVar3;
  int *piVar4;
  undefined1 auStackY_c8 [32];
  undefined4 local_98;
  undefined4 local_94;
  int *local_90;
  undefined4 *local_88;
  undefined1 local_80;
  int local_78;
  char local_74;
  undefined8 local_70;
  undefined8 uStack_68;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  char *local_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined8 local_38;
  undefined4 *local_30;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_c8;
  lVar3 = *(longlong *)(param_2 + 0xb8);
  local_78 = 0;
  local_74 = '\0';
  if (((DAT_1c0007028 < 5) || ((DAT_1c0007038 & 1) == 0)) ||
     (((uint)DAT_1c0007040 & 1) != DAT_1c0007040)) {
    local_70 = 0;
    uStack_68 = 0;
  }
  else {
    EtwActivityIdControl(3,&local_70);
  }
  local_78 = 1;
  if (((4 < DAT_1c0007028) && ((DAT_1c0007038 & 1) != 0)) &&
     (((uint)DAT_1c0007040 & 1) == DAT_1c0007040)) {
    local_94 = *(undefined4 *)(lVar3 + 0x10);
    if ((local_74 == '\0') ||
       (((local_60 == 0 && (local_5c == 0)) && ((local_58 == 0 && (local_54 == 0)))))) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = &local_60;
    }
    local_30 = &local_94;
    local_28 = 4;
    _tlgWriteTransfer_EtwWriteTransfer(0x1c0007028,&DAT_1c00057fc,&local_70,piVar4,3,&local_50);
  }
  local_90 = &local_78;
  local_98 = 0xc0000001;
  local_88 = &local_98;
  if (*(char *)(param_2 + 0x40) == '\0') {
    if (*(int *)(lVar3 + 0x10) == 5) {
      lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,param_1,
                         PTR__WDF_HVCRASH_DEVICE_CONTEXT_TYPE_INFO_1c0007018);
      puVar1 = *(undefined8 **)(param_2 + 0x18);
      uVar2 = *(undefined8 *)(*(longlong *)(lVar3 + 8) + 0x10);
      *puVar1 = uVar2;
      puVar1[1] = uVar2;
      *(undefined4 *)(puVar1 + 2) = 0;
      *(undefined2 *)((longlong)puVar1 + 0x14) = 0;
      *(undefined8 *)(param_2 + 0x38) = 0x18;
      *(undefined4 *)(param_2 + 0x30) = 0;
      IofCompleteRequest(param_2,0);
      local_98 = 0;
      local_80 = 0;
      <lambda_943ce50503ab45fdba1c243ff726252d>::operator()(&local_90);
      if (local_78 == 1) {
        local_78 = 2;
        _tlgWriteActivityAutoStop<1,4>((_tlgProvider_t *)&DAT_1c0007028,(_GUID *)&local_70);
      }
      return 0;
    }
    *(undefined4 *)(param_2 + 0x30) = 0xc00000bb;
    IofCompleteRequest(param_2,0);
    local_44 = 0x1d2;
  }
  else {
    *(undefined4 *)(param_2 + 0x30) = 0xc00000bb;
    IofCompleteRequest(param_2,0);
    local_44 = 0x1bc;
  }
  local_98 = 0xc00000bb;
  local_50 = "onecore\\vm\\dv\\crashdump\\driver\\sys\\drivermain.cpp";
  local_48 = 0xc00000bb;
  local_40 = 1;
  local_38 = 0;
  Diagnostics::NtStatus_ResultErrorCallback((ErrorContext *)&local_50);
  local_80 = 0;
  <lambda_943ce50503ab45fdba1c243ff726252d>::operator()(&local_90);
  if (local_78 == 1) {
    local_78 = 2;
    _tlgWriteActivityAutoStop<1,4>((_tlgProvider_t *)&DAT_1c0007028,(_GUID *)&local_70);
  }
  return 0xc00000bb;
}



===== _tlgEnableCallback @ 1c000b0b0 =====

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



===== __security_init_cookie @ 1c000c008 =====

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



===== DriverEntry @ 1c000c03c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(undefined8 param_1,undefined8 param_2)

{
  undefined2 uVar1;
  code *pcVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 auStack_d8 [8];
  undefined1 auStack_d0 [24];
  undefined4 *local_b8;
  WDFDRIVER__ **local_b0;
  WDFDRIVER__ *local_98;
  undefined4 local_90;
  undefined4 local_8c;
  code *local_88;
  undefined8 local_80;
  undefined4 local_78;
  undefined4 local_74;
  undefined8 local_70;
  code *pcStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  char *local_38;
  int iStack_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_d8;
  local_8c = 0;
  local_b0 = &local_98;
  local_80 = 0;
  local_78 = 0;
  local_98 = (WDFDRIVER__ *)0x0;
  local_40 = 0;
  local_60 = 0;
  uStack_58 = 0x100000001;
  pcStack_68 = HvCrashEvtDriverCleanup;
  local_b8 = &local_90;
  local_88 = HvCrashEvtDeviceAdd;
  local_50 = 0;
  uStack_48 = 0;
  local_70 = 0x38;
  local_90 = 0x20;
  local_74 = 0x72437648;
  iVar3 = (**(code **)(WdfFunctions_01015 + 0x3a0))(WdfDriverGlobals,param_1,param_2,&local_70);
  puVar4 = auStack_d8;
  if (iVar3 < 0) {
    local_28 = 0;
    local_38 = "onecore\\vm\\dv\\crashdump\\driver\\sys\\drivermain.cpp";
    local_20 = 0;
    uStack_2c = 0x91;
    local_24 = 0;
    iStack_30 = iVar3;
    Diagnostics::NtStatus_ResultErrorCallback((ErrorContext *)&local_38);
    puVar4 = auStack_d8;
  }
  else {
    local_38 = *(char **)(PTR_DAT_1c0007030 + -0x10);
    iStack_30 = *(int *)(PTR_DAT_1c0007030 + -8);
    uStack_2c = *(undefined4 *)(PTR_DAT_1c0007030 + -4);
    if (DAT_1c0007048 != 0) {
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(5);
      puVar4 = auStack_d0;
    }
    _DAT_1c0007050 = 0;
    uRam00000001c0007058 = 0;
    *(undefined8 *)(puVar4 + -8) = 0x1c000c173;
    iVar3 = EtwRegister(&local_38,_tlgEnableCallback,&DAT_1c0007028,&DAT_1c0007048);
    if (iVar3 == 0) {
      uVar1 = *(undefined2 *)PTR_DAT_1c0007030;
      *(undefined8 *)(puVar4 + -8) = 0x1c000c198;
      EtwSetInformation(DAT_1c0007048,2,PTR_DAT_1c0007030,uVar1);
    }
    *(undefined8 *)(puVar4 + -8) = 0x1c000c1a6;
    Diagnostics::Initialize(local_98);
    iVar3 = 0;
  }
  *(undefined8 *)(puVar4 + -8) = 0x1c000c1b4;
  return iVar3;
}


