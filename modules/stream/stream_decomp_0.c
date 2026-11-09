
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



===== __C_specific_handler @ 1c000101d =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001c000101d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== KsDispatchInvalidDeviceRequest @ 1c0001030 =====

void KsDispatchInvalidDeviceRequest(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001c0001030. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  KsDispatchInvalidDeviceRequest();
  return;
}



===== KsDispatchFastIoDeviceControlFailure @ 1c0001050 =====

void KsDispatchFastIoDeviceControlFailure(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001c0001050. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  KsDispatchFastIoDeviceControlFailure();
  return;
}



===== KsDispatchFastReadFailure @ 1c0001070 =====

void KsDispatchFastReadFailure(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001c0001070. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  KsDispatchFastReadFailure();
  return;
}



===== RtlStringCbPrintfA @ 1c0001084 =====

undefined8 RtlStringCbPrintfA(char *param_1,longlong param_2,char *param_3,undefined8 param_4)

{
  ulonglong _Count;
  int iVar1;
  undefined8 uVar2;
  undefined8 local_res20;
  
  if (param_2 - 1U < 0x7fffffff) {
    _Count = param_2 - 1;
    uVar2 = 0;
    local_res20 = param_4;
    iVar1 = _vsnprintf(param_1,_Count,param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (_Count < (ulonglong)(longlong)iVar1)) {
      param_1[_Count] = '\0';
      uVar2 = 0x80000005;
    }
    else if ((longlong)iVar1 == _Count) {
      param_1[_Count] = '\0';
    }
  }
  else {
    uVar2 = 0xc000000d;
    if (param_2 != 0) {
      *param_1 = '\0';
    }
  }
  return uVar2;
}



===== SCAcquireReserveSrb @ 1c00010f8 =====

longlong SCAcquireReserveSrb(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  code *pcVar3;
  undefined1 uVar4;
  longlong lVar5;
  longlong *plVar6;
  
  lVar5 = 0;
  uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x4c8);
  plVar6 = (longlong *)(param_1 + 0x4b8);
  plVar1 = (longlong *)*plVar6;
  if (plVar1 != plVar6) {
    if (((longlong *)plVar1[1] != plVar6) ||
       (lVar2 = *plVar1, (longlong *)*(longlong *)(lVar2 + 8) != plVar1)) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3,uVar4);
      pcVar3 = (code *)swi(3);
      lVar5 = (*pcVar3)();
      return lVar5;
    }
    *plVar6 = lVar2;
    lVar5 = (longlong)(plVar1 + -0x27);
    *(longlong **)(lVar2 + 8) = plVar6;
  }
  KeReleaseSpinLock(param_1 + 0x4c8);
  if (lVar5 != 0) {
    *(longlong *)(lVar5 + 0x48) = param_2;
    *(longlong *)(param_2 + 0x78) = lVar5;
  }
  return lVar5;
}



===== _guard_check_icall @ 1c00011a0 =====

void _guard_check_icall(void)

{
                    /* 0x11a0  6  StreamClassDebugAssert
                       0x11a0  9  StreamClassFilterReenumerateStreams
                       0x11a0  18  StreamClassReenumerateStreams */
  return;
}



===== SCBeginUnsynchronizedMinidriverCallin @ 1c00011b0 =====

void SCBeginUnsynchronizedMinidriverCallin(longlong param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x240);
  *param_2 = uVar1;
  return;
}



===== SCCallBackSrb @ 1c00011dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SCCallBackSrb(longlong param_1,longlong param_2)

{
  undefined1 uVar1;
  
  if (*(char *)(param_2 + 800) != '\0') {
    uVar1 = KeAcquireSpinLockRaiseToDpc(param_2 + 0x240);
    if (*(int *)(param_1 + 0x164) != 0) {
      KeReleaseSpinLock();
      return;
    }
    KeReleaseSpinLock(param_2 + 0x240,uVar1);
  }
  (**(code **)(param_1 + 0x130))(param_1);
  return;
}



===== SCCancelOutstandingIrp @ 1c0001254 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SCCancelOutstandingIrp(longlong param_1,undefined8 *param_2)

{
  longlong lVar1;
  int *piVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong *plVar5;
  
  plVar5 = (longlong *)(param_1 + 0x270);
  if ((longlong *)*plVar5 != plVar5) {
    uVar4 = SCCheckRequestsForIrp(plVar5,param_2,'\0',param_1);
    if ((char)uVar4 != '\0') {
      lVar3 = param_2[0xf];
      if (*(char *)(param_1 + 800) == '\0') {
        (**(code **)(param_1 + 0x238))
                  (*(undefined8 *)(param_1 + 0x138),SCNotifyMinidriverCancel,lVar3);
      }
      else if ((*(uint *)(lVar3 + 0x80) & 1) != 0) {
        *(int *)(lVar3 + 0x164) = *(int *)(lVar3 + 0x164) + 1;
        lVar1 = param_1 + 0x240;
        KeReleaseSpinLockFromDpcLevel(lVar1);
        (**(code **)(*(longlong *)(param_1 + 0x210) + 0x18))(lVar3);
        KeAcquireSpinLockAtDpcLevel(lVar1);
        piVar2 = (int *)(lVar3 + 0x164);
        *piVar2 = *piVar2 + -1;
        if ((*piVar2 == 0) && ((*(uint *)(lVar3 + 0x80) & 1) == 0)) {
          KeReleaseSpinLockFromDpcLevel(lVar1);
          (**(code **)(lVar3 + 0x130))(lVar3);
          KeAcquireSpinLockAtDpcLevel(lVar1);
        }
      }
    }
  }
  return;
}



===== SCCheckRequestsForIrp @ 1c0001360 =====

ulonglong SCCheckRequestsForIrp
                    (undefined8 *param_1,undefined8 *param_2,char param_3,longlong param_4)

{
  undefined8 *puVar1;
  undefined8 *in_RAX;
  undefined8 *puVar2;
  
  puVar1 = (undefined8 *)*param_1;
  while( true ) {
    if (puVar1 == param_1) {
      return (ulonglong)in_RAX & 0xffffffffffffff00;
    }
    puVar2 = puVar1 + -0x15;
    if (param_3 == '\0') {
      puVar2 = (undefined8 *)puVar1[-0x1e];
    }
    if ((param_2 == (undefined8 *)0x0) && (*(char *)((longlong)puVar2 + 0x44) == '\0')) break;
    if (param_2 == puVar2) goto LAB_1c00013e1;
    puVar1 = (undefined8 *)*puVar1;
    in_RAX = puVar1;
  }
  KeReleaseSpinLockFromDpcLevel(param_4 + 0x240);
  IoCancelIrp(puVar2);
  in_RAX = (undefined8 *)KeAcquireSpinLockAtDpcLevel(param_4 + 0x240);
LAB_1c00013e1:
  return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
}



===== SCCompleteIrp @ 1c00013ec =====

undefined4 SCCompleteIrp(longlong param_1,undefined4 param_2,longlong param_3)

{
  int *piVar1;
  int iVar2;
  
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x30) = param_2;
    if ((int)*(char *)(param_1 + 0x43) < *(char *)(param_1 + 0x42) + 1) {
      IofCompleteRequest(param_1,0);
    }
    else {
      IoFreeIrp();
    }
  }
  LOCK();
  piVar1 = (int *)(param_3 + 0x348);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    KeSetEvent(param_3 + 0x308,0,0);
  }
  return param_2;
}



===== SCDequeueAndDeleteSrb @ 1c0001470 =====

ulonglong SCDequeueAndDeleteSrb(longlong param_1)

{
  longlong *plVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  code *pcVar6;
  undefined1 uVar7;
  ulonglong uVar8;
  
  lVar3 = *(longlong *)(param_1 + 0x18);
  uVar2 = *(uint *)(param_1 + 8);
  uVar7 = KeAcquireSpinLockRaiseToDpc(lVar3 + -0x290);
  plVar1 = (longlong *)(param_1 + 0x138);
  lVar4 = *plVar1;
  if ((*(longlong **)(lVar4 + 8) != plVar1) ||
     (plVar5 = *(longlong **)(param_1 + 0x140), (longlong *)*plVar5 != plVar1)) {
LAB_1c0001581:
    pcVar6 = (code *)swi(0x29);
    (*pcVar6)(3);
    pcVar6 = (code *)swi(3);
    uVar8 = (*pcVar6)();
    return uVar8;
  }
  *plVar5 = lVar4;
  *(longlong **)(lVar4 + 8) = plVar5;
  lVar4 = *(longlong *)(param_1 + 0x48);
  if (lVar4 != 0) {
    LOCK();
    *(undefined8 *)(lVar4 + 0x68) = 0;
    UNLOCK();
  }
  KeReleaseSpinLock(lVar3 + -0x290,CONCAT71((int7)((ulonglong)lVar4 >> 8),uVar7));
  if ((*(uint *)(param_1 + 0x80) & 2) == 0) {
    IoFreeMdl(*(undefined8 *)(param_1 + 0x90));
    ExFreePool(param_1);
  }
  else {
    *(undefined8 *)(param_1 + 0x48) = 0;
    uVar7 = KeAcquireSpinLockRaiseToDpc(lVar3 + -8);
    lVar4 = lVar3 + -0x18;
    plVar5 = *(longlong **)(lVar3 + -0x10);
    if (*plVar5 != lVar4) goto LAB_1c0001581;
    *plVar1 = lVar4;
    *(longlong **)(param_1 + 0x140) = plVar5;
    *plVar5 = (longlong)plVar1;
    *(longlong **)(lVar3 + -0x10) = plVar1;
    KeReleaseSpinLock(lVar3 + -8,CONCAT71((int7)((ulonglong)lVar4 >> 8),uVar7));
  }
  return (ulonglong)uVar2;
}



===== SCDequeueAndStartStreamDataRequest @ 1c0001590 =====

undefined8
SCDequeueAndStartStreamDataRequest
          (longlong param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  long lVar5;
  undefined8 uVar6;
  longlong *plVar7;
  undefined4 uVar8;
  bool bVar9;
  
  lVar2 = *(longlong *)(param_1 + 0x1e8);
  plVar3 = *(longlong **)(param_1 + 0x1a0);
  if ((*plVar3 != param_1 + 0x198) ||
     (plVar7 = (longlong *)plVar3[1], (longlong *)*plVar7 != plVar3)) {
LAB_1c00016ab:
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)(3);
    pcVar4 = (code *)swi(3);
    uVar6 = (*pcVar4)();
    return uVar6;
  }
  *(longlong **)(param_1 + 0x1a0) = plVar7;
  *plVar7 = param_1 + 0x198;
  *(undefined1 *)(param_1 + 0x259) = 0;
  LOCK();
  plVar3[-8] = (longlong)StreamClassCancelOutstandingIrp;
  UNLOCK();
  KeReleaseSpinLockFromDpcLevel(lVar2 + 0x240);
  plVar3 = (longlong *)plVar3[-6];
  if (*(char *)(param_1 + 0x168) == '\0') {
    SCStartMinidriverRequest(param_1,(longlong)plVar3,*(undefined8 *)(param_1 + 0x140));
  }
  else {
    bVar9 = *(int *)((longlong)plVar3 + 4) == 0;
    uVar8 = CONCAT31((int3)((uint)param_4 >> 8),bVar9);
    lVar5 = DMABuffer::StartMapping
                      ((DMABuffer *)(*(longlong *)(*(longlong *)(lVar2 + 0x120) + 0x40) + 0x158),
                       (DMATransfer *)(plVar3 + 0x13),*(_MDL **)(plVar3[9] + 8),bVar9);
    if (lVar5 < 0) {
      plVar7 = (longlong *)(lVar2 + 0x270);
      *(undefined4 *)(plVar3 + 1) = 0xc000009a;
      lVar2 = *plVar7;
      plVar1 = plVar3 + 0x27;
      if (*(longlong **)(lVar2 + 8) != plVar7) goto LAB_1c00016ab;
      *plVar1 = lVar2;
      plVar3[0x28] = (longlong)plVar7;
      *(longlong **)(lVar2 + 8) = plVar1;
      *plVar7 = (longlong)plVar1;
      plVar7 = plVar3;
      StreamClassStreamNotification(3,plVar3[2],plVar3,uVar8);
      StreamClassStreamNotification(0,plVar3[2],plVar7,uVar8);
    }
  }
  return 0x103;
}



===== SCDummyMinidriverRoutine @ 1c00016c0 =====

undefined1 SCDummyMinidriverRoutine(void)

{
  return 1;
}



===== SCEnableDeviceEventSynchronized @ 1c00016d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong SCEnableDeviceEventSynchronized(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong lVar4;
  code *pcVar5;
  uint uVar6;
  ulonglong uVar7;
  
  lVar2 = *(longlong *)(param_1 + 0x28);
  plVar3 = *(longlong **)(param_1 + 8);
  uVar7 = 0;
  plVar1 = (longlong *)(lVar2 + -0x50);
  lVar4 = *plVar1;
  if (*(longlong **)(lVar4 + 8) != plVar1) {
LAB_1c000173e:
    pcVar5 = (code *)swi(0x29);
    (*pcVar5)(3);
    pcVar5 = (code *)swi(3);
    uVar7 = (*pcVar5)();
    return uVar7;
  }
  *plVar3 = lVar4;
  plVar3[1] = (longlong)plVar1;
  *(longlong **)(lVar4 + 8) = plVar3;
  *plVar1 = (longlong)plVar3;
  pcVar5 = *(code **)(lVar2 + -0x40);
  if (pcVar5 != (code *)0x0) {
    uVar6 = (*pcVar5)(param_1);
    uVar7 = (ulonglong)uVar6;
    if ((int)uVar6 < 0) {
      plVar1 = *(longlong **)(param_1 + 8);
      lVar2 = *plVar1;
      if ((*(longlong **)(lVar2 + 8) != plVar1) ||
         (plVar3 = (longlong *)plVar1[1], (longlong *)*plVar3 != plVar1)) goto LAB_1c000173e;
      *plVar3 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar3;
    }
  }
  return uVar7;
}



===== SCEnableEventSynchronized @ 1c0001750 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong SCEnableEventSynchronized(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong lVar4;
  code *pcVar5;
  uint uVar6;
  ulonglong uVar7;
  
  lVar2 = *(longlong *)(param_1 + 0x18);
  plVar3 = *(longlong **)(param_1 + 8);
  uVar7 = 0;
  plVar1 = (longlong *)(lVar2 + 0xa8);
  lVar4 = *plVar1;
  if (*(longlong **)(lVar4 + 8) != plVar1) {
LAB_1c00017c1:
    pcVar5 = (code *)swi(0x29);
    (*pcVar5)(3);
    pcVar5 = (code *)swi(3);
    uVar7 = (*pcVar5)();
    return uVar7;
  }
  *plVar3 = lVar4;
  plVar3[1] = (longlong)plVar1;
  *(longlong **)(lVar4 + 8) = plVar3;
  *plVar1 = (longlong)plVar3;
  pcVar5 = *(code **)(lVar2 + 0x58);
  if (pcVar5 != (code *)0x0) {
    uVar6 = (*pcVar5)(param_1);
    uVar7 = (ulonglong)uVar6;
    if ((int)uVar6 < 0) {
      plVar1 = *(longlong **)(param_1 + 8);
      lVar2 = *plVar1;
      if ((*(longlong **)(lVar2 + 8) != plVar1) ||
         (plVar3 = (longlong *)plVar1[1], (longlong *)*plVar3 != plVar1)) goto LAB_1c00017c1;
      *plVar3 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar3;
    }
  }
  return uVar7;
}



===== SCEndSynchronizedMinidriverDeviceCallin @ 1c00017d0 =====

void SCEndSynchronizedMinidriverDeviceCallin(longlong param_1)

{
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 1;
  return;
}



===== SCEndSynchronizedMinidriverStreamCallin @ 1c00017e0 =====

void SCEndSynchronizedMinidriverStreamCallin(longlong param_1)

{
  SCRequestDpcForStream(param_1);
  return;
}



===== SCEndUnsynchronizedMinidriverDeviceCallin @ 1c0001800 =====

void SCEndUnsynchronizedMinidriverDeviceCallin(longlong param_1,undefined1 *param_2)

{
  KeReleaseSpinLockFromDpcLevel();
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 1;
  StreamClassDpc(0,*(longlong *)(param_1 + 0x120),0,0);
  KeLowerIrql(*param_2);
  return;
}



===== SCEndUnsynchronizedMinidriverStreamCallin @ 1c0001860 =====

void SCEndUnsynchronizedMinidriverStreamCallin(ulonglong param_1,undefined1 *param_2)

{
  KeReleaseSpinLockFromDpcLevel(*(longlong *)(param_1 + 0x1e8) + 0x240);
  SCRequestDpcForStream(param_1);
  StreamClassDpc(0,*(longlong *)(*(longlong *)(param_1 + 0x1e8) + 0x120),0,param_1);
  KeLowerIrql(*param_2);
  return;
}



===== SCErrorDataSRB @ 1c00018d0 =====

void SCErrorDataSRB(longlong param_1,undefined8 param_2,longlong *param_3,undefined4 param_4)

{
  *(undefined4 *)(param_1 + 8) = 0xc00000bb;
  StreamClassStreamNotification(3,*(longlong *)(param_1 + 0x10),param_3,param_4);
  StreamClassStreamNotification(0,*(longlong *)(param_1 + 0x10),param_3,param_4);
  return;
}



===== SCFreeDeadEvents @ 1c0001910 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SCFreeDeadEvents(longlong ****param_1)

{
  longlong *******ppppppplVar1;
  code *pcVar2;
  undefined1 uVar3;
  longlong *******local_18;
  undefined8 local_10;
  
  local_10 = 0;
  local_18 = (longlong *******)param_1;
  uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x48);
  (*(code *)param_1[0x47])(param_1[0x27],SCGetDeadListSynchronized,&local_18);
  KeReleaseSpinLock(param_1 + 0x48,uVar3);
  do {
    if ((longlong ********)local_18 == &local_18) {
LAB_1c00019ba:
      *(undefined1 *)((longlong)param_1 + 0x419) = 0;
      return;
    }
    if (((longlong ********)local_18[1] != &local_18) ||
       (ppppppplVar1 = (longlong *******)*local_18, (longlong *******)ppppppplVar1[1] != local_18))
    {
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(3);
      goto LAB_1c00019ba;
    }
    ppppppplVar1[1] = (longlong ******)&local_18;
    local_18 = ppppppplVar1;
    KsDiscardEvent();
  } while( true );
}



===== SCGetDeadListSynchronized @ 1c00019e0 =====

void SCGetDeadListSynchronized(longlong *param_1)

{
  longlong lVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  longlong lVar4;
  code *pcVar5;
  longlong *plVar6;
  
  lVar1 = *param_1;
  plVar6 = (longlong *)(lVar1 + 0x388);
  param_1[1] = (longlong)param_1;
  *param_1 = (longlong)param_1;
  do {
    if ((longlong *)*plVar6 == plVar6) {
LAB_1c0001a2e:
      plVar6[1] = (longlong)plVar6;
      *plVar6 = (longlong)plVar6;
      return;
    }
    plVar2 = *(longlong **)(lVar1 + 0x390);
    if (((longlong *)*plVar2 != plVar6) ||
       (puVar3 = (undefined8 *)plVar2[1], (longlong *)*puVar3 != plVar2)) {
LAB_1c0001a27:
      pcVar5 = (code *)swi(0x29);
      plVar6 = (longlong *)(*pcVar5)(3);
      goto LAB_1c0001a2e;
    }
    *(undefined8 **)(lVar1 + 0x390) = puVar3;
    *puVar3 = plVar6;
    lVar4 = *param_1;
    if (*(longlong **)(lVar4 + 8) != param_1) goto LAB_1c0001a27;
    *plVar2 = lVar4;
    plVar2[1] = (longlong)param_1;
    *(longlong **)(lVar4 + 8) = plVar2;
    *param_1 = (longlong)plVar2;
  } while( true );
}



===== SCGetInterruptState @ 1c0001a40 =====

undefined8 SCGetInterruptState(longlong *param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  bool bVar5;
  
  lVar1 = param_1[1];
  lVar2 = *(longlong *)(lVar1 + 0x2e0);
  *param_1 = lVar2;
  if (lVar2 != 0) {
    uVar3 = *(undefined8 *)(lVar2 + 0x18);
    *(undefined1 *)(lVar2 + 0x25a) = 0;
    puVar4 = (undefined8 *)param_1[2];
    *puVar4 = *(undefined8 *)(lVar2 + 0x10);
    puVar4[1] = uVar3;
    uVar3 = *(undefined8 *)(lVar2 + 0x28);
    puVar4[2] = *(undefined8 *)(lVar2 + 0x20);
    puVar4[3] = uVar3;
    uVar3 = *(undefined8 *)(lVar2 + 0x38);
    puVar4[4] = *(undefined8 *)(lVar2 + 0x30);
    puVar4[5] = uVar3;
    uVar3 = *(undefined8 *)(lVar2 + 0x48);
    puVar4[6] = *(undefined8 *)(lVar2 + 0x40);
    puVar4[7] = uVar3;
    uVar3 = *(undefined8 *)(lVar2 + 0x58);
    puVar4[8] = *(undefined8 *)(lVar2 + 0x50);
    puVar4[9] = uVar3;
    puVar4[10] = *(undefined8 *)(lVar2 + 0x60);
    *(undefined4 *)(lVar2 + 0x10) = 0;
    *(undefined8 *)(lVar2 + 0x20) = 0;
    *(undefined8 *)(lVar1 + 0x2e0) = *(undefined8 *)(lVar2 + 0x1f0);
    *(undefined8 *)(lVar2 + 0x1f0) = 0;
  }
  puVar4 = (undefined8 *)(ulonglong)*(uint *)(lVar1 + 0x10);
  bVar5 = (*(uint *)(lVar1 + 0x10) & 1) != 0;
  if (bVar5) {
    uVar3 = *(undefined8 *)(lVar1 + 0x18);
    puVar4 = (undefined8 *)param_1[3];
    *puVar4 = *(undefined8 *)(lVar1 + 0x10);
    puVar4[1] = uVar3;
    uVar3 = *(undefined8 *)(lVar1 + 0x28);
    puVar4[2] = *(undefined8 *)(lVar1 + 0x20);
    puVar4[3] = uVar3;
    uVar3 = *(undefined8 *)(lVar1 + 0x38);
    puVar4[4] = *(undefined8 *)(lVar1 + 0x30);
    puVar4[5] = uVar3;
    uVar3 = *(undefined8 *)(lVar1 + 0x48);
    puVar4[6] = *(undefined8 *)(lVar1 + 0x40);
    puVar4[7] = uVar3;
    uVar3 = *(undefined8 *)(lVar1 + 0x58);
    puVar4[8] = *(undefined8 *)(lVar1 + 0x50);
    puVar4[9] = uVar3;
    puVar4[10] = *(undefined8 *)(lVar1 + 0x60);
    *(undefined4 *)(lVar1 + 0x10) = 0;
    *(undefined8 *)(lVar1 + 0x20) = 0;
  }
  return CONCAT71((int7)((ulonglong)puVar4 >> 8),bVar5 || lVar2 != 0);
}



===== SCGetPhysicalTime @ 1c0001b10 =====

undefined8 SCGetPhysicalTime(longlong param_1)

{
  longlong local_38;
  longlong local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  
  local_14 = 0;
  local_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  local_30 = *(longlong *)(*(longlong *)(param_1 + 0x18) + 0x10) + 0x130;
  local_38 = *(longlong *)
              (*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x18) + 0x10) + 0x1e8) + 0x220);
  local_28 = 1;
  SCMinidriverTimeFunction(&local_38);
  return CONCAT44(uStack_1c,uStack_20);
}



===== SCGetStreamTime @ 1c0001b70 =====

undefined8 SCGetStreamTime(longlong param_1)

{
  longlong local_38;
  longlong local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  
  local_14 = 0;
  local_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  local_30 = *(longlong *)(*(longlong *)(param_1 + 0x18) + 0x10) + 0x130;
  local_38 = *(longlong *)
              (*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x18) + 0x10) + 0x1e8) + 0x220);
  local_28 = 0;
  SCMinidriverTimeFunction(&local_38);
  return CONCAT44(uStack_1c,uStack_20);
}



===== SCGetSynchronizedTime @ 1c0001bd0 =====

undefined8 SCGetSynchronizedTime(longlong param_1,undefined8 *param_2)

{
  longlong local_38;
  longlong local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_14 = 0;
  local_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  local_30 = *(longlong *)(*(longlong *)(param_1 + 0x18) + 0x10) + 0x130;
  local_38 = *(longlong *)
              (*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x18) + 0x10) + 0x1e8) + 0x220);
  local_28 = 0;
  SCMinidriverTimeFunction(&local_38);
  *param_2 = CONCAT44(uStack_14,uStack_18);
  return CONCAT44(uStack_1c,uStack_20);
}



===== SCInsertFiltersInDevice @ 1c0001c3c =====

void SCInsertFiltersInDevice(longlong param_1,longlong param_2)

{
  code *pcVar1;
  undefined1 uVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined1 *puVar5;
  longlong *plVar6;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_2 + 0x240);
  puVar5 = auStack_28;
  plVar6 = (longlong *)(param_2 + 0x2c8);
  plVar4 = (longlong *)(param_1 + 0x10);
  lVar3 = *plVar6;
  if (*(longlong **)(lVar3 + 8) != plVar6) {
    lVar3 = 3;
    pcVar1 = (code *)swi(0x29);
    uVar2 = (*pcVar1)();
    puVar5 = auStack_20;
  }
  *plVar4 = lVar3;
  *(longlong **)(param_1 + 0x18) = plVar6;
  *(longlong **)(lVar3 + 8) = plVar4;
  *plVar6 = (longlong)plVar4;
  *(undefined8 *)(puVar5 + -8) = 0x1c0001c9c;
  KeReleaseSpinLock(param_2 + 0x240,uVar2);
  return;
}



===== SCInsertStreamInFilter @ 1c0001cb8 =====

void SCInsertStreamInFilter(longlong param_1,longlong param_2)

{
  code *pcVar1;
  undefined1 uVar2;
  longlong *plVar3;
  longlong *plVar4;
  undefined1 *puVar5;
  longlong lVar6;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_2 + 0x240);
  puVar5 = auStack_28;
  plVar3 = (longlong *)(param_1 + 0x1c8);
  plVar4 = (longlong *)(*(longlong *)(param_1 + 0x128) + 0x20);
  lVar6 = *plVar4;
  if (*(longlong **)(lVar6 + 8) != plVar4) {
    plVar3 = (longlong *)0x3;
    pcVar1 = (code *)swi(0x29);
    uVar2 = (*pcVar1)();
    puVar5 = auStack_20;
  }
  plVar3[1] = (longlong)plVar4;
  *plVar3 = lVar6;
  *(longlong **)(lVar6 + 8) = plVar3;
  *plVar4 = (longlong)plVar3;
  *(undefined8 *)(puVar5 + -8) = 0x1c0001d17;
  KeReleaseSpinLock(param_2 + 0x240,uVar2);
  return;
}



===== SCIssueRequestToDevice @ 1c0001d30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
SCIssueRequestToDevice
          (longlong param_1,ulonglong param_2,longlong *param_3,undefined *param_4,longlong *param_5
          ,undefined8 *param_6)

{
  longlong lVar1;
  longlong *plVar2;
  int *piVar3;
  longlong lVar4;
  longlong *plVar5;
  code *pcVar6;
  undefined3 uVar7;
  undefined1 uVar8;
  long lVar9;
  undefined8 uVar10;
  undefined4 uVar11;
  undefined *puVar12;
  bool bVar13;
  
  lVar1 = param_1 + 0x240;
  puVar12 = param_4;
  uVar8 = KeAcquireSpinLockRaiseToDpc(lVar1);
  if (*(char *)(param_1 + 800) == '\0') {
    lVar4 = *param_5;
    plVar2 = param_6 + 0x15;
    if (*(longlong **)(lVar4 + 8) == param_5) {
      param_6[0x16] = param_5;
      *plVar2 = lVar4;
      *(longlong **)(lVar4 + 8) = plVar2;
      *param_5 = (longlong)plVar2;
      LOCK();
      param_6[0xd] = StreamClassCancelPendingIrp;
      UNLOCK();
      if (*(char *)((longlong)param_6 + 0x44) == '\0') {
        KeReleaseSpinLockFromDpcLevel();
        StreamClassDpc(0,*(longlong *)(param_1 + 0x120),param_6,param_2);
        KeLowerIrql(uVar8);
        return 0x103;
      }
      LOCK();
      lVar4 = param_6[0xd];
      param_6[0xd] = 0;
      UNLOCK();
      if (lVar4 == 0) goto LAB_1c0002029;
      plVar2 = param_3 + 0x27;
      lVar4 = *plVar2;
      if ((*(longlong **)(lVar4 + 8) == plVar2) &&
         (plVar5 = (longlong *)param_3[0x28], (longlong *)*plVar5 == plVar2)) {
        *plVar5 = lVar4;
        *(longlong **)(lVar4 + 8) = plVar5;
        KeReleaseSpinLock(lVar1,CONCAT71((int7)((ulonglong)lVar4 >> 8),uVar8));
        IoFreeMdl(param_3[0x12]);
        ExFreePool(param_3);
        return 0xc0000120;
      }
    }
  }
  else {
    *(uint *)(param_3 + 0x10) = *(uint *)(param_3 + 0x10) | 1;
    plVar2 = (longlong *)(param_1 + 0x270);
    *(int *)((longlong)param_3 + 0x164) = *(int *)((longlong)param_3 + 0x164) + 1;
    plVar5 = param_3 + 0x27;
    lVar4 = *plVar2;
    if (*(longlong **)(lVar4 + 8) == plVar2) {
      *plVar5 = lVar4;
      param_3[0x28] = (longlong)plVar2;
      *(longlong **)(lVar4 + 8) = plVar5;
      *plVar2 = (longlong)plVar5;
      KeReleaseSpinLock(lVar1,CONCAT71((int7)((ulonglong)lVar4 >> 8),uVar8));
      if (((param_2 != 0) && (*(char *)(param_2 + 0x168) != '\0')) &&
         ((*(uint *)(param_3 + 10) & 1) != 0)) {
        KeInitializeEvent(param_3 + 0x2d,1);
        uVar8 = KfRaiseIrql(2);
        bVar13 = *(int *)((longlong)param_3 + 4) == 0;
        uVar11 = (undefined4)CONCAT71((int7)((ulonglong)puVar12 >> 8),bVar13);
        lVar9 = DMABuffer::StartMapping
                          ((DMABuffer *)
                           (*(longlong *)(*(longlong *)(param_1 + 0x120) + 0x40) + 0x158),
                           (DMATransfer *)(param_3 + 0x13),*(_MDL **)(param_3[9] + 8),bVar13);
        if (lVar9 < 0) {
          *(undefined4 *)(param_3 + 1) = 0xc000009a;
          KeLowerIrql();
          StreamClassStreamNotification(3,param_3[2],param_3,uVar11);
          return 0x103;
        }
        KeLowerIrql(uVar8);
        KeWaitForSingleObject(param_3 + 0x2d,0,0,0,0);
      }
      (*(code *)param_4)(param_3);
      uVar8 = KeAcquireSpinLockRaiseToDpc(lVar1);
      piVar3 = (int *)((longlong)param_3 + 0x164);
      *piVar3 = *piVar3 + -1;
      if (*piVar3 == 0) {
        uVar7 = (undefined3)(*(uint *)(param_3 + 0x10) >> 8);
        if ((*(uint *)(param_3 + 0x10) & 1) == 0) {
          KeReleaseSpinLock(lVar1,CONCAT31(uVar7,uVar8));
          (*(code *)param_3[0x26])(param_3);
          return 0x103;
        }
        LOCK();
        param_6[0xd] = StreamClassCancelOutstandingIrp;
        UNLOCK();
        if (*(char *)((longlong)param_6 + 0x44) != '\0') {
          LOCK();
          lVar4 = param_6[0xd];
          param_6[0xd] = 0;
          UNLOCK();
          if (lVar4 != 0) {
            KeReleaseSpinLock(lVar1,CONCAT31(uVar7,uVar8));
            IoAcquireCancelSpinLock((longlong)param_6 + 0x45);
            StreamClassCancelOutstandingIrp(*(longlong *)(param_1 + 0x120),param_6);
            return 0x103;
          }
        }
      }
LAB_1c0002029:
      KeReleaseSpinLock(lVar1,uVar8);
      return 0x103;
    }
  }
  pcVar6 = (code *)swi(0x29);
  (*pcVar6)(3);
  pcVar6 = (code *)swi(3);
  uVar10 = (*pcVar6)();
  return uVar10;
}



===== SCMinidriverDeviceTimerDpc @ 1c0002090 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SCMinidriverDeviceTimerDpc(undefined8 param_1,longlong param_2)

{
  KeAcquireSpinLockAtDpcLevel(param_2 + 0x240);
  if (*(longlong *)(param_2 + 0x68) != 0) {
    (**(code **)(param_2 + 0x238))(*(undefined8 *)(param_2 + 0x138));
  }
  KeReleaseSpinLockFromDpcLevel();
  StreamClassDpc(0,*(longlong *)(param_2 + 0x120),0,0);
  return;
}



===== SCMinidriverStreamTimerDpc @ 1c0002110 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SCMinidriverStreamTimerDpc(undefined8 param_1,ulonglong param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_2 + 0x1e8);
  if (*(char *)(lVar1 + 800) == '\0') {
    KeAcquireSpinLockAtDpcLevel();
  }
  if (*(longlong *)(param_2 + 0x68) != 0) {
    (**(code **)(lVar1 + 0x238))();
  }
  if (*(char *)(lVar1 + 800) == '\0') {
    KeReleaseSpinLockFromDpcLevel();
  }
  StreamClassDpc(0,*(longlong *)(lVar1 + 0x120),0,param_2);
  return;
}



===== SCMinidriverTimeFunction @ 1c00021ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SCMinidriverTimeFunction(longlong *param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 uVar3;
  
  lVar1 = *param_1;
  lVar2 = param_1[1];
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1 + -0x290);
  (**(code **)(lVar1 + -0x298))
            (*(undefined8 *)(lVar1 + -0x398),*(undefined8 *)(lVar2 + 0x20),param_1);
  KeReleaseSpinLock(lVar1 + -0x290,uVar3);
  return;
}



===== SCNotifyMinidriverCancel @ 1c0002240 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SCNotifyMinidriverCancel(longlong param_1)

{
  if ((*(uint *)(param_1 + 0x80) & 1) != 0) {
    (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0x18) + -0x2c0) + 0x18))();
  }
  return;
}



===== SCProcessCompletedDataRequest @ 1c0002270 =====

void SCProcessCompletedDataRequest(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  longlong lVar6;
  
  lVar1 = *(longlong *)(param_1 + 0x48);
  uVar4 = 0;
  lVar2 = *(longlong *)(param_1 + 0x18);
  if (lVar1 != 0) {
    lVar6 = *(longlong *)(param_1 + 0x28);
    lVar3 = *(longlong *)(lVar1 + 0xb8);
    for (puVar5 = *(undefined8 **)(lVar1 + 8); puVar5 != (undefined8 *)0x0;
        puVar5 = (undefined8 *)*puVar5) {
      if (*(char *)(*(longlong *)(param_1 + 0x10) + 0x39) != '\0') {
        for (; (*(int *)(lVar6 + 0x24) == 0 && (*(int *)(lVar6 + 0x20) == 0));
            lVar6 = lVar6 + (ulonglong)*(uint *)(param_1 + 0x160)) {
        }
        if (*(char *)(param_1 + 0x180) != '\0') {
          *(undefined8 *)(lVar6 + 0x28) =
               *(undefined8 *)(*(longlong *)(param_1 + 0x188) + uVar4 * 8);
        }
        uVar4 = (ulonglong)((int)uVar4 + 1);
        lVar6 = lVar6 + (ulonglong)*(uint *)(param_1 + 0x160);
        if (*(int *)(param_1 + 4) == 0) {
          KeFlushIoBuffers(puVar5,1,0);
        }
      }
    }
    DMABuffer::DoneMapping((DMABuffer *)(lVar2 + -0x378),(DMATransfer *)(param_1 + 0x98));
    if (*(longlong *)(lVar3 + 0x20) != 0) {
      ExFreePool();
    }
  }
  SCProcessCompletedRequest(param_1);
  return;
}



===== SCProcessCompletedMethodRequest @ 1c0002370 =====

void SCProcessCompletedMethodRequest(longlong param_1)

{
  ExFreePool(*(undefined8 *)(param_1 + 0x28));
  *(ulonglong *)(*(longlong *)(param_1 + 0x48) + 0x38) = (ulonglong)*(uint *)(param_1 + 0x60);
  SCDequeueAndDeleteSrb(param_1);
  return;
}



===== SCProcessCompletedRequest @ 1c00023b0 =====

void SCProcessCompletedRequest(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x48);
  lVar2 = *(longlong *)(param_1 + 0x18);
  uVar3 = SCDequeueAndDeleteSrb(param_1);
  SCCompleteIrp(lVar1,(int)uVar3,lVar2 + -0x4d0);
  return;
}



===== SCProcessPriorityChangeRequest @ 1c00023ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SCProcessPriorityChangeRequest(longlong param_1,longlong param_2,longlong param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  if (*(int *)(param_2 + 0x38) == 1) {
    KeAcquireSpinLockAtDpcLevel(param_3 + 0x240);
    (**(code **)(param_2 + 0x30))(*(undefined8 *)(param_2 + 0x40));
    if (((*(uint *)(param_1 + 0x10) & 4) != 0) && (*(int *)(param_1 + 0x48) == 0)) {
      *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xfffffffb;
      (**(code **)(param_3 + 0x238))
                (*(undefined8 *)(param_3 + 0x138),*(undefined8 *)(param_1 + 0x40),
                 *(undefined8 *)(param_1 + 0x50));
    }
    KeReleaseSpinLockFromDpcLevel(param_3 + 0x240);
  }
  else if (*(int *)(param_2 + 0x38) == 2) {
    uVar1 = *(undefined8 *)(param_2 + 0x40);
    uVar2 = *(undefined8 *)(param_2 + 0x30);
    *(undefined8 *)(param_1 + 0xf8) = 0;
    *(undefined8 *)(param_1 + 0x108) = uVar2;
    *(undefined8 *)(param_1 + 0x110) = uVar1;
    ExQueueWorkItem();
  }
  return;
}



===== SCProcessTimerRequest @ 1c00024c0 =====

void SCProcessTimerRequest(longlong param_1,longlong param_2)

{
  *(undefined8 *)(param_1 + 0x68) = *(undefined8 *)(param_2 + 0x18);
  *(undefined8 *)(param_1 + 0x70) = *(undefined8 *)(param_2 + 0x28);
  if (*(int *)(param_2 + 0x20) == 0) {
    KeCancelTimer(param_1 + 0x78);
  }
  else {
    KeSetTimer(param_1 + 0x78,CONCAT44(0xffffffff,*(int *)(param_2 + 0x20) * -10),param_1 + 0xb8);
  }
  return;
}



===== SCReferenceSwEnumDriver @ 1c0002524 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SCReferenceSwEnumDriver(longlong param_1,char param_2)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  code *pcVar5;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  local_38 = 0;
  uStack_30 = 0;
  lVar3 = ExAllocatePoolWithTag(0x200,0x38,0x736c4353);
  if (lVar3 == 0) {
    iVar2 = -0x3fffff66;
  }
  else {
    KeInitializeEvent(&local_28,1);
    lVar4 = IoBuildSynchronousFsdRequest
                      (0x1b,*(undefined8 *)(param_1 + 0x128),0,0,0,&local_28,&local_38);
    if (lVar4 == 0) {
      iVar2 = -0x3fffff66;
    }
    else {
      lVar1 = *(longlong *)(lVar4 + 0xb8);
      *(undefined1 *)(lVar4 + 0x40) = 0;
      *(undefined4 *)(lVar4 + 0x30) = 0xc00000bb;
      *(undefined8 *)(lVar1 + -0x28) = 0;
      *(undefined8 **)(lVar1 + -0x40) = &KSMEDIUMSETID_Standard;
      *(undefined1 *)(lVar1 + -0x47) = 8;
      *(undefined4 *)(lVar1 + -0x38) = 0x1000038;
      *(longlong *)(lVar1 + -0x30) = lVar3;
      iVar2 = IofCallDriver(*(undefined8 *)(param_1 + 0x128),lVar4);
      if (iVar2 == 0x103) {
        KeWaitForSingleObject(&local_28,0,0,0,0);
        iVar2 = (int)local_38;
      }
      if (-1 < iVar2) {
        if (param_2 == '\0') {
          pcVar5 = *(code **)(lVar3 + 0x28);
        }
        else {
          pcVar5 = *(code **)(lVar3 + 0x20);
        }
        (*pcVar5)(*(undefined8 *)(lVar3 + 8));
      }
    }
    ExFreePool(lVar3);
  }
  return iVar2;
}



===== SCSignalSRBEvent @ 1c00026a0 =====

void SCSignalSRBEvent(longlong param_1)

{
  KeSetEvent(param_1 + 0x148,0,0);
  return;
}



===== SCStartMinidriverRequest @ 1c00026c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SCStartMinidriverRequest(longlong param_1,longlong param_2,undefined8 param_3)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  code *pcVar4;
  longlong *plVar5;
  longlong *plVar6;
  longlong lVar7;
  undefined1 *puVar8;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  lVar1 = *(longlong *)(param_1 + 0x1e8);
  lVar2 = *(longlong *)(param_2 + 0x48);
  *(uint *)(param_2 + 0x80) = *(uint *)(param_2 + 0x80) | 1;
  KeAcquireSpinLockAtDpcLevel(lVar1 + 0x240);
  puVar8 = auStack_28;
  plVar5 = (longlong *)(lVar1 + 0x270);
  lVar7 = *plVar5;
  plVar6 = (longlong *)(param_2 + 0x138);
  if (*(longlong **)(lVar7 + 8) != plVar5) {
    plVar6 = (longlong *)0x3;
    pcVar4 = (code *)swi(0x29);
    plVar5 = (longlong *)(*pcVar4)();
    puVar8 = auStack_20;
  }
  *plVar6 = lVar7;
  plVar6[1] = (longlong)plVar5;
  *(longlong **)(lVar7 + 8) = plVar6;
  *plVar5 = (longlong)plVar6;
  LOCK();
  *(code **)(lVar2 + 0x68) = StreamClassCancelOutstandingIrp;
  UNLOCK();
  pcVar4 = *(code **)(lVar1 + 0x238);
  uVar3 = *(undefined8 *)(lVar1 + 0x138);
  *(undefined8 *)(puVar8 + -8) = 0x1c000275f;
  (*pcVar4)(uVar3,param_3,param_2);
  *(undefined8 *)(puVar8 + -8) = 0x1c0002769;
  KeReleaseSpinLockFromDpcLevel(lVar1 + 0x240);
  return;
}



===== SCStartRequestOnStream @ 1c0002790 =====

void SCStartRequestOnStream(longlong param_1,longlong param_2,undefined8 param_3,undefined4 param_4)

{
  longlong *plVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined1 *puVar4;
  undefined8 *puVar5;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  puVar5 = (undefined8 *)(param_2 + 0x240);
  KeAcquireSpinLockAtDpcLevel(puVar5);
  if ((*(char *)(param_1 + 0x259) != '\0') &&
     (*(longlong **)(param_1 + 0x198) != (longlong *)(param_1 + 0x198))) {
    SCDequeueAndStartStreamDataRequest(param_1,param_2,param_3,param_4);
    KeAcquireSpinLockAtDpcLevel(puVar5);
  }
  puVar4 = auStack_28;
  if ((*(char *)(param_1 + 600) != '\0') &&
     (plVar1 = (longlong *)(param_1 + 0x1a8), puVar4 = auStack_28, (longlong *)*plVar1 != plVar1)) {
    puVar5 = *(undefined8 **)(param_1 + 0x1b0);
    if (((longlong *)*puVar5 == plVar1) &&
       (plVar2 = (longlong *)puVar5[1], (undefined8 *)*plVar2 == puVar5)) {
      *(longlong **)(param_1 + 0x1b0) = plVar2;
      *plVar2 = (longlong)plVar1;
      *(undefined1 *)(param_1 + 600) = 0;
      KeReleaseSpinLockFromDpcLevel(*(longlong *)(param_1 + 0x1e8) + 0x240);
      SCStartMinidriverRequest(param_1,puVar5[-6],*(undefined8 *)(param_1 + 0x148));
      return;
    }
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(3);
    puVar4 = auStack_20;
  }
  *(undefined8 *)(puVar4 + -8) = 0x1c0002854;
  KeReleaseSpinLockFromDpcLevel(puVar5);
  return;
}



===== SCSubmitIdleNotification @ 1c000286c =====

void SCSubmitIdleNotification(longlong param_1,byte param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  char local_res8 [8];
  ulonglong local_res18;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_res8[0] = '\0';
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  local_38 = 0;
  uStack_30 = 0;
  puVar1 = (undefined8 *)
           IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 0x120) >> 8),
                                  *(undefined1 *)(*(longlong *)(param_1 + 0x120) + 0x4c)),0);
  if (puVar1 != (undefined8 *)0x0) {
    *(undefined2 *)(puVar1[0x17] + -0x48) = 0x61b;
    puVar1[9] = &local_38;
    puVar1[10] = &local_28;
    LOCK();
    *(int *)(param_1 + 0x348) = *(int *)(param_1 + 0x348) + 1;
    UNLOCK();
    local_res18 = (ulonglong)param_2;
    uVar2 = SCSubmitRequest(0x111,local_res18,0,SCProcessCompletedRequest,param_1,0,0,puVar1,
                            local_res8,(longlong *)(param_1 + 0x260),
                            *(undefined **)(*(longlong *)(param_1 + 0x210) + 0x10));
    if (local_res8[0] == '\0') {
      SCCompleteIrp((longlong)puVar1,(int)uVar2,param_1);
    }
  }
  return;
}



===== SCWaitForOutstandingIo @ 1c0002988 =====

void SCWaitForOutstandingIo(longlong param_1)

{
  int *piVar1;
  int iVar2;
  undefined1 uVar3;
  
  uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x240);
  *(uint *)(param_1 + 0x118) = *(uint *)(param_1 + 0x118) | 0x100;
  KeReleaseSpinLock(param_1 + 0x240,uVar3);
  LOCK();
  piVar1 = (int *)(param_1 + 0x348);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 != 1) {
    KeWaitForSingleObject(param_1 + 0x308,0,0,0,0);
  }
  LOCK();
  *(int *)(param_1 + 0x348) = *(int *)(param_1 + 0x348) + 1;
  UNLOCK();
  return;
}



===== StreamClassDpc @ 1c0002a10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void StreamClassDpc(undefined8 param_1,longlong param_2,undefined8 param_3,ulonglong param_4)

{
  longlong lVar1;
  ulonglong *puVar2;
  ulonglong *puVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 *puVar6;
  longlong *plVar7;
  longlong lVar8;
  code *pcVar9;
  undefined1 *puVar10;
  char cVar11;
  undefined1 uVar12;
  ulonglong uVar13;
  undefined1 *puVar14;
  undefined8 uVar15;
  longlong *plVar16;
  ulonglong uVar17;
  undefined1 auStack_178 [8];
  undefined1 auStack_170 [24];
  ulonglong local_158;
  undefined8 local_150;
  longlong lStack_148;
  undefined8 local_140;
  undefined8 uStack_138;
  longlong local_130;
  longlong local_128;
  longlong local_120;
  uint *local_118;
  uint *local_110;
  uint local_108 [4];
  longlong local_f8;
  undefined8 local_c0;
  int local_b8;
  uint local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  uint local_9c;
  longlong local_98;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_178;
  lVar5 = *(longlong *)(param_2 + 0x40);
  local_128 = 0;
  uVar17 = param_4;
  memset(local_108,0,0x58);
  uVar15 = 0x58;
  memset(&local_a8,0,0x58);
  local_130 = 0;
  local_118 = local_108;
  local_110 = &local_a8;
  local_150 = 0;
  lStack_148 = 0;
  local_140 = 0;
  uStack_138 = 0;
  local_120 = lVar5;
  if (param_4 != 0) {
    SCStartRequestOnStream(param_4,lVar5,uVar15,(int)uVar17);
  }
  puVar14 = auStack_178;
  lVar1 = lVar5 + 0x240;
  do {
    KeAcquireSpinLockAtDpcLevel(lVar1);
    if ((*(char *)(lVar5 + 0x418) != '\0') &&
       (plVar16 = (longlong *)(lVar5 + 0x260), (longlong *)*plVar16 != plVar16)) {
      puVar6 = *(undefined8 **)(lVar5 + 0x268);
      if (((longlong *)*puVar6 == plVar16) &&
         (plVar7 = (longlong *)puVar6[1], (undefined8 *)*plVar7 == puVar6)) {
        *(longlong **)(lVar5 + 0x268) = plVar7;
        *plVar7 = (longlong)plVar16;
        puVar2 = (ulonglong *)(lVar5 + 0x270);
        *(undefined1 *)(lVar5 + 0x418) = 0;
        lVar8 = puVar6[-6];
        *(uint *)(lVar8 + 0x80) = *(uint *)(lVar8 + 0x80) | 1;
        puVar3 = (ulonglong *)(lVar8 + 0x138);
        uVar17 = *puVar2;
        if (*(ulonglong **)(uVar17 + 8) == puVar2) {
          *(ulonglong **)(lVar8 + 0x140) = puVar2;
          *puVar3 = uVar17;
          *(ulonglong **)(uVar17 + 8) = puVar3;
          *puVar2 = (ulonglong)puVar3;
          LOCK();
          puVar6[-8] = StreamClassCancelOutstandingIrp;
          UNLOCK();
          (**(code **)(lVar5 + 0x238))
                    (*(undefined8 *)(lVar5 + 0x138),
                     *(undefined8 *)(*(longlong *)(lVar5 + 0x210) + 0x10));
          KeReleaseSpinLockFromDpcLevel(lVar1);
          KeAcquireSpinLockAtDpcLevel(lVar1);
          goto LAB_1c0002b81;
        }
      }
      pcVar9 = (code *)swi(0x29);
      (*pcVar9)(3);
      puVar10 = auStack_170;
LAB_1c0002e47:
      puVar14 = puVar10;
      *(undefined8 *)(puVar14 + -8) = 0x1c0002e4e;
      KeReleaseSpinLockFromDpcLevel();
      break;
    }
LAB_1c0002b81:
    local_128 = 0;
    plVar16 = &local_128;
    local_98 = 0;
    local_f8 = 0;
    local_a8 = 0;
    local_108[0] = 0;
    cVar11 = (**(code **)(lVar5 + 0x238))(*(undefined8 *)(lVar5 + 0x138),SCGetInterruptState);
    puVar10 = auStack_178;
    if (cVar11 == '\0') goto LAB_1c0002e47;
    KeReleaseSpinLockFromDpcLevel(lVar1);
    lVar8 = local_128;
    if (local_128 != 0) {
      SCStartRequestOnStream(local_128,lVar5,plVar16,(int)uVar17);
      while (lVar4 = local_f8, local_f8 != 0) {
        local_f8 = *(longlong *)(local_f8 + 0x40);
        SCCallBackSrb(lVar4,lVar5);
      }
      if ((local_108[0] & 2) != 0) {
        SCProcessTimerRequest(lVar8,(longlong)local_108);
      }
      if ((local_108[0] & 4) != 0) {
        SCProcessPriorityChangeRequest(lVar8,(longlong)local_108,lVar5);
      }
      if ((local_108[0] & 0x10) != 0) {
        local_150 = *(undefined8 *)(lVar5 + 0x220);
        lVar4 = lVar8 + 0x230;
        lStack_148 = lVar8 + 0x130;
        local_158 = 0;
        local_140 = CONCAT44(local_140._4_4_,local_b8);
        uVar12 = KeAcquireSpinLockRaiseToDpc(lVar4);
        puVar6 = *(undefined8 **)(lVar8 + 0x238);
        if (puVar6 == (undefined8 *)0x0) {
          uStack_138 = 0xffffffffffffffff;
        }
        else if (local_b8 == 0) {
          uStack_138 = (*(code *)puVar6[3])(*puVar6,&local_130);
        }
        else {
          if (local_b8 != 1) {
            KeReleaseSpinLock(lVar4,uVar12);
            goto LAB_1c0002d97;
          }
          uStack_138 = (*(code *)puVar6[1])(*puVar6);
          uVar13 = KeQueryPerformanceCounter(&local_158);
          uVar17 = (uVar13 >> 0x20) * 10000000;
          local_130 = ((uVar17 % local_158 << 0x20) + (uVar13 & 0xffffffff) * 10000000) / local_158
                      + (uVar17 / local_158 << 0x20);
        }
        KeReleaseSpinLock(lVar4,uVar12);
        if (*(char *)(lVar5 + 800) == '\0') {
          KeAcquireSpinLockAtDpcLevel(lVar1);
        }
        (**(code **)(lVar5 + 0x238))(*(undefined8 *)(lVar5 + 0x138),local_c0,&local_150);
        if (*(char *)(lVar5 + 800) == '\0') {
          KeReleaseSpinLockFromDpcLevel(lVar1);
        }
      }
    }
LAB_1c0002d97:
    if ((local_a8 & 8) != 0) {
      uVar17 = (ulonglong)local_9c;
      SCLogError(param_2,local_a0,local_a4,local_9c);
    }
    while (lVar8 = local_98, local_98 != 0) {
      local_98 = *(longlong *)(local_98 + 0x40);
      SCCallBackSrb(lVar8,lVar5);
    }
    if ((local_a8 & 2) != 0) {
      SCProcessTimerRequest(lVar5,(longlong)&local_a8);
    }
    if ((*(longlong **)(lVar5 + 0x388) != (longlong *)(lVar5 + 0x388)) &&
       (*(char *)(lVar5 + 0x419) == '\0')) {
      *(undefined1 *)(lVar5 + 0x419) = 1;
      ExQueueWorkItem(lVar5 + 0x398,1);
    }
    if ((local_a8 & 4) != 0) {
      SCProcessPriorityChangeRequest(lVar5,(longlong)&local_a8,lVar5);
    }
  } while ((*(longlong *)(lVar5 + 0x2e0) != 0) || ((*(uint *)(lVar5 + 0x10) & 1) != 0));
  *(undefined8 *)(puVar14 + -8) = 0x1c0002e5f;
  return;
}



===== StreamClassSynchronizeExecution @ 1c0002e90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void StreamClassSynchronizeExecution(undefined8 param_1,undefined *param_2,undefined8 param_3)

{
  (*(code *)param_2)(param_3);
  return;
}



===== DllInitialize @ 1c0002eb0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DllInitialize(void)

{
                    /* 0x2eb0  1  DllInitialize */
  _DAT_1c000b128 = 1;
  _WPP_MAIN_CB = 0;
  DAT_1c000b108 = &WPP_ThisDir_CTLGUID_Stream;
  DAT_1c000b110 = 0;
  _DAT_1c000b120 = 0;
  WppLoadTracingSupport();
  _DAT_1c000b120 = 0;
  WppInitKm();
  return 0;
}



===== GetDeviceObjects @ 1c0002f10 =====

void GetDeviceObjects(longlong param_1,longlong *param_2,undefined8 *param_3,undefined8 *param_4)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (param_2 != (longlong *)0x0) {
    *param_2 = param_1;
  }
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = *(undefined8 *)(lVar1 + 0x128);
  }
  if (param_4 != (undefined8 *)0x0) {
    *param_4 = *(undefined8 *)(lVar1 + 0x218);
  }
  return;
}



===== RtlStringCbPrintfW @ 1c0002f44 =====

undefined8
RtlStringCbPrintfW(wchar_t *param_1,ulonglong param_2,wchar_t *param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 local_res20;
  
  uVar2 = param_2 >> 1;
  if (uVar2 - 1 < 0x7fffffff) {
    uVar2 = uVar2 - 1;
    uVar3 = 0;
    local_res20 = param_4;
    iVar1 = _vsnwprintf(param_1,uVar2,param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (uVar2 < (ulonglong)(longlong)iVar1)) {
      uVar3 = 0x80000005;
    }
    else if ((longlong)iVar1 != uVar2) {
      return 0;
    }
    param_1[uVar2] = L'\0';
  }
  else {
    uVar3 = 0xc000000d;
    if (uVar2 != 0) {
      *param_1 = L'\0';
    }
  }
  return uVar3;
}



===== SCBuildChildIds @ 1c0002fc0 =====

ulonglong SCBuildChildIds(undefined8 param_1,char param_2,longlong param_3,undefined8 *param_4)

{
  uint uVar1;
  wchar_t *pwVar2;
  short *psVar3;
  short *psVar4;
  short *psVar5;
  undefined8 uVar6;
  longlong lVar7;
  ulonglong uVar8;
  short sVar9;
  int iVar10;
  ulonglong uVar11;
  wchar_t *pwVar12;
  longlong lVar13;
  int iVar14;
  int iVar15;
  undefined4 local_48 [4];
  
  local_48[0] = 0;
  psVar3 = (short *)0x0;
  uVar1 = IoGetDeviceProperty(param_1,-(uint)(param_2 != '\0') + 2,0,0,local_48);
  uVar11 = (ulonglong)uVar1;
  if (uVar1 == 0xc0000023) {
    do {
      if (psVar3 != (short *)0x0) {
        ExFreePool(psVar3);
      }
      psVar3 = (short *)ExAllocatePoolWithTag(1,local_48[0],0x736c4353);
      if (psVar3 == (short *)0x0) {
        return 0xc000009a;
      }
      uVar1 = IoGetDeviceProperty(param_1,-(uint)(param_2 != '\0') + 2,local_48[0],psVar3,local_48);
      uVar11 = (ulonglong)uVar1;
    } while (uVar1 == 0xc0000023);
  }
  else if (param_2 == '\0') {
    lVar13 = -1;
    do {
      lVar13 = lVar13 + 1;
    } while (*(short *)(param_3 + lVar13 * 2) != 0);
    uVar1 = (int)lVar13 * 2 + 0x12;
    pwVar2 = (wchar_t *)ExAllocatePoolWithTag(1,uVar1,0x736c4353);
    if (pwVar2 == (wchar_t *)0x0) {
      return 0xc000009a;
    }
    memset(pwVar2,0,(ulonglong)uVar1);
    RtlStringCbPrintfW(pwVar2,(ulonglong)uVar1,L"Stream\\%s",param_3);
    *param_4 = pwVar2;
    return uVar11;
  }
  if (-1 < (int)uVar11) {
    iVar10 = 0;
    iVar14 = 0;
    sVar9 = *psVar3;
    psVar5 = psVar3;
    while (sVar9 != 0) {
      do {
        psVar4 = psVar5;
        if (sVar9 == 0x5c) {
          *psVar4 = 0x23;
        }
        iVar10 = iVar10 + 1;
        sVar9 = psVar4[1];
        psVar5 = psVar4 + 1;
      } while (sVar9 != 0);
      psVar5 = psVar4 + 2;
      iVar14 = iVar14 + 1;
      sVar9 = *psVar5;
    }
    lVar13 = -1;
    do {
      lVar13 = lVar13 + 1;
    } while (*(short *)(param_3 + lVar13 * 2) != 0);
    iVar10 = (((int)lVar13 + 9) * iVar14 + iVar10) * 2;
    iVar15 = iVar10 + 2;
    if (iVar14 != 0) {
      iVar15 = iVar10;
    }
    uVar1 = iVar15 + 2;
    if (param_2 == '\0') {
      lVar13 = -1;
      do {
        lVar13 = lVar13 + 1;
      } while (*(short *)(param_3 + lVar13 * 2) != 0);
      uVar1 = uVar1 + (int)lVar13 * 2 + 0x10;
    }
    pwVar2 = (wchar_t *)ExAllocatePoolWithTag(1,uVar1,0x736c4353);
    if (pwVar2 == (wchar_t *)0x0) {
      uVar11 = 0xc000009a;
    }
    else {
      memset(pwVar2,0,(ulonglong)uVar1);
      pwVar12 = pwVar2;
      psVar5 = psVar3;
      do {
        if (iVar14 == 0) {
          if (param_2 == '\0') {
            uVar8 = RtlStringCbPrintfW(pwVar12,(ulonglong)uVar1,L"Stream\\%s",param_3);
            uVar11 = uVar8 & 0xffffffff;
            if ((int)uVar8 < 0) break;
          }
          *param_4 = pwVar2;
          goto LAB_1c000328d;
        }
        uVar6 = RtlStringCbPrintfW(pwVar12,(ulonglong)uVar1,L"Stream\\%s#%s",param_3);
        if ((int)uVar6 < 0) {
          uVar11 = 0xc0000001;
          break;
        }
        lVar13 = -1;
        do {
          lVar13 = lVar13 + 1;
        } while (pwVar12[lVar13] != L'\0');
        uVar1 = uVar1 + (-1 - (int)lVar13);
        lVar13 = -1;
        do {
          lVar7 = lVar13;
          lVar13 = lVar7 + 1;
        } while (pwVar12[lVar13] != L'\0');
        pwVar12 = pwVar12 + lVar7 + 2;
        lVar13 = -1;
        do {
          lVar7 = lVar13;
          lVar13 = lVar7 + 1;
        } while (psVar5[lVar13] != 0);
        psVar5 = psVar5 + lVar7 + 2;
        iVar14 = iVar14 + -1;
      } while (-1 < (int)uVar11);
      ExFreePool(pwVar2);
    }
  }
LAB_1c000328d:
  if (psVar3 != (short *)0x0) {
    ExFreePool(psVar3);
  }
  return uVar11;
}



===== SCBustedSynchPowerCompletionRoutine @ 1c00032d0 =====

undefined4 SCBustedSynchPowerCompletionRoutine(void)

{
  longlong in_R9;
  undefined4 *in_stack_00000028;
  
  *(undefined4 *)(in_R9 + 0x18) = *in_stack_00000028;
  KeSetEvent();
  return *(undefined4 *)(in_R9 + 0x18);
}



===== SCDevIrpCompletionWorker @ 1c0003310 =====

void SCDevIrpCompletionWorker(undefined8 *param_1)

{
  longlong lVar1;
  char local_res8 [8];
  
  local_res8[0] = '\0';
  lVar1 = *(longlong *)(*(longlong *)(param_1[0x17] + 0x28) + 0x40);
  KeWaitForSingleObject(lVar1 + 0x2f0,0,0,0,0);
  SCSubmitRequest(0x108,1,0,SCPowerCallback,lVar1,0,0,param_1,local_res8,(longlong *)(lVar1 + 0x260)
                  ,*(undefined **)(*(longlong *)(lVar1 + 0x210) + 0x10));
  if (local_res8[0] == '\0') {
    SCSetCurrentDPowerState(lVar1,1);
    PoStartNextPowerIrp(param_1);
    SCCompleteIrp((longlong)param_1,0,lVar1);
  }
  KeSetEvent(lVar1 + 0x2f0,0,0);
  SCRedispatchPendedIrps(lVar1,'\0');
  SCDereferenceDriver(lVar1);
  return;
}



===== SCDevWakeCompletionRoutine @ 1c0003420 =====

undefined8 SCDevWakeCompletionRoutine(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  *(undefined8 *)(lVar1 + 0x3f8) = 0;
  *(undefined8 *)(lVar1 + 0x410) = param_2;
  *(code **)(lVar1 + 0x408) = SCDevIrpCompletionWorker;
  ExQueueWorkItem((undefined8 *)(lVar1 + 0x3f8),1);
  return 0xc0000016;
}



===== SCHandleQueryInterface @ 1c0003464 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 SCHandleQueryInterface(longlong param_1,longlong param_2)

{
  ushort uVar1;
  longlong lVar2;
  void *_Dst;
  undefined8 uVar3;
  uint uVar4;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  uVar1 = *(ushort *)(lVar2 + 0x10);
  if (uVar1 < 0x20) {
    uVar3 = 0xc000000d;
  }
  else if ((**(longlong **)(lVar2 + 8) == 0x406806778776274d) &&
          ((*(longlong **)(lVar2 + 8))[1] == -0x734c56f29dc02a50)) {
    _Dst = *(void **)(lVar2 + 0x18);
    uVar4 = 0x28;
    if (uVar1 < 0x28) {
      uVar4 = (uint)uVar1;
    }
    memmove(_Dst,&g_StreamFDOInterfaceTable,(ulonglong)uVar4);
    *(undefined8 *)((longlong)_Dst + 8) = *(undefined8 *)(param_1 + 0x120);
    (*(code *)PTR__guard_check_icall_1c000b010)();
    uVar3 = 0;
  }
  else {
    uVar3 = 0xc00000bb;
  }
  return uVar3;
}



===== SCQueryWorker @ 1c00034f8 =====

void SCQueryWorker(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined1 uVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (*(int *)(param_2 + 0x30) < 0) {
    uVar2 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x240);
    *(uint *)(lVar1 + 0x118) = *(uint *)(lVar1 + 0x118) & 0xfffffeff;
    KeReleaseSpinLock(lVar1 + 0x240,uVar2);
  }
  SCCompleteIrp(param_2,*(undefined4 *)(param_2 + 0x30),lVar1);
  return;
}



===== SCRedispatchPendedIrps @ 1c0003568 =====

void SCRedispatchPendedIrps(longlong param_1,char param_2)

{
  longlong lVar1;
  
  KeSetEvent(param_1 + 0x468,0,0);
  while( true ) {
    lVar1 = KsRemoveIrpFromCancelableQueue(param_1 + 0x440,param_1 + 0x450,1);
    if (lVar1 == 0) break;
    if ((param_2 == '\0') || (**(char **)(lVar1 + 0xb8) == '\x02')) {
      KsDispatchIrp(*(undefined8 *)(param_1 + 0x120),lVar1);
    }
    else {
      *(undefined4 *)(lVar1 + 0x30) = 0x80000011;
      IofCompleteRequest(lVar1,0);
    }
  }
  return;
}



===== SCSetCurrentDPowerState @ 1c0003628 =====

void SCSetCurrentDPowerState(longlong param_1,int param_2)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x458);
  if (param_2 != 1) {
    KeResetEvent(param_1 + 0x468);
  }
  *(int *)(param_1 + 0x374) = param_2;
  KeReleaseSpinLock(param_1 + 0x458,uVar1);
  return;
}



===== SCSynchCompletionRoutine @ 1c00036b0 =====

undefined8 SCSynchCompletionRoutine(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  KeSetEvent(param_3,0,0);
  return 0xc0000016;
}



===== SCSynchPowerCompletionRoutine @ 1c00036e0 =====

undefined4 SCSynchPowerCompletionRoutine(void)

{
  longlong lVar1;
  undefined4 uVar2;
  longlong in_R9;
  undefined4 *in_stack_00000028;
  
  if (in_R9 == 0) {
    uVar2 = *in_stack_00000028;
  }
  else {
    lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(in_R9 + 0xb8) + 0x28) + 0x40);
    *(undefined4 *)(in_R9 + 0x30) = *in_stack_00000028;
    *(undefined8 *)(lVar1 + 0x3d8) = 0;
    *(code **)(lVar1 + 1000) = SCPowerCompletionWorker;
    *(longlong *)(lVar1 + 0x3f0) = in_R9;
    ExQueueWorkItem((undefined8 *)(lVar1 + 0x3d8),1);
    uVar2 = *in_stack_00000028;
  }
  return uVar2;
}



===== SciCreateSymbolicLinks @ 1c0003748 =====

void * SciCreateSymbolicLinks(longlong param_1,uint param_2,longlong param_3)

{
  void *pvVar1;
  uint uVar2;
  longlong lVar3;
  int iVar4;
  void *pvVar5;
  void *_Dst;
  uint uVar6;
  ulonglong uVar7;
  undefined8 local_res18;
  longlong local_res20;
  undefined8 local_50;
  undefined8 uStack_48;
  
  _Dst = (void *)0x0;
  lVar3 = *(longlong *)(*(uint **)(param_3 + 0x28) + 2);
  uVar2 = **(uint **)(param_3 + 0x28);
  local_res18 = 0;
  local_res20 = 0;
  local_50 = 0;
  uStack_48 = 0;
  pvVar5 = (void *)ExAllocatePoolWithTag(1,0x100,0x736c4353);
  if (pvVar5 == (void *)0x0) {
    iVar4 = -0x3fffff66;
  }
  else {
    _Dst = (void *)ExAllocatePoolWithTag(1,(ulonglong)uVar2 << 4,0x736c4353);
    if (_Dst == (void *)0x0) {
      iVar4 = -0x3fffff66;
    }
    else {
      memset(_Dst,0,(ulonglong)uVar2 << 4);
      iVar4 = IoOpenDeviceRegistryKey(*(undefined8 *)(param_1 + 0x218),2,0x1f0000,&local_res20);
      if (iVar4 < 0) {
        local_res20 = 0;
      }
      else {
        uVar7 = 0;
        if (uVar2 != 0) {
          do {
            pvVar1 = (void *)(uVar7 * 0x10 + (longlong)_Dst);
            iVar4 = IoRegisterDeviceInterface
                              (*(undefined8 *)(param_1 + 0x218),lVar3 + uVar7 * 0x10,
                               *(longlong *)(param_1 + 0x428) + 0x10 + (ulonglong)param_2 * 0x30,
                               pvVar1);
            if (iVar4 < 0) goto LAB_1c00039bf;
            iVar4 = IoSetDeviceInterfaceState(pvVar1,1);
            if (iVar4 < 0) goto LAB_1c00039bf;
            iVar4 = IoOpenDeviceInterfaceRegistryKey(pvVar1,0x1f0000,&local_res18);
            if (iVar4 < 0) goto LAB_1c00039bf;
            iVar4 = SCGetRegistryValue(local_res20,L"CLSID",0xc,pvVar5,0x100);
            if (-1 < iVar4) {
              RtlInitUnicodeString(&local_50,L"CLSID");
              ZwSetValueKey(local_res18,&local_50,0,1,pvVar5,0x100);
            }
            iVar4 = SCGetRegistryValue(local_res18,L"FriendlyName",0x1a,pvVar5,0x100);
            if (iVar4 < 0) {
              iVar4 = SCGetRegistryValue(local_res20,L"DriverDesc",0x16,pvVar5,0x100);
              if (-1 < iVar4) {
                RtlInitUnicodeString(&local_50,L"FriendlyName");
                ZwSetValueKey(local_res18,&local_50,0,1,pvVar5,0x100);
              }
            }
            ZwClose(local_res18);
            uVar6 = (int)uVar7 + 1;
            uVar7 = (ulonglong)uVar6;
          } while (uVar6 < uVar2);
        }
        iVar4 = 0;
      }
    }
LAB_1c00039bf:
    ExFreePool(pvVar5);
  }
  if (local_res20 != 0) {
    ZwClose();
  }
  if ((iVar4 < 0) && (_Dst != (void *)0x0)) {
    ExFreePool(_Dst);
    _Dst = (void *)0x0;
  }
  return _Dst;
}



===== SciFreeFilterInstance @ 1c0003a20 =====

undefined8 SciFreeFilterInstance(longlong *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong lVar4;
  code *pcVar5;
  undefined1 *puVar6;
  uint uVar7;
  ulonglong uVar8;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  puVar6 = auStack_28;
  lVar2 = param_1[0x14];
  plVar1 = param_1 + 4;
  param_1[0x14] = 0;
  do {
    plVar3 = (longlong *)*plVar1;
    if (plVar3 == plVar1) {
LAB_1c0003aa7:
      if ((int *)param_1[0x18] != (int *)0x0) {
        uVar8 = 0;
        if (*(int *)param_1[0x18] != 0) {
          do {
            if (*(longlong *)(lVar2 + uVar8 * 0x10) != 0) {
              *(undefined8 *)(puVar6 + -8) = 0x1c0003ad3;
              ExFreePool();
            }
            if (*(longlong *)(lVar2 + 8 + uVar8 * 0x10) != 0) {
              *(undefined8 *)(puVar6 + -8) = 0x1c0003ae9;
              ExFreePool();
            }
            uVar7 = (int)uVar8 + 1;
            uVar8 = (ulonglong)uVar7;
          } while (uVar7 < *(uint *)param_1[0x18]);
        }
        if (param_1[0x13] != 0) {
          *(undefined8 *)(puVar6 + -8) = 0x1c0003b0e;
          ExFreePool();
          param_1[0x13] = 0;
        }
        if (param_1[0xe] != 0) {
          *(undefined8 *)(puVar6 + -8) = 0x1c0003b2b;
          ExFreePool();
          param_1[0xe] = 0;
        }
        if (param_1[10] != 0) {
          *(undefined8 *)(puVar6 + -8) = 0x1c0003b45;
          ExFreePool();
          param_1[10] = 0;
        }
        lVar2 = param_1[0x18];
        *(undefined8 *)(puVar6 + -8) = 0x1c0003b5d;
        ExFreePool(lVar2);
        param_1[0x18] = 0;
      }
      if (param_1[0xc] != 0) {
        *(undefined8 *)(puVar6 + -8) = 0x1c0003b7a;
        ExFreePool();
        param_1[0xc] = 0;
      }
      if (*param_1 != 0) {
        *(undefined8 *)(puVar6 + -8) = 0x1c0003b93;
        KsFreeObjectHeader();
        *param_1 = 0;
      }
      if (param_1[8] != 0) {
        *(undefined8 *)(puVar6 + -8) = 0x1c0003bac;
        KsUnregisterWorker();
        param_1[8] = 0;
      }
      if (param_1[9] != 0) {
        *(undefined8 *)(puVar6 + -8) = 0x1c0003bc6;
        KsUnregisterWorker();
        param_1[9] = 0;
      }
      *(undefined8 *)(puVar6 + -8) = 0x1c0003bda;
      ExFreePool(param_1);
      return 0;
    }
    if (((longlong *)plVar3[1] != plVar1) ||
       (lVar4 = *plVar3, (longlong *)*(longlong *)(lVar4 + 8) != plVar3)) {
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      puVar6 = auStack_20;
      goto LAB_1c0003aa7;
    }
    *plVar1 = lVar4;
    *(longlong **)(lVar4 + 8) = plVar1;
    if (plVar3[-0x39] != 0) {
      KsFreeObjectHeader();
    }
    *(undefined8 *)(plVar3[-0x15] + 0x18) = 0;
    ExFreePool(plVar3 + -0x39);
  } while( true );
}



===== SciOnFilterStreamDescriptor @ 1c0003c00 =====

undefined8 SciOnFilterStreamDescriptor(longlong param_1,uint *param_2)

{
  uint uVar1;
  void *_Dst;
  undefined1 *puVar2;
  void *pvVar3;
  longlong *plVar4;
  uint *puVar5;
  longlong lVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  void *pvVar9;
  uint uVar10;
  
  uVar1 = *param_2;
  uVar7 = 0;
  _Dst = (void *)0x0;
  if (param_2[1] < 0x88) {
    return 0xc000000d;
  }
  if (uVar1 == 0) {
LAB_1c0003db2:
    if (param_2[2] != 0) {
      pvVar9 = SCCopyMinidriverProperties(param_2[2],*(void **)(param_2 + 4));
      *(void **)(param_1 + 0x98) = pvVar9;
      if (pvVar9 == (void *)0x0) goto LAB_1c0003c72;
    }
    if (param_2[6] != 0) {
      pvVar9 = SCCopyMinidriverEvents(param_2[6],*(void **)(param_2 + 8));
      *(void **)(param_1 + 0x70) = pvVar9;
      if (pvVar9 == (void *)0x0) goto LAB_1c0003c72;
    }
    if (param_2[0xe] != 0) {
      pvVar9 = SCCopyMinidriverMethods(param_2[0xe],*(void **)(param_2 + 0x10));
      *(void **)(param_1 + 0x50) = pvVar9;
      if (pvVar9 == (void *)0x0) goto LAB_1c0003c72;
    }
    SCUpdateMinidriverProperties(param_2[2],*(longlong *)(param_1 + 0x98),'\0');
    SCUpdateMinidriverEvents(param_2[6],*(longlong *)(param_1 + 0x70),'\0');
    if (param_2[0xe] != 0) {
      puVar5 = (uint *)(*(longlong *)(param_1 + 0x50) + 8);
      uVar8 = (ulonglong)param_2[0xe];
      do {
        uVar10 = 0;
        if (*puVar5 != 0) {
          plVar4 = (longlong *)(*(longlong *)(puVar5 + 2) + 8);
          do {
            if (plVar4[2] != 0) {
              plVar4[2] = (longlong)StreamClassMinidriverDeviceMethod;
            }
            if (*plVar4 != 0) {
              *plVar4 = (longlong)StreamClassMinidriverDeviceMethod;
            }
            plVar4 = plVar4 + 5;
            uVar10 = uVar10 + 1;
          } while (uVar10 < *puVar5);
        }
        puVar5 = puVar5 + 10;
        uVar8 = uVar8 - 1;
      } while (uVar8 != 0);
    }
    *(uint *)(param_1 + 0x78) = param_2[6];
    *(undefined8 *)(param_1 + 0x90) = *(undefined8 *)(param_2 + 0xc);
    if (*(longlong *)(param_1 + 0x60) != 0) {
      ExFreePool();
    }
    *(void **)(param_1 + 0x60) = _Dst;
    *(uint *)(param_1 + 0x68) = uVar1;
  }
  else {
    _Dst = (void *)ExAllocatePoolWithTag(0x200,uVar1 * 0x68,0x736c4353);
    if (_Dst != (void *)0x0) {
      memset(_Dst,0,(ulonglong)(uVar1 * 0x68));
      uVar8 = 0;
      pvVar9 = (void *)((ulonglong)uVar1 * 0x58 + (longlong)_Dst);
      *(void **)(param_1 + 0xa0) = pvVar9;
      if (*param_2 != 0) {
        puVar5 = param_2 + 0x2e;
        do {
          lVar6 = uVar8 * 0x58;
          *(undefined4 *)(lVar6 + (longlong)_Dst) = 1;
          *(undefined **)(lVar6 + 8 + (longlong)_Dst) = &PinInterfaces;
          if (puVar5[-2] == 0) {
            *(undefined4 *)(lVar6 + 0x10 + (longlong)_Dst) = 1;
            puVar2 = &PinMediums;
          }
          else {
            *(uint *)(lVar6 + 0x10 + (longlong)_Dst) = puVar5[-2];
            puVar2 = *(undefined1 **)puVar5;
          }
          *(undefined1 **)(lVar6 + 0x18 + (longlong)_Dst) = puVar2;
          *(uint *)(lVar6 + 0x20 + (longlong)_Dst) = puVar5[-0x19];
          *(undefined8 *)(lVar6 + 0x28 + (longlong)_Dst) = *(undefined8 *)(puVar5 + -0x18);
          *(uint *)(lVar6 + 0x30 + (longlong)_Dst) = puVar5[-0x1b];
          *(uint *)(lVar6 + 0x34 + (longlong)_Dst) = ((char)puVar5[2] != '\0') + 3;
          *(undefined8 *)(lVar6 + 0x38 + (longlong)_Dst) = *(undefined8 *)(puVar5 + -6);
          *(undefined8 *)(lVar6 + 0x40 + (longlong)_Dst) = *(undefined8 *)(puVar5 + -4);
          if (puVar5[-0xe] != 0) {
            pvVar3 = SCCopyMinidriverProperties(puVar5[-0xe],*(void **)(puVar5 + -0xc));
            *(void **)((longlong)pvVar9 + uVar8 * 0x10) = pvVar3;
            if (pvVar3 == (void *)0x0) goto LAB_1c0003c72;
          }
          if (puVar5[-10] != 0) {
            pvVar3 = SCCopyMinidriverEvents(puVar5[-10],*(void **)(puVar5 + -8));
            *(void **)((longlong)pvVar9 + uVar8 * 0x10 + 8) = pvVar3;
            if (pvVar3 == (void *)0x0) goto LAB_1c0003c72;
          }
          SCUpdateMinidriverProperties
                    (puVar5[-0xe],*(longlong *)((longlong)pvVar9 + uVar8 * 0x10),'\x01');
          SCUpdateMinidriverEvents
                    (puVar5[-10],*(longlong *)((longlong)pvVar9 + uVar8 * 0x10 + 8),'\x01');
          puVar5 = puVar5 + 0x22;
          uVar10 = (int)uVar8 + 1;
          uVar8 = (ulonglong)uVar10;
        } while (uVar10 < *param_2);
      }
      goto LAB_1c0003db2;
    }
LAB_1c0003c72:
    uVar7 = 0xc000009a;
  }
  return uVar7;
}



===== StreamClassCleanup @ 1c0003ed0 =====

undefined8 StreamClassCleanup(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x18);
  if ((lVar1 == 0) || (*(int *)(lVar1 + 8) != -0x28c501c1)) {
    *(undefined4 *)(param_2 + 0x30) = 0xc0000010;
    IofCompleteRequest(param_2,0);
    uVar2 = 0xc0000010;
  }
  else {
    uVar2 = StreamDispatchCleanup(param_1,param_2);
  }
  return uVar2;
}



===== StreamClassGetDmaBuffer @ 1c0003f30 =====

undefined8 StreamClassGetDmaBuffer(longlong param_1)

{
                    /* 0x3f30  10  StreamClassGetDmaBuffer */
  return *(undefined8 *)(param_1 + -0x278);
}



===== StreamClassPassThroughIrp @ 1c0003f40 =====

undefined8 StreamClassPassThroughIrp(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  longlong lVar2;
  undefined1 uVar3;
  undefined8 uVar4;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  if (*(char *)(param_2 + 0x40) == '\x01') {
    if (*(int *)(lVar2 + 0x374) == 1) goto LAB_1c0004083;
    if ((*(uint *)(lVar2 + 0x130) & 4) != 0) {
      uVar3 = KeAcquireSpinLockRaiseToDpc(lVar2 + 0x458);
      if ((*(int *)(lVar2 + 0x460) == 1) && (*(int *)(lVar2 + 0x374) != 1)) goto LAB_1c0004074;
      KeReleaseSpinLock(lVar2 + 0x458,uVar3);
    }
    KeWaitForSingleObject(lVar2 + 0x468,0,0,0,0);
  }
  else {
    if (*(int *)(lVar2 + 0x374) == 1) goto LAB_1c0004083;
    uVar3 = KeAcquireSpinLockRaiseToDpc(lVar2 + 0x458);
    if ((*(int *)(lVar2 + 0x374) != 1) &&
       (((*(uint *)(lVar2 + 0x130) & 4) == 0 || (*(int *)(lVar2 + 0x460) != 1)))) {
      pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
      *pbVar1 = *pbVar1 | 1;
      KsAddIrpToCancelableQueue(lVar2 + 0x440,lVar2 + 0x450,param_2,0,0);
      KeReleaseSpinLock(lVar2 + 0x458,uVar3);
      return 0x103;
    }
LAB_1c0004074:
    KeReleaseSpinLock(lVar2 + 0x458,uVar3);
  }
LAB_1c0004083:
  uVar4 = KsDispatchIrp(param_1,param_2);
  return uVar4;
}



===== StreamClassPower @ 1c00040c0 =====

ulonglong StreamClassPower(longlong param_1,undefined8 *param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined1 uVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  undefined4 extraout_var;
  undefined7 uVar10;
  ulonglong uVar11;
  uint uVar12;
  char local_res8 [8];
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  lVar3 = param_2[0x17];
  local_res8[0] = '\0';
  uVar11 = 0xc000000d;
  if ((*(uint *)(lVar2 + 0x118) & 2) != 0) {
    uVar7 = 0xc00000bb;
    if ((*(char *)(lVar3 + 1) == '\x02') || (*(char *)(lVar3 + 1) == '\x03')) {
      if (*(int *)(lVar3 + 0x10) == 0) {
        uVar7 = 0xc00000bb;
        if (*(int *)(lVar3 + 0x18) < 7) {
          uVar7 = 0;
        }
      }
      else if ((*(int *)(lVar3 + 0x10) == 1) && (*(int *)(lVar3 + 0x18) < 5)) {
        uVar7 = 0;
      }
    }
    PoStartNextPowerIrp(param_2);
    *(uint *)(param_2 + 6) = uVar7;
    IofCompleteRequest(param_2,0);
LAB_1c0004151:
    return (ulonglong)uVar7;
  }
  if ((*(uint *)(lVar2 + 0x118) >> 8 & 1) != 0) {
    uVar11 = SCCallNextDriver(lVar2,(longlong)param_2);
    PoStartNextPowerIrp(param_2);
    IofCompleteRequest(param_2,0);
    return uVar11 & 0xffffffff;
  }
  SCReferenceDriver(lVar2);
  LOCK();
  *(int *)(lVar2 + 0x348) = *(int *)(lVar2 + 0x348) + 1;
  UNLOCK();
  if (*(char *)(lVar3 + 1) == '\x02') {
    *(undefined4 *)(param_2 + 6) = 0;
    if (*(int *)(lVar3 + 0x10) == 0) {
      if ((*(uint *)(lVar2 + 0x118) & 1) != 0) {
        iVar1 = *(int *)(lVar3 + 0x18);
        uVar8 = *(undefined4 *)(lVar2 + 0x358 + (longlong)iVar1 * 4);
        if (iVar1 == 1) {
          PoStartNextPowerIrp(param_2);
          *(char *)((longlong)param_2 + 0x43) = *(char *)((longlong)param_2 + 0x43) + '\x01';
          param_2[0x17] = param_2[0x17] + 0x48;
          uVar7 = PoCallDriver(*(undefined8 *)(lVar2 + 0x128),param_2);
          LOCK();
          *(int *)(lVar2 + 0x348) = *(int *)(lVar2 + 0x348) + -1;
          UNLOCK();
          param_2 = (undefined8 *)0x0;
          uVar11 = (ulonglong)uVar7;
        }
        KeAcquireSpinLockRaiseToDpc(lVar2 + 0x458);
        *(int *)(lVar2 + 0x460) = iVar1;
        KeReleaseSpinLock(lVar2 + 0x458);
        lVar3 = lVar2 + 0x2f0;
        KeWaitForSingleObject(lVar3,0,0,0,0);
        if (((iVar1 == 1) && (*(int *)(lVar2 + 0x2d8) == 0)) &&
           ((*(uint *)(lVar2 + 0x130) & 4) != 0)) {
          KeSetEvent(lVar3,0,0);
          SCRedispatchPendedIrps(lVar2,'\0');
          SCDereferenceDriver(lVar2);
          return uVar11;
        }
        KeSetEvent(lVar3,0,0);
        if (iVar1 != 1) {
          uVar8 = 4;
        }
        if (param_2 != (undefined8 *)0x0) {
          *(byte *)(param_2[0x17] + 3) = *(byte *)(param_2[0x17] + 3) | 1;
        }
        uVar7 = PoRequestPowerIrp(*(undefined8 *)(lVar2 + 0x218),2,uVar8,
                                  SCSynchPowerCompletionRoutine,param_2,0);
        if ((int)uVar7 < 0) {
          if (param_2 != (undefined8 *)0x0) {
            PoStartNextPowerIrp(param_2);
            SCCompleteIrp((longlong)param_2,uVar7,lVar2);
            return (ulonglong)uVar7;
          }
        }
        else if (param_2 != (undefined8 *)0x0) {
          return 0x103;
        }
        SCDereferenceDriver(lVar2);
        uVar12 = 0;
        if ((int)uVar7 < 0) {
          uVar12 = uVar7;
        }
        return (ulonglong)uVar12;
      }
      PoStartNextPowerIrp(param_2);
      SCDereferenceDriver(lVar2);
      uVar8 = 0;
LAB_1c000467e:
      uVar8 = SCCompleteIrp((longlong)param_2,uVar8,lVar2);
      return CONCAT44(extraout_var,uVar8);
    }
    if (*(int *)(lVar3 + 0x10) == 1) {
      iVar1 = *(int *)(lVar3 + 0x18);
      if (iVar1 == 1) {
        puVar4 = (undefined8 *)param_2[0x17];
        puVar4[-9] = *puVar4;
        puVar4[-8] = puVar4[1];
        puVar4[-7] = puVar4[2];
        puVar4[-6] = puVar4[3];
        *(undefined4 *)(puVar4 + -5) = *(undefined4 *)(puVar4 + 4);
        *(undefined4 *)((longlong)puVar4 + -0x24) = *(undefined4 *)((longlong)puVar4 + 0x24);
        *(undefined4 *)(puVar4 + -4) = *(undefined4 *)(puVar4 + 5);
        *(undefined4 *)((longlong)puVar4 + -0x1c) = *(undefined4 *)((longlong)puVar4 + 0x2c);
        puVar4[-3] = puVar4[6];
        *(undefined1 *)((longlong)puVar4 + -0x45) = 0;
        lVar3 = param_2[0x17];
        *(code **)(lVar3 + -0x10) = SCDevWakeCompletionRoutine;
        *(undefined8 *)(lVar3 + -8) = 0;
        *(undefined1 *)(lVar3 + -0x45) = 0xe0;
        *(byte *)(param_2[0x17] + 3) = *(byte *)(param_2[0x17] + 3) | 1;
        PoCallDriver(*(undefined8 *)(lVar2 + 0x128),param_2);
        return 0x103;
      }
      KeWaitForSingleObject(lVar2 + 0x2f0,0,0,0,0);
      uVar9 = SCSubmitRequest(0x108,(longlong)iVar1,0,SCPowerCallback,lVar2,0,0,param_2,local_res8,
                              (longlong *)(lVar2 + 0x260),
                              *(undefined **)(*(longlong *)(lVar2 + 0x210) + 0x10));
      uVar7 = (uint)uVar9;
      if (local_res8[0] == '\0') {
        SCSetCurrentDPowerState(lVar2,iVar1);
        uVar11 = SCCallNextDriver(lVar2,(longlong)param_2);
        uVar7 = (uint)uVar11;
        PoStartNextPowerIrp(param_2);
        SCCompleteIrp((longlong)param_2,uVar7,lVar2);
      }
      KeSetEvent(lVar2 + 0x2f0,0,0);
      if (local_res8[0] == '\0') {
        SCDereferenceDriver(lVar2);
      }
      goto LAB_1c0004151;
    }
  }
  else if (*(char *)(lVar3 + 1) == '\x03') {
    *(undefined4 *)(param_2 + 6) = 0;
    if (*(int *)(lVar3 + 0x10) != 0) {
      if (*(int *)(lVar3 + 0x10) == 1) {
        if (*(int *)(lVar2 + 0x2d8) == 0) {
          uVar11 = SCCallNextDriver(lVar2,(longlong)param_2);
          uVar8 = (undefined4)uVar11;
        }
        else {
          uVar8 = 0x80000011;
        }
        PoStartNextPowerIrp(param_2);
        SCDereferenceDriver(lVar2);
      }
      else {
        PoStartNextPowerIrp(param_2);
        SCDereferenceDriver(lVar2);
        uVar8 = 0xc00000bb;
      }
      goto LAB_1c000467e;
    }
    if ((*(uint *)(lVar2 + 0x130) & 8) != 0) {
      lVar3 = lVar2 + 0x240;
      uVar6 = KeAcquireSpinLockRaiseToDpc(lVar3);
      for (puVar4 = *(undefined8 **)(lVar2 + 0x2c8); uVar10 = (undefined7)((ulonglong)puVar4 >> 8),
          puVar4 != (undefined8 *)(lVar2 + 0x2c8); puVar4 = (undefined8 *)*puVar4) {
        for (puVar5 = (undefined8 *)puVar4[2]; puVar5 != puVar4 + 2; puVar5 = (undefined8 *)*puVar5)
        {
          if (*(int *)((longlong)puVar5 + 0x8c) == 3) {
            KeReleaseSpinLock(lVar3,CONCAT71(uVar10,uVar6));
            PoStartNextPowerIrp(param_2);
            SCDereferenceDriver(lVar2);
            uVar8 = 0x80000011;
            goto LAB_1c000467e;
          }
        }
      }
      KeReleaseSpinLock(lVar3,CONCAT71(uVar10,uVar6));
    }
    PoStartNextPowerIrp(param_2);
    *(char *)((longlong)param_2 + 0x43) = *(char *)((longlong)param_2 + 0x43) + '\x01';
    param_2[0x17] = param_2[0x17] + 0x48;
    uVar7 = PoCallDriver(*(undefined8 *)(lVar2 + 0x128),param_2);
    LOCK();
    *(int *)(lVar2 + 0x348) = *(int *)(lVar2 + 0x348) + -1;
    UNLOCK();
    goto LAB_1c00042c5;
  }
  uVar7 = SCSendUnknownCommand(param_2,lVar2,SCUnknownPowerCallback,local_res8);
  if (local_res8[0] == '\0') {
    PoStartNextPowerIrp(param_2);
    uVar7 = SCCompleteIrp((longlong)param_2,0xc000009a,lVar2);
  }
LAB_1c00042c5:
  SCDereferenceDriver(lVar2);
  return (ulonglong)uVar7;
}



===== WppClassicProviderCallback @ 1c00046b0 =====

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



===== SCRequestDpcForStream @ 1c00046e4 =====

void SCRequestDpcForStream(longlong param_1)

{
  if (*(char *)(param_1 + 0x25a) == '\0') {
    *(undefined1 *)(param_1 + 0x25a) = 1;
    *(undefined8 *)(param_1 + 0x1f0) = *(undefined8 *)(*(longlong *)(param_1 + 0x1e8) + 0x2e0);
    *(longlong *)(*(longlong *)(param_1 + 0x1e8) + 0x2e0) = param_1;
  }
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 1;
  return;
}



===== StreamClassAbortOutstandingRequests @ 1c0004720 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void StreamClassAbortOutstandingRequests(longlong param_1,longlong param_2,undefined4 param_3)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  undefined1 local_res8 [8];
  
                    /* 0x4720  3  StreamClassAbortOutstandingRequests */
  local_res8[0] = 0;
  (**(code **)(param_1 + -0x1a0))(param_1 + -0x4d0,local_res8);
  plVar3 = (longlong *)(param_1 + -0x260);
  plVar2 = (longlong *)*plVar3;
  if (plVar2 != plVar3) {
    do {
      lVar1 = plVar2[-0x25];
      if (((param_2 == 0) || (lVar1 == param_2)) && ((*(uint *)(plVar2 + -0x17) & 1) != 0)) {
        *(undefined4 *)(plVar2 + -0x26) = param_3;
        *(uint *)(plVar2 + -0x17) = *(uint *)(plVar2 + -0x17) & 0xfffffffe;
        if ((*(uint *)(plVar2 + -0x1d) & 2) == 0) {
          plVar2[-0x1f] = *(longlong *)(param_1 + -0x4b0);
          *(longlong **)(param_1 + -0x4b0) = plVar2 + -0x27;
          *(undefined1 *)(param_1 + -0xb8) = 1;
        }
        else {
          if ((*(uint *)(plVar2 + -0x1d) & 1) == 0) {
            *(undefined1 *)(lVar1 + 0x128) = 1;
          }
          else {
            *(undefined1 *)(lVar1 + 0x129) = 1;
          }
          plVar2[-0x1f] = *(longlong *)(lVar1 + -0x110);
          *(longlong **)(lVar1 + -0x110) = plVar2 + -0x27;
          SCRequestDpcForStream(lVar1 + -0x130);
        }
      }
      plVar2 = (longlong *)*plVar2;
    } while (plVar2 != plVar3);
  }
  (**(code **)(param_1 + -400))(param_1 + -0x4d0,local_res8);
  return;
}



===== StreamClassCallAtNewPriority @ 1c0004820 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void StreamClassCallAtNewPriority
               (longlong param_1,longlong param_2,int param_3,undefined8 param_4,undefined8 param_5)

{
  undefined1 uVar1;
  longlong lVar2;
  longlong lVar3;
  
                    /* 0x4820  4  StreamClassCallAtNewPriority */
  lVar3 = param_2 + -0x4d0;
  lVar2 = param_1 + -0x130;
  if (param_3 == 3) {
    uVar1 = KeAcquireSpinLockRaiseToDpc(param_2 + -0x290);
    (**(code **)(param_2 + -0x298))(*(undefined8 *)(param_2 + -0x398),param_4);
    KeReleaseSpinLockFromDpcLevel();
    StreamClassDpc(0,*(longlong *)(param_2 + -0x3b0),0,0);
    KeLowerIrql(uVar1);
  }
  else {
    if (param_1 == 0) {
      *(uint *)(param_2 + -0x4c0) = *(uint *)(param_2 + -0x4c0) | 1;
    }
    else {
      SCRequestDpcForStream(lVar2);
      lVar3 = lVar2;
    }
    *(uint *)(lVar3 + 0x10) = *(uint *)(lVar3 + 0x10) | 4;
    *(undefined8 *)(lVar3 + 0x50) = param_5;
    *(int *)(lVar3 + 0x48) = param_3;
    *(undefined8 *)(lVar3 + 0x40) = param_4;
  }
  return;
}



===== StreamClassCompleteRequestAndMarkQueueReady @ 1c0004900 =====

void StreamClassCompleteRequestAndMarkQueueReady
               (longlong *param_1,undefined8 param_2,undefined8 param_3,longlong *param_4)

{
  undefined4 unaff_EBX;
  longlong *plVar1;
  undefined4 uVar2;
  
                    /* 0x4900  5  StreamClassCompleteRequestAndMarkQueueReady */
  uVar2 = SUB84(param_4,0);
  if ((*(uint *)(param_1 + 10) & 3) == 2) {
    plVar1 = param_1;
    StreamClassStreamNotification(3,param_1[2],param_1,uVar2);
    StreamClassStreamNotification(1,param_1[2],plVar1,uVar2);
  }
  else if ((*(uint *)(param_1 + 10) & 3) == 3) {
    plVar1 = param_1;
    StreamClassStreamNotification(3,param_1[2],param_1,uVar2);
    StreamClassStreamNotification(0,param_1[2],plVar1,uVar2);
  }
  else {
    plVar1 = param_1;
    StreamClassDeviceNotification(1,param_1[3],param_1,param_4,unaff_EBX);
    StreamClassDeviceNotification(0,param_1[3],plVar1,param_4,unaff_EBX);
  }
  return;
}



===== StreamClassDebugPrint @ 1c0004980 =====

void StreamClassDebugPrint(void)

{
                    /* 0x4980  7  StreamClassDebugPrint */
  return;
}



===== StreamClassDeviceNotification @ 1c00049a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void StreamClassDeviceNotification
               (int param_1,longlong param_2,longlong *param_3,longlong *param_4,undefined4 param_5)

{
  longlong lVar1;
  code *pcVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  longlong *plVar5;
  undefined4 local_res20;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [24];
  undefined8 local_38;
  undefined1 local_28 [16];
  
                    /* 0x49a0  8  StreamClassDeviceNotification */
  local_28[0] = 0;
  (**(code **)(param_2 + -0x1a0))(param_2 + -0x4d0,local_28);
  puVar3 = auStack_58;
  puVar4 = auStack_58;
  if (param_1 == 0) {
    *(undefined1 *)(param_2 + -0xb8) = 1;
    goto LAB_1c0004ab7;
  }
  if (param_1 == 1) {
    *(uint *)(param_3 + 0x10) = *(uint *)(param_3 + 0x10) & 0xfffffffe;
    param_3[8] = *(longlong *)(param_2 + -0x4b0);
    *(longlong **)(param_2 + -0x4b0) = param_3;
    puVar4 = auStack_58;
    goto LAB_1c0004ab7;
  }
  if (param_1 == 2) {
    plVar5 = *(longlong **)(param_2 + -0x208);
    puVar4 = auStack_58;
    if (plVar5 == (longlong *)(param_2 + -0x208)) goto LAB_1c0004ab7;
    local_res20 = SUB84(param_4,0);
    plVar5 = plVar5 + 0xe;
    param_4 = param_3;
    param_5 = local_res20;
LAB_1c0004a81:
    local_38 = 0;
    KsGenerateEventList(param_4,param_5,plVar5,0);
    puVar4 = auStack_58;
  }
  else {
    if (param_1 != 3) {
      if (param_1 != 4) {
        puVar4 = auStack_58;
        if (param_1 != 5) goto LAB_1c0004ab7;
        plVar5 = param_3 + -10;
        goto LAB_1c0004a81;
      }
      lVar1 = *param_3;
      if ((*(longlong **)(lVar1 + 8) == param_3) &&
         (plVar5 = (longlong *)param_3[1], (longlong *)*plVar5 == param_3)) {
        *plVar5 = lVar1;
        *(longlong **)(lVar1 + 8) = plVar5;
        plVar5 = *(longlong **)(param_2 + -0x140);
        if (*plVar5 == param_2 + -0x148) {
          *param_3 = param_2 + -0x148;
          param_3[1] = (longlong)plVar5;
          *plVar5 = (longlong)param_3;
          *(longlong **)(param_2 + -0x140) = param_3;
          puVar4 = auStack_58;
          goto LAB_1c0004ab7;
        }
      }
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(3);
      puVar3 = auStack_50;
    }
    *(undefined8 *)(puVar3 + -8) = 0x1c0004a61;
    KsGenerateEvent(param_3);
    puVar4 = puVar3;
  }
LAB_1c0004ab7:
  pcVar2 = *(code **)(param_2 + -400);
  *(undefined8 *)(puVar4 + -8) = 0x1c0004acb;
  (*pcVar2)(param_2 + -0x4d0,puVar4 + 0x30);
  return;
}



===== StreamClassGetNextEvent @ 1c0004ae0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

longlong *
StreamClassGetNextEvent
          (longlong param_1,longlong param_2,longlong *param_3,int param_4,longlong *param_5)

{
  char cVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong *plVar6;
  undefined1 local_res8 [8];
  
                    /* 0x4ae0  11  StreamClassGetNextEvent */
  lVar4 = param_1 + -0xd0;
  local_res8[0] = 0;
  plVar6 = (longlong *)0x0;
  if (*(int *)(param_1 + -0x78) == 0x46727453) {
    lVar3 = *(longlong *)(param_1 + -0x18);
  }
  else {
    lVar3 = param_1 + -0x4d0;
    lVar4 = param_1 + -0x290;
    cVar1 = '\0';
    if (*(char *)(param_1 + -0x1b0) != '\0') {
      local_res8[0] = KeAcquireSpinLockRaiseToDpc(lVar4);
      cVar1 = *(char *)(param_1 + -0x1b0);
    }
    plVar5 = *(longlong **)(param_1 + -0x208);
    if (plVar5 == (longlong *)(param_1 + -0x208)) {
      if (cVar1 != '\0') {
        KeReleaseSpinLock(lVar4);
      }
      return (longlong *)0x0;
    }
    if (cVar1 != '\0') {
      KeReleaseSpinLock(lVar4,local_res8[0]);
    }
    lVar4 = (longlong)(plVar5 + -2);
  }
  (**(code **)(lVar3 + 0x330))(lVar3,local_res8);
  plVar5 = (longlong *)(param_2 + 0xa8);
  if (param_2 == 0) {
    plVar5 = (longlong *)(lVar4 + 0x80);
  }
  plVar2 = (longlong *)*plVar5;
  if (plVar2 != plVar5) {
    do {
      if ((param_4 == *(int *)plVar2[7]) &&
         ((param_3 == (longlong *)0x0 ||
          ((*param_3 == **(longlong **)plVar2[6] && (param_3[1] == (*(longlong **)plVar2[6])[1])))))
         ) {
        if (param_5 == (longlong *)0x0) {
          plVar6 = plVar2;
          break;
        }
        if (param_5 == plVar2) {
          param_5 = (longlong *)0x0;
        }
      }
      plVar2 = (longlong *)*plVar2;
    } while (plVar2 != plVar5);
  }
  if (*(char *)(lVar3 + 800) != '\0') {
    KeReleaseSpinLock(lVar3 + 0x240,local_res8[0]);
  }
  return plVar6;
}



===== StreamClassGetPhysicalAddress @ 1c0004c60 =====

ulonglong StreamClassGetPhysicalAddress
                    (longlong param_1,longlong param_2,int param_3,int param_4,int *param_5)

{
  uint *puVar1;
  ulonglong uVar2;
  uint uVar3;
  longlong *plVar4;
  longlong *plVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  longlong lVar9;
  
                    /* 0x4c60  12  StreamClassGetPhysicalAddress */
  uVar2 = 0;
  uVar6 = 0;
  if (param_4 == 0) {
    uVar8 = (param_3 - (int)param_2) - 400;
    *param_5 = *(int *)(param_2 + 0x88) - uVar8;
    lVar9 = *(longlong *)(param_2 + 0x120) + 400;
LAB_1c0004d7f:
    uVar2 = lVar9 + (ulonglong)uVar8;
  }
  else if (param_4 == 1) {
    uVar6 = param_3 - *(int *)(param_1 + -0x278);
    *param_5 = *(int *)(param_1 + -0x284) - uVar6;
    uVar2 = (ulonglong)uVar6 + *(longlong *)(param_1 + -0x280);
  }
  else {
    if (param_4 == 2) {
      uVar7 = 0;
      lVar9 = *(longlong *)(param_2 + 0x28);
      if (*(uint *)(param_2 + 0x30) != 0) {
        do {
          if (*(int *)(param_2 + 4) == 1) {
            uVar3 = *(uint *)(lVar9 + 0x24);
          }
          else {
            uVar3 = *(uint *)(lVar9 + 0x20);
          }
          uVar8 = (param_3 - *(int *)(lVar9 + 0x28)) + 1;
          if (uVar8 <= uVar3) {
            plVar5 = *(longlong **)(param_2 + 0x68);
            if (uVar6 != 0) {
              do {
                uVar7 = (int)uVar2 + (int)plVar5[1];
                uVar2 = (ulonglong)uVar7;
                plVar5 = plVar5 + 2;
              } while (uVar7 < uVar6);
            }
            plVar4 = plVar5;
            if (*(uint *)(plVar5 + 1) < uVar8) {
              do {
                uVar8 = uVar8 - (int)plVar4[1];
                plVar5 = plVar4 + 2;
                puVar1 = (uint *)(plVar4 + 3);
                plVar4 = plVar5;
              } while (*puVar1 < uVar8);
            }
            *param_5 = ((int)plVar5[1] - uVar8) + 1;
            lVar9 = *plVar5 + -1;
            goto LAB_1c0004d7f;
          }
          uVar6 = uVar6 + uVar3;
          uVar7 = uVar7 + 1;
          lVar9 = lVar9 + (ulonglong)*(uint *)(*(longlong *)(param_2 + 0x10) + 0x48) +
                  (ulonglong)*(uint *)(*(longlong *)(param_2 + 0x10) + 0x4c);
        } while (uVar7 < *(uint *)(param_2 + 0x30));
      }
    }
    *param_5 = 0;
  }
  return uVar2;
}



===== StreamClassLogError @ 1c0004da0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void StreamClassLogError(longlong param_1,longlong param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined1 local_res8 [8];
  
                    /* 0x4da0  13  StreamClassLogError */
  uVar1 = 0;
  local_res8[0] = 0;
  (**(code **)(param_1 + -0x1a0))(param_1 + -0x4d0,local_res8);
  if ((*(uint *)(param_1 + -0x4c0) & 8) == 0) {
    *(undefined4 *)(param_1 + -0x4bc) = param_3;
    *(undefined4 *)(param_1 + -0x4b4) = param_4;
    if (param_2 != 0) {
      uVar1 = *(undefined4 *)(param_2 + 0x84);
    }
    *(undefined4 *)(param_1 + -0x4b8) = uVar1;
    *(uint *)(param_1 + -0x4c0) = *(uint *)(param_1 + -0x4c0) | 8;
    (**(code **)(param_1 + -400))(param_1 + -0x4d0,local_res8);
  }
  return;
}



===== StreamClassQueryMasterClock @ 1c0004e30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void StreamClassQueryMasterClock
               (longlong param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  longlong lVar1;
  undefined1 local_res18 [8];
  
                    /* 0x4e30  15  StreamClassQueryMasterClock */
  local_res18[0] = 0;
  lVar1 = *(longlong *)(param_1 + 0xb8);
  (**(code **)(lVar1 + 0x330))(lVar1,local_res18);
  *(uint *)(param_1 + -0x120) = *(uint *)(param_1 + -0x120) | 0x10;
  *(undefined8 *)(param_1 + -0xd8) = param_4;
  *(undefined4 *)(param_1 + -0xd0) = param_3;
  (**(code **)(lVar1 + 0x338))(param_1 + -0x130,local_res18);
  return;
}



===== StreamClassQueryMasterClockSync @ 1c0004eb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void StreamClassQueryMasterClockSync(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined1 uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong local_res10;
  
                    /* 0x4eb0  16  StreamClassQueryMasterClockSync */
  lVar2 = *(longlong *)(param_2 + 8);
  local_res10 = 0;
  lVar1 = lVar2 + 0x100;
  uVar4 = KeAcquireSpinLockRaiseToDpc(lVar1);
  puVar3 = *(undefined8 **)(lVar2 + 0x108);
  if (puVar3 == (undefined8 *)0x0) {
    *(undefined8 *)(param_2 + 0x18) = 0xffffffffffffffff;
  }
  else if (*(int *)(param_2 + 0x10) == 0) {
    uVar5 = (*(code *)puVar3[3])(*puVar3,param_2 + 0x20);
    *(undefined8 *)(param_2 + 0x18) = uVar5;
  }
  else if (*(int *)(param_2 + 0x10) == 1) {
    uVar5 = (*(code *)puVar3[1])(*puVar3);
    *(undefined8 *)(param_2 + 0x18) = uVar5;
    uVar6 = KeQueryPerformanceCounter(&local_res10);
    uVar7 = (uVar6 >> 0x20) * 10000000;
    *(ulonglong *)(param_2 + 0x20) =
         ((uVar7 % local_res10 << 0x20) + (uVar6 & 0xffffffff) * 10000000) / local_res10 +
         (uVar7 / local_res10 << 0x20);
  }
  KeReleaseSpinLock(lVar1,uVar4);
  return;
}



===== StreamClassReadWriteConfig @ 1c0004fc0 =====

undefined8
StreamClassReadWriteConfig
          (longlong param_1,char param_2,void *param_3,undefined4 param_4,uint param_5)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
                    /* 0x4fc0  17  StreamClassReadWriteConfig */
  lVar3 = *(longlong *)(param_1 + -0x3b0);
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  if (param_2 != '\0') {
    memset(param_3,0,(ulonglong)param_5);
  }
  lVar3 = IoAllocateIrp(*(undefined1 *)(lVar3 + 0x4c),0);
  uVar4 = 0;
  if (lVar3 != 0) {
    *(undefined4 *)(lVar3 + 0x30) = 0xc00000bb;
    KeInitializeEvent(&local_38,0,0);
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    *(code **)(lVar1 + -0x10) = SCSynchCompletionRoutine;
    *(undefined8 **)(lVar1 + -8) = &local_38;
    *(undefined1 *)(lVar1 + -0x45) = 0xe0;
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    *(undefined4 *)(lVar1 + -0x40) = 0;
    *(undefined1 *)(lVar1 + -0x48) = 0x1b;
    *(char *)(lVar1 + -0x47) = '\x10' - (param_2 != '\0');
    *(void **)(lVar1 + -0x38) = param_3;
    *(undefined4 *)(lVar1 + -0x30) = param_4;
    *(uint *)(lVar1 + -0x28) = param_5;
    iVar2 = IofCallDriver(*(undefined8 *)(param_1 + -0x2b8),lVar3);
    if (iVar2 == 0x103) {
      KeWaitForSingleObject(&local_38,5,0,0,0);
    }
    uVar4 = IoFreeIrp(lVar3);
    uVar4 = CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
  }
  return uVar4;
}



===== StreamClassRegisterFilterWithNoKSPins @ 1c0005100 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int StreamClassRegisterFilterWithNoKSPins
              (longlong param_1,longlong param_2,uint param_3,int *param_4,undefined4 *param_5,
              undefined4 *param_6)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  longlong lVar7;
  longlong lVar8;
  undefined4 *puVar9;
  char *pcVar10;
  int iVar11;
  uint uVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  char *pcVar15;
  char *pcVar16;
  ulonglong uVar17;
  int *piVar18;
  longlong local_b8;
  undefined8 local_b0;
  longlong local_a8;
  char *local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined4 *local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  code *pcStack_48;
  code *local_40;
  
                    /* 0x5100  20  StreamClassRegisterFilterWithNoKSPins */
  local_b0 = 0;
  uVar17 = (ulonglong)param_3;
  local_68 = 0;
  local_40 = (code *)0x0;
  local_78 = 0;
  uStack_70 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  pcStack_48 = (code *)0x0;
  if ((((param_3 == 0) || (param_2 == 0)) || (param_4 == (int *)0x0)) ||
     (param_5 == (undefined4 *)0x0)) {
    iVar6 = -0x3ffffff0;
  }
  else {
    lVar7 = IoGetAttachedDeviceReference(param_1);
    lVar8 = IoAllocateIrp(*(undefined1 *)(lVar7 + 0x4c),0);
    if (lVar8 != 0) {
      lVar1 = *(longlong *)(lVar8 + 0xb8);
      *(undefined1 *)(lVar8 + 0x40) = 0;
      *(undefined4 *)(lVar8 + 0x30) = 0xc00000bb;
      *(undefined2 *)(lVar1 + -0x48) = 0x81b;
      KeInitializeEvent(&local_78,0,0);
      lVar2 = *(longlong *)(lVar8 + 0xb8);
      *(code **)(lVar2 + -0x10) = SCSynchCompletionRoutine;
      *(undefined8 **)(lVar2 + -8) = &local_78;
      *(undefined1 *)(lVar2 + -0x45) = 0xe0;
      *(undefined8 *)(lVar1 + -0x28) = 0;
      *(undefined8 **)(lVar1 + -0x40) = &GUID_STREAM_FDO_INTERFACE;
      *(undefined8 **)(lVar1 + -0x30) = &local_60;
      *(undefined4 *)(lVar1 + -0x38) = 0x10028;
      iVar6 = IofCallDriver(lVar7,lVar8);
      if (iVar6 == 0x103) {
        KeWaitForSingleObject(&local_78,5,0,0,0);
        iVar6 = *(int *)(lVar8 + 0x30);
      }
      IoFreeIrp(lVar8);
      if (-1 < iVar6) {
        local_90 = 0;
        local_a8 = 0;
        local_b8 = 0;
        (*local_40)(uStack_58,&local_90,&local_a8,&local_b8);
        if ((param_1 == local_a8) && (local_a8 != local_b8)) {
          param_1 = local_b8;
        }
        (*pcStack_48)(uStack_58);
      }
    }
    ObfDereferenceObject(lVar7);
    iVar11 = ((-(uint)(param_6 != (undefined4 *)0x0) & param_3) + 1) * 0x10 + param_3 * 0x34;
    puVar9 = (undefined4 *)ExAllocatePoolWithTag(1,iVar11);
    if (puVar9 == (undefined4 *)0x0) {
      iVar6 = -0x3fffff66;
    }
    else {
      puVar9[3] = 0;
      pcVar10 = (char *)(puVar9 + 4);
      *puVar9 = 2;
      uVar12 = 0;
      local_a0 = pcVar10 + uVar17 * 0x1c;
      puVar9[1] = 0x200000;
      puVar9[2] = param_3;
      pcVar15 = local_a0 + uVar17 * 0x18;
      if (param_3 != 0) {
        puVar13 = param_6;
        puVar14 = param_5;
        pcVar16 = local_a0;
        piVar18 = param_4;
        do {
          pcVar10[0] = '0';
          pcVar10[1] = 'p';
          pcVar10[2] = 'i';
          pcVar10[3] = '3';
          *pcVar10 = (char)uVar12 + '0';
          iVar6 = *piVar18;
          pcVar10[8] = '\x01';
          pcVar10[9] = '\0';
          pcVar10[10] = '\0';
          pcVar10[0xb] = '\0';
          pcVar10[0xc] = '\0';
          pcVar10[0xd] = '\0';
          pcVar10[0xe] = '\0';
          pcVar10[0xf] = '\0';
          pcVar10[0x10] = '\x01';
          pcVar10[0x11] = '\0';
          pcVar10[0x12] = '\0';
          pcVar10[0x13] = '\0';
          *(int *)(pcVar10 + 0x18) = (int)pcVar16 - (int)puVar9;
          *(uint *)(pcVar10 + 4) = -(uint)(iVar6 != 0) & 8;
          uVar3 = puVar14[1];
          uVar4 = puVar14[2];
          uVar5 = puVar14[3];
          *(undefined4 *)pcVar16 = *puVar14;
          *(undefined4 *)(pcVar16 + 4) = uVar3;
          *(undefined4 *)(pcVar16 + 8) = uVar4;
          *(undefined4 *)(pcVar16 + 0xc) = uVar5;
          *(undefined8 *)(pcVar16 + 0x10) = *(undefined8 *)(puVar14 + 4);
          pcVar16 = pcVar16 + 0x18;
          if (param_6 == (undefined4 *)0x0) {
            pcVar10[0x14] = '\0';
            pcVar10[0x15] = '\0';
            pcVar10[0x16] = '\0';
            pcVar10[0x17] = '\0';
          }
          else {
            *(int *)(pcVar10 + 0x14) = (int)pcVar15 - (int)puVar9;
            uVar3 = puVar13[1];
            uVar4 = puVar13[2];
            uVar5 = puVar13[3];
            *(undefined4 *)pcVar15 = *puVar13;
            *(undefined4 *)(pcVar15 + 4) = uVar3;
            *(undefined4 *)(pcVar15 + 8) = uVar4;
            *(undefined4 *)(pcVar15 + 0xc) = uVar5;
            pcVar15 = pcVar15 + 0x10;
          }
          uVar12 = uVar12 + 1;
          piVar18 = piVar18 + 1;
          puVar14 = puVar14 + 6;
          puVar13 = puVar13 + 4;
          pcVar10 = pcVar10 + 0x1c;
        } while (uVar12 < param_3);
      }
      local_80 = puVar9;
      iVar6 = IoGetDeviceInterfaces(param_2,param_1,1,&local_b0);
      if (-1 < iVar6) {
        local_b8 = 0;
        local_a0 = (char *)0x0;
        uStack_98 = 0;
        RtlInitUnicodeString(&local_a0,local_b0);
        iVar6 = IoOpenDeviceInterfaceRegistryKey(&local_a0,0x1f0000,&local_b8);
        if (-1 < iVar6) {
          local_90 = 0;
          uStack_88 = 0;
          RtlInitUnicodeString(&local_90,L"FilterData");
          iVar6 = ZwSetValueKey(local_b8,&local_90,0,3,puVar9,iVar11);
          ZwClose(local_b8);
        }
        if (param_3 != 0) {
          do {
            KsCacheMedium(&local_a0,param_5,*param_4 != 0);
            param_5 = param_5 + 6;
            param_4 = param_4 + 1;
            uVar17 = uVar17 - 1;
          } while (uVar17 != 0);
          puVar9 = local_80;
        }
        ExFreePool(local_b0);
      }
      ExFreePool(puVar9);
    }
  }
  return iVar6;
}



===== StreamClassScheduleTimer @ 1c0005520 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void StreamClassScheduleTimer
               (longlong param_1,longlong param_2,undefined4 param_3,undefined8 param_4,
               undefined8 param_5)

{
  code *pcVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  undefined1 local_res18 [16];
  
                    /* 0x5520  21  StreamClassScheduleTimer */
  lVar3 = param_2 + -0x4d0;
  local_res18[0] = 0;
  lVar4 = param_1 + -0x130;
  (**(code **)(param_2 + -0x1a0))(lVar3,local_res18);
  if (param_1 == 0) {
    lVar4 = 0;
    *(uint *)(param_2 + -0x4c0) = *(uint *)(param_2 + -0x4c0) | 1;
    lVar2 = lVar3;
  }
  else {
    lVar2 = lVar4;
  }
  *(uint *)(lVar2 + 0x10) = *(uint *)(lVar2 + 0x10) | 2;
  *(undefined8 *)(lVar2 + 0x28) = param_4;
  *(undefined4 *)(lVar2 + 0x30) = param_3;
  *(undefined8 *)(lVar2 + 0x38) = param_5;
  if (lVar4 == 0) {
    pcVar1 = *(code **)(param_2 + -400);
  }
  else {
    pcVar1 = *(code **)(param_2 + -0x198);
    lVar3 = lVar4;
  }
  (*pcVar1)(lVar3,local_res18);
  return;
}



===== StreamClassStreamNotification @ 1c00055d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void StreamClassStreamNotification
               (int param_1,longlong param_2,longlong *param_3,undefined4 param_4)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [24];
  undefined8 local_48;
  undefined1 local_38 [24];
  
                    /* 0x55d0  22  StreamClassStreamNotification */
  local_38[0] = 0;
  lVar1 = *(longlong *)(param_2 + 0xb8);
  if ((*(char *)(lVar1 + 800) != '\0') && (param_1 == 3)) {
    local_38[0] = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x240);
    *(uint *)(param_3 + 0x10) = *(uint *)(param_3 + 0x10) & 0xfffffffe;
    if (*(int *)((longlong)param_3 + 0x164) == 0) {
      KeReleaseSpinLock(lVar1 + 0x240,local_38[0]);
      (*(code *)param_3[0x26])(param_3);
      return;
    }
    KeReleaseSpinLock();
    return;
  }
  (**(code **)(lVar1 + 0x330))(lVar1,local_38);
  puVar5 = auStack_68;
  puVar6 = auStack_68;
  if (param_1 == 0) {
    *(undefined1 *)(param_2 + 0x129) = 1;
  }
  else if (param_1 == 1) {
    *(undefined1 *)(param_2 + 0x128) = 1;
    puVar6 = auStack_68;
  }
  else if (param_1 == 3) {
    *(uint *)(param_3 + 0x10) = *(uint *)(param_3 + 0x10) & 0xfffffffe;
    param_3[8] = *(longlong *)(param_2 + -0x110);
    *(longlong **)(param_2 + -0x110) = param_3;
    puVar6 = auStack_68;
  }
  else if (param_1 == 4) {
    local_48 = 0;
    KsGenerateEventList(param_3,param_4,param_2 + 0xa8,0);
    puVar6 = auStack_68;
  }
  else {
    if (param_1 != 5) {
      puVar6 = auStack_68;
      if (param_1 != 6) goto LAB_1c0005755;
      lVar2 = *param_3;
      if ((*(longlong **)(lVar2 + 8) == param_3) &&
         (plVar3 = (longlong *)param_3[1], (longlong *)*plVar3 == param_3)) {
        *plVar3 = lVar2;
        *(longlong **)(lVar2 + 8) = plVar3;
        plVar3 = *(longlong **)(lVar1 + 0x390);
        if (*plVar3 == lVar1 + 0x388) {
          *param_3 = lVar1 + 0x388;
          param_3[1] = (longlong)plVar3;
          *plVar3 = (longlong)param_3;
          *(longlong **)(lVar1 + 0x390) = param_3;
          puVar6 = auStack_68;
          goto LAB_1c0005755;
        }
      }
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      puVar5 = auStack_60;
    }
    *(undefined8 *)(puVar5 + -8) = 0x1c0005701;
    KsGenerateEvent(param_3);
    puVar6 = puVar5;
  }
LAB_1c0005755:
  pcVar4 = *(code **)(lVar1 + 0x338);
  *(undefined8 *)(puVar6 + -8) = 0x1c0005769;
  (*pcVar4)(param_2 + -0x130,puVar6 + 0x30);
  return;
}



===== BeginTransfer @ 1c000577c =====

ulonglong BeginTransfer(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong lVar5;
  longlong *plVar6;
  code *pcVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  uint uVar10;
  ulonglong uVar11;
  undefined1 *puVar12;
  longlong *plVar13;
  undefined1 auStack_78 [8];
  undefined1 auStack_70 [24];
  longlong *local_58;
  undefined4 local_50;
  longlong *local_48;
  longlong *local_40;
  undefined4 local_38;
  undefined4 local_30;
  undefined1 local_28;
  
  if (*(int *)(param_2 + 0x25c) == 2) {
    plVar13 = (longlong *)0x0;
    *(undefined4 *)(param_2 + 0x25c) = 3;
    if (*(int *)(param_2 + 0x260) == 0) {
      lVar1 = param_2 + 0x2e0;
      uVar8 = KeAcquireSpinLockRaiseToDpc(lVar1);
      lVar2 = param_2 + 0x288;
      uVar9 = KeAcquireSpinLockRaiseToDpc(lVar2);
      puVar12 = auStack_78;
      plVar3 = (longlong *)(param_2 + 0x278);
      while( true ) {
        plVar4 = (longlong *)*plVar3;
        if (plVar4 == plVar3) break;
        if (((longlong *)plVar4[1] != plVar3) ||
           (lVar5 = *plVar4, *(longlong **)(lVar5 + 8) != plVar4)) {
LAB_1c0005927:
          pcVar7 = (code *)swi(0x29);
          (*pcVar7)(3,uVar9);
          puVar12 = auStack_70;
          break;
        }
        *plVar3 = lVar5;
        plVar13 = plVar4 + -6;
        *(longlong **)(lVar5 + 8) = plVar3;
        LOCK();
        *(int *)(param_2 + 0x370) = *(int *)(param_2 + 0x370) + 1;
        UNLOCK();
        plVar6 = *(longlong **)(param_2 + 0x2f0);
        if (*plVar6 != param_2 + 0x2e8) goto LAB_1c0005927;
        *plVar4 = param_2 + 0x2e8;
        plVar4[1] = (longlong)plVar6;
        *plVar6 = (longlong)plVar4;
        *(longlong **)(param_2 + 0x2f0) = plVar4;
        KeReleaseSpinLock(lVar2);
        KeReleaseSpinLock(lVar1,uVar8);
        LOCK();
        *(int *)(plVar4 + 2) = (int)plVar4[2] + 1;
        UNLOCK();
        local_40 = plVar4 + 6;
        local_28 = 0;
        local_48 = plVar4 + -5;
        local_30 = 0x1000;
        plVar4[4] = *(longlong *)(param_2 + 0x270);
        local_38 = (undefined4)*local_40;
        local_50 = 7;
        local_58 = plVar13;
        uVar10 = KsStreamIo(*(undefined8 *)(param_2 + 0x120),plVar4 + -3,0,IoCompletionRoutine);
        if (uVar10 != 0x103) {
          KeSetEvent(plVar4 + -3,0,0);
        }
        uVar8 = KeAcquireSpinLockRaiseToDpc(lVar1);
        uVar9 = KeAcquireSpinLockRaiseToDpc(lVar2);
        plVar13 = (longlong *)0x0;
        if ((int)uVar10 < 0) {
          plVar13 = (longlong *)(ulonglong)uVar10;
        }
      }
      *(undefined8 *)(puVar12 + -8) = 0x1c0005938;
      KeReleaseSpinLock(lVar2);
      *(undefined8 *)(puVar12 + -8) = 0x1c000594a;
      KeReleaseSpinLock(lVar1,uVar8);
    }
    uVar11 = (ulonglong)plVar13 & 0xffffffff;
  }
  else {
    uVar11 = 0xc0000184;
  }
  return uVar11;
}



===== EndTransfer @ 1c0005978 =====

undefined8 EndTransfer(undefined8 param_1,longlong param_2)

{
  int *piVar1;
  longlong *plVar2;
  int iVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong lVar6;
  code *pcVar7;
  undefined1 uVar8;
  undefined1 *puVar9;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  undefined8 local_18;
  
  lVar4 = *(longlong *)(param_2 + 0x1e8);
  *(undefined4 *)(param_2 + 0x25c) = 1;
  StreamFlushIo(lVar4,param_2);
  LOCK();
  piVar1 = (int *)(param_2 + 0x370);
  iVar3 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar3 != 1) {
    KeSetEvent(lVar4 + 0x2f0,0,0);
    local_18 = 0;
    KeWaitForSingleObject(param_2 + 0x290,0,0,0);
    local_18 = 0;
    KeWaitForSingleObject(lVar4 + 0x2f0,0,0,0);
    LOCK();
    *(undefined4 *)(param_2 + 0x370) = 1;
    UNLOCK();
  }
  lVar4 = param_2 + 0x288;
  uVar8 = KeAcquireSpinLockRaiseToDpc(lVar4);
  puVar9 = auStack_38;
  plVar2 = (longlong *)(param_2 + 0x278);
  do {
    plVar5 = (longlong *)*plVar2;
    if (plVar5 == plVar2) {
LAB_1c0005a9c:
      *(undefined4 *)(param_2 + 0x25c) = 0;
      *(undefined8 *)(puVar9 + -8) = 0x1c0005aaf;
      KeReleaseSpinLock(lVar4,uVar8);
      return 0;
    }
    if (((longlong *)plVar5[1] != plVar2) ||
       (lVar6 = *plVar5, (longlong *)*(longlong *)(lVar6 + 8) != plVar5)) {
      pcVar7 = (code *)swi(0x29);
      uVar8 = (*pcVar7)(3);
      puVar9 = auStack_30;
      goto LAB_1c0005a9c;
    }
    *plVar2 = lVar6;
    *(longlong **)(lVar6 + 8) = plVar2;
    KeReleaseSpinLock(lVar4,uVar8);
    FreeFrame(*(undefined8 *)(param_2 + 0x268),plVar5[0xb]);
    ExFreePool(plVar5 + -6);
    uVar8 = KeAcquireSpinLockRaiseToDpc(lVar4);
  } while( true );
}



===== HeaderTransfer @ 1c0005ad4 =====

bool HeaderTransfer(undefined8 param_1,longlong param_2,longlong param_3,longlong *param_4)

{
  int *piVar1;
  uint *puVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined1 uVar6;
  undefined8 *puVar7;
  longlong *plVar8;
  longlong lVar9;
  undefined1 *puVar10;
  undefined8 *puVar11;
  longlong lVar12;
  bool bVar13;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  puVar2 = (uint *)*param_4;
  lVar12 = 0;
  bVar13 = false;
  if (((*(int *)(param_2 + 0x25c) < 2) || (puVar2[2] == 0xc0000010)) || (puVar2[2] == 0xc0000184)) {
    if (puVar2[0x10] != 0) goto LAB_1c0005c69;
    lVar9 = param_2 + 0x288;
    uVar6 = KeAcquireSpinLockRaiseToDpc(lVar9);
    puVar10 = auStack_38;
    plVar8 = (longlong *)(param_2 + 0x278);
    puVar11 = *(undefined8 **)(param_2 + 0x280);
    puVar7 = (undefined8 *)(*param_4 + 0x30);
    if ((longlong *)*puVar11 != plVar8) goto LAB_1c0005c37;
LAB_1c0005c3e:
    *puVar7 = plVar8;
    puVar7[1] = puVar11;
    *puVar11 = puVar7;
    plVar8[1] = (longlong)puVar7;
  }
  else {
    if ((param_3 == 0) || (((puVar2[0x24] & 0x200) == 0 && (*(int *)(param_2 + 0x2d8) == 0)))) {
      if (puVar2 == (uint *)0x0) {
        return false;
      }
      lVar9 = (ulonglong)(*puVar2 ^ 1) * 0x40;
      lVar12 = lVar9 + param_2;
      uVar6 = KeAcquireSpinLockRaiseToDpc(lVar12 + 0x2e0);
      lVar3 = *param_4;
      puVar11 = (undefined8 *)(param_2 + 0x2e8 + lVar9);
      plVar8 = (longlong *)(lVar3 + 0x30);
      puVar7 = (undefined8 *)puVar11[1];
      if ((undefined8 *)*puVar7 == puVar11) {
        *plVar8 = (longlong)puVar11;
        *(undefined8 **)(lVar3 + 0x38) = puVar7;
        *puVar7 = plVar8;
        puVar11[1] = plVar8;
        KeReleaseSpinLock(lVar12 + 0x2e0,CONCAT71((int7)((ulonglong)plVar8 >> 8),uVar6));
        return false;
      }
LAB_1c0005c37:
      puVar7 = (undefined8 *)0x3;
      pcVar5 = (code *)swi(0x29);
      uVar6 = (*pcVar5)();
      puVar10 = auStack_30;
      goto LAB_1c0005c3e;
    }
    *(undefined4 *)(param_2 + 0x2d8) = 1;
    if (puVar2[0x10] != 0) goto LAB_1c0005c69;
    lVar9 = param_2 + 0x288;
    uVar6 = KeAcquireSpinLockRaiseToDpc(lVar9);
    puVar10 = auStack_38;
    lVar3 = *param_4;
    puVar11 = (undefined8 *)(param_2 + 0x278);
    plVar4 = *(longlong **)(param_2 + 0x280);
    plVar8 = (longlong *)(lVar3 + 0x30);
    if ((undefined8 *)*plVar4 != puVar11) goto LAB_1c0005c37;
    *plVar8 = (longlong)puVar11;
    *(longlong **)(lVar3 + 0x38) = plVar4;
    *plVar4 = (longlong)plVar8;
    *(longlong **)(param_2 + 0x280) = plVar8;
  }
  LOCK();
  piVar1 = (int *)(param_2 + 0x370);
  *piVar1 = *piVar1 + -1;
  bVar13 = *piVar1 == 0;
  UNLOCK();
  *(undefined8 *)(puVar10 + -8) = 0x1c0005c64;
  KeReleaseSpinLock(lVar9,uVar6);
LAB_1c0005c69:
  *param_4 = lVar12;
  return bVar13;
}



===== IoCompletionRoutine @ 1c0005c90 =====

undefined4 IoCompletionRoutine(undefined8 param_1,longlong param_2,uint *param_3)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined1 uVar7;
  code *pcVar8;
  undefined8 uVar9;
  undefined8 *puVar10;
  longlong lVar11;
  
  uVar1 = *param_3;
  lVar11 = (ulonglong)uVar1 * 0x40;
  lVar2 = *(longlong *)(*(longlong *)(param_3 + 0x12) + 0x18);
  lVar3 = *(longlong *)(*(longlong *)(*(longlong *)(param_3 + 0x12) + 0x40) + 0x18);
  uVar7 = KeAcquireSpinLockRaiseToDpc(lVar11 + lVar2 + 0x2e0);
  LOCK();
  param_3[0x10] = param_3[0x10] - 1;
  UNLOCK();
  uVar4 = *(uint *)(param_2 + 0x34);
  uVar5 = *(uint *)(param_2 + 0x38);
  uVar6 = *(uint *)(param_2 + 0x3c);
  param_3[2] = *(uint *)(param_2 + 0x30);
  param_3[3] = uVar4;
  param_3[4] = uVar5;
  param_3[5] = uVar6;
  if (*(int *)(lVar11 + 0x318 + lVar2) == 0) {
    puVar10 = (undefined8 *)(lVar2 + 0x2f8 + lVar11);
    pcVar8 = IoWorkerRead;
    if (uVar1 != 0) {
      pcVar8 = IoWorkerWrite;
    }
    *puVar10 = 0;
    puVar10[2] = pcVar8;
    puVar10[3] = lVar2;
    LOCK();
    *(undefined4 *)(lVar11 + 0x318 + lVar2) = 1;
    UNLOCK();
    if (uVar1 == 0) {
      uVar9 = *(undefined8 *)(lVar3 + 0x40);
    }
    else {
      uVar9 = *(undefined8 *)(lVar3 + 0x48);
    }
    KsQueueWorkItem(uVar9);
  }
  KeReleaseSpinLock(lVar11 + lVar2 + 0x2e0,uVar7);
  return *(undefined4 *)(param_2 + 0x30);
}



===== IoWorker @ 1c0005d90 =====

void IoWorker(longlong param_1,uint param_2)

{
  uint *puVar1;
  longlong *plVar2;
  longlong lVar3;
  code *pcVar4;
  undefined1 uVar5;
  bool bVar6;
  int iVar7;
  longlong lVar8;
  undefined1 *puVar9;
  longlong lVar10;
  longlong lVar11;
  longlong *plVar12;
  uint *local_res8;
  uint local_res10;
  longlong local_res18;
  undefined1 auStack_98 [8];
  undefined1 auStack_90 [24];
  uint *local_78;
  undefined4 local_70;
  uint *local_68;
  uint *local_60;
  uint local_58;
  undefined4 local_50;
  undefined1 local_48;
  
  bVar6 = false;
  if (*(longlong *)(*(longlong *)(param_1 + 0x118) + 0x18) != 0) {
    local_78 = (uint *)0x0;
    local_res18 = *(longlong *)(param_1 + 0x1e8) + 0x2f0;
    local_res10 = param_2;
    KeWaitForSingleObject(local_res18,0,0,0);
    lVar11 = (ulonglong)param_2 * 0x40;
    lVar10 = param_1 + 0x2e0 + lVar11;
    uVar5 = KeAcquireSpinLockRaiseToDpc(lVar10);
    plVar12 = (longlong *)(param_1 + 0x2e8 + lVar11);
    while( true ) {
      plVar2 = (longlong *)*plVar12;
      puVar9 = auStack_98;
      if ((plVar2 == plVar12) ||
         (local_res8 = (uint *)(plVar2 + -6), puVar9 = auStack_98, *(int *)(plVar2 + 2) != 0))
      goto LAB_1c0005f99;
      if (((longlong *)plVar2[1] != plVar12) ||
         (lVar8 = *plVar2, (longlong *)*(longlong *)(lVar8 + 8) != plVar2)) break;
      *plVar12 = lVar8;
      *(longlong **)(lVar8 + 8) = plVar12;
      KeReleaseSpinLock(lVar10,uVar5);
      lVar8 = (longlong)(plVar2 + -3);
      local_78 = (uint *)0x0;
      KeWaitForSingleObject(lVar8,0,0,0);
      lVar3 = plVar2[4];
      bVar6 = HeaderTransfer(lVar8,param_1,lVar3,(longlong *)&local_res8);
      if (local_res8 != (uint *)0x0) {
        if (lVar3 == *(longlong *)(param_1 + 0x270)) {
          *(undefined8 *)(local_res8 + 0x14) = *(undefined8 *)(param_1 + 0x120);
          local_50 = 0x1001;
        }
        else {
          local_res8[0x24] = 0;
          local_50 = 0x1000;
          local_res8[0x21] = 0;
          local_res8[0x1e] = 0;
          local_res8[0x1f] = 0;
          *(undefined8 *)(local_res8 + 0x14) = *(undefined8 *)(param_1 + 0x270);
        }
        LOCK();
        local_res8[0x10] = local_res8[0x10] + 1;
        UNLOCK();
        local_48 = 0;
        local_60 = local_res8 + 0x18;
        *local_res8 = local_res10 ^ 1;
        local_58 = *local_60;
        local_68 = local_res8 + 2;
        puVar1 = local_res8 + 6;
        local_70 = 7;
        local_78 = local_res8;
        iVar7 = KsStreamIo(lVar3);
        if (iVar7 != 0x103) {
          KeSetEvent(puVar1);
        }
      }
      uVar5 = KeAcquireSpinLockRaiseToDpc(lVar10);
    }
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)(3);
    puVar9 = auStack_90;
LAB_1c0005f99:
    LOCK();
    *(undefined4 *)(lVar11 + 0x318 + param_1) = 0;
    UNLOCK();
    if (bVar6 != false) {
      *(undefined8 *)(puVar9 + -8) = 0x1c0005fba;
      KeSetEvent(param_1 + 0x290,0,0);
    }
    *(undefined8 *)(puVar9 + -8) = 0x1c0005fcc;
    KeReleaseSpinLock(lVar10,uVar5);
    *(undefined8 *)(puVar9 + -8) = 0x1c0005fe5;
    KeSetEvent(*(undefined8 *)(puVar9 + 0xb0),0,0);
  }
  return;
}



===== IoWorkerRead @ 1c0006010 =====

void IoWorkerRead(longlong param_1)

{
  IoWorker(param_1,0);
  return;
}



===== IoWorkerWrite @ 1c0006030 =====

void IoWorkerWrite(longlong param_1)

{
  IoWorker(param_1,1);
  return;
}



===== SCCloseInstanceCallback @ 1c0006050 =====

ulonglong SCCloseInstanceCallback(longlong param_1)

{
  longlong *plVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  longlong *plVar7;
  code *pcVar8;
  undefined1 uVar9;
  ulonglong uVar10;
  longlong lVar11;
  
  lVar3 = *(longlong *)(param_1 + 0x18);
  lVar4 = *(longlong *)(param_1 + 0x48);
  lVar11 = lVar3 + -0x4d0;
  lVar5 = *(longlong *)(param_1 + 0x58);
  uVar2 = *(uint *)(param_1 + 8);
  *(int *)(lVar3 + -0x1f8) = *(int *)(lVar3 + -0x1f8) + -1;
  uVar9 = KeAcquireSpinLockRaiseToDpc(lVar3 + -0x290);
  plVar1 = (longlong *)(lVar5 + -0xc0);
  lVar6 = *plVar1;
  if ((*(longlong **)(lVar6 + 8) != plVar1) ||
     (plVar7 = *(longlong **)(lVar5 + -0xb8), (longlong *)*plVar7 != plVar1)) {
    pcVar8 = (code *)swi(0x29);
    (*pcVar8)(3);
    pcVar8 = (code *)swi(3);
    uVar10 = (*pcVar8)();
    return uVar10;
  }
  *plVar7 = lVar6;
  *(longlong **)(lVar6 + 8) = plVar7;
  KeReleaseSpinLock(lVar3 + -0x290,CONCAT71((int7)((ulonglong)plVar1 >> 8),uVar9));
  if (*(int *)(lVar3 + -0x1f8) == 0) {
    if ((*(uint *)(lVar3 + -0x3b8) & 0x100) != 0) {
      IoDetachDevice(*(undefined8 *)(lVar3 + -0x3a8));
      *(undefined8 *)(lVar3 + -0x3a8) = 0;
    }
    if (*(int *)(lVar3 + -0x1f8) == 0) {
      SCSubmitIdleNotification(lVar11,1);
    }
  }
  SCCheckPowerDown(lVar11);
  ObfDereferenceObject(*(undefined8 *)(lVar3 + -0x3b0));
  SciFreeFilterInstance((longlong *)(lVar5 + -0xd0));
  SCDereferenceDriver(lVar11);
  if (*(int *)(lVar4 + 0x30) == -0x3fffffea) {
    SCDequeueAndDeleteSrb(param_1);
  }
  else {
    SCProcessCompletedRequest(param_1);
    KeSetEvent(lVar3 + -0x1e0,0,0);
  }
  return (ulonglong)uVar2;
}



===== SCCloseStreamCallback @ 1c00061b0 =====

ulonglong SCCloseStreamCallback(longlong param_1)

{
  longlong *plVar1;
  int *piVar2;
  uint uVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  longlong *plVar8;
  code *pcVar9;
  undefined1 uVar10;
  ulonglong uVar11;
  
  lVar4 = *(longlong *)(param_1 + 0x48);
  lVar5 = *(longlong *)(param_1 + 0x10);
  lVar6 = *(longlong *)(param_1 + 0x18);
  uVar3 = *(uint *)(param_1 + 8);
  lVar7 = *(longlong *)(lVar4 + 0xb8);
  piVar2 = (int *)(*(longlong *)
                    (*(longlong *)(*(longlong *)(*(longlong *)(lVar7 + 0x30) + 0x40) + 0x18) + 0x38)
                  + (ulonglong)*(uint *)(lVar5 + 4) * 0xc);
  *piVar2 = *piVar2 + -1;
  KsFreeObjectHeader(*(undefined8 *)(lVar5 + -0x130));
  if (*(longlong *)(lVar5 + 0x118) != 0) {
    ExFreePool();
  }
  if ((*(uint *)(param_1 + 0x80) & 2) != 0) {
    SCDequeueAndDeleteSrb(param_1);
    param_1 = 0;
  }
  KeSetEvent(lVar6 + -0x1e0,0,0);
  *(undefined8 *)(*(longlong *)(lVar7 + 0x30) + 0x18) = 0;
  uVar10 = KeAcquireSpinLockRaiseToDpc(lVar6 + -0x290);
  plVar1 = (longlong *)(lVar5 + 0x98);
  lVar7 = *plVar1;
  if ((*(longlong **)(lVar7 + 8) != plVar1) ||
     (plVar8 = *(longlong **)(lVar5 + 0xa0), (longlong *)*plVar8 != plVar1)) {
    pcVar9 = (code *)swi(0x29);
    (*pcVar9)(3);
    pcVar9 = (code *)swi(3);
    uVar11 = (*pcVar9)();
    return uVar11;
  }
  *plVar8 = lVar7;
  *(longlong **)(lVar7 + 8) = plVar8;
  KeReleaseSpinLock(lVar6 + -0x290,CONCAT71((int7)((ulonglong)plVar8 >> 8),uVar10));
  KeCancelTimer(lVar5 + -0xb8);
  if (*(undefined8 **)(lVar5 + 0x108) != (undefined8 *)0x0) {
    ObfDereferenceObject(**(undefined8 **)(lVar5 + 0x108));
    ExFreePool(*(undefined8 *)(lVar5 + 0x108));
  }
  if (*(longlong *)(lVar5 + 0x140) != 0) {
    ObfDereferenceObject();
    *(undefined8 *)(lVar5 + 0x140) = 0;
  }
  if (*(longlong *)(lVar5 + 0x138) != 0) {
    ObfDereferenceObject();
    *(undefined8 *)(lVar5 + 0x138) = 0;
  }
  ObfDereferenceObject(*(undefined8 *)(lVar5 + -0x18));
  ExFreePool((undefined8 *)(lVar5 + -0x130));
  if (param_1 == 0) {
    if (*(int *)(lVar4 + 0x30) != -0x3fffffea) {
      SCCompleteIrp(lVar4,uVar3,lVar6 + -0x4d0);
    }
  }
  else if (*(int *)(lVar4 + 0x30) == -0x3fffffea) {
    SCDequeueAndDeleteSrb(param_1);
    KeWaitForSingleObject(lVar6 + -0x1e0,0,0,0,0);
  }
  else {
    SCProcessCompletedRequest(param_1);
  }
  return (ulonglong)uVar3;
}



===== SCGetStreamDeviceStateCallback @ 1c00063e0 =====

undefined4 SCGetStreamDeviceStateCallback(longlong param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



===== SCSetMasterClockWhenDeviceInaccessible @ 1c00063ec =====

undefined8 SCSetMasterClockWhenDeviceInaccessible(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  longlong *plVar3;
  int local_18;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  uVar1 = *(uint *)(lVar2 + 8);
  if (((*(int *)(lVar2 + 0x18) == 0x2f0003) && (0x17 < *(uint *)(lVar2 + 0x10))) && (7 < uVar1)) {
    if (*(char *)(param_2 + 0x40) != '\0') {
      ProbeForRead(*(undefined8 *)(lVar2 + 0x20),*(uint *)(lVar2 + 0x10),1);
      ProbeForRead(*(undefined8 *)(param_2 + 0x70),uVar1,4);
    }
    plVar3 = *(longlong **)(lVar2 + 0x20);
    if ((((int)((ulonglong)plVar3[2] >> 0x20) == 2) && (local_18 = (int)plVar3[2], local_18 == 3))
       && ((*plVar3 == 0x11cf98ae65aaba60 &&
           ((plVar3[1] == -0x1ba92e50dffff25f && (**(longlong **)(param_2 + 0x70) == 0)))))) {
      lVar2 = *(longlong *)(*(longlong *)(lVar2 + 0x30) + 0x18);
      KeWaitForSingleObject(lVar2 + 0x218,0,0,0,0);
      if (*(undefined8 **)(lVar2 + 0x238) != (undefined8 *)0x0) {
        ObfDereferenceObject(**(undefined8 **)(lVar2 + 0x238));
        ExFreePool(*(undefined8 *)(lVar2 + 0x238));
        *(undefined8 *)(lVar2 + 0x238) = 0;
      }
      KeSetEvent(lVar2 + 0x218,0,0);
      return 0;
    }
  }
  return 0xc0000001;
}



===== SciSetMasterClockInfo @ 1c0006564 =====

void SciSetMasterClockInfo(longlong param_1,undefined8 param_2)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x230);
  *(undefined8 *)(param_1 + 0x238) = param_2;
  KeReleaseSpinLock(param_1 + 0x230,uVar1);
  return;
}



===== StreamClassCancelOutstandingIrp @ 1c00065c0 =====

void StreamClassCancelOutstandingIrp(longlong param_1,undefined8 *param_2)

{
  undefined1 uVar1;
  longlong lVar2;
  undefined1 uVar3;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar2 + 0x240);
  uVar1 = *(undefined1 *)((longlong)param_2 + 0x45);
  IoReleaseCancelSpinLock(uVar3);
  SCCancelOutstandingIrp(lVar2,param_2);
  KeReleaseSpinLockFromDpcLevel();
  StreamClassDpc(0,*(longlong *)(lVar2 + 0x120),0,0);
  KeLowerIrql(uVar1);
  return;
}



===== StreamClassCancelPendingIrp @ 1c0006660 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void StreamClassCancelPendingIrp(longlong param_1,undefined8 *param_2)

{
  longlong *plVar1;
  undefined1 uVar2;
  longlong lVar3;
  undefined8 *puVar4;
  longlong lVar5;
  longlong *plVar6;
  longlong lVar7;
  code *pcVar8;
  undefined1 *puVar9;
  undefined1 uVar10;
  undefined8 uVar11;
  undefined1 *puVar12;
  undefined8 *puVar13;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  uVar10 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x240);
  uVar2 = *(undefined1 *)((longlong)param_2 + 0x45);
  IoReleaseCancelSpinLock(uVar10);
  puVar12 = auStack_48;
  for (puVar13 = *(undefined8 **)(lVar3 + 0x2c8); puVar13 != (undefined8 *)(lVar3 + 0x2c8);
      puVar13 = (undefined8 *)*puVar13) {
    for (puVar4 = (undefined8 *)puVar13[2]; puVar4 != puVar13 + 2; puVar4 = (undefined8 *)*puVar4) {
      uVar11 = SCCheckRequestsForIrp(puVar4 + -6,param_2,'\x01',puVar4[4]);
      if (((char)uVar11 != '\0') ||
         (uVar11 = SCCheckRequestsForIrp(puVar4 + -4,param_2,'\x01',puVar4[4]), (char)uVar11 != '\0'
         )) goto LAB_1c000671d;
    }
  }
  uVar11 = SCCheckRequestsForIrp((undefined8 *)(lVar3 + 0x270),param_2,'\x01',lVar3);
  puVar9 = auStack_48;
  if ((char)uVar11 != '\0') {
LAB_1c000671d:
    plVar1 = param_2 + 0x15;
    lVar5 = *plVar1;
    if ((*(longlong **)(lVar5 + 8) == plVar1) &&
       (plVar6 = (longlong *)param_2[0x16], (longlong *)*plVar6 == plVar1)) {
      *plVar6 = lVar5;
      *(longlong **)(lVar5 + 8) = plVar6;
      lVar7 = param_2[0xf];
      lVar5 = lVar7 + 0x138;
      *(undefined4 *)(lVar7 + 8) = 0xc0000120;
      *(longlong *)lVar5 = lVar5;
      *(longlong *)(lVar7 + 0x140) = lVar5;
      KeReleaseSpinLockFromDpcLevel(lVar3 + 0x240);
      (**(code **)(lVar7 + 0x130))();
      goto LAB_1c000679a;
    }
    pcVar8 = (code *)swi(0x29);
    (*pcVar8)(3);
    puVar9 = auStack_40;
  }
  puVar12 = puVar9;
  *(undefined8 *)(puVar12 + -8) = 0x1c000678b;
  SCCancelOutstandingIrp(lVar3,param_2);
  *(undefined8 *)(puVar12 + -8) = 0x1c0006795;
  KeReleaseSpinLockFromDpcLevel();
LAB_1c000679a:
  lVar3 = *(longlong *)(lVar3 + 0x120);
  *(undefined8 *)(puVar12 + -8) = 0x1c00067ae;
  StreamClassDpc(0,lVar3,0,0);
  *(undefined8 *)(puVar12 + -8) = 0x1c00067b8;
  KeLowerIrql(uVar2);
  return;
}



===== StreamClassDisableDeviceEventHandler @ 1c00067f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void StreamClassDisableDeviceEventHandler(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined8 local_48;
  longlong *plStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined1 local_18;
  
  lVar1 = *(longlong *)(param_1 + 0x18);
  local_18 = 0;
  local_38 = 0;
  local_28 = 0;
  uStack_30 = *(undefined8 *)(*(longlong *)(lVar1 + 0xb8) + 0x220);
  local_48 = 0;
  uStack_20 = *(undefined8 *)(lVar1 + 0x30);
  plStack_40 = param_2;
  if (*(code **)(lVar1 + 0x90) != (code *)0x0) {
    (**(code **)(lVar1 + 0x90))(&local_48);
  }
  lVar1 = *param_2;
  if ((*(longlong **)(lVar1 + 8) == param_2) &&
     (plVar2 = (longlong *)param_2[1], (longlong *)*plVar2 == param_2)) {
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    return;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== StreamClassDisableEventHandler @ 1c0006890 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void StreamClassDisableEventHandler(longlong param_1,longlong *param_2)

{
  longlong *plVar1;
  code *pcVar2;
  longlong lVar3;
  undefined8 local_48;
  longlong *plStack_40;
  undefined8 local_38;
  longlong lStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined1 local_18;
  
  local_18 = 0;
  lVar3 = *(longlong *)(param_1 + 0x18);
  local_38 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if (lVar3 == *(longlong *)(param_1 + 0x20)) {
    lVar3 = *(longlong *)(lVar3 + 0x10);
  }
  lStack_30 = lVar3 + 0x130;
  local_48 = 0;
  plStack_40 = param_2;
  if (*(code **)(lVar3 + 0x188) != (code *)0x0) {
    (**(code **)(lVar3 + 0x188))(&local_48);
  }
  lVar3 = *param_2;
  if ((*(longlong **)(lVar3 + 8) == param_2) &&
     (plVar1 = (longlong *)param_2[1], (longlong *)*plVar1 == param_2)) {
    *plVar1 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar1;
    return;
  }
  pcVar2 = (code *)swi(0x29);
  (*pcVar2)(3);
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}



===== StreamClassEnableDeviceEventHandler @ 1c0006920 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint StreamClassEnableDeviceEventHandler(longlong param_1,undefined8 param_2,longlong param_3)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 uVar3;
  char cVar4;
  undefined8 local_48;
  longlong lStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  undefined8 uStack_20;
  undefined1 local_18;
  
  local_18 = 0;
  lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x28) + 0x40);
  lVar2 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x30) + 0x18);
  local_28 = (ulonglong)((uint)(*(int *)(param_3 + 0x30) - *(int *)(lVar2 + 0x70)) / 0x18);
  uStack_30 = *(undefined8 *)(lVar1 + 0x220);
  uStack_20 = *(undefined8 *)(lVar2 + 0x30);
  local_48 = 1;
  lStack_40 = param_3;
  local_38 = param_2;
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x240);
  cVar4 = (**(code **)(lVar1 + 0x238))
                    (*(undefined8 *)(lVar1 + 0x138),SCEnableDeviceEventSynchronized,&local_48);
  KeReleaseSpinLock(lVar1 + 0x240,uVar3);
  return -(uint)(cVar4 != '\0') & 0xc0000001;
}



===== StreamClassEnableEventHandler @ 1c0006a20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint StreamClassEnableEventHandler(longlong param_1,undefined8 param_2,longlong param_3)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 uVar3;
  char cVar4;
  longlong lVar5;
  undefined8 local_48;
  longlong lStack_40;
  undefined8 local_38;
  longlong lStack_30;
  ulonglong local_28;
  undefined8 uStack_20;
  undefined1 local_18;
  
  local_18 = 0;
  uStack_20 = 0;
  lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x28) + 0x40);
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x30);
  lVar5 = *(longlong *)(lVar2 + 0x18);
  if (lVar5 == *(longlong *)(lVar2 + 0x20)) {
    lVar5 = *(longlong *)(lVar5 + 0x10);
  }
  lStack_30 = lVar5 + 0x130;
  local_28 = (ulonglong)((uint)(*(int *)(param_3 + 0x30) - *(int *)(lVar5 + 0x208)) / 0x18);
  local_48 = 1;
  lStack_40 = param_3;
  local_38 = param_2;
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x240);
  cVar4 = (**(code **)(lVar1 + 0x238))
                    (*(undefined8 *)(lVar1 + 0x138),SCEnableEventSynchronized,&local_48);
  KeReleaseSpinLock(lVar1 + 0x240,uVar3);
  return -(uint)(cVar4 != '\0') & 0xc0000001;
}



===== StreamClassInterrupt @ 1c0006b20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1 StreamClassInterrupt(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  undefined1 uVar2;
  
  lVar1 = *(longlong *)(param_2 + 0x40);
  if ((*(uint *)(*(longlong *)(lVar1 + 0x328) + 0x58) & 2) == 0) {
    uVar2 = (**(code **)(*(longlong *)(lVar1 + 0x210) + 8))(*(undefined8 *)(lVar1 + 0x220));
    if ((*(longlong *)(lVar1 + 0x2e0) != 0) || ((*(uint *)(lVar1 + 0x10) & 1) != 0)) {
      KeInsertQueueDpc(lVar1 + 0x280,0,0);
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



===== StreamClassMinidriverDeviceMethod @ 1c0006ba0 =====

ulonglong StreamClassMinidriverDeviceMethod
                    (undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  uint *puVar6;
  ulonglong uVar7;
  char local_res8 [8];
  
  lVar3 = param_1[0x17];
  local_res8[0] = '\0';
  lVar4 = *(longlong *)(*(longlong *)(lVar3 + 0x28) + 0x40);
  lVar5 = *(longlong *)(*(longlong *)(lVar3 + 0x30) + 0x18);
  puVar6 = (uint *)ExAllocatePoolWithTag(0x200,0x20);
  if (puVar6 == (uint *)0x0) {
    uVar7 = 0xc000009a;
  }
  else {
    iVar1 = *(int *)(param_1 + 0xf);
    iVar2 = *(int *)(lVar5 + 0x50);
    *(undefined8 *)(puVar6 + 2) = param_2;
    *(undefined8 *)(puVar6 + 4) = param_3;
    *puVar6 = (uint)(iVar1 - iVar2) / 0x28;
    puVar6[6] = *(uint *)(lVar3 + 0x10);
    puVar6[7] = *(uint *)(lVar3 + 8);
    uVar7 = SCSubmitRequest(0x10f,(longlong)puVar6,0,SCProcessCompletedMethodRequest,lVar4,
                            *(longlong *)(lVar5 + 0x30),0,param_1,local_res8,
                            (longlong *)(lVar4 + 0x260),
                            *(undefined **)(*(longlong *)(lVar4 + 0x210) + 0x10));
    uVar7 = uVar7 & 0xffffffff;
    if (local_res8[0] == '\0') {
      ExFreePool(puVar6);
    }
  }
  return uVar7;
}



===== StreamClassTickHandler @ 1c0006cd0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void StreamClassTickHandler(longlong param_1)

{
  undefined8 *puVar1;
  longlong lVar2;
  int *piVar3;
  undefined8 *puVar4;
  longlong lVar5;
  int iVar6;
  longlong lVar7;
  
  lVar7 = *(longlong *)(param_1 + 0x40);
  KeAcquireSpinLockAtDpcLevel(lVar7 + 0x240);
  puVar4 = *(undefined8 **)(lVar7 + 0x270);
  do {
    if (puVar4 == (undefined8 *)(lVar7 + 0x270)) {
LAB_1c0006df8:
      KeReleaseSpinLockFromDpcLevel(lVar7 + 0x240);
      return;
    }
    puVar1 = puVar4 + -0x27;
    if ((((*(uint *)(puVar4 + -0x17) & 1) != 0) && (*(int *)((longlong)puVar4 + -0x104) != 0)) &&
       (iVar6 = *(int *)((longlong)puVar4 + -0x104) + -1,
       *(int *)((longlong)puVar4 + -0x104) = iVar6, iVar6 == 0)) {
      lVar5 = puVar4[-0x24];
      lVar7 = lVar5 + -0x4d0;
      *(undefined4 *)((longlong)puVar4 + -0x104) = *(undefined4 *)(puVar4 + -0x20);
      if (*(char *)(lVar5 + -0x1b0) == '\0') {
        (**(code **)(lVar5 + -0x298))
                  (*(undefined8 *)(lVar5 + -0x398),
                   *(undefined8 *)(*(longlong *)(lVar5 + -0x2c0) + 0x20),puVar1);
      }
      else {
        *(int *)((longlong)puVar4 + 0x2c) = *(int *)((longlong)puVar4 + 0x2c) + 1;
        lVar2 = lVar5 + -0x290;
        KeReleaseSpinLockFromDpcLevel(lVar2);
        (**(code **)(*(longlong *)(lVar5 + -0x2c0) + 0x20))(puVar1);
        KeAcquireSpinLockAtDpcLevel(lVar2);
        piVar3 = (int *)((longlong)puVar4 + 0x2c);
        *piVar3 = *piVar3 + -1;
        if ((*piVar3 == 0) && ((*(uint *)(puVar4 + -0x17) & 1) == 0)) {
          KeReleaseSpinLockFromDpcLevel(lVar2);
          (*(code *)puVar4[-1])(puVar1);
          KeAcquireSpinLockAtDpcLevel(lVar2);
        }
      }
      goto LAB_1c0006df8;
    }
    puVar4 = (undefined8 *)*puVar4;
  } while( true );
}



===== StreamDispatchCleanup @ 1c0006e24 =====

undefined8 StreamDispatchCleanup(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  bool bVar3;
  longlong lVar4;
  undefined4 local_res8 [2];
  undefined8 local_res10;
  undefined4 uVar5;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  uVar5 = 0;
  lVar4 = lVar1 + 0x2f0;
  lVar2 = *(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x18);
  KeWaitForSingleObject(lVar4,0,0,0,0);
  if (((0 < *(int *)(lVar2 + 0x254)) && (*(int *)(lVar2 + 0x260) == 0)) &&
     (*(char *)(lVar2 + 0x36c) != '\0')) {
    EndTransfer(lVar4,lVar2);
  }
  bVar3 = false;
  if ((*(longlong **)(lVar2 + 0x238) != (longlong *)0x0) &&
     (lVar4 = **(longlong **)(lVar2 + 0x238), lVar4 != 0)) {
    bVar3 = false;
    if (*(longlong *)(lVar4 + 0x40) == *(longlong *)(lVar2 + 0x120)) {
      bVar3 = true;
    }
  }
  KeSetEvent(lVar1 + 0x2f0,0,0);
  if (bVar3) {
    local_res10 = 0;
    local_res8[0] = 0;
    local_38 = 0x65aaba60;
    uStack_34 = 0x11cf98ae;
    uStack_30 = 0x20000da1;
    uStack_2c = 0xe456d1af;
    local_28 = 3;
    local_24 = 2;
    KsSynchronousIoControlDevice
              (*(undefined8 *)(lVar2 + 0x120),0,0x2f0003,&local_38,CONCAT44(uVar5,0x18),&local_res10
               ,8,local_res8);
  }
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== StreamFlushIo @ 1c0006f7c =====

void StreamFlushIo(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong lVar6;
  undefined8 uVar7;
  code *pcVar8;
  undefined1 uVar9;
  undefined8 *puVar10;
  undefined1 *puVar11;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  lVar1 = param_1 + 0x240;
  uVar9 = KeAcquireSpinLockRaiseToDpc(lVar1);
  puVar11 = auStack_38;
  while( true ) {
    plVar3 = *(longlong **)(param_2 + 0x198);
    if (plVar3 == (longlong *)(param_2 + 0x198)) break;
    lVar4 = *plVar3;
    if (((longlong *)*(longlong *)(lVar4 + 8) != plVar3) ||
       (plVar5 = (longlong *)plVar3[1], (longlong *)*plVar5 != plVar3)) goto LAB_1c00070a8;
    *plVar5 = lVar4;
    *(longlong **)(lVar4 + 8) = plVar5;
    LOCK();
    plVar3[-8] = 0;
    UNLOCK();
    KeReleaseSpinLock(lVar1,uVar9);
    lVar6 = plVar3[-6];
    lVar4 = lVar6 + 0x138;
    *(undefined4 *)(lVar6 + 8) = 0xc0000120;
    *(longlong *)lVar4 = lVar4;
    *(longlong *)(lVar6 + 0x140) = lVar4;
    SCCallBackSrb(lVar6,param_1);
    uVar9 = KeAcquireSpinLockRaiseToDpc(lVar1);
  }
  while( true ) {
    plVar3 = *(longlong **)(param_2 + 0x1a8);
    if (plVar3 == (longlong *)(param_2 + 0x1a8)) break;
    lVar4 = *plVar3;
    if (((longlong *)*(longlong *)(lVar4 + 8) != plVar3) ||
       (plVar5 = (longlong *)plVar3[1], (longlong *)*plVar5 != plVar3)) goto LAB_1c00070a8;
    *plVar5 = lVar4;
    *(longlong **)(lVar4 + 8) = plVar5;
    LOCK();
    plVar3[-8] = 0;
    UNLOCK();
    KeReleaseSpinLock(lVar1,uVar9);
    lVar6 = plVar3[-6];
    lVar4 = lVar6 + 0x138;
    *(undefined4 *)(lVar6 + 8) = 0xc0000120;
    *(longlong *)lVar4 = lVar4;
    *(longlong *)(lVar6 + 0x140) = lVar4;
    SCCallBackSrb(lVar6,param_1);
    uVar9 = KeAcquireSpinLockRaiseToDpc(lVar1);
  }
LAB_1c00070af:
  puVar2 = (undefined8 *)(param_1 + 0x270);
  for (puVar10 = (undefined8 *)*puVar2; puVar10 != puVar2; puVar10 = (undefined8 *)*puVar10) {
    if (((param_2 == puVar10[-0x25] + -0x130) && (puVar10[-0x1e] != 0)) &&
       (*(char *)(puVar10[-0x1e] + 0x44) == '\0')) {
      *(undefined8 *)(puVar11 + -8) = 0x1c00070e9;
      KeReleaseSpinLockFromDpcLevel(lVar1);
      uVar7 = puVar10[-0x1e];
      *(undefined8 *)(puVar11 + -8) = 0x1c00070fc;
      IoCancelIrp(uVar7);
      *(undefined8 *)(puVar11 + -8) = 0x1c000710b;
      KeAcquireSpinLockAtDpcLevel(lVar1);
      puVar10 = puVar2;
    }
  }
  *(undefined8 *)(puVar11 + -8) = 0x1c0007125;
  KeReleaseSpinLockFromDpcLevel();
  lVar1 = *(longlong *)(param_1 + 0x120);
  *(undefined8 *)(puVar11 + -8) = 0x1c000713e;
  StreamClassDpc(0,lVar1,0,0);
  *(undefined8 *)(puVar11 + -8) = 0x1c0007148;
  KeLowerIrql(uVar9);
  return;
LAB_1c00070a8:
  pcVar8 = (code *)swi(0x29);
  (*pcVar8)(3);
  puVar11 = auStack_30;
  goto LAB_1c00070af;
}



===== CompleteMapping @ 1c0007170 =====

/* private: void __cdecl DMABuffer::CompleteMapping(class DMATransfer & __ptr64) __ptr64 */

void __thiscall DMABuffer::CompleteMapping(DMABuffer *this,DMATransfer *param_1)

{
  ulong uVar1;
  uint uVar2;
  uchar *puVar3;
  void *_Src;
  _MDL *p_Var4;
  uint uVar5;
  ulonglong uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  ulonglong _Size;
  void *_Dst;
  int local_res8;
  
  for (p_Var4 = param_1->TargetMDL; p_Var4 != (_MDL *)0x0; p_Var4 = p_Var4->Next) {
    KeFlushIoBuffers(p_Var4,param_1->IsRead);
  }
  if (this->PagesToMap != 0) {
    p_Var4 = param_1->TargetMDL;
    param_1->PagesMapped = this->PagesToMap;
    local_res8 = 0;
    if (p_Var4 != (_MDL *)0x0) {
      do {
        uVar5 = 0;
        _Size = (ulonglong)p_Var4->ByteCount;
        uVar8 = (uint)(_Size + 0xfff +
                       (ulonglong)(*(int *)&p_Var4->StartVa + p_Var4->ByteOffset & 0xfff) >> 0xc);
        uVar1 = this->PagesToMap;
        while (uVar1 != 0) {
          if (uVar8 <= uVar5) goto LAB_1c0007369;
          uVar2 = 0x1000;
          if (uVar5 == 0) {
            uVar2 = 0x1000 - p_Var4->ByteOffset;
          }
          uVar9 = (uint)_Size;
          if ((uVar2 <= uVar9) && (_Size = 0x1000, uVar5 == 0)) {
            _Size = (ulonglong)(0x1000 - p_Var4->ByteOffset);
          }
          if (param_1->OriginalPage[uVar5 + local_res8] < 0x100000) {
            param_1->Page[uVar5 + local_res8] = param_1->OriginalPage[uVar5 + local_res8];
          }
          else {
            uVar6 = 0;
            puVar3 = this->Bitmap;
            do {
              if (*puVar3 != 0xff) break;
              uVar2 = (int)uVar6 + 1;
              uVar6 = (ulonglong)uVar2;
              puVar3 = puVar3 + 1;
            } while (uVar2 < 0x40);
            uVar2 = 0;
            do {
              if ((this->Bitmap[uVar6] >> (uVar2 & 0x1f) & 1) == 0) break;
              uVar2 = uVar2 + 1;
            } while (uVar2 < 8);
            uVar7 = uVar2 + (int)uVar6 * 8;
            this->Bitmap[uVar6] = this->Bitmap[uVar6] | (byte)(1 << (uVar2 & 0x1f));
            param_1->Bitmap[uVar6] = param_1->Bitmap[uVar6] | (byte)(1 << (uVar2 & 0x1f));
            param_1->Page[uVar5 + local_res8] = (ulong64)(&this->MDLForBuffer[1].Next)[uVar7];
            if (param_1->IsRead == '\0') {
              _Dst = (void *)((ulonglong)(uVar7 * 0x1000) + (longlong)this->Buffer);
              if (uVar5 == 0) {
                _Dst = (void *)((longlong)_Dst + (ulonglong)p_Var4->ByteOffset);
              }
              if ((p_Var4->MdlFlags & 5) == 0) {
                _Src = (void *)MmMapLockedPagesSpecifyCache(p_Var4,0,1,0,0,0x40000010);
              }
              else {
                _Src = p_Var4->MappedSystemVa;
              }
              if (uVar5 != 0) {
                _Src = (void *)((longlong)_Src + (ulonglong)(uVar5 * 0x1000 - p_Var4->ByteOffset));
              }
              memmove(_Dst,_Src,_Size);
            }
            this->PagesToMap = this->PagesToMap - 1;
          }
          _Size = (ulonglong)(uVar9 - (int)_Size);
          uVar5 = uVar5 + 1;
          uVar1 = this->PagesToMap;
        }
        for (; uVar5 < uVar8; uVar5 = uVar5 + 1) {
          param_1->Page[uVar5 + local_res8] = param_1->OriginalPage[uVar5 + local_res8];
        }
LAB_1c0007369:
        p_Var4 = p_Var4->Next;
        local_res8 = local_res8 + uVar8;
      } while (p_Var4 != (_MDL *)0x0);
    }
    this->PagesAvailable = this->PagesAvailable - param_1->PagesMapped;
    KeFlushIoBuffers(this->MDLForBuffer,param_1->IsRead,1);
  }
  ComputeScatterGatherList((longlong)this->Owner,(longlong)param_1->Owner);
  return;
}



===== ComputeScatterGatherList @ 1c00073d0 =====

void ComputeScatterGatherList(longlong param_1,longlong param_2)

{
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong *plVar6;
  undefined8 *puVar7;
  uint uVar8;
  int iVar9;
  
  *(undefined4 *)(param_2 + 0x74) = 0;
  uVar4 = 0;
  lVar1 = *(longlong *)(param_2 + 0x10);
  plVar6 = *(longlong **)(param_2 + 0x68);
  puVar7 = *(undefined8 **)(*(longlong *)(param_2 + 0x48) + 8);
  do {
    if (puVar7 == (undefined8 *)0x0) {
      if (*(char *)(param_1 + 800) == '\0') {
        SCStartMinidriverRequest(lVar1 + -0x130,param_2,*(undefined8 *)(lVar1 + 0x10));
      }
      else {
        KeSetEvent(param_2 + 0x168,0,0);
      }
      return;
    }
    uVar8 = *(uint *)(puVar7 + 5);
    while (uVar8 != 0) {
      *(undefined4 *)(plVar6 + 1) = 0;
      lVar3 = *(longlong *)(*(longlong *)(param_2 + 0x118) + uVar4 * 8) * 0x1000;
      *plVar6 = lVar3;
      if (uVar8 == *(uint *)(puVar7 + 5)) {
        *plVar6 = (ulonglong)*(uint *)((longlong)puVar7 + 0x2c) + lVar3;
      }
      iVar9 = 0;
      uVar5 = uVar4;
      do {
        uVar2 = 0x1000;
        if (uVar8 == *(uint *)(puVar7 + 5)) {
          uVar2 = 0x1000 - *(int *)((longlong)puVar7 + 0x2c);
        }
        if (uVar8 < uVar2) {
          uVar2 = uVar8;
        }
        iVar9 = iVar9 + uVar2;
        *(int *)(plVar6 + 1) = iVar9;
        uVar8 = uVar8 - uVar2;
        uVar4 = uVar5;
        if ((uVar8 == 0) ||
           (uVar2 = (int)uVar5 + 1, uVar4 = (ulonglong)uVar2, *(uint *)(param_2 + 0x114) <= uVar2))
        break;
        lVar3 = uVar5 * 8;
        uVar5 = uVar4;
      } while (*(longlong *)(*(longlong *)(param_2 + 0x118) + uVar4 * 8) ==
               *(longlong *)(*(longlong *)(param_2 + 0x118) + lVar3) + 1);
      plVar6 = plVar6 + 2;
      *(int *)(param_2 + 0x74) = *(int *)(param_2 + 0x74) + 1;
    }
    puVar7 = (undefined8 *)*puVar7;
  } while( true );
}



===== DoneMapping @ 1c00074ec =====

/* public: long __cdecl DMABuffer::DoneMapping(class DMATransfer & __ptr64) __ptr64 */

long __thiscall DMABuffer::DoneMapping(DMABuffer *this,DMATransfer *param_1)

{
  _MDL *p_Var1;
  _MDL *p_Var2;
  _MDL *p_Var3;
  uint uVar4;
  undefined1 uVar5;
  uint uVar6;
  uchar *puVar7;
  DMATransfer *pDVar8;
  ulonglong _Size;
  uint uVar9;
  longlong lVar10;
  uint uVar11;
  void *_Dst;
  uint uVar12;
  void *pvVar13;
  uint local_res18;
  uint local_res20;
  void *local_60;
  longlong local_50;
  
  uVar5 = KeAcquireSpinLockRaiseToDpc();
  if (param_1->Page == param_1->OriginalPage) {
    DMATransfer::Purge(param_1);
  }
  else {
    if (param_1->IsRead != '\0') {
      p_Var1 = this->MDLForBuffer;
      p_Var2 = param_1->TargetMDL;
      pvVar13 = this->Buffer;
      local_res18 = 0;
      local_60 = pvVar13;
      uVar4 = 0;
      for (; p_Var2 != (_MDL *)0x0; p_Var2 = p_Var2->Next) {
        if ((p_Var2->MdlFlags & 5) == 0) {
          _Dst = (void *)MmMapLockedPagesSpecifyCache(p_Var2,0,1,0,0,0x40000010);
        }
        else {
          _Dst = p_Var2->MappedSystemVa;
        }
        local_res20 = p_Var2->ByteCount;
        uVar9 = (int)((ulonglong)local_res20 + 0xfff + (ulonglong)((uint)_Dst & 0xfff) >> 0xc) +
                uVar4;
        if (uVar4 < uVar9) {
          local_50 = (ulonglong)uVar4 * 8;
          _Size = (ulonglong)local_res20;
          uVar12 = uVar4;
          do {
            uVar11 = (uint)_Size;
            if (0x1000 < uVar11) {
              _Size = 0x1000;
            }
            if ((uVar12 == uVar4) && (uVar6 = 0x1000 - p_Var2->ByteOffset, uVar6 <= (uint)_Size)) {
              _Size = (ulonglong)uVar6;
            }
            p_Var3 = *(_MDL **)(local_50 + (longlong)param_1->Page);
            if (*(_MDL **)(local_50 + (longlong)param_1->OriginalPage) != p_Var3) {
              if (local_res18 < 0x200) {
                do {
                  if ((&p_Var1[1].Next)[local_res18] == p_Var3) break;
                  pvVar13 = (void *)((longlong)pvVar13 + 0x1000);
                  local_res18 = local_res18 + 1;
                } while (local_res18 < 0x200);
                local_60 = pvVar13;
              }
              if (uVar12 == uVar4) {
                uVar11 = p_Var2->ByteOffset;
              }
              else {
                uVar11 = 0;
              }
              memmove(_Dst,(void *)((ulonglong)uVar11 + (longlong)local_60),_Size);
              uVar11 = local_res20;
            }
            local_res20 = uVar11 - (int)_Size;
            _Dst = (void *)((longlong)_Dst + _Size);
            local_50 = local_50 + 8;
            uVar12 = uVar12 + 1;
            _Size = (ulonglong)local_res20;
            pvVar13 = local_60;
          } while (uVar12 < uVar9);
        }
        uVar4 = uVar9;
      }
    }
    puVar7 = this->Bitmap;
    lVar10 = 0x40;
    do {
      if (puVar7[(longlong)param_1 + (-0x34 - (longlong)this)] != 0) {
        *puVar7 = *puVar7 & ~puVar7[(longlong)param_1 + (-0x34 - (longlong)this)];
      }
      puVar7 = puVar7 + 1;
      lVar10 = lVar10 + -1;
    } while (lVar10 != 0);
    this->PagesAvailable = this->PagesAvailable + param_1->PagesMapped;
    DMATransfer::Purge(param_1);
    pDVar8 = this->NextTransfer;
    if (pDVar8 != (DMATransfer *)0x0) {
      do {
        if (this->PagesAvailable < pDVar8->PagesNeeded) goto LAB_1c0007771;
        this->PagesToMap = pDVar8->PagesNeeded;
        CompleteMapping(this,pDVar8);
        pDVar8 = this->NextTransfer->NextTransfer;
        this->NextTransfer = pDVar8;
      } while (pDVar8 != (DMATransfer *)0x0);
      this->LastTransfer = (DMATransfer *)0x0;
    }
  }
LAB_1c0007771:
  KeReleaseSpinLock(this,uVar5);
  return 0;
}



===== Purge @ 1c00077a0 =====

/* public: void __cdecl DMATransfer::Purge(void) __ptr64 */

void __thiscall DMATransfer::Purge(DMATransfer *this)

{
  _STREAM_REQUEST_BLOCK *p_Var1;
  
  if ((this->Page != (ulong64 *)0x0) && (this->Page != this->OriginalPage)) {
    ExFreePool();
  }
  if (((_MDL *)this->OriginalPage != (_MDL *)0x0) &&
     ((_MDL *)this->OriginalPage != this->TargetMDL + 1)) {
    ExFreePool();
  }
  p_Var1 = this->Owner;
  memset(this,0,0x88);
  this->Owner = p_Var1;
  return;
}



===== StartMapping @ 1c0007818 =====

/* public: long __cdecl DMABuffer::StartMapping(class DMATransfer & __ptr64,struct _MDL *
   __ptr64,bool) __ptr64 */

long __thiscall
DMABuffer::StartMapping(DMABuffer *this,DMATransfer *param_1,_MDL *param_2,bool param_3)

{
  ulong uVar1;
  undefined1 uVar2;
  _MDL *p_Var3;
  void *pvVar4;
  ulong64 *puVar5;
  uint uVar6;
  ulonglong uVar7;
  uint uVar8;
  ulong64 **ppuVar9;
  _MDL *p_Var10;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc();
  this->PagesToMap = 0;
  uVar6 = 0;
  for (p_Var10 = param_2; p_Var10 != (_MDL *)0x0; p_Var10 = p_Var10->Next) {
    uVar7 = (ulonglong)p_Var10->ByteCount + 0xfff +
            (ulonglong)(p_Var10->ByteOffset + *(int *)&p_Var10->StartVa & 0xfff) >> 0xc;
    uVar6 = uVar6 + (int)uVar7;
    if ((int)uVar7 != 0) {
      p_Var3 = p_Var10 + 1;
      do {
        if ((_MDL *)0xfffff < p_Var3->Next) {
          this->PagesToMap = this->PagesToMap + 1;
        }
        p_Var3 = (_MDL *)&p_Var3->Size;
        uVar7 = uVar7 - 1;
      } while (uVar7 != 0);
    }
  }
  uVar1 = this->PagesToMap;
  param_1->TargetMDL = param_2;
  if ((param_2->MdlFlags & 5) == 0) {
    pvVar4 = (void *)MmMapLockedPagesSpecifyCache(param_2,0,1,0,0,0x40000010);
  }
  else {
    pvVar4 = param_2->MappedSystemVa;
  }
  param_1->TargetAddress = pvVar4;
  if (pvVar4 != (void *)0x0) {
    uVar8 = param_1->TargetMDL->ByteCount;
    param_1->IsRead = param_3;
    ppuVar9 = &param_1->OriginalPage;
    param_1->Size = uVar8;
    uVar8 = (uint)((ulonglong)(*(uint *)&param_1->TargetAddress & 0xfff) + 0xfff + (ulonglong)uVar8
                  >> 0xc);
    param_1->Pages = uVar8;
    if (uVar8 < uVar6) {
      puVar5 = (ulong64 *)ExAllocatePoolWithTag(0x200,(ulonglong)uVar6 << 3,0x34365353);
      p_Var10 = param_1->TargetMDL;
      *ppuVar9 = puVar5;
      if (p_Var10 != (_MDL *)0x0) {
        uVar8 = 0;
        do {
          uVar7 = (ulonglong)p_Var10->ByteCount +
                  (ulonglong)(p_Var10->ByteOffset + *(int *)&p_Var10->StartVa & 0xfff) + 0xfff >>
                  0xc;
          memmove(*ppuVar9 + uVar8,p_Var10 + 1,uVar7 << 3);
          p_Var10 = p_Var10->Next;
          uVar8 = uVar8 + (int)uVar7;
        } while (p_Var10 != (_MDL *)0x0);
      }
      param_1->Pages = uVar6;
    }
    else {
      *ppuVar9 = (ulong64 *)(param_1->TargetMDL + 1);
    }
    ppuVar9 = &param_1->OriginalPage;
    if ((uVar1 == 0) || (*ppuVar9 == (ulong64 *)0x0)) {
      puVar5 = *ppuVar9;
    }
    else {
      puVar5 = (ulong64 *)ExAllocatePoolWithTag(0x200,(ulonglong)uVar6 << 3,0x34365353);
    }
    param_1->Page = puVar5;
    if (((puVar5 != (ulong64 *)0x0) && (*ppuVar9 != (ulong64 *)0x0)) && (uVar1 != 0)) {
      memset(puVar5,0,(ulonglong)param_1->Pages << 3);
    }
    if ((param_1->Page != (ulong64 *)0x0) && (this->PagesToMap <= this->MaximumPages)) {
      if (this->NextTransfer == (DMATransfer *)0x0) {
        if (this->PagesToMap <= this->PagesAvailable) {
          CompleteMapping(this,param_1);
          KeReleaseSpinLock(this,uVar2);
          return 0;
        }
        this->NextTransfer = param_1;
      }
      if (this->LastTransfer != (DMATransfer *)0x0) {
        this->LastTransfer->NextTransfer = param_1;
      }
      this->LastTransfer = param_1;
      param_1->PagesNeeded = this->PagesToMap;
      KeReleaseSpinLock(this,uVar2);
      return 0x103;
    }
  }
  KeReleaseSpinLock(this,uVar2);
  return -0x3fffff66;
}



===== dma64ConstructBuffer @ 1c0007ad4 =====

void dma64ConstructBuffer(longlong param_1)

{
  memset((void *)(param_1 + 0x158),0,0xb8);
  KeInitializeSpinLock((void *)(param_1 + 0x158));
  *(undefined8 *)(param_1 + 0x168) = 0;
  *(undefined4 *)(param_1 + 0x170) = 0;
  *(undefined4 *)(param_1 + 0x160) = 1;
  KeInitializeEvent(param_1 + 0x178,1,0);
  *(longlong *)(param_1 + 0x1f8) = param_1;
  return;
}



===== dma64DestroyBuffer @ 1c0007b44 =====

void dma64DestroyBuffer(longlong param_1)

{
  longlong *plVar1;
  
  plVar1 = (longlong *)(param_1 + 0x1a0);
  if (*(longlong *)(param_1 + 0x198) != 0) {
    MmUnmapLockedPages(*(longlong *)(param_1 + 0x198),*plVar1);
  }
  if (*plVar1 != 0) {
    MmFreePagesFromMdl();
    ExFreePool(*plVar1);
  }
  return;
}



===== dma64InitBuffer @ 1c0007ba0 =====

undefined8 dma64InitBuffer(longlong param_1,char param_2)

{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  
  uVar5 = 0;
  if (param_2 == '\0') {
    return 0;
  }
  lVar1 = param_1 + 0x160;
  ExAcquireFastMutex(lVar1);
  plVar2 = (longlong *)(param_1 + 0x1a0);
  if ((*(longlong *)(param_1 + 0x198) == 0) || (*plVar2 == 0)) {
    lVar3 = MmAllocatePagesForMdl(0,0xffffffff,0,0x200000);
    *plVar2 = lVar3;
    if (lVar3 != 0) {
      lVar3 = MmMapLockedPages(lVar3,0);
      *(longlong *)(param_1 + 0x198) = lVar3;
      if (lVar3 != 0) {
        uVar4 = (undefined4)
                ((ulonglong)*(uint *)(*plVar2 + 0x28) +
                 (ulonglong)(*(uint *)(param_1 + 0x198) & 0xfff) + 0xfff >> 0xc);
        *(undefined4 *)(param_1 + 0x1e8) = uVar4;
        *(undefined4 *)(param_1 + 0x1f0) = uVar4;
        goto LAB_1c0007c97;
      }
      MmFreePagesFromMdl(*plVar2);
      ExFreePool(*plVar2);
      *plVar2 = 0;
    }
    ExReleaseFastMutex(lVar1);
    uVar5 = 0xc000009a;
  }
  else {
LAB_1c0007c97:
    ExReleaseFastMutex(lVar1);
  }
  return uVar5;
}



===== dma64InitTransfer @ 1c0007cc4 =====

void dma64InitTransfer(longlong param_1)

{
  memset((void *)(param_1 + 0x98),0,0x88);
  *(longlong *)(param_1 + 0xf8) = param_1;
  return;
}



===== __GSHandlerCheck @ 1c0007d08 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c0007d2c =====

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



===== __cpu_features_init @ 1c0007da0 =====

/* WARNING: Removing unreachable block (ram,0x0001c0007e0a) */
/* WARNING: Removing unreachable block (ram,0x0001c0007db9) */
/* WARNING: Removing unreachable block (ram,0x0001c0007daa) */

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



===== __security_check_cookie @ 1c0007e70 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0007eb0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0007ee0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0007ee0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0007f10 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 1c0007f80 =====

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



===== memset @ 1c0008280 =====

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



===== __memset_repmovs @ 1c00083c0 =====

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



===== __memset_query @ 1c0008440 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c00084c0 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0008600 =====

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



===== __memset_spec_plain @ 1c0008680 =====

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



===== SCBuildRequestPacket @ 1c0010008 =====

undefined4 * SCBuildRequestPacket(longlong param_1,longlong param_2,uint param_3,int param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  longlong lVar3;
  uint uVar4;
  
  uVar4 = *(int *)(*(longlong *)(param_1 + 0x210) + 0x2c) + 400;
  if ((((399 < uVar4) && (uVar1 = uVar4 + param_3, uVar4 <= uVar1)) &&
      (uVar4 = uVar1 + param_4, uVar1 <= uVar4)) &&
     (puVar2 = (undefined4 *)ExAllocatePoolWithTag(0x200,uVar4,0x736c4353),
     puVar2 != (undefined4 *)0x0)) {
    lVar3 = IoAllocateMdl(puVar2,uVar4,0,0,0);
    *(longlong *)(puVar2 + 0x24) = lVar3;
    if (lVar3 != 0) {
      MmBuildMdlForNonPagedPool(lVar3);
      *(undefined8 *)(puVar2 + 4) = 0;
      *(undefined8 *)(puVar2 + 0x16) = 0;
      *(undefined8 *)(puVar2 + 0x10) = 0;
      puVar2[0x20] = 0;
      *(undefined4 **)(puVar2 + 8) = puVar2 + 100;
      puVar2[0x4a] = uVar4;
      *puVar2 = 0x80;
      puVar2[2] = 0x103;
      *(longlong *)(puVar2 + 0x12) = param_2;
      dma64InitTransfer((longlong)puVar2);
      puVar2[0x14] = 0;
      puVar2[0xd] = 0xf;
      puVar2[0xe] = 0xf;
      *(ulonglong *)(puVar2 + 0x1a) =
           (ulonglong)*(uint *)(*(longlong *)(param_1 + 0x210) + 0x2c) + *(longlong *)(puVar2 + 8);
      *(ulonglong *)(puVar2 + 0x62) =
           (ulonglong)*(uint *)(*(longlong *)(param_1 + 0x210) + 0x2c) + *(longlong *)(puVar2 + 8) +
           (ulonglong)param_3;
      if (param_2 == 0) {
        puVar2[0x20] = puVar2[0x20] | 2;
      }
      else {
        *(undefined4 **)(param_2 + 0x78) = puVar2;
      }
      return puVar2;
    }
    ExFreePool(puVar2);
  }
  return (undefined4 *)0x0;
}



===== SCCallNextDriver @ 1c0010178 =====

ulonglong SCCallNextDriver(longlong param_1,longlong param_2)

{
  char *pcVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  uVar3 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  if (*(longlong *)(param_1 + 0x128) != 0) {
    pcVar1 = *(char **)(param_2 + 0xb8);
    *(undefined8 *)(pcVar1 + -0x48) = *(undefined8 *)pcVar1;
    *(undefined8 *)(pcVar1 + -0x40) = *(undefined8 *)(pcVar1 + 8);
    *(undefined8 *)(pcVar1 + -0x38) = *(undefined8 *)(pcVar1 + 0x10);
    *(undefined8 *)(pcVar1 + -0x30) = *(undefined8 *)(pcVar1 + 0x18);
    *(undefined8 *)(pcVar1 + -0x28) = *(undefined8 *)(pcVar1 + 0x20);
    *(undefined8 *)(pcVar1 + -0x20) = *(undefined8 *)(pcVar1 + 0x28);
    *(undefined4 *)(pcVar1 + -0x18) = *(undefined4 *)(pcVar1 + 0x30);
    *(undefined4 *)(pcVar1 + -0x14) = *(undefined4 *)(pcVar1 + 0x34);
    *(undefined4 *)(pcVar1 + -0x10) = *(undefined4 *)(pcVar1 + 0x38);
    *(undefined4 *)(pcVar1 + -0xc) = *(undefined4 *)(pcVar1 + 0x3c);
    *(undefined8 *)(pcVar1 + -8) = *(undefined8 *)(pcVar1 + 0x40);
    KeInitializeEvent(&local_28,1,0);
    lVar2 = *(longlong *)(param_2 + 0xb8);
    *(code **)(lVar2 + -0x10) = SCSynchCompletionRoutine;
    *(undefined8 **)(lVar2 + -8) = &local_28;
    *(undefined1 *)(lVar2 + -0x45) = 0xe0;
    if (*pcVar1 == '\x16') {
      uVar3 = PoCallDriver(*(undefined8 *)(param_1 + 0x128),param_2);
    }
    else {
      uVar3 = IofCallDriver();
    }
    if ((int)uVar3 == 0x103) {
      KeWaitForSingleObject(&local_28,0,0,0,0);
      uVar3 = (ulonglong)*(uint *)(param_2 + 0x30);
    }
  }
  return uVar3;
}



===== SCCheckPowerDown @ 1c0010278 =====

void SCCheckPowerDown(longlong param_1)

{
  int iVar1;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  uStack_10 = 0;
  if (((*(uint *)(param_1 + 0x130) & 4) != 0) && (*(int *)(param_1 + 0x2d8) == 0)) {
    KeSetEvent(param_1 + 0x2f0,0,0);
    KeInitializeEvent(&local_28,0,0);
    iVar1 = PoRequestPowerIrp(*(undefined8 *)(param_1 + 0x218),2,4,
                              SCBustedSynchPowerCompletionRoutine,&local_28,0);
    if (iVar1 == 0x103) {
      KeWaitForSingleObject(&local_28,5,0,0,0);
    }
    KeWaitForSingleObject(param_1 + 0x2f0,0,0,0,0);
  }
  return;
}



===== SCCopyMinidriverEvents @ 1c0010368 =====

void * SCCopyMinidriverEvents(uint param_1,void *param_2)

{
  ulonglong _Size;
  uint uVar1;
  void *_Dst;
  ulonglong uVar2;
  uint *puVar3;
  void *_Dst_00;
  uint uVar4;
  ulonglong uVar5;
  
  uVar5 = (ulonglong)param_1;
  _Size = (ulonglong)param_1 * 0x18;
  if (_Size < 0x100000000) {
    uVar4 = 0;
    uVar2 = _Size & 0xffffffff;
    uVar1 = (uint)_Size;
    if (param_1 != 0) {
      puVar3 = (uint *)((longlong)param_2 + 8);
      do {
        if (0xffffffff < (ulonglong)*puVar3 * 0x28) {
          return (void *)0x0;
        }
        uVar1 = (uint)uVar2 + (int)((ulonglong)*puVar3 * 0x28);
        if (uVar1 < (uint)uVar2) {
          return (void *)0x0;
        }
        puVar3 = puVar3 + 6;
        uVar4 = uVar4 + 1;
        uVar2 = (ulonglong)uVar1;
      } while (uVar4 < param_1);
    }
    _Dst = (void *)ExAllocatePoolWithTag(0x200,uVar1,0x736c4353);
    if (_Dst != (void *)0x0) {
      memmove(_Dst,param_2,_Size);
      _Dst_00 = (void *)(_Size + (longlong)_Dst);
      if (param_1 != 0) {
        puVar3 = (uint *)((longlong)_Dst + 8);
        do {
          memmove(_Dst_00,*(void **)(puVar3 + 2),(ulonglong)*puVar3 * 0x28);
          uVar1 = *puVar3;
          *(void **)(puVar3 + 2) = _Dst_00;
          puVar3 = puVar3 + 6;
          _Dst_00 = (void *)((longlong)_Dst_00 + (ulonglong)uVar1 * 0x28);
          uVar5 = uVar5 - 1;
        } while (uVar5 != 0);
      }
      return _Dst;
    }
  }
  return (void *)0x0;
}



===== SCCopyMinidriverMethods @ 1c001046c =====

void * SCCopyMinidriverMethods(uint param_1,void *param_2)

{
  ulonglong _Size;
  uint uVar1;
  void *_Dst;
  ulonglong uVar2;
  uint *puVar3;
  void *_Dst_00;
  uint uVar4;
  ulonglong uVar5;
  
  uVar5 = (ulonglong)param_1;
  _Size = (ulonglong)param_1 * 0x28;
  if (_Size < 0x100000000) {
    uVar4 = 0;
    uVar2 = _Size & 0xffffffff;
    uVar1 = (uint)_Size;
    if (param_1 != 0) {
      puVar3 = (uint *)((longlong)param_2 + 8);
      do {
        if (0xffffffff < (ulonglong)*puVar3 * 0x28) {
          return (void *)0x0;
        }
        uVar1 = (uint)uVar2 + (int)((ulonglong)*puVar3 * 0x28);
        if (uVar1 < (uint)uVar2) {
          return (void *)0x0;
        }
        puVar3 = puVar3 + 10;
        uVar4 = uVar4 + 1;
        uVar2 = (ulonglong)uVar1;
      } while (uVar4 < param_1);
    }
    _Dst = (void *)ExAllocatePoolWithTag(0x200,uVar1,0x736c4353);
    if (_Dst != (void *)0x0) {
      memmove(_Dst,param_2,_Size);
      _Dst_00 = (void *)(_Size + (longlong)_Dst);
      if (param_1 != 0) {
        puVar3 = (uint *)((longlong)_Dst + 8);
        do {
          memmove(_Dst_00,*(void **)(puVar3 + 2),(ulonglong)*puVar3 * 0x28);
          uVar1 = *puVar3;
          *(void **)(puVar3 + 2) = _Dst_00;
          puVar3 = puVar3 + 10;
          _Dst_00 = (void *)((longlong)_Dst_00 + (ulonglong)uVar1 * 0x28);
          uVar5 = uVar5 - 1;
        } while (uVar5 != 0);
      }
      return _Dst;
    }
  }
  return (void *)0x0;
}



===== SCCopyMinidriverProperties @ 1c0010570 =====

void * SCCopyMinidriverProperties(uint param_1,void *param_2)

{
  void *_Dst;
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  void *_Dst_00;
  ulonglong uVar5;
  
  uVar5 = (ulonglong)param_1;
  uVar4 = 0;
  uVar2 = param_1 * 0x28;
  if (param_1 != 0) {
    puVar1 = (uint *)((longlong)param_2 + 8);
    uVar3 = uVar2;
    do {
      if ((0xffffffff < (ulonglong)*puVar1 * 0x48) ||
         (uVar2 = uVar3 + (int)((ulonglong)*puVar1 * 0x48), uVar2 < uVar3)) goto LAB_1c00105ee;
      puVar1 = puVar1 + 10;
      uVar4 = uVar4 + 1;
      uVar3 = uVar2;
    } while (uVar4 < param_1);
  }
  _Dst = (void *)ExAllocatePoolWithTag(0x200,uVar2,0x736c4353);
  if (_Dst == (void *)0x0) {
LAB_1c00105ee:
    _Dst = (void *)0x0;
  }
  else {
    memmove(_Dst,param_2,uVar5 * 0x28);
    _Dst_00 = (void *)(uVar5 * 0x28 + (longlong)_Dst);
    if (param_1 != 0) {
      puVar1 = (uint *)((longlong)_Dst + 8);
      do {
        memmove(_Dst_00,*(void **)(puVar1 + 2),(ulonglong)*puVar1 * 0x48);
        uVar2 = *puVar1;
        *(void **)(puVar1 + 2) = _Dst_00;
        puVar1 = puVar1 + 10;
        _Dst_00 = (void *)((longlong)_Dst_00 + (ulonglong)uVar2 * 0x48);
        uVar5 = uVar5 - 1;
      } while (uVar5 != 0);
    }
  }
  return _Dst;
}



===== SCDereferenceDriver @ 1c001066c =====

void SCDereferenceDriver(longlong param_1)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  longlong lVar6;
  char local_res8 [8];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_res8[0] = '\0';
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  local_38 = 0;
  uStack_30 = 0;
  if ((*(uint *)(param_1 + 0x130) & 0x10) != 0) {
    SCReferenceSwEnumDriver(param_1,'\0');
  }
  lVar3 = IoGetDriverObjectExtension(*(undefined8 *)(*(longlong *)(param_1 + 0x120) + 8));
  if ((*(uint *)(lVar3 + 0x58) & 1) == 0) {
    KeWaitForSingleObject(lVar3 + 0x60,0,0,0,0);
    piVar1 = (int *)(lVar3 + 0x78);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      for (lVar6 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x120) + 8) + 8); lVar6 != 0;
          lVar6 = *(longlong *)(lVar6 + 0x10)) {
        lVar2 = *(longlong *)(lVar6 + 0x40);
        if (((byte)*(undefined4 *)(lVar2 + 0x118) & 3) == 1) {
          KeInitializeEvent(&local_28);
          puVar4 = (undefined8 *)IoAllocateIrp(*(undefined1 *)(lVar6 + 0x4c));
          if (puVar4 == (undefined8 *)0x0) goto LAB_1c0010809;
          *(undefined2 *)(puVar4[0x17] + -0x48) = 0x61b;
          puVar4[9] = &local_38;
          puVar4[10] = &local_28;
          LOCK();
          *(int *)(lVar2 + 0x348) = *(int *)(lVar2 + 0x348) + 1;
          UNLOCK();
          uVar5 = SCSubmitRequest(0x10b,0,0,SCProcessCompletedRequest,lVar2,0,0,puVar4,local_res8,
                                  (longlong *)(lVar2 + 0x260),
                                  *(undefined **)(*(longlong *)(lVar2 + 0x210) + 0x10));
          if (local_res8[0] == '\0') {
            SCCompleteIrp((longlong)puVar4,(int)uVar5,lVar2);
            goto LAB_1c0010809;
          }
          if ((int)uVar5 < 0) goto LAB_1c0010809;
        }
      }
      *(uint *)(lVar3 + 0x58) = *(uint *)(lVar3 + 0x58) | 2;
      MmPageEntireDriver(*(undefined8 *)(lVar3 + 0x10));
    }
LAB_1c0010809:
    KeSetEvent(lVar3 + 0x60,0,0);
  }
  return;
}



===== SCGetRegistryValue @ 1c0010850 =====

int SCGetRegistryValue(undefined8 param_1,undefined8 param_2,int param_3,void *param_4,uint param_5)

{
  int iVar1;
  longlong lVar2;
  uint uVar3;
  uint local_res18 [4];
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_28 = 0;
  uStack_20 = 0;
  iVar1 = -0x3fffff66;
  RtlInitUnicodeString(&local_28);
  uVar3 = param_3 + 0x18;
  if ((uVar3 < 0x18) || (local_res18[0] = uVar3 + param_5, local_res18[0] < uVar3)) {
    return -0x3fffff6b;
  }
  lVar2 = ExAllocatePoolWithTag(1,local_res18[0],0x736c4353);
  if (lVar2 != 0) {
    iVar1 = ZwQueryValueKey(param_1,&local_28,1,lVar2,local_res18[0],local_res18);
    if (-1 < iVar1) {
      if (param_5 < *(uint *)(lVar2 + 0xc)) {
        iVar1 = -0x3fffffdd;
      }
      else {
        memmove(param_4,(void *)((ulonglong)*(uint *)(lVar2 + 8) + lVar2),
                (ulonglong)*(uint *)(lVar2 + 0xc));
      }
    }
    ExFreePool(lVar2);
  }
  return iVar1;
}



===== SCLogError @ 1c0010954 =====

void SCLogError(undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)IoAllocateErrorLogEntry(param_1,0x30);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    puVar1[5] = 0;
    puVar1[3] = param_3;
    puVar1[6] = param_2;
    puVar1[4] = param_4;
    IoWriteErrorLogEntry(puVar1);
  }
  return;
}



===== SCMinidriverDevicePropertyHandler @ 1c00109b4 =====

ulonglong SCMinidriverDevicePropertyHandler
                    (int param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  char local_res10 [8];
  
  lVar3 = param_2[0x17];
  local_res10[0] = '\0';
  lVar4 = *(longlong *)(*(longlong *)(lVar3 + 0x28) + 0x40);
  lVar5 = *(longlong *)(*(longlong *)(lVar3 + 0x30) + 0x18);
  puVar6 = (undefined8 *)ExAllocatePoolWithTag(0x200,0x20);
  if (puVar6 == (undefined8 *)0x0) {
    uVar7 = 0xc000009a;
  }
  else {
    iVar1 = *(int *)(param_2 + 0xf);
    iVar2 = *(int *)(lVar5 + 0x98);
    *puVar6 = param_3;
    puVar6[2] = param_4;
    *(uint *)(puVar6 + 1) = (uint)(iVar1 - iVar2) / 0x28;
    *(undefined4 *)(puVar6 + 3) = *(undefined4 *)(lVar3 + 0x10);
    *(undefined4 *)((longlong)puVar6 + 0x1c) = *(undefined4 *)(lVar3 + 8);
    uVar7 = SCSubmitRequest(param_1,(longlong)puVar6,0,SCProcessCompletedPropertyRequest,lVar4,
                            *(longlong *)(lVar5 + 0x30),0,param_2,local_res10,
                            (longlong *)(lVar4 + 0x260),
                            *(undefined **)(*(longlong *)(lVar4 + 0x210) + 0x10));
    uVar7 = uVar7 & 0xffffffff;
    if (local_res10[0] == '\0') {
      ExFreePool(puVar6);
    }
  }
  return uVar7;
}



===== SCMinidriverStreamPropertyHandler @ 1c0010af0 =====

ulonglong SCMinidriverStreamPropertyHandler
                    (int param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  char local_res10 [8];
  
  lVar3 = param_2[0x17];
  local_res10[0] = '\0';
  lVar4 = *(longlong *)(*(longlong *)(lVar3 + 0x28) + 0x40);
  lVar5 = *(longlong *)(*(longlong *)(lVar3 + 0x30) + 0x18);
  puVar6 = (undefined8 *)ExAllocatePoolWithTag(0x200,0x20,0x736c4353);
  if (puVar6 == (undefined8 *)0x0) {
    uVar7 = 0xc000009a;
  }
  else {
    iVar1 = *(int *)(param_2 + 0xf);
    iVar2 = *(int *)(lVar5 + 0x1f8);
    *puVar6 = param_3;
    puVar6[2] = param_4;
    *(uint *)(puVar6 + 1) = (uint)(iVar1 - iVar2) / 0x28;
    *(undefined4 *)(puVar6 + 3) = *(undefined4 *)(lVar3 + 0x10);
    *(undefined4 *)((longlong)puVar6 + 0x1c) = *(undefined4 *)(lVar3 + 8);
    uVar7 = SCSubmitRequest(param_1,(longlong)puVar6,0,SCProcessCompletedPropertyRequest,lVar4,
                            *(longlong *)(*(longlong *)(lVar5 + 0x128) + 0x30),lVar5 + 0x130,param_2
                            ,local_res10,(longlong *)(lVar5 + 0x1a8),*(undefined **)(lVar5 + 0x148))
    ;
    uVar7 = uVar7 & 0xffffffff;
    if (local_res10[0] == '\0') {
      ExFreePool(puVar6);
    }
  }
  return uVar7;
}



===== SCOpenMinidriverInstance @ 1c0010c34 =====

ulonglong SCOpenMinidriverInstance
                    (longlong param_1,longlong *param_2,ulonglong param_3,undefined8 *param_4)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  undefined8 *_Dst;
  ulonglong uVar8;
  undefined4 *puVar9;
  ulonglong uVar10;
  undefined4 *puVar11;
  ulonglong local_res18;
  ulonglong local_res20;
  
  uVar3 = *(uint *)(param_1 + 0x43c);
  uVar8 = (ulonglong)uVar3;
  local_res18 = param_3 & 0xffffffffffffff00;
  uVar4 = *(uint *)(param_4[0xf] + 8);
  uVar7 = **(uint **)((ulonglong)uVar4 * 0x20 + 0x10 + *(longlong *)(param_1 + 0x430));
  uVar10 = (ulonglong)uVar7;
  if ((*(int *)(param_1 + 0x2d8) != 0) && (uVar3 == 0)) {
    *param_2 = *(longlong *)(param_1 + 0x2c8) + -0x10;
    return 0;
  }
  _Dst = (undefined8 *)ExAllocatePoolWithTag(0x200,uVar8 + 0xd0 + uVar10 * 0xc,0x736c4353);
  if (_Dst != (undefined8 *)0x0) {
    memset(_Dst,0,uVar8 + 0xd0 + uVar10 * 0xc);
    *(undefined4 *)(_Dst + 0xb) = 0x46727453;
    _Dst[6] = _Dst + 0x1a;
    puVar1 = _Dst + 8;
    _Dst[0x17] = param_1;
    _Dst[7] = uVar8 + 0xd0 + (longlong)_Dst;
    *(uint *)(_Dst + 0x19) = uVar4;
    puVar2 = _Dst + 4;
    _Dst[5] = puVar2;
    *puVar2 = puVar2;
    puVar2 = _Dst + 2;
    _Dst[3] = puVar2;
    *puVar2 = puVar2;
    puVar2 = _Dst + 0x10;
    _Dst[0x11] = puVar2;
    *puVar2 = puVar2;
    iVar6 = KsRegisterWorker(0,puVar1);
    if (-1 < iVar6) {
      puVar2 = _Dst + 9;
      iVar6 = KsRegisterWorker(0,puVar2);
      if (-1 < iVar6) {
        puVar9 = (undefined4 *)(*(longlong *)(param_1 + 0x2e8) + 0x48);
        puVar11 = (undefined4 *)_Dst[7];
        if (uVar7 != 0) {
          do {
            *puVar11 = 0;
            uVar5 = *puVar9;
            puVar9 = puVar9 + 0x22;
            puVar11[1] = uVar5;
            uVar10 = uVar10 - 1;
            puVar11 = puVar11 + 3;
          } while (uVar10 != 0);
        }
        uVar7 = KsAllocateObjectHeader
                          (_Dst,1,&PTR_StreamDispatchCreate_1c0017180,param_4,&FilterDispatchTable);
        uVar10 = (ulonglong)uVar7;
        if ((int)uVar7 < 0) {
          KsUnregisterWorker(*puVar1);
          KsUnregisterWorker(*puVar2);
LAB_1c0010eea:
          ExFreePool(_Dst);
          _Dst = (undefined8 *)0x0;
        }
        else {
          if (uVar3 != 0) {
            local_res20 = (ulonglong)uVar4;
            uVar8 = SCSubmitRequest(0x103,local_res20,0,SCDequeueAndDeleteSrb,param_1,_Dst[6],0,
                                    param_4,(undefined1 *)&local_res18,(longlong *)(param_1 + 0x260)
                                    ,*(undefined **)(*(longlong *)(param_1 + 0x210) + 0x10));
            uVar10 = uVar8 & 0xffffffff;
            if ((char)local_res18 == '\0') {
              KsFreeObjectHeader(*_Dst);
              KsUnregisterWorker(*puVar1);
              KsUnregisterWorker(*puVar2);
            }
            if ((int)uVar8 < 0) goto LAB_1c0010eea;
          }
          SCInsertFiltersInDevice((longlong)_Dst,param_1);
        }
        goto LAB_1c0010f08;
      }
      KsUnregisterWorker(*puVar1);
    }
    ExFreePool(_Dst);
    _Dst = (undefined8 *)0x0;
  }
  uVar10 = 0xc000009a;
LAB_1c0010f08:
  *param_2 = (longlong)_Dst;
  return uVar10;
}



===== SCProcessCompletedPropertyRequest @ 1c0010f30 =====

void SCProcessCompletedPropertyRequest(longlong param_1)

{
  ExFreePool(*(undefined8 *)(param_1 + 0x28));
  *(ulonglong *)(*(longlong *)(param_1 + 0x48) + 0x38) = (ulonglong)*(uint *)(param_1 + 0x60);
  SCDequeueAndDeleteSrb(param_1);
  return;
}



===== SCProcessDataTransfer @ 1c0010f6c =====

undefined8 SCProcessDataTransfer(longlong param_1,undefined8 *param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  ulonglong uVar4;
  uint uVar5;
  int iVar6;
  longlong lVar7;
  longlong *plVar8;
  undefined1 uVar9;
  undefined8 uVar10;
  longlong lVar11;
  undefined8 *puVar12;
  undefined8 *puVar13;
  ulonglong uVar14;
  uint uVar15;
  uint uVar16;
  undefined8 *puVar17;
  undefined1 local_res20;
  ulonglong in_stack_ffffffffffffff88;
  uint local_68;
  int local_64;
  longlong local_60;
  ulonglong local_58;
  ulonglong local_50;
  
  lVar11 = param_2[0x17];
  uVar16 = 0;
  uVar5 = 0;
  local_68 = 0;
  uVar15 = 0;
  local_64 = 0;
  uVar10 = 0xb1;
  uVar4 = *(ulonglong *)(*(longlong *)(lVar11 + 0x30) + 0x18);
  local_60 = 0;
  if (*(char *)(uVar4 + 0x25b) != '\0') {
    return 0xc00000a3;
  }
  param_2[7] = 0;
  if (*(uint *)(lVar11 + 8) != 0) {
    local_64 = *(int *)(uVar4 + 0x17c);
    uVar15 = *(int *)(uVar4 + 0x178) + 0x38;
    if (param_3 == 0) {
      uVar10 = 0x30;
      param_2[7] = (ulonglong)*(uint *)(lVar11 + 8);
    }
    uVar10 = KsProbeStreamIrp(param_2,uVar10,uVar15);
    if ((int)uVar10 < 0) {
      return uVar10;
    }
    if (local_64 == 0) {
      local_60 = param_2[3];
      *(undefined8 *)(lVar11 + 0x20) = 0;
    }
    else {
      uVar10 = KsAllocateExtraData(param_2,local_64,&local_60);
      if ((int)uVar10 < 0) {
        return uVar10;
      }
      *(longlong *)(lVar11 + 0x20) = local_60;
    }
    uVar14 = (ulonglong)*(uint *)(lVar11 + 8) / (ulonglong)uVar15;
    uVar5 = (uint)uVar14;
    if ((*(char *)(uVar4 + 0x168) != '\0') && (puVar13 = (undefined8 *)param_2[1], uVar5 != 0)) {
      lVar11 = local_60;
      do {
        if (param_3 == 1) {
          uVar3 = *(uint *)(lVar11 + 0x24);
        }
        else {
          uVar3 = *(uint *)(lVar11 + 0x20);
        }
        if (uVar3 != 0) {
          piVar1 = (int *)((longlong)puVar13 + 0x2c);
          piVar2 = (int *)(puVar13 + 4);
          puVar13 = (undefined8 *)*puVar13;
          uVar16 = uVar16 + (int)((ulonglong)(*piVar1 + *piVar2 & 0xfff) + 0xfff + (ulonglong)uVar3
                                 >> 0xc);
        }
        lVar11 = lVar11 + (ulonglong)(local_64 + uVar15);
        uVar14 = uVar14 - 1;
      } while (uVar14 != 0);
      local_68 = uVar16;
    }
    if (*(int *)(param_1 + 0x150) - 1U < local_68) {
      return 0xc000009a;
    }
  }
  puVar13 = (undefined8 *)param_2[1];
  uVar16 = 0;
  lVar11 = local_60;
  if (uVar5 != 0) {
    do {
      if (param_3 == 1) {
        iVar6 = *(int *)(lVar11 + 0x24);
      }
      else {
        iVar6 = *(int *)(lVar11 + 0x20);
      }
      if (iVar6 != 0) {
        if ((*(byte *)((longlong)puVar13 + 10) & 5) == 0) {
          in_stack_ffffffffffffff88 = in_stack_ffffffffffffff88 & 0xffffffff00000000;
          lVar7 = MmMapLockedPagesSpecifyCache(puVar13,0,1,0,in_stack_ffffffffffffff88,0x40000020);
        }
        else {
          lVar7 = puVar13[3];
        }
        if (lVar7 == 0) break;
        puVar13 = (undefined8 *)*puVar13;
      }
      uVar16 = uVar16 + 1;
      lVar11 = lVar11 + (ulonglong)(local_64 + uVar15);
    } while (uVar16 < uVar5);
  }
  if ((uVar16 != uVar5) ||
     (plVar8 = (longlong *)SCBuildRequestPacket(param_1,(longlong)param_2,local_68 << 4,uVar5 * 8),
     plVar8 == (longlong *)0x0)) {
    return 0xc000009a;
  }
  if (*(char *)(uVar4 + 0x169) != '\0') {
    puVar13 = (undefined8 *)plVar8[0x31];
    puVar17 = (undefined8 *)param_2[1];
    local_res20 = 0;
    uVar9 = 0;
    if (uVar5 != 0) {
      uVar14 = (ulonglong)(local_64 + uVar15);
      puVar12 = (undefined8 *)(local_60 + 0x28);
      local_58 = (ulonglong)uVar5;
      local_50 = uVar14;
      do {
        if (param_3 == 1) {
          iVar6 = *(int *)((longlong)puVar12 + -4);
        }
        else {
          iVar6 = *(int *)(puVar12 + -1);
        }
        if (iVar6 != 0) {
          *puVar13 = *puVar12;
          local_res20 = 1;
          if ((*(byte *)((longlong)puVar17 + 10) & 5) == 0) {
            in_stack_ffffffffffffff88 = in_stack_ffffffffffffff88 & 0xffffffff00000000;
            uVar10 = MmMapLockedPagesSpecifyCache
                               (puVar17,0,1,0,in_stack_ffffffffffffff88,0x40000020);
            uVar14 = local_50;
          }
          else {
            uVar10 = puVar17[3];
          }
          *puVar12 = uVar10;
          puVar17 = (undefined8 *)*puVar17;
        }
        puVar12 = (undefined8 *)((longlong)puVar12 + uVar14);
        puVar13 = puVar13 + 1;
        local_58 = local_58 - 1;
      } while (local_58 != 0);
      local_58 = 0;
      uVar9 = local_res20;
    }
    *(undefined1 *)(plVar8 + 0x30) = uVar9;
  }
  *(int *)((longlong)plVar8 + 4) = param_3;
  *(uint *)(plVar8 + 0xe) = local_68;
  *(uint *)(plVar8 + 6) = uVar5;
  plVar8[5] = local_60;
  lVar11 = *(longlong *)(param_1 + 0x220);
  *(undefined4 *)((longlong)plVar8 + 0x164) = 0;
  *(uint *)(plVar8 + 10) = *(uint *)(plVar8 + 10) | 3;
  plVar8[3] = lVar11;
  plVar8[0x26] = (longlong)SCProcessCompletedDataRequest;
  plVar8[2] = uVar4 + 0x130;
  *(uint *)(plVar8 + 0x2c) = local_64 + uVar15;
  plVar8[0xb] = *(longlong *)(*(longlong *)(uVar4 + 0x128) + 0x30);
  param_2[0xf] = plVar8;
  *(byte *)(param_2[0x17] + 3) = *(byte *)(param_2[0x17] + 3) | 1;
  uVar10 = SCIssueRequestToDevice
                     (param_1,uVar4,plVar8,*(undefined **)(uVar4 + 0x140),
                      (longlong *)(uVar4 + 0x198),param_2);
  return uVar10;
}



===== SCQueryCapabilities @ 1c0011330 =====

undefined4 SCQueryCapabilities(longlong param_1,undefined4 *param_2)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  undefined4 uVar4;
  longlong lVar5;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  lVar5 = IoAllocateIrp(*(undefined1 *)(param_1 + 0x4c));
  if (lVar5 == 0) {
    uVar4 = 0xc000009a;
  }
  else {
    lVar1 = *(longlong *)(lVar5 + 0xb8);
    *(undefined2 *)(lVar1 + -0x48) = 0x91b;
    memset(param_2,0,0x40);
    *param_2 = 0x10040;
    param_2[2] = 0xffffffff;
    param_2[3] = 0xffffffff;
    KeInitializeEvent(&local_28,0,0);
    lVar2 = *(longlong *)(lVar5 + 0xb8);
    *(code **)(lVar2 + -0x10) = SCSynchCompletionRoutine;
    *(undefined8 **)(lVar2 + -8) = &local_28;
    *(undefined1 *)(lVar2 + -0x45) = 0xe0;
    *(undefined4 **)(lVar1 + -0x40) = param_2;
    *(undefined4 *)(lVar5 + 0x30) = 0xc00000bb;
    iVar3 = IofCallDriver(param_1,lVar5);
    if (iVar3 == 0x103) {
      KeWaitForSingleObject(&local_28,5,0,0,0);
    }
    uVar4 = *(undefined4 *)(lVar5 + 0x30);
    IoFreeIrp(lVar5);
  }
  return uVar4;
}



===== SCReadRegistryValues @ 1c001145c =====

void SCReadRegistryValues(longlong param_1,undefined8 param_2)

{
  int iVar1;
  undefined **ppuVar2;
  longlong lVar3;
  int local_res18 [2];
  undefined8 local_res20;
  
  local_res20 = 0;
  iVar1 = IoOpenDeviceRegistryKey(param_2,2,0x1f0000,&local_res20);
  if (-1 < iVar1) {
    ppuVar2 = &PTR_u_PageOutWhenUnopened_1c0017040;
    lVar3 = 6;
    do {
      local_res18[0] = 0;
      iVar1 = SCGetRegistryValue(local_res20,*ppuVar2,*(int *)(ppuVar2 + 1),local_res18,1);
      if ((-1 < iVar1) && (local_res18[0] != 0)) {
        *(uint *)(param_1 + 0x130) = *(uint *)(param_1 + 0x130) | *(uint *)((longlong)ppuVar2 + 0xc)
        ;
      }
      ppuVar2 = ppuVar2 + 2;
      lVar3 = lVar3 + -1;
    } while (lVar3 != 0);
    ZwClose(local_res20);
  }
  return;
}



===== SCReferenceDriver @ 1c0011510 =====

void SCReferenceDriver(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(param_1 + 0x328);
  if ((*(uint *)(param_1 + 0x130) & 0x10) != 0) {
    SCReferenceSwEnumDriver(param_1,'\x01');
  }
  if ((*(uint *)(lVar2 + 0x58) & 1) == 0) {
    KeWaitForSingleObject(lVar2 + 0x60,0,0,0,0);
    iVar1 = *(int *)(lVar2 + 0x78);
    *(int *)(lVar2 + 0x78) = iVar1 + 1;
    if (iVar1 == 0) {
      MmResetDriverPaging(*(undefined8 *)(lVar2 + 0x10));
      *(uint *)(lVar2 + 0x58) = *(uint *)(lVar2 + 0x58) & 0xfffffffd;
    }
    KeSetEvent(lVar2 + 0x60,0,0);
  }
  return;
}



===== SCSendUnknownCommand @ 1c00115a0 =====

void SCSendUnknownCommand
               (undefined8 *param_1,longlong param_2,undefined *param_3,undefined1 *param_4)

{
  SCSubmitRequest(0x10a,0,0,param_3,param_2,0,0,param_1,param_4,(longlong *)(param_2 + 0x260),
                  *(undefined **)(*(longlong *)(param_2 + 0x210) + 0x10));
  return;
}



===== SCShowIoPending @ 1c00115f8 =====

undefined8 SCShowIoPending(longlong param_1,longlong param_2)

{
  undefined8 uVar1;
  
  LOCK();
  *(int *)(param_1 + 0x348) = *(int *)(param_1 + 0x348) + 1;
  UNLOCK();
  if ((*(uint *)(param_1 + 0x118) & 0x100) == 0) {
    uVar1 = 0;
  }
  else {
    LOCK();
    *(int *)(param_1 + 0x348) = *(int *)(param_1 + 0x348) + -1;
    UNLOCK();
    *(undefined4 *)(param_2 + 0x30) = 0xc0000010;
    IofCompleteRequest(param_2,0);
    uVar1 = 0xc0000010;
  }
  return uVar1;
}



===== SCSubmitRequest @ 1c0011648 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
SCSubmitRequest(int param_1,longlong param_2,undefined4 param_3,undefined *param_4,longlong param_5,
               longlong param_6,longlong param_7,undefined8 *param_8,undefined1 *param_9,
               longlong *param_10,undefined *param_11)

{
  longlong lVar1;
  longlong *plVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  
  uVar4 = 0;
  plVar2 = (longlong *)SCBuildRequestPacket(param_5,(longlong)param_8,0,0);
  *param_9 = 1;
  if (plVar2 == (longlong *)0x0) {
    if ((param_1 - 0x102U & 0xfffffffd) == 0) {
      plVar2 = (longlong *)SCAcquireReserveSrb(param_5,(longlong)param_8);
      if (plVar2 != (longlong *)0x0) goto LAB_1c00116cf;
    }
    *param_9 = 0;
    uVar3 = 0xc000009a;
  }
  else {
LAB_1c00116cf:
    if ((param_7 != 0) && (uVar4 = param_7 - 0x130, 1 < param_1 - 0x101U)) {
      *(uint *)(plVar2 + 10) = *(uint *)(plVar2 + 10) | 2;
    }
    KeInitializeEvent(plVar2 + 0x29,1);
    plVar2[0x26] = (longlong)SCSignalSRBEvent;
    plVar2[0xb] = param_6;
    plVar2[5] = param_2;
    *(int *)((longlong)plVar2 + 4) = param_1;
    plVar2[2] = param_7;
    lVar1 = *(longlong *)(param_5 + 0x220);
    *(undefined4 *)((longlong)plVar2 + 0x164) = 0;
    plVar2[3] = lVar1;
    *(undefined4 *)(plVar2 + 0xc) = param_3;
    uVar3 = SCIssueRequestToDevice(param_5,uVar4,plVar2,param_11,param_10,param_8);
    if ((int)uVar3 == 0x103) {
      KeWaitForSingleObject(plVar2 + 0x29,0,0,0,0);
    }
    uVar3 = (*(code *)param_4)(plVar2);
  }
  return uVar3;
}



===== SCUpdateMinidriverEvents @ 1c00117c8 =====

void SCUpdateMinidriverEvents(uint param_1,longlong param_2,char param_3)

{
  uint *puVar1;
  undefined8 *puVar2;
  uint uVar3;
  code *pcVar4;
  ulonglong uVar5;
  code *pcVar6;
  
  if (param_1 != 0) {
    puVar1 = (uint *)(param_2 + 8);
    uVar5 = (ulonglong)param_1;
    do {
      uVar3 = 0;
      if (*puVar1 != 0) {
        pcVar4 = StreamClassEnableEventHandler;
        if (param_3 == '\0') {
          pcVar4 = StreamClassEnableDeviceEventHandler;
        }
        pcVar6 = StreamClassDisableEventHandler;
        if (param_3 == '\0') {
          pcVar6 = StreamClassDisableDeviceEventHandler;
        }
        puVar2 = (undefined8 *)(*(longlong *)(puVar1 + 2) + 0x18);
        do {
          puVar2[-1] = pcVar4;
          uVar3 = uVar3 + 1;
          *puVar2 = pcVar6;
          puVar2 = puVar2 + 5;
        } while (uVar3 < *puVar1);
      }
      puVar1 = puVar1 + 6;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  return;
}



===== SCUpdateMinidriverProperties @ 1c0011838 =====

void SCUpdateMinidriverProperties(uint param_1,longlong param_2,char param_3)

{
  code *pcVar1;
  longlong *plVar2;
  uint *puVar3;
  uint uVar4;
  ulonglong uVar5;
  
  if (param_1 != 0) {
    puVar3 = (uint *)(param_2 + 8);
    uVar5 = (ulonglong)param_1;
    do {
      uVar4 = 0;
      if (*puVar3 != 0) {
        plVar2 = (longlong *)(*(longlong *)(puVar3 + 2) + 8);
        do {
          if (plVar2[6] != 0) {
            pcVar1 = StreamClassMinidriverDeviceGetProperty;
            if (param_3 != '\0') {
              pcVar1 = StreamClassMinidriverStreamGetProperty;
            }
            plVar2[6] = (longlong)pcVar1;
          }
          if (*plVar2 != 0) {
            pcVar1 = StreamClassMinidriverDeviceGetProperty;
            if (param_3 != '\0') {
              pcVar1 = StreamClassMinidriverStreamGetProperty;
            }
            *plVar2 = (longlong)pcVar1;
          }
          if (plVar2[2] != 0) {
            pcVar1 = StreamClassMinidriverDeviceSetProperty;
            if (param_3 != '\0') {
              pcVar1 = StreamClassMinidriverStreamSetProperty;
            }
            plVar2[2] = (longlong)pcVar1;
          }
          plVar2 = plVar2 + 9;
          uVar4 = uVar4 + 1;
        } while (uVar4 < *puVar3);
      }
      puVar3 = puVar3 + 10;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  return;
}



===== SCCreateChildPdo @ 1c00118dc =====

ulonglong SCCreateChildPdo(longlong param_1,longlong param_2,undefined4 param_3)

{
  short sVar1;
  longlong lVar2;
  longlong lVar3;
  code *pcVar4;
  uint uVar5;
  ulonglong uVar6;
  longlong lVar7;
  short *psVar8;
  short *psVar9;
  longlong *plVar10;
  short *psVar11;
  longlong *plVar12;
  ulonglong uVar13;
  undefined1 *puVar14;
  longlong local_res10;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [24];
  undefined4 local_48;
  undefined1 local_40;
  longlong *local_38;
  
  lVar2 = *(longlong *)(param_2 + 0x40);
  local_38 = &local_res10;
  local_40 = 0;
  local_res10 = 0;
  local_48 = 0x180;
  uVar6 = IoCreateDevice(*(undefined8 *)(param_2 + 8),0x150,0,0x22);
  if (-1 < (int)uVar6) {
    *(char *)(local_res10 + 0x4c) = *(char *)(param_2 + 0x4c) + '\x01';
    lVar3 = *(longlong *)(local_res10 + 0x40);
    *(uint *)(lVar3 + 0x118) = *(uint *)(lVar3 + 0x118) | 2;
    *(longlong *)(lVar3 + 0x120) = local_res10;
    lVar7 = -1;
    *(undefined4 *)(lVar3 + 0x148) = param_3;
    *(longlong *)(lVar3 + 0x128) = param_2;
    do {
      lVar7 = lVar7 + 1;
    } while (*(short *)(param_1 + lVar7 * 2) != 0);
    uVar5 = (int)lVar7 * 2 + 2;
    psVar8 = (short *)ExAllocatePoolWithTag(1,uVar5,0x736c4353);
    puVar14 = auStack_68;
    if (psVar8 != (short *)0x0) {
      uVar13 = (ulonglong)(uVar5 >> 1);
      if (uVar13 != 0) {
        lVar7 = 0x7ffffffe - uVar13;
        psVar11 = psVar8;
        do {
          if ((lVar7 + uVar13 == 0) ||
             (sVar1 = *(short *)((param_1 - (longlong)psVar8) + (longlong)psVar11), sVar1 == 0))
          break;
          *psVar11 = sVar1;
          psVar11 = psVar11 + 1;
          uVar13 = uVar13 - 1;
        } while (uVar13 != 0);
        psVar9 = psVar11 + -1;
        if (uVar13 != 0) {
          psVar9 = psVar11;
        }
        *psVar9 = 0;
      }
      *(short **)(lVar3 + 0x140) = psVar8;
    }
    plVar10 = (longlong *)(lVar3 + 0x130);
    lVar7 = lVar2 + 0x378;
    *(longlong **)(lVar3 + 0x138) = plVar10;
    *plVar10 = (longlong)plVar10;
    plVar12 = *(longlong **)(lVar2 + 0x380);
    if (*plVar12 != lVar7) {
      lVar7 = 3;
      pcVar4 = (code *)swi(0x29);
      plVar10 = (longlong *)(*pcVar4)();
      puVar14 = auStack_60;
    }
    *plVar10 = lVar7;
    plVar10[1] = (longlong)plVar12;
    *plVar12 = (longlong)plVar10;
    *(longlong **)(lVar7 + 8) = plVar10;
    *(uint *)(*(longlong *)(puVar14 + 0x78) + 0x30) =
         *(uint *)(*(longlong *)(puVar14 + 0x78) + 0x30) | 0x2000;
    *(uint *)(*(longlong *)(puVar14 + 0x78) + 0x30) =
         *(uint *)(*(longlong *)(puVar14 + 0x78) + 0x30) & 0xffffff7f;
    uVar6 = uVar6 & 0xffffffff;
  }
  return uVar6;
}



===== SCEnumerateChildren @ 1c0011a60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SCEnumerateChildren(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  int iVar3;
  void *pvVar4;
  longlong lVar5;
  ulonglong uVar6;
  uint *_Dst;
  uint uVar7;
  uint *puVar8;
  uint *puVar9;
  uint uVar10;
  undefined1 auStackY_f8 [32];
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  longlong lStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 *local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  ulonglong uStack_70;
  longlong local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_f8;
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_b0 = 0;
  local_78 = 0;
  local_98 = 0;
  uStack_90 = 0;
  uStack_70 = uStack_70 & 0xffffffff00000000;
  local_88 = (undefined8 *)0x0;
  uStack_80 = 0;
  local_c0 = 0;
  local_b8 = 0;
  local_a8 = 0;
  lStack_a0 = 0;
  local_68 = param_2;
  if ((*(uint *)(lVar1 + 0x118) & 0x1000) != 0) {
    uVar7 = 0;
    for (puVar2 = *(undefined8 **)(lVar1 + 0x378); puVar2 != (undefined8 *)(lVar1 + 0x378);
        puVar2 = (undefined8 *)*puVar2) {
      uVar10 = uVar7 + 1;
      if ((*(uint *)(puVar2 + -3) & 0x800) != 0) {
        uVar10 = uVar7;
      }
      uVar7 = uVar10;
    }
LAB_1c0011db5:
    uVar10 = uVar7 * 8 + 0x10;
    _Dst = (uint *)ExAllocatePoolWithTag(1,uVar10,0x736c4353);
    if (_Dst == (uint *)0x0) {
      return -0x3fffff66;
    }
    memset(_Dst,0,(ulonglong)uVar10);
    puVar2 = *(undefined8 **)(lVar1 + 0x378);
    puVar8 = _Dst + 2;
    uVar10 = 0;
    puVar9 = puVar8;
    do {
      if (puVar2 == (undefined8 *)(lVar1 + 0x378)) {
        *_Dst = uVar7;
        *(uint **)(local_68 + 0x38) = _Dst;
        return 0;
      }
      if ((*(uint *)(puVar2 + -3) & 0x800) == 0) {
        if (uVar10 == uVar7) {
          if (uVar10 != 0) {
            uVar6 = (ulonglong)uVar10;
            do {
              ObfDereferenceObject(*(undefined8 *)puVar8);
              puVar8 = puVar8 + 2;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          ExFreePool(_Dst);
          return -0x3fffffff;
        }
        *(undefined8 *)puVar9 = puVar2[-2];
        ObfReferenceObject();
        puVar9 = puVar9 + 2;
        uVar10 = uVar10 + 1;
      }
      puVar2 = (undefined8 *)*puVar2;
    } while( true );
  }
  iVar3 = IoOpenDeviceRegistryKey(*(undefined8 *)(lVar1 + 0x218),2,0x1f0000,&local_b0);
  if (iVar3 < 0) {
LAB_1c0011d7f:
    iVar3 = -0x3ffffffe;
  }
  else {
    RtlInitUnicodeString(&local_a8,L"Enum");
    uStack_90 = local_b0;
    local_88 = &local_a8;
    local_98 = CONCAT44(local_98._4_4_,0x30);
    uStack_80 = CONCAT44(uStack_80._4_4_,0x240);
    local_78 = 0;
    uStack_70 = 0;
    iVar3 = ZwOpenKey(&local_c0,0x20019,&local_98);
    if (-1 < iVar3) {
      pvVar4 = (void *)ExAllocatePoolWithTag(1,0x100,0x736c4353);
      if (pvVar4 != (void *)0x0) {
        uVar7 = 0;
        while( true ) {
          local_50 = 0;
          local_60 = 0;
          uStack_58 = 0;
          iVar3 = ZwEnumerateKey(local_c0,uVar7,0,&local_60);
          if ((((iVar3 + 0x80000000U & 0x80000000) == 0) && (iVar3 != -0x7ffffffb)) ||
             (lVar5 = ExAllocatePoolWithTag(1,0,0x736c4353), lVar5 == 0)) goto LAB_1c0011d3b;
          iVar3 = ZwEnumerateKey(local_c0,uVar7,0,lVar5);
          if (iVar3 < 0) break;
          local_a8._0_4_ = CONCAT22(*(undefined2 *)(lVar5 + 0xc),*(undefined2 *)(lVar5 + 0xc));
          lStack_a0 = lVar5 + 0x10;
          local_98 = CONCAT44(local_98._4_4_,0x30);
          uStack_90 = local_c0;
          local_88 = &local_a8;
          uStack_80 = CONCAT44(uStack_80._4_4_,0x240);
          local_78 = 0;
          uStack_70 = 0;
          iVar3 = ZwOpenKey(&local_b8,0x20019,&local_98);
          if (iVar3 < 0) break;
          iVar3 = SCGetRegistryValue(local_b8,L"PnpId",0xc,pvVar4,0x100);
          if (iVar3 < 0) {
            ExFreePool(lVar5);
            ZwClose(local_b8);
            goto LAB_1c0011d3b;
          }
          uVar6 = SCCreateChildPdo((longlong)pvVar4,param_1,uVar7);
          ExFreePool(lVar5);
          ZwClose(local_b8);
          if ((int)uVar6 < 0) goto LAB_1c0011d3b;
          uVar7 = uVar7 + 1;
        }
        ExFreePool(lVar5);
LAB_1c0011d3b:
        ZwClose(local_c0);
        ZwClose(local_b0);
        ExFreePool(pvVar4);
        *(uint *)(lVar1 + 0x118) = *(uint *)(lVar1 + 0x118) | 0x1000;
        if (uVar7 != 0) goto LAB_1c0011db5;
        goto LAB_1c0011d7f;
      }
      ZwClose(local_c0);
      iVar3 = -0x3fffff66;
    }
    ZwClose(local_b0);
  }
  return iVar3;
}



===== SCFreeAllResources @ 1c0011eb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SCFreeAllResources(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 uVar4;
  code *pcVar5;
  undefined1 *puVar6;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  ulonglong local_18;
  
  local_18 = 0;
  KeWaitForSingleObject(param_1 + 0x2f0,0,0,0);
  if ((*(longlong *)(param_1 + 0x138) != param_1) && (*(longlong *)(param_1 + 0x138) != 0)) {
    IoDisconnectInterrupt();
    *(longlong *)(param_1 + 0x138) = param_1;
    *(code **)(param_1 + 0x238) = StreamClassSynchronizeExecution;
  }
  lVar2 = *(longlong *)(param_1 + 0x228);
  if (lVar2 != 0) {
    if (*(longlong *)(lVar2 + 0x40) != 0) {
      ExFreePool();
    }
    ExFreePool(lVar2);
    *(undefined8 *)(param_1 + 0x228) = 0;
  }
  lVar2 = *(longlong *)(param_1 + 0x148);
  if (lVar2 != 0) {
    if (*(longlong *)(param_1 + 0x250) != 0) {
      local_18 = local_18 & 0xffffffffffffff00;
      (**(code **)(*(longlong *)(lVar2 + 8) + 0x18))
                (lVar2,*(undefined4 *)(*(longlong *)(param_1 + 0x328) + 0x44),
                 *(longlong *)(param_1 + 0x250),*(undefined8 *)(param_1 + 600));
    }
    (**(code **)(*(longlong *)(lVar2 + 8) + 8))(lVar2);
    *(undefined8 *)(param_1 + 0x148) = 0;
  }
  while( true ) {
    puVar6 = auStack_38;
    lVar2 = *(longlong *)(param_1 + 0x230);
    if (lVar2 == 0) break;
    MmUnmapIoSpace(*(undefined8 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0x10));
    *(undefined8 *)(param_1 + 0x230) = **(undefined8 **)(param_1 + 0x230);
    ExFreePool();
  }
  *(undefined8 *)(param_1 + 0x230) = 0;
  if (*(longlong *)(param_1 + 0x2e8) != 0) {
    ExFreePool();
    *(undefined8 *)(param_1 + 0x2e8) = 0;
  }
  plVar1 = (longlong *)(param_1 + 0x4b8);
  do {
    plVar3 = (longlong *)*plVar1;
    if (plVar3 == plVar1) {
LAB_1c0012063:
      uVar4 = *(undefined8 *)(param_1 + 0x120);
      *(undefined8 *)(puVar6 + -8) = 0x1c0012071;
      IoStopTimer(uVar4);
      *(undefined8 *)(puVar6 + -8) = 0x1c0012081;
      KeCancelTimer(param_1 + 0x78);
      *(undefined8 *)(puVar6 + -8) = 0x1c0012095;
      KeSetEvent(param_1 + 0x2f0,0,0);
      return;
    }
    if (((longlong *)plVar3[1] != plVar1) ||
       (lVar2 = *plVar3, (longlong *)*(longlong *)(lVar2 + 8) != plVar3)) {
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      puVar6 = auStack_30;
      goto LAB_1c0012063;
    }
    *plVar1 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar1;
    IoFreeMdl(plVar3[-0x15]);
    ExFreePool(plVar3 + -0x27);
  } while( true );
}



===== SCInitializeCallback @ 1c00120c0 =====

ulonglong SCInitializeCallback(longlong param_1)

{
  longlong lVar1;
  undefined8 *puVar2;
  longlong lVar3;
  longlong lVar4;
  void *_Dst;
  ulonglong uVar5;
  char local_res8 [8];
  
  lVar1 = *(longlong *)(param_1 + 0x18);
  puVar2 = *(undefined8 **)(param_1 + 0x48);
  lVar3 = *(longlong *)(param_1 + 0x28);
  local_res8[0] = '\0';
  lVar4 = *(longlong *)(lVar1 + -0x3b0);
  if (*(int *)(param_1 + 8) < 0) {
    SCFreeAllResources(lVar1 + -0x4d0);
  }
  else {
    _Dst = (void *)ExAllocatePoolWithTag(0x200,*(undefined4 *)(lVar3 + 0x48),0x736c4353);
    if (_Dst == (void *)0x0) {
      SCUninitializeMinidriver(lVar4,puVar2);
    }
    else {
      memset(_Dst,0,(ulonglong)*(uint *)(lVar3 + 0x48));
      uVar5 = SCSubmitRequest(0x100,(longlong)_Dst,*(undefined4 *)(lVar3 + 0x48),
                              SCStreamInfoCallback,lVar1 + -0x4d0,0,0,puVar2,local_res8,
                              (longlong *)(lVar1 + -0x270),
                              *(undefined **)(*(longlong *)(lVar1 + -0x2c0) + 0x10));
      if (local_res8[0] != '\0') {
        *(undefined8 *)(param_1 + 0x48) = 0;
        SCDequeueAndDeleteSrb(param_1);
        return uVar5 & 0xffffffff;
      }
      ExFreePool(_Dst);
      SCUninitializeMinidriver(lVar4,puVar2);
      *(undefined4 *)(param_1 + 8) = 0xc000009a;
    }
  }
  uVar5 = SCProcessCompletedRequest(param_1);
  return uVar5;
}



===== SCPowerCallback @ 1c0012210 =====

undefined4 SCPowerCallback(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 uVar3;
  longlong lVar4;
  
  lVar1 = *(longlong *)(param_1 + 0x18);
  lVar2 = *(longlong *)(param_1 + 0x48);
  lVar4 = lVar1 + -0x4d0;
  SCSetCurrentDPowerState(lVar4,*(int *)(param_1 + 0x28));
  SCDequeueAndDeleteSrb(param_1);
  if (*(int *)(lVar1 + -0x15c) == 1) {
    PoStartNextPowerIrp(lVar2);
    SCCompleteIrp(lVar2,0,lVar4);
    uVar3 = 0;
  }
  else {
    PoStartNextPowerIrp();
    *(char *)(lVar2 + 0x43) = *(char *)(lVar2 + 0x43) + '\x01';
    *(longlong *)(lVar2 + 0xb8) = *(longlong *)(lVar2 + 0xb8) + 0x48;
    uVar3 = PoCallDriver(*(undefined8 *)(lVar1 + -0x3a8),lVar2);
    LOCK();
    *(int *)(lVar1 + -0x188) = *(int *)(lVar1 + -0x188) + -1;
    UNLOCK();
    SCDereferenceDriver(lVar4);
  }
  return uVar3;
}



===== SCPowerCompletionWorker @ 1c00122d0 =====

void SCPowerCompletionWorker(longlong param_1)

{
  longlong lVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  
  uVar2 = *(undefined4 *)(param_1 + 0x30);
  lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x28) + 0x40);
  if (*(int *)(*(longlong *)(param_1 + 0xb8) + 0x18) != 1) {
    *(undefined4 *)(param_1 + 0x30) = 0;
    uVar3 = SCCallNextDriver(lVar1,param_1);
    uVar2 = (undefined4)uVar3;
  }
  PoStartNextPowerIrp(param_1);
  SCDereferenceDriver(lVar1);
  SCCompleteIrp(param_1,uVar2,lVar1);
  return;
}



===== SCQueryEnumId @ 1c0012348 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SCQueryEnumId(longlong param_1,int param_2,undefined8 *param_3)

{
  uint uVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  longlong lVar4;
  ulonglong uVar5;
  longlong lVar6;
  char cVar7;
  wchar_t *pwVar8;
  undefined1 auStack_78 [32];
  wchar_t *local_58;
  wchar_t *local_50;
  wchar_t local_48 [12];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_78;
  lVar6 = *(longlong *)(param_1 + 0x40);
  local_58 = (wchar_t *)0x0;
  if (param_2 == 0) {
    lVar4 = -1;
    do {
      lVar4 = lVar4 + 1;
    } while (*(short *)(*(longlong *)(lVar6 + 0x140) + lVar4 * 2) != 0);
    uVar1 = (int)lVar4 * 2 + 0x10;
    pwVar2 = (wchar_t *)ExAllocatePoolWithTag(1,uVar1,0x736c4353);
    if (pwVar2 != (wchar_t *)0x0) {
      uVar5 = RtlStringCbPrintfW(pwVar2,(ulonglong)uVar1,L"Stream\\%s",
                                 *(undefined8 *)(lVar6 + 0x140));
      goto LAB_1c00124d6;
    }
LAB_1c00124b6:
    uVar5 = 0xc000009a;
  }
  else {
    if (param_2 == 1) {
      cVar7 = '\x01';
    }
    else {
      if (param_2 != 2) {
        if (param_2 != 3) {
          return 0xc00000bb;
        }
        local_50 = local_48;
        local_58 = (wchar_t *)0xb0000;
        RtlIntegerToUnicodeString(*(undefined4 *)(lVar6 + 0x148),10,&local_58);
        pwVar2 = (wchar_t *)ExAllocatePoolWithTag(1,0x10,0x736c4353);
        if (pwVar2 != (wchar_t *)0x0) {
          lVar6 = 8;
          pwVar2[0] = L'\0';
          pwVar2[1] = L'\0';
          pwVar2[2] = L'\0';
          pwVar2[3] = L'\0';
          pwVar2[4] = L'\0';
          pwVar2[5] = L'\0';
          pwVar2[6] = L'\0';
          pwVar2[7] = L'\0';
          pwVar8 = pwVar2;
          do {
            if ((lVar6 == -0x7ffffff6) || (*local_50 == L'\0')) break;
            *pwVar8 = *local_50;
            local_50 = local_50 + 1;
            pwVar8 = pwVar8 + 1;
            lVar6 = lVar6 + -1;
          } while (lVar6 != 0);
          pwVar3 = pwVar8 + -1;
          if (lVar6 != 0) {
            pwVar3 = pwVar8;
          }
          *pwVar3 = L'\0';
          uVar5 = (ulonglong)(~-(uint)(lVar6 != 0) & 0x80000005);
          goto LAB_1c00124d6;
        }
        goto LAB_1c00124b6;
      }
      cVar7 = '\0';
    }
    uVar5 = SCBuildChildIds(*(undefined8 *)
                             (*(longlong *)(*(longlong *)(lVar6 + 0x128) + 0x40) + 0x218),cVar7,
                            *(longlong *)(lVar6 + 0x140),&local_58);
    pwVar2 = local_58;
  }
LAB_1c00124d6:
  *param_3 = pwVar2;
  return uVar5;
}



===== SCSendSurpriseNotification @ 1c0012500 =====

void SCSendSurpriseNotification(longlong param_1,undefined8 *param_2)

{
  undefined1 local_res8 [32];
  
  SCSubmitRequest(0x10e,0,0,SCDequeueAndDeleteSrb,param_1,0,0,param_2,local_res8,
                  (longlong *)(param_1 + 0x260),
                  *(undefined **)(*(longlong *)(param_1 + 0x210) + 0x10));
  return;
}



===== SCStartWorker @ 1c0012560 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SCStartWorker(undefined8 *param_1)

{
  longlong *plVar1;
  char cVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  undefined4 *puVar6;
  longlong lVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  longlong lVar10;
  undefined8 *puVar11;
  void *_Dst;
  undefined8 uVar12;
  undefined4 uVar13;
  uint uVar14;
  undefined1 auStackY_118 [32];
  char local_b8 [4];
  undefined4 local_b4;
  undefined4 local_b0;
  uint local_ac;
  undefined4 local_a8 [2];
  longlong local_a0;
  longlong local_98;
  longlong local_90;
  undefined8 local_88;
  undefined1 local_78 [4];
  undefined2 local_74;
  undefined1 local_71;
  undefined1 local_70;
  undefined4 local_68;
  undefined4 local_64;
  undefined8 local_60;
  undefined4 local_58;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_118;
  lVar3 = param_1[0x17];
  local_88 = 0;
  lVar7 = 0;
  uVar14 = 0;
  local_98 = *(longlong *)(lVar3 + 0x28);
  lVar4 = *(longlong *)(local_98 + 0x40);
  memset(local_78,0,0x40);
  iVar5 = *(int *)(param_1 + 6);
  local_a8[0] = 0;
  local_b8[0] = '\0';
  local_b0 = 0;
  local_b4 = 0;
  if (iVar5 < 0) goto LAB_1c0012b5d;
  lVar10 = *(longlong *)(lVar4 + 0x210);
  local_a0 = lVar10;
  KeInitializeSpinLock(lVar4 + 0x240);
  KeInitializeDpc(lVar4 + 0x280,StreamClassDpc,local_98);
  KeInitializeEvent(lVar4 + 0x308,1,0);
  KeInitializeTimer(lVar4 + 0x78);
  KeInitializeDpc(lVar4 + 0xb8,SCMinidriverDeviceTimerDpc,lVar4);
  lVar3 = *(longlong *)(lVar3 + 0x10);
  puVar6 = (undefined4 *)ExAllocatePoolWithTag(0x200,0x78,0x736c4353);
  if (puVar6 == (undefined4 *)0x0) {
LAB_1c0012689:
    iVar5 = -0x3fffff66;
    goto LAB_1c0012b5d;
  }
  memset(puVar6 + 1,0,0x74);
  *(undefined4 **)(lVar4 + 0x228) = puVar6;
  *puVar6 = 0x78;
  *(undefined8 *)(puVar6 + 6) = *(undefined8 *)(lVar4 + 0x128);
  uVar12 = *(undefined8 *)(lVar4 + 0x218);
  puVar6[0xb] = 0xffffffff;
  puVar6[0xd] = 0xffffffff;
  *(undefined8 *)(puVar6 + 0x1a) = uVar12;
  puVar6[0xc] = 1;
  *(undefined8 **)(puVar6 + 0x14) = param_1;
  if (lVar3 == 0) {
LAB_1c00128b5:
    puVar6[0xe] = uVar14;
    uVar14 = *(uint *)(lVar10 + 0x44);
    if ((*(char *)(lVar10 + 0x38) == '\0') && (uVar14 == 0)) {
      *(undefined4 *)(lVar4 + 0x150) = 0xffffffff;
    }
    else {
      memset(local_78,0,0x40);
      local_68 = puVar6[0xd];
      local_64 = puVar6[9];
      local_60 = 2;
      local_74 = 0x101;
      local_70 = *(char *)(lVar10 + 0x39) == '\0';
      local_71 = 0;
      local_58 = 0xffffffff;
      uVar12 = IoGetDmaAdapter(*(undefined8 *)(lVar4 + 0x218),local_78,local_a8);
      *(undefined8 *)(lVar4 + 0x148) = uVar12;
      *(undefined4 *)(lVar4 + 0x150) = local_a8[0];
      *(undefined8 *)(puVar6 + 0x18) = uVar12;
      if (uVar14 != 0) {
        _Dst = (void *)(**(code **)(*(longlong *)(*(longlong *)(lVar4 + 0x148) + 8) + 0x10))
                                 (*(longlong *)(lVar4 + 0x148),uVar14,lVar4 + 0x250,0);
        if (_Dst == (void *)0x0) {
          SCFreeAllResources(lVar4);
          goto LAB_1c0012689;
        }
        memset(_Dst,0,(ulonglong)uVar14);
        *(void **)(lVar4 + 600) = _Dst;
        *(uint *)(lVar4 + 0x24c) = uVar14;
        lVar10 = local_a0;
      }
    }
    *(code **)(lVar4 + 0x238) = KeSynchronizeExecution_exref;
    if (*(char *)(lVar4 + 800) != '\0') {
      *(code **)(lVar4 + 0x238) = StreamClassSynchronizeExecution;
      *(longlong *)(lVar4 + 0x138) = lVar4;
    }
    if ((*(longlong *)(lVar10 + 8) == 0) || ((puVar6[10] == 0 && (puVar6[0xb] == 0)))) {
      *(code **)(lVar4 + 0x238) = StreamClassSynchronizeExecution;
      *(longlong *)(lVar4 + 0x138) = lVar4;
    }
    else {
      puVar11 = (undefined8 *)(lVar4 + 0x138);
      iVar5 = IoConnectInterrupt(puVar11,StreamClassInterrupt,local_98,0);
      if (iVar5 < 0) {
        *puVar11 = 0;
        goto LAB_1c0012b55;
      }
      *(undefined8 *)(puVar6 + 0x16) = *puVar11;
    }
    *(undefined8 *)(puVar6 + 2) = *(undefined8 *)(lVar4 + 0x220);
    *(longlong *)(puVar6 + 4) = local_98;
    IoStartTimer(local_98);
    plVar1 = (longlong *)(lVar4 + 0x260);
    *(longlong *)(lVar4 + 0x3b0) = lVar4;
    lVar3 = lVar4 + 0x270;
    *(longlong **)(lVar4 + 0x268) = plVar1;
    *(longlong *)(lVar4 + 0x278) = lVar3;
    *(longlong *)lVar3 = lVar3;
    lVar3 = lVar4 + 0x388;
    *plVar1 = (longlong)plVar1;
    *(longlong *)(lVar4 + 0x390) = lVar3;
    *(longlong *)lVar3 = lVar3;
    *(code **)(lVar4 + 0x3a8) = SCFreeDeadEvents;
    *(code **)(lVar4 + 1000) = SCPowerCompletionWorker;
    *(code **)(lVar4 + 0x408) = SCDevIrpCompletionWorker;
    *(undefined8 *)(lVar4 + 0x398) = 0;
    *(longlong *)(lVar4 + 0x3f0) = lVar4;
    *(undefined8 *)(lVar4 + 0x3d8) = 0;
    *(longlong *)(lVar4 + 0x410) = lVar4;
    *(undefined8 *)(lVar4 + 0x3f8) = 0;
    *(undefined1 *)(lVar4 + 0x418) = 1;
    uVar12 = SCSubmitRequest(0x107,(longlong)puVar6,0x78,SCInitializeCallback,lVar4,0,0,param_1,
                             local_b8,plVar1,*(undefined **)(*(longlong *)(lVar4 + 0x210) + 0x10));
    iVar5 = (int)uVar12;
    if (local_b8[0] != '\0') {
      return;
    }
  }
  else {
    iVar5 = IoGetDeviceProperty(*(undefined8 *)(lVar4 + 0x218),0xe,4,puVar6 + 8);
    if (iVar5 < 0) {
      puVar6[8] = 0;
    }
    iVar5 = IoGetDeviceProperty(*(undefined8 *)(lVar4 + 0x218),0xd,4,&local_b0);
    uVar13 = 0xffffffff;
    if (-1 < iVar5) {
      uVar13 = local_b0;
    }
    puVar6[9] = uVar13;
    if ((*(uint *)(lVar3 + 0x10) == 0) ||
       (lVar7 = ExAllocatePoolWithTag(0x200,(ulonglong)*(uint *)(lVar3 + 0x10) * 0x18,0x736c4353),
       lVar7 != 0)) {
      uVar8 = 0;
      *(longlong *)(puVar6 + 0x10) = lVar7;
      local_ac = 0;
      if (*(int *)(lVar3 + 0x10) != 0) {
        do {
          cVar2 = *(char *)(lVar3 + 0x14 + uVar8 * 0x14);
          if (cVar2 == '\x01') {
            uVar9 = (ulonglong)uVar14;
            uVar14 = uVar14 + 1;
            *(undefined8 *)(lVar7 + uVar9 * 0x18) = *(undefined8 *)(lVar3 + 0x18 + uVar8 * 0x14);
            *(undefined4 *)(lVar7 + 8 + uVar9 * 0x18) = *(undefined4 *)(lVar3 + 0x20 + uVar8 * 0x14)
            ;
            *(undefined1 *)(lVar7 + 0xc + uVar9 * 0x18) = 0;
          }
          else if (cVar2 == '\x02') {
            puVar6[0xb] = *(undefined4 *)(lVar3 + 0x1c + uVar8 * 0x14);
            local_88 = *(undefined8 *)(lVar3 + 0x20 + uVar8 * 0x14);
            puVar6[10] = *(undefined4 *)(lVar3 + 0x18 + uVar8 * 0x14);
            puVar6[0xc] = (uint)*(ushort *)(lVar3 + 0x16 + uVar8 * 0x14);
          }
          else if (cVar2 == '\x03') {
            uVar12 = *(undefined8 *)(lVar3 + 0x18 + uVar8 * 0x14);
            uVar9 = (ulonglong)uVar14;
            local_90 = uVar9 * 3;
            uVar13 = *(undefined4 *)(lVar3 + 0x20 + uVar8 * 0x14);
            *(undefined4 *)(lVar7 + 8 + uVar9 * 0x18) = uVar13;
            *(undefined1 *)(lVar7 + 0xc + uVar9 * 0x18) = 1;
            lVar10 = MmMapIoSpaceEx(uVar12,uVar13,0x204);
            *(longlong *)(lVar7 + local_90 * 8) = lVar10;
            if (lVar10 == 0) {
              SCFreeAllResources(lVar4);
              iVar5 = -0x3fffffe8;
              goto LAB_1c0012b5d;
            }
            puVar11 = (undefined8 *)ExAllocatePoolWithTag(0x200,0x28,0x736c4353);
            if (puVar11 != (undefined8 *)0x0) {
              puVar11[1] = *(undefined8 *)(lVar7 + local_90 * 8);
              *(undefined4 *)(puVar11 + 2) = *(undefined4 *)(lVar7 + 8 + local_90 * 8);
              puVar11[3] = *(undefined8 *)(lVar3 + 0x18 + uVar8 * 0x14);
              *(undefined4 *)(puVar11 + 4) = puVar6[8];
              *puVar11 = *(undefined8 *)(lVar4 + 0x230);
              *(undefined8 **)(lVar4 + 0x230) = puVar11;
            }
            uVar14 = uVar14 + 1;
          }
          local_ac = local_ac + 1;
          uVar8 = (ulonglong)local_ac;
        } while (local_ac < *(uint *)(lVar3 + 0x10));
        lVar10 = local_a0;
      }
      goto LAB_1c00128b5;
    }
    iVar5 = -0x3fffff66;
    *(undefined4 *)(param_1 + 6) = 0xc000009a;
  }
LAB_1c0012b55:
  SCFreeAllResources(lVar4);
LAB_1c0012b5d:
  SCCompleteIrp((longlong)param_1,iVar5,lVar4);
  return;
}



===== SCStreamInfoCallback @ 1c0012ba0 =====

void SCStreamInfoCallback(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  int *piVar3;
  uint *puVar4;
  void *pvVar5;
  undefined8 uVar6;
  undefined4 uVar7;
  longlong lVar8;
  int *piVar9;
  longlong lVar10;
  ulonglong uVar11;
  uint uVar12;
  ulonglong uVar13;
  undefined1 local_res8 [8];
  
  lVar1 = *(longlong *)(param_1 + 0x18);
  lVar2 = *(longlong *)(param_1 + 0x58);
  lVar8 = lVar1 + -0x4d0;
  if (lVar2 == 0) {
    piVar3 = *(int **)(param_1 + 0x28);
    lVar2 = *(longlong *)(lVar1 + -0xa0);
    *(int **)(lVar1 + -0x1e8) = piVar3;
    KeWaitForSingleObject(lVar1 + -0x1e0,0,0,0,0);
    uVar13 = 0;
    uVar11 = 0;
    if (*(int *)(lVar1 + -0xb0) != 0) {
      piVar9 = piVar3;
      do {
        if (((ulonglong)*(uint *)(param_1 + 0x60) < uVar11 + 0x48) || (piVar9[1] != 0x88)) break;
        lVar10 = uVar13 * 0x20;
        if ((*(uint *)(lVar1 + -0x3a0) & 0x10) == 0) {
          pvVar5 = SciCreateSymbolicLinks(lVar8,(uint)uVar13,(longlong)piVar9);
          *(void **)(lVar10 + lVar2) = pvVar5;
          uVar7 = **(undefined4 **)(piVar9 + 10);
        }
        else {
          *(undefined8 *)(lVar10 + lVar2) = 0;
          uVar7 = 0;
        }
        *(undefined4 *)(lVar10 + 8 + lVar2) = uVar7;
        uVar12 = (uint)uVar13 + 1;
        uVar13 = (ulonglong)uVar12;
        *(int **)(lVar10 + 0x10 + lVar2) = piVar9;
        uVar11 = (ulonglong)(uint)((int)uVar11 + *piVar9 * 0x88 + 0x48);
        piVar9 = (int *)((longlong)piVar3 + uVar11);
      } while (uVar12 < *(uint *)(lVar1 + -0xb0));
    }
    *(uint *)(lVar1 + -0x3b8) = *(uint *)(lVar1 + -0x3b8) | 1;
    SCSubmitRequest(0x10d,0,0,SCDequeueAndDeleteSrb,lVar8,0,0,*(undefined8 **)(param_1 + 0x48),
                    local_res8,(longlong *)(lVar1 + -0x270),
                    *(undefined **)(*(longlong *)(lVar1 + -0x2c0) + 0x10));
    SCCheckPowerDown(lVar8);
    KeSetEvent(lVar1 + -0x1e0,0,0);
  }
  else {
    puVar4 = *(uint **)(param_1 + 0x28);
    uVar6 = SciOnFilterStreamDescriptor(lVar2 + -0xd0,puVar4);
    if (-1 < (int)uVar6) {
      ExFreePool(*(undefined8 *)(lVar2 + -0x10));
      *(uint **)(lVar2 + -0x10) = puVar4;
    }
  }
  SCProcessCompletedRequest(param_1);
  return;
}



===== SCUninitializeCallback @ 1c0012d80 =====

int SCUninitializeCallback(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(param_1 + 0x18);
  iVar1 = *(int *)(param_1 + 8);
  KeSetEvent(lVar2 + -0x1e0,0,0);
  if (iVar1 != -0x3fffff3e) {
    *(uint *)(lVar2 + -0x3b8) = *(uint *)(lVar2 + -0x3b8) & 0xfffffffe;
    SCFreeAllResources(lVar2 + -0x4d0);
  }
  SCDequeueAndDeleteSrb(param_1);
  return iVar1;
}



===== SCUninitializeMinidriver @ 1c0012df0 =====

ulonglong SCUninitializeMinidriver(longlong param_1,undefined8 *param_2)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  uint uVar5;
  longlong lVar6;
  uint uVar7;
  longlong *plVar8;
  char local_res8 [8];
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  local_res8[0] = '\0';
  if ((*(longlong *)(lVar2 + 0x430) != 0) && (uVar7 = 0, *(int *)(lVar2 + 0x420) != 0)) {
    do {
      uVar4 = 0;
      lVar6 = (ulonglong)uVar7 * 0x20;
      lVar3 = *(longlong *)(*(longlong *)(lVar2 + 0x430) + lVar6);
      if (lVar3 != 0) {
        uVar1 = *(uint *)(*(longlong *)(lVar2 + 0x430) + 8 + lVar6);
        if (uVar1 != 0) {
          plVar8 = (longlong *)(lVar3 + 8);
          do {
            if (*plVar8 != 0) {
              IoSetDeviceInterfaceState(uVar4 * 0x10 + lVar3);
              ExFreePool(*plVar8);
            }
            uVar5 = (int)uVar4 + 1;
            uVar4 = (ulonglong)uVar5;
            plVar8 = plVar8 + 2;
          } while (uVar5 < uVar1);
        }
        ExFreePool(lVar3);
        *(undefined8 *)(lVar6 + *(longlong *)(lVar2 + 0x430)) = 0;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < *(uint *)(lVar2 + 0x420));
  }
  LOCK();
  *(int *)(lVar2 + 0x348) = *(int *)(lVar2 + 0x348) + -1;
  UNLOCK();
  SCWaitForOutstandingIo(lVar2);
  KeWaitForSingleObject(lVar2 + 0x2f0,0,0,0,0);
  LOCK();
  *(int *)(lVar2 + 0x348) = *(int *)(lVar2 + 0x348) + 1;
  UNLOCK();
  uVar4 = SCSubmitRequest(0x109,0,0,SCUninitializeCallback,lVar2,0,0,param_2,local_res8,
                          (longlong *)(lVar2 + 0x260),
                          *(undefined **)(*(longlong *)(lVar2 + 0x210) + 0x10));
  if (local_res8[0] == '\0') {
    KeSetEvent(lVar2 + 0x2f0,0,0);
  }
  return uVar4 & 0xffffffff;
}



===== SCUnknownPNPCallback @ 1c0012fa0 =====

void SCUnknownPNPCallback(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  ulonglong uVar4;
  int iVar5;
  
  lVar1 = *(longlong *)(param_1 + 0x18);
  lVar2 = *(longlong *)(param_1 + 0x48);
  uVar4 = SCDequeueAndDeleteSrb(param_1);
  iVar3 = (int)uVar4;
  if (iVar3 == -0x3ffffffe) {
    iVar5 = -0x3fffff45;
  }
  else {
    iVar5 = iVar3;
    if ((iVar3 != -0x3fffff45) && (iVar3 < 0)) goto LAB_1c0013004;
  }
  uVar4 = SCCallNextDriver(lVar1 + -0x4d0,lVar2);
  iVar3 = (int)uVar4;
  if (((int)uVar4 == -0x3fffff45) && (iVar3 = iVar5, iVar5 == -0x3fffff45)) {
    iVar3 = *(int *)(lVar2 + 0x30);
  }
LAB_1c0013004:
  SCCompleteIrp(lVar2,iVar3,lVar1 + -0x4d0);
  return;
}



===== SCUnknownPowerCallback @ 1c0013040 =====

void SCUnknownPowerCallback(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  ulonglong uVar4;
  int iVar5;
  
  lVar1 = *(longlong *)(param_1 + 0x18);
  lVar2 = *(longlong *)(param_1 + 0x48);
  uVar4 = SCDequeueAndDeleteSrb(param_1);
  iVar3 = (int)uVar4;
  if (iVar3 == -0x3ffffffe) {
    iVar5 = -0x3fffff45;
  }
  else {
    iVar5 = iVar3;
    if ((iVar3 != -0x3fffff45) && (iVar3 < 0)) goto LAB_1c0013098;
  }
  uVar4 = SCCallNextDriver(lVar1 + -0x4d0,lVar2);
  iVar3 = (int)uVar4;
  if ((int)uVar4 == -0x3fffff45) {
    iVar3 = iVar5;
  }
LAB_1c0013098:
  PoStartNextPowerIrp(lVar2);
  SCCompleteIrp(lVar2,iVar3,lVar1 + -0x4d0);
  return;
}



===== StreamClassForwardUnsupported @ 1c00130e0 =====

ulonglong StreamClassForwardUnsupported(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  undefined4 extraout_var;
  ulonglong uVar4;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  *(undefined8 *)(param_2 + 0x38) = 0;
  if ((*(uint *)(lVar1 + 0x118) & 2) == 0) {
    SCReferenceDriver(lVar1);
    uVar3 = SCShowIoPending(lVar1,param_2);
    uVar4 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      *(int *)(param_2 + 0x30) = (int)uVar3;
      IofCompleteRequest(param_2,0);
    }
    else {
      SCCallNextDriver(lVar1,param_2);
      SCDereferenceDriver(lVar1);
      uVar2 = SCCompleteIrp(param_2,*(undefined4 *)(param_2 + 0x30),lVar1);
      uVar4 = CONCAT44(extraout_var,uVar2);
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x30) = 0xc00000bb;
    IofCompleteRequest(param_2,0);
    uVar4 = 0xc00000bb;
  }
  return uVar4;
}



===== StreamClassPnP @ 1c0013190 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong StreamClassPnP(longlong param_1,undefined8 *param_2)

{
  longlong *plVar1;
  byte bVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  longlong lVar5;
  longlong *plVar6;
  code *pcVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  undefined4 uVar11;
  undefined4 *puVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  undefined8 uVar15;
  undefined4 extraout_var;
  undefined1 *puVar16;
  undefined1 auStackY_e8 [8];
  undefined1 auStackY_e0 [24];
  char local_88 [16];
  undefined4 local_78 [4];
  longlong local_68;
  longlong lStack_60;
  longlong local_58;
  undefined4 local_50;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_e8;
  uVar9 = 0;
  local_88[0] = '\0';
  memset(local_78,0,0x40);
  plVar3 = *(longlong **)(param_1 + 0x40);
  puVar4 = (undefined8 *)param_2[0x17];
  uVar10 = *(uint *)(plVar3 + 0x23);
  if ((uVar10 & 2) == 0) {
    SCReferenceDriver((longlong)plVar3);
    LOCK();
    *(int *)(plVar3 + 0x69) = (int)plVar3[0x69] + 1;
    UNLOCK();
    bVar2 = *(byte *)((longlong)puVar4 + 1);
    if (5 < bVar2) {
      if (bVar2 == 6) {
LAB_1c0013863:
        *(uint *)(plVar3 + 0x23) = *(uint *)(plVar3 + 0x23) & 0xfffffeff;
        SCCallNextDriver((longlong)plVar3,(longlong)param_2);
        SCDereferenceDriver((longlong)plVar3);
        iVar8 = 0;
      }
      else {
        if (bVar2 != 7) {
          if (bVar2 == 8) {
            uVar15 = SCHandleQueryInterface((longlong)plVar3,(longlong)param_2);
            iVar8 = (int)uVar15;
            if (-1 < iVar8) goto LAB_1c001377a;
          }
          else {
            if (bVar2 == 9) {
              *(undefined4 *)(param_2 + 6) = 0xc00000bb;
              uVar13 = SCCallNextDriver((longlong)plVar3,(longlong)param_2);
              iVar8 = (int)uVar13;
              *(uint *)(puVar4[1] + 4) = *(uint *)(puVar4[1] + 4) | 0x200;
LAB_1c001377a:
              uVar9 = SCCompleteIrp((longlong)param_2,iVar8,(longlong)plVar3);
              goto LAB_1c001364c;
            }
            if (bVar2 == 0x17) {
              if ((*(uint *)(plVar3 + 0x23) & 1) != 0) {
                SCSendSurpriseNotification((longlong)plVar3,param_2);
                SCUninitializeMinidriver(param_1,param_2);
              }
              uVar13 = SCCallNextDriver((longlong)plVar3,(longlong)param_2);
              uVar9 = SCCompleteIrp((longlong)param_2,(int)uVar13,(longlong)plVar3);
              SCDereferenceDriver((longlong)plVar3);
              *(uint *)(plVar3 + 0x23) = *(uint *)(plVar3 + 0x23) | 0x400;
              goto LAB_1c0013332;
            }
          }
LAB_1c001379b:
          if ((*(uint *)(plVar3 + 0x23) & 1) == 0) {
            uVar14 = SCCallNextDriver((longlong)plVar3,(longlong)param_2);
            uVar13 = uVar14 & 0xffffffff;
            SCCompleteIrp((longlong)param_2,(int)uVar14,(longlong)plVar3);
          }
          else {
            uVar13 = SCSubmitRequest(0x10a,0,0,SCUnknownPNPCallback,(longlong)plVar3,0,0,param_2,
                                     local_88,plVar3 + 0x4c,*(undefined **)(plVar3[0x42] + 0x10));
            uVar13 = uVar13 & 0xffffffff;
            if (local_88[0] == '\0') {
              uVar10 = SCCompleteIrp((longlong)param_2,0xc000009a,(longlong)plVar3);
              uVar13 = (ulonglong)uVar10;
            }
          }
          SCDereferenceDriver((longlong)plVar3);
          puVar16 = auStackY_e8;
          goto LAB_1c001388b;
        }
        if (*(int *)(puVar4 + 1) == 0) {
          iVar8 = SCEnumerateChildren(param_1,(longlong)param_2);
        }
        else {
          uVar13 = SCCallNextDriver((longlong)plVar3,(longlong)param_2);
          iVar8 = (int)uVar13;
        }
        SCDereferenceDriver((longlong)plVar3);
      }
      uVar11 = SCCompleteIrp((longlong)param_2,iVar8,(longlong)plVar3);
      uVar13 = CONCAT44(extraout_var,uVar11);
      puVar16 = auStackY_e8;
      goto LAB_1c001388b;
    }
    if (bVar2 == 5) {
      *(undefined4 *)(param_2 + 6) = 0;
      if ((*(uint *)(plVar3 + 0x23) & 1) != 0) {
        KeWaitForSingleObject(plVar3 + 0x5e,0,0,0);
      }
      if ((int)plVar3[0x5b] == 0) {
        *(uint *)(plVar3 + 0x23) = *(uint *)(plVar3 + 0x23) | 0x100;
LAB_1c0013697:
        SCCallNextDriver((longlong)plVar3,(longlong)param_2);
        uVar9 = SCQueryWorker(param_1,(longlong)param_2);
      }
      else {
LAB_1c00136af:
        uVar9 = SCCompleteIrp((longlong)param_2,0x80000011,(longlong)plVar3);
      }
      if ((*(uint *)(plVar3 + 0x23) & 1) != 0) {
        KeSetEvent(plVar3 + 0x5e,0,0);
      }
    }
    else {
      if (bVar2 != 0) {
        if (bVar2 == 1) {
          *(undefined4 *)(param_2 + 6) = 0;
          uVar10 = *(uint *)(plVar3 + 0x23);
          if ((uVar10 & 1) != 0) {
            KeWaitForSingleObject(plVar3 + 0x5e,0,0,0);
            uVar10 = *(uint *)(plVar3 + 0x23);
          }
          if ((int)plVar3[0x5b] != 0) goto LAB_1c00136af;
          *(uint *)(plVar3 + 0x23) = uVar10 | 0x100;
          goto LAB_1c0013697;
        }
        if (bVar2 != 2) {
          if (bVar2 != 3) {
            if (bVar2 == 4) {
              if (((*(uint *)(plVar3 + 0x23) & 1) == 0) ||
                 (uVar14 = SCUninitializeMinidriver(param_1,param_2), -1 < (int)uVar14)) {
                uVar14 = SCCallNextDriver((longlong)plVar3,(longlong)param_2);
              }
              uVar13 = uVar14 & 0xffffffff;
              SCRedispatchPendedIrps((longlong)plVar3,'\x01');
              SCCompleteIrp((longlong)param_2,(int)uVar14,(longlong)plVar3);
              SCDereferenceDriver((longlong)plVar3);
              puVar16 = auStackY_e8;
              goto LAB_1c001388b;
            }
            goto LAB_1c001379b;
          }
          goto LAB_1c0013863;
        }
        if ((*(uint *)(plVar3 + 0x23) & 1) == 0) {
LAB_1c0013446:
          uVar13 = SCCallNextDriver((longlong)plVar3,(longlong)param_2);
          iVar8 = (int)uVar13;
        }
        else {
          SCSendSurpriseNotification((longlong)plVar3,param_2);
          uVar13 = SCUninitializeMinidriver(param_1,param_2);
          iVar8 = (int)uVar13;
          if (-1 < iVar8) goto LAB_1c0013446;
        }
        SCRedispatchPendedIrps((longlong)plVar3,'\x01');
        uVar10 = SCCompleteIrp((longlong)param_2,iVar8,(longlong)plVar3);
        uVar13 = (ulonglong)uVar10;
        SCDereferenceDriver((longlong)plVar3);
        puVar16 = auStackY_e8;
        if (-1 < (int)uVar10) {
          if (*plVar3 != 0) {
            KsFreeDeviceHeader();
          }
          KeWaitForSingleObject(plVar3 + 0x5e,0,0,0);
          puVar16 = auStackY_e8;
          if ((int)plVar3[0x5b] == 0) {
            if (plVar3[0x25] != 0) {
              IoDetachDevice();
              plVar3[0x25] = 0;
            }
            puVar16 = auStackY_e8;
            plVar1 = plVar3 + 0x6f;
            while (plVar6 = (longlong *)*plVar1, plVar6 != plVar1) {
              if (((longlong *)plVar6[1] != plVar1) ||
                 (lVar5 = *plVar6, *(longlong **)(lVar5 + 8) != plVar6)) {
                pcVar7 = (code *)swi(0x29);
                (*pcVar7)(3);
                puVar16 = auStackY_e0;
                break;
              }
              *plVar1 = lVar5;
              *(longlong **)(lVar5 + 8) = plVar1;
              *(uint *)(plVar6 + -3) = *(uint *)(plVar6 + -3) | 0x800;
              IoDeleteDevice(plVar6[-2]);
            }
          }
          *(undefined8 *)(puVar16 + -8) = 0x1c0013531;
          KeSetEvent(plVar3 + 0x5e,0,0);
          if (plVar3[0x86] != 0) {
            *(undefined8 *)(puVar16 + -8) = 0x1c0013549;
            ExFreePool();
            plVar3[0x86] = 0;
            plVar3[0x85] = 0;
          }
          *(undefined8 *)(puVar16 + -8) = 0x1c0013564;
          dma64DestroyBuffer((longlong)plVar3);
          lVar5 = plVar3[0x24];
          *(undefined8 *)(puVar16 + -8) = 0x1c0013572;
          IoDeleteDevice(lVar5);
        }
        goto LAB_1c001388b;
      }
      memset((void *)plVar3[0x44],0,(ulonglong)*(uint *)(plVar3[0x65] + 0x28));
      *(uint *)(plVar3 + 0x23) = *(uint *)(plVar3 + 0x23) & 0xfffffeff;
      SCCallNextDriver((longlong)plVar3,(longlong)param_2);
      local_78[0]._0_2_ = 0x40;
      iVar8 = SCQueryCapabilities(plVar3[0x25],local_78);
      if (-1 < iVar8) {
        plVar3[0x6b] = local_68;
        plVar3[0x6c] = lStack_60;
        plVar3[0x6d] = local_58;
        *(undefined4 *)(plVar3 + 0x6e) = local_50;
      }
      uVar9 = SCStartWorker(param_2);
    }
LAB_1c001364c:
    SCDereferenceDriver((longlong)plVar3);
  }
  else {
    bVar2 = *(byte *)((longlong)puVar4 + 1);
    if (bVar2 < 8) {
      if (bVar2 == 7) {
        if (*(int *)(puVar4 + 1) == 4) {
          puVar12 = (undefined4 *)ExAllocatePoolWithTag(1,0x10,0x736c4353);
          if (puVar12 == (undefined4 *)0x0) {
            uVar9 = 0xc000009a;
          }
          else {
            ObfReferenceObject(param_1);
            *puVar12 = 1;
            *(longlong *)(puVar12 + 2) = param_1;
          }
          param_2[7] = puVar12;
        }
        else {
          uVar9 = *(uint *)(param_2 + 6);
        }
      }
      else if (bVar2 == 0) {
        *(uint *)(plVar3 + 0x23) = uVar10 & 0xfffff7ff;
      }
      else if (bVar2 != 1) {
        if (bVar2 == 2) {
          if ((uVar10 >> 0xb & 1) != 0) {
            if (plVar3[0x28] != 0) {
              ExFreePool();
            }
            IoDeleteDevice(param_1);
          }
        }
        else if ((bVar2 != 4) && (bVar2 != 5)) goto LAB_1c00132d8;
      }
    }
    else {
      if (bVar2 == 8) {
        puVar4[-9] = *puVar4;
        puVar4[-8] = puVar4[1];
        puVar4[-7] = puVar4[2];
        puVar4[-6] = puVar4[3];
        puVar4[-5] = puVar4[4];
        puVar4[-4] = puVar4[5];
        puVar4[-3] = puVar4[6];
        *(undefined1 *)((longlong)puVar4 + -0x45) = 0;
        uVar13 = IofCallDriver(plVar3[0x25],param_2);
        puVar16 = auStackY_e8;
        goto LAB_1c001388b;
      }
      if (bVar2 == 9) {
        lVar5 = puVar4[1];
        *(uint *)(lVar5 + 4) = *(uint *)(lVar5 + 4) & 0xffffff83;
        *(undefined8 *)(lVar5 + 0x2c) = 0;
        *(undefined4 *)(lVar5 + 0x34) = 10;
        *(undefined4 *)(lVar5 + 0x38) = 10;
        *(undefined4 *)(lVar5 + 0x3c) = 10;
        *(undefined4 *)(lVar5 + 0x10) = 1;
        *(undefined4 *)(lVar5 + 0x14) = 1;
        *(undefined4 *)(lVar5 + 0x18) = 1;
        *(undefined4 *)(lVar5 + 0x1c) = 1;
        *(undefined4 *)(lVar5 + 0x20) = 1;
      }
      else if (bVar2 != 0xb) {
        if (bVar2 == 0x13) {
          uVar13 = SCQueryEnumId(param_1,*(int *)(puVar4 + 1),param_2 + 7);
          uVar9 = (uint)uVar13;
        }
        else {
LAB_1c00132d8:
          uVar9 = 0xc0000002;
        }
      }
    }
    *(uint *)(param_2 + 6) = uVar9;
    IofCompleteRequest(param_2,0);
  }
LAB_1c0013332:
  puVar16 = auStackY_e8;
  uVar13 = (ulonglong)uVar9;
LAB_1c001388b:
  *(undefined8 *)(puVar16 + -8) = 0x1c001389b;
  return uVar13;
}



===== StreamClassPnPAddDevice @ 1c00138c0 =====

void StreamClassPnPAddDevice(undefined8 param_1,undefined8 param_2)

{
  longlong local_res18 [2];
  
  local_res18[0] = 0;
  StreamClassPnPAddDeviceWorker(param_1,param_2,local_res18);
  return;
}



===== StreamClassPnPAddDeviceWorker @ 1c00138e0 =====

ulonglong StreamClassPnPAddDeviceWorker(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  longlong lVar1;
  longlong *plVar2;
  undefined8 uVar3;
  code *pcVar4;
  short sVar5;
  uint uVar6;
  longlong lVar7;
  ulonglong uVar8;
  longlong lVar9;
  undefined4 *puVar10;
  longlong *plVar11;
  uint uVar12;
  undefined8 *puVar13;
  undefined1 *puVar14;
  longlong *plVar15;
  longlong local_res20;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [24];
  undefined4 local_48;
  undefined1 local_40;
  longlong *local_38;
  
                    /* 0x138e0  14  StreamClassPnPAddDeviceWorker */
  local_res20 = 0;
  lVar7 = IoGetDriverObjectExtension();
  if (lVar7 == 0) {
    SCLogError(param_1,0,0xc006001c,0x1004);
    return 0xc00000c0;
  }
  *(int *)(lVar7 + 0x7c) = *(int *)(lVar7 + 0x7c) + 1;
  local_38 = &local_res20;
  local_40 = 0;
  local_48 = 0x180;
  uVar8 = IoCreateDevice(param_1,*(int *)(lVar7 + 0x28) + 0x4d0,0);
  if ((int)uVar8 < 0) {
    return uVar8;
  }
  memset(*(void **)(local_res20 + 0x40),0,(ulonglong)*(uint *)(lVar7 + 0x28) + 0x4d0);
  lVar9 = IoAttachDeviceToDeviceStack(local_res20,param_2);
  if (lVar9 == 0) {
    IoDeleteDevice(local_res20);
    return uVar8 & 0xffffffff;
  }
  lVar1 = *(longlong *)(local_res20 + 0x40);
  *param_3 = lVar1;
  *(undefined4 *)(lVar1 + 0x438) = 0x44727453;
  *(undefined4 *)(*param_3 + 0x2c0) = 0x44727453;
  *(longlong *)(lVar1 + 0x128) = lVar9;
  KsSetDevicePnpAndBaseObject(lVar1,lVar9,local_res20);
  *(longlong *)(lVar1 + 0x328) = lVar7;
  *(undefined4 *)(lVar1 + 0x348) = 1;
  uVar6 = IoInitializeTimer(local_res20,StreamClassTickHandler,0);
  if (-1 < (int)uVar6) {
    lVar9 = lVar1 + 0x378;
    *(longlong *)(lVar1 + 0x380) = lVar9;
    *(longlong *)lVar9 = lVar9;
    KeInitializeEvent(lVar1 + 0x2f0,1,1);
    *(undefined4 *)(lVar1 + 0x374) = 1;
    *(undefined4 *)(lVar1 + 0x460) = 1;
    *(longlong *)(lVar1 + 0x210) = lVar7;
    *(undefined4 *)(lVar1 + 0x43c) = *(undefined4 *)(lVar7 + 0x34);
    *(longlong *)(lVar1 + 0x120) = local_res20;
    *(longlong *)(lVar1 + 0x220) = lVar1 + 0x4d0;
    lVar9 = lVar1 + 0x440;
    *(longlong *)(lVar1 + 0x448) = lVar9;
    *(longlong *)lVar9 = lVar9;
    *(undefined8 *)(lVar1 + 0x218) = param_2;
    KeInitializeSpinLock(lVar1 + 0x450);
    KeInitializeSpinLock(lVar1 + 0x458);
    KeInitializeEvent(lVar1 + 0x468,0);
    *(undefined4 *)(lVar1 + 0x480) = 1;
    *(undefined8 *)(lVar1 + 0x488) = 0;
    *(undefined4 *)(lVar1 + 0x490) = 0;
    KeInitializeEvent(lVar1 + 0x498);
    KeInitializeSpinLock(lVar1 + 0x4c8);
    plVar15 = (longlong *)(lVar1 + 0x4b8);
    uVar12 = 0;
    *(longlong **)(lVar1 + 0x4c0) = plVar15;
    *plVar15 = (longlong)plVar15;
    do {
      puVar14 = auStack_68;
      puVar10 = SCBuildRequestPacket(lVar1,0,0,0);
      if (puVar10 == (undefined4 *)0x0) goto LAB_1c0013d91;
      plVar2 = *(longlong **)(lVar1 + 0x4c0);
      plVar11 = (longlong *)(puVar10 + 0x4e);
      if ((longlong *)*plVar2 != plVar15) goto LAB_1c0013dd7;
      *(longlong **)(puVar10 + 0x50) = plVar2;
      *plVar11 = (longlong)plVar15;
      *plVar2 = (longlong)plVar11;
      *(longlong **)(lVar1 + 0x4c0) = plVar11;
      uVar12 = uVar12 + 1;
    } while (uVar12 < 2);
    *(uint *)(local_res20 + 0x30) = *(uint *)(local_res20 + 0x30) | 0x10;
    lVar9 = lVar1 + 0x2c8;
    *(longlong *)(lVar1 + 0x2d0) = lVar9;
    *(longlong *)lVar9 = lVar9;
    uVar12 = *(uint *)(lVar7 + 0x48);
    *(uint *)(lVar1 + 0x41c) = uVar12;
    uVar8 = (ulonglong)uVar12;
    if (uVar12 == 0) {
      uVar8 = 1;
    }
    lVar9 = ExAllocatePoolWithTag(0x200,uVar8 * 0x50,0x736c4353);
    if (lVar9 != 0) {
      *(int *)(lVar1 + 0x420) = (int)uVar8;
      uVar6 = 0;
      *(longlong *)(lVar1 + 0x430) = lVar9;
      puVar13 = (undefined8 *)(uVar8 * 0x20 + lVar9);
      *puVar13 = FilterDispatchGlobalCreate;
      puVar13[1] = 0;
      *(undefined4 *)(puVar13 + 2) = 0xe000c;
      *(undefined4 *)((longlong)puVar13 + 0x14) = 0;
      *(undefined4 *)(puVar13 + 3) = 0xc0016fa0;
      *(undefined4 *)((longlong)puVar13 + 0x1c) = 1;
      *(undefined4 *)(puVar13 + 4) = 0;
      *(undefined4 *)((longlong)puVar13 + 0x24) = 0;
      *(undefined4 *)(puVar13 + 5) = 0;
      *(undefined4 *)((longlong)puVar13 + 0x2c) = 0;
      plVar15 = *(longlong **)(lVar7 + 0x50);
      if (*(int *)(lVar1 + 0x41c) != 0) {
        do {
          uVar8 = (ulonglong)uVar6;
          lVar9 = -1;
          do {
            lVar9 = lVar9 + 1;
          } while (*(short *)(*plVar15 + lVar9 * 2) != 0);
          sVar5 = (short)lVar9 * 2;
          uVar6 = uVar6 + 1;
          *(short *)(puVar13 + uVar8 * 6 + 2) = sVar5;
          *(short *)((longlong)puVar13 + uVar8 * 0x30 + 0x12) = sVar5 + 2;
          lVar9 = *plVar15;
          plVar15 = plVar15 + 1;
          puVar13[uVar8 * 6 + 3] = lVar9;
          puVar13[uVar8 * 6] = FilterDispatchGlobalCreate;
          puVar13[uVar8 * 6 + 1] = uVar8;
          puVar13[uVar8 * 6 + 4] = 0;
          *(undefined4 *)(puVar13 + uVar8 * 6 + 5) = 0;
        } while (uVar6 < *(uint *)(lVar1 + 0x41c));
      }
      *(undefined8 **)(lVar1 + 0x428) = puVar13;
      if (uVar6 == 0) {
        uVar6 = 1;
      }
      KsAllocateDeviceHeader(lVar1,uVar6,puVar13);
      *(undefined1 *)(lVar1 + 800) = *(undefined1 *)(lVar7 + 0x40);
      *(code **)(lVar1 + 0x238) = KeSynchronizeExecution_exref;
      *(code **)(lVar1 + 0x330) = _guard_check_icall;
      *(code **)(lVar1 + 0x340) = SCEndSynchronizedMinidriverDeviceCallin;
      *(code **)(lVar1 + 0x338) = SCEndSynchronizedMinidriverStreamCallin;
      dma64ConstructBuffer(lVar1);
      if (*(char *)(lVar1 + 800) != '\0') {
        *(longlong *)(lVar1 + 0x138) = lVar1;
        *(code **)(lVar1 + 0x238) = StreamClassSynchronizeExecution;
        *(code **)(lVar1 + 0x330) = SCBeginUnsynchronizedMinidriverCallin;
        *(code **)(lVar1 + 0x340) = SCEndUnsynchronizedMinidriverDeviceCallin;
        *(code **)(lVar1 + 0x338) = SCEndUnsynchronizedMinidriverStreamCallin;
      }
      SCReadRegistryValues(lVar1,param_2);
      if ((*(uint *)(lVar1 + 0x130) & 1) == 0) {
        *(uint *)(lVar7 + 0x58) = *(uint *)(lVar7 + 0x58) | 1;
      }
      *(uint *)(local_res20 + 0x30) = *(uint *)(local_res20 + 0x30) & 0xffffff7f;
      *(uint *)(local_res20 + 0x30) = *(uint *)(local_res20 + 0x30) | 0x2000;
      return 0;
    }
  }
  IoDetachDevice(*(undefined8 *)(lVar1 + 0x128));
  IoDeleteDevice(local_res20);
  return (ulonglong)uVar6;
LAB_1c0013d91:
  plVar2 = (longlong *)*plVar15;
  if (plVar2 == plVar15) goto LAB_1c0013dde;
  if (((longlong *)plVar2[1] != plVar15) ||
     (lVar7 = *plVar2, (longlong *)*(longlong *)(lVar7 + 8) != plVar2)) goto LAB_1c0013dd7;
  *plVar15 = lVar7;
  *(longlong **)(lVar7 + 8) = plVar15;
  IoFreeMdl(plVar2[-0x15]);
  ExFreePool(plVar2 + -0x27);
  goto LAB_1c0013d91;
LAB_1c0013dd7:
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  puVar14 = auStack_60;
LAB_1c0013dde:
  uVar3 = *(undefined8 *)(lVar1 + 0x128);
  *(undefined8 *)(puVar14 + -8) = 0x1c0013dec;
  IoDetachDevice(uVar3);
  *(undefined8 *)(puVar14 + -8) = 0x1c0013dfc;
  IoDeleteDevice(local_res20);
  return 0xc000009a;
}



===== StreamClassRegisterAdapter @ 1c0013e30 =====

undefined8 StreamClassRegisterAdapter(longlong param_1,undefined8 param_2,short *param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined8 *local_res8;
  
                    /* 0x13e30  19  StreamClassRegisterAdapter */
  local_res8 = (undefined8 *)0x0;
  if ((*param_3 == 0x58) && ((param_3[1] & 0xfdffU) == 0)) {
    if ((*(longlong *)(param_3 + 8) != 0) && (*(longlong *)(param_3 + 0x10) != 0)) {
      if (*(longlong *)(param_3 + 0xc) == 0) {
        *(code **)(param_3 + 0xc) = SCDummyMinidriverRoutine;
      }
      *(code **)(param_1 + 0x120) = StreamClassPower;
      *(code **)(param_1 + 0x128) = StreamClassForwardUnsupported;
      *(code **)(param_1 + 0x148) = StreamClassPnP;
      *(code **)(param_1 + 0x100) = StreamClassCleanup;
      *(code **)(param_1 + 0x68) = KsNullDriverUnload_exref;
      *(code **)(*(longlong *)(param_1 + 0x30) + 8) = StreamClassPnPAddDevice;
      *(code **)(param_1 + 0xe0) = StreamClassPassThroughIrp;
      *(code **)(param_1 + 0xb8) = StreamClassPassThroughIrp;
      KsSetMajorFunctionHandler(param_1,0);
      KsSetMajorFunctionHandler(param_1,2);
      iVar3 = IoAllocateDriverObjectExtension(param_1,StreamClassPnP,0x80,&local_res8);
      if (iVar3 < 0) {
        SCLogError(param_1,0,0xc006001b,0x1004);
        return 0xc000009a;
      }
      memset(local_res8,0,0x80);
      uVar2 = *(undefined8 *)(param_3 + 4);
      *local_res8 = *(undefined8 *)param_3;
      local_res8[1] = uVar2;
      uVar2 = *(undefined8 *)(param_3 + 0xc);
      local_res8[2] = *(undefined8 *)(param_3 + 8);
      local_res8[3] = uVar2;
      uVar2 = *(undefined8 *)(param_3 + 0x14);
      local_res8[4] = *(undefined8 *)(param_3 + 0x10);
      local_res8[5] = uVar2;
      uVar2 = *(undefined8 *)(param_3 + 0x1c);
      local_res8[6] = *(undefined8 *)(param_3 + 0x18);
      local_res8[7] = uVar2;
      uVar4 = *(undefined4 *)(param_3 + 0x22);
      uVar5 = *(undefined4 *)(param_3 + 0x24);
      uVar1 = *(undefined4 *)(param_3 + 0x26);
      *(undefined4 *)(local_res8 + 8) = *(undefined4 *)(param_3 + 0x20);
      *(undefined4 *)((longlong)local_res8 + 0x44) = uVar4;
      *(undefined4 *)(local_res8 + 9) = uVar5;
      *(undefined4 *)((longlong)local_res8 + 0x4c) = uVar1;
      local_res8[10] = *(undefined8 *)(param_3 + 0x28);
      if (param_3[1] == 0x200) {
        if (*(int *)((longlong)local_res8 + 0x34) == 0) {
          *(undefined4 *)((longlong)local_res8 + 0x34) = 4;
        }
      }
      else {
        *(undefined4 *)(local_res8 + 9) = 0;
        local_res8[10] = 0;
      }
      KeInitializeEvent(local_res8 + 0xc,1,1);
      return 0;
    }
    uVar5 = 0x1003;
    uVar4 = 0xc0060004;
  }
  else {
    uVar5 = 0x1002;
    uVar4 = 0xc0060003;
  }
  SCLogError(param_1,0,uVar4,uVar5);
  return 0xc0000059;
}



===== WppInitKm @ 1c0014030 =====

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



===== WppLoadTracingSupport @ 1c00140c0 =====

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
  MmGetSystemRoutineAddress(&local_18);
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



===== WppTraceCallback @ 1c0014200 =====

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
        memmove((ushort *)((ulonglong)uVar11 + (longlong)param_4) + 1,*(void **)(puVar3 + 4),
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



===== AllocatorDispatchCreate @ 1c0014490 =====

void AllocatorDispatchCreate(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  
  lVar1 = *(longlong *)
           (*(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x40) + 0x18);
  uVar4 = SCShowIoPending(*(longlong *)(param_1 + 0x40),param_2);
  if (-1 < (int)uVar4) {
    lVar2 = *(longlong *)(param_1 + 0x40);
    if (*(char *)(lVar1 + 0x180) == '\0') {
      uVar3 = 0xc0000002;
    }
    else {
      uVar3 = KsCreateDefaultAllocator();
    }
    SCCompleteIrp(param_2,uVar3,lVar2);
  }
  return;
}



===== ClockDispatchClose @ 1c0014510 =====

ulonglong ClockDispatchClose(longlong param_1,undefined8 *param_2)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  char local_res8 [8];
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_res8[0] = '\0';
  lVar2 = *(longlong *)(*(longlong *)(*(longlong *)(param_2[0x17] + 0x30) + 0x18) + 0x10);
  LOCK();
  *(int *)(lVar1 + 0x348) = *(int *)(lVar1 + 0x348) + 1;
  UNLOCK();
  uVar3 = SCSubmitRequest(0xb,0,0,SCCloseClockCallback,lVar1,
                          *(longlong *)(*(longlong *)(lVar2 + 0x128) + 0x30),lVar2 + 0x130,param_2,
                          local_res8,(longlong *)(lVar2 + 0x1a8),*(undefined **)(lVar2 + 0x148));
  if (local_res8[0] == '\0') {
    SCCompleteIrp((longlong)param_2,(int)uVar3,lVar1);
  }
  return uVar3 & 0xffffffff;
}



===== ClockDispatchCreate @ 1c00145d0 =====

ulonglong ClockDispatchCreate(longlong param_1,undefined8 *param_2)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  ulonglong uVar6;
  longlong lVar7;
  undefined4 extraout_var;
  longlong lVar8;
  char cVar9;
  char local_res8 [8];
  undefined8 local_res10;
  
  local_res10 = 0;
  cVar9 = '\0';
  lVar1 = param_2[0x17];
  local_res8[0] = '\0';
  lVar8 = 0;
  uVar6 = SCShowIoPending(*(longlong *)(param_1 + 0x40),(longlong)param_2);
  if ((int)uVar6 < 0) {
    return uVar6;
  }
  uVar3 = KsValidateClockCreateRequest(param_2,&local_res10);
  uVar6 = (ulonglong)uVar3;
  lVar2 = *(longlong *)(*(longlong *)(lVar1 + 0x30) + 0x40);
  if (-1 < (int)uVar3) {
    lVar7 = ExAllocatePoolWithTag(0x200,0x18,0x736c4353);
    if (lVar7 == 0) {
      uVar6 = 0xc000009a;
    }
    else {
      *(longlong *)(lVar7 + 8) = lVar2;
      iVar4 = KsAllocateObjectHeader(lVar7,2,0,param_2,&ClockDispatchTable);
      if (iVar4 < 0) {
        ExFreePool(lVar7);
        uVar5 = SCCompleteIrp((longlong)param_2,iVar4,*(longlong *)(param_1 + 0x40));
        return CONCAT44(extraout_var,uVar5);
      }
      *(longlong *)(*(longlong *)(lVar1 + 0x30) + 0x18) = lVar7;
      *(longlong *)(*(longlong *)(lVar1 + 0x30) + 0x20) = lVar7;
      lVar8 = *(longlong *)(lVar2 + 0x18);
      *(longlong *)(lVar8 + 0x240) = lVar7;
      *(longlong *)(lVar7 + 0x10) = lVar8;
      uVar6 = SCSubmitRequest(6,*(longlong *)(lVar1 + 0x30),0,SCOpenMasterCallback,
                              *(longlong *)(lVar8 + 0x1e8),
                              *(longlong *)(*(longlong *)(lVar8 + 0x128) + 0x30),lVar8 + 0x130,
                              param_2,local_res8,(longlong *)(lVar8 + 0x1a8),
                              *(undefined **)(lVar8 + 0x148));
      uVar6 = uVar6 & 0xffffffff;
      cVar9 = local_res8[0];
    }
    if (cVar9 != '\0') {
      return uVar6;
    }
    if ((lVar8 != 0) && (*(longlong *)(lVar8 + 0x240) != 0)) {
      ExFreePool();
      *(undefined8 *)(lVar8 + 0x240) = 0;
    }
  }
  SCCompleteIrp((longlong)param_2,0xc000009a,*(longlong *)(param_1 + 0x40));
  return uVar6;
}



===== ClockDispatchIoControl @ 1c00147b0 =====

ulonglong ClockDispatchIoControl(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  undefined4 uVar4;
  uint uVar5;
  ulonglong uVar6;
  longlong lVar7;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  lVar3 = *(longlong *)(param_2 + 0xb8);
  uVar6 = SCShowIoPending(lVar2,param_2);
  if ((int)uVar6 < 0) {
    return uVar6;
  }
  iVar1 = *(int *)(lVar3 + 0x18);
  if (iVar1 == 0x2f0003) {
    uVar5 = KsPropertyHandler(param_2,1,&ClockPropertySets);
  }
  else if (iVar1 == 0x2f0007) {
    lVar3 = *(longlong *)(*(longlong *)(*(longlong *)(lVar3 + 0x30) + 0x40) + 0x18);
    uVar5 = KsEnableEvent(param_2,*(undefined4 *)(lVar3 + 0x210),*(undefined8 *)(lVar3 + 0x208),0,0,
                          0);
  }
  else {
    if (iVar1 != 0x2f000b) {
      if (iVar1 == 0x2f000f) {
        uVar6 = 0xc0000010;
      }
      else {
        uVar6 = 0xc00000bb;
      }
      goto LAB_1c00148bc;
    }
    if (*(code **)(lVar2 + 0x238) == KeSynchronizeExecution_exref) {
      lVar7 = *(longlong *)(lVar2 + 0x138);
      uVar4 = 5;
    }
    else {
      uVar4 = 1;
      lVar7 = lVar2 + 0x240;
    }
    uVar5 = KsDisableEvent(param_2,*(longlong *)
                                    (*(longlong *)(*(longlong *)(lVar3 + 0x30) + 0x40) + 0x18) +
                                   0x1d8,uVar4,lVar7);
  }
  uVar6 = (ulonglong)uVar5;
  if (uVar5 == 0x103) {
    return 0x103;
  }
LAB_1c00148bc:
  SCCompleteIrp(param_2,(int)uVar6,lVar2);
  return uVar6;
}



===== DllUnload @ 1c00148f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 DllUnload(void)

{
  undefined *puVar1;
  
                    /* 0x148f0  2  DllUnload */
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
  return 0;
}



===== FilterDispatchClose @ 1c0014980 =====

ulonglong FilterDispatchClose(longlong param_1,undefined8 *param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong *plVar6;
  code *pcVar7;
  undefined1 *puVar8;
  undefined4 uVar9;
  uint uVar10;
  undefined4 extraout_var;
  ulonglong uVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  undefined8 uVar14;
  longlong lVar15;
  char local_res8 [8];
  undefined1 auStackY_88 [8];
  undefined1 auStackY_80 [24];
  
  lVar3 = param_2[0x17];
  uVar10 = 0;
  lVar4 = *(longlong *)(param_1 + 0x40);
  local_res8[0] = '\0';
  plVar5 = *(longlong **)(*(longlong *)(lVar3 + 0x30) + 0x18);
  LOCK();
  *(int *)(lVar4 + 0x348) = *(int *)(lVar4 + 0x348) + 1;
  UNLOCK();
  lVar2 = lVar4 + 0x2f0;
  if (*(int *)(param_2 + 6) != -0x3fffffea) {
    KeWaitForSingleObject(lVar2,0,0,0);
  }
  if ((*(int *)(lVar4 + 0x43c) == 0) && (1 < *(uint *)(lVar4 + 0x2d8))) {
    *(uint *)(lVar4 + 0x2d8) = *(uint *)(lVar4 + 0x2d8) - 1;
    *(undefined8 *)(*(longlong *)(lVar3 + 0x30) + 0x18) = 0;
    if (*(int *)(param_2 + 6) != -0x3fffffea) {
      KeSetEvent(lVar2,0,0);
    }
    ObfDereferenceObject(param_1);
    SCDereferenceDriver(lVar4);
    if (*(int *)(param_2 + 6) == -0x3fffffea) {
      return 0;
    }
    uVar9 = SCCompleteIrp((longlong)param_2,0,lVar4);
    return CONCAT44(extraout_var,uVar9);
  }
  if (*(code **)(lVar4 + 0x238) == KeSynchronizeExecution_exref) {
    lVar15 = *(longlong *)(lVar4 + 0x138);
    uVar14 = 5;
  }
  else {
    uVar14 = 1;
    lVar15 = lVar4 + 0x240;
  }
  KsFreeEventList(*(undefined8 *)(lVar3 + 0x30),plVar5 + 0x10,uVar14,lVar15);
  if (*(int *)(lVar4 + 0x43c) != 0) {
    uVar11 = SCSubmitRequest(0x104,0,0,SCCloseInstanceCallback,lVar4,plVar5[6],0,param_2,local_res8,
                             (longlong *)(lVar4 + 0x260),
                             *(undefined **)(*(longlong *)(lVar4 + 0x210) + 0x10));
    if (local_res8[0] == '\0') {
      KeSetEvent(lVar2,0,0);
      SCCompleteIrp((longlong)param_2,(int)uVar11,lVar4);
    }
    return uVar11 & 0xffffffff;
  }
  *(int *)(lVar4 + 0x2d8) = *(int *)(lVar4 + 0x2d8) + -1;
  *(undefined8 *)(*(longlong *)(lVar3 + 0x30) + 0x18) = 0;
  if (*(longlong **)(lVar4 + 0x2c8) == (longlong *)(lVar4 + 0x2c8)) {
LAB_1c0014b7c:
    puVar12 = auStackY_88;
    puVar13 = auStackY_88;
    puVar8 = auStackY_88;
    if (*(int *)(lVar4 + 0x2d8) == 0) {
      if ((*(uint *)(lVar4 + 0x118) & 0x500) == 0x100) {
        if (*(longlong *)(lVar4 + 0x128) != 0) {
          IoDetachDevice();
          puVar13 = auStackY_88;
          *(undefined8 *)(lVar4 + 0x128) = 0;
        }
        goto LAB_1c0014bd0;
      }
      goto LAB_1c0014bbe;
    }
  }
  else {
    plVar1 = plVar5 + 2;
    lVar2 = *plVar1;
    if ((*(longlong **)(lVar2 + 8) == plVar1) &&
       (plVar6 = (longlong *)plVar5[3], (longlong *)*plVar6 == plVar1)) {
      *plVar6 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar6;
      SciFreeFilterInstance(plVar5);
      goto LAB_1c0014b7c;
    }
    pcVar7 = (code *)swi(0x29);
    (*pcVar7)(3);
    puVar12 = auStackY_80;
LAB_1c0014bbe:
    *(undefined8 *)(puVar12 + -8) = 0x1c0014bc8;
    SCSubmitIdleNotification(lVar4,1);
    puVar8 = puVar12;
  }
  puVar13 = puVar8;
  *(undefined8 *)(puVar13 + -8) = 0x1c0014bd0;
  SCCheckPowerDown(lVar4);
LAB_1c0014bd0:
  if (*(int *)(param_2 + 6) != -0x3fffffea) {
    *(undefined8 *)(puVar13 + -8) = 0x1c0014be9;
    KeSetEvent(lVar4 + 0x2f0,0,0);
  }
  *(undefined8 *)(puVar13 + -8) = 0x1c0014bf6;
  SCDereferenceDriver(lVar4);
  if (*(int *)(param_2 + 6) != -0x3fffffea) {
    *(undefined8 *)(puVar13 + -8) = 0x1c0014c09;
    uVar10 = SCCompleteIrp((longlong)param_2,0,lVar4);
  }
  *(undefined8 *)(puVar13 + -8) = 0x1c0014c15;
  ObfDereferenceObject(param_1);
  return (ulonglong)uVar10;
}



===== FilterDispatchGlobalCreate @ 1c0014c50 =====

ulonglong FilterDispatchGlobalCreate(longlong param_1,undefined8 *param_2)

{
  longlong lVar1;
  longlong lVar2;
  uint *_Src;
  uint uVar3;
  undefined4 uVar4;
  ulonglong uVar5;
  uint *_Dst;
  undefined8 uVar6;
  undefined4 extraout_var;
  int iVar7;
  uint uVar8;
  longlong local_res8 [4];
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  local_res8[0] = 0;
  local_res8[2] = param_2[0x17];
  uVar5 = SCShowIoPending(lVar2,(longlong)param_2);
  if ((int)uVar5 < 0) {
    return uVar5;
  }
  if ((*(uint *)(lVar2 + 0x130) & 0x10) != 0) {
    local_res8[1] = 0xfffffffffff0bdc0;
    iVar7 = 0;
    do {
      if ((*(uint *)(lVar2 + 0x118) & 1) != 0) break;
      KeDelayExecutionThread(0);
      iVar7 = iVar7 + 1;
    } while (iVar7 < 0x32);
    if ((*(uint *)(lVar2 + 0x118) & 1) == 0) {
      *(undefined4 *)(param_2 + 6) = 0xc00000a3;
      IofCompleteRequest(param_2,0);
      return 0xc00000a3;
    }
  }
  SCReferenceDriver(lVar2);
  lVar1 = lVar2 + 0x2f0;
  uVar5 = 0;
  KeWaitForSingleObject(lVar1,0,0,0,0);
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  if ((*(uint *)(lVar2 + 0x130) & 4) != 0) {
    do {
      if (*(int *)(lVar2 + 0x374) == 1) break;
      KeSetEvent(lVar1,0,0);
      KeInitializeEvent(&local_58,0,0);
      uVar6 = 0;
      iVar7 = PoRequestPowerIrp(*(undefined8 *)(lVar2 + 0x218));
      if (iVar7 == 0x103) {
        KeWaitForSingleObject(&local_58);
      }
      uVar5 = 0;
      KeWaitForSingleObject(lVar1,0,0,0,0,uVar6);
    } while (-1 < (int)uStack_40);
  }
  if (*(int *)(lVar2 + 0x2d8) == 0) {
    SCSubmitIdleNotification(lVar2,0);
  }
  uVar5 = SCOpenMinidriverInstance(lVar2,local_res8,uVar5,param_2);
  lVar1 = local_res8[0];
  iVar7 = (int)uVar5;
  if (iVar7 < 0) {
    SCDereferenceDriver(lVar2);
  }
  else {
    if ((*(int *)(lVar2 + 0x2d8) == 0) || (*(int *)(lVar2 + 0x43c) != 0)) {
      *(longlong *)(local_res8[0] + 8) = param_1;
      _Src = *(uint **)((ulonglong)*(uint *)(local_res8[0] + 200) * 0x20 + 0x10 +
                       *(longlong *)(lVar2 + 0x430));
      uVar5 = (ulonglong)*_Src * 0x88;
      if ((uVar5 < 0x100000000) &&
         ((uVar3 = (uint)uVar5, uVar8 = uVar3 + 0x48, uVar3 <= uVar8 &&
          (_Dst = (uint *)ExAllocatePoolWithTag(0x200,uVar8,0x736c4353), _Dst != (uint *)0x0)))) {
        memmove(_Dst,_Src,(ulonglong)uVar8);
        uVar6 = SciOnFilterStreamDescriptor(lVar1,_Dst);
        iVar7 = (int)uVar6;
        if (-1 < iVar7) {
          *(uint **)(lVar1 + 0xc0) = _Dst;
        }
      }
      else {
        iVar7 = -0x3fffff66;
      }
    }
    *(int *)(lVar2 + 0x2d8) = *(int *)(lVar2 + 0x2d8) + 1;
    *(longlong *)(*(longlong *)(local_res8[2] + 0x30) + 0x18) = lVar1;
    ObfReferenceObject(param_1);
    if (-1 < iVar7) goto LAB_1c0014f38;
    *(undefined4 *)(param_2 + 6) = 0xc0000016;
    FilterDispatchClose(param_1,param_2);
  }
  if ((*(int *)(param_2 + 6) != -0x3fffffea) && (*(int *)(lVar2 + 0x2d8) == 0)) {
    SCSubmitIdleNotification(lVar2,1);
  }
LAB_1c0014f38:
  KeSetEvent(lVar2 + 0x2f0,0,0);
  uVar4 = SCCompleteIrp((longlong)param_2,iVar7,lVar2);
  return CONCAT44(extraout_var,uVar4);
}



===== FilterDispatchIoControl @ 1c0014f90 =====

ulonglong FilterDispatchIoControl(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  longlong lVar7;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  lVar3 = *(longlong *)(param_2 + 0xb8);
  uVar5 = SCShowIoPending(lVar2,param_2);
  if ((int)uVar5 < 0) {
    return uVar5;
  }
  iVar1 = *(int *)(lVar3 + 0x18);
  if (iVar1 == 0x2f0003) {
    lVar3 = *(longlong *)(*(longlong *)(lVar3 + 0x30) + 0x18);
    iVar1 = *(int *)(*(longlong *)(lVar3 + 0xc0) + 8);
    if (((iVar1 == 0) ||
        (uVar4 = KsPropertyHandler(param_2,iVar1,*(undefined8 *)(lVar3 + 0x98)), uVar4 == 0xc0000230
        )) || (uVar4 == 0xc0000225)) {
      uVar4 = KsPropertyHandler(param_2,2,&PTR_KSPROPSETID_Pin_1c00173d0);
    }
  }
  else if (iVar1 == 0x2f0007) {
    lVar3 = *(longlong *)(*(longlong *)(lVar3 + 0x30) + 0x18);
    uVar4 = KsEnableEvent(param_2,*(undefined4 *)(lVar3 + 0x78),*(undefined8 *)(lVar3 + 0x70),0,0,0)
    ;
  }
  else {
    if (iVar1 != 0x2f000b) {
      if (iVar1 == 0x2f000f) {
        uVar5 = 0xc0000230;
      }
      else {
        uVar5 = 0xc00000bb;
      }
      goto LAB_1c00150ca;
    }
    if (*(code **)(lVar2 + 0x238) == KeSynchronizeExecution_exref) {
      lVar7 = *(longlong *)(lVar2 + 0x138);
      uVar6 = 5;
    }
    else {
      uVar6 = 1;
      lVar7 = lVar2 + 0x240;
    }
    uVar4 = KsDisableEvent(param_2,*(longlong *)(*(longlong *)(lVar3 + 0x30) + 0x18) + 0x80,uVar6,
                           lVar7);
  }
  uVar5 = (ulonglong)uVar4;
  if (uVar4 == 0x103) {
    return 0x103;
  }
LAB_1c00150ca:
  SCCompleteIrp(param_2,(int)uVar5,lVar2);
  return uVar5;
}



===== FreeFrame @ 1c00150f0 =====

void FreeFrame(undefined8 param_1,undefined8 param_2)

{
  undefined8 local_res10;
  undefined4 local_res18 [4];
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_res18[0] = 0;
  local_18 = 1;
  local_14 = 1;
  local_28 = 0xcf6e4341;
  uStack_24 = 0x11cfec87;
  uStack_20 = 0x200030a1;
  uStack_1c = 0xe456d1af;
  local_res10 = param_2;
  KsSynchronousIoControlDevice(0xcf6e4341,0,0x2f000f,&local_28,0x18,&local_res10,8,local_res18);
  return;
}



===== PrepareTransfer @ 1c0015160 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PrepareTransfer(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  undefined8 uVar2;
  longlong lVar3;
  code *pcVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined4 *_Dst;
  longlong *plVar7;
  undefined1 *puVar8;
  uint uVar9;
  undefined1 auStack_b8 [8];
  undefined1 auStack_b0 [24];
  undefined4 local_98;
  undefined8 *local_90;
  undefined4 local_88;
  undefined4 *local_80;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_b8;
  local_78 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  uStack_28 = 0;
  if (*(longlong *)(param_2 + 0x268) != 0) {
    if (*(int *)(param_2 + 0x25c) == 0) {
      local_80 = &local_78;
      local_60 = 1;
      local_90 = &local_40;
      local_88 = 0x20;
      local_98 = 0x18;
      local_70 = 0xcf6e4342;
      uStack_6c = 0x11cfec87;
      uStack_68 = 0x200030a1;
      uStack_64 = 0xe456d1af;
      local_5c = 1;
      uVar6 = KsSynchronousIoControlDevice(*(longlong *)(param_2 + 0x268),0,0x2f0003,&local_70);
      puVar8 = auStack_b8;
      if ((int)uVar6 < 0) goto LAB_1c00153fa;
      *(undefined4 *)(param_2 + 0x2c0) = (undefined4)local_40;
      *(undefined4 *)(param_2 + 0x2c4) = local_40._4_4_;
      *(undefined4 *)(param_2 + 0x2c8) = (undefined4)uStack_38;
      *(undefined4 *)(param_2 + 0x2cc) = uStack_38._4_4_;
      *(undefined8 *)(param_2 + 0x2d0) = local_30;
      if ((*(int *)(param_2 + 0x260) == 0) && (uVar9 = 0, *(int *)(param_2 + 0x2c8) != 0)) {
        do {
          puVar8 = auStack_b8;
          uVar5 = *(int *)(param_2 + 0x178) + 0x98;
          if ((uVar5 < 0x98) ||
             (_Dst = (undefined4 *)ExAllocatePoolWithTag(0x200,uVar5,0x70644353),
             _Dst == (undefined4 *)0x0)) {
            uVar6 = 0xc000009a;
          }
          else {
            memset(_Dst,0,(ulonglong)uVar5);
            KeInitializeEvent(_Dst + 6,1);
            _Dst[0x18] = *(int *)(param_2 + 0x178) + 0x38;
            if (*(int *)(param_2 + 0x178) != 0) {
              _Dst[0x26] = *(int *)(param_2 + 0x178);
            }
            local_80 = &local_74;
            local_74 = 0;
            local_90 = (undefined8 *)(_Dst + 0x22);
            local_48 = 0;
            local_88 = 8;
            local_98 = 0x18;
            local_58 = 0xcf6e4341;
            uStack_54 = 0x11cfec87;
            uStack_50 = 0x200030a1;
            uStack_4c = 0xe456d1af;
            local_44 = 2;
            uVar5 = KsSynchronousIoControlDevice
                              (*(undefined8 *)(param_2 + 0x268),0,0x2f000f,&local_58);
            *_Dst = 0;
            uVar6 = (ulonglong)uVar5;
            _Dst[1] = uVar9;
            if ((int)uVar5 < 0) {
              ExFreePool(_Dst);
            }
            else {
              uVar2 = *(undefined8 *)(param_2 + 0x120);
              _Dst[0x21] = 0;
              *(undefined8 *)(_Dst + 0x12) = uVar2;
              _Dst[0x20] = *(undefined4 *)(param_2 + 0x2cc);
              plVar1 = *(longlong **)(param_2 + 0x280);
              plVar7 = (longlong *)(_Dst + 0xc);
              if (*plVar1 != param_2 + 0x278) goto LAB_1c00153e2;
              *plVar7 = param_2 + 0x278;
              *(longlong **)(_Dst + 0xe) = plVar1;
              *plVar1 = (longlong)plVar7;
              *(longlong **)(param_2 + 0x280) = plVar7;
            }
          }
          uVar9 = uVar9 + 1;
        } while (uVar9 < *(uint *)(param_2 + 0x2c8));
        if ((int)uVar6 < 0) {
          plVar1 = (longlong *)(param_2 + 0x278);
          while (plVar7 = (longlong *)*plVar1, plVar7 != plVar1) {
            if (((longlong *)plVar7[1] != plVar1) ||
               (lVar3 = *plVar7, (longlong *)*(longlong *)(lVar3 + 8) != plVar7))
            goto LAB_1c00153e2;
            *plVar1 = lVar3;
            *(longlong **)(lVar3 + 8) = plVar1;
            FreeFrame(*(undefined8 *)(param_2 + 0x268),plVar7[0xb]);
            ExFreePool(plVar7 + -6);
          }
          goto LAB_1c00153fa;
        }
      }
    }
    *(undefined4 *)(param_2 + 0x25c) = 2;
  }
  puVar8 = auStack_b8;
  uVar6 = 0;
LAB_1c00153fa:
  *(undefined8 *)(puVar8 + -8) = 0x1c0015406;
  return uVar6;
LAB_1c00153e2:
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  puVar8 = auStack_b0;
  goto LAB_1c00153fa;
}



===== SCClockGetFunctionTable @ 1c0015430 =====

undefined8 SCClockGetFunctionTable(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)
           (*(longlong *)
             (*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x30) + 0x18) + 8) + 0x18)
  ;
  *param_3 = 0;
  param_3[1] = 0;
  param_3[2] = 0;
  param_3[3] = 0;
  if ((*(uint *)(lVar1 + 0x158) & 4) != 0) {
    *param_3 = SCGetStreamTime;
    param_3[2] = SCGetSynchronizedTime;
  }
  if ((*(uint *)(lVar1 + 0x158) & 2) != 0) {
    param_3[1] = SCGetPhysicalTime;
  }
  *(undefined8 *)(param_1 + 0x38) = 0x20;
  return 0;
}



===== SCClockGetPhysicalTime @ 1c00154a0 =====

undefined8 SCClockGetPhysicalTime(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x30) + 0x18);
  if ((*(uint *)(*(longlong *)(*(longlong *)(lVar1 + 8) + 0x18) + 0x158) & 2) == 0) {
    uVar2 = 0xc00000bb;
  }
  else {
    uVar2 = SCGetPhysicalTime(lVar1);
    *param_3 = uVar2;
    uVar2 = 0;
    *(undefined8 *)(param_1 + 0x38) = 8;
  }
  return uVar2;
}



===== SCClockGetSynchronizedTime @ 1c0015500 =====

undefined8 SCClockGetSynchronizedTime(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x30);
  if ((*(uint *)(*(longlong *)(*(longlong *)(*(longlong *)(lVar1 + 0x18) + 8) + 0x18) + 0x158) & 4)
      == 0) {
    uVar2 = 0xc00000bb;
  }
  else {
    uVar2 = SCGetSynchronizedTime(lVar1,param_3 + 1);
    *param_3 = uVar2;
    uVar2 = 0;
    *(undefined8 *)(param_1 + 0x38) = 0x10;
  }
  return uVar2;
}



===== SCClockGetTime @ 1c0015570 =====

undefined8 SCClockGetTime(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x30);
  if ((*(uint *)(*(longlong *)(*(longlong *)(*(longlong *)(lVar1 + 0x18) + 8) + 0x18) + 0x158) & 4)
      == 0) {
    uVar2 = 0xc00000bb;
  }
  else {
    uVar2 = SCGetStreamTime(lVar1);
    *param_3 = uVar2;
    uVar2 = 0;
    *(undefined8 *)(param_1 + 0x38) = 8;
  }
  return uVar2;
}



===== SCCloseClockCallback @ 1c00155d0 =====

int SCCloseClockCallback(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 *puVar4;
  
  iVar1 = *(int *)(param_1 + 8);
  lVar2 = *(longlong *)(param_1 + 0x10);
  lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x48) + 0xb8);
  if (-1 < iVar1) {
    puVar4 = *(undefined8 **)(*(longlong *)(lVar3 + 0x30) + 0x18);
    KsFreeObjectHeader(*puVar4);
    ExFreePool(puVar4);
    *(undefined8 *)(lVar2 + 0x110) = 0;
    ObfDereferenceObject(*(undefined8 *)(*(longlong *)(lVar3 + 0x30) + 0x40));
  }
  SCProcessCompletedRequest(param_1);
  return iVar1;
}



===== SCDataIntersectionCallback @ 1c0015670 =====

undefined4 SCDataIntersectionCallback(longlong param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(param_1 + 0x18);
  uVar1 = *(undefined4 *)(param_1 + 8);
  *(ulonglong *)(*(longlong *)(param_1 + 0x48) + 0x38) = (ulonglong)*(uint *)(param_1 + 0x60);
  KeSetEvent(lVar2 + -0x1e0,0,0);
  SCDequeueAndDeleteSrb(param_1);
  return uVar1;
}



===== SCFilterPinInstances @ 1c00156d0 =====

undefined8 SCFilterPinInstances(longlong param_1,longlong param_2,undefined4 *param_3)

{
  uint uVar1;
  longlong lVar2;
  
  uVar1 = *(uint *)(param_2 + 0x18);
  lVar2 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x30) + 0x18);
  if (uVar1 < *(uint *)(lVar2 + 0x68)) {
    lVar2 = *(longlong *)(lVar2 + 0x38);
    *param_3 = *(undefined4 *)(lVar2 + 4 + (ulonglong)uVar1 * 0xc);
    param_3[1] = *(undefined4 *)(lVar2 + (ulonglong)uVar1 * 0xc);
    *(undefined8 *)(param_1 + 0x38) = 8;
    return 0;
  }
  return 0xc000000d;
}



===== SCFilterPinIntersectionHandler @ 1c0015720 =====

void SCFilterPinIntersectionHandler(void)

{
  KsPinDataIntersection();
  return;
}



===== SCFilterPinPropertyHandler @ 1c0015770 =====

void SCFilterPinPropertyHandler(void)

{
  KsPinPropertyHandler();
  return;
}



===== SCFilterTopologyHandler @ 1c00157b0 =====

void SCFilterTopologyHandler(void)

{
  KsTopologyPropertyHandler();
  return;
}



===== SCGetMasterClock @ 1c00157f0 =====

undefined8 SCGetMasterClock(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  
  uVar2 = 0xc0000001;
  lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x30) + 0x18);
  if ((*(longlong *)(lVar1 + 0x150) != 0) && ((*(uint *)(lVar1 + 0x158) & 4) != 0)) {
    *param_3 = 0;
    uVar2 = 0;
  }
  return uVar2;
}



===== SCGetStreamDeviceState @ 1c0015830 =====

ulonglong SCGetStreamDeviceState(undefined8 *param_1,undefined8 param_2,undefined4 *param_3)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  char local_res8 [8];
  
  local_res8[0] = '\0';
  lVar1 = *(longlong *)(*(longlong *)(param_1[0x17] + 0x28) + 0x40);
  lVar2 = *(longlong *)(*(longlong *)(param_1[0x17] + 0x30) + 0x18);
  param_1[7] = 4;
  uVar3 = SCSubmitRequest(2,(longlong)param_3,0,SCGetStreamDeviceStateCallback,lVar1,
                          *(longlong *)(*(longlong *)(lVar2 + 0x128) + 0x30),lVar2 + 0x130,param_1,
                          local_res8,(longlong *)(lVar2 + 0x1a8),*(undefined **)(lVar2 + 0x148));
  uVar4 = uVar3 & 0xffffffff;
  if (local_res8[0] != '\0') {
    lVar1 = param_1[0xf];
    *param_3 = *(undefined4 *)(lVar1 + 0x28);
    SCDequeueAndDeleteSrb(lVar1);
  }
  if (((int)uVar3 == -0x3fffff45) || ((int)uVar3 == -0x3ffffffe)) {
    uVar4 = 0;
    *param_3 = *(undefined4 *)(lVar2 + 0x254);
  }
  return uVar4;
}



===== SCGetStreamHeaderSize @ 1c0015920 =====

undefined8 SCGetStreamHeaderSize(longlong param_1,undefined8 param_2,undefined4 *param_3)

{
  *param_3 = *(undefined4 *)
              (*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x30) + 0x18) + 0x178);
  *(undefined8 *)(param_1 + 0x38) = 4;
  return 0;
}



===== SCIntersectHandler @ 1c0015950 =====

ulonglong SCIntersectHandler(undefined8 *param_1,longlong param_2,undefined8 param_3,
                            undefined8 param_4)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  char local_res8 [8];
  undefined4 local_28;
  undefined4 local_24;
  undefined8 local_20;
  undefined8 local_18;
  undefined4 local_10;
  
  lVar1 = param_1[0x17];
  local_24 = 0;
  local_res8[0] = '\0';
  lVar2 = *(longlong *)(*(longlong *)(lVar1 + 0x30) + 0x18);
  lVar3 = *(longlong *)(*(longlong *)(lVar1 + 0x28) + 0x40);
  local_10 = *(undefined4 *)(lVar1 + 8);
  local_28 = *(undefined4 *)(param_2 + 0x18);
  local_20 = param_3;
  local_18 = param_4;
  KeWaitForSingleObject(lVar3 + 0x2f0,0,0,0,0);
  uVar4 = SCSubmitRequest(0x10c,(longlong)&local_28,0,SCDataIntersectionCallback,lVar3,
                          *(longlong *)(lVar2 + 0x30),0,param_1,local_res8,
                          (longlong *)(lVar3 + 0x260),
                          *(undefined **)(*(longlong *)(lVar3 + 0x210) + 0x10));
  if (local_res8[0] == '\0') {
    KeSetEvent(lVar3 + 0x2f0,0,0);
  }
  return uVar4 & 0xffffffff;
}



===== SCOpenMasterCallback @ 1c0015a70 =====

void SCOpenMasterCallback(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x10);
  if (*(int *)(param_1 + 8) < 0) {
    ExFreePool(*(undefined8 *)(lVar1 + 0x110));
    *(undefined8 *)(lVar1 + 0x110) = 0;
  }
  else {
    ObfReferenceObject(*(undefined8 *)
                        (*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x48) + 0xb8) + 0x30) +
                        0x40));
  }
  SCProcessCompletedRequest(param_1);
  return;
}



===== SCOpenStreamCallback @ 1c0015ae0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SCOpenStreamCallback(longlong param_1)

{
  undefined8 *puVar1;
  int *piVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 *puVar5;
  longlong lVar6;
  code *pcVar7;
  int iVar8;
  int iVar9;
  undefined8 uVar10;
  longlong lVar11;
  undefined1 auStack_a8 [32];
  undefined8 *local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  char local_50 [32];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_a8;
  lVar3 = *(longlong *)(param_1 + 0x18);
  lVar4 = *(longlong *)(param_1 + 0x10);
  puVar5 = *(undefined8 **)(param_1 + 0x48);
  iVar8 = *(int *)(param_1 + 8);
  puVar1 = (undefined8 *)(lVar4 + -0x130);
  lVar6 = puVar5[0x17];
  if (iVar8 < 0) {
    ExFreePool(puVar1);
    goto LAB_1c0015e4e;
  }
  if (*(longlong *)(lVar4 + 0x10) == 0) {
    *(code **)(lVar4 + 0x10) = SCErrorDataSRB;
  }
  *(undefined8 **)(*(longlong *)(lVar6 + 0x30) + 0x18) = puVar1;
  *(undefined8 *)(*(longlong *)(lVar6 + 0x30) + 0x20) = 0;
  KeInitializeEvent(lVar4 + 0xe8,1,1);
  KeInitializeSpinLock(lVar4 + 0x100);
  KeInitializeTimer(lVar4 + -0xb8);
  KeInitializeDpc(lVar4 + -0x78,SCMinidriverStreamTimerDpc,puVar1);
  lVar11 = lVar4 + 0x68;
  *(longlong *)(lVar4 + 0x70) = lVar11;
  *(longlong *)lVar11 = lVar11;
  lVar11 = lVar4 + 0x78;
  *(longlong *)(lVar4 + 0x80) = lVar11;
  *(longlong *)lVar11 = lVar11;
  lVar11 = lVar4 + 0x98;
  *(longlong *)(lVar4 + 0xa0) = lVar11;
  *(longlong *)lVar11 = lVar11;
  if (*(longlong *)(lVar4 + 0x18) == 0) {
    iVar8 = -0x3fffff3e;
  }
  else {
    lVar11 = lVar4 + 0x148;
    *(longlong *)(lVar4 + 0x150) = lVar11;
    *(longlong *)lVar11 = lVar11;
    KeInitializeSpinLock(lVar4 + 0x158);
    lVar11 = lVar4 + 0x1b8;
    *(longlong *)(lVar4 + 0x1c0) = lVar11;
    *(longlong *)lVar11 = lVar11;
    KeInitializeSpinLock(lVar4 + 0x1b0);
    lVar11 = lVar4 + 0x1f8;
    *(longlong *)(lVar4 + 0x200) = lVar11;
    *(longlong *)lVar11 = lVar11;
    KeInitializeSpinLock(lVar4 + 0x1f0);
    *(undefined4 *)(lVar4 + 0x180) = *(undefined4 *)(lVar4 + 4);
    *(undefined4 *)(lVar4 + 0x130) = 1;
    pcVar7 = IoFileObjectType_exref;
    if (*(longlong *)(lVar4 + 0x188) != 0) {
      local_88 = &local_78;
      *(undefined4 *)(lVar4 + 0x130) = 0;
      *(undefined8 *)(lVar4 + 0x140) = 0;
      local_80 = 0;
      local_78 = 0;
      iVar8 = ObReferenceObjectByHandle
                        (*(longlong *)(lVar4 + 0x188),0x100003,*(undefined8 *)pcVar7,0);
      if (iVar8 < 0) goto LAB_1c0015bec;
      *(undefined8 *)(lVar4 + 0x140) = local_78;
      uVar10 = IoGetRelatedDeviceObject();
      KsSetTargetDeviceObject(*puVar1,uVar10);
    }
    uVar10 = dma64InitBuffer(lVar3 + -0x4d0,*(char *)(lVar4 + 0x38));
    iVar8 = (int)uVar10;
    if (-1 < iVar8) {
      lVar11 = *(longlong *)(lVar3 + -0x1e8) + 0x48;
      if (*(uint *)(lVar4 + 4) != 0) {
        lVar11 = lVar11 + (ulonglong)*(uint *)(lVar4 + 4) * 0x88;
      }
      if (*(char *)(lVar11 + 8) != '\0') {
        *(undefined1 *)(lVar4 + 0x129) = 1;
      }
      *(undefined1 *)(lVar4 + 0x128) = 1;
      SCInsertStreamInFilter((longlong)puVar1,lVar3 + -0x4d0);
      ObfReferenceObject(*(undefined8 *)(*(longlong *)(lVar6 + 0x30) + 0x40));
      uVar10 = *(undefined8 *)(lVar6 + 0x30);
      local_78 = 0;
      local_60 = 0;
      uStack_58 = 0;
      local_70 = 0;
      uStack_68 = 0;
      iVar9 = IoOpenDeviceRegistryKey(*(undefined8 *)(lVar3 + -0x2b8),2,0x1f0000,&local_78);
      if (-1 < iVar9) {
        RtlStringCbPrintfA(local_50,0x20,"Pin%d\\Properties",(ulonglong)*(uint *)(lVar4 + 4));
        RtlInitAnsiString(&local_60,local_50);
        iVar9 = RtlAnsiStringToUnicodeString(&local_70,&local_60,1);
        if (-1 < iVar9) {
          KsUnserializeObjectPropertiesFromRegistry(uVar10,local_78,&local_70);
          RtlFreeUnicodeString(&local_70);
        }
        ZwClose(local_78);
      }
      piVar2 = (int *)(*(longlong *)
                        (*(longlong *)(*(longlong *)(*(longlong *)(lVar6 + 0x30) + 0x40) + 0x18) +
                        0x38) + (ulonglong)*(uint *)(lVar4 + 4) * 0xc);
      *piVar2 = *piVar2 + 1;
      goto LAB_1c0015e4e;
    }
  }
LAB_1c0015bec:
  *(undefined4 *)(puVar5 + 6) = 0xc0000016;
  StreamDispatchClose(*(longlong *)(lVar3 + -0x3b0),puVar5);
  *(int *)(param_1 + 8) = iVar8;
LAB_1c0015e4e:
  KeSetEvent(lVar3 + -0x1e0,0,0);
  SCProcessCompletedRequest(param_1);
  return iVar8;
}



===== SCSetMasterClock @ 1c0015eb0 =====

ulonglong SCSetMasterClock(undefined8 *param_1,undefined8 param_2,longlong *param_3)

{
  longlong lVar1;
  undefined1 uVar2;
  uint uVar3;
  longlong *plVar4;
  ulonglong uVar5;
  longlong lVar6;
  longlong *plVar7;
  ulonglong uVar8;
  undefined1 local_res8 [16];
  undefined4 local_res18 [2];
  longlong local_res20;
  undefined8 in_stack_ffffffffffffff78;
  undefined4 uVar9;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  
  uVar9 = (undefined4)((ulonglong)in_stack_ffffffffffffff78 >> 0x20);
  local_res18[0] = 0;
  local_res20 = 0;
  local_48 = 0;
  plVar4 = (longlong *)0x0;
  local_58 = 0;
  uStack_50 = 0;
  lVar1 = *(longlong *)(*(longlong *)(param_1[0x17] + 0x30) + 0x18);
  KeWaitForSingleObject(lVar1 + 0x218,0,0,0,0);
  plVar7 = *(longlong **)(lVar1 + 0x238);
  if (*param_3 == 0) {
LAB_1c001600d:
    uVar5 = SCSubmitRequest(7,local_res20,0,SCDequeueAndDeleteSrb,*(longlong *)(lVar1 + 0x1e8),
                            *(longlong *)(*(longlong *)(lVar1 + 0x128) + 0x30),lVar1 + 0x130,param_1
                            ,local_res8,(longlong *)(lVar1 + 0x1a8),*(undefined **)(lVar1 + 0x148));
    uVar8 = uVar5 & 0xffffffff;
    if ((int)uVar5 < 0) {
      SciSetMasterClockInfo(lVar1,plVar7);
      if (plVar4 == (longlong *)0x0) goto LAB_1c00160c8;
      lVar6 = local_res20;
LAB_1c00160ad:
      ObfDereferenceObject(lVar6);
      goto LAB_1c00160b9;
    }
    SciSetMasterClockInfo(lVar1,plVar4);
    if (plVar7 == (longlong *)0x0) goto LAB_1c00160c8;
    ObfDereferenceObject(*plVar7);
  }
  else {
    plVar4 = (longlong *)ExAllocatePoolWithTag(0x200,0x28,0x736c4353);
    if (plVar4 == (longlong *)0x0) {
      uVar8 = 0xc000009a;
      goto LAB_1c00160c8;
    }
    uVar2 = ExGetPreviousMode();
    uVar3 = ObReferenceObjectByHandle
                      (*param_3,0x100001,*(undefined8 *)IoFileObjectType_exref,uVar2,&local_res20,0)
    ;
    uVar8 = (ulonglong)uVar3;
    if (-1 < (int)uVar3) {
      *plVar4 = local_res20;
      local_58 = 0x11cfac17df12a4c0;
      uStack_50 = 0xc104db28d6a5;
      local_48 = 0x100000006;
      uVar3 = KsSynchronousIoControlDevice
                        (local_res20,0,0x2f0003,&local_58,0x18,plVar4 + 1,CONCAT44(uVar9,0x20),
                         local_res18);
      uVar8 = (ulonglong)uVar3;
      if (-1 < (int)uVar3) {
        SciSetMasterClockInfo(lVar1,plVar4);
        goto LAB_1c001600d;
      }
      lVar6 = *plVar4;
      goto LAB_1c00160ad;
    }
LAB_1c00160b9:
    plVar7 = plVar4;
  }
  ExFreePool(plVar7);
LAB_1c00160c8:
  KeSetEvent(lVar1 + 0x218,0,0);
  return uVar8;
}



===== SCStreamAllocator @ 1c0016100 =====

undefined4 SCStreamAllocator(longlong param_1,longlong param_2,longlong *param_3)

{
  longlong lVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  longlong lVar4;
  longlong *plVar5;
  
  uVar3 = 0;
  lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x30) + 0x18);
  if ((*(uint *)(param_2 + 0x14) & 1) == 0) {
    lVar4 = *(longlong *)(lVar1 + 0x1e8) + 0x2f0;
    KeWaitForSingleObject(lVar4,0,0,0,0);
    if (*(int *)(lVar1 + 0x254) != 0) {
      KeSetEvent(lVar4,0,0);
      return 0xc0000184;
    }
    plVar5 = (longlong *)(lVar1 + 0x268);
    if (*plVar5 != 0) {
      ObfDereferenceObject();
      *plVar5 = 0;
    }
    uVar3 = 0;
    if (*param_3 != 0) {
      uVar2 = ExGetPreviousMode();
      uVar3 = ObReferenceObjectByHandle
                        (*param_3,0x100001,*(undefined8 *)IoFileObjectType_exref,uVar2,plVar5,0);
    }
    KeSetEvent(lVar4,0,0);
  }
  else {
    *param_3 = 0;
  }
  return uVar3;
}



===== SCStreamDeviceRate @ 1c0016220 =====

ulonglong SCStreamDeviceRate(undefined8 *param_1,undefined8 param_2,longlong param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined1 local_res8 [32];
  
  lVar1 = *(longlong *)(*(longlong *)(param_1[0x17] + 0x30) + 0x18);
  uVar2 = SCSubmitRequest(9,param_3,0,SCDequeueAndDeleteSrb,
                          *(longlong *)(*(longlong *)(param_1[0x17] + 0x28) + 0x40),
                          *(longlong *)(*(longlong *)(lVar1 + 0x128) + 0x30),lVar1 + 0x130,param_1,
                          local_res8,(longlong *)(lVar1 + 0x1a8),*(undefined **)(lVar1 + 0x148));
  uVar3 = uVar2 & 0xffffffff;
  if ((int)uVar2 == -0x3ffffffe) {
    uVar3 = 0xc0000225;
  }
  return uVar3;
}



===== SCStreamDeviceRateCapability @ 1c00162c0 =====

ulonglong SCStreamDeviceRateCapability(undefined8 *param_1,longlong param_2,undefined8 *param_3)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined1 local_res8 [32];
  
  uVar3 = *(undefined8 *)(param_2 + 0x20);
  lVar1 = *(longlong *)(*(longlong *)(param_1[0x17] + 0x28) + 0x40);
  lVar2 = *(longlong *)(*(longlong *)(param_1[0x17] + 0x30) + 0x18);
  *param_3 = *(undefined8 *)(param_2 + 0x18);
  param_3[1] = uVar3;
  uVar3 = *(undefined8 *)(param_2 + 0x30);
  param_3[2] = *(undefined8 *)(param_2 + 0x28);
  param_3[3] = uVar3;
  uVar3 = *(undefined8 *)(param_2 + 0x40);
  param_3[4] = *(undefined8 *)(param_2 + 0x38);
  param_3[5] = uVar3;
  *(undefined4 *)(param_3 + 5) = 1000;
  param_1[7] = 0x30;
  uVar4 = SCSubmitRequest(0xc,param_2,0,SCDequeueAndDeleteSrb,lVar1,
                          *(longlong *)(*(longlong *)(lVar2 + 0x128) + 0x30),lVar2 + 0x130,param_1,
                          local_res8,(longlong *)(lVar2 + 0x1a8),*(undefined **)(lVar2 + 0x148));
  uVar5 = uVar4 & 0xffffffff;
  if ((int)uVar4 == -0x3ffffffe) {
    uVar5 = 0xc0000225;
  }
  return uVar5;
}



===== SCStreamDeviceState @ 1c0016390 =====

int SCStreamDeviceState(undefined8 *param_1,undefined8 param_2,int *param_3)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  undefined1 local_res8 [8];
  
  iVar4 = 0;
  lVar2 = *(longlong *)(*(longlong *)(param_1[0x17] + 0x28) + 0x40);
  lVar3 = *(longlong *)(*(longlong *)(param_1[0x17] + 0x30) + 0x18);
  KeWaitForSingleObject(lVar2 + 0x2f0,0,0,0,0);
  if (*(int *)(lVar3 + 0x254) != *param_3) {
    uVar5 = SCSubmitRequest(3,(longlong)*param_3,0,SCDequeueAndDeleteSrb,lVar2,
                            *(longlong *)(*(longlong *)(lVar3 + 0x128) + 0x30),lVar3 + 0x130,param_1
                            ,local_res8,(longlong *)(lVar3 + 0x1a8),*(undefined **)(lVar3 + 0x148));
    iVar4 = (int)uVar5;
    if (-1 < iVar4) {
      *(int *)(lVar3 + 0x254) = *param_3;
    }
    iVar1 = *param_3;
    if (iVar1 == 0) {
      if ((*(int *)(lVar3 + 0x260) == 0) && (*(char *)(lVar3 + 0x36c) != '\0')) {
        uVar5 = EndTransfer(0,lVar3);
        iVar4 = (int)uVar5;
      }
      else {
        StreamFlushIo(lVar2,lVar3);
      }
    }
    else if (iVar1 == 1) {
      iVar4 = 0;
    }
    else if (iVar1 == 2) {
      if (((-1 < iVar4) && (*(int *)(lVar3 + 0x260) == 0)) && (*(char *)(lVar3 + 0x36c) != '\0')) {
        uVar6 = PrepareTransfer(0,lVar3);
        iVar4 = (int)uVar6;
      }
    }
    else if (((iVar1 == 3) && (*(int *)(lVar3 + 0x260) == 0)) && (*(char *)(lVar3 + 0x36c) != '\0'))
    {
      uVar6 = BeginTransfer(1,lVar3);
      iVar4 = (int)uVar6;
    }
  }
  KeSetEvent(lVar2 + 0x2f0,0,0);
  return iVar4;
}



===== SCStreamProposeNewFormat @ 1c0016520 =====

ulonglong SCStreamProposeNewFormat(undefined8 *param_1,undefined8 param_2,longlong param_3)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined1 local_res8 [32];
  
  lVar1 = param_1[0x17];
  lVar2 = *(longlong *)(*(longlong *)(lVar1 + 0x30) + 0x18);
  uVar3 = SCSubmitRequest(10,param_3,*(undefined4 *)(lVar1 + 8),SCDequeueAndDeleteSrb,
                          *(longlong *)(*(longlong *)(lVar1 + 0x28) + 0x40),
                          *(longlong *)(*(longlong *)(lVar2 + 0x128) + 0x30),lVar2 + 0x130,param_1,
                          local_res8,(longlong *)(lVar2 + 0x1a8),*(undefined **)(lVar2 + 0x148));
  uVar4 = uVar3 & 0xffffffff;
  if ((int)uVar3 == -0x3ffffffe) {
    uVar4 = 0xc0000225;
  }
  return uVar4;
}



===== SCStreamSetFormat @ 1c00165c0 =====

ulonglong SCStreamSetFormat(undefined8 *param_1,undefined8 param_2,longlong param_3)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined1 local_res8 [32];
  
  lVar1 = param_1[0x17];
  lVar2 = *(longlong *)(*(longlong *)(lVar1 + 0x30) + 0x18);
  uVar3 = SCSubmitRequest(0xd,param_3,*(undefined4 *)(lVar1 + 8),SCDequeueAndDeleteSrb,
                          *(longlong *)(*(longlong *)(lVar1 + 0x28) + 0x40),
                          *(longlong *)(*(longlong *)(lVar2 + 0x128) + 0x30),lVar2 + 0x130,param_1,
                          local_res8,(longlong *)(lVar2 + 0x1a8),*(undefined **)(lVar2 + 0x148));
  uVar4 = uVar3 & 0xffffffff;
  if ((int)uVar3 == -0x3ffffffe) {
    uVar4 = 0xc0000225;
  }
  return uVar4;
}



===== StreamClassMinidriverDeviceGetProperty @ 1c0016660 =====

void StreamClassMinidriverDeviceGetProperty
               (undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  SCMinidriverDevicePropertyHandler(0x105,param_1,param_2,param_3);
  return;
}



===== StreamClassMinidriverDeviceSetProperty @ 1c0016690 =====

void StreamClassMinidriverDeviceSetProperty
               (undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  SCMinidriverDevicePropertyHandler(0x106,param_1,param_2,param_3);
  return;
}



===== StreamClassMinidriverStreamGetProperty @ 1c00166c0 =====

void StreamClassMinidriverStreamGetProperty
               (undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  SCMinidriverStreamPropertyHandler(5,param_1,param_2,param_3);
  return;
}



===== StreamClassMinidriverStreamSetProperty @ 1c00166f0 =====

void StreamClassMinidriverStreamSetProperty
               (undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  SCMinidriverStreamPropertyHandler(4,param_1,param_2,param_3);
  return;
}



===== StreamDispatchClose @ 1c0016720 =====

ulonglong StreamDispatchClose(longlong param_1,undefined8 *param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  longlong lVar6;
  char local_res8 [8];
  
  lVar1 = param_2[0x17];
  lVar2 = *(longlong *)(param_1 + 0x40);
  uVar5 = 1;
  local_res8[0] = '\0';
  lVar3 = *(longlong *)(*(longlong *)(lVar1 + 0x30) + 0x18);
  LOCK();
  *(int *)(lVar2 + 0x348) = *(int *)(lVar2 + 0x348) + 1;
  UNLOCK();
  if (*(code **)(lVar2 + 0x238) == KeSynchronizeExecution_exref) {
    lVar6 = *(longlong *)(lVar2 + 0x138);
    uVar5 = 5;
  }
  else {
    lVar6 = lVar2 + 0x240;
  }
  KsFreeEventList(*(undefined8 *)(lVar1 + 0x30),lVar3 + 0x1d8,uVar5,lVar6);
  if (*(int *)(param_2 + 6) != -0x3fffffea) {
    KeWaitForSingleObject(lVar2 + 0x2f0,0,0,0,0);
  }
  uVar4 = SCSubmitRequest(0x102,0,0,SCCloseStreamCallback,lVar2,
                          *(longlong *)(*(longlong *)(lVar3 + 0x128) + 0x30),lVar3 + 0x130,param_2,
                          local_res8,(longlong *)(lVar2 + 0x260),
                          *(undefined **)(*(longlong *)(lVar2 + 0x210) + 0x10));
  if ((local_res8[0] == '\0') && (*(int *)(param_2 + 6) != -0x3fffffea)) {
    KeSetEvent(lVar2 + 0x2f0,0,0);
    SCCompleteIrp((longlong)param_2,(int)uVar4,lVar2);
  }
  return uVar4 & 0xffffffff;
}



===== StreamDispatchCreate @ 1c0016880 =====

void StreamDispatchCreate(longlong param_1,undefined8 *param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  undefined8 uVar5;
  void *_Dst;
  uint uVar6;
  longlong lVar7;
  longlong lVar8;
  undefined1 uVar9;
  char local_res8 [8];
  longlong *local_res10;
  longlong local_res18;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  lVar8 = param_2[0x17];
  local_res10 = (longlong *)0x0;
  local_res8[0] = '\0';
  uVar5 = SCShowIoPending(lVar2,(longlong)param_2);
  if ((int)uVar5 < 0) {
    return;
  }
  local_res18 = *(longlong *)(*(longlong *)(lVar8 + 0x30) + 0x40);
  lVar3 = *(longlong *)(local_res18 + 0x18);
  lVar7 = *(longlong *)(lVar3 + 0x38);
  iVar4 = KsValidateConnectRequest
                    (param_2,*(undefined4 *)(lVar3 + 0x68),*(undefined8 *)(lVar3 + 0x60),
                     &local_res10);
  if (-1 < iVar4) {
    lVar1 = lVar2 + 0x2f0;
    KeWaitForSingleObject(lVar1,0,0,0,0);
    if (*(int *)(lVar7 + (ulonglong)*(uint *)(local_res10 + 6) * 0xc) ==
        *(int *)(lVar7 + 4 + (ulonglong)*(uint *)(local_res10 + 6) * 0xc)) {
      KeSetEvent(lVar1,0,0);
      iVar4 = -0x3ffffee1;
    }
    else {
      uVar6 = *(int *)(*(longlong *)(lVar2 + 0x210) + 0x30) + 0x378;
      if ((uVar6 < 0x378) ||
         (_Dst = (void *)ExAllocatePoolWithTag(0x200,uVar6,0x736c4353), _Dst == (void *)0x0)) {
        KeSetEvent(lVar1,0,0);
        iVar4 = -0x3fffff66;
      }
      else {
        memset(_Dst,0,(ulonglong)uVar6);
        *(undefined4 *)((longlong)_Dst + 0x254) = 0;
        *(undefined4 *)((longlong)_Dst + 8) = 0xd73afe3f;
        iVar4 = KsAllocateObjectHeader
                          (_Dst,2,&PTR_ClockDispatchCreate_1c0017470,param_2,&StreamDispatchTable);
        if (iVar4 < 0) {
          KeSetEvent(lVar1,0);
          ExFreePool(_Dst);
        }
        else {
          uVar9 = 1;
          *(int *)((longlong)_Dst + 0x134) = (int)local_res10[6];
          *(longlong *)((longlong)_Dst + 0x118) = local_res18;
          *(undefined8 *)((longlong)_Dst + 0x120) = *(undefined8 *)(lVar8 + 0x30);
          *(longlong *)((longlong)_Dst + 0x128) = lVar3;
          *(longlong *)((longlong)_Dst + 0x1e8) = lVar2;
          *(undefined4 *)((longlong)_Dst + 0x370) = 1;
          *(longlong *)((longlong)_Dst + 0x2b8) = local_res10[7];
          KeInitializeEvent((longlong)_Dst + 0x290,1,0);
          if ((((local_res10[3] != 0x11cf62ce4747b320) || (local_res10[4] != 0xc104db28d6a5)) ||
              (*local_res10 != 0x11cf62ce1a8766a0)) || (local_res10[1] != 0xc104db28d6a5)) {
            uVar9 = 0;
          }
          *(undefined1 *)((longlong)_Dst + 0x36c) = uVar9;
          *(undefined4 *)((longlong)_Dst + 0x130) = 0x68;
          *(undefined8 *)((longlong)_Dst + 0x170) = *(undefined8 *)(lVar2 + 0x220);
          *(longlong *)((longlong)_Dst + 0x138) = (longlong)_Dst + 0x378;
          lVar8 = *(longlong *)(lVar3 + 0xc0);
          if (lVar8 == 0) {
            lVar8 = *(longlong *)(lVar2 + 0x2e8);
          }
          lVar7 = (ulonglong)*(uint *)(local_res10 + 6) * 0x88;
          *(undefined8 *)((longlong)_Dst + 0x1f8) =
               *(undefined8 *)
                (*(longlong *)(lVar3 + 0xa0) + (ulonglong)*(uint *)(local_res10 + 6) * 0x10);
          *(undefined4 *)((longlong)_Dst + 0x200) = *(undefined4 *)(lVar7 + 0x80 + lVar8);
          *(undefined8 *)((longlong)_Dst + 0x208) =
               *(undefined8 *)
                (*(longlong *)(lVar3 + 0xa0) + 8 + (ulonglong)*(uint *)(local_res10 + 6) * 0x10);
          *(undefined4 *)((longlong)_Dst + 0x210) = *(undefined4 *)(lVar7 + 0x90 + lVar8);
          lVar8 = (longlong)_Dst + 0x1d8;
          *(longlong *)((longlong)_Dst + 0x1e0) = lVar8;
          *(longlong *)lVar8 = lVar8;
          uVar5 = SCSubmitRequest(0x101,(longlong)(local_res10 + 9),0,SCOpenStreamCallback,lVar2,
                                  *(longlong *)(lVar3 + 0x30),(longlong)_Dst + 0x130,param_2,
                                  local_res8,(longlong *)(lVar2 + 0x260),
                                  *(undefined **)(*(longlong *)(lVar2 + 0x210) + 0x10));
          iVar4 = (int)uVar5;
          if (local_res8[0] != '\0') {
            return;
          }
          KsFreeObjectHeader(_Dst);
          ExFreePool(_Dst);
          KeSetEvent(lVar1,0,0);
        }
      }
    }
  }
  SCCompleteIrp((longlong)param_2,iVar4,lVar2);
  return;
}



===== StreamDispatchIoControl @ 1c0016c40 =====

int StreamDispatchIoControl(longlong param_1,undefined8 *param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  int *piVar4;
  int iVar5;
  undefined8 uVar6;
  longlong lVar7;
  undefined8 *local_res10;
  ulonglong in_stack_ffffffffffffff98;
  
  lVar7 = param_2[0x17];
  lVar2 = *(longlong *)(*(longlong *)(lVar7 + 0x30) + 0x18);
  lVar3 = *(longlong *)(param_1 + 0x40);
  iVar5 = -0x3ffffff0;
  local_res10 = param_2;
  if ((*(uint *)(lVar3 + 0x118) & 0x100) != 0) {
    uVar6 = SCSetMasterClockWhenDeviceInaccessible(param_1,(longlong)param_2);
    iVar5 = -0x3ffffff0;
    if (-1 < (int)uVar6) {
      iVar5 = (int)uVar6;
    }
    *(int *)(param_2 + 6) = iVar5;
    IofCompleteRequest(param_2,0);
    return iVar5;
  }
  uVar6 = 1;
  LOCK();
  *(int *)(lVar3 + 0x348) = *(int *)(lVar3 + 0x348) + 1;
  UNLOCK();
  iVar1 = *(int *)(lVar7 + 0x18);
  if (iVar1 == 0x2f0003) {
    iVar5 = -0x3ffffdd0;
    if (*(int *)(lVar2 + 0x200) != 0) {
      iVar5 = KsPropertyHandler(param_2,*(int *)(lVar2 + 0x200),*(undefined8 *)(lVar2 + 0x1f8));
    }
    if (((iVar5 == -0x3ffffdd0) || (iVar5 == -0x3ffffddb)) && (*(longlong *)(lVar2 + 0x248) != 0)) {
      iVar5 = KsPropertyHandler(param_2,*(undefined4 *)(lVar2 + 0x250));
    }
    if ((iVar5 == -0x3ffffdd0) || (iVar5 == -0x3ffffddb)) {
      iVar5 = KsPropertyHandler(param_2,3,&PTR_KSPROPSETID_Connection_1c00174d0);
    }
  }
  else if (iVar1 == 0x2f0007) {
    iVar5 = KsEnableEvent(param_2,*(undefined4 *)(lVar2 + 0x210),*(undefined8 *)(lVar2 + 0x208),0,
                          in_stack_ffffffffffffff98 & 0xffffffff00000000,0);
  }
  else if (iVar1 == 0x2f000b) {
    if (*(code **)(lVar3 + 0x238) == KeSynchronizeExecution_exref) {
      uVar6 = 5;
      lVar7 = *(longlong *)(lVar3 + 0x138);
    }
    else {
      lVar7 = lVar3 + 0x240;
    }
    iVar5 = KsDisableEvent(param_2,lVar2 + 0x1d8,uVar6,lVar7);
  }
  else if (iVar1 == 0x2f000f) {
    iVar5 = -0x3ffffdd0;
    if (*(longlong *)(lVar2 + 0x360) != 0) {
      iVar5 = KsMethodHandler(param_2,*(undefined4 *)(lVar2 + 0x368));
    }
  }
  else if (iVar1 == 0x2f001b) {
    piVar4 = *(int **)(lVar7 + 0x20);
    if (*(char *)(param_2 + 8) == '\0') {
      iVar5 = *piVar4;
    }
    else {
      ProbeForRead(piVar4,4,4);
      iVar5 = *piVar4;
    }
    if (iVar5 == 0) {
      *(undefined1 *)(lVar2 + 0x25b) = 1;
      uVar6 = SCSubmitRequest(0xf,0,0,SCDequeueAndDeleteSrb,lVar3,
                              *(longlong *)(*(longlong *)(lVar2 + 0x128) + 0x30),lVar2 + 0x130,
                              param_2,(undefined1 *)&local_res10,(longlong *)(lVar2 + 0x1a8),
                              *(undefined **)(lVar2 + 0x148));
      iVar5 = (int)uVar6;
      StreamFlushIo(lVar3,lVar2);
    }
    else {
      uVar6 = SCSubmitRequest(0x10,0,0,SCDequeueAndDeleteSrb,lVar3,
                              *(longlong *)(*(longlong *)(lVar2 + 0x128) + 0x30),lVar2 + 0x130,
                              param_2,(undefined1 *)&local_res10,(longlong *)(lVar2 + 0x1a8),
                              *(undefined **)(lVar2 + 0x148));
      iVar5 = (int)uVar6;
      *(undefined1 *)(lVar2 + 0x25b) = 0;
    }
  }
  else {
    if (iVar1 == 0x2f4017) {
      iVar5 = 0;
    }
    else {
      if (iVar1 != 0x2f8013) goto LAB_1c0016f1e;
      iVar5 = 1;
    }
    uVar6 = SCProcessDataTransfer(lVar3,param_2,iVar5);
    iVar5 = (int)uVar6;
  }
LAB_1c0016f1e:
  if (iVar5 != 0x103) {
    SCCompleteIrp((longlong)param_2,iVar5,lVar3);
  }
  return iVar5;
}



===== entry @ 1c0019010 =====

void entry(void)

{
  __security_init_cookie();
  DriverEntry();
  return;
}



===== __security_init_cookie @ 1c0019044 =====

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



===== DriverEntry @ 1c0019078 =====

undefined8 DriverEntry(void)

{
  return 0;
}


