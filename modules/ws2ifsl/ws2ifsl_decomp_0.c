
===== __report_gsfailure @ 140001010 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 14000101d =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000101d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== DispatchPnP @ 140001030 =====

ulonglong DispatchPnP(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  if ((*(char *)(lVar1 + 1) == '\a') && (*(int *)(lVar1 + 8) == 4)) {
    if (**(int **)(*(longlong *)(lVar1 + 0x30) + 0x18) == 0x6b636f53) {
      uVar2 = SocketPnPTargetQuery(*(longlong *)(lVar1 + 0x30),param_2);
      uVar2 = uVar2 & 0xffffffff;
    }
    else {
      uVar2 = 0xc0000010;
    }
    if ((int)uVar2 == 0x103) {
      return uVar2;
    }
  }
  else {
    uVar2 = 0xc0000010;
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(int *)(param_2 + 0x30) = (int)uVar2;
  IofCompleteRequest(param_2,0);
  return uVar2;
}



===== wil_details_RecordCachedUsage @ 1400010ac =====

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



===== wil_details_RecordFeatureUsageReporting @ 140001200 =====

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



===== DereferenceProcessContext @ 140001284 =====

void DereferenceProcessContext(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  code *pcVar3;
  
  LOCK();
  plVar1 = (longlong *)(param_1 + 0x108);
  lVar2 = *plVar1;
  *plVar1 = *plVar1 + -1;
  UNLOCK();
  if (lVar2 < 2) {
    if (lVar2 == 1) {
      ExFreePoolWithTag(param_1,0x70327357);
    }
    else {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(0xe);
    }
  }
  return;
}



===== CancelQueueKernelRoutine @ 1400012d0 =====

void CancelQueueKernelRoutine(longlong param_1)

{
  DereferenceProcessContext(param_1 + -0xa8);
  return;
}



===== CancelRundownRoutine @ 1400012f0 =====

void CancelRundownRoutine(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined1 uVar5;
  undefined1 *puVar6;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + -8);
  puVar6 = auStack_28;
  *(undefined1 *)(param_1 + -0x10) = 0;
  do {
    plVar1 = *(longlong **)(param_1 + -0x20);
    if (plVar1 == (longlong *)(param_1 + -0x20)) {
LAB_140001352:
      *(undefined8 *)(puVar6 + -8) = 0x140001360;
      KeReleaseSpinLock(param_1 + -8,uVar5);
      *(undefined8 *)(puVar6 + -8) = 0x140001371;
      DereferenceProcessContext(param_1 + -0xa8);
      return;
    }
    lVar2 = *plVar1;
    if ((*(longlong **)(lVar2 + 8) != plVar1) ||
       (plVar3 = (longlong *)plVar1[1], (longlong *)*plVar3 != plVar1)) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      puVar6 = auStack_20;
      goto LAB_140001352;
    }
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    *plVar1 = 0;
    FreeSocketCancel((longlong)plVar1);
  } while( true );
}



===== CleanupQueuedRequests @ 140001390 =====

void CleanupQueuedRequests(longlong param_1,longlong param_2,longlong param_3)

{
  longlong *plVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined1 uVar5;
  longlong *plVar6;
  
  uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x28);
  plVar1 = *(longlong **)(param_1 + 0x10);
  while( true ) {
    do {
      plVar6 = plVar1;
      if (plVar6 == (longlong *)(param_1 + 0x10)) {
        KeReleaseSpinLock(param_1 + 0x28,uVar5);
        return;
      }
      plVar1 = (longlong *)*plVar6;
    } while (*(longlong *)(plVar6[2] + 0x30) != param_2);
    if (((longlong *)plVar1[1] != plVar6) ||
       (puVar2 = (undefined8 *)plVar6[1], (longlong *)*puVar2 != plVar6)) break;
    *puVar2 = plVar1;
    plVar1[1] = (longlong)puVar2;
    plVar6[-5] = 0;
    plVar3 = *(longlong **)(param_3 + 8);
    if (*plVar3 != param_3) break;
    *plVar6 = param_3;
    plVar6[1] = (longlong)plVar3;
    *plVar3 = (longlong)plVar6;
    *(longlong **)(param_3 + 8) = plVar6;
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3,plVar6,plVar6);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== DequeueCancel @ 140001448 =====

longlong * DequeueCancel(longlong param_1,int param_2,undefined1 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined1 uVar5;
  longlong *plVar6;
  undefined1 *puVar7;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  plVar1 = (longlong *)(param_1 + 0x88);
  uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 0xa0);
  plVar6 = (longlong *)*plVar1;
  puVar7 = auStack_38;
  if ((plVar6 != plVar1) && (puVar7 = auStack_38, (int)plVar6[3] == param_2)) {
    lVar2 = *plVar6;
    if ((*(longlong **)(lVar2 + 8) == plVar6) &&
       (plVar3 = (longlong *)plVar6[1], (longlong *)*plVar3 == plVar6)) {
      *plVar3 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar3;
      *plVar6 = 0;
      puVar7 = auStack_38;
      goto LAB_1400014bc;
    }
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)(3);
    puVar7 = auStack_30;
  }
  plVar6 = (longlong *)0x0;
LAB_1400014bc:
  if ((longlong *)*plVar1 == plVar1) {
    *(undefined1 *)(param_1 + 0x98) = 0;
  }
  else {
    *(undefined8 *)(puVar7 + -8) = 0x1400014cf;
    SignalCancel(param_1);
  }
  *param_3 = *(undefined1 *)(param_1 + 0x98);
  *(undefined8 *)(puVar7 + -8) = 0x1400014e3;
  KeReleaseSpinLock(param_1 + 0xa0,uVar5);
  return plVar6;
}



===== DequeueRequest @ 140001514 =====

longlong DequeueRequest(longlong param_1,uint param_2,undefined1 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined1 uVar6;
  undefined1 *puVar7;
  longlong lVar8;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  plVar1 = (longlong *)(param_1 + 0x10);
  uVar6 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x28);
  plVar2 = (longlong *)*plVar1;
  lVar8 = (longlong)(plVar2 + -0x15);
  puVar7 = auStack_38;
  if ((plVar2 != plVar1) && (puVar7 = auStack_38, plVar2[-6] == (ulonglong)param_2)) {
    lVar3 = *plVar2;
    if (((longlong *)*(longlong *)(lVar3 + 8) == plVar2) &&
       (plVar4 = (longlong *)plVar2[1], (longlong *)*plVar4 == plVar2)) {
      *plVar4 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar4;
      plVar2[-5] = 0;
      puVar7 = auStack_38;
      goto LAB_140001591;
    }
    pcVar5 = (code *)swi(0x29);
    (*pcVar5)(3);
    puVar7 = auStack_30;
  }
  lVar8 = 0;
LAB_140001591:
  if ((longlong *)*plVar1 == plVar1) {
    *(undefined1 *)(param_1 + 0x20) = 0;
  }
  else {
    *(undefined8 *)(puVar7 + -8) = 0x1400015a4;
    SignalRequest(param_1);
  }
  *param_3 = *(undefined1 *)(param_1 + 0x20);
  *(undefined8 *)(puVar7 + -8) = 0x1400015b8;
  KeReleaseSpinLock(param_1 + 0x28,uVar6);
  return lVar8;
}



===== Feature_TCPIP_2025_Wave2_Ws2ifsl__private_IsEnabledDeviceUsageNoInline @ 1400015e8 =====

ulonglong Feature_TCPIP_2025_Wave2_Ws2ifsl__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  undefined8 *local_res8;
  
  local_res8 = (undefined8 *)(ulonglong)(uint)Feature_TCPIP_2025_Wave2_Ws2ifsl__private_featureState
  ;
  if (((uint)Feature_TCPIP_2025_Wave2_Ws2ifsl__private_featureState & 0x10) == 0) {
    uVar1 = Feature_TCPIP_2025_Wave2_Ws2ifsl__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)((uint)Feature_TCPIP_2025_Wave2_Ws2ifsl__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_TCPIP_2025_Wave2_Ws2ifsl__private_IsEnabledFallback @ 140001620 =====

void Feature_TCPIP_2025_Wave2_Ws2ifsl__private_IsEnabledFallback(undefined8 *param_1,uint param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2);
  return;
}



===== FlushRequestQueue @ 140001638 =====

void FlushRequestQueue(longlong *param_1)

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
    lVar2 = *plVar1;
    if ((*(longlong **)(lVar2 + 8) != plVar1) ||
       (plVar3 = (longlong *)plVar1[1], (longlong *)*plVar3 != plVar1)) break;
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    plVar1[-5] = 0;
    KeReleaseSpinLockFromDpcLevel(param_1 + 3);
    plVar1[-0xe] = 0;
    *(undefined4 *)(plVar1 + -0xf) = 0xc0000120;
    CompleteSocketIrp((longlong)(plVar1 + -0x15));
    KeAcquireSpinLockAtDpcLevel(param_1 + 3);
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  return;
}



===== _guard_check_icall @ 1400016d0 =====

void _guard_check_icall(void)

{
  return;
}



===== QueueRequest @ 1400016dc =====

undefined1 QueueRequest(longlong param_1,longlong param_2)

{
  longlong lVar1;
  code *pcVar2;
  undefined1 uVar3;
  longlong *plVar4;
  longlong *plVar5;
  undefined1 *puVar6;
  undefined1 uVar7;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  lVar1 = param_1 + 0x10;
  LOCK();
  *(code **)(param_2 + 0x68) = QueuedCancelRoutine;
  UNLOCK();
  uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x28);
  puVar6 = auStack_38;
  uVar7 = 0;
  if (*(char *)(param_2 + 0x44) == '\0') {
    plVar4 = *(longlong **)(param_1 + 0x18);
    plVar5 = (longlong *)(param_2 + 0xa8);
    puVar6 = auStack_38;
    if (*plVar4 != lVar1) {
      plVar4 = (longlong *)0x3;
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)();
      puVar6 = auStack_30;
    }
    *plVar5 = lVar1;
    plVar5[1] = (longlong)plVar4;
    *plVar4 = (longlong)plVar5;
    *(longlong **)(param_1 + 0x18) = plVar5;
    *(longlong *)(param_2 + 0x80) = lVar1;
    if (*(char *)(param_1 + 0x20) == '\0') {
      *(undefined8 *)(puVar6 + -8) = 0x14000175f;
      SignalRequest(param_1);
    }
    uVar7 = 1;
  }
  *(undefined8 *)(puVar6 + -8) = 0x140001770;
  KeReleaseSpinLock(param_1 + 0x28,uVar3);
  return uVar7;
}



===== QueuedCancelRoutine @ 1400017a0 =====

void QueuedCancelRoutine(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  undefined1 uVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined1 *puVar6;
  longlong lVar7;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  lVar7 = *(longlong *)
           (*(longlong *)
             (*(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x18) + 0x10) +
           0x18) + 0x28;
  KeAcquireSpinLockAtDpcLevel(lVar7);
  puVar6 = auStack_28;
  if (*(longlong *)(param_2 + 0x80) != 0) {
    plVar1 = (longlong *)(param_2 + 0xa8);
    lVar3 = *plVar1;
    if ((*(longlong **)(lVar3 + 8) == plVar1) &&
       (plVar4 = *(longlong **)(param_2 + 0xb0), (longlong *)*plVar4 == plVar1)) {
      *plVar4 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar4;
      *(undefined8 *)(param_2 + 0x80) = 0;
      KeReleaseSpinLockFromDpcLevel(lVar7);
      IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
      *(undefined8 *)(param_2 + 0x38) = 0;
      *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
      CompleteSocketIrp(param_2);
      return;
    }
    pcVar5 = (code *)swi(0x29);
    (*pcVar5)(3);
    puVar6 = auStack_20;
  }
  *(undefined8 *)(puVar6 + -8) = 0x14000184e;
  KeReleaseSpinLockFromDpcLevel(lVar7);
  uVar2 = *(undefined1 *)(param_2 + 0x45);
  *(undefined8 *)(puVar6 + -8) = 0x14000185d;
  IoReleaseCancelSpinLock(uVar2);
  return;
}



===== RemoveQueuedCancel @ 140001874 =====

undefined1 RemoveQueuedCancel(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined1 uVar4;
  undefined1 *puVar5;
  undefined1 uVar6;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0xa0);
  puVar5 = auStack_28;
  lVar1 = *param_2;
  if (lVar1 != 0) {
    uVar6 = 1;
    if ((*(longlong **)(lVar1 + 8) == param_2) &&
       (plVar2 = (longlong *)param_2[1], (longlong *)*plVar2 == param_2)) {
      *plVar2 = lVar1;
      *(longlong **)(lVar1 + 8) = plVar2;
      *param_2 = 0;
      puVar5 = auStack_28;
      goto LAB_1400018cd;
    }
    pcVar3 = (code *)swi(0x29);
    uVar4 = (*pcVar3)(3);
    puVar5 = auStack_20;
  }
  uVar6 = 0;
LAB_1400018cd:
  *(undefined8 *)(puVar5 + -8) = 0x1400018d9;
  KeReleaseSpinLock(param_1 + 0xa0,uVar4);
  return uVar6;
}



===== RequestQueueKernelRoutine @ 140001900 =====

void RequestQueueKernelRoutine(longlong param_1)

{
  DereferenceProcessContext(param_1 + -0x30);
  return;
}



===== RequestRundownRoutine @ 140001920 =====

void RequestRundownRoutine(longlong param_1)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + -8);
  *(undefined1 *)(param_1 + -0x10) = 0;
  FlushRequestQueue((longlong *)(param_1 + -0x20));
  KeReleaseSpinLock(param_1 + -8,uVar1);
  DereferenceProcessContext(param_1 + -0x30);
  return;
}



===== SignalCancel @ 140001984 =====

void SignalCancel(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  longlong *plVar6;
  code *pcVar7;
  char cVar8;
  longlong lVar9;
  undefined1 *puVar10;
  longlong lVar11;
  undefined8 uStack_30;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  puVar10 = auStack_28;
  *(undefined1 *)(param_1 + 0x98) = 1;
  plVar1 = (longlong *)(param_1 + 0x88);
  lVar9 = *plVar1;
  lVar11 = *(longlong *)(*(longlong *)(lVar9 + 0x10) + 0x18);
  LOCK();
  plVar2 = (longlong *)(param_1 + 0x108);
  lVar3 = *plVar2;
  *plVar2 = *plVar2 + 1;
  UNLOCK();
  if (lVar3 + 1 < 2) {
    pcVar7 = (code *)swi(0x29);
    (*pcVar7)(0xe);
    puVar10 = auStack_20;
  }
  uVar4 = *(undefined4 *)(lVar9 + 0x18);
  uVar5 = *(undefined8 *)(lVar11 + 8);
  *(undefined8 *)(puVar10 + -8) = 0x1400019e3;
  cVar8 = KeInsertQueueApc(param_1 + 0xa8,uVar4,uVar5,2);
  if (cVar8 == '\0') {
    while (plVar2 = (longlong *)*plVar1, plVar2 != plVar1) {
      lVar3 = *plVar2;
      if ((*(longlong **)(lVar3 + 8) != plVar2) ||
         (plVar6 = (longlong *)plVar2[1], (longlong *)*plVar6 != plVar2)) {
        pcVar7 = (code *)swi(0x29);
        (*pcVar7)(3);
        puVar10 = puVar10 + 8;
        break;
      }
      *plVar6 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar6;
      *plVar2 = 0;
      *(undefined8 *)(puVar10 + -8) = 0x140001a16;
      FreeSocketCancel((longlong)plVar2);
    }
    *(undefined8 *)(puVar10 + -8) = 0x140001a27;
    DereferenceProcessContext(param_1);
  }
  return;
}



===== SignalRequest @ 140001a3c =====

void SignalRequest(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  int iVar3;
  char *pcVar4;
  undefined8 uVar5;
  code *pcVar6;
  char cVar7;
  ulonglong uVar8;
  undefined1 *puVar9;
  longlong lVar10;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  puVar9 = auStack_28;
  lVar10 = *(longlong *)(param_1 + 0x10);
  pcVar4 = *(char **)(lVar10 + 0x10);
  cVar7 = *pcVar4;
  if ((cVar7 != '\x03') && (cVar7 != '\x04')) {
    if (cVar7 != '\x0e') {
      if (cVar7 != '\x1b') {
        return;
      }
      uVar8 = 8;
      goto LAB_140001aa1;
    }
    iVar3 = *(int *)(pcVar4 + 0x18);
    if (iVar3 != 0x12017) {
      if ((iVar3 != 0x1201b) && (iVar3 != 0x12023)) {
        return;
      }
      uVar8 = (ulonglong)((*(int *)(pcVar4 + 8) + 1U & 0xfffffffe) + *(int *)(pcVar4 + 0x10));
      goto LAB_140001aa1;
    }
  }
  uVar8 = (ulonglong)*(uint *)(pcVar4 + 8);
LAB_140001aa1:
  LOCK();
  plVar1 = (longlong *)(param_1 + 0x108);
  lVar2 = *plVar1;
  *plVar1 = *plVar1 + 1;
  UNLOCK();
  if (lVar2 + 1 < 2) {
    pcVar6 = (code *)swi(0x29);
    (*pcVar6)(0xe);
    puVar9 = auStack_20;
  }
  uVar5 = *(undefined8 *)(lVar10 + -0x30);
  *(undefined8 *)(puVar9 + -8) = 0x140001ad7;
  cVar7 = KeInsertQueueApc(param_1 + 0x30,uVar5,uVar8 & 0xffffffff,2);
  if (cVar7 == '\0') {
    *(undefined8 *)(puVar9 + -8) = 0x140001aef;
    FlushRequestQueue((longlong *)(param_1 + 0x10));
    *(undefined8 *)(puVar9 + -8) = 0x140001af7;
    DereferenceProcessContext(param_1);
  }
  else {
    *(undefined1 *)(param_1 + 0x20) = 1;
  }
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 140001b0c =====

uint * wil_details_FeatureReporting_RecordUsageInCache
                 (uint *param_1,uint *param_2,uint param_3,uint param_4)

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
LAB_140001d15:
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
      uVar3 = uVar5 + 1;
      if ((0x1ff < uVar3) || (uVar3 < uVar5)) {
        uVar3 = 1;
        param_1[2] = param_3;
        param_1[1] = uVar5;
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
LAB_140001be7:
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
      if (param_3 == 4) goto LAB_140001d15;
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
          param_1[2] = param_3;
          param_1[1] = 1;
          param_1[3] = param_4;
          return param_1;
        }
        goto LAB_140001be7;
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
      uVar3 = uVar5 + 1;
      if ((0x7f < uVar3) || (uVar3 < uVar5)) {
        uVar3 = 1;
        param_1[2] = param_3;
        param_1[1] = uVar5;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 140001e00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (undefined8 param_1,ulonglong param_2,uint param_3)

{
  bool bVar1;
  undefined7 extraout_var;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  byte bVar5;
  uint local_res18 [4];
  
  uVar4 = (uint)param_2 & 1;
  uVar3 = (ulonglong)param_3;
  if (param_3 != 0) {
    if (param_3 == 1) {
      uVar2 = (uVar4 ^ 1) << 2;
      uVar3 = 0;
      goto LAB_140001ec3;
    }
    if (param_3 == 2) {
      uVar2 = (uVar4 ^ 1) * 4 + 1;
      uVar3 = 0;
      goto LAB_140001ec3;
    }
    if (param_3 == 3) {
      uVar2 = (uVar4 ^ 1) * 4 + 2;
      uVar3 = 0;
      goto LAB_140001ec3;
    }
    if (param_3 == 4) {
      uVar2 = (uVar4 ^ 1) * 4 + 3;
      uVar3 = 0;
      goto LAB_140001ec3;
    }
    uVar2 = param_3 - 5;
    uVar3 = (ulonglong)uVar2;
    if (uVar2 == 0) {
      uVar2 = (uVar4 ^ 1) * 2 + 8;
      goto LAB_140001ec3;
    }
    if (uVar2 == 1) {
      uVar2 = (uVar4 ^ 1) * 2 + 9;
      goto LAB_140001ec3;
    }
    bVar5 = (char)param_3 + 0x9c;
    if (bVar5 < 0x32) {
      uVar2 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar5;
      goto LAB_140001ec3;
    }
  }
  uVar2 = 0xff;
LAB_140001ec3:
  local_res18[0] = param_3;
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(uVar3,param_2,uVar2);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (0x2f3ddcf,&Feature_TCPIP_2025_Wave2_Ws2ifsl_logged_traits,0,uVar4,local_res18,0,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140001f1c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (undefined8 param_1,undefined8 param_2,uint param_3)

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
                     (local_50,&Feature_TCPIP_2025_Wave2_Ws2ifsl__private_reporting,param_3,
                      (uint)((ulonglong)param_2 >> 0x20));
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_68 = &local_38;
    (*g_wil_details_recordFeatureUsage)
              (0x2f3ddcf,param_3,1,&Feature_TCPIP_2025_Wave2_Ws2ifsl__private_reporting);
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && (param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)param_3,0x2f3ddcf);
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 140002008 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                    (uint *param_1,ulonglong param_2,longlong param_3)

{
  undefined8 *puVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  uint uVar8;
  uint uVar9;
  longlong *plVar10;
  uint uVar11;
  bool bVar12;
  bool bVar13;
  undefined1 auStack_a8 [32];
  undefined8 local_88;
  ulonglong local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined4 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_a8;
  iVar3 = 0;
  local_88 = param_2;
  if (g_wil_details_ensureSubscribedToFeatureConfigurationChanges != (code *)0x0) {
    iVar3 = (*g_wil_details_ensureSubscribedToFeatureConfigurationChanges)();
  }
  local_70 = 0;
  uStack_68 = 0;
  local_78 = 0;
  bVar2 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  iVar4 = RtlQueryFeatureConfiguration
                    (*(undefined4 *)(param_3 + 0x18),1 < (byte)(*(char *)(param_3 + 0x1c) - 2U),
                     &local_78,&local_58);
  if (iVar4 == 0) {
    bVar2 = 1;
    uVar8 = local_58._4_4_ >> 7 & 1;
    local_70 = CONCAT44(local_70._4_4_,local_58._4_4_ >> 4) & 0xffffffff00000003;
    uVar5 = local_58._4_4_ >> 6 & 1;
    uVar11 = local_58._4_4_ >> 4 & 3;
LAB_1400020bb:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_1400020e9;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_1400020bb;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_1400020e9:
  uVar6 = -(uint)bVar2 & uVar11 & 3;
  if (uVar6 == 0) {
    uVar9 = -(uint)(*(char *)(param_3 + 0x1f) != '\0') & 0x40;
  }
  else {
    uVar9 = 0;
    if (uVar11 == 2) {
      uVar9 = 0x40;
    }
  }
  uVar11 = uVar9 >> 6 ^ (uVar9 | uVar6 << 7 | uVar8 | uVar5);
  if ((uVar9 != 0) && (plVar10 = *(longlong **)(param_3 + 0x20), plVar10 != (longlong *)0x0)) {
    do {
      puVar1 = (undefined8 *)*plVar10;
      if (puVar1 == (undefined8 *)0x0) break;
      if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
         (*(char *)((longlong)puVar1 + 0x1d) == '\0')) {
        uVar8 = *(uint *)*puVar1;
        local_80 = (ulonglong)uVar8;
        if ((uVar8 & 2) == 0) {
          uVar7 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            ((uint *)*puVar1,local_80,(longlong)puVar1);
          uVar8 = (uint)uVar7;
        }
        uVar5 = uVar11 & 0xfffffffe;
        uVar11 = (uint)((uVar8 & uVar11 & 1) != 0);
      }
      else {
        if (((uVar11 & 1) == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
        }
        else {
          uVar5 = 1;
        }
        uVar11 = uVar11 & 0xfffffffe;
      }
      uVar11 = uVar11 | uVar5;
      plVar10 = plVar10 + 1;
    } while ((uVar11 & 1) != 0);
  }
  bVar12 = *(char *)(param_3 + 0x1c) == '\0';
  uVar7 = param_2 & 0xffffffff;
  while( true ) {
    uVar5 = (uint)uVar7;
    local_88 = CONCAT44(local_88._4_4_,uVar5);
    if ((!bVar12 || iVar3 != 0) && (local_88 = CONCAT44(local_88._4_4_,uVar5), (uVar7 & 2) == 0)) {
      uVar8 = (uVar11 ^ uVar5) & 0x9c1 ^ uVar5;
      uVar5 = uVar8 | 2;
      local_88 = CONCAT44(local_88._4_4_,uVar8) | 2;
    }
    if ((param_2 & 4) == 0) {
      uVar8 = (uVar5 ^ uVar11) & 0x400 ^ uVar5;
      uVar5 = uVar8 | 4;
      local_88 = CONCAT44(local_88._4_4_,uVar8) | 4;
    }
    uVar7 = param_2 & 0xffffffff;
    LOCK();
    uVar8 = *param_1;
    bVar13 = (uint)param_2 == uVar8;
    if (bVar13) {
      *param_1 = uVar5;
    }
    else {
      uVar7 = (ulonglong)uVar8;
    }
    UNLOCK();
    if (bVar13) break;
    param_2 = uVar7;
  }
  if (((param_2 & 4) == 0) &&
     (g_wil_details_subscribeFeatureStateCacheToConfigurationChanges != (code *)0x0)) {
    (*g_wil_details_subscribeFeatureStateCacheToConfigurationChanges)
              (param_1,*(undefined1 *)(param_3 + 0x1c),iVar3);
  }
  if (bVar12 && iVar3 == 0) {
    local_88 = CONCAT44(local_88._4_4_,(uVar11 ^ uVar5) & 0x9c1 ^ uVar5);
  }
  return local_88;
}



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140002274 =====

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
  if (((uint)Feature_TCPIP_2025_Wave2_Ws2ifsl__private_featureState & 2) != 0) {
    uVar1 = (uint)Feature_TCPIP_2025_Wave2_Ws2ifsl__private_featureState;
    while ((uVar1 & 1) == (param_1 & 1)) {
      LOCK();
      bVar3 = uVar1 == (uint)Feature_TCPIP_2025_Wave2_Ws2ifsl__private_featureState;
      if (bVar3) {
        Feature_TCPIP_2025_Wave2_Ws2ifsl__private_featureState._0_4_ = uVar2 | uVar1;
      }
      else {
        uVar1 = (uint)Feature_TCPIP_2025_Wave2_Ws2ifsl__private_featureState;
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



===== wil_details_IsEnabledFallback @ 1400022c8 =====

uint wil_details_IsEnabledFallback(undefined8 *param_1,uint param_2)

{
  undefined8 *puVar1;
  ulonglong local_res18;
  
  local_res18 = (ulonglong)param_1 & 0xffffffff;
  if (((ulonglong)param_1 & 2) == 0) {
    puVar1 = &Feature_TCPIP_2025_Wave2_Ws2ifsl__private_featureState;
    local_res18 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            ((uint *)&Feature_TCPIP_2025_Wave2_Ws2ifsl__private_featureState,
                             (ulonglong)param_1,0x140004ac8);
    param_1 = puVar1;
    puVar1 = (undefined8 *)(local_res18 & 0xffffffff);
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



===== CancelSocketIo @ 140002358 =====

void CancelSocketIo(longlong param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  code *pcVar6;
  undefined1 uVar7;
  longlong lVar8;
  longlong *plVar9;
  undefined1 *puVar10;
  bool bVar11;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  longlong local_28;
  
  lVar3 = *(longlong *)(param_1 + 0x18);
  lVar4 = *(longlong *)(*(longlong *)(lVar3 + 0x10) + 0x18);
  lVar8 = ExAllocatePool2(0x61,0x20,0x43327357);
  if (lVar8 != 0) {
    local_28 = lVar8;
    ObfReferenceObject(param_1);
    *(longlong *)(lVar8 + 0x10) = param_1;
    LOCK();
    piVar1 = (int *)(lVar4 + 0x100);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    *(int *)(local_28 + 0x18) = iVar2 + 1;
    plVar9 = (longlong *)(lVar3 + 0x38);
    LOCK();
    bVar11 = *plVar9 == 0;
    if (bVar11) {
      *plVar9 = local_28;
    }
    UNLOCK();
    if (bVar11) {
      uVar7 = KeAcquireSpinLockRaiseToDpc(lVar4 + 0xa0);
      puVar10 = auStack_48;
      plVar9 = *(longlong **)(lVar4 + 0x90);
      if (*plVar9 != lVar4 + 0x88) {
        plVar9 = (longlong *)0x3;
        pcVar6 = (code *)swi(0x29);
        (*pcVar6)();
        puVar10 = auStack_40;
      }
      plVar5 = *(longlong **)(puVar10 + 0x20);
      *plVar5 = lVar4 + 0x88;
      plVar5[1] = (longlong)plVar9;
      *plVar9 = (longlong)plVar5;
      *(longlong **)(lVar4 + 0x90) = plVar5;
      if (*(char *)(lVar4 + 0x98) == '\0') {
        *(undefined8 *)(puVar10 + -8) = 0x140002445;
        SignalCancel(lVar4);
      }
      *(undefined8 *)(puVar10 + -8) = 0x140002453;
      KeReleaseSpinLock(lVar4 + 0xa0,uVar7);
    }
    else {
      ObfDereferenceObject(param_1);
      ExFreePoolWithTag(local_28,0);
    }
  }
  return;
}



===== CleanupProcessedRequests @ 140002494 =====

void CleanupProcessedRequests(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined1 uVar5;
  longlong *plVar6;
  undefined1 *puVar7;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x30);
  puVar7 = auStack_28;
  plVar6 = (longlong *)(param_1 + 0x20);
  do {
    plVar1 = (longlong *)*plVar6;
    if (plVar1 == plVar6) {
LAB_140002505:
      *(undefined8 *)(puVar7 + -8) = 0x14000250f;
      KeReleaseSpinLock(param_1 + 0x30);
      return;
    }
    if (((longlong *)plVar1[1] != plVar6) ||
       (lVar2 = *plVar1, (longlong *)*(longlong *)(lVar2 + 8) != plVar1)) {
LAB_1400024fe:
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3,uVar5);
      puVar7 = auStack_20;
      goto LAB_140002505;
    }
    *plVar6 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar6;
    plVar1[-5] = 0;
    plVar3 = *(longlong **)(param_2 + 8);
    if (*plVar3 != param_2) goto LAB_1400024fe;
    *plVar1 = param_2;
    plVar1[1] = (longlong)plVar3;
    *plVar3 = (longlong)plVar1;
    *(longlong **)(param_2 + 8) = plVar1;
  } while( true );
}



===== CompleteSocketIrp @ 14000252c =====

void CompleteSocketIrp(longlong param_1)

{
  longlong lVar1;
  undefined1 local_res8 [32];
  
  LOCK();
  lVar1 = *(longlong *)(param_1 + 0x68);
  *(longlong *)(param_1 + 0x68) = 0;
  UNLOCK();
  if (lVar1 == 0) {
    local_res8[0] = 0;
    IoAcquireCancelSpinLock(local_res8);
    IoReleaseCancelSpinLock(local_res8[0]);
  }
  if (*(longlong *)(param_1 + 8) != 0) {
    if ((*(byte *)(*(longlong *)(param_1 + 8) + 10) & 2) != 0) {
      MmUnlockPages();
    }
    IoFreeMdl(*(undefined8 *)(param_1 + 8));
    *(undefined8 *)(param_1 + 8) = 0;
  }
  IofCompleteRequest(param_1,0);
  return;
}



===== CompleteTargetQuery @ 1400025c0 =====

undefined8 CompleteTargetQuery(undefined8 param_1,longlong param_2,longlong param_3)

{
  byte *pbVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  lVar2 = *(longlong *)(param_3 + 0xb8);
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  ObfDereferenceObject(*(undefined8 *)(lVar2 + 0x30));
  uVar3 = *(undefined4 *)(param_2 + 0x34);
  uVar4 = *(undefined4 *)(param_2 + 0x38);
  uVar5 = *(undefined4 *)(param_2 + 0x3c);
  *(undefined4 *)(param_3 + 0x30) = *(undefined4 *)(param_2 + 0x30);
  *(undefined4 *)(param_3 + 0x34) = uVar3;
  *(undefined4 *)(param_3 + 0x38) = uVar4;
  *(undefined4 *)(param_3 + 0x3c) = uVar5;
  IoFreeIrp(param_2);
  CompleteSocketIrp(param_3);
  return 0xc0000016;
}



===== FreeSocketCancel @ 140002630 =====

void FreeSocketCancel(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar2 = *(longlong *)(param_1 + 0x10);
  lVar3 = *(longlong *)(lVar2 + 0x18);
  *(undefined8 *)(param_1 + 0x10) = 0;
  plVar1 = (longlong *)(lVar3 + 0x38);
  LOCK();
  lVar3 = *plVar1;
  if (param_1 == lVar3) {
    *plVar1 = 0;
    lVar3 = param_1;
  }
  else {
  }
  UNLOCK();
  if (lVar3 != 0) {
    ExFreePoolWithTag(param_1,0);
  }
  ObfDereferenceObject(lVar2);
  return;
}



===== GetProcessedRequest @ 140002680 =====

undefined8 * GetProcessedRequest(longlong param_1,ulonglong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  code *pcVar3;
  undefined8 *puVar4;
  undefined1 uVar5;
  undefined8 *puVar6;
  
  lVar1 = param_1 + 0x30;
  uVar5 = KeAcquireSpinLockRaiseToDpc(lVar1);
  puVar6 = *(undefined8 **)(param_1 + 0x20);
  do {
    puVar4 = puVar6;
    if (puVar4 == (undefined8 *)(param_1 + 0x20)) {
      KeReleaseSpinLock(lVar1,uVar5);
      return (undefined8 *)0x0;
    }
    puVar6 = (undefined8 *)*puVar4;
  } while (puVar4[-6] != (param_2 & 0xffffffff));
  if (((undefined8 *)puVar6[1] == puVar4) &&
     (puVar2 = (undefined8 *)puVar4[1], (undefined8 *)*puVar2 == puVar4)) {
    *puVar2 = puVar6;
    puVar6[1] = puVar2;
    puVar4[-5] = 0;
    KeReleaseSpinLock(lVar1,CONCAT71((int7)((ulonglong)puVar2 >> 8),uVar5));
    return puVar4 + -0x15;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  puVar6 = (undefined8 *)(*pcVar3)();
  return puVar6;
}



===== GetSocketProcessReference @ 140002734 =====

undefined8 GetSocketProcessReference(longlong param_1)

{
  undefined8 uVar1;
  undefined1 uVar2;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x30);
  ObfReferenceObject(*(undefined8 *)(param_1 + 0x10));
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  KeReleaseSpinLock(param_1 + 0x30,uVar2);
  return uVar1;
}



===== InsertProcessedRequest @ 14000279c =====

ulonglong InsertProcessedRequest(longlong param_1,longlong param_2)

{
  longlong lVar1;
  code *pcVar2;
  undefined1 uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  longlong lVar6;
  longlong *plVar7;
  undefined1 *puVar8;
  longlong *plVar9;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  lVar1 = param_1 + 0x30;
  LOCK();
  *(code **)(param_2 + 0x68) = ProcessedCancelRoutine;
  UNLOCK();
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
  puVar8 = auStack_28;
  if (*(char *)(param_2 + 0x44) == '\0') {
    lVar6 = param_1 + 0x20;
    plVar9 = *(longlong **)(param_1 + 0x28);
    plVar7 = (longlong *)(param_2 + 0xa8);
    if (*plVar9 != lVar6) {
      lVar6 = 3;
      pcVar2 = (code *)swi(0x29);
      uVar3 = (*pcVar2)();
      puVar8 = auStack_20;
    }
    *plVar7 = lVar6;
    plVar7[1] = (longlong)plVar9;
    *plVar9 = (longlong)plVar7;
    *(longlong **)(lVar6 + 8) = plVar7;
    *(longlong *)(param_2 + 0x80) = lVar6;
    *(undefined8 *)(puVar8 + -8) = 0x140002811;
    uVar4 = KeReleaseSpinLock(lVar1,uVar3);
    uVar5 = CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
  }
  else {
    uVar5 = KeReleaseSpinLock(lVar1,uVar3);
    uVar5 = uVar5 & 0xffffffffffffff00;
  }
  return uVar5;
}



===== ProcessedCancelRoutine @ 140002850 =====

void ProcessedCancelRoutine(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  undefined1 uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  code *pcVar6;
  undefined1 *puVar7;
  longlong lVar8;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  lVar3 = *(longlong *)(param_2 + 0xb8);
  lVar8 = *(longlong *)(*(longlong *)(lVar3 + 0x30) + 0x18) + 0x30;
  KeAcquireSpinLockAtDpcLevel(lVar8);
  puVar7 = auStack_28;
  if (*(longlong *)(param_2 + 0x80) != 0) {
    plVar1 = (longlong *)(param_2 + 0xa8);
    lVar4 = *plVar1;
    if ((*(longlong **)(lVar4 + 8) == plVar1) &&
       (plVar5 = *(longlong **)(param_2 + 0xb0), (longlong *)*plVar5 == plVar1)) {
      *plVar5 = lVar4;
      *(longlong **)(lVar4 + 8) = plVar5;
      *(undefined8 *)(param_2 + 0x80) = 0;
      KeReleaseSpinLockFromDpcLevel(lVar8);
      IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
      CancelSocketIo(*(longlong *)(lVar3 + 0x30));
      *(undefined8 *)(param_2 + 0x38) = 0;
      *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
      CompleteSocketIrp(param_2);
      return;
    }
    pcVar6 = (code *)swi(0x29);
    (*pcVar6)(3);
    puVar7 = auStack_20;
  }
  *(undefined8 *)(puVar7 + -8) = 0x140002904;
  KeReleaseSpinLockFromDpcLevel(lVar8);
  uVar2 = *(undefined1 *)(param_2 + 0x45);
  *(undefined8 *)(puVar7 + -8) = 0x140002913;
  IoReleaseCancelSpinLock(uVar2);
  return;
}



===== SetSocketProcessReference @ 140002930 =====

undefined8 SetSocketProcessReference(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined1 uVar2;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x30);
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  *(undefined8 *)(param_1 + 0x10) = param_2;
  *(undefined8 *)(param_1 + 8) = param_3;
  KeReleaseSpinLock(param_1 + 0x30,uVar2);
  return uVar1;
}



===== __GSHandlerCheck @ 1400029a8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1400029cc =====

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



===== strcmp @ 140002a36 =====

int __cdecl strcmp(char *_Str1,char *_Str2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140002a36. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = strcmp(_Str1,_Str2);
  return iVar1;
}



===== __security_check_cookie @ 140002a60 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140002aa0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140002ad0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140002ad0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140002b00 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140002b80 =====

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



===== DispatchCleanup @ 140008010 =====

ulonglong DispatchCleanup(undefined8 param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  
  lVar2 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
  iVar1 = **(int **)(lVar2 + 0x18);
  if (iVar1 == 0x636f7250) {
    uVar4 = 0;
  }
  else if (iVar1 == 0x6b636f53) {
    uVar3 = CleanupSocketFile(lVar2);
    uVar4 = uVar3 & 0xffffffff;
    if ((int)uVar3 == 0x103) {
      return uVar4;
    }
  }
  else {
    uVar4 = 0xc0000008;
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(int *)(param_2 + 0x30) = (int)uVar4;
  IofCompleteRequest(param_2,0);
  return uVar4;
}



===== DispatchClose @ 140008090 =====

undefined4 DispatchClose(undefined8 param_1,longlong param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = *(int **)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x18);
  if (*piVar1 == 0x636f7250) {
    ObfDereferenceObject(*(undefined8 *)(piVar1 + 0xe));
    DereferenceProcessContext((longlong)piVar1);
  }
  else {
    if (*piVar1 != 0x6b636f53) {
      uVar2 = 0xc0000008;
      goto LAB_140008117;
    }
    ObfDereferenceObject(*(undefined8 *)(piVar1 + 4));
    if (*(longlong *)(piVar1 + 0xe) != 0) {
      ExFreePoolWithTag(*(longlong *)(piVar1 + 0xe),0);
    }
    ExFreePoolWithTag(piVar1,0);
  }
  uVar2 = 0;
LAB_140008117:
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = uVar2;
  IofCompleteRequest(param_2,0);
  return uVar2;
}



===== DispatchCreate @ 140008150 =====

int DispatchCreate(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  
  lVar1 = *(longlong *)(param_2 + 0x18);
  if ((lVar1 != 0) && (lVar2 = *(longlong *)(param_2 + 0xb8), *(char *)(lVar1 + 5) == '\a')) {
    iVar3 = strcmp((char *)(lVar1 + 8),"NifsSct");
    if (iVar3 == 0) {
      iVar3 = CreateSocketFile(*(longlong *)(lVar2 + 0x30),*(undefined1 *)(param_2 + 0x40),lVar1);
      goto LAB_1400081ce;
    }
    iVar3 = strcmp((char *)(lVar1 + 8),"NifsPvd");
    if (iVar3 == 0) {
      iVar3 = CreateProcessFile(*(longlong *)(lVar2 + 0x30),*(undefined1 *)(param_2 + 0x40),lVar1);
      goto LAB_1400081ce;
    }
  }
  iVar3 = -0x3ffffff3;
LAB_1400081ce:
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(int *)(param_2 + 0x30) = iVar3;
  IofCompleteRequest(param_2,0);
  return iVar3;
}



===== DispatchDeviceControl @ 140008210 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong DispatchDeviceControl(undefined8 param_1,longlong param_2)

{
  uint *puVar1;
  byte *pbVar2;
  longlong lVar3;
  longlong lVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  char cVar9;
  
  lVar3 = *(longlong *)(param_2 + 0xb8);
  cVar5 = '\0';
  cVar9 = '\0';
  lVar4 = *(longlong *)(lVar3 + 0x30);
  puVar1 = (uint *)(lVar3 + 0x18);
  if (**(int **)(lVar4 + 0x18) == 0x636f7250) {
    uVar7 = (*puVar1 >> 2 & 0xfff) - 0x800;
    if ((uVar7 < 3) && (*(uint *)(&ProcessIoctlCodeMap + (ulonglong)uVar7 * 4) == *puVar1)) {
      (*(code *)(&ProcessIoControlMap)[uVar7])
                (lVar4,CONCAT31((int3)(uVar7 >> 8),*(undefined1 *)(param_2 + 0x40)),
                 *(undefined8 *)(lVar3 + 0x20),*(undefined4 *)(lVar3 + 0x10),
                 *(undefined8 *)(param_2 + 0x70),*(undefined4 *)(lVar3 + 8),param_2 + 0x30);
LAB_14000835a:
      uVar8 = (ulonglong)*(uint *)(param_2 + 0x30);
      cVar9 = cVar5;
LAB_14000835c:
      uVar7 = (uint)uVar8;
      if (uVar7 == 0x103) {
        return uVar8;
      }
      goto LAB_140008368;
    }
  }
  else if (**(int **)(lVar4 + 0x18) == 0x6b636f53) {
    uVar7 = *puVar1;
    uVar6 = (uVar7 >> 2 & 0xfff) - 0x810;
    if ((uVar6 < 2) && (*(uint *)(&SocketIoctlCodeMap + (ulonglong)uVar6 * 4) == uVar7)) {
      cVar5 = (*(code *)(&SocketIoControlMap)[uVar6])
                        (lVar4,*(undefined1 *)(param_2 + 0x40),*(undefined8 *)(lVar3 + 0x20),
                         *(undefined4 *)(lVar3 + 0x10),*(undefined8 *)(param_2 + 0x70),
                         *(undefined4 *)(lVar3 + 8),param_2 + 0x30);
      if (cVar5 != '\0') {
        pbVar2 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
        *pbVar2 = *pbVar2 | 1;
      }
      goto LAB_14000835a;
    }
    if (((uVar7 - 0x12017 & 0xfffffff3) == 0) && (uVar7 != 0x1201f)) {
      uVar8 = DoSocketAfdIoctl(lVar4,param_2);
      uVar8 = uVar8 & 0xffffffff;
      cVar9 = '\0';
      goto LAB_14000835c;
    }
  }
  uVar7 = 0xc0000010;
LAB_140008368:
  *(uint *)(param_2 + 0x30) = uVar7;
  if (*puVar1 != 0x112047) {
    *(undefined8 *)(param_2 + 0x38) = 0;
  }
  IofCompleteRequest(param_2,0);
  uVar8 = (ulonglong)uVar7;
  if (cVar9 != '\0') {
    uVar8 = 0x103;
  }
  return uVar8;
}



===== DispatchReadWrite @ 1400083c0 =====

ulonglong DispatchReadWrite(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
  if (**(int **)(lVar1 + 0x18) == 0x6b636f53) {
    uVar2 = DoSocketReadWrite(lVar1,param_2);
    uVar3 = uVar2 & 0xffffffff;
    if ((int)uVar2 == 0x103) {
      return uVar3;
    }
  }
  else {
    uVar3 = 0xc0000010;
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(int *)(param_2 + 0x30) = (int)uVar3;
  IofCompleteRequest(param_2,0);
  return uVar3;
}



===== FastIoDeviceControl @ 140008430 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

char FastIoDeviceControl(longlong param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                        undefined8 param_5,undefined4 param_6,uint param_7,undefined8 *param_8)

{
  undefined1 uVar1;
  char cVar2;
  uint uVar3;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  if (**(int **)(param_1 + 0x18) == 0x636f7250) {
    uVar3 = (param_7 >> 2 & 0xfff) - 0x800;
    if ((uVar3 < 3) && (*(uint *)(&ProcessIoctlCodeMap + (ulonglong)uVar3 * 4) == param_7)) {
      uVar1 = ExGetPreviousMode();
      (*(code *)(&ProcessIoControlMap)[uVar3])
                (param_1,uVar1,param_3,param_4,param_5,param_6,param_8);
      return '\x01';
    }
  }
  else {
    if (**(int **)(param_1 + 0x18) != 0x6b636f53) {
      return '\0';
    }
    uVar3 = (param_7 >> 2 & 0xfff) - 0x810;
    if ((param_7 == 0x112047) && (*(longlong *)(param_1 + 0xb0) != 0)) {
      return '\0';
    }
    if ((uVar3 < 2) && (*(uint *)(&SocketIoctlCodeMap + (ulonglong)uVar3 * 4) == param_7)) {
      uVar1 = ExGetPreviousMode();
      cVar2 = (*(code *)(&SocketIoControlMap)[uVar3])
                        (param_1,uVar1,param_3,param_4,param_5,param_6,&local_18);
      if (cVar2 == '\0') {
        return '\0';
      }
      *param_8 = local_18;
      param_8[1] = uStack_10;
      return cVar2;
    }
    if (((param_7 - 0x12017 & 0xfffffff3) == 0) && (param_7 != 0x1201f)) {
      return '\0';
    }
  }
  *(undefined4 *)param_8 = 0xc0000010;
  return '\x01';
}



===== DriverUnload @ 1400085f0 =====

void DriverUnload(void)

{
  IoDeleteDevice(DeviceObject);
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



===== wil_details_EvaluateFeatureDependencies @ 14000865c =====

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
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x000140008697;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_140008711:
  while( true ) {
    if (&UNK_140004c17 < ppuVar3) {
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
      if (&UNK_140004c17 < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x000140008697:
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
      if (&UNK_140004c17 < ppuVar2) goto LAB_140008711;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_140008711;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14000874c =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_1400087e4;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_1400087e4;
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
LAB_1400087e4:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 140008830 =====

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
              if (&UNK_140004c17 < ppuVar2) {
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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 1400088b0 =====

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
    if (*ppuVar3 != (undefined *)0x0) goto LAB_1400089ad;
  }
LAB_1400089b6:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_1400089ad:
  if (ppuVar3 == (undefined **)0x0) goto LAB_1400089b6;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_14000897e:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_14000897e;
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
    if (&UNK_140004c17 < ppuVar3) goto LAB_1400089b6;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_1400089ad;
}



===== AllocateMdlChain @ 1400089dc =====

uint * AllocateMdlChain(longlong param_1,uint *param_2,uint param_3,uint *param_4)

{
  uint *puVar1;
  char cVar2;
  uint *puVar3;
  undefined8 *puVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined8 *puVar8;
  
  uVar7 = (ulonglong)param_3;
  if ((param_2 == (uint *)0x0) ||
     (puVar3 = (uint *)(ulonglong)(param_3 - 1), 0xffffffe < param_3 - 1)) {
LAB_140008af7:
                    /* WARNING: Subroutine does not return */
    ExRaiseStatus(0xc000000d);
  }
  cVar2 = *(char *)(param_1 + 0x40);
  if ((cVar2 != '\0') && (puVar3 = (uint *)(uVar7 * 0x10), param_3 != 0)) {
    if (((ulonglong)param_2 & 3) != 0) {
                    /* WARNING: Subroutine does not return */
      ExRaiseDatatypeMisalignment();
    }
    puVar1 = (uint *)((longlong)puVar3 + (longlong)param_2);
    puVar3 = *(uint **)MmUserProbeAddress_exref;
    if ((puVar3 < puVar1) || (puVar1 < param_2)) {
      puVar3 = (uint *)CONCAT71((int7)((ulonglong)puVar3 >> 8),(char)*puVar3);
    }
  }
  uVar5 = 0;
  *(undefined8 *)(param_1 + 8) = 0;
  puVar8 = (undefined8 *)(param_1 + 8);
  do {
    puVar4 = puVar8;
    if ((*(longlong *)(param_2 + 2) != 0) && (uVar6 = *param_2, uVar6 != 0)) {
      if (~uVar5 < uVar6) goto LAB_140008af7;
      puVar4 = (undefined8 *)IoAllocateMdl(*(longlong *)(param_2 + 2),uVar6,0,1,0);
      if (puVar4 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
        ExRaiseStatus(0xc000009a);
      }
      *puVar8 = puVar4;
      puVar3 = (uint *)MmProbeAndLockPages(puVar4,cVar2);
      param_2 = param_2 + 4;
      uVar5 = uVar5 + uVar6;
    }
    uVar6 = (int)uVar7 - 1;
    uVar7 = (ulonglong)uVar6;
    puVar8 = puVar4;
    if (uVar6 == 0) {
      *param_4 = uVar5;
      return puVar3;
    }
  } while( true );
}



===== AllocateMdlChain32 @ 140008b10 =====

void AllocateMdlChain32(longlong param_1,uint *param_2,int param_3,uint *param_4)

{
  undefined8 *puVar1;
  char cVar2;
  uint uVar3;
  undefined8 *puVar4;
  uint uVar5;
  
  cVar2 = *(char *)(param_1 + 0x40);
  puVar1 = (undefined8 *)(param_1 + 8);
  uVar5 = 0;
  *puVar1 = 0;
  if (cVar2 != '\0') {
    if ((param_2 == (uint *)0x0) || (0x1ffffffe < param_3 - 1U)) {
LAB_140008c26:
                    /* WARNING: Subroutine does not return */
      ExRaiseStatus(0xc000000d);
    }
    if ((param_3 != 0) && (((ulonglong)param_2 & 3) != 0)) {
                    /* WARNING: Subroutine does not return */
      ExRaiseDatatypeMisalignment();
    }
  }
  do {
    if (param_3 == 0) {
      *param_4 = uVar5;
      return;
    }
    uVar3 = *param_2;
    puVar4 = puVar1;
    if (uVar3 != 0) {
      if (~uVar5 < uVar3) goto LAB_140008c26;
      puVar4 = (undefined8 *)IoAllocateMdl(param_2[1],uVar3,0,1,0);
      if (puVar4 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
        ExRaiseStatus(0xc000009a);
      }
      *puVar1 = puVar4;
      MmProbeAndLockPages(puVar4,cVar2);
      uVar5 = uVar5 + uVar3;
    }
    param_2 = param_2 + 2;
    param_3 = param_3 + -1;
    puVar1 = puVar4;
  } while( true );
}



===== CopyMdlChainToBuffer @ 140008c40 =====

int CopyMdlChainToBuffer(undefined8 *param_1,void *param_2,uint param_3)

{
  uint uVar1;
  void *_Src;
  void *_Dst;
  
  _Dst = param_2;
  do {
    if (param_3 == 0) {
LAB_140008ca8:
      return (int)_Dst - (int)param_2;
    }
    do {
      if (param_1 == (undefined8 *)0x0) goto LAB_140008ca8;
      _Src = (void *)((ulonglong)*(uint *)((longlong)param_1 + 0x2c) + param_1[4]);
      uVar1 = *(uint *)(param_1 + 5);
      param_1 = (undefined8 *)*param_1;
    } while (uVar1 == 0);
    if (param_3 <= uVar1) {
      memmove(_Dst,_Src,(ulonglong)param_3);
      _Dst = (void *)((longlong)_Dst + (ulonglong)param_3);
      goto LAB_140008ca8;
    }
    memmove(_Dst,_Src,(ulonglong)uVar1);
    _Dst = (void *)((longlong)_Dst + (ulonglong)uVar1);
    param_3 = param_3 - uVar1;
  } while( true );
}



===== CallCompleteDrvRequest @ 140008cd0 =====

void CallCompleteDrvRequest
               (undefined8 param_1,char param_2,longlong *param_3,uint param_4,undefined8 *param_5,
               uint param_6,int *param_7)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  longlong lVar5;
  uint uVar6;
  longlong local_28;
  ulonglong uStack_20;
  longlong local_18;
  
  piVar1 = param_7;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  param_7[2] = 0;
  param_7[3] = 0;
  cVar3 = IoIs32bitProcess(0);
  if (cVar3 == '\0') {
    if (param_4 < 0x18) goto LAB_140008f30;
    if ((param_2 != '\0') && (((ulonglong)param_3 & 3) != 0)) {
                    /* WARNING: Subroutine does not return */
      ExRaiseDatatypeMisalignment();
    }
    local_28 = *param_3;
    uStack_20 = param_3[1];
    local_18 = param_3[2];
    uVar6 = (uint)local_18;
  }
  else {
    if (param_4 < 0x14) goto LAB_140008f30;
    if ((param_2 != '\0') && (((ulonglong)param_3 & 3) != 0)) {
                    /* WARNING: Subroutine does not return */
      ExRaiseDatatypeMisalignment();
    }
    local_28 = (longlong)(int)*param_3;
    uStack_20 = *(ulonglong *)((longlong)param_3 + 4);
    local_18 = *(longlong *)((longlong)param_3 + 0xc);
    uVar6 = *(uint *)((longlong)param_3 + 0xc);
  }
  if ((uint)(uStack_20 >> 0x20) <= param_6) {
    if (uVar6 != 0) {
      if (param_6 < uVar6) {
        return;
      }
      if ((ulonglong)param_6 < ((uStack_20 >> 0x20) + 1 & 0xfffffffffffffffe) + (ulonglong)uVar6) {
        return;
      }
    }
    param_7 = (int *)0x0;
    iVar4 = ObReferenceObjectByHandle
                      (local_28,0x1f01ff,*(undefined8 *)IoFileObjectType_exref,param_2,&param_7,0);
    piVar2 = param_7;
    *piVar1 = iVar4;
    if (iVar4 < 0) {
      return;
    }
    lVar5 = IoGetRelatedDeviceObject(param_7);
    if ((lVar5 == DeviceObject) && (**(int **)(piVar2 + 6) == 0x6b636f53)) {
      CompleteDrvRequest((longlong)piVar2,(longlong)&local_28,param_5,param_6,piVar1);
    }
    ObfDereferenceObject(piVar2);
    return;
  }
LAB_140008f30:
  *piVar1 = -0x3ffffff3;
  return;
}



===== CompleteDrvCancel @ 140008f60 =====

void CompleteDrvCancel(longlong param_1,char param_2,int *param_3,uint param_4,undefined8 param_5,
                      undefined8 param_6,uint *param_7)

{
  longlong lVar1;
  longlong *plVar2;
  char local_res20 [8];
  
  lVar1 = *(longlong *)(param_1 + 0x18);
  local_res20[0] = '\0';
  param_7[2] = 0;
  param_7[3] = 0;
  if (param_4 < 4) {
    *param_7 = 0xc000000d;
  }
  else {
    if ((param_2 != '\0') && (((ulonglong)param_3 & 3) != 0)) {
                    /* WARNING: Subroutine does not return */
      ExRaiseDatatypeMisalignment();
    }
    plVar2 = DequeueCancel(lVar1,*param_3,local_res20);
    if (plVar2 != (longlong *)0x0) {
      FreeSocketCancel((longlong)plVar2);
    }
    *param_7 = -(uint)(local_res20[0] != '\0') & 0x105;
  }
  return;
}



===== CreateProcessFile @ 140009000 =====

int CreateProcessFile(longlong param_1,undefined1 param_2,longlong param_3)

{
  undefined8 uVar1;
  char cVar2;
  int iVar3;
  longlong lVar4;
  undefined4 *puVar5;
  undefined8 uVar6;
  longlong lVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  undefined8 local_res20;
  
  cVar2 = IoIs32bitProcess(0);
  if (cVar2 == '\0') {
    if (*(short *)(param_3 + 6) != 0x28) {
      return -0x3ffffff3;
    }
    lVar7 = *(longlong *)(param_3 + 0x10);
    uVar9 = *(ulonglong *)(param_3 + 0x20);
    uVar10 = *(ulonglong *)(param_3 + 0x28);
    uVar8 = *(ulonglong *)(param_3 + 0x18);
  }
  else {
    if (*(short *)(param_3 + 6) != 0x14) {
      return -0x3ffffff3;
    }
    lVar7 = (longlong)*(int *)(param_3 + 0x10);
    uVar8 = (ulonglong)*(uint *)(param_3 + 0x14);
    uVar9 = (ulonglong)*(uint *)(param_3 + 0x18);
    uVar10 = (ulonglong)*(uint *)(param_3 + 0x1c);
  }
  local_res20 = 0;
  iVar3 = ObReferenceObjectByHandle
                    (lVar7,0x10,*(undefined8 *)PsThreadType_exref,param_2,&local_res20,0);
  uVar1 = local_res20;
  if (-1 < iVar3) {
    lVar7 = IoThreadToProcess(local_res20);
    lVar4 = IoGetCurrentProcess();
    if (lVar7 == lVar4) {
      puVar5 = (undefined4 *)ExAllocatePool2(0x61,0x110,0x50327357);
      if (puVar5 == (undefined4 *)0x0) {
        if (-1 < iVar3) {
          iVar3 = -0x3fffff66;
        }
      }
      else {
        *puVar5 = 0x636f7250;
        uVar6 = PsGetCurrentProcessId();
        *(undefined8 *)(puVar5 + 2) = uVar6;
        puVar5[0x40] = 0;
        *(undefined8 *)(puVar5 + 0x42) = 1;
        iVar3 = InitializeRequestQueue((longlong)puVar5,uVar1,param_2,uVar8,uVar10);
        if (-1 < iVar3) {
          iVar3 = InitializeCancelQueue((longlong)puVar5,uVar1,param_2,uVar9,uVar10);
        }
        if (-1 < iVar3) {
          *(undefined4 **)(param_1 + 0x18) = puVar5;
          return 0;
        }
      }
    }
    else {
      iVar3 = -0x3ffff8e4;
    }
    ObfDereferenceObject(uVar1);
  }
  return iVar3;
}



===== RetrieveDrvRequest @ 140009240 =====

void RetrieveDrvRequest(longlong param_1,char param_2,ulonglong *param_3,uint param_4,void *param_5,
                       uint param_6,uint *param_7)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  longlong lVar4;
  ulonglong uVar5;
  char cVar6;
  longlong lVar7;
  undefined8 uVar8;
  uint uVar9;
  ulonglong uVar10;
  undefined4 uVar11;
  ulonglong _Size;
  char local_res8 [8];
  ulonglong local_48;
  undefined4 uStack_40;
  uint uStack_34;
  uint uStack_30;
  undefined4 uStack_2c;
  
  lVar7 = *(longlong *)(param_1 + 0x18);
  local_res8[0] = '\0';
  cVar6 = IoIs32bitProcess(0);
  param_7[2] = 0;
  param_7[3] = 0;
  if (cVar6 == '\0') {
    if (param_4 < 0x20) goto LAB_140009322;
    if (param_2 != '\0') {
      if (((ulonglong)param_3 & 3) != 0) {
                    /* WARNING: Subroutine does not return */
        ExRaiseDatatypeMisalignment();
      }
      if (param_6 != 0) {
        ProbeForWrite(param_5,param_6,1);
      }
    }
    uVar9 = (uint)*param_3;
  }
  else {
    if (param_4 < 0x18) {
LAB_140009322:
      *param_7 = 0xc000000d;
      return;
    }
    if (param_2 != '\0') {
      if (((ulonglong)param_3 & 3) != 0) {
                    /* WARNING: Subroutine does not return */
        ExRaiseDatatypeMisalignment();
      }
      if (param_6 != 0) {
        ProbeForWrite(param_5,param_6,1);
      }
    }
    uVar9 = (uint)*param_3;
  }
  local_48 = (ulonglong)uVar9;
  uVar11 = 3;
  lVar7 = DequeueRequest(lVar7,uVar9,local_res8);
  if (lVar7 == 0) {
    *param_7 = 0xc0000120;
    goto LAB_140009608;
  }
  pcVar3 = *(char **)(lVar7 + 0xb8);
  if (param_5 == (void *)0x0) {
    *param_7 = 0xc000009a;
    goto LAB_140009608;
  }
  lVar4 = *(longlong *)(*(longlong *)(pcVar3 + 0x30) + 0x18);
  uVar5 = *(ulonglong *)(lVar4 + 8);
  cVar1 = *pcVar3;
  if (cVar1 == '\x03') {
    uVar11 = 0;
    uStack_30 = 0;
    uStack_2c = 0;
LAB_140009581:
    uStack_34 = *(uint *)(pcVar3 + 8);
  }
  else if (cVar1 == '\x04') {
    uStack_34 = CopyMdlChainToBuffer(*(undefined8 **)(lVar7 + 8),param_5,param_6);
    if (uStack_34 < *(uint *)(pcVar3 + 8)) {
                    /* WARNING: Subroutine does not return */
      ExRaiseStatus(0xc000009a);
    }
    uVar11 = 1;
    uStack_30 = 0;
    uStack_2c = 0;
    *(ulonglong *)(param_7 + 2) = (ulonglong)uStack_34;
  }
  else {
    if (cVar1 == '\x0e') {
      iVar2 = *(int *)(pcVar3 + 0x18);
      if (iVar2 == 0x12017) {
        uStack_30 = 0;
      }
      else {
        uVar11 = 4;
        if (iVar2 != 0x1201b) {
          if (iVar2 != 0x12023) goto LAB_140009445;
          uStack_34 = CopyMdlChainToBuffer(*(undefined8 **)(lVar7 + 8),param_5,param_6);
          if (uStack_34 <= *(uint *)(pcVar3 + 8)) {
LAB_1400094d4:
                    /* WARNING: Subroutine does not return */
            ExRaiseStatus(0xc000009a);
          }
          uVar10 = (ulonglong)uStack_34 + 1 & 0xfffffffffffffffe;
          _Size = (ulonglong)*(uint *)(pcVar3 + 0x10);
          if ((_Size + uVar10 < _Size) || (_Size + uVar10 < (ulonglong)param_6)) goto LAB_1400094d4;
          memmove((void *)(uVar10 + (longlong)param_5),*(void **)(pcVar3 + 0x20),_Size);
          uVar11 = 2;
          uStack_30 = *(uint *)(pcVar3 + 0x10);
          uStack_2c = *(undefined4 *)(lVar7 + 0x88);
          *(ulonglong *)(param_7 + 2) = uStack_30 + uVar10;
          goto LAB_140009589;
        }
        uStack_30 = *(uint *)(pcVar3 + 0x10);
      }
      uStack_2c = *(undefined4 *)(lVar7 + 0x88);
      goto LAB_140009581;
    }
    if (cVar1 != '\x1b') {
LAB_140009445:
      *param_7 = 0xc000000d;
      goto LAB_140009608;
    }
    uVar11 = 5;
    uStack_34 = 8;
    uStack_30 = 0;
    uStack_2c = 0;
  }
LAB_140009589:
  if (cVar6 == '\0') {
    *param_3 = local_48;
    param_3[1] = uVar5;
    param_3[2] = CONCAT44(uStack_34,uVar11);
    param_3[3] = CONCAT44(uStack_2c,uStack_30);
  }
  else {
    uStack_40 = (undefined4)uVar5;
    *(undefined4 *)((longlong)param_3 + 4) = uStack_40;
    *(undefined4 *)(param_3 + 1) = uVar11;
    *(uint *)((longlong)param_3 + 0xc) = uStack_34;
    *(uint *)(param_3 + 2) = uStack_30;
    *(undefined4 *)((longlong)param_3 + 0x14) = uStack_2c;
  }
  uVar8 = InsertProcessedRequest(lVar4,lVar7);
  if ((char)uVar8 == '\0') {
    uVar9 = 0xc0000120;
  }
  else {
    uVar9 = -(uint)(local_res8[0] != '\0') & 0x105;
  }
  *param_7 = uVar9;
LAB_140009608:
  if (((int)*param_7 < 0) && (lVar7 != 0)) {
    *(uint *)(lVar7 + 0x30) = *param_7;
    *(undefined8 *)(lVar7 + 0x38) = 0;
    CompleteSocketIrp(lVar7);
  }
  return;
}



===== InitializeCancelQueue @ 140009654 =====

int InitializeCancelQueue
              (longlong param_1,undefined8 param_2,undefined1 param_3,undefined8 param_4,
              undefined8 param_5)

{
  longlong lVar1;
  int iVar2;
  ulonglong uVar3;
  code *pcVar4;
  undefined8 local_res20;
  
  lVar1 = param_1 + 0x88;
  *(undefined1 *)(param_1 + 0x98) = 0;
  *(longlong *)(param_1 + 0x90) = lVar1;
  *(longlong *)lVar1 = lVar1;
  local_res20 = param_4;
  KeInitializeSpinLock(param_1 + 0xa0);
  iVar2 = PsWrapApcWow64Thread(&param_5,&local_res20);
  if (-1 < iVar2) {
    uVar3 = Feature_TCPIP_2025_Wave2_Ws2ifsl__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar3 == 0) {
      pcVar4 = _guard_check_icall;
    }
    else {
      pcVar4 = CancelQueueKernelRoutine;
    }
    KeInitializeApc(param_1 + 0xa8,param_2,0,pcVar4,CancelRundownRoutine,local_res20,param_3,param_5
                   );
  }
  return iVar2;
}



===== InitializeRequestQueue @ 140009738 =====

int InitializeRequestQueue
              (longlong param_1,undefined8 param_2,undefined1 param_3,undefined8 param_4,
              undefined8 param_5)

{
  longlong lVar1;
  int iVar2;
  ulonglong uVar3;
  code *pcVar4;
  undefined8 local_res20;
  
  lVar1 = param_1 + 0x10;
  *(undefined1 *)(param_1 + 0x20) = 0;
  *(longlong *)(param_1 + 0x18) = lVar1;
  *(longlong *)lVar1 = lVar1;
  local_res20 = param_4;
  KeInitializeSpinLock(param_1 + 0x28);
  iVar2 = PsWrapApcWow64Thread(&param_5,&local_res20);
  if (-1 < iVar2) {
    uVar3 = Feature_TCPIP_2025_Wave2_Ws2ifsl__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar3 == 0) {
      pcVar4 = _guard_check_icall;
    }
    else {
      pcVar4 = RequestQueueKernelRoutine;
    }
    KeInitializeApc(param_1 + 0x30,param_2,0,pcVar4,RequestRundownRoutine,local_res20,param_3,
                    param_5);
  }
  return iVar2;
}



===== CleanupSocketFile @ 140009810 =====

undefined8 CleanupSocketFile(longlong param_1)

{
  longlong ***ppplVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong ***ppplVar4;
  longlong lVar5;
  code *pcVar6;
  longlong ***ppplVar7;
  char cVar8;
  longlong lVar9;
  longlong ***ppplVar10;
  undefined1 *puVar11;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  longlong ***local_18;
  longlong ***local_10;
  
  lVar3 = *(longlong *)(param_1 + 0x18);
  lVar9 = GetSocketProcessReference(lVar3);
  local_10 = (longlong ***)&local_18;
  local_18 = (longlong ***)&local_18;
  CleanupQueuedRequests(*(longlong *)(lVar9 + 0x18),param_1,(longlong)&local_18);
  CleanupProcessedRequests(lVar3,(longlong)&local_18);
  puVar11 = auStack_38;
  do {
    ppplVar7 = local_18;
    if ((longlong ****)local_18 == &local_18) {
LAB_1400098b5:
      LOCK();
      plVar2 = *(longlong **)(lVar3 + 0x38);
      *(undefined8 *)(lVar3 + 0x38) = 0;
      UNLOCK();
      if (plVar2 != (longlong *)0x0) {
        lVar5 = *(longlong *)(lVar9 + 0x18);
        *(undefined8 *)(puVar11 + -8) = 0x1400098cc;
        cVar8 = RemoveQueuedCancel(lVar5,plVar2);
        *(longlong **)(lVar3 + 0x38) = plVar2;
        if (cVar8 != '\0') {
          *(undefined8 *)(puVar11 + -8) = 0x1400098dc;
          FreeSocketCancel((longlong)plVar2);
        }
      }
      *(undefined8 *)(puVar11 + -8) = 0x1400098e6;
      ObfDereferenceObject(lVar9);
      return 0;
    }
    if (((longlong ****)local_18[1] != &local_18) ||
       (ppplVar4 = (longlong ***)*local_18, (longlong ***)ppplVar4[1] != local_18)) {
      pcVar6 = (code *)swi(0x29);
      (*pcVar6)(3);
      puVar11 = auStack_30;
      goto LAB_1400098b5;
    }
    ppplVar10 = local_18 + -0x15;
    ppplVar4[1] = (longlong **)&local_18;
    ppplVar1 = local_18 + -0xe;
    local_18 = ppplVar4;
    *ppplVar1 = (longlong **)0x0;
    *(undefined4 *)(ppplVar7 + -0xf) = 0xc0000120;
    CompleteSocketIrp((longlong)ppplVar10);
  } while( true );
}



===== CompleteDrvRequest @ 140009904 =====

void CompleteDrvRequest(longlong param_1,longlong param_2,undefined8 *param_3,uint param_4,
                       undefined4 *param_5)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  longlong lVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  int iVar9;
  uint uVar10;
  undefined8 *puVar11;
  undefined8 uVar12;
  longlong lVar13;
  uint uVar14;
  void *pvVar15;
  uint uVar16;
  undefined8 *_Src;
  int iVar17;
  longlong *plVar18;
  undefined8 local_res8;
  int local_60;
  
  puVar11 = GetProcessedRequest(*(longlong *)(param_1 + 0x18),(ulonglong)*(uint *)(param_2 + 8));
  if (puVar11 == (undefined8 *)0x0) {
    *param_5 = 0xc0000120;
    return;
  }
  iVar9 = *(int *)(param_2 + 0x14);
  iVar17 = 0;
  local_60 = 0;
  pcVar3 = (char *)puVar11[0x17];
  cVar1 = *pcVar3;
  if (cVar1 == '\x03') goto LAB_140009bb7;
  if (cVar1 == '\x04') {
    uVar16 = *(uint *)(param_2 + 0xc);
  }
  else if (cVar1 == '\x0e') {
    iVar2 = *(int *)(pcVar3 + 0x18);
    if (iVar2 != 0x12017) {
      if (iVar2 != 0x1201b) {
        if (iVar2 != 0x12023) {
                    /* WARNING: Subroutine does not return */
          ExRaiseStatus(0xc000000d);
        }
        uVar16 = 0;
        goto LAB_140009c5c;
      }
      if (*(longlong *)(pcVar3 + 0x20) != 0) {
        uVar10 = *(int *)(pcVar3 + 8) + 1U & 0xfffffffe;
        uVar16 = *(uint *)(param_2 + 0x10);
        uVar14 = uVar16 + uVar10;
        if ((uVar14 < uVar16) || (param_4 < uVar14)) {
                    /* WARNING: Subroutine does not return */
          ExRaiseStatus(0xc000000d);
        }
        pvVar15 = (void *)((ulonglong)uVar10 + (longlong)param_3);
        if (*(uint *)(pcVar3 + 0x10) < uVar16) {
          memmove(*(void **)(pcVar3 + 0x20),pvVar15,(ulonglong)*(uint *)(pcVar3 + 0x10));
          iVar17 = -0x7ffffffb;
          local_60 = -0x7ffffffb;
        }
        else {
          memmove(*(void **)(pcVar3 + 0x20),pvVar15,(ulonglong)uVar16);
        }
      }
      if ((-1 < iVar17) && (puVar11[0xe] != 0)) {
        *(undefined4 *)puVar11[0x12] = *(undefined4 *)(param_2 + 0x10);
      }
    }
LAB_140009bb7:
    plVar18 = (longlong *)puVar11[1];
    if (plVar18 == (longlong *)0x0) {
      uVar16 = 0;
    }
    else {
      _Src = param_3;
      for (uVar16 = *(uint *)(param_2 + 0xc); uVar16 != 0; uVar16 = uVar16 - uVar10) {
        do {
          if (plVar18 == (longlong *)0x0) goto LAB_140009c14;
          pvVar15 = (void *)((ulonglong)*(uint *)((longlong)plVar18 + 0x2c) + plVar18[4]);
          uVar10 = *(uint *)(plVar18 + 5);
          plVar18 = (longlong *)*plVar18;
        } while (uVar10 == 0);
        if (uVar16 <= uVar10) {
          memmove(pvVar15,_Src,(ulonglong)uVar16);
          _Src = (undefined8 *)((longlong)_Src + (ulonglong)uVar16);
          break;
        }
        memmove(pvVar15,_Src,(ulonglong)uVar10);
        _Src = (undefined8 *)((longlong)_Src + (ulonglong)uVar10);
      }
LAB_140009c14:
      uVar16 = (int)_Src - (int)param_3;
      iVar17 = local_60;
    }
    if ((uVar16 < *(uint *)(param_2 + 0xc)) && (-1 < iVar9)) {
      iVar9 = -0x7ffffffb;
    }
  }
  else {
    if (cVar1 != '\x1b') {
                    /* WARNING: Subroutine does not return */
      ExRaiseStatus(0xc000000d);
    }
    uVar16 = 0;
    if (param_4 < 8) {
                    /* WARNING: Subroutine does not return */
      ExRaiseStatus(0xc000000d);
    }
    local_res8 = 0;
    iVar9 = ObReferenceObjectByHandle
                      (*param_3,0x2000000,*(undefined8 *)IoFileObjectType_exref,
                       *(undefined1 *)(puVar11 + 8),&local_res8,0,0);
    *(undefined8 *)(pcVar3 + 0x30) = local_res8;
    if (-1 < iVar9) {
      uVar12 = IoGetRelatedDeviceObject(local_res8);
      lVar13 = IoBuildAsynchronousFsdRequest(0x1b,uVar12,0,0,0,0);
      if (lVar13 != 0) {
        lVar4 = *(longlong *)(lVar13 + 0xb8);
        uVar8 = *(undefined8 *)(pcVar3 + 8);
        *(undefined8 *)(lVar4 + -0x48) = *(undefined8 *)pcVar3;
        *(undefined8 *)(lVar4 + -0x40) = uVar8;
        uVar8 = *(undefined8 *)(pcVar3 + 0x18);
        *(undefined8 *)(lVar4 + -0x38) = *(undefined8 *)(pcVar3 + 0x10);
        *(undefined8 *)(lVar4 + -0x30) = uVar8;
        uVar8 = *(undefined8 *)(pcVar3 + 0x28);
        *(undefined8 *)(lVar4 + -0x28) = *(undefined8 *)(pcVar3 + 0x20);
        *(undefined8 *)(lVar4 + -0x20) = uVar8;
        uVar5 = *(undefined4 *)(pcVar3 + 0x34);
        uVar6 = *(undefined4 *)(pcVar3 + 0x38);
        uVar7 = *(undefined4 *)(pcVar3 + 0x3c);
        *(undefined4 *)(lVar4 + -0x18) = *(undefined4 *)(pcVar3 + 0x30);
        *(undefined4 *)(lVar4 + -0x14) = uVar5;
        *(undefined4 *)(lVar4 + -0x10) = uVar6;
        *(undefined4 *)(lVar4 + -0xc) = uVar7;
        *(undefined8 *)(lVar4 + -8) = *(undefined8 *)(pcVar3 + 0x40);
        *(undefined8 *)(lVar4 + -0x18) = *(undefined8 *)(pcVar3 + 0x30);
        lVar13 = *(longlong *)(lVar13 + 0xb8);
        *(code **)(lVar13 + -0x10) = CompleteTargetQuery;
        *(undefined8 **)(lVar13 + -8) = puVar11;
        *(undefined1 *)(lVar13 + -0x45) = 0;
        *(undefined1 *)(lVar13 + -0x45) = 0x40;
        *(undefined1 *)(lVar13 + -0x45) = 0xc0;
        *(undefined1 *)(lVar13 + -0x45) = 0xe0;
        IofCallDriver(uVar12);
        goto LAB_140009c74;
      }
      ObfDereferenceObject(*(undefined8 *)(pcVar3 + 0x30));
      iVar9 = -0x3fffff66;
    }
  }
LAB_140009c5c:
  puVar11[7] = (ulonglong)uVar16;
  if (-1 < iVar9) {
    iVar9 = iVar17;
  }
  *(int *)(puVar11 + 6) = iVar9;
  CompleteSocketIrp((longlong)puVar11);
LAB_140009c74:
  *param_5 = 0;
  return;
}



===== CompletePvdRequest @ 140009cf0 =====

undefined1
CompletePvdRequest(longlong param_1,char param_2,undefined4 *param_3,uint param_4,undefined8 param_5
                  ,undefined8 param_6,undefined4 *param_7)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char cVar4;
  longlong lVar5;
  longlong lVar6;
  undefined1 uVar7;
  
  uVar7 = 0;
  *(undefined8 *)(param_7 + 2) = 0;
  cVar4 = IoIs32bitProcess(0);
  if (cVar4 == '\0') {
    if (param_4 < 0x10) goto LAB_140009d96;
  }
  else if (param_4 < 8) {
LAB_140009d96:
    *param_7 = 0xc000000d;
    return 0;
  }
  lVar5 = GetSocketProcessReference(*(longlong *)(param_1 + 0x18));
  lVar6 = PsGetCurrentProcessId();
  if (*(longlong *)(*(longlong *)(lVar5 + 0x18) + 8) == lVar6) {
    cVar4 = IoIs32bitProcess(0);
    if (cVar4 == '\0') {
      if ((param_2 != '\0') && (((ulonglong)param_3 & 3) != 0)) {
                    /* WARNING: Subroutine does not return */
        ExRaiseDatatypeMisalignment();
      }
      uVar1 = param_3[1];
      uVar2 = param_3[2];
      uVar3 = param_3[3];
      *param_7 = *param_3;
      param_7[1] = uVar1;
      param_7[2] = uVar2;
      param_7[3] = uVar3;
    }
    else {
      if ((param_2 != '\0') && (((ulonglong)param_3 & 3) != 0)) {
                    /* WARNING: Subroutine does not return */
        ExRaiseDatatypeMisalignment();
      }
      *param_7 = *param_3;
      *(ulonglong *)(param_7 + 2) = (ulonglong)(uint)param_3[1];
    }
    uVar7 = 1;
  }
  else {
    *param_7 = 0xc0000008;
  }
  ObfDereferenceObject(lVar5);
  return uVar7;
}



===== CreateSocketFile @ 140009e5c =====

int CreateSocketFile(longlong param_1,undefined1 param_2,longlong param_3)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  longlong lVar4;
  undefined4 *puVar5;
  longlong lVar6;
  ulonglong uVar7;
  longlong local_res20;
  
  cVar2 = IoIs32bitProcess(0);
  if (cVar2 == '\0') {
    if (*(short *)(param_3 + 6) != 0x10) {
      return -0x3ffffff3;
    }
    lVar6 = *(longlong *)(param_3 + 0x18);
    uVar7 = *(ulonglong *)(param_3 + 0x10);
  }
  else {
    if (*(short *)(param_3 + 6) != 8) {
      return -0x3ffffff3;
    }
    lVar6 = (longlong)*(int *)(param_3 + 0x14);
    uVar7 = (ulonglong)*(uint *)(param_3 + 0x10);
  }
  local_res20 = 0;
  iVar3 = ObReferenceObjectByHandle
                    (lVar6,0x1f01ff,*(undefined8 *)IoFileObjectType_exref,param_2,&local_res20,0,
                     uVar7);
  lVar6 = local_res20;
  if (-1 < iVar3) {
    lVar4 = IoGetRelatedDeviceObject(local_res20);
    if (((lVar4 == DeviceObject) && (**(int **)(lVar6 + 0x18) == 0x636f7250)) &&
       (lVar4 = PsGetCurrentProcessId(), *(longlong *)(*(longlong *)(lVar6 + 0x18) + 8) == lVar4)) {
      puVar5 = (undefined4 *)ExAllocatePool2(0x61,0x40,0x53327357);
      if (puVar5 != (undefined4 *)0x0) {
        *puVar5 = 0x6b636f53;
        *(ulonglong *)(puVar5 + 2) = uVar7;
        *(longlong *)(puVar5 + 4) = lVar6;
        puVar1 = puVar5 + 8;
        *(undefined4 **)(puVar5 + 10) = puVar1;
        *(undefined4 **)puVar1 = puVar1;
        KeInitializeSpinLock(puVar5 + 0xc);
        *(undefined8 *)(puVar5 + 0xe) = 0;
        puVar5[6] = 0;
        *(undefined4 **)(param_1 + 0x18) = puVar5;
        return iVar3;
      }
      if (-1 < iVar3) {
        iVar3 = -0x3fffff66;
      }
    }
    else {
      iVar3 = -0x3ffffff3;
    }
    ObfDereferenceObject(lVar6);
  }
  return iVar3;
}



===== DoSocketAfdIoctl @ 14000a014 =====

undefined8 DoSocketAfdIoctl(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  int *piVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  uint *puVar6;
  ulonglong *puVar7;
  char cVar8;
  longlong lVar9;
  longlong lVar10;
  uint *puVar11;
  uint uVar13;
  int iVar12;
  undefined8 uVar14;
  uint uVar15;
  uint local_54;
  ulonglong local_50;
  int *local_48;
  
  local_48 = (int *)0x0;
  lVar4 = *(longlong *)(param_2 + 0xb8);
  *(undefined8 *)(param_2 + 0x38) = 0;
  lVar5 = *(longlong *)(param_1 + 0x18);
  lVar9 = GetSocketProcessReference(lVar5);
  lVar10 = PsGetCurrentProcessId();
  if (*(longlong *)(*(longlong *)(lVar9 + 0x18) + 8) == lVar10) {
    if (((*(char *)(param_2 + 0x40) != '\0') && (*(int *)(lVar4 + 0x10) != 0)) &&
       ((*(ulonglong *)(lVar4 + 0x20) & 3) != 0)) {
                    /* WARNING: Subroutine does not return */
      ExRaiseDatatypeMisalignment();
    }
    iVar12 = 0;
    local_50 = 0;
    iVar3 = *(int *)(lVar4 + 0x18);
    if (iVar3 == 0x12017) {
      cVar8 = IoIs32bitProcess(0);
      if (cVar8 == '\0') {
        if (*(uint *)(lVar4 + 0x10) < 0x18) {
                    /* WARNING: Subroutine does not return */
          ExRaiseStatus(0xc000000d);
        }
        puVar7 = *(ulonglong **)(lVar4 + 0x20);
        puVar11 = (uint *)*puVar7;
        uVar15 = (uint)puVar7[1];
        local_54 = (uint)puVar7[2];
      }
      else {
        if (*(uint *)(lVar4 + 0x10) < 0x10) {
                    /* WARNING: Subroutine does not return */
          ExRaiseStatus(0xc000000d);
        }
        puVar6 = *(uint **)(lVar4 + 0x20);
        puVar11 = (uint *)(ulonglong)*puVar6;
        uVar15 = puVar6[1];
        local_54 = puVar6[3];
      }
    }
    else if (iVar3 == 0x1201b) {
      cVar8 = IoIs32bitProcess(0);
      if (cVar8 == '\0') {
        if (*(uint *)(lVar4 + 0x10) < 0x28) {
                    /* WARNING: Subroutine does not return */
          ExRaiseStatus(0xc000000d);
        }
        puVar7 = *(ulonglong **)(lVar4 + 0x20);
        puVar11 = (uint *)*puVar7;
        uVar15 = (uint)puVar7[1];
        local_50 = puVar7[3];
        local_48 = (int *)puVar7[4];
        local_54 = (uint)puVar7[2];
      }
      else {
        if (*(uint *)(lVar4 + 0x10) < 0x18) {
                    /* WARNING: Subroutine does not return */
          ExRaiseStatus(0xc000000d);
        }
        puVar6 = *(uint **)(lVar4 + 0x20);
        puVar11 = (uint *)(ulonglong)*puVar6;
        uVar15 = puVar6[1];
        local_50 = (ulonglong)puVar6[4];
        local_48 = (int *)(ulonglong)puVar6[5];
        local_54 = puVar6[3];
      }
      if ((local_50 == 0) != (local_48 == (int *)0x0)) {
                    /* WARNING: Subroutine does not return */
        ExRaiseStatus(0xc000000d);
      }
      if ((*(char *)(param_2 + 0x40) != '\0') && (((ulonglong)local_48 & 3) != 0)) {
                    /* WARNING: Subroutine does not return */
        ExRaiseDatatypeMisalignment();
      }
      iVar12 = *local_48;
      if (local_50 != 0) {
        if (0xfffe < iVar12 - 1U) {
                    /* WARNING: Subroutine does not return */
          ExRaiseStatus(0xc000000d);
        }
        if (*(char *)(param_2 + 0x40) != '\0') {
          ProbeForWrite(local_50,iVar12,1);
        }
      }
    }
    else {
      if (iVar3 != 0x12023) {
                    /* WARNING: Subroutine does not return */
        ExRaiseStatus(0xc000000d);
      }
      cVar8 = IoIs32bitProcess(0);
      if (cVar8 == '\0') {
        if (*(uint *)(lVar4 + 0x10) < 0x68) {
                    /* WARNING: Subroutine does not return */
          ExRaiseStatus(0xc000000d);
        }
        puVar7 = *(ulonglong **)(lVar4 + 0x20);
        puVar11 = (uint *)*puVar7;
        uVar15 = (uint)puVar7[1];
        local_50 = puVar7[0xc];
        uVar13 = (uint)puVar7[0xb];
      }
      else {
        if (*(uint *)(lVar4 + 0x10) < 0x38) {
                    /* WARNING: Subroutine does not return */
          ExRaiseStatus(0xc000000d);
        }
        puVar6 = *(uint **)(lVar4 + 0x20);
        puVar11 = (uint *)(ulonglong)*puVar6;
        uVar15 = puVar6[1];
        local_50 = (ulonglong)puVar6[0xd];
        uVar13 = puVar6[0xc];
      }
      local_50 = local_50 + 6;
      iVar12 = uVar13 - 6;
      if (0xfffe < uVar13 - 7) {
                    /* WARNING: Subroutine does not return */
        ExRaiseStatus(0xc000000d);
      }
      local_54 = 0;
    }
    cVar8 = IoIs32bitProcess(0);
    if (cVar8 == '\0') {
      AllocateMdlChain(param_2,puVar11,uVar15,(uint *)(lVar4 + 8));
    }
    else {
      AllocateMdlChain32(param_2,puVar11,uVar15,(uint *)(lVar4 + 8));
    }
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
    *(ulonglong *)(lVar4 + 0x20) = local_50;
    *(int *)(lVar4 + 0x10) = iVar12;
    LOCK();
    piVar2 = (int *)(lVar5 + 0x18);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + 1;
    UNLOCK();
    *(ulonglong *)(param_2 + 0x78) = (ulonglong)(iVar3 + 1);
    *(int **)(param_2 + 0x90) = local_48;
    *(ulonglong *)(param_2 + 0x88) = (ulonglong)local_54;
    *(undefined8 *)(param_2 + 0x80) = 0;
    cVar8 = QueueRequest(*(longlong *)(lVar9 + 0x18),param_2);
    if (cVar8 == '\0') {
      *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
      *(undefined8 *)(param_2 + 0x38) = 0;
      CompleteSocketIrp(param_2);
    }
    uVar14 = 0x103;
  }
  else {
    uVar14 = 0xc0000008;
  }
  ObfDereferenceObject(lVar9);
  return uVar14;
}



===== DoSocketReadWrite @ 14000a4d4 =====

undefined8 DoSocketReadWrite(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  int *piVar2;
  int iVar3;
  longlong lVar4;
  char cVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  undefined8 uVar9;
  
  lVar4 = *(longlong *)(param_1 + 0x18);
  lVar8 = *(longlong *)(param_2 + 0xb8);
  lVar6 = GetSocketProcessReference(lVar4);
  lVar7 = PsGetCurrentProcessId();
  if (*(longlong *)(*(longlong *)(lVar6 + 0x18) + 8) == lVar7) {
    lVar8 = IoAllocateMdl(*(undefined8 *)(param_2 + 0x70),*(undefined4 *)(lVar8 + 8),0,1,0);
    *(longlong *)(param_2 + 8) = lVar8;
    if (lVar8 == 0) {
      uVar9 = 0xc000009a;
    }
    else {
      pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
      *pbVar1 = *pbVar1 | 1;
      LOCK();
      piVar2 = (int *)(lVar4 + 0x18);
      iVar3 = *piVar2;
      *piVar2 = *piVar2 + 1;
      UNLOCK();
      *(ulonglong *)(param_2 + 0x78) = (ulonglong)(iVar3 + 1);
      *(undefined8 *)(param_2 + 0x88) = 0;
      *(undefined8 *)(param_2 + 0x90) = 0;
      *(undefined8 *)(param_2 + 0x80) = 0;
      cVar5 = QueueRequest(*(longlong *)(lVar6 + 0x18),param_2);
      if (cVar5 == '\0') {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
        CompleteSocketIrp(param_2);
      }
      uVar9 = 0x103;
    }
  }
  else {
    uVar9 = 0xc0000008;
  }
  ObfDereferenceObject(lVar6);
  return uVar9;
}



===== SetSocketContext @ 14000a5e0 =====

/* WARNING: Type propagation algorithm not settling */

undefined1
SetSocketContext(longlong param_1,char param_2,ulonglong *param_3,uint param_4,undefined8 param_5,
                undefined8 param_6,int *param_7)

{
  longlong *******ppppppplVar1;
  longlong lVar2;
  longlong *******ppppppplVar3;
  code *pcVar4;
  ulonglong uVar5;
  longlong *******ppppppplVar6;
  char cVar7;
  undefined1 uVar8;
  int iVar9;
  longlong lVar10;
  int *piVar11;
  longlong *******ppppppplVar12;
  int *piVar13;
  undefined1 *puVar14;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [24];
  int **local_48;
  undefined8 local_40;
  ulonglong local_38;
  ulonglong local_30;
  longlong *******local_28;
  longlong *******local_20;
  
  piVar11 = param_7;
  param_7[2] = 0;
  param_7[3] = 0;
  lVar2 = *(longlong *)(param_1 + 0x18);
  cVar7 = IoIs32bitProcess(0);
  if (cVar7 == '\0') {
    if (param_4 < 0x10) goto LAB_14000a689;
    if ((param_2 != '\0') && (((ulonglong)param_3 & 3) != 0)) {
                    /* WARNING: Subroutine does not return */
      ExRaiseDatatypeMisalignment();
    }
    local_38 = param_3[1];
    local_30 = *param_3;
  }
  else {
    if (param_4 < 8) {
LAB_14000a689:
      *piVar11 = -0x3ffffff3;
      return 0;
    }
    if ((param_2 != '\0') && (((ulonglong)param_3 & 3) != 0)) {
                    /* WARNING: Subroutine does not return */
      ExRaiseDatatypeMisalignment();
    }
    local_38 = (ulonglong)*(int *)((longlong)param_3 + 4);
    local_30 = (ulonglong)(uint)*param_3;
  }
  uVar5 = local_30;
  param_7 = (int *)0x0;
  local_40 = 0;
  local_48 = &param_7;
  iVar9 = ObReferenceObjectByHandle(local_38,0x1f01ff,*(undefined8 *)IoFileObjectType_exref,param_2)
  ;
  piVar13 = param_7;
  *piVar11 = iVar9;
  if (iVar9 < 0) {
    uVar8 = 0;
  }
  else {
    lVar10 = IoGetRelatedDeviceObject(param_7);
    if (((lVar10 == DeviceObject) && (**(int **)(piVar13 + 6) == 0x636f7250)) &&
       (lVar10 = PsGetCurrentProcessId(), *(longlong *)(*(longlong *)(piVar13 + 6) + 8) == lVar10))
    {
      uVar8 = 1;
      piVar11 = (int *)SetSocketProcessReference(lVar2,piVar13,uVar5);
      puVar14 = auStack_68;
      if (piVar11 != piVar13) {
        local_20 = (longlong *******)&local_28;
        local_28 = (longlong *******)&local_28;
        CleanupQueuedRequests(*(longlong *)(piVar11 + 6),param_1,(longlong)&local_28);
        puVar14 = auStack_68;
        while (ppppppplVar6 = local_28, (longlong ********)local_28 != &local_28) {
          ppppppplVar3 = (longlong *******)*local_28;
          if (((longlong ********)local_28[1] != &local_28) ||
             ((longlong *******)ppppppplVar3[1] != local_28)) {
            pcVar4 = (code *)swi(0x29);
            (*pcVar4)(3);
            puVar14 = auStack_60;
            break;
          }
          ppppppplVar3[1] = (longlong ******)&local_28;
          ppppppplVar12 = local_28 + -0x15;
          ppppppplVar1 = local_28 + -0xf;
          local_28 = ppppppplVar3;
          *(undefined4 *)ppppppplVar1 = 0xc0000120;
          ppppppplVar6[-0xe] = (longlong ******)0x0;
          CompleteSocketIrp((longlong)ppppppplVar12);
        }
        piVar13 = piVar11;
      }
    }
    else {
      puVar14 = auStack_68;
      *piVar11 = -0x3ffffff3;
      uVar8 = 0;
    }
    *(undefined8 *)(puVar14 + -8) = 0x14000a818;
    ObfDereferenceObject(piVar13);
  }
  return uVar8;
}



===== SocketPnPTargetQuery @ 14000a85c =====

undefined8 SocketPnPTargetQuery(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  int *piVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  char cVar6;
  longlong lVar7;
  
  *(undefined8 *)(param_2 + 0x38) = 0;
  lVar4 = *(longlong *)(param_1 + 0x18);
  lVar5 = *(longlong *)(param_2 + 0xb8);
  lVar7 = GetSocketProcessReference(lVar4);
  pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
  *pbVar1 = *pbVar1 | 1;
  *(undefined8 *)(lVar5 + 0x20) = 0;
  *(undefined4 *)(lVar5 + 0x10) = 0;
  LOCK();
  piVar2 = (int *)(lVar4 + 0x18);
  iVar3 = *piVar2;
  *piVar2 = *piVar2 + 1;
  UNLOCK();
  *(undefined8 *)(param_2 + 0x90) = 0;
  *(undefined8 *)(param_2 + 0x88) = 0;
  *(undefined8 *)(param_2 + 0x80) = 0;
  *(ulonglong *)(param_2 + 0x78) = (ulonglong)(iVar3 + 1);
  cVar6 = QueueRequest(*(longlong *)(lVar7 + 0x18),param_2);
  if (cVar6 == '\0') {
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
    CompleteSocketIrp(param_2);
  }
  ObfDereferenceObject(lVar7);
  return 0x103;
}



===== entry @ 14000b010 =====

void entry(longlong param_1)

{
  __security_init_cookie();
  DriverEntry(param_1);
  return;
}



===== __security_init_cookie @ 14000b044 =====

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



===== DriverEntry @ 14000b078 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(longlong param_1)

{
  int iVar1;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  wil_InitializeFeatureStaging();
  RtlInitUnicodeString(&local_18,L"\\Device\\WS2IFSL");
  iVar1 = IoCreateDevice(param_1,0,&local_18,0x11,(_DAT_fffff780000002d0 & 0x10000) * 2,0,
                         &DeviceObject);
  if (iVar1 < 0) {
    if (g_wil_details_featureChangeNotification != 0) {
      RtlUnregisterFeatureConfigurationChangeNotification();
      g_wil_details_featureChangeNotification = 0;
    }
    if (g_wil_details_featureUsageProvider != 0) {
      RtlUnregisterFeatureUsageProvider();
      g_wil_details_featureUsageProvider = 0;
    }
    g_wil_details_isFeatureStagingInitialized = 0;
  }
  else {
    *(undefined1 *)(DeviceObject + 0x4c) = 1;
    *(code **)(param_1 + 0x70) = DispatchCreate;
    *(code **)(param_1 + 0x80) = DispatchClose;
    *(code **)(param_1 + 0x100) = DispatchCleanup;
    *(code **)(param_1 + 0x90) = DispatchReadWrite;
    *(code **)(param_1 + 0x88) = DispatchReadWrite;
    *(code **)(param_1 + 0xe0) = DispatchDeviceControl;
    *(code **)(param_1 + 0x148) = DispatchPnP;
    *(code **)(param_1 + 0x68) = DriverUnload;
    *(undefined **)(param_1 + 0x50) = &FastIoDispatchTable;
    iVar1 = 0;
  }
  return iVar1;
}



===== wil_InitializeFeatureStaging @ 14000b1cc =====

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
      if (*ppuVar3 != (undefined *)0x0) goto LAB_14000b253;
    }
LAB_14000b28d:
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
LAB_14000b253:
  if (ppuVar3 == (undefined **)0x0) goto LAB_14000b28d;
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
    goto LAB_14000b28d;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_140004c17 < ppuVar3) goto LAB_14000b28d;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14000b253;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14000b2e0 =====

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
            if (&UNK_140004c17 < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_14000b3ca;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_14000b3ca;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_14000b3ca:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_140004c17 < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}


