
===== CiSchedulerRemoveThread @ 140001010 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CiSchedulerRemoveThread(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong lVar4;
  code *pcVar5;
  
  KeAcquireSpinLockRaiseToDpc(&CiSchedulerLock);
  _DAT_1400091c8 = SystemReserved1[0xf];
  if (DAT_1400090d0 != '\0') {
    CiLogThreadBuffering(param_1,0);
  }
  KeUpdateThreadTag(*(undefined8 *)(param_1 + 0x60),0);
  plVar1 = *(longlong **)(param_1 + 0x50);
  lVar2 = *(longlong *)(param_1 + 0x48);
  plVar3 = *(longlong **)(param_1 + 0x58);
  if ((plVar1[1] != param_1 + 0x50) || (*plVar3 != param_1 + 0x50)) {
LAB_1400010d2:
    pcVar5 = (code *)swi(0x29);
    (*pcVar5)(3);
    pcVar5 = (code *)swi(3);
    (*pcVar5)();
    return;
  }
  *plVar3 = (longlong)plVar1;
  plVar1[1] = (longlong)plVar3;
  if (plVar3 == plVar1) {
    lVar4 = *(longlong *)(lVar2 + 0x10);
    if ((*(longlong *)(lVar4 + 8) != lVar2 + 0x10) ||
       (plVar1 = *(longlong **)(lVar2 + 0x18), *plVar1 != lVar2 + 0x10)) goto LAB_1400010d2;
    *plVar1 = lVar4;
    *(longlong **)(lVar4 + 8) = plVar1;
  }
  _DAT_1400091c8 = (void *)0x0;
  KeReleaseSpinLock(&CiSchedulerLock,0);
  return;
}



===== CiLogThreadBuffering @ 1400010e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CiLogThreadBuffering(longlong param_1,int param_2)

{
  undefined *puVar1;
  undefined1 auStack_58 [32];
  undefined8 **local_38;
  undefined8 local_28;
  undefined8 *local_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  local_28 = PsGetThreadId(*(undefined8 *)(param_1 + 0x60));
  puVar1 = &CiThreadBufferingStartEvent;
  local_20 = &local_28;
  local_18 = 4;
  if (param_2 == 0) {
    puVar1 = &CiThreadBufferingStopEvent;
  }
  local_38 = &local_20;
  EtwWrite(DAT_1400090c8,puVar1,0,1);
  return;
}



===== CiProcessNotification @ 140001180 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void CiProcessNotification(ulonglong param_1,undefined8 param_2,undefined8 param_3)

{
  byte bVar1;
  undefined8 *puVar2;
  
  puVar2 = CiProcessLocate(param_1);
  if (puVar2 != (undefined8 *)0x0) {
    bVar1 = (*(code *)*CiKernelInterface)(param_1);
    CiProcessSuspend((longlong)puVar2,(ulonglong)bVar1,param_3);
    CiProcessDereference((longlong)puVar2);
  }
  return;
}



===== CiProcessSuspend @ 1400011e0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CiProcessSuspend(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int iVar3;
  ulonglong uVar4;
  byte bVar5;
  byte bVar6;
  int iVar7;
  undefined8 local_res8;
  byte local_res10 [8];
  
  local_res8 = 0;
  bVar5 = (byte)param_2;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,param_1,
               (char)*(undefined8 *)(param_1 + 0x50),bVar5);
  }
  local_res10[0] = 0;
  CiAcquireThreadLock(param_1);
  bVar6 = 0;
  if (*(byte *)(param_1 + 0x58) != bVar5) {
    puVar1 = (undefined8 *)(param_1 + 0x40);
    for (puVar2 = (undefined8 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined8 *)*puVar2) {
      if (bVar5 == 0) {
        CiThreadIncrementScheduledCount((longlong)(puVar2 + -0xe));
      }
      else {
        CiThreadDecrementScheduledCount((longlong)(puVar2 + -0xe));
      }
    }
    uVar4 = KeQueryInterruptTimePrecise(&local_res8);
    KeAcquireSpinLockRaiseToDpc(&CiSchedulerLock);
    _DAT_1400091c8 = SystemReserved1[0xf];
    iVar3 = 0;
    for (puVar2 = (undefined8 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined8 *)*puVar2) {
      iVar7 = iVar3 + 1;
      if ((*(byte *)(*(longlong *)(puVar2[-5] + 0x88) + 3) & 1) == 0) {
        iVar7 = iVar3;
      }
      *(byte *)((longlong)puVar2 + 0x24) =
           (*(byte *)((longlong)puVar2 + 0x24) ^ bVar5) & 1 ^ *(byte *)((longlong)puVar2 + 0x24);
      CiSchedulerUpdateSuspendState((longlong)(puVar2 + -0xe));
      iVar3 = iVar7;
    }
    CiSchedulerPostSuspend(bVar5,iVar3,uVar4,local_res10);
    *(byte *)(param_1 + 0x58) = bVar5;
    bVar6 = local_res10[0];
  }
  CiReleaseThreadLock(param_1);
  if (bVar6 != 0) {
    KeAlertThread(CiSchedulerThread,0);
  }
  return;
}



===== CiSchedulerUpdateSuspendState @ 140001390 =====

void CiSchedulerUpdateSuspendState(longlong param_1)

{
  if ((*(byte *)(param_1 + 0x94) & 1) == 0) {
    CiSchedulerSetPriority(param_1);
    return;
  }
  if (*(char *)(param_1 + 0x6b) != -1) {
    KeSetBasePriorityThread(*(undefined8 *)(param_1 + 0x60),*(undefined4 *)(param_1 + 0x90));
  }
  *(undefined1 *)(param_1 + 0x6b) = 0xff;
  return;
}



===== CiSchedulerPostSuspend @ 1400013e0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CiSchedulerPostSuspend(char param_1,int param_2,ulonglong param_3,byte *param_4)

{
  uint uVar1;
  byte bVar2;
  bool bVar3;
  
  CiSchedulerUpdateTimer(param_3);
  bVar2 = 0;
  if (param_2 != 0) {
    if (param_1 == '\0') {
      uVar1 = CiSchedulerWakeupReason;
      do {
        LOCK();
        bVar3 = uVar1 == CiSchedulerWakeupReason;
        if (bVar3) {
          CiSchedulerWakeupReason = uVar1 | 2;
        }
        else {
          uVar1 = CiSchedulerWakeupReason;
        }
        UNLOCK();
      } while (!bVar3);
      bVar2 = (byte)(uVar1 >> 0xf) & 1;
    }
    else {
      LOCK();
      CiSchedulerWakeupReason = CiSchedulerWakeupReason | 4;
      UNLOCK();
    }
  }
  _DAT_1400091c8 = 0;
  KeReleaseSpinLock(&CiSchedulerLock,0);
  *param_4 = bVar2;
  return;
}



===== CiSchedulerUpdateTimer @ 140001480 =====

void CiSchedulerUpdateTimer(ulonglong param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  
  if ((DAT_140009278 & 1) == 0) {
    uVar1 = DAT_140009278;
  }
  else {
    if (DAT_140009278 == 1) goto LAB_140001504;
    uVar1 = DAT_140009278 ^ 0x140009271;
  }
  if (uVar1 != 0) {
    if (uVar1 == CiSchedulerTimerNode) {
      return;
    }
    if (*(ulonglong *)(uVar1 + 0x18) < param_1) {
      lVar2 = 0;
    }
    else {
      lVar2 = param_1 - *(ulonglong *)(uVar1 + 0x18);
      if (lVar2 < -2000) {
        lVar2 = lVar2 + 2000;
      }
    }
    CiSchedulerTimerNode = uVar1;
    ExSetTimer(CiSchedulerTimer,lVar2,0,&CiSchedulerNoWakeTimerParams);
    return;
  }
LAB_140001504:
  if (CiSchedulerTimerNode != 1) {
    CiSchedulerTimerNode = 1;
    ExCancelTimer(CiSchedulerTimer,0);
  }
  return;
}



===== CiSchedulerDeepSleep @ 140001540 =====

void CiSchedulerDeepSleep(uint *param_1)

{
  uint uVar1;
  uint local_res8 [2];
  
  local_res8[0] = 0;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
            &WPP_e00c2d44edf236fb41cafbc4576a8546_Traceguids);
  }
  if (DAT_1400090d0 != '\0') {
    CiLogSchedulerSleep(5,0xffffffff);
  }
  uVar1 = CiSchedulerWakeupReason;
  LOCK();
  CiSchedulerWakeupReason = 0x8000;
  UNLOCK();
  *param_1 = uVar1;
  if (uVar1 == 0) {
    CiSchedulerWaitStatus = KeWaitForSingleObject(SystemReserved1[0xf],0,0,1,0);
  }
  CiSchedulerProcessDeadlines(local_res8);
  uVar1 = CiSchedulerWakeupReason;
  LOCK();
  CiSchedulerWakeupReason = 0;
  UNLOCK();
  *param_1 = *param_1 | uVar1;
  return;
}



===== CiSystemUpdateThreadTag @ 140001600 =====

void CiSystemUpdateThreadTag(longlong param_1,int param_2)

{
  if (DAT_1400090d0 != '\0') {
    CiLogThreadBuffering(param_1,(uint)(param_2 == 1));
  }
  KeUpdateThreadTag(*(undefined8 *)(param_1 + 0x60),param_2);
  return;
}



===== CiSchedulerAddThread @ 140001650 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CiSchedulerAddThread(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  code *pcVar4;
  
  KeAcquireSpinLockRaiseToDpc(&CiSchedulerLock);
  _DAT_1400091c8 = SystemReserved1[0xf];
  plVar1 = (longlong *)(param_1 + 0x20);
  if ((longlong *)*plVar1 == plVar1) {
    puVar2 = (undefined8 *)(param_1 + 0x10);
    if ((undefined8 *)*DAT_140009238 != &CiScheduledTaskIndexListHead) goto LAB_140001715;
    *puVar2 = &CiScheduledTaskIndexListHead;
    *(undefined8 **)(param_1 + 0x18) = DAT_140009238;
    *DAT_140009238 = puVar2;
    DAT_140009238 = puVar2;
  }
  *(undefined1 *)(param_2 + 0x6b) = 0xff;
  plVar3 = (longlong *)(param_2 + 0x50);
  puVar2 = *(undefined8 **)(param_1 + 0x28);
  if ((longlong *)*puVar2 == plVar1) {
    *plVar3 = (longlong)plVar1;
    *(undefined8 **)(param_2 + 0x58) = puVar2;
    *puVar2 = plVar3;
    *(longlong **)(param_1 + 0x28) = plVar3;
    CiSchedulerSetPriority(param_2);
    CiSystemUpdateThreadTag(param_2,*(int *)(param_1 + 0xc0));
    _DAT_1400091c8 = (void *)0x0;
    KeReleaseSpinLock(&CiSchedulerLock,0);
    return;
  }
LAB_140001715:
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== CiSchedulerRemoveDeadline @ 140001730 =====

void CiSchedulerRemoveDeadline(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x18) != 0) {
    *(undefined8 *)(param_1 + 0x18) = 0;
    if (*(char *)(param_1 + 0x24) != '\0') {
      *(undefined1 *)(param_1 + 0x24) = 0;
    }
    RtlRbRemoveNode(&CiSchedulerDeadlineQueue,param_1);
    if (CiSchedulerTimerNode == param_1) {
      CiSchedulerTimerNode = 2;
    }
  }
  return;
}



===== CiSchedulerCommitPriority @ 140001790 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CiSchedulerCommitPriority(longlong param_1)

{
  KeAcquireSpinLockRaiseToDpc(&CiSchedulerLock);
  _DAT_1400091c8 = SystemReserved1[0xf];
  CiSchedulerSetPriority(param_1);
  _DAT_1400091c8 = (void *)0x0;
  KeReleaseSpinLock(&CiSchedulerLock,0);
  return;
}



===== CiSchedulerCancelTaskIndexYield @ 140001800 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CiSchedulerCancelTaskIndexYield(longlong param_1)

{
  uint uVar1;
  bool bVar2;
  
  if (DAT_1400090d0 != '\0') {
    CiLogTaskIndexCancelYield(param_1);
  }
  KeAcquireSpinLockRaiseToDpc(&CiSchedulerLock);
  _DAT_1400091c8 = SystemReserved1[0xf];
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) & 0xfffffff7;
  bVar2 = *(longlong *)(param_1 + 0x50) == 0;
  if (!bVar2) {
    CiSchedulerRemoveDeadline(param_1 + 0x38);
  }
  if ((*(char *)(param_1 + 0x84) == '\0') || (*(longlong *)(param_1 + 0x78) == 0)) {
    if (bVar2) goto LAB_140001870;
  }
  else {
    CiSchedulerRemoveDeadline(param_1 + 0x60);
  }
  CiSchedulerUpdateTaskIndexPriorities(param_1);
LAB_140001870:
  uVar1 = *(uint *)(param_1 + 0xb8);
  if ((uVar1 & 0x20) != 0) {
    uVar1 = uVar1 & 0xffffffdf;
    CiTotalTasksDeadlineExpired = CiTotalTasksDeadlineExpired + -1;
    *(uint *)(param_1 + 0xb8) = uVar1;
  }
  if ((uVar1 & 0x10) != 0) {
    *(uint *)(param_1 + 0xb8) = uVar1 & 0xffffffef;
  }
  CiSchedulerRefreshTaskIndexQosProperties(param_1);
  _DAT_1400091c8 = (void *)0x0;
  KeReleaseSpinLock(&CiSchedulerLock,0);
  return;
}



===== CiSchedulerThreadFunction @ 1400018f0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CiSchedulerThreadFunction(undefined8 param_1)

{
  longlong *plVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  longlong lVar4;
  code *pcVar5;
  int iVar6;
  uint uVar7;
  char cVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  longlong *plVar11;
  undefined *puVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  undefined8 *puVar15;
  int iVar16;
  uint uVar17;
  uint local_res8 [2];
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  
  puVar15 = (undefined8 *)0x0;
  if (DAT_1400090d0 != '\0') {
    CiLogSchedulerWakeup(1);
  }
  puVar14 = auStack_48;
  cVar8 = '\x01';
  CiThreadsMovedUp = '\x01';
  CiSchedulerThread = SystemReserved1[0xf];
  CiSchedulerInLazyMode = 0;
  KeSetActualBasePriorityThread(SystemReserved1[0xf],0x1b);
  KeSetEvent(param_1,0,0);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
            &WPP_e00c2d44edf236fb41cafbc4576a8546_Traceguids);
  }
  local_res8[0] = 0;
  while( true ) {
    plVar11 = (longlong *)&CiSchedulerLock;
    iVar16 = 0;
    KeAcquireSpinLockRaiseToDpc();
    uVar17 = 0;
    _DAT_1400091c8 = SystemReserved1[0xf];
    CiThreadsMovedUp = cVar8;
    for (puVar3 = CiScheduledTaskIndexListHead;
        (undefined8 **)puVar3 != &CiScheduledTaskIndexListHead; puVar3 = (undefined8 *)*puVar3) {
      puVar15 = puVar3 + -2;
      puVar2 = (undefined8 *)puVar3[2];
      iVar6 = iVar16;
      uVar7 = uVar17;
      while (uVar17 = uVar7, iVar16 = iVar6, puVar2 != puVar3 + 2) {
        uVar10 = CiSchedulerSetPriority((longlong)(puVar2 + -10));
        puVar2 = (undefined8 *)*puVar2;
        plVar11 = (longlong *)(uVar10 & 0xff);
        iVar6 = iVar16 + 1;
        uVar7 = uVar17 + 1;
        if ((char)uVar10 == '\0') {
          iVar6 = iVar16;
          uVar7 = uVar17;
        }
      }
    }
    if ((CiThreadsMovedUp != '\0') && (1 < uVar17)) break;
LAB_1400019fa:
    if (iVar16 == 0) {
      cVar8 = '\x01';
      CiThreadsMovedUp = '\x01';
      CiSchedulerInLazyMode = 1;
      CiSchedulerRemoveDeadline(0x140009280);
      _DAT_1400091c8 = (void *)0x0;
      KeReleaseSpinLock(&CiSchedulerLock,0);
      CiSchedulerDeepSleep(local_res8);
    }
    else {
      uVar9 = CiSchedulerWait(plVar11,local_res8);
      cVar8 = (char)uVar9;
    }
    uVar17 = local_res8[0];
    if (DAT_1400090d0 != '\0') {
      CiLogSchedulerWakeup(local_res8[0]);
    }
    if ((uVar17 & 8) != 0) {
      puVar12 = WPP_GLOBAL_Control;
      puVar13 = auStack_48;
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
LAB_140001b80:
        puVar13 = puVar14;
        if (3 < (byte)puVar12[0x29]) {
          uVar9 = *(undefined8 *)(puVar12 + 0x18);
          *(undefined8 *)(puVar14 + -8) = 0x140001b9f;
          WPP_SF_(uVar9,0x10,&WPP_e00c2d44edf236fb41cafbc4576a8546_Traceguids);
        }
      }
      *(undefined8 *)(puVar13 + -8) = 0x140001a45;
      PsTerminateSystemThread(0);
      return;
    }
  }
  plVar11 = (longlong *)puVar15[4];
  plVar1 = puVar15 + 4;
  if (((longlong *)plVar11[1] == plVar1) && (lVar4 = *plVar11, *(longlong **)(lVar4 + 8) == plVar11)
     ) {
    *plVar1 = lVar4;
    *(longlong **)(lVar4 + 8) = plVar1;
    puVar3 = (undefined8 *)puVar15[5];
    if ((longlong *)*puVar3 == plVar1) {
      *plVar11 = (longlong)plVar1;
      plVar11[1] = (longlong)puVar3;
      *puVar3 = plVar11;
      puVar15[5] = plVar11;
      goto LAB_1400019fa;
    }
  }
  puVar12 = (undefined *)0x3;
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)();
  puVar14 = auStack_40;
  goto LAB_140001b80;
}



===== CiSchedulerProcessDeadlines @ 140001bb0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool CiSchedulerProcessDeadlines(uint *param_1)

{
  uint uVar1;
  bool bVar2;
  longlong lVar3;
  ulonglong uVar4;
  uint uVar5;
  ulonglong uVar6;
  bool bVar7;
  undefined8 local_res18;
  char *local_res20;
  
  if (CiSchedulerDeadlineQueue == 0) {
    return false;
  }
  uVar5 = 0;
  bVar2 = false;
  local_res18 = 0;
  if (CiSchedulerWaitStatus == 0x101) {
    uVar4 = KeQueryInterruptTimePrecise(&local_res18);
  }
  else {
    uVar4 = _DAT_fffff78000000008;
  }
  KeAcquireSpinLockRaiseToDpc(&CiSchedulerLock);
  _DAT_1400091c8 = SystemReserved1[0xf];
  CiSchedulerTimerNode = 2;
  if ((DAT_140009278 & 1) == 0) {
    uVar6 = DAT_140009278;
LAB_140001c64:
    if (uVar6 != 0) {
      do {
        if (uVar4 + 2000 < *(ulonglong *)(uVar6 + 0x18)) break;
        RtlRbRemoveNode(&CiSchedulerDeadlineQueue,uVar6);
        *(undefined8 *)(uVar6 + 0x18) = 0;
        if (*(int *)(uVar6 + 0x20) == 1) {
          local_res20 = (char *)(uVar6 + 0x24);
          uVar5 = uVar5 | 0x20;
          lVar3 = 0x60;
          if (*(char *)(uVar6 + 0x24) == '\0') {
            lVar3 = 0x38;
          }
          lVar3 = uVar6 - lVar3;
          uVar1 = *(uint *)(lVar3 + 0xb8);
          if (*(char *)(uVar6 + 0x24) == '\0') {
            *(uint *)(lVar3 + 0xb8) = uVar1 | 0x30;
            if ((uVar1 & 1) != 0) {
              bVar2 = true;
            }
            CiTotalTasksDeadlineExpired = CiTotalTasksDeadlineExpired + 1;
          }
          else {
            *(uint *)(lVar3 + 0xb8) = uVar1 | 0x10;
          }
          CiSchedulerUpdateTaskIndexPriorities(lVar3);
          CiSchedulerRefreshTaskIndexQosProperties(lVar3);
          if (DAT_1400090d0 != '\0') {
            if (*local_res20 == '\0') {
              CiLogTaskIndexDeadlineExpired(lVar3);
            }
            else {
              CiLogTaskIndexPreDeadlineExpired(lVar3);
            }
          }
        }
        else {
          uVar5 = uVar5 | 0x10;
        }
        if ((DAT_140009278 & 1) == 0) {
          uVar6 = DAT_140009278;
        }
        else {
          if (DAT_140009278 == 1) break;
          uVar6 = DAT_140009278 ^ 0x140009271;
        }
      } while (uVar6 != 0);
      if ((uVar5 & 0x20) != 0) {
        if (bVar2) {
          if (CiCurrentMediaBufferingState != '\0') {
            CiCurrentMediaBufferingState = '\0';
            PoNotifyMediaBuffering(0);
          }
        }
        else {
          bVar7 = CiTotalTasksBuffering != 0;
          if ((bVar7 != (bool)CiCurrentMediaBufferingState) &&
             ((!bVar7 || (CiTotalTasksDeadlineExpired == 0)))) {
            CiCurrentMediaBufferingState = bVar7;
            PoNotifyMediaBuffering();
          }
        }
      }
      if ((uVar5 & 0x10) != 0) goto LAB_140001da3;
    }
  }
  else if (DAT_140009278 != 1) {
    uVar6 = DAT_140009278 ^ 0x140009271;
    goto LAB_140001c64;
  }
  if ((DAT_140009278 & 1) == 0) {
    uVar6 = DAT_140009278;
LAB_140001d4a:
    if (uVar6 != 0) {
      if (uVar6 != CiSchedulerTimerNode) {
        if (*(ulonglong *)(uVar6 + 0x18) < uVar4) {
          lVar3 = 0;
        }
        else {
          lVar3 = uVar4 - *(ulonglong *)(uVar6 + 0x18);
          if (lVar3 < -2000) {
            lVar3 = lVar3 + 2000;
          }
        }
        CiSchedulerTimerNode = uVar6;
        ExSetTimer(CiSchedulerTimer,lVar3,0,&CiSchedulerNoWakeTimerParams);
      }
      goto LAB_140001da3;
    }
  }
  else if (DAT_140009278 != 1) {
    uVar6 = DAT_140009278 ^ 0x140009271;
    goto LAB_140001d4a;
  }
  if (CiSchedulerTimerNode != 1) {
    CiSchedulerTimerNode = 1;
    ExCancelTimer(CiSchedulerTimer,0);
  }
LAB_140001da3:
  _DAT_1400091c8 = (void *)0x0;
  KeReleaseSpinLock(&CiSchedulerLock,0);
  if (bVar2) {
    if (DAT_1400090d0 != '\0') {
      CiLogTurboEngaged();
    }
    PoLatencySensitivityHint(4);
  }
  uVar1 = CiSchedulerWakeupReason;
  LOCK();
  CiSchedulerWakeupReason = 0;
  UNLOCK();
  *param_1 = *param_1 | uVar5 | uVar1;
  return (*param_1 & 0xffffffdf) != 0;
}



===== CiSchedulerSleep @ 140001f80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CiSchedulerSleep(undefined4 param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  bool bVar2;
  undefined1 uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong *puVar6;
  ulonglong *puVar7;
  uint uVar8;
  longlong lVar9;
  uint uVar10;
  bool bVar11;
  undefined1 auStack_c8 [32];
  uint **local_a8;
  undefined4 local_98 [2];
  uint local_90 [2];
  uint local_88 [4];
  undefined8 local_78;
  undefined8 local_70;
  uint *local_68;
  undefined8 local_60;
  undefined4 *local_58;
  undefined8 local_50;
  uint *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_c8;
  if (DAT_140009298 != 0) {
    RtlRbRemoveNode(&CiSchedulerDeadlineQueue,&CiSchedulerDeadlineNode);
  }
  local_78 = 0;
  if (CiSchedulerWaitStatus == 0x101) {
    uVar4 = KeQueryInterruptTimePrecise(&local_78);
  }
  else {
    uVar4 = _DAT_fffff78000000008;
  }
  DAT_140009298 = uVar4 + param_2;
  DAT_1400092a4 = 0;
  puVar7 = CiSchedulerDeadlineQueue;
  if ((DAT_140009278 & 1) == 0) {
LAB_14000201a:
    uVar3 = 0;
    if (puVar7 != (ulonglong *)0x0) {
      do {
        if (puVar7[3] <= DAT_140009298) {
          puVar6 = (ulonglong *)puVar7[1];
          if ((DAT_140009278 & 1) == 0) {
LAB_1400023ce:
            if (puVar6 != (ulonglong *)0x0) goto LAB_1400023d3;
          }
          else if (puVar6 != (ulonglong *)0x0) {
            puVar6 = (ulonglong *)((ulonglong)puVar6 ^ (ulonglong)puVar7);
            goto LAB_1400023ce;
          }
          uVar3 = 1;
          break;
        }
        puVar6 = (ulonglong *)*puVar7;
        if ((DAT_140009278 & 1) != 0) {
          if (puVar6 == (ulonglong *)0x0) goto LAB_140002048;
          puVar6 = (ulonglong *)((ulonglong)puVar6 ^ (ulonglong)puVar7);
        }
        if (puVar6 == (ulonglong *)0x0) goto LAB_140002048;
LAB_1400023d3:
        puVar7 = puVar6;
      } while( true );
    }
  }
  else {
    if (CiSchedulerDeadlineQueue != (ulonglong *)0x0) {
      puVar7 = (ulonglong *)((ulonglong)CiSchedulerDeadlineQueue ^ 0x140009270);
      goto LAB_14000201a;
    }
    puVar7 = (ulonglong *)0x0;
LAB_140002048:
    uVar3 = 0;
  }
  RtlRbInsertNodeEx(&CiSchedulerDeadlineQueue,puVar7,uVar3,&CiSchedulerDeadlineNode);
  if ((DAT_140009278 & 1) == 0) {
    uVar5 = DAT_140009278;
LAB_140002077:
    if (uVar5 != 0) {
      if (uVar5 != CiSchedulerTimerNode) {
        if (*(ulonglong *)(uVar5 + 0x18) < uVar4) {
          lVar9 = 0;
        }
        else {
          lVar9 = uVar4 - *(ulonglong *)(uVar5 + 0x18);
          if (lVar9 < -2000) {
            lVar9 = lVar9 + 2000;
          }
        }
        CiSchedulerTimerNode = uVar5;
        ExSetTimer(CiSchedulerTimer,lVar9,0,&CiSchedulerNoWakeTimerParams);
      }
      goto LAB_1400020d0;
    }
  }
  else if (DAT_140009278 != 1) {
    uVar5 = DAT_140009278 ^ 0x140009271;
    goto LAB_140002077;
  }
  if (CiSchedulerTimerNode != 1) {
    CiSchedulerTimerNode = 1;
    ExCancelTimer(CiSchedulerTimer,0);
  }
LAB_1400020d0:
  _DAT_1400091c8 = (void *)0x0;
  KeReleaseSpinLock(&CiSchedulerLock,0);
  if (DAT_1400090d0 != '\0') {
    local_58 = local_98;
    local_48 = local_90;
    local_a8 = &local_58;
    local_50 = 4;
    local_40 = 4;
    local_98[0] = param_1;
    local_90[0] = param_2;
    EtwWrite(DAT_1400090c8,&CiSchedulerSleepEvent,0,2);
  }
  uVar8 = CiSchedulerWakeupReason;
  LOCK();
  CiSchedulerWakeupReason = 0;
  UNLOCK();
  if (uVar8 != 0) goto LAB_14000212c;
  do {
    local_a8 = (undefined4 **)0x0;
    CiSchedulerWaitStatus = KeWaitForSingleObject(CiSchedulerTimer,0,0,1);
LAB_14000212c:
    if (CiSchedulerDeadlineQueue != (ulonglong *)0x0) {
      uVar10 = 0;
      bVar2 = false;
      local_70 = 0;
      if (CiSchedulerWaitStatus == 0x101) {
        uVar4 = KeQueryInterruptTimePrecise(&local_70);
      }
      else {
        uVar4 = _DAT_fffff78000000008;
      }
      KeAcquireSpinLockRaiseToDpc(&CiSchedulerLock);
      _DAT_1400091c8 = SystemReserved1[0xf];
      CiSchedulerTimerNode = 2;
      if ((DAT_140009278 & 1) == 0) {
        uVar5 = DAT_140009278;
LAB_1400021a1:
        if (uVar5 == 0) goto LAB_14000224b;
        do {
          if (uVar4 + 2000 < *(ulonglong *)(uVar5 + 0x18)) break;
          RtlRbRemoveNode(&CiSchedulerDeadlineQueue);
          *(undefined8 *)(uVar5 + 0x18) = 0;
          if (*(int *)(uVar5 + 0x20) == 1) {
            uVar10 = uVar10 | 0x20;
            if (*(char *)(uVar5 + 0x24) == '\0') {
              *(uint *)(uVar5 + 0x80) = *(uint *)(uVar5 + 0x80) | 0x10;
              lVar9 = uVar5 - 0x38;
              uVar1 = *(uint *)(uVar5 + 0x80);
              *(uint *)(uVar5 + 0x80) = uVar1 | 0x20;
              if ((uVar1 & 1) != 0) {
                bVar2 = true;
              }
              CiTotalTasksDeadlineExpired = CiTotalTasksDeadlineExpired + 1;
            }
            else {
              *(uint *)(uVar5 + 0x58) = *(uint *)(uVar5 + 0x58) | 0x10;
              lVar9 = uVar5 - 0x60;
            }
            CiSchedulerUpdateTaskIndexPriorities(lVar9);
            CiSchedulerRefreshTaskIndexQosProperties(lVar9);
            if (DAT_1400090d0 != '\0') {
              if (*(char *)(uVar5 + 0x24) == '\0') {
                CiLogTaskIndexDeadlineExpired(lVar9);
              }
              else {
                CiLogTaskIndexPreDeadlineExpired(lVar9);
              }
            }
          }
          else {
            uVar10 = uVar10 | 0x10;
          }
          if ((DAT_140009278 & 1) == 0) {
            uVar5 = DAT_140009278;
          }
          else {
            if (DAT_140009278 == 1) break;
            uVar5 = DAT_140009278 ^ 0x140009271;
          }
        } while (uVar5 != 0);
        if ((uVar10 & 0x20) != 0) {
          if (bVar2) {
            if (CiCurrentMediaBufferingState != '\0') {
              CiCurrentMediaBufferingState = '\0';
              PoNotifyMediaBuffering(0);
            }
          }
          else {
            bVar11 = CiTotalTasksBuffering != 0;
            if ((bVar11 != (bool)CiCurrentMediaBufferingState) &&
               ((!bVar11 || (CiTotalTasksDeadlineExpired == 0)))) {
              CiCurrentMediaBufferingState = bVar11;
              PoNotifyMediaBuffering();
            }
          }
        }
        if ((uVar10 & 0x10) == 0) goto LAB_14000224b;
      }
      else {
        if (DAT_140009278 != 1) {
          uVar5 = DAT_140009278 ^ 0x140009271;
          goto LAB_1400021a1;
        }
LAB_14000224b:
        if ((DAT_140009278 & 1) == 0) {
          uVar5 = DAT_140009278;
LAB_140002265:
          if (uVar5 != 0) {
            if (uVar5 != CiSchedulerTimerNode) {
              if (*(ulonglong *)(uVar5 + 0x18) < uVar4) {
                lVar9 = 0;
              }
              else {
                lVar9 = uVar4 - *(ulonglong *)(uVar5 + 0x18);
                if (lVar9 < -2000) {
                  lVar9 = lVar9 + 2000;
                }
              }
              CiSchedulerTimerNode = uVar5;
              ExSetTimer(CiSchedulerTimer,lVar9,0,&CiSchedulerNoWakeTimerParams);
            }
            goto LAB_1400022bb;
          }
        }
        else if (DAT_140009278 != 1) {
          uVar5 = DAT_140009278 ^ 0x140009271;
          goto LAB_140002265;
        }
        if (CiSchedulerTimerNode != 1) {
          CiSchedulerTimerNode = 1;
          ExCancelTimer(CiSchedulerTimer);
        }
      }
LAB_1400022bb:
      _DAT_1400091c8 = (void *)0x0;
      KeReleaseSpinLock(&CiSchedulerLock);
      if (bVar2) {
        if (DAT_1400090d0 != '\0') {
          CiLogTurboEngaged();
        }
        PoLatencySensitivityHint(4);
      }
      uVar1 = CiSchedulerWakeupReason;
      LOCK();
      CiSchedulerWakeupReason = 0;
      UNLOCK();
      uVar8 = uVar8 | uVar10 | uVar1;
      if ((uVar8 & 0xffffffdf) != 0) {
        *param_3 = uVar8;
        return;
      }
    }
    if (DAT_1400090d0 != '\0') {
      local_68 = local_88;
      local_a8 = &local_68;
      local_60 = 4;
      local_88[0] = uVar8;
      EtwWrite(DAT_1400090c8,&CiSchedulerWakeupEvent,0,1);
    }
    uVar8 = 0;
  } while( true );
}



===== CiSchedulerWait @ 140002650 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong CiSchedulerWait(undefined8 param_1,uint *param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong *puVar5;
  undefined8 uVar6;
  undefined4 uVar7;
  undefined8 *puVar8;
  longlong lVar9;
  ulonglong *puVar10;
  uint uVar11;
  ulonglong *puVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  bool bVar16;
  undefined1 auStack_d8 [32];
  uint **local_b8;
  uint local_a8 [2];
  uint local_a0 [2];
  uint local_98 [2];
  uint local_90 [4];
  undefined8 local_80;
  undefined8 local_78;
  uint *local_70;
  undefined8 local_68;
  uint *local_60;
  undefined8 local_58;
  uint *local_50;
  undefined8 local_48;
  uint *local_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_d8;
  if (CiThreadsMovedUp == '\0') {
    uVar6 = CiSchedulerSleep(0,DAT_140009254,param_2);
    uVar3 = CONCAT71((int7)((ulonglong)uVar6 >> 8),1);
  }
  else {
    if (CiSchedulerInLazyMode == '\0') {
      uVar7 = 1;
      uVar11 = CiSchedulerTimeIncrement;
    }
    else {
      uVar7 = 2;
      uVar11 = CiSchedulerLazyModeTimeout;
    }
    CiSchedulerSleep(uVar7,uVar11,param_2);
LAB_1400026ba:
    puVar12 = (ulonglong *)0x0;
    uVar3 = (ulonglong)*param_2;
    if ((*param_2 & 0xc) == 0) {
      CiSystemDetectPotentiallyStarvedProcessors();
      if (CiProcessorIdleHistoryBits == 0) {
        uVar3 = 0;
        if (CiSchedulerInLazyMode != '\0') {
          CiSchedulerInLazyMode = '\0';
          uVar3 = (ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c);
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar3 = WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                            &WPP_e00c2d44edf236fb41cafbc4576a8546_Traceguids);
          }
        }
      }
      else {
        if (CiProcessorIdleHistoryBits == CiSchedulerIdleCycleBitMask) {
          if (CiSchedulerInLazyMode == '\0') {
            if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
               (3 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                       &WPP_e00c2d44edf236fb41cafbc4576a8546_Traceguids,CiSchedulerLazyModeTimeout);
            }
            CiSchedulerInLazyMode = '\x01';
          }
          uVar13 = 4;
          uVar11 = CiSchedulerLazyModeTimeout;
        }
        else {
          uVar13 = 3;
          uVar11 = CiSchedulerPeriod;
        }
        if (DAT_1400090d0 != '\0') {
          local_a8[0] = *param_2;
          local_70 = local_a8;
          local_68 = 4;
          local_b8 = &local_70;
          EtwWrite(DAT_1400090c8,&CiSchedulerWakeupEvent,0,1);
        }
        KeAcquireSpinLockRaiseToDpc(&CiSchedulerLock);
        _DAT_1400091c8 = SystemReserved1[0xf];
        puVar1 = CiScheduledTaskIndexListHead;
        if (CiSchedulerInLazyMode == '\0') {
LAB_140002765:
          if (DAT_140009298 != 0) {
            RtlRbRemoveNode(&CiSchedulerDeadlineQueue,&CiSchedulerDeadlineNode);
          }
          local_80 = 0;
          if (CiSchedulerWaitStatus == 0x101) {
            uVar3 = KeQueryInterruptTimePrecise(&local_80);
          }
          else {
            uVar3 = _DAT_fffff78000000008;
          }
          DAT_140009298 = uVar11 + uVar3;
          DAT_1400092a4 = 0;
          if ((DAT_140009278 & 1) == 0) {
            puVar10 = CiSchedulerDeadlineQueue;
LAB_1400027b3:
            uVar6 = 0;
            if (puVar10 != (ulonglong *)0x0) {
              while (DAT_140009298 < puVar10[3]) {
                puVar5 = (ulonglong *)*puVar10;
                if ((DAT_140009278 & 1) != 0) {
                  if (puVar5 == (ulonglong *)0x0) goto LAB_1400027e2;
                  puVar5 = (ulonglong *)((ulonglong)puVar5 ^ (ulonglong)puVar10);
                }
                if (puVar5 == (ulonglong *)0x0) goto LAB_1400027e2;
LAB_140002b44:
                puVar10 = puVar5;
              }
              puVar5 = (ulonglong *)puVar10[1];
              if ((DAT_140009278 & 1) == 0) {
LAB_140002b3b:
                if (puVar5 != (ulonglong *)0x0) goto LAB_140002b44;
              }
              else if (puVar5 != (ulonglong *)0x0) {
                puVar5 = (ulonglong *)((ulonglong)puVar5 ^ (ulonglong)puVar10);
                goto LAB_140002b3b;
              }
              uVar6 = 1;
            }
          }
          else {
            if (CiSchedulerDeadlineQueue != (ulonglong *)0x0) {
              puVar10 = (ulonglong *)((ulonglong)CiSchedulerDeadlineQueue ^ 0x140009270);
              goto LAB_1400027b3;
            }
            uVar6 = 0;
            puVar10 = puVar12;
          }
LAB_1400027e2:
          RtlRbInsertNodeEx(&CiSchedulerDeadlineQueue,puVar10,uVar6,&CiSchedulerDeadlineNode);
          if ((DAT_140009278 & 1) == 0) {
            uVar4 = DAT_140009278;
LAB_14000280f:
            if (uVar4 != 0) {
              if (uVar4 != CiSchedulerTimerNode) {
                if ((uVar3 <= *(ulonglong *)(uVar4 + 0x18)) &&
                   (puVar12 = (ulonglong *)(uVar3 - *(ulonglong *)(uVar4 + 0x18)),
                   (longlong)puVar12 < -2000)) {
                  puVar12 = puVar12 + 0xfa;
                }
                CiSchedulerTimerNode = uVar4;
                ExSetTimer(CiSchedulerTimer,puVar12,0,&CiSchedulerNoWakeTimerParams);
              }
              goto LAB_140002868;
            }
          }
          else if (DAT_140009278 != 1) {
            uVar4 = DAT_140009278 ^ 0x140009271;
            goto LAB_14000280f;
          }
          if (CiSchedulerTimerNode != 1) {
            CiSchedulerTimerNode = 1;
            ExCancelTimer(CiSchedulerTimer);
          }
LAB_140002868:
          _DAT_1400091c8 = (void *)0x0;
          KeReleaseSpinLock(&CiSchedulerLock);
          if (DAT_1400090d0 != '\0') {
            local_50 = local_a0;
            local_40 = local_98;
            local_b8 = &local_50;
            local_48 = 4;
            local_38 = 4;
            local_a0[0] = uVar13;
            local_98[0] = uVar11;
            EtwWrite(DAT_1400090c8,&CiSchedulerSleepEvent,0,2);
          }
          uVar11 = CiSchedulerWakeupReason;
          LOCK();
          CiSchedulerWakeupReason = 0;
          UNLOCK();
          if (uVar11 != 0) goto LAB_1400028c4;
          do {
            local_b8 = (uint **)0x0;
            CiSchedulerWaitStatus = KeWaitForSingleObject(CiSchedulerTimer,0,0,1);
LAB_1400028c4:
            uVar14 = 0;
            uVar13 = 0;
            if (CiSchedulerDeadlineQueue != (ulonglong *)0x0) {
              local_78 = 0;
              if (CiSchedulerWaitStatus == 0x101) {
                uVar3 = KeQueryInterruptTimePrecise(&local_78);
              }
              else {
                uVar3 = _DAT_fffff78000000008;
              }
              KeAcquireSpinLockRaiseToDpc(&CiSchedulerLock);
              _DAT_1400091c8 = SystemReserved1[0xf];
              CiSchedulerTimerNode = 2;
              uVar15 = uVar13;
              if ((DAT_140009278 & 1) == 0) {
                uVar4 = DAT_140009278;
LAB_140002942:
                uVar2 = uVar14;
                if (uVar4 == 0) goto LAB_1400029ee;
                do {
                  uVar13 = uVar2;
                  uVar15 = uVar14;
                  if (uVar3 + 2000 < *(ulonglong *)(uVar4 + 0x18)) break;
                  RtlRbRemoveNode(&CiSchedulerDeadlineQueue);
                  *(undefined8 *)(uVar4 + 0x18) = 0;
                  if (*(int *)(uVar4 + 0x20) == 1) {
                    uVar14 = uVar14 | 0x20;
                    if (*(char *)(uVar4 + 0x24) == '\0') {
                      *(uint *)(uVar4 + 0x80) = *(uint *)(uVar4 + 0x80) | 0x10;
                      lVar9 = uVar4 - 0x38;
                      uVar15 = *(uint *)(uVar4 + 0x80);
                      *(uint *)(uVar4 + 0x80) = uVar15 | 0x20;
                      if ((uVar15 & 1) != 0) {
                        uVar13 = 1;
                      }
                      CiTotalTasksDeadlineExpired = CiTotalTasksDeadlineExpired + 1;
                    }
                    else {
                      *(uint *)(uVar4 + 0x58) = *(uint *)(uVar4 + 0x58) | 0x10;
                      lVar9 = uVar4 - 0x60;
                    }
                    CiSchedulerUpdateTaskIndexPriorities(lVar9);
                    CiSchedulerRefreshTaskIndexQosProperties(lVar9);
                    if (DAT_1400090d0 != '\0') {
                      if (*(char *)(uVar4 + 0x24) == '\0') {
                        CiLogTaskIndexDeadlineExpired(lVar9);
                      }
                      else {
                        CiLogTaskIndexPreDeadlineExpired(lVar9);
                      }
                    }
                  }
                  else {
                    uVar14 = uVar14 | 0x10;
                  }
                  uVar15 = uVar14;
                  if ((DAT_140009278 & 1) == 0) {
                    uVar4 = DAT_140009278;
                  }
                  else {
                    if (DAT_140009278 == 1) break;
                    uVar4 = DAT_140009278 ^ 0x140009271;
                  }
                  uVar2 = uVar13;
                } while (uVar4 != 0);
                if ((uVar15 & 0x20) != 0) {
                  if (uVar13 == 0) {
                    bVar16 = CiTotalTasksBuffering != 0;
                    if ((bVar16 != (bool)CiCurrentMediaBufferingState) &&
                       ((!bVar16 || (CiTotalTasksDeadlineExpired == 0)))) {
                      CiCurrentMediaBufferingState = bVar16;
                      PoNotifyMediaBuffering();
                    }
                  }
                  else if (CiCurrentMediaBufferingState != '\0') {
                    CiCurrentMediaBufferingState = '\0';
                    PoNotifyMediaBuffering(0);
                  }
                }
                if ((uVar15 & 0x10) == 0) goto LAB_1400029ee;
              }
              else {
                if (DAT_140009278 != 1) {
                  uVar4 = DAT_140009278 ^ 0x140009271;
                  goto LAB_140002942;
                }
LAB_1400029ee:
                if ((DAT_140009278 & 1) == 0) {
                  uVar4 = DAT_140009278;
LAB_140002a08:
                  if (uVar4 != 0) {
                    if (uVar4 != CiSchedulerTimerNode) {
                      if (*(ulonglong *)(uVar4 + 0x18) < uVar3) {
                        lVar9 = 0;
                      }
                      else {
                        lVar9 = uVar3 - *(ulonglong *)(uVar4 + 0x18);
                        if (lVar9 < -2000) {
                          lVar9 = lVar9 + 2000;
                        }
                      }
                      CiSchedulerTimerNode = uVar4;
                      ExSetTimer(CiSchedulerTimer,lVar9,0,&CiSchedulerNoWakeTimerParams);
                    }
                    goto LAB_140002a5e;
                  }
                }
                else if (DAT_140009278 != 1) {
                  uVar4 = DAT_140009278 ^ 0x140009271;
                  goto LAB_140002a08;
                }
                if (CiSchedulerTimerNode != 1) {
                  CiSchedulerTimerNode = 1;
                  ExCancelTimer(CiSchedulerTimer);
                }
              }
LAB_140002a5e:
              _DAT_1400091c8 = (void *)0x0;
              KeReleaseSpinLock(&CiSchedulerLock);
              if (uVar13 != 0) {
                if (DAT_1400090d0 != '\0') {
                  CiLogTurboEngaged();
                }
                PoLatencySensitivityHint(4);
              }
              uVar13 = CiSchedulerWakeupReason;
              LOCK();
              CiSchedulerWakeupReason = 0;
              UNLOCK();
              uVar11 = uVar11 | uVar15 | uVar13;
              if ((uVar11 & 0xffffffdf) != 0) goto LAB_140002b1c;
            }
            if (DAT_1400090d0 != '\0') {
              local_60 = local_90;
              local_b8 = &local_60;
              local_58 = 4;
              local_90[0] = uVar11;
              EtwWrite(DAT_1400090c8,&CiSchedulerWakeupEvent,0,1);
            }
            uVar11 = 0;
          } while( true );
        }
        for (; (undefined8 **)puVar1 != &CiScheduledTaskIndexListHead;
            puVar1 = (undefined8 *)*puVar1) {
          for (puVar8 = (undefined8 *)puVar1[2]; puVar8 != puVar1 + 2;
              puVar8 = (undefined8 *)*puVar8) {
            if ((*(byte *)((longlong)puVar8 + 0x44) & 1) == 0) goto LAB_140002765;
          }
        }
        *param_2 = *param_2 | 0x80;
        _DAT_1400091c8 = (void *)0x0;
        uVar3 = KeReleaseSpinLock(&CiSchedulerLock,0);
      }
    }
    uVar3 = uVar3 & 0xffffffffffffff00;
  }
  return uVar3;
LAB_140002b1c:
  *param_2 = uVar11;
  goto LAB_1400026ba;
}



===== CiSchedulerUpdateTaskIndexPriorities @ 140002f70 =====

void CiSchedulerUpdateTaskIndexPriorities(longlong param_1)

{
  undefined8 *puVar1;
  longlong lVar2;
  byte bVar3;
  
  for (puVar1 = *(undefined8 **)(param_1 + 0x20); puVar1 != (undefined8 *)(param_1 + 0x20);
      puVar1 = (undefined8 *)*puVar1) {
    if ((*(byte *)((longlong)puVar1 + 0x44) & 1) == 0) {
      if (CiThreadsMovedUp == '\0') {
        bVar3 = *(byte *)((longlong)puVar1 + 0x1a);
      }
      else {
        lVar2 = puVar1[-1];
        if ((*(longlong *)(lVar2 + 0x78) == 0) &&
           ((*(char *)(lVar2 + 0x84) != '\0' || (*(longlong *)(lVar2 + 0x50) == 0)))) {
          bVar3 = *(byte *)(puVar1 + 3);
        }
        else {
          bVar3 = *(byte *)(puVar1[-2] + 0x28);
          if (*(byte *)(puVar1 + 3) < *(byte *)(puVar1[-2] + 0x28)) {
            bVar3 = *(byte *)(puVar1 + 3);
          }
        }
      }
      if ((uint)*(byte *)((longlong)puVar1 + 0x1b) != (uint)bVar3) {
        *(byte *)((longlong)puVar1 + 0x1b) = bVar3;
        if (DAT_1400090d0 != '\0') {
          CiLogSchedulerEvent((longlong)(puVar1 + -10),(uint)bVar3);
        }
        KeSetActualBasePriorityThread(puVar1[2],bVar3);
      }
    }
  }
  return;
}



===== CiSystemDetectPotentiallyStarvedProcessors @ 140003040 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CiSystemDetectPotentiallyStarvedProcessors(void)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  char cVar3;
  longlong lVar4;
  longlong lVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined8 *puVar8;
  ulonglong uVar9;
  uint uVar10;
  longlong lVar11;
  uint uVar12;
  undefined1 auStack_68 [32];
  undefined8 local_48;
  longlong lStack_40;
  longlong local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_68;
  if (CiSchedulerDisallowLazyMode != '\0') {
    return;
  }
  uVar10 = 0;
  uVar6 = 0;
  uVar12 = (uint)DAT_1400092f8;
  CiPotentiallyStarvedProcessors = 0;
  if (uVar12 != 0) {
    uVar7 = 0;
    lVar11 = 0;
    do {
      lStack_40 = 0;
      puVar8 = (undefined8 *)(CiLastIdleStats + lVar11);
      local_38 = 0;
      local_48 = *puVar8;
      cVar3 = PoCpuIdledSinceLastCallImprecise(uVar6,&local_48);
      lVar4 = (**(code **)(CiKernelInterface + 8))(uVar6,1);
      lStack_40 = lStack_40 + lVar4;
      lVar4 = (**(code **)(CiKernelInterface + 8))(uVar6,2);
      lStack_40 = lStack_40 + lVar4;
      lVar4 = (**(code **)(CiKernelInterface + 8))(uVar6,3);
      lStack_40 = lStack_40 + lVar4;
      lVar4 = (**(code **)(CiKernelInterface + 0x10))(uVar6);
      if ((cVar3 == '\0') &&
         (uVar9 = ((local_38 + lVar4) - puVar8[2]) * (ulonglong)(100 - CiSystemResponsiveness),
         auVar1._8_8_ = 0, auVar1._0_8_ = uVar9,
         lVar5 = SUB168(ZEXT816(0x47ae147ae147ae15) * auVar1,8),
         uVar9 = ((uVar9 - lVar5 >> 1) + lVar5 >> 6) * 0x5a, auVar2._8_8_ = 0, auVar2._0_8_ = uVar9,
         lVar5 = SUB168(ZEXT816(0x47ae147ae147ae15) * auVar2,8),
         (uVar9 - lVar5 >> 1) + lVar5 >> 6 < (ulonglong)(lStack_40 - puVar8[1]))) {
        CiPotentiallyStarvedProcessors = CiPotentiallyStarvedProcessors | 1L << (uVar7 & 0x3f);
      }
      uVar6 = uVar6 + 1;
      uVar7 = uVar7 + 1;
      lVar11 = lVar11 + 0x18;
      *puVar8 = local_48;
      puVar8[1] = lStack_40;
      puVar8[2] = local_38 + lVar4;
    } while (uVar6 < uVar12);
    if (CiPotentiallyStarvedProcessors != 0) goto LAB_1400031b7;
  }
  uVar10 = CiProcessorIdleHistoryBits * 2 | 1;
LAB_1400031b7:
  CiProcessorIdleHistoryBits = uVar10 & CiSchedulerIdleCycleBitMask;
  return;
}



===== CiSchedulerSetPriority @ 140003260 =====

undefined8 CiSchedulerSetPriority(longlong param_1)

{
  longlong lVar1;
  ulonglong in_RAX;
  undefined8 uVar2;
  byte bVar3;
  
  if ((*(byte *)(param_1 + 0x94) & 1) != 0) {
    return in_RAX & 0xffffffffffffff00;
  }
  if (CiThreadsMovedUp == '\0') {
    bVar3 = *(byte *)(param_1 + 0x6a);
  }
  else {
    lVar1 = *(longlong *)(param_1 + 0x48);
    if ((*(longlong *)(lVar1 + 0x78) == 0) &&
       ((*(char *)(lVar1 + 0x84) != '\0' || (*(longlong *)(lVar1 + 0x50) == 0)))) {
      bVar3 = *(byte *)(param_1 + 0x68);
    }
    else {
      bVar3 = *(byte *)(*(longlong *)(param_1 + 0x40) + 0x28);
      if (*(byte *)(param_1 + 0x68) < bVar3) {
        bVar3 = *(byte *)(param_1 + 0x68);
      }
    }
  }
  uVar2 = 0;
  if ((uint)*(byte *)(param_1 + 0x6b) != (uint)bVar3) {
    *(byte *)(param_1 + 0x6b) = bVar3;
    if (DAT_1400090d0 != '\0') {
      CiLogSchedulerEvent(param_1,(uint)bVar3);
    }
    uVar2 = KeSetActualBasePriorityThread(*(undefined8 *)(param_1 + 0x60),bVar3);
  }
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
}



===== CiSchedulerTaskIndexYield @ 140003320 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CiSchedulerTaskIndexYield(longlong param_1,uint param_2,uint param_3)

{
  ulonglong uVar1;
  undefined8 *puVar2;
  ulonglong uVar3;
  ulonglong *puVar4;
  uint uVar5;
  ulonglong *puVar6;
  ulonglong uVar7;
  longlong lVar8;
  undefined8 uVar9;
  undefined1 auStack_a8 [32];
  longlong *local_88;
  uint local_78 [2];
  int local_70 [2];
  undefined8 local_68;
  longlong local_60;
  undefined8 local_58;
  uint *local_50;
  undefined8 local_48;
  int *local_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_a8;
  local_68 = 0;
  if (param_2 < CiSchedulerTimerResolution) {
    param_2 = CiSchedulerTimerResolution;
  }
  uVar7 = (ulonglong)param_3;
  if (param_3 != 0xffffffff) {
    if (param_3 < CiSchedulerTimerResolution) {
      param_3 = CiSchedulerTimerResolution;
    }
    uVar7 = (ulonglong)param_3;
    if (param_2 <= param_3) {
      uVar7 = 0xffffffff;
    }
  }
  if (DAT_1400090d0 != '\0') {
    local_60 = param_1 + 0x90;
    local_50 = local_78;
    local_40 = local_70;
    local_58 = 4;
    local_88 = &local_60;
    local_48 = 4;
    local_38 = 4;
    local_78[0] = param_2;
    local_70[0] = (int)uVar7;
    EtwWrite(DAT_1400090c8,&CiTaskIndexYieldEvent,0,3);
  }
  uVar3 = KeQueryInterruptTimePrecise(&local_68);
  KeAcquireSpinLockRaiseToDpc(&CiSchedulerLock);
  uVar1 = param_1 + 0x38;
  _DAT_1400091c8 = SystemReserved1[0xf];
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) | 8;
  if (*(longlong *)(param_1 + 0x50) != 0) {
    *(undefined8 *)(param_1 + 0x50) = 0;
    if (*(char *)(param_1 + 0x5c) != '\0') {
      *(undefined1 *)(param_1 + 0x5c) = 0;
    }
    RtlRbRemoveNode(&CiSchedulerDeadlineQueue,uVar1);
    if (CiSchedulerTimerNode == uVar1) {
      CiSchedulerTimerNode = 2;
    }
  }
  *(undefined1 *)(param_1 + 0x5c) = 0;
  *(ulonglong *)(param_1 + 0x50) = param_2 + uVar3;
  puVar6 = CiSchedulerDeadlineQueue;
  if ((DAT_140009278 & 1) == 0) {
LAB_140003434:
    uVar9 = 0;
    if (puVar6 != (ulonglong *)0x0) {
      while (param_2 + uVar3 < puVar6[3]) {
        puVar4 = (ulonglong *)*puVar6;
        if ((DAT_140009278 & 1) != 0) {
          if (puVar4 == (ulonglong *)0x0) goto LAB_140003460;
          puVar4 = (ulonglong *)((ulonglong)puVar4 ^ (ulonglong)puVar6);
        }
        if (puVar4 == (ulonglong *)0x0) goto LAB_140003460;
LAB_14000368d:
        puVar6 = puVar4;
      }
      puVar4 = (ulonglong *)puVar6[1];
      if ((DAT_140009278 & 1) == 0) {
LAB_140003688:
        if (puVar4 != (ulonglong *)0x0) goto LAB_14000368d;
      }
      else if (puVar4 != (ulonglong *)0x0) {
        puVar4 = (ulonglong *)((ulonglong)puVar4 ^ (ulonglong)puVar6);
        goto LAB_140003688;
      }
      uVar9 = 1;
    }
  }
  else {
    if (CiSchedulerDeadlineQueue != (ulonglong *)0x0) {
      puVar6 = (ulonglong *)((ulonglong)CiSchedulerDeadlineQueue ^ 0x140009270);
      goto LAB_140003434;
    }
    puVar6 = (ulonglong *)0x0;
    uVar9 = 0;
  }
LAB_140003460:
  RtlRbInsertNodeEx(&CiSchedulerDeadlineQueue,puVar6,uVar9,uVar1);
  if ((*(char *)(param_1 + 0x84) != '\0') && (*(longlong *)(param_1 + 0x78) != 0)) {
    *(undefined8 *)(param_1 + 0x78) = 0;
    if (*(char *)(param_1 + 0x84) != '\0') {
      *(undefined1 *)(param_1 + 0x84) = 0;
    }
    RtlRbRemoveNode(&CiSchedulerDeadlineQueue,param_1 + 0x60U);
    if (CiSchedulerTimerNode == param_1 + 0x60U) {
      CiSchedulerTimerNode = 2;
    }
  }
  if ((int)uVar7 == -1) {
    *(undefined1 *)(param_1 + 0x84) = 0;
  }
  else {
    *(undefined1 *)(param_1 + 0x84) = 1;
    *(ulonglong *)(param_1 + 0x78) = uVar7 + uVar3;
    puVar6 = CiSchedulerDeadlineQueue;
    if ((DAT_140009278 & 1) == 0) {
LAB_1400034eb:
      uVar9 = 0;
      if (puVar6 != (ulonglong *)0x0) {
        while (uVar7 + uVar3 < puVar6[3]) {
          puVar4 = (ulonglong *)*puVar6;
          if ((DAT_140009278 & 1) != 0) {
            if (puVar4 == (ulonglong *)0x0) goto LAB_140003517;
            puVar4 = (ulonglong *)((ulonglong)puVar4 ^ (ulonglong)puVar6);
          }
          if (puVar4 == (ulonglong *)0x0) goto LAB_140003517;
LAB_1400036a2:
          puVar6 = puVar4;
        }
        puVar4 = (ulonglong *)puVar6[1];
        if ((DAT_140009278 & 1) == 0) {
LAB_14000369d:
          if (puVar4 != (ulonglong *)0x0) goto LAB_1400036a2;
        }
        else if (puVar4 != (ulonglong *)0x0) {
          puVar4 = (ulonglong *)((ulonglong)puVar4 ^ (ulonglong)puVar6);
          goto LAB_14000369d;
        }
        uVar9 = 1;
      }
    }
    else {
      if (CiSchedulerDeadlineQueue != (ulonglong *)0x0) {
        puVar6 = (ulonglong *)((ulonglong)CiSchedulerDeadlineQueue ^ 0x140009270);
        goto LAB_1400034eb;
      }
      puVar6 = (ulonglong *)0x0;
      uVar9 = 0;
    }
LAB_140003517:
    RtlRbInsertNodeEx(&CiSchedulerDeadlineQueue,puVar6,uVar9);
  }
  uVar7 = CiSchedulerTimerNode;
  for (puVar2 = *(undefined8 **)(param_1 + 0x20); puVar2 != (undefined8 *)(param_1 + 0x20);
      puVar2 = (undefined8 *)*puVar2) {
    CiSchedulerTimerNode = uVar7;
    if ((*(byte *)((longlong)puVar2 + 0x44) & 1) == 0) {
      if (CiThreadsMovedUp == '\0') {
        uVar5 = (uint)*(byte *)((longlong)puVar2 + 0x1a);
      }
      else {
        lVar8 = puVar2[-1];
        if ((*(longlong *)(lVar8 + 0x78) == 0) &&
           ((*(char *)(lVar8 + 0x84) != '\0' || (*(longlong *)(lVar8 + 0x50) == 0)))) {
          uVar5 = (uint)*(byte *)(puVar2 + 3);
        }
        else {
          uVar5 = (uint)*(byte *)(puVar2[-2] + 0x28);
          if (*(byte *)(puVar2 + 3) < *(byte *)(puVar2[-2] + 0x28)) {
            uVar5 = (uint)*(byte *)(puVar2 + 3);
          }
        }
      }
      if (*(byte *)((longlong)puVar2 + 0x1b) != uVar5) {
        *(char *)((longlong)puVar2 + 0x1b) = (char)uVar5;
        if (DAT_1400090d0 != '\0') {
          CiLogSchedulerEvent((longlong)(puVar2 + -10),uVar5);
        }
        KeSetActualBasePriorityThread(puVar2[2],uVar5);
      }
    }
    uVar7 = CiSchedulerTimerNode;
  }
  if ((DAT_140009278 & 1) == 0) {
    CiSchedulerTimerNode = DAT_140009278;
LAB_1400035b7:
    if (CiSchedulerTimerNode != 0) {
      if (CiSchedulerTimerNode != uVar7) {
        if (*(ulonglong *)(CiSchedulerTimerNode + 0x18) < uVar3) {
          lVar8 = 0;
        }
        else {
          lVar8 = uVar3 - *(ulonglong *)(CiSchedulerTimerNode + 0x18);
          if (lVar8 < -2000) {
            lVar8 = lVar8 + 2000;
          }
        }
        ExSetTimer(CiSchedulerTimer,lVar8,0,&CiSchedulerNoWakeTimerParams);
        uVar7 = CiSchedulerTimerNode;
      }
      goto LAB_140003610;
    }
  }
  else if (DAT_140009278 != 1) {
    CiSchedulerTimerNode = DAT_140009278 ^ 0x140009271;
    goto LAB_1400035b7;
  }
  if (uVar7 != 1) {
    CiSchedulerTimerNode = 1;
    ExCancelTimer(CiSchedulerTimer,0);
    uVar7 = CiSchedulerTimerNode;
  }
LAB_140003610:
  CiSchedulerTimerNode = uVar7;
  uVar5 = *(uint *)(param_1 + 0xb8);
  if ((uVar5 & 0x20) != 0) {
    uVar5 = uVar5 & 0xffffffdf;
    CiTotalTasksDeadlineExpired = CiTotalTasksDeadlineExpired + -1;
    *(uint *)(param_1 + 0xb8) = uVar5;
  }
  if ((uVar5 & 0x10) != 0) {
    *(uint *)(param_1 + 0xb8) = uVar5 & 0xffffffef;
  }
  CiSchedulerRefreshTaskIndexQosProperties(param_1);
  _DAT_1400091c8 = (void *)0x0;
  KeReleaseSpinLock(&CiSchedulerLock,0);
  return;
}



===== CiLogSchedulerEvent @ 140003860 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CiLogSchedulerEvent(longlong param_1,undefined4 param_2)

{
  undefined4 local_res10 [6];
  undefined1 auStack_98 [32];
  undefined8 **local_78;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 *local_58;
  undefined8 local_50;
  undefined8 *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  longlong local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_98;
  local_res10[0] = param_2;
  local_68 = PsGetThreadProcessId(*(undefined8 *)(param_1 + 0x60));
  local_60 = PsGetThreadId(*(undefined8 *)(param_1 + 0x60));
  local_58 = &local_68;
  local_50 = 4;
  local_48 = &local_60;
  local_40 = 4;
  local_38 = local_res10;
  local_28 = *(longlong *)(param_1 + 0x48) + 0x90;
  local_30 = 1;
  local_78 = &local_58;
  local_20 = 4;
  EtwWrite(DAT_1400090c8,&CiSchedulerPriorityEvent,0,4);
  return;
}



===== CiLogTaskIndexDeadlineExpired @ 140003950 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CiLogTaskIndexDeadlineExpired(longlong param_1)

{
  undefined1 auStack_58 [32];
  longlong *local_38;
  longlong local_28 [5];
  
  local_28[2] = __security_cookie ^ (ulonglong)auStack_58;
  local_28[0] = param_1 + 0x90;
  local_28[1] = 4;
  local_38 = local_28;
  EtwWrite(DAT_1400090c8,&CiTaskIndexDeadlineExpiredEvent,0,1);
  return;
}



===== CiLogTaskIndexPreDeadlineExpired @ 1400039c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CiLogTaskIndexPreDeadlineExpired(longlong param_1)

{
  undefined1 auStack_58 [32];
  longlong *local_38;
  longlong local_28 [5];
  
  local_28[2] = __security_cookie ^ (ulonglong)auStack_58;
  local_28[0] = param_1 + 0x90;
  local_28[1] = 4;
  local_38 = local_28;
  EtwWrite(DAT_1400090c8,&CiTaskIndexPreDeadlineExpiredEvent,0,1);
  return;
}



===== CiSystemAcquireSpinLock @ 140003a30 =====

void CiSystemAcquireSpinLock(longlong param_1)

{
  KeAcquireSpinLockRaiseToDpc();
  *(void **)(param_1 + 8) = SystemReserved1[0xf];
  return;
}



===== CiThreadNotification @ 140003a60 =====

void CiThreadNotification(undefined8 param_1,undefined8 param_2,char param_3)

{
  longlong *plVar1;
  
  if ((param_3 == '\0') &&
     (plVar1 = CiThreadLocate((ulonglong)SystemReserved1[0xf]), plVar1 != (longlong *)0x0)) {
    CiThreadCleanup((longlong)plVar1);
    CiThreadDereference((longlong)plVar1);
  }
  return;
}



===== CiThreadLocate @ 140003ab0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * CiThreadLocate(ulonglong param_1)

{
  longlong lVar1;
  code *pcVar2;
  longlong *plVar3;
  longlong *plVar4;
  undefined1 *puVar5;
  longlong *plVar6;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  plVar6 = (longlong *)0x0;
  KeAcquireSpinLockRaiseToDpc(&CiThreadTreeLock);
  puVar5 = auStack_28;
  _DAT_1400091d8 = SystemReserved1[0xf];
  plVar3 = CiThreadTree;
  if ((DAT_1400091e8 & 1) != 0) {
    if (CiThreadTree == (longlong *)0x0) goto LAB_140003b2b;
    plVar3 = (longlong *)((ulonglong)CiThreadTree ^ 0x1400091e0);
  }
  puVar5 = auStack_28;
  if (plVar3 != (longlong *)0x0) {
    do {
      if (param_1 < (ulonglong)plVar3[7]) {
        plVar4 = (longlong *)*plVar3;
        if (((DAT_1400091e8 & 1) != 0) && (plVar4 != (longlong *)0x0)) goto LAB_140003b5f;
LAB_140003b1e:
        plVar3 = plVar4;
      }
      else {
        if (param_1 <= (ulonglong)plVar3[7]) break;
        plVar4 = (longlong *)plVar3[1];
        if (((DAT_1400091e8 & 1) == 0) || (plVar4 == (longlong *)0x0)) goto LAB_140003b1e;
LAB_140003b5f:
        plVar3 = (longlong *)((ulonglong)plVar3 ^ (ulonglong)plVar4);
      }
    } while (plVar3 != (longlong *)0x0);
    puVar5 = auStack_28;
    if (plVar3 != (longlong *)0x0) {
      plVar6 = plVar3 + -5;
      LOCK();
      plVar3 = plVar3 + -1;
      lVar1 = *plVar3;
      *plVar3 = *plVar3 + 1;
      UNLOCK();
      puVar5 = auStack_28;
      if (lVar1 + 1 < 2) {
        pcVar2 = (code *)swi(0x29);
        (*pcVar2)(0xe);
        puVar5 = auStack_20;
      }
    }
  }
LAB_140003b2b:
  _DAT_1400091d8 = (void *)0x0;
  *(undefined8 *)(puVar5 + -8) = 0x140003b46;
  KeReleaseSpinLock(&CiThreadTreeLock,0);
  return plVar6;
}



===== CiSystemUpdateMediaBufferingState @ 140003ba0 =====

void CiSystemUpdateMediaBufferingState(void)

{
  bool bVar1;
  
  bVar1 = CiTotalTasksBuffering != 0;
  if ((bVar1 != (bool)CiCurrentMediaBufferingState) &&
     ((!bVar1 || (CiTotalTasksDeadlineExpired == 0)))) {
    CiCurrentMediaBufferingState = bVar1;
    PoNotifyMediaBuffering();
  }
  return;
}



===== CiThreadInsertInTree @ 140003bf0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte CiThreadInsertInTree(longlong param_1)

{
  undefined8 uVar1;
  longlong *plVar2;
  longlong *plVar3;
  byte bVar4;
  
  KeAcquireSpinLockRaiseToDpc(&CiThreadTreeLock);
  bVar4 = 0;
  _DAT_1400091d8 = SystemReserved1[0xf];
  uVar1 = 0;
  plVar3 = CiThreadTree;
  if (CiThreadTree != (longlong *)0x0) {
    do {
      if ((ulonglong)plVar3[7] < *(ulonglong *)(param_1 + 0x60)) {
        plVar2 = (longlong *)plVar3[1];
        if (plVar2 == (longlong *)0x0) {
          uVar1 = 1;
          break;
        }
      }
      else {
        if ((ulonglong)plVar3[7] <= *(ulonglong *)(param_1 + 0x60)) {
          bVar4 = 1;
          goto LAB_140003c3e;
        }
        plVar2 = (longlong *)*plVar3;
        if (plVar2 == (longlong *)0x0) goto LAB_140003ca5;
      }
      plVar3 = plVar2;
    } while( true );
  }
LAB_140003c7b:
  RtlRbInsertNodeEx(&CiThreadTree,plVar3,uVar1,param_1 + 0x28);
LAB_140003c3e:
  _DAT_1400091d8 = (void *)0x0;
  KeReleaseSpinLock(&CiThreadTreeLock,0);
  return bVar4 ^ 1;
LAB_140003ca5:
  uVar1 = 0;
  goto LAB_140003c7b;
}



===== CiTaskIndexDereference @ 140003cb0 =====

void CiTaskIndexDereference(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  code *pcVar4;
  longlong lVar5;
  undefined1 *puVar6;
  bool bVar7;
  undefined8 uStack_30;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  puVar6 = auStack_28;
  lVar5 = *(longlong *)(param_1 + 0x30);
  do {
    lVar1 = lVar5 + -1;
    if (lVar1 < 1) {
      if (lVar1 != 0) {
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(0xe);
        puVar6 = auStack_20;
      }
      *(undefined8 *)(puVar6 + -8) = 0x140003ce0;
      CiAcquireTaskIndexListLock();
      LOCK();
      plVar2 = (longlong *)(param_1 + 0x30);
      lVar5 = *plVar2;
      *plVar2 = *plVar2 + -1;
      UNLOCK();
      if (lVar5 < 2) {
        if (lVar5 == 1) {
          *(undefined8 *)(puVar6 + -8) = 0x140003d00;
          CiTaskIndexRemove(param_1);
          *(undefined8 *)(puVar6 + -8) = 0x140003d05;
          CiReleaseTaskIndexListLock();
          if (param_1 == 0) {
            return;
          }
          *(undefined8 *)(puVar6 + -8) = 0x140003d12;
          CiSchedulerRemoveTaskIndex(param_1);
          *(undefined8 *)(puVar6 + -8) = 0x140003d1e;
          ExFreePoolWithTag(param_1,0);
          return;
        }
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(0xe);
        puVar6 = puVar6 + 8;
      }
      *(undefined8 *)(puVar6 + -8) = 0x140003d3f;
      CiReleaseTaskIndexListLock();
      return;
    }
    LOCK();
    lVar3 = *(longlong *)(param_1 + 0x30);
    bVar7 = lVar5 == lVar3;
    if (bVar7) {
      *(longlong *)(param_1 + 0x30) = lVar1;
    }
    else {
      lVar5 = lVar3;
    }
    UNLOCK();
  } while (!bVar7);
  return;
}



===== CiSchedulerRemoveTaskIndex @ 140003d50 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CiSchedulerRemoveTaskIndex(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  bool bVar3;
  undefined8 local_res8;
  
  local_res8 = 0;
  uVar2 = KeQueryInterruptTimePrecise(&local_res8);
  KeAcquireSpinLockRaiseToDpc(&CiSchedulerLock);
  _DAT_1400091c8 = SystemReserved1[0xf];
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) & 0xfffffff7;
  bVar3 = *(longlong *)(param_1 + 0x50) != 0;
  if (bVar3) {
    CiSchedulerRemoveDeadline(param_1 + 0x38);
  }
  if (*(longlong *)(param_1 + 0x78) == 0) {
    if (!bVar3) goto LAB_140003dc8;
  }
  else {
    CiSchedulerRemoveDeadline(param_1 + 0x60);
  }
  CiSchedulerUpdateTimer(uVar2);
LAB_140003dc8:
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) & 0xfffffffd;
  uVar1 = *(uint *)(param_1 + 0xb8);
  if ((uVar1 & 0x20) != 0) {
    uVar1 = uVar1 & 0xffffffdf;
    CiTotalTasksDeadlineExpired = CiTotalTasksDeadlineExpired + -1;
    *(uint *)(param_1 + 0xb8) = uVar1;
  }
  if ((uVar1 & 0x10) != 0) {
    *(uint *)(param_1 + 0xb8) = uVar1 & 0xffffffef;
  }
  CiSchedulerRefreshTaskIndexQosProperties(param_1);
  _DAT_1400091c8 = (void *)0x0;
  KeReleaseSpinLock(&CiSchedulerLock,0);
  return;
}



===== CiTryIncrementTotalThreadCount @ 140003e60 =====

undefined8 CiTryIncrementTotalThreadCount(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  iVar2 = *param_1;
  do {
    if (param_2 <= iVar2) {
      return 0xc0000129;
    }
    LOCK();
    iVar1 = *param_1;
    bVar3 = iVar2 == iVar1;
    if (bVar3) {
      *param_1 = iVar2 + 1;
    }
    else {
      iVar2 = iVar1;
    }
    UNLOCK();
  } while (!bVar3);
  return 0;
}



===== CiDecrementTotalThreadCount @ 140003e90 =====

void CiDecrementTotalThreadCount(int *param_1)

{
  LOCK();
  *param_1 = *param_1 + -1;
  UNLOCK();
  return;
}



===== CiThreadRemoveFromTree @ 140003ea0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CiThreadRemoveFromTree(longlong param_1)

{
  KeAcquireSpinLockRaiseToDpc(&CiThreadTreeLock);
  _DAT_1400091d8 = SystemReserved1[0xf];
  RtlRbRemoveNode(&CiThreadTree,param_1 + 0x28);
  _DAT_1400091d8 = (void *)0x0;
  KeReleaseSpinLock(&CiThreadTreeLock,0);
  return;
}



===== CiSchedulerPoke @ 140003f10 =====

void CiSchedulerPoke(uint param_1)

{
  uint uVar1;
  bool bVar2;
  
  if (param_1 != 0) {
    uVar1 = CiSchedulerWakeupReason;
    do {
      LOCK();
      bVar2 = uVar1 == CiSchedulerWakeupReason;
      if (bVar2) {
        CiSchedulerWakeupReason = uVar1 | param_1;
      }
      else {
        uVar1 = CiSchedulerWakeupReason;
      }
      UNLOCK();
    } while (!bVar2);
    if ((uVar1 >> 0xf & 1) == 0) {
      return;
    }
  }
  KeAlertThread(CiSchedulerThread,0);
  return;
}



===== CiAllocateMemory @ 140003f60 =====

void CiAllocateMemory(undefined8 param_1)

{
  ExAllocatePool2(0x40,param_1,0x74727641);
  return;
}



===== CiThreadReferenceTaskIndex @ 140003f90 =====

longlong CiThreadReferenceTaskIndex(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  code *pcVar3;
  longlong lVar4;
  undefined1 *puVar5;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  lVar4 = 0;
  CiAcquireThreadLock(param_1);
  puVar5 = auStack_28;
  if ((*(byte *)(param_1 + 0x94) & 2) == 0) {
    lVar4 = *(longlong *)(param_1 + 0x48);
    LOCK();
    plVar1 = (longlong *)(lVar4 + 0x30);
    lVar2 = *plVar1;
    *plVar1 = *plVar1 + 1;
    UNLOCK();
    puVar5 = auStack_28;
    if (lVar2 + 1 < 2) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(0xe);
      puVar5 = auStack_20;
    }
  }
  *(undefined8 *)(puVar5 + -8) = 0x140003fcd;
  CiReleaseThreadLock(param_1);
  return lVar4;
}



===== CiFreeMemory @ 140003ff0 =====

void CiFreeMemory(undefined8 param_1)

{
  ExFreePoolWithTag(param_1,0);
  return;
}



===== CiLogSchedulerWakeup @ 140004010 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CiLogSchedulerWakeup(undefined4 param_1)

{
  undefined4 local_res8 [8];
  undefined1 auStack_58 [32];
  undefined4 **local_38;
  undefined4 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  local_28 = local_res8;
  local_38 = &local_28;
  local_20 = 4;
  local_res8[0] = param_1;
  EtwWrite(DAT_1400090c8,&CiSchedulerWakeupEvent,0,1);
  return;
}



===== CiTaskIndexReference @ 140004080 =====

void CiTaskIndexReference(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  code *pcVar3;
  
  LOCK();
  plVar1 = (longlong *)(param_1 + 0x30);
  lVar2 = *plVar1;
  *plVar1 = *plVar1 + 1;
  UNLOCK();
  if (lVar2 + 1 < 2) {
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(0xe);
    return;
  }
  return;
}



===== CiLogSchedulerSleep @ 1400040b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CiLogSchedulerSleep(undefined4 param_1,undefined4 param_2)

{
  undefined4 local_res8 [2];
  undefined4 local_res10 [6];
  undefined1 auStack_68 [32];
  undefined4 **local_48;
  undefined4 *local_38;
  undefined8 local_30;
  undefined4 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  local_38 = local_res8;
  local_28 = local_res10;
  local_30 = 4;
  local_48 = &local_38;
  local_20 = 4;
  local_res8[0] = param_1;
  local_res10[0] = param_2;
  EtwWrite(DAT_1400090c8,&CiSchedulerSleepEvent,0,2);
  return;
}



===== CiLogSetBufferingMode @ 140004140 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CiLogSetBufferingMode(longlong param_1,undefined4 param_2)

{
  undefined4 local_res10 [6];
  undefined1 auStack_68 [32];
  longlong *local_48;
  longlong local_38 [2];
  undefined4 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  local_38[0] = param_1 + 0x90;
  local_38[1] = 4;
  local_28 = local_res10;
  local_20 = 4;
  local_48 = local_38;
  local_res10[0] = param_2;
  EtwWrite(DAT_1400090c8,&CiSetMultimediaModeEvent,0,2);
  return;
}



===== CiLogTurboEngaged @ 1400041d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CiLogTurboEngaged(void)

{
  undefined1 auStack_58 [32];
  undefined4 **local_38;
  undefined4 local_28 [2];
  undefined4 *local_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  local_20 = local_28;
  local_38 = &local_20;
  local_28[0] = 1;
  local_18 = 4;
  EtwWrite(DAT_1400090c8,&CiTurboEngagedEvent,0,1);
  return;
}



===== CiSchedulerSetMultimediaMode @ 140004244 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 CiSchedulerSetMultimediaMode(longlong param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (param_2 == 0) {
    uVar1 = 3;
    uVar2 = 0;
  }
  else {
    if (param_2 != 1) {
      return 0xc000000d;
    }
    uVar1 = 1;
    uVar2 = 2;
  }
  if ((*(byte *)(*(longlong *)(param_1 + 0x88) + 3) & 1) != 0) {
    if (DAT_1400090d0 != '\0') {
      CiLogSetBufferingMode(param_1,uVar1);
    }
    KeAcquireSpinLockRaiseToDpc(&CiSchedulerLock);
    _DAT_1400091c8 = SystemReserved1[0xf];
    *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) & 0xfffffffd | uVar2 | 1;
    CiSchedulerRefreshTaskIndexQosProperties(param_1);
    _DAT_1400091c8 = (void *)0x0;
    KeReleaseSpinLock(&CiSchedulerLock,0);
  }
  return 0;
}



===== CiSchedulerRefreshTaskIndexQosProperties @ 14000430c =====

void CiSchedulerRefreshTaskIndexQosProperties(longlong param_1)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  undefined8 *puVar5;
  
  uVar1 = *(uint *)(param_1 + 0xb8);
  iVar2 = *(int *)(param_1 + 0xc0);
  if ((uVar1 & 1) == 0) {
LAB_140004365:
    iVar4 = 3;
  }
  else {
    if ((uVar1 & 0x20) == 0) {
      if (((uVar1 & 0x10) == 0) && ((uVar1 & 2) != 0)) {
        iVar4 = 1;
        bVar3 = true;
        goto LAB_14000436d;
      }
      goto LAB_140004365;
    }
    iVar4 = 2;
  }
  bVar3 = false;
LAB_14000436d:
  if (((uVar1 & 4) == 0) && (bVar3)) {
    CiTotalTasksBuffering = CiTotalTasksBuffering + 1;
    *(uint *)(param_1 + 0xb8) = uVar1 | 4;
    CiSystemUpdateMediaBufferingState();
  }
  if (iVar4 != iVar2) {
    *(int *)(param_1 + 0xc0) = iVar4;
    for (puVar5 = *(undefined8 **)(param_1 + 0x20); puVar5 != (undefined8 *)(param_1 + 0x20);
        puVar5 = (undefined8 *)*puVar5) {
      if (DAT_1400090d0 != '\0') {
        CiLogThreadBuffering((longlong)(puVar5 + -10),(uint)(iVar4 == 1));
      }
      KeUpdateThreadTag(puVar5[2],iVar4);
    }
  }
  if (((uVar1 & 4) != 0) && (!bVar3)) {
    *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) & 0xfffffffb;
    CiTotalTasksBuffering = CiTotalTasksBuffering + -1;
    CiSystemUpdateMediaBufferingState();
  }
  return;
}



===== CiLogThreadJoin @ 140004420 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CiLogThreadJoin(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 auStack_d8 [32];
  undefined8 **local_b8;
  byte local_a8;
  byte local_a7 [7];
  undefined8 local_a0;
  undefined8 *local_98;
  undefined8 local_90;
  longlong local_88;
  undefined8 local_80;
  longlong local_78;
  undefined8 local_70;
  longlong local_68;
  undefined8 local_60;
  longlong local_58;
  int local_50;
  undefined4 local_4c;
  longlong local_48;
  undefined8 local_40;
  byte *local_38;
  undefined8 local_30;
  byte *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_d8;
  local_a0 = PsGetThreadId(*(undefined8 *)(param_1 + 0x60));
  lVar2 = *(longlong *)(param_1 + 0x48);
  local_98 = &local_a0;
  local_88 = param_1 + 0x68;
  local_78 = param_1 + 0x69;
  local_68 = param_1 + 0x6a;
  local_90 = 4;
  local_80 = 1;
  local_70 = 1;
  local_60 = 1;
  local_58 = *(longlong *)(*(longlong *)(lVar2 + 0x88) + 0x18);
  lVar3 = -1;
  do {
    lVar1 = lVar3 * 2;
    lVar3 = lVar3 + 1;
  } while (*(short *)(local_58 + 2 + lVar1) != 0);
  local_50 = (int)lVar3 * 2 + 2;
  local_4c = 0;
  local_48 = lVar2 + 0x90;
  local_40 = 4;
  local_38 = &local_a8;
  local_a8 = *(byte *)(*(longlong *)(lVar2 + 0x88) + 3) >> 4 & 7;
  local_30 = 1;
  local_28 = local_a7;
  local_a7[0] = *(byte *)(*(longlong *)(lVar2 + 0x88) + 3) & 0x1f;
  local_b8 = &local_98;
  local_20 = 1;
  EtwWrite(DAT_1400090c8,&CiThreadJoinEvent,0,8);
  return;
}



===== CiLogThreadLeave @ 140004580 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CiLogThreadLeave(longlong param_1)

{
  undefined1 auStack_68 [32];
  undefined8 **local_48;
  undefined8 local_38;
  undefined8 *local_30;
  undefined8 local_28;
  longlong local_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  local_38 = PsGetThreadId(*(undefined8 *)(param_1 + 0x60));
  local_30 = &local_38;
  local_28 = 4;
  local_20 = param_1 + 0x90;
  local_18 = 1;
  local_48 = &local_30;
  EtwWrite(DAT_1400090c8,&CiThreadLeaveEvent,0,2);
  return;
}



===== WPP_SF_ @ 140004620 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,0);
  return;
}



===== __report_gsfailure @ 140004660 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __report_rangecheckfailure @ 140004670 =====

void __report_rangecheckfailure(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(8);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 14000467d =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000467d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== CiLogTaskIndexCancelYield @ 140004690 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CiLogTaskIndexCancelYield(longlong param_1)

{
  undefined1 auStack_58 [32];
  longlong *local_38;
  longlong local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  local_1c = 0;
  local_28 = param_1 + 0x90;
  local_38 = &local_28;
  local_20 = 4;
  EtwWrite(DAT_1400090c8,&CiTaskIndexYieldCancelEvent,0,1);
  return;
}



===== WPP_SF_D @ 140004704 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_D(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_59b4788dc7e93d268b2cbb08d31d0951_Traceguids,10,local_res20,4,0);
  return;
}



===== WPP_SF_Sd @ 140004750 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Sd(undefined8 param_1,undefined2 param_2,undefined8 param_3,wchar_t *param_4,
              undefined1 param_5)

{
  longlong lVar1;
  
  if (param_4 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"NULL";
  }
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,param_4,lVar1,&param_5,4,0);
  return;
}



===== WPP_SF_Z @ 1400047d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Z(undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  
  if (param_4 == (wchar_t *)0x0) {
    wVar1 = L'\b';
  }
  else {
    wVar1 = *param_4;
    if (*param_4 != L'\0') {
      pwVar2 = *(wchar_t **)(param_4 + 4);
      goto LAB_1400047fc;
    }
  }
  pwVar2 = L"NULL";
LAB_1400047fc:
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"\b";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_8f5427380d7633b566e62dbddd286985_Traceguids,10,param_4,2,pwVar2,wVar1
             ,0);
  return;
}



===== WPP_SF_Zd @ 140004854 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Zd(undefined8 param_1,undefined2 param_2,undefined8 param_3,wchar_t *param_4,
              undefined1 param_5)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  
  if (param_4 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *param_4;
    if (*param_4 != L'\0') {
      pwVar1 = *(wchar_t **)(param_4 + 4);
      goto LAB_140004881;
    }
  }
  pwVar1 = L"NULL";
LAB_140004881:
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"\b";
  }
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,param_4,2,pwVar1,wVar2,&param_5,4,0);
  return;
}



===== WPP_SF_Zq @ 1400048e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Zq(undefined8 param_1)

{
  undefined8 local_18 [3];
  
  local_18[0] = CiDeviceObject;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_8f5427380d7633b566e62dbddd286985_Traceguids,0x15,&CiDeviceName,2,
             L"\\Device\\MMCSS",0x1a,local_18,8,0);
  return;
}



===== WPP_SF_l @ 140004960 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_l(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== WPP_SF_dd @ 1400049a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_8f5427380d7633b566e62dbddd286985_Traceguids,param_2,local_res20,4,
             &param_5,4,0);
  return;
}



===== WPP_SF_q @ 1400049fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_8f5427380d7633b566e62dbddd286985_Traceguids,0xe,&local_res20,8,0);
  return;
}



===== WppClassicProviderCallback @ 140004a50 =====

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



===== wil_details_FeatureDescriptors_SkipPadding @ 140004a84 =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_14000881f < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_RecordCachedUsage @ 140004aac =====

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



===== wil_details_RecordFeatureUsageReporting @ 140004c00 =====

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



===== WPP_SF_P @ 140004c84 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_P(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_62da978b8000316eb1e6fce22b5cf66e_Traceguids,0x11,&local_res20,8,0);
  return;
}



===== WPP_SF_S @ 140004cd0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_S(undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4)

{
  longlong lVar1;
  
  if (param_4 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_62da978b8000316eb1e6fce22b5cf66e_Traceguids,0xb,param_4,lVar1,0);
  return;
}



===== WPP_SF_dI @ 140004d48 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dI(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_29026e0d014631895ac1404d49971dec_Traceguids,0xb,local_res20,4,
             &param_5,8,0);
  return;
}



===== WPP_SF_qqd @ 140004da4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_0f961914fea93012ea63c8b8118ed7e5_Traceguids,10,&local_res20,8,
             &param_5,8,&param_6,4,0);
  return;
}



===== WPP_SF_L @ 140004e0c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_L(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_350503daac883abe7be9cf63f89038d9_Traceguids,0xb,local_res20,4,0);
  return;
}



===== CiSchedulerQueryTaskIndexDebugInformation @ 140004e58 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CiSchedulerQueryTaskIndexDebugInformation(longlong param_1,uint *param_2)

{
  *param_2 = 0;
  CiSystemAcquireSpinLock(0x1400091c0);
  *param_2 = (*(uint *)(param_1 + 0xb8) >> 2 ^ *param_2) & 1 ^ *param_2;
  _DAT_1400091c8 = 0;
  KeReleaseSpinLock(&CiSchedulerLock,0);
  return;
}



===== _guard_check_icall @ 140004ed0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140004ee8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140004f0c =====

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



===== __GSHandlerCheck_SEH @ 140004f74 =====

void __GSHandlerCheck_SEH
               (_EXCEPTION_RECORD *param_1,void *param_2,_CONTEXT *param_3,
               _DISPATCHER_CONTEXT *param_4)

{
  uint uVar1;
  uint *puVar2;
  
  puVar2 = *(uint **)(param_4 + 0x38);
  uVar1 = *puVar2;
  __GSHandlerCheckCommon(param_2,(longlong)param_4);
  if ((puVar2[(ulonglong)uVar1 * 4 + 1] & ((param_1->ExceptionFlags & 0x66) != 0) + 1) != 0) {
    __C_specific_handler(param_1,param_2,param_3,param_4);
  }
  return;
}



===== __cpu_features_init @ 140005010 =====

/* WARNING: Removing unreachable block (ram,0x00014000507a) */
/* WARNING: Removing unreachable block (ram,0x000140005029) */
/* WARNING: Removing unreachable block (ram,0x00014000501a) */

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



===== __security_check_cookie @ 1400050e0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140005120 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140005150 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140005150. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140005180 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 140005200 =====

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



===== memset @ 140005500 =====

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



===== __memset_repmovs @ 140005640 =====

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



===== __memset_query @ 1400056c0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140005740 =====

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



===== __memset_spec_ermsb_repmovsb @ 140005880 =====

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



===== __memset_spec_plain @ 140005900 =====

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



===== WppLoadTracingSupport @ 14000c010 =====

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



===== WppInitKm @ 14000c160 =====

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



===== CiLogControlCallback @ 14000c200 =====

void CiLogControlCallback(undefined8 param_1,int param_2)

{
  if (param_2 == 0) {
    DAT_1400090c8 = 0;
    DAT_1400090d0 = 0;
    return;
  }
  DAT_1400090c8 = CiLoggerContext;
  DAT_1400090d0 = 1;
  return;
}



===== CiDispatchCreateNotificationClient @ 14000c240 =====

int CiDispatchCreateNotificationClient(longlong param_1,longlong param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined8 *puVar2;
  int iVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined8 *local_res8;
  
  uVar4 = PsGetCurrentProcess();
  lVar1 = *(longlong *)(param_2 + 0x30);
  iVar3 = 0;
  KeEnterCriticalRegion();
  local_res8 = CiProcessLocate(uVar4);
  if (local_res8 == (undefined8 *)0x0) {
    uVar5 = CiProcessCreate(&local_res8);
    iVar3 = (int)uVar5;
    if (iVar3 < 0) goto LAB_14000c308;
  }
  puVar2 = local_res8;
  CiSystemAcquirePushLock((longlong)(local_res8 + 2));
  if (puVar2[1] == 0) {
    puVar2[1] = lVar1;
  }
  else {
    iVar3 = -0x3fffffde;
  }
  puVar2[3] = 0;
  uVar5 = 0;
  ExReleasePushLockExclusiveEx(puVar2 + 2);
  if (iVar3 < 0) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,param_3,puVar2[1]);
    }
    CiProcessDereference((longlong)puVar2);
  }
  else {
    *(undefined8 **)(lVar1 + 0x18) = puVar2;
  }
LAB_14000c308:
  KeLeaveCriticalRegion();
  *(undefined8 *)(param_1 + 0x38) = 0;
  *(int *)(param_1 + 0x30) = iVar3;
  IofCompleteRequest(param_1,0);
  return iVar3;
}



===== CiDriverUnload @ 14000c350 =====

void CiDriverUnload(void)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
            &WPP_8f5427380d7633b566e62dbddd286985_Traceguids);
  }
  if (CiDeviceObject != 0) {
    IoDeleteDevice();
    CiDeviceObject = 0;
  }
  CsTerminate();
  wil_details_UnregisterFeatureStagingChangeNotification();
  wil_details_UnregisterFeatureUsageProvider();
  g_wil_details_isFeatureStagingInitialized = 0;
  return;
}



===== CiIsTestSigningEnabled @ 14000c3c0 =====

uint CiIsTestSigningEnabled(void)

{
  int iVar1;
  uint uVar2;
  undefined4 local_res8 [2];
  undefined8 local_res10;
  
  local_res8[0] = 0;
  local_res10 = 8;
  iVar1 = ZwQuerySystemInformation(0x67,&local_res10,8,local_res8);
  if (iVar1 < 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = local_res10._4_4_ >> 1 & 1;
  }
  return uVar2;
}



===== wil_details_UnregisterFeatureStagingChangeNotification @ 14000c410 =====

void wil_details_UnregisterFeatureStagingChangeNotification(void)

{
  if (g_wil_details_featureChangeNotification != 0) {
    RtlUnregisterFeatureConfigurationChangeNotification();
    g_wil_details_featureChangeNotification = 0;
  }
  return;
}



===== wil_details_UnregisterFeatureUsageProvider @ 14000c440 =====

void wil_details_UnregisterFeatureUsageProvider(void)

{
  if (g_wil_details_featureUsageProvider != 0) {
    RtlUnregisterFeatureUsageProvider();
    g_wil_details_featureUsageProvider = 0;
  }
  return;
}



===== CsTerminate @ 14000c470 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void CsTerminate(void)

{
  undefined8 *puVar1;
  code *pcVar2;
  undefined8 *puVar3;
  undefined *puVar4;
  undefined1 *puVar5;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  if (CiThreadCallbackRegistered != '\0') {
    PsRemoveCreateThreadNotifyRoutine(CiThreadNotification);
    CiThreadCallbackRegistered = '\0';
  }
  puVar5 = auStack_28;
  CiSchedulerTerminate();
  if (CiKernelExtensionRegistration != 0) {
    ExUnregisterExtension();
  }
  do {
    puVar3 = CiTaskListHead;
    if ((undefined8 **)CiTaskListHead == &CiTaskListHead) {
LAB_14000c502:
      *(undefined8 *)(puVar5 + -8) = 0x14000c507;
      CiSystemTerminate();
      *(undefined8 *)(puVar5 + -8) = 0x14000c50c;
      CiNdisCleanupThrottle();
      if (CiLoggerContext != 0) {
        *(undefined8 *)(puVar5 + -8) = 0x14000c51f;
        EtwUnregister();
        CiLoggerContext = 0;
      }
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        puVar4 = WPP_GLOBAL_Control;
        if (WPPTraceSuite == 4) {
          for (; puVar4 != (undefined *)0x0; puVar4 = *(undefined **)(puVar4 + 0x10)) {
            if (*(longlong *)(puVar4 + 0x38) != 0) {
              *(undefined8 *)(puVar5 + -8) = 0x14000c58b;
              (*pfnEtwUnregister)();
              *(undefined8 *)(puVar4 + 0x38) = 0;
            }
          }
        }
        else if (WPPTraceSuite == 2) {
          *(undefined8 *)(puVar5 + -8) = 0x14000c55e;
          IoWMIRegistrationControl(WPP_GLOBAL_Control,0x80000002);
        }
        WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
      }
      return;
    }
    if (((undefined8 **)CiTaskListHead[1] != &CiTaskListHead) ||
       (puVar1 = (undefined8 *)*CiTaskListHead, (undefined8 *)puVar1[1] != CiTaskListHead)) {
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(3);
      puVar5 = auStack_20;
      goto LAB_14000c502;
    }
    CiTaskListHead = puVar1;
    puVar1[1] = &CiTaskListHead;
    CiFreeMemory(puVar3[2]);
    CiFreeMemory(puVar3 + -1);
  } while( true );
}



===== WppTraceCallback @ 14000c5b0 =====

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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 14000c838 =====

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
      goto LAB_14000c895;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_14000c895;
    }
  }
  uVar1 = 0x206;
LAB_14000c895:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 14000c8a0 =====

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



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14000c958 =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 14000c990 =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_14000ca12;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_14000ca12;
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
LAB_14000ca12:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 14000ca60 =====

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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 14000cac0 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 14000cadc =====

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



===== CiNdisCleanupThrottle @ 14000cb90 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CiNdisCleanupThrottle(void)

{
  char local_res8 [32];
  
  if (CiNdisThrottleWorkItem != 0) {
    CiSystemAcquirePushLock(0x140009190);
    _DAT_140009198 = 0;
    local_res8[0] = CiNdisThrottleInProgress;
    ExReleasePushLockExclusiveEx(&CiThreadCountLock,0);
    if (local_res8[0] != '\0') {
      ExBlockOnAddressPushLock
                (&CiNdisThrottleInProgressPushLock,&CiNdisThrottleInProgress,local_res8,1,0);
      CiSystemAcquirePushLock(0x140009190);
      _DAT_140009198 = 0;
      ExReleasePushLockExclusiveEx(&CiThreadCountLock,0);
    }
    IoFreeWorkItem(CiNdisThrottleWorkItem);
    CiNdisThrottleWorkItem = 0;
    if (CiNdisDeviceHandle != 0) {
      ZwClose();
      CiNdisDeviceHandle = 0;
    }
  }
  return;
}



===== CiNdisOpenDevice @ 14000cc78 =====

int CiNdisOpenDevice(void)

{
  int iVar1;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_1c = 0;
  local_30 = 0;
  local_38 = 0x30;
  local_20 = 0x240;
  local_48 = 0;
  uStack_40 = 0;
  local_28 = &CiNdisDevceName;
  local_18 = 0;
  uStack_10 = 0;
  iVar1 = ZwOpenFile(&CiNdisDeviceHandle,0x12019f,&local_38,&local_48,7,0x20);
  if (((iVar1 < 0) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
             &WPP_8a12c31d698336a89006616b8d149517_Traceguids,iVar1);
  }
  return iVar1;
}



===== CiSystemTerminate @ 14000cd2c =====

void CiSystemTerminate(void)

{
  if (CiLastIdleStats != 0) {
    CiFreeMemory(CiLastIdleStats);
    CiLastIdleStats = 0;
  }
  return;
}



===== CiSchedulerTerminate @ 14000cd58 =====

void CiSchedulerTerminate(void)

{
  if (CiSchedulerThread != 0) {
    ObfReferenceObject();
    CiSchedulerPoke(8);
    CiSchedulerPoke(0);
    KeWaitForSingleObject(CiSchedulerThread,0,0,0,0);
    ObfDereferenceObject(CiSchedulerThread);
    CiSchedulerThread = 0;
  }
  if (CiSchedulerTimer != 0) {
    ExDeleteTimer(CiSchedulerTimer,1,0,0);
  }
  return;
}



===== CiDispatchFastIoDeviceControl @ 14000cdf0 =====

undefined8
CiDispatchFastIoDeviceControl
          (longlong param_1,undefined8 param_2,void *param_3,uint param_4,undefined4 *param_5,
          int param_6,uint param_7,int *param_8)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  void *_Size;
  void *_Size_00;
  undefined8 local_38;
  
  _Size_00 = (void *)(ulonglong)param_4;
  uVar5 = 0;
  local_38 = 0;
  iVar3 = -0x3ffffff3;
  _Size = param_3;
  KeEnterCriticalRegion();
  uVar6 = param_7 >> 2 & 0x7ff;
  uVar7 = (ulonglong)uVar6;
  if ((((uVar6 < 9) && ((param_7 & 0xffffe003) == 0x222003)) &&
      (piVar1 = *(int **)(param_1 + 0x18), *piVar1 == *(int *)(&CiApiTypeTable + uVar7 * 4))) &&
     ((param_4 == *(uint *)(&CiApiBufferSizeTable + uVar7 * 8) &&
      (param_6 == *(int *)(&DAT_1400086a4 + uVar7 * 8))))) {
    cVar2 = ExGetPreviousMode();
    if (cVar2 == '\0') {
      if (param_4 != 0) {
        memcpy(&local_38,param_3,(size_t)_Size_00);
        uVar5 = (uint)local_38;
        _Size = _Size_00;
      }
    }
    else {
      uVar5 = 0;
      if (param_4 != 0) {
        if (((ulonglong)param_3 & 3) != 0) {
                    /* WARNING: Subroutine does not return */
          ExRaiseDatatypeMisalignment();
        }
        _Size = (void *)(ulonglong)param_4;
        memcpy(&local_38,param_3,(size_t)_Size);
        uVar5 = (uint)local_38;
      }
      if (param_6 != 0) {
        _Size = (void *)0x4;
        ProbeForWrite(param_5,param_6);
      }
    }
    if (uVar6 == 5) {
      iVar3 = 0;
      _Size = (void *)(ulonglong)local_38._4_4_;
      CiSchedulerTaskIndexYield((longlong)piVar1,uVar5,local_38._4_4_);
    }
    else {
      if (uVar6 != 3) {
                    /* WARNING: Could not recover jumptable at 0x00014000cfca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar4 = (*(code *)(IMAGE_DOS_HEADER_140000000.e_magic +
                          *(uint *)(&DAT_140007480 + uVar7 * 4)))
                          (&IMAGE_DOS_HEADER_140000000,
                           IMAGE_DOS_HEADER_140000000.e_magic +
                           *(uint *)(&DAT_140007480 + uVar7 * 4));
        return uVar4;
      }
      iVar3 = CiCreateTaskIndexClientFromThread((longlong)piVar1,param_5);
    }
  }
  KeLeaveCriticalRegion();
  if (((iVar3 < 0) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,_Size,uVar6,(char)iVar3);
  }
  *param_8 = iVar3;
  param_8[2] = 0;
  param_8[3] = 0;
  return CONCAT71((int7)((ulonglong)param_8 >> 8),1);
}



===== CiCreateTaskIndexClientFromThread @ 14000d120 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int CiCreateTaskIndexClientFromThread(longlong param_1,undefined4 *param_2)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  undefined1 auStack_228 [32];
  undefined8 local_208;
  undefined4 local_200;
  undefined4 local_1f8;
  undefined4 local_1f0;
  undefined4 local_1e8;
  undefined8 *local_1e0;
  undefined4 local_1d8;
  undefined4 local_1d0;
  undefined8 local_1c8;
  undefined4 local_1c0;
  undefined8 local_1b8;
  int local_1a8;
  undefined8 local_1a0;
  longlong local_198;
  undefined4 local_190;
  undefined4 local_18c;
  undefined8 local_188;
  undefined *local_180;
  undefined4 local_178;
  undefined4 local_174;
  undefined8 local_170;
  undefined8 uStack_168;
  undefined8 local_160;
  undefined8 uStack_158;
  undefined8 local_148;
  undefined4 local_140;
  undefined4 local_13c;
  longlong local_138;
  undefined1 local_130 [264];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_228;
  local_13c = 0;
  memset(local_130,0,0xfc);
  local_160 = 0;
  uStack_158 = 0;
  local_18c = 0;
  local_174 = 0;
  local_1a0 = 0;
  lVar3 = CiThreadReferenceTaskIndex(param_1);
  if (lVar3 == 0) {
    iVar2 = -0x3ffffe77;
  }
  else {
    local_140 = 0;
    local_148 = 0x10f000000000000;
    local_198 = lVar3;
    local_138 = lVar3;
    cVar1 = ExGetPreviousMode();
    local_190 = 0x30;
    local_188 = 0;
    if (cVar1 == '\0') {
      local_178 = 0x200;
    }
    else {
      local_178 = 0;
    }
    local_180 = &CiTaskIndexClientName;
    local_170 = 0;
    uStack_168 = 0;
    local_1b8 = 0;
    local_1c0 = 0;
    local_1c8 = 0;
    local_1d0 = 0;
    local_1d8 = 0x118;
    local_1e0 = &local_148;
    local_1e8 = 0;
    local_1f0 = 0;
    local_1f8 = 0;
    local_200 = 0;
    local_208 = 0;
    iVar2 = IoCreateFileEx(&local_1a0,0x120089,&local_190,&local_160);
    local_1a8 = iVar2;
    if (iVar2 < 0) {
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                 &WPP_8f5427380d7633b566e62dbddd286985_Traceguids,iVar2);
      }
    }
    else if (cVar1 == '\0') {
      *param_2 = (undefined4)local_1a0;
    }
    else {
      *param_2 = (undefined4)local_1a0;
    }
    CiTaskIndexDereference(lVar3);
  }
  return iVar2;
}



===== CiDispatchCreateTaskIndexClient @ 14000d340 =====

int CiDispatchCreateTaskIndexClient(longlong param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  bool bVar3;
  int iVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  int iVar7;
  ulonglong uVar8;
  longlong lVar9;
  bool bVar10;
  longlong local_res8;
  undefined8 local_res10;
  
  uVar1 = *(uint *)(param_2 + 0x20);
  bVar3 = false;
  lVar2 = *(longlong *)(param_1 + 0x18);
  uVar8 = 0;
  iVar7 = -0x3ffffff3;
  iVar4 = -0x3ffffff3;
  if (uVar1 != 0x118) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,(ulonglong)uVar1,uVar1,0x18);
    }
    goto LAB_14000d40a;
  }
  lVar9 = *(longlong *)(lVar2 + 0x10);
  if ((lVar9 != 0) && (*(char *)(param_1 + 0x40) != '\0')) {
    iVar4 = iVar7;
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
              &WPP_8f5427380d7633b566e62dbddd286985_Traceguids);
    }
    goto LAB_14000d40a;
  }
  local_res10 = 0;
  local_res8 = lVar9;
  if (lVar9 == 0) {
    uVar5 = CiLookupTask((wchar_t *)(lVar2 + 0x18),(wchar_t *)(lVar2 + 0x98),0x118,
                         *(char *)(lVar2 + 0xb),&local_res10);
    iVar4 = (int)uVar5;
    if (-1 < iVar4) goto LAB_14000d3bf;
LAB_14000d3eb:
    if (lVar9 != 0) {
      CiTaskIndexDereference(lVar9);
    }
    if (!bVar3) goto LAB_14000d40a;
  }
  else {
LAB_14000d3bf:
    uVar6 = local_res10;
    bVar3 = true;
    KeEnterCriticalRegion();
    if (lVar9 == 0) {
      uVar6 = CiTaskIndexCreate(uVar6,&local_res8);
      iVar4 = (int)uVar6;
      lVar9 = local_res8;
      if (iVar4 < 0) goto LAB_14000d3eb;
    }
    else {
      CiTaskIndexReference(lVar9);
    }
    lVar2 = *(longlong *)(param_2 + 0x30);
    LOCK();
    bVar10 = *(longlong *)(lVar9 + 8) == 0;
    if (bVar10) {
      *(longlong *)(lVar9 + 8) = lVar2;
    }
    UNLOCK();
    if (!bVar10) {
      iVar4 = -0x3ffff8e8;
      lVar9 = local_res8;
      goto LAB_14000d3eb;
    }
    iVar4 = 0;
    *(longlong *)(lVar2 + 0x18) = local_res8;
    uVar8 = (ulonglong)*(uint *)(local_res8 + 0x90);
  }
  KeLeaveCriticalRegion();
LAB_14000d40a:
  *(ulonglong *)(param_1 + 0x38) = uVar8;
  *(int *)(param_1 + 0x30) = iVar4;
  IofCompleteRequest(param_1,0);
  return iVar4;
}



===== CiTaskIndexCreate @ 14000d500 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 CiTaskIndexCreate(undefined8 param_1,undefined8 *param_2)

{
  code *pcVar1;
  undefined8 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  
  puVar3 = (undefined4 *)CiAllocateMemory(200);
  if (puVar3 == (undefined4 *)0x0) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_8af022b3843c3d7d366520be64f7950a_Traceguids,0xc0000017);
    }
    uVar7 = 0xc0000017;
  }
  else {
    *puVar3 = 2;
    *(undefined8 *)(puVar3 + 0xc) = 1;
    *(undefined8 *)(puVar3 + 0x22) = param_1;
    uVar7 = 0;
    *(undefined8 *)(puVar3 + 2) = 0;
    puVar4 = puVar3 + 8;
    *(undefined4 **)(puVar3 + 10) = puVar4;
    *(undefined4 **)puVar4 = puVar4;
    uVar5 = PsGetCurrentProcessId();
    *(undefined8 *)(puVar3 + 0x26) = uVar5;
    uVar5 = PsGetCurrentThreadId();
    *(undefined8 *)(puVar3 + 0x14) = 0;
    *(undefined8 *)(puVar3 + 0x28) = uVar5;
    puVar3[0x16] = 1;
    *(undefined1 *)(puVar3 + 0x17) = 0;
    *(undefined8 *)(puVar3 + 0x1e) = 0;
    puVar3[0x20] = 1;
    *(undefined1 *)(puVar3 + 0x21) = 0;
    puVar3[0x2e] = 0;
    puVar3[0x30] = 3;
    CiSystemAcquirePushLock(0x140009210);
    if (CiTaskIndicesCount < 0x80) {
      do {
        CiTaskIndex = CiTaskIndex + 1;
        puVar6 = CiTaskIndexListHead;
        while( true ) {
          if ((undefined8 **)puVar6 == &CiTaskIndexListHead) {
            CiTaskIndicesCount = CiTaskIndicesCount + 1;
            puVar3[0x24] = CiTaskIndex;
            puVar2 = DAT_140009228;
            puVar6 = (undefined8 *)(puVar3 + 0x2a);
            *param_2 = puVar3;
            if ((undefined8 **)*puVar2 != &CiTaskIndexListHead) {
              pcVar1 = (code *)swi(0x29);
              (*pcVar1)(3);
              pcVar1 = (code *)swi(3);
              uVar7 = (*pcVar1)();
              return uVar7;
            }
            *(undefined8 **)(puVar3 + 0x2c) = puVar2;
            *puVar6 = &CiTaskIndexListHead;
            *puVar2 = puVar6;
            _DAT_140009218 = 0;
            DAT_140009228 = puVar6;
            ExReleasePushLockExclusiveEx(&CiTaskIndexListLock,0);
            goto LAB_14000d664;
          }
          if (*(int *)(puVar6 + -3) == CiTaskIndex) break;
          puVar6 = (undefined8 *)*puVar6;
        }
      } while( true );
    }
    _DAT_140009218 = 0;
    ExReleasePushLockExclusiveEx(&CiTaskIndexListLock,0);
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
              &WPP_8af022b3843c3d7d366520be64f7950a_Traceguids);
    }
    CiFreeMemory(puVar3);
    uVar7 = 0xc0000129;
  }
LAB_14000d664:
  return uVar7;
}



===== CiDispatchCreateMmThreadClient @ 14000d720 =====

int CiDispatchCreateMmThreadClient(longlong param_1,longlong param_2,undefined8 param_3)

{
  longlong lVar1;
  int *piVar2;
  longlong lVar3;
  void *pvVar4;
  int iVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  longlong local_res8;
  longlong local_res10;
  longlong local_res18;
  
  pvVar4 = SystemReserved1[0xf];
  uVar8 = 0;
  lVar1 = *(longlong *)(param_2 + 0x30);
  iVar5 = -0x3ffffff3;
  piVar2 = *(int **)(param_1 + 0x18);
  local_res8 = 0;
  local_res10 = 0;
  local_res18 = 0;
  if (*(int *)(param_2 + 0x20) == 0x110) {
    if (((((*piVar2 == 0) && ((char)piVar2[1] == '\0')) && (*(char *)((longlong)piVar2 + 5) == '\0')
         ) && ((*(short *)((longlong)piVar2 + 6) == 0x107 && ((char)piVar2[2] == '\0')))) &&
       ((*(char *)((longlong)piVar2 + 9) == '\0' &&
        ((*(char *)((longlong)piVar2 + 10) == '\0' && (*(byte *)((longlong)piVar2 + 0xb) < 2)))))) {
      uVar6 = CiLookupTask((wchar_t *)(piVar2 + 4),(wchar_t *)(piVar2 + 0x24),param_3,
                           *(byte *)((longlong)piVar2 + 0xb),&local_res8);
      iVar5 = (int)uVar6;
      if (-1 < iVar5) {
        iVar5 = piVar2[3];
        KeEnterCriticalRegion();
        if (iVar5 == 0) {
          uVar7 = CiTaskIndexCreate(local_res8,&local_res10);
          iVar5 = (int)uVar7;
          lVar3 = local_res10;
        }
        else {
          uVar7 = CiTaskIndexLocate(iVar5,local_res8,&local_res10);
          iVar5 = (int)uVar7;
          lVar3 = local_res10;
        }
        local_res10 = lVar3;
        if (-1 < iVar5) {
          uVar6 = CiThreadCreate(pvVar4,lVar3,&local_res18);
          iVar5 = (int)uVar6;
          if (-1 < iVar5) {
            *(longlong *)(local_res18 + 8) = lVar1;
            *(longlong *)(lVar1 + 0x18) = local_res18;
            uVar8 = (ulonglong)*(uint *)(lVar3 + 0x90);
          }
        }
        KeLeaveCriticalRegion();
      }
    }
    else if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
              &WPP_8f5427380d7633b566e62dbddd286985_Traceguids);
    }
  }
  else if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])
          ) {
    WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,param_3,*(int *)(param_2 + 0x20),0x10);
  }
  *(int *)(param_1 + 0x30) = iVar5;
  *(ulonglong *)(param_1 + 0x38) = uVar8;
  IofCompleteRequest(param_1,0);
  return iVar5;
}



===== CiLookupTask @ 14000d8f0 =====

ulonglong CiLookupTask(wchar_t *param_1,wchar_t *param_2,undefined8 param_3,char param_4,
                      undefined8 *param_5)

{
  ulonglong uVar1;
  ulonglong uVar2;
  byte *local_res8;
  byte *local_28 [2];
  
  local_res8 = (byte *)0x0;
  local_28[0] = (byte *)0x0;
  param_1[0x3f] = L'\0';
  uVar1 = CiTaskLocate(param_1,&local_res8);
  uVar2 = uVar1 & 0xffffffff;
  if ((int)uVar1 < 0) {
LAB_14000d974:
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_Sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                &WPP_8f5427380d7633b566e62dbddd286985_Traceguids,param_1,(char)uVar2);
    }
  }
  else {
    if (param_4 != '\0') {
      param_2[0x3f] = L'\0';
      uVar1 = CiTaskLocate(param_2,local_28);
      uVar2 = uVar1 & 0xffffffff;
      param_1 = param_2;
      if ((int)uVar1 < 0) goto LAB_14000d974;
      if (*local_res8 < *local_28[0]) {
        local_res8 = local_28[0];
      }
    }
    *param_5 = local_res8;
  }
  return uVar2;
}



===== CiTaskIndexLocate @ 14000d9d0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 CiTaskIndexLocate(int param_1,longlong param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  code *pcVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined8 uVar8;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  uVar8 = 0xc0000501;
  if (param_2 != 0) {
    CiSystemAcquirePushLock(0x140009210);
  }
  puVar6 = auStack_28;
  puVar7 = auStack_28;
  puVar4 = CiTaskIndexListHead;
  do {
    if ((undefined8 **)puVar4 == &CiTaskIndexListHead) {
LAB_14000da33:
      puVar7 = puVar6;
      if (param_2 != 0) {
LAB_14000da38:
        _DAT_140009218 = 0;
        *(undefined8 *)(puVar7 + -8) = 0x14000da4f;
        ExReleasePushLockExclusiveEx(&CiTaskIndexListLock,0);
      }
      return uVar8;
    }
    puVar5 = puVar4 + -0x15;
    if (*(int *)(puVar4 + -3) == param_1) {
      puVar6 = auStack_28;
      if (param_2 != 0) {
        if (puVar4[-4] != param_2) goto LAB_14000da38;
        LOCK();
        plVar1 = puVar4 + -0xf;
        lVar2 = *plVar1;
        *plVar1 = *plVar1 + 1;
        UNLOCK();
        puVar6 = auStack_28;
        if (lVar2 + 1 < 2) {
          pcVar3 = (code *)swi(0x29);
          (*pcVar3)(0xe);
          puVar6 = auStack_20;
        }
      }
      *param_3 = puVar5;
      uVar8 = 0;
      goto LAB_14000da33;
    }
    puVar4 = (undefined8 *)*puVar4;
  } while( true );
}



===== CiThreadSetRelativePriority @ 14000dab0 =====

undefined8 CiThreadSetRelativePriority(longlong param_1,byte param_2)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  uVar4 = 0xc000000d;
  if ((byte)(param_2 + 2) < 5) {
    pcVar1 = *(char **)(param_1 + 0x40);
    CiSystemAcquirePushLock(param_1 + 0x10);
    if ((*(byte *)(param_1 + 0x94) & 2) == 0) {
      lVar2 = PsGetThreadProcess(*(undefined8 *)(param_1 + 0x60));
      lVar3 = PsGetCurrentProcess();
      if (lVar2 == lVar3) {
        lVar2 = param_1;
        CiThreadUpdatePriorities(param_1,pcVar1,param_2);
        CiSchedulerCommitPriority(lVar2);
        uVar4 = 0;
      }
    }
    *(undefined8 *)(param_1 + 0x18) = 0;
    ExReleasePushLockExclusiveEx(param_1 + 0x10,0);
  }
  return uVar4;
}



===== CiAcquireThreadLock @ 14000db70 =====

void CiAcquireThreadLock(longlong param_1)

{
  CiSystemAcquirePushLock(param_1 + 0x10);
  return;
}



===== CiAcquireTaskIndexListLock @ 14000db90 =====

void CiAcquireTaskIndexListLock(void)

{
  CiSystemAcquirePushLock(0x140009210);
  return;
}



===== CiThreadCreate @ 14000dbb0 =====

ulonglong CiThreadCreate(undefined8 param_1,longlong param_2,undefined8 *param_3)

{
  char *pcVar1;
  undefined8 *puVar2;
  char cVar3;
  byte bVar4;
  uint uVar5;
  ulonglong uVar6;
  void *_Dst;
  void *pvVar7;
  int *piVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  ulonglong *puVar11;
  ulonglong local_res10 [2];
  undefined8 *local_res20;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  undefined4 local_40;
  undefined4 local_3c;
  
  pcVar1 = *(char **)(param_2 + 0x88);
  local_48 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_res10[0] = 0;
  uVar6 = PsGetThreadProcess();
  local_res20 = CiProcessLocate(uVar6);
  if (local_res20 == (undefined8 *)0x0) {
    uVar6 = CiProcessCreate(&local_res20);
    uVar10 = uVar6 & 0xffffffff;
    if ((int)uVar6 < 0) goto LAB_14000dec7;
  }
  puVar2 = local_res20;
  uVar6 = CiTryIncrementTotalThreadCount((int *)&CiTotalThreads,CiMaxThreadsTotal);
  uVar10 = uVar6 & 0xffffffff;
  if (-1 < (int)uVar6) {
    uVar6 = CiTryIncrementTotalThreadCount((int *)((longlong)puVar2 + 0x5c),CiMaxThreadsPerProcess);
    uVar10 = uVar6 & 0xffffffff;
    if ((int)uVar6 < 0) {
      piVar8 = (int *)&CiTotalThreads;
    }
    else {
      _Dst = (void *)ExAllocatePool2(0x41,0x98,0x4873634d);
      if (_Dst != (void *)0x0) {
        memset(_Dst,0,0x98);
        *(longlong *)((longlong)_Dst + 0x48) = param_2;
        *(undefined8 *)((longlong)_Dst + 0x20) = 1;
        *(undefined8 *)((longlong)_Dst + 0x40) = *(undefined8 *)(param_2 + 0x88);
        *(undefined8 **)((longlong)_Dst + 0x80) = puVar2;
        uVar5 = ZwQueryInformationThread(0xfffffffffffffffe,0,&local_68,0x30,0);
        uVar6 = (ulonglong)uVar5;
        if (-1 < (int)uVar5) {
          *(undefined4 *)((longlong)_Dst + 0x6c) = local_40;
          *(undefined4 *)((longlong)_Dst + 0x90) = local_3c;
          *(ulonglong *)((longlong)_Dst + 0x88) = local_48;
          cVar3 = pcVar1[1];
          *(undefined1 *)((longlong)_Dst + 0x69) = 8;
          if (cVar3 == '\0') {
            cVar3 = '\x01';
          }
          *(char *)((longlong)_Dst + 0x6a) = cVar3;
          *(char *)((longlong)_Dst + 0x68) = *pcVar1;
          local_res10[0] = *(ulonglong *)(pcVar1 + 0x20);
          if (local_res10[0] != local_48) {
            local_res10[0] = *(ulonglong *)(pcVar1 + 0x20);
            puVar11 = local_res10;
            uVar9 = 4;
            uVar5 = ZwSetInformationThread(0xfffffffffffffffe);
            uVar6 = (ulonglong)uVar5;
            if ((int)uVar5 < 0) {
              if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                WPP_SF_dI(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,puVar11,uVar5,
                          (char)local_res10[0]);
              }
              if ((uVar5 != 0xc000000d) || ((local_res10[0] & ~DAT_1400092f0) != 0))
              goto LAB_14000ddfa;
            }
          }
          *(undefined8 *)((longlong)_Dst + 0x60) = param_1;
          bVar4 = CiThreadInsertInTree((longlong)_Dst);
          if (bVar4 != 0) {
            pvVar7 = _Dst;
            CiThreadUpdatePriorities((longlong)_Dst,pcVar1,0);
            if (DAT_1400090d0 != '\0') {
              CiLogThreadJoin((longlong)pvVar7);
            }
            ObfReferenceObject(param_1);
            CiSystemAcquirePushLock((longlong)(puVar2 + 2));
            CiProcessAddThread((longlong)_Dst);
            if ((pcVar1[3] & 1U) != 0) {
              CiSchedulerAddThread(param_2,(longlong)_Dst);
            }
            if ((*(byte *)((longlong)_Dst + 0x94) & 1) == 0) {
              CiThreadIncrementScheduledCount((longlong)_Dst);
            }
            puVar2[3] = 0;
            ExReleasePushLockExclusiveEx(puVar2 + 2,0);
            *param_3 = _Dst;
            CiSchedulerPoke(1);
            return 0;
          }
          *(undefined8 *)((longlong)_Dst + 0x60) = 0;
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                    &WPP_29026e0d014631895ac1404d49971dec_Traceguids);
          }
          uVar6 = 0xc0000502;
        }
LAB_14000ddfa:
        CiThreadCleanup((longlong)_Dst);
        CiThreadDereference((longlong)_Dst);
        return uVar6;
      }
      uVar10 = 0xc0000017;
      CiDecrementTotalThreadCount((int *)&CiTotalThreads);
      piVar8 = (int *)((longlong)puVar2 + 0x5c);
    }
    CiDecrementTotalThreadCount(piVar8);
  }
  CiProcessDereference((longlong)puVar2);
LAB_14000dec7:
  CiTaskIndexDereference(param_2);
  return uVar10;
}



===== CiProcessCreate @ 14000df50 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 CiProcessCreate(undefined8 *param_1)

{
  ulonglong uVar1;
  code *pcVar2;
  longlong *_Dst;
  longlong lVar3;
  ulonglong uVar4;
  longlong *plVar5;
  longlong *plVar6;
  undefined1 *puVar7;
  ulonglong uVar8;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  _Dst = (longlong *)ExAllocatePool2(0x41,0x60,0x5073634d);
  if (_Dst == (longlong *)0x0) {
    return 0xc0000017;
  }
  uVar8 = 0;
  memset(_Dst,0,0x60);
  *(undefined4 *)_Dst = 1;
  _Dst[4] = 1;
  lVar3 = PsGetCurrentProcess();
  _Dst[10] = lVar3;
  plVar6 = _Dst + 8;
  _Dst[9] = (longlong)plVar6;
  *plVar6 = (longlong)plVar6;
  ObfReferenceObject(_Dst[10]);
  CiSystemAcquirePushLock(0x1400091f0);
  puVar7 = auStack_28;
  uVar8 = uVar8 & 0xffffffffffffff00;
  uVar1 = _Dst[10];
  plVar6 = CiProcessTree;
  if (CiProcessTree != (longlong *)0x0) {
    do {
      uVar4 = CiProcessComparer(uVar1,(longlong)plVar6);
      if ((int)uVar4 < 1) {
        if (-1 < (int)uVar4) {
          LOCK();
          plVar5 = plVar6 + -1;
          lVar3 = *plVar5;
          *plVar5 = *plVar5 + 1;
          UNLOCK();
          if (lVar3 + 1 < 2) {
            pcVar2 = (code *)swi(0x29);
            (*pcVar2)(0xe);
            puVar7 = auStack_20;
          }
          _DAT_1400091f8 = 0;
          *(undefined8 *)(puVar7 + -8) = 0x14000e09d;
          ExReleasePushLockExclusiveEx(&CiProcessTreeLock,0);
          if (plVar6 + -5 != (longlong *)0x0) {
            lVar3 = _Dst[10];
            *(undefined8 *)(puVar7 + -8) = 0x14000e0ed;
            ObfDereferenceObject(lVar3);
            *(undefined8 *)(puVar7 + -8) = 0x14000e101;
            ExFreePoolWithTag(_Dst,0x5073634d);
            _Dst = plVar6 + -5;
          }
          goto LAB_14000e0a7;
        }
        plVar5 = (longlong *)*plVar6;
        if (plVar5 == (longlong *)0x0) goto LAB_14000e0c8;
      }
      else {
        plVar5 = (longlong *)plVar6[1];
        if (plVar5 == (longlong *)0x0) {
          uVar8 = 1;
          break;
        }
      }
      plVar6 = plVar5;
    } while( true );
  }
LAB_14000e02f:
  RtlRbInsertNodeEx(&CiProcessTree,plVar6,uVar8,_Dst + 5);
  _DAT_1400091f8 = 0;
  ExReleasePushLockExclusiveEx(&CiProcessTreeLock,0);
LAB_14000e0a7:
  *param_1 = _Dst;
  return 0;
LAB_14000e0c8:
  uVar8 = uVar8 & 0xffffffffffffff00;
  goto LAB_14000e02f;
}



===== CiProcessLocate @ 14000e120 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * CiProcessLocate(ulonglong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  undefined8 *puVar3;
  code *pcVar4;
  undefined8 *puVar5;
  ulonglong uVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  undefined1 *puVar9;
  undefined8 *puVar10;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  puVar10 = (undefined8 *)0x0;
  ExAcquirePushLockExclusiveEx(&CiProcessTreeLock,0);
  uVar6 = DAT_140009208;
  puVar9 = auStack_28;
  _DAT_1400091f8 = SystemReserved1[0xf];
  puVar7 = CiProcessTree;
  if ((DAT_140009208 & 1) != 0) {
    if (CiProcessTree == (undefined8 *)0x0) goto LAB_14000e1c0;
    puVar7 = (undefined8 *)((ulonglong)CiProcessTree ^ 0x140009200);
  }
  while (puVar5 = puVar7, puVar5 != (undefined8 *)0x0) {
    uVar8 = CiProcessComparer(param_1,(longlong)puVar5);
    if ((int)uVar8 < 0) {
      puVar3 = (undefined8 *)*puVar5;
    }
    else {
      if ((int)uVar8 < 1) break;
      puVar3 = (undefined8 *)puVar5[1];
    }
    puVar7 = puVar3;
    if (((uVar6 & 1) != 0) && (puVar7 = (undefined8 *)0x0, puVar3 != (undefined8 *)0x0)) {
      puVar7 = (undefined8 *)((ulonglong)puVar5 ^ (ulonglong)puVar3);
    }
  }
  puVar9 = auStack_28;
  if (puVar5 != (undefined8 *)0x0) {
    puVar10 = puVar5 + -5;
    LOCK();
    plVar1 = puVar5 + -1;
    lVar2 = *plVar1;
    *plVar1 = *plVar1 + 1;
    UNLOCK();
    puVar9 = auStack_28;
    if (lVar2 + 1 < 2) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(0xe);
      puVar9 = auStack_20;
    }
  }
LAB_14000e1c0:
  _DAT_1400091f8 = (void *)0x0;
  *(undefined8 *)(puVar9 + -8) = 0x14000e1db;
  ExReleasePushLockExclusiveEx(&CiProcessTreeLock,0);
  return puVar10;
}



===== CiProcessComparer @ 14000e240 =====

ulonglong CiProcessComparer(ulonglong param_1,longlong param_2)

{
  if (param_1 < *(ulonglong *)(param_2 + 0x28)) {
    return 0xffffffff;
  }
  return (ulonglong)(*(ulonglong *)(param_2 + 0x28) < param_1);
}



===== CiThreadUpdatePriorities @ 14000e270 =====

void CiThreadUpdatePriorities(longlong param_1,char *param_2,byte param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  
  if (CiSystemResponsiveness == 100) {
    bVar1 = param_3 + 9;
    bVar3 = bVar1;
    bVar2 = bVar1;
    goto LAB_14000e2de;
  }
  bVar1 = param_3 + param_2[1];
  if (bVar1 == 0) {
    bVar1 = 1;
  }
  else if (7 < bVar1) {
    bVar1 = 7;
  }
  bVar3 = param_2[2];
  if (7 < (byte)param_2[2]) {
    bVar3 = param_3;
  }
  bVar3 = bVar3 + 8;
  bVar2 = param_3 + *param_2;
  bVar4 = (byte)param_2[3] >> 4 & 7;
  if (bVar4 == 2) {
    if (bVar2 < 0x10) {
      bVar2 = 0x10;
    }
    else if (0x17 < bVar2) {
LAB_14000e2ca:
      bVar2 = 0x17;
    }
  }
  else if (bVar4 == 1) {
    bVar2 = bVar3;
  }
  else if (bVar4 == 3) {
    if (bVar2 < 0x17) goto LAB_14000e2ca;
    if (0x1a < bVar2) {
      bVar2 = 0x1a;
    }
  }
  if (0x1a < bVar1) {
    bVar1 = 0x1a;
  }
  if (0x1a < bVar3) {
    bVar3 = 0x1a;
  }
  if (0x1a < bVar2) {
    bVar2 = 0x1b;
  }
LAB_14000e2de:
  *(byte *)(param_1 + 0x6a) = bVar1;
  *(byte *)(param_1 + 0x69) = bVar3;
  *(byte *)(param_1 + 0x68) = bVar2;
  return;
}



===== CiProcessAddThread @ 14000e350 =====

void CiProcessAddThread(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  longlong *plVar4;
  
  lVar1 = *(longlong *)(param_1 + 0x80);
  plVar2 = *(longlong **)(lVar1 + 0x48);
  plVar4 = (longlong *)(param_1 + 0x70);
  if (*plVar2 == lVar1 + 0x40) {
    *plVar4 = lVar1 + 0x40;
    *(longlong **)(param_1 + 0x78) = plVar2;
    *plVar2 = (longlong)plVar4;
    *(longlong **)(lVar1 + 0x48) = plVar4;
    *(byte *)(param_1 + 0x94) =
         (*(byte *)(param_1 + 0x94) ^ *(byte *)(lVar1 + 0x58)) & 1 ^ *(byte *)(param_1 + 0x94);
    return;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== CiDispatchCleanup @ 14000e3b0 =====

undefined8 CiDispatchCleanup(undefined8 param_1,longlong param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x18);
  if (piVar1 != (int *)0x0) {
    if (*piVar1 == 0) {
      CiThreadCleanup((longlong)piVar1);
    }
    else if (*piVar1 != 1) {
      piVar1[2] = 0;
      piVar1[3] = 0;
    }
  }
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== CiThreadCleanup @ 14000e420 =====

void CiThreadCleanup(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  void *pvVar3;
  undefined8 local_res8;
  
  lVar1 = 0;
  local_res8 = 0;
  lVar2 = 0;
  pvVar3 = (void *)0x0;
  if ((*(byte *)(param_1 + 0x94) & 2) == 0) {
    CiSystemAcquirePushLock(param_1 + 0x10);
    if ((*(byte *)(param_1 + 0x94) & 2) == 0) {
      lVar2 = *(longlong *)(param_1 + 0x80);
      lVar1 = *(longlong *)(param_1 + 0x48);
      *(byte *)(param_1 + 0x94) = *(byte *)(param_1 + 0x94) | 2;
      CiDecrementTotalThreadCount((int *)(lVar2 + 0x5c));
      pvVar3 = *(void **)(param_1 + 0x60);
      if (pvVar3 != (void *)0x0) {
        CiThreadRemoveFromTree(param_1);
        if ((*(byte *)(*(longlong *)(param_1 + 0x40) + 3) & 1) != 0) {
          CiSchedulerRemoveThread(param_1);
        }
        CiProcessRemoveThread(param_1);
        if ((*(byte *)(param_1 + 0x94) & 1) == 0) {
          CiThreadDecrementScheduledCount(param_1);
        }
        KeSetBasePriorityThread(pvVar3,*(undefined4 *)(param_1 + 0x90));
        KeSetPriorityThread(pvVar3,*(undefined4 *)(param_1 + 0x6c));
        local_res8 = *(undefined8 *)(param_1 + 0x88);
        if (pvVar3 == SystemReserved1[0xf]) {
          ZwSetInformationThread(0xfffffffffffffffe,4,&local_res8);
        }
        if (DAT_1400090d0 != '\0') {
          CiLogThreadLeave(param_1);
        }
      }
      CiDecrementTotalThreadCount((int *)&CiTotalThreads);
    }
    *(undefined8 *)(param_1 + 0x18) = 0;
    ExReleasePushLockExclusiveEx(param_1 + 0x10,0);
    if (pvVar3 != (void *)0x0) {
      ObfDereferenceObject(pvVar3);
    }
    if (lVar2 != 0) {
      CiProcessDereference(lVar2);
    }
    if (lVar1 != 0) {
      CiTaskIndexDereference(lVar1);
    }
  }
  return;
}



===== CiSystemAcquirePushLock @ 14000e5c0 =====

void CiSystemAcquirePushLock(longlong param_1)

{
  ExAcquirePushLockExclusiveEx(param_1,0);
  *(void **)(param_1 + 8) = SystemReserved1[0xf];
  return;
}



===== CiProcessDereference @ 14000e600 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CiProcessDereference(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 uVar4;
  code *pcVar5;
  longlong lVar6;
  undefined1 *puVar7;
  bool bVar8;
  undefined8 uStack_30;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  puVar7 = auStack_28;
  lVar6 = *(longlong *)(param_1 + 0x20);
  do {
    lVar1 = lVar6 + -1;
    if (lVar1 < 1) {
      if (lVar1 != 0) {
        pcVar5 = (code *)swi(0x29);
        (*pcVar5)(0xe);
        puVar7 = auStack_20;
      }
      *(undefined8 *)(puVar7 + -8) = 0x14000e63b;
      CiSystemAcquirePushLock(0x1400091f0);
      LOCK();
      plVar2 = (longlong *)(param_1 + 0x20);
      lVar6 = *plVar2;
      *plVar2 = *plVar2 + -1;
      UNLOCK();
      if (lVar6 < 2) {
        if (lVar6 == 1) {
          *(undefined8 *)(puVar7 + -8) = 0x14000e665;
          RtlRbRemoveNode(&CiProcessTree,param_1 + 0x28);
          _DAT_1400091f8 = 0;
          *(undefined8 *)(puVar7 + -8) = 0x14000e683;
          ExReleasePushLockExclusiveEx(&CiProcessTreeLock,0);
          uVar4 = *(undefined8 *)(param_1 + 0x50);
          *(undefined8 *)(puVar7 + -8) = 0x14000e693;
          ObfDereferenceObject(uVar4);
          *(undefined8 *)(puVar7 + -8) = 0x14000e6a7;
          ExFreePoolWithTag(param_1,0x5073634d);
          return;
        }
        pcVar5 = (code *)swi(0x29);
        (*pcVar5)(0xe);
        puVar7 = puVar7 + 8;
      }
      _DAT_1400091f8 = 0;
      *(undefined8 *)(puVar7 + -8) = 0x14000e6d3;
      ExReleasePushLockExclusiveEx(&CiProcessTreeLock,0);
      return;
    }
    LOCK();
    lVar3 = *(longlong *)(param_1 + 0x20);
    bVar8 = lVar6 == lVar3;
    if (bVar8) {
      *(longlong *)(param_1 + 0x20) = lVar1;
    }
    else {
      lVar6 = lVar3;
    }
    UNLOCK();
  } while (!bVar8);
  return;
}



===== CiProcessRemoveThread @ 14000e6f0 =====

void CiProcessRemoveThread(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  
  lVar1 = *(longlong *)(param_1 + 0x80);
  CiSystemAcquirePushLock(lVar1 + 0x10);
  lVar2 = *(longlong *)(param_1 + 0x70);
  if ((*(longlong *)(lVar2 + 8) == param_1 + 0x70) &&
     (plVar3 = *(longlong **)(param_1 + 0x78), *plVar3 == param_1 + 0x70)) {
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    *(undefined8 *)(lVar1 + 0x18) = 0;
    ExReleasePushLockExclusiveEx(lVar1 + 0x10,0);
    return;
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== CiThreadDecrementScheduledCount @ 14000e760 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CiThreadDecrementScheduledCount(longlong param_1)

{
  if ((*(byte *)(*(longlong *)(param_1 + 0x40) + 3) & 1) != 0) {
    CiSystemAcquirePushLock(0x140009190);
    CiScheduledThreadCount = CiScheduledThreadCount + -1;
    if (CiScheduledThreadCount == 0) {
      CiNdisUpdateThrottleState();
    }
    _DAT_140009198 = 0;
    ExReleasePushLockExclusiveEx(&CiThreadCountLock,0);
  }
  return;
}



===== CiThreadIncrementScheduledCount @ 14000e7c0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CiThreadIncrementScheduledCount(longlong param_1)

{
  if ((*(byte *)(*(longlong *)(param_1 + 0x40) + 3) & 1) != 0) {
    CiSystemAcquirePushLock(0x140009190);
    CiScheduledThreadCount = CiScheduledThreadCount + 1;
    if (CiScheduledThreadCount == 1) {
      CiNdisUpdateThrottleState();
    }
    _DAT_140009198 = 0;
    ExReleasePushLockExclusiveEx(&CiThreadCountLock,0);
  }
  return;
}



===== CiDispatchClose @ 14000e820 =====

undefined8 CiDispatchClose(undefined8 param_1,longlong param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x18);
  if (piVar1 != (int *)0x0) {
    if (*piVar1 == 1) {
      CiSystemAcquirePushLock((longlong)(piVar1 + 4));
      piVar1[2] = 0;
      piVar1[3] = 0;
      piVar1[6] = 0;
      piVar1[7] = 0;
      ExReleasePushLockExclusiveEx(piVar1 + 4,0);
      CiProcessDereference((longlong)piVar1);
    }
    else if (*piVar1 == 0) {
      CiThreadDereference((longlong)piVar1);
    }
    else {
      CiTaskIndexDereference((longlong)piVar1);
    }
  }
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== CiThreadDereference @ 14000e8d0 =====

void CiThreadDereference(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  code *pcVar3;
  
  LOCK();
  plVar1 = (longlong *)(param_1 + 0x20);
  lVar2 = *plVar1;
  *plVar1 = *plVar1 + -1;
  UNLOCK();
  if (lVar2 < 2) {
    if (lVar2 != 1) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(0xe);
      return;
    }
    ExFreePoolWithTag(param_1,0x4873634d);
  }
  return;
}



===== CiNdisUpdateThrottleState @ 14000e920 =====

void CiNdisUpdateThrottleState(void)

{
  if ((CiNdisDeviceHandle != 0) && (CiNdisThrottleInProgress == '\0')) {
    CiNdisThrottleInProgress = '\x01';
    IoQueueWorkItem(CiNdisThrottleWorkItem,CiNdisThrottle,3);
  }
  return;
}



===== CiTaskLocate @ 14000e970 =====

undefined8 CiTaskLocate(wchar_t *param_1,undefined8 *param_2)

{
  int iVar1;
  undefined8 *puVar2;
  
  puVar2 = CiTaskListHead;
  while( true ) {
    if ((undefined8 **)puVar2 == &CiTaskListHead) {
      return 0xc0000500;
    }
    iVar1 = _wcsicmp(param_1,(wchar_t *)puVar2[2]);
    if (iVar1 == 0) break;
    puVar2 = (undefined8 *)*puVar2;
  }
  *param_2 = puVar2 + -1;
  return 0;
}



===== CiDispatchCreate @ 14000ea00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 CiDispatchCreate(undefined8 param_1,undefined *param_2,undefined8 param_3)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  undefined8 uVar4;
  undefined *puVar5;
  ulonglong uVar6;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  uVar6 = 0;
  lVar2 = *(longlong *)(lVar1 + 0x30);
  puVar5 = param_2;
  while( true ) {
    if (2 < (uint)uVar6) {
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        WPP_SF_Z(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),puVar5,param_3,(wchar_t *)(lVar2 + 0x58)
                );
      }
      *(undefined4 *)(param_2 + 0x30) = 0xc0000225;
      *(undefined8 *)(param_2 + 0x38) = 0;
      IofCompleteRequest(param_2,0);
      return 0xc0000225;
    }
    param_3 = 0;
    puVar5 = &CiObjectCreationTable + uVar6 * 0x18;
    iVar3 = RtlCompareUnicodeString(lVar2 + 0x58);
    if (iVar3 == 0) break;
    uVar6 = (ulonglong)((uint)uVar6 + 1);
  }
  uVar4 = (*(code *)(&PTR_CiDispatchCreateMmThreadClient_140008700)[uVar6 * 3])(param_2,lVar1);
  return uVar4;
}



===== CiReleaseThreadLock @ 14000ead0 =====

void CiReleaseThreadLock(longlong param_1)

{
  *(undefined8 *)(param_1 + 0x18) = 0;
  ExReleasePushLockExclusiveEx(param_1 + 0x10,0);
  return;
}



===== CiTaskIndexRemove @ 14000eb00 =====

void CiTaskIndexRemove(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  longlong *plVar4;
  
  plVar4 = (longlong *)(param_1 + 0xa8);
  lVar1 = *plVar4;
  if ((*(longlong **)(lVar1 + 8) == plVar4) &&
     (plVar2 = *(longlong **)(param_1 + 0xb0), (longlong *)*plVar2 == plVar4)) {
    CiTaskIndicesCount = CiTaskIndicesCount + -1;
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



===== CiReleaseTaskIndexListLock @ 14000eb40 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CiReleaseTaskIndexListLock(void)

{
  _DAT_140009218 = 0;
  ExReleasePushLockExclusiveEx(&CiTaskIndexListLock,0);
  return;
}



===== CiNdisThrottle @ 14000eb70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int CiNdisThrottle(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  bool bVar4;
  undefined1 auStack_88 [32];
  undefined8 *local_68;
  undefined4 local_60;
  undefined8 *local_58;
  undefined4 local_50;
  undefined8 local_48;
  undefined4 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_88;
  local_28 = 0x100001;
  local_20 = 0xffffffffffffffff;
  local_38 = 0;
  uStack_30 = 0;
  iVar2 = 0;
  ExAcquirePushLockExclusiveEx(&CiThreadCountLock,0);
  bVar4 = CiScheduledThreadCount != 0;
  if (bVar4 != (bool)CiNdisThrottledDown) {
    do {
      _DAT_140009198 = 0;
      ExReleasePushLockExclusiveEx(&CiThreadCountLock,0);
      local_40 = 0;
      local_58 = &local_28;
      local_48 = 0;
      local_50 = 0x10;
      local_68 = &local_38;
      uVar3 = 0xffffffff;
      if (bVar4 != false) {
        uVar3 = CiNetworkThrottlingIndex;
      }
      local_28 = CONCAT44(uVar3,(undefined4)local_28);
      local_60 = 0x170040;
      iVar2 = ZwDeviceIoControlFile(CiNdisDeviceHandle,0,0,0);
      ExAcquirePushLockExclusiveEx(&CiThreadCountLock,0);
      if (-1 < iVar2) {
        CiNdisThrottledDown = bVar4;
      }
      bVar1 = CiScheduledThreadCount != 0;
    } while ((bVar4 != bVar1) && (bVar4 = bVar1, bVar1 != (bool)CiNdisThrottledDown));
  }
  CiNdisThrottleInProgress = 0;
  _DAT_140009198 = 0;
  ExReleasePushLockExclusiveEx(&CiThreadCountLock,0);
  ExUnblockOnAddressPushLockEx(&CiNdisThrottleInProgressPushLock,0);
  if ((iVar2 < 0) &&
     (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29])))) {
    WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
             &WPP_8a12c31d698336a89006616b8d149517_Traceguids,iVar2);
  }
  return iVar2;
}



===== CiConfigInitialize @ 14000f010 =====

int CiConfigInitialize(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined8 local_res8;
  undefined8 local_res10;
  undefined8 local_38;
  undefined8 local_30;
  undefined *local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_38 = 0x30;
  local_res8 = 0;
  local_res10 = 0;
  local_30 = 0;
  local_20 = 0x40;
  local_28 = &CiMmcssRootKeyName;
  local_18 = 0;
  uStack_10 = 0;
  iVar1 = ZwOpenKey(&local_res8,0x80000100,&local_38);
  if (iVar1 < 0) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
               &WPP_350503daac883abe7be9cf63f89038d9_Traceguids,iVar1);
    }
  }
  else {
    uVar2 = CiConfigReadDWORD(local_res8,L"(*",100);
    if (uVar2 - 10 < 0x5b) {
      CiSystemResponsiveness = (uVar2 / 10) * 10;
    }
    else {
      CiSystemResponsiveness = 0x14;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
               &WPP_350503daac883abe7be9cf63f89038d9_Traceguids,CiSystemResponsiveness);
    }
    if (CiSystemResponsiveness == 100) {
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                &WPP_350503daac883abe7be9cf63f89038d9_Traceguids);
      }
      iVar1 = -0x3fffff80;
    }
    else {
      CiNetworkThrottlingIndex = CiConfigReadDWORD(local_res8,L",.",10);
      if (CiNetworkThrottlingIndex == 0) {
        CiNetworkThrottlingIndex = 1;
      }
      else if (CiNetworkThrottlingIndex - 0x47U < 0xffffffb8) {
        CiNetworkThrottlingIndex = 0x46;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                 &WPP_350503daac883abe7be9cf63f89038d9_Traceguids,CiNetworkThrottlingIndex);
      }
      uVar3 = CiConfigReadDWORD(local_res8,L"\x14\x16",0);
      CiSchedulerDisallowLazyMode = (char)uVar3 != '\0';
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                 &WPP_350503daac883abe7be9cf63f89038d9_Traceguids,
                 (uint)(byte)CiSchedulerDisallowLazyMode);
      }
      CiSchedulerIdleDetectionCycles = CiConfigReadDWORD(local_res8,L"&(",2);
      if (0x1e < CiSchedulerIdleDetectionCycles - 1U) {
        CiSchedulerIdleDetectionCycles = 2;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                 &WPP_350503daac883abe7be9cf63f89038d9_Traceguids,CiSchedulerIdleDetectionCycles);
      }
      CiSchedulerIdleCycleBitMask = (1 << ((byte)CiSchedulerIdleDetectionCycles & 0x1f)) + -1;
      CiSchedulerLazyModeTimeout = CiConfigReadDWORD(local_res8,L"\x1e ",1000000);
      if (CiSchedulerLazyModeTimeout == 0) {
        CiSchedulerLazyModeTimeout = 1000000;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                 &WPP_350503daac883abe7be9cf63f89038d9_Traceguids,CiSchedulerLazyModeTimeout);
      }
      CiSchedulerTimerResolution = CiConfigReadDWORD(local_res8,L"02",10000);
      if (10000 < CiSchedulerTimerResolution) {
        CiSchedulerTimerResolution = 10000;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                 &WPP_350503daac883abe7be9cf63f89038d9_Traceguids,CiSchedulerTimerResolution);
      }
      CiSchedulerPeriod = CiConfigReadDWORD(local_res8,L"\x1e ",100000);
      if (950000 < CiSchedulerPeriod - 50000U) {
        CiSchedulerPeriod = 100000;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                 &WPP_350503daac883abe7be9cf63f89038d9_Traceguids,CiSchedulerPeriod);
      }
      CiMaxThreadsPerProcess = CiConfigReadDWORD(local_res8,L"(*",0x20);
      if (0x78 < CiMaxThreadsPerProcess - 8U) {
        CiMaxThreadsPerProcess = 0x20;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
                 &WPP_350503daac883abe7be9cf63f89038d9_Traceguids,CiMaxThreadsPerProcess);
      }
      CiMaxThreadsTotal = CiConfigReadDWORD(local_res8,L"\x1e ",0x100);
      if (0xffbf < CiMaxThreadsTotal - 0x40U) {
        CiMaxThreadsTotal = 0x100;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
                 &WPP_350503daac883abe7be9cf63f89038d9_Traceguids,CiMaxThreadsTotal);
      }
      local_30 = local_res8;
      local_38 = CONCAT44(local_38._4_4_,0x30);
      local_28 = &CiTasksKeyRootName;
      local_20 = CONCAT44(local_20._4_4_,0x40);
      local_18 = 0;
      uStack_10 = 0;
      iVar1 = ZwOpenKey(&local_res10,0x80000100,&local_38);
      if (-1 < iVar1) {
        iVar1 = CiConfigInitializeFromRegistry(local_res10);
        ZwClose(local_res10);
      }
    }
    ZwClose(local_res8);
  }
  return iVar1;
}



===== entry @ 14000f4d0 =====

void entry(longlong param_1)

{
  __security_init_cookie();
  DriverEntry(param_1);
  return;
}



===== __security_init_cookie @ 14000f504 =====

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



===== DriverEntry @ 14000f540 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  code *pcVar3;
  undefined8 uVar4;
  undefined8 local_res18;
  undefined4 uVar5;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined **local_28;
  undefined8 *local_20;
  longlong local_18;
  
  wil_InitializeFeatureStaging();
  _DAT_140009168 = 1;
  _WPP_MAIN_CB = 0;
  DAT_140009148 = &WPP_ThisDir_CTLGUID_MmcssTrace;
  DAT_140009150 = 0;
  _DAT_140009160 = 0;
  WppLoadTracingSupport();
  _DAT_140009160 = 0;
  WppInitKm();
  uVar4 = 0;
  DAT_140009268 = &CiTaskListHead;
  CiTaskListHead = &CiTaskListHead;
  pcVar3 = CiLogControlCallback;
  DAT_140009228 = &CiTaskIndexListHead;
  CiTaskIndexListHead = &CiTaskIndexListHead;
  DAT_140009238 = &CiScheduledTaskIndexListHead;
  CiScheduledTaskIndexListHead = &CiScheduledTaskIndexListHead;
  iVar1 = EtwRegister(&MMCSS_ETW_PROVIDER,CiLogControlCallback,0,&CiLoggerContext);
  if (iVar1 < 0) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),pcVar3,uVar4,iVar1);
    }
  }
  else {
    iVar1 = ZwQuerySystemInformation(0,&CiSystemBasicInfo,0x40);
    lVar2 = (longlong)DAT_1400092f8;
    CiLastIdleStats = (void *)ExAllocatePool2(0x40,lVar2 * 0x18,0x74727641);
    if (CiLastIdleStats == (void *)0x0) {
      iVar1 = -0x3fffffe9;
      CiSystemTerminate();
    }
    else {
      memset(CiLastIdleStats,0,lVar2 * 0x18);
      if (iVar1 < 0) {
        CiSystemTerminate();
      }
      else {
        iVar1 = CiConfigInitialize();
        if (-1 < iVar1) {
          iVar1 = PsSetCreateThreadNotifyRoutine(CiThreadNotification);
          if (iVar1 < 0) {
            if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                       &WPP_29026e0d014631895ac1404d49971dec_Traceguids,iVar1);
            }
          }
          else {
            CiThreadCallbackRegistered = 1;
          }
          if (-1 < iVar1) {
            local_30 = 0x10009;
            local_28 = &CiKernelCalloutTable;
            local_2c = 0x10000;
            local_20 = &CiKernelInterface;
            local_18 = param_1;
            iVar1 = ExRegisterExtension(&CiKernelExtensionRegistration,0x10001,&local_30);
            if (-1 < iVar1) {
              local_38 = 0;
              local_48 = 0;
              uStack_40 = 0;
              local_res18 = 0;
              DAT_140009254 = (uint)(CiSystemResponsiveness * CiSchedulerPeriod) / 100;
              CiSchedulerTimeIncrement = CiSchedulerPeriod - DAT_140009254;
              CiSchedulerTimer = ExAllocateTimer(0,0,0xc);
              if (CiSchedulerTimer == 0) {
                if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
                   (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                          &WPP_e00c2d44edf236fb41cafbc4576a8546_Traceguids);
                }
                iVar1 = -0x3fffffe9;
              }
              else {
                _CiSchedulerNoWakeTimerParams = 0;
                _DAT_1400091b8 = 0xffffffffffffffff;
                CiProcessorIdleHistoryBits = 0;
                KeInitializeEvent(&local_48,0,0);
                pcVar3 = CiSchedulerThreadFunction;
                iVar1 = PsCreateSystemThread
                                  (&local_res18,0x1fffff,0,0,0,CiSchedulerThreadFunction,&local_48);
                if (iVar1 < 0) {
                  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
                     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                            &WPP_e00c2d44edf236fb41cafbc4576a8546_Traceguids);
                  }
                }
                else {
                  ZwClose(local_res18);
                  uVar5 = 0;
                  KeWaitForSingleObject(&local_48,0,0,0,0);
                  *(undefined **)(param_1 + 0x50) = &CiFastIoDispatch;
                  *(code **)(param_1 + 0x70) = CiDispatchCreate;
                  *(code **)(param_1 + 0x100) = CiDispatchCleanup;
                  *(code **)(param_1 + 0x80) = CiDispatchClose;
                  *(code **)(param_1 + 0x68) = CiDriverUnload;
                  iVar1 = IoCreateDevice(param_1,0,&CiDeviceName,0x22,CONCAT44(uVar5,0x20000),
                                         (ulonglong)pcVar3 & 0xffffffffffffff00,&CiDeviceObject);
                  if (iVar1 < 0) {
                    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
                       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                      WPP_SF_Zd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                                &WPP_8f5427380d7633b566e62dbddd286985_Traceguids,L"\x1a\x1c",
                                (char)iVar1);
                    }
                  }
                  else if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
                          (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                    WPP_SF_Zq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18));
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if (((CiNetworkThrottlingIndex != -1) && (CiSystemResponsiveness != 100)) &&
     (CiNdisThrottleWorkItem = IoAllocateWorkItem(CiDeviceObject), CiNdisThrottleWorkItem != 0)) {
    CiNdisOpenDevice();
  }
  if (iVar1 < 0) {
    CsTerminate();
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
  return iVar1;
}



===== wil_InitializeFeatureStaging @ 14000fa54 =====

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



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14000fb44 =====

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



===== CiTaskAllocate @ 14000fc2c =====

undefined4 CiTaskAllocate(wchar_t *param_1,undefined8 *param_2,undefined8 *param_3)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  undefined4 uVar12;
  undefined8 *puVar13;
  undefined8 local_res20;
  
  local_res20 = 0;
  uVar9 = CiTaskLocate(param_1,&local_res20);
  if ((int)uVar9 < 0) {
    puVar10 = (undefined8 *)ExAllocatePool2(0x40,0x30,0x74727641);
    if (puVar10 != (undefined8 *)0x0) {
      uVar9 = param_2[1];
      puVar13 = &CiTaskListHead;
      uVar12 = *(undefined4 *)(param_2 + 2);
      uVar2 = *(undefined4 *)((longlong)param_2 + 0x14);
      uVar3 = *(undefined4 *)(param_2 + 3);
      uVar4 = *(undefined4 *)((longlong)param_2 + 0x1c);
      *puVar10 = *param_2;
      puVar10[1] = uVar9;
      uVar5 = *(undefined4 *)(param_2 + 4);
      uVar6 = *(undefined4 *)((longlong)param_2 + 0x24);
      uVar7 = *(undefined4 *)(param_2 + 5);
      uVar8 = *(undefined4 *)((longlong)param_2 + 0x2c);
      *(undefined4 *)(puVar10 + 2) = uVar12;
      *(undefined4 *)((longlong)puVar10 + 0x14) = uVar2;
      *(undefined4 *)(puVar10 + 3) = uVar3;
      *(undefined4 *)((longlong)puVar10 + 0x1c) = uVar4;
      *(undefined4 *)(puVar10 + 4) = uVar5;
      *(undefined4 *)((longlong)puVar10 + 0x24) = uVar6;
      *(undefined4 *)(puVar10 + 5) = uVar7;
      *(undefined4 *)((longlong)puVar10 + 0x2c) = uVar8;
      puVar10[3] = param_1;
      puVar11 = puVar10 + 1;
      if ((undefined8 *)*DAT_140009268 != &CiTaskListHead) {
        puVar10 = (undefined8 *)0x3;
        pcVar1 = (code *)swi(0x29);
        puVar11 = (undefined8 *)(*pcVar1)();
      }
      *puVar11 = puVar13;
      puVar11[1] = DAT_140009268;
      *DAT_140009268 = puVar11;
      DAT_140009268 = puVar11;
      *param_3 = puVar10;
      return 0;
    }
    uVar12 = 0xc0000017;
  }
  else {
    uVar12 = 0xc0000035;
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_62da978b8000316eb1e6fce22b5cf66e_Traceguids,uVar12);
  }
  ExFreePoolWithTag(param_1,0);
  return uVar12;
}



===== CiConfigReadDWORD @ 14000fd2c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 CiConfigReadDWORD(undefined8 param_1,wchar_t *param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 auStack_58 [32];
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  local_20 = 0;
  uStack_18 = 0;
  iVar1 = ZwQueryValueKey(0,param_2,2,&local_20);
  if ((iVar1 < 0) || (local_20._4_4_ != 4)) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_Zd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                &WPP_350503daac883abe7be9cf63f89038d9_Traceguids,param_2,(char)param_3);
    }
    uStack_18._4_4_ = param_3;
  }
  else {
  }
  return uStack_18._4_4_;
}



===== CiConfigQueryTaskFromRegistry @ 14000fdf0 =====

ulonglong CiConfigQueryTaskFromRegistry(undefined8 param_1,char *param_2,longlong param_3)

{
  char cVar1;
  undefined8 *puVar2;
  ulonglong uVar3;
  byte bVar4;
  ulonglong uVar5;
  
  *(byte *)(param_3 + 3) = *(byte *)(param_3 + 3) & 0x8f;
  uVar5 = 0;
  while( true ) {
    puVar2 = (undefined8 *)(&CiConfigTaskValues)[uVar5];
    if (puVar2 == (undefined8 *)0x0) {
      cVar1 = param_2[0x20];
      bVar4 = (*param_2 << 4 ^ *(byte *)(param_3 + 3)) & 0x70 ^ *(byte *)(param_3 + 3);
      *(ulonglong *)(param_3 + 0x20) = (ulonglong)*(uint *)(param_2 + 0x10);
      *(undefined4 *)(param_3 + 4) = *(undefined4 *)(param_2 + 0x18);
      bVar4 = (cVar1 << 2 ^ bVar4) & 4 ^ bVar4;
      *(char *)(param_3 + 1) = param_2[8];
      *(char *)(param_3 + 2) = param_2[0x28];
      *(byte *)(param_3 + 3) = (param_2[0x30] * '\x02' ^ bVar4) & 2 ^ bVar4;
      *(char *)(param_3 + 0x28) = param_2[0x38];
      return 0;
    }
    uVar3 = CiConfigQueryValue(param_1,puVar2,
                               (ulonglong *)
                               (param_2 + (ulonglong)(*(uint *)(puVar2 + 4) & 0x1f) * 8));
    if ((int)uVar3 < 0) break;
    uVar5 = (ulonglong)((int)uVar5 + 1);
  }
  return uVar3;
}



===== CiConfigQueryValue @ 14000fec0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong CiConfigQueryValue(undefined8 param_1,undefined8 *param_2,ulonglong *param_3)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  wchar_t *pwVar5;
  undefined8 uVar6;
  uint uVar7;
  undefined1 auStack_118 [32];
  wchar_t local_e0 [12];
  undefined1 local_c8 [8];
  uint local_c0;
  uint auStack_bc [17];
  wchar_t local_78 [32];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_118;
  local_e0[0] = L'\0';
  local_e0[1] = L'\0';
  local_e0[2] = L'\0';
  local_e0[3] = L'\0';
  local_e0[4] = L'\0';
  local_e0[5] = L'\0';
  local_e0[6] = L'\0';
  local_e0[7] = L'\0';
  RtlInitUnicodeStringEx(local_e0,*param_2);
  uVar4 = (ulonglong)*(uint *)(param_2 + 1);
  uVar6 = 2;
  pwVar5 = local_e0;
  uVar2 = ZwQueryValueKey(param_1,pwVar5,2,local_c8);
  if ((int)uVar2 < 0) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_Zd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                &WPP_350503daac883abe7be9cf63f89038d9_Traceguids,local_e0,(char)uVar2);
    }
LAB_14001005e:
    uVar2 = 0;
LAB_140010060:
    *param_3 = uVar4 & 0xffffffff;
    goto LAB_1400100a4;
  }
  uVar7 = *(uint *)(param_2 + 3) & 0x1f;
  if (uVar7 == 1) {
    if (local_c0 < 0x40) {
      memcpy(local_78,auStack_bc,(ulonglong)local_c0);
      if (0x3f < ((ulonglong)local_c0 & 0xfffffffe)) {
        __report_rangecheckfailure();
        pcVar1 = (code *)swi(3);
        uVar4 = (*pcVar1)();
        return uVar4;
      }
      *(undefined2 *)((longlong)local_78 + ((ulonglong)local_c0 & 0xfffffffe)) = 0;
      uVar2 = 0xc000000d;
      for (uVar7 = 0; uVar7 < *(uint *)((longlong)param_2 + 0x24); uVar7 = uVar7 + 1) {
        iVar3 = _wcsicmp(local_78,*(wchar_t **)(param_2[2] + (ulonglong)uVar7 * 0x10));
        if (iVar3 == 0) {
          uVar4 = *(ulonglong *)(param_2[2] + 8 + (ulonglong)uVar7 * 0x10);
          goto LAB_14001005e;
        }
      }
    }
    else {
      uVar2 = 0xc0000106;
    }
  }
  else {
    if (uVar7 == 2) {
      if (local_c0 == 4) {
        uVar4 = (ulonglong)auStack_bc[0];
        if (*(ulonglong *)param_2[2] <= uVar4) {
          if (uVar4 <= ((ulonglong *)param_2[2])[1]) goto LAB_140010060;
          uVar2 = 0xc000000d;
          goto LAB_140010072;
        }
      }
    }
    else if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),pwVar5,uVar6,uVar7);
    }
    uVar2 = 0xc000000d;
  }
LAB_140010072:
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_Zd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
              &WPP_350503daac883abe7be9cf63f89038d9_Traceguids,local_e0,(char)uVar2);
  }
LAB_1400100a4:
  if ((-1 < (int)uVar2) && ((*(byte *)((longlong)param_2 + 0x1c) & 1) != 0)) {
    *param_3 = *param_3 - 1;
  }
  return (ulonglong)uVar2;
}



===== CiTaskDump @ 1400100f0 =====

void CiTaskDump(byte *param_1,undefined8 param_2,undefined *param_3)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,
             *(wchar_t **)(param_1 + 0x18));
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_62da978b8000316eb1e6fce22b5cf66e_Traceguids;
    param_2 = 0xc;
    WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
             &WPP_62da978b8000316eb1e6fce22b5cf66e_Traceguids,*(undefined4 *)(param_1 + 4));
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_62da978b8000316eb1e6fce22b5cf66e_Traceguids;
    param_2 = 0xd;
    WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
             &WPP_62da978b8000316eb1e6fce22b5cf66e_Traceguids,(uint)*param_1);
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_62da978b8000316eb1e6fce22b5cf66e_Traceguids;
    param_2 = 0xe;
    WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
             &WPP_62da978b8000316eb1e6fce22b5cf66e_Traceguids,(uint)param_1[1]);
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_62da978b8000316eb1e6fce22b5cf66e_Traceguids;
    param_2 = 0xf;
    WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
             &WPP_62da978b8000316eb1e6fce22b5cf66e_Traceguids,param_1[3] >> 2 & 1);
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_62da978b8000316eb1e6fce22b5cf66e_Traceguids;
    param_2 = 0x10;
    WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
             &WPP_62da978b8000316eb1e6fce22b5cf66e_Traceguids,param_1[3] >> 4 & 7);
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_P(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,
             *(undefined8 *)(param_1 + 0x20));
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
             &WPP_62da978b8000316eb1e6fce22b5cf66e_Traceguids,param_1[3] >> 1 & 1);
  }
  return;
}



===== CiConfigTaskPolicy @ 140010280 =====

void CiConfigTaskPolicy(char *param_1)

{
  byte bVar1;
  ulonglong uVar2;
  bool bVar3;
  
  bVar1 = param_1[3];
  bVar3 = CiSystemResponsiveness == 100;
  param_1[3] = bVar1 & 0xfe;
  if (bVar3) {
    *param_1 = (&CiSchedulingCategoryPriorityMap)[bVar1 >> 4 & 7] + param_1[1];
  }
  else {
    if ((bVar1 & 0x70) == 0x30) {
      *param_1 = '\x18';
    }
    else {
      *param_1 = (&CiSchedulingCategoryPriorityMap)[bVar1 >> 4 & 7] + param_1[1];
      if ((bVar1 & 0x70) != 0x20) goto LAB_1400102f1;
    }
    param_1[3] = bVar1 & 0xfe | 1;
  }
LAB_1400102f1:
  uVar2 = *(ulonglong *)(param_1 + 0x20) & DAT_1400092f0;
  *(ulonglong *)(param_1 + 0x20) = uVar2;
  if (uVar2 == 0) {
    *(ulonglong *)(param_1 + 0x20) = DAT_1400092f0;
  }
  return;
}



===== CiConfigInitializeFromRegistry @ 140010320 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int CiConfigInitializeFromRegistry(undefined8 param_1)

{
  int iVar1;
  uint uVar2;
  wchar_t *_Dst;
  ulonglong uVar3;
  byte *pbVar4;
  char *pcVar5;
  int iVar6;
  undefined *puVar7;
  undefined1 auStack_1c8 [32];
  undefined8 local_190;
  byte *local_188;
  undefined8 local_180;
  undefined8 uStack_178;
  undefined8 *local_170;
  undefined8 uStack_168;
  undefined8 local_160;
  ulonglong uStack_158;
  undefined8 local_150;
  undefined8 uStack_148;
  char local_140 [56];
  char local_108 [64];
  undefined1 local_c8 [12];
  uint local_bc;
  undefined1 local_b8 [144];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_1c8;
  local_188 = (byte *)0x0;
  local_160 = 0;
  uStack_158 = uStack_158 & 0xffffffff00000000;
  local_190 = 0;
  local_180 = 0;
  uStack_178 = 0;
  local_170 = (undefined8 *)0x0;
  uStack_168 = 0;
  local_140[0] = '\0';
  local_140[1] = '\0';
  local_140[2] = '\0';
  local_140[3] = '\0';
  local_140[4] = '\0';
  local_140[5] = '\0';
  local_140[6] = '\0';
  local_140[7] = '\0';
  local_140[8] = '\0';
  local_140[9] = '\0';
  local_140[10] = '\0';
  local_140[0xb] = '\0';
  local_140[0xc] = '\0';
  local_140[0xd] = '\0';
  local_140[0xe] = '\0';
  local_140[0xf] = '\0';
  local_140[0x10] = '\0';
  local_140[0x11] = '\0';
  local_140[0x12] = '\0';
  local_140[0x13] = '\0';
  local_140[0x14] = '\0';
  local_140[0x15] = '\0';
  local_140[0x16] = '\0';
  local_140[0x17] = '\0';
  local_140[0x18] = '\0';
  local_140[0x19] = '\0';
  local_140[0x1a] = '\0';
  local_140[0x1b] = '\0';
  local_140[0x1c] = '\0';
  local_140[0x1d] = '\0';
  local_140[0x1e] = '\0';
  local_140[0x1f] = '\0';
  local_140[0x20] = '\0';
  local_140[0x21] = '\0';
  local_140[0x22] = '\0';
  local_140[0x23] = '\0';
  local_140[0x24] = '\0';
  local_140[0x25] = '\0';
  local_140[0x26] = '\0';
  local_140[0x27] = '\0';
  local_140[0x28] = '\0';
  local_140[0x29] = '\0';
  local_140[0x2a] = '\0';
  local_140[0x2b] = '\0';
  local_140[0x2c] = '\0';
  local_140[0x2d] = '\0';
  local_140[0x2e] = '\0';
  local_140[0x2f] = '\0';
  local_150 = 0;
  uStack_148 = 0;
  memset(local_108,0,0x40);
  iVar6 = 0;
  do {
    iVar1 = ZwEnumerateKey(param_1,iVar6,0,local_c8);
    if (iVar1 < 0) {
      if (iVar1 != -0x3fffffdd) {
        if (iVar1 == -0x7fffffe6) {
          iVar1 = 0;
        }
        else if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
                (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                   &WPP_350503daac883abe7be9cf63f89038d9_Traceguids,iVar1);
        }
        return iVar1;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                 &WPP_350503daac883abe7be9cf63f89038d9_Traceguids,0xc0000023);
      }
    }
    else if ((local_bc < 0x80) &&
            (_Dst = (wchar_t *)ExAllocatePool2(0x40,(ulonglong)(local_bc + 1) * 2),
            _Dst != (wchar_t *)0x0)) {
      memcpy(_Dst,local_b8,(ulonglong)local_bc);
      _Dst[local_bc >> 1] = L'\0';
      iVar1 = RtlInitUnicodeStringEx(&local_150,_Dst);
      if (-1 < iVar1) {
        local_170 = &local_150;
        local_180 = CONCAT44(local_180._4_4_,0x30);
        uStack_168 = CONCAT44(uStack_168._4_4_,0x40);
        local_160 = 0;
        uStack_158 = 0;
        uStack_178 = param_1;
        iVar1 = ZwOpenKey(&local_190,0x101);
        if (iVar1 < 0) {
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                     &WPP_350503daac883abe7be9cf63f89038d9_Traceguids,iVar1);
          }
        }
        else {
          uVar3 = CiConfigQueryTaskFromRegistry(local_190,local_108,(longlong)local_140);
          ZwClose(local_190);
          if (-1 < (int)uVar3) {
            CiConfigTaskPolicy(local_140);
            pcVar5 = local_140;
            uVar2 = CiTaskAllocate(_Dst,(undefined8 *)pcVar5,&local_188);
            puVar7 = (undefined *)(ulonglong)uVar2;
            if ((int)uVar2 < 0) {
              if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                WPP_SF_Sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                          &WPP_350503daac883abe7be9cf63f89038d9_Traceguids,(wchar_t *)0x0,
                          (char)uVar2);
              }
            }
            else {
              pbVar4 = local_188;
              CiConfigTaskPolicy((char *)local_188);
              CiTaskDump(pbVar4,pcVar5,puVar7);
            }
            goto LAB_1400105ad;
          }
        }
      }
      ExFreePoolWithTag(_Dst,0);
    }
LAB_1400105ad:
    iVar6 = iVar6 + 1;
  } while( true );
}


