
===== WinHvGetSintEventFlags @ 1c0001010 =====

longlong WinHvGetSintEventFlags(uint param_1)

{
  longlong lVar1;
  
                    /* 0x1010  12  WinHvGetSintEventFlags */
  if ((WinHvpConnected == '\0') ||
     (lVar1 = *(longlong *)
               ((ulonglong)SystemReserved1[0x12]._4_4_ * 0x58 + 0x10 + WinHvpVpDataPages),
     lVar1 == 0)) {
    return 0;
  }
  return (ulonglong)param_1 * 0x100 + lVar1;
}



===== __report_gsfailure @ 1c0001060 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 1c000106d =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001c000106d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== WinHvModifySparseGpaPageHostVisibility @ 1c0001080 =====

void WinHvModifySparseGpaPageHostVisibility
               (undefined8 param_1,uint param_2,ulonglong param_3,void *param_4,longlong *param_5)

{
  void *in_stack_ffffffffffffff88;
  undefined8 in_stack_ffffffffffffff90;
  undefined8 in_stack_ffffffffffffffc8;
  undefined8 in_stack_ffffffffffffffd0;
  undefined8 local_18;
  ulonglong local_10;
  
                    /* 0x1080  17  WinHvModifySparseGpaPageHostVisibility */
  local_10 = (ulonglong)(param_2 & 3);
  local_18 = param_1;
  WinHvpSpecialListRepHypercall
            (0xdb,param_3,(undefined4 *)&local_18,(uint)param_4,in_stack_ffffffffffffff88,
             in_stack_ffffffffffffff90,param_4,8,(undefined *)0x0,(undefined *)0x0,(void *)0x0,0,
             in_stack_ffffffffffffffc8,in_stack_ffffffffffffffd0,param_5);
  return;
}



===== wil_details_FeatureDescriptors_SkipPadding @ 1c00010f0 =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_1c0006a07 < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_RecordCachedUsage @ 1c0001118 =====

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



===== wil_details_RecordFeatureUsageReporting @ 1c0001270 =====

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



===== WinHvpCheckPartitionPrivileges @ 1c00012f4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001c0001319) */

undefined8 WinHvpCheckPartitionPrivileges(void)

{
  uint *puVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  bool bVar4;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  if (WinHvpNested == '\0') {
    local_28 = 0;
    uStack_20 = 0;
    uVar3 = HviGetHypervisorFeatures(&local_28);
    uVar2 = CONCAT71((int7)((ulonglong)uVar3 >> 8),(undefined1)local_28) & 0xffffffffffffff7e;
    bVar4 = (char)uVar2 == '~';
  }
  else {
    puVar1 = (uint *)cpuid(0x40000009);
    uVar2 = (ulonglong)*puVar1 & 0xffffffffffffff74;
    bVar4 = (char)uVar2 == 't';
  }
  return CONCAT71((int7)(uVar2 >> 8),bVar4);
}



===== WinHvpSetHypervisorInformation @ 1c0001358 =====

void WinHvpSetHypervisorInformation(void)

{
  ZwSetSystemInformation(0x5b,0,0);
  return;
}



===== WinHvpAllocateHypercallBuffer @ 1c0001380 =====

longlong WinHvpAllocateHypercallBuffer(void)

{
  longlong *plVar1;
  byte bVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 uVar5;
  
  bVar2 = KeGetCurrentIrql();
  if ((bVar2 < 3) && (lVar3 = ExAllocatePool2(0x40,0x30,0x42764857), lVar3 != 0)) {
    lVar4 = ExAllocatePool2(0x42,0x1000,0x4a764857);
    *(longlong *)(lVar3 + 0x10) = lVar4;
    plVar1 = (longlong *)(lVar3 + 0x20);
    if (lVar4 != 0) {
      lVar4 = ExAllocatePool2(0x42,0x1000,0x4b764857);
      *plVar1 = lVar4;
      if (lVar4 != 0) {
        uVar5 = MmGetPhysicalAddress(*(undefined8 *)(lVar3 + 0x10));
        *(undefined8 *)(lVar3 + 0x18) = uVar5;
        uVar5 = MmGetPhysicalAddress(*plVar1);
        *(undefined8 *)(lVar3 + 0x28) = uVar5;
        return lVar3;
      }
    }
    if (*(longlong *)(lVar3 + 0x10) != 0) {
      ExFreePoolWithTag(*(longlong *)(lVar3 + 0x10),0x4a764857);
    }
    if (*plVar1 != 0) {
      ExFreePoolWithTag(*plVar1,0x4b764857);
    }
    ExFreePoolWithTag(lVar3,0x42764857);
  }
  return 0;
}



===== WinHvpFreeHypercallBuffer @ 1c00014a0 =====

void WinHvpFreeHypercallBuffer(longlong param_1)

{
  ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x20),0x4b764857);
  ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x10),0x4a764857);
  ExFreePoolWithTag(param_1,0x42764857);
  return;
}



===== WinHvpHypercall @ 1c00014f4 =====

void WinHvpHypercall(void)

{
  WinHvpHypercallRoutine();
  return;
}



===== WinHvpHypercallRoutine @ 1c0001548 =====

uint WinHvpHypercallRoutine(void)

{
  undefined8 uVar1;
  uint uVar2;
  uint *in_R9;
  
  uVar2 = 0;
  if (WinHvpConnected == '\0') {
    uVar2 = 0xc0351000;
  }
  else {
    uVar1 = HvlInvokeHypercall();
    if (in_R9 != (uint *)0x0) {
      *in_R9 = (uint)((ulonglong)uVar1 >> 0x20) & 0xfff;
    }
    if ((short)uVar1 != 0) {
      uVar2 = (uint)uVar1 & 0xffff | 0xc0350000;
    }
  }
  return uVar2;
}



===== WinHvpReleaseFallbackBuffers @ 1c00015b0 =====

void WinHvpReleaseFallbackBuffers(longlong param_1)

{
  if (*(undefined **)(param_1 + 0x28) == &WinHvpFallbackBuffer2) {
    ExReleaseFastMutex(&WinHvpFallbackMutex);
  }
  else if (*(undefined **)(param_1 + 0x28) == &WinHvpFallbackBuffer) {
    KeReleaseSpinLock(&WinHvpFallbackSpinLock,CONCAT71(0x1c000d0,*(undefined1 *)(param_1 + 0x30)));
  }
  return;
}



===== WinHvpReleasePoolBuffers @ 1c0001610 =====

void WinHvpReleasePoolBuffers(longlong param_1)

{
  ExFreeToNPagedLookasideList
            ((ulonglong)*(ushort *)(param_1 + 0x20) * 0x80 + WinHvpNodeToHypercallLookaside,
             *(undefined8 *)(param_1 + 0x28));
  return;
}



===== WinHvpSetupHypercall @ 1c0001640 =====

void WinHvpSetupHypercall(undefined8 *param_1,undefined8 *param_2,longlong param_3)

{
  ushort uVar1;
  byte bVar2;
  undefined1 uVar3;
  undefined *puVar4;
  longlong lVar5;
  undefined8 uVar6;
  
  uVar1 = *(ushort *)(WinHvpProcessorToNode + (ulonglong)SystemReserved1[0x12]._4_4_ * 2);
  *(undefined8 *)(param_3 + 0x28) = 0;
  lVar5 = (ulonglong)uVar1 * 0x80 + WinHvpNodeToHypercallLookaside;
  *(ushort *)(param_3 + 0x20) = uVar1;
  puVar4 = (undefined *)ExAllocateFromNPagedLookasideList(lVar5);
  *(undefined **)(param_3 + 0x28) = puVar4;
  *(code **)(param_3 + 0x38) = WinHvpReleasePoolBuffers;
  if (puVar4 == (undefined *)0x0) {
    bVar2 = KeGetCurrentIrql();
    *(byte *)(param_3 + 0x30) = bVar2;
    if (bVar2 < 2) {
      ExAcquireFastMutex(&WinHvpFallbackMutex);
      puVar4 = &WinHvpFallbackBuffer2;
    }
    else {
      uVar3 = KeAcquireSpinLockRaiseToDpc(&WinHvpFallbackSpinLock);
      *(undefined1 *)(param_3 + 0x30) = uVar3;
      puVar4 = &WinHvpFallbackBuffer;
    }
    *(undefined **)(param_3 + 0x28) = puVar4;
    *(code **)(param_3 + 0x38) = WinHvpReleaseFallbackBuffers;
  }
  if (param_1 == (undefined8 *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = *(undefined8 *)(puVar4 + 0x10);
    *param_1 = uVar6;
  }
  *(undefined8 *)(param_3 + 8) = uVar6;
  if (param_2 == (undefined8 *)0x0) {
    *(undefined8 *)(param_3 + 0x10) = 0;
  }
  else {
    uVar6 = *(undefined8 *)(puVar4 + 0x20);
    *(undefined8 *)(param_3 + 0x10) = uVar6;
    *param_2 = uVar6;
  }
  *(longlong *)param_3 = param_3;
  return;
}



===== WinHvpSimplePoolHypercall_CallViaMacro @ 1c0001748 =====

void WinHvpSimplePoolHypercall_CallViaMacro(longlong param_1,uint param_2)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (*(char *)(param_1 + 0x18) == '\0') {
    if (*(char *)(param_1 + 0x19) == '\0') {
      WinHvpHypercall();
    }
    else {
      if (*(longlong *)(param_1 + 0x10) != 0) {
        uVar1 = *(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x28);
      }
      WinHvpIsolatedHypercall(param_2,*(void **)(param_1 + 8),*(uint *)(param_1 + 0x1c),uVar1);
    }
  }
  else {
    WinHvpSlowHypercallRemote();
  }
  return;
}



===== WinHvpSpecialListRepHypercall @ 1c00017c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int WinHvpSpecialListRepHypercall
              (undefined8 param_1,ulonglong param_2,undefined4 *param_3,uint param_4,void *param_5,
              undefined8 param_6,void *param_7,uint param_8,undefined *param_9,undefined *param_10,
              void *param_11,uint param_12,undefined8 param_13,undefined8 param_14,
              longlong *param_15)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  uint uVar10;
  longlong lVar11;
  int iVar12;
  ulonglong uVar13;
  uint uVar14;
  undefined4 *puVar15;
  undefined4 *local_res10;
  undefined4 *local_res18;
  uint local_res20;
  longlong local_88 [7];
  code *local_50;
  
  local_res18 = param_3;
  local_res20 = param_4;
  memset(local_88,0,0x40);
  uVar5 = param_12;
  uVar4 = param_8;
  *param_15 = 0;
  if (param_2 == 0) {
    return (WinHvpConnected != '\0') + 0xc0350002;
  }
  uVar14 = 0xfff;
  if (param_8 == 0) {
    uVar10 = 0xfff;
  }
  else {
    uVar10 = (uint)(0xff0 / (ulonglong)param_8);
  }
  if (param_12 == 0) {
    uVar6 = 0xfff;
  }
  else {
    uVar6 = (uint)(0x1000 / (ulonglong)param_12);
  }
  if (uVar10 < uVar6) {
    if (param_8 != 0) {
      uVar14 = (uint)(0xff0 / (ulonglong)param_8);
    }
  }
  else if (param_12 != 0) {
    uVar14 = (uint)(0x1000 / (ulonglong)param_12);
  }
  param_5 = (void *)0x0;
  local_res10 = (undefined4 *)0x0;
  KeGetCurrentIrql();
  lVar11 = local_88[0];
  puVar15 = (undefined4 *)0x0;
  while( true ) {
    if (lVar11 == 0) {
      WinHvpSetupHypercall(&local_res10,&param_5,(longlong)local_88);
      puVar15 = local_res10;
    }
    uVar13 = 0;
    local_res20 = 0;
    uVar8 = 0xffffffff;
    if (param_2 < 0xffffffff) {
      uVar8 = param_2;
    }
    if (uVar14 < (uint)uVar8) {
      uVar10 = uVar14;
    }
    else {
      uVar10 = 0xffffffff;
      if (param_2 < 0xffffffff) {
        uVar10 = (uint)param_2;
      }
    }
    uVar1 = local_res18[1];
    uVar2 = local_res18[2];
    uVar3 = local_res18[3];
    *puVar15 = *local_res18;
    puVar15[1] = uVar1;
    puVar15[2] = uVar2;
    puVar15[3] = uVar3;
    if (uVar4 != 0) {
      if (param_9 == (undefined *)0x0) {
        memcpy(puVar15 + 4,param_7,(ulonglong)(uVar10 * uVar4));
      }
      else {
        (*(code *)param_9)();
      }
    }
    if (*(char *)(local_88[0] + 0x18) == '\0') {
      iVar7 = WinHvpHypercall();
      uVar13 = (ulonglong)local_res20;
      lVar11 = local_88[0];
    }
    else {
      lVar11 = local_88[0];
      uVar9 = WinHvpSlowHypercallRemote();
      iVar7 = (int)uVar9;
    }
    iVar12 = (int)uVar13;
    *param_15 = *param_15 + uVar13;
    if (param_2 < uVar13) {
      iVar7 = -0x7ffffffb;
    }
    if ((uVar5 != 0) && (iVar12 != 0)) {
      memcpy(param_11,param_5,(ulonglong)(iVar12 * uVar5));
      lVar11 = local_88[0];
    }
    if (local_50 == WinHvpReleaseFallbackBuffers) {
      WinHvpReleaseFallbackBuffers(lVar11);
      lVar11 = 0;
      local_88[0] = 0;
    }
    param_2 = param_2 - uVar13;
    if ((iVar7 != 0) || (param_2 == 0)) break;
    puVar15 = local_res10;
    if (iVar12 != 0) {
      if (uVar4 != 0) {
        if (param_10 == (undefined *)0x0) {
          param_7 = (void *)((longlong)param_7 + (ulonglong)(iVar12 * uVar4));
        }
        else {
          param_7 = (void *)(*(code *)param_10)(param_7,uVar13);
          lVar11 = local_88[0];
        }
      }
      puVar15 = local_res10;
      if ((uVar5 != 0) && (param_11 != (void *)0x0)) {
        param_11 = (void *)((longlong)param_11 + (ulonglong)(iVar12 * uVar5));
      }
    }
  }
  if (lVar11 != 0) {
    (*local_50)();
  }
  return iVar7;
}



===== WinHvpVariableHeaderHypercall @ 1c0001a84 =====

void WinHvpVariableHeaderHypercall(void)

{
  WinHvpHypercallRoutine();
  return;
}



===== WinHvpCleanupIsolation @ 1c0001ac8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WinHvpCleanupIsolation(void)

{
  uint uVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  uint uVar4;
  longlong lVar5;
  undefined1 auStack_58 [32];
  undefined4 local_38;
  longlong local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  local_30 = 0;
  uStack_28 = 0;
  local_20 = 0;
  uStack_18 = 0;
  if (DAT_1c000d062 == '\0') {
    if (DAT_1c000d061 != '\0') {
      plVar2 = &DAT_1c000d068;
      lVar5 = 5;
      do {
        if (*plVar2 != 0) {
          WinHvFreeHostVisiblePages(*plVar2);
          *plVar2 = 0;
        }
        plVar2 = plVar2 + 1;
        lVar5 = lVar5 + -1;
      } while (lVar5 != 0);
    }
  }
  else {
    uVar1 = KeQueryActiveProcessorCountEx(0xffff);
    uVar4 = 0;
    puVar3 = &local_20;
    if (uVar1 != 0) {
      do {
        local_38 = 0;
        local_30 = 0;
        uStack_28 = 0;
        KeGetProcessorNumberFromIndex(uVar4,&local_38);
        uStack_28 = CONCAT62(uStack_28._2_6_,(undefined2)local_38);
        local_30 = 1L << (local_38._2_1_ & 0x3f);
        KeSetSystemGroupAffinityThread(&local_30,puVar3);
        puVar3 = (undefined8 *)0x0;
        MmUnmapIoSpace(*(undefined8 *)
                        ((ulonglong)SystemReserved1[0x12]._4_4_ * 0x58 + 0x30 + WinHvpVpDataPages),
                       0x1000);
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar1);
    }
    KeRevertToUserGroupAffinityThread(&local_20);
  }
  return;
}



===== WinHvpEnableIsolation @ 1c0001c0c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001c0001c95) */
/* WARNING: Removing unreachable block (ram,0x0001c0001c72) */

uint WinHvpEnableIsolation(void)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  longlong lVar4;
  ulonglong *puVar5;
  uint uVar6;
  ulonglong uVar7;
  uint uVar8;
  undefined8 *puVar9;
  undefined1 auStack_98 [32];
  undefined4 local_78;
  undefined4 local_70;
  undefined4 local_68;
  ulonglong local_60;
  longlong local_58;
  ulonglong local_50;
  undefined8 uStack_48;
  longlong local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_98;
  local_58 = 0;
  local_60 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_50 = 0;
  uStack_48 = 0;
  uVar2 = HviIsHypervisorMicrosoftCompatible();
  if ((char)uVar2 != '\0') {
    puVar5 = (ulonglong *)cpuid(0x40000003);
    local_50 = *puVar5;
    if ((local_50 & 0x40000000000000) != 0) {
      lVar4 = cpuid(0x4000000c);
      uVar6 = *(uint *)(lVar4 + 4) & 0xf;
      if (uVar6 != 0) {
        DAT_1c000d060 = 1;
        if (uVar6 == 2) {
          DAT_1c000d061 = '\x01';
          DAT_1c000d062 = '\x01';
          goto LAB_1c0001cbe;
        }
        if (uVar6 == 3) {
          DAT_1c000d061 = '\x01';
        }
      }
    }
  }
  if (DAT_1c000d061 == '\0') {
    return 0;
  }
LAB_1c0001cbe:
  WinHvpSharedGpaBoundary = HviGetSharedGpaBoundary();
  bVar1 = false;
  uVar6 = KeQueryActiveProcessorCountEx(0xffff);
  if (DAT_1c000d062 == '\0') {
    InitializeSListHead((PSLIST_HEADER)&DAT_1c000d090);
    if (4 < uVar6) {
      uVar6 = 4;
    }
    for (uVar7 = 0; (uint)uVar7 <= uVar6; uVar7 = (ulonglong)((uint)uVar7 + 1)) {
      lVar4 = WinHvAllocateHostVisiblePages();
      (&DAT_1c000d068)[uVar7] = lVar4;
      if (lVar4 == 0) {
        return 0xc000009a;
      }
      local_70 = 0x40000020;
      local_78 = 0;
      lVar4 = MmMapLockedPagesSpecifyCache(lVar4,0,1,0);
      if (lVar4 == 0) {
        return 0xc000009a;
      }
      ExpInterlockedPushEntrySList(&DAT_1c000d090,lVar4);
    }
    DAT_1c000d0a8 = ExpInterlockedPopEntrySList(&DAT_1c000d090);
    KeInitializeSpinLock(&DAT_1c000d0a0);
  }
  else {
    puVar9 = &local_30;
    bVar1 = false;
    for (uVar8 = 0; uVar8 < uVar6; uVar8 = uVar8 + 1) {
      local_68 = 0;
      local_40 = 0;
      uStack_38 = 0;
      KeGetProcessorNumberFromIndex(uVar8,&local_68);
      uStack_38 = CONCAT62(uStack_38._2_6_,(undefined2)local_68);
      local_40 = 1L << (local_68._2_1_ & 0x3f);
      KeSetSystemGroupAffinityThread(&local_40,puVar9);
      puVar5 = &local_60;
      bVar1 = true;
      puVar9 = (undefined8 *)0x0;
      uVar3 = WinHvpGetVpRegister64Self(0x90019,puVar5);
      if (((int)uVar3 < 0) ||
         (uVar3 = WinHvpValidateAndMapOverlayAddress(local_60,puVar5,'\x01',&local_58),
         (int)uVar3 < 0)) goto LAB_1c0001ed3;
      *(longlong *)((ulonglong)SystemReserved1[0x12]._4_4_ * 0x58 + 0x30 + WinHvpVpDataPages) =
           local_58;
      *(undefined2 *)(local_58 + 0xffa) = 1;
      *(undefined4 *)(local_58 + 0xffc) = 0xffffffff;
    }
  }
  uVar3 = WinHvpSetIsolatedVpRegister64Self
                    (0x90002,(((ulonglong)(DAT_1c000d504 & 0xff) << 8 |
                               (ulonglong)(uint)DAT_1c000d508 & 0xff | 0x1040000) << 8 |
                             (ulonglong)(DAT_1c000d614 & 0xff)) << 0x10 |
                             (ulonglong)(DAT_1c000d508._4_4_ & 0xffff));
  if (bVar1) {
LAB_1c0001ed3:
    KeRevertToUserGroupAffinityThread(&local_30);
  }
  return uVar3;
}



===== WinHvpIsIsolated @ 1c0001f1c =====

undefined1 WinHvpIsIsolated(void)

{
  return DAT_1c000d060;
}



===== WinHvpIsolatedHypercall @ 1c0001f2c =====

uint WinHvpIsolatedHypercall(uint param_1,void *param_2,uint param_3,undefined8 param_4)

{
  ulonglong _Size;
  undefined1 uVar1;
  ushort uVar2;
  void *pvVar3;
  undefined4 in_register_0000000c;
  uint uVar4;
  bool bVar5;
  ulonglong local_38;
  undefined1 local_30 [24];
  
  uVar4 = 0;
  _Size = (ulonglong)param_3;
  if (WinHvpConnected == '\0') {
    return 0xc0351000;
  }
  local_38 = (ulonglong)(param_1 & 0xffff);
  if (DAT_1c000d062 == '\0') {
    if (param_3 < 0x11) {
      memcpy(local_30,param_2,_Size);
      if (param_3 < 0x10) {
        memset(local_30 + _Size,0,0x10 - _Size);
      }
      uVar2 = WinHvpIsolatedHypercallDirect();
      goto LAB_1c0002114;
    }
    uVar1 = KeGetCurrentIrql();
    pvVar3 = (void *)ExpInterlockedPopEntrySList(&DAT_1c000d090);
    bVar5 = pvVar3 == (void *)0x0;
    if (bVar5) {
      KfRaiseIrql(0xf);
      KeAcquireSpinLockAtDpcLevel(&DAT_1c000d0a0);
      pvVar3 = DAT_1c000d0a8;
    }
    memcpy(pvVar3,param_2,_Size);
    MmGetPhysicalAddress(pvVar3);
    uVar2 = WinHvpIsolatedHypercallDirect();
    if (!bVar5) {
      ExpInterlockedPushEntrySList(&DAT_1c000d090,pvVar3);
      goto LAB_1c0002114;
    }
    KeReleaseSpinLockFromDpcLevel(&DAT_1c000d0a0);
  }
  else {
    uVar1 = KfRaiseIrql(CONCAT71((int7)(CONCAT44(in_register_0000000c,param_1) >> 8),0xf));
    pvVar3 = *(void **)((ulonglong)SystemReserved1[0x12]._4_4_ * 0x58 + 0x30 + WinHvpVpDataPages);
    *(undefined4 *)((longlong)pvVar3 + 0xffc) = 1;
    *(undefined8 *)((longlong)pvVar3 + 0xfe8) = param_4;
    *(ulonglong *)((longlong)pvVar3 + 0xff0) = local_38;
    if (param_3 != 0) {
      memcpy(pvVar3,param_2,_Size);
    }
    _sev_vmgexit();
    uVar2 = (ushort)*(undefined8 *)((longlong)pvVar3 + 0xff0);
    *(undefined4 *)((longlong)pvVar3 + 0xffc) = 0xffffffff;
  }
  KeLowerIrql(uVar1);
LAB_1c0002114:
  if (uVar2 != 0) {
    uVar4 = uVar2 | 0xc0350000;
  }
  return uVar4;
}



===== WinHvpReadIsolatedMsr @ 1c000214c =====

undefined8 WinHvpReadIsolatedMsr(ulonglong param_1,ulonglong *param_2)

{
  longlong lVar1;
  code *pcVar2;
  undefined1 uVar3;
  ulonglong uVar4;
  undefined1 *puVar5;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  if (DAT_1c000d062 == '\0') {
    uVar4 = WinHvpReadIsolatedMsrDirect();
    *param_2 = uVar4;
  }
  else {
    uVar3 = KfRaiseIrql(0xf);
    lVar1 = *(longlong *)((ulonglong)SystemReserved1[0x12]._4_4_ * 0x58 + 0x30 + WinHvpVpDataPages);
    *(undefined4 *)(lVar1 + 0xffc) = 0;
    *(undefined8 *)(lVar1 + 0x398) = 0;
    *(undefined8 *)(lVar1 + 0x3f0) = 0;
    *(undefined8 *)(lVar1 + 0x3a0) = 0;
    *(undefined8 *)(lVar1 + 0x3f8) = 0x1c000200000000;
    *(ulonglong *)(lVar1 + 0x308) = param_1 & 0xffffffff;
    *(undefined8 *)(lVar1 + 0x390) = 0x7c;
    _sev_vmgexit();
    puVar5 = auStack_28;
    if (*(longlong *)(lVar1 + 0x398) != 0) {
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(0x3a);
      puVar5 = auStack_20;
    }
    uVar4 = *(longlong *)(lVar1 + 0x310) << 0x20 | (ulonglong)*(uint *)(lVar1 + 0x1f8);
    *param_2 = uVar4;
    *(undefined4 *)(lVar1 + 0xffc) = 0xffffffff;
    *(undefined8 *)(puVar5 + -8) = 0x1c0002228;
    KeLowerIrql(CONCAT71((int7)(uVar4 >> 8),uVar3));
  }
  return 0;
}



===== WinHvpSetIsolatedVpRegister64Self @ 1c000224c =====

void WinHvpSetIsolatedVpRegister64Self(int param_1,ulonglong param_2)

{
  uint uVar1;
  undefined1 local_res18 [16];
  
  uVar1 = WinHvpGetMsrNameFromRegisterName(param_1,local_res18);
  WinHvpWriteIsolatedMsr((ulonglong)uVar1,param_2);
  return;
}



===== WinHvpWriteIsolatedMsr @ 1c0002274 =====

undefined8 WinHvpWriteIsolatedMsr(ulonglong param_1,ulonglong param_2)

{
  longlong lVar1;
  code *pcVar2;
  undefined1 uVar3;
  undefined1 *puVar4;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  if (DAT_1c000d062 == '\0') {
    WinHvpWriteIsolatedMsrDirect();
  }
  else {
    uVar3 = KfRaiseIrql(0xf);
    lVar1 = *(longlong *)((ulonglong)SystemReserved1[0x12]._4_4_ * 0x58 + 0x30 + WinHvpVpDataPages);
    *(undefined4 *)(lVar1 + 0xffc) = 0;
    *(undefined8 *)(lVar1 + 0x3a0) = 0;
    *(undefined8 *)(lVar1 + 0x398) = 1;
    *(undefined8 *)(lVar1 + 0x3f0) = 0x8000000000000000;
    *(undefined8 *)(lVar1 + 0x3f8) = 0x1c000600000000;
    *(ulonglong *)(lVar1 + 0x308) = param_1 & 0xffffffff;
    *(ulonglong *)(lVar1 + 0x1f8) = param_2 & 0xffffffff;
    *(ulonglong *)(lVar1 + 0x310) = param_2 >> 0x20;
    *(undefined8 *)(lVar1 + 0x390) = 0x7c;
    _sev_vmgexit();
    puVar4 = auStack_28;
    if (*(longlong *)(lVar1 + 0x398) != 0) {
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(0x3a);
      puVar4 = auStack_20;
    }
    *(undefined4 *)(lVar1 + 0xffc) = 0xffffffff;
    *(undefined8 *)(puVar4 + -8) = 0x1c0002356;
    KeLowerIrql(uVar3);
  }
  return 0;
}



===== WinHvAllocateOverlayPages @ 1c0002380 =====

void WinHvAllocateOverlayPages(int param_1)

{
                    /* 0x2380  4  WinHvAllocateOverlayPages */
  WinHvpAllocateOverlayPages(param_1,'\x01');
  return;
}



===== WinHvFreeOverlayPages @ 1c00023a0 =====

void WinHvFreeOverlayPages(undefined8 param_1)

{
                    /* 0x23a0  10  WinHvFreeOverlayPages */
  WinHvpFreeOverlayPages(param_1,DAT_1c000d061);
  return;
}



===== WinHvpAllocateHypervisorVisiblePages @ 1c00023bc =====

longlong WinHvpAllocateHypervisorVisiblePages
                   (int param_1,uint param_2,uint param_3,uint param_4,char param_5)

{
  bool bVar1;
  void *_Dst;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  
  if (WinHvpConnected != '\0') {
    if (((param_2 & 1) == 0) && (DAT_1c000d061 != '\0')) {
      param_2 = param_2 | 1;
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    uVar2 = param_1 << 0xc;
    lVar3 = 0;
    if (param_3 != 0) {
      lVar4 = 0;
      uVar5 = 0;
      do {
        if (param_4 <= uVar5) break;
        lVar4 = lVar4 + (ulonglong)param_3;
        lVar3 = MmAllocatePagesForMdlEx(0,lVar4 + -1,0,uVar2,1,param_2 | 4);
        uVar5 = uVar5 + 1;
      } while (lVar3 == 0);
    }
    if ((lVar3 != 0) ||
       (lVar3 = MmAllocatePagesForMdlEx(0,0xffffffffffffffff,0,(ulonglong)uVar2,1,param_2 | 4),
       lVar3 != 0)) {
      if (param_5 != '\0') {
        WinHvpModifyMdlHostVisibility(lVar3,'\x01');
      }
      _Dst = (void *)MmMapLockedPagesSpecifyCache(lVar3,0,1,0,0,0x40000020);
      if (_Dst == (void *)0x0) {
        if (lVar3 != 0) {
          WinHvpReclaimAndFreeHypervisorVisiblePages(lVar3,param_5);
          lVar3 = 0;
        }
      }
      else if (bVar1) {
        memset(_Dst,0,(ulonglong)uVar2);
      }
      return lVar3;
    }
  }
  return 0;
}



===== WinHvpAllocateOverlayPages @ 1c0002540 =====

undefined8 WinHvpAllocateOverlayPages(int param_1,char param_2)

{
  longlong lVar1;
  longlong lVar2;
  char cVar3;
  undefined8 local_18;
  longlong local_10;
  
  if ((param_2 == '\0') || (DAT_1c000d060 == '\0')) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  lVar1 = WinHvpAllocateHypervisorVisiblePages(param_1,0x20,0x40000000,4,cVar3);
  if (lVar1 != 0) {
    local_18 = *(undefined8 *)(lVar1 + 0x18);
    local_10 = lVar1;
    ExAcquireFastMutex(&WinHvpOverlayTableLock);
    lVar2 = RtlInsertElementGenericTable(&WinHvpOverlayTable,&local_18,0x10);
    ExReleaseFastMutex(&WinHvpOverlayTableLock);
    if (lVar2 != 0) {
      return *(undefined8 *)(lVar1 + 0x18);
    }
    WinHvpReclaimAndFreeHypervisorVisiblePages(lVar1,cVar3);
  }
  return 0;
}



===== WinHvpAllocateOverlayTableEntry @ 1c0002610 =====

void WinHvpAllocateOverlayTableEntry(undefined8 param_1,undefined4 param_2)

{
  ExAllocatePool2(0x40,param_2,0x55764857);
  return;
}



===== WinHvpCompareOverlayTableEntry @ 1c0002640 =====

int WinHvpCompareOverlayTableEntry(undefined8 param_1,ulonglong *param_2,ulonglong *param_3)

{
  if (*param_2 < *param_3) {
    return 0;
  }
  return 2 - (uint)(*param_3 < *param_2);
}



===== WinHvpFreeOverlayPages @ 1c000265c =====

void WinHvpFreeOverlayPages(undefined8 param_1,char param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 local_18;
  undefined8 local_10;
  
  local_10 = 0;
  local_18 = param_1;
  ExAcquireFastMutex(&WinHvpOverlayTableLock);
  lVar2 = RtlLookupElementGenericTable(&WinHvpOverlayTable,&local_18);
  lVar1 = *(longlong *)(lVar2 + 8);
  RtlDeleteElementGenericTable(&WinHvpOverlayTable,lVar2);
  ExReleaseFastMutex(&WinHvpOverlayTableLock);
  WinHvpReclaimAndFreeHypervisorVisiblePages(lVar1,param_2);
  return;
}



===== WinHvpFreeOverlayTableEntry @ 1c00026f0 =====

void WinHvpFreeOverlayTableEntry(undefined8 param_1,undefined8 param_2)

{
  ExFreePoolWithTag(param_2,0);
  return;
}



===== WinHvpModifyMdlHostVisibility @ 1c0002714 =====

void WinHvpModifyMdlHostVisibility(longlong param_1,char param_2)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong *puVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong local_res8;
  
  puVar3 = (ulonglong *)(param_1 + 0x30);
  local_res8 = 0;
  uVar4 = (ulonglong)*(uint *)(param_1 + 0x28) + 0xfff +
          (ulonglong)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x20) & 0xfff) >> 0xc;
  uVar5 = WinHvpSharedGpaBoundary >> 0xc;
  if (((uVar5 != 0) && (uVar5 <= *puVar3)) && ((int)uVar4 != 0)) {
    puVar1 = puVar3;
    uVar2 = uVar4;
    do {
      *puVar1 = *puVar1 - uVar5;
      puVar1 = puVar1 + 1;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  WinHvModifySparseGpaPageHostVisibility
            (0xffffffffffffffff,-(uint)(param_2 != '\0') & 3,uVar4,puVar3,&local_res8);
  if (((param_2 != '\0') && (uVar5 != 0)) && ((int)uVar4 != 0)) {
    do {
      *puVar3 = *puVar3 + uVar5;
      puVar3 = puVar3 + 1;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  return;
}



===== WinHvpReclaimAndFreeHypervisorVisiblePages @ 1c00027d8 =====

void WinHvpReclaimAndFreeHypervisorVisiblePages(longlong param_1,char param_2)

{
  if ((*(byte *)(param_1 + 10) & 1) != 0) {
    MmUnmapLockedPages(*(undefined8 *)(param_1 + 0x18));
  }
  if (param_2 != '\0') {
    WinHvpModifyMdlHostVisibility(param_1,'\0');
    *(ushort *)(param_1 + 10) = *(ushort *)(param_1 + 10) & 0xf7ff;
  }
  MmFreePagesFromMdl(param_1);
  ExFreePoolWithTag(param_1,0);
  return;
}



===== WinHvpValidateAndMapOverlayAddress @ 1c000284c =====

uint WinHvpValidateAndMapOverlayAddress
               (ulonglong param_1,undefined8 param_2,char param_3,longlong *param_4)

{
  longlong lVar1;
  
  if ((param_1 & 0xfff) == 0) {
    if (param_3 == '\0') {
      if ((WinHvpSharedGpaBoundary == 0) || (param_1 < WinHvpSharedGpaBoundary)) goto LAB_1c000288c;
    }
    else if (WinHvpSharedGpaBoundary <= param_1) {
LAB_1c000288c:
      lVar1 = MmMapIoSpaceEx((int)param_1,0x1000,4);
      *param_4 = lVar1;
      return ~-(uint)(lVar1 != 0) & 0xc000009a;
    }
  }
  *param_4 = 0;
  return 0xc0000001;
}



===== WinHvPostMessage @ 1c00028c0 =====

void WinHvPostMessage(undefined4 param_1,undefined4 param_2,void *param_3,ulonglong param_4)

{
                    /* 0x28c0  19  WinHvPostMessage */
  WinHvPostMessage2(param_1,param_2,0,param_3,param_4);
  return;
}



===== WinHvPostMessage2 @ 1c00028e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
WinHvPostMessage2(undefined4 param_1,undefined4 param_2,uint param_3,void *param_4,ulonglong param_5
                 )

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *local_68 [2];
  longlong local_58 [3];
  undefined1 local_3f;
  undefined4 local_3c;
  code *local_20;
  
                    /* 0x28e0  20  WinHvPostMessage2 */
  local_68[0] = (undefined4 *)0x0;
  memset(local_58,0,0x40);
  if (((param_3 & 0xfffffffe) == 0) &&
     (((DAT_1c000d061 != '\0' || ((param_3 & 1) == 0)) && (param_5 < 0xf1)))) {
    WinHvpSetupHypercall(local_68,(undefined8 *)0x0,(longlong)local_58);
    puVar1 = local_68[0];
    if ((DAT_1c000d061 != '\0') && ((param_3 & 1) == 0)) {
      local_3f = 1;
      local_3c = 0x100;
    }
    *local_68[0] = param_1;
    local_68[0][2] = param_2;
    local_68[0][3] = (int)param_5;
    memcpy(local_68[0] + 4,param_4,param_5);
    memset((void *)((longlong)puVar1 + param_5 + 0x10),0,0xf0 - param_5);
    uVar2 = WinHvpSimplePoolHypercall_CallViaMacro(local_58[0],0x5c);
    (*local_20)(local_58[0]);
  }
  else {
    uVar2 = 0xc000000d;
  }
  return uVar2;
}



===== WinHvSignalEvent @ 1c0002a00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvSignalEvent(undefined4 param_1,undefined2 param_2)

{
  uint uVar1;
  undefined4 *local_res18 [2];
  longlong local_48 [3];
  undefined1 local_2f;
  undefined4 local_2c;
  code *local_10;
  
                    /* 0x2a00  32  WinHvSignalEvent */
  if (DAT_1c000d061 == '\0') {
    local_res18[0] =
         (undefined4 *)(ulonglong)((-(uint)(WinHvpNested != '\0') & 0x80000000) + 0x1005d);
    uVar1 = WinHvpHypercallRoutine();
  }
  else {
    memset(local_48,0,0x40);
    local_res18[0] = (undefined4 *)0x0;
    WinHvpSetupHypercall(local_res18,(undefined8 *)0x0,(longlong)local_48);
    local_2f = 1;
    local_2c = 8;
    *local_res18[0] = param_1;
    *(undefined2 *)(local_res18[0] + 1) = param_2;
    *(undefined2 *)((longlong)local_res18[0] + 6) = 0;
    uVar1 = WinHvpSimplePoolHypercall_CallViaMacro(local_48[0],0x5d);
    (*local_10)(local_48[0]);
  }
  return uVar1;
}



===== WinHvpSetProcessorPartitionSints @ 1c0002af4 =====

void WinHvpSetProcessorPartitionSints(void)

{
  int iVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  
  uVar4 = 5;
  puVar6 = &DAT_1c0006194;
  do {
    iVar5 = (-(uint)(WinHvpNested != '\0') & 0x1000) + 0xa0000 + uVar4;
    if (*puVar6 != 0) {
      uVar2 = (ulonglong)(*puVar6 & 0xff);
      uVar3 = uVar2 | 0x10000;
      if (DAT_1c000d061 != '\0') {
        iVar1 = WinHvpSetIsolatedVpRegister64Self(iVar5,uVar3);
        uVar3 = uVar2 | 0x110000;
        if (iVar1 < 0) {
          return;
        }
      }
      iVar5 = WinHvpSetVpRegister64Self(iVar5,uVar3);
      if (iVar5 < 0) {
        return;
      }
    }
    uVar4 = uVar4 + 1;
    puVar6 = puVar6 + 1;
    if (0xf < uVar4) {
      return;
    }
  } while( true );
}



===== WinHvGetSintEventFlags2 @ 1c0002b90 =====

undefined8 WinHvGetSintEventFlags2(uint param_1,ulonglong param_2,longlong *param_3)

{
  longlong lVar1;
  
                    /* 0x2b90  13  WinHvGetSintEventFlags2 */
  if (WinHvpConnected != '\0') {
    if ((param_2 & 0xfffffffe) != 0) {
      return 0xc0350005;
    }
    if ((param_2 & 1) == 0) {
      lVar1 = *(longlong *)
               ((ulonglong)SystemReserved1[0x12]._4_4_ * 0x58 + 0x10 + WinHvpVpDataPages);
    }
    else {
      if (DAT_1c000d061 == '\0') {
        return 0xc0350005;
      }
      lVar1 = *(longlong *)
               ((ulonglong)SystemReserved1[0x12]._4_4_ * 0x58 + 0x48 + WinHvpVpDataPages);
    }
    if (lVar1 != 0) {
      *param_3 = (ulonglong)param_1 * 0x100 + lVar1;
      return 0;
    }
  }
  return 0xc0350002;
}



===== WinHvGetSintMessage @ 1c0002c20 =====

longlong WinHvGetSintMessage(uint param_1)

{
  longlong local_res10 [3];
  
                    /* 0x2c20  14  WinHvGetSintMessage */
  local_res10[0] = 0;
  WinHvGetSintMessage2(param_1,0,local_res10);
  return local_res10[0];
}



===== WinHvGetSintMessage2 @ 1c0002c50 =====

undefined8 WinHvGetSintMessage2(uint param_1,ulonglong param_2,longlong *param_3)

{
  longlong lVar1;
  
                    /* 0x2c50  15  WinHvGetSintMessage2 */
  if (WinHvpConnected != '\0') {
    if ((param_2 & 0xfffffffe) != 0) {
      return 0xc0350005;
    }
    if ((param_2 & 1) == 0) {
      lVar1 = *(longlong *)((ulonglong)SystemReserved1[0x12]._4_4_ * 0x58 + WinHvpVpDataPages);
    }
    else {
      if (DAT_1c000d061 == '\0') {
        return 0xc0350005;
      }
      lVar1 = *(longlong *)
               ((ulonglong)SystemReserved1[0x12]._4_4_ * 0x58 + 0x38 + WinHvpVpDataPages);
    }
    if (lVar1 != 0) {
      *param_3 = (ulonglong)param_1 * 0x100 + lVar1;
      return 0;
    }
  }
  return 0xc0350002;
}



===== WinHvReconnectSynic @ 1c0002ce0 =====

void WinHvReconnectSynic(void)

{
                    /* 0x2ce0  23  WinHvReconnectSynic */
  WinHvpConnectToSynic('\x01');
  return;
}



===== WinHvSetEndOfMessage @ 1c0002d00 =====

void WinHvSetEndOfMessage(void)

{
                    /* 0x2d00  25  WinHvSetEndOfMessage */
  WinHvSetEndOfMessage2(0);
  return;
}



===== WinHvSetEndOfMessage2 @ 1c0002d20 =====

ulonglong WinHvSetEndOfMessage2(uint param_1)

{
  ulonglong uVar1;
  
                    /* 0x2d20  26  WinHvSetEndOfMessage2 */
  if ((param_1 & 0xfffffffe) == 0) {
    if (WinHvpConnected == '\0') {
      uVar1 = 0xc0350002;
    }
    else {
      uVar1 = WinHvpSetVpRegister64Self2
                        ((-(uint)(WinHvpNested != '\0') & 0x1000) + 0xa0014,0,(byte)param_1 & 1);
    }
  }
  else {
    uVar1 = 0xc0350005;
  }
  return uVar1;
}



===== WinHvSetSint @ 1c0002d80 =====

void WinHvSetSint(uint param_1,byte param_2,char param_3,char param_4,ulonglong *param_5)

{
  uint uVar1;
  
                    /* 0x2d80  27  WinHvSetSint */
  uVar1 = param_3 != '\0' | 2;
  if (param_4 == '\0') {
    uVar1 = (uint)(param_3 != '\0');
  }
  WinHvSetSint2(param_1,param_2,param_5,uVar1);
  return;
}



===== WinHvSetSint2 @ 1c0002dc0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong WinHvSetSint2(uint param_1,byte param_2,ulonglong *param_3,uint param_4)

{
  bool bVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  undefined1 auStack_88 [40];
  longlong local_60;
  ulonglong uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  ulonglong local_40;
  
                    /* 0x2dc0  28  WinHvSetSint2 */
  local_40 = __security_cookie ^ (ulonglong)auStack_88;
  local_50 = 0;
  uStack_48 = 0;
  uVar2 = KeQueryGroupAffinity((short)param_3[1]);
  uVar2 = uVar2 & *param_3;
  if (uVar2 == 0) {
    uVar3 = 0;
  }
  else {
    puVar5 = &local_50;
    bVar1 = false;
    uVar4 = 0;
    if (uVar2 != 0) {
      for (; (uVar2 >> uVar4 & 1) == 0; uVar4 = uVar4 + 1) {
      }
    }
    local_60 = 0;
    uStack_58 = (ulonglong)(ushort)param_3[1];
    if (uVar2 != 0) {
      bVar1 = true;
      do {
        uVar2 = uVar2 & ~(1L << (uVar4 & 0x3f));
        local_60 = 1L << ((byte)uVar4 & 0x3f);
        KeSetSystemGroupAffinityThread(&local_60,puVar5);
        puVar5 = (undefined8 *)0x0;
        uVar4 = WinHvSetSintOnCurrentProcessor2(param_1,param_2,param_4);
        uVar3 = uVar4 & 0xffffffff;
        if ((int)uVar4 < 0) goto LAB_1c0002e7b;
        uVar4 = 0;
        if (uVar2 != 0) {
          for (; (uVar2 >> uVar4 & 1) == 0; uVar4 = uVar4 + 1) {
          }
        }
      } while (uVar2 != 0);
    }
    uVar3 = 0;
    if (bVar1) {
LAB_1c0002e7b:
      KeRevertToUserGroupAffinityThread(&local_50);
    }
  }
  return uVar3;
}



===== WinHvSetSintOnCurrentProcessor @ 1c0002ec0 =====

void WinHvSetSintOnCurrentProcessor(uint param_1,byte param_2,char param_3,char param_4)

{
  uint uVar1;
  
                    /* 0x2ec0  29  WinHvSetSintOnCurrentProcessor */
  uVar1 = param_3 != '\0' | 2;
  if (param_4 == '\0') {
    uVar1 = (uint)(param_3 != '\0');
  }
  WinHvSetSintOnCurrentProcessor2(param_1,param_2,uVar1);
  return;
}



===== WinHvSetSintOnCurrentProcessor2 @ 1c0002ef0 =====

ulonglong WinHvSetSintOnCurrentProcessor2(uint param_1,byte param_2,uint param_3)

{
  uint uVar1;
  ulonglong uVar2;
  int iVar3;
  
                    /* 0x2ef0  30  WinHvSetSintOnCurrentProcessor2 */
  if (WinHvpConnected == '\0') {
    return 0xc0350002;
  }
  if ((0xf < param_1) || ((param_3 & 0xfffffff8) != 0)) {
    return 0xc0350005;
  }
  uVar2 = (ulonglong)(param_3 & 3) << 0x10 | (ulonglong)param_2;
  iVar3 = (-(uint)(WinHvpNested != '\0') & 0x1000) + 0xa0000 + param_1;
  if (DAT_1c000d061 == '\0') {
    if ((param_3 & 4) != 0) {
      return 0xc0350005;
    }
  }
  else {
    uVar1 = WinHvpSetIsolatedVpRegister64Self(iVar3,uVar2);
    uVar2 = uVar2 | ~-(uint)((param_3 & 4) != 0) & 0x100000;
    if ((int)uVar1 < 0) {
      return (ulonglong)uVar1;
    }
  }
  uVar2 = WinHvpSetVpRegister64Self2(iVar3,uVar2,'\0');
  return uVar2 & 0xffffffff;
}



===== WinHvpConnectToSynic @ 1c0002fb4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WinHvpConnectToSynic(char param_1)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  ulonglong uVar5;
  uint uVar6;
  undefined8 *puVar7;
  bool bVar8;
  undefined1 auStack_78 [32];
  undefined8 local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 uStack_48;
  longlong local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_78;
  puVar7 = &local_30;
  local_58 = 0;
  uStack_48 = 0;
  local_50 = 0;
  local_4c = 0;
  bVar1 = false;
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  uStack_28 = 0;
  uVar3 = KeQueryActiveProcessorCountEx(0xffff);
  RtlInitializeBitMap(&local_50,WinHvpSynicProcessorsBitmap,uVar3);
  bVar8 = WinHvpNested != '\0';
  ExAcquireFastMutex(&WinHvpSynicChangeLock);
  iVar4 = WinHvpGetVpRegister64Self((-(uint)bVar8 & 0x1000) + 0xa0011,&local_58);
  if (((-1 < iVar4) && (local_58 == 1)) && (uVar6 = 0, uVar3 != 0)) {
    do {
      bVar8 = false;
      cVar2 = RtlTestBit(&local_50,uVar6);
      if (cVar2 == '\0') {
LAB_1c00030a4:
        local_58 = local_58 & 0xffffffff00000000;
        local_40 = 0;
        uStack_38 = 0;
        KeGetProcessorNumberFromIndex(uVar6,&local_58);
        uStack_38 = CONCAT62(uStack_38._2_6_,(undefined2)local_58);
        local_40 = 1L << (local_58._2_1_ & 0x3f);
        KeSetSystemGroupAffinityThread(&local_40,puVar7);
        puVar7 = (undefined8 *)0x0;
        bVar1 = true;
        if (bVar8) {
          WinHvpDisableSynic();
        }
        uVar5 = WinHvpEnableSynic();
        if ((int)uVar5 < 0) goto LAB_1c000312a;
        WinHvpSetProcessorPartitionSints();
        RtlSetBit(&local_50,uVar6);
      }
      else if (param_1 != '\0') {
        bVar8 = true;
        goto LAB_1c00030a4;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar3);
    if (bVar1) {
LAB_1c000312a:
      KeRevertToUserGroupAffinityThread(&local_30);
    }
  }
  ExReleaseFastMutex(&WinHvpSynicChangeLock);
  return;
}



===== WinHvpDisableSynic @ 1c0003180 =====

void WinHvpDisableSynic(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)((ulonglong)SystemReserved1[0x12]._4_4_ * 0x58 + WinHvpVpDataPages);
  WinHvpDisableSynicComponent(puVar1,(-(uint)(WinHvpNested != '\0') & 0x1000) + 0xa0013,'\0');
  WinHvpDisableSynicComponent(puVar1 + 2,(-(uint)(WinHvpNested != '\0') & 0x1000) + 0xa0012,'\0');
  if (DAT_1c000d061 != '\0') {
    WinHvpDisableSynicComponent(puVar1 + 7,0xa0013,'\x01');
    WinHvpDisableSynicComponent(puVar1 + 9,0xa0012,'\x01');
  }
  return;
}



===== WinHvpDisableSynicComponent @ 1c0003218 =====

void WinHvpDisableSynicComponent(undefined8 *param_1,int param_2,char param_3)

{
  ulonglong uVar1;
  char cVar2;
  ulonglong local_res8;
  
  local_res8 = 0;
  if (*(char *)((longlong)param_1 + 10) != '\0') {
    uVar1 = WinHvpGetVpRegister64Self2(param_2,&local_res8,param_3);
    if (-1 < (int)uVar1) {
      WinHvpSetVpRegister64Self2(param_2,local_res8 & 0xfffffffffffffffe,param_3);
    }
    *(undefined1 *)((longlong)param_1 + 10) = 0;
  }
  if (*(char *)((longlong)param_1 + 9) != '\0') {
    MmUnmapIoSpace(*param_1);
    *(undefined1 *)((longlong)param_1 + 9) = 0;
  }
  if (*(char *)(param_1 + 1) != '\0') {
    if ((DAT_1c000d061 == '\0') || (param_3 != '\0')) {
      cVar2 = '\0';
    }
    else {
      cVar2 = '\x01';
    }
    WinHvpFreeOverlayPages(*param_1,cVar2);
    *(undefined1 *)(param_1 + 1) = 0;
  }
  *param_1 = 0;
  return;
}



===== WinHvpEnableSynic @ 1c00032c0 =====

ulonglong WinHvpEnableSynic(void)

{
  ulonglong uVar1;
  ulonglong uVar2;
  int iVar3;
  longlong *plVar4;
  ulonglong local_res10;
  
  local_res10 = 0;
  plVar4 = (longlong *)((ulonglong)SystemReserved1[0x12]._4_4_ * 0x58 + WinHvpVpDataPages);
  uVar1 = WinHvpEnableSynicComponent(plVar4,(-(uint)(WinHvpNested != '\0') & 0x1000) + 0xa0013,'\0')
  ;
  uVar2 = uVar1 & 0xffffffff;
  if (-1 < (int)uVar1) {
    WinHvpEnableSynicComponent(plVar4 + 2,(-(uint)(WinHvpNested != '\0') & 0x1000) + 0xa0012,'\0');
    iVar3 = (-(uint)(WinHvpNested != '\0') & 0x1000) + 0xa0010;
    uVar1 = WinHvpGetVpRegister64Self2(iVar3,&local_res10,'\0');
    uVar2 = uVar1 & 0xffffffff;
    if (-1 < (int)uVar1) {
      local_res10 = local_res10 | 1;
      uVar1 = WinHvpSetVpRegister64Self2(iVar3,local_res10,'\0');
      uVar2 = uVar1 & 0xffffffff;
      if (-1 < (int)uVar1) {
        if (DAT_1c000d061 == '\0') {
          return uVar2;
        }
        WinHvpEnableSynicComponent(plVar4 + 7,0xa0013,'\x01');
        WinHvpEnableSynicComponent(plVar4 + 9,0xa0012,'\x01');
        uVar1 = WinHvpGetVpRegister64Self2(0xa0010,&local_res10,'\x01');
        if ((int)uVar1 < 0) {
          return uVar2;
        }
        WinHvpSetVpRegister64Self2(0xa0010,local_res10 | 1,'\x01');
        return uVar2;
      }
    }
  }
  WinHvpDisableSynic();
  return uVar2;
}



===== WinHvpEnableSynicComponent @ 1c00033f0 =====

ulonglong WinHvpEnableSynicComponent(longlong *param_1,int param_2,char param_3)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong *puVar5;
  ulonglong uVar6;
  ulonglong local_res20;
  
  local_res20 = 0;
  puVar5 = &local_res20;
  uVar2 = WinHvpGetVpRegister64Self2(param_2,puVar5,param_3);
  uVar4 = local_res20;
  uVar6 = uVar2 & 0xffffffff;
  if ((int)uVar2 < 0) {
    return uVar2;
  }
  if ((((WinHvpCpuManagement == '\0') && (WinHvpNested == '\0')) &&
      ((DAT_1c000d061 == '\0' || (param_3 != '\0')))) && ((local_res20 & 1) == 0)) {
    lVar3 = WinHvpAllocateOverlayPages(1,'\0');
    *param_1 = lVar3;
    if (lVar3 == 0) {
      uVar6 = 0xc000009a;
      goto LAB_1c000346a;
    }
    *(undefined1 *)(param_1 + 1) = 1;
    uVar2 = MmGetPhysicalAddress(lVar3);
  }
  else {
    uVar2 = local_res20 & 0xfffffffffffff000;
    uVar1 = WinHvpValidateAndMapOverlayAddress(uVar2,puVar5,param_3 == '\0',param_1);
    uVar6 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) goto LAB_1c000346a;
    *(undefined1 *)((longlong)param_1 + 9) = 1;
  }
  *(undefined1 *)((longlong)param_1 + 10) = 0;
  if ((uVar4 & 1) != 0) {
    return uVar6;
  }
  uVar4 = WinHvpSetVpRegister64Self2
                    (param_2,uVar2 & 0xfffffffffffff000 | (ulonglong)((uint)uVar4 & 0xffe) | 1,
                     param_3);
  uVar6 = uVar4 & 0xffffffff;
  if (-1 < (int)uVar4) {
    *(undefined1 *)((longlong)param_1 + 10) = 1;
    return uVar6;
  }
LAB_1c000346a:
  WinHvpDisableSynicComponent(param_1,param_2,param_3);
  return uVar6;
}



===== WinHvGetCurrentVpIndex @ 1c0003520 =====

undefined8 WinHvGetCurrentVpIndex(undefined4 *param_1)

{
  undefined8 uVar1;
  ulonglong local_res10 [3];
  
                    /* 0x3520  11  WinHvGetCurrentVpIndex */
  if (WinHvpConnected == '\0') {
    uVar1 = 0xc0350002;
  }
  else {
    local_res10[0] = 0;
    uVar1 = WinHvpGetVpRegister64Self
                      ((-(uint)(WinHvpNested != '\0') & 0x1000) + 0x90003,local_res10);
    *param_1 = (undefined4)local_res10[0];
  }
  return uVar1;
}



===== WinHvGetVpRegisters @ 1c0003580 =====

void WinHvGetVpRegisters(undefined8 param_1,undefined4 param_2,undefined1 param_3,uint param_4,
                        void *param_5,longlong *param_6,void *param_7)

{
  void *in_stack_ffffffffffffff88;
  undefined8 in_stack_ffffffffffffff90;
  undefined8 in_stack_ffffffffffffffc8;
  undefined8 in_stack_ffffffffffffffd0;
  undefined8 local_18;
  undefined8 local_10;
  
                    /* 0x3580  16  WinHvGetVpRegisters */
  local_10 = (ulonglong)CONCAT14(param_3,param_2);
  local_18 = param_1;
  WinHvpSpecialListRepHypercall
            (0x50,(ulonglong)param_4,(undefined4 *)&local_18,param_4,in_stack_ffffffffffffff88,
             in_stack_ffffffffffffff90,param_5,4,(undefined *)0x0,(undefined *)0x0,param_7,0x10,
             in_stack_ffffffffffffffc8,in_stack_ffffffffffffffd0,param_6);
  return;
}



===== WinHvNtProcessorToVpIndex @ 1c0003610 =====

undefined8 WinHvNtProcessorToVpIndex(uint param_1,undefined4 *param_2)

{
                    /* 0x3610  18  WinHvNtProcessorToVpIndex */
  if (WinHvpMaximumProcessorCount <= param_1) {
    return 0xc0000001;
  }
  if (*(char *)(WinHvpProcessorToVpIndex + 4 + (ulonglong)param_1 * 8) == '\0') {
    return 0xc0350002;
  }
  *param_2 = *(undefined4 *)(WinHvpProcessorToVpIndex + (ulonglong)param_1 * 8);
  return 0;
}



===== WinHvProcessorNumberToVpIndex @ 1c0003650 =====

ulonglong WinHvProcessorNumberToVpIndex(undefined4 param_1,undefined4 *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  undefined4 local_res8 [2];
  
                    /* 0x3650  21  WinHvProcessorNumberToVpIndex */
  uVar2 = 0xc0000001;
  local_res8[0] = param_1;
  uVar1 = KeGetProcessorIndexFromNumber(local_res8);
  if (uVar1 != 0xffffffff) {
    uVar2 = WinHvNtProcessorToVpIndex(uVar1,param_2);
    uVar2 = uVar2 & 0xffffffff;
  }
  return uVar2;
}



===== WinHvSetVpRegisters @ 1c00036a0 =====

void WinHvSetVpRegisters(undefined8 param_1,undefined4 param_2,undefined1 param_3,uint param_4,
                        undefined4 *param_5,undefined8 *param_6,longlong *param_7)

{
  byte bVar1;
  uint uVar2;
  void *in_stack_ffffffffffffff78;
  undefined8 in_stack_ffffffffffffff80;
  undefined8 in_stack_ffffffffffffffb8;
  undefined8 in_stack_ffffffffffffffc0;
  undefined8 local_28;
  undefined8 local_20;
  undefined4 *local_18;
  undefined8 *local_10;
  
                    /* 0x36a0  31  WinHvSetVpRegisters */
  local_20 = 0;
  uVar2 = param_4;
  bVar1 = KeGetCurrentIrql();
  if (bVar1 < 3) {
    local_18 = param_5;
    local_10 = param_6;
    local_20 = (ulonglong)CONCAT14(param_3,param_2);
    local_28 = param_1;
    WinHvpSpecialListRepHypercall
              (0x51,(ulonglong)param_4,(undefined4 *)&local_28,uVar2,in_stack_ffffffffffffff78,
               in_stack_ffffffffffffff80,&local_18,0x20,WinHvpSetVpRegisterBuilder,
               WinHvpSetVpRegisterAdvancer,(void *)0x0,0,in_stack_ffffffffffffffb8,
               in_stack_ffffffffffffffc0,param_7);
  }
  else {
    WinHvpSetVpRegistersElevated(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return;
}



===== WinHvpGetMsrNameFromRegisterName @ 1c00037d4 =====

int WinHvpGetMsrNameFromRegisterName(int param_1,undefined1 *param_2)

{
  *param_2 = 0;
  if (param_1 < 0xa0012) {
    if (param_1 != 0xa0011) {
      if (param_1 < 0xa0005) {
        if (param_1 != 0xa0004) {
          if (param_1 < 0x90023) {
            if (param_1 == 0x90022) {
              return 0x400000e2;
            }
            if (param_1 == 0x240) {
              return 0x40000022;
            }
            if (param_1 == 0x90002) {
              return 0x40000000;
            }
            if (param_1 == 0x90003) {
              return 0x40000002;
            }
            if (param_1 == 0x90004) {
              return 0x40000020;
            }
            if (param_1 == 0x90019) {
              return -0x3ffefed0;
            }
            return 0x400000e0;
          }
          if (param_1 == 0x91003) {
            return 0x40001002;
          }
        }
LAB_1c00038ad:
        return param_1 + 0x3ff60090;
      }
      if ((((param_1 < 0xa000c) || (param_1 == 0xa000c)) || (param_1 == 0xa000d)) ||
         ((param_1 == 0xa000e || (param_1 == 0xa000f)))) goto LAB_1c00038ad;
    }
  }
  else {
    if (0xa1008 < param_1) {
      if (param_1 < 0xa1010) goto LAB_1c00038ad;
      goto LAB_1c000391e;
    }
    if ((((param_1 == 0xa1008) || (0xa1002 < param_1)) || (param_1 == 0xa1002)) ||
       ((((param_1 != 0xa0012 && (param_1 != 0xa0013)) && (param_1 != 0xa0014)) &&
        (param_1 != 0xa0015)))) goto LAB_1c00038ad;
  }
  *param_2 = 1;
LAB_1c000391e:
  return param_1 + 0x3ff60070;
}



===== WinHvpGetVpRegister64Self @ 1c000392c =====

void WinHvpGetVpRegister64Self(int param_1,ulonglong *param_2)

{
  WinHvpGetVpRegister64Self2(param_1,param_2,'\0');
  return;
}



===== WinHvpGetVpRegister64Self2 @ 1c0003944 =====

ulonglong WinHvpGetVpRegister64Self2(int param_1,ulonglong *param_2,char param_3)

{
  ulonglong uVar1;
  uint uVar2;
  ulonglong uVar3;
  char cVar4;
  char local_18 [24];
  
  uVar3 = 0;
  local_18[0] = '\0';
  uVar2 = WinHvpGetMsrNameFromRegisterName(param_1,local_18);
  cVar4 = (char)uVar3;
  if ((param_3 == '\0') || ((local_18[0] != cVar4 && (DAT_1c000d061 != cVar4)))) {
    if ((local_18[0] == cVar4) || ((param_3 != '\0' || (DAT_1c000d061 == cVar4)))) {
      uVar1 = rdmsr(uVar2);
      *param_2 = uVar1;
    }
    else {
      uVar3 = WinHvpReadIsolatedMsr((ulonglong)uVar2,param_2);
      uVar3 = uVar3 & 0xffffffff;
    }
    uVar3 = uVar3 & 0xffffffff;
  }
  else {
    uVar3 = 0xc0350005;
  }
  return uVar3;
}



===== WinHvpSetVpRegister64Self @ 1c00039d0 =====

void WinHvpSetVpRegister64Self(int param_1,ulonglong param_2)

{
  WinHvpSetVpRegister64Self2(param_1,param_2,'\0');
  return;
}



===== WinHvpSetVpRegister64Self2 @ 1c00039e8 =====

ulonglong WinHvpSetVpRegister64Self2(int param_1,ulonglong param_2,char param_3)

{
  uint uVar1;
  ulonglong uVar2;
  char cVar3;
  char local_res18 [16];
  
  uVar2 = 0;
  local_res18[0] = '\0';
  uVar1 = WinHvpGetMsrNameFromRegisterName(param_1,local_res18);
  cVar3 = (char)uVar2;
  if ((param_3 == '\0') || ((local_res18[0] != cVar3 && (DAT_1c000d061 != cVar3)))) {
    if ((local_res18[0] == cVar3) || ((param_3 != '\0' || (DAT_1c000d061 == cVar3)))) {
      wrmsr(uVar1,param_2);
    }
    else {
      uVar2 = WinHvpWriteIsolatedMsr((ulonglong)uVar1,param_2);
      uVar2 = uVar2 & 0xffffffff;
    }
    uVar2 = uVar2 & 0xffffffff;
  }
  else {
    uVar2 = 0xc0350005;
  }
  return uVar2;
}



===== WinHvpSetVpRegisterAdvancer @ 1c0003a70 =====

longlong * WinHvpSetVpRegisterAdvancer(longlong *param_1,uint param_2)

{
  *param_1 = *param_1 + (ulonglong)param_2 * 4;
  param_1[1] = param_1[1] + (ulonglong)param_2 * 0x10;
  return param_1;
}



===== WinHvpSetVpRegisterBuilder @ 1c0003aa0 =====

void WinHvpSetVpRegisterBuilder(undefined4 *param_1,undefined8 *param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  puVar2 = (undefined4 *)*param_2;
  puVar3 = (undefined8 *)param_2[1];
  for (; param_3 != 0; param_3 = param_3 + -1) {
    uVar1 = *puVar2;
    puVar2 = puVar2 + 1;
    *param_1 = uVar1;
    uVar4 = *puVar3;
    uVar5 = puVar3[1];
    puVar3 = puVar3 + 2;
    *(undefined8 *)(param_1 + 4) = uVar4;
    *(undefined8 *)(param_1 + 6) = uVar5;
    param_1 = param_1 + 8;
  }
  return;
}



===== WinHvpSetVpRegistersElevated @ 1c0003ad4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong WinHvpSetVpRegistersElevated
                    (undefined8 param_1,undefined4 param_2,undefined1 param_3,uint param_4,
                    undefined4 *param_5,undefined8 *param_6,longlong *param_7)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  ulonglong uVar9;
  undefined1 auStack_378 [32];
  uint *local_358;
  uint local_300 [64];
  undefined8 local_200;
  undefined4 local_1f8;
  undefined1 local_1f4;
  undefined1 local_1f3;
  undefined2 local_1f2;
  undefined4 local_1f0 [4];
  undefined8 local_1e0 [28];
  ulonglong local_100;
  
  local_100 = __security_cookie ^ (ulonglong)auStack_378;
  if (param_4 == 0) {
    uVar9 = (ulonglong)((WinHvpConnected != '\0') + 0xc0350002);
  }
  else {
    *param_7 = 0;
    memset(local_1f0,0,0xf0);
    local_1f3 = 0;
    local_1f2 = 0;
    local_200 = param_1;
    local_1f8 = param_2;
    local_1f4 = param_3;
    do {
      local_300[0] = 0;
      if (param_4 < 8) {
        uVar7 = param_4;
        if (param_4 != 0) goto LAB_1c0003b96;
      }
      else {
        uVar7 = 7;
LAB_1c0003b96:
        puVar4 = local_1e0;
        uVar9 = (ulonglong)uVar7;
        puVar6 = param_6;
        puVar8 = param_5;
        do {
          uVar1 = *puVar8;
          puVar8 = puVar8 + 1;
          *(undefined4 *)(puVar4 + -2) = uVar1;
          uVar2 = *puVar6;
          uVar3 = puVar6[1];
          puVar6 = puVar6 + 2;
          *puVar4 = uVar2;
          puVar4[1] = uVar3;
          puVar4 = puVar4 + 4;
          uVar9 = uVar9 - 1;
        } while (uVar9 != 0);
      }
      MmGetPhysicalAddress(&local_200);
      local_358 = local_300;
      uVar9 = WinHvpHypercall();
      uVar5 = (ulonglong)local_300[0];
      *param_7 = *param_7 + uVar5;
      param_4 = param_4 - local_300[0];
      param_5 = param_5 + uVar5;
      param_6 = param_6 + uVar5 * 2;
    } while (((int)uVar9 == 0) && (param_4 != 0));
  }
  return uVar9;
}



===== WinHvDisablePartitionVtl @ 1c0003c40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 WinHvDisablePartitionVtl(undefined8 param_1,undefined1 param_2,undefined1 param_3)

{
  undefined4 uVar1;
  undefined8 *local_res8;
  longlong local_48 [7];
  code *local_10;
  
                    /* 0x3c40  6  WinHvDisablePartitionVtl */
  local_res8 = (undefined8 *)0x0;
  memset(local_48,0,0x40);
  WinHvpSetupHypercall(&local_res8,(undefined8 *)0x0,(longlong)local_48);
  *local_res8 = 0;
  local_res8[1] = 0;
  *local_res8 = param_1;
  *(undefined1 *)(local_res8 + 1) = param_2;
  *(undefined1 *)((longlong)local_res8 + 9) = param_3;
  uVar1 = WinHvpSimplePoolHypercall_CallViaMacro(local_48[0],0xe);
  (*local_10)(local_48[0]);
  return uVar1;
}



===== WinHvDisableVpVtl @ 1c0003cd0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
WinHvDisableVpVtl(undefined8 param_1,undefined4 param_2,undefined1 param_3,undefined1 param_4)

{
  undefined4 uVar1;
  undefined8 *local_res8;
  longlong local_48 [7];
  code *local_10;
  
                    /* 0x3cd0  7  WinHvDisableVpVtl */
  local_res8 = (undefined8 *)0x0;
  memset(local_48,0,0x40);
  WinHvpSetupHypercall(&local_res8,(undefined8 *)0x0,(longlong)local_48);
  *local_res8 = 0;
  local_res8[1] = 0;
  *local_res8 = param_1;
  *(undefined4 *)(local_res8 + 1) = param_2;
  *(undefined1 *)((longlong)local_res8 + 0xc) = param_3;
  *(undefined1 *)((longlong)local_res8 + 0xd) = param_4;
  uVar1 = WinHvpSimplePoolHypercall_CallViaMacro(local_48[0],0x10);
  (*local_10)(local_48[0]);
  return uVar1;
}



===== WinHvEnablePartitionVtl @ 1c0003d70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
WinHvEnablePartitionVtl
          (undefined8 param_1,undefined1 param_2,byte param_3,char param_4,char param_5)

{
  undefined4 uVar1;
  byte bVar2;
  undefined8 *local_res8;
  longlong local_48 [7];
  code *local_10;
  
                    /* 0x3d70  8  WinHvEnablePartitionVtl */
  local_res8 = (undefined8 *)0x0;
  memset(local_48,0,0x40);
  WinHvpSetupHypercall(&local_res8,(undefined8 *)0x0,(longlong)local_48);
  *local_res8 = 0;
  local_res8[1] = 0;
  *local_res8 = param_1;
  *(undefined1 *)(local_res8 + 1) = param_2;
  bVar2 = (*(byte *)((longlong)local_res8 + 9) ^ param_3) & 1 ^ *(byte *)((longlong)local_res8 + 9);
  bVar2 = (param_4 * '\x02' ^ bVar2) & 2 ^ bVar2;
  *(byte *)((longlong)local_res8 + 9) = (param_5 << 2 ^ bVar2) & 4 ^ bVar2;
  uVar1 = WinHvpSimplePoolHypercall_CallViaMacro(local_48[0],0xd);
  (*local_10)(local_48[0]);
  return uVar1;
}



===== WinHvEnableVpVtl @ 1c0003e40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
WinHvEnableVpVtl(undefined8 param_1,undefined4 param_2,undefined1 param_3,undefined8 *param_4)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined4 uVar3;
  undefined8 *local_res8;
  longlong local_58 [7];
  code *local_20;
  
                    /* 0x3e40  9  WinHvEnableVpVtl */
  local_res8 = (undefined8 *)0x0;
  memset(local_58,0,0x40);
  WinHvpSetupHypercall(&local_res8,(undefined8 *)0x0,(longlong)local_58);
  puVar2 = local_res8;
  memset(local_res8,0,0xf0);
  *puVar2 = param_1;
  *(undefined4 *)(puVar2 + 1) = param_2;
  *(undefined1 *)((longlong)puVar2 + 0xc) = param_3;
  uVar1 = param_4[1];
  puVar2[2] = *param_4;
  puVar2[3] = uVar1;
  uVar1 = param_4[3];
  puVar2[4] = param_4[2];
  puVar2[5] = uVar1;
  uVar1 = param_4[5];
  puVar2[6] = param_4[4];
  puVar2[7] = uVar1;
  uVar1 = param_4[7];
  puVar2[8] = param_4[6];
  puVar2[9] = uVar1;
  uVar1 = param_4[9];
  puVar2[10] = param_4[8];
  puVar2[0xb] = uVar1;
  uVar1 = param_4[0xb];
  puVar2[0xc] = param_4[10];
  puVar2[0xd] = uVar1;
  uVar1 = param_4[0xd];
  puVar2[0xe] = param_4[0xc];
  puVar2[0xf] = uVar1;
  uVar1 = param_4[0xf];
  puVar2[0x10] = param_4[0xe];
  puVar2[0x11] = uVar1;
  uVar1 = param_4[0x11];
  puVar2[0x12] = param_4[0x10];
  puVar2[0x13] = uVar1;
  uVar1 = param_4[0x13];
  puVar2[0x14] = param_4[0x12];
  puVar2[0x15] = uVar1;
  uVar1 = param_4[0x15];
  puVar2[0x16] = param_4[0x14];
  puVar2[0x17] = uVar1;
  uVar1 = param_4[0x17];
  puVar2[0x18] = param_4[0x16];
  puVar2[0x19] = uVar1;
  uVar1 = param_4[0x19];
  puVar2[0x1a] = param_4[0x18];
  puVar2[0x1b] = uVar1;
  uVar1 = param_4[0x1b];
  puVar2[0x1c] = param_4[0x1a];
  puVar2[0x1d] = uVar1;
  uVar3 = WinHvpSimplePoolHypercall_CallViaMacro(local_58[0],0xf);
  (*local_20)(local_58[0]);
  return uVar3;
}



===== WinHvControlHypervisorIptTrace @ 1c0003f70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int WinHvControlHypervisorIptTrace(void *param_1,void *param_2)

{
  int iVar1;
  void *local_res8;
  void *local_res18 [2];
  longlong local_48 [7];
  code *local_10;
  
                    /* 0x3f70  5  WinHvControlHypervisorIptTrace */
  memset(local_48,0,0x40);
  local_res8 = (void *)0x0;
  local_res18[0] = (void *)0x0;
  WinHvpSetupHypercall(&local_res8,local_res18,(longlong)local_48);
  memcpy(local_res8,param_1,0x820);
  iVar1 = WinHvpSimplePoolHypercall_CallViaMacro(local_48[0],0xe9);
  if (-1 < iVar1) {
    memcpy(param_2,local_res18[0],0x1000);
  }
  (*local_10)(local_48[0]);
  return iVar1;
}



===== WinHvQueryReferenceCounter @ 1c0004020 =====

undefined8 WinHvQueryReferenceCounter(ulonglong *param_1)

{
  undefined8 uVar1;
  
                    /* 0x4020  22  WinHvQueryReferenceCounter */
  if (WinHvpConnected == '\0') {
    uVar1 = 0xc0350002;
  }
  else {
    uVar1 = WinHvpGetVpRegister64Self(0x90004,param_1);
  }
  return uVar1;
}



===== WinHvpFreeAllVpDataPages @ 1c0004050 =====

void WinHvpFreeAllVpDataPages(void)

{
  if (WinHvpVpDataPages != 0) {
    ExFreePoolWithTag(WinHvpVpDataPages,0x55764857);
    WinHvpVpDataPages = 0;
  }
  return;
}



===== HviGetEnlightenmentInformation @ 1c0004088 =====

/* WARNING: Removing unreachable block (ram,0x0001c00040a1) */

void HviGetEnlightenmentInformation(undefined8 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar4 = HviIsHypervisorMicrosoftCompatible();
  if ((char)uVar4 == '\0') {
    *param_1 = 0;
    param_1[1] = 0;
  }
  else {
    puVar1 = (undefined4 *)cpuid(0x40000004);
    uVar4 = puVar1[1];
    uVar2 = puVar1[2];
    uVar3 = puVar1[3];
    *(undefined4 *)param_1 = *puVar1;
    *(undefined4 *)((longlong)param_1 + 4) = uVar4;
    *(undefined4 *)(param_1 + 1) = uVar3;
    *(undefined4 *)((longlong)param_1 + 0xc) = uVar2;
  }
  return;
}



===== HviGetHypervisorFeatures @ 1c00040c8 =====

/* WARNING: Removing unreachable block (ram,0x0001c00040e1) */

void HviGetHypervisorFeatures(undefined8 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar4 = HviIsHypervisorMicrosoftCompatible();
  if ((char)uVar4 == '\0') {
    *param_1 = 0;
    param_1[1] = 0;
  }
  else {
    puVar1 = (undefined4 *)cpuid(0x40000003);
    uVar4 = puVar1[1];
    uVar2 = puVar1[2];
    uVar3 = puVar1[3];
    *(undefined4 *)param_1 = *puVar1;
    *(undefined4 *)((longlong)param_1 + 4) = uVar4;
    *(undefined4 *)(param_1 + 1) = uVar3;
    *(undefined4 *)((longlong)param_1 + 0xc) = uVar2;
  }
  return;
}



===== HviGetSharedGpaBoundary @ 1c0004108 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001c0004157) */
/* WARNING: Removing unreachable block (ram,0x0001c0004135) */

longlong HviGetSharedGpaBoundary(void)

{
  longlong lVar1;
  undefined4 uVar2;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = 0;
  uStack_20 = 0;
  uVar2 = HviIsHypervisorMicrosoftCompatible();
  if (((char)uVar2 != '\0') && (lVar1 = cpuid(0x40000003), (*(uint *)(lVar1 + 4) & 0x400000) != 0))
  {
    lVar1 = cpuid(0x4000000c);
    if ((*(uint *)(lVar1 + 4) & 0x20) != 0) {
      return 1L << ((byte)(*(uint *)(lVar1 + 4) >> 6) & 0x3f);
    }
  }
  return 0;
}



===== HviIsAnyHypervisorPresent @ 1c000418c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001c00041c0) */
/* WARNING: Removing unreachable block (ram,0x0001c00041af) */

undefined8 HviIsAnyHypervisorPresent(void)

{
  uint *puVar1;
  ulonglong uVar2;
  undefined1 uVar3;
  
  puVar1 = (uint *)cpuid_Version_info(1);
  uVar2 = (ulonglong)*puVar1;
  uVar3 = 0;
  if ((int)puVar1[3] < 0) {
    puVar1 = (uint *)cpuid(0x40000001);
    uVar2 = (ulonglong)*puVar1;
    uVar3 = 0;
    if (*puVar1 != 0x766e6258) {
      uVar3 = 1;
    }
  }
  return CONCAT71((int7)(uVar2 >> 8),uVar3);
}



===== HviIsHypervisorMicrosoftCompatible @ 1c00041e8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001c0004215) */

undefined4 HviIsHypervisorMicrosoftCompatible(void)

{
  int *piVar1;
  undefined8 uVar2;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = 0;
  uStack_20 = 0;
  uVar2 = HviIsAnyHypervisorPresent();
  if ((char)uVar2 == '\0') {
  }
  else {
    piVar1 = (int *)cpuid(0x40000001);
    local_28._0_4_ = *piVar1;
  }
  return CONCAT31((int3)((uint)(int)local_28 >> 8),(int)local_28 == 0x31237648);
}



===== _guard_check_icall @ 1c0004250 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c0004268 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c000428c =====

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



===== __cpu_features_init @ 1c0004300 =====

/* WARNING: Removing unreachable block (ram,0x0001c000436a) */
/* WARNING: Removing unreachable block (ram,0x0001c0004319) */
/* WARNING: Removing unreachable block (ram,0x0001c000430a) */

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



===== _sev_vmgexit @ 1c00043d0 =====

void _sev_vmgexit(void)

{
  vmgexit();
  return;
}



===== _sev_pvalidate @ 1c00043e0 =====

/* WARNING: Removing unreachable block (ram,0x0001c00043f1) */

undefined8
_sev_pvalidate(undefined8 param_1,ulonglong param_2,ulonglong param_3,undefined8 *param_4)

{
  undefined4 uVar1;
  
  uVar1 = pvalidate(param_1,param_2 & 0xffffffff,param_3 & 0xffffffff);
  rmpFlags(uVar1);
  *param_4 = CONCAT44((int)((ulonglong)param_1 >> 0x20),uVar1);
  return 0;
}



===== _sev_rmpadjust @ 1c0004410 =====

undefined4 _sev_rmpadjust(undefined8 param_1,ulonglong param_2,undefined8 param_3)

{
  undefined4 uVar1;
  
  uVar1 = rmpadjust(param_1,param_2 & 0xffffffff,param_3);
  rmpFlags(uVar1);
  return uVar1;
}



===== WinHvpReadIsolatedMsrDirect @ 1c0004430 =====

/* WARNING: Control flow encountered bad instruction data */

void WinHvpReadIsolatedMsrDirect(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== WinHvpWriteIsolatedMsrDirect @ 1c0004460 =====

/* WARNING: Control flow encountered bad instruction data */

void WinHvpWriteIsolatedMsrDirect(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== WinHvpIsolatedHypercallDirect @ 1c00044a0 =====

/* WARNING: Control flow encountered bad instruction data */

void WinHvpIsolatedHypercallDirect(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== __security_check_cookie @ 1c00044d0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0004510 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0004540 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0004540. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0004570 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c00045c0 =====

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



===== memset @ 1c00048c0 =====

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



===== __memset_repmovs @ 1c0004a00 =====

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



===== __memset_query @ 1c0004a80 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0004b00 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0004c40 =====

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



===== __memset_spec_plain @ 1c0004cc0 =====

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



===== DllUnload @ 1c0010010 =====

undefined8 DllUnload(void)

{
                    /* 0x10010  2  DllUnload */
  if (WinHvpDllLoadSuccessful != '\0') {
    if (WinHvpRunningLoopback == '\0') {
      WinHvpCleanupIsolation();
      WinHvpConnected = 0;
      WinHvpTeardownVpIndexCache();
      WinHvpCleanupSynicSupport();
      WinHvpCleanupHypercallSupport();
      WinHvpFreeAllVpDataPages();
      WinHvpTeardownNumaMaps();
      WinHvpEnvUninit();
    }
    else {
      WinHvpCleanupHypercallSupport();
      WinHvpTeardownNumaMaps();
    }
  }
  wil_UninitializeFeatureStaging();
  if (DAT_1c000d628 != 0) {
    ExFreePoolWithTag(DAT_1c000d628,0x55764857);
    DAT_1c000d628 = 0;
  }
  return 0;
}



===== WinHvpEnvInit @ 1c0010094 =====

void WinHvpEnvInit(void)

{
  undefined8 local_18;
  wchar_t *local_10;
  
  local_18 = 0x1c001a;
  local_10 = L"\\Driver\\WinHv";
  IoCreateDriver(&local_18,WinHvpHypervisorDriverInitialization);
  return;
}



===== WinHvpEnvUninit @ 1c00100d4 =====

void WinHvpEnvUninit(void)

{
  if (WinHvpHypervisorDriver != 0) {
    IoDeleteDriver();
    WinHvpHypervisorDriver = 0;
  }
  return;
}



===== wil_UninitializeFeatureStaging @ 1c0010104 =====

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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 1c001015c =====

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
      goto LAB_1c00101b9;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_1c00101b9;
    }
  }
  uVar1 = 0x206;
LAB_1c00101b9:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 1c00101c4 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  longlong *plVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  bool bVar5;
  
  plVar1 = wil_details_FeatureDescriptors_SkipPadding((longlong *)&wil_details_featureDescriptors_z)
  ;
  if (plVar1 != (longlong *)0x0) {
    uVar3 = 0;
    uVar4 = 0x180;
    do {
      uVar2 = *(uint *)*plVar1;
      if ((uVar2 >> 9 & 1) != 0) {
        if (((uint)uVar4 & uVar2) == 0) {
          bVar5 = *(char *)((longlong)plVar1 + 0x1f) != '\0';
        }
        else {
          bVar5 = (uVar2 & (uint)uVar4) == 0x100;
        }
        uVar2 = uVar2 & 0x40 ^ (uint)bVar5 << 6 | (uint)uVar3 & 0xffffffbf;
        uVar3 = (ulonglong)uVar2;
        LOCK();
        *(uint *)*plVar1 = *(uint *)*plVar1 ^ uVar2;
        UNLOCK();
      }
      plVar1 = wil_details_FeatureDescriptors_SkipPadding(plVar1 + 7);
    } while (plVar1 != (longlong *)0x0);
  }
  plVar1 = (longlong *)&wil_details_featureDescriptors_z;
  while( true ) {
    plVar1 = wil_details_FeatureDescriptors_SkipPadding(plVar1);
    if (plVar1 == (longlong *)0x0) break;
    wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
              ((uint *)*plVar1,(longlong)plVar1);
    plVar1 = plVar1 + 7;
  }
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 1c001027c =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 1c00102b4 =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_1c0010336;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_1c0010336;
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
LAB_1c0010336:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 1c0010380 =====

void wil_details_OnFeatureUsageProviderFlushNotification(int param_1)

{
  int iVar1;
  longlong *plVar2;
  
  iVar1 = g_wil_details_featureUsageCached;
  if (param_1 == 1) {
    LOCK();
    g_wil_details_featureUsageCached = 0;
    UNLOCK();
    if (iVar1 != 0) {
      plVar2 = (longlong *)&wil_details_featureDescriptors_z;
      while (plVar2 = wil_details_FeatureDescriptors_SkipPadding(plVar2), plVar2 != (longlong *)0x0)
      {
        if ((*(uint *)plVar2[1] & 1) != 0) {
          wil_details_RecordCachedUsage((int)plVar2[3],(uint *)plVar2[1]);
        }
        plVar2 = plVar2 + 7;
      }
    }
  }
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 1c00103e0 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 1c00103fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_UpdateFeatureConfiguredStates(void)

{
  int iVar1;
  longlong *plVar2;
  undefined1 auStack_58 [32];
  uint local_38 [2];
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  plVar2 = (longlong *)&wil_details_featureDescriptors_z;
  while( true ) {
    plVar2 = wil_details_FeatureDescriptors_SkipPadding(plVar2);
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
    plVar2 = plVar2 + 7;
  }
  return;
}



===== WinHvpConnectToHypervisor @ 1c00104b0 =====

undefined8 WinHvpConnectToHypervisor(void)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  uVar2 = HviIsAnyHypervisorPresent();
  if ((char)uVar2 != '\0') {
    uVar1 = HviIsHypervisorMicrosoftCompatible();
    if (((char)uVar1 == '\0') || (uVar2 = WinHvpCheckPartitionPrivileges(), (char)uVar2 == '\0')) {
      return 0xc035001e;
    }
    if (WinHvpRunningLoopback == '\0') {
      uVar2 = WinHvpSetHypervisorInformation();
      if ((int)uVar2 < 0) {
        return uVar2;
      }
      WinHvpConnected = 1;
      return uVar2;
    }
  }
  return 0xc0351000;
}



===== WinHvpDisconnectFromHypervisor @ 1c0010504 =====

void WinHvpDisconnectFromHypervisor(void)

{
  WinHvpConnected = 0;
  return;
}



===== WinHvpCleanupHypercallSupport @ 1c0010514 =====

void WinHvpCleanupHypercallSupport(void)

{
  byte bVar1;
  ulonglong uVar2;
  
  if (WinHvpNodeToHypercallLookaside != 0) {
    uVar2 = 0;
    if (WinHvpNodeCount != 0) {
      do {
        ExDeleteNPagedLookasideList(uVar2 * 0x80 + WinHvpNodeToHypercallLookaside);
        bVar1 = (char)uVar2 + 1;
        uVar2 = (ulonglong)bVar1;
      } while (bVar1 < WinHvpNodeCount);
    }
    ExFreePoolWithTag(WinHvpNodeToHypercallLookaside,0x4c764857);
  }
  WinHvpNodeToHypercallLookaside = 0;
  WinHvpTeardownNodeInfo();
  return;
}



===== WinHvpInitializeFallbackHypercallBuffers @ 1c0010588 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 WinHvpInitializeFallbackHypercallBuffers(void)

{
  KeInitializeSpinLock(&WinHvpFallbackSpinLock);
  DAT_1c000d040 = &WinHvpFallbackInputBuffer;
  _DAT_1c000d048 = MmGetPhysicalAddress();
  _DAT_1c000d050 = &WinHvpFallbackOutputBuffer;
  _DAT_1c000d058 = MmGetPhysicalAddress();
  _DAT_1c000d748 = 0;
  _DAT_1c000d750 = 0;
  _WinHvpFallbackMutex = 1;
  KeInitializeEvent(&DAT_1c000d758,1,0);
  DAT_1c000d010 = &WinHvpDispatchFallbackInputBuffer;
  DAT_1c000d020 = &WinHvpDispatchFallbackOutputBuffer;
  _DAT_1c000d018 = MmGetPhysicalAddress();
  _DAT_1c000d028 = MmGetPhysicalAddress(&WinHvpDispatchFallbackOutputBuffer);
  return 0;
}



===== WinHvpInitializeHypercallLookasideBuffer @ 1c0010668 =====

undefined4 WinHvpInitializeHypercallLookasideBuffer(void)

{
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  byte bVar4;
  ulonglong uVar5;
  
  WinHvpNodeInfo = ExAllocatePool2(0x40,(ulonglong)WinHvpNodeCount * 0x28,0x46764857);
  if (WinHvpNodeInfo != 0) {
    WinHvpNodeToHypercallLookaside =
         ExAllocatePool2(0x42,(ulonglong)WinHvpNodeCount << 7,0x4c764857);
    if (WinHvpNodeToHypercallLookaside != 0) {
      uVar5 = 0;
      if (WinHvpNodeCount == 0) {
        return 0;
      }
      uVar2 = 0;
      do {
        lVar3 = uVar5 * 0x80;
        ExInitializeNPagedLookasideList
                  (WinHvpNodeToHypercallLookaside + lVar3,WinHvpAllocateHypercallBuffer,
                   WinHvpFreeHypercallBuffer,0x200,0x30,uVar2,0);
        lVar1 = ExAllocateFromNPagedLookasideList(WinHvpNodeToHypercallLookaside + lVar3);
        if (lVar1 != 0) {
          ExFreeToNPagedLookasideList(WinHvpNodeToHypercallLookaside + lVar3,lVar1);
        }
        bVar4 = (char)uVar5 + 1;
        uVar5 = (ulonglong)bVar4;
        uVar2 = (uint)bVar4;
      } while (uVar2 < WinHvpNodeCount);
      return 0;
    }
    WinHvpTeardownNodeInfo();
  }
  return 0xc000009a;
}



===== WinHvpSlowHypercallRemote @ 1c00107a8 =====

undefined8 WinHvpSlowHypercallRemote(void)

{
  return 0xc0350002;
}



===== WinHvRetargetDeviceInterrupt @ 1c00107c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
WinHvRetargetDeviceInterrupt
          (undefined8 param_1,undefined8 param_2,undefined8 *param_3,void *param_4,uint param_5)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined8 *local_res8;
  undefined8 local_48 [7];
  code *local_10;
  
                    /* 0x107c0  24  WinHvRetargetDeviceInterrupt */
  memset(local_48,0,0x40);
  local_res8 = (undefined8 *)0x0;
  WinHvpSetupHypercall(&local_res8,(undefined8 *)0x0,(longlong)local_48);
  *local_res8 = 0;
  local_res8[1] = 0;
  local_res8[2] = 0;
  local_res8[3] = 0;
  local_res8[4] = 0;
  local_res8[5] = 0;
  local_res8[6] = 0;
  *local_res8 = param_1;
  local_res8[1] = param_2;
  uVar1 = param_3[1];
  local_res8[2] = *param_3;
  local_res8[3] = uVar1;
  memcpy(local_res8 + 5,param_4,(ulonglong)param_5);
  uVar2 = WinHvpVariableHeaderHypercall();
  (*local_10)(local_48[0]);
  return uVar2;
}



===== WinHvAllocateHostVisiblePages @ 1c0010888 =====

void WinHvAllocateHostVisiblePages(void)

{
  char cVar1;
  
  cVar1 = WinHvpIsIsolated();
  WinHvpAllocateHypervisorVisiblePages(1,0,0,0,cVar1);
  return;
}



===== WinHvFreeHostVisiblePages @ 1c00108b4 =====

void WinHvFreeHostVisiblePages(longlong param_1)

{
  char cVar1;
  
  cVar1 = WinHvpIsIsolated();
  WinHvpReclaimAndFreeHypervisorVisiblePages(param_1,cVar1);
  return;
}



===== WinHvpCleanupSynicSupport @ 1c00108d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WinHvpCleanupSynicSupport(void)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  undefined8 *puVar5;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 uStack_38;
  longlong local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  uStack_38 = 0;
  local_40 = 0;
  local_3c = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_20 = 0;
  uStack_18 = 0;
  if (WinHvpSynicProcessorsBitmap != 0) {
    puVar5 = &local_20;
    bVar1 = false;
    uVar3 = KeQueryActiveProcessorCountEx(0xffff);
    RtlInitializeBitMap(&local_40,WinHvpSynicProcessorsBitmap,uVar3);
    uVar4 = 0;
    if (uVar3 != 0) {
      do {
        cVar2 = RtlTestBit(&local_40,uVar4);
        if (cVar2 != '\0') {
          local_48 = 0;
          local_30 = 0;
          uStack_28 = 0;
          KeGetProcessorNumberFromIndex(uVar4,&local_48);
          uStack_28 = CONCAT62(uStack_28._2_6_,(undefined2)local_48);
          local_30 = 1L << (local_48._2_1_ & 0x3f);
          KeSetSystemGroupAffinityThread(&local_30,puVar5);
          puVar5 = (undefined8 *)0x0;
          bVar1 = true;
          WinHvpDisableSynic();
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar3);
      if (bVar1) {
        KeRevertToUserGroupAffinityThread(&local_20);
      }
    }
    RtlClearAllBits(&local_40);
    ExFreePoolWithTag(WinHvpSynicProcessorsBitmap,0x55764857);
    WinHvpSynicProcessorsBitmap = 0;
  }
  return;
}



===== WinHvpTeardownNodeInfo @ 1c0010a3c =====

void WinHvpTeardownNodeInfo(void)

{
  if (WinHvpNodeInfo != 0) {
    ExFreePoolWithTag(WinHvpNodeInfo,0x46764857);
    WinHvpNodeInfo = 0;
  }
  return;
}



===== WinHvpBuildVpIndexCache @ 1c0010a74 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 WinHvpBuildVpIndexCache(void)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  longlong lVar4;
  uint uVar5;
  undefined8 *puVar6;
  longlong lVar7;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  longlong local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_68;
  puVar6 = &local_30;
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  uStack_28 = 0;
  WinHvpProcessorToVpIndex =
       ExAllocatePool2(0x40,(ulonglong)WinHvpMaximumProcessorCount << 3,0x55764857);
  uVar3 = 0;
  if (WinHvpProcessorToVpIndex == 0) {
    uVar3 = 0xc000009a;
    WinHvpTeardownVpIndexCache();
  }
  else {
    uVar1 = KeQueryActiveProcessorCountEx(0xffff);
    uVar5 = 0;
    if (uVar1 != 0) {
      lVar4 = 0;
      lVar7 = 0;
      do {
        local_48 = 0;
        local_40 = 0;
        uStack_38 = 0;
        KeGetProcessorNumberFromIndex(uVar5,&local_48);
        uStack_38 = CONCAT62(uStack_38._2_6_,(undefined2)local_48);
        local_40 = 1L << (local_48._2_1_ & 0x3f);
        KeSetSystemGroupAffinityThread(&local_40,puVar6);
        puVar6 = (undefined8 *)0x0;
        uVar2 = WinHvGetCurrentVpIndex((undefined4 *)(WinHvpProcessorToVpIndex + lVar7));
        if (-1 < (int)uVar2) {
          *(undefined1 *)(lVar4 + 4 + WinHvpProcessorToVpIndex) = 1;
        }
        uVar5 = uVar5 + 1;
        lVar7 = lVar7 + 8;
        lVar4 = lVar4 + 8;
      } while (uVar5 < uVar1);
      KeRevertToUserGroupAffinityThread(&local_30);
    }
  }
  return uVar3;
}



===== WinHvpTeardownVpIndexCache @ 1c0010bd0 =====

void WinHvpTeardownVpIndexCache(void)

{
  if (WinHvpProcessorToVpIndex != 0) {
    ExFreePoolWithTag(WinHvpProcessorToVpIndex,0x55764857);
    WinHvpProcessorToVpIndex = 0;
  }
  return;
}



===== entry @ 1c0012010 =====

void entry(void)

{
  __security_init_cookie();
  DriverEntry();
  return;
}



===== __security_init_cookie @ 1c0012044 =====

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



===== DllInitialize @ 1c0012080 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong DllInitialize(undefined2 *param_1)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
                    /* 0x12080  1  DllInitialize */
  __security_init_cookie();
  DAT_1c000d628 = ExAllocatePool2(0x40,*param_1,0x55764857);
  if (DAT_1c000d628 == 0) {
    uVar1 = 0xc000009a;
  }
  else {
    _DAT_1c000d622 = *param_1;
    RtlCopyUnicodeString(&WinHvpRegistryPath,param_1);
    wil_InitializeFeatureStaging();
    uVar2 = WinHvpInitialize();
    uVar1 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) {
      ExFreePoolWithTag(DAT_1c000d628,0x55764857);
      DAT_1c000d628 = 0;
      wil_UninitializeFeatureStaging();
    }
  }
  return uVar1;
}



===== DriverEntry @ 1c0012120 =====

void DriverEntry(void)

{
  code *pcVar1;
  
                    /* 0x12120  3  DriverEntry */
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== WinHvpHypervisorDriverInitialization @ 1c0012130 =====

undefined8 WinHvpHypervisorDriverInitialization(undefined8 param_1)

{
  WinHvpHypervisorDriver = param_1;
  return 0;
}



===== wil_InitializeFeatureStaging @ 1c0012144 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int wil_InitializeFeatureStaging(void)

{
  bool bVar1;
  int iVar2;
  longlong *plVar3;
  undefined8 local_res8;
  
  bVar1 = false;
  if (g_wil_details_isFeatureStagingInitialized == 0) {
    g_wil_details_isFeatureStagingInitialized = 1;
    local_res8 = RtlQueryFeatureConfigurationChangeStamp();
    wil_details_PopulateInitialConfiguredFeatureStates();
    wil_details_EvaluateFeatureDependencies();
    plVar3 = (longlong *)&wil_details_featureDescriptors_z;
    while (plVar3 = wil_details_FeatureDescriptors_SkipPadding(plVar3), plVar3 != (longlong *)0x0) {
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
      plVar3 = plVar3 + 7;
    }
    _g_wil_details_recordFeatureUsage = wil_details_RecordFeatureUsageReporting;
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



===== wil_details_PopulateInitialConfiguredFeatureStates @ 1c0012234 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_PopulateInitialConfiguredFeatureStates(void)

{
  int iVar1;
  longlong *plVar2;
  longlong *plVar3;
  undefined8 uVar4;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  plVar3 = (longlong *)&wil_details_featureDescriptors_z;
  do {
    plVar2 = wil_details_FeatureDescriptors_SkipPadding(plVar3);
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
    plVar3 = plVar2 + 7;
    *(undefined8 *)*plVar2 = local_38;
  } while( true );
}



===== WinHvpBuildNumaMaps @ 1c001231c =====

undefined8 WinHvpBuildNumaMaps(void)

{
  undefined2 uVar1;
  ulonglong uVar2;
  ushort uVar3;
  uint uVar4;
  ulonglong uVar5;
  ushort uVar6;
  undefined8 uVar7;
  uint local_res8 [2];
  
  uVar7 = 0;
  local_res8[0] = 0;
  WinHvpMaximumProcessorCount = KeQueryMaximumProcessorCountEx(0xffff);
  WinHvpProcessorToNode = ExAllocatePool2(0x40,WinHvpMaximumProcessorCount * 2,0x55764857);
  if (WinHvpProcessorToNode == 0) {
    uVar7 = 0xc000009a;
  }
  else {
    memset(&WinHvpNodeToProcessorMask,0,0x400);
    WinHvpNodeCount = 1;
    uVar3 = KeQueryHighestNodeNumber();
    uVar6 = 0;
    WinHvpNodeCount = uVar3 + 1;
    if (WinHvpNodeCount != 0) {
      do {
        KeQueryNodeActiveAffinity(uVar6,&WinHvpNodeToProcessorMask + (ulonglong)uVar6 * 0x10,0);
        uVar5 = *(ulonglong *)(&WinHvpNodeToProcessorMask + (ulonglong)uVar6 * 0x10);
        uVar1 = *(undefined2 *)(&DAT_1c000d0e8 + (ulonglong)uVar6 * 0x10);
        while( true ) {
          uVar2 = 0;
          if (uVar5 != 0) {
            for (; (uVar5 >> uVar2 & 1) == 0; uVar2 = uVar2 + 1) {
            }
          }
          if (uVar5 == 0) break;
          uVar5 = uVar5 ^ 1L << (uVar2 & 0x3f);
          local_res8[0] = (uint)CONCAT12((char)uVar2,uVar1);
          uVar4 = KeGetProcessorIndexFromNumber(local_res8);
          *(ushort *)(WinHvpProcessorToNode + (ulonglong)uVar4 * 2) = uVar6;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < WinHvpNodeCount);
    }
  }
  return uVar7;
}



===== WinHvpTeardownNumaMaps @ 1c0012458 =====

void WinHvpTeardownNumaMaps(void)

{
  if (WinHvpProcessorToNode != 0) {
    ExFreePoolWithTag(WinHvpProcessorToNode,0x55764857);
    WinHvpProcessorToNode = 0;
    WinHvpNodeCount = 0;
  }
  return;
}



===== WinHvpInitialize @ 1c0012494 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong WinHvpInitialize(void)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  ulonglong local_28 [4];
  
  local_28[2] = __security_cookie ^ (ulonglong)auStack_58;
  local_28[0] = 0;
  local_28[1] = 0;
  HviGetHypervisorFeatures(local_28);
  WinHvpCpuManagement = (byte)(local_28[0] >> 0x2c) & 1;
  if ((local_28[0] >> 0x2c & 1) != 0) {
    local_28[0] = 0;
    local_28[1] = 0;
    HviGetEnlightenmentInformation(local_28);
    if ((local_28[0] & 0x1000) == 0) {
      return 0xc0000001;
    }
    WinHvpNested = 1;
    WinHvpCpuManagement = 0;
  }
  _WinHvpOsVersionInfo = 0x11c;
  RtlGetVersion(&WinHvpOsVersionInfo);
  uVar2 = WinHvpBuildNumaMaps();
  uVar4 = uVar2 & 0xffffffff;
  if (-1 < (int)uVar2) {
    uVar1 = WinHvpEnvInit();
    uVar4 = (ulonglong)uVar1;
    if (-1 < (int)uVar1) {
      WinHvpVpDataPages = ExAllocatePool2(0x40,WinHvpMaximumProcessorCount * 0x58,0x55764857);
      if ((WinHvpVpDataPages == 0) ||
         (WinHvpSynicProcessorsBitmap =
               ExAllocatePool2(0x40,(ulonglong)(WinHvpMaximumProcessorCount + 0x1fU >> 5) << 2,
                               0x55764857), WinHvpSynicProcessorsBitmap == 0)) {
        uVar4 = 0xc000009a;
      }
      else {
        _DAT_1c000d668 = 0;
        _DAT_1c000d670 = 0;
        _WinHvpSynicChangeLock = 1;
        KeInitializeEvent(&DAT_1c000d678,1);
        uVar1 = WinHvpInitializeHypercallLookasideBuffer();
        uVar4 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          uVar2 = WinHvpInitializeFallbackHypercallBuffers();
          uVar4 = uVar2 & 0xffffffff;
          if (-1 < (int)uVar2) {
            _DAT_1c000d6a8 = 0;
            _DAT_1c000d6b0 = 0;
            _WinHvpOverlayTableLock = 1;
            KeInitializeEvent(&DAT_1c000d6b8,1);
            local_38 = 0;
            RtlInitializeGenericTable
                      (&WinHvpOverlayTable,WinHvpCompareOverlayTableEntry,
                       WinHvpAllocateOverlayTableEntry,WinHvpFreeOverlayTableEntry);
            uVar3 = HviIsAnyHypervisorPresent();
            if ((char)uVar3 != '\0') {
              uVar2 = WinHvpConnectToHypervisor();
              uVar4 = uVar2 & 0xffffffff;
              if (-1 < (int)uVar2) {
                uVar1 = WinHvpEnableIsolation();
                uVar4 = (ulonglong)uVar1;
                if (-1 < (int)uVar1) {
                  uVar2 = WinHvpBuildVpIndexCache();
                  uVar4 = uVar2 & 0xffffffff;
                  if (-1 < (int)uVar2) {
                    WinHvpConnectToSynic('\0');
                    WinHvpDllLoadSuccessful = 1;
                    return 0;
                  }
                }
              }
              if ((int)uVar4 < 0) goto LAB_1c00126a0;
            }
            WinHvpDllLoadSuccessful = 1;
            return 0;
          }
        }
        WinHvpCleanupHypercallSupport();
      }
    }
  }
LAB_1c00126a0:
  WinHvpTeardownVpIndexCache();
  WinHvpCleanupSynicSupport();
  WinHvpCleanupHypercallSupport();
  WinHvpCleanupIsolation();
  WinHvpDisconnectFromHypervisor();
  WinHvpFreeAllVpDataPages();
  WinHvpTeardownNumaMaps();
  WinHvpEnvUninit();
  return uVar4;
}


