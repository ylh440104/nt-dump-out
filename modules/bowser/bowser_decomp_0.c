
===== _tlgCreate1Sz_wchar_t @ 140001008 =====

void _tlgCreate1Sz_wchar_t(longlong *param_1,wchar_t *param_2)

{
  int iVar1;
  longlong lVar2;
  
  if (param_2 == (wchar_t *)0x0) {
    param_2 = L"";
    iVar1 = 2;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_2[lVar2] != L'\0');
    iVar1 = (int)lVar2 * 2 + 2;
  }
  *param_1 = (longlong)param_2;
  *(int *)(param_1 + 1) = iVar1;
  *(undefined4 *)((longlong)param_1 + 0xc) = 0;
  return;
}



===== _tlgWriteTransfer_EtwWriteTransfer @ 140001048 =====

void _tlgWriteTransfer_EtwWriteTransfer
               (undefined8 param_1,byte *param_2,undefined8 param_3,undefined8 param_4,
               undefined4 param_5,undefined8 *param_6)

{
  int local_18;
  uint local_14;
  undefined8 local_10;
  
  local_18 = (uint)*param_2 << 0x18;
  local_14 = (uint)*(ushort *)(param_2 + 1);
  local_10 = *(undefined8 *)(param_2 + 3);
  *param_6 = PTR_DAT_14000d0f8;
  *(uint *)(param_6 + 1) = (uint)*(ushort *)PTR_DAT_14000d0f8;
  param_6[2] = param_2 + 0xb;
  *(undefined4 *)((longlong)param_6 + 0xc) = 2;
  *(uint *)(param_6 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)param_6 + 0x1c) = 1;
  EtwWriteTransfer(DAT_14000d110,&local_18,0,0,param_5,param_6);
  return;
}



===== BowserHandleMailslotTransaction @ 140001100 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
BowserHandleMailslotTransaction
          (longlong param_1,longlong *param_2,undefined4 param_3,uint param_4,uint param_5,
          uint param_6,uint param_7,uint *param_8,longlong param_9,longlong *param_10)

{
  char *pcVar1;
  undefined1 *puVar2;
  longlong *plVar3;
  undefined8 uVar4;
  longlong *plVar5;
  undefined1 *_Dst;
  longlong lVar6;
  uint uVar7;
  longlong lVar8;
  undefined8 uVar9;
  
  lVar6 = *(longlong *)(param_1 + 0x18);
  if (param_4 <= param_7) {
    uVar7 = param_7 - param_4;
    if (((byte)(*(char *)(param_1 + 4) - 1U) < 2) || ((byte)(*(char *)(param_1 + 4) - 9U) < 3)) {
      plVar3 = BowserAllocateMailslotBuffer(param_1,uVar7);
      if (plVar3 != (longlong *)0x0) {
        plVar5 = plVar3 + 9;
        plVar3[6] = _DAT_fffff78000000014;
        *(undefined4 *)(plVar3 + 7) = param_3;
        if ((param_5 & 0x200) == 0) {
          if (plVar5 < plVar3 + 0xb) {
            lVar8 = (longlong)param_2 - (longlong)plVar5;
            do {
              *(undefined1 *)plVar5 = *(undefined1 *)(lVar8 + (longlong)plVar5);
              plVar5 = (longlong *)((longlong)plVar5 + 1);
            } while (plVar5 < plVar3 + 0xb);
          }
        }
        else {
          lVar8 = param_2[1];
          *plVar5 = *param_2;
          plVar3[10] = lVar8;
        }
        if (param_7 == param_6) {
          *(uint *)(plVar3 + 0xb) = uVar7;
          _Dst = (undefined1 *)((longlong)plVar3 + 0x5c);
          if ((param_5 & 0x200) == 0) {
            puVar2 = _Dst + uVar7;
            if (_Dst < puVar2) {
              lVar6 = (longlong)((ulonglong)param_4 + param_9) - (longlong)_Dst;
              do {
                *_Dst = _Dst[lVar6];
                _Dst = _Dst + 1;
              } while (_Dst < puVar2);
            }
          }
          else {
            memcpy(_Dst,(void *)((ulonglong)param_4 + param_9),(ulonglong)uVar7);
          }
          plVar3[4] = (longlong)plVar3;
          plVar3[3] = (longlong)BowserProcessMailslotWrite;
          plVar3[1] = 0;
          BowserQueueDelayedWorkItem(plVar3 + 1);
          return 0;
        }
        lVar8 = *(longlong *)(param_1 + 0x28);
        if (lVar8 == 0) {
          lVar8 = *(longlong *)(lVar6 + 0x50);
          uVar9 = *(undefined8 *)(lVar6 + 0x48);
        }
        else {
          uVar9 = *(undefined8 *)(param_1 + 0x20);
        }
        lVar6 = IoAllocateIrp(*(undefined1 *)(lVar8 + 0x4c),0);
        *param_10 = lVar6;
        if (lVar6 != 0) {
          uVar4 = IoAllocateMdl((longlong)plVar3 + 0x5c,uVar7,0,0,0);
          *(undefined8 *)(*param_10 + 8) = uVar4;
          if (*(longlong *)(*param_10 + 8) != 0) {
            MmBuildMdlForNonPagedPool(*(longlong *)(*param_10 + 8));
            lVar6 = *(longlong *)(*param_10 + 0xb8);
            *(code **)(lVar6 + -0x10) = CompleteReceiveMailslot;
            *(longlong **)(lVar6 + -8) = plVar3;
            *(undefined1 *)(lVar6 + -0x45) = 0xe0;
            lVar6 = *(longlong *)(*param_10 + 0xb8);
            *(undefined2 *)(lVar6 + -0x48) = 0xa0f;
            *(longlong *)(lVar6 + -0x20) = lVar8;
            *(undefined8 *)(lVar6 + -0x18) = uVar9;
            *(uint *)(lVar6 + -0x40) = uVar7;
            *(undefined8 *)(lVar6 + -0x38) = 0;
            *(undefined8 *)(lVar6 + -0x30) = 0;
            *(undefined4 *)(lVar6 + -0x28) = 0;
            lVar6 = *param_10;
            pcVar1 = (char *)(lVar6 + 0x43);
            *pcVar1 = *pcVar1 + -1;
            plVar3 = (longlong *)(lVar6 + 0xb8);
            *plVar3 = *plVar3 + -0x48;
            *param_8 = param_4;
            return 0xc0000016;
          }
          IoFreeIrp();
        }
        BowserFreeMailslotBufferHighIrql((longlong)plVar3);
        _DAT_14000d2e8 = _DAT_14000d2e8 + 1;
      }
      return 0xc00000d0;
    }
  }
  return 0;
}



===== BowserAllocateMailslotBuffer @ 140001360 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * BowserAllocateMailslotBuffer(longlong param_1,uint param_2)

{
  int *piVar1;
  longlong lVar2;
  code *pcVar3;
  bool bVar4;
  undefined1 uVar5;
  uint uVar6;
  longlong *plVar7;
  int iVar8;
  undefined1 *puVar9;
  uint uVar10;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  bVar4 = false;
  uVar5 = KeAcquireSpinLockRaiseToDpc(&BowserMailslotSpinLock);
  plVar7 = BowserMailslotBufferList;
  uVar10 = 0x200;
  puVar9 = auStack_38;
  if ((param_2 < 0x201) &&
     (puVar9 = auStack_38, (longlong **)BowserMailslotBufferList != &BowserMailslotBufferList)) {
    lVar2 = *BowserMailslotBufferList;
    if (((longlong **)BowserMailslotBufferList[1] == &BowserMailslotBufferList) &&
       (*(longlong **)(lVar2 + 8) == BowserMailslotBufferList)) {
      BowserNumberOfFreeMailslotBuffers = BowserNumberOfFreeMailslotBuffers + -1;
      BowserMailslotBufferList = (longlong *)lVar2;
      *(longlong ***)(lVar2 + 8) = &BowserMailslotBufferList;
      KeReleaseSpinLock(&BowserMailslotSpinLock,CONCAT71((int7)((ulonglong)lVar2 >> 8),uVar5));
      plVar7[7] = param_1;
      LOCK();
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      UNLOCK();
      LOCK();
      piVar1 = (int *)(*(longlong *)(param_1 + 0x18) + 4);
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      return plVar7 + -1;
    }
    pcVar3 = (code *)swi(0x29);
    uVar10 = 0x200;
    (*pcVar3)(3);
    puVar9 = auStack_30;
  }
  uVar6 = DAT_14000d848 + 0x32U;
  if (DAT_14000d848 + 0x32U < DAT_14000d294) {
    uVar6 = DAT_14000d294;
  }
  if (BowserNumberOfMailslotBuffers < uVar6) {
    if ((BowserNumberOfMaxSizeMailslotBuffers < (int)DAT_14000d294) && (param_2 <= uVar10)) {
      BowserNumberOfMaxSizeMailslotBuffers = BowserNumberOfMaxSizeMailslotBuffers + 1;
      iVar8 = 0x25c;
      bVar4 = true;
    }
    else {
      iVar8 = param_2 + 0x5c;
    }
    BowserNumberOfMailslotBuffers = BowserNumberOfMailslotBuffers + 1;
    *(undefined8 *)(puVar9 + -8) = 0x1400014a8;
    KeReleaseSpinLock(&BowserMailslotSpinLock,
                      CONCAT31((int3)(BowserNumberOfMailslotBuffers >> 8),uVar5));
    *(undefined8 *)(puVar9 + -8) = 0x1400014c1;
    plVar7 = (longlong *)ExAllocatePool2(0x42,iVar8,0x626d424c);
    if (plVar7 != (longlong *)0x0) {
      *(undefined4 *)plVar7 = 0x5c0007;
      *(int *)(plVar7 + 5) = iVar8 + -0x5c;
      plVar7[8] = param_1;
      LOCK();
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      UNLOCK();
      LOCK();
      piVar1 = (int *)(*(longlong *)(param_1 + 0x18) + 4);
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      return plVar7;
    }
    *(undefined8 *)(puVar9 + -8) = 0x1400014d8;
    uVar5 = KeAcquireSpinLockRaiseToDpc(&BowserMailslotSpinLock);
    BowserNumberOfMailslotBuffers = BowserNumberOfMailslotBuffers - 1;
    if (bVar4) {
      BowserNumberOfMaxSizeMailslotBuffers = BowserNumberOfMaxSizeMailslotBuffers + -1;
    }
    *(undefined8 *)(puVar9 + -8) = 0x1400014fa;
    KeReleaseSpinLock(&BowserMailslotSpinLock,uVar5);
    _DAT_14000d2e4 = _DAT_14000d2e4 + 1;
    BowserNumberOfMissedMailslotDatagrams = BowserNumberOfMissedMailslotDatagrams + 1;
    _DAT_14000d2d8 = _DAT_14000d2d8 + 1;
    if (BowserMailslotDatagramThreshold < BowserNumberOfMissedMailslotDatagrams) {
      *(undefined8 *)(puVar9 + -8) = 0x140001530;
      BowserWriteMailslotDatagramThresholdExceededEvent();
      BowserNumberOfMissedMailslotDatagrams = 0;
    }
  }
  else {
    _DAT_14000d2d8 = _DAT_14000d2d8 + 1;
    BowserNumberOfMissedMailslotDatagrams = BowserNumberOfMissedMailslotDatagrams + 1;
    if (BowserMailslotDatagramThreshold < BowserNumberOfMissedMailslotDatagrams) {
      *(undefined8 *)(puVar9 + -8) = 0x14000144e;
      BowserWriteMailslotDatagramThresholdExceededEvent();
      BowserNumberOfMissedMailslotDatagrams = 0;
    }
    *(undefined8 *)(puVar9 + -8) = 0x140001463;
    KeReleaseSpinLock(&BowserMailslotSpinLock,uVar5);
  }
  return (longlong *)0x0;
}



===== BowserGetBackupListRequest @ 140001580 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong BowserGetBackupListRequest
                    (longlong param_1,void *param_2,uint param_3,uint *param_4,void *param_5,
                    uint param_6,void *param_7,uint param_8,uint param_9)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined8 in_stack_ffffffffffffffd0;
  
  if (param_3 < 5) {
    uVar1 = 0xc00000d0;
  }
  else {
    _DAT_14000d2d0 = _DAT_14000d2d0 + 1;
    uVar2 = BowserPostDatagramToWorkerThread
                      (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
                       BowserGetBackupListWorker,in_stack_ffffffffffffffd0,1,param_9);
    uVar1 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) {
      _DAT_14000d2dc = _DAT_14000d2dc + 1;
      BowserNumberOfMissedGetBrowserServerListRequests =
           BowserNumberOfMissedGetBrowserServerListRequests + 1;
      if (BowserGetBrowserListThreshold < BowserNumberOfMissedGetBrowserServerListRequests) {
        BowserWriteGetBrowserListThresholdExceededEvent();
        BowserNumberOfMissedGetBrowserServerListRequests = 0;
      }
    }
  }
  return uVar1;
}



===== BowserHandleBecomeBackup @ 140001640 =====

void BowserHandleBecomeBackup
               (longlong param_1,void *param_2,uint param_3,uint *param_4,void *param_5,uint param_6
               ,void *param_7,uint param_8,uint param_9)

{
  undefined8 in_stack_ffffffffffffffd0;
  
  BowserPostDatagramToWorkerThread
            (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
             BowserBecomeBackupWorker,in_stack_ffffffffffffffd0,1,param_9);
  return;
}



===== BowserHandleElection @ 1400016b0 =====

undefined8
BowserHandleElection
          (longlong param_1,void *param_2,uint param_3,uint *param_4,void *param_5,uint param_6,
          void *param_7,uint param_8,uint param_9)

{
  int *piVar1;
  undefined1 *puVar2;
  undefined8 *puVar3;
  uint uVar4;
  undefined8 *puVar5;
  undefined1 *puVar6;
  undefined8 *puVar7;
  longlong lVar8;
  
  if (((param_3 <= param_3 + 0x50) && (uVar4 = param_3 + 0x50 + param_6, param_6 <= uVar4)) &&
     (puVar5 = (undefined8 *)ExAllocatePool2(0x42,uVar4,0x6470424c), puVar5 != (undefined8 *)0x0)) {
    puVar5[4] = param_1;
    puVar6 = (undefined1 *)((ulonglong)param_6 + 0x50 + (longlong)puVar5);
    puVar5[5] = puVar6;
    *(uint *)(puVar5 + 6) = param_3;
    if ((param_9 & 0x200) == 0) {
      puVar2 = puVar6 + param_3;
      if (puVar6 < puVar2) {
        lVar8 = (longlong)param_2 - (longlong)puVar6;
        do {
          *puVar6 = puVar6[lVar8];
          puVar6 = puVar6 + 1;
        } while (puVar6 < puVar2);
      }
      puVar6 = (undefined1 *)((longlong)puVar5 + 0x4c);
      *(uint *)(puVar5 + 9) = param_6;
      puVar2 = puVar6 + param_6;
      if (puVar6 < puVar2) {
        lVar8 = (longlong)param_5 - (longlong)puVar6;
        do {
          *puVar6 = puVar6[lVar8];
          puVar6 = puVar6 + 1;
        } while (puVar6 < puVar2);
      }
      puVar7 = puVar5 + 7;
      *(undefined4 *)((longlong)puVar5 + 0x34) = 0x10;
      puVar3 = (undefined8 *)((ulonglong)param_8 + (longlong)puVar7);
      if (puVar7 < puVar3) {
        lVar8 = (longlong)param_7 - (longlong)puVar7;
        do {
          *(undefined1 *)puVar7 = *(undefined1 *)(lVar8 + (longlong)puVar7);
          puVar7 = (undefined8 *)((longlong)puVar7 + 1);
        } while (puVar7 < puVar3);
      }
    }
    else {
      memcpy(puVar6,param_2,(ulonglong)param_3);
      *(uint *)(puVar5 + 9) = param_6;
      memcpy((void *)((longlong)puVar5 + 0x4c),param_5,(ulonglong)param_6);
      *(undefined4 *)((longlong)puVar5 + 0x34) = 0x10;
      memcpy(puVar5 + 7,param_7,(ulonglong)param_8);
    }
    if (1 < param_8) {
      for (uVar4 = param_8 - 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        if ((*(byte *)((longlong)puVar5 + (ulonglong)uVar4 + 0x38) & 0xdf) != 0) {
          *(undefined1 *)((longlong)puVar5 + (ulonglong)(uVar4 + 1) + 0x38) = 0;
          break;
        }
      }
    }
    *param_4 = param_3;
    puVar5[2] = HandleElectionWorker;
    puVar5[3] = puVar5;
    *puVar5 = 0;
    LOCK();
    UNLOCK();
    if (BowserPostedCriticalDatagramCount + 1U < 0x65) {
      LOCK();
      BowserPostedCriticalDatagramCount = BowserPostedCriticalDatagramCount + 1;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      UNLOCK();
      LOCK();
      piVar1 = (int *)(*(longlong *)(param_1 + 0x18) + 4);
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      BowserQueueCriticalWorkItem(puVar5);
      return 0;
    }
    LOCK();
    UNLOCK();
    ExFreePoolWithTag(puVar5,0);
  }
  return 0xc00000d0;
}



===== BowserPostDatagramToWorkerThread @ 1400018e0 =====

undefined8
BowserPostDatagramToWorkerThread
          (longlong param_1,void *param_2,uint param_3,uint *param_4,void *param_5,uint param_6,
          void *param_7,uint param_8,undefined8 param_9,undefined8 param_10,int param_11,
          uint param_12)

{
  int *piVar1;
  undefined8 *puVar2;
  uint uVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined8 *puVar8;
  longlong lVar9;
  
  if (((param_3 + 0x50 < param_3) || (uVar3 = param_3 + 0x50 + param_6, uVar3 < param_6)) ||
     (puVar4 = (undefined8 *)ExAllocatePool2(0x42,uVar3,0x6470424c), puVar4 == (undefined8 *)0x0)) {
LAB_140001b36:
    uVar5 = 0xc00000d0;
  }
  else {
    puVar6 = (undefined1 *)((ulonglong)param_6 + 0x50 + (longlong)puVar4);
    puVar4[4] = param_1;
    puVar4[5] = puVar6;
    *(uint *)(puVar4 + 6) = param_3;
    if ((param_12 & 0x200) == 0) {
      puVar7 = puVar6 + param_3;
      if (puVar6 < puVar7) {
        lVar9 = (longlong)param_2 - (longlong)puVar6;
        do {
          *puVar6 = puVar6[lVar9];
          puVar6 = puVar6 + 1;
        } while (puVar6 < puVar7);
      }
      puVar7 = (undefined1 *)((longlong)puVar4 + 0x4c);
      puVar6 = puVar7 + param_6;
      *(uint *)(puVar4 + 9) = param_6;
      if (puVar7 < puVar6) {
        lVar9 = (longlong)param_5 - (longlong)puVar7;
        do {
          *puVar7 = puVar7[lVar9];
          puVar7 = puVar7 + 1;
        } while (puVar7 < puVar6);
      }
      puVar8 = puVar4 + 7;
      *(undefined4 *)((longlong)puVar4 + 0x34) = 0x10;
      puVar2 = (undefined8 *)((ulonglong)param_8 + (longlong)puVar8);
      if (puVar8 < puVar2) {
        lVar9 = (longlong)param_7 - (longlong)puVar8;
        do {
          *(undefined1 *)puVar8 = *(undefined1 *)(lVar9 + (longlong)puVar8);
          puVar8 = (undefined8 *)((longlong)puVar8 + 1);
        } while (puVar8 < puVar2);
      }
    }
    else {
      memcpy(puVar6,param_2,(ulonglong)param_3);
      *(uint *)(puVar4 + 9) = param_6;
      memcpy((void *)((longlong)puVar4 + 0x4c),param_5,(ulonglong)param_6);
      *(undefined4 *)((longlong)puVar4 + 0x34) = 0x10;
      memcpy(puVar4 + 7,param_7,(ulonglong)param_8);
    }
    if (1 < param_8) {
      for (uVar3 = param_8 - 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        if ((*(byte *)((longlong)puVar4 + (ulonglong)uVar3 + 0x38) & 0xdf) != 0) {
          *(undefined1 *)((longlong)puVar4 + (ulonglong)(uVar3 + 1) + 0x38) = 0;
          break;
        }
      }
    }
    *param_4 = param_3;
    puVar4[2] = param_9;
    puVar4[3] = puVar4;
    *puVar4 = 0;
    if (param_11 == 0) {
      LOCK();
      UNLOCK();
      if (100 < BowserPostedCriticalDatagramCount + 1U) {
        LOCK();
        UNLOCK();
LAB_140001b28:
        ExFreePoolWithTag(puVar4,0);
        goto LAB_140001b36;
      }
      LOCK();
      BowserPostedCriticalDatagramCount = BowserPostedCriticalDatagramCount + 1;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      UNLOCK();
      LOCK();
      piVar1 = (int *)(*(longlong *)(param_1 + 0x18) + 4);
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      BowserQueueCriticalWorkItem(puVar4);
    }
    else {
      LOCK();
      UNLOCK();
      if (100 < BowserPostedDatagramCount + 1U) {
        LOCK();
        UNLOCK();
        goto LAB_140001b28;
      }
      LOCK();
      BowserPostedDatagramCount = BowserPostedDatagramCount + 1;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      UNLOCK();
      LOCK();
      piVar1 = (int *)(*(longlong *)(param_1 + 0x18) + 4);
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      BowserQueueDelayedWorkItem(puVar4);
    }
    uVar5 = 0;
  }
  return uVar5;
}



===== BowserQueueCriticalWorkItem @ 140001b48 =====

void BowserQueueCriticalWorkItem(undefined8 *param_1)

{
  code *pcVar1;
  undefined1 uVar2;
  bool bVar3;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(&BowserIrpQueueSpinLock);
  if ((undefined8 *)*DAT_14000d7d8 != &BowserCriticalThreadQueue) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(3);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  bVar3 = BowserCriticalThreadRunning == '\0';
  *param_1 = &BowserCriticalThreadQueue;
  param_1[1] = DAT_14000d7d8;
  *DAT_14000d7d8 = param_1;
  DAT_14000d7d8 = param_1;
  if (bVar3) {
    BowserCriticalThreadRunning = '\x01';
    KeReleaseSpinLock();
    IoQueueWorkItemEx(BowserCriticalThreadWorkItem,BowserCriticalThreadWorker,0,0);
  }
  else {
    KeReleaseSpinLock(&BowserIrpQueueSpinLock,CONCAT71(0x14000d7,uVar2));
  }
  return;
}



===== BowserHandleDomainAnnouncement @ 140001bf0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int BowserHandleDomainAnnouncement(longlong param_1,longlong param_2,uint param_3,uint *param_4)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  longlong *plVar5;
  char *pcVar6;
  undefined8 uVar7;
  char *pcVar8;
  longlong lVar9;
  uint uVar10;
  uint uVar11;
  longlong lVar12;
  ulonglong uVar13;
  bool bVar14;
  
  if (*(char *)(param_1 + 5) != '\0') {
    LOCK();
    _DAT_14000d2c0 = _DAT_14000d2c0 + 1;
    UNLOCK();
    if (0x1e < param_3) {
      uVar10 = param_3 - 5;
      pcVar8 = (char *)(param_2 + 5);
      uVar11 = 0;
      uVar3 = uVar10;
      if (uVar10 != 0) {
        do {
          cVar2 = *pcVar8;
          pcVar8 = pcVar8 + 1;
          uVar3 = uVar3 - 1;
          if (cVar2 == '\0') break;
          uVar11 = uVar11 + 1;
        } while (uVar3 != 0);
        if (0x10 < uVar11) {
          return -0x3fffff30;
        }
      }
      plVar5 = BowserAllocateViewBuffer();
      if (plVar5 != (longlong *)0x0) {
        pcVar8 = (char *)((longlong)plVar5 + 0x31);
        uVar13 = 0x10;
        if (uVar10 < 0x10) {
          uVar13 = (ulonglong)uVar10;
        }
        if (0x7ffffffe < uVar13) {
          *pcVar8 = '\0';
          BowserFreeViewBuffer((longlong)plVar5);
          return -0x3ffffff3;
        }
        lVar9 = 0x11;
        lVar12 = param_2 - (longlong)pcVar8;
        do {
          if (((uVar13 - 0x11) + lVar9 == 0) || (pcVar8[lVar12 + 5] == '\0')) break;
          *pcVar8 = pcVar8[lVar12 + 5];
          pcVar8 = pcVar8 + 1;
          lVar9 = lVar9 + -1;
        } while (lVar9 != 0);
        bVar14 = lVar9 != 0;
        pcVar6 = pcVar8 + -1;
        if (bVar14) {
          pcVar6 = pcVar8;
        }
        iVar4 = -0x7ffffffb;
        if (bVar14) {
          iVar4 = 0;
        }
        *pcVar6 = '\0';
        if (bVar14) {
          *(undefined1 *)(plVar5 + 8) = 0;
          uVar13 = 0xf;
          if (param_3 - 0x1f < 0xf) {
            uVar13 = (ulonglong)(param_3 - 0x1f);
          }
          uVar7 = RtlStringCbCopyNA((char *)((longlong)plVar5 + 0x4c),0x31,param_2 + 0x1f,uVar13);
          iVar4 = (int)uVar7;
          if (-1 < iVar4) {
            *(undefined1 *)((longlong)plVar5 + 0x5b) = 0;
            plVar5[5] = param_1;
            iVar4 = -0x80000000;
            if (*(int *)(param_2 + 0x17) < 0) {
              iVar4 = *(int *)(param_2 + 0x17);
            }
            *(int *)(plVar5 + 9) = iVar4;
            *(undefined1 *)((longlong)plVar5 + 0x44) = *(undefined1 *)(param_2 + 0x15);
            *(undefined1 *)((longlong)plVar5 + 0x45) = *(undefined1 *)(param_2 + 0x16);
            *(short *)((longlong)plVar5 + 0x46) =
                 (short)((ulonglong)(*(int *)(param_2 + 1) + 999) / 1000);
            LOCK();
            *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
            UNLOCK();
            LOCK();
            piVar1 = (int *)(*(longlong *)(param_1 + 0x18) + 4);
            *piVar1 = *piVar1 + 1;
            UNLOCK();
            plVar5[4] = (longlong)plVar5;
            plVar5[3] = (longlong)BowserProcessDomainAnnouncement;
            plVar5[1] = 0;
            BowserQueueDelayedWorkItem(plVar5 + 1);
            *param_4 = param_3;
            return 0;
          }
        }
        BowserFreeViewBuffer((longlong)plVar5);
        return iVar4;
      }
    }
  }
  return -0x3fffff30;
}



===== HandleLocalMasterAnnouncement @ 140001dd0 =====

undefined4
HandleLocalMasterAnnouncement
          (longlong param_1,longlong param_2,uint param_3,uint *param_4,void *param_5,uint param_6,
          undefined8 param_7,undefined8 param_8,uint param_9)

{
  int *piVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 *puVar5;
  undefined1 *_Dst;
  longlong lVar6;
  
  if (0x1e < param_3) {
    LOCK();
    iVar3 = BowserPostedDatagramCount + 1;
    UNLOCK();
    if (BowserPostedDatagramCount + 1U < 0x65) {
      BowserPostedDatagramCount = iVar3;
      if (param_6 <= param_6 + 0x48) {
        puVar5 = (undefined8 *)ExAllocatePool2(0x42,param_6 + 0x48,0x616d424c);
        if (puVar5 == (undefined8 *)0x0) {
          LOCK();
          BowserPostedDatagramCount = BowserPostedDatagramCount + -1;
          UNLOCK();
          return 0;
        }
        puVar5[3] = puVar5;
        puVar5[2] = BowserProcessMasterAnnouncement;
        *puVar5 = 0;
        LOCK();
        piVar1 = (int *)(*(longlong *)(param_1 + 0x18) + 4);
        *piVar1 = *piVar1 + 1;
        UNLOCK();
        puVar5[4] = *(undefined8 *)(param_1 + 0x18);
        *(undefined4 *)(puVar5 + 5) = *(undefined4 *)(param_2 + 0x17);
        *(undefined4 *)((longlong)puVar5 + 0x2c) = *(undefined4 *)(param_2 + 0x1b);
        puVar5[6] = *(undefined8 *)(param_2 + 5);
        *(undefined4 *)(puVar5 + 7) = *(undefined4 *)(param_2 + 0xd);
        *(undefined2 *)((longlong)puVar5 + 0x3c) = *(undefined2 *)(param_2 + 0x11);
        *(undefined1 *)((longlong)puVar5 + 0x3e) = *(undefined1 *)(param_2 + 0x13);
        _Dst = (undefined1 *)((longlong)puVar5 + 0x44);
        *(undefined1 *)((longlong)puVar5 + 0x3f) = 0;
        *(uint *)(puVar5 + 8) = param_6;
        if ((param_9 >> 9 & 1) == 0) {
          puVar2 = _Dst + param_6;
          if (_Dst < puVar2) {
            lVar6 = (longlong)param_5 - (longlong)_Dst;
            do {
              *_Dst = _Dst[lVar6];
              _Dst = _Dst + 1;
            } while (_Dst < puVar2);
          }
        }
        else {
          memcpy(_Dst,param_5,(ulonglong)param_6);
        }
        BowserQueueDelayedWorkItem(puVar5);
        if (*(char *)(param_1 + 5) != '\0') {
          uVar4 = BowserHandleServerAnnouncement(param_1,param_2,param_3,param_4);
          return uVar4;
        }
      }
    }
    else {
      LOCK();
      UNLOCK();
    }
  }
  return 0xc00000d0;
}



===== BowserHandleServerAnnouncement @ 140001f90 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
BowserHandleServerAnnouncement(longlong param_1,longlong param_2,uint param_3,uint *param_4)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  longlong *plVar5;
  char *pcVar6;
  char *pcVar7;
  undefined2 uVar8;
  longlong lVar9;
  undefined4 uVar10;
  uint uVar11;
  longlong lVar12;
  uint uVar13;
  ulonglong uVar14;
  size_t _Size;
  bool bVar15;
  
  uVar11 = 0;
  LOCK();
  _DAT_14000d2b8 = _DAT_14000d2b8 + 1;
  UNLOCK();
  plVar5 = BowserAllocateViewBuffer();
  if (plVar5 == (longlong *)0x0) {
    return 0xc00000d0;
  }
  if (1 < (byte)(*(char *)(param_1 + 4) - 6U)) {
    if (8 < param_3) {
      uVar13 = param_3 - 9;
      uVar4 = BowserSafeStrlen(param_2 + 9,uVar13);
      _Size = (size_t)uVar4;
      if (uVar4 - 1 < 0x10) {
        if (uVar4 < uVar13) {
          lVar9 = -1;
          do {
            lVar9 = lVar9 + 1;
          } while (*(char *)(param_2 + 9 + lVar9) != '\0');
          uVar11 = BowserSafeStrlen(param_2 + 10 + lVar9,(uVar13 - uVar4) + -1);
          if (0x30 < uVar11) goto LAB_1400021e7;
        }
        memcpy((void *)((longlong)plVar5 + 0x31),(void *)(param_2 + 9),_Size);
        *(undefined1 *)(_Size + 0x31 + (longlong)plVar5) = 0;
        if (uVar11 != 0) {
          memcpy((void *)((longlong)plVar5 + 0x4c),(void *)(param_2 + 10 + _Size),(ulonglong)uVar11)
          ;
        }
        *(undefined1 *)((ulonglong)uVar11 + 0x4c + (longlong)plVar5) = 0;
        *(undefined2 *)((longlong)plVar5 + 0x42) = 0x10f;
        *(undefined4 *)(plVar5 + 9) = *(undefined4 *)(param_2 + 1);
        *(undefined1 *)((longlong)plVar5 + 0x44) = *(undefined1 *)(param_2 + 5);
        *(undefined1 *)((longlong)plVar5 + 0x45) = *(undefined1 *)(param_2 + 6);
        uVar8 = *(undefined2 *)(param_2 + 7);
LAB_14000217a:
        *(undefined2 *)((longlong)plVar5 + 0x46) = uVar8;
        plVar5[5] = param_1;
        LOCK();
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
        UNLOCK();
        LOCK();
        piVar1 = (int *)(*(longlong *)(param_1 + 0x18) + 4);
        *piVar1 = *piVar1 + 1;
        UNLOCK();
        plVar5[4] = (longlong)plVar5;
        plVar5[3] = (longlong)BowserProcessHostAnnouncement;
        plVar5[1] = 0;
        BowserQueueDelayedWorkItem(plVar5 + 1);
        *param_4 = param_3;
        return 0;
      }
    }
LAB_1400021e7:
    BowserFreeViewBuffer((longlong)plVar5);
    return 0xc00000d0;
  }
  if (param_3 < 0x1f) goto LAB_1400021e7;
  iVar3 = param_3 - 5;
  uVar11 = 0;
  pcVar7 = (char *)(param_2 + 5);
  if (iVar3 != 0) {
    do {
      cVar2 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      iVar3 = iVar3 + -1;
      if (cVar2 == '\0') break;
      uVar11 = uVar11 + 1;
    } while (iVar3 != 0);
    if (0xf < uVar11) goto LAB_1400021e7;
  }
  iVar3 = param_3 - 0x1f;
  uVar11 = 0;
  pcVar7 = (char *)(param_2 + 0x1f);
  if (iVar3 != 0) {
    do {
      cVar2 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      iVar3 = iVar3 + -1;
      if (cVar2 == '\0') break;
      uVar11 = uVar11 + 1;
    } while (iVar3 != 0);
    if (0x30 < uVar11) goto LAB_1400021e7;
  }
  pcVar7 = (char *)((longlong)plVar5 + 0x31);
  uVar14 = 0x10;
  if (param_3 - 5 < 0x10) {
    uVar14 = (ulonglong)(param_3 - 5);
  }
  if (uVar14 < 0x7fffffff) {
    lVar9 = 0x11;
    lVar12 = param_2 - (longlong)pcVar7;
    do {
      if ((lVar9 + -0x11 + uVar14 == 0) || (pcVar7[lVar12 + 5] == '\0')) break;
      *pcVar7 = pcVar7[lVar12 + 5];
      pcVar7 = pcVar7 + 1;
      lVar9 = lVar9 + -1;
    } while (lVar9 != 0);
    pcVar6 = pcVar7 + -1;
    if (lVar9 != 0) {
      pcVar6 = pcVar7;
    }
    *pcVar6 = '\0';
    uVar10 = 0x80000005;
    if (lVar9 == 0) goto LAB_1400021ba;
    *(undefined1 *)((longlong)plVar5 + 0x41) = 0;
    uVar11 = param_3 - 0x1f;
    if (0x2f < param_3 - 0x1f) {
      uVar11 = 0x30;
    }
    pcVar7 = (char *)((longlong)plVar5 + 0x4c);
    if ((ulonglong)uVar11 < 0x7fffffff) {
      lVar9 = 0x31;
      lVar12 = param_2 - (longlong)pcVar7;
      do {
        if ((lVar9 + -0x31 + (ulonglong)uVar11 == 0) || (pcVar7[lVar12 + 0x1f] == '\0')) break;
        *pcVar7 = pcVar7[lVar12 + 0x1f];
        pcVar7 = pcVar7 + 1;
        lVar9 = lVar9 + -1;
      } while (lVar9 != 0);
      bVar15 = lVar9 != 0;
      pcVar6 = pcVar7 + -1;
      if (bVar15) {
        pcVar6 = pcVar7;
      }
      uVar10 = 0x80000005;
      if (bVar15) {
        uVar10 = 0;
      }
      *pcVar6 = '\0';
      if (bVar15) {
        *(undefined1 *)((longlong)plVar5 + 0x7c) = 0;
        uVar11 = *(uint *)(param_2 + 0x1b);
        if ((uVar11 & 0xffff0000) != 0xaa550000) {
          if ((*(uint *)(param_2 + 0x17) & 0x1000) == 0) {
            uVar11 = 0x10f;
          }
          else {
            uVar11 = 0;
          }
        }
        *(short *)((longlong)plVar5 + 0x42) = (short)uVar11;
        *(undefined4 *)(plVar5 + 9) = *(undefined4 *)(param_2 + 0x17);
        *(undefined1 *)((longlong)plVar5 + 0x44) = *(undefined1 *)(param_2 + 0x15);
        *(undefined1 *)((longlong)plVar5 + 0x45) = *(undefined1 *)(param_2 + 0x16);
        uVar8 = (undefined2)((ulonglong)(*(int *)(param_2 + 1) + 999) / 1000);
        goto LAB_14000217a;
      }
      goto LAB_1400021ba;
    }
  }
  uVar10 = 0xc000000d;
  *pcVar7 = '\0';
LAB_1400021ba:
  BowserFreeViewBuffer((longlong)plVar5);
  return uVar10;
}



===== BowserAllocateViewBuffer @ 1400022e0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * BowserAllocateViewBuffer(void)

{
  longlong lVar1;
  code *pcVar2;
  undefined1 uVar3;
  longlong *plVar4;
  undefined1 *puVar5;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  uVar3 = KeAcquireSpinLockRaiseToDpc(&BowserViewBufferListSpinLock);
  plVar4 = BowserViewBufferHead;
  puVar5 = auStack_28;
  if ((longlong **)BowserViewBufferHead != &BowserViewBufferHead) {
    lVar1 = *BowserViewBufferHead;
    if (((longlong **)BowserViewBufferHead[1] == &BowserViewBufferHead) &&
       (*(longlong **)(lVar1 + 8) == BowserViewBufferHead)) {
      BowserViewBufferHead = (longlong *)lVar1;
      *(longlong ***)(lVar1 + 8) = &BowserViewBufferHead;
      KeReleaseSpinLock(&BowserViewBufferListSpinLock,uVar3);
      return plVar4 + -1;
    }
    pcVar2 = (code *)swi(0x29);
    uVar3 = (*pcVar2)(3);
    puVar5 = auStack_20;
  }
  if (DAT_14000d298 < BowserNumberOfServerAnnounceBuffers) {
    *(undefined8 *)(puVar5 + -8) = 0x1400023e9;
    KeReleaseSpinLock(&BowserViewBufferListSpinLock,uVar3);
    _DAT_14000d2d4 = _DAT_14000d2d4 + 1;
  }
  else {
    BowserNumberOfServerAnnounceBuffers = BowserNumberOfServerAnnounceBuffers + 1;
    *(undefined8 *)(puVar5 + -8) = 0x140002375;
    KeReleaseSpinLock(&BowserViewBufferListSpinLock);
    *(undefined8 *)(puVar5 + -8) = 0x14000238f;
    plVar4 = (longlong *)ExAllocatePool2(0x42,0x80,0x6276424c);
    if (plVar4 != (longlong *)0x0) {
      *(undefined4 *)plVar4 = 0x800004;
      return plVar4;
    }
    *(undefined8 *)(puVar5 + -8) = 0x1400023a7;
    uVar3 = KeAcquireSpinLockRaiseToDpc(&BowserViewBufferListSpinLock);
    BowserNumberOfServerAnnounceBuffers = BowserNumberOfServerAnnounceBuffers + -1;
    _DAT_14000d2e0 = _DAT_14000d2e0 + 1;
    *(undefined8 *)(puVar5 + -8) = 0x1400023c9;
    KeReleaseSpinLock(&BowserViewBufferListSpinLock,uVar3);
  }
  return (longlong *)0x0;
}



===== BowserTimerDpc @ 140002410 =====

void BowserTimerDpc(undefined8 param_1,longlong param_2)

{
  BowserQueueDelayedWorkItem((undefined8 *)(param_2 + 0xb8));
  return;
}



===== BowserQueueDelayedWorkItem @ 140002430 =====

void BowserQueueDelayedWorkItem(undefined8 *param_1)

{
  code *pcVar1;
  undefined1 uVar2;
  bool bVar3;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(&BowserIrpQueueSpinLock);
  if ((undefined8 *)*DAT_14000d7e8 != &BowserDelayedThreadQueue) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(3);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  bVar3 = BowserDelayedThreadRunning == '\0';
  *param_1 = &BowserDelayedThreadQueue;
  param_1[1] = DAT_14000d7e8;
  *DAT_14000d7e8 = param_1;
  DAT_14000d7e8 = param_1;
  if (bVar3) {
    BowserDelayedThreadRunning = '\x01';
    KeReleaseSpinLock();
    IoQueueWorkItemEx(BowserDelayedThreadWorkItem,BowserDelayedThreadWorker,1);
  }
  else {
    KeReleaseSpinLock(&BowserIrpQueueSpinLock,uVar2);
  }
  return;
}



===== BowserFreeViewBuffer @ 1400024e0 =====

void BowserFreeViewBuffer(longlong param_1)

{
  undefined8 *puVar1;
  code *pcVar2;
  undefined1 uVar3;
  
  uVar3 = KeAcquireSpinLockRaiseToDpc(&BowserViewBufferListSpinLock);
  puVar1 = (undefined8 *)(param_1 + 8);
  if ((undefined8 *)*DAT_14000d288 == &BowserViewBufferHead) {
    *(undefined8 **)(param_1 + 0x10) = DAT_14000d288;
    *puVar1 = &BowserViewBufferHead;
    *DAT_14000d288 = puVar1;
    DAT_14000d288 = puVar1;
    KeReleaseSpinLock(&BowserViewBufferListSpinLock,uVar3);
    return;
  }
  pcVar2 = (code *)swi(0x29);
  (*pcVar2)(3);
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}



===== BowserSafeStrlen @ 140002550 =====

int BowserSafeStrlen(char *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    if (param_2 == 0) {
      return iVar2;
    }
    cVar1 = *param_1;
    param_1 = param_1 + 1;
    param_2 = param_2 + -1;
    if (cVar1 == '\0') break;
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}



===== RtlStringCbCopyNA @ 140002580 =====

undefined8 RtlStringCbCopyNA(char *param_1,longlong param_2,longlong param_3,ulonglong param_4)

{
  char *pcVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong lVar4;
  
  if (param_2 - 1U < 0x7fffffff) {
    if (param_4 < 0x7fffffff) {
      lVar4 = param_4 - param_2;
      lVar3 = param_3 - (longlong)param_1;
      do {
        if ((lVar4 + param_2 == 0) || (param_1[lVar3] == '\0')) break;
        *param_1 = param_1[lVar3];
        param_1 = param_1 + 1;
        param_2 = param_2 + -1;
      } while (param_2 != 0);
      pcVar1 = param_1 + -1;
      if (param_2 != 0) {
        pcVar1 = param_1;
      }
      *pcVar1 = '\0';
      uVar2 = 0x80000005;
      if (param_2 != 0) {
        uVar2 = 0;
      }
      return uVar2;
    }
    *param_1 = '\0';
  }
  return 0xc000000d;
}



===== BowserFsdDispatch @ 1400025f0 =====

ulonglong BowserFsdDispatch(uint *param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  undefined4 extraout_var;
  ulonglong uVar3;
  
  cVar1 = **(char **)(param_2 + 0xb8);
  if (cVar1 == '\x0e') {
    uVar2 = BowserFsdDeviceIoControlFile(param_1,param_2);
    uVar3 = CONCAT44(extraout_var,uVar2);
  }
  else {
    if (cVar1 == '\0') {
      uVar3 = BowserFsdCreate(param_1,(longlong)param_2);
      return uVar3;
    }
    if (cVar1 == '\x02') {
      uVar3 = BowserFsdClose(param_1,(longlong)param_2);
      return uVar3;
    }
    if (cVar1 == '\x12') {
      uVar3 = BowserFsdCleanup((ulonglong)param_1,(longlong)param_2);
      return uVar3;
    }
    if (cVar1 == '\x05') {
      uVar3 = BowserFsdQueryInformationFile(param_1,(longlong)param_2);
    }
    else {
      param_2[0x30] = '\x02';
      param_2[0x31] = '\0';
      param_2[0x32] = '\0';
      param_2[0x33] = -0x40;
      param_2[0x38] = '\0';
      param_2[0x39] = '\0';
      param_2[0x3a] = '\0';
      param_2[0x3b] = '\0';
      param_2[0x3c] = '\0';
      param_2[0x3d] = '\0';
      param_2[0x3e] = '\0';
      param_2[0x3f] = '\0';
      IofCompleteRequest(param_2,0);
      uVar3 = 0xc0000002;
    }
  }
  return uVar3;
}



===== BowserClassifyIncomingDatagram @ 140002690 =====

ulonglong BowserClassifyIncomingDatagram
                    (int *param_1,uint param_2,undefined8 *param_3,uint *param_4)

{
  char *_Str1;
  byte bVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  _Str1 = (char *)((longlong)param_1 + 0x45);
  if ((((((0x1f < param_2) && (*param_1 == 0x424d53ff)) && ((char)param_1[1] == '%')) &&
       ((0x4e < param_2 && ((char)param_1[8] == '\x11')))) &&
      ((*(char *)((longlong)param_1 + 0x3b) == '\x03' &&
       ((*(short *)((longlong)param_1 + 0x21) == 0 && (*(short *)((longlong)param_1 + 0x3d) == 1))))
      )) && (*(short *)((longlong)param_1 + 0x41) == 2)) {
    iVar8 = (int)param_1;
    uVar7 = (iVar8 - (int)_Str1) + param_2;
    if (8 < uVar7) {
      uVar6 = 9;
      iVar2 = _strnicmp(_Str1,"\\MAILSLOT",9);
      if (iVar2 == 0) {
        uVar4 = 0xf9;
        if ((0xf9 < uVar7) || (uVar4 = uVar7, 9 < uVar7)) {
          pcVar3 = (char *)((longlong)param_1 + 0x4e);
          do {
            if (*pcVar3 == '\0') break;
            uVar6 = uVar6 + 1;
            pcVar3 = pcVar3 + 1;
          } while (uVar6 < uVar4);
        }
        if (uVar6 != uVar4) {
          if ((((int)_Str1 - iVar8) + param_2 < 0x10) ||
             ((iVar2 = _strnicmp(_Str1,"\\MAILSLOT\\LANMAN",0x10), iVar2 != 0 &&
              (iVar2 = _strnicmp(_Str1,"\\MAILSLOT\\BROWSE",0x10), iVar2 != 0)))) {
            return 0xfffffffe;
          }
          if ((uint)*(ushort *)((longlong)param_1 + 0x39) <= param_2 - 1) {
            pbVar5 = (byte *)((ulonglong)*(ushort *)((longlong)param_1 + 0x39) + (longlong)param_1);
            *param_3 = pbVar5;
            bVar1 = *pbVar5;
            uVar7 = (iVar8 - (int)pbVar5) + param_2;
            *param_4 = uVar7;
            if ((bVar1 < 0x10) && ((byte)(&BowserMinimumDatagramSize)[bVar1] <= uVar7)) {
              return (ulonglong)bVar1;
            }
          }
        }
      }
    }
  }
  return 0;
}



===== BowserDelayedThreadWorker @ 140002830 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void BowserDelayedThreadWorker(void)

{
  undefined8 *puVar1;
  code *pcVar2;
  undefined8 *puVar3;
  undefined1 uVar4;
  
  while( true ) {
    uVar4 = KeAcquireSpinLockRaiseToDpc(&BowserIrpQueueSpinLock);
    puVar3 = BowserDelayedThreadQueue;
    if ((undefined8 **)BowserDelayedThreadQueue == &BowserDelayedThreadQueue) {
      BowserDelayedThreadRunning = 0;
      KeReleaseSpinLock(&BowserIrpQueueSpinLock,uVar4);
      return;
    }
    if (((undefined8 **)BowserDelayedThreadQueue[1] != &BowserDelayedThreadQueue) ||
       (puVar1 = (undefined8 *)*BowserDelayedThreadQueue,
       (undefined8 *)puVar1[1] != BowserDelayedThreadQueue)) break;
    BowserDelayedThreadQueue = puVar1;
    puVar1[1] = &BowserDelayedThreadQueue;
    KeReleaseSpinLock(&BowserIrpQueueSpinLock,uVar4);
    (*(code *)puVar3[2])(puVar3[3]);
  }
  pcVar2 = (code *)swi(0x29);
  (*pcVar2)(3);
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}



===== BowserScavengerTimerDispatch @ 1400028e0 =====

void BowserScavengerTimerDispatch(void)

{
  code *pcVar1;
  undefined1 uVar2;
  undefined8 *puVar3;
  bool bVar4;
  
  puVar3 = (undefined8 *)ExAllocatePool2(0x42,0x20,0x6977424c);
  if (puVar3 != (undefined8 *)0x0) {
    puVar3[3] = puVar3;
    puVar3[2] = BowserScavenger;
    *puVar3 = 0;
    uVar2 = KeAcquireSpinLockRaiseToDpc(&BowserIrpQueueSpinLock);
    if ((undefined8 *)*DAT_14000d7e8 != &BowserDelayedThreadQueue) {
      pcVar1 = (code *)swi(0x29);
      (*pcVar1)(3);
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    bVar4 = BowserDelayedThreadRunning == '\0';
    *puVar3 = &BowserDelayedThreadQueue;
    puVar3[1] = DAT_14000d7e8;
    *DAT_14000d7e8 = puVar3;
    DAT_14000d7e8 = puVar3;
    if (bVar4) {
      BowserDelayedThreadRunning = '\x01';
      KeReleaseSpinLock();
      IoQueueWorkItemEx(BowserDelayedThreadWorkItem,BowserDelayedThreadWorker,1);
    }
    else {
      KeReleaseSpinLock(&BowserIrpQueueSpinLock,uVar2);
    }
  }
  return;
}



===== RtlStringCbCopyA @ 1400029d0 =====

undefined8 RtlStringCbCopyA(char *param_1,longlong param_2,longlong param_3)

{
  char *pcVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong lVar4;
  
  if (param_2 - 1U < 0x7fffffff) {
    lVar4 = 0x7ffffffe - param_2;
    lVar3 = param_3 - (longlong)param_1;
    do {
      if ((lVar4 + param_2 == 0) || (param_1[lVar3] == '\0')) break;
      *param_1 = param_1[lVar3];
      param_1 = param_1 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
    pcVar1 = param_1 + -1;
    if (param_2 != 0) {
      pcVar1 = param_1;
    }
    *pcVar1 = '\0';
    uVar2 = 0x80000005;
    if (param_2 != 0) {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0xc000000d;
    if (param_2 != 0) {
      *param_1 = '\0';
      return uVar2;
    }
  }
  return uVar2;
}



===== BowserIsLegalBackupBrowser @ 140002a40 =====

bool BowserIsLegalBackupBrowser(longlong param_1,ushort *param_2)

{
  ulonglong uVar1;
  
  if ((((*(int *)(*(longlong *)(param_1 + 0x20) + 0x38) == 4) ||
       ((*(uint *)(param_1 + 0x4c) >> 0x11 & 1) == 0)) ||
      ((*(uint *)(param_1 + 0x4c) >> 0x12 & 1) != 0)) || (*(ushort *)(param_1 + 0x28) < 0x10f)) {
    return false;
  }
  uVar1 = RtlCompareMemory(param_1 + 0x2a,*(undefined8 *)(param_2 + 4),*param_2);
  return uVar1 != *param_2;
}



===== BowserForEachTransportInDomain @ 140002ab0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int BowserForEachTransportInDomain(longlong param_1,undefined *param_2,undefined8 param_3)

{
  longlong lVar1;
  int iVar2;
  undefined8 *puVar3;
  
  iVar2 = 0;
  ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
  puVar3 = BowserTransportHead;
  while( true ) {
    while( true ) {
      while( true ) {
        if ((undefined8 **)puVar3 == &BowserTransportHead) {
          ExReleaseResourceLite(&BowserTransportDatabaseResource);
          return iVar2;
        }
        lVar1 = puVar3[-1];
        if (*(char *)((longlong)puVar3 + 0x14e) == '\0') break;
        puVar3 = (undefined8 *)*puVar3;
      }
      if (*(longlong *)(lVar1 + 0x38) == param_1) break;
      puVar3 = (undefined8 *)*puVar3;
    }
    LOCK();
    *(int *)(lVar1 + 4) = *(int *)(lVar1 + 4) + 1;
    UNLOCK();
    ExReleaseResourceLite(&BowserTransportDatabaseResource);
    iVar2 = (*(code *)param_2)(lVar1,param_3);
    if (iVar2 < 0) break;
    ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
    puVar3 = (undefined8 *)*puVar3;
    BowserDereferenceTransport(lVar1);
  }
  BowserDereferenceTransport(lVar1);
  return iVar2;
}



===== BowserReferenceTransport @ 140002bc0 =====

void BowserReferenceTransport(longlong param_1)

{
  LOCK();
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  UNLOCK();
  return;
}



===== BowserValidUnicodeString @ 140002bd0 =====

undefined8 BowserValidUnicodeString(byte *param_1)

{
  if (((*param_1 & 1) == 0) && ((param_1[8] & 1) == 0)) {
    return 1;
  }
  return 0;
}



===== RdrDiscardableCodeDpcRoutine @ 140002bf0 =====

void RdrDiscardableCodeDpcRoutine(undefined8 param_1,undefined8 param_2)

{
  ExQueueWorkItem(param_2,0);
  return;
}



===== CompleteSendDatagram @ 140002c20 =====

undefined8 CompleteSendDatagram(undefined8 param_1,longlong param_2,undefined8 *param_3)

{
  if (*(char *)(param_3 + 2) == '\0') {
    ExFreePoolWithTag(*param_3);
    ExFreePoolWithTag(param_3[1],0);
    ExFreePoolWithTag(param_3,0);
    IoFreeMdl(*(undefined8 *)(param_2 + 8));
    IoFreeIrp(param_2);
  }
  else {
    KeSetEvent(param_3 + 3,0,0);
  }
  return 0xc0000016;
}



===== BowserGetCurrentTime @ 140002cc0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong BowserGetCurrentTime(void)

{
  longlong lVar1;
  
  lVar1 = SUB168(SEXT816(-0x29406b2a1a85bd43) *
                 SEXT816((longlong)((ulonglong)BowserTimeIncrement * _DAT_fffff78000000320)),8) +
          (ulonglong)BowserTimeIncrement * _DAT_fffff78000000320;
  return (lVar1 >> 0x17) - (lVar1 >> 0x3f);
}



===== BowserIsValidPotentialBrowser @ 140002d00 =====

ulonglong BowserIsValidPotentialBrowser(longlong param_1,longlong param_2)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  undefined4 extraout_var;
  
  uVar3 = *(ulonglong *)(param_2 + 0x20);
  if (*(int *)(uVar3 + 0x38) == 6) {
    uVar1 = *(uint *)(param_2 + 0x4c);
    uVar3 = (ulonglong)uVar1;
    if ((((uVar1 >> 0x10 & 1) != 0) && ((uVar1 & 0x60000) == 0)) &&
       (uVar3 = 0x10f, 0x10e < *(ushort *)(param_2 + 0x28))) {
      iVar2 = _wcsicmp((wchar_t *)(param_2 + 0x2a),(wchar_t *)(*(longlong *)(param_1 + 0x38) + 0x68)
                      );
      uVar3 = CONCAT44(extraout_var,iVar2);
      if (iVar2 != 0) {
        return CONCAT71((int7)(uVar3 >> 8),*(uint *)(param_2 + 0x58) < 10);
      }
    }
  }
  return uVar3 & 0xffffffffffffff00;
}



===== BowserCanonicalizeNetBiosName @ 140002d70 =====

ulonglong BowserCanonicalizeNetBiosName(ushort *param_1,undefined8 param_2,undefined1 param_3)

{
  uint uVar1;
  ulonglong uVar2;
  
  uVar1 = RtlxUnicodeStringToOemSize(param_2);
  if (0x10 < uVar1) {
    return 0xc00000be;
  }
  uVar2 = RtlUpcaseUnicodeStringToOemString(param_1,param_2,0);
  if (-1 < (int)uVar2) {
    memcpy((void *)(*(longlong *)(param_1 + 4) + (ulonglong)*param_1),s__14000d1e8,
           0x10 - (ulonglong)*param_1);
    *(undefined1 *)(*(longlong *)(param_1 + 4) + 0xf) = param_3;
    *param_1 = 0x10;
    uVar2 = uVar2 & 0xffffffff;
  }
  return uVar2;
}



===== BowserCreateTransportName @ 140002e20 =====

ulonglong BowserCreateTransportName(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  int iVar3;
  code *pcVar4;
  bool bVar5;
  byte bVar6;
  uint uVar7;
  longlong lVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  longlong *plVar11;
  undefined7 extraout_var;
  ulonglong uVar12;
  ulonglong uVar13;
  longlong lVar14;
  
  lVar14 = *(longlong *)(param_1 + 8);
  ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
  bVar5 = true;
  lVar8 = BowserFindTransportName(param_1,param_2);
  if (lVar8 != 0) {
    ExReleaseResourceLite(&BowserTransportDatabaseResource);
    return 0;
  }
  if (*(char *)(lVar14 + 0x15e) != '\0') {
    ExReleaseResourceLite(&BowserTransportDatabaseResource);
    return 0xc0000056;
  }
  puVar9 = (undefined4 *)ExAllocatePool2(0x42,0x5a,0x6e74424c);
  if (puVar9 != (undefined4 *)0x0) {
    puVar10 = (undefined4 *)ExAllocatePool2(0x102,0x40,0x6e70424c);
    *(undefined4 **)(puVar9 + 4) = puVar10;
    if (puVar10 != (undefined4 *)0x0) {
      *puVar9 = 0x400003;
      puVar9[2] = 2;
      *(undefined4 **)(puVar10 + 2) = puVar9;
      *puVar10 = 0x400009;
      *(longlong *)(puVar10 + 4) = param_2;
      BowserReferenceName(param_2);
      *(longlong *)(puVar9 + 6) = param_1;
      *(undefined8 *)(puVar10 + 0xe) = 0;
      plVar1 = (longlong *)(puVar10 + 6);
      *(undefined8 *)(puVar9 + 8) = 0;
      *(undefined8 *)(puVar9 + 10) = 0;
      plVar11 = (longlong *)(*(longlong *)(param_1 + 8) + 0x20);
      lVar8 = *plVar11;
      if (*(longlong **)(lVar8 + 8) != plVar11) {
LAB_1400030cf:
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3);
        pcVar4 = (code *)swi(3);
        uVar13 = (*pcVar4)();
        return uVar13;
      }
      *plVar1 = lVar8;
      *(longlong **)(puVar10 + 8) = plVar11;
      *(longlong **)(lVar8 + 8) = plVar1;
      plVar2 = (longlong *)(param_2 + 0x18);
      *plVar11 = (longlong)plVar1;
      plVar11 = (longlong *)(puVar10 + 10);
      lVar8 = *plVar2;
      if (*(longlong **)(lVar8 + 8) != plVar2) goto LAB_1400030cf;
      *(longlong **)(puVar10 + 0xc) = plVar2;
      *plVar11 = lVar8;
      *(longlong **)(lVar8 + 8) = plVar11;
      *plVar2 = (longlong)plVar11;
      *(bool *)((longlong)puVar9 + 5) = *(int *)(param_2 + 0x38) == 4;
      iVar3 = *(int *)(param_2 + 0x38);
      if (iVar3 == 1) {
        *(undefined4 **)(param_1 + 0x10) = puVar9;
      }
      else if (iVar3 == 2) {
        if (*(longlong *)(param_1 + 0x18) != 0) {
          *(longlong *)(param_1 + 0x20) = *(longlong *)(param_1 + 0x18);
        }
        *(undefined4 **)(param_1 + 0x18) = puVar9;
      }
      else if (iVar3 == 6) {
        *(undefined4 **)(param_1 + 0x28) = puVar9;
      }
      else if (iVar3 == 7) {
        *(undefined4 **)(param_1 + 0x30) = puVar9;
      }
      else if (iVar3 == 10) {
        *(undefined1 *)(lVar14 + 0x15c) = 1;
        lVar14 = *(longlong *)(param_1 + 8);
        bVar6 = BowserTransportFlags(lVar14);
        BowserSendPnp(5,(ushort *)(*(longlong *)(param_1 + 0x38) + 0x58),(ushort *)(lVar14 + 0x30),
                      (ushort *)(CONCAT71(extraout_var,bVar6) & 0xffffffff));
      }
      *(undefined2 *)((longlong)puVar9 + 0x32) = 0x1a;
      *(undefined4 **)(puVar9 + 0xe) = puVar9 + 0x10;
      uVar12 = BowserBuildTransportAddress
                         ((undefined2 *)(puVar9 + 0xc),param_2 + 0x28,
                          (ulonglong)*(uint *)(param_2 + 0x38),param_1);
      uVar13 = uVar12 & 0xffffffff;
      if ((int)uVar12 < 0) {
LAB_14000307f:
        if (*plVar1 != 0) {
          BowserDereferenceTransportName((longlong)puVar9);
        }
      }
      else {
        *(undefined1 *)(puVar9 + 1) = *(undefined1 *)(param_2 + 0x38);
        ExReleaseResourceLite(&BowserTransportDatabaseResource);
        bVar5 = false;
        if (-1 < *(short *)(*(longlong *)(param_1 + 8) + 0x158)) {
          uVar7 = BowserOpenNetbiosAddress((longlong)puVar10,param_1);
          uVar13 = (ulonglong)uVar7;
          if ((int)uVar7 < 0) goto LAB_14000307f;
        }
      }
      BowserDereferenceTransportName((longlong)puVar9);
      if (!bVar5) {
        return uVar13;
      }
      goto LAB_14000309b;
    }
    ExFreePoolWithTag(puVar9,0);
  }
  uVar13 = 0xc000009a;
LAB_14000309b:
  ExReleaseResourceLite(&BowserTransportDatabaseResource);
  return uVar13;
}



===== BowserDequeueQueuedIrp @ 1400030e0 =====

longlong BowserDequeueQueuedIrp(longlong *param_1,char param_2)

{
  longlong *plVar1;
  longlong lVar2;
  code *pcVar3;
  undefined1 *puVar4;
  undefined1 uVar5;
  undefined1 *puVar6;
  longlong *unaff_R14;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  uVar5 = KeAcquireSpinLockRaiseToDpc(&BowserIrpQueueSpinLock);
  plVar1 = (longlong *)*param_1;
  if (plVar1 == param_1) {
    KeReleaseSpinLock(&BowserIrpQueueSpinLock,uVar5);
    return 0;
  }
  if (((longlong *)plVar1[1] == param_1) && (lVar2 = *plVar1, *(longlong **)(lVar2 + 8) == plVar1))
  {
    *param_1 = lVar2;
    unaff_R14 = plVar1 + -0x15;
    *(longlong **)(lVar2 + 8) = param_1;
    IoAcquireCancelSpinLock((longlong)plVar1 + -99);
    *(undefined1 *)((longlong)plVar1 + -100) = 0;
    LOCK();
    plVar1[-8] = 0;
    UNLOCK();
    IoReleaseCancelSpinLock(*(undefined1 *)((longlong)plVar1 + -99));
    puVar6 = auStack_28;
    puVar4 = auStack_28;
    if (param_2 == '\0') goto LAB_14000319d;
  }
  else {
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(3);
    puVar4 = auStack_20;
  }
  puVar6 = puVar4;
  if ((longlong *)*param_1 == param_1) {
    *(undefined8 *)(puVar6 + -8) = 0x1400031de;
    BowserDeactivateScavengerTimer();
  }
LAB_14000319d:
  *(undefined8 *)(puVar6 + -8) = 0x1400031af;
  KeReleaseSpinLock(&BowserIrpQueueSpinLock,uVar5);
  return (longlong)unaff_R14;
}



===== BowserProbeAndCopyBuffer @ 1400031f0 =====

undefined8 BowserProbeAndCopyBuffer(ushort *param_1,undefined2 *param_2)

{
  ushort uVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  uVar1 = *param_1;
  if (uVar1 == 0) {
    *param_2 = 0;
    return 0;
  }
  if ((ulonglong)(ushort)param_2[1] < (ulonglong)uVar1 + 2) {
    uVar2 = 0xc000000d;
  }
  else {
    ProbeForRead(*(undefined8 *)(param_1 + 4),uVar1,2);
    RtlCopyUnicodeString(param_2,param_1);
  }
  return uVar2;
}



===== BowserUninitializeDatagramQueue @ 140003280 =====

void BowserUninitializeDatagramQueue(longlong *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  code *pcVar3;
  undefined1 uVar4;
  
  uVar4 = KeAcquireSpinLockRaiseToDpc(&BowserDatagramQueueSpinLock);
  while( true ) {
    plVar1 = (longlong *)*param_1;
    if (plVar1 == param_1) {
      *param_1 = 0;
      param_1[1] = 0;
      KeReleaseSpinLock(&BowserDatagramQueueSpinLock,uVar4);
      return;
    }
    if (((longlong *)plVar1[1] != param_1) || (lVar2 = *plVar1, *(longlong **)(lVar2 + 8) != plVar1)
       ) break;
    *param_1 = lVar2;
    *(longlong **)(lVar2 + 8) = param_1;
    *(int *)(param_1 + 2) = (int)param_1[2] + -1;
    ExFreePoolWithTag(plVar1,0);
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== HandleAnnounceRequest @ 140003310 =====

undefined8 HandleAnnounceRequest(longlong param_1)

{
  undefined8 uVar1;
  
  if ((param_1 == 0) || (*(longlong *)(param_1 + 0x18) == 0)) {
    uVar1 = 0xc000000d;
  }
  else {
    if (((*(int *)(*(longlong *)(param_1 + 0x18) + 0x60) != 2) &&
        ((*(char *)(param_1 + 4) - 2U & 0xfa) == 0)) && (*(char *)(param_1 + 4) != '\x03')) {
      KeSetEvent(BowserServerAnnouncementEvent,2);
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== BowserCriticalThreadWorker @ 140003370 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void BowserCriticalThreadWorker(void)

{
  undefined8 *puVar1;
  code *pcVar2;
  undefined8 *puVar3;
  undefined1 uVar4;
  
  while( true ) {
    uVar4 = KeAcquireSpinLockRaiseToDpc(&BowserIrpQueueSpinLock);
    puVar3 = BowserCriticalThreadQueue;
    if ((undefined8 **)BowserCriticalThreadQueue == &BowserCriticalThreadQueue) {
      BowserCriticalThreadRunning = 0;
      KeReleaseSpinLock(&BowserIrpQueueSpinLock,uVar4);
      return;
    }
    if (((undefined8 **)BowserCriticalThreadQueue[1] != &BowserCriticalThreadQueue) ||
       (puVar1 = (undefined8 *)*BowserCriticalThreadQueue,
       (undefined8 *)puVar1[1] != BowserCriticalThreadQueue)) break;
    BowserCriticalThreadQueue = puVar1;
    puVar1[1] = &BowserCriticalThreadQueue;
    KeReleaseSpinLock(&BowserIrpQueueSpinLock,uVar4);
    (*(code *)puVar3[2])(puVar3[3]);
  }
  pcVar2 = (code *)swi(0x29);
  (*pcVar2)(3);
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}



===== BowserGetBackupListResponse @ 140003420 =====

undefined8 BowserGetBackupListResponse(longlong param_1,byte *param_2,ulonglong param_3)

{
  byte *pbVar1;
  byte bVar2;
  longlong lVar3;
  uint uVar4;
  undefined1 uVar5;
  uint uVar6;
  ulonglong _Size;
  byte *pbVar7;
  uint in_stack_00000048;
  
  lVar3 = *(longlong *)(param_1 + 0x18);
  pbVar7 = param_2 + 5;
  _Size = param_3 & 0xffffffff;
  uVar6 = 0;
  if (*(longlong *)(lVar3 + 0x58) != 0) {
    uVar5 = KeAcquireSpinLockRaiseToDpc(&BowserBackupListSpinLock);
    if (*(int *)(param_2 + 1) == *(int *)(lVar3 + 0x44)) {
      bVar2 = *param_2;
      if (bVar2 != 0) {
        do {
          if (param_2 + _Size <= pbVar7) break;
          uVar4 = uVar6 + 1;
          if (*pbVar7 != 0) {
            uVar4 = uVar6;
          }
          uVar6 = uVar4;
          pbVar7 = pbVar7 + 1;
        } while (uVar6 < bVar2);
      }
      if ((pbVar7 != param_2 + _Size) || (bVar2 <= uVar6)) {
        pbVar7 = *(byte **)(lVar3 + 0x58);
        *(int *)(lVar3 + 0x44) = *(int *)(lVar3 + 0x44) + 1;
        if (pbVar7 != (byte *)0x0) {
          if ((in_stack_00000048 & 0x200) == 0) {
            pbVar1 = pbVar7 + _Size;
            for (; pbVar7 < pbVar1; pbVar7 = pbVar7 + 1) {
              bVar2 = *param_2;
              param_2 = param_2 + 1;
              *pbVar7 = bVar2;
            }
          }
          else {
            memcpy(pbVar7,param_2,_Size);
          }
          KeSetEvent(lVar3 + 0x360,2);
        }
        KeReleaseSpinLock(&BowserBackupListSpinLock,uVar5);
        return 0;
      }
    }
    KeReleaseSpinLock(&BowserBackupListSpinLock,uVar5);
  }
  return 0xc00000d0;
}



===== BowserReferenceTransportName @ 14000356c =====

void BowserReferenceTransportName(longlong param_1)

{
  LOCK();
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  UNLOCK();
  return;
}



===== BowserCopyOemComputerName @ 140003578 =====

void BowserCopyOemComputerName(undefined1 *param_1,void *param_2,uint param_3,uint param_4)

{
  undefined1 *puVar1;
  uint uVar2;
  
  if ((param_4 >> 9 & 1) == 0) {
    if (param_1 < param_1 + param_3) {
      puVar1 = param_1;
      do {
        *puVar1 = puVar1[(longlong)param_2 - (longlong)param_1];
        puVar1 = puVar1 + 1;
      } while (puVar1 < param_1 + param_3);
    }
  }
  else {
    memcpy(param_1,param_2,(ulonglong)param_3);
  }
  if (1 < param_3) {
    for (uVar2 = param_3 - 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      if ((param_1[uVar2] & 0xdf) != 0) {
        param_1[uVar2 + 1] = 0;
        return;
      }
    }
  }
  return;
}



===== IsZeroTerminated @ 1400035e4 =====

undefined1 IsZeroTerminated(char *param_1,int param_2)

{
  char cVar1;
  
  do {
    if (param_2 == 0) {
      return 0;
    }
    cVar1 = *param_1;
    param_1 = param_1 + 1;
    param_2 = param_2 + -1;
  } while (cVar1 != '\0');
  return 1;
}



===== BowserTdiReceiveDatagramHandler @ 140003610 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong BowserTdiReceiveDatagramHandler
                    (longlong param_1,uint param_2,int *param_3,uint param_4,undefined1 *param_5,
                    uint param_6,uint param_7,uint param_8,uint *param_9,int *param_10,
                    longlong *param_11)

{
  uint uVar1;
  int iVar2;
  undefined4 extraout_var;
  ulonglong uVar3;
  undefined4 uVar4;
  undefined1 auStackY_e8 [32];
  uint local_88;
  uint local_84;
  uint *local_80;
  longlong *local_78;
  longlong local_70;
  undefined1 *local_68;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined1 auStack_58 [8];
  undefined8 local_50;
  undefined2 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_e8;
  uVar4 = 0;
  local_68 = param_5;
  local_80 = param_9;
  local_78 = param_11;
  local_70 = 0;
  local_88 = 0;
  if (((param_8 <= *(uint *)(*(longlong *)(param_1 + 0x18) + 0x40)) &&
      (*(longlong *)(param_1 + 0x28) != 0)) && (0x19 < param_2)) {
    auStack_58 = *(undefined1 (*) [8])(param_3 + 2);
    local_48 = (undefined2)param_3[6];
    local_50 = *(undefined8 *)(param_3 + 4);
    uStack_5c._2_2_ = (short)((ulonglong)*(undefined8 *)param_3 >> 0x30);
    if (uStack_5c._2_2_ == 0x11) {
      _local_60 = CONCAT44((int)((ulonglong)*(undefined8 *)param_3 >> 0x20),1);
      local_84 = param_4;
      uVar1 = BowserIsRemoteMailslotsDeprecated();
      if ((int)uVar1 < 0) {
        return CONCAT44(extraout_var,uVar1);
      }
      uVar3 = BowserClassifyIncomingDatagram(param_10,param_7,&local_70,&local_88);
      iVar2 = (int)uVar3;
      if (iVar2 == -2) {
        if (((1 < *param_3) &&
            (uVar3 = (ulonglong)*(ushort *)(param_3 + 1),
            0xd < *(ushort *)(uVar3 + 8 + (longlong)param_3))) &&
           (*(short *)(uVar3 + 10 + (longlong)param_3) == 2)) {
          uVar4 = *(undefined4 *)(uVar3 + 0xe + (longlong)param_3);
        }
        uVar3 = BowserHandleMailslotTransaction
                          (param_1,(longlong *)(auStack_58 + 2),uVar4,0,param_6,param_7,param_8,
                           local_80,(longlong)param_10,local_78);
        return uVar3;
      }
      if (iVar2 == 0) {
        BowserLogIllegalDatagram(param_1,(longlong)param_10,(ushort)param_7,auStack_58 + 2,param_6);
      }
      else {
        if (*(code **)(&BowserDatagramHandlerTable + (longlong)iVar2 * 8) == (code *)0x0) {
          return 0;
        }
        if (param_7 < param_8) {
          uVar3 = BowserHandleShortBrowserPacket
                            (param_1,param_1,0x1a,&local_60,local_84,local_68,param_6,param_8,
                             local_80,local_78,BowserTdiReceiveDatagramHandler);
          return uVar3;
        }
        if (((iVar2 != 0xc) && (iVar2 != 1)) || (*(char *)(param_1 + 5) != '\0')) {
          uVar3 = (**(code **)(&BowserDatagramHandlerTable + (longlong)iVar2 * 8))
                            (param_1,local_70 + 1,(param_7 - 1) + ((int)param_10 - (int)local_70),
                             local_80);
          return uVar3;
        }
      }
    }
  }
  return 0xc00000d0;
}



===== _tlgKeywordOn @ 140003870 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong _tlgKeywordOn(void)

{
  ulonglong in_RAX;
  
  if (((_DAT_14000d100 & 0x400000000000) == 0) ||
     (in_RAX = DAT_14000d108 & 0x400000000000, in_RAX != DAT_14000d108)) {
    return in_RAX & 0xffffffffffffff00;
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}



===== BowWriteTelemetryMailslotProcessing @ 1400038a4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void BowWriteTelemetryMailslotProcessing
               (wchar_t *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  undefined1 auStackY_78 [32];
  undefined1 local_48 [32];
  longlong local_28 [2];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  if (5 < DAT_14000d0f0) {
    uVar1 = _tlgKeywordOn();
    if ((char)uVar1 != '\0') {
      _tlgCreate1Sz_wchar_t(local_28,param_1);
      _tlgWriteTransfer_EtwWriteTransfer
                (local_48,&DAT_140009c1d,param_3,param_4,3,(undefined8 *)local_48);
    }
  }
  return;
}



===== BowserActivateScavengerTimer @ 140003910 =====

void BowserActivateScavengerTimer(void)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(&BowserTimeSpinLock);
  BowserScavengerReferenceCount = BowserScavengerReferenceCount + 1;
  if (BowserScavengerReferenceCount == 1) {
    KeSetCoalescableTimer(&BowserScavengerTimer,0xffffffffee1e5d00,30000,15000,&BowserScavengerDpc);
  }
  KeReleaseSpinLock(&BowserTimeSpinLock,uVar1);
  return;
}



===== BowWriteTelemetryMailslotProcessing3 @ 140003994 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void BowWriteTelemetryMailslotProcessing3(undefined8 param_1,ushort *param_2,undefined8 param_3)

{
  ulonglong uVar1;
  undefined1 auStackY_98 [32];
  undefined8 local_68 [4];
  longlong local_48 [2];
  uint *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  uint local_20 [2];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  if (5 < DAT_14000d0f0) {
    uVar1 = _tlgKeywordOn();
    if ((char)uVar1 != '\0') {
      _tlgCreate1Sz_wchar_t(local_48,L"WriteMailslotEx");
      local_28 = *(undefined8 *)(param_2 + 4);
      local_38 = local_20;
      local_2c = 0;
      local_20[1] = 0;
      local_20[0] = (uint)*param_2;
      local_30 = 2;
      _tlgWriteTransfer_EtwWriteTransfer(local_38,&DAT_140009bde,param_3,param_2,5,local_68);
    }
  }
  return;
}



===== BowserCancelQueuedRequest @ 140003a40 =====

void BowserCancelQueuedRequest(undefined8 param_1,longlong param_2)

{
  longlong *******ppppppplVar1;
  longlong *******ppppppplVar2;
  uint uVar3;
  longlong lVar4;
  longlong *******ppppppplVar5;
  longlong *******ppppppplVar6;
  longlong ******pppppplVar7;
  code *pcVar8;
  undefined1 uVar9;
  undefined1 local_res10 [8];
  longlong *******local_18;
  longlong *******local_10;
  
  local_10 = (longlong *******)&local_18;
  lVar4 = *(longlong *)(param_2 + 0xb8);
  local_18 = (longlong *******)&local_18;
  local_res10[0] = 0;
  IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
  uVar9 = KeAcquireSpinLockRaiseToDpc(&BowserIrpQueueSpinLock);
  IoAcquireCancelSpinLock(local_res10);
  ppppppplVar5 = *(longlong ********)(lVar4 + -0x28);
  if ((ppppppplVar5 != (longlong *******)0x0) &&
     (ppppppplVar6 = (longlong *******)*ppppppplVar5,
     (longlong *******)*ppppppplVar5 != (longlong *******)0x0)) {
    while (ppppppplVar1 = ppppppplVar6, ppppppplVar1 != ppppppplVar5) {
      ppppppplVar6 = (longlong *******)*ppppppplVar1;
      if (*(char *)((longlong)ppppppplVar1 + -100) != '\0') {
        if (((longlong *******)ppppppplVar6[1] != ppppppplVar1) ||
           (pppppplVar7 = ppppppplVar1[1], (longlong *******)*pppppplVar7 != ppppppplVar1))
        goto LAB_140003b9a;
        *pppppplVar7 = (longlong *****)ppppppplVar6;
        ppppppplVar6[1] = pppppplVar7;
        ppppppplVar1[-0xe] = (longlong ******)0x0;
        *(undefined4 *)(ppppppplVar1 + -0xf) = 0xc0000120;
        LOCK();
        ppppppplVar1[-8] = (longlong ******)0x0;
        UNLOCK();
        if ((longlong ********)*local_10 != &local_18) goto LAB_140003b9a;
        ppppppplVar1[1] = (longlong ******)local_10;
        *ppppppplVar1 = (longlong ******)&local_18;
        *local_10 = (longlong ******)ppppppplVar1;
        local_10 = ppppppplVar1;
      }
    }
  }
  IoReleaseCancelSpinLock(local_res10[0]);
  KeReleaseSpinLock(&BowserIrpQueueSpinLock,uVar9);
  while( true ) {
    ppppppplVar5 = local_18;
    if ((longlong ********)local_18 == &local_18) {
      return;
    }
    if (((longlong ********)local_18[1] != &local_18) ||
       (ppppppplVar6 = (longlong *******)*local_18, (longlong *******)ppppppplVar6[1] != local_18))
    break;
    ppppppplVar6[1] = (longlong ******)&local_18;
    ppppppplVar2 = local_18 + -0x15;
    uVar3 = *(uint *)(local_18 + -0xf);
    ppppppplVar1 = local_18 + -0xf;
    local_18 = ppppppplVar6;
    *(uint *)ppppppplVar1 = uVar3;
    if ((uVar3 & 0xc0000000) == 0xc0000000) {
      ppppppplVar5[-0xe] = (longlong ******)0x0;
    }
    IofCompleteRequest(ppppppplVar2,0);
  }
LAB_140003b9a:
  pcVar8 = (code *)swi(0x29);
  (*pcVar8)(3);
  return;
}



===== BowserLogIllegalName @ 140003bb8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void BowserLogIllegalName(undefined4 param_1,void *param_2,ushort param_3)

{
  undefined1 uVar1;
  undefined8 *puVar2;
  int iVar3;
  
  iVar3 = 0;
  uVar1 = KeAcquireSpinLockRaiseToDpc(&BowserTimeSpinLock);
  if (1199999999 <
      (_DAT_fffff78000000320 - _BowserLastIllegalNameEvent) * (ulonglong)BowserTimeIncrement) {
    BowserIllegalNameCount = DAT_14000d29c;
    _BowserLastIllegalNameEvent = _DAT_fffff78000000320;
    BowserIllegalNameThreshold = '\0';
  }
  if (BowserIllegalNameCount < 1) {
    if (BowserIllegalNameThreshold != '\0') goto LAB_140003c5f;
    BowserIllegalNameThreshold = '\x01';
  }
  else {
    BowserIllegalNameCount = BowserIllegalNameCount + -1;
  }
  iVar3 = -0x3fffe0b6;
LAB_140003c5f:
  KeReleaseSpinLock(&BowserTimeSpinLock,uVar1);
  if (iVar3 != 0) {
    puVar2 = (undefined8 *)ExAllocatePool2(0x42,(ulonglong)param_3 + 0x38,0x6469424c);
    if (puVar2 != (undefined8 *)0x0) {
      *(int *)(puVar2 + 5) = iVar3;
      *(undefined4 *)((longlong)puVar2 + 0x2c) = param_1;
      *(ushort *)(puVar2 + 6) = param_3;
      memcpy((void *)((longlong)puVar2 + 0x32),param_2,(ulonglong)param_3);
      *puVar2 = 0;
      puVar2[2] = BowserLogIllegalNameWorker;
      puVar2[3] = puVar2;
      BowserQueueDelayedWorkItem(puVar2);
    }
  }
  return;
}



===== BowserWriteErrorLogEntry @ 140003cf0 =====

void BowserWriteErrorLogEntry
               (undefined4 param_1,undefined4 param_2,void *param_3,ushort param_4,ushort param_5,
               longlong param_6)

{
  void *_Src;
  longlong lVar1;
  undefined2 *puVar2;
  short *psVar3;
  ushort uVar4;
  ulonglong uVar5;
  longlong *plVar6;
  longlong lVar7;
  uint uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  undefined2 *_Dst;
  ushort *puVar11;
  
  uVar9 = 0;
  if (param_5 != 0) {
    if (param_5 != 0) {
      uVar10 = (ulonglong)(uint)param_5;
      plVar6 = &param_6;
      do {
        lVar1 = -1;
        do {
          lVar1 = lVar1 + 1;
        } while (*(short *)(*plVar6 + lVar1 * 2) != 0);
        if (lVar1 != 0) {
          psVar3 = (short *)(*plVar6 + lVar1 * 2);
          do {
            psVar3 = psVar3 + -1;
            if (*psVar3 != 0x20) break;
            lVar1 = lVar1 + -1;
          } while (lVar1 != 0);
        }
        uVar9 = uVar9 + lVar1 * 2 + 2;
        uVar10 = uVar10 - 1;
        plVar6 = plVar6 + 1;
      } while (uVar10 != 0);
    }
  }
  uVar5 = (ulonglong)param_4 + 0x31 + uVar9;
  uVar10 = 0xf0;
  if (uVar5 < 0xf0) {
    uVar10 = uVar5;
  }
  puVar2 = (undefined2 *)IoAllocateErrorLogEntry(BowserDeviceObject);
  if (puVar2 != (undefined2 *)0x0) {
    uVar10 = uVar10 - 0x28;
    *(undefined4 *)(puVar2 + 6) = param_1;
    *puVar2 = 0;
    *(undefined4 *)(puVar2 + 8) = 0;
    *(undefined4 *)(puVar2 + 10) = param_2;
    *(undefined8 *)(puVar2 + 0xe) = 0;
    *(undefined4 *)(puVar2 + 0x12) = 0;
    uVar5 = -(ulonglong)(uVar9 < uVar10) & uVar10 - uVar9;
    *(int *)(puVar2 + 0xc) = BowserSequenceNumber;
    if (uVar10 <= uVar9) {
      uVar9 = uVar10;
    }
    BowserSequenceNumber = BowserSequenceNumber + 1;
    puVar2[3] = (ushort)uVar5 + 0x29 & 0xfffe;
    if ((param_3 == (void *)0x0) || (uVar5 == 0)) {
      uVar8 = 0;
    }
    else {
      uVar8 = (uint)param_4;
      if ((ushort)uVar5 <= param_4) {
        uVar8 = (uint)uVar5 & 0xffff;
      }
      memcpy(puVar2 + 0x14,param_3,(ulonglong)uVar8);
    }
    puVar2[1] = (short)uVar8;
    puVar2[2] = 0;
    if (param_5 != 0) {
      _Dst = (undefined2 *)((ulonglong)(ushort)puVar2[3] + (longlong)puVar2);
      uVar8 = 0;
      if (param_5 != 0) {
        puVar11 = &param_5;
        uVar4 = param_5;
        do {
          puVar11 = puVar11 + 4;
          _Src = *(void **)puVar11;
          lVar1 = -1;
          do {
            lVar7 = lVar1;
            lVar1 = lVar7 + 1;
          } while (*(short *)((longlong)_Src + lVar1 * 2) != 0);
          if (lVar1 != 0) {
            psVar3 = (short *)((longlong)_Src + lVar7 * 2);
            do {
              if (*psVar3 != 0x20) break;
              psVar3 = psVar3 + -1;
              lVar1 = lVar1 + -1;
            } while (lVar1 != 0);
          }
          if (uVar9 < lVar1 * 2 + 2U) {
            if (uVar9 < 2) break;
            lVar1 = (uVar9 >> 1) - 1;
          }
          if (lVar1 != 0) {
            memcpy(_Dst,_Src,lVar1 * 2);
            uVar9 = uVar9 + lVar1 * -2 + -2;
            _Dst[lVar1] = 0;
            _Dst = _Dst + lVar1 + 1;
            puVar2[2] = puVar2[2] + 1;
            uVar4 = param_5;
          }
          uVar8 = uVar8 + 1;
        } while (uVar8 < uVar4);
      }
    }
    IoWriteErrorLogEntry(puVar2);
  }
  return;
}



===== BowWriteTelemetryMailslotProcessing2 @ 140003f20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void BowWriteTelemetryMailslotProcessing2(wchar_t *param_1,int param_2,undefined8 param_3)

{
  ulonglong uVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined1 auStackY_98 [32];
  longlong local_68 [2];
  undefined8 local_58 [4];
  longlong local_38 [2];
  longlong *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  lVar3 = (longlong)param_2;
  if (5 < DAT_14000d0f0) {
    uVar1 = _tlgKeywordOn();
    if ((char)uVar1 != '\0') {
      plVar2 = local_38;
      _tlgCreate1Sz_wchar_t(plVar2,param_1);
      local_1c = 0;
      local_28 = local_68;
      local_20 = 8;
      local_68[0] = lVar3;
      _tlgWriteTransfer_EtwWriteTransfer(plVar2,&DAT_140009b9f,param_3,lVar3,4,local_58);
    }
  }
  return;
}



===== BowserFreeMailslotBufferHighIrql @ 140003fb4 =====

void BowserFreeMailslotBufferHighIrql(longlong param_1)

{
  *(undefined8 *)(param_1 + 8) = 0;
  *(code **)(param_1 + 0x18) = BowserFreeMailslotBuffer;
  *(longlong *)(param_1 + 0x20) = param_1;
  BowserQueueDelayedWorkItem((undefined8 *)(param_1 + 8));
  return;
}



===== __report_gsfailure @ 140003ff0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 140003ffd =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140003ffd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== ProbeForRead @ 14000400f =====

void ProbeForRead(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000400f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ProbeForRead();
  return;
}



===== _guard_check_icall @ 140004030 =====

void _guard_check_icall(void)

{
  return;
}



===== __cpu_features_init @ 140004050 =====

/* WARNING: Removing unreachable block (ram,0x0001400040ba) */
/* WARNING: Removing unreachable block (ram,0x000140004069) */
/* WARNING: Removing unreachable block (ram,0x00014000405a) */

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



===== BowserIsValidBackupBrowser @ 140004118 =====

bool BowserIsValidBackupBrowser(longlong param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  bool bVar4;
  
  lVar2 = *(longlong *)(param_1 + 0x38);
  if ((((*(int *)(*(longlong *)(param_2 + 0x20) + 0x38) == 6) &&
       (uVar1 = *(uint *)(param_2 + 0x4c), (uVar1 >> 0x11 & 1) != 0)) && ((uVar1 >> 0x10 & 1) != 0))
     && ((uVar1 & 0x18) == 0)) {
    uVar3 = RtlCompareMemory(param_2 + 0x2a,*(undefined8 *)(lVar2 + 0x90),
                             *(undefined2 *)(lVar2 + 0x88));
    bVar4 = uVar3 != *(ushort *)(lVar2 + 0x88);
  }
  else {
    bVar4 = false;
  }
  return bVar4;
}



===== BowserResetState @ 140004180 =====

undefined8 BowserResetState(longlong param_1,undefined1 *param_2)

{
  if (BowserRefuseReset == '\0') {
    BowserResetStateForTransport(*(longlong *)(param_1 + 0x18),*param_2);
  }
  return 0;
}



===== BowserResetStateForTransport @ 1400041a8 =====

void BowserResetStateForTransport(longlong param_1,undefined1 param_2)

{
  uint uVar1;
  longlong lVar2;
  
  lVar2 = BowserDequeueQueuedIrp((longlong *)(param_1 + 0x3b8),'\0');
  if (lVar2 != 0) {
    if (*(uint *)(*(longlong *)(lVar2 + 0xb8) + 8) < 0x60) {
      uVar1 = 0xc000009a;
    }
    else {
      *(undefined1 *)(*(longlong *)(lVar2 + 0x18) + 0x38) = param_2;
      uVar1 = 0;
      *(undefined8 *)(lVar2 + 0x38) = 0x60;
    }
    *(uint *)(lVar2 + 0x30) = uVar1;
    if ((uVar1 & 0xc0000000) == 0xc0000000) {
      *(undefined8 *)(lVar2 + 0x38) = 0;
    }
    IofCompleteRequest(lVar2,0);
  }
  return;
}



===== BowserIpxDatagramHandler @ 140004220 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong BowserIpxDatagramHandler
                    (longlong param_1,uint param_2,void *param_3,uint param_4,undefined1 *param_5,
                    uint param_6,uint param_7,uint param_8,uint *param_9,longlong param_10,
                    longlong *param_11)

{
  char cVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  undefined4 extraout_var;
  ulonglong uVar5;
  longlong lVar6;
  longlong lVar7;
  uint *puVar8;
  uint uVar9;
  bool bVar10;
  uint local_res8 [2];
  uint local_res10;
  void *local_res18;
  undefined8 in_stack_ffffffffffffff80;
  undefined4 uVar11;
  undefined8 in_stack_ffffffffffffff90;
  undefined4 uVar12;
  undefined8 in_stack_ffffffffffffff98;
  undefined4 uVar13;
  longlong local_48 [2];
  
  uVar11 = (undefined4)((ulonglong)in_stack_ffffffffffffff80 >> 0x20);
  uVar12 = (undefined4)((ulonglong)in_stack_ffffffffffffff90 >> 0x20);
  uVar13 = (undefined4)((ulonglong)in_stack_ffffffffffffff98 >> 0x20);
  local_48[0] = 0;
  local_res8[0] = 0;
  lVar7 = *(longlong *)(param_1 + 0x10);
  if (*(uint *)(param_1 + 0x40) < param_8) {
    return 0xc00000d0;
  }
  if (param_7 < 0x45) {
    return 0xc00000d0;
  }
  if (lVar7 == 0) {
    return 0xc00000d0;
  }
  cVar1 = *(char *)(param_10 + 0x21);
  lVar2 = *(longlong *)(param_1 + 0x38);
  if (cVar1 == '\x01') {
    lVar6 = *(longlong *)(*(longlong *)(lVar7 + 0x38) + 10) - *(longlong *)(param_10 + 0x24);
    if (lVar6 == 0) {
      lVar6 = *(longlong *)(*(longlong *)(lVar7 + 0x38) + 0x12) - *(longlong *)(param_10 + 0x2c);
    }
    if (lVar6 != 0) {
      lVar6 = *(longlong *)(lVar2 + 0x24) - *(longlong *)(param_10 + 0x24);
LAB_1400042bf:
      if (lVar6 == 0) {
        lVar6 = *(longlong *)(lVar2 + 0x2c) - *(longlong *)(param_10 + 0x2c);
      }
      bVar10 = lVar6 == 0;
      goto LAB_1400042de;
    }
  }
  else {
    if (cVar1 == '\x02') {
      lVar6 = *(longlong *)(lVar2 + 0x24) - *(longlong *)(param_10 + 0x24);
      goto LAB_1400042bf;
    }
    bVar10 = cVar1 == '\x03';
LAB_1400042de:
    if (!bVar10) {
      return 0xc00000d0;
    }
  }
  uVar9 = param_7 - 0x44;
  local_res10 = param_2;
  local_res18 = param_3;
  uVar3 = BowserIsRemoteMailslotsDeprecated();
  if ((int)uVar3 < 0) {
    return CONCAT44(extraout_var,uVar3);
  }
  puVar8 = local_res8;
  uVar5 = BowserClassifyIncomingDatagram((int *)(param_10 + 0x44),uVar9,local_48,puVar8);
  lVar6 = local_48[0];
  iVar4 = (int)uVar5;
  if (iVar4 == -2) {
    *param_9 = 0x44;
    uVar5 = BowserHandleMailslotTransaction
                      (*(longlong *)(param_1 + 0x10),(longlong *)(param_10 + 0x34),0,0x44,param_6,
                       param_7,param_8,param_9,param_10,param_11);
    return uVar5;
  }
  if (iVar4 == 0) {
    lVar7 = *(longlong *)(param_1 + 0x10);
    if (param_8 == param_7) {
      BowserLogIllegalDatagram
                (lVar7,param_10 + 0x44,(short)param_7 - 0x44,(void *)(param_10 + 0x34),param_6);
      return 0xc00000d0;
    }
LAB_14000436f:
    uVar5 = BowserHandleShortBrowserPacket
                      (lVar7,param_1,local_res10,local_res18,param_4,param_5,param_6,param_8,param_9
                       ,param_11,BowserIpxDatagramHandler);
    return uVar5;
  }
  if (*(longlong *)(&BowserDatagramHandlerTable + (longlong)iVar4 * 8) == 0) {
    return 0;
  }
  if (param_7 != param_8) {
    lVar7 = *(longlong *)(param_1 + 0x10);
    goto LAB_14000436f;
  }
  if (*(char *)(param_10 + 0x21) == '\x03') {
    if (iVar4 != 0xf) {
      return 0xc00000d0;
    }
    if ((*(longlong *)(param_1 + 0x28) == 0) ||
       (*(char *)(*(longlong *)(param_1 + 0x28) + 5) == '\0')) {
      uVar5 = 0xc00000d0;
    }
    else {
      uVar5 = BowserHandleIpxDomainAnnouncement(param_1,param_10,local_48[0] + 1,puVar8,param_6);
      uVar5 = uVar5 & 0xffffffff;
    }
    lVar7 = *(longlong *)(lVar2 + 0x24) - *(longlong *)(param_10 + 0x24);
    if (lVar7 == 0) {
      lVar7 = *(longlong *)(lVar2 + 0x2c) - *(longlong *)(param_10 + 0x2c);
    }
    if (lVar7 != 0) {
      return uVar5;
    }
LAB_1400044b2:
    lVar7 = *(longlong *)(param_1 + 0x30);
    bVar10 = lVar7 == 0;
  }
  else {
    if ((iVar4 != 0xc) && (iVar4 != 1)) {
      if (iVar4 == 2) {
        lVar7 = *(longlong *)(param_1 + 0x18);
        goto LAB_1400044d2;
      }
      if (iVar4 != 0xf) goto LAB_1400044d2;
      goto LAB_1400044b2;
    }
    lVar7 = *(longlong *)(param_1 + 0x28);
    if (lVar7 == 0) {
      return 0xc00000d0;
    }
    bVar10 = *(char *)(lVar7 + 5) == '\0';
  }
  if (bVar10) {
    return 0xc00000d0;
  }
LAB_1400044d2:
  uVar5 = (**(code **)(&BowserDatagramHandlerTable + (longlong)iVar4 * 8))
                    (lVar7,lVar6 + 1,(param_7 - 0x44) + (((int)param_10 + 0x43) - (int)lVar6),
                     param_9,local_res18,CONCAT44(uVar11,local_res10),param_10 + 0x34,
                     CONCAT44(uVar12,0x10),CONCAT44(uVar13,param_6));
  return uVar5;
}



===== BowserEnqueueMasterAnnouncement @ 14000453c =====

void BowserEnqueueMasterAnnouncement(longlong param_1)

{
  void *_Src;
  longlong lVar1;
  code *pcVar2;
  undefined1 uVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  size_t sVar7;
  size_t _Size;
  undefined1 *puVar8;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  _Src = *(void **)(param_1 + 0x28);
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x18);
  _Size = 0xffffffffffffffff;
  do {
    sVar7 = _Size;
    _Size = sVar7 + 1;
  } while (*(char *)(_Size + (longlong)_Src) != '\0');
  if (_Size != 0) {
    puVar4 = (undefined8 *)ExAllocatePool2(0x42,sVar7 + 0x12,0x6471424c);
    if (puVar4 != (undefined8 *)0x0) {
      memcpy(puVar4 + 2,_Src,_Size);
      *(undefined1 *)((longlong)puVar4 + sVar7 + 0x11) = 0;
      uVar3 = KeAcquireSpinLockRaiseToDpc(&BowserDatagramQueueSpinLock);
      puVar8 = auStack_28;
      plVar6 = (longlong *)(lVar1 + 0x3d8);
      if (*plVar6 == 0) {
        KeReleaseSpinLock(&BowserDatagramQueueSpinLock,
                          CONCAT71((int7)((ulonglong)plVar6 >> 8),uVar3));
        ExFreePoolWithTag(puVar4,0);
      }
      else {
        puVar5 = *(undefined8 **)(lVar1 + 0x3e0);
        if ((longlong *)*puVar5 != plVar6) {
          pcVar2 = (code *)swi(0x29);
          puVar5 = (undefined8 *)(*pcVar2)(3);
          puVar8 = auStack_20;
        }
        *puVar4 = plVar6;
        puVar4[1] = puVar5;
        *puVar5 = puVar4;
        plVar6[1] = (longlong)puVar4;
        *(int *)(lVar1 + 1000) = *(int *)(lVar1 + 1000) + 1;
        *(undefined8 *)(puVar8 + -8) = 0x140004628;
        KeReleaseSpinLock(&BowserDatagramQueueSpinLock,uVar3);
      }
    }
  }
  return;
}



===== BowserMasterAnnouncement @ 140004650 =====

undefined8
BowserMasterAnnouncement
          (longlong param_1,char *param_2,uint param_3,uint *param_4,void *param_5,uint param_6,
          void *param_7,uint param_8,uint param_9)

{
  uint uVar1;
  undefined8 uVar2;
  char *pcVar3;
  undefined8 in_stack_ffffffffffffffd0;
  
  uVar1 = 0;
  if (param_3 != 0) {
    pcVar3 = param_2;
    do {
      if (*pcVar3 == '\0') break;
      uVar1 = uVar1 + 1;
      pcVar3 = pcVar3 + 1;
    } while (uVar1 < param_3);
  }
  if (uVar1 == param_3) {
    uVar2 = 0xc00000d0;
  }
  else {
    uVar2 = BowserPostDatagramToWorkerThread
                      (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
                       BowserMasterAnnouncementWorker,in_stack_ffffffffffffffd0,1,param_9);
  }
  return uVar2;
}



===== BowserSendQueuedMasterAnnouncement @ 1400046dc =====

undefined8 BowserSendQueuedMasterAnnouncement(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  longlong lVar4;
  ushort uVar5;
  int iVar6;
  undefined8 uVar7;
  longlong lVar9;
  longlong lVar8;
  ulonglong local_28;
  void *pvStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  lVar1 = *(longlong *)(param_1 + 0x18);
  KeAcquireSpinLockRaiseToDpc(&BowserDatagramQueueSpinLock);
  plVar2 = (longlong *)*param_2;
  if (plVar2 == param_2) {
    KeReleaseSpinLock(&BowserDatagramQueueSpinLock);
    uVar7 = 0xc0000225;
  }
  else {
    if (((longlong *)plVar2[1] != param_2) || (lVar9 = *plVar2, *(longlong **)(lVar9 + 8) != plVar2)
       ) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3);
      pcVar3 = (code *)swi(3);
      uVar7 = (*pcVar3)();
      return uVar7;
    }
    *param_2 = lVar9;
    *(longlong **)(lVar9 + 8) = param_2;
    *(int *)(param_2 + 2) = (int)param_2[2] + -1;
    KeReleaseSpinLock(&BowserDatagramQueueSpinLock);
    lVar9 = -1;
    do {
      lVar8 = lVar9 + 1;
      lVar4 = lVar9 + 0x11;
      lVar9 = lVar8;
    } while (*(char *)((longlong)plVar2 + lVar4) != '\0');
    if ((ulonglong)(*(int *)(*(longlong *)(param_1 + 0xb8) + 8) - 0x3c) < lVar8 * 2 + 2U) {
      *(undefined8 *)(param_1 + 0x38) = 0;
    }
    else {
      local_18 = 0;
      uStack_10 = 0;
      local_28 = 0;
      pvStack_20 = (void *)0x0;
      RtlInitString(&local_18,plVar2 + 2);
      iVar6 = RtlOemStringToUnicodeString(&local_28,&local_18,1);
      if (-1 < iVar6) {
        uVar5 = (ushort)local_28;
        *(uint *)(lVar1 + 0x38) = (uint)(ushort)local_28;
        memcpy((void *)(lVar1 + 0x3c),pvStack_20,local_28 & 0xffff);
        *(undefined2 *)(lVar1 + 0x3c + (ulonglong)(uVar5 >> 1) * 2) = 0;
        *(ulonglong *)(param_1 + 0x38) = (ulonglong)((ushort)local_28 + 0x3c) + 2;
        RtlFreeUnicodeString(&local_28);
      }
    }
    ExFreePoolWithTag(plVar2,0);
    uVar7 = 0;
  }
  return uVar7;
}



===== BowserIsRemoteMailslotsDeprecated @ 140004864 =====

uint BowserIsRemoteMailslotsDeprecated(void)

{
  uint uVar1;
  
  if ((char)BowEnableMailslotsByPolicy != '\x02') {
    return ~-(uint)((char)BowEnableMailslotsByPolicy != '\0') & 0xc05d0005;
  }
  uVar1 = 0;
  if (BowEnableMailslots == '\0') {
    uVar1 = 0xc05d0005;
  }
  return uVar1;
}



===== BowserWriteGetBrowserListThresholdExceededEvent @ 140004898 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void BowserWriteGetBrowserListThresholdExceededEvent(void)

{
  longlong in_stack_fffffffffffffff0;
  
  if (1199999999 <
      (_DAT_fffff78000000320 - _BowserLastGetBrowserListDatagramsEvent) *
      (ulonglong)BowserTimeIncrement) {
    _BowserLastGetBrowserListDatagramsEvent = _DAT_fffff78000000320;
    BowserWriteErrorLogEntry(0x40001f5f,0xc000009a,(void *)0x0,0,0,in_stack_fffffffffffffff0);
  }
  return;
}



===== BowserWriteMailslotDatagramThresholdExceededEvent @ 1400048f8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void BowserWriteMailslotDatagramThresholdExceededEvent(void)

{
  longlong in_stack_fffffffffffffff0;
  
  if (1199999999 <
      (_DAT_fffff78000000320 - _BowserLastMissedMailslotDatagramsEvent) *
      (ulonglong)BowserTimeIncrement) {
    _BowserLastMissedMailslotDatagramsEvent = _DAT_fffff78000000320;
    BowserWriteErrorLogEntry(0x40001f5e,0xc000009a,(void *)0x0,0,0,in_stack_fffffffffffffff0);
  }
  return;
}



===== Feature_Servicing_UMABowserRdbss__private_IsEnabledDeviceUsageNoInline @ 140004958 =====

ulonglong Feature_Servicing_UMABowserRdbss__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  undefined4 *local_res8;
  
  local_res8 = (undefined4 *)(ulonglong)Feature_Servicing_UMABowserRdbss__private_featureState;
  if ((Feature_Servicing_UMABowserRdbss__private_featureState & 0x10) == 0) {
    uVar1 = Feature_Servicing_UMABowserRdbss__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_Servicing_UMABowserRdbss__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_Servicing_UMABowserRdbss__private_IsEnabledFallback @ 140004990 =====

void Feature_Servicing_UMABowserRdbss__private_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2);
  return;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 1400049a8 =====

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



===== wil_details_FeatureReporting_IncrementUsageInCache @ 140004a80 =====

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



===== wil_details_FeatureReporting_RecordUsageInCache @ 140004b64 =====

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
LAB_140004cbc:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_140004caf:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_140004cbc;
      if (uVar5 == 5) goto LAB_140004caf;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 140004ce4 =====

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
              (0x35cd066,&Feature_UxPerfImp_logged_traits,0,uVar4,local_res18,0,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140004d60 =====

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
                     (local_50,(uint *)&Feature_Servicing_UMABowserRdbss__private_reporting,param_3,
                      (uint)((ulonglong)param_2 >> 0x20));
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_68 = &local_38;
    (*g_wil_details_recordFeatureUsage)
              (0x35cd066,param_3 & 0xffffffff,1,&Feature_Servicing_UMABowserRdbss__private_reporting
              );
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && ((int)param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)(param_3 & 0xffffffff),0x35cd066);
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 140004e4c =====

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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140004f5c =====

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
  if ((Feature_Servicing_UMABowserRdbss__private_featureState & 2) != 0) {
    uVar1 = Feature_Servicing_UMABowserRdbss__private_featureState;
    while ((uVar1 & 1) == (param_1 & 1)) {
      LOCK();
      bVar3 = uVar1 == Feature_Servicing_UMABowserRdbss__private_featureState;
      if (bVar3) {
        Feature_Servicing_UMABowserRdbss__private_featureState = uVar2 | uVar1;
      }
      else {
        uVar1 = Feature_Servicing_UMABowserRdbss__private_featureState;
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



===== wil_details_GetCurrentFeatureEnabledState @ 140004fb0 =====

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



===== wil_details_IsEnabledFallback @ 140005110 =====

uint wil_details_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  ulonglong local_res18;
  
  local_res18 = (ulonglong)param_1 & 0xffffffff;
  if (((ulonglong)param_1 & 2) == 0) {
    puVar1 = &Feature_Servicing_UMABowserRdbss__private_featureState;
    local_res18 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            (&Feature_Servicing_UMABowserRdbss__private_featureState,
                             (ulonglong)param_1,0x14000c1a0);
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



===== wil_details_MapReportingKind @ 1400051a0 =====

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



===== BowserDeactivateScavengerTimer @ 140005240 =====

void BowserDeactivateScavengerTimer(void)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(&BowserTimeSpinLock);
  BowserScavengerReferenceCount = BowserScavengerReferenceCount + -1;
  if (BowserScavengerReferenceCount == 0) {
    KeCancelTimer(&BowserScavengerTimer);
  }
  KeReleaseSpinLock(&BowserTimeSpinLock,uVar1);
  return;
}



===== IsSuiteVersion @ 14000529c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint IsSuiteVersion(void)

{
  uint uVar1;
  undefined8 uVar2;
  undefined1 auStack_158 [32];
  undefined4 local_138 [70];
  undefined2 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_158;
  memset(local_138,0,0x11c);
  local_138[0] = 0x11c;
  local_20 = 0x200;
  uVar2 = VerSetConditionMask(0,0x40,7);
  uVar1 = RtlVerifyVersionInfo(local_138,0x40,uVar2);
  return ~uVar1 >> 0x1f;
}



===== RtlStringCbPrintfW @ 140005330 =====

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



===== wil_details_FeatureDescriptors_SkipPadding @ 1400053ac =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_14000c247 < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_RecordCachedUsage @ 1400053d4 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140005530 =====

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



===== BowserHandleShortBrowserPacket @ 1400055b4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
BowserHandleShortBrowserPacket
          (longlong param_1,undefined8 param_2,uint param_3,void *param_4,uint param_5,
          undefined1 *param_6,uint param_7,uint param_8,undefined4 *param_9,longlong *param_10,
          undefined8 param_11)

{
  char *pcVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  undefined1 *puVar4;
  undefined1 uVar5;
  uint uVar6;
  undefined8 *puVar7;
  longlong lVar8;
  undefined8 uVar9;
  undefined1 *_Dst;
  size_t _Size;
  size_t _Size_00;
  undefined8 *_Dst_00;
  longlong lVar10;
  undefined8 uVar11;
  
  lVar8 = *(longlong *)(param_1 + 0x18);
  _Size = (size_t)(int)param_3;
  if (param_3 <= param_3 + 0x48) {
    _Size_00 = (size_t)(int)param_5;
    uVar6 = param_3 + 0x48 + param_5;
    if (((param_5 <= uVar6) && (uVar6 = uVar6 + param_8, param_8 <= uVar6)) &&
       (puVar7 = (undefined8 *)ExAllocatePool2(0x42,uVar6,0x6373424c), puVar7 != (undefined8 *)0x0))
    {
      puVar7[4] = _Size + 0x40 + (longlong)puVar7;
      _Dst_00 = puVar7 + 8;
      puVar7[2] = _Dst_00;
      puVar7[6] = _Size_00 + 0x40 + _Size + (longlong)puVar7;
      if ((param_7 & 0x200) == 0) {
        puVar3 = (undefined8 *)(_Size + (longlong)_Dst_00);
        if (_Dst_00 < puVar3) {
          lVar10 = (longlong)param_4 - (longlong)_Dst_00;
          do {
            *(undefined1 *)_Dst_00 = *(undefined1 *)(lVar10 + (longlong)_Dst_00);
            _Dst_00 = (undefined8 *)((longlong)_Dst_00 + 1);
          } while (_Dst_00 < puVar3);
        }
      }
      else {
        memcpy(_Dst_00,param_4,_Size);
      }
      _Dst = (undefined1 *)puVar7[4];
      *(uint *)(puVar7 + 1) = param_3;
      if ((param_7 & 0x200) == 0) {
        puVar4 = _Dst + _Size_00;
        for (; _Dst < puVar4; _Dst = _Dst + 1) {
          uVar5 = *param_6;
          param_6 = param_6 + 1;
          *_Dst = uVar5;
        }
      }
      else {
        memcpy(_Dst,param_6,_Size_00);
      }
      *(uint *)(puVar7 + 5) = param_7;
      *puVar7 = param_2;
      puVar7[7] = param_11;
      *(uint *)(puVar7 + 3) = param_5;
      lVar10 = *(longlong *)(param_1 + 0x28);
      if (lVar10 == 0) {
        lVar10 = *(longlong *)(lVar8 + 0x50);
        uVar11 = *(undefined8 *)(lVar8 + 0x48);
      }
      else {
        uVar11 = *(undefined8 *)(param_1 + 0x20);
      }
      lVar8 = IoAllocateIrp(*(undefined1 *)(lVar10 + 0x4c),0);
      *param_10 = lVar8;
      if (lVar8 != 0) {
        uVar9 = IoAllocateMdl(puVar7[6],param_8,0,0,0);
        *(undefined8 *)(*param_10 + 8) = uVar9;
        if (*(longlong *)(*param_10 + 8) != 0) {
          MmBuildMdlForNonPagedPool(*(longlong *)(*param_10 + 8));
          lVar8 = *(longlong *)(*param_10 + 0xb8);
          *(code **)(lVar8 + -0x10) = CompleteShortBrowserPacket;
          *(undefined8 **)(lVar8 + -8) = puVar7;
          *(undefined1 *)(lVar8 + -0x45) = 0xe0;
          lVar8 = *(longlong *)(*param_10 + 0xb8);
          *(undefined2 *)(lVar8 + -0x48) = 0xa0f;
          *(longlong *)(lVar8 + -0x20) = lVar10;
          *(undefined8 *)(lVar8 + -0x18) = uVar11;
          *(uint *)(lVar8 + -0x40) = param_8;
          *(undefined8 *)(lVar8 + -0x38) = 0;
          *(undefined8 *)(lVar8 + -0x30) = 0;
          *(undefined4 *)(lVar8 + -0x28) = 0;
          lVar8 = *param_10;
          pcVar1 = (char *)(lVar8 + 0x43);
          *pcVar1 = *pcVar1 + -1;
          plVar2 = (longlong *)(lVar8 + 0xb8);
          *plVar2 = *plVar2 + -0x48;
          *param_9 = 0;
          return 0xc0000016;
        }
        IoFreeIrp();
      }
      ExFreePoolWithTag(puVar7,0);
      _DAT_14000d2e8 = _DAT_14000d2e8 + 1;
    }
  }
  return 0xc00000d0;
}



===== BowserLogIllegalDatagram @ 140005814 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void BowserLogIllegalDatagram
               (longlong param_1,longlong param_2,ushort param_3,void *param_4,uint param_5)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  undefined8 *puVar3;
  undefined1 *puVar4;
  longlong lVar5;
  int iVar6;
  
  iVar6 = 0;
  LOCK();
  _DAT_14000d2f8 = _DAT_14000d2f8 + 1;
  UNLOCK();
  uVar2 = KeAcquireSpinLockRaiseToDpc(&BowserTimeSpinLock);
  if (1199999999 <
      (_DAT_fffff78000000320 - _BowserLastIllegalDatagramEvent) * (ulonglong)BowserTimeIncrement) {
    _BowserLastIllegalDatagramEvent = _DAT_fffff78000000320;
    BowserIllegalDatagramCount = DAT_14000d29c;
    BowserIllegalDatagramThreshold = '\0';
  }
  if (BowserIllegalDatagramCount < 1) {
    if (BowserIllegalDatagramThreshold == '\0') {
      BowserIllegalDatagramThreshold = '\x01';
      iVar6 = -0x3fffe0b0;
    }
  }
  else {
    BowserIllegalDatagramCount = BowserIllegalDatagramCount + -1;
    iVar6 = -0x7fffe0ba;
  }
  KeReleaseSpinLock(&BowserTimeSpinLock,uVar2);
  if (iVar6 != 0) {
    puVar3 = (undefined8 *)ExAllocatePool2(0x42,(ulonglong)param_3 + 0x40,0x6469424c);
    if (puVar3 != (undefined8 *)0x0) {
      *(int *)(puVar3 + 5) = iVar6;
      puVar3[4] = param_1;
      LOCK();
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      UNLOCK();
      puVar4 = (undefined1 *)((longlong)puVar3 + 0x3e);
      *(ushort *)((longlong)puVar3 + 0x2c) = param_3;
      puVar1 = puVar4 + param_3;
      if (puVar4 < puVar1) {
        lVar5 = param_2 - (longlong)puVar4;
        do {
          *puVar4 = puVar4[lVar5];
          puVar4 = puVar4 + 1;
        } while (puVar4 < puVar1);
      }
      BowserCopyOemComputerName((undefined1 *)((longlong)puVar3 + 0x2e),param_4,0x10,param_5);
      *puVar3 = 0;
      puVar3[2] = BowserLogIllegalDatagramWorker;
      puVar3[3] = puVar3;
      BowserQueueDelayedWorkItem(puVar3);
    }
  }
  return;
}



===== CompleteReceiveMailslot @ 1400059a0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 CompleteReceiveMailslot(undefined8 param_1,longlong param_2,longlong param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0x30);
  *(undefined4 *)(param_3 + 0x58) = *(undefined4 *)(param_2 + 0x38);
  IoFreeMdl(*(undefined8 *)(param_2 + 8));
  IoFreeIrp(param_2);
  if (iVar1 < 0) {
    _DAT_14000d2e8 = _DAT_14000d2e8 + 1;
    BowserFreeMailslotBufferHighIrql(param_3);
  }
  else {
    *(undefined8 *)(param_3 + 8) = 0;
    *(code **)(param_3 + 0x18) = BowserProcessMailslotWrite;
    *(longlong *)(param_3 + 0x20) = param_3;
    BowserQueueDelayedWorkItem((undefined8 *)(param_3 + 8));
  }
  return 0xc0000016;
}



===== CompleteShortBrowserPacket @ 140005a30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 CompleteShortBrowserPacket(undefined8 param_1,longlong param_2,undefined8 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  longlong local_res10;
  undefined4 local_res18 [2];
  
  iVar1 = *(int *)(param_2 + 0x30);
  local_res18[0] = 0;
  uVar2 = *(undefined4 *)(param_2 + 0x38);
  local_res10 = param_2;
  IoFreeMdl(*(undefined8 *)(param_2 + 8));
  IoFreeIrp(local_res10);
  if (-1 < iVar1) {
    (*(code *)param_3[7])
              (*param_3,*(undefined4 *)(param_3 + 1),param_3[2],*(undefined4 *)(param_3 + 3),
               param_3[4],*(undefined4 *)(param_3 + 5),uVar2,uVar2,local_res18,param_3[6],
               &local_res10);
  }
  ExFreePoolWithTag(param_3,0);
  return 0xc0000016;
}



===== BowUnregisterTelemetryProvider @ 140005af4 =====

void BowUnregisterTelemetryProvider(void)

{
  undefined8 uVar1;
  
  uVar1 = DAT_14000d110;
  DAT_14000d110 = 0;
  DAT_14000d0f0 = 0;
  EtwUnregister(uVar1);
  return;
}



===== BowWriteTelemetryCanonicalizeNameFailure @ 140005b28 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void BowWriteTelemetryCanonicalizeNameFailure(wchar_t *param_1,int param_2,undefined8 param_3)

{
  ulonglong uVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined1 auStackY_98 [32];
  longlong local_68 [2];
  undefined8 local_58 [4];
  longlong local_38 [2];
  longlong *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  lVar3 = (longlong)param_2;
  if (5 < DAT_14000d0f0) {
    uVar1 = _tlgKeywordOn();
    if ((char)uVar1 != '\0') {
      plVar2 = local_38;
      _tlgCreate1Sz_wchar_t(plVar2,param_1);
      local_1c = 0;
      local_28 = local_68;
      local_20 = 8;
      local_68[0] = lVar3;
      _tlgWriteTransfer_EtwWriteTransfer(plVar2,&DAT_140009b21,param_3,lVar3,4,local_58);
    }
  }
  return;
}



===== BowWriteTelemetryMailslotProcessing4 @ 140005bbc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void BowWriteTelemetryMailslotProcessing4(undefined8 param_1,ushort *param_2,undefined8 param_3)

{
  ulonglong uVar1;
  undefined1 auStackY_98 [32];
  undefined8 local_68 [4];
  longlong local_48 [2];
  uint *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  uint local_20 [2];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  if (5 < DAT_14000d0f0) {
    uVar1 = _tlgKeywordOn();
    if ((char)uVar1 != '\0') {
      _tlgCreate1Sz_wchar_t(local_48,L"BowserProcessMailslotWrite");
      local_28 = *(undefined8 *)(param_2 + 4);
      local_38 = local_20;
      local_2c = 0;
      local_20[1] = 0;
      local_20[0] = (uint)*param_2;
      local_30 = 2;
      _tlgWriteTransfer_EtwWriteTransfer(local_38,&DAT_140009b60,param_3,param_2,5,local_68);
    }
  }
  return;
}



===== _tlgDefineProvider_annotation__TlgBowserTelemetryProviderProv @ 140005c68 =====

void _tlgDefineProvider_annotation__TlgBowserTelemetryProviderProv(void)

{
  return;
}



===== __GSHandlerCheck @ 140005c78 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140005c9c =====

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



===== __GSHandlerCheck_SEH @ 140005d04 =====

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



===== __security_check_cookie @ 140005da0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== RtlpCopyDeviceMemory @ 140005dd0 =====

void * __cdecl RtlpCopyDeviceMemory(void *_Dst,void *_Src,size_t _Size)

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



===== RtlMoveVolatileMemory @ 140005de0 =====

void * __cdecl RtlMoveVolatileMemory(void *_Dst,void *_Src,size_t _Size)

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



===== RtlSetVolatileMemory @ 140005df0 =====

void * __cdecl RtlSetVolatileMemory(void *_Dst,int _Val,size_t _Size)

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



===== _guard_dispatch_icall @ 140005e20 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140005e20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140005e50 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140005e80 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 140005f00 =====

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



===== memset @ 140006200 =====

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



===== __memset_repmovs @ 140006340 =====

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



===== __memset_query @ 1400063c0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140006440 =====

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



===== __memset_spec_ermsb_repmovsb @ 140006580 =====

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



===== __memset_spec_plain @ 140006600 =====

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



===== BowserBuildAnnounceSecurityDescriptor @ 140007008 =====

int BowserBuildAnnounceSecurityDescriptor(longlong *param_1)

{
  undefined8 uVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong lVar6;
  undefined4 local_res10 [2];
  
  local_res10[0] = 0x100003;
  uVar4 = IoGetFileObjectGenericMapping();
  RtlMapGenericMask(local_res10,uVar4);
  uVar4 = *(undefined8 *)(*(longlong *)SeExports_exref + 0x108);
  uVar1 = *(undefined8 *)(*(longlong *)SeExports_exref + 0x180);
  iVar2 = RtlLengthSid(uVar4);
  iVar3 = RtlLengthSid(uVar1);
  iVar2 = iVar3 + 0x18 + iVar2;
  lVar5 = ExAllocatePool2(0x102,iVar2,0x73654c42);
  if (lVar5 == 0) {
    iVar2 = -0x3fffff66;
  }
  else {
    iVar2 = RtlCreateAcl(lVar5,iVar2,2);
    if (-1 < iVar2) {
      RtlAddAccessAllowedAce(lVar5,2,local_res10[0],uVar1);
      RtlAddAccessAllowedAce(lVar5,2,local_res10[0],uVar4);
      lVar6 = ExAllocatePool2(0x102,0x28,0x73654c42);
      if (lVar6 != 0) {
        RtlCreateSecurityDescriptor(lVar6,1);
        RtlSetDaclSecurityDescriptor(lVar6,1,lVar5,0);
        *param_1 = lVar6;
        return 0;
      }
      iVar2 = -0x3fffff66;
    }
    ExFreePoolWithTag(lVar5,0);
  }
  return iVar2;
}



===== BowserBuildDeviceAcl @ 14000718c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int BowserBuildDeviceAcl(longlong *param_1)

{
  undefined8 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  longlong lVar6;
  undefined4 *puVar7;
  longlong lVar8;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined4 local_44;
  undefined2 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_68;
  local_44 = 0;
  local_48 = 0x10000000;
  local_40 = 0x500;
  uVar5 = IoGetFileObjectGenericMapping();
  RtlMapGenericMask(&local_48,uVar5);
  uVar5 = *(undefined8 *)(*(longlong *)SeExports_exref + 0x110);
  uVar1 = *(undefined8 *)(*(longlong *)SeExports_exref + 0x108);
  iVar2 = RtlLengthRequiredSid(6);
  lVar6 = ExAllocatePool2(0x102,iVar2,0x73654c42);
  if (lVar6 == 0) {
    iVar2 = -0x3fffff66;
  }
  else {
    RtlInitializeSid(lVar6,&local_44,6);
    puVar7 = (undefined4 *)RtlSubAuthoritySid(lVar6,0);
    *puVar7 = 0x50;
    puVar7 = (undefined4 *)RtlSubAuthoritySid(lVar6,1);
    *puVar7 = 0x2aea4d57;
    puVar7 = (undefined4 *)RtlSubAuthoritySid(lVar6,2);
    *puVar7 = 0xa8e6d4cb;
    puVar7 = (undefined4 *)RtlSubAuthoritySid(lVar6,3);
    *puVar7 = 0x5d63bd2f;
    puVar7 = (undefined4 *)RtlSubAuthoritySid(lVar6,4);
    *puVar7 = 0xf4049bf1;
    puVar7 = (undefined4 *)RtlSubAuthoritySid(lVar6,5);
    *puVar7 = 0x54485448;
    iVar3 = RtlLengthSid(uVar1);
    iVar4 = RtlLengthSid(uVar5);
    iVar2 = iVar2 + iVar3 + iVar4 + 0x20;
    lVar8 = ExAllocatePool2(0x102,iVar2,0x73654c42);
    if (lVar8 == 0) {
      iVar2 = -0x3fffff66;
    }
    else {
      iVar2 = RtlCreateAcl(lVar8,iVar2,2);
      if (iVar2 < 0) {
        ExFreePoolWithTag(lVar8,0);
      }
      else {
        RtlAddAccessAllowedAce(lVar8,2,local_48,uVar5);
        RtlAddAccessAllowedAce(lVar8,2,local_48,uVar1);
        RtlAddAccessAllowedAce(lVar8,2,local_48,lVar6);
        iVar2 = 0;
        *param_1 = lVar8;
      }
    }
    ExFreePoolWithTag(lVar6,0);
  }
  return iVar2;
}



===== BowserCreateAdminSecurityDescriptor @ 1400073fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong BowserCreateAdminSecurityDescriptor(undefined8 param_1)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  void *_Dst;
  undefined1 auStack_88 [32];
  undefined4 local_68;
  undefined8 local_60;
  undefined1 local_58 [8];
  void *local_50;
  longlong local_48;
  undefined4 local_40 [2];
  undefined1 local_38 [40];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_88;
  local_48 = 0;
  local_50 = (void *)0x0;
  local_58[0] = 0;
  local_40[0] = 4;
  uVar3 = ObGetObjectSecurity(param_1,&local_50,local_58);
  if (-1 < (int)uVar3) {
    uVar1 = BowserBuildDeviceAcl(&local_48);
    if (-1 < (int)uVar1) {
      RtlCreateSecurityDescriptor(local_38,1);
      RtlSetDaclSecurityDescriptor(local_38,1,local_48,0);
      uVar2 = RtlLengthSecurityDescriptor(local_50);
      _Dst = (void *)ExAllocatePool2(0x102,uVar2,0x73654c42);
      if (_Dst != (void *)0x0) {
        memcpy(_Dst,local_50,(ulonglong)uVar2);
        g_pBowSecurityDescriptor = _Dst;
        local_60 = IoGetFileObjectGenericMapping();
        local_68 = 1;
        uVar1 = SeSetSecurityDescriptorInfo(0,local_40,local_38,&g_pBowSecurityDescriptor);
        if ((int)uVar1 < 0) {
          ExFreePoolWithTag(g_pBowSecurityDescriptor,0);
          g_pBowSecurityDescriptor = (void *)0x0;
        }
        else {
          if (g_pBowSecurityDescriptor != _Dst) {
            ExFreePoolWithTag(_Dst,0);
          }
          uVar1 = 0;
        }
      }
    }
    ObReleaseObjectSecurity(local_50,local_58[0]);
    if (local_48 != 0) {
      ExFreePoolWithTag(local_48,0);
    }
    uVar3 = (ulonglong)uVar1;
  }
  return uVar3;
}



===== BowserSecurityCheck @ 1400075c0 =====

undefined1 BowserSecurityCheck(longlong param_1,longlong param_2,undefined8 param_3)

{
  undefined1 uVar1;
  undefined8 uVar2;
  undefined4 local_res10 [4];
  undefined4 local_res20 [2];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_res10[0] = 0x10000000;
  local_res20[0] = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  SeCaptureSubjectContext(&local_38);
  SeLockSubjectContext(&local_38);
  uVar2 = IoGetFileObjectGenericMapping();
  RtlMapGenericMask(local_res10,uVar2);
  if ((*(byte *)(param_2 + 2) & 1) == 0) {
    uVar1 = *(undefined1 *)(param_1 + 0x40);
  }
  else {
    uVar1 = 1;
  }
  uVar2 = IoGetFileObjectGenericMapping();
  uVar1 = SeAccessCheck(g_pBowSecurityDescriptor,&local_38,1,local_res10[0],0,0,uVar2,uVar1,
                        local_res20,param_3);
  SeUnlockSubjectContext(&local_38);
  SeReleaseSubjectContext(&local_38);
  return uVar1;
}



===== memset$thunk$772440563353939046 @ 140008030 =====

void * __cdecl memset_thunk_772440563353939046(void *_Dst,int _Val,size_t _Size)

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



===== BowserLoseElection @ 140012008 =====

void BowserLoseElection(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined7 uVar4;
  
  lVar1 = *(longlong *)(param_1 + 8);
  uVar3 = CONCAT71((int7)((ulonglong)param_2 >> 8),1);
  ExAcquireResourceExclusiveLite(param_1 + 0xd0,uVar3);
  BowserStopTimer(param_1 + 0x138);
  uVar2 = BowserTimeUp();
  *(int *)(lVar1 + 0x110) = (int)uVar2;
  *(undefined4 *)(param_1 + 0x60) = 0;
  if (*(int *)(lVar1 + 0xf8) == 3) {
    uVar4 = (undefined7)((ulonglong)uVar3 >> 8);
    BowserResetStateForTransport(param_1,1);
    ExAcquireResourceExclusiveLite(param_1 + 0x68,CONCAT71(uVar4,1));
    BowserForEachTransportName(param_1,BowserStopProcessingAnnouncements,0);
    BowserDeleteGenericTable(lVar1 + 0x48);
    BowserDeleteGenericTable(lVar1 + 0x90);
    ExReleaseResourceLite(param_1 + 0x68);
  }
  ExReleaseResourceLite(param_1 + 0xd0);
  return;
}



===== BowserCommonQueryInformationFile @ 1400120e0 =====

undefined8 BowserCommonQueryInformationFile(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  *(undefined8 *)(param_3 + 0x38) = 0;
  *(undefined4 *)(param_3 + 0x30) = 0xc0000002;
  IofCompleteRequest(param_3,0);
  return 0xc0000002;
}



===== RtlWriteULongToUser @ 140012114 =====

/* WARNING: Removing unreachable block (ram,0x00014001212f) */

void RtlWriteULongToUser(undefined4 *param_1,undefined4 param_2)

{
  ProbeForRead(param_1,4,1);
  *param_1 = param_2;
  return;
}



===== BowserPromoteToBackup @ 140012158 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void BowserPromoteToBackup(longlong param_1)

{
  int iVar1;
  undefined1 auStackY_88 [32];
  undefined8 local_48;
  void *pvStack_40;
  undefined8 local_38;
  undefined1 *puStack_30;
  char local_28;
  undefined1 local_27 [23];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_88;
  local_28 = '\v';
  local_48 = 0;
  pvStack_40 = (void *)0x0;
  local_38 = 0;
  puStack_30 = (undefined1 *)0x0;
  RtlInitUnicodeString(&local_48);
  puStack_30 = local_27;
  local_38._0_4_ = CONCAT22(0x11,(ushort)local_38);
  iVar1 = RtlUnicodeStringToOemString(&local_38,&local_48,0);
  if (iVar1 < 0) {
    BowserLogIllegalName(iVar1,pvStack_40,(ushort)local_48);
  }
  else {
    BowserSendSecondClassMailslot
              (param_1,0,7,&local_28,(ushort)local_38 + 2,'\x01',"\\MAILSLOT\\BROWSE",(ushort *)0x0)
    ;
  }
  return;
}



===== BowserShutdownRemoteBrowser @ 140012234 =====

void BowserShutdownRemoteBrowser(longlong param_1)

{
  char local_res18 [16];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_18);
  local_res18[0] = '\x0e';
  local_res18[1] = '\x02';
  BowserSendSecondClassMailslot
            (param_1,(longlong)&local_18,1,local_res18,2,'\x01',"\\MAILSLOT\\BROWSE",(ushort *)0x0);
  return;
}



===== PackServerAnnouncement @ 1400122a4 =====

ulonglong PackServerAnnouncement
                    (uint param_1,int param_2,ulonglong *param_3,ulonglong *param_4,longlong param_5
                    ,longlong param_6,int *param_7)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  ulonglong uVar4;
  ushort *puVar5;
  undefined8 local_38;
  ulonglong uStack_30;
  undefined8 local_28;
  ulonglong uStack_20;
  
  piVar1 = (int *)*param_3;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  uVar2 = param_1 - 100;
  uVar4 = (ulonglong)uVar2;
  if (uVar2 == 0) {
    uVar2 = 0x10;
  }
  else {
    if (uVar2 != 1) goto LAB_140012429;
    uVar2 = param_1 - 0x3d;
  }
  *param_3 = (ulonglong)uVar2 + (longlong)piVar1;
  RtlInitUnicodeString(&local_38,param_6 + 0x2a);
  RtlInitUnicodeString(&local_28,param_6 + 0x5c);
  iVar3 = (ushort)local_38 + 2 + *param_7 + uVar2;
  *param_7 = iVar3;
  if (param_1 == 0x65) {
    iVar3 = (ushort)local_28 + 2 + iVar3;
    *param_7 = iVar3;
    if (param_2 == 0x20000) {
      *param_7 = iVar3 + 2;
    }
  }
  uVar4 = *param_4;
  if (*param_3 < uVar4) {
    *piVar1 = (-(uint)((*(uint *)(param_6 + 0x4c) & 0x1000) != 0) & 100) + 400;
    *(ulonglong *)(piVar1 + 2) = uStack_30;
    uVar2 = BowserPackUnicodeString
                      ((ulonglong *)(piVar1 + 2),(uint)(ushort)local_38,param_5,*param_3,param_4);
    uVar4 = CONCAT44(extraout_var,uVar2);
    if (uVar2 != 0) {
      if (100 < param_1) {
        piVar1[4] = (uint)*(byte *)(param_6 + 0x50);
        piVar1[5] = (uint)*(byte *)(param_6 + 0x51);
        piVar1[6] = *(int *)(param_6 + 0x4c);
        *(ulonglong *)(piVar1 + 8) = uStack_20;
        uVar2 = BowserPackUnicodeString
                          ((ulonglong *)(piVar1 + 8),(uint)(ushort)local_28,param_5,*param_3,param_4
                          );
        uVar4 = CONCAT44(extraout_var_00,uVar2);
        if (uVar2 == 0) goto LAB_140012429;
        if (param_2 == 0x20000) {
          uVar4 = (longlong)(*param_4 - *param_3) >> 1;
          if (uVar4 < 3) goto LAB_140012429;
          puVar5 = (ushort *)(*param_4 - 2);
          *param_4 = (ulonglong)puVar5;
          uVar4 = (ulonglong)*(ushort *)(param_6 + 0x28);
          *puVar5 = *(ushort *)(param_6 + 0x28);
        }
      }
      return CONCAT71((int7)(uVar4 >> 8),1);
    }
  }
LAB_140012429:
  return uVar4 & 0xffffffffffffff00;
}



===== BowserMasterAnnouncementWorker @ 140012460 =====

void BowserMasterAnnouncementWorker(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  ushort uVar4;
  uint uVar5;
  longlong lVar6;
  longlong lVar7;
  ulonglong local_38;
  void *pvStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  lVar1 = *(longlong *)(param_1 + 0x28);
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x18);
  lVar6 = BowserDequeueQueuedIrp((longlong *)(lVar2 + 0x3a8),'\0');
  if (lVar6 == 0) {
    BowserEnqueueMasterAnnouncement(param_1);
    goto LAB_1400125a5;
  }
  lVar3 = *(longlong *)(lVar6 + 0x18);
  lVar7 = -1;
  do {
    lVar7 = lVar7 + 1;
  } while (*(char *)(lVar1 + lVar7) != '\0');
  if (lVar7 == 0) {
    *(undefined8 *)(lVar6 + 0x38) = 0;
LAB_140012575:
    uVar5 = 0;
  }
  else if ((ulonglong)(*(int *)(*(longlong *)(lVar6 + 0xb8) + 8) - 0x3c) < lVar7 * 2 + 2U) {
    *(undefined8 *)(lVar6 + 0x38) = 0;
    uVar5 = 0xc0000023;
  }
  else {
    local_28 = 0;
    uStack_20 = 0;
    local_38 = 0;
    pvStack_30 = (void *)0x0;
    RtlInitString(&local_28,lVar1);
    uVar5 = RtlOemStringToUnicodeString(&local_38,&local_28,1);
    if (-1 < (int)uVar5) {
      uVar4 = (ushort)local_38;
      *(uint *)(lVar3 + 0x38) = (uint)(ushort)local_38;
      memcpy((void *)(lVar3 + 0x3c),pvStack_30,local_38 & 0xffff);
      *(undefined2 *)(lVar3 + 0x3c + (ulonglong)(uVar4 >> 1) * 2) = 0;
      *(ulonglong *)(lVar6 + 0x38) = (ulonglong)((ushort)local_38 + 0x3c) + 2;
      RtlFreeUnicodeString(&local_38);
      goto LAB_140012575;
    }
  }
  *(uint *)(lVar6 + 0x30) = uVar5;
  if ((uVar5 & 0xc0000000) == 0xc0000000) {
    *(undefined8 *)(lVar6 + 0x38) = 0;
  }
  IofCompleteRequest(lVar6,0);
LAB_1400125a5:
  BowserDereferenceTransportName(*(longlong *)(param_1 + 0x20));
  BowserDereferenceTransport(lVar2);
  LOCK();
  BowserPostedDatagramCount = BowserPostedDatagramCount + -1;
  UNLOCK();
  ExFreePoolWithTag(param_1,0);
  return;
}



===== BowserDeleteDefaultDomainNames @ 1400125f0 =====

undefined8 BowserDeleteDefaultDomainNames(longlong param_1,short *param_2)

{
  BowserDeleteTransportNameByName(param_1,param_2,2);
  BowserDeleteTransportNameByName(param_1,param_2,9);
  return 0;
}



===== BowserDeleteNameByName @ 140012630 =====

undefined4 BowserDeleteNameByName(longlong param_1,byte *param_2,int param_3)

{
  undefined4 uVar1;
  undefined8 *puVar2;
  
  puVar2 = (undefined8 *)0x0;
  if (((param_2 == (byte *)0x0) || (*(short *)param_2 == 0)) ||
     (puVar2 = BowserFindName(param_2,param_3), puVar2 != (undefined8 *)0x0)) {
    uVar1 = BowserDeleteNamesInDomain(param_1,(undefined8 *)param_2,param_3);
    if (puVar2 != (undefined8 *)0x0) {
      BowserDereferenceName((longlong)puVar2);
    }
  }
  else {
    uVar1 = 0xc0000034;
  }
  return uVar1;
}



===== BowserDeleteNamesInDomain @ 1400126c0 =====

void BowserDeleteNamesInDomain(longlong param_1,undefined8 *param_2,undefined4 param_3)

{
  undefined1 local_48 [40];
  undefined8 local_20;
  undefined8 uStack_18;
  undefined4 local_10;
  
  memset(local_48,0,0x40);
  local_20 = *param_2;
  uStack_18 = param_2[1];
  local_10 = param_3;
  BowserForEachTransportInDomain(param_1,BowserDeleteNamesWorker,local_48);
  return;
}



===== BowserDeleteNamesWorker @ 140012720 =====

void BowserDeleteNamesWorker(longlong param_1,longlong param_2)

{
  BowserDeleteTransportNameByName(param_1,(short *)(param_2 + 0x28),*(int *)(param_2 + 0x38));
  return;
}



===== BowserDeleteTransportNameByName @ 140012740 =====

int BowserDeleteTransportNameByName(longlong param_1,short *param_2,int param_3)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  code *pcVar5;
  char cVar6;
  int iVar7;
  ulonglong uVar8;
  undefined8 *puVar9;
  undefined1 *puVar10;
  undefined8 uStack_50;
  undefined1 auStack_48 [32];
  int local_28 [4];
  
  iVar7 = 0;
  ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
  puVar10 = auStack_48;
  puVar9 = *(undefined8 **)(*(longlong *)(param_1 + 8) + 0x20);
  do {
    while( true ) {
      if (puVar9 == (undefined8 *)(*(longlong *)(param_1 + 8) + 0x20)) goto LAB_14001281a;
      lVar1 = puVar9[-2];
      if (*(char *)(lVar1 + 4) == param_3) break;
LAB_14001280d:
      puVar9 = (undefined8 *)*puVar9;
    }
    if ((param_2 != (short *)0x0) && (*param_2 != 0)) {
      lVar2 = puVar9[-1];
      *(undefined8 *)(puVar10 + -8) = 0x1400127c7;
      cVar6 = RtlEqualUnicodeString(lVar2 + 0x28,param_2,1);
      if (cVar6 == '\0') goto LAB_14001280d;
    }
    puVar3 = (undefined8 *)*puVar9;
    puVar4 = (undefined8 *)puVar9[1];
    if (((undefined8 *)puVar3[1] != puVar9) || ((undefined8 *)*puVar4 != puVar9)) {
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      puVar10 = puVar10 + 8;
      goto LAB_14001280d;
    }
    *puVar4 = puVar3;
    puVar3[1] = puVar4;
    *puVar9 = 0;
    puVar9[1] = 0;
    *(undefined8 *)(puVar10 + -8) = 0x1400127fa;
    uVar8 = BowserDereferenceTransportName(lVar1);
    iVar7 = (int)uVar8;
    *(int *)(puVar10 + 0x20) = iVar7;
    puVar9 = puVar3;
  } while (-1 < iVar7);
LAB_14001281a:
  *(undefined8 *)(puVar10 + -8) = 0x140012828;
  ExReleaseResourceLite(&BowserTransportDatabaseResource);
  return iVar7;
}



===== BowserEnableIpxDatagramSocket @ 140012858 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int BowserEnableIpxDatagramSocket(longlong param_1)

{
  int iVar1;
  undefined8 *puVar2;
  undefined1 auStackY_58 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_58;
  local_28 = 0x5850494d;
  uStack_20 = 0x400000001;
  local_18 = 0x4944512c;
  iVar1 = BowserIssueTdiAction
                    (*(longlong *)(param_1 + 0x50),*(undefined8 *)(param_1 + 0x48),&local_28);
  if (-1 < iVar1) {
    puVar2 = &local_28;
    local_28 = 0x5850494d;
    uStack_20 = CONCAT71(uStack_20._1_7_,1);
    uStack_20 = CONCAT44(4,(undefined4)uStack_20);
    local_18 = CONCAT35(local_18._5_3_,0x144944507a);
    iVar1 = BowserIssueTdiAction
                      (*(longlong *)(param_1 + 0x50),*(undefined8 *)(param_1 + 0x48),puVar2);
    if ((-1 < iVar1) &&
       (iVar1 = BowserpTdiSetEventHandler
                          (*(longlong *)(param_1 + 0x50),*(undefined8 *)(param_1 + 0x48),puVar2,
                           BowserIpxDatagramHandler,param_1), -1 < iVar1)) {
      return 0;
    }
  }
  if (*(longlong *)(param_1 + 0x48) != 0) {
    ObfDereferenceObject();
    *(undefined8 *)(param_1 + 0x48) = 0;
  }
  if (*(longlong *)(*(longlong *)(param_1 + 8) + 0xf0) != 0) {
    ZwClose();
    *(undefined8 *)(*(longlong *)(param_1 + 8) + 0xf0) = 0;
  }
  return iVar1;
}



===== BowserIssueTdiAction @ 140012984 =====

int BowserIssueTdiAction(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar3 = IoAllocateIrp(*(undefined1 *)(param_1 + 0x4c),0);
  if (lVar3 != 0) {
    lVar4 = IoAllocateMdl(param_3,0x18,0,0,0);
    if (lVar4 != 0) {
      MmProbeAndLockPages(lVar4,0,1);
      lVar1 = *(longlong *)(lVar3 + 0xb8);
      *(undefined8 *)(lVar1 + -0x10) = 0;
      *(undefined8 *)(lVar1 + -8) = 0;
      *(undefined1 *)(lVar1 + -0x45) = 0;
      lVar1 = *(longlong *)(lVar3 + 0xb8);
      *(undefined2 *)(lVar1 + -0x48) = 0xe0f;
      *(longlong *)(lVar1 + -0x20) = param_1;
      *(undefined8 *)(lVar1 + -0x18) = param_2;
      *(longlong *)(lVar3 + 8) = lVar4;
      *(undefined8 *)(lVar3 + 0x18) = param_3;
      iVar2 = BowserSubmitTdiRequest(param_2,lVar3);
      IoFreeIrp(lVar3);
      if ((*(byte *)(lVar4 + 10) & 2) != 0) {
        MmUnlockPages(lVar4);
      }
      IoFreeMdl(lVar4);
      return iVar2;
    }
    IoFreeIrp(lVar3);
  }
  return -0x3fffff66;
}



===== UnbindTransportWorker @ 140012ae0 =====

undefined8 UnbindTransportWorker(longlong param_1)

{
  BowserDeleteTransport(param_1);
  return 0;
}



===== BowserPackNtString @ 140012af8 =====

ulonglong BowserPackNtString(ushort *param_1,longlong param_2,longlong param_3,longlong *param_4)

{
  ulonglong _Size;
  void *_Dst;
  
  _Size = (ulonglong)*param_1;
  if (*param_4 - param_3 < (longlong)_Size) {
    _Size = 0;
    *param_1 = 0;
  }
  else {
    _Dst = (void *)(*param_4 - _Size);
    *param_4 = (longlong)_Dst;
    memcpy(_Dst,*(void **)(param_1 + 4),_Size);
    *(longlong *)(param_1 + 4) = *param_4 - param_2;
  }
  return _Size;
}



===== AddBackupToBackupList @ 140012b68 =====

undefined8 AddBackupToBackupList(longlong *param_1,longlong param_2,longlong param_3)

{
  undefined8 uVar1;
  longlong lVar2;
  longlong local_28;
  longlong lStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  lStack_20 = *param_1;
  lVar2 = -1;
  local_18 = 0;
  uStack_10 = 0;
  do {
    lVar2 = lVar2 + 1;
  } while (*(short *)(param_3 + 0x2a + lVar2 * 2) != 0);
  if ((lStack_20 - param_2) + 1 + lVar2 < 0x400) {
    local_28 = (ulonglong)(ushort)(((short)param_2 - (short)*param_1) + 0x400) << 0x10;
    RtlInitUnicodeString(&local_18,param_3 + 0x2a);
    uVar1 = RtlUnicodeStringToOemString(&local_28,&local_18,0);
    if (-1 < (int)uVar1) {
      *param_1 = *param_1 + (ulonglong)((ushort)local_28 + 1);
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0x80000005;
  }
  return uVar1;
}



===== BowserLogIllegalNameWorker @ 140012c20 =====

void BowserLogIllegalNameWorker(longlong param_1)

{
  longlong in_stack_fffffffffffffff0;
  
  BowserWriteErrorLogEntry
            (*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x2c),
             (void *)(param_1 + 0x32),*(ushort *)(param_1 + 0x30),0,in_stack_fffffffffffffff0);
  ExFreePoolWithTag(param_1,0);
  return;
}



===== BowserCommonQueryVolumeInformationFile @ 140012c64 =====

undefined8
BowserCommonQueryVolumeInformationFile(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  *(undefined4 *)(param_3 + 0x30) = 0;
  IofCompleteRequest(param_3,0);
  return 0;
}



===== AddBowserName @ 140012c8c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong AddBowserName(undefined8 param_1,undefined8 param_2,ulonglong param_3,uint param_4)

{
  ushort *puVar1;
  ushort uVar2;
  longlong lVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  bool bVar8;
  undefined1 auStack_98 [32];
  undefined1 local_78;
  undefined8 *local_70;
  undefined8 *local_68;
  ushort local_60 [4];
  ulonglong uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_98;
  uVar5 = (ulonglong)param_4;
  local_60[0] = 0;
  local_60[1] = 0;
  local_60[2] = 0;
  local_60[3] = 0;
  uStack_58 = 0;
  puVar6 = (undefined8 *)0x0;
  local_70 = (undefined8 *)0x0;
  puVar7 = (undefined8 *)0x0;
  local_68 = (undefined8 *)0x0;
  local_78 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  uStack_28 = 0;
  lVar3 = IoGetCurrentProcess();
  bVar8 = lVar3 != BowserFspProcess;
  if (bVar8) {
    KeStackAttachProcess(BowserFspProcess,&local_50);
    local_78 = 1;
  }
  if ((0x40 < param_4) && (*(int *)(param_3 + 4) == 7)) {
    uVar2 = *(ushort *)(param_3 + 0x3c);
    local_60[1] = uVar2;
    local_60[0] = uVar2;
    uStack_58 = param_3 + 0x40;
    if ((uVar2 != 0) &&
       (((uVar2 <= param_4 && (param_3 <= uStack_58)) &&
        (uStack_58 <= (uVar5 - (uint)uVar2) + param_3)))) {
      puVar1 = (ushort *)(param_3 + 0x28);
      if (*puVar1 == 0) {
        *(undefined8 *)(param_3 + 0x30) = 0;
        *(undefined2 *)(param_3 + 0x2a) = 0;
      }
      else {
        uVar2 = *(ushort *)(param_3 + 0x2a);
        if (((param_4 < uVar2) || (uVar2 < *puVar1)) ||
           ((*(ulonglong *)(param_3 + 0x30) < param_3 ||
            ((uVar5 - uVar2) + param_3 < *(ulonglong *)(param_3 + 0x30))))) goto LAB_140012e3a;
      }
      if (*(ushort *)(param_3 + 0x18) == 0) {
        puVar4 = BowserFindDomain(puVar1);
        puVar7 = puVar4;
        local_68 = puVar4;
      }
      else {
        uVar2 = *(ushort *)(param_3 + 0x1a);
        if (((param_4 < uVar2) || (uVar2 < *(ushort *)(param_3 + 0x18))) ||
           ((*(ulonglong *)(param_3 + 0x20) < param_3 ||
            ((uVar5 - uVar2) + param_3 < *(ulonglong *)(param_3 + 0x20))))) goto LAB_140012e3a;
        puVar4 = (undefined8 *)BowserFindTransport((byte *)(param_3 + 0x18),puVar1);
        puVar6 = puVar4;
        local_70 = puVar4;
      }
      if (puVar4 == (undefined8 *)0x0) {
        uVar5 = 0xc0000034;
      }
      else {
        uVar5 = BowserAllocateName(local_60,*(int *)(param_3 + 0x38),(longlong)puVar6,
                                   (longlong)puVar7);
        uVar5 = uVar5 & 0xffffffff;
      }
      goto LAB_140012e3f;
    }
  }
LAB_140012e3a:
  uVar5 = 0xc000000d;
LAB_140012e3f:
  if (puVar6 != (undefined8 *)0x0) {
    BowserDereferenceTransport((longlong)puVar6);
  }
  if (puVar7 != (undefined8 *)0x0) {
    BowserDereferenceDomain(puVar7);
  }
  if (bVar8) {
    KeUnstackDetachProcess(&local_50);
  }
  return uVar5;
}



===== BowserRenameDomain @ 140012ea4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int BowserRenameDomain(ulonglong param_1,uint param_2)

{
  ushort uVar1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  undefined1 auStack_a8 [32];
  int local_88;
  int local_84;
  undefined8 local_80;
  ulonglong uStack_78;
  short *local_70;
  longlong local_68;
  undefined8 *local_60;
  ushort local_58 [8];
  short *local_48;
  longlong local_40;
  longlong local_38;
  short local_30 [16];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_a8;
  puVar5 = (undefined8 *)0x0;
  local_60 = (undefined8 *)0x0;
  local_58[0] = 0;
  local_58[1] = 0;
  local_58[2] = 0;
  local_58[3] = 0;
  local_58[4] = 0;
  local_58[5] = 0;
  local_58[6] = 0;
  local_58[7] = 0;
  local_80 = 0;
  uStack_78 = 0;
  if ((param_2 < 0x40) || (*(int *)(param_1 + 4) != 7)) {
LAB_140013130:
    iVar3 = -0x3ffffff3;
  }
  else {
    if (*(ushort *)(param_1 + 0x28) == 0) {
      *(undefined8 *)(param_1 + 0x30) = 0;
      *(undefined2 *)(param_1 + 0x2a) = 0;
    }
    else {
      uVar1 = *(ushort *)(param_1 + 0x2a);
      if ((((param_2 < uVar1) || (uVar1 < *(ushort *)(param_1 + 0x28))) ||
          (*(ulonglong *)(param_1 + 0x30) < param_1)) ||
         (((ulonglong)param_2 - (ulonglong)uVar1) + param_1 < *(ulonglong *)(param_1 + 0x30)))
      goto LAB_140013130;
    }
    uVar1 = *(ushort *)(param_1 + 0x3c);
    local_80 = (ulonglong)CONCAT22(uVar1,uVar1);
    uStack_78 = param_1 + 0x40;
    if (((uVar1 == 0) || (param_2 < uVar1)) ||
       ((uStack_78 < param_1 ||
        ((((ulonglong)param_2 - (ulonglong)uVar1) + param_1 < uStack_78 ||
         (uVar4 = BowserValidUnicodeString((byte *)&local_80), (int)uVar4 == 0))))))
    goto LAB_140013130;
    puVar5 = BowserFindDomain((ushort *)(param_1 + 0x28));
    local_60 = puVar5;
    if (puVar5 == (undefined8 *)0x0) {
      iVar3 = -0x3fffffcc;
    }
    else {
      local_38 = 0x7ffffffe;
      local_48 = (short *)((longlong)puVar5 + 0x36);
      local_70 = local_30;
      iVar3 = 0;
      local_68 = 0;
      for (local_40 = 0x10; local_40 != 0; local_40 = local_40 + -1) {
        if ((local_38 == 0) || (*local_48 == 0)) {
          if (local_40 != 0) goto LAB_140013064;
          break;
        }
        *local_70 = *local_48;
        local_70 = local_70 + 1;
        local_48 = local_48 + 1;
        local_38 = local_38 + -1;
        local_68 = local_68 + 1;
      }
      local_70 = local_70 + -1;
      local_68 = local_68 + -1;
      iVar3 = -0x7ffffffb;
LAB_140013064:
      *local_70 = 0;
      local_88 = iVar3;
      local_84 = iVar3;
      if (iVar3 < 0) goto LAB_140013139;
      RtlInitUnicodeString(local_58,local_30);
      cVar2 = RtlEqualUnicodeString(local_58,&local_80,1);
      if (cVar2 == '\0') {
        local_88 = BowserForEachTransportInDomain((longlong)puVar5,BowserAddDefaultNames,&local_80);
        if ((-1 < local_88) && (*(int *)(param_1 + 0x38) == 0)) {
          iVar3 = BowserSetDomainName((longlong)puVar5,(undefined2 *)&local_80);
          local_88 = iVar3;
          if (-1 < iVar3) {
            BowserForEachTransportInDomain((longlong)puVar5,BowserDeleteDefaultDomainNames,local_58)
            ;
            BowserSendPnp(4,local_58,(ushort *)0x0,(ushort *)0x0);
            goto LAB_140013139;
          }
        }
        iVar3 = local_88;
        BowserForEachTransportInDomain((longlong)puVar5,BowserDeleteDefaultDomainNames,&local_80);
        goto LAB_140013139;
      }
      iVar3 = 0;
    }
  }
  local_88 = iVar3;
LAB_140013139:
  if (puVar5 != (undefined8 *)0x0) {
    BowserDereferenceDomain(puVar5);
  }
  return iVar3;
}



===== BowserStopProcessingAnnouncements @ 140013180 =====

undefined8 BowserStopProcessingAnnouncements(longlong param_1)

{
  if (((*(char *)(param_1 + 4) == '\x02') || ((byte)(*(char *)(param_1 + 4) - 4U) < 4)) &&
     (*(char *)(param_1 + 5) != '\0')) {
    RdrDereferenceDiscardableCode(3);
    *(undefined1 *)(param_1 + 5) = 0;
  }
  return 0;
}



===== DeleteName @ 1400131bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 DeleteName(undefined8 param_1,undefined8 param_2,ulonglong param_3,uint param_4)

{
  ushort uVar1;
  undefined4 uVar2;
  longlong lVar3;
  undefined8 *puVar4;
  bool bVar5;
  undefined1 auStack_98 [32];
  undefined1 local_78;
  undefined8 local_70;
  ulonglong uStack_68;
  undefined8 *local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_98;
  local_70 = 0;
  uStack_68 = 0;
  puVar4 = (undefined8 *)0x0;
  local_60 = (undefined8 *)0x0;
  local_78 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  lVar3 = IoGetCurrentProcess();
  bVar5 = lVar3 != BowserFspProcess;
  if (bVar5) {
    KeStackAttachProcess(BowserFspProcess,&local_58);
    local_78 = 1;
  }
  if ((param_4 < 0x41) || (*(int *)(param_3 + 4) != 7)) {
LAB_14001330b:
    uVar2 = 0xc000000d;
  }
  else {
    uVar1 = *(ushort *)(param_3 + 0x3c);
    local_70._0_4_ = CONCAT22(uVar1,uVar1);
    uStack_68 = param_3 + 0x40;
    if (uVar1 == 0) {
      uStack_68 = 0;
      local_70 = (ulonglong)local_70._4_4_ << 0x20;
    }
    else if (((param_4 < uVar1) || (uStack_68 < param_3)) ||
            (((ulonglong)param_4 - (ulonglong)uVar1) + param_3 < uStack_68)) goto LAB_14001330b;
    if (*(ushort *)(param_3 + 0x28) == 0) {
      *(undefined8 *)(param_3 + 0x30) = 0;
      *(undefined2 *)(param_3 + 0x2a) = 0;
    }
    else {
      uVar1 = *(ushort *)(param_3 + 0x2a);
      if (((param_4 < uVar1) || (uVar1 < *(ushort *)(param_3 + 0x28))) ||
         ((*(ulonglong *)(param_3 + 0x30) < param_3 ||
          (((ulonglong)param_4 - (ulonglong)uVar1) + param_3 < *(ulonglong *)(param_3 + 0x30)))))
      goto LAB_14001330b;
    }
    puVar4 = BowserFindDomain((ushort *)(param_3 + 0x28));
    local_60 = puVar4;
    if (puVar4 == (undefined8 *)0x0) {
      uVar2 = 0xc0000034;
    }
    else {
      uVar2 = BowserDeleteNameByName((longlong)puVar4,(byte *)&local_70,*(int *)(param_3 + 0x38));
    }
  }
  if (puVar4 != (undefined8 *)0x0) {
    BowserDereferenceDomain(puVar4);
  }
  if (bVar5) {
    KeUnstackDetachProcess(&local_58);
  }
  return uVar2;
}



===== EnumServers @ 140013364 =====

undefined8
EnumServers(undefined8 param_1,undefined8 param_2,int *param_3,uint *param_4,void *param_5,
           uint param_6,longlong param_7)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  ulonglong local_28;
  int *piStack_20;
  
  local_28 = 0;
  piStack_20 = (int *)0x0;
  uVar3 = *param_4;
  uVar5 = (ulonglong)uVar3;
  if (((0x5f < uVar3) && (param_3[1] == 7)) && (*param_3 == 1)) {
    if (1 < param_3[2] - 100U) {
      return 0xc0000148;
    }
    if ((param_6 < 0x10) || ((param_3[2] == 0x65 && (param_6 < 0x28)))) {
      return 0xc0000023;
    }
    if (param_3[0x13] != 0) {
      piStack_20 = param_3 + 0x14;
      uVar1 = *(ushort *)(param_3 + 0x13);
      local_28 = (ulonglong)CONCAT22(uVar1,uVar1);
      if (uVar1 == 0) {
        return 0xc000000d;
      }
      if (uVar3 < uVar1) {
        return 0xc000000d;
      }
      if (piStack_20 < param_3) {
        return 0xc000000d;
      }
      if ((int *)((uVar5 - (uint)uVar1) + (longlong)param_3) < piStack_20) {
        return 0xc000000d;
      }
    }
    if (*(ushort *)(param_3 + 10) != 0) {
      uVar1 = *(ushort *)((longlong)param_3 + 0x2a);
      if (((uVar1 <= uVar3) && (*(ushort *)(param_3 + 10) <= uVar1)) &&
         ((param_3 <= *(int **)(param_3 + 0xc) &&
          (*(int **)(param_3 + 0xc) <= (int *)((uVar5 - uVar1) + (longlong)param_3))))) {
        uVar1 = *(ushort *)(param_3 + 6);
        if (uVar1 == 0) {
          param_3[8] = 0;
          param_3[9] = 0;
          *(undefined2 *)((longlong)param_3 + 0x1a) = 0;
        }
        else {
          uVar2 = *(ushort *)((longlong)param_3 + 0x1a);
          if (uVar3 < uVar2) {
            return 0xc000000d;
          }
          if (uVar2 < uVar1) {
            return 0xc000000d;
          }
          if (*(int **)(param_3 + 8) < param_3) {
            return 0xc000000d;
          }
          if ((int *)((uVar5 - uVar2) + (longlong)param_3) < *(int **)(param_3 + 8)) {
            return 0xc000000d;
          }
        }
        uVar4 = BowserEnumerateServers
                          (param_3[2],param_3 + 3,param_3 + 0x11,param_3[0x12],
                           (byte *)(-(ulonglong)(uVar1 != 0) & (ulonglong)(param_3 + 6)),
                           (ushort *)(param_3 + 10),
                           -(ulonglong)(param_3[0x13] != 0) & (ulonglong)&local_28,param_5,param_6,
                           param_3 + 0xe,param_3 + 0xf,param_3 + 0x10,param_7);
        *param_4 = 0x60;
        return uVar4;
      }
    }
  }
  return 0xc000000d;
}



===== StartBowser @ 14001357c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 StartBowser(void)

{
  char cVar1;
  undefined8 uVar2;
  longlong in_R9;
  int in_stack_00000028;
  
  cVar1 = ExAcquireResourceExclusiveLite(&BowserDataResource);
  uVar2 = 0;
  if (cVar1 == '\0') {
    uVar2 = 0x103;
  }
  else {
    if (BowserData == '\x01') {
      uVar2 = 0xc00000fc;
    }
    else if ((in_stack_00000028 == 0x60) && (*(int *)(in_R9 + 4) == 7)) {
      DAT_14000d29c = *(undefined4 *)(in_R9 + 0x40);
      _DAT_14000d2a0 = *(undefined4 *)(in_R9 + 0x44);
      DAT_14000d294 = *(undefined4 *)(in_R9 + 0x38);
      DAT_14000d298 = *(undefined4 *)(in_R9 + 0x3c);
      BowserLogElectionPackets = *(undefined1 *)(in_R9 + 0x48);
      DAT_14000d2a6 = *(undefined1 *)(in_R9 + 0x49);
      DAT_14000d288 = &BowserViewBufferHead;
      BowserViewBufferHead = &BowserViewBufferHead;
      KeInitializeSpinLock(&BowserViewBufferListSpinLock);
      BowserNumberOfServerAnnounceBuffers = 0;
      BowserData = '\x01';
      _BowserStartTime = _DAT_fffff78000000014;
      memset(&BowserStatistics,0,0x50);
      _BowserStatistics = _DAT_fffff78000000014;
      KeInitializeSpinLock(&BowserStatisticsLock);
    }
    else {
      uVar2 = 0xc000000d;
    }
    ExReleaseResourceLite(&BowserDataResource);
  }
  return uVar2;
}



===== StopBowser @ 1400136b0 =====

undefined8
StopBowser(undefined8 param_1,char param_2,undefined8 param_3,longlong param_4,int param_5)

{
  undefined8 *puVar1;
  code *pcVar2;
  undefined8 *puVar3;
  char cVar4;
  undefined8 uVar5;
  undefined8 local_res18 [2];
  
  local_res18[0] = param_3;
  cVar4 = ExAcquireResourceExclusiveLite(&BowserDataResource);
  uVar5 = 0;
  if (cVar4 == '\0') {
    uVar5 = 0x103;
  }
  else {
    if (BowserData == '\x01') {
      if ((param_5 == 0x60) && (*(int *)(param_4 + 4) == 7)) {
        if (param_2 == '\0') {
          BowserData = '\0';
          while( true ) {
            LOCK();
            UNLOCK();
            if (BowserOperationCount == 1) break;
            local_res18[0] = 0;
            LOCK();
            UNLOCK();
            ExReleaseResourceLite(&BowserDataResource);
            local_res18[0] = 0xffffffffff676980;
            KeDelayExecutionThread(0,0,local_res18);
            ExAcquireResourceExclusiveLite(&BowserDataResource);
          }
          LOCK();
          UNLOCK();
          BowserForEachTransport(UnbindTransportWorker,0);
          while (puVar3 = BowserViewBufferHead,
                (undefined8 **)BowserViewBufferHead != &BowserViewBufferHead) {
            puVar1 = (undefined8 *)*BowserViewBufferHead;
            if (((undefined8 **)BowserViewBufferHead[1] != &BowserViewBufferHead) ||
               ((undefined8 *)puVar1[1] != BowserViewBufferHead)) {
              pcVar2 = (code *)swi(0x29);
              (*pcVar2)(3);
              pcVar2 = (code *)swi(3);
              uVar5 = (*pcVar2)();
              return uVar5;
            }
            BowserViewBufferHead = puVar1;
            puVar1[1] = &BowserViewBufferHead;
            ExFreePoolWithTag(puVar3 + -1,0);
          }
          BowserNumberOfServerAnnounceBuffers = 0;
        }
        else {
          uVar5 = 0x103;
        }
      }
      else {
        uVar5 = 0xc000000d;
      }
    }
    else {
      uVar5 = 0xc00000fb;
    }
    ExReleaseResourceLite(&BowserDataResource);
  }
  return uVar5;
}



===== WaitForMasterAnnounce @ 140013824 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong WaitForMasterAnnounce(longlong param_1,longlong param_2,undefined8 param_3)

{
  ulonglong uVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined1 auStack_2a8 [32];
  longlong local_288;
  ushort local_280 [4];
  undefined1 *local_278;
  byte local_270 [8];
  undefined1 *local_268;
  undefined1 local_260 [40];
  undefined1 local_238 [528];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_2a8;
  lVar2 = 0;
  local_288 = 0;
  local_270[0] = 0;
  local_270[1] = 0;
  local_270[2] = 10;
  local_270[3] = 2;
  local_270[4] = 0;
  local_270[5] = 0;
  local_270[6] = 0;
  local_270[7] = 0;
  local_268 = local_238;
  local_280[0] = 0;
  local_280[1] = 0x20;
  local_280[2] = 0;
  local_280[3] = 0;
  local_278 = local_260;
  if (((*(uint *)(*(longlong *)(param_1 + 0xb8) + 8) < 0x3c) || ((uint)param_3 < 0x60)) ||
     ((*(byte *)(param_2 + 0x18) & 1) != 0)) {
    uVar3 = 0xc000000d;
  }
  else {
    uVar1 = BowserProbeAndCopyBuffer((ushort *)(param_2 + 0x18),(undefined2 *)local_270);
    uVar3 = uVar1 & 0xffffffff;
    if (-1 < (int)uVar1) {
      uVar1 = BowserProbeAndCopyBuffer((ushort *)(param_2 + 0x28),local_280);
      uVar3 = uVar1 & 0xffffffff;
      if (-1 < (int)uVar1) {
        lVar2 = BowserFindTransport(local_270,local_280);
        local_288 = lVar2;
        if (lVar2 == 0) {
          uVar3 = 0xc0000034;
        }
        else {
          uVar1 = BowserSendQueuedMasterAnnouncement(param_1,(longlong *)(lVar2 + 0x3d8));
          uVar3 = uVar1 & 0xffffffff;
          if ((int)uVar1 == -0x3ffffddb) {
            uVar3 = BowserQueueNonBufferRequest(param_1,(longlong *)(lVar2 + 0x3a8),param_3,'\0');
            uVar3 = uVar3 & 0xffffffff;
          }
        }
      }
    }
  }
  if (lVar2 != 0) {
    BowserDereferenceTransport(lVar2);
  }
  return uVar3;
}



===== wil_RtlStagingConfig_QueryFeatureState @ 14001395c =====

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



===== BowserStopBrowser @ 140013a30 =====

undefined8 BowserStopBrowser(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 8);
  ExAcquireResourceExclusiveLite(param_1 + 0xd0,1);
  if (*(int *)(lVar1 + 0xf8) == 3) {
    BowserDeactivateScavengerTimer();
  }
  *(undefined4 *)(lVar1 + 0xf8) = 0;
  *(uint *)(lVar1 + 0xfc) = *(uint *)(lVar1 + 0xfc) & 0xfff8ffff;
  BowserForEachTransportName(param_1,BowserStopProcessingAnnouncements,0);
  BowserStopTimer(param_1 + 0x138);
  BowserStopTimer(param_1 + 0x218);
  ExReleaseResourceLite(param_1 + 0xd0);
  BowserDeleteTransportNameByName(param_1,(short *)0x0,6);
  BowserDeleteTransportNameByName(param_1,(short *)0x0,5);
  BowserDeleteTransportNameByName(param_1,(short *)0x0,7);
  return 0;
}



===== BowserFsdPostToFsp @ 140013afc =====

undefined8 BowserFsdPostToFsp(undefined8 param_1,longlong param_2)

{
  byte *pbVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar3 = ExInterlockedRemoveHeadList(&BowserIrpContextList,&BowserIrpContextInterlock);
  if ((lVar3 != 0) || (lVar3 = ExAllocatePool2(0x42,0x30,0x6369424c), lVar3 != 0)) {
    uVar2 = BowserDeviceObject;
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
    *(longlong *)(lVar3 + 0x20) = param_2;
    *(undefined8 *)(lVar3 + 0x28) = param_1;
    lVar4 = IoAllocateWorkItem(uVar2);
    if (lVar4 != 0) {
      IoQueueWorkItemEx(lVar4,BowserFspDispatchWrapper,1,lVar3);
      return 0x103;
    }
    ExInterlockedInsertTailList(&BowserIrpContextList,lVar3,&BowserIrpContextInterlock);
  }
  return 0xc000009a;
}



===== BowserFspDispatch @ 140013be0 =====

void BowserFspDispatch(longlong param_1)

{
  char *pcVar1;
  uint *puVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  
  pcVar1 = *(char **)(param_1 + 0x20);
  puVar2 = *(uint **)(param_1 + 0x28);
  pbVar3 = *(byte **)(pcVar1 + 0xb8);
  ExInterlockedInsertTailList(&BowserIrpContextList,param_1,&BowserIrpContextInterlock);
  uVar4 = (uint)*pbVar3;
  if (uVar4 < 8) {
    if ((((uVar4 != 7) && (uVar4 = (uint)*pbVar3, uVar4 != 0)) && (uVar4 != 1)) &&
       (((uVar4 != 2 && (uVar4 != 3)) && (uVar4 != 4)))) {
      iVar5 = uVar4 - 5;
      if (iVar5 == 0) {
        BowserCommonQueryInformationFile(0,param_1,(longlong)pcVar1);
        return;
      }
LAB_140013c6a:
      if (iVar5 != 1) {
        pcVar1[0x30] = '\x02';
        pcVar1[0x31] = '\0';
        pcVar1[0x32] = '\0';
        pcVar1[0x33] = -0x40;
        goto LAB_140013c9a;
      }
    }
  }
  else if (uVar4 != 9) {
    if (uVar4 == 10) {
      BowserCommonQueryVolumeInformationFile(0,param_1,(longlong)pcVar1);
      return;
    }
    if ((uVar4 != 0xc) && (uVar4 != 0xd)) {
      if (uVar4 == 0xe) {
        BowserCommonDeviceIoControlFile(1,'\0',puVar2,pcVar1);
        return;
      }
      iVar5 = uVar4 - 0x11;
      if (iVar5 != 0) goto LAB_140013c6a;
    }
  }
  pcVar1[0x30] = '\x10';
  pcVar1[0x31] = '\0';
  pcVar1[0x32] = '\0';
  pcVar1[0x33] = -0x40;
LAB_140013c9a:
  pcVar1[0x38] = '\0';
  pcVar1[0x39] = '\0';
  pcVar1[0x3a] = '\0';
  pcVar1[0x3b] = '\0';
  pcVar1[0x3c] = '\0';
  pcVar1[0x3d] = '\0';
  pcVar1[0x3e] = '\0';
  pcVar1[0x3f] = '\0';
  IofCompleteRequest(pcVar1,0);
  return;
}



===== BowserFspDispatchWrapper @ 140013cd0 =====

void BowserFspDispatchWrapper(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  BowserFspDispatch(param_2);
  IoFreeWorkItem(param_3);
  return;
}



===== BowserUnload @ 140013d00 =====

void BowserUnload(void)

{
  undefined8 *puVar1;
  code *pcVar2;
  undefined8 *puVar3;
  undefined1 *_Dst;
  undefined1 *puVar4;
  undefined8 uVar5;
  undefined1 auStackY_98 [8];
  undefined1 auStackY_90 [24];
  undefined1 local_68 [4];
  undefined4 local_64;
  
  wil_UninitializeFeatureStaging();
  if (BowserData != '\0') {
    _Dst = local_68;
    uVar5 = 0x60;
    memset(_Dst,0,0x60);
    local_64 = 7;
    StopBowser(CONCAT71((int7)((ulonglong)_Dst >> 8),1),'\x01',uVar5,(longlong)local_68,0x60);
  }
  if (BowserPrimaryDomainInfo != (undefined8 *)0x0) {
    BowserDereferenceDomain(BowserPrimaryDomainInfo);
  }
  puVar4 = auStackY_98;
  BowUnregisterTelemetryProvider();
  do {
    puVar3 = BowserIrpContextList;
    if ((undefined8 **)BowserIrpContextList == &BowserIrpContextList) {
LAB_140013d9f:
      *(undefined8 *)(puVar4 + -8) = 0x140013da6;
      KeFlushQueuedDpcs();
      *(undefined8 *)(puVar4 + -8) = 0x140013db0;
      BowserpUninitializeMailslot();
      *(undefined8 *)(puVar4 + -8) = 0x140013dbe;
      ExDeleteResourceLite(&BowserTransportDatabaseResource);
      *(undefined8 *)(puVar4 + -8) = 0x140013dd1;
      ExDeleteResourceLite(&BowserDataResource);
      *(undefined8 *)(puVar4 + -8) = 0x140013de4;
      ObfDereferenceObject(BowserServerAnnouncementEvent);
      *(undefined8 *)(puVar4 + -8) = 0x140013df7;
      ZwClose(BowserServerAnnouncementEventHandle);
      if (BowserCriticalThreadWorkItem != 0) {
        *(undefined8 *)(puVar4 + -8) = 0x140013e0f;
        IoFreeWorkItem();
      }
      if (BowserDelayedThreadWorkItem != 0) {
        *(undefined8 *)(puVar4 + -8) = 0x140013e27;
        IoFreeWorkItem();
      }
      *(undefined8 *)(puVar4 + -8) = 0x140013e3a;
      IoDeleteDevice(BowserDeviceObject);
      *(undefined8 *)(puVar4 + -8) = 0x140013e44;
      RdrUninitializeDiscardableCode();
      if (DAT_14000d878 != 0) {
        *(undefined8 *)(puVar4 + -8) = 0x140013e5c;
        ExFreePoolWithTag(DAT_14000d878,0x6e695742);
        DAT_14000d878 = 0;
      }
      return;
    }
    if (((undefined8 **)BowserIrpContextList[1] != &BowserIrpContextList) ||
       (puVar1 = (undefined8 *)*BowserIrpContextList,
       (undefined8 *)puVar1[1] != BowserIrpContextList)) {
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(3);
      puVar4 = auStackY_90;
      goto LAB_140013d9f;
    }
    BowserIrpContextList = puVar1;
    puVar1[1] = &BowserIrpContextList;
    ExFreePoolWithTag(puVar3,0);
  } while( true );
}



===== wil_UninitializeFeatureStaging @ 140013e7c =====

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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 140013ed4 =====

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
      goto LAB_140013f31;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_140013f31;
    }
  }
  uVar1 = 0x206;
LAB_140013f31:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 140013f3c =====

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



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 140013ff4 =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 14001402c =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_1400140ae;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_1400140ae;
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
LAB_1400140ae:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 140014100 =====

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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 140014160 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 14001417c =====

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



===== BowserProcessMailslotWrite @ 140014230 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void BowserProcessMailslotWrite(longlong param_1)

{
  char cVar1;
  int iVar2;
  ushort *puVar3;
  char *pcVar4;
  longlong lVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  undefined1 auStackY_1f8 [32];
  longlong local_198;
  ushort local_190 [8];
  undefined8 local_180;
  void *pvStack_178;
  longlong local_170;
  undefined8 local_168;
  undefined8 uStack_160;
  ushort *local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  ulonglong uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  char local_128 [7];
  char local_121 [249];
  undefined1 local_28;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_1f8;
  local_198 = 0;
  local_168 = 0;
  uStack_160 = 0;
  local_158 = (ushort *)0x0;
  uStack_150 = 0;
  local_148 = 0;
  uStack_140 = uStack_140 & 0xffffffff00000000;
  local_180 = 0;
  pvStack_178 = (void *)0x0;
  local_190[0] = 0;
  local_190[1] = 0;
  local_190[2] = 0;
  local_190[3] = 0;
  local_190[4] = 0;
  local_190[5] = 0;
  local_190[6] = 0;
  local_190[7] = 0;
  local_138 = 0;
  uStack_130 = 0;
  lVar5 = param_1 + 0x5c;
  local_170 = param_1;
  if (((*(ushort *)(param_1 + 0x7f) == *(ushort *)(param_1 + 0x93)) &&
      (lVar5 + (ulonglong)*(ushort *)(param_1 + 0x95) <=
       param_1 + 0x5c + (ulonglong)*(uint *)(param_1 + 0x58))) &&
     ((uint)*(ushort *)(param_1 + 0x93) + (uint)*(ushort *)(param_1 + 0x95) <=
      *(uint *)(param_1 + 0x58))) {
    local_190[0] = 0;
    local_190[1] = 0x202;
    local_190[2] = 0;
    local_190[3] = 0;
    RtlStringCbCopyA(local_128,0x101,0x140009748);
    lVar5 = lVar5 + 0x45;
    uVar7 = 0xfa;
    RtlStringCbCopyNA(local_121,0xfa,lVar5,0xfa);
    local_28 = 0;
    pcVar4 = local_128;
    RtlInitString(&local_180);
    if ((DAT_14000d848 != 0) &&
       (cVar1 = BowserProcessNetlogonMailslotWrite(param_1,pcVar4,lVar5,uVar7), cVar1 != '\0')) {
      return;
    }
    iVar2 = RtlOemStringToUnicodeString(local_190,&local_180,1);
    if (iVar2 < 0) {
      BowserLogIllegalName(iVar2,pvStack_178,(ushort)local_180);
    }
    else {
      local_168 = CONCAT44(local_168._4_4_,0x30);
      uStack_160 = 0;
      uStack_150 = CONCAT44(uStack_150._4_4_,0x240);
      local_158 = local_190;
      local_148 = 0;
      uStack_140 = 0;
      puVar6 = &local_168;
      iVar2 = NtCreateFile(&local_198,0x40100000,puVar6,&local_138);
      puVar3 = local_190;
      RtlFreeUnicodeString();
      if (iVar2 < 0) {
        _DAT_14000d2f0 = _DAT_14000d2f0 + 1;
      }
      else {
        BowWriteTelemetryMailslotProcessing4(puVar3,local_190,puVar6);
        iVar2 = NtWriteFile(local_198,0,0,0);
        if (iVar2 < 0) {
          _DAT_14000d2ec = _DAT_14000d2ec + 1;
        }
        else {
          _DAT_14000d2cc = _DAT_14000d2cc + 1;
        }
      }
    }
    if (local_198 != 0) {
      ZwClose();
    }
  }
  else {
    BowserLogIllegalDatagram
              (*(longlong *)(param_1 + 0x40),lVar5,*(ushort *)(param_1 + 0x58),
               (void *)(param_1 + 0x48),0);
  }
  BowserFreeMailslotBuffer(param_1);
  return;
}



===== BowserpUninitializeMailslot @ 140014500 =====

void BowserpUninitializeMailslot(void)

{
  undefined8 *puVar1;
  code *pcVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  
  plVar4 = &BowserPnp;
  do {
    *(undefined4 *)(plVar4 + 2) = 0;
    BowserTrimMessageQueue(plVar4);
    BowserUninitializeIrpQueue(plVar4 + 3,(undefined1 *)0x0);
    plVar4 = plVar4 + 7;
  } while (plVar4 < &BowParametersRegistryKey);
  while( true ) {
    if ((undefined8 **)BowserMailslotBufferList == &BowserMailslotBufferList) {
      return;
    }
    if (((undefined8 **)BowserMailslotBufferList[1] != &BowserMailslotBufferList) ||
       (puVar1 = (undefined8 *)*BowserMailslotBufferList,
       (undefined8 *)puVar1[1] != BowserMailslotBufferList)) break;
    puVar3 = BowserMailslotBufferList + -1;
    BowserMailslotBufferList = puVar1;
    puVar1[1] = &BowserMailslotBufferList;
    ExFreePoolWithTag(puVar3,0);
  }
  pcVar2 = (code *)swi(0x29);
  (*pcVar2)(3);
  return;
}



===== BowserLogIllegalDatagramWorker @ 1400145a0 =====

void BowserLogIllegalDatagramWorker(longlong param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 local_28;
  void *pvStack_20;
  undefined8 local_18;
  longlong lStack_10;
  
  uVar1 = *(undefined4 *)(param_1 + 0x28);
  local_18 = 0;
  lStack_10 = 0;
  local_28 = 0;
  pvStack_20 = (void *)0x0;
  RtlInitAnsiString(&local_28,param_1 + 0x2e);
  iVar2 = RtlOemStringToUnicodeString(&local_18,&local_28,1);
  if (iVar2 < 0) {
    BowserLogIllegalName(iVar2,pvStack_20,(ushort)local_28);
  }
  else {
    BowserWriteErrorLogEntry
              (uVar1,0xc00000d0,(void *)(param_1 + 0x3e),*(ushort *)(param_1 + 0x2c),3,lStack_10);
    RtlFreeUnicodeString(&local_18);
  }
  BowserDereferenceTransportName(*(longlong *)(param_1 + 0x20));
  ExFreePoolWithTag(param_1,0);
  return;
}



===== BowserInitializeIrpContext @ 1400146a8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void BowserInitializeIrpContext(void)

{
  KeInitializeSpinLock(&BowserIrpContextInterlock);
  _DAT_14000d5d8 = &BowserIrpContextList;
  BowserIrpContextList = &BowserIrpContextList;
  return;
}



===== RdrUninitializeDiscardableCode @ 1400146e0 =====

void RdrUninitializeDiscardableCode(void)

{
  char cVar1;
  longlong *plVar2;
  longlong lVar3;
  
  ExAcquireResourceExclusiveLite(&RdrDiscardableCodeLock,1);
  plVar2 = &DAT_14000d5f8;
  lVar3 = 5;
  do {
    if (*plVar2 != 0) {
      cVar1 = KeCancelTimer();
      if (cVar1 == '\0') {
        ExReleaseResourceLite(&RdrDiscardableCodeLock);
        KeWaitForSingleObject(plVar2 + 1,0,0,0,0);
        ExAcquireResourceExclusiveLite(&RdrDiscardableCodeLock);
      }
      else {
        ExFreePoolWithTag(*plVar2,0);
        *plVar2 = 0;
      }
    }
    if (*(char *)((longlong)plVar2 + -4) != '\0') {
      *(undefined1 *)((longlong)plVar2 + -4) = 0;
      if (plVar2[5] != 0) {
        MmUnlockPagableImageSection();
        plVar2[5] = 0;
      }
      if (plVar2[7] != 0) {
        MmUnlockPagableImageSection();
        plVar2[7] = 0;
      }
    }
    plVar2 = plVar2 + 9;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  ExReleaseResourceLite(&RdrDiscardableCodeLock);
  ExDeleteResourceLite(&RdrDiscardableCodeLock);
  return;
}



===== TraceLoggingRegisterEx_EtwRegister_EtwSetInformation @ 140014804 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(void)

{
  undefined2 uVar1;
  code *pcVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  ulonglong local_18;
  
  puVar4 = auStack_48;
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = *(undefined4 *)(PTR_DAT_14000d0f8 + -0x10);
  uStack_24 = *(undefined4 *)(PTR_DAT_14000d0f8 + -0xc);
  uStack_20 = *(undefined4 *)(PTR_DAT_14000d0f8 + -8);
  uStack_1c = *(undefined4 *)(PTR_DAT_14000d0f8 + -4);
  if (DAT_14000d110 != 0) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(5);
    puVar4 = auStack_40;
  }
  _DAT_14000d118 = 0;
  uRam000000014000d120 = 0;
  *(undefined8 *)(puVar4 + -8) = 0x140014867;
  iVar3 = EtwRegister(puVar4 + 0x20,_tlgEnableCallback,&DAT_14000d0f0,&DAT_14000d110);
  if (iVar3 == 0) {
    uVar1 = *(undefined2 *)PTR_DAT_14000d0f8;
    *(undefined8 *)(puVar4 + -8) = 0x14001488e;
    EtwSetInformation(DAT_14000d110,2,PTR_DAT_14000d0f8,uVar1);
  }
  *(undefined8 *)(puVar4 + -8) = 0x1400148a2;
  return iVar3;
}



===== BowInitRegistryParametersKeyModule @ 1400148b0 =====

void BowInitRegistryParametersKeyModule(void)

{
  int iVar1;
  longlong local_res8 [4];
  
  local_res8[0] = 0;
  iVar1 = BowOpenParametersKeyFromRegistry(local_res8);
  if (-1 < iVar1) {
    BowEnableMailslots = BowReadEnableMailslotsFromRegistry(local_res8[0]);
  }
  if (local_res8[0] != 0) {
    ZwClose();
  }
  return;
}



===== BowOpenParametersKeyFromRegistry @ 1400148fc =====

int BowOpenParametersKeyFromRegistry(undefined8 *param_1)

{
  int iVar1;
  ushort uVar2;
  undefined8 local_res10;
  ushort local_68 [4];
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined8 local_58;
  undefined8 local_50;
  ushort *local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  local_58 = 0x30;
  local_48 = (ushort *)&BowParametersRegistryKey;
  local_40 = 0x240;
  local_50 = 0;
  local_38 = 0;
  uStack_30 = 0;
  iVar1 = ZwOpenKey(0,0x20019,&local_58);
  if (iVar1 == -0x3fffffcc) {
    uVar2 = 0;
    local_68[0] = 0;
    local_68[1] = 0x8c;
    local_68[2] = 0;
    local_68[3] = 0;
    uStack_60 = 0x400097a0;
    uStack_5c = 1;
    while( true ) {
      if (0x8a < local_68[0]) break;
      local_res10 = 0;
      while ((local_68[0] + 2 < 0x8b &&
             (*(short *)(CONCAT44(uStack_5c,uStack_60) + (ulonglong)(local_68[0] >> 1) * 2) != 0x5c)
             )) {
        local_68[0] = local_68[0] + 2;
      }
      if ((ushort)(local_68[0] - 1) < 0x89) {
        uVar2 = uVar2 + 1;
      }
      if (5 < uVar2) {
        local_48 = local_68;
        local_58 = CONCAT44(local_58._4_4_,0x30);
        local_50 = 0;
        local_38 = 0;
        uStack_30 = 0;
        local_40 = CONCAT44(local_40._4_4_,0x240);
        iVar1 = ZwCreateKey(&local_res10,0x20019,&local_58,0,0,0,0);
        if (iVar1 < 0) goto LAB_140014a77;
        if (local_68[0] == 0x8a) {
          *param_1 = local_res10;
          goto LAB_140014a51;
        }
        ZwClose(local_res10);
      }
      local_68[0] = local_68[0] + 2;
    }
  }
  if (iVar1 < 0) {
LAB_140014a77:
    *param_1 = 0;
  }
  else {
LAB_140014a51:
    iVar1 = 0;
  }
  return iVar1;
}



===== BowReadEnableMailslotsFromRegistry @ 140014a84 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool BowReadEnableMailslotsFromRegistry(undefined8 param_1)

{
  int iVar1;
  undefined4 uVar2;
  bool bVar3;
  undefined1 auStackY_78 [32];
  undefined4 *puVar4;
  undefined4 local_48 [2];
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_20 = 0;
  local_48[0] = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_40 = 0;
  uStack_38 = 0;
  RtlInitUnicodeString(&local_40,L"EnableMailslots");
  puVar4 = local_48;
  iVar1 = ZwQueryValueKey(param_1,&local_40,2,&local_30);
  if ((iVar1 < 0) || (local_30._4_4_ != 4)) {
    bVar3 = false;
  }
  else {
    bVar3 = uStack_28._4_4_ != 0;
  }
  if (BowEnableMailslotsByPolicy == 2) {
    uVar2 = 0x80001f65;
    if (bVar3 == false) {
      uVar2 = 0x40001f66;
    }
    BowserWriteErrorLogEntry(uVar2,0,(void *)0x0,0,0,(longlong)puVar4);
  }
  return bVar3;
}



===== BowInitRegistryPoliciesKeyModule @ 140014b68 =====

void BowInitRegistryPoliciesKeyModule(void)

{
  int iVar1;
  longlong local_res8 [4];
  
  local_res8[0] = 0;
  iVar1 = BowOpenPoliciesKeyFromRegistry(local_res8);
  if (-1 < iVar1) {
    BowEnableMailslotsByPolicy._0_1_ = BowReadEnableMailslotsFromPoliciesRegistry(local_res8[0]);
  }
  if (local_res8[0] != 0) {
    ZwClose();
  }
  return;
}



===== BowOpenPoliciesKeyFromRegistry @ 140014bb4 =====

int BowOpenPoliciesKeyFromRegistry(undefined8 *param_1)

{
  int iVar1;
  ushort uVar2;
  ushort uVar3;
  undefined8 local_res10;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 *local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong uStack_30;
  
  local_78 = 0x7a0078;
  local_38 = 0;
  uStack_30 = uStack_30 & 0xffffffff00000000;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = (undefined8 *)0x0;
  uStack_40 = 0;
  uStack_70 = ExAllocatePool2(0x100,0x7a,0x6f705742);
  if (uStack_70 == 0) {
    iVar1 = -0x3fffff66;
  }
  else {
    RtlCopyUnicodeString(&local_78,&BOW_REGISTRY_POLICIES_KEY_PATH);
    local_48 = &local_78;
    local_58 = CONCAT44(local_58._4_4_,0x30);
    uStack_50 = 0;
    uStack_40 = CONCAT44(uStack_40._4_4_,0x240);
    local_38 = 0;
    uStack_30 = 0;
    iVar1 = ZwOpenKey(param_1,0x20019,&local_58);
    if (iVar1 == -0x3fffffcc) {
      uVar3 = 0;
      local_68 = (undefined4)local_78;
      uStack_64 = local_78._4_4_;
      uStack_60 = (undefined4)uStack_70;
      uStack_5c = uStack_70._4_4_;
      uVar2 = 0;
      while( true ) {
        local_68 = CONCAT22(local_68._2_2_,uVar2);
        if (0x78 < uVar2) break;
        local_res10 = 0;
        while ((uVar2 + 2 < 0x79 &&
               (*(short *)(CONCAT44(uStack_5c,uStack_60) + (ulonglong)(uVar2 >> 1) * 2) != 0x5c))) {
          uVar2 = uVar2 + 2;
          local_68 = CONCAT22(local_68._2_2_,uVar2);
        }
        if ((ushort)(uVar2 - 1) < 0x78) {
          uVar3 = uVar3 + 1;
        }
        if (4 < uVar3) {
          local_48 = (undefined8 *)&local_68;
          local_58 = CONCAT44(local_58._4_4_,0x30);
          uStack_50 = 0;
          local_38 = 0;
          uStack_30 = 0;
          uStack_40 = CONCAT44(uStack_40._4_4_,0x240);
          iVar1 = ZwCreateKey(&local_res10,0x20019,&local_58,0,0,0,0);
          if (iVar1 < 0) goto LAB_140014da5;
          if ((ushort)local_68 == 0x78) {
            *param_1 = local_res10;
            goto LAB_140014d62;
          }
          ZwClose(local_res10);
          uVar2 = (ushort)local_68;
        }
        uVar2 = uVar2 + 2;
      }
    }
    if (iVar1 < 0) {
LAB_140014da5:
      *param_1 = 0;
    }
    else {
LAB_140014d62:
      iVar1 = 0;
    }
  }
  if (uStack_70 != 0) {
    ExFreePoolWithTag(uStack_70,0x6f705742);
  }
  return iVar1;
}



===== BowReadEnableMailslotsFromPoliciesRegistry @ 140014db0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 BowReadEnableMailslotsFromPoliciesRegistry(undefined8 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  undefined1 auStackY_78 [32];
  undefined4 *puVar4;
  undefined4 local_48 [2];
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_20 = 0;
  local_48[0] = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_40 = 0;
  uStack_38 = 0;
  RtlInitUnicodeString(&local_40,L"EnableMailslots");
  puVar4 = local_48;
  uVar3 = 2;
  iVar1 = ZwQueryValueKey(param_1,&local_40,2,&local_30);
  if ((-1 < iVar1) && (local_30._4_4_ == 4)) {
    uVar3 = uStack_28._4_4_ != 0;
    uVar2 = 0x80001f65;
    if (!(bool)uVar3) {
      uVar2 = 0x40001f66;
    }
    BowserWriteErrorLogEntry(uVar2,0,(void *)0x0,0,0,(longlong)puVar4);
  }
  return uVar3;
}



===== BowserFsdCleanup @ 140014ea0 =====

undefined8 BowserFsdCleanup(ulonglong param_1,longlong param_2)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 *puVar5;
  bool bVar6;
  ulonglong local_res8 [2];
  
  local_res8[0] = param_1;
  KeEnterCriticalRegion();
  lVar3 = *(longlong *)(param_2 + 0xc0);
  ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource);
  puVar5 = BowserTransportHead;
  while ((undefined8 **)puVar5 != &BowserTransportHead) {
    if (*(char *)((longlong)puVar5 + 0x14e) == '\0') {
      lVar4 = puVar5[-1];
      BowserReferenceTransport(lVar4);
      ExReleaseResourceLite(&BowserTransportDatabaseResource);
      local_res8[0] = local_res8[0] & 0xffffffffffffff00;
      BowserCancelQueuedIoForFile((longlong *)(lVar4 + 0x378),lVar3,(longlong *)0x0);
      BowserCancelQueuedIoForFile((longlong *)(lVar4 + 0x388),lVar3,(longlong *)0x0);
      BowserCancelQueuedIoForFile((longlong *)(lVar4 + 0x398),lVar3,(longlong *)local_res8);
      BowserCancelQueuedIoForFile((longlong *)(lVar4 + 0x3a8),lVar3,(longlong *)0x0);
      BowserCancelQueuedIoForFile((longlong *)(lVar4 + 0x3b8),lVar3,(longlong *)0x0);
      BowserCancelQueuedIoForFile((longlong *)(lVar4 + 0x3c8),lVar3,(longlong *)0x0);
      if ((char)local_res8[0] != '\0') {
        BowserDeactivateScavengerTimer();
      }
      ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
      puVar5 = (undefined8 *)*puVar5;
      ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource);
      LOCK();
      piVar1 = (int *)(lVar4 + 4);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        BowserpFreeTransport(lVar4);
      }
      ExReleaseResourceLite(&BowserTransportDatabaseResource);
    }
    else {
      puVar5 = (undefined8 *)*puVar5;
    }
  }
  ExReleaseResourceLite(&BowserTransportDatabaseResource);
  LOCK();
  iVar2 = BowserNumberOfOpenFiles + -1;
  UNLOCK();
  bVar6 = BowserNumberOfOpenFiles == 1;
  BowserNumberOfOpenFiles = iVar2;
  if (bVar6) {
    BowserForEachTransport(BowserStopBrowser,0);
  }
  KeLeaveCriticalRegion();
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== BowserScavenger @ 1400150a0 =====

void BowserScavenger(undefined8 param_1)

{
  int *piVar1;
  longlong ****pppplVar2;
  int iVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  
  ExFreePoolWithTag(param_1,0);
  ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
  puVar6 = BowserTransportHead;
LAB_1400150e0:
  do {
    if ((undefined8 **)puVar6 == &BowserTransportHead) {
      ExReleaseResourceLite(&BowserTransportDatabaseResource);
LAB_140015193:
      ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
      puVar6 = BowserTransportHead;
      while ((undefined8 **)puVar6 != &BowserTransportHead) {
        if (*(char *)((longlong)puVar6 + 0x14e) == '\0') {
          lVar4 = puVar6[-1];
          BowserReferenceTransport(lVar4);
          ExReleaseResourceLite(&BowserTransportDatabaseResource);
          pppplVar2 = (longlong ****)(lVar4 + 0x398);
          if ((longlong ****)*pppplVar2 != pppplVar2) {
            BowserTimeoutQueuedIrp(pppplVar2);
          }
          ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
          puVar6 = (undefined8 *)*puVar6;
          ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
          LOCK();
          piVar1 = (int *)(lVar4 + 4);
          iVar3 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            BowserpFreeTransport(lVar4);
          }
          ExReleaseResourceLite(&BowserTransportDatabaseResource);
        }
        else {
          puVar6 = (undefined8 *)*puVar6;
        }
      }
      ExReleaseResourceLite(&BowserTransportDatabaseResource);
      return;
    }
    if (*(char *)((longlong)puVar6 + 0x14e) != '\0') {
      puVar6 = (undefined8 *)*puVar6;
      goto LAB_1400150e0;
    }
    lVar4 = puVar6[-1];
    BowserReferenceTransport(lVar4);
    ExReleaseResourceLite(&BowserTransportDatabaseResource);
    uVar5 = AgeServerAnnouncements(lVar4);
    if ((int)uVar5 < 0) {
      BowserDereferenceTransport(lVar4);
      goto LAB_140015193;
    }
    ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
    puVar6 = (undefined8 *)*puVar6;
    ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
    LOCK();
    piVar1 = (int *)(lVar4 + 4);
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar3 == 1) {
      BowserpFreeTransport(lVar4);
    }
    ExReleaseResourceLite(&BowserTransportDatabaseResource);
  } while( true );
}



===== AgeServerAnnouncements @ 1400152a0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 AgeServerAnnouncements(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  bool bVar6;
  longlong lVar7;
  longlong lVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  undefined1 *puVar11;
  int iVar12;
  undefined8 uVar13;
  longlong lVar14;
  uint uVar15;
  undefined8 uVar16;
  undefined8 local_res18;
  undefined4 local_res20 [2];
  undefined8 uStack_a0;
  undefined1 auStack_98 [32];
  uint local_78 [4];
  ulonglong local_68 [2];
  int local_58 [2];
  ulonglong local_50 [3];
  
  uVar13 = 0;
  uVar16 = 0;
  iVar12 = 0;
  local_78[3] = 0;
  lVar14 = *(longlong *)(param_1 + 8);
  ExAcquireResourceExclusiveLite(param_1 + 0xd0,1);
  puVar11 = auStack_98;
  lVar7 = param_1 + 0xd0;
  if (*(int *)(lVar14 + 0xf8) == 3) {
    ExReleaseResourceLite(lVar7);
    local_50[1] = param_1 + 0x68;
    ExAcquireResourceExclusiveLite(local_50[1],1);
    puVar11 = auStack_98;
    local_78[1] = 0;
    local_78[0] = 0;
    while( true ) {
      *(undefined8 *)(puVar11 + -8) = 0x14001533b;
      lVar7 = RtlEnumerateGenericTableWithoutSplaying(lVar14 + 0x48,puVar11 + 0xb0);
      if (lVar7 == 0) break;
      *(undefined8 *)(puVar11 + -8) = 0x140015448;
      lVar8 = BowserGetCurrentTime();
      if (*(uint *)(lVar7 + 4) < (uint)lVar8) {
        if ((*(int *)(*(longlong *)(lVar7 + 0x20) + 0x38) != 4) &&
           ((*(uint *)(lVar7 + 0x4c) & 0x20000) != 0)) {
          *(int *)(lVar14 + 0x40) = *(int *)(lVar14 + 0x40) + -1;
        }
        *(undefined8 *)(puVar11 + 0xb0) = uVar16;
        *(undefined4 *)(puVar11 + 0x24) = 0;
        *(undefined4 *)(puVar11 + 0x20) = 0;
        iVar12 = iVar12 + 1;
        *(int *)(puVar11 + 0x40) = iVar12;
        plVar1 = (longlong *)(lVar7 + 0x10);
        lVar8 = *plVar1;
        if (lVar8 != 0) {
          plVar2 = *(longlong **)(lVar7 + 0x18);
          if ((*(longlong **)(lVar8 + 8) != plVar1) || ((longlong *)*plVar2 != plVar1)) {
            pcVar3 = (code *)swi(0x29);
            (*pcVar3)(3);
            puVar11 = puVar11 + 8;
            goto LAB_1400155f1;
          }
          *plVar2 = lVar8;
          *(longlong **)(lVar8 + 8) = plVar2;
          *(int *)(lVar14 + 0xe8) = *(int *)(lVar14 + 0xe8) + -1;
          *plVar1 = 0;
          *(undefined8 *)(lVar7 + 0x18) = 0;
        }
        lVar8 = *(longlong *)(lVar7 + 0x20);
        *(undefined8 *)(puVar11 + -8) = 0x14001558e;
        BowserDereferenceName(lVar8);
        *(undefined8 *)(puVar11 + -8) = 0x14001559c;
        RtlDeleteElementGenericTable(lVar14 + 0x48,lVar7);
      }
      else {
        lVar8 = *(longlong *)(param_1 + 0x38);
        *(undefined8 *)(puVar11 + -8) = 0x140015464;
        bVar6 = BowserIsLegalBackupBrowser(lVar7,(ushort *)(lVar8 + 0x88));
        if (bVar6) {
LAB_1400155f1:
          *(int *)(puVar11 + 0x24) = *(int *)(puVar11 + 0x24) + 1;
        }
        uVar15 = *(uint *)(lVar7 + 0x4c);
        if ((uVar15 & 0x18) == 0) {
          if (((uVar15 >> 0x11 & 1) != 0) && ((uVar15 >> 0x10 & 1) == 0)) {
LAB_140015616:
            *(int *)(puVar11 + 0x20) = *(int *)(puVar11 + 0x20) + 1;
          }
        }
        else if ((uVar15 & 0x61000) == 0x21000) goto LAB_140015616;
        uVar16 = *(undefined8 *)(puVar11 + 0xb0);
        *(undefined8 *)(puVar11 + 0x38) = uVar16;
      }
    }
    *(undefined8 *)(puVar11 + 0x48) = 0;
    *(undefined4 *)(puVar11 + 0xb8) = 0xe219652c;
    *(undefined4 *)(puVar11 + 0xbc) = 0xd1b71758;
    uVar9 = _DAT_fffff78000000014 - _BowserStartTime;
    *(undefined8 *)(puVar11 + 0x30) = 0;
    if ((longlong)uVar9 < 0) {
      auVar5._8_8_ = 0;
      auVar5._0_8_ = -uVar9;
      uVar10 = SUB168(ZEXT816(0xd1b71758e219652c) * auVar5,8);
    }
    else {
      auVar4._8_8_ = 0;
      auVar4._0_8_ = uVar9;
      uVar10 = SUB168(ZEXT816(0xd1b71758e219652c) * auVar4,8);
    }
    *(ulonglong *)(puVar11 + 0x30) = uVar10;
    uVar10 = uVar10 >> 0xd;
    *(ulonglong *)(puVar11 + 0x30) = uVar10;
    iVar12 = (int)uVar10;
    if ((longlong)uVar9 < 0) {
      uVar10 = -uVar10;
      *(ulonglong *)(puVar11 + 0x30) = uVar10;
      iVar12 = (int)uVar10;
    }
    *(ulonglong *)(puVar11 + 0x48) = uVar10;
    if ((int)(uVar10 >> 0x20) != 0) {
      iVar12 = -1;
    }
    if (900000 < (uint)(iVar12 - *(int *)(lVar14 + 0x118))) {
      if (*(uint *)(puVar11 + 0x20) < BowserMinimumConfiguredBrowsers) {
        *(undefined4 *)(lVar14 + 0x40) = *(undefined4 *)(puVar11 + 0x24);
        *(undefined8 *)(puVar11 + -8) = 0x1400154c4;
        iVar12 = RtlNumberGenericTableElements();
        uVar15 = iVar12 + 0x1fU >> 5;
        *(uint *)(puVar11 + 0x28) = uVar15;
        if (*(uint *)(lVar14 + 0x40) < uVar15) {
          iVar12 = uVar15 - *(uint *)(lVar14 + 0x40);
          *(int *)(puVar11 + 0x28) = iVar12;
          *(undefined8 *)(puVar11 + 0xb0) = 0;
          *(undefined8 *)(puVar11 + -8) = 0x140015506;
          lVar7 = RtlEnumerateGenericTableWithoutSplaying(lVar14 + 0x48,puVar11 + 0xb0);
          while (lVar7 != 0) {
            *(undefined8 *)(puVar11 + -8) = 0x140015528;
            uVar9 = BowserIsValidPotentialBrowser(param_1,lVar7);
            if ((char)uVar9 == '\0') {
              if (((*(uint *)(lVar7 + 0x4c) >> 0x11 & 1) != 0) &&
                 (*(ushort *)(lVar7 + 0x28) < 0x10f)) {
                *(undefined8 *)(puVar11 + -8) = 0x140015670;
                BowserShutdownRemoteBrowser(param_1);
              }
            }
            else {
              *(undefined8 *)(puVar11 + -8) = 0x14001563d;
              BowserPromoteToBackup(param_1);
              *(int *)(lVar7 + 0x58) = *(int *)(lVar7 + 0x58) + 1;
              iVar12 = iVar12 + -1;
              *(int *)(puVar11 + 0x28) = iVar12;
              if (iVar12 == 0) break;
            }
            *(undefined8 *)(puVar11 + -8) = 0x140015550;
            lVar7 = RtlEnumerateGenericTableWithoutSplaying(lVar14 + 0x48,puVar11 + 0xb0);
          }
        }
      }
      else {
        *(undefined8 *)(puVar11 + 0xb0) = 0;
        while( true ) {
          *(undefined8 *)(puVar11 + -8) = 0x14001568c;
          lVar7 = RtlEnumerateGenericTableWithoutSplaying(lVar14 + 0x48,puVar11 + 0xb0);
          if (lVar7 == 0) break;
          *(undefined8 *)(puVar11 + -8) = 0x1400156a8;
          bVar6 = BowserIsValidBackupBrowser(param_1,lVar7);
          if (bVar6) {
            *(undefined8 *)(puVar11 + -8) = 0x1400156b8;
            BowserShutdownRemoteBrowser(param_1);
          }
        }
      }
    }
    *(undefined8 *)(puVar11 + 0xb0) = 0;
    *(undefined8 *)(puVar11 + 0x38) = 0;
    lVar14 = lVar14 + 0x90;
    *(undefined8 *)(puVar11 + -8) = 0x1400153fa;
    lVar7 = RtlEnumerateGenericTableWithoutSplaying(lVar14,puVar11 + 0xb0);
    iVar12 = *(int *)(puVar11 + 0x2c);
    while (lVar7 != 0) {
      *(undefined8 *)(puVar11 + -8) = 0x140015414;
      lVar8 = BowserGetCurrentTime();
      if (*(uint *)(lVar7 + 4) < (uint)lVar8) {
        iVar12 = iVar12 + 1;
        *(int *)(puVar11 + 0x2c) = iVar12;
        *(undefined8 *)(puVar11 + 0xb0) = uVar13;
        lVar8 = *(longlong *)(lVar7 + 0x20);
        *(undefined8 *)(puVar11 + -8) = 0x1400156d5;
        BowserDereferenceName(lVar8);
        *(undefined8 *)(puVar11 + -8) = 0x1400156e2;
        RtlDeleteElementGenericTable(lVar14,lVar7);
      }
      else {
        uVar13 = *(undefined8 *)(puVar11 + 0xb0);
        *(undefined8 *)(puVar11 + 0x38) = uVar13;
      }
      *(undefined8 *)(puVar11 + -8) = 0x14001543c;
      lVar7 = RtlEnumerateGenericTableWithoutSplaying(lVar14,puVar11 + 0xb0);
    }
    lVar7 = *(longlong *)(puVar11 + 0x50);
  }
  *(undefined8 *)(puVar11 + -8) = 0x1400156f8;
  ExReleaseResourceLite(lVar7);
  return 0;
}



===== AsyncCreateTransportName @ 140015720 =====

void AsyncCreateTransportName(longlong param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  uVar4 = BowserAllocateName((ushort *)(param_1 + 0x20),*(int *)(param_1 + 0x30),
                             *(longlong *)(param_1 + 0x18),0);
  *(int *)(param_1 + 0x34) = (int)uVar4;
  lVar3 = *(longlong *)(param_1 + 0x18);
  if (lVar3 != 0) {
    ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
    LOCK();
    piVar1 = (int *)(lVar3 + 4);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      BowserpFreeTransport(lVar3);
    }
    ExReleaseResourceLite(&BowserTransportDatabaseResource);
  }
  PsTerminateSystemThread(0);
  return;
}



===== BowserAllocateName @ 1400157b0 =====

ulonglong BowserAllocateName(ushort *param_1,int param_2,longlong param_3,longlong param_4)

{
  undefined4 uVar1;
  code *pcVar2;
  undefined8 uVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  ulonglong uVar9;
  undefined8 *puVar10;
  undefined1 *puVar11;
  undefined8 *puVar12;
  undefined1 auStack_a8 [8];
  undefined1 auStack_a0 [24];
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  
  local_68 = 0;
  uStack_60 = 0;
  uVar7 = BowserValidUnicodeString((byte *)param_1);
  if ((int)uVar7 == 0) {
    return 0xc000000d;
  }
  ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
  local_88 = 0;
  uStack_80 = 0;
  local_78 = 0;
  uStack_70 = 0;
  uVar7 = BowserValidUnicodeString((byte *)param_1);
  if ((int)uVar7 == 0) {
LAB_1400158fb:
    puVar10 = (undefined8 *)ExAllocatePool2(0x100,(ulonglong)*param_1 + 0x42,0x6e62424c);
    if (puVar10 == (undefined8 *)0x0) {
      uVar9 = 0xc000009a;
    }
    else {
      *(undefined4 *)puVar10 = 0x400006;
      puVar12 = puVar10 + 1;
      *(undefined4 *)((longlong)puVar10 + 4) = 1;
      puVar8 = puVar10 + 3;
      puVar10[4] = puVar8;
      *puVar8 = puVar8;
      *(int *)(puVar10 + 7) = param_2;
      if ((undefined8 **)BowserNameHead[1] != &BowserNameHead) {
        pcVar2 = (code *)swi(0x29);
        (*pcVar2)(3);
        puVar11 = auStack_a0;
        goto LAB_140015a77;
      }
      *puVar12 = BowserNameHead;
      puVar10[2] = &BowserNameHead;
      BowserNameHead[1] = puVar12;
      BowserNameHead = puVar12;
      puVar10[6] = puVar10 + 8;
      *(ushort *)((longlong)puVar10 + 0x2a) = *param_1 + 2;
      RtlCopyUnicodeString(puVar10 + 5,param_1);
      *(undefined2 *)(puVar10[6] + (ulonglong)(*(ushort *)(puVar10 + 5) >> 1) * 2) = 0;
      uVar6 = RtlUpcaseUnicodeStringToOemString(&local_68,puVar10 + 5,1);
      uVar9 = (ulonglong)uVar6;
      if (-1 < (int)uVar6) {
        uVar6 = RtlOemStringToUnicodeString(puVar10 + 5,&local_68,0);
        uVar9 = (ulonglong)uVar6;
        RtlFreeOemString(&local_68);
        if (-1 < (int)uVar6) goto LAB_140015a32;
      }
    }
    ExReleaseResourceLite(&BowserTransportDatabaseResource);
    puVar11 = auStack_a8;
LAB_1400159ce:
    if (-1 < (int)uVar9) {
      if (puVar10 == (undefined8 *)0x0) {
        return uVar9;
      }
      goto LAB_140015af1;
    }
  }
  else {
    iVar5 = RtlUpcaseUnicodeStringToOemString(&local_88,param_1,1);
    if (iVar5 < 0) goto LAB_1400158fb;
    iVar5 = RtlOemStringToUnicodeString(&local_78,&local_88,1);
    RtlFreeOemString(&local_88);
    if (iVar5 < 0) goto LAB_1400158fb;
    ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
    for (puVar12 = BowserNameHead; puVar10 = (undefined8 *)0x0,
        (undefined8 **)puVar12 != &BowserNameHead; puVar12 = (undefined8 *)*puVar12) {
      puVar10 = puVar12 + -1;
      if ((*(int *)(puVar12 + 6) == param_2) &&
         (cVar4 = RtlEqualUnicodeString(puVar12 + 4,&local_78,0), cVar4 != '\0')) {
        *(int *)((longlong)puVar12 + -4) = *(int *)((longlong)puVar12 + -4) + 1;
        break;
      }
    }
    RtlFreeUnicodeString(&local_78);
    ExReleaseResourceLite(&BowserTransportDatabaseResource);
    if (puVar10 == (undefined8 *)0x0) goto LAB_1400158fb;
LAB_140015a32:
    puVar11 = auStack_a8;
    if (param_3 != 0) {
      ExReleaseResourceLite(&BowserTransportDatabaseResource);
      uVar9 = BowserCreateTransportName(param_3,(longlong)puVar10);
      uVar9 = uVar9 & 0xffffffff;
      puVar11 = auStack_a8;
      goto LAB_1400159ce;
    }
LAB_140015a77:
    uVar7 = *(undefined8 *)param_1;
    uVar3 = *(undefined8 *)(param_1 + 4);
    *(undefined4 *)(puVar11 + 0x74) = 0;
    *(undefined1 **)(puVar11 + 0x58) = puVar11 + 0x50;
    *(int *)(puVar11 + 0x70) = param_2;
    *(undefined1 **)(puVar11 + 0x50) = puVar11 + 0x50;
    *(undefined8 *)(puVar11 + 0x60) = uVar7;
    *(undefined8 *)(puVar11 + 0x68) = uVar3;
    *(undefined8 *)(puVar11 + -8) = 0x140015ab0;
    uVar6 = BowserForEachTransportInDomain(param_4,AddTransportName,puVar11 + 0x50);
    uVar9 = (ulonglong)uVar6;
    *(undefined8 *)(puVar11 + -8) = 0x140015ac0;
    ExReleaseResourceLite(&BowserTransportDatabaseResource);
    if (-1 < (int)uVar6) {
      *(undefined8 *)(puVar11 + -8) = 0x140015b03;
      uVar6 = WaitForAddNameOperation((longlong *)(puVar11 + 0x50));
      uVar9 = (ulonglong)uVar6;
      goto LAB_1400159ce;
    }
    *(undefined8 *)(puVar11 + -8) = 0x140015ad3;
    WaitForAddNameOperation((longlong *)(puVar11 + 0x50));
  }
  if (puVar10 == (undefined8 *)0x0) {
    return uVar9;
  }
  if (param_3 == 0) {
    uVar1 = *(undefined4 *)(puVar10 + 7);
    *(undefined8 *)(puVar11 + -8) = 0x140015af1;
    BowserDeleteNamesInDomain(param_4,puVar10 + 5,uVar1);
  }
LAB_140015af1:
  *(undefined8 *)(puVar11 + -8) = 0x140015af9;
  BowserDereferenceName((longlong)puVar10);
  return uVar9;
}



===== BowserDereferenceName @ 140015b10 =====

void BowserDereferenceName(longlong param_1)

{
  int *piVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  
  ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
  piVar1 = (int *)(param_1 + 4);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    lVar2 = *(longlong *)(param_1 + 8);
    if ((*(longlong *)(lVar2 + 8) != param_1 + 8) ||
       (plVar3 = *(longlong **)(param_1 + 0x10), *plVar3 != param_1 + 8)) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    ExFreePoolWithTag(param_1,0);
  }
  ExReleaseResourceLite(&BowserTransportDatabaseResource);
  return;
}



===== BowserForEachTransport @ 140015b90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int BowserForEachTransport(undefined *param_1,undefined8 param_2)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  int iVar4;
  undefined8 *puVar5;
  
  iVar4 = 0;
  ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
  puVar5 = BowserTransportHead;
  while( true ) {
    while( true ) {
      if ((undefined8 **)puVar5 == &BowserTransportHead) {
        ExReleaseResourceLite(&BowserTransportDatabaseResource);
        return iVar4;
      }
      if (*(char *)((longlong)puVar5 + 0x14e) == '\0') break;
      puVar5 = (undefined8 *)*puVar5;
    }
    lVar3 = puVar5[-1];
    BowserReferenceTransport(lVar3);
    ExReleaseResourceLite(&BowserTransportDatabaseResource);
    iVar4 = (*(code *)param_1)(lVar3,param_2);
    if (iVar4 < 0) break;
    ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
    puVar5 = (undefined8 *)*puVar5;
    ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
    LOCK();
    piVar1 = (int *)(lVar3 + 4);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      BowserpFreeTransport(lVar3);
    }
    ExReleaseResourceLite(&BowserTransportDatabaseResource);
  }
  BowserDereferenceTransport(lVar3);
  return iVar4;
}



===== BowserpFreeTransport @ 140015cc0 =====

void BowserpFreeTransport(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  char local_res8 [8];
  
  local_res8[0] = '\0';
  ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource);
  lVar2 = *(longlong *)(param_1 + 8);
  if (lVar2 != 0) {
    lVar3 = *(longlong *)(lVar2 + 0x10);
    lVar1 = lVar2 + 0x10;
    if (lVar3 != lVar1) {
      if ((*(longlong *)(lVar3 + 8) != lVar1) ||
         (plVar4 = *(longlong **)(lVar2 + 0x18), *plVar4 != lVar1)) {
        pcVar5 = (code *)swi(0x29);
        (*pcVar5)(3);
        pcVar5 = (code *)swi(3);
        (*pcVar5)();
        return;
      }
      *plVar4 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar4;
    }
    if (*(longlong **)(lVar2 + 0x20) != (longlong *)(lVar2 + 0x20)) {
      BowserpTdiRemoveAddresses(param_1);
    }
    BowserDeleteGenericTable(lVar2 + 0x48);
    BowserDeleteGenericTable(lVar2 + 0x90);
    if (*(undefined8 **)(lVar2 + 0x148) != (undefined8 *)0x0) {
      BowserFreeBrowserServerList(*(undefined8 **)(lVar2 + 0x148),*(uint *)(lVar2 + 0x150));
    }
    ExFreePoolWithTag(lVar2);
  }
  if (*(undefined8 **)(param_1 + 0x38) != (undefined8 *)0x0) {
    BowserDereferenceDomain(*(undefined8 **)(param_1 + 0x38));
  }
  ExDeleteResourceLite(param_1 + 0x410);
  ExDeleteResourceLite(param_1 + 0x2f8);
  ExDeleteResourceLite(param_1 + 0x68);
  ExDeleteResourceLite(param_1 + 0xd0);
  BowserUninitializeIrpQueue((longlong *)(param_1 + 0x378),(undefined1 *)0x0);
  BowserUninitializeIrpQueue((longlong *)(param_1 + 0x388),(undefined1 *)0x0);
  BowserUninitializeIrpQueue((longlong *)(param_1 + 0x398),local_res8);
  BowserUninitializeIrpQueue((longlong *)(param_1 + 0x3a8),(undefined1 *)0x0);
  BowserUninitializeIrpQueue((longlong *)(param_1 + 0x3b8),(undefined1 *)0x0);
  BowserUninitializeIrpQueue((longlong *)(param_1 + 0x3c8),(undefined1 *)0x0);
  BowserUninitializeDatagramQueue((longlong *)(param_1 + 0x3d8));
  if (local_res8[0] != '\0') {
    BowserDeactivateScavengerTimer();
  }
  ExFreePoolWithTag(param_1,0);
  ExReleaseResourceLite(&BowserTransportDatabaseResource);
  return;
}



===== BowserDeleteGenericTable @ 140015e6c =====

void BowserDeleteGenericTable(undefined8 param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  longlong lVar5;
  
  do {
    lVar5 = RtlEnumerateGenericTable(param_1,1);
    if (lVar5 == 0) {
      return;
    }
    plVar1 = (longlong *)(lVar5 + 0x10);
    lVar2 = *plVar1;
    if (lVar2 != 0) {
      if ((*(longlong **)(lVar2 + 8) != plVar1) ||
         (plVar3 = *(longlong **)(lVar5 + 0x18), (longlong *)*plVar3 != plVar1)) {
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3);
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      *plVar3 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar3;
      *plVar1 = 0;
      *(undefined8 *)(lVar5 + 0x18) = 0;
    }
    BowserDereferenceName(*(longlong *)(lVar5 + 0x20));
    RtlDeleteElementGenericTable(param_1,lVar5);
  } while( true );
}



===== BowserReferenceName @ 140015f00 =====

void BowserReferenceName(longlong param_1)

{
  ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  ExReleaseResourceLite(&BowserTransportDatabaseResource);
  return;
}



===== BowserSetElectionCriteria @ 140015f44 =====

int BowserSetElectionCriteria(longlong param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  ulonglong uVar4;
  
  *(undefined4 *)(param_1 + 0x104) = 0;
  uVar4 = BowserTimeUp();
  *(int *)(param_1 + 0x10c) = (int)uVar4;
  *(uint *)(param_1 + 0x114) = (-(uint)(DAT_14000d2a6 != '\0') & 0x10000000) + 0x10000000 | 0x10f00;
  if (DAT_14000d2a5 != '\0') {
    iVar1 = RtlNumberGenericTableElements(param_1 + 0x90);
    iVar2 = RtlNumberGenericTableElements(param_1 + 0x48);
    if (iVar2 + iVar1 + *(int *)(param_1 + 0x44) != 0) {
      *(uint *)(param_1 + 0x114) = *(uint *)(param_1 + 0x114) | 2;
    }
  }
  if (*(char *)(param_1 + 0x15c) != '\0') {
    *(uint *)(param_1 + 0x114) = *(uint *)(param_1 + 0x114) | 0x88;
  }
  if (*(int *)(param_1 + 0xf8) == 3) {
    *(uint *)(param_1 + 0x114) = *(uint *)(param_1 + 0x114) | 4;
  }
  else if (*(char *)(param_1 + 0x15c) == '\0') {
    if ((*(int *)(param_1 + 0xf8) == 2) || (DAT_14000d2a6 != '\0')) {
      *(uint *)(param_1 + 0x114) = *(uint *)(param_1 + 0x114) | 1;
      uVar3 = RtlRandom(&BowserRandomSeed);
      iVar1 = uVar3 % 400 + 200;
    }
    else {
      uVar3 = RtlRandom(&BowserRandomSeed);
      iVar1 = uVar3 % 0x898 + 800;
    }
    goto LAB_140016077;
  }
  iVar1 = 100;
LAB_140016077:
  if (*(char *)(param_1 + 0x15a) != '\0') {
    *(uint *)(param_1 + 0x114) = *(uint *)(param_1 + 0x114) | 0x20;
  }
  return iVar1;
}



===== EnumerateServersWorker @ 14001609c =====

undefined8 EnumerateServersWorker(longlong param_1,uint *param_2)

{
  longlong lVar1;
  char cVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong lVar5;
  uint uVar6;
  undefined8 local_res10;
  
  lVar1 = *(longlong *)(param_1 + 8);
  ExAcquireResourceSharedLite(param_1 + 0x68,1);
  lVar5 = *(longlong *)(param_2 + 6);
  if (lVar5 == 0) {
    lVar5 = *(longlong *)(param_1 + 0x38) + 0x58;
  }
  local_res10 = 0;
  uVar6 = 1;
  do {
    lVar3 = lVar1 + 0x90;
    if (param_2[4] != 0x80000000) {
      lVar3 = lVar1 + 0x48;
    }
    lVar3 = RtlEnumerateGenericTableWithoutSplaying(lVar3,&local_res10);
    if (lVar3 == 0) {
      ExReleaseResourceLite(param_1 + 0x68);
      return 0;
    }
    if ((param_2[0x13] < uVar6) && ((param_2[4] & *(uint *)(lVar3 + 0x4c)) != 0)) {
      if (param_2[4] != 0x80000000) {
        cVar2 = RtlEqualUnicodeString(lVar5,*(longlong *)(lVar3 + 0x20) + 0x28,1);
        if (cVar2 == '\0') goto LAB_1400161b8;
      }
      param_2[0xe] = param_2[0xe] + 1;
      uVar4 = PackServerAnnouncement
                        (*param_2,param_2[4],(ulonglong *)(param_2 + 8),(ulonglong *)(param_2 + 10),
                         *(longlong *)(param_2 + 0x10),lVar3,(int *)(param_2 + 0xf));
      if ((char)uVar4 != '\0') {
        param_2[0xd] = param_2[0xd] + 1;
        param_2[0x12] = uVar6;
      }
    }
LAB_1400161b8:
    uVar6 = uVar6 + 1;
  } while( true );
}



===== BowserEnumerateServers @ 140016200 =====

undefined8
BowserEnumerateServers
          (uint param_1,undefined8 param_2,undefined4 *param_3,undefined4 param_4,byte *param_5,
          ushort *param_6,undefined8 param_7,void *param_8,uint param_9,int *param_10,int *param_11,
          undefined4 *param_12,longlong param_13)

{
  void *_Src;
  undefined8 uVar1;
  longlong lVar2;
  uint local_78 [2];
  undefined8 local_70;
  undefined4 local_68;
  undefined4 local_64;
  undefined8 local_60;
  void *local_58;
  longlong local_50;
  uint local_48;
  undefined8 local_44;
  undefined4 local_3c;
  longlong local_38;
  undefined4 local_30;
  undefined4 local_2c;
  
  local_78[1] = 0;
  local_64 = 0;
  _Src = (void *)ExAllocatePool2(0x100,param_9,0x6573424c);
  if (_Src == (void *)0x0) {
    uVar1 = 0xc000009a;
  }
  else {
    local_50 = (ulonglong)param_9 + (longlong)_Src;
    local_44 = 0;
    local_3c = 0;
    local_30 = 0;
    local_2c = *param_3;
    local_60 = param_7;
    local_48 = param_9;
    local_38 = (longlong)_Src + (param_13 - (longlong)param_8);
    local_78[0] = param_1;
    local_70 = param_2;
    local_68 = param_4;
    local_58 = _Src;
    if (param_5 == (byte *)0x0) {
      ExFreePoolWithTag(_Src,0);
      uVar1 = 0xc000000d;
    }
    else {
      lVar2 = BowserFindTransport(param_5,param_6);
      if (lVar2 == 0) {
        ExFreePoolWithTag(_Src,0);
        uVar1 = 0xc0000034;
      }
      else {
        EnumerateServersWorker(lVar2,local_78);
        BowserDereferenceTransport(lVar2);
        *param_10 = (int)local_44;
        *param_11 = local_44._4_4_;
        *param_12 = local_3c;
        *param_3 = local_30;
        memcpy(param_8,_Src,(ulonglong)param_9);
        ExFreePoolWithTag(_Src,0);
        uVar1 = 0x105;
        if (*param_10 == *param_11) {
          uVar1 = 0;
        }
      }
    }
  }
  return uVar1;
}



===== BowserGetBackupListWorker @ 1400163e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void BowserGetBackupListWorker(longlong param_1)

{
  char *_Dst;
  byte bVar1;
  byte *pbVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  int iVar6;
  int iVar7;
  char *_Src;
  undefined8 uVar8;
  undefined8 *puVar9;
  ushort uVar10;
  char cVar11;
  uint uVar12;
  longlong *plVar13;
  ulonglong uVar14;
  uint uVar15;
  undefined1 auStackY_108 [32];
  ushort local_c8;
  char *local_a8;
  char *local_a0;
  undefined8 local_98;
  void *pvStack_90;
  ulonglong local_88;
  longlong lStack_80;
  undefined8 local_78;
  undefined1 *puStack_70;
  ulonglong local_68;
  longlong local_60;
  longlong local_58;
  undefined1 local_50 [32];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_108;
  pbVar2 = *(byte **)(param_1 + 0x28);
  lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x18);
  local_a0 = (char *)0x0;
  local_98 = 0;
  pvStack_90 = (void *)0x0;
  lStack_80 = param_1 + 0x4c;
  local_88 = (ulonglong)CONCAT22(*(undefined2 *)(param_1 + 0x48),*(undefined2 *)(param_1 + 0x48));
  puStack_70 = local_50;
  local_78 = 0x200000;
  local_60 = lVar3;
  local_58 = param_1;
  RtlInitAnsiString(&local_98,param_1 + 0x38);
  iVar6 = RtlOemStringToUnicodeString(&local_78,&local_98,0);
  if (iVar6 < 0) {
    BowserLogIllegalName(iVar6,pvStack_90,(ushort)local_98);
  }
  else {
    ExAcquireResourceSharedLite(lVar3 + 0xd0,1);
    if (*(int *)(*(longlong *)(lVar3 + 8) + 0xf8) == 3) {
      ExAcquireResourceSharedLite(lVar3 + 0x68,1);
      local_a8 = (char *)0x0;
      lVar4 = *(longlong *)(lVar3 + 8);
      _Src = (char *)ExAllocatePool2(0x102,0x400,0x7262424c);
      local_a0 = _Src;
      if (_Src != (char *)0x0) {
        _Src[0] = '\n';
        _Src[1] = '\0';
        *(undefined4 *)(_Src + 2) = *(undefined4 *)(pbVar2 + 1);
        _Dst = _Src + 6;
        local_a8 = _Dst;
        memcpy(_Dst,*(void **)(*(longlong *)(lVar3 + 0x38) + 0xb0),
               (ulonglong)*(ushort *)(*(longlong *)(lVar3 + 0x38) + 0xaa));
        local_a8 = _Dst + *(ushort *)(*(longlong *)(lVar3 + 0x38) + 0xaa);
        cVar11 = '\x01';
        if (BowserSkuBasedUserMax < *(uint *)(*(longlong *)(lVar3 + 8) + 0x44)) {
          bVar1 = *pbVar2;
          uVar10 = (ushort)bVar1;
          local_c8 = (ushort)bVar1;
          plVar5 = *(longlong **)(lVar4 + 0xd8);
          plVar13 = plVar5;
          iVar6 = *(int *)(lVar4 + 0xe8);
          do {
            if ((uVar10 == 0) || (iVar6 == 0)) break;
            if ((((*(uint *)((longlong)plVar13 + 0x3c) & 0x18) != 0) &&
                (0x10e < *(ushort *)(plVar13 + 3))) &&
               (((*(char *)(lVar4 + 0x15a) == '\0' ||
                 ((*(uint *)((longlong)plVar13 + 0x3c) >> 0xc & 1) != 0)) &&
                (iVar7 = _wcsicmp((wchar_t *)((longlong)plVar13 + 0x1a),
                                  (wchar_t *)(*(longlong *)(lVar3 + 0x38) + 0x68)),
                uVar10 = local_c8, iVar7 != 0)))) {
              uVar8 = AddBackupToBackupList
                                ((longlong *)&local_a8,(longlong)_Src,(longlong)(plVar13 + -2));
              if ((int)uVar8 < 0) break;
              cVar11 = cVar11 + '\x01';
              local_c8 = local_c8 - 1;
              uVar10 = local_c8;
            }
            plVar13 = (longlong *)*plVar13;
            if (plVar13 == (longlong *)(lVar4 + 0xd8)) {
              plVar13 = (longlong *)*plVar13;
            }
            iVar6 = iVar6 + -1;
          } while (plVar13 != plVar5);
          plVar5 = *(longlong **)(lVar4 + 0xd8);
          plVar13 = plVar5;
          iVar6 = *(int *)(lVar4 + 0xe8);
          do {
            if ((uVar10 == 0) || (iVar6 == 0)) break;
            if (((*(char *)(lVar4 + 0x15a) == '\0') ||
                ((*(uint *)((longlong)plVar13 + 0x3c) & 0x1000) != 0)) &&
               (((0x10e < *(ushort *)(plVar13 + 3) &&
                 ((*(uint *)((longlong)plVar13 + 0x3c) & 0x18) == 0)) &&
                (iVar7 = _wcsicmp((wchar_t *)((longlong)plVar13 + 0x1a),
                                  (wchar_t *)(*(longlong *)(lVar3 + 0x38) + 0x68)),
                uVar10 = local_c8, iVar7 != 0)))) {
              uVar8 = AddBackupToBackupList
                                ((longlong *)&local_a8,(longlong)_Src,(longlong)(plVar13 + -2));
              if ((int)uVar8 < 0) break;
              cVar11 = cVar11 + '\x01';
              local_c8 = local_c8 - 1;
              uVar10 = local_c8;
            }
            plVar13 = (longlong *)*plVar13;
            if (plVar13 == (longlong *)(lVar4 + 0xd8)) {
              plVar13 = (longlong *)*plVar13;
            }
            iVar6 = iVar6 + -1;
          } while (plVar13 != plVar5);
        }
        _Src[1] = cVar11;
        uVar15 = (int)local_a8 - (int)_Src;
        uVar14 = (ulonglong)uVar15 + 0x11;
        local_68 = (ulonglong)uVar15 + 0x56;
        if ((uVar14 <= local_68) && (local_68 < 0x100000000)) {
          uVar12 = (uint)local_68;
          puVar9 = (undefined8 *)ExAllocatePool2(0x40,local_68 & 0xffffffff,0x686d424c);
          if (puVar9 != (undefined8 *)0x0) {
            *(undefined4 *)puVar9 = 0x424d53ff;
            *(undefined1 *)((longlong)puVar9 + 4) = 0x25;
            *(undefined1 *)(puVar9 + 4) = 0x11;
            *(short *)((longlong)puVar9 + 0x23) = (short)uVar15;
            *(undefined4 *)((longlong)puVar9 + 0x2d) = 1000;
            *(short *)((longlong)puVar9 + 0x37) = (short)uVar15;
            *(undefined2 *)((longlong)puVar9 + 0x39) = 0x56;
            *(undefined1 *)((longlong)puVar9 + 0x3b) = 3;
            *(undefined4 *)((longlong)puVar9 + 0x3d) = 0x10001;
            *(undefined2 *)((longlong)puVar9 + 0x41) = 2;
            *(short *)((longlong)puVar9 + 0x43) = (short)uVar14;
            builtin_strncpy((char *)((longlong)puVar9 + 0x45),"\\MAILSLO",8);
            builtin_strncpy((char *)((longlong)puVar9 + 0x4d),"T\\BROWSE",8);
            *(undefined1 *)((longlong)puVar9 + 0x55) = 0;
            memcpy((void *)((longlong)puVar9 + 0x56),_Src,(ulonglong)uVar15);
            BowserSendDatagram(lVar3,(longlong)&local_78,1,puVar9,uVar12,'\x01',(ushort *)&local_88,
                               *_Src == '\x0f');
          }
        }
      }
      if (_Src != (char *)0x0) {
        ExFreePoolWithTag(_Src,0);
      }
      ExReleaseResourceLite(lVar3 + 0x68);
    }
    ExReleaseResourceLite(lVar3 + 0xd0);
  }
  BowserDereferenceTransportName(*(longlong *)(param_1 + 0x20));
  BowserDereferenceTransport(lVar3);
  LOCK();
  BowserPostedDatagramCount = BowserPostedDatagramCount + -1;
  UNLOCK();
  ExFreePoolWithTag(param_1,0);
  return;
}



===== BowserBecomeBackupWorker @ 140016940 =====

void BowserBecomeBackupWorker(longlong param_1)

{
  longlong lVar1;
  char *pcVar2;
  char cVar3;
  int iVar4;
  longlong lVar5;
  longlong in_stack_ffffffffffffffb0;
  undefined8 local_48;
  longlong local_40;
  undefined8 local_38;
  void *pvStack_30;
  
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x18);
  local_48 = 0;
  local_38 = 0;
  pvStack_30 = (void *)0x0;
  lVar5 = *(longlong *)(lVar1 + 8);
  pcVar2 = *(char **)(param_1 + 0x28);
  local_40 = 0;
  ExAcquireResourceExclusiveLite(lVar1 + 0xd0,1);
  if (*(int *)(param_1 + 0x30) != 0) {
    cVar3 = IsZeroTerminated(pcVar2,*(int *)(param_1 + 0x30));
    if (cVar3 != '\0') {
      RtlInitAnsiString(&local_38,pcVar2);
      iVar4 = RtlOemStringToUnicodeString(&local_48,&local_38,1);
      if (iVar4 < 0) {
        BowserLogIllegalName(iVar4,pvStack_30,(ushort)local_38);
      }
      else {
        cVar3 = RtlEqualUnicodeString(&local_48);
        if (cVar3 != '\0') {
          if (*(int *)(lVar5 + 0xf8) == 3) {
            BowserWriteErrorLogEntry
                      (0x80001f44,0xc0000001,(void *)0x0,0,0,in_stack_ffffffffffffffb0);
          }
          else if (*(char *)(lVar5 + 0x15d) == '\0') {
            lVar5 = BowserDequeueQueuedIrp((longlong *)(lVar1 + 0x378),'\0');
            if (lVar5 != 0) {
              *(undefined8 *)(lVar5 + 0x38) = 0;
              *(undefined4 *)(lVar5 + 0x30) = 0;
              IofCompleteRequest(lVar5,0);
            }
          }
        }
      }
    }
  }
  ExReleaseResourceLite(lVar1 + 0xd0);
  BowserDereferenceTransportName(*(longlong *)(param_1 + 0x20));
  BowserDereferenceTransport(lVar1);
  if (local_40 != 0) {
    RtlFreeUnicodeString(&local_48);
  }
  LOCK();
  BowserPostedDatagramCount = BowserPostedDatagramCount + -1;
  UNLOCK();
  ExFreePoolWithTag(param_1,0);
  return;
}



===== UnbindFromTransport @ 140016b00 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 UnbindFromTransport(undefined8 param_1,undefined8 param_2,ulonglong param_3,uint param_4)

{
  ushort uVar1;
  longlong lVar2;
  undefined8 uVar3;
  bool bVar4;
  undefined1 auStack_78 [32];
  undefined1 local_58;
  ushort local_50 [4];
  ulonglong uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_78;
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  uStack_48 = 0;
  local_58 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_20 = 0;
  uStack_18 = 0;
  lVar2 = IoGetCurrentProcess();
  bVar4 = lVar2 != BowserFspProcess;
  if (bVar4) {
    KeStackAttachProcess(BowserFspProcess,&local_40);
    local_58 = 1;
  }
  if ((0x3c < param_4) && (*(int *)(param_3 + 4) == 7)) {
    uVar1 = *(ushort *)(param_3 + 0x38);
    local_50[1] = uVar1;
    local_50[0] = uVar1;
    uStack_48 = param_3 + 0x3c;
    if ((uVar1 != 0) &&
       (((uVar1 <= param_4 && (param_3 <= uStack_48)) &&
        (uStack_48 <= ((ulonglong)param_4 - (ulonglong)(uint)uVar1) + param_3)))) {
      if (*(ushort *)(param_3 + 0x28) == 0) {
        *(undefined8 *)(param_3 + 0x30) = 0;
        *(undefined2 *)(param_3 + 0x2a) = 0;
      }
      else {
        uVar1 = *(ushort *)(param_3 + 0x2a);
        if (((param_4 < uVar1) || (uVar1 < *(ushort *)(param_3 + 0x28))) ||
           ((*(ulonglong *)(param_3 + 0x30) < param_3 ||
            (((ulonglong)param_4 - (ulonglong)uVar1) + param_3 < *(ulonglong *)(param_3 + 0x30)))))
        goto LAB_140016b64;
      }
      uVar3 = 0;
      lVar2 = BowserFindTransport((byte *)local_50,(ushort *)(param_3 + 0x28));
      if (lVar2 == 0) {
        uVar3 = 0xc0000034;
      }
      else {
        BowserDeleteTransport(lVar2);
        BowserDereferenceTransport(lVar2);
      }
      goto LAB_140016c13;
    }
  }
LAB_140016b64:
  uVar3 = 0xc000000d;
LAB_140016c13:
  if (bVar4) {
    KeUnstackDetachProcess(&local_40);
  }
  return uVar3;
}



===== GetBrowserServerList @ 140016c80 =====

int GetBrowserServerList
              (ulonglong param_1,undefined1 param_2,undefined1 param_3,ulonglong param_4,
              uint *param_5,ulonglong param_6,uint param_7,longlong param_8)

{
  uint uVar1;
  void *pvVar2;
  ushort uVar3;
  uint uVar4;
  ulonglong uVar5;
  bool bVar6;
  bool bVar7;
  char cVar8;
  int iVar9;
  uint uVar10;
  longlong lVar11;
  longlong lVar12;
  undefined2 *_Src;
  ulonglong *puVar13;
  void *_Dst;
  undefined2 local_res18 [8];
  uint local_5c;
  undefined8 *local_58;
  uint local_50;
  ulonglong local_48;
  ulonglong uStack_40;
  longlong local_38;
  void *local_30;
  
  local_res18[0] = CONCAT11(local_res18[0]._1_1_,param_3);
  local_48 = 0;
  uStack_40 = 0;
  lVar12 = 0;
  local_38 = 0;
  local_5c = 0;
  local_58 = (undefined8 *)0x0;
  bVar7 = false;
  _Dst = (void *)(param_6 + param_7);
  uVar4 = *param_5;
  if ((((0x5f < uVar4) && (*(int *)(param_4 + 4) == 7)) && (*(ushort *)(param_4 + 0x18) != 0)) &&
     (((uVar5 = *(ulonglong *)(param_4 + 0x20), uVar5 != 0 && (0x1f < param_7)) &&
      ((param_6 & 7) == 0)))) {
    uVar3 = *(ushort *)(param_4 + 0x48);
    if (uVar3 == 0) {
      local_48 = 0;
      uStack_40 = 0;
    }
    else {
      uStack_40 = param_4 + 0x4c;
      local_48 = (ulonglong)CONCAT22(uVar3,uVar3);
      if (((uVar4 < uVar3) || (uStack_40 < param_4)) ||
         (((ulonglong)uVar4 - (ulonglong)uVar3) + param_4 < uStack_40)) goto LAB_14001705d;
    }
    uVar3 = *(ushort *)(param_4 + 0x1a);
    if ((((uVar3 <= uVar4) && (*(ushort *)(param_4 + 0x18) <= uVar3)) && (param_4 <= uVar5)) &&
       (uVar5 <= ((ulonglong)uVar4 - (ulonglong)uVar3) + param_4)) {
      local_38 = BowserFindTransport((byte *)(param_4 + 0x18),(ushort *)&local_48);
      if ((local_38 == 0) &&
         (lVar12 = BowserFindTransport((byte *)(param_4 + 0x18),(ushort *)0x0), local_38 = lVar12,
         lVar12 == 0)) {
        iVar9 = -0x3fffffcc;
        bVar6 = false;
      }
      else {
        lVar12 = local_38;
        lVar11 = *(longlong *)(local_38 + 8);
        cVar8 = ExAcquireResourceSharedLite(local_38 + 0x2f8,param_2);
        if (cVar8 == '\0') {
          iVar9 = 0x103;
          bVar6 = false;
        }
        else {
          if (((short)local_48 == 0) ||
             (cVar8 = RtlEqualUnicodeString(&local_48,*(longlong *)(lVar12 + 0x38) + 0x58,1),
             cVar8 != '\0')) {
            bVar6 = true;
            bVar7 = true;
            local_58 = *(undefined8 **)(lVar11 + 0x148);
            local_5c = *(uint *)(lVar11 + 0x150);
          }
          else {
            bVar6 = false;
          }
          if ((((!bVar6) || (local_5c == 0)) || (!bVar6)) || (*(char *)(param_4 + 0x4a) != '\0')) {
            ExReleaseResourceLite(lVar12 + 0x2f8);
            bVar6 = false;
            cVar8 = ExAcquireResourceExclusiveLite(lVar12 + 0x2f8,param_2);
            if (cVar8 == '\0') {
              iVar9 = 0x103;
              goto LAB_14001714b;
            }
            bVar6 = true;
            if ((*(char *)(param_4 + 0x4a) != '\0') &&
               (*(undefined8 **)(lVar11 + 0x148) != (undefined8 *)0x0)) {
              BowserFreeBrowserServerList
                        (*(undefined8 **)(lVar11 + 0x148),*(uint *)(lVar11 + 0x150));
              *(undefined4 *)(lVar11 + 0x150) = 0;
              *(undefined8 *)(lVar11 + 0x148) = 0;
            }
            puVar13 = &local_48;
            if ((short)local_48 == 0) {
              puVar13 = (ulonglong *)0x0;
            }
            iVar9 = BowserGetBrowserServerList
                              (param_1,lVar12,(longlong)puVar13,(longlong *)&local_58,&local_5c);
            if (iVar9 < 0) goto LAB_14001714b;
            if (bVar7) {
              if (*(undefined8 **)(lVar11 + 0x148) != (undefined8 *)0x0) {
                BowserFreeBrowserServerList
                          (*(undefined8 **)(lVar11 + 0x148),*(uint *)(lVar11 + 0x150));
              }
              *(undefined8 **)(lVar11 + 0x148) = local_58;
              *(uint *)(lVar11 + 0x150) = local_5c;
            }
          }
          if (local_5c != 0) {
            bVar6 = true;
            *(undefined8 *)(param_4 + 0x38) = 0;
            *(undefined4 *)(param_4 + 0x40) = 0;
            local_50 = 0;
            while( true ) {
              uVar4 = local_50;
              uVar10 = local_5c;
              if (3 < local_5c) {
                uVar10 = 3;
              }
              if (uVar10 <= local_50) break;
              *(int *)(param_4 + 0x3c) = *(int *)(param_4 + 0x3c) + 1;
              lVar11 = -1;
              do {
                lVar11 = lVar11 + 1;
              } while (*(short *)(local_58[local_50] + lVar11 * 2) != 0);
              *(int *)(param_4 + 0x40) = *(int *)(param_4 + 0x40) + (int)lVar11 * 2;
              _Src = (undefined2 *)local_58[local_50];
              pvVar2 = (void *)(param_6 + (ulonglong)(local_50 + 1) * 8);
              if ((pvVar2 < _Dst) && (bVar6)) {
                lVar11 = -1;
                do {
                  lVar11 = lVar11 + 1;
                } while (_Src[lVar11] != 0);
                iVar9 = (int)_Dst;
                local_res18[0] = 0;
                uVar10 = (int)lVar11 * 2;
                if (_Src == (undefined2 *)0x0) {
                  _Src = local_res18;
                  uVar10 = 0;
                }
                uVar1 = uVar10 + 2;
                _Dst = (void *)((ulonglong)_Dst & 0xfffffffffffffffe);
                local_30 = _Dst;
                if ((_Dst < pvVar2) || ((uint)(iVar9 - (int)pvVar2) < uVar1)) goto LAB_140016fc7;
                _Dst = (void *)((longlong)_Dst - (ulonglong)uVar1);
                local_30 = _Dst;
                memcpy(_Dst,_Src,(ulonglong)uVar1 - 2);
                *(undefined2 *)((longlong)_Dst + (ulonglong)(uVar10 >> 1) * 2) = 0;
                if (uVar1 == 0) goto LAB_140016fc7;
                *(longlong *)(param_6 + (ulonglong)uVar4 * 8) = (longlong)_Dst - param_8;
                *(int *)(param_4 + 0x38) = *(int *)(param_4 + 0x38) + 1;
              }
              else {
LAB_140016fc7:
                bVar6 = false;
              }
              local_50 = uVar4 + 1;
            }
          }
          bVar6 = true;
          *param_5 = 0x60;
          iVar9 = 0;
        }
      }
      goto LAB_14001714b;
    }
  }
LAB_14001705d:
  bVar6 = false;
  iVar9 = -0x3ffffff3;
LAB_14001714b:
  if (lVar12 != 0) {
    if (bVar6) {
      ExReleaseResourceLite(lVar12 + 0x2f8);
    }
    BowserDereferenceTransport(lVar12);
  }
  if (((-1 < iVar9) && (!bVar7)) && (local_58 != (undefined8 *)0x0)) {
    BowserFreeBrowserServerList(local_58,local_5c);
  }
  return iVar9;
}



===== BowserProcessDomainAnnouncement @ 1400171c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void BowserProcessDomainAnnouncement(longlong param_1)

{
  short sVar1;
  longlong lVar2;
  longlong lVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  void *_Dst;
  longlong lVar7;
  undefined1 auStack_148 [32];
  char local_128 [8];
  undefined8 local_120;
  undefined1 *puStack_118;
  undefined8 local_110;
  undefined8 uStack_108;
  void *local_100;
  longlong local_f8;
  longlong local_f0;
  undefined2 local_e8;
  short local_e6;
  undefined8 local_d8;
  undefined8 uStack_d0;
  longlong local_c8;
  undefined1 local_be [34];
  undefined4 local_9c;
  undefined1 local_98;
  undefined1 local_97;
  undefined2 local_96;
  undefined4 local_94;
  undefined1 local_8c [100];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_148;
  memset(&local_e8,0,0xc0);
  local_120 = 0;
  puStack_118 = (undefined1 *)0x0;
  local_110 = 0;
  uStack_108 = 0;
  local_128[0] = '\0';
  lVar2 = *(longlong *)(param_1 + 0x28);
  lVar3 = *(longlong *)(lVar2 + 0x18);
  local_f8 = lVar3;
  local_f0 = lVar2;
  if (*(int *)(*(longlong *)(lVar3 + 8) + 0xf8) == 3) {
    puStack_118 = local_be;
    local_120 = 0x220000;
    RtlInitAnsiString(&local_110,param_1 + 0x31);
    iVar5 = RtlOemStringToUnicodeString(&local_120,&local_110,0);
    if (-1 < iVar5) {
      puStack_118 = local_8c;
      local_120 = CONCAT44(local_120._4_4_,0x620000);
      RtlInitAnsiString(&local_110,param_1 + 0x4c);
      iVar5 = RtlOemStringToUnicodeString(&local_120,&local_110,0);
      if (-1 < iVar5) {
        local_e8 = 5;
        local_e6 = (short)local_120 + 0x60;
        local_9c = *(undefined4 *)(param_1 + 0x48);
        local_98 = *(undefined1 *)(param_1 + 0x44);
        local_97 = *(undefined1 *)(param_1 + 0x45);
        local_c8 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x10) + 0x10);
        local_96 = *(undefined2 *)(param_1 + 0x46);
        local_d8 = 0;
        uStack_d0 = 0;
        local_94 = 0;
        lVar7 = *(longlong *)(lVar3 + 8);
        BowserFreeViewBuffer(param_1);
        ExAcquireResourceExclusiveLite(lVar3 + 0x68,1);
        lVar7 = lVar7 + 0x90;
        _Dst = (void *)RtlInsertElementGenericTable(lVar7,&local_e8,(int)local_e6,local_128);
        local_100 = _Dst;
        if (_Dst == (void *)0x0) {
          _DAT_14000d2d4 = _DAT_14000d2d4 + 1;
        }
        else {
          BowserReferenceName(local_c8);
          if (local_128[0] == '\0') {
            BowserDereferenceName(*(longlong *)((longlong)_Dst + 0x20));
            sVar1 = *(short *)((longlong)_Dst + 2);
            if (sVar1 < local_e6) {
              cVar4 = RtlDeleteElementGenericTable(lVar7,_Dst);
              if (cVar4 != '\0') {
                _Dst = (void *)RtlInsertElementGenericTable(lVar7,&local_e8,(int)local_e6,local_128)
                ;
                local_100 = _Dst;
                if (_Dst == (void *)0x0) {
                  _DAT_14000d2d4 = _DAT_14000d2d4 + 1;
                  goto LAB_14001747b;
                }
              }
            }
            else {
              memcpy(_Dst,&local_e8,(longlong)local_e6);
              *(short *)((longlong)_Dst + 2) = sVar1;
            }
          }
          else {
            uVar6 = RtlNumberGenericTableElements(lVar7);
            if (BowserMaximumBrowseEntries < uVar6) {
              BowserDereferenceName(*(longlong *)((longlong)_Dst + 0x20));
              RtlDeleteElementGenericTable(lVar7,_Dst);
              _DAT_14000d2d4 = _DAT_14000d2d4 + 1;
              goto LAB_14001747b;
            }
          }
          uVar6 = (uint)*(ushort *)((longlong)_Dst + 0x52);
          lVar7 = BowserGetCurrentTime();
          *(uint *)((longlong)_Dst + 4) = (int)lVar7 + uVar6 * 3;
        }
LAB_14001747b:
        ExReleaseResourceLite(lVar3 + 0x68);
        goto LAB_140017495;
      }
    }
  }
  BowserFreeViewBuffer(param_1);
LAB_140017495:
  BowserDereferenceTransportName(lVar2);
  BowserDereferenceTransport(lVar3);
  return;
}



===== HandleElectionWorker @ 1400174e0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void HandleElectionWorker(longlong param_1)

{
  byte *pbVar1;
  byte bVar2;
  char cVar3;
  char cVar4;
  longlong lVar5;
  byte *pbVar6;
  longlong lVar7;
  longlong lVar8;
  uint uVar9;
  ulonglong uVar10;
  char *pcVar11;
  byte *pbVar12;
  uint uVar13;
  undefined8 *puVar14;
  int iVar15;
  longlong lVar16;
  uint uVar17;
  bool bVar18;
  uint local_res10;
  undefined8 local_a8;
  longlong local_a0;
  int local_98;
  undefined8 local_90;
  void *pvStack_88;
  uint local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  uint local_6c;
  int local_68;
  uint local_64;
  int local_60;
  byte *local_58;
  longlong local_50;
  longlong local_48;
  longlong local_40;
  
  lVar5 = *(longlong *)(param_1 + 0x20);
  pbVar6 = *(byte **)(param_1 + 0x28);
  uVar9 = *(uint *)(param_1 + 0x30);
  lVar7 = *(longlong *)(lVar5 + 0x18);
  local_90 = 0;
  pvStack_88 = (void *)0x0;
  local_a8 = 0;
  lVar8 = *(longlong *)(lVar7 + 8);
  local_50 = lVar7;
  local_48 = param_1;
  local_40 = lVar5;
  ExAcquireResourceExclusiveLite(lVar7 + 0xd0,1);
  local_a0 = 0;
  if (uVar9 < 0xe) goto LAB_1400178fd;
  pbVar1 = pbVar6 + 0xd;
  iVar15 = uVar9 - 0xd;
  local_58 = pbVar1;
  do {
    local_98 = iVar15 + -1;
    if (iVar15 == 0) goto LAB_1400178fd;
    bVar2 = *local_58;
    local_58 = local_58 + 1;
    iVar15 = local_98;
  } while (bVar2 != 0);
  _DAT_14000d2c8 = _DAT_14000d2c8 + 1;
  uVar10 = BowserTimeUp();
  *(int *)(lVar8 + 0x11c) = (int)uVar10;
  if ((*(int *)(lVar7 + 0x60) == 3) || (*(char *)(lVar8 + 0x15d) != '\0')) goto LAB_1400178fd;
  RtlInitString(&local_90,pbVar1);
  puVar14 = &local_90;
  local_68 = RtlOemStringToUnicodeString(&local_a8,puVar14,1);
  if (local_68 < 0) {
    BowserLogIllegalName(local_68,pvStack_88,(ushort)local_90);
    goto LAB_1400178fd;
  }
  if (BowserLogElectionPackets != '\0') {
    puVar14 = (undefined8 *)0x0;
    BowserWriteErrorLogEntry(0x1f4c,0,pbVar6,(ushort)uVar9,2,local_a0);
  }
  if (*(int *)(lVar7 + 0x60) == 2) {
    pcVar11 = (char *)(*(longlong *)(lVar7 + 0x38) + 0x98);
    lVar16 = (longlong)pbVar1 - (longlong)pcVar11;
    do {
      cVar3 = *pcVar11;
      cVar4 = pcVar11[lVar16];
      if (cVar3 != cVar4) break;
      pcVar11 = pcVar11 + 1;
    } while (cVar4 != '\0');
    if ((cVar3 == cVar4) || ((*(int *)(pbVar6 + 1) == 0 && (*pbVar1 == 0)))) goto LAB_1400178fd;
    if (*(int *)(lVar8 + 0xf8) == 3) {
      local_res10 = RtlRandom();
      puVar14 = (undefined8 *)((ulonglong)local_res10 / 100);
      local_res10 = local_res10 + (int)puVar14 * -100;
    }
    else {
      uVar9 = RtlRandom(&BowserRandomSeed);
      puVar14 = (undefined8 *)((ulonglong)uVar9 / 700);
      local_res10 = uVar9 + (int)puVar14 * -700 + 200;
    }
  }
  else {
    local_res10 = BowserSetElectionCriteria(lVar8);
  }
  uVar9 = *(uint *)(lVar8 + 0x10c);
  bVar18 = *pbVar6 == 0;
  local_64 = uVar9;
  if ((*pbVar6 == 1) &&
     (bVar18 = *(uint *)(pbVar6 + 1) < *(uint *)(lVar8 + 0x114),
     *(uint *)(pbVar6 + 1) == *(uint *)(lVar8 + 0x114))) {
    if (uVar9 != *(uint *)(pbVar6 + 5)) {
      bVar18 = *(uint *)(pbVar6 + 5) < uVar9;
      goto LAB_140017763;
    }
    pbVar12 = (byte *)(*(longlong *)(lVar7 + 0x38) + 0x10);
    lVar16 = (longlong)pbVar1 - (longlong)pbVar12;
    do {
      bVar2 = *pbVar12;
      puVar14 = (undefined8 *)(ulonglong)pbVar12[lVar16];
      uVar13 = (uint)pbVar12[lVar16];
      if (bVar2 != uVar13) break;
      pbVar12 = pbVar12 + 1;
    } while (uVar13 != 0);
    if (0 < (int)(bVar2 - uVar13)) goto LAB_14001779b;
LAB_1400177b7:
    if (*(uint *)(lVar8 + 0x104) < 0x1f) {
      *(ushort *)(lVar8 + 0x158) = *(ushort *)(lVar8 + 0x158) & 0xfffe;
      uVar13 = uVar9;
      uVar17 = local_res10;
      if (*(int *)(lVar7 + 0x60) != 2) {
        if ((*(int *)(lVar8 + 0x110) != 0) &&
           (uVar10 = BowserTimeUp(), (uint)((int)uVar10 - *(int *)(lVar8 + 0x110)) < 11000))
        goto LAB_1400178fd;
        *(undefined4 *)(lVar7 + 0x60) = 2;
        *(undefined4 *)(lVar8 + 0x108) = 0;
      }
      *(undefined4 *)(lVar8 + 0x100) = 4;
      iVar15 = *(int *)(lVar8 + 0x108);
      uVar10 = BowserTimeUp();
      local_60 = (int)uVar10 + (iVar15 - uVar13);
      if ((iVar15 == 0) || ((int)uVar17 < local_60)) {
        BowserStopTimer(lVar7 + 0x138);
        *(uint *)(lVar8 + 0x108) = uVar9 + local_res10;
        BowserStartTimer(lVar7 + 0x138,local_res10,BowserElectMaster,lVar7);
      }
      goto LAB_1400178fd;
    }
  }
  else {
LAB_140017763:
    if (bVar18) goto LAB_1400177b7;
LAB_14001779b:
    *(ushort *)(lVar8 + 0x158) = *(ushort *)(lVar8 + 0x158) | 1;
  }
  if (*(char *)(lVar8 + 0x15c) != '\0') {
    local_80 = (uint)*pbVar6;
    local_7c = *(undefined4 *)(pbVar6 + 1);
    local_78 = *(undefined4 *)(pbVar6 + 5);
    local_74 = 1;
    local_70 = *(undefined4 *)(lVar8 + 0x114);
    puVar14 = (undefined8 *)0x0;
    local_6c = uVar9;
    BowserWriteErrorLogEntry(0x40001f5b,0,&local_80,0x18,2,local_a0);
  }
  BowserLoseElection(lVar7,puVar14);
LAB_1400178fd:
  ExReleaseResourceLite(lVar7 + 0xd0);
  LOCK();
  BowserPostedCriticalDatagramCount = BowserPostedCriticalDatagramCount + -1;
  UNLOCK();
  ExFreePoolWithTag(param_1,0);
  if (local_a0 != 0) {
    RtlFreeUnicodeString(&local_a8);
  }
  BowserDereferenceTransportName(lVar5);
  BowserDereferenceTransport(lVar7);
  return;
}



===== BowserBindToTransport @ 140017970 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int BowserBindToTransport(undefined8 param_1,undefined8 param_2,short *param_3,uint param_4)

{
  ulonglong uVar1;
  char cVar2;
  ushort uVar3;
  int iVar4;
  longlong lVar5;
  undefined8 uVar6;
  short *psVar7;
  ulonglong uVar8;
  ushort uVar9;
  bool bVar10;
  undefined1 auStack_c8 [32];
  undefined1 local_a8;
  undefined8 local_a0;
  short *psStack_98;
  short *local_90;
  ushort local_88 [8];
  undefined8 local_78;
  undefined8 uStack_70;
  undefined1 local_68 [16];
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_c8;
  uVar1 = (ulonglong)param_4;
  local_a0 = 0;
  psStack_98 = (short *)0x0;
  local_88[0] = 0;
  local_88[1] = 0;
  local_88[2] = 0;
  local_88[3] = 0;
  local_88[4] = 0;
  local_88[5] = 0;
  local_88[6] = 0;
  local_88[7] = 0;
  local_a8 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  lVar5 = IoGetCurrentProcess();
  bVar10 = lVar5 != BowserFspProcess;
  if (bVar10) {
    KeStackAttachProcess(BowserFspProcess,&local_58);
    local_a8 = 1;
  }
  if ((0x3c < param_4) && (*(int *)(param_3 + 2) == 7)) {
    uVar9 = param_3[0x1c];
    uVar8 = (ulonglong)uVar9;
    local_a0._0_4_ = CONCAT22(uVar9,uVar9);
    psVar7 = param_3 + 0x1e;
    psStack_98 = psVar7;
    uVar6 = BowserValidUnicodeString((byte *)&local_a0);
    if (((int)uVar6 != 0) &&
       (((((short)uVar8 != 0 && ((uint)uVar8 <= param_4)) && (param_3 <= psVar7)) &&
        (psVar7 <= (short *)((uVar1 - uVar8) + (longlong)param_3))))) {
      local_78 = 0;
      uStack_70 = 0;
      RtlInitUnicodeString(&local_78,L"\\Device\\NetbiosSmb");
      cVar2 = RtlEqualUnicodeString(&local_a0,&local_78,1);
      if (cVar2 != '\0') {
        iVar4 = 0;
        goto LAB_140017b6b;
      }
      local_68 = *(undefined1 (*) [16])(param_3 + 0x14);
      uVar9 = local_68._0_2_;
      if (uVar9 != 0) {
        uVar3 = local_68._2_2_;
        if (((uVar3 <= param_4) && (uVar9 <= uVar3)) &&
           ((param_3 <= (ulonglong)local_68._8_8_ &&
            ((ulonglong)local_68._8_8_ <= (short *)((uVar1 - uVar3) + (longlong)param_3))))) {
          if (*(int *)(param_3 + 4) == 0) {
            lVar5 = 0;
LAB_140017b2b:
            RtlInitUnicodeString(local_88,lVar5);
            if ((uVar9 == 0) || (local_88[0] == 0)) {
              iVar4 = -0x3ffffede;
            }
            else {
              iVar4 = BowserTdiAllocateTransport((ushort *)&local_a0,(ushort *)local_68,local_88);
            }
            goto LAB_140017b6b;
          }
          local_90 = (short *)0x0;
          psVar7 = (short *)((longlong)psStack_98 + (local_a0 & 0xffff));
          if (((param_3 <= psVar7) && (psVar7 < (short *)(uVar1 + (longlong)param_3))) &&
             ((~(uint)psVar7 & 1) != 0)) {
            for (; local_90 = psVar7, psVar7 < (short *)(uVar1 + (longlong)param_3);
                psVar7 = psVar7 + 1) {
              if (*psVar7 == 0) {
                lVar5 = (longlong)psStack_98 + (local_a0 & 0xffff);
                goto LAB_140017b2b;
              }
            }
          }
        }
      }
    }
  }
  iVar4 = -0x3ffffff3;
LAB_140017b6b:
  if (bVar10) {
    KeUnstackDetachProcess(&local_58);
  }
  return iVar4;
}



===== BowserTdiAllocateTransport @ 140017be0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int BowserTdiAllocateTransport(ushort *param_1,ushort *param_2,ushort *param_3)

{
  longlong ***ppplVar1;
  longlong ****pppplVar2;
  code *pcVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  longlong ****pppplVar7;
  longlong ***ppplVar8;
  longlong **pplVar9;
  longlong ***ppplVar10;
  uint uVar11;
  uint uVar12;
  undefined1 *puVar13;
  bool bVar14;
  undefined1 auStack_148 [8];
  undefined1 auStack_140 [24];
  longlong ****local_128;
  ulonglong local_120;
  undefined4 local_118;
  undefined4 local_110;
  undefined4 local_108;
  undefined4 *local_100;
  undefined4 local_f8;
  undefined4 local_f0;
  undefined8 local_e8;
  undefined4 local_e0;
  undefined4 local_d8;
  undefined4 uStack_d4;
  undefined8 uStack_d0;
  undefined4 local_c8;
  undefined8 local_b8;
  undefined8 local_b0;
  longlong ***local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined4 local_78;
  undefined4 local_74;
  char local_70 [48];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_148;
  ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
  bVar14 = true;
  pppplVar7 = (longlong ****)BowserFindTransport((byte *)param_1,param_2);
  if (pppplVar7 == (longlong ****)0x0) {
    pppplVar7 = (longlong ****)ExAllocatePool2(0x40,0x478,0x7078424c);
    if (pppplVar7 == (longlong ****)0x0) {
      iVar5 = -0x3fffff66;
      ExReleaseResourceLite(&BowserTransportDatabaseResource);
      puVar13 = auStack_148;
      goto LAB_140018031;
    }
    *(undefined4 *)pppplVar7 = 0x4780002;
    *(undefined4 *)((longlong)pppplVar7 + 4) = 1;
    ExInitializeResourceLite(pppplVar7 + 0x82);
    ExInitializeRundownProtection(pppplVar7 + 0x7e);
    KeInitializeEvent(pppplVar7 + 0x7f,0,0);
    ExInitializeResourceLite(pppplVar7 + 0x5f);
    KeInitializeEvent(pppplVar7 + 0x6c,0,1);
    ExInitializeResourceLite(pppplVar7 + 0x1a);
    pppplVar2 = pppplVar7 + 0x6f;
    pppplVar7[0x70] = (longlong ***)pppplVar2;
    *pppplVar2 = (longlong ***)pppplVar2;
    pppplVar2 = pppplVar7 + 0x71;
    pppplVar7[0x72] = (longlong ***)pppplVar2;
    *pppplVar2 = (longlong ***)pppplVar2;
    pppplVar2 = pppplVar7 + 0x73;
    pppplVar7[0x74] = (longlong ***)pppplVar2;
    *pppplVar2 = (longlong ***)pppplVar2;
    pppplVar2 = pppplVar7 + 0x75;
    pppplVar7[0x76] = (longlong ***)pppplVar2;
    *pppplVar2 = (longlong ***)pppplVar2;
    pppplVar2 = pppplVar7 + 0x79;
    pppplVar7[0x7a] = (longlong ***)pppplVar2;
    *pppplVar2 = (longlong ***)pppplVar2;
    pppplVar2 = pppplVar7 + 0x77;
    pppplVar7[0x78] = (longlong ***)pppplVar2;
    *pppplVar2 = (longlong ***)pppplVar2;
    pppplVar2 = pppplVar7 + 0x7b;
    pppplVar7[0x7c] = (longlong ***)pppplVar2;
    *pppplVar2 = (longlong ***)pppplVar2;
    *(undefined4 *)(pppplVar7 + 0x7d) = 0;
    BowserInitializeTimer((longlong)(pppplVar7 + 0x27));
    BowserInitializeTimer((longlong)(pppplVar7 + 0x43));
    ExInitializeResourceLite(pppplVar7 + 0xd);
    ppplVar8 = (longlong ***)ExAllocatePool2(0x100,(ulonglong)*param_1 + 0x19e,0x7470424c);
    pppplVar7[1] = ppplVar8;
    if (ppplVar8 == (longlong ***)0x0) {
LAB_140018135:
      iVar5 = -0x3fffff66;
      ExReleaseResourceLite(&BowserTransportDatabaseResource);
      puVar13 = auStack_148;
    }
    else {
      ppplVar8[1] = (longlong **)pppplVar7;
      ppplVar1 = ppplVar8 + 2;
      *(undefined4 *)ppplVar8 = 0x1600008;
      ppplVar8[3] = (longlong **)ppplVar1;
      *ppplVar1 = (longlong **)ppplVar1;
      ppplVar10 = ppplVar8 + 4;
      local_128 = (longlong ****)0x0;
      ppplVar8[5] = (longlong **)ppplVar10;
      *ppplVar10 = (longlong **)ppplVar10;
      *(undefined4 *)(ppplVar8 + 0x1f) = 0;
      *(undefined4 *)((longlong)ppplVar8 + 0x154) = 0xffffffff;
      *(undefined1 *)((longlong)ppplVar8 + 0x15d) = 1;
      *(undefined1 *)((longlong)ppplVar8 + 0x15b) = 0;
      RtlInitializeGenericTable
                (ppplVar8 + 9,BowserCompareAnnouncement,BowserAllocateAnnouncement,
                 BowserFreeAnnouncement);
      local_128 = (longlong ****)0x0;
      RtlInitializeGenericTable
                (ppplVar8 + 0x12,BowserCompareAnnouncement,BowserAllocateAnnouncement,
                 BowserFreeAnnouncement);
      ppplVar10 = ppplVar8 + 0x1b;
      ppplVar8[0x1c] = (longlong **)ppplVar10;
      *ppplVar10 = (longlong **)ppplVar10;
      ppplVar8[0x28] = (longlong **)(ppplVar8 + 0x2c);
      pplVar9 = (longlong **)((longlong)ppplVar8 + 0x17bU & 0xfffffffffffffffe);
      *(undefined4 *)(ppplVar8 + 0x1d) = 0;
      ppplVar8[0x26] = pplVar9;
      *(undefined2 *)((longlong)ppplVar8 + 0x13a) = 0x1a;
      ppplVar8[7] = pplVar9 + 4;
      *(undefined2 *)((longlong)ppplVar8 + 0x12a) = 0x20;
      *(ushort *)((longlong)ppplVar8 + 0x32) = *param_1 + 2;
      RtlCopyUnicodeString(ppplVar8 + 6,param_1);
      ppplVar10 = (longlong ***)BowserCreateDomain(param_2,param_3);
      pppplVar7[7] = ppplVar10;
      if (ppplVar10 == (longlong ***)0x0) goto LAB_140018135;
      iVar5 = BowserUpdateProviderInformation((longlong *)ppplVar8);
      puVar13 = auStack_148;
      if (iVar5 < 0) {
LAB_140018062:
        *(undefined8 *)(puVar13 + -8) = 0x140018070;
        ExReleaseResourceLite(&BowserTransportDatabaseResource);
        if (-1 < iVar5) {
          puVar4 = puVar13;
          if (pppplVar7 == (longlong ****)0x0) goto LAB_140018031;
          goto LAB_140018029;
        }
        if (pppplVar7 == (longlong ****)0x0) goto LAB_140018031;
      }
      else {
        iVar5 = 0;
        local_e0 = 0x300;
        local_e8 = 0;
        local_f0 = 0;
        local_f8 = 0x2d;
        *(undefined2 *)(ppplVar8 + 0x2b) = 0;
        builtin_strncpy(local_70,"TransportAddress",0x11);
        local_88 = 0;
        uStack_80 = 0;
        uStack_d0 = 0;
        local_c8 = 0x53050000;
        local_70[0x21] = '\0';
        local_70[0x22] = '\0';
        local_70[0x23] = '\x05';
        local_70[0x24] = 'S';
        local_100 = &local_78;
        local_108 = 0;
        local_110 = 2;
        local_118 = 3;
        local_d8 = 1;
        uStack_d4 = 0x6000c;
        local_120 = local_120 & 0xffffffff00000000;
        local_128 = (longlong ****)0x0;
        local_70[0x11] = '\x01';
        local_70[0x12] = '\0';
        local_70[0x13] = '\0';
        local_70[0x14] = '\0';
        local_70[0x15] = '\f';
        local_70[0x16] = '\0';
        local_70[0x17] = '\x06';
        local_70[0x18] = '\0';
        local_70[0x19] = '\0';
        local_70[0x1a] = '\0';
        local_70[0x1b] = '\0';
        local_70[0x1c] = '\0';
        local_70[0x1d] = '\0';
        local_70[0x1e] = '\0';
        local_70[0x1f] = '\0';
        local_70[0x20] = '\0';
        local_b8 = 0x30;
        local_a0 = 0x240;
        local_78 = 0;
        local_74 = 0x141000;
        local_b0 = 0;
        local_98 = 0;
        uStack_90 = 0;
        local_a8 = ppplVar8 + 6;
        iVar6 = IoCreateFile(ppplVar8 + 0x1e,0x180,&local_b8,&local_88);
        if (-1 < iVar6) {
          local_120 = 0;
          local_128 = pppplVar7 + 9;
          iVar5 = ObReferenceObjectByHandle
                            (ppplVar8[0x1e],0,*(undefined8 *)IoFileObjectType_exref,0);
          if (iVar5 < 0) {
            ZwClose(ppplVar8[0x1e]);
            ppplVar8[0x1e] = (longlong **)0x0;
            ppplVar10 = (longlong ***)0x0;
          }
          else {
            ppplVar10 = (longlong ***)IoGetRelatedDeviceObject(pppplVar7[9]);
          }
          pppplVar7[10] = ppplVar10;
          if (-1 < iVar5) {
            *(undefined1 *)((longlong)ppplVar8 + 0x15a) = 0;
            *(ushort *)(ppplVar8 + 0x2b) = *(ushort *)(ppplVar8 + 0x2b) | 0x8000;
          }
        }
        puVar13 = auStack_148;
        if (*DAT_14000d410 != (longlong **)&BowserTransportHead) {
          pcVar3 = (code *)swi(0x29);
          (*pcVar3)(3);
          puVar13 = auStack_140;
          goto LAB_140018062;
        }
        *ppplVar1 = (longlong **)&BowserTransportHead;
        ppplVar8[3] = (longlong **)DAT_14000d410;
        *DAT_14000d410 = (longlong **)ppplVar1;
        DAT_14000d410 = ppplVar1;
        BowserReferenceTransport((longlong)pppplVar7);
        ExReleaseResourceLite(&BowserTransportDatabaseResource);
        iVar5 = BowserAddDefaultNames(pppplVar7,(undefined4 *)0x0);
        if (-1 < iVar5) {
          bVar14 = *(short *)(ppplVar8 + 0x2b) < 0;
          if (bVar14) {
            ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
            BowserEnableIpxDatagramSocket((longlong)pppplVar7);
          }
          uVar11 = (uint)(*(char *)((longlong)ppplVar8 + 0x15a) != '\0');
          uVar12 = uVar11 | 8;
          if (*(char *)((longlong)ppplVar8 + 0x15c) == '\0') {
            uVar12 = uVar11;
          }
          uVar11 = uVar12 | 2;
          if (*(char *)((longlong)ppplVar8 + 0x15b) == '\0') {
            uVar11 = uVar12;
          }
          uVar12 = uVar11 | 4;
          if (-1 < *(short *)(ppplVar8 + 0x2b)) {
            uVar12 = uVar11;
          }
          BowserSendPnp(1,(ushort *)0x0,(ushort *)(ppplVar8 + 6),(ushort *)(ulonglong)uVar12);
          goto LAB_1400180e3;
        }
      }
    }
    *(undefined8 *)(puVar13 + -8) = 0x140018029;
    BowserDeleteTransport((longlong)pppplVar7);
    puVar4 = puVar13;
  }
  else {
LAB_1400180e3:
    puVar13 = auStack_148;
    iVar5 = 0;
    puVar4 = auStack_148;
    if (bVar14) goto LAB_140018062;
  }
LAB_140018029:
  puVar13 = puVar4;
  *(undefined8 *)(puVar13 + -8) = 0x140018031;
  BowserDereferenceTransport((longlong)pppplVar7);
LAB_140018031:
  *(undefined8 *)(puVar13 + -8) = 0x14001803f;
  return iVar5;
}



===== BowserDereferenceTransport @ 140018200 =====

void BowserDereferenceTransport(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
  LOCK();
  piVar1 = (int *)(param_1 + 4);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    BowserpFreeTransport(param_1);
  }
  ExReleaseResourceLite(&BowserTransportDatabaseResource);
  return;
}



===== BowserInitializeTimer @ 140018258 =====

void BowserInitializeTimer(longlong param_1)

{
  KeInitializeTimer(param_1 + 0x40);
  KeInitializeEvent(param_1 + 0x88,0,1);
  KeInitializeSpinLock(param_1 + 0x80);
  *(longlong *)(param_1 + 0xd0) = param_1;
  *(code **)(param_1 + 200) = BowserTimerDispatcher;
  *(undefined8 *)(param_1 + 0xb8) = 0;
  *(undefined4 *)(param_1 + 0xd8) = 0x100;
  return;
}



===== BowserCreateDomain @ 1400182e0 =====

undefined8 * BowserCreateDomain(ushort *param_1,ushort *param_2)

{
  undefined8 uVar1;
  code *pcVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [40];
  undefined4 local_18;
  undefined8 *local_10;
  
  local_18 = 0;
  local_10 = (undefined8 *)0x0;
  ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
  puVar4 = BowserFindDomain(param_1);
  puVar7 = auStack_48;
  local_10 = puVar4;
  if (puVar4 == (undefined8 *)0x0) {
    puVar4 = (undefined8 *)ExAllocatePool2(0x40,0xc0,0x6964424c);
    puVar6 = auStack_48;
    puVar7 = auStack_48;
    local_10 = puVar4;
    if (puVar4 != (undefined8 *)0x0) {
      *(undefined4 *)(puVar4 + 0x17) = 1;
      puVar5 = &BowserServicedDomains;
      if ((undefined8 *)*DAT_14000d4c0 != &BowserServicedDomains) {
        puVar5 = (undefined8 *)0x3;
        pcVar2 = (code *)swi(0x29);
        DAT_14000d4c0 = (undefined8 *)(*pcVar2)();
        puVar6 = auStack_40;
      }
      *puVar4 = puVar5;
      puVar4[1] = DAT_14000d4c0;
      *DAT_14000d4c0 = puVar4;
      puVar7 = puVar6;
      DAT_14000d4c0 = puVar4;
      goto LAB_14001833b;
    }
    iVar3 = -0x3fffffe9;
  }
  else {
LAB_14001833b:
    *(undefined8 *)(puVar7 + -8) = 0x140018346;
    iVar3 = BowserSetDomainName((longlong)puVar4,param_1);
    *(int *)(puVar7 + 0x30) = iVar3;
    if (iVar3 < 0) goto LAB_140018470;
    if (*param_2 < 0x1f) {
      *(uint *)(puVar7 + 0x20) = (uint)*param_2;
      uVar1 = *(undefined8 *)(param_2 + 4);
      *(undefined8 *)(puVar7 + -8) = 0x140018381;
      iVar3 = RtlUpcaseUnicodeToOemN(puVar4 + 0x13,0xf,puVar7 + 0x60,uVar1);
      *(int *)(puVar7 + 0x30) = iVar3;
      if (iVar3 < 0) goto LAB_140018470;
      *(undefined1 *)((ulonglong)*(uint *)(puVar7 + 0x60) + 0x98 + (longlong)puVar4) = 0;
      puVar4[0x16] = puVar4 + 0x13;
      *(undefined2 *)(puVar4 + 0x15) = *(undefined2 *)(puVar7 + 0x60);
      *(short *)((longlong)puVar4 + 0xaa) = *(short *)(puVar7 + 0x60) + 1;
      puVar4[0x12] = puVar4 + 0xd;
      *(undefined2 *)((longlong)puVar4 + 0x8a) = 0x20;
      *(undefined8 *)(puVar7 + -8) = 0x1400183eb;
      iVar3 = RtlOemStringToUnicodeString(puVar4 + 0x11,puVar4 + 0x15,0);
      *(int *)(puVar7 + 0x30) = iVar3;
      if (iVar3 < 0) goto LAB_140018470;
      iVar3 = 0;
    }
    else {
      iVar3 = -0x3ffffff3;
    }
  }
  *(int *)(puVar7 + 0x30) = iVar3;
LAB_140018470:
  if ((iVar3 < 0) && (puVar4 != (undefined8 *)0x0)) {
    *(undefined8 *)(puVar7 + -8) = 0x1400184ae;
    BowserDereferenceDomain(puVar4);
    puVar4 = (undefined8 *)0x0;
  }
  *(undefined8 *)(puVar7 + -8) = 0x140018482;
  ExReleaseResourceLite(&BowserTransportDatabaseResource);
  return puVar4;
}



===== BowserFindTransport @ 1400184c0 =====

longlong BowserFindTransport(byte *param_1,ushort *param_2)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  longlong lVar4;
  char cVar5;
  undefined8 uVar6;
  longlong *plVar7;
  undefined8 *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  longlong lVar11;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  longlong *local_18;
  
  lVar11 = 0;
  plVar7 = (longlong *)0x0;
  local_18 = (longlong *)0x0;
  ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
  uVar6 = BowserValidUnicodeString(param_1);
  if (((int)uVar6 != 0) &&
     (plVar7 = BowserFindDomain(param_2), local_18 = plVar7, plVar7 != (longlong *)0x0)) {
    for (puVar8 = BowserTransportHead; (undefined8 **)puVar8 != &BowserTransportHead;
        puVar8 = (undefined8 *)*puVar8) {
      if (((*(char *)((longlong)puVar8 + 0x14e) == '\0') &&
          (*(longlong **)(puVar8[-1] + 0x38) == plVar7)) &&
         (cVar5 = RtlEqualUnicodeString(param_1,puVar8 + 4,1), cVar5 != '\0')) {
        lVar11 = puVar8[-1];
        BowserReferenceTransport(lVar11);
        break;
      }
    }
  }
  puVar10 = auStack_38;
  puVar9 = auStack_38;
  if (plVar7 == (longlong *)0x0) goto LAB_1400185b7;
  ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
  plVar2 = plVar7 + 0x17;
  *(int *)plVar2 = (int)*plVar2 + -1;
  lVar4 = plVar7[0x17];
  if ((int)*plVar2 == 0) {
    lVar1 = *plVar7;
    plVar2 = (longlong *)plVar7[1];
    if ((*(longlong **)(lVar1 + 8) == plVar7) && ((longlong *)*plVar2 == plVar7)) {
      *plVar2 = lVar1;
      *(longlong **)(lVar1 + 8) = plVar2;
      goto LAB_1400185a0;
    }
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(3);
    puVar10 = auStack_30;
  }
  else {
LAB_1400185a0:
    ExReleaseResourceLite(&BowserTransportDatabaseResource);
    puVar9 = auStack_38;
    if ((int)lVar4 != 0) goto LAB_1400185b7;
  }
  *(undefined8 *)(puVar10 + -8) = 0x140018617;
  ExFreePoolWithTag(plVar7,0);
  puVar9 = puVar10;
LAB_1400185b7:
  *(undefined8 *)(puVar9 + -8) = 0x1400185c5;
  ExReleaseResourceLite(&BowserTransportDatabaseResource);
  return lVar11;
}



===== BowserFindDomain @ 140018630 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 * BowserFindDomain(ushort *param_1)

{
  int iVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  undefined1 auStack_68 [32];
  uint local_48;
  uint local_38 [2];
  undefined8 *local_30;
  undefined1 local_28 [16];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  local_30 = (undefined8 *)0x0;
  local_38[0] = 0;
  ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
  puVar4 = (undefined8 *)0x0;
  if ((param_1 == (ushort *)0x0) || (*param_1 == 0)) {
    if ((undefined8 **)BowserServicedDomains != &BowserServicedDomains) {
      puVar4 = BowserServicedDomains;
    }
    local_30 = puVar4;
  }
  else {
    if ((*(ulonglong *)(param_1 + 4) & 1) == 0) {
      local_48 = (uint)*param_1;
      iVar1 = RtlUpcaseUnicodeToOemN(local_28,0xf,local_38);
      if ((iVar1 < 0) ||
         ((puVar4 = BowserServicedDomains,
          (undefined8 **)BowserServicedDomains != &BowserServicedDomains &&
          (local_30 = BowserServicedDomains, *(int *)(BowserServicedDomains + 4) == 0))))
      goto LAB_14001874a;
      uVar3 = (ulonglong)local_38[0];
      for (; (undefined8 **)puVar4 != &BowserServicedDomains; puVar4 = (undefined8 *)*puVar4) {
        if (*(int *)(puVar4 + 4) == (int)uVar3) {
          local_30 = puVar4;
          uVar2 = RtlCompareMemory(puVar4 + 2,local_28,uVar3);
          uVar3 = (ulonglong)local_38[0];
          if (uVar2 == uVar3) goto LAB_14001874a;
        }
      }
    }
    puVar4 = (undefined8 *)0x0;
    local_30 = (undefined8 *)0x0;
  }
LAB_14001874a:
  if (puVar4 != (undefined8 *)0x0) {
    *(int *)(puVar4 + 0x17) = *(int *)(puVar4 + 0x17) + 1;
  }
  ExReleaseResourceLite(&BowserTransportDatabaseResource);
  return puVar4;
}



===== BowserSetDomainName @ 140018790 =====

int BowserSetDomainName(longlong param_1,undefined2 *param_2)

{
  void *_Src;
  int iVar1;
  undefined8 local_20;
  void *pvStack_18;
  
  iVar1 = 0;
  local_20 = 0;
  pvStack_18 = (void *)0x0;
  ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
  if ((~(uint)*(undefined8 *)(param_2 + 4) & 1) != 0) {
    _Src = (void *)(param_1 + 0x10);
    iVar1 = RtlUpcaseUnicodeToOemN(_Src,0x10,param_1 + 0x20,*(undefined8 *)(param_2 + 4),*param_2);
    if ((-1 < iVar1) && (*(uint *)(param_1 + 0x20) != 0x10)) {
      *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x20) + 0x10 + param_1) = 0;
      memcpy((void *)(param_1 + 0x24),_Src,(ulonglong)*(uint *)(param_1 + 0x20));
      memset((void *)((ulonglong)*(uint *)(param_1 + 0x20) + 0x24 + param_1),0x20,
             (ulonglong)(0xf - *(uint *)(param_1 + 0x20)));
      *(undefined1 *)(param_1 + 0x33) = 0;
      local_20._0_4_ = CONCAT22(*(undefined2 *)(param_1 + 0x20),*(undefined2 *)(param_1 + 0x20));
      *(longlong *)(param_1 + 0x60) = param_1 + 0x36;
      *(undefined2 *)(param_1 + 0x5a) = 0x20;
      pvStack_18 = _Src;
      iVar1 = RtlOemStringToUnicodeString(param_1 + 0x58,&local_20,0);
      if (-1 < iVar1) {
        iVar1 = 0;
      }
    }
  }
  ExReleaseResourceLite(&BowserTransportDatabaseResource);
  return iVar1;
}



===== BowserAddDefaultNames @ 1400188d0 =====

int BowserAddDefaultNames(longlong ****param_1,undefined4 *param_2)

{
  longlong ****pppplVar1;
  longlong ***ppplVar2;
  longlong ****pppplVar3;
  code *pcVar4;
  int iVar5;
  longlong ****pppplVar6;
  longlong lVar7;
  undefined8 *puVar8;
  int iVar9;
  bool bVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  longlong ****local_48;
  longlong ****local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined4 local_28;
  undefined4 local_24;
  
  ppplVar2 = param_1[7];
  iVar9 = 0;
  local_24 = 0;
  local_38 = ppplVar2[0x11];
  uStack_30 = ppplVar2[0x12];
  if (param_2 == (undefined4 *)0x0) {
    uVar11 = *(undefined4 *)(ppplVar2 + 0xb);
    uVar12 = *(undefined4 *)((longlong)ppplVar2 + 0x5c);
    uVar13 = *(undefined4 *)(ppplVar2 + 0xc);
    uVar14 = *(undefined4 *)((longlong)ppplVar2 + 100);
  }
  else {
    uVar11 = *param_2;
    uVar12 = param_2[1];
    uVar13 = param_2[2];
    uVar14 = param_2[3];
  }
  local_40 = (longlong ****)&local_48;
  local_48 = (longlong ****)&local_48;
  local_28 = 1;
  pppplVar6 = (longlong ****)ExAllocatePool2(0x102,0x38,0x6e61424c);
  if (pppplVar6 == (longlong ****)0x0) {
    iVar5 = -0x3fffff66;
  }
  else {
    pppplVar6[2] = (longlong ***)0x0;
    pppplVar6[3] = (longlong ***)param_1;
    lVar7 = BowserReferenceTransport((longlong)param_1);
    *(undefined4 *)(lVar7 + 0x20) = (undefined4)local_38;
    *(undefined4 *)(lVar7 + 0x24) = local_38._4_4_;
    *(undefined4 *)(lVar7 + 0x28) = (undefined4)uStack_30;
    *(undefined4 *)(lVar7 + 0x2c) = uStack_30._4_4_;
    *(undefined4 *)(pppplVar6 + 6) = local_28;
    iVar5 = PsCreateSystemThread(pppplVar6 + 2,0x1fffff,0,0,0,AsyncCreateTransportName,pppplVar6);
    if (iVar5 < 0) {
LAB_140018c43:
      BowserDereferenceTransport((longlong)param_1);
      goto LAB_140018b39;
    }
    if ((longlong *****)*local_40 != &local_48) {
LAB_140018b4c:
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
LAB_140018b53:
      if (-1 < iVar5) {
        iVar5 = iVar9;
      }
      return iVar5;
    }
    pppplVar6[1] = (longlong ***)local_40;
    *pppplVar6 = (longlong ***)&local_48;
    *local_40 = (longlong ***)pppplVar6;
    local_38 = (longlong **)CONCAT44(uVar12,uVar11);
    uStack_30 = (longlong **)CONCAT44(uVar14,uVar13);
    local_28 = 2;
    local_40 = pppplVar6;
    pppplVar6 = (longlong ****)ExAllocatePool2(0x102,0x38,0x6e61424c);
    if (pppplVar6 == (longlong ****)0x0) {
      iVar5 = -0x3fffff66;
    }
    else {
      pppplVar6[2] = (longlong ***)0x0;
      pppplVar6[3] = (longlong ***)param_1;
      lVar7 = BowserReferenceTransport((longlong)param_1);
      *(undefined4 *)(lVar7 + 0x20) = (undefined4)local_38;
      *(undefined4 *)(lVar7 + 0x24) = local_38._4_4_;
      *(undefined4 *)(lVar7 + 0x28) = (undefined4)uStack_30;
      *(undefined4 *)(lVar7 + 0x2c) = uStack_30._4_4_;
      *(undefined4 *)(pppplVar6 + 6) = local_28;
      iVar5 = PsCreateSystemThread(pppplVar6 + 2,0x1fffff,0,0,0,AsyncCreateTransportName,pppplVar6);
      if (iVar5 < 0) goto LAB_140018c43;
      if ((longlong *****)*local_40 != &local_48) goto LAB_140018b4c;
      bVar10 = DAT_14000d2a6 != '\0';
      *pppplVar6 = (longlong ***)&local_48;
      pppplVar6[1] = (longlong ***)local_40;
      *local_40 = (longlong ***)pppplVar6;
      local_40 = pppplVar6;
      if (bVar10) {
        local_28 = 9;
        local_38 = (longlong **)CONCAT44(uVar12,uVar11);
        uStack_30 = (longlong **)CONCAT44(uVar14,uVar13);
        pppplVar6 = (longlong ****)ExAllocatePool2(0x102,0x38,0x6e61424c);
        if (pppplVar6 == (longlong ****)0x0) {
          iVar5 = -0x3fffff66;
          goto LAB_140018ae0;
        }
        pppplVar6[2] = (longlong ***)0x0;
        pppplVar6[3] = (longlong ***)param_1;
        lVar7 = BowserReferenceTransport((longlong)param_1);
        *(undefined4 *)(lVar7 + 0x20) = (undefined4)local_38;
        *(undefined4 *)(lVar7 + 0x24) = local_38._4_4_;
        *(undefined4 *)(lVar7 + 0x28) = (undefined4)uStack_30;
        *(undefined4 *)(lVar7 + 0x2c) = uStack_30._4_4_;
        *(undefined4 *)(pppplVar6 + 6) = local_28;
        iVar5 = PsCreateSystemThread
                          (pppplVar6 + 2,0x1fffff,0,0,0,AsyncCreateTransportName,pppplVar6);
        if (iVar5 < 0) goto LAB_140018c43;
        if ((longlong *****)*local_40 != &local_48) goto LAB_140018b4c;
        pppplVar6[1] = (longlong ***)local_40;
        *pppplVar6 = (longlong ***)&local_48;
        *local_40 = (longlong ***)pppplVar6;
        local_40 = pppplVar6;
      }
      ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
      for (puVar8 = BowserNameHead; (undefined8 **)puVar8 != &BowserNameHead;
          puVar8 = (undefined8 *)*puVar8) {
        if (*(int *)(puVar8 + 6) == 4) {
          local_38 = (longlong **)puVar8[4];
          uStack_30 = (longlong **)puVar8[5];
          local_28 = 4;
          iVar5 = AddTransportName((longlong)param_1,(longlong)&local_48);
          if (iVar5 < 0) {
            ExReleaseResourceLite(&BowserTransportDatabaseResource);
            goto LAB_140018ae0;
          }
        }
      }
      ExReleaseResourceLite(&BowserTransportDatabaseResource);
      iVar5 = 0;
    }
  }
LAB_140018ae0:
  do {
    pppplVar6 = local_48;
    if ((longlong *****)local_48 == &local_48) goto LAB_140018b53;
    if (((longlong *****)local_48[1] != &local_48) ||
       (pppplVar3 = (longlong ****)*local_48, (longlong ****)pppplVar3[1] != local_48))
    goto LAB_140018b4c;
    pppplVar3[1] = (longlong ***)&local_48;
    pppplVar1 = local_48 + 2;
    local_48 = pppplVar3;
    ZwWaitForSingleObject(*pppplVar1,0,0);
    ZwClose(pppplVar6[2]);
    if (*(int *)((longlong)pppplVar6 + 0x34) < 0) {
      iVar9 = *(int *)((longlong)pppplVar6 + 0x34);
    }
LAB_140018b39:
    ExFreePoolWithTag(pppplVar6);
  } while( true );
}



===== BowserDeleteTransport @ 140018cb0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void BowserDeleteTransport(longlong param_1)

{
  longlong *plVar1;
  int iVar2;
  longlong lVar3;
  undefined8 *puVar4;
  char cVar5;
  longlong lVar6;
  uint uVar7;
  uint uVar8;
  undefined1 auStack_78 [32];
  undefined8 local_58;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_78;
  lVar3 = *(longlong *)(param_1 + 8);
  local_48 = 0;
  if (lVar3 == 0) {
    BowserUninitializeTimer(param_1 + 0x138);
    BowserUninitializeTimer(param_1 + 0x218);
    BowserNetlogonDeleteTransportFromMessageQueue(param_1);
  }
  else {
    uVar7 = (uint)(*(char *)(lVar3 + 0x15a) != '\0');
    uVar8 = uVar7 | 8;
    if (*(char *)(lVar3 + 0x15c) == '\0') {
      uVar8 = uVar7;
    }
    uVar7 = uVar8 | 2;
    if (*(char *)(lVar3 + 0x15b) == '\0') {
      uVar7 = uVar8;
    }
    uVar8 = uVar7 | 4;
    if (-1 < *(short *)(lVar3 + 0x158)) {
      uVar8 = uVar7;
    }
    BowserSendPnp(2,(ushort *)0x0,(ushort *)(lVar3 + 0x30),(ushort *)(ulonglong)uVar8);
    ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
    if (*(char *)(lVar3 + 0x15e) == '\0') {
      *(undefined1 *)(lVar3 + 0x15e) = 1;
      if (*(longlong **)(lVar3 + 0x10) != (longlong *)(lVar3 + 0x10)) {
        BowserDereferenceTransport(param_1);
      }
      ExReleaseResourceLite(&BowserTransportDatabaseResource);
      ExWaitForRundownProtectionRelease(param_1 + 0x3f0);
      KeSetEvent(param_1 + 0x3f8,0,0);
    }
    else {
      ExReleaseResourceLite(&BowserTransportDatabaseResource);
      local_58 = 0;
      KeWaitForSingleObject(param_1 + 0x3f8,0,0,0);
    }
    ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
    BowserCloseAllNetbiosAddresses(param_1);
    if (*(longlong *)(lVar3 + 0xf0) != 0) {
      local_40 = 0;
      uStack_38 = 0;
      local_30 = 0;
      uStack_28 = 0;
      local_20 = 0;
      uStack_18 = 0;
      lVar6 = IoGetCurrentProcess();
      if (lVar6 == BowserFspProcess) {
        ZwClose(*(undefined8 *)(lVar3 + 0xf0));
      }
      else {
        KeStackAttachProcess(BowserFspProcess,&local_40);
        ZwClose(*(undefined8 *)(lVar3 + 0xf0));
        KeUnstackDetachProcess(&local_40);
      }
      *(undefined8 *)(lVar3 + 0xf0) = 0;
      if (*(longlong *)(param_1 + 0x48) != 0) {
        ObfDereferenceObject();
        *(undefined8 *)(param_1 + 0x48) = 0;
      }
      *(undefined8 *)(param_1 + 0x50) = 0;
    }
    ExReleaseResourceLite(&BowserTransportDatabaseResource);
    BowserUninitializeTimer(param_1 + 0x138);
    BowserUninitializeTimer(param_1 + 0x218);
    BowserNetlogonDeleteTransportFromMessageQueue(param_1);
    ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
    lVar3 = *(longlong *)(param_1 + 8);
    puVar4 = *(undefined8 **)(lVar3 + 0x20);
    while ((puVar4 != (undefined8 *)0x0 && (puVar4 != (undefined8 *)(lVar3 + 0x20)))) {
      plVar1 = puVar4 + -2;
      puVar4 = (undefined8 *)*puVar4;
      if (*(int *)(*plVar1 + 8) != 1) {
        ExReleaseResourceLite(&BowserTransportDatabaseResource);
        local_48 = 0xfffffffffff0bdc0;
        KeDelayExecutionThread(0,0,&local_48);
        ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
        lVar3 = *(longlong *)(param_1 + 8);
        puVar4 = *(undefined8 **)(lVar3 + 0x20);
      }
    }
    ExReleaseResourceLite(&BowserTransportDatabaseResource);
  }
  cVar5 = ExAcquireResourceExclusiveLite(param_1 + 0x410,0);
  if (cVar5 != '\0') {
    iVar2 = *(int *)(param_1 + 4);
    while (iVar2 != 1) {
      local_48 = 0xfffffffffff0bdc0;
      KeDelayExecutionThread(0,0,&local_48);
      iVar2 = *(int *)(param_1 + 4);
    }
    ExReleaseResourceLite(param_1 + 0x410);
  }
  return;
}



===== BowserCloseAllNetbiosAddresses @ 140019010 =====

void BowserCloseAllNetbiosAddresses(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  
  ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
  plVar1 = (longlong *)(*(longlong *)(param_1 + 8) + 0x20);
  plVar2 = (longlong *)*plVar1;
  if (plVar2 != plVar1) {
    do {
      plVar1 = (longlong *)*plVar2;
      BowserCloseNetbiosAddress(plVar2[-2]);
      plVar2 = plVar1;
    } while (plVar1 != (longlong *)(*(longlong *)(param_1 + 8) + 0x20));
  }
  ExReleaseResourceLite(&BowserTransportDatabaseResource);
  return;
}



===== BowserpTdiRemoveAddresses @ 140019090 =====

ulonglong BowserpTdiRemoveAddresses(longlong param_1)

{
  int *piVar1;
  int iVar2;
  undefined8 *puVar3;
  longlong lVar4;
  undefined8 *puVar5;
  code *pcVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  
  ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
  puVar7 = *(undefined8 **)(*(longlong *)(param_1 + 8) + 0x20);
  while( true ) {
    if (puVar7 == (undefined8 *)(*(longlong *)(param_1 + 8) + 0x20)) {
      ExReleaseResourceLite(&BowserTransportDatabaseResource);
      return 0;
    }
    puVar3 = (undefined8 *)*puVar7;
    lVar4 = puVar7[-2];
    if (((undefined8 *)puVar3[1] != puVar7) ||
       (puVar5 = (undefined8 *)puVar7[1], (undefined8 *)*puVar5 != puVar7)) break;
    *puVar5 = puVar3;
    puVar3[1] = puVar5;
    *puVar7 = 0;
    puVar7[1] = 0;
    ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
    LOCK();
    piVar1 = (int *)(lVar4 + 8);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      uVar8 = BowserFreeTransportName(lVar4);
      ExReleaseResourceLite(&BowserTransportDatabaseResource);
      if ((int)uVar8 < 0) {
        ExReleaseResourceLite(&BowserTransportDatabaseResource);
        return uVar8 & 0xffffffff;
      }
    }
    else {
      ExReleaseResourceLite(&BowserTransportDatabaseResource);
    }
    puVar7 = puVar3;
  }
  pcVar6 = (code *)swi(0x29);
  (*pcVar6)(3);
  pcVar6 = (code *)swi(3);
  uVar8 = (*pcVar6)();
  return uVar8;
}



===== BowserDereferenceTransportName @ 1400191c0 =====

ulonglong BowserDereferenceTransportName(longlong param_1)

{
  int *piVar1;
  int iVar2;
  ulonglong uVar3;
  
  ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
  LOCK();
  piVar1 = (int *)(param_1 + 8);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    uVar3 = BowserFreeTransportName(param_1);
    uVar3 = uVar3 & 0xffffffff;
  }
  else {
    uVar3 = 0;
  }
  ExReleaseResourceLite(&BowserTransportDatabaseResource);
  return uVar3;
}



===== BowserFreeTransportName @ 140019220 =====

undefined8 BowserFreeTransportName(longlong param_1)

{
  undefined8 *puVar1;
  int *piVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  longlong *plVar7;
  code *pcVar8;
  uint uVar9;
  uint uVar10;
  undefined1 *puVar11;
  bool bVar12;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  lVar4 = *(longlong *)(param_1 + 0x18);
  lVar5 = *(longlong *)(param_1 + 0x10);
  ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
  BowserCloseNetbiosAddress(param_1);
  puVar11 = auStack_28;
  if (*(int *)(param_1 + 8) != 0) goto LAB_140019434;
  if (lVar5 == 0) goto LAB_140019364;
  lVar6 = *(longlong *)(lVar5 + 0x18);
  puVar1 = (undefined8 *)(lVar5 + 0x18);
  if (lVar6 == 0) {
LAB_140019288:
    lVar6 = *(longlong *)(lVar5 + 0x28);
    if ((*(longlong *)(lVar6 + 8) == lVar5 + 0x28) &&
       (plVar7 = *(longlong **)(lVar5 + 0x30), *plVar7 == lVar5 + 0x28)) {
      *plVar7 = lVar6;
      *(longlong **)(lVar6 + 8) = plVar7;
      lVar6 = *(longlong *)(lVar5 + 0x10);
      ExFreePoolWithTag(lVar5,0);
      if (lVar6 == 0) goto LAB_140019364;
      iVar3 = *(int *)(lVar6 + 0x38);
      if (iVar3 == 1) {
        *(undefined8 *)(lVar4 + 0x10) = 0;
      }
      else if (iVar3 == 2) {
        if (*(longlong *)(lVar4 + 0x18) == param_1) {
          *(undefined8 *)(lVar4 + 0x18) = *(undefined8 *)(lVar4 + 0x20);
          *(undefined8 *)(lVar4 + 0x20) = 0;
        }
        if (*(longlong *)(lVar4 + 0x20) == param_1) {
          *(undefined8 *)(lVar4 + 0x20) = 0;
        }
      }
      else if (iVar3 == 6) {
        *(undefined8 *)(lVar4 + 0x28) = 0;
      }
      else if (iVar3 == 7) {
        *(undefined8 *)(lVar4 + 0x30) = 0;
      }
      else if (iVar3 == 10) {
        *(undefined1 *)(*(longlong *)(lVar4 + 8) + 0x15c) = 0;
        lVar5 = *(longlong *)(lVar4 + 8);
        bVar12 = *(char *)(lVar5 + 0x15a) != '\0';
        uVar9 = bVar12 | 8;
        if (*(char *)(lVar5 + 0x15c) == '\0') {
          uVar9 = (uint)bVar12;
        }
        uVar10 = uVar9 | 2;
        if (*(char *)(lVar5 + 0x15b) == '\0') {
          uVar10 = uVar9;
        }
        uVar9 = uVar10 | 4;
        if (-1 < *(short *)(lVar5 + 0x158)) {
          uVar9 = uVar10;
        }
        BowserSendPnp(5,(ushort *)(*(longlong *)(lVar4 + 0x38) + 0x58),(ushort *)(lVar5 + 0x30),
                      (ushort *)(ulonglong)uVar9);
      }
      ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
      piVar2 = (int *)(lVar6 + 4);
      *piVar2 = *piVar2 + -1;
      if (*piVar2 == 0) {
        lVar4 = *(longlong *)(lVar6 + 8);
        if ((*(longlong *)(lVar4 + 8) != lVar6 + 8) ||
           (plVar7 = *(longlong **)(lVar6 + 0x10), *plVar7 != lVar6 + 8)) goto LAB_14001942d;
        *plVar7 = lVar4;
        *(longlong **)(lVar4 + 8) = plVar7;
        ExFreePoolWithTag(lVar6,0);
      }
      ExReleaseResourceLite(&BowserTransportDatabaseResource);
LAB_140019364:
      ExFreePoolWithTag(param_1,0);
      ExReleaseResourceLite(&BowserTransportDatabaseResource);
      return 0;
    }
  }
  else if ((*(undefined8 **)(lVar6 + 8) == puVar1) &&
          (plVar7 = *(longlong **)(lVar5 + 0x20), (undefined8 *)*plVar7 == puVar1)) {
    *plVar7 = lVar6;
    *(longlong **)(lVar6 + 8) = plVar7;
    *puVar1 = 0;
    *(undefined8 *)(lVar5 + 0x20) = 0;
    goto LAB_140019288;
  }
LAB_14001942d:
  pcVar8 = (code *)swi(0x29);
  (*pcVar8)(3);
  puVar11 = auStack_20;
LAB_140019434:
  *(undefined8 *)(puVar11 + -8) = 0x140019442;
  ExReleaseResourceLite(&BowserTransportDatabaseResource);
  return 0;
}



===== BowserCloseNetbiosAddress @ 140019490 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void BowserCloseNetbiosAddress(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined1 auStack_68 [32];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  lVar1 = *(longlong *)(param_1 + 0x10);
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
  if ((lVar1 != 0) && (*(longlong *)(lVar1 + 0x38) != 0)) {
    lVar3 = IoGetCurrentProcess();
    if (lVar3 == BowserFspProcess) {
      iVar2 = ZwClose(*(undefined8 *)(lVar1 + 0x38));
    }
    else {
      KeStackAttachProcess(BowserFspProcess,&local_48);
      iVar2 = ZwClose(*(undefined8 *)(lVar1 + 0x38));
      KeUnstackDetachProcess(&local_48);
    }
    if (*(char *)(param_1 + 4) == '\x06') {
      if (iVar2 < 0) {
        if (DAT_14000d88c < 5) {
          *(int *)(&DAT_14000d8a4 + (ulonglong)DAT_14000d88c * 4) = iVar2;
        }
        DAT_14000d88c = DAT_14000d88c + 1;
      }
      else {
        _DAT_14000d884 = _DAT_14000d884 + 1;
      }
    }
    *(undefined8 *)(lVar1 + 0x38) = 0;
  }
  if (*(longlong *)(param_1 + 0x20) != 0) {
    ObfDereferenceObject();
    *(undefined8 *)(param_1 + 0x20) = 0;
  }
  ExReleaseResourceLite(&BowserTransportDatabaseResource);
  return;
}



===== BowserTimeUp @ 1400195f0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong BowserTimeUp(void)

{
  ulonglong uVar1;
  
  uVar1 = _DAT_fffff78000000014 - _BowserStartTime;
  if ((longlong)uVar1 < 0) {
    uVar1 = -(-uVar1 / 10000);
  }
  else {
    uVar1 = uVar1 / 10000;
  }
  if ((int)(uVar1 >> 0x20) == 0) {
    return uVar1 & 0xffffffff;
  }
  return 0xffffffff;
}



===== BowserProcessHostAnnouncement @ 140019650 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void BowserProcessHostAnnouncement(longlong param_1)

{
  longlong *plVar1;
  ulonglong *puVar2;
  int *piVar3;
  short sVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  longlong *plVar8;
  ulonglong uVar9;
  ulonglong *puVar10;
  code *pcVar11;
  bool bVar12;
  char cVar13;
  int iVar14;
  uint uVar15;
  void *_Dst;
  longlong lVar16;
  longlong lVar17;
  undefined1 *puVar18;
  undefined1 *puVar19;
  ulonglong uVar20;
  undefined8 uStack_170;
  undefined1 auStack_168 [32];
  char local_148 [8];
  undefined8 local_140;
  void *pvStack_138;
  undefined8 local_130;
  undefined1 *puStack_128;
  longlong local_120;
  void *local_118;
  uint local_110;
  int iStack_10c;
  longlong local_108;
  undefined2 local_f8;
  short local_f6;
  undefined8 local_e8;
  undefined8 uStack_e0;
  longlong local_d8;
  undefined2 local_d0;
  undefined1 local_ce [34];
  uint local_ac;
  undefined1 local_a8;
  undefined1 local_a7;
  undefined2 local_a6;
  undefined4 local_a4;
  undefined1 local_9c [100];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_168;
  memset(&local_f8,0,0xc0);
  local_130 = 0;
  puStack_128 = (undefined1 *)0x0;
  local_140 = 0;
  pvStack_138 = (void *)0x0;
  local_148[0] = '\0';
  lVar5 = *(longlong *)(param_1 + 0x28);
  lVar6 = *(longlong *)(lVar5 + 0x18);
  local_120 = lVar6;
  local_108 = lVar5;
  if (*(int *)(*(longlong *)(lVar6 + 8) + 0xf8) == 3) {
    puStack_128 = local_ce;
    local_130 = 0x220000;
    RtlInitAnsiString(&local_140,param_1 + 0x31);
    iVar14 = RtlOemStringToUnicodeString(&local_130,&local_140,0);
    if (-1 < iVar14) {
      puStack_128 = local_9c;
      local_130 = CONCAT44(local_130._4_4_,0x620000);
      uVar20 = 0;
      RtlInitAnsiString(&local_140,param_1 + 0x4c);
      iVar14 = RtlOemStringToUnicodeString(&local_130,&local_140,0);
      if (-1 < iVar14) {
        local_f8 = 5;
        local_f6 = (short)local_130 + 0x60;
        local_ac = *(uint *)(param_1 + 0x48);
        local_a8 = *(undefined1 *)(param_1 + 0x44);
        local_a7 = *(undefined1 *)(param_1 + 0x45);
        local_d8 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x10) + 0x10);
        local_e8 = 0;
        uStack_e0 = 0;
        local_a6 = *(undefined2 *)(param_1 + 0x46);
        local_a4 = 0;
        local_d0 = *(undefined2 *)(param_1 + 0x42);
        lVar16 = *(longlong *)(lVar6 + 8);
        BowserFreeViewBuffer(param_1);
        ExAcquireResourceExclusiveLite(lVar6 + 0x68,1);
        puVar19 = auStack_168;
        if ((local_ac & 2) == 0) goto LAB_140019a30;
        _Dst = (void *)RtlInsertElementGenericTable(lVar16 + 0x48,&local_f8,(int)local_f6,local_148)
        ;
        lVar17 = local_d8;
        puVar19 = auStack_168;
        local_118 = _Dst;
        if (_Dst == (void *)0x0) {
          _DAT_14000d2d4 = _DAT_14000d2d4 + 1;
        }
        else {
          ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
          *(int *)(lVar17 + 4) = *(int *)(lVar17 + 4) + 1;
          ExReleaseResourceLite(&BowserTransportDatabaseResource);
          if (local_148[0] == '\0') {
            uVar20 = (ulonglong)*(uint *)((longlong)_Dst + 0x58);
            plVar1 = (longlong *)((longlong)_Dst + 0x10);
            lVar17 = *plVar1;
            if (lVar17 == 0) {
LAB_140019894:
              lVar17 = *(longlong *)((longlong)_Dst + 0x20);
              ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
              iVar14 = *(int *)(lVar17 + 4) + -1;
              *(int *)(lVar17 + 4) = iVar14;
              if (iVar14 == 0) {
                plVar1 = (longlong *)(lVar17 + 8);
                lVar7 = *plVar1;
                plVar8 = *(longlong **)(lVar17 + 0x10);
                puVar18 = auStack_168;
                if ((*(longlong **)(lVar7 + 8) != plVar1) ||
                   (puVar18 = auStack_168, (longlong *)*plVar8 != plVar1)) goto LAB_140019a29;
                *plVar8 = lVar7;
                *(longlong **)(lVar7 + 8) = plVar8;
                ExFreePoolWithTag(lVar17,0);
              }
              ExReleaseResourceLite(&BowserTransportDatabaseResource);
              sVar4 = *(short *)((longlong)_Dst + 2);
              if (sVar4 < local_f6) {
                cVar13 = RtlDeleteElementGenericTable(lVar16 + 0x48,_Dst);
                if (cVar13 != '\0') {
                  _Dst = (void *)RtlInsertElementGenericTable
                                           (lVar16 + 0x48,&local_f8,(int)local_f6,local_148);
                  puVar19 = auStack_168;
                  local_118 = _Dst;
                  if (_Dst == (void *)0x0) {
                    _DAT_14000d2d4 = _DAT_14000d2d4 + 1;
                    goto LAB_140019b1e;
                  }
                }
              }
              else {
                memcpy(_Dst,&local_f8,(longlong)local_f6);
                *(short *)((longlong)_Dst + 2) = sVar4;
              }
              if ((local_ac & 0x20000) != 0) {
                uVar20 = 0;
              }
              *(int *)((longlong)_Dst + 0x58) = (int)uVar20;
              goto LAB_14001993c;
            }
            plVar8 = *(longlong **)((longlong)_Dst + 0x18);
            puVar18 = auStack_168;
            if ((*(longlong **)(lVar17 + 8) == plVar1) &&
               (puVar18 = auStack_168, (longlong *)*plVar8 == plVar1)) {
              *plVar8 = lVar17;
              *(longlong **)(lVar17 + 8) = plVar8;
              *(int *)(lVar16 + 0xe8) = *(int *)(lVar16 + 0xe8) + -1;
              *plVar1 = 0;
              *(undefined8 *)((longlong)_Dst + 0x18) = 0;
              goto LAB_140019894;
            }
LAB_140019a29:
            do {
              pcVar11 = (code *)swi(0x29);
              (*pcVar11)(3);
              puVar19 = puVar18 + 8;
LAB_140019a30:
              *(undefined8 *)(puVar19 + -8) = 0x140019a37;
              lVar17 = RtlLookupElementGenericTable();
              *(longlong *)(puVar19 + 0x50) = lVar17;
              if (lVar17 == 0) goto LAB_140019b1e;
              puVar2 = (ulonglong *)(lVar17 + 0x10);
              uVar9 = *puVar2;
              if (uVar9 == 0) goto LAB_140019a86;
              puVar10 = *(ulonglong **)(lVar17 + 0x18);
              puVar18 = puVar19;
            } while ((*(ulonglong **)(uVar9 + 8) != puVar2) || ((ulonglong *)*puVar10 != puVar2));
            *puVar10 = uVar9;
            *(ulonglong **)(uVar9 + 8) = puVar10;
            *(int *)(lVar16 + 0xe8) = *(int *)(lVar16 + 0xe8) + -1;
            *puVar2 = uVar20;
            *(ulonglong *)(lVar17 + 0x18) = uVar20;
LAB_140019a86:
            lVar7 = *(longlong *)(lVar17 + 0x20);
            *(undefined8 *)(puVar19 + -8) = 0x140019a8f;
            BowserDereferenceName(lVar7);
            *(undefined8 *)(puVar19 + -8) = 0x140019a9d;
            RtlDeleteElementGenericTable(lVar16 + 0x48,lVar17);
          }
          else {
            *(undefined4 *)((longlong)_Dst + 0x58) = 0;
            uVar15 = RtlNumberGenericTableElements(lVar16 + 0x48);
            if (BowserMaximumBrowseEntries < uVar15) {
              BowserDereferenceName(*(longlong *)((longlong)_Dst + 0x20));
              RtlDeleteElementGenericTable(lVar16 + 0x48,_Dst);
              puVar19 = auStack_168;
              _DAT_14000d2d4 = _DAT_14000d2d4 + 1;
              goto LAB_140019b1e;
            }
LAB_14001993c:
            puVar19 = auStack_168;
            bVar12 = BowserIsLegalBackupBrowser
                               ((longlong)_Dst,(ushort *)(*(longlong *)(lVar6 + 0x38) + 0x88));
            if (bVar12) {
              plVar1 = (longlong *)((longlong)_Dst + 0x10);
              plVar8 = (longlong *)(lVar16 + 0xd8);
              lVar17 = *plVar8;
              puVar18 = auStack_168;
              if (*(longlong **)(lVar17 + 8) != plVar8) goto LAB_140019a29;
              *plVar1 = lVar17;
              *(longlong **)((longlong)_Dst + 0x18) = plVar8;
              *(longlong **)(lVar17 + 8) = plVar1;
              *plVar8 = (longlong)plVar1;
              *(int *)(lVar16 + 0xe8) = *(int *)(lVar16 + 0xe8) + 1;
            }
            uVar15 = (uint)*(ushort *)((longlong)_Dst + 0x52);
            local_110 = (uint)*(ushort *)((longlong)_Dst + 0x52);
            lVar16 = BowserGetCurrentTime();
            iStack_10c = (int)lVar16 + uVar15 * 3;
            *(int *)((longlong)_Dst + 4) = iStack_10c;
          }
        }
LAB_140019b1e:
        *(undefined8 *)(puVar19 + -8) = 0x140019b28;
        ExReleaseResourceLite(lVar6 + 0x68);
        *(undefined8 *)(puVar19 + -8) = 0x140019b3d;
        ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
        LOCK();
        piVar3 = (int *)(lVar5 + 8);
        iVar14 = *piVar3;
        *piVar3 = *piVar3 + -1;
        UNLOCK();
        if (iVar14 == 1) {
          *(undefined8 *)(puVar19 + -8) = 0x140019bcf;
          BowserFreeTransportName(lVar5);
        }
        *(undefined8 *)(puVar19 + -8) = 0x140019b62;
        ExReleaseResourceLite(&BowserTransportDatabaseResource);
        *(undefined8 *)(puVar19 + -8) = 0x140019b77;
        ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
        LOCK();
        piVar3 = (int *)(lVar6 + 4);
        iVar14 = *piVar3;
        *piVar3 = *piVar3 + -1;
        UNLOCK();
        if (iVar14 == 1) {
          *(undefined8 *)(puVar19 + -8) = 0x140019c05;
          BowserpFreeTransport(lVar6);
        }
        *(undefined8 *)(puVar19 + -8) = 0x140019b94;
        ExReleaseResourceLite(&BowserTransportDatabaseResource);
        goto LAB_140019b99;
      }
    }
    BowserLogIllegalName(iVar14,pvStack_138,(ushort)local_140);
  }
  BowserFreeViewBuffer(param_1);
  BowserDereferenceTransportName(lVar5);
  BowserDereferenceTransport(lVar6);
  puVar19 = auStack_168;
LAB_140019b99:
  *(undefined8 *)(puVar19 + -8) = 0x140019ba9;
  return;
}



===== BowserpTdiSetEventHandler @ 140019c10 =====

int BowserpTdiSetEventHandler
              (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              undefined8 param_5)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  lVar3 = IoAllocateIrp(*(undefined1 *)(param_1 + 0x4c),0);
  if (lVar3 == 0) {
    iVar2 = -0x3fffff66;
  }
  else {
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    local_28 = 0;
    uStack_20 = 0;
    *(undefined8 *)(lVar1 + -0x10) = 0;
    *(undefined8 *)(lVar1 + -8) = 0;
    *(undefined1 *)(lVar1 + -0x45) = 0;
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    *(undefined8 *)(lVar1 + -0x30) = param_5;
    *(undefined2 *)(lVar1 + -0x48) = 0xb0f;
    *(longlong *)(lVar1 + -0x20) = param_1;
    *(undefined8 *)(lVar1 + -0x18) = param_2;
    *(undefined4 *)(lVar1 + -0x40) = 4;
    *(undefined8 *)(lVar1 + -0x38) = param_4;
    local_18 = 0;
    BowserReferenceDiscardableCode(3);
    KeInitializeEvent(&local_28,0,0);
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    *(code **)(lVar1 + -0x10) = BowserCompleteTdiRequest;
    *(undefined8 **)(lVar1 + -8) = &local_28;
    *(undefined1 *)(lVar1 + -0x45) = 0xe0;
    uVar4 = IoGetRelatedDeviceObject(param_2);
    iVar2 = IofCallDriver(uVar4,lVar3);
    if (iVar2 == 0x103) {
      iVar2 = KeWaitForSingleObject(&local_28,0,0,0,0);
      if (iVar2 < 0) {
                    /* WARNING: Subroutine does not return */
        KeBugCheck(0x29a);
      }
      iVar2 = *(int *)(lVar3 + 0x30);
    }
    RdrDereferenceDiscardableCode(3);
    IoFreeIrp(lVar3);
  }
  return iVar2;
}



===== BowserUpdateProviderInformation @ 140019d90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int BowserUpdateProviderInformation(longlong *param_1)

{
  int iVar1;
  int iVar2;
  longlong *plVar3;
  int iVar4;
  char cVar5;
  char cVar6;
  undefined1 auStack_68 [32];
  longlong local_48;
  undefined8 uStack_40;
  int iStack_3c;
  ulonglong local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_68;
  local_28 = 0;
  local_48 = 0;
  uStack_40 = 0;
  cVar5 = '\0';
  cVar6 = '\0';
  local_38 = 0;
  uStack_30 = 0;
  ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
  iVar4 = *(int *)((longlong)param_1 + 0x154);
  plVar3 = &local_48;
  iVar2 = BowserDetermineProviderInformation
                    (param_1 + 6,(longlong)plVar3,(uint *)((longlong)param_1 + 0x154));
  if (-1 < iVar2) {
    if (iStack_3c == 0) {
      iVar2 = -0x3fffff3b;
    }
    else {
      *(int *)(param_1[1] + 0x40) = iStack_3c;
      *(byte *)((longlong)param_1 + 0x15a) = (byte)((uint)local_38 >> 10) & 1;
      if ((local_38 & 0x1000) != 0) {
        *(undefined1 *)((longlong)param_1 + 0x15b) = 1;
      }
      if ((*(char *)((longlong)param_1 + 0x15b) != '\0') ||
         (*(int *)((longlong)param_1 + 0x154) == 0)) {
        cVar5 = '\x01';
        cVar6 = '\x01';
      }
      if (*(int *)((longlong)param_1 + 0x154) != -1) {
        if (((iVar4 == 0) || (*(char *)((longlong)param_1 + 0x15d) != '\0')) ||
           (*(int *)((longlong)param_1 + 0x154) == iVar4)) {
          iVar4 = -1;
        }
        plVar3 = BowserTransportHead;
        if ((longlong **)BowserTransportHead != &BowserTransportHead) {
          do {
            if (((*(char *)((longlong)plVar3 + 0x14e) == '\0') &&
                (iVar1 = *(int *)((longlong)plVar3 + 0x144), iVar1 != -1)) &&
               ((*(char *)((longlong)plVar3 + 0x14b) == '\0' && (plVar3 + -2 != param_1)))) {
              if (*(char *)((longlong)plVar3 + 0x14d) == '\0') {
                if ((iVar1 == *(int *)((longlong)param_1 + 0x154)) &&
                   (cVar6 = cVar5,
                   *(longlong *)(plVar3[-1] + 0x38) == *(longlong *)(param_1[1] + 0x38))) {
                  cVar6 = '\x01';
                  cVar5 = '\x01';
                }
              }
              else if (iVar1 == iVar4) {
                *(undefined1 *)((longlong)plVar3 + 0x14d) = 0;
              }
            }
            plVar3 = (longlong *)*plVar3;
          } while ((longlong **)plVar3 != &BowserTransportHead);
        }
      }
      if ((cVar6 != '\0') && (*(char *)((longlong)param_1 + 0x15d) == '\0')) {
        *(char *)((longlong)param_1 + 0x15d) = cVar6;
        BowserLoseElection(param_1[1],plVar3);
        goto LAB_140019ed9;
      }
    }
  }
  *(char *)((longlong)param_1 + 0x15d) = cVar6;
LAB_140019ed9:
  ExReleaseResourceLite(&BowserTransportDatabaseResource);
  return iVar2;
}



===== BowserSubmitTdiRequest @ 140019fa0 =====

int BowserSubmitTdiRequest(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  BowserReferenceDiscardableCode(3);
  KeInitializeEvent(&local_28,0,0);
  lVar1 = *(longlong *)(param_2 + 0xb8);
  *(code **)(lVar1 + -0x10) = BowserCompleteTdiRequest;
  *(undefined8 **)(lVar1 + -8) = &local_28;
  *(undefined1 *)(lVar1 + -0x45) = 0xe0;
  uVar3 = IoGetRelatedDeviceObject(param_1);
  iVar2 = IofCallDriver(uVar3,param_2);
  if ((-1 < iVar2) && (iVar2 == 0x103)) {
    iVar2 = KeWaitForSingleObject(&local_28,0,0,0,0);
    if (iVar2 < 0) {
                    /* WARNING: Subroutine does not return */
      KeBugCheck(0x29a);
    }
    iVar2 = *(int *)(param_2 + 0x30);
  }
  RdrDereferenceDiscardableCode(3);
  return iVar2;
}



===== BowserGetBrowserServerList @ 14001a090 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int BowserGetBrowserServerList
              (ulonglong param_1,longlong param_2,longlong param_3,longlong *param_4,uint *param_5)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  longlong lVar4;
  byte *pbVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  byte *pbVar12;
  undefined1 auStackY_108 [32];
  ulonglong local_b0;
  void *pvStack_a8;
  int local_a0;
  undefined4 local_9c;
  ulonglong local_98 [2];
  uint *local_88;
  byte *local_80;
  longlong *local_78;
  longlong local_70;
  char local_68 [32];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_108;
  local_88 = param_5;
  iVar3 = 0;
  pbVar5 = (byte *)0x0;
  local_80 = (byte *)0x0;
  uVar7 = *(ulonglong *)(param_2 + 8);
  local_b0 = param_1;
  local_98[0] = uVar7;
  local_78 = param_4;
  local_70 = param_2;
  BowserReferenceDiscardableCode(3);
  *param_4 = 0;
  *param_5 = 0;
  local_a0 = 3;
  lVar4 = ExAllocatePool2(0x42,*(undefined4 *)(param_2 + 0x40),0x6c62424c);
  *(longlong *)(param_2 + 0x58) = lVar4;
  if (lVar4 == 0) {
    iVar3 = -0x3fffff66;
  }
  else {
    ExInterlockedAddUlong(param_2 + 0x44,1);
    iVar9 = 3;
    while (iVar10 = iVar9 + -1, local_a0 = iVar10, iVar9 != 0) {
      local_9c = 0;
      KeResetEvent(param_2 + 0x360);
      uVar7 = BowserSendBackupListRequest(param_2,param_3);
      if ((int)uVar7 < 0) goto LAB_14001a1fc;
      iVar3 = KeWaitForSingleObject(param_2 + 0x360,0,0,0);
      if ((iVar3 == 0x102) &&
         (cVar2 = PsIsThreadTerminating(*(undefined8 *)(local_b0 + 0x98)), cVar2 != '\0')) {
        iVar3 = -0x3ffffee0;
        goto LAB_14001a538;
      }
      if (iVar3 != 0x102) {
        uVar7 = local_98[0];
        break;
      }
      local_9c = 1;
      uVar8 = BowserTimeUp();
      uVar7 = local_98[0];
      *(int *)(local_98[0] + 0x10c) = (int)uVar8;
      iVar9 = iVar10;
      if (BowserLogElectionPackets != '\0') {
        BowserWriteErrorLogEntry(0x40001f4d,0,(void *)0x0,0,1,*(longlong *)(local_98[0] + 0x38));
      }
    }
    if (iVar3 == 0x102) {
      if (((*(int *)(uVar7 + 0xf8) == 0) ||
          (((param_3 != 0 &&
            (cVar2 = RtlEqualUnicodeString(param_3,*(longlong *)(param_2 + 0x38) + 0x58,1),
            cVar2 == '\0')) ||
           (uVar8 = BowserTimeUp(), 15000 < (uint)((int)uVar8 - *(int *)(uVar7 + 0x11c)))))) &&
         (local_68[0] = '\b', *(char *)(*(longlong *)(param_2 + 8) + 0x15d) == '\0')) {
        local_68[1] = 0;
        local_68[2] = '\0';
        local_68[3] = '\0';
        local_68[4] = '\0';
        local_68[5] = '\0';
        local_68[6] = '\0';
        local_68[7] = '\0';
        local_68[8] = '\0';
        local_68[9] = '\0';
        local_68[0xe] = 0;
        local_68[10] = '\0';
        local_68[0xb] = '\0';
        local_68[0xc] = '\0';
        local_68[0xd] = '\0';
        BowserSendSecondClassMailslot
                  (param_2,param_3,7,local_68,0xf,'\x01',"\\MAILSLOT\\BROWSE",(ushort *)0x0);
      }
LAB_14001a1fc:
      iVar3 = -0x3ffffde4;
    }
    else if (-1 < iVar3) {
      pbVar5 = (byte *)BowserGetBackupServerListFromTransport(param_2);
      bVar1 = *pbVar5;
      *param_5 = (uint)bVar1;
      local_80 = pbVar5;
      lVar4 = ExAllocatePool2(0x100,(ulonglong)(uint)bVar1 << 3,0x6c73424c);
      *param_4 = lVar4;
      if (lVar4 == 0) {
        iVar3 = -0x3fffff66;
      }
      else {
        pbVar12 = pbVar5 + 5;
        for (uVar11 = 0; uVar11 < *pbVar5; uVar11 = uVar11 + 1) {
          local_b0 = 0;
          pvStack_a8 = (void *)0x0;
          local_98[0] = 0;
          local_98[1] = 0;
          RtlInitAnsiString(local_98,pbVar12);
          iVar3 = RtlOemStringToUnicodeString(&local_b0,local_98,1);
          if (iVar3 < 0) goto LAB_14001a538;
          lVar4 = (ulonglong)uVar11 * 8;
          uVar6 = ExAllocatePool2(0x102,(local_b0 & 0xffff) + 6,0x7362424c);
          *(undefined8 *)(lVar4 + *param_4) = uVar6;
          if (*(undefined4 **)(lVar4 + *param_4) == (undefined4 *)0x0) {
            RtlFreeUnicodeString(&local_b0);
            iVar3 = -0x3fffff66;
            goto LAB_14001a538;
          }
          **(undefined4 **)(lVar4 + *param_4) = 0x5c005c;
          memcpy((void *)(*(longlong *)(lVar4 + *param_4) + 4),pvStack_a8,local_b0 >> 0x10 & 0xffff)
          ;
          pbVar12 = pbVar12 + (local_98[0] & 0xffff) + 1;
          RtlFreeUnicodeString(&local_b0);
        }
        if ((param_3 == 0) ||
           (cVar2 = RtlEqualUnicodeString(*(longlong *)(param_2 + 0x38) + 0x58), cVar2 != '\0')) {
          cVar2 = '\x01';
        }
        else {
          cVar2 = '\0';
        }
        BowserShuffleBrowserServerList
                  ((undefined8 *)*param_4,*param_5,cVar2,*(longlong *)(param_2 + 0x38));
        iVar3 = 0;
      }
    }
  }
LAB_14001a538:
  if (iVar3 < 0) {
    if (*param_4 != 0) {
      uVar11 = 0;
      if (*param_5 != 0) {
        do {
          lVar4 = *(longlong *)(*param_4 + (ulonglong)uVar11 * 8);
          if (lVar4 != 0) {
            ExFreePoolWithTag(lVar4,0);
          }
          uVar11 = uVar11 + 1;
        } while (uVar11 < *param_5);
      }
      ExFreePoolWithTag(*param_4,0);
      *param_4 = 0;
    }
    *param_5 = 0;
    BowserFreeTransportBackupList(param_2);
  }
  if (pbVar5 != (byte *)0x0) {
    ExFreePoolWithTag(pbVar5,0);
  }
  RdrDereferenceDiscardableCode(3);
  return iVar3;
}



===== BowserDetermineProviderInformation @ 14001a5f0 =====

int BowserDetermineProviderInformation(undefined8 param_1,longlong param_2,uint *param_3)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  undefined8 uVar8;
  longlong local_res8;
  longlong local_res20;
  undefined4 uVar9;
  ulonglong in_stack_ffffffffffffff48;
  undefined4 uVar10;
  undefined8 local_88;
  longlong local_80 [8];
  undefined8 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  local_res20 = 0;
  local_res8 = 0;
  local_80[5] = 0x30;
  local_40 = 0x240;
  local_80[3] = 0;
  local_80[4] = 0;
  lVar7 = 0;
  local_80[6] = 0;
  local_38 = 0;
  uStack_30 = 0;
  uVar10 = 0;
  local_80[7] = param_1;
  iVar3 = IoCreateFile(&local_res20,0xc0100000,local_80 + 5,local_80 + 3,0,0x80,1,3,
                       in_stack_ffffffffffffff48 & 0xffffffff00000000,0,0,0,0,0x300);
  if (-1 < iVar3) {
    uVar9 = 0;
    iVar3 = ObReferenceObjectByHandle
                      (local_res20,0,*(undefined8 *)IoFileObjectType_exref,0,&local_res8,0);
    if (-1 < iVar3) {
      lVar5 = IoGetRelatedDeviceObject(local_res8);
      lVar6 = IoAllocateIrp(*(undefined1 *)(lVar5 + 0x4c),0);
      local_88 = lVar6;
      if (lVar6 != 0) {
        lVar7 = IoAllocateMdl(param_2,0x28,0,0,0);
        local_80[0] = lVar7;
        if (lVar7 != 0) {
          MmProbeAndLockPages(lVar7,0,1);
          lVar2 = local_res8;
          *(longlong *)(lVar6 + 8) = lVar7;
          lVar1 = *(longlong *)(lVar6 + 0xb8);
          *(undefined8 *)(lVar1 + -0x10) = 0;
          *(undefined8 *)(lVar1 + -8) = 0;
          *(undefined1 *)(lVar1 + -0x45) = 0;
          lVar1 = *(longlong *)(lVar6 + 0xb8);
          *(undefined2 *)(lVar1 + -0x48) = 0xc0f;
          *(longlong *)(lVar1 + -0x20) = lVar5;
          *(longlong *)(lVar1 + -0x18) = local_res8;
          *(undefined4 *)(lVar1 + -0x40) = 2;
          *(undefined8 *)(lVar1 + -0x38) = 0;
          local_80[0] = 0;
          local_80[1] = 0;
          local_80[2] = 0;
          BowserReferenceDiscardableCode(3);
          KeInitializeEvent(local_80,0,0);
          lVar5 = *(longlong *)(lVar6 + 0xb8);
          *(code **)(lVar5 + -0x10) = BowserCompleteTdiRequest;
          *(longlong **)(lVar5 + -8) = local_80;
          *(undefined1 *)(lVar5 + -0x45) = 0xe0;
          uVar8 = IoGetRelatedDeviceObject(lVar2);
          iVar3 = IofCallDriver(uVar8,lVar6);
          if ((-1 < iVar3) && (iVar3 == 0x103)) {
            iVar3 = KeWaitForSingleObject(local_80,0,0,0,0);
            if (iVar3 < 0) {
                    /* WARNING: Subroutine does not return */
              KeBugCheck(0x29a);
            }
            iVar3 = *(int *)(lVar6 + 0x30);
          }
          RdrDereferenceDiscardableCode(3);
          IoFreeIrp(lVar6);
          if ((*(uint *)(param_2 + 0x10) & 0x400) == 0) {
            *param_3 = 0xffffffff;
          }
          else {
            local_80[0] = 0;
            local_80[1] = 0;
            iVar4 = ZwDeviceIoControlFile
                              (local_res20,0,0,0,local_80,CONCAT44(uVar9,0x2100aa),0,0,&local_88,
                               CONCAT44(uVar10,8));
            if (iVar4 < 0) {
              *param_3 = 0xffffffff;
            }
            else {
              *param_3 = local_88._4_4_ & (uint)local_88;
            }
          }
          goto LAB_14001a873;
        }
        IoFreeIrp(lVar6);
      }
      iVar3 = -0x3fffff66;
    }
  }
LAB_14001a873:
  if (lVar7 != 0) {
    if ((*(byte *)(lVar7 + 10) & 2) != 0) {
      MmUnlockPages(lVar7);
    }
    IoFreeMdl(lVar7);
  }
  if (local_res8 != 0) {
    ObfDereferenceObject();
  }
  if (local_res20 != 0) {
    ZwClose();
  }
  return iVar3;
}



===== BowserOpenNetbiosAddress @ 14001a9c0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int BowserOpenNetbiosAddress(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  longlong lVar3;
  bool bVar4;
  char cVar5;
  int iVar6;
  undefined4 *puVar7;
  longlong lVar8;
  longlong lVar9;
  undefined8 uVar10;
  longlong lVar11;
  longlong local_res8;
  longlong local_res10;
  longlong local_res18;
  longlong local_res20;
  undefined8 in_stack_ffffffffffffff00;
  undefined4 uVar12;
  undefined8 in_stack_ffffffffffffff08;
  undefined4 uVar13;
  ulonglong in_stack_ffffffffffffff18;
  undefined4 *puVar14;
  undefined1 uVar15;
  undefined8 local_a0;
  undefined8 uStack_98;
  longlong local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  ulonglong uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  
  uVar12 = (undefined4)((ulonglong)in_stack_ffffffffffffff00 >> 0x20);
  uVar13 = (undefined4)((ulonglong)in_stack_ffffffffffffff08 >> 0x20);
  lVar1 = *(longlong *)(param_1 + 8);
  local_a0 = 0;
  uStack_98 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_80 = 0;
  uStack_78 = uStack_78 & 0xffffffff00000000;
  local_58 = 0;
  uStack_50 = 0;
  local_res20 = 0;
  local_res8 = 0;
  bVar4 = false;
  lVar11 = param_2 + 0x3f0;
  local_res10 = param_2;
  local_res18 = lVar11;
  lVar8 = lVar1;
  cVar5 = ExAcquireRundownProtection(lVar11);
  if (cVar5 == '\0') {
    iVar6 = -0x3fffffaa;
    goto LAB_14001ae5d;
  }
  bVar4 = true;
  uVar15 = 1;
  puVar7 = (undefined4 *)ExAllocatePool2(0x102,0x46,0x6165424c);
  if (puVar7 == (undefined4 *)0x0) {
    iVar6 = -0x3fffff66;
  }
  else {
    *puVar7 = 0;
    *(undefined2 *)(puVar7 + 1) = 0x1000;
    builtin_strncpy((char *)(puVar7 + 2),"Transpor",8);
    builtin_strncpy((char *)(puVar7 + 4),"tAddress",8);
    *(undefined1 *)(puVar7 + 6) = 0;
    *(undefined2 *)((longlong)puVar7 + 6) = 0x1a;
    puVar2 = *(undefined8 **)(lVar1 + 0x38);
    uVar10 = puVar2[1];
    *(undefined8 *)((longlong)puVar7 + 0x19) = *puVar2;
    *(undefined8 *)((longlong)puVar7 + 0x21) = uVar10;
    *(undefined8 *)((longlong)puVar7 + 0x29) = puVar2[2];
    *(undefined2 *)((longlong)puVar7 + 0x31) = *(undefined2 *)(puVar2 + 3);
    local_a0 = CONCAT44(local_a0._4_4_,0x30);
    uStack_98 = 0;
    uStack_88 = CONCAT44(uStack_88._4_4_,0x240);
    local_90 = *(longlong *)(param_2 + 8) + 0x30;
    local_80 = 0;
    uStack_78 = 0;
    puVar14 = puVar7;
    iVar6 = IoCreateFile(&local_res20,0xc0100000,&local_a0,&local_58,0,CONCAT44(uVar12,0x80),
                         CONCAT44(uVar13,1),3,in_stack_ffffffffffffff18 & 0xffffffff00000000,puVar7,
                         0x33,0,0,0x300,uVar15,puVar7,lVar8);
    ExFreePoolWithTag(puVar7,0);
    if (-1 < iVar6) {
      iVar6 = (int)local_58;
      if (-1 < (int)local_58) {
        uVar12 = 0;
        iVar6 = ObReferenceObjectByHandle
                          (local_res20,0,*(undefined8 *)IoFileObjectType_exref,0,&local_res8,0);
        if (-1 < iVar6) {
          ObfReferenceObject(local_res8);
          lVar8 = IoGetRelatedDeviceObject(local_res8);
          lVar11 = local_res8;
          lVar9 = IoAllocateIrp(*(undefined1 *)(lVar8 + 0x4c),0);
          if (lVar9 == 0) {
            iVar6 = -0x3fffff66;
          }
          else {
            lVar3 = *(longlong *)(lVar9 + 0xb8);
            *(undefined8 *)(lVar3 + -0x10) = 0;
            *(undefined8 *)(lVar3 + -8) = 0;
            *(undefined1 *)(lVar3 + -0x45) = 0;
            lVar3 = *(longlong *)(lVar9 + 0xb8);
            *(undefined2 *)(lVar3 + -0x48) = 0xb0f;
            *(longlong *)(lVar3 + -0x20) = lVar8;
            *(longlong *)(lVar3 + -0x18) = lVar11;
            *(undefined4 *)(lVar3 + -0x40) = 4;
            *(code **)(lVar3 + -0x38) = BowserTdiReceiveDatagramHandler;
            *(longlong *)(lVar3 + -0x30) = lVar1;
            local_70 = 0;
            uStack_68 = 0;
            local_60 = 0;
            BowserReferenceDiscardableCode(3);
            KeInitializeEvent(&local_70,0,0);
            lVar3 = *(longlong *)(lVar9 + 0xb8);
            *(code **)(lVar3 + -0x10) = BowserCompleteTdiRequest;
            *(undefined8 **)(lVar3 + -8) = &local_70;
            *(undefined1 *)(lVar3 + -0x45) = 0;
            *(undefined1 *)(lVar3 + -0x45) = 0x40;
            *(undefined1 *)(lVar3 + -0x45) = 0xc0;
            *(undefined1 *)(lVar3 + -0x45) = 0xe0;
            uVar10 = IoGetRelatedDeviceObject(lVar11);
            iVar6 = IofCallDriver(uVar10,lVar9);
            if (iVar6 == 0x103) {
              iVar6 = KeWaitForSingleObject(&local_70,0,0,0,0);
              if (iVar6 < 0) {
                    /* WARNING: Subroutine does not return */
                KeBugCheck(0x29a);
              }
              iVar6 = *(int *)(lVar9 + 0x30);
            }
            RdrDereferenceDiscardableCode(3);
            IoFreeIrp(lVar9);
            if (-1 < iVar6) {
              if (*(char *)(*(longlong *)(param_2 + 8) + 0x15a) != '\0') {
                local_48 = 0;
                uStack_40 = 0;
                iVar6 = ZwDeviceIoControlFile
                                  (local_res20,0,0,0,&local_48,CONCAT44(uVar12,0x2180c4),0,0,0,
                                   (ulonglong)puVar14 & 0xffffffff00000000);
                if (iVar6 < 0) goto LAB_14001ad94;
              }
              ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
              *(longlong *)(lVar1 + 0x20) = local_res8;
              *(longlong *)(lVar1 + 0x28) = lVar8;
              *(longlong *)(param_1 + 0x38) = local_res20;
              local_res20 = 0;
              ExReleaseResourceLite(&BowserTransportDatabaseResource);
            }
          }
        }
      }
    }
  }
LAB_14001ad94:
  lVar11 = local_res18;
LAB_14001ae5d:
  if (local_res8 != 0) {
    ObfDereferenceObject();
  }
  if (local_res20 != 0) {
    ZwClose();
  }
  if (iVar6 < 0) {
    if (*(char *)(lVar1 + 4) == '\x06') {
      if (DAT_14000d888 < 5) {
        *(int *)(&DAT_14000d890 + (ulonglong)DAT_14000d888 * 4) = iVar6;
      }
      DAT_14000d888 = DAT_14000d888 + 1;
    }
    BowserCloseNetbiosAddress(lVar1);
  }
  else if (*(char *)(lVar1 + 4) == '\x06') {
    _BrOneD = _BrOneD + 1;
  }
  if (bVar4) {
    ExReleaseRundownProtection(lVar11);
  }
  return iVar6;
}



===== BowserReferenceDiscardableCode @ 14001af10 =====

void BowserReferenceDiscardableCode(int param_1)

{
  int iVar1;
  char cVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  lVar3 = (longlong)param_1;
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(&RdrDiscardableCodeLock,1);
  iVar1 = *(int *)(&RdrSectionInfo + lVar3 * 0x48);
  *(int *)(&RdrSectionInfo + lVar3 * 0x48) = iVar1 + 1;
  if (iVar1 == 0) {
    if ((&DAT_14000d5f8)[lVar3 * 9] != 0) {
      (&DAT_14000d5f5)[lVar3 * 0x48] = 1;
      cVar2 = KeCancelTimer();
      if (cVar2 != '\0') {
        ExFreePoolWithTag((&DAT_14000d5f8)[lVar3 * 9],0);
        (&DAT_14000d5f8)[lVar3 * 9] = 0;
        KeSetEvent(&DAT_14000d600 + lVar3 * 0x48,0,0);
      }
    }
    if ((&DAT_14000d5f4)[lVar3 * 0x48] == '\0') {
      if (*(longlong *)(&DAT_14000d618 + lVar3 * 0x48) != 0) {
        uVar4 = MmLockPagableDataSection();
        (&DAT_14000d620)[lVar3 * 9] = uVar4;
      }
      if (*(longlong *)(&DAT_14000d628 + lVar3 * 0x48) != 0) {
        uVar4 = MmLockPagableDataSection();
        (&DAT_14000d630)[lVar3 * 9] = uVar4;
      }
      (&DAT_14000d5f4)[lVar3 * 0x48] = 1;
    }
  }
  ExReleaseResourceLite(&RdrDiscardableCodeLock);
  KeLeaveCriticalRegion();
  return;
}



===== RdrDereferenceDiscardableCode @ 14001b030 =====

void RdrDereferenceDiscardableCode(int param_1)

{
  longlong lVar1;
  int *piVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar3 = (longlong)param_1;
  lVar1 = lVar3 * 0x48;
  piVar2 = (int *)(&RdrSectionInfo + lVar1);
  ExAcquireResourceExclusiveLite(&RdrDiscardableCodeLock,1);
  *piVar2 = *piVar2 + -1;
  if (((*piVar2 == 0) && ((&DAT_14000d5f8)[lVar3 * 9] == 0)) &&
     (lVar4 = ExAllocatePool2(0x42,0xa0,0x77627852), lVar4 != 0)) {
    (&DAT_14000d5f8)[lVar3 * 9] = lVar4;
    KeInitializeTimer(lVar4);
    KeClearEvent(&DAT_14000d600 + lVar1);
    (&DAT_14000d5f5)[lVar1] = 0;
    *(code **)(lVar4 + 0x90) = RdrDiscardableCodeRoutine;
    *(int **)(lVar4 + 0x98) = piVar2;
    *(undefined8 *)(lVar4 + 0x80) = 0;
    KeInitializeDpc(lVar4 + 0x40,RdrDiscardableCodeDpcRoutine,lVar4 + 0x80);
    KeSetTimer(lVar4,0xfffffffffa0a1f00,lVar4 + 0x40);
    ExReleaseResourceLite(&RdrDiscardableCodeLock);
    return;
  }
  ExReleaseResourceLite(&RdrDiscardableCodeLock);
  return;
}



===== BowserSendSecondClassMailslot @ 14001b170 =====

ulonglong BowserSendSecondClassMailslot
                    (longlong param_1,longlong param_2,int param_3,char *param_4,uint param_5,
                    char param_6,void *param_7,ushort *param_8)

{
  undefined8 *puVar1;
  ulonglong uVar2;
  longlong lVar4;
  longlong lVar3;
  void *_Dst;
  ulonglong uVar5;
  
  lVar3 = -1;
  do {
    lVar4 = lVar3;
    lVar3 = lVar4 + 1;
  } while (*(char *)((longlong)param_7 + lVar3) != '\0');
  uVar5 = (ulonglong)param_5 + 1 + lVar3;
  uVar2 = uVar5 + 0x45;
  if ((uVar5 <= uVar2) && (uVar2 < 0x100000000)) {
    puVar1 = (undefined8 *)ExAllocatePool2(0x40,uVar2 & 0xffffffff,0x686d424c);
    if (puVar1 != (undefined8 *)0x0) {
      *(undefined4 *)puVar1 = 0x424d53ff;
      *(undefined1 *)((longlong)puVar1 + 4) = 0x25;
      *(undefined1 *)(puVar1 + 4) = 0x11;
      *(short *)((longlong)puVar1 + 0x23) = (short)param_5;
      *(undefined4 *)((longlong)puVar1 + 0x2d) = 1000;
      *(short *)((longlong)puVar1 + 0x37) = (short)param_5;
      _Dst = (void *)((longlong)puVar1 + lVar4 + 0x47);
      *(undefined1 *)((longlong)puVar1 + 0x3b) = 3;
      *(undefined4 *)((longlong)puVar1 + 0x3d) = 0x10001;
      *(undefined2 *)((longlong)puVar1 + 0x41) = 2;
      *(short *)((longlong)puVar1 + 0x39) = (short)_Dst - (short)puVar1;
      *(short *)((longlong)puVar1 + 0x43) = (short)uVar5;
      memcpy((void *)((longlong)puVar1 + 0x45),param_7,lVar4 + 2);
      memcpy(_Dst,param_4,(ulonglong)param_5);
      uVar2 = BowserSendDatagram(param_1,param_2,param_3,puVar1,(uint)uVar2,param_6,param_8,
                                 *param_4 == '\x0f');
      return uVar2;
    }
  }
  return 0xc000009a;
}



===== BowserSendDatagram @ 14001b2e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong BowserSendDatagram(longlong param_1,longlong param_2,int param_3,undefined8 *param_4,
                            uint param_5,char param_6,ushort *param_7,char param_8)

{
  short sVar1;
  ushort uVar2;
  longlong lVar3;
  uint uVar4;
  int iVar5;
  longlong *plVar6;
  undefined4 *puVar7;
  longlong lVar8;
  longlong lVar9;
  ulonglong uVar10;
  char cVar11;
  ulonglong uVar12;
  undefined8 uVar13;
  uint7 uVar14;
  undefined8 *puVar15;
  longlong lVar16;
  longlong lVar17;
  undefined1 auStack_d8 [32];
  undefined8 local_b8;
  undefined1 local_a8 [4];
  uint local_a4;
  int local_a0;
  undefined8 *local_98;
  longlong local_90;
  uint local_88;
  ushort *local_80;
  char *local_78;
  undefined8 local_70;
  longlong lStack_68;
  ushort local_60 [4];
  undefined1 *local_58;
  undefined1 local_50 [16];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_d8;
  local_a4 = param_5;
  lVar16 = 0;
  local_58 = local_50;
  local_80 = param_7;
  local_a8[0] = 0;
  local_60[0] = 0;
  local_60[1] = 0x10;
  local_60[2] = 0;
  local_60[3] = 0;
  local_a0 = param_3;
  local_90 = param_2;
  ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
  lVar8 = *(longlong *)(param_1 + 0x10);
  if (lVar8 == 0) {
LAB_14001ba58:
    ExReleaseResourceLite(&BowserTransportDatabaseResource);
    uVar12 = 0xc00000be;
    goto LAB_14001b5e7;
  }
  if (*(short *)(*(longlong *)(param_1 + 8) + 0x158) < 0) {
    lVar17 = *(longlong *)(param_1 + 0x50);
    lVar16 = *(longlong *)(param_1 + 0x48);
  }
  else {
    lVar17 = *(longlong *)(lVar8 + 0x28);
    lVar16 = *(longlong *)(lVar8 + 0x20);
  }
  if ((lVar17 == 0) || (lVar16 == 0)) goto LAB_14001ba58;
  ObfReferenceObject(lVar16);
  ExReleaseResourceLite(&BowserTransportDatabaseResource);
  plVar6 = (longlong *)ExAllocatePool2(0x42,0x30,0x7364424c);
  if (plVar6 == (longlong *)0x0) {
    uVar12 = 0xc0000017;
    goto LAB_14001b5e7;
  }
  plVar6[1] = 0;
  *plVar6 = 0;
  if (local_90 == 0) {
    local_90 = *(longlong *)(param_1 + 0x38) + 0x58;
  }
  if (-1 < *(short *)(*(longlong *)(param_1 + 8) + 0x158)) {
    plVar6[1] = (longlong)param_4;
    puVar15 = param_4;
    goto LAB_14001b403;
  }
  local_70 = 0;
  lStack_68 = 0;
  local_88 = local_a4 + 0x44;
  if (local_88 < local_a4) {
    uVar12 = 0xc000009a;
    goto LAB_14001b5bd;
  }
  local_98 = (undefined8 *)ExAllocatePool2(0x42,local_88,0x7364424c);
  plVar6[1] = (longlong)local_98;
  if (local_98 == (undefined8 *)0x0) {
    uVar12 = 0xc000009a;
    goto LAB_14001b5bd;
  }
  *local_98 = 0;
  local_98[1] = 0;
  local_98[2] = 0;
  local_98[3] = 0;
  *(undefined1 *)(local_98 + 4) = 0xfc;
  switch(local_a0) {
  case 1:
  case 0xb:
    cVar11 = '\x01';
    break;
  default:
    uVar12 = 0xc0000010;
    goto LAB_14001b5bd;
  case 6:
    cVar11 = '\x02';
    break;
  case 7:
    cVar11 = (param_8 != '\0') + '\x02';
    break;
  case 9:
  case 10:
    uVar12 = 0;
    goto LAB_14001b5bd;
  }
  *(char *)((longlong)local_98 + 0x21) = cVar11;
  *(undefined2 *)((longlong)local_98 + 0x22) = 0;
  local_70._0_4_ = CONCAT22(0x10,(undefined2)local_70);
  lStack_68 = (longlong)local_98 + 0x24;
  uVar4 = RtlUpcaseUnicodeStringToOemString(&local_70,local_90,0);
  uVar12 = (ulonglong)uVar4;
  if (-1 < (int)uVar4) {
    memcpy((void *)((local_70 & 0xffff) + lStack_68),"                ",0x10 - (local_70 & 0xffff));
    *(undefined1 *)((longlong)local_98 + 0x33) = 0;
    lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x38);
    uVar13 = *(undefined8 *)(lVar8 + 0x12);
    *(undefined8 *)((longlong)local_98 + 0x34) = *(undefined8 *)(lVar8 + 10);
    *(undefined8 *)((longlong)local_98 + 0x3c) = uVar13;
    memcpy((void *)((longlong)local_98 + 0x44),param_4,(ulonglong)local_a4);
    ExFreePoolWithTag(param_4,0);
    puVar15 = (undefined8 *)plVar6[1];
    local_a4 = local_88;
    param_7 = local_80;
LAB_14001b403:
    param_4 = (undefined8 *)0x0;
    local_98 = (undefined8 *)0x0;
    uVar13 = 0x6963424c;
    puVar7 = (undefined4 *)ExAllocatePool2(0x42,0x5a,0x6963424c);
    *plVar6 = (longlong)puVar7;
    if (puVar7 == (undefined4 *)0x0) {
      uVar12 = 0xc000009a;
    }
    else {
      *puVar7 = 0;
      *(undefined8 *)(*plVar6 + 8) = 0;
      *(undefined4 *)(*plVar6 + 0x10) = 0;
      *(undefined8 *)(*plVar6 + 0x18) = 0;
      lVar8 = *plVar6;
      puVar7 = (undefined4 *)(lVar8 + 0x30);
      *(undefined4 **)(lVar8 + 0x28) = puVar7;
      *(char *)(plVar6 + 2) = param_6;
      if (param_7 == (ushort *)0x0) {
        if (local_a0 != 6) {
LAB_14001b635:
          if (*(short *)(*(longlong *)(param_1 + 8) + 0x158) < 0) {
            *puVar7 = 1;
            *(undefined8 *)(lVar8 + 0x34) = 0x6000c;
            *(undefined4 *)(lVar8 + 0x3c) = 0xffffffff;
            *(undefined4 *)(lVar8 + 0x40) = 0x5305ffff;
            goto LAB_14001b499;
          }
          *puVar7 = 1;
          local_78 = (char *)(lVar8 + 0x3a);
          *(undefined4 *)(lVar8 + 0x34) = 0x110012;
          uVar14 = (uint7)((ulonglong)uVar13 >> 8);
          lVar9 = CONCAT71(uVar14,0x20);
          local_80 = (ushort *)0x100000;
          if (local_a0 == 7) {
            sVar1 = *(short *)(*(longlong *)(param_1 + 8) + 0x158);
            *(undefined2 *)(lVar8 + 0x38) = 1;
            lVar9 = 0;
            if (-1 < sVar1) {
              lVar9 = 0x1e;
            }
switchD_14001b969_caseD_3:
            uVar10 = BowserCanonicalizeNetBiosName((ushort *)&local_80,local_90,(char)lVar9);
            uVar12 = uVar10 & 0xffffffff;
            if ((int)uVar10 < 0) {
              BowWriteTelemetryCanonicalizeNameFailure
                        (L"BowserBuildTransportAddress",(int)uVar10,lVar9);
              goto LAB_14001b5b9;
            }
          }
          else {
            if (local_a0 != 5) {
              switch(local_a0) {
              case 1:
              case 0xb:
                lVar9 = (ulonglong)uVar14 << 8;
              case 8:
                *(undefined2 *)(lVar8 + 0x38) = 0;
                break;
              case 2:
              case 4:
                *(undefined2 *)(lVar8 + 0x38) = 1;
                lVar9 = (ulonglong)uVar14 << 8;
                break;
              case 6:
                sVar1 = *(short *)(*(longlong *)(param_1 + 8) + 0x158);
                *(undefined2 *)(lVar8 + 0x38) = 0;
                lVar9 = 0;
                if (-1 < sVar1) {
                  lVar9 = 0x1d;
                }
                break;
              case 9:
                *(undefined2 *)(lVar8 + 0x38) = 1;
                lVar9 = CONCAT71(uVar14,0x1c);
                break;
              case 10:
                *(undefined2 *)(lVar8 + 0x38) = 0;
                lVar9 = CONCAT71(uVar14,0x1b);
              }
              goto switchD_14001b969_caseD_3;
            }
            builtin_strncpy(local_78,"\x01\x02__MSBR",8);
            builtin_strncpy((char *)(lVar8 + 0x42),"OWSE__\x02\x01",8);
            *(undefined2 *)(lVar8 + 0x38) = 1;
          }
          *(undefined4 *)(*plVar6 + 0x20) = 0x1a;
          goto LAB_14001b499;
        }
        uVar13 = 0;
        if (-1 < *(short *)(*(longlong *)(param_1 + 8) + 0x158)) {
          uVar13 = 0x1d;
        }
        uVar10 = BowserCanonicalizeNetBiosName(local_60,local_90,(char)uVar13);
        uVar12 = uVar10 & 0xffffffff;
        if (-1 < (int)uVar10) {
          uVar13 = 0;
          lVar9 = RtlCompareMemory(local_58,*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x38) + 10
                                   ,0x10);
          if (lVar9 == 0x10) {
            uVar2 = *(ushort *)(*(longlong *)(param_1 + 8) + 0x138);
            if (uVar2 != 0) {
              memcpy(*(void **)(*plVar6 + 0x28),*(void **)(*(longlong *)(param_1 + 8) + 0x140),
                     (ulonglong)uVar2);
              goto LAB_14001b480;
            }
          }
          goto LAB_14001b635;
        }
        BowWriteTelemetryCanonicalizeNameFailure(L"BowserSendDatagram",(int)uVar10,uVar13);
      }
      else {
        memcpy(*(void **)(*plVar6 + 0x28),*(void **)(param_7 + 4),(ulonglong)*param_7);
        *(uint *)(*plVar6 + 0x20) = (uint)*param_7;
LAB_14001b480:
        local_a8[0] = 4;
        *(undefined4 *)(*plVar6 + 0x10) = 1;
        *(undefined1 **)(*plVar6 + 0x18) = local_a8;
LAB_14001b499:
        lVar8 = IoAllocateIrp(*(undefined1 *)(lVar17 + 0x4c),1);
        if (lVar8 == 0) {
          uVar12 = 0xc000009a;
        }
        else {
          local_b8 = 0;
          lVar9 = IoAllocateMdl(puVar15,local_a4,0,0);
          if (lVar9 == 0) {
            IoFreeIrp(lVar8);
            uVar12 = 0xc000009a;
          }
          else {
            KeInitializeEvent(plVar6 + 3,0,0);
            MmBuildMdlForNonPagedPool(lVar9);
            lVar3 = *(longlong *)(lVar8 + 0xb8);
            *(code **)(lVar3 + -0x10) = CompleteSendDatagram;
            *(longlong **)(lVar3 + -8) = plVar6;
            *(undefined1 *)(lVar3 + -0x45) = 0xe0;
            lVar3 = *(longlong *)(lVar8 + 0xb8);
            *(undefined2 *)(lVar3 + -0x48) = 0x90f;
            *(longlong *)(lVar3 + -0x20) = lVar17;
            *(longlong *)(lVar3 + -0x18) = lVar16;
            *(uint *)(lVar3 + -0x40) = local_a4;
            *(longlong *)(lVar3 + -0x38) = *plVar6;
            *(longlong *)(lVar8 + 8) = lVar9;
            uVar4 = IofCallDriver(lVar17,lVar8);
            uVar12 = (ulonglong)uVar4;
            if (param_6 == '\0') goto LAB_14001ba8b;
            if ((uVar4 == 0x103) &&
               ((iVar5 = FsRtlCancellableWaitForSingleObject(plVar6 + 3,0,0), iVar5 == -0x3ffffee0
                || (iVar5 == -0x3fffffb5)))) {
              IoCancelIrp(lVar8);
              local_b8 = 0;
              KeWaitForSingleObject(plVar6 + 3,0,0,0);
            }
            IoFreeMdl(*(undefined8 *)(lVar8 + 8));
            uVar12 = (ulonglong)*(uint *)(lVar8 + 0x30);
            IoFreeIrp(lVar8);
          }
        }
      }
LAB_14001b5b9:
      param_4 = local_98;
    }
  }
LAB_14001b5bd:
  puVar15 = (undefined8 *)plVar6[1];
  if ((puVar15 != (undefined8 *)0x0) && (puVar15 != param_4)) {
    ExFreePoolWithTag(puVar15,0);
  }
  if (*plVar6 != 0) {
    ExFreePoolWithTag(*plVar6,0);
  }
  ExFreePoolWithTag(plVar6,0);
LAB_14001b5e7:
  if (param_4 != (undefined8 *)0x0) {
    ExFreePoolWithTag(param_4,0);
  }
  if (lVar16 == 0) {
    return uVar12;
  }
LAB_14001ba8b:
  ObfDereferenceObject(lVar16);
  return uVar12;
}



===== BowserSendBackupListRequest @ 14001bab0 =====

ulonglong BowserSendBackupListRequest(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined2 uStackX_a;
  undefined2 uStackX_c;
  
  uStackX_a = (undefined2)*(undefined4 *)(param_1 + 0x44);
  uStackX_c = (undefined2)((uint)*(undefined4 *)(param_1 + 0x44) >> 0x10);
  if (param_2 == 0) {
    lVar3 = *(longlong *)(param_1 + 0x38) + 0x58;
  }
  else {
    lVar3 = param_2;
  }
  puVar1 = (undefined8 *)ExAllocatePool2(0x40,0x5c,0x686d424c);
  if (puVar1 == (undefined8 *)0x0) {
    uVar4 = 0xc000009a;
  }
  else {
    *(undefined4 *)puVar1 = 0x424d53ff;
    *(undefined1 *)((longlong)puVar1 + 4) = 0x25;
    *(undefined1 *)(puVar1 + 4) = 0x11;
    *(undefined2 *)((longlong)puVar1 + 0x23) = 6;
    *(undefined4 *)((longlong)puVar1 + 0x2d) = 1000;
    *(undefined2 *)((longlong)puVar1 + 0x37) = 6;
    *(undefined1 *)((longlong)puVar1 + 0x3b) = 3;
    *(short *)((longlong)puVar1 + 0x39) =
         (short)(undefined4 *)((longlong)puVar1 + 0x56) - (short)puVar1;
    *(undefined4 *)((longlong)puVar1 + 0x3d) = 0x10001;
    *(undefined4 *)((longlong)puVar1 + 0x41) = 0x170002;
    builtin_strncpy((char *)((longlong)puVar1 + 0x45),"\\MAILSLO",8);
    builtin_strncpy((char *)((longlong)puVar1 + 0x4d),"T\\BROWSE",8);
    *(undefined1 *)((longlong)puVar1 + 0x55) = 0;
    *(undefined4 *)((longlong)puVar1 + 0x56) = CONCAT22(uStackX_a,0x409);
    *(undefined2 *)((longlong)puVar1 + 0x5a) = uStackX_c;
    uVar4 = BowserSendDatagram(param_1,lVar3,6,puVar1,0x5c,'\x01',(ushort *)0x0,'\0');
    uVar4 = uVar4 & 0xffffffff;
  }
  if (-1 < *(short *)(*(longlong *)(param_1 + 8) + 0x158)) {
    if (param_2 == 0) {
      param_2 = *(longlong *)(param_1 + 0x38) + 0x58;
    }
    puVar1 = (undefined8 *)ExAllocatePool2(0x40,0x5c,0x686d424c);
    if (puVar1 != (undefined8 *)0x0) {
      *(undefined4 *)puVar1 = 0x424d53ff;
      *(undefined1 *)((longlong)puVar1 + 4) = 0x25;
      *(undefined1 *)(puVar1 + 4) = 0x11;
      *(undefined2 *)((longlong)puVar1 + 0x23) = 6;
      *(undefined4 *)((longlong)puVar1 + 0x2d) = 1000;
      *(undefined2 *)((longlong)puVar1 + 0x37) = 6;
      *(undefined1 *)((longlong)puVar1 + 0x3b) = 3;
      *(short *)((longlong)puVar1 + 0x39) =
           (short)(undefined4 *)((longlong)puVar1 + 0x56) - (short)puVar1;
      *(undefined4 *)((longlong)puVar1 + 0x3d) = 0x10001;
      *(undefined4 *)((longlong)puVar1 + 0x41) = 0x170002;
      builtin_strncpy((char *)((longlong)puVar1 + 0x45),"\\MAILSLO",8);
      builtin_strncpy((char *)((longlong)puVar1 + 0x4d),"T\\BROWSE",8);
      *(undefined1 *)((longlong)puVar1 + 0x55) = 0;
      *(undefined4 *)((longlong)puVar1 + 0x56) = CONCAT22(uStackX_a,0x409);
      *(undefined2 *)((longlong)puVar1 + 0x5a) = uStackX_c;
      uVar2 = BowserSendDatagram(param_1,param_2,10,puVar1,0x5c,'\x01',(ushort *)0x0,'\0');
      if (-1 < (int)uVar2) {
        uVar4 = uVar2 & 0xffffffff;
      }
    }
  }
  return uVar4;
}



===== BowserFindMaster @ 14001bcc0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int BowserFindMaster(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  char *pcVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  longlong lVar6;
  uint uVar7;
  longlong lVar8;
  undefined2 uVar9;
  uint uVar10;
  char *pcVar11;
  code *pcVar12;
  undefined1 auStackY_d8 [32];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined2 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_d8;
  lVar1 = *(longlong *)(param_1 + 8);
  ExAcquireResourceExclusiveLite(param_1 + 0xd0,1);
  if (*(int *)(lVar1 + 0x100) == 0) {
    if (BowserLogElectionPackets != '\0') {
      BowserWriteErrorLogEntry(0x40001f4e,0,(void *)0x0,0,1,*(longlong *)(lVar1 + 0x38));
    }
    uVar5 = BowserTimeUp();
    if ((uint)uVar5 < *(uint *)(lVar1 + 0x11c)) {
      uVar7 = 15000;
LAB_14001bfc6:
      pcVar12 = BowserStartElection;
      goto LAB_14001be9e;
    }
    uVar7 = (*(uint *)(lVar1 + 0x11c) - (uint)uVar5) + 15000;
    if (0 < (int)uVar7) goto LAB_14001bfc6;
    uVar7 = BowserStartElection(param_1,(ulonglong)uVar7);
    if ((int)uVar7 < 0) {
      BowserCompleteFindMasterRequests(param_1,(ushort *)(lVar1 + 0x128),uVar7);
    }
  }
  else {
    *(int *)(lVar1 + 0x100) = *(int *)(lVar1 + 0x100) + -1;
    BowserStopTimer(param_1 + 0x218);
    lVar1 = *(longlong *)(param_1 + 0x38);
    uStack_40 = 0;
    local_38 = 0;
    local_48 = 2;
    pcVar11 = *(char **)(lVar1 + 0xb0);
    lVar8 = 0x7ffffffe;
    pcVar3 = (char *)((longlong)&local_48 + 2);
    iVar2 = 0;
    for (lVar6 = 0x10; lVar6 != 0; lVar6 = lVar6 + -1) {
      if ((lVar8 == 0) || (*pcVar11 == '\0')) {
        if (lVar6 != 0) goto LAB_14001bdfd;
        break;
      }
      *pcVar3 = *pcVar11;
      pcVar3 = pcVar3 + 1;
      pcVar11 = pcVar11 + 1;
      lVar8 = lVar8 + -1;
    }
    pcVar3 = pcVar3 + -1;
    iVar2 = -0x7ffffffb;
LAB_14001bdfd:
    *pcVar3 = '\0';
    if (-1 < iVar2) {
      uVar10 = (uint)*(ushort *)(*(longlong *)(param_1 + 0x38) + 0xa8);
      uVar7 = uVar10 + 0x59;
      if ((uVar7 < uVar10 + 0x14) ||
         (puVar4 = (undefined8 *)ExAllocatePool2(0x40,uVar7,0x686d424c), puVar4 == (undefined8 *)0x0
         )) {
        iVar2 = -0x3fffff66;
      }
      else {
        *(undefined4 *)puVar4 = 0x424d53ff;
        *(undefined1 *)((longlong)puVar4 + 4) = 0x25;
        *(undefined1 *)(puVar4 + 4) = 0x11;
        uVar9 = (undefined2)(uVar10 + 3);
        *(undefined2 *)((longlong)puVar4 + 0x23) = uVar9;
        *(undefined4 *)((longlong)puVar4 + 0x2d) = 1000;
        *(undefined2 *)((longlong)puVar4 + 0x37) = uVar9;
        *(undefined2 *)((longlong)puVar4 + 0x39) = 0x56;
        *(undefined1 *)((longlong)puVar4 + 0x3b) = 3;
        *(undefined4 *)((longlong)puVar4 + 0x3d) = 0x10001;
        *(undefined2 *)((longlong)puVar4 + 0x41) = 2;
        *(short *)((longlong)puVar4 + 0x43) = (short)(uVar10 + 0x14);
        builtin_strncpy((char *)((longlong)puVar4 + 0x45),"\\MAILSLO",8);
        builtin_strncpy((char *)((longlong)puVar4 + 0x4d),"T\\BROWSE",8);
        *(undefined1 *)((longlong)puVar4 + 0x55) = 0;
        memcpy((void *)((longlong)puVar4 + 0x56),&local_48,(ulonglong)(uVar10 + 3));
        uVar5 = BowserSendDatagram(param_1,lVar1 + 0x58,6,puVar4,uVar7,'\x01',(ushort *)0x0,
                                   (char)local_48 == '\x0f');
        iVar2 = (int)uVar5;
      }
    }
    if (((iVar2 + 0x80000000U & 0x80000000) == 0) && (iVar2 != -0x3fffff42)) goto LAB_14001c004;
    pcVar12 = BowserFindMaster;
    uVar7 = 0x5dc;
LAB_14001be9e:
    BowserStartTimer(param_1 + 0x218,uVar7,pcVar12,param_1);
  }
  iVar2 = 0;
LAB_14001c004:
  ExReleaseResourceLite(param_1 + 0xd0);
  return iVar2;
}



===== BowserQueueNonBufferRequest @ 14001c04c =====

ulonglong BowserQueueNonBufferRequest
                    (longlong param_1,longlong *param_2,undefined8 param_3,char param_4)

{
  ulonglong uVar1;
  
  BowserReferenceDiscardableCode(3);
  uVar1 = BowserQueueNonBufferRequestReferenced(param_1,param_2,param_3,param_4);
  RdrDereferenceDiscardableCode(3);
  return uVar1 & 0xffffffff;
}



===== BowserElectMaster @ 14001c0b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int BowserElectMaster(longlong param_1,undefined8 param_2)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  int iVar3;
  longlong lVar4;
  ulonglong uVar5;
  char *pcVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  longlong lVar9;
  longlong lVar10;
  int iVar11;
  char *pcVar12;
  uint uVar13;
  undefined1 auStackY_e8 [32];
  char local_58 [2];
  undefined8 local_56;
  undefined4 local_4e;
  char local_4a [18];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_e8;
  lVar10 = *(longlong *)(param_1 + 8);
  uVar7 = CONCAT71((int7)((ulonglong)param_2 >> 8),1);
  ExAcquireResourceExclusiveLite(param_1 + 0xd0);
  if (*(int *)(param_1 + 0x60) != 2) {
    BowserLoseElection(param_1,uVar7);
    iVar3 = 0;
    goto LAB_14001c3eb;
  }
  if (*(int *)(lVar10 + 0x100) == 0) {
    *(undefined4 *)(param_1 + 0x60) = 0;
    if (*(int *)(lVar10 + 0xf8) != 3) {
      BowserNewMaster(param_1);
      iVar3 = 0;
      goto LAB_14001c3eb;
    }
    KeSetEvent(BowserServerAnnouncementEvent,2);
  }
  else {
    BowserStopTimer(param_1 + 0x138);
    *(int *)(lVar10 + 0x100) = *(int *)(lVar10 + 0x100) + -1;
    *(int *)(lVar10 + 0x104) = *(int *)(lVar10 + 0x104) + 1;
    uVar5 = _DAT_fffff78000000014 - _BowserStartTime;
    if ((longlong)uVar5 < 0) {
      auVar1._8_8_ = 0;
      auVar1._0_8_ = -uVar5;
      uVar8 = SUB168(ZEXT816(0xd1b71758e219652c) * auVar1,8);
    }
    else {
      auVar2._8_8_ = 0;
      auVar2._0_8_ = uVar5;
      uVar8 = SUB168(ZEXT816(0xd1b71758e219652c) * auVar2,8);
    }
    uVar8 = uVar8 >> 0xd;
    iVar3 = (int)uVar8;
    if ((longlong)uVar5 < 0) {
      uVar8 = -uVar8;
      iVar3 = (int)uVar8;
    }
    iVar11 = -1;
    if ((int)(uVar8 >> 0x20) == 0) {
      iVar11 = iVar3;
    }
    *(int *)(lVar10 + 0x108) = iVar11 + 1000;
    lVar9 = *(longlong *)(param_1 + 0x38);
    lVar10 = lVar9 + 0x58;
    lVar4 = *(longlong *)(param_1 + 8);
    local_58[0] = '\b';
    if (*(char *)(lVar4 + 0x15d) != '\0') {
      iVar3 = -0x3fffffff;
      BowserLoseElection(param_1,uVar8);
      goto LAB_14001c3eb;
    }
    if ((*(uint *)(lVar4 + 0xfc) & 0x70000) == 0) {
      local_58[1] = 0;
      local_56 = 0;
      local_4a[0] = '\0';
      uVar13 = 0;
LAB_14001c3b2:
      local_4e = 0;
      uVar5 = BowserSendSecondClassMailslot
                        (param_1,lVar10,7,local_58,uVar13 + 0xf,'\x01',"\\MAILSLOT\\BROWSE",
                         (ushort *)0x0);
      iVar3 = (int)uVar5;
      lVar9 = lVar10;
    }
    else {
      local_58[1] = 1;
      local_56 = CONCAT44(*(undefined4 *)(lVar4 + 0x10c),*(undefined4 *)(lVar4 + 0x114));
      uVar13 = (uint)*(ushort *)(lVar9 + 0xa8);
      pcVar12 = *(char **)(lVar9 + 0xb0);
      lVar9 = 0x7ffffffe;
      pcVar6 = local_4a;
      iVar3 = 0;
      for (lVar4 = 0x10; local_4e = 0, lVar4 != 0; lVar4 = lVar4 + -1) {
        if ((lVar9 == 0) || (*pcVar12 == '\0')) {
          if (lVar4 != 0) goto LAB_14001c2b8;
          break;
        }
        *pcVar6 = *pcVar12;
        pcVar6 = pcVar6 + 1;
        pcVar12 = pcVar12 + 1;
        lVar9 = lVar9 + -1;
      }
      pcVar6 = pcVar6 + -1;
      iVar3 = -0x7ffffffb;
LAB_14001c2b8:
      *pcVar6 = '\0';
      if (-1 < iVar3) goto LAB_14001c3b2;
    }
    if (iVar3 < 0) {
      BowserLoseElection(param_1,lVar9);
      goto LAB_14001c3eb;
    }
    BowserStartTimer(param_1 + 0x138,1000,BowserElectMaster,param_1);
  }
  iVar3 = 0;
LAB_14001c3eb:
  ExReleaseResourceLite(param_1 + 0xd0);
  return iVar3;
}



===== UpdateStatus @ 14001c440 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong UpdateStatus(undefined8 param_1,undefined8 param_2,ulonglong param_3,uint param_4)

{
  ushort uVar1;
  longlong lVar2;
  bool bVar3;
  longlong lVar4;
  ulonglong uVar5;
  ushort *puVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  bool bVar11;
  undefined1 auStack_98 [32];
  undefined1 local_78;
  uint local_74;
  undefined1 local_70;
  uint local_6c;
  ulonglong local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_98;
  uVar9 = (ulonglong)param_4;
  uVar10 = 0;
  uVar5 = 0;
  local_68 = 0;
  bVar3 = false;
  local_78 = 0;
  local_70 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  uVar8 = param_3;
  lVar4 = IoGetCurrentProcess();
  bVar11 = lVar4 != BowserFspProcess;
  if (bVar11) {
    KeStackAttachProcess(BowserFspProcess,&local_60);
    local_70 = 1;
  }
  if (((param_4 < 0x48) || (*(int *)(param_3 + 4) != 7)) || (*(ushort *)(param_3 + 0x18) == 0)) {
LAB_14001c898:
    uVar10 = 0xc000000d;
  }
  else {
    uVar1 = *(ushort *)(param_3 + 0x1a);
    if (((param_4 < uVar1) || (uVar1 < *(ushort *)(param_3 + 0x18))) ||
       ((*(ulonglong *)(param_3 + 0x20) < param_3 ||
        ((uVar9 - uVar1) + param_3 < *(ulonglong *)(param_3 + 0x20))))) goto LAB_14001c898;
    puVar6 = (ushort *)(param_3 + 0x28);
    if (*puVar6 == 0) {
      *(undefined8 *)(param_3 + 0x30) = 0;
      *(undefined2 *)(param_3 + 0x2a) = 0;
    }
    else {
      uVar1 = *(ushort *)(param_3 + 0x2a);
      if (((param_4 < uVar1) || (uVar1 < *puVar6)) ||
         ((*(ulonglong *)(param_3 + 0x30) < param_3 ||
          (uVar9 = (uVar9 - uVar1) + param_3, uVar9 < *(ulonglong *)(param_3 + 0x30)))))
      goto LAB_14001c898;
    }
    uVar5 = BowserFindTransport((byte *)(param_3 + 0x18),puVar6);
    local_68 = uVar5;
    if (uVar5 != 0) {
      lVar2 = *(longlong *)(uVar5 + 8);
      local_6c = *(uint *)(param_3 + 0x38);
      DAT_14000d2a5 = *(undefined1 *)(param_3 + 0x44);
      DAT_14000d2a6 = *(undefined1 *)(param_3 + 0x40);
      lVar4 = uVar5 + 0xd0;
      uVar7 = CONCAT71((int7)((ulonglong)puVar6 >> 8),1);
      ExAcquireResourceExclusiveLite(lVar4);
      local_78 = 1;
      *(uint *)(lVar2 + 0xfc) = local_6c;
      if ((*(int *)(lVar2 + 0xf8) == 0) && ((local_6c >> 0x10 & 1) != 0)) {
        *(undefined4 *)(lVar2 + 0xf8) = 1;
        ExReleaseResourceLite(lVar4);
        bVar3 = false;
        local_78 = 0;
        uVar9 = *(ulonglong *)(uVar5 + 0x38);
        uVar7 = 0;
        uVar8 = uVar5;
        uVar10 = BowserAllocateName((ushort *)(uVar9 + 0x58),7,uVar5,uVar9);
        local_74 = (uint)uVar10;
        uVar10 = uVar10 & 0xffffffff;
        if ((int)local_74 < 0) goto LAB_14001c8a3;
        uVar7 = CONCAT71((int7)((ulonglong)uVar7 >> 8),1);
        ExAcquireResourceExclusiveLite(lVar4);
      }
      local_78 = 1;
      if (*(int *)(lVar2 + 0xf8) == 3) {
        *(undefined4 *)(lVar2 + 0x44) = *(undefined4 *)(param_3 + 0x3c);
        if ((local_6c & 0x40000) == 0) {
          *(undefined4 *)(lVar2 + 0xf8) = 2;
          BowserDeactivateScavengerTimer();
          local_74 = BowserForEachTransportName(uVar5,BowserStopProcessingAnnouncements,0);
          ExReleaseResourceLite(lVar4);
          local_78 = 0;
          local_74 = BowserDeleteTransportNameByName(uVar5,(short *)0x0,6);
          local_74 = BowserDeleteTransportNameByName(uVar5,(short *)0x0,5);
          uVar10 = (ulonglong)local_74;
          if ((local_6c & 0x20000) == 0) {
            ExAcquireResourceExclusiveLite(uVar5 + 0x2f8,1);
            if (*(undefined8 **)(lVar2 + 0x148) != (undefined8 *)0x0) {
              BowserFreeBrowserServerList(*(undefined8 **)(lVar2 + 0x148),*(uint *)(lVar2 + 0x150));
              *(undefined4 *)(lVar2 + 0x150) = 0;
              *(undefined8 *)(lVar2 + 0x148) = 0;
            }
            ExReleaseResourceLite(uVar5 + 0x2f8);
          }
LAB_14001c75e:
          ExAcquireResourceExclusiveLite(lVar4,1);
        }
      }
      else if ((local_6c & 0x40000) != 0) {
        ExReleaseResourceLite(lVar4);
        local_78 = 0;
        local_74 = BowserBecomeMaster(uVar5,uVar7,uVar8,uVar9);
        uVar10 = (ulonglong)local_74;
        goto LAB_14001c75e;
      }
      local_78 = 1;
      bVar3 = true;
      if ((-1 < (int)uVar10) && (*(int *)(lVar2 + 0xf8) != 3)) {
        if (*(int *)(lVar2 + 0xf8) == 2) {
          if ((local_6c & 0x20000) == 0) {
            *(undefined4 *)(lVar2 + 0xf8) = 1;
            ExAcquireResourceExclusiveLite(uVar5 + 0x2f8);
            if (*(undefined8 **)(lVar2 + 0x148) != (undefined8 *)0x0) {
              BowserFreeBrowserServerList(*(undefined8 **)(lVar2 + 0x148),*(uint *)(lVar2 + 0x150));
              *(undefined4 *)(lVar2 + 0x150) = 0;
              *(undefined8 *)(lVar2 + 0x148) = 0;
            }
            ExReleaseResourceLite(uVar5 + 0x2f8);
          }
        }
        else if ((local_6c & 0x20000) != 0) {
          *(undefined4 *)(lVar2 + 0xf8) = 2;
          uVar10 = 0;
          local_74 = 0;
        }
        if (((*(int *)(lVar2 + 0xf8) != 2) && (*(int *)(lVar2 + 0xf8) == 1)) &&
           ((local_6c >> 0x10 & 1) == 0)) {
          ExReleaseResourceLite(uVar5 + 0xd0);
          bVar3 = false;
          local_78 = 0;
          local_74 = BowserDeleteTransportNameByName(uVar5,(short *)0x0,7);
          uVar10 = (ulonglong)local_74;
          if (-1 < (int)local_74) {
            ExAcquireResourceExclusiveLite(uVar5 + 0xd0,1);
            bVar3 = true;
            local_78 = 1;
            *(undefined4 *)(lVar2 + 0xf8) = 0;
          }
        }
      }
      goto LAB_14001c8a3;
    }
    uVar10 = 0xc0000034;
  }
  local_74 = (uint)uVar10;
LAB_14001c8a3:
  if (bVar3) {
    ExReleaseResourceLite(uVar5 + 0xd0);
  }
  if (uVar5 != 0) {
    BowserDereferenceTransport(uVar5);
  }
  if (bVar11) {
    KeUnstackDetachProcess(&local_60);
  }
  return uVar10;
}



===== BowserBecomeMaster @ 14001c910 =====

int BowserBecomeMaster(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  int iVar2;
  ulonglong uVar3;
  
  lVar1 = *(longlong *)(param_1 + 8);
  ExAcquireResourceExclusiveLite(param_1 + 0xd0,1,param_3,param_4,0xc0000001);
  BowserReferenceDiscardableCode(3);
  uVar3 = BowserAllocateName((ushort *)(*(longlong *)(param_1 + 0x38) + 0x58),6,param_1,
                             *(longlong *)(param_1 + 0x38));
  iVar2 = (int)uVar3;
  if (-1 < iVar2) {
    uVar3 = BowserAllocateName((ushort *)(*(longlong *)(param_1 + 0x38) + 0x58),5,param_1,
                               *(longlong *)(param_1 + 0x38));
    iVar2 = (int)uVar3;
  }
  if (-1 < iVar2) {
    if (*(int *)(lVar1 + 0xf8) != 3) {
      BowserActivateScavengerTimer();
    }
    *(undefined4 *)(lVar1 + 0xf8) = 3;
    BowserForEachTransportName(param_1,StartProcessingAnnouncements,0);
    iVar2 = RtlNumberGenericTableElements(lVar1 + 0x48);
    if ((iVar2 == 0) && (*(uint *)(lVar1 + 0x44) < 0x20)) {
      BowserSendRequestAnnouncement(*(longlong *)(param_1 + 0x38) + 0x58,2,param_1);
    }
    iVar2 = RtlNumberGenericTableElements(lVar1 + 0x90);
    if ((iVar2 == 0) && (*(int *)(lVar1 + 0x44) == 0)) {
      BowserSendRequestAnnouncement(*(longlong *)(param_1 + 0x38) + 0x58,5,param_1);
    }
    uVar3 = BowserTimeUp();
    *(int *)(lVar1 + 0x118) = (int)uVar3;
    BowserForEachTransportName(param_1,BowserPrimeDomainTableWithOtherDomains,0);
    BowserCompleteFindMasterRequests
              (param_1,(ushort *)(*(longlong *)(param_1 + 0x38) + 0x88),0xc00000d0);
    iVar2 = 0;
  }
  if (iVar2 < 0) {
    *(undefined4 *)(lVar1 + 0xf8) = 1;
    *(undefined4 *)(lVar1 + 0x100) = 4;
    uVar3 = BowserTimeUp();
    *(int *)(lVar1 + 0x10c) = (int)uVar3;
    *(undefined4 *)(param_1 + 0x60) = 0;
    BowserForEachTransportName(param_1,BowserStopProcessingAnnouncements,0);
    BowserStopTimer(param_1 + 0x138);
    BowserDeleteTransportNameByName(param_1,(short *)0x0,6);
    BowserDeleteTransportNameByName(param_1,(short *)0x0,5);
    RdrDereferenceDiscardableCode(3);
  }
  ExReleaseResourceLite(param_1 + 0xd0);
  return iVar2;
}



===== BowserSendRequestAnnouncement @ 14001cb00 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong BowserSendRequestAnnouncement(longlong param_1,int param_2,longlong param_3)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  char *pcVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  char *pcVar7;
  longlong lVar8;
  undefined2 uVar9;
  uint uVar10;
  undefined1 auStackY_98 [32];
  undefined2 local_58;
  char local_56 [22];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_98;
  lVar2 = *(longlong *)(param_3 + 0x38);
  pcVar4 = local_56;
  local_58 = 2;
  lVar3 = *(longlong *)(lVar2 + 0xb0);
  lVar8 = 0x10;
  local_56[0] = '\0';
  local_56[1] = '\0';
  local_56[2] = '\0';
  local_56[3] = '\0';
  local_56[4] = '\0';
  local_56[5] = '\0';
  local_56[6] = '\0';
  local_56[7] = '\0';
  local_56[8] = '\0';
  local_56[9] = '\0';
  local_56[10] = '\0';
  local_56[0xb] = '\0';
  local_56[0xc] = '\0';
  local_56[0xd] = '\0';
  local_56[0xe] = '\0';
  local_56[0xf] = '\0';
  do {
    if ((lVar8 == -0x7fffffee) || (pcVar4[lVar3 - (longlong)local_56] == '\0')) break;
    *pcVar4 = pcVar4[lVar3 - (longlong)local_56];
    pcVar4 = pcVar4 + 1;
    lVar8 = lVar8 + -1;
  } while (lVar8 != 0);
  pcVar7 = pcVar4 + -1;
  if (lVar8 != 0) {
    pcVar7 = pcVar4;
  }
  *pcVar7 = '\0';
  uVar5 = 0x80000005;
  if (lVar8 != 0) {
    uVar10 = (uint)*(ushort *)(lVar2 + 0xa8);
    uVar1 = uVar10 + 0x59;
    if ((uVar1 < uVar10 + 0x14) ||
       (puVar6 = (undefined8 *)ExAllocatePool2(0x40,uVar1,0x686d424c), puVar6 == (undefined8 *)0x0))
    {
      uVar5 = 0xc000009a;
    }
    else {
      *(undefined4 *)puVar6 = 0x424d53ff;
      *(undefined1 *)((longlong)puVar6 + 4) = 0x25;
      *(undefined1 *)(puVar6 + 4) = 0x11;
      uVar9 = (undefined2)(uVar10 + 3);
      *(undefined2 *)((longlong)puVar6 + 0x23) = uVar9;
      *(undefined4 *)((longlong)puVar6 + 0x2d) = 1000;
      *(undefined2 *)((longlong)puVar6 + 0x37) = uVar9;
      *(undefined1 *)((longlong)puVar6 + 0x3b) = 3;
      *(short *)((longlong)puVar6 + 0x39) = (short)(void *)((longlong)puVar6 + 0x56) - (short)puVar6
      ;
      *(undefined4 *)((longlong)puVar6 + 0x3d) = 0x10001;
      *(undefined2 *)((longlong)puVar6 + 0x41) = 2;
      *(short *)((longlong)puVar6 + 0x43) = (short)(uVar10 + 0x14);
      builtin_strncpy((char *)((longlong)puVar6 + 0x45),"\\MAILSLO",8);
      builtin_strncpy((char *)((longlong)puVar6 + 0x4d),"T\\BROWSE",8);
      *(undefined1 *)((longlong)puVar6 + 0x55) = 0;
      memcpy((void *)((longlong)puVar6 + 0x56),&local_58,(ulonglong)(uVar10 + 3));
      uVar5 = BowserSendDatagram(param_3,param_1,param_2,puVar6,uVar1,'\x01',(ushort *)0x0,
                                 (char)local_58 == '\x0f');
    }
  }
  return uVar5;
}



===== BowserProcessMasterAnnouncement @ 14001ccd0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void BowserProcessMasterAnnouncement(longlong param_1)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  bool bVar4;
  char cVar5;
  int iVar6;
  ulonglong uVar7;
  longlong lVar8;
  uint uVar9;
  undefined1 auStackY_b8 [32];
  ushort local_70 [4];
  undefined1 *puStack_68;
  longlong local_60;
  undefined8 local_58;
  void *pvStack_50;
  longlong local_48;
  undefined1 local_40 [32];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_b8;
  lVar2 = *(longlong *)(param_1 + 0x20);
  local_70[0] = 0;
  local_70[1] = 0;
  local_70[2] = 0;
  local_70[3] = 0;
  puStack_68 = (undefined1 *)0x0;
  local_58 = 0;
  pvStack_50 = (void *)0x0;
  lVar3 = *(longlong *)(lVar2 + 8);
  local_60 = lVar2;
  local_48 = param_1;
  ExAcquireResourceExclusiveLite(lVar2 + 0xd0,1);
  puStack_68 = local_40;
  local_70[1] = 0x20;
  if (*(int *)(lVar2 + 0x60) == 2) goto LAB_14001d01b;
  RtlInitAnsiString(&local_58,param_1 + 0x30);
  iVar6 = RtlOemStringToUnicodeString(local_70,&local_58,0);
  if (iVar6 < 0) {
    BowserLogIllegalName(iVar6,pvStack_50,(ushort)local_58);
    goto LAB_14001d01b;
  }
  *(undefined4 *)(lVar3 + 0x100) = 0;
  *(undefined4 *)(lVar2 + 0x60) = 0;
  BowserStopTimer(lVar2 + 0x138);
  BowserStopTimer(lVar2 + 0x218);
  uVar9 = *(uint *)(param_1 + 0x40);
  if (uVar9 == *(ushort *)(lVar3 + 0x138)) {
    uVar7 = RtlCompareMemory(*(undefined8 *)(lVar3 + 0x140),param_1 + 0x44,uVar9);
    uVar9 = *(uint *)(param_1 + 0x40);
    if (uVar7 != uVar9) goto LAB_14001ceae;
  }
  else {
LAB_14001ceae:
    if (uVar9 <= *(ushort *)(lVar3 + 0x13a)) {
      *(short *)(lVar3 + 0x138) = (short)uVar9;
      memcpy(*(void **)(lVar3 + 0x140),(void *)(param_1 + 0x44),(ulonglong)*(uint *)(param_1 + 0x40)
            );
    }
  }
  cVar5 = RtlEqualUnicodeString(*(longlong *)(lVar2 + 0x38) + 0x88,local_70);
  if (cVar5 != '\0') {
    if (*(int *)(lVar3 + 0xf8) == 3) {
      BowserCompleteFindMasterRequests(lVar2,local_70,0xc0000016);
    }
    else if (*(char *)(lVar3 + 0x15d) == '\0') {
      BowserWriteErrorLogEntry(0x80001f45,0,(void *)0x0,0,1,(longlong)puStack_68);
      BowserResetStateForTransport(lVar2,1);
    }
    goto LAB_14001d01b;
  }
  bVar4 = false;
  if (*(int *)(lVar3 + 0xf8) == 3) {
    _DAT_14000d2f4 = _DAT_14000d2f4 + 1;
    lVar8 = BowserGetCurrentTime();
    if (*(uint *)(lVar3 + 0x120) < (uint)lVar8) {
      lVar8 = BowserGetCurrentTime();
      *(int *)(lVar3 + 0x120) = (int)lVar8 + _DAT_14000d2a0;
      BowserWriteErrorLogEntry(0xc0001f43,0,(void *)0x0,0,2,(longlong)puStack_68);
    }
    if ((*(byte *)(lVar3 + 0x158) & 1) == 0) {
      if (*(char *)(lVar3 + 0x15c) == '\0') {
        if ((DAT_14000d2a6 == '\0') || ((*(uint *)(param_1 + 0x28) & 0x18) != 0))
        goto LAB_14001cf6c;
      }
      else {
        bVar4 = true;
      }
    }
    else {
LAB_14001cf6c:
      BowserResetStateForTransport(lVar2,1);
    }
  }
  if ((*(uint *)(param_1 + 0x28) >> 0xd & 1) != 0) {
    bVar4 = true;
  }
  if ((((*(uint *)(param_1 + 0x2c) & 0xffff0000) == 0xaa550000) &&
      ((ushort)*(uint *)(param_1 + 0x2c) < 0x10f)) && ((*(byte *)(lVar3 + 0x158) & 1) == 0)) {
    bVar4 = true;
  }
  if ((((DAT_14000d2a6 != '\0') && ((*(byte *)(lVar3 + 0x158) & 1) == 0)) &&
      ((*(char *)(lVar3 + 0x15c) != '\0' || ((*(uint *)(param_1 + 0x28) & 0x18) == 0)))) || (bVar4))
  {
    BowserSendElection(*(longlong *)(lVar2 + 0x38) + 0x58,1,lVar2,'\0');
  }
  BowserCompleteFindMasterRequests(lVar2,local_70,0);
LAB_14001d01b:
  ExReleaseResourceLite(lVar2 + 0xd0);
  ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
  LOCK();
  piVar1 = (int *)(lVar2 + 4);
  iVar6 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar6 == 1) {
    BowserpFreeTransport(lVar2);
  }
  ExReleaseResourceLite(&BowserTransportDatabaseResource);
  LOCK();
  BowserPostedDatagramCount = BowserPostedDatagramCount + -1;
  UNLOCK();
  ExFreePoolWithTag(param_1,0);
  return;
}



===== BowserCompleteFindMasterRequests @ 14001d0c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void BowserCompleteFindMasterRequests(longlong param_1,ushort *param_2,uint param_3)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  longlong lVar4;
  undefined1 auStack_98 [32];
  undefined8 local_78;
  undefined1 *puStack_70;
  undefined1 local_68 [32];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_98;
  lVar4 = *(longlong *)(param_1 + 8);
  puStack_70 = local_68;
  local_78 = 0x200000;
  iVar3 = RtlUpcaseUnicodeString(&local_78,param_2,0);
  if (iVar3 < 0) {
    BowserLogIllegalName(iVar3,*(void **)(param_2 + 4),*param_2);
    return;
  }
  ExAcquireResourceExclusiveLite(param_1 + 0xd0,1);
  cVar2 = RtlEqualUnicodeString(&local_78,lVar4 + 0x128,0);
  if (cVar2 == '\0') {
    RtlCopyUnicodeString(lVar4 + 0x128,&local_78);
  }
  ExReleaseResourceLite(param_1 + 0xd0);
  do {
    lVar4 = BowserDequeueQueuedIrp((longlong *)(param_1 + 0x398),'\x01');
    if (cVar2 != '\0') {
LAB_14001d1de:
      if (lVar4 == 0) {
        return;
      }
    }
    else if (lVar4 == 0) {
      lVar4 = BowserDequeueQueuedIrp((longlong *)(param_1 + 0x3c8),'\0');
      goto LAB_14001d1de;
    }
    lVar1 = *(longlong *)(lVar4 + 0x18);
    if (-1 < (int)param_3) {
      if ((ushort)(*(short *)(*(longlong *)(lVar4 + 0xb8) + 8) - 0x36U) < *param_2) {
        param_3 = 0xc0000023;
      }
      else {
        *(undefined4 *)(lVar1 + 0x3c) = 0x5c005c;
        memcpy((void *)(lVar1 + 0x40),*(void **)(param_2 + 4),(ulonglong)*param_2);
        *(undefined2 *)(lVar1 + 0x40 + (ulonglong)(*param_2 >> 1) * 2) = 0;
      }
      *(uint *)(lVar1 + 0x38) = *param_2 + 4;
      *(ulonglong *)(lVar4 + 0x38) = (ulonglong)*param_2 + 0x42;
    }
    *(uint *)(lVar4 + 0x30) = param_3;
    if ((param_3 & 0xc0000000) == 0xc0000000) {
      *(undefined8 *)(lVar4 + 0x38) = 0;
    }
    IofCompleteRequest(lVar4,0);
  } while( true );
}



===== BowserForEachTransportName @ 14001d2c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int BowserForEachTransportName(longlong param_1,undefined *param_2,undefined8 param_3)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  int iVar4;
  undefined8 *puVar5;
  
  iVar4 = 0;
  ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
  puVar5 = *(undefined8 **)(*(longlong *)(param_1 + 8) + 0x20);
  while( true ) {
    if ((puVar5 == (undefined8 *)0x0) ||
       (puVar5 == (undefined8 *)(*(longlong *)(param_1 + 8) + 0x20))) goto LAB_14001d3e1;
    lVar3 = puVar5[-2];
    BowserReferenceTransportName(lVar3);
    ExReleaseResourceLite(&BowserTransportDatabaseResource);
    iVar4 = (*(code *)param_2)(lVar3,param_3);
    if (iVar4 < 0) break;
    ExAcquireResourceExclusiveLite();
    puVar5 = (undefined8 *)*puVar5;
    ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
    LOCK();
    piVar1 = (int *)(lVar3 + 8);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      BowserFreeTransportName(lVar3);
    }
    ExReleaseResourceLite(&BowserTransportDatabaseResource);
  }
  ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
  BowserDereferenceTransportName(lVar3);
LAB_14001d3e1:
  ExReleaseResourceLite(&BowserTransportDatabaseResource);
  return iVar4;
}



===== EnumerateNamesTransportWorker @ 14001d420 =====

void EnumerateNamesTransportWorker(longlong param_1,undefined8 param_2)

{
  BowserForEachTransportName(param_1,EnumerateNamesTransportNameWorker,param_2);
  return;
}



===== BowserStartElection @ 14001d440 =====

int BowserStartElection(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  int iVar2;
  undefined1 uVar3;
  undefined7 uVar4;
  
  uVar4 = (undefined7)((ulonglong)param_2 >> 8);
  lVar1 = *(longlong *)(param_1 + 8);
  uVar3 = 1;
  ExAcquireResourceExclusiveLite(param_1 + 0xd0);
  if (((*(char *)(lVar1 + 0x15d) == '\0') && (*(int *)(param_1 + 0x60) != 3)) &&
     (*(int *)(lVar1 + 0xf8) != 0)) {
    *(undefined4 *)(lVar1 + 0x100) = 4;
    *(undefined4 *)(param_1 + 0x60) = 2;
    BowserSetElectionCriteria(lVar1);
    iVar2 = BowserElectMaster(param_1,CONCAT71(uVar4,uVar3));
  }
  else {
    iVar2 = -0x3fffffff;
  }
  ExReleaseResourceLite(param_1 + 0xd0);
  return iVar2;
}



===== BowserNewMaster @ 14001d4e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void BowserNewMaster(longlong param_1)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  longlong lVar4;
  uint uVar5;
  undefined1 auStack_88 [32];
  ushort local_68 [4];
  undefined1 *puStack_60;
  undefined8 local_58;
  void *pvStack_50;
  longlong local_48;
  undefined1 local_40 [32];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_88;
  local_58 = 0;
  pvStack_50 = (void *)0x0;
  lVar1 = *(longlong *)(param_1 + 8);
  puStack_60 = local_40;
  local_68[0] = 0;
  local_68[1] = 0x20;
  local_68[2] = 0;
  local_68[3] = 0;
  local_48 = param_1;
  RtlInitAnsiString(&local_58);
  iVar3 = RtlOemStringToUnicodeString(local_68,&local_58,0);
  uVar5 = 0;
  if (iVar3 < 0) {
    BowserLogIllegalName(iVar3,pvStack_50,(ushort)local_58);
  }
  else {
    ExAcquireResourceExclusiveLite(param_1 + 0xd0,1);
    *(undefined4 *)(lVar1 + 0x100) = 0;
    *(undefined4 *)(param_1 + 0x60) = 0;
    BowserStopTimer(param_1 + 0x138);
    cVar2 = RtlEqualUnicodeString(local_68,*(longlong *)(param_1 + 0x38) + 0x88,1);
    if (cVar2 != '\0') {
      lVar4 = BowserDequeueQueuedIrp((longlong *)(param_1 + 0x388),'\0');
      if (lVar4 == 0) {
        *(undefined4 *)(param_1 + 0x60) = 3;
        if (*(int *)(lVar1 + 0xf8) == 6) {
          BowserDeleteTransportNameByName(param_1,(short *)0x0,6);
          BowserDeleteTransportNameByName(param_1,(short *)0x0,5);
        }
      }
      else {
        *(undefined8 *)(lVar4 + 0x38) = 0;
        *(undefined4 *)(lVar4 + 0x30) = 0;
        IofCompleteRequest(lVar4,0);
      }
      uVar5 = 0xc0000016;
    }
    BowserCompleteFindMasterRequests(param_1,local_68,uVar5);
    ExReleaseResourceLite(param_1 + 0xd0);
  }
  return;
}



===== BowserConvertType3IoControlToType2IoControl @ 14001d670 =====

undefined8 BowserConvertType3IoControlToType2IoControl(longlong param_1,longlong param_2)

{
  uint uVar1;
  void *_Src;
  undefined8 uVar2;
  longlong lVar3;
  
  if ((*(int *)(param_2 + 8) != 0) &&
     (uVar2 = BowserLockUsersBuffer(param_1,param_2,*(int *)(param_2 + 8)), (int)uVar2 < 0)) {
    return uVar2;
  }
  uVar1 = *(uint *)(param_2 + 0x10);
  if (uVar1 == 0) {
    *(undefined8 *)(param_1 + 0x18) = 0;
  }
  else {
    _Src = *(void **)(param_2 + 0x20);
    lVar3 = ExAllocatePool2(0x103,uVar1,0x20204744);
    *(longlong *)(param_1 + 0x18) = lVar3;
    if (lVar3 == 0) {
      return 0xc000009a;
    }
    if (*(char *)(param_1 + 0x40) != '\0') {
      ProbeForRead(_Src,(ulonglong)uVar1,1);
    }
    memcpy(*(void **)(param_1 + 0x18),_Src,(ulonglong)uVar1);
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x30;
  }
  return 0;
}



===== BowserLockUsersBuffer @ 14001d760 =====

undefined8 BowserLockUsersBuffer(longlong param_1,undefined8 param_2,undefined4 param_3)

{
  longlong lVar1;
  
  if (*(longlong *)(param_1 + 8) == 0) {
    lVar1 = IoAllocateMdl(*(undefined8 *)(param_1 + 0x70),param_3,0,1,0);
    *(longlong *)(param_1 + 8) = lVar1;
    if (lVar1 == 0) {
      return 0xc000009a;
    }
    MmProbeAndLockPages(lVar1,*(undefined1 *)(param_1 + 0x40),1);
  }
  return 0;
}



===== BowserFsdDeviceIoControlFile @ 14001d810 =====

uint BowserFsdDeviceIoControlFile(uint *param_1,char *param_2)

{
  byte bVar1;
  uint uVar2;
  longlong lVar3;
  bool bVar4;
  
  KeEnterCriticalRegion();
  lVar3 = IoGetCurrentProcess();
  bVar4 = lVar3 != BowserFspProcess;
  bVar1 = IoIsOperationSynchronous(param_2);
  uVar2 = BowserCommonDeviceIoControlFile(bVar1,bVar4,param_1,param_2);
  KeLeaveCriticalRegion();
  return uVar2;
}



===== BowserCommonDeviceIoControlFile @ 14001d890 =====

uint BowserCommonDeviceIoControlFile(byte param_1,char param_2,uint *param_3,char *param_4)

{
  int iVar1;
  int *piVar2;
  ulonglong uVar3;
  char cVar4;
  undefined8 uVar5;
  int *piVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  longlong lVar9;
  longlong lVar10;
  char *pcVar11;
  IMAGE_DOS_HEADER *pIVar12;
  IMAGE_DOS_HEADER *pIVar13;
  uint *_Size;
  uint uVar14;
  uint uVar15;
  bool bVar16;
  uint local_88;
  int local_84;
  uint local_80;
  char local_7c;
  int *local_78;
  uint local_70;
  char local_6c;
  int local_68;
  char *local_60;
  uint local_58;
  uint local_54;
  int *local_50;
  uint local_48;
  ulonglong local_40;
  
  local_88 = 0;
  pIVar13 = *(IMAGE_DOS_HEADER **)(param_4 + 0xb8);
  local_60 = (char *)0x0;
  iVar1 = *(int *)&pIVar13->e_lfarlc;
  local_58 = (uint)(byte)pIVar13->e_magic[1];
  uVar7 = 0;
  local_40 = 0;
  local_7c = '\0';
  local_50 = (int *)0x0;
  _Size = param_3;
  local_84 = iVar1;
  local_68 = iVar1;
  cVar4 = IoIs32bitProcess(param_4);
  local_6c = cVar4;
  if ((cVar4 != '\0') && ((iVar1 - 0x130023U & 0xffffffef) != 0)) {
    local_88 = 0xc0000002;
    goto LAB_14001e587;
  }
  local_78 = *(int **)(param_4 + 0x18);
  uVar14._0_2_ = pIVar13->e_cparhdr;
  uVar14._2_2_ = pIVar13->e_minalloc;
  uVar15 = *(uint *)&pIVar13->e_sp;
  local_80 = uVar15;
  local_70 = uVar14;
  local_48 = uVar14;
  if (uVar15 != 0) {
    if (cVar4 == '\0') {
      bVar16 = uVar15 < 0x38;
    }
    else {
      bVar16 = uVar15 < 0x28;
    }
    if (!bVar16) goto LAB_14001d976;
LAB_14001d95b:
    local_88 = 0xc000000d;
    goto LAB_14001e587;
  }
LAB_14001d976:
  if ((local_78 == (int *)0x0) && (uVar15 != 0)) {
    if (((byte)local_84 & 3) == 3) {
      uVar7 = *(ulonglong *)(pIVar13->e_res_4_ + 2);
      local_40 = uVar7;
      uVar5 = BowserConvertType3IoControlToType2IoControl((longlong)param_4,(longlong)pIVar13);
      local_88 = (uint)uVar5;
      if ((int)local_88 < 0) goto LAB_14001e587;
      piVar2 = *(int **)(param_4 + 0x18);
      if (piVar2 != (int *)0x0) {
        piVar6 = piVar2;
        if (cVar4 != '\0') {
          local_54 = uVar15 + 0x10;
          if (local_54 < uVar15) {
            local_54 = 0xffffffff;
            local_88 = 0xc0000095;
          }
          else {
            local_88 = 0;
          }
          if (-1 < (int)local_88) {
            piVar6 = (int *)ExAllocatePool2(0x102,local_54,0x7469424c);
            local_50 = piVar6;
            if (piVar6 != (int *)0x0) {
              *piVar6 = *piVar2;
              piVar6[1] = piVar2[1];
              piVar6[2] = piVar2[2];
              *(undefined8 *)(piVar6 + 3) = *(undefined8 *)(piVar2 + 3);
              *(short *)(piVar6 + 6) = (short)piVar2[5];
              *(undefined2 *)((longlong)piVar6 + 0x1a) = *(undefined2 *)((longlong)piVar2 + 0x16);
              *(longlong *)(piVar6 + 8) = (longlong)piVar2[6];
              *(short *)(piVar6 + 10) = (short)piVar2[7];
              *(undefined2 *)((longlong)piVar6 + 0x2a) = *(undefined2 *)((longlong)piVar2 + 0x1e);
              *(longlong *)(piVar6 + 0xc) = (longlong)piVar2[8];
              _Size = (uint *)(ulonglong)(uVar15 - 0x28);
              memcpy(piVar6 + 0xe,piVar2 + 10,(size_t)_Size);
              local_80 = local_54;
              uVar14 = local_48;
              uVar15 = local_54;
              goto LAB_14001daa8;
            }
            local_88 = 0xc000009a;
          }
          goto LAB_14001e587;
        }
LAB_14001daa8:
        if ((local_84 - 0x130007U & 0xfffffffb) == 0) {
          RtlInitUnicodeString(piVar6 + 10);
          RtlInitUnicodeString(piVar6 + 6);
        }
        if (piVar6[1] - 6U < 2) {
          if (*(ushort *)(piVar6 + 6) == 0) {
            *(undefined2 *)((longlong)piVar6 + 0x1a) = 0;
            piVar6[8] = 0;
            piVar6[9] = 0;
            uVar8 = (ulonglong)(-(uint)(cVar4 != '\0') & 0x10);
          }
          else {
            uVar3 = *(ulonglong *)(piVar6 + 8);
            if (((uVar3 < uVar7) || (*(ushort *)((longlong)piVar6 + 0x1a) < *(ushort *)(piVar6 + 6))
                ) || (((ulonglong)uVar15 - (ulonglong)*(ushort *)((longlong)piVar6 + 0x1a)) + uVar7
                      < uVar3)) goto LAB_14001d95b;
            uVar8 = (ulonglong)(-(uint)(cVar4 != '\0') & 0x10);
            _Size = (uint *)(ulonglong)(uint)((int)uVar3 - (int)uVar7);
            *(ulonglong *)(piVar6 + 8) = (longlong)_Size + uVar8 + (longlong)piVar6;
          }
          if ((*(ushort *)(piVar6 + 10) == 0) || (piVar6[1] == 6)) {
            *(undefined2 *)((longlong)piVar6 + 0x2a) = 0;
            piVar6[0xc] = 0;
            piVar6[0xd] = 0;
          }
          else {
            uVar3 = *(ulonglong *)(piVar6 + 0xc);
            if (((uVar3 < uVar7) ||
                (*(ushort *)((longlong)piVar6 + 0x2a) < *(ushort *)(piVar6 + 10))) ||
               (((ulonglong)uVar15 - (ulonglong)*(ushort *)((longlong)piVar6 + 0x2a)) + uVar7 <
                uVar3)) goto LAB_14001d95b;
            _Size = (uint *)(ulonglong)(uint)((int)uVar3 - (int)uVar7);
            *(ulonglong *)(piVar6 + 0xc) = (longlong)_Size + uVar8 + (longlong)piVar6;
          }
          local_78 = piVar6;
          goto LAB_14001dbb9;
        }
      }
    }
    goto LAB_14001d95b;
  }
LAB_14001dbb9:
  piVar2 = local_78;
  if (uVar14 != 0) {
    _Size = (uint *)(ulonglong)uVar14;
    BowserMapUsersBuffer((longlong)param_4,(ulonglong *)&local_60,uVar14);
    if (local_60 != (char *)0x0) goto LAB_14001dbeb;
    local_88 = 0xc000009a;
    goto LAB_14001e587;
  }
LAB_14001dbeb:
  if (piVar2 != (int *)0x0) {
    if (uVar15 < 0x38) {
                    /* WARNING: Subroutine does not return */
      ExRaiseStatus(0xc000000d);
    }
    if (piVar2[1] == 6) {
      RtlInitUnicodeString(piVar2 + 10,0);
      piVar2[1] = 7;
    }
  }
  if (local_58 != 0) {
    local_88 = 0xc0000002;
    goto LAB_14001e43e;
  }
  ExAcquireResourceSharedLite(&BowserDataResource,1);
  if ((local_84 != 0x130007) && (BowserData != '\x01')) {
    ExReleaseResourceLite(&BowserDataResource);
    local_88 = 0xc00000fb;
    goto LAB_14001e44c;
  }
  LOCK();
  BowserOperationCount = BowserOperationCount + 1;
  UNLOCK();
  ExReleaseResourceLite(&BowserDataResource);
  piVar6 = local_78;
  if (0x90 < local_84 - 0x130007U) {
switchD_14001dcc9_caseD_130008:
    local_88 = 0xc0000002;
    goto LAB_14001e41f;
  }
  pIVar12 = &IMAGE_DOS_HEADER_140000000;
  pcVar11 = IMAGE_DOS_HEADER_140000000.e_magic +
            (&switchD_14001dcc9::switchdataD_140009a04)
            [(&switchD_14001dcc9::switchdataD_140009a78)[local_84 - 0x130007U]];
  switch(local_84) {
  case 0x130007:
    if (((param_4[0x40] == '\0') ||
        (cVar4 = IoIsSystemThread(*(undefined8 *)(param_4 + 0x98)), cVar4 != '\0')) ||
       (cVar4 = BowserSecurityCheck((longlong)param_4,(longlong)pIVar13,&local_88), cVar4 != '\0'))
    {
      uVar5 = StartBowser();
      local_88 = (uint)uVar5;
      break;
    }
    goto LAB_14001dd00;
  default:
    goto switchD_14001dcc9_caseD_130008;
  case 0x13000b:
    if ((param_4[0x40] != '\0') &&
       (cVar4 = IoIsSystemThread(*(undefined8 *)(param_4 + 0x98)), cVar4 == '\0')) {
      _Size = &local_88;
      cVar4 = BowserSecurityCheck((longlong)param_4,(longlong)pIVar13,_Size);
      if (cVar4 == '\0') goto LAB_14001dd00;
    }
    uVar5 = StopBowser((ulonglong)param_1,param_2,_Size,(longlong)local_78,local_80);
    local_88 = (uint)uVar5;
    break;
  case 0x13000c:
    if (local_78 != (int *)0x0) {
      RtlInitUnicodeString(local_78 + 10);
      pcVar11 = (char *)(piVar6 + 6);
      pIVar12 = (IMAGE_DOS_HEADER *)0x0;
      RtlInitUnicodeString();
    }
    goto LAB_14001dee4;
  case 0x13000f:
LAB_14001dee4:
    if (param_4[0x40] == '\0') {
LAB_14001df19:
      uVar7 = AddBowserName(pcVar11,pIVar12,(ulonglong)piVar6,local_80);
      local_88 = (uint)uVar7;
      break;
    }
    pcVar11 = *(char **)(param_4 + 0x98);
    cVar4 = IoIsSystemThread();
    if ((cVar4 != '\0') ||
       (pcVar11 = param_4,
       cVar4 = BowserSecurityCheck((longlong)param_4,(longlong)pIVar13,&local_88), pIVar12 = pIVar13
       , cVar4 != '\0')) goto LAB_14001df19;
LAB_14001dd00:
    if (-1 < (int)local_88) {
      local_88 = 0xc0000022;
    }
    goto LAB_14001e587;
  case 0x130010:
    if (local_78 != (int *)0x0) {
      RtlInitUnicodeString(local_78 + 10);
      pcVar11 = (char *)(piVar6 + 6);
      pIVar12 = (IMAGE_DOS_HEADER *)0x0;
      RtlInitUnicodeString();
    }
    goto LAB_14001df64;
  case 0x130013:
LAB_14001df64:
    if (param_4[0x40] == '\0') {
LAB_14001df99:
      local_88 = DeleteName(pcVar11,pIVar12,(ulonglong)piVar6,local_80);
      break;
    }
    pcVar11 = *(char **)(param_4 + 0x98);
    cVar4 = IoIsSystemThread();
    if ((cVar4 != '\0') ||
       (pcVar11 = param_4,
       cVar4 = BowserSecurityCheck((longlong)param_4,(longlong)pIVar13,&local_88), pIVar12 = pIVar13
       , cVar4 != '\0')) goto LAB_14001df99;
    goto LAB_14001dd00;
  case 0x130017:
    local_88 = EnumNames(local_60,&IMAGE_DOS_HEADER_140000000,local_78,&local_80,local_60,local_70,
                         (longlong)local_60 - *(longlong *)(param_4 + 0x70));
    goto LAB_14001de63;
  case 0x13001b:
    uVar5 = EnumServers(local_60,&IMAGE_DOS_HEADER_140000000,local_78,&local_80,local_60,local_70,
                        (longlong)local_60 - *(longlong *)(param_4 + 0x70));
    local_88 = (uint)uVar5;
    goto LAB_14001de63;
  case 0x13001f:
    if (param_4[0x40] != '\0') {
      pcVar11 = *(char **)(param_4 + 0x98);
      cVar4 = IoIsSystemThread();
      if ((cVar4 == '\0') &&
         (pcVar11 = param_4,
         cVar4 = BowserSecurityCheck((longlong)param_4,(longlong)pIVar13,&local_88),
         pIVar12 = pIVar13, cVar4 == '\0')) goto LAB_14001dd00;
    }
    local_88 = BowserBindToTransport(pcVar11,pIVar12,(short *)local_78,local_80);
    break;
  case 0x130023:
    local_88 = BowserEnumTransports
                         (local_60,&IMAGE_DOS_HEADER_140000000,local_78,&local_80,
                          (undefined4 *)local_60,local_70,
                          (longlong)local_60 - *(longlong *)(param_4 + 0x70));
    goto LAB_14001de63;
  case 0x130027:
    if (param_4[0x40] != '\0') {
      pcVar11 = *(char **)(param_4 + 0x98);
      cVar4 = IoIsSystemThread();
      if ((cVar4 == '\0') &&
         (pcVar11 = param_4,
         cVar4 = BowserSecurityCheck((longlong)param_4,(longlong)pIVar13,&local_88),
         pIVar12 = pIVar13, cVar4 == '\0')) goto LAB_14001dd00;
    }
    uVar5 = UnbindFromTransport(pcVar11,pIVar12,(ulonglong)local_78,local_80);
    local_88 = (uint)uVar5;
    break;
  case 0x13002b:
    if (((param_4[0x40] != '\0') &&
        (cVar4 = IoIsSystemThread(*(undefined8 *)(param_4 + 0x98)), cVar4 == '\0')) &&
       (cVar4 = BowserSecurityCheck((longlong)param_4,(longlong)pIVar13,&local_88), cVar4 == '\0'))
    goto LAB_14001dd00;
    local_88 = BowserRenameDomain((ulonglong)local_78,local_80);
    break;
  case 0x130033:
    local_88 = GetBrowserServerList
                         ((ulonglong)param_4,param_1,(char)_Size,(ulonglong)local_78,&local_80,
                          (ulonglong)local_60,local_70,
                          (longlong)local_60 - *(longlong *)(param_4 + 0x70));
LAB_14001de63:
    if ((local_88 == 0) || (local_88 == 0x105)) {
      local_7c = '\x01';
    }
    break;
  case 0x130034:
    uVar7 = GetMasterName((longlong)param_4,&IMAGE_DOS_HEADER_140000000,_Size,(longlong)local_78,
                          local_80);
    local_88 = (uint)uVar7;
    break;
  case 0x130038:
    if (((param_4[0x40] != '\0') &&
        (cVar4 = IoIsSystemThread(*(undefined8 *)(param_4 + 0x98)), cVar4 == '\0')) &&
       (cVar4 = BowserSecurityCheck((longlong)param_4,(longlong)pIVar13,&local_88), cVar4 == '\0'))
    goto LAB_14001dd00;
    uVar7 = HandleBecomeBackup((longlong)param_4,(longlong)local_78,(ulonglong)local_80);
    local_88 = (uint)uVar7;
    break;
  case 0x13003c:
    if (((param_4[0x40] != '\0') &&
        (cVar4 = IoIsSystemThread(*(undefined8 *)(param_4 + 0x98)), cVar4 == '\0')) &&
       (cVar4 = BowserSecurityCheck((longlong)param_4,(longlong)pIVar13,&local_88), cVar4 == '\0'))
    goto LAB_14001dd00;
    uVar7 = BecomeMaster((longlong)param_4,(longlong)local_78,(ulonglong)local_80);
    local_88 = (uint)uVar7;
    break;
  case 0x130044:
    if (((param_4[0x40] != '\0') &&
        (cVar4 = IoIsSystemThread(*(undefined8 *)(param_4 + 0x98)), cVar4 == '\0')) &&
       (cVar4 = BowserSecurityCheck((longlong)param_4,(longlong)pIVar13,&local_88), cVar4 == '\0'))
    goto LAB_14001dd00;
    uVar7 = WaitForMasterAnnounce((longlong)param_4,(longlong)local_78,(ulonglong)local_80);
    local_88 = (uint)uVar7;
    break;
  case 0x13004b:
    cVar4 = '\x01';
    goto LAB_14001e136;
  case 0x13004f:
    if (param_4[0x40] != '\0') {
      pcVar11 = *(char **)(param_4 + 0x98);
      cVar4 = IoIsSystemThread();
      if ((cVar4 == '\0') &&
         (pcVar11 = param_4,
         cVar4 = BowserSecurityCheck((longlong)param_4,(longlong)pIVar13,&local_88),
         pIVar12 = pIVar13, cVar4 == '\0')) goto LAB_14001dd00;
    }
    uVar7 = UpdateStatus(pcVar11,pIVar12,(ulonglong)local_78,local_80);
    local_88 = (uint)uVar7;
    break;
  case 0x130050:
    if (((param_4[0x40] != '\0') &&
        (cVar4 = IoIsSystemThread(*(undefined8 *)(param_4 + 0x98)), cVar4 == '\0')) &&
       (cVar4 = BowserSecurityCheck((longlong)param_4,(longlong)pIVar13,&local_88), cVar4 == '\0'))
    goto LAB_14001dd00;
    uVar7 = WaitForBrowserRoleChange((longlong)param_4,(longlong)local_78,(ulonglong)local_80);
    local_88 = (uint)uVar7;
    break;
  case 0x130054:
    uVar7 = WaitForNewMaster((longlong)param_4,(undefined2 *)local_78,(ulonglong)local_80);
    local_88 = (uint)uVar7;
    break;
  case 0x130058:
    uVar5 = QueryStatistics(pcVar11,(undefined8 *)local_60,(int *)&local_70);
    local_88 = (uint)uVar5;
    local_80 = local_70;
    break;
  case 0x13005c:
    if (((param_4[0x40] != '\0') &&
        (cVar4 = IoIsSystemThread(*(undefined8 *)(param_4 + 0x98)), cVar4 == '\0')) &&
       (cVar4 = BowserSecurityCheck((longlong)param_4,(longlong)pIVar13,&local_88), cVar4 == '\0'))
    goto LAB_14001dd00;
    uVar5 = ResetStatistics();
    local_88 = (uint)uVar5;
    break;
  case 0x130066:
    if (((param_4[0x40] != '\0') &&
        (cVar4 = IoIsSystemThread(*(undefined8 *)(param_4 + 0x98)), cVar4 == '\0')) &&
       (cVar4 = BowserSecurityCheck((longlong)param_4,(longlong)pIVar13,&local_88),
       pIVar12 = pIVar13, cVar4 == '\0')) goto LAB_14001dd00;
    uVar7 = BowserReadPnp((longlong)param_4,pIVar12,(ushort *)0x1);
    local_88 = (uint)uVar7;
    break;
  case 0x130080:
    if ((param_4[0x40] != '\0') &&
       (cVar4 = IoIsSystemThread(*(undefined8 *)(param_4 + 0x98)), cVar4 == '\0')) {
      _Size = &local_88;
      cVar4 = BowserSecurityCheck((longlong)param_4,(longlong)pIVar13,_Size);
      if (cVar4 == '\0') goto LAB_14001dd00;
    }
    if (local_80 < 0x3c) {
      local_88 = 0xc000000d;
    }
    else {
      uVar5 = BowserEnablePnp((longlong)local_78,1,_Size);
      local_88 = (uint)uVar5;
    }
    break;
  case 0x13008e:
    if (((param_4[0x40] != '\0') &&
        (cVar4 = IoIsSystemThread(*(undefined8 *)(param_4 + 0x98)), cVar4 == '\0')) &&
       (cVar4 = BowserSecurityCheck((longlong)param_4,(longlong)pIVar13,&local_88),
       pIVar12 = pIVar13, cVar4 == '\0')) goto LAB_14001dd00;
    uVar7 = BowserReadPnp((longlong)param_4,pIVar12,(ushort *)0x0);
    local_88 = (uint)uVar7;
    break;
  case 0x130090:
    if ((param_4[0x40] != '\0') &&
       (cVar4 = IoIsSystemThread(*(undefined8 *)(param_4 + 0x98)), cVar4 == '\0')) {
      _Size = &local_88;
      cVar4 = BowserSecurityCheck((longlong)param_4,(longlong)pIVar13,_Size);
      if (cVar4 == '\0') goto LAB_14001dd00;
    }
    if (local_80 < 0x3c) {
      local_88 = 0xc000000d;
    }
    else {
      uVar5 = BowserEnablePnp((longlong)local_78,0,_Size);
      local_88 = (uint)uVar5;
    }
    break;
  case 0x130097:
    cVar4 = '\0';
LAB_14001e136:
    uVar7 = WriteMailslotEx(pcVar11,(undefined *)local_78,(undefined *)(ulonglong)local_80,local_60,
                            local_70,cVar4);
    local_88 = (uint)uVar7;
  }
LAB_14001e41f:
  LOCK();
  BowserOperationCount = BowserOperationCount + -1;
  UNLOCK();
  uVar7 = local_40;
  cVar4 = local_6c;
  uVar14 = local_70;
  uVar15 = local_80;
LAB_14001e43e:
  if (local_88 != 0x103) {
LAB_14001e44c:
    if (cVar4 != '\0') {
      uVar15 = uVar15 - 0x10;
      local_80 = uVar15;
    }
    if (uVar15 < uVar14) {
      uVar14 = uVar15;
    }
    *(ulonglong *)(param_4 + 0x38) = (ulonglong)uVar14;
    if ((local_7c != '\0') && (uVar7 != 0)) {
      if (param_4[0x40] != '\0') {
        ProbeForWrite(uVar7,uVar15,4);
      }
      uVar8 = Feature_Servicing_UMABowserRdbss__private_IsEnabledDeviceUsageNoInline();
      iVar1 = piVar2[0xe];
      if (cVar4 == '\0') {
        if ((int)uVar8 == 0) {
          *(int *)(uVar7 + 0x38) = iVar1;
          *(int *)(uVar7 + 0x3c) = piVar2[0xf];
          *(int *)(uVar7 + 0x40) = piVar2[0x10];
          *(int *)(uVar7 + 0x44) = piVar2[0x11];
        }
        else {
          RtlWriteULongToUser((undefined4 *)(uVar7 + 0x38),iVar1);
          RtlWriteULongToUser((undefined4 *)(uVar7 + 0x3c),piVar2[0xf]);
          RtlWriteULongToUser((undefined4 *)(uVar7 + 0x40),piVar2[0x10]);
          RtlWriteULongToUser((undefined4 *)(uVar7 + 0x44),piVar2[0x11]);
        }
      }
      else if ((int)uVar8 == 0) {
        *(int *)(uVar7 + 0x28) = iVar1;
        *(int *)(uVar7 + 0x2c) = piVar2[0xf];
        *(int *)(uVar7 + 0x30) = piVar2[0x10];
        *(int *)(uVar7 + 0x34) = piVar2[0x11];
      }
      else {
        RtlWriteULongToUser((undefined4 *)(uVar7 + 0x28),iVar1);
        RtlWriteULongToUser((undefined4 *)(uVar7 + 0x2c),piVar2[0xf]);
        RtlWriteULongToUser((undefined4 *)(uVar7 + 0x30),piVar2[0x10]);
        RtlWriteULongToUser((undefined4 *)(uVar7 + 0x34),piVar2[0x11]);
      }
    }
  }
LAB_14001e587:
  iVar1 = local_84;
  uVar14 = 0xc000009a;
  if (local_50 != (int *)0x0) {
    ExFreePoolWithTag(local_50,0);
  }
  if (local_88 == 0x103) {
    if (local_58 == 0) {
      if ((iVar1 - 0x130034U < 0x33) &&
         ((0x4000110010111U >> ((ulonglong)(iVar1 - 0x130034U) & 0x3f) & 1) != 0)) {
        return 0x103;
      }
      if (iVar1 == 0x13008e) {
        return 0x103;
      }
    }
    if (iVar1 == 0x130097) {
      local_88 = 0;
      param_4[0x30] = '\0';
      param_4[0x31] = '\0';
      param_4[0x32] = '\0';
      param_4[0x33] = '\0';
      goto LAB_14001e6e4;
    }
    lVar9 = ExInterlockedRemoveHeadList(&BowserIrpContextList,&BowserIrpContextInterlock);
    if (lVar9 == 0) {
      lVar9 = ExAllocatePool2(0x42,0x30,0x6369424c);
    }
    if (lVar9 != 0) {
      *(byte *)(*(longlong *)(param_4 + 0xb8) + 3) =
           *(byte *)(*(longlong *)(param_4 + 0xb8) + 3) | 1;
      *(char **)(lVar9 + 0x20) = param_4;
      *(uint **)(lVar9 + 0x28) = param_3;
      lVar10 = IoAllocateWorkItem(BowserDeviceObject);
      if (lVar10 == 0) {
        ExInterlockedInsertTailList(&BowserIrpContextList,lVar9,&BowserIrpContextInterlock);
      }
      else {
        IoQueueWorkItemEx(lVar10,BowserFspDispatchWrapper,1,lVar9);
        uVar14 = 0x103;
      }
    }
    if (uVar14 == 0x103) {
      return 0x103;
    }
    *(uint *)(param_4 + 0x30) = uVar14;
    local_88 = uVar14;
  }
  else {
    *(uint *)(param_4 + 0x30) = local_88;
  }
  if ((local_88 & 0xc0000000) == 0xc0000000) {
    param_4[0x38] = '\0';
    param_4[0x39] = '\0';
    param_4[0x3a] = '\0';
    param_4[0x3b] = '\0';
    param_4[0x3c] = '\0';
    param_4[0x3d] = '\0';
    param_4[0x3e] = '\0';
    param_4[0x3f] = '\0';
  }
LAB_14001e6e4:
  IofCompleteRequest(param_4,0);
  return local_88;
}



===== BowserFindName @ 14001e720 =====

undefined8 * BowserFindName(byte *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  uStack_10 = 0;
  uVar3 = BowserValidUnicodeString(param_1);
  if ((int)uVar3 != 0) {
    iVar2 = RtlUpcaseUnicodeStringToOemString(&local_28,param_1,1);
    if (-1 < iVar2) {
      iVar2 = RtlOemStringToUnicodeString(&local_18,&local_28,1);
      RtlFreeOemString(&local_28);
      if (-1 < iVar2) {
        ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
        puVar4 = BowserNameHead;
        do {
          puVar5 = (undefined8 *)0x0;
          if ((undefined8 **)puVar4 == &BowserNameHead) {
LAB_14001e7fd:
            RtlFreeUnicodeString(&local_18);
            ExReleaseResourceLite(&BowserTransportDatabaseResource);
            return puVar5;
          }
          puVar5 = puVar4 + -1;
          if ((*(int *)(puVar4 + 6) == param_2) &&
             (cVar1 = RtlEqualUnicodeString(puVar4 + 4,&local_18,0), cVar1 != '\0')) {
            *(int *)((longlong)puVar4 + -4) = *(int *)((longlong)puVar4 + -4) + 1;
            goto LAB_14001e7fd;
          }
          puVar4 = (undefined8 *)*puVar4;
        } while( true );
      }
    }
  }
  return (undefined8 *)0x0;
}



===== BowserSendElection @ 14001e850 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong BowserSendElection(longlong param_1,undefined8 param_2,longlong param_3,char param_4)

{
  uint uVar1;
  longlong lVar2;
  char *pcVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  char *pcVar6;
  longlong lVar7;
  undefined2 uVar8;
  uint uVar9;
  bool bVar10;
  undefined1 auStackY_a8 [32];
  undefined1 local_60;
  undefined1 local_5f;
  undefined8 local_5e;
  undefined4 local_56;
  char local_52 [18];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_a8;
  lVar2 = *(longlong *)(param_3 + 8);
  if (*(char *)(lVar2 + 0x15d) == '\0') {
    if ((param_4 == '\0') || ((*(uint *)(lVar2 + 0xfc) & 0x70000) == 0)) {
      local_5f = 0;
      local_5e = 0;
      uVar9 = 0;
      local_52[0] = '\0';
    }
    else {
      lVar7 = 0x10;
      local_5e = CONCAT44(*(undefined4 *)(lVar2 + 0x10c),*(undefined4 *)(lVar2 + 0x114));
      local_5f = 1;
      lVar2 = *(longlong *)(*(longlong *)(param_3 + 0x38) + 0xb0);
      uVar9 = (uint)*(ushort *)(*(longlong *)(param_3 + 0x38) + 0xa8);
      pcVar3 = local_52;
      do {
        if ((lVar7 == -0x7fffffee) || (pcVar3[lVar2 - (longlong)local_52] == '\0')) break;
        *pcVar3 = pcVar3[lVar2 - (longlong)local_52];
        pcVar3 = pcVar3 + 1;
        lVar7 = lVar7 + -1;
      } while (lVar7 != 0);
      bVar10 = lVar7 != 0;
      pcVar6 = pcVar3 + -1;
      if (bVar10) {
        pcVar6 = pcVar3;
      }
      uVar4 = 0x80000005;
      if (bVar10) {
        uVar4 = 0;
      }
      *pcVar6 = '\0';
      if (!bVar10) {
        return uVar4;
      }
    }
    local_56 = 0;
    local_60 = 8;
    uVar1 = uVar9 + 0x65;
    if ((uVar1 < uVar9 + 0x20) ||
       (puVar5 = (undefined8 *)ExAllocatePool2(0x40,uVar1,0x686d424c), puVar5 == (undefined8 *)0x0))
    {
      uVar4 = 0xc000009a;
    }
    else {
      *(undefined4 *)puVar5 = 0x424d53ff;
      *(undefined1 *)((longlong)puVar5 + 4) = 0x25;
      *(undefined1 *)(puVar5 + 4) = 0x11;
      uVar8 = (undefined2)(uVar9 + 0xf);
      *(undefined2 *)((longlong)puVar5 + 0x23) = uVar8;
      *(undefined4 *)((longlong)puVar5 + 0x2d) = 1000;
      *(undefined2 *)((longlong)puVar5 + 0x37) = uVar8;
      *(undefined1 *)((longlong)puVar5 + 0x3b) = 3;
      *(short *)((longlong)puVar5 + 0x39) = (short)(void *)((longlong)puVar5 + 0x56) - (short)puVar5
      ;
      *(undefined4 *)((longlong)puVar5 + 0x3d) = 0x10001;
      *(undefined2 *)((longlong)puVar5 + 0x41) = 2;
      *(short *)((longlong)puVar5 + 0x43) = (short)(uVar9 + 0x20);
      builtin_strncpy((char *)((longlong)puVar5 + 0x45),"\\MAILSLO",8);
      builtin_strncpy((char *)((longlong)puVar5 + 0x4d),"T\\BROWSE",8);
      *(undefined1 *)((longlong)puVar5 + 0x55) = 0;
      memcpy((void *)((longlong)puVar5 + 0x56),&local_60,(ulonglong)(uVar9 + 0xf));
      uVar4 = BowserSendDatagram(param_3,param_1,7,puVar5,uVar1,'\x01',(ushort *)0x0,'\0');
    }
  }
  else {
    uVar4 = 0xc0000001;
  }
  return uVar4;
}



===== BowserMapUsersBuffer @ 14001eaa0 =====

ulonglong BowserMapUsersBuffer(longlong param_1,ulonglong *param_2,int param_3)

{
  byte bVar1;
  longlong lVar2;
  ulonglong uVar3;
  
  lVar2 = *(longlong *)(param_1 + 8);
  if (lVar2 == 0) {
    uVar3 = *(ulonglong *)(param_1 + 0x18);
    if (uVar3 != 0) {
      *param_2 = uVar3;
      return uVar3 & 0xffffffffffffff00;
    }
    uVar3 = 0;
    if (*(char *)(param_1 + 0x40) == '\0') goto LAB_14001eae7;
    if ((param_3 != 0) && (lVar2 = *(longlong *)(param_1 + 0x70), lVar2 != 0)) {
      bVar1 = **(byte **)(param_1 + 0xb8);
      if ((byte)(bVar1 - 0xd) < 2) {
        if (((byte)*(undefined4 *)(*(byte **)(param_1 + 0xb8) + 0x18) & 3) == 3) goto LAB_14001eb7b;
      }
      else if ((bVar1 < 0x15) && ((0x101428U >> (bVar1 & 0x1f) & 1) != 0)) {
LAB_14001eb7b:
        ProbeForWrite(lVar2,param_3,1);
      }
      else {
        ProbeForRead(lVar2,param_3,1);
      }
    }
    uVar3 = *(ulonglong *)(param_1 + 0x70);
  }
  else {
    if ((*(byte *)(lVar2 + 10) & 5) != 0) {
      uVar3 = *(ulonglong *)(lVar2 + 0x18);
      *param_2 = uVar3;
      return uVar3 & 0xffffffffffffff00;
    }
    uVar3 = MmMapLockedPagesSpecifyCache(lVar2,0,1,0,0,0x40000000);
  }
  *param_2 = uVar3;
LAB_14001eae7:
  return uVar3 & 0xffffffffffffff00;
}



===== RdrDiscardableCodeRoutine @ 14001eba0 =====

void RdrDiscardableCodeRoutine(longlong param_1)

{
  ExAcquireResourceExclusiveLite(&RdrDiscardableCodeLock,1);
  if ((*(char *)(param_1 + 5) == '\0') && (*(char *)(param_1 + 4) != '\0')) {
    *(undefined1 *)(param_1 + 4) = 0;
    if (*(longlong *)(param_1 + 0x30) != 0) {
      MmUnlockPagableImageSection();
      *(undefined8 *)(param_1 + 0x30) = 0;
    }
    if (*(longlong *)(param_1 + 0x40) != 0) {
      MmUnlockPagableImageSection();
      *(undefined8 *)(param_1 + 0x40) = 0;
    }
  }
  ExFreePoolWithTag(*(undefined8 *)(param_1 + 8),0);
  *(undefined8 *)(param_1 + 8) = 0;
  ExReleaseResourceLite(&RdrDiscardableCodeLock);
  KeSetEvent(param_1 + 0x10,0,0);
  return;
}



===== AddTransportName @ 14001ec60 =====

int AddTransportName(longlong param_1,longlong param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  longlong *plVar6;
  longlong *plVar7;
  undefined8 uVar8;
  
  plVar6 = (longlong *)ExAllocatePool2(0x102,0x38,0x6e61424c);
  if (plVar6 != (longlong *)0x0) {
    uVar8 = 0;
    plVar6[2] = 0;
    plVar6[3] = param_1;
    plVar7 = plVar6;
    if (param_1 != 0) {
      plVar7 = (longlong *)BowserReferenceTransport(param_1);
    }
    uVar2 = *(undefined4 *)(param_2 + 0x14);
    uVar3 = *(undefined4 *)(param_2 + 0x18);
    uVar4 = *(undefined4 *)(param_2 + 0x1c);
    *(undefined4 *)(plVar7 + 4) = *(undefined4 *)(param_2 + 0x10);
    *(undefined4 *)((longlong)plVar7 + 0x24) = uVar2;
    *(undefined4 *)(plVar7 + 5) = uVar3;
    *(undefined4 *)((longlong)plVar7 + 0x2c) = uVar4;
    *(undefined4 *)(plVar6 + 6) = *(undefined4 *)(param_2 + 0x20);
    iVar5 = PsCreateSystemThread(plVar6 + 2,0x1fffff,0,0,uVar8,AsyncCreateTransportName,plVar6);
    if (iVar5 < 0) {
      if (param_1 != 0) {
        BowserDereferenceTransport(param_1);
      }
      ExFreePoolWithTag(plVar6,0);
      goto LAB_14001ed1c;
    }
    plVar7 = *(longlong **)(param_2 + 8);
    if (*plVar7 == param_2) {
      plVar6[1] = (longlong)plVar7;
      *plVar6 = param_2;
      *plVar7 = (longlong)plVar6;
      iVar5 = 0;
      *(longlong **)(param_2 + 8) = plVar6;
      goto LAB_14001ed1c;
    }
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(3);
  }
  iVar5 = -0x3fffff66;
LAB_14001ed1c:
  return iVar5;
}



===== BowserFsdCreate @ 14001ed70 =====

undefined8 BowserFsdCreate(undefined8 param_1,longlong param_2)

{
  LOCK();
  BowserNumberOfOpenFiles = BowserNumberOfOpenFiles + 1;
  UNLOCK();
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== BowserFindTransportName @ 14001edb0 =====

undefined8 BowserFindTransportName(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  
  uVar3 = 0;
  ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
  puVar1 = (undefined8 *)(*(longlong *)(param_1 + 8) + 0x20);
  for (puVar2 = (undefined8 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined8 *)*puVar2) {
    if (puVar2[-1] == param_2) {
      uVar3 = puVar2[-2];
    }
  }
  ExReleaseResourceLite(&BowserTransportDatabaseResource);
  return uVar3;
}



===== EnumerateNamesTransportNameWorker @ 14001ee40 =====

undefined8 EnumerateNamesTransportNameWorker(longlong param_1,longlong *param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  ushort *puVar3;
  undefined8 uVar4;
  char cVar5;
  ulonglong uVar6;
  undefined8 local_18;
  longlong lStack_10;
  
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x10);
  if (*(short *)(lVar2 + 0x28) != 0) {
    for (uVar6 = 0; (uint)uVar6 < *(uint *)((longlong)param_2 + 0x1c);
        uVar6 = (ulonglong)((uint)uVar6 + 1)) {
      puVar1 = (undefined8 *)(*param_2 + uVar6 * 0x18);
      if (*(int *)(lVar2 + 0x38) == *(int *)(*param_2 + 0x10 + uVar6 * 0x18)) {
        local_18 = *puVar1;
        lStack_10 = puVar1[1] + param_2[5];
        cVar5 = RtlEqualUnicodeString(&local_18,lVar2 + 0x28,0);
        if (cVar5 != '\0') {
          return 0;
        }
      }
    }
    *(int *)(param_2 + 4) = (int)param_2[4] + 1;
    puVar3 = (ushort *)param_2[1];
    if ((ulonglong)*(ushort *)(lVar2 + 0x28) + 0x18 < (ulonglong)(param_2[2] - (longlong)puVar3)) {
      puVar3[0] = 0;
      puVar3[1] = 0;
      puVar3[2] = 0;
      puVar3[3] = 0;
      puVar3[4] = 0;
      puVar3[5] = 0;
      puVar3[6] = 0;
      puVar3[7] = 0;
      puVar3[8] = 0;
      puVar3[9] = 0;
      puVar3[10] = 0;
      puVar3[0xb] = 0;
      param_2[1] = param_2[1] + 0x18;
      *(int *)((longlong)param_2 + 0x1c) = *(int *)((longlong)param_2 + 0x1c) + 1;
      uVar4 = *(undefined8 *)(lVar2 + 0x30);
      *(undefined8 *)puVar3 = *(undefined8 *)(lVar2 + 0x28);
      *(undefined8 *)(puVar3 + 4) = uVar4;
      BowserPackNtString(puVar3,param_2[5],param_2[1],param_2 + 2);
      *(undefined4 *)(puVar3 + 8) = *(undefined4 *)(lVar2 + 0x38);
    }
    *(int *)((longlong)param_2 + 0x24) =
         *(int *)((longlong)param_2 + 0x24) + *(ushort *)(lVar2 + 0x28) + 0x18;
  }
  return 0;
}



===== WriteMailslotEx @ 14001ef40 =====

ulonglong WriteMailslotEx(undefined8 param_1,undefined *param_2,undefined *param_3,char *param_4,
                         uint param_5,char param_6)

{
  uint uVar1;
  longlong lVar2;
  ushort uVar3;
  ulonglong uVar4;
  uint uVar5;
  ushort uVar6;
  undefined8 local_40;
  char *pcStack_38;
  undefined8 local_30;
  undefined *puStack_28;
  
  lVar2 = 0;
  local_30 = 0;
  puStack_28 = (undefined *)0x0;
  local_40 = 0;
  pcStack_38 = (char *)0x0;
  uVar5 = (uint)param_3;
  if ((((0x44 < uVar5) && (param_5 != 0)) && (*(int *)(param_2 + 4) == 7)) &&
     (*(ushort *)(param_2 + 0x18) != 0)) {
    uVar3 = *(ushort *)(param_2 + 0x1a);
    if (((uVar3 <= uVar5) && (*(ushort *)(param_2 + 0x18) <= uVar3)) &&
       ((param_2 <= *(undefined **)(param_2 + 0x20) &&
        (uVar4 = (ulonglong)param_3 & 0xffffffff,
        *(undefined **)(param_2 + 0x20) <=
        param_2 + (((ulonglong)param_3 & 0xffffffff) - (ulonglong)uVar3))))) {
      uVar3 = *(ushort *)(param_2 + 0x28);
      if (uVar3 == 0) {
        *(undefined8 *)(param_2 + 0x30) = 0;
        *(undefined2 *)(param_2 + 0x2a) = 0;
      }
      else {
        uVar6 = *(ushort *)(param_2 + 0x2a);
        if (((uVar5 < uVar6) || (uVar6 < uVar3)) ||
           ((*(undefined **)(param_2 + 0x30) < param_2 ||
            (param_3 = param_2 + (uVar4 - uVar6), param_3 < *(undefined **)(param_2 + 0x30)))))
        goto LAB_14001f145;
      }
      lVar2 = BowserFindTransport(param_2 + 0x18,(ushort *)(param_2 + 0x28));
      if (lVar2 == 0) {
        uVar4 = 0xc0000034;
        goto LAB_14001f14a;
      }
      uVar3 = *(ushort *)(param_2 + 0x40);
      local_30 = CONCAT62(CONCAT42(local_30._4_4_,uVar3),uVar3);
      puStack_28 = param_2 + 0x44;
      if ((((uVar3 != 0) && (uVar3 <= uVar5)) && (param_2 <= puStack_28)) &&
         (puStack_28 <= param_2 + (uVar4 - (uint)uVar3))) {
        uVar1 = *(uint *)(param_2 + 0x3c);
        if (uVar1 == 0) {
          local_40 = CONCAT44(local_40._4_4_,0x110010);
          pcStack_38 = "\\MAILSLOT\\BROWSE";
        }
        else {
          pcStack_38 = param_2 + (ulonglong)*(uint *)(param_2 + 0x40) + 0x44;
          uVar3 = (ushort)uVar1;
          uVar6 = uVar3 - 1;
          param_3 = (undefined *)(ulonglong)uVar6;
          local_40 = CONCAT62(CONCAT42(local_40._4_4_,uVar3),uVar6);
          if ((((uVar6 == 0) || (uVar5 < (uVar1 & 0xffff))) ||
              ((uVar3 < uVar6 ||
               ((pcStack_38 < param_2 ||
                (param_2 + (uVar4 - ((ulonglong)uVar1 & 0xffff)) < pcStack_38)))))) ||
             (pcStack_38[uVar6] != '\0')) goto LAB_14001f145;
        }
        BowWriteTelemetryMailslotProcessing3((ulonglong)uVar1,(ushort *)&local_40,param_3);
        uVar4 = BowserSendSecondClassMailslot
                          (lVar2,(longlong)&local_30,*(int *)(param_2 + 0x38),param_4,param_5,
                           param_6,pcStack_38,(ushort *)0x0);
        uVar4 = uVar4 & 0xffffffff;
        goto LAB_14001f14a;
      }
    }
  }
LAB_14001f145:
  uVar4 = 0xc000000d;
LAB_14001f14a:
  if (lVar2 != 0) {
    BowserDereferenceTransport(lVar2);
  }
  return uVar4;
}



===== BowserEnumerateNamesInDomain @ 14001f180 =====

undefined4
BowserEnumerateNamesInDomain
          (longlong param_1,longlong param_2,void *param_3,uint param_4,int *param_5,int *param_6,
          undefined4 *param_7,longlong param_8)

{
  void *pvVar1;
  void *_Src;
  undefined4 uVar2;
  void *local_48;
  void *local_40;
  void *pvStack_38;
  uint local_30;
  undefined8 local_2c;
  undefined4 local_24;
  longlong local_20;
  
  local_48 = (void *)0x0;
  local_40 = (void *)0x0;
  pvStack_38 = (void *)0x0;
  local_30 = 0;
  local_20 = 0;
  _Src = (void *)ExAllocatePool2(0x102,param_4,0x656e424c);
  if (_Src == (void *)0x0) {
    uVar2 = 0xc000009a;
  }
  else {
    pvVar1 = (void *)((ulonglong)param_4 + (longlong)_Src);
    local_2c = 0;
    local_24 = 0;
    local_20 = (longlong)_Src + (param_8 - (longlong)param_3);
    local_48 = _Src;
    local_40 = _Src;
    pvStack_38 = pvVar1;
    local_30 = param_4;
    if (param_2 == 0) {
      BowserForEachTransportInDomain(param_1,EnumerateNamesTransportWorker,&local_48);
    }
    else {
      BowserForEachTransportName(param_2,EnumerateNamesTransportNameWorker,&local_48);
    }
    *param_5 = (int)local_2c;
    *param_6 = local_2c._4_4_;
    *param_7 = local_24;
    memcpy(param_3,_Src,(ulonglong)(uint)((int)local_40 - (int)local_48));
    memcpy((void *)((ulonglong)(uint)((int)pvStack_38 - (int)local_48) + (longlong)param_3),
           pvStack_38,(ulonglong)(uint)((int)pvVar1 - (int)pvStack_38));
    uVar2 = 0x105;
    if (*param_5 == *param_6) {
      uVar2 = 0;
    }
    ExFreePoolWithTag(_Src,0);
  }
  return uVar2;
}



===== WaitForAddNameOperation @ 14001f320 =====

int WaitForAddNameOperation(longlong *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  while( true ) {
    plVar1 = (longlong *)*param_1;
    if (plVar1 == param_1) {
      return iVar4;
    }
    if (((longlong *)plVar1[1] != param_1) || (lVar2 = *plVar1, *(longlong **)(lVar2 + 8) != plVar1)
       ) break;
    *param_1 = lVar2;
    *(longlong **)(lVar2 + 8) = param_1;
    ZwWaitForSingleObject(plVar1[2],0,0);
    ZwClose(plVar1[2]);
    iVar5 = *(int *)((longlong)plVar1 + 0x34);
    ExFreePoolWithTag(plVar1);
    if (-1 < iVar5) {
      iVar5 = iVar4;
    }
    iVar4 = iVar5;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  return iVar4;
}



===== BowserCompareAnnouncement @ 14001f3d0 =====

char BowserCompareAnnouncement(undefined8 param_1,longlong param_2,longlong param_3)

{
  int iVar1;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  local_28 = 0;
  uStack_20 = 0;
  RtlInitUnicodeString(&local_18,param_2 + 0x2a);
  RtlInitUnicodeString(&local_28,param_3 + 0x2a);
  iVar1 = RtlCompareUnicodeString(&local_18,&local_28,0);
  if (iVar1 < 0) {
    return '\0';
  }
  return (iVar1 < 1) + '\x01';
}



===== BowserDereferenceDomain @ 14001f450 =====

void BowserDereferenceDomain(undefined8 *param_1)

{
  int *piVar1;
  int iVar2;
  longlong *plVar3;
  longlong *plVar4;
  code *pcVar5;
  
  ExAcquireResourceExclusiveLite(&BowserTransportDatabaseResource,1);
  piVar1 = (int *)(param_1 + 0x17);
  *piVar1 = *piVar1 + -1;
  iVar2 = *(int *)(param_1 + 0x17);
  if (*piVar1 == 0) {
    plVar3 = (longlong *)*param_1;
    if (((undefined8 *)plVar3[1] != param_1) ||
       (plVar4 = (longlong *)param_1[1], (undefined8 *)*plVar4 != param_1)) {
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      pcVar5 = (code *)swi(3);
      (*pcVar5)();
      return;
    }
    *plVar4 = (longlong)plVar3;
    plVar3[1] = (longlong)plVar4;
    if (plVar4 != plVar3) {
      ExReleaseResourceLite(&BowserTransportDatabaseResource);
      goto LAB_14001f4d5;
    }
  }
  ExReleaseResourceLite(&BowserTransportDatabaseResource);
  if (iVar2 != 0) {
    return;
  }
LAB_14001f4d5:
  ExFreePoolWithTag(param_1,0);
  return;
}



===== WaitForBrowserRoleChange @ 14001f500 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong WaitForBrowserRoleChange(longlong param_1,longlong param_2,undefined8 param_3)

{
  ulonglong uVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined1 auStack_2a8 [32];
  longlong local_288;
  ushort local_280 [4];
  undefined1 *local_278;
  byte local_270 [8];
  undefined1 *local_268;
  undefined1 local_260 [40];
  undefined1 local_238 [528];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_2a8;
  lVar2 = 0;
  local_288 = 0;
  local_270[0] = 0;
  local_270[1] = 0;
  local_270[2] = 10;
  local_270[3] = 2;
  local_270[4] = 0;
  local_270[5] = 0;
  local_270[6] = 0;
  local_270[7] = 0;
  local_268 = local_238;
  local_280[0] = 0;
  local_280[1] = 0x20;
  local_280[2] = 0;
  local_280[3] = 0;
  local_278 = local_260;
  if ((uint)param_3 < 0x60) {
    uVar3 = 0xc000000d;
  }
  else {
    uVar1 = BowserProbeAndCopyBuffer((ushort *)(param_2 + 0x18),(undefined2 *)local_270);
    uVar3 = uVar1 & 0xffffffff;
    if (-1 < (int)uVar1) {
      uVar1 = BowserProbeAndCopyBuffer((ushort *)(param_2 + 0x28),local_280);
      uVar3 = uVar1 & 0xffffffff;
      if (-1 < (int)uVar1) {
        lVar2 = BowserFindTransport(local_270,local_280);
        local_288 = lVar2;
        if (lVar2 == 0) {
          uVar3 = 0xc0000034;
        }
        else {
          uVar3 = BowserQueueNonBufferRequest(param_1,(longlong *)(lVar2 + 0x3b8),param_3,'\0');
          uVar3 = uVar3 & 0xffffffff;
        }
      }
    }
  }
  if (lVar2 != 0) {
    BowserDereferenceTransport(lVar2);
  }
  return uVar3;
}



===== BowserTransportFlags @ 14001f600 =====

byte BowserTransportFlags(longlong param_1)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  
  bVar3 = *(char *)(param_1 + 0x15a) != '\0';
  bVar2 = bVar3 | 8;
  if (*(char *)(param_1 + 0x15c) == '\0') {
    bVar2 = bVar3;
  }
  bVar1 = bVar2 | 2;
  if (*(char *)(param_1 + 0x15b) == '\0') {
    bVar1 = bVar2;
  }
  bVar2 = bVar1 | 4;
  if (-1 < *(short *)(param_1 + 0x158)) {
    bVar2 = bVar1;
  }
  return bVar2;
}



===== _tlgEnableCallback @ 14001f650 =====

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



===== EnumNames @ 14001f6d0 =====

undefined4
EnumNames(undefined8 param_1,undefined8 param_2,int *param_3,uint *param_4,void *param_5,
         uint param_6,longlong param_7)

{
  ushort uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined8 *puVar4;
  longlong lVar5;
  
  puVar4 = (undefined8 *)0x0;
  lVar5 = 0;
  uVar2 = *param_4;
  if (((uVar2 < 0x60) || (param_3[1] != 7)) || (*param_3 != 0)) {
LAB_14001f844:
    uVar3 = 0xc000000d;
  }
  else {
    if (param_6 < 0x18) {
      uVar3 = 0xc0000023;
      goto LAB_14001f849;
    }
    if (*(ushort *)(param_3 + 10) == 0) {
      param_3[0xc] = 0;
      param_3[0xd] = 0;
      *(undefined2 *)((longlong)param_3 + 0x2a) = 0;
    }
    else {
      uVar1 = *(ushort *)((longlong)param_3 + 0x2a);
      if (((uVar2 < uVar1) || (uVar1 < *(ushort *)(param_3 + 10))) ||
         ((*(int **)(param_3 + 0xc) < param_3 ||
          ((int *)(((ulonglong)uVar2 - (ulonglong)uVar1) + (longlong)param_3) <
           *(int **)(param_3 + 0xc))))) goto LAB_14001f844;
    }
    puVar4 = BowserFindDomain((ushort *)(param_3 + 10));
    if (puVar4 == (undefined8 *)0x0) {
      uVar3 = 0xc0000034;
      goto LAB_14001f849;
    }
    if (*(ushort *)(param_3 + 6) != 0) {
      uVar1 = *(ushort *)((longlong)param_3 + 0x1a);
      if (((uVar2 < uVar1) || (uVar1 < *(ushort *)(param_3 + 6))) ||
         ((*(int **)(param_3 + 8) < param_3 ||
          ((int *)(((ulonglong)uVar2 - (ulonglong)uVar1) + (longlong)param_3) <
           *(int **)(param_3 + 8))))) goto LAB_14001f844;
      lVar5 = BowserFindTransport((byte *)(param_3 + 6),(ushort *)(param_3 + 10));
      if (lVar5 == 0) {
        uVar3 = 0xc0000034;
        goto LAB_14001f849;
      }
    }
    uVar3 = BowserEnumerateNamesInDomain
                      ((longlong)puVar4,lVar5,param_5,param_6,param_3 + 0xe,param_3 + 0xf,
                       param_3 + 0x10,param_7);
    *param_4 = 0x60;
  }
LAB_14001f849:
  if (puVar4 != (undefined8 *)0x0) {
    BowserDereferenceDomain(puVar4);
  }
  if (lVar5 != 0) {
    BowserDereferenceTransport(lVar5);
  }
  return uVar3;
}



===== BowserFsdClose @ 14001f890 =====

undefined8 BowserFsdClose(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== BowserShuffleBrowserServerList @ 14001f8c0 =====

void BowserShuffleBrowserServerList(undefined8 *param_1,uint param_2,char param_3,longlong param_4)

{
  undefined8 uVar1;
  int iVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  
  if (param_2 != 0) {
    uVar4 = (ulonglong)param_2;
    puVar5 = param_1;
    do {
      uVar3 = RtlRandom(&BowserRandomSeed);
      uVar1 = *puVar5;
      uVar3 = (uVar3 & 0xffffffff) % (ulonglong)param_2;
      *puVar5 = param_1[uVar3];
      param_1[uVar3] = uVar1;
      uVar4 = uVar4 - 1;
      puVar5 = puVar5 + 1;
    } while (uVar4 != 0);
  }
  if (param_3 != '\0') {
    for (uVar4 = 0; (uint)uVar4 < param_2; uVar4 = (ulonglong)((uint)uVar4 + 1)) {
      iVar2 = BowserForEachTransportInDomain
                        (param_4,BowserCheckForPrimaryBrowserServer,param_1[uVar4]);
      if (-1 < iVar2) {
        uVar1 = *param_1;
        *param_1 = param_1[uVar4];
        param_1[uVar4] = uVar1;
        return;
      }
    }
  }
  return;
}



===== BowserBuildTransportAddress @ 14001f980 =====

ulonglong BowserBuildTransportAddress
                    (undefined2 *param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  short sVar1;
  undefined4 *puVar2;
  int iVar3;
  ulonglong uVar4;
  uint7 uVar6;
  ulonglong uVar5;
  uint uVar7;
  ushort local_18 [4];
  char *local_10;
  
  puVar2 = *(undefined4 **)(param_1 + 4);
  local_18[2] = 0;
  local_18[3] = 0;
  uVar6 = (uint7)((ulonglong)param_3 >> 8);
  uVar5 = CONCAT71(uVar6,0x20);
  if ((ushort)param_1[1] < 0x1a) {
    return 0xc0000023;
  }
  puVar2[1] = 0x110012;
  *puVar2 = 1;
  *param_1 = 0x1a;
  local_10 = (char *)((longlong)puVar2 + 10);
  local_18[0] = 0;
  local_18[1] = 0x10;
  iVar3 = (int)param_3;
  if (iVar3 == 7) {
    uVar7 = 0;
    if (-1 < *(short *)(*(longlong *)(param_4 + 8) + 0x158)) {
      uVar7 = 0x1e;
    }
    uVar5 = (ulonglong)uVar7;
    goto LAB_14001fa5f;
  }
  if (iVar3 == 5) {
    builtin_strncpy(local_10,"\x01\x02__MSBR",8);
    builtin_strncpy((char *)((longlong)puVar2 + 0x12),"OWSE__\x02\x01",8);
    *(undefined2 *)(puVar2 + 2) = 1;
    return 0;
  }
  switch(iVar3) {
  case 1:
  case 0xb:
    uVar5 = (ulonglong)uVar6 << 8;
  case 8:
    *(undefined2 *)(puVar2 + 2) = 0;
    break;
  case 2:
  case 4:
    uVar5 = (ulonglong)uVar6 << 8;
    goto LAB_14001fa5f;
  case 6:
    sVar1 = *(short *)(*(longlong *)(param_4 + 8) + 0x158);
    *(undefined2 *)(puVar2 + 2) = 0;
    uVar5 = 0;
    if (-1 < sVar1) {
      uVar5 = 0x1d;
    }
    break;
  case 9:
    uVar5 = CONCAT71(uVar6,0x1c);
LAB_14001fa5f:
    *(undefined2 *)(puVar2 + 2) = 1;
    break;
  case 10:
    uVar5 = CONCAT71(uVar6,0x1b);
    *(undefined2 *)(puVar2 + 2) = 0;
  }
  uVar4 = BowserCanonicalizeNetBiosName(local_18,param_2,(char)uVar5);
  if ((int)uVar4 < 0) {
    BowWriteTelemetryCanonicalizeNameFailure(L"BowserBuildTransportAddress",(int)uVar4,uVar5);
    uVar4 = uVar4 & 0xffffffff;
  }
  return uVar4;
}



===== BowserPackUnicodeString @ 14001fab0 =====

uint BowserPackUnicodeString
               (ulonglong *param_1,uint param_2,longlong param_3,ulonglong param_4,
               ulonglong *param_5)

{
  ulonglong uVar1;
  uint uVar2;
  ulonglong uVar3;
  void *_Dst;
  undefined2 local_res10 [4];
  
  local_res10[0] = 0;
  uVar1 = *param_5;
  if (*param_1 == 0) {
    param_2 = 0;
    *param_1 = (ulonglong)local_res10;
  }
  uVar2 = param_2 + 2;
  uVar3 = *param_5 & 0xfffffffffffffffe;
  *param_5 = uVar3;
  if ((uVar3 < param_4) || ((uint)((int)uVar1 - (int)param_4) < uVar2)) {
    *param_1 = 0;
    uVar2 = 0;
  }
  else {
    _Dst = (void *)(uVar3 - uVar2);
    *param_5 = (ulonglong)_Dst;
    memcpy(_Dst,(void *)*param_1,(ulonglong)uVar2 - 2);
    uVar1 = *param_5;
    *param_1 = uVar1;
    *(undefined2 *)(uVar1 + (ulonglong)(param_2 >> 1) * 2) = 0;
    *param_1 = *param_1 - param_3;
  }
  return uVar2;
}



===== HandleBecomeBackup @ 14001fb60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong HandleBecomeBackup(longlong param_1,longlong param_2,undefined8 param_3)

{
  ulonglong uVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined1 auStack_2a8 [32];
  longlong local_288;
  ushort local_280 [4];
  undefined1 *local_278;
  byte local_270 [8];
  undefined1 *local_268;
  undefined1 local_260 [40];
  undefined1 local_238 [528];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_2a8;
  lVar2 = 0;
  local_288 = 0;
  local_270[0] = 0;
  local_270[1] = 0;
  local_270[2] = 10;
  local_270[3] = 2;
  local_270[4] = 0;
  local_270[5] = 0;
  local_270[6] = 0;
  local_270[7] = 0;
  local_268 = local_238;
  local_280[0] = 0;
  local_280[1] = 0x20;
  local_280[2] = 0;
  local_280[3] = 0;
  local_278 = local_260;
  if ((uint)param_3 < 0x60) {
    uVar3 = 0xc000000d;
  }
  else {
    uVar1 = BowserProbeAndCopyBuffer((ushort *)(param_2 + 0x18),(undefined2 *)local_270);
    uVar3 = uVar1 & 0xffffffff;
    if (-1 < (int)uVar1) {
      uVar1 = BowserProbeAndCopyBuffer((ushort *)(param_2 + 0x28),local_280);
      uVar3 = uVar1 & 0xffffffff;
      if (-1 < (int)uVar1) {
        lVar2 = BowserFindTransport(local_270,local_280);
        local_288 = lVar2;
        if (lVar2 == 0) {
          uVar3 = 0xc0000034;
        }
        else {
          uVar3 = BowserQueueNonBufferRequest(param_1,(longlong *)(lVar2 + 0x378),param_3,'\0');
          uVar3 = uVar3 & 0xffffffff;
        }
      }
    }
  }
  if (lVar2 != 0) {
    BowserDereferenceTransport(lVar2);
  }
  return uVar3;
}



===== BowserAllocateAnnouncement @ 14001fc60 =====

void BowserAllocateAnnouncement(undefined8 param_1,undefined4 param_2)

{
  ExAllocatePool2(0x102,param_2,0x6e61424c);
  return;
}



===== WaitForNewMaster @ 14001fc8c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong WaitForNewMaster(longlong param_1,undefined2 *param_2,ulonglong param_3)

{
  undefined2 *puVar1;
  ushort uVar2;
  longlong lVar3;
  char cVar4;
  uint uVar5;
  ulonglong uVar6;
  longlong lVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  undefined1 auStack_2f8 [32];
  ulonglong local_2d8;
  undefined1 *puStack_2d0;
  longlong local_2c8;
  ushort local_2c0 [4];
  undefined1 *local_2b8;
  byte local_2b0 [8];
  undefined1 *local_2a8;
  ulonglong local_2a0;
  undefined2 *puStack_298;
  undefined1 local_290 [32];
  undefined1 local_270 [40];
  undefined1 local_248 [528];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_2f8;
  lVar7 = 0;
  local_2c8 = 0;
  local_2a0 = 0;
  puStack_298 = (undefined2 *)0x0;
  lVar3 = *(longlong *)(param_1 + 0xb8);
  local_2b0[0] = 0;
  local_2b0[1] = 0;
  local_2b0[2] = 10;
  local_2b0[3] = 2;
  local_2b0[4] = 0;
  local_2b0[5] = 0;
  local_2b0[6] = 0;
  local_2b0[7] = 0;
  local_2a8 = local_248;
  local_2c0[0] = 0;
  local_2c0[1] = 0x20;
  local_2c0[2] = 0;
  local_2c0[3] = 0;
  local_2b8 = local_290;
  if (0x3c < (uint)param_3) {
    puVar1 = param_2 + 0x1e;
    uVar2 = param_2[0x1c];
    local_2a0 = (ulonglong)CONCAT22(uVar2,uVar2);
    puStack_298 = puVar1;
    if ((((uVar2 != 0) && ((uint)uVar2 <= (uint)param_3)) && (param_2 <= puVar1)) &&
       (uVar9 = param_3 & 0xffffffff,
       puVar1 <= (undefined2 *)
                 (((param_3 & 0xffffffff) - (ulonglong)(uint)uVar2) + (longlong)param_2))) {
      uVar6 = BowserProbeAndCopyBuffer(param_2 + 0xc,(undefined2 *)local_2b0);
      uVar8 = uVar6 & 0xffffffff;
      if ((int)uVar6 < 0) goto LAB_14001ff14;
      uVar6 = BowserProbeAndCopyBuffer(param_2 + 0x14,local_2c0);
      uVar8 = uVar6 & 0xffffffff;
      if ((int)uVar6 < 0) goto LAB_14001ff14;
      lVar7 = BowserFindTransport(local_2b0,local_2c0);
      local_2c8 = lVar7;
      if (lVar7 == 0) {
        uVar8 = 0xc0000034;
        goto LAB_14001ff14;
      }
      if (*(short *)(*(longlong *)(lVar7 + 8) + 0x158) < 0) {
        uVar8 = 0xc00000bb;
        goto LAB_14001ff14;
      }
      if (*(short *)(*(longlong *)(lVar7 + 8) + 0x128) != 0) {
        puStack_2d0 = local_270;
        local_2d8 = 0x200000;
        uVar5 = RtlUpcaseUnicodeString(&local_2d8,&local_2a0);
        uVar8 = (ulonglong)uVar5;
        if ((int)uVar5 < 0) goto LAB_14001ff14;
        ExAcquireResourceExclusiveLite(lVar7 + 0xd0,1);
        param_3 = 0;
        cVar4 = RtlEqualUnicodeString(&local_2d8,*(longlong *)(lVar7 + 8) + 0x128);
        if (cVar4 == '\0') {
          RtlCopyUnicodeString(&local_2d8,*(longlong *)(lVar7 + 8) + 0x128);
          ExReleaseResourceLite(lVar7 + 0xd0);
          uVar2 = (ushort)local_2d8;
          if (uVar9 < (ulonglong)((ushort)local_2d8 + 0x3c) + 6) {
            uVar8 = 0xc0000023;
          }
          else {
            *puVar1 = 0x5c;
            param_2[0x1f] = 0x5c;
            memcpy(param_2 + 0x20,puStack_2d0,local_2d8 & 0xffff);
            *(uint *)(param_2 + 0x1c) = uVar2 + 4;
            param_2[(ulonglong)(uVar2 >> 1) + 0x20] = 0;
            *(ulonglong *)(param_1 + 0x38) = (ulonglong)((ushort)local_2d8 + 0x3c) + 6;
            uVar8 = 0;
          }
          goto LAB_14001ff14;
        }
        ExReleaseResourceLite(lVar7 + 0xd0);
      }
      if (0x41 < *(uint *)(lVar3 + 8)) {
        uVar8 = BowserQueueNonBufferRequest(param_1,(longlong *)(lVar7 + 0x3c8),param_3,'\0');
        uVar8 = uVar8 & 0xffffffff;
        goto LAB_14001ff14;
      }
    }
  }
  uVar8 = 0xc000000d;
LAB_14001ff14:
  if (lVar7 != 0) {
    BowserDereferenceTransport(lVar7);
  }
  return uVar8;
}



===== BowserEnumTransports @ 14001ff58 =====

uint BowserEnumTransports
               (undefined8 param_1,undefined8 param_2,int *param_3,uint *param_4,undefined4 *param_5
               ,uint param_6,undefined8 param_7)

{
  uint uVar1;
  
  if (((*param_4 < 0x60) || (param_3[1] != 7)) || (*param_3 != 2)) {
    uVar1 = 0xc000000d;
  }
  else if (param_6 < 0x10) {
    uVar1 = 0xc0000023;
  }
  else {
    uVar1 = BowserEnumerateTransports
                      (param_5,param_6,param_3 + 0xe,param_3 + 0xf,param_3 + 0x10,param_7);
    *param_4 = 0x60;
  }
  return uVar1;
}



===== StartProcessingAnnouncements @ 14001ffd0 =====

undefined8 StartProcessingAnnouncements(longlong param_1)

{
  if (((*(char *)(param_1 + 4) == '\x02') || ((byte)(*(char *)(param_1 + 4) - 4U) < 4)) &&
     (*(char *)(param_1 + 5) == '\0')) {
    BowserReferenceDiscardableCode(3);
    *(undefined1 *)(param_1 + 5) = 1;
  }
  return 0;
}



===== EnumerateTransportsWorker @ 140020010 =====

undefined8 EnumerateTransportsWorker(longlong param_1,longlong *param_2)

{
  char cVar1;
  ushort uVar2;
  short sVar3;
  longlong lVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  lVar4 = *(longlong *)(param_1 + 8);
  puVar5 = (uint *)*param_2;
  uVar2 = *(ushort *)(lVar4 + 0x30);
  *(int *)(param_2 + 4) = (int)param_2[4] + 1;
  uVar8 = uVar2 + 0x15 & 0xfffffffc;
  if ((ulonglong)uVar8 < (ulonglong)(param_2[1] - (longlong)puVar5)) {
    *(int *)((longlong)param_2 + 0x1c) = *(int *)((longlong)param_2 + 0x1c) + 1;
    param_2[2] = (longlong)puVar5;
    memcpy(puVar5 + 3,*(void **)(lVar4 + 0x38),(ulonglong)*(ushort *)(lVar4 + 0x30) + 2);
    *(undefined2 *)((longlong)puVar5 + (ulonglong)(*(ushort *)(lVar4 + 0x30) >> 1) * 2 + 0xc) = 0;
    puVar5[1] = (uint)*(ushort *)(lVar4 + 0x30);
    sVar3 = *(short *)(lVar4 + 0x158);
    uVar6 = (uint)(*(char *)(lVar4 + 0x15a) != '\0');
    uVar7 = uVar6 | 8;
    if (*(char *)(lVar4 + 0x15c) == '\0') {
      uVar7 = uVar6;
    }
    cVar1 = *(char *)(lVar4 + 0x15b);
    *puVar5 = uVar8;
    uVar6 = uVar7 | 2;
    if (cVar1 == '\0') {
      uVar6 = uVar7;
    }
    uVar7 = uVar6 | 4;
    if (-1 < sVar3) {
      uVar7 = uVar6;
    }
    puVar5[2] = puVar5[2] | uVar7;
    *param_2 = *param_2 + (ulonglong)uVar8;
  }
  *(int *)((longlong)param_2 + 0x24) = *(int *)((longlong)param_2 + 0x24) + uVar8;
  return 0;
}



===== BowserFsdQueryInformationFile @ 1400200fc =====

undefined8 BowserFsdQueryInformationFile(undefined8 param_1,longlong param_2)

{
  IoIsOperationSynchronous(param_2);
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0xc0000002;
  IofCompleteRequest(param_2,0);
  return 0xc0000002;
}



===== GetMasterName @ 140020144 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong GetMasterName(longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4,
                       uint param_5)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined1 auStack_2a8 [32];
  longlong local_288;
  ushort local_280 [4];
  undefined1 *local_278;
  byte local_270 [8];
  undefined1 *local_268;
  undefined1 local_260 [40];
  undefined1 local_238 [528];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_2a8;
  lVar4 = 0;
  local_288 = 0;
  local_270[0] = 0;
  local_270[1] = 0;
  local_270[2] = 10;
  local_270[3] = 2;
  local_270[4] = 0;
  local_270[5] = 0;
  local_270[6] = 0;
  local_270[7] = 0;
  local_268 = local_238;
  local_280[0] = 0;
  local_280[1] = 0x20;
  local_280[2] = 0;
  local_280[3] = 0;
  local_278 = local_260;
  if ((*(uint *)(*(longlong *)(param_1 + 0xb8) + 8) < 0x42) || (param_5 < 0x60)) {
    uVar5 = 0xc000000d;
  }
  else {
    uVar3 = BowserProbeAndCopyBuffer((ushort *)(param_4 + 0x18),(undefined2 *)local_270);
    uVar5 = uVar3 & 0xffffffff;
    if (-1 < (int)uVar3) {
      uVar3 = BowserProbeAndCopyBuffer((ushort *)(param_4 + 0x28),local_280);
      uVar5 = uVar3 & 0xffffffff;
      if (-1 < (int)uVar3) {
        lVar4 = BowserFindTransport(local_270,local_280);
        local_288 = lVar4;
        if (lVar4 == 0) {
          uVar5 = 0xc0000034;
        }
        else {
          lVar1 = *(longlong *)(lVar4 + 8);
          *(undefined4 *)(lVar1 + 0x100) = 4;
          uVar3 = BowserQueueNonBufferRequest(param_1,(longlong *)(lVar4 + 0x398),param_3,'\x01');
          uVar5 = uVar3 & 0xffffffff;
          if (-1 < (int)uVar3) {
            uVar2 = BowserFindMaster(lVar4);
            if ((int)uVar2 < 0) {
              BowserCompleteFindMasterRequests(lVar4,(ushort *)(lVar1 + 0x128),uVar2);
            }
            uVar5 = 0x103;
          }
        }
      }
    }
  }
  if (lVar4 != 0) {
    BowserDereferenceTransport(lVar4);
  }
  return uVar5;
}



===== BowserFreeBrowserServerList @ 14002029c =====

void BowserFreeBrowserServerList(undefined8 *param_1,uint param_2)

{
  undefined8 *puVar1;
  ulonglong uVar2;
  
  if (param_2 != 0) {
    uVar2 = (ulonglong)param_2;
    puVar1 = param_1;
    do {
      ExFreePoolWithTag(*puVar1,0);
      puVar1 = puVar1 + 1;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  ExFreePoolWithTag(param_1,0);
  return;
}



===== BowserInitializeIrpQueue @ 1400202fc =====

void BowserInitializeIrpQueue(longlong param_1)

{
  *(longlong *)(param_1 + 8) = param_1;
  *(longlong *)param_1 = param_1;
  return;
}



===== BecomeMaster @ 14002030c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong BecomeMaster(longlong param_1,longlong param_2,undefined8 param_3)

{
  ulonglong uVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined1 auStack_2a8 [32];
  longlong local_288;
  ushort local_280 [4];
  undefined1 *local_278;
  byte local_270 [8];
  undefined1 *local_268;
  undefined1 local_260 [40];
  undefined1 local_238 [528];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_2a8;
  lVar2 = 0;
  local_288 = 0;
  local_270[0] = 0;
  local_270[1] = 0;
  local_270[2] = 10;
  local_270[3] = 2;
  local_270[4] = 0;
  local_270[5] = 0;
  local_270[6] = 0;
  local_270[7] = 0;
  local_268 = local_238;
  local_280[0] = 0;
  local_280[1] = 0x20;
  local_280[2] = 0;
  local_280[3] = 0;
  local_278 = local_260;
  if ((uint)param_3 < 0x60) {
    uVar3 = 0xc000000d;
  }
  else {
    uVar1 = BowserProbeAndCopyBuffer((ushort *)(param_2 + 0x18),(undefined2 *)local_270);
    uVar3 = uVar1 & 0xffffffff;
    if (-1 < (int)uVar1) {
      uVar1 = BowserProbeAndCopyBuffer((ushort *)(param_2 + 0x28),local_280);
      uVar3 = uVar1 & 0xffffffff;
      if (-1 < (int)uVar1) {
        lVar2 = BowserFindTransport(local_270,local_280);
        local_288 = lVar2;
        if (lVar2 == 0) {
          uVar3 = 0xc0000034;
        }
        else {
          ExAcquireResourceExclusiveLite(lVar2 + 0xd0,1);
          if (*(int *)(lVar2 + 0x60) == 3) {
            *(undefined4 *)(lVar2 + 0x60) = 0;
          }
          ExReleaseResourceLite(lVar2 + 0xd0);
          uVar3 = BowserQueueNonBufferRequest(param_1,(longlong *)(lVar2 + 0x388),param_3,'\0');
          uVar3 = uVar3 & 0xffffffff;
        }
      }
    }
  }
  if (lVar2 != 0) {
    BowserDereferenceTransport(lVar2);
  }
  return uVar3;
}



===== BowserCheckForPrimaryBrowserServer @ 140020450 =====

undefined8 BowserCheckForPrimaryBrowserServer(longlong param_1,wchar_t *param_2)

{
  undefined8 *puVar1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  
  cVar2 = ExAcquireResourceSharedLite(param_1 + 0x2f8,0);
  uVar4 = 0;
  if (cVar2 == '\0') {
    uVar4 = 0;
  }
  else {
    puVar1 = *(undefined8 **)(*(longlong *)(param_1 + 8) + 0x148);
    if (puVar1 != (undefined8 *)0x0) {
      iVar3 = _wcsicmp(param_2,(wchar_t *)*puVar1);
      if (iVar3 == 0) {
        uVar4 = 0xc0000001;
      }
    }
    ExReleaseResourceLite(param_1 + 0x2f8);
  }
  return uVar4;
}



===== BowserEnumerateTransports @ 1400204e4 =====

uint BowserEnumerateTransports
               (undefined4 *param_1,uint param_2,int *param_3,int *param_4,undefined4 *param_5,
               undefined8 param_6)

{
  int iVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined4 *local_38;
  longlong lStack_30;
  undefined4 *local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  lStack_30 = (ulonglong)param_2 + (longlong)param_1;
  uStack_20 = (ulonglong)param_2;
  uStack_10 = param_6;
  local_38 = param_1;
  local_28 = param_1;
  puVar3 = BowserFindDomain((ushort *)0x0);
  if (puVar3 != (undefined8 *)0x0) {
    BowserForEachTransportInDomain((longlong)puVar3,EnumerateTransportsWorker,&local_38);
  }
  *param_3 = uStack_20._4_4_;
  *param_4 = (int)local_18;
  *param_5 = local_18._4_4_;
  if (*param_3 != 0) {
    *local_28 = 0;
  }
  iVar1 = *param_4;
  iVar2 = *param_3;
  if (puVar3 != (undefined8 *)0x0) {
    BowserDereferenceDomain(puVar3);
  }
  return -(uint)(iVar2 != iVar1) & 0x105;
}



===== BowserFreeAnnouncement @ 1400205d0 =====

void BowserFreeAnnouncement(undefined8 param_1,undefined8 param_2)

{
  ExFreePoolWithTag(param_2,0);
  return;
}



===== BowserPrimeDomainTableWithOtherDomains @ 140020600 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 BowserPrimeDomainTableWithOtherDomains(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 auStack_118 [32];
  char local_f8 [16];
  undefined2 local_e8;
  short local_e6;
  undefined4 local_e4;
  undefined4 local_e0;
  longlong local_c8;
  undefined2 local_be [17];
  undefined4 local_9c;
  undefined4 local_98;
  undefined2 local_8c [50];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_118;
  if (*(char *)(param_1 + 4) == '\x04') {
    lVar1 = *(longlong *)(param_1 + 0x18);
    lVar3 = *(longlong *)(lVar1 + 8);
    local_f8[0] = '\0';
    memset(&local_e4,0,0xbc);
    lVar2 = *(longlong *)(param_1 + 0x10);
    local_e8 = 5;
    local_e6 = *(short *)(*(longlong *)(lVar1 + 0x38) + 0x88) + 0x60;
    memcpy(local_be,*(void **)(*(longlong *)(lVar2 + 0x10) + 0x30),
           (ulonglong)*(ushort *)(*(longlong *)(lVar2 + 0x10) + 0x28));
    local_be[*(ushort *)(*(longlong *)(lVar2 + 0x10) + 0x28) >> 1] = 0;
    memcpy(local_8c,*(void **)(*(longlong *)(lVar1 + 0x38) + 0x90),
           (ulonglong)*(ushort *)(*(longlong *)(lVar1 + 0x38) + 0x88));
    local_8c[*(ushort *)(*(longlong *)(lVar1 + 0x38) + 0x88) >> 1] = 0;
    local_e4 = 0xffffffff;
    local_9c = 0x80000000;
    local_98 = 0xffff0002;
    local_e0 = 0;
    local_c8 = *(longlong *)(lVar2 + 0x10);
    ExAcquireResourceExclusiveLite(lVar1 + 0x68,1);
    lVar3 = RtlInsertElementGenericTable(lVar3 + 0x90,&local_e8,(int)local_e6,local_f8);
    if ((lVar3 != 0) && (local_f8[0] != '\0')) {
      BowserReferenceName(local_c8);
    }
    ExReleaseResourceLite(lVar1 + 0x68);
  }
  return 0;
}



===== AgeServerAnnouncements$fin$0 @ 140020780 =====

void AgeServerAnnouncements_fin_0(undefined8 param_1,longlong param_2)

{
  ExReleaseResourceLite(*(longlong *)(param_2 + 0xa0) + 0x68);
  return;
}



===== EnumerateServersWorker$fin$0 @ 1400207ae =====

void EnumerateServersWorker_fin_0(undefined8 param_1,longlong param_2)

{
  ExReleaseResourceLite(*(longlong *)(param_2 + 0x80) + 0x68);
  return;
}



===== BowserGetBackupListWorker$fin$0 @ 1400207e0 =====

void BowserGetBackupListWorker_fin_0(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  
  if (*(longlong *)(param_2 + 0x68) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x68),0);
  }
  lVar1 = *(longlong *)(param_2 + 0xa8);
  ExReleaseResourceLite(lVar1 + 0x68);
  ExReleaseResourceLite(lVar1 + 0xd0);
  lVar2 = *(longlong *)(param_2 + 0xb0);
  BowserDereferenceTransportName(*(longlong *)(lVar2 + 0x20));
  BowserDereferenceTransport(lVar1);
  LOCK();
  BowserPostedDatagramCount = BowserPostedDatagramCount + -1;
  UNLOCK();
  ExFreePoolWithTag(lVar2,0);
  return;
}



===== BowserBecomeBackupWorker$fin$0 @ 140020870 =====

void BowserBecomeBackupWorker_fin_0(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *(longlong *)(param_2 + 0x88);
  ExReleaseResourceLite(lVar1 + 0xd0);
  lVar2 = *(longlong *)(param_2 + 0x80);
  BowserDereferenceTransportName(*(longlong *)(lVar2 + 0x20));
  BowserDereferenceTransport(lVar1);
  if (*(longlong *)(param_2 + 0x38) != 0) {
    RtlFreeUnicodeString(param_2 + 0x30);
  }
  LOCK();
  BowserPostedDatagramCount = BowserPostedDatagramCount + -1;
  UNLOCK();
  ExFreePoolWithTag(lVar2,0);
  return;
}



===== UnbindFromTransport$fin$0 @ 1400208f0 =====

void UnbindFromTransport_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(char *)(param_2 + 0x20) != '\0') {
    KeUnstackDetachProcess(param_2 + 0x38);
  }
  return;
}



===== GetBrowserServerList$fin$0 @ 140020920 =====

void GetBrowserServerList_fin_0(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_2 + 0x60);
  if (lVar1 != 0) {
    if (*(char *)(param_2 + 0x30) != '\0') {
      ExReleaseResourceLite(lVar1 + 0x2f8);
    }
    BowserDereferenceTransport(lVar1);
  }
  if (((-1 < *(int *)(param_2 + 0x34)) && (*(char *)(param_2 + 0x31) == '\0')) &&
     (*(undefined8 **)(param_2 + 0x40) != (undefined8 *)0x0)) {
    BowserFreeBrowserServerList(*(undefined8 **)(param_2 + 0x40),*(uint *)(param_2 + 0x3c));
  }
  return;
}



===== BowserProcessDomainAnnouncement$fin$0 @ 140020990 =====

void BowserProcessDomainAnnouncement_fin_0(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_2 + 0x50);
  ExReleaseResourceLite(lVar1 + 0x68);
  BowserDereferenceTransportName(*(longlong *)(param_2 + 0x58));
  BowserDereferenceTransport(lVar1);
  return;
}



===== HandleElectionWorker$fin$0 @ 1400209d0 =====

void HandleElectionWorker_fin_0(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_2 + 0x98);
  ExReleaseResourceLite(lVar1 + 0xd0);
  LOCK();
  BowserPostedCriticalDatagramCount = BowserPostedCriticalDatagramCount + -1;
  UNLOCK();
  ExFreePoolWithTag(*(undefined8 *)(param_2 + 0xa0),0);
  if (*(longlong *)(param_2 + 0x48) != 0) {
    RtlFreeUnicodeString(param_2 + 0x40);
  }
  BowserDereferenceTransportName(*(longlong *)(param_2 + 0xa8));
  BowserDereferenceTransport(lVar1);
  return;
}



===== BowserBindToTransport$fin$0 @ 140020a50 =====

void BowserBindToTransport_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(char *)(param_2 + 0x20) != '\0') {
    KeUnstackDetachProcess(param_2 + 0x70);
  }
  return;
}



===== BowserCreateDomain$fin$0 @ 140020a80 =====

void BowserCreateDomain_fin_0(undefined8 param_1,longlong param_2)

{
  if ((*(int *)(param_2 + 0x30) < 0) && (*(undefined8 **)(param_2 + 0x38) != (undefined8 *)0x0)) {
    BowserDereferenceDomain(*(undefined8 **)(param_2 + 0x38));
    *(undefined8 *)(param_2 + 0x38) = 0;
  }
  ExReleaseResourceLite(&BowserTransportDatabaseResource);
  return;
}



===== BowserFindTransport$fin$0 @ 140020ad0 =====

void BowserFindTransport_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(undefined8 **)(param_2 + 0x20) != (undefined8 *)0x0) {
    BowserDereferenceDomain(*(undefined8 **)(param_2 + 0x20));
  }
  ExReleaseResourceLite(&BowserTransportDatabaseResource);
  return;
}



===== BowserFindDomain$fin$0 @ 140020b10 =====

void BowserFindDomain_fin_0(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_2 + 0x38);
  if (lVar1 != 0) {
    *(int *)(lVar1 + 0xb8) = *(int *)(lVar1 + 0xb8) + 1;
  }
  ExReleaseResourceLite(&BowserTransportDatabaseResource);
  return;
}



===== BowserSetDomainName$fin$0 @ 140020b60 =====

void BowserSetDomainName_fin_0(void)

{
  ExReleaseResourceLite(&BowserTransportDatabaseResource);
  return;
}



===== BowserProcessHostAnnouncement$fin$0 @ 140020b90 =====

void BowserProcessHostAnnouncement_fin_0(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_2 + 0x48);
  ExReleaseResourceLite(lVar1 + 0x68);
  BowserDereferenceTransportName(*(longlong *)(param_2 + 0x60));
  BowserDereferenceTransport(lVar1);
  return;
}



===== BowserGetBrowserServerList$fin$0 @ 140020bd0 =====

void BowserGetBrowserServerList_fin_0(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  uint *puVar2;
  uint uVar3;
  ulonglong uVar4;
  
  if (*(int *)(param_2 + 0x40) < 0) {
    plVar1 = *(longlong **)(param_2 + 0x90);
    puVar2 = *(uint **)(param_2 + 0x80);
    if (*plVar1 != 0) {
      uVar4 = 0;
      *(undefined4 *)(param_2 + 0x44) = 0;
      if (*puVar2 != 0) {
        do {
          if (*(longlong *)(*plVar1 + uVar4 * 8) != 0) {
            ExFreePoolWithTag(*(undefined8 *)(*plVar1 + uVar4 * 8),0);
          }
          uVar3 = (int)uVar4 + 1;
          uVar4 = (ulonglong)uVar3;
        } while (uVar3 < *puVar2);
        *(uint *)(param_2 + 0x44) = uVar3;
      }
      ExFreePoolWithTag(*plVar1,0);
      *plVar1 = 0;
    }
    *puVar2 = 0;
    BowserFreeTransportBackupList(*(longlong *)(param_2 + 0x98));
  }
  if (*(longlong *)(param_2 + 0x88) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x88),0);
  }
  RdrDereferenceDiscardableCode(3);
  return;
}



===== BowserOpenNetbiosAddress$fin$0 @ 140020c90 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void BowserOpenNetbiosAddress_fin_0(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  if (*(longlong *)(param_2 + 0x78) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x78),0);
  }
  if (*(longlong *)(param_2 + 0x130) != 0) {
    ObfDereferenceObject();
  }
  if (*(longlong *)(param_2 + 0x148) != 0) {
    ZwClose();
  }
  if (*(int *)(param_2 + 0x74) < 0) {
    lVar1 = *(longlong *)(param_2 + 0x80);
    if (*(char *)(lVar1 + 4) == '\x06') {
      if (DAT_14000d888 < 5) {
        *(int *)(&DAT_14000d890 + (ulonglong)DAT_14000d888 * 4) = *(int *)(param_2 + 0x74);
      }
      DAT_14000d888 = DAT_14000d888 + 1;
    }
    BowserCloseNetbiosAddress(lVar1);
  }
  else if (*(char *)(*(longlong *)(param_2 + 0x80) + 4) == '\x06') {
    _BrOneD = _BrOneD + 1;
  }
  if (*(char *)(param_2 + 0x70) != '\0') {
    ExReleaseRundownProtection(*(longlong *)(param_2 + 0x138) + 0x3f0);
  }
  return;
}



===== BowserFindMaster$fin$0 @ 140020d60 =====

void BowserFindMaster_fin_0(undefined8 param_1,longlong param_2)

{
  ExReleaseResourceLite(*(longlong *)(param_2 + 0x88) + 0xd0);
  return;
}



===== BowserElectMaster$fin$0 @ 140020da0 =====

void BowserElectMaster_fin_0(undefined8 param_1,longlong param_2)

{
  ExReleaseResourceLite(*(longlong *)(param_2 + 0x88) + 0xd0);
  return;
}



===== UpdateStatus$fin$0 @ 140020de0 =====

void UpdateStatus_fin_0(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_2 + 0x30);
  if (*(char *)(param_2 + 0x20) != '\0') {
    ExReleaseResourceLite(lVar1 + 0xd0);
  }
  if (lVar1 != 0) {
    BowserDereferenceTransport(lVar1);
  }
  if (*(char *)(param_2 + 0x28) != '\0') {
    KeUnstackDetachProcess(param_2 + 0x38);
  }
  return;
}



===== BowserBecomeMaster$fin$0 @ 140020e3b =====

void BowserBecomeMaster_fin_0(undefined8 param_1,longlong param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  
  if (*(int *)(param_2 + 0x20) < 0) {
    lVar2 = *(longlong *)(param_2 + 0x58);
    *(undefined4 *)(lVar2 + 0xf8) = 1;
    *(undefined4 *)(lVar2 + 0x100) = 4;
    uVar1 = BowserTimeUp();
    *(int *)(lVar2 + 0x10c) = (int)uVar1;
    lVar2 = *(longlong *)(param_2 + 0x50);
    *(undefined4 *)(lVar2 + 0x60) = 0;
    BowserForEachTransportName(lVar2,BowserStopProcessingAnnouncements,0);
    BowserStopTimer(lVar2 + 0x138);
    BowserDeleteTransportNameByName(lVar2,(short *)0x0,6);
    BowserDeleteTransportNameByName(lVar2,(short *)0x0,5);
    RdrDereferenceDiscardableCode(3);
  }
  else {
    lVar2 = *(longlong *)(param_2 + 0x50);
  }
  ExReleaseResourceLite(lVar2 + 0xd0);
  return;
}



===== BowserProcessMasterAnnouncement$fin$0 @ 140020ef0 =====

void BowserProcessMasterAnnouncement_fin_0(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_2 + 0x58);
  ExReleaseResourceLite(lVar1 + 0xd0);
  BowserDereferenceTransport(lVar1);
  LOCK();
  BowserPostedDatagramCount = BowserPostedDatagramCount + -1;
  UNLOCK();
  ExFreePoolWithTag(*(undefined8 *)(param_2 + 0x70),0);
  return;
}



===== BowserForEachTransportName$fin$0 @ 140020f50 =====

void BowserForEachTransportName_fin_0(void)

{
  ExReleaseResourceLite(&BowserTransportDatabaseResource);
  return;
}



===== BowserStartElection$fin$0 @ 140020f7a =====

void BowserStartElection_fin_0(undefined8 param_1,longlong param_2)

{
  ExReleaseResourceLite(*(longlong *)(param_2 + 0x30) + 0xd0);
  return;
}



===== BowserNewMaster$fin$0 @ 140020fa8 =====

void BowserNewMaster_fin_0(undefined8 param_1,longlong param_2)

{
  ExReleaseResourceLite(*(longlong *)(param_2 + 0x40) + 0xd0);
  return;
}



===== BowserCommonDeviceIoControlFile$fin$0 @ 140020fe0 =====

void BowserCommonDeviceIoControlFile_fin_0(undefined8 param_1,longlong param_2)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  longlong lVar4;
  
  if (*(longlong *)(param_2 + 0x78) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x78),0);
  }
  uVar2 = *(uint *)(param_2 + 0x40);
  if (uVar2 == 0x103) {
    iVar1 = *(int *)(param_2 + 0x60);
    if (*(int *)(param_2 + 0x70) == 0) {
      if ((iVar1 - 0x130034U < 0x33) &&
         ((0x4000110010111U >> ((ulonglong)(iVar1 - 0x130034U) & 0x3f) & 1) != 0)) {
        return;
      }
      if (iVar1 == 0x13008e) {
        return;
      }
    }
    if (iVar1 == 0x130097) {
      *(undefined4 *)(param_2 + 0x40) = 0;
      lVar4 = *(longlong *)(param_2 + 0xe8);
      *(undefined4 *)(lVar4 + 0x30) = 0;
    }
    else {
      lVar4 = *(longlong *)(param_2 + 0xe8);
      uVar3 = BowserFsdPostToFsp(*(undefined8 *)(param_2 + 0xe0),lVar4);
      uVar2 = (uint)uVar3;
      *(uint *)(param_2 + 0x40) = uVar2;
      if (uVar2 == 0x103) {
        return;
      }
      *(uint *)(lVar4 + 0x30) = uVar2;
      if ((uVar2 & 0xc0000000) == 0xc0000000) {
        *(undefined8 *)(lVar4 + 0x38) = 0;
      }
    }
  }
  else {
    lVar4 = *(longlong *)(param_2 + 0xe8);
    *(uint *)(lVar4 + 0x30) = uVar2;
    if ((uVar2 & 0xc0000000) == 0xc0000000) {
      *(undefined8 *)(lVar4 + 0x38) = 0;
    }
  }
  IofCompleteRequest(lVar4,0);
  return;
}



===== BowserFindTransportName$fin$0 @ 1400210e0 =====

void BowserFindTransportName_fin_0(void)

{
  ExReleaseResourceLite(&BowserTransportDatabaseResource);
  return;
}



===== WriteMailslotEx$fin$0 @ 140021110 =====

void WriteMailslotEx_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x40) != 0) {
    BowserDereferenceTransport(*(longlong *)(param_2 + 0x40));
  }
  return;
}



===== WaitForBrowserRoleChange$fin$0 @ 140021140 =====

void WaitForBrowserRoleChange_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x20) != 0) {
    BowserDereferenceTransport(*(longlong *)(param_2 + 0x20));
  }
  return;
}



===== EnumNames$fin$0 @ 140021170 =====

void EnumNames_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(undefined8 **)(param_2 + 0x40) != (undefined8 *)0x0) {
    BowserDereferenceDomain(*(undefined8 **)(param_2 + 0x40));
  }
  if (*(longlong *)(param_2 + 0x48) != 0) {
    BowserDereferenceTransport(*(longlong *)(param_2 + 0x48));
  }
  return;
}



===== HandleBecomeBackup$fin$0 @ 1400211b0 =====

void HandleBecomeBackup_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x20) != 0) {
    BowserDereferenceTransport(*(longlong *)(param_2 + 0x20));
  }
  return;
}



===== WaitForNewMaster$fin$0 @ 1400211d5 =====

void WaitForNewMaster_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x30) != 0) {
    BowserDereferenceTransport(*(longlong *)(param_2 + 0x30));
  }
  return;
}



===== GetMasterName$fin$0 @ 1400211fa =====

void GetMasterName_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x20) != 0) {
    BowserDereferenceTransport(*(longlong *)(param_2 + 0x20));
  }
  return;
}



===== BecomeMaster$fin$0 @ 14002121f =====

void BecomeMaster_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x20) != 0) {
    BowserDereferenceTransport(*(longlong *)(param_2 + 0x20));
  }
  return;
}



===== BowserEnumerateTransports$fin$0 @ 140021244 =====

void BowserEnumerateTransports_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(undefined8 **)(param_2 + 0x28) != (undefined8 *)0x0) {
    BowserDereferenceDomain(*(undefined8 **)(param_2 + 0x28));
  }
  return;
}



===== BowserDeleteTransportNameByName$fin$0 @ 140021269 =====

void BowserDeleteTransportNameByName_fin_0(void)

{
  ExReleaseResourceLite(&BowserTransportDatabaseResource);
  return;
}



===== AddBowserName$fin$0 @ 140021293 =====

void AddBowserName_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x28) != 0) {
    BowserDereferenceTransport(*(longlong *)(param_2 + 0x28));
  }
  if (*(undefined8 **)(param_2 + 0x30) != (undefined8 *)0x0) {
    BowserDereferenceDomain(*(undefined8 **)(param_2 + 0x30));
  }
  if (*(char *)(param_2 + 0x20) != '\0') {
    KeUnstackDetachProcess(param_2 + 0x48);
  }
  return;
}



===== BowserRenameDomain$fin$0 @ 1400212de =====

void BowserRenameDomain_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(undefined8 **)(param_2 + 0x48) != (undefined8 *)0x0) {
    BowserDereferenceDomain(*(undefined8 **)(param_2 + 0x48));
  }
  return;
}



===== DeleteName$fin$0 @ 140021303 =====

void DeleteName_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(undefined8 **)(param_2 + 0x38) != (undefined8 *)0x0) {
    BowserDereferenceDomain(*(undefined8 **)(param_2 + 0x38));
  }
  if (*(char *)(param_2 + 0x20) != '\0') {
    KeUnstackDetachProcess(param_2 + 0x40);
  }
  return;
}



===== EnumServers$fin$0 @ 14002133f =====

void EnumServers_fin_0(void)

{
  return;
}



===== StartBowser$fin$0 @ 140021355 =====

void StartBowser_fin_0(void)

{
  ExReleaseResourceLite(&BowserDataResource);
  return;
}



===== WaitForMasterAnnounce$fin$0 @ 14002137f =====

void WaitForMasterAnnounce_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x20) != 0) {
    BowserDereferenceTransport(*(longlong *)(param_2 + 0x20));
  }
  return;
}



===== BowserProcessMailslotWrite$fin$0 @ 1400213a4 =====

void BowserProcessMailslotWrite_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x60) != 0) {
    ZwClose();
  }
  BowserFreeMailslotBuffer(*(longlong *)(param_2 + 0x88));
  return;
}



===== BowserGetBackupServerListFromTransport @ 140022008 =====

undefined8 BowserGetBackupServerListFromTransport(longlong param_1)

{
  undefined8 uVar1;
  undefined1 uVar2;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(&BowserBackupListSpinLock);
  uVar1 = *(undefined8 *)(param_1 + 0x58);
  *(undefined8 *)(param_1 + 0x58) = 0;
  KeReleaseSpinLock(&BowserBackupListSpinLock,uVar2);
  return uVar1;
}



===== BowserHandleIpxDomainAnnouncement @ 14002205c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
BowserHandleIpxDomainAnnouncement
          (longlong param_1,longlong param_2,longlong param_3,undefined8 param_4,uint param_5)

{
  longlong *plVar1;
  undefined8 uVar2;
  
  LOCK();
  _DAT_14000d2c0 = _DAT_14000d2c0 + 1;
  UNLOCK();
  plVar1 = BowserAllocateViewBuffer();
  if (plVar1 == (longlong *)0x0) {
    uVar2 = 0xc00000d0;
  }
  else {
    BowserCopyOemComputerName
              ((undefined1 *)((longlong)plVar1 + 0x31),(void *)(param_2 + 0x24),0x10,param_5);
    BowserCopyOemComputerName
              ((undefined1 *)((longlong)plVar1 + 0x4c),(void *)(param_2 + 0x34),0x10,param_5);
    *(uint *)(plVar1 + 9) = *(uint *)(param_3 + 0x17) & 0x1000 | 0x80000000;
    plVar1[5] = *(longlong *)(param_1 + 0x28);
    *(undefined1 *)((longlong)plVar1 + 0x44) = *(undefined1 *)(param_3 + 0x15);
    *(undefined1 *)((longlong)plVar1 + 0x45) = *(undefined1 *)(param_3 + 0x16);
    *(short *)((longlong)plVar1 + 0x46) = (short)((ulonglong)(*(int *)(param_3 + 1) + 999) / 1000);
    BowserReferenceTransportName(*(longlong *)(param_1 + 0x28));
    BowserReferenceTransport(param_1);
    plVar1[1] = 0;
    plVar1[3] = (longlong)BowserProcessDomainAnnouncement;
    plVar1[4] = (longlong)plVar1;
    BowserQueueDelayedWorkItem(plVar1 + 1);
    uVar2 = 0;
  }
  return uVar2;
}



===== QueryStatistics @ 140022150 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 QueryStatistics(undefined8 param_1,undefined8 *param_2,int *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  undefined8 uVar5;
  
  if (*param_3 == 0x50) {
    BowserReferenceDiscardableCode(3);
    uVar4 = KeAcquireSpinLockRaiseToDpc(&BowserStatisticsLock);
    uVar5 = _DAT_14000d2b8;
    *param_2 = _BowserStatistics;
    param_2[1] = uVar5;
    uVar5 = _DAT_14000d2c8;
    param_2[2] = _DAT_14000d2c0;
    param_2[3] = uVar5;
    uVar5 = _DAT_14000d2d8;
    param_2[4] = _DAT_14000d2d0;
    param_2[5] = uVar5;
    uVar3 = _DAT_14000d2ec;
    uVar2 = _DAT_14000d2e8;
    uVar1 = _DAT_14000d2e4;
    *(undefined4 *)(param_2 + 6) = _DAT_14000d2e0;
    *(undefined4 *)((longlong)param_2 + 0x34) = uVar1;
    *(undefined4 *)(param_2 + 7) = uVar2;
    *(undefined4 *)((longlong)param_2 + 0x3c) = uVar3;
    uVar3 = uRam000000014000d2fc;
    uVar2 = _DAT_14000d2f8;
    uVar1 = _DAT_14000d2f4;
    *(undefined4 *)(param_2 + 8) = _DAT_14000d2f0;
    *(undefined4 *)((longlong)param_2 + 0x44) = uVar1;
    *(undefined4 *)(param_2 + 9) = uVar2;
    *(undefined4 *)((longlong)param_2 + 0x4c) = uVar3;
    KeReleaseSpinLock(&BowserStatisticsLock,uVar4);
    RdrDereferenceDiscardableCode(3);
    uVar5 = 0;
  }
  else {
    *param_3 = 0;
    uVar5 = 0xc0000023;
  }
  return uVar5;
}



===== ResetStatistics @ 1400221ec =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 ResetStatistics(void)

{
  undefined1 uVar1;
  
  BowserReferenceDiscardableCode(3);
  uVar1 = KeAcquireSpinLockRaiseToDpc(&BowserStatisticsLock);
  memset(&BowserStatistics,0,0x50);
  _BowserStatistics = _DAT_fffff78000000014;
  KeReleaseSpinLock(&BowserStatisticsLock,uVar1);
  RdrDereferenceDiscardableCode(3);
  return 0;
}



===== BowserCancelQueuedIoForFile @ 140022270 =====

void BowserCancelQueuedIoForFile(longlong *param_1,longlong param_2,longlong *param_3)

{
  uint uVar1;
  longlong lVar2;
  code *pcVar3;
  undefined1 *puVar4;
  undefined1 uVar5;
  longlong *plVar6;
  longlong *plVar7;
  undefined1 *puVar8;
  longlong *plVar9;
  longlong *plVar10;
  undefined1 auStack_38 [32];
  undefined8 ***local_18;
  undefined8 ***local_10;
  
  plVar9 = param_3;
  BowserReferenceDiscardableCode(3);
  local_10 = &local_18;
  local_18 = &local_18;
  KeAcquireSpinLockRaiseToDpc(&BowserIrpQueueSpinLock);
  puVar8 = auStack_38;
  plVar7 = (longlong *)*param_1;
  puVar4 = auStack_38;
  plVar10 = plVar7;
  if (plVar7 != param_1) goto LAB_140022310;
LAB_1400222c7:
  if (param_3 != (longlong *)0x0) {
    if ((plVar10 == param_1) || ((longlong *)*param_1 != param_1)) {
      uVar5 = 0;
    }
    else {
      uVar5 = 1;
    }
    *(undefined1 *)param_3 = uVar5;
  }
  *(undefined8 *)(puVar8 + -8) = 0x1400222da;
  KeReleaseSpinLock(&BowserIrpQueueSpinLock);
  while( true ) {
    plVar7 = *(longlong **)(puVar8 + 0x20);
    if (plVar7 == (longlong *)(puVar8 + 0x20)) {
      *(undefined8 *)(puVar8 + -8) = 0x1400222fc;
      RdrDereferenceDiscardableCode(3);
      return;
    }
    if (((undefined1 *)plVar7[1] != puVar8 + 0x20) ||
       (lVar2 = *plVar7, *(longlong **)(lVar2 + 8) != plVar7)) break;
    *(longlong *)(puVar8 + 0x20) = lVar2;
    *(undefined1 **)(lVar2 + 8) = puVar8 + 0x20;
    uVar1 = *(uint *)(plVar7 + -0xf);
    *(uint *)(plVar7 + -0xf) = uVar1;
    if ((uVar1 & 0xc0000000) == 0xc0000000) {
      plVar7[-0xe] = 0;
    }
    *(undefined8 *)(puVar8 + -8) = 0x14002242d;
    IofCompleteRequest(plVar7 + -0x15,0);
  }
  do {
    do {
      do {
        plVar7 = (longlong *)0x3;
        pcVar3 = (code *)swi(0x29);
        (*pcVar3)();
        puVar8 = puVar8 + 8;
LAB_140022386:
        LOCK();
        lVar2 = plVar7[-8];
        plVar7[-8] = 0;
        UNLOCK();
        if (lVar2 == 0) goto LAB_14002231f;
        lVar2 = *plVar7;
      } while ((*(longlong **)(lVar2 + 8) != plVar7) ||
              (plVar6 = (longlong *)plVar7[1], (longlong *)*plVar6 != plVar7));
      *plVar6 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar6;
      plVar7[-0xe] = 0;
      *(undefined4 *)(plVar7 + -0xf) = 0xc0000128;
      plVar6 = *(longlong **)(puVar8 + 0x28);
    } while ((undefined1 *)*plVar6 != puVar8 + 0x20);
    do {
      plVar7[1] = (longlong)plVar6;
      *plVar7 = (longlong)(puVar8 + 0x20);
      *plVar6 = (longlong)plVar7;
      *(longlong **)(puVar8 + 0x28) = plVar7;
LAB_14002231f:
      do {
        while( true ) {
          plVar7 = plVar9;
          puVar4 = puVar8;
          plVar9 = plVar7;
          if (plVar7 == param_1) goto LAB_1400222c7;
LAB_140022310:
          puVar8 = puVar4;
          plVar9 = (longlong *)*plVar7;
          if (*(char *)((longlong)plVar7 + -100) != '\0') break;
          if (plVar7[3] == param_2) goto LAB_140022386;
        }
        LOCK();
        lVar2 = plVar7[-8];
        plVar7[-8] = 0;
        UNLOCK();
      } while (lVar2 == 0);
      lVar2 = *plVar7;
      if ((*(longlong **)(lVar2 + 8) != plVar7) ||
         (plVar6 = (longlong *)plVar7[1], (longlong *)*plVar6 != plVar7)) break;
      *plVar6 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar6;
      plVar7[-0xe] = 0;
      *(undefined4 *)(plVar7 + -0xf) = 0xc0000120;
      plVar6 = *(longlong **)(puVar8 + 0x28);
    } while ((undefined1 *)*plVar6 == puVar8 + 0x20);
  } while( true );
}



===== BowserUninitializeIrpQueue @ 140022440 =====

void BowserUninitializeIrpQueue(longlong *param_1,undefined1 *param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  code *pcVar4;
  undefined1 uVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  BowserReferenceDiscardableCode(3);
  uVar5 = KeAcquireSpinLockRaiseToDpc(&BowserIrpQueueSpinLock);
  puVar7 = auStack_28;
  plVar1 = (longlong *)*param_1;
  do {
    plVar2 = (longlong *)*param_1;
    if (plVar2 == param_1) {
      *param_1 = 0;
      param_1[1] = 0;
      KeReleaseSpinLock(&BowserIrpQueueSpinLock);
      puVar6 = auStack_28;
      if (param_2 != (undefined1 *)0x0) {
        if (plVar1 == param_1) {
          uVar5 = 0;
          puVar7 = auStack_28;
        }
        else {
LAB_140022563:
          uVar5 = 1;
        }
        *param_2 = uVar5;
        puVar6 = puVar7;
      }
      *(undefined8 *)(puVar6 + -8) = 0x1400224c4;
      RdrDereferenceDiscardableCode(3);
      return;
    }
    if (((longlong *)plVar2[1] != param_1) || (lVar3 = *plVar2, *(longlong **)(lVar3 + 8) != plVar2)
       ) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3,uVar5);
      puVar7 = auStack_20;
      goto LAB_140022563;
    }
    *param_1 = lVar3;
    *(longlong **)(lVar3 + 8) = param_1;
    plVar2[-0xe] = 0;
    *(undefined1 *)((longlong)plVar2 + -100) = 0;
    LOCK();
    lVar3 = plVar2[-8];
    plVar2[-8] = 0;
    UNLOCK();
    if (lVar3 != 0) {
      KeReleaseSpinLock(&BowserIrpQueueSpinLock);
      *(undefined4 *)(plVar2 + -0xf) = 0xc0000120;
      plVar2[-0xe] = 0;
      IofCompleteRequest(plVar2 + -0x15,0);
      uVar5 = KeAcquireSpinLockRaiseToDpc(&BowserIrpQueueSpinLock);
    }
  } while( true );
}



===== BowserTimerDispatcher @ 140022570 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void BowserTimerDispatcher(longlong param_1)

{
  longlong lVar1;
  code *pcVar2;
  undefined8 uVar3;
  undefined1 uVar4;
  
  BowserReferenceDiscardableCode(3);
  lVar1 = param_1 + 0x80;
  uVar4 = KeAcquireSpinLockRaiseToDpc(lVar1);
  if (*(char *)(param_1 + 0xd9) == '\0') {
    KeSetEvent(param_1 + 0x88,2);
    KeReleaseSpinLock(lVar1,uVar4);
    RdrDereferenceDiscardableCode(3);
  }
  else if (*(char *)(param_1 + 0xda) == '\0') {
    *(undefined1 *)(param_1 + 0xd8) = 0;
    pcVar2 = *(code **)(param_1 + 0xa0);
    uVar3 = *(undefined8 *)(param_1 + 0xa8);
    KeReleaseSpinLock(lVar1,uVar4);
    (*pcVar2)(uVar3);
    uVar4 = KeAcquireSpinLockRaiseToDpc(lVar1);
    if (*(char *)(param_1 + 0xd8) == '\0') {
      KeSetEvent(param_1 + 0x88,2);
    }
    KeReleaseSpinLock(lVar1,uVar4);
    RdrDereferenceDiscardableCode(3);
  }
  else {
    if (*(char *)(param_1 + 0xdb) == '\0') {
      *(undefined1 *)(param_1 + 0xd8) = 0;
      *(undefined1 *)(param_1 + 0xda) = 0;
      KeSetEvent(param_1 + 0x88,2);
    }
    else {
      *(undefined1 *)(param_1 + 0xdb) = 0;
      KeInitializeDpc(param_1,BowserTimerDpc,param_1);
      KeSetTimer(param_1 + 0x40,*(undefined8 *)(param_1 + 0xb0),param_1);
    }
    KeReleaseSpinLock(lVar1,uVar4);
    RdrDereferenceDiscardableCode(3);
  }
  return;
}



===== BowserCopyPnp @ 140022750 =====

undefined8
BowserCopyPnp(longlong param_1,undefined4 param_2,ushort *param_3,ushort *param_4,undefined4 param_5
             )

{
  longlong lVar1;
  undefined8 *puVar2;
  void *_Dst;
  undefined2 *puVar3;
  undefined8 uVar4;
  
  BowserReferenceDiscardableCode(3);
  if (*(uint *)(*(longlong *)(param_1 + 0xb8) + 8) < *param_4 + 0x35 + (uint)*param_3) {
    uVar4 = 0xc0000023;
  }
  else {
    lVar1 = *(longlong *)(param_1 + 8);
    uVar4 = 0;
    if ((*(byte *)(lVar1 + 10) & 5) == 0) {
      puVar2 = (undefined8 *)MmMapLockedPagesSpecifyCache(lVar1,0,1,0,0,0x40000010);
    }
    else {
      puVar2 = *(undefined8 **)(lVar1 + 0x18);
    }
    if (puVar2 == (undefined8 *)0x0) {
      uVar4 = 0xc0000017;
    }
    else if (((ulonglong)puVar2 & 3) == 0) {
      *puVar2 = 0;
      puVar2[1] = 0;
      puVar2[2] = 0;
      puVar2[3] = 0;
      puVar2[4] = 0;
      puVar2[5] = 0;
      *(undefined4 *)((longlong)puVar2 + 0xc) = param_2;
      *(undefined4 *)((longlong)puVar2 + 0x1c) = param_5;
      *(undefined1 *)(puVar2 + 6) = 0;
      _Dst = (void *)((longlong)puVar2 + 0x31U & 0xfffffffffffffffe);
      *(uint *)(puVar2 + 2) = (uint)*param_4;
      *(uint *)((longlong)puVar2 + 0x14) =
           ((uint)((longlong)puVar2 + 0x31U) & 0xfffffffe) - (int)puVar2;
      memcpy(_Dst,*(void **)(param_4 + 4),(ulonglong)*param_4);
      puVar3 = (undefined2 *)((longlong)_Dst + (ulonglong)*param_4);
      *puVar3 = 0;
      *(uint *)(puVar2 + 4) = (uint)*param_3;
      *(int *)((longlong)puVar2 + 0x24) = ((int)puVar3 + 2) - (int)puVar2;
      memcpy(puVar3 + 1,*(void **)(param_3 + 4),(ulonglong)*param_3);
      *(undefined2 *)((longlong)puVar3 + (ulonglong)*param_3 + 2) = 0;
    }
    else {
      uVar4 = 0xc000000d;
    }
  }
  RdrDereferenceDiscardableCode(3);
  return uVar4;
}



===== BowserStartTimer @ 1400228b0 =====

undefined1 BowserStartTimer(longlong param_1,uint param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uVar1;
  undefined1 uVar2;
  longlong lVar3;
  
  BowserReferenceDiscardableCode(3);
  lVar3 = (ulonglong)param_2 * -10000;
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x80);
  if (*(char *)(param_1 + 0xd9) != '\0') {
    if (*(char *)(param_1 + 0xd8) != '\x01') {
      *(longlong *)(param_1 + 0xb0) = lVar3;
      *(undefined8 *)(param_1 + 0xa0) = param_3;
      *(undefined8 *)(param_1 + 0xa8) = param_4;
      *(undefined1 *)(param_1 + 0xd8) = 1;
      *(undefined2 *)(param_1 + 0xda) = 0;
      KeResetEvent(param_1 + 0x88);
      KeInitializeDpc(param_1,BowserTimerDpc,param_1);
      uVar2 = KeSetTimer(param_1 + 0x40,lVar3,param_1);
      KeReleaseSpinLock(param_1 + 0x80,uVar1);
      RdrDereferenceDiscardableCode(3);
      return uVar2;
    }
    if (*(char *)(param_1 + 0xda) != '\0') {
      *(longlong *)(param_1 + 0xb0) = lVar3;
      *(undefined8 *)(param_1 + 0xa0) = param_3;
      *(undefined1 *)(param_1 + 0xdb) = 1;
      KeReleaseSpinLock(param_1 + 0x80,uVar1);
      RdrDereferenceDiscardableCode(3);
      return 1;
    }
  }
  KeReleaseSpinLock(param_1 + 0x80,uVar1);
  RdrDereferenceDiscardableCode(3);
  return 0;
}



===== BowserQueueNonBufferRequestReferenced @ 140022a30 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
BowserQueueNonBufferRequestReferenced
          (longlong param_1,longlong *param_2,undefined8 param_3,char param_4)

{
  byte *pbVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  code *pcVar5;
  undefined1 *puVar6;
  undefined1 uVar7;
  undefined1 *puVar8;
  undefined1 local_res18 [16];
  undefined8 uStack_40;
  undefined1 auStack_38 [32];
  
  uVar7 = KeAcquireSpinLockRaiseToDpc(&BowserIrpQueueSpinLock);
  puVar8 = auStack_38;
  if (*param_2 == 0) {
    KeReleaseSpinLock(&BowserIrpQueueSpinLock,uVar7);
    return 0xc0000120;
  }
  pbVar1 = (byte *)(*(longlong *)(param_1 + 0xb8) + 3);
  *pbVar1 = *pbVar1 | 1;
  puVar6 = auStack_38;
  if (param_4 != '\0') goto LAB_140022bd7;
  do {
    plVar3 = (longlong *)param_2[1];
    plVar2 = (longlong *)(param_1 + 0xa8);
    if ((longlong *)*plVar3 == param_2) {
      *(longlong **)(param_1 + 0xb0) = plVar3;
      *plVar2 = (longlong)param_2;
      *plVar3 = (longlong)plVar2;
      param_2[1] = (longlong)plVar2;
      lVar4 = *(longlong *)(param_1 + 0xb8);
      *(undefined8 *)(lVar4 + -0x40) = _DAT_fffff78000000320;
      *(longlong **)(lVar4 + -0x28) = param_2;
      *(undefined8 *)(puVar8 + -8) = 0x140022ad3;
      IoAcquireCancelSpinLock(puVar8 + 0x50);
      param_2 = (longlong *)0x1;
      if (*(char *)(param_1 + 0x44) == '\0') {
        LOCK();
        *(code **)(param_1 + 0x68) = BowserCancelQueuedRequest;
        UNLOCK();
        goto LAB_140022aee;
      }
      if (*(longlong *)(param_1 + 0x68) == 0) goto LAB_140022b86;
      lVar4 = *plVar2;
      if ((*(longlong **)(lVar4 + 8) == plVar2) &&
         (plVar3 = *(longlong **)(param_1 + 0xb0), (longlong *)*plVar3 == plVar2)) {
        *plVar3 = lVar4;
        *(longlong **)(lVar4 + 8) = plVar3;
        *(undefined8 *)(puVar8 + -8) = 0x140022b4c;
        IoReleaseCancelSpinLock(puVar8[0x50]);
        *(undefined8 *)(puVar8 + -8) = 0x140022b63;
        KeReleaseSpinLock(&BowserIrpQueueSpinLock,uVar7);
        param_2 = (longlong *)0x0;
        *(undefined4 *)(param_1 + 0x30) = 0xc0000120;
        *(undefined8 *)(param_1 + 0x38) = 0;
        *(undefined8 *)(puVar8 + -8) = 0x140022b81;
        IofCompleteRequest(param_1,0);
LAB_140022b86:
        if ((int)param_2 != 0) {
LAB_140022aee:
          *(undefined8 *)(puVar8 + -8) = 0x140022afa;
          IoReleaseCancelSpinLock(puVar8[0x50]);
          *(undefined8 *)(puVar8 + -8) = 0x140022b11;
          KeReleaseSpinLock(&BowserIrpQueueSpinLock,uVar7);
        }
        return 0x103;
      }
    }
    pcVar5 = (code *)swi(0x29);
    (*pcVar5)(3);
    puVar6 = puVar8 + 8;
LAB_140022bd7:
    puVar8 = puVar6;
    if ((longlong *)*param_2 == param_2) {
      *(undefined8 *)(puVar8 + -8) = 0x140022be5;
      BowserActivateScavengerTimer();
    }
  } while( true );
}



===== BowserCompleteTdiRequest @ 140022bf0 =====

undefined8 BowserCompleteTdiRequest(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  KeSetEvent(param_3,0,0);
  return 0xc0000016;
}



===== BowserUninitializeTimer @ 140022c20 =====

void BowserUninitializeTimer(longlong param_1)

{
  undefined1 uVar1;
  
  BowserReferenceDiscardableCode(3);
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x80);
  *(undefined1 *)(param_1 + 0xd9) = 0;
  KeReleaseSpinLock(param_1 + 0x80,uVar1);
  BowserStopTimer(param_1);
  KeWaitForSingleObject(param_1 + 0x88,0,0,0,0);
  RdrDereferenceDiscardableCode(3);
  return;
}



===== BowserStopTimer @ 140022cb0 =====

void BowserStopTimer(longlong param_1)

{
  undefined1 uVar1;
  char cVar2;
  
  if (*(char *)(param_1 + 0xd8) != '\0') {
    BowserReferenceDiscardableCode(3);
    uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x80);
    if (*(char *)(param_1 + 0xd8) != '\0') {
      *(undefined1 *)(param_1 + 0xda) = 1;
      cVar2 = KeCancelTimer(param_1 + 0x40);
      if (cVar2 != '\0') {
        *(undefined2 *)(param_1 + 0xda) = 0;
        *(undefined1 *)(param_1 + 0xd8) = 0;
        KeSetEvent(param_1 + 0x88,2);
      }
    }
    KeReleaseSpinLock(param_1 + 0x80,uVar1);
    RdrDereferenceDiscardableCode(3);
  }
  return;
}



===== BowserEnablePnp @ 140022d74 =====

undefined8 BowserEnablePnp(longlong param_1,ulonglong param_2,undefined8 param_3)

{
  undefined4 uVar1;
  
  BowserReferenceDiscardableCode(3);
  uVar1 = *(undefined4 *)(param_1 + 0x38);
  KeAcquireSpinLockRaiseToDpc(&BowserMailslotSpinLock);
  (&DAT_14000d810)[(param_2 & 0xffffffff) * 0xe] = uVar1;
  KeReleaseSpinLock(&BowserMailslotSpinLock);
  BowserTrimMessageQueue(&BowserPnp + (param_2 & 0xffffffff) * 7);
  RdrDereferenceDiscardableCode(3);
  BowWriteTelemetryMailslotProcessing2(L"BowserEnablePnp",0,param_3);
  return 0;
}



===== BowserTrimMessageQueue @ 140022e00 =====

void BowserTrimMessageQueue(longlong *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  code *pcVar3;
  undefined1 *puVar4;
  undefined1 uVar5;
  uint uVar6;
  undefined1 *puVar7;
  undefined8 uStack_30;
  undefined1 auStack_28 [32];
  
  BowserReferenceDiscardableCode(3);
  uVar5 = KeAcquireSpinLockRaiseToDpc(&BowserMailslotSpinLock);
  puVar7 = auStack_28;
  uVar6 = *(uint *)(param_1 + 2);
  puVar4 = auStack_28;
  if (uVar6 < *(uint *)((longlong)param_1 + 0x14)) goto LAB_140022ecb;
LAB_140022e36:
  puVar7 = puVar4;
  if (uVar6 == 0) {
    param_1 = param_1 + 5;
    while (plVar1 = (longlong *)*param_1, plVar1 != param_1) {
      if (((longlong *)plVar1[1] != param_1) ||
         (lVar2 = *plVar1, (longlong *)*(longlong *)(lVar2 + 8) != plVar1)) {
        do {
          pcVar3 = (code *)swi(0x29);
          uVar5 = (*pcVar3)(3);
          puVar7 = puVar7 + 8;
LAB_140022ecb:
          while ((plVar1 = (longlong *)*param_1, (longlong *)plVar1[1] == param_1 &&
                 (lVar2 = *plVar1, *(longlong **)(lVar2 + 8) == plVar1))) {
            *param_1 = lVar2;
            *(longlong **)(lVar2 + 8) = param_1;
            *(int *)((longlong)param_1 + 0x14) = *(int *)((longlong)param_1 + 0x14) + -1;
            *(undefined8 *)(puVar7 + -8) = 0x140022ef8;
            KeReleaseSpinLock(&BowserMailslotSpinLock,uVar5);
            *(undefined8 *)(puVar7 + -8) = 0x140022f06;
            BowserFreeMailslotBuffer((longlong)(plVar1 + -1));
            *(undefined8 *)(puVar7 + -8) = 0x140022f14;
            uVar5 = KeAcquireSpinLockRaiseToDpc(&BowserMailslotSpinLock);
            uVar6 = *(uint *)(param_1 + 2);
            puVar4 = puVar7;
            if (*(uint *)((longlong)param_1 + 0x14) <= uVar6) goto LAB_140022e36;
          }
        } while( true );
      }
      *param_1 = lVar2;
      *(longlong **)(lVar2 + 8) = param_1;
      *(undefined8 *)(puVar7 + -8) = 0x140022e99;
      KeReleaseSpinLock(&BowserMailslotSpinLock,uVar5);
      *(undefined8 *)(puVar7 + -8) = 0x140022eaa;
      ExFreePoolWithTag(plVar1,0);
      *(undefined8 *)(puVar7 + -8) = 0x140022ebd;
      uVar5 = KeAcquireSpinLockRaiseToDpc(&BowserMailslotSpinLock);
    }
  }
  *(undefined8 *)(puVar7 + -8) = 0x140022e4b;
  KeReleaseSpinLock(&BowserMailslotSpinLock,uVar5);
  *(undefined8 *)(puVar7 + -8) = 0x140022e5a;
  RdrDereferenceDiscardableCode(3);
  return;
}



===== BowserSendPnp @ 140022f30 =====

void BowserSendPnp(undefined4 param_1,ushort *param_2,ushort *param_3,ushort *param_4)

{
  int *piVar1;
  ushort uVar2;
  ushort uVar3;
  undefined8 *puVar4;
  code *pcVar5;
  undefined4 uVar6;
  byte bVar7;
  undefined8 *puVar8;
  longlong lVar9;
  undefined8 uVar10;
  ushort *puVar11;
  int *piVar12;
  ushort *_Size;
  ushort *puVar13;
  ushort *puVar14;
  ushort local_38 [8];
  
  uVar6 = SUB84(param_4,0);
  puVar8 = (undefined8 *)0x0;
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[5] = 0;
  local_38[6] = 0;
  local_38[7] = 0;
  puVar11 = param_2;
  _Size = param_3;
  BowserReferenceDiscardableCode(3);
  puVar13 = local_38;
  if (param_3 != (ushort *)0x0) {
    puVar13 = param_3;
  }
  puVar14 = local_38;
  if (param_2 != (ushort *)0x0) {
    puVar14 = param_2;
  }
  piVar12 = &DAT_14000d810;
  do {
    if (*piVar12 != 0) {
      if (puVar8 == (undefined8 *)0x0) {
        _Size = (ushort *)0x6c6e424c;
        puVar8 = (undefined8 *)ExAllocatePool2(0x42);
        if (puVar8 != (undefined8 *)0x0) {
          *(undefined4 *)(puVar8 + 2) = param_1;
          puVar4 = puVar8 + 7;
          *(undefined4 *)((longlong)puVar8 + 0x14) = uVar6;
          uVar2 = *puVar13;
          *(ushort *)(puVar8 + 3) = uVar2;
          *(ushort *)((longlong)puVar8 + 0x1a) = uVar2;
          puVar8[4] = puVar4;
          memcpy(puVar4,*(void **)(puVar13 + 4),(ulonglong)*puVar13);
          uVar2 = *puVar13;
          uVar3 = *puVar14;
          *(ushort *)(puVar8 + 5) = uVar3;
          *(ushort *)((longlong)puVar8 + 0x2a) = uVar3;
          puVar8[6] = (void *)((longlong)puVar4 + (ulonglong)uVar2);
          _Size = (ushort *)(ulonglong)*puVar14;
          memcpy((void *)((longlong)puVar4 + (ulonglong)uVar2),*(void **)(puVar14 + 4),(size_t)_Size
                );
        }
      }
      bVar7 = KeAcquireSpinLockRaiseToDpc(&BowserMailslotSpinLock);
      if (*piVar12 != 0) {
        lVar9 = BowserDequeueQueuedIrp((longlong *)(piVar12 + 2),'\0');
        if (lVar9 != 0) {
          KeReleaseSpinLock(&BowserMailslotSpinLock,bVar7);
          _Size = puVar14;
          param_4 = puVar13;
          uVar10 = BowserCopyPnp(lVar9,param_1,puVar14,puVar13,uVar6);
          *(uint *)(lVar9 + 0x30) = (uint)uVar10;
          if (((uint)uVar10 & 0xc0000000) == 0xc0000000) {
            *(undefined8 *)(lVar9 + 0x38) = 0;
          }
          puVar11 = (ushort *)0x0;
          IofCompleteRequest(lVar9);
          goto LAB_1400230f8;
        }
        if (puVar8 != (undefined8 *)0x0) {
          puVar4 = *(undefined8 **)(piVar12 + 8);
          if ((int *)*puVar4 != piVar12 + 6) {
            pcVar5 = (code *)swi(0x29);
            (*pcVar5)(3);
            pcVar5 = (code *)swi(3);
            (*pcVar5)();
            return;
          }
          *puVar8 = piVar12 + 6;
          puVar8[1] = puVar4;
          *puVar4 = puVar8;
          *(undefined8 **)(piVar12 + 8) = puVar8;
          puVar8 = (undefined8 *)0x0;
        }
      }
      puVar11 = (ushort *)(ulonglong)bVar7;
      KeReleaseSpinLock(&BowserMailslotSpinLock);
    }
LAB_1400230f8:
    piVar1 = piVar12 + 10;
    piVar12 = piVar12 + 0xe;
    if ((int *)((longlong)&DAT_14000d868 + 7) < piVar1) {
      if (puVar8 != (undefined8 *)0x0) {
        puVar11 = (ushort *)0x0;
        ExFreePoolWithTag(puVar8);
      }
      BowWriteTelemetryMailslotProcessing(L"BowserSendPnp",puVar11,_Size,param_4);
      RdrDereferenceDiscardableCode(3);
      return;
    }
  } while( true );
}



===== BowserFreeTransportBackupList @ 140023170 =====

void BowserFreeTransportBackupList(longlong param_1)

{
  longlong lVar1;
  undefined1 uVar2;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(&BowserBackupListSpinLock);
  lVar1 = *(longlong *)(param_1 + 0x58);
  if (lVar1 == 0) {
    KeReleaseSpinLock(&BowserBackupListSpinLock,uVar2);
  }
  else {
    *(undefined8 *)(param_1 + 0x58) = 0;
    KeReleaseSpinLock();
    ExFreePoolWithTag(lVar1,0);
  }
  return;
}



===== BowserTimeoutQueuedIrp @ 1400231e8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void BowserTimeoutQueuedIrp(longlong ****param_1)

{
  longlong *****ppppplVar1;
  longlong *****ppppplVar2;
  longlong ****pppplVar3;
  uint uVar4;
  longlong ****pppplVar5;
  longlong *****ppppplVar6;
  code *pcVar7;
  undefined1 uVar8;
  ulonglong uVar9;
  undefined1 *puVar10;
  ulonglong uVar11;
  longlong *****ppppplVar12;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  longlong *****local_18;
  longlong *****local_10;
  
  uVar9 = (ulonglong)BowserFindMasterTimeout;
  BowserReferenceDiscardableCode(3);
  uVar11 = (ulonglong)BowserTimeIncrement;
  local_10 = (longlong *****)&local_18;
  local_18 = (longlong *****)&local_18;
  uVar8 = KeAcquireSpinLockRaiseToDpc(&BowserIrpQueueSpinLock,(uVar9 * 10000000) % uVar11);
  ppppplVar12 = (longlong *****)*param_1;
joined_r0x00014002324f:
  while (ppppplVar6 = ppppplVar12, ppppplVar6 != (longlong *****)param_1) {
    if (*(char *)((longlong)ppppplVar6 + -100) == '\0') goto LAB_140023272;
    ppppplVar12 = (longlong *****)*ppppplVar6;
    LOCK();
    pppplVar3 = ppppplVar6[-8];
    ppppplVar6[-8] = (longlong ****)0x0;
    UNLOCK();
    if (pppplVar3 != (longlong ****)0x0) {
      *(undefined4 *)(ppppplVar6 + -0xf) = 0xc0000120;
      goto LAB_14002329f;
    }
  }
  KeReleaseSpinLock(&BowserIrpQueueSpinLock,CONCAT71((int7)((ulonglong)ppppplVar6 >> 8),uVar8));
  while (ppppplVar12 = local_18, puVar10 = auStack_38, (longlong ******)local_18 != &local_18) {
    if (((longlong ******)local_18[1] != &local_18) ||
       (ppppplVar6 = (longlong *****)*local_18, (longlong *****)ppppplVar6[1] != local_18))
    goto LAB_140023363;
    ppppplVar6[1] = (longlong ****)&local_18;
    ppppplVar2 = local_18 + -0x15;
    uVar4 = *(uint *)(local_18 + -0xf);
    ppppplVar1 = local_18 + -0xf;
    local_18 = ppppplVar6;
    *(uint *)ppppplVar1 = uVar4;
    if ((uVar4 & 0xc0000000) == 0xc0000000) {
      ppppplVar12[-0xe] = (longlong ****)0x0;
    }
    IofCompleteRequest(ppppplVar2,0);
  }
LAB_14002336a:
  *(undefined8 *)(puVar10 + -8) = 0x140023374;
  RdrDereferenceDiscardableCode(3);
  return;
LAB_140023272:
  ppppplVar12 = (longlong *****)*ppppplVar6;
  if ((uint)((uVar9 * 10000000) / uVar11) <
      (uint)((int)_DAT_fffff78000000320 - *(int *)(ppppplVar6[2] + -8))) {
    LOCK();
    pppplVar3 = ppppplVar6[-8];
    ppppplVar6[-8] = (longlong ****)0x0;
    UNLOCK();
    if (pppplVar3 != (longlong ****)0x0) {
      *(undefined4 *)(ppppplVar6 + -0xf) = 0xc00000b5;
LAB_14002329f:
      ppppplVar6[-0xe] = (longlong ****)0x0;
      pppplVar3 = *ppppplVar6;
      if (((longlong *****)pppplVar3[1] != ppppplVar6) ||
         (pppplVar5 = ppppplVar6[1], (longlong *****)*pppplVar5 != ppppplVar6)) goto LAB_140023363;
      *pppplVar5 = (longlong ***)pppplVar3;
      pppplVar3[1] = (longlong ***)pppplVar5;
      if ((longlong ******)*local_10 != &local_18) goto LAB_140023363;
      ppppplVar6[1] = (longlong ****)local_10;
      *ppppplVar6 = (longlong ****)&local_18;
      *local_10 = (longlong ****)ppppplVar6;
      local_10 = ppppplVar6;
    }
  }
  goto joined_r0x00014002324f;
LAB_140023363:
  pcVar7 = (code *)swi(0x29);
  (*pcVar7)(3);
  puVar10 = auStack_30;
  goto LAB_14002336a;
}



===== BowserFreeMailslotBuffer @ 140023390 =====

void BowserFreeMailslotBuffer(longlong param_1)

{
  longlong lVar1;
  code *pcVar2;
  uint uVar3;
  undefined1 uVar4;
  undefined8 *puVar5;
  undefined1 *puVar6;
  undefined8 *puVar7;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  BowserReferenceDiscardableCode(3);
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x18);
  BowserDereferenceTransportName(*(longlong *)(param_1 + 0x40));
  BowserDereferenceTransport(lVar1);
  uVar4 = KeAcquireSpinLockRaiseToDpc(&BowserMailslotSpinLock);
  puVar6 = auStack_28;
  if (*(int *)(param_1 + 0x28) == 0x200) {
    if (BowserNumberOfFreeMailslotBuffers <= DAT_14000d294) {
      puVar5 = &BowserMailslotBufferList;
      puVar7 = (undefined8 *)(param_1 + 8);
      if ((undefined8 *)*DAT_14000d5a8 != &BowserMailslotBufferList) {
        puVar5 = (undefined8 *)0x3;
        pcVar2 = (code *)swi(0x29);
        uVar4 = (*pcVar2)();
        puVar6 = auStack_20;
      }
      *puVar7 = puVar5;
      BowserNumberOfFreeMailslotBuffers = BowserNumberOfFreeMailslotBuffers + 1;
      *(undefined8 **)(param_1 + 0x10) = DAT_14000d5a8;
      uVar3 = (uint)BowserNumberOfFreeMailslotBuffers >> 8;
      *DAT_14000d5a8 = puVar7;
      *(undefined8 *)(puVar6 + -8) = 0x14002342c;
      DAT_14000d5a8 = puVar7;
      KeReleaseSpinLock(&BowserMailslotSpinLock,CONCAT31((int3)uVar3,uVar4));
      goto LAB_14002345b;
    }
  }
  BowserNumberOfMailslotBuffers = BowserNumberOfMailslotBuffers + -1;
  KeReleaseSpinLock(&BowserMailslotSpinLock,uVar4);
  ExFreePoolWithTag(param_1,0);
  puVar6 = auStack_28;
LAB_14002345b:
  *(undefined8 *)(puVar6 + -8) = 0x140023465;
  RdrDereferenceDiscardableCode(3);
  return;
}



===== BowserReadPnp @ 140023478 =====

ulonglong BowserReadPnp(longlong param_1,undefined8 param_2,ushort *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined1 uVar5;
  uint uVar6;
  longlong *plVar7;
  ulonglong uVar8;
  undefined1 *puVar9;
  int iVar10;
  undefined1 auStackY_48 [8];
  undefined1 auStackY_40 [24];
  
  iVar10 = (int)param_3;
  uVar8 = (ulonglong)param_3 & 0xffffffff;
  plVar7 = &BowserPnp + uVar8 * 7;
  if (iVar10 == 1) {
    BowserReferenceDiscardableCode(4);
  }
  BowserReferenceDiscardableCode(3);
  uVar5 = KeAcquireSpinLockRaiseToDpc(&BowserMailslotSpinLock);
  if ((&DAT_14000d810)[uVar8 * 0xe] == 0) {
    KeReleaseSpinLock(&BowserMailslotSpinLock,uVar5);
    puVar9 = auStackY_48;
    uVar8 = 0xc00000bb;
LAB_1400235d4:
    if (iVar10 != 1) goto LAB_1400235e3;
  }
  else {
    plVar3 = &DAT_14000d828 + uVar8 * 7;
    plVar1 = (longlong *)*plVar3;
    if (plVar1 != plVar3) {
      if (((longlong *)plVar1[1] == plVar3) &&
         (lVar2 = *plVar1, *(longlong **)(lVar2 + 8) == plVar1)) {
        *plVar3 = lVar2;
        *(longlong **)(lVar2 + 8) = plVar3;
        KeReleaseSpinLock(&BowserMailslotSpinLock,uVar5);
        param_3 = (ushort *)(plVar1 + 5);
        uVar8 = BowserCopyPnp(param_1,(int)plVar1[2],param_3,(ushort *)(plVar1 + 3),
                              *(undefined4 *)((longlong)plVar1 + 0x14));
        uVar8 = uVar8 & 0xffffffff;
        ExFreePoolWithTag(plVar1,0);
        puVar9 = auStackY_48;
      }
      else {
LAB_1400235aa:
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3);
        puVar9 = auStackY_40;
LAB_1400235b1:
        *(undefined8 *)(puVar9 + -8) = 0x1400235c0;
        uVar8 = BowserQueueNonBufferRequestReferenced
                          (param_1,(longlong *)(&DAT_14000d818 + uVar8 * 0x38),param_3,'\0');
        uVar8 = uVar8 & 0xffffffff;
        *(undefined8 *)(puVar9 + -8) = 0x1400235cf;
        KeReleaseSpinLock(&BowserMailslotSpinLock,uVar5);
      }
      goto LAB_1400235d4;
    }
    puVar9 = auStackY_48;
    if ((iVar10 != 1) || (plVar3 = (longlong *)*plVar7, puVar9 = auStackY_48, plVar3 == plVar7))
    goto LAB_1400235b1;
    if (((longlong *)plVar3[1] != plVar7) || (lVar2 = *plVar3, *(longlong **)(lVar2 + 8) != plVar3))
    goto LAB_1400235aa;
    *plVar7 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar7;
    *(int *)(&DAT_14000d814 + uVar8 * 0x38) = *(int *)(&DAT_14000d814 + uVar8 * 0x38) + -1;
    KeReleaseSpinLock(&BowserMailslotSpinLock,uVar5);
    uVar6 = BowserNetlogonCopyMessage(param_1,(longlong)(plVar3 + -1));
    puVar9 = auStackY_48;
    uVar8 = (ulonglong)uVar6;
  }
  *(undefined8 *)(puVar9 + -8) = 0x1400235e3;
  RdrDereferenceDiscardableCode(4);
LAB_1400235e3:
  *(undefined8 *)(puVar9 + -8) = 0x1400235ed;
  RdrDereferenceDiscardableCode(3);
  *(undefined8 *)(puVar9 + -8) = 0x1400235fb;
  BowWriteTelemetryMailslotProcessing2(L"BowserReadPnp",(int)uVar8,param_3);
  return uVar8;
}



===== BowserCopyPnp$fin$0 @ 140023620 =====

void BowserCopyPnp_fin_0(void)

{
  RdrDereferenceDiscardableCode(3);
  return;
}



===== BowserEnablePnp$fin$0 @ 140023641 =====

void BowserEnablePnp_fin_0(void)

{
  RdrDereferenceDiscardableCode(3);
  return;
}



===== BowserNetlogonCopyMessage @ 140024010 =====

int BowserNetlogonCopyMessage(longlong param_1,longlong param_2)

{
  ushort uVar1;
  ushort uVar2;
  longlong lVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  void *_Dst;
  undefined2 *puVar8;
  ulonglong uVar9;
  ulonglong _Size;
  ulonglong local_68;
  void *pvStack_60;
  undefined8 local_58;
  void *pvStack_50;
  ulonglong local_48;
  void *pvStack_40;
  uint local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  local_58 = 0;
  pvStack_50 = (void *)0x0;
  local_68 = 0;
  pvStack_60 = (void *)0x0;
  BowserReferenceDiscardableCode(4);
  uVar1 = *(ushort *)(param_2 + 0x95);
  RtlInitString(&local_58,param_2 + 0xa1);
  uVar2 = *(ushort *)(param_2 + 0x93);
  uVar9 = (ulonglong)uVar2;
  lVar3 = *(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0x40) + 0x18) + 8);
  local_48 = *(ulonglong *)(lVar3 + 0x30);
  pvStack_40 = *(void **)(lVar3 + 0x38);
  lVar3 = *(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0x40) + 0x10) + 0x10);
  local_38 = *(uint *)(lVar3 + 0x28);
  uStack_34 = *(undefined4 *)(lVar3 + 0x2c);
  uStack_30 = *(undefined4 *)(lVar3 + 0x30);
  uStack_2c = *(undefined4 *)(lVar3 + 0x34);
  lVar3 = *(longlong *)(param_1 + 0xb8);
  iVar4 = RtlOemStringToUnicodeString(&local_68,&local_58,1);
  if (iVar4 < 0) {
    BowserLogIllegalName(iVar4,pvStack_50,(ushort)local_58);
    pvStack_60 = (void *)0x0;
  }
  else {
    _Size = (ulonglong)(ushort)local_38;
    if ((ulonglong)*(uint *)(lVar3 + 8) <
        _Size + 0x4c + (local_68 & 0xffff) + uVar9 + (local_48 & 0xffff)) {
      iVar4 = -0x3fffffdd;
    }
    else {
      lVar3 = *(longlong *)(param_1 + 8);
      if ((*(byte *)(lVar3 + 10) & 5) == 0) {
        puVar5 = (undefined8 *)MmMapLockedPagesSpecifyCache(lVar3,0,1,0,0,0x40000010);
      }
      else {
        puVar5 = *(undefined8 **)(lVar3 + 0x18);
      }
      if (puVar5 == (undefined8 *)0x0) {
        iVar4 = -0x3fffffe9;
      }
      else if (((ulonglong)puVar5 & 3) == 0) {
        *puVar5 = *(undefined8 *)(param_2 + 0x30);
        *(uint *)(puVar5 + 3) = (uint)uVar2;
        *(undefined4 *)((longlong)puVar5 + 0x1c) = 0x30;
        memcpy(puVar5 + 6,(void *)((ulonglong)uVar1 + param_2 + 0x5c),uVar9);
        puVar6 = (undefined8 *)((longlong)(puVar5 + 6) + uVar9);
        iVar4 = (int)puVar5;
        if (*(int *)(param_2 + 0x38) == 0) {
          puVar5[5] = 0;
        }
        else {
          *(undefined2 *)puVar6 = 0;
          *(undefined1 *)((longlong)puVar6 + 2) = 0;
          puVar7 = (undefined8 *)((ulonglong)((longlong)puVar6 + 3) & 0xfffffffffffffffc);
          *(undefined4 *)(puVar5 + 5) = 0x10;
          *(uint *)((longlong)puVar5 + 0x2c) =
               ((uint)(undefined1 *)((longlong)puVar6 + 3) & 0xfffffffc) - iVar4;
          *puVar7 = 0;
          puVar7[1] = 0;
          *(undefined2 *)puVar7 = 2;
          *(undefined4 *)((longlong)puVar7 + 4) = *(undefined4 *)(param_2 + 0x38);
          puVar6 = puVar7 + 2;
        }
        *(undefined1 *)puVar6 = 0;
        _Dst = (void *)((ulonglong)((longlong)puVar6 + 1) & 0xfffffffffffffffe);
        *(uint *)(puVar5 + 2) = (uint)(ushort)local_48;
        *(uint *)((longlong)puVar5 + 0x14) =
             ((uint)(undefined1 *)((longlong)puVar6 + 1) & 0xfffffffe) - iVar4;
        uVar9 = local_48 & 0xffff;
        memcpy(_Dst,pvStack_40,uVar9);
        puVar8 = (undefined2 *)((longlong)_Dst + uVar9);
        *puVar8 = 0;
        puVar8 = puVar8 + 1;
        *(uint *)(puVar5 + 1) = (uint)(ushort)local_68;
        *(int *)((longlong)puVar5 + 0xc) = (int)puVar8 - iVar4;
        memcpy(puVar8,pvStack_60,local_68 & 0xffff);
        puVar8 = (undefined2 *)((longlong)puVar8 + (local_68 & 0xffff));
        *puVar8 = 0;
        puVar8 = puVar8 + 1;
        *(uint *)(puVar5 + 4) = local_38 & 0xffff;
        *(int *)((longlong)puVar5 + 0x24) = (int)puVar8 - iVar4;
        memcpy(puVar8,(void *)CONCAT44(uStack_2c,uStack_30),_Size);
        *(undefined2 *)((longlong)puVar8 + _Size) = 0;
        iVar4 = 0;
      }
      else {
        iVar4 = -0x3ffffff3;
      }
    }
  }
  RtlFreeUnicodeString(&local_68);
  BowserFreeMailslotBuffer(param_2);
  RdrDereferenceDiscardableCode(4);
  return iVar4;
}



===== BowserProcessNetlogonMailslotWrite @ 1400242b4 =====

undefined1
BowserProcessNetlogonMailslotWrite
          (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  longlong lVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  char *pcVar8;
  undefined8 uVar9;
  undefined1 *puVar10;
  undefined1 uVar11;
  uint uVar12;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  BowserReferenceDiscardableCode(4);
  pcVar8 = "\\MAILSLOT\\NET\\NETLOGON";
  iVar3 = _stricmp((char *)(param_1 + 0xa1),"\\MAILSLOT\\NET\\NETLOGON");
  if (iVar3 == 0) {
LAB_140024315:
    uVar2 = KeAcquireSpinLockRaiseToDpc(&BowserMailslotSpinLock);
    if (DAT_14000d848 != 0) {
      uVar9 = 0;
      uVar11 = 1;
      lVar5 = BowserDequeueQueuedIrp((longlong *)&DAT_14000d850,'\0');
      puVar10 = auStack_28;
      if (lVar5 == 0) {
        puVar6 = (undefined8 *)(param_1 + 8);
        puVar7 = DAT_14000d840;
        if ((undefined8 *)*DAT_14000d840 != &DAT_14000d838) {
          puVar7 = (undefined8 *)0x3;
          pcVar1 = (code *)swi(0x29);
          puVar6 = (undefined8 *)(*pcVar1)();
          puVar10 = auStack_20;
        }
        puVar6[1] = puVar7;
        pcVar8 = (char *)CONCAT71((int7)((ulonglong)uVar9 >> 8),uVar2);
        *puVar6 = &DAT_14000d838;
        *puVar7 = puVar6;
        uVar4 = DAT_14000d848;
        uVar12 = DAT_14000d84c + 1;
        *(undefined8 *)(puVar10 + -8) = 0x140024405;
        DAT_14000d840 = puVar6;
        DAT_14000d84c = uVar12;
        KeReleaseSpinLock(&BowserMailslotSpinLock);
        if (uVar4 < uVar12) {
          *(undefined8 *)(puVar10 + -8) = 0x140024416;
          BowserTrimMessageQueue(&DAT_14000d838);
        }
      }
      else {
        KeReleaseSpinLock(&BowserMailslotSpinLock,uVar2);
        uVar4 = BowserNetlogonCopyMessage(lVar5,param_1);
        *(uint *)(lVar5 + 0x30) = uVar4;
        if ((uVar4 & 0xc0000000) == 0xc0000000) {
          *(undefined8 *)(lVar5 + 0x38) = 0;
        }
        pcVar8 = (char *)0x0;
        IofCompleteRequest(lVar5);
        puVar10 = auStack_28;
      }
      goto LAB_140024416;
    }
    pcVar8 = (char *)CONCAT71((int7)((ulonglong)pcVar8 >> 8),uVar2);
    KeReleaseSpinLock(&BowserMailslotSpinLock);
  }
  else {
    pcVar8 = "\\MAILSLOT\\NET\\NTLOGON";
    iVar3 = _stricmp((char *)(param_1 + 0xa1),"\\MAILSLOT\\NET\\NTLOGON");
    if (iVar3 == 0) goto LAB_140024315;
  }
  puVar10 = auStack_28;
  uVar11 = 0;
LAB_140024416:
  *(undefined8 *)(puVar10 + -8) = 0x140024420;
  RdrDereferenceDiscardableCode(4);
  *(undefined8 *)(puVar10 + -8) = 0x14002442c;
  BowWriteTelemetryMailslotProcessing(L"BowserProcessNetlogonMailslotWrite",pcVar8,param_3,param_4);
  return uVar11;
}



===== BowserNetlogonDeleteTransportFromMessageQueue @ 140024460 =====

void BowserNetlogonDeleteTransportFromMessageQueue(longlong param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  code *pcVar3;
  undefined1 uVar4;
  undefined8 *puVar5;
  
  BowserReferenceDiscardableCode(4);
  uVar4 = KeAcquireSpinLockRaiseToDpc(&BowserMailslotSpinLock);
  puVar5 = DAT_14000d838;
  if ((undefined8 **)DAT_14000d838 != &DAT_14000d838) {
    do {
      puVar1 = (undefined8 *)*puVar5;
      if (*(longlong *)(puVar5[7] + 0x18) == param_1) {
        if (((undefined8 *)puVar1[1] != puVar5) ||
           (puVar2 = (undefined8 *)puVar5[1], (undefined8 *)*puVar2 != puVar5)) {
          pcVar3 = (code *)swi(0x29);
          (*pcVar3)(3);
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        *puVar2 = puVar1;
        puVar1[1] = puVar2;
        DAT_14000d84c = DAT_14000d84c + -1;
        KeReleaseSpinLock(&BowserMailslotSpinLock,uVar4);
        BowserFreeMailslotBuffer((longlong)(puVar5 + -1));
        uVar4 = KeAcquireSpinLockRaiseToDpc(&BowserMailslotSpinLock);
        puVar5 = DAT_14000d838;
      }
      else {
        puVar5 = puVar1;
      }
    } while ((undefined8 **)puVar5 != &DAT_14000d838);
  }
  KeReleaseSpinLock(&BowserMailslotSpinLock,uVar4);
  RdrDereferenceDiscardableCode(4);
  return;
}



===== BowserNetlogonCopyMessage$fin$0 @ 140024554 =====

void BowserNetlogonCopyMessage_fin_0(undefined8 param_1,longlong param_2)

{
  RtlFreeUnicodeString(param_2 + 0x30);
  BowserFreeMailslotBuffer(*(longlong *)(param_2 + 0xa8));
  return;
}



===== BowserpInitializeIrpQueue @ 140025008 =====

undefined8 BowserpInitializeIrpQueue(void)

{
  KeInitializeSpinLock(&BowserIrpQueueSpinLock);
  DAT_14000d7d8 = &BowserCriticalThreadQueue;
  BowserCriticalThreadQueue = &BowserCriticalThreadQueue;
  DAT_14000d7e8 = &BowserDelayedThreadQueue;
  BowserDelayedThreadQueue = &BowserDelayedThreadQueue;
  BowserCriticalThreadWorkItem = IoAllocateWorkItem(BowserDeviceObject);
  BowserDelayedThreadWorkItem = IoAllocateWorkItem(BowserDeviceObject);
  if (BowserCriticalThreadWorkItem != 0) {
    if (BowserDelayedThreadWorkItem != 0) {
      return 0;
    }
    IoFreeWorkItem();
    BowserCriticalThreadWorkItem = 0;
  }
  if (BowserDelayedThreadWorkItem != 0) {
    IoFreeWorkItem();
    BowserDelayedThreadWorkItem = 0;
  }
  return 0xc000009a;
}



===== BowserpInitializeMailslot @ 1400250d8 =====

void BowserpInitializeMailslot(void)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  KeInitializeSpinLock(&BowserMailslotSpinLock);
  DAT_14000d5a8 = &BowserMailslotBufferList;
  BowserMailslotBufferList = &BowserMailslotBufferList;
  puVar2 = &DAT_14000d828;
  do {
    puVar1 = puVar2 + -5;
    puVar2[-4] = puVar1;
    *puVar1 = puVar1;
    puVar2[1] = puVar2;
    *puVar2 = puVar2;
    BowserInitializeIrpQueue((longlong)(puVar2 + -2));
    puVar1 = puVar2 + 2;
    puVar2 = puVar2 + 7;
  } while (puVar1 < &BowParametersRegistryKey);
  return;
}



===== BowserpInitializeTdi @ 140025148 =====

void BowserpInitializeTdi(void)

{
  DAT_14000d410 = &BowserTransportHead;
  BowserTransportHead = &BowserTransportHead;
  ExInitializeResourceLite(&BowserTransportDatabaseResource);
  KeInitializeSpinLock(&BowserTransportMasterNameSpinLock);
  DAT_14000d4c0 = &BowserServicedDomains;
  BowserServicedDomains = &BowserServicedDomains;
  return;
}



===== entry @ 1400251b0 =====

void entry(longlong param_1,ushort *param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 1400251e4 =====

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



===== BowserpInitializeFsp @ 140025218 =====

undefined8 BowserpInitializeFsp(void)

{
  BowserInitializeIrpContext();
  KeInitializeSpinLock(&BowserTimeSpinLock);
  KeInitializeTimer(&BowserScavengerTimer);
  KeInitializeDpc(&BowserScavengerDpc,BowserScavengerTimerDispatch,0);
  return 0;
}



===== DriverEntry @ 140025274 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong DriverEntry(longlong param_1,ushort *param_2)

{
  code *pcVar1;
  uint uVar2;
  wchar_t *pwVar3;
  ulonglong uVar4;
  longlong lVar5;
  ushort uVar6;
  ulonglong uVar7;
  undefined1 *puVar8;
  undefined8 *puVar9;
  longlong local_res10;
  longlong local_res18 [2];
  undefined1 auStack_b8 [8];
  undefined1 auStack_b0 [24];
  wchar_t *local_98;
  ulonglong local_90;
  longlong *local_88;
  ushort local_78 [8];
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 *local_48;
  undefined8 uStack_40;
  longlong local_38;
  ulonglong local_30;
  
  local_res10 = 0;
  local_res18[0] = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_38 = 0;
  local_78[0] = 0;
  local_78[1] = 0;
  local_78[2] = 0;
  local_78[3] = 0;
  local_78[4] = 0;
  local_78[5] = 0;
  local_78[6] = 0;
  local_78[7] = 0;
  local_30 = local_30 & 0xffffffff00000000;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = (undefined8 *)0x0;
  uStack_40 = 0;
  wil_InitializeFeatureStaging();
  RtlInitUnicodeString(&BowParametersRegistryKey,0);
  uVar6 = *param_2;
  if ((uVar6 & 1) == 0) {
    if (uVar6 < 2) {
      pcVar1 = (code *)swi(0x2c);
      (*pcVar1)();
    }
    else {
      if (*(short *)(*(longlong *)(param_2 + 4) + -2 + (ulonglong)(uVar6 >> 1) * 2) == 0x5c) {
        uVar6 = uVar6 - 2;
        *param_2 = uVar6;
      }
      uVar2 = uVar6 + 0x18;
      if (uVar2 < 0x10000) {
        pwVar3 = (wchar_t *)ExAllocatePool2(0x42,uVar2,0x6e695742);
        puVar8 = auStack_b8;
        if (pwVar3 == (wchar_t *)0x0) {
          uVar7 = 0xc000009a;
        }
        else {
          local_98 = L"\\Parameters";
          RtlStringCbPrintfW(pwVar3,(ulonglong)uVar2,L"%wZ%s",param_2);
          RtlInitUnicodeString(&BowParametersRegistryKey,pwVar3);
          BowInitRegistryPoliciesKeyModule();
          BowInitRegistryParametersKeyModule();
          RdrInitializeDiscardableCode();
          TraceLoggingRegisterEx_EtwRegister_EtwSetInformation();
          RtlInitUnicodeString(&BowserNameString,L"\\Device\\LanmanDatagramReceiver");
          local_88 = &local_res10;
          local_90 = local_90 & 0xffffffffffffff00;
          local_98 = (wchar_t *)((ulonglong)local_98 & 0xffffffff00000000);
          IoCreateDevice(param_1,0,&BowserNameString,0x13);
          BowserFspProcess = IoGetCurrentProcess();
          if (g_pBowSecurityDescriptor == 0) {
            BowserCreateAdminSecurityDescriptor(local_res10);
          }
          ExInitializeResourceLite(&BowserDataResource);
          BowserDeviceObject = local_res10;
          BowserReadBowserConfiguration(param_2);
          *(undefined1 *)(local_res10 + 0x4c) = BowserIrpStackSize;
          BowserTimeIncrement = KeQueryTimeIncrement();
          BowserpInitializeTdi();
          BowserpInitializeMailslot();
          uVar4 = BowserpInitializeIrpQueue();
          puVar8 = auStack_b8;
          uVar7 = uVar4 & 0xffffffff;
          if (-1 < (int)uVar4) {
            KeInitializeSpinLock(&BowserDatagramQueueSpinLock);
            _BowserGetBrowserListTimeout = 0xffffffffff676980;
            KeInitializeSpinLock();
            uVar4 = BowserpInitializeFsp();
            puVar8 = auStack_b8;
            uVar7 = uVar4 & 0xffffffff;
            if (-1 < (int)uVar4) {
              _DAT_14000d420 = &BowserNameHead;
              BowserNameHead = &BowserNameHead;
              uVar2 = IsSuiteVersion();
              BowserSkuBasedUserMax = (-(uint)(uVar2 != 0) & 0xfffffffb) + 0xb;
              uVar2 = BowserBuildAnnounceSecurityDescriptor(local_res18);
              puVar8 = auStack_b8;
              uVar7 = (ulonglong)uVar2;
              if (-1 < (int)uVar2) {
                RtlInitUnicodeString(&local_68,L"\\LanmanServerAnnounceEvent");
                lVar5 = local_res18[0];
                local_48 = &local_68;
                uStack_50 = 0;
                local_30 = 0;
                local_58 = CONCAT44(local_58._4_4_,0x30);
                uStack_40 = CONCAT44(uStack_40._4_4_,0x280);
                local_38 = local_res18[0];
                local_98 = (wchar_t *)((ulonglong)local_98 & 0xffffffffffffff00);
                uVar2 = ZwCreateEvent(&BowserServerAnnouncementEventHandle,0x100003,&local_58,1);
                if (-1 < (int)uVar2) {
                  local_90 = 0;
                  local_98 = (wchar_t *)&BowserServerAnnouncementEvent;
                  uVar2 = ObReferenceObjectByHandle(BowserServerAnnouncementEventHandle,2,0,0);
                }
                uVar7 = (ulonglong)uVar2;
                ExFreePoolWithTag(*(undefined8 *)(lVar5 + 0x20),0x73654c42);
                ExFreePoolWithTag(lVar5,0x73654c42);
                RtlInitUnicodeString(local_78,0);
                BowserPrimaryDomainInfo = BowserCreateDomain(local_78,local_78);
                if (-1 < (int)uVar2) {
                  puVar9 = (undefined8 *)(param_1 + 0x70);
                  for (lVar5 = 0x1c; lVar5 != 0; lVar5 = lVar5 + -1) {
                    *puVar9 = BowserFsdDispatch;
                    puVar9 = puVar9 + 1;
                  }
                  *(code **)(param_1 + 0x68) = BowserUnload;
                  return uVar7;
                }
                RdrUninitializeDiscardableCode();
                puVar8 = auStack_b8;
              }
            }
          }
        }
        goto LAB_1400255fd;
      }
      pcVar1 = (code *)swi(0x2c);
      (*pcVar1)();
    }
  }
  else {
    pcVar1 = (code *)swi(0x2c);
    (*pcVar1)();
  }
  puVar8 = auStack_b0;
  uVar7 = 0xc000000d;
LAB_1400255fd:
  if (BowserCriticalThreadWorkItem != 0) {
    *(undefined8 *)(puVar8 + -8) = 0x140025610;
    IoFreeWorkItem();
  }
  if (BowserDelayedThreadWorkItem != 0) {
    *(undefined8 *)(puVar8 + -8) = 0x140025628;
    IoFreeWorkItem();
  }
  *(undefined8 *)(puVar8 + -8) = 0x140025632;
  wil_UninitializeFeatureStaging();
  return uVar7;
}



===== wil_InitializeFeatureStaging @ 140025654 =====

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



===== wil_details_PopulateInitialConfiguredFeatureStates @ 140025744 =====

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



===== RdrInitializeDiscardableCode @ 14002582c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RdrInitializeDiscardableCode(void)

{
  undefined *puVar1;
  longlong lVar2;
  
  puVar1 = &DAT_14000d600;
  lVar2 = 5;
  do {
    KeInitializeEvent(puVar1,0,1);
    puVar1 = puVar1 + 0x48;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  _DAT_14000d6f0 = BowserStartTimer;
  _DAT_14000d618 = 0;
  _DAT_14000d628 = 0;
  _DAT_14000d660 = 0;
  _DAT_14000d670 = 0;
  _DAT_14000d6a8 = 0;
  _DAT_14000d6b8 = 0;
  _DAT_14000d700 = 0;
  _DAT_14000d748 = 0;
  _DAT_14000d738 = BowserNetlogonCopyMessage;
  ExInitializeResourceLite(&RdrDiscardableCodeLock);
  return;
}



===== BowserReadBowserConfiguration @ 1400258dc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void BowserReadBowserConfiguration(undefined8 param_1)

{
  int iVar1;
  longlong lVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  undefined1 auStackY_4a8 [32];
  longlong in_stack_fffffffffffffb80;
  undefined4 *puVar5;
  undefined8 local_478;
  undefined4 local_470 [2];
  undefined8 local_468;
  undefined8 local_460;
  undefined8 uStack_458;
  undefined8 local_450;
  undefined8 local_448;
  undefined8 *local_440;
  undefined8 local_438;
  undefined8 local_430;
  undefined8 uStack_428;
  int local_418 [256];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_4a8;
  local_478 = 0;
  local_468 = 0;
  local_470[0] = 0;
  local_450 = 0x30;
  local_438 = 0x240;
  local_460 = 0;
  uStack_458 = 0;
  local_448 = 0;
  local_430 = 0;
  uStack_428 = 0;
  local_440 = (undefined8 *)param_1;
  iVar1 = ZwOpenKey(&local_478,0x20019);
  if (iVar1 < 0) {
    BowserWriteErrorLogEntry(0x40001f5d,iVar1,(void *)0x0,0,0,in_stack_fffffffffffffb80);
  }
  else {
    RtlInitUnicodeString(&local_460,L"Parameters");
    local_448 = local_478;
    local_440 = &local_460;
    local_450 = CONCAT44(local_450._4_4_,0x30);
    local_438 = CONCAT44(local_438._4_4_,0x240);
    local_430 = 0;
    uStack_428 = 0;
    iVar1 = ZwOpenKey(&local_468,0x20019);
    if (iVar1 < 0) {
      if (iVar1 != -0x3fffffcc) {
        BowserWriteErrorLogEntry(0x40001f5d,iVar1,(void *)0x0,0,0,in_stack_fffffffffffffb80);
      }
    }
    else {
      ppuVar3 = &BowserConfigEntries;
      puVar4 = BowserConfigEntries;
      while (puVar4 != (undefined *)0x0) {
        RtlInitUnicodeString(&local_460,puVar4);
        puVar5 = local_470;
        iVar1 = ZwQueryValueKey(local_468,&local_460,1,local_418);
        if (iVar1 < 0) goto LAB_140025b13;
        if (local_418[3] == 0) {
          puVar4 = *ppuVar3;
          lVar2 = -1;
          do {
            lVar2 = lVar2 + 1;
          } while (*(short *)(puVar4 + lVar2 * 2) != 0);
LAB_140025af8:
          BowserWriteErrorLogEntry(0x40001f5d,0xc000000d,puVar4,(short)lVar2 * 2,0,(longlong)puVar5)
          ;
        }
        else if (*(int *)(ppuVar3 + 2) == -1) {
          if ((local_418[1] != 4) || (local_418[3] != 4)) {
            puVar4 = *ppuVar3;
            lVar2 = -1;
            do {
              lVar2 = lVar2 + 1;
            } while (*(short *)(puVar4 + lVar2 * 2) != 0);
            goto LAB_140025af8;
          }
          *ppuVar3[1] = *(int *)((longlong)local_418 + (ulonglong)(uint)local_418[2]) != 0;
        }
        else {
          if ((local_418[1] != *(int *)(ppuVar3 + 2)) ||
             (local_418[3] != *(uint *)((longlong)ppuVar3 + 0x14))) {
            puVar4 = *ppuVar3;
            lVar2 = -1;
            do {
              lVar2 = lVar2 + 1;
            } while (*(short *)(puVar4 + lVar2 * 2) != 0);
            goto LAB_140025af8;
          }
          memcpy(ppuVar3[1],(void *)((longlong)local_418 + (ulonglong)(uint)local_418[2]),
                 (ulonglong)(uint)local_418[3]);
        }
LAB_140025b13:
        ppuVar3 = ppuVar3 + 3;
        puVar4 = *ppuVar3;
      }
      ZwClose(local_468);
    }
    ZwClose(local_478);
  }
  return;
}


