
===== _tlgCreate1Sz_char @ 140001008 =====

void _tlgCreate1Sz_char(longlong *param_1,char *param_2)

{
  int iVar1;
  longlong lVar2;
  
  if (param_2 == (char *)0x0) {
    param_2 = "";
    iVar1 = 1;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_2[lVar2] != '\0');
    iVar1 = (int)lVar2 + 1;
  }
  *(undefined4 *)((longlong)param_1 + 0xc) = 0;
  *param_1 = (longlong)param_2;
  *(int *)(param_1 + 1) = iVar1;
  return;
}



===== _tlgKeywordOn @ 14000103c =====

undefined1 _tlgKeywordOn(longlong param_1,ulonglong param_2)

{
  undefined1 uVar1;
  
  uVar1 = 0;
  if ((param_2 == 0) ||
     (((*(ulonglong *)(param_1 + 0x10) & param_2) != 0 &&
      ((*(ulonglong *)(param_1 + 0x18) & param_2) == *(ulonglong *)(param_1 + 0x18))))) {
    uVar1 = 1;
  }
  return uVar1;
}



===== _tlgWriteTransfer_EtwWriteTransfer @ 140001068 =====

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
  EtwWriteTransfer(*(undefined8 *)(param_1 + 0x20),&local_18,0,0,param_5,param_6);
  return;
}



===== InpProcessingWorkerRoutine @ 140001110 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void InpProcessingWorkerRoutine(longlong *param_1,undefined8 param_2,uint *param_3)

{
  longlong lVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  undefined4 *puVar7;
  ulonglong uVar8;
  int iVar9;
  uint uVar10;
  uint local_res8 [2];
  uint local_res10 [2];
  
  bVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x88);
  *(undefined4 *)(param_1 + 0xcd) = 0xffffffff;
  uVar5 = InpWorkerTakeProcessingOwnershipLocked(param_1);
  uVar8 = (ulonglong)bVar2;
  KeReleaseSpinLock(param_1 + 0x88);
  if ((char)uVar5 != '\0') {
    uVar10 = 0;
    *(undefined1 *)(param_1 + 0xb0) = 0;
    local_res10[0] = 0;
    local_res8[0] = 0;
    if (5 < DAT_140020050) {
      uVar8 = 1;
      puVar7 = &DAT_140020050;
      cVar3 = _tlgKeywordOn(0x140020050,1);
      if (cVar3 != '\0') {
        param_3 = (uint *)(*param_1 + 0x6ec);
        VmbusTraceVerbPacketFetchStart
                  (puVar7,uVar8,param_3,(ulonglong)*(ushort *)(*param_1 + 0xc90),0);
      }
    }
    iVar9 = 0;
    do {
      if (199 < uVar10) {
        iVar4 = 1;
        goto LAB_140001280;
      }
      if (param_1[0x98] != 0) {
        iVar4 = 7;
        break;
      }
      if ((longlong *)param_1[0xa0] == param_1 + 0xa0) {
        param_3 = local_res8;
        uVar5 = InpFillQueue(param_1,uVar8,param_3);
        iVar9 = iVar9 + local_res8[0];
        iVar4 = (int)uVar5;
        if (iVar4 != 1) break;
      }
      param_3 = (uint *)(ulonglong)(200 - uVar10);
      uVar8 = 0;
      uVar6 = InpProcessQueue(param_1,'\0',200 - uVar10,local_res10);
      uVar10 = uVar10 + local_res10[0];
      iVar4 = (int)uVar6;
    } while (iVar4 == 1);
    if (uVar10 != 0) {
LAB_140001280:
      lVar1 = *param_1;
      if (*(char *)(lVar1 + 0x7c8) == '\0') {
        uVar8 = (ulonglong)uVar10;
        (**(code **)(lVar1 + 0x7d8))();
      }
      else {
        uVar8 = *(ulonglong *)(lVar1 + 0x7e0);
        param_3 = (uint *)(ulonglong)uVar10;
        (**(code **)(lVar1 + 0x7d8))();
      }
    }
    if (5 < DAT_140020050) {
      uVar8 = 1;
      puVar7 = &DAT_140020050;
      cVar3 = _tlgKeywordOn(0x140020050,1);
      if (cVar3 != '\0') {
        param_3 = (uint *)(*param_1 + 0x6ec);
        VmbusTraceVerbPacketFetchStop
                  (puVar7,uVar8,param_3,(ulonglong)*(ushort *)(*param_1 + 0xc90),iVar9,uVar10);
      }
    }
    if ((Microsoft_Windows_Hyper_V_KMCLEnableBits & 1) != 0) {
      lVar1 = *param_1;
      McTemplateK0jjqqh_EtwWriteTransfer
                (lVar1 + 0xa90,uVar8,param_3,lVar1 + 0xaa0,lVar1 + 0xa90,(char)uVar10,200,
                 (char)*(undefined2 *)(lVar1 + 0xc90));
    }
    *(undefined1 *)((longlong)param_1 + 0x4b1) = *(undefined1 *)((longlong)param_1 + 0x4b2);
    *(undefined1 *)(param_1 + 0xb0) = 0;
    InpTransitionRunningQueue(param_1,'\0',iVar4);
  }
  return;
}



===== KmclpVmbusIsr @ 140001340 =====

bool KmclpVmbusIsr(longlong *param_1,undefined8 param_2,uint *param_3)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  
  param_1[0xd0] = param_1[0xd0] + 1;
  iVar3 = PkpExpectedInterruptCount((longlong)(param_1 + 8));
  if (iVar3 == 0) {
    *(int *)(param_1 + 0xd2) = (int)param_1[0xd2] + 1;
  }
  else {
    LOCK();
    *(int *)((longlong)param_1 + 0x8c) = *(int *)((longlong)param_1 + 0x8c) + 1;
    UNLOCK();
  }
  InInterruptArrived(param_1,param_2,param_3);
  if ((int)param_1[0x19] != 0) {
    uVar4 = PkIsOutgoingRingFull(param_1 + 8,(int)param_1[0x19]);
    if ((char)uVar4 == '\0') {
      uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x20);
      if ((int)param_1[0x21] == 2) {
        OutpEnqueuePollingDpc((longlong)param_1);
        cVar2 = KeCancelTimer(param_1 + 0x69);
        if (cVar2 != '\0') {
          *(int *)(param_1 + 0x81) = (int)param_1[0x81] + -1;
        }
      }
      KeReleaseSpinLock(param_1 + 0x20,uVar1);
    }
  }
  return iVar3 != 0;
}



===== PkpExpectInterrupt @ 140001420 =====

void PkpExpectInterrupt(longlong param_1,char param_2)

{
  uint uVar1;
  
  uVar1 = PkpExpectedInterruptCount(param_1);
  if (uVar1 < 0x40) {
    if (param_2 == '\0') {
      LOCK();
      *(int *)(param_1 + 0x8c) = *(int *)(param_1 + 0x8c) + 1;
      UNLOCK();
    }
    else {
      LOCK();
      *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + 1;
      UNLOCK();
    }
  }
  return;
}



===== PkCompleteRemoval @ 140001460 =====

undefined8 PkCompleteRemoval(longlong param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  
  puVar7 = *(uint **)(param_1 + 0x18);
  uVar8 = *(uint *)(param_1 + 0x28);
  if (((longlong)(int)*puVar7 == (ulonglong)param_2) &&
     (uVar2 = PkpExpectedInterruptCount(param_1), uVar2 < 0x40)) {
    LOCK();
    *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + 1;
    UNLOCK();
  }
  iVar1 = *(int *)(param_1 + 0x44);
  *(uint *)(param_1 + 0x44) = param_2;
  puVar7[1] = param_2;
  LOCK();
  UNLOCK();
  uVar2 = *puVar7;
  uVar3 = puVar7[3] & 0xfffffff8;
  if ((uVar2 < uVar8) && ((uVar2 & 7) == 0)) {
    *(uint *)(param_1 + 0x40) = uVar2;
    if (uVar3 != 0) {
      uVar5 = (iVar1 - uVar2) - 8;
      if (uVar8 <= uVar5) {
        uVar5 = uVar5 + uVar8;
      }
      uVar6 = (param_2 - uVar2) - 8;
      if (uVar8 <= uVar6) {
        uVar6 = uVar6 + uVar8;
      }
      if ((uVar3 <= uVar6) && (uVar5 < uVar3)) {
        return 0x214;
      }
    }
    uVar4 = 0;
    if (param_2 == uVar2) {
      uVar4 = 0x213;
    }
  }
  else {
    uVar4 = 0xc0000102;
  }
  return uVar4;
}



===== PkpExpectedInterruptCount @ 140001510 =====

int PkpExpectedInterruptCount(longlong param_1)

{
  return (*(int *)(param_1 + 0x8c) - *(int *)(param_1 + 0x4c)) + *(int *)(param_1 + 0x48);
}



===== InInterruptArrived @ 140001530 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void InInterruptArrived(longlong *param_1,undefined8 param_2,uint *param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  char cVar3;
  int iVar4;
  undefined8 uVar5;
  longlong *plVar6;
  longlong *plVar7;
  undefined4 uVar8;
  undefined4 extraout_var_00;
  undefined4 extraout_var_01;
  undefined7 extraout_var;
  undefined4 extraout_var_02;
  undefined4 extraout_var_03;
  undefined4 extraout_var_04;
  undefined4 *puVar9;
  ulonglong uVar10;
  int iVar11;
  uint uVar12;
  undefined1 auStackY_88 [32];
  uint local_48;
  uint local_44;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined4 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_88;
  KeAcquireSpinLockAtDpcLevel(param_1 + 0x88);
  if ((int)param_1[0x89] != 4) {
    KeReleaseSpinLockFromDpcLevel(param_1 + 0x88);
    return;
  }
  *(undefined4 *)(param_1[0xb] + 8) = 1;
  if (5 < DAT_140020050) {
    param_2 = 1;
    cVar3 = _tlgKeywordOn(0x140020050,1);
    if (cVar3 != '\0') {
      cVar3 = (char)param_2;
      param_2 = 0x136e;
      param_3 = (uint *)(*param_1 + 0x6ec);
      VmbusTraceVerbInterruptMaskSet
                ("InpTransitionToProcessingLocked",0x136e,param_3,
                 (ulonglong)*(ushort *)(*param_1 + 0xc90),cVar3);
    }
  }
  *(undefined4 *)(param_1 + 0x89) = 1;
  param_1[0x8d] = (longlong)SystemReserved1[0xf];
  KeReleaseSpinLockFromDpcLevel(param_1 + 0x88);
  if (param_1[0xba] == -1) {
    uVar10 = InpFillAndProcessQueue
                       (param_1,CONCAT71((int7)((ulonglong)param_2 >> 8),2),(uint *)0x1e);
    iVar4 = (int)uVar10;
  }
  else {
    KmclDiscountOldDpcCycles((longlong)param_1);
    if ((ulonglong)param_1[0xba] <= (ulonglong)param_1[0xb9]) {
LAB_1400017b9:
      KeAcquireSpinLockAtDpcLevel(param_1 + 0x88);
      if (((int)param_1[0x89] == 1) && (param_1[0x98] != 0)) {
        if ((4 < DAT_140020050) && (cVar3 = _tlgKeywordOn(0x140020050,4), cVar3 != '\0')) {
          lVar1 = *param_1;
          VmbusTraceInfoRundownEvent
                    ("InpPrepareToQueueWorkerLocked",0x1205,lVar1 + 0x6ec,
                     *(undefined2 *)(lVar1 + 0xc90),*(uint *)(lVar1 + 0x898),*(int *)(lVar1 + 0x89c)
                     ,*(undefined4 *)(lVar1 + 0x8a8),"Setting StopEvent");
        }
        param_3 = (uint *)0x0;
        KeSetEvent(param_1[0x98],0);
        param_1[0x98] = 0;
        param_1[0x8d] = 0;
      }
      else {
        *(undefined4 *)(param_1 + 0x89) = 2;
        param_1[0x8d] = 0;
        iVar4 = SystemReserved1[0x12]._4_4_;
        if (((param_1[0x8e] == 0) &&
            ((((int)param_1[0xcc] != SystemReserved1[0x12]._4_4_ &&
              (*(int *)((longlong)param_1 + 0x664) != SystemReserved1[0x12]._4_4_)) &&
             ((int)param_1[0xcd] == -1)))) && (SystemReserved1[0x12]._4_4_ != -1)) {
          *(byte *)((longlong)param_1 + 0x44c) = *(byte *)((longlong)param_1 + 0x44c) | 2;
          param_1[0x94] = param_1[0x94] + 1;
          *(int *)((longlong)param_1 + 0x48c) = *(int *)((longlong)param_1 + 0x48c) + 1;
          *(int *)(param_1 + 0xcd) = iVar4;
          param_1[0x8e] = param_1[0xcb];
        }
      }
      InpReleaseLockAndPerformWork(param_1);
      *(int *)((longlong)param_1 + 0x534) = *(int *)((longlong)param_1 + 0x534) + 1;
      if ((Microsoft_Windows_Hyper_V_KMCLEnableBits & 4) == 0) {
        return;
      }
      lVar1 = *param_1;
      McTemplateK0jjh_EtwWriteTransfer
                (lVar1 + 0xa90,&VMBUS_HIT_DPC_LIMIT,param_3,lVar1 + 0xaa0,lVar1 + 0xa90,
                 (char)*(undefined2 *)(lVar1 + 0xc90));
      return;
    }
    local_40 = 0;
    uStack_38 = 0;
    local_30 = 0;
    uVar5 = KeQueryDpcWatchdogInformation(&local_40);
    if (-1 < (int)uVar5) {
      uVar5 = 0;
      if (uStack_38._4_4_ < (uint)((int)uStack_38 * 0x1e) / 100) goto LAB_1400017b9;
    }
    uVar2 = rdtsc();
    uVar12 = 0;
    uVar10 = uVar2 & 0xffffffff00000000;
    plVar6 = (longlong *)(CONCAT44((int)((ulonglong)uVar5 >> 0x20),(int)uVar2) | uVar10);
    *(undefined1 *)(param_1 + 0xb0) = 1;
    local_44 = 0;
    local_48 = 0;
    plVar7 = plVar6;
    if (5 < DAT_140020050) {
      uVar10 = 1;
      puVar9 = &DAT_140020050;
      cVar3 = _tlgKeywordOn(0x140020050,1);
      plVar7 = (longlong *)CONCAT71(extraout_var,cVar3);
      if (cVar3 != '\0') {
        param_3 = (uint *)(*param_1 + 0x6ec);
        plVar7 = (longlong *)
                 VmbusTraceVerbPacketFetchStart
                           (puVar9,uVar10,param_3,(ulonglong)*(ushort *)(*param_1 + 0xc90),2);
      }
    }
    iVar11 = 0;
    do {
      if (0x1d < uVar12) {
LAB_1400017af:
        iVar4 = 1;
        break;
      }
      if (param_1[0x98] != 0) {
        iVar4 = 7;
        break;
      }
      plVar7 = param_1 + 0xa0;
      if ((longlong *)*plVar7 == plVar7) {
        param_3 = &local_48;
        plVar7 = (longlong *)InpFillQueue(param_1,uVar10,param_3);
        iVar11 = iVar11 + local_48;
        iVar4 = (int)plVar7;
        if (iVar4 != 1) break;
      }
      if (*(char *)((longlong)param_1 + 0x4b1) != '\0') goto LAB_1400017af;
      param_3 = (uint *)(ulonglong)(0x1e - uVar12);
      uVar10 = CONCAT71((int7)(uVar10 >> 8),2);
      plVar7 = (longlong *)InpProcessQueue(param_1,'\x02',0x1e - uVar12,&local_44);
      uVar12 = uVar12 + local_44;
      iVar4 = (int)plVar7;
    } while (iVar4 == 1);
    uVar8 = (undefined4)((ulonglong)plVar7 >> 0x20);
    if (uVar12 != 0) {
      lVar1 = *param_1;
      if (*(char *)(lVar1 + 0x7c8) == '\0') {
        uVar10 = (ulonglong)uVar12;
        (**(code **)(lVar1 + 0x7d8))();
        uVar8 = extraout_var_01;
      }
      else {
        uVar10 = *(ulonglong *)(lVar1 + 0x7e0);
        param_3 = (uint *)(ulonglong)uVar12;
        (**(code **)(lVar1 + 0x7d8))();
        uVar8 = extraout_var_02;
      }
    }
    if (5 < DAT_140020050) {
      uVar10 = 1;
      puVar9 = &DAT_140020050;
      cVar3 = _tlgKeywordOn(0x140020050,1);
      uVar8 = extraout_var_03;
      if (cVar3 != '\0') {
        param_3 = (uint *)(*param_1 + 0x6ec);
        VmbusTraceVerbPacketFetchStop
                  (puVar9,uVar10,param_3,(ulonglong)*(ushort *)(*param_1 + 0xc90),iVar11,uVar12);
        uVar8 = extraout_var_04;
      }
    }
    if ((Microsoft_Windows_Hyper_V_KMCLEnableBits & 1) != 0) {
      lVar1 = *param_1;
      McTemplateK0jjqqh_EtwWriteTransfer
                (lVar1 + 0xa90,uVar10,param_3,lVar1 + 0xaa0,lVar1 + 0xa90,(char)uVar12,0x1e,
                 (char)*(undefined2 *)(lVar1 + 0xc90));
      uVar8 = extraout_var_00;
    }
    *(undefined1 *)(param_1 + 0xb0) = 0;
    uVar10 = rdtsc();
    param_1[0xb9] =
         (param_1[0xb9] - (longlong)plVar6) +
         (CONCAT44(uVar8,(int)uVar10) | uVar10 & 0xffffffff00000000);
  }
  InpTransitionRunningQueue(param_1,'\x01',iVar4);
  return;
}



===== KmclDiscountOldDpcCycles @ 140001a50 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void KmclDiscountOldDpcCycles(longlong param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  ulonglong uVar3;
  
  lVar2 = _DAT_fffff78000000320;
  uVar3 = _DAT_fffff78000000320 - *(longlong *)(param_1 + 0x5c0);
  if (uVar3 == 0) {
    return;
  }
  if (0xf < uVar3) {
    *(undefined8 *)(param_1 + 0x5c8) = 0;
    *(longlong *)(param_1 + 0x5c0) = lVar2;
    return;
  }
  uVar1 = *(ulonglong *)(param_1 + 0x5c8);
  if (uVar3 == 1) {
    *(ulonglong *)(param_1 + 0x5c8) = uVar1 - (uVar1 >> 4);
  }
  else {
    *(ulonglong *)(param_1 + 0x5c8) = (0x10 - uVar3) * uVar1 >> 4;
  }
  *(longlong *)(param_1 + 0x5c0) = lVar2;
  return;
}



===== InpProcessingDpcRoutine @ 140001ad0 =====

void InpProcessingDpcRoutine(longlong *param_1,longlong *param_2,uint *param_3,ulonglong param_4)

{
  ulonglong uVar1;
  undefined7 uVar2;
  uint *puVar3;
  
  uVar2 = (undefined7)((ulonglong)param_2 >> 8);
  puVar3 = param_3;
  KeAcquireSpinLockAtDpcLevel(param_2 + 0x88);
  if (param_1 == param_2 + 0xbb) {
    *(undefined4 *)(param_2 + 0xcc) = 0xffffffff;
  }
  else {
    *(undefined4 *)((longlong)param_2 + 0x664) = 0xffffffff;
  }
  uVar1 = InpWorkerTakeProcessingOwnershipLocked(param_2);
  KeReleaseSpinLockFromDpcLevel(param_2 + 0x88);
  if ((char)uVar1 != '\0') {
    InpRunQueueAtDpcLevel(param_2,CONCAT71(uVar2,param_3 != (uint *)0x0),puVar3,param_4);
  }
  return;
}



===== InpWorkerTakeProcessingOwnershipLocked @ 140001b80 =====

ulonglong InpWorkerTakeProcessingOwnershipLocked(longlong *param_1)

{
  undefined2 uVar1;
  longlong lVar2;
  code *pcVar3;
  void *pvVar4;
  char cVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined1 *puVar8;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [56];
  
  puVar8 = auStack_48;
  if (*(int *)((longlong)param_1 + 0x48c) == 0) {
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(0xe);
    puVar8 = auStack_40;
  }
  else {
    uVar6 = *(int *)((longlong)param_1 + 0x48c) - 1;
    uVar7 = (ulonglong)uVar6;
    *(uint *)((longlong)param_1 + 0x48c) = uVar6;
    if ((int)param_1[0x89] == 2) {
      *(undefined4 *)(param_1 + 0x89) = 1;
      pvVar4 = SystemReserved1[0xf];
      param_1[0x8d] = (longlong)SystemReserved1[0xf];
      return CONCAT71((int7)((ulonglong)pvVar4 >> 8),1);
    }
    if (uVar6 != 0) goto LAB_140001bcb;
  }
  if (4 < DAT_140020050) {
    *(undefined8 *)(puVar8 + -8) = 0x140001bf0;
    cVar5 = _tlgKeywordOn(0x140020050,4);
    if (cVar5 != '\0') {
      lVar2 = *param_1;
      *(char **)(puVar8 + 0x38) = "Setting StopEvent";
      *(undefined4 *)(puVar8 + 0x30) = *(undefined4 *)(lVar2 + 0x8a8);
      *(undefined4 *)(puVar8 + 0x28) = *(undefined4 *)(lVar2 + 0x89c);
      uVar1 = *(undefined2 *)(lVar2 + 0xc90);
      *(undefined4 *)(puVar8 + 0x20) = *(undefined4 *)(lVar2 + 0x898);
      *(undefined8 *)(puVar8 + -8) = 0x140001c44;
      VmbusTraceInfoRundownEvent
                ("InpWorkerTakeProcessingOwnershipLocked",0x11b4,lVar2 + 0x6ec,uVar1,
                 *(uint *)(puVar8 + 0x20),*(int *)(puVar8 + 0x28),*(undefined4 *)(puVar8 + 0x30),
                 *(char **)(puVar8 + 0x38));
    }
  }
  lVar2 = param_1[0x98];
  *(undefined8 *)(puVar8 + -8) = 0x140001c57;
  uVar7 = KeSetEvent(lVar2,0,0);
  param_1[0x98] = 0;
LAB_140001bcb:
  return uVar7 & 0xffffffffffffff00;
}



===== InpRunQueueAtDpcLevel @ 140001c80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void InpRunQueueAtDpcLevel(longlong *param_1,ulonglong param_2,uint *param_3,ulonglong param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  char cVar3;
  int iVar4;
  undefined8 uVar5;
  longlong *plVar6;
  longlong *plVar7;
  undefined4 uVar8;
  undefined4 extraout_var_00;
  undefined4 extraout_var_01;
  undefined7 extraout_var;
  undefined4 extraout_var_02;
  undefined4 extraout_var_03;
  undefined4 extraout_var_04;
  undefined4 *puVar9;
  ulonglong uVar10;
  int iVar11;
  uint uVar12;
  undefined1 auStackY_88 [32];
  uint local_48;
  uint local_44;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined4 local_30;
  ulonglong local_28;
  
  lVar1 = _DAT_fffff78000000320;
  local_28 = __security_cookie ^ (ulonglong)auStackY_88;
  if (param_1[0xba] == -1) {
    uVar10 = InpFillAndProcessQueue(param_1,CONCAT71((int7)(param_2 >> 8),2),(uint *)0x1e);
    iVar4 = (int)uVar10;
  }
  else {
    uVar12 = 0;
    if (((char)param_2 == '\0') && (param_2 = _DAT_fffff78000000320 - param_1[0xb8], param_2 != 0))
    {
      if (param_2 < 0x10) {
        uVar10 = param_1[0xb9];
        if (param_2 == 1) {
          param_4 = uVar10 - (uVar10 >> 4);
        }
        else {
          param_4 = uVar10 * (0x10 - param_2) >> 4;
        }
        param_1[0xb9] = param_4;
        param_1[0xb8] = lVar1;
      }
      else {
        param_1[0xb9] = 0;
        param_4 = 0;
        param_1[0xb8] = lVar1;
      }
    }
    if ((ulonglong)param_1[0xba] <= (ulonglong)param_1[0xb9]) {
LAB_140001eed:
      KeAcquireSpinLockAtDpcLevel(param_1 + 0x88);
      if (((int)param_1[0x89] == 1) && (param_1[0x98] != 0)) {
        if ((4 < DAT_140020050) && (cVar3 = _tlgKeywordOn(0x140020050,4), cVar3 != '\0')) {
          lVar1 = *param_1;
          VmbusTraceInfoRundownEvent
                    ("InpPrepareToQueueWorkerLocked",0x1205,lVar1 + 0x6ec,
                     *(undefined2 *)(lVar1 + 0xc90),*(uint *)(lVar1 + 0x898),*(int *)(lVar1 + 0x89c)
                     ,*(undefined4 *)(lVar1 + 0x8a8),"Setting StopEvent");
        }
        param_3 = (uint *)0x0;
        KeSetEvent(param_1[0x98],0);
        param_1[0x98] = 0;
        param_1[0x8d] = 0;
      }
      else {
        *(undefined4 *)(param_1 + 0x89) = 2;
        param_1[0x8d] = 0;
        iVar4 = SystemReserved1[0x12]._4_4_;
        if (((param_1[0x8e] == 0) &&
            ((((int)param_1[0xcc] != SystemReserved1[0x12]._4_4_ &&
              (*(int *)((longlong)param_1 + 0x664) != SystemReserved1[0x12]._4_4_)) &&
             ((int)param_1[0xcd] == -1)))) && (SystemReserved1[0x12]._4_4_ != -1)) {
          *(byte *)((longlong)param_1 + 0x44c) = *(byte *)((longlong)param_1 + 0x44c) | 2;
          param_1[0x94] = param_1[0x94] + 1;
          *(int *)((longlong)param_1 + 0x48c) = *(int *)((longlong)param_1 + 0x48c) + 1;
          *(int *)(param_1 + 0xcd) = iVar4;
          param_1[0x8e] = param_1[0xcb];
        }
      }
      InpReleaseLockAndPerformWork(param_1);
      *(int *)((longlong)param_1 + 0x534) = *(int *)((longlong)param_1 + 0x534) + 1;
      if ((Microsoft_Windows_Hyper_V_KMCLEnableBits & 4) == 0) {
        return;
      }
      lVar1 = *param_1;
      McTemplateK0jjh_EtwWriteTransfer
                (lVar1 + 0xa90,&VMBUS_HIT_DPC_LIMIT,param_3,lVar1 + 0xaa0,lVar1 + 0xa90,
                 (char)*(undefined2 *)(lVar1 + 0xc90));
      return;
    }
    local_40 = 0;
    uStack_38 = 0;
    local_30 = 0;
    uVar5 = KeQueryDpcWatchdogInformation(&local_40,param_2,param_3,param_4);
    if (-1 < (int)uVar5) {
      uVar5 = 0;
      if (uStack_38._4_4_ < (uint)((int)uStack_38 * 0x1e) / 100) goto LAB_140001eed;
    }
    uVar2 = rdtsc();
    uVar10 = uVar2 & 0xffffffff00000000;
    plVar6 = (longlong *)(CONCAT44((int)((ulonglong)uVar5 >> 0x20),(int)uVar2) | uVar10);
    *(undefined1 *)(param_1 + 0xb0) = 1;
    local_44 = 0;
    local_48 = 0;
    plVar7 = plVar6;
    if (5 < DAT_140020050) {
      uVar10 = 1;
      puVar9 = &DAT_140020050;
      cVar3 = _tlgKeywordOn(0x140020050,1);
      plVar7 = (longlong *)CONCAT71(extraout_var,cVar3);
      if (cVar3 != '\0') {
        param_3 = (uint *)(*param_1 + 0x6ec);
        plVar7 = (longlong *)
                 VmbusTraceVerbPacketFetchStart
                           (puVar9,uVar10,param_3,(ulonglong)*(ushort *)(*param_1 + 0xc90),2);
      }
    }
    iVar11 = 0;
    do {
      if (0x1d < uVar12) {
LAB_140001ee3:
        iVar4 = 1;
        break;
      }
      if (param_1[0x98] != 0) {
        iVar4 = 7;
        break;
      }
      plVar7 = param_1 + 0xa0;
      if ((longlong *)*plVar7 == plVar7) {
        param_3 = &local_48;
        plVar7 = (longlong *)InpFillQueue(param_1,uVar10,param_3);
        iVar11 = iVar11 + local_48;
        iVar4 = (int)plVar7;
        if (iVar4 != 1) break;
      }
      if (*(char *)((longlong)param_1 + 0x4b1) != '\0') goto LAB_140001ee3;
      param_3 = (uint *)(ulonglong)(0x1e - uVar12);
      uVar10 = CONCAT71((int7)(uVar10 >> 8),2);
      plVar7 = (longlong *)InpProcessQueue(param_1,'\x02',0x1e - uVar12,&local_44);
      uVar12 = uVar12 + local_44;
      iVar4 = (int)plVar7;
    } while (iVar4 == 1);
    uVar8 = (undefined4)((ulonglong)plVar7 >> 0x20);
    if (uVar12 != 0) {
      lVar1 = *param_1;
      if (*(char *)(lVar1 + 0x7c8) == '\0') {
        uVar10 = (ulonglong)uVar12;
        (**(code **)(lVar1 + 0x7d8))();
        uVar8 = extraout_var_01;
      }
      else {
        uVar10 = *(ulonglong *)(lVar1 + 0x7e0);
        param_3 = (uint *)(ulonglong)uVar12;
        (**(code **)(lVar1 + 0x7d8))();
        uVar8 = extraout_var_02;
      }
    }
    if (5 < DAT_140020050) {
      uVar10 = 1;
      puVar9 = &DAT_140020050;
      cVar3 = _tlgKeywordOn(0x140020050,1);
      uVar8 = extraout_var_03;
      if (cVar3 != '\0') {
        param_3 = (uint *)(*param_1 + 0x6ec);
        VmbusTraceVerbPacketFetchStop
                  (puVar9,uVar10,param_3,(ulonglong)*(ushort *)(*param_1 + 0xc90),iVar11,uVar12);
        uVar8 = extraout_var_04;
      }
    }
    if ((Microsoft_Windows_Hyper_V_KMCLEnableBits & 1) != 0) {
      lVar1 = *param_1;
      McTemplateK0jjqqh_EtwWriteTransfer
                (lVar1 + 0xa90,uVar10,param_3,lVar1 + 0xaa0,lVar1 + 0xa90,(char)uVar12,0x1e,
                 (char)*(undefined2 *)(lVar1 + 0xc90));
      uVar8 = extraout_var_00;
    }
    *(undefined1 *)(param_1 + 0xb0) = 0;
    uVar10 = rdtsc();
    param_1[0xb9] =
         (param_1[0xb9] - (longlong)plVar6) +
         (CONCAT44(uVar8,(int)uVar10) | uVar10 & 0xffffffff00000000);
  }
  InpTransitionRunningQueue(param_1,'\x01',iVar4);
  return;
}



===== InpFillAndProcessQueue @ 140002140 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong InpFillAndProcessQueue(longlong *param_1,ulonglong param_2,uint *param_3)

{
  longlong lVar1;
  char cVar2;
  char cVar3;
  ulonglong uVar4;
  undefined4 *puVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  int iVar11;
  uint local_res10 [2];
  uint local_res18 [4];
  
  uVar8 = 0;
  cVar3 = (char)param_2;
  local_res18[0] = 0;
  local_res10[0] = 0;
  *(bool *)(param_1 + 0xb0) = cVar3 == '\x02';
  uVar6 = param_2;
  puVar10 = param_3;
  if (5 < DAT_140020050) {
    uVar6 = 1;
    puVar5 = &DAT_140020050;
    cVar2 = _tlgKeywordOn(0x140020050,1);
    if (cVar2 != '\0') {
      puVar10 = (uint *)(*param_1 + 0x6ec);
      VmbusTraceVerbPacketFetchStart
                (puVar5,uVar6,puVar10,(ulonglong)*(ushort *)(*param_1 + 0xc90),
                 (ushort)param_2 & 0xff);
    }
  }
  iVar11 = 0;
  do {
    if ((uint)param_3 <= uVar8) {
LAB_1400022a1:
      uVar7 = 1;
      goto LAB_1400021c1;
    }
    if (param_1[0x98] != 0) {
      uVar7 = 7;
      goto LAB_1400021c1;
    }
    if ((longlong *)param_1[0xa0] == param_1 + 0xa0) {
      puVar10 = local_res10;
      uVar4 = InpFillQueue(param_1,uVar6,puVar10);
      iVar11 = iVar11 + local_res10[0];
      uVar7 = uVar4 & 0xffffffff;
      if ((int)uVar4 != 1) goto LAB_1400021c1;
    }
    if ((*(char *)((longlong)param_1 + 0x4b1) != '\0') && (cVar3 != '\0')) goto LAB_1400022a1;
    uVar9 = (uint)param_3 - uVar8;
    puVar10 = (uint *)(ulonglong)uVar9;
    uVar6 = param_2 & 0xff;
    uVar4 = InpProcessQueue(param_1,cVar3,uVar9,local_res18);
    uVar8 = uVar8 + local_res18[0];
    uVar7 = uVar4 & 0xffffffff;
    if ((int)uVar4 != 1) {
LAB_1400021c1:
      if (uVar8 != 0) {
        lVar1 = *param_1;
        if (*(char *)(lVar1 + 0x7c8) == '\0') {
          uVar6 = (ulonglong)uVar8;
          (**(code **)(lVar1 + 0x7d8))();
        }
        else {
          uVar6 = *(ulonglong *)(lVar1 + 0x7e0);
          puVar10 = (uint *)(ulonglong)uVar8;
          (**(code **)(lVar1 + 0x7d8))();
        }
      }
      if (5 < DAT_140020050) {
        uVar6 = 1;
        puVar5 = &DAT_140020050;
        cVar3 = _tlgKeywordOn(0x140020050,1);
        if (cVar3 != '\0') {
          puVar10 = (uint *)(*param_1 + 0x6ec);
          VmbusTraceVerbPacketFetchStop
                    (puVar5,uVar6,puVar10,(ulonglong)*(ushort *)(*param_1 + 0xc90),iVar11,uVar8);
        }
      }
      if ((Microsoft_Windows_Hyper_V_KMCLEnableBits & 1) != 0) {
        lVar1 = *param_1;
        McTemplateK0jjqqh_EtwWriteTransfer
                  (lVar1 + 0xa90,uVar6,puVar10,lVar1 + 0xaa0,lVar1 + 0xa90,(char)uVar8,(char)param_3
                   ,(char)*(undefined2 *)(lVar1 + 0xc90));
      }
      *(undefined1 *)(param_1 + 0xb0) = 0;
      return uVar7;
    }
  } while( true );
}



===== VmbChannelPollRingBuffer @ 140002340 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong VmbChannelPollRingBuffer(longlong *param_1,undefined8 param_2,uint *param_3)

{
  longlong lVar1;
  bool bVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined4 *puVar8;
  ulonglong uVar9;
  uint uVar10;
  uint uVar11;
  ulonglong uVar12;
  int iVar13;
  bool bVar14;
  uint local_res8 [2];
  uint local_res10 [2];
  
                    /* 0x2340  61  VmbChannelPollRingBuffer */
  bVar2 = false;
  bVar14 = false;
  bVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x88);
  iVar13 = (int)param_1[0x89];
  uVar12 = (ulonglong)bVar3;
  if (iVar13 == 3) {
    bVar14 = true;
    if (*(char *)((longlong)param_1 + 0x4b1) != '\0') {
      bVar2 = true;
      *(undefined1 *)((longlong)param_1 + 0x4b1) = 0;
    }
    goto LAB_14000238b;
  }
  if (iVar13 == 1) {
    *(byte *)(param_1 + 0x8c) = *(byte *)(param_1 + 0x8c) | 1;
    uVar6 = KeReleaseSpinLock(param_1 + 0x88,uVar12);
    goto LAB_1400024af;
  }
  if (iVar13 == 4) {
    bVar14 = *(int *)((longlong)param_1 + 0x84) != *(int *)param_1[0xb];
    if (bVar14) goto LAB_14000238b;
  }
  else if (iVar13 == 7) {
    bVar14 = true;
LAB_14000238b:
    *(undefined4 *)(param_1 + 0x89) = 1;
    param_1[0x8d] = (longlong)SystemReserved1[0xf];
  }
  uVar9 = uVar12;
  uVar6 = KeReleaseSpinLock(param_1 + 0x88);
  if (bVar14) {
    uVar10 = 200;
    if (bVar3 != 0) {
      uVar10 = 0x1e;
    }
    uVar11 = 0;
    local_res10[0] = 0;
    local_res8[0] = 0;
    *(bool *)(param_1 + 0xb0) = bVar3 == 2;
    if (5 < DAT_140020050) {
      uVar9 = 1;
      puVar8 = &DAT_140020050;
      cVar4 = _tlgKeywordOn(0x140020050,1);
      if (cVar4 != '\0') {
        param_3 = (uint *)(*param_1 + 0x6ec);
        VmbusTraceVerbPacketFetchStart
                  (puVar8,uVar9,param_3,(ulonglong)*(ushort *)(*param_1 + 0xc90),(ushort)bVar3);
      }
    }
    iVar13 = 0;
    do {
      if (uVar10 <= uVar11) {
LAB_140002583:
        iVar5 = 1;
        break;
      }
      if (param_1[0x98] != 0) {
        iVar5 = 7;
        break;
      }
      if ((longlong *)param_1[0xa0] == param_1 + 0xa0) {
        param_3 = local_res8;
        uVar6 = InpFillQueue(param_1,uVar9,param_3);
        iVar13 = iVar13 + local_res8[0];
        iVar5 = (int)uVar6;
        if (iVar5 != 1) break;
      }
      if ((*(char *)((longlong)param_1 + 0x4b1) != '\0') && (bVar3 != 0)) goto LAB_140002583;
      param_3 = (uint *)(ulonglong)(uVar10 - uVar11);
      uVar9 = uVar12;
      uVar7 = InpProcessQueue(param_1,bVar3,uVar10 - uVar11,local_res10);
      uVar11 = uVar11 + local_res10[0];
      iVar5 = (int)uVar7;
    } while (iVar5 == 1);
    if (uVar11 != 0) {
      lVar1 = *param_1;
      if (*(char *)(lVar1 + 0x7c8) == '\0') {
        uVar9 = (ulonglong)uVar11;
        (**(code **)(lVar1 + 0x7d8))();
      }
      else {
        uVar9 = *(ulonglong *)(lVar1 + 0x7e0);
        param_3 = (uint *)(ulonglong)uVar11;
        (**(code **)(lVar1 + 0x7d8))();
      }
    }
    if (5 < DAT_140020050) {
      uVar9 = 1;
      puVar8 = &DAT_140020050;
      cVar4 = _tlgKeywordOn(0x140020050,1);
      if (cVar4 != '\0') {
        param_3 = (uint *)(*param_1 + 0x6ec);
        VmbusTraceVerbPacketFetchStop
                  (puVar8,uVar9,param_3,(ulonglong)*(ushort *)(*param_1 + 0xc90),iVar13,uVar11);
      }
    }
    if ((Microsoft_Windows_Hyper_V_KMCLEnableBits & 1) != 0) {
      lVar1 = *param_1;
      McTemplateK0jjqqh_EtwWriteTransfer
                (lVar1 + 0xa90,uVar9,param_3,lVar1 + 0xaa0,lVar1 + 0xa90,(char)uVar11,(char)uVar10,
                 (char)*(undefined2 *)(lVar1 + 0xc90));
    }
    *(undefined1 *)(param_1 + 0xb0) = 0;
    if (bVar2) {
      *(undefined1 *)((longlong)param_1 + 0x4b1) = 1;
    }
    uVar6 = InpTransitionRunningQueue(param_1,'\0',iVar5);
    if ((iVar5 == 1) || (uVar6 = (ulonglong)(iVar5 - 5U), iVar5 - 5U < 3)) {
      return CONCAT71((int7)(uVar6 >> 8),1);
    }
  }
LAB_1400024af:
  return uVar6 & 0xffffffffffffff00;
}



===== InpFillQueue @ 140002690 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong InpFillQueue(longlong *param_1,undefined8 param_2,uint *param_3)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  longlong *plVar5;
  longlong *plVar6;
  code *pcVar7;
  uint uVar8;
  uint uVar9;
  undefined8 uVar10;
  uint uVar11;
  undefined1 uVar12;
  char cVar13;
  longlong lVar14;
  undefined8 *puVar15;
  undefined8 uVar16;
  ulonglong uVar17;
  uint uVar18;
  uint uVar19;
  uint *puVar20;
  undefined1 *puVar21;
  undefined1 *puVar22;
  uint uVar23;
  uint *puVar24;
  undefined1 unaff_R12B;
  int iVar25;
  undefined *puVar26;
  undefined1 auStackY_448 [8];
  undefined1 auStackY_440 [24];
  undefined2 local_404 [2];
  undefined2 local_400 [2];
  undefined2 local_3fc [2];
  ushort local_3f8 [2];
  ushort local_3f4 [2];
  ushort local_3f0 [2];
  uint local_3ec;
  uint local_3e8;
  undefined4 local_3e4;
  undefined4 local_3e0;
  undefined4 local_3dc;
  undefined4 local_3d8;
  undefined4 local_3d4;
  undefined4 local_3d0 [2];
  longlong local_3c8;
  ulonglong local_3c0;
  uint *local_3b8;
  uint local_3b0;
  undefined4 local_3ac;
  undefined8 local_3a8;
  uint local_3a0;
  undefined4 local_39c;
  undefined8 local_398;
  uint local_390;
  undefined4 local_38c;
  undefined8 local_388;
  uint local_380;
  undefined4 local_37c;
  undefined8 local_378;
  uint local_370;
  undefined4 local_36c;
  undefined8 local_368;
  uint local_360;
  undefined4 local_35c;
  undefined8 local_358;
  undefined8 local_348;
  undefined8 uStack_340;
  undefined8 local_338;
  undefined8 uStack_330;
  undefined *local_328;
  uint local_320;
  undefined4 local_31c;
  undefined *local_318;
  undefined4 local_310;
  undefined4 local_30c;
  char *local_308;
  undefined8 local_300;
  undefined4 *local_2f8;
  undefined8 local_2f0;
  longlong local_2e8;
  undefined8 local_2e0;
  ushort *local_2d8;
  undefined8 local_2d0;
  char *local_2c8;
  undefined8 local_2c0;
  undefined *local_2b8;
  uint local_2b0;
  undefined4 local_2ac;
  undefined *local_2a8;
  undefined4 local_2a0;
  undefined4 local_29c;
  char *local_298;
  undefined8 local_290;
  undefined4 *local_288;
  undefined8 local_280;
  longlong local_278;
  undefined8 local_270;
  undefined2 *local_268;
  undefined8 local_260;
  char *local_258;
  undefined8 local_250;
  undefined *local_248;
  uint local_240;
  undefined4 local_23c;
  undefined *local_238;
  undefined4 local_230;
  undefined4 local_22c;
  char *local_228;
  undefined8 local_220;
  undefined4 *local_218;
  undefined8 local_210;
  longlong local_208;
  undefined8 local_200;
  undefined2 *local_1f8;
  undefined8 local_1f0;
  char *local_1e8;
  undefined8 local_1e0;
  char *local_1d8;
  undefined8 local_1d0;
  undefined *local_1c8;
  uint local_1c0;
  undefined4 local_1bc;
  undefined *local_1b8;
  undefined4 local_1b0;
  undefined4 local_1ac;
  char *local_1a8;
  undefined8 local_1a0;
  undefined4 *local_198;
  undefined8 local_190;
  longlong local_188;
  undefined8 local_180;
  undefined2 *local_178;
  undefined8 local_170;
  char *local_168;
  undefined8 local_160;
  char *local_158;
  undefined8 local_150;
  undefined *local_148;
  uint local_140;
  undefined4 local_13c;
  undefined *local_138;
  undefined4 local_130;
  undefined4 local_12c;
  char *local_128;
  undefined8 local_120;
  undefined4 *local_118;
  undefined8 local_110;
  longlong local_108;
  undefined8 local_100;
  ushort *local_f8;
  undefined8 local_f0;
  char *local_e8;
  undefined8 local_e0;
  char *local_d8;
  undefined8 local_d0;
  undefined *local_c8;
  uint local_c0;
  undefined4 local_bc;
  undefined *local_b8;
  undefined4 local_b0;
  undefined4 local_ac;
  char *local_a8;
  undefined8 local_a0;
  undefined4 *local_98;
  undefined8 local_90;
  longlong local_88;
  undefined8 local_80;
  ushort *local_78;
  undefined8 local_70;
  char *local_68;
  undefined8 local_60;
  char *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_448;
  uVar23 = *(uint *)((longlong)param_1 + 0x84);
  iVar25 = 0;
  local_3c0 = 0;
  local_3c8 = 0;
  local_338 = 0;
  uStack_330 = 0;
  local_3e8 = uVar23;
  local_3b8 = param_3;
  uVar12 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x58);
  puVar21 = auStackY_448;
  local_3ec = 0;
  local_404[0] = CONCAT11(local_404[0]._1_1_,uVar12);
  do {
    uVar11 = local_3ec;
    uVar18 = *(uint *)(param_1 + 0x10);
    uVar19 = *(uint *)(param_1 + 0xd);
    puVar20 = (uint *)(ulonglong)uVar19;
    puVar26 = &_TraceLoggingMetadata;
    local_348 = 0;
    uStack_340 = 0;
    if (uVar18 == uVar23) {
      uVar18 = *(uint *)param_1[0xb];
      if ((uVar18 < uVar19) && ((uVar18 & 7) == 0)) {
        *(uint *)(param_1 + 0x10) = uVar18;
        if (uVar18 != uVar23) goto LAB_140002757;
        puVar26 = (undefined *)0x4;
      }
      else {
LAB_140002e3d:
        param_1[0xaf] = 4;
        if (2 < DAT_140020050) {
          uVar1 = *(ushort *)(*param_1 + 0xc90);
          puVar20 = (uint *)(ulonglong)uVar1;
          if (2 < DAT_140020050) {
            local_a8 = "InpGetNextPacket";
            local_78 = local_3f0;
            local_98 = &local_3d4;
            local_68 = "InFailedCorruptRingBuffer";
            puVar20 = &local_370;
            local_a0 = 0x11;
            local_58 = "InFailedPacketPreProcess";
            local_36c = 2;
            local_c8 = PTR_DAT_140020058;
            local_3d4 = 0x4ea;
            local_90 = 4;
            local_80 = 0x10;
            local_70 = 2;
            local_60 = 0x1a;
            local_50 = 0x19;
            local_370 = 0xb000000;
            local_368 = 0;
            local_c0 = (uint)*(ushort *)PTR_DAT_140020058;
            local_b8 = &DAT_14001d5f6;
            local_bc = 2;
            local_b0 = 0x5e;
            local_ac = 1;
            local_3f0[0] = uVar1;
            local_88 = *param_1 + 0x6ec;
LAB_140002f79:
            param_3 = (uint *)0x0;
            EtwWriteTransfer(DAT_140020070,puVar20,0,0);
          }
        }
LAB_140002f9f:
        puVar26 = (undefined *)0xb;
      }
      goto LAB_140002fa5;
    }
LAB_140002757:
    uVar18 = uVar18 - uVar23;
    if (uVar19 <= uVar18) {
      uVar18 = uVar18 + uVar19;
    }
    puVar24 = (uint *)((ulonglong)uVar23 + param_1[0xc]);
    uVar9 = *puVar24;
    uVar16 = *(undefined8 *)puVar24;
    local_348 = *(undefined8 *)puVar24;
    uVar10 = *(undefined8 *)(puVar24 + 2);
    uStack_340 = *(undefined8 *)(puVar24 + 2);
    param_3 = (uint *)((ulonglong)(ushort)puVar24[1] * 8);
    uVar8 = (uint)param_3;
    if ((uVar8 < 0x10) || (uVar18 < uVar8 + 8)) goto LAB_140002e3d;
    uVar18 = uVar8 + 8 + uVar23;
    local_338._2_2_ = (short)(uVar9 >> 0x10);
    uVar23 = uVar18 - uVar19;
    if (uVar18 < uVar19) {
      uVar23 = uVar18;
    }
    uVar18 = local_338._2_2_ * 8;
    puVar20 = (uint *)(ulonglong)uVar18;
    local_338 = uVar16;
    uStack_330 = uVar10;
    if ((uVar8 < uVar18) || (uVar18 < 0x10)) {
      param_1[0xaf] = 0;
      if (2 < DAT_140020050) {
        uVar1 = *(ushort *)(*param_1 + 0xc90);
        puVar20 = (uint *)(ulonglong)uVar1;
        if (2 < DAT_140020050) {
          local_128 = "InpGetNextPacket";
          local_f8 = local_3f4;
          local_118 = &local_3d8;
          local_e8 = "InFailedMalformedPacket";
          puVar20 = &local_380;
          local_120 = 0x11;
          local_d8 = "InFailedPacketPreProcess";
          local_37c = 2;
          local_148 = PTR_DAT_140020058;
          local_3d8 = 0x4f4;
          local_110 = 4;
          local_100 = 0x10;
          local_f0 = 2;
          local_e0 = 0x18;
          local_d0 = 0x19;
          local_380 = 0xb000000;
          local_378 = 0;
          local_140 = (uint)*(ushort *)PTR_DAT_140020058;
          local_138 = &DAT_14001d5f6;
          local_13c = 2;
          local_130 = 0x5e;
          local_12c = 1;
          local_3f4[0] = uVar1;
          local_108 = *param_1 + 0x6ec;
          goto LAB_140002f79;
        }
      }
      goto LAB_140002f9f;
    }
    uVar19 = uVar9 & 0xffff;
    if (((uVar19 != 6) && (uVar19 != 7)) && (uVar19 != 9)) {
      if ((uVar19 == 10) || (uVar19 != 0xb)) {
        param_1[0xaf] = 3;
        if (DAT_140020050 < 3) goto LAB_140002f9f;
        local_3fc[0] = *(undefined2 *)(*param_1 + 0xc90);
        local_188 = *param_1 + 0x6ec;
        local_1a8 = "InpFillQueue";
        puVar20 = &local_3a0;
        local_198 = &local_3e0;
        local_1a0 = 0xd;
        local_178 = local_3fc;
        local_168 = "InFailedInvalidPacketType";
        local_158 = "InFailedPacketPreProcess";
        local_39c = 2;
        local_1c8 = PTR_DAT_140020058;
        local_3e0 = 0x69e;
        local_190 = 4;
        local_180 = 0x10;
        local_170 = 2;
        local_160 = 0x1a;
        local_150 = 0x19;
        local_3a0 = 0xb000000;
        local_398 = 0;
        local_1c0 = (uint)*(ushort *)PTR_DAT_140020058;
        local_1b8 = &DAT_14001d5f6;
        local_1bc = 2;
        local_1b0 = 0x5e;
        local_1ac = 1;
        goto LAB_140002f79;
      }
      param_3 = (uint *)(ulonglong)uVar18;
      lVar14 = InpPreprocessCompletionPacketLocked
                         (param_1,puVar24,uVar18,uVar8,&local_338,&local_3c0);
      if (lVar14 == 0) {
        param_1[0xaf] = 2;
        puVar20 = puVar24;
        if (2 < DAT_140020050) {
          local_400[0] = *(undefined2 *)(*param_1 + 0xc90);
          local_208 = *param_1 + 0x6ec;
          local_228 = "InpFillQueue";
          puVar20 = &local_3b0;
          local_218 = &local_3e4;
          local_220 = 0xd;
          local_1f8 = local_400;
          local_1e8 = "InFailedMalformedOrOrphanCompletionPacket";
          local_1d8 = "InFailedPacketPreProcess";
          local_3ac = 2;
          local_248 = PTR_DAT_140020058;
          local_3e4 = 0x686;
          local_210 = 4;
          local_200 = 0x10;
          local_1f0 = 2;
          local_1e0 = 0x2a;
          local_1d0 = 0x19;
          local_3b0 = 0xb000000;
          local_3a8 = 0;
          local_240 = (uint)*(ushort *)PTR_DAT_140020058;
          local_238 = &DAT_14001d5f6;
          local_23c = 2;
          local_230 = 0x5e;
          local_22c = 1;
          goto LAB_140002f79;
        }
        goto LAB_140002f9f;
      }
      puVar20 = (uint *)(param_1 + 0xa2);
      puVar15 = (undefined8 *)(lVar14 + 0xb0);
      param_3 = (uint *)param_1[0xa3];
      if (*(uint **)param_3 == puVar20) {
        *puVar15 = puVar20;
        *(uint **)(lVar14 + 0xb8) = param_3;
        *(undefined8 **)param_3 = puVar15;
        goto LAB_1400028be;
      }
      goto LAB_14000335a;
    }
    if (*(uint *)((longlong)param_1 + 0x574) <= (uint)((int)param_1[0xa4] - (int)param_1[0x8f])) {
      param_1[0xa7] = param_1[0xa7] + 1;
      puVar26 = (undefined *)0x5;
      puVar20 = (uint *)(ulonglong)DAT_140020050;
      if (((4 < DAT_140020050) && (((byte)DAT_140020060 & 2) != 0)) &&
         (((uint)DAT_140020068 & 2) == DAT_140020068)) {
        uVar1 = *(ushort *)(*param_1 + 0xc90);
        param_3 = (uint *)(ulonglong)uVar1;
        if ((4 < DAT_140020050) && (((uint)DAT_140020068 & 2) == DAT_140020068)) {
          local_308 = "InpFillQueue";
          local_2f8 = &local_3dc;
          puVar20 = &local_390;
          local_300 = 0xd;
          local_2d8 = local_3f8;
          local_3dc = 0x64a;
          local_2c8 = "Pause";
          param_3 = (uint *)0x0;
          local_38c = 4;
          local_328 = PTR_DAT_140020058;
          local_2f0 = 4;
          local_2e0 = 0x10;
          local_2d0 = 2;
          local_2c0 = 6;
          local_390 = 0xb000000;
          local_388 = 2;
          local_320 = (uint)*(ushort *)PTR_DAT_140020058;
          local_318 = &DAT_14001dc0c;
          local_31c = 2;
          local_310 = 0x52;
          local_30c = 1;
          local_3f8[0] = uVar1;
          local_2e8 = *param_1 + 0x6ec;
          EtwWriteTransfer(DAT_140020070,puVar20,0,0);
        }
      }
      if ((Microsoft_Windows_Hyper_V_KMCLEnableBits & 4) != 0) {
        lVar14 = *param_1;
        puVar20 = (uint *)&VMBUS_HIT_INCOMING_QUOTA;
        McTemplateK0jjh_EtwWriteTransfer
                  (lVar14 + 0xa90,&VMBUS_HIT_INCOMING_QUOTA,param_3,lVar14 + 0xaa0,lVar14 + 0xa90,
                   (char)*(undefined2 *)(lVar14 + 0xc90));
      }
      goto LAB_140002fa5;
    }
    local_3c8 = 0;
    puVar20 = (uint *)(ulonglong)(uVar9 & 0xffff);
    uVar17 = InpBuildDeferredDataPacket
                       (param_1,uVar9 & 0xffff,(undefined8 *)puVar24,uVar18,uVar8,&local_3c8,
                        &local_338);
    puVar26 = (undefined *)(uVar17 & 0xffffffff);
    param_3 = puVar24;
    if ((int)uVar17 != 1) goto LAB_140002fa5;
    puVar20 = (uint *)param_1[0xa3];
    param_3 = (uint *)(param_1 + 0xa2);
    puVar15 = (undefined8 *)(local_3c8 + 0x68);
    if (*(uint **)puVar20 != param_3) goto LAB_14000335a;
    *puVar15 = param_3;
    *(uint **)(local_3c8 + 0x70) = puVar20;
    *(undefined8 **)puVar20 = puVar15;
LAB_1400028be:
    local_3ec = uVar11 + 1;
    param_1[0xa3] = (longlong)puVar15;
    *(int *)(param_1 + 0xa6) = (int)param_1[0xa6] + 1;
    local_3e8 = uVar23;
  } while (local_3ec < 0x40);
  puVar26 = (undefined *)0x1;
LAB_140002fa5:
  for (plVar5 = (longlong *)param_1[0xa2]; plVar5 != param_1 + 0xa2; plVar5 = (longlong *)*plVar5) {
    puVar24 = (uint *)(ulonglong)*(uint *)(plVar5 + 5);
    puVar20 = (uint *)plVar5[4];
    if ((short)plVar5[2] == 0xb) {
      puVar20 = (uint *)((longlong)puVar20 + (longlong)puVar24);
      puVar24 = param_3;
      if (*(uint *)((longlong)plVar5 + -0x3c) != 0) {
        puVar24 = (uint *)(ulonglong)*(uint *)((longlong)plVar5 + -0x3c);
        memmove((void *)plVar5[-9],puVar20,(size_t)puVar24);
      }
    }
    else {
      memmove(plVar5 + 7,puVar20,(size_t)puVar24);
      plVar5[7] = plVar5[2];
      plVar5[8] = plVar5[3];
    }
    param_3 = puVar24;
  }
  uVar16 = InpBatchProcessAndEnqueue(param_1,puVar20,(ulonglong)param_3);
  iVar25 = (int)uVar16;
  KeReleaseSpinLock(param_1 + 0x58);
  puVar22 = auStackY_448;
  if ((longlong *)param_1[0xa2] != param_1 + 0xa2) {
    unaff_R12B = KeAcquireSpinLockRaiseToDpc(param_1 + 0x88);
    while (plVar5 = (longlong *)param_1[0xa2], plVar5 != param_1 + 0xa2) {
      lVar14 = *plVar5;
      if (((longlong *)*(longlong *)(lVar14 + 8) != plVar5) ||
         (plVar6 = (longlong *)plVar5[1], (longlong *)*plVar6 != plVar5)) goto LAB_14000335a;
      *plVar6 = lVar14;
      *(longlong **)(lVar14 + 8) = plVar6;
      sVar2 = *(short *)(plVar5 + 2);
      if (((sVar2 == 6) || (sVar2 == 7)) || (sVar2 == 9)) {
        uVar23 = *(uint *)(plVar5 + -0xc);
        lVar14 = (longlong)(plVar5 + -0xd);
        iVar3 = *(int *)((longlong)plVar5 + -0x5c);
        if ((*(byte *)(plVar5 + -0xb) & 1) == 0) {
          puVar20 = (uint *)param_1[0xb4];
          uVar18 = uVar23 - 1 >> 10;
          if ((uVar18 < *puVar20) && (uVar23 == puVar20[(ulonglong)uVar18 * 0x20 + 0x1b])) {
            ExFreeToNPagedLookasideList(puVar20 + (ulonglong)uVar18 * 0x20 + 0x10);
          }
          else {
LAB_140003163:
            ExFreePoolWithTag(lVar14);
          }
        }
        else {
          if (lVar14 != param_1[0xb6]) goto LAB_140003163;
          LOCK();
          param_1[0xb7] = lVar14;
          UNLOCK();
        }
        LOCK();
        *(int *)(param_1 + 0x8f) = (int)param_1[0x8f] + 1;
        UNLOCK();
        iVar4 = (int)param_1[0x89];
        param_1[0x92] = param_1[0x92] + (ulonglong)(uVar23 - iVar3);
        if (iVar4 == 1) {
          *(byte *)(param_1 + 0x8c) = *(byte *)(param_1 + 0x8c) | 2;
        }
        else if (iVar4 == 5) {
          if (((4 < DAT_140020050) && (((byte)DAT_140020060 & 2) != 0)) &&
             (((uint)DAT_140020068 & 2) == DAT_140020068)) {
            if ((4 < DAT_140020050) && (((uint)DAT_140020068 & 2) == DAT_140020068)) {
              local_288 = local_3d0;
              local_268 = local_404;
              local_35c = 4;
              local_2b8 = PTR_DAT_140020058;
              local_298 = "InpPacketFreedLocked";
              local_290 = 0x15;
              local_3d0[0] = 0x863;
              local_280 = 4;
              local_270 = 0x10;
              local_260 = 2;
              local_258 = "Resume";
              local_250 = 7;
              local_360 = 0xb000000;
              local_358 = 2;
              local_2b0 = (uint)*(ushort *)PTR_DAT_140020058;
              local_2a8 = &DAT_14001dc0c;
              local_2ac = 2;
              local_2a0 = 0x52;
              local_29c = 1;
              local_404[0] = *(undefined2 *)(*param_1 + 0xc90);
              local_278 = *param_1 + 0x6ec;
              EtwWriteTransfer(DAT_140020070,&local_360,0,0);
            }
          }
          InpPrepareToQueueWorkerLocked(param_1,'\0','\0');
        }
        else if (iVar4 == 6) {
          InpPrepareToQueueWorkerLocked(param_1,'\0','\0');
        }
      }
      else if (sVar2 == 0xb) {
        *(undefined4 *)(plVar5 + -0x13) = 1;
        *(undefined1 *)((longlong)plVar5 + -0x73) = 0;
        *(undefined4 *)((longlong)plVar5 + -0x3c) = 0;
        if ((*(byte *)((longlong)plVar5 + -0x72) & 0x40) == 0) {
          (*(code *)plVar5[-0xb])(plVar5 + -0x16,0xc00002b6,plVar5[-9],0);
        }
        else {
          (*(code *)plVar5[-0xb])(plVar5 + -0x16,plVar5[-10],0xc00002b6,plVar5[-9]);
        }
      }
    }
    goto LAB_140003361;
  }
LAB_140003378:
  uVar23 = *(uint *)(puVar22 + 0x5c);
  *local_3b8 = uVar23;
  if ((iVar25 == 0xb) || ((int)puVar26 == 0xb)) {
    uVar17 = 0xb;
  }
  else {
    if (uVar23 != 0) {
      *(undefined8 *)(puVar22 + -8) = 0x14000339f;
      uVar16 = PkCompleteRemoval((longlong)(param_1 + 8),*(uint *)(puVar22 + 0x60));
      if ((int)uVar16 == 0x214) {
        lVar14 = *param_1;
        cVar13 = *(char *)(lVar14 + 0x8f9);
        uVar16 = *(undefined8 *)(lVar14 + 0x910);
        pcVar7 = *(code **)(lVar14 + 0x9a0);
        *(undefined8 *)(puVar22 + -8) = 0x1400033c8;
        cVar13 = (*pcVar7)(uVar16,cVar13 == '\0');
        if (cVar13 != '\0') {
          LOCK();
          *(int *)(lVar14 + 0x694) = *(int *)(lVar14 + 0x694) + 1;
          UNLOCK();
          param_1[0xa8] = param_1[0xa8] + 1;
          uVar17 = 1;
          goto LAB_1400033fc;
        }
        param_1[0xa9] = param_1[0xa9] + 1;
      }
      puVar26 = (undefined *)0x1;
    }
    uVar17 = (ulonglong)puVar26 & 0xffffffff;
  }
LAB_1400033fc:
  *(undefined8 *)(puVar22 + -8) = 0x14000340b;
  return uVar17;
LAB_14000335a:
  pcVar7 = (code *)swi(0x29);
  (*pcVar7)(3);
  puVar21 = auStackY_440;
LAB_140003361:
  *(undefined8 *)(puVar21 + -8) = 0x140003373;
  KeReleaseSpinLock(param_1 + 0x88,unaff_R12B);
  puVar22 = puVar21;
  goto LAB_140003378;
}



===== InpTransitionRunningQueue @ 140003430 =====

void InpTransitionRunningQueue(longlong *param_1,char param_2,int param_3)

{
  ushort uVar1;
  undefined2 uVar2;
  code *pcVar3;
  byte bVar4;
  undefined4 *puVar5;
  undefined1 *puVar6;
  char cVar7;
  longlong lVar8;
  undefined8 uVar9;
  undefined1 uVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  int iVar13;
  undefined1 local_58 [8];
  undefined1 auStackY_50 [24];
  
  iVar13 = 1;
  KeAcquireSpinLockRaiseToDpc(param_1 + 0x88);
  puVar11 = (undefined4 *)local_58;
  if (param_3 == 4) {
    puVar11 = (undefined4 *)local_58;
    if ((*(char *)((longlong)param_1 + 0x4b4) == '\0') &&
       (puVar11 = (undefined4 *)local_58, *(int *)((longlong)param_1 + 0x84) == *(int *)param_1[0xb]
       )) {
      puVar12 = (undefined4 *)local_58;
      if ((uint)((int)param_1[0xa5] + (int)param_1[0x91]) < *(uint *)((longlong)param_1 + 0x52c)) {
        ((int *)param_1[0xb])[2] = 0;
        puVar11 = (undefined4 *)local_58;
        puVar6 = local_58;
        if (5 < DAT_140020050) goto LAB_1400037d5;
        goto LAB_140003542;
      }
      goto switchD_140003701_caseD_b;
    }
    goto LAB_140003486;
  }
  puVar5 = (undefined4 *)local_58;
  puVar12 = (undefined4 *)local_58;
  switch(param_3) {
  case 1:
    goto switchD_140003701_caseD_1;
  default:
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(5);
    puVar6 = auStackY_50;
LAB_1400037d5:
    puVar11 = (undefined4 *)puVar6;
    *(undefined8 *)((longlong)puVar11 + -8) = 0x1400037e4;
    cVar7 = _tlgKeywordOn(0x140020050,1);
    if (cVar7 != '\0') {
      lVar8 = *param_1;
      *(undefined1 *)((longlong)puVar11 + 0x20) = 0;
      uVar1 = *(ushort *)(lVar8 + 0xc90);
      *(undefined8 *)((longlong)puVar11 + -8) = 0x140003814;
      VmbusTraceVerbInterruptMaskSet
                ("InpDisableInterruptMaskingAndPollLocked",0x1348,lVar8 + 0x6ec,(ulonglong)uVar1,
                 *(char *)((longlong)puVar11 + 0x20));
    }
LAB_140003542:
    LOCK();
    *puVar11 = *puVar11;
    UNLOCK();
    puVar12 = puVar11;
    if (*(int *)((longlong)param_1 + 0x84) == *(int *)param_1[0xb]) goto switchD_140003701_caseD_b;
    ((int *)param_1[0xb])[2] = 1;
    puVar5 = puVar11;
    if (DAT_140020050 < 6) {
switchD_140003701_caseD_1:
      puVar11 = puVar5;
      *(undefined1 *)(param_1 + 0x8c) = 0;
    }
    else {
      uVar10 = 1;
      *(undefined8 *)(puVar11 + -2) = 0x140003828;
      cVar7 = _tlgKeywordOn(0x140020050,1);
      if (cVar7 == '\0') goto switchD_140003701_caseD_1;
      lVar8 = *param_1;
      *(undefined1 *)(puVar11 + 8) = uVar10;
      uVar1 = *(ushort *)(lVar8 + 0xc90);
      *(undefined8 *)(puVar11 + -2) = 0x140003857;
      VmbusTraceVerbInterruptMaskSet
                ("InpDisableInterruptMaskingAndPollLocked",0x1357,lVar8 + 0x6ec,(ulonglong)uVar1,
                 *(char *)(puVar11 + 8));
      *(undefined1 *)(param_1 + 0x8c) = 0;
    }
    goto LAB_140003492;
  case 5:
  case 6:
    bVar4 = *(byte *)(param_1 + 0x8c) & 2;
    goto LAB_14000373f;
  case 7:
    bVar4 = *(byte *)(param_1 + 0x8c) & 1;
LAB_14000373f:
    puVar12 = (undefined4 *)local_58;
    if (bVar4 == 0) goto switchD_140003701_caseD_b;
    break;
  case 8:
    puVar12 = (undefined4 *)local_58;
    if ((*(byte *)(param_1 + 0x8c) & 4) != 0) {
      puVar11 = (undefined4 *)local_58;
      if ((*(byte *)(param_1 + 0x8c) & 8) != 0) {
        *(undefined4 *)(param_1 + 0xaf) = 5;
        iVar13 = 0xb;
        *(undefined4 *)((longlong)param_1 + 0x57c) = 3;
        puVar11 = (undefined4 *)local_58;
        if (2 < DAT_140020050) {
          VmbusTraceErrorQueueFailed
                    ("InpTransitionRunningQueue",0x10ac,*param_1 + 0x6ec,
                     (ulonglong)*(ushort *)(*param_1 + 0xc90),"InFailedMapFailed","InFailedMapSync")
          ;
          puVar11 = (undefined4 *)local_58;
        }
      }
      break;
    }
  case 0xb:
switchD_140003701_caseD_b:
    puVar11 = puVar12;
    iVar13 = param_3;
  }
LAB_140003486:
  *(undefined1 *)(param_1 + 0x8c) = 0;
  if (iVar13 == 1) {
LAB_140003492:
    if (*(char *)((longlong)param_1 + 0x4b4) != '\0') goto LAB_14000349f;
    if (((int)param_1[0x89] != 1) || (param_1[0x98] == 0)) {
      *(undefined4 *)(param_1 + 0x89) = 2;
      param_1[0x8d] = 0;
      iVar13 = SystemReserved1[0x12]._4_4_;
      if ((param_1[0x8e] == 0) &&
         ((((int)param_1[0xcc] != SystemReserved1[0x12]._4_4_ &&
           (*(int *)((longlong)param_1 + 0x664) != SystemReserved1[0x12]._4_4_)) &&
          ((int)param_1[0xcd] != SystemReserved1[0x12]._4_4_)))) {
        if (*(char *)((longlong)param_1 + 0x4b1) == '\0') {
          if ((int)param_1[0xcc] == -1) {
            *(int *)(param_1 + 0xcc) = SystemReserved1[0x12]._4_4_;
            lVar8 = 0x5d8;
          }
          else {
            if (*(int *)((longlong)param_1 + 0x664) != -1) goto LAB_1400034e1;
            *(int *)((longlong)param_1 + 0x664) = SystemReserved1[0x12]._4_4_;
            lVar8 = 0x618;
          }
          param_1[0x95] = param_1[0x95] + 1;
          param_1[0x8e] = lVar8 + (longlong)param_1;
          *(byte *)((longlong)param_1 + 0x44c) =
               param_2 != '\0' | *(byte *)((longlong)param_1 + 0x44c) & 0xfe;
        }
        else {
          if ((int)param_1[0xcd] != -1) goto LAB_1400034e1;
          *(byte *)((longlong)param_1 + 0x44c) = *(byte *)((longlong)param_1 + 0x44c) | 2;
          param_1[0x94] = param_1[0x94] + 1;
          *(int *)(param_1 + 0xcd) = iVar13;
          param_1[0x8e] = param_1[0xcb];
        }
        *(int *)((longlong)param_1 + 0x48c) = *(int *)((longlong)param_1 + 0x48c) + 1;
      }
      goto LAB_1400034e1;
    }
    if (4 < DAT_140020050) {
      *(undefined8 *)((longlong)puVar11 + -8) = 0x14000364f;
      cVar7 = _tlgKeywordOn(0x140020050,4);
      if (cVar7 != '\0') {
        lVar8 = *param_1;
        *(char **)((longlong)puVar11 + 0x38) = "Setting StopEvent";
        *(undefined4 *)((longlong)puVar11 + 0x30) = *(undefined4 *)(lVar8 + 0x8a8);
        *(undefined4 *)((longlong)puVar11 + 0x28) = *(undefined4 *)(lVar8 + 0x89c);
        uVar2 = *(undefined2 *)(lVar8 + 0xc90);
        *(undefined4 *)((longlong)puVar11 + 0x20) = *(undefined4 *)(lVar8 + 0x898);
        *(undefined8 *)((longlong)puVar11 + -8) = 0x1400036a5;
        VmbusTraceInfoRundownEvent
                  ("InpPrepareToQueueWorkerLocked",0x1205,lVar8 + 0x6ec,uVar2,
                   *(uint *)((longlong)puVar11 + 0x20),*(int *)((longlong)puVar11 + 0x28),
                   *(undefined4 *)((longlong)puVar11 + 0x30),*(char **)((longlong)puVar11 + 0x38));
      }
    }
    lVar8 = param_1[0x98];
    *(undefined8 *)((longlong)puVar11 + -8) = 0x1400036b8;
    KeSetEvent(lVar8,0,0);
    param_1[0x98] = 0;
  }
  else {
LAB_14000349f:
    if (param_1[0x98] == 0) {
LAB_1400034ac:
      if (*(char *)((longlong)param_1 + 0x4b4) != '\0') {
        if ((iVar13 != 0xb) && (iVar13 != 8)) {
          iVar13 = 3;
        }
        lVar8 = param_1[0x97];
        if (lVar8 != 0) {
          *(undefined8 *)((longlong)puVar11 + -8) = 0x140003920;
          KeSetEvent(lVar8,0,0);
          param_1[0x97] = 0;
        }
      }
      *(int *)(param_1 + 0x89) = iVar13;
    }
    else {
      if (iVar13 == 8) {
        *(undefined8 *)((longlong)puVar11 + -8) = 0x140003877;
        uVar9 = InpCancelMdlMapLocked(param_1);
        if ((char)uVar9 == '\0') goto LAB_1400034ac;
      }
      if (4 < DAT_140020050) {
        *(undefined8 *)((longlong)puVar11 + -8) = 0x1400038a0;
        cVar7 = _tlgKeywordOn(0x140020050,4);
        if (cVar7 != '\0') {
          lVar8 = *param_1;
          *(char **)((longlong)puVar11 + 0x38) = "Setting StopEvent";
          *(undefined4 *)((longlong)puVar11 + 0x30) = *(undefined4 *)(lVar8 + 0x8a8);
          *(undefined4 *)((longlong)puVar11 + 0x28) = *(undefined4 *)(lVar8 + 0x89c);
          uVar2 = *(undefined2 *)(lVar8 + 0xc90);
          *(undefined4 *)((longlong)puVar11 + 0x20) = *(undefined4 *)(lVar8 + 0x898);
          *(undefined8 *)((longlong)puVar11 + -8) = 0x1400038f4;
          VmbusTraceInfoRundownEvent
                    ("InpTransitionRunningQueue",0x10df,lVar8 + 0x6ec,uVar2,
                     *(uint *)((longlong)puVar11 + 0x20),*(int *)((longlong)puVar11 + 0x28),
                     *(undefined4 *)((longlong)puVar11 + 0x30),*(char **)((longlong)puVar11 + 0x38))
          ;
        }
      }
      lVar8 = param_1[0x98];
      *(undefined8 *)((longlong)puVar11 + -8) = 0x140003907;
      KeSetEvent(lVar8,0,0);
      param_1[0x98] = 0;
    }
  }
  param_1[0x8d] = 0;
LAB_1400034e1:
  *(undefined8 *)((longlong)puVar11 + -8) = 0x1400034ed;
  InpReleaseLockAndPerformWork(param_1);
  return;
}



===== InpReleaseLockAndPerformWork @ 140003940 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void InpReleaseLockAndPerformWork(longlong *param_1)

{
  byte bVar1;
  longlong lVar2;
  longlong lVar3;
  char cVar4;
  
  lVar2 = param_1[0x8e];
  if (lVar2 == 0) {
    *(undefined1 *)((longlong)param_1 + 0x44c) = 0;
    KeReleaseSpinLock(param_1 + 0x88);
    return;
  }
  bVar1 = *(byte *)((longlong)param_1 + 0x44c);
  param_1[0x8e] = 0;
  *(undefined1 *)((longlong)param_1 + 0x44c) = 0;
  if ((bVar1 & 4) != 0) {
    lVar3 = *param_1;
    cVar4 = (**(code **)(lVar3 + 0x9a8))(*(undefined8 *)(lVar3 + 0x910));
    if (cVar4 != '\0') {
      *(longlong *)(lVar3 + 0x688) = *(longlong *)(lVar3 + 0x688) + 1;
      KeReleaseSpinLock(param_1 + 0x88);
      OutPollQueue((longlong)param_1,'\0');
      goto LAB_1400039c8;
    }
  }
  KeReleaseSpinLock(param_1 + 0x88);
LAB_1400039c8:
  if ((bVar1 & 2) == 0) {
    KeInsertQueueDpc(lVar2,bVar1 & 1,0);
  }
  else {
    (**(code **)(*param_1 + 0x9b0))
              (*(undefined8 *)(*param_1 + 0x910),lVar2,InpProcessingWorkerRoutine,param_1);
  }
  return;
}



===== InpProcessQueue @ 140003a70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 InpProcessQueue(longlong *param_1,char param_2,uint param_3,uint *param_4)

{
  undefined4 uVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong *plVar5;
  longlong *plVar6;
  bool bVar7;
  code *pcVar8;
  undefined1 uVar9;
  char cVar10;
  char cVar11;
  longlong lVar12;
  undefined8 uVar13;
  undefined4 *puVar14;
  uint uVar15;
  longlong lVar16;
  ulonglong uVar17;
  ulonglong uVar18;
  undefined4 uVar19;
  int iVar20;
  longlong lVar21;
  
  lVar2 = *param_1;
  uVar15 = 0;
  uVar13 = 1;
  do {
    if (param_3 <= uVar15) {
LAB_140003cf5:
      *param_4 = uVar15;
      return uVar13;
    }
    plVar4 = param_1 + 0xa0;
    plVar3 = (longlong *)*plVar4;
    if (plVar3 == plVar4) goto LAB_140003cf5;
    if ((int)plVar3[2] == 1) {
      lVar12 = *plVar3;
      lVar21 = plVar3[7];
      uVar19 = 0;
      if ((*(byte *)((longlong)plVar3 + -0x52) & 2) == 0) {
        uVar19 = 0xc0000023;
      }
      if (((longlong *)*(longlong *)(lVar12 + 8) != plVar3) ||
         (plVar4 = (longlong *)plVar3[1], (longlong *)*plVar4 != plVar3)) {
LAB_140003e87:
        pcVar8 = (code *)swi(0x29);
        (*pcVar8)(3);
        pcVar8 = (code *)swi(3);
        uVar13 = (*pcVar8)();
        return uVar13;
      }
      *plVar4 = lVar12;
      *(longlong **)(lVar12 + 8) = plVar4;
      uVar1 = *(undefined4 *)((longlong)plVar3 + -0x1c);
      *(undefined4 *)(plVar3 + -0xf) = 1;
      *(undefined1 *)((longlong)plVar3 + -0x53) = 0;
      *(undefined4 *)((longlong)plVar3 + -0x1c) = uVar1;
      if ((*(byte *)((longlong)plVar3 + -0x52) & 0x40) == 0) {
        (*(code *)plVar3[-7])(plVar3 + -0x12,uVar19);
      }
      else {
        (*(code *)plVar3[-7])(plVar3 + -0x12,plVar3[-6],uVar19,plVar3[-5],uVar1);
      }
      if (5 < DAT_140020050) {
        cVar10 = '\x01';
        puVar14 = &DAT_140020050;
        cVar11 = _tlgKeywordOn(0x140020050,1);
        if (cVar11 != '\0') {
          uVar19 = 0xa4a;
LAB_140003d59:
          VmbusTraceVerbPacketProcess
                    (puVar14,uVar19,*param_1 + 0x6ec,*(undefined2 *)(*param_1 + 0xc90),lVar21,cVar10
                    );
        }
      }
    }
    else {
      plVar6 = plVar3 + -3;
      if (((*(byte *)(plVar3 + -1) & 2) != 0) && (param_2 != '\0')) {
        *(undefined1 *)((longlong)param_1 + 0x4b1) = 1;
        goto LAB_140003cf5;
      }
      iVar20 = *(int *)((longlong)plVar3 + 0x34);
      *(undefined8 *)((longlong)param_1 + 0x584) = 0;
      lVar21 = *plVar3;
      bVar7 = iVar20 != 0;
      if (((longlong *)*(longlong *)(lVar21 + 8) != plVar3) ||
         (plVar5 = (longlong *)plVar3[1], (longlong *)*plVar5 != plVar3)) goto LAB_140003e87;
      *plVar5 = lVar21;
      *(longlong **)(lVar21 + 8) = plVar5;
      *(int *)((longlong)param_1 + 0x524) = *(int *)((longlong)param_1 + 0x524) + 1;
      if (*(char *)((longlong)plVar3 + -7) != '\0') {
        *(int *)(param_1 + 0xa5) = (int)param_1[0xa5] + 1;
      }
      lVar21 = plVar3[0xd];
      uVar17 = (ulonglong)*(ushort *)((longlong)plVar3 + 0x8a) << 3;
      iVar20 = (uint)*(ushort *)((longlong)plVar3 + 0x8c) * 8 - (int)uVar17;
      uVar18 = uVar17;
      lVar12 = lVar2;
      if ((KmclPerformanceCounterTimingCounters != 0) ||
         ((3 < DAT_140020050 && (cVar10 = _tlgKeywordOn(0x140020050,2), cVar10 != '\0')))) {
        lVar12 = KeQueryPerformanceCounter(0);
        plVar3[9] = lVar12;
        uVar18 = uVar17;
        lVar12 = lVar2;
      }
      lVar16 = (uVar18 & 0xffffffff) + 0xa0 + (longlong)plVar6;
      if (*(char *)(lVar12 + 0x7c8) == '\0') {
        (**(code **)(lVar12 + 2000))(lVar12,plVar6,lVar16,iVar20,bVar7);
      }
      else {
        (**(code **)(lVar12 + 2000))
                  (lVar12,*(undefined8 *)(lVar12 + 0x7e0),plVar6,lVar16,iVar20,bVar7);
      }
      iVar20 = *(int *)((longlong)param_1 + 0x584);
      if (iVar20 != 0) {
        if (iVar20 == 2) {
          *(undefined4 *)((longlong)param_1 + 0x584) = 0;
          if ((*(byte *)(plVar3 + -1) & 0x10) != 0) {
            uVar9 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x88);
            lVar2 = *plVar3;
            if (((longlong *)*(longlong *)(lVar2 + 8) != plVar3) ||
               (plVar6 = (longlong *)plVar3[1], (longlong *)*plVar6 != plVar3)) goto LAB_140003e87;
            *plVar6 = lVar2;
            *(longlong **)(lVar2 + 8) = plVar6;
            *(int *)(param_1 + 0x90) = (int)param_1[0x90] + -1;
            KeReleaseSpinLock(param_1 + 0x88,uVar9);
            *(byte *)(plVar3 + -1) = *(byte *)(plVar3 + -1) & 0xef;
          }
          lVar2 = *plVar4;
          if (*(longlong **)(lVar2 + 8) != plVar4) goto LAB_140003e87;
          *plVar3 = lVar2;
          plVar3[1] = (longlong)plVar4;
          *(longlong **)(lVar2 + 8) = plVar3;
          *plVar4 = (longlong)plVar3;
          *(int *)((longlong)param_1 + 0x524) = *(int *)((longlong)param_1 + 0x524) + -1;
          if (*(char *)((longlong)plVar3 + -7) != '\0') {
            *(int *)(param_1 + 0xa5) = (int)param_1[0xa5] + -1;
          }
          uVar13 = 7;
          goto LAB_140003cf5;
        }
        if (iVar20 == 1) {
          *(undefined4 *)((longlong)param_1 + 0x584) = 0;
          InRequeuePacket((longlong)param_1,(longlong)plVar6);
          uVar13 = 8;
          goto LAB_140003cf5;
        }
        if (iVar20 == 3) {
          *(undefined4 *)((longlong)param_1 + 0x584) = 0;
          *(undefined1 *)((longlong)param_1 + 0x4b1) = 1;
          InRequeuePacket((longlong)param_1,(longlong)plVar6);
          goto LAB_140003cf5;
        }
      }
      if (5 < DAT_140020050) {
        puVar14 = &DAT_140020050;
        cVar10 = _tlgKeywordOn(0x140020050,1);
        if (cVar10 != '\0') {
          uVar19 = 0xaba;
          cVar10 = '\0';
          goto LAB_140003d59;
        }
      }
    }
    uVar15 = uVar15 + 1;
  } while( true );
}



===== InCompletePacket @ 140003ea0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void InCompletePacket(longlong *param_1,longlong param_2,void *param_3,uint param_4)

{
  undefined2 uVar1;
  uint *puVar2;
  undefined *puVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined1 uVar6;
  char cVar7;
  char cVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  ulonglong uVar12;
  undefined8 uVar13;
  longlong lVar14;
  int iVar15;
  char *pcVar16;
  char cVar17;
  uint uVar18;
  undefined *puVar19;
  undefined1 *puVar20;
  undefined1 *puVar21;
  int iVar22;
  uint uVar23;
  void *pvVar24;
  ulonglong *puVar25;
  longlong lVar26;
  longlong lVar27;
  undefined4 *puVar28;
  uint uVar29;
  uint uVar30;
  bool bVar31;
  undefined1 local_98 [8];
  undefined1 auStackY_90 [24];
  
  lVar14 = *(longlong *)(param_2 + 0x58);
  pvVar24 = param_3;
  if (((lVar14 != 0) && (lVar26 = *(longlong *)(param_2 + 0x60), lVar26 != 0)) &&
     ((KmclPerformanceCounterTimingCounters != 0 ||
      ((3 < DAT_140020050 && (cVar8 = _tlgKeywordOn(0x140020050,2), cVar8 != '\0')))))) {
    *(longlong *)(param_2 + 0x58) = lVar26 - lVar14;
    lVar14 = KeQueryPerformanceCounter(0);
    bVar31 = KmclPerformanceCounterTimingCounters != 0;
    *(longlong *)(param_2 + 0x60) = lVar14 - *(longlong *)(param_2 + 0x60);
    if (bVar31) {
      param_1[0xab] = param_1[0xab] + *(longlong *)(param_2 + 0x58);
      param_1[0xac] = param_1[0xac] + *(longlong *)(param_2 + 0x60);
    }
    lVar14 = *(longlong *)(param_2 + 0x60);
    lVar26 = *(longlong *)(param_2 + 0x58);
    lVar27 = *param_1;
    if (((*(ulonglong *)(lVar27 + 0x8b8) < (ulonglong)(lVar14 + lVar26)) && (3 < DAT_140020050)) &&
       (cVar8 = _tlgKeywordOn(0x140020050,2), cVar8 != '\0')) {
      pvVar24 = (void *)(lVar27 + 0x6ec);
      VmbusTraceWarnPacketDelay
                ("InCompletePacket",0x915,pvVar24,(ulonglong)*(ushort *)(lVar27 + 0xc90),
                 (ulonglong)(lVar26 * 1000) / KmclPerformanceCounterFrequency,
                 (ulonglong)(lVar14 * 1000) / KmclPerformanceCounterFrequency);
    }
  }
  puVar20 = local_98;
  puVar21 = local_98;
  lVar14 = 0;
  if (*(longlong *)(param_2 + 0x30) != 0) {
    pvVar24 = (void *)((ulonglong)*(uint *)(param_2 + 0x38) + 0xa0 + param_2 +
                      (ulonglong)*(uint *)(param_2 + 0x4c) * 8);
    iVar22 = (**(code **)(*param_1 + 0x9f8))(*(undefined8 *)(*param_1 + 0x910));
    if (-1 < iVar22) {
      *(undefined8 *)(param_2 + 0x30) = 0;
    }
  }
  uVar6 = KfRaiseIrql(2);
  if ((*(byte *)(param_2 + 0x10) & 0x10) != 0) {
    KeAcquireSpinLockAtDpcLevel(param_1 + 0x88);
    iVar22 = (int)param_1[0x89];
    if ((iVar22 == 0) || (iVar22 == 10)) {
      if ((*(byte *)(param_2 + 0x10) & 4) == 0) goto LAB_140004549;
    }
    else {
      lVar26 = *(longlong *)(param_2 + 0x18);
      lVar14 = param_2 + 0x18;
      if ((*(longlong *)(lVar26 + 8) == lVar14) &&
         (plVar4 = *(longlong **)(param_2 + 0x20), *plVar4 == lVar14)) {
        *plVar4 = lVar26;
        *(longlong **)(lVar26 + 8) = plVar4;
        *(int *)(param_1 + 0x90) = (int)param_1[0x90] + -1;
        KeReleaseSpinLockFromDpcLevel(param_1 + 0x88);
        goto LAB_140003f46;
      }
      iVar22 = 3;
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)();
      puVar21 = auStackY_90;
    }
    puVar20 = puVar21;
    if (iVar22 == 0) {
      uVar30 = *(uint *)(param_2 + 0x54);
      uVar9 = *(uint *)(param_2 + 0x40);
      *(undefined8 *)(puVar21 + -8) = 0x140004706;
      memmove((void *)((ulonglong)uVar9 + 0xa0 + (ulonglong)uVar30 + param_2),param_3,
              (ulonglong)param_4);
      *(uint *)(param_2 + 0x50) = param_4;
    }
LAB_140004549:
    *(byte *)(param_2 + 0x10) = *(byte *)(param_2 + 0x10) | 0x20;
    iVar22 = *(int *)((longlong)param_1 + 0x484) + 1;
    *(int *)((longlong)param_1 + 0x484) = iVar22;
    if (((int)param_1[0x89] == 10) && ((int)param_1[0x90] == iVar22)) {
      *(int *)(param_1 + 0x89) = (int)lVar14;
      if (4 < DAT_140020050) {
        *(undefined8 *)(puVar20 + -8) = 0x14000473c;
        cVar8 = _tlgKeywordOn(0x140020050,4);
        if (cVar8 != '\0') {
          lVar26 = *param_1;
          *(char **)(puVar20 + 0x38) = "Setting StopEvent";
          *(undefined4 *)(puVar20 + 0x30) = *(undefined4 *)(lVar26 + 0x8a8);
          *(undefined4 *)(puVar20 + 0x28) = *(undefined4 *)(lVar26 + 0x89c);
          uVar1 = *(undefined2 *)(lVar26 + 0xc90);
          *(undefined4 *)(puVar20 + 0x20) = *(undefined4 *)(lVar26 + 0x898);
          *(undefined8 *)(puVar20 + -8) = 0x140004792;
          VmbusTraceInfoRundownEvent
                    ("InCompletePacket",0x94e,lVar26 + 0x6ec,uVar1,*(uint *)(puVar20 + 0x20),
                     *(int *)(puVar20 + 0x28),*(undefined4 *)(puVar20 + 0x30),
                     *(char **)(puVar20 + 0x38));
        }
      }
      lVar26 = param_1[0x98];
      *(undefined8 *)(puVar20 + -8) = 0x1400047a5;
      KeSetEvent(lVar26,0,0);
      param_1[0x98] = lVar14;
    }
    *(undefined8 *)(puVar20 + -8) = 0x14000457a;
    KeReleaseSpinLock(param_1 + 0x88,uVar6);
    return;
  }
LAB_140003f46:
  cVar8 = *(char *)(param_2 + 0x11);
  if ((*(byte *)(param_2 + 0x10) & 4) == 0) {
LAB_140003f58:
    uVar30 = *(uint *)(param_2 + 8);
    iVar22 = *(int *)(param_2 + 0xc);
    if ((*(byte *)(param_2 + 0x10) & 1) == 0) {
      puVar2 = (uint *)param_1[0xb4];
      uVar9 = uVar30 - 1 >> 10;
      if ((*puVar2 <= uVar9) || (uVar30 != puVar2[(ulonglong)uVar9 * 0x20 + 0x1b]))
      goto LAB_140003f88;
      ExFreeToNPagedLookasideList(puVar2 + (ulonglong)uVar9 * 0x20 + 0x10);
    }
    else if (param_2 == param_1[0xb6]) {
      LOCK();
      param_1[0xb7] = param_2;
      UNLOCK();
    }
    else {
LAB_140003f88:
      ExFreePoolWithTag(param_2);
    }
    KeAcquireSpinLockAtDpcLevel(param_1 + 0x88);
    LOCK();
    *(int *)(param_1 + 0x8f) = (int)param_1[0x8f] + 1;
    UNLOCK();
    iVar15 = (int)param_1[0x89];
    param_1[0x92] = param_1[0x92] + (ulonglong)(uVar30 - iVar22);
    if (iVar15 == 1) {
      *(byte *)(param_1 + 0x8c) = *(byte *)(param_1 + 0x8c) | 2;
    }
    else {
      if (iVar15 == 5) {
        if ((4 < DAT_140020050) && (cVar7 = _tlgKeywordOn(0x140020050,2), cVar7 != '\0')) {
          VmbusTraceInfoQuotaExceeded
                    ("InpPacketFreedLocked",0x863,*param_1 + 0x6ec,
                     (ulonglong)*(ushort *)(*param_1 + 0xc90),'\0');
        }
      }
      else if (iVar15 != 6) goto LAB_140003fe6;
      InpPrepareToQueueWorkerLocked(param_1,'\0','\0');
    }
  }
  else {
    pcVar16 = (char *)(param_1 + 0x20);
    *(undefined8 *)(param_2 + 0x40) = *(undefined8 *)(param_2 + 0xa8);
    *(code **)(param_2 + 0x38) = InpCompletionSent;
    *(longlong *)(param_2 + 0x48) = param_2 + 0xa0;
    *(undefined4 *)(param_2 + 0x30) = *(undefined4 *)((longlong)param_1 + 0x5ac);
    KeAcquireSpinLockAtDpcLevel();
    if ((int)param_1[0x21] == 1) {
      puVar3 = *(undefined **)(param_2 + 0x40);
      uVar30 = param_4 + 0x10;
      iVar22 = -0x7ffffffb;
      if (uVar30 < 0x7fff9) {
        uVar9 = *(uint *)(param_1 + 0x18);
        uVar11 = *(uint *)(param_1 + 10);
        pcVar16 = (char *)(ulonglong)uVar11;
        uVar23 = param_4 + 0x17 & 0xfffffff8;
        pvVar24 = (void *)(ulonglong)uVar23;
        puVar28 = (undefined4 *)((ulonglong)uVar9 + param_1[9]);
        uVar29 = uVar23 + 8;
        uVar10 = (*(int *)((longlong)param_1 + 0xc4) - uVar9) - 8;
        if (uVar11 <= uVar10) {
          uVar10 = uVar10 + uVar11;
        }
        if (uVar10 < uVar29) {
          lVar14 = param_1[8];
          uVar10 = *(uint *)(lVar14 + 4);
          cVar7 = PkpValidatePointer(uVar11,uVar10);
          if (cVar7 == '\0') {
            iVar15 = -0x3ffffefe;
          }
          else {
            *(uint *)((longlong)param_1 + 0xc4) = uVar10;
            uVar18 = (uVar10 - uVar9) - 8;
            uVar10 = (uint)pcVar16;
            if (uVar10 <= uVar18) {
              uVar18 = uVar18 + uVar10;
            }
            if (uVar29 <= uVar18) goto code_r0x000140004174;
            if (uVar29 < uVar10) {
              if ((int)param_1[0x19] == 0) {
                PkpExpectInterrupt((longlong)(param_1 + 8),'\0');
                pvVar24 = (void *)(ulonglong)uVar23;
                pcVar16 = (char *)(ulonglong)uVar11;
              }
              uVar11 = uVar9 - (int)param_1[0x18];
              uVar10 = (uint)pcVar16;
              if (uVar10 <= uVar11) {
                uVar11 = uVar11 + uVar10;
              }
              uVar11 = uVar11 + uVar29;
              if (uVar10 <= uVar11) {
                uVar11 = uVar10 - 8;
              }
              *(uint *)(lVar14 + 0xc) = uVar11;
              *(int *)(param_1 + 0x19) = (int)pvVar24;
              LOCK();
              UNLOCK();
              uVar11 = *(uint *)(lVar14 + 4);
              cVar7 = PkpValidatePointer(uVar10,uVar11);
              if (cVar7 == '\0') {
                iVar15 = -0x3ffffefe;
              }
              else {
                *(uint *)((longlong)param_1 + 0xc4) = uVar11;
                uVar11 = (uVar11 - uVar9) - 8;
                if ((uint)pcVar16 <= uVar11) {
                  uVar11 = uVar11 + (uint)pcVar16;
                }
                if (uVar29 <= uVar11) goto code_r0x000140004174;
                iVar15 = -0x7ffffffb;
              }
            }
            else {
              iVar15 = -0x3ffffff3;
            }
          }
        }
        else {
code_r0x000140004174:
          *puVar28 = 0x2000b;
          *(short *)(puVar28 + 1) = (short)((ulonglong)uVar30 + 7 >> 3);
          *(undefined2 *)((longlong)puVar28 + 6) = 0;
          *(undefined **)(puVar28 + 2) = puVar3;
          memmove(puVar28 + 4,param_3,(ulonglong)param_4);
          uVar11 = *(uint *)(param_1 + 10);
          if ((uVar30 & 7) != 0) {
            puVar25 = (ulonglong *)((ulonglong)(uVar9 + (uVar30 & 0xfffffff8)) + param_1[9]);
            *puVar25 = (1L << (char)(uVar30 & 7) * '\b') - 1U & *puVar25;
            uVar30 = uVar23;
          }
          *(ulonglong *)((ulonglong)(uVar9 + uVar30) + param_1[9]) = (ulonglong)uVar9 << 0x20;
          if ((int)param_1[0x19] != 0) {
            *(undefined4 *)(param_1 + 0x19) = 0;
            *(undefined4 *)(param_1[8] + 0xc) = 0;
          }
          uVar30 = uVar9 + uVar30 + 8;
          if (uVar11 <= uVar30) {
            uVar30 = uVar30 - uVar11;
          }
          uVar9 = *(uint *)(param_1 + 0x18);
          pvVar24 = (void *)(ulonglong)uVar9;
          puVar2 = (uint *)param_1[8];
          uVar11 = *(uint *)(param_1 + 10);
          pcVar16 = (char *)(ulonglong)uVar11;
          *(uint *)(param_1 + 0x18) = uVar30;
          *puVar2 = uVar30;
          LOCK();
          UNLOCK();
          uVar30 = puVar2[2];
          uVar10 = puVar2[1];
          if ((uVar10 < uVar11) && ((uVar10 & 7) == 0)) {
            *(uint *)((longlong)param_1 + 0xc4) = uVar10;
            if (uVar9 == uVar10) {
              if (uVar30 == 0) {
                iVar15 = 0x214;
                goto LAB_140004254;
              }
              *(longlong *)param_1[0x1b] = *(longlong *)param_1[0x1b] + 1;
            }
            iVar15 = 0;
          }
          else {
            iVar15 = -0x3ffffefe;
          }
        }
      }
      else {
        iVar15 = -0x3ffffff3;
      }
LAB_140004254:
      if (5 < DAT_140020050) {
        cVar17 = '\x01';
        pcVar16 = (char *)&DAT_140020050;
        cVar7 = _tlgKeywordOn(0x140020050,1);
        if (cVar7 != '\0') {
          pcVar16 = "OutpTrySendCompletionPacket";
          pvVar24 = (void *)(*param_1 + 0x6ec);
          VmbusTraceVerbPacketSend
                    ("OutpTrySendCompletionPacket",0x53f,pvVar24,*(undefined2 *)(*param_1 + 0xc90),
                     puVar3,cVar17);
        }
      }
      puVar19 = puVar3;
      if ((Microsoft_Windows_Hyper_V_KMCLEnableBits & 2) != 0) {
        lVar14 = *param_1;
        pcVar16 = (char *)(lVar14 + 0xa90);
        puVar19 = &VMBUS_SEND_PACKET;
        McTemplateK0jjxth_EtwWriteTransfer
                  (pcVar16,&VMBUS_SEND_PACKET,pvVar24,lVar14 + 0xaa0,pcVar16,(char)puVar3,1,
                   (char)*(undefined2 *)(lVar14 + 0xc90));
      }
      if (iVar15 < 0) {
        if (iVar15 == -0x7ffffffb) {
          iVar15 = iVar22;
          if (((int)param_1[0x21] != 5) &&
             (*(undefined4 *)(param_1 + 0x21) = 2, (*(byte *)(param_1[0xb] + 0x40) & 1) == 0)) {
            pcVar16 = (char *)param_1;
            OutpEnqueuePollingTimer((longlong)param_1);
          }
        }
        else if (iVar15 == -0x3ffffff3) {
          if (2 < DAT_140020050) {
            pcVar16 = "OutpProcessRingResult";
            VmbusTraceErrorQueue
                      ("OutpProcessRingResult",0x2ca,*param_1 + 0x6ec,
                       (ulonglong)*(ushort *)(*param_1 + 0xc90),0xc000000d);
          }
        }
        else {
          *(undefined4 *)(param_1 + 0x21) = 6;
          *(int *)((longlong)param_1 + 0x42c) = iVar15;
          if (2 < DAT_140020050) {
            VmbusTraceErrorQueueFailedStatus
                      (pcVar16,puVar19,*param_1 + 0x6ec,(ulonglong)*(ushort *)(*param_1 + 0xc90),
                       iVar15);
          }
        }
      }
      else {
        *(int *)(param_1 + 0x42) = (int)param_1[0x42] + 1;
        *(int *)(param_1 + 0x39) = (int)param_1[0x39] + 1;
        if (iVar15 == 0x214) {
          pcVar16 = (char *)*param_1;
          uVar13 = KmclSendSignal((longlong)pcVar16);
          if ((char)uVar13 == '\0') {
            param_1[0x3c] = param_1[0x3c] + 1;
          }
          else {
            param_1[0x3b] = param_1[0x3b] + 1;
          }
        }
        iVar15 = 0;
      }
      if (iVar15 < 0) goto LAB_140004a1e;
LAB_1400042b9:
      KeReleaseSpinLockFromDpcLevel(param_1 + 0x20);
      goto LAB_140003f58;
    }
LAB_140004a1e:
    if (*(uint *)(param_2 + 0x30) < param_4) {
      MicrosoftTelemetryAssertTriggeredArgsKM(pcVar16,param_4,*(uint *)(param_2 + 0x30));
      goto LAB_1400042b9;
    }
    memmove(*(void **)(param_2 + 0x48),param_3,(ulonglong)param_4);
    *(uint *)(param_2 + 0x30) = param_4;
    *(undefined4 *)(param_2 + 0x28) = 2;
    OutpEnqueuePacket((longlong)param_1,(longlong *)(param_2 + 0x18));
    KeReleaseSpinLockFromDpcLevel(param_1 + 0x20);
    KeAcquireSpinLockAtDpcLevel(param_1 + 0x88);
  }
LAB_140003fe6:
  bVar31 = false;
  if (cVar8 == '\0') {
    if ((((int)param_1[0x89] != 4) || ((char)param_1[0x96] == '\0')) ||
       (*(int *)((longlong)param_1 + 0x84) == *(int *)param_1[0xb])) goto LAB_14000406f;
    ((int *)param_1[0xb])[2] = 1;
    if (5 < DAT_140020050) {
      cVar7 = '\x01';
      cVar8 = _tlgKeywordOn(0x140020050,1);
      if (cVar8 != '\0') {
        VmbusTraceVerbInterruptMaskSet
                  ("InpPacketCompletedLocked",0x8c7,*param_1 + 0x6ec,
                   (ulonglong)*(ushort *)(*param_1 + 0xc90),cVar7);
      }
    }
    *(byte *)((longlong)param_1 + 0x44c) = *(byte *)((longlong)param_1 + 0x44c) | 4;
    *(int *)((longlong)param_1 + 0x47c) = *(int *)((longlong)param_1 + 0x47c) + 1;
    iVar22 = (int)param_1[0x89];
  }
  else {
    iVar22 = (int)param_1[0x91] + -1;
    *(int *)(param_1 + 0x91) = iVar22;
    if ((int)param_1[0x89] == 4) {
      if (*(int *)((longlong)param_1 + 0x84) == *(int *)param_1[0xb]) {
        if (((int)param_1[0xa5] + iVar22 == *(int *)((longlong)param_1 + 0x52c) + -1) &&
           (uVar12 = InpDisableInterruptMaskingAndPollLocked(param_1), (char)uVar12 == '\0')) {
          bVar31 = true;
        }
      }
      else {
        bVar31 = true;
      }
    }
LAB_14000406f:
    iVar22 = (int)param_1[0x89];
    iVar15 = *(int *)((longlong)param_1 + 0x47c) + 1;
    *(int *)((longlong)param_1 + 0x47c) = iVar15;
    if (!bVar31) {
      if (iVar22 == 2) {
        uVar12 = InpPrepareToQueueWorkerLocked(param_1,'\0','\0');
        if ((char)uVar12 != '\0') {
          *(int *)((longlong)param_1 + 0x49c) = *(int *)((longlong)param_1 + 0x49c) + 1;
        }
      }
      else if ((iVar22 == 9) && (iVar15 + (int)param_1[0x90] == *(int *)((longlong)param_1 + 0x524))
              ) {
        *(int *)(param_1 + 0x89) = 0;
        if ((4 < DAT_140020050) && (cVar8 = _tlgKeywordOn(0x140020050,4), cVar8 != '\0')) {
          lVar14 = *param_1;
          VmbusTraceInfoRundownEvent
                    ("InpPacketCompletedLocked",0x8e7,lVar14 + 0x6ec,*(undefined2 *)(lVar14 + 0xc90)
                     ,*(uint *)(lVar14 + 0x898),*(int *)(lVar14 + 0x89c),
                     *(undefined4 *)(lVar14 + 0x8a8),"Incoming queue paused");
        }
        KmclDecrementRundownCount(*param_1,'\x01',0x8e8);
      }
      goto LAB_14000409a;
    }
  }
  if ((iVar22 == 1) && (param_1[0x98] != 0)) {
    if ((4 < DAT_140020050) && (cVar8 = _tlgKeywordOn(0x140020050,4), cVar8 != '\0')) {
      lVar14 = *param_1;
      VmbusTraceInfoRundownEvent
                ("InpPrepareToQueueWorkerLocked",0x1205,lVar14 + 0x6ec,
                 *(undefined2 *)(lVar14 + 0xc90),*(uint *)(lVar14 + 0x898),*(int *)(lVar14 + 0x89c),
                 *(undefined4 *)(lVar14 + 0x8a8),"Setting StopEvent");
    }
    KeSetEvent(param_1[0x98],0,0);
    param_1[0x98] = 0;
    param_1[0x8d] = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x89) = 2;
    param_1[0x8d] = 0;
    iVar22 = SystemReserved1[0x12]._4_4_;
    if ((((param_1[0x8e] == 0) && ((int)param_1[0xcc] != SystemReserved1[0x12]._4_4_)) &&
        (*(int *)((longlong)param_1 + 0x664) != SystemReserved1[0x12]._4_4_)) &&
       ((int)param_1[0xcd] != SystemReserved1[0x12]._4_4_)) {
      if (*(char *)((longlong)param_1 + 0x4b1) == '\0') {
        if ((int)param_1[0xcc] == -1) {
          *(int *)(param_1 + 0xcc) = SystemReserved1[0x12]._4_4_;
          lVar14 = 0x5d8;
        }
        else {
          if (*(int *)((longlong)param_1 + 0x664) != -1) goto LAB_14000409a;
          *(int *)((longlong)param_1 + 0x664) = SystemReserved1[0x12]._4_4_;
          lVar14 = 0x618;
        }
        param_1[0x95] = param_1[0x95] + 1;
        lVar14 = lVar14 + (longlong)param_1;
        *(byte *)((longlong)param_1 + 0x44c) = *(byte *)((longlong)param_1 + 0x44c) & 0xfe;
      }
      else {
        if ((int)param_1[0xcd] != -1) goto LAB_14000409a;
        *(byte *)((longlong)param_1 + 0x44c) = *(byte *)((longlong)param_1 + 0x44c) | 2;
        param_1[0x94] = param_1[0x94] + 1;
        *(int *)(param_1 + 0xcd) = iVar22;
        lVar14 = param_1[0xcb];
      }
      *(int *)((longlong)param_1 + 0x48c) = *(int *)((longlong)param_1 + 0x48c) + 1;
      *(int *)(param_1 + 0x93) = (int)param_1[0x93] + 1;
      param_1[0x8e] = lVar14;
    }
  }
LAB_14000409a:
  InpReleaseLockAndPerformWork(param_1);
  return;
}



===== VmbChannelPacketComplete @ 140004c00 =====

void VmbChannelPacketComplete(undefined8 *param_1,void *param_2,uint param_3)

{
                    /* 0x4c00  52  VmbChannelPacketComplete */
  InCompletePacket((longlong *)*param_1,(longlong)param_1,param_2,param_3);
  return;
}



===== InpDisableInterruptMaskingAndPollLocked @ 140004c30 =====

ulonglong InpDisableInterruptMaskingAndPollLocked(longlong *param_1)

{
  uint uVar1;
  char cVar2;
  undefined7 extraout_var;
  ulonglong uVar3;
  char cVar4;
  
  *(undefined4 *)(param_1[0xb] + 8) = 0;
  if (5 < DAT_140020050) {
    cVar2 = _tlgKeywordOn(0x140020050,1);
    if (cVar2 != '\0') {
      VmbusTraceVerbInterruptMaskSet
                ("InpDisableInterruptMaskingAndPollLocked",0x1348,*param_1 + 0x6ec,
                 (ulonglong)*(ushort *)(*param_1 + 0xc90),'\0');
    }
  }
  LOCK();
  UNLOCK();
  uVar1 = *(uint *)param_1[0xb];
  uVar3 = (ulonglong)uVar1;
  if (*(uint *)((longlong)param_1 + 0x84) == uVar1) {
    uVar3 = CONCAT71((uint7)(uint3)(uVar1 >> 8),1);
  }
  else {
    ((uint *)param_1[0xb])[2] = 1;
    if (5 < DAT_140020050) {
      cVar4 = '\x01';
      cVar2 = _tlgKeywordOn(0x140020050,1);
      uVar3 = CONCAT71(extraout_var,cVar2);
      if (cVar2 != '\0') {
        uVar3 = VmbusTraceVerbInterruptMaskSet
                          ("InpDisableInterruptMaskingAndPollLocked",0x1357,*param_1 + 0x6ec,
                           (ulonglong)*(ushort *)(*param_1 + 0xc90),cVar4);
      }
    }
    uVar3 = uVar3 & 0xffffffffffffff00;
  }
  return uVar3;
}



===== InpPacketCompletedLocked @ 140004d10 =====

void InpPacketCompletedLocked(longlong *param_1,char param_2)

{
  bool bVar1;
  char cVar2;
  ulonglong uVar3;
  longlong lVar4;
  int iVar5;
  char cVar6;
  int iVar7;
  
  bVar1 = false;
  if (param_2 == '\0') {
    if ((((int)param_1[0x89] == 4) && ((char)param_1[0x96] != '\0')) &&
       (*(int *)((longlong)param_1 + 0x84) != *(int *)param_1[0xb])) {
      ((int *)param_1[0xb])[2] = 1;
      if (5 < DAT_140020050) {
        cVar6 = '\x01';
        cVar2 = _tlgKeywordOn(0x140020050,1);
        if (cVar2 != '\0') {
          VmbusTraceVerbInterruptMaskSet
                    ("InpPacketCompletedLocked",0x8c7,*param_1 + 0x6ec,
                     (ulonglong)*(ushort *)(*param_1 + 0xc90),cVar6);
        }
      }
      *(byte *)((longlong)param_1 + 0x44c) = *(byte *)((longlong)param_1 + 0x44c) | 4;
      *(int *)((longlong)param_1 + 0x47c) = *(int *)((longlong)param_1 + 0x47c) + 1;
      iVar7 = (int)param_1[0x89];
      goto LAB_140004dd3;
    }
  }
  else {
    iVar7 = (int)param_1[0x91] + -1;
    *(int *)(param_1 + 0x91) = iVar7;
    if ((int)param_1[0x89] == 4) {
      if (*(int *)((longlong)param_1 + 0x84) != *(int *)param_1[0xb]) {
        *(int *)((longlong)param_1 + 0x47c) = *(int *)((longlong)param_1 + 0x47c) + 1;
        iVar7 = (int)param_1[0x89];
        goto LAB_140004dd3;
      }
      if (((int)param_1[0xa5] + iVar7 == *(int *)((longlong)param_1 + 0x52c) + -1) &&
         (uVar3 = InpDisableInterruptMaskingAndPollLocked(param_1), (char)uVar3 == '\0')) {
        bVar1 = true;
      }
    }
  }
  iVar7 = (int)param_1[0x89];
  iVar5 = *(int *)((longlong)param_1 + 0x47c) + 1;
  *(int *)((longlong)param_1 + 0x47c) = iVar5;
  if (!bVar1) {
    if (iVar7 == 2) {
      uVar3 = InpPrepareToQueueWorkerLocked(param_1,'\0','\0');
      if ((char)uVar3 == '\0') {
        return;
      }
      *(int *)((longlong)param_1 + 0x49c) = *(int *)((longlong)param_1 + 0x49c) + 1;
      return;
    }
    if (iVar7 != 9) {
      return;
    }
    if (iVar5 + (int)param_1[0x90] != *(int *)((longlong)param_1 + 0x524)) {
      return;
    }
    *(undefined4 *)(param_1 + 0x89) = 0;
    if ((4 < DAT_140020050) && (cVar2 = _tlgKeywordOn(0x140020050,4), cVar2 != '\0')) {
      lVar4 = *param_1;
      VmbusTraceInfoRundownEvent
                ("InpPacketCompletedLocked",0x8e7,lVar4 + 0x6ec,*(undefined2 *)(lVar4 + 0xc90),
                 *(uint *)(lVar4 + 0x898),*(int *)(lVar4 + 0x89c),*(undefined4 *)(lVar4 + 0x8a8),
                 "Incoming queue paused");
    }
    KmclDecrementRundownCount(*param_1,'\x01',0x8e8);
    return;
  }
LAB_140004dd3:
  if ((iVar7 == 1) && (param_1[0x98] != 0)) {
    if ((4 < DAT_140020050) && (cVar2 = _tlgKeywordOn(0x140020050,4), cVar2 != '\0')) {
      lVar4 = *param_1;
      VmbusTraceInfoRundownEvent
                ("InpPrepareToQueueWorkerLocked",0x1205,lVar4 + 0x6ec,*(undefined2 *)(lVar4 + 0xc90)
                 ,*(uint *)(lVar4 + 0x898),*(int *)(lVar4 + 0x89c),*(undefined4 *)(lVar4 + 0x8a8),
                 "Setting StopEvent");
    }
    KeSetEvent(param_1[0x98],0,0);
    param_1[0x98] = 0;
    param_1[0x8d] = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x89) = 2;
    param_1[0x8d] = 0;
    iVar7 = SystemReserved1[0x12]._4_4_;
    if ((param_1[0x8e] == 0) &&
       ((((int)param_1[0xcc] != SystemReserved1[0x12]._4_4_ &&
         (*(int *)((longlong)param_1 + 0x664) != SystemReserved1[0x12]._4_4_)) &&
        ((int)param_1[0xcd] != SystemReserved1[0x12]._4_4_)))) {
      if (*(char *)((longlong)param_1 + 0x4b1) == '\0') {
        if ((int)param_1[0xcc] == -1) {
          *(int *)(param_1 + 0xcc) = SystemReserved1[0x12]._4_4_;
          lVar4 = 0x5d8;
        }
        else {
          if (*(int *)((longlong)param_1 + 0x664) != -1) {
            return;
          }
          *(int *)((longlong)param_1 + 0x664) = SystemReserved1[0x12]._4_4_;
          lVar4 = 0x618;
        }
        param_1[0x95] = param_1[0x95] + 1;
        lVar4 = lVar4 + (longlong)param_1;
        *(byte *)((longlong)param_1 + 0x44c) = *(byte *)((longlong)param_1 + 0x44c) & 0xfe;
      }
      else {
        if ((int)param_1[0xcd] != -1) {
          return;
        }
        *(byte *)((longlong)param_1 + 0x44c) = *(byte *)((longlong)param_1 + 0x44c) | 2;
        param_1[0x94] = param_1[0x94] + 1;
        *(int *)(param_1 + 0xcd) = iVar7;
        lVar4 = param_1[0xcb];
      }
      *(int *)((longlong)param_1 + 0x48c) = *(int *)((longlong)param_1 + 0x48c) + 1;
      *(int *)(param_1 + 0x93) = (int)param_1[0x93] + 1;
      param_1[0x8e] = lVar4;
      return;
    }
  }
  return;
}



===== InpPrepareToQueueWorkerLocked @ 140005090 =====

ulonglong InpPrepareToQueueWorkerLocked(longlong *param_1,char param_2,char param_3)

{
  uint uVar1;
  char cVar2;
  ulonglong uVar3;
  longlong lVar4;
  
  if (((int)param_1[0x89] == 1) && (param_1[0x98] != 0)) {
    if ((4 < DAT_140020050) && (cVar2 = _tlgKeywordOn(0x140020050,4), cVar2 != '\0')) {
      lVar4 = *param_1;
      VmbusTraceInfoRundownEvent
                ("InpPrepareToQueueWorkerLocked",0x1205,lVar4 + 0x6ec,*(undefined2 *)(lVar4 + 0xc90)
                 ,*(uint *)(lVar4 + 0x898),*(int *)(lVar4 + 0x89c),*(undefined4 *)(lVar4 + 0x8a8),
                 "Setting StopEvent");
    }
    KeSetEvent(param_1[0x98],0,0);
    param_1[0x98] = 0;
    param_1[0x8d] = 0;
    return 0;
  }
  uVar3 = 0;
  *(undefined4 *)(param_1 + 0x89) = 2;
  param_1[0x8d] = 0;
  uVar1 = SystemReserved1[0x12]._4_4_;
  if (param_1[0x8e] == 0) {
    uVar3 = (ulonglong)SystemReserved1[0x12]._4_4_;
    if (((*(uint *)(param_1 + 0xcc) != SystemReserved1[0x12]._4_4_) &&
        (*(uint *)((longlong)param_1 + 0x664) != SystemReserved1[0x12]._4_4_)) &&
       (*(uint *)(param_1 + 0xcd) != SystemReserved1[0x12]._4_4_)) {
      if ((param_2 == '\0') && (*(char *)((longlong)param_1 + 0x4b1) == '\0')) {
        if (*(uint *)(param_1 + 0xcc) == 0xffffffff) {
          *(uint *)(param_1 + 0xcc) = SystemReserved1[0x12]._4_4_;
          lVar4 = 0x5d8;
        }
        else {
          if (*(uint *)((longlong)param_1 + 0x664) != 0xffffffff) goto LAB_140005247;
          *(uint *)((longlong)param_1 + 0x664) = SystemReserved1[0x12]._4_4_;
          lVar4 = 0x618;
        }
        param_1[0x95] = param_1[0x95] + 1;
        param_1[0x8e] = lVar4 + (longlong)param_1;
        lVar4 = 0;
        *(byte *)((longlong)param_1 + 0x44c) =
             param_3 != '\0' | *(byte *)((longlong)param_1 + 0x44c) & 0xfe;
      }
      else {
        if (*(uint *)(param_1 + 0xcd) != 0xffffffff) goto LAB_140005247;
        *(byte *)((longlong)param_1 + 0x44c) = *(byte *)((longlong)param_1 + 0x44c) | 2;
        param_1[0x94] = param_1[0x94] + 1;
        *(uint *)(param_1 + 0xcd) = uVar1;
        lVar4 = param_1[0xcb];
        param_1[0x8e] = lVar4;
      }
      *(int *)((longlong)param_1 + 0x48c) = *(int *)((longlong)param_1 + 0x48c) + 1;
      return CONCAT71((int7)((ulonglong)lVar4 >> 8),1);
    }
  }
LAB_140005247:
  return uVar3 & 0xffffffffffffff00;
}



===== InRequeuePacket @ 140005254 =====

void InRequeuePacket(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined1 uVar5;
  
  plVar1 = (longlong *)(param_2 + 0x18);
  if ((*(byte *)(param_2 + 0x10) & 0x10) == 0) {
LAB_1400052c2:
    plVar3 = (longlong *)(param_1 + 0x500);
    lVar2 = *plVar3;
    if (*(longlong **)(lVar2 + 8) == plVar3) {
      *plVar1 = lVar2;
      *(longlong **)(param_2 + 0x20) = plVar3;
      *(longlong **)(lVar2 + 8) = plVar1;
      *plVar3 = (longlong)plVar1;
      *(int *)(param_1 + 0x524) = *(int *)(param_1 + 0x524) + -1;
      if (*(char *)(param_2 + 0x11) == '\0') {
        return;
      }
      goto LAB_140005309;
    }
  }
  else {
    uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x440);
    lVar2 = *plVar1;
    if ((*(longlong **)(lVar2 + 8) == plVar1) &&
       (plVar3 = *(longlong **)(param_2 + 0x20), (longlong *)*plVar3 == plVar1)) {
      *plVar3 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar3;
      *(int *)(param_1 + 0x480) = *(int *)(param_1 + 0x480) + -1;
      KeReleaseSpinLock(param_1 + 0x440,CONCAT71((int7)((ulonglong)plVar3 >> 8),uVar5));
      *(byte *)(param_2 + 0x10) = *(byte *)(param_2 + 0x10) & 0xef;
      goto LAB_1400052c2;
    }
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
LAB_140005309:
  *(int *)(param_1 + 0x528) = *(int *)(param_1 + 0x528) + -1;
  return;
}



===== OutCopyAndSendPacket @ 140005318 =====

ulonglong OutCopyAndSendPacket
                    (ulonglong param_1,undefined8 *param_2,uint *param_3,undefined8 param_4,
                    undefined1 param_5,uint param_6)

{
  uint uVar1;
  bool bVar2;
  ulonglong uVar3;
  undefined7 uVar4;
  uint uVar5;
  
  uVar4 = (undefined7)((ulonglong)param_4 >> 8);
  uVar5 = *(uint *)(param_1 + 0xac);
  uVar3 = 0;
  bVar2 = false;
  while( true ) {
    if (bVar2) {
      uVar3 = OutSendPacket(param_1,param_1 + 0xf0,uVar3,CONCAT71(uVar4,param_5),
                            param_6 & 0xfffffffe);
      return uVar3;
    }
    uVar1 = *param_3;
    if (uVar5 < uVar1) break;
    memmove((void *)(uVar3 + 0xf0 + param_1),(void *)*param_2,(ulonglong)uVar1);
    uVar3 = (ulonglong)((int)uVar3 + uVar1);
    uVar5 = uVar5 - uVar1;
    bVar2 = true;
  }
  return 0xc0000023;
}



===== VmbPacketSend @ 1400053d0 =====

int VmbPacketSend(ulonglong param_1,undefined8 param_2,uint param_3,longlong param_4)

{
  code *pcVar1;
  int iVar2;
  ulonglong uVar3;
  int iVar4;
  undefined1 *puVar5;
  ulonglong uVar6;
  longlong lVar7;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [40];
  
                    /* 0x53d0  99  VmbPacketSend */
  puVar5 = auStack_38;
  lVar7 = param_4;
  if (4 < *(int *)(param_1 + 0x18) - 1U) {
    param_1 = 5;
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)();
    puVar5 = auStack_30;
  }
  uVar3 = (ulonglong)*(uint *)(puVar5 + 0x60);
  if (lVar7 != 0) {
    param_4 = 0;
    *(uint *)(puVar5 + 0x20) = *(uint *)(puVar5 + 0x60) & 0xfffffffd;
    *(undefined8 *)(puVar5 + -8) = 0x140005426;
    OutSetupGpaDirectPacket(param_1,lVar7,0,0,*(uint *)(puVar5 + 0x20));
  }
  uVar6 = CONCAT71((int7)((ulonglong)param_4 >> 8),(char)uVar3) & 0xffffffffffffff01;
  if ((uVar3 & 4) == 0) {
    *(undefined4 *)(puVar5 + 0x20) = 1;
    *(undefined8 *)(puVar5 + -8) = 0x140005460;
    uVar3 = OutSendPacket(param_1,param_2,(ulonglong)param_3,uVar6,*(uint *)(puVar5 + 0x20));
    iVar2 = (int)uVar3;
  }
  else {
    *(undefined4 *)(puVar5 + 0x28) = 0;
    puVar5[0x20] = (char)uVar6;
    *(undefined8 *)(puVar5 + -8) = 0x14000544b;
    uVar3 = OutCopyAndSendPacket
                      (param_1,(undefined8 *)(puVar5 + 0x48),(uint *)(puVar5 + 0x50),uVar6,
                       puVar5[0x20],*(uint *)(puVar5 + 0x28));
    iVar2 = (int)uVar3;
  }
  iVar4 = 0;
  if (iVar2 < 0) {
    iVar4 = iVar2;
  }
  return iVar4;
}



===== VmbChannelSendSynchronousRequest @ 140005480 =====

void VmbChannelSendSynchronousRequest
               (longlong *param_1,undefined8 param_2,uint param_3,undefined8 param_4,uint param_5,
               ulonglong *param_6,undefined4 *param_7,longlong *param_8)

{
  undefined8 local_res10;
  uint local_res18 [4];
  
                    /* 0x5480  68  VmbChannelSendSynchronousRequest */
  local_res10 = param_2;
  local_res18[0] = param_3;
  VmbChannelSendMultipleBufferSynchronousRequest
            (param_1,&local_res10,local_res18,param_4,param_4,param_5,param_6,param_7,param_8);
  return;
}



===== VmbChannelSendMultipleBufferSynchronousRequest @ 1400054dc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong VmbChannelSendMultipleBufferSynchronousRequest
                    (longlong *param_1,undefined8 *param_2,uint *param_3,undefined8 param_4,
                    longlong param_5,uint param_6,ulonglong *param_7,undefined4 *param_8,
                    longlong *param_9)

{
  int iVar1;
  ulonglong uVar2;
  uint uVar3;
  bool bVar4;
  undefined1 auStackY_188 [32];
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  ulonglong uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  longlong *local_128;
  undefined8 local_120;
  undefined8 *local_118;
  undefined8 local_110;
  undefined2 local_fb;
  code *local_e0;
  ulonglong *local_d0;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined4 local_98;
  undefined4 local_8c;
  ulonglong local_48 [2];
  
  local_48[0] = __security_cookie ^ (ulonglong)auStackY_188;
  local_138 = 0;
  uStack_130 = 0;
  memset(&local_128,0,0xe0);
  local_158 = 0;
  uStack_150 = 0;
  local_148 = 0;
  uStack_140 = 0;
  KeInitializeEvent(&local_158,1);
  uVar2 = (ulonglong)param_6;
  local_d0 = local_48;
  local_e0 = KmclpSynchronousPacketCompletionRoutine;
  local_118 = &local_158;
  local_120 = 1;
  local_110 = 0;
  local_fb = 0;
  local_8c = 0;
  local_c8 = 0;
  local_98 = 1;
  local_b0 = 0;
  local_c0 = 0;
  local_b8 = 0;
  bVar4 = (param_6 & 1) != 0;
  if (bVar4) {
    local_c8 = *param_8;
    local_d0 = param_7;
  }
  uVar3 = 2;
  if ((param_9 != (longlong *)0x0) && (uVar3 = 2, *param_9 == 0)) {
    uVar3 = 6;
  }
  local_128 = param_1;
  if (param_5 != 0) {
    param_4 = 0;
    OutSetupGpaDirectPacket((longlong)&local_138,param_5,0,0,param_6 & 0xfffffffd);
  }
  if ((uVar2 & 4) == 0) {
    uVar2 = OutSendPacket((ulonglong)&local_138,*param_2,(ulonglong)*param_3,
                          CONCAT71((int7)((ulonglong)param_4 >> 8),bVar4),uVar3);
  }
  else {
    uVar2 = OutCopyAndSendPacket((ulonglong)&local_138,param_2,param_3,param_4,bVar4,uVar3);
  }
  if ((int)uVar2 == 0x103) {
    iVar1 = KeWaitForSingleObject(&local_158,0,0,0);
    if (iVar1 == 0x102) {
      OutCancelPacket(param_1,(longlong)&local_138);
      KeWaitForSingleObject(&local_158,0,0,0);
    }
    if (param_8 != (undefined4 *)0x0) {
      *param_8 = local_c4;
    }
    uVar2 = uStack_140 & 0xffffffff;
  }
  return uVar2;
}



===== VmbChannelSendInterrupt @ 1400056e0 =====

void VmbChannelSendInterrupt(longlong param_1)

{
                    /* 0x56e0  67  VmbChannelSendInterrupt */
  KmclSendSignal(param_1);
  return;
}



===== OutpTrySendCompletionPacket @ 140005700 =====

byte OutpTrySendCompletionPacket(longlong *param_1,undefined *param_2,void *param_3,uint param_4)

{
  uint uVar1;
  uint *puVar2;
  longlong lVar3;
  char cVar4;
  uint uVar5;
  undefined8 uVar6;
  uint uVar7;
  char *pcVar8;
  char cVar9;
  uint uVar10;
  undefined *puVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  void *pvVar17;
  ulonglong *puVar18;
  undefined4 uVar19;
  longlong lVar20;
  undefined4 *puVar21;
  size_t _Size;
  bool bVar22;
  longlong local_res8;
  
  _Size = (size_t)param_4;
  iVar15 = 0;
  uVar13 = param_4 + 0x10;
  if (0x7fff8 < uVar13) {
    iVar14 = -0x3ffffff3;
    pcVar8 = (char *)param_1;
    goto LAB_140005870;
  }
  uVar7 = *(uint *)(param_1 + 10);
  pvVar17 = (void *)(ulonglong)uVar7;
  uVar12 = param_4 + 0x17 & 0xfffffff8;
  uVar10 = *(uint *)(param_1 + 0x18);
  puVar21 = (undefined4 *)((ulonglong)uVar10 + param_1[9]);
  uVar1 = uVar12 + 8;
  uVar5 = (*(int *)((longlong)param_1 + 0xc4) - uVar10) - 8;
  if (uVar7 <= uVar5) {
    uVar5 = uVar5 + uVar7;
  }
  if (uVar5 < uVar1) {
    lVar3 = param_1[8];
    pcVar8 = (char *)(ulonglong)uVar7;
    uVar5 = *(uint *)(lVar3 + 4);
    lVar20 = lVar3;
    cVar4 = PkpValidatePointer(uVar7,uVar5);
    if (cVar4 == '\0') {
      iVar14 = -0x3ffffefe;
    }
    else {
      *(uint *)((longlong)param_1 + 0xc4) = uVar5;
      uVar5 = (uVar5 - uVar10) - 8;
      uVar16 = (uint)pvVar17;
      if (uVar16 <= uVar5) {
        uVar5 = uVar5 + uVar16;
      }
      if (uVar1 <= uVar5) goto code_r0x000140005787;
      if (uVar1 < uVar16) {
        if ((int)param_1[0x19] == 0) {
          PkpExpectInterrupt((longlong)(param_1 + 8),'\0');
          pvVar17 = (void *)(ulonglong)uVar7;
          lVar20 = lVar3;
        }
        uVar7 = uVar10 - (int)param_1[0x18];
        uVar5 = (uint)pvVar17;
        if (uVar5 <= uVar7) {
          uVar7 = uVar7 + uVar5;
        }
        uVar16 = uVar5 - 8;
        if (uVar7 + uVar1 < uVar5) {
          uVar16 = uVar7 + uVar1;
        }
        *(uint *)(lVar20 + 0xc) = uVar16;
        *(uint *)(param_1 + 0x19) = uVar12;
        LOCK();
        UNLOCK();
        uVar7 = *(uint *)(lVar20 + 4);
        pcVar8 = (char *)((ulonglong)pvVar17 & 0xffffffff);
        cVar4 = PkpValidatePointer(uVar5,uVar7);
        if (cVar4 == '\0') {
          iVar14 = -0x3ffffefe;
        }
        else {
          *(uint *)((longlong)param_1 + 0xc4) = uVar7;
          uVar7 = (uVar7 - uVar10) - 8;
          if ((uint)pvVar17 <= uVar7) {
            uVar7 = uVar7 + (uint)pvVar17;
          }
          if (uVar1 <= uVar7) goto code_r0x000140005787;
          iVar14 = -0x7ffffffb;
        }
      }
      else {
        iVar14 = -0x3ffffff3;
      }
    }
  }
  else {
code_r0x000140005787:
    *puVar21 = 0x2000b;
    *(short *)(puVar21 + 1) = (short)((ulonglong)uVar13 + 7 >> 3);
    *(undefined2 *)((longlong)puVar21 + 6) = 0;
    *(undefined **)(puVar21 + 2) = param_2;
    memmove(puVar21 + 4,param_3,_Size);
    uVar1 = *(uint *)(param_1 + 10);
    if ((uVar13 & 7) != 0) {
      puVar18 = (ulonglong *)((ulonglong)(uVar10 + (uVar13 & 0xfffffff8)) + param_1[9]);
      *puVar18 = (1L << (char)(uVar13 & 7) * '\b') - 1U & *puVar18;
      uVar13 = uVar12;
    }
    local_res8 = (ulonglong)uVar10 << 0x20;
    *(longlong *)((ulonglong)(uVar10 + uVar13) + param_1[9]) = local_res8;
    if ((int)param_1[0x19] != 0) {
      *(undefined4 *)(param_1 + 0x19) = 0;
      *(undefined4 *)(param_1[8] + 0xc) = 0;
    }
    uVar7 = *(uint *)(param_1 + 10);
    pcVar8 = (char *)(ulonglong)uVar7;
    uVar5 = uVar10 + uVar13 + 8;
    uVar13 = *(uint *)(param_1 + 0x18);
    pvVar17 = (void *)(ulonglong)uVar13;
    uVar10 = uVar5 - uVar1;
    if (uVar5 < uVar1) {
      uVar10 = uVar5;
    }
    puVar2 = (uint *)param_1[8];
    *(uint *)(param_1 + 0x18) = uVar10;
    *puVar2 = uVar10;
    LOCK();
    UNLOCK();
    uVar1 = puVar2[2];
    uVar10 = puVar2[1];
    if ((uVar10 < uVar7) && ((uVar10 & 7) == 0)) {
      *(uint *)((longlong)param_1 + 0xc4) = uVar10;
      if (uVar13 == uVar10) {
        if (uVar1 == 0) {
          iVar14 = 0x214;
          goto LAB_140005858;
        }
        *(longlong *)param_1[0x1b] = *(longlong *)param_1[0x1b] + 1;
      }
      iVar14 = 0;
    }
    else {
      iVar14 = -0x3ffffefe;
    }
  }
LAB_140005858:
  param_3 = pvVar17;
LAB_140005870:
  uVar19 = 2;
  if (5 < DAT_140020050) {
    cVar9 = '\x01';
    pcVar8 = (char *)&DAT_140020050;
    uVar19 = 2;
    cVar4 = _tlgKeywordOn(0x140020050,1);
    if (cVar4 != '\0') {
      pcVar8 = "OutpTrySendCompletionPacket";
      param_3 = (void *)(*param_1 + 0x6ec);
      VmbusTraceVerbPacketSend
                ("OutpTrySendCompletionPacket",0x53f,param_3,*(undefined2 *)(*param_1 + 0xc90),
                 param_2,cVar9);
      uVar19 = 2;
    }
  }
  puVar11 = param_2;
  if ((Microsoft_Windows_Hyper_V_KMCLEnableBits & 2) != 0) {
    lVar3 = *param_1;
    pcVar8 = (char *)(lVar3 + 0xa90);
    puVar11 = &VMBUS_SEND_PACKET;
    McTemplateK0jjxth_EtwWriteTransfer
              (pcVar8,&VMBUS_SEND_PACKET,param_3,lVar3 + 0xaa0,pcVar8,(char)param_2,1,
               (char)*(undefined2 *)(lVar3 + 0xc90));
    uVar19 = 2;
  }
  if (iVar14 < 0) {
    if (iVar14 == -0x7ffffffb) {
      if (((int)param_1[0x21] != 5) &&
         (*(undefined4 *)(param_1 + 0x21) = uVar19, (*(byte *)(param_1[0xb] + 0x40) & 1) == 0)) {
        OutpEnqueuePollingTimer((longlong)param_1);
      }
      iVar14 = -0x7ffffffb;
    }
    else if (iVar14 == -0x3ffffff3) {
      if (2 < DAT_140020050) {
        VmbusTraceErrorQueue
                  ("OutpProcessRingResult",0x2ca,*param_1 + 0x6ec,
                   (ulonglong)*(ushort *)(*param_1 + 0xc90),0xc000000d);
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x21) = 6;
      *(int *)((longlong)param_1 + 0x42c) = iVar14;
      if (2 < DAT_140020050) {
        VmbusTraceErrorQueueFailedStatus
                  (pcVar8,puVar11,*param_1 + 0x6ec,(ulonglong)*(ushort *)(*param_1 + 0xc90),iVar14);
      }
    }
  }
  else {
    *(int *)(param_1 + 0x42) = (int)param_1[0x42] + 1;
    *(int *)(param_1 + 0x39) = (int)param_1[0x39] + 1;
    bVar22 = iVar14 == 0x214;
    iVar14 = iVar15;
    if (bVar22) {
      uVar6 = KmclSendSignal(*param_1);
      if ((char)uVar6 == '\0') {
        param_1[0x3c] = param_1[0x3c] + 1;
      }
      else {
        param_1[0x3b] = param_1[0x3b] + 1;
      }
    }
  }
  return (byte)((uint)iVar14 >> 0x1f) ^ 1;
}



===== OutSendCompletionAtDpcLevel @ 140005b90 =====

undefined8
OutSendCompletionAtDpcLevel
          (longlong *param_1,longlong *param_2,void *param_3,uint param_4,char param_5)

{
  undefined *puVar1;
  uint *puVar2;
  longlong lVar3;
  char cVar4;
  uint uVar5;
  undefined8 uVar6;
  uint uVar7;
  char *pcVar8;
  char cVar9;
  uint uVar10;
  undefined *puVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  void *pvVar16;
  ulonglong *puVar17;
  longlong lVar18;
  undefined4 *puVar19;
  uint uVar20;
  uint uVar21;
  bool bVar22;
  
  pcVar8 = (char *)(param_1 + 0x20);
  pvVar16 = param_3;
  KeAcquireSpinLockAtDpcLevel();
  if ((int)param_1[0x21] == 1) {
    puVar1 = (undefined *)param_2[5];
    uVar12 = param_4 + 0x10;
    iVar14 = 0;
    if (uVar12 < 0x7fff9) {
      uVar7 = *(uint *)(param_1 + 10);
      pvVar16 = (void *)(ulonglong)uVar7;
      uVar21 = param_4 + 0x17 & 0xfffffff8;
      uVar10 = *(uint *)(param_1 + 0x18);
      puVar19 = (undefined4 *)((ulonglong)uVar10 + param_1[9]);
      uVar20 = uVar21 + 8;
      uVar5 = (*(int *)((longlong)param_1 + 0xc4) - uVar10) - 8;
      if (uVar7 <= uVar5) {
        uVar5 = uVar5 + uVar7;
      }
      if (uVar5 < uVar20) {
        lVar3 = param_1[8];
        uVar5 = *(uint *)(lVar3 + 4);
        lVar18 = lVar3;
        cVar4 = PkpValidatePointer(uVar7,uVar5);
        if (cVar4 == '\0') {
          iVar13 = -0x3ffffefe;
        }
        else {
          *(uint *)((longlong)param_1 + 0xc4) = uVar5;
          uVar5 = (uVar5 - uVar10) - 8;
          uVar15 = (uint)pvVar16;
          if (uVar15 <= uVar5) {
            uVar5 = uVar5 + uVar15;
          }
          if (uVar20 <= uVar5) goto code_r0x000140005c4d;
          if (uVar20 < uVar15) {
            if ((int)param_1[0x19] == 0) {
              PkpExpectInterrupt((longlong)(param_1 + 8),'\0');
              pvVar16 = (void *)(ulonglong)uVar7;
              lVar18 = lVar3;
            }
            uVar7 = uVar10 - (int)param_1[0x18];
            uVar5 = (uint)pvVar16;
            if (uVar5 <= uVar7) {
              uVar7 = uVar7 + uVar5;
            }
            uVar15 = uVar5 - 8;
            if (uVar7 + uVar20 < uVar5) {
              uVar15 = uVar7 + uVar20;
            }
            *(uint *)(lVar18 + 0xc) = uVar15;
            *(uint *)(param_1 + 0x19) = uVar21;
            LOCK();
            UNLOCK();
            uVar7 = *(uint *)(lVar18 + 4);
            cVar4 = PkpValidatePointer(uVar5,uVar7);
            if (cVar4 == '\0') {
              iVar13 = -0x3ffffefe;
            }
            else {
              *(uint *)((longlong)param_1 + 0xc4) = uVar7;
              uVar7 = (uVar7 - uVar10) - 8;
              if ((uint)pvVar16 <= uVar7) {
                uVar7 = uVar7 + (uint)pvVar16;
              }
              if (uVar20 <= uVar7) goto code_r0x000140005c4d;
              iVar13 = -0x7ffffffb;
            }
          }
          else {
            iVar13 = -0x3ffffff3;
          }
        }
      }
      else {
code_r0x000140005c4d:
        *puVar19 = 0x2000b;
        *(short *)(puVar19 + 1) = (short)((ulonglong)uVar12 + 7 >> 3);
        *(undefined2 *)((longlong)puVar19 + 6) = 0;
        *(undefined **)(puVar19 + 2) = puVar1;
        memmove(puVar19 + 4,param_3,(ulonglong)param_4);
        uVar20 = *(uint *)(param_1 + 10);
        if ((uVar12 & 7) != 0) {
          puVar17 = (ulonglong *)((ulonglong)(uVar10 + (uVar12 & 0xfffffff8)) + param_1[9]);
          *puVar17 = (1L << (char)(uVar12 & 7) * '\b') - 1U & *puVar17;
          uVar12 = uVar21;
        }
        *(ulonglong *)((ulonglong)(uVar10 + uVar12) + param_1[9]) = (ulonglong)uVar10 << 0x20;
        if ((int)param_1[0x19] != 0) {
          *(undefined4 *)(param_1 + 0x19) = 0;
          *(undefined4 *)(param_1[8] + 0xc) = 0;
        }
        uVar7 = *(uint *)(param_1 + 10);
        uVar5 = uVar10 + uVar12 + 8;
        uVar12 = *(uint *)(param_1 + 0x18);
        pvVar16 = (void *)(ulonglong)uVar12;
        uVar10 = uVar5 - uVar20;
        if (uVar5 < uVar20) {
          uVar10 = uVar5;
        }
        puVar2 = (uint *)param_1[8];
        *(uint *)(param_1 + 0x18) = uVar10;
        *puVar2 = uVar10;
        LOCK();
        UNLOCK();
        uVar20 = puVar2[2];
        uVar10 = puVar2[1];
        if ((uVar10 < uVar7) && ((uVar10 & 7) == 0)) {
          *(uint *)((longlong)param_1 + 0xc4) = uVar10;
          if (uVar12 == uVar10) {
            if (uVar20 == 0) {
              iVar13 = 0x214;
              goto LAB_140005d2f;
            }
            *(longlong *)param_1[0x1b] = *(longlong *)param_1[0x1b] + 1;
          }
          iVar13 = 0;
        }
        else {
          iVar13 = -0x3ffffefe;
        }
      }
    }
    else {
      iVar13 = -0x3ffffff3;
    }
LAB_140005d2f:
    if (5 < DAT_140020050) {
      cVar9 = '\x01';
      cVar4 = _tlgKeywordOn(0x140020050,1);
      if (cVar4 != '\0') {
        pvVar16 = (void *)(*param_1 + 0x6ec);
        VmbusTraceVerbPacketSend
                  ("OutpTrySendCompletionPacket",0x53f,pvVar16,*(undefined2 *)(*param_1 + 0xc90),
                   puVar1,cVar9);
      }
    }
    puVar11 = puVar1;
    if ((Microsoft_Windows_Hyper_V_KMCLEnableBits & 2) != 0) {
      lVar3 = *param_1;
      puVar11 = &VMBUS_SEND_PACKET;
      McTemplateK0jjxth_EtwWriteTransfer
                (lVar3 + 0xa90,&VMBUS_SEND_PACKET,pvVar16,lVar3 + 0xaa0,lVar3 + 0xa90,(char)puVar1,1
                 ,(char)*(undefined2 *)(lVar3 + 0xc90));
    }
    pcVar8 = (char *)0x2;
    if (iVar13 < 0) {
      if (iVar13 == -0x7ffffffb) {
        if (((int)param_1[0x21] != 5) &&
           (*(undefined4 *)(param_1 + 0x21) = 2, (*(byte *)(param_1[0xb] + 0x40) & 1) == 0)) {
          pcVar8 = (char *)param_1;
          OutpEnqueuePollingTimer((longlong)param_1);
        }
        iVar13 = -0x7ffffffb;
      }
      else if (iVar13 == -0x3ffffff3) {
        if (2 < DAT_140020050) {
          pcVar8 = "OutpProcessRingResult";
          VmbusTraceErrorQueue
                    ("OutpProcessRingResult",0x2ca,*param_1 + 0x6ec,
                     (ulonglong)*(ushort *)(*param_1 + 0xc90),0xc000000d);
        }
      }
      else {
        *(undefined4 *)(param_1 + 0x21) = 6;
        *(int *)((longlong)param_1 + 0x42c) = iVar13;
        if (2 < DAT_140020050) {
          VmbusTraceErrorQueueFailedStatus
                    (2,puVar11,*param_1 + 0x6ec,(ulonglong)*(ushort *)(*param_1 + 0xc90),iVar13);
        }
      }
    }
    else {
      *(int *)(param_1 + 0x42) = (int)param_1[0x42] + 1;
      *(int *)(param_1 + 0x39) = (int)param_1[0x39] + 1;
      bVar22 = iVar13 == 0x214;
      iVar13 = iVar14;
      if (bVar22) {
        pcVar8 = (char *)*param_1;
        uVar6 = KmclSendSignal((longlong)pcVar8);
        if ((char)uVar6 == '\0') {
          param_1[0x3c] = param_1[0x3c] + 1;
        }
        else {
          param_1[0x3b] = param_1[0x3b] + 1;
        }
      }
    }
    if (iVar13 < 0) goto LAB_14000605a;
LAB_140005d8c:
    uVar6 = 1;
  }
  else {
LAB_14000605a:
    if (param_5 == '\0') {
      param_2[6] = (longlong)param_3;
    }
    else {
      if (*(uint *)(param_2 + 3) < param_4) {
        MicrosoftTelemetryAssertTriggeredArgsKM(pcVar8,param_4,*(uint *)(param_2 + 3));
        goto LAB_140005d8c;
      }
      memmove((void *)param_2[6],param_3,(ulonglong)param_4);
    }
    *(uint *)(param_2 + 3) = param_4;
    *(undefined4 *)(param_2 + 2) = 2;
    OutpEnqueuePacket((longlong)param_1,param_2);
    uVar6 = 0;
  }
  KeReleaseSpinLockFromDpcLevel(param_1 + 0x20);
  return uVar6;
}



===== OutpTrySendControlPacket @ 1400060c0 =====

int OutpTrySendControlPacket(longlong *param_1,undefined8 param_2,ulonglong param_3,char param_4)

{
  ushort uVar1;
  uint uVar2;
  void *_Src;
  uint *puVar3;
  longlong lVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined8 uVar9;
  uint uVar10;
  char *pcVar11;
  uint uVar12;
  undefined *puVar13;
  uint uVar14;
  uint uVar15;
  ulonglong uVar16;
  ulonglong *puVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  uint uVar21;
  undefined8 *puVar22;
  undefined8 *puVar23;
  bool bVar24;
  byte bVar25;
  uint local_64;
  
  if (*(char *)(param_3 + 0x3d) != '\x02') {
    pcVar11 = (char *)(param_1 + 8);
    if (*(char *)(param_3 + 0x3d) == '\0') {
      uVar16 = (ulonglong)*(uint *)(param_3 + 0x38);
      puVar13 = *(undefined **)(param_3 + 0x30);
      uVar9 = PkSendPacketSimple((longlong *)pcVar11,puVar13,*(uint *)(param_3 + 0x38),param_2,
                                 param_4);
      iVar19 = (int)uVar9;
    }
    else {
      bVar25 = *(byte *)(param_3 + 0x3e) & 1;
      if (*(longlong **)(param_3 + 0x50) == (longlong *)0x0) {
        uVar16 = (ulonglong)*(uint *)(param_3 + 0x38);
        puVar13 = *(undefined **)(param_3 + 0x30);
        uVar9 = PkSendPacketGpaDirect
                          ((longlong *)pcVar11,puVar13,*(uint *)(param_3 + 0x38),param_2,
                           *(longlong **)(param_3 + 0x40),*(uint *)(param_3 + 0x48),
                           *(uint *)(param_3 + 0x4c),bVar25);
        iVar19 = (int)uVar9;
      }
      else {
        uVar16 = (ulonglong)*(uint *)(param_3 + 0x38);
        puVar13 = *(undefined **)(param_3 + 0x30);
        uVar9 = PkSendPacketGpaDirectList
                          ((longlong *)pcVar11,puVar13,*(uint *)(param_3 + 0x38),param_2,
                           *(longlong **)(param_3 + 0x50),*(uint *)(param_3 + 0x48),
                           *(uint *)(param_3 + 0x4c),bVar25);
        iVar19 = (int)uVar9;
      }
    }
    goto LAB_14000632b;
  }
  uVar1 = *(ushort *)(param_3 + 0x48);
  puVar22 = *(undefined8 **)(param_3 + 0x40);
  iVar19 = 0;
  uVar18 = *(uint *)(param_3 + 0x38);
  puVar13 = (undefined *)(ulonglong)uVar18;
  _Src = *(void **)(param_3 + 0x30);
  local_64 = 0;
  for (puVar23 = puVar22; puVar23 != (undefined8 *)0x0; puVar23 = (undefined8 *)*puVar23) {
    iVar19 = iVar19 + *(int *)(puVar23 + 1);
  }
  uVar10 = iVar19 * 8 + 0x18;
  pcVar11 = (char *)(ulonglong)uVar10;
  uVar21 = uVar10 + uVar18;
  if (0x7fff8 < uVar21) {
    iVar19 = -0x3ffffff3;
    uVar16 = param_3;
    goto LAB_14000632b;
  }
  uVar2 = *(uint *)(param_1 + 0x18);
  uVar15 = *(uint *)(param_1 + 10);
  uVar16 = (ulonglong)uVar15;
  uVar6 = uVar21 + 7 & 0xfffffff8;
  puVar23 = (undefined8 *)((ulonglong)uVar2 + param_1[9]);
  uVar8 = uVar6 + 8;
  uVar7 = (*(int *)((longlong)param_1 + 0xc4) - uVar2) - 8;
  if (uVar15 <= uVar7) {
    uVar7 = uVar7 + uVar15;
  }
  if (uVar7 < uVar8) {
    lVar4 = param_1[8];
    pcVar11 = (char *)(ulonglong)uVar15;
    puVar13 = (undefined *)(ulonglong)*(uint *)(lVar4 + 4);
    uVar7 = uVar8;
    uVar20 = uVar2;
    cVar5 = PkpValidatePointer(uVar15,*(uint *)(lVar4 + 4));
    if (cVar5 == '\0') {
      iVar19 = -0x3ffffefe;
    }
    else {
      *(int *)((longlong)param_1 + 0xc4) = (int)puVar13;
      uVar12 = ((int)puVar13 - uVar20) - 8;
      uVar14 = (uint)uVar16;
      if (uVar14 <= uVar12) {
        uVar12 = uVar12 + uVar14;
      }
      puVar13 = (undefined *)(ulonglong)uVar12;
      if (uVar7 <= uVar12) {
LAB_14000657f:
        pcVar11 = (char *)(ulonglong)(iVar19 * 8 + 0x18);
        goto LAB_1400061be;
      }
      if (uVar7 < uVar14) {
        if ((int)param_1[0x19] == 0) {
          PkpExpectInterrupt((longlong)(param_1 + 8),'\0');
          uVar16 = (ulonglong)uVar15;
          uVar7 = uVar8;
        }
        uVar8 = uVar20 - (int)param_1[0x18];
        uVar15 = (uint)uVar16;
        if (uVar15 <= uVar8) {
          uVar8 = uVar8 + uVar15;
        }
        uVar8 = uVar8 + uVar7;
        if (uVar15 <= uVar8) {
          uVar8 = uVar15 - 8;
        }
        *(uint *)(lVar4 + 0xc) = uVar8;
        *(uint *)(param_1 + 0x19) = uVar6;
        LOCK();
        UNLOCK();
        puVar13 = (undefined *)(ulonglong)*(uint *)(lVar4 + 4);
        pcVar11 = (char *)(uVar16 & 0xffffffff);
        cVar5 = PkpValidatePointer(uVar15,*(uint *)(lVar4 + 4));
        if (cVar5 == '\0') {
          iVar19 = -0x3ffffefe;
        }
        else {
          *(int *)((longlong)param_1 + 0xc4) = (int)puVar13;
          uVar8 = ((int)puVar13 - uVar20) - 8;
          if ((uint)uVar16 <= uVar8) {
            uVar8 = uVar8 + (uint)uVar16;
          }
          puVar13 = (undefined *)(ulonglong)uVar8;
          if (uVar7 <= uVar8) goto LAB_14000657f;
          iVar19 = -0x7ffffffb;
        }
      }
      else {
        iVar19 = -0x3ffffff3;
      }
    }
  }
  else {
LAB_1400061be:
    *puVar23 = CONCAT26(1,CONCAT24((short)((ulonglong)uVar21 + 7 >> 3),
                                   CONCAT22((short)((uint)pcVar11 >> 3),7)));
    puVar23[1] = param_2;
    puVar23[2] = CONCAT44(iVar19,(uint)uVar1);
    puVar23[3] = 0;
    if (puVar22 != (undefined8 *)0x0) {
      do {
        memmove(puVar23 + (ulonglong)local_64 + 3,(void *)((longlong)puVar22 + 0xc),
                (ulonglong)*(uint *)(puVar22 + 1) << 3);
        local_64 = local_64 + *(int *)(puVar22 + 1);
        puVar22 = (undefined8 *)*puVar22;
      } while (puVar22 != (undefined8 *)0x0);
      pcVar11 = (char *)(ulonglong)uVar10;
    }
    memmove((void *)((longlong)pcVar11 + (longlong)puVar23),_Src,(ulonglong)uVar18);
    uVar18 = *(uint *)(param_1 + 10);
    if ((uVar21 & 7) != 0) {
      puVar17 = (ulonglong *)((ulonglong)(uVar2 + (uVar21 & 0xfffffff8)) + param_1[9]);
      *puVar17 = (1L << (char)(uVar21 & 7) * '\b') - 1U & *puVar17;
      uVar21 = uVar6;
    }
    *(ulonglong *)((ulonglong)(uVar2 + uVar21) + param_1[9]) = (ulonglong)uVar2 << 0x20;
    if ((int)param_1[0x19] != 0) {
      *(undefined4 *)(param_1 + 0x19) = 0;
      *(undefined4 *)(param_1[8] + 0xc) = 0;
    }
    uVar21 = uVar2 + uVar21 + 8;
    if (uVar18 <= uVar21) {
      uVar21 = uVar21 - uVar18;
    }
    uVar18 = *(uint *)(param_1 + 0x18);
    puVar3 = (uint *)param_1[8];
    uVar10 = *(uint *)(param_1 + 10);
    pcVar11 = (char *)(ulonglong)uVar10;
    *(uint *)(param_1 + 0x18) = uVar21;
    *puVar3 = uVar21;
    LOCK();
    UNLOCK();
    uVar21 = puVar3[2];
    uVar16 = (ulonglong)uVar21;
    uVar8 = puVar3[1];
    puVar13 = (undefined *)(ulonglong)uVar8;
    if ((uVar8 < uVar10) && ((uVar8 & 7) == 0)) {
      *(uint *)((longlong)param_1 + 0xc4) = uVar8;
      if (uVar18 == uVar8) {
        if (uVar21 == 0) {
          iVar19 = 0x214;
          goto LAB_14000631b;
        }
        *(longlong *)param_1[0x1b] = *(longlong *)param_1[0x1b] + 1;
      }
      iVar19 = 0;
    }
    else {
      iVar19 = -0x3ffffefe;
    }
  }
LAB_14000631b:
LAB_14000632b:
  uVar18 = DAT_140020050;
  if (5 < DAT_140020050) {
    puVar13 = (undefined *)0x1;
    pcVar11 = (char *)&DAT_140020050;
    cVar5 = _tlgKeywordOn(0x140020050,1);
    if (cVar5 != '\0') {
      pcVar11 = "OutpTrySendControlPacket";
      puVar13 = (undefined *)0x510;
      uVar16 = *param_1 + 0x6ec;
      VmbusTraceVerbPacketSend
                ("OutpTrySendControlPacket",0x510,uVar16,*(undefined2 *)(*param_1 + 0xc90),param_2,
                 '\0');
      uVar18 = DAT_140020050;
    }
  }
  if ((Microsoft_Windows_Hyper_V_KMCLEnableBits & 2) != 0) {
    lVar4 = *param_1;
    puVar13 = &VMBUS_SEND_PACKET;
    pcVar11 = (char *)(lVar4 + 0xa90);
    McTemplateK0jjxth_EtwWriteTransfer
              (pcVar11,&VMBUS_SEND_PACKET,uVar16,lVar4 + 0xaa0,pcVar11,(char)param_2,0,
               (char)*(undefined2 *)(lVar4 + 0xc90));
    uVar18 = DAT_140020050;
  }
  if (iVar19 < 0) {
    if (iVar19 == -0x7ffffffb) {
      if (((int)param_1[0x21] != 5) &&
         (*(undefined4 *)(param_1 + 0x21) = 2, (*(byte *)(param_1[0xb] + 0x40) & 1) == 0)) {
        OutpEnqueuePollingTimer((longlong)param_1);
      }
      iVar19 = -0x7ffffffb;
    }
    else if (iVar19 == -0x3ffffff3) {
      if (2 < uVar18) {
        VmbusTraceErrorQueue
                  ("OutpProcessRingResult",0x2ca,*param_1 + 0x6ec,
                   (ulonglong)*(ushort *)(*param_1 + 0xc90),0xc000000d);
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x21) = 6;
      *(int *)((longlong)param_1 + 0x42c) = iVar19;
      if (2 < DAT_140020050) {
        VmbusTraceErrorQueueFailedStatus
                  (pcVar11,puVar13,*param_1 + 0x6ec,(ulonglong)*(ushort *)(*param_1 + 0xc90),iVar19)
        ;
      }
    }
  }
  else {
    if ((param_4 != '\0') &&
       ((KmclPerformanceCounterTimingCounters != 0 ||
        ((3 < uVar18 && (cVar5 = _tlgKeywordOn(0x140020050,2), cVar5 != '\0')))))) {
      uVar9 = KeQueryPerformanceCounter(0);
      bVar24 = KmclPerformanceCounterTimingCounters != 0;
      *(undefined8 *)(param_3 + 0x80) = uVar9;
      if (bVar24) {
        *(int *)(param_1 + 0x40) = (int)param_1[0x40] + 1;
      }
    }
    *(int *)(param_1 + 0x39) = (int)param_1[0x39] + 1;
    if (iVar19 == 0x214) {
      uVar9 = KmclSendSignal(*param_1);
      if ((char)uVar9 == '\0') {
        param_1[0x3c] = param_1[0x3c] + 1;
      }
      else {
        param_1[0x3b] = param_1[0x3b] + 1;
      }
    }
    iVar19 = 0;
  }
  return iVar19;
}



===== VmbPacketSendWithTransferPageRanges @ 140006740 =====

/* WARNING: Restarted to delay deadcode elimination for space: stack */

ulonglong VmbPacketSendWithTransferPageRanges
                    (ulonglong param_1,void *param_2,ulonglong param_3,undefined8 param_4,
                    undefined8 param_5,undefined8 param_6,uint param_7)

{
  code *pcVar1;
  bool bVar2;
  ulonglong uVar3;
  uint uVar4;
  uint7 uVar6;
  longlong lVar5;
  uint uVar7;
  
                    /* 0x6740  102  VmbPacketSendWithTransferPageRanges */
  uVar4 = (uint)param_3;
  if (4 < *(int *)(param_1 + 0x18) - 1U) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(5);
    pcVar1 = (code *)swi(3);
    uVar3 = (*pcVar1)();
    return uVar3;
  }
  *(undefined8 *)(param_1 + 0x40) = param_6;
  *(undefined1 *)(param_1 + 0x3d) = 2;
  *(short *)(param_1 + 0x48) = (short)param_4;
  if ((param_7 & 4) == 0) {
    uVar6 = (uint7)((ulonglong)param_4 >> 8);
    if ((param_7 & 1) == 0) {
      lVar5 = (ulonglong)uVar6 << 8;
    }
    else {
      lVar5 = CONCAT71(uVar6,1);
    }
    uVar3 = OutSendPacket(param_1,param_2,param_3,lVar5,1);
    uVar4 = (uint)uVar3;
  }
  else {
    uVar3 = 0;
    uVar7 = *(uint *)(param_1 + 0xac);
    bVar2 = false;
    while (!bVar2) {
      if (uVar7 < uVar4) {
        uVar4 = 0xc0000023;
        goto LAB_1400067a9;
      }
      memmove((void *)(uVar3 + 0xf0 + param_1),param_2,param_3 & 0xffffffff);
      uVar3 = (ulonglong)((int)uVar3 + uVar4);
      uVar7 = uVar7 - uVar4;
      bVar2 = true;
    }
    uVar3 = OutSendPacket(param_1,param_1 + 0xf0,uVar3,(ulonglong)(param_7 & 1),0);
    uVar4 = (uint)uVar3;
  }
LAB_1400067a9:
  uVar7 = 0;
  if ((int)uVar4 < 0) {
    uVar7 = uVar4;
  }
  return (ulonglong)uVar7;
}



===== OutSendPacket @ 140006870 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong OutSendPacket(ulonglong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                       uint param_5)

{
  ushort uVar1;
  uint uVar2;
  longlong *plVar3;
  void *_Src;
  uint *puVar4;
  longlong lVar5;
  char cVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined8 uVar10;
  ulonglong uVar11;
  uint uVar12;
  char *pcVar13;
  uint uVar14;
  undefined *puVar15;
  ulonglong uVar16;
  uint uVar17;
  ulonglong uVar18;
  undefined8 *puVar19;
  longlong *plVar20;
  longlong *plVar21;
  ulonglong *puVar22;
  char cVar23;
  uint uVar24;
  int iVar25;
  uint uVar26;
  undefined8 *puVar27;
  bool bVar28;
  undefined1 local_res8 [8];
  longlong *in_stack_ffffffffffffff48;
  byte bVar29;
  uint local_40 [6];
  
  cVar23 = (char)param_4;
  if (*(int *)(param_1 + 0x18) != 1) {
    if (2 < DAT_140020050) {
      VmbusTraceError(param_1,param_2,param_3,param_4);
    }
    return 0xc0000010;
  }
  plVar3 = *(longlong **)(param_1 + 0x10);
  *(undefined8 *)(param_1 + 0x30) = param_2;
  *(int *)(param_1 + 0x38) = (int)param_3;
  *(char *)(param_1 + 0x3c) = cVar23;
  local_res8[0] = KeAcquireSpinLockRaiseToDpc(plVar3 + 0x20);
  if ((int)plVar3[0x21] == 1) {
    uVar17 = 0;
    if (cVar23 != '\0') {
      puVar22 = (ulonglong *)plVar3[0x59];
      uVar16 = *puVar22;
      do {
        if (uVar16 == 0) goto LAB_140006b2d;
        uVar18 = uVar16 & 0xffffffff;
        uVar17 = (uint)uVar16;
        LOCK();
        uVar11 = *puVar22;
        bVar28 = uVar16 == uVar11;
        if (bVar28) {
          *puVar22 = puVar22[uVar18];
        }
        else {
          uVar16 = uVar11;
        }
        UNLOCK();
      } while (!bVar28);
      if (uVar17 == 0) {
LAB_140006b2d:
        *(undefined4 *)(plVar3 + 0x21) = 4;
        OutpEnqueuePollingDpc((longlong)plVar3);
        goto LAB_140006b45;
      }
      puVar22[uVar18] = param_1;
      *(uint *)(param_1 + 0x1c) = uVar17;
    }
    if (((*(char *)(param_1 + 0x3d) == '\x01') && (*(char *)(*plVar3 + 0xad9) != '\0')) &&
       ((*(int *)(param_1 + 0x18) != 2 || (*(longlong *)(param_1 + 0x50) == 0)))) {
      uVar8 = OutpPreparePacketForIsolation(plVar3,param_1);
      uVar16 = (ulonglong)uVar8;
      if (uVar8 == 0xc0000017) {
        *(undefined4 *)(plVar3 + 0x21) = 5;
        IoQueueWorkItem(*(undefined8 *)(*plVar3 + 0xb00),OutPacketAddMoreBounceWorkerRoutine,1,
                        plVar3);
      }
      else {
        if ((int)uVar8 < 0) {
          OutpTransitionPacketToReadyToComplete(plVar3,param_1);
          *(undefined4 *)(param_1 + 0x18) = 1;
          *(undefined1 *)(param_1 + 0x3d) = 0;
          if (2 < DAT_140020050) {
            VmbusTraceErrorQueue
                      ("OutSendPacket",0x69c,*plVar3 + 0x6ec,(ulonglong)*(ushort *)(*plVar3 + 0xc90)
                       ,uVar8);
          }
          goto LAB_140006c8f;
        }
        OutpPacketCopyToBouncePagesCycleLock((longlong)plVar3,param_1,local_res8);
        if (((int)plVar3[0x21] == 1) || ((int)plVar3[0x21] == 5)) goto LAB_14000691a;
      }
      goto LAB_140006b45;
    }
LAB_14000691a:
    plVar20 = (longlong *)(ulonglong)uVar17;
    if (*(char *)(param_1 + 0x3d) == '\x02') {
      uVar1 = *(ushort *)(param_1 + 0x48);
      iVar25 = 0;
      uVar16 = 0;
      uVar8 = *(uint *)(param_1 + 0x38);
      _Src = *(void **)(param_1 + 0x30);
      puVar19 = *(undefined8 **)(param_1 + 0x40);
      for (puVar27 = puVar19; puVar27 != (undefined8 *)0x0; puVar27 = (undefined8 *)*puVar27) {
        iVar25 = iVar25 + *(int *)(puVar27 + 1);
      }
      uVar14 = iVar25 * 8 + 0x18;
      puVar15 = (undefined *)(ulonglong)uVar14;
      uVar12 = uVar8 + uVar14;
      pcVar13 = (char *)(ulonglong)uVar12;
      plVar21 = plVar20;
      if (uVar12 < 0x7fff9) {
        uVar9 = *(uint *)(plVar3 + 10);
        uVar11 = (ulonglong)uVar9;
        uVar26 = (uVar12 + 7 & 0xfffffff8) + 8;
        uVar2 = *(uint *)(plVar3 + 0x18);
        puVar27 = (undefined8 *)((ulonglong)uVar2 + plVar3[9]);
        uVar7 = (*(int *)((longlong)plVar3 + 0xc4) - uVar2) - 8;
        if (uVar9 <= uVar7) {
          uVar7 = uVar7 + uVar9;
        }
        if (uVar7 < uVar26) {
          lVar5 = plVar3[8];
          pcVar13 = (char *)(ulonglong)uVar9;
          puVar15 = (undefined *)(ulonglong)*(uint *)(lVar5 + 4);
          cVar6 = PkpValidatePointer(uVar9,*(uint *)(lVar5 + 4));
          if (cVar6 == '\0') {
            uVar16 = 0xc0000102;
          }
          else {
            *(int *)((longlong)plVar3 + 0xc4) = (int)puVar15;
            uVar7 = ((int)puVar15 - uVar2) - 8;
            uVar24 = (uint)uVar11;
            if (uVar24 <= uVar7) {
              uVar7 = uVar7 + uVar24;
            }
            puVar15 = (undefined *)(ulonglong)uVar7;
            if (uVar26 <= uVar7) {
LAB_140007117:
              puVar15 = (undefined *)(ulonglong)(iVar25 * 8 + 0x18);
              goto LAB_1400069f0;
            }
            if (uVar26 < uVar24) {
              if ((int)plVar3[0x19] == 0) {
                PkpExpectInterrupt((longlong)(plVar3 + 8),'\0');
                uVar11 = (ulonglong)uVar9;
                plVar21 = plVar20;
              }
              uVar9 = uVar2 - (int)plVar3[0x18];
              uVar7 = (uint)uVar11;
              if (uVar7 <= uVar9) {
                uVar9 = uVar9 + uVar7;
              }
              uVar9 = uVar9 + uVar26;
              if (uVar7 <= uVar9) {
                uVar9 = uVar7 - 8;
              }
              *(uint *)(lVar5 + 0xc) = uVar9;
              *(uint *)(plVar3 + 0x19) = uVar26 - 8;
              LOCK();
              UNLOCK();
              puVar15 = (undefined *)(ulonglong)*(uint *)(lVar5 + 4);
              pcVar13 = (char *)(uVar11 & 0xffffffff);
              cVar6 = PkpValidatePointer(uVar7,*(uint *)(lVar5 + 4));
              if (cVar6 == '\0') {
                uVar16 = 0xc0000102;
              }
              else {
                *(int *)((longlong)plVar3 + 0xc4) = (int)puVar15;
                uVar9 = ((int)puVar15 - uVar2) - 8;
                if (uVar7 <= uVar9) {
                  uVar9 = uVar9 + uVar7;
                }
                puVar15 = (undefined *)(ulonglong)uVar9;
                if (uVar26 <= uVar9) goto LAB_140007117;
                uVar16 = 0x80000005;
              }
            }
            else {
              uVar16 = 0xc000000d;
            }
          }
        }
        else {
LAB_1400069f0:
          *puVar27 = CONCAT26(1,CONCAT24((short)((ulonglong)uVar12 + 7 >> 3),
                                         CONCAT22((short)((uint)puVar15 >> 3),7)));
          puVar27[1] = plVar21;
          puVar27[2] = CONCAT44(iVar25,(uint)uVar1);
          puVar27[3] = 0;
          if (puVar19 != (undefined8 *)0x0) {
            do {
              memmove(puVar27 + uVar16 + 3,(void *)((longlong)puVar19 + 0xc),
                      (ulonglong)*(uint *)(puVar19 + 1) << 3);
              uVar16 = (ulonglong)(uint)((int)uVar16 + *(int *)(puVar19 + 1));
              puVar19 = (undefined8 *)*puVar19;
            } while (puVar19 != (undefined8 *)0x0);
            puVar15 = (undefined *)(ulonglong)uVar14;
          }
          memmove(puVar15 + (longlong)puVar27,_Src,(ulonglong)uVar8);
          uVar8 = *(uint *)(plVar3 + 10);
          if ((uVar12 & 7) != 0) {
            puVar22 = (ulonglong *)((ulonglong)((uVar12 & 0xfffffff8) + uVar2) + plVar3[9]);
            *puVar22 = (1L << (char)(uVar12 & 7) * '\b') - 1U & *puVar22;
            uVar12 = uVar12 + 7 & 0xfffffff8;
          }
          *(ulonglong *)((ulonglong)(uVar2 + uVar12) + plVar3[9]) = (ulonglong)uVar2 << 0x20;
          if ((int)plVar3[0x19] != 0) {
            *(undefined4 *)(plVar3 + 0x19) = 0;
            *(undefined4 *)(plVar3[8] + 0xc) = 0;
          }
          uVar12 = uVar2 + uVar12 + 8;
          if (uVar8 <= uVar12) {
            uVar12 = uVar12 - uVar8;
          }
          uVar8 = *(uint *)(plVar3 + 0x18);
          puVar4 = (uint *)plVar3[8];
          uVar14 = *(uint *)(plVar3 + 10);
          pcVar13 = (char *)(ulonglong)uVar14;
          *(uint *)(plVar3 + 0x18) = uVar12;
          *puVar4 = uVar12;
          LOCK();
          UNLOCK();
          uVar12 = puVar4[2];
          plVar21 = (longlong *)(ulonglong)uVar12;
          uVar9 = puVar4[1];
          puVar15 = (undefined *)(ulonglong)uVar9;
          if ((uVar9 < uVar14) && ((uVar9 & 7) == 0)) {
            *(uint *)((longlong)plVar3 + 0xc4) = uVar9;
            if (uVar8 == uVar9) {
              if (uVar12 == 0) {
                uVar16 = 0x214;
                goto LAB_140006c11;
              }
              *(longlong *)plVar3[0x1b] = *(longlong *)plVar3[0x1b] + 1;
            }
            uVar16 = 0;
          }
          else {
            uVar16 = 0xc0000102;
          }
        }
      }
      else {
        uVar16 = 0xc000000d;
      }
    }
    else {
      uVar8 = *(uint *)(param_1 + 0x38);
      plVar21 = (longlong *)(ulonglong)uVar8;
      pcVar13 = (char *)(plVar3 + 8);
      if (*(char *)(param_1 + 0x3d) == '\0') {
        puVar15 = *(undefined **)(param_1 + 0x30);
        in_stack_ffffffffffffff48 =
             (longlong *)CONCAT71((int7)((ulonglong)in_stack_ffffffffffffff48 >> 8),cVar23);
        uVar16 = PkSendPacketSimple((longlong *)pcVar13,puVar15,uVar8,plVar20,cVar23);
        uVar16 = uVar16 & 0xffffffff;
      }
      else {
        in_stack_ffffffffffffff48 = *(longlong **)(param_1 + 0x50);
        bVar29 = *(byte *)(param_1 + 0x3e) & 1;
        if (in_stack_ffffffffffffff48 == (longlong *)0x0) {
          in_stack_ffffffffffffff48 = *(longlong **)(param_1 + 0x40);
          puVar15 = *(undefined **)(param_1 + 0x30);
          uVar16 = PkSendPacketGpaDirect
                             ((longlong *)pcVar13,puVar15,uVar8,plVar20,in_stack_ffffffffffffff48,
                              *(uint *)(param_1 + 0x48),*(uint *)(param_1 + 0x4c),bVar29);
          uVar16 = uVar16 & 0xffffffff;
        }
        else {
          puVar15 = *(undefined **)(param_1 + 0x30);
          uVar16 = PkSendPacketGpaDirectList
                             ((longlong *)pcVar13,puVar15,uVar8,plVar20,in_stack_ffffffffffffff48,
                              *(uint *)(param_1 + 0x48),*(uint *)(param_1 + 0x4c),bVar29);
          uVar16 = uVar16 & 0xffffffff;
        }
      }
    }
LAB_140006c11:
    uVar8 = DAT_140020050;
    if (DAT_140020050 < 6) {
    }
    else {
      puVar15 = (undefined *)0x1;
      pcVar13 = (char *)&DAT_140020050;
      cVar6 = _tlgKeywordOn(0x140020050,1);
      if (cVar6 != '\0') {
        pcVar13 = "OutpTrySendControlPacket";
        puVar15 = (undefined *)0x510;
        plVar21 = (longlong *)(*plVar3 + 0x6ec);
        VmbusTraceVerbPacketSend
                  ("OutpTrySendControlPacket",0x510,plVar21,*(undefined2 *)(*plVar3 + 0xc90),plVar20
                   ,'\0');
        uVar8 = DAT_140020050;
        in_stack_ffffffffffffff48 = plVar20;
      }
    }
    if ((Microsoft_Windows_Hyper_V_KMCLEnableBits & 2) != 0) {
      lVar5 = *plVar3;
      puVar15 = &VMBUS_SEND_PACKET;
      pcVar13 = (char *)(lVar5 + 0xa90);
      in_stack_ffffffffffffff48 = (longlong *)pcVar13;
      McTemplateK0jjxth_EtwWriteTransfer
                (pcVar13,&VMBUS_SEND_PACKET,plVar21,lVar5 + 0xaa0,pcVar13,(char)uVar17,0,
                 (char)*(undefined2 *)(lVar5 + 0xc90));
      uVar8 = DAT_140020050;
    }
    iVar25 = (int)uVar16;
    if (iVar25 < 0) {
      if (iVar25 != -0x7ffffffb) {
        if (iVar25 == -0x3ffffff3) {
          if (2 < uVar8) {
            VmbusTraceErrorQueue
                      ("OutpProcessRingResult",0x2ca,*plVar3 + 0x6ec,
                       (ulonglong)*(ushort *)(*plVar3 + 0xc90),0xc000000d);
          }
        }
        else {
          *(undefined4 *)(plVar3 + 0x21) = 6;
          *(int *)((longlong)plVar3 + 0x42c) = iVar25;
          if (2 < DAT_140020050) {
            VmbusTraceErrorQueueFailedStatus
                      (pcVar13,puVar15,*plVar3 + 0x6ec,(ulonglong)*(ushort *)(*plVar3 + 0xc90),
                       iVar25);
          }
        }
        OutpTransitionPacketToReadyToComplete(plVar3,param_1);
        *(undefined4 *)(param_1 + 0x18) = 1;
        *(undefined1 *)(param_1 + 0x3d) = 0;
        if (2 < DAT_140020050) {
          VmbusTraceErrorQueue
                    ("OutSendPacket",0x6c2,*plVar3 + 0x6ec,(ulonglong)*(ushort *)(*plVar3 + 0xc90),
                     iVar25);
        }
        goto LAB_140006c8f;
      }
      if (((int)plVar3[0x21] != 5) &&
         (*(undefined4 *)(plVar3 + 0x21) = 2, (*(byte *)(plVar3[0xb] + 0x40) & 1) == 0)) {
        OutpEnqueuePollingTimer((longlong)plVar3);
      }
      goto LAB_140006b45;
    }
    if ((cVar23 != '\0') &&
       ((KmclPerformanceCounterTimingCounters != 0 ||
        ((3 < uVar8 && (cVar6 = _tlgKeywordOn(0x140020050,2), cVar6 != '\0')))))) {
      uVar10 = KeQueryPerformanceCounter();
      bVar28 = KmclPerformanceCounterTimingCounters != 0;
      *(undefined8 *)(param_1 + 0x80) = uVar10;
      if (bVar28) {
        *(int *)(plVar3 + 0x40) = (int)plVar3[0x40] + 1;
      }
    }
    *(int *)(plVar3 + 0x39) = (int)plVar3[0x39] + 1;
    if (iVar25 == 0x214) {
      uVar10 = KmclSendSignal(*plVar3);
      if ((char)uVar10 == '\0') {
        plVar3[0x3c] = plVar3[0x3c] + 1;
      }
      else {
        plVar3[0x3b] = plVar3[0x3b] + 1;
      }
    }
    if (cVar23 == '\0') {
      if ((param_5 & 2) == 0) {
        uVar17 = *(uint *)(param_1 + 0x1c);
        if (uVar17 != 0) {
          local_40[1] = 0;
          local_40[2] = 0;
          if (uVar17 < *(uint *)(plVar3 + 0x5a)) {
            puVar22 = (ulonglong *)plVar3[0x59];
            uVar16 = *puVar22;
            do {
              puVar22[uVar17] = uVar16;
              LOCK();
              if (uVar16 == *puVar22) {
                *puVar22 = (ulonglong)uVar17;
                uVar11 = uVar16;
              }
              else {
                uVar11 = *puVar22;
              }
              UNLOCK();
              bVar28 = uVar11 != uVar16;
              uVar16 = uVar11;
            } while (bVar28);
          }
          else {
            local_40[0] = uVar17;
            RtlDeleteElementGenericTableAvl(plVar3[0x5e],local_40);
          }
          *(undefined4 *)(param_1 + 0x1c) = 0;
        }
        if ((*(char *)(param_1 + 0x3d) == '\x01') &&
           (*(undefined8 **)(param_1 + 0x50) != (undefined8 *)0x0)) {
          KmclpFreeBounceList(*plVar3,*(undefined8 **)(param_1 + 0x50));
          *(undefined8 *)(param_1 + 0x50) = 0;
        }
        *(undefined4 *)(param_1 + 0x18) = 4;
        KeReleaseSpinLock(plVar3 + 0x20,local_res8[0]);
        *(undefined4 *)(param_1 + 0x18) = 1;
        *(undefined1 *)(param_1 + 0x3d) = 0;
        *(undefined4 *)(param_1 + 0x74) = 0;
        if ((*(byte *)(param_1 + 0x3e) & 0x40) == 0) {
          (**(code **)(param_1 + 0x58))(param_1,0,*(undefined8 *)(param_1 + 0x68),0);
        }
        else {
          (**(code **)(param_1 + 0x58))
                    (param_1,*(undefined8 *)(param_1 + 0x60),0,*(undefined8 *)(param_1 + 0x68),
                     (ulonglong)in_stack_ffffffffffffff48 & 0xffffffff00000000);
        }
        return 0x103;
      }
      uVar16 = 0;
      goto LAB_140006c8f;
    }
    *(undefined4 *)(param_1 + 0x18) = 3;
  }
  else {
    if ((int)plVar3[0x21] == 0) {
      *(int *)(plVar3 + 0x41) = (int)plVar3[0x41] + 1;
      uVar16 = 0xc0000184;
      *(undefined4 *)(param_1 + 0x18) = 1;
      *(undefined1 *)(param_1 + 0x3d) = 0;
      if (2 < DAT_140020050) {
        VmbusTraceErrorQueue
                  ("OutSendPacket",0x6f1,*plVar3 + 0x6ec,(ulonglong)*(ushort *)(*plVar3 + 0xc90),
                   0xc0000184);
      }
      goto LAB_140006c8f;
    }
LAB_140006b45:
    if (((*(char *)(param_1 + 0x3d) == '\x01') &&
        (*(undefined8 **)(param_1 + 0x50) != (undefined8 *)0x0)) &&
       ((longlong *)plVar3[0x22] != plVar3 + 0x22)) {
      KmclpFreeBounceList(*plVar3,*(undefined8 **)(param_1 + 0x50));
      *(undefined8 *)(param_1 + 0x50) = 0;
    }
    if ((param_5 & 4) != 0) {
      *(int *)((longlong)plVar3 + 0x204) = *(int *)((longlong)plVar3 + 0x204) + 1;
      uVar16 = 0x80000005;
      OutpTransitionPacketToReadyToComplete(plVar3,param_1);
      *(undefined4 *)(param_1 + 0x18) = 1;
      *(undefined1 *)(param_1 + 0x3d) = 0;
      if (2 < DAT_140020050) {
        VmbusTraceErrorQueue
                  ("OutSendPacket",0x71c,*plVar3 + 0x6ec,(ulonglong)*(ushort *)(*plVar3 + 0xc90),
                   0x80000005);
      }
      goto LAB_140006c8f;
    }
    if ((param_5 & 1) != 0) {
      if (*(uint *)(param_1 + 0xac) < *(uint *)(param_1 + 0x38)) {
        *(int *)((longlong)plVar3 + 0x20c) = *(int *)((longlong)plVar3 + 0x20c) + 1;
        uVar16 = 0xc0000023;
        OutpTransitionPacketToReadyToComplete(plVar3,param_1);
        *(undefined4 *)(param_1 + 0x18) = 1;
        *(undefined1 *)(param_1 + 0x3d) = 0;
        if (2 < DAT_140020050) {
          VmbusTraceErrorQueue
                    ("OutSendPacket",0x728,*plVar3 + 0x6ec,(ulonglong)*(ushort *)(*plVar3 + 0xc90),
                     0xc0000023);
        }
        goto LAB_140006c8f;
      }
      memmove((void *)(param_1 + 0xf0),*(void **)(param_1 + 0x30),
              (ulonglong)*(uint *)(param_1 + 0x38));
      *(void **)(param_1 + 0x30) = (void *)(param_1 + 0xf0);
    }
    OutpEnqueuePacket((longlong)plVar3,(longlong *)(param_1 + 0x90));
    *(undefined4 *)(param_1 + 0x18) = 2;
    if ((int)plVar3[0x21] == 2) {
      *(int *)((longlong)plVar3 + 0x1cc) = *(int *)((longlong)plVar3 + 0x1cc) + 1;
    }
  }
  uVar16 = 0x103;
LAB_140006c8f:
  KeReleaseSpinLock(plVar3 + 0x20,local_res8[0]);
  if ((*(char *)(*plVar3 + 0xad9) != '\0') &&
     (*(uint *)(plVar3 + 0x39) == (*(uint *)(plVar3 + 0x39) / 10000) * 10000)) {
    KmclpFreeOldBounceBlocks(*plVar3);
  }
  return uVar16;
}



===== KmclSendSignal @ 140007410 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 KmclSendSignal(longlong param_1)

{
  undefined8 uVar1;
  uint7 uVar2;
  
  uVar1 = (**(code **)(param_1 + 0x9a0))
                    (*(undefined8 *)(param_1 + 0x910),*(char *)(param_1 + 0x8f9) == '\0');
  uVar2 = (uint7)((ulonglong)uVar1 >> 8);
  if ((char)uVar1 == '\0') {
    return (ulonglong)uVar2 << 8;
  }
  LOCK();
  *(int *)(param_1 + 0x694) = *(int *)(param_1 + 0x694) + 1;
  UNLOCK();
  return CONCAT71(uVar2,1);
}



===== OutpTransitionPacketToReadyToComplete @ 140007460 =====

void OutpTransitionPacketToReadyToComplete(longlong *param_1,longlong param_2)

{
  uint uVar1;
  ulonglong *puVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  bool bVar5;
  uint local_18 [4];
  
  uVar1 = *(uint *)(param_2 + 0x1c);
  if (uVar1 != 0) {
    local_18[1] = 0;
    local_18[2] = 0;
    if (uVar1 < *(uint *)(param_1 + 0x5a)) {
      puVar2 = (ulonglong *)param_1[0x59];
      uVar3 = *puVar2;
      do {
        puVar2[uVar1] = uVar3;
        LOCK();
        if (uVar3 == *puVar2) {
          *puVar2 = (ulonglong)uVar1;
          uVar4 = uVar3;
        }
        else {
          uVar4 = *puVar2;
        }
        UNLOCK();
        bVar5 = uVar4 != uVar3;
        uVar3 = uVar4;
      } while (bVar5);
    }
    else {
      local_18[0] = uVar1;
      RtlDeleteElementGenericTableAvl(param_1[0x5e],local_18);
    }
    *(undefined4 *)(param_2 + 0x1c) = 0;
  }
  if ((*(char *)(param_2 + 0x3d) == '\x01') &&
     (*(undefined8 **)(param_2 + 0x50) != (undefined8 *)0x0)) {
    KmclpFreeBounceList(*param_1,*(undefined8 **)(param_2 + 0x50));
    *(undefined8 *)(param_2 + 0x50) = 0;
  }
  *(undefined4 *)(param_2 + 0x18) = 4;
  return;
}



===== PkSendPacketSimple @ 140007508 =====

undefined8
PkSendPacketSimple(longlong *param_1,void *param_2,uint param_3,undefined8 param_4,char param_5)

{
  uint uVar1;
  undefined8 uVar2;
  uint uVar3;
  int local_res18 [4];
  undefined4 *local_38 [2];
  
  local_38[0] = (undefined4 *)0x0;
  local_res18[0] = 0;
  uVar3 = param_3 + 0x10;
  if (uVar3 < 0x7fff9) {
    uVar1 = *(uint *)(param_1 + 0x10);
    uVar2 = PkGetSendBufferEx(param_1,uVar1,uVar3,(longlong *)local_38,local_res18);
    if (-1 < (int)uVar2) {
      *local_38[0] = 0x20006;
      *(short *)(local_38[0] + 1) = (short)((ulonglong)uVar3 + 7 >> 3);
      *(ushort *)((longlong)local_38[0] + 6) = (ushort)(param_5 != '\0');
      *(undefined8 *)(local_38[0] + 2) = param_4;
      memmove(local_38[0] + 4,param_2,(ulonglong)param_3);
      uVar3 = PkWritePacketFooter(param_1,uVar1,uVar3);
      uVar2 = PkCompleteInsertion(param_1,uVar3);
    }
  }
  else {
    uVar2 = 0xc000000d;
  }
  return uVar2;
}



===== PkGetSendBufferEx @ 1400075e0 =====

undefined8
PkGetSendBufferEx(longlong *param_1,uint param_2,int param_3,longlong *param_4,int *param_5)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  longlong lVar8;
  
  uVar2 = *(uint *)(param_1 + 2);
  uVar7 = param_3 + 7U & 0xfffffff8;
  lVar8 = (ulonglong)param_2 + param_1[1];
  uVar1 = uVar7 + 8;
  uVar6 = (*(int *)((longlong)param_1 + 0x84) - param_2) - 8;
  if (uVar2 <= uVar6) {
    uVar6 = uVar6 + uVar2;
  }
  if (uVar6 < uVar1) {
    lVar3 = *param_1;
    uVar6 = *(uint *)(lVar3 + 4);
    cVar4 = PkpValidatePointer(uVar2,uVar6);
    if (cVar4 == '\0') {
      return 0xc0000102;
    }
    *(uint *)((longlong)param_1 + 0x84) = uVar6;
    uVar6 = (uVar6 - param_2) - 8;
    if (uVar2 <= uVar6) {
      uVar6 = uVar6 + uVar2;
    }
    if (uVar6 < uVar1) {
      if (uVar2 <= uVar1) {
        return 0xc000000d;
      }
      if ((int)param_1[0x11] == 0) {
        PkpExpectInterrupt((longlong)param_1,'\0');
      }
      uVar6 = param_2 - (int)param_1[0x10];
      if (uVar2 <= uVar6) {
        uVar6 = uVar6 + uVar2;
      }
      uVar5 = uVar2 - 8;
      if (uVar6 + uVar1 < uVar2) {
        uVar5 = uVar6 + uVar1;
      }
      *(uint *)(lVar3 + 0xc) = uVar5;
      *(uint *)(param_1 + 0x11) = uVar7;
      LOCK();
      UNLOCK();
      uVar6 = *(uint *)(lVar3 + 4);
      cVar4 = PkpValidatePointer(uVar2,uVar6);
      if (cVar4 == '\0') {
        return 0xc0000102;
      }
      *(uint *)((longlong)param_1 + 0x84) = uVar6;
      uVar6 = (uVar6 - param_2) - 8;
      if (uVar2 <= uVar6) {
        uVar6 = uVar6 + uVar2;
      }
      if (uVar6 < uVar1) {
        return 0x80000005;
      }
    }
  }
  *param_4 = lVar8;
  *param_5 = uVar6 - 8;
  return 0;
}



===== PkCompleteInsertion @ 140007720 =====

undefined8 PkCompleteInsertion(longlong *param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  uVar1 = *(uint *)(param_1 + 0x10);
  puVar5 = (undefined4 *)*param_1;
  uVar2 = *(uint *)(param_1 + 2);
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *puVar5 = param_2;
  LOCK();
  UNLOCK();
  iVar3 = puVar5[2];
  uVar4 = puVar5[1];
  if ((uVar2 <= uVar4) || ((uVar4 & 7) != 0)) {
    return 0xc0000102;
  }
  *(uint *)((longlong)param_1 + 0x84) = uVar4;
  if (uVar1 == uVar4) {
    if (iVar3 == 0) {
      return 0x214;
    }
    *(longlong *)param_1[0x13] = *(longlong *)param_1[0x13] + 1;
  }
  return 0;
}



===== PkWritePacketFooter @ 140007780 =====

uint PkWritePacketFooter(longlong *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  ulonglong *puVar4;
  
  uVar1 = *(uint *)(param_1 + 2);
  if ((param_3 & 7) != 0) {
    puVar4 = (ulonglong *)((ulonglong)((param_3 & 0xfffffff8) + param_2) + param_1[1]);
    *puVar4 = (1L << ((byte)param_3 & 7) * '\b') - 1U & *puVar4;
    param_3 = param_3 + 7 & 0xfffffff8;
  }
  *(ulonglong *)((ulonglong)(param_2 + param_3) + param_1[1]) = (ulonglong)param_2 << 0x20;
  if ((int)param_1[0x11] != 0) {
    *(undefined4 *)(param_1 + 0x11) = 0;
    *(undefined4 *)(*param_1 + 0xc) = 0;
  }
  uVar3 = param_2 + param_3 + 8;
  uVar2 = uVar3 - uVar1;
  if (uVar3 < uVar1) {
    uVar2 = uVar3;
  }
  return uVar2;
}



===== InpBatchProcessAndEnqueue @ 140007830 =====

undefined8 InpBatchProcessAndEnqueue(longlong *param_1,undefined8 param_2,ulonglong param_3)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  longlong *plVar4;
  longlong *plVar5;
  longlong *plVar6;
  code *pcVar7;
  char cVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  undefined8 uVar12;
  ulonglong uVar13;
  uint *puVar14;
  undefined4 *puVar15;
  char *pcVar16;
  char cVar17;
  undefined4 uVar18;
  ulonglong uVar19;
  uint uVar20;
  uint *puVar21;
  uint uVar22;
  ulonglong uVar23;
  uint *puVar24;
  longlong lVar25;
  ulonglong uVar26;
  uint uVar27;
  bool bVar28;
  char *pcVar29;
  
LAB_14000785b:
  while( true ) {
    plVar4 = (longlong *)param_1[0xa2];
    if (plVar4 == param_1 + 0xa2) {
      return 1;
    }
    sVar1 = *(short *)(plVar4 + 2);
    if (sVar1 == 0xb) break;
    if (((sVar1 != 6) && (sVar1 != 7)) && (sVar1 != 9)) {
      *(undefined4 *)(param_1 + 0xaf) = 3;
      *(undefined4 *)((longlong)param_1 + 0x57c) = 2;
      if (2 < DAT_140020050) {
        lVar25 = *param_1;
        pcVar16 = "InpBatchProcessAndEnqueue";
        uVar18 = 0x5e3;
        pcVar29 = "InFailedInvalidPacketType";
        uVar2 = *(ushort *)(lVar25 + 0xc90);
LAB_140007ca6:
        VmbusTraceErrorQueueFailed
                  (pcVar16,uVar18,lVar25 + 0x6ec,(ulonglong)uVar2,pcVar29,
                   "InFailedPacketPostProcess");
      }
      return 0xb;
    }
    param_3 = (ulonglong)((*(int *)(plVar4 + -0xc) - *(uint *)(plVar4 + 5)) - 0xa0);
    memset((void *)((ulonglong)*(uint *)(plVar4 + 5) + 0x38 + (longlong)plVar4),0,param_3);
    if (*(short *)(plVar4 + 2) == 9) {
      puVar24 = (uint *)(plVar4 + 10);
      uVar22 = *(uint *)((longlong)plVar4 + 0x34);
      uVar26 = (longlong)plVar4 + (ulonglong)*(uint *)((longlong)plVar4 + -0x2c) + 0x38;
      iVar3 = *(int *)((longlong)plVar4 + 0x2c);
      uVar20 = *(int *)(plVar4 + -5) - *(uint *)((longlong)plVar4 + -0x2c);
      lVar25 = (ulonglong)*(uint *)(plVar4 + -6) + 0x38 + (longlong)plVar4;
      uVar10 = 0;
      puVar21 = puVar24;
      uVar27 = 0;
      for (uVar23 = 0; (uint)uVar23 < uVar22; uVar23 = (ulonglong)((uint)uVar23 + 1)) {
        if ((((int)uVar10 < 0) ||
            (uVar19 = ((ulonglong)(iVar3 - 0x18) - (longlong)puVar21) + (longlong)puVar24,
            uVar19 < 8)) || ((*puVar21 == 0 || (0xfff < puVar21[1])))) {
LAB_140007cd1:
          if ((int)param_1[0x89] == 0) {
            return 0xb;
          }
          *(undefined4 *)(param_1 + 0xaf) = 1;
          *(undefined4 *)((longlong)param_1 + 0x57c) = 2;
          if (DAT_140020050 < 3) {
            return 0xb;
          }
          lVar25 = *param_1;
          pcVar16 = "InpBuildDataPacketComplete";
          uVar18 = 0x36c;
          pcVar29 = "InFailedMalformedGPAPacket";
          uVar2 = *(ushort *)(lVar25 + 0xc90);
          goto LAB_140007ca6;
        }
        uVar13 = (ulonglong)(puVar21[1] & 0xfff) + 0xfff + (ulonglong)*puVar21 >> 0xc;
        if (((0xfffff < (uint)uVar13) || (uVar9 = uVar27 + (uint)uVar13, uVar9 < uVar27)) ||
           (uVar19 < uVar13 * 8 + 8)) goto LAB_140007cd1;
        if (lVar25 != 0) {
          *(uint **)(lVar25 + uVar23 * 8) = puVar21;
        }
        puVar14 = puVar21 + uVar13 * 2 + 2;
        puVar11 = (uint *)0xffffffffffffffff;
        if (puVar21 <= puVar14) {
          puVar11 = puVar14;
        }
        uVar10 = -(uint)(puVar14 < puVar21) & 0xc0000095;
        puVar21 = puVar11;
        uVar27 = uVar9;
      }
      uVar10 = 0;
      uVar23 = uVar26;
      while ((param_3 = (ulonglong)uVar10, uVar10 < uVar22 &&
             (uVar19 = (ulonglong)*puVar24 + 0xfff + (ulonglong)(puVar24[1] & 0xfff) >> 0xc,
             (uint)uVar19 < 0x100000))) {
        *(ulonglong *)(lVar25 + (ulonglong)uVar22 * 8 + param_3 * 8) = uVar23;
        puVar24 = puVar24 + uVar19 * 2 + 2;
        uVar23 = uVar23 + uVar19 * 8 + 0x30;
        if ((uVar20 != 0) && (uVar20 + uVar26 < uVar23)) break;
        uVar10 = uVar10 + 1;
      }
      *(uint *)(plVar4 + -4) = uVar27;
      *(uint *)((longlong)plVar4 + -0x1c) = uVar22;
      *(uint *)((longlong)plVar4 + 0x4c) = uVar22;
    }
    plVar6 = plVar4 + -10;
    *(byte *)(plVar4 + -0xb) =
         (*(byte *)((longlong)plVar4 + 0x16) & 1) << 2 | *(byte *)(plVar4 + -0xb) & 0xfb;
    plVar5 = (longlong *)param_1[0xa1];
    if ((longlong *)*plVar5 != param_1 + 0xa0) goto LAB_140007d35;
    *plVar6 = (longlong)(param_1 + 0xa0);
    plVar4[-9] = (longlong)plVar5;
    *plVar5 = (longlong)plVar6;
    param_1[0xa1] = (longlong)plVar6;
    lVar25 = *plVar4;
    if (((longlong *)*(longlong *)(lVar25 + 8) != plVar4) ||
       (plVar6 = (longlong *)plVar4[1], (longlong *)*plVar6 != plVar4)) goto LAB_140007d35;
    bVar28 = KmclPerformanceCounterTimingCounters != 0;
    *plVar6 = lVar25;
    *(longlong **)(lVar25 + 8) = plVar6;
    if ((bVar28) ||
       ((uVar22 = DAT_140020050, 3 < DAT_140020050 &&
        (cVar8 = _tlgKeywordOn(0x140020050,2), cVar8 != '\0')))) {
      uVar12 = KeQueryPerformanceCounter(0);
      plVar4[-2] = uVar12;
      uVar22 = DAT_140020050;
    }
    if (5 < uVar22) {
      puVar15 = &DAT_140020050;
      cVar8 = _tlgKeywordOn(0x140020050,1);
      if (cVar8 != '\0') {
        param_3 = *param_1 + 0x6ec;
        VmbusTraceVerbPacketFetch
                  (puVar15,0x5bc,param_3,*(undefined2 *)(*param_1 + 0xc90),plVar4[3],'\0');
      }
    }
    if ((Microsoft_Windows_Hyper_V_KMCLEnableBits & 1) != 0) {
      lVar25 = *param_1;
      McTemplateK0jjxth_EtwWriteTransfer
                (lVar25 + 0xa90,&VMBUS_FETCH_PACKET,param_3,lVar25 + 0xaa0,lVar25 + 0xa90,
                 (char)plVar4[3],0,(char)*(undefined2 *)(lVar25 + 0xc90));
    }
  }
  plVar5 = (longlong *)param_1[0xa1];
  plVar6 = plVar4 + -4;
  if ((longlong *)*plVar5 == param_1 + 0xa0) {
    *plVar6 = (longlong)(param_1 + 0xa0);
    plVar4[-3] = (longlong)plVar5;
    *plVar5 = (longlong)plVar6;
    param_1[0xa1] = (longlong)plVar6;
    lVar25 = *plVar4;
    if (((longlong *)*(longlong *)(lVar25 + 8) == plVar4) &&
       (plVar6 = (longlong *)plVar4[1], (longlong *)*plVar6 == plVar4)) {
      *plVar6 = lVar25;
      *(longlong **)(lVar25 + 8) = plVar6;
      if (5 < DAT_140020050) {
        cVar17 = '\x01';
        puVar15 = &DAT_140020050;
        cVar8 = _tlgKeywordOn(0x140020050,1);
        if (cVar8 != '\0') {
          param_3 = *param_1 + 0x6ec;
          VmbusTraceVerbPacketFetch
                    (puVar15,0x5d1,param_3,*(undefined2 *)(*param_1 + 0xc90),plVar4[3],cVar17);
        }
      }
      if ((Microsoft_Windows_Hyper_V_KMCLEnableBits & 1) != 0) {
        lVar25 = *param_1;
        McTemplateK0jjxth_EtwWriteTransfer
                  (lVar25 + 0xa90,&VMBUS_FETCH_PACKET,param_3,lVar25 + 0xaa0,lVar25 + 0xa90,
                   (char)plVar4[3],1,(char)*(undefined2 *)(lVar25 + 0xc90));
      }
      goto LAB_14000785b;
    }
  }
LAB_140007d35:
  pcVar7 = (code *)swi(0x29);
  (*pcVar7)(3);
  pcVar7 = (code *)swi(3);
  uVar12 = (*pcVar7)();
  return uVar12;
}



===== InpPreprocessCompletionPacketLocked @ 140007d50 =====

longlong InpPreprocessCompletionPacketLocked
                   (longlong *param_1,undefined8 param_2,int param_3,int param_4,undefined8 *param_5
                   ,ulonglong *param_6)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  char cVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  longlong lVar9;
  longlong lVar10;
  byte bVar11;
  longlong lVar12;
  int iVar13;
  longlong lVar14;
  bool bVar15;
  uint local_48 [4];
  uint local_38 [4];
  
  if ((uint)(param_4 - param_3) <= *(uint *)((longlong)param_1 + 0x5ac)) {
    local_48[2] = 0;
    local_48[0] = 0;
    local_48[1] = 0;
    lVar12 = 0;
    uVar2 = param_5[1];
    if ((uint)uVar2 < *(uint *)(param_1 + 0x5a)) {
      lVar9 = *(longlong *)(param_1[0x59] + (uVar2 & 0xffffffff) * 8);
      if (lVar9 < 0) {
        lVar12 = lVar9;
      }
    }
    else if ((param_1[0x5e] != 0) &&
            (local_48[0] = (uint)uVar2,
            lVar9 = RtlLookupElementGenericTableAvl(param_1[0x5e],local_48), lVar9 != 0)) {
      lVar12 = *(longlong *)(lVar9 + 8);
    }
    if (lVar12 != 0) {
      if (*(int *)(lVar12 + 0x18) != 3) {
        KeAcquireSpinLockAtDpcLevel(param_1 + 0x20);
        if (*(int *)(lVar12 + 0x18) != 3) {
          KeReleaseSpinLockFromDpcLevel(param_1 + 0x20);
          return 0;
        }
        *(int *)(param_1 + 0x85) = (int)param_1[0x85] + 1;
        KeReleaseSpinLockFromDpcLevel();
      }
      if ((*(longlong *)(lVar12 + 0x80) != 0) &&
         ((KmclPerformanceCounterTimingCounters != 0 ||
          ((3 < DAT_140020050 && (cVar6 = _tlgKeywordOn(0x140020050,2), cVar6 != '\0')))))) {
        lVar10 = KeQueryPerformanceCounter(0);
        lVar9 = *(longlong *)(lVar12 + 0x78);
        lVar10 = lVar10 - *(longlong *)(lVar12 + 0x80);
        *(longlong *)(lVar12 + 0x80) = lVar10;
        lVar14 = *param_1;
        if ((*(ulonglong *)(lVar14 + 0x8b8) < (ulonglong)(lVar9 + lVar10)) &&
           ((3 < DAT_140020050 && (cVar6 = _tlgKeywordOn(0x140020050,2), cVar6 != '\0')))) {
          VmbusTraceWarnPacketDelay
                    ("OutFindAndReadyPacketForCompletion",0x8f3,lVar14 + 0x6ec,
                     (ulonglong)*(ushort *)(lVar14 + 0xc90),
                     (ulonglong)(lVar9 * 1000) / KmclPerformanceCounterFrequency,
                     (ulonglong)(lVar10 * 1000) / KmclPerformanceCounterFrequency);
        }
        if (KmclPerformanceCounterTimingCounters != 0) {
          param_1[0x3f] = param_1[0x3f] + *(longlong *)(lVar12 + 0x80);
        }
      }
      OutpPacketCopyBouncePagesToMdl((longlong)param_1,lVar12,'\x01');
      KeAcquireSpinLockAtDpcLevel();
      uVar1 = *(uint *)(lVar12 + 0x1c);
      if (uVar1 != 0) {
        local_38[2] = 0;
        local_38[0] = 0;
        local_38[1] = 0;
        if (uVar1 < *(uint *)(param_1 + 0x5a)) {
          puVar3 = (ulonglong *)param_1[0x59];
          uVar7 = *puVar3;
          do {
            puVar3[uVar1] = uVar7;
            LOCK();
            if (uVar7 == *puVar3) {
              *puVar3 = (ulonglong)uVar1;
              uVar8 = uVar7;
            }
            else {
              uVar8 = *puVar3;
            }
            UNLOCK();
            bVar15 = uVar8 != uVar7;
            uVar7 = uVar8;
          } while (bVar15);
        }
        else {
          local_38[0] = uVar1;
          RtlDeleteElementGenericTableAvl(param_1[0x5e],local_38);
        }
        *(undefined4 *)(lVar12 + 0x1c) = 0;
      }
      if ((*(char *)(lVar12 + 0x3d) == '\x01') &&
         (*(undefined8 **)(lVar12 + 0x50) != (undefined8 *)0x0)) {
        KmclpFreeBounceList(*param_1,*(undefined8 **)(lVar12 + 0x50));
        *(undefined8 *)(lVar12 + 0x50) = 0;
      }
      *(undefined4 *)(lVar12 + 0x18) = 4;
      KeReleaseSpinLockFromDpcLevel(param_1 + 0x20);
      lVar9 = lVar12 + 0xb0;
      *(longlong *)(lVar12 + 0xb8) = lVar9;
      *(longlong *)lVar9 = lVar9;
      uVar4 = *param_5;
      uVar5 = param_5[1];
      *(undefined8 *)(lVar12 + 0xd0) = param_2;
      *(int *)(lVar12 + 0xdc) = param_4;
      *(undefined8 *)(lVar12 + 0xc0) = uVar4;
      *(undefined8 *)(lVar12 + 200) = uVar5;
      *(int *)(lVar12 + 0xd8) = param_3;
      iVar13 = 0;
      if ((uint)(param_4 - param_3) <= *(uint *)(lVar12 + 0x70)) {
        iVar13 = param_4 - param_3;
      }
      bVar11 = *(byte *)(lVar12 + 0x3e) | 2;
      if (*(uint *)(lVar12 + 0x70) < (uint)(param_4 - param_3)) {
        bVar11 = *(byte *)(lVar12 + 0x3e) & 0xfd;
      }
      *(byte *)(lVar12 + 0x3e) = bVar11;
      *(int *)(lVar12 + 0x74) = iVar13;
      *param_6 = uVar2;
      return lVar12;
    }
  }
  return 0;
}



===== OutpPacketCopyBouncePagesToMdl @ 1400080c0 =====

void OutpPacketCopyBouncePagesToMdl(longlong param_1,longlong param_2,char param_3)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  void *pvVar4;
  undefined1 uVar5;
  uint uVar6;
  ulonglong uVar7;
  size_t _Size;
  void *_Dst;
  uint uVar8;
  void *_Src;
  longlong lVar9;
  size_t sVar10;
  undefined8 *puVar11;
  uint uVar12;
  uint local_res10;
  ulonglong local_res20;
  longlong local_88;
  uint local_80;
  void *local_78;
  void *local_70;
  longlong *local_60;
  longlong *local_58;
  
  uVar5 = 0;
  local_80 = 0;
  bVar3 = false;
  if ((*(char *)(param_2 + 0x3d) == '\x01') &&
     (local_60 = *(longlong **)(param_2 + 0x50), local_60 != (longlong *)0x0)) {
    bVar1 = *(byte *)(param_2 + 0x3e);
    if (param_3 == '\0') {
      bVar2 = bVar1 & 0x10;
    }
    else {
      bVar2 = bVar1 & 0x20;
    }
    if (bVar2 == 0) {
      uVar12 = *(uint *)(param_2 + 0x48);
      if ((((uVar12 != 0) || (*(int *)(param_2 + 0x4c) != 0)) || (uVar8 = 0, (bVar1 & 1) != 0)) &&
         (uVar8 = uVar12, (bVar1 & 1) != 0)) {
        local_80 = *(uint *)(param_2 + 0x4c);
      }
      puVar11 = *(undefined8 **)(param_2 + 0x40);
      uVar12 = local_80;
      do {
        uVar6 = *(uint *)((longlong)puVar11 + 0x2c);
        lVar9 = (ulonglong)uVar6 + puVar11[4];
        if ((*(byte *)((longlong)puVar11 + 10) & 5) == 0) {
          local_78 = (void *)MmMapLockedPagesSpecifyCache
                                       (puVar11,0,1,0,0,ExDefaultMdlProtection | 0x40000020);
          uVar6 = *(uint *)((longlong)puVar11 + 0x2c);
        }
        else {
          local_78 = (void *)puVar11[3];
        }
        pvVar4 = local_78;
        local_res20 = (ulonglong)uVar6;
        if (uVar12 == 0) {
          local_res10 = *(uint *)(puVar11 + 5);
          uVar6 = uVar12;
        }
        else {
          local_80 = 0;
          uVar6 = 0;
          local_res10 = uVar12;
        }
        sVar10 = (size_t)local_res10;
        local_58 = (longlong *)local_60[2];
        uVar12 = uVar6;
        if (local_58 != local_60 + 2) {
          _Src = local_78;
          local_88 = lVar9;
          do {
            local_70 = (void *)local_58[4];
            if ((int)local_res20 != 0) {
              if (param_3 == '\0') {
                memset(local_70,0,local_res20);
                sVar10 = (size_t)local_res10;
                _Src = local_78;
                lVar9 = local_88;
              }
            }
            uVar12 = 0x1000 - (int)local_res20;
            local_70 = (void *)((longlong)local_70 + local_res20);
            local_res20 = 0;
            if (uVar8 != 0) {
              uVar6 = uVar8;
              if (uVar12 < uVar8) {
                uVar6 = uVar12;
              }
              uVar7 = (ulonglong)uVar6;
              if (param_3 == '\0') {
                memset(local_70,0,(ulonglong)uVar6);
                sVar10 = (size_t)local_res10;
                _Src = local_78;
                lVar9 = local_88;
              }
              local_70 = (void *)((longlong)local_70 + uVar7);
              uVar12 = uVar12 - uVar6;
              lVar9 = lVar9 + uVar7;
              _Src = (void *)((longlong)_Src + uVar7);
              local_res20 = (ulonglong)-uVar6;
              uVar8 = uVar8 - uVar6;
              local_88 = lVar9;
              local_78 = _Src;
            }
            _Size = sVar10;
            if (uVar12 < (uint)sVar10) {
              _Size = (size_t)uVar12;
            }
            uVar6 = (uint)_Size;
            if (uVar6 != 0) {
              if (pvVar4 == (void *)0x0) {
                if (param_3 == '\0') {
                  uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x100);
                  bVar3 = true;
                  lVar9 = local_88;
                }
                _Src = (void *)OutpAcquireReservedMapping(param_1,param_3,puVar11,lVar9,uVar6);
              }
              if (param_3 == '\0') {
                _Dst = local_70;
              }
              else {
                _Dst = _Src;
                _Src = local_70;
              }
              memmove(_Dst,_Src,_Size);
              if ((pvVar4 == (void *)0x0) && (OutpReleaseReservedMapping(param_1,param_3), bVar3)) {
                KeReleaseSpinLock(param_1 + 0x100,uVar5);
                bVar3 = false;
              }
              uVar12 = uVar12 - uVar6;
              lVar9 = local_88 + _Size;
              _Src = (void *)((longlong)local_78 + _Size);
              local_70 = (void *)((longlong)local_70 + _Size);
              local_res10 = local_res10 - uVar6;
              sVar10 = (size_t)local_res10;
              local_88 = lVar9;
              local_78 = _Src;
            }
            if (uVar12 != 0) {
              if (param_3 == '\0') {
                memset(local_70,0,(ulonglong)uVar12);
                sVar10 = (size_t)local_res10;
                _Src = local_78;
                lVar9 = local_88;
              }
            }
            local_58 = (longlong *)*local_58;
          } while (local_58 != local_60 + 2);
          uVar12 = local_80;
        }
        local_60 = (longlong *)*local_60;
        puVar11 = (undefined8 *)*puVar11;
      } while (local_60 != (longlong *)0x0);
    }
  }
  return;
}



===== InpBuildDeferredDataPacket @ 140008450 =====

undefined8
InpBuildDeferredDataPacket
          (longlong *param_1,int param_2,undefined8 *param_3,uint param_4,int param_5,
          undefined8 *param_6,undefined8 *param_7)

{
  undefined8 *puVar1;
  uint uVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  undefined8 *puVar11;
  uint uVar12;
  longlong lVar13;
  uint uVar14;
  uint uVar15;
  
  lVar13 = *param_1;
  if (*(uint *)(lVar13 + 0x6c8) < param_5 - param_4) {
    if ((int)param_1[0x89] == 0) {
      return 0xb;
    }
    *(undefined4 *)((longlong)param_1 + 0x57c) = 1;
    *(undefined4 *)(param_1 + 0xaf) = 0;
    if (DAT_140020050 < 3) {
      return 0xb;
    }
    uVar9 = 0x3a1;
    pcVar5 = "InFailedMalformedPacket";
    goto LAB_1400086b7;
  }
  if (param_2 == 9) {
    if (param_4 < 0x18) {
      if ((int)param_1[0x89] == 0) {
        return 0xb;
      }
      *(undefined4 *)(param_1 + 0xaf) = 1;
      *(undefined4 *)((longlong)param_1 + 0x57c) = 1;
      if (DAT_140020050 < 3) {
        return 0xb;
      }
      uVar9 = 0x3b2;
    }
    else {
      uVar15 = *(uint *)((longlong)param_3 + 0x14);
      if ((uVar15 != 0) && (uVar15 <= param_4 - 0x18 >> 3)) {
        uVar12 = (param_4 - 0x18) + uVar15 * -8 >> 3;
        goto LAB_14000849c;
      }
      if ((int)param_1[0x89] == 0) {
        return 0xb;
      }
      *(undefined4 *)(param_1 + 0xaf) = 1;
      *(undefined4 *)((longlong)param_1 + 0x57c) = 1;
      if (DAT_140020050 < 3) {
        return 0xb;
      }
      lVar13 = *param_1;
      uVar9 = 0x3c2;
    }
    pcVar5 = "InFailedMalformedGPAPacket";
LAB_1400086b7:
    VmbusTraceErrorQueueFailed
              ("InpBuildDeferredDataPacket",uVar9,lVar13 + 0x6ec,
               (ulonglong)*(ushort *)(lVar13 + 0xc90),pcVar5,"InFailedPacketBuild");
    return 0xb;
  }
  uVar15 = 0;
  uVar12 = 0;
LAB_14000849c:
  puVar11 = param_3;
  if (param_7 != (undefined8 *)0x0) {
    puVar11 = param_7;
  }
  uVar6 = (uVar12 + uVar15 * 6) * 8 + 0xf & 0xfffffff0;
  uVar14 = param_5 + 0xfU & 0xfffffff0;
  uVar7 = uVar6 + (int)param_1[0xae] + uVar15 * 0x10 + uVar14;
  uVar10 = uVar7 + 0xa0;
  if ((*(byte *)((longlong)puVar11 + 6) & 1) != 0) {
    uVar2 = *(uint *)((longlong)param_1 + 0x5ac);
    if (*(char *)((longlong)param_1 + 0x4b3) == '\0') {
      if (uVar2 <= uVar7) goto LAB_140008520;
      uVar2 = uVar2 - uVar7;
    }
    uVar10 = uVar10 + uVar2;
  }
LAB_140008520:
  if (*(uint *)(param_1 + 0xb5) < uVar10) {
    if ((int)param_1[0x89] != 0) {
      *(undefined4 *)(param_1 + 0xaf) = 0;
      *(undefined4 *)((longlong)param_1 + 0x57c) = 1;
      if (2 < DAT_140020050) {
        VmbusTraceErrorQueueFailed
                  ("InpAllocatePacket",0x1c1,*param_1 + 0x6ec,
                   (ulonglong)*(ushort *)(*param_1 + 0xc90),"InFailedMalformedPacket",
                   "InFailedPacketBuild");
      }
    }
    uVar4 = 0xb;
  }
  else {
    puVar3 = (undefined8 *)
             ExAllocateFromNPagedLookasideList
                       ((ulonglong)(uVar10 - 1 >> 10) * 0x80 + param_1[0xb4] + 0x40);
    if (puVar3 == (undefined8 *)0x0) {
      LOCK();
      puVar3 = (undefined8 *)param_1[0xb7];
      param_1[0xb7] = 0;
      UNLOCK();
      if (puVar3 == (undefined8 *)0x0) {
        return 6;
      }
      *(undefined1 *)(puVar3 + 2) = 1;
    }
    else {
      *(undefined1 *)(puVar3 + 2) = 0;
    }
    param_1[0xad] = param_1[0xad] + (ulonglong)(*(int *)(puVar3 + 1) - uVar10);
    *(uint *)((longlong)puVar3 + 0xc) = uVar10;
    iVar8 = uVar15 * 0x10 + uVar14;
    *(int *)((longlong)puVar3 + 0x3c) = iVar8;
    *(uint *)(puVar3 + 8) = iVar8 + uVar6;
    *puVar3 = param_1;
    *(undefined4 *)(puVar3 + 5) = 0;
    puVar3[6] = 0;
    *(uint *)(puVar3 + 7) = uVar14;
    *(int *)((longlong)puVar3 + 0x54) = (int)param_1[0xae];
    puVar3[9] = 0;
    *(undefined1 *)((longlong)puVar3 + 0x11) = 0;
    puVar3[0xb] = 0;
    puVar3[0xc] = 0;
    uVar4 = puVar11[1];
    puVar1 = puVar3 + 0xd;
    puVar3[0xf] = *puVar11;
    puVar3[0x10] = uVar4;
    puVar3[0xe] = puVar1;
    *puVar1 = puVar1;
    *(uint *)(puVar3 + 0x13) = uVar12;
    *(int *)(puVar3 + 0x12) = param_5;
    puVar3[0x11] = param_3;
    *(uint *)((longlong)puVar3 + 0x94) = param_4;
    *(uint *)((longlong)puVar3 + 0x9c) = uVar15;
    *(int *)(param_1 + 0xa4) = (int)param_1[0xa4] + 1;
    *param_6 = puVar3;
    uVar4 = 1;
  }
  return uVar4;
}



===== PkpValidatePointer @ 1400087f0 =====

undefined1 PkpValidatePointer(uint param_1,uint param_2)

{
  if ((param_2 < param_1) && ((param_2 & 7) == 0)) {
    return 1;
  }
  return 0;
}



===== InpBuildDataPacketComplete @ 140008810 =====

undefined8 InpBuildDataPacketComplete(longlong *param_1,longlong param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  ulonglong uVar6;
  uint *puVar7;
  ulonglong uVar8;
  uint uVar9;
  uint uVar10;
  ulonglong uVar11;
  uint *puVar12;
  uint *puVar13;
  ulonglong uVar14;
  uint uVar15;
  longlong lVar16;
  
  memset((void *)(param_2 + 0x38 + (ulonglong)*(uint *)(param_2 + 0x28)),0,
         (ulonglong)((*(int *)(param_2 + -0x60) - *(uint *)(param_2 + 0x28)) - 0xa0));
  if (*(short *)(param_2 + 0x10) == 9) {
    puVar13 = (uint *)(param_2 + 0x50);
    uVar1 = *(uint *)(param_2 + 0x34);
    uVar14 = param_2 + 0x38 + (ulonglong)*(uint *)(param_2 + -0x2c);
    iVar2 = *(int *)(param_2 + 0x2c);
    uVar15 = *(int *)(param_2 + -0x28) - *(uint *)(param_2 + -0x2c);
    lVar16 = (ulonglong)*(uint *)(param_2 + -0x30) + 0x38 + param_2;
    uVar11 = 0;
    uVar4 = 0;
    puVar12 = puVar13;
    uVar10 = 0;
    for (uVar9 = 0; uVar9 < uVar1; uVar9 = uVar9 + 1) {
      if (((((int)uVar4 < 0) ||
           (uVar8 = ((ulonglong)(iVar2 - 0x18) - (longlong)puVar12) + (longlong)puVar13, uVar8 < 8))
          || (*puVar12 == 0)) || (0xfff < puVar12[1])) {
LAB_1400089e9:
        if ((int)param_1[0x89] != 0) {
          *(undefined4 *)(param_1 + 0xaf) = 1;
          *(undefined4 *)((longlong)param_1 + 0x57c) = 2;
          if (2 < DAT_140020050) {
            VmbusTraceErrorQueueFailed
                      ("InpBuildDataPacketComplete",0x36c,*param_1 + 0x6ec,
                       (ulonglong)*(ushort *)(*param_1 + 0xc90),"InFailedMalformedGPAPacket",
                       "InFailedPacketPostProcess");
          }
        }
        return 0xb;
      }
      uVar6 = (ulonglong)(puVar12[1] & 0xfff) + 0xfff + (ulonglong)*puVar12 >> 0xc;
      if (((0xfffff < (uint)uVar6) || (uVar3 = uVar10 + (uint)uVar6, uVar3 < uVar10)) ||
         (uVar8 < uVar6 * 8 + 8)) goto LAB_1400089e9;
      if (lVar16 != 0) {
        *(uint **)(lVar16 + (ulonglong)uVar9 * 8) = puVar12;
      }
      puVar7 = puVar12 + uVar6 * 2 + 2;
      puVar5 = (uint *)0xffffffffffffffff;
      if (puVar12 <= puVar7) {
        puVar5 = puVar7;
      }
      uVar4 = -(uint)(puVar7 < puVar12) & 0xc0000095;
      puVar12 = puVar5;
      uVar10 = uVar3;
    }
    uVar8 = uVar14;
    while (((uint)uVar11 < uVar1 &&
           (uVar6 = (ulonglong)*puVar13 + 0xfff + (ulonglong)(puVar13[1] & 0xfff) >> 0xc,
           (uint)uVar6 < 0x100000))) {
      *(ulonglong *)(lVar16 + (ulonglong)uVar1 * 8 + uVar11 * 8) = uVar8;
      puVar13 = puVar13 + uVar6 * 2 + 2;
      uVar8 = uVar8 + uVar6 * 8 + 0x30;
      if ((uVar15 != 0) && (uVar15 + uVar14 < uVar8)) break;
      uVar11 = (ulonglong)((uint)uVar11 + 1);
    }
    *(uint *)(param_2 + -0x20) = uVar10;
    *(uint *)(param_2 + -0x1c) = uVar1;
    *(uint *)(param_2 + 0x4c) = uVar1;
  }
  *(byte *)(param_2 + -0x58) =
       (*(byte *)(param_2 + 0x16) & 1) << 2 | *(byte *)(param_2 + -0x58) & 0xfb;
  return 1;
}



===== VmbChannelSetPollingMode @ 140008a70 =====

void VmbChannelSetPollingMode(longlong *param_1,char param_2)

{
                    /* 0x8a70  75  VmbChannelSetPollingMode */
  if ((*(byte *)(param_1 + 0x11f) & 0x20) == 0) {
    *(char *)((longlong)param_1 + 0x4b4) = param_2;
  }
  else {
    InSetPollingMode(param_1,param_2);
  }
  return;
}



===== InSetPollingMode @ 140008aa0 =====

void InSetPollingMode(longlong *param_1,char param_2)

{
  undefined1 uVar1;
  ulonglong uVar2;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x88);
  if (*(char *)((longlong)param_1 + 0x4b4) != param_2) {
    *(char *)((longlong)param_1 + 0x4b4) = param_2;
    *(char *)(*param_1 + 0x8f9) = param_2;
    switch((int)param_1[0x89]) {
    case 1:
      if (param_2 != '\0') {
        KeInitializeEvent(&local_28,1);
        param_1[0x97] = (longlong)&local_28;
        KeReleaseSpinLock(param_1 + 0x88,uVar1);
        KeWaitForSingleObject(&local_28,0,0,0,0);
        return;
      }
      break;
    case 2:
    case 4:
    case 5:
    case 6:
    case 7:
      *(undefined4 *)(param_1[0xb] + 8) = 1;
      if (((5 < DAT_140020050) && (((byte)DAT_140020060 & 1) != 0)) &&
         (((uint)DAT_140020068 & 1) == DAT_140020068)) {
        VmbusTraceVerbInterruptMaskSet
                  ("InSetPollingMode",0xed5,*param_1 + 0x6ec,
                   (ulonglong)*(ushort *)(*param_1 + 0xc90),'\x01');
      }
      *(undefined4 *)(param_1 + 0x89) = 3;
      break;
    case 3:
      uVar2 = InpDisableInterruptMaskingAndPollLocked(param_1);
      if ((char)uVar2 == '\0') {
        InpPrepareToQueueWorkerLocked(param_1,'\0','\0');
        InpReleaseLockAndPerformWork(param_1);
        return;
      }
      *(undefined4 *)(param_1 + 0x89) = 4;
    }
  }
  KeReleaseSpinLock(param_1 + 0x88,uVar1);
  return;
}



===== OutpAllocateHandle @ 140008c60 =====

ulonglong OutpAllocateHandle(longlong param_1,ulonglong param_2)

{
  ulonglong uVar1;
  ulonglong *puVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  
  puVar2 = *(ulonglong **)(param_1 + 0x2c8);
  uVar4 = *puVar2;
  do {
    uVar3 = uVar4;
    if (uVar3 == 0) {
      uVar5 = 0;
      goto LAB_140008ca7;
    }
    uVar5 = uVar3 & 0xffffffff;
    LOCK();
    uVar1 = *puVar2;
    if (uVar3 == uVar1) {
      *puVar2 = puVar2[uVar5];
      uVar4 = uVar3;
    }
    else {
      uVar4 = uVar1;
    }
    UNLOCK();
  } while (uVar3 != uVar1);
  if ((int)uVar3 == 0) {
LAB_140008ca7:
    *(undefined4 *)(param_1 + 0x108) = 4;
    OutpEnqueuePollingDpc(param_1);
  }
  else {
    puVar2[uVar5] = param_2;
    *(int *)(param_2 + 0x1c) = (int)uVar3;
  }
  return uVar5;
}



===== InpValidatePacket @ 140008cc0 =====

longlong InpValidatePacket(longlong param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  uint7 uVar2;
  
  uVar1 = *(short *)(param_1 + 2) * 8;
  uVar2 = (uint7)(uint3)(uVar1 >> 8);
  if ((uVar1 < 0x10) || (param_2 < uVar1)) {
    return (ulonglong)uVar2 << 8;
  }
  *param_3 = uVar1;
  return CONCAT71(uVar2,1);
}



===== InpParseGpaDirectPacket @ 140008cf0 =====

ulonglong InpParseGpaDirectPacket(longlong param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint *puVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  uint *puVar5;
  ulonglong uVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  ulonglong uVar11;
  uint uVar12;
  ulonglong uVar13;
  longlong lVar14;
  
  uVar13 = param_1 + 0xa0 + (ulonglong)*(uint *)(param_1 + 0x3c);
  puVar10 = (uint *)(param_1 + 0xb8);
  uVar8 = *(int *)(param_1 + 0x40) - *(uint *)(param_1 + 0x3c);
  lVar14 = param_1 + 0xa0 + (ulonglong)*(uint *)(param_1 + 0x38);
  uVar11 = 0;
  uVar3 = 0;
  puVar7 = puVar10;
  uVar9 = 0;
  for (uVar12 = 0; uVar12 < param_3; uVar12 = uVar12 + 1) {
    if (((((int)uVar3 < 0) ||
         (uVar6 = ((ulonglong)(param_2 - 0x18) - (longlong)puVar7) + (longlong)puVar10, uVar6 < 8))
        || (uVar3 = (ulonglong)*puVar7, *puVar7 == 0)) || (0xfff < puVar7[1])) {
LAB_140008d9f:
      return uVar3 & 0xffffffffffffff00;
    }
    uVar4 = (ulonglong)(puVar7[1] & 0xfff) + 0xfff + uVar3 >> 0xc;
    if (0xfffff < (uint)uVar4) goto LAB_140008d9f;
    uVar1 = uVar9 + (uint)uVar4;
    uVar3 = (ulonglong)uVar1;
    if ((uVar1 < uVar9) || (uVar3 = uVar4, uVar6 < uVar4 * 8 + 8)) goto LAB_140008d9f;
    if (lVar14 != 0) {
      *(uint **)(lVar14 + (ulonglong)uVar12 * 8) = puVar7;
    }
    puVar5 = puVar7 + uVar4 * 2 + 2;
    puVar2 = (uint *)0xffffffffffffffff;
    if (puVar7 <= puVar5) {
      puVar2 = puVar5;
    }
    uVar3 = (ulonglong)(-(uint)(puVar5 < puVar7) & 0xc0000095);
    puVar7 = puVar2;
    uVar9 = uVar1;
  }
  uVar6 = uVar13;
  while (((uint)uVar11 < param_3 &&
         (uVar4 = (ulonglong)*puVar10 + 0xfff + (ulonglong)(puVar10[1] & 0xfff) >> 0xc,
         (uint)uVar4 < 0x100000))) {
    *(ulonglong *)(lVar14 + (ulonglong)param_3 * 8 + uVar11 * 8) = uVar6;
    puVar10 = puVar10 + uVar4 * 2 + 2;
    uVar6 = uVar6 + uVar4 * 8 + 0x30;
    uVar3 = uVar4;
    if ((uVar8 != 0) && (uVar3 = uVar8 + uVar13, uVar3 < uVar6)) break;
    uVar11 = (ulonglong)((uint)uVar11 + 1);
  }
  *(uint *)(param_1 + 0x48) = uVar9;
  *(uint *)(param_1 + 0x4c) = param_3;
  *(uint *)(param_1 + 0xb4) = param_3;
  return CONCAT71((int7)(uVar3 >> 8),1);
}



===== InpFreePacket @ 140008e80 =====

void InpFreePacket(longlong param_1,longlong param_2)

{
  uint *puVar1;
  uint uVar2;
  
  if ((*(byte *)(param_2 + 0x10) & 1) == 0) {
    puVar1 = *(uint **)(param_1 + 0x5a0);
    uVar2 = *(uint *)(param_2 + 8) - 1 >> 10;
    if ((uVar2 < *puVar1) && (*(uint *)(param_2 + 8) == puVar1[(ulonglong)uVar2 * 0x20 + 0x1b])) {
      ExFreeToNPagedLookasideList(puVar1 + (ulonglong)uVar2 * 0x20 + 0x10,param_2);
      return;
    }
  }
  else if (param_2 == *(longlong *)(param_1 + 0x5b0)) {
    LOCK();
    *(longlong *)(param_1 + 0x5b8) = param_2;
    UNLOCK();
    return;
  }
  ExFreePoolWithTag(param_2,0x6e696b56);
  return;
}



===== VmbChannelPacketShortLifetime @ 140008f00 =====

void VmbChannelPacketShortLifetime(longlong *param_1)

{
  longlong *plVar1;
  undefined1 uVar2;
  char cVar3;
  int iVar4;
  char cVar5;
  
                    /* 0x8f00  59  VmbChannelPacketShortLifetime */
  plVar1 = (longlong *)*param_1;
  LOCK();
  cVar3 = *(char *)((longlong)param_1 + 0x11);
  *(char *)((longlong)param_1 + 0x11) = '\x01';
  UNLOCK();
  if (cVar3 == '\0') {
    if ((((int)plVar1[0x89] == 1) && ((void *)plVar1[0x8d] == SystemReserved1[0xf])) &&
       ((iVar4 = KeIsExecutingDpc(), iVar4 == 0 || ((char)plVar1[0xb0] != '\0')))) {
      *(int *)(plVar1 + 0xa5) = (int)plVar1[0xa5] + 1;
      return;
    }
    uVar2 = KeAcquireSpinLockRaiseToDpc(plVar1 + 0x88);
    iVar4 = (int)plVar1[0x91] + 1;
    *(int *)(plVar1 + 0x91) = iVar4;
    if ((((int)plVar1[0x89] == 4) &&
        (iVar4 + (int)plVar1[0xa5] == *(int *)((longlong)plVar1 + 0x52c))) &&
       (*(undefined4 *)(plVar1[0xb] + 8) = 1, 5 < DAT_140020050)) {
      cVar5 = '\x01';
      cVar3 = _tlgKeywordOn(0x140020050,1);
      if (cVar3 != '\0') {
        VmbusTraceVerbInterruptMaskSet
                  ("InMarkPacketShortLifetime",0x847,*plVar1 + 0x6ec,
                   (ulonglong)*(ushort *)(*plVar1 + 0xc90),cVar5);
      }
    }
    KeReleaseSpinLock(plVar1 + 0x88,uVar2);
  }
  return;
}



===== VmbChannelPacketGetExternalData @ 140009020 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int VmbChannelPacketGetExternalData(longlong *param_1,ulonglong param_2,longlong *param_3)

{
  longlong *plVar1;
  uint uVar2;
  longlong *plVar3;
  byte bVar4;
  int iVar5;
  longlong *plVar6;
  longlong lVar7;
  longlong *plVar8;
  undefined4 uVar9;
  ulonglong uVar10;
  
                    /* 0x9020  58  VmbChannelPacketGetExternalData */
  if (param_1[6] != 0) {
    *param_3 = param_1[6];
    return 0;
  }
  plVar8 = (longlong *)*param_1;
  if (*(char *)(*plVar8 + 0x6c0) == '\0') {
    return -0x3ffffe7c;
  }
  uVar2 = *(uint *)((longlong)param_1 + 0x4c);
  if (uVar2 == 0) {
LAB_14000910b:
    iVar5 = 0;
    *param_3 = param_1[6];
  }
  else {
    bVar4 = KeGetCurrentIrql();
    if (bVar4 <= *(byte *)(plVar8 + 0xb3)) {
      if ((param_2 & 1) == 0) {
        uVar9 = 2;
        if ((*(byte *)(param_1 + 2) & 0x10) != 0) {
          uVar9 = 4;
        }
      }
      else {
        uVar9 = 1;
      }
      *(undefined4 *)((longlong)param_1 + 0x44) = uVar9;
      lVar7 = (ulonglong)*(uint *)(param_1 + 7) + 0xa0 + (longlong)param_1;
      *(longlong **)(plVar8[0xb2] + 8) = param_1;
      plVar1 = (longlong *)(lVar7 + (ulonglong)uVar2 * 8);
      iVar5 = (**(code **)(*plVar8 + 0x9f0))
                        (*(undefined8 *)(*plVar8 + 0x910),plVar8[0xb2] + 0x10,
                         InpMapPacketMdlComplete,uVar9,lVar7,plVar1,uVar2);
      if (iVar5 == 0) {
        if (1 < uVar2) {
          uVar10 = (ulonglong)(uVar2 - 1);
          plVar8 = plVar1;
          plVar6 = plVar1;
          do {
            plVar6 = plVar6 + 1;
            plVar3 = (longlong *)*plVar8;
            plVar8 = plVar8 + 1;
            *plVar3 = *plVar6;
            uVar10 = uVar10 - 1;
          } while (uVar10 != 0);
        }
        param_1[6] = *plVar1;
        goto LAB_14000910b;
      }
      if (iVar5 == -0x3fffff28) {
        iVar5 = -0x3ffffeb8;
      }
      if (iVar5 == 0x103) {
        *(undefined4 *)(*param_1 + 0x584) = 1;
        return 0x103;
      }
      if (iVar5 != -0x3ffffeb8) {
        return iVar5;
      }
    }
    iVar5 = 0x103;
    *(undefined4 *)(*param_1 + 0x584) = 3;
  }
  return iVar5;
}



===== VmbPacketGetInlinePacketContextPointer @ 1400091d0 =====

undefined8 VmbPacketGetInlinePacketContextPointer(longlong param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  
                    /* 0x91d0  95  VmbPacketGetInlinePacketContextPointer */
  if (*(int *)(param_1 + 0x18) - 1U < 5) {
    return *(undefined8 *)(param_1 + 0x28);
  }
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(5);
  pcVar1 = (code *)swi(3);
  uVar2 = (*pcVar1)();
  return uVar2;
}



===== DvFreeHandleEntry @ 1400091f0 =====

void DvFreeHandleEntry(undefined8 *param_1,uint param_2)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  bool bVar4;
  uint local_18 [6];
  
  local_18[1] = 0;
  local_18[2] = 0;
  if (param_2 < *(uint *)(param_1 + 1)) {
    puVar1 = (ulonglong *)*param_1;
    uVar2 = *puVar1;
    do {
      puVar1[param_2] = uVar2;
      LOCK();
      if (uVar2 == *puVar1) {
        *puVar1 = (ulonglong)param_2;
        uVar3 = uVar2;
      }
      else {
        uVar3 = *puVar1;
      }
      UNLOCK();
      bVar4 = uVar3 != uVar2;
      uVar2 = uVar3;
    } while (bVar4);
  }
  else {
    local_18[0] = param_2;
    RtlDeleteElementGenericTableAvl(param_1[5],local_18);
  }
  return;
}



===== InpPacketFreedLocked @ 140009250 =====

void InpPacketFreedLocked(longlong *param_1,ulonglong param_2)

{
  int iVar1;
  char cVar2;
  
  LOCK();
  *(int *)(param_1 + 0x8f) = (int)param_1[0x8f] + 1;
  UNLOCK();
  param_1[0x92] = param_1[0x92] + (param_2 & 0xffffffff);
  iVar1 = (int)param_1[0x89];
  if (iVar1 == 1) {
    *(byte *)(param_1 + 0x8c) = *(byte *)(param_1 + 0x8c) | 2;
  }
  else {
    if (iVar1 == 5) {
      if ((4 < DAT_140020050) && (cVar2 = _tlgKeywordOn(0x140020050,2), cVar2 != '\0')) {
        VmbusTraceInfoQuotaExceeded
                  ("InpPacketFreedLocked",0x863,*param_1 + 0x6ec,
                   (ulonglong)*(ushort *)(*param_1 + 0xc90),'\0');
      }
    }
    else if (iVar1 != 6) {
      return;
    }
    InpPrepareToQueueWorkerLocked(param_1,'\0','\0');
  }
  return;
}



===== OutCompletePacketToClient @ 1400092f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void OutCompletePacketToClient(longlong param_1,ulonglong param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x18) = 1;
  *(undefined1 *)(param_1 + 0x3d) = 0;
  *(undefined4 *)(param_1 + 0x74) = param_3;
  if ((*(byte *)(param_1 + 0x3e) & 0x40) == 0) {
    (**(code **)(param_1 + 0x58))(param_1,param_2,*(undefined8 *)(param_1 + 0x68),param_3);
  }
  else {
    (**(code **)(param_1 + 0x58))
              (param_1,*(undefined8 *)(param_1 + 0x60),param_2 & 0xffffffff,
               *(undefined8 *)(param_1 + 0x68),param_3);
  }
  return;
}



===== VmbPacketSetCompletionRoutineEx @ 140009350 =====

void VmbPacketSetCompletionRoutineEx(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  
                    /* 0x9350  104  VmbPacketSetCompletionRoutineEx */
  if (*(int *)(param_1 + 0x18) - 1U < 5) {
    *(byte *)(param_1 + 0x3e) = *(byte *)(param_1 + 0x3e) | 0x40;
    *(undefined8 *)(param_1 + 0x58) = param_3;
    *(undefined8 *)(param_1 + 0x60) = param_2;
    return;
  }
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(5);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== OutPollQueue @ 140009380 =====

void OutPollQueue(longlong param_1,char param_2)

{
  undefined1 uVar1;
  char cVar2;
  undefined8 uVar3;
  
  if (param_2 == '\0') {
    if (*(int *)(param_1 + 200) == 0) {
      return;
    }
    uVar3 = PkIsOutgoingRingFull((longlong *)(param_1 + 0x40),*(int *)(param_1 + 200));
    if ((char)uVar3 != '\0') {
      return;
    }
  }
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x100);
  if (*(int *)(param_1 + 0x108) == 2) {
    OutpEnqueuePollingDpc(param_1);
    cVar2 = KeCancelTimer(param_1 + 0x348);
    if (cVar2 != '\0') {
      *(int *)(param_1 + 0x408) = *(int *)(param_1 + 0x408) + -1;
    }
  }
  KeReleaseSpinLock(param_1 + 0x100,uVar1);
  return;
}



===== DvpPushFreeEntries @ 140009430 =====

void DvpPushFreeEntries(ulonglong *param_1,uint param_2,ulonglong *param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  bool bVar3;
  
  uVar1 = *param_1;
  do {
    *param_3 = uVar1;
    LOCK();
    if (uVar1 == *param_1) {
      *param_1 = (ulonglong)param_2;
      uVar2 = uVar1;
    }
    else {
      uVar2 = *param_1;
    }
    UNLOCK();
    bVar3 = uVar2 != uVar1;
    uVar1 = uVar2;
  } while (bVar3);
  return;
}



===== InpUnmapPacketMdl @ 140009450 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void InpUnmapPacketMdl(longlong *param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  
  lVar2 = param_2 + 0xa0 + (ulonglong)*(uint *)(param_2 + 0x38);
  iVar1 = (**(code **)(*param_1 + 0x9f8))
                    (*(undefined8 *)(*param_1 + 0x910),lVar2,
                     lVar2 + (ulonglong)*(uint *)(param_2 + 0x4c) * 8,
                     (ulonglong)*(uint *)(param_2 + 0x4c),*(undefined4 *)(param_2 + 0x44));
  if (-1 < iVar1) {
    *(undefined8 *)(param_2 + 0x30) = 0;
  }
  return;
}



===== VmbPacketGetChannel @ 1400094b0 =====

undefined8 VmbPacketGetChannel(longlong param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  
                    /* 0x94b0  94  VmbPacketGetChannel */
  if (*(int *)(param_1 + 0x18) - 1U < 5) {
    return **(undefined8 **)(param_1 + 0x10);
  }
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(5);
  pcVar1 = (code *)swi(3);
  uVar2 = (*pcVar1)();
  return uVar2;
}



===== OutpPacketNeedsIsolation @ 1400094d0 =====

ulonglong OutpPacketNeedsIsolation(ulonglong *param_1,longlong param_2)

{
  ulonglong in_RAX;
  
  if (((*(char *)(param_2 + 0x3d) == '\x01') &&
      (in_RAX = *param_1, *(char *)(in_RAX + 0xad9) != '\0')) &&
     ((*(int *)(param_2 + 0x18) != 2 || (*(longlong *)(param_2 + 0x50) == 0)))) {
    return CONCAT71((int7)(in_RAX >> 8),1);
  }
  return in_RAX & 0xffffffffffffff00;
}



===== VmbChannelPacketEnableDeferredPause @ 140009500 =====

void VmbChannelPacketEnableDeferredPause(longlong *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined1 uVar5;
  
                    /* 0x9500  55  VmbChannelPacketEnableDeferredPause */
  lVar2 = *param_1;
  uVar5 = KeAcquireSpinLockRaiseToDpc(lVar2 + 0x440);
  plVar3 = *(longlong **)(lVar2 + 0x458);
  plVar1 = param_1 + 3;
  if (*plVar3 == lVar2 + 0x450) {
    *plVar1 = lVar2 + 0x450;
    param_1[4] = (longlong)plVar3;
    *plVar3 = (longlong)plVar1;
    *(longlong **)(lVar2 + 0x458) = plVar1;
    *(int *)(lVar2 + 0x480) = *(int *)(lVar2 + 0x480) + 1;
    KeReleaseSpinLock(lVar2 + 0x440,uVar5);
    *(byte *)(param_1 + 2) = *(byte *)(param_1 + 2) | 0x10;
    return;
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== VmbChannelGetPointer @ 140009590 =====

undefined8 VmbChannelGetPointer(longlong param_1)

{
                    /* 0x9590  23  VmbChannelGetPointer */
  return *(undefined8 *)(param_1 + 0x900);
}



===== VmbChannelPacketGetClientContext @ 1400095a0 =====

longlong VmbChannelPacketGetClientContext(longlong param_1)

{
                    /* 0x95a0  57  VmbChannelPacketGetClientContext */
  return (ulonglong)*(uint *)(param_1 + 0x40) + 0xa0 + param_1;
}



===== InpPostProcessMappedMdl @ 1400095b4 =====

void InpPostProcessMappedMdl(longlong param_1,undefined8 *param_2,uint param_3)

{
  undefined8 *puVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  
  if (1 < param_3) {
    uVar2 = (ulonglong)(param_3 - 1);
    puVar4 = param_2;
    puVar3 = param_2;
    do {
      puVar3 = puVar3 + 1;
      puVar1 = (undefined8 *)*puVar4;
      puVar4 = puVar4 + 1;
      *puVar1 = *puVar3;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  *(undefined8 *)(param_1 + 0x30) = *param_2;
  return;
}



===== KmclpVmbusManualIsr @ 1400095f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

bool KmclpVmbusManualIsr(longlong param_1)

{
  char cVar1;
  
  *(longlong *)(param_1 + 0x680) = *(longlong *)(param_1 + 0x680) + 1;
  cVar1 = (**(code **)(param_1 + 0x850))();
  if (cVar1 == '\0') {
    *(int *)(param_1 + 0x690) = *(int *)(param_1 + 0x690) + 1;
  }
  return cVar1 != '\0';
}



===== KmclpContinueChannelRundownAndUnlock @ 14000962c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void KmclpContinueChannelRundownAndUnlock(longlong *param_1,longlong *param_2,longlong *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  char cVar3;
  int iVar4;
  ulonglong uVar5;
  longlong lVar6;
  uint uVar7;
  undefined4 uVar8;
  char *pcVar9;
  longlong local_res8;
  longlong local_res10;
  undefined1 uVar10;
  longlong local_248;
  longlong lStack_240;
  longlong local_238;
  longlong lStack_230;
  longlong local_228;
  longlong lStack_220;
  longlong local_218;
  longlong lStack_210;
  longlong local_208;
  longlong lStack_200;
  longlong local_1f8;
  longlong lStack_1f0;
  longlong local_1e8;
  longlong lStack_1e0;
  longlong local_1d8;
  longlong lStack_1d0;
  longlong local_1c8;
  longlong lStack_1c0;
  longlong local_1b8;
  longlong lStack_1b0;
  longlong local_1a8;
  longlong lStack_1a0;
  longlong local_198;
  longlong lStack_190;
  longlong local_188;
  longlong lStack_180;
  longlong local_178;
  longlong lStack_170;
  longlong local_168;
  longlong lStack_160;
  longlong local_158;
  longlong lStack_150;
  longlong local_148;
  longlong lStack_140;
  longlong local_138;
  longlong lStack_130;
  longlong local_128;
  longlong lStack_120;
  longlong local_118;
  longlong lStack_110;
  longlong local_108;
  longlong lStack_100;
  longlong local_f8;
  longlong lStack_f0;
  longlong local_e8;
  longlong lStack_e0;
  longlong local_d8;
  longlong lStack_d0;
  longlong local_c8;
  longlong lStack_c0;
  longlong local_b8;
  longlong lStack_b0;
  longlong local_a8;
  longlong lStack_a0;
  longlong local_98;
  longlong lStack_90;
  longlong local_88;
  longlong lStack_80;
  longlong local_78;
  longlong lStack_70;
  longlong local_68;
  longlong lStack_60;
  longlong local_58;
  longlong lStack_50;
  longlong local_48;
  longlong lStack_40;
  
  local_res8 = 0;
  local_res10 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_2 = (longlong *)0x62;
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x62,param_3,param_1,(char)param_1[0x113]);
  }
  pcVar9 = "";
  if (5 < DAT_140020050) {
    param_2 = (longlong *)0x4;
    cVar3 = _tlgKeywordOn(0x140020050,4);
    if (cVar3 != '\0') {
      param_3 = (longlong *)((longlong)param_1 + 0x6ec);
      param_2 = (longlong *)0xddc;
      VmbusTraceVerbRundownFnStart
                ("KmclpContinueChannelRundownAndUnlock",0xddc,param_3,(short)param_1[0x192],
                 *(uint *)(param_1 + 0x113),*(int *)((longlong)param_1 + 0x89c),(int)param_1[0x115],
                 pcVar9);
    }
  }
  iVar4 = (int)param_1[0x113];
  if (iVar4 == 3) {
    iVar4 = *(int *)((longlong)param_1 + 0x89c);
    if (iVar4 != 1) {
      if ((iVar4 == 4) || ((char)param_1[0xd8] == '\0')) {
        *(byte *)(param_1 + 0x11f) = *(byte *)(param_1 + 0x11f) & 0xfd;
        KmclpDisableClosedChannel((longlong)param_1);
      }
      else if (iVar4 != 3) {
        *(undefined4 *)(param_1 + 0x113) = 5;
        LOCK();
        plVar2 = param_1 + 0x194;
        lVar6 = *plVar2;
        *(int *)plVar2 = (int)*plVar2 + 1;
        UNLOCK();
        uVar7 = (int)lVar6 + 1;
        uVar5 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar5 == 0) {
          iVar4 = (int)((ulonglong)((longlong)(int)uVar7 * -0x2aaaaaab) >> 0x20);
          iVar4 = ((iVar4 >> 2) - (iVar4 >> 0x1f)) * 0x18;
        }
        else {
          iVar4 = (uVar7 / 0x18) * -0x18;
        }
        param_2 = (longlong *)(longlong)(int)(uVar7 + iVar4);
        *(char *)((longlong)param_1 + (longlong)param_2 * 6 + 0xca4) = (char)param_1[0x113];
        *(undefined1 *)((longlong)param_1 + (longlong)param_2 * 6 + 0xca5) =
             *(undefined1 *)((longlong)param_1 + 0x89c);
        *(short *)((longlong)param_1 + (longlong)param_2 * 6 + 0xca6) = (short)param_1[0x115];
        *(undefined2 *)((longlong)param_1 + (longlong)param_2 * 6 + 0xca8) = 0xf54;
        if (4 < DAT_140020050) {
          param_3 = &local_228;
          local_228 = param_1[0x152];
          lStack_220 = param_1[0x153];
          param_2 = &local_248;
          local_248 = param_1[0x150];
          lStack_240 = param_1[0x151];
          local_238 = param_1[0x154];
          lStack_230 = param_1[0x155];
          VmbusTraceInfoChannelStateChange
                    (&local_238,param_2,param_3,(ulonglong)*(ushort *)(param_1 + 0x192),
                     (int)param_1[0x113],*(undefined4 *)((longlong)param_1 + 0x89c),
                     (int)param_1[0x115],0xf54);
        }
        KmclpStartWaitForAction((longlong)param_1,param_2,param_3);
      }
    }
LAB_14000acc9:
    KmclpFinishSuspendProcessAndUnlock((longlong)param_1,param_2,param_3);
    goto LAB_14000acd1;
  }
  if (iVar4 == 4) {
    if (*(int *)((longlong)param_1 + 0x89c) == 1) goto LAB_14000acc9;
    if ((*(char *)((longlong)param_1 + 0x706) != '\0') && (*(int *)((longlong)param_1 + 0x89c) == 3)
       ) {
      local_res8 = param_1[0x114];
      param_1[0x114] = 0;
      if ((*(byte *)(param_1 + 0x11f) & 0x40) != 0) {
        local_res10 = param_1[0x183];
        *(byte *)(param_1 + 0x11f) = *(byte *)(param_1 + 0x11f) & 0xbf;
      }
    }
    *(undefined4 *)(param_1 + 0x113) = 0xb;
    LOCK();
    plVar2 = param_1 + 0x194;
    lVar6 = *plVar2;
    *(int *)plVar2 = (int)*plVar2 + 1;
    UNLOCK();
    uVar7 = (int)lVar6 + 1;
    uVar5 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar5 == 0) {
      iVar4 = (int)((ulonglong)((longlong)(int)uVar7 * -0x2aaaaaab) >> 0x20);
      iVar4 = ((iVar4 >> 2) - (iVar4 >> 0x1f)) * 0x18;
    }
    else {
      iVar4 = (uVar7 / 0x18) * -0x18;
    }
    lVar6 = (longlong)(int)(uVar7 + iVar4);
    *(char *)((longlong)param_1 + lVar6 * 6 + 0xca4) = (char)param_1[0x113];
    *(undefined1 *)((longlong)param_1 + lVar6 * 6 + 0xca5) =
         *(undefined1 *)((longlong)param_1 + 0x89c);
    *(short *)((longlong)param_1 + lVar6 * 6 + 0xca6) = (short)param_1[0x115];
    *(undefined2 *)((longlong)param_1 + lVar6 * 6 + 0xca8) = 0xeab;
    if (4 < DAT_140020050) {
      param_3 = &local_c8;
      local_c8 = param_1[0x152];
      lStack_c0 = param_1[0x153];
      local_b8 = param_1[0x150];
      lStack_b0 = param_1[0x151];
      local_a8 = param_1[0x154];
      lStack_a0 = param_1[0x155];
      VmbusTraceInfoChannelStateChange
                (&local_a8,&local_b8,param_3,(ulonglong)*(ushort *)(param_1 + 0x192),
                 (int)param_1[0x113],*(undefined4 *)((longlong)param_1 + 0x89c),(int)param_1[0x115],
                 0xeab);
    }
    LOCK();
    *(undefined4 *)(param_1 + 0x115) = 1;
    UNLOCK();
    LOCK();
    plVar2 = param_1 + 0x194;
    lVar6 = *plVar2;
    *(int *)plVar2 = (int)*plVar2 + 1;
    UNLOCK();
    uVar7 = (int)lVar6 + 1;
    uVar5 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar5 == 0) {
      iVar4 = (int)((ulonglong)((longlong)(int)uVar7 * -0x2aaaaaab) >> 0x20);
      iVar4 = ((iVar4 >> 2) - (iVar4 >> 0x1f)) * 0x18;
    }
    else {
      iVar4 = (uVar7 / 0x18) * -0x18;
    }
    lVar6 = (longlong)(int)(uVar7 + iVar4);
    *(char *)((longlong)param_1 + lVar6 * 6 + 0xca4) = (char)param_1[0x113];
    *(undefined1 *)((longlong)param_1 + lVar6 * 6 + 0xca5) =
         *(undefined1 *)((longlong)param_1 + 0x89c);
    *(short *)((longlong)param_1 + lVar6 * 6 + 0xca6) = (short)param_1[0x115];
    *(undefined2 *)((longlong)param_1 + lVar6 * 6 + 0xca8) = 0xead;
    if (4 < DAT_140020050) {
      param_3 = &local_98;
      local_98 = param_1[0x152];
      lStack_90 = param_1[0x153];
      local_88 = param_1[0x150];
      lStack_80 = param_1[0x151];
      local_78 = param_1[0x154];
      lStack_70 = param_1[0x155];
      VmbusTraceInfoChannelStateChange
                (&local_78,&local_88,param_3,(ulonglong)*(ushort *)(param_1 + 0x192),
                 (int)param_1[0x113],*(undefined4 *)((longlong)param_1 + 0x89c),(int)param_1[0x115],
                 0xead);
    }
    *(byte *)(param_1 + 0x11f) = *(byte *)(param_1 + 0x11f) & 0xfd;
    KmclUnlockChannel((longlong)param_1);
    KeEnterCriticalRegion();
    ExAcquireFastMutexUnsafe(param_1 + 0x185);
    for (plVar2 = (longlong *)param_1[0x18c]; plVar2 != param_1 + 0x18c;
        plVar2 = (longlong *)*plVar2) {
      LOCK();
      *(int *)(param_1 + 0x115) = (int)param_1[0x115] + 1;
      UNLOCK();
      LOCK();
      plVar1 = param_1 + 0x194;
      lVar6 = *plVar1;
      *(int *)plVar1 = (int)*plVar1 + 1;
      UNLOCK();
      uVar7 = (int)lVar6 + 1;
      uVar5 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar5 == 0) {
        iVar4 = (int)((ulonglong)((longlong)(int)uVar7 * -0x2aaaaaab) >> 0x20);
        iVar4 = ((iVar4 >> 2) - (iVar4 >> 0x1f)) * 0x18;
      }
      else {
        iVar4 = (uVar7 / 0x18) * -0x18;
      }
      lVar6 = (longlong)(int)(uVar7 + iVar4);
      *(char *)((longlong)param_1 + lVar6 * 6 + 0xca4) = (char)param_1[0x113];
      *(undefined1 *)((longlong)param_1 + lVar6 * 6 + 0xca5) =
           *(undefined1 *)((longlong)param_1 + 0x89c);
      *(short *)((longlong)param_1 + lVar6 * 6 + 0xca6) = (short)param_1[0x115];
      *(undefined2 *)((longlong)param_1 + lVar6 * 6 + 0xca8) = 0xec4;
      if (4 < DAT_140020050) {
        param_3 = &local_68;
        local_68 = param_1[0x152];
        lStack_60 = param_1[0x153];
        local_58 = param_1[0x150];
        lStack_50 = param_1[0x151];
        local_48 = param_1[0x154];
        lStack_40 = param_1[0x155];
        VmbusTraceInfoChannelStateChange
                  (&local_48,&local_58,param_3,(ulonglong)*(ushort *)(param_1 + 0x192),
                   (int)param_1[0x113],*(undefined4 *)((longlong)param_1 + 0x89c),
                   (int)param_1[0x115],0xec4);
      }
      uVar10 = SUB81(plVar2 + -0x18e,0);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        param_3 = (longlong *)&WPP_a989f33e64883200e74810d340c3677a_Traceguids;
        WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x69,
                  &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1,uVar10);
      }
      if ((4 < DAT_140020050) && (cVar3 = _tlgKeywordOn(0x140020050,4), cVar3 != '\0')) {
        param_3 = (longlong *)((longlong)param_1 + 0x6ec);
        VmbusTraceInfoRundownEvent
                  ("KmclpContinueChannelRundownAndUnlock",0xecd,param_3,(short)param_1[0x192],
                   *(uint *)(param_1 + 0x113),*(int *)((longlong)param_1 + 0x89c),
                   (int)param_1[0x115],"Disabling subchannel");
      }
      KmclpDisableChannel((longlong)(plVar2 + -0x18e),'\0',param_3);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        param_3 = (longlong *)&WPP_a989f33e64883200e74810d340c3677a_Traceguids;
        WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6a,
                  &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1,uVar10);
      }
    }
    ExReleaseFastMutexUnsafe(param_1 + 0x185);
    KeLeaveCriticalRegion();
    if (*(char *)((longlong)param_1 + 0x6c1) == '\0') {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6b,
                 &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1);
      }
      if ((4 < DAT_140020050) && (cVar3 = _tlgKeywordOn(0x140020050,4), cVar3 != '\0')) {
        VmbusTraceInfoRundownEvent
                  ("KmclpContinueChannelRundownAndUnlock",0xee4,(longlong)param_1 + 0x6ec,
                   (short)param_1[0x192],*(uint *)(param_1 + 0x113),
                   *(int *)((longlong)param_1 + 0x89c),(int)param_1[0x115],"Stopping incoming queue"
                  );
      }
      InStopQueue(param_1);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6c,
                 &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1);
      }
    }
    if ((char)param_1[0xd8] == '\0') {
      KmclpClientCloseChannel((longlong)param_1);
    }
    if (local_res8 != 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6d,
                 &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1);
      }
      if ((4 < DAT_140020050) && (cVar3 = _tlgKeywordOn(0x140020050,4), cVar3 != '\0')) {
        VmbusTraceInfoRundownEvent
                  ("KmclpContinueChannelRundownAndUnlock",0xf01,(longlong)param_1 + 0x6ec,
                   (short)param_1[0x192],*(uint *)(param_1 + 0x113),
                   *(int *)((longlong)param_1 + 0x89c),(int)param_1[0x115],
                   "Setting SuspendDoneEvent");
      }
      KmclpSignalWaiters(local_res8);
    }
    if (local_res10 != 0) {
      if ((4 < DAT_140020050) && (cVar3 = _tlgKeywordOn(0x140020050,4), cVar3 != '\0')) {
        VmbusTraceInfoRundownEvent
                  ("KmclpContinueChannelRundownAndUnlock",0xf08,(longlong)param_1 + 0x6ec,
                   (short)param_1[0x192],*(uint *)(param_1 + 0x113),
                   *(int *)((longlong)param_1 + 0x89c),(int)param_1[0x115],"Subchannel paused");
      }
      KmclDecrementRundownCount(local_res10,'\x01',0xf09);
    }
    uVar8 = 0xf0c;
  }
  else if (iVar4 == 5) {
    *(undefined4 *)(param_1 + 0x113) = 8;
    LOCK();
    plVar2 = param_1 + 0x194;
    lVar6 = *plVar2;
    *(int *)plVar2 = (int)*plVar2 + 1;
    UNLOCK();
    uVar7 = (int)lVar6 + 1;
    uVar5 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar5 == 0) {
      iVar4 = (int)((ulonglong)((longlong)(int)uVar7 * -0x2aaaaaab) >> 0x20);
      iVar4 = ((iVar4 >> 2) - (iVar4 >> 0x1f)) * 0x18;
    }
    else {
      iVar4 = (uVar7 / 0x18) * -0x18;
    }
    lVar6 = (longlong)(int)(uVar7 + iVar4);
    *(char *)((longlong)param_1 + lVar6 * 6 + 0xca4) = (char)param_1[0x113];
    *(undefined1 *)((longlong)param_1 + lVar6 * 6 + 0xca5) =
         *(undefined1 *)((longlong)param_1 + 0x89c);
    *(short *)((longlong)param_1 + lVar6 * 6 + 0xca6) = (short)param_1[0x115];
    *(undefined2 *)((longlong)param_1 + lVar6 * 6 + 0xca8) = 0xf17;
    if (4 < DAT_140020050) {
      local_128 = param_1[0x152];
      lStack_120 = param_1[0x153];
      local_118 = param_1[0x150];
      lStack_110 = param_1[0x151];
      local_108 = param_1[0x154];
      lStack_100 = param_1[0x155];
      VmbusTraceInfoChannelStateChange
                (&local_108,&local_118,&local_128,(ulonglong)*(ushort *)(param_1 + 0x192),
                 (int)param_1[0x113],*(undefined4 *)((longlong)param_1 + 0x89c),(int)param_1[0x115],
                 0xf17);
    }
    LOCK();
    *(undefined4 *)(param_1 + 0x115) = 1;
    UNLOCK();
    LOCK();
    plVar2 = param_1 + 0x194;
    lVar6 = *plVar2;
    *(int *)plVar2 = (int)*plVar2 + 1;
    UNLOCK();
    uVar7 = (int)lVar6 + 1;
    uVar5 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar5 == 0) {
      iVar4 = (int)((ulonglong)((longlong)(int)uVar7 * -0x2aaaaaab) >> 0x20);
      iVar4 = ((iVar4 >> 2) - (iVar4 >> 0x1f)) * 0x18;
    }
    else {
      iVar4 = (uVar7 / 0x18) * -0x18;
    }
    lVar6 = (longlong)(int)(uVar7 + iVar4);
    *(char *)((longlong)param_1 + lVar6 * 6 + 0xca4) = (char)param_1[0x113];
    *(undefined1 *)((longlong)param_1 + lVar6 * 6 + 0xca5) =
         *(undefined1 *)((longlong)param_1 + 0x89c);
    *(short *)((longlong)param_1 + lVar6 * 6 + 0xca6) = (short)param_1[0x115];
    *(undefined2 *)((longlong)param_1 + lVar6 * 6 + 0xca8) = 0xf19;
    if (4 < DAT_140020050) {
      local_f8 = param_1[0x152];
      lStack_f0 = param_1[0x153];
      local_e8 = param_1[0x150];
      lStack_e0 = param_1[0x151];
      local_d8 = param_1[0x154];
      lStack_d0 = param_1[0x155];
      VmbusTraceInfoChannelStateChange
                (&local_d8,&local_e8,&local_f8,(ulonglong)*(ushort *)(param_1 + 0x192),
                 (int)param_1[0x113],*(undefined4 *)((longlong)param_1 + 0x89c),(int)param_1[0x115],
                 0xf19);
    }
    if (*(char *)((longlong)param_1 + 0xac4) != '\0') {
      LOCK();
      *(int *)(param_1 + 0x115) = (int)param_1[0x115] + 1;
      UNLOCK();
      LOCK();
      plVar2 = param_1 + 0x194;
      lVar6 = *plVar2;
      *(int *)plVar2 = (int)*plVar2 + 1;
      UNLOCK();
      uVar7 = (int)lVar6 + 1;
      uVar5 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar5 == 0) {
        iVar4 = (int)((ulonglong)((longlong)(int)uVar7 * -0x2aaaaaab) >> 0x20);
        iVar4 = ((iVar4 >> 2) - (iVar4 >> 0x1f)) * 0x18;
      }
      else {
        iVar4 = (uVar7 / 0x18) * -0x18;
      }
      lVar6 = (longlong)(int)(uVar7 + iVar4);
      *(char *)((longlong)param_1 + lVar6 * 6 + 0xca4) = (char)param_1[0x113];
      *(undefined1 *)((longlong)param_1 + lVar6 * 6 + 0xca5) =
           *(undefined1 *)((longlong)param_1 + 0x89c);
      *(short *)((longlong)param_1 + lVar6 * 6 + 0xca6) = (short)param_1[0x115];
      *(undefined2 *)((longlong)param_1 + lVar6 * 6 + 0xca8) = 0xf29;
      if (4 < DAT_140020050) {
        local_228 = param_1[0x152];
        lStack_220 = param_1[0x153];
        local_248 = param_1[0x150];
        lStack_240 = param_1[0x151];
        local_238 = param_1[0x154];
        lStack_230 = param_1[0x155];
        VmbusTraceInfoChannelStateChange
                  (&local_238,&local_248,&local_228,(ulonglong)*(ushort *)(param_1 + 0x192),
                   (int)param_1[0x113],*(undefined4 *)((longlong)param_1 + 0x89c),
                   (int)param_1[0x115],0xf29);
        if ((4 < DAT_140020050) && (cVar3 = _tlgKeywordOn(0x140020050,4), cVar3 != '\0')) {
          VmbusTraceInfoRundownEvent
                    ("KmclpContinueChannelRundownAndUnlock",0xf2a,(longlong)param_1 + 0x6ec,
                     (short)param_1[0x192],*(uint *)(param_1 + 0x113),
                     *(int *)((longlong)param_1 + 0x89c),(int)param_1[0x115],"Cancelling action IRP"
                    );
        }
      }
      IoCancelIrp(param_1[0x156]);
    }
    KmclUnlockChannel((longlong)param_1);
    uVar8 = 0xf30;
  }
  else {
    if (iVar4 == 6) {
      *(undefined4 *)(param_1 + 0x113) = 9;
      LOCK();
      plVar2 = param_1 + 0x194;
      lVar6 = *plVar2;
      *(int *)plVar2 = (int)*plVar2 + 1;
      UNLOCK();
      uVar7 = (int)lVar6 + 1;
      uVar5 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar5 == 0) {
        iVar4 = (int)((ulonglong)((longlong)(int)uVar7 * -0x2aaaaaab) >> 0x20);
        iVar4 = ((iVar4 >> 2) - (iVar4 >> 0x1f)) * 0x18;
      }
      else {
        iVar4 = (uVar7 / 0x18) * -0x18;
      }
      lVar6 = (longlong)(int)(uVar7 + iVar4);
      *(char *)((longlong)param_1 + lVar6 * 6 + 0xca4) = (char)param_1[0x113];
      *(undefined1 *)((longlong)param_1 + lVar6 * 6 + 0xca5) =
           *(undefined1 *)((longlong)param_1 + 0x89c);
      *(short *)((longlong)param_1 + lVar6 * 6 + 0xca6) = (short)param_1[0x115];
      *(undefined2 *)((longlong)param_1 + lVar6 * 6 + 0xca8) = 0xdea;
      if (4 < DAT_140020050) {
        local_238 = param_1[0x152];
        lStack_230 = param_1[0x153];
        local_248 = param_1[0x150];
        lStack_240 = param_1[0x151];
        local_228 = param_1[0x154];
        lStack_220 = param_1[0x155];
        VmbusTraceInfoChannelStateChange
                  (&local_228,&local_248,&local_238,(ulonglong)*(ushort *)(param_1 + 0x192),
                   (int)param_1[0x113],*(undefined4 *)((longlong)param_1 + 0x89c),
                   (int)param_1[0x115],0xdea);
      }
      KmclUnlockChannel((longlong)param_1);
      goto LAB_14000acd1;
    }
    if (iVar4 != 7) goto LAB_14000acd1;
    LOCK();
    plVar2 = param_1 + 0x194;
    lVar6 = *plVar2;
    *(int *)plVar2 = (int)*plVar2 + 1;
    UNLOCK();
    uVar7 = (int)lVar6 + 1;
    uVar5 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar5 == 0) {
      iVar4 = (int)((ulonglong)((longlong)(int)uVar7 * -0x2aaaaaab) >> 0x20);
      iVar4 = ((iVar4 >> 2) - (iVar4 >> 0x1f)) * 0x18;
    }
    else {
      iVar4 = (uVar7 / 0x18) * -0x18;
    }
    lVar6 = (longlong)(int)(uVar7 + iVar4);
    *(char *)((longlong)param_1 + lVar6 * 6 + 0xca4) = (char)param_1[0x113];
    *(undefined1 *)((longlong)param_1 + lVar6 * 6 + 0xca5) =
         *(undefined1 *)((longlong)param_1 + 0x89c);
    *(short *)((longlong)param_1 + lVar6 * 6 + 0xca6) = (short)param_1[0x115];
    *(undefined2 *)((longlong)param_1 + lVar6 * 6 + 0xca8) = 0xdf8;
    if (4 < DAT_140020050) {
      param_3 = &local_148;
      local_148 = param_1[0x152];
      lStack_140 = param_1[0x153];
      local_138 = param_1[0x150];
      lStack_130 = param_1[0x151];
      local_218 = param_1[0x154];
      lStack_210 = param_1[0x155];
      VmbusTraceInfoChannelStateChange
                (&local_218,&local_138,param_3,(ulonglong)*(ushort *)(param_1 + 0x192),
                 (int)param_1[0x113],*(undefined4 *)((longlong)param_1 + 0x89c),(int)param_1[0x115],
                 0xdf8);
    }
    LOCK();
    *(undefined4 *)(param_1 + 0x115) = 1;
    UNLOCK();
    LOCK();
    plVar2 = param_1 + 0x194;
    lVar6 = *plVar2;
    *(int *)plVar2 = (int)*plVar2 + 1;
    UNLOCK();
    uVar7 = (int)lVar6 + 1;
    uVar5 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar5 == 0) {
      iVar4 = (int)((ulonglong)((longlong)(int)uVar7 * -0x2aaaaaab) >> 0x20);
      iVar4 = ((iVar4 >> 2) - (iVar4 >> 0x1f)) * 0x18;
    }
    else {
      iVar4 = (uVar7 / 0x18) * -0x18;
    }
    lVar6 = (longlong)(int)(uVar7 + iVar4);
    *(char *)((longlong)param_1 + lVar6 * 6 + 0xca4) = (char)param_1[0x113];
    *(undefined1 *)((longlong)param_1 + lVar6 * 6 + 0xca5) =
         *(undefined1 *)((longlong)param_1 + 0x89c);
    *(short *)((longlong)param_1 + lVar6 * 6 + 0xca6) = (short)param_1[0x115];
    *(undefined2 *)((longlong)param_1 + lVar6 * 6 + 0xca8) = 0xdfa;
    if (4 < DAT_140020050) {
      param_3 = &local_208;
      local_208 = param_1[0x152];
      lStack_200 = param_1[0x153];
      local_1f8 = param_1[0x150];
      lStack_1f0 = param_1[0x151];
      local_1e8 = param_1[0x154];
      lStack_1e0 = param_1[0x155];
      VmbusTraceInfoChannelStateChange
                (&local_1e8,&local_1f8,param_3,(ulonglong)*(ushort *)(param_1 + 0x192),
                 (int)param_1[0x113],*(undefined4 *)((longlong)param_1 + 0x89c),(int)param_1[0x115],
                 0xdfa);
    }
    *(undefined4 *)(param_1 + 0x113) = 10;
    LOCK();
    plVar2 = param_1 + 0x194;
    lVar6 = *plVar2;
    *(int *)plVar2 = (int)*plVar2 + 1;
    UNLOCK();
    uVar7 = (int)lVar6 + 1;
    uVar5 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar5 == 0) {
      iVar4 = (int)((ulonglong)((longlong)(int)uVar7 * -0x2aaaaaab) >> 0x20);
      iVar4 = ((iVar4 >> 2) - (iVar4 >> 0x1f)) * 0x18;
    }
    else {
      iVar4 = (uVar7 / 0x18) * -0x18;
    }
    lVar6 = (longlong)(int)(uVar7 + iVar4);
    *(char *)((longlong)param_1 + lVar6 * 6 + 0xca4) = (char)param_1[0x113];
    *(undefined1 *)((longlong)param_1 + lVar6 * 6 + 0xca5) =
         *(undefined1 *)((longlong)param_1 + 0x89c);
    *(short *)((longlong)param_1 + lVar6 * 6 + 0xca6) = (short)param_1[0x115];
    *(undefined2 *)((longlong)param_1 + lVar6 * 6 + 0xca8) = 0xe02;
    if (4 < DAT_140020050) {
      param_3 = &local_1d8;
      local_1d8 = param_1[0x152];
      lStack_1d0 = param_1[0x153];
      local_1c8 = param_1[0x150];
      lStack_1c0 = param_1[0x151];
      local_1b8 = param_1[0x154];
      lStack_1b0 = param_1[0x155];
      VmbusTraceInfoChannelStateChange
                (&local_1b8,&local_1c8,param_3,(ulonglong)*(ushort *)(param_1 + 0x192),
                 (int)param_1[0x113],*(undefined4 *)((longlong)param_1 + 0x89c),(int)param_1[0x115],
                 0xe02);
    }
    if (*(char *)((longlong)param_1 + 0xac4) != '\0') {
      LOCK();
      *(int *)(param_1 + 0x115) = (int)param_1[0x115] + 1;
      UNLOCK();
      LOCK();
      plVar2 = param_1 + 0x194;
      lVar6 = *plVar2;
      *(int *)plVar2 = (int)*plVar2 + 1;
      UNLOCK();
      uVar7 = (int)lVar6 + 1;
      uVar5 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar5 == 0) {
        iVar4 = (int)((ulonglong)((longlong)(int)uVar7 * -0x2aaaaaab) >> 0x20);
        iVar4 = ((iVar4 >> 2) - (iVar4 >> 0x1f)) * 0x18;
      }
      else {
        iVar4 = (uVar7 / 0x18) * -0x18;
      }
      lVar6 = (longlong)(int)(uVar7 + iVar4);
      *(char *)((longlong)param_1 + lVar6 * 6 + 0xca4) = (char)param_1[0x113];
      *(undefined1 *)((longlong)param_1 + lVar6 * 6 + 0xca5) =
           *(undefined1 *)((longlong)param_1 + 0x89c);
      *(short *)((longlong)param_1 + lVar6 * 6 + 0xca6) = (short)param_1[0x115];
      *(undefined2 *)((longlong)param_1 + lVar6 * 6 + 0xca8) = 0xe16;
      if (4 < DAT_140020050) {
        param_3 = &local_1a8;
        local_1a8 = param_1[0x152];
        lStack_1a0 = param_1[0x153];
        local_198 = param_1[0x150];
        lStack_190 = param_1[0x151];
        local_188 = param_1[0x154];
        lStack_180 = param_1[0x155];
        VmbusTraceInfoChannelStateChange
                  (&local_188,&local_198,param_3,(ulonglong)*(ushort *)(param_1 + 0x192),
                   (int)param_1[0x113],*(undefined4 *)((longlong)param_1 + 0x89c),
                   (int)param_1[0x115],0xe16);
        if ((4 < DAT_140020050) && (cVar3 = _tlgKeywordOn(0x140020050,4), cVar3 != '\0')) {
          param_3 = (longlong *)((longlong)param_1 + 0x6ec);
          VmbusTraceInfoRundownEvent
                    ("KmclpContinueChannelRundownAndUnlock",0xe17,param_3,(short)param_1[0x192],
                     *(uint *)(param_1 + 0x113),*(int *)((longlong)param_1 + 0x89c),
                     (int)param_1[0x115],"Cancelling action IRP");
        }
      }
      IoCancelIrp(param_1[0x156]);
    }
    KmclUnlockChannel((longlong)param_1);
    KeEnterCriticalRegion();
    ExAcquireFastMutexUnsafe(param_1 + 0x185);
    for (plVar2 = (longlong *)param_1[0x18c]; plVar2 != param_1 + 0x18c;
        plVar2 = (longlong *)*plVar2) {
      LOCK();
      *(int *)(param_1 + 0x115) = (int)param_1[0x115] + 1;
      UNLOCK();
      LOCK();
      plVar1 = param_1 + 0x194;
      lVar6 = *plVar1;
      *(int *)plVar1 = (int)*plVar1 + 1;
      UNLOCK();
      uVar7 = (int)lVar6 + 1;
      uVar5 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar5 == 0) {
        iVar4 = (int)((ulonglong)((longlong)(int)uVar7 * -0x2aaaaaab) >> 0x20);
        iVar4 = ((iVar4 >> 2) - (iVar4 >> 0x1f)) * 0x18;
      }
      else {
        iVar4 = (uVar7 / 0x18) * -0x18;
      }
      lVar6 = (longlong)(int)(uVar7 + iVar4);
      *(char *)((longlong)param_1 + lVar6 * 6 + 0xca4) = (char)param_1[0x113];
      *(undefined1 *)((longlong)param_1 + lVar6 * 6 + 0xca5) =
           *(undefined1 *)((longlong)param_1 + 0x89c);
      *(short *)((longlong)param_1 + lVar6 * 6 + 0xca6) = (short)param_1[0x115];
      *(undefined2 *)((longlong)param_1 + lVar6 * 6 + 0xca8) = 0xe2c;
      if (4 < DAT_140020050) {
        param_3 = &local_178;
        local_178 = param_1[0x152];
        lStack_170 = param_1[0x153];
        local_168 = param_1[0x150];
        lStack_160 = param_1[0x151];
        local_158 = param_1[0x154];
        lStack_150 = param_1[0x155];
        VmbusTraceInfoChannelStateChange
                  (&local_158,&local_168,param_3,(ulonglong)*(ushort *)(param_1 + 0x192),
                   (int)param_1[0x113],*(undefined4 *)((longlong)param_1 + 0x89c),
                   (int)param_1[0x115],0xe2c);
      }
      uVar10 = SUB81(plVar2 + -0x18e,0);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        param_3 = (longlong *)&WPP_a989f33e64883200e74810d340c3677a_Traceguids;
        WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),99,
                  &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1,uVar10);
      }
      if ((4 < DAT_140020050) && (cVar3 = _tlgKeywordOn(0x140020050,4), cVar3 != '\0')) {
        param_3 = (longlong *)((longlong)param_1 + 0x6ec);
        VmbusTraceInfoRundownEvent
                  ("KmclpContinueChannelRundownAndUnlock",0xe35,param_3,(short)param_1[0x192],
                   *(uint *)(param_1 + 0x113),*(int *)((longlong)param_1 + 0x89c),
                   (int)param_1[0x115],"Pausing subchannel");
      }
      KmclpPauseChannel((longlong)(plVar2 + -0x18e),'\0',param_3);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        param_3 = (longlong *)&WPP_a989f33e64883200e74810d340c3677a_Traceguids;
        WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),100,
                  &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1,uVar10);
      }
    }
    ExReleaseFastMutexUnsafe(param_1 + 0x185);
    KeLeaveCriticalRegion();
    if ((*(char *)((longlong)param_1 + 0x6c1) == '\0') || (param_1[0x10a] != 0)) {
      (*(code *)param_1[0x133])(param_1[0x122]);
    }
    if (*(char *)((longlong)param_1 + 0x6c1) == '\0') {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x65,
                 &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1);
      }
      if ((4 < DAT_140020050) && (cVar3 = _tlgKeywordOn(0x140020050,4), cVar3 != '\0')) {
        VmbusTraceInfoRundownEvent
                  ("KmclpContinueChannelRundownAndUnlock",0xe5b,(longlong)param_1 + 0x6ec,
                   (short)param_1[0x192],*(uint *)(param_1 + 0x113),
                   *(int *)((longlong)param_1 + 0x89c),(int)param_1[0x115],"Pausing incoming queue")
        ;
      }
      InPauseQueue(param_1);
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x66,
                   &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1);
        }
        goto LAB_140009ee8;
      }
    }
    else {
LAB_140009ee8:
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x67,
                 &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1);
      }
    }
    if ((4 < DAT_140020050) && (cVar3 = _tlgKeywordOn(0x140020050,4), cVar3 != '\0')) {
      VmbusTraceInfoRundownEvent
                ("KmclpContinueChannelRundownAndUnlock",0xe70,(longlong)param_1 + 0x6ec,
                 (short)param_1[0x192],*(uint *)(param_1 + 0x113),
                 *(int *)((longlong)param_1 + 0x89c),(int)param_1[0x115],
                 "Notifying client that channel is pausing");
    }
    if ((char)param_1[0xfd] == '\0') {
      (*(code *)param_1[0x101])(param_1);
    }
    else {
      (*(code *)param_1[0x102])(param_1,param_1[0xff]);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x68,
               &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1);
    }
    uVar8 = 0xe89;
  }
  KmclDecrementRundownCount((longlong)param_1,'\x01',uVar8);
LAB_14000acd1:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6e,
             &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1);
  }
  if ((5 < DAT_140020050) && (cVar3 = _tlgKeywordOn(0x140020050,4), cVar3 != '\0')) {
    VmbusTraceVerbRundownFnStop
              ("KmclpContinueChannelRundownAndUnlock",0xf66,(longlong)param_1 + 0x6ec,
               (short)param_1[0x192],*(uint *)(param_1 + 0x113),*(int *)((longlong)param_1 + 0x89c),
               (int)param_1[0x115],"");
  }
  return;
}



===== VmbChannelEnable @ 14000ada0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong VmbChannelEnable(longlong *param_1,undefined8 param_2,ulonglong param_3)

{
  uint uVar1;
  ulonglong uVar2;
  longlong *plVar3;
  undefined2 uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  longlong *plVar7;
  
                    /* 0xada0  13  VmbChannelEnable */
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = (ulonglong)(*(byte *)(param_1 + 0x11f) >> 2 & 1);
    WPP_SF_qLd_guid__guid_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(longlong)param_1 + 0x6dc,param_3,param_1,
               (char)param_1[0x113],*(byte *)(param_1 + 0x11f) >> 2 & 1,(longlong)param_1 + 0x6dc,
               (longlong)param_1 + 0x6ec);
  }
  if ((int)param_1[0x113] == 0xc) {
    if ((char)param_1[0xfd] == '\0') {
      (*(code *)param_1[0xff])(param_1);
    }
    else {
      (*(code *)param_1[0x100])(param_1,param_1[0xff]);
    }
    return 0;
  }
  if (*(char *)((longlong)param_1 + 0x6c1) == '\0') {
    param_3 = (ulonglong)*(uint *)(param_1 + 0xd9);
    if (*(uint *)(param_1 + 0xd9) == 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc000000d;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return 0xc000000d;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return 0xc000000d;
      }
      WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1,0);
      return 0xc000000d;
    }
  }
  else if (*(char *)((longlong)param_1 + 0x706) != '\0') {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc000000d;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return 0xc000000d;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return 0xc000000d;
    }
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
             &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1);
    return 0xc000000d;
  }
  if ((int)param_1[0xda] == 0) {
    *(undefined4 *)(param_1 + 0xda) = 1;
  }
  if (*(int *)((longlong)param_1 + 0x6fc) == 0) {
    *(undefined4 *)((longlong)param_1 + 0x6fc) = 1;
  }
  uVar5 = 0;
  if ((((int)param_1[0xe2] != 0) || (*(int *)((longlong)param_1 + 0x714) != 0)) ||
     (((int)param_1[0xe3] != 0 || (*(int *)((longlong)param_1 + 0x71c) != 0)))) {
    plVar3 = (longlong *)param_1[0xf4];
    param_3 = 0;
    if (plVar3 != (longlong *)0x0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc000000d;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return 0xc000000d;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return 0xc000000d;
      }
      uVar4 = 0xd;
      plVar7 = plVar3;
      goto LAB_14000b1c1;
    }
  }
  if ((*(char *)((longlong)param_1 + 0x701) != '\0') &&
     ((((int)param_1[0xe2] != 0 || (*(int *)((longlong)param_1 + 0x714) != 0)) ||
      (((int)param_1[0xe3] != 0 ||
       ((*(int *)((longlong)param_1 + 0x71c) != 0 || (param_1[0xf4] != 0)))))))) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc000000d;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return 0xc000000d;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return 0xc000000d;
    }
    plVar3 = param_1 + 0xe2;
    uVar4 = 0xe;
    plVar7 = (longlong *)param_1[0xf4];
LAB_14000b1c1:
    WPP_SF_q_guid_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,plVar3,param_1,param_1 + 0xe2,
                    (char)plVar7);
    return 0xc000000d;
  }
  if ((*(char *)((longlong)param_1 + 0x6c1) == '\0') && ((*(byte *)(param_1 + 0x11f) & 0x20) == 0))
  {
    uVar2 = InInitializeQueue(param_1);
    uVar6 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return uVar6;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return uVar6;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return uVar6;
      }
      uVar4 = 0xf;
LAB_14000b213:
      WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
                &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1,(char)uVar6);
      return uVar6;
    }
    uVar2 = OutInitializeQueue(param_1);
    uVar6 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return uVar6;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return uVar6;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return uVar6;
      }
      uVar4 = 0x10;
      goto LAB_14000b213;
    }
    *(byte *)(param_1 + 0x11f) = *(byte *)(param_1 + 0x11f) | 0x20;
  }
  plVar3 = (longlong *)param_1[0x183];
  if (plVar3 == (longlong *)0x0) {
    if ((char)param_1[0x184] != '\0') {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc0000184;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return 0xc0000184;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return 0xc0000184;
      }
      WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,param_3,param_1,(char)param_1[0x113]
               );
      return 0xc0000184;
    }
    KmclLockChannel((longlong)param_1);
  }
  else {
    KmclLockChannel((longlong)plVar3);
    KmclLockChannel((longlong)param_1);
    uVar1 = *(uint *)(plVar3 + 0x113);
    uVar5 = (ulonglong)uVar1;
    if ((10 < uVar1) || ((0x6d0U >> (uVar1 & 0x1f) & 1) == 0)) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_qLqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,param_3,param_1,
                    (char)param_1[0x113],(char)plVar3,(char)uVar1);
      }
      KmclUnlockChannel((longlong)param_1);
      goto LAB_14000b045;
    }
    KmclUnlockChannel((longlong)plVar3);
  }
  uVar1 = *(uint *)(param_1 + 0x113);
  plVar7 = (longlong *)(ulonglong)uVar1;
  if ((uVar1 != 0) || ((*(byte *)(param_1 + 0x11f) & 4) != 0)) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_qLd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,plVar7,param_1,(char)uVar1,
                 *(byte *)(param_1 + 0x11f) >> 2 & 1);
    }
    plVar3 = param_1;
LAB_14000b045:
    KmclUnlockChannel((longlong)plVar3);
    return 0xc0000184;
  }
  if ((char)param_1[0xd8] == '\0') {
    uVar1 = KmclpClientFindVmbusAndUnlock(param_1,uVar5,(longlong *)0x0);
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_14000aee3;
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1,(char)uVar1);
    }
  }
  else {
    uVar2 = KmclpServerOfferChannel(param_1);
    uVar1 = (uint)uVar2;
    KmclUnlockChannel((longlong)param_1);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (uVar5 = (ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
        (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      plVar7 = (longlong *)&WPP_a989f33e64883200e74810d340c3677a_Traceguids;
      uVar5 = 0x14;
      WPP_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                 &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1,(char)plVar3,(char)uVar2);
    }
    if (plVar3 != (longlong *)0x0) {
      KmclLockChannel((longlong)plVar3);
      if ((int)plVar3[0x113] - 6U < 2) {
        KmclLockChannel((longlong)param_1);
        KmclUnlockChannel((longlong)plVar3);
        KmclpStartChannelAndUnlock(param_1,uVar5,plVar7);
      }
      else {
        KmclUnlockChannel((longlong)plVar3);
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
              &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1,(char)uVar1);
  }
LAB_14000aee3:
  return (ulonglong)uVar1;
}



===== KmclLockChannel @ 14000b3f4 =====

void KmclLockChannel(longlong param_1)

{
  KeEnterCriticalRegion();
  ExAcquireFastMutexUnsafe(param_1 + 0x8c0);
  return;
}



===== KmclpClientFindVmbusAndUnlock @ 14000b42c =====

int KmclpClientFindVmbusAndUnlock(longlong *param_1,undefined8 param_2,longlong *param_3)

{
  longlong *plVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined2 uVar5;
  longlong *plVar6;
  longlong lVar7;
  uint uVar8;
  longlong local_48;
  longlong lStack_40;
  longlong local_38;
  longlong lStack_30;
  longlong local_28;
  longlong lStack_20;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,param_3,param_1,(char)param_1[0x113]);
  }
  lVar7 = 0;
  *(undefined4 *)(param_1 + 0x113) = 1;
  LOCK();
  plVar6 = param_1 + 0x194;
  lVar4 = *plVar6;
  *(int *)plVar6 = (int)*plVar6 + 1;
  UNLOCK();
  uVar8 = (int)lVar4 + 1;
  uVar3 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 == 0) {
    iVar2 = (int)((ulonglong)((longlong)(int)uVar8 * -0x2aaaaaab) >> 0x20);
    iVar2 = ((iVar2 >> 2) - (iVar2 >> 0x1f)) * 0x18;
  }
  else {
    iVar2 = (uVar8 / 0x18) * -0x18;
  }
  plVar6 = (longlong *)(longlong)(int)(uVar8 + iVar2);
  *(char *)((longlong)param_1 + (longlong)plVar6 * 6 + 0xca4) = (char)param_1[0x113];
  *(undefined1 *)((longlong)param_1 + (longlong)plVar6 * 6 + 0xca5) =
       *(undefined1 *)((longlong)param_1 + 0x89c);
  *(short *)((longlong)param_1 + (longlong)plVar6 * 6 + 0xca6) = (short)param_1[0x115];
  *(undefined2 *)((longlong)param_1 + (longlong)plVar6 * 6 + 0xca8) = 0x50f;
  if (4 < DAT_140020050) {
    param_3 = &local_48;
    local_48 = param_1[0x152];
    lStack_40 = param_1[0x153];
    plVar6 = &local_38;
    local_38 = param_1[0x150];
    lStack_30 = param_1[0x151];
    local_28 = param_1[0x154];
    lStack_20 = param_1[0x155];
    VmbusTraceInfoChannelStateChange
              (&local_28,plVar6,param_3,(ulonglong)*(ushort *)(param_1 + 0x192),(int)param_1[0x113],
               *(undefined4 *)((longlong)param_1 + 0x89c),(int)param_1[0x115],0x50f);
  }
  if (*(char *)((longlong)param_1 + 0x7c1) == '\0') {
    if ((char)param_1[0xf8] == '\0') {
      lVar4 = IoGetLowerDeviceObject(param_1[400]);
      param_1[0x14e] = lVar4;
      if (lVar4 == 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
                    &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1,(char)param_1[400]);
        }
        iVar2 = -0x3ffffff3;
      }
      else {
        iVar2 = VmbusSendInterfaceQuery((longlong)param_1);
        if (-1 < iVar2) goto LAB_14000b816;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
                    &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1,(char)iVar2);
        }
        ObfDereferenceObject(param_1[0x14e]);
        param_1[0x14e] = 0;
      }
      goto LAB_14000b5db;
    }
    plVar1 = param_1 + 0x149;
    param_3 = (longlong *)((longlong)param_1 + 0x6dc);
    param_1[0x14a] = (longlong)SystemReserved1[0xf];
    plVar6 = (longlong *)0x1;
    *(undefined4 *)(param_1 + 0x14b) = 0x103;
    iVar2 = IoRegisterPlugPlayNotification
                      (2,1,param_3,*(undefined8 *)(param_1[400] + 8),KmclpVmbusArrivalNotification,
                       param_1,plVar1);
    param_1[0x14a] = 0;
    if (iVar2 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar5 = 0x28;
        goto LAB_14000b5cc;
      }
      goto LAB_14000b5db;
    }
    iVar2 = (int)param_1[0x14b];
    if (iVar2 != 0x103) {
      lVar7 = *plVar1;
      *plVar1 = 0;
      if (-1 < iVar2) goto LAB_14000b816;
      goto LAB_14000b5db;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
               &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1);
    }
    iVar2 = 0;
  }
  else {
    iVar2 = VmbusSendInterfaceQuery((longlong)param_1);
    if (iVar2 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar5 = 0x25;
LAB_14000b5cc:
        WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
                  &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1,(char)iVar2);
      }
    }
    else {
LAB_14000b816:
      uVar3 = KmclpClientOpenChannel(param_1);
      iVar2 = (int)uVar3;
      if (-1 < iVar2) {
        KmclpResumePausedChannelAndUnlock(param_1,plVar6,param_3);
        iVar2 = 0;
        goto LAB_14000b5eb;
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar5 = 0x2a;
        goto LAB_14000b5cc;
      }
    }
LAB_14000b5db:
    KmclpDisableClosedChannel((longlong)param_1);
  }
  KmclUnlockChannel((longlong)param_1);
LAB_14000b5eb:
  if (lVar7 != 0) {
    IoUnregisterPlugPlayNotificationEx(lVar7);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
              &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1,(char)iVar2);
  }
  return iVar2;
}



===== KmclUnlockChannel @ 14000b86c =====

void KmclUnlockChannel(longlong param_1)

{
  ExReleaseFastMutexUnsafe(param_1 + 0x8c0);
  KeLeaveCriticalRegion();
  return;
}



===== KmclpResumePausedChannelAndUnlock @ 14000b89c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void KmclpResumePausedChannelAndUnlock(longlong *param_1,undefined8 param_2,longlong *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  ulonglong uVar5;
  code *pcVar6;
  longlong *plVar7;
  uint uVar8;
  longlong local_88;
  longlong lStack_80;
  longlong local_78;
  longlong lStack_70;
  longlong local_68;
  longlong lStack_60;
  longlong local_58;
  longlong lStack_50;
  longlong local_48;
  longlong lStack_40;
  longlong local_38;
  longlong lStack_30;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x46,param_3,param_1,(char)param_1[0x113]);
  }
  *(undefined4 *)(param_1 + 0x113) = 6;
  LOCK();
  plVar7 = param_1 + 0x194;
  lVar2 = *plVar7;
  *(int *)plVar7 = (int)*plVar7 + 1;
  UNLOCK();
  uVar8 = (int)lVar2 + 1;
  uVar5 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar5 == 0) {
    iVar4 = (int)((ulonglong)((longlong)(int)uVar8 * -0x2aaaaaab) >> 0x20);
    iVar4 = ((iVar4 >> 2) - (iVar4 >> 0x1f)) * 0x18;
  }
  else {
    iVar4 = (uVar8 / 0x18) * -0x18;
  }
  pcVar6 = (code *)(longlong)(int)(uVar8 + iVar4);
  *(char *)((longlong)param_1 + (longlong)pcVar6 * 6 + 0xca4) = (char)param_1[0x113];
  *(undefined1 *)((longlong)param_1 + (longlong)pcVar6 * 6 + 0xca5) =
       *(undefined1 *)((longlong)param_1 + 0x89c);
  *(short *)((longlong)param_1 + (longlong)pcVar6 * 6 + 0xca6) = (short)param_1[0x115];
  *(undefined2 *)((longlong)param_1 + (longlong)pcVar6 * 6 + 0xca8) = 0xa81;
  if (4 < DAT_140020050) {
    param_3 = &local_88;
    local_88 = param_1[0x152];
    lStack_80 = param_1[0x153];
    pcVar6 = (code *)&local_78;
    local_78 = param_1[0x150];
    lStack_70 = param_1[0x151];
    local_68 = param_1[0x154];
    lStack_60 = param_1[0x155];
    VmbusTraceInfoChannelStateChange
              (&local_68,pcVar6,param_3,(ulonglong)*(ushort *)(param_1 + 0x192),(int)param_1[0x113],
               *(undefined4 *)((longlong)param_1 + 0x89c),(int)param_1[0x115],0xa81);
  }
  if (*(char *)((longlong)param_1 + 0x6c1) == '\0') {
    OutStartQueue((longlong)param_1);
  }
  KmclUnlockChannel((longlong)param_1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    pcVar6 = (code *)0x47;
    param_3 = (longlong *)&WPP_a989f33e64883200e74810d340c3677a_Traceguids;
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x47,
             &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1);
  }
  if ((char)param_1[0xfd] == '\0') {
    (*(code *)param_1[0x102])(param_1);
  }
  else {
    pcVar6 = (code *)param_1[0xff];
    (*(code *)param_1[0x103])();
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    pcVar6 = (code *)0x48;
    param_3 = (longlong *)&WPP_a989f33e64883200e74810d340c3677a_Traceguids;
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x48,
             &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1);
  }
  if ((*(char *)((longlong)param_1 + 0x6c1) == '\0') || (param_1[0x10a] != 0)) {
    pcVar6 = KmclpVmbusManualIsr;
    if (*(char *)((longlong)param_1 + 0x6c1) == '\0') {
      pcVar6 = KmclpVmbusIsr;
    }
    param_3 = param_1;
    (*(code *)param_1[0x132])(param_1[0x122]);
  }
  if (*(char *)((longlong)param_1 + 0x6c1) == '\0') {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      pcVar6 = (code *)0x0;
      param_3 = (longlong *)&WPP_a989f33e64883200e74810d340c3677a_Traceguids;
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x49,
               &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1);
    }
    pcVar6 = (code *)CONCAT71((int7)((ulonglong)pcVar6 >> 8),1);
    OutPollQueue((longlong)param_1,'\x01');
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      pcVar6 = (code *)0x4a;
      param_3 = (longlong *)&WPP_a989f33e64883200e74810d340c3677a_Traceguids;
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4a,
               &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1);
    }
    InStartQueue(param_1);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      pcVar6 = (code *)0x4b;
      param_3 = (longlong *)&WPP_a989f33e64883200e74810d340c3677a_Traceguids;
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4b,
               &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1);
    }
  }
  KeEnterCriticalRegion();
  ExAcquireFastMutexUnsafe(param_1 + 0x185);
  for (plVar7 = (longlong *)param_1[0x18c]; plVar7 != param_1 + 0x18c; plVar7 = (longlong *)*plVar7)
  {
    plVar1 = plVar7 + -0x18e;
    KmclLockChannel((longlong)plVar1);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      param_3 = (longlong *)&WPP_a989f33e64883200e74810d340c3677a_Traceguids;
      pcVar6 = (code *)0x4c;
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4c,
                &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1,(char)plVar1);
    }
    KmclpStartChannelAndUnlock(plVar1,pcVar6,param_3);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      param_3 = (longlong *)&WPP_a989f33e64883200e74810d340c3677a_Traceguids;
      pcVar6 = (code *)&DAT_0000004d;
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4d,
                &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1,(char)plVar1);
    }
  }
  ExReleaseFastMutexUnsafe(param_1 + 0x185);
  KeLeaveCriticalRegion();
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = (longlong *)&WPP_a989f33e64883200e74810d340c3677a_Traceguids;
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4e,
             &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1);
  }
  if ((char)param_1[0xfd] == '\0') {
    (*(code *)param_1[0x103])(param_1);
  }
  else {
    (*(code *)param_1[0x104])(param_1,param_1[0xff]);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = (longlong *)&WPP_a989f33e64883200e74810d340c3677a_Traceguids;
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4f,
             &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1);
  }
  KmclLockChannel((longlong)param_1);
  lVar2 = param_1[0x113];
  *(undefined4 *)(param_1 + 0x113) = 7;
  LOCK();
  plVar7 = param_1 + 0x194;
  lVar3 = *plVar7;
  *(int *)plVar7 = (int)*plVar7 + 1;
  UNLOCK();
  uVar8 = (int)lVar3 + 1;
  uVar5 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar5 == 0) {
    iVar4 = (int)((ulonglong)((longlong)(int)uVar8 * -0x2aaaaaab) >> 0x20);
    iVar4 = ((iVar4 >> 2) - (iVar4 >> 0x1f)) * 0x18;
  }
  else {
    iVar4 = (uVar8 / 0x18) * -0x18;
  }
  plVar7 = (longlong *)(longlong)(int)(uVar8 + iVar4);
  *(char *)((longlong)param_1 + (longlong)plVar7 * 6 + 0xca4) = (char)param_1[0x113];
  *(undefined1 *)((longlong)param_1 + (longlong)plVar7 * 6 + 0xca5) =
       *(undefined1 *)((longlong)param_1 + 0x89c);
  *(short *)((longlong)param_1 + (longlong)plVar7 * 6 + 0xca6) = (short)param_1[0x115];
  *(undefined2 *)((longlong)param_1 + (longlong)plVar7 * 6 + 0xca8) = 0xb23;
  if (4 < DAT_140020050) {
    param_3 = &local_58;
    local_58 = param_1[0x152];
    lStack_50 = param_1[0x153];
    plVar7 = &local_48;
    local_48 = param_1[0x150];
    lStack_40 = param_1[0x151];
    local_38 = param_1[0x154];
    lStack_30 = param_1[0x155];
    VmbusTraceInfoChannelStateChange
              (&local_38,plVar7,param_3,(ulonglong)*(ushort *)(param_1 + 0x192),(int)param_1[0x113],
               *(undefined4 *)((longlong)param_1 + 0x89c),(int)param_1[0x115],0xb23);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    plVar7 = (longlong *)0x50;
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x50,param_3,param_1,(char)lVar2);
  }
  if ((int)lVar2 == 6) {
    KmclpStartWaitForAction((longlong)param_1,plVar7,param_3);
    KmclUnlockChannel((longlong)param_1);
  }
  else {
    KmclpContinueChannelRundownAndUnlock(param_1,plVar7,param_3);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x51,
             &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1);
  }
  return;
}



===== InLookasideAllocate @ 14000bec0 =====

void InLookasideAllocate(undefined8 param_1,undefined4 param_2)

{
  longlong lVar1;
  
  lVar1 = ExAllocatePoolWithTag();
  if (lVar1 != 0) {
    *(undefined4 *)(lVar1 + 8) = param_2;
  }
  return;
}



===== InReferenceProfilerForQueue @ 14000beec =====

ulonglong InReferenceProfilerForQueue(longlong *param_1,uint param_2,undefined8 *param_3)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong *plVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  longlong *local_res8;
  
  local_res8 = (longlong *)0x0;
  ExAcquireFastMutex();
  if ((*(char *)(*param_1 + 0x6c0) == '\0') ||
     (puVar5 = KmclProfilerList, (undefined8 **)KmclProfilerList == &KmclProfilerList)) {
LAB_14000bf76:
    uVar1 = InpAllocatePacketProfilerLocked(param_1,param_2,&local_res8);
    uVar4 = uVar1 & 0xffffffff;
    if ((int)uVar1 < 0) goto LAB_14000bf8f;
    plVar3 = local_res8;
  }
  else {
    do {
      plVar3 = puVar5 + -1;
      if (((puVar5[5] == *(longlong *)(*param_1 + 0xc80)) &&
          (((local_res8 = plVar3, lVar2 = RtlCompareMemory(puVar5 + 2,*param_1 + 0xa80,0x10),
            lVar2 == 0x10 && (*(short *)(*param_1 + 0xc88) == *(short *)(puVar5 + 4))) &&
           (*(uint *)((longlong)puVar5 + -4) < 4)))) && (param_2 <= (uint)((int)*plVar3 * 0x400)))
      break;
      puVar5 = (undefined8 *)*puVar5;
      plVar3 = (longlong *)0x0;
      local_res8 = (longlong *)0x0;
    } while ((undefined8 **)puVar5 != &KmclProfilerList);
    if (plVar3 == (longlong *)0x0) goto LAB_14000bf76;
  }
  *(int *)((longlong)plVar3 + 4) = *(int *)((longlong)plVar3 + 4) + 1;
  *param_3 = plVar3;
  uVar4 = 0;
LAB_14000bf8f:
  ExReleaseFastMutex(&KmclProfilerListLock);
  return uVar4;
}



===== InpAllocatePacketProfilerLocked @ 14000c030 =====

undefined8 InpAllocatePacketProfilerLocked(longlong *param_1,uint param_2,undefined8 *param_3)

{
  uint *puVar1;
  longlong lVar2;
  code *pcVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  uint *puVar9;
  uint uVar10;
  undefined2 *puVar11;
  
  uVar5 = (param_2 >> 10) + 1;
  if ((param_2 & 0x3ff) == 0) {
    uVar5 = param_2 >> 10;
  }
  puVar6 = (uint *)ExAllocatePool2(0x40,uVar5 * 0x80 + 0x40,0x6e696b56);
  uVar8 = 0;
  if (puVar6 == (uint *)0x0) {
    uVar8 = 0xc000009a;
  }
  else {
    puVar1 = puVar6 + 2;
    uVar10 = 0;
    *(uint **)(puVar6 + 4) = puVar1;
    *(uint **)puVar1 = puVar1;
    if (uVar5 != 0) {
      puVar11 = (undefined2 *)((longlong)puVar6 + 0x52);
      puVar9 = puVar6 + 0x10;
      do {
        ExInitializeNPagedLookasideList
                  (puVar9,InLookasideAllocate,0,ExDefaultNonPagedPoolType | 0x200,
                   (uVar10 + 1) * 0x400,0x6e696b56,0);
        *puVar11 = 0x400;
        puVar9 = puVar9 + 0x20;
        puVar11 = puVar11 + 0x40;
        uVar10 = uVar10 + 1;
      } while (uVar10 < uVar5);
    }
    *puVar6 = uVar5;
    *(undefined2 *)(puVar6 + 10) = *(undefined2 *)(*param_1 + 0xc88);
    *(undefined8 *)(puVar6 + 0xc) = *(undefined8 *)(*param_1 + 0xc80);
    puVar7 = &KmclProfilerList;
    lVar2 = *param_1;
    uVar5 = *(uint *)(lVar2 + 0xa84);
    uVar10 = *(uint *)(lVar2 + 0xa88);
    uVar4 = *(uint *)(lVar2 + 0xa8c);
    puVar6[6] = *(uint *)(lVar2 + 0xa80);
    puVar6[7] = uVar5;
    puVar6[8] = uVar10;
    puVar6[9] = uVar4;
    if (*(undefined8 **)DAT_140020318 != &KmclProfilerList) {
      puVar7 = (undefined8 *)0x3;
      pcVar3 = (code *)swi(0x29);
      DAT_140020318 = (uint *)(*pcVar3)();
    }
    *(undefined8 **)puVar1 = puVar7;
    *(uint **)(puVar6 + 4) = DAT_140020318;
    *(uint **)DAT_140020318 = puVar1;
    DAT_140020318 = puVar1;
    *param_3 = puVar6;
  }
  return uVar8;
}



===== KmclpRundownCountZero @ 14000c1a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void KmclpRundownCountZero(undefined8 param_1,longlong *param_2,longlong *param_3)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  ulonglong uVar5;
  longlong *plVar6;
  longlong *plVar7;
  uint *puVar8;
  uint uVar9;
  char *pcVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  longlong local_48;
  longlong lStack_40;
  longlong local_38;
  longlong lStack_30;
  longlong local_28;
  longlong lStack_20;
  
  KmclLockChannel((longlong)param_2);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6f,param_3,param_2,(char)param_2[0x113]);
  }
  pcVar10 = "";
  uVar9 = DAT_140020050;
  if ((5 < DAT_140020050) && (cVar2 = _tlgKeywordOn(0x140020050,4), cVar2 != '\0')) {
    param_3 = (longlong *)((longlong)param_2 + 0x6ec);
    VmbusTraceVerbRundownFnStart
              ("KmclpRundownCountZero",0xf89,param_3,(short)param_2[0x192],
               *(uint *)(param_2 + 0x113),*(int *)((longlong)param_2 + 0x89c),(int)param_2[0x115],
               pcVar10);
    uVar9 = DAT_140020050;
  }
  puVar8 = (uint *)(param_2 + 0x113);
  if (*puVar8 == 8) {
    *puVar8 = 3;
    LOCK();
    plVar7 = param_2 + 0x194;
    lVar1 = *plVar7;
    *(int *)plVar7 = (int)*plVar7 + 1;
    UNLOCK();
    uVar9 = (int)lVar1 + 1;
    uVar5 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar5 == 0) {
      iVar3 = (int)((ulonglong)((longlong)(int)uVar9 * -0x2aaaaaab) >> 0x20);
      iVar3 = ((iVar3 >> 2) - (iVar3 >> 0x1f)) * 0x18;
    }
    else {
      iVar3 = (uVar9 / 0x18) * -0x18;
    }
    param_3 = (longlong *)((longlong)param_2 + 0x89c);
    plVar7 = (longlong *)(longlong)(int)(uVar9 + iVar3);
    *(char *)((longlong)param_2 + (longlong)plVar7 * 6 + 0xca4) = (char)*puVar8;
    *(undefined1 *)((longlong)param_2 + (longlong)plVar7 * 6 + 0xca5) =
         *(undefined1 *)((longlong)param_2 + 0x89c);
    *(short *)((longlong)param_2 + (longlong)plVar7 * 6 + 0xca6) = (short)param_2[0x115];
    *(undefined2 *)((longlong)param_2 + (longlong)plVar7 * 6 + 0xca8) = 3999;
    if (DAT_140020050 < 5) goto LAB_14000c7be;
    uVar12 = (undefined4)param_2[0x115];
    uVar13 = 3999;
    uVar11 = *(undefined4 *)param_3;
    uVar4 = (undefined4)param_2[0x113];
LAB_14000c77d:
    local_28 = param_2[0x152];
    lStack_20 = param_2[0x153];
    plVar6 = &local_48;
    param_3 = &local_28;
    local_48 = param_2[0x154];
    lStack_40 = param_2[0x155];
  }
  else {
    if (*puVar8 == 10) {
      if (*(char *)((longlong)param_2 + 0x6c1) == '\0') {
        if ((4 < uVar9) && (cVar2 = _tlgKeywordOn(0x140020050,4), cVar2 != '\0')) {
          param_3 = (longlong *)((longlong)param_2 + 0x6ec);
          VmbusTraceInfoRundownEvent
                    ("KmclpRundownCountZero",0xf95,param_3,(short)param_2[0x192],*puVar8,
                     *(int *)((longlong)param_2 + 0x89c),(int)param_2[0x115],
                     "Stopping outgoing queue");
        }
        OutStopQueue(param_2);
      }
      plVar6 = param_2 + 0x113;
      *(undefined4 *)plVar6 = 4;
      LOCK();
      plVar7 = param_2 + 0x194;
      lVar1 = *plVar7;
      *(int *)plVar7 = (int)*plVar7 + 1;
      UNLOCK();
      uVar9 = (int)lVar1 + 1;
      uVar5 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar5 == 0) {
        iVar3 = (int)((ulonglong)((longlong)(int)uVar9 * -0x2aaaaaab) >> 0x20);
        iVar3 = ((iVar3 >> 2) - (iVar3 >> 0x1f)) * 0x18;
      }
      else {
        iVar3 = (uVar9 / 0x18) * -0x18;
      }
      plVar7 = (longlong *)(longlong)(int)(uVar9 + iVar3);
      *(char *)((longlong)param_2 + (longlong)plVar7 * 6 + 0xca4) = (char)*plVar6;
      *(undefined1 *)((longlong)param_2 + (longlong)plVar7 * 6 + 0xca5) =
           *(undefined1 *)((longlong)param_2 + 0x89c);
      *(short *)((longlong)param_2 + (longlong)plVar7 * 6 + 0xca6) = (short)param_2[0x115];
      *(undefined2 *)((longlong)param_2 + (longlong)plVar7 * 6 + 0xca8) = 0xf9a;
      if (DAT_140020050 < 5) goto LAB_14000c7be;
      uVar12 = (undefined4)param_2[0x115];
      uVar13 = 0xf9a;
      uVar11 = *(undefined4 *)((longlong)param_2 + 0x89c);
      uVar4 = (undefined4)*plVar6;
      goto LAB_14000c77d;
    }
    if (*(char *)((longlong)param_2 + 0x6c1) == '\0') {
      OutPurgeQueue(param_2);
      InPurgeCompletions((longlong)param_2);
    }
    KmclUnlockChannel((longlong)param_2);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      param_3 = (longlong *)&WPP_a989f33e64883200e74810d340c3677a_Traceguids;
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x70,
               &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_2);
    }
    if ((4 < DAT_140020050) && (cVar2 = _tlgKeywordOn(0x140020050,4), cVar2 != '\0')) {
      param_3 = (longlong *)((longlong)param_2 + 0x6ec);
      VmbusTraceInfoRundownEvent
                ("KmclpRundownCountZero",0xfbd,param_3,(short)param_2[0x192],
                 *(uint *)(param_2 + 0x113),*(int *)((longlong)param_2 + 0x89c),(int)param_2[0x115],
                 "Notifying client that channel is closing");
    }
    if ((char)param_2[0xfd] == '\0') {
      (*(code *)param_2[0x100])(param_2);
    }
    else {
      (*(code *)param_2[0x101])(param_2,param_2[0xff]);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      param_3 = (longlong *)&WPP_a989f33e64883200e74810d340c3677a_Traceguids;
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x71,
               &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_2);
    }
    if (*(char *)((longlong)param_2 + 0x6c1) == '\0') {
      if (*(char *)((longlong)param_2 + 0x706) != '\0') {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          param_3 = (longlong *)&WPP_a989f33e64883200e74810d340c3677a_Traceguids;
          WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x72,
                   &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_2);
        }
        if ((4 < DAT_140020050) && (cVar2 = _tlgKeywordOn(0x140020050,4), cVar2 != '\0')) {
          param_3 = (longlong *)((longlong)param_2 + 0x6ec);
          VmbusTraceInfoRundownEvent
                    ("KmclpRundownCountZero",0xfe0,param_3,(short)param_2[0x192],
                     *(uint *)(param_2 + 0x113),*(int *)((longlong)param_2 + 0x89c),
                     (int)param_2[0x115],"Waiting for deferred packet completions");
        }
        InWaitForDeferredPackets(param_2);
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          param_3 = (longlong *)&WPP_a989f33e64883200e74810d340c3677a_Traceguids;
          WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x73,
                   &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_2);
        }
      }
      InPurgeQueue(param_2);
    }
    KmclLockChannel((longlong)param_2);
    KmclpTeardownOpenChannelState(param_2);
    *(undefined4 *)(param_2 + 0x113) = 3;
    LOCK();
    plVar7 = param_2 + 0x194;
    lVar1 = *plVar7;
    *(int *)plVar7 = (int)*plVar7 + 1;
    UNLOCK();
    uVar9 = (int)lVar1 + 1;
    uVar5 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar5 == 0) {
      iVar3 = (int)((ulonglong)((longlong)(int)uVar9 * -0x2aaaaaab) >> 0x20);
      iVar3 = ((iVar3 >> 2) - (iVar3 >> 0x1f)) * 0x18;
    }
    else {
      iVar3 = (uVar9 / 0x18) * -0x18;
    }
    plVar7 = (longlong *)(longlong)(int)(uVar9 + iVar3);
    *(char *)((longlong)param_2 + (longlong)plVar7 * 6 + 0xca4) = (char)param_2[0x113];
    *(undefined1 *)((longlong)param_2 + (longlong)plVar7 * 6 + 0xca5) =
         *(undefined1 *)((longlong)param_2 + 0x89c);
    *(short *)((longlong)param_2 + (longlong)plVar7 * 6 + 0xca6) = (short)param_2[0x115];
    *(undefined2 *)((longlong)param_2 + (longlong)plVar7 * 6 + 0xca8) = 0xffb;
    if (DAT_140020050 < 5) goto LAB_14000c7be;
    uVar12 = (undefined4)param_2[0x115];
    param_3 = &local_48;
    local_48 = param_2[0x152];
    lStack_40 = param_2[0x153];
    uVar13 = 0xffb;
    plVar6 = &local_28;
    uVar11 = *(undefined4 *)((longlong)param_2 + 0x89c);
    local_28 = param_2[0x154];
    lStack_20 = param_2[0x155];
    uVar4 = (undefined4)param_2[0x113];
  }
  local_38 = param_2[0x150];
  lStack_30 = param_2[0x151];
  plVar7 = &local_38;
  VmbusTraceInfoChannelStateChange
            (plVar6,plVar7,param_3,(ulonglong)*(ushort *)(param_2 + 0x192),uVar4,uVar11,uVar12,
             uVar13);
LAB_14000c7be:
  KmclpContinueChannelRundownAndUnlock(param_2,plVar7,param_3);
  if ((5 < DAT_140020050) && (cVar2 = _tlgKeywordOn(0x140020050,4), cVar2 != '\0')) {
    VmbusTraceVerbRundownFnStop
              ("KmclpRundownCountZero",0x1006,(longlong)param_2 + 0x6ec,(short)param_2[0x192],
               *(uint *)(param_2 + 0x113),*(int *)((longlong)param_2 + 0x89c),(int)param_2[0x115],""
              );
  }
  return;
}



===== KmclpSynchronousIoControl @ 14000c854 =====

ulonglong KmclpSynchronousIoControl
                    (longlong param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4,
                    undefined8 param_5,undefined4 param_6)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong local_38 [6];
  
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  KeInitializeEvent(local_38 + 2,1,0);
  lVar1 = IoBuildDeviceIoControlRequest
                    (param_2,*(undefined8 *)(param_1 + 0xa70),param_3,param_4,param_5,param_6,0,
                     local_38 + 2,local_38);
  if (lVar1 == 0) {
    uVar2 = 0xc000009a;
  }
  else {
    *(undefined8 *)(*(longlong *)(lVar1 + 0xb8) + -0x18) = *(undefined8 *)(param_1 + 0xa78);
    uVar2 = IofCallDriver(*(undefined8 *)(param_1 + 0xa70),lVar1);
    if ((int)uVar2 == 0x103) {
      KeWaitForSingleObject(local_38 + 2,0,0,0,0);
      uVar2 = local_38[0] & 0xffffffff;
    }
  }
  return uVar2;
}



===== KmclpFinishSuspendProcessAndUnlock @ 14000c96c =====

void KmclpFinishSuspendProcessAndUnlock(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  int *piVar1;
  longlong lVar2;
  char cVar3;
  int iVar4;
  ulonglong uVar5;
  undefined4 *puVar6;
  longlong lVar7;
  undefined8 uVar8;
  uint uVar9;
  char *pcVar10;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qLd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x77,param_3,param_1,
               (char)*(undefined4 *)(param_1 + 0x898),*(byte *)(param_1 + 0x8f8) >> 6 & 1);
  }
  pcVar10 = "";
  if (5 < DAT_140020050) {
    cVar3 = _tlgKeywordOn(0x140020050,4);
    if (cVar3 != '\0') {
      VmbusTraceVerbRundownFnStart
                ("KmclpFinishSuspendProcessAndUnlock",0x110c,param_1 + 0x6ec,
                 *(undefined2 *)(param_1 + 0xc90),*(uint *)(param_1 + 0x898),
                 *(int *)(param_1 + 0x89c),*(undefined4 *)(param_1 + 0x8a8),pcVar10);
    }
  }
  *(undefined4 *)(param_1 + 0x89c) = 0;
  LOCK();
  piVar1 = (int *)(param_1 + 0xca0);
  iVar4 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  uVar9 = iVar4 + 1;
  uVar5 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar5 == 0) {
    iVar4 = (int)((ulonglong)((longlong)(int)uVar9 * -0x2aaaaaab) >> 0x20);
    iVar4 = ((iVar4 >> 2) - (iVar4 >> 0x1f)) * 0x18;
  }
  else {
    iVar4 = (uVar9 / 0x18) * -0x18;
  }
  lVar7 = (longlong)(int)(uVar9 + iVar4);
  *(undefined1 *)(param_1 + 0xca4 + lVar7 * 6) = *(undefined1 *)(param_1 + 0x898);
  *(undefined1 *)(param_1 + 0xca5 + lVar7 * 6) = *(undefined1 *)(param_1 + 0x89c);
  *(short *)(param_1 + 0xca6 + lVar7 * 6) = (short)*(undefined4 *)(param_1 + 0x8a8);
  *(undefined2 *)(param_1 + 0xca8 + lVar7 * 6) = 0x110f;
  if (4 < DAT_140020050) {
    local_48 = *(undefined8 *)(param_1 + 0xa90);
    uStack_40 = *(undefined8 *)(param_1 + 0xa98);
    local_38 = *(undefined8 *)(param_1 + 0xa80);
    uStack_30 = *(undefined8 *)(param_1 + 0xa88);
    local_28 = *(undefined8 *)(param_1 + 0xaa0);
    uStack_20 = *(undefined8 *)(param_1 + 0xaa8);
    VmbusTraceInfoChannelStateChange
              (&local_28,&local_38,&local_48,(ulonglong)*(ushort *)(param_1 + 0xc90),
               *(undefined4 *)(param_1 + 0x898),*(undefined4 *)(param_1 + 0x89c),
               *(undefined4 *)(param_1 + 0x8a8),0x110f);
  }
  if ((*(byte *)(param_1 + 0x8f8) & 0x40) == 0) {
    lVar7 = 0;
  }
  else {
    lVar7 = *(longlong *)(param_1 + 0xc18);
    *(byte *)(param_1 + 0x8f8) = *(byte *)(param_1 + 0x8f8) & 0xbf;
  }
  lVar2 = *(longlong *)(param_1 + 0x8a0);
  *(undefined8 *)(param_1 + 0x8a0) = 0;
  KmclUnlockChannel(param_1);
  if (4 < DAT_140020050) {
    uVar8 = 4;
    puVar6 = &DAT_140020050;
    cVar3 = _tlgKeywordOn(0x140020050,4);
    if (cVar3 != '\0') {
      VmbusTraceInfoRundownStop
                (puVar6,uVar8,param_1 + 0x6ec,*(undefined2 *)(param_1 + 0xc90),
                 *(uint *)(param_1 + 0x898),*(int *)(param_1 + 0x89c),*(uint *)(param_1 + 0x8a8));
    }
  }
  if (lVar7 != 0) {
    if (4 < DAT_140020050) {
      cVar3 = _tlgKeywordOn(0x140020050,4);
      if (cVar3 != '\0') {
        pcVar10 = "Subchannel paused";
        if (*(int *)(param_1 + 0x898) != 4) {
          pcVar10 = "Subchannel disabled";
        }
        VmbusTraceInfoRundownEvent
                  ("KmclpFinishSuspendProcessAndUnlock",0x1128,param_1 + 0x6ec,
                   *(undefined2 *)(param_1 + 0xc90),*(uint *)(param_1 + 0x898),
                   *(int *)(param_1 + 0x89c),*(undefined4 *)(param_1 + 0x8a8),pcVar10);
      }
    }
    KmclDecrementRundownCount(*(longlong *)(param_1 + 0xc18),'\x01',0x112a);
  }
  if (lVar2 != 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x78,
               &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1);
    }
    if (4 < DAT_140020050) {
      cVar3 = _tlgKeywordOn(0x140020050,4);
      if (cVar3 != '\0') {
        VmbusTraceInfoRundownEvent
                  ("KmclpFinishSuspendProcessAndUnlock",0x1135,param_1 + 0x6ec,
                   *(undefined2 *)(param_1 + 0xc90),*(uint *)(param_1 + 0x898),
                   *(int *)(param_1 + 0x89c),*(undefined4 *)(param_1 + 0x8a8),
                   "Setting SuspendDoneEvent");
      }
    }
    KmclpSignalWaiters(lVar2);
  }
  if (5 < DAT_140020050) {
    cVar3 = _tlgKeywordOn(0x140020050,4);
    if (cVar3 != '\0') {
      VmbusTraceVerbRundownFnStop
                ("KmclpFinishSuspendProcessAndUnlock",0x1139,param_1 + 0x6ec,
                 *(undefined2 *)(param_1 + 0xc90),*(uint *)(param_1 + 0x898),
                 *(int *)(param_1 + 0x89c),*(undefined4 *)(param_1 + 0x8a8),"");
    }
  }
  return;
}



===== KmclpDisableClosedChannel @ 14000cd68 =====

void KmclpDisableClosedChannel(longlong param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  ulonglong uVar4;
  longlong lVar5;
  uint uVar6;
  longlong lVar7;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x79,
             &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1);
  }
  if (5 < DAT_140020050) {
    cVar2 = _tlgKeywordOn(0x140020050,4);
    if (cVar2 != '\0') {
      VmbusTraceVerbRundownFnStart
                ("KmclpDisableClosedChannel",0x1151,param_1 + 0x6ec,*(undefined2 *)(param_1 + 0xc90)
                 ,*(uint *)(param_1 + 0x898),*(int *)(param_1 + 0x89c),
                 *(undefined4 *)(param_1 + 0x8a8),"");
    }
  }
  ExAcquireFastMutex(&KmclPerformanceCounterLock);
  lVar5 = *(longlong *)(param_1 + 0x878);
  lVar7 = 0;
  if (lVar5 != 0) {
    *(undefined8 *)(param_1 + 0x878) = 0;
    *(undefined2 *)(param_1 + 0x870) = 0;
    lVar7 = lVar5;
  }
  ExReleaseFastMutex(&KmclPerformanceCounterLock);
  if (lVar7 != 0) {
    ExFreePoolWithTag(lVar7,0x636d6b56);
  }
  if (*(longlong *)(param_1 + 0xab0) != 0) {
    IoFreeIrp();
    *(undefined8 *)(param_1 + 0xab0) = 0;
  }
  if (*(char *)(param_1 + 0xad9) != '\0') {
    KmclpFreeAllBounceBlocks(param_1);
  }
  VmbusDropInterface(param_1);
  if (*(char *)(param_1 + 0x7c1) == '\0') {
    if (*(longlong *)(param_1 + 0xa70) != 0) {
      ObfDereferenceObject();
      *(undefined8 *)(param_1 + 0xa70) = 0;
    }
    if (*(longlong *)(param_1 + 0xa78) != 0) {
      ObfDereferenceObject();
      *(undefined8 *)(param_1 + 0xa78) = 0;
    }
  }
  *(undefined8 *)(param_1 + 0xa90) = 0;
  *(undefined8 *)(param_1 + 0xa98) = 0;
  *(undefined8 *)(param_1 + 0xa80) = 0;
  *(undefined8 *)(param_1 + 0xa88) = 0;
  *(undefined4 *)(param_1 + 0x898) = 0;
  LOCK();
  piVar1 = (int *)(param_1 + 0xca0);
  iVar3 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  uVar6 = iVar3 + 1;
  uVar4 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar4 == 0) {
    iVar3 = (int)((ulonglong)((longlong)(int)uVar6 * -0x2aaaaaab) >> 0x20);
    iVar3 = ((iVar3 >> 2) - (iVar3 >> 0x1f)) * 0x18;
  }
  else {
    iVar3 = (uVar6 / 0x18) * -0x18;
  }
  lVar5 = (longlong)(int)(uVar6 + iVar3);
  *(undefined1 *)(param_1 + 0xca4 + lVar5 * 6) = *(undefined1 *)(param_1 + 0x898);
  *(undefined1 *)(param_1 + 0xca5 + lVar5 * 6) = *(undefined1 *)(param_1 + 0x89c);
  *(short *)(param_1 + 0xca6 + lVar5 * 6) = (short)*(undefined4 *)(param_1 + 0x8a8);
  *(undefined2 *)(param_1 + 0xca8 + lVar5 * 6) = 0x119a;
  if (4 < DAT_140020050) {
    local_38 = *(undefined8 *)(param_1 + 0xa90);
    uStack_30 = *(undefined8 *)(param_1 + 0xa98);
    local_28 = *(undefined8 *)(param_1 + 0xa80);
    uStack_20 = *(undefined8 *)(param_1 + 0xa88);
    local_18 = *(undefined8 *)(param_1 + 0xaa0);
    uStack_10 = *(undefined8 *)(param_1 + 0xaa8);
    VmbusTraceInfoChannelStateChange
              (&local_18,&local_28,&local_38,(ulonglong)*(ushort *)(param_1 + 0xc90),
               *(undefined4 *)(param_1 + 0x898),*(undefined4 *)(param_1 + 0x89c),
               *(undefined4 *)(param_1 + 0x8a8),0x119a);
  }
  if (5 < DAT_140020050) {
    cVar2 = _tlgKeywordOn(0x140020050,4);
    if (cVar2 != '\0') {
      VmbusTraceVerbRundownFnStop
                ("KmclpDisableClosedChannel",0x119c,param_1 + 0x6ec,*(undefined2 *)(param_1 + 0xc90)
                 ,*(uint *)(param_1 + 0x898),*(int *)(param_1 + 0x89c),
                 *(undefined4 *)(param_1 + 0x8a8),"");
    }
  }
  return;
}



===== KmclDecrementRundownCount @ 14000d088 =====

void KmclDecrementRundownCount(longlong param_1,char param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  ulonglong uVar4;
  longlong lVar5;
  uint uVar6;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x8a8);
  iVar3 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  LOCK();
  piVar1 = (int *)(param_1 + 0xca0);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  uVar6 = iVar2 + 1;
  uVar4 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar4 == 0) {
    iVar2 = (int)((ulonglong)((longlong)(int)uVar6 * -0x2aaaaaab) >> 0x20);
    iVar2 = ((iVar2 >> 2) - (iVar2 >> 0x1f)) * 0x18;
  }
  else {
    iVar2 = (uVar6 / 0x18) * -0x18;
  }
  lVar5 = (longlong)(int)(uVar6 + iVar2);
  *(undefined1 *)(param_1 + 0xca4 + lVar5 * 6) = *(undefined1 *)(param_1 + 0x898);
  *(undefined1 *)(param_1 + 0xca5 + lVar5 * 6) = *(undefined1 *)(param_1 + 0x89c);
  *(short *)(param_1 + 0xca6 + lVar5 * 6) = (short)*(undefined4 *)(param_1 + 0x8a8);
  *(short *)(param_1 + 0xca8 + lVar5 * 6) = (short)param_3;
  if (4 < DAT_140020050) {
    local_78 = *(undefined8 *)(param_1 + 0xa90);
    uStack_70 = *(undefined8 *)(param_1 + 0xa98);
    local_68 = *(undefined8 *)(param_1 + 0xa80);
    uStack_60 = *(undefined8 *)(param_1 + 0xa88);
    local_58 = *(undefined8 *)(param_1 + 0xaa0);
    uStack_50 = *(undefined8 *)(param_1 + 0xaa8);
    VmbusTraceInfoChannelStateChange
              (&local_58,&local_68,&local_78,(ulonglong)*(ushort *)(param_1 + 0xc90),
               *(undefined4 *)(param_1 + 0x898),*(undefined4 *)(param_1 + 0x89c),
               *(undefined4 *)(param_1 + 0x8a8),param_3);
  }
  if ((iVar3 == 1) && (param_2 != '\0')) {
    LOCK();
    piVar1 = (int *)(param_1 + 0xca0);
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    uVar6 = iVar3 + 1;
    uVar4 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar4 == 0) {
      iVar3 = (int)((ulonglong)((longlong)(int)uVar6 * -0x2aaaaaab) >> 0x20);
      iVar3 = ((iVar3 >> 2) - (iVar3 >> 0x1f)) * 0x18;
    }
    else {
      iVar3 = (uVar6 / 0x18) * -0x18;
    }
    lVar5 = (longlong)(int)(uVar6 + iVar3);
    *(undefined1 *)(param_1 + 0xca4 + lVar5 * 6) = *(undefined1 *)(param_1 + 0x898);
    *(undefined1 *)(param_1 + 0xca5 + lVar5 * 6) = *(undefined1 *)(param_1 + 0x89c);
    *(short *)(param_1 + 0xca6 + lVar5 * 6) = (short)*(undefined4 *)(param_1 + 0x8a8);
    *(undefined2 *)(param_1 + 0xca8 + lVar5 * 6) = 0x10d5;
    if (4 < DAT_140020050) {
      local_48 = *(undefined8 *)(param_1 + 0xa90);
      uStack_40 = *(undefined8 *)(param_1 + 0xa98);
      local_38 = *(undefined8 *)(param_1 + 0xa80);
      uStack_30 = *(undefined8 *)(param_1 + 0xa88);
      local_28 = *(undefined8 *)(param_1 + 0xaa0);
      uStack_20 = *(undefined8 *)(param_1 + 0xaa8);
      VmbusTraceInfoChannelStateChange
                (&local_28,&local_38,&local_48,(ulonglong)*(ushort *)(param_1 + 0xc90),
                 *(undefined4 *)(param_1 + 0x898),*(undefined4 *)(param_1 + 0x89c),
                 *(undefined4 *)(param_1 + 0x8a8),0x10d5);
    }
    IoQueueWorkItem(*(undefined8 *)(param_1 + 0x8b0),KmclpRundownCountZero,1,param_1);
  }
  return;
}



===== OutInitializePacket @ 14000d2e0 =====

void OutInitializePacket(undefined8 param_1,longlong param_2,int param_3,undefined8 param_4)

{
  *(undefined8 *)(param_2 + 0x10) = param_1;
  *(undefined8 *)(param_2 + 0x18) = 1;
  *(longlong *)(param_2 + 0x68) = param_2 + 0xf0;
  *(undefined8 *)(param_2 + 0x20) = 0;
  *(undefined8 *)(param_2 + 0x28) = 0;
  *(undefined4 *)(param_2 + 0xa0) = 1;
  *(undefined2 *)(param_2 + 0x3d) = 0;
  *(int *)(param_2 + 0xac) = param_3 + -0xf0;
  *(int *)(param_2 + 0x70) = param_3 + -0xf0;
  *(undefined8 *)(param_2 + 0x88) = 0;
  *(undefined8 *)(param_2 + 0x78) = 0;
  *(undefined8 *)(param_2 + 0x80) = 0;
  *(undefined8 *)(param_2 + 0x58) = param_4;
  return;
}



===== VmbChannelInitSetStateChangeCallbacks @ 14000d340 =====

undefined8 VmbChannelInitSetStateChangeCallbacks(longlong param_1,int *param_2)

{
  code *pcVar1;
  
                    /* 0xd340  45  VmbChannelInitSetStateChangeCallbacks */
  if ((*(int *)(param_1 + 0x898) != 0) && (*(int *)(param_1 + 0x898) != 0xc)) {
    return 0xc00000ef;
  }
  if (*param_2 == 5) {
    if (param_2[1] != 0x38) {
      return 0xc00000f0;
    }
    *(undefined1 *)(param_1 + 0x7e8) = 1;
    *(undefined8 *)(param_1 + 0x7f8) = *(undefined8 *)(param_2 + 2);
    pcVar1 = KmclpDefaultChannelOpenedEx;
    if (*(code **)(param_2 + 4) != (code *)0x0) {
      pcVar1 = *(code **)(param_2 + 4);
    }
    *(code **)(param_1 + 0x800) = pcVar1;
    pcVar1 = _guard_check_icall;
    if (*(code **)(param_2 + 6) != (code *)0x0) {
      pcVar1 = *(code **)(param_2 + 6);
    }
    *(code **)(param_1 + 0x808) = pcVar1;
    pcVar1 = _guard_check_icall;
    if (*(code **)(param_2 + 10) != (code *)0x0) {
      pcVar1 = *(code **)(param_2 + 10);
    }
    *(code **)(param_1 + 0x818) = pcVar1;
    pcVar1 = _guard_check_icall;
    if (*(code **)(param_2 + 0xc) != (code *)0x0) {
      pcVar1 = *(code **)(param_2 + 0xc);
    }
    *(code **)(param_1 + 0x820) = pcVar1;
    pcVar1 = _guard_check_icall;
    if (*(code **)(param_2 + 8) != (code *)0x0) {
      pcVar1 = *(code **)(param_2 + 8);
    }
    *(code **)(param_1 + 0x810) = pcVar1;
  }
  else {
    if (*param_2 != 1) {
      return 0xc00000f0;
    }
    if (param_2[1] != 0x30) {
      return 0xc00000f0;
    }
    if (*(longlong *)(param_2 + 4) != 0) {
      *(longlong *)(param_1 + 0x800) = *(longlong *)(param_2 + 4);
    }
    if (*(longlong *)(param_2 + 2) != 0) {
      *(longlong *)(param_1 + 0x7f8) = *(longlong *)(param_2 + 2);
    }
    if (*(longlong *)(param_2 + 8) != 0) {
      *(longlong *)(param_1 + 0x810) = *(longlong *)(param_2 + 8);
    }
    if (*(longlong *)(param_2 + 10) != 0) {
      *(longlong *)(param_1 + 0x818) = *(longlong *)(param_2 + 10);
    }
    if (*(longlong *)(param_2 + 6) != 0) {
      *(longlong *)(param_1 + 0x808) = *(longlong *)(param_2 + 6);
    }
  }
  return 0;
}



===== KmclpDisableChannel @ 14000d46c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void KmclpDisableChannel(longlong param_1,char param_2,undefined8 *param_3)

{
  int *piVar1;
  undefined8 uVar2;
  char cVar3;
  int iVar4;
  char *pcVar5;
  ulonglong uVar6;
  longlong lVar7;
  uint uVar8;
  char *pcVar9;
  char *pcVar10;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  KmclLockChannel(param_1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qLd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,param_3,param_1,
               (char)*(undefined4 *)(param_1 + 0x898),param_2);
  }
  pcVar9 = "Wait: false";
  pcVar10 = "Wait: true";
  if (5 < DAT_140020050) {
    cVar3 = _tlgKeywordOn(0x140020050,4);
    if (cVar3 != '\0') {
      param_3 = (undefined8 *)(param_1 + 0x6ec);
      pcVar5 = "Wait: true";
      if (param_2 == '\0') {
        pcVar5 = pcVar9;
      }
      VmbusTraceVerbRundownFnStart
                ("KmclpDisableChannel",0x251,param_3,*(undefined2 *)(param_1 + 0xc90),
                 *(uint *)(param_1 + 0x898),*(int *)(param_1 + 0x89c),
                 *(undefined4 *)(param_1 + 0x8a8),pcVar5);
    }
  }
  *(byte *)(param_1 + 0x8f8) = *(byte *)(param_1 + 0x8f8) & 0xfb;
  iVar4 = *(int *)(param_1 + 0x898);
  if (iVar4 != 0) {
    if (iVar4 != 1) {
      if (iVar4 == 0xc) {
        KmclUnlockChannel(param_1);
        if (*(char *)(param_1 + 0x7e8) == '\0') {
          (**(code **)(param_1 + 0x800))(param_1);
        }
        else {
          (**(code **)(param_1 + 0x808))(param_1,*(undefined8 *)(param_1 + 0x7f8));
        }
      }
      else {
        *(undefined4 *)(param_1 + 0x89c) = 4;
        LOCK();
        piVar1 = (int *)(param_1 + 0xca0);
        iVar4 = *piVar1;
        *piVar1 = *piVar1 + 1;
        UNLOCK();
        uVar8 = iVar4 + 1;
        uVar6 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar6 == 0) {
          iVar4 = (int)((ulonglong)((longlong)(int)uVar8 * -0x2aaaaaab) >> 0x20);
          iVar4 = ((iVar4 >> 2) - (iVar4 >> 0x1f)) * 0x18;
        }
        else {
          iVar4 = (uVar8 / 0x18) * -0x18;
        }
        lVar7 = (longlong)(int)(uVar8 + iVar4);
        *(undefined1 *)(param_1 + 0xca4 + lVar7 * 6) = *(undefined1 *)(param_1 + 0x898);
        *(undefined1 *)(param_1 + 0xca5 + lVar7 * 6) = *(undefined1 *)(param_1 + 0x89c);
        *(short *)(param_1 + 0xca6 + lVar7 * 6) = (short)*(undefined4 *)(param_1 + 0x8a8);
        *(undefined2 *)(param_1 + 0xca8 + lVar7 * 6) = 0x29c;
        if (4 < DAT_140020050) {
          param_3 = &local_98;
          local_98 = *(undefined8 *)(param_1 + 0xa90);
          uStack_90 = *(undefined8 *)(param_1 + 0xa98);
          local_88 = *(undefined8 *)(param_1 + 0xa80);
          uStack_80 = *(undefined8 *)(param_1 + 0xa88);
          local_78 = *(undefined8 *)(param_1 + 0xaa0);
          uStack_70 = *(undefined8 *)(param_1 + 0xaa8);
          VmbusTraceInfoChannelStateChange
                    (&local_78,&local_88,param_3,(ulonglong)*(ushort *)(param_1 + 0xc90),
                     *(undefined4 *)(param_1 + 0x898),*(undefined4 *)(param_1 + 0x89c),
                     *(undefined4 *)(param_1 + 0x8a8),0x29c);
        }
        KmclpRundownChannelStateAndUnlock(param_1,param_2,param_3);
      }
      goto LAB_14000da37;
    }
    *(undefined4 *)(param_1 + 0x898) = 2;
    LOCK();
    piVar1 = (int *)(param_1 + 0xca0);
    iVar4 = *piVar1;
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    uVar8 = iVar4 + 1;
    uVar6 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar6 == 0) {
      iVar4 = (int)((ulonglong)((longlong)(int)uVar8 * -0x2aaaaaab) >> 0x20);
      iVar4 = ((iVar4 >> 2) - (iVar4 >> 0x1f)) * 0x18;
    }
    else {
      iVar4 = (uVar8 / 0x18) * -0x18;
    }
    lVar7 = (longlong)(int)(uVar8 + iVar4);
    *(undefined1 *)(param_1 + 0xca4 + lVar7 * 6) = *(undefined1 *)(param_1 + 0x898);
    *(undefined1 *)(param_1 + 0xca5 + lVar7 * 6) = *(undefined1 *)(param_1 + 0x89c);
    *(short *)(param_1 + 0xca6 + lVar7 * 6) = (short)*(undefined4 *)(param_1 + 0x8a8);
    *(undefined2 *)(param_1 + 0xca8 + lVar7 * 6) = 0x26e;
    if (4 < DAT_140020050) {
      local_68 = *(undefined8 *)(param_1 + 0xa90);
      uStack_60 = *(undefined8 *)(param_1 + 0xa98);
      local_58 = *(undefined8 *)(param_1 + 0xa80);
      uStack_50 = *(undefined8 *)(param_1 + 0xa88);
      local_48 = *(undefined8 *)(param_1 + 0xaa0);
      uStack_40 = *(undefined8 *)(param_1 + 0xaa8);
      VmbusTraceInfoChannelStateChange
                (&local_48,&local_58,&local_68,(ulonglong)*(ushort *)(param_1 + 0xc90),
                 *(undefined4 *)(param_1 + 0x898),*(undefined4 *)(param_1 + 0x89c),
                 *(undefined4 *)(param_1 + 0x8a8),0x26e);
    }
    uVar2 = *(undefined8 *)(param_1 + 0xa48);
    *(undefined8 *)(param_1 + 0xa48) = 0;
    KmclUnlockChannel(param_1);
    IoUnregisterPlugPlayNotificationEx(uVar2);
    KmclLockChannel(param_1);
    *(undefined4 *)(param_1 + 0x898) = 0;
    LOCK();
    piVar1 = (int *)(param_1 + 0xca0);
    iVar4 = *piVar1;
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    uVar8 = iVar4 + 1;
    uVar6 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar6 == 0) {
      iVar4 = (int)((ulonglong)((longlong)(int)uVar8 * -0x2aaaaaab) >> 0x20);
      iVar4 = ((iVar4 >> 2) - (iVar4 >> 0x1f)) * 0x18;
    }
    else {
      iVar4 = (uVar8 / 0x18) * -0x18;
    }
    lVar7 = (longlong)(int)(uVar8 + iVar4);
    *(undefined1 *)(param_1 + 0xca4 + lVar7 * 6) = *(undefined1 *)(param_1 + 0x898);
    *(undefined1 *)(param_1 + 0xca5 + lVar7 * 6) = *(undefined1 *)(param_1 + 0x89c);
    *(short *)(param_1 + 0xca6 + lVar7 * 6) = (short)*(undefined4 *)(param_1 + 0x8a8);
    *(undefined2 *)(param_1 + 0xca8 + lVar7 * 6) = 0x28b;
    if (4 < DAT_140020050) {
      local_38 = *(undefined8 *)(param_1 + 0xa90);
      uStack_30 = *(undefined8 *)(param_1 + 0xa98);
      local_28 = *(undefined8 *)(param_1 + 0xa80);
      uStack_20 = *(undefined8 *)(param_1 + 0xa88);
      local_18 = *(undefined8 *)(param_1 + 0xaa0);
      uStack_10 = *(undefined8 *)(param_1 + 0xaa8);
      VmbusTraceInfoChannelStateChange
                (&local_18,&local_28,&local_38,(ulonglong)*(ushort *)(param_1 + 0xc90),
                 *(undefined4 *)(param_1 + 0x898),*(undefined4 *)(param_1 + 0x89c),
                 *(undefined4 *)(param_1 + 0x8a8),0x28b);
    }
  }
  KmclUnlockChannel(param_1);
  if (param_2 == '\0') {
    if (4 < DAT_140020050) {
      cVar3 = _tlgKeywordOn(0x140020050,4);
      if (cVar3 != '\0') {
        VmbusTraceInfoRundownEvent
                  ("KmclpDisableChannel",0x293,param_1 + 0x6ec,*(undefined2 *)(param_1 + 0xc90),
                   *(uint *)(param_1 + 0x898),*(int *)(param_1 + 0x89c),
                   *(undefined4 *)(param_1 + 0x8a8),"Subchannel already disabled");
      }
    }
    LOCK();
    piVar1 = (int *)(param_1 + 0xca0);
    iVar4 = *piVar1;
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    uVar8 = iVar4 + 1;
    uVar6 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar6 == 0) {
      iVar4 = (int)((ulonglong)((longlong)(int)uVar8 * -0x2aaaaaab) >> 0x20);
      iVar4 = ((iVar4 >> 2) - (iVar4 >> 0x1f)) * 0x18;
    }
    else {
      iVar4 = (uVar8 / 0x18) * -0x18;
    }
    lVar7 = (longlong)(int)(uVar8 + iVar4);
    *(undefined1 *)(param_1 + 0xca4 + lVar7 * 6) = *(undefined1 *)(param_1 + 0x898);
    *(undefined1 *)(param_1 + 0xca5 + lVar7 * 6) = *(undefined1 *)(param_1 + 0x89c);
    *(short *)(param_1 + 0xca6 + lVar7 * 6) = (short)*(undefined4 *)(param_1 + 0x8a8);
    *(undefined2 *)(param_1 + 0xca8 + lVar7 * 6) = 0x294;
    if (4 < DAT_140020050) {
      local_78 = *(undefined8 *)(param_1 + 0xa90);
      uStack_70 = *(undefined8 *)(param_1 + 0xa98);
      local_88 = *(undefined8 *)(param_1 + 0xa80);
      uStack_80 = *(undefined8 *)(param_1 + 0xa88);
      local_98 = *(undefined8 *)(param_1 + 0xaa0);
      uStack_90 = *(undefined8 *)(param_1 + 0xaa8);
      VmbusTraceInfoChannelStateChange
                (&local_98,&local_88,&local_78,(ulonglong)*(ushort *)(param_1 + 0xc90),
                 *(undefined4 *)(param_1 + 0x898),*(undefined4 *)(param_1 + 0x89c),
                 *(undefined4 *)(param_1 + 0x8a8),0x294);
    }
    KmclDecrementRundownCount(*(longlong *)(param_1 + 0xc18),'\0',0x295);
  }
LAB_14000da37:
  if (5 < DAT_140020050) {
    cVar3 = _tlgKeywordOn(0x140020050,4);
    if (cVar3 != '\0') {
      if (param_2 == '\0') {
        pcVar10 = "Wait: false";
      }
      VmbusTraceVerbRundownFnStop
                ("KmclpDisableChannel",0x2a1,param_1 + 0x6ec,*(undefined2 *)(param_1 + 0xc90),
                 *(uint *)(param_1 + 0x898),*(int *)(param_1 + 0x89c),
                 *(undefined4 *)(param_1 + 0x8a8),pcVar10);
    }
  }
  return;
}



===== KmclInitializeChannel @ 14000dacc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint KmclInitializeChannel(void *param_1,undefined8 param_2,char param_3)

{
  code *pcVar1;
  undefined1 auVar2 [16];
  uint uVar3;
  uint uVar4;
  undefined8 *puVar5;
  ulonglong uVar6;
  undefined8 *puVar7;
  longlong lVar8;
  undefined8 *puVar9;
  undefined1 *puVar10;
  undefined1 auStack_78 [8];
  undefined1 auStack_70 [24];
  undefined8 local_58;
  undefined4 local_50;
  undefined2 local_48;
  ulonglong local_38 [4];
  
  local_38[2] = __security_cookie ^ (ulonglong)auStack_78;
  memset(param_1,0,0xd40);
  *(undefined4 *)((longlong)param_1 + 0x8c0) = 1;
  *(undefined8 *)((longlong)param_1 + 0x8c8) = 0;
  *(undefined4 *)((longlong)param_1 + 0x8d0) = 0;
  KeInitializeEvent((longlong)param_1 + 0x8d8,1);
  *(undefined4 *)((longlong)param_1 + 0xc28) = 1;
  *(undefined8 *)((longlong)param_1 + 0xc30) = 0;
  *(undefined4 *)((longlong)param_1 + 0xc38) = 0;
  KeInitializeEvent((longlong)param_1 + 0xc40,1);
  lVar8 = (longlong)param_1 + 0xc70;
  *(longlong *)((longlong)param_1 + 0xc78) = lVar8;
  *(longlong *)lVar8 = lVar8;
  lVar8 = (longlong)param_1 + 0xc60;
  *(longlong *)((longlong)param_1 + 0xc68) = lVar8;
  *(longlong *)lVar8 = lVar8;
  lVar8 = (longlong)param_1 + 0xae0;
  *(longlong *)((longlong)param_1 + 0xae8) = lVar8;
  *(longlong *)lVar8 = lVar8;
  lVar8 = (longlong)param_1 + 0xaf0;
  *(longlong *)((longlong)param_1 + 0xaf8) = lVar8;
  *(longlong *)lVar8 = lVar8;
  *(void **)param_1 = param_1;
  *(undefined1 *)((longlong)param_1 + 0x4b0) = 1;
  *(uint *)((longlong)param_1 + 0x574) = (-(uint)(param_3 != '\0') & 0x101) - 1;
  uVar6 = KmclTscTicksPerNtTick * 0x1e0;
  *(char *)((longlong)param_1 + 0x6c0) = param_3;
  auVar2._8_8_ = 0;
  auVar2._0_8_ = uVar6;
  lVar8 = SUB168(ZEXT816(0x47ae147ae147ae15) * auVar2,8);
  *(ulonglong *)((longlong)param_1 + 0x5d0) = (uVar6 - lVar8 >> 1) + lVar8 >> 6;
  if (param_3 == '\0') {
    *(byte *)((longlong)param_1 + 0x8f8) = *(byte *)((longlong)param_1 + 0x8f8) | 1;
  }
  *(undefined1 *)((longlong)param_1 + 0x7e8) = 0;
  *(code **)((longlong)param_1 + 0x7f8) = KmclpDefaultChannelOpenedEx;
  *(undefined4 *)((longlong)param_1 + 0x7b0) = 0xffffffff;
  *(code **)((longlong)param_1 + 0x800) = _guard_check_icall;
  *(code **)((longlong)param_1 + 0x808) = _guard_check_icall;
  *(code **)((longlong)param_1 + 0x810) = _guard_check_icall;
  *(code **)((longlong)param_1 + 0x818) = _guard_check_icall;
  *(code **)((longlong)param_1 + 0x858) = _guard_check_icall;
  uVar3 = KmclInitializeChannelParentDevice((longlong)param_1,param_2);
  if ((int)uVar3 < 0) {
LAB_14000dcd3:
    VmbChannelCleanup((longlong)param_1);
    puVar10 = auStack_78;
  }
  else {
    if (param_3 == '\0') {
      local_38[0] = 0;
      local_38[1] = 0;
      HviGetHypervisorFeatures(local_38);
      if ((local_38[0] & 0x40000000000000) != 0) {
        *(undefined2 *)((longlong)param_1 + 0xad8) = 0x101;
      }
      if (*(char *)((longlong)param_1 + 0xad9) != '\0') {
        lVar8 = IoAllocateWorkItem(*(undefined8 *)((longlong)param_1 + 0xc80));
        *(longlong *)((longlong)param_1 + 0xb00) = lVar8;
        if (lVar8 == 0) {
          uVar3 = 0xc000009a;
          goto LAB_14000dcd3;
        }
        local_48 = 0;
        uVar3 = ExDefaultNonPagedPoolType | 0x200;
        local_50 = 0x636d6b56;
        *(undefined4 *)((longlong)param_1 + 0x7b4) = 0;
        *(undefined4 *)((longlong)param_1 + 0x7b8) = 0x80000;
        *(undefined4 *)((longlong)param_1 + 0x7bc) = 0x2000000;
        local_58 = 0x20;
        ExInitializeNPagedLookasideList((longlong)param_1 + 0xb40,0,0,uVar3);
        *(undefined1 *)((longlong)param_1 + 0xbc0) = 1;
      }
    }
    ExAcquireFastMutex(&KmclChannelListLock);
    puVar10 = auStack_78;
    puVar9 = &KmclChannelList;
    puVar5 = (undefined8 *)((longlong)param_1 + 0x860);
    puVar7 = DAT_1400202a8;
    if ((undefined8 *)*DAT_1400202a8 != &KmclChannelList) {
      puVar7 = (undefined8 *)0x3;
      pcVar1 = (code *)swi(0x29);
      puVar5 = (undefined8 *)(*pcVar1)();
      puVar10 = auStack_70;
    }
    puVar5[1] = puVar7;
    *puVar5 = puVar9;
    *puVar7 = puVar5;
    *(undefined8 *)(puVar10 + -8) = 0x14000dda9;
    DAT_1400202a8 = puVar5;
    ExReleaseFastMutex(&KmclChannelListLock);
    lVar8 = KmclPerformanceCounterFrequency;
    *(undefined8 *)((longlong)param_1 + 0x250) = 0xffffffffffffffff;
    *(longlong *)((longlong)param_1 + 0x260) = lVar8;
    *(undefined8 *)((longlong)param_1 + 0x248) = 0;
    *(undefined8 *)(puVar10 + -8) = 0x14000ddd0;
    uVar4 = KmclpGetTraceLogPacketDelayThreshold();
    uVar3 = 0;
    *(ulonglong *)((longlong)param_1 + 0x8b8) = (ulonglong)uVar4 * KmclPerformanceCounterFrequency;
  }
  *(undefined8 *)(puVar10 + -8) = 0x14000dcea;
  return uVar3;
}



===== VmbChannelCleanup @ 14000ddf0 =====

void VmbChannelCleanup(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  
                    /* 0xddf0  6  VmbChannelCleanup */
  if (*(int *)(param_1 + 0x898) != 0xc) {
    lVar2 = *(longlong *)(param_1 + 0xc18);
    if (lVar2 != 0) {
      KmclLockChannel(lVar2);
      ExAcquireFastMutexUnsafe(lVar2 + 0xc28);
      plVar1 = (longlong *)(param_1 + 0xc70);
      lVar3 = *plVar1;
      if ((*(longlong **)(lVar3 + 8) != plVar1) ||
         (plVar4 = *(longlong **)(param_1 + 0xc78), (longlong *)*plVar4 != plVar1))
      goto LAB_14000e049;
      *plVar4 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar4;
      ExReleaseFastMutexUnsafe(lVar2 + 0xc28);
      KmclUnlockChannel(lVar2);
      *(undefined8 *)(param_1 + 0xc18) = 0;
    }
    plVar1 = (longlong *)(param_1 + 0xc60);
    if ((longlong *)*plVar1 != plVar1) {
      KeEnterCriticalRegion();
      ExAcquireFastMutexUnsafe(param_1 + 0xc28);
      while (plVar4 = (longlong *)*plVar1, plVar4 != plVar1) {
        if (((longlong *)plVar4[1] != plVar1) ||
           (lVar2 = *plVar4, *(longlong **)(lVar2 + 8) != plVar4)) goto LAB_14000e049;
        *plVar1 = lVar2;
        *(longlong **)(lVar2 + 8) = plVar1;
        plVar4[1] = (longlong)plVar4;
        *plVar4 = (longlong)plVar4;
        plVar4[-0xb] = 0;
      }
      ExReleaseFastMutexUnsafe(param_1 + 0xc28);
      KeLeaveCriticalRegion();
    }
    if (*(longlong *)(param_1 + 0x890) != 0) {
      RtlFreeUnicodeString(param_1 + 0x888);
    }
    plVar1 = (longlong *)(param_1 + 0x860);
    if (*plVar1 != 0) {
      ExAcquireFastMutex(&KmclChannelListLock);
      lVar2 = *plVar1;
      if ((*(longlong **)(lVar2 + 8) != plVar1) ||
         (plVar4 = *(longlong **)(param_1 + 0x868), (longlong *)*plVar4 != plVar1)) {
LAB_14000e049:
        pcVar5 = (code *)swi(0x29);
        (*pcVar5)(3);
        pcVar5 = (code *)swi(3);
        (*pcVar5)();
        return;
      }
      *plVar4 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar4;
      ExReleaseFastMutex(&KmclChannelListLock);
    }
    if (*(longlong *)(param_1 + 0xb00) != 0) {
      IoFreeWorkItem();
      *(undefined8 *)(param_1 + 0xb00) = 0;
    }
    KmclpFreeAllBounceBlocks(param_1);
    if (*(char *)(param_1 + 0xbc0) != '\0') {
      ExDeleteNPagedLookasideList(param_1 + 0xb40);
      *(undefined1 *)(param_1 + 0xbc0) = 0;
    }
    if ((*(char *)(param_1 + 0x6c1) == '\0') && ((*(byte *)(param_1 + 0x8f8) & 0x20) != 0)) {
      OutUninitializeQueue(param_1);
    }
    if (*(longlong *)(param_1 + 0xa70) != 0) {
      ObfDereferenceObject();
      *(undefined8 *)(param_1 + 0xa70) = 0;
    }
    if (*(longlong *)(param_1 + 0xa78) != 0) {
      ObfDereferenceObject();
      *(undefined8 *)(param_1 + 0xa78) = 0;
    }
    KmclChannelCleanupParentDevice(param_1);
    if ((*(byte *)(param_1 + 0x8f8) & 8) != 0) {
      ExFreePoolWithTag(param_1,0x636d6b56);
    }
  }
  return;
}



===== InpFreePacketProfilerLocked @ 14000e058 =====

void InpFreePacketProfilerLocked(uint *param_1)

{
  uint *puVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  uint uVar5;
  ulonglong uVar6;
  
  uVar6 = 0;
  if (*param_1 != 0) {
    do {
      ExDeleteNPagedLookasideList(param_1 + uVar6 * 0x20 + 0x10);
      uVar5 = (int)uVar6 + 1;
      uVar6 = (ulonglong)uVar5;
    } while (uVar5 < *param_1);
  }
  puVar1 = param_1 + 2;
  lVar2 = *(longlong *)puVar1;
  if ((*(uint **)(lVar2 + 8) == puVar1) &&
     (plVar3 = *(longlong **)(param_1 + 4), (uint *)*plVar3 == puVar1)) {
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    ExFreePoolWithTag(param_1,0x6e696b56);
    return;
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== VmbusSendInterfaceQuery @ 14000e0d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int VmbusSendInterfaceQuery(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_38 = 0;
  uStack_30 = 0;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  uVar3 = IoGetAttachedDeviceReference(*(undefined8 *)(param_1 + 0xa70));
  KeInitializeEvent(&local_28,1);
  lVar4 = IoBuildAsynchronousFsdRequest(0x1b,uVar3,0,0,0,&local_38);
  if (lVar4 == 0) {
    iVar2 = -0x3fffff66;
  }
  else {
    lVar1 = *(longlong *)(lVar4 + 0xb8);
    *(code **)(lVar1 + -0x10) = VmbusSendInterfaceQueryCompletionRoutine;
    *(undefined8 **)(lVar1 + -8) = &local_28;
    *(undefined1 *)(lVar1 + -0x45) = 0xe0;
    lVar1 = *(longlong *)(lVar4 + 0xb8);
    *(undefined **)(lVar1 + -0x40) = &GUID_VMBUS_INTERFACE_STANDARD;
    *(longlong *)(lVar1 + -0x30) = param_1 + 0x908;
    *(undefined1 *)(lVar1 + -0x47) = 8;
    *(undefined4 *)(lVar1 + -0x38) = 0xd0140;
    *(undefined8 *)(lVar1 + -0x28) = *(undefined8 *)(param_1 + 0xa78);
    *(undefined8 *)(lVar1 + -0x18) = *(undefined8 *)(param_1 + 0xa78);
    *(undefined4 *)(lVar4 + 0x30) = 0xc00000bb;
    iVar2 = IofCallDriver(uVar3);
    if (iVar2 == 0x103) {
      KeWaitForSingleObject(&local_28,0,0,0,0);
      iVar2 = (int)local_38;
    }
    if (-1 < iVar2) {
      if (*(short *)(param_1 + 0x90a) == 0xd) {
        iVar2 = 0;
      }
      else {
        if (*(code **)(param_1 + 0x920) != (code *)0x0) {
          (**(code **)(param_1 + 0x920))(*(undefined8 *)(param_1 + 0x910));
          *(undefined8 *)(param_1 + 0x920) = 0;
        }
        iVar2 = -0x3fffffa7;
      }
    }
  }
  ObfDereferenceObject(uVar3);
  return iVar2;
}



===== VmbPacketAllocate @ 14000e280 =====

longlong VmbPacketAllocate(longlong *param_1)

{
  longlong lVar1;
  
                    /* 0xe280  92  VmbPacketAllocate */
  lVar1 = ExAllocateFromNPagedLookasideList(param_1 + 0x28);
  if (lVar1 != 0) {
    OutInitializePacket(param_1,lVar1,*(int *)(*param_1 + 0x6c8) + 0xf0,KmclpFreeCompletionRoutine);
    if (*(int *)(*param_1 + 0x6d8) != 0) {
      *(ulonglong *)(lVar1 + 0x28) = (ulonglong)*(uint *)(lVar1 + 0xac) + 0xf0 + lVar1;
    }
    *(byte *)(lVar1 + 0x3e) = *(byte *)(lVar1 + 0x3e) | 8;
  }
  return lVar1;
}



===== VmbusDropInterface @ 14000e300 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VmbusDropInterface(longlong param_1)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_345048b4f05133d6c38ffb6ee80f3f20_Traceguids,param_1);
  }
  if (*(code **)(param_1 + 0x920) != (code *)0x0) {
    (**(code **)(param_1 + 0x920))(*(undefined8 *)(param_1 + 0x910));
  }
  memset((void *)(param_1 + 0x908),0,0x140);
  return;
}



===== KmclpWaitForActionWorkerRoutine @ 14000e380 =====

void KmclpWaitForActionWorkerRoutine(undefined8 param_1,longlong *param_2,undefined8 param_3)

{
  uint uVar1;
  longlong lVar2;
  char cVar3;
  int iVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  longlong *plVar7;
  longlong *plVar8;
  uint uVar9;
  longlong *plVar10;
  undefined4 uVar11;
  longlong local_48;
  longlong lStack_40;
  longlong local_38;
  longlong lStack_30;
  longlong local_28;
  longlong lStack_20;
  
  KmclLockChannel((longlong)param_2);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x60,param_3,param_2,(char)param_2[0x113]);
  }
  iVar4 = (int)param_2[0x113];
  uVar9 = *(uint *)(param_2 + 0x158);
  uVar5 = (ulonglong)uVar9;
  *(undefined1 *)((longlong)param_2 + 0xac4) = 0;
  uVar1 = *(uint *)(param_2[0x156] + 0x30);
  plVar10 = (longlong *)(ulonglong)uVar1;
  if (iVar4 == 5) {
    if (-1 < (int)uVar1) {
      if (uVar9 == 1) {
        uVar6 = KmclpServerOpenChannel(param_2,1,plVar10);
        if (-1 < (int)uVar6) {
          KmclpResumePausedChannelAndUnlock(param_2,uVar5,plVar10);
          goto LAB_14000e701;
        }
      }
LAB_14000e6f1:
      KmclpStartWaitForAction((longlong)param_2,uVar5,plVar10);
    }
  }
  else if (iVar4 == 7) {
    if (-1 < (int)uVar1) {
      if (uVar9 == 3) {
        *(undefined4 *)((longlong)param_2 + 0x89c) = 2;
        LOCK();
        plVar8 = param_2 + 0x194;
        lVar2 = *plVar8;
        *(int *)plVar8 = (int)*plVar8 + 1;
        UNLOCK();
        uVar9 = (int)lVar2 + 1;
        uVar5 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar5 == 0) {
          iVar4 = (int)((ulonglong)((longlong)(int)uVar9 * -0x2aaaaaab) >> 0x20);
          iVar4 = ((iVar4 >> 2) - (iVar4 >> 0x1f)) * 0x18;
        }
        else {
          iVar4 = (uVar9 / 0x18) * -0x18;
        }
        plVar8 = (longlong *)(longlong)(int)(uVar9 + iVar4);
        *(char *)((longlong)param_2 + (longlong)plVar8 * 6 + 0xca4) = (char)param_2[0x113];
        *(undefined1 *)((longlong)param_2 + (longlong)plVar8 * 6 + 0xca5) =
             *(undefined1 *)((longlong)param_2 + 0x89c);
        *(short *)((longlong)param_2 + (longlong)plVar8 * 6 + 0xca6) = (short)param_2[0x115];
        *(undefined2 *)((longlong)param_2 + (longlong)plVar8 * 6 + 0xca8) = 0xd79;
        if (4 < DAT_140020050) {
          local_48 = param_2[0x152];
          lStack_40 = param_2[0x153];
          uVar11 = 0xd79;
          plVar10 = &local_48;
          plVar7 = &local_28;
          local_28 = param_2[0x154];
          lStack_20 = param_2[0x155];
LAB_14000e63a:
          plVar8 = &local_38;
          local_38 = param_2[0x150];
          lStack_30 = param_2[0x151];
          VmbusTraceInfoChannelStateChange
                    (plVar7,plVar8,plVar10,(ulonglong)*(ushort *)(param_2 + 0x192),
                     (int)param_2[0x113],*(int *)((longlong)param_2 + 0x89c),(int)param_2[0x115],
                     uVar11);
          if (4 < DAT_140020050) {
            plVar8 = (longlong *)0x4;
            cVar3 = _tlgKeywordOn(0x140020050,4);
            if (cVar3 != '\0') {
              plVar10 = (longlong *)((longlong)param_2 + 0x6ec);
              plVar8 = (longlong *)0xd91;
              VmbusTraceInfoRundownStart
                        ("KmclpWaitForActionWorkerRoutine",0xd91,plVar10,(short)param_2[0x192],
                         *(uint *)(param_2 + 0x113),*(int *)((longlong)param_2 + 0x89c),
                         *(uint *)(param_2 + 0x115));
            }
          }
        }
      }
      else {
        if (uVar9 != 4) goto LAB_14000e6f1;
        *(undefined4 *)((longlong)param_2 + 0x89c) = 4;
        LOCK();
        plVar8 = param_2 + 0x194;
        lVar2 = *plVar8;
        *(int *)plVar8 = (int)*plVar8 + 1;
        UNLOCK();
        uVar9 = (int)lVar2 + 1;
        uVar5 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar5 == 0) {
          iVar4 = (int)((ulonglong)((longlong)(int)uVar9 * -0x2aaaaaab) >> 0x20);
          iVar4 = ((iVar4 >> 2) - (iVar4 >> 0x1f)) * 0x18;
        }
        else {
          iVar4 = (uVar9 / 0x18) * -0x18;
        }
        plVar8 = (longlong *)(longlong)(int)(uVar9 + iVar4);
        *(char *)((longlong)param_2 + (longlong)plVar8 * 6 + 0xca4) = (char)param_2[0x113];
        *(undefined1 *)((longlong)param_2 + (longlong)plVar8 * 6 + 0xca5) =
             *(undefined1 *)((longlong)param_2 + 0x89c);
        *(short *)((longlong)param_2 + (longlong)plVar8 * 6 + 0xca6) = (short)param_2[0x115];
        *(undefined2 *)((longlong)param_2 + (longlong)plVar8 * 6 + 0xca8) = 0xd80;
        if (4 < DAT_140020050) {
          local_28 = param_2[0x152];
          lStack_20 = param_2[0x153];
          uVar11 = 0xd80;
          plVar10 = &local_28;
          plVar7 = &local_48;
          local_48 = param_2[0x154];
          lStack_40 = param_2[0x155];
          goto LAB_14000e63a;
        }
      }
      KmclpContinueChannelRundownAndUnlock(param_2,plVar8,plVar10);
      goto LAB_14000e701;
    }
  }
  else if ((iVar4 == 8) || (iVar4 == 10)) {
    if (-1 < (int)uVar1) {
      *(undefined1 *)((longlong)param_2 + 0xac5) = 1;
    }
    if (4 < DAT_140020050) {
      cVar3 = _tlgKeywordOn(0x140020050,4);
      if (cVar3 != '\0') {
        VmbusTraceInfoRundownEvent
                  ("KmclpWaitForActionWorkerRoutine",0xda9,(longlong)param_2 + 0x6ec,
                   (short)param_2[0x192],*(uint *)(param_2 + 0x113),
                   *(int *)((longlong)param_2 + 0x89c),(int)param_2[0x115],"Action IRP returned");
      }
    }
    KmclDecrementRundownCount((longlong)param_2,'\x01',0xdaa);
  }
  KmclUnlockChannel((longlong)param_2);
LAB_14000e701:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x61,
             &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_2);
  }
  return;
}



===== KmclpStartChannelAndUnlock @ 14000e754 =====

void KmclpStartChannelAndUnlock(longlong *param_1,undefined8 param_2,longlong *param_3)

{
  int iVar1;
  ulonglong uVar2;
  longlong lVar3;
  longlong *plVar4;
  uint uVar5;
  longlong local_38;
  longlong lStack_30;
  longlong local_28;
  longlong lStack_20;
  longlong local_18;
  longlong lStack_10;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_2 = 0x21;
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,param_3,param_1,(char)param_1[0x113]);
  }
  iVar1 = (int)param_1[0x113];
  if ((iVar1 != 0) && (iVar1 != 1)) {
    if (iVar1 == 3) {
      *(undefined4 *)(param_1 + 0x113) = 5;
      LOCK();
      plVar4 = param_1 + 0x194;
      lVar3 = *plVar4;
      *(int *)plVar4 = (int)*plVar4 + 1;
      UNLOCK();
      uVar5 = (int)lVar3 + 1;
      uVar2 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar2 == 0) {
        iVar1 = (int)((ulonglong)((longlong)(int)uVar5 * -0x2aaaaaab) >> 0x20);
        iVar1 = ((iVar1 >> 2) - (iVar1 >> 0x1f)) * 0x18;
      }
      else {
        iVar1 = (uVar5 / 0x18) * -0x18;
      }
      plVar4 = (longlong *)(longlong)(int)(uVar5 + iVar1);
      *(char *)((longlong)param_1 + (longlong)plVar4 * 6 + 0xca4) = (char)param_1[0x113];
      *(undefined1 *)((longlong)param_1 + (longlong)plVar4 * 6 + 0xca5) =
           *(undefined1 *)((longlong)param_1 + 0x89c);
      *(short *)((longlong)param_1 + (longlong)plVar4 * 6 + 0xca6) = (short)param_1[0x115];
      *(undefined2 *)((longlong)param_1 + (longlong)plVar4 * 6 + 0xca8) = 0x486;
      if (4 < DAT_140020050) {
        param_3 = &local_18;
        local_18 = param_1[0x152];
        lStack_10 = param_1[0x153];
        plVar4 = &local_28;
        local_28 = param_1[0x150];
        lStack_20 = param_1[0x151];
        local_38 = param_1[0x154];
        lStack_30 = param_1[0x155];
        VmbusTraceInfoChannelStateChange
                  (&local_38,plVar4,param_3,(ulonglong)*(ushort *)(param_1 + 0x192),
                   (int)param_1[0x113],*(undefined4 *)((longlong)param_1 + 0x89c),
                   (int)param_1[0x115],0x486);
      }
      KmclpStartWaitForAction((longlong)param_1,plVar4,param_3);
    }
    else {
      if (iVar1 == 4) {
        KmclpResumePausedChannelAndUnlock(param_1,param_2,param_3);
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
          return;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
          return;
        }
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
                 &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1);
        return;
      }
      if (((iVar1 != 5) && (iVar1 != 7)) &&
         ((iVar1 != 10 && ((iVar1 == 0xb && (*(int *)((longlong)param_1 + 0x89c) == 3)))))) {
        *(undefined4 *)((longlong)param_1 + 0x89c) = 2;
        LOCK();
        plVar4 = param_1 + 0x194;
        lVar3 = *plVar4;
        *(int *)plVar4 = (int)*plVar4 + 1;
        UNLOCK();
        uVar5 = (int)lVar3 + 1;
        uVar2 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar2 == 0) {
          iVar1 = (int)((ulonglong)((longlong)(int)uVar5 * -0x2aaaaaab) >> 0x20);
          iVar1 = ((iVar1 >> 2) - (iVar1 >> 0x1f)) * 0x18;
        }
        else {
          iVar1 = (uVar5 / 0x18) * -0x18;
        }
        lVar3 = (longlong)(int)(uVar5 + iVar1);
        *(char *)((longlong)param_1 + lVar3 * 6 + 0xca4) = (char)param_1[0x113];
        *(undefined1 *)((longlong)param_1 + lVar3 * 6 + 0xca5) =
             *(undefined1 *)((longlong)param_1 + 0x89c);
        *(short *)((longlong)param_1 + lVar3 * 6 + 0xca6) = (short)param_1[0x115];
        *(undefined2 *)((longlong)param_1 + lVar3 * 6 + 0xca8) = 0x467;
        if (4 < DAT_140020050) {
          param_3 = &local_38;
          local_38 = param_1[0x152];
          lStack_30 = param_1[0x153];
          local_28 = param_1[0x150];
          lStack_20 = param_1[0x151];
          local_18 = param_1[0x154];
          lStack_10 = param_1[0x155];
          VmbusTraceInfoChannelStateChange
                    (&local_18,&local_28,param_3,(ulonglong)*(ushort *)(param_1 + 0x192),
                     (int)param_1[0x113],*(undefined4 *)((longlong)param_1 + 0x89c),
                     (int)param_1[0x115],0x467);
        }
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,param_3,param_1,(char)param_1[0x113]);
  }
  KmclUnlockChannel((longlong)param_1);
  return;
}



===== KmclpGetTraceLogPacketDelayThreshold @ 14000ea98 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 KmclpGetTraceLogPacketDelayThreshold(void)

{
  short sVar1;
  int iVar2;
  wchar_t *pwVar3;
  longlong lVar4;
  undefined4 uVar5;
  undefined1 auStack_a8 [32];
  undefined4 local_88;
  undefined4 *local_80;
  undefined4 local_78 [2];
  undefined8 local_70;
  undefined8 local_68;
  wchar_t *pwStack_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  undefined *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined1 local_28 [4];
  int local_24;
  int local_20;
  undefined4 local_1c;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_a8;
  local_70 = 0;
  local_54 = 0;
  local_3c = 0;
  lVar4 = 0x7fff;
  uVar5 = 10;
  local_78[0] = 0;
  pwVar3 = L"TraceLogPacketDelayThresholdSec";
  local_68 = 0;
  pwStack_60 = (wchar_t *)0x0;
  do {
    if (*pwVar3 == L'\0') break;
    pwVar3 = pwVar3 + 1;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  if (lVar4 != 0) {
    pwStack_60 = L"TraceLogPacketDelayThresholdSec";
    sVar1 = (0x7fff - (short)lVar4) * 2;
    local_68 = (ulonglong)CONCAT22(sVar1 + 2,sVar1);
  }
  if ((int)-(uint)(lVar4 != 0) < 0) {
    local_58 = 0x30;
    local_48 = &KmclRegistryPath;
    local_50 = 0;
    local_40 = 0x240;
    local_38 = 0;
    uStack_30 = 0;
    iVar2 = ZwOpenKey(&local_70,0x20019,&local_58);
    if (-1 < iVar2) {
      local_80 = local_78;
      local_88 = 0x14;
      iVar2 = ZwQueryValueKey(local_70,&local_68,2,local_28);
      if ((-1 < iVar2) && (local_24 == 4)) {
        uVar5 = 10;
        if (local_20 == 4) {
          uVar5 = local_1c;
        }
      }
      ZwClose(local_70);
    }
  }
  return uVar5;
}



===== VmbChannelSetPointer @ 14000ec00 =====

void VmbChannelSetPointer(longlong param_1,undefined8 param_2)

{
                    /* 0xec00  74  VmbChannelSetPointer */
  *(undefined8 *)(param_1 + 0x900) = param_2;
  return;
}



===== KmclpStartWaitForAction @ 14000ec10 =====

void KmclpStartWaitForAction(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qLd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5e,param_3,param_1,
               (char)*(undefined4 *)(param_1 + 0x898),*(undefined1 *)(param_1 + 0xac5));
  }
  if (*(char *)(param_1 + 0xac5) == '\0') {
    lVar1 = *(longlong *)(param_1 + 0xab0);
    IoReuseIrp(lVar1,0x103);
    lVar2 = *(longlong *)(lVar1 + 0xb8);
    *(undefined4 *)(lVar2 + -0x38) = 0;
    *(undefined1 *)(lVar2 + -0x48) = 0xe;
    *(undefined4 *)(lVar2 + -0x30) = 0x3ec008;
    *(undefined4 *)(lVar2 + -0x40) = 4;
    *(undefined8 *)(lVar2 + -0x18) = *(undefined8 *)(param_1 + 0xa78);
    *(undefined8 *)(lVar2 + -0x20) = *(undefined8 *)(param_1 + 0xa70);
    *(undefined1 *)(lVar1 + 0x40) = 0;
    *(void **)(lVar1 + 0x98) = SystemReserved1[0xf];
    *(undefined8 *)(lVar1 + 0xc0) = *(undefined8 *)(lVar2 + -0x18);
    *(longlong *)(lVar1 + 0x18) = param_1 + 0xac0;
    *(longlong *)(lVar1 + 0x70) = param_1 + 0xac0;
    lVar3 = *(longlong *)(lVar1 + 0xb8);
    *(code **)(lVar3 + -0x10) = KmclpWaitForActionCompleted;
    *(longlong *)(lVar3 + -8) = param_1;
    *(undefined1 *)(lVar3 + -0x45) = 0xe0;
    IofCallDriver(*(undefined8 *)(lVar2 + -0x20),lVar1);
  }
  else {
    *(undefined1 *)(param_1 + 0xac5) = 0;
    IoQueueWorkItem(*(undefined8 *)(param_1 + 0xab8),KmclpWaitForActionWorkerRoutine,1,param_1);
  }
  *(undefined1 *)(param_1 + 0xac4) = 1;
  return;
}



===== VmbChannelGetClientStatsBuffer @ 14000ed60 =====

longlong VmbChannelGetClientStatsBuffer(longlong param_1)

{
                    /* 0xed60  15  VmbChannelGetClientStatsBuffer */
  return param_1 + 0x698;
}



===== VmbChannelSizeofPacket @ 14000ed70 =====

int VmbChannelSizeofPacket(longlong param_1)

{
                    /* 0xed70  78  VmbChannelSizeofPacket */
  return *(int *)(param_1 + 0x6c8) + 0xf0 + *(int *)(param_1 + 0x6d8);
}



===== KmclpTeardownOpenChannelState @ 14000ed8c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void KmclpTeardownOpenChannelState(longlong *param_1)

{
  if (*(char *)((longlong)param_1 + 0x6c1) == '\0') {
    PkUninitializeRingBuffer((longlong)(param_1 + 8));
    InCloseChannel(param_1);
  }
  if ((char)param_1[0xd8] != '\0') {
    ExAcquirePushLockExclusiveEx(param_1 + 0x159,0);
    *(undefined1 *)((longlong)param_1 + 0xac6) = 0;
    ExReleasePushLockExclusiveEx(param_1 + 0x159,0);
    if ((int)param_1[0x17b] != 0) {
      param_1[0x14c] = 0;
      (*(code *)param_1[0x12f])(param_1[0x122]);
      *(undefined4 *)(param_1 + 0x17b) = 0;
    }
    if ((*(byte *)(param_1 + 0x11f) & 0x10) != 0) {
      (*(code *)param_1[0x125])(param_1[0x122]);
      *(byte *)(param_1 + 0x11f) = *(byte *)(param_1 + 0x11f) & 0xef;
    }
  }
  return;
}



===== KmclpInitializeVmbusConnection @ 14000ee4c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int KmclpInitializeVmbusConnection(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  
  lVar2 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 0xa70) >> 8),
                                 *(undefined1 *)(*(longlong *)(param_1 + 0xa70) + 0x4c)),0);
  *(longlong *)(param_1 + 0xab0) = lVar2;
  if (lVar2 == 0) {
    iVar1 = -0x3fffff66;
  }
  else {
    (**(code **)(param_1 + 0x9e0))(*(undefined8 *)(param_1 + 0x910),0,0,param_1 + 0xaa0);
    iVar1 = KmclpEnablePerformanceCounters(param_1);
    if (-1 < iVar1) {
      iVar1 = 0;
    }
  }
  return iVar1;
}



===== VmbPacketFree @ 14000eed0 =====

void VmbPacketFree(longlong param_1)

{
  code *pcVar1;
  
                    /* 0xeed0  93  VmbPacketFree */
  if ((*(int *)(param_1 + 0x18) - 1U < 5) && (*(int *)(param_1 + 0x18) == 1)) {
    *(undefined4 *)(param_1 + 0x18) = 6;
    ExFreeToNPagedLookasideList(*(longlong *)(param_1 + 0x10) + 0x140);
    return;
  }
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(5);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== McGenEventWrite_EtwWriteTransfer @ 14000ef18 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_140020008;
  uVar2 = 0;
  if (DAT_140020008 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_140020008;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(VMBKMCLR_PROVIDER_Context,param_2,0,0,param_4,param_5);
  return;
}



===== KmclpClientOpenChannel @ 14000ef7c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong KmclpClientOpenChannel(longlong *param_1)

{
  int iVar1;
  longlong *plVar2;
  int iVar3;
  longlong lVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  ulonglong uVar8;
  undefined2 uVar9;
  longlong lVar10;
  longlong lVar11;
  ulonglong uVar12;
  undefined8 uVar13;
  undefined1 auStackY_208 [32];
  undefined4 local_1c8;
  undefined4 local_1c4;
  undefined8 local_1c0;
  longlong local_1b8;
  longlong lStack_1b0;
  longlong local_1a8;
  longlong lStack_1a0;
  longlong local_198;
  longlong lStack_190;
  longlong local_188;
  undefined8 uStack_180;
  undefined8 local_178;
  undefined8 uStack_170;
  longlong local_168;
  longlong lStack_160;
  longlong local_158;
  longlong lStack_150;
  int local_148;
  undefined1 local_142;
  longlong local_140;
  longlong local_138;
  longlong local_130;
  longlong lStack_128;
  longlong local_120;
  longlong lStack_118;
  longlong local_110;
  longlong lStack_108;
  longlong local_100;
  longlong lStack_f8;
  longlong local_f0;
  longlong lStack_e8;
  longlong local_e0;
  longlong lStack_d8;
  undefined4 local_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  longlong local_c0;
  undefined1 local_b8 [120];
  int local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_208;
  memset(local_b8,0,0x80);
  uVar13 = 0xb0;
  memset(&local_168,0,0xb0);
  local_1c0 = 0;
  local_1c4 = 0;
  local_1c8 = 0;
  local_188 = 0;
  uStack_180 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x34,uVar13,param_1,(char)param_1[0x113]);
  }
  local_178 = 0;
  uStack_170 = 0;
  uVar8 = KmclpSynchronousIoControl((longlong)param_1,0x3ec024,0,0,&local_168,0xb0);
  uVar12 = uVar8 & 0xffffffff;
  if ((int)uVar8 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      uVar9 = 0x36;
      uVar12 = uVar8 & 0xffffffff;
LAB_14000f5eb:
      WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,
                &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1,(char)uVar12);
    }
  }
  else {
    param_1[0x179] = local_140;
    param_1[0x17a] = local_138;
    param_1[0x150] = local_168;
    param_1[0x151] = lStack_160;
    param_1[0x152] = local_158;
    param_1[0x153] = lStack_150;
    if ((char)param_1[0x15b] != '\0') {
      *(undefined1 *)((longlong)param_1 + 0xad9) = local_142;
    }
    param_1[0xe4] = local_130;
    param_1[0xe5] = lStack_128;
    param_1[0xe6] = local_120;
    param_1[0xe7] = lStack_118;
    param_1[0xe8] = local_110;
    param_1[0xe9] = lStack_108;
    param_1[0xea] = local_100;
    param_1[0xeb] = lStack_f8;
    param_1[0xec] = local_f0;
    param_1[0xed] = lStack_e8;
    param_1[0xee] = local_e0;
    param_1[0xef] = lStack_d8;
    *(undefined4 *)(param_1 + 0xf0) = local_d0;
    *(undefined4 *)((longlong)param_1 + 0x784) = uStack_cc;
    *(undefined4 *)(param_1 + 0xf1) = uStack_c8;
    *(undefined4 *)((longlong)param_1 + 0x78c) = uStack_c4;
    param_1[0xf2] = local_c0;
    iVar7 = (int)param_1[0xf6];
    if ((int)param_1[0xf6] == -1) {
      *(int *)(param_1 + 0xf6) = local_148;
      iVar7 = local_148;
    }
    iVar5 = KeGetProcessorNumberFromIndex(iVar7,&local_1c8);
    if (-1 < iVar5) {
      uStack_180 = CONCAT62(uStack_180._2_6_,(undefined2)local_1c8);
      local_188 = 1L << (local_1c8._2_1_ & 0x3f);
      KeSetSystemGroupAffinityThread(&local_188,&local_178);
    }
    if ((*(char *)((longlong)param_1 + 0xad9) != '\0') &&
       (*(uint *)((longlong)param_1 + 0x7b4) != 0)) {
      uVar6 = KmclpAllocateBounceBlock
                        ((longlong)param_1,(ulonglong)*(uint *)((longlong)param_1 + 0x7b4),1);
      uVar12 = (ulonglong)uVar6;
      if ((int)uVar6 < 0) goto LAB_14000f5fe;
    }
    if (*(char *)((longlong)param_1 + 0x6c1) == '\0') {
      uVar8 = InOpenChannel(param_1);
      uVar12 = uVar8 & 0xffffffff;
      if ((int)uVar8 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar9 = 0x37;
          goto LAB_14000f5eb;
        }
        goto LAB_14000f5fe;
      }
    }
    uVar6 = KmclpInitializeVmbusConnection((longlong)param_1);
    uVar12 = (ulonglong)uVar6;
    if ((int)uVar6 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar9 = 0x38;
        goto LAB_14000f5eb;
      }
    }
    else {
      lVar11 = param_1[0xf5];
      iVar3 = *(int *)((longlong)param_1 + 0x7ac);
      iVar5 = (int)lVar11 + 1;
      iVar1 = iVar3 + 1;
      *(int *)(param_1 + 0x14d) = iVar5;
      *(int *)((longlong)param_1 + 0xa6c) = iVar1;
      local_1c0 = CONCAT44(iVar1,iVar5 + iVar1);
      uVar8 = KmclpSynchronousIoControl((longlong)param_1,0x3ec02e,&local_1c0,8,&local_1c4,4);
      uVar12 = uVar8 & 0xffffffff;
      if ((int)uVar8 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar9 = 0x39;
          goto LAB_14000f5eb;
        }
      }
      else {
        (*(code *)param_1[300])(param_1[0x122],local_1c4,param_1 + 0x14c);
        if (*(char *)((longlong)param_1 + 0x6c1) == '\0') {
          lVar4 = param_1[0x14c];
          lVar10 = (ulonglong)(uint)(iVar1 * 0x1000) + lVar4;
          uVar8 = PkInitializeRingBuffer
                            (param_1 + 8,lVar10,lVar10 + 0x1000,(int)lVar11,lVar4,lVar4 + 0x1000,
                             iVar3);
          uVar12 = uVar8 & 0xffffffff;
          if (-1 < (int)uVar8) {
            param_1[0x1b] = (longlong)(param_1 + 0x3d);
            goto LAB_14000f334;
          }
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar9 = 0x3a;
            goto LAB_14000f46d;
          }
        }
        else {
LAB_14000f334:
          ExAcquirePushLockExclusiveEx(param_1 + 0x159,0);
          *(undefined1 *)((longlong)param_1 + 0xac6) = 1;
          ExReleasePushLockExclusiveEx(param_1 + 0x159,0);
          local_3c = 1;
          if (*(char *)((longlong)param_1 + 0x7c2) != '\0') {
            local_3c = 3;
          }
          local_40 = iVar7;
          uVar8 = KmclpSynchronousIoControl((longlong)param_1,0x3ec034,local_b8,0x80,0,0);
          uVar12 = uVar8 & 0xffffffff;
          if ((int)uVar8 < 0) {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              uVar9 = 0x3b;
LAB_14000f46d:
              WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,
                        &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1,(char)uVar12);
            }
          }
          else {
            *(int *)((longlong)param_1 + 0xc8c) = iVar7;
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
               (3 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3c,
                       &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1);
            }
            if ((char)param_1[0xfd] == '\0') {
              uVar6 = (*(code *)param_1[0xff])(param_1);
            }
            else {
              uVar6 = (*(code *)param_1[0x100])(param_1,param_1[0xff]);
            }
            uVar12 = (ulonglong)uVar6;
            if (-1 < (int)uVar6) {
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                 (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3e,
                          &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1,(char)uVar6);
              }
              *(undefined4 *)(param_1 + 0x113) = 4;
              LOCK();
              plVar2 = param_1 + 0x194;
              lVar11 = *plVar2;
              *(int *)plVar2 = (int)*plVar2 + 1;
              UNLOCK();
              uVar6 = (int)lVar11 + 1;
              uVar8 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
              if ((int)uVar8 == 0) {
                iVar7 = (int)((ulonglong)((longlong)(int)uVar6 * -0x2aaaaaab) >> 0x20);
                iVar7 = ((iVar7 >> 2) - (iVar7 >> 0x1f)) * 0x18;
              }
              else {
                iVar7 = (uVar6 / 0x18) * -0x18;
              }
              lVar11 = (longlong)(int)(uVar6 + iVar7);
              *(char *)((longlong)param_1 + lVar11 * 6 + 0xca4) = (char)param_1[0x113];
              *(undefined1 *)((longlong)param_1 + lVar11 * 6 + 0xca5) =
                   *(undefined1 *)((longlong)param_1 + 0x89c);
              *(short *)((longlong)param_1 + lVar11 * 6 + 0xca6) = (short)param_1[0x115];
              *(undefined2 *)((longlong)param_1 + lVar11 * 6 + 0xca8) = 0x919;
              if (4 < DAT_140020050) {
                local_1b8 = param_1[0x152];
                lStack_1b0 = param_1[0x153];
                local_1a8 = param_1[0x150];
                lStack_1a0 = param_1[0x151];
                local_198 = param_1[0x154];
                lStack_190 = param_1[0x155];
                VmbusTraceInfoChannelStateChange
                          (&local_198,&local_1a8,&local_1b8,(ulonglong)*(ushort *)(param_1 + 0x192),
                           (int)param_1[0x113],*(undefined4 *)((longlong)param_1 + 0x89c),
                           (int)param_1[0x115],0x919);
              }
              uVar12 = 0;
              goto LAB_14000f60e;
            }
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              uVar9 = 0x3d;
              goto LAB_14000f46d;
            }
          }
        }
        KmclpClientCloseChannel((longlong)param_1);
      }
    }
  }
LAB_14000f5fe:
  KmclpTeardownOpenChannelState(param_1);
  KmclpDisableClosedChannel((longlong)param_1);
LAB_14000f60e:
  KeRevertToUserGroupAffinityThread(&local_178);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3f,
              &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1,(char)uVar12);
  }
  return uVar12;
}



===== KmclpRundownChannelStateAndUnlock @ 14000f688 =====

void KmclpRundownChannelStateAndUnlock(longlong param_1,char param_2,longlong *param_3)

{
  char cVar1;
  char *pcVar2;
  undefined7 in_register_00000011;
  longlong *plVar3;
  char *pcVar4;
  char *pcVar5;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  plVar3 = (longlong *)CONCAT71(in_register_00000011,param_2);
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    plVar3 = (longlong *)0x74;
    WPP_SF_qLLd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x74,param_3,param_1,
                (char)*(undefined4 *)(param_1 + 0x898),(char)*(undefined4 *)(param_1 + 0x89c),
                param_2);
  }
  pcVar5 = "Wait: false";
  pcVar4 = "Wait: true";
  if (5 < DAT_140020050) {
    plVar3 = (longlong *)0x4;
    cVar1 = _tlgKeywordOn(0x140020050,4);
    if (cVar1 != '\0') {
      param_3 = (longlong *)(param_1 + 0x6ec);
      plVar3 = (longlong *)0x107b;
      pcVar2 = "Wait: true";
      if (param_2 == '\0') {
        pcVar2 = pcVar5;
      }
      VmbusTraceVerbRundownFnStart
                ("KmclpRundownChannelStateAndUnlock",0x107b,param_3,*(undefined2 *)(param_1 + 0xc90)
                 ,*(uint *)(param_1 + 0x898),*(int *)(param_1 + 0x89c),
                 *(undefined4 *)(param_1 + 0x8a8),pcVar2);
    }
  }
  if (param_2 == '\0') {
    *(byte *)(param_1 + 0x8f8) = *(byte *)(param_1 + 0x8f8) | 0x40;
  }
  else {
    param_3 = (longlong *)0x0;
    plVar3 = (longlong *)0x1;
    KeInitializeEvent(&local_38);
    uStack_20 = *(undefined8 *)(param_1 + 0x8a0);
    *(undefined8 **)(param_1 + 0x8a0) = &local_38;
  }
  if (*(int *)(param_1 + 0x898) - 8U < 4) {
    KmclUnlockChannel(param_1);
  }
  else {
    if (4 < DAT_140020050) {
      plVar3 = (longlong *)0x4;
      cVar1 = _tlgKeywordOn(0x140020050,4);
      if (cVar1 != '\0') {
        param_3 = (longlong *)(param_1 + 0x6ec);
        plVar3 = (longlong *)0x1097;
        VmbusTraceInfoRundownStart
                  ("KmclpRundownChannelStateAndUnlock",0x1097,param_3,
                   *(undefined2 *)(param_1 + 0xc90),*(uint *)(param_1 + 0x898),
                   *(int *)(param_1 + 0x89c),*(uint *)(param_1 + 0x8a8));
      }
    }
    KmclpContinueChannelRundownAndUnlock((longlong *)param_1,plVar3,param_3);
  }
  if (param_2 != '\0') {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x75,
               &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1);
    }
    if (4 < DAT_140020050) {
      cVar1 = _tlgKeywordOn(0x140020050,4);
      if (cVar1 != '\0') {
        VmbusTraceInfoRundownEvent
                  ("KmclpRundownChannelStateAndUnlock",0x10a8,param_1 + 0x6ec,
                   *(undefined2 *)(param_1 + 0xc90),*(uint *)(param_1 + 0x898),
                   *(int *)(param_1 + 0x89c),*(undefined4 *)(param_1 + 0x8a8),
                   "Waiting for SuspendDoneEvent");
      }
    }
    KeWaitForSingleObject(&local_38,0,0,0,0);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x76,
               &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1);
    }
    if (4 < DAT_140020050) {
      cVar1 = _tlgKeywordOn(0x140020050,4);
      if (cVar1 != '\0') {
        VmbusTraceInfoRundownEvent
                  ("KmclpRundownChannelStateAndUnlock",0x10b2,param_1 + 0x6ec,
                   *(undefined2 *)(param_1 + 0xc90),*(uint *)(param_1 + 0x898),
                   *(int *)(param_1 + 0x89c),*(undefined4 *)(param_1 + 0x8a8),
                   "SuspendDoneEvent wait complete");
      }
    }
  }
  if (5 < DAT_140020050) {
    cVar1 = _tlgKeywordOn(0x140020050,4);
    if (cVar1 != '\0') {
      if (param_2 == '\0') {
        pcVar4 = "Wait: false";
      }
      VmbusTraceVerbRundownFnStop
                ("KmclpRundownChannelStateAndUnlock",0x10b5,param_1 + 0x6ec,
                 *(undefined2 *)(param_1 + 0xc90),*(uint *)(param_1 + 0x898),
                 *(int *)(param_1 + 0x89c),*(undefined4 *)(param_1 + 0x8a8),pcVar4);
    }
  }
  return;
}



===== RtlUnicodeStringPrintf @ 14000fa00 =====

undefined8
RtlUnicodeStringPrintf(ushort *param_1,wchar_t *param_2,undefined8 param_3,undefined8 param_4)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  ulonglong _Count;
  undefined8 local_res18;
  undefined8 local_res20;
  
  uVar1 = *param_1;
  if ((((((uVar1 & 1) == 0) && (uVar2 = param_1[1], (uVar2 & 1) == 0)) && (uVar1 <= uVar2)) &&
      (uVar2 != 0xffff)) &&
     ((uVar5 = 0, *(longlong *)(param_1 + 4) != 0 || ((uVar1 == 0 && (uVar2 == 0)))))) {
    _Count = (ulonglong)(param_1[1] >> 1);
    local_res18 = param_3;
    local_res20 = param_4;
    iVar3 = _vsnwprintf(*(wchar_t **)(param_1 + 4),_Count,param_2,(va_list)&local_res18);
    if ((iVar3 < 0) || (uVar4 = (longlong)iVar3, _Count < (ulonglong)(longlong)iVar3)) {
      uVar5 = 0x80000005;
      uVar4 = _Count;
    }
    *param_1 = (short)uVar4 * 2;
  }
  else {
    uVar5 = 0xc000000d;
  }
  return uVar5;
}



===== KmclpFreeAllBounceBlocks @ 14000faa0 =====

void KmclpFreeAllBounceBlocks(longlong param_1)

{
  longlong ****pppplVar1;
  longlong ****pppplVar2;
  longlong ***ppplVar3;
  code *pcVar4;
  undefined1 uVar5;
  longlong ****local_18;
  longlong ****local_10;
  
  local_10 = (longlong ****)&local_18;
  local_18 = (longlong ****)&local_18;
  uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x100);
  pppplVar1 = (longlong ****)(param_1 + 0xae0);
  while (pppplVar2 = (longlong ****)*pppplVar1, pppplVar2 != pppplVar1) {
    if (((longlong ****)pppplVar2[1] != pppplVar1) ||
       (ppplVar3 = *pppplVar2, (longlong ****)ppplVar3[1] != pppplVar2)) goto LAB_14000fb6c;
    *pppplVar1 = ppplVar3;
    ppplVar3[1] = (longlong **)pppplVar1;
    if ((longlong *****)*local_10 != &local_18) goto LAB_14000fb6c;
    pppplVar2[1] = (longlong ***)local_10;
    *pppplVar2 = (longlong ***)&local_18;
    *local_10 = (longlong ***)pppplVar2;
    local_10 = pppplVar2;
  }
  KeReleaseSpinLock(param_1 + 0x100,CONCAT71((int7)((ulonglong)pppplVar1 >> 8),uVar5));
  while( true ) {
    pppplVar1 = local_18;
    if ((longlong *****)local_18 == &local_18) {
      return;
    }
    if (((longlong *****)local_18[1] != &local_18) ||
       (pppplVar2 = (longlong ****)*local_18, (longlong ****)pppplVar2[1] != local_18)) break;
    pppplVar2[1] = (longlong ***)&local_18;
    local_18 = pppplVar2;
    KmclpFreeBounceBlock(param_1,(longlong)pppplVar1);
  }
LAB_14000fb6c:
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  return;
}



===== KmclInitializeChannelParentDevice @ 14000fb8c =====

uint KmclInitializeChannelParentDevice(longlong param_1,undefined8 param_2)

{
  uint uVar1;
  longlong lVar2;
  
  *(undefined8 *)(param_1 + 0xc80) = param_2;
  ObfReferenceObject(param_2);
  lVar2 = IoAllocateWorkItem(*(undefined8 *)(param_1 + 0xc80));
  *(longlong *)(param_1 + 0x8b0) = lVar2;
  if (lVar2 == 0) {
    uVar1 = 0xc000009a;
  }
  else {
    lVar2 = IoAllocateWorkItem();
    *(longlong *)(param_1 + 0xab8) = lVar2;
    uVar1 = ~-(uint)(lVar2 != 0) & 0xc000009a;
  }
  return uVar1;
}



===== KmclChannelCleanupParentDevice @ 14000fc08 =====

void KmclChannelCleanupParentDevice(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x8b0) != 0) {
    IoFreeWorkItem();
    *(undefined8 *)(param_1 + 0x8b0) = 0;
  }
  if (*(longlong *)(param_1 + 0xab8) != 0) {
    IoFreeWorkItem();
    *(undefined8 *)(param_1 + 0xab8) = 0;
  }
  if (*(longlong *)(param_1 + 0xc80) != 0) {
    ObfDereferenceObject();
    *(undefined8 *)(param_1 + 0xc80) = 0;
  }
  return;
}



===== OutpEnqueuePollingDpc @ 14000fc80 =====

void OutpEnqueuePollingDpc(longlong param_1)

{
  char cVar1;
  
  cVar1 = KeInsertQueueDpc(param_1 + 0x3c8,0,0);
  if (cVar1 != '\0') {
    *(int *)(param_1 + 0x408) = *(int *)(param_1 + 0x408) + 1;
  }
  return;
}



===== VmbChannelSetAllowableDpcCpuUsage @ 14000fcc0 =====

void VmbChannelSetAllowableDpcCpuUsage(longlong param_1,byte param_2)

{
  undefined1 auVar1 [16];
  longlong lVar2;
  ulonglong uVar3;
  
                    /* 0xfcc0  69  VmbChannelSetAllowableDpcCpuUsage */
  if (param_2 < 100) {
    uVar3 = (ulonglong)param_2 * 0x10 * KmclTscTicksPerNtTick;
    auVar1._8_8_ = 0;
    auVar1._0_8_ = uVar3;
    lVar2 = SUB168(ZEXT816(0x47ae147ae147ae15) * auVar1,8);
    uVar3 = (uVar3 - lVar2 >> 1) + lVar2 >> 6;
  }
  else {
    uVar3 = 0xffffffffffffffff;
  }
  *(ulonglong *)(param_1 + 0x5d0) = uVar3;
  return;
}



===== _guard_check_icall @ 14000fd10 =====

void _guard_check_icall(void)

{
  return;
}



===== __report_gsfailure @ 14000fd30 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 14000fd3d =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000fd3d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== VmbusTraceError @ 14000fd50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void VmbusTraceError(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 auStackY_a8 [32];
  undefined4 local_78;
  undefined4 local_74 [3];
  undefined8 local_68 [4];
  longlong local_48 [2];
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  if (2 < DAT_140020050) {
    _tlgCreate1Sz_char(local_48,"OutSendPacket");
    local_2c = 0;
    local_38 = &local_78;
    local_1c = 0;
    local_28 = local_74;
    local_30 = 4;
    local_20 = 4;
    local_78 = 0x66a;
    local_74[0] = 0xc0000010;
    _tlgWriteTransfer_EtwWriteTransfer(0x140020050,&DAT_14001d741,param_3,param_4,5,local_68);
  }
  return;
}



===== VmbusTraceErrorQueue @ 14000fdf8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void VmbusTraceErrorQueue
               (char *param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
               undefined4 param_5)

{
  undefined2 uVar1;
  undefined6 uVar2;
  undefined1 auStackY_c8 [32];
  undefined2 local_98 [2];
  undefined4 local_94;
  undefined4 local_90 [2];
  undefined8 local_88 [4];
  longlong local_68 [2];
  undefined4 *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined2 *local_38;
  undefined8 local_30;
  undefined4 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  uVar1 = (undefined2)param_4;
  uVar2 = (undefined6)((ulonglong)param_4 >> 0x10);
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  if (2 < DAT_140020050) {
    _tlgCreate1Sz_char(local_68,param_1);
    local_58 = &local_94;
    local_38 = local_98;
    local_50 = 4;
    local_90[0] = param_5;
    local_28 = local_90;
    local_40 = 0x10;
    local_30 = 2;
    local_20 = 4;
    local_98[0] = uVar1;
    local_94 = param_2;
    local_48 = param_3;
    _tlgWriteTransfer_EtwWriteTransfer
              (0x140020050,&DAT_14001d947,param_3,CONCAT62(uVar2,uVar1),7,local_88);
  }
  return;
}



===== VmbusTraceErrorQueueFailed @ 14000feb8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void VmbusTraceErrorQueueFailed
               (char *param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,char *param_5
               ,char *param_6)

{
  undefined2 uVar1;
  undefined6 uVar2;
  undefined1 auStackY_d8 [32];
  undefined2 local_a8 [2];
  undefined4 local_a4 [3];
  undefined8 local_98 [4];
  longlong local_78 [2];
  undefined4 *local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined2 *local_48;
  undefined8 local_40;
  longlong local_38 [2];
  longlong local_28 [2];
  ulonglong local_18;
  
  uVar1 = (undefined2)param_4;
  uVar2 = (undefined6)((ulonglong)param_4 >> 0x10);
  local_18 = __security_cookie ^ (ulonglong)auStackY_d8;
  if (2 < DAT_140020050) {
    _tlgCreate1Sz_char(local_78,param_1);
    local_68 = local_a4;
    local_48 = local_a8;
    local_60 = 4;
    local_50 = 0x10;
    local_40 = 2;
    local_a8[0] = uVar1;
    local_a4[0] = param_2;
    local_58 = param_3;
    _tlgCreate1Sz_char(local_38,param_5);
    _tlgCreate1Sz_char(local_28,param_6);
    _tlgWriteTransfer_EtwWriteTransfer
              (0x140020050,&DAT_14001d5eb,param_3,CONCAT62(uVar2,uVar1),8,local_98);
  }
  return;
}



===== VmbusTraceErrorQueueFailedStatus @ 14000ff90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void VmbusTraceErrorQueueFailedStatus
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined4 param_5)

{
  undefined2 uVar1;
  undefined6 uVar2;
  undefined1 auStackY_c8 [32];
  undefined2 local_98 [2];
  undefined4 local_94;
  undefined4 local_90 [2];
  undefined8 local_88 [4];
  longlong local_68 [2];
  undefined4 *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined2 *local_38;
  undefined8 local_30;
  undefined4 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  uVar1 = (undefined2)param_4;
  uVar2 = (undefined6)((ulonglong)param_4 >> 0x10);
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  if (2 < DAT_140020050) {
    _tlgCreate1Sz_char(local_68,"OutpProcessRingResult");
    local_58 = &local_94;
    local_94 = 0x2d0;
    local_38 = local_98;
    local_50 = 4;
    local_90[0] = param_5;
    local_28 = local_90;
    local_40 = 0x10;
    local_30 = 2;
    local_20 = 4;
    local_98[0] = uVar1;
    local_48 = param_3;
    _tlgWriteTransfer_EtwWriteTransfer
              (0x140020050,&DAT_14001d491,param_3,CONCAT62(uVar2,uVar1),7,local_88);
  }
  return;
}



===== VmbusTraceInfoChannelStateChange @ 140010058 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void VmbusTraceInfoChannelStateChange
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined1 auStackY_108 [32];
  undefined2 local_d8 [2];
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8 [4];
  undefined8 local_b8 [4];
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined2 *local_68;
  undefined8 local_60;
  undefined4 *local_58;
  undefined8 local_50;
  undefined4 *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  undefined4 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_d8[0] = (undefined2)param_4;
  local_18 = __security_cookie ^ (ulonglong)auStackY_108;
  if (4 < DAT_140020050) {
    local_68 = local_d8;
    local_d4 = param_5;
    local_58 = &local_d4;
    local_d0 = param_6;
    local_48 = &local_d0;
    local_cc = param_7;
    local_38 = &local_cc;
    local_c8[0] = param_8;
    local_28 = local_c8;
    local_90 = 0x10;
    local_80 = 0x10;
    local_70 = 0x10;
    local_60 = 2;
    local_50 = 4;
    local_40 = 4;
    local_30 = 4;
    local_20 = 4;
    local_98 = param_1;
    local_88 = param_2;
    local_78 = param_3;
    _tlgWriteTransfer_EtwWriteTransfer(0x140020050,&DAT_14001d557,param_3,param_4,10,local_b8);
  }
  return;
}



===== VmbusTraceInfoQuotaExceeded @ 140010154 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void VmbusTraceInfoQuotaExceeded
               (char *param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,char param_5)

{
  char cVar1;
  char *pcVar2;
  char cVar3;
  undefined2 uVar4;
  undefined6 uVar5;
  undefined1 auStackY_c8 [32];
  undefined2 local_98 [2];
  undefined4 local_94 [3];
  undefined1 local_88 [32];
  longlong local_68 [2];
  undefined4 *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined2 *local_38;
  undefined8 local_30;
  longlong local_28 [2];
  ulonglong local_18;
  
  uVar4 = (undefined2)param_4;
  uVar5 = (undefined6)((ulonglong)param_4 >> 0x10);
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  if (4 < DAT_140020050) {
    cVar1 = _tlgKeywordOn(0x140020050,2);
    cVar3 = '\0';
    if (cVar1 != '\0') {
      _tlgCreate1Sz_char(local_68,param_1);
      local_58 = local_94;
      pcVar2 = "Pause";
      local_38 = local_98;
      local_50 = 4;
      if (param_5 == cVar3) {
        pcVar2 = "Resume";
      }
      local_40 = 0x10;
      local_30 = 2;
      local_98[0] = uVar4;
      local_94[0] = param_2;
      local_48 = param_3;
      _tlgCreate1Sz_char(local_28,pcVar2);
      _tlgWriteTransfer_EtwWriteTransfer
                (0x140020050,&DAT_14001dc01,local_88,CONCAT62(uVar5,uVar4),7,(undefined8 *)local_88)
      ;
    }
  }
  return;
}



===== VmbusTraceInfoRundownEvent @ 140010250 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void VmbusTraceInfoRundownEvent
               (char *param_1,undefined4 param_2,undefined8 param_3,undefined2 param_4,uint param_5,
               int param_6,undefined4 param_7,char *param_8)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  undefined1 auStackY_108 [32];
  undefined2 local_d8 [2];
  undefined4 local_d4;
  undefined4 local_d0 [2];
  undefined1 local_c8 [32];
  longlong local_a8 [2];
  undefined4 *local_98;
  undefined4 local_90;
  undefined4 local_8c;
  undefined8 local_88;
  undefined4 local_80;
  undefined4 local_7c;
  undefined2 *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  longlong local_68 [2];
  longlong local_58 [2];
  undefined4 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_108;
  if (param_5 < 7) {
    if (param_5 == 6) {
      pcVar2 = "ChannelResuming";
      goto LAB_14001034f;
    }
    if (param_5 == 0) {
      pcVar2 = "ChannelDisabled";
      goto LAB_14001034f;
    }
    if (param_5 == 1) {
      pcVar2 = "ChannelEnablingWaitingForVmbus";
      goto LAB_14001034f;
    }
    if (param_5 == 2) {
      pcVar2 = "ChannelCancellingEnable";
      goto LAB_14001034f;
    }
    if (param_5 == 3) {
      pcVar2 = "ChannelPausedClosed";
      goto LAB_14001034f;
    }
    if (param_5 == 4) {
      pcVar2 = "ChannelPausedOpen";
      goto LAB_14001034f;
    }
    if (param_5 == 5) {
      pcVar2 = "ChannelRunningClosed";
      goto LAB_14001034f;
    }
  }
  else {
    if (param_5 == 7) {
      pcVar2 = "ChannelRunningOpen";
      goto LAB_14001034f;
    }
    if (param_5 == 8) {
      pcVar2 = "ChannelPausingClosed";
      goto LAB_14001034f;
    }
    if (param_5 == 9) {
      pcVar2 = "ChannelPausingWhileResuming";
      goto LAB_14001034f;
    }
    if (param_5 == 10) {
      pcVar2 = "ChannelPausingOpenWaitingForPackets";
      goto LAB_14001034f;
    }
    if (param_5 == 0xb) {
      pcVar2 = "ChannelClosing";
      goto LAB_14001034f;
    }
    if (param_5 == 0xc) {
      pcVar2 = "ChannelPausedServicing";
      goto LAB_14001034f;
    }
  }
  pcVar2 = "ChannelStateUnknown";
LAB_14001034f:
  if (param_6 == 0) {
    pcVar3 = "ChannelNotRunningDown";
  }
  else if (param_6 == 1) {
    pcVar3 = "ChannelRundownPausing";
  }
  else if (param_6 == 2) {
    pcVar3 = "ChannelRundownClosing";
  }
  else if (param_6 == 3) {
    pcVar3 = "ChannelRundownClosingAndPausing";
  }
  else if (param_6 == 4) {
    pcVar3 = "ChannelRundownDisabling";
  }
  else {
    pcVar3 = "ChannelRundownReasonUnknown";
  }
  if (4 < DAT_140020050) {
    cVar1 = _tlgKeywordOn(0x140020050,4);
    if (cVar1 != '\0') {
      _tlgCreate1Sz_char(local_a8,param_1);
      local_8c = 0;
      local_98 = &local_d4;
      local_7c = 0;
      local_6c = 0;
      local_78 = local_d8;
      local_90 = 4;
      local_80 = 0x10;
      local_70 = 2;
      local_d8[0] = param_4;
      local_d4 = param_2;
      local_88 = param_3;
      _tlgCreate1Sz_char(local_68,pcVar2);
      _tlgCreate1Sz_char(local_58,pcVar3);
      local_48 = local_d0;
      local_3c = 0;
      local_d0[0] = param_7;
      local_40 = 4;
      _tlgCreate1Sz_char(local_38,param_8);
      _tlgWriteTransfer_EtwWriteTransfer
                (0x140020050,&DAT_14001d8c4,local_c8,pcVar2,10,(undefined8 *)local_c8);
    }
  }
  return;
}



===== VmbusTraceInfoRundownStart @ 1400104a4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void VmbusTraceInfoRundownStart
               (char *param_1,undefined4 param_2,undefined8 param_3,undefined2 param_4,uint param_5,
               int param_6,uint param_7)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  undefined1 auStackY_e8 [32];
  undefined2 local_b8 [2];
  undefined4 local_b4;
  uint local_b0 [2];
  undefined8 local_a8 [4];
  longlong local_88 [2];
  undefined4 *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined8 local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined2 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong local_48 [2];
  longlong local_38 [2];
  uint *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_e8;
  if (param_5 < 7) {
    if (param_5 == 6) {
      pcVar2 = "ChannelResuming";
      goto LAB_1400105a0;
    }
    if (param_5 == 0) {
      pcVar2 = "ChannelDisabled";
      goto LAB_1400105a0;
    }
    if (param_5 == 1) {
      pcVar2 = "ChannelEnablingWaitingForVmbus";
      goto LAB_1400105a0;
    }
    if (param_5 == 2) {
      pcVar2 = "ChannelCancellingEnable";
      goto LAB_1400105a0;
    }
    if (param_5 == 3) {
      pcVar2 = "ChannelPausedClosed";
      goto LAB_1400105a0;
    }
    if (param_5 == 4) {
      pcVar2 = "ChannelPausedOpen";
      goto LAB_1400105a0;
    }
    if (param_5 == 5) {
      pcVar2 = "ChannelRunningClosed";
      goto LAB_1400105a0;
    }
  }
  else {
    if (param_5 == 7) {
      pcVar2 = "ChannelRunningOpen";
      goto LAB_1400105a0;
    }
    if (param_5 == 8) {
      pcVar2 = "ChannelPausingClosed";
      goto LAB_1400105a0;
    }
    if (param_5 == 9) {
      pcVar2 = "ChannelPausingWhileResuming";
      goto LAB_1400105a0;
    }
    if (param_5 == 10) {
      pcVar2 = "ChannelPausingOpenWaitingForPackets";
      goto LAB_1400105a0;
    }
    if (param_5 == 0xb) {
      pcVar2 = "ChannelClosing";
      goto LAB_1400105a0;
    }
    if (param_5 == 0xc) {
      pcVar2 = "ChannelPausedServicing";
      goto LAB_1400105a0;
    }
  }
  pcVar2 = "ChannelStateUnknown";
LAB_1400105a0:
  if (param_6 == 0) {
    pcVar3 = "ChannelNotRunningDown";
  }
  else if (param_6 == 1) {
    pcVar3 = "ChannelRundownPausing";
  }
  else if (param_6 == 2) {
    pcVar3 = "ChannelRundownClosing";
  }
  else if (param_6 == 3) {
    pcVar3 = "ChannelRundownClosingAndPausing";
  }
  else if (param_6 == 4) {
    pcVar3 = "ChannelRundownDisabling";
  }
  else {
    pcVar3 = "ChannelRundownReasonUnknown";
  }
  if (4 < DAT_140020050) {
    cVar1 = _tlgKeywordOn(0x140020050,4);
    if (cVar1 != '\0') {
      _tlgCreate1Sz_char(local_88,param_1);
      local_6c = 0;
      local_78 = &local_b4;
      local_5c = 0;
      local_4c = 0;
      local_58 = local_b8;
      local_70 = 4;
      local_60 = 0x10;
      local_50 = 2;
      local_b8[0] = param_4;
      local_b4 = param_2;
      local_68 = param_3;
      _tlgCreate1Sz_char(local_48,pcVar2);
      _tlgCreate1Sz_char(local_38,pcVar3);
      local_28 = local_b0;
      local_1c = 0;
      local_b0[0] = param_7;
      local_20 = 4;
      _tlgWriteTransfer_EtwWriteTransfer
                (0x140020050,&DAT_14001da19,(ulonglong)param_7,pcVar2,9,local_a8);
    }
  }
  return;
}



===== VmbusTraceInfoRundownStop @ 1400106e4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void VmbusTraceInfoRundownStop
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               uint param_5,int param_6,uint param_7)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  undefined1 auStackY_e8 [32];
  undefined2 local_b8 [2];
  undefined4 local_b4;
  uint local_b0 [2];
  undefined8 local_a8 [4];
  longlong local_88 [2];
  undefined4 *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined8 local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined2 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong local_48 [2];
  longlong local_38 [2];
  uint *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_e8;
  if (param_5 < 7) {
    if (param_5 == 6) {
      pcVar2 = "ChannelResuming";
      goto LAB_1400107d2;
    }
    if (param_5 == 0) {
      pcVar2 = "ChannelDisabled";
      goto LAB_1400107d2;
    }
    if (param_5 == 1) {
      pcVar2 = "ChannelEnablingWaitingForVmbus";
      goto LAB_1400107d2;
    }
    if (param_5 == 2) {
      pcVar2 = "ChannelCancellingEnable";
      goto LAB_1400107d2;
    }
    if (param_5 == 3) {
      pcVar2 = "ChannelPausedClosed";
      goto LAB_1400107d2;
    }
    if (param_5 == 4) {
      pcVar2 = "ChannelPausedOpen";
      goto LAB_1400107d2;
    }
    if (param_5 == 5) {
      pcVar2 = "ChannelRunningClosed";
      goto LAB_1400107d2;
    }
  }
  else {
    if (param_5 == 7) {
      pcVar2 = "ChannelRunningOpen";
      goto LAB_1400107d2;
    }
    if (param_5 == 8) {
      pcVar2 = "ChannelPausingClosed";
      goto LAB_1400107d2;
    }
    if (param_5 == 9) {
      pcVar2 = "ChannelPausingWhileResuming";
      goto LAB_1400107d2;
    }
    if (param_5 == 10) {
      pcVar2 = "ChannelPausingOpenWaitingForPackets";
      goto LAB_1400107d2;
    }
    if (param_5 == 0xb) {
      pcVar2 = "ChannelClosing";
      goto LAB_1400107d2;
    }
    if (param_5 == 0xc) {
      pcVar2 = "ChannelPausedServicing";
      goto LAB_1400107d2;
    }
  }
  pcVar2 = "ChannelStateUnknown";
LAB_1400107d2:
  if (param_6 == 0) {
    pcVar3 = "ChannelNotRunningDown";
  }
  else if (param_6 == 1) {
    pcVar3 = "ChannelRundownPausing";
  }
  else if (param_6 == 2) {
    pcVar3 = "ChannelRundownClosing";
  }
  else if (param_6 == 3) {
    pcVar3 = "ChannelRundownClosingAndPausing";
  }
  else if (param_6 == 4) {
    pcVar3 = "ChannelRundownDisabling";
  }
  else {
    pcVar3 = "ChannelRundownReasonUnknown";
  }
  if (4 < DAT_140020050) {
    cVar1 = _tlgKeywordOn(0x140020050,4);
    if (cVar1 != '\0') {
      _tlgCreate1Sz_char(local_88,"KmclpFinishSuspendProcessAndUnlock");
      local_6c = 0;
      local_78 = &local_b4;
      local_5c = 0;
      local_4c = 0;
      local_58 = local_b8;
      local_b4 = 0x1123;
      local_70 = 4;
      local_60 = 0x10;
      local_50 = 2;
      local_b8[0] = param_4;
      local_68 = param_3;
      _tlgCreate1Sz_char(local_48,pcVar2);
      _tlgCreate1Sz_char(local_38,pcVar3);
      local_28 = local_b0;
      local_1c = 0;
      local_b0[0] = param_7;
      local_20 = 4;
      _tlgWriteTransfer_EtwWriteTransfer
                (0x140020050,&DAT_14001d770,(ulonglong)param_7,pcVar2,9,local_a8);
    }
  }
  return;
}



===== VmbusTraceVerbInterruptMaskSet @ 140010914 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void VmbusTraceVerbInterruptMaskSet
               (char *param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,char param_5)

{
  char cVar1;
  char *pcVar2;
  char cVar3;
  undefined2 uVar4;
  undefined6 uVar5;
  undefined1 auStackY_c8 [32];
  undefined2 local_98 [2];
  undefined4 local_94 [3];
  undefined1 local_88 [32];
  longlong local_68 [2];
  undefined4 *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined2 *local_38;
  undefined8 local_30;
  longlong local_28 [2];
  ulonglong local_18;
  
  uVar4 = (undefined2)param_4;
  uVar5 = (undefined6)((ulonglong)param_4 >> 0x10);
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  if (5 < DAT_140020050) {
    cVar1 = _tlgKeywordOn(0x140020050,1);
    cVar3 = '\0';
    if (cVar1 != '\0') {
      _tlgCreate1Sz_char(local_68,param_1);
      local_58 = local_94;
      pcVar2 = "Enabled";
      local_38 = local_98;
      local_50 = 4;
      if (param_5 == cVar3) {
        pcVar2 = "Disabled";
      }
      local_40 = 0x10;
      local_30 = 2;
      local_98[0] = uVar4;
      local_94[0] = param_2;
      local_48 = param_3;
      _tlgCreate1Sz_char(local_28,pcVar2);
      _tlgWriteTransfer_EtwWriteTransfer
                (0x140020050,&DAT_14001d655,local_88,CONCAT62(uVar5,uVar4),7,(undefined8 *)local_88)
      ;
    }
  }
  return;
}



===== VmbusTraceVerbPacketFetch @ 140010a10 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void VmbusTraceVerbPacketFetch
               (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,char param_6)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  ulonglong uVar4;
  undefined1 auStackY_d8 [32];
  undefined2 local_a8 [2];
  undefined4 local_a4;
  undefined8 local_a0;
  undefined1 local_98 [32];
  longlong local_78 [2];
  undefined4 *local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined2 *local_48;
  undefined8 local_40;
  undefined8 *local_38;
  ulonglong local_30;
  longlong local_28 [2];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_d8;
  if (5 < DAT_140020050) {
    cVar1 = _tlgKeywordOn(0x140020050,1);
    iVar3 = 0;
    if (cVar1 != '\0') {
      _tlgCreate1Sz_char(local_78,"InpBatchProcessAndEnqueue");
      local_68 = &local_a4;
      pcVar2 = "Yes";
      local_48 = local_a8;
      uVar4 = (ulonglong)(iVar3 + 8);
      local_a0 = param_5;
      local_38 = &local_a0;
      if (param_6 == (char)iVar3) {
        pcVar2 = "No";
      }
      local_60 = 4;
      local_50 = 0x10;
      local_40 = 2;
      local_a8[0] = param_4;
      local_a4 = param_2;
      local_58 = param_3;
      local_30 = uVar4;
      _tlgCreate1Sz_char(local_28,pcVar2);
      _tlgWriteTransfer_EtwWriteTransfer
                (0x140020050,&DAT_14001d9ac,local_98,uVar4,(int)uVar4,(undefined8 *)local_98);
    }
  }
  return;
}



===== VmbusTraceVerbPacketFetchStart @ 140010b14 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void VmbusTraceVerbPacketFetchStart
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               short param_5)

{
  char cVar1;
  char *pcVar2;
  undefined2 uVar3;
  undefined6 uVar4;
  undefined1 auStackY_c8 [32];
  undefined2 local_98 [2];
  undefined4 local_94 [3];
  undefined1 local_88 [32];
  longlong local_68 [2];
  undefined4 *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined2 *local_38;
  undefined8 local_30;
  longlong local_28 [2];
  ulonglong local_18;
  
  uVar3 = (undefined2)param_4;
  uVar4 = (undefined6)((ulonglong)param_4 >> 0x10);
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  if (5 < DAT_140020050) {
    cVar1 = _tlgKeywordOn(0x140020050,1);
    if (cVar1 != '\0') {
      _tlgCreate1Sz_char(local_68,"InpFillAndProcessQueue");
      local_58 = local_94;
      local_94[0] = 0xae2;
      pcVar2 = "DISPATCH";
      local_38 = local_98;
      local_50 = 4;
      if (param_5 != 2) {
        pcVar2 = "PASSIVE";
      }
      local_40 = 0x10;
      local_30 = 2;
      local_98[0] = uVar3;
      local_48 = param_3;
      _tlgCreate1Sz_char(local_28,pcVar2);
      _tlgWriteTransfer_EtwWriteTransfer
                (0x140020050,&DAT_14001d7e5,local_88,CONCAT62(uVar4,uVar3),7,(undefined8 *)local_88)
      ;
    }
  }
  return;
}



===== VmbusTraceVerbPacketFetchStop @ 140010c04 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void VmbusTraceVerbPacketFetchStop
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined4 param_5,undefined4 param_6)

{
  char cVar1;
  undefined2 uVar2;
  undefined6 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_d8 [32];
  undefined2 local_a8 [2];
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined8 local_98 [4];
  longlong local_78 [2];
  undefined4 *local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined2 *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  undefined4 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  uVar2 = (undefined2)param_4;
  uVar3 = (undefined6)((ulonglong)param_4 >> 0x10);
  local_18 = __security_cookie ^ (ulonglong)auStackY_d8;
  if (5 < DAT_140020050) {
    uVar4 = param_3;
    cVar1 = _tlgKeywordOn(0x140020050,1);
    if (cVar1 != '\0') {
      _tlgCreate1Sz_char(local_78,"InpFillAndProcessQueue");
      local_68 = &local_a4;
      local_a4 = 0xb35;
      local_48 = local_a8;
      local_60 = 4;
      local_a0 = param_5;
      local_38 = &local_a0;
      local_9c = param_6;
      local_28 = &local_9c;
      local_50 = 0x10;
      local_40 = 2;
      local_30 = 4;
      local_20 = 4;
      local_a8[0] = uVar2;
      local_58 = uVar4;
      _tlgWriteTransfer_EtwWriteTransfer
                (0x140020050,&DAT_14001db89,param_3,CONCAT62(uVar3,uVar2),8,local_98);
    }
  }
  return;
}



===== VmbusTraceVerbPacketProcess @ 140010d00 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void VmbusTraceVerbPacketProcess
               (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,char param_6)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  ulonglong uVar4;
  undefined1 auStackY_d8 [32];
  undefined2 local_a8 [2];
  undefined4 local_a4;
  undefined8 local_a0;
  undefined1 local_98 [32];
  longlong local_78 [2];
  undefined4 *local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined2 *local_48;
  undefined8 local_40;
  undefined8 *local_38;
  ulonglong local_30;
  longlong local_28 [2];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_d8;
  if (5 < DAT_140020050) {
    cVar1 = _tlgKeywordOn(0x140020050,1);
    iVar3 = 0;
    if (cVar1 != '\0') {
      _tlgCreate1Sz_char(local_78,"InpProcessQueue");
      local_68 = &local_a4;
      pcVar2 = "Yes";
      local_48 = local_a8;
      uVar4 = (ulonglong)(iVar3 + 8);
      local_a0 = param_5;
      local_38 = &local_a0;
      if (param_6 == (char)iVar3) {
        pcVar2 = "No";
      }
      local_60 = 4;
      local_50 = 0x10;
      local_40 = 2;
      local_a8[0] = param_4;
      local_a4 = param_2;
      local_58 = param_3;
      local_30 = uVar4;
      _tlgCreate1Sz_char(local_28,pcVar2);
      _tlgWriteTransfer_EtwWriteTransfer
                (0x140020050,&DAT_14001db1a,local_98,uVar4,(int)uVar4,(undefined8 *)local_98);
    }
  }
  return;
}



===== VmbusTraceVerbPacketSend @ 140010e04 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void VmbusTraceVerbPacketSend
               (char *param_1,undefined4 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,char param_6)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  ulonglong uVar4;
  undefined1 auStackY_d8 [32];
  undefined2 local_a8 [2];
  undefined4 local_a4;
  undefined8 local_a0;
  undefined1 local_98 [32];
  longlong local_78 [2];
  undefined4 *local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined2 *local_48;
  undefined8 local_40;
  undefined8 *local_38;
  ulonglong local_30;
  longlong local_28 [2];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_d8;
  if (5 < DAT_140020050) {
    cVar1 = _tlgKeywordOn(0x140020050,1);
    iVar3 = 0;
    if (cVar1 != '\0') {
      _tlgCreate1Sz_char(local_78,param_1);
      local_68 = &local_a4;
      pcVar2 = "Yes";
      local_48 = local_a8;
      uVar4 = (ulonglong)(iVar3 + 8);
      local_a0 = param_5;
      local_38 = &local_a0;
      if (param_6 == (char)iVar3) {
        pcVar2 = "No";
      }
      local_60 = 4;
      local_50 = 0x10;
      local_40 = 2;
      local_a8[0] = param_4;
      local_a4 = param_2;
      local_58 = param_3;
      local_30 = uVar4;
      _tlgCreate1Sz_char(local_28,pcVar2);
      _tlgWriteTransfer_EtwWriteTransfer
                (0x140020050,&DAT_14001d4ed,local_98,uVar4,(int)uVar4,(undefined8 *)local_98);
    }
  }
  return;
}



===== VmbusTraceVerbRundownFnStart @ 140010f14 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void VmbusTraceVerbRundownFnStart
               (char *param_1,undefined4 param_2,undefined8 param_3,undefined2 param_4,uint param_5,
               int param_6,undefined4 param_7,char *param_8)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  undefined1 auStackY_108 [32];
  undefined2 local_d8 [2];
  undefined4 local_d4;
  undefined4 local_d0 [2];
  undefined1 local_c8 [32];
  longlong local_a8 [2];
  undefined4 *local_98;
  undefined4 local_90;
  undefined4 local_8c;
  undefined8 local_88;
  undefined4 local_80;
  undefined4 local_7c;
  undefined2 *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  longlong local_68 [2];
  longlong local_58 [2];
  undefined4 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_108;
  if (param_5 < 7) {
    if (param_5 == 6) {
      pcVar2 = "ChannelResuming";
      goto LAB_140011013;
    }
    if (param_5 == 0) {
      pcVar2 = "ChannelDisabled";
      goto LAB_140011013;
    }
    if (param_5 == 1) {
      pcVar2 = "ChannelEnablingWaitingForVmbus";
      goto LAB_140011013;
    }
    if (param_5 == 2) {
      pcVar2 = "ChannelCancellingEnable";
      goto LAB_140011013;
    }
    if (param_5 == 3) {
      pcVar2 = "ChannelPausedClosed";
      goto LAB_140011013;
    }
    if (param_5 == 4) {
      pcVar2 = "ChannelPausedOpen";
      goto LAB_140011013;
    }
    if (param_5 == 5) {
      pcVar2 = "ChannelRunningClosed";
      goto LAB_140011013;
    }
  }
  else {
    if (param_5 == 7) {
      pcVar2 = "ChannelRunningOpen";
      goto LAB_140011013;
    }
    if (param_5 == 8) {
      pcVar2 = "ChannelPausingClosed";
      goto LAB_140011013;
    }
    if (param_5 == 9) {
      pcVar2 = "ChannelPausingWhileResuming";
      goto LAB_140011013;
    }
    if (param_5 == 10) {
      pcVar2 = "ChannelPausingOpenWaitingForPackets";
      goto LAB_140011013;
    }
    if (param_5 == 0xb) {
      pcVar2 = "ChannelClosing";
      goto LAB_140011013;
    }
    if (param_5 == 0xc) {
      pcVar2 = "ChannelPausedServicing";
      goto LAB_140011013;
    }
  }
  pcVar2 = "ChannelStateUnknown";
LAB_140011013:
  if (param_6 == 0) {
    pcVar3 = "ChannelNotRunningDown";
  }
  else if (param_6 == 1) {
    pcVar3 = "ChannelRundownPausing";
  }
  else if (param_6 == 2) {
    pcVar3 = "ChannelRundownClosing";
  }
  else if (param_6 == 3) {
    pcVar3 = "ChannelRundownClosingAndPausing";
  }
  else if (param_6 == 4) {
    pcVar3 = "ChannelRundownDisabling";
  }
  else {
    pcVar3 = "ChannelRundownReasonUnknown";
  }
  if (5 < DAT_140020050) {
    cVar1 = _tlgKeywordOn(0x140020050,4);
    if (cVar1 != '\0') {
      _tlgCreate1Sz_char(local_a8,param_1);
      local_8c = 0;
      local_98 = &local_d4;
      local_7c = 0;
      local_6c = 0;
      local_78 = local_d8;
      local_90 = 4;
      local_80 = 0x10;
      local_70 = 2;
      local_d8[0] = param_4;
      local_d4 = param_2;
      local_88 = param_3;
      _tlgCreate1Sz_char(local_68,pcVar2);
      _tlgCreate1Sz_char(local_58,pcVar3);
      local_48 = local_d0;
      local_3c = 0;
      local_d0[0] = param_7;
      local_40 = 4;
      _tlgCreate1Sz_char(local_38,param_8);
      _tlgWriteTransfer_EtwWriteTransfer
                (0x140020050,&DAT_14001da8f,local_c8,pcVar2,10,(undefined8 *)local_c8);
    }
  }
  return;
}



===== VmbusTraceVerbRundownFnStop @ 140011168 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void VmbusTraceVerbRundownFnStop
               (char *param_1,undefined4 param_2,undefined8 param_3,undefined2 param_4,uint param_5,
               int param_6,undefined4 param_7,char *param_8)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  undefined1 auStackY_108 [32];
  undefined2 local_d8 [2];
  undefined4 local_d4;
  undefined4 local_d0 [2];
  undefined1 local_c8 [32];
  longlong local_a8 [2];
  undefined4 *local_98;
  undefined4 local_90;
  undefined4 local_8c;
  undefined8 local_88;
  undefined4 local_80;
  undefined4 local_7c;
  undefined2 *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  longlong local_68 [2];
  longlong local_58 [2];
  undefined4 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_108;
  if (param_5 < 7) {
    if (param_5 == 6) {
      pcVar2 = "ChannelResuming";
      goto LAB_140011267;
    }
    if (param_5 == 0) {
      pcVar2 = "ChannelDisabled";
      goto LAB_140011267;
    }
    if (param_5 == 1) {
      pcVar2 = "ChannelEnablingWaitingForVmbus";
      goto LAB_140011267;
    }
    if (param_5 == 2) {
      pcVar2 = "ChannelCancellingEnable";
      goto LAB_140011267;
    }
    if (param_5 == 3) {
      pcVar2 = "ChannelPausedClosed";
      goto LAB_140011267;
    }
    if (param_5 == 4) {
      pcVar2 = "ChannelPausedOpen";
      goto LAB_140011267;
    }
    if (param_5 == 5) {
      pcVar2 = "ChannelRunningClosed";
      goto LAB_140011267;
    }
  }
  else {
    if (param_5 == 7) {
      pcVar2 = "ChannelRunningOpen";
      goto LAB_140011267;
    }
    if (param_5 == 8) {
      pcVar2 = "ChannelPausingClosed";
      goto LAB_140011267;
    }
    if (param_5 == 9) {
      pcVar2 = "ChannelPausingWhileResuming";
      goto LAB_140011267;
    }
    if (param_5 == 10) {
      pcVar2 = "ChannelPausingOpenWaitingForPackets";
      goto LAB_140011267;
    }
    if (param_5 == 0xb) {
      pcVar2 = "ChannelClosing";
      goto LAB_140011267;
    }
    if (param_5 == 0xc) {
      pcVar2 = "ChannelPausedServicing";
      goto LAB_140011267;
    }
  }
  pcVar2 = "ChannelStateUnknown";
LAB_140011267:
  if (param_6 == 0) {
    pcVar3 = "ChannelNotRunningDown";
  }
  else if (param_6 == 1) {
    pcVar3 = "ChannelRundownPausing";
  }
  else if (param_6 == 2) {
    pcVar3 = "ChannelRundownClosing";
  }
  else if (param_6 == 3) {
    pcVar3 = "ChannelRundownClosingAndPausing";
  }
  else if (param_6 == 4) {
    pcVar3 = "ChannelRundownDisabling";
  }
  else {
    pcVar3 = "ChannelRundownReasonUnknown";
  }
  if (5 < DAT_140020050) {
    cVar1 = _tlgKeywordOn(0x140020050,4);
    if (cVar1 != '\0') {
      _tlgCreate1Sz_char(local_a8,param_1);
      local_8c = 0;
      local_98 = &local_d4;
      local_7c = 0;
      local_6c = 0;
      local_78 = local_d8;
      local_90 = 4;
      local_80 = 0x10;
      local_70 = 2;
      local_d8[0] = param_4;
      local_d4 = param_2;
      local_88 = param_3;
      _tlgCreate1Sz_char(local_68,pcVar2);
      _tlgCreate1Sz_char(local_58,pcVar3);
      local_48 = local_d0;
      local_3c = 0;
      local_d0[0] = param_7;
      local_40 = 4;
      _tlgCreate1Sz_char(local_38,param_8);
      _tlgWriteTransfer_EtwWriteTransfer
                (0x140020050,&DAT_14001d83a,local_c8,pcVar2,10,(undefined8 *)local_c8);
    }
  }
  return;
}



===== VmbusTraceWarnPacketDelay @ 1400113bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void VmbusTraceWarnPacketDelay
               (char *param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  undefined2 uVar1;
  undefined6 uVar2;
  undefined1 auStackY_e8 [32];
  undefined2 local_b8 [2];
  undefined4 local_b4;
  undefined8 local_b0;
  undefined8 local_a8 [2];
  undefined8 local_98 [4];
  longlong local_78 [2];
  undefined4 *local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined2 *local_48;
  undefined8 local_40;
  undefined8 *local_38;
  undefined8 local_30;
  undefined8 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  uVar1 = (undefined2)param_4;
  uVar2 = (undefined6)((ulonglong)param_4 >> 0x10);
  local_18 = __security_cookie ^ (ulonglong)auStackY_e8;
  if (3 < DAT_140020050) {
    _tlgCreate1Sz_char(local_78,param_1);
    local_68 = &local_b4;
    local_30 = 8;
    local_48 = local_b8;
    local_20 = 8;
    local_b0 = param_5;
    local_38 = &local_b0;
    local_a8[0] = param_6;
    local_28 = local_a8;
    local_60 = 4;
    local_50 = 0x10;
    local_40 = 2;
    local_b8[0] = uVar1;
    local_b4 = param_2;
    local_58 = param_3;
    _tlgWriteTransfer_EtwWriteTransfer
              (0x140020050,&DAT_14001d6b8,param_3,CONCAT62(uVar2,uVar1),8,local_98);
  }
  return;
}



===== KmclCalibrateTsc @ 140011494 =====

ulonglong KmclCalibrateTsc(void)

{
  ulonglong uVar1;
  ulonglong uVar2;
  uint uVar3;
  undefined1 uVar4;
  longlong lVar5;
  longlong lVar6;
  uint uVar7;
  longlong lVar8;
  longlong local_res8;
  
  uVar7 = 0;
  local_res8 = 0;
  uVar4 = KfRaiseIrql(2);
  lVar5 = KeQueryPerformanceCounter(&local_res8);
  uVar1 = rdtsc();
  lVar8 = lVar5;
  do {
    lVar6 = KeQueryPerformanceCounter(0);
    uVar3 = uVar7 + 1;
    if (lVar6 == lVar8) {
      uVar3 = uVar7;
    }
    uVar7 = uVar3;
    lVar8 = lVar6;
  } while (uVar7 < 10);
  uVar2 = rdtsc();
  KeLowerIrql(CONCAT31((int3)(uVar7 >> 8),uVar4));
  return (((CONCAT44((int)((ulonglong)lVar6 >> 0x20),(int)uVar2) | uVar2 & 0xffffffff00000000) -
          (CONCAT44((int)((ulonglong)lVar5 >> 0x20),(int)uVar1) | uVar1 & 0xffffffff00000000)) *
         local_res8) / (ulonglong)(lVar6 - lVar5);
}



===== KmclpDefaultChannelOpenedEx @ 140011560 =====

undefined8 KmclpDefaultChannelOpenedEx(void)

{
  return 0;
}



===== VmbChannelAllocate @ 140011570 =====

uint VmbChannelAllocate(undefined8 param_1,char param_2,undefined8 *param_3)

{
  uint uVar1;
  void *pvVar2;
  
                    /* 0x11570  3  VmbChannelAllocate */
  pvVar2 = (void *)ExAllocatePool2(0x40,0xd40,0x636d6b56);
  if (pvVar2 == (void *)0x0) {
    uVar1 = 0xc000009a;
  }
  else {
    uVar1 = KmclInitializeChannel(pvVar2,param_1,param_2);
    if ((int)uVar1 < 0) {
      ExFreePoolWithTag(pvVar2,0x636d6b56);
    }
    else {
      *(byte *)((longlong)pvVar2 + 0x8f8) = *(byte *)((longlong)pvVar2 + 0x8f8) | 8;
      uVar1 = 0;
      *param_3 = pvVar2;
    }
  }
  return uVar1;
}



===== VmbChannelInitSetBounceBufferSizes @ 140011610 =====

undefined8
VmbChannelInitSetBounceBufferSizes(longlong param_1,uint param_2,uint param_3,uint param_4)

{
                    /* 0x11610  33  VmbChannelInitSetBounceBufferSizes */
  if ((*(char *)(param_1 + 0x6c0) != '\0') || (*(int *)(param_1 + 0x898) != 0)) {
    return 0xc00000ef;
  }
  if (param_2 != 0) {
    if ((param_2 < 0x40000) || ((param_2 & 0xfff) != 0)) {
      return 0xc00000f0;
    }
    *(uint *)(param_1 + 0x7b4) = param_2;
  }
  if (param_3 != 0) {
    if ((param_3 < 0x40000) || ((param_3 & 0xfff) != 0)) {
      return 0xc00000f1;
    }
    *(uint *)(param_1 + 0x7b8) = param_3;
  }
  if (param_4 != 0) {
    if ((param_4 < 0x40000) || ((param_4 & 0xfff) != 0)) {
      return 0xc00000f2;
    }
    *(uint *)(param_1 + 0x7bc) = param_4;
  }
  return 0;
}



===== VmbChannelInitSetFlags @ 1400116a0 =====

undefined8 VmbChannelInitSetFlags(longlong param_1,uint param_2)

{
                    /* 0x116a0  35  VmbChannelInitSetFlags */
  if (*(int *)(param_1 + 0x898) != 0) {
    return 0xc00000ef;
  }
  if ((param_2 & 0xfffffffc) != 0) {
    return 0xc00000f0;
  }
  if ((param_2 & 1) != 0) {
    *(undefined1 *)(param_1 + 0x700) = 1;
  }
  if ((param_2 & 2) != 0) {
    *(undefined1 *)(param_1 + 0x7c2) = 1;
  }
  return 0;
}



===== VmbChannelInitSetMaximumPacketSize @ 1400116f0 =====

undefined8 VmbChannelInitSetMaximumPacketSize(longlong param_1,int param_2)

{
                    /* 0x116f0  40  VmbChannelInitSetMaximumPacketSize */
  if (*(int *)(param_1 + 0x898) != 0) {
    return 0xc00000ef;
  }
  if (param_2 == 0) {
    return 0xc00000f0;
  }
  *(uint *)(param_1 + 0x6c8) = param_2 + 7U & 0xfffffff8;
  return 0;
}



===== VmbChannelInitSetPrimaryChannel @ 140011730 =====

undefined8 VmbChannelInitSetPrimaryChannel(longlong param_1,longlong param_2,short param_3)

{
  code *pcVar1;
  undefined8 uVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined1 *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
                    /* 0x11730  41  VmbChannelInitSetPrimaryChannel */
  if (*(int *)(param_2 + 0x898) != 0xc) {
    if (*(int *)(param_1 + 0x898) != 0) {
      return 0xc00000ef;
    }
    if ((((*(char *)(param_1 + 0xc20) != '\0') || (*(char *)(param_1 + 0x7c0) != '\0')) ||
        (*(char *)(param_2 + 0xc20) != '\0')) || ((*(byte *)(param_2 + 0x8f8) & 4) != 0)) {
      return 0xc00000f0;
    }
    if (param_3 == 0) {
      return 0xc00000f1;
    }
    *(longlong *)(param_1 + 0xc18) = param_2;
    *(undefined1 *)(param_1 + 0xc20) = 1;
    *(short *)(param_1 + 0xc90) = param_3;
    KmclLockChannel(param_2);
    *(byte *)(param_2 + 0x8f8) = *(byte *)(param_2 + 0x8f8) & 0xfd;
    ExAcquireFastMutexUnsafe(param_2 + 0xc28);
    puVar6 = auStack_28;
    lVar4 = param_2 + 0xc60;
    plVar5 = *(longlong **)(param_2 + 0xc68);
    plVar3 = (longlong *)(param_1 + 0xc70);
    if (*plVar5 != lVar4) {
      lVar4 = 3;
      pcVar1 = (code *)swi(0x29);
      plVar3 = (longlong *)(*pcVar1)();
      puVar6 = auStack_20;
    }
    *plVar3 = lVar4;
    plVar3[1] = (longlong)plVar5;
    *plVar5 = (longlong)plVar3;
    *(longlong **)(lVar4 + 8) = plVar3;
    *(undefined8 *)(puVar6 + -8) = 0x140011823;
    ExReleaseFastMutexUnsafe(param_2 + 0xc28);
    *(undefined8 *)(puVar6 + -8) = 0x140011830;
    KmclUnlockChannel(param_2);
    if (*(char *)(param_1 + 0x6c0) == '\0') {
      uVar2 = *(undefined8 *)(param_2 + 0xa98);
      *(undefined8 *)(param_1 + 0x6ec) = *(undefined8 *)(param_2 + 0xa90);
      *(undefined8 *)(param_1 + 0x6f4) = uVar2;
      uVar7 = *(undefined4 *)(param_2 + 0xa80);
      uVar8 = *(undefined4 *)(param_2 + 0xa84);
      uVar9 = *(undefined4 *)(param_2 + 0xa88);
      uVar10 = *(undefined4 *)(param_2 + 0xa8c);
      *(undefined1 *)(param_1 + 0x7c0) = 1;
    }
    else {
      uVar2 = *(undefined8 *)(param_2 + 0x6f4);
      *(undefined8 *)(param_1 + 0x6ec) = *(undefined8 *)(param_2 + 0x6ec);
      *(undefined8 *)(param_1 + 0x6f4) = uVar2;
      uVar7 = *(undefined4 *)(param_2 + 0x6dc);
      uVar8 = *(undefined4 *)(param_2 + 0x6e0);
      uVar9 = *(undefined4 *)(param_2 + 0x6e4);
      uVar10 = *(undefined4 *)(param_2 + 0x6e8);
    }
    *(undefined4 *)(param_1 + 0x6dc) = uVar7;
    *(undefined4 *)(param_1 + 0x6e0) = uVar8;
    *(undefined4 *)(param_1 + 0x6e4) = uVar9;
    *(undefined4 *)(param_1 + 0x6e8) = uVar10;
  }
  return 0;
}



===== VmbChannelInitSetProcessPacketCallbacks @ 1400118a0 =====

undefined8
VmbChannelInitSetProcessPacketCallbacks(longlong param_1,undefined8 param_2,undefined8 param_3)

{
                    /* 0x118a0  42  VmbChannelInitSetProcessPacketCallbacks */
  if ((*(int *)(param_1 + 0x898) == 0) || (*(int *)(param_1 + 0x898) == 0xc)) {
    *(undefined1 *)(param_1 + 0x7c8) = 0;
    *(undefined8 *)(param_1 + 2000) = param_2;
    *(undefined8 *)(param_1 + 0x7d8) = param_3;
    return 0;
  }
  return 0xc00000ef;
}



===== VmbChannelInitSetProcessPacketCallbacksEx @ 1400118e0 =====

undefined8
VmbChannelInitSetProcessPacketCallbacksEx
          (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
                    /* 0x118e0  43  VmbChannelInitSetProcessPacketCallbacksEx */
  if ((*(int *)(param_1 + 0x898) == 0) || (*(int *)(param_1 + 0x898) == 0xc)) {
    *(undefined1 *)(param_1 + 0x7c8) = 1;
    *(undefined8 *)(param_1 + 0x7e0) = param_2;
    *(undefined8 *)(param_1 + 2000) = param_3;
    *(undefined8 *)(param_1 + 0x7d8) = param_4;
    return 0;
  }
  return 0xc00000ef;
}



===== VmbClientChannelInitSetRingBufferPageCount @ 140011920 =====

undefined8
VmbClientChannelInitSetRingBufferPageCount(longlong param_1,undefined4 param_2,undefined4 param_3)

{
                    /* 0x11920  85  VmbClientChannelInitSetRingBufferPageCount */
  if ((*(char *)(param_1 + 0x6c0) == '\0') && (*(int *)(param_1 + 0x898) == 0)) {
    *(undefined4 *)(param_1 + 0x7a8) = param_2;
    *(undefined4 *)(param_1 + 0x7ac) = param_3;
    return 0;
  }
  return 0xc00000ef;
}



===== VmbClientChannelInitSetTargetPnp @ 140011950 =====

undefined8
VmbClientChannelInitSetTargetPnp
          (longlong param_1,undefined8 *param_2,undefined8 *param_3,longlong param_4)

{
  undefined8 uVar1;
  
                    /* 0x11950  87  VmbClientChannelInitSetTargetPnp */
  if ((*(char *)(param_1 + 0x6c0) != '\0') || (*(int *)(param_1 + 0x898) != 0)) {
    return 0xc00000ef;
  }
  if (*(char *)(param_1 + 0x7c1) != '\0') {
    return 0xc00000f0;
  }
  uVar1 = param_2[1];
  *(undefined8 *)(param_1 + 0x6dc) = *param_2;
  *(undefined8 *)(param_1 + 0x6e4) = uVar1;
  if (param_3 != (undefined8 *)0x0) {
    uVar1 = param_3[1];
    *(undefined8 *)(param_1 + 0x6ec) = *param_3;
    *(undefined8 *)(param_1 + 0x6f4) = uVar1;
  }
  if (param_4 != 0) {
    *(longlong *)(param_1 + 0x858) = param_4;
  }
  *(undefined1 *)(param_1 + 0x7c0) = 1;
  return 0;
}



===== VmbClientChannelInitSetTargetProcessorIndex @ 1400119b0 =====

undefined8 VmbClientChannelInitSetTargetProcessorIndex(longlong param_1,undefined4 param_2)

{
                    /* 0x119b0  88  VmbClientChannelInitSetTargetProcessorIndex */
  if ((*(char *)(param_1 + 0x6c0) == '\0') && (*(int *)(param_1 + 0x898) == 0)) {
    *(undefined4 *)(param_1 + 0x7b0) = param_2;
    return 0;
  }
  return 0xc00000ef;
}



===== VmbSizeofChannel @ 1400119e0 =====

undefined8 VmbSizeofChannel(void)

{
                    /* 0x119e0  117  VmbSizeofChannel */
  return 0xd40;
}



===== Feature_3130672440__private_IsEnabledDeviceUsageNoInline @ 1400119f0 =====

ulonglong Feature_3130672440__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  undefined4 *local_res8;
  
  local_res8 = (undefined4 *)(ulonglong)Feature_3130672440__private_featureState;
  if ((Feature_3130672440__private_featureState & 0x10) == 0) {
    uVar1 = Feature_3130672440__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_3130672440__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_3130672440__private_IsEnabledFallback @ 140011a28 =====

void Feature_3130672440__private_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2);
  return;
}



===== InCloseChannel @ 140011a40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void InCloseChannel(longlong *param_1)

{
  InpReleasePacketAllocationResources((longlong)param_1);
  if (param_1[0xb2] != 0) {
    ExFreePoolWithTag(param_1[0xb2],0x636d6b56);
    param_1[0xb2] = 0;
  }
  if (param_1[0xcb] != 0) {
    (**(code **)(*param_1 + 0x9c8))(*(undefined8 *)(*param_1 + 0x910));
    param_1[0xcb] = 0;
  }
  return;
}



===== InDereferencePacketProfiler @ 140011aac =====

void InDereferencePacketProfiler(uint *param_1)

{
  uint *puVar1;
  
  ExAcquireFastMutex(&KmclProfilerListLock);
  puVar1 = param_1 + 1;
  *puVar1 = *puVar1 - 1;
  if (*puVar1 == 0) {
    InpFreePacketProfilerLocked(param_1);
  }
  ExReleaseFastMutex(&KmclProfilerListLock);
  return;
}



===== InInitializeQueue @ 140011af8 =====

undefined8 InInitializeQueue(longlong *param_1)

{
  longlong *plVar1;
  int iVar2;
  undefined4 uVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  int iVar7;
  int iVar8;
  
  lVar4 = *param_1;
  *(undefined4 *)(param_1 + 0x89) = 0;
  KeInitializeDpc(param_1 + 0xbb,InpProcessingDpcRoutine,param_1);
  KeInitializeDpc(param_1 + 0xc3,InpProcessingDpcRoutine,param_1);
  *(undefined4 *)(param_1 + 0xcc) = 0xffffffff;
  *(undefined4 *)((longlong)param_1 + 0x664) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xcd) = 0xffffffff;
  plVar1 = param_1 + 0xa0;
  param_1[0xa1] = (longlong)plVar1;
  *plVar1 = (longlong)plVar1;
  plVar1 = param_1 + 0x8a;
  param_1[0x8b] = (longlong)plVar1;
  *plVar1 = (longlong)plVar1;
  plVar1 = param_1 + 0xa2;
  param_1[0xa3] = (longlong)plVar1;
  *plVar1 = (longlong)plVar1;
  *(undefined4 *)(param_1 + 0xae) = *(undefined4 *)(lVar4 + 0x6d4);
  *(undefined1 *)((longlong)param_1 + 0x4b3) = *(undefined1 *)(lVar4 + 0x706);
  uVar3 = *(undefined4 *)(lVar4 + 0x6fc);
  *(undefined4 *)((longlong)param_1 + 0x584) = 0;
  param_1[0xb4] = 0;
  *(undefined4 *)((longlong)param_1 + 0x52c) = uVar3;
  lVar5 = *param_1;
  if (*(char *)(lVar5 + 0x7c8) == '\0') {
    if (*(longlong *)(lVar5 + 2000) == 0) {
      *(code **)(lVar5 + 2000) = InpChannelProcessPacketNoOp;
    }
    lVar5 = *param_1;
    lVar6 = *(longlong *)(lVar5 + 0x7d8);
  }
  else {
    if (*(longlong *)(lVar5 + 2000) == 0) {
      *(code **)(lVar5 + 2000) = InpChannelProcessPacketExNoOp;
    }
    lVar5 = *param_1;
    lVar6 = *(longlong *)(lVar5 + 0x7d8);
  }
  if (lVar6 == 0) {
    *(code **)(lVar5 + 0x7d8) = _guard_check_icall;
  }
  iVar7 = *(int *)(lVar4 + 0x6d0);
  iVar8 = *(int *)(lVar4 + 0x6c8);
  if (iVar7 == 0) {
    iVar7 = iVar8 + 0xb0;
  }
  else {
    iVar2 = (*(int *)(lVar4 + 0x6cc) + 0xfffU >> 0xc) + iVar7 * 2;
    iVar7 = (iVar8 + 0xd7 + (iVar7 + iVar2) * 8 & 0xfffffff0U) + (iVar2 + iVar7 * 8) * 8;
  }
  iVar7 = (iVar7 + 0xfU & 0xfffffff0) + (int)param_1[0xae];
  if (*(char *)((longlong)param_1 + 0x4b3) != '\0') {
    iVar8 = *(int *)(lVar4 + 0x798);
    iVar7 = iVar7 + iVar8;
  }
  *(int *)((longlong)param_1 + 0x5ac) = iVar8;
  *(int *)(param_1 + 0xb5) = iVar7;
  return 0;
}



===== InIsQueuePurged @ 140011cb4 =====

undefined4 InIsQueuePurged(longlong param_1)

{
  return CONCAT31((int3)((uint)*(int *)(param_1 + 0x478) >> 8),
                  *(int *)(param_1 + 0x520) == *(int *)(param_1 + 0x478));
}



===== InOpenChannel @ 140011ccc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong InOpenChannel(longlong *param_1)

{
  longlong lVar1;
  uint uVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined8 local_res8;
  
  lVar1 = *param_1;
  local_res8 = 0;
  if (*(char *)(lVar1 + 0x6c0) != '\0') {
    uVar2 = (**(code **)(lVar1 + 0x9e8))(*(undefined8 *)(lVar1 + 0x910),&local_res8);
    uVar5 = (ulonglong)uVar2;
    if ((int)uVar2 < 0) goto LAB_140011d43;
    puVar3 = (undefined8 *)ExAllocatePool2(0x40,(int)local_res8 + 0x10,0x636d6b56);
    param_1[0xb2] = (longlong)puVar3;
    if (puVar3 == (undefined8 *)0x0) {
      uVar5 = 0xc000009a;
      goto LAB_140011d43;
    }
    *puVar3 = param_1;
    *(undefined1 *)(param_1 + 0xb3) = local_res8._4_1_;
  }
  uVar2 = (**(code **)(lVar1 + 0x9c0))
                    (*(undefined8 *)(lVar1 + 0x910),*(undefined8 *)(*param_1 + 0xc80),param_1 + 0xcb
                    );
  uVar5 = (ulonglong)uVar2;
  if (-1 < (int)uVar2) {
    uVar4 = InpReacquirePacketAllocationResources(param_1,*(uint *)(param_1 + 0xb5));
    uVar5 = uVar4 & 0xffffffff;
    if (-1 < (int)uVar4) {
      return 0;
    }
  }
LAB_140011d43:
  InCloseChannel(param_1);
  return uVar5;
}



===== InPauseQueue @ 140011db4 =====

void InPauseQueue(longlong *param_1)

{
  int *piVar1;
  longlong lVar2;
  char cVar3;
  int iVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  longlong lVar7;
  uint uVar8;
  undefined1 local_res8 [8];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_res8[0] = KeAcquireSpinLockRaiseToDpc(param_1 + 0x88);
  if ((5 < DAT_140020050) && (cVar3 = _tlgKeywordOn(0x140020050,4), cVar3 != '\0')) {
    lVar2 = *param_1;
    VmbusTraceVerbRundownFnStart
              ("InPauseQueue",0xda2,lVar2 + 0x6ec,*(undefined2 *)(lVar2 + 0xc90),
               *(uint *)(lVar2 + 0x898),*(int *)(lVar2 + 0x89c),*(undefined4 *)(lVar2 + 0x8a8),"");
  }
  if (((int)param_1[0x89] == 8) && (uVar5 = InpCancelMdlMapLocked(param_1), (char)uVar5 != '\0')) {
    *(undefined4 *)(param_1 + 0x89) = 7;
  }
  if (((int)param_1[0x89] == 1) || ((int)param_1[0x89] == 8)) {
    InpWaitForQueueStopEvent(param_1,local_res8);
    if (param_1[0x97] != 0) {
      KeSetEvent(param_1[0x97],0,0);
      param_1[0x97] = 0;
    }
  }
  if (*(int *)((longlong)param_1 + 0x524) ==
      (int)param_1[0x90] + *(int *)((longlong)param_1 + 0x47c)) {
    *(undefined4 *)(param_1 + 0x89) = 0;
    if ((4 < DAT_140020050) && (cVar3 = _tlgKeywordOn(0x140020050,4), cVar3 != '\0')) {
      lVar2 = *param_1;
      VmbusTraceInfoRundownEvent
                ("InPauseQueue",0xde0,lVar2 + 0x6ec,*(undefined2 *)(lVar2 + 0xc90),
                 *(uint *)(lVar2 + 0x898),*(int *)(lVar2 + 0x89c),*(undefined4 *)(lVar2 + 0x8a8),
                 "Incoming queue paused");
    }
  }
  else {
    lVar2 = *param_1;
    *(undefined4 *)(param_1 + 0x89) = 9;
    LOCK();
    *(int *)(lVar2 + 0x8a8) = *(int *)(lVar2 + 0x8a8) + 1;
    UNLOCK();
    LOCK();
    piVar1 = (int *)(lVar2 + 0xca0);
    iVar4 = *piVar1;
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    uVar8 = iVar4 + 1;
    uVar6 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar6 == 0) {
      iVar4 = (int)((ulonglong)((longlong)(int)uVar8 * -0x2aaaaaab) >> 0x20);
      iVar4 = ((iVar4 >> 2) - (iVar4 >> 0x1f)) * 0x18;
    }
    else {
      iVar4 = (uVar8 / 0x18) * -0x18;
    }
    lVar7 = (longlong)(int)(uVar8 + iVar4);
    *(undefined1 *)(lVar2 + 0xca4 + lVar7 * 6) = *(undefined1 *)(lVar2 + 0x898);
    *(undefined1 *)(lVar2 + 0xca5 + lVar7 * 6) = *(undefined1 *)(lVar2 + 0x89c);
    *(short *)(lVar2 + 0xca6 + lVar7 * 6) = (short)*(undefined4 *)(lVar2 + 0x8a8);
    *(undefined2 *)(lVar2 + 0xca8 + lVar7 * 6) = 0xdda;
    if (4 < DAT_140020050) {
      local_48 = *(undefined8 *)(lVar2 + 0xa90);
      uStack_40 = *(undefined8 *)(lVar2 + 0xa98);
      local_38 = *(undefined8 *)(lVar2 + 0xa80);
      uStack_30 = *(undefined8 *)(lVar2 + 0xa88);
      local_28 = *(undefined8 *)(lVar2 + 0xaa0);
      uStack_20 = *(undefined8 *)(lVar2 + 0xaa8);
      VmbusTraceInfoChannelStateChange
                (&local_28,&local_38,&local_48,(ulonglong)*(ushort *)(lVar2 + 0xc90),
                 *(undefined4 *)(lVar2 + 0x898),*(undefined4 *)(lVar2 + 0x89c),
                 *(undefined4 *)(lVar2 + 0x8a8),0xdda);
      if ((4 < DAT_140020050) && (cVar3 = _tlgKeywordOn(0x140020050,4), cVar3 != '\0')) {
        lVar2 = *param_1;
        VmbusTraceInfoRundownEvent
                  ("InPauseQueue",0xddb,lVar2 + 0x6ec,*(undefined2 *)(lVar2 + 0xc90),
                   *(uint *)(lVar2 + 0x898),*(int *)(lVar2 + 0x89c),*(undefined4 *)(lVar2 + 0x8a8),
                   "Waiting for packet completions");
      }
    }
  }
  KeReleaseSpinLock(param_1 + 0x88,local_res8[0]);
  if ((5 < DAT_140020050) && (cVar3 = _tlgKeywordOn(0x140020050,4), cVar3 != '\0')) {
    lVar2 = *param_1;
    VmbusTraceVerbRundownFnStop
              ("InPauseQueue",0xde5,lVar2 + 0x6ec,*(undefined2 *)(lVar2 + 0xc90),
               *(uint *)(lVar2 + 0x898),*(int *)(lVar2 + 0x89c),*(undefined4 *)(lVar2 + 0x8a8),"");
  }
  return;
}



===== InPurgeCompletions @ 140012160 =====

void InPurgeCompletions(longlong param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  code *pcVar3;
  undefined8 *puVar4;
  
  puVar4 = *(undefined8 **)(param_1 + 0x500);
  while( true ) {
    while( true ) {
      if (puVar4 == (undefined8 *)(param_1 + 0x500)) {
        return;
      }
      puVar1 = (undefined8 *)*puVar4;
      if (*(int *)(puVar4 + 2) == 1) break;
      puVar4 = puVar1;
    }
    if (((undefined8 *)puVar1[1] != puVar4) ||
       (puVar2 = (undefined8 *)puVar4[1], (undefined8 *)*puVar2 != puVar4)) break;
    *puVar2 = puVar1;
    puVar1[1] = puVar2;
    puVar1 = (undefined8 *)*puVar4;
    OutCompletePacketToClient((longlong)(puVar4 + -0x12),0xc00002b6,0);
    puVar4 = puVar1;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== InPurgeQueue @ 1400121d4 =====

void InPurgeQueue(longlong *param_1)

{
  longlong *plVar1;
  int iVar2;
  int iVar3;
  longlong *plVar4;
  longlong lVar5;
  code *pcVar6;
  undefined1 *puVar7;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  puVar7 = auStack_28;
  plVar1 = param_1 + 0xa0;
  do {
    plVar4 = (longlong *)*plVar1;
    if (plVar4 == plVar1) {
LAB_14001224a:
      if (*(char *)((longlong)param_1 + 0x4b3) != '\0') {
        *(undefined8 *)(puVar7 + -8) = 0x14001225d;
        InpProcessCompletedDeferredPackets(param_1,'\0');
      }
      return;
    }
    if (((longlong *)plVar4[1] != plVar1) ||
       (lVar5 = *plVar4, (longlong *)*(longlong *)(lVar5 + 8) != plVar4)) {
      pcVar6 = (code *)swi(0x29);
      (*pcVar6)(3);
      puVar7 = auStack_20;
      goto LAB_14001224a;
    }
    *plVar1 = lVar5;
    *(longlong **)(lVar5 + 8) = plVar1;
    if (plVar4[3] != 0) {
      InpUnmapPacketMdl(param_1,(longlong)(plVar4 + -3));
    }
    iVar2 = *(int *)(plVar4 + -2);
    iVar3 = *(int *)((longlong)plVar4 + -0xc);
    InpFreePacket((longlong)param_1,(longlong)(plVar4 + -3));
    InpPacketFreedLocked(param_1,(ulonglong)(uint)(iVar2 - iVar3));
  } while( true );
}



===== InStartQueue @ 14001227c =====

void InStartQueue(longlong *param_1)

{
  undefined1 uVar1;
  char cVar2;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x88);
  if (*(int *)((longlong)param_1 + 0x48c) == 0) {
    *(undefined4 *)((longlong)param_1 + 0x48c) = 1;
  }
  if (*(char *)((longlong)param_1 + 0x4b3) != '\0') {
    InpProcessCompletedDeferredPackets(param_1,'\x01');
  }
  if (*(char *)((longlong)param_1 + 0x4b4) == '\0') {
    *(undefined4 *)(param_1[0xb] + 8) = 1;
    if (5 < DAT_140020050) {
      cVar2 = _tlgKeywordOn(0x140020050,1);
      if (cVar2 != '\0') {
        VmbusTraceVerbInterruptMaskSet
                  ("InpTransitionToProcessingLocked",0x136e,*param_1 + 0x6ec,
                   (ulonglong)*(ushort *)(*param_1 + 0xc90),'\x01');
      }
    }
    *(undefined4 *)(param_1 + 0x89) = 1;
    param_1[0x8d] = (longlong)SystemReserved1[0xf];
    InpPrepareToQueueWorkerLocked(param_1,'\0','\0');
    InpReleaseLockAndPerformWork(param_1);
  }
  else {
    *(undefined4 *)(param_1 + 0x89) = 3;
    *(undefined4 *)(param_1[0xb] + 8) = 1;
    if (5 < DAT_140020050) {
      cVar2 = _tlgKeywordOn(0x140020050,1);
      if (cVar2 != '\0') {
        VmbusTraceVerbInterruptMaskSet
                  ("InStartQueue",0xd6f,*param_1 + 0x6ec,(ulonglong)*(ushort *)(*param_1 + 0xc90),
                   '\x01');
      }
    }
    KeReleaseSpinLock(param_1 + 0x88,uVar1);
  }
  return;
}



===== InStopQueue @ 1400123d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void InStopQueue(longlong *param_1)

{
  undefined2 uVar1;
  longlong lVar2;
  code *pcVar3;
  char cVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 auStackY_48 [8];
  undefined1 auStackY_40 [24];
  
  KeAcquireSpinLockRaiseToDpc(param_1 + 0x88);
  if (5 < DAT_140020050) {
    cVar4 = _tlgKeywordOn(0x140020050,4);
    if (cVar4 != '\0') {
      lVar2 = *param_1;
      VmbusTraceVerbRundownFnStart
                ("InStopQueue",0xdf9,lVar2 + 0x6ec,*(undefined2 *)(lVar2 + 0xc90),
                 *(uint *)(lVar2 + 0x898),*(int *)(lVar2 + 0x89c),*(undefined4 *)(lVar2 + 0x8a8),"")
      ;
    }
  }
  puVar7 = auStackY_48;
  if ((int)param_1[0xcd] != -1) {
    pcVar3 = *(code **)(*param_1 + 0x9b8);
    puVar7 = auStackY_48;
    if (pcVar3 != (code *)0x0) {
      cVar4 = (*pcVar3)(*(undefined8 *)(*param_1 + 0x910),param_1[0xcb]);
      puVar6 = auStackY_48;
      puVar7 = auStackY_48;
      if (cVar4 != '\0') {
        iVar5 = *(int *)((longlong)param_1 + 0x48c);
        if (iVar5 == 0) {
          pcVar3 = (code *)swi(0x29);
          iVar5 = (*pcVar3)(0xe);
          puVar6 = auStackY_40;
        }
        *(undefined4 *)(param_1 + 0xcd) = 0xffffffff;
        *(int *)((longlong)param_1 + 0x48c) = iVar5 + -1;
        puVar7 = puVar6;
      }
    }
  }
  if (*(uint *)((longlong)param_1 + 0x48c) < 2) {
    *(undefined4 *)((longlong)param_1 + 0x48c) = 0;
  }
  else {
    *(uint *)((longlong)param_1 + 0x48c) = *(uint *)((longlong)param_1 + 0x48c) - 1;
    *(undefined8 *)(puVar7 + -8) = 0x1400124e7;
    InpWaitForQueueStopEvent(param_1,puVar7 + 0x50);
  }
  if (4 < DAT_140020050) {
    *(undefined8 *)(puVar7 + -8) = 0x140012507;
    cVar4 = _tlgKeywordOn(0x140020050,4);
    if (cVar4 != '\0') {
      lVar2 = *param_1;
      *(char **)(puVar7 + 0x38) = "Incoming queue stopped";
      *(undefined4 *)(puVar7 + 0x30) = *(undefined4 *)(lVar2 + 0x8a8);
      *(undefined4 *)(puVar7 + 0x28) = *(undefined4 *)(lVar2 + 0x89c);
      uVar1 = *(undefined2 *)(lVar2 + 0xc90);
      *(undefined4 *)(puVar7 + 0x20) = *(undefined4 *)(lVar2 + 0x898);
      *(undefined8 *)(puVar7 + -8) = 0x14001255b;
      VmbusTraceInfoRundownEvent
                ("InStopQueue",0xe1f,lVar2 + 0x6ec,uVar1,*(uint *)(puVar7 + 0x20),
                 *(int *)(puVar7 + 0x28),*(undefined4 *)(puVar7 + 0x30),*(char **)(puVar7 + 0x38));
    }
  }
  *(undefined8 *)(puVar7 + -8) = 0x140012569;
  KeReleaseSpinLock(param_1 + 0x88,puVar7[0x50]);
  if (5 < DAT_140020050) {
    *(undefined8 *)(puVar7 + -8) = 0x140012586;
    cVar4 = _tlgKeywordOn(0x140020050,4);
    if (cVar4 != '\0') {
      lVar2 = *param_1;
      *(char **)(puVar7 + 0x38) = "";
      *(undefined4 *)(puVar7 + 0x30) = *(undefined4 *)(lVar2 + 0x8a8);
      *(undefined4 *)(puVar7 + 0x28) = *(undefined4 *)(lVar2 + 0x89c);
      uVar1 = *(undefined2 *)(lVar2 + 0xc90);
      *(undefined4 *)(puVar7 + 0x20) = *(undefined4 *)(lVar2 + 0x898);
      *(undefined8 *)(puVar7 + -8) = 0x1400125d3;
      VmbusTraceVerbRundownFnStop
                ("InStopQueue",0xe23,lVar2 + 0x6ec,uVar1,*(uint *)(puVar7 + 0x20),
                 *(int *)(puVar7 + 0x28),*(undefined4 *)(puVar7 + 0x30),*(char **)(puVar7 + 0x38));
    }
  }
  return;
}



===== InWaitForDeferredPackets @ 1400125f0 =====

void InWaitForDeferredPackets(longlong *param_1)

{
  longlong lVar1;
  char cVar2;
  undefined1 local_res8 [8];
  
  if (5 < DAT_140020050) {
    cVar2 = _tlgKeywordOn(0x140020050,4);
    if (cVar2 != '\0') {
      lVar1 = *param_1;
      VmbusTraceVerbRundownFnStart
                ("InWaitForDeferredPackets",0x13dc,lVar1 + 0x6ec,*(undefined2 *)(lVar1 + 0xc90),
                 *(uint *)(lVar1 + 0x898),*(int *)(lVar1 + 0x89c),*(undefined4 *)(lVar1 + 0x8a8),"")
      ;
    }
  }
  local_res8[0] = KeAcquireSpinLockRaiseToDpc(param_1 + 0x88);
  if ((int)param_1[0x90] != *(int *)((longlong)param_1 + 0x484)) {
    *(undefined4 *)(param_1 + 0x89) = 10;
    InpWaitForQueueStopEvent(param_1,local_res8);
  }
  if (4 < DAT_140020050) {
    cVar2 = _tlgKeywordOn(0x140020050,4);
    if (cVar2 != '\0') {
      lVar1 = *param_1;
      VmbusTraceInfoRundownEvent
                ("InWaitForDeferredPackets",0x13ea,lVar1 + 0x6ec,*(undefined2 *)(lVar1 + 0xc90),
                 *(uint *)(lVar1 + 0x898),*(int *)(lVar1 + 0x89c),*(undefined4 *)(lVar1 + 0x8a8),
                 "All deferred packets completed");
    }
  }
  KeReleaseSpinLock(param_1 + 0x88,local_res8[0]);
  if (5 < DAT_140020050) {
    cVar2 = _tlgKeywordOn(0x140020050,4);
    if (cVar2 != '\0') {
      lVar1 = *param_1;
      VmbusTraceVerbRundownFnStop
                ("InWaitForDeferredPackets",0x13ee,lVar1 + 0x6ec,*(undefined2 *)(lVar1 + 0xc90),
                 *(uint *)(lVar1 + 0x898),*(int *)(lVar1 + 0x89c),*(undefined4 *)(lVar1 + 0x8a8),"")
      ;
    }
  }
  return;
}



===== InpBuildDataPacket @ 1400127b8 =====

ulonglong InpBuildDataPacket(longlong *param_1,int param_2,undefined8 *param_3,uint param_4,
                            int param_5,longlong param_6,longlong *param_7)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  
  param_6 = 0;
  uVar2 = InpBuildDeferredDataPacket
                    (param_1,param_2,param_3,param_4,param_5,&param_6,(undefined8 *)0x0);
  lVar1 = param_6;
  uVar3 = uVar2 & 0xffffffff;
  if ((int)uVar2 == 1) {
    memmove((void *)(param_6 + 0xa0),*(void **)(param_6 + 0x88),(ulonglong)*(uint *)(param_6 + 0x90)
           );
    uVar2 = InpBuildDataPacketComplete(param_1,lVar1 + 0x68);
    uVar3 = uVar2 & 0xffffffff;
    if ((int)uVar2 == 1) {
      *param_7 = lVar1;
    }
    else {
      InpFreePacket((longlong)param_1,lVar1);
      *param_7 = 0;
    }
  }
  return uVar3;
}



===== InpCancelMdlMapLocked @ 140012860 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 InpCancelMdlMapLocked(longlong *param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  pcVar1 = *(code **)(*param_1 + 0xa38);
  if (pcVar1 != (code *)0x0) {
    uVar2 = (*pcVar1)(*(undefined8 *)(*param_1 + 0x910),param_1[0xb2] + 0x10);
  }
  return uVar2;
}



===== InpChannelProcessPacketExNoOp @ 1400128a0 =====

void InpChannelProcessPacketExNoOp(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  *(undefined4 *)(*param_3 + 0x584) = 2;
  return;
}



===== InpChannelProcessPacketNoOp @ 1400128c0 =====

void InpChannelProcessPacketNoOp(undefined8 param_1,longlong *param_2)

{
  *(undefined4 *)(*param_2 + 0x584) = 2;
  return;
}



===== InpCompletionSent @ 1400128e0 =====

void InpCompletionSent(longlong param_1)

{
  int iVar1;
  int iVar2;
  longlong *plVar3;
  
  plVar3 = *(longlong **)(param_1 + -0x18);
  iVar1 = *(int *)(param_1 + -0x10);
  iVar2 = *(int *)(param_1 + -0xc);
  InpFreePacket((longlong)plVar3,(longlong)(param_1 + -0x18));
  KeAcquireSpinLockRaiseToDpc(plVar3 + 0x88);
  InpPacketFreedLocked(plVar3,(ulonglong)(uint)(iVar1 - iVar2));
  InpReleaseLockAndPerformWork(plVar3);
  return;
}



===== InpMapPacketMdlComplete @ 140012950 =====

void InpMapPacketMdlComplete(longlong param_1,int param_2)

{
  byte bVar1;
  longlong *plVar2;
  longlong lVar3;
  bool bVar4;
  int iVar5;
  
  plVar2 = *(longlong **)(param_1 + -0x10);
  bVar4 = true;
  if (param_2 < 0) {
    *(undefined4 *)(plVar2 + 0xaf) = 5;
    *(undefined4 *)((longlong)plVar2 + 0x57c) = 4;
    if (2 < DAT_140020050) {
      VmbusTraceErrorQueueFailed
                ("InpMapPacketMdlComplete",0x7bd,*plVar2 + 0x6ec,
                 (ulonglong)*(ushort *)(*plVar2 + 0xc90),"InFailedMapFailed","InFailedMapAsync");
    }
    iVar5 = 0xb;
  }
  else {
    lVar3 = *(longlong *)(param_1 + -8);
    InpPostProcessMappedMdl
              (lVar3,(undefined8 *)
                     ((ulonglong)*(uint *)(lVar3 + 0x38) + lVar3 +
                      (ulonglong)*(uint *)(lVar3 + 0x4c) * 8 + 0xa0),*(uint *)(lVar3 + 0x4c));
    iVar5 = 1;
  }
  KeAcquireSpinLockRaiseToDpc(plVar2 + 0x88);
  if ((int)plVar2[0x89] == 8) {
    *(undefined4 *)(plVar2 + 0x89) = 1;
    plVar2[0x8d] = (longlong)SystemReserved1[0xf];
  }
  else {
    bVar1 = *(byte *)(plVar2 + 0x8c);
    *(byte *)(plVar2 + 0x8c) = bVar1 | 4;
    if (param_2 < 0) {
      *(byte *)(plVar2 + 0x8c) = bVar1 | 0xc;
    }
    bVar4 = false;
  }
  KeReleaseSpinLock(plVar2 + 0x88);
  if (bVar4) {
    InpTransitionRunningQueue(plVar2,'\0',iVar5);
  }
  return;
}



===== InpProcessCompletedDeferredPackets @ 140012a90 =====

void InpProcessCompletedDeferredPackets(longlong *param_1,char param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  longlong *plVar4;
  longlong lVar5;
  longlong *plVar6;
  code *pcVar7;
  undefined8 uVar8;
  longlong *plVar9;
  longlong *plVar10;
  
  plVar4 = (longlong *)param_1[0x8a];
  do {
    do {
      plVar10 = plVar4;
      if (plVar10 == param_1 + 0x8a) {
        return;
      }
      plVar4 = (longlong *)*plVar10;
      plVar9 = plVar10 + -3;
    } while ((*(byte *)(plVar10 + -1) & 0x20) == 0);
    if (plVar10[3] != 0) {
      InpUnmapPacketMdl(param_1,(longlong)plVar9);
    }
    lVar5 = *plVar10;
    if ((*(longlong **)(lVar5 + 8) != plVar10) ||
       (plVar6 = (longlong *)plVar10[1], (longlong *)*plVar6 != plVar10)) {
      pcVar7 = (code *)swi(0x29);
      (*pcVar7)(3);
      pcVar7 = (code *)swi(3);
      (*pcVar7)();
      return;
    }
    *plVar6 = lVar5;
    *(longlong **)(lVar5 + 8) = plVar6;
    *(int *)(param_1 + 0x90) = (int)param_1[0x90] + -1;
    *(int *)((longlong)param_1 + 0x484) = *(int *)((longlong)param_1 + 0x484) + -1;
    cVar1 = *(char *)((longlong)plVar10 + -7);
    if ((param_2 == '\0') || ((*(byte *)(plVar10 + -1) & 4) == 0)) {
LAB_140012b69:
      lVar5 = plVar10[-2];
      iVar3 = *(int *)((longlong)plVar10 + -0xc);
      InpFreePacket((longlong)param_1,(longlong)plVar9);
      InpPacketFreedLocked(param_1,(ulonglong)(uint)((int)lVar5 - iVar3));
    }
    else {
      uVar2 = *(uint *)(plVar10 + 5);
      plVar10[5] = plVar10[0x12];
      plVar10[4] = (longlong)InpCompletionSent;
      uVar8 = OutSendCompletionAtDpcLevel
                        (param_1,plVar10,
                         (void *)((longlong)plVar9 +
                                 (ulonglong)uVar2 + 0xa0 +
                                 (ulonglong)*(uint *)((longlong)plVar10 + 0x3c)),
                         *(uint *)(plVar10 + 7),'\0');
      if ((char)uVar8 != '\0') goto LAB_140012b69;
    }
    InpPacketCompletedLocked(param_1,cVar1);
  } while( true );
}



===== InpReacquirePacketAllocationResources @ 140012bc8 =====

ulonglong InpReacquirePacketAllocationResources(longlong *param_1,uint param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  uint *puVar3;
  ulonglong uVar4;
  uint *local_res18 [2];
  
  local_res18[0] = (uint *)0x0;
  lVar1 = ExAllocatePool2(0x40,param_2,0x6e696b56);
  if (lVar1 == 0) {
    uVar4 = 0xc000009a;
  }
  else {
    *(uint *)(lVar1 + 8) = param_2;
    uVar2 = InReferenceProfilerForQueue(param_1,param_2,local_res18);
    uVar4 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) {
      puVar3 = local_res18[0];
    }
    else {
      InpReleasePacketAllocationResources((longlong)param_1);
      param_1[0xb6] = lVar1;
      param_1[0xb7] = lVar1;
      lVar1 = 0;
      param_1[0xb4] = (longlong)local_res18[0];
      uVar4 = 0;
      puVar3 = (uint *)0x0;
    }
    if (puVar3 != (uint *)0x0) {
      InDereferencePacketProfiler(puVar3);
    }
    if (lVar1 != 0) {
      ExFreePoolWithTag(lVar1,0x6e696b56);
    }
  }
  return uVar4;
}



===== InpReleasePacketAllocationResources @ 140012c90 =====

void InpReleasePacketAllocationResources(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x5b0) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x5b0),0x6e696b56);
    *(undefined8 *)(param_1 + 0x5b0) = 0;
    *(undefined8 *)(param_1 + 0x5b8) = 0;
  }
  if (*(uint **)(param_1 + 0x5a0) != (uint *)0x0) {
    InDereferencePacketProfiler(*(uint **)(param_1 + 0x5a0));
    *(undefined8 *)(param_1 + 0x5a0) = 0;
  }
  return;
}



===== InpWaitForQueueStopEvent @ 140012cec =====

void InpWaitForQueueStopEvent(longlong *param_1,undefined1 *param_2)

{
  longlong lVar1;
  uint uVar2;
  char cVar3;
  undefined1 uVar4;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  if (5 < DAT_140020050) {
    cVar3 = _tlgKeywordOn(0x140020050,4);
    if (cVar3 != '\0') {
      lVar1 = *param_1;
      VmbusTraceVerbRundownFnStart
                ("InpWaitForQueueStopEvent",0x13ff,lVar1 + 0x6ec,*(undefined2 *)(lVar1 + 0xc90),
                 *(uint *)(lVar1 + 0x898),*(int *)(lVar1 + 0x89c),*(undefined4 *)(lVar1 + 0x8a8),"")
      ;
    }
  }
  KeInitializeEvent(&local_28,1);
  uVar4 = *param_2;
  param_1[0x98] = (longlong)&local_28;
  KeReleaseSpinLock(param_1 + 0x88,uVar4);
  if (4 < DAT_140020050) {
    cVar3 = _tlgKeywordOn(0x140020050,4);
    if (cVar3 != '\0') {
      lVar1 = *param_1;
      VmbusTraceInfoRundownEvent
                ("InpWaitForQueueStopEvent",0x1405,lVar1 + 0x6ec,*(undefined2 *)(lVar1 + 0xc90),
                 *(uint *)(lVar1 + 0x898),*(int *)(lVar1 + 0x89c),*(undefined4 *)(lVar1 + 0x8a8),
                 "Waiting for StopEvent");
    }
  }
  KeWaitForSingleObject(&local_28,0,0,0,0);
  if (4 < DAT_140020050) {
    cVar3 = _tlgKeywordOn(0x140020050,4);
    if (cVar3 != '\0') {
      lVar1 = *param_1;
      VmbusTraceInfoRundownEvent
                ("InpWaitForQueueStopEvent",0x1409,lVar1 + 0x6ec,*(undefined2 *)(lVar1 + 0xc90),
                 *(uint *)(lVar1 + 0x898),*(int *)(lVar1 + 0x89c),*(undefined4 *)(lVar1 + 0x8a8),
                 "StopEvent wait complete");
    }
  }
  uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x88);
  uVar2 = DAT_140020050;
  *param_2 = uVar4;
  if (5 < uVar2) {
    cVar3 = _tlgKeywordOn(0x140020050,4);
    if (cVar3 != '\0') {
      lVar1 = *param_1;
      VmbusTraceVerbRundownFnStop
                ("InpWaitForQueueStopEvent",0x1415,lVar1 + 0x6ec,*(undefined2 *)(lVar1 + 0xc90),
                 *(uint *)(lVar1 + 0x898),*(int *)(lVar1 + 0x89c),*(undefined4 *)(lVar1 + 0x8a8),"")
      ;
    }
  }
  return;
}



===== McTemplateK0jjh_EtwWriteTransfer @ 140012f50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0jjh_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined1 param_6)

{
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_38 = param_5;
  local_28 = &param_6;
  local_40 = 0x10;
  local_30 = 0x10;
  local_20 = 2;
  local_48 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,4,local_58);
  return;
}



===== McTemplateK0jjqqh_EtwWriteTransfer @ 140012fc8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0jjqqh_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined1 auStackY_a8 [32];
  undefined8 local_78 [2];
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_58 = param_5;
  local_48 = &param_6;
  local_38 = &param_7;
  local_28 = &param_8;
  local_60 = 0x10;
  local_50 = 0x10;
  local_40 = 4;
  local_30 = 4;
  local_20 = 2;
  local_68 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&VMBUS_FINISH_FETCHING,param_3,6,local_78);
  return;
}



===== McTemplateK0jjxth_EtwWriteTransfer @ 140013068 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0jjxth_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined1 auStackY_a8 [32];
  undefined8 local_78 [2];
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_58 = param_5;
  local_48 = &param_6;
  local_38 = &param_7;
  local_28 = &param_8;
  local_60 = 0x10;
  local_50 = 0x10;
  local_40 = 8;
  local_30 = 4;
  local_20 = 2;
  local_68 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,6,local_78);
  return;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 140013100 =====

void wil_details_FeatureReporting_IncrementOpportunityInCache
               (uint *param_1,uint param_2,undefined8 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = *param_1;
  do {
    uVar4 = uVar1;
    param_4[1] = 0;
    uVar1 = uVar4 | 1;
    if ((uVar4 >> 0x16 & 1) != (uint)(param_2 == 5)) {
      uVar3 = uVar4 >> 0xf & 0x7f;
      if (uVar3 != 0) {
        param_4[1] = uVar3;
        uVar3 = 5;
        if (param_2 != 1) {
          uVar3 = 1;
        }
        uVar1 = uVar4 & 0xffc07fff | 1;
        param_4[2] = uVar3;
      }
      uVar3 = 0;
      if (param_2 == 5) {
        uVar3 = 0x400000;
      }
      uVar1 = uVar3 | uVar1 & 0xffbfffff;
    }
    uVar2 = uVar1 >> 0xf & 0x7f;
    uVar3 = uVar2 + 1;
    if ((0x7f < uVar3) || (uVar3 < uVar2)) {
      uVar3 = 1;
      param_4[2] = param_2;
      param_4[1] = uVar2;
    }
    LOCK();
    uVar2 = *param_1;
    if (uVar4 == uVar2) {
      *param_1 = (uVar3 << 0xf ^ uVar1) & 0x3f8000 ^ uVar1;
      uVar1 = uVar4;
    }
    else {
      uVar1 = uVar2;
    }
    UNLOCK();
  } while (uVar4 != uVar2);
  param_4[4] = 0;
  *param_4 = ~uVar4 & 1;
  return;
}



===== wil_details_FeatureReporting_IncrementUsageInCache @ 1400131d8 =====

void wil_details_FeatureReporting_IncrementUsageInCache
               (uint *param_1,uint param_2,undefined8 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = *param_1;
  do {
    uVar3 = uVar1;
    param_4[1] = 0;
    uVar1 = uVar3 | 1;
    if ((uVar3 >> 0xe & 1) != (uint)(param_2 == 4)) {
      uVar4 = uVar3 >> 5 & 0x1ff;
      if (uVar4 != 0) {
        param_4[1] = uVar4;
        param_4[2] = ~-(uint)(param_2 != 0) & 4;
        uVar1 = uVar3 & 0xffffc01f | 1;
      }
      uVar4 = 0;
      if (param_2 == 4) {
        uVar4 = 0x4000;
      }
      uVar1 = uVar4 | uVar1 & 0xffffbfff;
    }
    uVar2 = uVar1 >> 5 & 0x1ff;
    uVar4 = uVar2 + 1;
    if ((0x1ff < uVar4) || (uVar4 < uVar2)) {
      uVar4 = 1;
      param_4[2] = param_2;
      param_4[1] = uVar2;
    }
    LOCK();
    uVar2 = *param_1;
    if (uVar3 == uVar2) {
      *param_1 = (uVar4 << 5 ^ uVar1) & 0x3fe0 ^ uVar1;
      uVar1 = uVar3;
    }
    else {
      uVar1 = uVar2;
    }
    UNLOCK();
  } while (uVar3 != uVar2);
  param_4[4] = 0;
  *param_4 = ~uVar3 & 1;
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 1400132bc =====

uint * wil_details_FeatureReporting_RecordUsageInCache
                 (uint *param_1,uint *param_2,undefined8 param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  
  uVar5 = (uint)param_3;
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  if (uVar5 == 0) {
LAB_140013414:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_140013407:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_140013414;
      if (uVar5 == 5) goto LAB_140013407;
      if ((uVar5 != 6) && (uVar5 != 7)) {
        uVar6 = uVar5 - 0x140;
        if ((int)uVar6 < 0x40) {
          uVar2 = param_2[1];
          do {
            if (((uVar2 & 0x10) == 0) || ((uVar2 >> 5 & 0x3f) != uVar6)) {
              uVar4 = 0;
            }
            else {
              uVar4 = 1;
            }
            param_1[4] = uVar4;
            LOCK();
            uVar4 = param_2[1];
            bVar7 = uVar2 == uVar4;
            if (bVar7) {
              param_2[1] = (uVar6 * 0x20 ^ uVar2) & 0x7e0 ^ uVar2 | 0x10;
            }
            else {
              uVar2 = uVar4;
            }
            UNLOCK();
          } while (!bVar7);
          if (param_1[4] != 0) {
            return param_1;
          }
        }
        param_1[2] = uVar5;
        param_1[1] = 1;
        param_1[3] = param_4;
        return param_1;
      }
    }
    uVar6 = 0;
    if (uVar5 == 2) {
      uVar6 = 2;
    }
    else if (uVar5 == 3) {
      uVar6 = 8;
    }
    else if (uVar5 == 6) {
      uVar6 = 4;
    }
    else if (uVar5 == 7) {
      uVar6 = 0x10;
    }
    uVar2 = 1;
    uVar5 = *param_2;
    do {
      uVar3 = uVar5;
      uVar5 = uVar6 | uVar3;
      param_1[4] = (uint)(uVar5 == uVar3);
      uVar4 = uVar5 | 1;
      if (uVar5 == uVar3) {
        uVar4 = uVar5;
      }
      LOCK();
      uVar1 = *param_2;
      if (uVar3 == uVar1) {
        *param_2 = uVar4;
        uVar5 = uVar3;
      }
      else {
        uVar5 = uVar1;
      }
      UNLOCK();
    } while (uVar3 != uVar1);
    if (((uVar4 & 1) == 0) || ((uVar3 & 1) != 0)) {
      uVar2 = 0;
    }
    *param_1 = uVar2;
  }
  return param_1;
}



===== wil_details_FeatureReporting_ReportUsageToService @ 14001343c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (undefined8 param_1,undefined8 param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  undefined7 extraout_var;
  ulonglong uVar3;
  uint uVar4;
  uint local_res18 [4];
  
  uVar4 = (uint)param_2 & 1;
  uVar3 = (ulonglong)param_3;
  local_res18[0] = param_3;
  uVar2 = wil_details_MapReportingKind(param_3,uVar4);
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(uVar3,param_2,(ulonglong)uVar2);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (0x3cdf870,&Feature_3130672440_logged_traits,0,uVar4,local_res18,0,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 1400134b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (undefined8 param_1,undefined8 param_2,ulonglong param_3)

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
                     (local_50,(uint *)&Feature_3130672440__private_reporting,param_3,
                      (uint)((ulonglong)param_2 >> 0x20));
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_68 = &local_38;
    (*g_wil_details_recordFeatureUsage)
              (0x3cdf870,param_3 & 0xffffffff,1,&Feature_3130672440__private_reporting);
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && ((int)param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)(param_3 & 0xffffffff),0x3cdf870);
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 1400135a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                    (uint *param_1,ulonglong param_2,longlong param_3)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  uint local_res8 [2];
  undefined8 local_res10;
  
  iVar1 = 0;
  local_res8[0] = 0;
  local_res10 = param_2;
  if (g_wil_details_ensureSubscribedToFeatureConfigurationChanges != (code *)0x0) {
    iVar1 = (*g_wil_details_ensureSubscribedToFeatureConfigurationChanges)();
  }
  uVar2 = wil_details_GetCurrentFeatureEnabledState(param_3,local_res8);
  if (*(char *)(param_3 + 0x1c) == '\0') {
    local_res8[0] = local_res8[0] & -(uint)(iVar1 != 0);
  }
  uVar3 = param_2 & 0xffffffff;
  while( true ) {
    uVar5 = (uint)uVar3;
    local_res10 = CONCAT44(local_res10._4_4_,uVar5);
    if ((local_res8[0] != 0) && (local_res10 = CONCAT44(local_res10._4_4_,uVar5), (uVar3 & 2) == 0))
    {
      uVar4 = uVar5 & 0xfffff63e | uVar2 & 0x9c1;
      uVar5 = uVar4 | 2;
      local_res10 = CONCAT44(local_res10._4_4_,uVar4) | 2;
    }
    if ((param_2 & 4) == 0) {
      uVar4 = uVar2 & 0x400 | uVar5 & 0xfffffbff;
      uVar5 = uVar4 | 4;
      local_res10 = CONCAT44(local_res10._4_4_,uVar4) | 4;
    }
    uVar3 = param_2 & 0xffffffff;
    LOCK();
    uVar4 = *param_1;
    bVar6 = (uint)param_2 == uVar4;
    if (bVar6) {
      *param_1 = uVar5;
    }
    else {
      uVar3 = (ulonglong)uVar4;
    }
    UNLOCK();
    if (bVar6) break;
    param_2 = uVar3;
  }
  if (((param_2 & 4) == 0) &&
     (g_wil_details_subscribeFeatureStateCacheToConfigurationChanges != (code *)0x0)) {
    (*g_wil_details_subscribeFeatureStateCacheToConfigurationChanges)
              (param_1,*(undefined1 *)(param_3 + 0x1c),iVar1);
  }
  if (local_res8[0] == 0) {
    local_res10 = CONCAT44(local_res10._4_4_,uVar2 & 0x9c1 | uVar5 & 0xfffff63e);
  }
  return local_res10;
}



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 1400136b4 =====

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
  if ((Feature_3130672440__private_featureState & 2) != 0) {
    uVar1 = Feature_3130672440__private_featureState;
    while ((uVar1 & 1) == (param_1 & 1)) {
      LOCK();
      bVar3 = uVar1 == Feature_3130672440__private_featureState;
      if (bVar3) {
        Feature_3130672440__private_featureState = uVar2 | uVar1;
      }
      else {
        uVar1 = Feature_3130672440__private_featureState;
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



===== wil_details_GetCurrentFeatureEnabledState @ 140013708 =====

uint wil_details_GetCurrentFeatureEnabledState(longlong param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined8 *puVar3;
  uint uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  uint uVar7;
  longlong *plVar8;
  uint local_res8;
  ulonglong local_res10;
  uint local_28 [8];
  
  cVar1 = *(char *)(param_1 + 0x1c);
  uVar2 = *(undefined4 *)(param_1 + 0x18);
  *param_2 = 1;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  uVar5 = wil_RtlStagingConfig_QueryFeatureState(local_28,uVar2,(uint)((byte)(cVar1 - 2U) < 2));
  uVar4 = -(uint)((int)uVar5 != 0) & local_28[0] & 3;
  if (uVar4 == 0) {
    uVar7 = -(uint)(*(char *)(param_1 + 0x1f) != '\0') & 0x40;
  }
  else {
    uVar7 = 0;
    if (local_28[0] == 2) {
      uVar7 = 0x40;
    }
  }
  local_res8 = uVar7 >> 6 ^
               (uVar4 << 7 | -(uint)(local_28[5] != 0) & 0x800 | -(uint)(local_28[4] != 0) & 0x400 |
               uVar7);
  if ((uVar7 != 0) && (plVar8 = *(longlong **)(param_1 + 0x20), plVar8 != (longlong *)0x0)) {
    do {
      puVar3 = (undefined8 *)*plVar8;
      if (puVar3 == (undefined8 *)0x0) {
        return local_res8;
      }
      if ((*(char *)((longlong)puVar3 + 0x1e) == '\0') &&
         (*(char *)((longlong)puVar3 + 0x1d) == '\0')) {
        uVar7 = *(uint *)*puVar3;
        local_res10 = (ulonglong)uVar7;
        if ((uVar7 & 2) == 0) {
          uVar6 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            ((uint *)*puVar3,local_res10,(longlong)puVar3);
          uVar7 = (uint)uVar6;
        }
        uVar4 = local_res8 & 0xfffffffe;
        local_res8 = (uint)((uVar7 & local_res8 & 1) != 0);
      }
      else {
        if (((local_res8 & 1) == 0) || (*(char *)((longlong)puVar3 + 0x1f) == '\0')) {
          uVar4 = 0;
        }
        else {
          uVar4 = 1;
        }
        local_res8 = local_res8 & 0xfffffffe;
      }
      local_res8 = local_res8 | uVar4;
      plVar8 = plVar8 + 1;
    } while ((local_res8 & 1) != 0);
  }
  return local_res8;
}



===== wil_details_IsEnabledFallback @ 140013868 =====

uint wil_details_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  ulonglong local_res18;
  
  local_res18 = (ulonglong)param_1 & 0xffffffff;
  if (((ulonglong)param_1 & 2) == 0) {
    puVar1 = &Feature_3130672440__private_featureState;
    local_res18 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            (&Feature_3130672440__private_featureState,(ulonglong)param_1,
                             0x14001ff48);
    param_1 = puVar1;
    puVar1 = (undefined4 *)(local_res18 & 0xffffffff);
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



===== wil_details_MapReportingKind @ 1400138f8 =====

uint wil_details_MapReportingKind(int param_1,int param_2)

{
  byte bVar1;
  
  if (param_1 != 0) {
    if (param_1 == 1) {
      return ~-(uint)(param_2 != 0) & 4;
    }
    if (param_1 == 2) {
      return (-(uint)(param_2 != 0) & 0xfffffffc) + 5;
    }
    if (param_1 == 3) {
      return (-(uint)(param_2 != 0) & 0xfffffffc) + 6;
    }
    if (param_1 == 4) {
      return (-(uint)(param_2 != 0) & 0xfffffffc) + 7;
    }
    if (param_1 == 5) {
      return (-(uint)(param_2 != 0) & 0xfffffffe) + 10;
    }
    if (param_1 == 6) {
      return (-(uint)(param_2 != 0) & 0xfffffffe) + 0xb;
    }
    bVar1 = (char)param_1 + 0x9c;
    if (bVar1 < 0x32) {
      return (-(uint)(param_2 != 0) & 0xffffffce) + 0x96 + (uint)bVar1;
    }
  }
  return 0xff;
}



===== KmclpAllocateBounceBlock @ 140013998 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint KmclpAllocateBounceBlock(longlong param_1,undefined8 param_2,undefined1 param_3)

{
  longlong *plVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  longlong *plVar5;
  code *pcVar6;
  undefined1 uVar7;
  longlong *plVar8;
  longlong lVar9;
  longlong lVar10;
  longlong *plVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  uint uVar14;
  longlong *plVar15;
  uint uVar16;
  ulonglong uVar17;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined4 local_28;
  uint local_20;
  
  if (*(char *)(param_1 + 0xad9) == '\0') {
    return ~-(uint)(*(char *)(param_1 + 0xad8) != '\0') & 0xc00000bb;
  }
  plVar8 = (longlong *)ExAllocatePool2(0x40,0x48,0x636d6b56);
  if (plVar8 == (longlong *)0x0) {
    uVar14 = 0xc000009a;
  }
  else {
    local_20 = 4;
    local_28 = 1;
    lVar10 = MmAllocatePagesForMdlEx(0,0xffffffffffffffff,0);
    plVar8[8] = lVar10;
    if (lVar10 == 0) {
LAB_140013b21:
      uVar14 = 0xc000009a;
    }
    else {
      iVar2 = *(int *)(lVar10 + 0x2c);
      plVar1 = plVar8 + 2;
      iVar3 = *(int *)(lVar10 + 0x20);
      uVar16 = *(uint *)(lVar10 + 0x28);
      plVar8[1] = (longlong)plVar8;
      *plVar8 = (longlong)plVar8;
      uVar17 = (ulonglong)uVar16 + 0xfff + (ulonglong)(iVar2 + iVar3 & 0xfff) >> 0xc;
      plVar8[3] = (longlong)plVar1;
      *plVar1 = (longlong)plVar1;
      uVar16 = (uint)uVar17;
      *(uint *)((longlong)plVar8 + 0x2c) = uVar16;
      *(undefined1 *)((longlong)plVar8 + 0x31) = param_3;
      if (*(char *)(param_1 + 0xad8) == '\0') {
LAB_140013aad:
        lVar10 = plVar8[8];
        plVar15 = (longlong *)(lVar10 + 0x30);
        if ((*(byte *)(lVar10 + 10) & 5) == 0) {
          local_20 = ExDefaultMdlProtection | 0x40000010;
          local_28 = 0;
          lVar10 = MmMapLockedPagesSpecifyCache(lVar10,0,1);
        }
        else {
          lVar10 = *(longlong *)(lVar10 + 0x18);
        }
        if (lVar10 != 0) {
          lVar9 = ExAllocatePool2(0x40,uVar17 * 0x28);
          plVar8[4] = lVar9;
          if (lVar9 != 0) {
            uVar14 = 0;
            if (uVar16 != 0) {
              lVar9 = 0;
              do {
                plVar11 = (longlong *)(plVar8[4] + lVar9);
                plVar11[1] = (longlong)plVar11;
                *plVar11 = (longlong)plVar11;
                lVar4 = *plVar15;
                plVar15 = plVar15 + 1;
                plVar11[2] = lVar4;
                plVar11[3] = (longlong)plVar8;
                plVar11[4] = (ulonglong)(uVar14 << 0xc) + lVar10;
                plVar5 = (longlong *)plVar8[3];
                if ((longlong *)*plVar5 != plVar1) goto LAB_140013c71;
                *plVar11 = (longlong)plVar1;
                uVar14 = uVar14 + 1;
                plVar11[1] = (longlong)plVar5;
                lVar9 = lVar9 + 0x28;
                *plVar5 = (longlong)plVar11;
                plVar8[3] = (longlong)plVar11;
              } while (uVar14 < uVar16);
            }
            if (*(char *)((longlong)plVar8 + 0x31) == '\0') {
              lVar10 = KeQueryUnbiasedInterruptTime();
              plVar8[7] = lVar10;
            }
            lVar10 = param_1 + 0x100;
            uVar7 = KeAcquireSpinLockRaiseToDpc(lVar10);
            puVar13 = auStack_48;
            lVar9 = param_1 + 0xae0;
            plVar11 = *(longlong **)(param_1 + 0xae8);
            if (*plVar11 != lVar9) {
LAB_140013c71:
              lVar9 = 3;
              pcVar6 = (code *)swi(0x29);
              uVar7 = (*pcVar6)();
              puVar13 = auStack_40;
            }
            *plVar8 = lVar9;
            plVar8[1] = (longlong)plVar11;
            *plVar11 = (longlong)plVar8;
            *(longlong **)(lVar9 + 8) = plVar8;
            *(undefined8 *)(puVar13 + -8) = 0x140013c92;
            KeReleaseSpinLock(lVar10,uVar7);
            uVar14 = 0;
            lVar10 = 0x218;
            goto LAB_140013c9e;
          }
        }
        goto LAB_140013b21;
      }
      uVar14 = (**(code **)(param_1 + 0xa30))(*(undefined8 *)(param_1 + 0x910),plVar8[8],1);
      if (-1 < (int)uVar14) {
        *(undefined1 *)(plVar8 + 6) = 1;
        goto LAB_140013aad;
      }
    }
    if (plVar8[4] != 0) {
      ExFreePoolWithTag(plVar8[4],0x636d6b56);
      plVar8[4] = 0;
    }
    puVar12 = auStack_48;
    lVar10 = plVar8[8];
    if (lVar10 != 0) {
      if ((*(byte *)(lVar10 + 10) & 1) != 0) {
        MmUnmapLockedPages(*(undefined8 *)(lVar10 + 0x18),lVar10);
      }
      puVar12 = auStack_48;
      if ((char)plVar8[6] != '\0') {
        uVar14 = (**(code **)(param_1 + 0xa30))(*(undefined8 *)(param_1 + 0x910),plVar8[8],3);
        puVar12 = auStack_48;
        if ((int)uVar14 < 0) {
          pcVar6 = (code *)swi(0x29);
          (*pcVar6)(0x3a);
          puVar12 = auStack_40;
        }
        *(undefined1 *)(plVar8 + 6) = 0;
      }
      lVar10 = plVar8[8];
      *(undefined8 *)(puVar12 + -8) = 0x140013ba6;
      MmFreePagesFromMdl(lVar10);
      lVar10 = plVar8[8];
      *(undefined8 *)(puVar12 + -8) = 0x140013bb8;
      ExFreePoolWithTag(lVar10,0);
    }
    *(undefined8 *)(puVar12 + -8) = 0x140013bcc;
    ExFreePoolWithTag(plVar8,0x636d6b56);
  }
  lVar10 = 0x220;
LAB_140013c9e:
  LOCK();
  *(longlong *)(lVar10 + param_1) = *(longlong *)(lVar10 + param_1) + 1;
  UNLOCK();
  return uVar14;
}



===== KmclpAllocateBounceList @ 140013cc8 =====

int KmclpAllocateBounceList(longlong param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  longlong *plVar2;
  longlong *plVar3;
  code *pcVar4;
  longlong lVar5;
  undefined8 *puVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong *plVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  int iVar13;
  ulonglong uVar14;
  undefined8 *puVar15;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  lVar5 = 0;
  *param_3 = 0;
  if (KmclPerformanceCounterTimingCounters != 0) {
    lVar5 = KeQueryPerformanceCounter(0);
  }
  puVar12 = auStack_38;
  puVar11 = auStack_38;
  puVar10 = auStack_38;
  puVar15 = (undefined8 *)0x0;
  do {
    if (param_2 == (undefined8 *)0x0) {
      *(longlong *)(param_1 + 0x230) = *(longlong *)(param_1 + 0x230) + 1;
      iVar13 = 0;
LAB_140013e86:
      if (KmclPerformanceCounterTimingCounters != 0) {
        *(undefined8 *)(puVar12 + -8) = 0x140013e99;
        lVar7 = KeQueryPerformanceCounter(0);
        uVar14 = lVar7 - lVar5;
        if (*(ulonglong *)(param_1 + 0x248) < uVar14) {
          *(ulonglong *)(param_1 + 0x248) = uVar14;
        }
        if (uVar14 < *(ulonglong *)(param_1 + 0x250)) {
          *(ulonglong *)(param_1 + 0x250) = uVar14;
        }
        if (iVar13 < 0) {
          *(longlong *)(param_1 + 0x270) = *(longlong *)(param_1 + 0x270) + 1;
          *(ulonglong *)(param_1 + 0x278) = uVar14 + *(longlong *)(param_1 + 0x278);
        }
        else {
          *(longlong *)(param_1 + 0x268) = *(longlong *)(param_1 + 0x268) + 1;
          *(longlong *)(param_1 + 0x280) = *(longlong *)(param_1 + 0x280) + uVar14;
        }
      }
      return iVar13;
    }
    uVar14 = (ulonglong)*(uint *)(param_2 + 5) +
             (ulonglong)(*(int *)(param_2 + 4) + *(int *)((longlong)param_2 + 0x2c) & 0xfff) + 0xfff
             >> 0xc;
    iVar13 = (int)uVar14;
    puVar6 = (undefined8 *)ExAllocateFromNPagedLookasideList(param_1 + 0xb40);
    if (puVar6 == (undefined8 *)0x0) {
      iVar13 = -0x3fffff66;
LAB_140013e60:
      puVar15 = (undefined8 *)*param_3;
      if (puVar15 != (undefined8 *)0x0) {
        *(undefined8 *)(puVar11 + -8) = 0x140013e70;
        KmclpFreeBounceList(param_1,puVar15);
      }
      *param_3 = 0;
      *(longlong *)(param_1 + 0x238) = *(longlong *)(param_1 + 0x238) + 1;
      puVar12 = puVar11;
      goto LAB_140013e86;
    }
    *puVar6 = 0;
    puVar1 = puVar6 + 2;
    *(undefined4 *)(puVar6 + 1) = *(undefined4 *)(param_2 + 5);
    *(undefined4 *)((longlong)puVar6 + 0xc) = *(undefined4 *)((longlong)param_2 + 0x2c);
    puVar6[3] = puVar1;
    *puVar1 = puVar1;
    if (puVar15 == (undefined8 *)0x0) {
      *param_3 = puVar6;
    }
    else {
      *puVar15 = puVar6;
    }
    plVar2 = (longlong *)(param_1 + 0xae0);
    plVar8 = (longlong *)*plVar2;
    if (plVar8 != plVar2) {
      while (iVar13 = (int)uVar14, plVar8 != plVar2) {
        plVar9 = plVar8 + 2;
        while( true ) {
          plVar3 = (longlong *)*plVar9;
          iVar13 = (int)uVar14;
          if ((plVar3 == plVar9) || (iVar13 == 0)) break;
          *(int *)(plVar8 + 5) = (int)plVar8[5] + 1;
          plVar8[7] = 0;
          if (((longlong *)plVar3[1] != plVar9) ||
             (lVar7 = *plVar3, *(longlong **)(lVar7 + 8) != plVar3)) goto LAB_140013e4d;
          *plVar9 = lVar7;
          uVar14 = (ulonglong)(iVar13 - 1);
          *(longlong **)(lVar7 + 8) = plVar9;
          puVar15 = (undefined8 *)puVar6[3];
          if ((undefined8 *)*puVar15 != puVar1) goto LAB_140013e4d;
          *plVar3 = (longlong)puVar1;
          plVar3[1] = (longlong)puVar15;
          *puVar15 = plVar3;
          puVar6[3] = plVar3;
        }
        plVar9 = plVar8;
        if ((int)plVar8[5] == *(int *)((longlong)plVar8 + 0x2c)) {
          lVar7 = *plVar8;
          plVar9 = (longlong *)plVar8[1];
          if ((*(longlong **)(lVar7 + 8) == plVar8) && ((longlong *)*plVar9 == plVar8)) {
            *plVar9 = lVar7;
            *(longlong **)(lVar7 + 8) = plVar9;
            plVar3 = *(longlong **)(param_1 + 0xaf8);
            if (*plVar3 == param_1 + 0xaf0) {
              *plVar8 = param_1 + 0xaf0;
              plVar8[1] = (longlong)plVar3;
              *plVar3 = (longlong)plVar8;
              *(longlong **)(param_1 + 0xaf8) = plVar8;
              *(undefined1 *)((longlong)plVar8 + 0x32) = 1;
              goto LAB_140013e35;
            }
          }
LAB_140013e4d:
          pcVar4 = (code *)swi(0x29);
          (*pcVar4)(3);
          puVar10 = auStack_30;
          goto LAB_140013e54;
        }
LAB_140013e35:
        if (iVar13 == 0) goto LAB_140013e45;
        plVar8 = (longlong *)*plVar9;
      }
    }
    if (iVar13 != 0) {
LAB_140013e54:
      iVar13 = -0x3fffffe9;
      puVar11 = puVar10;
      goto LAB_140013e60;
    }
LAB_140013e45:
    param_2 = (undefined8 *)*param_2;
    puVar15 = puVar6;
  } while( true );
}



===== KmclpFreeBounceBlock @ 140013f20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void KmclpFreeBounceBlock(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  
  if (*(longlong *)(param_2 + 0x20) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x20),0x636d6b56);
    *(undefined8 *)(param_2 + 0x20) = 0;
  }
  lVar1 = *(longlong *)(param_2 + 0x40);
  if (lVar1 != 0) {
    if ((*(byte *)(lVar1 + 10) & 1) != 0) {
      MmUnmapLockedPages(*(undefined8 *)(lVar1 + 0x18),lVar1);
    }
    if (*(char *)(param_2 + 0x30) != '\0') {
      iVar2 = (**(code **)(param_1 + 0xa30))
                        (*(undefined8 *)(param_1 + 0x910),*(undefined8 *)(param_2 + 0x40),3);
      if (iVar2 < 0) {
                    /* WARNING: Subroutine does not return */
        KeBugCheckEx(0x53495650,0xf4e,param_1,param_2,0);
      }
      *(undefined1 *)(param_2 + 0x30) = 0;
    }
    MmFreePagesFromMdl(*(undefined8 *)(param_2 + 0x40));
    ExFreePoolWithTag(*(undefined8 *)(param_2 + 0x40),0);
  }
  ExFreePoolWithTag(param_2,0x636d6b56);
  LOCK();
  *(longlong *)(param_1 + 0x228) = *(longlong *)(param_1 + 0x228) + 1;
  UNLOCK();
  return;
}



===== KmclpFreeBounceList @ 140014014 =====

void KmclpFreeBounceList(longlong param_1,undefined8 *param_2)

{
  longlong *plVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong *plVar6;
  code *pcVar7;
  undefined8 uVar8;
  
joined_r0x000140014036:
  if (param_2 == (undefined8 *)0x0) {
    *(longlong *)(param_1 + 0x240) = *(longlong *)(param_1 + 0x240) + 1;
    return;
  }
  puVar2 = (undefined8 *)*param_2;
  plVar1 = param_2 + 2;
LAB_140014046:
  do {
    plVar3 = (longlong *)*plVar1;
    if (plVar3 == plVar1) break;
    if (((longlong *)plVar3[1] != plVar1) || (lVar4 = *plVar3, *(longlong **)(lVar4 + 8) != plVar3))
    goto LAB_14001415a;
    *plVar1 = lVar4;
    *(longlong **)(lVar4 + 8) = plVar1;
    lVar4 = plVar3[3];
    plVar5 = *(longlong **)(lVar4 + 0x18);
    if (*plVar5 != lVar4 + 0x10) goto LAB_14001415a;
    *plVar3 = lVar4 + 0x10;
    plVar3[1] = (longlong)plVar5;
    *plVar5 = (longlong)plVar3;
    *(longlong **)(lVar4 + 0x18) = plVar3;
    *(int *)(plVar3[3] + 0x28) = *(int *)(plVar3[3] + 0x28) + -1;
    if ((*(int *)(plVar3[3] + 0x28) == 0) && (*(char *)(plVar3[3] + 0x31) == '\0')) {
      uVar8 = KeQueryUnbiasedInterruptTime();
      *(undefined8 *)(plVar3[3] + 0x38) = uVar8;
    }
    plVar5 = (longlong *)plVar3[3];
    if (*(char *)((longlong)plVar5 + 0x32) != '\0') {
      lVar4 = *plVar5;
      if ((*(longlong **)(lVar4 + 8) == plVar5) &&
         (plVar6 = (longlong *)plVar5[1], (longlong *)*plVar6 == plVar5)) {
        *plVar6 = lVar4;
        *(longlong **)(lVar4 + 8) = plVar6;
        plVar5 = *(longlong **)(param_1 + 0xae8);
        plVar6 = (longlong *)plVar3[3];
        if (*plVar5 == param_1 + 0xae0) {
          *plVar6 = param_1 + 0xae0;
          plVar6[1] = (longlong)plVar5;
          *plVar5 = (longlong)plVar6;
          *(longlong **)(param_1 + 0xae8) = plVar6;
          *(undefined1 *)(plVar3[3] + 0x32) = 0;
          goto LAB_140014046;
        }
      }
LAB_14001415a:
      pcVar7 = (code *)swi(0x29);
      (*pcVar7)(3);
      pcVar7 = (code *)swi(3);
      (*pcVar7)();
      return;
    }
  } while( true );
  ExFreeToNPagedLookasideList(param_1 + 0xb40,param_2);
  param_2 = puVar2;
  goto joined_r0x000140014036;
}



===== KmclpFreeOldBounceBlocks @ 140014168 =====

void KmclpFreeOldBounceBlocks(longlong param_1)

{
  longlong ***ppplVar1;
  longlong ***ppplVar2;
  code *pcVar3;
  undefined1 uVar4;
  longlong lVar5;
  longlong ****pppplVar6;
  longlong ****pppplVar7;
  longlong ****local_18;
  longlong ****local_10;
  
  local_10 = (longlong ****)&local_18;
  local_18 = (longlong ****)&local_18;
  uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x100);
  lVar5 = KeQueryUnbiasedInterruptTime();
  pppplVar7 = *(longlong *****)(param_1 + 0xae0);
  while (pppplVar7 != (longlong ****)(param_1 + 0xae0)) {
    pppplVar6 = (longlong ****)0x0;
    if ((pppplVar7[7] != (longlong ***)0x0) &&
       (600000000 < (ulonglong)(lVar5 - (longlong)pppplVar7[7]))) {
      pppplVar6 = pppplVar7;
    }
    pppplVar7 = (longlong ****)*pppplVar7;
    if (pppplVar6 != (longlong ****)0x0) {
      ppplVar1 = *pppplVar6;
      if (((longlong ****)ppplVar1[1] != pppplVar6) ||
         (ppplVar2 = pppplVar6[1], (longlong ****)*ppplVar2 != pppplVar6)) goto LAB_14001426e;
      *ppplVar2 = (longlong **)ppplVar1;
      ppplVar1[1] = (longlong **)ppplVar2;
      if ((longlong *****)*local_10 != &local_18) goto LAB_14001426e;
      pppplVar6[1] = (longlong ***)local_10;
      *pppplVar6 = (longlong ***)&local_18;
      *local_10 = (longlong ***)pppplVar6;
      local_10 = pppplVar6;
    }
  }
  KeReleaseSpinLock(param_1 + 0x100,uVar4);
  while( true ) {
    pppplVar7 = local_18;
    if ((longlong *****)local_18 == &local_18) {
      return;
    }
    if (((longlong *****)local_18[1] != &local_18) ||
       (pppplVar6 = (longlong ****)*local_18, (longlong ****)pppplVar6[1] != local_18)) break;
    pppplVar6[1] = (longlong ***)&local_18;
    local_18 = pppplVar6;
    KmclpFreeBounceBlock(param_1,(longlong)pppplVar7);
  }
LAB_14001426e:
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  return;
}



===== OutCancelPacket @ 140014294 =====

void OutCancelPacket(longlong *param_1,longlong param_2)

{
  undefined1 uVar1;
  bool bVar2;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x58);
  KeAcquireSpinLockAtDpcLevel(param_1 + 0x20);
  bVar2 = *(int *)(param_2 + 0x18) == 2;
  if (bVar2) {
    OutpDequeuePacket((longlong)param_1,(longlong *)(param_2 + 0x90));
    OutpTransitionPacketToReadyToComplete(param_1,param_2);
  }
  KeReleaseSpinLockFromDpcLevel(param_1 + 0x20);
  KeReleaseSpinLock(param_1 + 0x58,uVar1);
  if (bVar2) {
    OutCompletePacketToClient(param_2,0xc0000120,0);
  }
  return;
}



===== OutInitializeQueue @ 140014360 =====

undefined8 OutInitializeQueue(longlong *param_1)

{
  longlong *plVar1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  undefined4 uVar5;
  
  *(undefined4 *)(param_1 + 0x21) = 0;
  KeInitializeSpinLock(param_1 + 0x20);
  KeInitializeSpinLock(param_1 + 0x58);
  plVar1 = param_1 + 0x22;
  param_1[0x23] = (longlong)plVar1;
  *plVar1 = (longlong)plVar1;
  KeInitializeTimer(param_1 + 0x69);
  KeInitializeDpc(param_1 + 0x71,OutpPollingDpcRoutine,param_1);
  KeInitializeDpc(param_1 + 0x79,OutpPollingDpcRoutine,param_1);
  ExInitializeNPagedLookasideList
            (param_1 + 0x28,0,0,ExDefaultNonPagedPoolType | 0x200,
             (ulonglong)*(uint *)(*param_1 + 0x6c8) + (ulonglong)*(uint *)(*param_1 + 0x6d8) + 0xf0,
             0x756f6b56,0);
  *(undefined1 *)(param_1 + 0x38) = 1;
  uVar2 = *(uint *)(*param_1 + 0x6c4);
  param_1[0x59] = 0;
  param_1[0x5a] = 0;
  uVar4 = 0x4000;
  if (0x4000 < uVar2) {
    uVar4 = uVar2;
  }
  param_1[0x5b] = 0;
  param_1[0x5c] = 0;
  param_1[0x5d] = 0;
  param_1[0x5e] = 0;
  *(uint *)((longlong)param_1 + 0x2d4) = uVar4;
  param_1[0x59] = (longlong)(param_1 + 0x5d);
  param_1[0x5c] = 0x40;
  *(undefined4 *)(param_1 + 0x5b) = 0x636d6b56;
  *(undefined4 *)(param_1 + 0x5a) = 1;
  if (*(char *)(*param_1 + 0xad9) == '\0') {
    return 0;
  }
  lVar3 = MmAllocateMappingAddress(0x1000,0x636d6b56);
  param_1[0x51] = lVar3;
  if (lVar3 == 0) {
    if (DAT_140020050 < 3) goto LAB_1400145d7;
    uVar5 = 0x14d;
  }
  else {
    lVar3 = IoAllocateMdl(0,0x1000,0,0,0);
    param_1[0x52] = lVar3;
    if (lVar3 == 0) {
      if (DAT_140020050 < 3) goto LAB_1400145d7;
      uVar5 = 0x155;
    }
    else {
      lVar3 = MmAllocateMappingAddress(0x1000,0x636d6b56);
      param_1[0x5f] = lVar3;
      if (lVar3 == 0) {
        if (DAT_140020050 < 3) goto LAB_1400145d7;
        uVar5 = 0x161;
      }
      else {
        lVar3 = IoAllocateMdl(0,0x1000,0,0,0);
        param_1[0x60] = lVar3;
        if (lVar3 != 0) {
          return 0;
        }
        if (DAT_140020050 < 3) goto LAB_1400145d7;
        uVar5 = 0x169;
      }
    }
  }
  VmbusTraceErrorQueue
            ("OutInitializeQueue",uVar5,*param_1 + 0x6ec,(ulonglong)*(ushort *)(*param_1 + 0xc90),
             0xc000009a);
LAB_1400145d7:
  OutUninitializeQueue((longlong)param_1);
  return 0xc000009a;
}



===== OutIsQueuePurged @ 1400145f8 =====

undefined8 OutIsQueuePurged(longlong param_1)

{
  longlong *plVar1;
  undefined1 uVar2;
  uint local_res8 [8];
  
  uVar2 = 0;
  plVar1 = (longlong *)(param_1 + 0x110);
  local_res8[0] = 0;
  if ((longlong *)*plVar1 == plVar1) {
    plVar1 = (longlong *)DvGetNextHandleEntry((longlong *)(param_1 + 0x2c8),local_res8);
    if (plVar1 == (longlong *)0x0) {
      uVar2 = 1;
    }
  }
  return CONCAT71((int7)((ulonglong)plVar1 >> 8),uVar2);
}



===== OutPacketAddMoreBounceWorkerRoutine @ 140014640 =====

void OutPacketAddMoreBounceWorkerRoutine(undefined8 param_1,ulonglong *param_2)

{
  ulonglong *puVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined1 local_res10 [8];
  undefined8 ****local_18;
  undefined8 ****local_10;
  
  uVar2 = *(uint *)(*param_2 + 0x7b8);
  uVar3 = (ulonglong)uVar2;
  if (uVar2 < 0x40000) {
    uVar3 = 0x40000;
  }
  KmclpAllocateBounceBlock(*param_2,uVar3,0);
  puVar1 = param_2 + 0x20;
  local_res10[0] = KeAcquireSpinLockRaiseToDpc(puVar1);
  if ((int)param_2[0x21] == 5) {
    local_10 = &local_18;
    *(undefined4 *)(param_2 + 0x21) = 2;
    local_18 = &local_18;
    OutpProcessQueueLocked(param_2,(ulonglong)&local_18,local_res10);
    if ((undefined8 *****)local_18 != &local_18) {
      KeReleaseSpinLock(puVar1,local_res10[0]);
      OutpCompletePacketListToClient((longlong *)&local_18);
      return;
    }
  }
  else {
    KeSetEvent(param_2[0x82],0,0);
    param_2[0x82] = 0;
  }
  KeReleaseSpinLock(puVar1,local_res10[0]);
  return;
}



===== OutPurgeQueue @ 14001472c =====

void OutPurgeQueue(longlong *param_1)

{
  code *pcVar1;
  longlong lVar2;
  undefined8 ***pppuVar3;
  uint local_res8 [2];
  undefined8 ***local_18;
  undefined8 ***local_10;
  
  local_18 = &local_18;
  local_10 = &local_18;
  while (pppuVar3 = (undefined8 ***)param_1[0x22], pppuVar3 != (undefined8 ***)(param_1 + 0x22)) {
    OutpDequeuePacket((longlong)param_1,(longlong *)pppuVar3);
    if (*(int *)(pppuVar3 + 2) == 1) {
      *(undefined4 *)(pppuVar3 + 3) = 0xc00002b6;
      OutpTransitionPacketToReadyToComplete(param_1,(longlong)(pppuVar3 + -0x12));
    }
    if ((undefined8 ****)*local_10 != &local_18) goto LAB_14001482f;
    pppuVar3[1] = local_10;
    *pppuVar3 = &local_18;
    *local_10 = pppuVar3;
    local_10 = pppuVar3;
  }
  local_res8[0] = 0;
  while( true ) {
    lVar2 = DvGetNextHandleEntry(param_1 + 0x59,local_res8);
    if (lVar2 == 0) {
      OutpCompletePacketListToClient((longlong *)&local_18);
      return;
    }
    *(undefined4 *)(lVar2 + 0xa8) = 0xc00002b6;
    OutpTransitionPacketToReadyToComplete(param_1,lVar2);
    pppuVar3 = (undefined8 ***)(lVar2 + 0x90);
    if ((undefined8 ****)*local_10 != &local_18) break;
    *(undefined8 ****)(lVar2 + 0x98) = local_10;
    *pppuVar3 = &local_18;
    *local_10 = pppuVar3;
    local_10 = pppuVar3;
  }
LAB_14001482f:
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(3);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== OutSetupGpaDirectPacket @ 14001483c =====

void OutSetupGpaDirectPacket
               (longlong param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
               uint param_5)

{
  byte bVar1;
  uint uVar2;
  byte bVar3;
  
  *(undefined4 *)(param_1 + 0x48) = param_3;
  bVar3 = *(byte *)(param_1 + 0x3e) & 0xfe;
  *(undefined8 *)(param_1 + 0x40) = param_2;
  *(undefined4 *)(param_1 + 0x4c) = param_4;
  uVar2 = param_5 & 2;
  *(undefined1 *)(param_1 + 0x3d) = 1;
  *(undefined8 *)(param_1 + 0x50) = 0;
  *(byte *)(param_1 + 0x3e) = uVar2 != 0 | bVar3;
  if ((param_5 & 8) == 0) {
    if ((param_5 & 0x10) == 0) {
      return;
    }
    bVar1 = (uVar2 != 0) + 0x20;
  }
  else {
    bVar1 = (uVar2 != 0) + 0x10;
  }
  *(byte *)(param_1 + 0x3e) = bVar1 | bVar3;
  return;
}



===== OutStartQueue @ 140014898 =====

void OutStartQueue(longlong param_1)

{
  longlong *plVar1;
  undefined1 uVar2;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x100);
  plVar1 = (longlong *)(param_1 + 0x110);
  *(uint *)(param_1 + 0x108) = ((longlong *)*plVar1 != plVar1) + 1;
  KeReleaseSpinLock(param_1 + 0x100,CONCAT71((int7)((ulonglong)plVar1 >> 8),uVar2));
  return;
}



===== OutStopQueue @ 1400148fc =====

void OutStopQueue(longlong *param_1)

{
  longlong lVar1;
  undefined1 uVar2;
  char cVar3;
  char *pcVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_58 = 0;
  local_40 = 0;
  local_28 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_38 = 0;
  uStack_30 = 0;
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x20);
  pcVar4 = "";
  if (5 < DAT_140020050) {
    cVar3 = _tlgKeywordOn(0x140020050,4);
    if (cVar3 != '\0') {
      lVar1 = *param_1;
      VmbusTraceVerbRundownFnStart
                ("OutStopQueue",0xa3b,lVar1 + 0x6ec,*(undefined2 *)(lVar1 + 0xc90),
                 *(uint *)(lVar1 + 0x898),*(int *)(lVar1 + 0x89c),*(undefined4 *)(lVar1 + 0x8a8),
                 pcVar4);
    }
  }
  bVar5 = (int)param_1[0x21] == 5;
  if (bVar5) {
    KeInitializeEvent(&local_50,1);
    param_1[0x82] = (longlong)&local_50;
  }
  bVar6 = (int)param_1[0x83] != 0;
  if (bVar6) {
    KeInitializeEvent(&local_38,1);
    param_1[0x84] = (longlong)&local_38;
  }
  *(undefined4 *)(param_1 + 0x21) = 0;
  cVar3 = KeCancelTimer(param_1 + 0x69);
  if (cVar3 != '\0') {
    *(int *)(param_1 + 0x81) = (int)param_1[0x81] + -1;
  }
  bVar7 = (int)param_1[0x81] != 0;
  if (bVar7) {
    KeInitializeEvent(&local_68,1);
    param_1[0x68] = (longlong)&local_68;
  }
  KeReleaseSpinLock(param_1 + 0x20,uVar2);
  if (bVar7) {
    if (4 < DAT_140020050) {
      cVar3 = _tlgKeywordOn(0x140020050,4);
      if (cVar3 != '\0') {
        lVar1 = *param_1;
        VmbusTraceInfoRundownEvent
                  ("OutStopQueue",0xa65,lVar1 + 0x6ec,*(undefined2 *)(lVar1 + 0xc90),
                   *(uint *)(lVar1 + 0x898),*(int *)(lVar1 + 0x89c),*(undefined4 *)(lVar1 + 0x8a8),
                   "Waiting for DPCs");
      }
    }
    KeWaitForSingleObject(&local_68,0,0,0,0);
    if (4 < DAT_140020050) {
      cVar3 = _tlgKeywordOn(0x140020050,4);
      if (cVar3 != '\0') {
        lVar1 = *param_1;
        VmbusTraceInfoRundownEvent
                  ("OutStopQueue",0xa67,lVar1 + 0x6ec,*(undefined2 *)(lVar1 + 0xc90),
                   *(uint *)(lVar1 + 0x898),*(int *)(lVar1 + 0x89c),*(undefined4 *)(lVar1 + 0x8a8),
                   "DPC wait complete");
      }
    }
  }
  if (bVar5) {
    if (4 < DAT_140020050) {
      cVar3 = _tlgKeywordOn(0x140020050,4);
      if (cVar3 != '\0') {
        lVar1 = *param_1;
        VmbusTraceInfoRundownEvent
                  ("OutStopQueue",0xa6c,lVar1 + 0x6ec,*(undefined2 *)(lVar1 + 0xc90),
                   *(uint *)(lVar1 + 0x898),*(int *)(lVar1 + 0x89c),*(undefined4 *)(lVar1 + 0x8a8),
                   "Waiting for additional bounce buffer");
      }
    }
    KeWaitForSingleObject(&local_50,0,0,0,0);
    if (4 < DAT_140020050) {
      cVar3 = _tlgKeywordOn(0x140020050,4);
      if (cVar3 != '\0') {
        lVar1 = *param_1;
        VmbusTraceInfoRundownEvent
                  ("OutStopQueue",0xa6e,lVar1 + 0x6ec,*(undefined2 *)(lVar1 + 0xc90),
                   *(uint *)(lVar1 + 0x898),*(int *)(lVar1 + 0x89c),*(undefined4 *)(lVar1 + 0x8a8),
                   "Bounce buffer wait complete");
      }
    }
  }
  if (bVar6) {
    if (4 < DAT_140020050) {
      cVar3 = _tlgKeywordOn(0x140020050,4);
      if (cVar3 != '\0') {
        lVar1 = *param_1;
        VmbusTraceInfoRundownEvent
                  ("OutStopQueue",0xa73,lVar1 + 0x6ec,*(undefined2 *)(lVar1 + 0xc90),
                   *(uint *)(lVar1 + 0x898),*(int *)(lVar1 + 0x89c),*(undefined4 *)(lVar1 + 0x8a8),
                   "Waiting for bounce buffer copies");
      }
    }
    KeWaitForSingleObject(&local_38,0,0,0,0);
    if (DAT_140020050 < 5) goto LAB_140014def;
    cVar3 = _tlgKeywordOn(0x140020050,4);
    if (cVar3 != '\0') {
      lVar1 = *param_1;
      VmbusTraceInfoRundownEvent
                ("OutStopQueue",0xa75,lVar1 + 0x6ec,*(undefined2 *)(lVar1 + 0xc90),
                 *(uint *)(lVar1 + 0x898),*(int *)(lVar1 + 0x89c),*(undefined4 *)(lVar1 + 0x8a8),
                 "Bounce buffer copy wait complete");
    }
  }
  if (4 < DAT_140020050) {
    cVar3 = _tlgKeywordOn(0x140020050,4);
    if (cVar3 != '\0') {
      lVar1 = *param_1;
      VmbusTraceInfoRundownEvent
                ("OutStopQueue",0xa78,lVar1 + 0x6ec,*(undefined2 *)(lVar1 + 0xc90),
                 *(uint *)(lVar1 + 0x898),*(int *)(lVar1 + 0x89c),*(undefined4 *)(lVar1 + 0x8a8),
                 "Outgoing queue stopped");
    }
  }
LAB_140014def:
  if (5 < DAT_140020050) {
    cVar3 = _tlgKeywordOn(0x140020050,4);
    if (cVar3 != '\0') {
      lVar1 = *param_1;
      VmbusTraceVerbRundownFnStop
                ("OutStopQueue",0xa7a,lVar1 + 0x6ec,*(undefined2 *)(lVar1 + 0xc90),
                 *(uint *)(lVar1 + 0x898),*(int *)(lVar1 + 0x89c),*(undefined4 *)(lVar1 + 0x8a8),"")
      ;
    }
  }
  return;
}



===== OutUninitializeQueue @ 140014e80 =====

void OutUninitializeQueue(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x2c8);
  if ((lVar1 != param_1 + 0x2e8) && (lVar1 != 0)) {
    ExFreePoolWithTag(lVar1,*(undefined4 *)(param_1 + 0x2d8));
  }
  *(undefined8 *)(param_1 + 0x2c8) = 0;
  if (*(longlong *)(param_1 + 0x2f0) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x2f0),*(undefined4 *)(param_1 + 0x2d8));
    *(undefined8 *)(param_1 + 0x2f0) = 0;
  }
  if (*(char *)(param_1 + 0x1c0) != '\0') {
    ExDeleteNPagedLookasideList(param_1 + 0x140);
    *(undefined1 *)(param_1 + 0x1c0) = 0;
  }
  if (*(longlong *)(param_1 + 0x288) != 0) {
    MmFreeMappingAddress(*(longlong *)(param_1 + 0x288),0x636d6b56);
    *(undefined8 *)(param_1 + 0x288) = 0;
  }
  if (*(longlong *)(param_1 + 0x290) != 0) {
    IoFreeMdl();
    *(undefined8 *)(param_1 + 0x290) = 0;
  }
  if (*(longlong *)(param_1 + 0x2f8) != 0) {
    MmFreeMappingAddress(*(longlong *)(param_1 + 0x2f8),0x636d6b56);
    *(undefined8 *)(param_1 + 0x2f8) = 0;
  }
  if (*(longlong *)(param_1 + 0x300) != 0) {
    IoFreeMdl();
    *(undefined8 *)(param_1 + 0x300) = 0;
  }
  return;
}



===== OutpAcquireReservedMapping @ 140014f9c =====

void OutpAcquireReservedMapping
               (longlong param_1,char param_2,undefined8 param_3,undefined8 param_4,uint param_5)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  
  if (param_2 == '\0') {
    puVar3 = *(undefined8 **)(param_1 + 0x290);
    uVar2 = *(undefined8 *)(param_1 + 0x288);
  }
  else {
    puVar3 = *(undefined8 **)(param_1 + 0x300);
    uVar2 = *(undefined8 *)(param_1 + 0x2f8);
  }
  *puVar3 = 0;
  *(undefined2 *)((longlong)puVar3 + 10) = 0;
  puVar3[4] = 0;
  *(undefined4 *)((longlong)puVar3 + 0x2c) = 0;
  *(uint *)(puVar3 + 5) = param_5;
  *(short *)(puVar3 + 1) = ((short)((ulonglong)param_5 + 0xfff >> 0xc) + 6) * 8;
  IoBuildPartialMdl(param_3,puVar3,param_4);
  lVar1 = MmMapLockedPagesWithReservedMapping(uVar2,0x636d6b56,puVar3,1);
  if (lVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(0x53495650,0x361,param_1,uVar2,0);
  }
  return;
}



===== OutpCompletePacketListToClient @ 140015080 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void OutpCompletePacketListToClient(longlong *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  code *pcVar3;
  
  while( true ) {
    plVar1 = (longlong *)*param_1;
    if (plVar1 == param_1) {
      return;
    }
    if (((longlong *)plVar1[1] != param_1) || (lVar2 = *plVar1, *(longlong **)(lVar2 + 8) != plVar1)
       ) break;
    *param_1 = lVar2;
    *(longlong **)(lVar2 + 8) = param_1;
    if ((int)plVar1[2] == 2) {
      (*(code *)plVar1[4])();
    }
    else {
      OutCompletePacketToClient((longlong)(plVar1 + -0x12),(ulonglong)*(uint *)(plVar1 + 3),0);
    }
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  return;
}



===== OutpDequeuePacket @ 1400150e0 =====

void OutpDequeuePacket(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  char cVar4;
  longlong lVar5;
  bool bVar6;
  
  lVar1 = *param_2;
  if ((*(longlong **)(lVar1 + 8) != param_2) ||
     (plVar2 = (longlong *)param_2[1], (longlong *)*plVar2 != param_2)) {
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(3);
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  *plVar2 = lVar1;
  *(longlong **)(lVar1 + 8) = plVar2;
  if ((*(longlong **)(param_1 + 0x110) == (longlong *)(param_1 + 0x110)) &&
     (*(int *)(param_1 + 0x108) != 0)) {
    *(undefined4 *)(param_1 + 0x108) = 1;
  }
  if ((int)param_2[2] != 1) {
    return;
  }
  if (param_2[-3] == 0) {
    return;
  }
  if (KmclPerformanceCounterTimingCounters == 0) {
    if (DAT_140020050 < 4) {
      return;
    }
    cVar4 = _tlgKeywordOn(0x140020050,2);
    if (cVar4 == '\0') {
      return;
    }
  }
  lVar5 = KeQueryPerformanceCounter(0);
  lVar1 = param_2[-3];
  bVar6 = KmclPerformanceCounterTimingCounters != 0;
  param_2[-3] = lVar5 - lVar1;
  if (bVar6) {
    *(longlong *)(param_1 + 0x1f0) = *(longlong *)(param_1 + 0x1f0) + (lVar5 - lVar1);
  }
  return;
}



===== OutpEnqueuePacket @ 1400151a8 =====

void OutpEnqueuePacket(longlong param_1,longlong *param_2)

{
  code *pcVar1;
  char cVar2;
  longlong lVar3;
  longlong *plVar4;
  
  if ((int)param_2[2] != 1) goto LAB_1400151f8;
  if (KmclPerformanceCounterTimingCounters == 0) {
    if (DAT_140020050 < 4) goto LAB_1400151f8;
    cVar2 = _tlgKeywordOn(0x140020050,2);
    if (cVar2 == '\0') goto LAB_1400151f8;
  }
  lVar3 = KeQueryPerformanceCounter(0);
  param_2[-3] = lVar3;
LAB_1400151f8:
  lVar3 = param_1 + 0x110;
  plVar4 = *(longlong **)(param_1 + 0x118);
  if (*plVar4 != lVar3) {
    pcVar1 = (code *)swi(0x29);
    lVar3 = (*pcVar1)(3);
  }
  *param_2 = lVar3;
  param_2[1] = (longlong)plVar4;
  *plVar4 = (longlong)param_2;
  *(longlong **)(lVar3 + 8) = param_2;
  return;
}



===== OutpEnqueuePollingTimer @ 140015230 =====

void OutpEnqueuePollingTimer(longlong param_1)

{
  char cVar1;
  
  cVar1 = KeSetTimer(param_1 + 0x348,0xfffffffffd050f80,param_1 + 0x388);
  if (cVar1 == '\0') {
    *(int *)(param_1 + 0x408) = *(int *)(param_1 + 0x408) + 1;
  }
  return;
}



===== OutpPacketCopyToBouncePagesCycleLock @ 140015274 =====

void OutpPacketCopyToBouncePagesCycleLock(longlong param_1,longlong param_2,undefined1 *param_3)

{
  longlong lVar1;
  int *piVar2;
  undefined1 uVar3;
  
  *(int *)(param_1 + 0x418) = *(int *)(param_1 + 0x418) + 1;
  lVar1 = param_1 + 0x100;
  if (param_3 == (undefined1 *)0x0) {
    KeReleaseSpinLockFromDpcLevel(lVar1);
  }
  else {
    KeReleaseSpinLock(lVar1,*param_3);
  }
  OutpPacketCopyBouncePagesToMdl(param_1,param_2,'\0');
  if (param_3 == (undefined1 *)0x0) {
    KeAcquireSpinLockAtDpcLevel(lVar1);
  }
  else {
    uVar3 = KeAcquireSpinLockRaiseToDpc();
    *param_3 = uVar3;
  }
  piVar2 = (int *)(param_1 + 0x418);
  *piVar2 = *piVar2 + -1;
  if ((*piVar2 == 0) && (*(longlong *)(param_1 + 0x420) != 0)) {
    KeSetEvent(*(longlong *)(param_1 + 0x420),0,0);
  }
  return;
}



===== OutpPollingDpcRoutine @ 140015340 =====

void OutpPollingDpcRoutine(undefined8 param_1,ulonglong *param_2)

{
  ulonglong *puVar1;
  ulonglong *puVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 ***local_18;
  undefined8 ***local_10;
  
  local_10 = &local_18;
  puVar1 = param_2 + 0x20;
  local_18 = &local_18;
  KeAcquireSpinLockAtDpcLevel(puVar1);
  iVar3 = (int)param_2[0x21];
  if (iVar3 == 4) {
    KeReleaseSpinLockFromDpcLevel(puVar1);
    KeAcquireSpinLockAtDpcLevel(param_2 + 0x58);
    KeAcquireSpinLockAtDpcLevel(puVar1);
    uVar4 = DvEnsureFreeHandleEntries(param_2 + 0x59);
    *(int *)(param_2 + 0x3a) = (int)param_2[0x5a];
    KeReleaseSpinLockFromDpcLevel(param_2 + 0x58);
    if ((int)uVar4 < 0) {
      OutpEnqueuePollingTimer((longlong)param_2);
      goto LAB_140015457;
    }
    iVar3 = (int)param_2[0x21];
    if (iVar3 != 4) goto LAB_14001540e;
    *(undefined4 *)(param_2 + 0x21) = 2;
  }
  else {
LAB_14001540e:
    if (iVar3 != 2) goto LAB_140015457;
  }
  OutpProcessQueueLocked(param_2,(ulonglong)&local_18,(undefined1 *)0x0);
  if ((undefined8 ****)local_18 != &local_18) {
    KeReleaseSpinLockFromDpcLevel(puVar1);
    OutpCompletePacketListToClient((longlong *)&local_18);
    KeAcquireSpinLockAtDpcLevel(puVar1);
  }
LAB_140015457:
  puVar2 = param_2 + 0x81;
  *(int *)puVar2 = (int)*puVar2 + -1;
  if (((int)*puVar2 == 0) && (param_2[0x68] != 0)) {
    KeSetEvent(param_2[0x68],0,0);
    param_2[0x68] = 0;
  }
  KeReleaseSpinLockFromDpcLevel(puVar1);
  return;
}



===== OutpPreparePacketForIsolation @ 1400154b0 =====

int OutpPreparePacketForIsolation(longlong *param_1,longlong param_2)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  
  if ((KmclPerformanceCounterTimingCounters != 0) && (*(longlong *)(param_2 + 0x88) == 0)) {
    uVar2 = KeQueryPerformanceCounter(0);
    *(undefined8 *)(param_2 + 0x88) = uVar2;
  }
  iVar1 = KmclpAllocateBounceList
                    (*param_1,*(undefined8 **)(param_2 + 0x40),(undefined8 *)(param_2 + 0x50));
  if (iVar1 < 0) {
    if (2 < DAT_140020050) {
      VmbusTraceErrorQueue
                ("OutpPreparePacketForIsolation",0x31b,*param_1 + 0x6ec,
                 (ulonglong)*(ushort *)(*param_1 + 0xc90),iVar1);
    }
  }
  else {
    if (KmclPerformanceCounterTimingCounters != 0) {
      lVar3 = KeQueryPerformanceCounter(0);
      *(longlong *)(*param_1 + 600) =
           *(longlong *)(*param_1 + 600) + (lVar3 - *(longlong *)(param_2 + 0x88));
    }
    iVar1 = 0;
  }
  return iVar1;
}



===== OutpProcessQueueLocked @ 14001557c =====

void OutpProcessQueueLocked(ulonglong *param_1,ulonglong param_2,undefined1 *param_3)

{
  ulonglong *puVar1;
  ulonglong *puVar2;
  code *pcVar3;
  byte bVar4;
  int iVar5;
  ulonglong uVar6;
  ulonglong *puVar7;
  ulonglong *puVar8;
  char cVar9;
  
  if ((int)param_1[0x21] == 3) {
    return;
  }
LAB_1400155b6:
  puVar1 = (ulonglong *)param_1[0x22];
  if (puVar1 == param_1 + 0x22) {
    return;
  }
  if ((int)puVar1[2] == 1) goto code_r0x0001400155cc;
  bVar4 = OutpTrySendCompletionPacket
                    ((longlong *)param_1,(undefined *)puVar1[5],(void *)puVar1[6],(uint)puVar1[3]);
  if (bVar4 == 0) {
    return;
  }
  OutpDequeuePacket((longlong)param_1,(longlong *)puVar1);
  goto LAB_1400156cb;
code_r0x0001400155cc:
  puVar2 = puVar1 + -0x12;
  if ((int)puVar1[-0xf] != 2) goto LAB_1400155b6;
  cVar9 = *(char *)((longlong)puVar1 + -0x54);
  if (((cVar9 != '\0') && (*(int *)((longlong)puVar1 + -0x74) == 0)) &&
     (uVar6 = OutpAllocateHandle((longlong)param_1,(ulonglong)puVar2), (int)uVar6 == 0)) {
    *(undefined4 *)(param_1 + 0x21) = 4;
    OutpEnqueuePollingDpc((longlong)param_1);
    return;
  }
  puVar7 = param_1;
  puVar8 = puVar2;
  uVar6 = OutpPacketNeedsIsolation(param_1,(longlong)puVar2);
  if ((char)uVar6 == '\0') {
LAB_140015658:
    iVar5 = OutpTrySendControlPacket
                      ((longlong *)param_1,(ulonglong)*(uint *)((longlong)puVar1 + -0x74),
                       (ulonglong)puVar2,cVar9);
    *(int *)(puVar1 + 3) = iVar5;
    if (iVar5 != -0x3ffffff3) {
      if (iVar5 < 0) {
        return;
      }
      goto LAB_14001567f;
    }
  }
  else {
    iVar5 = OutpPreparePacketForIsolation((longlong *)puVar7,(longlong)puVar8);
    if (iVar5 == -0x3fffffe9) {
      *(undefined4 *)(param_1 + 0x21) = 5;
      IoQueueWorkItem(*(undefined8 *)(*param_1 + 0xb00),OutPacketAddMoreBounceWorkerRoutine,1,
                      param_1);
      return;
    }
    if (-1 < iVar5) {
      *(undefined4 *)(puVar1 + -0xf) = 5;
      *(undefined4 *)(param_1 + 0x21) = 3;
      OutpPacketCopyToBouncePagesCycleLock((longlong)param_1,(longlong)puVar2,param_3);
      *(undefined4 *)(puVar1 + -0xf) = 2;
      if ((int)param_1[0x21] != 3) {
        return;
      }
      *(undefined4 *)(param_1 + 0x21) = 2;
      goto LAB_140015658;
    }
  }
  cVar9 = '\0';
LAB_14001567f:
  OutpDequeuePacket((longlong)param_1,(longlong *)puVar1);
  if (cVar9 == '\0') {
    OutpTransitionPacketToReadyToComplete((longlong *)param_1,(longlong)puVar2);
LAB_1400156cb:
    puVar2 = *(ulonglong **)(param_2 + 8);
    if (*puVar2 != param_2) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3);
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    *puVar1 = param_2;
    puVar1[1] = (ulonglong)puVar2;
    *puVar2 = (ulonglong)puVar1;
    *(ulonglong **)(param_2 + 8) = puVar1;
  }
  else {
    *(undefined4 *)(puVar1 + -0xf) = 3;
  }
  goto LAB_1400155b6;
}



===== OutpReleaseReservedMapping @ 140015758 =====

void OutpReleaseReservedMapping(longlong param_1,char param_2)

{
  undefined8 uVar1;
  longlong lVar2;
  
  if (param_2 == '\0') {
    lVar2 = *(longlong *)(param_1 + 0x290);
    uVar1 = *(undefined8 *)(param_1 + 0x288);
  }
  else {
    lVar2 = *(longlong *)(param_1 + 0x300);
    uVar1 = *(undefined8 *)(param_1 + 0x2f8);
  }
  MmUnmapReservedMapping(uVar1,0x636d6b56,lVar2);
  if ((*(byte *)(lVar2 + 10) & 0x20) != 0) {
    MmUnmapLockedPages(*(undefined8 *)(lVar2 + 0x18),lVar2);
  }
  return;
}



===== OutpRestoredCompletionSent @ 1400157c0 =====

void OutpRestoredCompletionSent(undefined8 param_1)

{
  ExFreePoolWithTag(param_1,0x636d6b56);
  return;
}



===== WPP_SF_q @ 1400157e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,0);
  return;
}



===== WPP_SF_qDd @ 140015828 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qDd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_5aa4bd3afbb734822e41f6b706e97d47_Traceguids,0x11,&local_res20,8,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_qd @ 140015890 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,4,0);
  return;
}



===== WPP_SF_qdd @ 1400158e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qdd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_qq @ 140015944 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,8,0);
  return;
}



===== KmclpFreeCompletionRoutine @ 1400159a0 =====

void KmclpFreeCompletionRoutine(longlong param_1)

{
  VmbPacketFree(param_1);
  return;
}



===== KmclpSynchronousPacketCompletionRoutine @ 1400159c0 =====

void KmclpSynchronousPacketCompletionRoutine(longlong param_1,undefined4 param_2)

{
  longlong lVar1;
  code *pcVar2;
  undefined1 *puVar3;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [32];
  
  puVar3 = auStack_28;
  if (4 < *(int *)(param_1 + 0x18) - 1U) {
    param_1 = 5;
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)();
    puVar3 = auStack_20;
  }
  lVar1 = *(longlong *)(param_1 + 0x20);
  *(undefined4 *)(lVar1 + 0x18) = param_2;
  *(undefined8 *)(puVar3 + -8) = 0x1400159e8;
  KeSetEvent(lVar1,0,0);
  return;
}



===== OutPacketToVmbPacket @ 1400159fc =====

undefined8 OutPacketToVmbPacket(undefined8 param_1)

{
  return param_1;
}



===== VmbPacketAddTransferPageRanges @ 140015a10 =====

undefined8
VmbPacketAddTransferPageRanges
          (longlong param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  
                    /* 0x15a10  91  VmbPacketAddTransferPageRanges */
  if (4 < *(int *)(param_1 + 0x18) - 1U) {
    param_1 = 5;
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)();
  }
  *(byte *)(param_1 + 0x3e) = *(byte *)(param_1 + 0x3e) | 4;
  *(undefined8 *)(param_1 + 0x40) = param_4;
  *(undefined2 *)(param_1 + 0x48) = param_2;
  return 0;
}



===== VmbPacketGetPointer @ 140015a40 =====

undefined8 VmbPacketGetPointer(longlong param_1)

{
  code *pcVar1;
  
                    /* 0x15a40  96  VmbPacketGetPointer */
  if (4 < *(int *)(param_1 + 0x18) - 1U) {
    param_1 = 5;
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)();
  }
  return *(undefined8 *)(param_1 + 0x20);
}



===== VmbPacketInitialize @ 140015a60 =====

undefined8 VmbPacketInitialize(undefined8 param_1,longlong param_2,int param_3)

{
                    /* 0x15a60  97  VmbPacketInitialize */
  *(undefined8 *)(param_2 + 0x10) = param_1;
  *(undefined8 *)(param_2 + 0x18) = 1;
  *(int *)(param_2 + 0xac) = param_3 + -0xf0;
  *(longlong *)(param_2 + 0x68) = param_2 + 0xf0;
  *(int *)(param_2 + 0x70) = param_3 + -0xf0;
  *(code **)(param_2 + 0x58) = _guard_check_icall;
  *(undefined4 *)(param_2 + 0xa0) = 1;
  *(undefined8 *)(param_2 + 0x20) = 0;
  *(undefined8 *)(param_2 + 0x28) = 0;
  *(undefined2 *)(param_2 + 0x3d) = 0;
  *(undefined8 *)(param_2 + 0x88) = 0;
  *(undefined8 *)(param_2 + 0x78) = 0;
  *(undefined8 *)(param_2 + 0x80) = 0;
  return 0;
}



===== VmbPacketRestore @ 140015ad0 =====

ulonglong VmbPacketRestore(longlong param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  longlong *plVar3;
  code *pcVar4;
  ulonglong uVar5;
  longlong lVar6;
  undefined1 *puVar7;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [40];
  
                    /* 0x15ad0  98  VmbPacketRestore */
  puVar7 = auStack_38;
  lVar6 = param_1;
  if (4 < *(int *)(param_1 + 0x18) - 1U) {
    lVar6 = 5;
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)();
    puVar7 = auStack_30;
  }
  uVar1 = **(undefined8 **)(lVar6 + 0x10);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    uVar2 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    *(undefined8 *)(puVar7 + 0x20) = uVar1;
    *(undefined8 *)(puVar7 + -8) = 0x140015b3c;
    WPP_SF_qq(uVar2,10,&WPP_cc5dcd5a17403e663b8f37ec0d1d5065_Traceguids,param_1,puVar7[0x20]);
  }
  plVar3 = *(longlong **)(param_1 + 0x10);
  *(undefined8 *)(puVar7 + -8) = 0x140015b48;
  uVar5 = OutSetRestorePacket(plVar3,param_1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    uVar2 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    *(int *)(puVar7 + 0x28) = (int)uVar5;
    *(undefined8 *)(puVar7 + 0x20) = uVar1;
    *(undefined8 *)(puVar7 + -8) = 0x140015b85;
    WPP_SF_qqd(uVar2,0xb,&WPP_cc5dcd5a17403e663b8f37ec0d1d5065_Traceguids,param_1,puVar7[0x20],
               puVar7[0x28]);
  }
  return uVar5 & 0xffffffff;
}



===== VmbPacketSendWithExternalMdl @ 140015bb0 =====

int VmbPacketSendWithExternalMdl
              (ulonglong param_1,undefined8 param_2,ulonglong param_3,undefined8 param_4)

{
  code *pcVar1;
  int iVar2;
  ulonglong uVar3;
  int iVar4;
  undefined1 *puVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [40];
  
                    /* 0x15bb0  100  VmbPacketSendWithExternalMdl */
  puVar5 = auStack_38;
  uVar3 = param_3 & 0xffffffff;
  if (4 < *(int *)(param_1 + 0x18) - 1U) {
    param_1 = 5;
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)();
    puVar5 = auStack_30;
  }
  uVar7 = (ulonglong)*(uint *)(puVar5 + 0x70);
  uVar6 = (ulonglong)*(uint *)(puVar5 + 0x68);
  *(uint *)(puVar5 + 0x20) = *(uint *)(puVar5 + 0x70);
  *(undefined8 *)(puVar5 + -8) = 0x140015bfa;
  OutSetupGpaDirectPacket
            (param_1,param_4,*(undefined4 *)(puVar5 + 0x60),*(uint *)(puVar5 + 0x68),
             *(uint *)(puVar5 + 0x20));
  uVar6 = CONCAT71((int7)(uVar6 >> 8),(char)uVar7) & 0xffffffffffffff01;
  if ((uVar7 & 4) == 0) {
    *(undefined4 *)(puVar5 + 0x20) = 1;
    *(undefined8 *)(puVar5 + -8) = 0x140015c36;
    uVar3 = OutSendPacket(param_1,param_2,uVar3 & 0xffffffff,uVar6,*(uint *)(puVar5 + 0x20));
    iVar2 = (int)uVar3;
  }
  else {
    *(undefined4 *)(puVar5 + 0x28) = 0;
    puVar5[0x20] = (char)uVar6;
    *(undefined8 *)(puVar5 + -8) = 0x140015c21;
    uVar3 = OutCopyAndSendPacket
                      (param_1,(undefined8 *)(puVar5 + 0x48),(uint *)(puVar5 + 0x50),uVar6,
                       puVar5[0x20],*(uint *)(puVar5 + 0x28));
    iVar2 = (int)uVar3;
  }
  iVar4 = 0;
  if (iVar2 < 0) {
    iVar4 = iVar2;
  }
  return iVar4;
}



===== VmbPacketSendWithExternalPfns @ 140015c50 =====

int VmbPacketSendWithExternalPfns
              (ulonglong param_1,undefined8 param_2,uint param_3,void *param_4,uint param_5)

{
  int iVar1;
  longlong lVar2;
  
                    /* 0x15c50  101  VmbPacketSendWithExternalPfns */
  if ((param_4 == (void *)0x0) || (param_5 == 0)) {
    iVar1 = -0x3ffffff3;
  }
  else {
    lVar2 = IoAllocateMdl(0,param_5 << 0xc,0,0,0);
    if (lVar2 == 0) {
      iVar1 = -0x3fffff66;
    }
    else {
      *(ushort *)(lVar2 + 10) = *(ushort *)(lVar2 + 10) | 2;
      memmove((void *)(lVar2 + 0x30),param_4,(ulonglong)param_5 << 3);
      iVar1 = VmbPacketSendWithExternalMdl(param_1,param_2,(ulonglong)param_3,lVar2);
      IoFreeMdl(lVar2);
    }
  }
  return iVar1;
}



===== VmbPacketSetCompletionRoutine @ 140015d40 =====

void VmbPacketSetCompletionRoutine(longlong param_1,undefined8 param_2)

{
  code *pcVar1;
  
                    /* 0x15d40  103  VmbPacketSetCompletionRoutine */
  if (4 < *(int *)(param_1 + 0x18) - 1U) {
    param_1 = 5;
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)();
  }
  if ((*(byte *)(param_1 + 0x3e) & 0x40) == 0) {
    *(undefined8 *)(param_1 + 0x58) = param_2;
  }
  return;
}



===== VmbPacketSetPointer @ 140015d70 =====

void VmbPacketSetPointer(longlong param_1,undefined8 param_2)

{
  code *pcVar1;
  
                    /* 0x15d70  105  VmbPacketSetPointer */
  if (4 < *(int *)(param_1 + 0x18) - 1U) {
    param_1 = 5;
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)();
  }
  *(undefined8 *)(param_1 + 0x20) = param_2;
  return;
}



===== WPP_SF_qqd @ 140015d90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,8,&param_6,4,0);
  return;
}



===== VmbusSendInterfaceQueryCompletionRoutine @ 140015df0 =====

undefined8
VmbusSendInterfaceQueryCompletionRoutine(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  KeSetEvent(param_3,0,0);
  IoFreeIrp(param_2);
  return 0xc0000016;
}



===== KmclpClientCloseChannel @ 140015e30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void KmclpClientCloseChannel(longlong param_1)

{
  ExAcquirePushLockExclusiveEx(param_1 + 0xac8,0);
  *(undefined1 *)(param_1 + 0xac6) = 0;
  ExReleasePushLockExclusiveEx(param_1 + 0xac8,0);
  (**(code **)(param_1 + 0x928))(*(undefined8 *)(param_1 + 0x910));
  return;
}



===== KmclpPauseChannel @ 140015e94 =====

void KmclpPauseChannel(longlong param_1,char param_2,undefined8 *param_3)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  ulonglong uVar5;
  longlong lVar6;
  uint uVar7;
  undefined4 uVar8;
  char *pcVar9;
  char *pcVar10;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  KmclLockChannel(param_1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qLLd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,param_3,param_1,
                (char)*(undefined4 *)(param_1 + 0x898),(char)*(undefined4 *)(param_1 + 0x89c),
                param_2);
  }
  pcVar9 = "Wait: false";
  pcVar10 = "Wait: true";
  if (5 < DAT_140020050) {
    cVar2 = _tlgKeywordOn(0x140020050,4);
    if (cVar2 != '\0') {
      param_3 = (undefined8 *)(param_1 + 0x6ec);
      pcVar4 = "Wait: true";
      if (param_2 == '\0') {
        pcVar4 = pcVar9;
      }
      VmbusTraceVerbRundownFnStart
                ("KmclpPauseChannel",0x3ae,param_3,*(undefined2 *)(param_1 + 0xc90),
                 *(uint *)(param_1 + 0x898),*(int *)(param_1 + 0x89c),
                 *(undefined4 *)(param_1 + 0x8a8),pcVar4);
    }
  }
  iVar3 = *(int *)(param_1 + 0x898);
  if (((iVar3 == 0) || (iVar3 == 1)) || ((iVar3 == 3 || ((iVar3 == 4 || (iVar3 == 0xc)))))) {
    KmclUnlockChannel(param_1);
    if (param_2 != '\0') goto LAB_1400164a8;
    if (4 < DAT_140020050) {
      cVar2 = _tlgKeywordOn(0x140020050,4);
      if (cVar2 != '\0') {
        VmbusTraceInfoRundownEvent
                  ("KmclpPauseChannel",0x3bb,param_1 + 0x6ec,*(undefined2 *)(param_1 + 0xc90),
                   *(uint *)(param_1 + 0x898),*(int *)(param_1 + 0x89c),
                   *(undefined4 *)(param_1 + 0x8a8),"Subchannel already paused");
      }
    }
    LOCK();
    piVar1 = (int *)(param_1 + 0xca0);
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    uVar7 = iVar3 + 1;
    uVar5 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar5 == 0) {
      iVar3 = (int)((ulonglong)((longlong)(int)uVar7 * -0x2aaaaaab) >> 0x20);
      iVar3 = ((iVar3 >> 2) - (iVar3 >> 0x1f)) * 0x18;
    }
    else {
      iVar3 = (uVar7 / 0x18) * -0x18;
    }
    lVar6 = (longlong)(int)(uVar7 + iVar3);
    *(undefined1 *)(param_1 + 0xca4 + lVar6 * 6) = *(undefined1 *)(param_1 + 0x898);
    *(undefined1 *)(param_1 + 0xca5 + lVar6 * 6) = *(undefined1 *)(param_1 + 0x89c);
    *(short *)(param_1 + 0xca6 + lVar6 * 6) = (short)*(undefined4 *)(param_1 + 0x8a8);
    *(undefined2 *)(param_1 + 0xca8 + lVar6 * 6) = 0x3bc;
    if (4 < DAT_140020050) {
      local_58 = *(undefined8 *)(param_1 + 0xa90);
      uStack_50 = *(undefined8 *)(param_1 + 0xa98);
      local_68 = *(undefined8 *)(param_1 + 0xa80);
      uStack_60 = *(undefined8 *)(param_1 + 0xa88);
      local_78 = *(undefined8 *)(param_1 + 0xaa0);
      uStack_70 = *(undefined8 *)(param_1 + 0xaa8);
      VmbusTraceInfoChannelStateChange
                (&local_78,&local_68,&local_58,(ulonglong)*(ushort *)(param_1 + 0xc90),
                 *(undefined4 *)(param_1 + 0x898),*(undefined4 *)(param_1 + 0x89c),
                 *(undefined4 *)(param_1 + 0x8a8),0x3bc);
    }
    uVar8 = 0x3bd;
LAB_14001649a:
    KmclDecrementRundownCount(*(longlong *)(param_1 + 0xc18),'\0',uVar8);
  }
  else {
    if (*(int *)(param_1 + 0x89c) == 0) {
      *(undefined4 *)(param_1 + 0x89c) = 1;
      LOCK();
      piVar1 = (int *)(param_1 + 0xca0);
      iVar3 = *piVar1;
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      uVar7 = iVar3 + 1;
      uVar5 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar5 == 0) {
        iVar3 = (int)((ulonglong)((longlong)(int)uVar7 * -0x2aaaaaab) >> 0x20);
        iVar3 = ((iVar3 >> 2) - (iVar3 >> 0x1f)) * 0x18;
      }
      else {
        iVar3 = (uVar7 / 0x18) * -0x18;
      }
      lVar6 = (longlong)(int)(uVar7 + iVar3);
      *(undefined1 *)(param_1 + 0xca4 + lVar6 * 6) = *(undefined1 *)(param_1 + 0x898);
      *(undefined1 *)(param_1 + 0xca5 + lVar6 * 6) = *(undefined1 *)(param_1 + 0x89c);
      *(short *)(param_1 + 0xca6 + lVar6 * 6) = (short)*(undefined4 *)(param_1 + 0x8a8);
      *(undefined2 *)(param_1 + 0xca8 + lVar6 * 6) = 0x3c6;
      if (4 < DAT_140020050) {
        param_3 = &local_78;
        local_78 = *(undefined8 *)(param_1 + 0xa90);
        uStack_70 = *(undefined8 *)(param_1 + 0xa98);
        local_68 = *(undefined8 *)(param_1 + 0xa80);
        uStack_60 = *(undefined8 *)(param_1 + 0xa88);
        local_58 = *(undefined8 *)(param_1 + 0xaa0);
        uStack_50 = *(undefined8 *)(param_1 + 0xaa8);
        VmbusTraceInfoChannelStateChange
                  (&local_58,&local_68,param_3,(ulonglong)*(ushort *)(param_1 + 0xc90),
                   *(undefined4 *)(param_1 + 0x898),*(undefined4 *)(param_1 + 0x89c),
                   *(undefined4 *)(param_1 + 0x8a8),0x3c6);
      }
    }
    else if (*(int *)(param_1 + 0x89c) == 2) {
      *(undefined4 *)(param_1 + 0x89c) = 3;
      LOCK();
      piVar1 = (int *)(param_1 + 0xca0);
      iVar3 = *piVar1;
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      uVar7 = iVar3 + 1;
      uVar5 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar5 == 0) {
        iVar3 = (int)((ulonglong)((longlong)(int)uVar7 * -0x2aaaaaab) >> 0x20);
        iVar3 = ((iVar3 >> 2) - (iVar3 >> 0x1f)) * 0x18;
      }
      else {
        iVar3 = (uVar7 / 0x18) * -0x18;
      }
      lVar6 = (longlong)(int)(uVar7 + iVar3);
      *(undefined1 *)(param_1 + 0xca4 + lVar6 * 6) = *(undefined1 *)(param_1 + 0x898);
      *(undefined1 *)(param_1 + 0xca5 + lVar6 * 6) = *(undefined1 *)(param_1 + 0x89c);
      *(short *)(param_1 + 0xca6 + lVar6 * 6) = (short)*(undefined4 *)(param_1 + 0x8a8);
      *(undefined2 *)(param_1 + 0xca8 + lVar6 * 6) = 0x3cb;
      if (4 < DAT_140020050) {
        param_3 = &local_48;
        local_48 = *(undefined8 *)(param_1 + 0xa90);
        uStack_40 = *(undefined8 *)(param_1 + 0xa98);
        local_38 = *(undefined8 *)(param_1 + 0xa80);
        uStack_30 = *(undefined8 *)(param_1 + 0xa88);
        local_28 = *(undefined8 *)(param_1 + 0xaa0);
        uStack_20 = *(undefined8 *)(param_1 + 0xaa8);
        VmbusTraceInfoChannelStateChange
                  (&local_28,&local_38,param_3,(ulonglong)*(ushort *)(param_1 + 0xc90),
                   *(undefined4 *)(param_1 + 0x898),*(undefined4 *)(param_1 + 0x89c),
                   *(undefined4 *)(param_1 + 0x8a8),0x3cb);
      }
      if (*(int *)(param_1 + 0x898) == 0xb) {
        KmclUnlockChannel(param_1);
        if (param_2 != '\0') goto LAB_1400164a8;
        if (4 < DAT_140020050) {
          cVar2 = _tlgKeywordOn(0x140020050,4);
          if (cVar2 != '\0') {
            VmbusTraceInfoRundownEvent
                      ("KmclpPauseChannel",0x3e0,param_1 + 0x6ec,*(undefined2 *)(param_1 + 0xc90),
                       *(uint *)(param_1 + 0x898),*(int *)(param_1 + 0x89c),
                       *(undefined4 *)(param_1 + 0x8a8),"Subchannel already pausing");
          }
        }
        LOCK();
        piVar1 = (int *)(param_1 + 0xca0);
        iVar3 = *piVar1;
        *piVar1 = *piVar1 + 1;
        UNLOCK();
        uVar7 = iVar3 + 1;
        uVar5 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar5 == 0) {
          iVar3 = (int)((ulonglong)((longlong)(int)uVar7 * -0x2aaaaaab) >> 0x20);
          iVar3 = ((iVar3 >> 2) - (iVar3 >> 0x1f)) * 0x18;
        }
        else {
          iVar3 = (uVar7 / 0x18) * -0x18;
        }
        lVar6 = (longlong)(int)(uVar7 + iVar3);
        *(undefined1 *)(param_1 + 0xca4 + lVar6 * 6) = *(undefined1 *)(param_1 + 0x898);
        *(undefined1 *)(param_1 + 0xca5 + lVar6 * 6) = *(undefined1 *)(param_1 + 0x89c);
        *(short *)(param_1 + 0xca6 + lVar6 * 6) = (short)*(undefined4 *)(param_1 + 0x8a8);
        *(undefined2 *)(param_1 + 0xca8 + lVar6 * 6) = 0x3e1;
        if (4 < DAT_140020050) {
          local_58 = *(undefined8 *)(param_1 + 0xa90);
          uStack_50 = *(undefined8 *)(param_1 + 0xa98);
          local_68 = *(undefined8 *)(param_1 + 0xa80);
          uStack_60 = *(undefined8 *)(param_1 + 0xa88);
          local_78 = *(undefined8 *)(param_1 + 0xaa0);
          uStack_70 = *(undefined8 *)(param_1 + 0xaa8);
          VmbusTraceInfoChannelStateChange
                    (&local_78,&local_68,&local_58,(ulonglong)*(ushort *)(param_1 + 0xc90),
                     *(undefined4 *)(param_1 + 0x898),*(undefined4 *)(param_1 + 0x89c),
                     *(undefined4 *)(param_1 + 0x8a8),0x3e1);
        }
        uVar8 = 0x3e2;
        goto LAB_14001649a;
      }
    }
    KmclpRundownChannelStateAndUnlock(param_1,param_2,param_3);
  }
LAB_1400164a8:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
              &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1,param_2);
  }
  if (5 < DAT_140020050) {
    cVar2 = _tlgKeywordOn(0x140020050,4);
    if (cVar2 != '\0') {
      if (param_2 == '\0') {
        pcVar10 = "Wait: false";
      }
      VmbusTraceVerbRundownFnStop
                ("KmclpPauseChannel",0x3f4,param_1 + 0x6ec,*(undefined2 *)(param_1 + 0xc90),
                 *(uint *)(param_1 + 0x898),*(int *)(param_1 + 0x89c),
                 *(undefined4 *)(param_1 + 0x8a8),pcVar10);
    }
  }
  return;
}



===== KmclpSignalWaiters @ 14001657c =====

void KmclpSignalWaiters(longlong param_1)

{
  longlong lVar1;
  
  while (param_1 != 0) {
    lVar1 = *(longlong *)(param_1 + 0x18);
    KeSetEvent(param_1,0,0);
    param_1 = lVar1;
  }
  return;
}



===== KmclpVmbusArrivalNotification @ 1400165b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140016833) */
/* WARNING: Removing unreachable block (ram,0x00014001684a) */
/* WARNING: Removing unreachable block (ram,0x000140016856) */
/* WARNING: Removing unreachable block (ram,0x000140016860) */

undefined8 KmclpVmbusArrivalNotification(longlong param_1,longlong *param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  uint uVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  ulonglong uVar7;
  undefined2 uVar8;
  undefined **ppuVar9;
  undefined8 uVar10;
  longlong *plVar11;
  bool bVar12;
  undefined1 auStackY_118 [32];
  undefined1 uVar13;
  undefined1 local_e0 [16];
  longlong local_d0;
  longlong local_c8;
  short local_bc;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_118;
  uVar10 = 0xb0;
  memset(local_e0,0,0xb0);
  lVar6 = 0;
  bVar12 = (void *)param_2[0x14a] != SystemReserved1[0xf];
  if (bVar12) {
    KmclLockChannel((longlong)param_2);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,uVar10,param_2,(char)param_2[0x113]);
  }
  if (((int)param_2[0x14b] != 0x103) || ((int)param_2[0x113] != 1)) {
LAB_140016a15:
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,uVar10,param_2,(char)param_2[0x113])
      ;
    }
    if (bVar12) {
      KmclUnlockChannel((longlong)param_2);
    }
    return 0;
  }
  lVar5 = *(longlong *)(param_1 + 4) + -0x11d046f0cb3a4004;
  if (lVar5 == 0) {
    lVar5 = *(longlong *)(param_1 + 0xc) + -0x3f05139760008fb0;
  }
  if (lVar5 != 0) goto LAB_140016a15;
  plVar1 = param_2 + 0x14e;
  plVar2 = param_2 + 0x14f;
  uVar3 = IoGetDeviceObjectPointer(*(undefined8 *)(param_1 + 0x28),0x1f01ff,plVar2,plVar1);
  plVar11 = (longlong *)(ulonglong)uVar3;
  if ((int)uVar3 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      lVar6 = 0;
      plVar11 = (longlong *)&WPP_a989f33e64883200e74810d340c3677a_Traceguids;
      WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
                &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_2,(char)uVar3);
    }
    goto LAB_140016716;
  }
  ObfReferenceObject(*plVar1);
  lVar6 = IoGetDeviceAttachmentBaseRef(*plVar1);
  IoGetDeviceProperty(lVar6);
  plVar11 = (longlong *)0x0;
  ppuVar9 = (undefined **)0x3ec024;
  uVar7 = KmclpSynchronousIoControl((longlong)param_2,0x3ec024,0,0,local_e0,0xb0);
  iVar4 = (int)uVar7;
  if (iVar4 < 0) {
    ppuVar9 = &WPP_GLOBAL_Control;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_140016757;
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_14001671b;
    uVar8 = 0x30;
    uVar13 = (undefined1)uVar7;
LAB_1400168cf:
    plVar11 = (longlong *)&WPP_a989f33e64883200e74810d340c3677a_Traceguids;
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
              &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_2,uVar13);
LAB_14001671b:
    ppuVar9 = &WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      plVar11 = (longlong *)&WPP_a989f33e64883200e74810d340c3677a_Traceguids;
      ppuVar9 = (undefined **)0x33;
      WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x33,
                &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_2,(char)iVar4);
    }
  }
  else {
    lVar5 = *(longlong *)((longlong)param_2 + 0x6ec);
    if (lVar5 == 0) {
      lVar5 = *(longlong *)((longlong)param_2 + 0x6f4);
    }
    if (lVar5 == 0) {
      if (local_bc == 0) goto LAB_14001694c;
LAB_140016716:
      iVar4 = 0x103;
      goto LAB_14001671b;
    }
    local_d0 = *(longlong *)((longlong)param_2 + 0x6ec) - local_d0;
    if (local_d0 == 0) {
      local_d0 = *(longlong *)((longlong)param_2 + 0x6f4) - local_c8;
    }
    if ((local_d0 != 0) || ((short)param_2[0x192] != local_bc)) goto LAB_140016716;
LAB_14001694c:
    iVar4 = VmbusSendInterfaceQuery((longlong)param_2);
    if (-1 < iVar4) {
      if (bVar12) {
        uVar7 = KmclpClientOpenChannel(param_2);
        iVar4 = (int)uVar7;
        if (iVar4 < 0) {
          if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
            if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              uVar8 = 0x32;
              goto LAB_14001698b;
            }
            goto LAB_14001671b;
          }
          goto LAB_140016757;
        }
      }
      iVar4 = 0;
      goto LAB_14001671b;
    }
    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        uVar8 = 0x31;
LAB_14001698b:
        uVar13 = (undefined1)iVar4;
        goto LAB_1400168cf;
      }
      goto LAB_14001671b;
    }
  }
LAB_140016757:
  *(int *)(param_2 + 0x14b) = iVar4;
  if (iVar4 != 0) {
    VmbusDropInterface((longlong)param_2);
    if (*plVar1 != 0) {
      ObfDereferenceObject();
      *plVar1 = 0;
    }
    if (*plVar2 != 0) {
      ObfDereferenceObject();
      *plVar2 = 0;
    }
  }
  if (bVar12) {
    if (iVar4 != 0x103) {
      if (param_2[0x149] != 0) {
        IoUnregisterPlugPlayNotificationEx();
        param_2[0x149] = 0;
      }
      if (iVar4 == 0) {
        KmclpResumePausedChannelAndUnlock(param_2,ppuVar9,plVar11);
        goto LAB_1400169ff;
      }
    }
    KmclUnlockChannel((longlong)param_2);
    if (iVar4 < 0) {
      (*(code *)param_2[0x10b])(param_2,iVar4);
    }
  }
LAB_1400169ff:
  if (lVar6 == 0) {
    return 0;
  }
  ObfDereferenceObject(lVar6);
  return 0;
}



===== KmclpWaitForActionCompleted @ 140016a90 =====

undefined8 KmclpWaitForActionCompleted(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  IoQueueWorkItem(*(undefined8 *)(param_3 + 0xab8),KmclpWaitForActionWorkerRoutine,1,param_3);
  return 0xc0000016;
}



===== VmbChannelDisable @ 140016ad0 =====

void VmbChannelDisable(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
                    /* 0x16ad0  12  VmbChannelDisable */
  KmclpDisableChannel(param_1,'\x01',param_3);
  return;
}



===== VmbChannelGetServicingState @ 140016af0 =====

bool VmbChannelGetServicingState(longlong param_1,undefined8 param_2,undefined8 param_3)

{
                    /* 0x16af0  25  VmbChannelGetServicingState */
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,param_3,param_1,
              (char)*(undefined4 *)(param_1 + 0x898));
  }
  return *(int *)(param_1 + 0x898) == 0xc;
}



===== VmbChannelSetInterruptLatency @ 140016b50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VmbChannelSetInterruptLatency(longlong param_1)

{
                    /* 0x16b50  72  VmbChannelSetInterruptLatency */
  (**(code **)(param_1 + 0xa20))(*(undefined8 *)(param_1 + 0x910));
  return;
}



===== VmbChannelSetServicingState @ 140016b80 =====

undefined8 VmbChannelSetServicingState(longlong param_1,char param_2,undefined8 param_3)

{
  int *piVar1;
  longlong *plVar2;
  longlong *plVar3;
  int iVar4;
  longlong *plVar5;
  int iVar6;
  ulonglong uVar7;
  longlong lVar8;
  uint uVar9;
  undefined8 uVar10;
  undefined4 uVar11;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  longlong local_68;
  longlong lStack_60;
  longlong local_58;
  longlong lStack_50;
  longlong local_48;
  longlong lStack_40;
  
                    /* 0x16b80  76  VmbChannelSetServicingState */
  KmclLockChannel(param_1);
  iVar4 = *(int *)(param_1 + 0x898);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qLd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,param_3,param_1,(char)iVar4,param_2);
  }
  uVar10 = 0;
  if ((*(char *)(param_1 + 0xad9) == '\0') && (*(int *)(param_1 + 0x108) == 0)) {
    if (param_2 == '\0') {
      if ((iVar4 != 0xc) || (*(longlong *)(param_1 + 0xc80) == 0)) goto LAB_140016ec0;
      uVar11 = 4;
    }
    else {
      if (iVar4 != 4) goto LAB_140016ec0;
      uVar11 = 0xc;
      KmclChannelCleanupParentDevice(param_1);
    }
    *(undefined4 *)(param_1 + 0x898) = uVar11;
    LOCK();
    piVar1 = (int *)(param_1 + 0xca0);
    iVar6 = *piVar1;
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    uVar9 = iVar6 + 1;
    uVar7 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar7 == 0) {
      iVar6 = (int)((ulonglong)((longlong)(int)uVar9 * -0x2aaaaaab) >> 0x20);
      iVar6 = ((iVar6 >> 2) - (iVar6 >> 0x1f)) * 0x18;
    }
    else {
      iVar6 = (uVar9 / 0x18) * -0x18;
    }
    lVar8 = (longlong)(int)(uVar9 + iVar6);
    *(undefined1 *)(param_1 + 0xca4 + lVar8 * 6) = *(undefined1 *)(param_1 + 0x898);
    *(undefined1 *)(param_1 + 0xca5 + lVar8 * 6) = *(undefined1 *)(param_1 + 0x89c);
    *(short *)(param_1 + 0xca6 + lVar8 * 6) = (short)*(undefined4 *)(param_1 + 0x8a8);
    *(undefined2 *)(param_1 + 0xca8 + lVar8 * 6) = 0x33d;
    if (4 < DAT_140020050) {
      local_98 = *(undefined8 *)(param_1 + 0xa90);
      uStack_90 = *(undefined8 *)(param_1 + 0xa98);
      local_88 = *(undefined8 *)(param_1 + 0xa80);
      uStack_80 = *(undefined8 *)(param_1 + 0xa88);
      local_78 = *(undefined8 *)(param_1 + 0xaa0);
      uStack_70 = *(undefined8 *)(param_1 + 0xaa8);
      VmbusTraceInfoChannelStateChange
                (&local_78,&local_88,&local_98,(ulonglong)*(ushort *)(param_1 + 0xc90),
                 *(undefined4 *)(param_1 + 0x898),*(undefined4 *)(param_1 + 0x89c),
                 *(undefined4 *)(param_1 + 0x8a8),0x33d);
    }
    plVar2 = (longlong *)(param_1 + 0xc60);
    if ((longlong *)*plVar2 != plVar2) {
      KeEnterCriticalRegion();
      ExAcquireFastMutexUnsafe(param_1 + 0xc28);
      for (plVar5 = (longlong *)*plVar2; plVar5 != plVar2; plVar5 = (longlong *)*plVar5) {
        if (iVar4 == 4) {
          KmclChannelCleanupParentDevice((longlong)(plVar5 + -0x18e));
        }
        *(undefined4 *)(plVar5 + -0x7b) = uVar11;
        LOCK();
        plVar3 = plVar5 + 6;
        lVar8 = *plVar3;
        *(int *)plVar3 = (int)*plVar3 + 1;
        UNLOCK();
        uVar9 = (int)lVar8 + 1;
        uVar7 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar7 == 0) {
          iVar6 = (int)((ulonglong)((longlong)(int)uVar9 * -0x2aaaaaab) >> 0x20);
          iVar6 = ((iVar6 >> 2) - (iVar6 >> 0x1f)) * 0x18;
        }
        else {
          iVar6 = (uVar9 / 0x18) * -0x18;
        }
        lVar8 = (longlong)(int)(uVar9 + iVar6);
        *(char *)((longlong)plVar5 + lVar8 * 6 + 0x34) = (char)plVar5[-0x7b];
        *(undefined1 *)((longlong)plVar5 + lVar8 * 6 + 0x35) =
             *(undefined1 *)((longlong)plVar5 + -0x3d4);
        *(short *)((longlong)plVar5 + lVar8 * 6 + 0x36) = (short)plVar5[-0x79];
        *(undefined2 *)((longlong)plVar5 + lVar8 * 6 + 0x38) = 0x359;
        if (4 < DAT_140020050) {
          local_68 = plVar5[-0x3c];
          lStack_60 = plVar5[-0x3b];
          local_58 = plVar5[-0x3e];
          lStack_50 = plVar5[-0x3d];
          local_48 = plVar5[-0x3a];
          lStack_40 = plVar5[-0x39];
          VmbusTraceInfoChannelStateChange
                    (&local_48,&local_58,&local_68,(ulonglong)*(ushort *)(plVar5 + 4),
                     (int)plVar5[-0x7b],*(undefined4 *)((longlong)plVar5 + -0x3d4),
                     (int)plVar5[-0x79],0x359);
        }
      }
      ExReleaseFastMutexUnsafe(param_1 + 0xc28);
      KeLeaveCriticalRegion();
    }
  }
  else {
LAB_140016ec0:
    uVar10 = 0xc0000184;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,param_3,param_1,(char)iVar4);
    }
  }
  KmclUnlockChannel(param_1);
  return uVar10;
}



===== WPP_SF_qL @ 140016f20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qL(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_2,&local_res20,8,
             &param_5,4,0);
  return;
}



===== WPP_SF_qLLd @ 140016f78 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qLLd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_2,&local_res20,8,
             &param_5,4,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_qL_guid__guid_ @ 140016fec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qL_guid__guid_
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined8 param_6,undefined8 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_a989f33e64883200e74810d340c3677a_Traceguids,0x1e,&local_res20,8,
             &param_5,4,param_6,0x10,param_7,0x10,0);
  return;
}



===== WPP_SF_qLd @ 14001706c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qLd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_2,&local_res20,8,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_qLd_guid__guid_ @ 1400170d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qLd_guid__guid_
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,undefined8 param_7,undefined8 param_8)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_a989f33e64883200e74810d340c3677a_Traceguids,10,&local_res20,8,
             &param_5,4,&param_6,4,param_7,0x10,param_8,0x10,0);
  return;
}



===== WPP_SF_qLdd @ 140017164 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qLdd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_a989f33e64883200e74810d340c3677a_Traceguids,0x1f,&local_res20,8,
             &param_5,4,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_qLqd @ 1400171d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qLqd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_a989f33e64883200e74810d340c3677a_Traceguids,0x11,&local_res20,8,
             &param_5,4,&param_6,8,&param_7,4,0);
  return;
}



===== WPP_SF_q_guid_q @ 14001724c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q_guid_q(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                    undefined8 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_2,&local_res20,8,
             param_5,0x10,&param_6,8,0);
  return;
}



===== LockChildPagesCompletionRoutineInternal @ 1400172c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void LockChildPagesCompletionRoutineInternal(longlong param_1,undefined4 param_2)

{
  undefined8 uVar1;
  code *pcVar2;
  
  uVar1 = *(undefined8 *)(param_1 + -8);
  pcVar2 = *(code **)(param_1 + -0x10);
  ExFreePoolWithTag((undefined8 *)(param_1 + -0x10),0x636d6b56);
  (*pcVar2)(uVar1,param_2);
  return;
}



===== VmbChannelAllocateBounceBuffer @ 140017320 =====

uint VmbChannelAllocateBounceBuffer(longlong param_1,undefined8 param_2)

{
  uint uVar1;
  
                    /* 0x17320  4  VmbChannelAllocateBounceBuffer */
  if (*(char *)(param_1 + 0x6c0) == '\0') {
    uVar1 = KmclpAllocateBounceBlock(param_1,param_2,1);
  }
  else {
    uVar1 = 0xc00000bb;
  }
  return uVar1;
}



===== VmbChannelAllocateForStorage @ 140017350 =====

int VmbChannelAllocateForStorage(longlong param_1)

{
                    /* 0x17350  5  VmbChannelAllocateForStorage */
  if (*(char *)(param_1 + 0x6c0) == '\0') {
    return (-(uint)(*(int *)(param_1 + 0x898) != 0) & 0x34) + 0xc00000bb;
  }
  return -0x3fffff45;
}



===== VmbChannelCreateGpadl @ 140017380 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VmbChannelCreateGpadl
               (longlong param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  int iVar1;
  
                    /* 0x17380  7  VmbChannelCreateGpadl */
  iVar1 = (**(code **)(param_1 + 0x940))(*(undefined8 *)(param_1 + 0x910),param_3,param_4);
  if (-1 < iVar1) {
    LOCK();
    *(int *)(param_1 + 0xad0) = *(int *)(param_1 + 0xad0) + 1;
    UNLOCK();
  }
  return;
}



===== VmbChannelCreateGpadlFromBuffer @ 1400173c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VmbChannelCreateGpadlFromBuffer
               (longlong param_1,uint param_2,undefined8 param_3,undefined4 param_4,
               undefined8 param_5)

{
  int iVar1;
  
                    /* 0x173c0  8  VmbChannelCreateGpadlFromBuffer */
  iVar1 = (**(code **)(param_1 + 0x948))
                    (*(undefined8 *)(param_1 + 0x910),param_3,param_4,(~param_2 & 1) * 2,param_5);
  if (-1 < iVar1) {
    LOCK();
    *(int *)(param_1 + 0xad0) = *(int *)(param_1 + 0xad0) + 1;
    UNLOCK();
  }
  return;
}



===== VmbChannelCreateGpadlFromMdl @ 140017420 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VmbChannelCreateGpadlFromMdl
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined4 param_5,undefined8 param_6)

{
  int iVar1;
  
                    /* 0x17420  9  VmbChannelCreateGpadlFromMdl */
  iVar1 = (**(code **)(param_1 + 0x958))
                    (*(undefined8 *)(param_1 + 0x910),param_3,param_4,param_5,param_6);
  if (-1 < iVar1) {
    LOCK();
    *(int *)(param_1 + 0xad0) = *(int *)(param_1 + 0xad0) + 1;
    UNLOCK();
  }
  return;
}



===== VmbChannelCreateGpadlFromPfnList @ 140017470 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
VmbChannelCreateGpadlFromPfnList
          (longlong param_1,undefined8 param_2,longlong param_3,int param_4,undefined8 param_5)

{
  undefined8 uVar1;
  
                    /* 0x17470  10  VmbChannelCreateGpadlFromPfnList */
  if (*(char *)(param_1 + 0x6c0) == '\0') {
    if ((param_3 == 0) || (param_4 == 0)) {
      uVar1 = 0xc00000f1;
    }
    else {
      uVar1 = (**(code **)(param_1 + 0x950))
                        (*(undefined8 *)(param_1 + 0x910),param_3,param_4,param_5);
      if (-1 < (int)uVar1) {
        LOCK();
        *(int *)(param_1 + 0xad0) = *(int *)(param_1 + 0xad0) + 1;
        UNLOCK();
      }
    }
  }
  else {
    uVar1 = 0xc00000ef;
  }
  return uVar1;
}



===== VmbChannelDeleteGpadl @ 1400174e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VmbChannelDeleteGpadl(longlong param_1)

{
                    /* 0x174e0  11  VmbChannelDeleteGpadl */
  LOCK();
  *(int *)(param_1 + 0xad0) = *(int *)(param_1 + 0xad0) + -1;
  UNLOCK();
  (**(code **)(param_1 + 0x968))(*(undefined8 *)(param_1 + 0x910));
  return;
}



===== VmbChannelGetInterfaceInstance @ 140017510 =====

void VmbChannelGetInterfaceInstance(longlong param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
                    /* 0x17510  16  VmbChannelGetInterfaceInstance */
  uVar1 = *(undefined8 *)(param_1 + 0xa98);
  *param_2 = *(undefined8 *)(param_1 + 0xa90);
  param_2[1] = uVar1;
  return;
}



===== VmbChannelGetMmioSpace @ 140017530 =====

void VmbChannelGetMmioSpace(longlong param_1,undefined8 *param_2,undefined8 *param_3)

{
                    /* 0x17530  17  VmbChannelGetMmioSpace */
  *param_2 = *(undefined8 *)(param_1 + 0xbc8);
  *param_3 = *(undefined8 *)(param_1 + 0xbd0);
  return;
}



===== VmbChannelGetNodeNumber @ 140017550 =====

undefined2 VmbChannelGetNodeNumber(longlong param_1)

{
                    /* 0x17550  18  VmbChannelGetNodeNumber */
  return *(undefined2 *)(param_1 + 0xc88);
}



===== VmbChannelGetNumaNodeMap @ 140017560 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VmbChannelGetNumaNodeMap(longlong param_1)

{
                    /* 0x17560  19  VmbChannelGetNumaNodeMap */
  (**(code **)(param_1 + 0x9d8))(*(undefined8 *)(param_1 + 0x910));
  return;
}



===== VmbChannelGetOfferData @ 1400175a0 =====

void VmbChannelGetOfferData(longlong param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
                    /* 0x175a0  20  VmbChannelGetOfferData */
  uVar1 = *(undefined8 *)(param_1 + 0x728);
  *param_2 = *(undefined8 *)(param_1 + 0x720);
  param_2[1] = uVar1;
  uVar1 = *(undefined8 *)(param_1 + 0x738);
  param_2[2] = *(undefined8 *)(param_1 + 0x730);
  param_2[3] = uVar1;
  uVar1 = *(undefined8 *)(param_1 + 0x748);
  param_2[4] = *(undefined8 *)(param_1 + 0x740);
  param_2[5] = uVar1;
  uVar1 = *(undefined8 *)(param_1 + 0x758);
  param_2[6] = *(undefined8 *)(param_1 + 0x750);
  param_2[7] = uVar1;
  uVar1 = *(undefined8 *)(param_1 + 0x768);
  param_2[8] = *(undefined8 *)(param_1 + 0x760);
  param_2[9] = uVar1;
  uVar1 = *(undefined8 *)(param_1 + 0x778);
  param_2[10] = *(undefined8 *)(param_1 + 0x770);
  param_2[0xb] = uVar1;
  uVar1 = *(undefined8 *)(param_1 + 0x788);
  param_2[0xc] = *(undefined8 *)(param_1 + 0x780);
  param_2[0xd] = uVar1;
  param_2[0xe] = *(undefined8 *)(param_1 + 0x790);
  return;
}



===== VmbChannelGetPacketDescriptor @ 140017610 =====

void VmbChannelGetPacketDescriptor(longlong param_1,int *param_2)

{
                    /* 0x17610  21  VmbChannelGetPacketDescriptor */
  if (param_2 != (int *)0x0) {
    *param_2 = (uint)*(ushort *)(param_1 + 0xa4) << 3;
  }
  return;
}



===== VmbChannelGetParentDeviceObject @ 140017630 =====

void VmbChannelGetParentDeviceObject(longlong param_1,undefined8 *param_2)

{
                    /* 0x17630  22  VmbChannelGetParentDeviceObject */
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = *(undefined8 *)(param_1 + 0xc80);
  }
  return;
}



===== VmbChannelGetRingBuffer @ 140017650 =====

void VmbChannelGetRingBuffer
               (longlong param_1,longlong *param_2,int *param_3,longlong *param_4,int *param_5)

{
  int iVar1;
  
                    /* 0x17650  24  VmbChannelGetRingBuffer */
  if (*(char *)(param_1 + 0x6c0) == '\0') {
    *param_4 = *(longlong *)(param_1 + 0xa60);
    iVar1 = *(int *)(param_1 + 0xa6c);
    *param_5 = iVar1;
    *param_2 = (ulonglong)(uint)(iVar1 << 0xc) + *param_4;
    *param_3 = *(int *)(param_1 + 0xa68);
    return;
  }
  *param_2 = *(longlong *)(param_1 + 0xa60);
  iVar1 = *(int *)(param_1 + 0xa68);
  *param_3 = iVar1;
  *param_4 = (ulonglong)(uint)(iVar1 << 0xc) + *param_2;
  *param_5 = *(int *)(param_1 + 0xa6c);
  return;
}



===== VmbChannelGetSystemAddressForGpadl @ 1400176c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint VmbChannelGetSystemAddressForGpadl
               (longlong param_1,undefined8 param_2,undefined4 param_3,longlong *param_4)

{
                    /* 0x176c0  27  VmbChannelGetSystemAddressForGpadl */
  (**(code **)(param_1 + 0x960))(*(undefined8 *)(param_1 + 0x910),param_3,param_4);
  return ~-(uint)(*param_4 != 0) & 0xc000009a;
}



===== VmbChannelGetTargetDeviceObject @ 140017700 =====

void VmbChannelGetTargetDeviceObject(longlong param_1,undefined8 *param_2)

{
                    /* 0x17700  28  VmbChannelGetTargetDeviceObject */
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = *(undefined8 *)(param_1 + 0xa70);
  }
  return;
}



===== VmbChannelGetTargetProcessorIndex @ 140017720 =====

undefined4 VmbChannelGetTargetProcessorIndex(longlong param_1)

{
                    /* 0x17720  29  VmbChannelGetTargetProcessorIndex */
  return *(undefined4 *)(param_1 + 0xc8c);
}



===== VmbChannelGetVMBusInterface @ 140017730 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 VmbChannelGetVMBusInterface(longlong param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  longlong lVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  undefined8 uVar10;
  
                    /* 0x17730  30  VmbChannelGetVMBusInterface */
  uVar10 = 0;
  if (*(longlong *)(param_1 + 0x910) == 0) {
    memset(param_2,0,0x140);
    uVar10 = 0xc00002b9;
  }
  else {
    lVar7 = 2;
    puVar5 = param_2;
    puVar6 = (undefined8 *)(param_1 + 0x908);
    do {
      puVar9 = puVar6;
      puVar8 = puVar5;
      uVar4 = puVar9[1];
      *puVar8 = *puVar9;
      puVar8[1] = uVar4;
      uVar4 = puVar9[3];
      puVar8[2] = puVar9[2];
      puVar8[3] = uVar4;
      uVar4 = puVar9[5];
      puVar8[4] = puVar9[4];
      puVar8[5] = uVar4;
      uVar4 = puVar9[7];
      puVar8[6] = puVar9[6];
      puVar8[7] = uVar4;
      uVar4 = puVar9[9];
      puVar8[8] = puVar9[8];
      puVar8[9] = uVar4;
      uVar4 = puVar9[0xb];
      puVar8[10] = puVar9[10];
      puVar8[0xb] = uVar4;
      uVar4 = puVar9[0xd];
      puVar8[0xc] = puVar9[0xc];
      puVar8[0xd] = uVar4;
      uVar4 = puVar9[0xf];
      puVar8[0xe] = puVar9[0xe];
      puVar8[0xf] = uVar4;
      lVar7 = lVar7 + -1;
      puVar5 = puVar8 + 0x10;
      puVar6 = puVar9 + 0x10;
    } while (lVar7 != 0);
    uVar4 = puVar9[0x11];
    puVar8[0x10] = puVar9[0x10];
    puVar8[0x11] = uVar4;
    uVar4 = puVar9[0x13];
    puVar8[0x12] = puVar9[0x12];
    puVar8[0x13] = uVar4;
    uVar1 = *(undefined4 *)((longlong)puVar9 + 0xa4);
    uVar2 = *(undefined4 *)(puVar9 + 0x15);
    uVar3 = *(undefined4 *)((longlong)puVar9 + 0xac);
    *(undefined4 *)(puVar8 + 0x14) = *(undefined4 *)(puVar9 + 0x14);
    *(undefined4 *)((longlong)puVar8 + 0xa4) = uVar1;
    *(undefined4 *)(puVar8 + 0x15) = uVar2;
    *(undefined4 *)((longlong)puVar8 + 0xac) = uVar3;
    uVar1 = *(undefined4 *)((longlong)puVar9 + 0xb4);
    uVar2 = *(undefined4 *)(puVar9 + 0x17);
    uVar3 = *(undefined4 *)((longlong)puVar9 + 0xbc);
    *(undefined4 *)(puVar8 + 0x16) = *(undefined4 *)(puVar9 + 0x16);
    *(undefined4 *)((longlong)puVar8 + 0xb4) = uVar1;
    *(undefined4 *)(puVar8 + 0x17) = uVar2;
    *(undefined4 *)((longlong)puVar8 + 0xbc) = uVar3;
    (*(code *)param_2[2])(param_2[1]);
  }
  return uVar10;
}



===== VmbChannelGetVaBackingProcess @ 140017800 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VmbChannelGetVaBackingProcess(longlong param_1)

{
                    /* 0x17800  31  VmbChannelGetVaBackingProcess */
  (**(code **)(param_1 + 0xa18))(*(undefined8 *)(param_1 + 0x910));
  return;
}



===== VmbChannelGetVirtualProcessorCount @ 140017830 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 VmbChannelGetVirtualProcessorCount(longlong param_1)

{
  undefined4 local_res8 [8];
  
                    /* 0x17830  32  VmbChannelGetVirtualProcessorCount */
  local_res8[0] = 0;
  (**(code **)(param_1 + 0x9d8))(*(undefined8 *)(param_1 + 0x910),0,0,0,local_res8);
  return local_res8[0];
}



===== VmbChannelLockChildPages @ 140017870 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong VmbChannelLockChildPages
                    (longlong param_1,undefined8 param_2,undefined8 param_3,char param_4,
                    undefined4 param_5,undefined8 param_6,undefined8 param_7)

{
  uint uVar1;
  undefined8 *puVar2;
  ulonglong uVar3;
  undefined7 in_register_00000089;
  ulonglong local_res8;
  
                    /* 0x17870  48  VmbChannelLockChildPages */
  local_res8 = 0;
  uVar3 = (**(code **)(param_1 + 0x9e8))
                    (*(undefined8 *)(param_1 + 0x910),&local_res8,param_3,
                     CONCAT71(in_register_00000089,param_4));
  if (-1 < (int)uVar3) {
    puVar2 = (undefined8 *)ExAllocatePool2(0x40,(local_res8 & 0xffffffff) + 0x10,0x636d6b56);
    if (puVar2 == (undefined8 *)0x0) {
      uVar3 = 0xc000009a;
    }
    else {
      *puVar2 = param_2;
      puVar2[1] = param_3;
      uVar1 = (**(code **)(param_1 + 0x9f0))
                        (*(undefined8 *)(param_1 + 0x910),puVar2 + 2,
                         LockChildPagesCompletionRoutineInternal,2 - (uint)(param_4 != '\0'),param_6
                         ,param_7,param_5);
      uVar3 = (ulonglong)uVar1;
      if (uVar1 != 0x103) {
        *puVar2 = 0;
        puVar2[1] = 0;
        ExFreePoolWithTag(puVar2,0x636d6b56);
      }
    }
  }
  return uVar3;
}



===== VmbChannelMapChildMmioSpace @ 140017980 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VmbChannelMapChildMmioSpace(longlong param_1)

{
                    /* 0x17980  49  VmbChannelMapChildMmioSpace */
  (**(code **)(param_1 + 0xa00))(*(undefined8 *)(param_1 + 0x910));
  return;
}



===== VmbChannelMapChildVaSpace @ 1400179b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VmbChannelMapChildVaSpace
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4,
               undefined4 param_5,undefined4 param_6,undefined8 param_7,undefined8 param_8)

{
  undefined8 local_28;
  ulonglong uStack_20;
  undefined8 local_18;
  
                    /* 0x179b0  50  VmbChannelMapChildVaSpace */
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if (param_4 != (undefined8 *)0x0) {
    local_28 = *param_4;
    uStack_20 = (ulonglong)*(uint *)(param_4 + 1);
    local_18 = param_4[2];
  }
  (**(code **)(param_1 + 0xa10))
            (*(undefined8 *)(param_1 + 0x910),param_2,param_3,
             -(ulonglong)(param_4 != (undefined8 *)0x0) & (ulonglong)&local_28,param_5,param_6,
             param_7,param_8);
  return;
}



===== VmbChannelMapGpadl @ 140017a50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VmbChannelMapGpadl(longlong param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  
                    /* 0x17a50  51  VmbChannelMapGpadl */
  iVar1 = (**(code **)(param_1 + 0x970))
                    (*(undefined8 *)(param_1 + 0x910),param_3,(~param_2 & 1) + 1);
  if (-1 < iVar1) {
    LOCK();
    *(int *)(param_1 + 0xad4) = *(int *)(param_1 + 0xad4) + 1;
    UNLOCK();
  }
  return;
}



===== VmbChannelPacketDeferToPassive @ 140017aa0 =====

void VmbChannelPacketDeferToPassive(longlong *param_1)

{
                    /* 0x17aa0  53  VmbChannelPacketDeferToPassive */
  *(undefined4 *)(*param_1 + 0x584) = 3;
  return;
}



===== VmbChannelPacketDeferUntilPolled @ 140017ac0 =====

void VmbChannelPacketDeferUntilPolled(longlong *param_1)

{
                    /* 0x17ac0  54  VmbChannelPacketDeferUntilPolled
                       0x17ac0  56  VmbChannelPacketFail */
  *(undefined4 *)(*param_1 + 0x584) = 2;
  return;
}



===== VmbChannelSetIncomingPollOnCompletion @ 140017ae0 =====

void VmbChannelSetIncomingPollOnCompletion(longlong param_1,char param_2)

{
                    /* 0x17ae0  70  VmbChannelSetIncomingPollOnCompletion */
  *(bool *)(param_1 + 0x4b0) = param_2 != '\0';
  return;
}



===== VmbChannelSetIncomingProcessingAtPassive @ 140017b00 =====

void VmbChannelSetIncomingProcessingAtPassive(longlong param_1,char param_2)

{
                    /* 0x17b00  71  VmbChannelSetIncomingProcessingAtPassive */
  *(bool *)(param_1 + 0x4b2) = param_2 != '\0';
  if (param_2 != '\0') {
    *(undefined1 *)(param_1 + 0x4b1) = 1;
  }
  return;
}



===== VmbChannelSetInterruptPolicy @ 140017b20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 VmbChannelSetInterruptPolicy(longlong param_1,int *param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
                    /* 0x17b20  73  VmbChannelSetInterruptPolicy */
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  iVar1 = *param_2;
  uStack_20 = 0;
  if (iVar1 == 1) {
    local_28 = 1;
  }
  else {
    if (iVar1 == 2) {
      local_28._0_4_ = 2;
    }
    else {
      if (iVar1 == 3) {
        uStack_20 = *(undefined8 *)(param_2 + 2);
        local_28 = CONCAT44(param_2[1],3);
        goto LAB_140017b98;
      }
      if (iVar1 != 4) {
        return 0xc000000d;
      }
      local_28._0_4_ = 4;
    }
    local_28 = CONCAT44(param_2[1],(undefined4)local_28);
  }
LAB_140017b98:
  uVar2 = (**(code **)(param_1 + 0x9d0))(*(undefined8 *)(param_1 + 0x910),&local_28);
  return uVar2;
}



===== VmbChannelSetTransactionQuota @ 140017bd0 =====

void VmbChannelSetTransactionQuota(longlong param_1,undefined4 param_2)

{
                    /* 0x17bd0  77  VmbChannelSetTransactionQuota */
  *(undefined4 *)(param_1 + 0x574) = param_2;
  return;
}



===== VmbChannelUnlockChildPages @ 140017be0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VmbChannelUnlockChildPages
               (longlong param_1,char param_2,undefined4 param_3,undefined8 param_4,
               undefined8 param_5)

{
                    /* 0x17be0  80  VmbChannelUnlockChildPages */
  (**(code **)(param_1 + 0x9f8))
            (*(undefined8 *)(param_1 + 0x910),param_4,param_5,param_3,2 - (uint)(param_2 != '\0'));
  return;
}



===== VmbChannelUnmapChildMmioSpace @ 140017c20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VmbChannelUnmapChildMmioSpace(longlong param_1)

{
                    /* 0x17c20  81  VmbChannelUnmapChildMmioSpace */
  (**(code **)(param_1 + 0xa08))(*(undefined8 *)(param_1 + 0x910));
  return;
}



===== VmbChannelUnmapGpadl @ 140017c50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VmbChannelUnmapGpadl(longlong param_1)

{
                    /* 0x17c50  82  VmbChannelUnmapGpadl */
  LOCK();
  *(int *)(param_1 + 0xad4) = *(int *)(param_1 + 0xad4) + -1;
  UNLOCK();
  (**(code **)(param_1 + 0x978))(*(undefined8 *)(param_1 + 0x910));
  return;
}



===== VmbChannelUpdateClientContextSize @ 140017c80 =====

void VmbChannelUpdateClientContextSize(longlong *param_1,int param_2)

{
                    /* 0x17c80  83  VmbChannelUpdateClientContextSize */
  InChangeClientContextSize(param_1,param_2);
  return;
}



===== VmbChannelUpdateInterruptProcessor @ 140017ca0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VmbChannelUpdateInterruptProcessor(longlong param_1)

{
                    /* 0x17ca0  84  VmbChannelUpdateInterruptProcessor */
  (**(code **)(param_1 + 0xa28))(*(undefined8 *)(param_1 + 0x910));
  return;
}



===== DllUnload @ 140017cd0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DllUnload(void)

{
  undefined8 uVar1;
  
                    /* 0x17cd0  2  DllUnload */
  if (KmclPcChannel != 0) {
    PcwUnregister();
  }
  if (KmclPcPipeChannel != 0) {
    PcwUnregister();
  }
  if (KmclPcChannelState != 0) {
    PcwUnregister();
  }
  UninitializeTelemetryAssertsKM();
  if (DAT_140020308 != 0) {
    ExFreePoolWithTag(DAT_140020308,0x636d6b56);
    _KmclRegistryPath = 0;
    DAT_140020308 = 0;
  }
  uVar1 = DAT_140020070;
  DAT_140020070 = 0;
  DAT_140020050 = 0;
  EtwUnregister(uVar1);
  McGenEventUnregister_EtwUnregister();
  WppCleanupKm();
  wil_UninitializeFeatureStaging();
  return 0;
}



===== McGenControlCallbackV2 @ 140017d90 =====

void McGenControlCallbackV2
               (undefined8 param_1,int param_2,undefined1 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,longlong param_7)

{
  uint *puVar1;
  ulonglong uVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  
  if (param_7 != 0) {
    if (param_2 == 0) {
      *(undefined4 *)(param_7 + 0x24) = 0;
      *(undefined1 *)(param_7 + 0x28) = 0;
      *(undefined8 *)(param_7 + 0x10) = 0;
      *(undefined8 *)(param_7 + 0x18) = 0;
      if (*(ushort *)(param_7 + 0x2a) != 0) {
        memset(*(void **)(param_7 + 0x30),0,
               (longlong)((int)(*(ushort *)(param_7 + 0x2a) - 1) / 0x20 + 1) << 2);
      }
    }
    else if (param_2 == 1) {
      *(undefined1 *)(param_7 + 0x28) = param_3;
      uVar6 = 0;
      *(undefined8 *)(param_7 + 0x18) = param_5;
      *(undefined8 *)(param_7 + 0x10) = param_4;
      *(undefined4 *)(param_7 + 0x24) = 1;
      if (*(short *)(param_7 + 0x2a) != 0) {
        do {
          uVar2 = *(ulonglong *)(*(longlong *)(param_7 + 0x38) + uVar6 * 8);
          if (((*(byte *)(param_7 + 0x28) < *(byte *)(uVar6 + *(longlong *)(param_7 + 0x40))) &&
              (*(byte *)(param_7 + 0x28) != 0)) ||
             ((uVar2 != 0 &&
              (((*(ulonglong *)(param_7 + 0x10) & uVar2) == 0 ||
               ((*(ulonglong *)(param_7 + 0x18) & uVar2) != *(ulonglong *)(param_7 + 0x18))))))) {
            bVar3 = false;
          }
          else {
            bVar3 = true;
          }
          uVar4 = 1 << ((byte)uVar6 & 0x1f);
          puVar1 = (uint *)(*(longlong *)(param_7 + 0x30) + (uVar6 >> 5) * 4);
          uVar5 = *puVar1;
          if (bVar3) {
            uVar4 = uVar4 | uVar5;
          }
          else {
            uVar4 = ~uVar4 & uVar5;
          }
          *puVar1 = uVar4;
          uVar5 = (int)uVar6 + 1;
          uVar6 = (ulonglong)uVar5;
        } while (uVar5 < *(ushort *)(param_7 + 0x2a));
      }
    }
  }
  return;
}



===== McGenEventRegister_EtwRegister @ 140017ea0 =====

void McGenEventRegister_EtwRegister(void)

{
  if (VMBKMCLR_PROVIDER_Context == 0) {
    EtwRegister(&VMBKMCLR_PROVIDER,McGenControlCallbackV2,&VMBKMCLR_PROVIDER_Context,
                &VMBKMCLR_PROVIDER_Context);
  }
  return;
}



===== McGenEventUnregister_EtwUnregister @ 140017ee0 =====

undefined8 McGenEventUnregister_EtwUnregister(void)

{
  undefined8 uVar1;
  
  if (VMBKMCLR_PROVIDER_Context == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    VMBKMCLR_PROVIDER_Context = 0;
  }
  return uVar1;
}



===== WppClassicProviderCallback @ 140017f20 =====

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



===== _tlgDefineProvider_annotation__Tlgmtakm_hTelemetryAssertProv @ 140017f54 =====

void _tlgDefineProvider_annotation__Tlgmtakm_hTelemetryAssertProv(void)

{
  return;
}



===== wil_details_FeatureDescriptors_SkipPadding @ 140017f60 =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_14001ff7f < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_RecordCachedUsage @ 140017f8c =====

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



===== wil_details_RecordFeatureUsageReporting @ 1400180e0 =====

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



===== KmclpEnablePerformanceCounters @ 140018164 =====

int KmclpEnablePerformanceCounters(longlong param_1)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  char local_res10 [8];
  
  local_res10[0] = '\0';
  iVar1 = KmclpUsePerformanceCounters(local_res10);
  if ((-1 < iVar1) && (local_res10[0] != '\0')) {
    uVar2 = KmclpGetInstanceNameLength(param_1);
    lVar3 = ExAllocatePool2(0x40,uVar2 & 0xffff,0x636d6b56);
    if (lVar3 == 0) {
      iVar1 = -0x3fffff66;
    }
    else {
      ExAcquireFastMutex(&KmclPerformanceCounterLock);
      *(undefined8 *)(param_1 + 0x870) = 0;
      *(undefined8 *)(param_1 + 0x878) = 0;
      *(short *)(param_1 + 0x872) = (short)uVar2;
      *(longlong *)(param_1 + 0x878) = lVar3;
      *(int *)(param_1 + 0x880) = KmclPerformanceCounterNextID;
      KmclPerformanceCounterNextID = KmclPerformanceCounterNextID + 1;
      if (KmclPerformanceCounterNextID == 0) {
        KmclPerformanceCounterNextID = 1;
      }
      ExReleaseFastMutex(&KmclPerformanceCounterLock);
      iVar1 = 0;
    }
  }
  return iVar1;
}



===== KmclpGetInstanceNameLength @ 140018244 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint KmclpGetInstanceNameLength(longlong param_1)

{
  uint uVar1;
  int iVar2;
  ushort local_res8 [4];
  
  iVar2 = 0;
  local_res8[0] = 0;
  if (*(longlong *)(param_1 + 0x890) != 0) {
    iVar2 = *(ushort *)(param_1 + 0x888) + 2;
  }
  if (*(char *)(param_1 + 0x6c0) != '\0') {
    (**(code **)(param_1 + 0x9e0))(*(undefined8 *)(param_1 + 0x910),0,local_res8,0);
    iVar2 = iVar2 + local_res8[0] + 2;
  }
  uVar1 = (-(uint)(*(short *)(param_1 + 0xc90) != 0) & 10) + 0x4c + iVar2;
  if (0xfffe < uVar1) {
    uVar1 = 0xfffe;
  }
  return uVar1;
}



===== KmclpUsePerformanceCounters @ 1400182cc =====

int KmclpUsePerformanceCounters(char *param_1)

{
  int iVar1;
  undefined8 local_48;
  undefined1 *puStack_40;
  undefined8 local_38;
  undefined1 *puStack_30;
  code *local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_48 = 0;
  puStack_40 = (undefined1 *)0x0;
  local_18 = local_18 & 0xffffffff00000000;
  local_38 = 0;
  puStack_30 = (undefined1 *)0x0;
  local_28 = (code *)0x0;
  uStack_20 = 0;
  KeEnterCriticalRegion();
  ExAcquireFastMutexUnsafe(&KmclPerformanceCounterLock);
  if (KmclPerformanceCountersRegistered == '\0') {
    local_48 = 0x100;
    puStack_40 = &`KmclPcInitRegistrationInformationChannel'::__l2::Name;
    local_38 = 0x1c;
    puStack_30 = &`KmclPcInitRegistrationInformationChannel'::__l2::Descriptors;
    local_18 = 0;
    local_28 = KmclpStatsCallback;
    uStack_20 = 1;
    iVar1 = PcwRegister(&KmclPcChannel,&local_48);
    if ((-1 < iVar1) && (KmclPcChannel != 0)) {
      local_48 = 0x100;
      puStack_40 = &`KmclPcInitRegistrationInformationChannelState'::__l2::Name;
      local_38 = 0xc;
      puStack_30 = &`KmclPcInitRegistrationInformationChannelState'::__l2::Descriptors;
      local_18 = 0;
      local_28 = KmclpStatsCallback;
      uStack_20 = 3;
      iVar1 = PcwRegister(&KmclPcChannelState,&local_48);
      if ((-1 < iVar1) && (KmclPcChannel != 0)) {
        local_48 = 0x100;
        puStack_40 = &`KmclPcInitRegistrationInformationPipeChannel'::__l2::Name;
        local_38 = 4;
        puStack_30 = &`KmclPcInitRegistrationInformationPipeChannel'::__l2::Descriptors;
        local_18 = 0;
        local_28 = KmclpStatsCallback;
        uStack_20 = 2;
        iVar1 = PcwRegister(&KmclPcPipeChannel,&local_48);
        if ((-1 < iVar1) && (KmclPcPipeChannel != 0)) {
          KmclPerformanceCountersRegistered = '\x01';
          goto LAB_140018458;
        }
      }
    }
    iVar1 = -0x3fffffff;
  }
  else {
    iVar1 = 0;
  }
LAB_140018458:
  *param_1 = KmclPerformanceCountersRegistered;
  ExReleaseFastMutexUnsafe(&KmclPerformanceCounterLock);
  KeLeaveCriticalRegion();
  return iVar1;
}



===== RestoreFindSubChannel @ 1400184a0 =====

undefined8 RestoreFindSubChannel(longlong param_1,short *param_2,uint param_3,undefined8 *param_4)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  
  if (7 < param_3) {
    plVar3 = (longlong *)0x0;
    KeEnterCriticalRegion();
    ExAcquireFastMutexUnsafe(param_1 + 0xc28);
    plVar1 = (longlong *)(param_1 + 0xc60);
    plVar2 = (longlong *)*plVar1;
    if (plVar2 != plVar1) {
      do {
        plVar3 = plVar2 + -0x18e;
        if ((short)plVar2[4] == *param_2) break;
        plVar2 = (longlong *)*plVar2;
        plVar3 = (longlong *)0x0;
      } while (plVar2 != plVar1);
    }
    ExReleaseFastMutexUnsafe(param_1 + 0xc28);
    KeLeaveCriticalRegion();
    if (plVar3 != (longlong *)0x0) {
      *param_4 = plVar3;
      return 0;
    }
  }
  return 0xc0000102;
}



===== RestoreReadVersion @ 140018568 =====

uint RestoreReadVersion(undefined8 param_1,short *param_2,uint param_3)

{
  if (param_3 < 8) {
    return 0xc000000d;
  }
  if (*param_2 == 2) {
    return -(uint)(param_2[1] != 0) & 0xc0000059;
  }
  return 0xc0000059;
}



===== SaveCommit @ 140018598 =====

undefined8 SaveCommit(longlong *param_1)

{
  if (*(uint *)(param_1 + 1) < *(uint *)((longlong)param_1 + 0xc)) {
    return 0xc0000023;
  }
  *(uint *)((ulonglong)*(uint *)(param_1 + 2) + 4 + *param_1) =
       (*(uint *)((longlong)param_1 + 0xc) - *(uint *)(param_1 + 2)) + -0x10;
  *(int *)(param_1 + 3) = (int)param_1[3] + 1;
  *(undefined4 *)(param_1 + 2) = *(undefined4 *)((longlong)param_1 + 0xc);
  return 0;
}



===== SaveCopyRawBytes @ 1400185d4 =====

void SaveCopyRawBytes(longlong *param_1,void *param_2,uint param_3)

{
  void *_Dst;
  
  _Dst = SaveGetBuffer(param_1,param_3);
  if (_Dst != (void *)0x0) {
    memmove(_Dst,param_2,(ulonglong)param_3);
  }
  return;
}



===== SaveGetBuffer @ 140018614 =====

void * SaveGetBuffer(longlong *param_1,uint param_2)

{
  uint uVar1;
  void *_Dst;
  
  uVar1 = *(uint *)((longlong)param_1 + 0xc);
  if ((-(uint)(uVar1 < *(uint *)(param_1 + 1)) & *(uint *)(param_1 + 1) - uVar1) < param_2) {
    _Dst = (void *)0x0;
  }
  else {
    _Dst = (void *)((ulonglong)uVar1 + *param_1);
    memset(_Dst,0,(ulonglong)param_2);
  }
  *(int *)((longlong)param_1 + 0xc) = *(int *)((longlong)param_1 + 0xc) + param_2;
  return _Dst;
}



===== SaveStart @ 140018674 =====

void SaveStart(longlong *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = SaveGetBuffer(param_1,0x10);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    puVar1[2] = (int)param_1[3];
  }
  return;
}



===== SaveWriteNextSubChannel @ 1400186ac =====

undefined8 SaveWriteNextSubChannel(longlong *param_1,longlong param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined2 *puVar3;
  
  if (param_1[6] == param_2) {
    puVar1 = *(undefined8 **)(param_2 + 0xc60);
  }
  else {
    puVar1 = *(undefined8 **)(param_1[6] + 0xc70);
  }
  if (puVar1 == (undefined8 *)(param_2 + 0xc60)) {
    uVar2 = 0x8000001a;
  }
  else {
    SaveStart(param_1,0x62755353);
    puVar3 = SaveGetBuffer(param_1,8);
    if (puVar3 != (undefined2 *)0x0) {
      *puVar3 = *(undefined2 *)(puVar1 + 4);
    }
    uVar2 = SaveCommit(param_1);
    if (-1 < (int)uVar2) {
      param_1[6] = (longlong)(puVar1 + -0x18e);
      uVar2 = 0;
    }
  }
  return uVar2;
}



===== HviGetHypervisorFeatures @ 140018738 =====

/* WARNING: Removing unreachable block (ram,0x000140018751) */

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



===== HviIsAnyHypervisorPresent @ 140018778 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001400187ac) */
/* WARNING: Removing unreachable block (ram,0x00014001879b) */

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



===== HviIsHypervisorMicrosoftCompatible @ 1400187d4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000140018801) */

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



===== GetImageTuple @ 14001882c =====

/* WARNING: Removing unreachable block (ram,0x000140018862) */

undefined8 GetImageTuple(undefined8 param_1,dword *param_2,dword *param_3)

{
  *param_2 = 0xb2f9da6d;
  *param_3 = 0x33000;
  return 1;
}



===== InitializeTelemetryAssertsKM @ 14001887c =====

ulonglong InitializeTelemetryAssertsKM(ushort *param_1)

{
  uint uVar1;
  uint uVar2;
  void *_Dst;
  ulonglong uVar3;
  undefined8 local_b8;
  longlong lStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined1 local_78 [8];
  undefined4 local_70;
  wchar_t *local_68;
  undefined8 *local_60;
  undefined4 local_58;
  
  local_b8 = 0;
  lStack_b0 = 0;
  uVar3 = 0xc0000017;
  LOCK();
  UNLOCK();
  if (g_AssertsOperational == 0) {
    RtlInitAnsiString(&local_b8,0);
    _Dst = (void *)ExAllocatePool2(0x40,(ulonglong)*param_1 + 2,0x74727341);
    if (_Dst != (void *)0x0) {
      memmove(_Dst,*(void **)(param_1 + 4),(ulonglong)*param_1);
      local_a8 = 0;
      uStack_a0 = 0;
      RtlInitUnicodeString(&local_a8);
      memset(local_78,0,0x70);
      local_68 = L"ImagePath";
      local_60 = &local_a8;
      local_70 = 0x20;
      local_58 = 2;
      uVar2 = RtlQueryRegistryValuesEx(0,_Dst,local_78,0,0);
      uVar3 = (ulonglong)uVar2;
      if (-1 < (int)uVar2) {
        uVar2 = RtlUnicodeStringToAnsiString(&local_b8,&local_a8,1);
        uVar3 = (ulonglong)uVar2;
        ExFreePoolWithTag(uStack_a0,0);
        if (-1 < (int)uVar2) {
          uVar2 = (uint)(ushort)local_b8;
          do {
            uVar1 = uVar2;
            uVar2 = uVar1 - 1;
            if (uVar2 == 0) goto LAB_1400189f6;
          } while (*(char *)((ulonglong)uVar2 + lStack_b0) != '\\');
          if (uVar2 != (ushort)local_b8) {
            local_98 = 0;
            uStack_90 = 0;
            RtlInitAnsiString(&local_98,(ulonglong)uVar1 + lStack_b0);
            local_88 = local_98;
            uStack_80 = uStack_90;
            uVar3 = InitializeTelemetryAssertsKMWorkerInternal((ushort *)&local_88);
            uVar3 = uVar3 & 0xffffffff;
          }
LAB_1400189f6:
          RtlFreeAnsiString(&local_b8);
        }
      }
      ExFreePoolWithTag(_Dst,0x74727341);
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



===== InitializeTelemetryAssertsKMWorkerInternal @ 140018a3c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 InitializeTelemetryAssertsKMWorkerInternal(ushort *param_1)

{
  undefined8 uVar1;
  
  KeInitializeSpinLock(&g_AssertSpinLock);
  uVar1 = 0;
  g_ModuleName = (void *)ExAllocatePool2(0x40,(ulonglong)*param_1 + 1,0x74727341);
  if (g_ModuleName == (void *)0x0) {
    uVar1 = 0xc0000017;
  }
  else {
    memmove(g_ModuleName,*(void **)(param_1 + 4),(ulonglong)*param_1);
    _DAT_1400201e8 = &g_MicrosoftTelemetryAssertsTriggeredList;
    g_MicrosoftTelemetryAssertsTriggeredList = &g_MicrosoftTelemetryAssertsTriggeredList;
    TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(0x140025040);
    TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(0x140025008);
    TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(0x140025078);
    LOCK();
    g_AssertsOperational = g_AssertsOperational + 1;
    UNLOCK();
  }
  return uVar1;
}



===== MicrosoftTelemetryAssertTriggeredArgsKM @ 140018af0 =====

void MicrosoftTelemetryAssertTriggeredArgsKM
               (undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  IMAGE_DOS_HEADER *unaff_retaddr;
  
  MicrosoftTelemetryAssertTriggeredWorker(unaff_retaddr,1,0,param_2,param_3);
  return;
}



===== MicrosoftTelemetryAssertTriggeredWorker @ 140018b20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MicrosoftTelemetryAssertTriggeredWorker
               (IMAGE_DOS_HEADER *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined4 param_5)

{
  uint uVar1;
  code *pcVar2;
  longlong lVar3;
  undefined1 uVar4;
  char cVar5;
  byte bVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  longlong *plVar10;
  longlong *plVar11;
  undefined8 uVar12;
  longlong *plVar13;
  char *pcVar14;
  uint uVar15;
  undefined1 *puVar16;
  ulonglong uVar17;
  char *pcVar18;
  longlong lVar19;
  undefined1 auStack_1a8 [8];
  undefined1 auStack_1a0 [80];
  undefined4 local_150;
  char *local_128;
  undefined1 local_118 [32];
  undefined1 *local_f8;
  undefined8 local_f0;
  undefined1 *local_e8;
  undefined8 local_e0;
  undefined1 *local_d8;
  undefined8 local_d0;
  undefined1 *local_c8;
  undefined8 local_c0;
  longlong local_b8 [2];
  undefined1 *local_a8;
  undefined8 local_a0;
  undefined1 *local_98;
  undefined8 local_90;
  undefined1 *local_88;
  undefined8 local_80;
  longlong local_78 [2];
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  longlong local_48 [2];
  ulonglong local_38;
  
  puVar16 = auStack_1a8;
  local_38 = __security_cookie ^ (ulonglong)auStack_1a8;
  LOCK();
  UNLOCK();
  if (g_AssertsOperational == 0) goto LAB_1400190c0;
  local_150 = param_4;
  uVar4 = KeAcquireSpinLockRaiseToDpc(&g_AssertSpinLock);
  puVar16 = auStack_1a8;
  for (plVar11 = g_MicrosoftTelemetryAssertsTriggeredList;
      (longlong **)plVar11 != &g_MicrosoftTelemetryAssertsTriggeredList;
      plVar11 = (longlong *)*plVar11) {
    plVar10 = plVar11 + -4;
    if ((IMAGE_DOS_HEADER *)*plVar10 == param_1) goto LAB_140018c5d;
  }
  plVar10 = (longlong *)ExAllocatePool2(0x42,0x30,0x74727341);
  lVar19 = _DAT_fffff78000000320;
  puVar16 = auStack_1a8;
  if (plVar10 != (longlong *)0x0) {
    *plVar10 = (longlong)param_1;
    uVar7 = KeQueryTimeIncrement();
    puVar16 = auStack_1a8;
    plVar10[2] = 0;
    *(undefined4 *)(plVar10 + 3) = 0;
    plVar10[1] = (longlong)((ulonglong)uVar7 * lVar19) / 10000 + -0xea61;
    plVar11 = plVar10 + 4;
    plVar13 = g_MicrosoftTelemetryAssertsTriggeredList;
    if ((longlong **)g_MicrosoftTelemetryAssertsTriggeredList[1] !=
        &g_MicrosoftTelemetryAssertsTriggeredList) {
      plVar13 = (longlong *)0x3;
      pcVar2 = (code *)swi(0x29);
      plVar11 = (longlong *)(*pcVar2)();
      puVar16 = auStack_1a0;
    }
    *plVar11 = (longlong)plVar13;
    plVar11[1] = (longlong)&g_MicrosoftTelemetryAssertsTriggeredList;
    plVar13[1] = (longlong)plVar11;
    g_MicrosoftTelemetryAssertsTriggeredList = plVar11;
LAB_140018c5d:
    *(int *)(plVar10 + 2) = (int)plVar10[2] + 1;
    *(int *)((longlong)plVar10 + 0x14) = *(int *)((longlong)plVar10 + 0x14) + 1;
    lVar3 = _DAT_fffff78000000320;
    *(undefined8 *)(puVar16 + -8) = 0x140018c6d;
    uVar7 = KeQueryTimeIncrement();
    *(undefined4 *)(puVar16 + 0x54) = 0;
    *(undefined4 *)(puVar16 + 0x50) = 0;
    lVar19 = (longlong)((ulonglong)uVar7 * lVar3) / 10000;
    if (60000 < (ulonglong)(lVar19 - plVar10[1])) {
      *(undefined8 *)(puVar16 + -8) = 0x140018cbb;
      uVar12 = GetImageTuple((ulonglong)uVar7 * lVar3,(dword *)(puVar16 + 0x54),
                             (dword *)(puVar16 + 0x50));
      uVar7 = *(uint *)(puVar16 + 0x50);
      iVar8 = (int)uVar12;
      if ((((iVar8 == 0) || (param_1 < &IMAGE_DOS_HEADER_140000000)) ||
          ((IMAGE_DOS_HEADER *)(IMAGE_DOS_HEADER_140000000.e_magic + uVar7) <
           (IMAGE_DOS_HEADER *)(IMAGE_DOS_HEADER_140000000.e_magic + 1))) ||
         ((IMAGE_DOS_HEADER *)(IMAGE_DOS_HEADER_140000000.e_magic + uVar7) < param_1)) {
        uVar15 = 0;
      }
      else {
        uVar15 = (int)param_1 + 0xc0000000;
      }
      *(int *)(puVar16 + 0x50) = (int)plVar10[2];
      plVar10[1] = lVar19;
      lVar19 = plVar10[3];
      *(undefined4 *)(puVar16 + 0x7c) = *(undefined4 *)((longlong)plVar10 + 0x14);
      *(undefined8 *)(puVar16 + -8) = 0x140018d10;
      KeReleaseSpinLock(&g_AssertSpinLock,uVar4);
      uVar1 = *(uint *)(puVar16 + 0x54);
      local_128 = g_ModuleName;
      if (5 < DAT_140025040) {
        *(undefined8 *)(puVar16 + -8) = 0x140018d4f;
        pcVar18 = g_ModuleName;
        cVar5 = _tlgKeywordOn(0x140025040,0x400000000000);
        uVar12 = 0;
        if (cVar5 != '\0') {
          local_f8 = puVar16 + 0x54;
          *(undefined4 *)(puVar16 + 0x54) = 10;
          local_e8 = puVar16 + 0x5c;
          local_f0 = 4;
          *(uint *)(puVar16 + 0x5c) = uVar15;
          local_d8 = puVar16 + 0x60;
          local_e0 = 4;
          local_d0 = 4;
          *(uint *)(puVar16 + 0x60) = -(uint)(iVar8 != 0) & uVar1;
          local_c0 = 4;
          local_c8 = puVar16 + 100;
          *(uint *)(puVar16 + 100) = -(uint)(iVar8 != 0) & uVar7;
          pcVar14 = "<unknown>";
          if (pcVar18 != (char *)0x0) {
            pcVar14 = pcVar18;
          }
          *(undefined8 *)(puVar16 + -8) = 0x140018dd9;
          _tlgCreate1Sz_char(local_b8,pcVar14);
          local_a8 = puVar16 + 0x68;
          *(undefined4 *)(puVar16 + 0x6c) = *(undefined4 *)(puVar16 + 0x7c);
          local_98 = puVar16 + 0x6c;
          *(undefined4 *)(puVar16 + 0x68) = *(undefined4 *)(puVar16 + 0x50);
          local_a0 = 4;
          local_90 = 4;
          *(undefined8 *)(puVar16 + -8) = 0x140018e12;
          bVar6 = KeGetCurrentIrql();
          *(uint *)(puVar16 + 0x70) = (uint)bVar6;
          local_88 = puVar16 + 0x70;
          local_80 = 4;
          *(undefined8 *)(puVar16 + -8) = 0x140018e3c;
          _tlgCreate1Sz_char(local_78,local_128);
          local_68 = puVar16 + 0x74;
          *(undefined4 *)(puVar16 + 0x78) = param_5;
          local_58 = puVar16 + 0x78;
          *(undefined4 *)(puVar16 + 0x74) = *(undefined4 *)(puVar16 + 0x58);
          local_60 = 4;
          local_50 = 4;
          *(undefined8 *)(puVar16 + -8) = 0x140018e7c;
          _tlgCreate1Sz_char(local_48,"<unknown>");
          *(undefined1 **)(puVar16 + 0x28) = local_118;
          *(undefined4 *)(puVar16 + 0x20) = 0xe;
          *(undefined8 *)(puVar16 + -8) = 0x140018ea0;
          _tlgWriteTransfer_EtwWriteTransfer
                    (0x140025040,&DAT_14001dc5f,uVar12,pcVar18,*(undefined4 *)(puVar16 + 0x20),
                     *(undefined8 **)(puVar16 + 0x28));
        }
      }
      if ((DAT_140025078 == 0) || ((int)lVar19 != 0)) goto LAB_1400190c0;
      *(undefined8 *)(puVar16 + -8) = 0x140018ebf;
      cVar5 = KeGetCurrentIrql();
      if (cVar5 != '\0') goto LAB_1400190c0;
      *(undefined4 *)(puVar16 + 0x40) = 0;
      *(undefined8 *)(puVar16 + 0x38) = 0;
      *(undefined8 *)(puVar16 + 0x30) = 0;
      *(ulonglong *)(puVar16 + 0x28) = (ulonglong)uVar7;
      uVar17 = (ulonglong)uVar15;
      *(ulonglong *)(puVar16 + 0x20) = (ulonglong)uVar1;
      *(undefined8 *)(puVar16 + -8) = 0x140018f05;
      pcVar18 = g_ModuleName;
      iVar9 = DbgkWerCaptureLiveKernelDump(L"TELASSERT",0x1d1);
      if (5 < DAT_140025040) {
        *(undefined8 *)(puVar16 + -8) = 0x140018f2f;
        cVar5 = _tlgKeywordOn(0x140025040,0x400000000000);
        if (cVar5 != '\0') {
          local_f8 = puVar16 + 0x78;
          *(undefined4 *)(puVar16 + 0x78) = 10;
          local_e8 = puVar16 + 0x74;
          local_f0 = 4;
          local_d8 = puVar16 + 0x70;
          *(uint *)(puVar16 + 0x74) = uVar15;
          local_e0 = 4;
          *(uint *)(puVar16 + 0x70) = -(uint)(iVar8 != 0) & uVar1;
          local_d0 = 4;
          local_c0 = 4;
          *(uint *)(puVar16 + 0x6c) = -(uint)(iVar8 != 0) & uVar7;
          local_c8 = puVar16 + 0x6c;
          pcVar14 = "<unknown>";
          if (g_ModuleName != (char *)0x0) {
            pcVar14 = g_ModuleName;
          }
          *(undefined8 *)(puVar16 + -8) = 0x140018fbb;
          _tlgCreate1Sz_char(local_b8,pcVar14);
          *(undefined4 *)(puVar16 + 0x68) = *(undefined4 *)(puVar16 + 0x50);
          local_a8 = puVar16 + 0x68;
          *(undefined4 *)(puVar16 + 100) = *(undefined4 *)(puVar16 + 0x7c);
          local_98 = puVar16 + 100;
          local_88 = puVar16 + 0x60;
          local_a0 = 4;
          local_90 = 4;
          *(int *)(puVar16 + 0x60) = iVar9;
          local_80 = 4;
          *(undefined8 *)(puVar16 + -8) = 0x14001900f;
          _tlgCreate1Sz_char(local_78,local_128);
          *(undefined4 *)(puVar16 + 0x5c) = *(undefined4 *)(puVar16 + 0x58);
          local_68 = puVar16 + 0x5c;
          local_60 = 4;
          *(undefined4 *)(puVar16 + 0x58) = param_5;
          local_58 = puVar16 + 0x58;
          *(undefined1 **)(puVar16 + 0x28) = local_118;
          *(undefined4 *)(puVar16 + 0x20) = 0xd;
          local_50 = 4;
          *(undefined8 *)(puVar16 + -8) = 0x140019067;
          _tlgWriteTransfer_EtwWriteTransfer
                    (0x140025040,&DAT_14001dd09,uVar17,pcVar18,*(undefined4 *)(puVar16 + 0x20),
                     *(undefined8 **)(puVar16 + 0x28));
        }
      }
      if (iVar9 != 0) goto LAB_1400190c0;
      *(undefined8 *)(puVar16 + -8) = 0x140019079;
      uVar4 = KeAcquireSpinLockRaiseToDpc(&g_AssertSpinLock);
      plVar11 = g_MicrosoftTelemetryAssertsTriggeredList;
      if ((longlong **)g_MicrosoftTelemetryAssertsTriggeredList !=
          &g_MicrosoftTelemetryAssertsTriggeredList) {
        do {
          if ((IMAGE_DOS_HEADER *)plVar11[-4] == param_1) {
            *(int *)(plVar11 + -1) = (int)plVar11[-1] + 1;
            break;
          }
          plVar11 = (longlong *)*plVar11;
        } while ((longlong **)plVar11 != &g_MicrosoftTelemetryAssertsTriggeredList);
      }
    }
  }
  *(undefined8 *)(puVar16 + -8) = 0x1400190bb;
  KeReleaseSpinLock(&g_AssertSpinLock,uVar4);
LAB_1400190c0:
  *(undefined8 *)(puVar16 + -8) = 0x1400190cc;
  return;
}



===== UninitializeTelemetryAssertsKM @ 1400190f4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void UninitializeTelemetryAssertsKM(void)

{
  undefined8 *puVar1;
  code *pcVar2;
  undefined8 uVar3;
  undefined1 uVar4;
  undefined8 *puVar5;
  undefined1 *puVar6;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  LOCK();
  UNLOCK();
  if (g_AssertsOperational != 0) {
    LOCK();
    g_AssertsOperational = g_AssertsOperational + -1;
    UNLOCK();
    uVar4 = KeAcquireSpinLockRaiseToDpc(&g_AssertSpinLock);
    puVar6 = auStack_28;
    while ((undefined8 **)g_MicrosoftTelemetryAssertsTriggeredList !=
           &g_MicrosoftTelemetryAssertsTriggeredList) {
      if (((undefined8 **)g_MicrosoftTelemetryAssertsTriggeredList[1] !=
           &g_MicrosoftTelemetryAssertsTriggeredList) ||
         (puVar1 = (undefined8 *)*g_MicrosoftTelemetryAssertsTriggeredList,
         (undefined8 *)puVar1[1] != g_MicrosoftTelemetryAssertsTriggeredList)) {
        pcVar2 = (code *)swi(0x29);
        (*pcVar2)(3);
        puVar6 = auStack_20;
        break;
      }
      puVar5 = g_MicrosoftTelemetryAssertsTriggeredList + -4;
      g_MicrosoftTelemetryAssertsTriggeredList = puVar1;
      puVar1[1] = &g_MicrosoftTelemetryAssertsTriggeredList;
      ExFreePoolWithTag(puVar5,0x74727341);
    }
    *(undefined8 *)(puVar6 + -8) = 0x140019187;
    KeReleaseSpinLock(&g_AssertSpinLock,uVar4);
    if (g_ModuleName != 0) {
      *(undefined8 *)(puVar6 + -8) = 0x1400191a4;
      ExFreePoolWithTag(g_ModuleName,0x74727341);
      g_ModuleName = 0;
    }
    uVar3 = DAT_140025098;
    DAT_140025098 = 0;
    DAT_140025078 = 0;
    *(undefined8 *)(puVar6 + -8) = 0x1400191ce;
    EtwUnregister(uVar3);
    uVar3 = DAT_140025028;
    DAT_140025028 = 0;
    _DAT_140025008 = 0;
    *(undefined8 *)(puVar6 + -8) = 0x1400191f0;
    EtwUnregister(uVar3);
    uVar3 = DAT_140025060;
    DAT_140025060 = 0;
    DAT_140025040 = 0;
    *(undefined8 *)(puVar6 + -8) = 0x140019212;
    EtwUnregister(uVar3);
  }
  return;
}



===== DvClaimHandleEntry @ 14001922c =====

ulonglong DvClaimHandleEntry(longlong *param_1,uint param_2,undefined8 param_3)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined4 extraout_var;
  
  uVar3 = (ulonglong)param_2;
  if (param_2 == 0) {
    uVar3 = 0xc000000d;
  }
  else {
    if (*(uint *)(param_1 + 1) <= param_2) {
      uVar4 = DvpReallocateTable(param_1,param_2 + 1);
      if ((int)uVar4 < 0) {
        if ((int)uVar4 == -0x3fffffbc) {
          uVar2 = DvpClaimExtendedHandleEntry((longlong)param_1,param_2,param_3);
          return CONCAT44(extraout_var,uVar2);
        }
        return uVar4;
      }
    }
    lVar1 = *param_1;
    if (*(longlong *)(lVar1 + uVar3 * 8) < 0) {
      uVar3 = 0xc0000708;
    }
    else {
      for (uVar4 = 0; (uint)uVar4 < *(uint *)(param_1 + 1); uVar4 = (ulonglong)((uint)uVar4 + 1)) {
        if ((-1 < *(longlong *)(lVar1 + uVar4 * 8)) && (*(uint *)(lVar1 + uVar4 * 8) == param_2)) {
          *(undefined8 *)(lVar1 + uVar4 * 8) = *(undefined8 *)(lVar1 + uVar3 * 8);
          break;
        }
      }
      *(undefined8 *)(*param_1 + uVar3 * 8) = param_3;
      uVar3 = 0;
    }
  }
  return uVar3;
}



===== DvEnsureFreeHandleEntries @ 1400192d8 =====

undefined8 DvEnsureFreeHandleEntries(undefined8 *param_1)

{
  undefined8 uVar1;
  
  if (*(int *)*param_1 == 0) {
    uVar1 = DvpReallocateTable(param_1,*(int *)(param_1 + 1) + 1);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



===== DvGetNextHandleEntry @ 140019300 =====

longlong DvGetNextHandleEntry(longlong *param_1,uint *param_2)

{
  longlong lVar1;
  uint *puVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 local_res8;
  int local_18 [4];
  
  uVar4 = (ulonglong)*param_2;
  local_res8 = 0;
  local_18[2] = 0;
  local_18[1] = 0;
  do {
    local_18[0] = (int)uVar4;
    uVar3 = local_18[0] + 1;
    uVar4 = (ulonglong)uVar3;
    if (*(uint *)(param_1 + 1) <= uVar3) {
      if (param_1[5] != 0) {
        local_res8 = RtlLookupElementGenericTableAvl(param_1[5],local_18);
        puVar2 = (uint *)RtlEnumerateGenericTableWithoutSplayingAvl(param_1[5],&local_res8);
        if (puVar2 != (uint *)0x0) {
          lVar1 = *(longlong *)(puVar2 + 2);
          *param_2 = *puVar2;
          return lVar1;
        }
      }
      return 0;
    }
    lVar1 = *(longlong *)(*param_1 + uVar4 * 8);
  } while (-1 < lVar1);
  *param_2 = uVar3;
  return lVar1;
}



===== DvUpdateHandleEntry @ 1400193a8 =====

void DvUpdateHandleEntry(longlong *param_1,uint param_2,undefined8 param_3)

{
  longlong lVar1;
  uint local_18 [4];
  
  local_18[1] = 0;
  local_18[2] = 0;
  if (param_2 < *(uint *)(param_1 + 1)) {
    *(undefined8 *)(*param_1 + (ulonglong)param_2 * 8) = param_3;
  }
  else {
    local_18[0] = param_2;
    lVar1 = RtlLookupElementGenericTableAvl(param_1[5],local_18);
    *(undefined8 *)(lVar1 + 8) = param_3;
  }
  return;
}



===== DvpClaimExtendedHandleEntry @ 1400193f8 =====

uint DvpClaimExtendedHandleEntry(longlong param_1,undefined4 param_2,undefined8 param_3)

{
  longlong lVar1;
  char local_res8 [8];
  undefined4 local_18;
  undefined4 local_14;
  undefined8 local_10;
  
  lVar1 = *(longlong *)(param_1 + 0x28);
  local_14 = 0;
  local_res8[0] = '\0';
  if (lVar1 == 0) {
    lVar1 = ExAllocatePool2(*(undefined8 *)(param_1 + 0x18),0x68,*(undefined4 *)(param_1 + 0x10));
    if (lVar1 == 0) {
      return 0xc000009a;
    }
    RtlInitializeGenericTableAvl(lVar1,DvpExtendedCompare,DvpExtendedAllocate,DvpExtendedFree,0);
    *(longlong *)(lVar1 + 0x60) = param_1;
    *(longlong *)(param_1 + 0x28) = lVar1;
  }
  local_18 = param_2;
  local_10 = param_3;
  lVar1 = RtlInsertElementGenericTableAvl(lVar1,&local_18,0x10,local_res8);
  if (lVar1 == 0) {
    return 0xc000009a;
  }
  return ~-(uint)(local_res8[0] != '\0') & 0xc0000708;
}



===== DvpExtendedAllocate @ 1400194e0 =====

void DvpExtendedAllocate(longlong param_1,undefined4 param_2)

{
  ExAllocatePool2(*(undefined8 *)(*(longlong *)(param_1 + 0x60) + 0x18),param_2,
                  *(undefined4 *)(*(longlong *)(param_1 + 0x60) + 0x10));
  return;
}



===== DvpExtendedCompare @ 140019510 =====

char DvpExtendedCompare(undefined8 param_1,uint *param_2,uint *param_3)

{
  char cVar1;
  
  cVar1 = '\0';
  if (*param_3 <= *param_2) {
    cVar1 = (*param_2 == *param_3) + '\x01';
  }
  return cVar1;
}



===== DvpExtendedFree @ 140019530 =====

void DvpExtendedFree(longlong param_1,undefined8 param_2)

{
  ExFreePoolWithTag(param_2,*(undefined4 *)(*(longlong *)(param_1 + 0x60) + 0x10));
  return;
}



===== DvpReallocateTable @ 14001955c =====

undefined8 DvpReallocateTable(undefined8 *param_1,uint param_2)

{
  uint uVar1;
  undefined8 uVar2;
  ulonglong *_Dst;
  uint uVar3;
  ulonglong uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  
  uVar6 = *(uint *)((longlong)param_1 + 0xc);
  uVar1 = *(uint *)(param_1 + 1);
  if (uVar6 < param_2) {
    uVar2 = 0xc0000044;
  }
  else {
    uVar3 = 8;
    if (7 < param_2) {
      uVar3 = param_2;
    }
    uVar5 = uVar1 * 2;
    uVar7 = uVar5;
    if (uVar5 < uVar3) {
      uVar7 = uVar3;
    }
    if ((uVar7 <= uVar6) && (uVar6 = uVar5, uVar5 < uVar3)) {
      uVar6 = uVar3;
    }
    _Dst = (ulonglong *)
           ExAllocatePool2(param_1[3],(ulonglong)uVar6 << 3,*(undefined4 *)(param_1 + 2));
    if (_Dst == (ulonglong *)0x0) {
      uVar2 = 0xc000009a;
    }
    else {
      memmove(_Dst,(void *)*param_1,(ulonglong)uVar1 << 3);
      uVar3 = uVar6 - 1;
      if (uVar1 <= uVar3) {
        uVar8 = (ulonglong)uVar3;
        uVar5 = uVar6;
        do {
          uVar7 = (int)uVar8 - 1;
          uVar4 = (ulonglong)uVar5;
          uVar5 = uVar5 - 1;
          _Dst[uVar8] = uVar4;
          uVar8 = (ulonglong)uVar7;
        } while (uVar1 <= uVar7);
      }
      DvpPushFreeEntries(_Dst,uVar1,_Dst + uVar3);
      if ((undefined8 *)*param_1 != param_1 + 4) {
        ExFreePoolWithTag((undefined8 *)*param_1,*(undefined4 *)(param_1 + 2));
      }
      *param_1 = _Dst;
      uVar2 = 0;
      *(uint *)(param_1 + 1) = uVar6;
    }
  }
  return uVar2;
}



===== PkIsOutgoingRingFull @ 14001965c =====

undefined8 PkIsOutgoingRingFull(longlong *param_1,int param_2)

{
  char cVar1;
  undefined7 extraout_var;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  uVar4 = *(uint *)(param_1 + 2);
  iVar6 = (int)param_1[0x10];
  uVar5 = (param_2 + 7U & 0xfffffff8) + 8;
  uVar3 = *(uint *)(*param_1 + 4);
  cVar1 = PkpValidatePointer(uVar4,uVar3);
  uVar2 = 0;
  if ((cVar1 != '\0') && (uVar2 = (uVar3 - iVar6) - 8, uVar4 <= uVar2)) {
    uVar2 = uVar2 + uVar4;
  }
  return CONCAT71(extraout_var,uVar2 < uVar5);
}



===== PkpInitRingBufferControl @ 1400196b0 =====

undefined8 PkpInitRingBufferControl(longlong *param_1)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar1 = *(uint *)param_1[3];
  uVar4 = *(uint *)(param_1[3] + 4);
  uVar5 = *(uint *)*param_1;
  uVar6 = *(uint *)(*param_1 + 4);
  uVar3 = *(uint *)(param_1 + 5);
  cVar2 = PkpValidatePointer(uVar3,uVar1);
  if ((cVar2 != '\0') && (cVar2 = PkpValidatePointer(uVar3,uVar4), cVar2 != '\0')) {
    uVar3 = *(uint *)(param_1 + 2);
    cVar2 = PkpValidatePointer(uVar3,uVar5);
    if ((cVar2 != '\0') && (cVar2 = PkpValidatePointer(uVar3,uVar6), cVar2 != '\0')) {
      *(uint *)(param_1 + 8) = uVar1;
      *(uint *)((longlong)param_1 + 0x44) = uVar4;
      *(uint *)(param_1 + 0x10) = uVar5;
      *(uint *)((longlong)param_1 + 0x84) = uVar6;
      *(undefined4 *)(*param_1 + 0xc) = 0;
      *(undefined4 *)(param_1[3] + 8) = 0;
      *(undefined4 *)(*param_1 + 0x40) = 0;
      *(uint *)(*param_1 + 0x40) = *(uint *)(*param_1 + 0x40) | 1;
      PkpExpectInterrupt((longlong)param_1,'\x01');
      PkpExpectInterrupt((longlong)param_1,'\0');
      return 0;
    }
  }
  return 0xc0000102;
}



===== PkCreateGpaRangesEx @ 140019768 =====

void PkCreateGpaRangesEx(undefined8 param_1,longlong *param_2,uint *param_3,undefined8 param_4,
                        uint param_5,uint param_6,char param_7)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  uint *puVar7;
  
  if (param_2 != (longlong *)0x0) {
    bVar2 = false;
    do {
      uVar3 = *(uint *)(param_2 + 5);
      if (param_5 < uVar3) {
        uVar3 = uVar3 - param_5;
        if (param_6 != 0) {
          if ((param_7 == '\0') && (uVar3 < param_6)) {
            param_6 = param_6 - uVar3;
          }
          else {
            bVar2 = true;
            uVar3 = param_6;
          }
        }
        iVar1 = *(int *)((longlong)param_2 + 0x2c);
        *param_3 = uVar3;
        param_3[1] = *(int *)((longlong)param_2 + 0x2c) + param_5 & 0xfff;
        uVar6 = (ulonglong)uVar3 + 0xfff + (ulonglong)(iVar1 + param_5 & 0xfff) >> 0xc;
        uVar3 = *(int *)((longlong)param_2 + 0x2c) + param_5 >> 0xc;
        if ((short)uVar6 != 0) {
          uVar5 = uVar6 & 0xffff;
          puVar7 = param_3;
          do {
            puVar7 = puVar7 + 2;
            uVar4 = (ulonglong)uVar3;
            uVar3 = uVar3 + 1;
            *(longlong *)puVar7 = param_2[uVar4 + 6];
            uVar5 = uVar5 - 1;
          } while (uVar5 != 0);
        }
        param_3 = (uint *)((longlong)param_3 + (ulonglong)((int)uVar6 * 8 + 8));
        if (bVar2) {
          return;
        }
        param_5 = 0;
      }
      else {
        param_5 = param_5 - uVar3;
      }
      param_2 = (longlong *)*param_2;
    } while (param_2 != (longlong *)0x0);
  }
  return;
}



===== PkCreateGpaRangesList @ 14001985c =====

void PkCreateGpaRangesList
               (undefined8 param_1,longlong *param_2,uint *param_3,undefined8 param_4,uint param_5,
               uint param_6,char param_7)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  longlong *plVar4;
  uint uVar5;
  ulonglong uVar6;
  uint uVar7;
  
  if (param_2 != (longlong *)0x0) {
    bVar2 = false;
    do {
      uVar3 = *(uint *)(param_2 + 1);
      if (param_5 < uVar3) {
        uVar3 = uVar3 - param_5;
        if (param_6 != 0) {
          if ((param_7 == '\0') && (uVar3 < param_6)) {
            param_6 = param_6 - uVar3;
          }
          else {
            bVar2 = true;
            uVar3 = param_6;
          }
        }
        iVar1 = *(int *)((longlong)param_2 + 0xc);
        *param_3 = uVar3;
        param_3[1] = *(int *)((longlong)param_2 + 0xc) + param_5 & 0xfff;
        plVar4 = (longlong *)param_2[2];
        uVar7 = *(int *)((longlong)param_2 + 0xc) + param_5 >> 0xc;
        uVar6 = 0;
        while ((uVar5 = (uint)((ulonglong)uVar3 + 0xfff + (ulonglong)(iVar1 + param_5 & 0xfff) >>
                              0xc), plVar4 != param_2 + 2 && ((uint)uVar6 < uVar5))) {
          if (uVar7 == 0) {
            *(longlong *)(param_3 + uVar6 * 2 + 2) = plVar4[2];
            uVar6 = (ulonglong)((uint)uVar6 + 1);
          }
          else {
            uVar7 = uVar7 - 1;
          }
          plVar4 = (longlong *)*plVar4;
        }
        param_3 = (uint *)((longlong)param_3 + (ulonglong)(uVar5 * 8 + 8));
        if (bVar2) {
          return;
        }
        param_5 = 0;
      }
      else {
        param_5 = param_5 - uVar3;
      }
      param_2 = (longlong *)*param_2;
    } while (param_2 != (longlong *)0x0);
  }
  return;
}



===== PkSendPacketGpaDirect @ 140019960 =====

undefined8
PkSendPacketGpaDirect
          (longlong *param_1,void *param_2,uint param_3,undefined8 param_4,longlong *param_5,
          uint param_6,uint param_7,char param_8)

{
  bool bVar1;
  undefined2 *puVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  longlong *plVar6;
  int iVar7;
  undefined2 **ppuVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int local_res18 [2];
  undefined8 local_res20;
  undefined2 *local_48 [2];
  
  local_res18[0] = 0;
  iVar7 = 0;
  local_48[0] = (undefined2 *)0x0;
  bVar1 = false;
  iVar11 = 0;
  uVar10 = param_6;
  uVar9 = param_7;
  for (plVar6 = param_5; plVar6 != (longlong *)0x0; plVar6 = (longlong *)*plVar6) {
    uVar3 = *(uint *)(plVar6 + 5);
    if (uVar10 < uVar3) {
      iVar11 = iVar11 + 1;
      uVar3 = uVar3 - uVar10;
      uVar4 = (ulonglong)uVar3;
      if (uVar9 != 0) {
        if ((param_8 == '\0') && (uVar3 < uVar9)) {
          uVar9 = uVar9 - uVar3;
        }
        else {
          bVar1 = true;
          uVar4 = (ulonglong)uVar9;
        }
      }
      iVar7 = iVar7 + (int)((ulonglong)(*(int *)((longlong)plVar6 + 0x2c) + uVar10 & 0xfff) + 0xfff
                            + uVar4 >> 0xc) * 8 + 8;
      uVar10 = 0;
    }
    else {
      uVar10 = uVar10 - uVar3;
    }
    if (bVar1) break;
  }
  uVar10 = iVar7 + 0x18;
  uVar9 = uVar10 + param_3;
  if (uVar9 < 0x7fff9) {
    uVar3 = *(uint *)(param_1 + 0x10);
    ppuVar8 = local_48;
    plVar6 = param_1;
    local_res20 = param_4;
    uVar5 = PkGetSendBufferEx(param_1,uVar3,uVar9,(longlong *)ppuVar8,local_res18);
    puVar2 = local_48[0];
    if (-1 < (int)uVar5) {
      *local_48[0] = 9;
      local_48[0][3] = 1;
      local_48[0][1] = (short)(uVar10 >> 3);
      local_48[0][2] = (short)((ulonglong)uVar9 + 7 >> 3);
      *(undefined8 *)(local_48[0] + 4) = local_res20;
      *(int *)(local_48[0] + 10) = iVar11;
      PkCreateGpaRangesEx(plVar6,param_5,(uint *)(local_48[0] + 0xc),ppuVar8,param_6,param_7,param_8
                         );
      memmove((void *)((ulonglong)uVar10 + (longlong)puVar2),param_2,(ulonglong)param_3);
      uVar10 = PkWritePacketFooter(param_1,uVar3,uVar9);
      uVar5 = PkCompleteInsertion(param_1,uVar10);
    }
  }
  else {
    uVar5 = 0xc000000d;
  }
  return uVar5;
}



===== PkSendPacketGpaDirectList @ 140019b08 =====

undefined8
PkSendPacketGpaDirectList
          (longlong *param_1,void *param_2,uint param_3,undefined8 param_4,longlong *param_5,
          uint param_6,uint param_7,char param_8)

{
  bool bVar1;
  undefined2 *puVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  longlong *plVar6;
  int iVar7;
  undefined2 **ppuVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int local_res18 [2];
  undefined8 local_res20;
  undefined2 *local_48 [2];
  
  local_res18[0] = 0;
  iVar7 = 0;
  local_48[0] = (undefined2 *)0x0;
  bVar1 = false;
  iVar11 = 0;
  uVar10 = param_6;
  uVar9 = param_7;
  for (plVar6 = param_5; plVar6 != (longlong *)0x0; plVar6 = (longlong *)*plVar6) {
    uVar3 = *(uint *)(plVar6 + 1);
    if (uVar10 < uVar3) {
      iVar11 = iVar11 + 1;
      uVar3 = uVar3 - uVar10;
      uVar4 = (ulonglong)uVar3;
      if (uVar9 != 0) {
        if ((param_8 == '\0') && (uVar3 < uVar9)) {
          uVar9 = uVar9 - uVar3;
        }
        else {
          bVar1 = true;
          uVar4 = (ulonglong)uVar9;
        }
      }
      iVar7 = iVar7 + (int)((ulonglong)(*(int *)((longlong)plVar6 + 0xc) + uVar10 & 0xfff) + 0xfff +
                            uVar4 >> 0xc) * 8 + 8;
      uVar10 = 0;
    }
    else {
      uVar10 = uVar10 - uVar3;
    }
    if (bVar1) break;
  }
  uVar10 = iVar7 + 0x18;
  uVar9 = uVar10 + param_3;
  if (uVar9 < 0x7fff9) {
    uVar3 = *(uint *)(param_1 + 0x10);
    ppuVar8 = local_48;
    plVar6 = param_1;
    local_res20 = param_4;
    uVar5 = PkGetSendBufferEx(param_1,uVar3,uVar9,(longlong *)ppuVar8,local_res18);
    puVar2 = local_48[0];
    if (-1 < (int)uVar5) {
      *local_48[0] = 9;
      local_48[0][3] = 1;
      local_48[0][1] = (short)(uVar10 >> 3);
      local_48[0][2] = (short)((ulonglong)uVar9 + 7 >> 3);
      *(undefined8 *)(local_48[0] + 4) = local_res20;
      *(int *)(local_48[0] + 10) = iVar11;
      PkCreateGpaRangesList
                (plVar6,param_5,(uint *)(local_48[0] + 0xc),ppuVar8,param_6,param_7,param_8);
      memmove((void *)((ulonglong)uVar10 + (longlong)puVar2),param_2,(ulonglong)param_3);
      uVar10 = PkWritePacketFooter(param_1,uVar3,uVar9);
      uVar5 = PkCompleteInsertion(param_1,uVar10);
    }
  }
  else {
    uVar5 = 0xc000000d;
  }
  return uVar5;
}



===== PkInitializeRingBuffer @ 140019cb0 =====

ulonglong PkInitializeRingBuffer
                    (longlong *param_1,longlong param_2,undefined8 param_3,int param_4,
                    longlong param_5,undefined8 param_6,int param_7)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong local_38;
  longlong local_30;
  longlong local_28;
  longlong local_20;
  
  local_28 = 0;
  local_20 = 0;
  local_30 = 0;
  local_38 = 0;
  uVar1 = PkpDoubleMapBuffer(param_3,param_4 << 0xc,&local_30,&local_28);
  lVar2 = 0;
  if (-1 < (int)uVar1) {
    uVar1 = PkpDoubleMapBuffer(param_6,param_7 << 0xc,&local_38,&local_20);
    if (-1 < (int)uVar1) {
      memset(param_1,0,0xc0);
      param_1[4] = local_28;
      *param_1 = param_5;
      param_1[1] = local_20;
      param_1[0x13] = (longlong)(param_1 + 0x12);
      param_1[3] = param_2;
      *(int *)(param_1 + 5) = param_4 << 0xc;
      *(int *)(param_1 + 2) = param_7 << 0xc;
      uVar1 = PkpInitRingBufferControl(param_1);
      if (-1 < (int)uVar1) {
        param_1[6] = local_30;
        param_1[7] = local_38;
        return 0;
      }
    }
    lVar2 = local_38;
  }
  if (local_30 != 0) {
    PkpFreeDoubleMappedBuffer(local_30);
  }
  if (lVar2 != 0) {
    PkpFreeDoubleMappedBuffer(lVar2);
  }
  return uVar1 & 0xffffffff;
}



===== PkUninitializeRingBuffer @ 140019dd0 =====

void PkUninitializeRingBuffer(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x30) != 0) {
    PkpFreeDoubleMappedBuffer(*(longlong *)(param_1 + 0x30));
    *(undefined8 *)(param_1 + 0x30) = 0;
  }
  if (*(longlong *)(param_1 + 0x38) != 0) {
    PkpFreeDoubleMappedBuffer(*(longlong *)(param_1 + 0x38));
    *(undefined8 *)(param_1 + 0x38) = 0;
  }
  return;
}



===== PkpDoubleMapBuffer @ 140019e0c =====

undefined8 PkpDoubleMapBuffer(undefined8 param_1,uint param_2,longlong *param_3,undefined8 *param_4)

{
  size_t _Size;
  bool bVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  
  bVar1 = false;
  uVar5 = 0;
  lVar2 = IoAllocateMdl(param_1,param_2 * 2,0,0,0);
  if (lVar2 != 0) {
    *(uint *)(lVar2 + 0x28) = param_2;
    MmProbeAndLockPages(lVar2,0,2);
    bVar1 = true;
    _Size = (ulonglong)(param_2 >> 0xc) * 8;
    memmove((void *)(_Size + lVar2 + 0x30),(void *)(lVar2 + 0x30),_Size);
    *(uint *)(lVar2 + 0x28) = param_2 * 2;
    lVar3 = MmMapLockedPagesSpecifyCache
                      (lVar2,0,1,0,uVar5 & 0xffffffff00000000,ExDefaultMdlProtection | 0x40000010);
    if (lVar3 != 0) {
      *param_3 = lVar2;
      *param_4 = *(undefined8 *)(lVar2 + 0x18);
      lVar2 = 0;
      uVar4 = 0;
      goto LAB_140019ef9;
    }
    *(uint *)(lVar2 + 0x28) = *(uint *)(lVar2 + 0x28) >> 1;
  }
  uVar4 = 0xc000009a;
LAB_140019ef9:
  if (lVar2 != 0) {
    if (bVar1) {
      MmUnlockPages(lVar2);
    }
    IoFreeMdl(lVar2);
  }
  return uVar4;
}



===== PkpFreeDoubleMappedBuffer @ 140019f44 =====

void PkpFreeDoubleMappedBuffer(longlong param_1)

{
  MmUnmapLockedPages(*(undefined8 *)(param_1 + 0x18),param_1);
  *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) >> 1;
  MmUnlockPages(param_1);
  IoFreeMdl(param_1);
  return;
}



===== PkSetInterruptMaskSkipCount @ 140019f90 =====

void PkSetInterruptMaskSkipCount(longlong param_1,undefined8 param_2)

{
  *(undefined8 *)(param_1 + 0x98) = param_2;
  return;
}



===== __GSHandlerCheck @ 140019fa8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140019fcc =====

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



===== __cpu_features_init @ 14001a040 =====

/* WARNING: Removing unreachable block (ram,0x00014001a0aa) */
/* WARNING: Removing unreachable block (ram,0x00014001a059) */
/* WARNING: Removing unreachable block (ram,0x00014001a04a) */

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



===== __security_check_cookie @ 14001a110 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 14001a150 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 14001a180 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00014001a180. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 14001a1b0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 14001a200 =====

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



===== memset @ 14001a500 =====

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



===== __memset_repmovs @ 14001a640 =====

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



===== __memset_query @ 14001a6c0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 14001a740 =====

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



===== __memset_spec_ermsb_repmovsb @ 14001a880 =====

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



===== __memset_spec_plain @ 14001a900 =====

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



===== KmclPcAddChannel @ 140026008 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void KmclPcAddChannel(void)

{
  undefined1 auStack_98 [32];
  undefined1 *local_78;
  undefined1 local_68 [8];
  undefined4 local_60;
  undefined4 local_50;
  undefined4 local_40;
  undefined4 local_30;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_98;
  local_78 = local_68;
  local_60 = 0x18;
  local_30 = 0x18;
  local_50 = 0xc0;
  local_40 = 0x38;
  local_20 = 0x110;
  PcwAddInstance();
  return;
}



===== VmbChannelFind @ 1400260b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint VmbChannelFind(undefined8 param_1,longlong *param_2,longlong *param_3,short param_4,
                   undefined8 param_5,undefined8 *param_6)

{
  undefined8 *puVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  undefined8 *puVar5;
  
                    /* 0x260b0  14  VmbChannelFind */
  uVar3 = 0xc0000225;
  ExAcquireFastMutex(&KmclChannelListLock);
  puVar5 = KmclChannelList;
  do {
    if ((undefined8 **)puVar5 == &KmclChannelList) {
LAB_1400261bb:
      ExReleaseFastMutex(&KmclChannelListLock);
      return uVar3;
    }
    puVar1 = puVar5 + -0x10c;
    if ((*(int *)(puVar5 + 7) == 0xc) && (puVar5[0x84] == 0)) {
      lVar4 = *(longlong *)((longlong)puVar5 + -0x184) - *param_2;
      if (lVar4 == 0) {
        lVar4 = *(longlong *)((longlong)puVar5 + -0x17c) - param_2[1];
      }
      if (lVar4 == 0) {
        lVar4 = *(longlong *)((longlong)puVar5 + -0x174) - *param_3;
        if (lVar4 == 0) {
          lVar4 = *(longlong *)((longlong)puVar5 + -0x16c) - param_3[1];
        }
        if ((lVar4 == 0) && (*(short *)(puVar5 + 0x86) == param_4)) {
          iVar2 = (*(code *)puVar5[0x3c])(puVar5[0x16],param_1);
          if (-1 < iVar2) {
            uVar3 = KmclInitializeChannelParentDevice((longlong)puVar1,param_5);
            if ((int)uVar3 < 0) {
              KmclChannelCleanupParentDevice((longlong)puVar1);
            }
            else {
              *param_6 = puVar1;
              uVar3 = 0;
            }
            goto LAB_1400261bb;
          }
        }
      }
    }
    puVar5 = (undefined8 *)*puVar5;
  } while( true );
}



===== VmbChannelInitSetClientContextSize @ 140026200 =====

undefined8 VmbChannelInitSetClientContextSize(longlong param_1,undefined4 param_2)

{
                    /* 0x26200  34  VmbChannelInitSetClientContextSize */
  if (*(int *)(param_1 + 0x898) == 0) {
    *(undefined4 *)(param_1 + 0x6d4) = param_2;
    return 0;
  }
  return 0xc00000ef;
}



===== VmbChannelInitSetFriendlyName @ 140026220 =====

undefined8 VmbChannelInitSetFriendlyName(longlong param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
                    /* 0x26220  36  VmbChannelInitSetFriendlyName */
  if (*(int *)(param_1 + 0x898) == 0) {
    if (*(longlong *)(param_1 + 0x890) == 0) {
      uVar1 = RtlDuplicateUnicodeString(1,param_2,param_1 + 0x888);
    }
    else {
      uVar1 = 0xc00000f0;
    }
  }
  else {
    uVar1 = 0xc00000ef;
  }
  return uVar1;
}



===== VmbChannelInitSetInlinePacketContextSize @ 140026270 =====

undefined8 VmbChannelInitSetInlinePacketContextSize(longlong param_1,int param_2)

{
                    /* 0x26270  37  VmbChannelInitSetInlinePacketContextSize */
  if (*(int *)(param_1 + 0x898) == 0) {
    *(uint *)(param_1 + 0x6d8) = param_2 + 7U & 0xfffffff8;
    return 0;
  }
  return 0xc00000ef;
}



===== VmbChannelInitSetMaximumExternalData @ 1400262a0 =====

undefined8 VmbChannelInitSetMaximumExternalData(longlong param_1,int param_2,int param_3)

{
                    /* 0x262a0  38  VmbChannelInitSetMaximumExternalData */
  if (*(int *)(param_1 + 0x898) != 0) {
    return 0xc00000ef;
  }
  if (param_2 == 0) {
    return 0xc00000f0;
  }
  if (param_3 == 0) {
    return 0xc00000f1;
  }
  *(int *)(param_1 + 0x6cc) = param_2;
  *(int *)(param_1 + 0x6d0) = param_3;
  return 0;
}



===== VmbChannelInitSetMaximumPacketCount @ 1400262e0 =====

undefined8 VmbChannelInitSetMaximumPacketCount(longlong param_1,int param_2)

{
                    /* 0x262e0  39  VmbChannelInitSetMaximumPacketCount */
  if (*(int *)(param_1 + 0x898) != 0) {
    return 0xc00000ef;
  }
  if (param_2 == 0) {
    return 0xc00000f0;
  }
  *(int *)(param_1 + 0x6c4) = param_2;
  return 0;
}



===== VmbChannelInitSetShortLifetimeThreshold @ 140026310 =====

undefined8 VmbChannelInitSetShortLifetimeThreshold(longlong param_1,undefined4 param_2)

{
                    /* 0x26310  44  VmbChannelInitSetShortLifetimeThreshold */
  if (*(int *)(param_1 + 0x898) == 0) {
    *(undefined4 *)(param_1 + 0x6fc) = param_2;
    return 0;
  }
  return 0xc00000ef;
}



===== VmbChannelInitialize @ 140026330 =====

uint VmbChannelInitialize(undefined8 param_1,char param_2,void *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  
                    /* 0x26330  47  VmbChannelInitialize */
  if (param_4 < 0xd40) {
    uVar2 = 0xc0000023;
  }
  else {
    uVar1 = KmclInitializeChannel(param_3,param_1,param_2);
    uVar2 = 0;
    if ((int)uVar1 < 0) {
      uVar2 = uVar1;
    }
  }
  return uVar2;
}



===== VmbClientChannelInitSetTargetFile @ 140026370 =====

undefined8 VmbClientChannelInitSetTargetFile(longlong param_1,undefined8 param_2,longlong param_3)

{
  undefined8 uVar1;
  
                    /* 0x26370  86  VmbClientChannelInitSetTargetFile */
  if ((*(char *)(param_1 + 0x6c0) == '\0') && (*(int *)(param_1 + 0x898) == 0)) {
    if ((*(char *)(param_1 + 0x7c0) == '\0') && (*(char *)(param_1 + 0x7c1) == '\0')) {
      ObfReferenceObject(param_2);
      *(undefined8 *)(param_1 + 0xa70) = param_2;
      if (param_3 != 0) {
        ObfReferenceObject(param_3);
        *(longlong *)(param_1 + 0xa78) = param_3;
      }
      *(undefined1 *)(param_1 + 0x7c1) = 1;
      uVar1 = 0;
    }
    else {
      uVar1 = 0xc00000f0;
    }
  }
  else {
    uVar1 = 0xc00000ef;
  }
  return uVar1;
}



===== VmbConvertVmbusHandleToKernelHandle @ 140026410 =====

undefined8 VmbConvertVmbusHandleToKernelHandle(longlong param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
                    /* 0x26410  89  VmbConvertVmbusHandleToKernelHandle */
  if (param_1 == 0) {
    *param_2 = 0;
    uVar1 = 0;
  }
  else {
    uVar1 = IoConvertFileHandleToKernelHandle(param_1,1,0x1f01ff,0,param_2);
  }
  return uVar1;
}



===== VmbServerChannelInitEnableDeferredPause @ 140026450 =====

undefined8 VmbServerChannelInitEnableDeferredPause(longlong param_1,undefined4 param_2)

{
                    /* 0x26450  106  VmbServerChannelInitEnableDeferredPause */
  if ((*(char *)(param_1 + 0x6c0) == '\0') || (*(int *)(param_1 + 0x898) != 0)) {
    return 0xc00000ef;
  }
  *(undefined1 *)(param_1 + 0x706) = 1;
  *(undefined4 *)(param_1 + 0x798) = param_2;
  return 0;
}



===== VmbServerChannelInitSetFlags @ 140026480 =====

undefined8 VmbServerChannelInitSetFlags(longlong param_1,uint param_2)

{
                    /* 0x26480  107  VmbServerChannelInitSetFlags */
  if ((*(char *)(param_1 + 0x6c0) == '\0') || (*(int *)(param_1 + 0x898) != 0)) {
    return 0xc00000ef;
  }
  if ((param_2 & 0xffffffe0) != 0) {
    return 0xc00000f0;
  }
  if ((param_2 & 2) != 0) {
    *(undefined1 *)(param_1 + 0x702) = 1;
  }
  if ((param_2 & 1) != 0) {
    *(undefined1 *)(param_1 + 0x701) = 1;
  }
  if ((param_2 & 4) != 0) {
    *(undefined1 *)(param_1 + 0x703) = 1;
  }
  if ((param_2 & 8) != 0) {
    *(undefined1 *)(param_1 + 0x704) = 1;
  }
  if ((param_2 & 0x10) != 0) {
    *(undefined1 *)(param_1 + 0x705) = 1;
  }
  return 0;
}



===== VmbServerChannelInitSetMmioMegabytes @ 1400264f0 =====

undefined8 VmbServerChannelInitSetMmioMegabytes(longlong param_1,short param_2,short param_3)

{
                    /* 0x264f0  108  VmbServerChannelInitSetMmioMegabytes */
  if ((*(char *)(param_1 + 0x6c0) == '\0') || (*(int *)(param_1 + 0x898) != 0)) {
    return 0xc00000ef;
  }
  if ((param_2 == 0) && (param_3 == 0)) {
    return 0xc00000f0;
  }
  *(short *)(param_1 + 0x70a) = param_2;
  *(short *)(param_1 + 0x70c) = param_3;
  return 0;
}



===== VmbServerChannelInitSetMonitoredNotifications @ 140026540 =====

undefined8 VmbServerChannelInitSetMonitoredNotifications(longlong param_1,undefined2 param_2)

{
                    /* 0x26540  109  VmbServerChannelInitSetMonitoredNotifications */
  if ((*(char *)(param_1 + 0x6c0) == '\0') || (*(int *)(param_1 + 0x898) != 0)) {
    return 0xc00000ef;
  }
  *(undefined2 *)(param_1 + 0x708) = param_2;
  return 0;
}



===== VmbServerChannelInitSetOfferData @ 140026570 =====

undefined8 VmbServerChannelInitSetOfferData(longlong param_1,void *param_2,uint param_3)

{
  undefined8 uVar1;
  
                    /* 0x26570  110  VmbServerChannelInitSetOfferData */
  if ((*(char *)(param_1 + 0x6c0) == '\0') || (*(int *)(param_1 + 0x898) != 0)) {
    uVar1 = 0xc00000ef;
  }
  else if (param_3 < 0x79) {
    memmove((void *)(param_1 + 0x720),param_2,(ulonglong)param_3);
    uVar1 = 0;
  }
  else {
    uVar1 = 0xc00000f1;
  }
  return uVar1;
}



===== VmbServerChannelInitSetSaveRestorePacketCallbacks @ 1400265c0 =====

undefined8
VmbServerChannelInitSetSaveRestorePacketCallbacks
          (longlong param_1,undefined8 param_2,undefined8 param_3)

{
                    /* 0x265c0  111  VmbServerChannelInitSetSaveRestorePacketCallbacks */
  if ((*(char *)(param_1 + 0x6c0) == '\0') ||
     ((*(int *)(param_1 + 0x898) != 0 && (*(int *)(param_1 + 0x898) != 0xc)))) {
    return 0xc00000ef;
  }
  *(undefined8 *)(param_1 + 0x840) = param_2;
  *(undefined8 *)(param_1 + 0x848) = param_3;
  return 0;
}



===== VmbServerChannelInitSetSaveRestorePacketCallbacksEx @ 140026600 =====

undefined8
VmbServerChannelInitSetSaveRestorePacketCallbacksEx
          (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
                    /* 0x26600  112  VmbServerChannelInitSetSaveRestorePacketCallbacksEx */
  if ((*(char *)(param_1 + 0x6c0) == '\0') ||
     ((*(int *)(param_1 + 0x898) != 0 && (*(int *)(param_1 + 0x898) != 0xc)))) {
    return 0xc00000ef;
  }
  *(undefined8 *)(param_1 + 0x838) = param_2;
  *(undefined8 *)(param_1 + 0x828) = param_3;
  *(undefined8 *)(param_1 + 0x830) = param_4;
  return 0;
}



===== VmbServerChannelInitSetTargetInterfaceId @ 140026640 =====

undefined8
VmbServerChannelInitSetTargetInterfaceId(longlong param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
                    /* 0x26640  113  VmbServerChannelInitSetTargetInterfaceId */
  if ((*(char *)(param_1 + 0x6c0) == '\0') ||
     ((*(int *)(param_1 + 0x898) != 0 && (*(int *)(param_1 + 0x898) != 0xc)))) {
    return 0xc00000ef;
  }
  uVar1 = param_2[1];
  uVar2 = *param_3;
  uVar3 = param_3[1];
  *(undefined8 *)(param_1 + 0x6dc) = *param_2;
  *(undefined8 *)(param_1 + 0x6e4) = uVar1;
  *(undefined8 *)(param_1 + 0x6ec) = uVar2;
  *(undefined8 *)(param_1 + 0x6f4) = uVar3;
  return 0;
}



===== VmbServerChannelInitSetTargetVtl @ 140026680 =====

undefined8 VmbServerChannelInitSetTargetVtl(longlong param_1,byte param_2)

{
                    /* 0x26680  114  VmbServerChannelInitSetTargetVtl */
  if ((*(int *)(param_1 + 0x898) != 0) || (*(char *)(param_1 + 0x6c0) == '\0')) {
    return 0xc00000ef;
  }
  if (param_2 < 3) {
    *(byte *)(param_1 + 0x7c3) = param_2;
    return 0;
  }
  return 0xc00000f0;
}



===== VmbServerChannelInitSetVmId @ 1400266c0 =====

undefined8 VmbServerChannelInitSetVmId(longlong param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
                    /* 0x266c0  115  VmbServerChannelInitSetVmId */
  if ((*(char *)(param_1 + 0x6c0) == '\0') || (*(int *)(param_1 + 0x898) != 0)) {
    return 0xc00000ef;
  }
  uVar1 = param_2[1];
  *(undefined8 *)(param_1 + 0x710) = *param_2;
  *(undefined8 *)(param_1 + 0x718) = uVar1;
  return 0;
}



===== VmbServerChannelInitSetVmbusHandle @ 1400266f0 =====

undefined8 VmbServerChannelInitSetVmbusHandle(longlong param_1,longlong param_2)

{
                    /* 0x266f0  116  VmbServerChannelInitSetVmbusHandle */
  if ((*(char *)(param_1 + 0x6c0) == '\0') || (*(int *)(param_1 + 0x898) != 0)) {
    return 0xc00000ef;
  }
  if (param_2 < 0) {
    *(longlong *)(param_1 + 0x7a0) = param_2;
    return 0;
  }
  return 0xc00000f0;
}



===== InChangeClientContextSize @ 140026728 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong InChangeClientContextSize(longlong *param_1,int param_2)

{
  byte bVar1;
  longlong *plVar2;
  longlong lVar3;
  code *pcVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  uint uVar10;
  longlong *plVar11;
  longlong *plVar12;
  uint uVar13;
  undefined1 auStack_88 [8];
  undefined1 auStack_80 [24];
  longlong local_68 [6];
  
  puVar9 = auStack_88;
  local_68[4] = __security_cookie ^ (ulonglong)auStack_88;
  local_68[0] = 0;
  local_68[1] = 0;
  if ((int)param_1[0x89] != 0) {
    uVar5 = 0xc0000184;
    puVar9 = auStack_88;
    goto LAB_140026968;
  }
  if (param_2 == (int)param_1[0xae]) {
    uVar5 = 0;
    goto LAB_140026968;
  }
  local_68[2] = 0;
  local_68[3] = 0;
  KeQueryNodeActiveAffinity(*(undefined2 *)(*param_1 + 0xc88),local_68,0);
  if (local_68[0] != 0) {
    KeSetSystemGroupAffinityThread(local_68,local_68 + 2);
  }
  puVar8 = auStack_88;
  uVar13 = ((int)param_1[0xb5] - (int)param_1[0xae]) + param_2;
  plVar11 = (longlong *)param_1[0xa0];
  while (plVar11 != param_1 + 0xa0) {
    plVar12 = plVar11;
    if ((int)plVar11[2] == 0) {
      uVar10 = (*(int *)((longlong)plVar11 + -0xc) - *(int *)((longlong)plVar11 + 0x3c)) + param_2;
      if (*(uint *)(plVar11 + -2) < uVar10) {
        puVar6 = (undefined8 *)ExAllocatePool2(0x40,uVar10,0x6e696b56);
        if (puVar6 != (undefined8 *)0x0) {
          *(uint *)(puVar6 + 1) = uVar10;
          *(uint *)((longlong)puVar6 + 0xc) = uVar10;
          *(undefined1 *)(puVar6 + 2) = 0x40;
          plVar12 = puVar6 + 3;
          puVar6[4] = plVar12;
          *plVar12 = (longlong)plVar12;
          *(undefined4 *)(puVar6 + 5) = 0;
          puVar6[6] = 0;
          puVar6[9] = 0;
          *(undefined1 *)((longlong)puVar6 + 0x11) = 0;
          bVar1 = *(byte *)(plVar11 + -1);
          *(int *)((longlong)plVar11 + 0x3c) = param_2;
          *puVar6 = param_1;
          *(byte *)(puVar6 + 2) = bVar1 & 0xfe | 0x40;
          *(int *)(puVar6 + 7) = (int)plVar11[4];
          *(undefined4 *)((longlong)puVar6 + 0x3c) = *(undefined4 *)((longlong)plVar11 + 0x24);
          *(int *)(puVar6 + 8) = (int)plVar11[5];
          memmove(puVar6 + 0x14,plVar11 + 0x11,(ulonglong)*(uint *)(plVar11 + 4));
          if (*(uint *)((longlong)plVar11 + 0x34) != 0) {
            uVar7 = InpParseGpaDirectPacket
                              ((longlong)puVar6,(uint)*(ushort *)((longlong)puVar6 + 0xa2) << 3,
                               *(uint *)((longlong)plVar11 + 0x34));
            if ((char)uVar7 == '\0') {
              uVar5 = 0xc0000102;
              ExFreePoolWithTag(puVar6,0x6e696b56);
              puVar9 = auStack_88;
              goto LAB_140026955;
            }
          }
          plVar2 = (longlong *)plVar11[1];
          if ((longlong *)*plVar2 == plVar11) {
            *plVar12 = (longlong)plVar11;
            puVar6[4] = plVar2;
            *plVar2 = (longlong)plVar12;
            plVar11[1] = (longlong)plVar12;
            lVar3 = *plVar11;
            if ((*(longlong **)(lVar3 + 8) == plVar11) && ((longlong *)*plVar12 == plVar11)) {
              *plVar12 = lVar3;
              *(longlong **)(lVar3 + 8) = plVar12;
              InpFreePacket((longlong)param_1,(longlong)(plVar11 + -3));
              goto LAB_1400268f9;
            }
          }
          pcVar4 = (code *)swi(0x29);
          (*pcVar4)(3);
          puVar8 = auStack_80;
        }
        uVar5 = 0xc000009a;
        puVar9 = puVar8;
        goto LAB_140026955;
      }
      param_1[0xad] = param_1[0xad] + (ulonglong)(*(int *)((longlong)plVar11 + -0xc) - uVar10);
      *(uint *)((longlong)plVar11 + -0xc) = uVar10;
      *(int *)((longlong)plVar11 + 0x3c) = param_2;
    }
LAB_1400268f9:
    plVar11 = (longlong *)*plVar12;
  }
  if (param_1[0xb6] == 0) {
LAB_140026945:
    *(uint *)(param_1 + 0xb5) = uVar13;
    uVar5 = 0;
    *(int *)(param_1 + 0xae) = param_2;
    puVar9 = auStack_88;
  }
  else {
    uVar7 = InpReacquirePacketAllocationResources(param_1,uVar13);
    uVar5 = uVar7 & 0xffffffff;
    puVar9 = auStack_88;
    if (-1 < (int)uVar7) goto LAB_140026945;
  }
LAB_140026955:
  *(undefined8 *)(puVar9 + -8) = 0x140026961;
  KeRevertToUserGroupAffinityThread(puVar9 + 0x30);
LAB_140026968:
  *(undefined8 *)(puVar9 + -8) = 0x140026975;
  return uVar5;
}



===== InRestorePacket @ 140026994 =====

undefined4 InRestorePacket(longlong *param_1,ushort *param_2,uint param_3)

{
  code *pcVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  uint uVar5;
  longlong *plVar6;
  undefined4 uVar7;
  longlong *plVar8;
  undefined4 uVar9;
  uint local_res20 [2];
  undefined8 in_stack_ffffffffffffffd0;
  longlong local_18 [2];
  
  local_18[0] = 0;
  local_res20[0] = 0;
  lVar2 = InpValidatePacket((longlong)param_2,param_3,local_res20);
  if ((char)lVar2 == '\0') {
    uVar9 = 0xc0000102;
    if (DAT_140020050 < 3) {
      return 0xc0000102;
    }
    uVar7 = 0xbe3;
  }
  else {
    uVar5 = (uint)*param_2;
    if (((*param_2 - 6 & 0xfffffffc) == 0) && (uVar5 != 8)) {
      uVar3 = InpBuildDataPacket(param_1,uVar5,(undefined8 *)param_2,local_res20[0],param_3,
                                 in_stack_ffffffffffffffd0,local_18);
      if ((int)uVar3 == 1) {
        plVar6 = param_1 + 0xa0;
        *(byte *)(local_18[0] + 0x10) = *(byte *)(local_18[0] + 0x10) | 8;
        puVar4 = (undefined8 *)(local_18[0] + 0x18);
        plVar8 = (longlong *)param_1[0xa1];
        if ((longlong *)*plVar8 != plVar6) {
          plVar6 = (longlong *)0x3;
          pcVar1 = (code *)swi(0x29);
          puVar4 = (undefined8 *)(*pcVar1)();
        }
        *puVar4 = plVar6;
        puVar4[1] = plVar8;
        *plVar8 = (longlong)puVar4;
        plVar6[1] = (longlong)puVar4;
        return 0;
      }
      uVar9 = 0xc0000102;
      if ((int)uVar3 != 0xb) {
        uVar9 = 0xc000009a;
      }
      if (DAT_140020050 < 3) {
        return uVar9;
      }
      uVar7 = 0xc07;
    }
    else {
      if (uVar5 == 10) {
        return 0;
      }
      uVar9 = 0xc0000102;
      if (DAT_140020050 < 3) {
        return 0xc0000102;
      }
      uVar7 = 0xc28;
    }
  }
  VmbusTraceErrorQueue
            ("InRestorePacket",uVar7,*param_1 + 0x6ec,(ulonglong)*(ushort *)(*param_1 + 0xc90),uVar9
            );
  return uVar9;
}



===== InSaveQueue @ 140026abc =====

ulonglong InSaveQueue(longlong *param_1,longlong *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  longlong *plVar4;
  
  if (*(char *)((longlong)param_1 + 0x4b3) != '\0') {
    plVar4 = (longlong *)param_2[4];
    if (plVar4 == (longlong *)0x0) {
      plVar4 = (longlong *)param_1[0x8a];
    }
    for (; plVar4 != param_1 + 0x8a; plVar4 = (longlong *)*plVar4) {
      SaveStart(param_2,0x50745353);
      SaveCopyRawBytes(param_2,plVar4 + 0x11,(uint)*(ushort *)((longlong)plVar4 + 0x8c) << 3);
      uVar2 = SaveCommit(param_2);
      if ((int)uVar2 < 0) {
        param_2[4] = (longlong)plVar4;
        return uVar2 & 0xffffffff;
      }
    }
    param_2[4] = (longlong)plVar4;
  }
  plVar4 = (longlong *)param_2[5];
  if (plVar4 == (longlong *)0x0) {
    plVar4 = (longlong *)param_1[0xa0];
  }
  while( true ) {
    if (plVar4 == param_1 + 0xa0) {
      param_2[5] = (longlong)plVar4;
      return 0;
    }
    if ((int)plVar4[2] == 1) {
      uVar1 = OutSavePacket(param_2,(longlong *)plVar4[-0x10],(longlong)(plVar4 + -0x12));
    }
    else {
      SaveStart(param_2,0x50745353);
      SaveCopyRawBytes(param_2,plVar4 + 0x11,(uint)*(ushort *)((longlong)plVar4 + 0x8c) << 3);
      uVar3 = SaveCommit(param_2);
      uVar1 = (uint)uVar3;
    }
    if ((int)uVar1 < 0) break;
    plVar4 = (longlong *)*plVar4;
  }
  param_2[5] = (longlong)plVar4;
  if (DAT_140020050 < 3) {
    return (ulonglong)uVar1;
  }
  VmbusTraceErrorQueue
            ("InSaveQueue",0xbb9,*param_1 + 0x6ec,(ulonglong)*(ushort *)(*param_1 + 0xc90),uVar1);
  return (ulonglong)uVar1;
}



===== wil_RtlStagingConfig_QueryFeatureState @ 140026c18 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 wil_RtlStagingConfig_QueryFeatureState(uint *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 local_20;
  uint local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = 0;
  local_20 = 0;
  local_18 = 0;
  iVar1 = RtlQueryFeatureConfiguration(param_2,param_3 == 0,&local_28,&local_20);
  if (iVar1 == 0) {
    *param_1 = local_20._4_4_ >> 4 & 3;
    *(byte *)(param_1 + 1) = (byte)((ulonglong)local_20 >> 0x28) & 0x3f;
    param_1[3] = local_18;
    param_1[2] = local_20._4_4_ >> 0xe & 3;
    param_1[5] = local_20._4_4_ >> 6 & 1;
    param_1[4] = local_20._4_4_ >> 7 & 1;
  }
  else {
    if (iVar1 != 0x117) {
      return 0;
    }
    param_1[4] = local_20._4_4_ >> 7 & 1;
  }
  return 1;
}



===== OutRestoreCompletionPacket @ 140026ce4 =====

undefined4 OutRestoreCompletionPacket(longlong *param_1,longlong *param_2,uint param_3)

{
  longlong *plVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  longlong lVar5;
  
  if (param_3 < 8) {
    uVar3 = 0xc0000102;
    if (DAT_140020050 < 3) {
      return 0xc0000102;
    }
    lVar5 = *param_1;
    uVar2 = 0xd97;
  }
  else {
    uVar4 = param_3 - 8;
    plVar1 = (longlong *)ExAllocatePool2(0x40,(ulonglong)uVar4 + 0x38,0x636d6b56);
    if (plVar1 != (longlong *)0x0) {
      *(undefined4 *)(plVar1 + 2) = 2;
      plVar1[5] = *param_2;
      plVar1[6] = (longlong)(plVar1 + 7);
      plVar1[4] = (longlong)OutpRestoredCompletionSent;
      *(uint *)(plVar1 + 3) = uVar4;
      memmove(plVar1 + 7,param_2 + 1,(ulonglong)uVar4);
      OutpEnqueuePacket((longlong)param_1,plVar1);
      return 0;
    }
    uVar3 = 0xc000009a;
    if (DAT_140020050 < 3) {
      return 0xc000009a;
    }
    lVar5 = *param_1;
    uVar2 = 0xdab;
  }
  VmbusTraceErrorQueue
            ("OutRestoreCompletionPacket",uVar2,lVar5 + 0x6ec,(ulonglong)*(ushort *)(lVar5 + 0xc90),
             uVar3);
  return uVar3;
}



===== OutRestorePacket @ 140026df0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong OutRestorePacket(longlong *param_1,uint *param_2,uint param_3)

{
  void *_Dst;
  byte bVar1;
  char cVar2;
  uint uVar3;
  longlong *plVar4;
  undefined8 uVar5;
  code *pcVar6;
  uint uVar7;
  ulonglong uVar8;
  longlong lVar9;
  undefined8 *puVar10;
  longlong *plVar11;
  undefined4 uVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  undefined1 *puVar15;
  uint uVar16;
  undefined1 auStackY_68 [8];
  undefined1 auStackY_60 [24];
  
  plVar4 = (longlong *)*param_1;
  uVar16 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
             &WPP_5aa4bd3afbb734822e41f6b706e97d47_Traceguids,plVar4);
  }
  puVar15 = auStackY_68;
  if (param_3 < 0x10) {
    uVar14 = 0xc0000102;
    puVar15 = auStackY_68;
    if (DAT_140020050 < 3) goto LAB_1400272e0;
    uVar12 = 0xc31;
LAB_1400272be:
    lVar9 = *param_1;
  }
  else {
    uVar7 = *param_2;
    if (((uVar7 < 0x10) || (param_3 < uVar7)) || (param_3 - uVar7 < param_2[1])) {
      uVar14 = 0xc0000102;
      if (DAT_140020050 < 3) goto LAB_1400272e0;
      uVar12 = 0xc3c;
      goto LAB_1400272be;
    }
    lVar9 = *param_1;
    if (*(uint *)(lVar9 + 0x6c8) < param_2[1]) {
      uVar14 = 0xc0000102;
      puVar15 = auStackY_68;
      if (DAT_140020050 < 3) goto LAB_1400272e0;
      uVar12 = 0xc44;
    }
    else {
      bVar1 = (byte)param_2[3];
      if ((((bVar1 & 0xfc) == 0) && (bVar1 != 2)) &&
         (((*(byte *)((longlong)param_2 + 0xd) & 1) != 0 || (bVar1 == 0)))) {
        if (bVar1 == 1) {
          uVar13 = (ulonglong)param_2[2];
          plVar11 = param_1;
          uVar8 = DvClaimHandleEntry(param_1 + 0x59,param_2[2],param_1);
          uVar14 = uVar8 & 0xffffffff;
          if (-1 < (int)uVar8) {
            uVar16 = param_2[2];
            *(int *)(param_1 + 0x3a) = (int)param_1[0x5a];
            goto LAB_140026f9d;
          }
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_qDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar13,plVar11,plVar4,
                       (char)param_2[2],(char)uVar8);
          }
          if ((int)uVar8 != -0x3fffff66) {
            uVar14 = 0xc0000102;
          }
          if (2 < DAT_140020050) {
            VmbusTraceErrorQueue
                      ("OutRestorePacket",0xc74,*param_1 + 0x6ec,
                       (ulonglong)*(ushort *)(*param_1 + 0xc90),(int)uVar14);
          }
          puVar15 = auStackY_68;
          if (-1 < (int)uVar14) goto LAB_1400272e0;
        }
        else {
LAB_140026f9d:
          uVar7 = param_2[1];
          uVar3 = *param_2;
          plVar4[0x17e] = (longlong)param_2;
          if ((plVar4[0x106] == 0) && (plVar4[0x109] == 0)) {
            lVar9 = VmbPacketAllocate(plVar4);
            if (lVar9 == 0) {
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                         &WPP_5aa4bd3afbb734822e41f6b706e97d47_Traceguids,plVar4);
              }
              uVar14 = 0xc000009a;
            }
            else {
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
                 (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                          &WPP_5aa4bd3afbb734822e41f6b706e97d47_Traceguids,plVar4,(char)lVar9);
              }
              OutSetRestorePacket(plVar4,lVar9);
              uVar14 = 0;
            }
          }
          else {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 &&
                (3 < (byte)WPP_GLOBAL_Control[0x29])))) {
              WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                       &WPP_5aa4bd3afbb734822e41f6b706e97d47_Traceguids,plVar4);
            }
            if ((code *)plVar4[0x106] == (code *)0x0) {
              uVar7 = (*(code *)plVar4[0x109])(plVar4,param_2,uVar7 + uVar3);
            }
            else {
              uVar7 = (*(code *)plVar4[0x106])(plVar4,plVar4[0x107],param_2,uVar7 + uVar3);
            }
            uVar14 = (ulonglong)uVar7;
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
               (3 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                        &WPP_5aa4bd3afbb734822e41f6b706e97d47_Traceguids,plVar4,(char)uVar7);
            }
          }
          puVar15 = auStackY_68;
          lVar9 = plVar4[0x17d];
          plVar4[0x17d] = 0;
          plVar4[0x17e] = 0;
          if (-1 < (int)uVar14) {
            if (lVar9 == 0) {
              puVar15 = auStackY_68;
              if ((*(byte *)((longlong)param_2 + 0xd) & 1) != 0) {
                uVar14 = 0xc00000e5;
                if (2 < DAT_140020050) {
                  uVar12 = 0xcdc;
                  goto LAB_14002717a;
                }
                goto LAB_14002719c;
              }
            }
            else {
              _Dst = (void *)(lVar9 + 0xf0);
              *(undefined4 *)(lVar9 + 0x70) = *(undefined4 *)(lVar9 + 0xac);
              *(void **)(lVar9 + 0x68) = _Dst;
              *(byte *)(lVar9 + 0x3c) = *(byte *)((longlong)param_2 + 0xd) & 1;
              cVar2 = (char)param_2[3];
              if (cVar2 == '\0') {
                *(void **)(lVar9 + 0x30) = _Dst;
                *(uint *)(lVar9 + 0x38) = param_2[1];
                memmove(_Dst,(void *)((ulonglong)*param_2 + (longlong)param_2),(ulonglong)param_2[1]
                       );
                if ((char)plVar4[0x17f] != '\0') {
                  *(undefined1 *)(lVar9 + 0x3d) = 2;
                }
                OutpEnqueuePacket((longlong)param_1,(longlong *)(lVar9 + 0x90));
                puVar15 = auStackY_68;
                *(undefined4 *)(lVar9 + 0x18) = 2;
              }
              else if (cVar2 == '\x01') {
                DvUpdateHandleEntry(param_1 + 0x59,uVar16,lVar9);
                puVar15 = auStackY_68;
                *(uint *)(lVar9 + 0x1c) = uVar16;
                *(undefined4 *)(lVar9 + 0x18) = 3;
              }
              else if (cVar2 == '\x03') {
                *(uint *)(lVar9 + 0x74) = param_2[1];
                memmove(_Dst,(void *)((ulonglong)*param_2 + (longlong)param_2),(ulonglong)param_2[1]
                       );
                puVar15 = auStackY_68;
                *(byte *)(lVar9 + 0x3e) = *(byte *)(lVar9 + 0x3e) | 2;
                puVar10 = (undefined8 *)(lVar9 + 0x90);
                plVar11 = (longlong *)param_1[0xa1];
                if ((longlong *)*plVar11 != param_1 + 0xa0) {
                  plVar11 = (longlong *)0x3;
                  pcVar6 = (code *)swi(0x29);
                  puVar10 = (undefined8 *)(*pcVar6)();
                  puVar15 = auStackY_60;
                }
                *puVar10 = param_1 + 0xa0;
                puVar10[1] = plVar11;
                *plVar11 = (longlong)puVar10;
                param_1[0xa1] = (longlong)puVar10;
                *(undefined4 *)(lVar9 + 0x18) = 4;
              }
            }
            uVar14 = 0;
            goto LAB_1400272e0;
          }
          if (2 < DAT_140020050) {
            uVar12 = 0xccf;
LAB_14002717a:
            VmbusTraceErrorQueue
                      ("OutRestorePacket",uVar12,*param_1 + 0x6ec,
                       (ulonglong)*(ushort *)(*param_1 + 0xc90),(int)uVar14);
          }
        }
LAB_14002719c:
        puVar15 = auStackY_68;
        if (uVar16 != 0) {
          DvFreeHandleEntry(param_1 + 0x59,uVar16);
          puVar15 = auStackY_68;
        }
        goto LAB_1400272e0;
      }
      uVar14 = 0xc0000102;
      puVar15 = auStackY_68;
      if (DAT_140020050 < 3) goto LAB_1400272e0;
      uVar12 = 0xc52;
    }
  }
  uVar14 = 0xc0000102;
  VmbusTraceErrorQueue
            ("OutRestorePacket",uVar12,lVar9 + 0x6ec,(ulonglong)*(ushort *)(lVar9 + 0xc90),
             0xc0000102);
  puVar15 = auStackY_68;
LAB_1400272e0:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    *(int *)(puVar15 + 0x20) = (int)uVar14;
    *(undefined8 *)(puVar15 + -8) = 0x14002731d;
    WPP_SF_qd(uVar5,0x16,&WPP_5aa4bd3afbb734822e41f6b706e97d47_Traceguids,plVar4,puVar15[0x20]);
  }
  return uVar14;
}



===== OutSavePacket @ 140027340 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int OutSavePacket(longlong *param_1,longlong *param_2,longlong param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined8 uVar5;
  void *pvVar6;
  undefined4 uVar7;
  longlong lVar8;
  ulonglong uVar9;
  code *pcVar10;
  code *pcVar11;
  uint local_res10 [2];
  ulonglong in_stack_ffffffffffffffc8;
  
  local_res10[0] = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_5aa4bd3afbb734822e41f6b706e97d47_Traceguids,param_3);
  }
  lVar8 = *param_2;
  if (((*(char *)(param_3 + 0x3d) != '\0') && (*(longlong *)(lVar8 + 0x840) == 0)) &&
     (*(longlong *)(lVar8 + 0x828) == 0)) {
    iVar3 = -0x3ffffff0;
    if (DAT_140020050 < 3) goto LAB_1400276a4;
    uVar9 = (ulonglong)*(ushort *)(lVar8 + 0xc90);
    lVar8 = lVar8 + 0x6ec;
    uVar7 = 0xaaa;
    goto LAB_1400273db;
  }
  SaveStart(param_1,0x74754f53);
  puVar4 = SaveGetBuffer(param_1,0x10);
  if (puVar4 != (undefined4 *)0x0) {
    puVar4[2] = *(undefined4 *)(param_3 + 0x1c);
    cVar1 = *(char *)(param_3 + 0x3c);
    *puVar4 = 0x10;
    *(byte *)((longlong)puVar4 + 0xd) = cVar1 != '\0' | *(byte *)((longlong)puVar4 + 0xd) & 0xfe;
    iVar3 = *(int *)(param_3 + 0x18);
    if (iVar3 == 2) {
      *(undefined1 *)(puVar4 + 3) = 0;
      uVar7 = *(undefined4 *)(param_3 + 0x38);
LAB_140027455:
      puVar4[1] = uVar7;
    }
    else if (iVar3 == 3) {
      *(undefined1 *)(puVar4 + 3) = 1;
    }
    else if (iVar3 == 4) {
      *(undefined1 *)(puVar4 + 3) = 3;
      uVar7 = *(undefined4 *)(param_3 + 0x74);
      goto LAB_140027455;
    }
  }
  if (*(int *)(param_3 + 0x18) == 2) {
    uVar2 = *(uint *)(param_3 + 0x38);
    pvVar6 = *(void **)(param_3 + 0x30);
LAB_140027477:
    SaveCopyRawBytes(param_1,pvVar6,uVar2);
  }
  else if (*(int *)(param_3 + 0x18) == 4) {
    uVar2 = *(uint *)(param_3 + 0x74);
    pvVar6 = *(void **)(param_3 + 0x68);
    goto LAB_140027477;
  }
  pcVar10 = *(code **)(lVar8 + 0x840);
  if ((pcVar10 != (code *)0x0) || (*(longlong *)(lVar8 + 0x828) != 0)) {
    pcVar11 = *(code **)(lVar8 + 0x828);
    uVar5 = OutPacketToVmbPacket(param_3);
    if (pcVar11 == (code *)0x0) {
      iVar3 = (*pcVar10)(lVar8,uVar5,0,0,local_res10);
    }
    else {
      iVar3 = (*pcVar11)(lVar8,*(undefined8 *)(lVar8 + 0x838),uVar5,0,
                         in_stack_ffffffffffffffc8 & 0xffffffff00000000,local_res10);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_qdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                 &WPP_5aa4bd3afbb734822e41f6b706e97d47_Traceguids,param_3,(char)iVar3,
                 (char)local_res10[0]);
    }
    if (iVar3 < 0) {
      if (iVar3 != -0x3fffffdd) {
        if (DAT_140020050 < 3) goto LAB_1400276a4;
        uVar7 = 0xb1c;
        lVar8 = *param_2 + 0x6ec;
        uVar9 = (ulonglong)*(ushort *)(*param_2 + 0xc90);
LAB_1400273db:
        VmbusTraceErrorQueue("OutSavePacket",uVar7,lVar8,uVar9,iVar3);
        goto LAB_1400276a4;
      }
      pvVar6 = SaveGetBuffer(param_1,local_res10[0]);
      if (pvVar6 != (void *)0x0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                   &WPP_5aa4bd3afbb734822e41f6b706e97d47_Traceguids,param_3);
        }
        pcVar10 = *(code **)(lVar8 + 0x828);
        uVar5 = OutPacketToVmbPacket(param_3);
        if (pcVar10 == (code *)0x0) {
          iVar3 = (**(code **)(lVar8 + 0x840))(lVar8,uVar5,pvVar6,local_res10[0],local_res10);
        }
        else {
          iVar3 = (*pcVar10)(lVar8,*(undefined8 *)(lVar8 + 0x838),uVar5,pvVar6,local_res10[0],
                             local_res10);
        }
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                    &WPP_5aa4bd3afbb734822e41f6b706e97d47_Traceguids,param_3,(char)iVar3);
        }
        if (iVar3 < 0) {
          if (iVar3 == -0x3fffffdd) {
            iVar3 = -0x3fffff1b;
          }
          if (DAT_140020050 < 3) goto LAB_1400276a4;
          uVar7 = 0xb51;
          lVar8 = *param_2 + 0x6ec;
          uVar9 = (ulonglong)*(ushort *)(*param_2 + 0xc90);
          goto LAB_1400273db;
        }
      }
    }
  }
  uVar5 = SaveCommit(param_1);
  iVar3 = (int)uVar5;
LAB_1400276a4:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
              &WPP_5aa4bd3afbb734822e41f6b706e97d47_Traceguids,param_3,(char)iVar3);
  }
  return iVar3;
}



===== OutSaveQueue @ 1400276fc =====

int OutSaveQueue(longlong *param_1,longlong *param_2)

{
  int iVar1;
  longlong *plVar2;
  
  plVar2 = (longlong *)param_2[4];
  if (plVar2 == (longlong *)0x0) {
    plVar2 = (longlong *)param_1[0x22];
  }
  do {
    if (plVar2 == param_1 + 0x22) {
      iVar1 = 0;
LAB_140027794:
      param_2[4] = (longlong)plVar2;
      return iVar1;
    }
    if ((int)plVar2[2] == 1) {
      iVar1 = OutSavePacket(param_2,param_1,(longlong)(plVar2 + -0x12));
    }
    else {
      iVar1 = OutpSaveCompletionPacket(param_2,(longlong)plVar2);
    }
    if (iVar1 < 0) {
      if (2 < DAT_140020050) {
        VmbusTraceErrorQueue
                  ("OutSaveQueue",0xbc0,*param_1 + 0x6ec,(ulonglong)*(ushort *)(*param_1 + 0xc90),
                   iVar1);
      }
      goto LAB_140027794;
    }
    plVar2 = (longlong *)*plVar2;
  } while( true );
}



===== OutSaveSentPackets @ 1400277bc =====

int OutSaveSentPackets(longlong *param_1,longlong *param_2)

{
  int iVar1;
  longlong lVar2;
  uint local_res8 [2];
  
  local_res8[0] = *(uint *)(param_2 + 4);
  while( true ) {
    lVar2 = DvGetNextHandleEntry(param_1 + 0x59,local_res8);
    if (lVar2 == 0) {
      return 0;
    }
    if ((*(int *)(lVar2 + 0x18) == 3) && (iVar1 = OutSavePacket(param_2,param_1,lVar2), iVar1 < 0))
    break;
    *(uint *)(param_2 + 4) = local_res8[0];
  }
  if (DAT_140020050 < 3) {
    return iVar1;
  }
  VmbusTraceErrorQueue
            ("OutSaveSentPackets",0xbf8,*param_1 + 0x6ec,(ulonglong)*(ushort *)(*param_1 + 0xc90),
             iVar1);
  return iVar1;
}



===== OutSetRestorePacket @ 140027868 =====

undefined8 OutSetRestorePacket(longlong *param_1,longlong param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
             &WPP_5aa4bd3afbb734822e41f6b706e97d47_Traceguids,param_2);
  }
  lVar1 = *param_1;
  *(byte *)(lVar1 + 0xbf8) = *(byte *)(param_2 + 0x3e) >> 2 & 1;
  *(byte *)(param_2 + 0x3e) = *(byte *)(param_2 + 0x3e) & 0xfb;
  if (*(uint *)(param_2 + 0xac) < *(uint *)(*(longlong *)(lVar1 + 0xbf0) + 4)) {
    if (DAT_140020050 < 3) {
      return 0xc000000d;
    }
    uVar2 = 0xd5f;
  }
  else {
    if (*(longlong *)(lVar1 + 0xbe8) == 0) {
      *(longlong *)(lVar1 + 0xbe8) = param_2;
      return 0;
    }
    if (DAT_140020050 < 3) {
      return 0xc000000d;
    }
    uVar2 = 0xd67;
  }
  VmbusTraceErrorQueue
            ("OutSetRestorePacket",uVar2,*param_1 + 0x6ec,(ulonglong)*(ushort *)(*param_1 + 0xc90),
             0xc000000d);
  return 0xc000000d;
}



===== OutpSaveCompletionPacket @ 140027948 =====

void OutpSaveCompletionPacket(longlong *param_1,longlong param_2)

{
  undefined8 *puVar1;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
             &WPP_5aa4bd3afbb734822e41f6b706e97d47_Traceguids,param_2);
  }
  SaveStart(param_1,0x506f4353);
  puVar1 = SaveGetBuffer(param_1,8);
  if (puVar1 != (undefined8 *)0x0) {
    *puVar1 = *(undefined8 *)(param_2 + 0x28);
  }
  SaveCopyRawBytes(param_1,*(void **)(param_2 + 0x30),*(uint *)(param_2 + 0x18));
  SaveCommit(param_1);
  return;
}



===== VmbFillChannelDump @ 1400279e0 =====

undefined1 VmbFillChannelDump(void)

{
                    /* 0x279e0  90  VmbFillChannelDump */
  return 0;
}



===== VmbChannelPause @ 1400279f0 =====

void VmbChannelPause(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
                    /* 0x279f0  60  VmbChannelPause */
  KmclpPauseChannel(param_1,'\x01',param_3);
  return;
}



===== VmbChannelPurge @ 140027a10 =====

void VmbChannelPurge(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  ulonglong uVar4;
  longlong lVar5;
  uint uVar6;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
                    /* 0x27a10  62  VmbChannelPurge */
  KmclLockChannel(param_1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = (undefined8 *)&WPP_a989f33e64883200e74810d340c3677a_Traceguids;
    WPP_SF_qdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
               &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1,
               (char)*(undefined4 *)(param_1 + 0x898),(char)*(undefined4 *)(param_1 + 0x89c));
  }
  if (5 < DAT_140020050) {
    cVar2 = _tlgKeywordOn(0x140020050,4);
    if (cVar2 != '\0') {
      param_3 = (undefined8 *)(param_1 + 0x6ec);
      VmbusTraceVerbRundownFnStart
                ("VmbChannelPurge",0x2c3,param_3,*(undefined2 *)(param_1 + 0xc90),
                 *(uint *)(param_1 + 0x898),*(int *)(param_1 + 0x89c),
                 *(undefined4 *)(param_1 + 0x8a8),"");
    }
  }
  *(byte *)(param_1 + 0x8f8) = *(byte *)(param_1 + 0x8f8) & 0xfb;
  iVar3 = *(int *)(param_1 + 0x898);
  if (((iVar3 == 0) || (iVar3 == 1)) || ((iVar3 == 3 || (iVar3 == 0xc)))) {
    KmclUnlockChannel(param_1);
  }
  else {
    if (*(int *)(param_1 + 0x89c) != 4) {
      *(undefined4 *)(param_1 + 0x89c) = 3;
      LOCK();
      piVar1 = (int *)(param_1 + 0xca0);
      iVar3 = *piVar1;
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      uVar6 = iVar3 + 1;
      uVar4 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar4 == 0) {
        iVar3 = (int)((ulonglong)((longlong)(int)uVar6 * -0x2aaaaaab) >> 0x20);
        iVar3 = ((iVar3 >> 2) - (iVar3 >> 0x1f)) * 0x18;
      }
      else {
        iVar3 = (uVar6 / 0x18) * -0x18;
      }
      lVar5 = (longlong)(int)(uVar6 + iVar3);
      *(undefined1 *)(param_1 + 0xca4 + lVar5 * 6) = *(undefined1 *)(param_1 + 0x898);
      *(undefined1 *)(param_1 + 0xca5 + lVar5 * 6) = *(undefined1 *)(param_1 + 0x89c);
      *(short *)(param_1 + 0xca6 + lVar5 * 6) = (short)*(undefined4 *)(param_1 + 0x8a8);
      *(undefined2 *)(param_1 + 0xca8 + lVar5 * 6) = 0x2d3;
      if (4 < DAT_140020050) {
        param_3 = &local_38;
        local_38 = *(undefined8 *)(param_1 + 0xa90);
        uStack_30 = *(undefined8 *)(param_1 + 0xa98);
        local_28 = *(undefined8 *)(param_1 + 0xa80);
        uStack_20 = *(undefined8 *)(param_1 + 0xa88);
        local_18 = *(undefined8 *)(param_1 + 0xaa0);
        uStack_10 = *(undefined8 *)(param_1 + 0xaa8);
        VmbusTraceInfoChannelStateChange
                  (&local_18,&local_28,param_3,(ulonglong)*(ushort *)(param_1 + 0xc90),
                   *(undefined4 *)(param_1 + 0x898),*(undefined4 *)(param_1 + 0x89c),
                   *(undefined4 *)(param_1 + 0x8a8),0x2d3);
      }
    }
    KmclpRundownChannelStateAndUnlock(param_1,'\x01',param_3);
  }
  if (5 < DAT_140020050) {
    cVar2 = _tlgKeywordOn(0x140020050,4);
    if (cVar2 != '\0') {
      VmbusTraceVerbRundownFnStop
                ("VmbChannelPurge",0x2d9,param_1 + 0x6ec,*(undefined2 *)(param_1 + 0xc90),
                 *(uint *)(param_1 + 0x898),*(int *)(param_1 + 0x89c),
                 *(undefined4 *)(param_1 + 0x8a8),"");
    }
  }
  return;
}



===== VmbChannelStart @ 140027ca0 =====

void VmbChannelStart(longlong *param_1,undefined8 param_2,longlong *param_3)

{
  byte bVar1;
  
                    /* 0x27ca0  79  VmbChannelStart */
  KmclLockChannel((longlong)param_1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qL_guid__guid_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(longlong)param_1 + 0x6dc,param_3,param_1,
               (char)param_1[0x113],(longlong)param_1 + 0x6dc,(longlong)param_1 + 0x6ec);
  }
  bVar1 = *(byte *)(param_1 + 0x11f);
  if ((bVar1 & 6) == 0) {
    KmclpStartChannelAndUnlock(param_1,(ulonglong)bVar1,param_3);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
               &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1);
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_qLdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)(bVar1 >> 1 & 1),param_3,
                  param_1,(char)param_1[0x113],bVar1 >> 1 & 1,bVar1 >> 2 & 1);
    }
    KmclUnlockChannel((longlong)param_1);
  }
  return;
}



===== VmbChannelGetStatistics @ 140027db0 =====

void VmbChannelGetStatistics(longlong param_1,ulonglong *param_2)

{
                    /* 0x27db0  26  VmbChannelGetStatistics */
  *param_2 = (ulonglong)*(uint *)(param_1 + 0x1c8);
  param_2[1] = (ulonglong)*(uint *)(param_1 + 0x530);
  param_2[2] = *(ulonglong *)(param_1 + 0x680);
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = *(ulonglong *)(param_1 + 0x4a8);
  param_2[6] = *(ulonglong *)(param_1 + 0x4a0);
  param_2[7] = *(ulonglong *)(param_1 + 0x1d8);
  param_2[8] = *(ulonglong *)(param_1 + 0x1e0);
  param_2[9] = *(ulonglong *)(param_1 + 0x1e8);
  param_2[10] = *(ulonglong *)(param_1 + 0x540);
  param_2[0xb] = *(ulonglong *)(param_1 + 0x548);
  param_2[0xc] = *(ulonglong *)(param_1 + 0x688);
  param_2[0xd] = *(ulonglong *)(param_1 + 0x538);
  param_2[0xe] = (ulonglong)(uint)(*(int *)(param_1 + 0x520) - *(int *)(param_1 + 0x478));
  param_2[0xf] = 0;
  param_2[0x10] = 0;
  param_2[0x11] = 0;
  param_2[0x12] = 0;
  param_2[0x13] = 0;
  param_2[0x14] = 0;
  param_2[0x15] = 0;
  *(undefined4 *)(param_2 + 0x16) = 0;
  param_2[0x17] = 0;
  *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(param_1 + 0x1cc);
  *(undefined8 *)((longlong)param_2 + 0xc4) = 0;
  *(undefined4 *)((longlong)param_2 + 0xcc) = 0;
  memset(param_2 + 0x1a,0,0x60);
  return;
}



===== TraceLoggingRegisterEx_EtwRegister_EtwSetInformation @ 140027eb4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(longlong param_1)

{
  longlong *plVar1;
  undefined2 uVar2;
  longlong lVar3;
  undefined2 *puVar4;
  code *pcVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  ulonglong local_18;
  
  puVar7 = auStack_48;
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  lVar3 = *(longlong *)(param_1 + 8);
  plVar1 = (longlong *)(param_1 + 0x20);
  local_28 = *(undefined4 *)(lVar3 + -0x10);
  uStack_24 = *(undefined4 *)(lVar3 + -0xc);
  uStack_20 = *(undefined4 *)(lVar3 + -8);
  uStack_1c = *(undefined4 *)(lVar3 + -4);
  if (*plVar1 != 0) {
    pcVar5 = (code *)swi(0x29);
    (*pcVar5)(5);
    puVar7 = auStack_40;
  }
  *(undefined8 *)(param_1 + 0x28) = 0;
  *(undefined8 *)(param_1 + 0x30) = 0;
  *(undefined8 *)(puVar7 + -8) = 0x140027f17;
  iVar6 = EtwRegister(puVar7 + 0x20,_tlgEnableCallback,param_1,plVar1);
  if (iVar6 == 0) {
    puVar4 = *(undefined2 **)(param_1 + 8);
    lVar3 = *plVar1;
    uVar2 = *puVar4;
    *(undefined8 *)(puVar7 + -8) = 0x140027f37;
    EtwSetInformation(lVar3,2,puVar4,uVar2);
  }
  *(undefined8 *)(puVar7 + -8) = 0x140027f4b;
  return iVar6;
}



===== WppCleanupKm @ 140027f64 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WppCleanupKm(void)

{
  undefined *puVar1;
  
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
  return;
}



===== WppInitKm @ 140027fe4 =====

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



===== WppLoadTracingSupport @ 140028074 =====

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



===== WppTraceCallback @ 1400281c0 =====

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



===== _tlgEnableCallback @ 140028450 =====

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



===== wil_UninitializeFeatureStaging @ 1400284cc =====

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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 140028524 =====

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
      goto LAB_140028581;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_140028581;
    }
  }
  uVar1 = 0x206;
LAB_140028581:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 14002858c =====

void wil_details_EvaluateFeatureDependencies(void)

{
  longlong *plVar1;
  undefined **ppuVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  bool bVar6;
  
  plVar1 = wil_details_FeatureDescriptors_SkipPadding((longlong *)&wil_details_featureDescriptors_a)
  ;
  if (plVar1 != (longlong *)0x0) {
    uVar4 = 0;
    uVar5 = 0x180;
    do {
      uVar3 = *(uint *)*plVar1;
      if ((uVar3 >> 9 & 1) != 0) {
        if (((uint)uVar5 & uVar3) == 0) {
          bVar6 = *(char *)((longlong)plVar1 + 0x1f) != '\0';
        }
        else {
          bVar6 = (uVar3 & (uint)uVar5) == 0x100;
        }
        uVar3 = uVar3 & 0x40 ^ (uint)bVar6 << 6 | (uint)uVar4 & 0xffffffbf;
        uVar4 = (ulonglong)uVar3;
        LOCK();
        *(uint *)*plVar1 = *(uint *)*plVar1 ^ uVar3;
        UNLOCK();
      }
      plVar1 = wil_details_FeatureDescriptors_SkipPadding(plVar1 + 7);
    } while (plVar1 != (longlong *)0x0);
  }
  ppuVar2 = &wil_details_featureDescriptors_a;
  while( true ) {
    plVar1 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar2);
    if (plVar1 == (longlong *)0x0) break;
    wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
              ((uint *)*plVar1,(longlong)plVar1);
    ppuVar2 = (undefined **)(plVar1 + 7);
  }
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 140028644 =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 14002867c =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_1400286fe;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_1400286fe;
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
LAB_1400286fe:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 140028750 =====

void wil_details_OnFeatureUsageProviderFlushNotification(int param_1)

{
  int iVar1;
  longlong *plVar2;
  undefined **ppuVar3;
  
  iVar1 = g_wil_details_featureUsageCached;
  if (param_1 == 1) {
    LOCK();
    g_wil_details_featureUsageCached = 0;
    UNLOCK();
    if (iVar1 != 0) {
      ppuVar3 = &wil_details_featureDescriptors_a;
      while (plVar2 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar3),
            plVar2 != (longlong *)0x0) {
        if ((*(uint *)plVar2[1] & 1) != 0) {
          wil_details_RecordCachedUsage((int)plVar2[3],(uint *)plVar2[1]);
        }
        ppuVar3 = (undefined **)(plVar2 + 7);
      }
    }
  }
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 1400287b0 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 1400287cc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_UpdateFeatureConfiguredStates(void)

{
  int iVar1;
  longlong *plVar2;
  undefined **ppuVar3;
  undefined1 auStack_58 [32];
  uint local_38 [2];
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  ppuVar3 = &wil_details_featureDescriptors_a;
  while( true ) {
    plVar2 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar3);
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
    ppuVar3 = (undefined **)(plVar2 + 7);
  }
  return;
}



===== KmclpCreateInstanceName @ 140028880 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int KmclpCreateInstanceName(longlong param_1,ushort *param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined2 local_res8 [4];
  ushort local_38;
  short local_36;
  undefined4 local_34;
  longlong local_30;
  undefined8 local_28;
  longlong lStack_20;
  
  local_34 = 0;
  local_res8[0] = 0;
  local_28 = 0;
  lStack_20 = 0;
  KmclpGetInstanceNameLength(param_1);
  if (*(char *)(param_1 + 0x6c0) != '\0') {
    param_4 = 0;
    (**(code **)(param_1 + 0x9e0))(*(undefined8 *)(param_1 + 0x910),param_2,local_res8);
    RtlAppendUnicodeToString(param_2,L":");
  }
  if (*(longlong *)(param_1 + 0x890) != 0) {
    RtlAppendUnicodeStringToString(param_2,param_1 + 0x888);
    RtlAppendUnicodeToString(param_2,L"-");
  }
  iVar1 = RtlStringFromGUID(param_1 + 0xa90,&local_28);
  if (-1 < iVar1) {
    RtlAppendUnicodeStringToString(param_2,&local_28);
    if (*(ushort *)(param_1 + 0xc90) != 0) {
      local_38 = 0;
      local_30 = *(longlong *)(param_2 + 4) + (ulonglong)(*param_2 >> 1) * 2;
      local_36 = param_2[1] - *param_2;
      RtlUnicodeStringPrintf(&local_38,L"-%04x",(ulonglong)*(ushort *)(param_1 + 0xc90),param_4);
      *param_2 = *param_2 + local_38;
    }
    iVar1 = 0;
  }
  if (lStack_20 != 0) {
    ExFreePoolWithTag(lStack_20,0x636d6b56);
  }
  return iVar1;
}



===== KmclpStatsCallback @ 1400289e0 =====

int KmclpStatsCallback(int param_1,uint *param_2,undefined8 *param_3)

{
  int iVar1;
  
  iVar1 = (int)param_3;
  if (param_1 == 0) {
    if (iVar1 == 1) {
      KmclPerformanceCounterTimingCounters =
           KmclPerformanceCounterTimingCounters | (ulonglong)(*param_2 & 0x200000) | 0xfc00000;
    }
  }
  else {
    if (param_1 != 1) {
      if ((param_1 == 2) || (param_1 == 3)) {
        iVar1 = KmclpStatsRequest(iVar1,param_2[4],*(ulonglong *)(param_2 + 6),param_3);
        return iVar1;
      }
      return -0x3fffffff;
    }
    if (iVar1 == 1) {
      KmclPerformanceCounterTimingCounters =
           KmclPerformanceCounterTimingCounters & ~((ulonglong)(*param_2 & 0x200000) | 0xfc00000);
    }
  }
  return 0;
}



===== SaveContinueSaving @ 140028a5c =====

ulonglong SaveContinueSaving(longlong *param_1,longlong param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined4 *puVar7;
  
  while( true ) {
    iVar1 = *(int *)((longlong)param_1 + 0x14);
    if (iVar1 == 7) {
      return 0;
    }
    if (iVar1 == 0) break;
    if (iVar1 == 1) {
      uVar5 = InSaveQueue((longlong *)param_1[6],param_1);
      uVar6 = uVar5 & 0xffffffff;
      if ((int)uVar5 < 0) goto LAB_140028bda;
      *(undefined4 *)((longlong)param_1 + 0x14) = 4;
      goto LAB_140028bce;
    }
    if (iVar1 == 3) {
      uVar3 = OutSaveQueue((longlong *)param_1[6],param_1);
      uVar6 = (ulonglong)uVar3;
      if ((int)uVar3 < 0) goto LAB_140028bda;
      *(undefined4 *)((longlong)param_1 + 0x14) = 5;
      goto LAB_140028bce;
    }
    if (iVar1 == 4) {
      uVar3 = OutSaveSentPackets((longlong *)param_1[6],param_1);
      uVar6 = (ulonglong)uVar3;
      if ((int)uVar3 < 0) goto LAB_140028bda;
      *(undefined4 *)((longlong)param_1 + 0x14) = 3;
      goto LAB_140028bce;
    }
    if (iVar1 == 5) {
      uVar6 = SaveWriteNextSubChannel(param_1,param_2);
      iVar1 = (int)uVar6;
      uVar6 = uVar6 & 0xffffffff;
      if (((iVar1 + 0x80000000U & 0x80000000) == 0) && (iVar1 != -0x7fffffe6)) goto LAB_140028bda;
      iVar2 = 6;
      if (iVar1 != -0x7fffffe6) {
        iVar2 = 1;
      }
      *(int *)((longlong)param_1 + 0x14) = iVar2;
      if (iVar2 != 5) {
LAB_140028bce:
        param_1[4] = 0;
        param_1[5] = 0;
      }
    }
    else if (iVar1 == 6) {
      SaveStart(param_1,0x646e4553);
      uVar5 = SaveCommit(param_1);
      uVar6 = uVar5 & 0xffffffff;
      if ((int)uVar5 < 0) {
LAB_140028bda:
        if ((int)uVar6 != -0x3fffffdd) {
          return uVar6;
        }
        if ((int)param_1[2] == 0) {
          return uVar6;
        }
        return 0x80000005;
      }
      *(undefined4 *)((longlong)param_1 + 0x14) = 7;
      goto LAB_140028bce;
    }
  }
  SaveStart(param_1,0x72655653);
  puVar7 = SaveGetBuffer(param_1,8);
  if (puVar7 != (undefined4 *)0x0) {
    *puVar7 = 2;
  }
  uVar5 = SaveCommit(param_1);
  uVar6 = uVar5 & 0xffffffff;
  if ((int)uVar5 < 0) goto LAB_140028bda;
  uVar4 = 1;
  if (*(int *)(param_2 + 0x898) == 0xb) {
    uVar4 = 6;
  }
  *(undefined4 *)((longlong)param_1 + 0x14) = uVar4;
  goto LAB_140028bce;
}



===== VmbChannelRestoreFromBuffer @ 140028c20 =====

ulonglong VmbChannelRestoreFromBuffer(longlong param_1,int *param_2,uint param_3)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  longlong lVar7;
  ulonglong uVar8;
  longlong *plVar9;
  longlong *local_res8;
  
  KmclLockChannel(param_1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_74c40c40472c3852eed534411c352eab_Traceguids,param_1,
               (char)*(undefined4 *)(param_1 + 0x898),*(byte *)(param_1 + 0x8f8) >> 2 & 1);
  }
  if ((*(byte *)(param_1 + 0x8f8) & 4) == 0) {
    if (*(int *)(param_1 + 0x898) != 3) {
      if (*(int *)(param_1 + 0x898) == 4) {
        lVar7 = param_1;
        uVar3 = InIsQueuePurged(param_1);
        if ((char)uVar3 != '\0') {
          uVar5 = OutIsQueuePurged(lVar7);
          if ((char)uVar5 != '\0') goto LAB_140028cd1;
        }
      }
LAB_140028cb2:
      uVar8 = 0xc0000184;
LAB_140028dfe:
      KmclUnlockChannel(param_1);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                  &WPP_74c40c40472c3852eed534411c352eab_Traceguids,param_1,(char)uVar8);
      }
      return uVar8;
    }
LAB_140028cd1:
    *(byte *)(param_1 + 0x8f8) = *(byte *)(param_1 + 0x8f8) | 4;
    *(undefined4 *)(param_1 + 0xbfc) = 0;
    *(longlong *)(param_1 + 0xbe0) = param_1;
  }
  plVar9 = *(longlong **)(param_1 + 0xbe0);
  local_res8 = plVar9;
LAB_140028cf2:
  if (param_3 == 0) goto LAB_140028df9;
  if (param_3 < 0x10) {
    uVar8 = 0xc0000206;
    goto LAB_140028dfe;
  }
  uVar4 = param_2[1];
  puVar1 = (uint *)(param_2 + 4);
  if ((ulonglong)param_3 - 0x10 < (ulonglong)uVar4) {
    uVar8 = 0xc0000023;
    goto LAB_140028dfe;
  }
  if (*(int *)(param_1 + 0xbfc) != param_2[2]) goto LAB_140028de4;
  iVar2 = *param_2;
  if (iVar2 == 0x506f4353) {
    uVar4 = OutRestoreCompletionPacket(plVar9,(longlong *)puVar1,uVar4);
  }
  else {
    if (iVar2 == 0x50745353) {
      if (*(int *)(param_1 + 0x898) == 4) {
        uVar4 = InRestorePacket(plVar9,(ushort *)puVar1,uVar4);
        goto LAB_140028db4;
      }
      goto LAB_140028cb2;
    }
    if (iVar2 == 0x62755353) {
      uVar6 = RestoreFindSubChannel(param_1,(short *)puVar1,uVar4,&local_res8);
      uVar8 = uVar6 & 0xffffffff;
      if ((int)uVar6 < 0) goto LAB_140028dfe;
      *(longlong **)(param_1 + 0xbe0) = local_res8;
      plVar9 = local_res8;
      goto LAB_140028dba;
    }
    if (iVar2 == 0x646e4553) {
      *(byte *)(param_1 + 0x8f8) = *(byte *)(param_1 + 0x8f8) & 0xfb;
      uVar8 = 0;
      goto LAB_140028dfe;
    }
    if (iVar2 != 0x72655653) {
      if (iVar2 == 0x74754f53) {
        uVar8 = OutRestorePacket(plVar9,puVar1,uVar4);
        uVar4 = (uint)uVar8;
        goto LAB_140028db4;
      }
LAB_140028de4:
      uVar8 = 0xc0000102;
      goto LAB_140028dfe;
    }
    if (param_2[2] != 0) goto LAB_140028de4;
    uVar4 = RestoreReadVersion(0,(short *)puVar1,uVar4);
  }
LAB_140028db4:
  uVar8 = (ulonglong)uVar4;
  if ((int)uVar4 < 0) goto LAB_140028dfe;
LAB_140028dba:
  param_3 = param_3 + (-0x10 - param_2[1]);
  param_2 = (int *)((longlong)param_2 + (ulonglong)(uint)param_2[1] + 0x10);
  *(int *)(param_1 + 0xbfc) = *(int *)(param_1 + 0xbfc) + 1;
  goto LAB_140028cf2;
LAB_140028df9:
  uVar8 = 0xc0000016;
  goto LAB_140028dfe;
}



===== VmbChannelSaveBegin @ 140028e60 =====

undefined8 VmbChannelSaveBegin(longlong param_1)

{
  byte bVar1;
  int iVar2;
  undefined8 uVar3;
  
                    /* 0x28e60  64  VmbChannelSaveBegin */
  KmclLockChannel(param_1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
               &WPP_74c40c40472c3852eed534411c352eab_Traceguids,param_1,
               (char)*(undefined4 *)(param_1 + 0x898),(char)*(undefined4 *)(param_1 + 0x89c));
  }
  bVar1 = *(byte *)(param_1 + 0x8f8);
  if ((bVar1 & 6) == 0) {
    iVar2 = *(int *)(param_1 + 0x898);
    if ((iVar2 - 3U < 2) || ((iVar2 == 0xb && (*(int *)(param_1 + 0x89c) == 3)))) {
      uVar3 = 0;
      *(undefined8 *)(param_1 + 0xbe0) = 0;
      *(undefined8 *)(param_1 + 0xbe8) = 0;
      *(undefined8 *)(param_1 + 0xbf0) = 0;
      *(undefined8 *)(param_1 + 0xbf8) = 0;
      *(undefined8 *)(param_1 + 0xc00) = 0;
      *(undefined8 *)(param_1 + 0xc08) = 0;
      *(undefined8 *)(param_1 + 0xbe8) = 0;
      *(undefined4 *)(param_1 + 0xbf0) = 0;
      *(longlong *)(param_1 + 0xc10) = param_1;
      *(byte *)(param_1 + 0x8f8) = *(byte *)(param_1 + 0x8f8) | 2;
      goto LAB_140028fce;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_qdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                 &WPP_74c40c40472c3852eed534411c352eab_Traceguids,param_1,(char)iVar2,
                 (char)*(undefined4 *)(param_1 + 0x89c));
    }
  }
  else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
               &WPP_74c40c40472c3852eed534411c352eab_Traceguids,param_1,bVar1 >> 1 & 1,
               bVar1 >> 2 & 1);
  }
  uVar3 = 0xc0000184;
LAB_140028fce:
  KmclUnlockChannel(param_1);
  return uVar3;
}



===== VmbChannelSaveContinue @ 140028ff0 =====

ulonglong VmbChannelSaveContinue
                    (longlong param_1,longlong param_2,undefined4 param_3,undefined4 *param_4,
                    int *param_5)

{
  ulonglong uVar1;
  
                    /* 0x28ff0  65  VmbChannelSaveContinue */
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
             &WPP_74c40c40472c3852eed534411c352eab_Traceguids,param_1);
  }
  KmclLockChannel(param_1);
  if ((*(byte *)(param_1 + 0x8f8) & 2) == 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
               &WPP_74c40c40472c3852eed534411c352eab_Traceguids,param_1);
    }
    uVar1 = 0xc0000184;
  }
  else {
    *(undefined4 *)(param_1 + 0xbec) = 0;
    *(undefined4 *)(param_1 + 0xbf0) = 0;
    *(longlong *)(param_1 + 0xbe0) = param_2;
    *(undefined4 *)(param_1 + 0xbe8) = param_3;
    uVar1 = SaveContinueSaving((longlong *)(param_1 + 0xbe0),param_1);
    uVar1 = uVar1 & 0xffffffff;
    *param_4 = *(undefined4 *)(param_1 + 0xbf0);
    *param_5 = *(int *)(param_1 + 0xbec) - *(int *)(param_1 + 0xbf0);
  }
  KmclUnlockChannel(param_1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
              &WPP_74c40c40472c3852eed534411c352eab_Traceguids,param_1,(char)uVar1);
  }
  return uVar1;
}



===== VmbChannelSaveEnd @ 140029130 =====

void VmbChannelSaveEnd(longlong param_1)

{
                    /* 0x29130  66  VmbChannelSaveEnd */
  KmclLockChannel(param_1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
             &WPP_74c40c40472c3852eed534411c352eab_Traceguids,param_1);
  }
  *(byte *)(param_1 + 0x8f8) = *(byte *)(param_1 + 0x8f8) & 0xfd;
  *(undefined8 *)(param_1 + 0xbe0) = 0;
  *(undefined8 *)(param_1 + 0xbe8) = 0;
  *(undefined8 *)(param_1 + 0xbf0) = 0;
  *(undefined8 *)(param_1 + 0xbf8) = 0;
  *(undefined8 *)(param_1 + 0xc00) = 0;
  *(undefined8 *)(param_1 + 0xc08) = 0;
  *(undefined8 *)(param_1 + 0xc10) = 0;
  KmclUnlockChannel(param_1);
  return;
}



===== KmclpServerOfferChannel @ 1400291b4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong KmclpServerOfferChannel(longlong *param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined2 uVar6;
  longlong *plVar7;
  ulonglong uVar8;
  longlong *_Dst;
  undefined1 auStackY_2b8 [32];
  undefined8 local_248;
  ushort local_240 [4];
  undefined1 *local_238;
  undefined8 local_230;
  undefined8 local_228;
  longlong lStack_220;
  ushort *local_218;
  undefined8 uStack_210;
  undefined8 local_208;
  ulonglong uStack_200;
  longlong local_1f8;
  longlong lStack_1f0;
  undefined8 local_1e8;
  undefined8 uStack_1e0;
  longlong local_1d8;
  longlong lStack_1d0;
  longlong local_1c8;
  longlong lStack_1c0;
  longlong local_1b8;
  undefined8 uStack_1b0;
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  ulonglong local_198;
  ushort local_190;
  undefined2 local_18e;
  undefined2 local_18c;
  undefined2 local_18a;
  undefined1 local_188;
  longlong local_180;
  longlong lStack_178;
  longlong local_170;
  longlong lStack_168;
  longlong local_160;
  longlong lStack_158;
  longlong local_150;
  longlong lStack_148;
  longlong local_140;
  longlong lStack_138;
  longlong local_130;
  longlong lStack_128;
  longlong local_120;
  longlong lStack_118;
  longlong local_110;
  wchar_t local_f8 [32];
  undefined1 local_b8 [128];
  ulonglong local_38;
  
  _Dst = &local_1b8;
  local_38 = __security_cookie ^ (ulonglong)auStackY_2b8;
  builtin_wcsncpy(local_f8 + 0x10,L"s\\offer\\",9);
  local_238 = local_b8;
  builtin_wcsncpy(local_f8,L"\\DosDevices\\VMBu",0x10);
  local_240[0] = 0;
  local_240[1] = 0x7e;
  local_240[2] = 0;
  local_240[3] = 0;
  local_230 = 0;
  local_248 = 0;
  local_208 = 0;
  uStack_200 = uStack_200 & 0xffffffff00000000;
  local_1e8 = 0;
  uStack_1e0 = 0;
  local_228 = 0;
  lStack_220 = 0;
  local_218 = (ushort *)0x0;
  uStack_210 = 0;
  memset(_Dst,0,0xc0);
  param_1[0x150] = *(longlong *)((longlong)param_1 + 0x6dc);
  param_1[0x151] = *(longlong *)((longlong)param_1 + 0x6e4);
  *(undefined4 *)(param_1 + 0x152) = *(undefined4 *)((longlong)param_1 + 0x6ec);
  *(int *)((longlong)param_1 + 0xa94) = (int)param_1[0xde];
  *(undefined4 *)(param_1 + 0x153) = *(undefined4 *)((longlong)param_1 + 0x6f4);
  *(int *)((longlong)param_1 + 0xa9c) = (int)param_1[0xdf];
  if (param_1[0xf4] == 0) {
    RtlUnicodeStringPrintf
              (local_240,L"%s{%08lx-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x}",local_f8,
               (ulonglong)*(uint *)(param_1 + 0xe2));
    lStack_220 = 0;
LAB_140029440:
    uStack_210 = CONCAT44(uStack_210._4_4_,0x240);
    local_218 = local_240;
    local_228 = CONCAT44(local_228._4_4_,0x30);
    local_208 = 0;
    uStack_200 = 0;
    uVar2 = ZwOpenFile(&local_248,0x1f01ff,&local_228,&local_1e8);
    uVar8 = (ulonglong)uVar2;
    if (-1 < (int)uVar2) {
      local_1f8 = 0;
      ObReferenceObjectByHandle(local_248,0,*(undefined8 *)IoFileObjectType_exref,0);
      param_1[0x14f] = local_1f8;
      ZwClose(local_248);
      lVar4 = IoGetRelatedDeviceObject(param_1[0x14f]);
      param_1[0x14e] = lVar4;
      ObfReferenceObject(lVar4);
      local_18e = *(undefined2 *)((longlong)param_1 + 0x70a);
      local_1b8 = *(longlong *)((longlong)param_1 + 0x6dc);
      uStack_1b0 = *(undefined8 *)((longlong)param_1 + 0x6e4);
      local_18c = *(undefined2 *)((longlong)param_1 + 0x70c);
      local_1a8 = *(undefined8 *)((longlong)param_1 + 0x6ec);
      uStack_1a0 = *(undefined8 *)((longlong)param_1 + 0x6f4);
      local_188 = *(undefined1 *)((longlong)param_1 + 0x7c3);
      if (*(ushort *)(param_1 + 0xe1) != 0) {
        local_190 = local_190 | 0x400;
        local_198 = (ulonglong)*(ushort *)(param_1 + 0xe1);
      }
      if (*(char *)((longlong)param_1 + 0x703) != '\0') {
        local_190 = local_190 | 0x10;
      }
      if (*(char *)((longlong)param_1 + 0x701) != '\0') {
        local_190 = local_190 | 0x100;
      }
      if (*(char *)((longlong)param_1 + 0x702) != '\0') {
        local_190 = local_190 | 1;
      }
      if (*(char *)((longlong)param_1 + 0x704) != '\0') {
        local_190 = local_190 | 0x1000;
      }
      if (*(char *)((longlong)param_1 + 0x705) != '\0') {
        local_190 = local_190 | 0x2000;
      }
      if ((char)param_1[0x184] != '\0') {
        local_18a = (undefined2)param_1[0x192];
      }
      local_180 = param_1[0xe4];
      lStack_178 = param_1[0xe5];
      local_170 = param_1[0xe6];
      lStack_168 = param_1[0xe7];
      local_160 = param_1[0xe8];
      lStack_158 = param_1[0xe9];
      local_150 = param_1[0xea];
      lStack_148 = param_1[0xeb];
      local_140 = param_1[0xec];
      lStack_138 = param_1[0xed];
      local_130 = param_1[0xee];
      lStack_128 = param_1[0xef];
      local_120 = param_1[0xf0];
      lStack_118 = param_1[0xf1];
      local_110 = param_1[0xf2];
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x40,
                 &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1);
      }
      uVar5 = KmclpSynchronousIoControl((longlong)param_1,0x3ec01c,_Dst,0xc0,0,0);
      uVar8 = uVar5 & 0xffffffff;
      if (-1 < (int)uVar5) {
        uVar2 = VmbusSendInterfaceQuery((longlong)param_1);
        uVar8 = (ulonglong)uVar2;
        if ((int)uVar2 < 0) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar6 = 0x41;
LAB_1400296df:
            WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
                      &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1,(char)uVar8);
          }
        }
        else {
          uVar2 = KmclpInitializeVmbusConnection((longlong)param_1);
          uVar8 = (ulonglong)uVar2;
          if ((int)uVar2 < 0) {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              uVar6 = 0x42;
              goto LAB_1400296df;
            }
          }
          else {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
               (3 < (byte)WPP_GLOBAL_Control[0x29])) {
              _Dst = (longlong *)&WPP_a989f33e64883200e74810d340c3677a_Traceguids;
              WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x43,
                       &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1);
            }
            *(undefined4 *)(param_1 + 0x113) = 3;
            LOCK();
            plVar7 = param_1 + 0x194;
            lVar4 = *plVar7;
            *(int *)plVar7 = (int)*plVar7 + 1;
            UNLOCK();
            uVar2 = (int)lVar4 + 1;
            uVar8 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
            if ((int)uVar8 == 0) {
              iVar3 = (int)((ulonglong)((longlong)(int)uVar2 * -0x2aaaaaab) >> 0x20);
              iVar3 = ((iVar3 >> 2) - (iVar3 >> 0x1f)) * 0x18;
            }
            else {
              iVar3 = (uVar2 / 0x18) * -0x18;
            }
            plVar7 = (longlong *)(longlong)(int)(uVar2 + iVar3);
            *(char *)((longlong)param_1 + (longlong)plVar7 * 6 + 0xca4) = (char)param_1[0x113];
            *(undefined1 *)((longlong)param_1 + (longlong)plVar7 * 6 + 0xca5) =
                 *(undefined1 *)((longlong)param_1 + 0x89c);
            *(short *)((longlong)param_1 + (longlong)plVar7 * 6 + 0xca6) = (short)param_1[0x115];
            *(undefined2 *)((longlong)param_1 + (longlong)plVar7 * 6 + 0xca8) = 0xa31;
            if (4 < DAT_140020050) {
              _Dst = &local_1f8;
              local_1f8 = param_1[0x152];
              lStack_1f0 = param_1[0x153];
              plVar7 = &local_1d8;
              local_1d8 = param_1[0x150];
              lStack_1d0 = param_1[0x151];
              local_1c8 = param_1[0x154];
              lStack_1c0 = param_1[0x155];
              VmbusTraceInfoChannelStateChange
                        (&local_1c8,plVar7,_Dst,(ulonglong)*(ushort *)(param_1 + 0x192),
                         (int)param_1[0x113],*(undefined4 *)((longlong)param_1 + 0x89c),
                         (int)param_1[0x115],0xa31);
            }
            uVar5 = KmclpServerOpenChannel(param_1,plVar7,_Dst);
            uVar8 = uVar5 & 0xffffffff;
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
               (3 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x44,
                        &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1,(char)uVar5);
            }
            if ((((int)uVar5 + 0x80000000U & 0x80000000) != 0) || ((int)uVar5 == -0x3fffff5d)) {
              uVar8 = 0;
              goto LAB_1400292d0;
            }
          }
        }
      }
    }
  }
  else {
    cVar1 = ObIsKernelHandle();
    if (cVar1 != '\0') {
      uVar2 = ZwQueryVolumeInformationFile(param_1[0xf4],&local_1e8,&local_230,8);
      uVar8 = (ulonglong)uVar2;
      if ((int)uVar2 < 0) goto LAB_1400292c8;
      if ((int)local_230 == 0x3e) {
        RtlAppendUnicodeToString(local_240,L"offer");
        lStack_220 = param_1[0xf4];
        goto LAB_140029440;
      }
    }
    uVar8 = 0xc000000d;
  }
LAB_1400292c8:
  KmclpDisableClosedChannel((longlong)param_1);
LAB_1400292d0:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x45,
              &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1,(char)uVar8);
  }
  return uVar8;
}



===== KmclpServerOpenChannel @ 1400298c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong KmclpServerOpenChannel(longlong *param_1,undefined8 param_2,undefined8 param_3)

{
  longlong *plVar1;
  bool bVar2;
  int iVar3;
  ulonglong uVar4;
  undefined2 uVar5;
  longlong lVar6;
  longlong lVar7;
  uint uVar8;
  uint uVar9;
  ulonglong uVar10;
  undefined1 auStackY_e8 [32];
  longlong local_a8 [2];
  longlong local_98;
  longlong lStack_90;
  longlong local_88;
  longlong lStack_80;
  longlong local_78;
  longlong lStack_70;
  undefined8 local_68;
  undefined4 local_60;
  longlong local_58 [6];
  
  local_58[4] = __security_cookie ^ (ulonglong)auStackY_e8;
  local_a8[0] = 0;
  bVar2 = false;
  local_68 = 0;
  local_60 = 0;
  local_58[0] = 0;
  local_58[1] = 0;
  local_58[2] = 0;
  local_58[3] = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x52,param_3,param_1,(char)param_1[0x113]);
  }
  uVar9 = (*(code *)param_1[0x126])(param_1[0x122],&local_68);
  uVar10 = (ulonglong)uVar9;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x53,
              &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1,(char)uVar9);
  }
  if ((int)uVar9 < 0) {
LAB_140029e11:
    KmclpTeardownOpenChannelState(param_1);
    if (!bVar2) goto LAB_140029e97;
  }
  else {
    *(undefined2 *)(param_1 + 0x191) = (undefined2)local_60;
    bVar2 = true;
    uVar9 = (*(code *)param_1[0x12e])(param_1[0x122],local_68 & 0xffffffff,2,local_a8);
    uVar10 = (ulonglong)uVar9;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x54,
                &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1,(char)uVar9);
    }
    if ((int)uVar9 < 0) goto LAB_140029e11;
    *(undefined4 *)(param_1 + 0x17b) = (undefined4)local_68;
    if ((*(int *)(local_a8[0] + 0x2c) != 0) || ((*(uint *)(local_a8[0] + 0x28) & 0xfff) != 0)) {
LAB_140029e0c:
      uVar10 = 0xc000000d;
      goto LAB_140029e11;
    }
    uVar9 = local_68._4_4_;
    uVar8 = *(uint *)(local_a8[0] + 0x28) >> 0xc;
    if ((uVar8 <= local_68._4_4_) ||
       ((uVar8 = uVar8 - local_68._4_4_, local_68._4_4_ < 2 || (uVar8 < 2)))) goto LAB_140029e0c;
    if ((*(byte *)(local_a8[0] + 10) & 5) == 0) {
      lVar7 = MmMapLockedPagesSpecifyCache(local_a8[0],0,1,0);
    }
    else {
      lVar7 = *(longlong *)(local_a8[0] + 0x18);
    }
    param_1[0x14c] = lVar7;
    if (lVar7 == 0) {
      uVar10 = 0xc000009a;
      goto LAB_140029e11;
    }
    *(uint *)(param_1 + 0x14d) = uVar9;
    *(uint *)((longlong)param_1 + 0xa6c) = uVar8;
    if (*(char *)((longlong)param_1 + 0x6c1) == '\0') {
      lVar6 = (ulonglong)(uVar9 << 0xc) + lVar7;
      uVar4 = PkInitializeRingBuffer
                        (param_1 + 8,lVar7,lVar7 + 0x1000,uVar9 - 1,lVar6,lVar6 + 0x1000,uVar8 - 1);
      uVar10 = uVar4 & 0xffffffff;
      if (-1 < (int)uVar4) {
        PkSetInterruptMaskSkipCount((longlong)(param_1 + 8),param_1 + 0x3d);
        goto LAB_140029b66;
      }
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) goto LAB_140029e11;
      uVar5 = 0x55;
LAB_140029b33:
      WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
                &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1,(char)uVar10);
      goto LAB_140029e11;
    }
LAB_140029b66:
    ExAcquirePushLockExclusiveEx(param_1 + 0x159,0);
    *(undefined1 *)((longlong)param_1 + 0xac6) = 1;
    ExReleasePushLockExclusiveEx(param_1 + 0x159,0);
    if (*(char *)((longlong)param_1 + 0x6c1) == '\0') {
      KeQueryNodeActiveAffinity((undefined2)local_60,local_58,0);
      if (local_58[0] != 0) {
        KeSetSystemGroupAffinityThread(local_58,local_58 + 2);
      }
      uVar4 = InOpenChannel(param_1);
      uVar10 = uVar4 & 0xffffffff;
      if ((int)uVar4 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140029e11;
        uVar5 = 0x56;
        goto LAB_140029b33;
      }
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x57,
               &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1);
    }
    if ((char)param_1[0xfd] == '\0') {
      uVar9 = (*(code *)param_1[0xff])(param_1);
    }
    else {
      uVar9 = (*(code *)param_1[0x100])(param_1,param_1[0xff]);
    }
    uVar10 = (ulonglong)uVar9;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x58,
                &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1,(char)uVar9);
    }
    if ((int)uVar9 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) goto LAB_140029e11;
      uVar5 = 0x59;
      goto LAB_140029b33;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5a,
                &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1,(char)uVar9);
    }
    *(undefined4 *)(param_1 + 0x113) = 4;
    LOCK();
    plVar1 = param_1 + 0x194;
    lVar7 = *plVar1;
    *(int *)plVar1 = (int)*plVar1 + 1;
    UNLOCK();
    uVar9 = (int)lVar7 + 1;
    uVar10 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar10 == 0) {
      iVar3 = (int)((ulonglong)((longlong)(int)uVar9 * -0x2aaaaaab) >> 0x20);
      iVar3 = ((iVar3 >> 2) - (iVar3 >> 0x1f)) * 0x18;
    }
    else {
      iVar3 = (uVar9 / 0x18) * -0x18;
    }
    lVar7 = (longlong)(int)(uVar9 + iVar3);
    *(char *)((longlong)param_1 + lVar7 * 6 + 0xca4) = (char)param_1[0x113];
    *(undefined1 *)((longlong)param_1 + lVar7 * 6 + 0xca5) =
         *(undefined1 *)((longlong)param_1 + 0x89c);
    *(short *)((longlong)param_1 + lVar7 * 6 + 0xca6) = (short)param_1[0x115];
    *(undefined2 *)((longlong)param_1 + lVar7 * 6 + 0xca8) = 0xc4a;
    if (4 < DAT_140020050) {
      local_98 = param_1[0x152];
      lStack_90 = param_1[0x153];
      local_88 = param_1[0x150];
      lStack_80 = param_1[0x151];
      local_78 = param_1[0x154];
      lStack_70 = param_1[0x155];
      VmbusTraceInfoChannelStateChange
                (&local_78,&local_88,&local_98,(ulonglong)*(ushort *)(param_1 + 0x192),
                 (int)param_1[0x113],*(undefined4 *)((longlong)param_1 + 0x89c),(int)param_1[0x115],
                 0xc4a);
    }
    *(byte *)(param_1 + 0x11f) = *(byte *)(param_1 + 0x11f) | 0x10;
    uVar10 = 0;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5b,
             &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1);
  }
  (*(code *)param_1[0x127])(param_1[0x122],uVar10);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5c,
             &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1);
  }
LAB_140029e97:
  KeRevertToUserGroupAffinityThread(local_58 + 2);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5d,
              &WPP_a989f33e64883200e74810d340c3677a_Traceguids,param_1,(char)uVar10);
  }
  return uVar10;
}



===== VmbChannelInitSuppressQueueManagement @ 140029f10 =====

undefined8 VmbChannelInitSuppressQueueManagement(longlong param_1,undefined8 param_2)

{
                    /* 0x29f10  46  VmbChannelInitSuppressQueueManagement */
  if ((*(int *)(param_1 + 0x898) == 0) || (*(int *)(param_1 + 0x898) == 0xc)) {
    *(undefined1 *)(param_1 + 0x6c1) = 1;
    *(undefined8 *)(param_1 + 0x850) = param_2;
    return 0;
  }
  return 0xc00000ef;
}



===== KmclpStatsRequest @ 140029f40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int KmclpStatsRequest(int param_1,int param_2,ulonglong param_3,undefined8 *param_4)

{
  undefined8 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  undefined1 auStack_d8 [32];
  undefined8 **local_b8;
  undefined8 *local_b0;
  undefined8 *local_a8;
  undefined8 *local_a0;
  undefined8 local_98;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined8 local_88;
  undefined4 local_80;
  undefined8 *local_78;
  undefined4 local_70;
  undefined8 *local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 *local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_d8;
  iVar2 = 0;
  uVar5 = param_3;
  ExAcquireFastMutex(&KmclChannelListLock);
  puVar6 = KmclChannelList;
  do {
    if ((undefined8 **)puVar6 == &KmclChannelList) {
LAB_14002a20b:
      ExReleaseFastMutex(&KmclChannelListLock);
      return iVar2;
    }
    puVar1 = (undefined8 *)*puVar6;
    ExAcquireFastMutex(&KmclPerformanceCounterLock);
    if ((((0xfffffffd < param_2 - 1U) || (param_2 == *(int *)(puVar6 + 4))) && (puVar6[0x17] != 0))
       && (puVar6[3] != 0)) {
      if (*(ushort *)(puVar6 + 2) == 0) {
        KmclpCreateInstanceName((longlong)(puVar6 + -0x10c),(ushort *)(puVar6 + 2),uVar5,param_4);
      }
      if (param_1 == 1) {
        local_a0 = puVar6 + -0x35;
        local_b0 = puVar6 + -0x66;
        uVar5 = (ulonglong)*(uint *)(puVar6 + 4);
        local_b8 = (undefined8 **)(puVar6 + -0xd3);
        param_4 = puVar6 + -0x3c;
        puVar6[-0x62] = puVar6[-0x5f] - puVar6[-0x7a];
        local_a8 = puVar6 + -0x79;
        iVar2 = KmclPcAddChannel();
      }
      else if (param_1 == 2) {
        if (*(char *)(puVar6 + -0x2c) != '\0') {
          local_78 = puVar6 + -0x39;
          local_70 = 0x20;
          param_4 = (undefined8 *)0x1;
          local_b8 = &local_78;
          goto LAB_14002a1c8;
        }
      }
      else if (param_1 == 3) {
        local_58 = 0;
        local_40 = (undefined8 *)0x0;
        local_68 = (undefined8 *)0x0;
        uStack_60 = 0;
        local_50 = 0;
        uStack_48 = 0;
        ExAcquirePushLockSharedEx(puVar6 + 0x4d,0);
        if (*(char *)((longlong)puVar6 + 0x266) != '\0') {
          puVar4 = (undefined4 *)puVar6[0x40];
          if (*(char *)(puVar6 + -0x34) == '\0') {
            puVar3 = (undefined4 *)
                     ((ulonglong)(uint)(*(int *)((longlong)puVar6 + 0x20c) << 0xc) +
                     (longlong)puVar4);
          }
          else {
            puVar3 = puVar4;
            puVar4 = (undefined4 *)
                     ((ulonglong)(uint)(*(int *)(puVar6 + 0x41) << 0xc) + (longlong)puVar4);
          }
          local_98 = (undefined8 **)CONCAT44(*puVar3,*(int *)(puVar6 + 0x41) << 0xc);
          uStack_60 = *(undefined8 *)(puVar3 + 1);
          local_88 = (undefined8 *)CONCAT44(puVar3[0x10],puVar3[3]);
          iVar2 = *(int *)((longlong)puVar6 + 0x20c) << 0xc;
          local_68 = local_98;
          local_58 = local_88;
          local_98 = (undefined8 **)CONCAT44(*puVar4,iVar2);
          uStack_90 = puVar4[1];
          uStack_8c = puVar4[2];
          uStack_48 = *(undefined8 *)(puVar4 + 1);
          local_88 = (undefined8 *)CONCAT44(puVar4[0x10],puVar4[3]);
          local_50 = CONCAT44(*puVar4,iVar2);
          local_40 = local_88;
        }
        ExReleasePushLockSharedEx(puVar6 + 0x4d,0);
        local_98 = &local_68;
        local_88 = &local_50;
        local_b8 = (undefined8 **)&local_98;
        uStack_90 = 0x18;
        local_80 = 0x18;
        param_4 = (undefined8 *)0x2;
LAB_14002a1c8:
        uVar5 = (ulonglong)*(uint *)(puVar6 + 4);
        iVar2 = PcwAddInstance(param_3);
      }
      if (iVar2 < 0) {
        iVar2 = -0x3fffffff;
        goto LAB_14002a20b;
      }
    }
    ExReleaseFastMutex(&KmclPerformanceCounterLock);
    puVar6 = puVar1;
  } while( true );
}



===== entry @ 14002d010 =====

void entry(void)

{
  __security_init_cookie();
  DriverEntry();
  return;
}



===== __security_init_cookie @ 14002d044 =====

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



===== DllInitialize @ 14002d080 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DllInitialize(ushort *param_1)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined1 auStack_168 [32];
  undefined8 local_148 [2];
  undefined4 local_138;
  uint local_134;
  uint local_130;
  ulonglong local_18;
  
                    /* 0x2d080  1  DllInitialize */
  local_18 = __security_cookie ^ (ulonglong)auStack_168;
  wil_InitializeFeatureStaging();
  _WPP_MAIN_CB = 0;
  DAT_140020328 = &WPP_ThisDir_CTLGUID_VMBKmclDriverTraceGuid;
  DAT_140020330 = 0;
  _DAT_140020340 = 0;
  _DAT_140020348 = 1;
  WppLoadTracingSupport();
  _DAT_140020340 = 0;
  WppInitKm();
  memset(&local_134,0,0x110);
  local_138 = 0x114;
  iVar1 = RtlGetVersion(&local_138);
  if ((-1 < iVar1) && ((6 < local_134 || ((local_134 == 6 && (1 < local_130)))))) {
    ExDefaultNonPagedPoolType = 0x200;
    ExDefaultMdlProtection = 0x40000000;
  }
  _KmclChannelListLock = 1;
  _DAT_1400202c8 = 0;
  _DAT_1400202d0 = 0;
  KeInitializeEvent(&DAT_1400202d8,1,0);
  _KmclProfilerListLock = 1;
  DAT_1400202a8 = &KmclChannelList;
  KmclChannelList = &KmclChannelList;
  _DAT_140020268 = 0;
  _DAT_140020270 = 0;
  KeInitializeEvent(&DAT_140020278,1,0);
  local_148[0] = 0;
  DAT_140020318 = &KmclProfilerList;
  KmclProfilerList = &KmclProfilerList;
  _KmclPerformanceCounterLock = 1;
  _DAT_140020208 = 0;
  _DAT_140020210 = 0;
  KeInitializeEvent(&DAT_140020218,1,0);
  KeQueryPerformanceCounter(local_148);
  KmclPerformanceCounterFrequency = local_148[0];
  InitializeTelemetryAssertsKM(param_1);
  if (KmclTscTicksPerNtTick == 0) {
    uVar2 = KeQueryTimeIncrement();
    uVar3 = KmclCalibrateTsc();
    KmclTscTicksPerNtTick = uVar3 / (10000000 / (ulonglong)uVar2);
  }
  McGenEventRegister_EtwRegister();
  TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(0x140020050);
  DAT_140020308 = ExAllocatePool2(0x100,*param_1,0x636d6b56);
  if (DAT_140020308 == 0) {
    wil_UninitializeFeatureStaging();
    uVar4 = 0xc000009a;
  }
  else {
    _DAT_140020302 = *param_1;
    RtlCopyUnicodeString(&KmclRegistryPath,param_1);
    uVar4 = 0;
  }
  return uVar4;
}



===== DriverEntry @ 14002d2d8 =====

undefined8 DriverEntry(void)

{
  return 0xc0000001;
}



===== wil_InitializeFeatureStaging @ 14002d2e8 =====

int wil_InitializeFeatureStaging(void)

{
  bool bVar1;
  int iVar2;
  longlong *plVar3;
  undefined **ppuVar4;
  undefined8 local_res8;
  
  bVar1 = false;
  if (g_wil_details_isFeatureStagingInitialized == 0) {
    g_wil_details_isFeatureStagingInitialized = 1;
    local_res8 = RtlQueryFeatureConfigurationChangeStamp();
    wil_details_PopulateInitialConfiguredFeatureStates();
    wil_details_EvaluateFeatureDependencies();
    ppuVar4 = &wil_details_featureDescriptors_a;
    while (plVar3 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar4),
          plVar3 != (longlong *)0x0) {
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
      ppuVar4 = (undefined **)(plVar3 + 7);
    }
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
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14002d3d8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_PopulateInitialConfiguredFeatureStates(void)

{
  int iVar1;
  longlong *plVar2;
  undefined **ppuVar3;
  undefined8 uVar4;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  ppuVar3 = &wil_details_featureDescriptors_a;
  do {
    plVar2 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar3);
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
    ppuVar3 = (undefined **)(plVar2 + 7);
    *(undefined8 *)*plVar2 = local_38;
  } while( true );
}


