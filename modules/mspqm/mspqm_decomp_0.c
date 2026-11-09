
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



===== _guard_check_icall @ 1c0001030 =====

void _guard_check_icall(void)

{
  return;
}



===== __security_check_cookie @ 1c0001050 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0001090 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0001090. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c00010c0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== PnpAddDevice @ 1c0007010 =====

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
    uVar3 = KsAllocateDeviceHeader(puVar1,1,&PTR_QualityDispatchCreate_1c0002090);
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



===== PropertyGetReport @ 1c0007110 =====

undefined8 PropertyGetReport(longlong param_1,longlong param_2,undefined4 *param_3)

{
  int *piVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  longlong lVar9;
  longlong *plVar10;
  undefined1 *puVar11;
  ulonglong uVar12;
  longlong lVar13;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [40];
  
  uVar8 = (uint)(*(int *)(param_2 + 0x10) != 0);
  uVar12 = (ulonglong)uVar8;
  lVar2 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x30) + 0x18);
  KeEnterCriticalRegion();
  lVar13 = (uVar12 + 1) * 0x38 + lVar2;
  ExAcquireFastMutexUnsafe(lVar13);
  puVar11 = auStack_48;
  lVar9 = uVar12 * 0x10;
  plVar10 = (longlong *)(lVar2 + 0xa8 + lVar9);
  plVar3 = (longlong *)*plVar10;
  if (plVar3 != plVar10) {
    if (((longlong *)plVar3[1] == plVar10) &&
       (lVar9 = *plVar3, (longlong *)*(longlong *)(lVar9 + 8) == plVar3)) {
      *plVar10 = lVar9;
      *(longlong **)(lVar9 + 8) = plVar10;
      piVar1 = (int *)(lVar2 + 200 + uVar12 * 4);
      *piVar1 = *piVar1 + -1;
      ExReleaseFastMutexUnsafe(lVar13);
      KeLeaveCriticalRegion();
      if (uVar8 == 0) {
        uVar5 = *(undefined4 *)((longlong)plVar3 + 0x14);
        uVar6 = *(undefined4 *)(plVar3 + 3);
        uVar7 = *(undefined4 *)((longlong)plVar3 + 0x1c);
        *param_3 = *(undefined4 *)(plVar3 + 2);
        param_3[1] = uVar5;
        param_3[2] = uVar6;
        param_3[3] = uVar7;
        *(longlong *)(param_3 + 4) = plVar3[4];
        ExFreePool(plVar3);
        *(undefined8 *)(param_1 + 0x38) = 0x18;
      }
      else if (uVar8 == 1) {
        uVar5 = *(undefined4 *)((longlong)plVar3 + 0x14);
        uVar6 = *(undefined4 *)(plVar3 + 3);
        uVar7 = *(undefined4 *)((longlong)plVar3 + 0x1c);
        *param_3 = *(undefined4 *)(plVar3 + 2);
        param_3[1] = uVar5;
        param_3[2] = uVar6;
        param_3[3] = uVar7;
        ExFreePool(plVar3);
        *(undefined8 *)(param_1 + 0x38) = 0x10;
      }
      return 0;
    }
    pcVar4 = (code *)swi(0x29);
    lVar9 = (*pcVar4)(3);
    puVar11 = auStack_40;
  }
  *(undefined8 *)(puVar11 + 0x20) = 0;
  *(undefined8 *)(puVar11 + -8) = 0x1c000724b;
  KsAddIrpToCancelableQueue(lVar2 + 0x18 + lVar9,lVar2 + (uVar12 + 1) * 8,param_1,0);
  *(undefined8 *)(puVar11 + -8) = 0x1c000725a;
  ExReleaseFastMutexUnsafe(lVar13);
  *(undefined8 *)(puVar11 + -8) = 0x1c0007266;
  KeLeaveCriticalRegion();
  return 0x103;
}



===== PropertyGetReportComplete @ 1c0007290 =====

undefined8 PropertyGetReportComplete(undefined4 param_1,longlong param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  longlong in_RCX;
  
  if (*(int *)(param_2 + 0x10) == 0) {
    puVar1 = *(undefined4 **)(in_RCX + 0x90);
    param_1 = *puVar1;
    uVar2 = puVar1[1];
    uVar3 = puVar1[2];
    uVar4 = puVar1[3];
    *param_3 = param_1;
    param_3[1] = uVar2;
    param_3[2] = uVar3;
    param_3[3] = uVar4;
    *(undefined8 *)(param_3 + 4) = *(undefined8 *)(puVar1 + 4);
    *(undefined8 *)(in_RCX + 0x38) = 0x18;
  }
  else if (*(int *)(param_2 + 0x10) == 1) {
    puVar1 = *(undefined4 **)(in_RCX + 0x90);
    param_1 = *puVar1;
    uVar2 = puVar1[1];
    uVar3 = puVar1[2];
    uVar4 = puVar1[3];
    *param_3 = param_1;
    param_3[1] = uVar2;
    param_3[2] = uVar3;
    param_3[3] = uVar4;
    *(undefined8 *)(in_RCX + 0x38) = 0x10;
  }
  *(undefined4 *)(in_RCX + 0x30) = 0;
  IofCompleteRequest(param_1,0);
  return 0;
}



===== PropertySetReport @ 1c0007300 =====

undefined8 PropertySetReport(longlong param_1,longlong param_2,undefined4 *param_3)

{
  int *piVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  longlong lVar8;
  undefined8 uVar9;
  longlong *plVar10;
  longlong lVar11;
  ulonglong uVar12;
  longlong lVar13;
  
  uVar7 = (uint)(*(int *)(param_2 + 0x10) != 0);
  uVar12 = (ulonglong)uVar7;
  lVar11 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x30) + 0x18);
  KeEnterCriticalRegion();
  lVar13 = (uVar12 + 1) * 0x38 + lVar11;
  ExAcquireFastMutexUnsafe(lVar13);
  lVar8 = KsRemoveIrpFromCancelableQueue(lVar11 + 0x18 + uVar12 * 0x10,lVar11 + (uVar12 + 1) * 8,1);
  ExReleaseFastMutexUnsafe(lVar13);
  KeLeaveCriticalRegion();
  if (lVar8 != 0) {
    *(undefined4 **)(lVar8 + 0x90) = param_3;
    uVar9 = KsDispatchSpecificProperty(lVar8,PropertyGetReportComplete);
    return uVar9;
  }
  KeEnterCriticalRegion();
  ExAcquireFastMutexUnsafe(lVar13);
  lVar8 = lVar11 + uVar12 * 4;
  if (*(int *)(lVar8 + 200) == 0x100) {
    ExReleaseFastMutexUnsafe(lVar13);
    KeLeaveCriticalRegion();
    return 0xc000009a;
  }
  if (uVar7 == 0) {
    plVar10 = (longlong *)ExAllocatePoolWithTag(0x401,0x28,0x7271534b);
    if (plVar10 == (longlong *)0x0) {
      return 0xc000009a;
    }
    uVar4 = param_3[1];
    uVar5 = param_3[2];
    uVar6 = param_3[3];
    lVar11 = lVar11 + 0xa8;
    *(undefined4 *)(plVar10 + 2) = *param_3;
    *(undefined4 *)((longlong)plVar10 + 0x14) = uVar4;
    *(undefined4 *)(plVar10 + 3) = uVar5;
    *(undefined4 *)((longlong)plVar10 + 0x1c) = uVar6;
    plVar10[4] = *(longlong *)(param_3 + 4);
  }
  else {
    if (uVar7 != 1) goto LAB_1c000746e;
    plVar10 = (longlong *)ExAllocatePoolWithTag(0x401,0x20,0x7265534b);
    if (plVar10 == (longlong *)0x0) {
      return 0xc000009a;
    }
    uVar4 = param_3[1];
    uVar5 = param_3[2];
    uVar6 = param_3[3];
    lVar11 = lVar11 + 0xb8;
    *(undefined4 *)(plVar10 + 2) = *param_3;
    *(undefined4 *)((longlong)plVar10 + 0x14) = uVar4;
    *(undefined4 *)(plVar10 + 3) = uVar5;
    *(undefined4 *)((longlong)plVar10 + 0x1c) = uVar6;
  }
  plVar2 = *(longlong **)(lVar11 + 8);
  if (*plVar2 != lVar11) {
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(3);
    pcVar3 = (code *)swi(3);
    uVar9 = (*pcVar3)();
    return uVar9;
  }
  *plVar10 = lVar11;
  plVar10[1] = (longlong)plVar2;
  *plVar2 = (longlong)plVar10;
  *(longlong **)(lVar11 + 8) = plVar10;
LAB_1c000746e:
  piVar1 = (int *)(lVar8 + 200);
  *piVar1 = *piVar1 + 1;
  ExReleaseFastMutexUnsafe(lVar13);
  KeLeaveCriticalRegion();
  return 0;
}



===== QualityDispatchClose @ 1c0007500 =====

undefined8 QualityDispatchClose(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  longlong *plVar2;
  longlong lVar3;
  code *pcVar4;
  undefined8 uVar5;
  longlong *plVar6;
  int iVar7;
  ulonglong uVar8;
  
  uVar8 = 0;
  puVar1 = *(undefined8 **)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x18);
  plVar6 = puVar1 + 0x15;
  do {
    iVar7 = (int)uVar8;
    KsCancelIo(puVar1 + uVar8 * 2 + 3,puVar1 + uVar8 + 1);
    while (plVar2 = (longlong *)*plVar6, plVar2 != plVar6) {
      if (((longlong *)plVar2[1] != plVar6) ||
         (lVar3 = *plVar2, (longlong *)*(longlong *)(lVar3 + 8) != plVar2)) {
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3);
        pcVar4 = (code *)swi(3);
        uVar5 = (*pcVar4)();
        return uVar5;
      }
      *plVar6 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar6;
      if ((iVar7 == 0) || (iVar7 == 1)) {
        ExFreePool();
      }
    }
    uVar8 = (ulonglong)(iVar7 + 1U);
    plVar6 = plVar6 + 2;
    if (1 < iVar7 + 1U) {
      KsFreeObjectHeader(*puVar1);
      ExFreePool(puVar1);
      KsDereferenceSoftwareBusObject(**(undefined8 **)(param_1 + 0x40));
      *(undefined4 *)(param_2 + 0x30) = 0;
      IofCompleteRequest(param_2,0);
      return 0;
    }
  } while( true );
}



===== QualityDispatchCreate @ 1c0007620 =====

int QualityDispatchCreate(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  iVar2 = KsReferenceSoftwareBusObject(**(undefined8 **)(param_1 + 0x40));
  if (-1 < iVar2) {
    lVar3 = ExAllocatePoolWithTag(0x600,0xd0,0x4946734b);
    if (lVar3 == 0) {
      iVar2 = -0x3fffff66;
    }
    else {
      iVar2 = KsAllocateObjectHeader(lVar3,0,0,param_2,&PTR_QualityDispatchIoControl_1c00020c0);
      if (-1 < iVar2) {
        puVar8 = (undefined4 *)(lVar3 + 200);
        lVar6 = 2;
        lVar5 = lVar3 + 0x18;
        puVar7 = (undefined4 *)(lVar3 + 0x48);
        lVar4 = lVar3;
        do {
          lVar4 = lVar4 + 8;
          KeInitializeSpinLock(lVar4);
          *(longlong *)(lVar5 + 8) = lVar5;
          *(longlong *)lVar5 = lVar5;
          *(undefined8 *)(puVar7 + -2) = 0;
          *puVar7 = 0;
          puVar7[-4] = 1;
          KeInitializeEvent(puVar7 + 2,1);
          lVar1 = lVar5 + 0x90;
          *(longlong *)(lVar5 + 0x98) = lVar1;
          puVar7 = puVar7 + 0xe;
          *(longlong *)lVar1 = lVar1;
          lVar5 = lVar5 + 0x10;
          *puVar8 = 0;
          puVar8 = puVar8 + 1;
          lVar6 = lVar6 + -1;
        } while (lVar6 != 0);
        iVar2 = 0;
        *(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x18) = lVar3;
        goto LAB_1c0007773;
      }
      ExFreePool(lVar3);
    }
    KsDereferenceSoftwareBusObject(**(undefined8 **)(param_1 + 0x40));
  }
LAB_1c0007773:
  *(int *)(param_2 + 0x30) = iVar2;
  IofCompleteRequest(param_2,0);
  return iVar2;
}



===== QualityDispatchIoControl @ 1c00077b0 =====

int QualityDispatchIoControl(undefined8 param_1,longlong param_2)

{
  int iVar1;
  
  if (*(int *)(*(longlong *)(param_2 + 0xb8) + 0x18) == 0x2f0003) {
    iVar1 = KsPropertyHandler(param_2,1,&QualityPropertySets);
    if (iVar1 == 0x103) {
      return 0x103;
    }
  }
  else {
    iVar1 = -0x3ffffff0;
  }
  *(int *)(param_2 + 0x30) = iVar1;
  IofCompleteRequest(param_2,0);
  return iVar1;
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


