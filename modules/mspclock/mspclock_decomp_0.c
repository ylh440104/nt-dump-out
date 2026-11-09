
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



===== KsiPropertyDefaultClockGetFunctionTable @ 1c0001020 =====

void KsiPropertyDefaultClockGetFunctionTable(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001c0001020. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  KsiPropertyDefaultClockGetFunctionTable();
  return;
}



===== KsiPropertyDefaultClockGetCorrelatedTime @ 1c0001040 =====

void KsiPropertyDefaultClockGetCorrelatedTime(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001c0001040. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  KsiPropertyDefaultClockGetCorrelatedTime();
  return;
}



===== KsiDefaultClockAddMarkEvent @ 1c0001060 =====

void KsiDefaultClockAddMarkEvent(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001c0001060. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  KsiDefaultClockAddMarkEvent();
  return;
}



===== KsiPropertyDefaultClockGetTime @ 1c0001080 =====

void KsiPropertyDefaultClockGetTime(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001c0001080. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  KsiPropertyDefaultClockGetTime();
  return;
}



===== KsiPropertyDefaultClockGetResolution @ 1c00010a0 =====

void KsiPropertyDefaultClockGetResolution(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001c00010a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  KsiPropertyDefaultClockGetResolution();
  return;
}



===== KsiPropertyDefaultClockGetPhysicalTime @ 1c00010c0 =====

void KsiPropertyDefaultClockGetPhysicalTime(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001c00010c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  KsiPropertyDefaultClockGetPhysicalTime();
  return;
}



===== KsiPropertyDefaultClockGetState @ 1c00010e0 =====

void KsiPropertyDefaultClockGetState(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001c00010e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  KsiPropertyDefaultClockGetState();
  return;
}



===== KsiPropertyDefaultClockGetCorrelatedPhysicalTime @ 1c0001100 =====

void KsiPropertyDefaultClockGetCorrelatedPhysicalTime(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001c0001100. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  KsiPropertyDefaultClockGetCorrelatedPhysicalTime();
  return;
}



===== _guard_check_icall @ 1c0001120 =====

void _guard_check_icall(void)

{
  return;
}



===== __security_check_cookie @ 1c0001140 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0001180 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0001180. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c00011b0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== ClockDispatchClose @ 1c0007010 =====

undefined8 ClockDispatchClose(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
  puVar2 = *(undefined8 **)(lVar1 + 0x18);
  KsFreeEventList(lVar1,puVar2[1] + 0x28,1,puVar2[1] + 0x38);
  KsFreeDefaultClock(puVar2[1]);
  KsFreeObjectHeader(*puVar2);
  ExFreePool(puVar2);
  KsDereferenceSoftwareBusObject(**(undefined8 **)(param_1 + 0x40));
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== ClockDispatchCreate @ 1c00070d0 =====

int ClockDispatchCreate(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  
  iVar1 = KsReferenceSoftwareBusObject(**(undefined8 **)(param_1 + 0x40));
  if (-1 < iVar1) {
    lVar2 = ExAllocatePoolWithTag(0x600,0x50,0x4946734b);
    if (lVar2 == 0) {
      iVar1 = -0x3fffff66;
    }
    else {
      iVar1 = KsAllocateDefaultClock(lVar2 + 8);
      if (-1 < iVar1) {
        KsAllocateObjectHeader(lVar2,0,0,param_2,&PTR_ClockDispatchIoControl_1c0002000);
        *(undefined8 *)(lVar2 + 0x20) = 0;
        *(undefined4 *)(lVar2 + 0x28) = 0;
        *(undefined4 *)(lVar2 + 0x18) = 1;
        KeInitializeEvent(lVar2 + 0x30,1,0);
        iVar1 = 0;
        *(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x18) = lVar2;
        goto LAB_1c00071c1;
      }
      ExFreePool(lVar2);
    }
    KsDereferenceSoftwareBusObject(**(undefined8 **)(param_1 + 0x40));
  }
LAB_1c00071c1:
  *(int *)(param_2 + 0x30) = iVar1;
  IofCompleteRequest(param_2,0);
  return iVar1;
}



===== ClockDispatchIoControl @ 1c0007200 =====

undefined4 ClockDispatchIoControl(undefined8 param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x18);
  if (iVar1 == 0x2f0003) {
    uVar3 = KsPropertyHandler(param_2,1,&PTR_KSPROPSETID_Clock_1c00022e8);
  }
  else if (iVar1 == 0x2f0007) {
    uVar3 = KsEnableEvent(param_2,1,&PTR_KSEVENTSETID_Clock_1c00022d0,0,0,0);
  }
  else if (iVar1 == 0x2f000b) {
    lVar2 = *(longlong *)
             (*(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x18) + 8);
    uVar3 = KsDisableEvent(param_2,lVar2 + 0x28,1,lVar2 + 0x38);
  }
  else {
    uVar3 = 0xc0000010;
  }
  *(undefined4 *)(param_2 + 0x30) = uVar3;
  IofCompleteRequest(param_2,0);
  return uVar3;
}



===== PnpAddDevice @ 1c00072d0 =====

ulonglong PnpAddDevice(undefined8 param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  uint uVar3;
  ulonglong uVar4;
  longlong lVar5;
  longlong local_res18 [2];
  
  local_res18[0] = 0;
  uVar4 = IoCreateDevice(param_1,8,0,0x2f,0,0,local_res18);
  if (-1 < (int)uVar4) {
    puVar1 = *(undefined8 **)(local_res18[0] + 0x40);
    uVar3 = KsAllocateDeviceHeader(puVar1,1,&PTR_ClockDispatchCreate_1c0002050);
    uVar4 = (ulonglong)uVar3;
    if (-1 < (int)uVar3) {
      lVar5 = IoAttachDeviceToDeviceStack(local_res18[0],param_2);
      uVar2 = *puVar1;
      if (lVar5 != 0) {
        KsSetDevicePnpAndBaseObject(uVar2,lVar5,local_res18[0]);
        *(uint *)(local_res18[0] + 0x30) = *(uint *)(local_res18[0] + 0x30) | 0x2000;
        *(uint *)(local_res18[0] + 0x30) = *(uint *)(local_res18[0] + 0x30) & 0xffffff7f;
        return 0;
      }
      KsFreeDeviceHeader(uVar2);
    }
    *(uint *)(local_res18[0] + 0x30) = *(uint *)(local_res18[0] + 0x30) & 0xffffff7f;
    IoDeleteDevice(local_res18[0]);
  }
  return uVar4;
}



===== PropertyClockSetState @ 1c00073d0 =====

undefined8 PropertyClockSetState(longlong param_1,undefined8 param_2,undefined4 *param_3)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x30) + 0x18);
  KeEnterCriticalRegion();
  ExAcquireFastMutexUnsafe(lVar1 + 0x18);
  KsSetDefaultClockState(*(undefined8 *)(lVar1 + 8),*param_3);
  ExReleaseFastMutexUnsafe(lVar1 + 0x18);
  KeLeaveCriticalRegion();
  return 0;
}



===== PropertyClockSetTime @ 1c0007460 =====

undefined8 PropertyClockSetTime(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x30) + 0x18);
  KeEnterCriticalRegion();
  ExAcquireFastMutexUnsafe(lVar1 + 0x18);
  KsSetDefaultClockTime(*(undefined8 *)(lVar1 + 8),*param_3);
  ExReleaseFastMutexUnsafe(lVar1 + 0x18);
  KeLeaveCriticalRegion();
  return 0;
}



===== entry @ 1c0008010 =====

void entry(longlong param_1)

{
  __security_init_cookie();
  DriverEntry(param_1);
  return;
}



===== __security_init_cookie @ 1c0008044 =====

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



===== DriverEntry @ 1c0008078 =====

undefined8 DriverEntry(longlong param_1)

{
  *(code **)(param_1 + 0x148) = KsDefaultDispatchPnp_exref;
  *(code **)(param_1 + 0x120) = KsDefaultDispatchPower_exref;
  *(code **)(param_1 + 0x128) = KsDefaultForwardIrp_exref;
  *(code **)(*(longlong *)(param_1 + 0x30) + 8) = PnpAddDevice;
  *(code **)(param_1 + 0x68) = KsNullDriverUnload_exref;
  KsSetMajorFunctionHandler(param_1,0);
  KsSetMajorFunctionHandler(param_1,2);
  KsSetMajorFunctionHandler(param_1,0xe);
  return 0;
}


