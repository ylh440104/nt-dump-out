
===== BalanceUpdateStatsForStartingJob @ 1c0001010 =====

uint BalanceUpdateStatsForStartingJob(longlong param_1)

{
  uint *puVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong lVar5;
  longlong *plVar6;
  longlong lVar7;
  undefined1 auVar8 [16];
  undefined1 uVar9;
  ulonglong uVar10;
  longlong lVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  bool bVar14;
  
  uVar4 = *(ulonglong *)(param_1 + 0xa0);
  lVar5 = **(longlong **)(param_1 + 0x28);
  *(undefined1 *)(param_1 + 0x80) = 1;
  LOCK();
  plVar6 = *(longlong **)(param_1 + 0x28) + 0x19;
  *(int *)plVar6 = (int)*plVar6 + 1;
  UNLOCK();
  LOCK();
  *(int *)(lVar5 + 0x1028) = *(int *)(lVar5 + 0x1028) + 1;
  UNLOCK();
  plVar6 = *(longlong **)(param_1 + 0x28);
  uVar13 = 0;
  lVar11 = *(longlong *)(param_1 + 0x90);
  lVar7 = *plVar6;
  if (lVar11 == 0) {
    uVar12 = 0;
  }
  else {
    uVar10 = *(ulonglong *)(param_1 + 0x88) >> 9;
    uVar12 = lVar11 + 0x1ffU >> 9;
    LOCK();
    lVar3 = plVar6[0x1f];
    plVar6[0x1f] = uVar12 + uVar10;
    UNLOCK();
    LOCK();
    plVar6[0x20] = uVar10 - lVar3;
    UNLOCK();
  }
  *(bool *)(param_1 + 0x7f) = lVar11 != 0;
  lVar11 = *(longlong *)(lVar7 + 0x460);
  if (*(ulonglong *)(lVar7 + 0x4c8) != 0) {
    lVar11 = lVar11 + (ulonglong)(*(longlong *)(lVar7 + 0x4e0) * *(longlong *)(lVar7 + 0x478)) /
                      *(ulonglong *)(lVar7 + 0x4c8);
  }
  if (*(char *)(param_1 + 0x7f) != '\0') {
    lVar11 = lVar11 + *(longlong *)(lVar7 + 0x468);
  }
  uVar12 = lVar11 + uVar12 * *(longlong *)(lVar7 + 0x470);
  if ((longlong)uVar12 < 1) {
    uVar12 = 1;
  }
  else if (4000000000 < uVar12) {
    uVar12 = 4000000000;
  }
  *(ulonglong *)(param_1 + 0x98) = uVar12;
  if ((ulonglong)(*(longlong *)(lVar5 + 0xbc8) + DAT_1c000d2c0) <= uVar4) {
    LOCK();
    puVar1 = (uint *)(lVar5 + 0xb78);
    uVar2 = *puVar1;
    *puVar1 = *puVar1 | 1;
    UNLOCK();
    if ((uVar2 & 1) == 0) {
      BalanceCollectThroughputSample(lVar5,uVar4,(ulonglong *)(lVar5 + 0xbc8));
      if (DAT_1c000d320 <= uVar4 - *(longlong *)(lVar5 + 0xb80)) {
        *(ulonglong *)(lVar5 + 0xb80) = uVar4;
        if (((0x13 < *(uint *)(lVar5 + 0xb74)) && (0x13 < *(uint *)(lVar5 + 0xfa8))) &&
           (*(longlong *)(lVar5 + 0xba0) != 0)) {
          uVar12 = (ulonglong)DAT_1c000d2e4 * *(longlong *)(lVar5 + 0xba0);
          auVar8._8_8_ = 0;
          auVar8._0_8_ = uVar12;
          lVar11 = SUB168(ZEXT816(0x47ae147ae147ae15) * auVar8,8);
          BalanceComputeThroughputFunction
                    (lVar5 + 0xbc8,lVar11 + (uVar12 - lVar11 >> 1) >> 6,
                     *(ulonglong *)(lVar5 + 0xb90));
        }
        uVar9 = KeAcquireSpinLockRaiseToDpc(lVar5 + 0x440);
        *(undefined1 *)(lVar5 + 0x448) = uVar9;
        uVar10 = SqospAreExternalDeviceCostEstimatesValid(lVar5);
        uVar12 = DAT_1c000d2d0;
        if ((char)uVar10 == '\0') {
          if ((*(longlong *)(lVar5 + 0xfc0) == 0) || (*(int *)(lVar5 + 0x398) == 0)) {
            *(ulonglong *)(lVar5 + 0x458) = DAT_1c000d2d0;
          }
          else {
            lVar11 = *(longlong *)(lVar5 + 0x458);
            if (lVar11 == 0) {
              lVar11 = *(longlong *)(lVar5 + 0x3c0);
            }
            uVar12 = (ulonglong)(*(longlong *)(lVar5 + 0xfc0) + lVar11) >> 1;
            *(ulonglong *)(lVar5 + 0x458) = uVar12;
          }
        }
        else {
          uVar12 = *(ulonglong *)(lVar5 + 0x3c0);
        }
        KeReleaseSpinLock(lVar5 + 0x440);
        uVar10 = DAT_1c000d2d8;
        if ((DAT_1c000d2d8 <= uVar12) && (uVar10 = uVar12, DAT_1c000d2d0 < uVar12)) {
          uVar10 = DAT_1c000d2d0;
        }
        uVar12 = *(longlong *)(lVar5 + 0xfe0) - *(longlong *)(lVar5 + 0xbb0);
        *(longlong *)(lVar5 + 0xbb0) = *(longlong *)(lVar5 + 0xfe0);
        if (uVar12 != 0) {
          lVar11 = *(longlong *)(lVar5 + 0xba8);
          *(longlong *)(lVar5 + 0xba8) = *(longlong *)(lVar5 + 0x1038);
          uVar13 = ((ulonglong)(*(longlong *)(lVar5 + 0x1038) - lVar11) / uVar12) * DAT_1c000d298 >>
                   0x10;
        }
        if (uVar10 >> 1 < uVar13 * 100) {
          LOCK();
          *(uint *)(lVar5 + 0xb78) = *(uint *)(lVar5 + 0xb78) | 2;
          UNLOCK();
        }
        else {
          LOCK();
          *(uint *)(lVar5 + 0xb78) = *(uint *)(lVar5 + 0xb78) & 0xfffffffd;
          UNLOCK();
        }
        if (*(int *)(lVar5 + 0x39c) != 0) {
          *(ulonglong *)(lVar5 + 3000) = uVar10 >> 1;
          *(ulonglong *)(lVar5 + 0xbc0) = uVar13 * 100;
        }
      }
      LOCK();
      *(uint *)(lVar5 + 0xb78) = *(uint *)(lVar5 + 0xb78) & 0xfffffffe;
      UNLOCK();
    }
  }
  if (*(int *)(lVar5 + 0x480) == 3) {
    LOCK();
    bVar14 = *(int *)(lVar5 + 0x480) == 3;
    if (bVar14) {
      *(int *)(lVar5 + 0x480) = 4;
    }
    UNLOCK();
    if (bVar14) {
      BalanceUpdateCostEstimatesInternal(lVar5,uVar4);
    }
  }
  return CONCAT31((uint3)(*(uint *)(lVar5 + 0xb78) >> 9),(char)(*(uint *)(lVar5 + 0xb78) >> 1)) &
         0xffffff01;
}



===== SqospCompleteJob @ 1c0001370 =====

undefined8 SqospCompleteJob(longlong param_1,char param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 *puVar3;
  code *pcVar4;
  bool bVar5;
  undefined1 uVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  undefined8 uVar9;
  undefined8 ****ppppuVar10;
  undefined8 ****local_48;
  undefined8 ****local_40;
  longlong local_38;
  undefined *local_30;
  undefined8 local_28;
  undefined2 local_20;
  undefined1 local_1e;
  undefined4 local_1d;
  undefined1 local_19;
  
  uVar9 = 0;
  local_1d = 0;
  local_19 = 0;
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 8);
  uVar7 = KeQueryPerformanceCounter(0);
  FltReferenceContext(lVar1);
  local_30 = &DAT_1c000d180;
  local_20 = 0;
  local_1e = 0;
  local_28 = 0;
  *(undefined8 *)(param_1 + 0xb0) = uVar7;
  local_38 = lVar1;
  if (*(char *)(param_1 + 0x81) != '\0') {
    if (param_2 == '\0') {
      bVar5 = SqospTryAcquireDeviceLock(lVar1);
      if (!bVar5) {
        lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 8);
        *(undefined1 *)(param_1 + 0x7d) = 1;
        ExpInterlockedPushEntrySList(lVar2 + 0x110);
        SqospQueueDeviceTimer(lVar1);
        uVar9 = 1;
        goto LAB_1c00013ff;
      }
    }
    else {
      uVar6 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x340);
      *(undefined1 *)(lVar1 + 0x348) = uVar6;
    }
    local_40 = &local_48;
    local_48 = &local_48;
    puVar8 = (undefined8 *)SqospFlushDeferredJobList();
    while (puVar8 != (undefined8 *)0x0) {
      puVar3 = (undefined8 *)*puVar8;
      BalanceCompleteJob((longlong)(puVar8 + -8),(longlong)&local_38);
      ppppuVar10 = (undefined8 ****)(puVar8 + 4);
      if ((undefined8 *****)*local_40 != &local_48) {
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3);
        pcVar4 = (code *)swi(3);
        uVar7 = (*pcVar4)();
        return uVar7;
      }
      puVar8[5] = local_40;
      *ppppuVar10 = &local_48;
      *local_40 = ppppuVar10;
      puVar8 = puVar3;
      local_40 = ppppuVar10;
    }
    BalanceCompleteJob(param_1,(longlong)&local_38);
    KeReleaseSpinLock(lVar1 + 0x340);
    SqospCompleteJobsOutsideLock((longlong *)&local_48);
  }
  SqospDestroyJob(param_1);
LAB_1c00013ff:
  SqospProcessJobDispatcherContext(&local_38,(undefined8 *)0x0,uVar7);
  return uVar9;
}



===== SqosPostReadWrite @ 1c0001540 =====

undefined8 SqosPostReadWrite(longlong param_1,undefined8 param_2,longlong *param_3,uint param_4)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 *puVar3;
  code *pcVar4;
  bool bVar5;
  undefined1 uVar6;
  longlong lVar7;
  undefined8 *puVar8;
  undefined8 uVar9;
  undefined8 ****ppppuVar10;
  undefined8 ****local_48;
  undefined8 ****local_40;
  longlong local_38;
  undefined *local_30;
  undefined8 local_28;
  undefined2 local_20;
  undefined1 local_1e;
  undefined4 local_1d;
  undefined1 local_19;
  
  *param_3 = param_1;
  *(longlong **)(param_1 + 0x40) = param_3;
  uVar9 = 0;
  local_1d = 0;
  local_19 = 0;
  lVar1 = *(longlong *)(param_3[4] + 8);
  lVar7 = KeQueryPerformanceCounter(0);
  FltReferenceContext(lVar1);
  local_30 = &DAT_1c000d180;
  local_20 = 0;
  local_1e = 0;
  local_28 = 0;
  param_3[0x16] = lVar7;
  local_38 = lVar1;
  if (*(char *)((longlong)param_3 + 0x81) != '\0') {
    if ((param_4 & 1) == 0) {
      bVar5 = SqospTryAcquireDeviceLock(lVar1);
      if (!bVar5) {
        lVar2 = *(longlong *)(param_3[4] + 8);
        *(undefined1 *)((longlong)param_3 + 0x7d) = 1;
        ExpInterlockedPushEntrySList(lVar2 + 0x110);
        SqospQueueDeviceTimer(lVar1);
        uVar9 = 1;
        goto LAB_1c00015d6;
      }
    }
    else {
      uVar6 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x340);
      *(undefined1 *)(lVar1 + 0x348) = uVar6;
    }
    local_40 = &local_48;
    local_48 = &local_48;
    puVar8 = (undefined8 *)SqospFlushDeferredJobList();
    while (puVar8 != (undefined8 *)0x0) {
      puVar3 = (undefined8 *)*puVar8;
      BalanceCompleteJob((longlong)(puVar8 + -8),(longlong)&local_38);
      ppppuVar10 = (undefined8 ****)(puVar8 + 4);
      if ((undefined8 *****)*local_40 != &local_48) {
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3);
        pcVar4 = (code *)swi(3);
        uVar9 = (*pcVar4)();
        return uVar9;
      }
      puVar8[5] = local_40;
      *ppppuVar10 = &local_48;
      *local_40 = ppppuVar10;
      puVar8 = puVar3;
      local_40 = ppppuVar10;
    }
    BalanceCompleteJob((longlong)param_3,(longlong)&local_38);
    KeReleaseSpinLock(lVar1 + 0x340);
    SqospCompleteJobsOutsideLock((longlong *)&local_48);
  }
  SqospDestroyJob((longlong)param_3);
LAB_1c00015d6:
  SqospProcessJobDispatcherContext(&local_38,(undefined8 *)0x0,lVar7);
  return uVar9;
}



===== SqospStartJob @ 1c0001720 =====

int SqospStartJob(longlong *param_1)

{
  uint *puVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong lVar6;
  undefined1 auVar7 [16];
  byte bVar8;
  char cVar9;
  undefined1 uVar10;
  int iVar11;
  longlong lVar12;
  ulonglong uVar13;
  longlong lVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  bool bVar17;
  longlong local_48;
  undefined *local_40;
  longlong local_38;
  undefined2 local_30;
  undefined1 local_2e;
  undefined4 local_2d;
  undefined1 local_29;
  
  local_2d = 0;
  local_29 = 0;
  lVar4 = *(longlong *)(param_1[4] + 8);
  lVar12 = KeQueryPerformanceCounter(0);
  FltReferenceContext(lVar4);
  local_40 = &DAT_1c000d180;
  local_30 = 0;
  local_2e = 0;
  local_48 = lVar4;
  bVar8 = KeGetCurrentIrql();
  if ((bVar8 < 2) && (cVar9 = KeAreAllApcsDisabled(), cVar9 == '\0')) {
    local_38 = (ulonglong)SystemReserved1[0x12]._4_4_ * 0x40 + DAT_1c000d1d0;
  }
  else {
    local_38 = 0;
  }
  param_1[0x14] = lVar12;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  lVar4 = *(longlong *)(*param_1 + 0x10);
  cVar9 = *(char *)(lVar4 + 4);
  if (cVar9 == '\x04') {
    param_1[0x11] = *(longlong *)(lVar4 + 0x28);
    uVar15 = (ulonglong)*(uint *)(lVar4 + 0x18);
  }
  else if (cVar9 == '\x03') {
    param_1[0x11] = *(longlong *)(lVar4 + 0x28);
    uVar15 = (ulonglong)*(uint *)(lVar4 + 0x18);
  }
  else {
    uVar15 = 0;
    if (cVar9 != '\r') goto LAB_1c0001806;
    if (*(int *)(lVar4 + 0x28) == 0x98268) {
      lVar14 = *(longlong *)(lVar4 + 0x30);
      param_1[0x11] = *(longlong *)(lVar14 + 8);
      uVar15 = *(ulonglong *)(lVar14 + 0x10);
      param_1[0x12] = uVar15;
    }
    if (*(int *)(lVar4 + 0x28) != 0x980c8) goto LAB_1c0001806;
    plVar5 = *(longlong **)(lVar4 + 0x30);
    param_1[0x11] = *plVar5;
    uVar15 = plVar5[1] - *plVar5;
  }
  param_1[0x12] = uVar15;
LAB_1c0001806:
  lVar4 = param_1[5];
  if ((((*(char *)(*(longlong *)(lVar4 + 8) + 0x7e) == '\0') || (uVar15 == 0)) ||
      ((*(longlong *)(lVar4 + 0x1c8) == 0 && (*(longlong *)(lVar4 + 0x1d0) == 0)))) ||
     (bVar17 = SqospLimiterStartJobInternal(param_1,(longlong)&local_48), bVar17)) {
    plVar5 = (longlong *)param_1[5];
    uVar15 = param_1[0x14];
    lVar4 = *plVar5;
    *(undefined1 *)(param_1 + 0x10) = 1;
    LOCK();
    plVar5 = plVar5 + 0x19;
    *(int *)plVar5 = (int)*plVar5 + 1;
    UNLOCK();
    LOCK();
    *(int *)(lVar4 + 0x1028) = *(int *)(lVar4 + 0x1028) + 1;
    UNLOCK();
    plVar5 = (longlong *)param_1[5];
    lVar14 = param_1[0x12];
    lVar6 = *plVar5;
    if (lVar14 == 0) {
      uVar16 = 0;
    }
    else {
      uVar13 = param_1[0x11];
      uVar16 = lVar14 + 0x1ffU >> 9;
      LOCK();
      lVar3 = plVar5[0x1f];
      plVar5[0x1f] = uVar16 + (uVar13 >> 9);
      UNLOCK();
      LOCK();
      plVar5[0x20] = (uVar13 >> 9) - lVar3;
      UNLOCK();
    }
    *(bool *)((longlong)param_1 + 0x7f) = lVar14 != 0;
    lVar14 = *(longlong *)(lVar6 + 0x460);
    if (*(ulonglong *)(lVar6 + 0x4c8) != 0) {
      lVar14 = lVar14 + (ulonglong)(*(longlong *)(lVar6 + 0x4e0) * *(longlong *)(lVar6 + 0x478)) /
                        *(ulonglong *)(lVar6 + 0x4c8);
    }
    if (*(char *)((longlong)param_1 + 0x7f) != '\0') {
      lVar14 = lVar14 + *(longlong *)(lVar6 + 0x468);
    }
    uVar16 = lVar14 + uVar16 * *(longlong *)(lVar6 + 0x470);
    if ((longlong)uVar16 < 1) {
      uVar16 = 1;
    }
    else if (4000000000 < uVar16) {
      uVar16 = 4000000000;
    }
    param_1[0x13] = uVar16;
    if ((ulonglong)(*(longlong *)(lVar4 + 0xbc8) + DAT_1c000d2c0) <= uVar15) {
      LOCK();
      puVar1 = (uint *)(lVar4 + 0xb78);
      uVar2 = *puVar1;
      *puVar1 = *puVar1 | 1;
      UNLOCK();
      if ((uVar2 & 1) == 0) {
        BalanceCollectThroughputSample(lVar4,uVar15,(ulonglong *)(lVar4 + 0xbc8));
        if (DAT_1c000d320 <= uVar15 - *(longlong *)(lVar4 + 0xb80)) {
          *(ulonglong *)(lVar4 + 0xb80) = uVar15;
          if (((0x13 < *(uint *)(lVar4 + 0xb74)) && (0x13 < *(uint *)(lVar4 + 0xfa8))) &&
             (*(longlong *)(lVar4 + 0xba0) != 0)) {
            uVar16 = (ulonglong)DAT_1c000d2e4 * *(longlong *)(lVar4 + 0xba0);
            auVar7._8_8_ = 0;
            auVar7._0_8_ = uVar16;
            lVar14 = SUB168(ZEXT816(0x47ae147ae147ae15) * auVar7,8);
            BalanceComputeThroughputFunction
                      (lVar4 + 0xbc8,lVar14 + (uVar16 - lVar14 >> 1) >> 6,
                       *(ulonglong *)(lVar4 + 0xb90));
          }
          uVar10 = KeAcquireSpinLockRaiseToDpc(lVar4 + 0x440);
          *(undefined1 *)(lVar4 + 0x448) = uVar10;
          uVar13 = SqospAreExternalDeviceCostEstimatesValid(lVar4);
          uVar16 = DAT_1c000d2d0;
          if ((char)uVar13 == '\0') {
            if ((*(longlong *)(lVar4 + 0xfc0) == 0) || (*(int *)(lVar4 + 0x398) == 0)) {
              *(ulonglong *)(lVar4 + 0x458) = DAT_1c000d2d0;
            }
            else {
              lVar14 = *(longlong *)(lVar4 + 0x458);
              if (lVar14 == 0) {
                lVar14 = *(longlong *)(lVar4 + 0x3c0);
              }
              uVar16 = (ulonglong)(*(longlong *)(lVar4 + 0xfc0) + lVar14) >> 1;
              *(ulonglong *)(lVar4 + 0x458) = uVar16;
            }
          }
          else {
            uVar16 = *(ulonglong *)(lVar4 + 0x3c0);
          }
          KeReleaseSpinLock(lVar4 + 0x440);
          uVar13 = DAT_1c000d2d8;
          if ((DAT_1c000d2d8 <= uVar16) && (uVar13 = uVar16, DAT_1c000d2d0 < uVar16)) {
            uVar13 = DAT_1c000d2d0;
          }
          uVar16 = *(longlong *)(lVar4 + 0xfe0) - *(longlong *)(lVar4 + 0xbb0);
          *(longlong *)(lVar4 + 0xbb0) = *(longlong *)(lVar4 + 0xfe0);
          if (uVar16 == 0) {
            uVar16 = 0;
          }
          else {
            lVar14 = *(longlong *)(lVar4 + 0xba8);
            *(longlong *)(lVar4 + 0xba8) = *(longlong *)(lVar4 + 0x1038);
            uVar16 = ((ulonglong)(*(longlong *)(lVar4 + 0x1038) - lVar14) / uVar16) * DAT_1c000d298
                     >> 0x10;
          }
          if (uVar13 >> 1 < uVar16 * 100) {
            LOCK();
            *(uint *)(lVar4 + 0xb78) = *(uint *)(lVar4 + 0xb78) | 2;
            UNLOCK();
          }
          else {
            LOCK();
            *(uint *)(lVar4 + 0xb78) = *(uint *)(lVar4 + 0xb78) & 0xfffffffd;
            UNLOCK();
          }
          if (*(int *)(lVar4 + 0x39c) != 0) {
            *(ulonglong *)(lVar4 + 3000) = uVar13 >> 1;
            *(ulonglong *)(lVar4 + 0xbc0) = uVar16 * 100;
          }
        }
        LOCK();
        *(uint *)(lVar4 + 0xb78) = *(uint *)(lVar4 + 0xb78) & 0xfffffffe;
        UNLOCK();
      }
    }
    if (*(int *)(lVar4 + 0x480) == 3) {
      LOCK();
      bVar17 = *(int *)(lVar4 + 0x480) == 3;
      if (bVar17) {
        *(int *)(lVar4 + 0x480) = 4;
      }
      UNLOCK();
      if (bVar17) {
        BalanceUpdateCostEstimatesInternal(lVar4,uVar15);
      }
    }
    if ((*(uint *)(lVar4 + 0xb78) & 2) == 0) {
      param_1[0x15] = lVar12;
      SqospProcessJobDispatcherContext(&local_48,(undefined8 *)0x0,lVar12);
      return 0;
    }
    iVar11 = SqospProcessJobDispatcherContext(&local_48,param_1,lVar12);
    if (param_1 != (longlong *)0x0) {
      return iVar11;
    }
  }
  else {
    SqospProcessJobDispatcherContext(&local_48,(undefined8 *)0x0,lVar12);
  }
  return 2;
}



===== SqospProcessJobDispatcherContext @ 1c0001c80 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int SqospProcessJobDispatcherContext(longlong *param_1,undefined8 *param_2,undefined8 param_3)

{
  uint *puVar1;
  uint uVar2;
  undefined8 *puVar3;
  byte bVar4;
  int iVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  longlong lVar8;
  char local_res8 [8];
  
  lVar8 = *param_1;
  iVar5 = 2;
  if (lVar8 == 0) goto LAB_1c0001cd9;
  if ((char)param_1[3] != '\0') {
    SqospLimiterProcessQueue(lVar8,(longlong)param_1);
    lVar8 = *param_1;
  }
  if ((*(char *)((longlong)param_1 + 0x19) == '\0') && (param_2 == (undefined8 *)0x0)) {
LAB_1c0001cb9:
    if (((DAT_1c000d218 != 0) && (*(int *)(lVar8 + 0xbc) == 2)) &&
       (*(ulonglong *)(lVar8 + 0x10c8) <= _DAT_fffff78000000008)) {
      LOCK();
      puVar1 = (uint *)(lVar8 + 0x1040);
      uVar2 = *puVar1;
      *puVar1 = *puVar1 | 1;
      UNLOCK();
      if (((uVar2 & 1) == 0) && (bVar4 = SqospQueueStatsWorkItem(lVar8), bVar4 == 0)) {
        LOCK();
        *(uint *)(lVar8 + 0x1040) = *(uint *)(lVar8 + 0x1040) & 0xfffffffe;
        UNLOCK();
      }
    }
  }
  else {
    local_res8[0] = '\0';
    iVar5 = SqospProcessBalancerQueue(param_1,param_2,param_3,local_res8);
    if (local_res8[0] != '\0') {
      lVar8 = *param_1;
      goto LAB_1c0001cb9;
    }
  }
  FltReleaseContext(*param_1);
  *param_1 = 0;
LAB_1c0001cd9:
  if (((ulonglong *)param_1[2] != (ulonglong *)0x0) && (*(char *)((longlong)param_1 + 0x1a) != '\0')
     ) {
    puVar6 = (undefined8 *)DvRemoveOrderedWorkQueue((ulonglong *)param_1[2]);
    while (puVar6 != (undefined8 *)0x0) {
      do {
        puVar3 = (undefined8 *)*puVar6;
        *puVar6 = 0;
        uVar7 = KeQueryPerformanceCounter(0);
        puVar6[7] = uVar7;
        SqospDispatchDeferredJob(puVar6 + -0xe);
        puVar6 = puVar3;
      } while (puVar3 != (undefined8 *)0x0);
      puVar6 = (undefined8 *)DvRemoveOrderedWorkQueue((ulonglong *)param_1[2]);
    }
  }
  return iVar5;
}



===== SqospDestroyJob @ 1c0001df0 =====

void SqospDestroyJob(longlong param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  byte bVar4;
  undefined8 uVar5;
  longlong lVar6;
  
  if (*(char *)(param_1 + 0x80) != '\0') {
    uVar5 = BalanceUpdateStatsForCompletedJob(param_1);
    if ((((char)uVar5 != '\0') && (DAT_1c000d218 != 0)) &&
       (*(int *)(**(longlong **)(param_1 + 0x28) + 0xbc) == 2)) {
      SqospSetVolumeStatsTimer(**(longlong **)(param_1 + 0x28));
    }
  }
  lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 8);
  LOCK();
  piVar1 = (int *)(lVar3 + 0xc);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    if (*(char *)(lVar3 + 0x7d) == '\0') {
      SqospCleanupClient(lVar3);
    }
    else {
      bVar4 = KeGetCurrentIrql();
      if (bVar4 < 2) {
        SqospRemoveClient(lVar3);
      }
      else {
        FltQueueGenericWorkItem
                  (DAT_1c000d280,DAT_1c000d208,SqospClientRemovalWorkItemRoutine,1,lVar3);
      }
    }
  }
  lVar3 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x20) + 8) + 0x90);
  lVar6 = (ulonglong)(*(int *)(param_1 + 0x78) + 1) * 0x80 + lVar3;
  if (*(char *)(lVar6 + 0xb0) == '\0') {
    PplpLazyInitializeLookasideList(lVar3,lVar6 + 0x40);
  }
  ExFreeToLookasideListEx(lVar6 + 0x40,param_1);
  return;
}



===== BalanceUpdateStatsForCompletedJob @ 1c0001f10 =====

undefined8 BalanceUpdateStatsForCompletedJob(longlong param_1)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  longlong *plVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  
  lVar6 = *(longlong *)(param_1 + 0xa8);
  if (lVar6 == 0) {
    lVar6 = *(longlong *)(param_1 + 0xa0);
    *(longlong *)(param_1 + 0xa8) = lVar6;
    lVar7 = lVar6;
  }
  else {
    lVar7 = *(longlong *)(param_1 + 0xa0);
  }
  lVar5 = *(longlong *)(param_1 + 0xb0);
  if (*(longlong *)(param_1 + 0xb0) == 0) {
    *(longlong *)(param_1 + 0xb0) = lVar6;
    lVar5 = lVar6;
  }
  lVar6 = *(longlong *)(param_1 + 0x28);
  LOCK();
  *(longlong *)(lVar6 + 0xe8) = *(longlong *)(lVar6 + 0xe8) + (lVar5 - lVar7);
  UNLOCK();
  LOCK();
  *(longlong *)(lVar6 + 0xf0) =
       *(longlong *)(lVar6 + 0xf0) + (*(longlong *)(param_1 + 0xb0) - *(longlong *)(param_1 + 0xa8))
  ;
  UNLOCK();
  LOCK();
  *(longlong *)(lVar6 + 0xd8) =
       *(longlong *)(lVar6 + 0xd8) +
       ((ulonglong)(*(longlong *)(param_1 + 0x90) + (1L << ((byte)DAT_1c000d2a4 & 0x3f)) + -1) >>
       ((byte)DAT_1c000d2a4 & 0x3f));
  UNLOCK();
  LOCK();
  *(longlong *)(lVar6 + 0xe0) =
       *(longlong *)(lVar6 + 0xe0) + (*(longlong *)(param_1 + 0x90) + 0x3ffU >> 10);
  UNLOCK();
  LOCK();
  *(longlong *)(lVar6 + 0xd0) = *(longlong *)(lVar6 + 0xd0) + 1;
  UNLOCK();
  if ((ulonglong)(*(longlong *)(lVar6 + 0x148) + DAT_1c000d318) <= *(ulonglong *)(param_1 + 0xb0)) {
    LOCK();
    puVar2 = (uint *)(lVar6 + 0x140);
    uVar3 = *puVar2;
    *puVar2 = *puVar2 | 1;
    UNLOCK();
    if ((uVar3 & 1) == 0) {
      BalanceUpdateFlowAverageStats(lVar6,*(ulonglong *)(param_1 + 0xb0));
      LOCK();
      *(uint *)(lVar6 + 0x140) = *(uint *)(lVar6 + 0x140) & 0xfffffffe;
      UNLOCK();
    }
  }
  BalanceUpdateDeviceStats(**(longlong **)(param_1 + 0x28),param_1);
  LOCK();
  piVar1 = (int *)(*(longlong *)(param_1 + 0x28) + 200);
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  plVar4 = *(longlong **)(param_1 + 0x28);
  LOCK();
  piVar1 = (int *)(*plVar4 + 0x1028);
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  return CONCAT71((int7)((ulonglong)plVar4 >> 8),*piVar1 == 0);
}



===== BalanceUpdateDeviceStats @ 1c0002050 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong BalanceUpdateDeviceStats(longlong param_1,longlong param_2)

{
  uint *puVar1;
  uint uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  longlong lVar6;
  int iVar7;
  bool bVar8;
  
  LOCK();
  *(longlong *)(param_1 + 0x1030) =
       *(longlong *)(param_1 + 0x1030) +
       (*(longlong *)(param_2 + 0xb0) - *(longlong *)(param_2 + 0xa0));
  UNLOCK();
  LOCK();
  *(longlong *)(param_1 + 0x1038) =
       *(longlong *)(param_1 + 0x1038) +
       (*(longlong *)(param_2 + 0xb0) - *(longlong *)(param_2 + 0xa8));
  UNLOCK();
  LOCK();
  *(longlong *)(param_1 + 0xfc8) = *(longlong *)(param_1 + 0xfc8) + *(longlong *)(param_2 + 0x98);
  UNLOCK();
  LOCK();
  *(longlong *)(param_1 + 0xff8) =
       *(longlong *)(param_1 + 0xff8) +
       ((ulonglong)(*(longlong *)(param_2 + 0x90) + -1 + (1L << ((byte)DAT_1c000d2a4 & 0x3f))) >>
       ((byte)DAT_1c000d2a4 & 0x3f));
  UNLOCK();
  LOCK();
  *(longlong *)(param_1 + 0x1010) =
       *(longlong *)(param_1 + 0x1010) + (*(longlong *)(param_2 + 0x90) + 0x3ffU >> 10);
  UNLOCK();
  LOCK();
  *(longlong *)(param_1 + 0xfe0) = *(longlong *)(param_1 + 0xfe0) + 1;
  UNLOCK();
  if (*(int *)(param_1 + 0x480) == 2) {
    uVar4 = *(longlong *)(param_2 + 0x90) + 0x1ffU >> 9;
    LOCK();
    *(longlong *)(param_1 + 0x4a0) = *(longlong *)(param_1 + 0x4a0) + 1;
    UNLOCK();
    if (uVar4 != 0) {
      LOCK();
      *(longlong *)(param_1 + 0x4b0) = *(longlong *)(param_1 + 0x4b0) + uVar4;
      UNLOCK();
      if (*(char *)(param_2 + 0x7f) != '\0') {
        LOCK();
        *(longlong *)(param_1 + 0x4a8) = *(longlong *)(param_1 + 0x4a8) + 1;
        UNLOCK();
      }
      LOCK();
      lVar6 = *(longlong *)(param_1 + 0x498);
      *(longlong *)(param_1 + 0x498) = *(longlong *)(param_2 + 0x28);
      UNLOCK();
      if ((lVar6 != 0) && (*(longlong *)(param_2 + 0x28) != lVar6)) {
        LOCK();
        *(longlong *)(param_1 + 0x4b8) = *(longlong *)(param_1 + 0x4b8) + 1;
        UNLOCK();
      }
    }
    uVar2 = *(uint *)(param_1 + 0x1028);
    if (uVar2 < *(uint *)(param_1 + 0x4f0)) {
      LOCK();
      if (*(uint *)(param_1 + 0x4f0) == *(uint *)(param_1 + 0x4f0)) {
        *(uint *)(param_1 + 0x4f0) = uVar2;
      }
      UNLOCK();
    }
    if (uVar2 < *(uint *)(param_1 + 0x4e8)) {
      LOCK();
      if (*(int *)(param_1 + 0x480) == 2) {
        *(int *)(param_1 + 0x480) = 0;
      }
      UNLOCK();
    }
  }
  if ((*(int *)(param_1 + 0x480) == 0) &&
     ((ulonglong)(*(longlong *)(param_1 + 0x490) + _DAT_1c000d2f0) <= *(ulonglong *)(param_2 + 0xb0)
     )) {
    LOCK();
    bVar8 = *(int *)(param_1 + 0x480) == 0;
    if (bVar8) {
      *(int *)(param_1 + 0x480) = 1;
    }
    UNLOCK();
    if (bVar8) {
      lVar6 = 4;
      uVar4 = *(longlong *)(param_2 + 0xb0) - *(longlong *)(param_1 + 0x4f8);
      if (uVar4 < DAT_1c000d2f8) {
        iVar7 = (int)(((DAT_1c000d2f8 - uVar4) * (ulonglong)(*(int *)(param_1 + 0x4f4) - 4)) /
                     DAT_1c000d2f8) + 4;
      }
      else {
        iVar7 = 4;
      }
      uVar2 = (uint)(iVar7 * 0x3c) / 100;
      if (*(uint *)(param_1 + 0x1028) < uVar2) {
        LOCK();
        if (*(int *)(param_1 + 0x480) == 1) {
          *(int *)(param_1 + 0x480) = 0;
        }
        UNLOCK();
      }
      else {
        puVar5 = (undefined8 *)(param_1 + 0x4a0);
        do {
          LOCK();
          *puVar5 = 0;
          UNLOCK();
          lVar6 = lVar6 + -1;
          puVar5 = puVar5 + 1;
        } while (lVar6 != 0);
        LOCK();
        *(undefined8 *)(param_1 + 0x498) = 0;
        UNLOCK();
        uVar3 = *(undefined8 *)(param_2 + 0xb0);
        *(undefined4 *)(param_1 + 0x4f0) = *(undefined4 *)(param_1 + 0x1028);
        *(undefined8 *)(param_1 + 0x488) = uVar3;
        *(uint *)(param_1 + 0x4e8) = uVar2;
        *(int *)(param_1 + 0x4ec) = iVar7;
        LOCK();
        if (*(int *)(param_1 + 0x480) == 1) {
          *(int *)(param_1 + 0x480) = 2;
        }
        UNLOCK();
      }
    }
  }
  uVar4 = (ulonglong)*(uint *)(param_1 + 0x480);
  if ((*(uint *)(param_1 + 0x480) == 2) &&
     ((ulonglong)(*(longlong *)(param_1 + 0x488) + _DAT_1c000d2e8) <= *(ulonglong *)(param_2 + 0xb0)
     )) {
    uVar4 = 2;
    LOCK();
    uVar2 = *(uint *)(param_1 + 0x480);
    if (uVar2 == 2) {
      *(uint *)(param_1 + 0x480) = 1;
    }
    else {
      uVar4 = (ulonglong)uVar2;
    }
    UNLOCK();
    if (uVar2 == 2) {
      uVar4 = *(longlong *)(param_1 + 0xfe0) - *(longlong *)(param_1 + 0x500);
      *(longlong *)(param_1 + 0x500) = *(longlong *)(param_1 + 0xfe0);
      if (uVar4 == 0) {
        uVar4 = 0;
      }
      else {
        lVar6 = *(longlong *)(param_1 + 0x508);
        *(longlong *)(param_1 + 0x508) = *(longlong *)(param_1 + 0x1038);
        uVar4 = ((ulonglong)(*(longlong *)(param_1 + 0x1038) - lVar6) / uVar4) * DAT_1c000d298 >>
                0x10;
      }
      if (uVar4 * 100 < DAT_1c000d2d8 / 10) {
        uVar4 = 1;
        LOCK();
        uVar2 = *(uint *)(param_1 + 0x480);
        if (uVar2 == 1) {
          *(uint *)(param_1 + 0x480) = 0;
        }
        else {
          uVar4 = (ulonglong)uVar2;
        }
        UNLOCK();
      }
      else {
        *(ulonglong *)(param_1 + 0x4c0) =
             (1000000000 / DAT_1c000d2c0) *
             (*(longlong *)(param_2 + 0xb0) - *(longlong *)(param_1 + 0x488));
        if (*(uint *)(param_1 + 0x4ec) < *(uint *)(param_1 + 0x4f0)) {
          *(uint *)(param_1 + 0x4f4) = *(uint *)(param_1 + 0x4f0);
          *(undefined8 *)(param_1 + 0x4f8) = *(undefined8 *)(param_2 + 0xb0);
        }
        uVar4 = 1;
        LOCK();
        uVar2 = *(uint *)(param_1 + 0x480);
        if (uVar2 == 1) {
          *(uint *)(param_1 + 0x480) = 3;
        }
        else {
          uVar4 = (ulonglong)uVar2;
        }
        UNLOCK();
      }
    }
  }
  if (*(longlong *)(param_1 + 0xb88) + DAT_1c000d310 <= *(ulonglong *)(param_2 + 0xb0)) {
    LOCK();
    puVar1 = (uint *)(param_1 + 0xb78);
    uVar2 = *puVar1;
    *puVar1 = *puVar1 | 1;
    UNLOCK();
    if ((uVar2 & 1) == 0) {
      uVar4 = *(ulonglong *)(param_2 + 0xb0);
      if (*(longlong *)(param_1 + 0xb88) + DAT_1c000d310 <= uVar4) {
        uVar4 = (uVar4 - *(longlong *)(param_1 + 0xb88)) / DAT_1c000d310;
        BalanceUpdateMovingAverage(uVar4,(longlong *)(param_1 + 0xfc8));
        BalanceUpdateMovingAverage(uVar4,(longlong *)(param_1 + 0xfe0));
        BalanceUpdateMovingAverage(uVar4,(longlong *)(param_1 + 0xff8));
        uVar4 = BalanceUpdateMovingAverage(uVar4,(longlong *)(param_1 + 0x1010));
        *(undefined8 *)(param_1 + 0xb88) = *(undefined8 *)(param_2 + 0xb0);
        if (*(ulonglong *)(param_1 + 0xff0) != 0) {
          uVar4 = *(ulonglong *)(param_1 + 0xfd8) / *(ulonglong *)(param_1 + 0xff0);
          *(ulonglong *)(param_1 + 0xb90) = uVar4;
        }
        if (*(ulonglong *)(param_1 + 0x1008) != 0) {
          uVar4 = *(ulonglong *)(param_1 + 0xfd8) / *(ulonglong *)(param_1 + 0x1008);
          *(ulonglong *)(param_1 + 0xb98) = uVar4;
        }
        if ((0x14 < *(uint *)(param_1 + 0xb74)) && (*(ulonglong *)(param_1 + 0xb98) != 0)) {
          uVar4 = 1000000000 / *(ulonglong *)(param_1 + 0xb98);
          *(ulonglong *)(param_1 + 0xba0) = uVar4;
        }
      }
      LOCK();
      *(uint *)(param_1 + 0xb78) = *(uint *)(param_1 + 0xb78) & 0xfffffffe;
      UNLOCK();
    }
  }
  return uVar4;
}



===== BalanceUpdateFlowAverageStats @ 1c00024f0 =====

void BalanceUpdateFlowAverageStats(longlong param_1,ulonglong param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  uint uVar6;
  
  uVar3 = DAT_1c000d318;
  lVar1 = *(longlong *)(param_1 + 0x148);
  if (lVar1 + DAT_1c000d318 <= param_2) {
    *(ulonglong *)(param_1 + 0x148) = param_2;
    uVar5 = param_2 - lVar1;
    lVar1 = *(longlong *)(param_1 + 0x158);
    *(longlong *)(param_1 + 0x158) = *(longlong *)(param_1 + 0xe8);
    *(int *)(param_1 + 0x178) =
         (int)((ulonglong)((*(longlong *)(param_1 + 0xe8) - lVar1) * 0x400) / uVar5);
    uVar2 = (*(longlong *)(param_1 + 0xd8) - *(longlong *)(param_1 + 0x150)) * DAT_1c000d2c0;
    *(longlong *)(param_1 + 0x150) = *(longlong *)(param_1 + 0xd8);
    *(ulonglong *)(param_1 + 0x168) = uVar2 / uVar5;
    uVar2 = (*(longlong *)(param_1 + 0xe0) - *(longlong *)(param_1 + 0x160)) * DAT_1c000d2c0;
    *(longlong *)(param_1 + 0x160) = *(longlong *)(param_1 + 0xe0);
    uVar4 = 0;
    *(ulonglong *)(param_1 + 0x170) = uVar2 / uVar5;
    if (0x397 < *(uint *)(param_1 + 0x178)) {
      uVar4 = (ulonglong)(*(ulonglong *)(param_1 + 0x168) < *(ulonglong *)(param_1 + 0x1c0));
    }
    uVar6 = (uint)(uVar5 / uVar3);
    if (uVar6 < 0xf) {
      if (uVar6 != 0) {
        uVar2 = *(ulonglong *)(param_1 + 0x180);
        uVar3 = uVar5 / uVar3 & 0xffffffff;
        do {
          if ((uVar2 >> 0xe & 1) != 0) {
            *(int *)(param_1 + 0x188) = *(int *)(param_1 + 0x188) + -1;
          }
          uVar2 = uVar2 * 2;
          uVar3 = uVar3 - 1;
        } while (uVar3 != 0);
        *(ulonglong *)(param_1 + 0x180) = uVar2;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x188) = 0;
      *(undefined8 *)(param_1 + 0x180) = 0;
    }
    *(int *)(param_1 + 0x188) = *(int *)(param_1 + 0x188) + (int)uVar4;
    *(ulonglong *)(param_1 + 0x180) = *(uint *)(param_1 + 0x180) & 0x7fff | uVar4;
  }
  return;
}



===== BalanceUpdateMovingAverage @ 1c0002640 =====

void BalanceUpdateMovingAverage(longlong param_1,longlong *param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  uVar1 = param_2[2];
  lVar3 = *param_2 - param_2[1];
  uVar4 = uVar1 * param_1 >> 5;
  param_2[1] = *param_2;
  lVar2 = (uVar1 - uVar4) + lVar3;
  if (uVar1 < uVar4) {
    lVar2 = lVar3;
  }
  param_2[2] = lVar2;
  return;
}



===== SqospProcessBalancerQueue @ 1c0002680 =====

int SqospProcessBalancerQueue
              (undefined8 *param_1,undefined8 *param_2,undefined8 param_3,undefined1 *param_4)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  longlong lVar3;
  bool bVar4;
  int iVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  undefined8 *puVar8;
  int iVar9;
  undefined8 ****local_28;
  undefined8 ****local_20;
  
  puVar2 = (undefined8 *)*param_1;
  iVar9 = 2;
  puVar8 = param_2;
  bVar4 = SqospTryAcquireDeviceLock((longlong)puVar2);
  if (bVar4) {
    local_20 = &local_28;
    local_28 = &local_28;
    SqospFlushDeferredJobCompletions(puVar2,puVar8,(longlong)param_1,(longlong)&local_28);
    puVar6 = (undefined8 *)SqospFlushDeferredJobList();
    while (puVar6 != (undefined8 *)0x0) {
      puVar1 = puVar6 + -6;
      puVar6 = (undefined8 *)*puVar6;
      SqospStartJobLocked(puVar1,puVar8,(longlong)param_1);
    }
    if (param_2 != (undefined8 *)0x0) {
      iVar5 = SqospStartJobLocked(param_2,puVar8,(longlong)param_1);
      if (iVar5 == 0) {
        param_2[0x15] = param_3;
        iVar9 = 0;
      }
      else if (iVar5 != 1) {
        iVar9 = 1;
      }
    }
    uVar7 = SqospCheckVolumeStatsLocked((longlong)puVar2);
    KeReleaseSpinLock(puVar2 + 0x68,*(undefined1 *)(puVar2 + 0x69));
    SqospCompleteJobsOutsideLock((longlong *)&local_28);
    if ((char)uVar7 != '\0') {
      SqospQueueVolumeStatsNotification(puVar2);
    }
    if ((param_2 != (undefined8 *)0x0) && (iVar9 == 1)) {
      SqospDestroyJob((longlong)param_2);
    }
    *param_4 = 0;
  }
  else {
    if (param_2 != (undefined8 *)0x0) {
      lVar3 = *(longlong *)(param_2[4] + 8);
      *(undefined1 *)((longlong)param_2 + 0x7c) = 1;
      ExpInterlockedPushEntrySList(lVar3 + 0x100,param_2 + 6);
    }
    SqospQueueDeviceTimer((longlong)puVar2);
    *param_4 = 1;
  }
  return iVar9;
}



===== SqospTryAcquireDeviceLock @ 1c0002810 =====

bool SqospTryAcquireDeviceLock(longlong param_1)

{
  undefined1 uVar1;
  char cVar2;
  
  if (*(longlong *)(param_1 + 0x340) != 0) {
    return false;
  }
  uVar1 = KfRaiseIrql(2);
  cVar2 = KeTryToAcquireSpinLockAtDpcLevel(param_1 + 0x340);
  if (cVar2 == '\0') {
    KeLowerIrql(uVar1);
  }
  else {
    *(undefined1 *)(param_1 + 0x348) = uVar1;
  }
  return cVar2 != '\0';
}



===== SqospCompleteJobsOutsideLock @ 1c00028a0 =====

void SqospCompleteJobsOutsideLock(longlong *param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  
  plVar2 = (longlong *)*param_1;
  if (((longlong *)plVar2[1] == param_1) && (lVar3 = *plVar2, *(longlong **)(lVar3 + 8) == plVar2))
  {
    *param_1 = lVar3;
    *(longlong **)(lVar3 + 8) = param_1;
    while( true ) {
      if (plVar2 == param_1) {
        return;
      }
      plVar1 = plVar2 + -0xc;
      plVar4 = (longlong *)*param_1;
      if (((longlong *)plVar4[1] != param_1) ||
         (lVar3 = *plVar4, *(longlong **)(lVar3 + 8) != plVar4)) break;
      *param_1 = lVar3;
      *(longlong **)(lVar3 + 8) = param_1;
      lVar3 = *plVar1;
      if (*(char *)((longlong)plVar2 + 0x24) == '\0') {
        SqospDestroyJob((longlong)plVar1);
        FltCompletePendedPostOperation(lVar3);
        plVar2 = plVar4;
      }
      else {
        SqospDestroyJob((longlong)plVar1);
        FltCompletePendedPreOperation(lVar3,4);
        plVar2 = plVar4;
      }
    }
  }
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)(3);
  pcVar5 = (code *)swi(3);
  (*pcVar5)();
  return;
}



===== SqospFlushDeferredJobCompletions @ 1c0002960 =====

void SqospFlushDeferredJobCompletions
               (undefined8 param_1,undefined8 param_2,longlong param_3,longlong param_4)

{
  undefined8 *puVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  
  puVar4 = (undefined8 *)SqospFlushDeferredJobList();
  while( true ) {
    if (puVar4 == (undefined8 *)0x0) {
      return;
    }
    puVar1 = (undefined8 *)*puVar4;
    BalanceCompleteJob((longlong)(puVar4 + -8),param_3);
    plVar2 = *(longlong **)(param_4 + 8);
    plVar5 = puVar4 + 4;
    if (*plVar2 != param_4) break;
    *plVar5 = param_4;
    puVar4[5] = plVar2;
    *plVar2 = (longlong)plVar5;
    *(longlong **)(param_4 + 8) = plVar5;
    puVar4 = puVar1;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== SqospFlushDeferredJobList @ 1c00029f0 =====

void SqospFlushDeferredJobList(void)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  
  puVar3 = (undefined8 *)ExpInterlockedFlushSList();
  puVar2 = (undefined8 *)0x0;
  while (puVar3 != (undefined8 *)0x0) {
    puVar1 = (undefined8 *)*puVar3;
    *puVar3 = puVar2;
    puVar2 = puVar3;
    puVar3 = puVar1;
  }
  return;
}



===== SqospCheckVolumeStatsLocked @ 1c0002a30 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong SqospCheckVolumeStatsLocked(longlong param_1)

{
  undefined8 *puVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined1 uVar4;
  ulonglong uVar5;
  
  uVar3 = _DAT_fffff78000000008;
  uVar5 = 0;
  if (((*(char *)(param_1 + 0xb9) == '\0') && (DAT_1c000d218 != 0)) &&
     (*(int *)(param_1 + 0xbc) == 2)) {
    if ((*(char *)(param_1 + 0x10d8) == '\0') &&
       (uVar5 = *(longlong *)(param_1 + 0x10d0) + 40000000, uVar5 <= _DAT_fffff78000000008)) {
      puVar1 = *(undefined8 **)(param_1 + 0x380);
      *(undefined1 *)(param_1 + 0x10d8) = 1;
      for (; puVar1 != (undefined8 *)(param_1 + 0x380); puVar1 = (undefined8 *)*puVar1) {
        lVar2 = puVar1[-2];
        uVar4 = KeAcquireSpinLockRaiseToDpc(lVar2);
        *(undefined1 *)(lVar2 + 8) = uVar4;
        if ((*(uint *)(lVar2 + 0x84) & 0xfffffffd) == 0) {
          *(undefined4 *)(lVar2 + 0x80) = 0;
          *(undefined8 *)(lVar2 + 200) = 0;
          *(undefined8 *)(lVar2 + 0xd0) = 0;
          *(undefined8 *)(lVar2 + 0xd8) = 0;
          BalanceSetFlowMinimumIoRate(puVar1 + -3,0);
          puVar1[0x36] = 0;
          LOCK();
          puVar1[0x3c] = 0;
          UNLOCK();
          puVar1[0x37] = 0;
          LOCK();
          puVar1[0x3d] = 0;
          UNLOCK();
        }
        uVar5 = KeReleaseSpinLock(lVar2);
      }
    }
    if (*(ulonglong *)(param_1 + 0x10c8) <= uVar3) {
      *(undefined4 *)(param_1 + 0x10dc) = 0x278;
      for (puVar1 = *(undefined8 **)(param_1 + 0x380); puVar1 != (undefined8 *)(param_1 + 0x380);
          puVar1 = (undefined8 *)*puVar1) {
        *(undefined1 *)(puVar1 + 0x34) = 1;
        *(int *)(param_1 + 0x10dc) = *(int *)(param_1 + 0x10dc) + *(ushort *)(puVar1 + 4) + 0x488;
      }
      lVar2 = uVar3 + 40000000;
      *(longlong *)(param_1 + 0x10c8) = lVar2;
      return CONCAT71((int7)((ulonglong)lVar2 >> 8),1);
    }
  }
  return uVar5 & 0xffffffffffffff00;
}



===== SqospStartJobLocked @ 1c0002bd0 =====

int SqospStartJobLocked(undefined8 *param_1,undefined8 param_2,longlong param_3)

{
  int iVar1;
  
  if (*(int *)(*(longlong *)(param_1[4] + 8) + 0x39c) == 0) {
    *(undefined1 *)((longlong)param_1 + 0x7e) = 1;
    if (*(char *)((longlong)param_1 + 0x7c) != '\0') {
      SqospQueueJobForDispatch((longlong)param_1,param_3);
    }
    iVar1 = 2;
  }
  else {
    iVar1 = BalanceStartJob(param_1,param_3);
  }
  return iVar1;
}



===== BalanceStartJob @ 1c0002c20 =====

int BalanceStartJob(undefined8 *param_1,longlong param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  char cVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  longlong lVar7;
  
  uVar1 = param_1[0x14];
  lVar2 = *(longlong *)param_1[5];
  *(undefined1 *)((longlong)param_1 + 0x81) = 1;
  lVar7 = DAT_1c000d308;
  if (DAT_1c000d300 < uVar1 - *(longlong *)(lVar2 + 0x3f0)) {
    puVar6 = *(undefined8 **)(lVar2 + 0x380);
    *(ulonglong *)(lVar2 + 0x3f0) = uVar1;
    for (; puVar6 != (undefined8 *)(lVar2 + 0x380); puVar6 = (undefined8 *)*puVar6) {
      if ((((ulonglong)(puVar6[0x15] + lVar7) < uVar1) &&
          ((undefined8 *)puVar6[0xd] != puVar6 + 0xd)) &&
         ((ulonglong)(((undefined8 *)puVar6[0xd])[0xb] + lVar7) < uVar1)) {
        *(undefined8 *)(lVar2 + 0x3e0) = 1;
        *(undefined8 *)(lVar2 + 0x3c8) = 0;
        break;
      }
    }
  }
  if (((*(longlong *)(lVar2 + 0x458) != 0) && (*(longlong *)(lVar2 + 0x440) == 0)) &&
     (cVar3 = KeTryToAcquireSpinLockAtDpcLevel(lVar2 + 0x440), cVar3 != '\0')) {
    *(undefined1 *)(lVar2 + 0x448) = 2;
    if (*(ulonglong *)(lVar2 + 0x458) != 0) {
      BalanceSetLatencyTarget(lVar2,*(ulonglong *)(lVar2 + 0x458));
      *(undefined8 *)(lVar2 + 0x458) = 0;
    }
    KeReleaseSpinLock(lVar2 + 0x440,*(undefined1 *)(lVar2 + 0x448));
  }
  if (*(char *)(lVar2 + 0xb8) != '\0') {
    param_1[0x13] = 0;
LAB_1c0002cf1:
    BalanceIssueJob((longlong)param_1,param_2);
    return 0;
  }
  lVar7 = param_1[5];
  if (*(ulonglong *)(lVar2 + 0x3a8) < *(ulonglong *)(lVar2 + 0x3c8)) {
    if (*(longlong *)(lVar7 + 0xb0) < 1) {
      if ((*(longlong *)(lVar7 + 0xa0) < 0) &&
         (lVar7 = *(longlong *)(lVar2 + 0x3b0) - *(longlong *)(lVar7 + 0xa8), lVar7 < 0)) {
        BalanceAdvanceIssueLine(lVar2,-lVar7);
      }
    }
    else if (*(longlong *)(lVar2 + 0x408) - *(longlong *)(lVar7 + 0xb8) < 0) {
      *(longlong *)(lVar2 + 0x408) = *(longlong *)(lVar7 + 0xb8);
    }
    BalanceIssueJob((longlong)param_1,param_2);
    if (*(ulonglong *)(lVar2 + 0x3c8) <= *(ulonglong *)(lVar2 + 0x3a8)) {
      BalanceSetLowerThreshold(lVar2);
    }
    iVar4 = 0;
  }
  else {
    if ((-1 < *(longlong *)(lVar7 + 0xa0)) ||
       (((0 < *(longlong *)(lVar7 + 0xb0) &&
         (*(ulonglong *)(lVar7 + 0xb8) <= *(ulonglong *)(lVar2 + 0x408))) ||
        (-1 < *(longlong *)(lVar2 + 0x3b0) - *(longlong *)(lVar7 + 0xa8))))) goto LAB_1c0002cf1;
    uVar5 = BalanceDelayJob(param_1,param_2);
    iVar4 = 2 - (uint)((char)uVar5 != '\0');
  }
  return iVar4;
}



===== BalanceIssueJob @ 1c0002e90 =====

void BalanceIssueJob(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  ulonglong uVar2;
  code *pcVar3;
  longlong *plVar4;
  longlong lVar5;
  ulonglong uVar6;
  longlong lVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined8 unaff_RSI;
  longlong unaff_RDI;
  longlong lVar10;
  longlong *plVar11;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  puVar8 = auStack_28;
  puVar9 = auStack_28;
  plVar11 = *(longlong **)(param_1 + 0x28);
  lVar5 = *plVar11;
  if (*(char *)(param_1 + 0x84) != '\0') {
    return;
  }
  plVar1 = (longlong *)plVar11[0x11];
  plVar4 = (longlong *)(param_1 + 0x50);
  if ((longlong *)*plVar1 == plVar11 + 0x10) {
    *plVar4 = (longlong)(plVar11 + 0x10);
    *(longlong **)(param_1 + 0x58) = plVar1;
    *plVar1 = (longlong)plVar4;
    plVar11[0x11] = (longlong)plVar4;
    *(longlong *)(lVar5 + 0x3a8) = *(longlong *)(lVar5 + 0x3a8) + *(longlong *)(param_1 + 0x98);
    *(undefined1 *)(param_1 + 0x83) = 1;
    if (*(longlong *)(param_1 + 0x98) == 0) goto LAB_1c0002f4e;
    plVar4 = (longlong *)
             ((ulonglong)(*(longlong *)(param_1 + 0x98) * *(longlong *)(lVar5 + 0x3d8)) /
             (ulonglong)plVar11[0x3b]);
    lVar7 = plVar11[0x14];
    unaff_RDI = 0x3fffffffffffffff;
    if ((longlong *)0x3fffffffffffffff < plVar4) {
      plVar4 = (longlong *)0x3fffffffffffffff;
    }
    puVar8 = auStack_28;
    if (lVar7 < 0) goto LAB_1c0002f67;
  }
  else {
    lVar5 = 3;
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)();
    puVar9 = auStack_20;
LAB_1c0002f67:
    lVar7 = *(longlong *)(lVar5 + 1000);
    lVar10 = *(longlong *)(lVar5 + 0x3d8);
    *(undefined8 *)(puVar9 + 0x30) = unaff_RSI;
    uVar6 = plVar11[0x15];
    lVar10 = (ulonglong)(lVar7 * lVar10) / (ulonglong)plVar11[0x3b] - plVar11[0x14];
    if (unaff_RDI < lVar10) {
      lVar10 = unaff_RDI;
    }
    uVar2 = *(ulonglong *)(lVar5 + 0x3b0);
    if ((uVar6 < uVar2) && (4000000000 < uVar2 - uVar6)) {
      uVar6 = uVar2 - 4000000000;
    }
    lVar7 = plVar11[0x14] + lVar10;
    plVar11[0x15] = uVar6 + lVar10;
    puVar8 = puVar9;
  }
  plVar11[0x14] = lVar7 - (longlong)plVar4;
  if (0 < plVar11[0x16]) {
    plVar11[0x16] =
         plVar11[0x16] -
         ((ulonglong)(*(longlong *)(param_1 + 0x90) + (1L << ((byte)DAT_1c000d2a4 & 0x3f)) + -1) >>
         ((byte)DAT_1c000d2a4 & 0x3f));
    plVar11[0x17] =
         plVar11[0x17] +
         ((ulonglong)(*(longlong *)(param_1 + 0x90) + (1L << ((byte)DAT_1c000d2a4 & 0x3f)) + -1) >>
         ((byte)DAT_1c000d2a4 & 0x3f));
  }
LAB_1c0002f4e:
  if (*(char *)(param_1 + 0x7c) != '\0') {
    *(undefined8 *)(puVar8 + -8) = 0x1c0003040;
    SqospQueueJobForDispatch(param_1,param_2);
  }
  return;
}



===== BalanceCollectThroughputSample @ 1c0003050 =====

void BalanceCollectThroughputSample(longlong param_1,ulonglong param_2,ulonglong *param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  
  uVar7 = *param_3;
  if (DAT_1c000d2c0 + uVar7 <= param_2) {
    *param_3 = param_2;
    uVar6 = *(ulonglong *)(param_1 + 0x1038);
    uVar1 = param_3[1];
    uVar7 = param_2 - uVar7;
    param_3[1] = uVar6;
    uVar2 = *(ulonglong *)(param_1 + 0xfe0);
    uVar3 = param_3[3];
    param_3[3] = uVar2;
    uVar4 = *(ulonglong *)(param_1 + 0xff8);
    uVar5 = param_3[2];
    param_3[2] = uVar4;
    if ((uVar2 != uVar3) && (uVar6 = ((uVar6 - uVar1) * 0x400) / uVar7, 0x3ff < uVar6)) {
      param_3[((ulonglong)*(uint *)((longlong)param_3 + 0x3e4) + 2) * 2] = uVar6;
      param_3[(ulonglong)*(uint *)((longlong)param_3 + 0x3e4) * 2 + 5] =
           (DAT_1c000d2c0 * (uVar4 - uVar5)) / uVar7;
      *(int *)((longlong)param_3 + 0x3e4) = *(int *)((longlong)param_3 + 0x3e4) + 1;
      if (0x3b < *(uint *)((longlong)param_3 + 0x3e4)) {
        *(undefined4 *)((longlong)param_3 + 0x3e4) = 0;
      }
      if ((uint)param_3[0x7c] < 0x3c) {
        *(uint *)(param_3 + 0x7c) = (uint)param_3[0x7c] + 1;
      }
    }
  }
  return;
}



===== BalanceCompleteJob @ 1c0003140 =====

void BalanceCompleteJob(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  code *pcVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  lVar2 = *(longlong *)(param_1 + 0xb0);
  lVar3 = **(longlong **)(param_1 + 0x28);
  (*(longlong **)(param_1 + 0x28))[0x18] = lVar2;
  if (*(char *)(param_1 + 0x83) == '\0') {
    if (*(char *)(param_1 + 0x82) == '\0') goto LAB_1c0003170;
    lVar4 = *(longlong *)(param_1 + 0x50);
    puVar1 = (undefined8 *)(param_1 + 0x50);
    if ((*(undefined8 **)(lVar4 + 8) == puVar1) &&
       (plVar5 = *(longlong **)(param_1 + 0x58), (undefined8 *)*plVar5 == puVar1)) {
      *plVar5 = lVar4;
      *(longlong **)(lVar4 + 8) = plVar5;
      *puVar1 = 0;
      *(undefined8 *)(param_1 + 0x58) = 0;
      *(longlong *)(lVar3 + 0x3b8) = *(longlong *)(lVar3 + 0x3b8) - *(longlong *)(param_1 + 0x98);
      goto LAB_1c0003170;
    }
    pcVar6 = (code *)swi(0x29);
    (*pcVar6)(3);
    puVar8 = auStack_20;
  }
  else {
    BalanceDeIssueJob(param_1);
LAB_1c0003170:
    puVar8 = auStack_28;
    puVar7 = auStack_28;
    if (*(ulonglong *)(lVar3 + 0x3e0) <= *(ulonglong *)(lVar3 + 0x3a8)) goto LAB_1c0003180;
  }
  *(undefined8 *)(puVar8 + -8) = 0x1c00031f1;
  BalanceIssueBalancedJobs(lVar3,param_2);
  puVar7 = puVar8;
LAB_1c0003180:
  if (DAT_1c000d2c0 <= (ulonglong)(lVar2 - *(longlong *)(lVar3 + 0x400))) {
    *(undefined8 *)(puVar7 + -8) = 0x1c00031fe;
    BalanceResetReservedIoCounts(lVar3,lVar2);
  }
  return;
}



===== BalanceDeIssueJob @ 1c0003210 =====

void BalanceDeIssueJob(longlong param_1)

{
  undefined8 *puVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  
  lVar2 = *(longlong *)(param_1 + 0x50);
  lVar3 = **(longlong **)(param_1 + 0x28);
  puVar1 = (undefined8 *)(param_1 + 0x50);
  if ((*(undefined8 **)(lVar2 + 8) == puVar1) &&
     (plVar4 = *(longlong **)(param_1 + 0x58), (undefined8 *)*plVar4 == puVar1)) {
    *plVar4 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar4;
    *puVar1 = 0;
    *(undefined8 *)(param_1 + 0x58) = 0;
    plVar4 = (longlong *)(lVar3 + 0x3a8);
    *plVar4 = *plVar4 - *(longlong *)(param_1 + 0x98);
    return;
  }
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)(3);
  pcVar5 = (code *)swi(3);
  (*pcVar5)();
  return;
}



===== BalanceComputeThroughputFunction @ 1c0003260 =====

void BalanceComputeThroughputFunction(longlong param_1,ulonglong param_2,ulonglong param_3)

{
  longlong lVar1;
  uint uVar2;
  ulonglong *puVar3;
  ulonglong uVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  
  dVar6 = (double)param_2;
  dVar7 = *(double *)(param_1 + 1000);
  uVar11 = SUB84(dVar7,0);
  uVar12 = (undefined4)((ulonglong)dVar7 >> 0x20);
  if (dVar7 <= 0.0) {
    uVar11 = 0;
    uVar12 = 0x3ff00000;
  }
  dVar7 = (double)CONCAT44(uVar12,uVar11);
  uVar2 = 0;
  do {
    dVar5 = 0.0;
    if (*(uint *)(param_1 + 0x3e0) != 0) {
      puVar3 = (ulonglong *)(param_1 + 0x28);
      uVar4 = (ulonglong)*(uint *)(param_1 + 0x3e0);
      dVar5 = 0.0;
      do {
        if ((puVar3[-1] != 0) && (*puVar3 != 0)) {
          dVar9 = (double)puVar3[-1] * 0.0009765625;
          dVar10 = (double)*puVar3;
          dVar8 = dVar9 + dVar7;
          dVar5 = dVar5 + -((((dVar6 - dVar10) * dVar9 - dVar10 * dVar7) / dVar8) *
                           (dVar9 / dVar8 + dVar9 / dVar8)) * (dVar6 / dVar8);
        }
        puVar3 = puVar3 + 2;
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
    }
    dVar5 = (dVar5 * dVar7) / (dVar6 * dVar6);
    if (dVar5 == 0.0) break;
    uVar2 = uVar2 + 1;
    dVar5 = dVar7 - dVar5 * 0.5;
    dVar7 = 0.5;
    if (0.5 <= dVar5) {
      dVar7 = dVar5;
    }
  } while (uVar2 < 0x28);
  *(double *)(param_1 + 1000) = dVar7;
  dVar6 = BalanceSqrt(4.0 / (dVar7 * 0.005) + 1.0);
  dVar7 = (dVar6 - 1.0) * dVar7 * 0.5;
  *(double *)(param_1 + 0x3f0) = dVar7;
  dVar7 = (double)param_3 * dVar7;
  lVar1 = 0;
  if ((9.223372036854776e+18 <= dVar7) &&
     (dVar7 = dVar7 - 9.223372036854776e+18, dVar7 < 9.223372036854776e+18)) {
    lVar1 = -0x8000000000000000;
  }
  *(longlong *)(param_1 + 0x3f8) = (longlong)dVar7 + lVar1;
  return;
}



===== SqospAllocateStreamHandleContext @ 1c0003510 =====

int SqospAllocateStreamHandleContext(longlong param_1,longlong *param_2)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 uVar4;
  int iVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  longlong local_res8;
  longlong local_res18 [2];
  
  local_res18[0] = 0;
  local_res8 = 0;
  iVar5 = FltGetInstanceContext(*(undefined8 *)(param_1 + 0x18),local_res18);
  if (-1 < iVar5) {
    iVar5 = FltAllocateContext(*(undefined8 *)(param_1 + 8),0x10,0x28,0x200,&local_res8);
    if (-1 < iVar5) {
      FltInitializePushLock(local_res8);
      FltReferenceContext(local_res18[0]);
      *(longlong *)(local_res8 + 8) = local_res18[0];
      LOCK();
      piVar1 = (int *)(*(longlong *)(local_res18[0] + 0xb0) + 0xc);
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      *(undefined8 *)(local_res8 + 0x10) = *(undefined8 *)(local_res18[0] + 0xb0);
      *(undefined1 *)(local_res8 + 0x20) = DAT_1c000d2ab;
      lVar2 = *(longlong *)(local_res8 + 0x10);
      lVar3 = *(longlong *)(local_res8 + 8);
      uVar4 = KeAcquireSpinLockRaiseToDpc(lVar2);
      puVar6 = *(undefined8 **)(lVar2 + 0x68);
      *(undefined1 *)(lVar2 + 8) = uVar4;
      for (; puVar6 != (undefined8 *)(lVar2 + 0x68); puVar6 = (undefined8 *)*puVar6) {
        puVar7 = puVar6 + -5;
        if (puVar6[-5] == lVar3) goto LAB_1c000362d;
      }
      puVar7 = (undefined8 *)0x0;
LAB_1c000362d:
      KeReleaseSpinLock(lVar2,uVar4);
      *(undefined8 **)(local_res8 + 0x18) = puVar7;
      *param_2 = local_res8;
      local_res8 = 0;
      goto LAB_1c000365f;
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
             &WPP_af53c64ad8bd3a498290aca5a9ae070a_Traceguids,iVar5);
  }
  if (local_res8 != 0) {
    FltReleaseContext();
  }
LAB_1c000365f:
  if (local_res18[0] != 0) {
    FltReleaseContext();
  }
  return iVar5;
}



===== SqospCleanupStreamHandleContext @ 1c00036f0 =====

void SqospCleanupStreamHandleContext(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  undefined1 uVar4;
  byte bVar5;
  
  lVar3 = *(longlong *)(param_1 + 8);
  if ((((lVar3 != 0) && (*(longlong *)(param_1 + 0x10) != 0)) &&
      (*(char *)(*(longlong *)(param_1 + 0x10) + 0x7c) == '\0')) &&
     (*(char *)(param_1 + 0x20) == '\0')) {
    uVar4 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x340);
    *(undefined1 *)(lVar3 + 0x348) = uVar4;
    piVar1 = (int *)(*(longlong *)(param_1 + 8) + 0x394);
    *piVar1 = *piVar1 + -1;
    BalanceUpdateDeviceMode(*(longlong *)(param_1 + 8),param_2,param_3);
    KeReleaseSpinLock(*(longlong *)(param_1 + 8) + 0x340,
                      *(undefined1 *)(*(longlong *)(param_1 + 8) + 0x348));
  }
  lVar3 = *(longlong *)(param_1 + 0x10);
  if (lVar3 != 0) {
    LOCK();
    piVar1 = (int *)(lVar3 + 0xc);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      if (*(char *)(lVar3 + 0x7d) == '\0') {
        SqospCleanupClient(lVar3);
      }
      else {
        bVar5 = KeGetCurrentIrql();
        if (bVar5 < 2) {
          SqospRemoveClient(lVar3);
        }
        else {
          FltQueueGenericWorkItem
                    (DAT_1c000d280,DAT_1c000d208,SqospClientRemovalWorkItemRoutine,1,lVar3);
        }
      }
    }
    *(undefined8 *)(param_1 + 0x10) = 0;
  }
  if (*(longlong *)(param_1 + 8) != 0) {
    FltReleaseContext();
    *(undefined8 *)(param_1 + 8) = 0;
  }
  return;
}



===== SqospCreateJob @ 1c0003830 =====

longlong * SqospCreateJob(longlong param_1,longlong param_2)

{
  int *piVar1;
  longlong lVar2;
  int iVar3;
  longlong *_Dst;
  longlong lVar4;
  
  iVar3 = SystemReserved1[0x12]._4_4_;
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 8) + 0x90);
  lVar4 = (ulonglong)(SystemReserved1[0x12]._4_4_ + 1) * 0x80 + lVar2;
  if (*(char *)(lVar4 + 0xb0) == '\0') {
    PplpLazyInitializeLookasideList(lVar2,lVar4 + 0x40);
  }
  _Dst = (longlong *)ExAllocateFromLookasideListEx(lVar4 + 0x40);
  if (_Dst != (longlong *)0x0) {
    memset(_Dst,0,0xc0);
    _Dst[4] = param_1;
    *_Dst = param_2;
    *(int *)(_Dst + 0xf) = iVar3;
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined8 *)(param_2 + 0x30) = 0;
    *(longlong **)(param_2 + 0x40) = _Dst;
    FltAcquirePushLockSharedEx(_Dst[4],0);
    LOCK();
    piVar1 = (int *)(*(longlong *)(_Dst[4] + 0x10) + 0xc);
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    _Dst[5] = *(longlong *)(_Dst[4] + 0x18);
    FltReleasePushLockEx(_Dst[4],0);
  }
  return _Dst;
}



===== SqospLookupFlow @ 1c0003920 =====

longlong * SqospLookupFlow(longlong param_1,longlong param_2,char param_3,longlong param_4)

{
  undefined1 uVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc();
  *(undefined1 *)(param_1 + 8) = uVar1;
  puVar2 = *(undefined8 **)(param_1 + 0x68);
  do {
    if (puVar2 == (undefined8 *)(param_1 + 0x68)) {
      plVar3 = (longlong *)0x0;
      KeReleaseSpinLock(param_1,uVar1);
LAB_1c00039a8:
      if (param_3 == '\0') {
        plVar3 = SqospCreateFlow(param_1,param_2,param_4);
      }
LAB_1c000397e:
      return plVar3;
    }
    plVar3 = puVar2 + -5;
    if (puVar2[-5] == param_2) {
      KeReleaseSpinLock(param_1);
      if (plVar3 == (longlong *)0x0) goto LAB_1c00039a8;
      goto LAB_1c000397e;
    }
    puVar2 = (undefined8 *)*puVar2;
  } while( true );
}



===== SqospFindFlow @ 1c00039d0 =====

undefined8 * SqospFindFlow(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(param_1 + 0x68);
  while( true ) {
    if (puVar1 == (undefined8 *)(param_1 + 0x68)) {
      return (undefined8 *)0x0;
    }
    if (puVar1[-5] == param_2) break;
    puVar1 = (undefined8 *)*puVar1;
  }
  return puVar1 + -5;
}



===== SqospReleaseClient @ 1c0003a00 =====

void SqospReleaseClient(longlong param_1)

{
  int *piVar1;
  int iVar2;
  byte bVar3;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0xc);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    if (*(char *)(param_1 + 0x7d) == '\0') {
      SqospCleanupClient(param_1);
    }
    else {
      bVar3 = KeGetCurrentIrql();
      if (bVar3 < 2) {
        SqospRemoveClient(param_1);
      }
      else {
        FltQueueGenericWorkItem
                  (DAT_1c000d280,DAT_1c000d208,SqospClientRemovalWorkItemRoutine,1,param_1);
      }
    }
  }
  return;
}



===== SqospAddRefClient @ 1c0003a80 =====

void SqospAddRefClient(longlong param_1)

{
  LOCK();
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  UNLOCK();
  return;
}



===== RtlUnicodeStringValidateSrcWorker @ 1c0003a90 =====

void RtlUnicodeStringValidateSrcWorker(ushort *param_1,undefined8 *param_2,ulonglong *param_3)

{
  undefined8 uVar1;
  
  *param_2 = 0;
  *param_3 = 0;
  uVar1 = RtlUnicodeStringValidateWorker(param_1);
  if ((-1 < (int)uVar1) && (param_1 != (ushort *)0x0)) {
    *param_2 = *(undefined8 *)(param_1 + 4);
    *param_3 = (ulonglong)(*param_1 >> 1);
  }
  return;
}



===== SqospCopyUnicodeString @ 1c0003ad0 =====

ulonglong SqospCopyUnicodeString(ushort *param_1,ushort *param_2)

{
  ulonglong uVar1;
  
  if (*param_2 == 0xfffe) {
    return 0xc0000106;
  }
  uVar1 = SqospAllocateUnicodeString(param_1,*param_2 + 2);
  if (-1 < (int)uVar1) {
    RtlUnicodeStringCopy(param_1,param_2);
    uVar1 = uVar1 & 0xffffffff;
  }
  return uVar1;
}



===== SqospAllocateUnicodeString @ 1c0003b40 =====

undefined8 SqospAllocateUnicodeString(undefined2 *param_1,short param_2)

{
  undefined2 *puVar1;
  undefined8 uVar2;
  
  if ((ushort)(param_2 - 1U) < 0xfffe) {
    puVar1 = (undefined2 *)ExAllocatePool2(0x40,param_2,0x46535153);
    if (puVar1 == (undefined2 *)0x0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0')) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                 &WPP_b8a405419f5733ac566e8c3690148060_Traceguids,0xc000009a);
      }
      uVar2 = 0xc000009a;
    }
    else {
      *puVar1 = 0;
      *(undefined2 **)(param_1 + 4) = puVar1;
      uVar2 = 0;
      param_1[1] = param_2;
      *param_1 = 0;
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0')) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
               &WPP_b8a405419f5733ac566e8c3690148060_Traceguids,0xc000000d);
    }
    uVar2 = 0xc000000d;
  }
  return uVar2;
}



===== RtlUnicodeStringValidateDestWorker @ 1c0003c30 =====

ulonglong RtlUnicodeStringValidateDestWorker
                    (ushort *param_1,undefined8 *param_2,ulonglong *param_3,ulonglong *param_4)

{
  ulonglong uVar1;
  
  *param_2 = 0;
  *param_3 = 0;
  if (param_4 != (ulonglong *)0x0) {
    *param_4 = 0;
  }
  uVar1 = RtlUnicodeStringValidateWorker(param_1);
  if ((-1 < (int)uVar1) && (param_1 != (ushort *)0x0)) {
    *param_2 = *(undefined8 *)(param_1 + 4);
    *param_3 = (ulonglong)(param_1[1] >> 1);
    if (param_4 != (ulonglong *)0x0) {
      *param_4 = (ulonglong)(*param_1 >> 1);
      uVar1 = uVar1 & 0xffffffff;
    }
  }
  return uVar1;
}



===== RtlUnicodeStringCopy @ 1c0003ca0 =====

ulonglong RtlUnicodeStringCopy(ushort *param_1,ushort *param_2)

{
  ulonglong uVar1;
  undefined2 *puVar2;
  ushort *puVar3;
  undefined2 *puVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined2 *puVar7;
  ulonglong uVar8;
  
  puVar3 = param_1;
  uVar1 = RtlUnicodeStringValidateWorker(param_1);
  puVar7 = (undefined2 *)0x0;
  if (((int)uVar1 < 0) || (puVar3 == (ushort *)0x0)) {
    lVar5 = 0;
    uVar8 = 0;
    if ((int)uVar1 < 0) {
      return uVar1;
    }
  }
  else {
    lVar5 = *(longlong *)(puVar3 + 4);
    uVar8 = (ulonglong)(puVar3[1] >> 1);
  }
  uVar1 = RtlUnicodeStringValidateWorker(param_2);
  uVar6 = uVar1 & 0xffffffff;
  if (((int)uVar1 < 0) || (param_2 == (ushort *)0x0)) {
    puVar2 = puVar7;
    puVar4 = puVar7;
    if ((int)uVar1 < 0) goto LAB_1c0003d2f;
  }
  else {
    puVar2 = *(undefined2 **)(param_2 + 4);
    puVar4 = (undefined2 *)(ulonglong)(*param_2 >> 1);
  }
  uVar6 = (ulonglong)puVar7 & 0xffffffff;
  if (uVar8 != 0) {
    lVar5 = lVar5 - (longlong)puVar2;
    do {
      if (puVar4 == (undefined2 *)0x0) goto LAB_1c0003d2f;
      puVar4 = (undefined2 *)((longlong)puVar4 + -1);
      *(undefined2 *)(lVar5 + (longlong)puVar2) = *puVar2;
      puVar7 = (undefined2 *)((longlong)puVar7 + 1);
      puVar2 = puVar2 + 1;
      uVar8 = uVar8 - 1;
    } while (uVar8 != 0);
  }
  if (puVar4 != (undefined2 *)0x0) {
    uVar6 = 0x80000005;
  }
LAB_1c0003d2f:
  *param_1 = (short)puVar7 * 2;
  return uVar6;
}



===== RtlUnicodeStringValidateWorker @ 1c0003d60 =====

undefined8 RtlUnicodeStringValidateWorker(ushort *param_1)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = *param_1;
  if ((((((uVar1 & 1) == 0) && (uVar2 = param_1[1], (uVar2 & 1) == 0)) && (uVar1 <= uVar2)) &&
      (uVar2 != 0xffff)) && ((*(longlong *)(param_1 + 4) != 0 || ((uVar1 == 0 && (uVar2 == 0)))))) {
    return 0;
  }
  return 0xc000000d;
}



===== RtlWideCharArrayCopyWorker @ 1c0003db0 =====

undefined4
RtlWideCharArrayCopyWorker
          (longlong param_1,longlong param_2,longlong *param_3,undefined2 *param_4,longlong param_5)

{
  longlong lVar1;
  undefined4 uVar2;
  longlong lVar3;
  
  uVar2 = 0;
  lVar3 = 0;
  if (param_2 != 0) {
    lVar1 = param_1 - (longlong)param_4;
    do {
      if (param_5 == 0) goto LAB_1c0003df0;
      param_5 = param_5 + -1;
      *(undefined2 *)(lVar1 + (longlong)param_4) = *param_4;
      lVar3 = lVar3 + 1;
      param_4 = param_4 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  uVar2 = 0;
  if (param_5 != 0) {
    uVar2 = 0x80000005;
  }
LAB_1c0003df0:
  *param_3 = lVar3;
  return uVar2;
}



===== PplpGenericAllocateFunction @ 1c0003e10 =====

void PplpGenericAllocateFunction(void)

{
  longlong in_R9;
  
  ExAllocateFromLookasideListEx(*(undefined8 *)(in_R9 + 0x60));
  return;
}



===== PplpGenericFreeFunction @ 1c0003e30 =====

void PplpGenericFreeFunction(undefined8 param_1,longlong param_2)

{
  ExFreeToLookasideListEx(*(undefined8 *)(param_2 + 0x60),param_1);
  return;
}



===== SqospGetStreamHandleContextClient @ 1c0003e60 =====

undefined8 SqospGetStreamHandleContextClient(longlong param_1)

{
  int *piVar1;
  undefined8 uVar2;
  
  FltAcquirePushLockSharedEx(param_1,0);
  LOCK();
  piVar1 = (int *)(*(longlong *)(param_1 + 0x10) + 0xc);
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  uVar2 = *(undefined8 *)(param_1 + 0x10);
  FltReleasePushLockEx(param_1,0);
  return uVar2;
}



===== SqospQueueJobForDispatch @ 1c0003eb0 =====

void SqospQueueJobForDispatch(longlong param_1,longlong param_2)

{
  longlong lVar1;
  char cVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong *puVar6;
  bool bVar7;
  
  if ((*(char *)(param_1 + 0x80) == '\0') &&
     (uVar3 = BalanceUpdateStatsForStartingJob(param_1), (char)uVar3 != '\0')) {
    *(undefined1 *)(param_2 + 0x19) = 1;
    lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 8);
    *(undefined1 *)(param_1 + 0x7c) = 1;
    ExpInterlockedPushEntrySList(lVar1 + 0x100,param_1 + 0x30);
    return;
  }
  puVar6 = (ulonglong *)
           ((ulonglong)*(uint *)(param_1 + 0x78) * 0x40 +
           *(longlong *)(*(longlong *)(param_2 + 8) + 0x50));
  uVar4 = *puVar6;
  do {
    *(ulonglong *)(param_1 + 0x70U) = uVar4 & 0xfffffffffffffffe;
    LOCK();
    if (uVar4 == *puVar6) {
      *puVar6 = param_1 + 0x70U;
      uVar5 = uVar4;
    }
    else {
      uVar5 = *puVar6;
    }
    UNLOCK();
    bVar7 = uVar5 != uVar4;
    uVar4 = uVar5;
  } while (bVar7);
  if (uVar5 == 0) {
    if (*(ulonglong **)(param_2 + 0x10) == puVar6) {
      *(undefined1 *)(param_2 + 0x1a) = 1;
    }
    else {
      cVar2 = ExTryQueueWorkItem(puVar6 + 1,1);
      if (cVar2 == '\0') {
        KeInsertQueue(*(longlong *)(param_2 + 8) + 8,puVar6 + 1);
      }
    }
  }
  return;
}



===== SqospFreeUnicodeString @ 1c0003f90 =====

void SqospFreeUnicodeString(undefined4 *param_1)

{
  if (*(longlong *)(param_1 + 2) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 2),0x46535153);
  }
  *(undefined8 *)(param_1 + 2) = 0;
  *param_1 = 0;
  return;
}



===== SqospGetClientStatusInfo @ 1c0003fd0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SqospGetClientStatusInfo(longlong param_1,ushort *param_2,ushort *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  bool bVar7;
  undefined1 uVar8;
  uint uVar9;
  undefined4 uVar10;
  longlong lVar11;
  ulonglong uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  ulonglong uVar16;
  
  uVar8 = KeAcquireSpinLockRaiseToDpc();
  *(undefined1 *)(param_1 + 8) = uVar8;
  if ((*(uint *)(param_2 + 2) & 0x10) != 0) {
    *(longlong *)(param_1 + 0xe0) = *(longlong *)(param_1 + 0xe0) + *(longlong *)(param_2 + 0x28);
    *(longlong *)(param_1 + 0xe8) = *(longlong *)(param_1 + 0xe8) + *(longlong *)(param_2 + 0x2c);
    if (*param_2 < 0x101) {
      lVar11 = 0;
    }
    else {
      lVar11 = *(longlong *)(param_2 + 0x3c);
    }
    *(longlong *)(param_1 + 0xf0) = *(longlong *)(param_1 + 0xf0) + lVar11;
    *(longlong *)(param_1 + 0xf8) = *(longlong *)(param_1 + 0xf8) + *(longlong *)(param_2 + 0x30);
    *(longlong *)(param_1 + 0x100) = *(longlong *)(param_1 + 0x100) + *(longlong *)(param_2 + 0x34);
  }
  if (param_3 == (ushort *)0x0) goto LAB_1c000423d;
  uVar14 = 60000;
  bVar7 = false;
  uVar16 = 60000;
  iVar15 = 60000;
  uVar13 = 60000;
  for (puVar3 = *(undefined8 **)(param_1 + 0x68); puVar3 != (undefined8 *)(param_1 + 0x68);
      puVar3 = (undefined8 *)*puVar3) {
    if (*(int *)(puVar3[-5] + 0xbc) == 2) {
      uVar12 = *(ulonglong *)(puVar3[-5] + 0x10d0);
      if (_DAT_fffff78000000008 < uVar12) {
        uVar12 = (uVar12 - _DAT_fffff78000000008) / 10000;
      }
      else {
        uVar12 = 4000;
      }
      bVar7 = true;
      uVar9 = (uint)uVar12;
      if (uVar16 <= uVar12) {
        uVar9 = (uint)uVar16;
      }
      uVar16 = (ulonglong)uVar9;
    }
    else {
      if (*(uint *)(puVar3 + 0x2c) < 0xc) {
        uVar9 = (0xc - *(uint *)(puVar3 + 0x2c)) * 4000;
      }
      else {
        uVar9 = 0;
      }
      if (uVar9 < uVar13) {
        uVar13 = uVar9;
      }
    }
    iVar15 = (int)uVar16;
  }
  iVar2 = *(int *)(param_1 + 0x84);
  if (bVar7) {
    if (iVar2 == 1) {
      *(undefined4 *)(param_1 + 0x80) = 4;
      param_3[0x1c] = 60000;
      param_3[0x1d] = 0;
      uVar14 = 60000;
    }
    else {
      if (DAT_1c000d218 != 0) {
        uVar14 = iVar15 + 200;
        *(uint *)(param_3 + 0x1c) = uVar14;
        *(undefined8 *)(param_3 + 0x20) = *(undefined8 *)(param_1 + 0xd0);
        *(undefined8 *)(param_3 + 0x24) = *(undefined8 *)(param_1 + 200);
        if (0x100 < *param_3) {
          *(undefined8 *)(param_3 + 0x2c) = *(undefined8 *)(param_1 + 0xd8);
        }
        goto LAB_1c00041f7;
      }
      uVar14 = 4000;
      if (iVar2 != 2) {
        uVar14 = 60000;
      }
      uVar10 = 2;
      if (iVar2 != 2) {
        uVar10 = 0;
      }
      *(undefined4 *)(param_1 + 0x80) = uVar10;
      *(uint *)(param_3 + 0x1c) = uVar14;
    }
    param_3[0x20] = 0;
    param_3[0x21] = 0;
    param_3[0x22] = 0;
    param_3[0x23] = 0;
    param_3[0x24] = 0;
    param_3[0x25] = 0;
    param_3[0x26] = 0;
    param_3[0x27] = 0;
    if (0x100 < *param_3) {
      param_3[0x2c] = 0;
      param_3[0x2d] = 0;
      param_3[0x2e] = 0;
      param_3[0x2f] = 0;
    }
  }
  else {
    puVar1 = (undefined4 *)(param_1 + 0x80);
    if (iVar2 == 2) {
      *puVar1 = 4;
    }
    else {
      uVar14 = 60000;
      if (iVar2 != 0) {
        if (uVar13 == 0) {
          *puVar1 = 1;
          uVar14 = 5000;
          goto LAB_1c00041e1;
        }
        uVar14 = uVar13;
      }
      *puVar1 = 0;
    }
LAB_1c00041e1:
    *(uint *)(param_3 + 0x1c) = uVar14;
    param_3[0x20] = 0;
    param_3[0x21] = 0;
    param_3[0x22] = 0;
    param_3[0x23] = 0;
    param_3[0x24] = 0;
    param_3[0x25] = 0;
    param_3[0x26] = 0;
    param_3[0x27] = 0;
    if (0x100 < *param_3) {
      param_3[0x2c] = 0;
      param_3[0x2d] = 0;
      param_3[0x2e] = 0;
      param_3[0x2f] = 0;
    }
  }
LAB_1c00041f7:
  if (uVar14 < 1000) {
    param_3[0x1c] = 1000;
    param_3[0x1d] = 0;
  }
  *(undefined4 *)(param_3 + 0x1e) = *(undefined4 *)(param_1 + 0x80);
  uVar6 = *(undefined8 *)(param_1 + 0x60);
  *(undefined8 *)(param_3 + 4) = *(undefined8 *)(param_1 + 0x58);
  *(undefined8 *)(param_3 + 8) = uVar6;
  uVar6 = *(undefined8 *)(param_1 + 0x90);
  *(undefined8 *)(param_3 + 0xc) = *(undefined8 *)(param_1 + 0x88);
  *(undefined8 *)(param_3 + 0x10) = uVar6;
  uVar10 = *(undefined4 *)(param_1 + 0x9c);
  uVar4 = *(undefined4 *)(param_1 + 0xa0);
  uVar5 = *(undefined4 *)(param_1 + 0xa4);
  *(undefined4 *)(param_3 + 0x14) = *(undefined4 *)(param_1 + 0x98);
  *(undefined4 *)(param_3 + 0x16) = uVar10;
  *(undefined4 *)(param_3 + 0x18) = uVar4;
  *(undefined4 *)(param_3 + 0x1a) = uVar5;
  *(undefined4 *)(param_3 + 0x28) = DAT_1c000d2a0;
LAB_1c000423d:
  KeReleaseSpinLock(param_1,*(undefined1 *)(param_1 + 8));
  return;
}



===== SqospQueueDeviceTimer @ 1c0004270 =====

ulonglong SqospQueueDeviceTimer(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  
  uVar2 = (ulonglong)*(uint *)(param_1 + 0x124);
  if (*(uint *)(param_1 + 0x124) == 0) {
    LOCK();
    uVar1 = *(uint *)(param_1 + 0x124);
    if (uVar1 == 0) {
      *(uint *)(param_1 + 0x124) = 1;
    }
    else {
      uVar2 = (ulonglong)uVar1;
    }
    UNLOCK();
    if (uVar1 == 0) {
      FltReferenceContext(param_1);
      uVar2 = KeSetTimer(param_1 + 0x128,0xfffffffffffe7960,param_1 + 0x168);
    }
  }
  return uVar2;
}



===== BalanceSqrt @ 1c00042d0 =====

double BalanceSqrt(double param_1)

{
  uint uVar1;
  double dVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (param_1 == 0.0) {
    return 0.0;
  }
  dVar2 = 1.0;
  uVar3 = 0;
  uVar4 = 0;
  uVar1 = 0;
  while( true ) {
    uVar1 = uVar1 + 1;
    if (dVar2 == (double)CONCAT44(uVar4,uVar3)) {
      return dVar2;
    }
    if (dVar2 == 0.0) break;
    uVar3 = SUB84(dVar2,0);
    uVar4 = (undefined4)((ulonglong)dVar2 >> 0x20);
    dVar2 = (dVar2 + param_1 / dVar2) * 0.5;
    if (9 < uVar1) {
      return dVar2;
    }
  }
  return dVar2;
}



===== SqospAreExternalDeviceCostEstimatesValid @ 1c0004330 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong SqospAreExternalDeviceCostEstimatesValid(longlong param_1)

{
  ulonglong in_RAX;
  
  if ((*(int *)(param_1 + 0x44c) == 1) &&
     (in_RAX = _DAT_fffff78000000008, _DAT_fffff78000000008 < *(ulonglong *)(param_1 + 0x450))) {
    return CONCAT71((int7)(_DAT_fffff78000000008 >> 8),1);
  }
  return in_RAX & 0xffffffffffffff00;
}



===== SqospBuildFlowName @ 1c0004360 =====

ulonglong SqospBuildFlowName(longlong param_1,longlong param_2,ushort *param_3)

{
  short *psVar1;
  ushort uVar2;
  int iVar3;
  ulonglong uVar4;
  short sVar5;
  ushort *puVar6;
  ulonglong uVar7;
  wchar_t *pwVar8;
  longlong lVar9;
  longlong local_res10 [2];
  ulonglong local_res20;
  ulonglong local_38;
  longlong local_30;
  
  local_res10[0] = 0;
  if (param_2 == 0) {
    uVar4 = SqospAllocateUnicodeString(param_3,*(short *)(param_1 + 0x18) + 0x1a);
    uVar7 = uVar4 & 0xffffffff;
    if ((int)uVar4 < 0) goto LAB_1c0004576;
    RtlUnicodeStringCopy(param_3,(ushort *)(param_1 + 0x18));
    local_30 = 0;
    local_res20 = 0;
    local_38 = 0;
    uVar4 = RtlUnicodeStringValidateDestWorker(param_3,&local_30,&local_res20,&local_38);
    if (-1 < (int)uVar4) {
      pwVar8 = L"\\DefaultFlow";
      lVar9 = 0x7fff;
      sVar5 = 0;
      if (local_res20 - local_38 != 0) {
        sVar5 = 0;
        do {
          if ((lVar9 == 0) || (*pwVar8 == L'\0')) break;
          lVar9 = lVar9 + -1;
          *(wchar_t *)(local_38 * 2 + -0x1c000b478 + local_30 + (longlong)pwVar8) = *pwVar8;
          pwVar8 = pwVar8 + 1;
          sVar5 = sVar5 + 1;
        } while ((local_res20 - local_38) + -0x7fff + lVar9 != 0);
      }
      *param_3 = (sVar5 + (short)local_38) * 2;
    }
  }
  else {
    iVar3 = FltGetFileNameInformation(param_2,0x401,local_res10);
    if (iVar3 < 0) {
      uVar4 = SqospAllocateUnicodeString(param_3,*(short *)(param_1 + 0x18) + 0x10);
      uVar7 = uVar4 & 0xffffffff;
      if ((int)uVar4 < 0) goto LAB_1c0004576;
      RtlUnicodeStringCopy(param_3,(ushort *)(param_1 + 0x18));
      RtlUnicodeStringCatString(param_3,L"\\");
      RtlUnicodeStringCat(param_3,(ushort *)&UNKNOWN_OBJECT_NAME);
    }
    else {
      iVar3 = 0;
      for (uVar2 = 0; uVar2 < *(ushort *)(local_res10[0] + 8) >> 1; uVar2 = uVar2 + 1) {
        psVar1 = (short *)(*(longlong *)(local_res10[0] + 0x10) + (ulonglong)uVar2 * 2);
        if ((*(short *)(*(longlong *)(local_res10[0] + 0x10) + (ulonglong)uVar2 * 2) == 0x5c) &&
           (iVar3 = iVar3 + 1, iVar3 == 3)) {
          if (psVar1 == (short *)0x0) goto LAB_1c000445b;
          uVar4 = SqospAllocateUnicodeString
                            (param_3,*(ushort *)(local_res10[0] + 8) + uVar2 * -2 +
                                     *(short *)(param_1 + 0x18));
          uVar7 = uVar4 & 0xffffffff;
          if ((int)uVar4 < 0) goto LAB_1c0004576;
          RtlUnicodeStringCopy(param_3,(ushort *)(param_1 + 0x18));
          RtlUnicodeStringCatString(param_3,psVar1);
          goto LAB_1c000456b;
        }
      }
      if (iVar3 == 2) {
        puVar6 = (ushort *)(param_1 + 0x18);
      }
      else {
LAB_1c000445b:
        puVar6 = (ushort *)(local_res10[0] + 8);
      }
      uVar4 = SqospCopyUnicodeString(param_3,puVar6);
      uVar7 = uVar4 & 0xffffffff;
      if ((int)uVar4 < 0) goto LAB_1c0004576;
    }
  }
LAB_1c000456b:
  SqospCleanUnicodeStringForPC(param_3);
  uVar7 = 0;
LAB_1c0004576:
  if (local_res10[0] != 0) {
    FltReleaseFileNameInformation();
  }
  return uVar7;
}



===== PplpLazyInitializeLookasideList @ 1c00045c0 =====

void PplpLazyInitializeLookasideList(longlong param_1,longlong param_2)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_2 + 0x68);
  if (*(char *)(param_2 + 0x70) == '\0') {
    ExInitializeLookasideListEx
              (param_2,PplpGenericAllocateFunction,PplpGenericFreeFunction,
               *(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_1 + 4),
               *(undefined8 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 8),
               *(undefined2 *)(param_1 + 0x24));
    *(undefined1 *)(param_2 + 0x70) = 1;
  }
  KeReleaseSpinLock(param_2 + 0x68,uVar1);
  return;
}



===== BalanceSetDeviceMode @ 1c0004670 =====

void BalanceSetDeviceMode(longlong param_1,int param_2,undefined8 param_3)

{
  undefined1 uVar1;
  longlong lVar2;
  ulonglong uVar3;
  
  if (*(int *)(param_1 + 0x39c) != param_2) {
    uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x440);
    uVar3 = DAT_1c000d2d0;
    *(undefined1 *)(param_1 + 0x448) = uVar1;
    *(undefined8 *)(param_1 + 0x458) = 0;
    lVar2 = param_1;
    BalanceSetLatencyTarget(param_1,uVar3);
    BalanceRestoreCostEstimates(lVar2);
    uVar3 = (ulonglong)*(byte *)(param_1 + 0x448);
    KeReleaseSpinLock(param_1 + 0x440);
    *(int *)(param_1 + 0x39c) = param_2;
    if (param_2 == 0) {
      *(undefined8 *)(param_1 + 3000) = 0;
      *(undefined8 *)(param_1 + 0xbc0) = 0;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,param_3,param_1,(char)param_2);
    }
  }
  return;
}



===== __report_gsfailure @ 1c0004760 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 1c000476d =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001c000476d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== BalanceAdvanceIssueLine @ 1c0004780 =====

void BalanceAdvanceIssueLine(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(param_1 + 0x3b0) + param_2;
  *(longlong *)(param_1 + 0x3b0) = lVar2;
  if ((*(longlong *)(param_1 + 0x3d0) == lVar2) || (param_2 == 0)) {
    for (puVar1 = *(undefined8 **)(param_1 + 0x380); puVar1 != (undefined8 *)(param_1 + 0x380);
        puVar1 = (undefined8 *)*puVar1) {
      if (4000000000 < lVar2 - puVar1[0x12]) {
        puVar1[0x12] = lVar2 + -4000000000;
        lVar2 = *(longlong *)(param_1 + 0x3b0);
      }
    }
    *(longlong *)(param_1 + 0x3d0) = lVar2 + 0x3fffffff1194d801;
  }
  return;
}



===== BalanceDelayJob @ 1c0004804 =====

ulonglong BalanceDelayJob(undefined8 *param_1,longlong param_2)

{
  code *pcVar1;
  ulonglong uVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong *plVar5;
  
  uVar2 = FltCbdqInsertIo(*(longlong *)(param_1[4] + 8) + 0x1e0,*param_1,param_1 + 1,0);
  if ((int)uVar2 < 0) {
    param_1[0x13] = 0;
    *(undefined1 *)((longlong)param_1 + 0x7e) = 1;
    if (*(char *)((longlong)param_1 + 0x7c) != '\0') {
      uVar2 = SqospQueueJobForDispatch((longlong)param_1,param_2);
    }
    uVar2 = uVar2 & 0xffffffffffffff00;
  }
  else {
    *(undefined1 *)((longlong)param_1 + 0x7c) = 1;
    if (0 < ((longlong *)param_1[5])[0x16]) {
      *(undefined1 *)(*(longlong *)param_1[5] + 0x410) = 1;
    }
    plVar4 = param_1 + 10;
    lVar3 = param_1[5] + 0x90;
    plVar5 = *(longlong **)(param_1[5] + 0x98);
    if (*plVar5 != lVar3) {
      plVar4 = (longlong *)0x3;
      pcVar1 = (code *)swi(0x29);
      lVar3 = (*pcVar1)();
    }
    *plVar4 = lVar3;
    plVar4[1] = (longlong)plVar5;
    *plVar5 = (longlong)plVar4;
    *(longlong **)(lVar3 + 8) = plVar4;
    uVar2 = CONCAT71((int7)((ulonglong)lVar3 >> 8),1);
    *(longlong *)(*(longlong *)param_1[5] + 0x3b8) =
         *(longlong *)(*(longlong *)param_1[5] + 0x3b8) + param_1[0x13];
    *(undefined1 *)((longlong)param_1 + 0x82) = 1;
  }
  return uVar2;
}



===== BalanceFinalizeFlow @ 1c00048d8 =====

void BalanceFinalizeFlow(longlong *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  
  plVar1 = param_1 + 3;
  lVar2 = *plVar1;
  if ((*(longlong **)(lVar2 + 8) == plVar1) &&
     (plVar3 = (longlong *)param_1[4], (longlong *)*plVar3 == plVar1)) {
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    *plVar1 = 0;
    param_1[4] = 0;
    *(int *)(*param_1 + 0x390) = *(int *)(*param_1 + 0x390) + -1;
    *(longlong *)(*param_1 + 0x3d8) = *(longlong *)(*param_1 + 0x3d8) - param_1[0x3b];
    BalanceSetFlowMinimumIoRate(param_1,0);
    return;
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== BalanceFindFlowWithBestReservedJob @ 1c000493c =====

undefined8 * BalanceFindFlowWithBestReservedJob(longlong param_1)

{
  longlong lVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined8 *puVar4;
  
  puVar4 = (undefined8 *)0x0;
  lVar3 = -0x8000000000000000;
  for (puVar2 = *(undefined8 **)(param_1 + 0x380); puVar2 != (undefined8 *)(param_1 + 0x380);
      puVar2 = (undefined8 *)*puVar2) {
    if ((((undefined8 *)puVar2[0xf] != puVar2 + 0xf) && (0 < (longlong)puVar2[0x13])) &&
       (lVar1 = *(longlong *)(param_1 + 0x408) - puVar2[0x14], lVar3 < lVar1)) {
      puVar4 = puVar2 + -3;
      lVar3 = lVar1;
    }
  }
  return puVar4;
}



===== BalanceInitialize @ 1c00049a4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
BalanceInitialize(longlong param_1,ulonglong param_2,ulonglong param_3,undefined4 param_4,
                 int param_5)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  longlong lVar7;
  longlong lVar8;
  
  DAT_1c000d2c0 = param_1;
  DAT_1c000d2e0 = param_4;
  DAT_1c000d2c8 = 8;
  DAT_1c000d2d0 = ((param_2 & 0xffffffff) * 1000000000) / 1000000;
  DAT_1c000d2e4 = param_5 + 100;
  DAT_1c000d2d8 = ((param_3 & 0xffffffff) * 1000000000) / 1000000;
  auVar1._8_8_ = 0;
  auVar1._0_8_ = param_1 * 0x32;
  lVar7 = SUB168(ZEXT816(0x624dd2f1a9fbe77) * auVar1,8);
  _DAT_1c000d2e8 = ((ulonglong)(param_1 * 0x32 - lVar7) >> 1) + lVar7 >> 9;
  auVar2._8_8_ = 0;
  auVar2._0_8_ = param_1 * 200;
  lVar7 = SUB168(ZEXT816(0x624dd2f1a9fbe77) * auVar2,8);
  _DAT_1c000d2f0 = ((ulonglong)(param_1 * 200 - lVar7) >> 1) + lVar7 >> 9;
  auVar3._8_8_ = 0;
  auVar3._0_8_ = param_1 * 300000;
  lVar7 = SUB168(ZEXT816(0x624dd2f1a9fbe77) * auVar3,8);
  DAT_1c000d2f8 = ((ulonglong)(param_1 * 300000 - lVar7) >> 1) + lVar7 >> 9;
  auVar4._8_8_ = 0;
  auVar4._0_8_ = param_1 * 1000;
  lVar7 = SUB168(ZEXT816(0x624dd2f1a9fbe77) * auVar4,8);
  auVar5._8_8_ = 0;
  auVar5._0_8_ = param_1 * 4000;
  lVar8 = SUB168(ZEXT816(0x624dd2f1a9fbe77) * auVar5,8);
  DAT_1c000d300 = ((ulonglong)(param_1 * 1000 - lVar7) >> 1) + lVar7 >> 9;
  auVar6._8_8_ = 0;
  auVar6._0_8_ = param_1 * 0xfa;
  lVar7 = SUB168(ZEXT816(0x624dd2f1a9fbe77) * auVar6,8);
  DAT_1c000d308 = ((ulonglong)(param_1 * 4000 - lVar8) >> 1) + lVar8 >> 9;
  DAT_1c000d320 = DAT_1c000d308;
  DAT_1c000d310 = ((ulonglong)(param_1 * 0xfa - lVar7) >> 1) + lVar7 >> 9;
  DAT_1c000d318 = DAT_1c000d308;
  return SUB168(ZEXT816(0x624dd2f1a9fbe77) * auVar6,0);
}



===== BalanceInitializeDevice @ 1c0004af0 =====

void BalanceInitializeDevice(longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  
  lVar1 = param_1 + 0x380;
  *(longlong *)(param_1 + 0x388) = lVar1;
  *(longlong *)lVar1 = lVar1;
  uVar2 = DAT_1c000d2d0;
  *(ulonglong *)(param_1 + 0x3c0) = DAT_1c000d2d0;
  uVar2 = uVar2 >> 1;
  if (uVar2 == 0) {
    uVar2 = 1;
  }
  *(undefined4 *)(param_1 + 0x39c) = 0;
  *(undefined8 *)(param_1 + 0xb80) = 0;
  *(ulonglong *)(param_1 + 0x3c8) = uVar2;
  *(undefined8 *)(param_1 + 0x3b0) = 4000000000;
  *(undefined8 *)(param_1 + 0x510) = 1;
  *(undefined8 *)(param_1 + 0x518) = 1;
  *(undefined8 *)(param_1 + 0x520) = 1;
  *(undefined8 *)(param_1 + 0x528) = 1;
  *(undefined8 *)(param_1 + 0x3f8) = 1;
  uVar2 = (ulonglong)DAT_1c000d2c8;
  *(undefined4 *)(param_1 + 0x4f4) = 4;
  uVar2 = (ulonglong)(*(longlong *)(param_1 + 0x3f8) * 100) / uVar2;
  if (uVar2 == 0) {
    uVar2 = 1;
  }
  *(ulonglong *)(param_1 + 1000) = uVar2;
  return;
}



===== BalanceInitializeFlow @ 1c0004b98 =====

void BalanceInitializeFlow(longlong *param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  int iVar3;
  longlong *plVar4;
  
  plVar4 = param_1 + 0x12;
  param_1[0x13] = (longlong)plVar4;
  plVar1 = (longlong *)(param_2 + 0x380);
  *plVar4 = (longlong)plVar4;
  plVar4 = param_1 + 0x10;
  param_1[0x11] = (longlong)plVar4;
  *plVar4 = (longlong)plVar4;
  *param_1 = param_2;
  plVar4 = (longlong *)*plVar1;
  if (plVar4 != plVar1) {
    lVar2 = param_1[1];
    do {
      iVar3 = memcmp((void *)(lVar2 + 0x58),(void *)(plVar4[-2] + 0x58),0x10);
      if (iVar3 < 0) break;
      plVar4 = (longlong *)*plVar4;
    } while (plVar4 != plVar1);
  }
  plVar1 = param_1 + 3;
  param_1[0x3b] = 100;
  *(longlong *)(param_2 + 0x3d8) = *(longlong *)(param_2 + 0x3d8) + 100;
  param_1[0x16] = 0;
  plVar4 = (longlong *)plVar4[1];
  lVar2 = *plVar4;
  *plVar1 = lVar2;
  param_1[4] = (longlong)plVar4;
  *(longlong **)(lVar2 + 8) = plVar1;
  *plVar4 = (longlong)plVar1;
  *(int *)(param_2 + 0x390) = *(int *)(param_2 + 0x390) + 1;
  param_1[0x14] = -1;
  param_1[0x15] = *(longlong *)(*param_1 + 0x3b0) + -4000000000;
  return;
}



===== BalanceIssueBalancedJobs @ 1c0004c8c =====

void BalanceIssueBalancedJobs(longlong param_1,longlong param_2)

{
  char cVar1;
  ulonglong uVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined8 *puVar6;
  undefined8 *puVar7;
  longlong lVar8;
  longlong lVar9;
  ulonglong uVar10;
  
  lVar8 = *(longlong *)(param_1 + 0x3a8);
  uVar10 = ((ulonglong)(100 - DAT_1c000d2e0) * *(longlong *)(param_1 + 0x3c0) * 0x78) / 10000;
  cVar1 = *(char *)(param_1 + 0x410);
  while (((cVar1 != '\0' && (*(ulonglong *)(param_1 + 0x3a8) < uVar10)) &&
         (puVar6 = BalanceFindFlowWithBestReservedJob(param_1), puVar6 != (undefined8 *)0x0))) {
    *(longlong *)(param_1 + 0x408) = puVar6[0x17] + 0x20;
    BalanceIssueReservedJobs(param_1,param_2);
    cVar1 = *(char *)(param_1 + 0x410);
  }
  uVar2 = *(ulonglong *)(param_1 + 0x3a8);
  if (uVar10 < uVar2) {
    uVar10 = (uVar2 - lVar8) * (ulonglong)DAT_1c000d2e0;
    auVar4._8_8_ = 0;
    auVar4._0_8_ = uVar10;
    lVar8 = SUB168(ZEXT816(0x47ae147ae147ae15) * auVar4,8);
    uVar10 = ((uVar10 - lVar8 >> 1) + lVar8 >> 6) + uVar2;
  }
  else {
    uVar10 = *(longlong *)(param_1 + 0x3c0) * 0x78;
    auVar3._8_8_ = 0;
    auVar3._0_8_ = uVar10;
    lVar8 = SUB168(ZEXT816(0x47ae147ae147ae15) * auVar3,8);
    uVar10 = (uVar10 - lVar8 >> 1) + lVar8 >> 6;
  }
  while ((uVar2 < uVar10 && (*(longlong *)(param_1 + 0x3b8) != 0))) {
    puVar6 = (undefined8 *)0x0;
    lVar8 = -0x8000000000000000;
    for (puVar7 = *(undefined8 **)(param_1 + 0x380); puVar7 != (undefined8 *)(param_1 + 0x380);
        puVar7 = (undefined8 *)*puVar7) {
      if (((undefined8 *)puVar7[0xf] != puVar7 + 0xf) &&
         (lVar9 = *(longlong *)(param_1 + 0x3b0) - puVar7[0x12], lVar8 < lVar9)) {
        puVar6 = puVar7 + -3;
        lVar8 = lVar9;
      }
    }
    BalanceAdvanceIssueLine
              (param_1,((*(ulonglong *)(param_1 + 0x3c0) >> 3) + puVar6[0x15]) -
                       *(longlong *)(param_1 + 0x3b0));
    BalanceIssueQualifiedJobs(param_1,param_2);
    uVar2 = *(ulonglong *)(param_1 + 0x3a8);
  }
  uVar10 = *(longlong *)(param_1 + 0x3c0) * 0x78;
  auVar5._8_8_ = 0;
  auVar5._0_8_ = uVar10;
  lVar8 = SUB168(ZEXT816(0x47ae147ae147ae15) * auVar5,8);
  while (((*(char *)(param_1 + 0x410) != '\0' &&
          (*(ulonglong *)(param_1 + 0x3a8) < (uVar10 - lVar8 >> 1) + lVar8 >> 6)) &&
         (puVar6 = BalanceFindFlowWithBestReservedJob(param_1), puVar6 != (undefined8 *)0x0))) {
    *(longlong *)(param_1 + 0x408) = puVar6[0x17] + 0x20;
    BalanceIssueReservedJobs(param_1,param_2);
  }
  uVar10 = *(ulonglong *)(param_1 + 0x3c0) >> 1;
  if (uVar10 == 0) {
    uVar10 = 1;
  }
  if (*(ulonglong *)(param_1 + 0x3a8) < uVar10) {
    *(undefined8 *)(param_1 + 0x3e0) = 0;
    *(ulonglong *)(param_1 + 0x3c8) = uVar10;
  }
  else {
    BalanceSetLowerThreshold(param_1);
  }
  return;
}



===== BalanceIssueQualifiedJobs @ 1c0004ec8 =====

void BalanceIssueQualifiedJobs(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  undefined8 *puVar2;
  
  *(undefined1 *)(param_1 + 0x410) = 0;
  puVar2 = *(undefined8 **)(param_1 + 0x380);
  do {
    if (puVar2 == (undefined8 *)(param_1 + 0x380)) {
      return;
    }
    while ((undefined8 *)puVar2[0xf] != puVar2 + 0xf) {
      if (((longlong)puVar2[0x11] < 0) && (*(longlong *)(param_1 + 0x3b0) - puVar2[0x12] < 0)) {
        if (0 < (longlong)puVar2[0x13]) {
          *(undefined1 *)(param_1 + 0x410) = 1;
        }
        break;
      }
      plVar1 = BalanceRemoveFirstDelayedJob(puVar2 + -3);
      BalanceIssueJob((longlong)plVar1,param_2);
    }
    puVar2 = (undefined8 *)*puVar2;
  } while( true );
}



===== BalanceIssueReservedJobs @ 1c0004f6c =====

void BalanceIssueReservedJobs(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  undefined8 *puVar2;
  
  *(undefined1 *)(param_1 + 0x410) = 0;
  puVar2 = *(undefined8 **)(param_1 + 0x380);
  do {
    if (puVar2 == (undefined8 *)(param_1 + 0x380)) {
      return;
    }
    while ((undefined8 *)puVar2[0xf] != puVar2 + 0xf) {
      if ((longlong)puVar2[0x11] < 0) {
        if ((longlong)puVar2[0x13] < 1) break;
        if (*(ulonglong *)(param_1 + 0x408) < (ulonglong)puVar2[0x14]) {
          if (0 < (longlong)puVar2[0x13]) {
            *(undefined1 *)(param_1 + 0x410) = 1;
          }
          break;
        }
      }
      plVar1 = BalanceRemoveFirstDelayedJob(puVar2 + -3);
      BalanceIssueJob((longlong)plVar1,param_2);
    }
    puVar2 = (undefined8 *)*puVar2;
  } while( true );
}



===== BalanceOverrideCostEstimates @ 1c000501c =====

void BalanceOverrideCostEstimates(longlong param_1,longlong param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  longlong lVar3;
  longlong *plVar4;
  
  plVar4 = &e_max_fp;
  lVar3 = 4;
  do {
    lVar1 = *plVar4;
    uVar2 = *(ulonglong *)(param_2 + -0x1c000b3d0 + (longlong)plVar4);
    plVar4 = plVar4 + 1;
    if ((ulonglong)(lVar1 / 0x2000) < uVar2) {
      uVar2 = lVar1 / 0x2000;
    }
    *(ulonglong *)(param_1 + -0x1c000af78 + (longlong)plVar4) = uVar2;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  *(undefined8 *)(param_1 + 0x3f8) = *(undefined8 *)(param_1 + 0x478);
  uVar2 = (ulonglong)DAT_1c000d2c8;
  *(undefined4 *)(param_1 + 0x44c) = 1;
  uVar2 = (ulonglong)(*(longlong *)(param_1 + 0x3f8) * 100) / uVar2;
  if (uVar2 == 0) {
    uVar2 = 1;
  }
  *(ulonglong *)(param_1 + 1000) = uVar2;
  return;
}



===== BalanceRemoveFirstDelayedJob @ 1c00050b8 =====

longlong * BalanceRemoveFirstDelayedJob(longlong *param_1)

{
  longlong *plVar1;
  code *pcVar2;
  longlong lVar3;
  longlong *plVar4;
  
  plVar4 = param_1 + 0x12;
  plVar1 = (longlong *)*plVar4;
  if (((longlong *)plVar1[1] != plVar4) || (lVar3 = *plVar1, *(longlong **)(lVar3 + 8) != plVar1)) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(3);
    pcVar2 = (code *)swi(3);
    plVar4 = (longlong *)(*pcVar2)();
    return plVar4;
  }
  *plVar4 = lVar3;
  *(longlong **)(lVar3 + 8) = plVar4;
  plVar1[1] = 0;
  *plVar1 = 0;
  *(longlong *)(*param_1 + 0x3b8) = *(longlong *)(*param_1 + 0x3b8) - plVar1[9];
  *(undefined1 *)((longlong)plVar1 + 0x32) = 0;
  lVar3 = FltCbdqRemoveIo(*(longlong *)(plVar1[-6] + 8) + 0x1e0,plVar1 + -9);
  if (lVar3 == 0) {
    *(undefined1 *)((longlong)plVar1 + 0x34) = 1;
  }
  return plVar1 + -10;
}



===== BalanceResetReservedIoCounts @ 1c0005148 =====

void BalanceResetReservedIoCounts(longlong param_1,undefined8 param_2)

{
  int iVar1;
  longlong lVar2;
  undefined8 *puVar3;
  longlong lVar4;
  
  *(undefined1 *)(param_1 + 0x410) = 0;
  iVar1 = *(int *)(param_1 + 0x398);
  puVar3 = *(undefined8 **)(param_1 + 0x380);
  do {
    if (puVar3 == (undefined8 *)(param_1 + 0x380)) {
      *(undefined8 *)(param_1 + 0x408) = 0;
      *(undefined8 *)(param_1 + 0x400) = param_2;
      return;
    }
    lVar2 = puVar3[0x35];
    if (iVar1 == 0) {
      puVar3[0x13] = 0;
    }
    else {
      if (lVar2 == 0) {
        puVar3[0x13] = 0;
        if (*(char *)(puVar3[-2] + 0x7c) == '\0') goto LAB_1c00051e9;
      }
      else {
        lVar4 = puVar3[0x13] + lVar2;
        puVar3[0x13] = lVar4;
        if (lVar2 < lVar4) {
          puVar3[0x13] = lVar2;
          lVar4 = lVar2;
        }
        if ((0 < lVar4) && ((undefined8 *)puVar3[0xf] != puVar3 + 0xf)) {
          *(undefined1 *)(param_1 + 0x410) = 1;
        }
      }
      if (*(ulonglong *)(param_1 + 0x3b0) < (ulonglong)puVar3[0x12]) {
        puVar3[0x12] = *(ulonglong *)(param_1 + 0x3b0) + 1;
      }
    }
LAB_1c00051e9:
    puVar3[0x14] = 1;
    puVar3 = (undefined8 *)*puVar3;
  } while( true );
}



===== BalanceRestoreCostEstimates @ 1c000521c =====

void BalanceRestoreCostEstimates(longlong param_1)

{
  ulonglong uVar1;
  longlong *plVar2;
  longlong lVar3;
  
  lVar3 = 4;
  plVar2 = (longlong *)(param_1 + 0x460);
  do {
    *plVar2 = plVar2[0x16] / 0x2000;
    plVar2 = plVar2 + 1;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  *(undefined8 *)(param_1 + 0x3f8) = *(undefined8 *)(param_1 + 0x478);
  uVar1 = (ulonglong)(*(longlong *)(param_1 + 0x3f8) * 100) / (ulonglong)DAT_1c000d2c8;
  if (uVar1 == 0) {
    uVar1 = 1;
  }
  *(undefined4 *)(param_1 + 0x44c) = 0;
  *(ulonglong *)(param_1 + 1000) = uVar1;
  return;
}



===== BalanceSetFlowMinimumIoRate @ 1c0005290 =====

void BalanceSetFlowMinimumIoRate(longlong *param_1,longlong param_2)

{
  if (param_1[0x38] == 0) {
    if (param_2 != 0) {
      LOCK();
      *(int *)(*param_1 + 0x398) = *(int *)(*param_1 + 0x398) + 1;
      UNLOCK();
    }
  }
  else if (param_2 == 0) {
    LOCK();
    *(int *)(*param_1 + 0x398) = *(int *)(*param_1 + 0x398) + -1;
    UNLOCK();
  }
  param_1[0x38] = param_2;
  return;
}



===== BalanceSetLatencyTarget @ 1c00052cc =====

void BalanceSetLatencyTarget(longlong param_1,ulonglong param_2)

{
  ulonglong uVar1;
  
  uVar1 = DAT_1c000d2d8;
  if ((DAT_1c000d2d8 <= param_2) && (uVar1 = param_2, DAT_1c000d2d0 < param_2)) {
    uVar1 = DAT_1c000d2d0;
  }
  if (uVar1 != *(ulonglong *)(param_1 + 0x3c0)) {
    *(ulonglong *)(param_1 + 0x3c0) = uVar1;
    uVar1 = uVar1 >> 1;
    if (uVar1 == 0) {
      uVar1 = 1;
    }
    if (*(longlong *)(param_1 + 0x3c8) != 0) {
      *(ulonglong *)(param_1 + 0x3c8) = uVar1;
    }
    if (uVar1 <= *(ulonglong *)(param_1 + 0x3a8)) {
      BalanceSetLowerThreshold(param_1);
    }
  }
  return;
}



===== BalanceSetLowerThreshold @ 1c000533c =====

void BalanceSetLowerThreshold(longlong param_1)

{
  ulonglong uVar1;
  
  *(undefined8 *)(param_1 + 0x3c8) = 0;
  uVar1 = (ulonglong)(*(longlong *)(param_1 + 0x3a8) * 100) / 0x78;
  *(ulonglong *)(param_1 + 0x3e0) = uVar1;
  if (*(ulonglong *)(param_1 + 0x3c0) < uVar1) {
    *(ulonglong *)(param_1 + 0x3e0) = *(ulonglong *)(param_1 + 0x3c0);
    return;
  }
  if (uVar1 == 0) {
    *(undefined8 *)(param_1 + 0x3e0) = 1;
  }
  return;
}



===== BalanceUpdateCostEstimatesInternal @ 1c0005394 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int BalanceUpdateCostEstimatesInternal(longlong param_1,undefined8 param_2)

{
  longlong *plVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined1 uVar12;
  int iVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong lVar16;
  longlong lVar17;
  longlong lVar18;
  ulonglong uVar19;
  ulonglong uVar20;
  longlong lVar21;
  longlong lVar22;
  uint uVar23;
  undefined1 auStack_118 [32];
  uint local_f8;
  longlong local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  longlong local_d8 [4];
  longlong local_b8 [4];
  longlong alStack_98 [4];
  longlong local_78 [4];
  longlong alStack_58 [4];
  ulonglong local_38;
  longlong local_30;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_118;
  plVar1 = (longlong *)(param_1 + 0x510);
  iVar13 = 0;
  if (*(longlong *)(param_1 + 0x4a0) != 0) {
    uVar19 = (ulonglong)*(uint *)(param_1 + 0xb70);
    uVar20 = 1;
    uVar5 = *(undefined4 *)(param_1 + 0x4a4);
    uVar6 = *(undefined4 *)(param_1 + 0x4a8);
    uVar7 = *(undefined4 *)(param_1 + 0x4ac);
    uVar8 = *(undefined4 *)(param_1 + 0x4b0);
    uVar9 = *(undefined4 *)(param_1 + 0x4b4);
    uVar10 = *(undefined4 *)(param_1 + 0x4b8);
    uVar11 = *(undefined4 *)(param_1 + 0x4bc);
    uVar4 = *(undefined8 *)(param_1 + 0x4c0);
    puVar2 = (undefined4 *)(param_1 + 0x530 + uVar19 * 0x28);
    *puVar2 = *(undefined4 *)(param_1 + 0x4a0);
    puVar2[1] = uVar5;
    puVar2[2] = uVar6;
    puVar2[3] = uVar7;
    puVar2 = (undefined4 *)(param_1 + 0x540 + uVar19 * 0x28);
    *puVar2 = uVar8;
    puVar2[1] = uVar9;
    puVar2[2] = uVar10;
    puVar2[3] = uVar11;
    *(undefined8 *)(param_1 + 0x550 + uVar19 * 0x28) = uVar4;
    *(int *)(param_1 + 0xb70) = *(int *)(param_1 + 0xb70) + 1;
    if (*(int *)(param_1 + 0xb70) == 0x28) {
      *(undefined4 *)(param_1 + 0xb70) = 0;
    }
    if (*(uint *)(param_1 + 0xb74) < 0x28) {
      *(uint *)(param_1 + 0xb74) = *(uint *)(param_1 + 0xb74) + 1;
    }
    local_e8 = 0x2000;
    lVar18 = 4;
    plVar15 = (longlong *)(param_1 + 0x4c8);
    do {
      *plVar15 = (*plVar15 * 0x1c00 + plVar15[-5] * 0x800000) / 0x2000;
      plVar15 = plVar15 + 1;
      lVar18 = lVar18 + -1;
    } while (lVar18 != 0);
    local_f8 = 0;
    uVar23 = (*(int *)(param_1 + 0xb70) - *(int *)(param_1 + 0xb74)) + 0x28;
    if (*(int *)(param_1 + 0xb74) != 0) {
      local_f0 = (longlong)&e_max_fp - (longlong)plVar1;
      do {
        lVar17 = 4;
        lVar18 = param_1 + ((ulonglong)(uVar23 % 0x28) * 5 + 0xa6) * 8;
        lVar22 = *(longlong *)(lVar18 + 0x20);
        plVar15 = local_b8;
        do {
          *plVar15 = *(longlong *)((lVar18 - (longlong)local_b8) + (longlong)plVar15);
          plVar15 = plVar15 + 1;
          lVar17 = lVar17 - uVar20;
        } while (lVar17 != 0);
        lVar17 = 0;
        lVar21 = 4;
        lVar18 = 0;
        do {
          lVar16 = *(longlong *)
                    (((longlong)plVar1 - (longlong)local_b8) + (longlong)local_b8 + lVar18) *
                   *(longlong *)((longlong)local_b8 + lVar18);
          *(longlong *)((longlong)alStack_98 + lVar18) = lVar16;
          lVar17 = lVar17 + lVar16;
          lVar18 = lVar18 + 8;
          lVar21 = lVar21 + -1;
        } while (lVar21 != 0);
        lVar18 = 0;
        lVar21 = 4;
        do {
          lVar16 = *(longlong *)((longlong)alStack_98 + lVar18);
          *(longlong *)((longlong)local_d8 + lVar18) = lVar16;
          if (lVar16 < 0) {
            lVar16 = -lVar16;
            *(longlong *)((longlong)local_d8 + lVar18) = lVar16;
          }
          if (lVar16 < 1) {
            *(undefined8 *)((longlong)local_d8 + lVar18) = 1;
          }
          lVar18 = lVar18 + 8;
          lVar21 = lVar21 + -1;
        } while (lVar21 != 0);
        lVar21 = 0;
        plVar15 = local_d8;
        lVar18 = 4;
        do {
          lVar16 = lVar18;
          lVar21 = lVar21 + *plVar15;
          plVar15 = plVar15 + 1;
          lVar18 = lVar16 + -1;
        } while (lVar18 != 0);
        uVar19 = (ulonglong)((int)lVar16 + 3);
        if (lVar21 < 1) {
          lVar21 = 0x7fffffffffffffff;
        }
        lVar18 = 0;
        do {
          *(longlong *)((longlong)alStack_58 + lVar18) =
               (*(longlong *)((longlong)local_d8 + lVar18) << 0xd) / lVar21;
          uVar19 = uVar19 - 1;
          lVar18 = lVar18 + 8;
        } while (uVar19 != 0);
        lVar18 = 0;
        plVar15 = (longlong *)(param_1 + 0x4c8);
        lVar21 = 4;
        do {
          if (*(longlong *)((longlong)local_b8 + lVar18) == 0) {
            lVar16 = 0;
          }
          else {
            lVar16 = (((((lVar22 * 0x2000 - lVar17) * 0x40) / 0x2000) *
                      *(longlong *)((longlong)alStack_58 + lVar18)) /
                     *(longlong *)((longlong)local_b8 + lVar18)) / 0x2000;
          }
          *(longlong *)((longlong)alStack_98 + lVar18) = lVar16;
          *(longlong *)(lVar18 + (longlong)plVar1) =
               *(longlong *)(lVar18 + (longlong)plVar1) + lVar16;
          lVar18 = lVar18 + 8;
          lVar21 = lVar21 + -1;
        } while (lVar21 != 0);
        lVar18 = 4;
        plVar14 = plVar15;
        do {
          if (*plVar14 < 0x40) {
            *plVar14 = 0x40;
            plVar14[9] = 1;
          }
          plVar14 = plVar14 + 1;
          lVar18 = lVar18 + -1;
        } while (lVar18 != 0);
        lVar22 = 4;
        lVar18 = 0;
        plVar14 = plVar1;
        do {
          lVar17 = (plVar14[-9] * *plVar14) / 0x2000;
          if (lVar17 < 0) {
            lVar17 = (plVar14[-9] * *plVar14) / -0x2000;
          }
          *(longlong *)(((longlong)local_78 - (longlong)plVar1) + (longlong)plVar14) = lVar17;
          lVar18 = lVar18 + lVar17;
          plVar14 = plVar14 + 1;
          lVar22 = lVar22 + -1;
        } while (lVar22 != 0);
        if (lVar18 < 1) {
          lVar18 = 1;
        }
        lVar22 = 4;
        do {
          lVar17 = lVar22;
          if ((*(longlong *)((longlong)plVar15 + ((longlong)local_78 - (param_1 + 0x4c8))) << 0xd) /
              lVar18 < 5) {
            plVar15[9] = (lVar18 * 10) / *plVar15;
          }
          plVar15 = plVar15 + 1;
          lVar22 = lVar17 + -1;
        } while (lVar22 != 0);
        plVar15 = plVar1;
        uVar19 = (ulonglong)((int)lVar17 + 3);
        do {
          uVar20 = uVar19;
          lVar18 = *plVar15;
          if (lVar18 < 1) {
            lVar18 = 1;
            *plVar15 = 1;
          }
          if (*(longlong *)(local_f0 + (longlong)plVar15) < lVar18) {
            *plVar15 = *(longlong *)(local_f0 + (longlong)plVar15);
          }
          plVar15 = plVar15 + 1;
          uVar19 = uVar20 - 1;
        } while (uVar19 != 0);
        local_f8 = local_f8 + 1;
        uVar23 = uVar23 % 0x28 + 1;
        uVar20 = uVar20 & 0xffffffff;
      } while (local_f8 < *(uint *)(param_1 + 0xb74));
    }
    local_e0 = param_2;
    uVar12 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x440);
    *(undefined1 *)(param_1 + 0x448) = uVar12;
    lVar18 = param_1;
    uVar19 = SqospAreExternalDeviceCostEstimatesValid(param_1);
    if ((char)uVar19 == '\0') {
      BalanceRestoreCostEstimates(lVar18);
    }
    KeReleaseSpinLock(param_1 + 0x440,*(undefined1 *)(param_1 + 0x448));
    iVar13 = 4;
    *(undefined8 *)(param_1 + 0x490) = param_2;
    LOCK();
    iVar3 = *(int *)(param_1 + 0x480);
    if (iVar3 == 4) {
      *(int *)(param_1 + 0x480) = 0;
    }
    else {
      iVar13 = iVar3;
    }
    UNLOCK();
  }
  return iVar13;
}



===== BalanceUpdateDeviceMode @ 1c00057cc =====

void BalanceUpdateDeviceMode(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x39c) == 0) {
    if (*(int *)(param_1 + 0x394) == 0) {
      return;
    }
    iVar1 = 1;
  }
  else {
    if (*(int *)(param_1 + 0x394) != 0) {
      return;
    }
    iVar1 = 0;
  }
  BalanceSetDeviceMode(param_1,iVar1,param_3);
  return;
}



===== WPP_SF_qL @ 1c0005804 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qL(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_925a8a691fae32c96d8a3dae9c5c3a2e_Traceguids,10,&local_res20,8,
             &param_5,4,0);
  return;
}



===== PplpCreateLookasideListEx @ 1c0005860 =====

uint * PplpCreateLookasideListEx(int param_1)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  longlong lVar4;
  uint uVar5;
  undefined8 local_28;
  undefined8 local_20;
  
  uVar5 = param_1 + 1;
  local_28 = 1;
  local_20 = 0;
  puVar2 = (uint *)ExAllocatePool3(0x48,(ulonglong)uVar5 * 0x80 + 0x40,0x46535153,&local_28,1);
  if (puVar2 == (uint *)0x0) {
LAB_1c0005972:
    puVar2 = (uint *)0x0;
  }
  else {
    lVar4 = 0;
    for (iVar3 = 0; iVar3 < (int)uVar5; iVar3 = iVar3 + 1) {
      KeInitializeSpinLock(puVar2 + lVar4 * 0x20 + 0x2a);
      if (lVar4 == 0) {
        iVar1 = ExInitializeLookasideListEx(puVar2 + 0x10,0,0,0x204,0,0xc0,0x46535153,0);
        if (iVar1 < 0) {
          ExFreePoolWithTag(puVar2,0x46535153);
          goto LAB_1c0005972;
        }
        puVar2[0x28] = 0;
        puVar2[0x29] = 0;
        *(undefined1 *)(puVar2 + 0x2c) = 1;
      }
      else {
        *(undefined1 *)(puVar2 + lVar4 * 0x20 + 0x2c) = 0;
        *(uint **)(puVar2 + lVar4 * 0x20 + 0x28) = puVar2 + 0x10;
      }
      lVar4 = lVar4 + 1;
    }
    *puVar2 = uVar5;
    puVar2[1] = 0;
    puVar2[2] = 0x46535153;
    puVar2[3] = 0x46535153;
    puVar2[4] = 0xc0;
    puVar2[5] = 0;
    puVar2[8] = 0x204;
    *(undefined2 *)(puVar2 + 9) = 0;
    puVar2[6] = 0;
    puVar2[7] = 0;
  }
  return puVar2;
}



===== RtlUnicodeStringCat @ 1c00059c8 =====

void RtlUnicodeStringCat(ushort *param_1,ushort *param_2)

{
  int iVar1;
  ulonglong uVar2;
  ulonglong local_res18;
  ulonglong local_res20;
  longlong local_28;
  ulonglong local_20;
  undefined2 *local_18;
  longlong local_10;
  
  local_28 = 0;
  local_res18 = 0;
  local_res20 = 0;
  uVar2 = RtlUnicodeStringValidateDestWorker(param_1,&local_28,&local_res18,&local_res20);
  if (-1 < (int)uVar2) {
    local_18 = (undefined2 *)0x0;
    local_20 = 0;
    iVar1 = RtlUnicodeStringValidateSrcWorker(param_2,&local_18,&local_20);
    uVar2 = local_res20;
    if (-1 < iVar1) {
      local_10 = 0;
      RtlWideCharArrayCopyWorker
                (local_28 + local_res20 * 2,local_res18 - local_res20,&local_10,local_18,local_20);
      *param_1 = ((short)uVar2 + (short)local_10) * 2;
    }
  }
  return;
}



===== RtlUnicodeStringCatString @ 1c0005a74 =====

ulonglong RtlUnicodeStringCatString(ushort *param_1,short *param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  short sVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong local_res18;
  ulonglong local_res20;
  longlong local_18 [2];
  
  local_18[0] = 0;
  local_res18 = 0;
  local_res20 = 0;
  uVar1 = RtlUnicodeStringValidateDestWorker(param_1,local_18,&local_res18,&local_res20);
  if ((int)uVar1 < 0) {
    return uVar1 & 0xffffffff;
  }
  lVar5 = 0x7fff;
  uVar1 = 0;
  sVar3 = 0;
  lVar4 = local_res18 - local_res20;
  if (lVar4 != 0) {
    lVar2 = local_res20 * 2 - (longlong)param_2;
    do {
      if (lVar5 == 0) goto LAB_1c0005b0d;
      if (*param_2 == 0) break;
      *(short *)(lVar2 + local_18[0] + (longlong)param_2) = *param_2;
      lVar5 = lVar5 + -1;
      param_2 = param_2 + 1;
      sVar3 = sVar3 + 1;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
    if ((lVar4 != 0) || (lVar5 == 0)) goto LAB_1c0005b0d;
  }
  uVar1 = 0;
  if (*param_2 != 0) {
    uVar1 = 0x80000005;
  }
LAB_1c0005b0d:
  *param_1 = (sVar3 + (short)local_res20) * 2;
  return uVar1;
}



===== SqosClientNodeComparisonRoutine @ 1c0005b34 =====

void SqosClientNodeComparisonRoutine(void *param_1,longlong param_2)

{
  memcmp(param_1,(void *)(param_2 + 0x18),0x10);
  return;
}



===== SqospAssignClientIoRates @ 1c0005b54 =====

void SqospAssignClientIoRates(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  
  if (*(int *)(param_1 + 0x78) != 0) {
    plVar3 = (longlong *)(param_1 + 0x68);
    plVar2 = (longlong *)*plVar3;
    if (plVar2 != plVar3) {
      do {
        if (*(int *)(plVar2[-5] + 0xbc) == 1) {
          lVar1 = *(longlong *)(param_1 + 200);
        }
        else {
          lVar1 = 0;
        }
        BalanceSetFlowMinimumIoRate(plVar2 + -5,lVar1);
        lVar1 = *(longlong *)(param_1 + 0xd0);
        plVar2[0x34] = lVar1;
        LOCK();
        plVar2[0x3a] = (ulonglong)(lVar1 << 0x10) / 5;
        UNLOCK();
        lVar1 = *(longlong *)(param_1 + 0xd8);
        plVar2[0x35] = lVar1;
        LOCK();
        plVar2[0x3b] = (ulonglong)(lVar1 << 0x10) / 5;
        UNLOCK();
        plVar2 = (longlong *)*plVar2;
      } while (plVar2 != plVar3);
    }
  }
  return;
}



===== SqospCreateFlow @ 1c0005bfc =====

longlong * SqospCreateFlow(longlong param_1,longlong param_2,longlong param_3)

{
  code *pcVar1;
  bool bVar2;
  undefined1 uVar3;
  longlong *_Dst;
  ulonglong uVar4;
  longlong *plVar5;
  longlong lVar6;
  longlong *plVar7;
  longlong *plVar8;
  undefined1 *puVar9;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [56];
  
  plVar5 = (longlong *)0x0;
  bVar2 = false;
  _Dst = (longlong *)ExAllocateFromLookasideListEx(param_2 + 0x30);
  if (_Dst != (longlong *)0x0) {
    memset(_Dst,0,0x240);
    *(undefined1 *)((longlong)_Dst + 0x1b9) = 1;
    KeInitializeSpinLock(_Dst + 0x3c);
    uVar4 = SqospBuildFlowName(param_2,param_3,(ushort *)(_Dst + 7));
    puVar9 = auStack_58;
    plVar8 = _Dst;
    if (-1 < (int)uVar4) {
      uVar3 = KeAcquireSpinLockRaiseToDpc(param_2 + 0x340);
      *(undefined1 *)(param_2 + 0x348) = uVar3;
      uVar3 = KeAcquireSpinLockRaiseToDpc(param_1);
      *(undefined1 *)(param_1 + 8) = uVar3;
      plVar5 = SqospFindFlow(param_1,param_2);
      puVar9 = auStack_58;
      if (plVar5 == (longlong *)0x0) {
        lVar6 = param_1 + 0x68;
        plVar8 = (longlong *)0x0;
        bVar2 = true;
        _Dst[1] = param_1;
        plVar5 = _Dst + 5;
        plVar7 = *(longlong **)(param_1 + 0x70);
        puVar9 = auStack_58;
        if (*plVar7 != lVar6) {
          plVar5 = (longlong *)0x3;
          pcVar1 = (code *)swi(0x29);
          lVar6 = (*pcVar1)();
          puVar9 = auStack_50;
        }
        plVar5[1] = (longlong)plVar7;
        *plVar5 = lVar6;
        *plVar7 = (longlong)plVar5;
        *(longlong **)(lVar6 + 8) = plVar5;
        *(int *)(param_1 + 0x78) = *(int *)(param_1 + 0x78) + 1;
        *(undefined8 *)(puVar9 + -8) = 0x1c0005d03;
        BalanceInitializeFlow(_Dst,param_2);
        plVar5 = _Dst;
        if (*(int *)(param_1 + 0x84) == 1) {
          *(undefined8 *)(puVar9 + -8) = 0x1c0005d14;
          SqospAssignClientIoRates(param_1);
        }
      }
      uVar3 = *(undefined1 *)(param_1 + 8);
      *(undefined8 *)(puVar9 + -8) = 0x1c0005d21;
      KeReleaseSpinLock(param_1,uVar3);
      uVar3 = *(undefined1 *)(param_2 + 0x348);
      *(undefined8 *)(puVar9 + -8) = 0x1c0005d36;
      KeReleaseSpinLock(param_2 + 0x340,uVar3);
      if ((bVar2) && (DAT_1c000d2a9 != '\0')) {
        *(undefined1 **)(puVar9 + 0x20) = puVar9 + 0x30;
        *(longlong **)(puVar9 + 0x30) = plVar5;
        *(undefined4 *)(puVar9 + 0x38) = 0x240;
        *(undefined8 *)(puVar9 + -8) = 0x1c0005d7c;
        PcwCreateInstance(plVar5 + 2,SqosPcFlowCounterSet,plVar5 + 7,1);
      }
      if (plVar8 == (longlong *)0x0) {
        return plVar5;
      }
    }
    *(undefined8 *)(puVar9 + -8) = 0x1c0005d8f;
    SqospFreeUnicodeString((undefined4 *)(plVar8 + 7));
    *(undefined8 *)(puVar9 + -8) = 0x1c0005d9d;
    ExFreeToLookasideListEx(param_2 + 0x30,plVar8);
  }
  return plVar5;
}



===== SqospCreateStreamHandleContext @ 1c0005dcc =====

int SqospCreateStreamHandleContext
              (longlong param_1,longlong param_2,longlong param_3,char param_4,char param_5,
              longlong *param_6)

{
  int iVar1;
  longlong lVar2;
  longlong local_28;
  longlong local_20;
  
  local_28 = 0;
  local_20 = 0;
  iVar1 = SqospAllocateStreamHandleContext(param_2,&local_28);
  lVar2 = local_28;
  if (iVar1 < 0) goto LAB_1c0005ed4;
  iVar1 = FltSetStreamHandleContext
                    (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),1,local_28,
                     &local_20);
  if (iVar1 < 0) {
    if (iVar1 != -0x3fe3fffe) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                 &WPP_af53c64ad8bd3a498290aca5a9ae070a_Traceguids,iVar1);
      }
      goto LAB_1c0005ed4;
    }
    FltReleaseContext(lVar2);
    lVar2 = local_20;
    local_20 = 0;
    if (param_5 != '\0') goto LAB_1c0005eab;
    iVar1 = 0;
  }
  else {
LAB_1c0005eab:
    iVar1 = SqospModifyStreamHandleContext(param_1,param_2,lVar2,param_3,param_4);
    if (iVar1 < 0) goto LAB_1c0005ed4;
  }
  *param_6 = lVar2;
  lVar2 = 0;
LAB_1c0005ed4:
  if (lVar2 != 0) {
    FltReleaseContext(lVar2);
  }
  if (local_20 != 0) {
    FltReleaseContext();
  }
  return iVar1;
}



===== SqospFindDeviceByVolumeId @ 1c0005f20 =====

undefined8 * SqospFindDeviceByVolumeId(longlong *param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  longlong lVar3;
  
  lVar3 = *param_1;
  if (lVar3 == 0) {
    lVar3 = param_1[1];
  }
  puVar1 = (undefined8 *)0x0;
  if (lVar3 != 0) {
    FltAcquirePushLockSharedEx(&SqosGlobals,0);
    for (puVar2 = DAT_1c000d148; (undefined8 **)puVar2 != &DAT_1c000d148;
        puVar2 = (undefined8 *)*puVar2) {
      puVar1 = puVar2 + -0x14;
      if (*(char *)((longlong)puVar2 + 0x19) == '\0') {
        lVar3 = *param_1 - puVar2[-0x13];
        if (lVar3 == 0) {
          lVar3 = param_1[1] - puVar2[-0x12];
        }
        if (lVar3 == 0) {
          FltReferenceContext(puVar1);
          goto LAB_1c0005fb0;
        }
      }
    }
    puVar1 = (undefined8 *)0x0;
LAB_1c0005fb0:
    FltReleasePushLockEx(&SqosGlobals,0);
  }
  return puVar1;
}



===== SqospModifyStreamHandleContext @ 1c0005fdc =====

int SqospModifyStreamHandleContext
              (longlong param_1,longlong param_2,longlong param_3,longlong param_4,char param_5)

{
  longlong *plVar1;
  char *pcVar2;
  char cVar3;
  undefined1 uVar4;
  longlong *plVar5;
  longlong lVar6;
  longlong lVar7;
  int iVar8;
  longlong lVar9;
  
  lVar9 = 0;
  plVar1 = (longlong *)(param_3 + 8);
  plVar5 = (longlong *)0x0;
  iVar8 = 0;
  lVar7 = param_2;
  if (*(longlong *)(param_3 + 0x10) != param_4) {
    lVar7 = *plVar1;
    plVar5 = SqospLookupFlow(param_4,lVar7,'\0',param_1);
    if (plVar5 == (longlong *)0x0) {
      return -0x3fffff66;
    }
  }
  lVar6 = *plVar1;
  uVar4 = KeAcquireSpinLockRaiseToDpc(lVar6 + 0x340);
  *(undefined1 *)(lVar6 + 0x348) = uVar4;
  lVar6 = *plVar1;
  if (*(char *)(lVar6 + 0x3a0) != '\0') {
    iVar8 = -0x3fe3fff5;
    goto LAB_1c00060d0;
  }
  pcVar2 = (char *)(param_3 + 0x20);
  cVar3 = *(char *)(*(longlong *)(param_3 + 0x10) + 0x7c);
  if ((cVar3 == '\0') && (*pcVar2 == '\0')) {
LAB_1c00060a3:
    if ((*pcVar2 == '\0') && ((*(char *)(param_4 + 0x7c) != '\0' || (param_5 != '\0')))) {
      *(int *)(lVar6 + 0x394) = *(int *)(lVar6 + 0x394) + -1;
      lVar6 = *(longlong *)(param_3 + 8);
LAB_1c00060c0:
      BalanceUpdateDeviceMode(lVar6,CONCAT71((int7)((ulonglong)lVar7 >> 8),cVar3),0);
    }
  }
  else {
    if ((*(char *)(param_4 + 0x7c) == '\0') && (param_5 == '\0')) {
      *(int *)(lVar6 + 0x394) = *(int *)(lVar6 + 0x394) + 1;
      lVar6 = *plVar1;
      goto LAB_1c00060c0;
    }
    if (cVar3 == '\0') goto LAB_1c00060a3;
  }
  *pcVar2 = param_5;
LAB_1c00060d0:
  lVar7 = *(longlong *)(param_3 + 8);
  KeReleaseSpinLock(lVar7 + 0x340,
                    CONCAT71((int7)((ulonglong)lVar7 >> 8),*(undefined1 *)(lVar7 + 0x348)));
  if (-1 < iVar8) {
    if (*(longlong *)(param_3 + 0x10) != param_4) {
      FltAcquirePushLockExclusiveEx(param_3,0);
      lVar9 = *(longlong *)(param_3 + 0x10);
      LOCK();
      *(int *)(param_4 + 0xc) = *(int *)(param_4 + 0xc) + 1;
      UNLOCK();
      *(longlong *)(param_3 + 0x10) = param_4;
      *(longlong **)(param_3 + 0x18) = plVar5;
      FltReleasePushLockEx(param_3,0);
    }
    SqosTraceStreamHandleContext(param_1,param_2,param_3,'\0');
    if (lVar9 != 0) {
      SqospReleaseClient(lVar9);
    }
  }
  return iVar8;
}



===== SqospProbeClientPolicy @ 1c0006168 =====

undefined1 SqospProbeClientPolicy(longlong param_1,longlong *param_2,longlong *param_3)

{
  undefined1 uVar1;
  longlong lVar2;
  undefined1 uVar3;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc();
  *(undefined1 *)(param_1 + 8) = uVar1;
  lVar2 = *(longlong *)(param_1 + 0x88) - *param_2;
  if (lVar2 == 0) {
    lVar2 = *(longlong *)(param_1 + 0x90) - param_2[1];
  }
  uVar3 = 0;
  if (lVar2 == 0) {
    lVar2 = *(longlong *)(param_1 + 0x98) - *param_3;
    if (lVar2 == 0) {
      lVar2 = *(longlong *)(param_1 + 0xa0) - param_3[1];
    }
    if (lVar2 == 0) {
      uVar3 = 1;
    }
  }
  KeReleaseSpinLock(param_1,uVar1);
  return uVar3;
}



===== SqospRemoveClientFlows @ 1c00061f8 =====

void SqospRemoveClientFlows(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  code *pcVar5;
  undefined1 uVar6;
  
  plVar1 = (longlong *)(param_1 + 0x68);
  while( true ) {
    plVar3 = (longlong *)*plVar1;
    if (plVar3 == plVar1) {
      return;
    }
    if (((longlong *)plVar3[1] != plVar1) || (lVar4 = *plVar3, *(longlong **)(lVar4 + 8) != plVar3))
    break;
    *plVar1 = lVar4;
    plVar2 = plVar3 + -5;
    *(longlong **)(lVar4 + 8) = plVar1;
    plVar3[1] = 0;
    *plVar3 = 0;
    *(int *)(param_1 + 0x78) = *(int *)(param_1 + 0x78) + -1;
    lVar4 = *plVar2;
    uVar6 = KeAcquireSpinLockRaiseToDpc(lVar4 + 0x340);
    *(undefined1 *)(lVar4 + 0x348) = uVar6;
    BalanceFinalizeFlow(plVar2);
    KeReleaseSpinLock(lVar4 + 0x340,*(undefined1 *)(lVar4 + 0x348));
    SqospCleanupFlow((longlong)plVar2,lVar4);
  }
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)(3);
  return;
}



===== SqospRemoveFlow @ 1c00062b8 =====

void SqospRemoveFlow(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined1 uVar4;
  longlong *plVar5;
  longlong *plVar6;
  
  uVar4 = KeAcquireSpinLockRaiseToDpc();
  *(undefined1 *)(param_1 + 8) = uVar4;
  plVar5 = SqospFindFlow(param_1,param_2);
  if (plVar5 != (longlong *)0x0) {
    plVar6 = plVar5 + 5;
    lVar1 = *plVar6;
    if ((*(longlong **)(lVar1 + 8) != plVar6) ||
       (plVar2 = (longlong *)plVar5[6], (longlong *)*plVar2 != plVar6)) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3);
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    plVar5[6] = 0;
    *plVar6 = 0;
    *(int *)(param_1 + 0x78) = *(int *)(param_1 + 0x78) + -1;
    BalanceFinalizeFlow(plVar5);
  }
  KeReleaseSpinLock(param_1,*(undefined1 *)(param_1 + 8));
  if (plVar5 != (longlong *)0x0) {
    SqospCleanupFlow((longlong)plVar5,param_2);
  }
  return;
}



===== SqospStartDeviceTeardown @ 1c0006360 =====

bool SqospStartDeviceTeardown(longlong param_1)

{
  bool bVar1;
  undefined1 uVar2;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x340);
  *(undefined1 *)(param_1 + 0x348) = uVar2;
  bVar1 = *(int *)(param_1 + 0x394) == 0;
  if (bVar1) {
    *(undefined1 *)(param_1 + 0x3a0) = 1;
  }
  KeReleaseSpinLock(param_1 + 0x340,uVar2);
  return bVar1;
}



===== SqospUpdateClientPolicy @ 1c00063d0 =====

ulonglong SqospUpdateClientPolicy(longlong param_1,ushort *param_2)

{
  ushort *puVar1;
  ushort uVar2;
  undefined8 uVar3;
  bool bVar4;
  undefined1 uVar5;
  ulonglong uVar6;
  longlong lVar7;
  undefined8 uVar8;
  longlong lVar9;
  ulonglong uVar10;
  ushort local_18 [4];
  longlong lStack_10;
  
  local_18[0] = 0;
  local_18[1] = 0;
  local_18[2] = 0;
  local_18[3] = 0;
  lStack_10 = 0;
  bVar4 = false;
  uVar5 = KeAcquireSpinLockRaiseToDpc();
  *(undefined1 *)(param_1 + 8) = uVar5;
  uVar2 = param_2[0x25];
  if (uVar2 != 0) {
    puVar1 = (ushort *)(param_1 + 0xa8);
    lStack_10 = (ulonglong)param_2[0x24] + (longlong)param_2;
    local_18[1] = uVar2;
    local_18[0] = uVar2;
    if (*(ushort *)(param_1 + 0xaa) < uVar2) {
      SqospFreeUnicodeString((undefined4 *)puVar1);
      uVar6 = SqospCopyUnicodeString(puVar1,local_18);
      uVar10 = uVar6 & 0xffffffff;
      if ((int)uVar6 < 0) goto LAB_1c00065fe;
    }
    else {
      RtlCopyUnicodeString(puVar1,local_18);
    }
  }
  uVar2 = param_2[0x27];
  if (uVar2 != 0) {
    puVar1 = (ushort *)(param_1 + 0xb8);
    lStack_10 = (ulonglong)param_2[0x26] + (longlong)param_2;
    local_18[1] = uVar2;
    local_18[0] = uVar2;
    if (*(ushort *)(param_1 + 0xba) < uVar2) {
      SqospFreeUnicodeString((undefined4 *)puVar1);
      uVar6 = SqospCopyUnicodeString(puVar1,local_18);
      uVar10 = uVar6 & 0xffffffff;
      if ((int)uVar6 < 0) goto LAB_1c00065fe;
    }
    else {
      RtlCopyUnicodeString(puVar1,local_18);
    }
  }
  uVar8 = *(undefined8 *)(param_2 + 0x18);
  uVar10 = 0;
  *(undefined8 *)(param_1 + 0x98) = *(undefined8 *)(param_2 + 0x14);
  *(undefined8 *)(param_1 + 0xa0) = uVar8;
  *(byte *)(param_1 + 0x7e) = (byte)((uint)*(undefined4 *)(param_2 + 2) >> 0x1d) & 1;
  lVar9 = *(longlong *)(param_2 + 0xc);
  if (lVar9 == 0) {
    lVar9 = *(longlong *)(param_2 + 0x10);
  }
  if (lVar9 == 0) {
    lVar9 = *(longlong *)(param_1 + 0x88);
    if (lVar9 == 0) {
      lVar9 = *(longlong *)(param_1 + 0x90);
    }
    if (((lVar9 == 0) && (*(longlong *)(param_1 + 0xd0) == *(longlong *)(param_2 + 0x1c))) &&
       (lVar9 = *(longlong *)(param_1 + 200), lVar9 == *(longlong *)(param_2 + 0x20))) {
      if (*param_2 < 0x101) {
        lVar7 = 0;
      }
      else {
        lVar7 = *(longlong *)(param_2 + 0x38);
      }
      if (*(longlong *)(param_1 + 0xd8) != lVar7) goto LAB_1c0006561;
    }
    else {
LAB_1c0006561:
      uVar8 = *(undefined8 *)(param_2 + 0x10);
      bVar4 = true;
      *(longlong *)(param_1 + 0x88) = *(longlong *)(param_2 + 0xc);
      *(undefined8 *)(param_1 + 0x90) = uVar8;
      *(undefined8 *)(param_1 + 0xd0) = *(undefined8 *)(param_2 + 0x1c);
      lVar9 = *(longlong *)(param_2 + 0x20);
      *(longlong *)(param_1 + 200) = lVar9;
      if (*param_2 < 0x101) {
        uVar8 = 0;
      }
      else {
        uVar8 = *(undefined8 *)(param_2 + 0x38);
      }
      *(undefined8 *)(param_1 + 0xd8) = uVar8;
    }
    *(uint *)(param_1 + 0x84) = (uint)(lVar9 != 0);
    if (!bVar4) goto LAB_1c00065fe;
  }
  else {
    lVar9 = *(longlong *)(param_2 + 0xc) - *(longlong *)(param_1 + 0x88);
    if (lVar9 == 0) {
      lVar9 = *(longlong *)(param_2 + 0x10) - *(longlong *)(param_1 + 0x90);
    }
    if (lVar9 == 0) goto LAB_1c00065fe;
    *(undefined4 *)(param_1 + 0x84) = 2;
    uVar8 = *(undefined8 *)(param_2 + 0xc);
    uVar3 = *(undefined8 *)(param_2 + 0x10);
    *(undefined8 *)(param_1 + 0xd0) = 0;
    *(undefined8 *)(param_1 + 200) = 0;
    *(undefined8 *)(param_1 + 0x88) = uVar8;
    *(undefined8 *)(param_1 + 0x90) = uVar3;
    *(undefined8 *)(param_1 + 0xd8) = 0;
  }
  SqospAssignClientIoRates(param_1);
LAB_1c00065fe:
  KeReleaseSpinLock(param_1,*(undefined1 *)(param_1 + 8));
  return uVar10;
}



===== WPP_SF_d @ 1c0006634 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_d(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== SqosDelayedJobQueueAcquire @ 1c0006680 =====

void SqosDelayedJobQueueAcquire(longlong param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + -0x20);
  *param_2 = uVar1;
  return;
}



===== SqosDelayedJobQueueCompleteCanceledIo @ 1c00066b0 =====

void SqosDelayedJobQueueCompleteCanceledIo(undefined8 param_1,longlong param_2)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 uVar5;
  
  lVar2 = *(longlong *)(param_2 + 0x40);
  lVar3 = *(longlong *)(*(longlong *)(lVar2 + 0x20) + 8);
  *(undefined1 *)(lVar2 + 0x84) = 1;
  uVar5 = KeQueryPerformanceCounter(0);
  *(undefined8 *)(lVar2 + 0xb0) = uVar5;
  *(undefined8 *)(param_2 + 0x20) = 0;
  *(undefined4 *)(param_2 + 0x18) = 0xc0000120;
  if (*(char *)(lVar2 + 0x80) == '\0') {
    LOCK();
    piVar1 = (int *)(*(longlong *)(lVar2 + 0x28) + 0x208);
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    SqospDestroyJob(lVar2);
    FltCompletePendedPreOperation(param_2,4);
  }
  else {
    FltReferenceContext(lVar3);
    lVar4 = *(longlong *)(*(longlong *)(lVar2 + 0x20) + 8);
    *(undefined1 *)(lVar2 + 0x7d) = 1;
    ExpInterlockedPushEntrySList(lVar4 + 0x110,lVar2 + 0x40);
    SqospQueueDeviceTimer(lVar3);
    FltReleaseContext(lVar3);
  }
  return;
}



===== SqosDelayedJobQueueInsertIo @ 1c0006790 =====

undefined8 SqosDelayedJobQueueInsertIo(longlong param_1,longlong param_2,char *param_3)

{
  longlong *plVar1;
  code *pcVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong *plVar5;
  
  if ((param_3 == (char *)0x0) || (*param_3 == '\0')) {
    plVar3 = (longlong *)(param_2 + 0x30);
    lVar4 = param_1 + -0x18;
    plVar5 = *(longlong **)(param_1 + -0x10);
    if (*plVar5 != lVar4) goto LAB_1c00067cd;
  }
  else {
    plVar3 = (longlong *)(param_2 + 0x30);
    plVar1 = (longlong *)(param_1 + -0x18);
    plVar5 = (longlong *)*plVar1;
    if ((longlong *)plVar5[1] == plVar1) {
      *plVar3 = (longlong)plVar5;
      *(longlong **)(param_2 + 0x38) = plVar1;
      plVar5[1] = (longlong)plVar3;
      *plVar1 = (longlong)plVar3;
      goto LAB_1c00067e2;
    }
LAB_1c00067cd:
    lVar4 = param_1 + -0x18;
    param_1 = 3;
    pcVar2 = (code *)swi(0x29);
    plVar3 = (longlong *)(*pcVar2)();
  }
  *plVar3 = lVar4;
  plVar3[1] = (longlong)plVar5;
  *plVar5 = (longlong)plVar3;
  *(longlong **)(lVar4 + 8) = plVar3;
LAB_1c00067e2:
  *(int *)(param_1 + -8) = *(int *)(param_1 + -8) + 1;
  return 0;
}



===== SqosDelayedJobQueuePeekNextIo @ 1c00067f0 =====

longlong SqosDelayedJobQueuePeekNextIo(longlong param_1,longlong param_2,longlong param_3)

{
  longlong *plVar1;
  
  plVar1 = (longlong *)(param_1 + -0x18);
  if (param_2 != 0) {
    plVar1 = (longlong *)(param_2 + 0x30);
  }
  do {
    plVar1 = (longlong *)*plVar1;
    if (plVar1 == (longlong *)(param_1 + -0x18)) {
      return 0;
    }
  } while ((param_3 != 0) && (*(longlong *)(plVar1[2] + 0x28) != param_3));
  return (longlong)(plVar1 + -6);
}



===== SqosDelayedJobQueueRelease @ 1c0006830 =====

void SqosDelayedJobQueueRelease(longlong param_1)

{
  KeReleaseSpinLock(param_1 + -0x20);
  return;
}



===== SqosDelayedJobQueueRemoveIo @ 1c0006850 =====

void SqosDelayedJobQueueRemoveIo(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  
  plVar1 = (longlong *)(param_2 + 0x30);
  lVar2 = *plVar1;
  if ((*(longlong **)(lVar2 + 8) == plVar1) &&
     (plVar3 = *(longlong **)(param_2 + 0x38), (longlong *)*plVar3 == plVar1)) {
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    *(undefined8 *)(param_2 + 0x38) = 0;
    *plVar1 = 0;
    *(int *)(param_1 + -8) = *(int *)(param_1 + -8) + -1;
    return;
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== SqosDeviceTimerRoutine @ 1c0006890 =====

void SqosDeviceTimerRoutine(undefined8 param_1,longlong param_2)

{
  LOCK();
  *(undefined4 *)(param_2 + 0x124) = 0;
  UNLOCK();
  SqospQueueDeviceWorkItem(param_2);
  FltReleaseContext(param_2);
  return;
}



===== SqosDeviceWorkItemRoutine @ 1c00068d0 =====

void SqosDeviceWorkItemRoutine(undefined8 param_1,longlong param_2)

{
  byte bVar1;
  char cVar2;
  undefined8 uVar3;
  longlong local_28;
  undefined *local_20;
  longlong local_18;
  undefined2 local_10;
  undefined1 local_e;
  undefined4 local_d;
  undefined1 local_9;
  
  local_d = 0;
  local_9 = 0;
  FltReferenceContext(param_2);
  local_20 = &DAT_1c000d180;
  local_e = 0;
  local_28 = param_2;
  bVar1 = KeGetCurrentIrql();
  if (bVar1 < 2) {
    cVar2 = KeAreAllApcsDisabled();
    if (cVar2 == '\0') {
      local_18 = (ulonglong)SystemReserved1[0x12]._4_4_ * 0x40 + *(longlong *)(local_20 + 0x50);
      goto LAB_1c000694e;
    }
  }
  local_18 = 0;
LAB_1c000694e:
  uVar3 = KeQueryPerformanceCounter(0);
  LOCK();
  *(undefined4 *)(param_2 + 0x120) = 0;
  UNLOCK();
  local_10 = 0x101;
  SqospProcessJobDispatcherContext(&local_28,(undefined8 *)0x0,uVar3);
  FltReleaseContext(param_2);
  return;
}



===== SqosJobDispatcherWorkItemRoutine @ 1c00069a0 =====

void SqosJobDispatcherWorkItemRoutine(longlong param_1)

{
  longlong local_28;
  undefined *puStack_20;
  longlong local_18;
  undefined8 uStack_10;
  
  local_28 = 0;
  puStack_20 = &DAT_1c000d180;
  local_18 = param_1 + -8;
  uStack_10 = 0x10000;
  SqospProcessJobDispatcherContext(&local_28,(undefined8 *)0x0,0);
  return;
}



===== SqospDispatchDeferredJob @ 1c00069e8 =====

void SqospDispatchDeferredJob(longlong *param_1)

{
  uint *puVar1;
  int iVar2;
  bool bVar3;
  
  puVar1 = (uint *)*param_1;
  if (((*puVar1 & 8) != 0) ||
     ((((byte)(*(char *)(*(longlong *)(puVar1 + 4) + 4) - 3U) < 2 &&
       (*(char *)(*(longlong *)(puVar1 + 4) + 5) == '\x02')) ||
      (iVar2 = FltLockUserBuffer(puVar1), -1 < iVar2)))) {
    bVar3 = *(char *)((longlong)param_1 + 0x7e) == '\0';
    if (!bVar3) {
      SqospDestroyJob((longlong)param_1);
      param_1 = (longlong *)0x0;
    }
    FltCompletePendedPreOperation(puVar1,!bVar3,param_1);
    return;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_febed84a0cc4351c39ee11633478a7cb_Traceguids,iVar2);
  }
  SqospFailJob(param_1,iVar2);
  return;
}



===== SqospFailJob @ 1c0006ab4 =====

void SqospFailJob(longlong *param_1,undefined4 param_2)

{
  longlong lVar1;
  longlong lVar2;
  byte bVar3;
  char cVar4;
  undefined1 uVar5;
  longlong lVar6;
  longlong local_38;
  undefined *local_30;
  longlong local_28;
  undefined2 local_20;
  undefined1 local_1e;
  undefined4 local_1d;
  undefined1 local_19;
  
  local_1d = 0;
  lVar1 = *param_1;
  local_19 = 0;
  lVar2 = *(longlong *)(param_1[4] + 8);
  FltReferenceContext(lVar2);
  local_20 = 0;
  local_30 = &DAT_1c000d180;
  local_1e = 0;
  local_38 = lVar2;
  bVar3 = KeGetCurrentIrql();
  if (bVar3 < 2) {
    cVar4 = KeAreAllApcsDisabled();
    if (cVar4 == '\0') {
      local_28 = (ulonglong)SystemReserved1[0x12]._4_4_ * 0x40 + *(longlong *)(local_30 + 0x50);
      goto LAB_1c0006b50;
    }
  }
  local_28 = 0;
LAB_1c0006b50:
  lVar6 = KeQueryPerformanceCounter(0);
  param_1[0x16] = lVar6;
  lVar2 = *(longlong *)(param_1[4] + 8);
  uVar5 = KeAcquireSpinLockRaiseToDpc(lVar2 + 0x340);
  *(undefined1 *)(lVar2 + 0x348) = uVar5;
  BalanceCompleteJob((longlong)param_1,(longlong)&local_38);
  lVar2 = *(longlong *)(param_1[4] + 8);
  KeReleaseSpinLock(lVar2 + 0x340,
                    CONCAT71((int7)((ulonglong)lVar2 >> 8),*(undefined1 *)(lVar2 + 0x348)));
  SqospDestroyJob((longlong)param_1);
  *(undefined8 *)(lVar1 + 0x20) = 0;
  *(undefined4 *)(lVar1 + 0x18) = param_2;
  FltCompletePendedPreOperation(lVar1);
  SqospProcessJobDispatcherContext(&local_38,(undefined8 *)0x0,lVar6);
  return;
}



===== SqospInitializeDelayedJobQueue @ 1c0006c0c =====

int SqospInitializeDelayedJobQueue(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  
  iVar2 = FltCbdqInitialize(param_1,param_2 + 0x20,SqosDelayedJobQueueInsertIo,
                            SqosDelayedJobQueueRemoveIo,SqosDelayedJobQueuePeekNextIo,
                            SqosDelayedJobQueueAcquire,SqosDelayedJobQueueRelease,
                            SqosDelayedJobQueueCompleteCanceledIo);
  if (-1 < iVar2) {
    KeInitializeSpinLock(param_2);
    lVar1 = param_2 + 8;
    *(longlong *)(param_2 + 0x10) = lVar1;
    *(longlong *)lVar1 = lVar1;
    *(undefined4 *)(param_2 + 0x18) = 0;
  }
  return iVar2;
}



===== SqospQueueDeviceWorkItem @ 1c0006ca0 =====

ulonglong SqospQueueDeviceWorkItem(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  
  uVar2 = (ulonglong)*(uint *)(param_1 + 0x120);
  if (*(uint *)(param_1 + 0x120) == 0) {
    LOCK();
    uVar1 = *(uint *)(param_1 + 0x120);
    if (uVar1 == 0) {
      *(uint *)(param_1 + 0x120) = 1;
    }
    else {
      uVar2 = (ulonglong)uVar1;
    }
    UNLOCK();
    if (uVar1 == 0) {
      FltReferenceContext(param_1);
      uVar2 = IoQueueWorkItemEx(*(undefined8 *)(param_1 + 0x28),SqosDeviceWorkItemRoutine,0,param_1)
      ;
    }
  }
  return uVar2;
}



===== SqospDecrementFlowQuota @ 1c0006cfc =====

ulonglong SqospDecrementFlowQuota(longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  ulonglong *puVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  longlong lVar7;
  bool bVar8;
  
  uVar1 = 1L << ((byte)DAT_1c000d2a4 & 0x3f);
  uVar4 = *(longlong *)(param_2 + 0x90) + -1 + uVar1 >> ((byte)DAT_1c000d2a4 & 0x3f);
  lVar7 = *(longlong *)(param_1 + 0x1d0);
  uVar6 = *(longlong *)(param_2 + 0x90) * 0x40 + 0xffc0U & 0xffffffffffff0000;
  if (*(longlong *)(param_1 + 0x1c8) == 0) {
    if (lVar7 != 0) {
LAB_1c0006d70:
      if ((*(longlong *)(param_1 + 0x1c8) == 0) && (lVar7 != 0)) {
        lVar7 = -uVar6;
        puVar3 = (ulonglong *)(param_1 + 0x200);
        goto LAB_1c0006d69;
      }
      uVar1 = *(ulonglong *)(param_1 + 0x1f8);
      if (((longlong)uVar1 < 0) || (uVar2 = uVar1, (longlong)*(ulonglong *)(param_1 + 0x200) < 0)) {
LAB_1c0006dec:
        return uVar1 & 0xffffffffffffff00;
      }
      do {
        LOCK();
        uVar1 = *(ulonglong *)(param_1 + 0x1f8);
        if (uVar2 == uVar1) {
          *(ulonglong *)(param_1 + 0x1f8) = uVar2 + uVar4 * -0x10000;
          uVar1 = uVar2;
        }
        else {
        }
        UNLOCK();
        if ((longlong)uVar1 < 0) goto LAB_1c0006dec;
        bVar8 = uVar1 != uVar2;
        uVar2 = uVar1;
        uVar5 = *(ulonglong *)(param_1 + 0x200);
      } while (bVar8);
      do {
        LOCK();
        uVar1 = *(ulonglong *)(param_1 + 0x200);
        if (uVar5 == uVar1) {
          *(ulonglong *)(param_1 + 0x200) = uVar5 - uVar6;
          uVar1 = uVar5;
        }
        else {
        }
        UNLOCK();
        if ((longlong)uVar1 < 0) {
          LOCK();
          *(longlong *)(param_1 + 0x1f8) = *(longlong *)(param_1 + 0x1f8) + uVar4 * 0x10000;
          UNLOCK();
          goto LAB_1c0006dec;
        }
        bVar8 = uVar1 != uVar5;
        uVar5 = uVar1;
      } while (bVar8);
    }
    uVar1 = CONCAT71((int7)(uVar1 >> 8),1);
  }
  else {
    if (lVar7 != 0) goto LAB_1c0006d70;
    lVar7 = uVar4 * -0x10000;
    puVar3 = (ulonglong *)(param_1 + 0x1f8);
LAB_1c0006d69:
    uVar1 = SqospInterlockedAdd64IfPositive(puVar3,lVar7);
  }
  return uVar1;
}



===== SqospInterlockedAdd64IfPositive @ 1c0006dfc =====

ulonglong SqospInterlockedAdd64IfPositive(ulonglong *param_1,longlong param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  bool bVar3;
  
  uVar1 = *param_1;
  do {
    if ((longlong)uVar1 < 1) {
      return uVar1 & 0xffffffffffffff00;
    }
    LOCK();
    if (uVar1 == *param_1) {
      *param_1 = uVar1 + param_2;
      uVar2 = uVar1;
    }
    else {
      uVar2 = *param_1;
    }
    UNLOCK();
    bVar3 = uVar2 != uVar1;
    uVar1 = uVar2;
  } while (bVar3);
  return CONCAT71((int7)(uVar2 >> 8),1);
}



===== SqospInterlockedAdd64UpToMaximum @ 1c0006e24 =====

longlong SqospInterlockedAdd64UpToMaximum(longlong *param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  bool bVar4;
  
  lVar1 = *param_1;
  do {
    lVar3 = lVar1 + param_2;
    if (param_3 < lVar1 + param_2) {
      lVar3 = param_3;
    }
    LOCK();
    if (lVar1 == *param_1) {
      *param_1 = lVar3;
      lVar2 = lVar1;
    }
    else {
      lVar2 = *param_1;
    }
    UNLOCK();
    bVar4 = lVar2 != lVar1;
    lVar1 = lVar2;
  } while (bVar4);
  return lVar3 - lVar2;
}



===== SqospLimiterProcessQueue @ 1c0006e50 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SqospLimiterProcessQueue(longlong param_1,longlong param_2)

{
  undefined8 ****ppppuVar1;
  int iVar2;
  longlong lVar3;
  code *pcVar4;
  ulonglong uVar5;
  undefined1 uVar6;
  bool bVar7;
  longlong lVar8;
  ulonglong uVar9;
  undefined1 *puVar10;
  undefined8 ****ppppuVar11;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [24];
  undefined8 ****local_38;
  undefined8 ****local_30;
  
  uVar5 = _DAT_fffff78000000008;
  puVar10 = auStack_58;
  local_30 = &local_38;
  local_38 = &local_38;
  while ((lVar8 = FltCbdqRemoveNextIo(param_1 + 0x2a0,0), lVar8 != 0 &&
         (lVar8 = *(longlong *)(lVar8 + 0x40), lVar8 != 0))) {
    lVar3 = *(longlong *)(lVar8 + 0x28);
    if (*(ulonglong *)(lVar3 + 0x1f0) <= uVar5) {
      uVar6 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x1e0);
      SqospLimiterReplenishQuota(lVar3,uVar5);
      KeReleaseSpinLock(lVar3 + 0x1e0,uVar6);
    }
    uVar9 = SqospDecrementFlowQuota(lVar3,lVar8);
    if ((char)uVar9 == '\0') {
      ppppuVar11 = (undefined8 ****)(lVar8 + 0x60);
      if ((undefined8 *****)*local_30 != &local_38) goto LAB_1c0006f9f;
      *(undefined8 *****)(lVar8 + 0x68) = local_30;
      *ppppuVar11 = &local_38;
      *local_30 = ppppuVar11;
      local_30 = ppppuVar11;
    }
    else {
      LOCK();
      *(int *)(lVar3 + 0x208) = *(int *)(lVar3 + 0x208) + -1;
      UNLOCK();
      SqospQueueJobForDispatch(lVar8,param_2);
    }
  }
  while ((undefined8 *****)local_38 != &local_38) {
    if (((undefined8 *****)*local_30 != &local_38) ||
       (ppppuVar11 = (undefined8 ****)local_30[1], (undefined8 ****)*ppppuVar11 != local_30))
    goto LAB_1c0006f9f;
    *ppppuVar11 = &local_38;
    ppppuVar1 = local_30 + -0xc;
    local_30 = ppppuVar11;
    bVar7 = SqospLimiterQueueJob(ppppuVar1,1);
    if (!bVar7) {
      SqospQueueJobForDispatch((longlong)ppppuVar1,param_2);
    }
  }
LAB_1c0006fa6:
  *(undefined8 *)(puVar10 + -8) = 0x1c0006fb7;
  uVar6 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x280);
  iVar2 = *(int *)(param_1 + 0x298);
  *(undefined8 *)(puVar10 + -8) = 0x1c0006fcb;
  KeReleaseSpinLock(param_1 + 0x280,uVar6);
  if (iVar2 != 0) {
    *(undefined8 *)(puVar10 + -8) = 0x1c0006fdc;
    SqospQueueDeviceWorkItem(param_1);
  }
  return;
LAB_1c0006f9f:
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  puVar10 = auStack_50;
  goto LAB_1c0006fa6;
}



===== SqospLimiterQueueJob @ 1c0007000 =====

bool SqospLimiterQueueJob(undefined8 *param_1,undefined1 param_2)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 local_res10 [24];
  
  uVar1 = *(undefined1 *)((longlong)param_1 + 0x7c);
  *(undefined1 *)((longlong)param_1 + 0x7c) = 1;
  local_res10[0] = param_2;
  iVar2 = FltCbdqInsertIo(*(longlong *)(param_1[4] + 8) + 0x2a0,*param_1,param_1 + 1,local_res10);
  if (iVar2 < 0) {
    *(undefined1 *)((longlong)param_1 + 0x7c) = uVar1;
  }
  return iVar2 >= 0;
}



===== SqospLimiterReplenishQuota @ 1c0007060 =====

void SqospLimiterReplenishQuota(longlong param_1,ulonglong param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong lVar5;
  
  if (param_2 < *(ulonglong *)(param_1 + 0x1f0)) {
    return;
  }
  *(longlong *)(param_1 + 0x220) = *(longlong *)(param_1 + 0x220) + 1;
  *(ulonglong *)(param_1 + 0x1f0) = DAT_1c000d328 + param_2;
  uVar4 = param_2 - *(longlong *)(param_1 + 0x1e8);
  lVar2 = *(longlong *)(param_1 + 0x1c8);
  lVar1 = *(longlong *)(param_1 + 0x1d0);
  if ((longlong)DAT_1c000d330 < (longlong)uVar4) {
    uVar4 = DAT_1c000d330;
  }
  lVar5 = ((uVar4 << 0x10) / DAT_1c000d330) * lVar2;
  lVar3 = ((uVar4 << 0x10) / DAT_1c000d330) * lVar1;
  if (lVar2 == 0) {
    if (lVar1 == 0) {
      return;
    }
  }
  else if (lVar1 == 0) {
    if (lVar5 == 0) {
      return;
    }
    lVar2 = SqospInterlockedAdd64UpToMaximum
                      ((longlong *)(param_1 + 0x1f8),lVar5,(ulonglong)(lVar2 << 0x10) / 5);
    uVar4 = *(longlong *)(param_1 + 0x210) + lVar2;
    *(ulonglong *)(param_1 + 0x210) = uVar4;
    *(ulonglong *)(param_1 + 0x218) = uVar4 >> 0x10;
    goto LAB_1c0007202;
  }
  if (lVar2 == 0) {
    if (lVar3 == 0) {
      return;
    }
  }
  else {
    if (lVar5 == 0) {
      return;
    }
    if (lVar3 == 0) {
      return;
    }
    lVar2 = SqospInterlockedAdd64UpToMaximum
                      ((longlong *)(param_1 + 0x1f8),lVar5,(ulonglong)(lVar2 << 0x10) / 5);
    uVar4 = *(longlong *)(param_1 + 0x210) + lVar2;
    *(ulonglong *)(param_1 + 0x210) = uVar4;
    *(ulonglong *)(param_1 + 0x218) = uVar4 >> 0x10;
  }
  lVar2 = SqospInterlockedAdd64UpToMaximum
                    ((longlong *)(param_1 + 0x200),lVar3,(ulonglong)(lVar1 << 0x10) / 5);
  uVar4 = *(longlong *)(param_1 + 0x228) + lVar2;
  *(ulonglong *)(param_1 + 0x228) = uVar4;
  *(ulonglong *)(param_1 + 0x230) = uVar4 >> 0x10;
LAB_1c0007202:
  *(ulonglong *)(param_1 + 0x1e8) = param_2;
  return;
}



===== SqospLimiterStartJobInternal @ 1c0007228 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool SqospLimiterStartJobInternal(undefined8 *param_1,longlong param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined1 uVar4;
  char cVar5;
  bool bVar6;
  ulonglong uVar7;
  
  uVar7 = _DAT_fffff78000000008;
  plVar2 = (longlong *)param_1[5];
  lVar3 = *plVar2;
  if (((ulonglong)plVar2[0x3e] <= _DAT_fffff78000000008) && (plVar1 = plVar2 + 0x3c, *plVar1 == 0))
  {
    uVar4 = KfRaiseIrql(2);
    cVar5 = KeTryToAcquireSpinLockAtDpcLevel(plVar1);
    if (cVar5 != '\0') {
      SqospLimiterReplenishQuota((longlong)plVar2,uVar7);
      KeReleaseSpinLockFromDpcLevel(plVar1);
    }
    KeLowerIrql(uVar4);
    if ((0 < (int)plVar2[0x41]) && (cVar5 != '\0')) {
      SqospLimiterProcessQueue(lVar3,param_2);
    }
  }
  if (((int)plVar2[0x41] == 0) &&
     (uVar7 = SqospDecrementFlowQuota((longlong)plVar2,(longlong)param_1), (char)uVar7 != '\0')) {
    return true;
  }
  bVar6 = SqospLimiterQueueJob(param_1,0);
  if (bVar6) {
    LOCK();
    *(int *)(plVar2 + 0x41) = (int)plVar2[0x41] + 1;
    UNLOCK();
    SqospQueueDeviceTimer(lVar3);
  }
  return !bVar6;
}



===== SqosVolumeStatsTimerRoutine @ 1c0007350 =====

void SqosVolumeStatsTimerRoutine(undefined8 param_1,longlong param_2)

{
  byte bVar1;
  
  bVar1 = SqospQueueStatsWorkItem(param_2);
  if (bVar1 == 0) {
    LOCK();
    *(uint *)(param_2 + 0x1040) = *(uint *)(param_2 + 0x1040) & 0xfffffffe;
    UNLOCK();
  }
  FltReleaseContext(param_2);
  return;
}



===== SqosVolumeStatsWorkItemRoutine @ 1c0007390 =====

void SqosVolumeStatsWorkItemRoutine(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined1 uVar1;
  ulonglong uVar2;
  char cVar3;
  
  cVar3 = '\0';
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_3 + 0x68);
  *(undefined1 *)(param_3 + 0x69) = uVar1;
  if (*(char *)(param_3 + 0x17) == '\0') {
    uVar2 = SqospCheckVolumeStatsLocked((longlong)param_3);
    cVar3 = (char)uVar2;
  }
  KeReleaseSpinLock(param_3 + 0x68,*(undefined1 *)(param_3 + 0x69));
  if (cVar3 != '\0') {
    SqospQueueVolumeStatsNotification(param_3);
  }
  LOCK();
  *(uint *)(param_3 + 0x208) = *(uint *)(param_3 + 0x208) & 0xfffffffe;
  UNLOCK();
  if (*(int *)(param_3 + 0x205) == 0) {
    SqospSetVolumeStatsTimer((longlong)param_3);
  }
  FltFreeGenericWorkItem(param_1);
  FltReleaseContext(param_3);
  return;
}



===== SqospAssignFlowIoRates @ 1c0007458 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 SqospAssignFlowIoRates(longlong param_1,longlong param_2,ulonglong param_3)

{
  void *_Buf2;
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  undefined1 uVar6;
  int iVar7;
  void *pvVar8;
  uint uVar9;
  ulonglong uVar10;
  longlong *plVar11;
  longlong *plVar12;
  
  lVar5 = _DAT_fffff78000000008;
  uVar1 = *(uint *)(param_2 + 0x250);
  uVar9 = *(uint *)(param_2 + 0x224);
  if (uVar9 != DAT_1c000d2a0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)uVar9,param_3,DAT_1c000d2a0,
                (char)uVar9);
    }
    DAT_1c000d2a0 = *(uint *)(param_2 + 0x224);
    DAT_1c000d2a4 = SqospLogBase2(DAT_1c000d2a0);
  }
  uVar6 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x340);
  *(undefined1 *)(param_1 + 0x348) = uVar6;
  uVar6 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x440);
  *(undefined1 *)(param_1 + 0x448) = uVar6;
  if (*(longlong *)(param_2 + 0x248) == 0) {
    BalanceRestoreCostEstimates(param_1);
  }
  else {
    BalanceOverrideCostEstimates(param_1,param_2 + 0x228);
    uVar9 = *(uint *)(param_2 + 0x220);
    *(undefined8 *)(param_1 + 0x458) = 0;
    *(ulonglong *)(param_1 + 0x450) = (ulonglong)uVar9 * 20000 + lVar5;
    BalanceSetLatencyTarget(param_1,*(ulonglong *)(param_2 + 0x248));
  }
  KeReleaseSpinLock(param_1 + 0x440,*(undefined1 *)(param_1 + 0x448));
  plVar12 = *(longlong **)(param_1 + 0x380);
  if (plVar12 != (longlong *)(param_1 + 0x380)) {
    uVar10 = 0;
    plVar11 = plVar12 + -3;
    if (*(int *)(param_2 + 0x254) != 0) {
      do {
        _Buf2 = (void *)((ulonglong)uVar1 + param_2 + uVar10 * 0x48);
        uVar2 = *(ulonglong *)((longlong)_Buf2 + 0x30);
        if (((uVar2 == 0) || (*(ulonglong *)((longlong)_Buf2 + 0x38) <= uVar2)) &&
           ((*(ulonglong *)((longlong)_Buf2 + 0x18) == 0 ||
            (*(ulonglong *)((longlong)_Buf2 + 0x20) <= *(ulonglong *)((longlong)_Buf2 + 0x18))))) {
          while( true ) {
            param_3 = 0x10;
            pvVar8 = _Buf2;
            iVar7 = memcmp((void *)(plVar11[1] + 0x58),_Buf2,0x10);
            if (-1 < iVar7) break;
            plVar12 = (longlong *)*plVar12;
            if (plVar12 == (longlong *)(param_1 + 0x380)) goto LAB_1c00077d1;
            plVar11 = plVar12 + -3;
          }
          if (iVar7 == 0) {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
               (4 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF__guid_DIIIII(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),pvVar8,param_3,_Buf2,
                                  (char)*(undefined4 *)((longlong)_Buf2 + 0x10),
                                  (char)*(undefined8 *)((longlong)_Buf2 + 0x20),
                                  (char)*(undefined8 *)((longlong)_Buf2 + 0x18),
                                  (char)*(undefined8 *)((longlong)_Buf2 + 0x38),
                                  (char)*(undefined8 *)((longlong)_Buf2 + 0x30),
                                  (char)*(undefined8 *)((longlong)_Buf2 + 0x40));
            }
            lVar3 = plVar11[1];
            uVar6 = KeAcquireSpinLockRaiseToDpc(lVar3);
            *(undefined1 *)(lVar3 + 8) = uVar6;
            *(byte *)((longlong)plVar11 + 0x1b9) =
                 (byte)(*(uint *)((longlong)_Buf2 + 0x10) >> 2) & 1;
            if ((*(uint *)(lVar3 + 0x84) & 0xfffffffd) == 0) {
              if ((*(uint *)((longlong)_Buf2 + 0x10) & 1) == 0) {
                *(uint *)(lVar3 + 0x80) = (*(uint *)((longlong)_Buf2 + 0x10) & 0xff) >> 1 & 1;
              }
              else {
                *(undefined4 *)(lVar3 + 0x80) = 2;
              }
              *(undefined8 *)(lVar3 + 0xd0) = *(undefined8 *)((longlong)_Buf2 + 0x30);
              *(undefined8 *)(lVar3 + 200) = *(undefined8 *)((longlong)_Buf2 + 0x38);
              *(undefined8 *)(lVar3 + 0xd8) = *(undefined8 *)((longlong)_Buf2 + 0x40);
              BalanceSetFlowMinimumIoRate(plVar11,*(longlong *)((longlong)_Buf2 + 0x20));
              lVar4 = *(longlong *)((longlong)_Buf2 + 0x18);
              plVar11[0x39] = lVar4;
              LOCK();
              plVar11[0x3f] = (ulonglong)(lVar4 << 0x10) / 5;
              UNLOCK();
              lVar4 = *(longlong *)((longlong)_Buf2 + 0x28);
              plVar11[0x3a] = lVar4;
              param_3 = lVar4 << 0x10;
              LOCK();
              plVar11[0x40] = param_3 / 5;
              UNLOCK();
            }
            KeReleaseSpinLock(lVar3,*(undefined1 *)(lVar3 + 8));
          }
        }
        else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
                (2 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF__guid_IIII(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,param_3,_Buf2,
                            (char)*(undefined8 *)((longlong)_Buf2 + 0x20),
                            (char)*(undefined8 *)((longlong)_Buf2 + 0x18),
                            (char)*(undefined8 *)((longlong)_Buf2 + 0x38),(char)uVar2);
        }
        uVar9 = (int)uVar10 + 1;
        uVar10 = (ulonglong)uVar9;
      } while (uVar9 < *(uint *)(param_2 + 0x254));
    }
  }
LAB_1c00077d1:
  if (500 < *(uint *)(param_2 + 0x220)) {
    *(ulonglong *)(param_1 + 0x10c8) = (ulonglong)(*(uint *)(param_2 + 0x220) - 500) * 10000 + lVar5
    ;
  }
  uVar1 = *(uint *)(param_2 + 0x220);
  *(undefined1 *)(param_1 + 0x10d8) = 0;
  *(ulonglong *)(param_1 + 0x10d0) = (ulonglong)uVar1 * 10000 + lVar5;
  KeReleaseSpinLock(param_1 + 0x340,*(undefined1 *)(param_1 + 0x348));
  return 0;
}



===== SqospInitializeVolumeStatsReporting @ 1c0007850 =====

void SqospInitializeVolumeStatsReporting(longlong param_1)

{
  SqospSetVolumeStatsTimer(param_1);
  return;
}



===== SqospQueueStatsWorkItem @ 1c0007868 =====

byte SqospQueueStatsWorkItem(longlong param_1)

{
  undefined1 uVar1;
  byte extraout_var;
  longlong lVar2;
  byte bVar3;
  
  bVar3 = 0;
  FltReferenceContext();
  lVar2 = FltAllocateGenericWorkItem();
  if (lVar2 != 0) {
    uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0xc0);
    if (*(longlong *)(param_1 + 200) != 0) {
      FltQueueGenericWorkItem
                (lVar2,*(longlong *)(param_1 + 200),SqosVolumeStatsWorkItemRoutine,1,param_1);
      bVar3 = extraout_var >> 7 ^ 1;
    }
    KeReleaseSpinLock(param_1 + 0xc0,uVar1);
    if (bVar3 != 0) {
      return bVar3;
    }
    FltFreeGenericWorkItem(lVar2);
  }
  FltReleaseContext(param_1);
  return 0;
}



===== SqospSetVolumeStatsTimer @ 1c0007950 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SqospSetVolumeStatsTimer(longlong param_1)

{
  uint *puVar1;
  uint uVar2;
  longlong lVar3;
  
  LOCK();
  puVar1 = (uint *)(param_1 + 0x1040);
  uVar2 = *puVar1;
  *puVar1 = *puVar1 | 1;
  UNLOCK();
  if ((uVar2 & 1) == 0) {
    if (_DAT_fffff78000000008 < *(ulonglong *)(param_1 + 0x10c8)) {
      lVar3 = (_DAT_fffff78000000008 - *(ulonglong *)(param_1 + 0x10c8)) + -200000;
    }
    else {
      lVar3 = -10000000;
    }
    FltReferenceContext();
    KeSetTimerEx(param_1 + 0x1048,lVar3,0,param_1 + 0x1088);
  }
  return;
}



===== SqospTeardownVolumeStatsReporting @ 1c00079d4 =====

void SqospTeardownVolumeStatsReporting(longlong param_1)

{
  char cVar1;
  
  cVar1 = KeCancelTimer(param_1 + 0x1048);
  if (cVar1 != '\0') {
    FltReleaseContext(param_1);
  }
  return;
}



===== SqospWriteUnicodeString @ 1c0007a10 =====

ushort SqospWriteUnicodeString(longlong param_1,uint param_2,uint *param_3,ushort *param_4)

{
  uint uVar1;
  ushort uVar2;
  
  uVar1 = *param_3;
  if (param_2 < uVar1 + *param_4) {
    uVar2 = 0;
  }
  else {
    memcpy((void *)(param_1 + (ulonglong)uVar1),*(void **)(param_4 + 4),(ulonglong)*param_4);
    uVar2 = *param_4;
    *param_3 = uVar2 + uVar1;
  }
  return uVar2;
}



===== SqospWriteVolumeStats @ 1c0007a64 =====

undefined8 SqospWriteVolumeStats(longlong param_1,undefined2 *param_2,uint param_3,uint *param_4)

{
  longlong *plVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  uint uVar8;
  undefined1 uVar9;
  ushort uVar10;
  undefined6 extraout_var;
  ulonglong uVar11;
  ulonglong uVar12;
  undefined6 extraout_var_00;
  undefined6 extraout_var_01;
  longlong *plVar13;
  uint uVar14;
  uint uVar15;
  undefined8 uVar16;
  undefined4 uVar17;
  undefined4 *_Dst;
  longlong *plVar18;
  longlong lVar19;
  longlong *plVar20;
  bool bVar21;
  uint local_48;
  uint local_44;
  
  uVar9 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x340);
  uVar16 = 0;
  *(undefined1 *)(param_1 + 0x348) = uVar9;
  if (param_3 < *(uint *)(param_1 + 0x10dc)) {
LAB_1c0007ab5:
    *param_4 = 0;
    uVar16 = 0xc0000023;
  }
  else {
    plVar13 = (longlong *)(param_1 + 0x380);
    plVar20 = (longlong *)*plVar13;
    uVar15 = 0;
    plVar18 = plVar20;
    if (plVar20 != plVar13) {
      do {
        uVar14 = (uint)(((ulonglong)param_3 - 0x278) / 0x88);
        bVar21 = uVar15 < uVar14;
        if (!bVar21) goto LAB_1c0007b20;
        plVar1 = plVar18 + 0x34;
        plVar18 = (longlong *)*plVar18;
        uVar8 = uVar15 + 1;
        if ((char)*plVar1 == '\0') {
          uVar8 = uVar15;
        }
        uVar15 = uVar8;
      } while (plVar18 != plVar13);
      bVar21 = uVar15 < uVar14;
LAB_1c0007b20:
      if (!bVar21 && uVar15 != uVar14) goto LAB_1c0007ab5;
    }
    uVar12 = 0;
    uVar17 = 0;
    local_44 = 0;
    uVar15 = uVar15 * 0x88 + 0x278;
    local_48 = uVar15;
    if (plVar20 != plVar13) {
      do {
        if ((char)plVar20[0x34] != '\0') {
          _Dst = (undefined4 *)(param_2 + uVar12 * 0x44 + 0x13c);
          memset(_Dst,0,0x88);
          lVar19 = plVar20[-2];
          uVar17 = *(undefined4 *)(lVar19 + 0x5c);
          uVar3 = *(undefined4 *)(lVar19 + 0x60);
          uVar4 = *(undefined4 *)(lVar19 + 100);
          *_Dst = *(undefined4 *)(lVar19 + 0x58);
          _Dst[1] = uVar17;
          _Dst[2] = uVar3;
          _Dst[3] = uVar4;
          if (*(char *)((longlong)plVar20 + 0x1a1) != '\0') {
            _Dst[0x20] = uVar15;
            uVar10 = SqospWriteUnicodeString
                               ((longlong)param_2,param_3,&local_48,(ushort *)(plVar20 + 4));
            _Dst[0x21] = (int)CONCAT62(extraout_var,uVar10);
          }
          lVar19 = plVar20[0x17];
          uVar11 = lVar19 - plVar20[0x2f];
          uVar12 = 0xffffffff;
          if (uVar11 < 0xffffffff) {
            uVar12 = uVar11;
          }
          _Dst[0x18] = (int)uVar12;
          plVar20[0x2f] = lVar19;
          lVar19 = plVar20[0x18];
          uVar11 = lVar19 - plVar20[0x30];
          uVar12 = 0xffffffff;
          if (uVar11 < 0xffffffff) {
            uVar12 = uVar11;
          }
          _Dst[0x19] = (int)uVar12;
          plVar20[0x30] = lVar19;
          lVar19 = plVar20[0x19];
          uVar11 = lVar19 - plVar20[0x31];
          uVar12 = 0xffffffff;
          if (uVar11 < 0xffffffff) {
            uVar12 = uVar11;
          }
          _Dst[0x1a] = (int)uVar12;
          plVar20[0x31] = lVar19;
          lVar19 = plVar20[0x1a];
          *(ulonglong *)(_Dst + 0x1c) =
               (ulonglong)((lVar19 - plVar20[0x32]) * DAT_1c000d298) >> 0x10;
          plVar20[0x32] = lVar19;
          lVar19 = plVar20[0x1b];
          *(ulonglong *)(_Dst + 0x1e) =
               (ulonglong)((lVar19 - plVar20[0x33]) * DAT_1c000d298) >> 0x10;
          lVar2 = plVar20[-2];
          plVar20[0x33] = lVar19;
          uVar9 = KeAcquireSpinLockRaiseToDpc(lVar2);
          *(undefined1 *)(lVar2 + 8) = uVar9;
          lVar19 = plVar20[-2];
          uVar17 = *(undefined4 *)(lVar19 + 0x8c);
          uVar3 = *(undefined4 *)(lVar19 + 0x90);
          uVar4 = *(undefined4 *)(lVar19 + 0x94);
          _Dst[4] = *(undefined4 *)(lVar19 + 0x88);
          _Dst[5] = uVar17;
          _Dst[6] = uVar3;
          _Dst[7] = uVar4;
          uVar7 = *(undefined8 *)(plVar20[-2] + 0xa0);
          *(undefined8 *)(_Dst + 8) = *(undefined8 *)(plVar20[-2] + 0x98);
          *(undefined8 *)(_Dst + 10) = uVar7;
          if (*(char *)(plVar20[-2] + 0x7e) == '\0') {
            uVar12 = *(ulonglong *)(plVar20[-2] + 0xe0);
            uVar11 = 0xffffffff;
            if (uVar12 < 0xffffffff) {
              uVar11 = uVar12;
            }
            _Dst[0xc] = (int)uVar11;
            *(undefined8 *)(plVar20[-2] + 0xe0) = 0;
            uVar12 = 0xffffffff;
            if (*(ulonglong *)(plVar20[-2] + 0xe8) < 0xffffffff) {
              uVar12 = *(ulonglong *)(plVar20[-2] + 0xe8);
            }
            _Dst[0xd] = (int)uVar12;
            *(undefined8 *)(plVar20[-2] + 0xe8) = 0;
            uVar12 = 0xffffffff;
            if (*(ulonglong *)(plVar20[-2] + 0xf0) < 0xffffffff) {
              uVar12 = *(ulonglong *)(plVar20[-2] + 0xf0);
            }
            _Dst[0xe] = (int)uVar12;
            *(undefined8 *)(plVar20[-2] + 0xf0) = 0;
            *(undefined8 *)(_Dst + 0x10) = *(undefined8 *)(plVar20[-2] + 0xf8);
            *(undefined8 *)(plVar20[-2] + 0xf8) = 0;
            *(undefined8 *)(_Dst + 0x12) = *(undefined8 *)(plVar20[-2] + 0x100);
            *(undefined8 *)(plVar20[-2] + 0x100) = 0;
          }
          else {
            _Dst[0xc] = _Dst[0x18];
            _Dst[0xd] = _Dst[0x19];
            *(undefined8 *)(_Dst + 0x10) = *(undefined8 *)(_Dst + 0x1c);
            *(undefined8 *)(_Dst + 0x12) = *(undefined8 *)(_Dst + 0x1e);
            _Dst[0xe] = _Dst[0x1a];
          }
          if (*(char *)((longlong)plVar20 + 0x1a1) != '\0') {
            _Dst[0x14] = local_48;
            uVar10 = SqospWriteUnicodeString
                               ((longlong)param_2,param_3,&local_48,(ushort *)(plVar20[-2] + 0xa8));
            _Dst[0x15] = (int)CONCAT62(extraout_var_00,uVar10);
            _Dst[0x16] = local_48;
            uVar10 = SqospWriteUnicodeString
                               ((longlong)param_2,param_3,&local_48,(ushort *)(plVar20[-2] + 0xb8));
            _Dst[0x17] = (int)CONCAT62(extraout_var_01,uVar10);
          }
          KeReleaseSpinLock();
          local_44 = local_44 + 1;
          uVar12 = (ulonglong)local_44;
          *(undefined1 *)(plVar20 + 0x34) = 0;
          uVar15 = local_48;
        }
        uVar17 = (undefined4)uVar12;
        plVar20 = (longlong *)*plVar20;
      } while (plVar20 != plVar13);
    }
    memset(param_2,0,0x278);
    *param_2 = 0x101;
    plVar13 = (longlong *)(param_2 + 0x124);
    *(undefined4 *)(param_2 + 2) = 3;
    uVar3 = *(undefined4 *)(param_1 + 8);
    uVar4 = *(undefined4 *)(param_1 + 0xc);
    uVar5 = *(undefined4 *)(param_1 + 0x10);
    uVar6 = *(undefined4 *)(param_1 + 0x14);
    *(undefined4 *)(param_2 + 0x138) = 0x278;
    *(undefined4 *)(param_2 + 0x13a) = uVar17;
    lVar19 = 4;
    *(undefined4 *)(param_2 + 0x108) = uVar3;
    *(undefined4 *)(param_2 + 0x10a) = uVar4;
    *(undefined4 *)(param_2 + 0x10c) = uVar5;
    *(undefined4 *)(param_2 + 0x10e) = uVar6;
    do {
      *plVar13 = *(longlong *)((param_1 - (longlong)param_2) + 0x2c8 + (longlong)plVar13) / 0x2000;
      uVar12 = DAT_1c000d2d0;
      plVar13 = plVar13 + 1;
      lVar19 = lVar19 + -1;
    } while (lVar19 != 0);
    uVar11 = *(ulonglong *)(param_1 + 0xfc0);
    *(ulonglong *)(param_2 + 0x134) = uVar11;
    if (((uVar11 == 0) || (uVar12 < uVar11)) || (uVar12 = DAT_1c000d2d8, uVar11 < DAT_1c000d2d8)) {
      *(ulonglong *)(param_2 + 0x134) = uVar12;
    }
    lVar19 = *(longlong *)(param_1 + 0xfe0);
    uVar11 = lVar19 - *(longlong *)(param_1 + 0x10e0);
    uVar12 = 0xffffffff;
    if (uVar11 < 0xffffffff) {
      uVar12 = uVar11;
    }
    *(int *)(param_2 + 0x114) = (int)uVar12;
    *(longlong *)(param_1 + 0x10e0) = lVar19;
    lVar19 = *(longlong *)(param_1 + 0xff8);
    uVar11 = lVar19 - *(longlong *)(param_1 + 0x10e8);
    uVar12 = 0xffffffff;
    if (uVar11 < 0xffffffff) {
      uVar12 = uVar11;
    }
    *(int *)(param_2 + 0x116) = (int)uVar12;
    *(longlong *)(param_1 + 0x10e8) = lVar19;
    lVar19 = *(longlong *)(param_1 + 0x1010);
    uVar11 = lVar19 - *(longlong *)(param_1 + 0x10f0);
    uVar12 = 0xffffffff;
    if (uVar11 < 0xffffffff) {
      uVar12 = uVar11;
    }
    *(int *)(param_2 + 0x118) = (int)uVar12;
    *(longlong *)(param_1 + 0x10f0) = lVar19;
    lVar19 = *(longlong *)(param_1 + 0x1030);
    *(ulonglong *)(param_2 + 0x11c) =
         (ulonglong)((lVar19 - *(longlong *)(param_1 + 0x10f8)) * DAT_1c000d298) >> 0x10;
    *(longlong *)(param_1 + 0x10f8) = lVar19;
    lVar19 = *(longlong *)(param_1 + 0x1038);
    *(ulonglong *)(param_2 + 0x120) =
         (ulonglong)((lVar19 - *(longlong *)(param_1 + 0x1100)) * DAT_1c000d298) >> 0x10;
    *(longlong *)(param_1 + 0x1100) = lVar19;
    *param_4 = local_48;
  }
  KeReleaseSpinLock(param_1 + 0x340,*(undefined1 *)(param_1 + 0x348));
  return uVar16;
}



===== WPP_SF_ @ 1c0007fb4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,0);
  return;
}



===== WPP_SF_DD @ 1c0007fe0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_484a7e20184230f2fd6f3fbff0f89920_Traceguids,10,local_res20,4,&param_5
             ,4,0);
  return;
}



===== WPP_SF__guid_ @ 1c0008038 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF__guid_(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_484a7e20184230f2fd6f3fbff0f89920_Traceguids,0xd,param_4,0x10,0);
  return;
}



===== WPP_SF__guid_DIIIII @ 1c000807c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF__guid_DIIIII(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        ,undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        ,undefined1 param_9,undefined1 param_10)

{
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_484a7e20184230f2fd6f3fbff0f89920_Traceguids,0xc,param_4,0x10,&param_5
             ,4,&param_6,8,&param_7,8,&param_8,8,&param_9,8,&param_10,8,0);
  return;
}



===== WPP_SF__guid_IIII @ 1c0008118 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF__guid_IIII(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                      undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_484a7e20184230f2fd6f3fbff0f89920_Traceguids,0xb,param_4,0x10,&param_5
             ,8,&param_6,8,&param_7,8,&param_8,8,0);
  return;
}



===== SqosInstanceTeardownStart @ 1c00081a0 =====

void SqosInstanceTeardownStart(longlong param_1,uint param_2)

{
  undefined1 uVar1;
  int iVar2;
  longlong local_res8;
  
  local_res8 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,(ulonglong)param_2,
              *(undefined8 *)(param_1 + 0x10),(char)param_2);
  }
  iVar2 = FltGetInstanceContext(*(undefined8 *)(param_1 + 0x18),&local_res8);
  if (-1 < iVar2) {
    uVar1 = KeAcquireSpinLockRaiseToDpc(local_res8 + 0xc0);
    *(undefined8 *)(local_res8 + 200) = 0;
    KeReleaseSpinLock(local_res8 + 0xc0,uVar1);
    FltCbdqDisable(local_res8 + 0x1e0);
    *(undefined1 *)(local_res8 + 0xb8) = 1;
    FltReleaseContext(local_res8);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
             &WPP_97d16c38264433ff5e04fa48b3a3652b_Traceguids,0);
  }
  return;
}



===== SqosPostFileSystemControl @ 1c00082c0 =====

ulonglong SqosPostFileSystemControl
                    (longlong param_1,longlong param_2,longlong *param_3,byte param_4)

{
  ulonglong uVar1;
  longlong *plVar2;
  
  uVar1 = 0;
  plVar2 = param_3;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3c,param_3,
              *(undefined8 *)(param_2 + 0x20),
              (char)*(undefined4 *)(*(longlong *)(param_1 + 0x10) + 0x28));
  }
  if (param_3 != (longlong *)0x0) {
    *param_3 = param_1;
    *(longlong **)(param_1 + 0x40) = param_3;
    uVar1 = SqospCompleteJob((longlong)param_3,param_4 & 1);
    uVar1 = uVar1 & 0xffffffff;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3d,plVar2,(int)uVar1);
  }
  return uVar1;
}



===== WPP_SF_L @ 1c0008390 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_L(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_97d16c38264433ff5e04fa48b3a3652b_Traceguids,param_2,local_res20,4,0);
  return;
}



===== WPP_SF_DDq @ 1c00083d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DDq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_97d16c38264433ff5e04fa48b3a3652b_Traceguids,0x21,local_res20,4,
             &param_5,4,&param_6,8,0);
  return;
}



===== WPP_SF_III @ 1c0008440 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_III(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_97d16c38264433ff5e04fa48b3a3652b_Traceguids,0x22,&local_res20,8,
             &param_5,8,&param_6,8,0);
  return;
}



===== WPP_SF_q @ 1c00084a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_97d16c38264433ff5e04fa48b3a3652b_Traceguids,param_2,&local_res20,8,0)
  ;
  return;
}



===== WPP_SF_qD @ 1c00084ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_97d16c38264433ff5e04fa48b3a3652b_Traceguids,param_2,&local_res20,8,
             &param_5,4,0);
  return;
}



===== WPP_SF_ql @ 1c0008544 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ql(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_97d16c38264433ff5e04fa48b3a3652b_Traceguids,0x49,&local_res20,8,
             &param_5,4,0);
  return;
}



===== WppClassicProviderCallback @ 1c00085a0 =====

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



===== wil_details_FeatureDescriptors_SkipPadding @ 1c00085d4 =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_1c000ccbf < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_RecordCachedUsage @ 1c0008600 =====

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



===== wil_details_RecordFeatureUsageReporting @ 1c0008760 =====

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



===== WPP_SF_qDDDDZZZ @ 1c00087e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qDDDDZZZ(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                    undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                    wchar_t *param_9,wchar_t *param_10,wchar_t *param_11)

{
  wchar_t wVar1;
  wchar_t wVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  wchar_t *pwVar5;
  wchar_t *pwVar6;
  wchar_t *pwVar7;
  wchar_t *pwVar8;
  wchar_t wVar9;
  undefined8 local_res20;
  
  pwVar3 = L"NULL";
  if (param_11 == (wchar_t *)0x0) {
    wVar2 = L'\b';
LAB_1c000884a:
    pwVar4 = L"NULL";
  }
  else {
    wVar2 = *param_11;
    if (*param_11 == L'\0') goto LAB_1c000884a;
    pwVar4 = *(wchar_t **)(param_11 + 4);
  }
  pwVar6 = param_11;
  if (param_11 == (wchar_t *)0x0) {
    pwVar6 = L"\b";
  }
  if (param_10 == (wchar_t *)0x0) {
    wVar1 = L'\b';
  }
  else {
    wVar1 = *param_10;
    if (*param_10 != L'\0') {
      pwVar5 = *(wchar_t **)(param_10 + 4);
      goto LAB_1c0008876;
    }
  }
  pwVar5 = L"NULL";
LAB_1c0008876:
  pwVar7 = param_10;
  if (param_10 == (wchar_t *)0x0) {
    pwVar7 = L"\b";
  }
  if (param_9 == (wchar_t *)0x0) {
    wVar9 = L'\b';
  }
  else {
    wVar9 = *param_9;
    if (*param_9 != L'\0') {
      pwVar3 = *(wchar_t **)(param_9 + 4);
    }
  }
  pwVar8 = param_9;
  if (param_9 == (wchar_t *)0x0) {
    pwVar8 = L"\b";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fa3443bab7c03510ec50bc5c71b707b7_Traceguids,10,&local_res20,8,
             &param_5,4,&param_6,4,&param_7,4,&param_8,4,pwVar8,2,pwVar3,wVar9,pwVar7,2,pwVar5,wVar1
             ,pwVar6,2,pwVar4,wVar2,0);
  return;
}



===== WPP_SF_sqZ_guid_DD @ 1c00089a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sqZ_guid_DD(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4,
                       undefined1 param_5,wchar_t *param_6,undefined8 param_7,undefined1 param_8,
                       undefined1 param_9)

{
  wchar_t *pwVar1;
  longlong lVar2;
  longlong lVar3;
  wchar_t wVar4;
  wchar_t *pwVar5;
  
  if (param_6 == (wchar_t *)0x0) {
    wVar4 = L'\b';
  }
  else {
    wVar4 = *param_6;
    if (*param_6 != L'\0') {
      pwVar5 = *(wchar_t **)(param_6 + 4);
      goto LAB_1c00089e3;
    }
  }
  pwVar5 = L"NULL";
LAB_1c00089e3:
  pwVar1 = param_6;
  if (param_6 == (wchar_t *)0x0) {
    pwVar1 = L"\b";
  }
  if (param_4 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    lVar2 = -1;
    do {
      lVar3 = lVar2;
      lVar2 = lVar3 + 1;
    } while (param_4[lVar2] != '\0');
    lVar3 = lVar3 + 2;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fa3443bab7c03510ec50bc5c71b707b7_Traceguids,0xb,param_4,lVar3,
             &param_5,8,pwVar1,2,pwVar5,wVar4,param_7,0x10,&param_8,4,&param_9,4,0);
  return;
}



===== SqospAllocate @ 1c0008ae0 =====

void SqospAllocate(undefined8 param_1)

{
  ExAllocatePool2(0x40,param_1,0x46535153);
  return;
}



===== SqospCleanUnicodeStringForPC @ 1c0008b0c =====

void SqospCleanUnicodeStringForPC(ushort *param_1)

{
  short sVar1;
  short *psVar2;
  ulonglong uVar3;
  
  psVar2 = *(short **)(param_1 + 4);
  if (*param_1 >> 1 != 0) {
    uVar3 = (ulonglong)(*param_1 >> 1);
    do {
      sVar1 = *psVar2;
      if (sVar1 == 0x23) {
LAB_1c0008b52:
        *psVar2 = 0x5f;
      }
      else if (sVar1 == 0x28) {
        *psVar2 = 0x5b;
      }
      else if (sVar1 == 0x29) {
        *psVar2 = 0x5d;
      }
      else {
        if (sVar1 == 0x2a) goto LAB_1c0008b52;
        if (sVar1 == 0x2f) {
          *psVar2 = 0x2d;
        }
      }
      psVar2 = psVar2 + 1;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  return;
}



===== SqospFree @ 1c0008b6c =====

void SqospFree(undefined8 param_1)

{
  ExFreePoolWithTag(param_1,0x46535153);
  return;
}



===== SqospIsNullGuid @ 1c0008b90 =====

undefined8 SqospIsNullGuid(longlong *param_1)

{
  longlong lVar1;
  
  lVar1 = *param_1;
  if (lVar1 == 0) {
    lVar1 = param_1[1];
  }
  return CONCAT71((int7)((ulonglong)lVar1 >> 8),lVar1 == 0);
}



===== SqospLogBase2 @ 1c0008bb8 =====

int SqospLogBase2(uint param_1)

{
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    param_1 = param_1 >> 1;
    if (param_1 == 0) break;
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}



===== DvRemoveOrderedWorkQueue @ 1c0008bcc =====

void DvRemoveOrderedWorkQueue(ulonglong *param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  bool bVar6;
  
  uVar3 = *param_1;
  do {
    if ((uVar3 & 2) != 0) {
      puVar5 = (undefined8 *)DvpRemoveWorkQueueRunningDown((longlong *)param_1);
      break;
    }
    puVar5 = (undefined8 *)(uVar3 & 0xfffffffffffffffe);
    LOCK();
    if (uVar3 == *param_1) {
      *param_1 = (ulonglong)(puVar5 != (undefined8 *)0x0);
      uVar4 = uVar3;
    }
    else {
      uVar4 = *param_1;
    }
    UNLOCK();
    bVar6 = uVar4 != uVar3;
    uVar3 = uVar4;
  } while (bVar6);
  puVar2 = (undefined8 *)0x0;
  while (puVar5 != (undefined8 *)0x0) {
    puVar1 = (undefined8 *)*puVar5;
    *puVar5 = puVar2;
    puVar2 = puVar5;
    puVar5 = puVar1;
  }
  return;
}



===== DvpRemoveWorkQueueRunningDown @ 1c0008c2c =====

longlong DvpRemoveWorkQueueRunningDown(longlong *param_1)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *param_1;
  lVar2 = *(longlong *)(lVar1 + 0x16);
  *(undefined8 *)(lVar1 + 0x16) = 0;
  if (lVar2 == 0) {
    *param_1 = 0;
    KeSetEvent(lVar1 + -2,0,0);
  }
  return lVar2;
}



===== _guard_check_icall @ 1c0008c80 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c0008c98 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c0008cbc =====

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



===== __GSHandlerCheck_SEH @ 1c0008d24 =====

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



===== __cpu_features_init @ 1c0008dc0 =====

/* WARNING: Removing unreachable block (ram,0x0001c0008e2a) */
/* WARNING: Removing unreachable block (ram,0x0001c0008dd9) */
/* WARNING: Removing unreachable block (ram,0x0001c0008dca) */

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



===== __security_check_cookie @ 1c0008e90 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0008ed0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0008f00 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0008f00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0008f30 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcmp @ 1c0008f60 =====

int __cdecl memcmp(void *_Buf1,void *_Buf2,size_t _Size)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  bool bVar5;
  
  lVar3 = (longlong)_Buf2 - (longlong)_Buf1;
  if (7 < _Size) {
    for (; ((ulonglong)_Buf1 & 7) != 0; _Buf1 = (void *)((longlong)_Buf1 + 1)) {
      bVar5 = (byte)*(ulonglong *)_Buf1 < *(byte *)((longlong)_Buf1 + lVar3);
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_1c0008fa3;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_1c0009014;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_1c0009010:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1c0009014;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_1c000900c:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1c0009010;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1c000900c;
          }
          _Buf1 = (void *)((longlong)_Buf1 + 0x20);
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
        _Size = _Size & 0x1f;
      }
      uVar4 = _Size >> 3;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) {
LAB_1c0009014:
            uVar4 = *(ulonglong *)(lVar3 + (longlong)_Buf1);
            uVar1 = (uint)((uVar2 >> 0x38 | (uVar2 & 0xff000000000000) >> 0x28 |
                            (uVar2 & 0xff0000000000) >> 0x18 | (uVar2 & 0xff00000000) >> 8 |
                            (uVar2 & 0xff000000) << 8 | (uVar2 & 0xff0000) << 0x18 |
                            (uVar2 & 0xff00) << 0x28 | uVar2 << 0x38) <
                          (uVar4 >> 0x38 | (uVar4 & 0xff000000000000) >> 0x28 |
                           (uVar4 & 0xff0000000000) >> 0x18 | (uVar4 & 0xff00000000) >> 8 |
                           (uVar4 & 0xff000000) << 8 | (uVar4 & 0xff0000) << 0x18 |
                           (uVar4 & 0xff00) << 0x28 | uVar4 << 0x38));
            return (1 - uVar1) - (uint)(uVar1 != 0);
          }
          _Buf1 = (void *)((longlong)_Buf1 + 8);
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
        _Size = _Size & 7;
      }
    }
  }
  while( true ) {
    if (_Size == 0) {
      return 0;
    }
    bVar5 = (byte)*(ulonglong *)_Buf1 < *(byte *)((longlong)_Buf1 + lVar3);
    if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) break;
    _Buf1 = (void *)((longlong)_Buf1 + 1);
    _Size = _Size - 1;
  }
LAB_1c0008fa3:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== memcpy @ 1c0009080 =====

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



===== memset @ 1c0009380 =====

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



===== __memset_repmovs @ 1c00094c0 =====

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



===== __memset_query @ 1c0009540 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c00095c0 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0009700 =====

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



===== __memset_spec_plain @ 1c0009780 =====

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



===== SqospCleanupDevice @ 1c0011008 =====

void SqospCleanupDevice(longlong param_1)

{
  int *piVar1;
  int *piVar2;
  longlong lVar3;
  
  if (*(longlong *)(param_1 + 0x98) != 0) {
    PcwCloseInstance();
  }
  ExDeleteLookasideListEx(param_1 + 0x30);
  piVar1 = *(int **)(param_1 + 0x90);
  if (piVar1 != (int *)0x0) {
    lVar3 = (longlong)(*piVar1 + -1);
    if (-1 < *piVar1 + -1) {
      piVar2 = piVar1 + lVar3 * 0x20 + 0x10;
      do {
        if ((char)piVar2[0x1c] != '\0') {
          ExDeleteLookasideListEx(piVar2);
        }
        piVar2 = piVar2 + -0x20;
        lVar3 = lVar3 + -1;
      } while (-1 < lVar3);
    }
    ExFreePoolWithTag(piVar1,0x46535153);
  }
  if (*(longlong *)(param_1 + 0x28) != 0) {
    IoFreeWorkItem();
  }
  SqospFreeUnicodeString((undefined4 *)(param_1 + 0x18));
  return;
}



===== SqospCleanupFlow @ 1c00110dc =====

void SqospCleanupFlow(longlong param_1,longlong param_2)

{
  if (*(longlong *)(param_1 + 0x10) != 0) {
    PcwCloseInstance();
  }
  SqospFreeUnicodeString((undefined4 *)(param_1 + 0x38));
  ExFreeToLookasideListEx(param_2 + 0x30,param_1);
  return;
}



===== SqospClientRemovalWorkItemRoutine @ 1c0011130 =====

void SqospClientRemovalWorkItemRoutine(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  SqospRemoveClient(param_3);
  return;
}



===== SqospCreateClient @ 1c0011148 =====

void * SqospCreateClient(void)

{
  longlong lVar1;
  void *_Dst;
  
  _Dst = (void *)ExAllocateFromLookasideListEx(&DAT_1c000d220);
  if (_Dst != (void *)0x0) {
    memset(_Dst,0,0x140);
    *(undefined4 *)((longlong)_Dst + 0xc) = 1;
    KeInitializeSpinLock(_Dst);
    lVar1 = (longlong)_Dst + 0x68;
    *(longlong *)((longlong)_Dst + 0x70) = lVar1;
    *(longlong *)lVar1 = lVar1;
    *(undefined4 *)((longlong)_Dst + 0x80) = 0;
    *(undefined4 *)((longlong)_Dst + 0x84) = 0;
    *(undefined8 *)((longlong)_Dst + 0xd0) = 0;
    *(undefined8 *)((longlong)_Dst + 200) = 0;
  }
  return _Dst;
}



===== SqospCreateDevice @ 1c00111c8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SqospCreateDevice(undefined8 param_1,undefined8 param_2,int param_3,undefined8 *param_4)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  uint *puVar5;
  ulonglong uVar6;
  void *pvVar7;
  longlong *plVar8;
  undefined8 *puVar9;
  ushort *puVar10;
  undefined8 *puVar11;
  ulonglong uVar12;
  undefined1 *puVar13;
  longlong lVar14;
  undefined8 *puVar15;
  undefined1 auStack_f8 [8];
  undefined1 auStack_f0 [24];
  undefined8 **local_d8;
  undefined8 local_d0;
  undefined4 local_c8;
  undefined2 local_c0;
  undefined8 *local_a8;
  longlong local_a0;
  ushort local_98 [4];
  longlong lStack_90;
  ushort local_88 [8];
  undefined8 *local_78;
  undefined4 local_70;
  undefined8 *local_68;
  undefined4 local_60;
  undefined8 *local_58;
  undefined4 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_f8;
  local_d8 = &local_a8;
  local_a8 = (undefined8 *)0x0;
  local_a0 = 0;
  local_88[0] = 0;
  local_88[1] = 0;
  local_88[2] = 0;
  local_88[3] = 0;
  local_88[4] = 0;
  local_88[5] = 0;
  local_88[6] = 0;
  local_88[7] = 0;
  local_98[0] = 0;
  local_98[1] = 0;
  local_98[2] = 0;
  local_98[3] = 0;
  lStack_90 = 0;
  uVar2 = FltAllocateContext(DAT_1c000d208,2,0x1140,0x200);
  puVar13 = auStack_f8;
  uVar12 = (ulonglong)uVar2;
  if ((int)uVar2 < 0) goto LAB_1c00116bf;
  memset(local_a8,0,0x1140);
  KeInitializeSpinLock(local_a8 + 0x18);
  local_a8[0x19] = param_1;
  *local_a8 = param_2;
  uVar4 = IoAllocateWorkItem(DAT_1c000d200);
  local_a8[5] = uVar4;
  if (local_a8[5] != 0) {
    local_c0 = 0;
    local_c8 = 0x46535153;
    local_d0 = 0x240;
    local_d8 = (undefined8 **)((ulonglong)local_d8 & 0xffffffff00000000);
    ExInitializeLookasideListEx(local_a8 + 6,0,0);
    iVar3 = KeQueryMaximumProcessorCountEx(0xffff);
    puVar5 = PplpCreateLookasideListEx(iVar3);
    local_a8[0x12] = puVar5;
    if (local_a8[0x12] != 0) {
      InitializeSListHead((PSLIST_HEADER)(local_a8 + 0x20));
      InitializeSListHead((PSLIST_HEADER)(local_a8 + 0x22));
      KeInitializeSpinLock(local_a8 + 0x68);
      KeInitializeSpinLock(local_a8 + 0x88);
      KeInitializeTimer(local_a8 + 0x25);
      KeInitializeDpc(local_a8 + 0x2d,SqosDeviceTimerRoutine);
      KeInitializeTimer(local_a8 + 0x209);
      KeInitializeDpc(local_a8 + 0x211,SqosVolumeStatsTimerRoutine);
      uVar2 = SqospInitializeDelayedJobQueue(param_1,(longlong)(local_a8 + 0x38));
      puVar13 = auStack_f8;
      uVar12 = (ulonglong)uVar2;
      if ((int)uVar2 < 0) goto LAB_1c00116bf;
      uVar2 = SqospInitializeDelayedJobQueue(param_1,(longlong)(local_a8 + 0x50));
      puVar13 = auStack_f8;
      uVar12 = (ulonglong)uVar2;
      if ((int)uVar2 < 0) goto LAB_1c00116bf;
      if ((param_3 == 0x1b) || (DAT_1c000d2aa != '\0')) {
        *(undefined4 *)((longlong)local_a8 + 0xbc) = 2;
      }
      else {
        *(undefined4 *)((longlong)local_a8 + 0xbc) = 1;
      }
      uVar6 = SqospQueryVolumeId(param_2,param_3 == 0x1b,local_a8 + 1);
      puVar13 = auStack_f8;
      uVar12 = uVar6 & 0xffffffff;
      if ((int)uVar6 == -0x3ffffdd3) {
        if (*(int *)((longlong)local_a8 + 0xbc) == 2) {
          *(undefined1 *)((longlong)local_a8 + 0x3a1) = 1;
        }
      }
      else if ((int)uVar6 < 0) goto LAB_1c00116bf;
      uVar2 = FltGetDiskDeviceObject(param_2,&local_a0);
      puVar13 = auStack_f8;
      uVar12 = (ulonglong)uVar2;
      if ((int)uVar2 < 0) goto LAB_1c00116bf;
      iVar3 = IoVolumeDeviceToDosName(local_a0,local_98);
      if (iVar3 < 0) {
        puVar10 = local_88;
        if (local_88[0] == 0) {
          puVar10 = (ushort *)&UNKNOWN_OBJECT_NAME;
        }
      }
      else {
        puVar10 = local_98;
      }
      uVar6 = SqospCopyUnicodeString((ushort *)(local_a8 + 3),puVar10);
      puVar13 = auStack_f8;
      uVar12 = uVar6 & 0xffffffff;
      if ((int)uVar6 < 0) goto LAB_1c00116bf;
      BalanceInitializeDevice((longlong)local_a8);
      pvVar7 = SqospCreateClient();
      local_a8[0x16] = pvVar7;
      if (local_a8[0x16] != 0) {
        *(undefined1 *)(local_a8[0x16] + 0x7c) = 1;
        plVar8 = SqospLookupFlow(local_a8[0x16],(longlong)local_a8,'\0',0);
        if (plVar8 != (longlong *)0x0) {
          if (DAT_1c000d2a8 != '\0') {
            local_78 = local_a8;
            local_60 = 0x18;
            local_50 = 0x18;
            local_68 = local_a8 + 0x1ff;
            local_58 = local_a8 + 0x202;
            local_70 = 0x1140;
            local_d8 = &local_78;
            PcwCreateInstance(local_a8 + 0x13,SqosPcDeviceCounterSet,local_a8 + 3,3);
          }
          FltAcquirePushLockExclusiveEx(&SqosGlobals,0);
          if ((DAT_1c000d218 != 0) && (*(int *)((longlong)local_a8 + 0xbc) == 2)) {
            SqospInitializeVolumeStatsReporting((longlong)local_a8);
          }
          puVar11 = local_a8;
          uVar4 = SqospIsNullGuid(local_a8 + 1);
          puVar13 = auStack_f8;
          puVar15 = &DAT_1c000d148;
          if ((char)uVar4 == '\0') {
            for (puVar9 = DAT_1c000d148; (undefined8 **)puVar9 != &DAT_1c000d148;
                puVar9 = (undefined8 *)*puVar9) {
              lVar14 = puVar11[1] - puVar9[-0x13];
              if (lVar14 == 0) {
                lVar14 = puVar11[2] - puVar9[-0x12];
              }
              if (lVar14 == 0) {
                *(undefined1 *)((longlong)puVar9 + 0x19) = 1;
                puVar11 = local_a8;
              }
            }
          }
          puVar11 = puVar11 + 0x14;
          if ((undefined8 **)*DAT_1c000d150 != &DAT_1c000d148) {
            pcVar1 = (code *)swi(0x29);
            DAT_1c000d150 = (undefined8 *)(*pcVar1)(3);
            puVar13 = auStack_f0;
          }
          *puVar11 = puVar15;
          puVar11[1] = DAT_1c000d150;
          *DAT_1c000d150 = puVar11;
          *(undefined8 *)(puVar13 + -8) = 0x1c0011655;
          DAT_1c000d150 = puVar11;
          FltReleasePushLockEx(&SqosGlobals,0);
          *(undefined8 *)(puVar13 + -8) = 0x1c001166f;
          uVar2 = FltSetInstanceContext(param_1,1,local_a8);
          uVar12 = (ulonglong)uVar2;
          if ((int)uVar2 < 0) {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              uVar4 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
              *(undefined8 *)(puVar13 + -8) = 0x1c00116b2;
              WPP_SF_d(uVar4,0xd,&WPP_af53c64ad8bd3a498290aca5a9ae070a_Traceguids,uVar2);
            }
          }
          else {
            *param_4 = local_a8;
            local_a8 = (undefined8 *)0x0;
          }
          goto LAB_1c00116bf;
        }
      }
    }
  }
  puVar13 = auStack_f8;
  uVar12 = 0xc000009a;
LAB_1c00116bf:
  if (lStack_90 != 0) {
    *(undefined8 *)(puVar13 + -8) = 0x1c00116d1;
    ExFreePoolWithTag(lStack_90,0);
  }
  *(undefined8 *)(puVar13 + -8) = 0x1c00116df;
  SqospFreeUnicodeString((undefined4 *)local_88);
  if (local_a0 != 0) {
    *(undefined8 *)(puVar13 + -8) = 0x1c00116ef;
    ObfDereferenceObject();
  }
  if (local_a8 != (undefined8 *)0x0) {
    *(undefined8 *)(puVar13 + -8) = 0x1c0011702;
    SqospRemoveDevice((longlong)local_a8);
    *(undefined8 *)(puVar13 + -8) = 0x1c001170d;
    FltReleaseContext(local_a8);
  }
  *(undefined8 *)(puVar13 + -8) = 0x1c0011720;
  return uVar12;
}



===== SqospDeviceUpdateVolumeId @ 1c001173c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 SqospDeviceUpdateVolumeId(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  ulonglong uVar2;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = 0;
  uStack_20 = 0;
  if (*(char *)((longlong)param_1 + 0x3a1) != '\0') {
    uVar2 = SqospQueryVolumeId(*param_1,'\0',&local_28);
    if ((int)uVar2 < 0) {
      return uVar2 & 0xffffffffffffff00;
    }
    FltAcquirePushLockExclusiveEx(&SqosGlobals,0);
    if (*(char *)((longlong)param_1 + 0x3a1) != '\0') {
      *(undefined1 *)((longlong)param_1 + 0x3a1) = 0;
      *(undefined4 *)(param_1 + 1) = (undefined4)local_28;
      *(undefined4 *)((longlong)param_1 + 0xc) = local_28._4_4_;
      *(undefined4 *)(param_1 + 2) = (undefined4)uStack_20;
      *(undefined4 *)((longlong)param_1 + 0x14) = uStack_20._4_4_;
    }
    local_18 = FltReleasePushLockEx(&SqosGlobals,0);
  }
  uVar1 = param_1[2];
  *param_2 = param_1[1];
  param_2[1] = uVar1;
  return CONCAT71((int7)(local_18 >> 8),1);
}



===== SqospLookupClient @ 1c00117f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 * SqospLookupClient(UCHAR *param_1,longlong param_2,longlong param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  NTSTATUS NVar8;
  undefined8 *puVar9;
  longlong *plVar10;
  undefined8 *puVar11;
  undefined8 *puVar12;
  undefined8 *puVar13;
  undefined8 *puVar14;
  undefined8 uVar15;
  undefined1 auStack_78 [32];
  longlong local_58;
  UCHAR local_48 [16];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_78;
  puVar9 = (undefined8 *)0x0;
  puVar13 = (undefined8 *)0x0;
  local_48[0] = '\0';
  local_48[1] = '\0';
  local_48[2] = '\0';
  local_48[3] = '\0';
  local_48[4] = '\0';
  local_48[5] = '\0';
  local_48[6] = '\0';
  local_48[7] = '\0';
  local_48[8] = '\0';
  local_48[9] = '\0';
  local_48[10] = '\0';
  local_48[0xb] = '\0';
  local_48[0xc] = '\0';
  local_48[0xd] = '\0';
  local_48[0xe] = '\0';
  local_48[0xf] = '\0';
  local_58 = param_3;
  if (param_1 == (UCHAR *)0x0) {
    NVar8 = BCryptGenRandom((BCRYPT_ALG_HANDLE)0x0,local_48,0x10,2);
    if (NVar8 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return (undefined8 *)0x0;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
        return (undefined8 *)0x0;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return (undefined8 *)0x0;
      }
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_af53c64ad8bd3a498290aca5a9ae070a_Traceguids,NVar8);
      return (undefined8 *)0x0;
    }
    param_1 = local_48;
  }
  else {
    FltAcquirePushLockSharedEx(&SqosGlobals,0);
    puVar11 = DAT_1c000d158;
    if (((DAT_1c000d160 & 1) != 0) && (DAT_1c000d158 != (undefined8 *)0x0)) {
      puVar11 = (undefined8 *)((ulonglong)DAT_1c000d158 ^ 0x1c000d158);
    }
    puVar14 = (undefined8 *)0x0;
    uVar1 = DAT_1c000d160 & 1;
    if (puVar11 != (undefined8 *)0x0) {
      do {
        iVar7 = SqosClientNodeComparisonRoutine(param_1,(longlong)puVar11);
        if (iVar7 < 0) {
LAB_1c0011895:
          puVar12 = (undefined8 *)*puVar11;
        }
        else {
          if (iVar7 < 1) {
            puVar14 = puVar11;
            goto LAB_1c0011895;
          }
          puVar12 = (undefined8 *)puVar11[1];
        }
        if ((uVar1 != 0) && (puVar12 != (undefined8 *)0x0)) {
          puVar12 = (undefined8 *)((ulonglong)puVar11 ^ (ulonglong)puVar12);
        }
        puVar11 = puVar12;
      } while (puVar12 != (undefined8 *)0x0);
      if (puVar14 != (undefined8 *)0x0) {
        puVar9 = puVar14 + -8;
        SqospAddRefClient((longlong)puVar9);
      }
    }
    FltReleasePushLockEx(&SqosGlobals,0);
    if (puVar9 != (undefined8 *)0x0) goto LAB_1c0011aac;
  }
  puVar9 = SqospCreateClient();
  if (puVar9 == (undefined8 *)0x0) {
    return (undefined8 *)0x0;
  }
  if (param_1 == (UCHAR *)0x0) {
    puVar13 = (undefined8 *)0x0;
    goto LAB_1c0011aac;
  }
  FltAcquirePushLockExclusiveEx(&SqosGlobals,0);
  puVar13 = DAT_1c000d158;
  if (((DAT_1c000d160 & 1) != 0) && (DAT_1c000d158 != (undefined8 *)0x0)) {
    puVar13 = (undefined8 *)((ulonglong)DAT_1c000d158 ^ 0x1c000d158);
  }
  puVar11 = (undefined8 *)0x0;
  uVar1 = DAT_1c000d160 & 1;
  if (puVar13 == (undefined8 *)0x0) {
LAB_1c00119f5:
    uVar3 = *(undefined4 *)param_1;
    uVar4 = *(undefined4 *)(param_1 + 4);
    uVar5 = *(undefined4 *)(param_1 + 8);
    uVar6 = *(undefined4 *)(param_1 + 0xc);
    *(undefined1 *)((longlong)puVar9 + 0x7d) = 1;
    *(undefined4 *)(puVar9 + 0xb) = uVar3;
    *(undefined4 *)((longlong)puVar9 + 0x5c) = uVar4;
    *(undefined4 *)(puVar9 + 0xc) = uVar5;
    *(undefined4 *)((longlong)puVar9 + 100) = uVar6;
    puVar13 = DAT_1c000d158;
    if (((DAT_1c000d160 & 1) != 0) && (DAT_1c000d158 != (undefined8 *)0x0)) {
      puVar13 = (undefined8 *)((ulonglong)DAT_1c000d158 ^ 0x1c000d158);
    }
    uVar15 = 0;
    uVar1 = DAT_1c000d160 & 1;
    uVar2 = DAT_1c000d160 & 1;
    if (puVar13 != (undefined8 *)0x0) {
      do {
        iVar7 = SqosClientNodeComparisonRoutine(puVar9 + 0xb,(longlong)puVar13);
        if (iVar7 < 0) {
          puVar11 = (undefined8 *)*puVar13;
          if (uVar2 == 0) {
LAB_1c0011a66:
            if (puVar11 != (undefined8 *)0x0) goto LAB_1c0011a6b;
          }
          else if (puVar11 != (undefined8 *)0x0) {
            puVar11 = (undefined8 *)((ulonglong)puVar11 ^ (ulonglong)puVar13);
            goto LAB_1c0011a66;
          }
          uVar15 = 0;
          break;
        }
        puVar11 = (undefined8 *)puVar13[1];
        if (uVar1 != 0) {
          if (puVar11 == (undefined8 *)0x0) goto LAB_1c0011a52;
          puVar11 = (undefined8 *)((ulonglong)puVar11 ^ (ulonglong)puVar13);
        }
        if (puVar11 == (undefined8 *)0x0) goto LAB_1c0011a52;
LAB_1c0011a6b:
        puVar13 = puVar11;
      } while( true );
    }
    goto LAB_1c0011a73;
  }
  do {
    iVar7 = SqosClientNodeComparisonRoutine(param_1,(longlong)puVar13);
    if (iVar7 < 0) {
LAB_1c00119c6:
      puVar14 = (undefined8 *)*puVar13;
    }
    else {
      if (iVar7 < 1) {
        puVar11 = puVar13;
        goto LAB_1c00119c6;
      }
      puVar14 = (undefined8 *)puVar13[1];
    }
    if ((uVar1 != 0) && (puVar14 != (undefined8 *)0x0)) {
      puVar14 = (undefined8 *)((ulonglong)puVar13 ^ (ulonglong)puVar14);
    }
    puVar13 = puVar14;
  } while (puVar14 != (undefined8 *)0x0);
  if (puVar11 == (undefined8 *)0x0) goto LAB_1c00119f5;
  SqospAddRefClient((longlong)(puVar11 + -8));
  puVar11 = puVar11 + -8;
  puVar13 = puVar9;
  goto LAB_1c0011a8f;
LAB_1c0011a52:
  uVar15 = 1;
LAB_1c0011a73:
  RtlRbInsertNodeEx(&DAT_1c000d158,puVar13,uVar15,puVar9 + 8);
  puVar13 = (undefined8 *)0x0;
  puVar11 = puVar9;
LAB_1c0011a8f:
  FltReleasePushLockEx(&SqosGlobals,0);
  puVar9 = puVar11;
LAB_1c0011aac:
  plVar10 = SqospLookupFlow((longlong)puVar9,param_2,'\0',local_58);
  if (plVar10 == (longlong *)0x0) {
    SqospReleaseClient((longlong)puVar9);
    puVar9 = (undefined8 *)0x0;
  }
  if (puVar13 != (undefined8 *)0x0) {
    SqospReleaseClient((longlong)puVar13);
  }
  return puVar9;
}



===== SqospQueryVolumeId @ 1c0011b0c =====

ulonglong SqospQueryVolumeId(undefined8 param_1,char param_2,undefined8 param_3)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  ulonglong uVar4;
  wchar_t *pwVar5;
  wchar_t *pwVar6;
  ulonglong uVar7;
  longlong lVar8;
  ulonglong local_28;
  wchar_t *pwStack_20;
  undefined8 local_18;
  wchar_t *pwStack_10;
  
  local_18 = 0;
  pwStack_10 = (wchar_t *)0x0;
  local_28 = 0;
  pwStack_20 = (wchar_t *)0x0;
  if ((DAT_1c000d2aa == '\0') || (param_2 == '\0')) {
    uVar4 = SqospAllocateUnicodeString((undefined2 *)&local_28,0x62);
    uVar7 = uVar4 & 0xffffffff;
    if ((int)uVar4 < 0) goto LAB_1c0011c50;
    iVar2 = FltGetVolumeGuidName(param_1,&local_28,0);
    if (-1 < iVar2) {
      pwStack_20[(local_28 >> 0x11 & 0x7fff) - 1] = L'\0';
      pwVar5 = wcschr(pwStack_20,L'{');
      if (pwVar5 == (wchar_t *)0x0) {
        uVar7 = 0xc000014f;
      }
      else {
        lVar8 = 0x7fff;
        pwVar6 = pwVar5;
        do {
          if (*pwVar6 == L'\0') {
            sVar1 = (0x7fff - (short)lVar8) * 2;
            local_18._0_4_ = CONCAT22(sVar1 + 2,sVar1);
            pwStack_10 = pwVar5;
            break;
          }
          pwVar6 = pwVar6 + 1;
          lVar8 = lVar8 + -1;
        } while (lVar8 != 0);
        uVar3 = RtlGUIDFromString(&local_18,param_3);
        if ((int)uVar3 < 0) {
          uVar3 = 0xc000014f;
        }
        uVar7 = (ulonglong)uVar3;
      }
      goto LAB_1c0011c50;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
               &WPP_af53c64ad8bd3a498290aca5a9ae070a_Traceguids,iVar2);
    }
  }
  uVar7 = 0xc000022d;
LAB_1c0011c50:
  SqospFreeUnicodeString((undefined4 *)&local_28);
  return uVar7;
}



===== SqospRemoveDevice @ 1c0011c7c =====

void SqospRemoveDevice(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  code *pcVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  bool bVar8;
  
  SqospTeardownVolumeStatsReporting(param_1);
  plVar1 = (longlong *)(param_1 + 0xa0);
  if ((*plVar1 != 0) || (*(longlong *)(param_1 + 0xa8) != 0)) {
    FltAcquirePushLockExclusiveEx(&SqosGlobals,0);
    lVar2 = *plVar1;
    if ((*(longlong **)(lVar2 + 8) != plVar1) ||
       (plVar3 = *(longlong **)(param_1 + 0xa8), (longlong *)*plVar3 != plVar1)) {
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      pcVar5 = (code *)swi(3);
      (*pcVar5)();
      return;
    }
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    *(longlong *)(param_1 + 0xa8) = 0;
    *(undefined8 *)(param_1 + 0xa0) = 0;
    FltReleasePushLockEx(&SqosGlobals,0);
  }
  FltAcquirePushLockSharedEx(&SqosGlobals,0);
  if (((ulonglong)DAT_1c000d160 & 1) == 0) {
    puVar7 = DAT_1c000d160;
  }
  else {
    if (DAT_1c000d160 == (undefined8 *)0x1) goto LAB_1c0011d97;
    puVar7 = (undefined8 *)((ulonglong)DAT_1c000d160 ^ 0x1c000d159);
  }
LAB_1c0011d92:
  if (puVar7 != (undefined8 *)0x0) {
    SqospRemoveFlow((longlong)(puVar7 + -8),param_1);
    puVar4 = (undefined8 *)puVar7[1];
    puVar6 = puVar7;
    if (puVar4 == (undefined8 *)0x0) {
      do {
        puVar7 = (undefined8 *)(puVar6[2] & 0xfffffffffffffffc);
        if (puVar7 == (undefined8 *)0x0) break;
        bVar8 = (undefined8 *)*puVar7 != puVar6;
        puVar6 = puVar7;
      } while (bVar8);
    }
    else {
      for (puVar6 = (undefined8 *)*puVar4; puVar7 = puVar4, puVar6 != (undefined8 *)0x0;
          puVar6 = (undefined8 *)*puVar6) {
        puVar4 = puVar6;
      }
    }
    goto LAB_1c0011d92;
  }
LAB_1c0011d97:
  FltReleasePushLockEx(&SqosGlobals,0);
  if (*(longlong *)(param_1 + 0xb0) != 0) {
    SqospRemoveFlow(*(longlong *)(param_1 + 0xb0),param_1);
    SqospReleaseClient(*(longlong *)(param_1 + 0xb0));
    *(undefined8 *)(param_1 + 0xb0) = 0;
  }
  return;
}



===== SqosJobDispatcherThreadRoutine @ 1c0011e00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SqosJobDispatcherThreadRoutine(longlong param_1)

{
  char cVar1;
  longlong lVar2;
  
  KeSetActualBasePriorityThread(SystemReserved1[0xf],0xc);
  while( true ) {
    lVar2 = KeRemoveQueue(param_1 + 8,0,0);
    if (lVar2 == 0x80) break;
    cVar1 = ExTryQueueWorkItem(lVar2);
    if (cVar1 == '\0') {
      (**(code **)(lVar2 + 0x10))(lVar2);
    }
  }
  return;
}



===== SqospRundownJobDispatcher @ 1c0011e80 =====

void SqospRundownJobDispatcher(longlong *param_1)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  
  if (param_1[10] != 0) {
    uVar1 = KeQueryMaximumProcessorCountEx(0xffff);
    if (uVar1 != 0) {
      lVar3 = 0;
      uVar2 = (ulonglong)uVar1;
      do {
        DvRundownWorkQueue((ulonglong *)(param_1[10] + lVar3));
        lVar3 = lVar3 + 0x40;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    ExFreePoolWithTag(param_1[10],0x46535153);
  }
  if ((char)param_1[9] != '\0') {
    KeRundownQueue(param_1 + 1);
    if (*param_1 != 0) {
      KeWaitForSingleObject(*param_1,0,0,0,0);
      ObfDereferenceObject(*param_1);
    }
  }
  return;
}



===== SqospHandleVolumeStatsRequest @ 1c0011f3c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SqospHandleVolumeStatsRequest
                    (longlong param_1,uint param_2,undefined8 param_3,uint param_4,uint *param_5)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined2 *puVar3;
  ulonglong uVar4;
  undefined1 auStack_88 [32];
  ulonglong local_68;
  undefined4 local_60;
  char local_58;
  undefined8 *local_50;
  longlong local_48;
  longlong local_40;
  undefined8 uStack_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_88;
  puVar1 = (undefined8 *)0x0;
  local_50 = (undefined8 *)0x0;
  lVar2 = 0;
  local_58 = '\0';
  if (param_2 < 0x220) {
    uVar4 = 0xc000000d;
  }
  else {
    local_40 = *(longlong *)(param_1 + 0x210);
    uStack_38 = *(undefined8 *)(param_1 + 0x218);
    puVar1 = SqospFindDeviceByVolumeId(&local_40);
    local_50 = puVar1;
    if (puVar1 == (undefined8 *)0x0) {
      uVar4 = 0xc0000225;
    }
    else {
      local_68 = 0;
      lVar2 = IoAllocateMdl(param_3,param_4,0,0);
      local_48 = lVar2;
      if (lVar2 != 0) {
        MmProbeAndLockPages(lVar2,0,1);
        local_58 = '\x01';
        if ((*(byte *)(lVar2 + 10) & 5) == 0) {
          local_60 = 0x40000010;
          local_68 = local_68 & 0xffffffff00000000;
          puVar3 = (undefined2 *)MmMapLockedPagesSpecifyCache(lVar2,0,1,0);
        }
        else {
          puVar3 = *(undefined2 **)(lVar2 + 0x18);
        }
        if (puVar3 != (undefined2 *)0x0) {
          uVar4 = SqospWriteVolumeStats((longlong)puVar1,puVar3,param_4,param_5);
          uVar4 = uVar4 & 0xffffffff;
          goto LAB_1c0012064;
        }
      }
      uVar4 = 0xc000009a;
    }
  }
LAB_1c0012064:
  if (lVar2 != 0) {
    if (local_58 != '\0') {
      MmUnlockPages(lVar2);
    }
    IoFreeMdl(lVar2);
  }
  if (puVar1 != (undefined8 *)0x0) {
    FltReleaseContext(puVar1);
  }
  return uVar4;
}



===== SqospHandleVolumeThroughputAllocation @ 1c00120c4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SqospHandleVolumeThroughputAllocation(undefined8 *param_1,uint param_2)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  longlong lVar6;
  undefined8 *puVar7;
  uint uVar8;
  longlong lVar9;
  ulonglong uVar10;
  undefined1 auStack_2d8 [32];
  ulonglong local_2b8;
  undefined4 local_2b0;
  char local_2a8;
  undefined8 *local_2a0;
  longlong local_298;
  undefined8 local_288;
  longlong local_78 [8];
  uint local_38;
  uint local_34;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_2d8;
  local_288._2_2_ = 0;
  memset(&local_288,0,0x256);
  puVar5 = (undefined8 *)0x0;
  local_2a0 = (undefined8 *)0x0;
  lVar6 = 0;
  local_2a8 = '\0';
  if (599 < param_2) {
    lVar9 = 4;
    puVar2 = param_1;
    puVar3 = &local_288;
    do {
      puVar7 = puVar3;
      puVar4 = puVar2;
      uVar1 = puVar4[1];
      *puVar7 = *puVar4;
      puVar7[1] = uVar1;
      uVar1 = puVar4[3];
      puVar7[2] = puVar4[2];
      puVar7[3] = uVar1;
      uVar1 = puVar4[5];
      puVar7[4] = puVar4[4];
      puVar7[5] = uVar1;
      uVar1 = puVar4[7];
      puVar7[6] = puVar4[6];
      puVar7[7] = uVar1;
      uVar1 = puVar4[9];
      puVar7[8] = puVar4[8];
      puVar7[9] = uVar1;
      uVar1 = puVar4[0xb];
      puVar7[10] = puVar4[10];
      puVar7[0xb] = uVar1;
      uVar1 = puVar4[0xd];
      puVar7[0xc] = puVar4[0xc];
      puVar7[0xd] = uVar1;
      uVar1 = puVar4[0xf];
      puVar7[0xe] = puVar4[0xe];
      puVar7[0xf] = uVar1;
      lVar9 = lVar9 + -1;
      puVar2 = puVar4 + 0x10;
      puVar3 = puVar7 + 0x10;
    } while (lVar9 != 0);
    uVar1 = puVar4[0x11];
    puVar7[0x10] = puVar4[0x10];
    puVar7[0x11] = uVar1;
    uVar1 = puVar4[0x13];
    puVar7[0x12] = puVar4[0x12];
    puVar7[0x13] = uVar1;
    uVar1 = puVar4[0x15];
    puVar7[0x14] = puVar4[0x14];
    puVar7[0x15] = uVar1;
    uVar1 = puVar4[0x17];
    puVar7[0x16] = puVar4[0x16];
    puVar7[0x17] = uVar1;
    uVar1 = puVar4[0x19];
    puVar7[0x18] = puVar4[0x18];
    puVar7[0x19] = uVar1;
    puVar7[0x1a] = puVar4[0x1a];
    if ((ulonglong)local_34 * 0x48 < 0x100000000) {
      uVar8 = local_38 + (int)((ulonglong)local_34 * 0x48);
      if ((local_38 <= uVar8) && (uVar8 <= param_2)) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0 &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])))) {
          WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)uVar8,0x80,local_78);
        }
        puVar5 = SqospFindDeviceByVolumeId(local_78);
        local_2a0 = puVar5;
        if (puVar5 == (undefined8 *)0x0) {
          uVar10 = 0xc0000225;
        }
        else {
          local_2b8 = 0;
          lVar6 = IoAllocateMdl(param_1,param_2);
          local_298 = lVar6;
          if (lVar6 != 0) {
            uVar10 = 0;
            MmProbeAndLockPages(lVar6,0);
            local_2a8 = '\x01';
            if ((*(byte *)(lVar6 + 10) & 5) == 0) {
              local_2b0 = 0x40000010;
              local_2b8 = local_2b8 & 0xffffffff00000000;
              uVar10 = 1;
              lVar9 = MmMapLockedPagesSpecifyCache(lVar6,0);
            }
            else {
              lVar9 = *(longlong *)(lVar6 + 0x18);
            }
            if (lVar9 != 0) {
              uVar10 = SqospAssignFlowIoRates((longlong)puVar5,lVar9,uVar10);
              uVar10 = uVar10 & 0xffffffff;
              goto LAB_1c00122e0;
            }
          }
          uVar10 = 0xc000009a;
        }
        goto LAB_1c00122e0;
      }
    }
  }
  uVar10 = 0xc000000d;
LAB_1c00122e0:
  if (lVar6 != 0) {
    if (local_2a8 != '\0') {
      MmUnlockPages(lVar6);
    }
    IoFreeMdl(lVar6);
  }
  if (puVar5 != (undefined8 *)0x0) {
    FltReleaseContext(puVar5);
  }
  return uVar10;
}



===== SqospQueueVolumeNotification @ 1c001234c =====

void SqospQueueVolumeNotification(longlong param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined8 *puVar6;
  longlong lVar7;
  undefined8 *puVar8;
  undefined1 *puVar9;
  undefined8 local_res10 [3];
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined8 local_28;
  undefined8 local_20;
  undefined8 *local_18;
  
  local_res10[0] = 0;
  local_18 = local_res10;
  local_20 = 0;
  local_28 = 0;
  iVar5 = FltSendMessage(DAT_1c000d208,&DAT_1c000d218,param_1,0x3f8);
  if (iVar5 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
               &WPP_484a7e20184230f2fd6f3fbff0f89920_Traceguids,iVar5);
    }
  }
  else if (iVar5 == 0x102) {
    puVar6 = (undefined8 *)SqospAllocate(0x28);
    if (puVar6 != (undefined8 *)0x0) {
      uVar2 = *(undefined4 *)(param_1 + 0x218);
      uVar3 = *(undefined4 *)(param_1 + 0x21c);
      uVar4 = *(undefined4 *)(param_1 + 0x220);
      *(undefined4 *)(puVar6 + 2) = *(undefined4 *)(param_1 + 0x214);
      *(undefined4 *)((longlong)puVar6 + 0x14) = uVar2;
      *(undefined4 *)(puVar6 + 3) = uVar3;
      *(undefined4 *)((longlong)puVar6 + 0x1c) = uVar4;
      puVar6[4] = *(undefined8 *)(param_1 + 0x224);
      FltAcquirePushLockExclusiveEx(&SqosGlobals,0);
      puVar9 = auStack_48;
      puVar8 = &DAT_1c000d168;
      if ((undefined8 *)*DAT_1c000d170 != &DAT_1c000d168) {
        puVar8 = (undefined8 *)0x3;
        pcVar1 = (code *)swi(0x29);
        DAT_1c000d170 = (undefined8 *)(*pcVar1)();
        puVar9 = auStack_40;
      }
      *puVar6 = puVar8;
      puVar6[1] = DAT_1c000d170;
      *DAT_1c000d170 = puVar6;
      DAT_1c000d170 = puVar6;
      if (DAT_1c000d178 == '\0') {
        *(undefined8 *)(puVar9 + -8) = 0x1c001246c;
        lVar7 = FltAllocateGenericWorkItem();
        if (lVar7 != 0) {
          *(undefined8 *)(puVar9 + 0x20) = 0;
          *(undefined8 *)(puVar9 + -8) = 0x1c001249d;
          iVar5 = FltQueueGenericWorkItem(lVar7,DAT_1c000d208,SqospVolumeNotificationWorkItem,1);
          if (iVar5 < 0) {
            *(undefined8 *)(puVar9 + -8) = 0x1c00124b9;
            FltFreeGenericWorkItem(lVar7);
          }
          else {
            DAT_1c000d178 = '\x01';
          }
        }
      }
      *(undefined8 *)(puVar9 + -8) = 0x1c00124ce;
      FltReleasePushLockEx(&SqosGlobals,0);
    }
  }
  return;
}



===== SqospQueueVolumeStatsNotification @ 1c00124e8 =====

void SqospQueueVolumeStatsNotification(undefined8 *param_1)

{
  undefined2 *puVar1;
  undefined8 uVar2;
  undefined8 local_18;
  undefined8 uStack_10;
  
  puVar1 = (undefined2 *)SqospAllocate(0x3f8);
  if (puVar1 != (undefined2 *)0x0) {
    if (DAT_1c000d218 != 0) {
      local_18 = 0;
      uStack_10 = 0;
      uVar2 = SqospDeviceUpdateVolumeId(param_1,&local_18);
      if ((char)uVar2 != '\0') {
        *puVar1 = 0x101;
        *(undefined4 *)(puVar1 + 2) = 1;
        *(undefined4 *)(puVar1 + 0x108) = 1;
        *(undefined4 *)(puVar1 + 0x112) = 1;
        *(undefined8 *)(puVar1 + 0x10a) = local_18;
        *(undefined8 *)(puVar1 + 0x10e) = uStack_10;
        *(undefined4 *)(puVar1 + 0x114) = *(undefined4 *)((longlong)param_1 + 0x10dc);
        SqospQueueVolumeNotification((longlong)puVar1);
      }
    }
    SqospFree(puVar1);
  }
  return;
}



===== SqospVolumeNotificationWorkItem @ 1c0012580 =====

void SqospVolumeNotificationWorkItem(undefined8 param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  code *pcVar3;
  undefined8 *puVar4;
  int iVar5;
  undefined2 *puVar6;
  undefined1 *puVar7;
  char cVar8;
  uint uVar9;
  ulonglong uVar10;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [56];
  
  puVar6 = (undefined2 *)SqospAllocate(0x3f8);
  puVar7 = auStack_58;
  if (puVar6 != (undefined2 *)0x0) {
    FltAcquirePushLockExclusiveEx(&SqosGlobals,0);
    uVar10 = 0;
    while( true ) {
      puVar4 = DAT_1c000d168;
      uVar9 = (uint)uVar10;
      puVar7 = auStack_58;
      if (((undefined8 **)DAT_1c000d168 == &DAT_1c000d168) || (puVar7 = auStack_58, 0x13 < uVar9))
      goto LAB_1c0012632;
      if (((undefined8 **)DAT_1c000d168[1] != &DAT_1c000d168) ||
         (puVar1 = (undefined8 *)*DAT_1c000d168, (undefined8 *)puVar1[1] != DAT_1c000d168)) break;
      DAT_1c000d168 = puVar1;
      puVar1[1] = &DAT_1c000d168;
      uVar2 = puVar4[3];
      *(undefined8 *)(puVar6 + uVar10 * 0xc + 0x10a) = puVar4[2];
      *(undefined8 *)((longlong)(puVar6 + uVar10 * 0xc + 0x10a) + 8) = uVar2;
      *(undefined8 *)(puVar6 + uVar10 * 0xc + 0x112) = puVar4[4];
      SqospFree(puVar4);
      uVar10 = (ulonglong)(uVar9 + 1);
    }
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(3);
    puVar7 = auStack_50;
LAB_1c0012632:
    if (uVar9 == 0) {
      DAT_1c000d178 = '\0';
    }
    *(undefined8 *)(puVar7 + -8) = 0x1c001264d;
    FltReleasePushLockEx(&SqosGlobals,0);
    if (uVar9 != 0) {
      *(undefined4 *)(puVar6 + 2) = 1;
      *(undefined1 **)(puVar7 + 0x30) = puVar7 + 0x78;
      *(undefined8 *)(puVar7 + 0x28) = 0;
      *(undefined8 *)(puVar7 + 0x20) = 0;
      *puVar6 = 0x101;
      *(uint *)(puVar6 + 0x108) = uVar9;
      *(undefined8 *)(puVar7 + 0x78) = 0xffffffffffd9da60;
      *(undefined8 *)(puVar7 + -8) = 0x1c00126a9;
      iVar5 = FltSendMessage(DAT_1c000d208,&DAT_1c000d218,puVar6,0x3f8);
      if (iVar5 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar2 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
          *(undefined8 *)(puVar7 + -8) = 0x1c00126ed;
          WPP_SF_d(uVar2,0xf,&WPP_484a7e20184230f2fd6f3fbff0f89920_Traceguids,iVar5);
        }
      }
      else if ((((iVar5 == 0x102) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
              (2 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar2 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
        *(undefined8 *)(puVar7 + -8) = 0x1c001272c;
        WPP_SF_(uVar2,0x10,&WPP_484a7e20184230f2fd6f3fbff0f89920_Traceguids);
      }
      *(undefined8 *)(puVar7 + -8) = 0x1c001273c;
      FltAcquirePushLockExclusiveEx(&SqosGlobals,0);
      cVar8 = '\0';
      if ((-1 < iVar5) && ((undefined8 **)DAT_1c000d168 != &DAT_1c000d168)) {
        *(undefined8 *)(puVar7 + 0x20) = 0;
        *(undefined8 *)(puVar7 + -8) = 0x1c0012774;
        iVar5 = FltQueueGenericWorkItem(param_1,DAT_1c000d208,SqospVolumeNotificationWorkItem,1);
        cVar8 = '\0';
        if (-1 < iVar5) {
          cVar8 = '\x01';
        }
      }
      *(undefined8 *)(puVar7 + -8) = 0x1c0012799;
      DAT_1c000d178 = cVar8;
      FltReleasePushLockEx(&SqosGlobals,0);
      if (cVar8 != '\0') goto LAB_1c00127b7;
    }
  }
  *(undefined8 *)(puVar7 + -8) = 0x1c00127ad;
  FltFreeGenericWorkItem(param_1);
  if (puVar6 == (undefined2 *)0x0) {
    return;
  }
LAB_1c00127b7:
  *(undefined8 *)(puVar7 + -8) = 0x1c00127bf;
  SqospFree(puVar6);
  return;
}



===== SqosConnectNotifyCallback @ 1c00127e0 =====

undefined8
SqosConnectNotifyCallback
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
          undefined8 *param_5)

{
  undefined8 *puVar1;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x40,param_3,param_1);
  }
  DAT_1c000d218 = param_1;
  *param_5 = param_1;
  FltAcquirePushLockSharedEx(&SqosGlobals,0);
  for (puVar1 = DAT_1c000d148; (undefined8 **)puVar1 != &DAT_1c000d148;
      puVar1 = (undefined8 *)*puVar1) {
    if ((*(char *)((longlong)puVar1 + 0x19) == '\0') && (*(int *)((longlong)puVar1 + 0x1c) == 2)) {
      SqospInitializeVolumeStatsReporting((longlong)(puVar1 + -0x14));
    }
  }
  FltReleasePushLockEx(&SqosGlobals,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x41,
             &WPP_97d16c38264433ff5e04fa48b3a3652b_Traceguids,0);
  }
  return 0;
}



===== SqosDisconnectNotifyCallback @ 1c00128e0 =====

void SqosDisconnectNotifyCallback(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x42,param_3,param_1);
  }
  FltCloseClientPort(DAT_1c000d208,&DAT_1c000d218);
  return;
}



===== SqosFilterUnload @ 1c0012940 =====

undefined8 SqosFilterUnload(undefined4 param_1,undefined8 param_2,undefined8 param_3)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,param_3,param_1);
  }
  SqosFilterUnloadInternal();
  return 0;
}



===== SqosFilterUnloadInternal @ 1c0012988 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SqosFilterUnloadInternal(void)

{
  undefined8 *puVar1;
  code *pcVar2;
  undefined8 *puVar3;
  undefined *puVar4;
  undefined1 *puVar5;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  if (DAT_1c000d210 != 0) {
    FltCloseCommunicationPort();
  }
  if (DAT_1c000d208 != 0) {
    FltUnregisterFilter();
  }
  SqospRundownJobDispatcher((longlong *)&DAT_1c000d180);
  if (DAT_1c000d2a9 != '\0') {
    PcwUnregister(SqosPcFlowCounterSet);
  }
  if (DAT_1c000d2a8 != '\0') {
    PcwUnregister(SqosPcDeviceCounterSet);
  }
  if (DAT_1c000d288 != 0) {
    SqospFree(DAT_1c000d288);
  }
  if (DAT_1c000d280 != 0) {
    FltFreeGenericWorkItem();
  }
  puVar5 = auStack_28;
  do {
    puVar3 = DAT_1c000d168;
    if ((undefined8 **)DAT_1c000d168 == &DAT_1c000d168) {
LAB_1c0012a6a:
      *(undefined8 *)(puVar5 + -8) = 0x1c0012a78;
      ExDeleteLookasideListEx(&DAT_1c000d220);
      *(undefined8 *)(puVar5 + -8) = 0x1c0012a82;
      wil_UninitializeFeatureStaging();
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        puVar4 = WPP_GLOBAL_Control;
        if (WPPTraceSuite == 4) {
          for (; puVar4 != (undefined *)0x0; puVar4 = *(undefined **)(puVar4 + 0x10)) {
            if (*(longlong *)(puVar4 + 0x38) != 0) {
              *(undefined8 *)(puVar5 + -8) = 0x1c0012ae1;
              (*pfnEtwUnregister)();
              *(undefined8 *)(puVar4 + 0x38) = 0;
            }
          }
        }
        else if (WPPTraceSuite == 2) {
          *(undefined8 *)(puVar5 + -8) = 0x1c0012ab4;
          IoWMIRegistrationControl(WPP_GLOBAL_Control,0x80000002);
        }
        WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
      }
      return;
    }
    if (((undefined8 **)DAT_1c000d168[1] != &DAT_1c000d168) ||
       (puVar1 = (undefined8 *)*DAT_1c000d168, (undefined8 *)puVar1[1] != DAT_1c000d168)) {
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(3);
      puVar5 = auStack_20;
      goto LAB_1c0012a6a;
    }
    DAT_1c000d168 = puVar1;
    puVar1[1] = &DAT_1c000d168;
    SqospFree(puVar3);
  } while( true );
}



===== SqosInstanceContextCleanup @ 1c0012b00 =====

void SqosInstanceContextCleanup(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3e,param_3,param_1);
  }
  SqospCleanupDevice(param_1);
  return;
}



===== SqosInstanceQueryTeardown @ 1c0012b50 =====

undefined4 SqosInstanceQueryTeardown(longlong param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  longlong local_res8;
  
  local_res8 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,(ulonglong)param_2,
              *(undefined8 *)(param_1 + 0x10),(char)param_2);
  }
  iVar2 = FltGetInstanceContext(*(undefined8 *)(param_1 + 0x18),&local_res8);
  if ((-1 < iVar2) && (DAT_1c000d2aa == '\0')) {
    bVar1 = SqospStartDeviceTeardown(local_res8);
    if (!bVar1) {
      uVar3 = 0xc01c0010;
      goto LAB_1c0012bd6;
    }
  }
  uVar3 = 0;
LAB_1c0012bd6:
  if (local_res8 != 0) {
    FltReleaseContext();
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
             &WPP_97d16c38264433ff5e04fa48b3a3652b_Traceguids,uVar3);
  }
  return uVar3;
}



===== SqosInstanceTeardownComplete @ 1c0012c40 =====

void SqosInstanceTeardownComplete(longlong param_1,uint param_2)

{
  int iVar1;
  longlong local_res8;
  
  local_res8 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,(ulonglong)param_2,
              *(undefined8 *)(param_1 + 0x10),(char)param_2);
  }
  iVar1 = FltGetInstanceContext(*(undefined8 *)(param_1 + 0x18),&local_res8);
  if (-1 < iVar1) {
    SqospRemoveDevice(local_res8);
    FltReleaseContext(local_res8);
  }
  FltDeleteInstanceContext(*(undefined8 *)(param_1 + 0x18),0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
             &WPP_97d16c38264433ff5e04fa48b3a3652b_Traceguids,0);
  }
  return;
}



===== SqosMessageNotifyCallback @ 1c0012d20 =====

ulonglong SqosMessageNotifyCallback
                    (undefined8 param_1,undefined8 *param_2,ulonglong param_3,longlong param_4,
                    uint param_5,uint *param_6)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  ushort *puVar3;
  undefined8 *puVar4;
  ushort *puVar5;
  undefined2 uVar6;
  longlong lVar7;
  ulonglong uVar8;
  uint uVar9;
  ushort local_218 [2];
  uint uStack_214;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x43,param_3,param_1);
  }
  if ((param_2 != (undefined8 *)0x0) && (uVar9 = (uint)param_3, 0x20f < uVar9)) {
    ProbeForRead(param_2,param_3 & 0xffffffff,8);
    if (param_4 != 0) {
      ProbeForWrite(param_4,param_5,8);
    }
    lVar7 = 4;
    puVar2 = param_2;
    puVar3 = local_218;
    do {
      puVar5 = puVar3;
      puVar4 = puVar2;
      uVar1 = puVar4[1];
      *(undefined8 *)puVar5 = *puVar4;
      *(undefined8 *)(puVar5 + 4) = uVar1;
      uVar1 = puVar4[3];
      *(undefined8 *)(puVar5 + 8) = puVar4[2];
      *(undefined8 *)(puVar5 + 0xc) = uVar1;
      uVar1 = puVar4[5];
      *(undefined8 *)(puVar5 + 0x10) = puVar4[4];
      *(undefined8 *)(puVar5 + 0x14) = uVar1;
      uVar1 = puVar4[7];
      *(undefined8 *)(puVar5 + 0x18) = puVar4[6];
      *(undefined8 *)(puVar5 + 0x1c) = uVar1;
      uVar1 = puVar4[9];
      *(undefined8 *)(puVar5 + 0x20) = puVar4[8];
      *(undefined8 *)(puVar5 + 0x24) = uVar1;
      uVar1 = puVar4[0xb];
      *(undefined8 *)(puVar5 + 0x28) = puVar4[10];
      *(undefined8 *)(puVar5 + 0x2c) = uVar1;
      uVar1 = puVar4[0xd];
      *(undefined8 *)(puVar5 + 0x30) = puVar4[0xc];
      *(undefined8 *)(puVar5 + 0x34) = uVar1;
      uVar1 = puVar4[0xf];
      *(undefined8 *)(puVar5 + 0x38) = puVar4[0xe];
      *(undefined8 *)(puVar5 + 0x3c) = uVar1;
      lVar7 = lVar7 + -1;
      puVar2 = puVar4 + 0x10;
      puVar3 = puVar5 + 0x40;
    } while (lVar7 != 0);
    uVar1 = puVar4[0x11];
    *(undefined8 *)(puVar5 + 0x40) = puVar4[0x10];
    *(undefined8 *)(puVar5 + 0x44) = uVar1;
    if (local_218[0] == 0x101) {
      if (uStack_214 == 2) {
        uVar8 = SqospHandleVolumeStatsRequest((longlong)param_2,uVar9,param_4,param_5,param_6);
        uVar8 = uVar8 & 0xffffffff;
        goto LAB_1c0012ee8;
      }
      if (uStack_214 == 4) {
        uVar8 = SqospHandleVolumeThroughputAllocation(param_2,uVar9);
        uVar8 = uVar8 & 0xffffffff;
        *param_6 = 0;
        goto LAB_1c0012ee8;
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar6 = 0x45;
        goto LAB_1c0012e5d;
      }
    }
    else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uStack_214 = (uint)local_218[0];
      uVar6 = 0x44;
LAB_1c0012e5d:
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,0x80,uStack_214);
    }
  }
  uVar8 = 0xc000000d;
LAB_1c0012ee8:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x46,
             &WPP_97d16c38264433ff5e04fa48b3a3652b_Traceguids,(int)uVar8);
  }
  return uVar8;
}



===== SqospCreateQoSControlSecurityDescriptor @ 1c0012f3c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SqospCreateQoSControlSecurityDescriptor
              (undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  undefined4 *puVar6;
  uint *puVar7;
  void *_Dst;
  undefined2 uVar8;
  undefined8 uVar9;
  uint *puVar10;
  undefined1 auStack_78 [32];
  uint local_58 [2];
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined4 local_28;
  undefined2 local_24;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_78;
  local_24 = 0x500;
  local_58[0] = 0;
  local_30 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_28 = 0;
  local_40 = 0;
  uStack_38 = 0;
  _Dst = (void *)0x0;
  uVar1 = RtlLengthRequiredSid(2);
  lVar5 = SqospAllocate((ulonglong)uVar1);
  if (lVar5 == 0) {
    return -0x3fffff66;
  }
  uVar9 = CONCAT71((int7)((ulonglong)param_3 >> 8),2);
  iVar2 = RtlInitializeSid(lVar5,&local_28);
  if (iVar2 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,uVar9,iVar2);
    }
    goto LAB_1c0013472;
  }
  puVar6 = (undefined4 *)RtlSubAuthoritySid(lVar5,0);
  *puVar6 = 0x53;
  puVar6 = (undefined4 *)RtlSubAuthoritySid(lVar5,1);
  *puVar6 = 0;
  iVar2 = RtlLengthSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0x108));
  iVar3 = RtlLengthSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0x110));
  iVar4 = RtlLengthSid(lVar5);
  uVar1 = iVar2 + iVar3 + iVar4 + 0x20;
  puVar7 = (uint *)SqospAllocate((ulonglong)uVar1);
  if (puVar7 == (uint *)0x0) {
    iVar2 = -0x3fffff66;
    goto LAB_1c0013472;
  }
  puVar10 = (uint *)0x2;
  iVar2 = RtlCreateAcl(puVar7,uVar1);
  if (iVar2 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      uVar8 = 0x30;
LAB_1c00130f6:
LAB_1c00130f9:
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,puVar10,iVar2);
    }
  }
  else {
    puVar10 = (uint *)0x1f01ff;
    iVar2 = RtlAddAccessAllowedAce
                      (puVar7,2,0x1f01ff,*(undefined8 *)(*(longlong *)SeExports_exref + 0x108));
    if (iVar2 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar8 = 0x31;
        goto LAB_1c00130f6;
      }
    }
    else {
      puVar10 = (uint *)0x1f01ff;
      iVar2 = RtlAddAccessAllowedAce
                        (puVar7,2,0x1f01ff,*(undefined8 *)(*(longlong *)SeExports_exref + 0x110));
      if (iVar2 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar8 = 0x32;
          goto LAB_1c00130f6;
        }
      }
      else {
        puVar10 = (uint *)0x1f01ff;
        iVar2 = RtlAddAccessAllowedAce(puVar7,2,0x1f01ff,lVar5);
        if (iVar2 < 0) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar8 = 0x33;
            goto LAB_1c00130f6;
          }
        }
        else {
          iVar2 = RtlCreateSecurityDescriptor(&local_50,1);
          if (iVar2 < 0) {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              uVar8 = 0x34;
              goto LAB_1c00130f6;
            }
          }
          else {
            puVar10 = puVar7;
            iVar2 = RtlSetDaclSecurityDescriptor(&local_50,1,puVar7,0);
            if (iVar2 < 0) {
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                uVar8 = 0x35;
                goto LAB_1c00130f6;
              }
            }
            else {
              puVar10 = (uint *)0x0;
              iVar2 = RtlSetOwnerSecurityDescriptor
                                (&local_50,*(undefined8 *)(*(longlong *)SeExports_exref + 0x108));
              if (iVar2 < 0) {
                if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                   (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                  uVar8 = 0x36;
                  goto LAB_1c00130f6;
                }
              }
              else {
                puVar10 = (uint *)0x0;
                iVar2 = RtlSetGroupSecurityDescriptor(&local_50);
                if (iVar2 < 0) {
                  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                    uVar8 = 0x37;
                    goto LAB_1c00130f6;
                  }
                }
                else {
                  local_58[0] = RtlLengthSecurityDescriptor(&local_50);
                  if (local_58[0] < 0x28) {
                    iVar2 = -0x3fffff1b;
                    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                      uVar8 = 0x38;
                      iVar2 = -0x3fffff1b;
                      goto LAB_1c00130f9;
                    }
                  }
                  else {
                    _Dst = (void *)SqospAllocate((ulonglong)local_58[0]);
                    if (_Dst == (void *)0x0) {
                      iVar2 = -0x3fffff66;
                    }
                    else {
                      memset(_Dst,0,(ulonglong)local_58[0]);
                      puVar10 = local_58;
                      iVar2 = RtlAbsoluteToSelfRelativeSD(&local_50,_Dst);
                      if (iVar2 < 0) {
                        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                          uVar8 = 0x39;
                          goto LAB_1c00130f6;
                        }
                      }
                      else {
                        *param_1 = _Dst;
                        _Dst = (void *)0x0;
                        iVar2 = 0;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  SqospFree(puVar7);
  if (_Dst != (void *)0x0) {
    SqospFree(_Dst);
  }
LAB_1c0013472:
  SqospFree(lVar5);
  return iVar2;
}



===== SqospIsCsvHiddenVolume @ 1c00134ac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SqospIsCsvHiddenVolume(undefined8 param_1,undefined1 *param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined1 auStack_c8 [32];
  longlong local_78 [4];
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_c8;
  local_78[0] = 0;
  local_78[3] = 0;
  local_78[1] = 0;
  local_78[2] = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  KeInitializeEvent(local_78 + 1,0);
  iVar1 = FltGetDiskDeviceObject(param_1,local_78);
  if (iVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x47,
               &WPP_97d16c38264433ff5e04fa48b3a3652b_Traceguids,iVar1);
    }
  }
  else {
    lVar2 = IoGetAttachedDeviceReference(local_78[0]);
    uVar5 = 0;
    lVar3 = IoBuildDeviceIoControlRequest(0x70214,lVar2,0,0);
    if (lVar3 == 0) {
      iVar1 = -0x3fffff66;
    }
    else {
      iVar1 = IofCallDriver(lVar2,lVar3);
      if (iVar1 == 0x103) {
        uVar5 = 0;
        lVar3 = 0;
        KeWaitForSingleObject(local_78 + 1,0,0,0);
        iVar1 = (int)local_58;
      }
      if (iVar1 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x48,
                   &WPP_97d16c38264433ff5e04fa48b3a3652b_Traceguids,iVar1);
        }
      }
      else {
        uVar4 = CONCAT71((int7)((ulonglong)lVar3 >> 8),(byte)uStack_40 >> 1) & 0xffffffffffffff01;
        *param_2 = (char)uVar4;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_ql(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,uVar5,param_1,
                    (byte)uStack_40 >> 1 & 1);
        }
      }
    }
    if (lVar2 != 0) {
      ObfDereferenceObject(lVar2);
    }
  }
  if (local_78[0] != 0) {
    ObfDereferenceObject();
  }
  return iVar1;
}



===== WppInitKm @ 1c00136e4 =====

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



===== WppLoadTracingSupport @ 1c0013774 =====

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



===== WppTraceCallback @ 1c00138c0 =====

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



===== wil_UninitializeFeatureStaging @ 1c0013b48 =====

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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 1c0013ba0 =====

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
      goto LAB_1c0013bfd;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_1c0013bfd;
    }
  }
  uVar1 = 0x206;
LAB_1c0013bfd:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 1c0013c08 =====

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



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 1c0013cc0 =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 1c0013cf8 =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_1c0013d7a;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_1c0013d7a;
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
LAB_1c0013d7a:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 1c0013dd0 =====

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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 1c0013e30 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 1c0013e4c =====

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



===== SqosTraceNewInstanceContext @ 1c0013f00 =====

void SqosTraceNewInstanceContext(longlong param_1,undefined1 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  uint local_res18 [4];
  
  local_res18[0] = 0;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    iVar1 = FltGetVolumeProperties(*(undefined8 *)(param_1 + 0x10),0,0,local_res18);
    if (iVar1 == -0x3fffffdd) {
      puVar2 = (undefined4 *)SqospAllocate((ulonglong)local_res18[0]);
      if (puVar2 != (undefined4 *)0x0) {
        iVar1 = FltGetVolumeProperties
                          (*(undefined8 *)(param_1 + 0x10),puVar2,local_res18[0],local_res18);
        if ((((-1 < iVar1) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_qDDDDZZZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),puVar2 + 10,puVar2 + 6,
                          *(undefined8 *)(param_1 + 0x10),param_2,(char)*puVar2,(char)puVar2[1],
                          (char)puVar2[2],(wchar_t *)(puVar2 + 6),(wchar_t *)(puVar2 + 10),
                          (wchar_t *)(puVar2 + 0xe));
        }
        SqospFree(puVar2);
      }
    }
  }
  return;
}



===== SqospGetParametersBOOLEAN @ 1c001401c =====

longlong SqospGetParametersBOOLEAN(undefined8 param_1,ulonglong param_2,undefined8 param_3)

{
  char cVar1;
  uint7 extraout_var;
  longlong lVar2;
  ulonglong local_res10 [3];
  
  local_res10[0] = param_2 & 0xffffffff00000000;
  cVar1 = SqospGetParametersUINT32(param_1,L"EnableTestFeatures",0,1,(uint *)local_res10);
  if (cVar1 == '\0') {
    lVar2 = (ulonglong)extraout_var << 8;
  }
  else {
    lVar2 = CONCAT71(extraout_var,1);
    *(bool *)param_3 = (int)local_res10[0] != 0;
  }
  return lVar2;
}



===== SqospGetParametersUINT32 @ 1c0014070 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
SqospGetParametersUINT32(undefined8 param_1,short *param_2,uint param_3,uint param_4,uint *param_5)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  longlong lVar4;
  undefined2 uVar5;
  uint uVar6;
  undefined1 uVar7;
  undefined1 auStack_98 [32];
  longlong *local_78;
  undefined4 *local_70;
  undefined4 local_68 [2];
  longlong local_60;
  undefined8 local_58;
  short *psStack_50;
  undefined1 local_48 [4];
  int local_44;
  int local_40;
  uint local_3c;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_98;
  local_68[0] = 0;
  local_60 = 0;
  uVar7 = 0;
  local_58 = 0;
  psStack_50 = (short *)0x0;
  if (param_2 == (short *)0x0) {
LAB_1c001415b:
    local_78 = &local_60;
    uVar6 = IoOpenDriverRegistryKey(param_1,0,0x20019,0);
    if (-1 < (int)uVar6) {
      local_70 = local_68;
      local_78 = (longlong *)CONCAT44(local_78._4_4_,0x14);
      iVar2 = ZwQueryValueKey(local_60,&local_58,2,local_48);
      if (((-1 < iVar2) && (local_44 == 4)) && (local_40 == 4)) {
        *param_5 = local_3c;
        if (local_3c < param_3) {
          *param_5 = param_3;
        }
        else if (param_4 < local_3c) {
          *param_5 = param_4;
        }
        uVar7 = 1;
      }
      goto LAB_1c00141ff;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        (-1 < (char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c))) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c00141ff;
    uVar5 = 0xd;
  }
  else {
    lVar4 = 0x7fff;
    psVar3 = param_2;
    do {
      if (*psVar3 == 0) break;
      psVar3 = psVar3 + 1;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
    uVar6 = ~-(uint)(lVar4 != 0) & 0xc000000d;
    if (lVar4 != 0) {
      sVar1 = (0x7fff - (short)lVar4) * 2;
      local_58 = (ulonglong)CONCAT22(sVar1 + 2,sVar1);
      psStack_50 = param_2;
    }
    if (-1 < (int)uVar6) goto LAB_1c001415b;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0;
    }
    if (-1 < (char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c)) {
      return 0;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return 0;
    }
    uVar5 = 0xc;
  }
  WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
           &WPP_b8a405419f5733ac566e8c3690148060_Traceguids,uVar6);
LAB_1c00141ff:
  if (local_60 != 0) {
    ZwClose();
  }
  return uVar7;
}



===== SqospGetRegistryUINT32 @ 1c0014244 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 SqospGetRegistryUINT32(undefined8 param_1)

{
  short sVar1;
  int iVar2;
  wchar_t *pwVar3;
  undefined2 uVar4;
  longlong lVar5;
  undefined1 uVar6;
  uint uVar7;
  uint *in_stack_00000028;
  undefined1 auStack_b8 [32];
  undefined4 local_98;
  undefined4 *local_90;
  undefined4 local_88 [2];
  longlong local_80;
  undefined8 local_78;
  wchar_t *pwStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong uStack_40;
  undefined1 local_38 [4];
  int local_34;
  int local_30;
  uint local_2c;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_b8;
  local_48 = 0;
  uStack_40 = uStack_40 & 0xffffffff00000000;
  local_88[0] = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_80 = 0;
  local_58 = 0;
  uStack_50 = 0;
  uVar6 = 0;
  lVar5 = 0x7fff;
  local_78 = 0;
  pwStack_70 = (wchar_t *)0x0;
  pwVar3 = L"StorageBaseIOSize";
  do {
    if (*pwVar3 == L'\0') break;
    pwVar3 = pwVar3 + 1;
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  uVar7 = ~-(uint)(lVar5 != 0) & 0xc000000d;
  if (lVar5 != 0) {
    pwStack_70 = L"StorageBaseIOSize";
    sVar1 = (0x7fff - (short)lVar5) * 2;
    local_78 = (ulonglong)CONCAT22(sVar1 + 2,sVar1);
  }
  if ((int)uVar7 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0;
    }
    if (-1 < (char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c)) {
      return 0;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return 0;
    }
    uVar4 = 10;
  }
  else {
    local_68 = 0x30;
    uStack_60 = 0;
    uStack_50 = 0x240;
    local_48 = 0;
    uStack_40 = 0;
    local_58 = param_1;
    uVar7 = ZwOpenKey(&local_80,0x20019,&local_68);
    if (-1 < (int)uVar7) {
      local_90 = local_88;
      local_98 = 0x14;
      iVar2 = ZwQueryValueKey(local_80,&local_78,2,local_38);
      if (((-1 < iVar2) && (local_34 == 4)) && (local_30 == 4)) {
        uVar7 = 0x1000;
        *in_stack_00000028 = local_2c;
        if ((local_2c < 0x1000) || (uVar7 = 0x400000, 0x400000 < local_2c)) {
          *in_stack_00000028 = uVar7;
        }
        uVar6 = 1;
      }
      goto LAB_1c00143f1;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        (-1 < (char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c))) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c00143f1;
    uVar4 = 0xb;
  }
  WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
           &WPP_b8a405419f5733ac566e8c3690148060_Traceguids,uVar7);
LAB_1c00143f1:
  if (local_80 != 0) {
    ZwClose();
  }
  return uVar6;
}



===== DvRundownWorkQueue @ 1c0014434 =====

void DvRundownWorkQueue(ulonglong *param_1)

{
  ulonglong uVar1;
  ulonglong uVar2;
  bool bVar3;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong uStack_10;
  
  uVar2 = *param_1;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  uStack_10 = 0;
  if (uVar2 != 0) {
    KeInitializeEvent(&local_28,0,0);
    do {
      if (uVar2 == 0) {
        return;
      }
      uStack_10 = uVar2 & 0xfffffffffffffffe;
      LOCK();
      if (uVar2 == *param_1) {
        *param_1 = (longlong)&local_28 + 2;
        uVar1 = uVar2;
      }
      else {
        uVar1 = *param_1;
      }
      UNLOCK();
      bVar3 = uVar1 != uVar2;
      uVar2 = uVar1;
    } while (bVar3);
    KeWaitForSingleObject(&local_28,0,0,0,0);
  }
  return;
}



===== SqosPreReadWrite @ 1c00144d0 =====

int SqosPreReadWrite(uint *param_1,longlong param_2,undefined8 *param_3)

{
  int iVar1;
  longlong *plVar2;
  longlong local_res8;
  longlong local_res20;
  
  local_res20 = 0;
  local_res8 = 0;
  if ((*param_1 & 1) == 0) {
    return 1;
  }
  iVar1 = FltGetStreamHandleContext
                    (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),&local_res8);
  if (iVar1 == -0x3ffffddb) {
    iVar1 = FltGetInstanceContext(*(undefined8 *)(param_2 + 0x18),&local_res20);
    if (((-1 < iVar1) && (*(int *)(local_res20 + 0xbc) == 2)) &&
       (*(int *)(local_res20 + 0x39c) != 0)) {
      iVar1 = SqospCreateStreamHandleContext
                        ((longlong)param_1,param_2,*(longlong *)(local_res20 + 0xb0),DAT_1c000d2ab,
                         '\0',&local_res8);
      goto joined_r0x0001c0014617;
    }
  }
  else {
joined_r0x0001c0014617:
    if (((-1 < iVar1) && (*(char *)(local_res8 + 0x20) == '\0')) &&
       ((*(int *)(*(longlong *)(local_res8 + 8) + 0x39c) != 0 &&
        (plVar2 = SqospCreateJob(local_res8,(longlong)param_1), plVar2 != (longlong *)0x0)))) {
      iVar1 = SqospStartJob(plVar2);
      if (iVar1 == 0) {
        *param_3 = plVar2;
      }
      else {
        *param_3 = 0;
      }
      goto LAB_1c0014567;
    }
  }
  iVar1 = 1;
LAB_1c0014567:
  if (local_res20 != 0) {
    FltReleaseContext();
  }
  if (local_res8 != 0) {
    FltReleaseContext();
  }
  return iVar1;
}



===== SqosPostCreate @ 1c0014630 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 SqosPostCreate(longlong param_1,longlong param_2,longlong *param_3,ulonglong param_4)

{
  byte bVar1;
  int iVar2;
  longlong *plVar3;
  wchar_t *pwVar4;
  undefined1 auStackY_b8 [32];
  longlong local_68 [8];
  
  local_68[6] = __security_cookie ^ (ulonglong)auStackY_b8;
  local_68[1] = 0;
  local_68[2] = 0;
  local_68[5] = 0;
  local_68[3] = 0;
  local_68[4] = 0;
  plVar3 = param_3;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,param_3,*(undefined8 *)(param_2 + 0x20)
            );
  }
  if (((param_4 & 1) == 0) && (-1 < *(int *)(param_1 + 0x18))) {
    if ((char)param_3[4] == '\0') {
      iVar2 = FltQueryInformationFile
                        (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),
                         local_68 + 1,0x28);
      if ((iVar2 < 0) || ((local_68[5] & 0x400000U) != 0)) {
        *(undefined1 *)(param_3 + 4) = 1;
      }
    }
    plVar3 = (longlong *)0x1;
    iVar2 = FltSetStreamHandleContext
                      (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),1,param_3);
    if (iVar2 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        plVar3 = (longlong *)&WPP_97d16c38264433ff5e04fa48b3a3652b_Traceguids;
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
                 &WPP_97d16c38264433ff5e04fa48b3a3652b_Traceguids,iVar2);
      }
    }
    else {
      local_68[0] = 0;
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        plVar3 = local_68;
        FltGetFileNameInformation(param_1,0x401);
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0 &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])))) {
          pwVar4 = L"\x0e\x10";
          if (local_68[0] != 0) {
            pwVar4 = (wchar_t *)(local_68[0] + 8);
          }
          bVar1 = *(byte *)(param_3[2] + 0x7c);
          plVar3 = (longlong *)(ulonglong)bVar1;
          WPP_SF_sqZ_guid_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),
                             (ulonglong)*(byte *)(param_3 + 4),plVar3,"Created",
                             (char)*(undefined8 *)(param_2 + 0x20),pwVar4,param_3[2] + 0x58,bVar1,
                             *(byte *)(param_3 + 4));
        }
        if (local_68[0] != 0) {
          FltReleaseFileNameInformation();
        }
      }
    }
  }
  FltReleaseContext(param_3);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,plVar3,0);
  }
  return 0;
}



===== SqosPreCreate @ 1c00148a0 =====

bool SqosPreCreate(undefined8 param_1,longlong param_2,longlong *param_3)

{
  int iVar1;
  longlong *plVar2;
  bool bVar3;
  longlong local_res20;
  
  local_res20 = 0;
  plVar2 = param_3;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,param_3,*(undefined8 *)(param_2 + 0x20)
            );
  }
  iVar1 = SqospAllocateStreamHandleContext(param_2,&local_res20);
  bVar3 = iVar1 < 0;
  if (!bVar3) {
    *param_3 = local_res20;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,plVar2,(uint)bVar3);
  }
  return bVar3;
}



===== SqosPreClose @ 1c0014970 =====

undefined8 SqosPreClose(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,param_3,*(undefined8 *)(param_2 + 0x20)
            );
  }
  uVar1 = 0;
  FltDeleteStreamHandleContext(*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20));
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,uVar1,1);
  }
  return 1;
}



===== SqosTraceStreamHandleContext @ 1c0014a10 =====

void SqosTraceStreamHandleContext(undefined8 param_1,longlong param_2,longlong param_3,char param_4)

{
  byte bVar1;
  char *pcVar2;
  wchar_t *pwVar3;
  longlong local_18 [2];
  
  local_18[0] = 0;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    FltGetFileNameInformation(param_1,0x401,local_18);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0 && (3 < (byte)WPP_GLOBAL_Control[0x29]))
       )) {
      pwVar3 = L"\x0e\x10";
      if (local_18[0] != 0) {
        pwVar3 = (wchar_t *)(local_18[0] + 8);
      }
      pcVar2 = "Created";
      bVar1 = *(byte *)(*(longlong *)(param_3 + 0x10) + 0x7c);
      if (param_4 == '\0') {
        pcVar2 = "Modified";
      }
      WPP_SF_sqZ_guid_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),
                         (ulonglong)*(byte *)(param_3 + 0x20),(ulonglong)bVar1,pcVar2,
                         (char)*(undefined8 *)(param_2 + 0x20),pwVar3,
                         *(longlong *)(param_3 + 0x10) + 0x58,bVar1,*(byte *)(param_3 + 0x20));
    }
    if (local_18[0] != 0) {
      FltReleaseFileNameInformation();
    }
  }
  return;
}



===== SqosStreamHandleContextCleanup @ 1c0014b20 =====

void SqosStreamHandleContextCleanup(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_2 = 0x3f;
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3f,param_3,param_1);
  }
  SqospCleanupStreamHandleContext(param_1,param_2,param_3);
  return;
}



===== SqosPreFileSystemControl @ 1c0014b80 =====

int SqosPreFileSystemControl(uint *param_1,longlong param_2,longlong *param_3)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  longlong *plVar4;
  longlong *plVar5;
  longlong local_res8;
  longlong local_res20;
  
  lVar1 = *(longlong *)(param_1 + 4);
  plVar5 = param_3;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3a,param_3,
              *(undefined8 *)(param_2 + 0x20),(char)*(undefined4 *)(lVar1 + 0x28));
  }
  iVar2 = *(int *)(lVar1 + 0x28);
  if ((iVar2 == 0x98268) || (iVar2 == 0x980c8)) {
    local_res20 = 0;
    local_res8 = 0;
    if ((*param_1 & 1) != 0) {
      plVar5 = &local_res8;
      iVar2 = FltGetStreamHandleContext
                        (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20));
      if (iVar2 == -0x3ffffddb) {
        iVar2 = FltGetInstanceContext(*(undefined8 *)(param_2 + 0x18),&local_res20);
        if (((-1 < iVar2) && (*(int *)(local_res20 + 0xbc) == 2)) &&
           (*(int *)(local_res20 + 0x39c) != 0)) {
          plVar5 = *(longlong **)(local_res20 + 0xb0);
          iVar2 = SqospCreateStreamHandleContext
                            ((longlong)param_1,param_2,(longlong)plVar5,DAT_1c000d2ab,'\0',
                             &local_res8);
          if (-1 < iVar2) goto LAB_1c0014c5f;
        }
LAB_1c0014ce9:
        iVar2 = 1;
      }
      else {
        if (iVar2 < 0) goto LAB_1c0014ce9;
LAB_1c0014c5f:
        if (((*(char *)(local_res8 + 0x20) != '\0') ||
            (*(int *)(*(longlong *)(local_res8 + 8) + 0x39c) == 0)) ||
           (plVar4 = SqospCreateJob(local_res8,(longlong)param_1), plVar4 == (longlong *)0x0))
        goto LAB_1c0014ce9;
        iVar2 = SqospStartJob(plVar4);
        if (iVar2 == 0) {
          *param_3 = (longlong)plVar4;
        }
        else {
          *param_3 = 0;
        }
      }
      if (local_res20 != 0) {
        FltReleaseContext();
      }
      if (local_res8 != 0) {
        FltReleaseContext();
      }
      goto LAB_1c0014beb;
    }
  }
  else if (iVar2 == 0x90350) {
    iVar2 = 4;
    uVar3 = SqospHandleControlRequest((longlong)param_1,param_2,plVar5);
    if ((int)uVar3 < 0) {
      param_1[8] = 0;
      param_1[9] = 0;
    }
    param_1[6] = uVar3;
    goto LAB_1c0014beb;
  }
  iVar2 = 1;
LAB_1c0014beb:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3b,plVar5,iVar2);
  }
  return iVar2;
}



===== SqosInstanceSetup @ 1c0014dc0 =====

ulonglong SqosInstanceSetup(longlong param_1,byte param_2,undefined8 param_3,int param_4)

{
  int iVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  char local_res18 [16];
  longlong local_28 [2];
  
  local_res18[0] = '\0';
  local_28[0] = 0;
  uVar4 = param_3;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,param_3,
              *(undefined8 *)(param_1 + 0x10),param_2);
  }
  if ((int)param_3 != 8) {
    uVar3 = 0xc01c000f;
    goto LAB_1c0014e0f;
  }
  if (param_4 == 2) {
LAB_1c0014e95:
    if ((param_2 & 2) == 0) {
      uVar3 = 0xc01c000f;
      goto LAB_1c0014e0f;
    }
    iVar1 = SqospIsCsvHiddenVolume(*(undefined8 *)(param_1 + 0x10),local_res18);
    if (iVar1 < 0) {
      uVar3 = 0xc01c000f;
      goto LAB_1c0014e0f;
    }
    if (local_res18[0] != '\0') {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,uVar4,
                 *(undefined8 *)(param_1 + 0x10));
      }
      uVar3 = 0xc01c000f;
      goto LAB_1c0014e0f;
    }
  }
  else if (param_4 != 0x1b) {
    if (param_4 != 0x1c) {
      uVar3 = 0xc01c000f;
      goto LAB_1c0014e0f;
    }
    goto LAB_1c0014e95;
  }
  uVar2 = SqospCreateDevice(*(undefined8 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x10),param_4,
                            local_28);
  uVar3 = uVar2 & 0xffffffff;
  if (-1 < (int)uVar2) {
    SqosTraceNewInstanceContext(param_1,(char)param_4);
  }
  if (local_28[0] != 0) {
    FltReleaseContext();
  }
LAB_1c0014e0f:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
             &WPP_97d16c38264433ff5e04fa48b3a3652b_Traceguids,(int)uVar3);
  }
  return uVar3;
}



===== SqospHandleControlRequest @ 1c0014f50 =====

int SqospHandleControlRequest(longlong param_1,longlong param_2,undefined8 param_3)

{
  ushort uVar1;
  ushort *puVar2;
  char cVar3;
  uint uVar4;
  undefined8 uVar5;
  ushort ****ppppuVar6;
  ulonglong uVar7;
  ushort *puVar8;
  undefined2 uVar9;
  undefined8 uVar10;
  longlong lVar11;
  undefined1 uVar12;
  uint uVar13;
  ushort ****ppppuVar14;
  undefined **ppuVar15;
  int local_res8 [2];
  undefined4 local_res20 [2];
  ulonglong in_stack_ffffffffffffff58;
  ushort ****local_78;
  longlong local_70;
  ushort *local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  
  lVar11 = *(longlong *)(param_1 + 0x10);
  uVar12 = 0;
  ppppuVar6 = (ushort ****)0x0;
  local_res8[0] = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_res20[0] = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_78 = (ushort ****)0x0;
  local_70 = 0;
  local_68 = (ushort *)0x0;
  if (*(uint *)(lVar11 + 0x20) < 8) {
    local_res8[0] = -0x3ffffff3;
    goto LAB_1c00156e9;
  }
  puVar2 = *(ushort **)(lVar11 + 0x30);
  uVar13 = *(uint *)(puVar2 + 2);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    in_stack_ffffffffffffff58 = CONCAT44((int)(in_stack_ffffffffffffff58 >> 0x20),uVar13);
    WPP_SF_DDq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,(uint)*puVar2,(char)uVar13
               ,(char)*(undefined8 *)(param_2 + 0x20));
  }
  ppuVar15 = &WPP_GLOBAL_Control;
  if (*puVar2 != 0x100) {
    if (*puVar2 == 0x101) {
      uVar10 = 0x80;
      uVar4 = 0x60;
      goto LAB_1c0015041;
    }
    local_res8[0] = -0x3fffffa7;
    goto LAB_1c0015693;
  }
  uVar10 = 0x70;
  uVar4 = 0x58;
LAB_1c0015041:
  if ((*(uint *)(lVar11 + 0x20) < (uint)uVar10) ||
     (puVar2 = *(ushort **)(lVar11 + 0x30), uVar13 == 0)) {
LAB_1c0015684:
    local_res8[0] = -0x3ffffff3;
  }
  else {
    if ((uVar13 & 8) != 0) {
      if (*(uint *)(lVar11 + 0x18) < uVar4) goto LAB_1c0015684;
      local_68 = puVar2;
    }
    if (((uVar13 & 4) != 0) &&
       (uVar5 = SqospIsNullGuid((longlong *)(puVar2 + 4)), (char)uVar5 != '\0')) goto LAB_1c0015684;
    if ((uVar13 & 6) != 0) {
      uVar7 = *(ulonglong *)(puVar2 + 0x1c);
      uVar5 = SqospIsNullGuid((longlong *)(puVar2 + 0xc));
      if ((char)uVar5 != '\0') {
        if ((1000000000 < uVar7) ||
           ((((0x100 < *puVar2 && (1000000000 < *(ulonglong *)(puVar2 + 0x38))) ||
             (1000000000 < *(ulonglong *)(puVar2 + 0x20))) ||
            ((uVar7 != 0 && (uVar7 < *(ulonglong *)(puVar2 + 0x20))))))) {
          if (((undefined **)WPP_GLOBAL_Control != ppuVar15) &&
             (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0 &&
              (1 < (byte)WPP_GLOBAL_Control[0x29])))) {
            if (0x100 < *puVar2) {
              uVar12 = (undefined1)*(undefined8 *)(puVar2 + 0x38);
            }
            WPP_SF_III(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,0x101,uVar7,
                       (char)*(undefined8 *)(puVar2 + 0x20),uVar12);
          }
          goto LAB_1c0015684;
        }
        goto LAB_1c0015176;
      }
      if (((uVar7 == 0) && (*(longlong *)(puVar2 + 0x20) == 0)) &&
         ((*puVar2 < 0x101 || (*(longlong *)(puVar2 + 0x38) == 0)))) goto LAB_1c0015176;
      if ((((undefined **)WPP_GLOBAL_Control == ppuVar15) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) goto LAB_1c0015684;
      uVar9 = 0x23;
LAB_1c0015674:
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,
              &WPP_97d16c38264433ff5e04fa48b3a3652b_Traceguids);
      goto LAB_1c0015684;
    }
LAB_1c0015176:
    uVar1 = puVar2[0x25];
    if ((uVar1 != 0) || (puVar2[0x24] != 0)) {
      if (((uVar1 & 1) == 0) && (uVar1 < 0x201)) {
        if ((uint)puVar2[0x24] < (uint)uVar10) {
          if ((((undefined **)WPP_GLOBAL_Control != ppuVar15) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar9 = 0x25;
            goto LAB_1c0015674;
          }
        }
        else {
          if ((uint)uVar1 + (uint)puVar2[0x24] <= *(uint *)(lVar11 + 0x20)) goto LAB_1c0015211;
          if ((((undefined **)WPP_GLOBAL_Control != ppuVar15) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar9 = 0x26;
            goto LAB_1c0015674;
          }
        }
      }
      else if ((((undefined **)WPP_GLOBAL_Control != ppuVar15) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
              (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar9 = 0x24;
        goto LAB_1c0015674;
      }
      goto LAB_1c0015684;
    }
LAB_1c0015211:
    uVar1 = puVar2[0x27];
    if ((uVar1 != 0) || (puVar2[0x26] != 0)) {
      if (((uVar1 & 1) == 0) && (uVar1 < 0x201)) {
        if ((uint)puVar2[0x26] < (uint)uVar10) {
          if ((((undefined **)WPP_GLOBAL_Control != ppuVar15) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar9 = 0x28;
            goto LAB_1c0015674;
          }
        }
        else {
          if ((uint)uVar1 + (uint)puVar2[0x26] <= *(uint *)(lVar11 + 0x20)) goto LAB_1c00152a6;
          if ((((undefined **)WPP_GLOBAL_Control != ppuVar15) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar9 = 0x29;
            goto LAB_1c0015674;
          }
        }
      }
      else if ((((undefined **)WPP_GLOBAL_Control != ppuVar15) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
              (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar9 = 0x27;
        goto LAB_1c0015674;
      }
      goto LAB_1c0015684;
    }
LAB_1c00152a6:
    if (*(char *)(param_1 + 0x50) != '\0') {
      SeCaptureSubjectContext(&local_60);
      uVar10 = IoGetFileObjectGenericMapping();
      cVar3 = SeAccessCheck(DAT_1c000d288,&local_60,0,2,
                            in_stack_ffffffffffffff58 & 0xffffffff00000000,0,uVar10,
                            *(undefined1 *)(param_1 + 0x50),local_res20,local_res8);
      if (cVar3 != '\0') {
        local_res8[0] = 0;
      }
      SeReleaseSubjectContext(&local_60);
      if (local_res8[0] < 0) goto LAB_1c0015693;
    }
    ppppuVar14 = (ushort ****)&local_78;
    local_res8[0] =
         FltGetStreamHandleContext(*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20));
    if (((local_res8[0] + 0x80000000U & 0x80000000) == 0) && (local_res8[0] != -0x3ffffddb)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29])))
         ) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
                 &WPP_97d16c38264433ff5e04fa48b3a3652b_Traceguids,local_res8[0]);
      }
      goto LAB_1c0015693;
    }
    if (((local_78 != (ushort ****)0x0) &&
        (ppppuVar6 = (ushort ****)SqospGetStreamHandleContextClient((longlong)local_78),
        ppppuVar6 != (ushort ****)0x0)) && (*(char *)((longlong)ppppuVar6 + 0x7c) == '\0')) {
      uVar13 = uVar13 & 0xfffffffb;
    }
    if (((uVar13 >> 0x1c & 1) != 0) && ((uVar13 & 1) == 0)) {
      uVar13 = uVar13 & 0xefffffff;
    }
    if ((uVar13 & 5) != 0) {
      if (ppppuVar6 == (ushort ****)0x0) {
LAB_1c001541d:
        local_res8[0] = FltGetInstanceContext(*(undefined8 *)(param_2 + 0x18),&local_70);
        if (-1 < local_res8[0]) {
          puVar8 = puVar2 + 4;
          uVar10 = SqospIsNullGuid((longlong *)puVar8);
          if ((char)uVar10 == '\0') {
            ppppuVar6 = (ushort ****)SqospLookupClient((UCHAR *)puVar8,local_70,param_1);
            if (ppppuVar6 == (ushort ****)0x0) {
              local_res8[0] = -0x3fffff66;
              goto LAB_1c0015693;
            }
          }
          else {
            SqospAddRefClient(*(longlong *)(local_70 + 0xb0));
            ppppuVar6 = *(ushort *****)(local_70 + 0xb0);
          }
          goto LAB_1c001544d;
        }
        local_res8[0] = -0x3fffff17;
      }
      else {
        lVar11 = (longlong)ppppuVar6[0xb] - *(longlong *)(puVar2 + 4);
        if (lVar11 == 0) {
          lVar11 = (longlong)ppppuVar6[0xc] - *(longlong *)(puVar2 + 8);
        }
        if (lVar11 != 0) {
          SqospReleaseClient((longlong)ppppuVar6);
          ppppuVar6 = (ushort ****)0x0;
          goto LAB_1c001541d;
        }
        if ((uVar13 & 1) == 0) goto LAB_1c00154ed;
LAB_1c001544d:
        if (local_78 == (ushort ****)0x0) {
          ppppuVar14 = ppppuVar6;
          local_res8[0] =
               SqospCreateStreamHandleContext
                         (param_1,param_2,(longlong)ppppuVar6,(uVar13 & 0x10000000) != 0,'\x01',
                          (longlong *)&local_78);
        }
        else {
          ppppuVar14 = local_78;
          local_res8[0] =
               SqospModifyStreamHandleContext
                         (param_1,param_2,(longlong)local_78,(longlong)ppppuVar6,
                          (uVar13 & 0x10000000) != 0);
        }
        if (-1 < local_res8[0]) goto LAB_1c00154ed;
      }
      goto LAB_1c0015693;
    }
LAB_1c00154ed:
    if (local_78 == (ushort ****)0x0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar9 = 0x2b;
LAB_1c0015518:
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,ppppuVar14,
                 *(undefined8 *)(param_2 + 0x20));
      }
LAB_1c0015526:
      local_res8[0] = -0x3ffffddb;
    }
    else if ((uVar13 & 6) == 0) {
LAB_1c00155be:
      puVar8 = local_68;
      if (local_68 == (ushort *)0x0) {
        if ((uVar13 & 0x10) != 0) goto LAB_1c0015609;
LAB_1c001562b:
        uVar7 = 0;
      }
      else {
        if (*(char *)((longlong)ppppuVar6 + 0x7c) != '\0') {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
             (2 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar9 = 0x2d;
            goto LAB_1c0015518;
          }
          goto LAB_1c0015526;
        }
LAB_1c0015609:
        SqospGetClientStatusInfo((longlong)ppppuVar6,puVar2,local_68);
        if (puVar8 == (ushort *)0x0) goto LAB_1c001562b;
        *puVar8 = *puVar2;
        uVar7 = (ulonglong)uVar4;
        puVar8[2] = 0;
        puVar8[3] = 0;
      }
      *(ulonglong *)(param_1 + 0x20) = uVar7;
      local_res8[0] = 0;
    }
    else if (*(char *)((longlong)ppppuVar6 + 0x7c) == '\0') {
      if ((uVar13 & 2) == 0) {
        ppppuVar14 = (ushort ****)(puVar2 + 0x14);
        cVar3 = SqospProbeClientPolicy
                          ((longlong)ppppuVar6,(longlong *)(puVar2 + 0xc),(longlong *)ppppuVar14);
        if (cVar3 != '\0') goto LAB_1c00155be;
      }
      uVar7 = SqospUpdateClientPolicy((longlong)ppppuVar6,puVar2);
      local_res8[0] = (int)uVar7;
      if (-1 < local_res8[0]) goto LAB_1c00155be;
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) goto LAB_1c0015526;
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
               &WPP_97d16c38264433ff5e04fa48b3a3652b_Traceguids,local_res8[0]);
      local_res8[0] = -0x3ffffddb;
    }
  }
LAB_1c0015693:
  if (local_78 != (ushort ****)0x0) {
    FltReleaseContext(local_78);
  }
  if (ppppuVar6 != (ushort ****)0x0) {
    SqospReleaseClient((longlong)ppppuVar6);
  }
  if (local_70 != 0) {
    FltReleaseContext(local_70);
  }
LAB_1c00156e9:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
             &WPP_97d16c38264433ff5e04fa48b3a3652b_Traceguids,local_res8[0]);
  }
  return local_res8[0];
}



===== SqospRemoveClient @ 1c0015760 =====

void SqospRemoveClient(longlong param_1)

{
  FltAcquirePushLockExclusiveEx(&SqosGlobals,0);
  if (*(int *)(param_1 + 0xc) == 0) {
    *(undefined1 *)(param_1 + 0x7d) = 0;
    RtlRbRemoveNode(&DAT_1c000d158,param_1 + 0x40);
    SqospRemoveClientFlows(param_1);
    FltReleasePushLockEx(&SqosGlobals,0);
    SqospCleanupClient(param_1);
  }
  else {
    FltReleasePushLockEx(&SqosGlobals,0);
  }
  return;
}



===== SqospCleanupClient @ 1c00157f0 =====

void SqospCleanupClient(longlong param_1)

{
  SqospFreeUnicodeString((undefined4 *)(param_1 + 0xa8));
  SqospFreeUnicodeString((undefined4 *)(param_1 + 0xb8));
  ExFreeToLookasideListEx(&DAT_1c000d220,param_1);
  return;
}



===== entry @ 1c0016010 =====

void entry(undefined8 param_1)

{
  __security_init_cookie();
  DriverEntry(param_1);
  return;
}



===== __security_init_cookie @ 1c0016044 =====

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



===== SqospInitializeJobDispatcher @ 1c0016078 =====

int SqospInitializeJobDispatcher(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  ulonglong uVar7;
  longlong local_res8;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_2c = 0;
  local_res8 = 0;
  local_40 = 0;
  local_38 = 0;
  local_48 = 0x30;
  local_28 = 0;
  uStack_20 = 0;
  local_30 = 0x200;
  KeInitializeQueue(param_1 + 8,1);
  *(undefined1 *)(param_1 + 0x48) = 1;
  iVar2 = PsCreateSystemThread
                    (&local_res8,0x1fffff,&local_48,0,0,SqosJobDispatcherThreadRoutine,param_1);
  if (-1 < iVar2) {
    iVar2 = ObReferenceObjectByHandle(local_res8,0x100020,0,0,param_1,0);
    if (-1 < iVar2) {
      uVar3 = KeQueryMaximumProcessorCountEx(0xffff);
      uVar7 = (ulonglong)uVar3;
      lVar4 = ExAllocatePool2(0x48);
      *(longlong *)(param_1 + 0x50) = lVar4;
      if (lVar4 == 0) {
        iVar2 = -0x3fffff66;
      }
      else if (uVar3 != 0) {
        lVar4 = 0;
        lVar6 = 0;
        do {
          lVar1 = *(longlong *)(param_1 + 0x50);
          *(undefined8 *)(lVar4 + 8 + lVar1) = 0;
          *(code **)(lVar4 + 0x18 + lVar1) = SqosJobDispatcherWorkItemRoutine;
          lVar5 = lVar1 + 8 + lVar6;
          lVar6 = lVar6 + 0x40;
          *(longlong *)(lVar4 + 0x20 + lVar1) = lVar5;
          *(undefined8 *)(lVar4 + *(longlong *)(param_1 + 0x50)) = 0;
          lVar4 = lVar4 + 0x40;
          uVar7 = uVar7 - 1;
        } while (uVar7 != 0);
      }
    }
  }
  if (local_res8 != 0) {
    ZwClose();
  }
  return iVar2;
}



===== DriverEntry @ 1c00161fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(undefined8 param_1)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined2 uVar4;
  ulonglong uVar5;
  wchar_t *pwVar6;
  undefined1 auStackY_298 [32];
  uint local_258;
  uint local_254;
  uint local_250;
  uint local_24c;
  uint local_248 [2];
  longlong local_240 [2];
  undefined1 *local_230;
  undefined8 local_228;
  undefined1 *local_220;
  undefined8 local_218;
  undefined8 local_210;
  undefined8 local_208;
  longlong local_200;
  wchar_t *local_1f8;
  undefined8 local_1f0;
  undefined8 uStack_1e8;
  undefined8 *local_1e0;
  undefined8 uStack_1d8;
  longlong local_1d0;
  ulonglong local_1c8;
  undefined8 local_1c0;
  undefined8 uStack_1b8;
  undefined4 local_1a8 [70];
  char local_8e;
  wchar_t local_88 [56];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_298;
  builtin_wcsncpy(local_88,L"\\Registry\\Machine\\System\\CurrentControlSet\\Contr",0x30);
  builtin_wcsncpy(local_88 + 0x30,L"ol\\QoS",7);
  local_1f8 = local_88;
  local_1c0 = 0;
  uStack_1b8 = 0;
  local_200 = 0x6e006c;
  local_1f0 = 0;
  uStack_1e8 = 0;
  local_1d0 = 0;
  local_1e0 = (undefined8 *)0x0;
  uStack_1d8 = 0;
  local_1c8 = local_1c8 & 0xffffffff00000000;
  memset(local_1a8,0,0x11c);
  _DAT_1c000d368 = 1;
  local_240[0] = 0;
  DAT_1c000d348 = &WPP_ThisDir_CTLGUID_StorQosFltTraceGuid;
  _WPP_MAIN_CB = 0;
  DAT_1c000d350 = 0;
  _DAT_1c000d360 = 0;
  WppLoadTracingSupport();
  _DAT_1c000d360 = 0;
  WppInitKm();
  wil_InitializeFeatureStaging();
  memset(&SqosGlobals,0,0x180);
  DAT_1c000d208 = 0;
  DAT_1c000d200 = param_1;
  FltInitializePushLock(&SqosGlobals);
  DAT_1c000d150 = &DAT_1c000d148;
  DAT_1c000d148 = &DAT_1c000d148;
  uVar3 = 0;
  DAT_1c000d170 = &DAT_1c000d168;
  DAT_1c000d168 = &DAT_1c000d168;
  DAT_1c000d158 = 0;
  DAT_1c000d160 = 0;
  DAT_1c000d178 = 0;
  ExInitializeLookasideListEx(&DAT_1c000d220,0,0,0x200);
  _DAT_1c000d2a8 = 0;
  KeQueryPerformanceCounter(&DAT_1c000d290);
  DAT_1c000d2a0 = 0x2000;
  DAT_1c000d2aa = 0;
  DAT_1c000d298 = 0x9896800000 / DAT_1c000d290;
  uVar5 = 0x9896800000 % DAT_1c000d290;
  DAT_1c000d280 = FltAllocateGenericWorkItem();
  if (DAT_1c000d280 == 0) {
    iVar1 = -0x3fffff66;
  }
  else {
    DAT_1c000d288 = 0;
    iVar1 = SqospCreateQoSControlSecurityDescriptor(&DAT_1c000d288,uVar5,uVar3);
    if (iVar1 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) goto LAB_1c0016904;
      uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
      uVar4 = 10;
    }
    else {
      local_258 = 83000;
      local_248[0] = 1000;
      local_24c = 10;
      local_250 = 0x19;
      local_254 = 0;
      local_1a8[0] = 0x11c;
      iVar1 = RtlGetVersion(local_1a8);
      if (iVar1 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c0016904;
        uVar4 = 0xb;
      }
      else {
        if (local_8e == '\x01') {
          DAT_1c000d2ab = 1;
        }
        SqospGetParametersUINT32(param_1,L"LatencyTargetMicroseconds",1000,10000000,&local_258);
        SqospGetParametersUINT32
                  (param_1,L"MinimumDeviceLatencyMicroseconds",1000,local_258,local_248);
        SqospGetParametersUINT32(param_1,L"UnreservedCapacityPercent",1,0x32,&local_24c);
        pwVar6 = L"CapacityCompensationPercent";
        SqospGetParametersUINT32(param_1,L"CapacityCompensationPercent",0,100,&local_250);
        SqospGetParametersBOOLEAN(param_1,(ulonglong)pwVar6,&DAT_1c000d2aa);
        SqospGetParametersUINT32(param_1,L"DefaultFlowBypassPolicy",0,2,&local_254);
        if (local_254 == 1) {
          DAT_1c000d2ab = 1;
        }
        else if (local_254 == 2) {
          DAT_1c000d2ab = 0;
        }
        SqospGetRegistryUINT32(local_240 + 8);
        uVar2 = DAT_1c000d2a0 - 1 >> 1 | DAT_1c000d2a0 - 1;
        uVar2 = uVar2 >> 2 | uVar2;
        uVar2 = uVar2 >> 4 | uVar2;
        uVar2 = uVar2 >> 8 | uVar2;
        DAT_1c000d2a0 = (uVar2 >> 0x10 | uVar2) + 1;
        DAT_1c000d2a4 = SqospLogBase2(DAT_1c000d2a0);
        DAT_1c000d330 = 10000000;
        DAT_1c000d328 = 100000;
        BalanceInitialize(DAT_1c000d290,(ulonglong)local_258,(ulonglong)local_248[0],local_24c,
                          local_250);
        iVar1 = SqospInitializeJobDispatcher(0x1c000d180);
        if (iVar1 < 0) goto LAB_1c0016904;
        local_240[1] = 0x200;
        local_230 = &`SqosPcInitRegistrationInformationDeviceCounterSet'::__l2::Name;
        local_228 = 0x12;
        local_220 = &`SqosPcInitRegistrationInformationDeviceCounterSet'::__l2::Descriptors;
        local_208 = 0;
        local_218 = 0;
        local_210 = 0;
        iVar1 = PcwRegister(&SqosPcDeviceCounterSet,local_240 + 1);
        if (-1 < iVar1) {
          _DAT_1c000d2a8 = CONCAT11(DAT_1c000d2a9,1);
        }
        local_240[1] = 0x200;
        local_230 = &`SqosPcInitRegistrationInformationFlowCounterSet'::__l2::Name;
        local_228 = 10;
        local_220 = &`SqosPcInitRegistrationInformationFlowCounterSet'::__l2::Descriptors;
        local_208 = 0;
        local_218 = 0;
        local_210 = 0;
        iVar1 = PcwRegister(&SqosPcFlowCounterSet,local_240 + 1);
        if (-1 < iVar1) {
          _DAT_1c000d2a8 = CONCAT11(1,DAT_1c000d2a8);
        }
        iVar1 = FltRegisterFilter(param_1,&SqosFilterRegistration,&DAT_1c000d208);
        if (iVar1 < 0) {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c0016904;
          uVar4 = 0xc;
        }
        else {
          RtlInitUnicodeString(&local_1c0,L"\\storqosfltport");
          iVar1 = FltBuildDefaultSecurityDescriptor(local_240,0x1f0001);
          if (iVar1 < 0) {
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c0016904;
            uVar4 = 0xd;
          }
          else {
            local_1e0 = &local_1c0;
            local_1d0 = local_240[0];
            local_1f0 = CONCAT44(local_1f0._4_4_,0x30);
            uStack_1e8 = 0;
            uStack_1d8 = CONCAT44(uStack_1d8._4_4_,0x240);
            local_1c8 = 0;
            iVar1 = FltCreateCommunicationPort(DAT_1c000d208,&DAT_1c000d210,&local_1f0,0);
            if (iVar1 < 0) {
              if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
                 ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c0016904;
              uVar4 = 0xe;
            }
            else {
              iVar1 = FltStartFiltering(DAT_1c000d208);
              if ((((-1 < iVar1) || ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control)) ||
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
                 ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c0016904;
              uVar4 = 0xf;
            }
          }
        }
      }
      uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    }
    WPP_SF_d(uVar3,uVar4,&WPP_97d16c38264433ff5e04fa48b3a3652b_Traceguids,iVar1);
  }
LAB_1c0016904:
  if (local_240[0] != 0) {
    FltFreeSecurityDescriptor();
  }
  if (iVar1 < 0) {
    SqosFilterUnloadInternal();
  }
  return iVar1;
}



===== wil_InitializeFeatureStaging @ 1c0016954 =====

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



===== wil_details_PopulateInitialConfiguredFeatureStates @ 1c0016a44 =====

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


