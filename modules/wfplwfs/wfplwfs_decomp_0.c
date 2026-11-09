
===== _tlgKeywordOn @ 140001008 =====

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



===== _tlgWriteTransfer_EtwWriteTransfer @ 140001034 =====

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



===== _tlgCreate1Sz_char @ 1400010dc =====

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



===== L2FlowsManagerTimerCallback @ 140001110 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void L2FlowsManagerTimerCallback(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int *piVar2;
  longlong lVar3;
  int iVar4;
  bool bVar5;
  bool bVar6;
  char cVar7;
  longlong lVar8;
  undefined8 *puVar9;
  longlong lVar10;
  bool bVar11;
  undefined1 auStack_b8 [32];
  undefined1 local_98 [8];
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined4 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_b8;
  local_80 = 0;
  local_68 = 0;
  local_50 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_38 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_48 = 0;
  uStack_40 = 0;
  KeAcquireSpinLockAtDpcLevel(param_2 + 0x120);
  bVar5 = true;
  lVar3 = param_2 + 0x128;
  if (param_1 == param_2 + 0xa0) {
    RtlUpdateCurrentTimerWheelTick
              (lVar3,(-(uint)(*(char *)(param_2 + 0x774) != '\0') & 0x13) + 1 +
                     *(int *)(param_2 + 300));
  }
  lVar8 = RtlGetNextExpiredTimerWheelEntry(lVar3);
  while (bVar6 = false, lVar8 != 0) {
    lVar1 = lVar8 + -0x58;
    local_98[0] = 0;
    bVar11 = false;
    KeAcquireSpinLockAtDpcLevel(lVar8 + -8);
    if ((*(int *)(lVar8 + 0x14) == 0) || (0 < *(int *)(lVar8 + 0x14) - *(int *)(lVar8 + 0x10))) {
      RtlReturnTimerWheelEntry(lVar3,lVar8);
    }
    else {
      bVar6 = true;
      cVar7 = RtlCleanupTimerWheelEntry(lVar3,lVar8,local_98);
      bVar11 = cVar7 != '\0';
      if (bVar11) {
        LOCK();
        *(int *)(lVar8 + 0x18) = *(int *)(lVar8 + 0x18) + -1;
        UNLOCK();
      }
      LOCK();
      *(int *)(lVar8 + 0x18) = *(int *)(lVar8 + 0x18) + 2;
      UNLOCK();
    }
    KeReleaseSpinLockFromDpcLevel(lVar8 + -8);
    if (bVar6) {
      KeReleaseSpinLockFromDpcLevel(param_2 + 0x120);
      if (bVar11) {
        puVar9 = (undefined8 *)(lVar8 + 0x20);
        lVar10 = 2;
        do {
          if ((code *)puVar9[1] != (code *)0x0) {
            (*(code *)puVar9[1])(0,lVar1,*puVar9);
          }
          puVar9 = puVar9 + 2;
          lVar10 = lVar10 + -1;
        } while (lVar10 != 0);
      }
      KeAcquireInStackQueuedSpinLockAtDpcLevel(param_2 + 0x40,&local_60);
      do {
      } while (*(int *)(param_2 + 0x48) != 0);
      KeAcquireInStackQueuedSpinLockAtDpcLevel(param_2,&local_78);
      do {
      } while (*(int *)(param_2 + 8) != 0);
      L2pRemoveFlowFromHashTables(param_2,lVar1);
      KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_78);
      KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_60);
      LOCK();
      piVar2 = (int *)(lVar8 + 0x18);
      iVar4 = *piVar2;
      *piVar2 = *piVar2 + -2;
      UNLOCK();
      if (iVar4 == 3) {
        PplFreeToLookasideList(*(longlong *)(param_2 + 0x760),lVar1);
      }
      KeAcquireSpinLockAtDpcLevel(param_2 + 0x120);
    }
    KeQueryDpcWatchdogInformation(&local_48);
    if (((int)uStack_40 != 0) && (uStack_40._4_4_ < (uint)((int)uStack_40 * 0x19) / 100)) break;
    if (((int)local_48 != 0) && (local_48._4_4_ < (uint)((int)local_48 * 0x19) / 100)) {
      KeInsertQueueDpc(param_2 + 0xe0,0,0);
      KeReleaseSpinLockFromDpcLevel(param_2 + 0x120);
      return;
    }
    lVar8 = RtlGetNextExpiredTimerWheelEntry(lVar3);
  }
  KeReleaseSpinLockFromDpcLevel(param_2 + 0x120);
  if (lVar8 == 0) {
    *(undefined4 *)(param_2 + 0x770) = 0;
  }
  else {
    *(int *)(param_2 + 0x770) = *(int *)(param_2 + 0x770) + 1;
  }
  if (*(longlong *)(param_2 + 0x50) != 0) {
    RtlAcquireWriteLockAtDpcLevel(param_2 + 0x40);
    L2pBalanceHashtable(*(longlong *)(param_2 + 0x50));
    KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_90);
  }
  KeAcquireInStackQueuedSpinLockAtDpcLevel(param_2,&local_90);
  do {
  } while (*(int *)(param_2 + 8) != 0);
  L2pBalanceHashtable(param_2 + 0x10);
  if ((*(int *)(param_2 + 0x24) == 0) && (bVar5 = false, *(char *)(param_2 + 0x774) != '\0')) {
    KeSetEvent(param_2 + 0x778,0,0);
  }
  KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_90);
  if (bVar5) {
    L2pStartTimer(param_2);
  }
  return;
}



===== L2pBalanceHashtable @ 1400014f0 =====

ulonglong L2pBalanceHashtable(longlong param_1)

{
  ulonglong uVar1;
  uint uVar2;
  
  if (*(uint *)(param_1 + 0x18) * 8 < *(uint *)(param_1 + 0x14)) {
    do {
      uVar1 = RtlExpandHashTable(param_1);
      if ((char)uVar1 == '\0') {
        return uVar1;
      }
      uVar2 = *(int *)(param_1 + 0x18) * 8;
      uVar1 = (ulonglong)uVar2;
    } while (uVar2 < *(uint *)(param_1 + 0x14));
  }
  else {
    uVar2 = *(int *)(param_1 + 8) * 0x19;
    uVar1 = (ulonglong)uVar2 * 0x51eb851f & 0xffffffff;
    if (*(uint *)(param_1 + 0x18) < uVar2 / 100) {
      do {
        uVar1 = RtlContractHashTable(param_1);
        if ((char)uVar1 == '\0') {
          return uVar1;
        }
        uVar2 = *(int *)(param_1 + 8) * 0x19;
        uVar1 = (ulonglong)uVar2 * 0x51eb851f & 0xffffffff;
      } while (*(uint *)(param_1 + 0x18) < uVar2 / 100);
    }
  }
  return uVar1;
}



===== L2pStartTimer @ 140001574 =====

void L2pStartTimer(longlong param_1)

{
  KeSetCoalescableTimer(param_1 + 0x60,0xffffffffff676980,0,200,param_1 + 0xa0);
  return;
}



===== L2pRemoveFlowFromHashTables @ 1400015b0 =====

void L2pRemoveFlowFromHashTables(longlong param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 8) & 2) != 0) {
    RtlRemoveEntryHashTable(*(undefined8 *)(param_1 + 0x50),param_2 + 0x28,0);
    *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) & 0xfffffffd;
    LOCK();
    *(int *)(param_2 + 0x70) = *(int *)(param_2 + 0x70) + -2;
    UNLOCK();
  }
  if ((*(uint *)(param_2 + 8) & 1) != 0) {
    RtlRemoveEntryHashTable(param_1 + 0x10,param_2 + 0x10,0);
    *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) & 0xfffffffe;
    LOCK();
    *(int *)(param_2 + 0x70) = *(int *)(param_2 + 0x70) + -2;
    UNLOCK();
  }
  return;
}



===== L2pDiagnosePacketDrop @ 140001624 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void L2pDiagnosePacketDrop(longlong param_1,ushort param_2,longlong param_3,undefined8 param_4)

{
  ulonglong uVar1;
  undefined1 auStack_3c8 [32];
  undefined1 local_3a8 [8];
  undefined2 local_3a0;
  undefined2 local_320;
  ulonglong local_2a0;
  undefined8 local_290;
  ulonglong local_238;
  undefined1 local_e8;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_3c8;
  memset(local_3a8,0,0x368);
  uVar1 = *(ulonglong *)(param_1 + 0xf8);
  local_3a0 = 0x21;
  local_320 = 0x21;
  L2pFillCommonAuditDiagEventInfo(param_1,param_2,param_3,(longlong)local_3a8);
  local_238 = uVar1 & 0x7fffffffffffffff;
  local_e8 = 1;
  local_2a0 = (ulonglong)param_2;
  local_290 = param_4;
  KfdDiagnoseEvent(local_3a8);
  return;
}



===== L2pAuditPacketDrop @ 1400016f4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void L2pAuditPacketDrop(ushort param_1,longlong param_2,undefined8 param_3)

{
  undefined1 auStack_3a8 [32];
  undefined4 local_388 [2];
  undefined2 local_380;
  undefined2 local_300;
  ulonglong local_280;
  undefined8 local_270;
  undefined4 local_268;
  undefined2 local_230;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_3a8;
  memset(local_388,0,0x368);
  local_380 = 0x21;
  local_300 = 0x21;
  L2pFillCommonAuditDiagEventInfo(0,param_1,param_2,(longlong)local_388);
  local_268 = 0x141e;
  local_230 = 0x10;
  local_388[0] = 1;
  local_280 = (ulonglong)param_1;
  local_270 = param_3;
  KfdAuditEvent(local_388);
  return;
}



===== L2pFillCommonAuditDiagEventInfo @ 1400017c4 =====

void L2pFillCommonAuditDiagEventInfo
               (longlong param_1,short param_2,longlong param_3,longlong param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  
  *(undefined2 *)(param_4 + 8) = 0x21;
  *(undefined2 *)(param_4 + 0x88) = 0x21;
  if ((param_2 == 0x39) || (param_2 == 0x38)) {
    *(uint *)(param_4 + 0x110) = (uint)*(ushort *)(param_3 + 0x58);
    puVar1 = *(undefined4 **)(param_3 + 0x18);
    *(undefined4 *)(param_4 + 10) = *puVar1;
    *(undefined2 *)(param_4 + 0xe) = *(undefined2 *)(puVar1 + 1);
    puVar1 = *(undefined4 **)(param_3 + 0x28);
    *(undefined4 *)(param_4 + 0x8a) = *puVar1;
    *(undefined2 *)(param_4 + 0x8e) = *(undefined2 *)(puVar1 + 1);
    if (*(int *)(param_3 + 0x60) != 0) {
      *(undefined2 *)(param_4 + 0x198) = *(undefined2 *)(param_3 + 0x68);
    }
    *(undefined8 *)(param_4 + 0x178) = **(undefined8 **)(param_3 + 0x78);
  }
  else {
    *(undefined4 *)(param_4 + 0x19c) = *(undefined4 *)(param_3 + 8);
    *(undefined8 *)(param_4 + 0x178) = **(undefined8 **)(param_3 + 0x28);
    *(undefined4 *)(param_4 + 0x194) = *(undefined4 *)(param_3 + 0x38);
    *(undefined4 *)(param_4 + 0x1a0) = *(undefined4 *)(param_3 + 0x58);
  }
  if (param_1 != 0) {
    uVar2 = *(uint *)(*(longlong *)(param_1 + 8) + 0x18);
    if (0x100 < uVar2) {
      uVar2 = 0x100;
    }
    puVar1 = (undefined4 *)NdisGetDataBuffer(*(longlong *)(param_1 + 8),uVar2,0,1,0);
    *(uint *)(param_4 + 0x1a4) = uVar2;
    if (puVar1 == (undefined4 *)0x0) {
      NdisGetDataBuffer(*(undefined8 *)(param_1 + 8),uVar2,(undefined4 *)(param_4 + 0x1a8),1,0);
    }
    else {
      *(undefined4 *)(param_4 + 0x1a8) = *puVar1;
    }
  }
  return;
}



===== L2CheckAndCompleteInjectedNetBufferLists @ 140001920 =====

void L2CheckAndCompleteInjectedNetBufferLists
               (int param_1,undefined8 *param_2,char param_3,int *param_4,longlong param_5)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  longlong lVar5;
  
  puVar2 = (undefined8 *)*param_2;
joined_r0x000140001947:
  do {
    do {
      puVar3 = param_2;
      param_2 = puVar2;
      if (param_2 == (undefined8 *)0x0) {
        return;
      }
      puVar2 = (undefined8 *)*param_2;
    } while ((param_2[0xf] != param_5) || (uVar4 = WfpNblInfoGetFlags(param_2), (uVar4 & 2) == 0));
    lVar5 = (ulonglong)*(ushort *)(param_2[2] + 10) + param_2[2];
    iVar1 = *(int *)(*(longlong *)(lVar5 + 0x18) + 0x38);
    if (iVar1 == 0) goto LAB_1400019e5;
  } while (((iVar1 != 1) || (param_1 != 1)) && ((iVar1 != 2 || (param_1 != 2))));
  goto LAB_1400019c7;
LAB_1400019e5:
  if (param_1 == 0) {
LAB_1400019c7:
    if ((((param_3 != '\0') && (iVar1 == 2)) && (param_1 == 2)) &&
       ((*(short *)(lVar5 + 0x20) == 0x48 && (param_4 != (int *)0x0)))) {
      *param_4 = *param_4 + 1;
    }
    L2CompleteInjectedNetBufferLists(param_2);
    *puVar3 = puVar2;
    param_2 = puVar3;
  }
  goto joined_r0x000140001947;
}



===== L2CompleteInjectedNetBufferLists @ 140001a10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void L2CompleteInjectedNetBufferLists(undefined8 *param_1)

{
  code *pcVar1;
  undefined8 *puVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  
  puVar4 = (undefined8 *)param_1[3];
  pcVar1 = *(code **)((ulonglong)*(ushort *)(param_1[2] + 10) + 0x38 + param_1[2]);
  *param_1 = 0;
  (*pcVar1)(param_1,1);
  while( true ) {
    if (puVar4 == (undefined8 *)0x0) {
      return;
    }
    uVar3 = WfpNblInfoGetFlags(puVar4);
    if ((uVar3 & 2) == 0) break;
    puVar2 = (undefined8 *)puVar4[3];
    pcVar1 = *(code **)((ulonglong)*(ushort *)(puVar4[2] + 10) + 0x38 + puVar4[2]);
    *puVar4 = 0;
    if (pcVar1 == (code *)0x0) {
      L2DereferenceNetBufferListContext((longlong)puVar4);
      return;
    }
    (*pcVar1)(puVar4,1);
    puVar4 = puVar2;
  }
  return;
}



===== LwfLowerDetach @ 140001aa0 =====

void LwfLowerDetach(longlong *param_1)

{
  int *piVar1;
  int iVar2;
  code *pcVar3;
  undefined1 uVar4;
  longlong lVar5;
  longlong *plVar6;
  
  uVar4 = KeAcquireSpinLockRaiseToDpc(&DAT_14002ce90);
  lVar5 = *param_1;
  plVar6 = (longlong *)param_1[1];
  if ((*(longlong **)(lVar5 + 8) != param_1) || ((longlong *)*plVar6 != param_1)) {
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(3);
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  *plVar6 = lVar5;
  *(longlong **)(lVar5 + 8) = plVar6;
  DAT_14002cec0 = DAT_14002cec0 + -1;
  KeReleaseSpinLock(&DAT_14002ce90,CONCAT71((int7)((ulonglong)plVar6 >> 8),uVar4));
  uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 6);
  if (*(int *)((longlong)param_1 + 0x5c) == 0x10) {
    plVar6 = param_1 + 0x2d;
    lVar5 = 0xc;
    do {
      L2PurgeLayerClassifyCache(plVar6 + -1);
      L2PurgeLayerClassifyCache(plVar6);
      plVar6 = plVar6 + 6;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
  }
  else {
    L2PurgeLayerClassifyCache(param_1 + 0x2a);
    L2PurgeLayerClassifyCache(param_1 + 0x2b);
  }
  KeReleaseSpinLock(param_1 + 6,uVar4);
  LOCK();
  piVar1 = (int *)((longlong)param_1 + 0x14c);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 2) {
    if (param_1[0x79] != 0) {
      ExFreePoolWithTag(param_1[0x79],0x67326c57);
      param_1[0x79] = 0;
      *(undefined4 *)(param_1 + 0x7a) = 0;
      *(undefined1 *)((longlong)param_1 + 0x3d4) = 0;
    }
    ExFreePoolWithTag(param_1,0x6c326c57);
  }
  return;
}



===== L2p802_3FlowEventCallback @ 140001c10 =====

undefined1 L2p802_3FlowEventCallback(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  longlong local_res18 [2];
  
  local_res18[0] = param_3;
  L2PurgeLayerClassifyCache(local_res18);
  return 1;
}



===== LwfLowerOidRequestComplete @ 140001c40 =====

void LwfLowerOidRequestComplete(longlong param_1,longlong param_2,int param_3)

{
  int iVar1;
  longlong lVar2;
  undefined1 uVar3;
  byte bVar4;
  undefined4 uVar5;
  longlong lVar6;
  void *_Dst;
  ulonglong uVar7;
  undefined8 uVar8;
  
  _Dst = (void *)0x0;
  uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x30);
  lVar6 = *(longlong *)(param_2 + 0xd8);
  *(undefined8 *)(param_2 + 0xd8) = 0;
  if (lVar6 != 0) {
    *(undefined8 *)(param_1 + 0x140) = 0;
  }
  KeReleaseSpinLock(param_1 + 0x30,uVar3);
  iVar1 = *(int *)(param_2 + 4);
  if ((iVar1 == 2) || (iVar1 == 0)) {
    if (lVar6 != 0) {
      *(undefined4 *)(lVar6 + 0x34) = *(undefined4 *)(param_2 + 0x34);
      *(undefined4 *)(lVar6 + 0x38) = *(undefined4 *)(param_2 + 0x38);
    }
    if (param_3 == 0) {
      if (*(int *)(param_2 + 0x20) == 0xd010308) {
        lVar2 = *(longlong *)(param_2 + 0x28);
        uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x30);
        if (*(int *)(param_1 + 0x170 + (ulonglong)*(uint *)(param_2 + 8) * 0x30) == 0) {
          *(undefined4 *)(param_1 + 0x170 + (ulonglong)*(uint *)(param_2 + 8) * 0x30) =
               *(undefined4 *)(lVar2 + 4);
        }
        L2PurgeLayerClassifyCache
                  ((longlong *)((ulonglong)*(uint *)(param_2 + 8) * 0x30 + 0x160 + param_1));
        L2PurgeLayerClassifyCache
                  ((longlong *)((ulonglong)*(uint *)(param_2 + 8) * 0x30 + 0x168 + param_1));
LAB_140001f08:
        KeReleaseSpinLock(param_1 + 0x30,uVar3);
      }
      else if (((*(int *)(param_2 + 0x20) == 0x10101) && (*(uint *)(param_1 + 0x5c) < 0x13)) &&
              ((0x50200U >> (*(uint *)(param_1 + 0x5c) & 0x1f) & 1) != 0)) {
        _Dst = (void *)ExAllocatePool2(0x40,(ulonglong)*(uint *)(param_2 + 0x30) + 4,0x67326c57);
        if (_Dst == (void *)0x0) {
          param_3 = -0x3fffff66;
        }
        else {
          memmove(_Dst,*(void **)(param_2 + 0x28),(ulonglong)*(uint *)(param_2 + 0x30));
          *(undefined4 *)((ulonglong)*(uint *)(param_2 + 0x30) + (longlong)_Dst) = 0x2021e;
        }
      }
    }
LAB_140001cef:
    if (lVar6 == 0) {
LAB_140001d8d:
      iVar1 = *(int *)(param_1 + 0x3c);
      ExFreePoolWithTag(param_2,0x67326c57);
      if (param_3 == 0) {
        *(undefined1 *)(param_1 + 0x40) = 0;
        uVar5 = 3;
      }
      else {
        uVar5 = 1;
      }
      *(undefined4 *)(param_1 + 0x3c) = uVar5;
      if (iVar1 == 2) {
        bVar4 = KeGetCurrentIrql();
        if (bVar4 < 2) {
          NdisFRestartComplete(*(undefined8 *)(param_1 + 0x48),param_3);
        }
        else {
          *(int *)(param_1 + 0x3d8) = param_3;
          uVar8 = DAT_14002ce88;
          lVar6 = IoAllocateWorkItem();
          if (lVar6 == 0) {
            WfpReportSysErrorAsNtStatus(uVar8,"IoAllocateWorkItem",-0x3fffffe9);
          }
          else {
            uVar7 = RoReferenceEx((uint *)(param_1 + 0x14c));
            if ((char)uVar7 == '\0') {
              IoFreeWorkItem(lVar6);
              *(undefined4 *)(param_1 + 0x3d8) = 0;
            }
            else {
              IoQueueWorkItemEx(lVar6,L2RestartCompleteWorkRoutine,1,param_1);
            }
          }
        }
      }
      goto LAB_140001d21;
    }
  }
  else {
    if (iVar1 == 1) {
      if (lVar6 != 0) {
        *(undefined4 *)(lVar6 + 0x34) = *(undefined4 *)(param_2 + 0x34);
        *(undefined4 *)(lVar6 + 0x38) = *(undefined4 *)(param_2 + 0x38);
      }
      if ((param_3 == 0) && (*(int *)(param_2 + 0x20) == 0xd010308)) {
        lVar2 = *(longlong *)(param_2 + 0x28);
        uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x30);
        *(undefined4 *)(param_1 + 0x170 + (ulonglong)*(uint *)(param_2 + 8) * 0x30) =
             *(undefined4 *)(lVar2 + 4);
        L2PurgeLayerClassifyCache
                  ((longlong *)((ulonglong)*(uint *)(param_2 + 8) * 0x30 + 0x160 + param_1));
        L2PurgeLayerClassifyCache
                  ((longlong *)((ulonglong)*(uint *)(param_2 + 8) * 0x30 + 0x168 + param_1));
        goto LAB_140001f08;
      }
      goto LAB_140001cef;
    }
    if (iVar1 != 0xc) goto LAB_140001cef;
    if (lVar6 == 0) goto LAB_140001d8d;
    *(undefined4 *)(lVar6 + 0x34) = *(undefined4 *)(param_2 + 0x34);
    *(undefined4 *)(lVar6 + 0x40) = *(undefined4 *)(param_2 + 0x40);
    *(undefined4 *)(lVar6 + 0x44) = *(undefined4 *)(param_2 + 0x44);
    *(undefined4 *)(lVar6 + 0x3c) = *(undefined4 *)(param_2 + 0x3c);
  }
  NdisFreeCloneOidRequest(*(undefined8 *)(param_1 + 0x48),param_2);
  NdisFOidRequestComplete(*(undefined8 *)(param_1 + 0x48),lVar6,param_3);
LAB_140001d21:
  if (_Dst != (void *)0x0) {
    ExFreePoolWithTag(_Dst,0x67326c57);
  }
  return;
}



===== L2PurgeLayerClassifyCache @ 14000201c =====

void L2PurgeLayerClassifyCache(longlong *param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  
  lVar3 = *param_1;
  if (lVar3 != 0) {
    if ((*(byte *)(lVar3 + 0x30) & 1) == 0) {
      LOCK();
      piVar1 = (int *)(lVar3 + 0x30);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 2) {
        KfdReleaseCachedFilters();
        L2FreeLayerClassifyCache(param_1);
      }
    }
    *param_1 = 0;
  }
  return;
}



===== L2AuditAndDiagPacketDrop @ 14000206c =====

void L2AuditAndDiagPacketDrop(ushort param_1,longlong param_2,longlong param_3,longlong param_4)

{
  L2pAuditPacketDrop(param_1,param_2,*(undefined8 *)(param_4 + 0x10));
  if ((*(uint *)(param_4 + 0x20) & 0x10000000) != 0) {
    L2pAuditPacketVeto(param_1,param_2,*(undefined8 *)(param_4 + 0x10));
  }
  L2pDiagnosePacketDrop(param_3,param_1,param_2,*(undefined8 *)(param_4 + 0x10));
  return;
}



===== L2FlowAssociateContext @ 1400020e0 =====

undefined8
L2FlowAssociateContext(longlong param_1,int param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uVar1;
  undefined8 uVar2;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x50);
  if ((*(byte *)(param_1 + 0x70) & 1) == 0) {
    *(undefined8 *)(param_1 + ((longlong)param_2 + 8) * 0x10) = param_3;
    *(undefined8 *)(param_1 + 0x78 + (longlong)param_2 * 0x10) = param_4;
    uVar2 = 0;
  }
  else {
    uVar2 = 0xc0000001;
  }
  KeReleaseSpinLock(param_1 + 0x50,uVar1);
  return uVar2;
}



===== L2CreateLayerClassifyCache @ 140002174 =====

ulonglong L2CreateLayerClassifyCache
                    (longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
                    undefined8 *param_5)

{
  longlong *plVar1;
  longlong lVar2;
  undefined4 uVar3;
  longlong *plVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  longlong local_res10;
  longlong *local_38 [2];
  
  uVar3 = *(undefined4 *)(param_2 + 0x210);
  uVar6 = 0;
  plVar1 = *(longlong **)(param_2 + 0x200);
  local_res10 = 0;
  plVar4 = (longlong *)ExAllocatePool2(0x40,0x38,0x63326c57);
  if (plVar4 == (longlong *)0x0) {
    uVar6 = 0xc0000017;
  }
  else {
    local_38[0] = plVar4;
    uVar5 = FeCopyIncomingValues(param_3,0,&local_res10);
    if (uVar5 == 0) {
      *(undefined4 *)((longlong)plVar4 + 0x2c) = uVar3;
      plVar4[4] = local_res10;
      if (param_1 == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = *(undefined4 *)(param_1 + 0x28);
      }
      *(undefined4 *)(plVar4 + 5) = uVar3;
      if ((longlong *)*plVar1 == plVar1) {
        plVar4[1] = (longlong)plVar4;
        *plVar4 = (longlong)plVar4;
      }
      else {
        lVar2 = plVar1[1];
        *plVar4 = *plVar1;
        plVar4[1] = lVar2;
        *(longlong **)(*plVar4 + 8) = plVar4;
        *(longlong **)plVar4[1] = plVar4;
        plVar1[1] = (longlong)plVar1;
        *plVar1 = (longlong)plVar1;
      }
      *(undefined4 *)(plVar4 + 2) = *(undefined4 *)(param_2 + 0x208);
      *(undefined4 *)((longlong)plVar4 + 0x14) = *(undefined4 *)(param_2 + 0x20c);
      *(undefined4 *)(plVar4 + 3) = *(undefined4 *)(param_2 + 0x21c);
      *(undefined4 *)(plVar4 + 6) = 2;
      *param_5 = plVar4;
    }
    else {
      L2FreeLayerClassifyCache((longlong *)local_38);
      uVar6 = uVar5 & 0xffffffff;
    }
  }
  return uVar6;
}



===== L2CreateMacFlow @ 140002298 =====

undefined8
L2CreateMacFlow(undefined8 param_1,ushort param_2,byte *param_3,byte *param_4,ushort param_5,
               ulonglong param_6,int param_7,undefined8 param_8,undefined8 param_9,
               undefined8 *param_10)

{
  longlong lVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  undefined8 uVar4;
  bool bVar5;
  longlong local_res8;
  ushort local_res10;
  undefined8 in_stack_ffffffffffffff70;
  int iVar6;
  undefined4 in_stack_ffffffffffffff84;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  
  uVar4 = 0;
  local_res8 = 0;
  local_58 = 0;
  local_40 = 0;
  bVar5 = false;
  local_68 = 0;
  uStack_60 = 0;
  local_50 = 0;
  uStack_48 = 0;
  if (2 < DAT_14002ce50) {
    return 0xc0000001;
  }
  local_res10 = param_2;
  L2pComputeMacFlowHashSignature
            ((ulonglong)param_2,param_3,param_4,param_5,param_6,
             CONCAT44((int)((ulonglong)in_stack_ffffffffffffff70 >> 0x20),param_7),&local_res8);
  KeAcquireInStackQueuedSpinLock(&DAT_14002c720,&local_50);
  do {
  } while (DAT_14002c728 != 0);
  puVar3 = &gL2FlowsMgr;
  KeAcquireInStackQueuedSpinLockAtDpcLevel(&gL2FlowsMgr,&local_68);
  lVar1 = local_res8;
  do {
  } while (DAT_14002c6e8 != 0);
  if (DAT_14002ce54 == '\0') {
    iVar6 = param_7;
    puVar2 = (undefined4 *)
             L2pLookupMacFlow(puVar3,local_res8,param_2,param_3,param_4,param_5,param_6,param_7);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = L2pCreateMacFlow(puVar3,local_res10,(undefined4 *)param_3,(undefined4 *)param_4,
                                param_5,param_6,param_7,CONCAT44(in_stack_ffffffffffffff84,iVar6),
                                lVar1);
      if (puVar2 == (undefined4 *)0x0) {
        uVar4 = 0xc0000017;
        goto LAB_140002457;
      }
      RoReferenceEx(puVar2 + 0x1c);
      bVar5 = DAT_14002c704 == 1;
    }
    KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_68);
    KeReleaseInStackQueuedSpinLock(&local_50);
    L2RefreshFlow(0x14002c6e0,(longlong)puVar2);
    if (bVar5) {
      L2pStartTimer(0x14002c6e0);
    }
    *param_10 = puVar2;
  }
  else {
    uVar4 = 0xc0000001;
LAB_140002457:
    KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_68);
    KeReleaseInStackQueuedSpinLock(&local_50);
  }
  return uVar4;
}



===== L2pComputeMacFlowHashSignature @ 140002490 =====

void L2pComputeMacFlowHashSignature
               (ulonglong param_1,byte *param_2,byte *param_3,ushort param_4,ulonglong param_5,
               ulonglong param_6,longlong *param_7)

{
  byte bStackX_21;
  
  bStackX_21 = (byte)(param_4 >> 8);
  *param_7 = (((((((((((((((((((((((((((param_1 & 0xff) * 0x25 + (param_1 >> 8 & 0xff)) * 0x25 +
                                     (ulonglong)*param_2) * 0x25 + (ulonglong)param_2[1]) * 0x25 +
                                   (ulonglong)param_2[2]) * 0x25 + (ulonglong)param_2[3]) * 0x25 +
                                 (ulonglong)param_2[4]) * 0x25 + (ulonglong)param_2[5]) * 0x25 +
                               (ulonglong)*param_3) * 0x25 + (ulonglong)param_3[1]) * 0x25 +
                             (ulonglong)param_3[2]) * 0x25 + (ulonglong)param_3[3]) * 0x25 +
                           (ulonglong)param_3[4]) * 0x25 + (ulonglong)param_3[5]) * 0x25 +
                         (ulonglong)(byte)param_4) * 0x25 + (ulonglong)bStackX_21) * 0x25 +
                       (param_5 & 0xff)) * 0x25 + (param_5 >> 8 & 0xff)) * 0x25 +
                     (param_5 >> 0x10 & 0xff)) * 0x25 + (param_5 >> 0x18 & 0xff)) * 0x25 +
                   (param_5 >> 0x20 & 0xff)) * 0x25 + (param_5 >> 0x28 & 0xff)) * 0x25 +
                 (param_5 >> 0x30 & 0xff)) * 0x25 + (param_5 >> 0x38)) * 0x25 + (param_6 & 0xff)) *
               0x25 + (param_6 >> 8 & 0xff)) * 0x25 + (param_6 >> 0x10 & 0xff)) * 0x25 +
             (param_6 >> 0x18 & 0xff);
  return;
}



===== L2pCreateMacFlow @ 1400025f4 =====

undefined4 *
L2pCreateMacFlow(undefined8 param_1,undefined2 param_2,undefined4 *param_3,undefined4 *param_4,
                undefined2 param_5,undefined8 param_6,undefined4 param_7,undefined8 param_8,
                longlong param_9)

{
  undefined4 *puVar1;
  undefined8 *puVar2;
  longlong lVar3;
  
  puVar1 = (undefined4 *)PplAllocateFromLookasideList(DAT_14002ce40);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    *(undefined2 *)(puVar1 + 1) = param_2;
    *(undefined2 *)((longlong)puVar1 + 6) = param_5;
    *(undefined8 *)(puVar1 + 0x2a) = param_6;
    puVar1[0x2c] = param_7;
    puVar1[0x26] = *param_3;
    *(undefined2 *)(puVar1 + 0x27) = *(undefined2 *)(param_3 + 1);
    lVar3 = 2;
    *(undefined4 *)((longlong)puVar1 + 0x9e) = *param_4;
    *(undefined2 *)((longlong)puVar1 + 0xa2) = *(undefined2 *)(param_4 + 1);
    puVar2 = (undefined8 *)(puVar1 + 0x20);
    puVar1[0x12] = 0x3c;
    puVar1[2] = 0;
    do {
      puVar2[-1] = 0;
      *puVar2 = 0;
      puVar2 = puVar2 + 2;
      lVar3 = lVar3 + -1;
    } while (lVar3 != 0);
    *(undefined8 *)(puVar1 + 0x16) = 0;
    *(undefined8 *)(puVar1 + 0x18) = 0;
    *(undefined8 *)(puVar1 + 0x1a) = 0;
    KeInitializeSpinLock(puVar1 + 0x14);
    RtlInitializeTimerWheelEntry(0,puVar1 + 0x16,0,0);
    puVar1[0x1c] = 2;
    RtlInsertEntryHashTable(&DAT_14002c6f0,puVar1 + 4,param_9 << ((byte)DAT_14002c718 & 0x3f),0);
    puVar1[2] = puVar1[2] | 1;
    RoReferenceEx(puVar1 + 0x1c);
  }
  return puVar1;
}



===== PplAllocateFromLookasideList @ 14000272c =====

void PplAllocateFromLookasideList(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = PplpRetrieveListIndex(param_1,SystemReserved1[0x12]._4_4_);
  ExAllocateFromLookasideListEx(lVar1);
  return;
}



===== L2RefreshFlow @ 140002760 =====

void L2RefreshFlow(longlong param_1,longlong param_2)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 300) + *(int *)(param_2 + 0x48);
  if (*(char *)(param_1 + 0x774) == '\0') {
    uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x120);
    KeAcquireSpinLockAtDpcLevel(param_2 + 0x50);
    if ((*(byte *)(param_2 + 0x70) & 1) == 0) {
      if (iVar2 == 0) {
        iVar2 = 1;
      }
      *(int *)(param_2 + 0x6c) = iVar2;
      if ((*(int *)(param_2 + 0x68) == 0) || (iVar2 - *(int *)(param_2 + 0x68) < 0)) {
        RtlIndicateTimerWheelEntryTimerStart(param_1 + 0x128,param_2 + 0x58);
      }
    }
    KeReleaseSpinLockFromDpcLevel(param_2 + 0x50);
    KeReleaseSpinLock(param_1 + 0x120,uVar1);
  }
  return;
}



===== PplpRetrieveListIndex @ 140002838 =====

longlong PplpRetrieveListIndex(longlong param_1,int param_2)

{
  longlong lVar1;
  
  lVar1 = (ulonglong)(param_2 + 1) * 0x80 + param_1;
  if (*(char *)(lVar1 + 0xb0) == '\0') {
    PplpLazyInitializeLookasideList(param_1,lVar1 + 0x40);
  }
  return lVar1 + 0x40;
}



===== L2FreeLayerClassifyCache @ 140002870 =====

void L2FreeLayerClassifyCache(longlong *param_1)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *param_1;
  lVar2 = *(longlong *)(lVar1 + 0x20);
  if (lVar2 != 0) {
    ExFreePoolWithTag(lVar2,0);
  }
  ExFreePoolWithTag(lVar1,0x63326c57);
  *param_1 = 0;
  return;
}



===== L2ReleaseFlow @ 1400028d0 =====

void L2ReleaseFlow(longlong param_1,longlong *param_2)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  
  lVar3 = *param_2;
  LOCK();
  piVar1 = (int *)(lVar3 + 0x70);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -2;
  UNLOCK();
  if (iVar2 == 3) {
    PplFreeToLookasideList(*(longlong *)(param_1 + 0x760),lVar3);
  }
  *param_2 = 0;
  return;
}



===== PplFreeToLookasideList @ 14000290c =====

void PplFreeToLookasideList(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  
  lVar1 = PplpRetrieveListIndex(param_1,SystemReserved1[0x12]._4_4_);
  ExFreeToLookasideListEx(lVar1,param_2);
  return;
}



===== L2pDeepCloneNetBufferListCompletionFn @ 140002950 =====

void L2pDeepCloneNetBufferListCompletionFn(longlong param_1)

{
  L2DereferenceNetBufferListContext(param_1);
  return;
}



===== L2ReferenceNetBufferListContext @ 140002970 =====

void L2ReferenceNetBufferListContext(longlong param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  lVar3 = *(longlong *)(param_1 + 0x10);
  uVar4 = (ulonglong)*(ushort *)(lVar3 + 10);
  LOCK();
  piVar1 = (int *)(uVar4 + 0x4c + lVar3);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  if ((DAT_14002cf40 & 0x10) != 0) {
    L2InsertNetBufferListReferenceRecord(*(longlong *)(uVar4 + 0x18 + lVar3),param_1,iVar2 + 1);
  }
  if (*(char *)(uVar4 + 0x48 + lVar3) == '\0') {
    *(undefined1 *)(uVar4 + 0x48 + lVar3) = 1;
  }
  return;
}



===== L2DereferenceNetBufferListContext @ 1400029d0 =====

void L2DereferenceNetBufferListContext(longlong param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong lVar5;
  bool bVar6;
  longlong local_res8;
  
  bVar6 = false;
  lVar5 = (ulonglong)*(ushort *)(*(longlong *)(param_1 + 0x10) + 10) + *(longlong *)(param_1 + 0x10)
  ;
  local_res8 = *(longlong *)(lVar5 + 0x18);
  if ((DAT_14002cf40 & 0x10) != 0) {
    uVar4 = RoReferenceEx((uint *)(local_res8 + 0x14c));
    bVar6 = (char)uVar4 != '\0';
  }
  lVar3 = local_res8;
  LOCK();
  piVar1 = (int *)(lVar5 + 0x4c);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 + -1 == 0) {
    L2pReturnOrCompleteNetBufferList(param_1,lVar5 + 0x10);
    if (!bVar6) {
      return;
    }
  }
  else {
    if (!bVar6) {
      return;
    }
    L2InsertNetBufferListReferenceRecord(local_res8,param_1,iVar2 + -1);
  }
  LOCK();
  piVar1 = (int *)(lVar3 + 0x14c);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -2;
  UNLOCK();
  if (iVar2 == 3) {
    L2LwfFree(&local_res8);
  }
  return;
}



===== L2pReturnOrCompleteNetBufferList @ 140002a80 =====

void L2pReturnOrCompleteNetBufferList(longlong param_1,longlong param_2)

{
  char cVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  undefined8 uVar6;
  
  lVar5 = *(longlong *)(param_2 + 8);
  sVar2 = *(short *)(param_2 + 0x10);
  iVar3 = *(int *)(param_2 + 0x14);
  iVar4 = *(int *)(param_2 + 0x18);
  uVar6 = *(undefined8 *)(lVar5 + 0x48);
  cVar1 = *(char *)(param_2 + 0x39);
  L2FreeNetBufferListContext(param_1);
  if (cVar1 == '\0') {
    if ((DAT_14002cf40 & 0x10) != 0) {
      L2InsertNetBufferListReferenceRecord(lVar5,param_1,0);
    }
    if (param_1 != 0) {
      if (sVar2 != 0x3a) {
        if (sVar2 == 0x38) {
          if ((iVar3 != 0) && (*(int *)(*(longlong *)(param_1 + 8) + 0x28) == iVar4)) {
            NdisRetreatNetBufferDataStart(*(longlong *)(param_1 + 8),iVar3,0,0);
          }
        }
        else if (sVar2 != 0x49) {
          NdisFSendNetBufferListsComplete(uVar6,param_1,0);
          return;
        }
      }
      NdisFReturnNetBufferLists(uVar6,param_1,0);
    }
  }
  return;
}



===== L2pNativeLayerDirectClassify @ 140002b70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char L2pNativeLayerDirectClassify
               (ushort param_1,char param_2,undefined8 *param_3,undefined8 param_4,longlong param_5,
               uint param_6,uint param_7,int param_8,longlong *param_9,int *param_10,char *param_11,
               longlong *param_12)

{
  char cVar1;
  int iVar2;
  ulonglong uVar3;
  int *piVar4;
  longlong lVar5;
  longlong lVar6;
  short sVar7;
  int iVar8;
  char cVar10;
  undefined1 uVar9;
  undefined1 auStack_358 [32];
  longlong *local_338;
  int *local_330;
  undefined8 *local_328;
  uint local_320;
  char *local_318;
  longlong *local_310;
  undefined8 local_308;
  undefined8 local_2f8;
  undefined1 local_2f0 [216];
  undefined8 local_218;
  undefined1 local_210 [4];
  int local_20c;
  int *local_b8;
  undefined1 local_b0 [104];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_358;
  local_320 = param_6;
  local_318 = param_11;
  local_310 = param_12;
  local_308 = param_4;
  memset(local_2f0,0,0xd8);
  memset(local_210,0,0x158);
  memset(local_b0,0,0x60);
  cVar10 = '\0';
  uVar9 = 0;
  local_328 = (undefined8 *)0x0;
  if ((param_1 == 0x3a) && ((param_7 & 2) != 0)) {
    lVar6 = FwppDeepCloneNetBufferList(param_3,0,0,&local_328);
    if (lVar6 != 0) {
      return '\0';
    }
    NdisCopyReceiveNetBufferListInfo(local_328,param_3);
    iVar8 = 0;
    param_3 = local_328;
    if (local_328 == (undefined8 *)0x0) goto LAB_140002c42;
    uVar9 = 1;
    local_328[0xf] = *(undefined8 *)(param_5 + 0x48);
LAB_140002c5e:
    iVar2 = NdisAllocateNetBufferListContext(param_3,0x40,0x40,0x6e326c57);
    if (iVar2 != 0) {
      if (local_328 != (undefined8 *)0x0) {
        FwppFreeDeepCloneNetBufferList();
      }
      return '\0';
    }
    lVar6 = (ulonglong)*(ushort *)(param_3[2] + 10) + param_3[2];
    *(undefined4 *)(lVar6 + 0x10) = 0x6e326c57;
    *(longlong *)(lVar6 + 0x18) = param_5;
    *(ushort *)(lVar6 + 0x20) = param_1;
    *(undefined1 *)(lVar6 + 0x22) = 1;
    *(undefined8 *)(lVar6 + 0x24) = 0;
    *(undefined8 *)(lVar6 + 0x38) = 0;
    *(undefined8 *)(lVar6 + 0x40) = 0;
    *(undefined1 *)(lVar6 + 0x48) = 0;
    *(undefined1 *)(lVar6 + 0x49) = uVar9;
    RoReferenceEx((uint *)(param_5 + 0x14c));
    uVar3 = WfpNblInfoGetFlags(param_3);
    if ((uVar3 & 2) == 0) {
      WfpNblInfoSetFlags(param_3,2);
      lVar5 = 0;
    }
    else {
      lVar5 = param_3[2] + 0x10 + (ulonglong)*(ushort *)(param_3[2] + 10);
    }
    *(longlong *)(lVar6 + 0x30) = lVar5;
    *(undefined4 *)(lVar6 + 0x4c) = 1;
    cVar10 = '\x01';
  }
  else {
    iVar8 = (int)param_9[3];
LAB_140002c42:
    if (((param_2 == '\0') && (*(int *)((longlong)param_9 + 0x14) != 0)) && (iVar8 == 0))
    goto LAB_140002c5e;
  }
  local_2f8 = 0;
  if ((longlong *)*param_9 == param_9) {
    *param_10 = 0x1002;
    *local_318 = cVar10;
    *local_310 = (longlong)local_328;
    return '\x01';
  }
  local_218 = 0;
  if (param_8 != 0) {
    local_218 = 2;
    local_20c = param_8;
  }
  iVar2 = *(int *)(param_5 + 0x5c);
  if ((iVar2 == 0x10) || (iVar2 == 9)) {
    piVar4 = (int *)((ulonglong)local_320 * 0x30 + 0x174 + param_5);
  }
  else {
    piVar4 = (int *)(param_5 + 0x3a0);
  }
  local_b8 = (int *)0x0;
  if (*piVar4 != 0) {
    local_b8 = piVar4;
  }
  if ((iVar2 == 9) || ((iVar2 == 0 && (*(int *)(param_5 + 0x60) == 8)))) {
    if (param_3[0x19] == 8) {
      if ((*(uint *)(param_3 + 0x10) & 0x200) == 0) {
LAB_140002fb6:
        sVar7 = 0;
      }
      else {
        sVar7 = 2;
      }
    }
    else {
      if ((param_3[0x19] != 0xdd86) || ((*(uint *)(param_3 + 0x10) & 0x400) == 0))
      goto LAB_140002fb6;
      sVar7 = 0x17;
    }
    if (iVar8 == 0) {
      if (sVar7 == 2) {
        local_218 = CONCAT44(1,(undefined4)local_218);
      }
      else if (sVar7 == 0x17) {
        local_218 = CONCAT44(2,(undefined4)local_218);
      }
      goto LAB_140002e07;
    }
  }
  else if (iVar8 == 0) goto LAB_140002e07;
  *param_3 = local_308;
LAB_140002e07:
  local_330 = param_10;
  local_338 = param_9;
  cVar1 = KfdDirectClassify(param_1,param_9[4],&local_2f8,param_3);
  if (cVar1 == '\0') {
    if (cVar10 != '\0') {
      L2FreeNetBufferListContext((longlong)param_3);
    }
  }
  else {
    if ((*param_10 == 0x1001) && ((param_10[7] & 1U) == 0)) {
      L2AuditAndDiagPacketDrop
                (param_1,*(longlong *)(param_9[4] + 8),(longlong)param_3,(longlong)param_10);
    }
    *local_318 = cVar10;
    *local_310 = (longlong)local_328;
  }
  return cVar1;
}



===== L2DereferenceLayerClassifyCache @ 140002fc8 =====

void L2DereferenceLayerClassifyCache(longlong param_1)

{
  int *piVar1;
  int iVar2;
  longlong local_res8 [4];
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x30);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -2;
  UNLOCK();
  if (iVar2 == 3) {
    local_res8[0] = param_1;
    KfdReleaseCachedFilters(param_1);
    L2FreeLayerClassifyCache(local_res8);
  }
  return;
}



===== L2p802_3IsNblPermitted @ 140003010 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

char L2p802_3IsNblPermitted
               (undefined8 **param_1,longlong *param_2,ushort param_3,char param_4,longlong *param_5
               ,longlong *param_6,undefined4 param_7,undefined8 *param_8)

{
  int *piVar1;
  ushort uVar2;
  uint uVar3;
  longlong *plVar4;
  byte bVar5;
  char cVar6;
  undefined1 uVar7;
  longlong lVar8;
  ulonglong uVar9;
  undefined1 *_Dst;
  undefined8 **ppuVar10;
  longlong lVar11;
  longlong lVar12;
  char cVar13;
  int iVar14;
  undefined8 *puVar15;
  longlong *plVar16;
  ulonglong uVar17;
  uint uVar18;
  undefined8 uVar19;
  bool bVar20;
  undefined1 auStackY_248 [32];
  uint in_stack_fffffffffffffdf0;
  undefined4 in_stack_fffffffffffffdf4;
  int *in_stack_fffffffffffffdf8;
  byte local_1e7;
  char local_1e6;
  char local_1e5;
  longlong local_1e0;
  longlong *local_1d8;
  longlong local_1d0;
  int local_1c8;
  undefined8 **local_1c0;
  undefined8 *local_1b8;
  longlong local_1b0;
  longlong *local_1a8;
  undefined8 *local_1a0;
  longlong *local_198;
  int local_190 [6];
  ulonglong uStack_178;
  undefined8 local_170;
  undefined1 local_168 [224];
  undefined8 local_88;
  undefined4 local_80;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_248;
  uVar19 = 0;
  local_1d8 = param_5;
  local_198 = param_6;
  local_1b8 = param_8;
  uVar9 = (ulonglong)(param_3 != 0x38);
  local_170 = 0;
  local_1e6 = '\0';
  local_1b0 = 0;
  local_190[0] = 0;
  local_190[1] = 0;
  local_190[2] = 0;
  local_190[3] = 0;
  local_190[4] = 0;
  local_190[5] = 0;
  uStack_178 = 0;
  uVar18 = (uint)(param_3 != 0x38);
  local_1c0 = param_1;
  local_1a8 = param_2;
  if ((param_1 == (undefined8 **)0x0) || (param_1[uVar9 * 2 + 0xf] == (undefined8 *)0x0)) {
LAB_140003243:
    puVar15 = local_1b8;
    in_stack_fffffffffffffdf8 = local_190;
    ppuVar10 = param_1;
    L2p802_3LayerRegularClassify
              ((longlong)param_1,local_1a8,param_3,param_4,*local_1d8,param_7,local_1b8,uVar18,
               in_stack_fffffffffffffdf8,&local_1e6,&local_1b0);
  }
  else {
    bVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 10);
    uVar17 = (ulonglong)bVar5;
    if (((ulonglong)param_1[0xe] & 1) != 0) {
      KeReleaseSpinLock(param_1 + 10,uVar17);
      goto LAB_140003243;
    }
    if (param_1[uVar9 * 2 + 0xf] != (undefined8 *)0x0) {
      RoReferenceEx((uint *)(param_1[uVar9 * 2 + 0xf] + 6));
    }
    puVar15 = param_1[uVar9 * 2 + 0xf];
    KeReleaseSpinLock(param_1 + 10,uVar17 & 0xff);
    if (puVar15 == (undefined8 *)0x0) goto LAB_140003243;
    local_1c8 = 0;
    KfdGetLayerCacheEpoch(param_3);
    if (*(int *)((longlong)puVar15 + 0x2c) != local_1c8) {
LAB_1400034f9:
      L2FlowRemoveContext((longlong)param_1,uVar18);
      L2DereferenceLayerClassifyCache((longlong)puVar15);
      goto LAB_140003243;
    }
    _Dst = local_168;
    local_1e0 = *local_1d8;
    uVar3 = *(uint *)(local_1b8 + 6);
    memset(_Dst,0,0x118);
    lVar12 = local_1e0;
    ppuVar10 = (undefined8 **)((ulonglong)_Dst & 0xffffffffffffff00);
    local_1e5 = '\0';
    local_1e7 = 0;
    local_1d0 = 0;
    if ((param_3 == 0x38) && ((uVar3 & 2) != 0)) {
      lVar8 = FwppDeepCloneNetBufferList(local_1e0,0,0,&local_1d0);
      if (lVar8 == 0) {
        NdisCopyReceiveNetBufferListInfo(local_1d0,lVar12);
        local_1e0 = local_1d0;
        if (local_1d0 == 0) {
          ppuVar10 = (undefined8 **)0x0;
          goto LAB_140003181;
        }
        goto LAB_14000348f;
      }
      goto LAB_1400034f9;
    }
LAB_140003181:
    if ((param_4 == '\0') && (*(int *)((longlong)puVar15 + 0x14) != 0)) {
LAB_14000348f:
      bVar20 = local_1d0 != 0;
      if (local_1d0 != 0) {
        *(longlong *)(local_1e0 + 0x78) = local_1a8[9];
      }
      iVar14 = NdisAllocateNetBufferListContext(local_1e0,0x40,0x40,0x6e326c57);
      if (iVar14 != 0) {
        if (local_1d0 != 0) {
          FwppFreeDeepCloneNetBufferList();
        }
        goto LAB_1400034f9;
      }
      local_1a0 = (undefined8 *)
                  (*(longlong *)(local_1e0 + 0x10) + 0x10 +
                  (ulonglong)*(ushort *)(*(longlong *)(local_1e0 + 0x10) + 10));
      *(undefined4 *)local_1a0 = 0x6e326c57;
      local_1a0[1] = local_1a8;
      *(ushort *)(local_1a0 + 2) = param_3;
      *(undefined1 *)((longlong)local_1a0 + 0x12) = 1;
      *(undefined8 *)((longlong)local_1a0 + 0x14) = 0;
      local_1a0[5] = 0;
      local_1a0[6] = 0;
      *(undefined1 *)(local_1a0 + 7) = 0;
      *(bool *)((longlong)local_1a0 + 0x39) = bVar20;
      lVar12 = local_1e0;
      RoReferenceEx((uint *)((longlong)local_1a8 + 0x14c));
      uVar9 = WfpNblInfoGetFlags(lVar12);
      if ((uVar9 & 2) == 0) {
        WfpNblInfoSetFlags(local_1e0,2);
        lVar12 = 0;
      }
      else {
        lVar12 = *(longlong *)(local_1e0 + 0x10) + 0x10 +
                 (ulonglong)*(ushort *)(*(longlong *)(local_1e0 + 0x10) + 10);
      }
      local_1a0[4] = lVar12;
      *(undefined4 *)((longlong)local_1a0 + 0x3c) = 1;
      ppuVar10 = (undefined8 **)0x1;
      local_1e7 = 1;
    }
    if ((undefined8 *)*puVar15 == puVar15) {
      local_190[0] = 0x1002;
      local_1b0 = local_1d0;
    }
    else {
      local_80 = param_7;
      local_88 = 1;
      if ((*(int *)((longlong)puVar15 + 0x14) != 0) && (param_3 == 0x38)) {
        NdisAdvanceNetBufferDataStart(*(undefined8 *)(local_1e0 + 8),param_7,0,0);
        local_1e5 = '\x01';
      }
      cVar6 = KfdDirectClassify(param_3,puVar15[4],local_168,local_1e0);
      if ((local_1e5 != '\0') && ((uStack_178 & 0x100000000) == 0)) {
        NdisRetreatNetBufferDataStart(*(undefined8 *)(local_1e0 + 8),param_7,0,0);
      }
      if (cVar6 == '\0') {
        if (local_1e7 != 0) {
          L2FreeNetBufferListContext(local_1e0);
        }
        goto LAB_1400034f9;
      }
      if ((local_190[0] == 0x1001) && ((uStack_178 & 0x100000000) == 0)) {
        L2AuditAndDiagPacketDrop
                  (param_3,*(longlong *)(puVar15[4] + 8),local_1e0,(longlong)local_190);
      }
      ppuVar10 = (undefined8 **)(ulonglong)local_1e7;
      local_1b0 = local_1d0;
    }
    local_1e6 = (char)ppuVar10;
    LOCK();
    piVar1 = (int *)(puVar15 + 6);
    iVar14 = *piVar1;
    *piVar1 = *piVar1 + -2;
    UNLOCK();
    local_1d0 = local_1b0;
    local_1a0 = puVar15;
    if (iVar14 == 3) {
      KfdReleaseCachedFilters(puVar15);
      ppuVar10 = &local_1a0;
      L2FreeLayerClassifyCache((longlong *)ppuVar10);
    }
    puVar15 = local_1b8;
    param_1 = local_1c0;
    uVar18 = in_stack_fffffffffffffdf0;
  }
  if ((local_190[0] != 0x1001) || ((uStack_178 & 0x100000000) != 0)) {
    if (param_1 == (undefined8 **)0x0) {
      L2CreateMacFlow(ppuVar10,*(ushort *)(puVar15 + 3),(byte *)puVar15[1],(byte *)puVar15[2],
                      *(ushort *)((longlong)puVar15 + 0x1a),puVar15[4],
                      *(int *)((longlong)puVar15 + 0x2c),CONCAT44(in_stack_fffffffffffffdf4,uVar18),
                      in_stack_fffffffffffffdf8,&local_1c0);
      param_1 = local_1c0;
    }
    else {
      iVar14 = DAT_14002c80c + *(int *)(param_1 + 9);
      if (DAT_14002ce54 == '\0') {
        uVar7 = KeAcquireSpinLockRaiseToDpc(&DAT_14002c800);
        KeAcquireSpinLockAtDpcLevel(param_1 + 10);
        if (((ulonglong)param_1[0xe] & 1) == 0) {
          if (iVar14 == 0) {
            iVar14 = 1;
          }
          *(int *)((longlong)param_1 + 0x6c) = iVar14;
          if ((*(int *)(param_1 + 0xd) == 0) || (iVar14 - *(int *)(param_1 + 0xd) < 0)) {
            RtlIndicateTimerWheelEntryTimerStart(&DAT_14002c808);
          }
        }
        KeReleaseSpinLockFromDpcLevel(param_1 + 10);
        KeReleaseSpinLock(&DAT_14002c800,uVar7);
      }
    }
  }
  if (param_1 != (undefined8 **)0x0) {
    LOCK();
    ppuVar10 = param_1 + 0xe;
    iVar14 = *(int *)ppuVar10;
    *(int *)ppuVar10 = *(int *)ppuVar10 + -2;
    UNLOCK();
    if (iVar14 == 3) {
      PplFreeToLookasideList(DAT_14002ce40,local_1c0);
    }
  }
  lVar12 = local_1b0;
  plVar16 = local_1d8;
  cVar6 = '\x01';
  if (local_190[0] == 0x1001) {
    cVar13 = '\0';
    cVar6 = '\0';
    if ((uStack_178 & 0x100000000) != 0) {
      if (local_1b0 == 0) {
        if (local_1e6 != '\0') {
          L2DereferenceNetBufferListContext(*local_1d8);
        }
        *plVar16 = 0;
        goto LAB_140003373;
      }
      L2DereferenceNetBufferListContext(local_1b0);
    }
  }
  cVar13 = cVar6;
  plVar16 = local_1d8;
LAB_140003373:
  plVar4 = local_198;
  if ((uStack_178 & 0x100000000) == 0) {
    if (lVar12 == 0) {
      if (local_1e6 != '\0') {
        lVar12 = *plVar16;
        bVar20 = false;
        lVar11 = (ulonglong)*(ushort *)(*(longlong *)(lVar12 + 0x10) + 10) +
                 *(longlong *)(lVar12 + 0x10);
        lVar8 = *(longlong *)(lVar11 + 0x18);
        cVar6 = *(char *)(lVar11 + 0x49);
        if ((*(char *)(lVar11 + 0x22) == '\0') && (*(int *)(lVar8 + 0x38) == 2)) {
          uVar19 = *(undefined8 *)(lVar8 + 0xa0);
          bVar20 = true;
        }
        LOCK();
        *(int *)(lVar8 + 0x14c) = *(int *)(lVar8 + 0x14c) + -2;
        UNLOCK();
        if (*(longlong *)(lVar11 + 0x30) == 0) {
          WfpNblInfoClearFlags(lVar12,2);
        }
        NdisFreeNetBufferListContext(lVar12,0x40);
        if (bVar20) {
          (*DAT_14002c590)(uVar19,lVar12);
        }
        if (cVar6 != '\0') {
          FwppFreeDeepCloneNetBufferList(lVar12);
        }
      }
    }
    else if (cVar13 == '\0') {
      L2FreeNetBufferListContext(lVar12);
    }
    else {
      *local_198 = lVar12;
      L2ReferenceNetBufferListContext(lVar12);
      lVar8 = *(longlong *)(*plVar4 + 0x10);
      uVar2 = *(ushort *)(lVar8 + 10);
      *(code **)((ulonglong)uVar2 + 0x38 + lVar8) = L2pDeepCloneNetBufferListCompletionFn;
      *(undefined8 *)((ulonglong)uVar2 + 0x40 + lVar8) = 0;
      L2DereferenceNetBufferListContext(lVar12);
    }
  }
  return cVar13;
}



===== L2p802_3LayerRegularClassify @ 140003800 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void L2p802_3LayerRegularClassify
               (longlong param_1,longlong *param_2,ushort param_3,char param_4,longlong param_5,
               undefined4 param_6,undefined8 *param_7,int param_8,int *param_9,undefined1 *param_10,
               longlong *param_11)

{
  undefined8 ***pppuVar1;
  bool bVar2;
  undefined8 ****ppppuVar3;
  int iVar4;
  int iVar5;
  ulonglong uVar6;
  longlong *plVar7;
  ulonglong uVar8;
  longlong lVar9;
  longlong lVar10;
  undefined4 uVar11;
  longlong *plVar12;
  bool bVar13;
  undefined1 auStack_448 [32];
  undefined8 local_428;
  int *local_420;
  undefined1 local_418;
  char local_417;
  ushort local_416;
  undefined4 local_414;
  longlong local_410;
  int *local_408;
  longlong *local_400;
  longlong local_3f8;
  undefined1 *local_3f0;
  longlong *local_3e8;
  ushort local_3e0 [4];
  undefined4 *local_3d8;
  undefined8 ****local_3d0;
  undefined8 ****ppppuStack_3c8;
  longlong *local_3c0;
  undefined1 local_3b8 [224];
  undefined4 local_2d8;
  undefined4 local_2d0;
  undefined8 ****local_1b8;
  undefined4 local_1b0;
  undefined4 local_1ac;
  undefined4 local_1a8;
  undefined4 local_1a4;
  int local_1a0;
  undefined4 local_19c;
  undefined4 local_108 [2];
  undefined8 local_100;
  undefined4 local_f8;
  byte *local_f0;
  undefined4 local_e8;
  byte *local_e0;
  undefined4 local_d8;
  undefined1 local_d0;
  undefined4 local_c8;
  undefined1 local_c0;
  undefined4 local_b8;
  undefined2 local_b0;
  undefined4 local_a8;
  short local_a0;
  undefined4 local_98;
  undefined8 *local_90;
  undefined4 local_88;
  undefined4 local_80;
  undefined4 local_78;
  undefined4 local_70;
  undefined4 local_68;
  uint local_60;
  undefined4 local_58;
  undefined4 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_448;
  local_3f0 = param_10;
  local_3e8 = param_11;
  local_408 = param_9;
  local_3e0[1] = 0;
  local_416 = param_3;
  local_400 = param_2;
  local_3f8 = param_1;
  memset(local_3b8,0,0x2a8);
  bVar2 = false;
  local_410 = 0;
  local_108[0] = 0x12;
  local_f0 = (byte *)param_7[1];
  local_100 = *param_7;
  local_60 = -(uint)(*(char *)((longlong)param_2 + 0x66) != '\0') & 0x80;
  local_e0 = (byte *)param_7[2];
  local_f8 = 0x12;
  local_e8 = 0x12;
  local_d8 = 1;
  local_418 = 0;
  local_417 = '\0';
  if ((*local_f0 & 1) == 0) {
    local_d0 = 0;
  }
  else {
    iVar5 = *(int *)local_f0 + 1;
    if (iVar5 == 0) {
      iVar5 = *(ushort *)(local_f0 + 4) - 0xffff;
    }
    if (iVar5 == 0) {
      local_d0 = 2;
    }
    else {
      local_d0 = 1;
    }
  }
  local_c8 = 1;
  if ((*local_e0 & 1) == 0) {
    local_c0 = 0;
  }
  else {
    iVar5 = *(int *)local_e0 + 1;
    if (iVar5 == 0) {
      iVar5 = *(ushort *)(local_e0 + 4) - 0xffff;
    }
    if (iVar5 == 0) {
      local_c0 = 2;
    }
    else {
      local_c0 = 1;
    }
  }
  local_b0 = *(undefined2 *)(param_7 + 3);
  local_b8 = 2;
  if (*(short *)((longlong)param_7 + 0x1a) == 0) {
    local_a8 = 0;
  }
  else {
    local_a8 = 2;
    local_a0 = *(short *)((longlong)param_7 + 0x1a);
  }
  local_90 = param_7 + 4;
  local_80 = *(undefined4 *)(param_7 + 5);
  local_70 = *(undefined4 *)((longlong)param_7 + 0x2c);
  local_50 = *(undefined4 *)((longlong)param_2 + 0x3dc);
  ppppuStack_3c8 = &local_3d0;
  local_3d0 = &local_3d0;
  local_98 = 4;
  local_88 = 3;
  local_78 = 3;
  local_68 = 3;
  local_58 = 3;
  local_2d8 = 1;
  local_2d0 = param_6;
  if (local_3f8 != 0) {
    local_1b8 = &local_3d0;
    local_1a4 = 1;
  }
  local_3d8 = local_108;
  local_3e0[2] = 0xc;
  local_3e0[3] = 0;
  local_3e0[0] = param_3;
  if (param_3 == 0x38) {
    if ((*(uint *)(param_7 + 6) & 2) == 0) {
LAB_140003c18:
      NdisAdvanceNetBufferDataStart(*(undefined8 *)(param_5 + 8),param_6,0,0);
      bVar2 = true;
      goto LAB_140003a22;
    }
    lVar9 = FwppDeepCloneNetBufferList(param_5,0,0,&local_410);
    if (lVar9 == 0) {
      NdisCopyReceiveNetBufferListInfo(local_410,param_5);
      param_5 = local_410;
      goto LAB_140003c18;
    }
    iVar5 = -0x3fffff66;
LAB_140003b43:
  }
  else {
LAB_140003a22:
    if ((param_4 != '\0') && (local_410 == 0)) {
LAB_140003b1d:
      local_428 = 0;
      local_420 = param_9;
      iVar5 = KfdClassify(param_3,local_3e0,local_3b8,param_5);
      goto LAB_140003b43;
    }
    if (bVar2) {
      local_414 = param_6;
      uVar11 = *(undefined4 *)(*(longlong *)(param_5 + 8) + 0x28);
    }
    else {
      uVar11 = 0;
      local_414 = 0;
    }
    bVar13 = local_410 != 0;
    if (bVar13) {
      *(longlong *)(param_5 + 0x78) = param_2[9];
    }
    iVar4 = NdisAllocateNetBufferListContext(param_5,0x40,0x40,0x6e326c57);
    if (iVar4 == 0) {
      lVar9 = *(longlong *)(param_5 + 0x10);
      uVar8 = (ulonglong)*(ushort *)(lVar9 + 10);
      *(undefined4 *)(uVar8 + 0x28 + lVar9) = uVar11;
      *(longlong **)(uVar8 + 0x18 + lVar9) = local_400;
      *(ushort *)(uVar8 + 0x20 + lVar9) = local_416;
      *(undefined8 *)(uVar8 + 0x38 + lVar9) = 0;
      *(undefined8 *)(uVar8 + 0x40 + lVar9) = 0;
      *(undefined1 *)(uVar8 + 0x48 + lVar9) = 0;
      *(undefined4 *)(uVar8 + 0x10 + lVar9) = 0x6e326c57;
      *(undefined1 *)(uVar8 + 0x22 + lVar9) = 1;
      *(undefined4 *)(uVar8 + 0x24 + lVar9) = local_414;
      *(bool *)(uVar8 + 0x49 + lVar9) = bVar13;
      RoReferenceEx((uint *)((longlong)local_400 + 0x14c));
      uVar6 = WfpNblInfoGetFlags(param_5);
      if ((uVar6 & 2) == 0) {
        WfpNblInfoSetFlags(param_5,2);
        lVar10 = 0;
      }
      else {
        lVar10 = *(longlong *)(param_5 + 0x10) + 0x10 +
                 (ulonglong)*(ushort *)(*(longlong *)(param_5 + 0x10) + 10);
      }
      *(longlong *)(uVar8 + 0x30 + lVar9) = lVar10;
      *(undefined4 *)(uVar8 + 0x4c + lVar9) = 1;
      local_418 = 1;
      param_9 = local_408;
      param_3 = local_416;
      goto LAB_140003b1d;
    }
    param_3 = local_416;
    if ((((iVar4 == 0x103) || (iVar4 == -0x7ffffffb)) || (iVar5 = -0x3fffffff, iVar4 == -0x3fffffff)
        ) || ((iVar4 == -0x3fffff66 || (iVar4 == -0x3fffff45)))) {
      local_417 = '\x01';
      local_418 = 0;
      iVar5 = iVar4;
      goto LAB_140003b43;
    }
    if (iVar4 == -0x3ffeffea) {
      iVar5 = -0x3fffffdd;
LAB_140003f46:
      local_417 = '\x01';
      local_418 = 0;
    }
    else {
      if (iVar4 == -0x3ffeffec) {
        iVar5 = -0x3ffffdfa;
        goto LAB_140003f46;
      }
      local_417 = '\x01';
      local_418 = 0;
      if (iVar4 == -0x3ffeffeb) {
        iVar5 = -0x3ffffff3;
      }
    }
  }
  plVar12 = (longlong *)0x0;
  if ((bVar2) && ((param_9[7] & 1U) == 0)) {
    NdisRetreatNetBufferDataStart(*(undefined8 *)(param_5 + 8),param_6,0,0);
  }
  ppppuVar3 = local_1b8;
  if (iVar5 < 0) {
    *param_9 = 0x1001;
  }
  else {
    if ((local_1a0 != 0) && (local_3f8 != 0)) {
      local_408 = (int *)0x0;
      local_400 = (longlong *)0x0;
      local_414 = local_1a8;
      plVar7 = (longlong *)ExAllocatePool2(0x40,0x38,0x63326c57);
      local_3c0 = plVar7;
      if (plVar7 == (longlong *)0x0) {
        uVar6 = 0xc0000017;
      }
      else {
        uVar6 = FeCopyIncomingValues(local_3e0,0,&local_408);
        if (uVar6 == 0) {
          *(undefined4 *)((longlong)plVar7 + 0x2c) = local_414;
          plVar7[4] = (longlong)local_408;
          *(undefined4 *)(plVar7 + 5) = 0;
          if ((undefined8 ****)*ppppuVar3 == ppppuVar3) {
            plVar7[1] = (longlong)plVar7;
            *plVar7 = (longlong)plVar7;
          }
          else {
            pppuVar1 = ppppuVar3[1];
            *plVar7 = (longlong)*ppppuVar3;
            plVar7[1] = (longlong)pppuVar1;
            *(longlong **)(*plVar7 + 8) = plVar7;
            *(longlong **)plVar7[1] = plVar7;
            ppppuVar3[1] = ppppuVar3;
            *ppppuVar3 = ppppuVar3;
          }
          *(undefined4 *)(plVar7 + 2) = local_1b0;
          *(undefined4 *)((longlong)plVar7 + 0x14) = local_1ac;
          *(undefined4 *)(plVar7 + 3) = local_19c;
          *(undefined4 *)(plVar7 + 6) = 2;
          local_400 = plVar7;
        }
        else {
          L2FreeLayerClassifyCache((longlong *)&local_3c0);
          plVar7 = plVar12;
          if ((int)uVar6 < 0) goto LAB_140003d1a;
        }
        uVar8 = L2FlowAssociateContext(local_3f8,param_8,L2p802_3FlowEventCallback,plVar7);
        uVar6 = uVar8 & 0xffffffff;
        plVar12 = plVar7;
        if (-1 < (int)uVar8) goto LAB_140003b7b;
      }
LAB_140003d1a:
      if ((plVar12 == (longlong *)0x0) ||
         (L2FreeLayerClassifyCache((longlong *)&local_400), (int)uVar6 < 0)) {
        KfdReleaseCachedFilters(&local_3d0);
      }
    }
LAB_140003b7b:
    if (*param_9 != 0x1001) goto LAB_140003b83;
  }
  if ((param_9[7] & 1U) == 0) {
    L2AuditAndDiagPacketDrop(param_3,(longlong)local_108,param_5,(longlong)param_9);
  }
LAB_140003b83:
  if ((local_410 == 0) || (local_417 == '\0')) {
    *local_3f0 = local_418;
    *local_3e8 = local_410;
  }
  else {
    FwppFreeDeepCloneNetBufferList(local_410);
    *local_3f0 = local_418;
    *local_3e8 = 0;
  }
  return;
}



===== L2FlowRetrieveContext @ 140003fa0 =====

undefined8
L2FlowRetrieveContext(longlong param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  longlong lVar1;
  undefined1 uVar2;
  undefined8 uVar3;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x50);
  if ((*(byte *)(param_1 + 0x70) & 1) == 0) {
    lVar1 = *(longlong *)(param_1 + 0x78 + (longlong)param_2 * 0x10);
    if (lVar1 != 0) {
      RoReferenceEx((uint *)(lVar1 + 0x30));
    }
    uVar3 = 0;
    *param_4 = *(undefined8 *)(param_1 + 0x78 + (longlong)param_2 * 0x10);
  }
  else {
    uVar3 = 0xc0000001;
  }
  KeReleaseSpinLock(param_1 + 0x50,uVar2);
  return uVar3;
}



===== L2pAllocateNetBufferListContext @ 140004050 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong L2pAllocateNetBufferListContext
                    (longlong param_1,char param_2,longlong param_3,char param_4,undefined2 param_5,
                    undefined4 param_6,undefined4 param_7)

{
  longlong lVar1;
  bool bVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong lVar6;
  
  bVar2 = false;
  if ((((param_4 == '\0') || (param_2 != '\0')) &&
      (*(undefined8 *)(param_1 + 0x78) = *(undefined8 *)(param_3 + 0x48), param_4 == '\0')) &&
     (*(int *)(param_3 + 0x38) == 2)) {
    uVar3 = (*DAT_14002c588)(*(undefined8 *)(param_3 + 0xa0),param_1);
    if ((int)uVar3 != 0) {
      return uVar3;
    }
    bVar2 = true;
  }
  uVar3 = NdisAllocateNetBufferListContext(param_1,0x40,0x40,0x6e326c57);
  if ((int)uVar3 == 0) {
    lVar1 = *(longlong *)(param_1 + 0x10);
    uVar5 = (ulonglong)*(ushort *)(lVar1 + 10);
    *(undefined2 *)(uVar5 + 0x20 + lVar1) = param_5;
    *(char *)(uVar5 + 0x22 + lVar1) = param_4;
    lVar6 = 0;
    *(undefined4 *)(uVar5 + 0x24 + lVar1) = param_6;
    *(undefined4 *)(uVar5 + 0x10 + lVar1) = 0x6e326c57;
    *(longlong *)(uVar5 + 0x18 + lVar1) = param_3;
    *(undefined4 *)(uVar5 + 0x28 + lVar1) = param_7;
    *(undefined8 *)(uVar5 + 0x38 + lVar1) = 0;
    *(undefined8 *)(uVar5 + 0x40 + lVar1) = 0;
    *(undefined1 *)(uVar5 + 0x48 + lVar1) = 0;
    *(char *)(uVar5 + 0x49 + lVar1) = param_2;
    RoReferenceEx((uint *)(param_3 + 0x14c));
    uVar4 = WfpNblInfoGetFlags(param_1);
    if ((uVar4 & 2) == 0) {
      WfpNblInfoSetFlags(param_1,2);
    }
    else {
      lVar6 = *(longlong *)(param_1 + 0x10) + 0x10 +
              (ulonglong)*(ushort *)(*(longlong *)(param_1 + 0x10) + 10);
    }
    *(longlong *)(uVar5 + 0x30 + lVar1) = lVar6;
    *(undefined4 *)(uVar5 + 0x4c + lVar1) = 1;
    uVar3 = uVar3 & 0xffffffff;
  }
  else if (bVar2) {
    (*DAT_14002c590)(*(undefined8 *)(param_3 + 0xa0),param_1);
    uVar3 = uVar3 & 0xffffffff;
  }
  return uVar3;
}



===== L2LookupMacFlow @ 1400041d0 =====

undefined8
L2LookupMacFlow(undefined8 param_1,ushort param_2,byte *param_3,byte *param_4,short param_5,
               ulonglong param_6,int param_7,longlong *param_8)

{
  undefined1 uVar1;
  char cVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  longlong lVar6;
  longlong lVar7;
  byte bStackX_11;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  
  bStackX_11 = (byte)(param_2 >> 8);
  lVar6 = (((((((((((((((((((((((((ulonglong)(byte)param_2 * 0x25 + (ulonglong)bStackX_11) * 0x25 +
                                (ulonglong)*param_3) * 0x25 + (ulonglong)param_3[1]) * 0x25 +
                              (ulonglong)param_3[2]) * 0x25 + (ulonglong)param_3[3]) * 0x25 +
                            (ulonglong)param_3[4]) * 0x25 + (ulonglong)param_3[5]) * 0x25 +
                          (ulonglong)*param_4) * 0x25 + (ulonglong)param_4[1]) * 0x25 +
                        (ulonglong)param_4[2]) * 0x25 + (ulonglong)param_4[3]) * 0x25 +
                      (ulonglong)param_4[4]) * 0x25 + (ulonglong)param_4[5]) * 0x25 +
                    (ulonglong)(byte)param_5) * 0x25 + (ulonglong)param_5._1_1_) * 0x25 +
                  (param_6 & 0xff)) * 0x25 + (param_6 >> 8 & 0xff)) * 0x25 +
                (param_6 >> 0x10 & 0xff)) * 0x25 + (param_6 >> 0x18 & 0xff)) * 0x25 +
              (param_6 >> 0x20 & 0xff)) * 0x25 + (param_6 >> 0x28 & 0xff)) * 0x25 +
            (param_6 >> 0x30 & 0xff)) * 0x25 + (param_6 >> 0x38)) * 0x25 + (ulonglong)(byte)param_7)
          * 0x25 + (ulonglong)param_7._1_1_;
  uVar1 = KfRaiseIrql(CONCAT71((int7)((ulonglong)lVar6 >> 8),2));
  local_48 = 0;
  local_58 = 0;
  uStack_50 = 0;
  LOCK();
  DAT_14002c6e8 = DAT_14002c6e8 + 1;
  UNLOCK();
  cVar2 = KeTestSpinLock(&gL2FlowsMgr);
  if (cVar2 == '\0') {
    LOCK();
    DAT_14002c6e8 = DAT_14002c6e8 + -1;
    UNLOCK();
    KeAcquireInStackQueuedSpinLockAtDpcLevel(&gL2FlowsMgr,&local_58);
    LOCK();
    DAT_14002c6e8 = DAT_14002c6e8 + 1;
    UNLOCK();
    KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_58);
  }
  local_30 = 0;
  lVar7 = 0;
  local_40 = 0;
  uStack_38 = 0;
  lVar6 = RtlLookupEntryHashTable
                    (&DAT_14002c6f0,
                     (lVar6 * 0x25 + (ulonglong)param_7._2_1_) * 0x25 + (ulonglong)param_7._3_1_ <<
                     ((byte)DAT_14002c718 & 0x3f),&local_40);
  if (lVar6 != 0) {
    do {
      lVar7 = lVar6 + -0x10;
      if ((((*(ushort *)(lVar6 + -0xc) == param_2) && (*(short *)(lVar6 + -10) == param_5)) &&
          (*(int *)(lVar6 + 0xa0) == param_7)) &&
         (((*(ulonglong *)(lVar6 + 0x98) == param_6 &&
           (lVar3 = RtlCompareMemory(lVar6 + 0x88,param_3,6), lVar3 == 6)) &&
          ((lVar3 = RtlCompareMemory(lVar6 + 0x8e,param_4,6), lVar3 == 6 &&
           (uVar4 = RoReferenceEx((uint *)(lVar6 + 0x60)), (char)uVar4 != '\0')))))) break;
      lVar7 = 0;
      lVar6 = RtlGetNextEntryHashTable(&DAT_14002c6f0,&local_40);
    } while (lVar6 != 0);
  }
  LOCK();
  DAT_14002c6e8 = DAT_14002c6e8 + -1;
  UNLOCK();
  KeLowerIrql(uVar1);
  if (lVar7 == 0) {
    uVar5 = 0xc0000225;
  }
  else {
    *param_8 = lVar7;
    uVar5 = 0;
  }
  return uVar5;
}



===== L2pLookupMacFlow @ 140004550 =====

longlong L2pLookupMacFlow(undefined8 param_1,longlong param_2,short param_3,undefined8 param_4,
                         undefined8 param_5,short param_6,longlong param_7,int param_8)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  lVar1 = RtlLookupEntryHashTable(&DAT_14002c6f0,param_2 << ((byte)DAT_14002c718 & 0x3f),&local_38);
  while( true ) {
    if (lVar1 == 0) {
      return 0;
    }
    if ((((*(short *)(lVar1 + -0xc) == param_3) && (*(short *)(lVar1 + -10) == param_6)) &&
        (*(int *)(lVar1 + 0xa0) == param_8)) &&
       (((*(longlong *)(lVar1 + 0x98) == param_7 &&
         (lVar2 = RtlCompareMemory(lVar1 + 0x88,param_4,6), lVar2 == 6)) &&
        ((lVar2 = RtlCompareMemory(lVar1 + 0x8e,param_5,6), lVar2 == 6 &&
         (uVar3 = RoReferenceEx((uint *)(lVar1 + 0x60)), (char)uVar3 != '\0')))))) break;
    lVar1 = RtlGetNextEntryHashTable(&DAT_14002c6f0,&local_38);
  }
  return lVar1 + -0x10;
}



===== RoReferenceEx @ 140004680 =====

ulonglong RoReferenceEx(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  do {
    uVar2 = *param_1;
    if ((uVar2 & 1) != 0) {
      return (ulonglong)(uVar2 & 0xffffff00);
    }
    LOCK();
    uVar1 = *param_1;
    bVar3 = uVar2 == uVar1;
    if (bVar3) {
      *param_1 = uVar2 + 2;
      uVar1 = uVar2;
    }
    UNLOCK();
  } while (!bVar3);
  return CONCAT71((uint7)(uint3)(uVar1 >> 8),1);
}



===== L2FreeNetBufferListContext @ 1400046a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void L2FreeNetBufferListContext(longlong param_1)

{
  char cVar1;
  longlong lVar2;
  bool bVar3;
  longlong lVar4;
  undefined8 uVar5;
  
  bVar3 = false;
  uVar5 = 0;
  lVar4 = (ulonglong)*(ushort *)(*(longlong *)(param_1 + 0x10) + 10) + *(longlong *)(param_1 + 0x10)
  ;
  lVar2 = *(longlong *)(lVar4 + 0x18);
  cVar1 = *(char *)(lVar4 + 0x49);
  if ((*(char *)(lVar4 + 0x22) == '\0') && (*(int *)(lVar2 + 0x38) == 2)) {
    uVar5 = *(undefined8 *)(lVar2 + 0xa0);
    bVar3 = true;
  }
  LOCK();
  *(int *)(lVar2 + 0x14c) = *(int *)(lVar2 + 0x14c) + -2;
  UNLOCK();
  if (*(longlong *)(lVar4 + 0x30) == 0) {
    WfpNblInfoClearFlags(param_1,2);
  }
  NdisFreeNetBufferListContext(param_1,0x40);
  if (bVar3) {
    (*DAT_14002c590)(uVar5,param_1);
  }
  if (cVar1 != '\0') {
    FwppFreeDeepCloneNetBufferList(param_1);
  }
  return;
}



===== LwfUpperSendNetBufferLists @ 140004770 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void LwfUpperSendNetBufferLists(longlong *param_1,longlong ******param_2,uint param_3,uint param_4)

{
  ushort uVar1;
  longlong *******ppppppplVar2;
  longlong lVar3;
  char cVar4;
  char cVar5;
  int iVar6;
  longlong *******ppppppplVar7;
  longlong *plVar8;
  longlong lVar9;
  longlong *plVar10;
  uint uVar11;
  longlong *******ppppppplVar12;
  undefined1 auStackY_108 [32];
  char local_a8 [4];
  uint local_a4;
  uint local_a0;
  longlong *******local_98;
  int local_90;
  longlong *******local_88;
  longlong *******local_80;
  longlong local_78;
  longlong ******local_70;
  int local_68 [6];
  ulonglong uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_108;
  local_a4 = param_4;
  local_a0 = param_3;
  local_70 = param_2;
  iVar6 = KfdIsLayerEmpty(0x39);
  if (iVar6 == 0) {
    local_80 = &local_70;
    local_88 = (longlong *******)0x0;
    plVar8 = (longlong *)0x0;
    local_a8[1] = 1;
    ppppppplVar12 = (longlong *******)0x0;
    local_98 = (longlong *******)param_2;
    while (ppppppplVar7 = local_98, local_98 != (longlong *******)0x0) {
      ppppppplVar2 = (longlong *******)*local_98;
      *local_98 = (longlong ******)0x0;
      if ((int)param_1[7] == 0) {
        local_98 = (longlong *******)((ulonglong)local_98 & 0xffffffff00000000);
        local_68[0] = 0;
        local_68[1] = 0;
        local_68[2] = 0;
        local_68[3] = 0;
        local_48 = 0;
        local_68[4] = 0;
        local_68[5] = 0;
        uStack_50 = 0;
        local_a8[0] = '\0';
        local_78 = 0;
        if (*(int *)((longlong)param_1 + 0x5c) == 0x10) {
          lVar9 = param_1[(ulonglong)param_3 * 6 + 0x2d];
        }
        else {
          lVar9 = param_1[0x2b];
        }
        if (lVar9 == 0) {
LAB_1400048ab:
          uVar11 = local_a4;
LAB_1400048af:
          L2pNativeLayerRegularClassify
                    (0x39,'\0',(longlong)ppppppplVar7,uVar11,(longlong)param_1,1,param_3,local_68,
                     local_a8,&local_78);
        }
        else {
          KeAcquireSpinLockRaiseToDpc(param_1 + 6);
          if (*(int *)((longlong)param_1 + 0x5c) == 0x10) {
            plVar10 = (longlong *)param_1[(ulonglong)param_3 * 6 + 0x2d];
            local_98 = (longlong *******)
                       CONCAT44(local_98._4_4_,(int)param_1[(ulonglong)param_3 * 6 + 0x2e]);
          }
          else {
            plVar10 = (longlong *)param_1[0x2b];
          }
          if (plVar10 != (longlong *)0x0) {
            RoReferenceEx((uint *)(plVar10 + 6));
          }
          KeReleaseSpinLock(param_1 + 6);
          iVar6 = (int)local_98;
          if (plVar10 == (longlong *)0x0) goto LAB_1400048ab;
          local_90 = 0;
          KfdGetLayerCacheEpoch(0x39);
          uVar11 = local_a4;
          if ((*(int *)((longlong)plVar10 + 0x2c) != local_90) ||
             (cVar5 = L2pNativeLayerDirectClassify
                                (0x39,'\0',ppppppplVar7,ppppppplVar2,(longlong)param_1,param_3,
                                 local_a4,iVar6,plVar10,local_68,local_a8,&local_78), cVar5 == '\0')
             ) {
            LwfLowerPurgeClassifyCache((longlong)param_1,1,param_3);
            goto LAB_1400048af;
          }
          L2DereferenceLayerClassifyCache((longlong)plVar10);
        }
        lVar9 = local_78;
        cVar5 = local_a8[0];
        cVar4 = '\x01';
        if (local_68[0] == 0x1001) {
          cVar4 = '\0';
          if ((uStack_50 & 0x100000000) != 0) {
            if (local_78 == 0) {
              if (local_a8[0] != '\0') {
                L2DereferenceNetBufferListContext((longlong)ppppppplVar7);
              }
              ppppppplVar7 = (longlong *******)0x0;
            }
            else {
              L2DereferenceNetBufferListContext(local_78);
            }
            goto LAB_140004907;
          }
LAB_14000490d:
          if (lVar9 == 0) {
            if (cVar5 != '\0') {
              L2FreeNetBufferListContext((longlong)ppppppplVar7);
            }
            goto LAB_140004923;
          }
          if (cVar4 != '\0') {
            *plVar8 = lVar9;
            L2ReferenceNetBufferListContext(lVar9);
            lVar3 = *(longlong *)(*plVar8 + 0x10);
            uVar1 = *(ushort *)(lVar3 + 10);
            *(code **)((ulonglong)uVar1 + 0x38 + lVar3) = L2pDeepCloneNetBufferListCompletionFn;
            *(undefined8 *)((ulonglong)uVar1 + 0x40 + lVar3) = 0;
            L2DereferenceNetBufferListContext(lVar9);
            goto LAB_140004928;
          }
          L2FreeNetBufferListContext(lVar9);
        }
        else {
LAB_140004907:
          if ((uStack_50 & 0x100000000) == 0) goto LAB_14000490d;
LAB_140004923:
          if (cVar4 != '\0') {
LAB_140004928:
            if (*ppppppplVar7 != (longlong ******)0x0) {
              ppppppplVar12 = local_88;
              param_4 = local_a4;
              param_3 = local_a0;
              break;
            }
          }
        }
        ppppppplVar12 = local_88;
        param_3 = local_a0;
        if ((plVar8 != (longlong *)0x0) && ((longlong *)*plVar8 != (longlong *)0x0)) {
          _DAT_00000000 = _DAT_00000000 + 1;
          plVar8 = (longlong *)*plVar8;
        }
      }
      else {
        if ((int)param_1[7] == 1) {
          cVar4 = L2802_3IsNetBufferListPermitted
                            (0x39,'\0',(longlong *)&local_98,plVar8,param_1,param_3,param_4);
          if ((plVar8 != (longlong *)0x0) && ((longlong *)*plVar8 != (longlong *)0x0)) {
            _DAT_00000000 = _DAT_00000000 + 1;
            plVar8 = (longlong *)*plVar8;
          }
        }
        else {
          cVar4 = vSwitch802_3IsNetBufferListPermitted
                            (1,0x39,'\0',(longlong *)&local_98,(longlong)param_1);
        }
        ppppppplVar7 = local_98;
      }
      param_4 = local_a4;
      local_98 = ppppppplVar2;
      if (cVar4 == '\0') {
        local_a8[1] = 0;
        *local_80 = (longlong ******)ppppppplVar2;
        if (ppppppplVar7 == (longlong *******)0x0) goto LAB_140004865;
        *ppppppplVar7 = (longlong ******)ppppppplVar12;
        ppppppplVar12 = ppppppplVar7;
        local_88 = ppppppplVar7;
      }
      else {
        *ppppppplVar7 = (longlong ******)ppppppplVar2;
        local_80 = ppppppplVar7;
LAB_140004865:
      }
    }
    local_80 = ppppppplVar12;
    if ((int)param_1[7] == 0) {
      L2InspectNetBufferListsFast
                (1,0x39,(longlong *)&local_70,(undefined4 *)0x0,(longlong *)0x0,(undefined4 *)0x0,
                 (longlong *)&local_80,(longlong)param_1,param_3,(byte)param_4,local_a8 + 1,'\0');
    }
    ppppppplVar12 = local_80;
    if (local_70 != (longlong ******)0x0) {
      L2NdisFSendNetBufferLists((longlong)param_1,param_1[9],(longlong ***)local_70,param_3,param_4)
      ;
    }
    if (ppppppplVar12 != (longlong *******)0x0) {
      NdisFSendNetBufferListsComplete(param_1[9],ppppppplVar12,param_4 & 1);
    }
  }
  else {
    L2NdisFSendNetBufferLists((longlong)param_1,param_1[9],(longlong ***)param_2,param_3,param_4);
  }
  return;
}



===== LwfUpperRecvNetBufferLists @ 140004c90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void LwfUpperRecvNetBufferLists
               (longlong *param_1,longlong *********param_2,uint param_3,int param_4,uint param_5)

{
  ushort uVar1;
  longlong **********pppppppppplVar2;
  longlong **pplVar3;
  longlong ****pppplVar4;
  char cVar5;
  char cVar6;
  int iVar7;
  longlong **********pppppppppplVar8;
  uint uVar9;
  undefined8 unaff_R12;
  ulonglong uVar10;
  longlong **********pppppppppplVar11;
  longlong lVar12;
  longlong *plVar13;
  undefined1 auStackY_138 [32];
  char local_d8;
  undefined1 local_d7 [3];
  uint local_d4;
  int local_d0;
  uint local_cc;
  longlong **********local_c8;
  int local_c0;
  int local_bc;
  longlong ****local_b8;
  int local_b0;
  longlong **********local_a8;
  longlong **********local_a0;
  uint local_98;
  longlong ***local_90;
  longlong *********local_88;
  int local_80 [6];
  ulonglong uStack_68;
  undefined8 local_60;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_138;
  local_90 = (longlong ***)0x0;
  local_d0 = 0;
  local_d4 = param_3;
  local_c0 = param_4;
  local_bc = param_4;
  local_88 = param_2;
  iVar7 = KfdIsLayerEmpty(0x38);
  if (iVar7 != 0) {
    L2NdisFIndicateReceiveNetBufferLists
              ((longlong)param_1,param_1[9],(longlong ***)param_2,param_3,param_4,param_5);
    return;
  }
  local_a0 = &local_88;
  uVar10 = CONCAT71((int7)((ulonglong)unaff_R12 >> 8),1);
  local_a8 = (longlong **********)0x0;
  local_b8 = &local_90;
  local_98 = param_5 & 2;
  local_cc = (uint)uVar10;
  local_d7[0] = 1;
  pppppppppplVar11 = (longlong **********)0x0;
  local_c8 = (longlong **********)param_2;
  do {
    pppppppppplVar8 = local_c8;
    if (local_c8 == (longlong **********)0x0) {
LAB_140004edb:
      local_a0 = pppppppppplVar11;
      if ((int)param_1[7] == 0) {
        L2InspectNetBufferListsFast
                  (2,0x38,(longlong *)&local_88,&local_c0,(longlong *)&local_90,&local_d0,
                   (longlong *)&local_a0,(longlong)param_1,param_3,(byte)param_5,local_d7,'\0');
        iVar7 = local_c0;
      }
      else {
        iVar7 = local_bc;
      }
      pppppppppplVar11 = local_a0;
      if (local_90 != (longlong ***)0x0) {
        L2NdisFIndicateReceiveNetBufferLists
                  ((longlong)param_1,param_1[9],local_90,param_3,local_d0,param_5 & 0xfffffffd);
      }
      if (local_88 != (longlong *********)0x0) {
        if ((param_5 & 2) == 0) {
          L2NdisFIndicateReceiveNetBufferLists
                    ((longlong)param_1,param_1[9],(longlong ***)local_88,param_3,iVar7,param_5);
        }
        else {
          L2CheckAndNotifyNetBufferListEvent(local_88,7);
        }
      }
      if (pppppppppplVar11 == (longlong **********)0x0) {
        return;
      }
      NdisFReturnNetBufferLists(param_1[9],pppppppppplVar11,param_5 & 1);
      return;
    }
    pppppppppplVar2 = (longlong **********)*local_c8;
    *local_c8 = (longlong *********)0x0;
    if ((int)param_1[7] == 0) {
      local_c8 = (longlong **********)0x0;
      iVar7 = 0;
      local_60 = 0;
      local_80[0] = 0;
      local_80[1] = 0;
      local_80[2] = 0;
      local_80[3] = 0;
      local_d8 = '\0';
      local_80[4] = 0;
      local_80[5] = 0;
      uStack_68 = 0;
      if (*(int *)((longlong)param_1 + 0x5c) == 0x10) {
        lVar12 = param_1[(ulonglong)param_3 * 6 + 0x2d];
      }
      else {
        lVar12 = param_1[0x2b];
      }
      if (lVar12 == 0) {
LAB_140004e1b:
        uVar9 = local_d4;
LAB_140004e20:
        L2pNativeLayerRegularClassify
                  (0x38,'\0',(longlong)pppppppppplVar8,param_5,(longlong)param_1,1,uVar9,local_80,
                   &local_d8,(longlong *)&local_c8);
      }
      else {
        KeAcquireSpinLockRaiseToDpc(param_1 + 6);
        if (*(int *)((longlong)param_1 + 0x5c) == 0x10) {
          plVar13 = (longlong *)param_1[(ulonglong)local_d4 * 6 + 0x2d];
          iVar7 = (int)param_1[(ulonglong)local_d4 * 6 + 0x2e];
        }
        else {
          plVar13 = (longlong *)param_1[0x2b];
        }
        if (plVar13 != (longlong *)0x0) {
          RoReferenceEx((uint *)(plVar13 + 6));
        }
        KeReleaseSpinLock(param_1 + 6);
        if (plVar13 == (longlong *)0x0) goto LAB_140004e1b;
        local_b0 = 0;
        KfdGetLayerCacheEpoch(0x38);
        uVar9 = local_d4;
        if ((*(int *)((longlong)plVar13 + 0x2c) != local_b0) ||
           (cVar6 = L2pNativeLayerDirectClassify
                              (0x38,'\0',pppppppppplVar8,pppppppppplVar2,(longlong)param_1,local_d4,
                               param_5,iVar7,plVar13,local_80,&local_d8,(longlong *)&local_c8),
           cVar6 == '\0')) {
          LwfLowerPurgeClassifyCache((longlong)param_1,1,uVar9);
          goto LAB_140004e20;
        }
        L2DereferenceLayerClassifyCache((longlong)plVar13);
      }
      pppppppppplVar11 = local_c8;
      cVar6 = local_d8;
      cVar5 = '\x01';
      if (local_80[0] == 0x1001) {
        cVar5 = '\0';
        if ((uStack_68 & 0x100000000) != 0) {
          if (local_c8 == (longlong **********)0x0) {
            if (local_d8 != '\0') {
              L2DereferenceNetBufferListContext((longlong)pppppppppplVar8);
            }
            pppppppppplVar8 = (longlong **********)0x0;
          }
          else {
            L2DereferenceNetBufferListContext((longlong)local_c8);
          }
          goto LAB_140004e7c;
        }
LAB_140004e82:
        pppplVar4 = local_b8;
        if (pppppppppplVar11 == (longlong **********)0x0) {
          if (cVar6 != '\0') {
            L2FreeNetBufferListContext((longlong)pppppppppplVar8);
          }
          goto LAB_140004e98;
        }
        if (cVar5 != '\0') {
          *local_b8 = (longlong ***)pppppppppplVar11;
          L2ReferenceNetBufferListContext((longlong)pppppppppplVar11);
          pplVar3 = (*pppplVar4)[2];
          uVar1 = *(ushort *)((longlong)pplVar3 + 10);
          *(code **)((ulonglong)uVar1 + 0x38 + (longlong)pplVar3) =
               L2pDeepCloneNetBufferListCompletionFn;
          *(undefined8 *)((ulonglong)uVar1 + 0x40 + (longlong)pplVar3) = 0;
          L2DereferenceNetBufferListContext((longlong)pppppppppplVar11);
          goto LAB_140004e9d;
        }
        L2FreeNetBufferListContext((longlong)pppppppppplVar11);
      }
      else {
LAB_140004e7c:
        if ((uStack_68 & 0x100000000) == 0) goto LAB_140004e82;
LAB_140004e98:
        if (cVar5 != '\0') {
LAB_140004e9d:
          if (*pppppppppplVar8 != (longlong *********)0x0) {
            pppppppppplVar11 = local_a8;
            param_3 = local_d4;
            goto LAB_140004edb;
          }
        }
      }
      uVar10 = (ulonglong)local_cc;
      pppppppppplVar11 = local_a8;
      if ((local_b8 != (longlong ****)0x0) && ((longlong ****)*local_b8 != (longlong ****)0x0)) {
        local_d0 = local_d0 + 1;
        local_b8 = (longlong ****)*local_b8;
      }
    }
    else {
      if ((int)param_1[7] == 1) {
        cVar5 = L2802_3IsNetBufferListPermitted
                          (0x38,'\0',(longlong *)&local_c8,(longlong *)local_b8,param_1,param_3,
                           param_5);
        if ((local_b8 != (longlong ****)0x0) && ((longlong ****)*local_b8 != (longlong ****)0x0)) {
          local_d0 = local_d0 + 1;
          local_b8 = (longlong ****)*local_b8;
        }
      }
      else {
        cVar5 = vSwitch802_3IsNetBufferListPermitted
                          (2,0x38,'\0',(longlong *)&local_c8,(longlong)param_1);
      }
      pppppppppplVar8 = local_c8;
    }
    param_3 = local_d4;
    local_c8 = pppppppppplVar2;
    if ((cVar5 == '\0') && (local_98 == 0)) {
      uVar10 = uVar10 & 0xffffffffffffff00;
      local_c0 = local_bc + -1;
      local_cc = (uint)uVar10;
      local_d7[0] = 0;
      *local_a0 = (longlong *********)pppppppppplVar2;
      local_bc = local_c0;
      if (pppppppppplVar8 == (longlong **********)0x0) goto LAB_140004dce;
      *pppppppppplVar8 = (longlong *********)pppppppppplVar11;
      pppppppppplVar11 = pppppppppplVar8;
      local_a8 = pppppppppplVar8;
    }
    else {
      uVar10 = uVar10 & 0xff;
      *pppppppppplVar8 = (longlong *********)pppppppppplVar2;
      if (cVar5 == '\0') {
        uVar10 = 0;
      }
      local_cc = (uint)uVar10;
      local_d7[0] = (undefined1)uVar10;
      local_a0 = pppppppppplVar8;
LAB_140004dce:
    }
  } while( true );
}



===== L2InspectNetBufferLists @ 140005270 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1
L2InspectNetBufferLists
          (uint param_1,ushort param_2,longlong *param_3,int *param_4,longlong *param_5,int *param_6
          ,longlong *param_7,longlong *param_8,uint param_9,uint param_10)

{
  longlong *plVar1;
  longlong *plVar2;
  char cVar3;
  char cVar4;
  longlong lVar5;
  longlong *plVar6;
  longlong lVar7;
  longlong *plVar8;
  uint uVar9;
  undefined8 uVar10;
  int iVar11;
  ulonglong uVar12;
  bool bVar13;
  undefined1 auStackY_148 [32];
  undefined1 local_e8;
  char local_e7;
  char local_e6;
  ushort local_e4;
  longlong *local_e0;
  int local_d8;
  int local_d4;
  uint local_d0;
  longlong *local_c8;
  longlong *local_c0;
  longlong *local_b8;
  longlong local_b0;
  int *local_a8;
  longlong *local_a0;
  int *local_98;
  longlong *local_90;
  longlong *local_88;
  longlong *local_80;
  int local_78 [6];
  ulonglong uStack_60;
  undefined8 local_58;
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStackY_148;
  plVar8 = (longlong *)0x0;
  local_90 = param_7;
  local_a0 = param_8;
  local_88 = param_5;
  local_a8 = param_6;
  local_c8 = (longlong *)0x0;
  local_c0 = param_5;
  local_e8 = 1;
  if ((param_1 == 2) && ((param_10 & 2) != 0)) {
    local_e6 = '\x01';
  }
  else {
    local_e6 = '\0';
  }
  local_e4 = param_2;
  local_e0 = (longlong *)*param_3;
  local_d0 = param_1;
  local_b8 = param_3;
  local_98 = param_4;
  local_80 = param_3;
  do {
    plVar6 = local_e0;
    iVar11 = 0;
    if (local_e0 == (longlong *)0x0) {
LAB_14000555e:
      *local_90 = (longlong)plVar8;
      if ((int)param_8[7] == 0) {
        L2InspectNetBufferListsFast
                  (local_d0,local_e4,local_80,local_98,local_88,local_a8,local_90,(longlong)param_8,
                   param_9,(byte)param_10,&local_e8,'\0');
      }
      return local_e8;
    }
    plVar1 = (longlong *)*local_e0;
    *local_e0 = 0;
    if ((int)param_8[7] == 0) {
      local_d8 = 0;
      bVar13 = local_e4 != 0x3b;
      local_58 = 0;
      local_e7 = '\0';
      local_b0 = 0;
      uVar12 = (ulonglong)bVar13;
      local_78[0] = 0;
      local_78[1] = 0;
      local_78[2] = 0;
      local_78[3] = 0;
      local_78[4] = 0;
      local_78[5] = 0;
      uStack_60 = 0;
      if (*(int *)((longlong)param_8 + 0x5c) == 0x10) {
        lVar7 = param_8[uVar12 + (ulonglong)param_9 * 6 + 0x2c];
      }
      else {
        lVar7 = param_8[uVar12 + 0x2a];
      }
      if (lVar7 == 0) {
        plVar8 = (longlong *)0x0;
      }
      else {
        KeAcquireSpinLockRaiseToDpc(param_8 + 6);
        if (*(int *)((longlong)local_a0 + 0x5c) == 0x10) {
          plVar8 = (longlong *)local_a0[uVar12 + (ulonglong)param_9 * 6 + 0x2c];
          iVar11 = (int)local_a0[(ulonglong)param_9 * 6 + 0x2e];
        }
        else {
          plVar8 = (longlong *)local_a0[uVar12 + 0x2a];
          iVar11 = local_d8;
        }
        if (plVar8 != (longlong *)0x0) {
          RoReferenceEx((uint *)(plVar8 + 6));
        }
        KeReleaseSpinLock(param_8 + 6);
        param_8 = local_a0;
      }
      uVar9 = (uint)bVar13;
      if (plVar8 == (longlong *)0x0) {
LAB_14000542f:
        L2pNativeLayerRegularClassify
                  (local_e4,'\0',(longlong)plVar6,param_10,(longlong)param_8,uVar9,param_9,local_78,
                   &local_e7,&local_b0);
      }
      else {
        local_d4 = 0;
        KfdGetLayerCacheEpoch(local_e4);
        if (*(int *)((longlong)plVar8 + 0x2c) != local_d4) {
LAB_140005862:
          LwfLowerPurgeClassifyCache((longlong)param_8,uVar9,param_9);
          goto LAB_14000542f;
        }
        cVar4 = L2pNativeLayerDirectClassify
                          (local_e4,'\0',plVar6,plVar1,(longlong)param_8,param_9,param_10,iVar11,
                           plVar8,local_78,&local_e7,&local_b0);
        if (cVar4 == '\0') goto LAB_140005862;
        L2DereferenceLayerClassifyCache((longlong)plVar8);
      }
      lVar7 = local_b0;
      cVar4 = local_e7;
      cVar3 = '\x01';
      if (local_78[0] == 0x1001) {
        cVar3 = '\0';
        if ((uStack_60 & 0x100000000) != 0) {
          if (local_b0 == 0) {
            if (local_e7 != '\0') {
              L2DereferenceNetBufferListContext((longlong)plVar6);
            }
            plVar6 = (longlong *)0x0;
            local_e0 = (longlong *)0x0;
          }
          else {
            L2DereferenceNetBufferListContext(local_b0);
          }
          goto LAB_14000548e;
        }
LAB_140005494:
        plVar2 = local_c0;
        plVar8 = local_e0;
        if (lVar7 == 0) {
          if (cVar4 != '\0') {
            uVar10 = 0;
            lVar5 = (ulonglong)*(ushort *)(plVar6[2] + 10) + plVar6[2];
            lVar7 = *(longlong *)(lVar5 + 0x18);
            cVar4 = *(char *)(lVar5 + 0x49);
            bVar13 = false;
            if ((*(char *)(lVar5 + 0x22) == '\0') && (*(int *)(lVar7 + 0x38) == 2)) {
              uVar10 = *(undefined8 *)(lVar7 + 0xa0);
              bVar13 = true;
            }
            LOCK();
            *(int *)(lVar7 + 0x14c) = *(int *)(lVar7 + 0x14c) + -2;
            UNLOCK();
            if (*(longlong *)(lVar5 + 0x30) == 0) {
              WfpNblInfoClearFlags(local_e0,2);
            }
            NdisFreeNetBufferListContext(plVar8);
            if (bVar13) {
              (*DAT_14002c590)(uVar10);
            }
            plVar6 = plVar8;
            if (cVar4 != '\0') {
              FwppFreeDeepCloneNetBufferList(plVar8);
            }
          }
          goto LAB_140005511;
        }
        if (cVar3 != '\0') {
          *local_c0 = lVar7;
          L2ReferenceNetBufferListContext(lVar7);
          lVar5 = (ulonglong)*(ushort *)(*(longlong *)(*plVar2 + 0x10) + 10) +
                  *(longlong *)(*plVar2 + 0x10);
          *(code **)(lVar5 + 0x38) = L2pDeepCloneNetBufferListCompletionFn;
          *(undefined8 *)(lVar5 + 0x40) = 0;
          L2DereferenceNetBufferListContext(lVar7);
          goto LAB_140005516;
        }
        L2FreeNetBufferListContext(lVar7);
      }
      else {
LAB_14000548e:
        if ((uStack_60 & 0x100000000) == 0) goto LAB_140005494;
LAB_140005511:
        if (cVar3 != '\0') {
LAB_140005516:
          if (*plVar6 != 0) {
            plVar8 = local_c8;
            goto LAB_14000555e;
          }
        }
      }
      param_3 = local_b8;
      param_5 = local_c0;
      plVar8 = local_c8;
      if ((local_c0 != (longlong *)0x0) &&
         (plVar2 = (longlong *)*local_c0, plVar2 != (longlong *)0x0)) {
        *local_a8 = *local_a8 + 1;
        param_5 = plVar2;
        local_c0 = plVar2;
      }
    }
    else {
      if ((int)param_8[7] == 1) {
        cVar3 = L2802_3IsNetBufferListPermitted
                          (local_e4,'\0',(longlong *)&local_e0,param_5,param_8,param_9,param_10);
        if ((param_5 != (longlong *)0x0) &&
           (plVar6 = (longlong *)*param_5, plVar6 != (longlong *)0x0)) {
          *local_a8 = *local_a8 + 1;
          param_5 = plVar6;
          local_c0 = plVar6;
        }
      }
      else {
        cVar3 = vSwitch802_3IsNetBufferListPermitted
                          (local_d0,local_e4,'\0',(longlong *)&local_e0,(longlong)param_8);
      }
      plVar6 = local_e0;
    }
    if ((cVar3 == '\0') && (local_e6 == '\0')) {
      local_e8 = 0;
      if (local_98 != (int *)0x0) {
        *local_98 = *local_98 + -1;
      }
      *param_3 = (longlong)plVar1;
      if (plVar6 != (longlong *)0x0) {
        *plVar6 = (longlong)plVar8;
        plVar8 = plVar6;
        local_c8 = plVar6;
      }
    }
    else {
      *plVar6 = (longlong)plVar1;
      if (cVar3 == '\0') {
        local_e8 = 0;
      }
      param_3 = plVar6;
      local_b8 = plVar6;
    }
    local_e0 = plVar1;
  } while( true );
}



===== L2802_3IsNetBufferListPermitted @ 1400058c0 =====

char L2802_3IsNetBufferListPermitted
               (ushort param_1,char param_2,longlong *param_3,longlong *param_4,longlong *param_5,
               int param_6,undefined4 param_7)

{
  longlong lVar1;
  bool bVar2;
  char cVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined8 **ppuVar6;
  ushort uVar7;
  undefined4 uVar8;
  ushort uVar9;
  undefined8 in_stack_ffffffffffffff78;
  uint uVar10;
  undefined8 **local_68;
  longlong local_60;
  byte *local_58;
  byte *pbStack_50;
  undefined8 local_48;
  ulonglong local_40;
  undefined4 local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  uVar10 = (uint)((ulonglong)in_stack_ffffffffffffff78 >> 0x20);
  local_58 = (byte *)0x0;
  pbStack_50 = (byte *)0x0;
  local_48 = 0;
  local_40 = 0;
  local_2c = 0;
  local_68 = (undefined8 **)0x0;
  uVar4 = Feature_Firewall_BugFixes_25D_WFPlwfs_L28023_resilience__private_IsEnabledDeviceUsageNoInline
                    ();
  lVar1 = *param_3;
  uVar8 = 0xe;
  bVar2 = false;
  if ((int)uVar4 == 0) {
    pbStack_50 = (byte *)NdisGetDataBuffer(*(undefined8 *)(lVar1 + 8),1,0,1,
                                           (ulonglong)uVar10 << 0x20);
    uVar9 = *(ushort *)(pbStack_50 + 0xc) >> 8 | *(ushort *)(pbStack_50 + 0xc) << 8;
    if (uVar9 < 0x600) {
      uVar8 = 0x16;
      if ((*(int3 *)(pbStack_50 + 0xe) == 0x3aaaa) &&
         (CONCAT21(CONCAT11(pbStack_50[0x11],pbStack_50[0x12]),pbStack_50[0x13]) == 0)) {
        uVar9 = *(ushort *)(pbStack_50 + 0x14) >> 8 | *(ushort *)(pbStack_50 + 0x14) << 8;
      }
      else {
        bVar2 = true;
      }
    }
    uVar4 = *(ulonglong *)(lVar1 + 0xb0);
    uVar7 = ((ushort)(uVar4 >> 3) & 1 | (short)uVar4 * 2) << 0xc |
            (ushort)((uint)uVar4 >> 4) & 0xfff;
    local_48._0_4_ = CONCAT22(uVar7,uVar9);
LAB_140005a99:
    if (bVar2) {
      return '\x01';
    }
    local_60 = (longlong)param_5 + 0x67;
    if (param_1 == 0x38) {
      local_58 = pbStack_50;
      pbStack_50 = pbStack_50 + 6;
    }
    else {
      local_58 = pbStack_50 + 6;
    }
    local_38 = (undefined4)param_5[0xb];
    local_40 = param_5[10];
    local_30 = param_7;
    local_34 = param_6;
    uVar5 = L2LookupMacFlow(&local_68,uVar9,local_58,pbStack_50,uVar7,local_40,param_6,
                            (longlong *)&local_68);
    if ((int)uVar5 < 0) {
      ppuVar6 = (undefined8 **)0x0;
      if ((int)uVar5 != -0x3ffffddb) goto LAB_140005b33;
    }
    else {
      ppuVar6 = local_68;
    }
    cVar3 = L2p802_3IsNblPermitted(ppuVar6,param_5,param_1,param_2,param_3,param_4,uVar8,&local_60);
  }
  else {
    pbStack_50 = (byte *)NdisGetDataBuffer(*(undefined8 *)(lVar1 + 8),0xe,0,1,
                                           (ulonglong)uVar10 << 0x20);
    if (pbStack_50 != (byte *)0x0) {
      uVar9 = *(ushort *)(pbStack_50 + 0xc) >> 8 | *(ushort *)(pbStack_50 + 0xc) << 8;
      if (uVar9 < 0x600) {
        uVar8 = 0x16;
        if ((*(int3 *)(pbStack_50 + 0xe) == 0x3aaaa) &&
           (CONCAT21(CONCAT11(pbStack_50[0x11],pbStack_50[0x12]),pbStack_50[0x13]) == 0)) {
          uVar9 = *(ushort *)(pbStack_50 + 0x14) >> 8 | *(ushort *)(pbStack_50 + 0x14) << 8;
        }
        else {
          bVar2 = true;
        }
      }
      uVar4 = *(ulonglong *)(lVar1 + 0xb0);
      uVar7 = ((ushort)(uVar4 >> 3) & 1 | (short)uVar4 * 2) << 0xc |
              (ushort)((uint)uVar4 >> 4) & 0xfff;
      local_48._0_4_ = CONCAT22(uVar7,uVar9);
      goto LAB_140005a99;
    }
LAB_140005b33:
    cVar3 = '\0';
  }
  return cVar3;
}



===== L2pNativeLayerRegularClassify @ 140005b90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void L2pNativeLayerRegularClassify
               (ushort param_1,char param_2,longlong param_3,uint param_4,longlong param_5,
               int param_6,uint param_7,int *param_8,undefined1 *param_9,longlong *param_10)

{
  bool bVar1;
  int iVar2;
  ulonglong uVar3;
  int *piVar4;
  longlong lVar5;
  undefined1 uVar6;
  longlong lVar7;
  uint uVar8;
  uint uVar9;
  undefined1 uVar10;
  undefined1 auStackY_3e8 [32];
  longlong local_3b0;
  longlong local_3a8;
  uint local_3a0;
  ushort local_398 [4];
  undefined4 *local_390;
  undefined8 ***local_388;
  undefined8 ***local_380;
  undefined1 local_378 [224];
  uint local_298;
  uint local_294;
  uint local_28c;
  undefined8 ***local_178;
  undefined4 local_164;
  int local_160;
  int *local_138;
  undefined4 local_c8 [2];
  int local_c0;
  undefined4 local_b8;
  int local_b0;
  undefined4 local_a8;
  longlong local_a0;
  undefined4 local_98;
  uint local_90;
  undefined4 local_88;
  undefined4 local_80;
  undefined4 local_78;
  uint local_70;
  undefined4 local_68;
  uint local_60;
  undefined4 local_58;
  undefined4 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_3e8;
  uVar6 = 0;
  local_398[1] = 0;
  local_3a0 = param_4;
  memset(local_378,0,0x2a8);
  local_c0 = *(int *)(param_5 + 0x5c);
  local_3a8 = 0;
  bVar1 = false;
  if (local_c0 == 0x10) {
    uVar8 = *(uint *)(param_5 + 0x170 + (ulonglong)param_7 * 0x30);
    uVar9 = 10;
    if ((uVar8 & 0x70) == 0) {
      uVar9 = 2;
    }
  }
  else {
    uVar8 = 0;
    if (local_c0 == 0) {
      uVar9 = 4;
      if (*(int *)(param_5 + 0x60) != 8) {
        uVar9 = 1;
      }
    }
    else {
      uVar9 = 0;
      if (local_c0 == 9) {
        uVar9 = 4;
      }
    }
  }
  local_b0 = *(int *)(param_5 + 0x60);
  local_a0 = param_5 + 0x50;
  local_90 = (uint)*(ushort *)(param_5 + 100);
  local_80 = *(undefined4 *)(param_5 + 0x58);
  local_60 = uVar9 | 0x80;
  if (*(char *)(param_5 + 0x66) == '\0') {
    local_60 = uVar9;
  }
  local_70 = param_7;
  local_50 = *(undefined4 *)(param_5 + 0x3dc);
  local_c8[0] = 3;
  local_b8 = 3;
  local_a8 = 4;
  local_98 = 3;
  local_88 = 3;
  local_78 = 3;
  local_68 = 3;
  local_58 = 3;
  if (uVar8 != 0) {
    local_298 = local_298 | 2;
    local_28c = uVar8;
  }
  if ((local_c0 == 0x10) || (local_c0 == 9)) {
    piVar4 = (int *)((ulonglong)param_7 * 0x30 + 0x174 + param_5);
  }
  else {
    piVar4 = (int *)(param_5 + 0x3a0);
  }
  local_138 = (int *)0x0;
  if (*piVar4 != 0) {
    local_138 = piVar4;
  }
  if ((local_c0 == 9) || ((local_c0 == 0 && (local_b0 == 8)))) {
    if (*(longlong *)(param_3 + 200) == 8) {
      if ((*(uint *)(param_3 + 0x80) & 0x200) != 0) {
        local_294 = local_294 | 1;
      }
    }
    else if ((*(longlong *)(param_3 + 200) == 0xdd86) && ((*(uint *)(param_3 + 0x80) & 0x400) != 0))
    {
      local_294 = local_294 | 2;
    }
  }
  local_164 = 1;
  local_380 = &local_388;
  local_388 = &local_388;
  local_178 = &local_388;
  local_390 = local_c8;
  local_398[2] = 8;
  local_398[3] = 0;
  local_3b0 = param_3;
  local_398[0] = param_1;
  if ((param_1 == 0x3a) && ((local_3a0 & 2) != 0)) {
    lVar7 = FwppDeepCloneNetBufferList(param_3,0,0,&local_3a8);
    if (lVar7 == 0) {
      NdisCopyReceiveNetBufferListInfo(local_3a8,param_3);
      local_3b0 = local_3a8;
      goto LAB_140005da2;
    }
    iVar2 = -0x3fffff66;
LAB_140005ea8:
    if (iVar2 < 0) goto LAB_140005f18;
    if ((local_160 != 0) &&
       (uVar3 = L2pCacheMatchedNativeLayerFilterList
                          (param_5,param_6,param_7,(longlong)local_378,local_398), (int)uVar3 < 0))
    {
      KfdReleaseCachedFilters(&local_388);
    }
    if (*param_8 != 0x1001) goto LAB_140005ec2;
  }
  else {
LAB_140005da2:
    if (param_2 != '\0') {
      if (local_3a8 != 0) goto LAB_140005dc0;
LAB_140005e7e:
      iVar2 = KfdClassify(param_1,local_398,local_378,local_3b0);
      goto LAB_140005ea8;
    }
    if (local_3a8 == 0) {
      uVar10 = 0;
    }
    else {
LAB_140005dc0:
      uVar10 = 1;
      *(undefined8 *)(local_3b0 + 0x78) = *(undefined8 *)(param_5 + 0x48);
    }
    iVar2 = NdisAllocateNetBufferListContext(local_3b0,0x40,0x40,0x6e326c57);
    if (iVar2 == 0) {
      lVar7 = (ulonglong)*(ushort *)(*(longlong *)(local_3b0 + 0x10) + 10) +
              *(longlong *)(local_3b0 + 0x10);
      *(undefined4 *)(lVar7 + 0x10) = 0x6e326c57;
      *(longlong *)(lVar7 + 0x18) = param_5;
      *(ushort *)(lVar7 + 0x20) = param_1;
      *(undefined1 *)(lVar7 + 0x22) = 1;
      *(undefined8 *)(lVar7 + 0x24) = 0;
      *(undefined8 *)(lVar7 + 0x38) = 0;
      *(undefined8 *)(lVar7 + 0x40) = 0;
      *(undefined1 *)(lVar7 + 0x48) = 0;
      *(undefined1 *)(lVar7 + 0x49) = uVar10;
      RoReferenceEx((uint *)(param_5 + 0x14c));
      uVar3 = WfpNblInfoGetFlags(local_3b0);
      if ((uVar3 & 2) == 0) {
        WfpNblInfoSetFlags(local_3b0);
        lVar5 = 0;
      }
      else {
        lVar5 = *(longlong *)(local_3b0 + 0x10) + 0x10 +
                (ulonglong)*(ushort *)(*(longlong *)(local_3b0 + 0x10) + 10);
      }
      *(longlong *)(lVar7 + 0x30) = lVar5;
      *(undefined4 *)(lVar7 + 0x4c) = 1;
      uVar6 = 1;
      goto LAB_140005e7e;
    }
    bVar1 = true;
    if ((((iVar2 == 0x103) || (bVar1 = true, iVar2 == -0x7ffffffb)) ||
        (bVar1 = true, iVar2 == -0x3fffffff)) ||
       ((bVar1 = true, iVar2 == -0x3fffff66 || (bVar1 = true, iVar2 == -0x3fffff45))))
    goto LAB_140005ea8;
    bVar1 = true;
LAB_140005f18:
    *param_8 = 0x1001;
  }
  if ((param_8[7] & 1U) == 0) {
    L2AuditAndDiagPacketDrop(param_1,(longlong)local_c8,local_3b0,(longlong)param_8);
  }
LAB_140005ec2:
  if ((local_3a8 == 0) || (!bVar1)) {
    *param_9 = uVar6;
    *param_10 = local_3a8;
  }
  else {
    FwppFreeDeepCloneNetBufferList(local_3a8);
    *param_9 = uVar6;
    *param_10 = 0;
  }
  return;
}



===== LwfLowerRecvNetBufferLists @ 140006100 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void LwfLowerRecvNetBufferLists
               (longlong *param_1,longlong *********param_2,uint param_3,int param_4,uint param_5)

{
  ushort uVar1;
  longlong **pplVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  longlong *********ppppppppplVar7;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  longlong *********ppppppppplVar8;
  longlong **********pppppppppplVar9;
  int iVar10;
  ulonglong uVar11;
  undefined1 auStackY_138 [32];
  byte local_d8;
  char local_d7;
  char local_d6 [6];
  longlong **********local_d0;
  int local_c8;
  int local_c4;
  longlong ***local_c0;
  uint local_b8;
  longlong ****local_b0;
  int local_a8;
  int local_a4;
  longlong *********local_a0;
  uint local_98;
  longlong **********local_90;
  longlong ***local_88;
  longlong **********local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  ulonglong uStack_60;
  undefined8 local_58;
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStackY_138;
  uVar11 = (ulonglong)param_3;
  local_d0 = (longlong **********)0x0;
  local_88 = (longlong ***)0x0;
  iVar10 = 0;
  local_c4 = 0;
  local_d7 = '\x01';
  local_c8 = param_4;
  local_a0 = param_2;
  iVar4 = KfdIsLayerEmpty(0x3a);
  if ((iVar4 != 0) && (iVar4 = KfdIsLayerEmpty(0x50), iVar4 != 0)) {
    L2NdisFIndicateReceiveNetBufferLists
              ((longlong)param_1,param_1[9],(longlong ***)param_2,param_3,param_4,param_5);
    return;
  }
  uVar6 = KfdIsLayerEmpty(0x3a);
  if (((int)uVar6 == 0) && (*(int *)((longlong)param_1 + 0x5c) != 3)) {
    local_80 = &local_a0;
    local_90 = (longlong **********)0x0;
    local_b8 = (uint)CONCAT71((int7)((ulonglong)uVar6 >> 8),1);
    local_b0 = &local_88;
    local_d7 = '\x01';
    local_98 = param_5 & 2;
LAB_1400062cf:
    do {
      pppppppppplVar9 = (longlong **********)param_2;
      if (pppppppppplVar9 == (longlong **********)0x0) goto LAB_140006446;
      param_2 = *pppppppppplVar9;
      *pppppppppplVar9 = (longlong *********)0x0;
      if ((int)param_1[7] == 0) {
        local_a4 = 0;
        local_78 = 0;
        uStack_70 = 0;
        local_58 = 0;
        local_68 = 0;
        uStack_60 = 0;
        local_d6[0] = '\0';
        local_c0 = (longlong ***)0x0;
        if (*(int *)((longlong)param_1 + 0x5c) == 0x10) {
          local_d0 = (longlong **********)param_1[uVar11 * 6 + 0x2d];
        }
        else {
          local_d0 = (longlong **********)param_1[0x2b];
        }
        if (local_d0 == (longlong **********)0x0) {
LAB_140006399:
          uVar6 = L2pNativeLayerRegularClassify
                            (0x3a,'\0',(longlong)pppppppppplVar9,param_5,(longlong)param_1,1,param_3
                             ,(int *)&local_78,local_d6,(longlong *)&local_c0);
        }
        else {
          KeAcquireSpinLockRaiseToDpc(param_1 + 6);
          if (*(int *)((longlong)param_1 + 0x5c) == 0x10) {
            local_d0 = (longlong **********)param_1[uVar11 * 6 + 0x2d];
            local_a4 = (int)param_1[uVar11 * 6 + 0x2e];
          }
          else {
            local_d0 = (longlong **********)param_1[0x2b];
          }
          if (local_d0 != (longlong **********)0x0) {
            RoReferenceEx((uint *)(local_d0 + 6));
          }
          KeReleaseSpinLock(param_1 + 6);
          if (local_d0 == (longlong **********)0x0) goto LAB_140006399;
          local_a8 = 0;
          KfdGetLayerCacheEpoch(0x3a,&local_a8);
          if ((*(int *)((longlong)local_d0 + 0x2c) != local_a8) ||
             (cVar3 = L2pNativeLayerDirectClassify
                                (0x3a,'\0',pppppppppplVar9,param_2,(longlong)param_1,param_3,param_5
                                 ,local_a4,(longlong *)local_d0,(int *)&local_78,local_d6,
                                 (longlong *)&local_c0), cVar3 == '\0')) {
            LwfLowerPurgeClassifyCache((longlong)param_1,1,param_3);
            goto LAB_140006399;
          }
          uVar6 = L2DereferenceLayerClassifyCache((longlong)local_d0);
        }
        uVar5 = (uint)CONCAT71((int7)((ulonglong)uVar6 >> 8),1);
        local_d8 = 1;
        if ((int)local_78 == 0x1001) {
          uVar5 = (int)((ulonglong)uVar6 >> 8) << 8;
          local_d8 = 0;
          if ((uStack_60 & 0x100000000) != 0) {
            if (local_c0 == (longlong ***)0x0) {
              if (local_d6[0] == '\0') {
                pppppppppplVar9 = (longlong **********)0x0;
              }
              else {
                L2DereferenceNetBufferListContext((longlong)pppppppppplVar9);
                pppppppppplVar9 = (longlong **********)0x0;
                uVar5 = 0;
              }
            }
            else {
              L2DereferenceNetBufferListContext((longlong)local_c0);
              uVar5 = 0;
            }
            goto LAB_1400063f3;
          }
LAB_1400063f9:
          if (local_c0 == (longlong ***)0x0) {
            if (local_d6[0] != '\0') {
              L2FreeNetBufferListContext((longlong)pppppppppplVar9);
              uVar5 = (uint)local_d8;
            }
            goto LAB_140006413;
          }
          if ((char)uVar5 != '\0') {
            *local_b0 = local_c0;
            L2ReferenceNetBufferListContext((longlong)local_c0);
            pplVar2 = (*local_b0)[2];
            uVar1 = *(ushort *)((longlong)pplVar2 + 10);
            *(code **)((longlong)pplVar2 + (ulonglong)uVar1 + 0x38) =
                 L2pDeepCloneNetBufferListCompletionFn;
            *(undefined8 *)((longlong)pplVar2 + (ulonglong)uVar1 + 0x40) = 0;
            L2DereferenceNetBufferListContext((longlong)local_c0);
            uVar5 = (uint)local_d8;
            goto LAB_140006417;
          }
          L2FreeNetBufferListContext((longlong)local_c0);
          uVar5 = (uint)local_d8;
        }
        else {
LAB_1400063f3:
          if ((uStack_60 & 0x100000000) == 0) goto LAB_1400063f9;
LAB_140006413:
          if ((char)uVar5 != '\0') {
LAB_140006417:
            if (*pppppppppplVar9 != (longlong *********)0x0) goto LAB_140006446;
          }
        }
        if ((local_b0 != (longlong ****)0x0) && ((longlong ****)*local_b0 != (longlong ****)0x0)) {
          iVar10 = iVar10 + 1;
          local_c4 = iVar10;
          local_b0 = (longlong ****)*local_b0;
        }
      }
      else {
        local_d0 = pppppppppplVar9;
        if ((int)param_1[7] == 1) {
          cVar3 = L2802_3IsNetBufferListPermitted
                            (0x3a,'\0',(longlong *)&local_d0,(longlong *)local_b0,param_1,param_3,
                             param_5);
          uVar5 = (uint)CONCAT71(extraout_var,cVar3);
          if ((local_b0 != (longlong ****)0x0) && ((longlong ****)*local_b0 != (longlong ****)0x0))
          {
            iVar10 = iVar10 + 1;
            local_c4 = iVar10;
            local_b0 = (longlong ****)*local_b0;
          }
        }
        else {
          cVar3 = vSwitch802_3IsNetBufferListPermitted
                            (2,0x3a,'\0',(longlong *)&local_d0,(longlong)param_1);
          uVar5 = (uint)CONCAT71(extraout_var_00,cVar3);
        }
        pppppppppplVar9 = local_d0;
      }
      if (((char)uVar5 == '\0') && (local_98 == 0)) {
        local_b8 = uVar5 & 0xffffff00;
        local_c8 = param_4 + -1;
        local_d7 = '\0';
        *local_80 = param_2;
        param_4 = local_c8;
        if (pppppppppplVar9 != (longlong **********)0x0) {
          *pppppppppplVar9 = (longlong *********)local_90;
          local_90 = pppppppppplVar9;
          goto LAB_1400062cf;
        }
      }
      else {
        local_b8 = local_b8 & 0xff;
        if ((char)uVar5 == '\0') {
          local_b8 = 0;
        }
        *pppppppppplVar9 = param_2;
        local_d7 = (char)local_b8;
        local_80 = pppppppppplVar9;
      }
    } while( true );
  }
  L2InspectNetBufferListsFast
            (2,0x3a,(longlong *)&local_a0,&local_c8,(longlong *)0x0,(undefined4 *)0x0,
             (longlong *)&local_d0,(longlong)param_1,param_3,(byte)param_5,&local_d7,'\x01');
  ppppppppplVar8 = local_a0;
  if (local_d7 != '\0') {
    L2NdisFIndicateReceiveNetBufferLists
              ((longlong)param_1,param_1[9],(longlong ***)local_a0,param_3,local_c8,param_5);
  }
  if ((param_5 & 2) == 0) goto LAB_140006213;
LAB_140006266:
  ppppppppplVar7 = (longlong *********)WfpGetPacketTagCount();
  while (ppppppppplVar7 != (longlong *********)0x0) {
    FwppNetBufferListEventNotify(ppppppppplVar8,0,9);
    ppppppppplVar8 = (longlong *********)*ppppppppplVar8;
    ppppppppplVar7 = ppppppppplVar8;
  }
LAB_140006213:
  if (local_d0 != (longlong **********)0x0) {
    NdisFReturnNetBufferLists(param_1[9],local_d0,param_5 & 1);
  }
  return;
LAB_140006446:
  local_d0 = local_90;
  if ((int)param_1[7] == 0) {
    L2InspectNetBufferListsFast
              (2,0x3a,(longlong *)&local_a0,&local_c8,(longlong *)&local_88,&local_c4,
               (longlong *)&local_d0,(longlong)param_1,param_3,(byte)param_5,&local_d7,'\0');
    iVar10 = local_c4;
    param_4 = local_c8;
  }
  if (local_88 != (longlong ***)0x0) {
    L2NdisFIndicateReceiveNetBufferLists
              ((longlong)param_1,param_1[9],local_88,param_3,iVar10,param_5 & 0xfffffffd);
  }
  if (local_a0 == (longlong *********)0x0) goto LAB_140006213;
  ppppppppplVar8 = local_a0;
  if ((param_5 & 2) == 0) {
    L2NdisFIndicateReceiveNetBufferLists
              ((longlong)param_1,param_1[9],(longlong ***)local_a0,param_3,param_4,param_5);
    goto LAB_140006213;
  }
  goto LAB_140006266;
}



===== LwfLowerSendNetBufferLists @ 140006780 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void LwfLowerSendNetBufferLists
               (longlong *param_1,longlong *********param_2,uint param_3,uint param_4)

{
  ushort uVar1;
  longlong **********pppppppppplVar2;
  ulonglong uVar3;
  char cVar4;
  int iVar5;
  longlong lVar6;
  longlong *plVar7;
  longlong **********pppppppppplVar8;
  longlong **********pppppppppplVar9;
  undefined1 auStackY_108 [32];
  char local_a8 [8];
  longlong **********local_a0;
  longlong **********local_98;
  longlong *local_90;
  int local_88;
  longlong *********local_80;
  longlong **********local_78;
  int local_70 [6];
  ulonglong uStack_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_108;
  uVar3 = (ulonglong)param_3;
  local_a0 = (longlong **********)0x0;
  local_a8[1] = 1;
  local_80 = param_2;
  iVar5 = KfdIsLayerEmpty(0x3b);
  if ((iVar5 != 0) && (iVar5 = KfdIsLayerEmpty(0x51), iVar5 != 0)) {
    L2NdisFSendNetBufferLists((longlong)param_1,param_1[9],(longlong ***)param_2,param_3,param_4);
    return;
  }
  iVar5 = KfdIsLayerEmpty(0x3b);
  if ((iVar5 == 0) && (*(int *)((longlong)param_1 + 0x5c) != 3)) {
    local_78 = &local_80;
    local_90 = (longlong *)0x0;
    local_a8[1] = 1;
    pppppppppplVar8 = (longlong **********)0x0;
    local_98 = (longlong **********)param_2;
    while (pppppppppplVar9 = local_98, local_98 != (longlong **********)0x0) {
      pppppppppplVar2 = (longlong **********)*local_98;
      *local_98 = (longlong *********)0x0;
      if ((int)param_1[7] == 0) {
        local_98 = (longlong **********)((ulonglong)local_98 & 0xffffffff00000000);
        local_70[0] = 0;
        local_70[1] = 0;
        local_70[2] = 0;
        local_70[3] = 0;
        local_50 = 0;
        local_70[4] = 0;
        local_70[5] = 0;
        uStack_58 = 0;
        local_a8[0] = '\0';
        local_a0 = (longlong **********)0x0;
        if (*(int *)((longlong)param_1 + 0x5c) == 0x10) {
          lVar6 = param_1[uVar3 * 6 + 0x2c];
        }
        else {
          lVar6 = param_1[0x2a];
        }
        if (lVar6 == 0) {
LAB_140006991:
          L2pNativeLayerRegularClassify
                    (0x3b,'\0',(longlong)pppppppppplVar9,param_4,(longlong)param_1,0,param_3,
                     local_70,local_a8,(longlong *)&local_a0);
        }
        else {
          KeAcquireSpinLockRaiseToDpc(param_1 + 6);
          if (*(int *)((longlong)param_1 + 0x5c) == 0x10) {
            plVar7 = (longlong *)param_1[uVar3 * 6 + 0x2c];
            local_98 = (longlong **********)CONCAT44(local_98._4_4_,(int)param_1[uVar3 * 6 + 0x2e]);
          }
          else {
            plVar7 = (longlong *)param_1[0x2a];
          }
          if (plVar7 != (longlong *)0x0) {
            RoReferenceEx((uint *)(plVar7 + 6));
          }
          KeReleaseSpinLock(param_1 + 6);
          if (plVar7 == (longlong *)0x0) goto LAB_140006991;
          local_88 = 0;
          KfdGetLayerCacheEpoch(0x3b);
          if (*(int *)((longlong)plVar7 + 0x2c) != local_88) {
LAB_140006c4f:
            LwfLowerPurgeClassifyCache((longlong)param_1,0,param_3);
            goto LAB_140006991;
          }
          cVar4 = L2pNativeLayerDirectClassify
                            (0x3b,'\0',pppppppppplVar9,pppppppppplVar2,(longlong)param_1,param_3,
                             param_4,(int)local_98,plVar7,local_70,local_a8,(longlong *)&local_a0);
          if (cVar4 == '\0') goto LAB_140006c4f;
          L2DereferenceLayerClassifyCache((longlong)plVar7);
        }
        cVar4 = '\x01';
        if (local_70[0] == 0x1001) {
          cVar4 = '\0';
          if ((uStack_58 & 0x100000000) != 0) {
            if (local_a0 == (longlong **********)0x0) {
              if (local_a8[0] != '\0') {
                L2DereferenceNetBufferListContext((longlong)pppppppppplVar9);
              }
              pppppppppplVar9 = (longlong **********)0x0;
            }
            else {
              L2DereferenceNetBufferListContext((longlong)local_a0);
            }
            goto LAB_1400069e3;
          }
LAB_1400069e9:
          if (local_a0 == (longlong **********)0x0) {
            if (local_a8[0] != '\0') {
              L2FreeNetBufferListContext((longlong)pppppppppplVar9);
            }
            goto LAB_140006a02;
          }
          if (cVar4 != '\0') {
            *local_90 = (longlong)local_a0;
            L2ReferenceNetBufferListContext((longlong)local_a0);
            lVar6 = *(longlong *)(*local_90 + 0x10);
            uVar1 = *(ushort *)(lVar6 + 10);
            *(code **)((ulonglong)uVar1 + 0x38 + lVar6) = L2pDeepCloneNetBufferListCompletionFn;
            *(undefined8 *)((ulonglong)uVar1 + 0x40 + lVar6) = 0;
            L2DereferenceNetBufferListContext((longlong)local_a0);
            goto LAB_140006a07;
          }
          L2FreeNetBufferListContext((longlong)local_a0);
        }
        else {
LAB_1400069e3:
          if ((uStack_58 & 0x100000000) == 0) goto LAB_1400069e9;
LAB_140006a02:
          if (cVar4 != '\0') {
LAB_140006a07:
            if (*pppppppppplVar9 != (longlong *********)0x0) break;
          }
        }
        if ((local_90 != (longlong *)0x0) && ((longlong *)*local_90 != (longlong *)0x0)) {
          _DAT_00000000 = _DAT_00000000 + 1;
          local_90 = (longlong *)*local_90;
        }
      }
      else {
        if ((int)param_1[7] == 1) {
          cVar4 = L2802_3IsNetBufferListPermitted
                            (0x3b,'\0',(longlong *)&local_98,local_90,param_1,param_3,param_4);
          if ((local_90 != (longlong *)0x0) && ((longlong *)*local_90 != (longlong *)0x0)) {
            _DAT_00000000 = _DAT_00000000 + 1;
            local_90 = (longlong *)*local_90;
          }
        }
        else {
          cVar4 = vSwitch802_3IsNetBufferListPermitted
                            (1,0x3b,'\0',(longlong *)&local_98,(longlong)param_1);
        }
        pppppppppplVar9 = local_98;
      }
      local_98 = pppppppppplVar2;
      if (cVar4 == '\0') {
        local_a8[1] = 0;
        *local_78 = (longlong *********)pppppppppplVar2;
        if (pppppppppplVar9 == (longlong **********)0x0) goto LAB_14000694b;
        *pppppppppplVar9 = (longlong *********)pppppppppplVar8;
        pppppppppplVar8 = pppppppppplVar9;
      }
      else {
        *pppppppppplVar9 = (longlong *********)pppppppppplVar2;
        local_78 = pppppppppplVar9;
LAB_14000694b:
      }
    }
    local_a0 = pppppppppplVar8;
    if ((int)param_1[7] != 0) goto LAB_140006850;
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  L2InspectNetBufferListsFast
            (1,0x3b,(longlong *)&local_80,(undefined4 *)0x0,(longlong *)0x0,(undefined4 *)0x0,
             (longlong *)&local_a0,(longlong)param_1,param_3,(byte)param_4,local_a8 + 1,cVar4);
LAB_140006850:
  pppppppppplVar8 = local_a0;
  if (local_80 != (longlong *********)0x0) {
    L2NdisFSendNetBufferLists((longlong)param_1,param_1[9],(longlong ***)local_80,param_3,param_4);
  }
  if (pppppppppplVar8 != (longlong **********)0x0) {
    NdisFSendNetBufferListsComplete(param_1[9],pppppppppplVar8,param_4 & 1);
  }
  return;
}



===== L2InspectNetBufferListsFast @ 140006ca0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void L2InspectNetBufferListsFast
               (int param_1,short param_2,longlong *param_3,undefined4 *param_4,longlong *param_5,
               undefined4 *param_6,longlong *param_7,longlong param_8,uint param_9,byte param_10,
               undefined1 *param_11,char param_12)

{
  longlong lVar1;
  bool bVar2;
  bool bVar3;
  longlong *plVar4;
  int iVar5;
  longlong *plVar6;
  byte bVar7;
  longlong *plVar8;
  undefined1 auStack_1b8 [32];
  longlong *local_198;
  longlong *local_190;
  undefined4 *local_188;
  longlong local_180;
  uint local_178;
  undefined4 local_174;
  ushort local_168;
  undefined4 local_166;
  undefined2 local_162;
  longlong *local_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  longlong *local_130;
  ulonglong local_128;
  undefined8 uStack_120;
  int local_118 [4];
  undefined8 local_108;
  undefined8 local_100;
  undefined4 local_f8;
  undefined4 local_e8 [32];
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined4 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_1b8;
  local_198 = param_7;
  local_48 = 0;
  local_166 = 0;
  local_162 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if ((param_1 == 2) && ((param_10 & 2) != 0)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  local_190 = param_3;
  local_188 = param_4;
  if (param_2 == 0x3a) {
    iVar5 = KfdIsLayerEmpty(0x50);
    local_168 = 0x50;
  }
  else {
    iVar5 = KfdIsLayerEmpty(0x51);
    local_168 = 0x51;
  }
  if (iVar5 != 0) {
    return;
  }
  if (param_5 != (longlong *)0x0) {
    plVar6 = (longlong *)*param_5;
    if (plVar6 != (longlong *)0x0) {
      bVar3 = true;
      goto LAB_140006d6f;
    }
    param_3 = local_190;
  }
  if ((bVar2) && (param_12 == '\0')) {
    return;
  }
  plVar6 = (longlong *)*param_3;
  bVar3 = false;
  if (plVar6 == (longlong *)0x0) {
    return;
  }
LAB_140006d6f:
  if (param_9 < 0x1000000) {
    local_166 = 0;
    local_162 = 0;
    local_138 = 0;
    local_174 = 0;
    local_130 = &local_180;
    local_180 = param_8;
    local_158 = 0;
    uStack_150 = 0;
    local_148 = 0;
    uStack_140 = 0;
    local_128 = 0;
    uStack_120 = 0;
    local_160 = (longlong *)*local_198;
    local_178 = param_9;
    if (local_160 != (longlong *)0x0) {
      local_128 = 4;
      KfdClassify2(&local_168,&local_68);
      local_128 = local_128 & 0xfffffffffffffffb;
    }
    local_160 = plVar6;
    iVar5 = KfdClassify2(&local_168,&local_68);
    if ((iVar5 < 0) || ((int)local_68 == 0x1001)) {
      *param_11 = 0;
      bVar7 = 0;
      local_118[1] = 0;
      local_118[2] = 0;
      local_118[3] = 0;
      lVar1 = *local_130;
      local_100 = 0;
      local_f8 = 0;
      if (*(int *)(lVar1 + 0x5c) == 0x10) {
        bVar7 = (byte)*(undefined4 *)(lVar1 + 0x170 + (ulonglong)*(uint *)(local_130 + 1) * 0x30);
      }
      local_118[0] = (int)local_68;
      local_108 = local_58;
      L2pMarshalNativeLayerFields(lVar1,(int)local_130[1],bVar7,local_e8);
      plVar8 = plVar6;
      do {
        L2AuditAndDiagPacketDrop(local_168,(longlong)local_e8,(longlong)plVar8,(longlong)local_118);
        plVar8 = (longlong *)*plVar8;
      } while (plVar8 != (longlong *)0x0);
      if (bVar2) {
        if (bVar3) {
          plVar6 = (longlong *)*param_5;
          if ((longlong *)*param_5 != (longlong *)0x0) {
            do {
              plVar8 = (longlong *)*plVar6;
              L2FreeNetBufferListContext((longlong)plVar6);
              plVar6 = plVar8;
            } while (plVar8 != (longlong *)0x0);
            *param_5 = 0;
          }
          if (param_6 != (undefined4 *)0x0) {
            *param_6 = 0;
          }
        }
      }
      else {
        plVar8 = (longlong *)*local_198;
        if (plVar8 == (longlong *)0x0) {
          *local_198 = (longlong)plVar6;
        }
        else {
          for (plVar4 = (longlong *)*plVar8; plVar4 != (longlong *)0x0; plVar4 = (longlong *)*plVar4
              ) {
            plVar8 = plVar4;
          }
          *plVar8 = (longlong)plVar6;
        }
        *local_190 = 0;
        if (local_188 != (undefined4 *)0x0) {
          *local_188 = 0;
        }
      }
    }
  }
  else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_D(*(undefined **)((longlong)WPP_GLOBAL_Control + 0x18),10,
             &WPP_55b06a2d6529343c1d592bc39396dd87_Traceguids,param_9);
  }
  return;
}



===== L2NdisFSendNetBufferLists @ 140007020 =====

void L2NdisFSendNetBufferLists
               (longlong param_1,undefined8 param_2,longlong ***param_3,undefined4 param_4,
               uint param_5)

{
  longlong ***ppplVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = 0;
  for (ppplVar1 = param_3; ppplVar1 != (longlong ***)0x0; ppplVar1 = (longlong ***)*ppplVar1) {
    iVar3 = iVar3 + 1;
  }
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x30);
  *(int *)(param_1 + 0x148) = *(int *)(param_1 + 0x148) + iVar3;
  if ((*(int *)(param_1 + 0x3c) == 3) && ((*(uint *)(param_1 + 0x118) & 1) != 0)) {
    KeReleaseSpinLock(param_1 + 0x30,uVar2);
    NdisFSendNetBufferLists(param_2,param_3,param_4,param_5);
  }
  else {
    KeReleaseSpinLock(param_1 + 0x30,uVar2);
    uVar4 = param_5 & 1;
    for (ppplVar1 = param_3; ppplVar1 != (longlong ***)0x0; ppplVar1 = (longlong ***)*ppplVar1) {
      *(undefined4 *)((longlong)ppplVar1 + 0x8c) = 0xc023002a;
    }
    iVar3 = *(int *)(param_1 + 0x38);
    if (iVar3 == 0) {
      LwfLowerSendNetBufferListsComplete(param_1,param_3,uVar4);
    }
    else if (iVar3 == 1) {
      LwfUpperSendNetBufferListsComplete(param_1,param_3,uVar4);
    }
    else if (iVar3 == 2) {
      LwfvSwitchSendNetBufferListsComplete(param_1,param_3,uVar4);
    }
  }
  return;
}



===== L2pMarshalNativeLayerFields @ 140007150 =====

undefined8
L2pMarshalNativeLayerFields(longlong param_1,undefined4 param_2,byte param_3,undefined4 *param_4)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = *(int *)(param_1 + 0x5c);
  uVar4 = 0;
  if (iVar2 == 0) {
    uVar4 = 4;
    if (*(int *)(param_1 + 0x60) != 8) {
      uVar4 = 1;
    }
  }
  else if (iVar2 == 0x10) {
    uVar4 = 10;
    if ((param_3 & 0x70) == 0) {
      uVar4 = 2;
    }
  }
  else if (iVar2 == 9) {
    uVar4 = 4;
  }
  cVar1 = *(char *)(param_1 + 0x66);
  *param_4 = 3;
  param_4[2] = *(undefined4 *)(param_1 + 0x5c);
  param_4[4] = 3;
  param_4[6] = *(undefined4 *)(param_1 + 0x60);
  *(longlong *)(param_4 + 10) = param_1 + 0x50;
  param_4[8] = 4;
  param_4[0xc] = 3;
  param_4[0xe] = (uint)*(ushort *)(param_1 + 100);
  param_4[0x10] = 3;
  param_4[0x12] = *(undefined4 *)(param_1 + 0x58);
  param_4[0x14] = 3;
  param_4[0x16] = param_2;
  param_4[0x18] = 3;
  uVar3 = uVar4 | 0x80;
  if (cVar1 == '\0') {
    uVar3 = uVar4;
  }
  param_4[0x1c] = 3;
  param_4[0x1a] = uVar3;
  param_4[0x1e] = *(undefined4 *)(param_1 + 0x3dc);
  return 8;
}



===== L2NdisFIndicateReceiveNetBufferLists @ 140007240 =====

void L2NdisFIndicateReceiveNetBufferLists
               (longlong param_1,undefined8 param_2,longlong ***param_3,undefined4 param_4,
               int param_5,uint param_6)

{
  int iVar1;
  longlong ***ppplVar2;
  undefined1 uVar3;
  uint uVar4;
  
  uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x30);
  if ((param_6 & 2) == 0) {
    *(int *)(param_1 + 0x148) = *(int *)(param_1 + 0x148) + param_5;
  }
  if ((*(int *)(param_1 + 0x3c) == 3) && ((*(uint *)(param_1 + 0x118) & 2) != 0)) {
    KeReleaseSpinLock(param_1 + 0x30,uVar3);
    NdisFIndicateReceiveNetBufferLists(param_2,param_3,param_4,param_5,param_6);
  }
  else {
    KeReleaseSpinLock(param_1 + 0x30,uVar3);
    if ((param_6 & 2) == 0) {
      uVar4 = param_6 & 1;
      for (ppplVar2 = param_3; ppplVar2 != (longlong ***)0x0; ppplVar2 = (longlong ***)*ppplVar2) {
        *(undefined4 *)((longlong)ppplVar2 + 0x8c) = 0xc023002a;
      }
      iVar1 = *(int *)(param_1 + 0x38);
      if (iVar1 == 0) {
        LwfLowerReturnNetBufferLists(param_1,param_3,uVar4);
      }
      else if (iVar1 == 1) {
        LwfUpperReturnNetBufferLists(param_1,param_3,uVar4);
      }
      else if (iVar1 == 2) {
        LwfvSwitchReturnNetBufferLists(param_1,param_3,uVar4);
      }
    }
  }
  return;
}



===== L2NativeIsNetBufferListPermitted @ 140007390 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char L2NativeIsNetBufferListPermitted
               (ushort param_1,char param_2,longlong *param_3,undefined8 param_4,longlong *param_5,
               longlong param_6,uint param_7,uint param_8)

{
  ushort uVar1;
  longlong lVar2;
  bool bVar3;
  byte bVar4;
  char cVar5;
  longlong lVar6;
  longlong *plVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  uint uVar10;
  ulonglong uVar11;
  undefined1 auStackY_f8 [32];
  char local_98 [4];
  int local_94;
  int local_90;
  longlong local_88;
  undefined8 local_80;
  longlong *local_78;
  int local_70 [6];
  ulonglong uStack_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar9 = (ulonglong)param_7;
  local_78 = param_5;
  local_50 = 0;
  local_98[0] = '\0';
  local_90 = 0;
  uVar11 = (ulonglong)(param_1 != 0x3b);
  local_70[0] = 0;
  local_70[1] = 0;
  local_70[2] = 0;
  local_70[3] = 0;
  local_88 = 0;
  local_70[4] = 0;
  local_70[5] = 0;
  uStack_58 = 0;
  if (*(int *)(param_6 + 0x5c) == 0x10) {
    lVar6 = *(longlong *)(param_6 + 0x160 + (uVar11 + uVar9 * 6) * 8);
  }
  else {
    lVar6 = *(longlong *)(param_6 + 0x150 + uVar11 * 8);
  }
  plVar7 = (longlong *)0x0;
  local_80 = param_4;
  if (lVar6 != 0) {
    bVar4 = KeAcquireSpinLockRaiseToDpc(param_6 + 0x30);
    uVar8 = (ulonglong)bVar4;
    if (*(int *)(param_6 + 0x5c) == 0x10) {
      plVar7 = *(longlong **)(param_6 + 0x160 + (uVar11 + uVar9 * 6) * 8);
      local_90 = *(int *)(param_6 + 0x170 + uVar9 * 0x30);
    }
    else {
      plVar7 = *(longlong **)(param_6 + 0x150 + uVar11 * 8);
    }
    if (plVar7 != (longlong *)0x0) {
      RoReferenceEx((uint *)(plVar7 + 6));
    }
    KeReleaseSpinLock(param_6 + 0x30,uVar8 & 0xff);
  }
  uVar10 = (uint)(param_1 != 0x3b);
  if (plVar7 == (longlong *)0x0) {
LAB_140007442:
    L2pNativeLayerRegularClassify
              (param_1,param_2,*param_3,param_8,param_6,uVar10,param_7,local_70,local_98,&local_88);
  }
  else {
    local_94 = 0;
    KfdGetLayerCacheEpoch(param_1,&local_94);
    if ((*(int *)((longlong)plVar7 + 0x2c) != local_94) ||
       (cVar5 = L2pNativeLayerDirectClassify
                          (param_1,param_2,(undefined8 *)*param_3,local_80,param_6,param_7,param_8,
                           local_90,plVar7,local_70,local_98,&local_88), cVar5 == '\0')) {
      LwfLowerPurgeClassifyCache(param_6,uVar10,param_7);
      goto LAB_140007442;
    }
    L2DereferenceLayerClassifyCache((longlong)plVar7);
  }
  lVar6 = local_88;
  bVar3 = true;
  if (local_70[0] == 0x1001) {
    bVar3 = false;
    if ((uStack_58 & 0x100000000) == 0) goto LAB_1400074a8;
    if (local_88 == 0) {
      if (local_98[0] != '\0') {
        L2DereferenceNetBufferListContext(*param_3);
      }
      *param_3 = 0;
    }
    else {
      L2DereferenceNetBufferListContext(local_88);
    }
  }
  if ((uStack_58 & 0x100000000) != 0) {
    return bVar3;
  }
LAB_1400074a8:
  plVar7 = local_78;
  if (lVar6 == 0) {
    if (local_98[0] == '\0') {
      return bVar3;
    }
    lVar6 = *param_3;
  }
  else if (bVar3) {
    *local_78 = lVar6;
    L2ReferenceNetBufferListContext(lVar6);
    lVar2 = *(longlong *)(*plVar7 + 0x10);
    uVar1 = *(ushort *)(lVar2 + 10);
    *(code **)((ulonglong)uVar1 + 0x38 + lVar2) = L2pDeepCloneNetBufferListCompletionFn;
    *(undefined8 *)((ulonglong)uVar1 + 0x40 + lVar2) = 0;
    L2DereferenceNetBufferListContext(lVar6);
    return '\x01';
  }
  L2FreeNetBufferListContext(lVar6);
  return bVar3;
}



===== vSwitch802_3IsNetBufferListPermitted @ 1400076c0 =====

char vSwitch802_3IsNetBufferListPermitted
               (uint param_1,ushort param_2,char param_3,longlong *param_4,longlong param_5)

{
  longlong lVar1;
  char cVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong local_res20;
  byte *local_58;
  byte *pbStack_50;
  undefined8 local_48;
  longlong lStack_40;
  uint local_38 [4];
  
  lVar1 = *param_4;
  local_38[0] = 0;
  local_38[1] = 0;
  local_48 = 0;
  lStack_40 = (ulonglong)param_1 << 0x20;
  local_res20 = 0;
  local_58 = (byte *)0x0;
  pbStack_50 = (byte *)0x0;
  uVar3 = Feature_Firewall_BugFixes_25D_WFPlwfs_L28023_resilience__private_IsEnabledDeviceUsageNoInline
                    ();
  if ((int)uVar3 == 0) {
    L2802_3ParseMacHeader
              (*param_4,(longlong *)&pbStack_50,(longlong *)&local_58,
               (ushort *)((longlong)&local_48 + 2),(ushort *)((longlong)&local_48 + 4),
               (undefined4 *)&lStack_40,(undefined1 *)&local_48,local_38);
LAB_140007750:
    lVar5 = 0;
    if ((char)local_48 == '\0') {
      uVar4 = L2LookupvSwitchFlow(*(longlong *)(param_5 + 0x98),local_48._2_2_,local_58,pbStack_50,
                                  local_48._4_2_,(uint)*(ushort *)(lVar1 + 0x12a),&local_res20);
      if ((((int)uVar4 + 0x80000000U & 0x80000000) == 0) && ((int)uVar4 != -0x3ffffddb))
      goto LAB_140007827;
      lVar5 = local_res20;
    }
    cVar2 = vSwitchp802_3IsNblPermitted
                      (lVar5,param_5,param_2,param_3,param_4,lVar1 + 0x128,&local_58);
    if ((cVar2 != '\0') || (*param_4 == 0)) {
      if (lVar5 == 0) {
        return cVar2;
      }
      L2RefreshFlow(*(longlong *)(param_5 + 0x98),lVar5);
    }
    if (lVar5 != 0) {
      L2ReleaseFlow(*(longlong *)(param_5 + 0x98),&local_res20);
    }
  }
  else {
    uVar4 = L2802_3ParseMacHeader_25D
                      (*param_4,(longlong *)&pbStack_50,(longlong *)&local_58,
                       (ushort *)((longlong)&local_48 + 2),(ushort *)((longlong)&local_48 + 4),
                       (undefined4 *)&lStack_40,(undefined1 *)&local_48,local_38);
    if (-1 < (int)uVar4) goto LAB_140007750;
LAB_140007827:
    cVar2 = '\0';
  }
  return cVar2;
}



===== L2GetValueFromClassifyContext @ 140007840 =====

ulonglong L2GetValueFromClassifyContext
                    (int param_1,int param_2,short *param_3,undefined8 param_4,undefined4 *param_5,
                    longlong *param_6)

{
  int iVar1;
  uint uVar2;
  longlong *plVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong lVar6;
  int *piVar7;
  uint *puVar8;
  
  if (param_1 == 0) {
    if ((*param_3 == 0x50) || (*param_3 == 0x51)) {
      if (param_2 == 2) {
        *param_6 = **(longlong **)(param_3 + 0x1c) + 0x50;
        *param_5 = 8;
        return 0;
      }
      if (param_2 == 0) {
        lVar6 = **(longlong **)(param_3 + 0x1c) + 0x5c;
      }
      else {
        if (param_2 != 5) {
          if (param_2 != 6) {
            return 0xc00000bb;
          }
          puVar8 = (uint *)(param_3 + 0x24);
          lVar6 = **(longlong **)(param_3 + 0x1c);
          iVar1 = *(int *)(lVar6 + 0x5c);
          if (iVar1 == 0x10) {
            uVar4 = *(uint *)(lVar6 + 0x170 +
                             (ulonglong)*(uint *)(*(longlong **)(param_3 + 0x1c) + 1) * 0x30);
            uVar2 = *puVar8;
            *puVar8 = uVar2 | 2;
            if ((uVar4 & 0x70) != 0) {
              *puVar8 = uVar2 | 10;
            }
          }
          else if (iVar1 == 0) {
            uVar4 = 4;
            if (*(int *)(lVar6 + 0x60) != 8) {
              uVar4 = 1;
            }
            *puVar8 = *puVar8 | uVar4;
          }
          else if (iVar1 == 9) {
            *puVar8 = *puVar8 | 4;
          }
          if (*(char *)(lVar6 + 0x66) != '\0') {
            *puVar8 = *puVar8 | 0x80;
          }
          *param_6 = (longlong)puVar8;
          *param_5 = 4;
          return 0;
        }
        lVar6 = *(longlong *)(param_3 + 0x1c) + 8;
      }
      *param_6 = lVar6;
      *param_5 = 4;
      return 0;
    }
  }
  else if (param_1 != 2) {
    return 0xc00000bb;
  }
  if (param_2 != -0x80000000) {
    return 0xc00000bb;
  }
  plVar3 = *(longlong **)(param_3 + 0x1c);
  lVar6 = *plVar3;
  if ((*(int *)(lVar6 + 0x5c) == 0x10) || (*(int *)(lVar6 + 0x5c) == 9)) {
    if (0xb < *(uint *)(plVar3 + 1)) {
      *param_6 = 0;
      *param_5 = 0;
      uVar5 = WfpReportSysErrorAsNtStatus(plVar3,"L2GetProfileInfo",-0x3ffffff3);
      return uVar5 & 0xffffffff;
    }
    piVar7 = (int *)(lVar6 + 0x174 + (ulonglong)*(uint *)(plVar3 + 1) * 0x30);
  }
  else {
    piVar7 = (int *)(lVar6 + 0x3a0);
  }
  if (*piVar7 == 0) {
    *param_6 = 0;
    *param_5 = 0;
    return 0;
  }
  *param_6 = (longlong)piVar7;
  *param_5 = 0x1c;
  return 0;
}



===== L2CheckAndNotifyNetBufferListEvent @ 140007a20 =====

void L2CheckAndNotifyNetBufferListEvent(undefined8 *param_1,undefined4 param_2)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)WfpGetPacketTagCount();
  while (puVar1 != (undefined8 *)0x0) {
    FwppNetBufferListEventNotify(param_1,0,param_2);
    param_1 = (undefined8 *)*param_1;
    puVar1 = param_1;
  }
  return;
}



===== L2GetCompletedNblCounts @ 140007a80 =====

void L2GetCompletedNblCounts(undefined8 *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = 0;
  *param_2 = 0;
  while (param_1 != (undefined8 *)0x0) {
    param_1 = (undefined8 *)*param_1;
    iVar1 = iVar1 + 1;
    *param_2 = iVar1;
  }
  return;
}



===== L2802_3ParseMacHeader @ 140007aa0 =====

void L2802_3ParseMacHeader
               (longlong param_1,longlong *param_2,longlong *param_3,ushort *param_4,ushort *param_5
               ,undefined4 *param_6,undefined1 *param_7,uint *param_8)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined4 uVar3;
  ushort uVar4;
  
  uVar3 = 0xe;
  if (param_7 != (undefined1 *)0x0) {
    *param_7 = 0;
  }
  lVar2 = NdisGetDataBuffer(*(undefined8 *)(param_1 + 8),1,0,1,0);
  if ((param_4 != (ushort *)0x0) || (param_6 != (undefined4 *)0x0)) {
    uVar4 = *(ushort *)(lVar2 + 0xc) >> 8 | *(ushort *)(lVar2 + 0xc) << 8;
    uVar3 = 0xe;
    if (uVar4 < 0x600) {
      uVar3 = 0x16;
      if ((*(int3 *)(lVar2 + 0xe) == 0x3aaaa) &&
         (CONCAT21(CONCAT11(*(undefined1 *)(lVar2 + 0x11),*(undefined1 *)(lVar2 + 0x12)),
                   *(undefined1 *)(lVar2 + 0x13)) == 0)) {
        uVar4 = *(ushort *)(lVar2 + 0x14) >> 8 | *(ushort *)(lVar2 + 0x14) << 8;
      }
      else if (param_7 != (undefined1 *)0x0) {
        *param_7 = 1;
      }
    }
    if (param_4 != (ushort *)0x0) {
      *param_4 = uVar4;
    }
  }
  if (param_2 != (longlong *)0x0) {
    *param_2 = lVar2;
  }
  if (param_3 != (longlong *)0x0) {
    *param_3 = lVar2 + 6;
  }
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = uVar3;
  }
  if (param_5 != (ushort *)0x0) {
    uVar1 = *(ulonglong *)(param_1 + 0xb0);
    *param_5 = ((ushort)(uVar1 >> 3) & 1 | (short)uVar1 * 2) << 0xc |
               (ushort)((uint)uVar1 >> 4) & 0xfff;
  }
  if (param_8 != (uint *)0x0) {
    *param_8 = *(uint *)(param_1 + 0x130) & 0xffffff;
  }
  return;
}



===== LwfLowerOidRequest @ 140007c40 =====

undefined8 LwfLowerOidRequest(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  longlong local_res8;
  
  iVar1 = *(int *)(param_2 + 0x20);
  uVar4 = 0;
  local_res8 = 0;
  if (((iVar1 == 0xd010308) || (iVar1 == 0x2021e)) && (0xb < *(uint *)(param_2 + 8))) {
    return 0xc0010015;
  }
  if ((*(int *)(param_2 + 4) == 1) && (iVar1 == 0x2021e)) {
    if (*(uint *)(param_2 + 0x30) < 0x1c) {
      *(undefined4 *)(param_2 + 0x38) = 0x1c;
      uVar4 = 0xc0010016;
    }
    else {
      puVar2 = *(undefined8 **)(param_2 + 0x28);
      if ((*(int *)(param_1 + 0x5c) == 0x10) || (*(int *)(param_1 + 0x5c) == 9)) {
        puVar5 = (undefined8 *)(param_1 + 0x174 + (ulonglong)*(uint *)(param_2 + 8) * 0x30);
      }
      else {
        puVar5 = (undefined8 *)(param_1 + 0x3a0);
      }
      uVar3 = puVar2[1];
      *puVar5 = *puVar2;
      puVar5[1] = uVar3;
      puVar5[2] = puVar2[2];
      *(undefined4 *)(puVar5 + 3) = *(undefined4 *)(puVar2 + 3);
      *(undefined4 *)(param_2 + 0x34) = 0x1c;
    }
    return uVar4;
  }
  uVar4 = NdisAllocateCloneOidRequest
                    (*(undefined8 *)(param_1 + 0x48),param_2,0x67326c57,&local_res8);
  if ((int)uVar4 == 0) {
    *(longlong *)(local_res8 + 0xd8) = param_2;
    *(undefined8 *)(local_res8 + 0x10) = *(undefined8 *)(param_2 + 0x10);
    *(longlong *)(param_1 + 0x140) = local_res8;
    uVar4 = NdisFOidRequest(*(undefined8 *)(param_1 + 0x48));
    if ((int)uVar4 != 0x103) {
      LwfLowerOidRequestComplete(param_1,local_res8,(int)uVar4);
      uVar4 = 0x103;
    }
  }
  else {
    iVar1 = *(int *)(param_2 + 4);
    if ((((iVar1 == 0) || (iVar1 == 1)) || (iVar1 == 2)) || (iVar1 != 0xc)) {
      *(undefined8 *)(param_2 + 0x34) = 0;
    }
    else {
      *(undefined8 *)(param_2 + 0x40) = 0;
      *(undefined4 *)(param_2 + 0x3c) = 0;
    }
  }
  return uVar4;
}



===== L2LookupvSwitchFlow @ 140007dd8 =====

undefined8
L2LookupvSwitchFlow(longlong param_1,short param_2,byte *param_3,byte *param_4,short param_5,
                   int param_6,longlong *param_7)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined1 local_res8 [8];
  longlong local_28 [2];
  
  local_28[0] = 0;
  local_res8[0] = 0;
  L2pComputevSwitchFlowHashSignature(param_2,param_3,param_4,param_5,(byte)param_6,local_28);
  RtlAcquireReadLock(param_1,local_res8);
  lVar1 = L2pLookupvSwitchFlow(param_1,local_28[0],param_2,param_3,param_4,param_5,param_6);
  RtlReleaseReadLock(param_1,local_res8[0]);
  if (lVar1 == 0) {
    uVar2 = 0xc0000225;
  }
  else {
    *param_7 = lVar1;
    uVar2 = 0;
  }
  return uVar2;
}



===== RtlReleaseReadLock @ 140007eb0 =====

void RtlReleaseReadLock(longlong param_1,undefined1 param_2)

{
  LOCK();
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
  UNLOCK();
  KeLowerIrql(param_2);
  return;
}



===== WfpFastIoDeviceControl @ 140007ee0 =====

ulonglong WfpFastIoDeviceControl
                    (longlong param_1,undefined8 param_2,int *param_3,char *param_4,uint *param_5,
                    uint param_6,undefined8 param_7,int *param_8,ulonglong param_9)

{
  ulonglong uVar1;
  undefined8 in_stack_ffffffffffffffd8;
  
  if (param_9 == DAT_14002cf80) {
    uVar1 = WfpRioFastIoDeviceControl
                      (param_1,param_2,param_3,param_4,param_5,param_6,in_stack_ffffffffffffffd8,
                       param_8);
  }
  else {
    uVar1 = DAT_14002cf80 & 0xffffffffffffff00;
  }
  return uVar1;
}



===== WfpRioFastIoDeviceControl @ 140007f30 =====

undefined8
WfpRioFastIoDeviceControl
          (longlong param_1,undefined8 param_2,int *param_3,char *param_4,uint *param_5,uint param_6
          ,undefined8 param_7,int *param_8)

{
  uint uVar1;
  uint uVar2;
  longlong ****pppplVar3;
  char cVar4;
  undefined1 uVar5;
  undefined4 uVar6;
  int iVar7;
  longlong ***ppplVar8;
  longlong lVar9;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  undefined4 extraout_var_01;
  undefined4 extraout_var_02;
  undefined4 extraout_var_03;
  undefined4 extraout_var_04;
  ulonglong uVar10;
  uint uVar11;
  int *piVar12;
  char *pcVar13;
  uint uVar14;
  uint local_res10;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  int local_58;
  
  local_res10 = 0xc0000100;
  local_80 = 0;
  uStack_78 = 0;
  local_70 = 0;
  piVar12 = param_3;
  pcVar13 = param_4;
  cVar4 = ExGetPreviousMode();
  uVar11 = 0;
  param_8[2] = 0;
  param_8[3] = 0;
  pppplVar3 = *(longlong *****)(param_1 + 0x18);
  ppplVar8 = (longlong ***)IoGetCurrentProcess();
  if (pppplVar3[0x35] != ppplVar8) {
    *param_8 = -0x3fffffde;
    goto LAB_14000811b;
  }
  if ((param_3 == (int *)0x0) || (uVar14 = (uint)param_4, uVar14 < 4)) {
    *param_8 = -0x3fffff10;
    goto LAB_14000811b;
  }
  if ((cVar4 != '\0') && (((ulonglong)param_3 & 3) != 0)) {
                    /* WARNING: Subroutine does not return */
    ExRaiseDatatypeMisalignment();
  }
  local_58 = *param_3;
  if (local_58 == 2) {
    if (uVar14 < 8) {
      ppplVar8 = (longlong ***)0xc000000d;
    }
    else {
      if ((cVar4 != '\0') && (((ulonglong)param_3 & 3) != 0)) {
                    /* WARNING: Subroutine does not return */
        ExRaiseDatatypeMisalignment();
      }
      uVar10 = (ulonglong)(uint)param_3[1];
      lVar9 = WfpRioFindAndReferenceCq((longlong)pppplVar3,param_3[1]);
      if (lVar9 != 0) {
        uVar5 = KeAcquireSpinLockRaiseToDpc(lVar9);
        uVar14 = *(uint *)(lVar9 + 0x38);
        if ((uVar14 & 2) != 0) {
          uVar1 = **(uint **)(lVar9 + 0x10);
          uVar2 = (*(uint **)(lVar9 + 0x10))[1];
          if (((uVar1 < *(uint *)(lVar9 + 0x1c)) && (uVar2 < *(uint *)(lVar9 + 0x1c))) &&
             ((uVar14 & 1) == 0)) {
            if (((byte)uVar14 & 6) == 6) {
              KeResetEvent(*(undefined8 *)(lVar9 + 0x30));
            }
            *(uint *)(lVar9 + 0x38) = *(uint *)(lVar9 + 0x38) | 1;
            uVar14 = *(uint *)(lVar9 + 0x24);
            if (uVar2 < uVar1) {
              if (uVar14 != *(uint *)(lVar9 + 0x1c)) {
                if (uVar14 < uVar1) goto joined_r0x000140008411;
LAB_140008417:
                WfpRioDequeueNotifyRequests(lVar9,uVar10,piVar12);
              }
            }
            else if (uVar1 <= uVar14) {
joined_r0x000140008411:
              if (uVar14 < uVar2) goto LAB_140008417;
            }
          }
          else {
            uVar11 = 0xc0000184;
          }
          KeReleaseSpinLock(lVar9,uVar5);
          WfpRioDereferenceCqInline(lVar9);
          local_res10 = uVar11;
          goto switchD_140008226_caseD_2;
        }
        KeReleaseSpinLock(lVar9,uVar5);
        WfpRioDereferenceCqInline(lVar9);
      }
      ppplVar8 = (longlong ***)0xc000000d;
    }
    goto LAB_140008118;
  }
  if (local_58 == 6) {
    ppplVar8 = pppplVar3[2];
    KeAcquireInStackQueuedSpinLock(ppplVar8,&local_80);
    do {
    } while (*(int *)(ppplVar8 + 1) != 0);
    ppplVar8 = pppplVar3[8];
    if ((*(char *)(pppplVar3 + 0x30) == '\0') && (ppplVar8 != (longlong ***)0x0)) {
      local_res10 = *(uint *)(ppplVar8 + 1);
      if (local_res10 != 0) goto LAB_1400083a6;
      if (*(char *)(ppplVar8 + 9) != '\0') goto LAB_140008191;
      uVar6 = WfpRioFlushSend(pppplVar3,&local_80,piVar12,pcVar13);
      ppplVar8 = (longlong ***)CONCAT44(extraout_var,uVar6);
    }
    else {
      KeReleaseInStackQueuedSpinLock(&local_80);
      ppplVar8 = (longlong ***)0xc0000008;
    }
    goto LAB_140008118;
  }
  switch(local_58) {
  case 0:
    iVar7 = WfpRioCreateCq((longlong)pppplVar3,(ulonglong)param_3,uVar14,param_5,param_6,cVar4);
    ppplVar8 = (longlong ***)CONCAT44(extraout_var_03,iVar7);
    break;
  case 1:
    ppplVar8 = (longlong ***)WfpRioDestroyCq((longlong)pppplVar3,(ulonglong)param_3,uVar14,cVar4);
    break;
  default:
    goto switchD_140008226_caseD_2;
  case 3:
    uVar6 = WfpRioCreateRqPair((longlong)pppplVar3,(ulonglong)param_3,uVar14,cVar4);
    ppplVar8 = (longlong ***)CONCAT44(extraout_var_04,uVar6);
    break;
  case 4:
    iVar7 = WfpRioRegisterBuffer
                      ((longlong)pppplVar3,(ulonglong)param_3,uVar14,param_5,param_6,cVar4);
    ppplVar8 = (longlong ***)CONCAT44(extraout_var_00,iVar7);
    break;
  case 5:
    uVar6 = WfpRioDeregisterBuffer
                      ((longlong)pppplVar3,(ulonglong)param_3,(ulonglong)param_4 & 0xffffffff,cVar4)
    ;
    ppplVar8 = (longlong ***)CONCAT44(extraout_var_01,uVar6);
    break;
  case 7:
    RtlAcquireWriteLock((longlong)pppplVar3[2]);
    local_res10 = 0;
    WfpRioFlushReceiveQueue((longlong)pppplVar3,0xc0000120);
    goto LAB_1400083a6;
  case 10:
    ppplVar8 = pppplVar3[2];
    KeAcquireInStackQueuedSpinLock(ppplVar8,&local_80);
    do {
    } while (*(int *)(ppplVar8 + 1) != 0);
    *(undefined1 *)(pppplVar3 + 0xe) = 1;
    *(undefined1 *)((longlong)pppplVar3 + 0x72) = 0;
LAB_140008191:
    KeReleaseInStackQueuedSpinLock(&local_80);
    ppplVar8 = (longlong ***)0x0;
    break;
  case 0xb:
    ppplVar8 = pppplVar3[2];
    KeAcquireInStackQueuedSpinLock(ppplVar8,&local_80);
    do {
    } while (*(int *)(ppplVar8 + 1) != 0);
    *(undefined1 *)(pppplVar3 + 0xe) = 0;
    *(undefined1 *)((longlong)pppplVar3 + 0x72) = 0;
    KeReleaseInStackQueuedSpinLock(&local_80);
    ppplVar8 = (longlong ***)0x0;
    break;
  case 0xc:
    RtlAcquireWriteLock((longlong)pppplVar3[2]);
    if (pppplVar3[8] == (longlong ***)0x0) {
      local_res10 = 0xc000000d;
    }
    else {
      WfpRioCloseAndRemoveRioState((longlong)pppplVar3);
    }
LAB_1400083a6:
    KeReleaseInStackQueuedSpinLock(&local_80);
switchD_140008226_caseD_2:
    ppplVar8 = (longlong ***)(ulonglong)local_res10;
    break;
  case 0xd:
    uVar6 = WfpRioInitializeActivityTracking
                      ((longlong)pppplVar3,(ulonglong)param_3,(ulonglong)param_4 & 0xffffffff,cVar4)
    ;
    ppplVar8 = (longlong ***)CONCAT44(extraout_var_02,uVar6);
  }
LAB_140008118:
  *param_8 = (int)ppplVar8;
LAB_14000811b:
  return CONCAT71((int7)((ulonglong)ppplVar8 >> 8),1);
}



===== WfpRioFindAndReferenceCq @ 14000842c =====

longlong WfpRioFindAndReferenceCq(longlong param_1,uint param_2)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 local_res10 [24];
  
  local_res10[0] = 0;
  RtlAcquireReadLock(*(longlong *)(param_1 + 0x10),local_res10);
  if (((param_2 < *(uint *)(param_1 + 0x30)) &&
      (*(longlong *)(*(longlong *)(param_1 + 0x20) + (ulonglong)param_2 * 8) != 0)) &&
     (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x20) + (ulonglong)param_2 * 8),
     *(int *)(lVar3 + 0x2c) == 0)) {
    if (lVar3 != 0) {
      LOCK();
      *(int *)(lVar3 + 0x18) = *(int *)(lVar3 + 0x18) + 1;
      UNLOCK();
    }
  }
  else {
    lVar3 = 0;
  }
  lVar2 = *(longlong *)(param_1 + 0x10);
  LOCK();
  piVar1 = (int *)(lVar2 + 8);
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  KeLowerIrql(CONCAT71((int7)((ulonglong)lVar2 >> 8),local_res10[0]));
  return lVar3;
}



===== WfpRioDereferenceCqInline @ 1400084ac =====

void WfpRioDereferenceCqInline(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x18);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    ExFreePoolWithTag(param_1,0x70646657);
  }
  return;
}



===== RtlAcquireReadLock @ 1400084e0 =====

void RtlAcquireReadLock(longlong param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  char cVar2;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  uVar1 = KfRaiseIrql(2);
  *param_2 = uVar1;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  LOCK();
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  UNLOCK();
  cVar2 = KeTestSpinLock(param_1);
  if (cVar2 == '\0') {
    LOCK();
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
    UNLOCK();
    KeAcquireInStackQueuedSpinLockAtDpcLevel(param_1,&local_28);
    LOCK();
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    UNLOCK();
    KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_28);
  }
  return;
}



===== WfpRioFlushSend @ 140008568 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 WfpRioFlushSend(longlong ****param_1,undefined8 param_2,undefined8 param_3,char *param_4)

{
  longlong *****ppppplVar1;
  int iVar2;
  ulonglong uVar3;
  longlong ******pppppplVar4;
  undefined4 uVar5;
  uint uVar6;
  longlong ******pppppplVar7;
  longlong ******pppppplVar8;
  longlong ******pppppplVar9;
  int iVar10;
  longlong ******local_res18;
  longlong ******local_res20;
  longlong ******local_78;
  longlong *****local_70;
  longlong ******local_68;
  ulonglong local_60;
  undefined8 uStack_58;
  longlong ****local_50;
  
  pppppplVar8 = (longlong ******)param_1[8];
  local_res20 = (longlong ******)&local_res18;
  uVar5 = 0;
  local_70 = (longlong *****)0x0;
  local_50 = (longlong ****)0x0;
  local_res18 = (longlong ******)0x0;
  pppppplVar9 = (longlong ******)0x0;
  iVar10 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_78 = pppppplVar8;
  if (pppppplVar8 != (longlong ******)0x0) {
    do {
      if (pppppplVar8[5] == (longlong *****)0x0) break;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,
                &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids);
      }
      pppppplVar7 = &local_70;
      uVar3 = WfpRioGetNextQueuedSend((longlong)(pppppplVar8 + 3),&local_60,(longlong *)pppppplVar7)
      ;
      ppppplVar1 = local_70;
      if ((char)uVar3 == '\0') {
        uVar3 = Feature_VPN_BugFixes_25A__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar3 == 0) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            pppppplVar7 = (longlong ******)&WPP_69b955bb632732390393ed1a04d5aa40_Traceguids;
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x33,
                    &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids);
          }
          KeReleaseInStackQueuedSpinLock(param_2);
          if (iVar10 != 0) {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
              WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x34,pppppplVar7,pppppplVar9,
                        (char)iVar10);
            }
            goto LAB_140008c46;
          }
        }
        else {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            param_4 = "WfpRioFlushSend";
            WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x30,pppppplVar7,"WfpRioFlushSend");
          }
          if (iVar10 == 0) break;
          *(int *)(param_1 + 9) = *(int *)(param_1 + 9) + iVar10;
          *(int *)((longlong)param_1 + 0x164) = *(int *)((longlong)param_1 + 0x164) + iVar10;
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
LAB_140008c30:
            pppppplVar9 = local_res18;
          }
          else {
            if ((3 < (byte)WPP_GLOBAL_Control[0x29]) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
              param_4 = "WfpRioFlushSend";
              pppppplVar7 = (longlong ******)&WPP_69b955bb632732390393ed1a04d5aa40_Traceguids;
              WPP_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
                        &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids,"WfpRioFlushSend",
                        (char)*(undefined4 *)((longlong)param_1 + 0x164));
            }
            pppppplVar9 = local_res18;
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((byte)WPP_GLOBAL_Control[0x29] < 4)) ||
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_140008c30;
            WPP_SF_sqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,pppppplVar7,param_4,
                       (char)local_res18,(char)iVar10);
          }
          KeReleaseInStackQueuedSpinLock(param_2);
LAB_140008c46:
          (*(code *)param_1[0x37])(param_1,pppppplVar9);
        }
        RtlAcquireWriteLock((longlong)param_1[2]);
        break;
      }
      uVar6 = 0;
      local_68 = (longlong ******)0x0;
      *local_70 = param_1;
      *(undefined4 *)((longlong)local_70 + 0xc) = uStack_58._4_4_;
      local_70[3] = local_50;
      *(undefined4 *)(local_70 + 2) = 0;
      local_70[5] = (longlong ****)0x0;
      if (*(int *)(pppppplVar8 + 1) == 0) {
        pppppplVar7 = (longlong ******)&local_68;
        uVar3 = WfpRioValidateRequestBuffer((longlong *)pppppplVar8,(uint *)&local_60,pppppplVar7);
        if ((char)uVar3 == '\0') goto LAB_14000878f;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          pppppplVar7 = (longlong ******)&WPP_69b955bb632732390393ed1a04d5aa40_Traceguids;
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x36,
                  &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids);
        }
        *(undefined4 *)(ppppplVar1 + 1) = (undefined4)local_60;
        ppppplVar1[5] = (longlong ****)*local_68;
        if ((int)uStack_58 == 0) {
          param_4 = (char *)local_68;
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            pppppplVar7 = (longlong ******)&WPP_69b955bb632732390393ed1a04d5aa40_Traceguids;
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x37,
                    &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids);
          }
          goto LAB_1400087c8;
        }
        pppppplVar7 = (longlong ******)0x0;
        param_4 = (char *)*local_68;
        pppppplVar4 = (longlong ******)
                      NdisAllocateNetBufferAndNetBufferList
                                (WfpRioNetBufferListPool,8,0,param_4,local_60 >> 0x20,
                                 uStack_58 & 0xffffffff);
        if (pppppplVar4 == (longlong ******)0x0) {
          uVar6 = 0xc000009a;
        }
        else {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            param_4 = (char *)pppppplVar4;
            WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x38,pppppplVar7,pppppplVar4);
          }
          iVar10 = iVar10 + 1;
          *(longlong ******)
           ((ulonglong)*(ushort *)((longlong)pppppplVar4[2] + 10) + 0x10 + (longlong)pppppplVar4[2])
               = ppppplVar1;
          *local_res20 = (longlong *****)pppppplVar4;
          local_res20 = pppppplVar4;
          pppppplVar9 = local_res18;
        }
      }
      else {
LAB_14000878f:
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          pppppplVar7 = (longlong ******)&WPP_69b955bb632732390393ed1a04d5aa40_Traceguids;
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x35,
                  &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids);
        }
        *(undefined4 *)(ppppplVar1 + 1) = 0;
LAB_1400087c8:
        uVar6 = 0xc000000d;
      }
      iVar2 = 0;
      if (*(int *)((longlong)pppppplVar8 + 0x44) != *(int *)(pppppplVar8 + 6) + -1) {
        iVar2 = *(int *)((longlong)pppppplVar8 + 0x44) + 1;
      }
      *(int *)((longlong)pppppplVar8 + 0x44) = iVar2;
      if ((int)uVar6 < 0) {
        if (pppppplVar9 != (longlong ******)0x0) goto LAB_140008852;
LAB_14000890a:
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3b,
                   &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids,uVar6);
        }
        param_4 = (char *)(ulonglong)uVar6;
        pppppplVar7 = pppppplVar8;
        WfpRioSendComplete((longlong)ppppplVar1,(longlong)param_1,(longlong)pppppplVar8,uVar6,0);
      }
      else if (*(char *)((longlong)param_1 + 0x71) == '\0') {
LAB_140008852:
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          pppppplVar7 = (longlong ******)&WPP_69b955bb632732390393ed1a04d5aa40_Traceguids;
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x39,
                   &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids,uVar6);
        }
        pppppplVar8 = pppppplVar9;
        if (*(char *)((longlong)param_1 + 0x71) == '\0') {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            pppppplVar7 = (longlong ******)&WPP_69b955bb632732390393ed1a04d5aa40_Traceguids;
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3a,
                    &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids);
          }
          uVar6 = 0xc0000184;
        }
        for (; pppppplVar8 != (longlong ******)0x0; pppppplVar8 = (longlong ******)*pppppplVar8) {
          *(uint *)((longlong)pppppplVar8 + 0x8c) = uVar6;
        }
        param_4 = (char *)0x0;
        WfpRioNblSendComplete
                  ((longlong *)param_1,(longlong *)pppppplVar9,
                   (undefined *)CONCAT71((int7)((ulonglong)pppppplVar7 >> 8),1),'\0');
        pppppplVar7 = (longlong ******)&local_res18;
        pppppplVar9 = (longlong ******)0x0;
        local_res18 = (longlong ******)0x0;
        iVar10 = 0;
        pppppplVar8 = local_78;
        local_res20 = pppppplVar7;
        if ((int)uVar6 < 0) goto LAB_14000890a;
      }
      else {
        uVar3 = Feature_VPN_BugFixes_25A__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar3 == 0) {
          LOCK();
          *(int *)((longlong)param_1 + 0x164) = *(int *)((longlong)param_1 + 0x164) + 1;
          UNLOCK();
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            param_4 = (char *)(ulonglong)*(uint *)((longlong)param_1 + 0x164);
            WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3c,pppppplVar7,
                     *(uint *)((longlong)param_1 + 0x164));
          }
          pppppplVar9 = local_res18;
        }
      }
      uVar3 = Feature_VPN_BugFixes_25A__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar3 == 0) {
        KeReleaseInStackQueuedSpinLock(param_2);
        if (iVar10 == 0x40) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            param_4 = (char *)pppppplVar9;
            WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3f,pppppplVar7,pppppplVar9,0x40);
          }
          goto LAB_1400089b5;
        }
LAB_1400089d6:
        RtlAcquireWriteLock((longlong)param_1[2]);
        pppppplVar8 = (longlong ******)param_1[8];
        local_78 = pppppplVar8;
      }
      else if (iVar10 == 0x40) {
        *(int *)(param_1 + 9) = *(int *)(param_1 + 9) + 0x40;
        *(int *)((longlong)param_1 + 0x164) = *(int *)((longlong)param_1 + 0x164) + 0x40;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          param_4 = "WfpRioFlushSend";
          pppppplVar7 = (longlong ******)&WPP_69b955bb632732390393ed1a04d5aa40_Traceguids;
          WPP_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3d,
                    &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids,"WfpRioFlushSend",
                    (char)*(undefined4 *)((longlong)param_1 + 0x164));
        }
        KeReleaseInStackQueuedSpinLock(param_2);
        pppppplVar9 = local_res18;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          WPP_SF_sqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3e,pppppplVar7,param_4,
                     (char)local_res18,0x40);
        }
LAB_1400089b5:
        (*(code *)param_1[0x37])(param_1,pppppplVar9);
        local_res20 = (longlong ******)&local_res18;
        local_res18 = (longlong ******)0x0;
        pppppplVar9 = (longlong ******)0x0;
        iVar10 = 0;
        goto LAB_1400089d6;
      }
    } while (pppppplVar8 != (longlong ******)0x0);
    if (param_1[8] == (longlong ***)0x0) {
      uVar5 = 0xc0000128;
    }
    else {
      uVar5 = *(undefined4 *)(param_1[8] + 1);
    }
  }
  KeReleaseInStackQueuedSpinLock(param_2);
  return uVar5;
}



===== WfpRioRegisterBuffer @ 140008ca0 =====

int WfpRioRegisterBuffer
              (longlong param_1,ulonglong param_2,uint param_3,uint *param_4,uint param_5,
              char param_6)

{
  undefined4 uVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 in_stack_ffffffffffffff90;
  undefined4 uVar5;
  uint local_60;
  undefined4 local_5c;
  undefined8 local_58;
  longlong local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  
  uVar5 = (undefined4)((ulonglong)in_stack_ffffffffffffff90 >> 0x20);
  local_50 = 0;
  local_58 = 0;
  local_60 = 0;
  local_5c = 0;
  local_48 = 0;
  if (param_3 < 0x18) {
                    /* WARNING: Subroutine does not return */
    ExRaiseStatus(0xc000000d);
  }
  if ((param_6 != '\0') && ((param_2 & 3) != 0)) {
                    /* WARNING: Subroutine does not return */
    ExRaiseDatatypeMisalignment();
  }
  uVar1 = *(undefined4 *)(param_2 + 0x10);
  local_40 = *(undefined8 *)(param_2 + 8);
  uVar4 = 0;
  local_5c = uVar1;
  lVar3 = IoAllocateMdl(local_40,uVar1,0,1,0);
  local_50 = lVar3;
  if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
    ExRaiseStatus(0xc0000017);
  }
  MmProbeAndLockPages(lVar3,param_6,1);
  if ((*(byte *)(lVar3 + 10) & 5) == 0) {
    local_58 = MmMapLockedPagesSpecifyCache
                         (lVar3,0,1,0,uVar4 & 0xffffffff00000000,CONCAT44(uVar5,0x40000010),1);
    local_38 = local_58;
  }
  else {
    local_58 = *(undefined8 *)(lVar3 + 0x18);
  }
  uVar4 = WfpRioCreateRegisteredBuffer(param_1,lVar3,local_58,uVar1,&local_60,&local_48);
  iVar2 = (int)uVar4;
  if (iVar2 == 0) {
    if (param_5 < 4) {
                    /* WARNING: Subroutine does not return */
      ExRaiseStatus(0xc000000d);
    }
    if (param_6 != '\0') {
      ProbeForWrite(param_4,4,4);
    }
    *param_4 = local_60;
    iVar2 = 0;
  }
  else if (lVar3 != 0) {
    MmUnlockPages(lVar3);
    IoFreeMdl(lVar3);
  }
  return iVar2;
}



===== WfpRioCreateRegisteredBuffer @ 140008f20 =====

ulonglong WfpRioCreateRegisteredBuffer
                    (longlong param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                    uint *param_5,undefined8 *param_6)

{
  longlong *plVar1;
  uint *puVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  local_48 = 0;
  uStack_40 = 0;
  *param_6 = 0;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = 0;
  KeAcquireInStackQueuedSpinLock(lVar3,&local_48);
  do {
  } while (*(int *)(lVar3 + 8) != 0);
  if (*(char *)(param_1 + 0x38) == '\0') {
    plVar1 = (longlong *)(param_1 + 0x18);
    puVar2 = (uint *)(param_1 + 0x28);
    uVar6 = *(uint *)(param_1 + 0x2c);
    do {
      if (uVar6 != 0) {
        puVar5 = *(undefined8 **)(*plVar1 + (ulonglong)uVar6 * 8);
        if (puVar5 == (undefined8 *)0x0) goto LAB_140008fdb;
        if (*(int *)(puVar5 + 3) == 2) {
          *(uint *)(param_1 + 0x2c) = uVar6;
          goto LAB_140009009;
        }
      }
      if (uVar6 == *puVar2 - 1) {
        uVar6 = 0;
      }
      else {
        uVar6 = uVar6 + 1;
      }
    } while (uVar6 != *(uint *)(param_1 + 0x2c));
    uVar6 = *puVar2;
    uVar4 = WfpRioGrowTable(plVar1,puVar2);
    uVar7 = uVar4 & 0xffffffff;
    if (-1 < (int)uVar4) {
LAB_140008fdb:
      *(uint *)(param_1 + 0x2c) = uVar6;
      puVar5 = (undefined8 *)ExAllocatePool2(0x40,0x20,0x70646657);
      if (puVar5 == (undefined8 *)0x0) {
        uVar7 = 0xc0000017;
      }
      else {
        *(undefined8 **)(*plVar1 + (ulonglong)uVar6 * 8) = puVar5;
LAB_140009009:
        *(undefined4 *)(puVar5 + 3) = 0;
        uVar7 = 0;
        *puVar5 = param_2;
        puVar5[1] = param_3;
        *(undefined4 *)(puVar5 + 2) = param_4;
        *(undefined4 *)((longlong)puVar5 + 0x14) = 1;
        *param_5 = uVar6;
        *param_6 = puVar5;
      }
    }
  }
  else {
    uVar7 = 0xc0000184;
  }
  KeReleaseInStackQueuedSpinLock(&local_48);
  return uVar7;
}



===== WfpRioDeregisterBuffer @ 140009080 =====

undefined4
WfpRioDeregisterBuffer(longlong param_1,ulonglong param_2,undefined8 param_3,char param_4)

{
  undefined4 local_18;
  
  if ((uint)param_3 < 8) {
    local_18 = 0xc000000d;
  }
  else {
    if ((param_4 != '\0') && ((param_2 & 3) != 0)) {
                    /* WARNING: Subroutine does not return */
      ExRaiseDatatypeMisalignment();
    }
    local_18 = 0;
    WfpRioInvalidateBuffer(param_1,*(uint *)(param_2 + 4),param_3,'\0');
  }
  return local_18;
}



===== WfpRioCloseRegistrationDomain @ 140009114 =====

void WfpRioCloseRegistrationDomain(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  undefined1 uVar2;
  undefined7 uVar3;
  
  uVar2 = (undefined1)param_3;
  uVar3 = (undefined7)((ulonglong)param_3 >> 8);
  *(undefined1 *)(param_1 + 0x38) = 1;
  if (*(longlong *)(param_1 + 0x40) != 0) {
    WfpRioCloseAndRemoveRioState(param_1);
  }
  uVar1 = 0;
  if (*(int *)(param_1 + 0x30) != 0) {
    do {
      uVar2 = 1;
      WfpRioInvalidateCq(param_1,uVar1,'\x01');
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint *)(param_1 + 0x30));
  }
  uVar1 = 0;
  if (*(int *)(param_1 + 0x28) != 0) {
    do {
      WfpRioInvalidateBuffer(param_1,uVar1,CONCAT71(uVar3,uVar2),'\x01');
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint *)(param_1 + 0x28));
  }
  ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x18),0x70646657);
  ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x20),0x70646657);
  *(undefined8 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined8 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  return;
}



===== WfpRioInvalidateBuffer @ 1400091bc =====

void WfpRioInvalidateBuffer(longlong param_1,uint param_2,undefined8 param_3,char param_4)

{
  longlong lVar1;
  bool bVar2;
  undefined8 *puVar3;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  puVar3 = (undefined8 *)0x0;
  bVar2 = false;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  if (param_4 == '\0') {
    lVar1 = *(longlong *)(param_1 + 0x10);
    KeAcquireInStackQueuedSpinLock(lVar1,&local_38);
    do {
    } while (*(int *)(lVar1 + 8) != 0);
  }
  if ((param_2 < *(uint *)(param_1 + 0x28)) &&
     (puVar3 = *(undefined8 **)(*(longlong *)(param_1 + 0x18) + (ulonglong)param_2 * 8),
     puVar3 != (undefined8 *)0x0)) {
    if (*(int *)(puVar3 + 3) == 0) {
      bVar2 = true;
      *(undefined4 *)(puVar3 + 3) = 1;
    }
    else if (*(int *)(puVar3 + 3) == 2) {
      ExFreePoolWithTag(puVar3,0x70646657);
      *(undefined8 *)(*(longlong *)(param_1 + 0x18) + (ulonglong)param_2 * 8) = 0;
    }
  }
  if (param_4 == '\0') {
    KeReleaseInStackQueuedSpinLock(&local_38);
  }
  if (bVar2) {
    WfpRioDereferenceBuffer(param_1,puVar3,param_2,param_4);
  }
  return;
}



===== WfpRioGrowTable @ 1400092b0 =====

undefined8 WfpRioGrowTable(undefined8 *param_1,uint *param_2)

{
  uint uVar1;
  void *_Dst;
  undefined8 uVar2;
  ulonglong uVar3;
  
  uVar1 = *param_2;
  if (uVar1 < 0x40) {
    uVar3 = (ulonglong)(uVar1 * 2);
  }
  else if (uVar1 < 0xffc1) {
    uVar3 = (ulonglong)(uVar1 + 0x40);
  }
  else {
    uVar3 = 0x10000;
    if (0xffff < uVar1) {
      return 0xc00000ce;
    }
  }
  _Dst = (void *)ExAllocatePool2(0x40,uVar3 << 3,0x70646657);
  if (_Dst == (void *)0x0) {
    uVar2 = 0xc0000017;
  }
  else {
    memmove(_Dst,(void *)*param_1,(ulonglong)*param_2 << 3);
    memset((void *)((longlong)_Dst + (ulonglong)*param_2 * 8),0,
           (ulonglong)((uint)uVar3 - *param_2) << 3);
    uVar2 = *param_1;
    *param_1 = _Dst;
    *param_2 = (uint)uVar3;
    ExFreePoolWithTag(uVar2,0x70646657);
    uVar2 = 0;
  }
  return uVar2;
}



===== L2pLookupvSwitchFlow @ 140009380 =====

longlong L2pLookupvSwitchFlow
                   (longlong param_1,longlong param_2,short param_3,undefined8 param_4,
                   undefined8 param_5,short param_6,int param_7)

{
  bool bVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  lVar2 = RtlLookupEntryHashTable
                    (param_1 + 0x10,param_2 << ((byte)*(undefined4 *)(param_1 + 0x38) & 0x3f),
                     &local_38);
  while( true ) {
    if (lVar2 == 0) {
      return 0;
    }
    bVar1 = L2pIsSamevSwitchFlow(lVar2 + -0x10,param_3,param_4,param_5,param_6,param_7);
    if ((bVar1) && (uVar3 = RoReferenceEx((uint *)(lVar2 + 0x60)), (char)uVar3 != '\0')) break;
    lVar2 = RtlGetNextEntryHashTable(param_1 + 0x10,&local_38);
  }
  return lVar2 + -0x10;
}



===== EthernetAddressType @ 140009460 =====

int EthernetAddressType(byte *param_1)

{
  int iVar1;
  
  if ((*param_1 & 1) == 0) {
    return 0;
  }
  iVar1 = memcmp(param_1,&eui48_broadcast,6);
  return 2 - (uint)(iVar1 != 0);
}



===== WfpRioReceiveNbl @ 1400094a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WfpRioReceiveNbl(longlong param_1,undefined8 *param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  int iVar4;
  char cVar5;
  undefined8 *puVar6;
  longlong *local_res8;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_res8 = (longlong *)0x0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  cVar5 = '\x01';
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5e,
            &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x10);
  KeAcquireInStackQueuedSpinLock(lVar1,&local_38);
  do {
  } while (*(int *)(lVar1 + 8) != 0);
  if (((*(int *)(param_1 + 0x4c) == 3) || (*(char *)(param_1 + 0x180) != '\0')) ||
     (*(longlong *)(param_1 + 0x40) == 0)) {
    puVar6 = param_2;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5f,
              &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids);
    }
    for (; puVar6 != (undefined8 *)0x0; puVar6 = (undefined8 *)*puVar6) {
      *(undefined4 *)((longlong)puVar6 + 0x8c) = 0xc000021b;
    }
  }
  else {
    puVar6 = param_2;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x60,
              &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids);
    }
    for (; puVar6 != (undefined8 *)0x0; puVar6 = (undefined8 *)*puVar6) {
      uVar2 = WfpRioNblReceiveHandler(param_1,(longlong)puVar6,cVar5,&local_res8);
      cVar5 = '\0';
      if ((int)uVar2 < 0) {
        iVar4 = 0;
        if (puVar6 != (undefined8 *)0x0) {
          while( true ) {
            *(undefined4 *)((longlong)puVar6 + 0x8c) = 0xc000021b;
            if (local_res8 != (longlong *)0x0) {
              do {
                local_res8 = (longlong *)*local_res8;
                iVar4 = iVar4 + 1;
              } while (local_res8 != (longlong *)0x0);
              local_res8 = (longlong *)0x0;
            }
            puVar6 = (undefined8 *)*puVar6;
            if (puVar6 == (undefined8 *)0x0) break;
            local_res8 = (longlong *)puVar6[1];
          }
        }
        **(int **)(param_1 + 0x138) = **(int **)(param_1 + 0x138) + iVar4;
        break;
      }
    }
  }
  if ((*(int *)(param_1 + 0x4c) == 3) || (*(char *)(param_1 + 0x70) != '\0')) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((3 < (byte)WPP_GLOBAL_Control[0x29] && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x61,
              &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids);
    }
    if (*(char *)(param_1 + 0x72) == '\0') {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x62,
                &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids);
      }
      uVar3 = WfpRioQueueBiNotification(param_1);
      if ((char)uVar3 != '\0') {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),99,
                  &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids);
        }
        *(undefined1 *)(param_1 + 0x72) = 1;
      }
    }
  }
  KeReleaseInStackQueuedSpinLock(&local_38);
  (**(code **)(param_1 + 0x1c0))(param_1,param_2);
  return;
}



===== WfpRioNblReceiveHandler @ 140009784 =====

ulonglong WfpRioNblReceiveHandler
                    (longlong param_1,longlong param_2,char param_3,undefined8 *param_4)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  undefined2 uVar5;
  int *piVar6;
  ulonglong uVar7;
  int *local_res8;
  uint local_38 [2];
  int *local_30;
  
  piVar6 = *(int **)(param_2 + 8);
  uVar4 = 0;
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_38[0] = 0;
  local_38[1] = 0;
  local_res8 = (int *)0x0;
  LOCK();
  UNLOCK();
  uVar2 = FwpsNetBufferListRetrieveContext0(param_2,8,0,0,&local_res8);
  uVar7 = (ulonglong)uVar2;
  if ((int)uVar2 < 0) {
    if ((((uVar2 != 0xc0000225) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x49,
               &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids,uVar2);
    }
  }
  else {
    local_30 = local_res8;
    if (*local_res8 == 1) {
      local_38[0] = 2;
    }
    else if (*local_res8 == 2) {
      local_38[0] = 3;
    }
    else {
      local_38[0] = 4;
    }
    uVar4 = WfpRioRecvBufferReceiveHandler(param_1,local_38,param_3,uVar7);
    iVar3 = (int)uVar4;
    uVar4 = uVar4 & 0xffffffff;
    if (iVar3 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return uVar4;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return uVar4;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return uVar4;
      }
      uVar5 = 0x4a;
      goto LAB_14000993c;
    }
  }
  *param_4 = 0;
  while( true ) {
    if (piVar6 == (int *)0x0) {
      return uVar4;
    }
    if (*(int *)(lVar1 + 8) != 0) {
      return uVar4;
    }
    *param_4 = piVar6;
    local_38[0] = 1;
    local_38[1] = 0;
    local_30 = piVar6;
    uVar4 = WfpRioRecvBufferReceiveHandler(param_1,local_38,param_3,uVar7);
    iVar3 = (int)uVar4;
    uVar4 = uVar4 & 0xffffffff;
    if (iVar3 < 0) break;
    piVar6 = *(int **)piVar6;
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((byte)WPP_GLOBAL_Control[0x29] < 2)) || ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) {
    return uVar4;
  }
  uVar5 = 0x4b;
LAB_14000993c:
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
           &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids,iVar3);
  return uVar4;
}



===== WfpRioRecvBufferReceiveHandler @ 140009958 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong WfpRioRecvBufferReceiveHandler
                    (longlong param_1,uint *param_2,char param_3,ulonglong param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint *puVar4;
  ulonglong uVar5;
  undefined1 auStack_78 [32];
  uint local_48 [6];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_78;
  lVar1 = *(longlong *)(param_1 + 0x40);
  puVar4 = local_48;
  uVar5 = 0;
  uVar3 = 0;
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  local_48[4] = 0;
  local_48[5] = 0;
  uVar2 = wfp_rio_rq_deque(*(uint **)(lVar1 + 0x60),*(uint *)(lVar1 + 0x68),puVar4);
  if ((int)uVar2 == 1) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      puVar4 = (uint *)&WPP_69b955bb632732390393ed1a04d5aa40_Traceguids;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x43,
              &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids);
    }
    if ((param_3 != '\0') && ((*(uint *)(param_1 + 0xb8) & 4) != 0)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((3 < (byte)WPP_GLOBAL_Control[0x29] && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)))
         ) {
        puVar4 = (uint *)&WPP_69b955bb632732390393ed1a04d5aa40_Traceguids;
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x44,
                &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids);
      }
      uVar3 = WfpRioSwitchToActive(param_1);
      uVar3 = uVar3 & 0xff;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)
         ) {
        param_4 = uVar3;
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x45,puVar4,(int)uVar3);
      }
    }
    puVar4 = local_48;
    uVar2 = WfpRioHandleReceive(param_1,puVar4,param_2,param_4,(char)uVar3);
    uVar5 = uVar2 & 0xffffffff;
    if (-1 < (int)uVar2) {
      if ((*(uint *)(param_1 + 0xb8) & 2) != 0) {
        *(undefined8 *)(param_1 + 0xc0) = _DAT_fffff78000000008;
      }
      if ((char)uVar3 != '\0') {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          puVar4 = (uint *)0x46;
          WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x46,param_2,param_1);
        }
        *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) & 0xfffffffb;
        *(undefined8 *)(param_1 + 0xc0) = 0;
        *(undefined8 *)(param_1 + 200) = 0;
        *(undefined4 *)(param_1 + 0xd8) = 0;
        *(undefined8 *)(param_1 + 0xe8) = 0;
        *(undefined8 *)(param_1 + 0xf0) = 0;
        if ((*(uint *)(param_1 + 0xb8) & 1) != 0) {
          *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) | 2;
          WfpRioTrackIdle(param_1,puVar4,param_2);
        }
      }
    }
  }
  else if ((int)uVar2 == 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x47,
              &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids);
    }
    uVar5 = 0xc0000001;
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x48,
              &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids);
    }
    if (-1 < *(int *)(lVar1 + 8)) {
      *(undefined4 *)(lVar1 + 8) = 0xc0000232;
    }
  }
  return uVar5;
}



===== wfp_rio_rq_deque @ 140009c1c =====

ulonglong wfp_rio_rq_deque(uint *param_1,uint param_2,void *param_3)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = *param_1;
  uVar2 = param_1[1];
  if ((uVar1 < param_2) && (uVar2 < param_2)) {
    if (uVar2 == uVar1) {
      uVar3 = 0;
    }
    else {
      if (uVar1 < uVar2) {
        uVar3 = (ulonglong)(uVar2 != uVar1);
        memmove(param_3,param_1 + (ulonglong)uVar1 * 6 + 4,uVar3 * 0x18);
      }
      else {
        uVar3 = (ulonglong)(param_2 != uVar1);
        memmove(param_3,param_1 + (ulonglong)uVar1 * 6 + 4,uVar3 * 0x18);
        uVar5 = (uint)(param_2 != uVar1);
        uVar4 = 1 - uVar5;
        if (uVar4 <= uVar2) {
          uVar2 = uVar4;
        }
        if (uVar2 != 0) {
          memmove((void *)((longlong)param_3 + uVar3 * 0x18),param_1 + 4,(ulonglong)uVar2 * 0x18);
          uVar3 = (ulonglong)(uVar5 + uVar2);
        }
      }
      LOCK();
      *param_1 = ((int)uVar3 + uVar1) % param_2;
      UNLOCK();
    }
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}



===== WfpRioHandleReceive @ 140009d24 =====

undefined8
WfpRioHandleReceive(longlong param_1,uint *param_2,uint *param_3,undefined8 param_4,
                   undefined1 param_5)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  longlong *plVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  uint *puVar7;
  undefined8 *puVar8;
  uint uVar9;
  longlong lVar10;
  undefined8 **ppuVar11;
  ulonglong uVar12;
  uint uVar13;
  longlong local_58;
  undefined8 *local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  plVar4 = *(longlong **)(param_1 + 0x40);
  local_58 = 0;
  local_50 = (undefined8 *)0x0;
  uVar13 = 0;
  lVar10 = 0;
  uVar9 = 0;
  if ((int)plVar4[1] != 0) {
LAB_140009e6d:
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x40,
              &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids);
    }
    return 0xc000000d;
  }
  ppuVar11 = &local_50;
  puVar7 = param_2;
  uVar5 = WfpRioValidateRequestBuffer(plVar4,param_2,ppuVar11);
  puVar8 = local_50;
  if ((char)uVar5 == '\0') goto LAB_140009e6d;
  if (local_50 != (undefined8 *)0x0) {
    uVar9 = *param_3;
    lVar10 = *(longlong *)(param_3 + 2);
    if (uVar9 == 1) {
      uVar5 = (ulonglong)*(uint *)(lVar10 + 0x18);
      puVar7 = (uint *)(ulonglong)*(uint *)(lVar10 + 0x28);
      uVar3 = *(uint *)(lVar10 + 0x18);
      if (param_2[2] <= uVar5) {
        uVar3 = param_2[2];
      }
      ppuVar11 = (undefined8 **)*local_50;
      RtlCopyMdlToMdl(*(undefined8 *)(lVar10 + 0x20),puVar7,ppuVar11,param_2[1],uVar3,&local_58);
    }
    else {
      if (uVar9 == 2) {
        uVar6 = *(undefined8 *)(lVar10 + 8);
        uVar5 = 0x1a0;
      }
      else {
        uVar5 = (ulonglong)*(uint *)(lVar10 + 8);
        uVar6 = *(undefined8 *)(lVar10 + 0x10);
      }
      ppuVar11 = (undefined8 **)(ulonglong)param_2[1];
      puVar7 = (uint *)*local_50;
      uVar12 = uVar5;
      if (param_2[2] <= uVar5) {
        uVar12 = (ulonglong)param_2[2];
      }
      RtlCopyBufferToMdl(uVar6,puVar7,ppuVar11,uVar12,&local_58);
    }
    *(int *)(plVar4 + 0xe) = (int)local_58;
    lVar10 = uVar5 - local_58;
    if (lVar10 != 0) {
      uVar13 = 0x80000005;
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),puVar7,ppuVar11,(int)lVar10);
  }
  uVar3 = *param_2;
  if (*(int *)((longlong)puVar8 + 0x14) != 1) {
    LOCK();
    piVar1 = (int *)((longlong)puVar8 + 0x14);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 != 1) goto LAB_140009e1e;
    puVar8 = local_50;
  }
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  *(undefined8 *)(*(longlong *)(param_1 + 0x18) + (ulonglong)uVar3 * 8) = 0;
  WfpRioCleanupBuffer(puVar8);
LAB_140009e1e:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x42,
            &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids);
  }
  uVar6 = WfpRioQueueReceiveCompletion(plVar4 + 10,(ulonglong)param_2,uVar13,param_5,uVar9);
  return uVar6;
}



===== WfpRioValidateRequestBuffer @ 140009f88 =====

ulonglong WfpRioValidateRequestBuffer(longlong *param_1,uint *param_2,undefined8 *param_3)

{
  uint *puVar1;
  uint uVar2;
  longlong lVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  uint uVar6;
  
  uVar2 = *param_2;
  uVar5 = (ulonglong)uVar2;
  if ((((uVar2 != 0) && (lVar3 = *param_1, *(char *)(lVar3 + 0x38) == '\0')) &&
      (uVar2 < *(uint *)(lVar3 + 0x28))) &&
     ((puVar4 = *(undefined8 **)(*(longlong *)(lVar3 + 0x18) + uVar5 * 8),
      puVar4 != (undefined8 *)0x0 && (*(int *)(puVar4 + 3) == 0)))) {
    LOCK();
    *(int *)((longlong)puVar4 + 0x14) = *(int *)((longlong)puVar4 + 0x14) + 1;
    UNLOCK();
    uVar6 = param_2[2] + param_2[1];
    if ((param_2[1] <= uVar6) && (uVar6 <= *(uint *)(puVar4 + 2))) {
      *param_3 = puVar4;
      return CONCAT71((uint7)(uint3)(uVar2 >> 8),1);
    }
    uVar2 = *param_2;
    lVar3 = *param_1;
    if (*(int *)((longlong)puVar4 + 0x14) != 1) {
      LOCK();
      puVar1 = (uint *)((longlong)puVar4 + 0x14);
      uVar6 = *puVar1;
      uVar5 = (ulonglong)uVar6;
      *puVar1 = *puVar1 - 1;
      UNLOCK();
      if (uVar6 != 1) goto LAB_14000a003;
    }
    *(undefined8 *)(*(longlong *)(lVar3 + 0x18) + (ulonglong)uVar2 * 8) = 0;
    uVar5 = WfpRioCleanupBuffer(puVar4);
  }
LAB_14000a003:
  *param_3 = 0;
  return uVar5 & 0xffffffffffffff00;
}



===== WfpRioSendComplete @ 14000a034 =====

void WfpRioSendComplete(longlong param_1,longlong param_2,longlong param_3,undefined4 param_4,
                       undefined1 param_5)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined8 *puVar4;
  
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x20) = param_4;
  WfpRioQueueSendCompletion((longlong *)(param_3 + 0x18),*(undefined8 *)(param_3 + 0x10),param_5);
  uVar3 = *(uint *)(param_1 + 8);
  if (uVar3 != 0) {
    puVar4 = *(undefined8 **)(*(longlong *)(param_2 + 0x18) + (ulonglong)uVar3 * 8);
    if (*(int *)((longlong)puVar4 + 0x14) != 1) {
      LOCK();
      piVar1 = (int *)((longlong)puVar4 + 0x14);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 != 1) {
        return;
      }
    }
    *(undefined8 *)(*(longlong *)(param_2 + 0x18) + (ulonglong)uVar3 * 8) = 0;
    WfpRioCleanupBuffer(puVar4);
  }
  return;
}



===== WfpRioQueueSendCompletion @ 14000a0b8 =====

undefined8 WfpRioQueueSendCompletion(longlong *param_1,undefined8 param_2,undefined1 param_3)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  longlong lVar5;
  longlong lVar6;
  uint *puVar7;
  undefined8 uVar8;
  undefined1 uVar9;
  uint uVar10;
  ulonglong uVar11;
  
  lVar5 = *param_1;
  uVar9 = KeAcquireSpinLockRaiseToDpc(lVar5);
  puVar1 = (uint *)(param_1 + 5);
  uVar10 = *puVar1;
  if (uVar10 != *(uint *)((longlong)param_1 + 0x2c)) {
    do {
      lVar6 = *(longlong *)(param_1[4] + (ulonglong)uVar10 * 8);
      if (*(int *)(lVar6 + 0x20) == 0x103) break;
      if (uVar10 == (int)param_1[3] - 1U) {
        uVar10 = 0;
      }
      else {
        uVar10 = uVar10 + 1;
      }
      *puVar1 = uVar10;
      if ((uint *)param_1[2] != (uint *)0x0) {
        *(uint *)param_1[2] = uVar10;
      }
      LOCK();
      UNLOCK();
      if (*(int *)(lVar5 + 0x2c) == 0) {
        puVar7 = *(uint **)(lVar5 + 0x10);
        uVar10 = *(uint *)(lVar5 + 0x1c);
        uVar2 = *(uint *)(lVar6 + 0x10);
        uVar3 = *(uint *)(lVar6 + 0x20);
        uVar4 = puVar7[1];
        uVar8 = *(undefined8 *)(lVar6 + 0x18);
        if ((((*puVar7 < uVar10) && (uVar4 < uVar10)) && ((char)puVar7[2] == '\0')) &&
           (uVar10 = (uVar4 + 1) % uVar10, uVar10 != *puVar7)) {
          uVar11 = (ulonglong)uVar4;
          *(undefined8 *)(puVar7 + uVar11 * 8 + 6) = param_2;
          *(undefined8 *)(puVar7 + uVar11 * 8 + 8) = uVar8;
          puVar7[uVar11 * 8 + 4] = uVar3;
          puVar7[uVar11 * 8 + 5] = uVar2;
          *(undefined1 *)(puVar7 + uVar11 * 8 + 10) = param_3;
          puVar7[uVar11 * 8 + 0xb] = 1;
          LOCK();
          puVar7[1] = uVar10;
          UNLOCK();
        }
        else {
          *(undefined1 *)(puVar7 + 2) = 1;
        }
        WfpRioUpdateNotifyState(lVar5,(ulonglong)uVar4,(ulonglong)*(uint *)(lVar6 + 0xc));
      }
      uVar10 = *puVar1;
    } while (uVar10 != *(uint *)((longlong)param_1 + 0x2c));
  }
  KeReleaseSpinLock(lVar5,uVar9);
  return 0;
}



===== WfpRioUpdateNotifyState @ 14000a228 =====

void WfpRioUpdateNotifyState(longlong param_1,undefined8 param_2,ulonglong param_3)

{
  if ((param_3 & 1) == 0) {
    *(int *)(param_1 + 0x24) = (int)param_2;
    WfpRioDequeueNotifyRequests(param_1,param_2,param_3);
  }
  else if (*(int *)(param_1 + 0x24) == (int)param_2) {
    *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 0x1c);
  }
  return;
}



===== WfpRioQueueReceiveCompletion @ 14000a254 =====

undefined8
WfpRioQueueReceiveCompletion
          (longlong *param_1,ulonglong param_2,uint param_3,undefined1 param_4,uint param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  uint *puVar5;
  undefined8 uVar6;
  undefined1 uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  
  uVar1 = *(uint *)(param_1 + 4);
  lVar4 = *param_1;
  *(undefined4 *)(param_1 + 4) = 0;
  uVar9 = param_2;
  uVar7 = KeAcquireSpinLockRaiseToDpc(lVar4);
  if (*(int *)(lVar4 + 0x2c) != 0) {
    KeReleaseSpinLock(lVar4,uVar7);
    return 0xc0000232;
  }
  puVar5 = *(uint **)(lVar4 + 0x10);
  uVar2 = *(uint *)(lVar4 + 0x1c);
  uVar6 = *(undefined8 *)(param_2 + 0x10);
  uVar3 = puVar5[1];
  if (((*puVar5 < uVar2) && (uVar3 < uVar2)) && ((char)puVar5[2] == '\0')) {
    uVar9 = (ulonglong)(uVar3 + 1) % (ulonglong)uVar2;
    if ((uint)uVar9 != *puVar5) {
      uVar8 = (ulonglong)uVar3;
      (puVar5 + uVar8 * 8 + 6)[0] = 0;
      (puVar5 + uVar8 * 8 + 6)[1] = 0;
      *(undefined8 *)(puVar5 + uVar8 * 8 + 8) = uVar6;
      puVar5[uVar8 * 8 + 4] = param_3;
      puVar5[uVar8 * 8 + 5] = uVar1;
      *(undefined1 *)(puVar5 + uVar8 * 8 + 10) = param_4;
      puVar5[uVar8 * 8 + 0xb] = param_5;
      LOCK();
      uVar1 = puVar5[1];
      puVar5[1] = (uint)uVar9;
      uVar9 = (ulonglong)uVar1;
      UNLOCK();
      goto LAB_14000a302;
    }
  }
  *(undefined1 *)(puVar5 + 2) = 1;
LAB_14000a302:
  if ((*(uint *)(param_2 + 0xc) & 1) == 0) {
    *(uint *)(lVar4 + 0x24) = uVar3;
    WfpRioDequeueNotifyRequests(lVar4,uVar9,puVar5);
  }
  else if (*(uint *)(lVar4 + 0x24) == uVar3) {
    *(undefined4 *)(lVar4 + 0x24) = *(undefined4 *)(lVar4 + 0x1c);
  }
  KeReleaseSpinLock(lVar4,uVar7);
  return 0;
}



===== WfpRioDequeueNotifyRequests @ 14000a378 =====

void WfpRioDequeueNotifyRequests(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_LL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,
              *(uint *)(param_1 + 0x38) & 1,(byte)(*(uint *)(param_1 + 0x38) >> 1) & 1);
  }
  uVar1 = *(uint *)(param_1 + 0x38);
  if (((uVar1 & 1) != 0) && (*(uint *)(param_1 + 0x38) = uVar1 & 0xfffffffe, (uVar1 & 2) != 0)) {
    KeSetEvent(*(undefined8 *)(param_1 + 0x30),2,0);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((3 < (byte)WPP_GLOBAL_Control[0x29] && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
              &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids);
    }
  }
  return;
}



===== WfpRioQueueBiNotification @ 14000a430 =====

undefined8 WfpRioQueueBiNotification(longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined **ppuVar3;
  undefined8 uVar4;
  
  lVar1 = IoAllocateWorkItem(*(undefined8 *)(param_1 + 0x1b0));
  if (lVar1 == 0) {
    uVar4 = 0;
  }
  else {
    uVar2 = RoReferenceEx((uint *)(param_1 + 0x160));
    if ((char)uVar2 == '\0') {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5c,
                &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids);
      }
      ppuVar3 = (undefined **)IoFreeWorkItem(lVar1);
    }
    else {
      IoQueueWorkItemEx(lVar1,WfpRioBiSignalWorkItem,1,param_1);
      ppuVar3 = &WPP_GLOBAL_Control;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (ppuVar3 = (undefined **)(ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
         (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        ppuVar3 = (undefined **)
                  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5b,
                          &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids);
      }
    }
    uVar4 = CONCAT71((int7)((ulonglong)ppuVar3 >> 8),1);
  }
  return uVar4;
}



===== WfpRioFindCqUnderLock @ 14000a51c =====

longlong WfpRioFindCqUnderLock(longlong param_1,uint param_2,char param_3)

{
  longlong lVar1;
  longlong lVar2;
  
  if (param_2 < *(uint *)(param_1 + 0x30)) {
    if (*(longlong *)(*(longlong *)(param_1 + 0x20) + (ulonglong)param_2 * 8) != 0) {
      lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x20) + (ulonglong)param_2 * 8);
      if (param_3 != '\0') {
        lVar1 = 0;
        if (*(int *)(lVar2 + 0x2c) == 0) {
          lVar1 = lVar2;
        }
        lVar2 = lVar1;
      }
      return lVar2;
    }
  }
  return 0;
}



===== WfpRioGetNextQueuedSend @ 14000a558 =====

ulonglong WfpRioGetNextQueuedSend(longlong param_1,undefined8 *param_2,longlong *param_3)

{
  undefined8 *puVar1;
  uint uVar2;
  longlong lVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  
  uVar2 = *(uint *)(param_1 + 0x2c);
  uVar6 = (ulonglong)uVar2;
  uVar5 = (ulonglong)(uVar2 + 1) / (ulonglong)*(uint *)(param_1 + 0x18);
  if ((uVar2 + 1) % *(uint *)(param_1 + 0x18) != *(uint *)(param_1 + 0x28)) {
    uVar5 = *(ulonglong *)(param_1 + 0x20);
    lVar3 = *(longlong *)(uVar5 + uVar6 * 8);
    *param_3 = lVar3;
    *(undefined4 *)(lVar3 + 0x20) = 0x103;
    lVar3 = *(longlong *)(param_1 + 0x10);
    if (uVar2 != *(uint *)(lVar3 + 4)) {
      puVar1 = (undefined8 *)(lVar3 + 0x10 + uVar6 * 0x18);
      uVar4 = puVar1[1];
      *param_2 = *puVar1;
      param_2[1] = uVar4;
      param_2[2] = *(undefined8 *)(lVar3 + 0x20 + uVar6 * 0x18);
      return CONCAT71((int7)(uVar6 * 3 >> 8),1);
    }
  }
  return uVar5 & 0xffffffffffffff00;
}



===== LwfUpperStatusIndication @ 14000a5c0 =====

void LwfUpperStatusIndication(longlong param_1,longlong param_2)

{
  short *psVar1;
  
  if (((*(int *)(param_2 + 0x14) == 0x400200b0) && (*(int *)(param_2 + 0x38) == 0x22)) &&
     (psVar1 = *(short **)(param_2 + 0x30), *psVar1 == 6)) {
    *(undefined4 *)(param_1 + 0x67) = *(undefined4 *)(psVar1 + 1);
    *(short *)(param_1 + 0x6b) = psVar1[3];
  }
  NdisFIndicateStatus(*(undefined8 *)(param_1 + 0x48));
  return;
}



===== WfpRioDereferenceBuffer @ 14000a610 =====

void WfpRioDereferenceBuffer(longlong param_1,undefined8 *param_2,uint param_3,char param_4)

{
  int *piVar1;
  int iVar2;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  if (*(int *)((longlong)param_2 + 0x14) != 1) {
    LOCK();
    piVar1 = (int *)((longlong)param_2 + 0x14);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 != 1) {
      return;
    }
  }
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if (param_4 == '\0') {
    RtlAcquireWriteLock(*(longlong *)(param_1 + 0x10));
  }
  *(undefined8 *)(*(longlong *)(param_1 + 0x18) + (ulonglong)param_3 * 8) = 0;
  if (param_4 == '\0') {
    KeReleaseInStackQueuedSpinLock(&local_28);
  }
  WfpRioCleanupBuffer(param_2);
  return;
}



===== L2RetrieveNetBufferListCompletionContext @ 14000a6b0 =====

void L2RetrieveNetBufferListCompletionContext
               (longlong param_1,undefined8 *param_2,undefined8 *param_3)

{
  longlong lVar1;
  
  lVar1 = (ulonglong)*(ushort *)(*(longlong *)(param_1 + 0x10) + 10) + *(longlong *)(param_1 + 0x10)
  ;
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = *(undefined8 *)(lVar1 + 0x38);
  }
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = *(undefined8 *)(lVar1 + 0x40);
  }
  return;
}



===== RtlAcquireWriteLock @ 14000a6dc =====

void RtlAcquireWriteLock(longlong param_1)

{
  KeAcquireInStackQueuedSpinLock();
  do {
  } while (*(int *)(param_1 + 8) != 0);
  return;
}



===== WfpRioSendCompleteNbl @ 14000a710 =====

void WfpRioSendCompleteNbl(longlong *param_1,longlong *param_2)

{
  WfpRioNblSendComplete(param_1,param_2,(undefined *)0x0,'\x01');
  return;
}



===== WfpRioNblSendComplete @ 14000a72c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WfpRioNblSendComplete(longlong *param_1,longlong *param_2,undefined *param_3,char param_4)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  longlong *plVar6;
  char cVar7;
  undefined *puVar8;
  longlong *plVar9;
  char local_res10;
  longlong local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  local_res10 = '\0';
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  plVar6 = param_2;
  puVar8 = param_3;
  uVar4 = Feature_VPN_BugFixes_25A__private_IsEnabledDeviceUsageNoInline();
  cVar7 = (char)param_3;
  if ((int)uVar4 == 0) {
    if (cVar7 == '\0') {
LAB_14000a841:
      plVar6 = &local_48;
      RtlAcquireWriteLock(param_1[2]);
    }
LAB_14000a781:
    uVar4 = Feature_VPN_BugFixes_25A__private_IsEnabledDeviceUsageNoInline();
    if (((int)uVar4 == 0) ||
       (((*(int *)((longlong)param_1 + 0x4c) != 3 && ((char)param_1[0x30] == '\0')) &&
        (param_1[8] != 0)))) {
joined_r0x00014000a7ae:
      plVar9 = param_2;
      if (param_2 != (longlong *)0x0) {
        while( true ) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),plVar6,puVar8,plVar9,
                      (char)*(undefined4 *)((longlong)plVar9 + 0x8c));
          }
          puVar8 = (undefined *)param_1[8];
          lVar2 = *(longlong *)((ulonglong)*(ushort *)(plVar9[2] + 10) + 0x10 + plVar9[2]);
          *(undefined4 *)(lVar2 + 0x10) = 0;
          if ((*(uint *)(param_1 + 0x17) & 2) != 0) {
            param_1[0x18] = _DAT_fffff78000000008;
          }
          if ((*(uint *)(param_1 + 0x17) & 4) != 0) {
            uVar5 = WfpRioSwitchToActive((longlong)param_1);
            local_res10 = (char)uVar5;
          }
          plVar6 = param_1;
          WfpRioSendComplete(lVar2,(longlong)param_1,(longlong)puVar8,
                             *(undefined4 *)((longlong)plVar9 + 0x8c),local_res10);
          if (local_res10 != '\0') {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
              plVar6 = (longlong *)0x2b;
              WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,puVar8,param_1);
            }
            uVar1 = *(uint *)(param_1 + 0x17);
            uVar3 = uVar1 & 0xfffffffb;
            param_1[0x18] = 0;
            *(uint *)(param_1 + 0x17) = uVar3;
            param_1[0x19] = 0;
            *(undefined4 *)(param_1 + 0x1b) = 0;
            param_1[0x1d] = 0;
            param_1[0x1e] = 0;
            if ((uVar1 & 1) != 0) {
              *(uint *)(param_1 + 0x17) = uVar3 | 2;
              WfpRioTrackIdle((longlong)param_1,plVar6,puVar8);
            }
          }
          param_2 = (longlong *)*plVar9;
          NdisFreeNetBufferList(plVar9);
          if (param_4 == '\0') {
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((byte)WPP_GLOBAL_Control[0x29] < 4)) ||
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto joined_r0x00014000a7ae;
            plVar6 = (longlong *)0x2e;
            goto LAB_14000aa47;
          }
          uVar4 = Feature_VPN_BugFixes_25A__private_IsEnabledDeviceUsageNoInline();
          if ((int)uVar4 == 0) break;
          *(int *)((longlong)param_1 + 0x164) = *(int *)((longlong)param_1 + 0x164) + -1;
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            puVar8 = &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids;
            plVar6 = (longlong *)0x2c;
            WPP_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
                      &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids,"WfpRioNblSendComplete",
                      (char)*(undefined4 *)((longlong)param_1 + 0x164));
          }
          KeReleaseInStackQueuedSpinLock(&local_48);
          WfpRioDecrementReferenceCount((longlong)param_1,plVar6,puVar8);
          if (param_2 == (longlong *)0x0) {
            return;
          }
          plVar6 = &local_48;
          RtlAcquireWriteLock(param_1[2]);
          plVar9 = param_2;
        }
        LOCK();
        *(int *)((longlong)param_1 + 0x164) = *(int *)((longlong)param_1 + 0x164) + -1;
        UNLOCK();
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          plVar6 = (longlong *)0x2d;
LAB_14000aa47:
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(short)plVar6,puVar8,
                   *(undefined4 *)((longlong)param_1 + 0x164));
        }
        goto joined_r0x00014000a7ae;
      }
      if (cVar7 == '\0') {
        KeReleaseInStackQueuedSpinLock(&local_48);
      }
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)
         ) {
        plVar6 = (longlong *)0x28;
        WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,puVar8,"WfpRioNblSendComplete");
      }
      if (param_4 != '\0') {
        *(int *)((longlong)param_1 + 0x164) = *(int *)((longlong)param_1 + 0x164) + -1;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          puVar8 = &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids;
          plVar6 = (longlong *)0x29;
          WPP_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
                    &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids,"WfpRioNblSendComplete",
                    (char)*(undefined4 *)((longlong)param_1 + 0x164));
        }
        KeReleaseInStackQueuedSpinLock(&local_48);
        WfpRioDecrementReferenceCount((longlong)param_1,plVar6,puVar8);
      }
    }
  }
  else {
    if (param_4 == '\0') {
      if (cVar7 != '\0') goto LAB_14000a781;
    }
    else if (cVar7 == '\0') goto LAB_14000a841;
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      WPP_SF_sdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18));
    }
  }
  return;
}



===== L2AllocateNetBufferListContext @ 14000ab60 =====

int L2AllocateNetBufferListContext(longlong param_1,int param_2,uint *param_3,short param_4)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  bool bVar7;
  
  iVar2 = 0;
  puVar6 = (undefined8 *)0x0;
  KeAcquireSpinLockRaiseToDpc(&DAT_14002ce90);
  if ((ushort)(param_4 - 0x38U) < 2) {
    for (puVar5 = DAT_14002ce98; puVar6 = (undefined8 *)0x0, (undefined8 **)puVar5 != &DAT_14002ce98
        ; puVar5 = (undefined8 *)*puVar5) {
      if (*(int *)(puVar5 + 0xb) == param_2) goto LAB_14000abd9;
    }
  }
  else if ((ushort)(param_4 - 0x3aU) < 2) {
    for (puVar5 = DAT_14002ceb0; puVar6 = (undefined8 *)0x0, (undefined8 **)puVar5 != &DAT_14002ceb0
        ; puVar5 = (undefined8 *)*puVar5) {
      if (*(int *)(puVar5 + 0xb) == param_2) goto LAB_14000abd9;
    }
  }
  else if (param_4 == 0x48) {
    for (puVar5 = DAT_14002cec8; puVar6 = (undefined8 *)0x0, (undefined8 **)puVar5 != &DAT_14002cec8
        ; puVar5 = (undefined8 *)*puVar5) {
      uVar3 = (uint)*(ushort *)(puVar5[0xe] + 8);
      if ((*param_3 == uVar3) &&
         (uVar4 = RtlCompareMemory(*(undefined8 *)(param_3 + 2),puVar5[0xe] + 10,uVar3),
         uVar4 == *(ushort *)(puVar5[0xe] + 8))) goto LAB_14000abd9;
    }
  }
  else {
    iVar2 = -0x3fddffcb;
  }
LAB_14000abde:
  KeReleaseSpinLock(&DAT_14002ce90);
  if (-1 < iVar2) {
    if (puVar6 == (undefined8 *)0x0) {
      iVar2 = -0x3fddffc2;
    }
    else {
      uVar1 = KeAcquireSpinLockRaiseToDpc(puVar6 + 6);
      if ((*(int *)((longlong)puVar6 + 0x3c) == 3) || (*(int *)((longlong)puVar6 + 0x3c) == 4)) {
        uVar4 = L2pAllocateNetBufferListContext(param_1,'\0',(longlong)puVar6,'\0',param_4,0,0);
        iVar2 = (int)uVar4;
        if (((iVar2 != 0) &&
            (((iVar2 != 0x103 && (iVar2 != -0x7ffffffb)) && (iVar2 != -0x3fffffff)))) &&
           ((iVar2 != -0x3fffff66 && (iVar2 != -0x3fffff45)))) {
          if (iVar2 == -0x3ffeffea) {
            iVar2 = -0x3fffffdd;
          }
          else if (iVar2 == -0x3ffeffec) {
            iVar2 = -0x3ffffdfa;
          }
          else {
            bVar7 = iVar2 == -0x3ffeffeb;
            iVar2 = -0x3fffffff;
            if (bVar7) {
              iVar2 = -0x3ffffff3;
            }
          }
        }
      }
      else {
        iVar2 = -0x3fddffc2;
      }
      LOCK();
      *(int *)((longlong)puVar6 + 0x14c) = *(int *)((longlong)puVar6 + 0x14c) + -2;
      UNLOCK();
      KeReleaseSpinLock(puVar6 + 6,uVar1);
    }
  }
  return iVar2;
LAB_14000abd9:
  RoReferenceEx((uint *)((longlong)puVar5 + 0x14c));
  puVar6 = puVar5;
  goto LAB_14000abde;
}



===== RtlAcquireWriteLockAtDpcLevel @ 14000adb8 =====

void RtlAcquireWriteLockAtDpcLevel(longlong param_1)

{
  KeAcquireInStackQueuedSpinLockAtDpcLevel();
  do {
  } while (*(int *)(param_1 + 8) != 0);
  return;
}



===== L2SetNetBufferListCompletionContext @ 14000adf0 =====

void L2SetNetBufferListCompletionContext(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  ushort uVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(param_1 + 0x10);
  uVar1 = *(ushort *)(lVar2 + 10);
  *(undefined8 *)((ulonglong)uVar1 + 0x38 + lVar2) = param_2;
  *(undefined8 *)((ulonglong)uVar1 + 0x40 + lVar2) = param_3;
  return;
}



===== PplpGenericAllocateFunction @ 14000ae10 =====

void PplpGenericAllocateFunction(void)

{
  longlong in_R9;
  
  ExAllocateFromLookasideListEx(*(undefined8 *)(in_R9 + 0x60));
  return;
}



===== L2vSwitchExtentionAdapterChangeNotification @ 14000ae30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void L2vSwitchExtentionAdapterChangeNotification(void)

{
  int iVar1;
  longlong lVar2;
  int in_R9D;
  undefined1 auStack_318 [32];
  undefined8 local_2f8 [2];
  undefined1 local_2e8 [16];
  undefined *local_2d8;
  undefined4 local_2d0;
  undefined4 local_2c8;
  undefined4 local_2c4;
  undefined8 *local_2c0;
  undefined4 local_2b8;
  undefined1 *local_290;
  undefined4 local_288;
  undefined1 local_278 [536];
  longlong local_60;
  longlong local_58;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_318;
  memset(local_278,0,600);
  memset(local_2e8,0,0x68);
  local_2f8[0] = 0;
  local_2d0 = 0;
  local_2d8 = &NPI_MS_NDIS_MODULEID;
  local_2c0 = local_2f8;
  local_290 = local_278;
  local_2b8 = 8;
  local_2c8 = 1;
  local_2c4 = 1;
  local_288 = 600;
  if (in_R9D == 1) {
    local_2c4 = 0;
    NsiGetAllParametersEx(local_2e8);
    local_60 = local_60 - _gvSwitchExtentionAdapterGuid;
    if (local_60 == 0) {
      local_60 = local_58 - _DAT_14002ce78;
    }
    if (local_60 == 0) {
      DAT_14002cf28 = DAT_14002cf28 + 1;
    }
  }
  else if (in_R9D == 2) {
    local_2c4 = 0;
    NsiGetAllParametersEx(local_2e8);
    local_60 = local_60 - _gvSwitchExtentionAdapterGuid;
    if (local_60 == 0) {
      local_60 = local_58 - _DAT_14002ce78;
    }
    if (local_60 == 0) {
      DAT_14002cf28 = DAT_14002cf28 + -1;
    }
  }
  else if (in_R9D == 3) {
    iVar1 = NsiGetAllParametersEx(local_2e8);
    while (iVar1 != -0x7fffffe6) {
      lVar2 = local_60 - _gvSwitchExtentionAdapterGuid;
      if (lVar2 == 0) {
        lVar2 = local_58 - _DAT_14002ce78;
      }
      if (lVar2 == 0) {
        DAT_14002cf28 = DAT_14002cf28 + 1;
      }
      local_2c4 = 2;
      iVar1 = NsiGetAllParametersEx(local_2e8);
    }
  }
  return;
}



===== LwfUpperAttach @ 14000b000 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong LwfUpperAttach(longlong param_1,undefined8 param_2,longlong param_3)

{
  code *pcVar1;
  char cVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  uint uVar5;
  longlong *plVar6;
  ulonglong uVar7;
  undefined4 local_res20;
  undefined4 local_res24;
  longlong *local_18 [2];
  
  plVar6 = (longlong *)ExAllocatePool2(0x40,0x3e0);
  if (plVar6 == (longlong *)0x0) {
    uVar7 = 0xc000009a;
  }
  else {
    *(undefined4 *)(plVar6 + 7) = 1;
    *(undefined4 *)((longlong)plVar6 + 0x3c) = 1;
    plVar6[9] = param_1;
    plVar6[10] = *(longlong *)(param_3 + 0x88);
    *(undefined4 *)(plVar6 + 0xb) = *(undefined4 *)(param_3 + 0x18);
    *(undefined4 *)((longlong)plVar6 + 0x5c) = *(undefined4 *)(param_3 + 0x48);
    *(undefined4 *)(plVar6 + 0xc) = *(undefined4 *)(param_3 + 0x4c);
    *(undefined2 *)((longlong)plVar6 + 100) = *(undefined2 *)(param_3 + 0x8e);
    *(undefined1 *)((longlong)plVar6 + 0x66) = *(undefined1 *)(param_3 + 200);
    *(undefined1 *)(plVar6 + 8) = 0;
    plVar6[0x28] = 0;
    *(undefined4 *)(plVar6 + 0x29) = 0;
    plVar6[0x79] = 0;
    local_18[0] = plVar6;
    uVar4 = GetInterfaceCompartmentId();
    *(undefined4 *)((longlong)plVar6 + 0x3dc) = uVar4;
    *(undefined4 *)((longlong)plVar6 + 0x67) = *(undefined4 *)(param_3 + 0x62);
    *(undefined2 *)((longlong)plVar6 + 0x6b) = *(undefined2 *)(param_3 + 0x66);
    KeInitializeSpinLock(plVar6 + 6);
    *(undefined4 *)(plVar6 + 0x23) = 0;
    *(undefined4 *)((longlong)plVar6 + 0x11c) = 0;
    *(undefined1 *)(plVar6 + 0x24) = 0;
    KeInitializeEvent(plVar6 + 0x25,0);
    cVar2 = L2IsClassifyNeededForInterface(0x39,plVar6[10],0);
    if (cVar2 != '\0') {
      *(uint *)((longlong)plVar6 + 0x11c) = *(uint *)((longlong)plVar6 + 0x11c) | 1;
    }
    cVar2 = L2IsClassifyNeededForInterface(0x38,plVar6[10],0);
    if (cVar2 != '\0') {
      *(uint *)((longlong)plVar6 + 0x11c) = *(uint *)((longlong)plVar6 + 0x11c) | 2;
    }
    *(undefined4 *)((longlong)plVar6 + 0x14c) = 2;
    local_res24 = 0;
    local_res20 = 0x8018d;
    uVar5 = NdisFSetAttributes(param_1,plVar6,&local_res20);
    uVar7 = (ulonglong)uVar5;
    if (uVar5 == 0) {
      L2InitializeNblReferenceRecords((longlong)plVar6);
      uVar3 = KeAcquireSpinLockRaiseToDpc(&DAT_14002ce90);
      if ((undefined8 *)*DAT_14002cea0 != &DAT_14002ce98) {
        pcVar1 = (code *)swi(0x29);
        (*pcVar1)(3);
        pcVar1 = (code *)swi(3);
        uVar7 = (*pcVar1)();
        return uVar7;
      }
      *plVar6 = (longlong)&DAT_14002ce98;
      plVar6[1] = (longlong)DAT_14002cea0;
      *DAT_14002cea0 = (longlong)plVar6;
      _DAT_14002cea8 = _DAT_14002cea8 + 1;
      DAT_14002cea0 = plVar6;
      KeReleaseSpinLock(&DAT_14002ce90,CONCAT71(0x14002ce,uVar3));
    }
    else {
      L2LwfFree((longlong *)local_18);
    }
  }
  return uVar7;
}



===== L2IsClassifyNeededForInterface @ 14000b204 =====

undefined1 L2IsClassifyNeededForInterface(ushort param_1,undefined8 param_2,uint param_3)

{
  undefined1 uVar1;
  int iVar2;
  short sVar3;
  bool bVar4;
  int local_res8 [2];
  undefined8 local_res10;
  undefined8 local_res20;
  ulonglong local_58 [2];
  undefined8 *local_48;
  ulonglong local_40;
  uint uStack_38;
  undefined4 uStack_34;
  ulonglong *local_30;
  undefined4 local_28;
  undefined2 local_24;
  
  uVar1 = 0;
  local_24 = 0;
  local_res20 = 0;
  sVar3 = 0;
  local_res8[0] = 0;
  bVar4 = false;
  if ((param_1 == 0x38) || (param_1 == 0x39)) {
    local_58[0]._0_4_ = 7;
  }
  else {
    local_58[0]._0_4_ = 2;
    if (param_1 == 0x3a) {
      sVar3 = 0x50;
    }
    else {
      sVar3 = 0x51;
    }
  }
  local_28 = 0xffffffff;
  local_48 = &local_res10;
  local_30 = local_58;
  local_58[1] = 4;
  local_58[0] = (ulonglong)(uint)local_58[0];
  _uStack_38 = CONCAT44(1,param_3 | 2);
  local_40 = (ulonglong)param_1;
  local_res10 = param_2;
  iVar2 = KfdEnumLayer(param_1,&local_40,&local_res20,local_res8);
  if (iVar2 < 0) {
    uVar1 = 1;
  }
  else {
    KfdFreeEnumHandle(local_res20);
    if (sVar3 != 0) {
      iVar2 = KfdIsLayerEmpty(sVar3);
      bVar4 = iVar2 == 0;
    }
    if ((local_res8[0] != 0) || (bVar4)) {
      uVar1 = 1;
    }
  }
  return uVar1;
}



===== L2InitializeNblReferenceRecords @ 14000b330 =====

void L2InitializeNblReferenceRecords(longlong param_1)

{
  undefined8 uVar1;
  
  if ((DAT_14002cf40 & 0x10) != 0) {
    uVar1 = ExAllocatePool2(0x40,0x28000,0x67326c57);
    *(undefined4 *)(param_1 + 0x3d0) = 0;
    *(undefined8 *)(param_1 + 0x3c8) = uVar1;
    *(undefined1 *)(param_1 + 0x3d4) = 0;
  }
  return;
}



===== L2LwfFree @ 14000b384 =====

void L2LwfFree(longlong *param_1)

{
  L2FreeNblReferenceRecords(*param_1);
  ExFreePoolWithTag(*param_1,0x6c326c57);
  *param_1 = 0;
  return;
}



===== L2FreeNblReferenceRecords @ 14000b3bc =====

void L2FreeNblReferenceRecords(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x3c8) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x3c8),0x67326c57);
    *(undefined8 *)(param_1 + 0x3c8) = 0;
    *(undefined4 *)(param_1 + 0x3d0) = 0;
    *(undefined1 *)(param_1 + 0x3d4) = 0;
  }
  return;
}



===== WfpRioBiSignalWorkItem @ 14000b410 =====

void WfpRioBiSignalWorkItem(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  int *piVar1;
  int iVar2;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x67,param_3,
             **(undefined4 **)(param_2 + 0x198));
  }
  iVar2 = BiSignalEvent();
  if (iVar2 < 0) {
    RtlAcquireWriteLock(*(longlong *)(param_2 + 0x10));
    *(undefined1 *)(param_2 + 0x72) = 0;
    KeReleaseInStackQueuedSpinLock(&local_28);
  }
  IoFreeWorkItem(param_3);
  LOCK();
  piVar1 = (int *)(param_2 + 0x160);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -2;
  UNLOCK();
  if (iVar2 == 3) {
    KeSetEvent(param_2 + 0x168,0,0);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x68,
              &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids);
    }
  }
  return;
}



===== BiSignalEvent @ 14000b544 =====

int BiSignalEvent(void)

{
  int iVar1;
  RPC_BINDING_HANDLE local_res18 [2];
  
  local_res18[0] = (RPC_BINDING_HANDLE)0x0;
  iVar1 = BipCreateRpcBinding((longlong *)local_res18);
  if (-1 < iVar1) {
    iVar1 = RBiCltSignalEvent(local_res18[0]);
    RpcBindingFree(local_res18);
  }
  return iVar1;
}



===== BipCreateRpcBinding @ 14000b5c8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int BipCreateRpcBinding(longlong *param_1)

{
  int iVar1;
  undefined1 auStack_e8 [32];
  RPC_BINDING_HANDLE local_c8;
  undefined4 local_c0;
  undefined8 local_bc;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined8 local_a8;
  undefined4 *local_a0;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined4 *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_e8;
  local_c8 = (RPC_BINDING_HANDLE)0x0;
  local_70 = 0x101;
  local_54 = 0;
  local_bc = 0;
  local_b4 = 0;
  local_a8 = 0;
  local_20 = 0;
  local_50 = 1;
  local_60 = 1;
  local_5c = 1;
  uStack_48 = 3;
  local_98 = 3;
  local_8c = 3;
  local_78 = &local_70;
  local_a0 = &local_98;
  local_94 = 1;
  local_90 = 1;
  local_c0 = 1;
  local_6c = 0x5000000;
  local_68 = 0x12;
  local_40 = 0;
  uStack_38 = 0;
  local_58 = 5;
  local_30 = 0;
  uStack_28 = 0;
  local_b0 = 6;
  local_88 = 0;
  uStack_80 = 0;
  local_ac = 0x14;
  iVar1 = RpcBindingCreateW(&local_50,&local_c0,&local_60,&local_c8);
  if ((iVar1 == 0) && (iVar1 = RpcBindingBind(0,local_c8,&DAT_140021000), iVar1 == 0)) {
    *param_1 = (longlong)local_c8;
    return 0;
  }
  if ((iVar1 < 0) && (local_c8 != (RPC_BINDING_HANDLE)0x0)) {
    RpcBindingFree(&local_c8);
  }
  return iVar1;
}



===== RBiCltSignalEvent @ 14000b710 =====

void RBiCltSignalEvent(undefined8 param_1)

{
  NdrClientCall3((MIDL_STUBLESS_PROXY_INFO *)&PTR_PTR_140021060,0,(void *)0x0);
  return;
}



===== LwfLowerAdvertiseL2ProfileSupport @ 14000b770 =====

int LwfLowerAdvertiseL2ProfileSupport(undefined8 *param_1)

{
  int iVar1;
  void *local_res8;
  
  while( true ) {
    if (param_1 == (undefined8 *)0x0) {
      return 0;
    }
    if (*(int *)(param_1 + 1) == 0x1021d) break;
    param_1 = (undefined8 *)*param_1;
  }
  if (*(uint *)((longlong)param_1 + 0xc) < 0x58) {
    return 0;
  }
  local_res8 = (void *)0x0;
  if (param_1[0xb] == 0) {
    return 0;
  }
  iVar1 = NdisAllocateMemoryWithTag(&local_res8,*(int *)(param_1 + 0xc) + 4,0x67326c57);
  if (iVar1 == 0) {
    memmove(local_res8,(void *)param_1[0xb],(ulonglong)*(uint *)(param_1 + 0xc));
    *(undefined4 *)((ulonglong)*(uint *)(param_1 + 0xc) + (longlong)local_res8) = 0x2021e;
    NdisFreeMemory(param_1[0xb],0,0);
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 4;
    param_1[0xb] = local_res8;
    return 0;
  }
  return iVar1;
}



===== DPWnfPdcCallback @ 14000b830 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DPWnfPdcCallback(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  int iVar1;
  longlong lVar2;
  undefined1 auStack_78 [32];
  undefined4 local_58 [2];
  undefined4 local_50 [2];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  longlong local_30;
  longlong lStack_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_78;
  local_58[0] = 0x18;
  local_30 = 0;
  lStack_28 = 0;
  local_20 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  local_50[0] = param_4;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6b,
            &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids);
  }
  iVar1 = ExQueryWnfStateData(param_1,local_50,&local_30,local_58);
  if (iVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6c,
               &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids,iVar1);
    }
    iVar1 = 0;
  }
  else {
    lVar2 = local_30 + -0x44fd8b8ecc99192b;
    if (lVar2 == 0) {
      lVar2 = lStack_28 + -0x294d1b1462efa9b0;
    }
    if (((lVar2 == 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       ((3 < (byte)WPP_GLOBAL_Control[0x29] && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6d,
              &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids);
    }
    KeAcquireInStackQueuedSpinLock(&DAT_14002c508,&local_48);
    do {
    } while (DAT_14002c510 != 0);
    KeReleaseInStackQueuedSpinLock(&local_48);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6e,
              &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids);
    }
  }
  return iVar1;
}



===== PplpGenericFreeFunction @ 14000ba00 =====

void PplpGenericFreeFunction(undefined8 param_1,longlong param_2)

{
  ExFreeToLookasideListEx(*(undefined8 *)(param_2 + 0x60),param_1);
  return;
}



===== L2IsInboundLayer @ 14000ba28 =====

ulonglong L2IsInboundLayer(int param_1)

{
  uint3 uVar1;
  uint uVar2;
  
  uVar2 = param_1 - 0x38;
  uVar1 = (uint3)(uVar2 >> 8);
  if (((ushort)uVar2 < 0x15) && ((0x120005U >> (uVar2 & 0x1f) & 1) != 0)) {
    return CONCAT71((uint7)uVar1,1);
  }
  return (ulonglong)CONCAT31(uVar1,(short)param_1 == 0x4d);
}



===== LwfUpperDetach @ 14000ba50 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void LwfUpperDetach(longlong *param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined1 uVar6;
  
  uVar6 = KeAcquireSpinLockRaiseToDpc(&DAT_14002ce90);
  lVar3 = *param_1;
  plVar4 = (longlong *)param_1[1];
  if ((*(longlong **)(lVar3 + 8) != param_1) || ((longlong *)*plVar4 != param_1)) {
    pcVar5 = (code *)swi(0x29);
    (*pcVar5)(3);
    pcVar5 = (code *)swi(3);
    (*pcVar5)();
    return;
  }
  *plVar4 = lVar3;
  *(longlong **)(lVar3 + 8) = plVar4;
  _DAT_14002cea8 = _DAT_14002cea8 + -1;
  KeReleaseSpinLock(&DAT_14002ce90,CONCAT71((int7)((ulonglong)plVar4 >> 8),uVar6));
  LOCK();
  piVar1 = (int *)((longlong)param_1 + 0x14c);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 2) {
    if (param_1[0x79] != 0) {
      ExFreePoolWithTag(param_1[0x79],0x67326c57);
      param_1[0x79] = 0;
      *(undefined4 *)(param_1 + 0x7a) = 0;
      *(undefined1 *)((longlong)param_1 + 0x3d4) = 0;
    }
    ExFreePoolWithTag(param_1,0x6c326c57);
  }
  return;
}



===== WfpRioAllocateRioState @ 14000bb18 =====

longlong WfpRioAllocateRioState(uint param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  uint uVar5;
  ulonglong uVar6;
  
  lVar2 = ExAllocatePool2(0x40,0x80,0x70646657);
  if (lVar2 != 0) {
    lVar3 = ExAllocatePool2(0x40,(ulonglong)param_1 << 3,0x70646657);
    *(longlong *)(lVar2 + 0x38) = lVar3;
    if (lVar3 != 0) {
      uVar6 = 0;
      while( true ) {
        if (param_1 <= (uint)uVar6) {
          return lVar2;
        }
        uVar4 = ExAllocatePool2(0x40,0x30,0x70646657);
        *(undefined8 *)(*(longlong *)(lVar2 + 0x38) + uVar6 * 8) = uVar4;
        if (*(longlong *)(*(longlong *)(lVar2 + 0x38) + uVar6 * 8) == 0) break;
        uVar6 = (ulonglong)((uint)uVar6 + 1);
      }
      if (*(longlong *)(lVar2 + 0x38) != 0) {
        uVar5 = 0;
        if (param_1 != 0) {
          lVar3 = 0;
          do {
            lVar1 = *(longlong *)(lVar3 + *(longlong *)(lVar2 + 0x38));
            if (lVar1 == 0) break;
            ExFreePoolWithTag(lVar1,0x70646657);
            uVar5 = uVar5 + 1;
            lVar3 = lVar3 + 8;
          } while (uVar5 < param_1);
        }
        ExFreePoolWithTag(*(undefined8 *)(lVar2 + 0x38),0x70646657);
      }
    }
    ExFreePoolWithTag(lVar2,0x70646657);
  }
  return 0;
}



===== L2vSwitchExtentionAdapterIdQuery @ 14000bc38 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int L2vSwitchExtentionAdapterIdQuery(void)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_2b8 [32];
  undefined4 local_298;
  undefined4 *local_290;
  longlong local_288;
  undefined4 local_280 [2];
  undefined8 local_278;
  undefined1 *puStack_270;
  undefined4 local_268;
  undefined4 local_264;
  undefined8 local_260;
  undefined *local_258;
  undefined4 local_250;
  undefined4 local_24c;
  undefined8 local_248;
  undefined8 uStack_240;
  undefined1 local_238 [12];
  undefined2 local_22c;
  undefined1 local_228 [528];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_2b8;
  local_288 = 0;
  iVar2 = 0;
  local_258 = &SYSTEM_ADAPTERS_INFO_KEY;
  local_264 = 0;
  local_24c = 0;
  local_260 = 0;
  local_268 = 0x30;
  local_248 = 0;
  uStack_240 = 0;
  local_250 = 0x240;
  iVar1 = ZwOpenKey(&local_288,0x20019,&local_268);
  if (-1 < iVar1) {
    while( true ) {
      local_290 = local_280;
      local_280[0] = 0;
      local_298 = 0x218;
      local_278 = 0;
      puStack_270 = (undefined1 *)0x0;
      iVar1 = ZwEnumerateKey(local_288,iVar2,0,local_238);
      if (iVar1 == -0x7fffffe6) break;
      if (iVar1 < 0) goto LAB_14000bd39;
      puStack_270 = local_228;
      local_278._0_4_ = CONCAT22(local_22c,local_22c);
      iVar1 = L2vSwitchpExtentionAdapterIdQuery(local_288,&local_278);
      if (iVar1 != -0x3ffffddb) goto LAB_14000bd39;
      iVar2 = iVar2 + 1;
    }
    iVar1 = 0;
  }
LAB_14000bd39:
  if (local_288 != 0) {
    ZwClose();
  }
  return iVar1;
}



===== L2vSwitchpExtentionAdapterIdQuery @ 14000bd7c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int L2vSwitchpExtentionAdapterIdQuery(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  int iVar2;
  ushort uVar3;
  ulonglong uVar4;
  undefined1 auStack_138 [32];
  undefined4 local_118;
  undefined4 *local_110;
  undefined4 local_108 [2];
  longlong local_100;
  longlong local_f8;
  longlong lStack_f0;
  ushort local_e8;
  ushort local_e6;
  undefined4 local_e4;
  longlong local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined1 local_a8 [4];
  int local_a4;
  undefined8 local_a0;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_138;
  local_100 = 0;
  local_108[0] = 0;
  local_d8 = 0x30;
  local_b8 = 0;
  uStack_b0 = 0;
  local_c0 = 0x240;
  local_d0 = param_1;
  local_c8 = param_2;
  iVar2 = ZwOpenKey(&local_100,0x20019,&local_d8);
  if (-1 < iVar2) {
    local_110 = local_108;
    local_118 = 0x90;
    iVar2 = ZwQueryValueKey(local_100,&VSWITCH_EXTN_ADAPTER_COMPONENT_ID_VALUE,2,local_a8);
    if ((-1 < iVar2) && (local_a4 == 1)) {
      lStack_f0 = (longlong)&local_a0 + 4;
      local_f8 = (local_a0 & 0xffff) << 0x10;
      uVar4 = local_a0;
      while( true ) {
        uVar3 = (ushort)uVar4;
        local_f8 = CONCAT62(local_f8._2_6_,uVar3);
        if ((uVar3 < 2) || (*(short *)(local_a8 + (uVar4 & 0xfffe) + 10) != 0)) break;
        uVar4 = (ulonglong)(ushort)(uVar3 - 2);
      }
      cVar1 = RtlEqualUnicodeString(&local_f8,&VSWITCH_EXTN_ADAPTER_COMPONENT_ID_DATA,1);
      if (cVar1 != '\0') {
        local_110 = local_108;
        local_118 = 0x90;
        iVar2 = ZwQueryValueKey(local_100,&VSWITCH_EXTN_ADAPTER_NETCFG_INSTANCE_ID_VALUE,2,local_a8)
        ;
        if (((-1 < iVar2) && (local_a4 == 1)) && (2 < (uint)local_a0)) {
          local_e0 = (longlong)&local_a0 + 4;
          local_e4 = 0;
          local_e8 = (ushort)(uint)local_a0;
          local_e6 = local_e8;
          L2TrimUnicodeString(&local_e8);
          iVar2 = RtlGUIDFromString(&local_e8,&gvSwitchExtentionAdapterGuid);
          goto LAB_14000bf1e;
        }
      }
    }
    iVar2 = -0x3ffffddb;
  }
LAB_14000bf1e:
  if (local_100 != 0) {
    ZwClose();
  }
  return iVar2;
}



===== WfpRioCleanupBuffer @ 14000bf60 =====

void WfpRioCleanupBuffer(undefined8 *param_1)

{
  MmUnlockPages(*param_1);
  IoFreeMdl(*param_1);
  *param_1 = 0;
  ExFreePoolWithTag(param_1,0x70646657);
  return;
}



===== WfpRioCleanupRioState @ 14000bfac =====

void WfpRioCleanupRioState(undefined8 *param_1)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  
  *param_1 = 0;
  if (param_1[7] != 0) {
    uVar3 = 0;
    if (*(int *)(param_1 + 6) != 0) {
      do {
        lVar1 = *(longlong *)(param_1[7] + uVar3 * 8);
        if (lVar1 == 0) break;
        ExFreePoolWithTag(lVar1,0x70646657);
        uVar2 = (int)uVar3 + 1;
        uVar3 = (ulonglong)uVar2;
      } while (uVar2 < *(uint *)(param_1 + 6));
    }
    ExFreePoolWithTag(param_1[7],0x70646657);
  }
  WfpRioCleanupQueueContextCq(param_1 + 3);
  WfpRioCleanupQueueContextCq(param_1 + 10);
  ExFreePoolWithTag(param_1,0x70646657);
  return;
}



===== LwfvSwitchOidRequestComplete @ 14000c040 =====

void LwfvSwitchOidRequestComplete(longlong param_1,longlong param_2,ulonglong param_3)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong lVar4;
  uint uVar5;
  undefined8 *puVar6;
  undefined1 uVar7;
  void *pvVar8;
  longlong lVar9;
  int iVar10;
  longlong lVar11;
  uint local_38 [2];
  longlong local_30;
  
  lVar9 = 0;
  uVar3 = param_3 & 0xffffffff;
  KeAcquireSpinLockRaiseToDpc(param_1 + 0x30);
  lVar2 = *(longlong *)(param_2 + 0xd8);
  *(undefined8 *)(param_2 + 0xd8) = 0;
  iVar10 = (int)param_3;
  if (lVar2 == 0) {
    lVar9 = *(longlong *)(param_2 + 0xe0);
    *(int *)(param_2 + 0xe0) = iVar10;
  }
  else {
    *(undefined8 *)(param_1 + 0x140) = 0;
  }
  KeReleaseSpinLock(param_1 + 0x30);
  iVar1 = *(int *)(param_2 + 4);
  if (iVar1 == 0) {
LAB_14000c3f6:
    if (lVar2 == 0) goto LAB_14000c315;
    *(undefined4 *)(lVar2 + 0x34) = *(undefined4 *)(param_2 + 0x34);
    *(undefined4 *)(lVar2 + 0x38) = *(undefined4 *)(param_2 + 0x38);
  }
  else if (iVar1 == 1) {
    if (lVar2 == 0) goto LAB_14000c315;
    *(undefined4 *)(lVar2 + 0x34) = *(undefined4 *)(param_2 + 0x34);
    *(undefined4 *)(lVar2 + 0x38) = *(undefined4 *)(param_2 + 0x38);
    if (iVar10 != 0) goto LAB_14000c21b;
    iVar10 = *(int *)(lVar2 + 0x20);
    if (iVar10 == 0x10278) {
      puVar6 = *(undefined8 **)(lVar2 + 0x28);
      pvVar8 = (void *)0x0;
LAB_14000c1bf:
      uVar3 = LwfvSwitchpFillPortDatabase(param_1,puVar6,pvVar8);
      uVar3 = uVar3 & 0xffffffff;
    }
    else {
      if (iVar10 == 0x1027a) {
        pvVar8 = *(void **)(lVar2 + 0x28);
        puVar6 = (undefined8 *)0x0;
        goto LAB_14000c1bf;
      }
      if (iVar10 == 0x10279) {
        lVar11 = *(longlong *)(lVar2 + 0x28);
        lVar4 = 0;
LAB_14000c213:
        LwfvSwitchpClearPortDatabase(param_1,lVar11,lVar4);
      }
      else if (iVar10 == 0x1027b) {
        LwfvSwitchpMarkInterfaceConnected(param_1,*(longlong *)(lVar2 + 0x28));
      }
      else if (iVar10 == 0x1027c) {
        LwfvSwitchpMarkInterfaceDisconnected(param_1,*(longlong *)(lVar2 + 0x28));
      }
      else if (iVar10 == 0x1027d) {
        lVar4 = *(longlong *)(lVar2 + 0x28);
        lVar11 = 0;
        goto LAB_14000c213;
      }
    }
LAB_14000c21b:
    if ((*(int *)(lVar2 + 0x20) == 0x10271) || (*(int *)(lVar2 + 0x20) == 0x10272)) {
      lVar11 = *(longlong *)(lVar2 + 0x28);
      lVar4 = L2GetvSwitchPortUnsafe(param_1,*(int *)(lVar11 + 8));
      local_38[1] = 0;
      local_30 = *(longlong *)(param_1 + 0x70) + 10;
      local_38[0] = (uint)*(ushort *)(*(longlong *)(param_1 + 0x70) + 8);
      iVar10 = (int)uVar3;
      if (*(int *)(lVar11 + 0xc) == 3) {
        lVar11 = (ulonglong)*(uint *)(lVar11 + 0x38) + lVar11;
        if (*(int *)(lVar11 + 8) == 1) {
          if (iVar10 == 0) {
            uVar5 = *(uint *)(lVar4 + 0x46c);
            if ((uVar5 != 0) && (uVar5 != *(ushort *)(lVar11 + 0x10))) {
              vSwitchFlpDerefCompartment(local_38,uVar5);
            }
            *(uint *)(lVar4 + 0x46c) = (uint)*(ushort *)(lVar11 + 0x10);
            *(undefined1 *)(lVar4 + 0x468) = 0;
            *(undefined1 *)(lVar4 + 0x490) = 0;
            *(undefined1 *)(lVar4 + 0x470) = 0;
          }
          else if ((*(ushort *)(lVar11 + 0x10) != 0) && (*(char *)(lVar4 + 0x490) != '\0')) {
            uVar5 = (uint)*(ushort *)(lVar11 + 0x10);
LAB_14000c3e0:
            vSwitchFlpDerefCompartment(local_38,uVar5);
            goto LAB_14000c3ea;
          }
        }
        else if (iVar10 == 0) {
          *(undefined1 *)(lVar4 + 0x468) = 1;
        }
      }
      else if (*(int *)(lVar11 + 0xc) == 2) {
        lVar11 = (ulonglong)*(uint *)(lVar11 + 0x38) + lVar11;
        if (iVar10 == 0) {
          iVar10 = *(int *)(lVar4 + 0x46c);
          uVar7 = 1;
          if (((iVar10 != 0) && (iVar10 != *(int *)(lVar11 + 0xc))) &&
             ((*(char *)(lVar4 + 0x470) == '\x01' ||
              ((*(char *)(lVar4 + 0x470) == '\0' && (*(int *)(lVar11 + 0xc) != 0)))))) {
            vSwitchFlpDerefCompartment(local_38,iVar10);
          }
          *(undefined4 *)(lVar4 + 0x46c) = *(undefined4 *)(lVar11 + 0xc);
          if (*(int *)(lVar11 + 0xc) == 0) {
            if (*(char *)(lVar4 + 0x470) == '\x01') {
              *(undefined4 *)(lVar4 + 0x46c) = 0;
            }
            uVar7 = 0;
          }
          else {
            *(int *)(lVar4 + 0x46c) = *(int *)(lVar11 + 0xc);
          }
          *(undefined1 *)(lVar4 + 0x470) = uVar7;
LAB_14000c3ea:
          *(undefined1 *)(lVar4 + 0x490) = 0;
        }
        else {
          uVar5 = *(uint *)(lVar11 + 0xc);
          if ((uVar5 != 0) && (*(char *)(lVar4 + 0x490) != '\0')) goto LAB_14000c3e0;
        }
      }
    }
  }
  else {
    if (iVar1 == 2) goto LAB_14000c3f6;
    if (iVar1 == 0xc) {
      if (lVar2 == 0) goto LAB_14000c315;
      *(undefined4 *)(lVar2 + 0x34) = *(undefined4 *)(param_2 + 0x34);
      *(undefined4 *)(lVar2 + 0x40) = *(undefined4 *)(param_2 + 0x40);
      *(undefined4 *)(lVar2 + 0x44) = *(undefined4 *)(param_2 + 0x44);
      *(undefined4 *)(lVar2 + 0x3c) = *(undefined4 *)(param_2 + 0x3c);
      if (*(int *)(param_2 + 0x20) == 0x10270) {
        lVar11 = *(longlong *)(*(longlong *)(param_2 + 0x28) + 0x18);
        if (*(int *)(lVar11 + 4) == 0xc) {
          if (*(int *)(lVar11 + 0x20) == 0x10245) {
            lVar9 = *(longlong *)(param_2 + 0xe0);
            *(int *)(param_2 + 0xe0) = iVar10;
            if (lVar9 != 0) {
              param_2 = 0;
            }
          }
        }
        else if (((*(int *)(lVar11 + 4) == 1) && (*(int *)(lVar11 + 0x20) == 0x10246)) &&
                (iVar10 == 0)) {
          LwfvSwitchpProcessVfFree(param_1,*(int *)(*(longlong *)(param_2 + 0x28) + 8));
        }
      }
    }
    else if (lVar2 == 0) goto LAB_14000c315;
  }
  if (param_2 != 0) {
    NdisFreeCloneOidRequest(*(undefined8 *)(param_1 + 0x48),param_2);
    NdisFOidRequestComplete(*(undefined8 *)(param_1 + 0x48),lVar2,uVar3);
  }
LAB_14000c315:
  if (lVar9 != 0) {
    KeSetEvent(lVar9,0,0);
  }
  return;
}



===== WfpRioDelayExecution @ 14000c418 =====

void WfpRioDelayExecution(void)

{
  undefined8 local_res8 [4];
  
  local_res8[0] = 0xfffffffffff0bdc0;
  KeDelayExecutionThread(0,0,local_res8);
  return;
}



===== WfpRioDPConfigCloseDispatchHandler @ 14000c448 =====

undefined8 WfpRioDPConfigCloseDispatchHandler(undefined8 param_1,longlong param_2)

{
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeAcquireInStackQueuedSpinLock(&DAT_14002c508,&local_28);
  do {
  } while (DAT_14002c510 != 0);
  if (DAT_14002c4c8 != 0) {
    if (*(longlong *)(DAT_14002c4c8 + 8) != 0) {
      ExFreePoolWithTag(*(longlong *)(DAT_14002c4c8 + 8),0x70646657);
    }
    ExFreePoolWithTag(DAT_14002c4c8,0x70646657);
    DAT_14002c4c8 = 0;
  }
  DAT_14002c4c1 = 0;
  KeReleaseInStackQueuedSpinLock(&local_28);
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== L2KfdProcessLayerEvent @ 14000c508 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint L2KfdProcessLayerEvent(int param_1,short param_2)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  code *pcVar4;
  bool bVar5;
  undefined1 uVar6;
  uint uVar7;
  longlong lVar8;
  undefined8 *puVar9;
  longlong lVar10;
  uint uVar11;
  undefined8 *puVar12;
  undefined8 ***pppuVar13;
  undefined1 *puVar14;
  ulonglong uVar15;
  ulonglong local_res18;
  undefined8 ***local_res20;
  undefined1 auStack_98 [8];
  undefined1 auStack_90 [56];
  undefined8 ***local_58;
  undefined8 ***local_50;
  undefined8 ***local_48;
  undefined8 ***pppuStack_40;
  
  uVar7 = 0;
  lVar8 = 0;
  lVar10 = 0;
  uVar15 = 0;
  bVar3 = (ushort)(param_2 - 0x38U) < 2;
  if ((DAT_14002cf44 == '\0') &&
     (((ushort)(param_2 - 0x3aU) < 2 || ((ushort)(param_2 - 0x50U) < 2)))) {
    bVar5 = true;
  }
  else {
    bVar5 = false;
  }
  local_res18 = local_res18 & 0xffffffffffffff00;
  local_50 = &local_58;
  local_58 = &local_58;
  local_res20 = (undefined8 ***)CONCAT71(local_res20._1_7_,(ushort)(param_2 - 0x48U) < 6);
  local_48 = (undefined8 ***)0x0;
  pppuStack_40 = (undefined8 ***)0x0;
  uVar6 = KeAcquireSpinLockRaiseToDpc(&DAT_14002ce90);
  uVar11 = DAT_14002cec0 + DAT_14002ced8 + _DAT_14002cea8;
  if ((uVar11 != 0) && (lVar8 = ExAllocatePool2(0x40,(ulonglong)uVar11 << 3,0x67326c57), lVar8 == 0)
     ) {
    uVar7 = 0xc0000017;
LAB_14000c5d6:
    puVar14 = auStack_98;
    KeReleaseSpinLock(&DAT_14002ce90,uVar6);
    goto LAB_14000c8c0;
  }
  if (bVar3) {
    puVar12 = DAT_14002ce98;
LAB_14000c612:
    do {
      puVar9 = &DAT_14002ce98;
      if (!bVar3) {
        puVar9 = &DAT_14002ceb0;
      }
      if (puVar12 == puVar9) goto LAB_14000c6ba;
      if (param_1 == 1) {
        if (bVar3) {
          uVar7 = LwfUpperKfdUpdateNotify((longlong)puVar12);
        }
        else {
          uVar7 = LwfLowerKfdUpdateNotify((longlong)puVar12);
        }
      }
      else if (bVar3) {
        uVar7 = LwfUpperKfdCommitNotify((longlong)puVar12);
      }
      else {
        uVar7 = LwfLowerKfdCommitNotify((longlong)puVar12);
      }
      if (uVar7 != 0) {
        if (uVar7 != 0x103) goto LAB_14000c5d6;
        *(undefined8 **)(lVar8 + uVar15 * 8) = puVar12 + 0x25;
        uVar15 = (ulonglong)((int)uVar15 + 1);
        RoReferenceEx((uint *)((longlong)puVar12 + 0x14c));
        pppuVar13 = (undefined8 ***)(puVar12 + 2);
        if ((undefined8 ****)*local_50 != &local_58) goto LAB_14000c768;
        puVar12[3] = local_50;
        *pppuVar13 = &local_58;
        *local_50 = pppuVar13;
        local_50 = pppuVar13;
      }
      puVar12 = (undefined8 *)*puVar12;
    } while( true );
  }
  if (bVar5) {
    puVar12 = DAT_14002ceb0;
    goto LAB_14000c612;
  }
LAB_14000c6ba:
  pppuStack_40 = &local_48;
  local_48 = &local_48;
  puVar14 = auStack_98;
  if ((char)local_res20 != '\0') {
    if ((DAT_14002ced8 == 0) || (DAT_14002ced8 < DAT_14002cf28)) {
      local_res18 = CONCAT71(local_res18._1_7_,1);
    }
    for (puVar12 = DAT_14002cec8; puVar14 = auStack_98, (undefined8 **)puVar12 != &DAT_14002cec8;
        puVar12 = (undefined8 *)*puVar12) {
      if (param_1 == 1) {
        uVar7 = LwfvSwitchKfdUpdateNotify((longlong)puVar12,(longlong *)&local_48);
      }
      else {
        uVar7 = LwfvSwitchKfdCommitNotify((longlong)puVar12);
      }
      if (uVar7 != 0) {
        if (uVar7 != 0x103) goto LAB_14000c5d6;
        *(undefined8 **)(lVar8 + uVar15 * 8) = puVar12 + 0x25;
        uVar15 = (ulonglong)((int)uVar15 + 1);
        RoReferenceEx((uint *)((longlong)puVar12 + 0x14c));
        pppuVar13 = (undefined8 ***)(puVar12 + 2);
        if ((undefined8 ****)*local_50 != &local_58) goto LAB_14000c768;
        puVar12[3] = local_50;
        *pppuVar13 = &local_58;
        *local_50 = pppuVar13;
        local_50 = pppuVar13;
      }
    }
  }
LAB_14000c773:
  *(undefined8 *)(puVar14 + -8) = 0x14000c784;
  KeReleaseSpinLock();
  if ((char)local_res18 != '\0') {
    *(undefined8 *)(puVar14 + -8) = 0x14000c798;
    uVar7 = L2FirevSwitchEvent(0,0);
  }
  uVar11 = uVar7;
  for (pppuVar13 = local_48; (undefined8 ****)pppuVar13 != &local_48;
      pppuVar13 = (undefined8 ***)*pppuVar13) {
    *(undefined8 *)(puVar14 + -8) = 0x14000c7b5;
    uVar7 = L2FirevSwitchEvent((longlong)(pppuVar13 + -4),1);
    if ((int)uVar7 < 0) goto LAB_14000c8c0;
    uVar11 = uVar7;
  }
  uVar7 = (uint)uVar15;
  if (uVar7 != 0) {
    local_res18 = 0xfffffffffe363c80;
    if (param_1 != 1) {
      local_res18 = 0xffffffffff676980;
    }
    if (0x40 < uVar7) {
      uVar7 = 0xc000009a;
      goto LAB_14000c8c0;
    }
    if (3 < uVar7) {
      *(undefined8 *)(puVar14 + -8) = 0x14000c814;
      lVar10 = ExAllocatePool2(0x40,uVar15 * 0x30,0x67326c57);
      if (lVar10 == 0) {
        uVar7 = 0xc0000017;
        goto LAB_14000c8c0;
      }
    }
    *(longlong *)(puVar14 + 0x38) = lVar10;
    *(ulonglong **)(puVar14 + 0x30) = &local_res18;
    puVar14[0x28] = 0;
    puVar14[0x20] = 0;
    *(undefined8 *)(puVar14 + -8) = 0x14000c858;
    uVar11 = KeWaitForMultipleObjects(uVar15,lVar8,0,6);
    for (pppuVar13 = local_58; (undefined8 ****)pppuVar13 != &local_58;
        pppuVar13 = (undefined8 ***)*pppuVar13) {
      local_res20 = pppuVar13 + -2;
      *(undefined8 *)(puVar14 + -8) = 0x14000c875;
      L2KfdUpdateNotifyComplete((longlong)local_res20);
      LOCK();
      piVar1 = (int *)((longlong)pppuVar13 + 0x13c);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -2;
      UNLOCK();
      if (iVar2 == 3) {
        *(undefined8 *)(puVar14 + -8) = 0x14000c890;
        L2LwfFree((longlong *)&local_res20);
      }
    }
  }
  uVar7 = 0;
  if (param_1 != 2) {
    uVar7 = uVar11;
  }
  if (lVar10 != 0) {
    *(undefined8 *)(puVar14 + -8) = 0x14000c8bb;
    ExFreePoolWithTag(lVar10,0x67326c57);
  }
LAB_14000c8c0:
  if (lVar8 != 0) {
    *(undefined8 *)(puVar14 + -8) = 0x14000c8d4;
    ExFreePoolWithTag(lVar8,0x67326c57);
  }
  return uVar7;
LAB_14000c768:
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  puVar14 = auStack_90;
  goto LAB_14000c773;
}



===== WfpL2DispatchCreate @ 14000c900 =====

int WfpL2DispatchCreate(longlong param_1,longlong param_2)

{
  int iVar1;
  
  if (param_1 == DAT_14002cf80) {
    iVar1 = WfpRioCreateRegistrationDomain(param_1,param_2);
  }
  else if (param_1 == DAT_14002cf88) {
    iVar1 = WfpRioDPConfigCreate(param_1,param_2);
  }
  else {
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
    IofCompleteRequest(param_2,0);
    iVar1 = -0x3ffffff3;
  }
  return iVar1;
}



===== WfpRioCreateRegistrationDomain @ 14000c958 =====

int WfpRioCreateRegistrationDomain(longlong param_1,longlong param_2)

{
  void *pvVar1;
  uint uVar2;
  bool bVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  undefined8 *puVar9;
  undefined8 uVar10;
  undefined8 **ppuVar11;
  undefined8 **ppuVar12;
  undefined *puVar13;
  undefined *puVar14;
  longlong *plVar15;
  longlong lVar16;
  undefined8 *local_res18;
  longlong local_res20;
  undefined *local_b8;
  undefined8 **local_b0;
  undefined8 local_a8;
  longlong lStack_a0;
  longlong local_98;
  undefined8 *local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  longlong local_78 [7];
  
  local_78[4] = 0;
  local_b8 = (undefined *)0x0;
  local_b0 = (undefined8 **)0x0;
  bVar3 = false;
  local_78[2] = 0;
  local_78[3] = 0;
  local_80 = 0;
  local_90 = (undefined8 *)0x0;
  uStack_88 = 0;
  local_78[0] = 0;
  local_78[1] = 0;
  local_a8 = 0;
  lStack_a0 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
            &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids);
  }
  local_98 = *(longlong *)(param_2 + 0xb8);
  if ((*(char *)(param_2 + 0x40) == '\x01') && (uVar2 = *(uint *)(local_98 + 0x20), 0x2f < uVar2)) {
    uVar7 = IoGetCurrentProcess();
    lVar16 = *(longlong *)(param_2 + 0x18);
    if (lVar16 != 0) {
      local_a8 = CONCAT62(CONCAT42(local_a8._4_4_,*(byte *)(lVar16 + 5) + 1),
                          (ushort)*(byte *)(lVar16 + 5));
      lStack_a0 = lVar16 + 8;
      RtlInitString(local_78,"WfpRioRDOpen");
      cVar4 = RtlEqualString(local_78,&local_a8,0);
      if (cVar4 != '\0') {
        plVar15 = (longlong *)((ulonglong)*(byte *)(lVar16 + 5) + 9 + lVar16);
        uVar5 = (int)plVar15[2] + 0x30;
        if ((0x2f < uVar5) && (uVar5 <= uVar2)) {
          uVar8 = WfpRioCheckAccessAndGetSids(uVar7,(longlong *)&local_b8,(longlong *)&local_b0);
          ppuVar12 = local_b0;
          puVar14 = local_b8;
          iVar6 = (int)uVar8;
          if (iVar6 < 0) {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
              WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
                      &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids);
            }
            ppuVar12 = local_b0;
            puVar14 = local_b8;
          }
          else if ((local_b8 == (undefined *)0x0) || (local_b0 == (undefined8 **)0x0)) {
            iVar6 = -0x3ffffff3;
          }
          else {
            local_res20 = PsChargeProcessWakeCounter(uVar7,0,4,DPDeviceObject);
            if (local_res20 == 0) {
              iVar6 = -0x3fffffff;
            }
            else {
              RtlAcquireWriteLock(0x14002c670);
              puVar13 = (undefined *)(ulonglong)*(uint *)(plVar15 + 2);
              pvVar1 = (void *)((longlong)plVar15 + 0x14);
              ppuVar11 = ppuVar12;
              puVar9 = WfpRioFindExistingRegDomainForPackage(puVar14,ppuVar12,puVar13,pvVar1);
              local_res18 = puVar9;
              if (puVar9 == (undefined8 *)0x0) {
LAB_14000cc3d:
                uVar8 = Feature_VPN_BugFixes_25A__private_IsEnabledDeviceUsageNoInline();
                if ((int)uVar8 != 0) {
                  if (puVar9 != (undefined8 *)0x0) goto LAB_14000cc29;
                  ppuVar11 = &local_res18;
                  puVar13 = puVar14;
                  uVar8 = WfpRioCreateAndInitializeRegDomain
                                    (param_1,(longlong *)ppuVar11,(longlong)puVar14,
                                     (longlong)ppuVar12,*(uint *)(plVar15 + 2),pvVar1,
                                     (undefined4 *)plVar15);
                  iVar6 = (int)uVar8;
                  if (-1 < iVar6) goto LAB_14000cded;
                  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                      (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
                     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
                    ppuVar11 = (undefined8 **)0x1c;
                    puVar13 = &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids;
                    WPP_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
                              &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids,
                              "WfpRioCreateRegistrationDomain",(char)uVar8);
                  }
LAB_14000ccbc:
                  puVar9 = local_res18;
                  goto LAB_14000ccc0;
                }
                if (puVar9 == (undefined8 *)0x0) {
                  ppuVar11 = &local_res18;
                  puVar13 = puVar14;
                  uVar8 = WfpRioCreateAndInitializeRegDomain
                                    (param_1,(longlong *)ppuVar11,(longlong)puVar14,
                                     (longlong)ppuVar12,*(uint *)(plVar15 + 2),pvVar1,
                                     (undefined4 *)plVar15);
                  iVar6 = (int)uVar8;
                  if (iVar6 < 0) goto LAB_14000ccbc;
LAB_14000cded:
                  ppuVar12 = (undefined8 **)0x0;
                  puVar14 = (undefined *)0x0;
                }
                else {
                  uVar10 = WfpRioInitializeRegDomainFieldsNewHandle((longlong)puVar9);
                  iVar6 = (int)uVar10;
                  if (iVar6 < 0) goto LAB_14000ccc0;
                  *(undefined4 *)((longlong)puVar9 + 0x4c) = 1;
                  *(undefined1 *)(puVar9 + 7) = 0;
                  *(undefined1 *)(puVar9 + 0x30) = 0;
                  *(undefined1 *)((longlong)puVar9 + 0x72) = 0;
                  *(undefined4 *)puVar9[0x27] = 0;
                  puVar9[0x18] = 0;
                  puVar9[0x19] = 0;
                  *(undefined4 *)(puVar9 + 0x1b) = 0;
                  puVar9[0x1d] = 0;
                  puVar9[0x1e] = 0;
                  *(undefined4 *)(puVar9 + 0x28) = 2;
                  KeClearEvent(puVar9 + 0x29);
                  puVar9[0x1a] = 0;
                  *(int *)(local_res18 + 9) = *(int *)(puVar9 + 9) + 1;
                  *(undefined1 *)(local_res18 + 0xe) = 1;
                  ppuVar12 = local_b0;
                  puVar14 = local_b8;
                }
                lVar16 = local_res20;
                puVar9 = local_res18;
                local_res18[0x35] = uVar7;
                local_res18[0x39] = local_res20;
                ObfReferenceObject(local_res18[0x35]);
              }
              else {
                ppuVar11 = &local_90;
                RtlAcquireWriteLock(puVar9[2]);
                bVar3 = true;
                uVar8 = Feature_VPN_BugFixes_25A__private_IsEnabledDeviceUsageNoInline();
                if ((int)uVar8 == 0) {
                  if (*(int *)((longlong)puVar9 + 0x4c) == 4) {
                    KeReleaseInStackQueuedSpinLock(&local_90);
                    puVar9 = (undefined8 *)0x0;
                    bVar3 = false;
                    local_res18 = (undefined8 *)0x0;
                  }
                }
                else if ((*(int *)((longlong)puVar9 + 0x4c) == 3) ||
                        (MicrosoftTelemetryAssertTriggeredNoArgsKM(),
                        *(int *)((longlong)puVar9 + 0x4c) == 3)) {
                  KeReleaseInStackQueuedSpinLock(&local_90);
                  bVar3 = false;
                  WfpRioDecrementReferenceCount((longlong)puVar9,ppuVar11,puVar13);
                  puVar9 = (undefined8 *)0x0;
                  local_res18 = (undefined8 *)0x0;
                  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                     (((byte)WPP_GLOBAL_Control[0x29] < 4 ||
                      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)))) goto LAB_14000cc3d;
                  ppuVar11 = (undefined8 **)0x1b;
                  WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,puVar13,
                           "WfpRioCreateRegistrationDomain");
                }
                if ((puVar9 == (undefined8 *)0x0) ||
                   ((((*(longlong *)puVar9[0x31] == *plVar15 &&
                      (((longlong *)puVar9[0x31])[1] == plVar15[1])) &&
                     (*(int *)((longlong)puVar9 + 0x4c) != 1)) && (puVar9[0x39] == 0))))
                goto LAB_14000cc3d;
LAB_14000cc29:
                iVar6 = -0x3ffffff3;
LAB_14000ccc0:
                lVar16 = local_res20;
              }
              if (bVar3) {
                KeReleaseInStackQueuedSpinLock(&local_90);
                uVar8 = Feature_VPN_BugFixes_25A__private_IsEnabledDeviceUsageNoInline();
                if ((int)uVar8 != 0) {
                  WfpRioDecrementReferenceCount((longlong)puVar9,ppuVar11,puVar13);
                }
              }
              KeReleaseInStackQueuedSpinLock(local_78 + 2);
              if (iVar6 < 0) {
                PsReleaseProcessWakeCounter(lVar16,DPDeviceObject);
              }
              else {
                *(undefined8 **)(*(longlong *)(local_98 + 0x30) + 0x18) = puVar9;
              }
            }
          }
          if (puVar14 != (undefined *)0x0) {
            ExFreePoolWithTag(puVar14,0x70646657);
          }
          if (ppuVar12 != (undefined8 **)0x0) {
            ExFreePoolWithTag(ppuVar12,0x70646657);
          }
          goto LAB_14000ce6a;
        }
      }
    }
  }
  iVar6 = -0x3ffffff3;
LAB_14000ce6a:
  *(int *)(param_2 + 0x30) = iVar6;
  IofCompleteRequest(param_2,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
             &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids,iVar6);
  }
  return iVar6;
}



===== L2BfeStateChangeCallback @ 14000cee0 =====

void L2BfeStateChangeCallback(undefined8 param_1,int param_2)

{
  undefined1 uVar1;
  
  if (param_2 == 3) {
    FwpmEngineOpen0(0,0xffffffff,0,0,&DAT_14002cf10);
  }
  else if ((param_2 == 2) && (DAT_14002cf10 != 0)) {
    uVar1 = KeAcquireSpinLockRaiseToDpc(&DAT_14002ce90);
    KeReleaseSpinLock(&DAT_14002ce90,uVar1);
    while (DAT_14002cf18 != '\0') {
      L2DelayExecution(200);
    }
    FwpmEngineClose0(DAT_14002cf10);
    DAT_14002cf10 = 0;
  }
  uVar1 = KeAcquireSpinLockRaiseToDpc(&DAT_14002ce90);
  DAT_14002cf08 = param_2;
  KeReleaseSpinLock(&DAT_14002ce90,uVar1);
  return;
}



===== LwfvSwitchOidRequest @ 14000cfc0 =====

ulonglong LwfvSwitchOidRequest(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined1 uVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong local_res8;
  
  local_res8 = 0;
  lVar4 = param_1 + 0x30;
  uVar2 = KeAcquireSpinLockRaiseToDpc(lVar4);
  if ((*(int *)(param_1 + 0x3c) == 0) &&
     (uVar3 = LwfvSwitchIsOidAuthenticated(param_2), (char)uVar3 != '\0')) {
    KeReleaseSpinLock(lVar4,uVar2);
    KeWaitForSingleObject(param_1 + 0x100,0,0,0,0);
  }
  else {
    KeReleaseSpinLock(lVar4,uVar2);
  }
  uVar3 = NdisAllocateCloneOidRequest
                    (*(undefined8 *)(param_1 + 0x48),param_2,0x67326c57,&local_res8);
  if ((int)uVar3 == 0) {
    *(longlong *)(local_res8 + 0xd8) = param_2;
    *(undefined8 *)(local_res8 + 0x10) = *(undefined8 *)(param_2 + 0x10);
    *(longlong *)(param_1 + 0x140) = local_res8;
    lVar4 = local_res8;
    uVar3 = LwfvSwitchIsOidAuthenticated(param_2);
    if ((char)uVar3 == '\0') {
      uVar3 = NdisFOidRequest(*(undefined8 *)(param_1 + 0x48),lVar4);
      if ((int)uVar3 == 0x103) {
        return uVar3;
      }
      LwfvSwitchOidRequestComplete(param_1,local_res8,uVar3 & 0xffffffff);
    }
    else {
      IoQueueWorkItem(*(undefined8 *)(param_1 + 0x3c0),LwfvSwitchpOidRequestWorkRoutine,1,param_1);
    }
    uVar3 = 0x103;
  }
  else {
    iVar1 = *(int *)(param_2 + 4);
    if ((((iVar1 == 0) || (iVar1 == 1)) || (iVar1 == 2)) || (iVar1 != 0xc)) {
      *(undefined4 *)(param_2 + 0x34) = 0;
      *(undefined4 *)(param_2 + 0x38) = 0;
    }
    else {
      *(undefined4 *)(param_2 + 0x40) = 0;
      *(undefined4 *)(param_2 + 0x44) = 0;
      *(undefined4 *)(param_2 + 0x3c) = 0;
    }
  }
  return uVar3;
}



===== LwfUpperReturnNetBufferLists @ 14000d140 =====

void LwfUpperReturnNetBufferLists(longlong param_1,longlong ***param_2,undefined4 param_3)

{
  longlong ****pppplVar1;
  longlong *****ppppplVar2;
  longlong ***ppplVar3;
  ulonglong uVar4;
  longlong *****ppppplVar5;
  int iVar6;
  longlong *****ppppplVar7;
  longlong *****local_res10;
  
  iVar6 = 0;
  for (ppplVar3 = param_2; ppplVar3 != (longlong ***)0x0; ppplVar3 = (longlong ***)*ppplVar3) {
    iVar6 = iVar6 + 1;
  }
  local_res10 = (longlong *****)param_2;
  ppplVar3 = (longlong ***)WfpGetPacketTagCount();
  ppppplVar5 = local_res10;
  while (local_res10 = ppppplVar5, ppplVar3 != (longlong ***)0x0) {
    FwppNetBufferListEventNotify(param_2,0,7);
    param_2 = (longlong ***)*param_2;
    ppppplVar5 = local_res10;
    ppplVar3 = param_2;
  }
  if (*(int *)(param_1 + 0x148) != 0) {
    ppppplVar7 = (longlong *****)&local_res10;
    pppplVar1 = *(longlong *****)(param_1 + 0x48);
    if (ppppplVar5 == (longlong *****)0x0) goto LAB_14000d239;
    do {
      ppppplVar2 = (longlong *****)*ppppplVar5;
      if (((ppppplVar5[0xf] == pppplVar1) &&
          (uVar4 = WfpNblInfoGetFlags(ppppplVar5), (uVar4 & 2) != 0)) &&
         (*(int *)(*(longlong *)
                    ((ulonglong)*(ushort *)((longlong)ppppplVar5[2] + 10) + 0x18 +
                    (longlong)ppppplVar5[2]) + 0x38) == 1)) {
        L2CompleteInjectedNetBufferLists(ppppplVar5);
        *ppppplVar7 = (longlong ****)ppppplVar2;
      }
      else {
        ppppplVar7 = ppppplVar5;
      }
      ppppplVar5 = ppppplVar2;
    } while (ppppplVar2 != (longlong *****)0x0);
  }
  if (local_res10 != (longlong *****)0x0) {
    NdisFReturnNetBufferLists(*(undefined8 *)(param_1 + 0x48),local_res10,param_3);
  }
LAB_14000d239:
  L2UpdateCompletedNblCounts(param_1,iVar6);
  return;
}



===== L2vSwitchpIsWinPE @ 14000d260 =====

bool L2vSwitchpIsWinPE(void)

{
  int iVar1;
  undefined8 local_res8 [4];
  undefined8 local_38;
  undefined8 local_30;
  undefined *local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_38 = 0x30;
  local_30 = 0;
  local_28 = &WINPE_KEY;
  local_20 = 0x240;
  local_res8[0] = 0;
  local_18 = 0;
  uStack_10 = 0;
  iVar1 = ZwOpenKey(local_res8,0x20019,&local_38);
  if (-1 < iVar1) {
    ZwClose(local_res8[0]);
  }
  return -1 < iVar1;
}



===== L2InitializeFlowsManager @ 14000d2d8 =====

undefined8 L2InitializeFlowsManager(longlong param_1)

{
  char cVar1;
  int iVar2;
  uint *puVar3;
  undefined8 uVar4;
  longlong local_res8;
  
  uVar4 = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  local_res8 = param_1 + 0x10;
  cVar1 = RtlCreateHashTable(&local_res8,0,0);
  if (cVar1 == '\0') {
    uVar4 = 0xc0000017;
  }
  else {
    *(undefined4 *)(param_1 + 0x58) = 0;
    *(undefined8 *)(param_1 + 0x50) = 0;
    iVar2 = KeQueryMaximumProcessorCountEx(0xffff);
    puVar3 = PplpCreateLookasideListEx(iVar2);
    *(uint **)(param_1 + 0x760) = puVar3;
    if (puVar3 == (uint *)0x0) {
      uVar4 = 0xc0000017;
      RtlDeleteHashTable(param_1 + 0x10);
    }
    else {
      KeInitializeSpinLock(param_1);
      *(undefined4 *)(param_1 + 8) = 0;
      KeInitializeSpinLock(param_1 + 0x40);
      *(undefined4 *)(param_1 + 0x48) = 0;
      KeInitializeTimerEx(param_1 + 0x60,0);
      KeInitializeDpc(param_1 + 0xa0,L2FlowsManagerTimerCallback,param_1);
      KeInitializeSpinLock(param_1 + 0x120);
      RtlInitializeTimerWheel(param_1 + 0x128,0x40,1,1,0);
      KeInitializeDpc(param_1 + 0xe0,L2FlowsManagerTimerCallback,param_1);
      *(undefined8 *)(param_1 + 0x768) = 0;
      *(undefined4 *)(param_1 + 0x770) = 0;
      *(undefined1 *)(param_1 + 0x774) = 0;
      KeInitializeEvent(param_1 + 0x778,0,0);
    }
  }
  return uVar4;
}



===== L2TrimUnicodeString @ 14000d44c =====

void L2TrimUnicodeString(ushort *param_1)

{
  ushort uVar1;
  
  uVar1 = *param_1;
  if (1 < uVar1) {
    do {
      if (*(short *)(*(longlong *)(param_1 + 4) + -2 + (ulonglong)(uVar1 >> 1) * 2) != 0) {
        return;
      }
      uVar1 = uVar1 - 2;
      *param_1 = uVar1;
    } while (1 < uVar1);
  }
  return;
}



===== WfpL2DispatchCleanup @ 14000d480 =====

undefined8 WfpL2DispatchCleanup(longlong param_1,longlong param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  if (param_1 == DAT_14002cf80) {
    uVar1 = WfpRioCleanup(param_1,param_2,param_3);
  }
  else {
    uVar1 = 0;
    if (param_1 == DAT_14002cf88) {
      *(undefined4 *)(param_2 + 0x30) = 0;
    }
    else {
      *(undefined8 *)(param_2 + 0x38) = 0;
      *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
      uVar1 = 0xc000000d;
    }
    IofCompleteRequest(param_2,0);
  }
  return uVar1;
}



===== WfpRioCleanup @ 14000d4d8 =====

undefined8 WfpRioCleanup(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  char cVar5;
  ulonglong uVar6;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  lVar4 = *(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x18);
  RtlAcquireWriteLock(*(longlong *)(lVar4 + 0x10));
  uVar3 = *(uint *)(lVar4 + 0xb8);
  *(undefined1 *)(lVar4 + 0x180) = 1;
  *(uint *)(lVar4 + 0xb8) = uVar3 & 0xfffffff8;
  if ((uVar3 & 8) != 0) {
    cVar5 = KeCancelTimer(lVar4 + 0x78);
    if (cVar5 != '\0') {
      LOCK();
      *(int *)(lVar4 + 0x140) = *(int *)(lVar4 + 0x140) + -2;
      UNLOCK();
      *(uint *)(lVar4 + 0xb8) = *(uint *)(lVar4 + 0xb8) & 0xfffffff7;
    }
  }
  uVar6 = Feature_VPN_BugFixes_25A__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar6 == 0) {
    KeReleaseInStackQueuedSpinLock(&local_28);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x69,param_3,
               *(undefined4 *)(lVar4 + 0x164));
    }
    while( true ) {
      LOCK();
      piVar1 = (int *)(lVar4 + 0x164);
      iVar2 = *piVar1;
      *piVar1 = *piVar1;
      UNLOCK();
      if (iVar2 == 0) break;
      WfpRioDelayExecution();
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6a,
              &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids);
    }
    RtlAcquireWriteLock(*(longlong *)(lVar4 + 0x10));
  }
  if (*(longlong *)(lVar4 + 0x40) != 0) {
    WfpRioFlushRq(lVar4,0xc0000120);
  }
  KeReleaseInStackQueuedSpinLock(&local_28);
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== vSwitchFlStartup @ 14000d650 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int vSwitchFlStartup(undefined8 param_1,undefined8 *param_2)

{
  int iVar1;
  undefined8 *puVar2;
  
  DAT_14002c560 = &DAT_14002c558;
  DAT_14002c558 = &DAT_14002c558;
  KeInitializeSpinLock(&DAT_14002c548);
  puVar2 = (undefined8 *)0x0;
  _DAT_14002c2d0 = &DAT_14002c2c8;
  _DAT_14002c2c8 = &DAT_14002c2c8;
  DAT_14002c550 = 0;
  KeInitializeSpinLock(&DAT_14002c2c0);
  _DAT_14002c1d0 = &DAT_14002c1c8;
  _DAT_14002c1c8 = &DAT_14002c1c8;
  KeInitializeSpinLock(&DAT_14002c1c0);
  iVar1 = vSwitchFlpRegisterNdisIfProvider();
  if (-1 < iVar1) {
    iVar1 = NmrRegisterProvider(&DAT_14002c1e8,&DAT_14002c1e8,&DAT_14002c2b8);
    if (-1 < iVar1) {
      vSwitchFl4ProviderState = 1;
      iVar1 = NmrRegisterProvider(&DAT_14002c0e8,&DAT_14002c0e8,&DAT_14002c1b8);
      if (-1 < iVar1) {
        vSwitchFl6ProviderState = 1;
        puVar2 = &vSwitchFlGlobalState;
        goto LAB_14000d74f;
      }
    }
  }
  vSwitchFlCleanup();
LAB_14000d74f:
  *param_2 = puVar2;
  return iVar1;
}



===== PplpLazyInitializeLookasideList @ 14000d76c =====

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



===== WfpRioMatchRegDomain @ 14000d818 =====

ulonglong WfpRioMatchRegDomain
                    (longlong param_1,undefined8 param_2,undefined8 param_3,int param_4,
                    undefined8 param_5)

{
  char cVar1;
  undefined **ppuVar2;
  ulonglong uVar3;
  undefined2 uVar4;
  
  cVar1 = RtlEqualSid(param_2,*(undefined8 *)(param_1 + 0x50));
  if (cVar1 == '\0') {
    ppuVar2 = &WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((byte)WPP_GLOBAL_Control[0x29] < 4)) ||
       (ppuVar2 = (undefined **)(ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
       (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_14000d94d;
    uVar4 = 0xe;
  }
  else {
    cVar1 = RtlEqualSid(param_3,*(undefined8 *)(param_1 + 0x58));
    if (cVar1 == '\0') {
      ppuVar2 = &WPP_GLOBAL_Control;
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((byte)WPP_GLOBAL_Control[0x29] < 4)) ||
         (ppuVar2 = (undefined **)(ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
         (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_14000d94d;
      uVar4 = 0xf;
    }
    else if (param_4 == *(int *)(param_1 + 0x60)) {
      uVar3 = RtlCompareMemory(param_5,*(undefined8 *)(param_1 + 0x68),*(int *)(param_1 + 0x60));
      if (uVar3 == *(uint *)(param_1 + 0x60)) {
        ppuVar2 = &WPP_GLOBAL_Control;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          ppuVar2 = (undefined **)
                    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                            &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids);
        }
        return CONCAT71((int7)((ulonglong)ppuVar2 >> 8),1);
      }
      ppuVar2 = &WPP_GLOBAL_Control;
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((byte)WPP_GLOBAL_Control[0x29] < 4)) ||
         (ppuVar2 = (undefined **)(ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
         (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_14000d94d;
      uVar4 = 0x11;
    }
    else {
      ppuVar2 = &WPP_GLOBAL_Control;
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((byte)WPP_GLOBAL_Control[0x29] < 4)) ||
         (ppuVar2 = (undefined **)(ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
         (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_14000d94d;
      uVar4 = 0x10;
    }
  }
  ppuVar2 = (undefined **)
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
                    &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids);
LAB_14000d94d:
  return (ulonglong)ppuVar2 & 0xffffffffffffff00;
}



===== WfpRioInsertCompletionQueue @ 14000d9a0 =====

ulonglong WfpRioInsertCompletionQueue(longlong param_1,longlong param_2)

{
  uint uVar1;
  longlong *plVar2;
  uint *puVar3;
  longlong lVar4;
  ulonglong in_RAX;
  uint uVar5;
  bool bVar6;
  
  if (*(char *)(param_1 + 0x38) == '\0') {
    plVar2 = (longlong *)(param_1 + 0x20);
    puVar3 = (uint *)(param_1 + 0x30);
    uVar5 = *(uint *)(param_1 + 0x34);
    do {
      if (*(longlong *)(*plVar2 + (ulonglong)uVar5 * 8) == 0) goto LAB_14000da04;
      uVar1 = uVar5 + 1;
      bVar6 = uVar5 != *puVar3 - 1;
      uVar5 = 0;
      if (bVar6) {
        uVar5 = uVar1;
      }
    } while (uVar5 != *(uint *)(param_1 + 0x34));
    uVar5 = *puVar3;
    in_RAX = WfpRioGrowTable(plVar2,puVar3);
    if (-1 < (int)in_RAX) {
LAB_14000da04:
      lVar4 = *plVar2;
      *(uint *)(param_1 + 0x34) = uVar5;
      *(longlong *)(lVar4 + (ulonglong)uVar5 * 8) = param_2;
      *(uint *)(param_2 + 0x28) = uVar5;
      return CONCAT71((int7)((ulonglong)lVar4 >> 8),1);
    }
  }
  return in_RAX & 0xffffffffffffff00;
}



===== WfpInitializeDPConfigDevice @ 14000da38 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int WfpInitializeDPConfigDevice(undefined8 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  longlong lVar4;
  undefined4 *puVar5;
  longlong lVar6;
  longlong lVar7;
  undefined1 auStack_e8 [32];
  undefined4 local_c8;
  undefined1 local_c0;
  longlong *local_b8;
  longlong local_a8 [8];
  undefined4 local_68;
  undefined2 local_64;
  wchar_t local_60 [24];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_e8;
  local_a8[0] = 0;
  local_68 = 0;
  builtin_wcsncpy(local_60,L"\\Device\\WFPL2DPC",0x10);
  lVar6 = 0;
  builtin_wcsncpy(local_60 + 0x10,L"onfig",6);
  lVar4 = 0;
  local_64 = 0x500;
  local_a8[3] = 0;
  local_a8[4] = 0;
  lVar7 = 0;
  local_a8[7] = 0;
  local_a8[5] = 0;
  local_a8[6] = 0;
  local_a8[1] = 0;
  local_a8[2] = 0;
  RtlInitUnicodeString(local_a8 + 1,local_60);
  local_b8 = local_a8;
  local_c0 = 0;
  local_c8 = 0x100;
  iVar1 = IoCreateDevice(param_1,0,local_a8 + 1,0x12);
  if (-1 < iVar1) {
    uVar2 = RtlLengthRequiredSid(6);
    lVar4 = ExAllocatePool2(0x40,uVar2,0x67326c57);
    if (lVar4 == 0) {
LAB_14000db38:
      iVar1 = -0x3fffffe9;
    }
    else {
      iVar1 = RtlInitializeSid(lVar4,&local_68,6);
      if (-1 < iVar1) {
        puVar5 = (undefined4 *)RtlSubAuthoritySid(lVar4,0);
        *puVar5 = 0x50;
        puVar5 = (undefined4 *)RtlSubAuthoritySid(lVar4,1);
        *puVar5 = 0xf8ee4d1a;
        puVar5 = (undefined4 *)RtlSubAuthoritySid(lVar4,2);
        *puVar5 = 0x1231c877;
        puVar5 = (undefined4 *)RtlSubAuthoritySid(lVar4,3);
        *puVar5 = 0x8682c501;
        puVar5 = (undefined4 *)RtlSubAuthoritySid(lVar4,4);
        *puVar5 = 0xa1c73fcb;
        puVar5 = (undefined4 *)RtlSubAuthoritySid(lVar4,5);
        *puVar5 = 0xd3bf5936;
        uVar2 = RtlLengthRequiredSid(2);
        lVar6 = ExAllocatePool2(0x40,uVar2,0x67326c57);
        if (lVar6 == 0) goto LAB_14000db38;
        iVar1 = RtlInitializeSid(lVar6,&local_68,2);
        if (-1 < iVar1) {
          puVar5 = (undefined4 *)RtlSubAuthoritySid(lVar6,0);
          *puVar5 = 0x20;
          puVar5 = (undefined4 *)RtlSubAuthoritySid(lVar6,1);
          *puVar5 = 0x220;
          iVar1 = RtlLengthSid(lVar4);
          iVar3 = RtlLengthSid(lVar6);
          iVar1 = iVar1 + iVar3 + 0x18;
          lVar7 = ExAllocatePool2(0x40,iVar1,0x67326c57);
          if (lVar7 == 0) goto LAB_14000db38;
          iVar1 = RtlCreateAcl(lVar7,iVar1,2);
          if (-1 < iVar1) {
            iVar1 = RtlAddAccessAllowedAce(lVar7,2,0x10000000,lVar4);
            if (-1 < iVar1) {
              iVar1 = RtlAddAccessAllowedAce(lVar7,2,0x10000000,lVar6);
              if (-1 < iVar1) {
                iVar1 = RtlCreateSecurityDescriptor(local_a8 + 3,1);
                if (-1 < iVar1) {
                  iVar1 = RtlSetDaclSecurityDescriptor(local_a8 + 3,1,lVar7,0);
                  if (-1 < iVar1) {
                    iVar1 = ObSetSecurityObjectByPointer(local_a8[0],4,local_a8 + 3);
                    if (-1 < iVar1) {
                      DAT_14002cf88 = local_a8[0];
                      goto LAB_14000db52;
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
  if (local_a8[0] != 0) {
    IoDeleteDevice();
  }
LAB_14000db52:
  ExFreePoolWithTag(lVar4,0x67326c57);
  ExFreePoolWithTag(lVar6,0x67326c57);
  ExFreePoolWithTag(lVar7,0x67326c57);
  return iVar1;
}



===== L2QueueRestartCompleteWorkItem @ 14000de14 =====

ulonglong L2QueueRestartCompleteWorkItem(longlong param_1,undefined4 param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  
  *(undefined4 *)(param_1 + 0x3d8) = param_2;
  uVar2 = 0;
  uVar4 = DAT_14002ce88;
  lVar1 = IoAllocateWorkItem();
  if (lVar1 == 0) {
    uVar2 = WfpReportSysErrorAsNtStatus(uVar4,"IoAllocateWorkItem",-0x3fffffe9);
  }
  else {
    uVar3 = RoReferenceEx((uint *)(param_1 + 0x14c));
    if ((char)uVar3 == '\0') {
      IoFreeWorkItem(lVar1);
      *(undefined4 *)(param_1 + 0x3d8) = 0;
    }
    else {
      IoQueueWorkItemEx(lVar1,L2RestartCompleteWorkRoutine,1,param_1);
    }
  }
  return uVar2 & 0xffffffff;
}



===== WfpRioGetTokenInformation @ 14000deb4 =====

undefined8 WfpRioGetTokenInformation(undefined8 param_1,ulonglong param_2,longlong *param_3)

{
  undefined8 uVar1;
  longlong lVar2;
  undefined4 local_res18 [2];
  
  local_res18[0] = 0;
  *param_3 = 0;
  uVar1 = ZwQueryInformationToken(param_1,param_2,0,0,local_res18);
  if ((int)uVar1 == -0x3fffffdd) {
    lVar2 = ExAllocatePool2(0x40,local_res18[0],0x70646657);
    if (lVar2 == 0) {
      uVar1 = 0xc000009a;
    }
    else {
      uVar1 = ZwQueryInformationToken(param_1,param_2 & 0xffffffff,lVar2,local_res18[0],local_res18)
      ;
      if (-1 < (int)uVar1) {
        *param_3 = lVar2;
      }
    }
  }
  return uVar1;
}



===== WfpRioInitialize @ 14000df6c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int WfpRioInitialize(undefined8 param_1)

{
  int iVar1;
  undefined1 auStack_68 [32];
  code *local_48;
  undefined8 local_40;
  char local_38 [8];
  undefined8 local_30;
  undefined8 uStack_28;
  undefined4 local_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  local_18 = 0x41c6013da3bc0875;
  local_38[0] = '\0';
  local_20 = 0;
  local_30 = 0;
  uStack_28 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids);
  }
  WfpRioNdisObject = NdisAllocateGenericObject(0,0x70646657,0);
  if (WfpRioNdisObject != 0) {
    local_30 = CONCAT26(local_30._6_2_,0x10000140180);
    uStack_28 = CONCAT44(uStack_28._4_4_,0x70646657);
    WfpRioNetBufferListPool = NdisAllocateNetBufferListPool(WfpRioNdisObject,&local_30);
    if (WfpRioNetBufferListPool != 0) {
      _DAT_14002c688 = &RegDomainList;
      RegDomainList = &RegDomainList;
      KeInitializeSpinLock(&RegDomainListRWLock);
      _DAT_14002c678 = 0;
      KeInitializeSpinLock(&DAT_14002c508);
      DAT_14002c510 = 0;
      local_48 = (code *)CONCAT44(local_48._4_4_,1);
      DPDeviceObject = param_1;
      iVar1 = ZwPowerInformation(0x42,0,0,local_38);
      if (-1 < iVar1) {
        DAT_14002c4c0 = local_38[0];
      }
      if (DAT_14002c4c0 != '\0') {
        local_40 = 0;
        local_48 = DPWnfPdcCallback;
        iVar1 = ExSubscribeWnfStateChange(&DAT_14002c4b8,&local_18,1);
        if (-1 < iVar1) {
          return iVar1;
        }
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                   &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids,iVar1);
        }
        return 0;
      }
      if (-1 < iVar1) {
        return iVar1;
      }
      goto LAB_14000e139;
    }
  }
  iVar1 = -0x3fffff66;
LAB_14000e139:
  if (WfpRioNetBufferListPool == 0) {
    NdisFreeNetBufferListPool(0);
  }
  if (WfpRioNdisObject != 0) {
    NdisFreeGenericObject();
  }
  return iVar1;
}



===== L2UpdateCompletedNblCounts @ 14000e190 =====

void L2UpdateCompletedNblCounts(longlong param_1,int param_2)

{
  undefined1 uVar1;
  int iVar2;
  
  if (param_2 != 0) {
    uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x30);
    iVar2 = *(int *)(param_1 + 0x148) - param_2;
    *(int *)(param_1 + 0x148) = iVar2;
    if ((iVar2 == 0) && (*(int *)(param_1 + 0x3c) == 4)) {
      *(undefined4 *)(param_1 + 0x3c) = 1;
      KeReleaseSpinLock(param_1 + 0x30,uVar1);
      NdisFPauseComplete(*(undefined8 *)(param_1 + 0x48));
      return;
    }
    KeReleaseSpinLock(param_1 + 0x30,uVar1);
  }
  return;
}



===== LwfUpperKfdUpdateNotify @ 14000e23c =====

int LwfUpperKfdUpdateNotify(longlong param_1)

{
  longlong lVar1;
  undefined1 uVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  
  lVar1 = param_1 + 0x30;
  iVar4 = 0;
  uVar2 = KeAcquireSpinLockRaiseToDpc(lVar1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
               &WPP_2142e384b80c35b5005992d824702965_Traceguids,*(undefined4 *)(param_1 + 0x118),
               (char)*(undefined4 *)(param_1 + 0x3c),*(undefined1 *)(param_1 + 0x40));
  }
  uVar5 = *(uint *)(param_1 + 0x118);
  if (uVar5 != 3) {
    cVar3 = L2IsClassifyNeededForInterface(0x39,*(undefined8 *)(param_1 + 0x50),0x20);
    if ((cVar3 != '\0') && ((*(uint *)(param_1 + 0x118) & 1) == 0)) {
      uVar5 = uVar5 | 1;
    }
    cVar3 = L2IsClassifyNeededForInterface(0x38,*(undefined8 *)(param_1 + 0x50),0x20);
    if ((cVar3 != '\0') && ((*(uint *)(param_1 + 0x118) & 2) == 0)) {
      uVar5 = uVar5 | 2;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
               &WPP_2142e384b80c35b5005992d824702965_Traceguids,uVar5);
    }
    if (uVar5 != *(uint *)(param_1 + 0x118)) {
      *(uint *)(param_1 + 0x11c) = uVar5;
      if (*(int *)(param_1 + 0x3c) == 1) {
        if (*(char *)(param_1 + 0x40) != '\0') {
LAB_14000e3a4:
          *(undefined1 *)(param_1 + 0x120) = 1;
          KeReleaseSpinLock(lVar1,uVar2);
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                    &WPP_2142e384b80c35b5005992d824702965_Traceguids);
          }
          iVar4 = NdisFRestartFilter(*(undefined8 *)(param_1 + 0x48));
          if (iVar4 == 0) {
            return 0x103;
          }
          if (((iVar4 == 0x103) || (iVar4 == -0x7ffffffb)) ||
             ((iVar4 == -0x3fffffff || ((iVar4 == -0x3fffff66 || (iVar4 == -0x3fffff45)))))) {
            return iVar4;
          }
          if (iVar4 == -0x3ffeffea) {
            return -0x3fffffdd;
          }
          if (iVar4 == -0x3ffeffec) {
            return -0x3ffffdfa;
          }
          if (iVar4 == -0x3ffeffeb) {
            return -0x3ffffff3;
          }
          return -0x3fffffff;
        }
        *(undefined1 *)(param_1 + 0x120) = 1;
        iVar4 = 0x103;
      }
      else if (*(int *)(param_1 + 0x3c) - 2U < 3) goto LAB_14000e3a4;
    }
  }
  KeReleaseSpinLock(lVar1,uVar2);
  return iVar4;
}



===== LwfUpperPause @ 14000e480 =====

uint LwfUpperPause(longlong param_1)

{
  int iVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc();
  iVar1 = *(int *)(param_1 + 0x148);
  uVar3 = 4;
  if (iVar1 == 0) {
    uVar3 = 1;
  }
  *(undefined4 *)(param_1 + 0x3c) = uVar3;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
             &WPP_2142e384b80c35b5005992d824702965_Traceguids,uVar3);
  }
  KeReleaseSpinLock(param_1 + 0x30,uVar2);
  return -(uint)(iVar1 != 0) & 0x103;
}



===== LwfUpperRestart @ 14000e540 =====

undefined8 LwfUpperRestart(longlong param_1,longlong param_2)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
            &WPP_2142e384b80c35b5005992d824702965_Traceguids);
  }
  if ((*(int *)(param_1 + 0x5c) != 0) && (*(int *)(param_2 + 4) == 0)) {
    *(undefined4 *)(param_1 + 0x5c) = 0;
  }
  *(undefined1 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 3;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
             &WPP_2142e384b80c35b5005992d824702965_Traceguids,3);
  }
  return 0;
}



===== LwfUpperSendNetBufferListsComplete @ 14000e5f0 =====

void LwfUpperSendNetBufferListsComplete(longlong param_1,longlong ***param_2,undefined4 param_3)

{
  longlong ****pppplVar1;
  longlong *****ppppplVar2;
  longlong ***ppplVar3;
  ulonglong uVar4;
  longlong *****ppppplVar5;
  int iVar6;
  longlong *****ppppplVar7;
  longlong *****local_res10;
  
  iVar6 = 0;
  for (ppplVar3 = param_2; ppplVar3 != (longlong ***)0x0; ppplVar3 = (longlong ***)*ppplVar3) {
    iVar6 = iVar6 + 1;
  }
  local_res10 = (longlong *****)param_2;
  ppplVar3 = (longlong ***)WfpGetPacketTagCount();
  ppppplVar5 = local_res10;
  while (local_res10 = ppppplVar5, ppplVar3 != (longlong ***)0x0) {
    FwppNetBufferListEventNotify(param_2,0,6);
    param_2 = (longlong ***)*param_2;
    ppppplVar5 = local_res10;
    ppplVar3 = param_2;
  }
  if (*(int *)(param_1 + 0x148) != 0) {
    ppppplVar7 = (longlong *****)&local_res10;
    pppplVar1 = *(longlong *****)(param_1 + 0x48);
    if (ppppplVar5 == (longlong *****)0x0) goto LAB_14000e6e9;
    do {
      ppppplVar2 = (longlong *****)*ppppplVar5;
      if (((ppppplVar5[0xf] == pppplVar1) &&
          (uVar4 = WfpNblInfoGetFlags(ppppplVar5), (uVar4 & 2) != 0)) &&
         (*(int *)(*(longlong *)
                    ((ulonglong)*(ushort *)((longlong)ppppplVar5[2] + 10) + 0x18 +
                    (longlong)ppppplVar5[2]) + 0x38) == 1)) {
        L2CompleteInjectedNetBufferLists(ppppplVar5);
        *ppppplVar7 = (longlong ****)ppppplVar2;
      }
      else {
        ppppplVar7 = ppppplVar5;
      }
      ppppplVar5 = ppppplVar2;
    } while (ppppplVar2 != (longlong *****)0x0);
  }
  if (local_res10 != (longlong *****)0x0) {
    NdisFSendNetBufferListsComplete(*(undefined8 *)(param_1 + 0x48),local_res10,param_3);
  }
LAB_14000e6e9:
  L2UpdateCompletedNblCounts(param_1,iVar6);
  return;
}



===== LwfUpperSetFilterModuleOptions @ 14000e710 =====

undefined8 LwfUpperSetFilterModuleOptions(longlong param_1)

{
  longlong lVar1;
  uint uVar2;
  bool bVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 uVar6;
  bool bVar7;
  undefined8 local_48;
  code *pcStack_40;
  code *local_38;
  undefined8 uStack_30;
  code *local_28;
  code *pcStack_20;
  
  lVar1 = param_1 + 0x30;
  bVar3 = false;
  bVar7 = false;
  local_48 = 0;
  pcStack_40 = (code *)0x0;
  local_38 = (code *)0x0;
  uStack_30 = 0;
  local_28 = (code *)0x0;
  pcStack_20 = (code *)0x0;
  uVar6 = KeAcquireSpinLockRaiseToDpc(lVar1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_2142e384b80c35b5005992d824702965_Traceguids,*(undefined4 *)(param_1 + 0x11c),
              (char)*(undefined4 *)(param_1 + 0x118));
  }
  uVar4 = local_48;
  uVar2 = *(uint *)(param_1 + 0x11c);
  if (uVar2 != *(uint *)(param_1 + 0x118)) {
    local_48 = CONCAT71(local_48._1_7_,0x8c);
    uVar5 = local_48;
    local_48._4_4_ = SUB84(uVar4,4);
    local_48._0_4_ = CONCAT22(0x30,(short)uVar5);
    if ((uVar2 & 1) != 0) {
      pcStack_40 = LwfUpperSendNetBufferLists;
      local_38 = LwfUpperSendNetBufferListsComplete;
    }
    if ((uVar2 & 2) != 0) {
      local_28 = LwfUpperRecvNetBufferLists;
      pcStack_20 = LwfUpperReturnNetBufferLists;
    }
    bVar3 = true;
    *(uint *)(param_1 + 0x118) = uVar2;
    bVar7 = *(char *)(param_1 + 0x120) != '\0';
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0))
    {
      WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                &WPP_2142e384b80c35b5005992d824702965_Traceguids,uVar2,*(char *)(param_1 + 0x120));
    }
  }
  *(undefined1 *)(param_1 + 0x40) = 1;
  KeReleaseSpinLock(lVar1,uVar6);
  if (bVar3) {
    NdisSetOptionalHandlers(*(undefined8 *)(param_1 + 0x48),&local_48);
  }
  if (bVar7) {
    uVar6 = KeAcquireSpinLockRaiseToDpc(lVar1);
    *(undefined1 *)(param_1 + 0x120) = 0;
    KeSetEvent(param_1 + 0x128,0,0);
    KeReleaseSpinLock(lVar1,uVar6);
  }
  return 0;
}



===== LwfLowerAttach @ 14000e8f0 =====

int LwfLowerAttach(longlong param_1,undefined8 param_2,longlong param_3)

{
  code *pcVar1;
  bool bVar2;
  char cVar3;
  undefined1 uVar4;
  undefined4 uVar5;
  int iVar6;
  longlong *plVar7;
  undefined8 *puVar8;
  undefined1 *puVar9;
  undefined8 local_res20;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  longlong *local_18 [2];
  
  local_res20 = 0;
  plVar7 = (longlong *)ExAllocatePool2(0x40,0x3e0,0x6c326c57);
  if (plVar7 == (longlong *)0x0) {
    iVar6 = -0x3fffff66;
  }
  else {
    *(undefined4 *)(plVar7 + 7) = 0;
    *(undefined4 *)((longlong)plVar7 + 0x3c) = 1;
    plVar7[9] = param_1;
    plVar7[10] = *(longlong *)(param_3 + 0x88);
    *(undefined4 *)(plVar7 + 0xb) = *(undefined4 *)(param_3 + 0x18);
    *(undefined4 *)((longlong)plVar7 + 0x5c) = *(undefined4 *)(param_3 + 0x48);
    *(undefined4 *)(plVar7 + 0xc) = *(undefined4 *)(param_3 + 0x4c);
    *(undefined2 *)((longlong)plVar7 + 100) = *(undefined2 *)(param_3 + 0x8e);
    plVar7[0x2a] = 0;
    plVar7[0x2b] = 0;
    *(undefined1 *)((longlong)plVar7 + 0x66) = *(undefined1 *)(param_3 + 200);
    *(undefined1 *)(plVar7 + 8) = 0;
    plVar7[0x28] = 0;
    *(undefined4 *)(plVar7 + 0x29) = 0;
    plVar7[0x79] = 0;
    local_18[0] = plVar7;
    uVar5 = GetInterfaceCompartmentId();
    *(undefined4 *)((longlong)plVar7 + 0x3dc) = uVar5;
    *(undefined4 *)((longlong)plVar7 + 0x67) = 0;
    *(undefined2 *)((longlong)plVar7 + 0x6b) = 0;
    memset(plVar7 + 0x2c,0,0x240);
    plVar7[0x74] = 0;
    plVar7[0x75] = 0;
    plVar7[0x76] = 0;
    *(undefined4 *)(plVar7 + 0x77) = 0;
    KeInitializeSpinLock(plVar7 + 6);
    if (DAT_14002cf44 == '\0') {
      *(undefined4 *)(plVar7 + 0x23) = 0;
      *(undefined4 *)((longlong)plVar7 + 0x11c) = 0;
      *(undefined1 *)(plVar7 + 0x24) = 0;
      KeInitializeEvent(plVar7 + 0x25,0);
      bVar2 = LwfLowerIsSupportedMediaType(*(uint *)((longlong)plVar7 + 0x5c));
      if (bVar2) {
        cVar3 = L2IsClassifyNeededForInterface(0x3b,plVar7[10],0);
        if (cVar3 != '\0') {
          *(uint *)((longlong)plVar7 + 0x11c) = *(uint *)((longlong)plVar7 + 0x11c) | 1;
        }
        cVar3 = L2IsClassifyNeededForInterface(0x3a,plVar7[10],0);
        if (cVar3 != '\0') {
          *(uint *)((longlong)plVar7 + 0x11c) = *(uint *)((longlong)plVar7 + 0x11c) | 2;
        }
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                   &WPP_8d78ca0d606e3bf520aeb7d0d517a1c9_Traceguids,
                   *(undefined4 *)((longlong)plVar7 + 0x11c));
        }
      }
    }
    else {
      *(undefined4 *)(plVar7 + 0x23) = 3;
      *(undefined4 *)((longlong)plVar7 + 0x11c) = 3;
    }
    *(undefined4 *)((longlong)plVar7 + 0x14c) = 2;
    local_res20 = 0x8018d;
    iVar6 = NdisFSetAttributes(param_1,plVar7,&local_res20);
    if (iVar6 == 0) {
      L2InitializeNblReferenceRecords((longlong)plVar7);
      uVar4 = KeAcquireSpinLockRaiseToDpc(&DAT_14002ce90);
      puVar9 = auStack_38;
      puVar8 = &DAT_14002ceb0;
      if ((undefined8 *)*DAT_14002ceb8 != &DAT_14002ceb0) {
        puVar8 = (undefined8 *)0x3;
        pcVar1 = (code *)swi(0x29);
        uVar4 = (*pcVar1)();
        puVar9 = auStack_30;
      }
      *plVar7 = (longlong)puVar8;
      plVar7[1] = (longlong)DAT_14002ceb8;
      *DAT_14002ceb8 = (longlong)plVar7;
      DAT_14002cec0 = DAT_14002cec0 + 1;
      *(undefined8 *)(puVar9 + -8) = 0x14000eb5b;
      DAT_14002ceb8 = plVar7;
      KeReleaseSpinLock(&DAT_14002ce90,uVar4);
    }
    else {
      L2LwfFree((longlong *)local_18);
    }
  }
  return iVar6;
}



===== LwfLowerPause @ 14000eb90 =====

uint LwfLowerPause(longlong param_1)

{
  int iVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc();
  iVar1 = *(int *)(param_1 + 0x148);
  uVar3 = 4;
  if (iVar1 == 0) {
    uVar3 = 1;
  }
  *(undefined4 *)(param_1 + 0x3c) = uVar3;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
             &WPP_8d78ca0d606e3bf520aeb7d0d517a1c9_Traceguids,uVar3);
  }
  KeReleaseSpinLock(param_1 + 0x30,uVar2);
  return -(uint)(iVar1 != 0) & 0x103;
}



===== LwfLowerRestart @ 14000ec50 =====

int LwfLowerRestart(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
            &WPP_8d78ca0d606e3bf520aeb7d0d517a1c9_Traceguids);
  }
  if (((*(uint *)(param_1 + 0x5c) < 0x13) &&
      ((0x50200U >> (*(uint *)(param_1 + 0x5c) & 0x1f) & 1) != 0)) &&
     (iVar1 = LwfLowerAdvertiseL2ProfileSupport(*(undefined8 **)(param_2 + 0x10)), iVar1 != 0)) {
    return iVar1;
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x5c) == 0x10) {
    puVar2 = (undefined4 *)ExAllocatePool2(0x40,0x100,0x67326c57);
    if (puVar2 == (undefined4 *)0x0) {
      return -0x3fffff66;
    }
    puVar2[1] = 0;
    *puVar2 = 0xec0196;
    puVar2[8] = 0xd010308;
    *(undefined4 **)(puVar2 + 10) = puVar2 + 0x3e;
    puVar2[0xc] = 8;
    *(undefined8 *)(puVar2 + 4) = 0x67326c57;
    *(undefined4 *)(param_1 + 0x3c) = 2;
    iVar1 = NdisFOidRequest(*(undefined8 *)(param_1 + 0x48),puVar2);
    if (iVar1 != 0x103) {
      *(undefined4 *)(param_1 + 0x3c) = 1;
      LwfLowerOidRequestComplete(param_1,(longlong)puVar2,iVar1);
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x3c) = 3;
    *(undefined1 *)(param_1 + 0x40) = 0;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
             &WPP_8d78ca0d606e3bf520aeb7d0d517a1c9_Traceguids,*(undefined4 *)(param_1 + 0x3c));
  }
  return iVar1;
}



===== LwfLowerReturnNetBufferLists @ 14000edc0 =====

void LwfLowerReturnNetBufferLists(longlong param_1,longlong ***param_2,undefined4 param_3)

{
  longlong ****pppplVar1;
  longlong *****ppppplVar2;
  longlong ***ppplVar3;
  ulonglong uVar4;
  longlong *****ppppplVar5;
  int iVar6;
  longlong *****ppppplVar7;
  longlong *****local_res10;
  
  iVar6 = 0;
  for (ppplVar3 = param_2; ppplVar3 != (longlong ***)0x0; ppplVar3 = (longlong ***)*ppplVar3) {
    iVar6 = iVar6 + 1;
  }
  local_res10 = (longlong *****)param_2;
  ppplVar3 = (longlong ***)WfpGetPacketTagCount();
  ppppplVar5 = local_res10;
  while (local_res10 = ppppplVar5, ppplVar3 != (longlong ***)0x0) {
    FwppNetBufferListEventNotify(param_2,0,9);
    param_2 = (longlong ***)*param_2;
    ppppplVar5 = local_res10;
    ppplVar3 = param_2;
  }
  if (*(int *)(param_1 + 0x148) != 0) {
    ppppplVar7 = (longlong *****)&local_res10;
    pppplVar1 = *(longlong *****)(param_1 + 0x48);
    if (ppppplVar5 == (longlong *****)0x0) goto LAB_14000eeb9;
    do {
      ppppplVar2 = (longlong *****)*ppppplVar5;
      if (((ppppplVar5[0xf] == pppplVar1) &&
          (uVar4 = WfpNblInfoGetFlags(ppppplVar5), (uVar4 & 2) != 0)) &&
         (*(int *)(*(longlong *)
                    ((ulonglong)*(ushort *)((longlong)ppppplVar5[2] + 10) + 0x18 +
                    (longlong)ppppplVar5[2]) + 0x38) == 0)) {
        L2CompleteInjectedNetBufferLists(ppppplVar5);
        *ppppplVar7 = (longlong ****)ppppplVar2;
      }
      else {
        ppppplVar7 = ppppplVar5;
      }
      ppppplVar5 = ppppplVar2;
    } while (ppppplVar2 != (longlong *****)0x0);
  }
  if (local_res10 != (longlong *****)0x0) {
    NdisFReturnNetBufferLists(*(undefined8 *)(param_1 + 0x48),local_res10,param_3);
  }
LAB_14000eeb9:
  L2UpdateCompletedNblCounts(param_1,iVar6);
  return;
}



===== LwfLowerSendNetBufferListsComplete @ 14000eee0 =====

void LwfLowerSendNetBufferListsComplete(longlong param_1,longlong ***param_2,undefined4 param_3)

{
  longlong ****pppplVar1;
  longlong *****ppppplVar2;
  longlong ***ppplVar3;
  ulonglong uVar4;
  longlong *****ppppplVar5;
  int iVar6;
  longlong *****ppppplVar7;
  longlong *****local_res10;
  
  iVar6 = 0;
  for (ppplVar3 = param_2; ppplVar3 != (longlong ***)0x0; ppplVar3 = (longlong ***)*ppplVar3) {
    iVar6 = iVar6 + 1;
  }
  local_res10 = (longlong *****)param_2;
  ppplVar3 = (longlong ***)WfpGetPacketTagCount();
  ppppplVar5 = local_res10;
  while (local_res10 = ppppplVar5, ppplVar3 != (longlong ***)0x0) {
    FwppNetBufferListEventNotify(param_2,0,8);
    param_2 = (longlong ***)*param_2;
    ppppplVar5 = local_res10;
    ppplVar3 = param_2;
  }
  if (*(int *)(param_1 + 0x148) != 0) {
    ppppplVar7 = (longlong *****)&local_res10;
    pppplVar1 = *(longlong *****)(param_1 + 0x48);
    if (ppppplVar5 == (longlong *****)0x0) goto LAB_14000efd9;
    do {
      ppppplVar2 = (longlong *****)*ppppplVar5;
      if (((ppppplVar5[0xf] == pppplVar1) &&
          (uVar4 = WfpNblInfoGetFlags(ppppplVar5), (uVar4 & 2) != 0)) &&
         (*(int *)(*(longlong *)
                    ((ulonglong)*(ushort *)((longlong)ppppplVar5[2] + 10) + 0x18 +
                    (longlong)ppppplVar5[2]) + 0x38) == 0)) {
        L2CompleteInjectedNetBufferLists(ppppplVar5);
        *ppppplVar7 = (longlong ****)ppppplVar2;
      }
      else {
        ppppplVar7 = ppppplVar5;
      }
      ppppplVar5 = ppppplVar2;
    } while (ppppplVar2 != (longlong *****)0x0);
  }
  if (local_res10 != (longlong *****)0x0) {
    NdisFSendNetBufferListsComplete(*(undefined8 *)(param_1 + 0x48),local_res10,param_3);
  }
LAB_14000efd9:
  L2UpdateCompletedNblCounts(param_1,iVar6);
  return;
}



===== LwfLowerSetFilterModuleOptions @ 14000f000 =====

undefined8 LwfLowerSetFilterModuleOptions(longlong param_1)

{
  longlong lVar1;
  uint uVar2;
  bool bVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 uVar6;
  bool bVar7;
  undefined8 local_48;
  code *pcStack_40;
  code *local_38;
  undefined8 uStack_30;
  code *local_28;
  code *pcStack_20;
  
  lVar1 = param_1 + 0x30;
  bVar3 = false;
  bVar7 = false;
  local_48 = 0;
  pcStack_40 = (code *)0x0;
  local_38 = (code *)0x0;
  uStack_30 = 0;
  local_28 = (code *)0x0;
  pcStack_20 = (code *)0x0;
  uVar6 = KeAcquireSpinLockRaiseToDpc(lVar1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
              &WPP_8d78ca0d606e3bf520aeb7d0d517a1c9_Traceguids,*(undefined4 *)(param_1 + 0x11c),
              (char)*(undefined4 *)(param_1 + 0x118));
  }
  uVar4 = local_48;
  uVar2 = *(uint *)(param_1 + 0x11c);
  if (uVar2 != *(uint *)(param_1 + 0x118)) {
    local_48 = CONCAT71(local_48._1_7_,0x8c);
    uVar5 = local_48;
    local_48._4_4_ = SUB84(uVar4,4);
    local_48._0_4_ = CONCAT22(0x30,(short)uVar5);
    if ((uVar2 & 1) != 0) {
      pcStack_40 = LwfLowerSendNetBufferLists;
      local_38 = LwfLowerSendNetBufferListsComplete;
    }
    if ((uVar2 & 2) != 0) {
      local_28 = LwfLowerRecvNetBufferLists;
      pcStack_20 = LwfLowerReturnNetBufferLists;
    }
    bVar3 = true;
    *(uint *)(param_1 + 0x118) = uVar2;
    bVar7 = *(char *)(param_1 + 0x120) != '\0';
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0))
    {
      WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                &WPP_8d78ca0d606e3bf520aeb7d0d517a1c9_Traceguids,uVar2,*(char *)(param_1 + 0x120));
    }
  }
  *(undefined1 *)(param_1 + 0x40) = 1;
  KeReleaseSpinLock(lVar1,uVar6);
  if (bVar3) {
    NdisSetOptionalHandlers(*(undefined8 *)(param_1 + 0x48),&local_48);
  }
  if (bVar7) {
    uVar6 = KeAcquireSpinLockRaiseToDpc(lVar1);
    *(undefined1 *)(param_1 + 0x120) = 0;
    KeSetEvent(param_1 + 0x128,0,0);
    KeReleaseSpinLock(lVar1,uVar6);
  }
  return 0;
}



===== L2InjectNetBufferLists @ 14000f1e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void L2InjectNetBufferLists
               (ulonglong param_1,longlong ******param_2,uint param_3,uint param_4,ushort param_5,
               uint param_6)

{
  ushort uVar1;
  longlong *******ppppppplVar2;
  longlong ***ppplVar3;
  char cVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  longlong lVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  longlong *******ppppppplVar11;
  longlong ******pppppplVar12;
  longlong *******ppppppplVar13;
  longlong *******ppppppplVar14;
  longlong ******local_res10;
  uint local_res18;
  uint local_res20;
  int local_68 [2];
  longlong *******local_60;
  longlong *******local_58;
  longlong *******local_50 [2];
  
  ppppppplVar14 = (longlong *******)0x0;
  uVar9 = (ulonglong)param_4;
  local_50[0] = (longlong *******)0x0;
  local_58 = &local_res10;
  local_68[0] = 0;
  uVar10 = param_1;
  ppppppplVar13 = local_58;
  local_res10 = param_2;
  local_res18 = param_3;
  local_res20 = param_4;
  local_60 = (longlong *******)param_2;
  do {
    ppppppplVar11 = local_60;
    iVar7 = local_68[0];
    pppppplVar12 = local_60[2];
    iVar6 = 0;
    ppppppplVar2 = (longlong *******)*local_60;
    uVar1 = *(ushort *)((longlong)pppppplVar12 + 10);
    ppplVar3 = *(longlong ****)((longlong)pppppplVar12 + (ulonglong)uVar1 + 0x18);
    *local_60 = (longlong ******)0x0;
    if (*(char *)((longlong)pppppplVar12 + (ulonglong)uVar1 + 0x22) == '\0') {
      if (*(int *)(ppplVar3 + 7) == 0) {
        cVar4 = L2NativeIsNetBufferListPermitted
                          (*(ushort *)((longlong)pppppplVar12 + (ulonglong)uVar1 + 0x20),'\x01',
                           (longlong *)&local_60,0,(longlong *)0x0,(longlong)ppplVar3,local_res18,
                           param_6);
      }
      else if (*(int *)(ppplVar3 + 7) == 1) {
        cVar4 = L2802_3IsNetBufferListPermitted
                          (*(ushort *)((longlong)pppppplVar12 + (ulonglong)uVar1 + 0x20),'\x01',
                           (longlong *)&local_60,(longlong *)0x0,(longlong *)ppplVar3,local_res18,
                           param_6);
      }
      else {
        lVar8 = vSwitchFindOriginalvmSwitchNetBufferList((longlong)local_60);
        if (lVar8 != 0) {
          iVar7 = (*DAT_14002c5c0)(ppplVar3[0x14],ppppppplVar11,lVar8,0);
          uVar9 = (ulonglong)local_res20;
          iVar6 = 0;
          ppppppplVar13 = local_58;
          if (iVar7 == 0) goto LAB_14000f2ee;
LAB_14000f482:
          uVar10 = param_1 & 0xffff;
          goto LAB_14000f486;
        }
LAB_14000f2ee:
        if (*(short *)((longlong)pppppplVar12 + (ulonglong)uVar1 + 0x20) == 0x48) {
          if (lVar8 == 0) {
            *(uint *)((longlong)ppppppplVar11 + 300) =
                 *(uint *)((longlong)ppppppplVar11 + 300) | 0x400;
          }
          else if (((uint)*(ushort *)(lVar8 + 0x12a) == (uint)uVar9) &&
                  (((ushort)*(undefined4 *)(lVar8 + 300) & 0xff) == param_5)) {
            if (iVar6 != 0) goto LAB_14000f482;
            goto LAB_14000f346;
          }
          iVar6 = L2vSwitchValidatePortNicAndSetSource
                            ((uint)uVar9,(ulonglong)param_5,ppppppplVar11,(longlong)ppplVar3);
          if (iVar6 != 0) {
            uVar9 = (ulonglong)local_res20;
            ppppppplVar13 = local_58;
            goto LAB_14000f482;
          }
        }
LAB_14000f346:
        uVar1 = *(ushort *)((longlong)pppppplVar12 + (ulonglong)uVar1 + 0x20);
        cVar4 = vSwitch802_3IsNetBufferListPermitted
                          ((uVar1 != 0x48) + 1,uVar1,'\x01',(longlong *)&local_60,(longlong)ppplVar3
                          );
        iVar7 = local_68[0];
      }
      uVar10 = param_1 & 0xffff;
      uVar9 = (ulonglong)local_res20;
      if (cVar4 != '\0') goto LAB_14000f396;
      ppppppplVar11 = local_60;
      ppppppplVar13 = local_58;
LAB_14000f486:
      *ppppppplVar13 = (longlong ******)ppppppplVar2;
      local_60 = ppppppplVar13;
      if (ppppppplVar11 != (longlong *******)0x0) {
        *ppppppplVar11 = (longlong ******)ppppppplVar14;
        ppppppplVar14 = ppppppplVar11;
        local_50[0] = ppppppplVar11;
      }
    }
    else {
      if ((local_60[0x24] != (longlong ******)0x0) &&
         (*(short *)((longlong)pppppplVar12 + (ulonglong)uVar1 + 0x20) != (short)uVar10))
      goto LAB_14000f486;
LAB_14000f396:
      local_68[0] = iVar7 + 1;
      *local_60 = (longlong ******)ppppppplVar2;
      local_58 = local_60;
    }
    pppppplVar12 = local_res10;
    ppppppplVar13 = local_60;
    local_60 = ppppppplVar2;
    if (ppppppplVar2 == (longlong *******)0x0) {
      if ((local_res10 != (longlong ******)0x0) && (ppplVar3 != (longlong ***)0x0)) {
        uVar9 = L2IsInboundLayer((int)uVar10);
        if ((char)uVar9 == '\0') {
          if ((short)uVar10 == 0x48) {
            iVar6 = KfdIsLayerEmpty(0x4a);
            iVar7 = KfdIsLayerEmpty(0x4b);
            local_58 = (longlong *******)0x0;
            if ((iVar6 == 0) || (iVar7 == 0)) {
              bVar5 = L2AcquireL3InspectRef((longlong)ppplVar3);
              if (bVar5) {
                uVar10 = Feature_Firewall_BugFixes_25D_WFPlwfs_L28023_resilience__private_IsEnabledDeviceUsageNoInline
                                   ();
                if ((int)uVar10 == 0) {
                  vSwitchInspectL3NetBufferLists
                            (ppplVar3,1,iVar6 == 0,iVar7 == 0,(longlong ***)&local_res10,(int *)0x0,
                             (longlong ***)&local_58,param_6);
                }
                else {
                  vSwitchInspectL3NetBufferLists_25D
                            (ppplVar3,1,iVar6 == 0,iVar7 == 0,(longlong ***)&local_res10,(int *)0x0,
                             (longlong ***)&local_58,param_6);
                }
                L2UpdateCompletedNblCounts((longlong)ppplVar3,1);
                pppppplVar12 = local_res10;
              }
              else {
                L2MoveNblsToBlockList(pppppplVar12,local_50);
                ppppppplVar14 = local_50[0];
              }
            }
          }
          if (pppppplVar12 != (longlong ******)0x0) {
            L2NdisFSendNetBufferLists
                      ((longlong)ppplVar3,ppplVar3[9],(longlong ***)pppppplVar12,local_res18,param_6
                      );
          }
        }
        else {
          if ((short)uVar10 == 0x49) {
            iVar6 = KfdIsLayerEmpty(0x4c);
            iVar7 = KfdIsLayerEmpty(0x4d);
            local_58 = (longlong *******)0x0;
            if ((iVar6 == 0) || (iVar7 == 0)) {
              bVar5 = L2AcquireL3InspectRef((longlong)ppplVar3);
              if (bVar5) {
                uVar10 = Feature_Firewall_BugFixes_25D_WFPlwfs_L28023_resilience__private_IsEnabledDeviceUsageNoInline
                                   ();
                if ((int)uVar10 == 0) {
                  vSwitchInspectL3NetBufferLists
                            (ppplVar3,2,iVar6 == 0,iVar7 == 0,(longlong ***)&local_res10,local_68,
                             (longlong ***)&local_58,param_6);
                }
                else {
                  vSwitchInspectL3NetBufferLists_25D
                            (ppplVar3,2,iVar6 == 0,iVar7 == 0,(longlong ***)&local_res10,local_68,
                             (longlong ***)&local_58,param_6);
                }
                L2UpdateCompletedNblCounts((longlong)ppplVar3,1);
                pppppplVar12 = local_res10;
              }
              else {
                L2MoveNblsToBlockList(pppppplVar12,local_50);
                ppppppplVar14 = local_50[0];
              }
            }
          }
          if (pppppplVar12 != (longlong ******)0x0) {
            L2NdisFIndicateReceiveNetBufferLists
                      ((longlong)ppplVar3,ppplVar3[9],(longlong ***)pppppplVar12,local_res18,
                       local_68[0],param_6);
          }
        }
      }
      if (ppppppplVar14 != (longlong *******)0x0) {
        do {
          ppppppplVar13 = (longlong *******)*ppppppplVar14;
          *(undefined4 *)((longlong)ppppppplVar14 + 0x8c) = 0x10003;
          L2CompleteInjectedNetBufferLists(ppppppplVar14);
          ppppppplVar14 = ppppppplVar13;
        } while (ppppppplVar13 != (longlong *******)0x0);
      }
      return;
    }
  } while( true );
}



===== WfpRioChannelCreate @ 14000f620 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int WfpRioChannelCreate(undefined8 *param_1,undefined8 *param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  void *_Dst;
  void *_Dst_00;
  undefined8 *puVar3;
  void *_Dst_01;
  ulonglong uVar4;
  uint uVar5;
  undefined8 *_Src;
  int iVar6;
  uint uVar7;
  undefined *_Size;
  ulonglong _Size_00;
  undefined1 auStack_c8 [32];
  void *local_a8;
  void *local_a0;
  longlong local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined4 local_60;
  uint uStack_5c;
  uint uStack_58;
  uint uStack_54;
  ulonglong local_50;
  uint local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_c8;
  local_68 = 0;
  local_a8 = (void *)0x0;
  local_a0 = (void *)0x0;
  local_98 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_80 = 0;
  local_90 = 0;
  uStack_88 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x51,
            &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids);
  }
  *param_2 = 0;
  puVar2 = (undefined4 *)param_1[3];
  if ((puVar2 == (undefined4 *)0x0) || (uVar1 = *(uint *)(param_1 + 2), uVar1 < 0x1c)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((3 < (byte)WPP_GLOBAL_Control[0x29] && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x52,
              &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids);
    }
  }
  else {
    local_60 = *puVar2;
    uStack_5c = puVar2[1];
    uStack_58 = puVar2[2];
    uStack_54 = puVar2[3];
    local_48 = puVar2[6];
    local_50 = *(ulonglong *)(puVar2 + 4);
    if (((uStack_5c < uVar1) &&
        (uVar5 = (uint)((ulonglong)*(undefined8 *)(puVar2 + 2) >> 0x20), uVar5 < uVar1)) &&
       (uVar7 = (uint)(local_50 >> 0x20), uVar7 < uVar1)) {
      if ((uStack_5c <= uStack_58 + uStack_5c) && (uStack_58 + uStack_5c <= uVar1)) {
        uVar4 = local_50 & 0xffffffff;
        if (((uVar5 <= (uint)local_50 + uVar5) &&
            (((uint)local_50 + uVar5 <= uVar1 && (uVar7 <= local_48 + uVar7)))) &&
           (local_48 + uVar7 <= uVar1)) {
          if (((uStack_58 <= uStack_58 + 0x1c) &&
              (uVar5 = (uint)local_50 + uStack_58 + 0x1c, (uint)local_50 <= uVar5)) &&
             ((2 < local_48 && ((local_48 & 1) == 0)))) {
            uVar7 = local_48 - 2;
            uVar5 = uVar5 + uVar7;
            if ((uVar7 <= uVar5) && (uVar5 <= uVar1)) {
              _Size_00 = (ulonglong)uStack_58;
              _Dst = (void *)ExAllocatePool2(0x40,uStack_58,0x70646657);
              if (_Dst == (void *)0x0) {
                iVar6 = -0x3fffff66;
                goto LAB_14000fc24;
              }
              memmove(_Dst,(void *)((ulonglong)uStack_5c + (longlong)puVar2),_Size_00);
              _Dst_00 = (void *)ExAllocatePool2(0x40,uVar4,0x70646657);
              if (_Dst_00 == (void *)0x0) {
LAB_14000f805:
                iVar6 = -0x3fffff66;
              }
              else {
                memmove(_Dst_00,(void *)((ulonglong)uStack_54 + (longlong)puVar2),uVar4);
                local_a8 = (void *)ExAllocatePool2(0x40,uVar7,0x70646657);
                if (local_a8 == (void *)0x0) goto LAB_14000f805;
                memmove(local_a8,(void *)((local_50 >> 0x20) + (longlong)puVar2),(ulonglong)uVar7);
                RtlAcquireWriteLock(0x14002c670);
                _Size = (undefined *)(ulonglong)uVar7;
                puVar3 = WfpRioFindExistingRegDomainForPackage(_Dst_00,_Dst,_Size,local_a8);
                if (puVar3 == (undefined8 *)0x0) {
                  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                      (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
                     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
                    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x54,
                            &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids);
                  }
                  iVar6 = -0x3ffffddb;
                }
                else {
                  _Src = &local_90;
                  RtlAcquireWriteLock(puVar3[2]);
                  if (*(char *)((longlong)puVar3 + 0x71) == '\0') {
                    if ((puVar3[0x37] != 0) || (puVar3[0x38] != 0)) {
                      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                         ((3 < (byte)WPP_GLOBAL_Control[0x29] &&
                          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)))) {
                        _Src = (undefined8 *)0x56;
                        goto LAB_14000fae0;
                      }
                      goto LAB_14000faf0;
                    }
                    uVar4 = Feature_VPN_BugFixes_25A__private_IsEnabledDeviceUsageNoInline();
                    iVar6 = 0;
                    if (((int)uVar4 == 0) && (*(int *)((longlong)puVar3 + 0x4c) == 4)) {
                      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                         ((3 < (byte)WPP_GLOBAL_Control[0x29] &&
                          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)))) {
                        _Src = (undefined8 *)0x57;
                        goto LAB_14000fae0;
                      }
                      goto LAB_14000faf0;
                    }
                    if (puVar3[0x33] != 0) {
                      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                          (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
                         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
                        _Src = (undefined8 *)0x58;
                        goto LAB_14000fae0;
                      }
                      goto LAB_14000faf0;
                    }
                    if (puVar3[0x34] != 0) {
                      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                          (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
                         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
                        _Src = (undefined8 *)0x59;
                        goto LAB_14000fae0;
                      }
                      goto LAB_14000faf0;
                    }
                    _Src = (undefined8 *)(ulonglong)*(uint *)(param_1 + 2);
                    _Size = (undefined *)0x70646657;
                    _Dst_01 = (void *)ExAllocatePool2(0x40);
                    local_a0 = _Dst_01;
                    if (_Dst_01 == (void *)0x0) goto LAB_14000faf0;
                    _Src = (undefined8 *)(ulonglong)*(uint *)(param_1 + 2);
                    _Size = (undefined *)0x70646657;
                    local_98 = ExAllocatePool2(0x40);
                    if (local_98 == 0) goto LAB_14000faf0;
                    puVar3[0x33] = _Dst_01;
                    puVar3[0x34] = local_98;
                    memmove(_Dst_01,(void *)param_1[3],(ulonglong)*(uint *)(param_1 + 2));
                    _Size = (undefined *)(ulonglong)*(uint *)(param_1 + 2);
                    _Src = (undefined8 *)param_1[3];
                    memmove((void *)puVar3[0x34],_Src,(size_t)_Size);
                    *(undefined4 *)puVar3[0x34] = 5;
                    *(undefined4 *)(puVar3 + 0x32) = *(undefined4 *)(param_1 + 2);
                    puVar3[0x37] = *param_1;
                    puVar3[0x38] = param_1[1];
                    *(undefined1 *)((longlong)puVar3 + 0x71) = 1;
                    *(int *)(puVar3 + 9) = *(int *)(puVar3 + 9) + 1;
                    *param_2 = puVar3;
                  }
                  else {
                    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                        (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
                       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
                      _Src = (undefined8 *)0x55;
LAB_14000fae0:
                      _Size = &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids;
                      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(short)_Src,
                              &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids);
                    }
LAB_14000faf0:
                    iVar6 = -0x3ffffff3;
                  }
                  KeReleaseInStackQueuedSpinLock(&local_90);
                  uVar4 = Feature_VPN_BugFixes_25A__private_IsEnabledDeviceUsageNoInline();
                  if ((int)uVar4 != 0) {
                    WfpRioDecrementReferenceCount((longlong)puVar3,_Src,_Size);
                  }
                }
                KeReleaseInStackQueuedSpinLock(&local_78);
              }
              ExFreePoolWithTag(_Dst,0x70646657);
              if (_Dst_00 != (void *)0x0) {
                ExFreePoolWithTag(_Dst_00,0x70646657);
              }
              if (local_a8 != (void *)0x0) {
                ExFreePoolWithTag(local_a8,0x70646657);
              }
              if (iVar6 < 0) {
                if (local_a0 != (void *)0x0) {
                  ExFreePoolWithTag(local_a0,0x70646657);
                }
                if (local_98 != 0) {
                  ExFreePoolWithTag(local_98,0x70646657);
                }
              }
              goto LAB_14000fc24;
            }
          }
          goto LAB_14000fc18;
        }
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x53,
                &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids);
      }
      iVar6 = -0x3ffffff3;
      goto LAB_14000fc24;
    }
  }
LAB_14000fc18:
  iVar6 = -0x3ffffff3;
LAB_14000fc24:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5a,
             &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids,iVar6);
  }
  return iVar6;
}



===== WfpRioChannelDestroy @ 14000fc90 =====

void WfpRioChannelDestroy(longlong *param_1,undefined8 param_2,undefined *param_3)

{
  ulonglong uVar1;
  
  uVar1 = Feature_VPN_BugFixes_25A__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar1 == 0) {
    WfpRioChannelDestroy_old(param_1,param_2,param_3);
  }
  else {
    WfpRioChannelDestroy_2503((longlong)param_1,param_2,param_3);
  }
  return;
}



===== WfpRioFlushReceiveQueue @ 14000fcc0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WfpRioFlushReceiveQueue(longlong param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  uint *puVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  int iVar8;
  undefined1 local_68 [32];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)local_68;
  lVar4 = *(longlong *)(param_1 + 0x40);
  local_28 = 0;
  local_38 = 0;
  uStack_30 = 0;
  if ((lVar4 != 0) && (puVar5 = *(uint **)(lVar4 + 0x60), puVar5 != (uint *)0x0)) {
    *(undefined1 *)(puVar5 + 2) = 1;
    LOCK();
    UNLOCK();
    uVar1 = *puVar5;
    uVar2 = *(uint *)(lVar4 + 0x68);
    uVar3 = puVar5[1];
    if ((uVar1 < uVar2) && (uVar3 < uVar2)) {
      iVar8 = uVar2 + (uVar3 - uVar1);
      if (uVar1 <= uVar3) {
        iVar8 = uVar3 - uVar1;
      }
      if (iVar8 != 0) {
        while( true ) {
          uVar6 = wfp_rio_rq_deque(puVar5,*(uint *)(lVar4 + 0x68),&local_38);
          if ((int)uVar6 == 0) break;
          if ((int)uVar6 != 1) {
            if (*(int *)(lVar4 + 8) < 0) {
              return;
            }
            *(undefined4 *)(lVar4 + 8) = 0xc0000232;
            return;
          }
          uVar7 = WfpRioQueueReceiveCompletion
                            ((longlong *)(lVar4 + 0x50),(ulonglong)&local_38,param_2,0,0);
          if (((int)uVar7 < 0) && (-1 < *(int *)(lVar4 + 8))) {
            *(int *)(lVar4 + 8) = (int)uVar7;
          }
          iVar8 = iVar8 + -1;
          if (iVar8 == 0) {
            return;
          }
        }
      }
    }
  }
  return;
}



===== LwfvSwitchPause @ 14000fdc0 =====

uint LwfvSwitchPause(longlong param_1)

{
  int iVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x30);
  iVar1 = *(int *)(param_1 + 0x148);
  uVar3 = 4;
  if (iVar1 == 0) {
    uVar3 = 1;
  }
  *(undefined4 *)(param_1 + 0x3c) = uVar3;
  KeReleaseSpinLock(param_1 + 0x30,uVar2);
  return -(uint)(iVar1 != 0) & 0x103;
}



===== L2pComputevSwitchFlowHashSignature @ 14000fe34 =====

void L2pComputevSwitchFlowHashSignature
               (undefined2 param_1,byte *param_2,byte *param_3,undefined2 param_4,byte param_5,
               longlong *param_6)

{
  byte bVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  byte *pbVar5;
  longlong lVar6;
  undefined2 local_res8 [12];
  undefined2 local_res20 [4];
  
  local_res8[0] = param_1;
  lVar2 = 0;
  local_res20[0] = param_4;
  pbVar5 = (byte *)local_res8;
  lVar3 = 2;
  do {
    bVar1 = *pbVar5;
    pbVar5 = pbVar5 + 1;
    lVar2 = lVar2 * 0x25 + (ulonglong)bVar1;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  lVar3 = 6;
  lVar6 = 6;
  do {
    bVar1 = *param_2;
    param_2 = param_2 + 1;
    lVar2 = lVar2 * 0x25 + (ulonglong)bVar1;
    lVar6 = lVar6 + -1;
  } while (lVar6 != 0);
  do {
    bVar1 = *param_3;
    param_3 = param_3 + 1;
    lVar2 = lVar2 * 0x25 + (ulonglong)bVar1;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  pbVar5 = (byte *)local_res20;
  lVar3 = 2;
  do {
    lVar6 = lVar3;
    bVar1 = *pbVar5;
    pbVar5 = pbVar5 + 1;
    lVar2 = lVar2 * 0x25 + (ulonglong)bVar1;
    lVar3 = lVar6 + -1;
  } while (lVar3 != 0);
  pbVar5 = &param_5;
  uVar4 = (ulonglong)((int)lVar6 + 3);
  do {
    bVar1 = *pbVar5;
    pbVar5 = pbVar5 + 1;
    lVar2 = lVar2 * 0x25 + (ulonglong)bVar1;
    *param_6 = lVar2;
    uVar4 = uVar4 - 1;
  } while (uVar4 != 0);
  return;
}



===== vSwitchFlCleanup @ 14000fed8 =====

void vSwitchFlCleanup(void)

{
  int iVar1;
  
  vSwitchFlpDeleteAllCompartments();
  if (vSwitchFl4ProviderState != '\0') {
    iVar1 = NmrDeregisterProvider(DAT_14002c2b8);
    if (iVar1 == 0x103) {
      NmrWaitForProviderDeregisterComplete(DAT_14002c2b8);
    }
  }
  if (vSwitchFl6ProviderState != '\0') {
    iVar1 = NmrDeregisterProvider(DAT_14002c1b8);
    if (iVar1 == 0x103) {
      NmrWaitForProviderDeregisterComplete(DAT_14002c1b8);
    }
  }
  if (vSwitchFlGlobalState != 0) {
    NdisIfDeregisterProvider();
  }
  return;
}



===== vSwitchFlpDeleteAllCompartments @ 14000ff74 =====

void vSwitchFlpDeleteAllCompartments(void)

{
  code *pcVar1;
  undefined8 ***pppuVar2;
  undefined8 ***unaff_RBX;
  undefined8 ***pppuVar3;
  undefined1 *puVar4;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [24];
  undefined8 ***local_38;
  undefined8 ***local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_30 = &local_38;
  local_38 = &local_38;
  local_28 = 0;
  uStack_20 = 0;
  KeAcquireInStackQueuedSpinLock(&DAT_14002c548,&local_28);
  do {
  } while (DAT_14002c550 != 0);
  if ((undefined8 ****)DAT_14002c558 != &DAT_14002c558) {
    pppuVar3 = DAT_14002c558;
    do {
      pppuVar2 = pppuVar3;
      pppuVar3 = (undefined8 ***)*pppuVar2;
      if ((undefined8 ****)*local_30 != &local_38) {
        pcVar1 = (code *)swi(0x29);
        (*pcVar1)(3);
        puVar4 = auStack_50;
        goto LAB_14001001c;
      }
      pppuVar2[1] = local_30;
      *pppuVar2 = &local_38;
      *local_30 = pppuVar2;
      local_30 = pppuVar2;
    } while ((undefined8 ****)pppuVar3 != &DAT_14002c558);
  }
  KeReleaseInStackQueuedSpinLock(&local_28);
  puVar4 = auStack_58;
  pppuVar3 = local_38;
  while (unaff_RBX = pppuVar3, (undefined8 ****)pppuVar3 != &local_38) {
LAB_14001001c:
    pppuVar3 = (undefined8 ***)*unaff_RBX;
    *(undefined8 *)(puVar4 + -8) = 0x140010027;
    vSwitchFlpDeleteCompartment((longlong)unaff_RBX);
  }
  return;
}



===== LwfvSwitchIsOidAuthenticated @ 140010044 =====

ulonglong LwfvSwitchIsOidAuthenticated(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  
  uVar1 = *(uint *)(param_1 + 4);
  uVar2 = (ulonglong)uVar1;
  if (uVar1 == 1) {
    uVar1 = *(uint *)(param_1 + 0x20);
    uVar3 = (ulonglong)uVar1;
    if (uVar1 < 0x1027b) {
      if (((uVar1 == 0x1027a) || (uVar3 = (ulonglong)(uVar1 - 0x10271), uVar1 - 0x10271 == 0)) ||
         ((uVar3 = (ulonglong)(uVar1 - 0x10272), uVar1 - 0x10272 == 0 ||
          (uVar3 = (ulonglong)(uVar1 - 0x10273), uVar1 - 0x10273 == 0)))) goto LAB_1400100a4;
      uVar1 = uVar1 - 0x10278;
    }
    else {
      uVar3 = (ulonglong)(uVar1 - 0x1027b);
      if (((uVar1 - 0x1027b == 0) || (uVar3 = (ulonglong)(uVar1 - 0x1027c), uVar1 - 0x1027c == 0))
         || (uVar3 = (ulonglong)(uVar1 - 0x1027d), uVar1 - 0x1027d == 0)) goto LAB_1400100a4;
      uVar1 = uVar1 - 0x10291;
    }
    uVar3 = (ulonglong)uVar1;
    if ((uVar1 == 0) || (uVar2 = uVar3, uVar1 == 1)) {
LAB_1400100a4:
      return CONCAT71((int7)(uVar3 >> 8),1);
    }
  }
  else if ((uVar1 == 0xc) &&
          ((uVar3 = 0, *(int *)(param_1 + 0x20) == 0x10270 || (*(int *)(param_1 + 0x20) == 0x10290))
          )) goto LAB_1400100a4;
  return uVar2 & 0xffffffffffffff00;
}



===== L2FirevSwitchEvent @ 1400100b0 =====

undefined4 L2FirevSwitchEvent(longlong param_1,uint param_2)

{
  undefined1 uVar1;
  undefined4 uVar2;
  longlong lVar3;
  ulonglong local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  uVar2 = 0;
  uVar1 = KeAcquireSpinLockRaiseToDpc(&DAT_14002ce90);
  lVar3 = 0;
  if ((DAT_14002cf08 == 3) && (DAT_14002cf10 != 0)) {
    DAT_14002cf18 = 1;
    lVar3 = DAT_14002cf10;
  }
  KeReleaseSpinLock(&DAT_14002ce90,uVar1);
  if (lVar3 != 0) {
    uStack_20 = 0;
    local_28 = (ulonglong)param_2;
    local_18 = 0;
    uStack_10 = 0;
    if (param_2 != 0) {
      uStack_20 = *(undefined8 *)(param_1 + 0x78);
      if (param_2 == 1) {
        uStack_10 = *(undefined8 *)(param_1 + 0xb8);
        local_18 = (ulonglong)*(uint *)(param_1 + 0xc0);
      }
      else if (param_2 == 4) {
        uStack_10 = *(undefined8 *)(param_1 + 0xb8);
        local_18 = CONCAT44(*(undefined4 *)(param_1 + 0xc0),(uint)*(byte *)(param_1 + 0xb0));
      }
    }
    uVar2 = FwpmvSwitchEventFire0(DAT_14002cf10,&local_28);
    uVar1 = KeAcquireSpinLockRaiseToDpc(&DAT_14002ce90);
    DAT_14002cf18 = 0;
    KeReleaseSpinLock(&DAT_14002ce90,uVar1);
  }
  return uVar2;
}



===== WfpRioCleanupQueueContextCq @ 1400101e8 =====

void WfpRioCleanupQueueContextCq(longlong *param_1)

{
  undefined1 uVar1;
  int iVar2;
  
  if (*param_1 != 0) {
    uVar1 = KeAcquireSpinLockRaiseToDpc();
    iVar2 = 1 - (int)param_1[3];
    *(int *)(*param_1 + 0x20) = *(int *)(*param_1 + 0x20) + iVar2;
    KeReleaseSpinLock(*param_1,CONCAT31((int3)((uint)iVar2 >> 8),uVar1));
    WfpRioDereferenceCqInline(*param_1);
    *param_1 = 0;
  }
  return;
}



===== WfpRioTrackIdle @ 140010240 =====

void WfpRioTrackIdle(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  if ((*(uint *)(param_1 + 0xb8) & 2) != 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      param_2 = 0x20;
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,param_3,param_1);
    }
    WfpSetActivityTimerDpc(param_1,param_2,param_3);
  }
  return;
}



===== WfpReportSysErrorAsNtStatus @ 14001029c =====

longlong WfpReportSysErrorAsNtStatus(undefined8 param_1,char *param_2,int param_3)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) != 0)) {
    WPP_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_c15558396cc63da9014e9889efdb8f36_Traceguids,param_2,(char)param_3);
  }
  return (longlong)param_3;
}



===== vSwitchFlpRegisterNdisIfProvider @ 1400102f4 =====

void vSwitchFlpRegisterNdisIfProvider(void)

{
  undefined4 local_38;
  undefined4 local_34;
  code *local_30;
  code *local_28;
  undefined8 local_20;
  undefined8 uStack_18;
  
  local_34 = 0;
  local_30 = vSwitchFlSetInterface;
  local_38 = 0x280180;
  local_28 = vSwitchFlSetInterface;
  local_20 = 0;
  uStack_18 = 0;
  NdisIfRegisterProvider(&local_38,0,&vSwitchFlGlobalState);
  return;
}



===== __report_gsfailure @ 140010360 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 14001036d =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014001036d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== L2802_3ParseMacHeader_25D @ 140010380 =====

undefined8
L2802_3ParseMacHeader_25D
          (longlong param_1,longlong *param_2,longlong *param_3,ushort *param_4,ushort *param_5,
          undefined4 *param_6,undefined1 *param_7,uint *param_8)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  ushort uVar5;
  
  uVar4 = 0xe;
  if (param_7 != (undefined1 *)0x0) {
    *param_7 = 0;
  }
  lVar2 = NdisGetDataBuffer(*(undefined8 *)(param_1 + 8),0xe,0,1,0);
  if (lVar2 == 0) {
    uVar3 = 0xc000000d;
  }
  else {
    if ((param_4 != (ushort *)0x0) || (param_6 != (undefined4 *)0x0)) {
      uVar5 = *(ushort *)(lVar2 + 0xc) >> 8 | *(ushort *)(lVar2 + 0xc) << 8;
      uVar4 = 0xe;
      if (uVar5 < 0x600) {
        uVar4 = 0x16;
        if ((*(int3 *)(lVar2 + 0xe) == 0x3aaaa) &&
           (CONCAT21(CONCAT11(*(undefined1 *)(lVar2 + 0x11),*(undefined1 *)(lVar2 + 0x12)),
                     *(undefined1 *)(lVar2 + 0x13)) == 0)) {
          uVar5 = *(ushort *)(lVar2 + 0x14) >> 8 | *(ushort *)(lVar2 + 0x14) << 8;
        }
        else if (param_7 != (undefined1 *)0x0) {
          *param_7 = 1;
        }
      }
      if (param_4 != (ushort *)0x0) {
        *param_4 = uVar5;
      }
    }
    if (param_2 != (longlong *)0x0) {
      *param_2 = lVar2;
    }
    if (param_3 != (longlong *)0x0) {
      *param_3 = lVar2 + 6;
    }
    if (param_6 != (undefined4 *)0x0) {
      *param_6 = uVar4;
    }
    if (param_5 != (ushort *)0x0) {
      uVar1 = *(ulonglong *)(param_1 + 0xb0);
      *param_5 = ((ushort)(uVar1 >> 3) & 1 | (short)uVar1 * 2) << 0xc |
                 (ushort)((uint)uVar1 >> 4) & 0xfff;
    }
    if (param_8 != (uint *)0x0) {
      *param_8 = *(uint *)(param_1 + 0x130) & 0xffffff;
    }
    uVar3 = 0;
  }
  return uVar3;
}



===== L2DelayExecution @ 140010508 =====

void L2DelayExecution(longlong param_1)

{
  longlong local_res8 [4];
  
  local_res8[0] = param_1 * -10000;
  KeDelayExecutionThread(0,0,local_res8);
  return;
}



===== L2DeterminevSwitchVLanTenantId @ 14001053c =====

void L2DeterminevSwitchVLanTenantId
               (ushort param_1,uint param_2,longlong param_3,uint *param_4,undefined1 *param_5)

{
  *param_4 = 0;
  *param_5 = 0;
  if ((param_3 == 0) || (*(int *)(param_3 + 0x434) == 1)) {
    if (param_1 != 0) {
      *param_4 = (uint)param_1;
      return;
    }
    if (param_2 != 0) {
      *param_4 = param_2;
      *param_5 = 1;
    }
  }
  else if (*(uint *)(param_3 + 0x46c) != 0) {
    *param_4 = *(uint *)(param_3 + 0x46c);
    *param_5 = *(undefined1 *)(param_3 + 0x470);
    return;
  }
  return;
}



===== L2GetvSwitchPortUnsafe @ 140010594 =====

undefined8 L2GetvSwitchPortUnsafe(longlong param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return *(undefined8 *)
          (*(longlong *)(*(longlong *)(param_1 + 0x80) + (ulonglong)(param_2 - 1U >> 8) * 8) +
          (ulonglong)(param_2 - 1U & 0xff) * 8);
}



===== L2IsMacLayersEmpty @ 1400105c4 =====

bool L2IsMacLayersEmpty(void)

{
  int iVar1;
  
  iVar1 = KfdIsLayerEmpty(0x38);
  if ((((iVar1 == 0) || (iVar1 = KfdIsLayerEmpty(0x39), iVar1 == 0)) ||
      (iVar1 = KfdIsLayerEmpty(0x3a), iVar1 == 0)) ||
     ((iVar1 = KfdIsLayerEmpty(0x3b), iVar1 == 0 || (iVar1 = KfdIsLayerEmpty(0x50), iVar1 == 0)))) {
    return false;
  }
  iVar1 = KfdIsLayerEmpty(0x51);
  return iVar1 != 0;
}



===== L2IsvSwitchLayersEmpty @ 140010658 =====

bool L2IsvSwitchLayersEmpty(void)

{
  int iVar1;
  
  iVar1 = KfdIsLayerEmpty(0x48);
  if ((((iVar1 == 0) || (iVar1 = KfdIsLayerEmpty(0x49), iVar1 == 0)) ||
      (iVar1 = KfdIsLayerEmpty(0x4a), iVar1 == 0)) ||
     ((iVar1 = KfdIsLayerEmpty(0x4b), iVar1 == 0 || (iVar1 = KfdIsLayerEmpty(0x4c), iVar1 == 0)))) {
    return false;
  }
  iVar1 = KfdIsLayerEmpty(0x4d);
  return iVar1 != 0;
}



===== L2KfdLogVSwitchLayerEmptyAtCompartmentCreationTelemetry @ 1400106ec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void L2KfdLogVSwitchLayerEmptyAtCompartmentCreationTelemetry
               (byte param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  ulonglong uVar2;
  undefined1 auStackY_78 [32];
  undefined4 local_48 [2];
  undefined8 local_40 [4];
  undefined4 *local_20;
  undefined4 local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  uVar2 = (ulonglong)param_1;
  if ((DAT_14002c2e0 != 0) && (5 < DAT_14002c2e0)) {
    cVar1 = _tlgKeywordOn(0x14002c2e0,0x200000000000);
    if (cVar1 != '\0') {
      local_14 = 0;
      local_20 = local_48;
      local_48[0] = (undefined4)uVar2;
      local_18 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002c2e0,&DAT_140028f39,param_3,uVar2,3,local_40);
    }
  }
  return;
}



===== L2KfdUpdateNotifyComplete @ 14001078c =====

void L2KfdUpdateNotifyComplete(longlong param_1)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x30);
  KeClearEvent(param_1 + 0x128);
  KeReleaseSpinLock(param_1 + 0x30,uVar1);
  return;
}



===== L2RestartCompleteWorkRoutine @ 1400107f0 =====

void L2RestartCompleteWorkRoutine(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  longlong local_res10;
  
  uVar3 = *(undefined4 *)(param_2 + 0x3d8);
  *(undefined4 *)(param_2 + 0x3d8) = 0;
  local_res10 = param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
             &WPP_55b06a2d6529343c1d592bc39396dd87_Traceguids,uVar3);
  }
  NdisFRestartComplete(*(undefined8 *)(param_2 + 0x48),uVar3);
  LOCK();
  piVar1 = (int *)(param_2 + 0x14c);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -2;
  UNLOCK();
  if (iVar2 == 3) {
    L2LwfFree(&local_res10);
  }
  IoFreeWorkItem(param_3);
  return;
}



===== L2vSwitchCopyVmSwitchNblInfo @ 1400108b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int L2vSwitchCopyVmSwitchNblInfo(longlong param_1,longlong param_2,longlong param_3)

{
  int iVar1;
  longlong lVar2;
  undefined8 local_res8;
  
  local_res8 = 0;
  lVar2 = param_2;
  if (*(longlong *)(param_3 + 0x120) == 0) {
    param_3 = vSwitchFindOriginalvmSwitchNetBufferList(param_3);
  }
  *(undefined8 *)(lVar2 + 0x78) = *(undefined8 *)(param_1 + 0x80);
  iVar1 = (*DAT_14002c588)(*(undefined8 *)(param_1 + 0x78));
  if (iVar1 == 0) {
    iVar1 = (*DAT_14002c5c0)(*(undefined8 *)(param_1 + 0x78),param_2,param_3,
                             *(int *)(param_1 + 0xc) == 2);
    if (iVar1 == 0) {
      (*DAT_14002c5b0)(*(undefined8 *)(param_1 + 0x78),param_2,&local_res8);
      if (*(int *)(param_1 + 0xc) == 2) {
        *(undefined8 *)(param_1 + 0x38) = local_res8;
      }
    }
    else {
      (*DAT_14002c590)();
    }
  }
  return iVar1;
}



===== L2vSwitchFreeVmSwitchNblInfo @ 140010990 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void L2vSwitchFreeVmSwitchNblInfo(longlong param_1)

{
  (*DAT_14002c590)(*(undefined8 *)(param_1 + 0x78));
  return;
}



===== L2vSwitchGetDestinationArray @ 1400109b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 L2vSwitchGetDestinationArray(longlong param_1,undefined8 param_2)

{
  undefined8 local_res8 [4];
  
  local_res8[0] = 0;
  (*DAT_14002c5b0)(*(undefined8 *)(param_1 + 0x78),param_2,local_res8);
  return local_res8[0];
}



===== L2vSwitchGetDestinationInterface @ 1400109e0 =====

longlong L2vSwitchGetDestinationInterface(longlong param_1,int param_2,ushort param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  
  uVar2 = (ulonglong)param_3;
  lVar1 = L2GetvSwitchPortUnsafe(param_1,param_2);
  return uVar2 * 0x8b8 + *(longlong *)(lVar1 + 0x448);
}



===== L2vSwitchValidatePortNicAndSetSource @ 140010a0c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
L2vSwitchValidatePortNicAndSetSource
          (uint param_1,ulonglong param_2,undefined8 param_3,longlong param_4)

{
  undefined1 uVar1;
  undefined4 uVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar3 = 0;
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_4 + 0x30);
  if (param_1 <= *(uint *)(param_4 + 0xd8)) {
    lVar3 = L2GetvSwitchPortUnsafe(param_4,param_1);
  }
  if (param_1 == 0) {
    if (lVar3 != 0) goto LAB_140010a74;
LAB_140010a9b:
    uVar2 = (*DAT_14002c598)(*(undefined8 *)(param_4 + 0xa0),param_3,param_1,param_2 & 0xffff);
  }
  else {
    if (lVar3 != 0) {
LAB_140010a74:
      lVar3 = *(longlong *)(lVar3 + 0x448);
      if (((lVar3 != 0) &&
          (lVar4 = (param_2 & 0xffff) * 0x8b8, *(char *)(lVar4 + 0x8b1 + lVar3) != '\0')) &&
         (*(char *)(lVar4 + 0x8b0 + lVar3) == '\0')) goto LAB_140010a9b;
    }
    uVar2 = 0xc000000d;
  }
  KeReleaseSpinLock(param_4 + 0x30,uVar1);
  return uVar2;
}



===== WPP_SF_D @ 140010af8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_D(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== vSwitchFindOriginalvmSwitchNetBufferList @ 140010b3c =====

void vSwitchFindOriginalvmSwitchNetBufferList(longlong param_1)

{
  longlong lVar1;
  
  for (lVar1 = *(longlong *)(param_1 + 0x18); (lVar1 != 0 && (*(longlong *)(lVar1 + 0x120) == 0));
      lVar1 = *(longlong *)(lVar1 + 0x18)) {
  }
  return;
}



===== vSwitchReportPacketDrop @ 140010b60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void vSwitchReportPacketDrop
               (longlong param_1,int param_2,int param_3,undefined8 param_4,longlong param_5,
               char param_6,longlong param_7)

{
  longlong lVar1;
  undefined4 uVar2;
  undefined *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  puVar3 = &WFP_VSWITCH_FILTER_REASON_POLICY;
  if (param_3 != -0x3fffffde) {
    puVar3 = &WFP_VSWITCH_FILTER_REASON_RESOURCES;
  }
  uVar2 = 0;
  if (param_2 == 1) {
    if (param_5 != 0) {
      uVar2 = *(undefined4 *)(param_5 + 0x410);
    }
    (*DAT_14002c5e8)(param_4,&WFP_LWF_VSWITCH_UNIQUE_NAME,&WFP_LWF_VSWITCH_FRIENDLY_NAME,uVar2,1,1,
                     param_1,puVar3);
  }
  else {
    param_7 = 0;
    if (*(longlong *)(param_1 + 0x120) != 0) {
      (*DAT_14002c5b0)(param_4,param_1,&param_7);
      if ((param_7 != 0) && (uVar4 = 0, lVar1 = param_7, *(int *)(param_7 + 0xc) != 0)) {
        do {
          puVar5 = (undefined4 *)
                   ((ulonglong)(uVar4 * *(int *)(lVar1 + 4)) + *(longlong *)(lVar1 + 0x10));
          if (((*(byte *)((longlong)puVar5 + 6) & 1) != 0) || (param_6 == '\0')) {
            (*DAT_14002c5e8)(param_4,&WFP_LWF_VSWITCH_UNIQUE_NAME,&WFP_LWF_VSWITCH_FRIENDLY_NAME,
                             *puVar5,0,1,param_1,puVar3);
            lVar1 = param_7;
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < *(uint *)(lVar1 + 0xc));
      }
    }
  }
  return;
}



===== LwfUpperKfdCommitNotify @ 140010cb8 =====

uint LwfUpperKfdCommitNotify(longlong param_1)

{
  longlong lVar1;
  bool bVar2;
  undefined1 uVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  lVar1 = param_1 + 0x30;
  uVar7 = 0;
  bVar2 = false;
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
  uVar6 = *(uint *)(param_1 + 0x118);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
               &WPP_2142e384b80c35b5005992d824702965_Traceguids,uVar6,
               (char)*(undefined4 *)(param_1 + 0x3c),*(undefined1 *)(param_1 + 0x40));
  }
  cVar4 = L2IsClassifyNeededForInterface(0x39,*(undefined8 *)(param_1 + 0x50),0);
  if ((cVar4 == '\0') && ((*(uint *)(param_1 + 0x118) & 1) != 0)) {
    uVar6 = uVar6 & 0xfffffffe;
  }
  cVar4 = L2IsClassifyNeededForInterface(0x38,*(undefined8 *)(param_1 + 0x50),0);
  if ((cVar4 == '\0') && ((*(uint *)(param_1 + 0x118) & 2) != 0)) {
    uVar6 = uVar6 & 0xfffffffd;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
             &WPP_2142e384b80c35b5005992d824702965_Traceguids,uVar6);
  }
  if (uVar6 != *(uint *)(param_1 + 0x118)) {
    *(uint *)(param_1 + 0x11c) = uVar6;
    if (*(int *)(param_1 + 0x3c) == 1) {
      if (*(char *)(param_1 + 0x40) == '\0') {
        *(undefined1 *)(param_1 + 0x120) = 1;
        KeReleaseSpinLock(lVar1,uVar3);
        return 0x103;
      }
    }
    else if (2 < *(int *)(param_1 + 0x3c) - 2U) goto LAB_140010e00;
    bVar2 = true;
    *(undefined1 *)(param_1 + 0x120) = 1;
  }
LAB_140010e00:
  KeReleaseSpinLock(lVar1,uVar3);
  if (bVar2) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
              &WPP_2142e384b80c35b5005992d824702965_Traceguids);
    }
    iVar5 = NdisFRestartFilter();
    uVar7 = ~-(uint)(iVar5 != 0) & 0x103;
  }
  return uVar7;
}



===== WPP_SF_ @ 140010e8c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,0);
  return;
}



===== WPP_SF_DD @ 140010eb8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,0);
  return;
}



===== WPP_SF_DDD @ 140010f08 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DDD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,&param_6,4,0);
  return;
}



===== LwfLowerCacheClassifyCache @ 140010f64 =====

void LwfLowerCacheClassifyCache(longlong param_1,longlong param_2,int param_3,uint param_4)

{
  undefined1 uVar1;
  longlong *plVar2;
  longlong local_res8;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_2 + 0x30);
  if (*(int *)(param_2 + 0x5c) == 0x10) {
    plVar2 = (longlong *)(param_2 + ((longlong)param_3 + ((ulonglong)param_4 * 3 + 0x16) * 2) * 8);
  }
  else {
    plVar2 = (longlong *)(param_2 + 0x150 + (longlong)param_3 * 8);
  }
  local_res8 = *plVar2;
  *plVar2 = param_1;
  L2PurgeLayerClassifyCache(&local_res8);
  KeReleaseSpinLock(param_2 + 0x30,uVar1);
  return;
}



===== LwfLowerCancelOidRequest @ 140011010 =====

void LwfLowerCancelOidRequest(longlong param_1,longlong param_2)

{
  undefined1 uVar1;
  longlong lVar2;
  
  lVar2 = 0;
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x30);
  if ((*(longlong *)(param_1 + 0x140) != 0) &&
     (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x140) + 0xd8),
     *(longlong *)(lVar2 + 0x10) != param_2)) {
    lVar2 = 0;
  }
  KeReleaseSpinLock(param_1 + 0x30,uVar1);
  if (lVar2 != 0) {
    NdisFCancelOidRequest(*(undefined8 *)(param_1 + 0x48),param_2);
  }
  return;
}



===== LwfLowerIsSupportedMediaType @ 1400110ac =====

bool LwfLowerIsSupportedMediaType(uint param_1)

{
  if ((param_1 < 0x11) && ((0x10201U >> (param_1 & 0x1f) & 1) != 0)) {
    return true;
  }
  return param_1 == 3;
}



===== LwfLowerKfdCommitNotify @ 1400110d0 =====

uint LwfLowerKfdCommitNotify(longlong param_1)

{
  longlong lVar1;
  bool bVar2;
  bool bVar3;
  undefined1 uVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  uVar8 = 0;
  bVar2 = false;
  bVar3 = LwfLowerIsSupportedMediaType(*(uint *)(param_1 + 0x5c));
  if (!bVar3) {
    return 0;
  }
  lVar1 = param_1 + 0x30;
  uVar4 = KeAcquireSpinLockRaiseToDpc(lVar1);
  uVar7 = *(uint *)(param_1 + 0x118);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
               &WPP_8d78ca0d606e3bf520aeb7d0d517a1c9_Traceguids,uVar7,
               (char)*(undefined4 *)(param_1 + 0x3c),*(undefined1 *)(param_1 + 0x40));
  }
  cVar5 = L2IsClassifyNeededForInterface(0x3b,*(undefined8 *)(param_1 + 0x50),0);
  if ((cVar5 == '\0') && ((*(uint *)(param_1 + 0x118) & 1) != 0)) {
    uVar7 = uVar7 & 0xfffffffe;
  }
  cVar5 = L2IsClassifyNeededForInterface(0x3a,*(undefined8 *)(param_1 + 0x50),0);
  if ((cVar5 == '\0') && ((*(uint *)(param_1 + 0x118) & 2) != 0)) {
    uVar7 = uVar7 & 0xfffffffd;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
             &WPP_8d78ca0d606e3bf520aeb7d0d517a1c9_Traceguids,uVar7);
  }
  if (uVar7 != *(uint *)(param_1 + 0x118)) {
    *(uint *)(param_1 + 0x11c) = uVar7;
    if (*(int *)(param_1 + 0x3c) == 1) {
      if (*(char *)(param_1 + 0x40) == '\0') {
        *(undefined1 *)(param_1 + 0x120) = 1;
        KeReleaseSpinLock(lVar1,uVar4);
        return 0x103;
      }
    }
    else if (2 < *(int *)(param_1 + 0x3c) - 2U) goto LAB_140011228;
    bVar2 = true;
    *(undefined1 *)(param_1 + 0x120) = 1;
  }
LAB_140011228:
  KeReleaseSpinLock(lVar1,uVar4);
  if (bVar2) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
              &WPP_8d78ca0d606e3bf520aeb7d0d517a1c9_Traceguids);
    }
    iVar6 = NdisFRestartFilter();
    uVar8 = ~-(uint)(iVar6 != 0) & 0x103;
  }
  return uVar8;
}



===== LwfLowerKfdUpdateNotify @ 1400112b4 =====

int LwfLowerKfdUpdateNotify(longlong param_1)

{
  longlong lVar1;
  bool bVar2;
  undefined1 uVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  
  iVar5 = 0;
  bVar2 = LwfLowerIsSupportedMediaType(*(uint *)(param_1 + 0x5c));
  if (!bVar2) {
    return 0;
  }
  lVar1 = param_1 + 0x30;
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
               &WPP_8d78ca0d606e3bf520aeb7d0d517a1c9_Traceguids,*(undefined4 *)(param_1 + 0x118),
               (char)*(undefined4 *)(param_1 + 0x3c),*(undefined1 *)(param_1 + 0x40));
  }
  uVar6 = *(uint *)(param_1 + 0x118);
  if (uVar6 != 3) {
    cVar4 = L2IsClassifyNeededForInterface(0x3b,*(undefined8 *)(param_1 + 0x50),0x20);
    if ((cVar4 != '\0') && ((*(uint *)(param_1 + 0x118) & 1) == 0)) {
      uVar6 = uVar6 | 1;
    }
    cVar4 = L2IsClassifyNeededForInterface(0x3a,*(undefined8 *)(param_1 + 0x50),0x20);
    if ((cVar4 != '\0') && ((*(uint *)(param_1 + 0x118) & 2) == 0)) {
      uVar6 = uVar6 | 2;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
               &WPP_8d78ca0d606e3bf520aeb7d0d517a1c9_Traceguids,uVar6);
    }
    if (uVar6 != *(uint *)(param_1 + 0x118)) {
      *(uint *)(param_1 + 0x11c) = uVar6;
      if (*(int *)(param_1 + 0x3c) == 1) {
        if (*(char *)(param_1 + 0x40) != '\0') {
LAB_140011423:
          *(undefined1 *)(param_1 + 0x120) = 1;
          KeReleaseSpinLock(lVar1,uVar3);
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                    &WPP_8d78ca0d606e3bf520aeb7d0d517a1c9_Traceguids);
          }
          iVar5 = NdisFRestartFilter(*(undefined8 *)(param_1 + 0x48));
          if (iVar5 == 0) {
            return 0x103;
          }
          if (((iVar5 == 0x103) || (iVar5 == -0x7ffffffb)) ||
             ((iVar5 == -0x3fffffff || ((iVar5 == -0x3fffff66 || (iVar5 == -0x3fffff45)))))) {
            return iVar5;
          }
          if (iVar5 == -0x3ffeffea) {
            return -0x3fffffdd;
          }
          if (iVar5 == -0x3ffeffec) {
            return -0x3ffffdfa;
          }
          if (iVar5 == -0x3ffeffeb) {
            return -0x3ffffff3;
          }
          return -0x3fffffff;
        }
        *(undefined1 *)(param_1 + 0x120) = 1;
        iVar5 = 0x103;
      }
      else if (*(int *)(param_1 + 0x3c) - 2U < 3) goto LAB_140011423;
    }
  }
  KeReleaseSpinLock(lVar1,uVar3);
  return iVar5;
}



===== LwfLowerPurgeClassifyCache @ 1400114ec =====

void LwfLowerPurgeClassifyCache(longlong param_1,int param_2,uint param_3)

{
  longlong *plVar1;
  undefined1 uVar2;
  longlong lVar3;
  longlong local_res8;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x30);
  if (*(int *)(param_1 + 0x5c) == 0x10) {
    lVar3 = (longlong)param_2 + ((ulonglong)param_3 * 3 + 0x16) * 2;
  }
  else {
    lVar3 = (longlong)param_2 + 0x2a;
  }
  plVar1 = (longlong *)(param_1 + lVar3 * 8);
  local_res8 = *plVar1;
  *plVar1 = 0;
  L2PurgeLayerClassifyCache(&local_res8);
  KeReleaseSpinLock(param_1 + 0x30,uVar2);
  return;
}



===== Feature_VPN_BugFixes_25A__private_IsEnabledDeviceUsageNoInline @ 140011584 =====

ulonglong Feature_VPN_BugFixes_25A__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_VPN_BugFixes_25A__private_featureState;
  if ((Feature_VPN_BugFixes_25A__private_featureState & 0x10) == 0) {
    uVar1 = Feature_VPN_BugFixes_25A__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_VPN_BugFixes_25A__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_VPN_BugFixes_25A__private_IsEnabledFallback @ 1400115bc =====

void Feature_VPN_BugFixes_25A__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_VPN_BugFixes_25A__private_descriptor);
  return;
}



===== L2DeregisterLayerEventNotify @ 1400115d8 =====

void L2DeregisterLayerEventNotify(void)

{
  int iVar1;
  
  while( true ) {
    iVar1 = KfdDeregisterLayerEventNotify(3,L2KfdLayerEventNotifyFn);
    if (-1 < iVar1) break;
    L2DelayExecution(100);
  }
  return;
}



===== L2KfdLayerProcessFiltersAddRefCompartments @ 140011610 =====

void L2KfdLayerProcessFiltersAddRefCompartments(undefined8 param_1,short *param_2)

{
  short sVar1;
  bool bVar2;
  bool bVar3;
  undefined1 uVar4;
  char cVar5;
  int iVar6;
  longlong lVar7;
  ushort *puVar8;
  undefined8 uVar9;
  ushort uVar10;
  uint *puVar11;
  undefined8 uVar12;
  uint uVar13;
  uint uVar14;
  uint *puVar15;
  ulonglong uVar16;
  uint *puVar17;
  uint local_res18;
  undefined2 local_58;
  undefined2 local_56;
  undefined4 local_54;
  undefined8 local_50;
  undefined2 local_48;
  undefined2 local_46;
  undefined4 local_44;
  longlong local_40;
  
  bVar3 = false;
  local_res18 = 0;
  do {
    puVar11 = (uint *)0x0;
    uVar12 = 5;
    if (*(uint *)(param_2 + 8) <= local_res18) {
LAB_140011844:
      KeSetEvent(param_2 + 0xc,0,0);
      return;
    }
    sVar1 = *param_2;
    uVar10 = 0;
    if (((((sVar1 == 0x48) || (sVar1 == 0x49)) || (sVar1 == 0x4a)) ||
        ((sVar1 == 0x4b || (sVar1 == 0x4c)))) || (sVar1 == 0x4d)) {
      uVar9 = 7;
    }
    else {
      uVar9 = 0xffff;
      if (((sVar1 != 0x48) && (sVar1 != 0x49)) &&
         ((sVar1 != 0x4a && (((sVar1 != 0x4b && (sVar1 != 0x4c)) && (sVar1 != 0x4d)))))) {
        uVar9 = 0xffffffff;
        uVar12 = 0xffffffff;
      }
    }
    lVar7 = *(longlong *)(*(longlong *)(param_2 + 4) + (ulonglong)local_res18 * 8);
    uVar14 = *(uint *)(lVar7 + 0x1c);
    if (uVar14 != 0) {
      puVar8 = *(ushort **)(lVar7 + 0x20);
      puVar15 = puVar11;
      puVar17 = puVar11;
      do {
        if ((int)(short)uVar9 == (uint)*puVar8) {
          puVar17 = *(uint **)(puVar8 + 8);
        }
        if ((uint)uVar12 == (uint)*puVar8) {
          uVar10 = puVar8[8];
        }
        if ((uVar10 != 0) && (puVar17 != (uint *)0x0)) goto LAB_140011704;
        uVar13 = (int)puVar15 + 1;
        puVar15 = (uint *)(ulonglong)uVar13;
        puVar8 = puVar8 + 0xc;
      } while (uVar13 < uVar14);
      if (puVar17 != (uint *)0x0) {
LAB_140011704:
        bVar2 = false;
        uVar4 = KeAcquireSpinLockRaiseToDpc(&DAT_14002ce90);
        for (puVar15 = DAT_14002cec8; (uint **)puVar15 != &DAT_14002cec8;
            puVar15 = *(uint **)puVar15) {
          lVar7 = *(longlong *)(puVar15 + 0x1c);
          uVar12 = CONCAT71((int7)((ulonglong)uVar12 >> 8),1);
          local_44 = 0;
          local_40 = lVar7 + 10;
          local_48 = *(undefined2 *)(lVar7 + 8);
          local_46 = *(undefined2 *)(lVar7 + 8);
          local_54 = 0;
          local_50 = *(undefined8 *)(puVar17 + 2);
          local_58 = (undefined2)*puVar17;
          local_56 = local_58;
          cVar5 = RtlEqualUnicodeString(&local_48,&local_58);
          puVar11 = puVar15;
          if (cVar5 != '\0') {
            RoReferenceEx(puVar15 + 0x53);
            bVar2 = true;
            break;
          }
        }
        KeReleaseSpinLock(&DAT_14002ce90,uVar4);
        if (bVar2) {
          if (uVar10 == 0) {
            bVar3 = true;
LAB_140011808:
            iVar6 = vSwitchFlpRefOrCreateCompartment(puVar17,(ulonglong)uVar10,uVar12);
            if (iVar6 < 0) {
              LOCK();
              puVar11[0x53] = puVar11[0x53] - 2;
              UNLOCK();
              goto LAB_140011844;
            }
          }
          else {
            uVar16 = (ulonglong)puVar11[0x3e];
            for (uVar14 = 1; uVar14 <= (uint)uVar16; uVar14 = uVar14 + 1) {
              lVar7 = L2GetvSwitchPortUnsafe((longlong)puVar11,uVar14);
              if ((lVar7 != 0) && (*(uint *)(lVar7 + 0x46c) == (uint)uVar10)) {
                bVar3 = true;
                break;
              }
            }
            if (bVar3) goto LAB_140011808;
          }
          LOCK();
          puVar11[0x53] = puVar11[0x53] - 2;
          UNLOCK();
        }
      }
    }
    local_res18 = local_res18 + 1;
  } while( true );
}



===== L2KfdLayerProcessFiltersAddRefCompartmentsSync @ 140011878 =====

undefined4
L2KfdLayerProcessFiltersAddRefCompartmentsSync
          (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined2 *puVar1;
  undefined4 uVar2;
  longlong lVar3;
  undefined2 *local_res20;
  
  local_res20 = (undefined2 *)0x0;
  WfpPoolAllocNonPaged(param_1,param_2,(longlong *)&local_res20);
  puVar1 = local_res20;
  *(int *)(local_res20 + 8) = (int)param_2;
  *(undefined8 *)(local_res20 + 4) = param_3;
  *local_res20 = (short)param_1;
  lVar3 = IoAllocateWorkItem(DAT_14002ce88);
  if (lVar3 == 0) {
    uVar2 = 0xc0000017;
  }
  else {
    KeInitializeEvent(puVar1 + 0xc,0,0);
    IoQueueWorkItem(lVar3,L2KfdLayerProcessFiltersAddRefCompartments,1,puVar1);
    uVar2 = KeWaitForSingleObject(puVar1 + 0xc,0,0,0,0);
  }
  WfpPoolFree((longlong *)&local_res20);
  if (lVar3 != 0) {
    IoFreeWorkItem(lVar3);
  }
  return uVar2;
}



===== WfpL2DispatchClose @ 140011970 =====

undefined8 WfpL2DispatchClose(longlong param_1,longlong param_2,undefined *param_3)

{
  undefined8 uVar1;
  
  if (param_1 == DAT_14002cf80) {
    uVar1 = WfpRioCloseDispatchHandler(param_1,param_2,param_3);
  }
  else if (param_1 == DAT_14002cf88) {
    uVar1 = WfpRioDPConfigCloseDispatchHandler(param_1,param_2);
  }
  else {
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
    IofCompleteRequest(param_2,0);
    uVar1 = 0xc000000d;
  }
  return uVar1;
}



===== WfpL2DispatchDeviceControl @ 1400119d0 =====

undefined4 WfpL2DispatchDeviceControl(longlong param_1,longlong param_2)

{
  undefined4 uVar1;
  
  if (param_1 == DAT_14002cf80) {
    *(undefined4 *)(param_2 + 0x30) = 0;
    *(undefined8 *)(param_2 + 0x38) = 0;
    IofCompleteRequest(param_2,0);
    uVar1 = 0;
  }
  else if (param_1 == DAT_14002cf88) {
    uVar1 = WfpRioDPConfigDispatch(param_1,param_2);
  }
  else {
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
    IofCompleteRequest(param_2,0);
    uVar1 = 0xc000000d;
  }
  return uVar1;
}



===== WfpL2DispatchInternalDeviceControl @ 140011a40 =====

undefined8 WfpL2DispatchInternalDeviceControl(longlong param_1,longlong param_2)

{
  undefined8 uVar1;
  
  if ((param_1 == DAT_14002cf80) || (param_1 == DAT_14002cf88)) {
    *(undefined4 *)(param_2 + 0x30) = 0;
    uVar1 = 0;
  }
  else {
    uVar1 = 0xc000000d;
    *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return uVar1;
}



===== WppClassicProviderCallback @ 140011a90 =====

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



===== _tlgDefineProvider_annotation__Tlgmtakm_hTelemetryAssertProv @ 140011ac4 =====

void _tlgDefineProvider_annotation__Tlgmtakm_hTelemetryAssertProv(void)

{
  return;
}



===== vSwitchCheckAndRevokeAssignedVfs @ 140011ad0 =====

ulonglong vSwitchCheckAndRevokeAssignedVfs(ushort param_1)

{
  undefined8 ****ppppuVar1;
  int *piVar2;
  int iVar3;
  code *pcVar4;
  undefined1 uVar5;
  uint uVar6;
  longlong lVar7;
  ulonglong uVar8;
  longlong lVar9;
  undefined8 ****ppppuVar10;
  undefined1 *puVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  undefined8 ****local_res10;
  undefined1 auStack_88 [8];
  undefined1 auStack_80 [56];
  undefined8 ****local_48;
  undefined8 ****local_40;
  undefined8 ****local_38;
  undefined8 ****local_30;
  
  local_40 = &local_48;
  local_48 = &local_48;
  uVar12 = 0;
  lVar7 = 0;
  local_30 = &local_38;
  lVar9 = 0;
  uVar13 = 0;
  local_38 = &local_38;
  uVar5 = KeAcquireSpinLockRaiseToDpc(&DAT_14002ce90);
  if (DAT_14002ced8 == 0) {
LAB_140011b6a:
    for (ppppuVar10 = DAT_14002cec8; (undefined8 *****)ppppuVar10 != &DAT_14002cec8;
        ppppuVar10 = (undefined8 ****)*ppppuVar10) {
      uVar8 = LwfvSwitchCheckAndRevokeAssignedVfs((longlong)ppppuVar10,param_1,(longlong)&local_38);
      uVar12 = uVar8 & 0xffffffff;
      if ((int)uVar8 == 0x103) {
        *(undefined8 *****)(lVar7 + uVar13 * 8) = ppppuVar10 + 0x1c;
        uVar13 = (ulonglong)((int)uVar13 + 1);
        RoReferenceEx((uint *)((longlong)ppppuVar10 + 0x14c));
        ppppuVar1 = ppppuVar10 + 2;
        if ((undefined8 *****)*local_40 != &local_48) {
          pcVar4 = (code *)swi(0x29);
          (*pcVar4)(3);
          puVar11 = auStack_80;
          goto LAB_140011bfa;
        }
        ppppuVar10[3] = local_40;
        *ppppuVar1 = &local_48;
        *local_40 = ppppuVar1;
        local_40 = ppppuVar1;
      }
    }
    KeReleaseSpinLock(&DAT_14002ce90,uVar5);
    puVar11 = auStack_88;
    for (ppppuVar10 = local_38; (undefined8 *****)ppppuVar10 != &local_38;
        ppppuVar10 = (undefined8 ****)*ppppuVar10) {
LAB_140011bfa:
      *(undefined8 *)(puVar11 + -8) = 0x140011c03;
      LwfvSwitchRevokeAssignedVf((longlong)(ppppuVar10 + -2));
    }
    uVar6 = (uint)uVar13;
    if (uVar6 != 0) {
      if (0x40 < uVar6) {
        uVar12 = 0xc000009a;
        goto LAB_140011d3f;
      }
      if (3 < uVar6) {
        *(undefined8 *)(puVar11 + -8) = 0x140011c45;
        lVar9 = ExAllocatePool2(0x40,uVar13 * 0x30,0x67326c57);
        if (lVar9 == 0) {
          uVar12 = 0xc0000017;
          goto LAB_140011d3f;
        }
      }
      *(longlong *)(puVar11 + 0x38) = lVar9;
      *(undefined8 *)(puVar11 + 0x30) = 0;
      puVar11[0x28] = 0;
      puVar11[0x20] = 0;
      *(undefined8 *)(puVar11 + -8) = 0x140011c86;
      uVar6 = KeWaitForMultipleObjects(uVar13,lVar7,0,6);
      uVar12 = (ulonglong)uVar6;
      for (ppppuVar10 = local_48; (undefined8 *****)ppppuVar10 != &local_48;
          ppppuVar10 = (undefined8 ****)*ppppuVar10) {
        local_res10 = ppppuVar10 + -2;
        *(undefined8 *)(puVar11 + -8) = 0x140011ca6;
        uVar5 = KeAcquireSpinLockRaiseToDpc(ppppuVar10 + 4);
        *(undefined8 *)(puVar11 + -8) = 0x140011cbb;
        KeClearEvent(ppppuVar10 + 0x1a);
        *(undefined8 *)(puVar11 + -8) = 0x140011ccd;
        KeReleaseSpinLock(ppppuVar10 + 4,uVar5);
        LOCK();
        piVar2 = (int *)((longlong)ppppuVar10 + 0x13c);
        iVar3 = *piVar2;
        *piVar2 = *piVar2 + -2;
        UNLOCK();
        if (iVar3 == 3) {
          *(undefined8 *)(puVar11 + -8) = 0x140011cee;
          L2LwfFree((longlong *)&local_res10);
        }
      }
    }
    *(undefined8 *)(puVar11 + -8) = 0x140011d08;
    uVar5 = KeAcquireSpinLockRaiseToDpc(&DAT_14002ce90);
  }
  else {
    lVar7 = ExAllocatePool2(0x40,(ulonglong)DAT_14002ced8 << 3,0x67326c57);
    puVar11 = auStack_88;
    if (lVar7 != 0) goto LAB_140011b6a;
    uVar12 = 0xc0000017;
  }
  *(undefined8 *)(puVar11 + -8) = 0x140011d21;
  KeReleaseSpinLock(&DAT_14002ce90,uVar5);
  if (lVar9 != 0) {
    *(undefined8 *)(puVar11 + -8) = 0x140011d3a;
    ExFreePoolWithTag(lVar9,0x67326c57);
  }
LAB_140011d3f:
  if (lVar7 != 0) {
    *(undefined8 *)(puVar11 + -8) = 0x140011d53;
    ExFreePoolWithTag(lVar7,0x67326c57);
  }
  return uVar12;
}



===== wil_details_FeatureDescriptors_SkipPadding @ 140011d80 =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_14002bb3f < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 140011da8 =====

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



===== wil_details_FeatureReporting_IncrementUsageInCache @ 140011e80 =====

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



===== wil_details_FeatureReporting_RecordUsageInCache @ 140011f64 =====

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
LAB_1400120bc:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_1400120af:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_1400120bc;
      if (uVar5 == 5) goto LAB_1400120af;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 1400120e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (longlong param_1,undefined8 param_2,int param_3)

{
  bool bVar1;
  uint uVar2;
  undefined7 extraout_var;
  uint uVar3;
  int local_res18 [4];
  
  uVar3 = (uint)param_2 & 1;
  local_res18[0] = param_3;
  uVar2 = wil_details_MapReportingKind(param_3,uVar3);
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(param_1,param_2,(ulonglong)uVar2);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (*(undefined4 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x10),0,uVar3,local_res18,0
               ,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140012168 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (longlong param_1,undefined8 param_2,ulonglong param_3)

{
  uint6 uVar1;
  uint *puVar2;
  undefined1 auStack_98 [32];
  uint *local_78;
  undefined8 local_68;
  uint local_60 [6];
  uint local_48;
  uint uStack_44;
  uint uStack_40;
  uint uStack_3c;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_98;
  puVar2 = wil_details_FeatureReporting_RecordUsageInCache
                     (local_60,*(uint **)(param_1 + 8),param_3,(uint)((ulonglong)param_2 >> 0x20));
  local_48 = *puVar2;
  uStack_44 = puVar2[1];
  uStack_40 = puVar2[2];
  uStack_3c = puVar2[3];
  local_38 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_78 = &local_48;
    (*g_wil_details_recordFeatureUsage)
              (*(undefined4 *)(param_1 + 0x18),param_3 & 0xffffffff,1,*(undefined8 *)(param_1 + 8));
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && ((int)param_3 != 0xfe)) {
    local_68._0_6_ = CONCAT24((short)(param_3 & 0xffffffff),*(undefined4 *)(param_1 + 0x18));
    uVar1 = (uint6)local_68;
    local_68 = (ulonglong)(uint6)local_68;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_68 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_68);
  }
  return (int)local_38 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 140012258 =====

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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140012368 =====

void wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath
               (uint param_1,int param_2,undefined8 *param_3)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
  puVar2 = (uint *)*param_3;
  if (param_2 == 3) {
    uVar4 = 0x10;
  }
  else {
    if (param_2 != 4) {
      return;
    }
    uVar4 = 0x20;
  }
  if ((*(char *)((longlong)param_3 + 0x1e) == '\0') && (*(char *)((longlong)param_3 + 0x1d) == '\0')
     ) {
    uVar3 = *puVar2;
    if ((uVar3 & 2) != 0) {
      while ((uVar3 & 1) == (param_1 & 1)) {
        LOCK();
        uVar1 = *puVar2;
        bVar5 = uVar3 == uVar1;
        if (bVar5) {
          *puVar2 = uVar4 | uVar3;
        }
        else {
          uVar3 = uVar1;
        }
        UNLOCK();
        if (bVar5) {
          return;
        }
        if ((uVar3 & 2) == 0) {
          return;
        }
      }
    }
  }
  else {
    LOCK();
    *puVar2 = *puVar2 | uVar4;
    UNLOCK();
  }
  return;
}



===== wil_details_GetCurrentFeatureEnabledState @ 1400123cc =====

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



===== wil_details_IsEnabledFallback @ 14001252c =====

uint wil_details_IsEnabledFallback(ulonglong param_1,int param_2,undefined8 *param_3)

{
  ulonglong local_res8;
  
  local_res8 = param_1 & 0xffffffff;
  if ((param_1 & 2) == 0) {
    local_res8 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                           ((uint *)*param_3,param_1,(longlong)param_3);
    param_1 = local_res8 & 0xffffffff;
  }
  if ((param_2 != 0) &&
     (wil_details_FeatureReporting_ReportUsageToService((longlong)param_3,local_res8,param_2),
     param_2 - 3U < 2)) {
    wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath((uint)local_res8,param_2,param_3);
  }
  return (uint)param_1 & 1;
}



===== wil_details_MapReportingKind @ 1400125c0 =====

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



===== wil_details_RecordCachedUsage @ 140012660 =====

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



===== wil_details_RecordFeatureUsageReporting @ 1400127c0 =====

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



===== L2CreatevSwitchFlow @ 140012844 =====

undefined8
L2CreatevSwitchFlow(longlong param_1,short param_2,byte *param_3,byte *param_4,short param_5,
                   int param_6,undefined8 param_7,undefined8 param_8,undefined8 *param_9)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  bool bVar3;
  longlong local_res8;
  int iVar4;
  undefined4 in_stack_ffffffffffffff8c;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  
  uVar2 = 0;
  local_res8 = 0;
  local_48 = 0;
  local_30 = 0;
  local_58 = 0;
  uStack_50 = 0;
  bVar3 = false;
  local_40 = 0;
  uStack_38 = 0;
  if (2 < *(uint *)(param_1 + 0x770)) {
    return 0xc0000001;
  }
  L2pComputevSwitchFlowHashSignature(param_2,param_3,param_4,param_5,(byte)param_6,&local_res8);
  RtlAcquireWriteLock(param_1 + 0x40);
  RtlAcquireWriteLockAtDpcLevel(param_1);
  if (*(char *)(param_1 + 0x774) == '\0') {
    iVar4 = param_6;
    puVar1 = (undefined4 *)
             L2pLookupvSwitchFlow(param_1,local_res8,param_2,param_3,param_4,param_5,param_6);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = L2pCreatevSwitchFlow
                         (param_1,param_2,(undefined4 *)param_3,(undefined4 *)param_4,param_5,
                          param_6,CONCAT44(in_stack_ffffffffffffff8c,iVar4),local_res8);
      if (puVar1 == (undefined4 *)0x0) {
        uVar2 = 0xc0000017;
        goto LAB_140012958;
      }
      RoReferenceEx(puVar1 + 0x1c);
      bVar3 = *(int *)(param_1 + 0x24) == 1;
    }
    KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_58);
    KeReleaseInStackQueuedSpinLock(&local_40);
    L2RefreshFlow(param_1,(longlong)puVar1);
    if (bVar3) {
      L2pStartTimer(param_1);
    }
    *param_9 = puVar1;
  }
  else {
    uVar2 = 0xc0000001;
LAB_140012958:
    KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_58);
    KeReleaseInStackQueuedSpinLock(&local_40);
  }
  return uVar2;
}



===== L2FlowRemoveContext @ 1400129f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 L2FlowRemoveContext(longlong param_1,int param_2)

{
  undefined1 uVar1;
  code *pcVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  lVar3 = (longlong)param_2;
  pcVar2 = (code *)0x0;
  uVar5 = 0;
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x50);
  if ((*(byte *)(param_1 + 0x70) & 1) == 0) {
    pcVar2 = *(code **)(param_1 + (lVar3 + 8) * 0x10);
    uVar5 = *(undefined8 *)(param_1 + 0x78 + lVar3 * 0x10);
    *(undefined8 *)(param_1 + (lVar3 + 8) * 0x10) = 0;
    *(undefined8 *)(param_1 + 0x78 + lVar3 * 0x10) = 0;
    uVar4 = 0;
  }
  else {
    uVar4 = 0xc0000001;
  }
  KeReleaseSpinLock(param_1 + 0x50,uVar1);
  if (pcVar2 != (code *)0x0) {
    (*pcVar2)(1,param_1,uVar5);
  }
  return uVar4;
}



===== L2UnInitializeFlowsManager @ 140012aa8 =====

void L2UnInitializeFlowsManager(longlong param_1)

{
  int iVar1;
  int *piVar2;
  longlong lVar3;
  int *piVar4;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  RtlAcquireWriteLock(param_1);
  iVar1 = *(int *)(param_1 + 0x24);
  *(undefined1 *)(param_1 + 0x774) = 1;
  KeReleaseInStackQueuedSpinLock(&local_28);
  if (iVar1 != 0) {
    KeWaitForSingleObject(param_1 + 0x778,0,0,0,0);
  }
  KeCancelTimer(param_1 + 0x60);
  RtlCleanupTimerWheel(param_1 + 0x128);
  piVar2 = *(int **)(param_1 + 0x760);
  if (piVar2 != (int *)0x0) {
    lVar3 = (longlong)(*piVar2 + -1);
    if (-1 < *piVar2 + -1) {
      piVar4 = piVar2 + lVar3 * 0x20 + 0x10;
      do {
        if ((char)piVar4[0x1c] != '\0') {
          ExDeleteLookasideListEx(piVar4);
        }
        piVar4 = piVar4 + -0x20;
        lVar3 = lVar3 + -1;
      } while (-1 < lVar3);
    }
    ExFreePoolWithTag(piVar2,0x66326c57);
  }
  if (*(longlong *)(param_1 + 0x50) != 0) {
    RtlDeleteHashTable();
  }
  RtlDeleteHashTable(param_1 + 0x10);
  return;
}



===== L2pCreatevSwitchFlow @ 140012bd4 =====

undefined4 *
L2pCreatevSwitchFlow
          (longlong param_1,undefined2 param_2,undefined4 *param_3,undefined4 *param_4,
          undefined2 param_5,undefined4 param_6,undefined8 param_7,longlong param_8)

{
  undefined4 *puVar1;
  undefined8 *puVar2;
  longlong lVar3;
  
  puVar1 = (undefined4 *)PplAllocateFromLookasideList(*(longlong *)(param_1 + 0x760));
  if (puVar1 != (undefined4 *)0x0) {
    *(undefined2 *)(puVar1 + 1) = param_2;
    *puVar1 = 1;
    lVar3 = 2;
    *(undefined2 *)((longlong)puVar1 + 6) = param_5;
    puVar1[0x29] = param_6;
    puVar1[0x26] = *param_3;
    *(undefined2 *)(puVar1 + 0x27) = *(undefined2 *)(param_3 + 1);
    *(undefined4 *)((longlong)puVar1 + 0x9e) = *param_4;
    *(undefined2 *)((longlong)puVar1 + 0xa2) = *(undefined2 *)(param_4 + 1);
    puVar2 = (undefined8 *)(puVar1 + 0x20);
    puVar1[0x12] = 0x3c;
    puVar1[2] = 0;
    do {
      puVar2[-1] = 0;
      *puVar2 = 0;
      puVar2 = puVar2 + 2;
      lVar3 = lVar3 + -1;
    } while (lVar3 != 0);
    *(undefined8 *)(puVar1 + 0x16) = 0;
    *(undefined8 *)(puVar1 + 0x18) = 0;
    *(undefined8 *)(puVar1 + 0x1a) = 0;
    KeInitializeSpinLock(puVar1 + 0x14);
    RtlInitializeTimerWheelEntry(0,puVar1 + 0x16,0,0);
    puVar1[0x1c] = 2;
    RtlInsertEntryHashTable
              (param_1 + 0x10,puVar1 + 4,param_8 << ((byte)*(undefined4 *)(param_1 + 0x38) & 0x3f),0
              );
    puVar1[2] = puVar1[2] | 1;
    RoReferenceEx(puVar1 + 0x1c);
  }
  return puVar1;
}



===== L2pIsSamevSwitchFlow @ 140012d10 =====

bool L2pIsSamevSwitchFlow
               (longlong param_1,short param_2,undefined8 param_3,undefined8 param_4,short param_5,
               int param_6)

{
  longlong lVar1;
  
  if ((((*(short *)(param_1 + 4) == param_2) && (*(short *)(param_1 + 6) == param_5)) &&
      (*(int *)(param_1 + 0xa4) == param_6)) &&
     (lVar1 = RtlCompareMemory(param_1 + 0x98,param_3,6), lVar1 == 6)) {
    lVar1 = RtlCompareMemory(param_1 + 0x9e,param_4,6);
    return lVar1 == 6;
  }
  return false;
}



===== PplpCreateLookasideListEx @ 140012d98 =====

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
  puVar2 = (uint *)ExAllocatePool3(0x48,(ulonglong)uVar5 * 0x80 + 0x40,0x66326c57,&local_28,1);
  if (puVar2 == (uint *)0x0) {
LAB_140012eaa:
    puVar2 = (uint *)0x0;
  }
  else {
    lVar4 = 0;
    for (iVar3 = 0; iVar3 < (int)uVar5; iVar3 = iVar3 + 1) {
      KeInitializeSpinLock(puVar2 + lVar4 * 0x20 + 0x2a);
      if (lVar4 == 0) {
        iVar1 = ExInitializeLookasideListEx(puVar2 + 0x10,0,0,0x200,0,0xb8,0x66326c57,0);
        if (iVar1 < 0) {
          ExFreePoolWithTag(puVar2,0x66326c57);
          goto LAB_140012eaa;
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
    puVar2[2] = 0x66326c57;
    puVar2[3] = 0x66326c57;
    puVar2[4] = 0xb8;
    puVar2[5] = 0;
    puVar2[8] = 0x200;
    *(undefined2 *)(puVar2 + 9) = 0;
    puVar2[6] = 0;
    puVar2[7] = 0;
  }
  return puVar2;
}



===== L2pAuditPacketVeto @ 140012f00 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void L2pAuditPacketVeto(ushort param_1,longlong param_2,undefined8 param_3)

{
  undefined1 auStack_3a8 [32];
  undefined4 local_388 [2];
  undefined2 local_380;
  undefined2 local_300;
  ulonglong local_280;
  undefined8 local_270;
  undefined4 local_268;
  undefined2 local_230;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_3a8;
  memset(local_388,0,0x368);
  local_380 = 0x21;
  local_300 = 0x21;
  L2pFillCommonAuditDiagEventInfo(0,param_1,param_2,(longlong)local_388);
  local_268 = 0x141f;
  local_230 = 0x10;
  local_388[0] = 2;
  local_280 = (ulonglong)param_1;
  local_270 = param_3;
  KfdAuditEvent(local_388);
  return;
}



===== Feature_Firewall_BugFixes_25D_WFPlwfs_L28023_resilience__private_IsEnabledDeviceUsageNoInline @ 140012fd0 =====

ulonglong Feature_Firewall_BugFixes_25D_WFPlwfs_L28023_resilience__private_IsEnabledDeviceUsageNoInline
                    (void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)
               Feature_Firewall_BugFixes_25D_WFPlwfs_L28023_resilience__private_featureState;
  if ((Feature_Firewall_BugFixes_25D_WFPlwfs_L28023_resilience__private_featureState & 0x10) == 0) {
    uVar1 = Feature_Firewall_BugFixes_25D_WFPlwfs_L28023_resilience__private_IsEnabledFallback
                      (local_res8,3);
  }
  else {
    uVar1 = (ulonglong)
            (Feature_Firewall_BugFixes_25D_WFPlwfs_L28023_resilience__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_Firewall_BugFixes_25D_WFPlwfs_L28023_resilience__private_IsEnabledFallback @ 140013008 =====

void Feature_Firewall_BugFixes_25D_WFPlwfs_L28023_resilience__private_IsEnabledFallback
               (ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,
             &Feature_Firewall_BugFixes_25D_WFPlwfs_L28023_resilience__private_descriptor);
  return;
}



===== L2pCacheMatchedNativeLayerFilterList @ 140013024 =====

ulonglong L2pCacheMatchedNativeLayerFilterList
                    (longlong param_1,int param_2,uint param_3,longlong param_4,undefined8 param_5)

{
  ulonglong uVar1;
  longlong local_18 [2];
  
  local_18[0] = 0;
  uVar1 = L2CreateLayerClassifyCache(0,param_4,param_5,param_4,local_18);
  if (-1 < (int)uVar1) {
    LwfLowerCacheClassifyCache(local_18[0],param_1,param_2,param_3);
  }
  return uVar1 & 0xffffffff;
}



===== L2InsertNetBufferListReferenceRecord @ 140013094 =====

void L2InsertNetBufferListReferenceRecord(longlong param_1,undefined8 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  undefined8 *puVar2;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x30);
  if (*(longlong *)(param_1 + 0x3c8) != 0) {
    puVar2 = (undefined8 *)
             ((ulonglong)*(uint *)(param_1 + 0x3d0) * 0x50 + *(longlong *)(param_1 + 0x3c8));
    *puVar2 = param_2;
    *(undefined4 *)(puVar2 + 1) = param_3;
    RtlCaptureStackBackTrace(1,8,puVar2 + 2);
    *(int *)(param_1 + 0x3d0) = *(int *)(param_1 + 0x3d0) + 1;
    if (*(int *)(param_1 + 0x3d0) == 0x800) {
      *(undefined4 *)(param_1 + 0x3d0) = 0;
      *(undefined1 *)(param_1 + 0x3d4) = 1;
    }
  }
  KeReleaseSpinLock(param_1 + 0x30,uVar1);
  return;
}



===== L2AcquireL3InspectRef @ 14001315c =====

bool L2AcquireL3InspectRef(longlong param_1)

{
  undefined1 uVar1;
  bool bVar2;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x30);
  bVar2 = *(int *)(param_1 + 0x3c) == 3;
  if (bVar2) {
    *(int *)(param_1 + 0x148) = *(int *)(param_1 + 0x148) + 1;
  }
  KeReleaseSpinLock(param_1 + 0x30,uVar1);
  return bVar2;
}



===== L2MoveNblsToBlockList @ 1400131c4 =====

void L2MoveNblsToBlockList(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar2 = (undefined8 *)*param_2;
  while (param_1 != (undefined8 *)0x0) {
    puVar1 = (undefined8 *)*param_1;
    *param_1 = puVar2;
    puVar2 = param_1;
    param_1 = puVar1;
  }
  *param_2 = puVar2;
  return;
}



===== MIDL_user_allocate @ 1400131f0 =====

void * __stdcall MIDL_user_allocate(size_t size)

{
  void *pvVar1;
  
  pvVar1 = (void *)ExAllocatePool2(0x40,size,0x70646657);
  return pvVar1;
}



===== MIDL_user_free @ 140013220 =====

void __stdcall MIDL_user_free(void *param_1)

{
  ExFreePoolWithTag(param_1,0x70646657);
  return;
}



===== WPP_SF_L @ 140013244 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_L(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_69b955bb632732390393ed1a04d5aa40_Traceguids,0x41,local_res20,4,0);
  return;
}



===== WPP_SF_LL @ 140013290 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_LL(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_69b955bb632732390393ed1a04d5aa40_Traceguids,0x23,local_res20,4,
             &param_5,4,0);
  return;
}



===== WPP_SF_d @ 1400132e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_d(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_69b955bb632732390393ed1a04d5aa40_Traceguids,param_2,local_res20,4,0);
  return;
}



===== WPP_SF_q @ 140013330 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_69b955bb632732390393ed1a04d5aa40_Traceguids,param_2,&local_res20,8,0)
  ;
  return;
}



===== WPP_SF_qD @ 140013378 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_69b955bb632732390393ed1a04d5aa40_Traceguids,0x2a,&local_res20,8,
             &param_5,4,0);
  return;
}



===== WPP_SF_qd @ 1400133d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_69b955bb632732390393ed1a04d5aa40_Traceguids,param_2,&local_res20,8,
             &param_5,4,0);
  return;
}



===== WPP_SF_s @ 14001342c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_s(undefined8 param_1,undefined2 param_2,undefined8 param_3,char *param_4)

{
  longlong lVar1;
  longlong lVar2;
  
  if (param_4 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_4[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_69b955bb632732390393ed1a04d5aa40_Traceguids,param_2,param_4,lVar2,0);
  return;
}



===== WPP_SF_sd @ 140013494 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sd(undefined8 param_1,undefined2 param_2,undefined8 param_3,char *param_4,
              undefined1 param_5)

{
  longlong lVar1;
  longlong lVar2;
  
  if (param_4 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_4[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,param_4,lVar2,&param_5,4,0);
  return;
}



===== WPP_SF_sdd @ 14001350c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sdd(undefined8 param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 uStack0000000000000028;
  undefined1 uStack0000000000000030;
  
  lVar1 = -1;
  do {
    lVar2 = lVar1;
    lVar1 = lVar2 + 1;
  } while ("WfpRioNblSendComplete"[lVar2 + 1] != '\0');
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_69b955bb632732390393ed1a04d5aa40_Traceguids,0x27,
             "WfpRioNblSendComplete",lVar2 + 2,&uStack0000000000000028,4,&uStack0000000000000030,4,0
            );
  return;
}



===== WPP_SF_sqd @ 14001358c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sqd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = -1;
  do {
    lVar2 = lVar1;
    lVar1 = lVar2 + 1;
  } while ("WfpRioFlushSend"[lVar2 + 1] != '\0');
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_69b955bb632732390393ed1a04d5aa40_Traceguids,param_2,"WfpRioFlushSend"
             ,lVar2 + 2,&param_5,8,&param_6,4,0);
  return;
}



===== WfpExceptionFilter @ 14001360c =====

undefined8 WfpExceptionFilter(undefined8 *param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)*param_1;
  }
  return 1;
}



===== WfpRioChannelDestroy_2503 @ 140013628 =====

void WfpRioChannelDestroy_2503(longlong param_1,undefined8 param_2,undefined *param_3)

{
  undefined8 *puVar1;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  puVar1 = &local_28;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  RtlAcquireWriteLock(*(longlong *)(param_1 + 0x10));
  *(undefined1 *)(param_1 + 0x71) = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    param_3 = &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids;
    puVar1 = (undefined8 *)0x64;
    WPP_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),100,
              &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids,"WfpRioChannelDestroy_2503",
              (char)*(undefined4 *)(param_1 + 0x164));
  }
  KeReleaseInStackQueuedSpinLock(&local_28);
  WfpRioDecrementReferenceCount(param_1,puVar1,param_3);
  return;
}



===== WfpRioChannelDestroy_old @ 1400136c8 =====

void WfpRioChannelDestroy_old(longlong *param_1,undefined8 param_2,undefined8 param_3)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  bool bVar6;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined8 local_10;
  
  local_20 = 0;
  uStack_18 = 0;
  local_10 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  RtlAcquireWriteLock(param_1[2]);
  *(undefined1 *)((longlong)param_1 + 0x71) = 0;
  KeReleaseInStackQueuedSpinLock(&local_38);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x65,param_3,
             *(undefined4 *)((longlong)param_1 + 0x164));
  }
  while( true ) {
    LOCK();
    piVar1 = (int *)((longlong)param_1 + 0x164);
    iVar2 = *piVar1;
    *piVar1 = *piVar1;
    UNLOCK();
    if (iVar2 == 0) break;
    WfpRioDelayExecution();
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x66,
            &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids);
  }
  RtlAcquireWriteLock(param_1[2]);
  *(int *)(param_1 + 9) = (int)param_1[9] + -1;
  bVar6 = (int)param_1[9] == 0;
  if (bVar6) {
    *(undefined4 *)((longlong)param_1 + 0x4c) = 4;
  }
  KeReleaseInStackQueuedSpinLock(&local_38);
  if (bVar6) {
    RtlAcquireWriteLock(0x14002c670);
    lVar3 = *param_1;
    plVar4 = (longlong *)param_1[1];
    if ((*(longlong **)(lVar3 + 8) != param_1) || ((longlong *)*plVar4 != param_1)) {
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      pcVar5 = (code *)swi(3);
      (*pcVar5)();
      return;
    }
    *plVar4 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar4;
    KeReleaseInStackQueuedSpinLock(&local_20);
    WfpRioFreeRegDomain((longlong)param_1);
  }
  return;
}



===== WfpRioCheckAccess @ 140013838 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 WfpRioCheckAccess(undefined8 param_1,undefined4 *param_2)

{
  char cVar1;
  ulonglong uVar2;
  void *_Dst;
  undefined1 auStack_a8 [32];
  undefined4 local_88;
  undefined8 local_80;
  undefined4 *local_78;
  undefined1 local_70;
  uint *local_68;
  uint *local_60;
  uint local_58;
  uint local_54;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_a8;
  *param_2 = 0;
  local_54 = 0;
  local_58 = 0;
  local_40 = 0;
  local_38 = 0x20001;
  local_2c = 0x20001;
  cVar1 = '\0';
  local_34 = 0x20000;
  local_30 = 0x20000;
  local_50 = 0;
  uStack_48 = 0;
  RtlAcquireWriteLock(0x14002c508);
  if (DAT_14002c4c8 == (uint *)0x0) {
    KeReleaseInStackQueuedSpinLock(&local_50);
    uVar2 = 0xc0000022;
    goto LAB_1400139a7;
  }
  _Dst = (void *)ExAllocatePool2(0x40,*DAT_14002c4c8,0x70646657);
  if (_Dst == (void *)0x0) {
    KeReleaseInStackQueuedSpinLock(&local_50);
    uVar2 = 0xc000009a;
    goto LAB_1400139a7;
  }
  memmove(_Dst,*(void **)(DAT_14002c4c8 + 2),(ulonglong)*DAT_14002c4c8);
  KeReleaseInStackQueuedSpinLock(&local_50);
  local_60 = &local_58;
  local_68 = &local_54;
  local_70 = 1;
  local_78 = &local_38;
  local_80 = 0;
  local_88 = 0;
  cVar1 = SeAccessCheckFromStateEx(_Dst,param_1,0,1);
  if (-1 < (int)local_58) {
    if (cVar1 != '\0') {
      if ((local_54 & 1) != 0) {
        cVar1 = '\x01';
        goto LAB_140013990;
      }
      cVar1 = '\0';
    }
    local_58 = 0xc0000022;
  }
LAB_140013990:
  ExFreePoolWithTag(_Dst,0x70646657);
  uVar2 = (ulonglong)local_58;
LAB_1400139a7:
  *param_2 = (int)uVar2;
  return CONCAT71((int7)(uVar2 >> 8),cVar1);
}



===== WfpRioCheckAccessAndGetSids @ 1400139d8 =====

ulonglong WfpRioCheckAccessAndGetSids(undefined8 param_1,longlong *param_2,longlong *param_3)

{
  uint uVar1;
  longlong lVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong *plVar6;
  longlong lVar7;
  int local_res10 [2];
  uint local_res18 [2];
  undefined4 local_res20 [2];
  longlong *local_58;
  longlong local_50;
  longlong local_48;
  longlong local_40;
  
  local_50 = 0;
  plVar6 = (longlong *)0x0;
  local_res10[0] = 0;
  local_40 = 0;
  local_res20[0] = 0;
  *param_2 = 0;
  *param_3 = 0;
  local_48 = 0;
  local_58 = (longlong *)0x0;
  lVar2 = PsReferencePrimaryToken();
  uVar1 = ObOpenObjectByPointer(lVar2,0x200,0,0xf01ff,0,0,&local_50);
  uVar5 = (ulonglong)uVar1;
  if (-1 < (int)uVar1) {
    local_res18[0] = ZwQueryInformationToken(local_50,0x1d,local_res10,4,local_res20);
    if (local_res10[0] == 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids);
      }
      uVar5 = 0xc0000022;
    }
    else {
      uVar3 = WfpRioCheckAccess(lVar2,local_res18);
      if ((char)uVar3 == '\0') {
        uVar5 = (ulonglong)local_res18[0];
      }
      else {
        uVar5 = WfpRioGetTokenInformation(local_50,0x1f,(longlong *)&local_58);
        plVar6 = local_58;
        if (-1 < (int)uVar5) {
          lVar7 = 0;
          if (*local_58 != 0) {
            uVar4 = WfpRioCopySid(*local_58,&local_48);
            uVar5 = uVar4 & 0xffffffff;
            if ((int)uVar4 < 0) goto LAB_140013b73;
            lVar7 = local_48;
          }
          ExFreePoolWithTag(plVar6,0x70646657);
          local_58 = (longlong *)0x0;
          uVar5 = WfpRioGetTokenInformation(local_50,1,(longlong *)&local_58);
          plVar6 = local_58;
          if (-1 < (int)uVar5) {
            uVar4 = WfpRioCopySid(*local_58,&local_40);
            uVar5 = uVar4 & 0xffffffff;
            if (-1 < (int)uVar4) {
              *param_3 = local_40;
              *param_2 = lVar7;
            }
            goto LAB_140013b73;
          }
        }
        uVar5 = uVar5 & 0xffffffff;
        plVar6 = local_58;
      }
    }
  }
LAB_140013b73:
  if (local_50 != 0) {
    ObCloseHandle(local_50,0);
  }
  if (lVar2 != 0) {
    PsDereferencePrimaryToken(lVar2);
  }
  if (plVar6 != (longlong *)0x0) {
    ExFreePoolWithTag(plVar6,0x70646657);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
             &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids,(int)uVar5);
  }
  return uVar5;
}



===== WfpRioCheckRqBufferSize @ 140013c04 =====

ulonglong WfpRioCheckRqBufferSize(uint param_1,uint param_2)

{
  ulonglong in_RAX;
  
  if ((param_1 < 0xaaaaaa9) &&
     (in_RAX = (ulonglong)param_2, (ulonglong)param_1 * 0x18 + 0x10 == in_RAX)) {
    return CONCAT71((uint7)(uint3)(param_2 >> 8),1);
  }
  return in_RAX & 0xffffffffffffff00;
}



===== WfpRioCleanupQueueContextRq @ 140013c30 =====

void WfpRioCleanupQueueContextRq(longlong param_1)

{
  MmUnlockPages(*(undefined8 *)(param_1 + 8));
  IoFreeMdl(*(undefined8 *)(param_1 + 8));
  *(undefined8 *)(param_1 + 8) = 0;
  return;
}



===== WfpRioCloseAndRemoveRioState @ 140013c6c =====

void WfpRioCloseAndRemoveRioState(longlong param_1)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(param_1 + 0x40);
  if (-1 < *(int *)(puVar1 + 1)) {
    *(undefined4 *)(puVar1 + 1) = 0xc0000128;
  }
  WfpRioFlushRq(param_1,0xc0000128);
  puVar1[5] = 0;
  puVar1[0xc] = 0;
  WfpRioCleanupQueueContextRq((longlong)(puVar1 + 3));
  WfpRioCleanupQueueContextRq((longlong)(puVar1 + 10));
  WfpRioCleanupRioState(puVar1);
  *(undefined8 *)(param_1 + 0x40) = 0;
  return;
}



===== WfpRioCloseDispatchHandler @ 140013ccc =====

void WfpRioCloseDispatchHandler(undefined8 param_1,longlong param_2,undefined *param_3)

{
  ulonglong uVar1;
  
  uVar1 = Feature_VPN_BugFixes_25A__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar1 == 0) {
    WfpRioCloseDispatchHandler_old(param_1,param_2,param_3);
  }
  else {
    WfpRioCloseDispatchHandler_2503(param_1,param_2,param_3);
  }
  return;
}



===== WfpRioCloseDispatchHandler_2503 @ 140013cfc =====

undefined8 WfpRioCloseDispatchHandler_2503(undefined8 param_1,longlong param_2,undefined *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  code *pcVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  longlong lVar7;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  plVar1 = *(longlong **)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x18);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    param_3 = &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids;
    WPP_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4e,
              &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids,"WfpRioCloseDispatchHandler_2503",
              (char)*(undefined4 *)((longlong)plVar1 + 0x164));
  }
  LOCK();
  plVar2 = plVar1 + 0x28;
  lVar4 = *plVar2;
  *(int *)plVar2 = (int)*plVar2 + -1;
  UNLOCK();
  if ((int)lVar4 != 2) {
    param_3 = (undefined *)0x0;
    KeWaitForSingleObject(plVar1 + 0x29,0,0,0,0);
  }
  puVar6 = &local_28;
  RtlAcquireWriteLock(plVar1[2]);
  *(undefined4 *)((longlong)plVar1 + 0x4c) = 3;
  WfpRioCloseRegistrationDomain((longlong)plVar1,puVar6,param_3);
  lVar4 = plVar1[0x39];
  lVar7 = 0;
  if (lVar4 != 0) {
    plVar1[0x39] = 0;
    lVar7 = lVar4;
  }
  ObfDereferenceObject(plVar1[0x35]);
  plVar1[0x35] = 0;
  KeReleaseInStackQueuedSpinLock(&local_28);
  if (lVar7 != 0) {
    PsReleaseProcessWakeCounter(lVar7,DPDeviceObject);
  }
  puVar6 = &local_28;
  RtlAcquireWriteLock(0x14002c670);
  lVar4 = *plVar1;
  if ((*(longlong **)(lVar4 + 8) == plVar1) &&
     (plVar2 = (longlong *)plVar1[1], (longlong *)*plVar2 == plVar1)) {
    *plVar2 = lVar4;
    *(longlong **)(lVar4 + 8) = plVar2;
    KeReleaseInStackQueuedSpinLock(&local_28);
    WfpRioDecrementReferenceCount((longlong)plVar1,puVar6,param_3);
    *(undefined4 *)(param_2 + 0x30) = 0;
    IofCompleteRequest(param_2,0);
    return 0;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  uVar5 = (*pcVar3)();
  return uVar5;
}



===== WfpRioCloseDispatchHandler_old @ 140013ea0 =====

undefined8 WfpRioCloseDispatchHandler_old(undefined8 param_1,longlong param_2,undefined *param_3)

{
  int *piVar1;
  int iVar2;
  longlong *plVar3;
  longlong *plVar4;
  code *pcVar5;
  longlong lVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  longlong lVar9;
  bool bVar10;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined8 local_10;
  
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  local_20 = 0;
  uStack_18 = 0;
  local_10 = 0;
  plVar3 = *(longlong **)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x18);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4f,param_3,
             *(undefined4 *)((longlong)plVar3 + 0x164));
  }
  while( true ) {
    LOCK();
    piVar1 = (int *)((longlong)plVar3 + 0x164);
    iVar2 = *piVar1;
    *piVar1 = *piVar1;
    UNLOCK();
    if (iVar2 == 0) break;
    WfpRioDelayExecution();
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    param_3 = &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x50,
            &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids);
  }
  LOCK();
  plVar4 = plVar3 + 0x28;
  lVar6 = *plVar4;
  *(int *)plVar4 = (int)*plVar4 + -1;
  UNLOCK();
  if ((int)lVar6 != 2) {
    param_3 = (undefined *)0x0;
    KeWaitForSingleObject(plVar3 + 0x29,0,0,0,0);
  }
  puVar8 = &local_38;
  RtlAcquireWriteLock(plVar3[2]);
  *(undefined4 *)((longlong)plVar3 + 0x4c) = 3;
  *(int *)(plVar3 + 9) = (int)plVar3[9] + -1;
  WfpRioCloseRegistrationDomain((longlong)plVar3,puVar8,param_3);
  lVar6 = plVar3[0x39];
  lVar9 = 0;
  if (lVar6 != 0) {
    plVar3[0x39] = 0;
    lVar9 = lVar6;
  }
  ObfDereferenceObject(plVar3[0x35]);
  plVar3[0x35] = 0;
  bVar10 = (int)plVar3[9] == 0;
  if (bVar10) {
    *(undefined4 *)((longlong)plVar3 + 0x4c) = 4;
  }
  KeReleaseInStackQueuedSpinLock(&local_38);
  if (lVar9 != 0) {
    PsReleaseProcessWakeCounter(lVar9,DPDeviceObject);
  }
  if (bVar10) {
    RtlAcquireWriteLock(0x14002c670);
    lVar6 = *plVar3;
    plVar4 = (longlong *)plVar3[1];
    if ((*(longlong **)(lVar6 + 8) != plVar3) || ((longlong *)*plVar4 != plVar3)) {
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      pcVar5 = (code *)swi(3);
      uVar7 = (*pcVar5)();
      return uVar7;
    }
    *plVar4 = lVar6;
    *(longlong **)(lVar6 + 8) = plVar4;
    KeReleaseInStackQueuedSpinLock(&local_20);
    WfpRioFreeRegDomain((longlong)plVar3);
  }
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== WfpRioCopySid @ 1400140b8 =====

undefined8 WfpRioCopySid(undefined8 param_1,longlong *param_2)

{
  undefined4 uVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  *param_2 = 0;
  uVar1 = RtlLengthSid();
  lVar2 = ExAllocatePool2(0x40,uVar1,0x70646657);
  *param_2 = lVar2;
  if (lVar2 == 0) {
    uVar3 = 0xc000009a;
  }
  else {
    RtlCopySid(uVar1,lVar2,param_1);
    uVar3 = 0;
  }
  return uVar3;
}



===== WfpRioCreateAndInitializeRegDomain @ 140014134 =====

ulonglong WfpRioCreateAndInitializeRegDomain
                    (longlong param_1,longlong *param_2,longlong param_3,longlong param_4,
                    uint param_5,void *param_6,undefined4 *param_7)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  longlong lVar5;
  longlong *plVar6;
  undefined4 *puVar7;
  void *_Dst;
  longlong lVar8;
  ulonglong uVar9;
  undefined8 *puVar10;
  ulonglong uVar11;
  
  _Dst = (void *)0x0;
  *param_2 = 0;
  puVar7 = (undefined4 *)0x0;
  lVar8 = 0;
  if (param_5 + 2 < 2) {
    return 0xc000000d;
  }
  lVar5 = ExAllocatePool2(0x48,0x10,0x70646657);
  if (lVar5 == 0) {
    return 0xc000009a;
  }
  plVar6 = (longlong *)ExAllocatePool2(0x40,0x1d0,0x70646657);
  if ((((plVar6 == (longlong *)0x0) ||
       (puVar7 = (undefined4 *)ExAllocatePool2(0x40,0x10,0x70646657), puVar7 == (undefined4 *)0x0))
      || (_Dst = (void *)ExAllocatePool2(0x40,(ulonglong)param_5 + 2,0x70646657),
         _Dst == (void *)0x0)) || (lVar8 = ExAllocatePool2(0x40,4,0x70646657), lVar8 == 0)) {
    uVar11 = 0xc000009a;
  }
  else {
    KeInitializeTimer(plVar6 + 0xf);
    uVar9 = WfpRioInitializeRegDomainFieldsNewHandle((longlong)plVar6);
    uVar11 = uVar9 & 0xffffffff;
    if (-1 < (int)uVar9) {
      plVar6[2] = lVar5;
      KeInitializeSpinLock(lVar5);
      *(undefined4 *)(lVar5 + 8) = 0;
      plVar6[10] = param_3;
      plVar6[0xb] = param_4;
      plVar6[0x36] = param_1;
      memmove(_Dst,param_6,(ulonglong)param_5);
      plVar6[0xd] = (longlong)_Dst;
      *(uint *)(plVar6 + 0xc) = param_5;
      plVar6[0x27] = lVar8;
      *(undefined4 *)(plVar6 + 9) = 1;
      uVar2 = param_7[1];
      uVar3 = param_7[2];
      uVar4 = param_7[3];
      *puVar7 = *param_7;
      puVar7[1] = uVar2;
      puVar7[2] = uVar3;
      puVar7[3] = uVar4;
      plVar6[0x31] = (longlong)puVar7;
      *(undefined4 *)((longlong)plVar6 + 0x4c) = 1;
      KeInitializeEvent(plVar6 + 0x2d,0,0);
      KeInitializeEvent(plVar6 + 0x29,0,0);
      *(undefined1 *)(plVar6 + 0xe) = 1;
      *(undefined4 *)(plVar6 + 0x2c) = 2;
      *(undefined4 *)(plVar6 + 0x28) = 2;
      KeInitializeDpc(plVar6 + 0x1f,WfpRioIdleDpcHandler,plVar6);
      puVar10 = &RegDomainList;
      if ((longlong **)*(undefined8 **)((longlong)RegDomainList + 8) != &RegDomainList) {
        puVar10 = (undefined8 *)0x3;
        pcVar1 = (code *)swi(0x29);
        RegDomainList = (longlong *)(*pcVar1)();
      }
      *plVar6 = (longlong)RegDomainList;
      plVar6[1] = (longlong)puVar10;
      *(longlong **)((longlong)RegDomainList + 8) = plVar6;
      RegDomainList = plVar6;
      *param_2 = (longlong)plVar6;
      return uVar11;
    }
  }
  ExFreePoolWithTag(lVar5,0x70646657);
  if (puVar7 != (undefined4 *)0x0) {
    ExFreePoolWithTag(puVar7,0x70646657);
  }
  if (plVar6 != (longlong *)0x0) {
    ExFreePoolWithTag(plVar6,0x70646657);
  }
  if (_Dst != (void *)0x0) {
    ExFreePoolWithTag(_Dst,0x70646657);
  }
  if (lVar8 != 0) {
    ExFreePoolWithTag(lVar8,0x70646657);
  }
  return uVar11;
}



===== WfpRioCreateCompletionQueue @ 140014404 =====

int WfpRioCreateCompletionQueue
              (longlong param_1,longlong *param_2,longlong param_3,int param_4,int param_5,
              undefined1 param_6,int param_7,undefined8 param_8,longlong param_9)

{
  bool bVar1;
  longlong lVar2;
  undefined1 uVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  undefined4 in_register_0000008c;
  int iVar7;
  ulonglong uVar8;
  undefined8 in_stack_ffffffffffffff70;
  undefined4 uVar9;
  int local_84;
  undefined8 local_80;
  longlong local_78;
  longlong local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  longlong local_48;
  
  uVar9 = (undefined4)((ulonglong)in_stack_ffffffffffffff70 >> 0x20);
  lVar5 = 0;
  local_78 = 0;
  bVar1 = false;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  lVar6 = 0;
  local_68 = 0;
  iVar7 = param_4 * 0x20 + 0x10;
  if ((param_4 == 0) || (0x800000 < param_4 - 1U)) {
    local_84 = -0x3ffffff3;
  }
  else {
    if ((iVar7 != param_5) || (param_3 == 0)) {
      local_84 = -0x3ffffff3;
      goto LAB_140014702;
    }
    if (param_7 == 0) {
      iVar4 = 0;
    }
    else if (param_7 == 1) {
      local_80 = 0;
      uVar9 = 0;
      iVar4 = ObReferenceObjectByHandle
                        (param_8,2,*(undefined8 *)ExEventObjectType_exref,
                         CONCAT71((int7)(CONCAT44(in_register_0000008c,param_4) >> 8),param_6),
                         &local_80,0,0);
      param_8 = local_80;
    }
    else {
      iVar4 = -0x3ffffff3;
    }
    local_84 = -0x3ffffff3;
    if (iVar4 < 0) goto LAB_140014702;
    uVar8 = 0;
    bVar1 = true;
    lVar5 = IoAllocateMdl(param_3,iVar7,0,1,0);
    local_78 = lVar5;
    if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
      ExRaiseStatus(0xc0000017);
    }
    uVar3 = ExGetPreviousMode();
    MmProbeAndLockPages(lVar5,uVar3,1);
    if ((*(byte *)(lVar5 + 10) & 5) == 0) {
      local_70 = MmMapLockedPagesSpecifyCache
                           (lVar5,0,1,0,uVar8 & 0xffffffff00000000,CONCAT44(uVar9,0x40000010),1);
      local_48 = local_70;
    }
    else {
      local_70 = *(longlong *)(lVar5 + 0x18);
    }
    lVar2 = local_70;
    if (local_70 == 0) {
                    /* WARNING: Subroutine does not return */
      ExRaiseStatus(0xc000009a);
    }
    local_84 = 0;
    lVar6 = ExAllocatePool2(0x40,0x40,0x70646657);
    if (lVar6 == 0) {
      local_84 = -0x3fffffe9;
      goto LAB_140014702;
    }
    *(longlong *)(lVar6 + 0x10) = lVar2;
    *(longlong *)(lVar6 + 8) = lVar5;
    *(int *)(lVar6 + 0x1c) = param_4;
    *(int *)(lVar6 + 0x24) = param_4;
    *(undefined4 *)(lVar6 + 0x38) = 0;
    *(undefined4 *)(lVar6 + 0x18) = 2;
    *(undefined4 *)(lVar6 + 0x20) = 0;
    KeInitializeSpinLock();
    *(undefined4 *)(lVar6 + 0x2c) = 0;
    if (param_7 == 1) {
      *(undefined8 *)(lVar6 + 0x30) = param_8;
      *(uint *)(lVar6 + 0x38) = -(uint)(param_9 != 0) & 4 | *(uint *)(lVar6 + 0x38) & 0xfffffffb | 2
      ;
    }
    RtlAcquireWriteLock(*(longlong *)(param_1 + 0x10));
    uVar8 = WfpRioInsertCompletionQueue(param_1,lVar6);
    if ((char)uVar8 == '\0') {
      local_84 = -0x3fffffe9;
    }
    else {
      *param_2 = lVar6;
    }
    KeReleaseInStackQueuedSpinLock(&local_60);
    bVar1 = true;
  }
  if (-1 < local_84) {
    return local_84;
  }
LAB_140014702:
  if (lVar5 != 0) {
    if (bVar1) {
      MmUnlockPages(lVar5);
    }
    IoFreeMdl(lVar5);
  }
  if (lVar6 != 0) {
    ExFreePoolWithTag(lVar6,0x70646657);
  }
  *param_2 = 0;
  return local_84;
}



===== WfpRioCreateCq @ 140014764 =====

int WfpRioCreateCq(longlong param_1,ulonglong param_2,uint param_3,undefined4 *param_4,uint param_5,
                  char param_6)

{
  longlong lVar1;
  int iVar2;
  longlong local_48;
  longlong local_40;
  undefined8 local_38;
  longlong local_30;
  
  local_48 = 0;
  local_40 = 0;
  local_38 = 0;
  local_30 = 0;
  if (param_3 < 0x38) {
                    /* WARNING: Subroutine does not return */
    ExRaiseStatus(0xc000000d);
  }
  if ((param_6 != '\0') && ((param_2 & 3) != 0)) {
                    /* WARNING: Subroutine does not return */
    ExRaiseDatatypeMisalignment();
  }
  local_40 = *(longlong *)(param_2 + 0x30);
  local_38 = *(undefined8 *)(param_2 + 0x10);
  local_30 = *(longlong *)(param_2 + 0x18);
  iVar2 = WfpRioCreateCompletionQueue
                    (param_1,&local_48,local_40,*(int *)(param_2 + 4),*(int *)(param_2 + 0x28),
                     param_6,*(int *)(param_2 + 8),local_38,local_30);
  lVar1 = local_48;
  if (-1 < iVar2) {
    if (param_5 < 4) {
                    /* WARNING: Subroutine does not return */
      ExRaiseStatus(0xc000000d);
    }
    if (param_6 != '\0') {
      ProbeForWrite(param_4);
    }
    *param_4 = *(undefined4 *)(lVar1 + 0x28);
    *(uint *)(lVar1 + 0x38) = *(uint *)(lVar1 + 0x38) | 8;
    iVar2 = 0;
  }
  if (lVar1 != 0) {
    if (iVar2 < 0) {
      WfpRioInvalidateCq(param_1,*(uint *)(lVar1 + 0x28),'\0');
    }
    WfpRioDereferenceCqInline(lVar1);
  }
  return iVar2;
}



===== WfpRioCreateRqPair @ 14001495c =====

undefined4 WfpRioCreateRqPair(longlong param_1,ulonglong param_2,uint param_3,char param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  longlong lVar5;
  bool bVar6;
  bool bVar7;
  undefined1 uVar8;
  ulonglong uVar9;
  longlong lVar10;
  longlong lVar11;
  longlong lVar12;
  longlong *plVar13;
  longlong lVar14;
  uint uVar15;
  undefined4 uVar16;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  if (param_3 < 0x40) {
                    /* WARNING: Subroutine does not return */
    ExRaiseStatus(0xc000000d);
  }
  if ((param_4 != '\0') && ((param_2 & 3) != 0)) {
                    /* WARNING: Subroutine does not return */
    ExRaiseDatatypeMisalignment();
  }
  uVar15 = *(uint *)(param_2 + 0x10);
  uVar1 = *(uint *)(param_2 + 0x20);
  uVar2 = *(uint *)(param_2 + 0xc);
  if ((uVar2 == 0) || (uVar1 == 0)) {
                    /* WARNING: Subroutine does not return */
    ExRaiseStatus(0xc000000d);
  }
  if ((uVar2 == 1) && (uVar1 == 1)) {
                    /* WARNING: Subroutine does not return */
    ExRaiseStatus(0xc000000d);
  }
  if ((0x5555555 < uVar2) || (0x5555555 < uVar1)) {
                    /* WARNING: Subroutine does not return */
    ExRaiseStatus(0xc000000d);
  }
  uVar3 = *(uint *)(param_2 + 8);
  lVar10 = *(longlong *)(param_2 + 0x28);
  if ((lVar10 == 0) ||
     (uVar9 = WfpRioCheckRqBufferSize(uVar1,*(uint *)(param_2 + 0x24)), (char)uVar9 == '\0')) {
                    /* WARNING: Subroutine does not return */
    ExRaiseStatus(0xc000000d);
  }
  uVar9 = 0;
  lVar10 = IoAllocateMdl(lVar10);
  if (lVar10 == 0) {
                    /* WARNING: Subroutine does not return */
    ExRaiseStatus(0xc0000017);
  }
  MmProbeAndLockPages(lVar10,param_4,1);
  bVar7 = false;
  if ((*(byte *)(lVar10 + 10) & 5) == 0) {
    lVar14 = MmMapLockedPagesSpecifyCache(lVar10,0,1,0,uVar9 & 0xffffffff00000000,0x40000010);
  }
  else {
    lVar14 = *(longlong *)(lVar10 + 0x18);
  }
  if (lVar14 == 0) {
                    /* WARNING: Subroutine does not return */
    ExRaiseStatus(0xc000009a);
  }
  uVar4 = *(uint *)(param_2 + 4);
  lVar11 = *(longlong *)(param_2 + 0x18);
  if ((lVar11 == 0) || (uVar9 = WfpRioCheckRqBufferSize(uVar2,uVar15), (char)uVar9 == '\0')) {
                    /* WARNING: Subroutine does not return */
    ExRaiseStatus(0xc000000d);
  }
  uVar9 = 0;
  lVar11 = IoAllocateMdl(lVar11);
  if (lVar11 == 0) {
                    /* WARNING: Subroutine does not return */
    ExRaiseStatus(0xc0000017);
  }
  MmProbeAndLockPages(lVar11,param_4,1);
  bVar6 = false;
  if ((*(byte *)(lVar11 + 10) & 5) == 0) {
    lVar12 = MmMapLockedPagesSpecifyCache(lVar11,0,1,0,uVar9 & 0xffffffff00000000,0x40000010);
  }
  else {
    lVar12 = *(longlong *)(lVar11 + 0x18);
  }
  if (lVar12 == 0) {
                    /* WARNING: Subroutine does not return */
    ExRaiseStatus(0xc000009a);
  }
  lVar5 = *(longlong *)(param_2 + 0x38);
  plVar13 = (longlong *)WfpRioAllocateRioState(uVar2);
  if (plVar13 == (longlong *)0x0) {
    uVar16 = 0xc0000017;
  }
  else {
    *plVar13 = param_1;
    plVar13[4] = lVar11;
    *(uint *)(plVar13 + 6) = uVar2;
    plVar13[5] = lVar12;
    *(undefined1 *)(lVar12 + 8) = 1;
    *(undefined1 *)(plVar13 + 9) = 0;
    plVar13[0xb] = lVar10;
    *(uint *)(plVar13 + 0xd) = uVar1;
    plVar13[0xc] = lVar14;
    *(undefined1 *)(lVar14 + 8) = 0;
    plVar13[2] = lVar5;
    lVar14 = WfpRioFindAndReferenceCq(param_1,uVar4);
    plVar13[3] = lVar14;
    lVar14 = WfpRioFindAndReferenceCq(param_1,uVar3);
    plVar13[10] = lVar14;
    if ((plVar13[3] == 0) || (lVar14 == 0)) {
      uVar16 = 0xc000000d;
    }
    else {
      uVar8 = KeAcquireSpinLockRaiseToDpc();
      lVar14 = plVar13[3];
      uVar15 = *(int *)(lVar14 + 0x20) + (uVar2 - 1);
      uVar9 = (ulonglong)uVar15;
      if ((uVar2 - 1 <= uVar15) && (uVar15 < *(uint *)(lVar14 + 0x1c))) {
        *(uint *)(lVar14 + 0x20) = uVar15;
        KeReleaseSpinLock(plVar13[3],CONCAT31((int3)(uVar15 >> 8),uVar8));
        bVar6 = true;
        uVar8 = KeAcquireSpinLockRaiseToDpc(plVar13[10]);
        lVar14 = plVar13[10];
        uVar15 = *(int *)(lVar14 + 0x20) + (uVar1 - 1);
        uVar9 = (ulonglong)uVar15;
        if ((uVar1 - 1 <= uVar15) && (uVar15 < *(uint *)(lVar14 + 0x1c))) {
          *(uint *)(lVar14 + 0x20) = uVar15;
          KeReleaseSpinLock(plVar13[10],CONCAT31((int3)(uVar15 >> 8),uVar8));
          bVar7 = true;
          RtlAcquireWriteLock(*(longlong *)(param_1 + 0x10));
          if (*(longlong *)(param_1 + 0x40) == 0) {
            *(byte *)(plVar13 + 0xf) = *(byte *)(plVar13 + 0xf) | 1;
            LOCK();
            UNLOCK();
            *(longlong **)(param_1 + 0x40) = plVar13;
            KeReleaseInStackQueuedSpinLock(&local_48);
            return 0;
          }
          KeReleaseInStackQueuedSpinLock(&local_48);
          uVar16 = 0xc0000184;
          goto LAB_140014ee6;
        }
      }
      KeReleaseSpinLock(lVar14,CONCAT71((int7)(uVar9 >> 8),uVar8));
      uVar16 = 0xc00000ce;
    }
  }
LAB_140014ee6:
  if (plVar13 != (longlong *)0x0) {
    *(byte *)(plVar13 + 0xf) = *(byte *)(plVar13 + 0xf) & 0xfe;
    if ((!bVar6) && (plVar13[3] != 0)) {
      WfpRioDereferenceCqInline(plVar13[3]);
      plVar13[3] = 0;
    }
    if ((!bVar7) && (plVar13[10] != 0)) {
      WfpRioDereferenceCqInline(plVar13[10]);
      plVar13[10] = 0;
    }
    WfpRioCleanupRioState(plVar13);
  }
  if (lVar11 != 0) {
    MmUnlockPages(lVar11);
    IoFreeMdl(lVar11);
  }
  if (lVar10 != 0) {
    MmUnlockPages(lVar10);
    IoFreeMdl(lVar10);
  }
  return uVar16;
}



===== WfpRioDPConfigCreate @ 140014fa4 =====

undefined4 WfpRioDPConfigCreate(undefined8 param_1,longlong param_2)

{
  undefined4 uVar1;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  uVar1 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  RtlAcquireWriteLock(0x14002c508);
  if (DAT_14002c4c1 == '\x01') {
    uVar1 = 0xc000000d;
  }
  else {
    DAT_14002c4c1 = '\x01';
  }
  KeReleaseInStackQueuedSpinLock(&local_28);
  *(undefined4 *)(param_2 + 0x30) = uVar1;
  IofCompleteRequest(param_2,0);
  return uVar1;
}



===== WfpRioDPConfigDispatch @ 140015024 =====

undefined4 WfpRioDPConfigDispatch(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  void *_Src;
  char cVar2;
  uint *puVar3;
  void *_Dst;
  undefined4 uVar4;
  ulonglong _Size;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uVar4 = 0;
  uVar1 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10);
  _Size = (ulonglong)uVar1;
  if ((uVar1 != 0) && (_Src = *(void **)(param_2 + 0x18), _Src != (void *)0x0)) {
    if (*(int *)(*(longlong *)(param_2 + 0xb8) + 0x18) != 0x128000) {
      uVar4 = 0xc000000d;
      goto LAB_14001517f;
    }
    puVar3 = (uint *)ExAllocatePool2(0x40,0x10,0x70646657);
    if (puVar3 != (uint *)0x0) {
      _Dst = (void *)ExAllocatePool2(0x40,_Size,0x70646657);
      if (_Dst == (void *)0x0) {
        uVar4 = 0xc000009a;
      }
      else {
        memmove(_Dst,_Src,_Size);
        cVar2 = RtlValidRelativeSecurityDescriptor(_Dst,_Size,0);
        if (cVar2 != '\0') {
          RtlAcquireWriteLock(0x14002c508);
          if (DAT_14002c4c8 == (uint *)0x0) {
            *puVar3 = uVar1;
            *(void **)(puVar3 + 2) = _Dst;
            DAT_14002c4c8 = puVar3;
            KeReleaseInStackQueuedSpinLock(&local_38);
            goto LAB_14001517f;
          }
          KeReleaseInStackQueuedSpinLock();
        }
        uVar4 = 0xc000000d;
        ExFreePoolWithTag(_Dst,0x70646657);
      }
      ExFreePoolWithTag(puVar3,0x70646657);
      goto LAB_14001517f;
    }
  }
  uVar4 = 0xc000009a;
LAB_14001517f:
  *(undefined4 *)(param_2 + 0x30) = uVar4;
  IofCompleteRequest(param_2,0);
  return uVar4;
}



===== WfpRioDecrementReferenceCount @ 1400151bc =====

void WfpRioDecrementReferenceCount(longlong param_1,undefined8 param_2,undefined *param_3)

{
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  RtlAcquireWriteLock(*(longlong *)(param_1 + 0x10));
  if (*(int *)(param_1 + 0x48) < 1) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + -1;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    param_3 = &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids;
    WPP_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
              &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids,"WfpRioDecrementReferenceCount",
              (char)*(undefined4 *)(param_1 + 0x48));
  }
  if (*(int *)(param_1 + 0x48) == 0) {
    if (*(char *)(param_1 + 0x38) == '\0') {
      MicrosoftTelemetryAssertTriggeredNoArgsKM();
    }
    KeReleaseInStackQueuedSpinLock(&local_28);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,param_3,
               "WfpRioDecrementReferenceCount");
    }
    WfpRioFreeRegDomain(param_1);
  }
  else {
    KeReleaseInStackQueuedSpinLock(&local_28);
  }
  return;
}



===== WfpRioDestroyCq @ 1400152c4 =====

undefined8 WfpRioDestroyCq(longlong param_1,ulonglong param_2,uint param_3,char param_4)

{
  undefined8 uVar1;
  
  if (param_3 < 8) {
    uVar1 = 0xc000000d;
  }
  else {
    if ((param_4 != '\0') && ((param_2 & 3) != 0)) {
                    /* WARNING: Subroutine does not return */
      ExRaiseDatatypeMisalignment();
    }
    uVar1 = WfpRioInvalidateCq(param_1,*(uint *)(param_2 + 4),'\0');
  }
  return uVar1;
}



===== WfpRioFindExistingRegDomainForPackage @ 140015354 =====

undefined8 *
WfpRioFindExistingRegDomainForPackage
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  puVar3 = RegDomainList;
  uVar4 = param_3;
  if ((undefined8 **)RegDomainList != &RegDomainList) {
    do {
      uVar1 = Feature_VPN_BugFixes_25A__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar1 == 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                  &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids);
        }
        uVar4 = param_2;
        uVar2 = WfpRioMatchRegDomain((longlong)puVar3,param_1,param_2,(int)param_3,param_4);
        if ((char)uVar2 != '\0') {
          return puVar3;
        }
        puVar3 = (undefined8 *)*puVar3;
      }
      else {
        local_38 = 0;
        uStack_30 = 0;
        local_28 = 0;
        RtlAcquireWriteLock(puVar3[2]);
        if (*(int *)((longlong)puVar3 + 0x4c) != 3) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,uVar4,
                     "WfpRioFindExistingRegDomainForPackage");
          }
          uVar4 = param_2;
          uVar2 = WfpRioMatchRegDomain((longlong)puVar3,param_1,param_2,(int)param_3,param_4);
          if ((char)uVar2 != '\0') {
            *(int *)(puVar3 + 9) = *(int *)(puVar3 + 9) + 1;
            KeReleaseInStackQueuedSpinLock(&local_38);
            return puVar3;
          }
        }
        puVar3 = (undefined8 *)*puVar3;
        KeReleaseInStackQueuedSpinLock(&local_38);
      }
    } while ((undefined8 **)puVar3 != &RegDomainList);
  }
  return (undefined8 *)0x0;
}



===== WfpRioFlushRq @ 1400154c8 =====

void WfpRioFlushRq(longlong param_1,uint param_2)

{
  WfpRioFlushReceiveQueue(param_1,param_2);
  WfpRioFlushSendQueue(param_1,param_2);
  return;
}



===== WfpRioFlushSendQueue @ 1400154f8 =====

void WfpRioFlushSendQueue(longlong param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  uint *puVar5;
  int iVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  int iVar9;
  longlong local_res8;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  lVar4 = *(longlong *)(param_1 + 0x40);
  local_res8 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  puVar5 = *(uint **)(lVar4 + 0x28);
  if (puVar5 != (uint *)0x0) {
    *(undefined1 *)(puVar5 + 2) = 1;
    LOCK();
    UNLOCK();
    uVar1 = *puVar5;
    uVar2 = *(uint *)(lVar4 + 0x30);
    uVar3 = puVar5[1];
    if ((uVar1 < uVar2) && (uVar3 < uVar2)) {
      iVar6 = uVar2 + (uVar3 - uVar1);
      if (uVar1 <= uVar3) {
        iVar6 = uVar3 - uVar1;
      }
      while ((iVar6 != 0 &&
             (uVar7 = WfpRioGetNextQueuedSend(lVar4 + 0x18,&local_28,&local_res8),
             (char)uVar7 != '\0'))) {
        if (*(int *)(lVar4 + 0x44) == *(int *)(lVar4 + 0x30) + -1) {
          iVar9 = 0;
        }
        else {
          iVar9 = *(int *)(lVar4 + 0x44) + 1;
        }
        *(int *)(lVar4 + 0x44) = iVar9;
        *(undefined8 *)(local_res8 + 0x18) = local_18;
        *(undefined4 *)(local_res8 + 0xc) = uStack_20._4_4_;
        *(undefined4 *)(local_res8 + 0x10) = 0;
        *(undefined4 *)(local_res8 + 0x20) = param_2;
        uVar8 = WfpRioQueueSendCompletion
                          ((longlong *)(lVar4 + 0x18),*(undefined8 *)(lVar4 + 0x10),0);
        if (((int)uVar8 < 0) && (-1 < *(int *)(lVar4 + 8))) {
          *(int *)(lVar4 + 8) = (int)uVar8;
        }
        iVar6 = iVar6 + -1;
      }
    }
  }
  return;
}



===== WfpRioFreeRegDomain @ 1400155e8 =====

void WfpRioFreeRegDomain(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x160);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 != 2) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4c,
              &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids);
    }
    KeWaitForSingleObject(param_1 + 0x168,0,0,0,0);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4d,
              &WPP_69b955bb632732390393ed1a04d5aa40_Traceguids);
    }
  }
  ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x10),0x70646657);
  if (*(longlong *)(param_1 + 0x50) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x50),0x70646657);
  }
  if (*(longlong *)(param_1 + 0x58) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x58),0x70646657);
  }
  if (*(longlong *)(param_1 + 0x188) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x188),0x70646657);
  }
  if (*(longlong *)(param_1 + 0x68) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x68),0x70646657);
  }
  if (*(longlong *)(param_1 + 0x198) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x198),0x70646657);
  }
  if (*(longlong *)(param_1 + 0x1a0) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x1a0),0x70646657);
  }
  if (*(longlong *)(param_1 + 0x138) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x138),0x70646657);
  }
  ExFreePoolWithTag(param_1,0x70646657);
  return;
}



===== WfpRioGetProcessIdFromProfileName @ 140015780 =====

void WfpRioGetProcessIdFromProfileName(longlong param_1,undefined4 *param_2)

{
  ulonglong uVar1;
  
  uVar1 = Feature_VPN_BugFixes_25A__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar1 == 0) {
    WfpRioGetProcessIdFromProfileName_old(param_1,param_2);
  }
  else {
    WfpRioGetProcessIdFromProfileName_2503(param_1,param_2);
  }
  return;
}



===== WfpRioGetProcessIdFromProfileName_2503 @ 1400157c0 =====

uint WfpRioGetProcessIdFromProfileName_2503(longlong param_1,undefined4 *param_2)

{
  bool bVar1;
  undefined4 uVar2;
  longlong lVar3;
  undefined8 *puVar4;
  longlong lVar5;
  undefined1 local_res18 [8];
  undefined1 local_res20 [8];
  
  bVar1 = false;
  local_res20[0] = 0;
  lVar5 = -1;
  local_res18[0] = 0;
  do {
    lVar5 = lVar5 + 1;
  } while (*(short *)(param_1 + lVar5 * 2) != 0);
  lVar5 = lVar5 * 2;
  RtlAcquireReadLock(0x14002c670,local_res20);
  for (puVar4 = RegDomainList; (undefined8 **)puVar4 != &RegDomainList;
      puVar4 = (undefined8 *)*puVar4) {
    RtlAcquireReadLock(puVar4[2],local_res18);
    if ((*(int *)((longlong)puVar4 + 0x4c) == 1) &&
       (lVar5 == (ulonglong)*(uint *)(puVar4 + 0xc) - 0x12)) {
      lVar3 = RtlCompareMemory(param_1,puVar4[0xd] + 0x14,lVar5);
      if (lVar3 == lVar5) {
        uVar2 = PsGetProcessId(puVar4[0x35]);
        *param_2 = uVar2;
        bVar1 = true;
      }
    }
    RtlReleaseReadLock(puVar4[2],local_res18[0]);
    if (bVar1) break;
  }
  RtlReleaseReadLock(0x14002c670,local_res20[0]);
  return ~-(uint)bVar1 & 0xc0000034;
}



===== WfpRioGetProcessIdFromProfileName_old @ 1400158bc =====

uint WfpRioGetProcessIdFromProfileName_old(longlong param_1,undefined4 *param_2)

{
  byte bVar1;
  undefined4 uVar2;
  longlong lVar3;
  undefined8 *puVar4;
  longlong lVar5;
  undefined1 local_res18 [8];
  undefined1 local_res20 [8];
  
  bVar1 = 0;
  local_res20[0] = 0;
  lVar5 = -1;
  local_res18[0] = 0;
  do {
    lVar5 = lVar5 + 1;
  } while (*(short *)(param_1 + lVar5 * 2) != 0);
  lVar5 = lVar5 * 2;
  RtlAcquireReadLock(0x14002c670,local_res20);
  puVar4 = RegDomainList;
  do {
    if ((undefined8 **)puVar4 == &RegDomainList) {
LAB_14001598b:
      RtlReleaseReadLock(0x14002c670,local_res20[0]);
      return ~-(uint)bVar1 & 0xc0000034;
    }
    if ((lVar5 == (ulonglong)*(uint *)(puVar4 + 0xc) - 0x12) &&
       (lVar3 = RtlCompareMemory(param_1,puVar4[0xd] + 0x14,lVar5), lVar3 == lVar5)) {
      RtlAcquireReadLock(puVar4[2],local_res18);
      if (*(int *)((longlong)puVar4 + 0x4c) == 1) {
        uVar2 = PsGetProcessId(puVar4[0x35]);
        bVar1 = 1;
        *param_2 = uVar2;
        RtlReleaseReadLock(puVar4[2],local_res18[0]);
        goto LAB_14001598b;
      }
      RtlReleaseReadLock(puVar4[2],local_res18[0]);
    }
    puVar4 = (undefined8 *)*puVar4;
  } while( true );
}



===== WfpRioIdleDpcHandler @ 1400159c0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WfpRioIdleDpcHandler(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  int *piVar1;
  int iVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  RtlAcquireWriteLock(*(longlong *)(param_2 + 0x10));
  *(uint *)(param_2 + 0xb8) = *(uint *)(param_2 + 0xb8) & 0xfffffff7;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,param_3,param_2);
  }
  if (((*(char *)(param_2 + 0x180) == '\0') && ((*(uint *)(param_2 + 0xb8) & 1) != 0)) &&
     ((*(uint *)(param_2 + 0xb8) & 2) != 0)) {
    uVar4 = _DAT_fffff78000000008;
    if (_DAT_fffff78000000008 <
        (ulonglong)(*(longlong *)(param_2 + 0xc0) - *(longlong *)(param_2 + 0xd0))) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)
         ) {
        uVar4 = 0x14;
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,param_3,param_2);
      }
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)
         ) {
        uVar4 = 0x15;
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,param_3,param_2);
      }
      uVar3 = WfpRioQueueActivityEvent(param_2);
      if (-1 < (int)uVar3) goto LAB_140015acf;
    }
    WfpSetActivityTimerDpc(param_2,uVar4,param_3);
  }
LAB_140015acf:
  KeReleaseInStackQueuedSpinLock(&local_28);
  LOCK();
  piVar1 = (int *)(param_2 + 0x140);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -2;
  UNLOCK();
  if (iVar2 == 3) {
    KeSetEvent(param_2 + 0x148,0,0);
  }
  return;
}



===== WfpRioInitializeActivityTracking @ 140015b1c =====

undefined4
WfpRioInitializeActivityTracking(longlong param_1,ulonglong param_2,undefined8 param_3,char param_4)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  ulonglong uVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined4 local_38;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  if ((uint)param_3 < 8) {
                    /* WARNING: Subroutine does not return */
    ExRaiseStatus(0xc000000d);
  }
  if ((param_4 != '\0') && ((param_2 & 3) != 0)) {
                    /* WARNING: Subroutine does not return */
    ExRaiseDatatypeMisalignment();
  }
  uVar1 = *(uint *)(param_2 + 4);
  local_38 = 0;
  RtlAcquireWriteLock(*(longlong *)(param_1 + 0x10));
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,param_3,param_1,(char)uVar1);
  }
  if (*(char *)(param_1 + 0x180) == '\0') {
    if (uVar1 == 0) {
      uVar1 = *(uint *)(param_1 + 0xb8);
      *(uint *)(param_1 + 0xb8) = uVar1 & 0xfffffff8;
      if (((uVar1 & 8) != 0) && (cVar3 = KeCancelTimer(param_1 + 0x78), cVar3 != '\0')) {
        LOCK();
        *(int *)(param_1 + 0x140) = *(int *)(param_1 + 0x140) + -2;
        UNLOCK();
        *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) & 0xfffffff7;
      }
      *(undefined8 *)(param_1 + 0xc0) = 0;
      *(undefined8 *)(param_1 + 200) = 0;
      *(undefined4 *)(param_1 + 0xd8) = 0;
      *(undefined8 *)(param_1 + 0xe8) = 0;
      *(undefined8 *)(param_1 + 0xf0) = 0;
      *(undefined8 *)(param_1 + 0xd0) = 0;
    }
    else {
      if (0xd < uVar1 - 0xc) {
        local_38 = 0xc000000d;
        goto LAB_140015cd1;
      }
      uVar2 = *(uint *)(param_1 + 0xb8);
      uVar5 = uVar2 & 0xfffffffb | 3;
      uVar6 = (ulonglong)uVar5;
      *(uint *)(param_1 + 0xb8) = uVar5;
      *(ulonglong *)(param_1 + 0xd0) = (ulonglong)uVar1 * -10000000;
      uVar4 = (ulonglong)(uVar1 * 40000000) / 5;
      *(ulonglong *)(param_1 + 0xe0) = uVar4;
      if ((uVar2 & 8) != 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          uVar4 = 0x22;
          WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,uVar6,param_1);
        }
        cVar3 = KeCancelTimer(param_1 + 0x78);
        if (cVar3 == '\0') goto LAB_140015d4b;
        LOCK();
        *(int *)(param_1 + 0x140) = *(int *)(param_1 + 0x140) + -2;
        UNLOCK();
        *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) & 0xfffffff7;
      }
      WfpRioTrackIdle(param_1,uVar4,uVar6);
    }
LAB_140015d4b:
    KeReleaseInStackQueuedSpinLock(&local_28);
  }
  else {
    local_38 = 0xc0000008;
LAB_140015cd1:
    KeReleaseInStackQueuedSpinLock(&local_28);
  }
  return local_38;
}



===== WfpRioInitializeRegDomainFieldsNewHandle @ 140015d7c =====

undefined8 WfpRioInitializeRegDomainFieldsNewHandle(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  uVar3 = 0;
  lVar1 = ExAllocatePool2(0x40,0x40,0x70646657);
  if (lVar1 == 0) {
    uVar3 = 0xc000009a;
  }
  else {
    lVar2 = ExAllocatePool2(0x40,0x40,0x70646657);
    if (lVar2 == 0) {
      uVar3 = 0xc000009a;
      ExFreePoolWithTag(lVar1,0x70646657);
    }
    else {
      *(longlong *)(param_1 + 0x18) = lVar2;
      *(undefined8 *)(param_1 + 0x28) = 8;
      *(longlong *)(param_1 + 0x20) = lVar1;
      *(undefined8 *)(param_1 + 0x30) = 8;
      *(undefined1 *)(param_1 + 0x38) = 0;
    }
  }
  return uVar3;
}



===== WfpRioInvalidateCq @ 140015e34 =====

undefined8 WfpRioInvalidateCq(longlong param_1,uint param_2,char param_3)

{
  ulonglong *puVar1;
  undefined1 uVar2;
  longlong lVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  if (param_3 == '\0') {
    RtlAcquireWriteLock(*(longlong *)(param_1 + 0x10));
  }
  uVar5 = 0;
  lVar3 = WfpRioFindCqUnderLock(param_1,param_2,'\0');
  if (lVar3 != 0) {
    puVar1 = (ulonglong *)(*(longlong *)(param_1 + 0x20) + (ulonglong)param_2 * 8);
    *puVar1 = *puVar1 & uVar5;
  }
  if (param_3 == '\0') {
    KeReleaseInStackQueuedSpinLock(&local_28);
  }
  if (lVar3 == 0) {
    uVar4 = 0xc000000d;
  }
  else {
    uVar2 = KeAcquireSpinLockRaiseToDpc(lVar3);
    *(undefined4 *)(lVar3 + 0x2c) = 1;
    MmUnlockPages(*(undefined8 *)(lVar3 + 8));
    IoFreeMdl(*(undefined8 *)(lVar3 + 8));
    *(undefined8 *)(lVar3 + 8) = 0;
    *(undefined8 *)(lVar3 + 0x10) = 0;
    if ((*(uint *)(lVar3 + 0x38) & 2) != 0) {
      ObfDereferenceObject(*(undefined8 *)(lVar3 + 0x30));
      *(uint *)(lVar3 + 0x38) = *(uint *)(lVar3 + 0x38) & 0xfffffffd;
    }
    KeReleaseSpinLock(lVar3,uVar2);
    WfpRioDereferenceCqInline(lVar3);
    uVar4 = 0;
  }
  return uVar4;
}



===== WfpRioQueueActivityEvent @ 140015f48 =====

undefined8 WfpRioQueueActivityEvent(longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  
  uVar3 = 0;
  lVar1 = IoAllocateWorkItem(*(undefined8 *)(param_1 + 0x1b0));
  if (lVar1 == 0) {
    uVar3 = 0xc000009a;
  }
  else {
    uVar2 = RoReferenceEx((uint *)(param_1 + 0x140));
    if ((char)uVar2 == '\0') {
      IoFreeWorkItem(lVar1);
    }
    else {
      IoQueueWorkItemEx(lVar1,WfpRioWorkQueueHandler,1,param_1);
    }
  }
  return uVar3;
}



===== WfpRioSwitchToActive @ 140015fcc =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 WfpRioSwitchToActive(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined1 uVar6;
  
  uVar3 = _DAT_fffff78000000008;
  uVar6 = 0;
  lVar1 = *(longlong *)(param_1 + 200);
  uVar4 = lVar1 + 600000000;
  if (uVar4 < _DAT_fffff78000000008) {
    *(undefined4 *)(param_1 + 0xd8) = 1;
    *(ulonglong *)(param_1 + 200) = uVar4;
    *(ulonglong *)(param_1 + 0xf0) = uVar3;
    *(ulonglong *)(param_1 + 0xe8) = uVar3 - uVar4;
    goto LAB_140016075;
  }
  *(int *)(param_1 + 0xd8) = *(int *)(param_1 + 0xd8) + 1;
  lVar2 = *(longlong *)(param_1 + 0xf0);
  if (lVar2 == 0) {
LAB_14001602f:
    uVar5 = uVar3 - lVar1;
    *(ulonglong *)(param_1 + 0xe8) = uVar5;
  }
  else {
    uVar5 = *(ulonglong *)(param_1 + 0xe8);
    uVar4 = uVar3 - lVar2;
    lVar1 = lVar2;
    if (uVar5 < uVar4) goto LAB_14001602f;
  }
  *(ulonglong *)(param_1 + 0xf0) = uVar3;
  if ((4 < *(int *)(param_1 + 0xd8)) && (uVar5 < *(ulonglong *)(param_1 + 0xe0))) {
    uVar6 = 1;
  }
LAB_140016075:
  return CONCAT71((int7)(uVar4 >> 8),uVar6);
}



===== WfpRioUninitialize @ 140016088 =====

void WfpRioUninitialize(void)

{
  if (DAT_14002c4b8 != 0) {
    ExUnsubscribeWnfStateChange();
  }
  if (WfpRioNetBufferListPool == 0) {
    NdisFreeNetBufferListPool(0);
  }
  if (WfpRioNdisObject != 0) {
    NdisFreeGenericObject();
  }
  return;
}



===== WfpRioWorkQueueHandler @ 1400160e0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WfpRioWorkQueueHandler(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  int *piVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  uVar4 = param_3;
  iVar2 = BiSignalEvent();
  puVar3 = &local_28;
  if (iVar2 < 0) {
    RtlAcquireWriteLock(*(longlong *)(param_2 + 0x10));
    WfpRioTrackIdle(param_2,puVar3,uVar4);
  }
  else {
    RtlAcquireWriteLock(*(longlong *)(param_2 + 0x10));
    if ((*(uint *)(param_2 + 0xb8) & 1) != 0) {
      *(undefined8 *)(param_2 + 200) = 0;
      *(undefined8 *)(param_2 + 0xc0) = 0;
      *(undefined4 *)(param_2 + 0xd8) = 0;
      *(undefined8 *)(param_2 + 0xe8) = 0;
      *(undefined8 *)(param_2 + 0xf0) = 0;
      *(uint *)(param_2 + 0xb8) = *(uint *)(param_2 + 0xb8) & 0xfffffffd | 4;
      *(undefined8 *)(param_2 + 200) = _DAT_fffff78000000008;
    }
  }
  KeReleaseInStackQueuedSpinLock(&local_28);
  IoFreeWorkItem(param_3);
  LOCK();
  piVar1 = (int *)(param_2 + 0x140);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -2;
  UNLOCK();
  if (iVar2 == 3) {
    KeSetEvent(param_2 + 0x148,0,0);
  }
  return;
}



===== WfpSetActivityTimerDpc @ 1400161e8 =====

void WfpSetActivityTimerDpc(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  ulonglong uVar1;
  
  if ((*(uint *)(param_1 + 0xb8) & 8) == 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,param_3,param_1);
    }
    uVar1 = RoReferenceEx((uint *)(param_1 + 0x140));
    if ((char)uVar1 != '\0') {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)
         ) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,param_3,param_1);
      }
      KeSetTimer(param_1 + 0x78,*(undefined8 *)(param_1 + 0xd0),param_1 + 0xf8);
      *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) | 8;
    }
  }
  return;
}



===== EdpEnterpriseResultCallback @ 1400162b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EdpEnterpriseResultCallback(PRPC_ASYNC_STATE param_1,undefined8 param_2,int param_3)

{
  short *psVar1;
  short sVar2;
  RPC_STATUS RVar3;
  short *psVar4;
  longlong lVar5;
  uint local_res18 [4];
  undefined8 local_18;
  short *psStack_10;
  
  if (param_3 != 4) {
    local_res18[0] = 0;
    local_18 = 0;
    psStack_10 = (short *)0x0;
    RVar3 = RpcAsyncCompleteCall(param_1,local_res18);
    *(RPC_STATUS *)(param_1->Reserved + 1) = RVar3;
    if ((local_res18[0] == 0) && (psVar1 = param_1[1].RuntimeInfo, psVar1 != (short *)0x0)) {
      lVar5 = 0x7fff;
      psVar4 = psVar1;
      do {
        if (*psVar4 == 0) break;
        psVar4 = psVar4 + 1;
        lVar5 = lVar5 + -1;
      } while (lVar5 != 0);
      local_res18[0] = ~-(uint)(lVar5 != 0) & 0xc000000d;
      if (lVar5 != 0) {
        sVar2 = (0x7fff - (short)lVar5) * 2;
        local_18._0_4_ = CONCAT22(sVar2 + 2,sVar2);
        psStack_10 = psVar1;
      }
      if ((int)local_res18[0] < 0) {
        local_18 = local_18 & 0xffffffff00000000;
        psStack_10 = (short *)0x0;
      }
      else if (local_res18[0] == 0) {
        (*(code *)param_1->Reserved[2])(param_1->Reserved[3],&local_18);
      }
      ExFreePoolWithTag(param_1[1].RuntimeInfo,0x6f706445);
      param_1[1].RuntimeInfo = (void *)0x0;
    }
    KeSetEvent(param_1 + 1,0,0);
  }
  return;
}



===== EdpGetEnterpriseIdSyncCallback @ 1400163d0 =====

void EdpGetEnterpriseIdSyncCallback(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  void *_Dst;
  
  if (param_1 != (undefined8 *)0x0) {
    *param_1 = 0;
    param_1[1] = 0;
    _Dst = (void *)ExAllocatePool2(0x40,*(undefined2 *)((longlong)param_2 + 2),0x6f706445);
    if (_Dst != (void *)0x0) {
      memmove(_Dst,(void *)param_2[1],(ulonglong)*(ushort *)((longlong)param_2 + 2));
      uVar1 = param_2[1];
      *param_1 = *param_2;
      param_1[1] = uVar1;
      param_1[1] = _Dst;
    }
  }
  return;
}



===== EdpRpcBindingBind @ 140016448 =====

int EdpRpcBindingBind(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  iVar1 = RpcBindingBind(0,param_1,&DAT_140022720);
  if (iVar1 < 0) {
    WfpReportSysErrorAsNtStatus(uVar2,"RpcBindingBind",iVar1);
  }
  return iVar1;
}



===== EdpRpcBindingCreateLocal @ 14001648c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int EdpRpcBindingCreateLocal(undefined8 *param_1)

{
  int iVar1;
  longlong lVar2;
  undefined8 *puVar3;
  char *pcVar4;
  undefined1 auStack_c8 [32];
  undefined8 *local_a8;
  undefined4 local_a0;
  undefined8 local_9c;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined8 local_88;
  undefined4 *local_80;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_c8;
  *param_1 = 0;
  local_a8 = (undefined8 *)0x0;
  local_9c = 0;
  local_4c = 0;
  local_70 = 0;
  local_94 = 0;
  puVar3 = &local_48;
  local_88 = 0;
  local_18 = 0;
  local_48 = 1;
  local_58 = &DAT_140023258;
  local_80 = &local_78;
  local_38 = 0;
  uStack_30 = 0;
  uStack_40 = 3;
  local_28 = 0;
  uStack_20 = 0;
  local_78 = 4;
  local_68 = 0;
  uStack_60 = 0;
  local_74 = 1;
  local_6c = 2;
  local_50 = 1;
  local_a0 = 1;
  local_90 = 6;
  local_8c = 10;
  iVar1 = RpcBindingCreateW(puVar3,&local_a0,0,&local_a8);
  if (iVar1 < 0) {
    pcVar4 = "RpcBindingCreateW";
  }
  else {
    puVar3 = local_a8;
    iVar1 = RpcBindingSetOption(local_a8,9,1);
    if (-1 < iVar1) {
      *param_1 = local_a8;
      return iVar1;
    }
    pcVar4 = "RpcBindingSetOption";
  }
  lVar2 = WfpReportSysErrorAsNtStatus(puVar3,pcVar4,iVar1);
  if ((lVar2 != 0) && (local_a8 != (undefined8 *)0x0)) {
    RpcBindingFree(&local_a8);
  }
  return iVar1;
}



===== MIDL_fw_allocate @ 1400165f0 =====

void MIDL_fw_allocate(undefined8 param_1)

{
  ExAllocatePool2(0x40,param_1,0x6f706445);
  return;
}



===== MIDL_fw_free @ 140016620 =====

void MIDL_fw_free(undefined8 param_1)

{
  ExFreePoolWithTag(param_1,0x6f706445);
  return;
}



===== RPC_NetworkIsolationGetEnterpriseIdAsync @ 140016644 =====

void RPC_NetworkIsolationGetEnterpriseIdAsync(undefined8 param_1)

{
  Ndr64AsyncClientCall((MIDL_STUBLESS_PROXY_INFO *)&PTR_PTR_1400226e8,1,(void *)0x0);
  return;
}



===== LwfvSwitchAttach @ 1400166a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int LwfvSwitchAttach(undefined8 param_1,undefined8 param_2,longlong param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  code *pcVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  bool bVar6;
  undefined1 uVar7;
  undefined4 uVar8;
  int iVar9;
  undefined8 *puVar10;
  longlong lVar11;
  undefined8 uVar12;
  undefined8 *puVar13;
  undefined1 *puVar14;
  undefined1 auStackY_a8 [8];
  undefined1 auStackY_a0 [24];
  undefined8 local_68 [4];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_a8;
  bVar4 = false;
  bVar3 = false;
  if ((DAT_14002c2e0 != 0) && (5 < DAT_14002c2e0)) {
    lVar11 = param_3;
    cVar5 = _tlgKeywordOn(0x14002c2e0,0x200000000000);
    if (cVar5 != '\0') {
      _tlgWriteTransfer_EtwWriteTransfer(0x14002c2e0,&DAT_140028f8d,lVar11,param_4,2,local_68);
    }
  }
  puVar10 = (undefined8 *)ExAllocatePool2(0x40,0x3e0,0x6c326c57);
  puVar14 = auStackY_a8;
  if (puVar10 == (undefined8 *)0x0) {
    iVar9 = -0x3fffff66;
    goto LAB_140016b14;
  }
  puVar10[7] = 2;
  puVar10[9] = param_1;
  puVar10[10] = *(undefined8 *)(param_3 + 0x88);
  *(undefined4 *)(puVar10 + 0xb) = *(undefined4 *)(param_3 + 0x18);
  *(undefined4 *)((longlong)puVar10 + 0x5c) = *(undefined4 *)(param_3 + 0x48);
  *(undefined4 *)(puVar10 + 0xc) = *(undefined4 *)(param_3 + 0x4c);
  *(undefined2 *)((longlong)puVar10 + 100) = *(undefined2 *)(param_3 + 0x8e);
  *(undefined1 *)(puVar10 + 8) = 0;
  puVar10[0x28] = 0;
  *(undefined4 *)(puVar10 + 0x29) = 0;
  puVar10[0x79] = 0;
  puVar10[0xe] = 0;
  puVar10[0xf] = 0;
  puVar10[0x10] = 0;
  *(undefined4 *)(puVar10 + 0x12) = 0;
  *(undefined4 *)((longlong)puVar10 + 0x8a) = 0;
  *(undefined2 *)(puVar10 + 0x11) = 0;
  puVar10[0x15] = *(undefined8 *)(param_3 + 8);
  *(undefined1 *)(puVar10 + 0x16) = 0;
  puVar10[0x17] = 0;
  *(undefined4 *)(puVar10 + 0x18) = 0;
  *(undefined4 *)(puVar10 + 0x1b) = 0;
  *(undefined4 *)(puVar10 + 0x1f) = 0;
  puVar10[0x13] = 0;
  uVar8 = GetInterfaceCompartmentId();
  *(undefined4 *)((longlong)puVar10 + 0x3dc) = uVar8;
  lVar11 = IoAllocateWorkItem(DAT_14002ce88);
  puVar10[0x78] = lVar11;
  if (lVar11 == 0) {
LAB_140016834:
    puVar14 = auStackY_a8;
    iVar9 = -0x3fffff66;
  }
  else {
    puVar1 = puVar10 + 0x19;
    puVar10[0x1a] = puVar1;
    *puVar1 = puVar1;
    lVar11 = ExAllocatePool2(0x40,0x790,0x6c326c57);
    puVar10[0x13] = lVar11;
    if (lVar11 == 0) goto LAB_140016834;
    uVar12 = L2InitializeFlowsManager(lVar11);
    if ((int)uVar12 < 0) goto LAB_140016834;
    puVar1 = puVar10 + 6;
    *(undefined4 *)((longlong)puVar10 + 0x67) = *(undefined4 *)(param_3 + 0x62);
    bVar4 = true;
    *(undefined2 *)((longlong)puVar10 + 0x6b) = *(undefined2 *)(param_3 + 0x66);
    KeInitializeSpinLock(puVar1);
    puVar10[0x23] = 0;
    *(undefined1 *)(puVar10 + 0x24) = 0;
    *(undefined4 *)((longlong)puVar10 + 0xdc) = 0;
    KeInitializeEvent(puVar10 + 0x25,0,0);
    KeInitializeEvent(puVar10 + 0x1c,0,0);
    KeInitializeEvent(puVar10 + 0x20,0,0);
    *(undefined4 *)((longlong)puVar10 + 0x14c) = 2;
    _gvSwitchHandlers = 0x7001b8;
    iVar9 = NdisFGetOptionalSwitchHandlers(param_1,puVar10 + 0x14,&gvSwitchHandlers);
    puVar14 = auStackY_a8;
    if (iVar9 == 0) {
      iVar9 = NdisFSetAttributes(param_1);
      puVar14 = auStackY_a8;
      if (iVar9 == 0) {
        iVar9 = LwfvSwitchpInitializevSwitch((longlong)puVar10);
        puVar14 = auStackY_a8;
        if (iVar9 == 0) {
          bVar3 = true;
          bVar6 = LwfvSwitchpIsClassifyNeeded(0x48,puVar10[0xe],0);
          if (bVar6) {
LAB_1400169b7:
            *(uint *)((longlong)puVar10 + 0x11c) = *(uint *)((longlong)puVar10 + 0x11c) | 1;
          }
          else {
            bVar6 = LwfvSwitchpIsClassifyNeeded(0x4a,puVar10[0xe],0);
            if (bVar6) goto LAB_1400169b7;
            bVar6 = LwfvSwitchpIsClassifyNeeded(0x4b,puVar10[0xe],0);
            if (bVar6) goto LAB_1400169b7;
          }
          bVar6 = LwfvSwitchpIsClassifyNeeded(0x49,puVar10[0xe],0);
          if (bVar6) {
            *(uint *)((longlong)puVar10 + 0x11c) = *(uint *)((longlong)puVar10 + 0x11c) | 3;
          }
          else {
            bVar6 = LwfvSwitchpIsClassifyNeeded(0x4c,puVar10[0xe],0);
            if (!bVar6) {
              bVar6 = LwfvSwitchpIsClassifyNeeded(0x4d,puVar10[0xe],0);
              if (!bVar6) goto LAB_140016a0d;
            }
            *(uint *)((longlong)puVar10 + 0x11c) = *(uint *)((longlong)puVar10 + 0x11c) | 2;
          }
LAB_140016a0d:
          L2InitializeNblReferenceRecords((longlong)puVar10);
          uVar7 = KeAcquireSpinLockRaiseToDpc(&DAT_14002ce90);
          puVar14 = auStackY_a8;
          puVar13 = &DAT_14002cec8;
          if ((undefined8 *)*DAT_14002ced0 != &DAT_14002cec8) {
            puVar13 = (undefined8 *)0x3;
            pcVar2 = (code *)swi(0x29);
            uVar7 = (*pcVar2)();
            puVar14 = auStackY_a0;
          }
          *puVar10 = puVar13;
          puVar10[1] = DAT_14002ced0;
          *DAT_14002ced0 = puVar10;
          DAT_14002ced8 = DAT_14002ced8 + 1;
          *(undefined8 *)(puVar14 + -8) = 0x140016a69;
          DAT_14002ced0 = puVar10;
          KeReleaseSpinLock(&DAT_14002ce90,uVar7);
          *(undefined8 *)(puVar14 + -8) = 0x140016a78;
          KeAcquireSpinLockRaiseToDpc(puVar1);
          *(undefined4 *)((longlong)puVar10 + 0x3c) = 1;
          *(undefined8 *)(puVar14 + -8) = 0x140016a90;
          KeReleaseSpinLock(puVar1);
        }
        *(undefined8 *)(puVar14 + -8) = 0x140016aa4;
        KeSetEvent(puVar10 + 0x20,0,0);
        if (iVar9 == 0) goto LAB_140016b14;
        if (bVar3) {
          *(undefined8 *)(puVar14 + -8) = 0x140016abc;
          LwfvSwitchpClosevSwitch((longlong)puVar10,'\0');
        }
      }
    }
  }
  if (puVar10[0x13] != 0) {
    if (bVar4) {
      lVar11 = puVar10[0x13];
      *(undefined8 *)(puVar14 + -8) = 0x140016ad6;
      L2UnInitializeFlowsManager(lVar11);
    }
    uVar12 = puVar10[0x13];
    *(undefined8 *)(puVar14 + -8) = 0x140016ae9;
    ExFreePoolWithTag(uVar12,0x6c326c57);
  }
  if (puVar10[0x78] != 0) {
    uVar12 = puVar10[0x78];
    *(undefined8 *)(puVar14 + -8) = 0x140016b05;
    IoFreeWorkItem(uVar12);
  }
  *(undefined8 *)(puVar14 + -8) = 0x140016b14;
  L2LwfFree((longlong *)(puVar14 + 0x38));
LAB_140016b14:
  *(undefined8 *)(puVar14 + -8) = 0x140016b23;
  return iVar9;
}



===== LwfvSwitchCheckAndRevokeAssignedVfs @ 140016b44 =====

undefined8 LwfvSwitchCheckAndRevokeAssignedVfs(longlong param_1,ushort param_2,longlong param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined1 uVar4;
  bool bVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  
  uVar7 = 0;
  uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x30);
  puVar6 = *(undefined8 **)(param_1 + 200);
  do {
    if (puVar6 == (undefined8 *)(param_1 + 200)) {
      KeReleaseSpinLock(param_1 + 0x30,uVar4);
      return uVar7;
    }
    bVar5 = vSwitchIsIovOffloadPossibleForLayer(param_2,param_1,*(int *)(puVar6 + 5),0,0);
    if (!bVar5) {
      *(undefined1 *)((longlong)puVar6 + 0x471) = 1;
      plVar1 = puVar6 + 2;
      *(int *)(param_1 + 0xdc) = *(int *)(param_1 + 0xdc) + 1;
      plVar2 = *(longlong **)(param_3 + 8);
      if (*plVar2 != param_3) {
        pcVar3 = (code *)swi(0x29);
        (*pcVar3)(3);
        pcVar3 = (code *)swi(3);
        uVar7 = (*pcVar3)();
        return uVar7;
      }
      *plVar1 = param_3;
      uVar7 = 0x103;
      puVar6[3] = plVar2;
      *plVar2 = (longlong)plVar1;
      *(longlong **)(param_3 + 8) = plVar1;
    }
    puVar6 = (undefined8 *)*puVar6;
  } while( true );
}



===== LwfvSwitchCleanupPortDirectory @ 140016c1c =====

void LwfvSwitchCleanupPortDirectory(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  longlong lVar4;
  uint local_28 [2];
  longlong local_20;
  
  if (*(longlong *)(param_1 + 0x80) != 0) {
    local_28[1] = 0;
    uVar3 = 1;
    local_20 = *(longlong *)(param_1 + 0x70) + 10;
    local_28[0] = (uint)*(ushort *)(*(longlong *)(param_1 + 0x70) + 8);
    if (*(int *)(param_1 + 0xd8) != 0) {
      do {
        lVar1 = L2GetvSwitchPortUnsafe(param_1,uVar3);
        if ((lVar1 != 0) && (*(longlong *)(lVar1 + 0x448) != 0)) {
          lVar4 = 0;
          lVar2 = 0x40;
          if (*(int *)(lVar1 + 0x434) != 1) {
            lVar2 = 1;
          }
          do {
            if (*(char *)(lVar4 + 0x8b1 + *(longlong *)(lVar1 + 0x448)) != '\0') {
              vSwitchFlpDerefCompartment(local_28,0);
            }
            lVar4 = lVar4 + 0x8b8;
            lVar2 = lVar2 + -1;
          } while (lVar2 != 0);
          ExFreePoolWithTag(*(undefined8 *)(lVar1 + 0x448),0x70737657);
          *(undefined8 *)(lVar1 + 0x448) = 0;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 <= *(uint *)(param_1 + 0xd8));
    }
    uVar3 = 1;
    if (*(int *)(param_1 + 0xf8) != 0) {
      do {
        lVar1 = L2GetvSwitchPortUnsafe(param_1,uVar3);
        if (lVar1 != 0) {
          if (*(int *)(lVar1 + 0x46c) != 0) {
            vSwitchFlpDerefCompartment(local_28,*(int *)(lVar1 + 0x46c));
          }
          ExFreePoolWithTag(lVar1,0x70737657);
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 <= *(uint *)(param_1 + 0xf8));
    }
    lVar2 = 0;
    lVar1 = 0x100;
    do {
      lVar4 = *(longlong *)(lVar2 + *(longlong *)(param_1 + 0x80));
      if (lVar4 != 0) {
        ExFreePoolWithTag(lVar4,0x70737657);
      }
      lVar2 = lVar2 + 8;
      lVar1 = lVar1 + -1;
    } while (lVar1 != 0);
    ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x80),0x70737657);
  }
  return;
}



===== LwfvSwitchDetach @ 140016dc0 =====

void LwfvSwitchDetach(longlong *param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined1 uVar6;
  longlong *local_res8 [4];
  
  local_res8[0] = param_1;
  uVar6 = KeAcquireSpinLockRaiseToDpc(&DAT_14002ce90);
  lVar3 = *param_1;
  plVar4 = (longlong *)param_1[1];
  if ((*(longlong **)(lVar3 + 8) != param_1) || ((longlong *)*plVar4 != param_1)) {
    pcVar5 = (code *)swi(0x29);
    (*pcVar5)(3);
    pcVar5 = (code *)swi(3);
    (*pcVar5)();
    return;
  }
  *plVar4 = lVar3;
  *(longlong **)(lVar3 + 8) = plVar4;
  DAT_14002ced8 = DAT_14002ced8 + -1;
  KeReleaseSpinLock(&DAT_14002ce90,CONCAT71((int7)((ulonglong)plVar4 >> 8),uVar6));
  LOCK();
  piVar1 = (int *)((longlong)param_1 + 0x14c);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 2) {
    LwfvSwitchpClosevSwitch((longlong)param_1,'\x01');
    if (param_1[0x17] != 0) {
      ExFreePoolWithTag(param_1[0x17],0x67326c57);
    }
    L2UnInitializeFlowsManager(param_1[0x13]);
    ExFreePoolWithTag(param_1[0x13],0x6c326c57);
    IoFreeWorkItem(param_1[0x78]);
    L2LwfFree((longlong *)local_res8);
  }
  return;
}



===== LwfvSwitchEventNotifyComplete @ 140016eb0 =====

void LwfvSwitchEventNotifyComplete(int param_1,longlong param_2,int param_3,int param_4)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 uVar3;
  uint uVar4;
  longlong lVar5;
  bool bVar6;
  
  lVar1 = *(longlong *)(param_2 + 0xe0);
  if (param_1 == 6) {
LAB_140016ef3:
    lVar5 = L2GetvSwitchPortUnsafe(lVar1,*(int *)(*(longlong *)(param_2 + 0x28) + 0x410));
    uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x30);
    bVar6 = *(char *)(lVar5 + 0x471) != '\0';
    if (bVar6) {
      *(longlong *)(lVar5 + 0x478) = param_2;
      *(int *)(lVar5 + 0x474) = param_1;
    }
    KeReleaseSpinLock(lVar1 + 0x30,uVar3);
    if (bVar6) {
      return;
    }
LAB_140016f50:
    if (param_1 - 0xcU < 2) {
      if (-1 < param_3) {
        lVar5 = *(longlong *)(param_2 + 0xd8);
        lVar2 = *(longlong *)(lVar5 + 0x28);
        if (param_1 == 0xc) {
          if (*(short *)(lVar2 + 0x234) == 0) {
            if (param_4 != 0) {
              param_3 = -0x7ffffffb;
              *(int *)(lVar5 + 0x44) = param_4;
            }
          }
          else {
            param_3 = 0;
            *(undefined8 *)(lVar2 + 0x10) = 0x48dff3c5e7c3b2f0;
            *(undefined8 *)(lVar2 + 0x18) = 0x7a2ed7d6fe102baf;
          }
LAB_140016f9c:
          NdisFreeCloneOidRequest(*(undefined8 *)(lVar1 + 0x48),param_2);
          *(undefined8 *)(lVar1 + 0x140) = 0;
          NdisFOidRequestComplete(*(undefined8 *)(lVar1 + 0x48),lVar5,param_3);
          return;
        }
        if (param_1 == 0xd) goto LAB_140016f9c;
        goto LAB_140016fd9;
      }
    }
    else if (-1 < param_3) {
LAB_140016fd9:
      uVar4 = NdisFOidRequest(*(undefined8 *)(lVar1 + 0x48),param_2);
      if (uVar4 == 0x103) {
        return;
      }
      goto LAB_140016ff3;
    }
  }
  else {
    if (param_1 != 5) goto LAB_140016f50;
    if (-1 < param_3) goto LAB_140016ef3;
  }
  uVar4 = 0xc000009a;
LAB_140016ff3:
  LwfvSwitchOidRequestComplete(lVar1,param_2,(ulonglong)uVar4);
  return;
}



===== LwfvSwitchFillInitialPortProperties @ 140017028 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int LwfvSwitchFillInitialPortProperties
              (longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  ushort uVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  longlong lVar6;
  longlong lVar7;
  undefined8 uVar8;
  undefined1 uVar9;
  longlong local_res8;
  uint local_38 [2];
  longlong local_30;
  
  local_res8 = 0;
  uVar9 = 0;
  local_38[1] = 0;
  iVar3 = (*DAT_14002c5d8)(*(undefined8 *)(param_1 + 0xa0),*(undefined4 *)(param_2 + 8));
  if (iVar3 != 0) {
    return 0;
  }
  local_30 = *(longlong *)(param_1 + 0x70) + 10;
  local_38[0] = (uint)*(ushort *)(*(longlong *)(param_1 + 0x70) + 8);
  uVar5 = *(int *)(param_2 + 8) - 1;
  uVar8 = 3;
  lVar2 = *(longlong *)
           (*(longlong *)(*(longlong *)(param_1 + 0x80) + (ulonglong)(uVar5 >> 8) * 8) +
           (ulonglong)(byte)uVar5 * 8);
  iVar3 = LwfvSwitchGetPortProperties(param_1,*(int *)(param_2 + 8),3,param_4,param_3,&local_res8);
  if (iVar3 == 0) {
    if ((local_res8 == 0) || (*(int *)(local_res8 + 0x28) == 0)) {
LAB_140017105:
      ExFreePoolWithTag(local_res8,0x67326c57);
      uVar8 = 2;
      iVar3 = LwfvSwitchGetPortProperties
                        (param_1,*(undefined4 *)(param_2 + 8),2,param_4,param_3,&local_res8);
      if (iVar3 != 0) goto LAB_14001719c;
      lVar6 = local_res8;
      if (((local_res8 == 0) || (*(int *)(local_res8 + 0x28) == 0)) ||
         (lVar7 = (ulonglong)*(uint *)(local_res8 + 0x24) + local_res8,
         uVar5 = *(uint *)((ulonglong)*(uint *)(lVar7 + 0x24) + 0xc + lVar7), uVar5 == 0))
      goto LAB_1400171a1;
      uVar9 = 1;
    }
    else {
      lVar6 = (ulonglong)*(uint *)(local_res8 + 0x24) + local_res8;
      if (*(int *)((ulonglong)*(uint *)(lVar6 + 0x24) + 8 + lVar6) != 1) {
        *(undefined1 *)(lVar2 + 0x468) = 1;
        goto LAB_140017105;
      }
      uVar1 = *(ushort *)((ulonglong)*(uint *)(lVar6 + 0x24) + 0x10 + lVar6);
      if (uVar1 == 0) goto LAB_140017105;
      uVar5 = (uint)uVar1;
    }
    lVar6 = local_res8;
    iVar4 = vSwitchFlpRefOrCreateCompartment(local_38,(ulonglong)uVar5,uVar8);
    if (iVar4 < 0) {
      iVar3 = -0x3fffff66;
    }
    else {
      *(uint *)(lVar2 + 0x46c) = uVar5;
      *(undefined1 *)(lVar2 + 0x470) = uVar9;
    }
  }
  else {
LAB_14001719c:
    lVar6 = local_res8;
  }
LAB_1400171a1:
  (*DAT_14002c5e0)(*(undefined8 *)(param_1 + 0xa0),*(undefined4 *)(param_2 + 8));
  if (lVar6 != 0) {
    ExFreePoolWithTag(lVar6,0x67326c57);
  }
  return iVar3;
}



===== LwfvSwitchGetPortProperties @ 1400171f8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int LwfvSwitchGetPortProperties
              (longlong param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
              undefined8 param_5,longlong *param_6)

{
  int iVar1;
  undefined8 *puVar2;
  undefined1 auStack_188 [32];
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_118;
  undefined8 *local_110;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_f4;
  undefined8 local_58;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_188;
  memset(&local_138,0,0xf8);
  *param_6 = 0;
  local_100 = 0;
  local_168 = 0x180;
  uStack_140 = 0;
  uStack_160 = CONCAT44(param_3,param_2);
  local_148 = 1;
  local_138 = 0xf80196;
  local_134 = 0xc;
  local_118 = 0x10274;
  local_58 = param_5;
  puVar2 = (undefined8 *)ExAllocatePool2(0x40,0x30,0x67326c57);
  if (puVar2 == (undefined8 *)0x0) {
LAB_1400172bb:
    iVar1 = -0x3fffff66;
  }
  else {
    *puVar2 = local_168;
    puVar2[1] = uStack_160;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = local_148;
    puVar2[5] = uStack_140;
    *(undefined2 *)((longlong)puVar2 + 2) = 0x30;
    local_108 = 0x30;
    local_104 = 0x30;
    local_110 = puVar2;
    iVar1 = LwfvSwitchIssueSyncOidRequest(param_1,(longlong)&local_138,param_5);
    if (iVar1 == 0) {
LAB_140017302:
      *param_6 = (longlong)puVar2;
      return 0;
    }
    if (iVar1 == -0x3ffeffec) {
      ExFreePoolWithTag(puVar2,0x67326c57);
      puVar2 = (undefined8 *)ExAllocatePool2(0x40,local_f4,0x67326c57);
      if (puVar2 == (undefined8 *)0x0) goto LAB_1400172bb;
      *puVar2 = local_168;
      puVar2[1] = uStack_160;
      puVar2[2] = 0;
      puVar2[3] = 0;
      puVar2[4] = local_148;
      puVar2[5] = uStack_140;
      *(short *)((longlong)puVar2 + 2) = (short)local_f4;
      local_104 = local_f4;
      local_58 = param_5;
      local_110 = puVar2;
      iVar1 = LwfvSwitchIssueSyncOidRequest(param_1,(longlong)&local_138,param_5);
      if (iVar1 == 0) goto LAB_140017302;
    }
    ExFreePoolWithTag(puVar2,0x67326c57);
  }
  return iVar1;
}



===== LwfvSwitchIssueSyncOidRequest @ 1400173d0 =====

undefined4 LwfvSwitchIssueSyncOidRequest(longlong param_1,longlong param_2,undefined8 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = NdisFOidRequest(*(undefined8 *)(param_1 + 0x48));
  if (uVar2 != 0x103) {
    LwfvSwitchOidRequestComplete(param_1,param_2,(ulonglong)uVar2);
  }
  KeWaitForSingleObject(param_3,0,0,0,0);
  uVar1 = *(undefined4 *)(param_2 + 0xe0);
  *(undefined8 *)(param_2 + 0xe0) = 0;
  return uVar1;
}



===== LwfvSwitchKfdCommitNotify @ 140017450 =====

uint LwfvSwitchKfdCommitNotify(longlong param_1)

{
  longlong lVar1;
  bool bVar2;
  undefined1 uVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  lVar1 = param_1 + 0x30;
  uVar7 = 0;
  bVar2 = false;
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
  uVar6 = *(uint *)(param_1 + 0x118);
  if (((((uVar6 & 1) != 0) &&
       (bVar4 = LwfvSwitchpIsClassifyNeeded(0x48,*(longlong *)(param_1 + 0x70),0), !bVar4)) &&
      (bVar4 = LwfvSwitchpIsClassifyNeeded(0x4a,*(longlong *)(param_1 + 0x70),0), !bVar4)) &&
     (bVar4 = LwfvSwitchpIsClassifyNeeded(0x4b,*(longlong *)(param_1 + 0x70),0), !bVar4)) {
    uVar6 = uVar6 & 0xfffffffe;
  }
  if ((((*(uint *)(param_1 + 0x118) & 2) != 0) &&
      (bVar4 = LwfvSwitchpIsClassifyNeeded(0x49,*(longlong *)(param_1 + 0x70),0), !bVar4)) &&
     ((bVar4 = LwfvSwitchpIsClassifyNeeded(0x4c,*(longlong *)(param_1 + 0x70),0), !bVar4 &&
      (bVar4 = LwfvSwitchpIsClassifyNeeded(0x4d,*(longlong *)(param_1 + 0x70),0), !bVar4)))) {
    uVar6 = uVar6 & 0xfffffffd;
  }
  if (((uVar6 & 2) != 0) &&
     (bVar4 = LwfvSwitchpIsClassifyNeeded(0x49,*(longlong *)(param_1 + 0x70),0x20), bVar4)) {
    uVar6 = uVar6 | 1;
  }
  if (uVar6 != *(uint *)(param_1 + 0x118)) {
    *(uint *)(param_1 + 0x11c) = uVar6;
    if (*(int *)(param_1 + 0x3c) == 1) {
      if (*(char *)(param_1 + 0x40) == '\0') {
        *(undefined1 *)(param_1 + 0x120) = 1;
        KeReleaseSpinLock(lVar1,uVar3);
        return 0x103;
      }
    }
    else if (2 < *(int *)(param_1 + 0x3c) - 2U) goto LAB_140017586;
    bVar2 = true;
    *(undefined1 *)(param_1 + 0x120) = 1;
  }
LAB_140017586:
  KeReleaseSpinLock(lVar1,uVar3);
  if (bVar2) {
    iVar5 = NdisFRestartFilter();
    uVar7 = ~-(uint)(iVar5 != 0) & 0x103;
  }
  return uVar7;
}



===== LwfvSwitchKfdUpdateNotify @ 1400175dc =====

int LwfvSwitchKfdUpdateNotify(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  code *pcVar3;
  uint uVar4;
  undefined1 uVar5;
  bool bVar6;
  int iVar7;
  longlong *plVar8;
  longlong lVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  uint uVar12;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  puVar10 = auStack_38;
  iVar7 = 0;
  puVar11 = auStack_38;
  if (*(char *)(param_1 + 0xb0) == '\0') {
    plVar8 = (longlong *)(param_1 + 0x20);
    lVar9 = *param_2;
    if (*(longlong **)(lVar9 + 8) != param_2) {
      lVar9 = 3;
      pcVar3 = (code *)swi(0x29);
      plVar8 = (longlong *)(*pcVar3)();
      puVar10 = auStack_30;
    }
    *plVar8 = lVar9;
    plVar8[1] = (longlong)param_2;
    *(longlong **)(lVar9 + 8) = plVar8;
    *param_2 = (longlong)plVar8;
    puVar11 = puVar10;
  }
  lVar9 = param_1 + 0x30;
  *(undefined8 *)(puVar11 + -8) = 0x14001762f;
  uVar5 = KeAcquireSpinLockRaiseToDpc(lVar9);
  uVar12 = *(uint *)(param_1 + 0x118);
  if (uVar12 == 3) goto LAB_14001770b;
  if ((uVar12 & 1) == 0) {
    lVar1 = *(longlong *)(param_1 + 0x70);
    *(undefined8 *)(puVar11 + -8) = 0x140017662;
    bVar6 = LwfvSwitchpIsClassifyNeeded(0x48,lVar1,0x20);
    if (!bVar6) {
      lVar1 = *(longlong *)(param_1 + 0x70);
      *(undefined8 *)(puVar11 + -8) = 0x140017676;
      bVar6 = LwfvSwitchpIsClassifyNeeded(0x4a,lVar1,0x20);
      if (!bVar6) {
        lVar1 = *(longlong *)(param_1 + 0x70);
        *(undefined8 *)(puVar11 + -8) = 0x14001768a;
        bVar6 = LwfvSwitchpIsClassifyNeeded(0x4b,lVar1,0x20);
        if (!bVar6) goto LAB_140017691;
      }
    }
    uVar12 = uVar12 | 1;
  }
LAB_140017691:
  if ((*(uint *)(param_1 + 0x118) & 2) == 0) {
    lVar1 = *(longlong *)(param_1 + 0x70);
    *(undefined8 *)(puVar11 + -8) = 0x1400176ac;
    bVar6 = LwfvSwitchpIsClassifyNeeded(0x49,lVar1,0x20);
    lVar1 = *(longlong *)(param_1 + 0x70);
    uVar4 = uVar12 | 3;
    if (!bVar6) {
      uVar4 = uVar12;
    }
    uVar12 = uVar4;
    *(undefined8 *)(puVar11 + -8) = 0x1400176c9;
    bVar6 = LwfvSwitchpIsClassifyNeeded(0x4c,lVar1,0x20);
    if (!bVar6) {
      lVar1 = *(longlong *)(param_1 + 0x70);
      *(undefined8 *)(puVar11 + -8) = 0x1400176de;
      bVar6 = LwfvSwitchpIsClassifyNeeded(0x4d,lVar1,0x20);
      if (!bVar6) goto LAB_1400176e5;
    }
    uVar12 = uVar12 | 2;
  }
LAB_1400176e5:
  if (uVar12 != *(uint *)(param_1 + 0x118)) {
    *(uint *)(param_1 + 0x11c) = uVar12;
    if (*(int *)(param_1 + 0x3c) == 1) {
      if (*(char *)(param_1 + 0x40) != '\0') {
LAB_140017741:
        *(undefined1 *)(param_1 + 0x120) = 1;
        *(undefined8 *)(puVar11 + -8) = 0x140017755;
        KeReleaseSpinLock(lVar9,uVar5);
        uVar2 = *(undefined8 *)(param_1 + 0x48);
        *(undefined8 *)(puVar11 + -8) = 0x140017765;
        iVar7 = NdisFRestartFilter(uVar2);
        if (iVar7 == 0) {
          return 0x103;
        }
        if ((((iVar7 == 0x103) || (iVar7 == -0x7ffffffb)) || (iVar7 == -0x3fffffff)) ||
           ((iVar7 == -0x3fffff66 || (iVar7 == -0x3fffff45)))) {
          return iVar7;
        }
        if (iVar7 == -0x3ffeffea) {
          return -0x3fffffdd;
        }
        if (iVar7 == -0x3ffeffec) {
          return -0x3ffffdfa;
        }
        if (iVar7 == -0x3ffeffeb) {
          return -0x3ffffff3;
        }
        return -0x3fffffff;
      }
      *(undefined1 *)(param_1 + 0x120) = 1;
      iVar7 = 0x103;
    }
    else if (*(int *)(param_1 + 0x3c) - 2U < 3) goto LAB_140017741;
  }
LAB_14001770b:
  *(undefined8 *)(puVar11 + -8) = 0x140017718;
  KeReleaseSpinLock(lVar9,uVar5);
  return iVar7;
}



===== LwfvSwitchNetPnPEvent @ 1400177e0 =====

void LwfvSwitchNetPnPEvent(longlong param_1,longlong param_2)

{
  int iVar1;
  
  if (((*(int *)(param_2 + 8) == 0x11) && (*(longlong *)(param_1 + 0x80) == 0)) &&
     (iVar1 = LwfvSwitchpInitializevSwitchConfig(param_1), iVar1 != 0)) {
    return;
  }
  NdisFNetPnPEvent(*(undefined8 *)(param_1 + 0x48),param_2);
  return;
}



===== LwfvSwitchRecvNetBufferLists @ 140017830 =====

void LwfvSwitchRecvNetBufferLists
               (longlong ***param_1,longlong ***param_2,uint param_3,int param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  ulonglong uVar3;
  longlong ***ppplVar4;
  longlong **pplVar5;
  longlong **local_res8;
  longlong ***local_res10;
  uint local_res18;
  int local_res20 [2];
  
  local_res8 = (longlong **)0x0;
  local_res10 = param_2;
  local_res18 = param_3;
  local_res20[0] = param_4;
  LwfvSwitchpHandleReroutedEgressNBLs
            ((longlong)param_1,param_3,param_5,local_res20,(longlong ***)&local_res10);
  iVar1 = KfdIsLayerEmpty(0x49);
  pplVar5 = (longlong **)0x0;
  if (iVar1 == 0) {
    if (local_res10 == (longlong ***)0x0) {
      return;
    }
    L2InspectNetBufferLists
              (2,0x49,(longlong *)&local_res10,local_res20,(longlong *)0x0,(int *)0x0,
               (longlong *)&local_res8,(longlong *)param_1,param_3,param_5);
    pplVar5 = local_res8;
  }
  ppplVar4 = local_res10;
  if (local_res10 != (longlong ***)0x0) {
    iVar1 = KfdIsLayerEmpty(0x4c);
    iVar2 = KfdIsLayerEmpty(0x4d);
    local_res8 = (longlong **)0x0;
    if ((iVar1 == 0) || (iVar2 == 0)) {
      uVar3 = Feature_Firewall_BugFixes_25D_WFPlwfs_L28023_resilience__private_IsEnabledDeviceUsageNoInline
                        ();
      if ((int)uVar3 == 0) {
        vSwitchInspectL3NetBufferLists
                  (param_1,2,iVar1 == 0,iVar2 == 0,(longlong ***)&local_res10,local_res20,
                   &local_res8,param_5);
      }
      else {
        vSwitchInspectL3NetBufferLists_25D
                  (param_1,2,iVar1 == 0,iVar2 == 0,(longlong ***)&local_res10,local_res20,
                   &local_res8,param_5);
      }
      if (local_res8 != (longlong **)0x0) {
        NdisFReturnNetBufferLists(param_1[9],local_res8,param_5 & 1);
      }
      ppplVar4 = local_res10;
    }
    if (ppplVar4 != (longlong ***)0x0) {
      L2NdisFIndicateReceiveNetBufferLists
                ((longlong)param_1,param_1[9],ppplVar4,local_res18,local_res20[0],param_5);
    }
  }
  if (pplVar5 != (longlong **)0x0) {
    NdisFReturnNetBufferLists(param_1[9],pplVar5,param_5 & 1);
  }
  return;
}



===== LwfvSwitchReorderEventNotifyComplete @ 1400179e0 =====

void LwfvSwitchReorderEventNotifyComplete(longlong *param_1,int param_2)

{
  longlong lVar1;
  byte bVar2;
  undefined4 uVar3;
  
  lVar1 = *param_1;
  uVar3 = 0;
  if (param_2 < 0) {
    uVar3 = 0xc000009a;
  }
  else {
    *(undefined4 *)(lVar1 + 0x3c) = 3;
    *(undefined1 *)(lVar1 + 0x40) = 0;
  }
  ExFreePoolWithTag(param_1[1],0x67326c57);
  ExFreePoolWithTag(param_1,0x67326c57);
  bVar2 = KeGetCurrentIrql();
  if (bVar2 < 2) {
    NdisFRestartComplete(*(undefined8 *)(lVar1 + 0x48));
  }
  else {
    L2QueueRestartCompleteWorkItem(lVar1,uVar3);
  }
  return;
}



===== LwfvSwitchRestart @ 140017a80 =====

ulonglong LwfvSwitchRestart(longlong param_1,longlong param_2)

{
  undefined4 uVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong *plVar5;
  ulonglong uVar6;
  undefined4 local_res8 [2];
  undefined4 local_res18 [2];
  
  local_res8[0] = 0;
  local_res18[0] = 0;
  if ((*(int *)(param_1 + 0x5c) != 0) && (*(int *)(param_2 + 4) == 0)) {
    *(undefined4 *)(param_1 + 0x5c) = 0;
  }
  NdisEnumerateFilterModules(*(undefined8 *)(param_1 + 0x48),0,0,local_res8,local_res18);
  uVar1 = local_res8[0];
  lVar3 = ExAllocatePool2(0x40,local_res8[0],0x67326c57);
  if (lVar3 == 0) {
    return 0xc000009a;
  }
  NdisEnumerateFilterModules(*(undefined8 *)(param_1 + 0x48),lVar3,uVar1,local_res8,local_res18);
  uVar4 = LwfvSwitchpIsInRequiredPosition(param_1,lVar3,(undefined1 *)(param_1 + 0xb0));
  uVar6 = uVar4 & 0xffffffff;
  if ((int)uVar4 == 0) {
    L2FirevSwitchEvent(param_1,4);
    plVar5 = (longlong *)ExAllocatePool2(0x40,0x10,0x67326c57);
    if (plVar5 != (longlong *)0x0) {
      *plVar5 = param_1;
      plVar5[1] = lVar3;
      iVar2 = FwppvSwitchLwfReorderEventNotify(plVar5,*(undefined1 *)(param_1 + 0xb0),lVar3);
      if (-1 < iVar2) {
        if (iVar2 == 0x103) {
          return 0x103;
        }
        *(undefined4 *)(param_1 + 0x3c) = 3;
        *(undefined1 *)(param_1 + 0x40) = 0;
        goto LAB_140017bbc;
      }
    }
    uVar6 = 0xc000009a;
  }
  else {
    plVar5 = (longlong *)0x0;
    if ((int)uVar4 == 0x103) {
      return uVar6;
    }
  }
LAB_140017bbc:
  ExFreePoolWithTag(lVar3,0x67326c57);
  if (plVar5 != (longlong *)0x0) {
    ExFreePoolWithTag(plVar5,0x67326c57);
  }
  return uVar6;
}



===== LwfvSwitchReturnNetBufferLists @ 140017c10 =====

void LwfvSwitchReturnNetBufferLists(longlong param_1,undefined8 *param_2,undefined4 param_3)

{
  int iVar1;
  int local_res8 [2];
  undefined8 *local_res10;
  int local_res20 [2];
  
  local_res8[0] = 0;
  local_res20[0] = 0;
  local_res10 = param_2;
  L2GetCompletedNblCounts(param_2,local_res8);
  L2CheckAndNotifyNetBufferListEvent(param_2,0xb);
  if (*(int *)(param_1 + 0x148) != 0) {
    L2CheckAndCompleteInjectedNetBufferLists
              (2,&local_res10,'\x01',local_res20,*(longlong *)(param_1 + 0x48));
  }
  iVar1 = local_res8[0] + local_res20[0];
  vSwitchCheckAndCompleteL3NetBufferLists(&local_res10,'\x01',(byte)param_3);
  if (local_res10 != (undefined8 *)0x0) {
    NdisFReturnNetBufferLists(*(undefined8 *)(param_1 + 0x48),local_res10,param_3);
  }
  L2UpdateCompletedNblCounts(param_1,iVar1);
  return;
}



===== LwfvSwitchRevokeAssignedVf @ 140017cc8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void LwfvSwitchRevokeAssignedVf(longlong param_1)

{
  longlong lVar1;
  bool bVar2;
  undefined1 uVar3;
  int iVar4;
  ulonglong uVar5;
  undefined4 uVar6;
  undefined2 uVar7;
  undefined1 auStack_158 [32];
  undefined4 local_138;
  undefined8 local_134;
  undefined8 uStack_12c;
  undefined4 local_124;
  undefined4 *local_120;
  undefined4 local_118 [2];
  undefined8 local_110;
  undefined4 local_104;
  undefined8 local_e8;
  undefined4 local_e0;
  undefined4 local_a8 [2];
  undefined8 local_a0;
  undefined4 local_94;
  undefined4 *local_78;
  undefined4 local_70;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_158;
  lVar1 = *(longlong *)(param_1 + 0x488);
  memset(local_a8,0,0x70);
  local_124 = 0;
  local_134 = 0;
  uStack_12c = 0;
  memset(local_118,0,0x70);
  local_138 = 0x200198;
  local_118[0] = 0x700198;
  uVar6 = 0;
  local_110 = *(undefined8 *)(lVar1 + 0x48);
  uVar7 = 0;
  bVar2 = false;
  local_120 = local_118;
  local_104 = 0xc0241001;
  local_e8 = 0;
  local_e0 = 0;
  local_a8[0] = 0x700198;
  local_a0 = *(undefined8 *)(lVar1 + 0x48);
  local_78 = &local_138;
  local_70 = 0x20;
  local_94 = 0xc0241002;
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x30);
  uVar5 = -(ulonglong)(*(char *)(*(ulonglong *)(param_1 + 0x448) + 0x8b1) != '\0') &
          *(ulonglong *)(param_1 + 0x448);
  if ((*(char *)(uVar5 + 0x8b1) != '\0') && (*(char *)(uVar5 + 0x8b0) == '\0')) {
    iVar4 = (*DAT_14002c5c8)(*(undefined8 *)(lVar1 + 0xa0),*(undefined4 *)(uVar5 + 0x410),
                             *(undefined2 *)(uVar5 + 0x414));
    if (iVar4 == 0) {
      uVar6 = *(undefined4 *)(uVar5 + 0x410);
      bVar2 = true;
      uVar7 = *(undefined2 *)(uVar5 + 0x414);
    }
  }
  KeReleaseSpinLock(lVar1 + 0x30,uVar3);
  if (bVar2) {
    uStack_12c = CONCAT44(uVar6,(undefined4)uStack_12c);
    NdisFIndicateStatus(*(undefined8 *)(lVar1 + 0x48),local_a8);
    (*DAT_14002c5d0)(*(undefined8 *)(lVar1 + 0xa0),uVar6,uVar7);
  }
  return;
}



===== LwfvSwitchSendNetBufferLists @ 140017e90 =====

void LwfvSwitchSendNetBufferLists(longlong ***param_1,longlong ***param_2,uint param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  ulonglong uVar3;
  longlong **pplVar4;
  longlong **local_res8;
  longlong ***local_res10;
  uint local_res18;
  
  local_res8 = (longlong **)0x0;
  local_res10 = param_2;
  local_res18 = param_3;
  iVar1 = KfdIsLayerEmpty(0x48);
  pplVar4 = (longlong **)0x0;
  if (iVar1 == 0) {
    L2InspectNetBufferLists
              (1,0x48,(longlong *)&local_res10,(int *)0x0,(longlong *)0x0,(int *)0x0,
               (longlong *)&local_res8,(longlong *)param_1,param_3,param_4);
    param_2 = local_res10;
    pplVar4 = local_res8;
  }
  if (param_2 != (longlong ***)0x0) {
    iVar1 = KfdIsLayerEmpty(0x4a);
    iVar2 = KfdIsLayerEmpty(0x4b);
    local_res8 = (longlong **)0x0;
    if ((iVar1 == 0) || (iVar2 == 0)) {
      uVar3 = Feature_Firewall_BugFixes_25D_WFPlwfs_L28023_resilience__private_IsEnabledDeviceUsageNoInline
                        ();
      if ((int)uVar3 == 0) {
        vSwitchInspectL3NetBufferLists
                  (param_1,1,iVar1 == 0,iVar2 == 0,(longlong ***)&local_res10,(int *)0x0,&local_res8
                   ,param_4);
      }
      else {
        vSwitchInspectL3NetBufferLists_25D
                  (param_1,1,iVar1 == 0,iVar2 == 0,(longlong ***)&local_res10,(int *)0x0,&local_res8
                   ,param_4);
      }
      if (local_res8 != (longlong **)0x0) {
        NdisFSendNetBufferListsComplete(param_1[9],local_res8,param_4 & 1);
      }
      param_2 = local_res10;
    }
    if (param_2 != (longlong ***)0x0) {
      L2NdisFSendNetBufferLists((longlong)param_1,param_1[9],param_2,local_res18,param_4);
    }
  }
  if (pplVar4 != (longlong **)0x0) {
    NdisFSendNetBufferListsComplete(param_1[9],pplVar4,param_4 & 1);
  }
  return;
}



===== LwfvSwitchSendNetBufferListsComplete @ 140018030 =====

void LwfvSwitchSendNetBufferListsComplete(longlong param_1,undefined8 *param_2,undefined4 param_3)

{
  int local_res8 [2];
  undefined8 *local_res10;
  
  local_res8[0] = 0;
  local_res10 = param_2;
  L2GetCompletedNblCounts(param_2,local_res8);
  L2CheckAndNotifyNetBufferListEvent(param_2,10);
  if (*(int *)(param_1 + 0x148) != 0) {
    L2CheckAndCompleteInjectedNetBufferLists
              (2,&local_res10,'\0',(int *)0x0,*(longlong *)(param_1 + 0x48));
  }
  vSwitchCheckAndCompleteL3NetBufferLists(&local_res10,'\0',(byte)param_3);
  if (local_res10 != (undefined8 *)0x0) {
    NdisFSendNetBufferListsComplete(*(undefined8 *)(param_1 + 0x48),local_res10,param_3);
  }
  L2UpdateCompletedNblCounts(param_1,local_res8[0]);
  return;
}



===== LwfvSwitchSetFilterModuleOptions @ 1400180e0 =====

undefined8 LwfvSwitchSetFilterModuleOptions(longlong param_1)

{
  longlong lVar1;
  uint uVar2;
  bool bVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 uVar6;
  bool bVar7;
  undefined8 local_38;
  code *pcStack_30;
  code *local_28;
  undefined8 uStack_20;
  code *local_18;
  code *pcStack_10;
  
  lVar1 = param_1 + 0x30;
  bVar3 = false;
  bVar7 = false;
  local_38 = 0;
  pcStack_30 = (code *)0x0;
  local_28 = (code *)0x0;
  uStack_20 = 0;
  local_18 = (code *)0x0;
  pcStack_10 = (code *)0x0;
  uVar6 = KeAcquireSpinLockRaiseToDpc(lVar1);
  uVar4 = local_38;
  uVar2 = *(uint *)(param_1 + 0x11c);
  if (uVar2 != *(uint *)(param_1 + 0x118)) {
    local_38 = CONCAT71(local_38._1_7_,0x8c);
    uVar5 = local_38;
    local_38._4_4_ = SUB84(uVar4,4);
    local_38._0_4_ = CONCAT22(0x30,(short)uVar5);
    if ((uVar2 & 1) != 0) {
      pcStack_30 = LwfvSwitchSendNetBufferLists;
      local_28 = LwfvSwitchSendNetBufferListsComplete;
    }
    if ((uVar2 & 2) != 0) {
      local_18 = LwfvSwitchRecvNetBufferLists;
      pcStack_10 = LwfvSwitchReturnNetBufferLists;
    }
    bVar7 = *(char *)(param_1 + 0x120) != '\0';
    bVar3 = true;
    *(uint *)(param_1 + 0x118) = uVar2;
  }
  *(undefined1 *)(param_1 + 0x40) = 1;
  KeReleaseSpinLock(lVar1,uVar6);
  if (bVar3) {
    NdisSetOptionalHandlers(*(undefined8 *)(param_1 + 0x48),&local_38);
  }
  if (bVar7) {
    uVar6 = KeAcquireSpinLockRaiseToDpc(lVar1);
    *(undefined1 *)(param_1 + 0x120) = 0;
    KeSetEvent(param_1 + 0x128,0,0);
    KeReleaseSpinLock(lVar1,uVar6);
  }
  return 0;
}



===== LwfvSwitchStatusIndication @ 140018230 =====

void LwfvSwitchStatusIndication(longlong param_1)

{
  NdisFIndicateStatus(*(undefined8 *)(param_1 + 0x48));
  return;
}



===== LwfvSwitchpClearPortDatabase @ 140018250 =====

void LwfvSwitchpClearPortDatabase(longlong param_1,longlong param_2,longlong param_3)

{
  int iVar1;
  undefined1 uVar2;
  uint uVar3;
  longlong lVar4;
  ulonglong uVar5;
  int iVar6;
  ulonglong uVar7;
  longlong lVar8;
  longlong lVar9;
  uint local_28 [2];
  longlong local_20;
  
  local_28[1] = 0;
  if (param_2 != 0) {
    uVar3 = *(int *)(param_2 + 8) - 1;
    uVar7 = (ulonglong)(uVar3 & 0xff);
    local_20 = *(longlong *)(param_1 + 0x70) + 10;
    uVar5 = (ulonglong)(uVar3 >> 8);
    local_28[0] = (uint)*(ushort *)(*(longlong *)(param_1 + 0x70) + 8);
    uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x30);
    lVar4 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x80) + uVar5 * 8) + uVar7 * 8);
    iVar1 = *(int *)(lVar4 + 0x46c);
    iVar6 = 0;
    if (iVar1 != 0) {
      *(undefined4 *)(lVar4 + 0x46c) = 0;
      *(undefined1 *)
       (*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x80) + uVar5 * 8) + uVar7 * 8) + 0x470)
           = 0;
      iVar6 = iVar1;
    }
    lVar4 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x80) + uVar5 * 8) + uVar7 * 8);
    if (*(longlong *)(lVar4 + 0x448) != 0) {
      lVar8 = 0;
      lVar9 = 1;
      if (*(int *)(lVar4 + 0x434) == 1) {
        lVar9 = 0x40;
      }
      do {
        lVar8 = lVar8 + 0x8b8;
        lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x80) + uVar5 * 8);
        *(undefined1 *)(*(longlong *)(*(longlong *)(lVar4 + uVar7 * 8) + 0x448) + -7 + lVar8) = 0;
        lVar9 = lVar9 + -1;
      } while (lVar9 != 0);
    }
    KeReleaseSpinLock(param_1 + 0x30,CONCAT71((int7)((ulonglong)lVar4 >> 8),uVar2));
    if (iVar6 != 0) {
      vSwitchFlpDerefCompartment(local_28,iVar6);
    }
    lVar4 = *(longlong *)
             (*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x80) + uVar5 * 8) + uVar7 * 8) +
             0x448);
    if (lVar4 != 0) {
      ExFreePoolWithTag(lVar4,0x70737657);
      *(undefined8 *)
       (*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x80) + uVar5 * 8) + uVar7 * 8) + 0x448)
           = 0;
    }
    ExFreePoolWithTag(*(undefined8 *)
                       (*(longlong *)(*(longlong *)(param_1 + 0x80) + uVar5 * 8) + uVar7 * 8));
    *(undefined8 *)(*(longlong *)(*(longlong *)(param_1 + 0x80) + uVar5 * 8) + uVar7 * 8) = 0;
  }
  if (param_3 != 0) {
    uVar3 = *(int *)(param_3 + 0x410) - 1;
    uVar7 = (ulonglong)(uVar3 & 0xff);
    local_20 = *(longlong *)(param_1 + 0x70) + 10;
    uVar5 = (ulonglong)(uVar3 >> 8);
    local_28[0] = (uint)*(ushort *)(*(longlong *)(param_1 + 0x70) + 8);
    vSwitchFlpDerefCompartment(local_28,0);
    uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x30);
    *(undefined1 *)
     (*(longlong *)
       (*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x80) + uVar5 * 8) + uVar7 * 8) + 0x448)
      + 0x8b1 + (ulonglong)*(ushort *)(param_3 + 0x414) * 0x8b8) = 0;
    lVar4 = (ulonglong)*(ushort *)(param_3 + 0x414) * 0x8b8;
    *(undefined1 *)
     (*(longlong *)
       (*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x80) + uVar5 * 8) + uVar7 * 8) + 0x448)
      + 0x8b0 + lVar4) = 0;
    KeReleaseSpinLock(param_1 + 0x30,CONCAT71((int7)((ulonglong)lVar4 >> 8),uVar2));
    if (*(int *)(param_3 + 0x410) == *(int *)(param_1 + 0xd8)) {
      *(undefined4 *)(param_1 + 0xd8) =
           *(undefined4 *)
            (*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x80) + uVar5 * 8) + uVar7 * 8) +
            0x480);
    }
    if (*(int *)(param_3 + 0x418) == 0) {
      *(short *)(param_1 + 0x8c) = *(short *)(param_1 + 0x8c) + -1;
    }
    else if (*(int *)(param_3 + 0x418) == 3) {
      *(short *)(param_1 + 0x88) = *(short *)(param_1 + 0x88) + -1;
    }
    else {
      *(short *)(param_1 + 0x8a) = *(short *)(param_1 + 0x8a) + -1;
    }
    if (*(short *)(param_1 + 0x8c) == 0) {
      if (*(short *)(param_1 + 0x88) == 0) {
        if (*(short *)(param_1 + 0x8a) != 0) {
          *(undefined4 *)(param_1 + 0x90) = 1;
        }
      }
      else {
        *(undefined4 *)(param_1 + 0x90) = 2;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x90) = 3;
    }
  }
  return;
}



===== LwfvSwitchpClosevSwitch @ 140018560 =====

void LwfvSwitchpClosevSwitch(longlong param_1,char param_2)

{
  if (param_2 != '\0') {
    FwppvSwitchDeleteNotify(*(undefined8 *)(param_1 + 0x70));
    L2FirevSwitchEvent(param_1,3);
  }
  LwfvSwitchCleanupPortDirectory(param_1);
  if (*(longlong *)(param_1 + 0x70) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x70),0x70737657);
    if (*(longlong *)(param_1 + 0x78) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x78),0x70737657);
    }
  }
  return;
}



===== LwfvSwitchpFillPortDatabase @ 1400185dc =====

undefined8 LwfvSwitchpFillPortDatabase(longlong param_1,undefined8 *param_2,void *param_3)

{
  longlong lVar1;
  longlong *plVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined1 uVar8;
  int iVar9;
  undefined8 uVar10;
  longlong lVar11;
  longlong lVar12;
  uint uVar13;
  undefined8 *puVar14;
  longlong lVar15;
  ulonglong uVar16;
  undefined8 *puVar17;
  void *pvVar18;
  ulonglong uVar19;
  longlong *local_58;
  uint local_50 [2];
  longlong local_48;
  
  local_50[1] = 0;
  pvVar18 = param_3;
  if (param_2 != (undefined8 *)0x0) {
    uVar13 = *(uint *)(param_2 + 1) - 1;
    uVar16 = (ulonglong)(uVar13 >> 8);
    uVar19 = (ulonglong)(uVar13 & 0xff);
    if (*(longlong *)(*(longlong *)(param_1 + 0x80) + uVar16 * 8) == 0) {
      pvVar18 = (void *)0x70737657;
      uVar10 = ExAllocatePool2(0x40,0x800);
      *(undefined8 *)(*(longlong *)(param_1 + 0x80) + uVar16 * 8) = uVar10;
      if (*(longlong *)(*(longlong *)(param_1 + 0x80) + uVar16 * 8) == 0) {
        return 0xc000009a;
      }
    }
    lVar1 = param_1 + 0x30;
    uVar8 = KeAcquireSpinLockRaiseToDpc(lVar1);
    lVar12 = *(longlong *)(param_1 + 0x80);
    if (*(longlong *)(*(longlong *)(lVar12 + uVar16 * 8) + uVar19 * 8) == 0) {
      pvVar18 = (void *)ExAllocatePool2(0x40,0x498,0x70737657);
      lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x80) + uVar16 * 8);
      *(void **)(lVar11 + uVar19 * 8) = pvVar18;
      lVar12 = *(longlong *)(param_1 + 0x80);
      if (*(longlong *)(*(longlong *)(lVar12 + uVar16 * 8) + uVar19 * 8) == 0) {
        KeReleaseSpinLock(lVar1,CONCAT71((int7)((ulonglong)lVar11 >> 8),uVar8));
        return 0xc000009a;
      }
    }
    lVar11 = 8;
    puVar6 = (undefined8 *)(*(longlong *)(*(longlong *)(lVar12 + uVar16 * 8) + uVar19 * 8) + 0x20);
    puVar7 = param_2;
    do {
      puVar17 = puVar7;
      puVar14 = puVar6;
      uVar10 = puVar17[1];
      *puVar14 = *puVar17;
      puVar14[1] = uVar10;
      uVar10 = puVar17[3];
      puVar14[2] = puVar17[2];
      puVar14[3] = uVar10;
      uVar10 = puVar17[5];
      puVar14[4] = puVar17[4];
      puVar14[5] = uVar10;
      uVar10 = puVar17[7];
      puVar14[6] = puVar17[6];
      puVar14[7] = uVar10;
      uVar10 = puVar17[9];
      puVar14[8] = puVar17[8];
      puVar14[9] = uVar10;
      uVar10 = puVar17[0xb];
      puVar14[10] = puVar17[10];
      puVar14[0xb] = uVar10;
      uVar10 = puVar17[0xd];
      puVar14[0xc] = puVar17[0xc];
      puVar14[0xd] = uVar10;
      uVar10 = puVar17[0xf];
      puVar14[0xe] = puVar17[0xe];
      puVar14[0xf] = uVar10;
      lVar11 = lVar11 + -1;
      puVar6 = puVar14 + 0x10;
      puVar7 = puVar17 + 0x10;
    } while (lVar11 != 0);
    uVar3 = *(undefined4 *)((longlong)puVar17 + 0x84);
    uVar4 = *(undefined4 *)(puVar17 + 0x11);
    uVar5 = *(undefined4 *)((longlong)puVar17 + 0x8c);
    *(undefined4 *)(puVar14 + 0x10) = *(undefined4 *)(puVar17 + 0x10);
    *(undefined4 *)((longlong)puVar14 + 0x84) = uVar3;
    *(undefined4 *)(puVar14 + 0x11) = uVar4;
    *(undefined4 *)((longlong)puVar14 + 0x8c) = uVar5;
    uVar3 = *(undefined4 *)((longlong)puVar17 + 0x94);
    uVar4 = *(undefined4 *)(puVar17 + 0x13);
    uVar5 = *(undefined4 *)((longlong)puVar17 + 0x9c);
    *(undefined4 *)(puVar14 + 0x12) = *(undefined4 *)(puVar17 + 0x12);
    *(undefined4 *)((longlong)puVar14 + 0x94) = uVar3;
    *(undefined4 *)(puVar14 + 0x13) = uVar4;
    *(undefined4 *)((longlong)puVar14 + 0x9c) = uVar5;
    *(undefined1 *)
     (*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x80) + uVar16 * 8) + uVar19 * 8) + 0x440)
         = 1;
    *(longlong *)
     (*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x80) + uVar16 * 8) + uVar19 * 8) + 0x488)
         = param_1;
    uVar13 = *(uint *)(param_2 + 1);
    if (*(uint *)(param_1 + 0xf8) < uVar13) {
      *(uint *)(param_1 + 0xf8) = uVar13;
    }
    KeReleaseSpinLock(lVar1);
  }
  if (param_3 == (void *)0x0) {
    return 0;
  }
  uVar13 = *(int *)((longlong)param_3 + 0x410) - 1;
  uVar16 = (ulonglong)(uVar13 & 0xff);
  local_48 = *(longlong *)(param_1 + 0x70) + 10;
  uVar19 = (ulonglong)(uVar13 >> 8);
  local_50[0] = (uint)*(ushort *)(*(longlong *)(param_1 + 0x70) + 8);
  iVar9 = vSwitchFlpRefOrCreateCompartment(local_50,0,pvVar18);
  if (iVar9 < 0) {
    return 0xc000009a;
  }
  lVar1 = param_1 + 0x30;
  uVar8 = KeAcquireSpinLockRaiseToDpc(lVar1);
  plVar2 = (longlong *)(param_1 + 0x80);
  lVar12 = *plVar2;
  lVar11 = *(longlong *)(*(longlong *)(lVar12 + uVar19 * 8) + uVar16 * 8);
  if (*(longlong *)(lVar11 + 0x448) == 0) {
    uVar10 = 0x22e00;
    if (*(int *)(lVar11 + 0x434) != 1) {
      uVar10 = 0x8b8;
    }
    uVar10 = ExAllocatePool2(0x40,uVar10,0x70737657);
    *(undefined8 *)(*(longlong *)(*(longlong *)(*plVar2 + uVar19 * 8) + uVar16 * 8) + 0x448) =
         uVar10;
    lVar12 = *plVar2;
    if (*(longlong *)(*(longlong *)(*(longlong *)(lVar12 + uVar19 * 8) + uVar16 * 8) + 0x448) == 0)
    {
      KeReleaseSpinLock(lVar1);
      vSwitchFlpDerefCompartment(local_50,0);
      return 0xc000009a;
    }
  }
  local_58 = (longlong *)(param_1 + 0x80);
  memmove((void *)((ulonglong)*(ushort *)((longlong)param_3 + 0x414) * 0x8b8 +
                  *(longlong *)
                   (*(longlong *)(*(longlong *)(lVar12 + uVar19 * 8) + uVar16 * 8) + 0x448)),param_3
          ,0x8b0);
  *(undefined1 *)
   (*(longlong *)(*(longlong *)(*(longlong *)(*plVar2 + uVar19 * 8) + uVar16 * 8) + 0x448) + 0x8b1 +
   (ulonglong)*(ushort *)((longlong)param_3 + 0x414) * 0x8b8) = 1;
  lVar12 = *(longlong *)(*(longlong *)(*plVar2 + uVar19 * 8) + uVar16 * 8);
  lVar15 = (ulonglong)*(ushort *)((longlong)param_3 + 0x414) * 0x8b8;
  lVar11 = *(longlong *)(lVar12 + 0x448);
  if (*(int *)((longlong)param_3 + 0x41c) == 2) {
    *(undefined1 *)(lVar11 + 0x8b0 + lVar15) = 0;
  }
  else {
    *(undefined1 *)(lVar11 + 0x8b0 + lVar15) = 1;
  }
  KeReleaseSpinLock(lVar1,CONCAT71((int7)((ulonglong)lVar12 >> 8),uVar8));
  lVar1 = *(longlong *)(*(longlong *)(*plVar2 + uVar19 * 8) + uVar16 * 8);
  *(undefined8 *)(lVar1 + 0x450) = 0;
  *(undefined8 *)(lVar1 + 0x458) = 0;
  *(undefined8 *)(lVar1 + 0x460) = 0;
  lVar1 = *(longlong *)(*(longlong *)(*plVar2 + uVar19 * 8) + uVar16 * 8);
  lVar12 = lVar1 + 0x450;
  *(longlong *)(lVar1 + 0x458) = lVar12;
  *(longlong *)lVar12 = lVar12;
  if (*(uint *)(param_1 + 0xd8) < *(uint *)((longlong)param_3 + 0x410)) {
    *(uint *)(*(longlong *)(*(longlong *)(*local_58 + uVar19 * 8) + uVar16 * 8) + 0x480) =
         *(uint *)(param_1 + 0xd8);
    *(undefined4 *)(param_1 + 0xd8) = *(undefined4 *)((longlong)param_3 + 0x410);
  }
  if (*(int *)((longlong)param_3 + 0x418) == 0) {
    *(short *)(param_1 + 0x8c) = *(short *)(param_1 + 0x8c) + 1;
  }
  else if (*(int *)((longlong)param_3 + 0x418) == 3) {
    *(short *)(param_1 + 0x88) = *(short *)(param_1 + 0x88) + 1;
  }
  else {
    *(short *)(param_1 + 0x8a) = *(short *)(param_1 + 0x8a) + 1;
  }
  if (*(short *)(param_1 + 0x8c) != 0) {
    *(undefined4 *)(param_1 + 0x90) = 3;
    return 0;
  }
  if (*(short *)(param_1 + 0x88) != 0) {
    *(undefined4 *)(param_1 + 0x90) = 2;
    return 0;
  }
  if (*(short *)(param_1 + 0x8a) == 0) {
    return 0;
  }
  *(undefined4 *)(param_1 + 0x90) = 1;
  return 0;
}



===== LwfvSwitchpHandleReroutedEgressNBLs @ 140018a60 =====

void LwfvSwitchpHandleReroutedEgressNBLs
               (longlong param_1,undefined4 param_2,uint param_3,int *param_4,longlong ***param_5)

{
  longlong ***ppplVar1;
  longlong ***ppplVar2;
  longlong ***ppplVar3;
  int iVar4;
  
  ppplVar1 = (longlong ***)*param_5;
  ppplVar3 = param_5;
  while (ppplVar2 = ppplVar1, ppplVar2 != (longlong ***)0x0) {
    param_5 = (longlong ***)0x0;
    ppplVar1 = (longlong ***)*ppplVar2;
    iVar4 = FwpsNetBufferListRetrieveContext0(ppplVar2,2,0,0,&param_5);
    if ((iVar4 < 0) || (*(int *)((longlong)param_5 + 0xc) != 2)) {
      *ppplVar2 = (longlong **)ppplVar1;
      ppplVar3 = ppplVar2;
    }
    else {
      *ppplVar2 = (longlong **)0x0;
      *param_4 = *param_4 + -1;
      *ppplVar3 = (longlong **)ppplVar1;
      L2NdisFIndicateReceiveNetBufferLists
                (param_1,*(undefined8 *)(param_1 + 0x48),ppplVar2,param_2,1,param_3);
    }
  }
  return;
}



===== LwfvSwitchpInitializevSwitch @ 140018b30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int LwfvSwitchpInitializevSwitch(longlong param_1)

{
  uint uVar1;
  int iVar2;
  undefined1 *puVar3;
  void *_Dst;
  undefined1 auStack_168 [32];
  undefined8 local_148;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 local_118 [4];
  undefined4 local_f8;
  undefined8 local_f0;
  undefined4 local_e8;
  undefined8 *local_38;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_168;
  local_128 = 0;
  local_138 = 0;
  uStack_130 = 0;
  memset(local_118,0,0xf8);
  KeInitializeEvent(&local_138,1);
  puVar3 = (undefined1 *)ExAllocatePool2(0x40,0x418,0x70737657);
  *(undefined1 **)(param_1 + 0x70) = puVar3;
  if (puVar3 != (undefined1 *)0x0) {
    *puVar3 = 0x80;
    *(undefined1 *)(*(longlong *)(param_1 + 0x70) + 1) = 1;
    *(undefined2 *)(*(longlong *)(param_1 + 0x70) + 2) = 0x415;
    local_f0 = *(undefined8 *)(param_1 + 0x70);
    local_38 = &local_138;
    local_118[0] = 0xf80196;
    local_f8 = 0x10275;
    local_e8 = 0x418;
    uVar1 = NdisFOidRequest(*(undefined8 *)(param_1 + 0x48),local_118);
    if (uVar1 != 0x103) {
      LwfvSwitchOidRequestComplete(param_1,(longlong)local_118,(ulonglong)uVar1);
    }
    local_148 = 0;
    KeWaitForSingleObject(&local_138,0,0,0);
    iVar2 = (int)local_38;
    local_38 = (undefined8 *)0x0;
    if (iVar2 != 0) {
      return iVar2;
    }
    _Dst = (void *)ExAllocatePool2(0x40,(ulonglong)*(ushort *)(*(longlong *)(param_1 + 0x70) + 8) +
                                        2,0x67326c57);
    *(void **)(param_1 + 0x78) = _Dst;
    if (_Dst != (void *)0x0) {
      memmove(_Dst,(void *)(*(longlong *)(param_1 + 0x70) + 10),
              (ulonglong)*(ushort *)(*(longlong *)(param_1 + 0x70) + 8));
      *(undefined2 *)
       (*(longlong *)(param_1 + 0x78) +
       (ulonglong)(*(ushort *)(*(longlong *)(param_1 + 0x70) + 8) >> 1) * 2) = 0;
      if (*(char *)(*(longlong *)(param_1 + 0x70) + 0x414) == '\0') {
        return 0;
      }
      iVar2 = LwfvSwitchpInitializevSwitchConfig(param_1);
      return iVar2;
    }
  }
  return -0x3fffff66;
}



===== LwfvSwitchpInitializevSwitchConfig @ 140018cf8 =====

int LwfvSwitchpInitializevSwitchConfig(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong *puVar8;
  uint uVar9;
  undefined8 *puVar10;
  ulonglong local_res10;
  longlong local_res18 [2];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  local_res18[0] = 0;
  local_38 = 0;
  uVar6 = 0;
  local_res10 = 0;
  local_48 = 0;
  uStack_40 = 0;
  KeInitializeEvent(&local_48,1,0);
  iVar2 = LwfvSwitchpQueryPortOrNicArray(param_1,0x10276,&local_48,local_res18);
  lVar1 = local_res18[0];
  uVar7 = uVar6;
  if (iVar2 == 0) {
    puVar8 = &local_res10;
    iVar2 = LwfvSwitchpQueryPortOrNicArray(param_1,0x10277,&local_48,puVar8);
    if (iVar2 == 0) {
      lVar4 = ExAllocatePool2(0x40);
      *(longlong *)(param_1 + 0x80) = lVar4;
      if (lVar4 != 0) {
        while( true ) {
          uVar7 = local_res10;
          uVar9 = (uint)uVar6;
          if (*(uint *)(lVar1 + 0xc) <= uVar9) break;
          puVar10 = (undefined8 *)
                    ((ulonglong)*(ushort *)(lVar1 + 8) +
                    (ulonglong)(uVar9 * *(int *)(lVar1 + 0x10)) + lVar1);
          uVar5 = LwfvSwitchpFillPortDatabase(param_1,puVar10,(void *)0x0);
          iVar2 = (int)uVar5;
          if ((iVar2 != 0) ||
             (iVar2 = LwfvSwitchFillInitialPortProperties
                                (param_1,(longlong)puVar10,&local_48,puVar8), iVar2 != 0))
          goto LAB_140018da0;
          uVar6 = (ulonglong)(uVar9 + 1);
        }
        for (uVar9 = 0; uVar9 < *(uint *)(uVar7 + 0xc); uVar9 = uVar9 + 1) {
          uVar5 = LwfvSwitchpFillPortDatabase
                            (param_1,(undefined8 *)0x0,
                             (void *)((ulonglong)*(ushort *)(uVar7 + 8) +
                                     uVar9 * *(int *)(uVar7 + 0x10) + uVar7));
          iVar2 = (int)uVar5;
          if (iVar2 != 0) goto LAB_140018da4;
        }
        iVar3 = FwppvSwitchCreateNotify(*(undefined8 *)(param_1 + 0x70),lVar1,uVar7);
        if (iVar3 < 0) {
          iVar2 = -0x3fffff66;
        }
        else {
          iVar3 = L2FirevSwitchEvent(param_1,2);
          if (iVar3 < 0) {
            iVar2 = -0x3fffff66;
          }
        }
        goto LAB_140018da4;
      }
      iVar2 = -0x3fffff66;
    }
LAB_140018da0:
    uVar7 = local_res10;
  }
LAB_140018da4:
  if (lVar1 != 0) {
    ExFreePoolWithTag(lVar1,0x67326c57);
  }
  if (uVar7 != 0) {
    ExFreePoolWithTag(uVar7,0x67326c57);
  }
  if ((iVar2 != 0) && (*(longlong *)(param_1 + 0x80) != 0)) {
    LwfvSwitchCleanupPortDirectory(param_1);
    *(undefined8 *)(param_1 + 0x80) = 0;
  }
  return iVar2;
}



===== LwfvSwitchpIsClassifyNeeded @ 140018edc =====

bool LwfvSwitchpIsClassifyNeeded(ushort param_1,longlong param_2,uint param_3)

{
  int iVar1;
  bool bVar2;
  int local_res8 [2];
  undefined8 local_res10 [3];
  uint local_58 [2];
  longlong local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  uint *local_38;
  ulonglong local_30;
  uint uStack_28;
  undefined4 uStack_24;
  undefined8 *local_20;
  undefined4 local_18;
  undefined2 local_14;
  
  local_res10[0] = 0;
  local_res8[0] = 0;
  local_58[1] = 0;
  local_14 = 0;
  local_50 = param_2 + 10;
  local_58[0] = (uint)*(ushort *)(param_2 + 8);
  local_18 = 0xffffffff;
  local_48 = 7;
  local_38 = local_58;
  uStack_40 = 0xc;
  local_20 = &local_48;
  _uStack_28 = CONCAT44(1,param_3 | 2);
  local_30 = (ulonglong)param_1;
  iVar1 = KfdEnumLayer(param_1,&local_30,local_res10,local_res8);
  if (iVar1 < 0) {
    bVar2 = true;
  }
  else {
    KfdFreeEnumHandle(local_res10[0]);
    bVar2 = local_res8[0] != 0;
  }
  return bVar2;
}



===== LwfvSwitchpIsInRequiredPosition @ 140018fc0 =====

undefined8 LwfvSwitchpIsInRequiredPosition(longlong param_1,longlong param_2,undefined8 param_3)

{
  char cVar1;
  longlong lVar2;
  void *_Dst;
  uint uVar3;
  longlong lVar4;
  longlong lVar5;
  uint uVar6;
  uint uVar7;
  uint local_res20;
  
  lVar4 = (ulonglong)*(uint *)(param_2 + 0xc) + param_2;
  local_res20 = 0;
  uVar3 = 0xffffffff;
  lVar2 = 0;
  uVar6 = 0;
  do {
    uVar7 = 0xffffffff;
    if (*(uint *)(param_2 + 8) <= uVar6) {
LAB_140019155:
      *(bool *)param_3 = uVar3 == uVar7;
      if (uVar3 != uVar7) {
        *(longlong *)(param_1 + 0xb8) = lVar2;
        *(uint *)(param_1 + 0xc0) = local_res20;
      }
      return 0;
    }
    lVar5 = (ulonglong)uVar6 * 0x40;
    L2TrimUnicodeString((ushort *)(lVar4 + 0x20 + lVar5));
    cVar1 = RtlEqualUnicodeString();
    if (cVar1 != '\0') {
      uVar7 = uVar6;
      if (uVar3 != 0xffffffff) {
        uVar7 = uVar3;
      }
      uVar3 = uVar7;
      if (*(longlong *)(lVar4 + 0x18 + lVar5) == *(longlong *)(param_1 + 0xa8)) {
        uVar7 = uVar6;
        goto LAB_140019155;
      }
      if ((lVar2 == 0) &&
         (lVar2 = ExAllocatePool2(0x40,(ulonglong)*(uint *)(param_2 + 8) << 3,0x67326c57),
         lVar2 == 0)) {
        return 0xc000009a;
      }
      _Dst = (void *)ExAllocatePool2(0x40,(ulonglong)*(ushort *)(lVar4 + 0x30 + lVar5) * 2 + 2,
                                     0x67326c57);
      if (_Dst == (void *)0x0) {
        if (lVar2 == 0) {
          return 0xc000009a;
        }
        ExFreePoolWithTag(lVar2,0x67326c57);
        *(undefined8 *)(param_1 + 0xb8) = 0;
        *(undefined4 *)(param_1 + 0xc0) = 0;
        return 0xc000009a;
      }
      memmove(_Dst,*(void **)(lVar4 + 0x38 + lVar5),(ulonglong)*(ushort *)(lVar4 + 0x30 + lVar5));
      *(undefined2 *)((longlong)_Dst + (ulonglong)(*(ushort *)(lVar4 + 0x30 + lVar5) >> 1) * 2) = 0;
      *(void **)(lVar2 + (ulonglong)local_res20 * 8) = _Dst;
      local_res20 = local_res20 + 1;
    }
    uVar6 = uVar6 + 1;
  } while( true );
}



===== LwfvSwitchpMarkInterfaceConnected @ 140019194 =====

void LwfvSwitchpMarkInterfaceConnected(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined1 uVar2;
  uint uVar3;
  
  uVar3 = *(int *)(param_2 + 0x410) - 1;
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x30);
  lVar1 = *(longlong *)
           (*(longlong *)
             (*(longlong *)(*(longlong *)(param_1 + 0x80) + (ulonglong)(uVar3 >> 8) * 8) +
             (ulonglong)(uVar3 & 0xff) * 8) + 0x448);
  *(undefined1 *)(lVar1 + 0x8b0 + (ulonglong)*(ushort *)(param_2 + 0x414) * 0x8b8) = 0;
  KeReleaseSpinLock(param_1 + 0x30,CONCAT71((int7)((ulonglong)lVar1 >> 8),uVar2));
  return;
}



===== LwfvSwitchpMarkInterfaceDisconnected @ 140019238 =====

void LwfvSwitchpMarkInterfaceDisconnected(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined1 uVar2;
  uint uVar3;
  
  uVar3 = *(int *)(param_2 + 0x410) - 1;
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x30);
  lVar1 = *(longlong *)
           (*(longlong *)
             (*(longlong *)(*(longlong *)(param_1 + 0x80) + (ulonglong)(uVar3 >> 8) * 8) +
             (ulonglong)(uVar3 & 0xff) * 8) + 0x448);
  *(undefined1 *)(lVar1 + 0x8b0 + (ulonglong)*(ushort *)(param_2 + 0x414) * 0x8b8) = 1;
  KeReleaseSpinLock(param_1 + 0x30,CONCAT71((int7)((ulonglong)lVar1 >> 8),uVar2));
  return;
}



===== LwfvSwitchpOidRequestWorkRoutine @ 1400192e0 =====

void LwfvSwitchpOidRequestWorkRoutine(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  ushort uVar1;
  int iVar2;
  longlong lVar3;
  code *pcVar4;
  undefined1 uVar5;
  int iVar6;
  uint uVar7;
  longlong lVar8;
  longlong lVar9;
  longlong lVar10;
  undefined8 uVar11;
  longlong *plVar12;
  char cVar13;
  undefined8 uVar14;
  longlong *plVar15;
  undefined1 *puVar16;
  ulonglong uVar17;
  bool bVar18;
  int local_res10 [2];
  undefined1 auStack_88 [8];
  undefined1 auStack_80 [24];
  longlong local_68;
  undefined4 local_60;
  int *local_58;
  ulonglong local_48;
  longlong lStack_40;
  undefined8 local_38;
  
  lVar3 = *(longlong *)(param_2 + 0x140);
  uVar7 = 0;
  local_res10[0] = 0;
  if (*(int *)(lVar3 + 4) == 1) {
    iVar6 = *(int *)(lVar3 + 0x20);
    if (iVar6 == 0x10278) {
      lVar8 = *(longlong *)(lVar3 + 0x28);
      if (*(char *)(lVar8 + 0x418) != '\0') goto LAB_140019415;
      *(longlong *)(lVar3 + 0xe0) = param_2;
      uVar14 = 3;
LAB_140019348:
      iVar6 = FwppvSwitchPortEventNotify(uVar14,lVar3,*(undefined8 *)(param_2 + 0x70),lVar8);
    }
    else {
      if (iVar6 == 0x10279) {
        *(longlong *)(lVar3 + 0xe0) = param_2;
        uVar14 = 4;
        lVar8 = *(longlong *)(lVar3 + 0x28);
        goto LAB_140019348;
      }
      if (iVar6 == 0x1027a) {
        lVar8 = *(longlong *)(lVar3 + 0x28);
        *(longlong *)(lVar3 + 0xe0) = param_2;
        iVar6 = FwppvSwitchNicEventNotify(5,lVar3,*(undefined8 *)(param_2 + 0x70),lVar8);
        if (-1 < iVar6) {
          if (iVar6 != 0x103) {
            lVar8 = L2GetvSwitchPortUnsafe(param_2,*(int *)(lVar8 + 0x410));
            uVar5 = KeAcquireSpinLockRaiseToDpc(param_2 + 0x30);
            if (*(char *)(lVar8 + 0x471) != '\0') {
              *(longlong *)(lVar8 + 0x478) = lVar3;
              iVar6 = 0x103;
              *(undefined4 *)(lVar8 + 0x474) = 5;
            }
            KeReleaseSpinLock(param_2 + 0x30,uVar5);
          }
          goto LAB_140019410;
        }
        goto LAB_1400196f9;
      }
      if (iVar6 == 0x1027d) {
        lVar8 = *(longlong *)(lVar3 + 0x28);
        *(longlong *)(lVar3 + 0xe0) = param_2;
        iVar6 = FwppvSwitchNicEventNotify(6,lVar3,*(undefined8 *)(param_2 + 0x70),lVar8);
        if (iVar6 != 0x103) {
          lVar8 = L2GetvSwitchPortUnsafe(param_2,*(int *)(lVar8 + 0x410));
          uVar5 = KeAcquireSpinLockRaiseToDpc(param_2 + 0x30);
          if (*(char *)(lVar8 + 0x471) != '\0') {
            *(longlong *)(lVar8 + 0x478) = lVar3;
            iVar6 = 0x103;
            *(undefined4 *)(lVar8 + 0x474) = 6;
          }
          KeReleaseSpinLock(param_2 + 0x30,uVar5);
        }
      }
      else {
        if (iVar6 == 0x1027b) {
          uVar14 = 7;
        }
        else {
          if (iVar6 != 0x1027c) {
            if (iVar6 - 0x10271U < 3) {
              lVar8 = *(longlong *)(lVar3 + 0x28);
              lStack_40 = *(longlong *)(param_2 + 0x70) + 10;
              local_48 = (ulonglong)*(ushort *)(*(longlong *)(param_2 + 0x70) + 8);
              lVar9 = L2GetvSwitchPortUnsafe(param_2,*(int *)(lVar8 + 8));
              if (iVar6 == 0x10273) {
                iVar6 = *(int *)(lVar8 + 0xc);
                if (iVar6 == 1) {
                  cVar13 = '\v';
                  lVar9 = 0;
                  local_68 = lVar8;
                  goto LAB_1400196d3;
                }
                if (iVar6 == 3) {
                  if (*(char *)(lVar9 + 0x468) == '\0') {
                    if (*(int *)(lVar9 + 0x46c) != 0) {
                      vSwitchFlpDerefCompartment((uint *)&local_48,*(int *)(lVar9 + 0x46c));
                      *(undefined4 *)(lVar9 + 0x46c) = 0;
                    }
                  }
                  else {
                    *(undefined1 *)(lVar9 + 0x468) = 0;
                  }
                }
                else if (((iVar6 == 2) && (*(int *)(lVar9 + 0x46c) != 0)) &&
                        (*(char *)(lVar9 + 0x470) == '\x01')) {
                  vSwitchFlpDerefCompartment((uint *)&local_48,*(int *)(lVar9 + 0x46c));
                  *(undefined4 *)(lVar9 + 0x46c) = 0;
                  *(undefined1 *)(lVar9 + 0x470) = 0;
                }
              }
              else {
                iVar2 = *(int *)(lVar8 + 0xc);
                if (iVar2 == 1) {
                  local_68 = 0;
                  cVar13 = (iVar6 != 0x10271) + '\t';
                  lVar9 = lVar8;
LAB_1400196d3:
                  *(longlong *)(lVar3 + 0xe0) = param_2;
                  iVar6 = FwppvSwitchPolicyEventNotify
                                    (cVar13,lVar3,*(undefined8 *)(param_2 + 0x70),lVar9);
                  goto LAB_1400196f0;
                }
                if (iVar2 == 3) {
                  if (*(int *)((ulonglong)*(uint *)(lVar8 + 0x38) + 8 + lVar8) == 1) {
                    uVar1 = *(ushort *)((ulonglong)*(uint *)(lVar8 + 0x38) + 0x10 + lVar8);
                    uVar17 = (ulonglong)uVar1;
                    if (*(uint *)(lVar9 + 0x46c) != (uint)uVar1) {
                      bVar18 = uVar1 == 0;
                      goto LAB_140019676;
                    }
                  }
                }
                else if (iVar2 == 2) {
                  uVar7 = *(uint *)((ulonglong)*(uint *)(lVar8 + 0x38) + 0xc + lVar8);
                  uVar17 = (ulonglong)uVar7;
                  if (*(uint *)(lVar9 + 0x46c) != uVar7) {
                    bVar18 = uVar7 == 0;
LAB_140019676:
                    if (!bVar18) {
                      iVar6 = vSwitchFlpRefOrCreateCompartment((uint *)&local_48,uVar17,param_3);
                      if (-1 < iVar6) {
                        *(undefined1 *)(lVar9 + 0x490) = 1;
                        goto LAB_140019410;
                      }
                      goto LAB_1400196f9;
                    }
                  }
                }
              }
            }
            else if (iVar6 == 0x10291) {
              lVar8 = L2GetvSwitchPortUnsafe(param_2,*(int *)(*(longlong *)(lVar3 + 0x28) + 8));
              *(undefined1 *)(lVar8 + 0x460) = 0;
            }
            else if (iVar6 == 0x10292) {
              lVar8 = *(longlong *)(lVar3 + 0x28);
              lVar9 = L2GetvSwitchPortUnsafe(param_2,*(int *)(lVar8 + 8));
              *(longlong *)(lVar3 + 0xe0) = param_2;
              lVar10 = *(longlong *)(lVar8 + 0x10) + -0x48dff3c5e7c3b2f0;
              if (lVar10 == 0) {
                lVar10 = *(longlong *)(lVar8 + 0x18) + -0x7a2ed7d6fe102baf;
              }
              if (lVar10 == 0) {
                local_68 = lVar8;
                iVar6 = FwppvSwitchRuntimeStateRestoreNotify
                                  (0xd,lVar3,*(undefined8 *)(param_2 + 0x70),lVar9 + 0x450);
                if (-1 < iVar6) {
                  if (iVar6 != 0x103) {
                    *(undefined4 *)(lVar3 + 0x34) = 0x238;
                    *(undefined4 *)(lVar3 + 0x38) = 0x238;
                    goto LAB_1400198c6;
                  }
                  goto LAB_140019410;
                }
                goto LAB_1400196f9;
              }
            }
            goto LAB_140019415;
          }
          uVar14 = 8;
        }
        *(longlong *)(lVar3 + 0xe0) = param_2;
        iVar6 = FwppvSwitchNicEventNotify
                          (uVar14,lVar3,*(undefined8 *)(param_2 + 0x70),
                           *(undefined8 *)(lVar3 + 0x28));
      }
    }
LAB_1400196f0:
    if (iVar6 < 0) {
LAB_1400196f9:
      uVar17 = 0xc000009a;
      goto LAB_140019430;
    }
LAB_140019410:
    if (iVar6 == 0x103) {
      return;
    }
  }
  else if (*(int *)(lVar3 + 4) == 0xc) {
    if (*(int *)(lVar3 + 0x20) == 0x10290) {
      lVar8 = *(longlong *)(lVar3 + 0x28);
      lVar9 = L2GetvSwitchPortUnsafe(param_2,*(int *)(lVar8 + 8));
      *(longlong *)(lVar3 + 0xe0) = param_2;
      local_58 = local_res10;
      local_60 = *(undefined4 *)(lVar3 + 0x34);
      local_68 = lVar8;
      iVar6 = FwppvSwitchRuntimeStateSaveNotify
                        (0xc,lVar3,*(undefined8 *)(param_2 + 0x70),lVar9 + 0x450);
      if (-1 < iVar6) {
        if (iVar6 != 0x103) {
          if (*(short *)(lVar8 + 0x234) == 0) {
            if (local_res10[0] == 0) goto LAB_140019415;
            *(int *)(lVar3 + 0x44) = local_res10[0];
            uVar7 = 0x80000005;
            *(undefined8 *)(lVar8 + 0x10) = 0x48dff3c5e7c3b2f0;
            *(undefined8 *)(lVar8 + 0x18) = 0x7a2ed7d6fe102baf;
          }
          else {
            *(undefined4 *)(lVar3 + 0x3c) = 0x238;
            *(undefined4 *)(lVar3 + 0x44) = 0x238;
            *(undefined8 *)(lVar8 + 0x10) = 0x48dff3c5e7c3b2f0;
            *(undefined8 *)(lVar8 + 0x18) = 0x7a2ed7d6fe102baf;
          }
          goto LAB_1400198c6;
        }
        goto LAB_140019410;
      }
      goto LAB_1400196f9;
    }
    if (*(int *)(lVar3 + 0x20) == 0x10270) {
      lVar8 = *(longlong *)(lVar3 + 0x28);
      uVar14 = *(undefined8 *)(lVar3 + 0xd8);
      lVar9 = *(longlong *)(lVar8 + 0x18);
      if ((*(int *)(lVar9 + 4) == 0xc) && (*(int *)(lVar9 + 0x20) == 0x10245)) {
        local_68 = 0;
        KeWaitForSingleObject(&DAT_14002cf48,0,0,0);
        uVar11 = vSwitchIsIovOffloadPossible(param_2,lVar8,*(longlong *)(lVar9 + 0x28));
        if ((char)uVar11 != '\0') {
          iVar6 = *(int *)(lVar8 + 8);
          local_38 = 0;
          local_48 = 0;
          lStack_40 = 0;
          KeInitializeEvent(&local_48,1,0);
          *(ulonglong **)(lVar3 + 0xe0) = &local_48;
          uVar7 = NdisFOidRequest(*(undefined8 *)(param_2 + 0x48),lVar3);
          if (uVar7 != 0x103) {
            LwfvSwitchOidRequestComplete(param_2,lVar3,(ulonglong)uVar7);
          }
          local_68 = 0;
          KeWaitForSingleObject(&local_48,0,0,0);
          puVar16 = auStack_88;
          iVar2 = *(int *)(lVar3 + 0xe0);
          *(undefined8 *)(lVar3 + 0xe0) = 0;
          if (iVar2 == 0) {
            plVar12 = (longlong *)L2GetvSwitchPortUnsafe(param_2,iVar6);
            uVar5 = KeAcquireSpinLockRaiseToDpc(param_2 + 0x30);
            puVar16 = auStack_88;
            lVar8 = param_2 + 200;
            plVar15 = *(longlong **)(param_2 + 0xd0);
            if (*plVar15 != lVar8) {
              lVar8 = 3;
              pcVar4 = (code *)swi(0x29);
              uVar5 = (*pcVar4)();
              puVar16 = auStack_80;
            }
            *plVar12 = lVar8;
            plVar12[1] = (longlong)plVar15;
            *plVar15 = (longlong)plVar12;
            *(longlong **)(lVar8 + 8) = plVar12;
            *(undefined8 *)(puVar16 + -8) = 0x1400199a5;
            KeReleaseSpinLock(param_2 + 0x30,uVar5);
          }
          *(undefined8 *)(puVar16 + -8) = 0x1400199ba;
          KeReleaseMutex(&DAT_14002cf48,0);
          uVar11 = *(undefined8 *)(param_2 + 0x48);
          *(undefined8 *)(puVar16 + -8) = 0x1400199cd;
          NdisFreeCloneOidRequest(uVar11,lVar3);
          uVar11 = *(undefined8 *)(param_2 + 0x48);
          *(undefined8 *)(puVar16 + -8) = 0x1400199e3;
          NdisFOidRequestComplete(uVar11,uVar14,iVar2);
          return;
        }
        uVar7 = 0xc0000001;
        KeReleaseMutex(&DAT_14002cf48,0);
LAB_1400198c6:
        uVar17 = (ulonglong)uVar7;
        goto LAB_140019430;
      }
    }
  }
LAB_140019415:
  uVar7 = NdisFOidRequest(*(undefined8 *)(param_2 + 0x48),lVar3);
  if (uVar7 == 0x103) {
    return;
  }
  uVar17 = (ulonglong)uVar7;
LAB_140019430:
  LwfvSwitchOidRequestComplete(param_2,lVar3,uVar17);
  return;
}



===== LwfvSwitchpProcessVfFree @ 1400199f4 =====

void LwfvSwitchpProcessVfFree(longlong param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  undefined1 uVar4;
  longlong lVar5;
  
  lVar5 = L2GetvSwitchPortUnsafe(param_1,param_2);
  uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x30);
  if (*(int *)(param_1 + 0xdc) == 0) {
    vSwitchClearIovOffloaded(param_1,param_2);
  }
  else if (*(char *)(lVar5 + 0x471) != '\0') {
    lVar3 = *(longlong *)(lVar5 + 0x478);
    *(undefined1 *)(lVar5 + 0x471) = 0;
    iVar2 = *(int *)(lVar5 + 0x474);
    vSwitchClearIovOffloaded(param_1,param_2);
    piVar1 = (int *)(param_1 + 0xdc);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      KeSetEvent(param_1 + 0xe0,0);
    }
    if (lVar3 != 0) {
      LwfvSwitchEventNotifyComplete(iVar2,lVar3,0,0);
    }
  }
  KeReleaseSpinLock(param_1 + 0x30,uVar4);
  return;
}



===== LwfvSwitchpQueryPortOrNicArray @ 140019ad4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int LwfvSwitchpQueryPortOrNicArray
              (longlong param_1,undefined4 param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  undefined2 *puVar2;
  undefined1 auStack_168 [32];
  undefined4 local_148;
  undefined4 local_144;
  undefined4 local_128;
  undefined2 *local_120;
  undefined4 local_118;
  undefined4 local_110;
  undefined8 local_68;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_168;
  memset(&local_148,0,0xf8);
  local_144 = 0;
  local_120 = (undefined2 *)0x0;
  local_118 = 0;
  local_148 = 0xf80196;
  local_128 = param_2;
  local_68 = param_3;
  LwfvSwitchIssueSyncOidRequest(param_1,(longlong)&local_148,param_3);
  puVar2 = (undefined2 *)ExAllocatePool2(0x40,local_110,0x67326c57);
  if (puVar2 == (undefined2 *)0x0) {
    iVar1 = -0x3fffff66;
  }
  else {
    *puVar2 = 0x180;
    puVar2[1] = (short)local_110;
    local_118 = local_110;
    local_120 = puVar2;
    local_68 = param_3;
    iVar1 = LwfvSwitchIssueSyncOidRequest(param_1,(longlong)&local_148,param_3);
    if (iVar1 == 0) {
      *param_4 = puVar2;
    }
    else {
      ExFreePoolWithTag(puVar2,0x67326c57);
    }
  }
  return iVar1;
}



===== vSwitchp802_3IsNblPermitted @ 140019bdc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
vSwitchp802_3IsNblPermitted
          (longlong param_1,longlong param_2,ushort param_3,char param_4,longlong *param_5,
          longlong param_6,undefined8 *param_7)

{
  uint uVar1;
  longlong *plVar2;
  char cVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong lVar6;
  int *piVar7;
  undefined1 uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  undefined1 auStackY_118 [32];
  undefined8 *in_stack_ffffffffffffff18;
  char local_a8;
  char local_a7;
  char local_a6;
  char local_a5;
  bool local_a4;
  undefined1 local_a3;
  ushort local_a2;
  longlong local_a0;
  undefined8 *local_98;
  longlong *local_90;
  longlong local_88;
  longlong local_80;
  longlong local_78;
  int local_70 [6];
  ulonglong uStack_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_118;
  local_80 = param_6;
  piVar7 = (int *)0x0;
  local_a0 = 0;
  uVar11 = 0;
  iVar10 = 0;
  local_50 = 0;
  local_a6 = '\0';
  local_a5 = '\0';
  local_a7 = '\0';
  local_98 = param_7;
  local_a3 = 1;
  local_a4 = false;
  local_70[0] = 0;
  local_70[1] = 0;
  local_70[2] = 0;
  local_70[3] = 0;
  local_70[4] = 0;
  local_70[5] = 0;
  uStack_58 = 0;
  local_a2 = param_3;
  local_88 = param_2;
  local_78 = param_1;
  if (*(int *)((longlong)param_7 + 0x1c) == 1) {
    lVar6 = 0;
  }
  else {
    lVar6 = 1;
    if (*(int *)((longlong)param_7 + 0x1c) == 2) {
      (*DAT_14002c5b0)(*(undefined8 *)(param_2 + 0xa0),*param_5,&local_a0);
      uVar1 = *(uint *)(local_a0 + 8);
      if (uVar1 != 0) {
        do {
          if ((*(byte *)((ulonglong)(*(int *)(local_a0 + 4) * uVar11) + 6 +
                        *(longlong *)(local_a0 + 0x10)) & 1) == 0) break;
          uVar11 = uVar11 + 1;
        } while (uVar11 < uVar1);
      }
      lVar6 = 1;
      if (uVar11 == uVar1) {
        return 1;
      }
      piVar7 = (int *)((ulonglong)(uVar11 * *(int *)(local_a0 + 4)) + *(longlong *)(local_a0 + 0x10)
                      );
      local_a4 = *(int *)(local_a0 + 0xc) == 1;
    }
  }
  iVar9 = (int)lVar6;
  local_a8 = param_4;
  if ((((*(int *)((longlong)local_98 + 0x1c) == 1) || (local_a4)) && (param_1 != 0)) &&
     (*(longlong *)(param_1 + 0x78 + lVar6 * 0x10) != 0)) {
    local_90 = (longlong *)0x0;
    uVar4 = L2FlowRetrieveContext(param_1,iVar9,local_98,&local_90);
    plVar2 = local_90;
    if (((int)uVar4 < 0) || (param_2 = local_88, local_90 == (longlong *)0x0)) goto LAB_140019e0c;
    local_90 = (longlong *)((ulonglong)local_90 & 0xffffffff00000000);
    KfdGetLayerCacheEpoch(local_a2,&local_90);
    if (((*(int *)((longlong)plVar2 + 0x2c) != (int)local_90) ||
        ((piVar7 != (int *)0x0 && ((int)plVar2[5] != *piVar7)))) ||
       (in_stack_ffffffffffffff18 = local_98,
       cVar3 = vSwitchp802_3LayerDirectClassify
                         (local_88,local_a2,param_4,*param_5,local_80,piVar7,(longlong)local_98,
                          plVar2,local_70,&local_a6), cVar3 == '\0')) {
      L2FlowRemoveContext(param_1,iVar9);
      L2DereferenceLayerClassifyCache((longlong)plVar2);
      param_2 = local_88;
      goto LAB_140019e0c;
    }
    if (piVar7 != (int *)0x0) {
      if (local_70[0] == 0x1001) {
        *(ushort *)((longlong)piVar7 + 6) = *(ushort *)((longlong)piVar7 + 6) | 1;
        local_a5 = '\x01';
      }
      else {
        iVar10 = 1;
      }
    }
    L2DereferenceLayerClassifyCache((longlong)plVar2);
    param_2 = local_88;
  }
  else {
LAB_140019e0c:
    do {
      in_stack_ffffffffffffff18 =
           (undefined8 *)CONCAT71((int7)((ulonglong)in_stack_ffffffffffffff18 >> 8),local_a4);
      vSwitchp802_3LayerRegularClassify
                (local_78,param_2,local_a2,local_a8,*param_5,local_80,local_a4,piVar7,local_98,iVar9
                 ,local_a7,local_70,&local_a6);
      if (local_a0 != 0) {
        if (local_70[0] == 0x1001) {
          *(ushort *)((longlong)piVar7 + 6) = *(ushort *)((longlong)piVar7 + 6) | 1;
          local_a5 = '\x01';
        }
        else {
          iVar10 = iVar10 + 1;
        }
        uVar1 = uVar11;
        do {
          uVar1 = uVar1 + 1;
          uVar11 = 0xffffffff;
          if (*(uint *)(local_a0 + 8) <= uVar1) break;
          uVar11 = uVar1;
        } while ((*(byte *)((ulonglong)(uVar1 * *(int *)(local_a0 + 4)) + 6 +
                           *(longlong *)(local_a0 + 0x10)) & 1) != 0);
        if (uVar11 == 0xffffffff) break;
        local_a8 = '\x01';
        local_a7 = '\x01';
        piVar7 = (int *)((ulonglong)(uVar11 * *(int *)(local_a0 + 4)) +
                        *(longlong *)(local_a0 + 0x10));
      }
    } while (piVar7 != (int *)0x0);
  }
  cVar3 = local_a6;
  if (local_a0 == 0) {
LAB_140019f5d:
    if (local_70[0] == 0x1001) {
      uVar8 = 0;
      if ((uStack_58 & 0x100000000) == 0) {
        if (*(int *)((longlong)local_98 + 0x1c) == 1) {
          lVar6 = local_80;
          lVar5 = L2GetvSwitchPortUnsafe(param_2,(uint)*(ushort *)(local_80 + 2));
          if (((lVar5 == 0) ||
              (lVar6 = (ulonglong)(*(ushort *)(lVar6 + 4) & 0xff) * 0x8b8 +
                       *(longlong *)(lVar5 + 0x448), *(char *)(lVar6 + 0x8b1) == '\0')) ||
             (lVar6 == 0)) {
            lVar6 = 0;
          }
          vSwitchReportPacketDrop
                    (*param_5,1,-0x3fffffde,*(undefined8 *)(param_2 + 0xa0),lVar6,'\0',
                     (longlong)in_stack_ffffffffffffff18);
        }
      }
      else {
        if (cVar3 != '\0') {
          L2DereferenceNetBufferListContext(*param_5);
        }
        *param_5 = 0;
      }
      goto LAB_140019ff8;
    }
  }
  else {
    if ((local_a5 != '\0') &&
       (vSwitchReportPacketDrop
                  (*param_5,2,-0x3fffffde,*(undefined8 *)(param_2 + 0xa0),0,'\x01',
                   (longlong)in_stack_ffffffffffffff18), iVar10 != 0)) {
      (*DAT_14002c5b8)(*(undefined8 *)(param_2 + 0xa0),*param_5,0,local_a0);
    }
    if ((local_a0 == 0) || (iVar10 == 0)) goto LAB_140019f5d;
    if (local_70[0] == 0x1001) {
      local_70[0] = 0x1002;
      goto LAB_140019f5d;
    }
  }
  uVar8 = local_a3;
LAB_140019ff8:
  if (((uStack_58 & 0x100000000) == 0) && (cVar3 != '\0')) {
    L2FreeNetBufferListContext(*param_5);
  }
  return uVar8;
}



===== vSwitchp802_3LayerDirectClassify @ 14001a03c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char vSwitchp802_3LayerDirectClassify
               (longlong param_1,ushort param_2,char param_3,longlong param_4,longlong param_5,
               undefined4 *param_6,longlong param_7,longlong *param_8,int *param_9,
               undefined1 *param_10)

{
  char cVar1;
  ulonglong uVar2;
  undefined1 uVar3;
  undefined1 auStackY_1c8 [32];
  undefined1 local_168 [224];
  undefined4 local_88;
  undefined4 local_80;
  uint local_78;
  ushort local_74;
  undefined4 local_70;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1c8;
  cVar1 = '\x01';
  memset(local_168,0,0x118);
  uVar3 = 0;
  if ((longlong *)*param_8 == param_8) {
    *param_9 = 0x1002;
  }
  else {
    local_88 = 0xd;
    local_80 = *(undefined4 *)(param_7 + 0x18);
    local_78 = (uint)*(ushort *)(param_5 + 2);
    local_74 = *(ushort *)(param_5 + 4) & 0xff;
    if (param_6 != (undefined4 *)0x0) {
      local_70 = *param_6;
      local_88 = 0x2d;
    }
    if ((*(int *)((longlong)param_8 + 0x14) != 0) && (param_3 == '\0')) {
      uVar2 = L2pAllocateNetBufferListContext(param_4,'\0',param_1,'\x01',param_2,0,0);
      if ((int)uVar2 != 0) {
        cVar1 = '\0';
        goto LAB_14001a1c3;
      }
      uVar3 = 1;
    }
    cVar1 = KfdDirectClassify(param_2,param_8[4],local_168,param_4);
    if (((cVar1 != '\0') && (*param_9 == 0x1001)) && ((param_9[7] & 1U) == 0)) {
      vSwitchAuditAndDiagPacketDrop
                (param_2,param_4,*(longlong *)(param_8[4] + 8),param_5,param_6,(longlong)param_9);
    }
  }
LAB_14001a1c3:
  *param_10 = uVar3;
  return cVar1;
}



===== vSwitchp802_3LayerRegularClassify @ 14001a208 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void vSwitchp802_3LayerRegularClassify
               (longlong param_1,longlong param_2,ushort param_3,char param_4,longlong param_5,
               longlong param_6,char param_7,int *param_8,undefined8 *param_9,int param_10,
               char param_11,int *param_12,char *param_13)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  uint uVar7;
  int *piVar8;
  undefined1 auStackY_508 [32];
  uint *puVar9;
  uint *puVar10;
  char local_4a8;
  undefined8 ***local_498;
  undefined8 ***pppuStack_490;
  ushort local_488 [2];
  undefined4 local_484;
  undefined4 *local_480;
  longlong local_478;
  int *local_470;
  longlong local_468;
  longlong local_460;
  uint local_458 [4];
  uint local_448 [4];
  uint local_438 [4];
  uint local_428 [4];
  uint local_418 [4];
  undefined1 local_408 [224];
  uint local_328;
  uint local_324;
  undefined4 local_320;
  uint local_318;
  ushort local_314;
  undefined4 local_310;
  undefined8 ***local_208;
  undefined4 local_1f4;
  int local_1f0;
  undefined4 local_158 [68];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_508;
  lVar4 = 0;
  local_470 = param_8;
  local_468 = param_6;
  local_488[1] = 0;
  local_478 = param_1;
  memset(local_408,0,0x2a8);
  local_4a8 = '\0';
  local_418[2] = 0;
  local_428[2] = 0;
  local_438[2] = 0;
  local_448[2] = 0;
  local_458[2] = 0;
  local_418[0] = 0;
  local_418[1] = 0;
  local_428[0] = 0;
  local_428[1] = 0;
  local_438[0] = 0;
  local_438[1] = 0;
  local_448[0] = 0;
  local_448[1] = 0;
  local_458[0] = 0;
  local_458[1] = 0;
  uVar1 = (uint)*(ushort *)(param_6 + 2);
  local_498 = (undefined8 ***)0x0;
  pppuStack_490 = (undefined8 ***)0x0;
  lVar3 = L2GetvSwitchPortUnsafe(param_2,uVar1);
  piVar8 = local_470;
  local_460 = lVar3;
  if (local_470 != (int *)0x0) {
    lVar4 = L2GetvSwitchPortUnsafe(param_2,*local_470);
  }
  puVar10 = local_428;
  puVar9 = local_418;
  uVar5 = vSwitchpMarshal802_3LayerFields
                    (param_2,lVar3,lVar4,param_9,param_6,(longlong)piVar8,puVar9,puVar10,local_438,
                     local_448,local_458,local_158);
  local_320 = *(undefined4 *)(param_9 + 3);
  uVar7 = 5;
  local_328 = 5;
  if (local_460 != 0) {
    uVar7 = 0xd;
    local_328 = 0xd;
    local_314 = *(ushort *)(param_6 + 4) & 0xff;
  }
  if (lVar4 != 0) {
    local_328 = uVar7 | 0x20;
    local_310 = *(undefined4 *)(lVar4 + 0x28);
  }
  if (param_11 != '\0') {
    local_324 = local_324 | 8;
  }
  if ((*(int *)((longlong)param_9 + 0x1c) == 1) || (param_7 != '\0')) {
    pppuStack_490 = &local_498;
    local_1f4 = 1;
    local_498 = &local_498;
    local_208 = &local_498;
  }
  local_480 = local_158;
  local_484 = (undefined4)uVar5;
  local_488[0] = param_3;
  local_318 = uVar1;
  if ((param_4 == '\0') && (*param_13 == '\0')) {
    puVar9 = (uint *)((ulonglong)puVar9 & 0xffffffff00000000);
    uVar6 = L2pAllocateNetBufferListContext(param_5,'\0',param_2,'\x01',param_3,0,0);
    iVar2 = (int)uVar6;
    if (iVar2 == 0) {
      local_4a8 = '\x01';
      goto LAB_14001a45d;
    }
    if ((((iVar2 == 0x103) || (iVar2 == -0x7ffffffb)) || (iVar2 == -0x3fffffff)) ||
       ((iVar2 == -0x3fffff66 || (iVar2 == -0x3fffff45)))) goto LAB_14001a486;
  }
  else {
LAB_14001a45d:
    iVar2 = KfdClassify(param_3,local_488,local_408);
LAB_14001a486:
    if (-1 < iVar2) {
      if (param_1 == 0) {
        if ((local_1f0 == 0) || ((*(int *)((longlong)param_9 + 0x1c) != 1 && (param_7 == '\0'))))
        goto LAB_14001a593;
        uVar5 = L2CreatevSwitchFlow(*(longlong *)(param_2 + 0x98),
                                    *(short *)((longlong)param_9 + 0x12),(byte *)*param_9,
                                    (byte *)param_9[1],*(short *)((longlong)param_9 + 0x14),
                                    (uint)*(ushort *)(local_468 + 2),puVar9,puVar10,&local_478);
        if ((int)uVar5 < 0) {
          KfdReleaseCachedFilters(&local_498);
        }
        param_1 = local_478;
        if (local_478 == 0) goto LAB_14001a593;
      }
      if ((local_1f0 != 0) && ((*(int *)((longlong)param_9 + 0x1c) == 1 || (param_7 != '\0')))) {
        uVar6 = vSwitchpCacheMatched802_3LayerFilterList
                          (param_1,lVar4,param_10,(longlong)local_408,local_488);
        if ((int)uVar6 < 0) {
          KfdReleaseCachedFilters(&local_498);
        }
      }
      goto LAB_14001a593;
    }
  }
  *param_12 = 0x1001;
LAB_14001a593:
  if ((*param_12 == 0x1001) && ((param_12[7] & 1U) == 0)) {
    vSwitchAuditAndDiagPacketDrop
              (param_3,param_5,(longlong)local_158,local_468,local_470,(longlong)param_12);
  }
  if (*param_13 == '\0') {
    *param_13 = local_4a8;
  }
  return;
}



===== vSwitchpCacheMatched802_3LayerFilterList @ 14001a60c =====

ulonglong vSwitchpCacheMatched802_3LayerFilterList
                    (longlong param_1,longlong param_2,int param_3,longlong param_4,
                    undefined8 param_5)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong local_18 [2];
  
  local_18[0] = 0;
  uVar1 = L2CreateLayerClassifyCache(param_2,param_4,param_5,param_4,local_18);
  lVar2 = local_18[0];
  if (-1 < (int)uVar1) {
    uVar1 = L2FlowAssociateContext(param_1,param_3,L2p802_3FlowEventCallback,local_18[0]);
    if (-1 < (int)uVar1) {
      lVar2 = 0;
    }
    local_18[0] = lVar2;
  }
  if (local_18[0] != 0) {
    L2FreeLayerClassifyCache(local_18);
  }
  return uVar1 & 0xffffffff;
}



===== vSwitchpMarshal802_3LayerFields @ 14001a6ac =====

undefined8
vSwitchpMarshal802_3LayerFields
          (longlong param_1,longlong param_2,longlong param_3,undefined8 *param_4,longlong param_5,
          longlong param_6,uint *param_7,uint *param_8,uint *param_9,uint *param_10,uint *param_11,
          undefined4 *param_12)

{
  undefined4 *puVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  ulonglong uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint local_res8 [2];
  
  puVar1 = param_12;
  uVar6 = 0;
  local_res8[0] = 0;
  param_12._0_1_ = '\0';
  uVar7 = -(uint)(*(char *)(param_4 + 2) != '\0') & 0x20;
  if (((param_2 != 0) && (param_3 != 0)) && (*(int *)(param_2 + 0x28) == *(int *)(param_3 + 0x28)))
  {
    uVar7 = uVar7 | 0x10;
  }
  *(longlong *)(param_7 + 2) = *(longlong *)(param_1 + 0x70) + 10;
  *param_7 = (uint)*(ushort *)(*(longlong *)(param_1 + 0x70) + 8);
  *puVar1 = 0x12;
  *(undefined8 *)(puVar1 + 2) = *param_4;
  puVar1[4] = 1;
  iVar2 = EthernetAddressType((byte *)*param_4);
  *(char *)(puVar1 + 6) = (char)iVar2;
  puVar1[8] = 0x12;
  *(undefined8 *)(puVar1 + 10) = param_4[1];
  puVar1[0xc] = 1;
  iVar2 = EthernetAddressType((byte *)param_4[1]);
  *(char *)(puVar1 + 0xe) = (char)iVar2;
  puVar1[0x10] = 2;
  *(undefined2 *)(puVar1 + 0x12) = *(undefined2 *)((longlong)param_4 + 0x12);
  puVar1[0x14] = 0;
  puVar1[0x18] = 0;
  L2DeterminevSwitchVLanTenantId
            (*(ushort *)((longlong)param_4 + 0x14),*(uint *)(param_4 + 4),param_2,local_res8,
             (undefined1 *)&param_12);
  if (local_res8[0] != 0) {
    if ((char)param_12 == '\0') {
      puVar1[0x14] = 2;
      *(short *)(puVar1 + 0x16) = (short)local_res8[0];
    }
    else {
      puVar1[0x18] = 3;
      puVar1[0x1a] = local_res8[0];
    }
  }
  *(uint **)(puVar1 + 0x1e) = param_7;
  puVar1[0x1c] = 0xc;
  puVar1[0x20] = 1;
  *(undefined1 *)(puVar1 + 0x22) = *(undefined1 *)(param_1 + 0x90);
  if (param_2 == 0) {
    puVar1[0x24] = 0;
    puVar1[0x28] = 0;
    uVar4 = 0;
  }
  else {
    uVar5 = (ulonglong)(*(ushort *)(param_5 + 4) & 0xff) * 0x8b8 + *(longlong *)(param_2 + 0x448);
    uVar5 = -(ulonglong)(*(char *)(uVar5 + 0x8b1) != '\0') & uVar5;
    *(ulonglong *)(param_8 + 2) = uVar5 + 10;
    *param_8 = (uint)*(ushort *)(uVar5 + 8);
    puVar1[0x24] = 0xc;
    *(uint **)(puVar1 + 0x26) = param_8;
    puVar1[0x28] = 1;
    *(undefined1 *)(puVar1 + 0x2a) = *(undefined1 *)(uVar5 + 0x418);
    if ((*(int *)(uVar5 + 0x418) == 1) || (*(int *)(uVar5 + 0x418) == 2)) {
      *(ulonglong *)(param_10 + 2) = uVar5 + 0x422;
      *param_10 = (uint)*(ushort *)(uVar5 + 0x420);
      *(uint **)(puVar1 + 0x2e) = param_10;
      uVar4 = 0xc;
    }
    else {
      uVar4 = 0;
    }
  }
  puVar1[0x2c] = uVar4;
  if (*(int *)((longlong)param_4 + 0x1c) == 1) {
    puVar1[0x30] = 3;
    puVar1[0x32] = uVar7;
    puVar1[0x34] = 3;
    puVar1[0x36] = *(undefined4 *)(param_1 + 0x3dc);
    uVar3 = 0xe;
  }
  else {
    if ((param_3 == 0) || (param_6 == 0)) {
      puVar1[0x30] = 0;
      puVar1[0x34] = 0;
    }
    else {
      uVar5 = (ulonglong)*(ushort *)(param_6 + 4) * 0x8b8 + *(longlong *)(param_3 + 0x448);
      uVar5 = -(ulonglong)(*(char *)(uVar5 + 0x8b1) != '\0') & uVar5;
      *(ulonglong *)(param_9 + 2) = uVar5 + 10;
      *param_9 = (uint)*(ushort *)(uVar5 + 8);
      puVar1[0x30] = 0xc;
      *(uint **)(puVar1 + 0x32) = param_9;
      puVar1[0x34] = 1;
      *(undefined1 *)(puVar1 + 0x36) = *(undefined1 *)(uVar5 + 0x418);
      if ((*(int *)(uVar5 + 0x418) == 1) || (*(int *)(uVar5 + 0x418) == 2)) {
        uVar6 = 0xc;
        *(ulonglong *)(param_11 + 2) = uVar5 + 0x422;
        *param_11 = (uint)*(ushort *)(uVar5 + 0x420);
        *(uint **)(puVar1 + 0x3a) = param_11;
      }
    }
    puVar1[0x38] = uVar6;
    puVar1[0x3c] = 3;
    puVar1[0x3e] = uVar7;
    puVar1[0x40] = 3;
    puVar1[0x42] = *(undefined4 *)(param_1 + 0x3dc);
    uVar3 = 0x11;
  }
  return uVar3;
}



===== vSwitchAuditAndDiagPacketDrop @ 14001aa18 =====

void vSwitchAuditAndDiagPacketDrop
               (ushort param_1,longlong param_2,longlong param_3,longlong param_4,
               undefined4 *param_5,longlong param_6)

{
  vSwitchpAuditPacketDrop(param_4,param_5,param_1,param_3,*(undefined8 *)(param_6 + 0x10));
  if ((*(uint *)(param_6 + 0x20) & 0x10000000) != 0) {
    vSwitchpAuditPacketVeto(param_4,param_5,param_1,param_3,*(undefined8 *)(param_6 + 0x10));
  }
  vSwitchpDiagnosePacketDrop
            (param_4,param_5,param_1,param_2,param_3,*(undefined8 *)(param_6 + 0x10));
  return;
}



===== vSwitchpAuditPacketDrop @ 14001aac8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void vSwitchpAuditPacketDrop
               (longlong param_1,undefined4 *param_2,ushort param_3,longlong param_4,
               undefined8 param_5)

{
  undefined8 uVar1;
  undefined1 auStackY_3c8 [32];
  undefined4 local_398 [66];
  ulonglong local_290;
  undefined8 local_280;
  undefined4 local_278;
  undefined2 local_240;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_3c8;
  uVar1 = 0x368;
  memset(local_398,0,0x368);
  vSwitchpFillCommonAuditDiagEventInfo(param_1,param_2,uVar1,param_4,(longlong)local_398);
  local_280 = param_5;
  local_240 = 0x10;
  local_278 = 0x141a;
  local_398[0] = 1;
  local_290 = (ulonglong)param_3;
  KfdAuditEvent(local_398);
  return;
}



===== vSwitchpAuditPacketVeto @ 14001ab94 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void vSwitchpAuditPacketVeto
               (longlong param_1,undefined4 *param_2,ushort param_3,longlong param_4,
               undefined8 param_5)

{
  undefined8 uVar1;
  undefined1 auStackY_3c8 [32];
  undefined4 local_398 [66];
  ulonglong local_290;
  undefined8 local_280;
  undefined4 local_278;
  undefined2 local_240;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_3c8;
  uVar1 = 0x368;
  memset(local_398,0,0x368);
  vSwitchpFillCommonAuditDiagEventInfo(param_1,param_2,uVar1,param_4,(longlong)local_398);
  local_280 = param_5;
  local_240 = 0x10;
  local_278 = 0x141b;
  local_398[0] = 2;
  local_290 = (ulonglong)param_3;
  KfdAuditEvent(local_398);
  return;
}



===== vSwitchpDiagnosePacketDrop @ 14001ac60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void vSwitchpDiagnosePacketDrop
               (longlong param_1,undefined4 *param_2,ushort param_3,longlong param_4,
               longlong param_5,undefined8 param_6)

{
  ulonglong uVar1;
  undefined8 uVar2;
  undefined1 auStackY_3c8 [32];
  undefined1 local_398 [264];
  ulonglong local_290;
  undefined8 local_280;
  ulonglong local_228;
  undefined1 local_d8;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_3c8;
  uVar1 = *(ulonglong *)(param_4 + 0xf8);
  uVar2 = 0x368;
  memset(local_398,0,0x368);
  vSwitchpFillCommonAuditDiagEventInfo(param_1,param_2,uVar2,param_5,(longlong)local_398);
  local_280 = param_6;
  local_228 = uVar1 & 0x7fffffffffffffff;
  local_d8 = 1;
  local_290 = (ulonglong)param_3;
  KfdDiagnoseEvent(local_398);
  return;
}



===== vSwitchpFillCommonAuditDiagEventInfo @ 14001ad40 =====

void vSwitchpFillCommonAuditDiagEventInfo
               (longlong param_1,undefined4 *param_2,undefined8 param_3,longlong param_4,
               longlong param_5)

{
  undefined2 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  *(undefined2 *)(param_5 + 8) = 0x21;
  *(undefined2 *)(param_5 + 0x88) = 0x21;
  *(uint *)(param_5 + 0x110) = (uint)*(ushort *)(param_4 + 0x48);
  puVar2 = *(undefined4 **)(param_4 + 8);
  *(undefined4 *)(param_5 + 10) = *puVar2;
  *(undefined2 *)(param_5 + 0xe) = *(undefined2 *)(puVar2 + 1);
  puVar2 = *(undefined4 **)(param_4 + 0x28);
  *(undefined4 *)(param_5 + 0x8a) = *puVar2;
  *(undefined2 *)(param_5 + 0x8e) = *(undefined2 *)(puVar2 + 1);
  if (*(int *)(param_4 + 0x50) != 0) {
    *(undefined2 *)(param_5 + 0x198) = *(undefined2 *)(param_4 + 0x58);
  }
  *(undefined8 *)(param_5 + 0x2b0) = *(undefined8 *)(*(longlong *)(param_4 + 0x78) + 8);
  uVar1 = **(undefined2 **)(param_4 + 0x78);
  *(undefined2 *)(param_5 + 0x2a8) = uVar1;
  *(undefined2 *)(param_5 + 0x2aa) = uVar1;
  *(uint *)(param_5 + 0x2b8) = (uint)*(ushort *)(param_1 + 2);
  if (param_2 == (undefined4 *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *param_2;
  }
  *(undefined4 *)(param_5 + 700) = uVar3;
  *(undefined4 *)(param_5 + 0x19c) = 0;
  *(uint *)(param_5 + 0x194) = (uint)*(byte *)(param_4 + 0xa8);
  return;
}



===== vSwitchClearIovOffloaded @ 14001ae0c =====

void vSwitchClearIovOffloaded(longlong param_1,int param_2)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  longlong *plVar4;
  
  plVar4 = (longlong *)L2GetvSwitchPortUnsafe(param_1,param_2);
  lVar1 = *plVar4;
  if ((*(longlong **)(lVar1 + 8) == plVar4) &&
     (plVar2 = (longlong *)plVar4[1], (longlong *)*plVar2 == plVar4)) {
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



===== vSwitchIsIovOffloadPossible @ 14001ae44 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 vSwitchIsIovOffloadPossible(longlong param_1,longlong param_2,longlong param_3)

{
  bool bVar1;
  ulonglong uVar2;
  undefined7 extraout_var;
  undefined1 uVar3;
  ulonglong uVar4;
  undefined1 auStackY_78 [32];
  ushort local_48 [8];
  ulonglong local_38;
  
  uVar2 = __security_cookie ^ (ulonglong)auStackY_78;
  local_38 = uVar2;
  local_48[0] = 0x48;
  local_48[1] = 0x4a;
  local_48[2] = 0x4b;
  local_48[3] = 0x49;
  local_48[4] = 0x4c;
  local_48[5] = 0x4d;
  uVar3 = 1;
  uVar4 = 0;
  do {
    if (5 < (uint)uVar4) {
LAB_14001aeb0:
      return CONCAT71((int7)(uVar2 >> 8),uVar3);
    }
    bVar1 = vSwitchIsIovOffloadPossibleForLayer
                      (local_48[uVar4],param_1,*(int *)(param_2 + 8),
                       (ulonglong)*(ushort *)(param_2 + 0xc),param_3);
    uVar2 = CONCAT71(extraout_var,bVar1);
    if (!bVar1) {
      uVar3 = 0;
      goto LAB_14001aeb0;
    }
    uVar4 = (ulonglong)((uint)uVar4 + 1);
  } while( true );
}



===== vSwitchIsIovOffloadPossibleForLayer @ 14001aed4 =====

bool vSwitchIsIovOffloadPossibleForLayer
               (ushort param_1,longlong param_2,int param_3,ulonglong param_4,longlong param_5)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  byte *pbVar5;
  ulonglong uVar6;
  
  lVar3 = L2GetvSwitchPortUnsafe(param_2,param_3);
  pbVar5 = (byte *)0x0;
  uVar6 = (param_4 & 0xffff) * 0x8b8 + *(longlong *)(lVar3 + 0x448);
  uVar6 = -(ulonglong)(*(char *)(uVar6 + 0x8b1) != '\0') & uVar6;
  if ((param_5 != 0) && (*(short *)(param_5 + 0x618) == 6)) {
    pbVar5 = (byte *)(param_5 + 0x63a);
  }
  uVar4 = L2IsInboundLayer((uint)param_1);
  if ((char)uVar4 == '\0') {
    iVar2 = KfdIsLayerEmpty();
    if (iVar2 != 0) {
      return true;
    }
    cVar1 = vSwitchpFilterExistAffectingvSwitchAndvmNic
                      (param_1,param_2,*(undefined4 *)(lVar3 + 0x46c),uVar6,0,pbVar5,(byte *)0x0);
    if ((cVar1 == '\0') &&
       (cVar1 = vSwitchpFilterExistAffectingvSwitchAndvmNic
                          (param_1,param_2,*(undefined4 *)(lVar3 + 0x46c),uVar6,0,(byte *)0x0,pbVar5
                          ), cVar1 == '\0')) {
      return true;
    }
  }
  else {
    iVar2 = KfdIsLayerEmpty();
    if (iVar2 != 0) {
      return true;
    }
    cVar1 = vSwitchpFilterExistAffectingvSwitchAndvmNic
                      (param_1,param_2,*(undefined4 *)(lVar3 + 0x46c),uVar6,0,pbVar5,(byte *)0x0);
    if (((cVar1 == '\0') &&
        (cVar1 = vSwitchpFilterExistAffectingvSwitchAndvmNic
                           (param_1,param_2,*(undefined4 *)(lVar3 + 0x46c),uVar6,0,(byte *)0x0,
                            pbVar5), cVar1 == '\0')) &&
       (cVar1 = vSwitchpFilterExistAffectingvSwitchAndvmNic
                          (param_1,param_2,*(undefined4 *)(lVar3 + 0x46c),0,uVar6,pbVar5,(byte *)0x0
                          ), cVar1 == '\0')) {
      cVar1 = vSwitchpFilterExistAffectingvSwitchAndvmNic
                        (param_1,param_2,*(undefined4 *)(lVar3 + 0x46c),0,uVar6,(byte *)0x0,pbVar5);
      return cVar1 == '\0';
    }
  }
  return false;
}



===== vSwitchpFilterExistAffectingvSwitchAndvmNic @ 14001b0a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
vSwitchpFilterExistAffectingvSwitchAndvmNic
          (short param_1,longlong param_2,undefined4 param_3,longlong param_4,longlong param_5,
          byte *param_6,byte *param_7)

{
  ushort uVar1;
  char cVar2;
  int iVar3;
  longlong lVar4;
  undefined1 uVar5;
  int iVar6;
  ulonglong uVar7;
  undefined1 auStack_268 [40];
  ulonglong local_240;
  undefined8 uStack_238;
  undefined2 *local_230;
  undefined4 local_228;
  undefined2 local_224;
  ulonglong local_220;
  longlong lStack_218;
  uint local_210 [2];
  longlong local_208;
  undefined8 local_200;
  undefined8 uStack_1f8;
  undefined8 local_1f0;
  undefined8 uStack_1e8;
  undefined8 local_1e0;
  undefined2 local_1d8 [2];
  undefined8 local_1d4;
  uint *local_1c8;
  undefined2 local_1c0;
  undefined4 local_1bc;
  undefined4 local_1b8;
  undefined1 local_1b0;
  undefined2 local_1a8;
  undefined4 local_1a4;
  undefined4 local_1a0;
  undefined4 local_198;
  undefined2 local_190 [2];
  undefined4 local_18c [3];
  ulonglong *local_180;
  undefined2 local_178 [2];
  undefined4 local_174 [3];
  undefined1 local_168 [8];
  undefined2 local_160;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_268;
  local_230 = (undefined2 *)0x0;
  local_228 = 0;
  local_224 = 0;
  local_1e0 = 0;
  local_210[1] = 0;
  uVar5 = 0;
  local_240 = 0;
  uStack_238 = 0;
  local_208 = *(longlong *)(param_2 + 0x70) + 10;
  local_220 = 0;
  lStack_218 = 0;
  local_200 = 0;
  uStack_1f8 = 0;
  local_1f0 = 0;
  uStack_1e8 = 0;
  local_210[0] = (uint)*(ushort *)(*(longlong *)(param_2 + 0x70) + 8);
  if (param_4 == 0) {
    if (param_5 != 0) {
      uVar5 = (undefined1)*(undefined4 *)(param_5 + 0x418);
      uVar1 = *(ushort *)(param_5 + 8);
      lStack_218 = param_5;
      goto LAB_14001b16c;
    }
  }
  else {
    uVar5 = (undefined1)*(undefined4 *)(param_4 + 0x418);
    uVar1 = *(ushort *)(param_4 + 8);
    lStack_218 = param_4;
LAB_14001b16c:
    lStack_218 = lStack_218 + 10;
    local_220 = (ulonglong)uVar1;
  }
  if (param_1 == 0x48) {
    local_1a8 = 5;
    if (param_4 != 0) {
      local_190[0] = 9;
      local_178[0] = 10;
    }
    if (param_6 == (byte *)0x0) {
      if (param_7 != (byte *)0x0) {
        *(undefined2 *)((longlong)local_190 + (ulonglong)(-(uint)(param_4 != 0) & 0x30)) = 2;
        *(undefined2 *)((longlong)local_178 + (ulonglong)(-(uint)(param_4 != 0) & 0x30)) = 3;
      }
    }
    else {
      *(undefined2 *)((longlong)local_190 + (ulonglong)(-(uint)(param_4 != 0) & 0x30)) = 0;
      *(undefined2 *)((longlong)local_178 + (ulonglong)(-(uint)(param_4 != 0) & 0x30)) = 1;
    }
  }
  else if (param_1 == 0x49) {
    local_1a8 = 5;
    lVar4 = 3;
    if (param_4 == 0) {
      if (param_5 != 0) {
        local_160 = 5;
        local_190[0] = 0xc;
        local_178[0] = 0xd;
        lVar4 = 6;
      }
    }
    else {
      lVar4 = 5;
      local_190[0] = 9;
      local_178[0] = 10;
    }
    if (param_6 == (byte *)0x0) {
      if (param_7 != (byte *)0x0) {
        local_1d8[lVar4 * 0xc] = 2;
        local_1d8[(ulonglong)((int)lVar4 + 1) * 0xc] = 3;
      }
    }
    else {
      local_1d8[lVar4 * 0xc] = 0;
      local_1d8[(ulonglong)((int)lVar4 + 1) * 0xc] = 1;
    }
  }
  else if ((param_1 == 0x4a) || (param_1 == 0x4b)) {
    if (param_4 != 0) {
      local_1a8 = 9;
      local_190[0] = 10;
    }
  }
  else if (param_4 == 0) {
    if (param_5 != 0) {
      local_1a8 = 0xc;
      local_190[0] = 0xd;
    }
  }
  else {
    local_1a8 = 9;
    local_190[0] = 10;
  }
  local_1c0 = 8;
  local_1d8[0] = 7;
  local_1d4._4_4_ = 0xc;
  local_1c8 = local_210;
  local_1b0 = *(undefined1 *)(param_2 + 0x90);
  local_1a0 = 3;
  lVar4 = 3;
  local_1d4._0_4_ = 0;
  local_1b8 = 1;
  local_1bc = 0;
  local_1a4 = 0;
  if ((param_4 != 0) || (param_5 != 0)) {
    local_18c[0] = 0;
    local_18c[1] = 0xc;
    lVar4 = 5;
    local_180 = &local_220;
    local_174[1] = 1;
    local_174[0] = 0;
    local_168[0] = uVar5;
  }
  iVar6 = (int)lVar4;
  local_198 = param_3;
  if ((param_6 != (byte *)0x0) || (param_6 = param_7, param_7 != (byte *)0x0)) {
    uVar7 = (ulonglong)(iVar6 + 1);
    *(undefined4 *)((longlong)&local_1d4 + (lVar4 * 6 + 1) * 4) = 0x12;
    *(byte **)((longlong)&local_1d4 + (lVar4 * 6 + 3) * 4) = param_6;
    *(undefined4 *)(&local_1d4 + lVar4 * 3) = 0;
    *(undefined4 *)((longlong)&local_1d4 + (uVar7 * 6 + 1) * 4) = 1;
    iVar3 = EthernetAddressType(param_6);
    *(char *)((longlong)&local_1d4 + (uVar7 * 6 + 3) * 4) = (char)iVar3;
    iVar6 = iVar6 + 2;
    *(undefined4 *)(&local_1d4 + uVar7 * 3) = 0;
  }
  local_228 = 0xffffffff;
  local_230 = local_1d8;
  uStack_238 = CONCAT44(iVar6,0x22);
  local_240 = CONCAT62((int6)(local_240 >> 0x10),param_1) & 0xffffffff;
  lVar4 = KfdGetLayerActionFromEnumTemplate(param_1,&local_240,&local_200);
  if (lVar4 == 0) {
    cVar2 = vSwitchpFilterHasIpAddressPortFields((undefined2 *)&local_240);
    if (cVar2 == '\0') goto LAB_14001b472;
  }
  local_200._0_4_ = 7;
LAB_14001b472:
  if ((int)local_200 == 0x1002) {
    if ((param_1 != 0x49) && (1 < (ushort)(param_1 - 0x4cU))) {
      return 0;
    }
    if ((param_4 == 0) || (*(int *)(param_4 + 0x418) != 1)) {
      if (param_5 == 0) {
        return 0;
      }
      if (*(int *)(param_5 + 0x418) != 2) {
        return 0;
      }
    }
    local_1e0 = 0;
    local_200 = 0;
    uStack_1f8 = 0;
    local_1f0 = 0;
    uStack_1e8 = 0;
    if (((param_1 == 0x49) || (param_1 == 0x4c)) || (param_1 == 0x4d)) {
      local_1d8[0] = 0xf;
    }
    local_228 = 0xffffffff;
    local_230 = local_1d8;
    local_1d4._4_4_ = 3;
    local_1c8 = (uint *)CONCAT44(local_1c8._4_4_,0x10);
    local_1d4._0_4_ = 6;
    uStack_238 = 0x100000022;
    local_240 = CONCAT62((int6)(local_240 >> 0x10),param_1) & 0xffffffff;
    lVar4 = KfdGetLayerActionFromEnumTemplate(param_1,&local_240,&local_200);
    if (lVar4 != 0) {
      local_200._0_4_ = 7;
    }
    if ((int)local_200 == 0x1002) {
      return 0;
    }
  }
  return 1;
}



===== vSwitchpFilterHasIpAddressPortFields @ 14001b590 =====

char vSwitchpFilterHasIpAddressPortFields(undefined2 *param_1)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  short *psVar4;
  char cVar5;
  ulonglong uVar6;
  longlong local_res8;
  undefined4 local_res10 [2];
  longlong local_res18;
  undefined8 local_res20;
  
  local_res18 = 0;
  local_res10[0] = 0;
  uVar2 = KfdEnumLayer(*param_1,param_1,&local_res18,local_res10);
  uVar2 = uVar2 >> 0x1f;
  do {
    local_res20 = 0;
    local_res8 = 0;
    iVar3 = KfdGetNextFilter(&local_res18,&local_res8,&local_res20);
    if (iVar3 < 0) {
      uVar2 = 1;
      cVar5 = '\x01';
      if (iVar3 == -0x7fffffe6) break;
    }
    else {
      if (*(uint *)(local_res8 + 0x1c) != 0) {
        psVar4 = *(short **)(local_res8 + 0x20);
        uVar6 = (ulonglong)*(uint *)(local_res8 + 0x1c);
        do {
          sVar1 = *psVar4;
          if ((((sVar1 == 0) || (sVar1 == 1)) || (sVar1 == 3)) || (sVar1 == 4)) {
            uVar2 = 1;
          }
          psVar4 = psVar4 + 0xc;
          uVar6 = uVar6 - 1;
        } while (uVar6 != 0);
      }
      KfdDerefFilterContext(local_res20);
    }
    cVar5 = (char)uVar2;
  } while (cVar5 == '\0');
  if (local_res18 != 0) {
    KfdFreeEnumHandle();
  }
  return cVar5;
}



===== vSwitchCheckAndCompleteL3NetBufferLists @ 14001b660 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void vSwitchCheckAndCompleteL3NetBufferLists(undefined8 *param_1,char param_2,byte param_3)

{
  undefined8 *puVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  int iVar4;
  longlong local_res8;
  
  puVar1 = (undefined8 *)*param_1;
  while (puVar3 = param_1, param_1 = puVar1, param_1 != (undefined8 *)0x0) {
    puVar1 = (undefined8 *)*param_1;
    if (param_1[3] != 0) {
      local_res8 = 0;
      iVar4 = FwpsNetBufferListRetrieveContext0(param_1,2,0,0,&local_res8);
      if ((-1 < iVar4) &&
         (((param_2 == '\0' || (*(char *)(local_res8 + 0x4b) != '\0')) || (param_2 == '\0')))) {
        plVar2 = (longlong *)param_1[3];
        FwpsNetBufferListRetrieveContext0(param_1,2,1,0,&local_res8);
        (*DAT_14002c590)(*(undefined8 *)(local_res8 + 0x78),param_1);
        FwppDereferencevSwitchNblContext(local_res8);
        LOCK();
        *(int *)(param_1[3] + 0x84) = *(int *)(param_1[3] + 0x84) + -1;
        UNLOCK();
        NdisFreeCloneNetBufferList(param_1,0);
        *plVar2 = 0;
        vSwitchFlSendNetBufferListsComplete(param_1,plVar2,param_3 & 1);
        *puVar3 = puVar1;
        param_1 = puVar3;
      }
    }
  }
  return;
}



===== vSwitchFlReturnNetBufferLists @ 14001b798 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void vSwitchFlReturnNetBufferLists(undefined8 param_1,undefined8 *param_2,uint param_3)

{
  int *piVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  longlong ***ppplVar5;
  undefined8 *puVar6;
  longlong local_res8;
  longlong ***local_res10;
  longlong in_stack_ffffffffffffffc8;
  
  if (param_2 != (undefined8 *)0x0) {
    do {
      local_res8 = 0;
      FwpsNetBufferListRetrieveContext0(param_2,2,1,0,&local_res8);
      if ((*(int *)(local_res8 + 0x44) == -0x3fffffde) ||
         (*(int *)(local_res8 + 0x44) == -0x3fffff66)) {
        uVar3 = *param_2;
        *param_2 = 0;
        vSwitchReportPacketDrop
                  ((longlong)param_2,*(int *)(local_res8 + 0xc),*(int *)(local_res8 + 0x44),
                   *(undefined8 *)(local_res8 + 0x78),*(longlong *)(local_res8 + 0x30),
                   *(int *)(local_res8 + 0x44) == -0x3fffffde,in_stack_ffffffffffffffc8);
        *param_2 = uVar3;
      }
      lVar4 = *(longlong *)(local_res8 + 0x88);
      ppplVar5 = (longlong ***)param_2[3];
      local_res10 = ppplVar5;
      L2UpdateCompletedNblCounts(lVar4,1);
      LOCK();
      piVar1 = (int *)((longlong)ppplVar5 + 0x84);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -0x10001;
      UNLOCK();
      if ((iVar2 - 0x10001U & 0xffff0000) == 0) {
        if (((*(char *)(local_res8 + 0x48) == '\0') || (*(int *)(local_res8 + 0x44) != 0)) &&
           (*(int *)((longlong)param_2 + 0x8c) != -0x3fdcffd3)) {
          if (ppplVar5 != (longlong ***)0x0) {
            vSwitchpCompleteL3Inspection(lVar4,local_res8,(longlong *)&local_res10,param_3 & 1);
          }
        }
        else {
          *local_res10 = (longlong **)0x0;
          if (*(int *)(local_res8 + 0xc) == 1) {
            L2NdisFSendNetBufferLists
                      (lVar4,*(undefined8 *)(local_res8 + 0x80),local_res10,0,param_3 & 1);
          }
          else {
            L2NdisFIndicateReceiveNetBufferLists
                      (lVar4,*(undefined8 *)(lVar4 + 0x48),local_res10,0,1,param_3 & 1);
            local_res10 = (longlong ***)0x0;
          }
        }
      }
      puVar6 = (undefined8 *)*param_2;
      if ((*(longlong *)(local_res8 + 0x38) != 0) && (param_2[0x24] != 0)) {
        (*DAT_14002c590)(*(undefined8 *)(local_res8 + 0x78),param_2);
      }
      if (*(char *)(local_res8 + 0x72) == '\0') {
        NdisFreeCloneNetBufferList(param_2,0);
      }
      else {
        NdisFreeNetBufferList();
      }
      FwppDereferencevSwitchNblContext(local_res8);
      param_2 = puVar6;
    } while (puVar6 != (undefined8 *)0x0);
  }
  return;
}



===== vSwitchFlSendNetBufferLists @ 14001b980 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void vSwitchFlSendNetBufferLists(undefined8 param_1,longlong *param_2,uint param_3)

{
  int iVar1;
  undefined8 uVar2;
  longlong ***ppplVar3;
  longlong ***ppplVar4;
  longlong ***ppplVar5;
  longlong lVar6;
  longlong ***ppplVar7;
  longlong ***ppplVar8;
  longlong lVar9;
  longlong local_res10;
  longlong ***local_res20;
  longlong in_stack_ffffffffffffffa8;
  undefined8 local_48;
  longlong *local_40;
  
  ppplVar4 = (longlong ***)0x0;
  ppplVar8 = (longlong ***)0x0;
  iVar1 = 0;
  ppplVar5 = (longlong ***)0x0;
  ppplVar7 = (longlong ***)0x0;
  local_res20 = (longlong ***)0x0;
  lVar6 = 0;
  lVar9 = 0;
  if (param_2 != (longlong *)0x0) {
    do {
      local_res10 = 0;
      local_40 = (longlong *)*param_2;
      FwpsNetBufferListRetrieveContext0(param_2,2,0,0,&local_res10);
      if (lVar6 == 0) {
        lVar6 = *(longlong *)(local_res10 + 0x88);
      }
      if (lVar9 == 0) {
        lVar9 = *(longlong *)(local_res10 + 0x80);
      }
      if ((*(longlong *)(local_res10 + 0x38) != 0) && (*(char *)(local_res10 + 0x40) != '\0')) {
        uVar2 = *(undefined8 *)(local_res10 + 0x78);
        local_48 = 0;
        (*DAT_14002c5b0)(uVar2,param_2,&local_48);
        vSwitchReportPacketDrop
                  ((longlong)param_2,2,-0x3fffffde,uVar2,0,'\x01',in_stack_ffffffffffffffa8);
        (*DAT_14002c5b8)(uVar2,param_2,0);
        ppplVar4 = local_res20;
      }
      ppplVar3 = (longlong ***)
                 vSwitchpPrepareCloneNblToReenterVmSwitch(local_res10,param_2,(byte)param_3);
      if (ppplVar3 != (longlong ***)0x0) {
        if ((*(int *)(local_res10 + 0xc) == 1) || (*(char *)(local_res10 + 0x49) != '\0')) {
          if (ppplVar8 == (longlong ***)0x0) {
            ppplVar8 = ppplVar3;
          }
          else {
            *ppplVar7 = (longlong **)ppplVar3;
          }
          ppplVar7 = ppplVar3;
        }
        else {
          iVar1 = iVar1 + 1;
          *(undefined1 *)(local_res10 + 0x4b) = 1;
          if (ppplVar5 == (longlong ***)0x0) {
            ppplVar5 = ppplVar3;
          }
          else {
            *ppplVar4 = (longlong **)ppplVar3;
          }
          ppplVar4 = ppplVar3;
          local_res20 = ppplVar3;
        }
      }
      param_2 = local_40;
    } while (local_40 != (longlong *)0x0);
    if (ppplVar8 != (longlong ***)0x0) {
      L2NdisFSendNetBufferLists(lVar6,lVar9,ppplVar8,0,param_3 & 1);
    }
    if (ppplVar5 != (longlong ***)0x0) {
      L2NdisFIndicateReceiveNetBufferLists(lVar6,lVar9,ppplVar5,0,iVar1,param_3 & 1);
    }
  }
  return;
}



===== vSwitchInspectL3NetBufferListPacketDrop @ 14001bb64 =====

void vSwitchInspectL3NetBufferListPacketDrop
               (longlong param_1,undefined8 *param_2,longlong param_3,int param_4,longlong param_5,
               int param_6)

{
  ulonglong uVar1;
  longlong in_stack_ffffffffffffffe8;
  
  uVar1 = 0;
  *param_2 = 0;
  if (param_5 != 0) {
    uVar1 = (ulonglong)(byte)*(undefined2 *)(param_3 + 4) * 0x8b8 + *(longlong *)(param_5 + 0x448);
    uVar1 = -(ulonglong)(*(char *)(uVar1 + 0x8b1) != '\0') & uVar1;
  }
  vSwitchReportPacketDrop
            ((longlong)param_2,(param_4 != 1) + 1,param_6,*(undefined8 *)(param_1 + 0xa0),uVar1,'\0'
             ,in_stack_ffffffffffffffe8);
  return;
}



===== vSwitchInspectL3NetBufferLists @ 14001bbd8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void vSwitchInspectL3NetBufferLists
               (longlong ***param_1,int param_2,char param_3,char param_4,longlong ***param_5,
               int *param_6,longlong ***param_7,uint param_8)

{
  longlong ***ppplVar1;
  uint uVar2;
  ushort uVar3;
  longlong ***ppplVar4;
  longlong lVar5;
  ulonglong uVar6;
  longlong ***ppplVar7;
  longlong ***ppplVar8;
  longlong ***ppplVar9;
  int iVar10;
  undefined4 uVar13;
  longlong ****pppplVar11;
  longlong lVar12;
  ushort local_98 [2];
  ushort local_94 [2];
  uint local_90;
  int local_8c;
  longlong ***local_88;
  longlong ***local_80;
  longlong **local_78;
  longlong **local_70;
  longlong local_68;
  undefined4 *local_60;
  undefined4 *local_58;
  longlong ***local_50;
  longlong ***local_48;
  longlong ***local_40;
  
  local_78 = (longlong **)0x0;
  local_70 = (longlong **)0x0;
  iVar10 = 0;
  local_8c = 0;
  local_50 = &local_78;
  local_48 = &local_70;
  if ((longlong ***)*param_5 != (longlong ***)0x0) {
    ppplVar8 = param_5;
    ppplVar1 = (longlong ***)*param_5;
    do {
      local_80 = ppplVar1;
      ppplVar9 = local_80;
      local_68 = 0;
      local_40 = local_80 + 0x25;
      ppplVar1 = (longlong ***)*local_80;
      local_58 = (undefined4 *)0x0;
      local_60 = (undefined4 *)0x0;
      local_98[0] = 0;
      param_5 = (longlong ***)((ulonglong)param_5 & 0xffffffffffffff00);
      local_94[0] = 0;
      local_90 = 0;
      if (param_2 == 2) {
        (*DAT_14002c5b0)(param_1[0x14],local_80,&local_68);
      }
      pppplVar11 = &param_5;
      L2802_3ParseMacHeader
                ((longlong)ppplVar9,(longlong *)&local_58,(longlong *)&local_60,local_98,local_94,
                 (undefined4 *)0x0,(undefined1 *)pppplVar11,&local_90);
      uVar13 = (undefined4)((ulonglong)pppplVar11 >> 0x20);
      ppplVar7 = param_1;
      lVar5 = L2GetvSwitchPortUnsafe
                        ((longlong)param_1,(uint)*(ushort *)((longlong)ppplVar9 + 0x12a));
      uVar3 = local_98[0];
      if (((lVar5 == 0) || (*(char *)(lVar5 + 0x468) == '\0')) && ((char)param_5 == '\0')) {
        ppplVar7 = (longlong ***)0x800;
        if ((local_98[0] != 0x800) && (local_98[0] != 0x86dd)) goto LAB_14001be68;
        if (((param_2 == 2) && (local_68 == 0)) ||
           (((local_98[0] != 0x800 || (param_3 == '\0')) &&
            ((local_98[0] != 0x86dd || (param_4 == '\0')))))) goto LAB_14001be68;
        lVar12 = CONCAT44(uVar13,local_90);
        param_5 = (longlong ***)0x0;
        local_88 = (longlong ***)0x0;
        uVar6 = vSwitchpPrepareNetBufferListForL3Inspection
                          ((longlong)param_1,param_2,local_58,local_60,local_98[0],local_94[0],
                           local_90,(longlong *)&local_80,local_68,(longlong)local_40,lVar5,
                           (longlong *)&param_5,(longlong *)&local_88,&local_8c);
        ppplVar4 = local_48;
        ppplVar7 = local_50;
        ppplVar9 = local_80;
        if ((int)uVar6 < 0) {
          *local_80 = (longlong **)0x0;
          if (((lVar5 == 0) ||
              (lVar5 = (ulonglong)(*(ushort *)((longlong)local_40 + 4) & 0xff) * 0x8b8 +
                       *(longlong *)(lVar5 + 0x448), *(char *)(lVar5 + 0x8b1) == '\0')) ||
             (lVar5 == 0)) {
            lVar5 = 0;
          }
          vSwitchReportPacketDrop
                    ((longlong)local_80,(param_2 != 1) + 1,-0x3fffffde,param_1[0x14],lVar5,'\0',
                     lVar12);
          ppplVar7 = param_7;
          param_7 = ppplVar9;
          *ppplVar7 = (longlong **)ppplVar9;
        }
        else {
          if (uVar3 == 0x800) {
            *local_50 = (longlong **)param_5;
            local_50 = local_88;
            local_80 = ppplVar7;
          }
          else {
            *local_48 = (longlong **)param_5;
            local_48 = local_88;
            local_80 = ppplVar4;
          }
          iVar10 = iVar10 + local_8c;
        }
        *ppplVar8 = (longlong **)ppplVar1;
        ppplVar9 = ppplVar8;
        if (param_6 != (int *)0x0) {
          *param_6 = *param_6 + -1;
        }
      }
      else {
LAB_14001be68:
        local_80 = ppplVar7;
      }
      uVar2 = param_8;
      ppplVar8 = ppplVar9;
    } while (ppplVar1 != (longlong ***)0x0);
    ppplVar8 = local_80;
    local_80 = ppplVar1;
    if (iVar10 != 0) {
      ppplVar8 = param_1;
      vSwitchpRefL3Inspections((longlong)param_1,iVar10,&local_78,&local_70);
    }
    if (local_78 != (longlong **)0x0) {
      vSwitchFlIndicateReceiveNetBufferLists
                (ppplVar8,local_78,uVar2 & 1,(longlong)param_1[0xe],0x800);
    }
    if (local_70 != (longlong **)0x0) {
      vSwitchFlIndicateReceiveNetBufferLists
                (ppplVar8,local_70,uVar2 & 1,(longlong)param_1[0xe],-0x7923);
    }
  }
  return;
}



===== vSwitchInspectL3NetBufferLists_25D @ 14001bef8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void vSwitchInspectL3NetBufferLists_25D
               (longlong ***param_1,uint param_2,char param_3,char param_4,longlong ***param_5,
               int *param_6,longlong ***param_7,uint param_8)

{
  longlong ***ppplVar1;
  longlong ***ppplVar2;
  ushort uVar3;
  longlong ***ppplVar4;
  longlong ***ppplVar5;
  longlong ***ppplVar6;
  longlong lVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  longlong ***ppplVar10;
  undefined4 *puVar11;
  int iVar12;
  char local_a8 [4];
  ushort local_a4 [2];
  ushort local_a0 [2];
  uint local_9c;
  int local_98 [2];
  longlong **local_90;
  longlong **local_88;
  longlong ***local_80;
  longlong ***local_78;
  longlong ***local_70;
  longlong **local_68;
  longlong local_60;
  undefined4 *local_58;
  undefined4 *local_50;
  longlong ***local_48;
  longlong ***local_40;
  
  local_68 = (longlong **)0x0;
  local_98[0] = 0;
  local_90 = (longlong **)0x0;
  local_70 = (longlong ***)*param_5;
  iVar12 = 0;
  local_48 = &local_68;
  local_40 = &local_90;
  ppplVar10 = param_1;
  if (local_70 != (longlong ***)0x0) {
    do {
      ppplVar5 = local_70;
      ppplVar2 = param_7;
      local_60 = 0;
      local_78 = local_70 + 0x25;
      ppplVar1 = (longlong ***)*local_70;
      local_50 = (undefined4 *)0x0;
      local_58 = (undefined4 *)0x0;
      local_a4[0] = 0;
      local_a8[0] = '\0';
      local_a0[0] = 0;
      local_9c = 0;
      if (param_2 == 2) {
        (*DAT_14002c5b0)(param_1[0x14],local_70,&local_60);
      }
      puVar11 = (undefined4 *)0x0;
      lVar7 = L2GetvSwitchPortUnsafe((longlong)param_1,(uint)*(ushort *)((longlong)local_78 + 2));
      ppplVar10 = ppplVar5;
      uVar8 = L2802_3ParseMacHeader_25D
                        ((longlong)ppplVar5,(longlong *)&local_50,(longlong *)&local_58,local_a4,
                         local_a0,puVar11,local_a8,&local_9c);
      ppplVar4 = local_78;
      uVar3 = local_a4[0];
      if ((int)uVar8 < 0) {
        ppplVar10 = param_1;
        vSwitchInspectL3NetBufferListPacketDrop
                  ((longlong)param_1,ppplVar5,(longlong)local_78,param_2,lVar7,(int)uVar8);
        *param_7 = (longlong **)ppplVar5;
        *param_5 = (longlong **)ppplVar1;
        param_7 = ppplVar5;
        if (param_6 != (int *)0x0) {
LAB_14001c19f:
          *param_6 = *param_6 + -1;
        }
      }
      else if ((((((lVar7 == 0) || (*(char *)(lVar7 + 0x468) == '\0')) && (local_a8[0] == '\0')) &&
                ((local_a4[0] == 0x800 || (local_a4[0] == 0x86dd)))) &&
               ((ppplVar10 = (longlong ***)(ulonglong)param_2, param_2 != 2 || (local_60 != 0)))) &&
              (((local_a4[0] == 0x800 && (param_3 != '\0')) ||
               ((local_a4[0] == 0x86dd && (param_4 != '\0')))))) {
        local_88 = (longlong **)0x0;
        local_80 = (longlong ***)0x0;
        uVar9 = vSwitchpPrepareNetBufferListForL3Inspection
                          ((longlong)param_1,param_2,local_50,local_58,local_a4[0],local_a0[0],
                           local_9c,(longlong *)&local_70,local_60,(longlong)local_78,lVar7,
                           (longlong *)&local_88,(longlong *)&local_80,local_98);
        ppplVar10 = local_40;
        ppplVar6 = local_48;
        ppplVar5 = local_70;
        if ((int)uVar9 < 0) {
          ppplVar10 = param_1;
          vSwitchInspectL3NetBufferListPacketDrop
                    ((longlong)param_1,local_70,(longlong)ppplVar4,param_2,lVar7,-0x3fffffde);
          param_7 = ppplVar5;
          *ppplVar2 = (longlong **)ppplVar5;
        }
        else {
          if (uVar3 == 0x800) {
            *local_48 = local_88;
            local_48 = local_80;
            ppplVar10 = ppplVar6;
          }
          else {
            *local_40 = local_88;
            local_40 = local_80;
          }
          iVar12 = iVar12 + local_98[0];
        }
        *param_5 = (longlong **)ppplVar1;
        if (param_6 != (int *)0x0) goto LAB_14001c19f;
      }
      else {
        param_5 = ppplVar5;
      }
      local_70 = ppplVar1;
    } while (ppplVar1 != (longlong ***)0x0);
    if (iVar12 != 0) {
      ppplVar10 = param_1;
      vSwitchpRefL3Inspections((longlong)param_1,iVar12,&local_68,&local_90);
    }
    if (local_68 != (longlong **)0x0) {
      vSwitchFlIndicateReceiveNetBufferLists
                (ppplVar10,local_68,param_8 & 1,(longlong)param_1[0xe],0x800);
    }
  }
  if (local_90 != (longlong **)0x0) {
    vSwitchFlIndicateReceiveNetBufferLists
              (ppplVar10,local_90,param_8 & 1,(longlong)param_1[0xe],-0x7923);
  }
  return;
}



===== vSwitchNetBufferListEventNotifyFn @ 14001c240 =====

int vSwitchNetBufferListEventNotifyFn
              (int param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
              undefined8 param_5,undefined8 param_6)

{
  int iVar1;
  
  if (((param_1 != 1) && (param_1 != 2)) && (param_1 != 3)) {
    if (param_1 == 5) {
      FwppDereferencevSwitchNblContext(param_5);
      return 0;
    }
    if (param_1 != 0xc) {
      return 0;
    }
  }
  iVar1 = FwppNetBufferListAssociateContext
                    (1,param_3,param_4,param_5,param_6,0,0,0,vSwitchNetBufferListEventNotifyFn,0);
  if (-1 < iVar1) {
    FwppReferencevSwitchNblContext(param_5);
  }
  return iVar1;
}



===== vSwitchpAllocateNblContext @ 14001c2f4 =====

undefined2 *
vSwitchpAllocateNblContext
          (longlong param_1,int param_2,undefined4 *param_3,undefined4 *param_4,undefined2 param_5,
          ushort param_6,uint param_7,undefined8 param_8,longlong param_9,longlong param_10)

{
  uint uVar1;
  undefined2 *puVar2;
  ulonglong uVar3;
  
  puVar2 = (undefined2 *)ExAllocatePool2(0x40,0x98,0x6f6e7657);
  if (puVar2 != (undefined2 *)0x0) {
    *(uint *)(puVar2 + 6) = (param_2 != 1) + 1;
    *(undefined4 *)(puVar2 + 0xe) = *param_4;
    puVar2[0x10] = *(undefined2 *)(param_4 + 1);
    *(undefined4 *)(puVar2 + 0x11) = *param_3;
    puVar2[0x13] = *(undefined2 *)(param_3 + 1);
    *puVar2 = param_5;
    L2DeterminevSwitchVLanTenantId
              (param_6,param_7,param_10,(uint *)(puVar2 + 2),(undefined1 *)(puVar2 + 4));
    *(undefined8 *)(puVar2 + 8) = *(undefined8 *)(param_1 + 0x70);
    if (param_10 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = (ulonglong)(byte)*(undefined2 *)(param_9 + 4) * 0x8b8 +
              *(longlong *)(param_10 + 0x448);
      uVar3 = -(ulonglong)(*(char *)(uVar3 + 0x8b1) != '\0') & uVar3;
    }
    *(ulonglong *)(puVar2 + 0x18) = uVar3;
    *(undefined1 *)(puVar2 + 0x39) = 0;
    *(undefined8 *)(puVar2 + 0x3c) = *(undefined8 *)(param_1 + 0xa0);
    *(undefined8 *)(puVar2 + 0x40) = *(undefined8 *)(param_1 + 0x48);
    *(undefined4 *)(puVar2 + 0xc) = *(undefined4 *)(param_1 + 0x90);
    if ((*(uint *)(param_9 + 4) >> 10 & 1) == 0) {
      uVar1 = *(uint *)(param_9 + 4) >> 0xb & 0xfff;
    }
    else {
      uVar1 = 0xffffffff;
    }
    *(uint *)(puVar2 + 0x14) = uVar1;
    *(undefined8 *)(puVar2 + 0x1c) = param_8;
    *(undefined1 *)(puVar2 + 0x20) = 0;
    *(longlong *)(puVar2 + 0x44) = param_1;
    *(undefined8 *)(puVar2 + 0x30) = 0;
    *(undefined4 *)(puVar2 + 0x34) = 0;
    *(uint *)(puVar2 + 0x36) = (uint)*(ushort *)(param_9 + 2);
    puVar2[0x38] = 0;
    *(undefined8 *)(puVar2 + 0x22) = 0;
    *(undefined4 *)(puVar2 + 0x48) = 1;
  }
  return puVar2;
}



===== vSwitchpCleanupCloneNetBufferLists @ 14001c480 =====

void vSwitchpCleanupCloneNetBufferLists(longlong *param_1)

{
  char cVar1;
  longlong *plVar2;
  int iVar3;
  longlong local_res8;
  
  if (param_1 != (longlong *)0x0) {
    do {
      local_res8 = 0;
      iVar3 = FwpsNetBufferListRetrieveContext0(param_1,2,1,0,&local_res8);
      plVar2 = (longlong *)*param_1;
      if (iVar3 != -0x3ffffddb) {
        cVar1 = *(char *)(local_res8 + 0x72);
        FwppDereferencevSwitchNblContext();
        LOCK();
        *(int *)(param_1[3] + 0x84) = *(int *)(param_1[3] + 0x84) + -0x10001;
        UNLOCK();
        if (cVar1 == '\0') {
          NdisFreeCloneNetBufferList(param_1,0);
        }
        else {
          NdisFreeNetBufferList();
        }
      }
      param_1 = plVar2;
    } while (plVar2 != (longlong *)0x0);
  }
  return;
}



===== vSwitchpCompleteL3Inspection @ 14001c538 =====

void vSwitchpCompleteL3Inspection
               (longlong param_1,longlong param_2,longlong *param_3,undefined4 param_4)

{
  *(undefined8 *)*param_3 = 0;
  if (*(int *)(param_1 + 0x148) != 0) {
    L2CheckAndCompleteInjectedNetBufferLists
              (2,param_3,'\0',(int *)0x0,*(longlong *)(param_1 + 0x48));
  }
  if (*param_3 != 0) {
    if (*(int *)(param_2 + 0xc) == 1) {
      NdisFSendNetBufferListsComplete();
    }
    else {
      NdisFReturnNetBufferLists(*(undefined8 *)(param_2 + 0x80),*param_3,param_4);
    }
  }
  *param_3 = 0;
  return;
}



===== vSwitchpInitializeCloneNetBufferList @ 14001c5cc =====

undefined8
vSwitchpInitializeCloneNetBufferList(longlong param_1,longlong param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  lVar1 = FwppNetBufferListAssociateContext
                    (1,param_2,0xffff,param_3,2,0,0,0,vSwitchNetBufferListEventNotifyFn,0);
  if (lVar1 == 0) {
    NetioCopyNetBufferListInformation(param_2,param_1);
    *(undefined8 *)(param_2 + 0x100) = *(undefined8 *)(param_1 + 0x100);
    *(longlong *)(param_2 + 0x18) = param_1;
    LOCK();
    *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + 0x10001;
    UNLOCK();
  }
  else {
    uVar2 = 0xc000009a;
  }
  return uVar2;
}



===== vSwitchpPrepareCloneNblToReenterVmSwitch @ 14001c674 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

longlong vSwitchpPrepareCloneNblToReenterVmSwitch(longlong param_1,longlong *param_2,byte param_3)

{
  int iVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 uVar4;
  
  lVar2 = NdisAllocateCloneNetBufferList(param_2,DAT_14002cf38,0,0);
  if (lVar2 != 0) {
    NetioCopyNetBufferListInformation(lVar2,param_2);
    *(undefined8 *)(lVar2 + 0x78) = *(undefined8 *)(param_1 + 0x80);
    iVar1 = (*DAT_14002c588)(*(undefined8 *)(param_1 + 0x78),lVar2);
    if (iVar1 == 0) {
      if (param_2[0x24] == 0) {
        plVar3 = (longlong *)vSwitchFindOriginalvmSwitchNetBufferList((longlong)param_2);
      }
      else {
        plVar3 = param_2;
      }
      if (plVar3 == (longlong *)0x0) {
        *(uint *)(lVar2 + 300) = *(uint *)(lVar2 + 300) | 0x400;
        iVar1 = L2vSwitchValidatePortNicAndSetSource
                          (*(uint *)(*(longlong *)(param_1 + 0x30) + 0x410),
                           (ulonglong)*(ushort *)(*(longlong *)(param_1 + 0x30) + 0x414),lVar2,
                           *(longlong *)(param_1 + 0x88));
      }
      else {
        if ((*(int *)(param_1 + 0xc) == 2) && (*(char *)(param_1 + 0x49) == '\0')) {
          uVar4 = 1;
        }
        else {
          uVar4 = 0;
        }
        iVar1 = (*DAT_14002c5c0)(*(undefined8 *)(param_1 + 0x78),lVar2,plVar3,uVar4);
        *(longlong *)(lVar2 + 0x100) = plVar3[0x20];
      }
      if (iVar1 == 0) {
        *(longlong **)(lVar2 + 0x18) = param_2;
        LOCK();
        *(int *)((longlong)param_2 + 0x84) = *(int *)((longlong)param_2 + 0x84) + 1;
        UNLOCK();
        return lVar2;
      }
    }
    FwpsNetBufferListRemoveContext0(lVar2,2);
    FwppDereferencevSwitchNblContext(param_1);
    NdisFreeCloneNetBufferList(lVar2,0);
    *param_2 = 0;
    vSwitchFlSendNetBufferListsComplete(lVar2,param_2,param_3 & 1);
  }
  return 0;
}



===== vSwitchpPrepareNetBufferListForL3Inspection @ 14001c7fc =====

ulonglong vSwitchpPrepareNetBufferListForL3Inspection
                    (longlong param_1,int param_2,undefined4 *param_3,undefined4 *param_4,
                    undefined2 param_5,ushort param_6,uint param_7,longlong *param_8,
                    undefined8 param_9,longlong param_10,longlong param_11,longlong *param_12,
                    longlong *param_13,int *param_14)

{
  longlong lVar1;
  longlong *plVar2;
  int *piVar3;
  longlong **pplVar4;
  undefined2 *puVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  longlong **pplVar8;
  longlong *plVar9;
  
  piVar3 = param_14;
  plVar2 = param_8;
  pplVar4 = (longlong **)0x0;
  puVar5 = (undefined2 *)0x0;
  param_8 = (longlong *)0x0;
  uVar7 = 0xc000000d;
  lVar1 = *plVar2;
  *param_14 = 0;
  plVar9 = *(longlong **)(lVar1 + 8);
  if (*plVar9 == 0) {
    pplVar4 = (longlong **)NdisAllocateCloneNetBufferList(lVar1,DAT_14002cf38,0,0);
    if (pplVar4 == (longlong **)0x0) {
      return 0xc000009a;
    }
    puVar5 = vSwitchpAllocateNblContext
                       (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_9,param_10,
                        param_11);
    if (puVar5 == (undefined2 *)0x0) {
      uVar7 = 0xc000009a;
    }
    else {
      *(undefined1 *)(puVar5 + 0x39) = 0;
      uVar6 = vSwitchpInitializeCloneNetBufferList(lVar1,(longlong)pplVar4,puVar5);
      uVar7 = uVar6 & 0xffffffff;
      if (-1 < (int)uVar6) {
        FwppReferencevSwitchNblContext(puVar5);
        *piVar3 = *piVar3 + 1;
        pplVar8 = pplVar4;
        goto LAB_14001ca6e;
      }
    }
    NdisFreeCloneNetBufferList(pplVar4,0);
    pplVar8 = (longlong **)0x0;
  }
  else {
    pplVar8 = &param_8;
    for (; plVar9 != (longlong *)0x0; plVar9 = (longlong *)*plVar9) {
      pplVar4 = (longlong **)
                NdisAllocateNetBufferAndNetBufferList
                          (DAT_14002cf38,0x200,0x200,plVar9[1],(int)plVar9[5],(int)plVar9[3]);
      if (pplVar4 == (longlong **)0x0) {
        uVar7 = 0xc000009a;
LAB_14001ca55:
        pplVar8 = (longlong **)param_8;
        goto LAB_14001ca89;
      }
      puVar5 = vSwitchpAllocateNblContext
                         (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_9,param_10,
                          param_11);
      if (puVar5 == (undefined2 *)0x0) {
        uVar7 = 0xc000009a;
LAB_14001ca46:
        NdisFreeNetBufferList(pplVar4);
        goto LAB_14001ca55;
      }
      *(undefined1 *)(puVar5 + 0x39) = 1;
      uVar6 = vSwitchpInitializeCloneNetBufferList(lVar1,(longlong)pplVar4,puVar5);
      uVar7 = uVar6 & 0xffffffff;
      if ((int)uVar6 < 0) goto LAB_14001ca46;
      FwppReferencevSwitchNblContext(puVar5);
      *piVar3 = *piVar3 + 1;
      *pplVar8 = (longlong *)pplVar4;
      pplVar8 = pplVar4;
    }
    pplVar8 = (longlong **)param_8;
LAB_14001ca6e:
    *plVar2 = 0;
    *param_12 = (longlong)pplVar8;
    *param_13 = (longlong)pplVar4;
  }
LAB_14001ca89:
  if (puVar5 != (undefined2 *)0x0) {
    FwppDereferencevSwitchNblContext(puVar5);
  }
  if (((int)uVar7 < 0) && (pplVar8 != (longlong **)0x0)) {
    vSwitchpCleanupCloneNetBufferLists((longlong *)pplVar8);
  }
  return uVar7;
}



===== vSwitchpRefL3Inspections @ 14001cac8 =====

void vSwitchpRefL3Inspections(longlong param_1,int param_2,undefined8 *param_3,undefined8 *param_4)

{
  undefined1 uVar1;
  bool bVar2;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x30);
  bVar2 = *(int *)(param_1 + 0x3c) == 3;
  if (bVar2) {
    *(int *)(param_1 + 0x148) = *(int *)(param_1 + 0x148) + param_2;
  }
  KeReleaseSpinLock(param_1 + 0x30,uVar1);
  if (!bVar2) {
    vSwitchpCleanupCloneNetBufferLists((longlong *)*param_3);
    *param_3 = 0;
    vSwitchpCleanupCloneNetBufferLists((longlong *)*param_4);
    *param_4 = 0;
  }
  return;
}



===== Ipv4AddressType @ 14001cb68 =====

int Ipv4AddressType(uint *param_1)

{
  uint uVar1;
  
  uVar1 = *param_1;
  if ((uVar1 & 0xf0) == 0xe0) {
    return 3;
  }
  if (uVar1 == 0xffffffff) {
    return 4;
  }
  if (uVar1 == 0) {
    return 0;
  }
  return (-(uint)((char)uVar1 != '\0' && (uVar1 & 0xf0) != 0xf0) & 0xfffffffc) + 5;
}



===== Ipv6AddressType @ 14001cbb8 =====

int Ipv6AddressType(short *param_1)

{
  short sVar1;
  int iVar2;
  longlong lVar3;
  int iVar4;
  bool bVar5;
  
  if ((char)*param_1 == -1) {
    return 3;
  }
  sVar1 = *param_1;
  if ((((sVar1 == 0) && (param_1[1] == 0)) && (param_1[2] == 0)) &&
     (((param_1[3] == 0 && (param_1[4] == 0)) &&
      ((param_1[5] == 0 && ((param_1[6] == 0 && (param_1[7] == 0)))))))) {
    return 0;
  }
  iVar4 = 1;
  if ((((param_1[4] & 0xfffdU) == 0) && (param_1[5] == -0x1a2)) ||
     (((sVar1 == 0 && (((param_1[1] == 0 && (param_1[2] == 0)) && (param_1[3] == 0)))) &&
      (((param_1[4] == 0 && (param_1[5] == 0)) &&
       ((param_1[6] != 0 || (((char)param_1[7] != '\0' || (1 < *(byte *)((longlong)param_1 + 0xf))))
        ))))))) {
LAB_14001cca6:
    lVar3 = 0xc;
  }
  else {
    if ((sVar1 == 0) && (((param_1[1] == 0 && (param_1[2] == 0)) && (param_1[3] == 0)))) {
      if (param_1[4] == 0) {
        bVar5 = param_1[5] == -1;
      }
      else {
        if (param_1[4] != -1) goto LAB_14001ccad;
        bVar5 = param_1[5] == 0;
      }
      if (bVar5) goto LAB_14001cca6;
    }
LAB_14001ccad:
    if (sVar1 != 0x220) {
      return 1;
    }
    lVar3 = 2;
  }
  iVar2 = Ipv4AddressType((uint *)((longlong)param_1 + lVar3));
  if (iVar2 != iVar4) {
    iVar4 = 5;
  }
  return iVar4;
}



===== Ipv6UnicastAddressScope @ 14001cce0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 Ipv6UnicastAddressScope(short *param_1)

{
  undefined8 uVar1;
  short *psVar2;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)&local_28;
  local_28 = 0;
  uStack_20 = 0;
  if (((ulonglong)param_1 & 1) != 0) {
    local_28 = *(undefined8 *)param_1;
    uStack_20 = *(undefined8 *)(param_1 + 4);
  }
  psVar2 = (short *)&local_28;
  if (((ulonglong)param_1 & 1) == 0) {
    psVar2 = param_1;
  }
  if ((((char)*psVar2 == -2) && ((short)(*psVar2 & -0x4000) == -0x8000)) ||
     ((((*psVar2 == 0 &&
        ((((psVar2[1] == 0 && (psVar2[2] == 0)) && (psVar2[3] == 0)) &&
         ((psVar2[4] == 0 && (psVar2[5] == 0)))))) && (psVar2[6] == 0)) && (psVar2[7] == 0x100)))) {
    uVar1 = 2;
  }
  else if (((char)*psVar2 != -2) || (uVar1 = 5, (short)(*psVar2 & -0x4000) != -0x4000)) {
    uVar1 = 0xe;
  }
  return uVar1;
}



===== NdisSetCurrentThreadCompartmentId @ 14001cda4 =====

void NdisSetCurrentThreadCompartmentId(undefined4 param_1)

{
  NdisSetThreadObjectCompartmentId(SystemReserved1[0xf],param_1);
  return;
}



===== NetioRestoreNetBufferList @ 14001cdcc =====

void NetioRestoreNetBufferList(longlong param_1)

{
  longlong *plVar1;
  int iVar2;
  uint uVar3;
  longlong *plVar4;
  longlong lVar5;
  undefined8 *puVar6;
  int iVar7;
  
  for (puVar6 = *(undefined8 **)(param_1 + 8); puVar6 != (undefined8 *)0x0;
      puVar6 = (undefined8 *)*puVar6) {
    iVar7 = *(int *)(puVar6 + 0xb);
    plVar1 = puVar6 + 4;
    *(undefined4 *)(puVar6 + 0xb) = 0;
    for (iVar7 = ((iVar7 - *(int *)((longlong)puVar6 + 0x54)) - *(int *)(puVar6 + 10)) +
                 *(int *)(puVar6 + 5) + *(int *)(puVar6 + 3); iVar7 != 0; iVar7 = iVar7 - iVar2) {
      plVar4 = (longlong *)*plVar1;
      *plVar1 = *plVar4;
      iVar2 = *(int *)(plVar4 + 5);
      NetioFreeMdl();
    }
    lVar5 = *plVar1;
    *(undefined4 *)(puVar6 + 3) = *(undefined4 *)((longlong)puVar6 + 0x54);
    uVar3 = *(uint *)(puVar6 + 10);
    *(uint *)(puVar6 + 5) = uVar3;
    puVar6[1] = lVar5;
    *(uint *)(puVar6 + 2) = uVar3;
    if ((lVar5 != 0) && (*(uint *)(lVar5 + 0x28) < uVar3)) {
      NdisAdjustNetBufferCurrentMdl(puVar6);
    }
  }
  return;
}



===== vSwitchFlAddGroup @ 14001ce70 =====

undefined8 vSwitchFlAddGroup(void)

{
  return 0;
}



===== vSwitchFlAttachClient @ 14001ce80 =====

undefined8
vSwitchFlAttachClient
          (undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
          longlong param_5,undefined8 *param_6,longlong *param_7)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  bool bVar3;
  
  if (*(short *)(param_5 + 4) == *(short *)(param_2 + 0x4c)) {
    puVar2 = (undefined8 *)ExAllocatePool2(0x40,0x28,0x6c665356);
    if (puVar2 == (undefined8 *)0x0) {
      uVar1 = 0xc000009a;
    }
    else {
      LOCK();
      bVar3 = *(longlong *)(param_2 + 200) == 0;
      if (bVar3) {
        *(longlong *)(param_2 + 200) = (longlong)puVar2;
      }
      UNLOCK();
      if (bVar3) {
        puVar2[3] = 0;
        puVar2[1] = param_5;
        *puVar2 = param_4;
        puVar2[2] = param_1;
        puVar2[4] = param_2 + -8;
        *(undefined4 *)(*(longlong *)(param_2 + 200) + 0x18) = 2;
        *param_6 = *(undefined8 *)(param_2 + 200);
        *param_7 = param_2 + 0x58;
        uVar1 = 0;
      }
      else {
        ExFreePoolWithTag(puVar2,0);
        uVar1 = 0xc0000001;
      }
    }
  }
  else {
    uVar1 = 0xc00002b9;
  }
  return uVar1;
}



===== vSwitchFlCleanupClientContext @ 14001cf60 =====

void vSwitchFlCleanupClientContext(longlong param_1)

{
  *(undefined8 *)(*(longlong *)(param_1 + 0x20) + 0xd0) = 0;
  ExFreePoolWithTag(param_1,0);
  return;
}



===== _guard_check_icall @ 14001cf90 =====

void _guard_check_icall(void)

{
  return;
}



===== vSwitchFlDetachClient @ 14001cfa0 =====

undefined8 vSwitchFlDetachClient(longlong param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  
  lVar3 = *(longlong *)(param_1 + 0x20);
  LOCK();
  piVar1 = (int *)(*(longlong *)(lVar3 + 0xd0) + 0x18);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 2) {
    NmrProviderDetachClientComplete(*(undefined8 *)(*(longlong *)(lVar3 + 0xd0) + 0x10));
  }
  return 0x103;
}



===== vSwitchFlSetInterface @ 14001cff0 =====

undefined8 vSwitchFlSetInterface(void)

{
  return 0xc00000bb;
}



===== vSwitchFlIndicateReceiveNetBufferLists @ 14001d000 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */

void vSwitchFlIndicateReceiveNetBufferLists
               (undefined8 param_1,longlong **param_2,uint param_3,longlong param_4,short param_5)

{
  longlong **pplVar1;
  undefined1 uVar2;
  short *psVar3;
  undefined8 *puVar4;
  longlong **pplVar5;
  longlong **_Dst;
  uint uVar6;
  longlong *plVar7;
  ulonglong uVar8;
  uint *puVar9;
  undefined1 *puVar10;
  int iVar11;
  uint uVar12;
  undefined1 auStackY_158 [32];
  undefined1 local_128;
  char local_127;
  int local_124;
  longlong local_120;
  uint local_118;
  int local_114;
  uint local_110 [2];
  longlong **local_108;
  longlong **local_100;
  longlong *local_f8;
  longlong *local_f0;
  uint local_e8 [2];
  longlong local_e0;
  undefined8 local_c8;
  longlong local_c0 [17];
  
  local_c0[0xf] = __security_cookie ^ (ulonglong)auStackY_158;
  local_e0 = param_4 + 10;
  local_108 = &local_f8;
  _Dst = (longlong **)&local_c8;
  uVar2 = (undefined1)param_3;
  local_e8[0] = (uint)*(ushort *)(param_4 + 8);
  local_100 = &local_f0;
  local_e8[1] = 0;
  puVar9 = (uint *)0x0;
  local_120 = 0;
  puVar10 = (undefined1 *)0x0;
  local_110[0] = 0;
  local_124 = 0;
  uVar12 = 0;
  local_118 = 0;
  local_128 = 0;
  local_f8 = (longlong *)0x0;
  local_f0 = (longlong *)0x0;
  memset(_Dst,0,0x80);
  if (param_2 != (longlong **)0x0) {
    do {
      local_127 = '\0';
      local_114 = 0;
      psVar3 = (short *)FwppGetvSwitchNblContext(param_2);
      for (uVar6 = 0; uVar6 < 4; uVar6 = uVar6 + 1) {
        plVar7 = (longlong *)((longlong)local_c0 + ((ulonglong)uVar6 * 4 + -2) * 8 + 8);
        if (((char)*plVar7 != '\0') &&
           (*(int *)((longlong)local_c0 + (ulonglong)uVar6 * 0x20 + 0xfffffffffffffffc) ==
            *(int *)(psVar3 + 2))) {
          if (plVar7 == (longlong *)0x0) goto LAB_14001d0f2;
          goto LAB_14001d1c0;
        }
      }
      plVar7 = (longlong *)0x0;
LAB_14001d0f2:
      RtlAcquireReadLock(0x14002c548,&local_128);
      puVar4 = vSwitchFlpFindCompartmentUnderLock(local_e8,*(int *)(psVar3 + 2));
      _Dst = (longlong **)&DAT_14002c548;
      RtlReleaseReadLock(0x14002c548,local_128);
      if (puVar4 == (undefined8 *)0x0) {
        *(undefined4 *)((longlong)param_2 + 0x8c) = 0xc023002d;
        iVar11 = -0x3fdcffd3;
      }
      else {
        if (*psVar3 != 0x800) {
          local_120 = puVar4[0x49];
        }
        else {
          local_120 = puVar4[0x48];
        }
        _Dst = (longlong **)&vSwitchFl6ProviderState;
        puVar10 = &vSwitchFl4ProviderState;
        if (*psVar3 != 0x800) {
          puVar10 = &vSwitchFl6ProviderState;
        }
        if (local_120 == 0) {
          psVar3[0x22] = 0x22;
          psVar3[0x23] = -0x4000;
          *(undefined4 *)((longlong)param_2 + 0x8c) = 0xc023002b;
          iVar11 = -0x3fdcffd5;
        }
        else {
          if (uVar12 < 4) {
            uVar8 = (ulonglong)uVar12;
            plVar7 = (longlong *)((longlong)local_c0 + (uVar8 * 4 + -2) * 8 + 8);
            uVar12 = uVar12 + 1;
            *(char *)plVar7 = '\x01';
            *(undefined4 *)((longlong)local_c0 + uVar8 * 0x20 + 0xfffffffffffffffc) =
                 *(undefined4 *)(psVar3 + 2);
            *(longlong **)((longlong)local_c0 + (uVar8 * 4 + 1) * 8 + 8) =
                 (longlong *)((longlong)local_c0 + uVar8 * 0x20 + 8);
            local_c0[uVar8 * 4] = (longlong)puVar4;
          }
LAB_14001d1c0:
          NetioInitializeNetBufferListContext(param_2,0,vSwitchFlReceiveNetBufferListsComplete,0);
          NetioAdvanceNetBufferList(param_2,0xe);
          *(longlong **)(psVar3 + 0x28) = param_2[0x12];
          puVar9 = local_110;
          *(longlong **)(psVar3 + 0x2c) = param_2[0x14];
          param_2[0x12] = (longlong *)0x0;
          *(undefined4 *)(param_2 + 0x12) = 0x20;
          param_2[0x14] = (longlong *)0x0;
          local_127 = '\x01';
          _Dst = param_2;
          vSwitchFlpGetNblInfo((longlong)param_2,psVar3,puVar9,&local_124,&local_118);
          if ((local_124 == 4) || ((iVar11 = local_114, local_124 == 3 && ((int)local_118 < 3)))) {
            param_2[0x12] = *(longlong **)(psVar3 + 0x28);
            param_2[0x14] = *(longlong **)(psVar3 + 0x2c);
            iVar11 = -0x3fffff45;
          }
        }
      }
      pplVar1 = (longlong **)*param_2;
      *param_2 = (longlong *)0x0;
      if (iVar11 < 0) {
        if (local_127 != '\0') {
          puVar9 = (uint *)0x0;
          NetioRetreatNetBufferList(param_2,0xe);
        }
        _Dst = param_2;
        WfpNblInfoClearFlags(param_2,1);
        if ((iVar11 + 0x3fdcffd5U & 0xfffffffd) == 0) {
          pplVar5 = local_100;
          local_100 = param_2;
        }
        else {
          pplVar5 = local_108;
          local_108 = param_2;
        }
        *pplVar5 = (longlong *)param_2;
      }
      else if (plVar7 == (longlong *)0x0) {
        puVar9 = (uint *)(CONCAT71((int7)((ulonglong)puVar9 >> 8),uVar2) & 0xffffffffffffff01);
        _Dst = *(longlong ***)(local_120 + 0x50);
        (**(code **)(*(longlong *)(*(longlong *)(puVar10 + 0xd0) + 8) + 0x40))(_Dst,param_2);
      }
      else {
        *(longlong ***)plVar7[3] = param_2;
        plVar7[3] = (longlong)param_2;
      }
      param_2 = pplVar1;
    } while (pplVar1 != (longlong **)0x0);
    if (uVar12 != 0) {
      uVar8 = (ulonglong)uVar12;
      plVar7 = local_c0;
      if (param_5 == 0x800) {
        do {
          if (plVar7[1] != 0) {
            puVar9 = (uint *)(CONCAT71((int7)((ulonglong)puVar9 >> 8),uVar2) & 0xffffffffffffff01);
            _Dst = *(longlong ***)(*(longlong *)(*plVar7 + 0x240) + 0x50);
            (**(code **)(*(longlong *)(DAT_14002c2b0 + 8) + 0x40))(_Dst,plVar7[1],puVar9);
          }
          plVar7 = plVar7 + 4;
          uVar8 = uVar8 - 1;
        } while (uVar8 != 0);
      }
      else {
        do {
          if (plVar7[1] != 0) {
            puVar9 = (uint *)(CONCAT71((int7)((ulonglong)puVar9 >> 8),uVar2) & 0xffffffffffffff01);
            _Dst = *(longlong ***)(*(longlong *)(*plVar7 + 0x248) + 0x50);
            (**(code **)(*(longlong *)(DAT_14002c1b0 + 8) + 0x40))(_Dst,plVar7[1],puVar9);
          }
          plVar7 = plVar7 + 4;
          uVar8 = uVar8 - 1;
        } while (uVar8 != 0);
      }
    }
  }
  if (local_f8 != (longlong *)0x0) {
    vSwitchFlSendNetBufferLists(_Dst,local_f8,param_3 & 1);
  }
  if (local_f0 != (longlong *)0x0) {
    vSwitchFlReturnNetBufferLists(_Dst,local_f0,param_3 & 1);
  }
  return;
}



===== vSwitchFlIndicationComplete @ 14001d420 =====

void vSwitchFlIndicationComplete(longlong *param_1)

{
  longlong lVar1;
  
  lVar1 = *param_1;
  *(int *)(lVar1 + 0x70) = (int)param_1[2];
  KeSetEvent(lVar1 + 0x58,0,0);
  return;
}



===== vSwitchFlMapAddress @ 14001d450 =====

undefined8 vSwitchFlMapAddress(longlong param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0x10);
  *puVar1 = 0x4c504657;
  *(undefined2 *)(puVar1 + 1) = 0x4657;
  return 0;
}



===== vSwitchFlReceiveNetBufferListsComplete @ 14001d480 =====

void vSwitchFlReceiveNetBufferListsComplete(longlong *param_1,undefined8 param_2,char param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  
  if (param_1 != (longlong *)0x0) {
    do {
      FwppGetvSwitchNblContext(param_1);
      NetioRestoreNetBufferList((longlong)param_1);
      plVar2 = param_1;
      WfpNblInfoClearFlags(param_1,1);
      plVar1 = (longlong *)*param_1;
      *param_1 = 0;
      vSwitchFlReturnNetBufferLists(plVar2,param_1,(uint)(param_3 != '\0'));
      param_1 = plVar1;
    } while (plVar1 != (longlong *)0x0);
  }
  return;
}



===== vSwitchFlSendNetBufferListsComplete @ 14001d4fc =====

void vSwitchFlSendNetBufferListsComplete(undefined8 param_1,longlong *param_2,undefined1 param_3)

{
  longlong *plVar1;
  undefined8 uVar2;
  
  if (param_2 != (longlong *)0x0) {
    do {
      uVar2 = 0;
      WfpNblInfoSetFlags(param_2,1);
      plVar1 = (longlong *)*param_2;
      NetioDereferenceNetBufferList
                (param_2,CONCAT71((int7)((ulonglong)uVar2 >> 8),param_3) & 0xffffffffffffff01);
      param_2 = plVar1;
    } while (plVar1 != (longlong *)0x0);
  }
  return;
}



===== vSwitchFlSendPackets @ 14001d570 =====

void vSwitchFlSendPackets(undefined8 param_1,char param_2,longlong *param_3)

{
  longlong **pplVar1;
  ushort *puVar2;
  longlong **pplVar3;
  longlong **pplVar4;
  longlong *local_res18;
  
  if (param_3 != (longlong *)0x0) {
    local_res18 = (longlong *)0x0;
    pplVar4 = &local_res18;
    do {
      pplVar1 = (longlong **)param_3[1];
      puVar2 = (ushort *)FwppGetvSwitchNblContext(pplVar1);
      pplVar1[0x12] = *(longlong **)(puVar2 + 0x28);
      pplVar1[0x14] = *(longlong **)(puVar2 + 0x2c);
      NetioRetreatNetBufferList(pplVar1,0xe);
      vSwitchFlpAddEthernetHeader
                ((longlong)pplVar1,*puVar2,(undefined4 *)(puVar2 + 0xe),
                 (undefined4 *)(puVar2 + 0x11));
      pplVar3 = pplVar1;
      WfpNblInfoClearFlags(pplVar1,1);
      *pplVar4 = (longlong *)pplVar1;
      param_3 = (longlong *)*param_3;
      pplVar4 = pplVar1;
    } while (param_3 != (longlong *)0x0);
    if (local_res18 != (longlong *)0x0) {
      vSwitchFlSendNetBufferLists(pplVar3,local_res18,(uint)(param_2 != '\0'));
    }
  }
  return;
}



===== vSwitchFlpAddEthernetHeader @ 14001d654 =====

void vSwitchFlpAddEthernetHeader
               (longlong param_1,ushort param_2,undefined4 *param_3,undefined4 *param_4)

{
  longlong lVar1;
  undefined4 *puVar2;
  longlong *plVar3;
  
  plVar3 = *(longlong **)(param_1 + 8);
  if (plVar3 != (longlong *)0x0) {
    do {
      lVar1 = plVar3[1];
      if ((*(byte *)(lVar1 + 10) & 5) == 0) {
        lVar1 = MmMapLockedPagesSpecifyCache(lVar1,0,1,0,0,0x40000000);
      }
      else {
        lVar1 = *(longlong *)(lVar1 + 0x18);
      }
      puVar2 = (undefined4 *)((ulonglong)*(uint *)(plVar3 + 2) + lVar1);
      *puVar2 = *param_4;
      *(undefined2 *)(puVar2 + 1) = *(undefined2 *)(param_4 + 1);
      *(undefined4 *)((longlong)puVar2 + 6) = *param_3;
      *(undefined2 *)((longlong)puVar2 + 10) = *(undefined2 *)(param_3 + 1);
      *(ushort *)(puVar2 + 3) = param_2 >> 8 | param_2 << 8;
      plVar3 = (longlong *)*plVar3;
    } while (plVar3 != (longlong *)0x0);
  }
  return;
}



===== vSwitchFlpAllocCompartmentId @ 14001d6fc =====

int vSwitchFlpAllocCompartmentId(undefined4 *param_1,undefined4 *param_2,undefined8 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 local_res20 [2];
  
  local_res20[0] = 0;
  puVar6 = (undefined4 *)ExAllocatePool2(0x40,0x668,0x63665356);
  if (puVar6 == (undefined4 *)0x0) {
    iVar5 = -0x3fffffe9;
  }
  else {
    *puVar6 = 0x65402ad;
    uVar1 = *param_1;
    uVar2 = param_1[1];
    uVar3 = param_1[2];
    uVar4 = param_1[3];
    puVar6[0x194] = 3;
    puVar6[0x10e] = uVar1;
    puVar6[0x10f] = uVar2;
    puVar6[0x110] = uVar3;
    puVar6[0x111] = uVar4;
    iVar5 = NsiSetAllParameters(1,1,&NPI_MS_NDIS_MODULEID,7,local_res20,4,puVar6,0x668);
    if (-1 < iVar5) {
      iVar5 = NsiGetParameter(1,&NPI_MS_NDIS_MODULEID,0xb,puVar6 + 0x10e,0x10,2,local_res20,4,0);
      if (-1 < iVar5) {
        *param_2 = local_res20[0];
        iVar5 = NsiGetParameter(1,&NPI_MS_NDIS_MODULEID,7,local_res20,4,0,param_3,0x10,0x10);
      }
    }
    ExFreePoolWithTag(puVar6,0);
  }
  return iVar5;
}



===== vSwitchFlpCleanupInterface @ 14001d884 =====

void vSwitchFlpCleanupInterface(longlong param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  ExFreePoolWithTag(param_1,0);
  LOCK();
  piVar1 = (int *)(*(longlong *)(lVar3 + 0xd0) + 0x18);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -2;
  UNLOCK();
  if (iVar2 == 3) {
    NmrProviderDetachClientComplete(*(undefined8 *)(*(longlong *)(lVar3 + 0xd0) + 0x10));
  }
  return;
}



===== vSwitchFlpCreateAdapter @ 14001d8d8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void vSwitchFlpCreateAdapter(undefined4 *param_1,undefined8 param_2,ulonglong *param_3)

{
  int iVar1;
  undefined1 auStack_148 [32];
  ulonglong *local_128;
  undefined4 local_120;
  undefined4 local_118;
  undefined4 *local_110;
  undefined4 local_108;
  undefined4 local_100;
  uint local_f8 [4];
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined1 local_c0;
  undefined4 local_b8;
  undefined1 local_b4 [16];
  undefined4 local_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 local_90;
  wchar_t local_88 [40];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_148;
  local_f8[0] = 0;
  local_88[0x24] = L'\0';
  local_88[0x25] = L'\0';
  local_88[0x26] = L'\0';
  local_88[0x27] = L'\0';
  iVar1 = NdisIfAllocateNetLuidIndexEx(6,1,local_f8);
  if (-1 < iVar1) {
    *(undefined2 *)((longlong)param_3 + 6) = 6;
    *param_3 = ((ulonglong)local_f8[0] << 0x18 ^ *param_3) & 0xffff000000000000 ^
               (ulonglong)local_f8[0] << 0x18;
    memset(&local_e8,0,0x60);
    local_e4 = 0;
    local_c8 = 0;
    builtin_wcsncpy(local_88,L"WFP vSwitch extension LWF interf",0x20);
    builtin_wcsncpy(local_88 + 0x20,L"ace",4);
    local_e8 = 0x600180;
    local_cc = 2;
    local_c4 = 1;
    local_c0 = 0;
    local_b8 = 0x600048;
    ExUuidCreate(local_b4);
    local_a4 = *param_1;
    uStack_a0 = param_1[1];
    uStack_9c = param_1[2];
    uStack_98 = param_1[3];
    local_90 = 0;
    local_128 = (ulonglong *)param_2;
    iVar1 = NdisIfRegisterInterface(vSwitchFlGlobalState,*param_3,local_f8[0],&local_e8);
    if (-1 < iVar1) {
      local_100 = 0;
      local_108 = 0x10;
      local_118 = 0;
      local_120 = 8;
      local_128 = param_3;
      local_110 = param_1;
      NsiSetParameter(1,0,&NPI_MS_NDIS_MODULEID,0);
    }
  }
  return;
}



===== vSwitchFlpCreateAndBindInterface @ 14001da78 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int vSwitchFlpCreateAndBindInterface
              (longlong param_1,undefined4 param_2,undefined4 param_3,longlong param_4,
              undefined8 *param_5)

{
  longlong *plVar1;
  longlong *plVar2;
  code *pcVar3;
  byte bVar4;
  undefined1 uVar5;
  int iVar6;
  longlong *plVar7;
  ulonglong uVar8;
  longlong lVar9;
  undefined1 *puVar10;
  longlong *plVar11;
  longlong *plVar12;
  undefined1 auStack_108 [8];
  undefined1 auStack_100 [24];
  undefined8 local_e8;
  undefined4 local_d8;
  undefined4 local_d4;
  code *local_d0;
  undefined8 local_c8;
  longlong *local_c0;
  longlong *local_b8;
  longlong *local_b0;
  longlong *local_a8;
  code *local_a0;
  longlong local_98;
  longlong *local_90;
  longlong *local_88;
  longlong *local_80;
  longlong *local_78;
  longlong local_70;
  undefined4 local_68;
  undefined8 local_64;
  undefined8 uStack_5c;
  undefined8 local_54;
  undefined4 local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_108;
  plVar11 = (longlong *)(param_1 + 0xe0);
  local_54 = 0;
  local_4c = 0;
  local_64 = 0;
  uStack_5c = 0;
  local_d8 = param_3;
  local_d4 = param_2;
  bVar4 = KeAcquireSpinLockRaiseToDpc(plVar11);
  plVar12 = (longlong *)(ulonglong)bVar4;
  plVar7 = (longlong *)ExAllocatePool2(0x40,0x20e,0x69665356);
  if (plVar7 == (longlong *)0x0) {
    KeReleaseSpinLock(plVar11,bVar4);
    puVar10 = auStack_108;
    iVar6 = -0x3fffff66;
    goto LAB_14001ddc5;
  }
  plVar2 = plVar7 + 0xb;
  KeInitializeEvent(plVar2,1);
  *(undefined4 *)(plVar7 + 4) = local_d8;
  *(undefined4 *)(plVar7 + 5) = local_d4;
  plVar7[3] = param_4;
  *(undefined4 *)(plVar7 + 2) = 1;
  plVar7[8] = param_1;
  *(undefined1 *)(plVar7 + 0x13) = 0xe;
  *(undefined2 *)((longlong)plVar7 + 0x99) = 0x602;
  *(undefined4 *)(plVar7 + 0x39) = 0;
  *(undefined2 *)((longlong)plVar7 + 0x1cc) = 0;
  *(undefined4 *)((longlong)plVar7 + 0x7c) = 0;
  *(uint *)((longlong)plVar7 + 0xb4) = *(uint *)((longlong)plVar7 + 0xb4) | 0x20f;
  *(undefined4 *)(plVar7 + 0x14) = 2;
  *(undefined4 *)(plVar7 + 0x16) = 2;
  plVar7[0x12] = -1;
  plVar7[0x11] = -1;
  *(undefined4 *)((longlong)plVar7 + 0xa4) = 6;
  *(undefined4 *)((longlong)plVar7 + 0xac) = 0xe;
  *(undefined4 *)(plVar7 + 0xf) = 1;
  *(undefined4 *)(plVar7 + 0x10) = 0x40000000;
  uVar8 = RoReferenceEx((uint *)(*(longlong *)(param_1 + 0xd0) + 0x18));
  puVar10 = auStack_108;
  if ((char)uVar8 != '\0') {
    plVar1 = *(longlong **)(param_1 + 0xf0);
    if (*plVar1 == param_1 + 0xe8) {
      plVar7[1] = (longlong)plVar1;
      *plVar7 = param_1 + 0xe8;
      *plVar1 = (longlong)plVar7;
      *(longlong **)(param_1 + 0xf0) = plVar7;
      KeReleaseSpinLock(plVar11,bVar4);
      local_d0 = vSwitchFlIndicationComplete;
      plVar12 = plVar7 + 3;
      local_c8 = **(undefined8 **)(param_1 + 0xd0);
      local_a8 = plVar7 + 9;
      local_c0 = plVar7;
      local_b8 = plVar12;
      local_b0 = plVar7 + 0x13;
      iVar6 = (**(code **)((*(undefined8 **)(param_1 + 0xd0))[1] + 8))(&local_d0);
      if (iVar6 == 0x103) {
        local_e8 = 0;
        KeWaitForSingleObject(plVar2,0,0,0);
        iVar6 = (int)plVar7[0xe];
      }
      if (iVar6 < 0) {
        uVar5 = KeAcquireSpinLockRaiseToDpc(plVar11);
        lVar9 = *plVar7;
        if ((*(longlong **)(lVar9 + 8) != plVar7) ||
           (plVar2 = (longlong *)plVar7[1], (longlong *)*plVar2 != plVar7)) goto LAB_14001dd96;
        *plVar2 = lVar9;
        *(longlong **)(lVar9 + 8) = plVar2;
LAB_14001dcb4:
        KeReleaseSpinLock(param_1 + 0xe0,CONCAT71((int7)((ulonglong)lVar9 >> 8),uVar5));
        vSwitchFlpCleanupInterface((longlong)plVar7);
      }
      else {
        local_70 = *plVar12;
        plVar11 = plVar7 + 10;
        local_80 = plVar7 + 0xf;
        plVar12 = (longlong *)0x0;
        local_68 = 0;
        local_98 = plVar7[9];
        local_88 = &local_70;
        local_a0 = vSwitchFlIndicationComplete;
        local_90 = plVar7;
        local_78 = plVar11;
        iVar6 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0xd0) + 8) + 0x20))(&local_a0);
        if (iVar6 == 0x103) {
          local_e8 = 0;
          KeWaitForSingleObject(plVar2,0,0,0);
          iVar6 = (int)plVar7[0xe];
        }
        if (iVar6 < 0) {
          *plVar11 = 0;
          uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 0xe0);
          lVar9 = *plVar7;
          if ((*(longlong **)(lVar9 + 8) != plVar7) ||
             (plVar2 = (longlong *)plVar7[1], (longlong *)*plVar2 != plVar7)) goto LAB_14001dd96;
          *plVar2 = lVar9;
          *(longlong **)(lVar9 + 8) = plVar2;
          goto LAB_14001dcb4;
        }
        *param_5 = plVar7;
      }
      puVar10 = auStack_108;
      goto LAB_14001ddc5;
    }
LAB_14001dd96:
    bVar4 = (byte)plVar12;
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(3);
    puVar10 = auStack_100;
  }
  *(undefined8 *)(puVar10 + -8) = 0x14001ddaa;
  KeReleaseSpinLock(plVar11,bVar4);
  *(undefined8 *)(puVar10 + -8) = 0x14001ddbb;
  ExFreePoolWithTag(plVar7,0);
  iVar6 = -0x3fffffaa;
LAB_14001ddc5:
  *(undefined8 *)(puVar10 + -8) = 0x14001ddd1;
  return iVar6;
}



===== vSwitchFlpDeleteCompartment @ 14001ddf4 =====

void vSwitchFlpDeleteCompartment(longlong param_1)

{
  ulonglong uVar1;
  int local_res8 [2];
  
  if (*(longlong **)(param_1 + 0x248) != (longlong *)0x0) {
    vSwitchFlpUnbindInterface(*(longlong **)(param_1 + 0x248));
  }
  if (*(longlong **)(param_1 + 0x240) != (longlong *)0x0) {
    vSwitchFlpUnbindInterface(*(longlong **)(param_1 + 0x240));
  }
  if (*(int *)(param_1 + 0x230) != 0) {
    uVar1 = *(ulonglong *)(param_1 + 0x238);
    NdisIfDeregisterInterface();
    NdisIfFreeNetLuidIndex(uVar1 >> 0x30,(uint)(uVar1 >> 0x18) & 0xffffff);
  }
  if (*(int *)(param_1 + 0x21c) != 0) {
    local_res8[0] = *(int *)(param_1 + 0x21c);
    NsiSetAllParameters(1,3,&NPI_MS_NDIS_MODULEID,7,local_res8,4,0,0);
  }
  ExFreePoolWithTag(param_1,0);
  return;
}



===== vSwitchFlpDerefCompartment @ 14001ded0 =====

undefined8 vSwitchFlpDerefCompartment(uint *param_1,int param_2)

{
  longlong *plVar1;
  code *pcVar2;
  bool bVar3;
  longlong lVar4;
  bool bVar5;
  longlong *plVar6;
  undefined1 *puVar7;
  undefined8 uVar8;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  bVar3 = false;
  RtlAcquireWriteLock(0x14002c548);
  plVar6 = vSwitchFlpFindCompartmentUnderLock(param_1,param_2);
  puVar7 = auStack_48;
  if (plVar6 == (longlong *)0x0) {
LAB_14001df4c:
    uVar8 = 0xc0000225;
  }
  else {
    LOCK();
    plVar1 = plVar6 + 2;
    lVar4 = *plVar1;
    *(int *)plVar1 = (int)*plVar1 + -1;
    UNLOCK();
    bVar5 = false;
    if ((int)lVar4 == 1) {
      lVar4 = *plVar6;
      if ((*(longlong **)(lVar4 + 8) != plVar6) ||
         (plVar1 = (longlong *)plVar6[1], (longlong *)*plVar1 != plVar6)) {
        pcVar2 = (code *)swi(0x29);
        (*pcVar2)(3);
        puVar7 = auStack_40;
        goto LAB_14001df4c;
      }
      *plVar1 = lVar4;
      *(longlong **)(lVar4 + 8) = plVar1;
      bVar5 = true;
    }
    bVar3 = bVar5;
    uVar8 = 0;
    puVar7 = auStack_48;
  }
  *(undefined8 *)(puVar7 + -8) = 0x14001df5d;
  KeReleaseInStackQueuedSpinLock(puVar7 + 0x20);
  if (bVar3) {
    *(undefined8 *)(puVar7 + -8) = 0x14001df6f;
    vSwitchFlpDeleteCompartment((longlong)plVar6);
  }
  return uVar8;
}



===== vSwitchFlpFindCompartmentUnderLock @ 14001df88 =====

undefined8 * vSwitchFlpFindCompartmentUnderLock(uint *param_1,int param_2)

{
  ulonglong uVar1;
  undefined8 *puVar2;
  
  puVar2 = DAT_14002c558;
  while( true ) {
    if ((undefined8 **)puVar2 == &DAT_14002c558) {
      return (undefined8 *)0x0;
    }
    if (((*(int *)(puVar2 + 0x43) == param_2) &&
        ((uint)*(byte *)((longlong)puVar2 + 0x214) == *param_1)) &&
       (uVar1 = RtlCompareMemory((longlong)puVar2 + 0x14,*(undefined8 *)(param_1 + 2),*param_1),
       uVar1 == *param_1)) break;
    puVar2 = (undefined8 *)*puVar2;
  }
  return puVar2;
}



===== vSwitchFlpGetNblInfo @ 14001e008 =====

/* WARNING: Removing unreachable block (ram,0x00014001e0e3) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffffe8 : 0x00014001e0f3 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void vSwitchFlpGetNblInfo(longlong param_1,short *param_2,uint *param_3,int *param_4,uint *param_5)

{
  char cVar1;
  longlong lVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  longlong lVar7;
  
  lVar2 = *(longlong *)(param_1 + 8);
  lVar7 = *(longlong *)(lVar2 + 8);
  if ((*(byte *)(lVar7 + 10) & 5) == 0) {
    lVar7 = MmMapLockedPagesSpecifyCache(lVar7,0,1,0,0,0x40000000);
  }
  else {
    lVar7 = *(longlong *)(lVar7 + 0x18);
  }
  lVar7 = (ulonglong)*(uint *)(lVar2 + 0x10) + lVar7;
  if (*param_2 != 0x800) {
    *param_3 = (uint)*(byte *)(lVar7 + 6);
    iVar4 = Ipv6AddressType((short *)(lVar7 + 0x18));
    cVar1 = *(char *)(lVar7 + 0x18);
    *param_4 = iVar4;
    if (cVar1 == -1) {
      uVar5 = *(byte *)(lVar7 + 0x19) & 0xf;
    }
    else {
      uVar6 = Ipv6UnicastAddressScope((short *)(lVar7 + 0x18));
      uVar5 = (uint)uVar6;
    }
    goto LAB_14001e132;
  }
  *param_3 = (uint)*(byte *)(lVar7 + 9);
  iVar4 = Ipv4AddressType((uint *)(lVar7 + 0x10));
  uVar5 = *(uint *)(lVar7 + 0x10);
  *param_4 = iVar4;
  if (uVar5 != 0xffffffff) {
    bVar3 = (byte)uVar5;
    if ((bVar3 & 0xf0) == 0xe0) {
      if ((uVar5 & 0xffffff) != 0xe0) {
        if ((short)uVar5 == -0x11) {
          uVar5 = 4;
        }
        else {
          uVar5 = 0xe;
          if (bVar3 == 0xef) {
            uVar5 = 5;
          }
        }
        goto LAB_14001e132;
      }
    }
    else if (((short)uVar5 != -0x157) && (bVar3 != 0x7f)) {
      uVar5 = 0xe;
      goto LAB_14001e132;
    }
  }
  uVar5 = 2;
LAB_14001e132:
  *param_5 = uVar5;
  return;
}



===== vSwitchFlpRefOrCreateCompartment @ 14001e15c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int vSwitchFlpRefOrCreateCompartment(uint *param_1,undefined8 param_2,undefined8 param_3)

{
  int *piVar1;
  ulonglong *puVar2;
  undefined4 uVar3;
  int iVar4;
  code *pcVar5;
  bool bVar6;
  byte bVar7;
  int iVar8;
  undefined8 *puVar9;
  ulonglong uVar10;
  undefined8 *puVar11;
  undefined8 uVar12;
  undefined1 *puVar13;
  int iVar14;
  undefined1 auStack_a8 [8];
  undefined1 auStack_a0 [44];
  undefined4 local_74;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_a8;
  local_58 = 0;
  uStack_50 = 0;
  local_60 = 0;
  local_70 = 0;
  uStack_68 = 0;
  iVar8 = 0;
  uVar12 = param_2;
  bVar6 = L2IsvSwitchLayersEmpty();
  if (bVar6) {
    L2KfdLogVSwitchLayerEmptyAtCompartmentCreationTelemetry(1,uVar12,param_3);
    puVar13 = auStack_a8;
    iVar8 = 0;
    goto LAB_14001e3c5;
  }
  L2KfdLogVSwitchLayerEmptyAtCompartmentCreationTelemetry(0,uVar12,param_3);
  local_74 = NdisGetThreadObjectCompartmentId(SystemReserved1[0xf]);
  RtlAcquireWriteLock(0x14002c548);
  iVar14 = (int)param_2;
  puVar9 = vSwitchFlpFindCompartmentUnderLock(param_1,iVar14);
  if (puVar9 == (undefined8 *)0x0) {
    puVar9 = (undefined8 *)ExAllocatePool2(0x40,0x250,0x63665356);
    if (puVar9 != (undefined8 *)0x0) {
      *(undefined4 *)(puVar9 + 2) = 1;
      bVar7 = -(*param_1 < 0x200) & (byte)*param_1;
      *(byte *)((longlong)puVar9 + 0x214) = bVar7;
      memmove((void *)((longlong)puVar9 + 0x14),*(void **)(param_1 + 2),(ulonglong)bVar7);
      puVar13 = auStack_a8;
      *(int *)(puVar9 + 0x43) = iVar14;
      puVar11 = &DAT_14002c558;
      if ((undefined8 *)*DAT_14002c560 != &DAT_14002c558) {
        puVar11 = (undefined8 *)0x3;
        pcVar5 = (code *)swi(0x29);
        DAT_14002c560 = (undefined8 *)(*pcVar5)();
        puVar13 = auStack_a0;
      }
      *puVar9 = puVar11;
      puVar9[1] = DAT_14002c560;
      *DAT_14002c560 = puVar9;
      *(undefined8 *)(puVar13 + -8) = 0x14001e2a7;
      DAT_14002c560 = puVar9;
      KeReleaseInStackQueuedSpinLock(puVar13 + 0x38);
      *(undefined8 *)(puVar13 + -8) = 0x14001e2bd;
      ExUuidCreate(puVar9 + 0x44);
      piVar1 = (int *)((longlong)puVar9 + 0x21c);
      *(undefined8 *)(puVar13 + -8) = 0x14001e2d9;
      iVar8 = vSwitchFlpAllocCompartmentId((undefined4 *)(puVar9 + 0x44),piVar1,puVar13 + 0x50);
      if (-1 < iVar8) {
        puVar2 = puVar9 + 0x47;
        puVar11 = puVar9 + 0x46;
        *(undefined8 *)(puVar13 + -8) = 0x14001e301;
        iVar8 = vSwitchFlpCreateAdapter((undefined4 *)(puVar13 + 0x50),puVar11,puVar2);
        if (-1 < iVar8) {
          if (DAT_14002c2b0 != 0) {
            uVar10 = *puVar2;
            uVar3 = *(undefined4 *)puVar11;
            iVar8 = *piVar1;
            *(undefined8 **)(puVar13 + 0x20) = puVar9 + 0x48;
            *(undefined8 *)(puVar13 + -8) = 0x14001e337;
            iVar8 = vSwitchFlpCreateAndBindInterface
                              (0x14002c1e0,iVar8,uVar3,uVar10,*(undefined8 **)(puVar13 + 0x20));
            if (iVar8 < 0) goto LAB_14001e3b8;
          }
          if (DAT_14002c1b0 != 0) {
            uVar10 = *puVar2;
            uVar3 = *(undefined4 *)puVar11;
            iVar8 = *piVar1;
            *(undefined8 **)(puVar13 + 0x20) = puVar9 + 0x49;
            *(undefined8 *)(puVar13 + -8) = 0x14001e369;
            iVar8 = vSwitchFlpCreateAndBindInterface
                              (0x14002c0e0,iVar8,uVar3,uVar10,*(undefined8 **)(puVar13 + 0x20));
            if (iVar8 < 0) goto LAB_14001e3b8;
          }
          iVar8 = *piVar1;
          iVar4 = *(int *)(puVar13 + 0x34);
          if (iVar8 == iVar4) {
            bVar6 = false;
          }
          else {
            *(undefined8 *)(puVar13 + -8) = 0x14001e381;
            iVar8 = NdisSetCurrentThreadCompartmentId(iVar8);
            if (iVar8 < 0) goto LAB_14001e3b8;
            bVar6 = true;
          }
          *(undefined8 *)(puVar13 + -8) = 0x14001e397;
          uVar10 = vSwitchFlpSetCompartmentForwarding((longlong)puVar9);
          iVar8 = (int)uVar10;
          if (-1 < iVar8) {
            *(undefined8 *)(puVar13 + -8) = 0x14001e3a5;
            iVar8 = vSwitchFlpSetCompartmentDefaultRoute((longlong)puVar9);
          }
          if (bVar6) {
            *(undefined8 *)(puVar13 + -8) = 0x14001e3b4;
            NdisSetCurrentThreadCompartmentId(iVar4);
          }
          if (-1 < iVar8) goto LAB_14001e3c5;
        }
      }
LAB_14001e3b8:
      *(undefined8 *)(puVar13 + -8) = 0x14001e3c3;
      vSwitchFlpDerefCompartment(param_1,iVar14);
      goto LAB_14001e3c5;
    }
    iVar8 = -0x3fffff66;
  }
  else {
    LOCK();
    *(int *)(puVar9 + 2) = *(int *)(puVar9 + 2) + 1;
    UNLOCK();
  }
  KeReleaseInStackQueuedSpinLock(&local_70);
  puVar13 = auStack_a8;
LAB_14001e3c5:
  *(undefined8 *)(puVar13 + -8) = 0x14001e3d2;
  return iVar8;
}



===== vSwitchFlpSetCompartmentDefaultRoute @ 14001e3f4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void vSwitchFlpSetCompartmentDefaultRoute(longlong param_1)

{
  int iVar1;
  undefined1 auStack_f8 [32];
  ulonglong *local_d8;
  undefined4 local_d0;
  undefined8 *local_c8;
  undefined4 local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  ulonglong local_98 [6];
  uint local_68 [5];
  ushort local_54;
  undefined8 local_52;
  undefined8 uStack_4a;
  ushort local_42;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 uStack_28;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_f8;
  local_54 = (ushort)(byte)local_54;
  local_42 = (ushort)(byte)local_42;
  local_98[0] = 0;
  local_98[1] = 0;
  local_98[2] = 0;
  local_98[3] = 0;
  local_98[4] = 0;
  local_98[5] = 0;
  uStack_a0 = 0xffffffffffffffff;
  local_b8 = 0xffffffffffffff00;
  uStack_b0 = 0x100ffffffff;
  local_a8 = 0xffffffff00000003;
  if (DAT_14002c2b0 != 0) {
    local_98[0] = (ulonglong)*(uint *)(param_1 + 0x21c);
    local_98[1] = 0;
    local_98[2] = 0;
    local_98[3] = *(undefined8 *)(*(longlong *)(param_1 + 0x240) + 0x18);
    local_98[4] = *(undefined8 *)(*(longlong *)(param_1 + 0x240) + 0x18);
    local_98[5] = 0;
    local_c8 = &local_b8;
    local_c0 = 0x20;
    local_d8 = local_98;
    local_d0 = 0x30;
    iVar1 = NsiSetAllParameters(1,2,&NPI_MS_IPV4_MODULEID);
    if (iVar1 < 0) {
      return;
    }
  }
  if (DAT_14002c1b0 != 0) {
    local_68[0] = *(uint *)(param_1 + 0x21c);
    local_54 = 0;
    local_42 = 0;
    local_68[1] = 0;
    local_68[2] = 0;
    local_68[3] = 0;
    local_68[4] = 0;
    local_c0 = 0x20;
    local_52 = 0;
    uStack_4a = 0;
    local_40 = *(undefined8 *)(*(longlong *)(param_1 + 0x248) + 0x18);
    local_38 = *(undefined8 *)(*(longlong *)(param_1 + 0x248) + 0x18);
    local_c8 = &local_b8;
    local_d8 = (ulonglong *)local_68;
    local_d0 = 0x48;
    local_30 = 0;
    uStack_28 = 0;
    NsiSetAllParameters(1,2,&NPI_MS_IPV6_MODULEID);
  }
  return;
}



===== vSwitchFlpSetCompartmentForwarding @ 14001e59c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong vSwitchFlpSetCompartmentForwarding(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined1 auStack_68 [32];
  undefined4 *local_48;
  undefined4 local_40;
  undefined8 *local_38;
  undefined4 local_30;
  undefined4 local_28 [2];
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  uVar3 = 0;
  local_28[0] = *(undefined4 *)(param_1 + 0x21c);
  local_20 = 0xffffffff00000000;
  uStack_18 = 0xff010100ffffffff;
  if (DAT_14002c2b0 != 0) {
    local_38 = &local_20;
    local_30 = 0x10;
    local_48 = local_28;
    local_40 = 4;
    uVar2 = NsiSetAllParameters(1,0,&NPI_MS_IPV4_MODULEID,2);
    uVar3 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) {
      return uVar2;
    }
  }
  if (DAT_14002c1b0 != 0) {
    local_30 = 0x10;
    local_38 = &local_20;
    local_40 = 4;
    local_48 = local_28;
    uVar1 = NsiSetAllParameters(1,0,&NPI_MS_IPV6_MODULEID,2);
    uVar3 = (ulonglong)uVar1;
  }
  return uVar3;
}



===== vSwitchFlpUnbindInterface @ 14001e690 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void vSwitchFlpUnbindInterface(longlong *param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined1 uVar5;
  int iVar6;
  code *local_28;
  longlong lStack_20;
  code *local_18;
  longlong lStack_10;
  
  if (param_1 != (longlong *)0x0) {
    lVar1 = param_1[8];
    local_18 = (code *)0x0;
    lStack_10 = 0;
    local_28 = (code *)0x0;
    lStack_20 = 0;
    uVar5 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0xe0);
    lVar2 = *param_1;
    if ((*(longlong **)(lVar2 + 8) != param_1) ||
       (plVar3 = (longlong *)param_1[1], (longlong *)*plVar3 != param_1)) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    KeReleaseSpinLock(lVar1 + 0xe0,CONCAT71((int7)((ulonglong)plVar3 >> 8),uVar5));
    if (param_1[10] != 0) {
      local_28 = vSwitchFlIndicationComplete;
      lStack_20 = param_1[10];
      iVar6 = (**(code **)(*(longlong *)(*(longlong *)(lVar1 + 0xd0) + 8) + 0x28))(&local_28);
      if (iVar6 == 0x103) {
        KeWaitForSingleObject(param_1 + 0xb,0,0,0,0);
      }
      param_1[10] = 0;
    }
    if (param_1[9] != 0) {
      local_18 = vSwitchFlIndicationComplete;
      lStack_10 = param_1[9];
      iVar6 = (**(code **)(*(longlong *)(*(longlong *)(lVar1 + 0xd0) + 8) + 0x10))(&local_18);
      if (iVar6 == 0x103) {
        KeWaitForSingleObject(param_1 + 0xb,0,0,0,0);
      }
      param_1[9] = 0;
    }
    LOCK();
    plVar3 = param_1 + 2;
    lVar1 = *plVar3;
    *(int *)plVar3 = (int)*plVar3 + -1;
    UNLOCK();
    if ((int)lVar1 == 1) {
      vSwitchFlpCleanupInterface((longlong)param_1);
    }
  }
  return;
}



===== WfpReportError @ 14001e7ec =====

void WfpReportError(undefined1 param_1)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) != 0)) {
    WPP_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
              &WPP_c15558396cc63da9014e9889efdb8f36_Traceguids,"WfpPoolAllocNonPaged",param_1);
  }
  return;
}



===== WfpPoolAllocNonPaged @ 14001e844 =====

longlong WfpPoolAllocNonPaged(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  lVar2 = 0;
  uVar3 = 0x40;
  lVar1 = ExAllocatePool2(0x40,0x30,0x67326c57);
  *param_3 = lVar1;
  if (lVar1 == 0) {
    lVar2 = WfpReportSysErrorAsNtStatus(uVar3,"ExAllocatePool2",-0x3fffffe9);
    if (lVar2 != 0) {
      WfpReportError((char)lVar2);
    }
  }
  return lVar2;
}



===== WfpPoolFree @ 14001e8ac =====

void WfpPoolFree(longlong *param_1)

{
  if (*param_1 != 0) {
    ExFreePoolWithTag(*param_1,0);
  }
  *param_1 = -0x4524520545245206;
  return;
}



===== GetImageTuple @ 14001e8e8 =====

/* WARNING: Removing unreachable block (ram,0x00014001e91e) */

undefined8 GetImageTuple(undefined8 param_1,dword *param_2,dword *param_3)

{
  *param_2 = 0xcd2ddf56;
  *param_3 = 0x3a000;
  return 1;
}



===== InitializeTelemetryAssertsKMByDriverObject @ 14001e938 =====

ulonglong InitializeTelemetryAssertsKMByDriverObject(undefined8 param_1)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  longlong lStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_38 = 0;
  lStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  LOCK();
  UNLOCK();
  if (g_AssertsOperational == 0) {
    RtlInitUnicodeString(&local_48,0);
    uVar3 = IoQueryFullDriverPath(param_1,&local_48);
    if (-1 < (int)uVar3) {
      uVar2 = RtlUnicodeStringToAnsiString(&local_38,&local_48,1);
      uVar3 = (ulonglong)uVar2;
      ExFreePoolWithTag(uStack_40,0);
      if (-1 < (int)uVar2) {
        uVar2 = (uint)(ushort)local_38;
        do {
          uVar1 = uVar2;
          uVar2 = uVar1 - 1;
          if (uVar2 == 0) goto LAB_14001ea19;
        } while (*(char *)((ulonglong)uVar2 + lStack_30) != '\\');
        if (uVar2 != (ushort)local_38) {
          local_28 = 0;
          uStack_20 = 0;
          RtlInitAnsiString(&local_28,(ulonglong)uVar1 + lStack_30);
          local_18 = local_28;
          uStack_10 = uStack_20;
          uVar3 = InitializeTelemetryAssertsKMWorkerInternal((ushort *)&local_18);
          uVar3 = uVar3 & 0xffffffff;
        }
LAB_14001ea19:
        RtlFreeAnsiString(&local_38);
      }
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



===== InitializeTelemetryAssertsKMWorkerInternal @ 14001ea40 =====

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
    _DAT_14002c528 = &g_MicrosoftTelemetryAssertsTriggeredList;
    g_MicrosoftTelemetryAssertsTriggeredList = &g_MicrosoftTelemetryAssertsTriggeredList;
    TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(0x140033040);
    TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(0x140033008);
    TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(0x140033078);
    LOCK();
    g_AssertsOperational = g_AssertsOperational + 1;
    UNLOCK();
  }
  return uVar1;
}



===== MicrosoftTelemetryAssertTriggeredNoArgsKM @ 14001eaf4 =====

void MicrosoftTelemetryAssertTriggeredNoArgsKM(void)

{
  IMAGE_DOS_HEADER *unaff_retaddr;
  
  MicrosoftTelemetryAssertTriggeredWorker(unaff_retaddr,0,0,0xffffffff);
  return;
}



===== MicrosoftTelemetryAssertTriggeredWorker @ 14001eb24 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MicrosoftTelemetryAssertTriggeredWorker
               (IMAGE_DOS_HEADER *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  longlong lVar2;
  undefined1 uVar3;
  char cVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  longlong *plVar9;
  longlong *plVar10;
  undefined8 uVar11;
  longlong *plVar12;
  char *pcVar13;
  uint uVar14;
  undefined1 *puVar15;
  ulonglong uVar16;
  undefined4 uVar17;
  longlong lVar18;
  char *pcVar19;
  undefined1 auStack_168 [8];
  undefined1 auStack_160 [120];
  undefined1 local_e8 [32];
  undefined1 *local_c8;
  undefined8 local_c0;
  undefined1 *local_b8;
  undefined8 local_b0;
  undefined1 *local_a8;
  undefined8 local_a0;
  undefined1 *local_98;
  undefined8 local_90;
  longlong local_88 [2];
  undefined1 *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  longlong local_48 [2];
  ulonglong local_38;
  
  puVar15 = auStack_168;
  local_38 = __security_cookie ^ (ulonglong)auStack_168;
  LOCK();
  UNLOCK();
  if (g_AssertsOperational == 0) goto LAB_14001f034;
  uVar3 = KeAcquireSpinLockRaiseToDpc(&g_AssertSpinLock);
  puVar15 = auStack_168;
  for (plVar10 = g_MicrosoftTelemetryAssertsTriggeredList;
      (longlong **)plVar10 != &g_MicrosoftTelemetryAssertsTriggeredList;
      plVar10 = (longlong *)*plVar10) {
    plVar9 = plVar10 + -4;
    if ((IMAGE_DOS_HEADER *)*plVar9 == param_1) goto LAB_14001ec56;
  }
  plVar9 = (longlong *)ExAllocatePool2(0x42,0x30,0x74727341);
  lVar18 = _DAT_fffff78000000320;
  puVar15 = auStack_168;
  if (plVar9 != (longlong *)0x0) {
    *plVar9 = (longlong)param_1;
    uVar6 = KeQueryTimeIncrement();
    puVar15 = auStack_168;
    *(undefined4 *)(plVar9 + 2) = 0;
    *(undefined4 *)((longlong)plVar9 + 0x14) = 0;
    *(undefined4 *)(plVar9 + 3) = 0;
    plVar9[1] = (longlong)((ulonglong)uVar6 * lVar18) / 10000 + -0xea61;
    plVar10 = plVar9 + 4;
    plVar12 = g_MicrosoftTelemetryAssertsTriggeredList;
    if ((longlong **)g_MicrosoftTelemetryAssertsTriggeredList[1] !=
        &g_MicrosoftTelemetryAssertsTriggeredList) {
      plVar12 = (longlong *)0x3;
      pcVar1 = (code *)swi(0x29);
      plVar10 = (longlong *)(*pcVar1)();
      puVar15 = auStack_160;
    }
    *plVar10 = (longlong)plVar12;
    plVar10[1] = (longlong)&g_MicrosoftTelemetryAssertsTriggeredList;
    plVar12[1] = (longlong)plVar10;
    g_MicrosoftTelemetryAssertsTriggeredList = plVar10;
LAB_14001ec56:
    *(int *)(plVar9 + 2) = (int)plVar9[2] + 1;
    *(int *)((longlong)plVar9 + 0x14) = *(int *)((longlong)plVar9 + 0x14) + 1;
    lVar2 = _DAT_fffff78000000320;
    *(undefined8 *)(puVar15 + -8) = 0x14001ec66;
    uVar6 = KeQueryTimeIncrement();
    *(undefined4 *)(puVar15 + 0x54) = 0;
    *(undefined4 *)(puVar15 + 0x50) = 0;
    lVar18 = (longlong)((ulonglong)uVar6 * lVar2) / 10000;
    if (60000 < (ulonglong)(lVar18 - plVar9[1])) {
      *(undefined8 *)(puVar15 + -8) = 0x14001ecb4;
      uVar11 = GetImageTuple((ulonglong)uVar6 * lVar2,(dword *)(puVar15 + 0x54),
                             (dword *)(puVar15 + 0x50));
      uVar6 = *(uint *)(puVar15 + 0x50);
      iVar7 = (int)uVar11;
      if ((((iVar7 == 0) || (param_1 < &IMAGE_DOS_HEADER_140000000)) ||
          ((IMAGE_DOS_HEADER *)(IMAGE_DOS_HEADER_140000000.e_magic + uVar6) <
           (IMAGE_DOS_HEADER *)(IMAGE_DOS_HEADER_140000000.e_magic + 1))) ||
         ((IMAGE_DOS_HEADER *)(IMAGE_DOS_HEADER_140000000.e_magic + uVar6) < param_1)) {
        uVar14 = 0;
      }
      else {
        uVar14 = (int)param_1 + 0xc0000000;
      }
      *(int *)(puVar15 + 0x50) = (int)plVar9[2];
      plVar9[1] = lVar18;
      lVar18 = plVar9[3];
      *(undefined4 *)(puVar15 + 0x74) = *(undefined4 *)((longlong)plVar9 + 0x14);
      *(undefined8 *)(puVar15 + -8) = 0x14001ed08;
      KeReleaseSpinLock(&g_AssertSpinLock,uVar3);
      if (5 < DAT_140033040) {
        *(undefined8 *)(puVar15 + -8) = 0x14001ed37;
        cVar4 = _tlgKeywordOn(0x140033040,0x400000000000);
        uVar11 = 0;
        if (cVar4 != '\0') {
          local_c8 = puVar15 + 0x58;
          *(undefined4 *)(puVar15 + 0x58) = 10;
          local_b8 = puVar15 + 0x5c;
          local_c0 = 4;
          *(uint *)(puVar15 + 0x5c) = uVar14;
          local_a8 = puVar15 + 0x60;
          local_b0 = 4;
          *(uint *)(puVar15 + 0x60) = -(uint)(iVar7 != 0) & *(uint *)(puVar15 + 0x54);
          local_98 = puVar15 + 100;
          local_a0 = 4;
          *(uint *)(puVar15 + 100) = -(uint)(iVar7 != 0) & uVar6;
          local_90 = 4;
          pcVar13 = "<unknown>";
          if (g_ModuleName != (char *)0x0) {
            pcVar13 = g_ModuleName;
          }
          *(undefined8 *)(puVar15 + -8) = 0x14001edc9;
          _tlgCreate1Sz_char(local_88,pcVar13);
          local_78 = puVar15 + 0x68;
          *(undefined4 *)(puVar15 + 0x6c) = *(undefined4 *)(puVar15 + 0x74);
          local_68 = puVar15 + 0x6c;
          *(undefined4 *)(puVar15 + 0x68) = *(undefined4 *)(puVar15 + 0x50);
          local_70 = 4;
          local_60 = 4;
          *(undefined8 *)(puVar15 + -8) = 0x14001ee02;
          bVar5 = KeGetCurrentIrql();
          *(uint *)(puVar15 + 0x70) = (uint)bVar5;
          local_58 = puVar15 + 0x70;
          local_50 = 4;
          *(undefined8 *)(puVar15 + -8) = 0x14001ee2e;
          _tlgCreate1Sz_char(local_48,"<unknown>");
          *(undefined1 **)(puVar15 + 0x28) = local_e8;
          *(undefined4 *)(puVar15 + 0x20) = 0xb;
          *(undefined8 *)(puVar15 + -8) = 0x14001ee52;
          _tlgWriteTransfer_EtwWriteTransfer
                    (0x140033040,&DAT_140029112,uVar11,param_4,*(undefined4 *)(puVar15 + 0x20),
                     *(undefined8 **)(puVar15 + 0x28));
        }
      }
      if ((DAT_140033078 == 0) || ((int)lVar18 != 0)) goto LAB_14001f034;
      *(undefined8 *)(puVar15 + -8) = 0x14001ee71;
      cVar4 = KeGetCurrentIrql();
      if (cVar4 != '\0') goto LAB_14001f034;
      *(undefined4 *)(puVar15 + 0x40) = 0;
      *(undefined8 *)(puVar15 + 0x38) = 0;
      *(undefined8 *)(puVar15 + 0x30) = 0;
      *(ulonglong *)(puVar15 + 0x28) = (ulonglong)uVar6;
      *(ulonglong *)(puVar15 + 0x20) = (ulonglong)*(uint *)(puVar15 + 0x54);
      uVar16 = (ulonglong)uVar14;
      *(undefined8 *)(puVar15 + -8) = 0x14001eeb9;
      pcVar13 = g_ModuleName;
      iVar8 = DbgkWerCaptureLiveKernelDump(L"TELASSERT",0x1d1);
      if (5 < DAT_140033040) {
        *(undefined8 *)(puVar15 + -8) = 0x14001eee3;
        cVar4 = _tlgKeywordOn(0x140033040,0x400000000000);
        if (cVar4 != '\0') {
          local_c8 = puVar15 + 0x70;
          local_c0 = 4;
          uVar17 = 10;
          local_b8 = puVar15 + 0x6c;
          *(undefined4 *)(puVar15 + 0x70) = 10;
          *(uint *)(puVar15 + 0x6c) = uVar14;
          local_a8 = puVar15 + 0x68;
          local_b0 = 4;
          *(uint *)(puVar15 + 0x68) = -(uint)(iVar7 != 0) & *(uint *)(puVar15 + 0x54);
          local_a0 = 4;
          local_90 = 4;
          *(uint *)(puVar15 + 100) = -(uint)(iVar7 != 0) & uVar6;
          local_98 = puVar15 + 100;
          pcVar19 = "<unknown>";
          if (g_ModuleName != (char *)0x0) {
            pcVar19 = g_ModuleName;
          }
          *(undefined8 *)(puVar15 + -8) = 0x14001ef73;
          _tlgCreate1Sz_char(local_88,pcVar19);
          *(undefined4 *)(puVar15 + 0x60) = *(undefined4 *)(puVar15 + 0x50);
          local_78 = puVar15 + 0x60;
          local_70 = 4;
          *(undefined4 *)(puVar15 + 0x5c) = *(undefined4 *)(puVar15 + 0x74);
          local_68 = puVar15 + 0x5c;
          local_58 = puVar15 + 0x58;
          *(undefined1 **)(puVar15 + 0x28) = local_e8;
          *(undefined4 *)(puVar15 + 0x20) = uVar17;
          local_60 = 4;
          *(int *)(puVar15 + 0x58) = iVar8;
          local_50 = 4;
          *(undefined8 *)(puVar15 + -8) = 0x14001efdb;
          _tlgWriteTransfer_EtwWriteTransfer
                    (0x140033040,&DAT_14002917f,uVar16,pcVar13,*(undefined4 *)(puVar15 + 0x20),
                     *(undefined8 **)(puVar15 + 0x28));
        }
      }
      if (iVar8 != 0) goto LAB_14001f034;
      *(undefined8 *)(puVar15 + -8) = 0x14001efed;
      uVar3 = KeAcquireSpinLockRaiseToDpc(&g_AssertSpinLock);
      plVar10 = g_MicrosoftTelemetryAssertsTriggeredList;
      if ((longlong **)g_MicrosoftTelemetryAssertsTriggeredList !=
          &g_MicrosoftTelemetryAssertsTriggeredList) {
        do {
          if ((IMAGE_DOS_HEADER *)plVar10[-4] == param_1) {
            *(int *)(plVar10 + -1) = (int)plVar10[-1] + 1;
            break;
          }
          plVar10 = (longlong *)*plVar10;
        } while ((longlong **)plVar10 != &g_MicrosoftTelemetryAssertsTriggeredList);
      }
    }
  }
  *(undefined8 *)(puVar15 + -8) = 0x14001f02f;
  KeReleaseSpinLock(&g_AssertSpinLock,uVar3);
LAB_14001f034:
  *(undefined8 *)(puVar15 + -8) = 0x14001f040;
  return;
}



===== UninitializeTelemetryAssertsKM @ 14001f064 =====

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
    *(undefined8 *)(puVar6 + -8) = 0x14001f0f7;
    KeReleaseSpinLock(&g_AssertSpinLock,uVar4);
    if (g_ModuleName != 0) {
      *(undefined8 *)(puVar6 + -8) = 0x14001f114;
      ExFreePoolWithTag(g_ModuleName,0x74727341);
      g_ModuleName = 0;
    }
    uVar3 = DAT_140033098;
    DAT_140033098 = 0;
    DAT_140033078 = 0;
    *(undefined8 *)(puVar6 + -8) = 0x14001f13e;
    EtwUnregister(uVar3);
    uVar3 = DAT_140033028;
    DAT_140033028 = 0;
    _DAT_140033008 = 0;
    *(undefined8 *)(puVar6 + -8) = 0x14001f160;
    EtwUnregister(uVar3);
    uVar3 = DAT_140033060;
    DAT_140033060 = 0;
    DAT_140033040 = 0;
    *(undefined8 *)(puVar6 + -8) = 0x14001f182;
    EtwUnregister(uVar3);
  }
  return;
}



===== __GSHandlerCheck @ 14001f1a8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14001f1cc =====

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



===== __cpu_features_init @ 14001f240 =====

/* WARNING: Removing unreachable block (ram,0x00014001f2aa) */
/* WARNING: Removing unreachable block (ram,0x00014001f259) */
/* WARNING: Removing unreachable block (ram,0x00014001f24a) */

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



===== __security_check_cookie @ 14001f310 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 14001f350 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 14001f380 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00014001f380. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 14001f3b0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcmp @ 14001f3e0 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_14001f423;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_14001f494;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_14001f490:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14001f494;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_14001f48c:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14001f490;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14001f48c;
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
LAB_14001f494:
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
LAB_14001f423:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== memmove @ 14001f500 =====

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



===== memset @ 14001f800 =====

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



===== __memset_repmovs @ 14001f940 =====

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



===== __memset_query @ 14001f9c0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 14001fa40 =====

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



===== __memset_spec_ermsb_repmovsb @ 14001fb80 =====

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



===== __memset_spec_plain @ 14001fc00 =====

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



===== WfpRioFastIoDeviceControl$filt$0 @ 14001fd00 =====

undefined8 WfpRioFastIoDeviceControl_filt_0(undefined8 param_1,longlong param_2)

{
  *(undefined8 *)(param_2 + 0x80) = param_1;
  *(longlong *)(param_2 + 0x58) = param_2 + 200;
  *(undefined8 *)(param_2 + 0x70) = param_1;
  if (*(longlong *)(param_2 + 0x58) != 0) {
    **(undefined4 **)(param_2 + 0x58) = *(undefined4 *)**(undefined8 **)(param_2 + 0x70);
  }
  return 1;
}



===== WfpRioFastIoDeviceControl$filt$1 @ 14001fd43 =====

undefined8 WfpRioFastIoDeviceControl_filt_1(undefined8 param_1,longlong param_2)

{
  *(undefined8 *)(param_2 + 0x78) = param_1;
  *(longlong *)(param_2 + 0x50) = param_2 + 200;
  *(undefined8 *)(param_2 + 0x68) = param_1;
  if (*(longlong *)(param_2 + 0x50) != 0) {
    **(undefined4 **)(param_2 + 0x50) = *(undefined4 *)**(undefined8 **)(param_2 + 0x68);
  }
  return 1;
}



===== WfpRioRegisterBuffer$filt$0 @ 14001fd89 =====

void WfpRioRegisterBuffer_filt_0(undefined8 *param_1,longlong param_2)

{
  *(undefined8 **)(param_2 + 0x68) = param_1;
  WfpExceptionFilter(param_1,(undefined4 *)(param_2 + 0x34));
  return;
}



===== WfpRioRegisterBuffer$filt$1 @ 14001fda7 =====

void WfpRioRegisterBuffer_filt_1(undefined8 *param_1,longlong param_2)

{
  WfpExceptionFilter(param_1,(undefined4 *)(param_2 + 0x34));
  return;
}



===== WfpRioDeregisterBuffer$filt$0 @ 14001fdc7 =====

void WfpRioDeregisterBuffer_filt_0(undefined8 *param_1,longlong param_2)

{
  WfpExceptionFilter(param_1,(undefined4 *)(param_2 + 0x20));
  return;
}



===== BiSignalEvent$filt$0 @ 14001fde7 =====

void BiSignalEvent_filt_0(undefined8 *param_1)

{
  RpcExceptionFilter(*(undefined4 *)*param_1);
  return;
}



===== WfpRioCreateCompletionQueue$filt$0 @ 14001fe0f =====

void WfpRioCreateCompletionQueue_filt_0(undefined8 *param_1,longlong param_2)

{
  WfpExceptionFilter(param_1,(undefined4 *)(param_2 + 0x34));
  return;
}



===== WfpRioCreateCq$filt$0 @ 14001fe2f =====

void WfpRioCreateCq_filt_0(undefined8 *param_1,longlong param_2)

{
  *(undefined8 **)(param_2 + 0x80) = param_1;
  WfpExceptionFilter(param_1,(undefined4 *)(param_2 + 0x50));
  return;
}



===== WfpRioCreateCq$filt$1 @ 14001fe50 =====

void WfpRioCreateCq_filt_1(undefined8 *param_1,longlong param_2)

{
  WfpExceptionFilter(param_1,(undefined4 *)(param_2 + 0x50));
  return;
}



===== WfpRioCreateRqPair$filt$0 @ 14001fe70 =====

void WfpRioCreateRqPair_filt_0(undefined8 *param_1,longlong param_2)

{
  *(undefined8 **)(param_2 + 0x108) = param_1;
  WfpExceptionFilter(param_1,(undefined4 *)(param_2 + 0x34));
  return;
}



===== WfpRioDestroyCq$filt$0 @ 14001fe97 =====

void WfpRioDestroyCq_filt_0(undefined8 *param_1,longlong param_2)

{
  WfpExceptionFilter(param_1,(undefined4 *)(param_2 + 0x20));
  return;
}



===== WfpRioInitializeActivityTracking$filt$0 @ 14001feb7 =====

void WfpRioInitializeActivityTracking_filt_0(undefined8 *param_1,longlong param_2)

{
  *(undefined8 **)(param_2 + 0x38) = param_1;
  WfpExceptionFilter(param_1,(undefined4 *)(param_2 + 0x30));
  return;
}



===== WppInitKm @ 140034008 =====

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



===== DriverUnload @ 1400340a0 =====

void DriverUnload(void)

{
  undefined8 uVar1;
  bool bVar2;
  ulonglong uVar3;
  
  L2DeregisterLayerEventNotify();
  do {
    bVar2 = L2IsMacLayersEmpty();
    if (bVar2) {
      bVar2 = L2IsvSwitchLayersEmpty();
      if (bVar2) {
        NdisFreeNetBufferListPool(DAT_14002cf38);
        NdisFreeGenericObject(DAT_14002cf30);
        if (DAT_14002cf10 != 0) {
          FwpmEngineClose0();
        }
        FwpmBfeStateUnsubscribeChanges0(DAT_14002cf00);
        if (DAT_14002cef8 != 0) {
          NsiDeregisterChangeNotification(&NPI_MS_NDIS_MODULEID,0);
        }
        NdisFDeregisterFilterDriver(DAT_14002cef0);
        vSwitchFlCleanup();
        NdisFDeregisterFilterDriver(DAT_14002cee8);
        NdisFDeregisterFilterDriver(DAT_14002cee0);
        L2UnInitializeFlowsManager(0x14002c6e0);
        FwpsL2DispatchTableClear0();
        if (DAT_14002ce88 != 0) {
          IoDeleteDevice();
        }
        if (DAT_14002cf88 != 0) {
          IoDeleteDevice();
        }
        WfpRioUninitialize();
        if (DAT_14002cf80 != 0) {
          IoDeleteDevice();
        }
        uVar3 = Feature_VPN_BugFixes_25A__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar3 != 0) {
          UninitializeTelemetryAssertsKM();
        }
        uVar1 = DAT_14002c300;
        DAT_14002c300 = 0;
        DAT_14002c2e0 = 0;
        EtwUnregister(uVar1);
        if (g_wil_details_featureChangeNotification != 0) {
          RtlUnregisterFeatureConfigurationChangeNotification();
          g_wil_details_featureChangeNotification = 0;
        }
        if (g_wil_details_featureUsageProvider != 0) {
          RtlUnregisterFeatureUsageProvider();
          g_wil_details_featureUsageProvider = 0;
        }
        g_wil_details_isFeatureStagingInitialized = 0;
        WppCleanupKm();
        return;
      }
    }
    L2DelayExecution(1000);
  } while( true );
}



===== WppCleanupKm @ 140034264 =====

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



===== WppTraceCallback @ 1400342f0 =====

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



===== wil_RtlStagingConfig_QueryFeatureState @ 140034578 =====

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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 140034644 =====

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
      goto LAB_1400346a1;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_1400346a1;
    }
  }
  uVar1 = 0x206;
LAB_1400346a1:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 1400346ac =====

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



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 140034764 =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 14003479c =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_14003481e;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_14003481e;
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
LAB_14003481e:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 140034870 =====

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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 1400348d0 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 1400348ec =====

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



===== NikEdpFreeMemory @ 1400349a0 =====

void NikEdpFreeMemory(undefined8 param_1)

{
  ExFreePoolWithTag(param_1,0x6f706445);
  return;
}



===== NikEdpGetEnterpriseId @ 1400349d0 =====

void NikEdpGetEnterpriseId(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  int iVar1;
  RPC_BINDING_HANDLE *local_res20;
  
  local_res20 = (RPC_BINDING_HANDLE *)0x0;
  *param_3 = 0;
  param_3[1] = 0;
  iVar1 = NikEdpGetEnterpriseIdAsync
                    (param_1,param_2,param_3,EdpGetEnterpriseIdSyncCallback,&local_res20);
  if (iVar1 == 0) {
    NikEdpGetEnterpriseIdClose(local_res20,1);
  }
  return;
}



===== NikEdpGetEnterpriseIdAsync @ 140034a20 =====

int NikEdpGetEnterpriseIdAsync
              (undefined8 param_1,undefined8 param_2,RPC_BINDING_HANDLE param_3,
              RPC_BINDING_HANDLE param_4,undefined8 *param_5)

{
  int iVar1;
  RPC_BINDING_HANDLE *ppvVar2;
  RPC_BINDING_HANDLE local_28 [2];
  
  local_28[0] = (RPC_BINDING_HANDLE)0x0;
  *param_5 = 0;
  ppvVar2 = (RPC_BINDING_HANDLE *)ExAllocatePool2(0x40,0xb0,0x6f706445);
  if (ppvVar2 == (RPC_BINDING_HANDLE *)0x0) {
    iVar1 = -0x3fffff66;
  }
  else {
    KeInitializeEvent(ppvVar2 + 0xf,0,0);
    iVar1 = EdpRpcBindingCreateLocal(local_28);
    if ((-1 < iVar1) && (iVar1 = EdpRpcBindingBind(local_28[0]), -1 < iVar1)) {
      *ppvVar2 = local_28[0];
      local_28[0] = (RPC_BINDING_HANDLE)0x0;
      *(undefined4 *)((longlong)ppvVar2 + 0xa4) = 0;
      *(undefined4 *)(ppvVar2 + 0x15) = 0;
      ppvVar2[0xd] = param_4;
      ppvVar2[0xe] = param_3;
      *(undefined4 *)(ppvVar2 + 0x14) = 1;
      iVar1 = RpcAsyncInitializeHandle((PRPC_ASYNC_STATE)(ppvVar2 + 1),0x58);
      if (-1 < iVar1) {
        ppvVar2[4] = (RPC_BINDING_HANDLE)0x0;
        ppvVar2[7] = EdpEnterpriseResultCallback;
        *(undefined4 *)((longlong)ppvVar2 + 0x34) = 2;
        RPC_NetworkIsolationGetEnterpriseIdAsync(ppvVar2 + 1);
        *param_5 = ppvVar2;
      }
    }
    if (iVar1 == 0) {
      return 0;
    }
  }
  if (local_28[0] != (RPC_BINDING_HANDLE)0x0) {
    RpcBindingFree(local_28);
    local_28[0] = (RPC_BINDING_HANDLE)0x0;
  }
  if (ppvVar2 != (RPC_BINDING_HANDLE *)0x0) {
    NikEdpGetEnterpriseIdClose(ppvVar2,0);
  }
  return iVar1;
}



===== L2KfdLayerEventNotifyFn @ 140034bb0 =====

ulonglong L2KfdLayerEventNotifyFn
                    (int param_1,ushort param_2,undefined8 param_3,ulonglong param_4,
                    undefined8 param_5)

{
  bool bVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar3 = 0;
  bVar1 = false;
  switch(param_2) {
  case 0x38:
  case 0x39:
  case 0x3a:
  case 0x3b:
  case 0x50:
  case 0x51:
    goto switchD_140034c0a_caseD_38;
  default:
    return 0;
  case 0x48:
  case 0x49:
  case 0x4a:
  case 0x4b:
  case 0x4c:
  case 0x4d:
    break;
  }
  bVar1 = true;
  uVar2 = L2KfdLayerProcessFiltersAddRefCompartmentsSync
                    ((ulonglong)param_2,param_4 & 0xffffffff,param_5);
  uVar3 = (ulonglong)uVar2;
  if ((int)uVar2 < 0) {
    return uVar3;
  }
switchD_140034c0a_caseD_38:
  if (param_1 != 1) {
    L2KfdProcessLayerEvent(2,param_2);
    return uVar3;
  }
  uVar2 = L2KfdProcessLayerEvent(1,param_2);
  uVar3 = (ulonglong)uVar2;
  if ((-1 < (int)uVar2) && (bVar1)) {
    KeWaitForSingleObject(&DAT_14002cf48,0,0,0,0);
    uVar3 = vSwitchCheckAndRevokeAssignedVfs(param_2);
    uVar3 = uVar3 & 0xffffffff;
    KeReleaseMutex(&DAT_14002cf48,0);
  }
  if ((int)uVar3 < 1) {
    return uVar3;
  }
  return 0xc0000001;
}



===== _tlgEnableCallback @ 140034cb0 =====

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



===== NikEdpGetEnterpriseIdClose @ 140034d30 =====

RPC_STATUS NikEdpGetEnterpriseIdClose(RPC_BINDING_HANDLE *param_1,int param_2)

{
  RPC_STATUS RVar1;
  RPC_STATUS RVar2;
  
  RVar2 = 0;
  if (param_2 == 0) {
    RVar1 = RpcAsyncCancelCall((PRPC_ASYNC_STATE)(param_1 + 1),1);
    *(RPC_STATUS *)(param_1 + 0xc) = RVar1;
  }
  else {
    KeWaitForSingleObject(param_1 + 0xf,0,0,0,0);
  }
  if (*param_1 != (RPC_BINDING_HANDLE)0x0) {
    RVar2 = RpcBindingFree(param_1);
  }
  ExFreePoolWithTag(param_1,0x6f706445);
  return RVar2;
}



===== TraceLoggingRegisterEx_EtwRegister_EtwSetInformation @ 140034db8 =====

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
  *(undefined8 *)(puVar7 + -8) = 0x140034e1b;
  iVar6 = EtwRegister(puVar7 + 0x20,_tlgEnableCallback,param_1,plVar1);
  if (iVar6 == 0) {
    puVar4 = *(undefined2 **)(param_1 + 8);
    lVar3 = *plVar1;
    uVar2 = *puVar4;
    *(undefined8 *)(puVar7 + -8) = 0x140034e3b;
    EtwSetInformation(lVar3,2,puVar4,uVar2);
  }
  *(undefined8 *)(puVar7 + -8) = 0x140034e4f;
  return iVar6;
}



===== WppLoadTracingSupport @ 140034e68 =====

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



===== entry @ 140035010 =====

void entry(longlong param_1)

{
  __security_init_cookie();
  DriverEntry(param_1);
  return;
}



===== __security_init_cookie @ 140035044 =====

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



===== wil_InitializeFeatureStaging @ 140035078 =====

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



===== wil_details_PopulateInitialConfiguredFeatureStates @ 140035168 =====

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



===== DriverEntry @ 140035250 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong DriverEntry(longlong param_1)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  longlong lVar9;
  undefined1 auStack_6f8 [32];
  undefined1 *local_6d8;
  undefined8 *local_6d0;
  undefined8 *local_6c8;
  code *local_6b8;
  code *pcStack_6b0;
  code *local_6a8;
  code *pcStack_6a0;
  code *local_698;
  code *local_690;
  code *pcStack_688;
  code *local_680;
  code *pcStack_678;
  undefined8 local_670;
  undefined8 uStack_668;
  code *local_658;
  code *local_650;
  code *local_648;
  code *local_640;
  code *local_638;
  code *local_630;
  code *local_628;
  code *local_620;
  code *local_618;
  code *local_610;
  code *local_608;
  code *local_600;
  undefined4 local_5f8;
  undefined4 local_5f4;
  undefined4 local_5f0;
  undefined8 local_5e8;
  wchar_t *pwStack_5e0;
  undefined4 local_5d8;
  undefined4 uStack_5d4;
  undefined4 uStack_5d0;
  undefined4 uStack_5cc;
  undefined8 local_5c8;
  undefined *puStack_5c0;
  code *local_5b0;
  code *local_5a8;
  code *local_5a0;
  code *local_598;
  code *local_590;
  code *local_588;
  code *local_580;
  code *local_570;
  code *local_568;
  code *local_560;
  code *local_558;
  code *local_550;
  code *local_538;
  undefined4 local_508;
  undefined8 local_504;
  undefined8 local_4f8;
  wchar_t *pwStack_4f0;
  undefined4 local_4e8;
  undefined4 uStack_4e4;
  undefined4 uStack_4e0;
  undefined4 uStack_4dc;
  undefined8 local_4d8;
  undefined *puStack_4d0;
  code *local_4c0;
  code *local_4b8;
  code *local_4b0;
  code *local_4a8;
  code *local_4a0;
  code *local_470;
  code *local_468;
  code *local_460;
  code *local_450;
  code *local_448;
  undefined4 local_418;
  undefined4 local_414;
  undefined4 local_410;
  undefined8 local_408;
  wchar_t *pwStack_400;
  undefined4 local_3f8;
  undefined4 uStack_3f4;
  undefined4 uStack_3f0;
  undefined4 uStack_3ec;
  undefined8 local_3e8;
  undefined *puStack_3e0;
  code *local_3d0;
  code *local_3c8;
  code *local_3c0;
  code *local_3b8;
  code *local_3b0;
  code *local_358;
  undefined8 local_328;
  undefined8 uStack_320;
  undefined4 local_318;
  undefined4 local_308 [70];
  undefined1 local_1ee;
  undefined1 local_1e8 [288];
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined4 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_6f8;
  bVar1 = false;
  memset(&local_418,0,0xf0);
  memset(&local_5f8,0,0xf0);
  memset(&local_508,0,0xf0);
  local_318 = 0;
  local_328 = 0;
  uStack_320 = 0;
  memset(&local_658,0,0x60);
  memset(local_308,0,0x11c);
  local_40 = 0x32;
  local_58 = 0x7600650044005c;
  uStack_50 = 0x5c006500630069;
  bVar2 = false;
  local_48 = 0x4c005000460057;
  local_6b8 = (code *)0x0;
  pcStack_6b0 = (code *)0x0;
  local_698 = (code *)0x0;
  local_6a8 = (code *)0x0;
  pcStack_6a0 = (code *)0x0;
  local_690 = (code *)0x0;
  pcStack_688 = (code *)0x0;
  local_680 = (code *)0x0;
  pcStack_678 = (code *)0x0;
  memset(local_1e8,0,0x18c);
  _WPP_MAIN_CB = 0;
  DAT_14002c6a8 = &WPP_ThisDir_CTLGUID_WfpLwfsWPPGuid;
  DAT_14002c6b0 = 0;
  _DAT_14002c6c0 = 0;
  _DAT_14002c6c8 = 1;
  WppLoadTracingSupport();
  _DAT_14002c6c0 = 0;
  WppInitKm();
  wil_InitializeFeatureStaging();
  TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(0x14002c2e0);
  uVar6 = Feature_VPN_BugFixes_25A__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar6 != 0) {
    InitializeTelemetryAssertsKMByDriverObject(param_1);
  }
  local_308[0] = 0x11c;
  local_1ee = 1;
  uVar7 = VerSetConditionMask(0,0x80,1);
  iVar4 = RtlVerifyVersionInfo(local_308,0x80,uVar7);
  DAT_14002cf44 = iVar4 != -0x3fffffa7;
  local_670 = 0;
  uStack_668 = 0;
  gWfpL2Globals = param_1;
  RtlInitUnicodeString(&local_670,&local_58);
  local_6c8 = &DAT_14002ce88;
  local_6d0 = (undefined8 *)((ulonglong)local_6d0 & 0xffffffffffffff00);
  local_6d8 = (undefined1 *)CONCAT44(local_6d8._4_4_,0x100);
  uVar5 = IoCreateDevice(param_1,0,0,0x12);
  uVar6 = (ulonglong)uVar5;
  if ((int)uVar5 < 0) goto LAB_140035a2c;
  local_6c8 = &DAT_14002cf80;
  local_6d0 = (undefined8 *)((ulonglong)local_6d0 & 0xffffffffffffff00);
  local_6d8 = (undefined1 *)CONCAT44(local_6d8._4_4_,0x20000);
  uVar5 = IoCreateDevice(param_1,0,&local_670,0x12);
  uVar6 = (ulonglong)uVar5;
  if ((int)uVar5 < 0) goto LAB_140035a2c;
  uVar5 = WfpInitializeDPConfigDevice(param_1);
  uVar6 = (ulonglong)uVar5;
  if ((int)uVar5 < 0) goto LAB_140035a2c;
  *(code **)(param_1 + 0x70) = WfpL2DispatchCreate;
  *(code **)(param_1 + 0x80) = WfpL2DispatchClose;
  *(code **)(param_1 + 0x100) = WfpL2DispatchCleanup;
  *(code **)(param_1 + 0xe8) = WfpL2DispatchInternalDeviceControl;
  *(code **)(param_1 + 0xe0) = WfpL2DispatchDeviceControl;
  *(undefined **)(param_1 + 0x50) = &WfpFastIoDispatch;
  KeInitializeSpinLock(&DAT_14002ce90);
  KeInitializeMutex(&DAT_14002cf48,0xffff);
  local_648 = L2ReferenceNetBufferListContext;
  local_640 = L2DereferenceNetBufferListContext;
  local_658 = L2AllocateNetBufferListContext;
  local_650 = L2FreeNetBufferListContext;
  local_638 = L2InjectNetBufferLists;
  local_630 = L2RetrieveNetBufferListCompletionContext;
  local_628 = L2SetNetBufferListCompletionContext;
  local_620 = L2GetValueFromClassifyContext;
  local_608 = L2vSwitchGetDestinationInterface;
  local_618 = L2vSwitchCopyVmSwitchNblInfo;
  local_610 = L2vSwitchFreeVmSwitchNblInfo;
  local_600 = L2vSwitchGetDestinationArray;
  FwpsL2DispatchTableAndGlobalsSet0(&local_658);
  local_6b8 = WfpRioChannelCreate;
  pcStack_6b0 = WfpRioReceiveNbl;
  local_6a8 = WfpRioSendCompleteNbl;
  pcStack_6a0 = WfpRioChannelDestroy;
  local_698 = WfpRioGetProcessIdFromProfileName;
  FwppDPDispatchTableAndGlobalsSet0(&local_6b8);
  local_690 = NikEdpGetEnterpriseId;
  pcStack_688 = NikEdpGetEnterpriseIdAsync;
  pcStack_678 = NikEdpFreeMemory;
  local_680 = NikEdpGetEnterpriseIdClose;
  FwppEdpDispatchTableAndGlobalsSet0(&local_690);
  uVar8 = L2InitializeFlowsManager(0x14002c6e0);
  uVar6 = uVar8 & 0xffffffff;
  if ((int)uVar8 < 0) goto LAB_140035a2c;
  bVar1 = true;
  uVar5 = WfpRioInitialize(DAT_14002cf80);
  uVar6 = (ulonglong)uVar5;
  if ((int)uVar5 < 0) goto LAB_140035a2c;
  local_3c8 = LwfUpperAttach;
  local_418 = 0xf0038b;
  local_3c0 = LwfUpperDetach;
  local_414 = 0x15906;
  local_3b8 = LwfUpperRestart;
  local_410 = 2;
  local_3b0 = LwfUpperPause;
  _DAT_14002cea8 = 0;
  local_3d0 = LwfUpperSetFilterModuleOptions;
  bVar2 = true;
  local_408 = 0x4e004c;
  pwStack_400 = L"WFP 802.3 MAC Layer LightWeight Filter";
  local_358 = LwfUpperStatusIndication;
  DAT_14002cea0 = &DAT_14002ce98;
  DAT_14002ce98 = &DAT_14002ce98;
  local_3f8 = 0x4e004c;
  uStack_3f4 = 0;
  uStack_3f0 = 0x40023070;
  uStack_3ec = 1;
  local_3e8 = 0x10000e;
  puStack_3e0 = &WFP_LWFS_SERVICE_NAME_buffer;
  uVar5 = NdisFRegisterFilterDriver(param_1,gWfpL2Globals,&local_418,&DAT_14002cee0);
  if (uVar5 == 0) {
    local_5a8 = LwfLowerAttach;
    local_5a0 = LwfLowerDetach;
    local_598 = LwfLowerRestart;
    local_590 = LwfLowerPause;
    local_5b0 = LwfLowerSetFilterModuleOptions;
    local_538 = LwfUpperStatusIndication;
    local_560 = LwfLowerOidRequest;
    local_5e8 = 0x50004e;
    pwStack_5e0 = L"WFP Native MAC Layer LightWeight Filter";
    local_558 = LwfLowerOidRequestComplete;
    local_550 = LwfLowerCancelOidRequest;
    local_5f8 = 0xf0038b;
    local_5f4 = 0x15906;
    local_5f0 = 2;
    local_5d8 = 0x4e004c;
    uStack_5d4 = 0;
    uStack_5d0 = 0x40022fd0;
    uStack_5cc = 1;
    local_5c8 = 0x10000e;
    puStack_5c0 = &WFP_LWFS_SERVICE_NAME_buffer;
    if (DAT_14002cf44 != '\0') {
      local_588 = LwfLowerSendNetBufferLists;
      local_580 = LwfLowerSendNetBufferListsComplete;
      local_570 = LwfLowerRecvNetBufferLists;
      local_568 = LwfLowerReturnNetBufferLists;
    }
    DAT_14002ceb8 = &DAT_14002ceb0;
    DAT_14002ceb0 = &DAT_14002ceb0;
    DAT_14002cec0 = 0;
    lVar9 = param_1;
    uVar5 = NdisFRegisterFilterDriver(param_1,gWfpL2Globals,&local_5f8,&DAT_14002cee8);
    if (uVar5 == 0) {
      DAT_14002ced8 = 0;
      DAT_14002ced0 = &DAT_14002cec8;
      DAT_14002cec8 = &DAT_14002cec8;
      bVar3 = L2vSwitchpIsWinPE();
      if (!bVar3) {
        uVar5 = vSwitchFlStartup(lVar9,&DAT_14002cf20);
        uVar6 = (ulonglong)uVar5;
        if ((int)uVar5 < 0) goto LAB_140035a2c;
        local_508 = 0xf0038b;
        local_4b8 = LwfvSwitchAttach;
        local_504 = 0x15906;
        local_4b0 = LwfvSwitchDetach;
        local_4a8 = LwfvSwitchRestart;
        local_4a0 = LwfvSwitchPause;
        local_4c0 = LwfvSwitchSetFilterModuleOptions;
        local_448 = LwfvSwitchStatusIndication;
        local_470 = LwfvSwitchOidRequest;
        local_468 = LwfvSwitchOidRequestComplete;
        local_4f8 = 0x4c004a;
        pwStack_4f0 = L"WFP vSwitch Layers LightWeight Filter";
        local_460 = LwfLowerCancelOidRequest;
        local_450 = LwfvSwitchNetPnPEvent;
        local_4e8 = 0x4e004c;
        uStack_4e4 = 0;
        uStack_4e0 = 0x40022f30;
        uStack_4dc = 1;
        local_4d8 = 0x10000e;
        puStack_4d0 = &WFP_LWFS_SERVICE_NAME_buffer;
        FwppvSwitchNotifyCompletionFnSet
                  (LwfvSwitchEventNotifyComplete,LwfvSwitchReorderEventNotifyComplete);
        uVar5 = NdisFRegisterFilterDriver(param_1,gWfpL2Globals,&local_508,&DAT_14002cef0);
        if (uVar5 != 0) goto LAB_1400359e3;
        uVar5 = L2vSwitchExtentionAdapterIdQuery();
        uVar6 = (ulonglong)uVar5;
        if ((int)uVar5 < 0) goto LAB_140035a2c;
        local_6d0 = &DAT_14002cef8;
        local_6d8 = (undefined1 *)0x0;
        uVar5 = NsiRegisterChangeNotification
                          (&NPI_MS_NDIS_MODULEID,0,L2vSwitchExtentionAdapterChangeNotification,1);
        uVar6 = (ulonglong)uVar5;
        if ((int)uVar5 < 0) goto LAB_140035a2c;
        uVar5 = FwpmBfeStateSubscribeChangesWithoutDevice0
                          (L2BfeStateChangeCallback,0,&DAT_14002cf00);
        uVar6 = (ulonglong)uVar5;
        if ((int)uVar5 < 0) goto LAB_140035a2c;
        DAT_14002cf30 = NdisAllocateGenericObject(0,0x57766e62,0);
        if (DAT_14002cf30 == 0) {
          return uVar6;
        }
        local_328 = CONCAT26(local_328._6_2_,0x10000140180);
        uStack_320 = CONCAT44(uStack_320._4_4_,0x57766e62);
        DAT_14002cf38 = NdisAllocateNetBufferListPool(DAT_14002cf30,&local_328);
        if (DAT_14002cf38 == 0) {
          return uVar6;
        }
      }
      DAT_14002cf40 = 0;
      MmIsVerifierEnabled(&DAT_14002cf40);
      local_c8 = 0x100000001;
      uStack_c0 = 0x100000001;
      local_b8 = 0x100000001;
      while( true ) {
        local_6d8 = local_1e8;
        uVar5 = KfdRegisterLayerEventNotifyEx(3,1,L2KfdLayerEventNotifyFn,99);
        uVar6 = (ulonglong)uVar5;
        if (-1 < (int)uVar5) {
          *(code **)(param_1 + 0x68) = DriverUnload;
          return uVar6;
        }
        if (uVar5 == 0xc000009a) break;
        L2DelayExecution(100);
      }
      goto LAB_140035a2c;
    }
  }
LAB_1400359e3:
  if ((((uVar5 == 0x103) || (uVar5 == 0x80000005)) || (uVar5 == 0xc0000001)) ||
     ((uVar5 == 0xc000009a || (uVar5 == 0xc00000bb)))) {
    uVar6 = (ulonglong)uVar5;
    if (-1 < (int)uVar5) {
      return uVar6;
    }
  }
  else if (uVar5 == 0xc0010016) {
    uVar6 = 0xc0000023;
  }
  else if (uVar5 == 0xc0010014) {
    uVar6 = 0xc0000206;
  }
  else {
    uVar6 = 0xc0000001;
    if (uVar5 == 0xc0010015) {
      uVar6 = 0xc000000d;
    }
  }
LAB_140035a2c:
  if (DAT_14002cf38 != 0) {
    NdisFreeNetBufferListPool();
  }
  if (DAT_14002cf30 != 0) {
    NdisFreeGenericObject();
  }
  if (DAT_14002cf00 != 0) {
    FwpmBfeStateUnsubscribeChanges0();
  }
  if (DAT_14002cef8 != 0) {
    NsiDeregisterChangeNotification(&NPI_MS_NDIS_MODULEID,0);
  }
  if (DAT_14002cef0 != 0) {
    NdisFDeregisterFilterDriver();
  }
  if (DAT_14002cf20 != 0) {
    vSwitchFlCleanup();
  }
  if (DAT_14002cee8 != 0) {
    NdisFDeregisterFilterDriver();
  }
  if (DAT_14002cee0 != 0) {
    NdisFDeregisterFilterDriver();
  }
  if (bVar1) {
    L2UnInitializeFlowsManager(0x14002c6e0);
  }
  FwpsL2DispatchTableClear0();
  if (DAT_14002ce88 != 0) {
    IoDeleteDevice();
  }
  if (bVar2) {
    WfpRioUninitialize();
  }
  if (DAT_14002cf80 != 0) {
    IoDeleteDevice();
  }
  if (DAT_14002cf88 != 0) {
    IoDeleteDevice();
  }
  WppCleanupKm();
  return uVar6;
}


